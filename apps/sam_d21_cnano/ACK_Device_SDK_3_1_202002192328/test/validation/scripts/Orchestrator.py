# Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

import bisect
import concurrent.futures
import sys
import time

import Exceptions
import Multiplexer

from AckModule import *
from AcpChannel import *
from DebugPort import *
from enum import Enum, auto
from HumanReadableStrings import *
from Log import *
from Marker import *
from typing import List

if sys.version_info < (3, 7):
    print(STR_PYTHON_VERSION_REQUIRED.format(3, 7))
    sys.exit(1)

# Manages the simulation. This involves
#   * Listening to the debug port for both regular debug print messages, and Marker traffic.
#   * Running the ACK Module.
#   * Processing markers, which updates state kept in the ACK Module.
class Orchestrator:
    MarkerInstructionPrefix = "@~^"

    def __init__(self, log: Log, ackModule: AckModule, debugPort: DebugPort):
        self._log = log
        self._ackModule = ackModule
        self._debugPort = debugPort

        self._inMarker = False
        self._markerOrdinal = 0

        self._multiplexer = Multiplexer.Multiplexer(0.1)
        self._multiplexer.AddTask(
            self._ackModule.SyncToCommandRequestAsync, 
            self._OnAckModule)
        self._multiplexer.AddTask(
            self._debugPort.ReadLineAsync,
            self._OnDebugPort)

        # Wait for the HMCU to start. This is detected when the RESET signal transitions from not asserted
        # to asserted, and remains asserted for 100ms.
        oldState = False
        assertedTime = None
        lastPrintedTime = None
        hmcuRunning = False
        while not hmcuRunning:
            # Timeout of 25ms is arbitrary. Ensures we don't suck up 100% CPU but also wake up enough
            # to appear responsive to the HMCU asserting the RESET module signal.
            time.sleep(0.025)
            currentTime = time.monotonic()
            if (lastPrintedTime is None) or ((currentTime - lastPrintedTime) >= 2.5):
                self._log.LogLocalString(STR_WAITING_FOR_HMCU)
                lastPrintedTime = currentTime
            currentState = self._ackModule.IsResetAsserted()
            if currentState:
                if not oldState:
                    assertedTime = currentTime
                if (assertedTime is not None) and ((currentTime - assertedTime) >= 0.1):
                    hmcuRunning = True
            oldState = currentState
        self._log.LogLocalString(STR_HMCU_STARTED)

    def Close(self):
        # Call the stop routines on the debug port and ack module channel, even though we're not in
        # either one of their threads. This is necessary because those threads are possibly sitting in
        # blocking I/O operations.
        self._debugPort.Close()
        self._ackModule.Close()

    # Wait for all markers in a list to be satisfied, within a timeout.
    # Raises Exceptions.ValidationFailure if the timeout elapses.
    def WaitForMarkers(self, markers: List[Marker], *, timeout: float, description: str) -> List[Marker]:
        if isinstance(markers, Marker):
            markers = [markers]
        assert (markers is not None) and (len(markers) > 0)
        self._Wait(markers, timeout = timeout, description = description)
        return self._receivedMarkers

    def Delay(self, timeout: float, *, description: str):
        self._Wait(None, timeout = timeout, description = description)

    def StandardStartupProgressionToConnected(self):
        # Note: timeouts in here are more or less arbitrary, based on observing various runs to see
        # how much time is actually needed, with some buffer.
        self._ackModule.SetBooted()

        self.WaitForMarkers(
            Marker(MarkerKind.HMCU_LIFECYCLE_STATE, strings = ["2"]),
            timeout = 5,
            description = STR_STEP_BOOTED)

        self.WaitForMarkers(
            [
                Marker(MarkerKind.MODULE_RECEIVED_HOST_CONFIG),
                Marker(MarkerKind.HMCU_LIFECYCLE_STATE, strings = ["6"])
            ],
            timeout = 5,
            description = STR_STEP_WAIT_HOST_CONFIG)

        self._ackModule.SetIsConnected(True)
        self.WaitForMarkers(
            Marker(MarkerKind.HMCU_LIFECYCLE_STATE, strings = ["7"]),
            timeout = 5,
            description = STR_STEP_CONNECTED)

        delay = 2
        self.Delay(delay, description = STR_STEP_DELAY_X_SECONDS.format(delay))

    # If markers is None or empty, we're waiting only for a timeout.
    def _Wait(self, waitMarkers: List[Marker], *, timeout: float, description: str):
        if waitMarkers is None:
            waitMarkers = []
        self._waitMarkers = waitMarkers
        self._waitMarkersFulfilled = [False] * len(waitMarkers)
        self._waitDueTime = time.monotonic() + timeout
        self._receivedMarkers = []

        while True:
            if not self._multiplexer.Wait():
                # Shutting down.
                return

            timedOut = (time.monotonic() >= self._waitDueTime)

            if timedOut and (len(self._waitMarkersFulfilled) > 0) and (False in self._waitMarkersFulfilled):
                raise Exceptions.ValidationFailure(STR_MARKERS_TIMEOUT.format(description, timeout))

            if (timedOut and (len(self._waitMarkersFulfilled) == 0)) \
                or ((len(self._waitMarkersFulfilled) > 0) and (False not in self._waitMarkersFulfilled)):
                self._log.LogLocalString(STR_MARKERS_FULFILLED.format(description))
                return

    def _OnAckModule(self, result):
        if result:
            markers = self._ackModule.ProcessRequest()
            for marker in markers:
                self._log.Log(
                    LogEntryKind.MODULE_MARKER,
                    strings = [marker.Kind.value] + marker.Strings,
                    extra = marker)
                self._ProcessMarkerForMatches(marker)

    def _OnDebugPort(self, string):
        if string is not None:
            self._ProcessDebugPortString(string)

    def _ProcessMarkerForMatches(self, marker: Marker):

        for index in range(0, len(self._waitMarkersFulfilled)):
            if self._waitMarkersFulfilled[index]:
                continue

            waitMarker = self._waitMarkers[index]

            if marker.Kind != waitMarker.Kind:
                continue

            # To compare the watch to the current marker, we use only the first N strings, where N is
            # the number of strings in the watch. This gives us a form of prefix matching and allows a
            # primitive form of versioning, in that changes don't have to be breaking.
            actualMarkerStrings = marker.Strings
            expectedMarkerStrings = waitMarker.Strings
            if len(actualMarkerStrings) > len(expectedMarkerStrings):
                actualMarkerStrings = actualMarkerStrings[0 : len(expectedMarkerStrings)]
            if actualMarkerStrings == expectedMarkerStrings:
                self._waitMarkersFulfilled[index] = True
                self._receivedMarkers.append(marker)
                break

    # Processes a string on the debug port.
    def _ProcessDebugPortString(self, string: str):
        #print(f"ORCHESTRATOR: debugportstring {string}")

        # Check whether this is a marker instruction.
        # If not, then it has to be either a plain debug print, or a marker string.
        if not string.startswith(Orchestrator.MarkerInstructionPrefix):
            if self._inMarker:
                if self._receivedHmcuMarker is None:
                    try:
                        self._receivedHmcuMarker = Marker(MarkerKind(string))
                    except ValueError:
                        self._receivedHmcuMarker = Marker(MarkerKind.UNKNOWN)
                else:
                    self._receivedHmcuMarker.Strings.append(string)
            else:
                self._log.Log(LogEntryKind.HMCU_DEBUG_PRINT, strings = [string])
            return

        # Process the marker instruction.
        if self._ProcessMarkerInstruction(string):
            self._log.Log(
                LogEntryKind.HMCU_MARKER,
                strings = [self._receivedHmcuMarker.Kind.value] + self._receivedHmcuMarker.Strings)

            # Process matches in current wait.
            self._ProcessMarkerForMatches(self._receivedHmcuMarker)

    # Returns True if self._receivedHmcuMarker now represents a complete marker.
    def _ProcessMarkerInstruction(self, string) -> bool:
        markerInstruction, markerOrdinal, markerTicks = self._ParseMarkerInstruction(string)
        if markerInstruction is None:
            self._LogHmcuMarkerCorruption(string, 1)
            return False

        completeMarker = False

        if markerInstruction == "open":

            if self._inMarker:
                # Nested open.
                self._LogHmcuMarkerCorruption(string, markerOrdinal)
            else:
                # Proper open.
                self._inMarker = True

            assert (markerOrdinal is not None) and (markerTicks is not None)
            self._markerOrdinal = markerOrdinal
            self._receivedHmcuMarker = None

        else:
            assert markerInstruction == "close"
            assert (markerOrdinal is not None) and (markerTicks is None)

            if self._inMarker:
                # Proper close.
                if markerOrdinal != self._markerOrdinal:
                    self._LogHmcuMarkerCorruption(string, markerOrdinal)
                self._inMarker = False
                completeMarker = True
            else:
                # Close without an open.
                self._LogHmcuMarkerCorruption(string, markerOrdinal)

        return completeMarker

    def _ParseMarkerInstruction(self, string):
        parts = string[len(Orchestrator.MarkerInstructionPrefix):].split("*")
        assert len(parts) > 0

        corrupt = False
        markerOrdinal = None
        markerTicks = None

        if parts[0] == "OPEN":
            markerInstruction = "open"
            if len(parts) == 3:
                markerOrdinal = Orchestrator._SafeToInt(parts[1])
                markerTicks = Orchestrator._SafeToInt(parts[2])
                if (markerOrdinal is None) or (markerTicks is None):
                    corrupt = True
            else:
                corrupt = True

        elif parts[0] == "CLOSE":
            markerInstruction = "close"
            if len(parts) == 2:
                markerOrdinal = Orchestrator._SafeToInt(parts[1])
                if markerOrdinal is None:
                    corrupt = True
            else:
                corrupt = True

        else:
            corrupt = True

        if corrupt:
            markerInstruction = None
            markerOrdinal = None
            markerTicks = None

        return markerInstruction, markerOrdinal, markerTicks

    def _LogHmcuMarkerCorruption(self, string: str, ordinal: int):
        # Don't log a negative number.
        count = ordinal - self._markerOrdinal
        if count <= 0:
            count = 1
        self._log.Log(LogEntryKind.HMCU_DEBUG_PORT_CORRUPTION, strings = [string, str(count)])
        if ordinal > self._markerOrdinal:
            self._markerOrdinal = ordinal

    @staticmethod
    def _SafeToInt(string: str) -> int:
        try:
            return int(string)
        except ValueError:
            return None
    
