# Copyright 2020 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

import concurrent.futures

import AcpChannel
import SocketProtocol

# Implementation of ACP protocol and debug-print handling, using sockets. Most meaningful work is
# delegated to a common socket protocol handler implemented elsewhere in this SDK.
class SocketComms:

    def __init__(self, address: str, port: int):
        self._protocolServer = SocketProtocol.Server(address, port)

    def Open(self) -> bool:
        # Wait for connection from HMCU. This has to happen before any higher-level protocol work occurs,
        # such as waiting for the RESET pin to be signalled. We can't do that until the socket connection
        # has occurred.
        if not self._protocolServer.Open():
            return False

        self._syncExecutor = concurrent.futures.ThreadPoolExecutor(max_workers = 1)
        self._readLineExecutor = concurrent.futures.ThreadPoolExecutor(max_workers = 1)

        return True

    def Close(self):
        self._protocolServer.Close()
        self._syncExecutor.shutdown()
        self._readLineExecutor.shutdown()

    # Initiates an operation that reads from a connected peer until an ACP request header pattern has
    # been seen. The read proceeds asynchronously in a worker thread, and completes a Future when done.
    # (ACP protocol)
    def SyncAsync(self) -> concurrent.futures.Future:
        try:
            result = self._syncExecutor.submit(self._SyncAcp)
        except RuntimeError:
            # Executor shut down already.
            result = False
        return result

    # Synchronously reads ACP data from a connected peer. Does not return until all requested data has
    # been read, or an error or shutdown occurs.
    # (ACP protocol)
    def Read(self, count) -> bytes:
        return self._protocolServer.ReceiveAcpData(count)

    # Drops any ACP data that has been received from a connected peer but not yet consumed locally.
    # (ACP protocol)
    def DrainRead(self) -> None:
        self._protocolServer.DrainAcpData()

    # Synchronously writes ACP data to a connected peer. Does not return until all requested data has
    # been written, or an error or shutdown occurs.
    # (ACP protocol)
    def Write(self, data) -> bool:
        return self._protocolServer.SendAcpData(data)

    # Sends an updated HOSTINT signal state to a connected peer.
    # (ACP protocol)
    def SetHostInterrupt(self, state: bool) -> None:
        self._protocolServer.SendHostInterrupt(state)

    # Sends an updated RESET signal state to a connected peer.
    # (ACP protocol)
    def IsResetAsserted(self) -> bool:
        return self._protocolServer.IsResetActive()

    # Initiates an operation that reads a newline-terminated string from a connected peer. The read
    # asynchronously in a worker thread, and completes a Future when done.
    # (debug port)
    def ReadLineAsync(self) -> concurrent.futures.Future:
        try:
            result = self._readLineExecutor.submit(self._ReadDebugLine)
        except RuntimeError:
            # Executor shut down already.
            result = False
        return result

    # Worker routine for SyncAsync, intended to be called from a worker thread.
    def _SyncAcp(self) -> bool:
        patternIndex = 0

        while True:
            byte = self._protocolServer.ReceiveAcpData(1)
            if byte is None:
                # Shutting down.
                return False

            if byte[0] == AcpChannel.HEADER_BYTE_PATTERN[patternIndex]:
                patternIndex += 1
                if patternIndex == len(AcpChannel.HEADER_BYTE_PATTERN):
                    return True
            else:
                patternIndex = 0
            
    # Worker routine for ReadLinecAsync, intended to be called from a worker thread.
    def _ReadDebugLine(self) -> str:
        return self._protocolServer.ReceiveDebugPrintLine()

