# Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

import concurrent.futures
import serial
import sys
import threading
import unittest

from HumanReadableStrings import *

if sys.version_info < (3, 7):
    print(STR_PYTHON_VERSION_REQUIRED.format(3, 7))
    sys.exit(1)

# ACP request header pattern.
HEADER_BYTE_PATTERN = b'~\xd4*\x94J'

# Provides byte-oriented communications on a serial port used as an ACP communications channel.
# Also provides signalling to simulate an ACK module's HOSTINT and RESET pins using RTS and CTS respectively.
#
# Receiving data on the port is split into two distinct phases:
#   (1) Synchronizing with an ACP request header, which is a distinct 5-byte pattern. A synchronize operation
#       is an asynchronous read which completes only when 5 sequentally received bytes match the pattern.
#   (2) Reading other parts of an ACP request. Those reads are synchronous, and can time out.
#
# Sending data can also time out.
class AcpChannel:
    _BaudRate = 115200
    _IOTimeout = 0.5

    def __init__(self, port):
        # Use serial_for_url instead of the standard constructor so that tests can use 'loop://' as the port.
        self._s = serial.serial_for_url(
            port,
            baudrate = AcpChannel._BaudRate,
            timeout = AcpChannel._IOTimeout,
            write_timeout = AcpChannel._IOTimeout)

        # rts defaults on, but we don't want HOSTINT signalled yet.
        self.SetHostInterrupt(False)

        self._closing = False

        self._e = concurrent.futures.ThreadPoolExecutor(max_workers = 1)

    # Shuts down. Safe to call while a Sync, Read, or Write is in progress on another thread.
    def Close(self):
        self._closing = True
        self._s.cancel_read()
        self._s.cancel_write()
        self._e.shutdown()
        self._s.close()

    # Initiate an asynchronous operation to sync up with the command header. The resulting Future
    # completes only when 5 sequentially received bytes match the header pattern.
    # None is returned if the AcpChannel is being shut down due to Close having been called.
    # The Future result is True if synchronized successfully, or False in case of timeout, or if the
    # AcpChannel is being shut down due to Close having been called.
    def SyncAsync(self) -> concurrent.futures.Future:
        return None if self._closing else self._e.submit(self._Sync)

    # Sync up with the command header. This blocks until 5 sequentially received bytes match the
    # header pattern.
    # Returns True if synchronized successfully, or False in case of timeout, or if the AcpChannel
    # is being shut down due to Close having been called.
    def _Sync(self) -> bool:
        patternIndex = 0
        patternLength = len(HEADER_BYTE_PATTERN)
        while patternIndex < patternLength:
            if self._closing:
                return False
            byte = self._ReadOne(block = (patternIndex == 0))
            if byte is None:
                return False
            if byte == HEADER_BYTE_PATTERN[patternIndex]:
                patternIndex += 1
            else:
                patternIndex = 0
        return True

    # Reads bytes from the serial port. This can time out.
    # Returns bytes if the read completed successfully, in which case the length of the returned bytes
    # will always be the number of bytes requested, or None in case of error or the AcpChannel shutting down
    # due to Close having been called.
    def Read(self, count) -> bytes:
        if self._closing:
            return None
        try:
            data = self._s.read(count)
        except serial.SerialException:
            return None

        return data if (len(data) == count) else None

    # Reads and discards bytes from the serial port until no more are immediately available.
    # This is not a blocking operation.
    def DrainRead(self):
        while (not self._closing) and (self._s.in_waiting > 0):
            try:
                self._s.read(self._s.in_waiting)
            except serial.SerialException:
                return

    # Writes bytes to the serial port. This can time out.
    # Returns True if the write completed successfully, in which case all bytes will have been written,
    # or False in case of timeout/error or the AcpChannel shutting down due to Close having been called.
    def Write(self, data) -> bool:
        try:
            writtenCount = self._s.write(data)
        except serial.SerialException:
            return False

        return writtenCount == len(data)

    # Sets the state of the HOSTINT pin. True indicates that there are events ready for the HMCU to request.
    # False means there are no events. If the AcpChannel is already shut down due to Close having been
    # called, this is a no-op.
    def SetHostInterrupt(self, state: bool):
        try:
            self._s.rts = state
        except serial.SerialException:
            pass

    # Indicates whether the RESET pin is asserted. True indicates that the HMCU is requesting reset.
    # False means it isn't. None means an error occurred or the AcpChannel was shut down due to Close
    # having been called.
    def IsResetAsserted(self) -> bool:
        try:
            return self._s.cts
        except serial.SerialException:
            return None

    # Reads one byte from the serial port, optionally providing a blocking semantic.
    # In the constructor, the port is opened with a read timeout specified, so a blocking semantic is
    # something we implement here, and not something we rely on pyserial to provide.
    def _ReadOne(self, block: bool) -> int:
        while True:
            if self._closing:
                return None

            try:
                data = self._s.read(1)
            except serial.SerialException:
                return None

            # If we got data back, we're done. Otherwise, the read timed out. A read time out is an error
            # unless the caller asked us to block until the read could be completed successfully.
            if len(data) != 0:
                assert len(data) == 1
                return data[0]

            if not block:
                return None

