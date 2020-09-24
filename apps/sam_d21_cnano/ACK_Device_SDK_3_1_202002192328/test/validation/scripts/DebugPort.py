# Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

import concurrent.futures
import serial
import sys
import unittest

from HumanReadableStrings import *

# Provides line-oriented read communications on a serial port. Here 'line' refers to a string terminated
# with a newline character.
# Reading a line is an asynchronous operation. The caller can use the returned Future to determine
# when the read has completed. 
class DebugPort:
    _BaudRate = 115200

    def __init__(self, port):
        # Use serial_for_url instead of the standard constructor so that tests can use 'loop://' as the port.
        self._s = serial.serial_for_url(port, baudrate = DebugPort._BaudRate)

        self._buffer = bytearray()
        self._closing = False

        self._e = concurrent.futures.ThreadPoolExecutor(max_workers = 1)

    # Shuts down. Safe to call while a ReadLineAsync is pending.
    def Close(self):
        self._closing = True
        self._s.cancel_read()
        self._e.shutdown()
        self._s.close()

    # Initiates an asynchronous operation to read a line of text from the serial port. The resulting Future
    # completes only when the line has been successfully read, or an error has been encountered.
    def ReadLineAsync(self) -> concurrent.futures.Future:
        return None if self._closing else self._e.submit(self._ReadLine)

    # Blocks until a line of text has been read from the serial port. A line is defined by any sequence of
    # bytes terminating with a newline character (ASCII code 10). The returned line has whitespace
    # (including the terminator) stripped off the end.
    # Returns None in case of error, or if the DebugPort is shutting down due to Close having been called
    # in another thread.
    def _ReadLine(self) -> str:
        # Could possibly have used serial.readline, but I found it to be slow, and I want my own semantics in
        # case of errors.
        lineData = None
        while lineData is None:
            index = self._buffer.find(10)
            if index >= 0:
                lineData = self._buffer[0 : index + 1]
                self._buffer = self._buffer[index + 1 : ]
            else:
                if self._closing:
                    return None
                try:
                    data = self._s.read(max(1, self._s.in_waiting))
                except serial.SerialException:
                    return None
                self._buffer.extend(data)

        # Treat as utf-8, ignoring decode errors.
        return lineData.decode("utf-8", "replace").rstrip()

##########################################################################
# Tests
def setUpModule():
    if sys.version_info < (3, 7):
        raise RuntimeError("ERROR: Python 3.7 or later required")

class Tests(unittest.TestCase):

    def setUp(self):
        self.DebugPort = DebugPort("loop://")
        self.Serial = self.DebugPort._s

    def tearDown(self):
        self.DebugPort.Close()
        del self.DebugPort

    def _ReadLinesTest(self, cases):
        for case in cases:
            receivedBytes = case[0]
            expectedStrings = case[1]
            testMessage = f"in case: {receivedBytes} {expectedStrings}"

            self.Serial.write(receivedBytes)

            futures = []
            for expectedString in expectedStrings:
                future = self.DebugPort.ReadLineAsync()
                self.assertIsInstance(future, concurrent.futures.Future, testMessage)
                futures.append(future)

            done, pending = concurrent.futures.wait(
                futures,
                timeout = 1,
                return_when = concurrent.futures.ALL_COMPLETED)
            self.assertEqual(0, len(pending))
            self.assertSequenceEqual(set(futures), set(done), testMessage)

            actualStrings = [future.result() for future in futures]
            self.assertSequenceEqual(expectedStrings, actualStrings, testMessage)

    # Tests that DebugPort opens the debug port with expected characteristics.
    def testOpenCharacteristics(self):
        self.assertEqual(115200, self.Serial.baudrate)
        self.assertEqual(8, self.Serial.bytesize)
        self.assertEqual(serial.PARITY_NONE, self.Serial.parity)
        self.assertEqual(serial.STOPBITS_ONE, self.Serial.stopbits)
        self.assertEqual(False, self.Serial.xonxoff)
        self.assertEqual(False, self.Serial.rtscts)
        self.assertEqual(False, self.Serial.dsrdtr)

    # Tests that closing a DebugPort is idempotent.
    def testCloseIsIdempotent(self):
        f = self.DebugPort.ReadLineAsync()
        self.assertIsInstance(f, concurrent.futures.Future)
        self.DebugPort.Close()

        f = self.DebugPort.ReadLineAsync()
        self.assertIsNone(f)

        self.DebugPort.Close()
        f = self.DebugPort.ReadLineAsync()
        self.assertIsNone(f)

    # Tests closing a DebugPort without a pending async read.
    def testCloseWithoutReadPending(self):
        self.DebugPort.Close()
        f = self.DebugPort.ReadLineAsync()
        self.assertIsNone(f)

    # Tests closing a DebugPort with a pending async read.
    def testCloseWhileReadPending(self):
        f = self.DebugPort.ReadLineAsync()
        self.assertIsInstance(f, concurrent.futures.Future)
        self.DebugPort.Close()
        f = self.DebugPort.ReadLineAsync()
        self.assertIsNone(f)

    # Tests reception of (non-empty) lines.
    def testReadLines(self):
        # (received, expected)
        cases = \
        [
            (b'abc\n', ["abc"]),                    # Normal string
            (b'\n\n\n', ["", "", ""]),              # Empty lines
            (b'\nabc\n\n', ["", "abc", ""]),        # Empty and non-empty interleaved
            (b'abc\n\ndef\n', ["abc", "", "def"]),  # Empty and non-empty interleaved
            (b'a \t \r\r\n', ["a"]),                # Trailing whitespace
            (b'\xe2\x82\xac\n', ["\u20ac"]),        # UTF-8
            (b'123\xe2xyz\n', ["123\ufffdxyz"]),    # corrupt UTF-8 (replaced with unicode placeholder char)
        ]

        self._ReadLinesTest(cases)

    # Tests reception of lines that are split across receive completions.
    def testReadPartialLines(self):
        # First read leaves an incomplete line;
        # second read completes it.
        self._ReadLinesTest([(b'abc\ndef\nghijk', ["abc", "def"])])

        self._ReadLinesTest([(b'lmn\n', ["ghijklmn"])])

    # Tests reading a closed port.
    def testReadClosed(self):
        f = self.DebugPort.ReadLineAsync()
        self.assertIsInstance(f, concurrent.futures.Future)

        self.DebugPort.Close()

        done, pending = concurrent.futures.wait([f], return_when = concurrent.futures.ALL_COMPLETED)
        self.assertIn(f, done)
        self.assertEqual(0, len(pending))

        # Should result in None.
        self.assertIsNone(f.result())

if __name__ == "__main__":
    unittest.main()
