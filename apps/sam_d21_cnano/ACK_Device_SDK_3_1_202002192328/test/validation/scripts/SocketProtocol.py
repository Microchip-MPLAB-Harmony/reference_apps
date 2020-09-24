# Copyright 2020 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

import queue
import select
import socket
import threading
import time

from enum import *
from typing import *

# Represents a simple protocol for exchanging information between a simulated ACK module acting as
# the server, and a simulated HMCU acting as the client.
# The ACK module's signalling pins are represented with an active/inactive semantic that is independent
# of the actual active-low representation that would apply on a physical UART.
class Endpoint(object):
    # Implementation of receiving ACP data and debug-print strings on the socket uses a producer/consumer
    # model. The producer is a separate receiver thread that is always running and reading from the socket.
    # Incoming data messages are handled in that thread by writing the bytes of the message into queues --
    # one distinct queue for each of the two types of data messages. The public 'receive ACP data' and
    # 'receive debug-print string' methods are queue consumers.
    #
    # The public 'send ACP data' and 'send debug-print string' methods execute synchronously by writing
    # to the socket.
    #
    # RESET and HOSTINT signals are maintained as simple booleans. When the receiver thread receives
    # updates to those signals, it simply updates the appropriate boolean. The public 'get HOSTINT state'
    # and 'get RESET state' methods simply return the current value of those booleans.
    #
    # The design of this class is fairly tightly coupled to the intended usage patterns. For example,
    # the 'receive debug-print string' method is synchronous and does not accept a timeout, which would
    # seemingly prevent a graceful shutdown of the object. However the caller of that method is assumed to
    # itself be running in a background thread in another class. So the main thread can call Close on this
    # class, which will cause the socket to be closed, which would cause any pending socket-based I/O to
    # abort, which would cause the 'receive debug-print string' method to wake up if blocked on socket I/O,
    # note the I/O error, and return accordingly.

    # Messages are exchanged in a simple packetized format. These are the packet types, represented by
    # a single byte on the wire. Some packet types have additional components beyond the type byte.
    class PacketType(IntEnum):
        # HMCU indicating to ACK module that the RESET signal is active.
        # No size or payload follows.
        RESET_ACTIVE = 1

        # HMCU indicating to ACK module that the RESET signal is inactive.
        # No size or payload follows.
        RESET_INACTIVE = 2

        # ACK module indicating to HMCU that the HOSTINT signal is active.
        # No size or payload follows.
        HOSTINT_ACTIVE = 3

        # ACK module indicating to HMCU that the HOSTINT signal is inactive.
        # No size or payload follows.
        HOSTINT_INACTIVE = 4

        # HMCU sending ACP data to the ACK module, or vice versa.
        # The following two bytes are the big-endian size of the data, and the data follows.
        ACP_DATA = 5

        # HMCU debug-print output.
        # The following two bytes are the big-endian size of the UTF-8 string, and the bytes of the
        # string follow.
        DEBUG_PRINT_DATA = 6

    def __init__(self):
        # Not yet opened.
        self._closing = True

    # Returns a boolean indicating whether the RESET signal is asserted/active.
    def IsResetActive(self) -> bool:
        return self._resetActive

    # Returns a boolean indicating whether the HOSTING signal is asserted/active.
    def IsHostintActive(self) -> bool:
        return self._hostintActive

    # Sends host interrupt state as the appropriate packet type.
    def SendHostInterrupt(self, state: bool) -> None:
        self._Send(bytes([Endpoint.PacketType.HOSTINT_ACTIVE if state else Endpoint.PacketType.HOSTINT_INACTIVE]))

    # Sends reset state as the appropriate packet type.
    def SendReset(self, state: bool) -> None:
        self._Send(bytes([Endpoint.PacketType.RESET_ACTIVE if state else Endpoint.PacketType.RESET_INACTIVE]))

    # Attempts to receive ACP data over the socket.
    # Returns None if shutting down, or a timeout occurs.
    def ReceiveAcpData(self, byteCount: int, *, timeout = None) -> bytearray:
        if timeout is not None:
            assert timeout > 0

        data = bytearray()

        dueTime = None if (timeout is None) else (time.monotonic() + timeout)

        while len(data) < byteCount:
            try:
                # Use a 25ms timeout so we can respond to self._closing and shut down in a timely manner.
                # This value is arbitrarily chosen to balance responsiveness with CPU usage (e.g., not
                # sucking up 100% CPU).
                x = self._acpReceiveQueue.get(timeout = 0.025)
            except queue.Empty:
                x = None

            if self._closing or ((dueTime is not None) and (time.monotonic() >= dueTime)):
                # Shutting down, or timed out.
                return None
            if x is not None:
                data.append(x)

        return data

    # Attempts to send ACP data over the socket.
    def SendAcpData(self, data, *, timeout = None) -> bool:
        packetData = bytearray([ Endpoint.PacketType.ACP_DATA, len(data) // 256, len(data) % 256])
        packetData.extend(data)
    
        return self._Send(packetData, timeout = timeout)

    # Throws away any received ACP data that has not been retrieved.
    def DrainAcpData(self) -> None:
        while True:
            try:
                self._acpReceiveQueue.get_nowait()
            except queue.Empty:
                return

    # Attempts to receive a line of debug-print text over the socket.
    # Returns None if this object is shut down.
    def ReceiveDebugPrintLine(self) -> str:

        lineData = bytearray()

        while not self._closing:
            try:
                # Use a 25ms timeout so we can respond to self._closing and shut down in a timely manner.
                x = self._debugPrintReceiveQueue.get(timeout = 0.025)
            except queue.Empty:
                continue

            if x == 10:
                # Treat as utf-8, ignoring decode errors.
                return lineData.decode("utf-8", "replace")

            lineData.append(x)

        return None

    # Attempts to send a line of debug-print text over the socket.
    def SendDebugPrintLine(self, string: str) -> bool:
        stringData = string.rstrip().encode("utf-8")
        length = len(stringData) + 1

        packetData = bytearray([ Endpoint.PacketType.DEBUG_PRINT_DATA, length // 256, length % 256])
        packetData.extend(stringData)
        packetData.append(10)

        return self._Send(packetData)

    # Worker routine for derived classes.
    # Performs open processing common to client and server.
    def _OnOpened(self, s: socket.socket) -> None:
        # Set socket to non-blocking so we have better control over timeouts in Send/ReceiveAcpData.
        s.setblocking(False)

        self._s = s
        self._closing = False

        self._resetActive = False
        self._hostintActive = False

        self._acpReceiveQueue = queue.SimpleQueue()
        self._debugPrintReceiveQueue = queue.SimpleQueue()

        self._readerThread = threading.Thread(target = self._ReceiverThread)
        self._readerThread.start()

    # Worker routine for derived classes.
    # Performs close processing common to client and server.
    def _Close(self) -> None:
        if self._closing:
            return

        self._closing = True
        self._s.close()
        self._readerThread.join()

    # Thread that continuously receives from the socket, in the background.
    def _ReceiverThread(self):
        class State(Enum):
            # Next byte should be a value from the Endpoint.PacketType enum.
            TYPE = auto()

            # Next byte should be the high byte of a 2-byte payload size.
            SIZE_HIGH = auto()

            # Next byte should be the low byte of a 2-byte payload size.
            SIZE_LOW = auto()

            # Receiving the payload of an ACP or debug-print data packet.
            PAYLOAD = auto()

        readSize = 1
        state = State.TYPE

        while not self._closing:
            # Non-blocking socket; need to wait until we have something to receive.
            r, w, x = select.select([self._s], [], [], 0.025)
            if len(x) != 0:
                # Socket in error/exception state.
                return
            if len(r) == 0:
                # Nothing to read yet.
                continue

            try:
                data = self._s.recv(readSize)
            except OSError as ex:
                data = None
            if (data is None) or (len(data) == 0):
                # Connection is gone.
                return

            if state == State.TYPE:
                try:
                    packetType = Endpoint.PacketType(data[0])
                except ValueError:
                    # Protocol error. We can't recover from those.
                    return

                if packetType == Endpoint.PacketType.RESET_ACTIVE:
                    self._resetActive = True

                elif packetType == Endpoint.PacketType.RESET_INACTIVE:
                    self._resetActive = False

                elif packetType == Endpoint.PacketType.HOSTINT_ACTIVE:
                    self._hostintActive = True

                elif packetType == Endpoint.PacketType.HOSTINT_INACTIVE:
                    self._hostintActive = False

                elif packetType == Endpoint.PacketType.ACP_DATA:
                    queue = self._acpReceiveQueue
                    state = State.SIZE_HIGH

                elif packetType == Endpoint.PacketType.DEBUG_PRINT_DATA:
                    queue = self._debugPrintReceiveQueue
                    state = State.SIZE_HIGH

                else:
                    # Protocol error. We can't recover from those.
                    return

            elif state == State.SIZE_HIGH:
                payloadSizeHigh = 256 * data[0]
                state = State.SIZE_LOW

            elif state == State.SIZE_LOW:
                readSize = payloadSizeHigh + data[0]
                state = State.PAYLOAD

            elif state == State.PAYLOAD:
                for x in data:
                    queue.put(x)
                readSize -= len(data)
                assert readSize >= 0
                if readSize == 0:
                    readSize = 1
                    state = State.TYPE

            else:
                # Protocol error. We can't recover from those.
                return

    # Attempts to send data (all of it) within an optional timeout period.
    def _Send(self, data, *, timeout = None) -> bool:
        if timeout is not None:
            assert timeout > 0

        dueTime = None if (timeout is None) else (time.monotonic() + timeout)

        while len(data) > 0:
            # Wait for the ability to send at least one byte.
            interval = None
            if dueTime is not None:
                interval = min(0.025, dueTime - time.monotonic())

            r, w, x = select.select([], [self._s], [], interval)
            if self._closing or (len(x) != 0) or ((dueTime is not None) and (time.monotonic() >= dueTime)):
                # Shutting down, some error/exception occurred, or timed out.
                return False

            if len(w) == 0:
                # Can't send yet.
                continue

            # Should be able to send at least one byte.
            try:
                sent = self._s.send(data)
            except OSError:
                sent = -1
            if sent <= 0:
                # Connection is gone.
                return False

            data = data[sent :]

        return True

# Endpoint which acts as a protocol server.
# Accepts at most one connection from a client.
class Server(Endpoint):
    def __init__(self, address, port):
        super().__init__()
        self._address = address
        self._port = port

    # Opens the connection by waiting for a connection. This routine does not return until either
    # an error occurs or a connection is made successfully.
    def Open(self) -> bool:
        self._listener = socket.socket()
        try:
            self._listener.bind((self._address, self._port))
            self._listener.listen(0)
        except OSError:
            return False

        s, _ = self._listener.accept()

        self._OnOpened(s)
        return True

    # Shuts down the connection and the object.
    def Close(self):
        if not self._closing:
            self._listener.close()
            super()._Close()

# Endpoint which acts as a protocol client.
class Client(Endpoint):
    def __init__(self, address, port):
        super().__init__()
        self._address = address
        self._port = port

    # Connects to the server. This routine does not return until either an error occurs or a connection
    # is made successfully.
    def Open(self):
        self._closing = False

        s = socket.socket()
        try:
            s.connect((self._address, self._port))
        except OSError as ex:
            return False

        self._OnOpened(s)
        return True

    # Shuts down the connection and the object.
    def Close(self):
        if not self._closing:
            super()._Close()
