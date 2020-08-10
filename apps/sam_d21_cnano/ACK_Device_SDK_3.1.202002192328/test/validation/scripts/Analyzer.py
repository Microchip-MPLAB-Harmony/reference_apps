# Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

import typing

from enum import Enum, auto
from HumanReadableStrings import *
from Log import Log, LogEntryKind
from Marker import *

class MessageSeverity(Enum):
    INFO = "Info"
    WARNING = "Warning"
    ERROR = "ERROR"

# Analyzes program output such as Markers, according to a set of caller-defined rules.
class Analyzer:
    def __init__(
        self,
        log: Log,
        rules: typing.List[typing.Callable[[Log], typing.Tuple[bool, typing.List[str]]]]):
        
        self._log = log
        self._rules = rules

    def Analyze(self):
        if (self._rules is None) or (len(self._rules)) == 0:
            self._result = False
            self._resultStrings = Analyzer.CreateMessage(MessageSeverity.ERROR, STR_NO_ANALYSIS_RULES)
            return

        result = True
        strings = []

        for rule in self._rules:
            r, s = rule.Analyze(self._log)

            result = result and r
            if s is not None:
                strings.extend(s)

        self._result = result
        self._resultStrings = strings

    def LogResult(self):
        for s in self._resultStrings:
            self._log.LogLocalString(s)
        self._log.LogLocalString(STR_PASS if self._result else STR_FAIL)
        return self._result

    @staticmethod
    def CreateMessage(severity: MessageSeverity, string: str) -> str:
        return f"{severity.value}: {string}"

# Rule to analyze communications errors.
class CommunicationsErrorsRule:
    def Analyze(self, log: Log):
        entryCount = log.EntryCount

        # We might see some comms errors prior to the lifecycle state becoming BOOTED (2).
        # Lifecycle states are in ack.h.
        ioErrorCount = log.MarkerOccurrenceCount(MarkerKind.HMCU_PROTOCOL_ERROR)
        
        if ioErrorCount > 0:

            bootedLifecycleStateChangeIndex = entryCount

            for i in range(0, entryCount):
                strings = log.EntryAt(i)[2]
                if strings == [MarkerKind.HMCU_LIFECYCLE_STATE.value, "2"]:
                    bootedLifecycleStateChangeIndex = i
                    break

            # See if any errors occured subsequently to the transition to booted lifecycle state.
            for i in range(bootedLifecycleStateChangeIndex, entryCount):
                strings = log.EntryAt(i)[2]
                if strings[0] == "PROTOCOL-ERROR":
                    return False, [ Analyzer.CreateMessage(MessageSeverity.ERROR, STR_UNSTABLE_UART_COMMS) ]

        return True, [ Analyzer.CreateMessage(MessageSeverity.INFO, STR_STABLE_UART_COMMS) ]

# Rule to check that an OTA update was applied successfully through to the point where the device
# would restart.
class OtaUpdateRetrievedAndAppliedRule:
    def __init__(self, otaImageSize: int):
        self._otaImageSize = otaImageSize

    def Analyze(self, log: Log):
        entryCount = log.EntryCount
        result = True
        resultStrings = []

        chunkErrorCount = log.MarkerOccurrenceCount(MarkerKind.HMCU_READ_OTA_CHUNK_ERROR)
        chunkDownloadedCount = log.MarkerOccurrenceCount(MarkerKind.HMCU_READ_OTA_CHUNK_SUCCESS)

        restarted = False
        for i in reversed(range(0, entryCount)):
            strings = log.EntryAt(i)[2]
            if strings[0] == MarkerKind.HMCU_OTA_RESTART_DEVICE.value:
                restarted = True
                break

        if chunkDownloadedCount == 0:
            result = False
            resultStrings.append(Analyzer.CreateMessage(MessageSeverity.ERROR, STR_OTA_NOT_RETRIEVED))

        # The error count is the number of times a chunk couldn't be downloaded on the first try.
        # Allow one error, because there's a special case in the ACK module that fails exactly one
        # attempt at downloading the first chunk.
        elif chunkErrorCount > 1:
            result = False
            resultStrings.append(Analyzer.CreateMessage(
                MessageSeverity.ERROR,
                STR_OTA_CHUNK_RETRIES.format(chunkErrorCount - 1)))

        elif not restarted:
            result = False
            resultStrings.append(Analyzer.CreateMessage(
                MessageSeverity.ERROR,
                STR_OTA_NOT_APPLIED.format(self._otaImageSize)))

        else:
            resultStrings.append(Analyzer.CreateMessage(MessageSeverity.INFO, STR_OTA_APPLIED))

        return result, resultStrings