##########################################################################
# Tests
def setUpModule():
    pass

class Tests(unittest.TestCase):

    def setUp(self):
        AcpChannel._IOTimeout = 0.050 # reduce I/O timeout to 50ms for tests
        self.AcpChannel = AcpChannel("loop://")
        self.Serial = self.AcpChannel._s

    def tearDown(self):
        self.AcpChannel.Close()
        del self.AcpChannel

    # Tests that AcpChannel opens the debug port with expected characteristics.
    def testOpenCharacteristics(self):
        self.assertEqual(115200, self.Serial.baudrate)
        self.assertEqual(8, self.Serial.bytesize)
        self.assertEqual(serial.PARITY_NONE, self.Serial.parity)
        self.assertEqual(serial.STOPBITS_ONE, self.Serial.stopbits)
        self.assertEqual(False, self.Serial.xonxoff)
        self.assertEqual(False, self.Serial.rtscts)
        self.assertEqual(False, self.Serial.dsrdtr)
        self.assertIsNotNone(self.Serial.timeout)
        self.assertNotEqual(0, self.Serial.timeout)
        self.assertIsNotNone(self.Serial.write_timeout)
        self.assertNotEqual(0, self.Serial.write_timeout)
        self.assertFalse(self.Serial.rts)

    def testClose(self):
        # Close should terminate a pending Sync.
        f = self.AcpChannel.SyncAsync()
        self.assertIsInstance(f, concurrent.futures.Future)
        self.assertFalse(f.done())
        self.AcpChannel.Close()
        self.assertTrue(f.done())
        self.assertFalse(f.result())

    # Tests SetHostInterrupt and IsResetAsserted.
    def testHostIntAndReset(self):
        # The loopback port ties rts and cts together.
        self.assertFalse(self.Serial.rts)
        self.assertFalse(self.Serial.cts)
        self.assertFalse(self.AcpChannel.IsResetAsserted())

        self.AcpChannel.SetHostInterrupt(True) # sets rts
        self.assertTrue(self.Serial.rts)
        self.assertTrue(self.Serial.cts)
        self.assertTrue(self.AcpChannel.IsResetAsserted())

        self.AcpChannel.SetHostInterrupt(False) # clears rts
        self.assertFalse(self.Serial.rts)
        self.assertFalse(self.Serial.cts)
        self.assertFalse(self.AcpChannel.IsResetAsserted())

    # Tests SetHostInterrupt and IsResetAsserted when the channel has been closed.
    def testHostIntAndResetClosed(self):
        self.AcpChannel.Close()

        # No exception when calling SetHostInterrupt.
        try:
            self.AcpChannel.SetHostInterrupt(True)
        except Exception as e:
            self.fail(f"Got exception {e}")

        # IsResetAsserted should return None.
        self.assertIsNone(self.AcpChannel.IsResetAsserted())

    # Tests Write.
    def testWrite(self):
        expectedData = b'12345'
        self.assertTrue(self.AcpChannel.Write(expectedData))
        actualData = self.Serial.read(len(expectedData))
        self.assertEqual(0, self.Serial.in_waiting)
        self.assertSequenceEqual(expectedData, actualData)

    # Tests Write to a closed channel.
    def testWriteClosed(self):
        self.AcpChannel.Close()
        self.assertFalse(self.AcpChannel.Write(b''))

    # Tests Read.
    def testRead(self):
        expectedData = b'12345'
        self.assertEqual(len(expectedData), self.Serial.write(expectedData))
        actualData = self.AcpChannel.Read(len(expectedData))
        self.assertEqual(0, self.Serial.in_waiting)
        self.assertSequenceEqual(expectedData, actualData)

    # Tests Read to a closed channel.
    def testReadClosed(self):
        self.AcpChannel.Close()
        self.assertIsNone(self.AcpChannel.Read(0))
        self.assertIsNone(self.AcpChannel.Read(1))

    # Tests DrainRead.
    def testDrainRead(self):
        self.Serial.write(b'123')
        self.AcpChannel.DrainRead()
        expectedData = b"456"
        self.Serial.write(expectedData)
        actualData = self.AcpChannel.Read(len(expectedData))
        self.assertEqual(0, self.Serial.in_waiting)
        self.assertSequenceEqual(expectedData, actualData)

    # Tests DrainRead when there's no data to drain.
    def testDrainReadNoData(self):
        self.AcpChannel.DrainRead()
        expectedData = b"123"
        self.Serial.write(expectedData)
        actualData = self.AcpChannel.Read(len(expectedData))
        self.assertEqual(0, self.Serial.in_waiting)
        self.assertSequenceEqual(expectedData, actualData)

    # Tests DrainRead when the channel has been closed.
    def testDrainReadClosed(self):
        self.AcpChannel.Close()
        try:
            self.AcpChannel.DrainRead()
        except Exception as e:
            self.fail(f"Got exception {e}")

    # Tests Sync for a success case.
    def testSync(self):
        f = self.AcpChannel.SyncAsync()
        self.assertIsInstance(f, concurrent.futures.Future)
        self.assertFalse(f.done())

        # Check that Sync consumes only the header.
        self.assertEqual(len(HEADER_BYTE_PATTERN), self.Serial.write(HEADER_BYTE_PATTERN))

        expectedResidualData = b'123'
        self.assertEqual(len(expectedResidualData), self.Serial.write(expectedResidualData))

        done, pending = concurrent.futures.wait([f], 1, concurrent.futures.ALL_COMPLETED)
        self.assertEqual(0, len(pending))
        self.assertSequenceEqual(set([f]), done)
        self.assertTrue(f.done())
        self.assertTrue(f.result())

        actualResidualData = self.AcpChannel.Read(len(expectedResidualData))
        self.assertSequenceEqual(expectedResidualData, actualResidualData)

    # Tests Sync when resync must occur.
    def testSyncResync(self):
        bytePattern = list(HEADER_BYTE_PATTERN)
        passCount = len(bytePattern) - 1

        futures = []
        for i in range(passCount):
            receivedData = bytePattern[0:i] + [bytePattern[i]] + bytePattern[i:]
            self.Serial.write(receivedData)
            future = self.AcpChannel.SyncAsync()
            self.assertIsInstance(future, concurrent.futures.Future)
            self.assertFalse(future.done())

        done, pending = concurrent.futures.wait(futures, 1, concurrent.futures.ALL_COMPLETED)
        self.assertEqual(0, len(pending))
        self.assertSetEqual(done, set(futures))

        for future in futures:
            self.assertTrue(future.done())
            self.assertTrue(future.result())

    # Tests Sync when resync must occur but times out.
    def testSyncResyncTimesOut(self):
        partialLength = len(HEADER_BYTE_PATTERN) // 2
        self.assertEqual(partialLength, self.Serial.write(HEADER_BYTE_PATTERN[0:partialLength]))

        future = self.AcpChannel.SyncAsync()
        self.assertIsInstance(future, concurrent.futures.Future)

        done, pending = concurrent.futures.wait([future], 2 * AcpChannel._IOTimeout)
        self.assertEqual(0, len(pending))
        self.assertSetEqual(set([future]), done)

        self.assertTrue(future.done())
        self.assertFalse(future.result())

if __name__ == "__main__":
    unittest.main()
