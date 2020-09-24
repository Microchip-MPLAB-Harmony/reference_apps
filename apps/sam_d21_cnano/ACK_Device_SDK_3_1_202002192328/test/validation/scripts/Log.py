# Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

import threading
import time

from enum import *
from HumanReadableStrings import *
from Marker import *
from typing import List, Tuple

# The second element in the tuple indicates whether the entry kind should be shown only
# when verbose output is enabled.
class LogEntryKind(Enum):
    LOCAL_STRING = ("LOCAL", False)
    HMCU_MARKER = ("MARKER", True)
    MODULE_MARKER = ("MARKER", True)
    HMCU_DEBUG_PRINT = ("HMCU", False)
    HMCU_DEBUG_PORT_CORRUPTION = ("CORRUPTION", False)

class Log:
    def __init__(self, *, verbose: bool = False):
        self._entries = []
        self._verbose = verbose
        self._markerCounts = {}

    # Creates an entry in the log.
    def Log(self, entryKind: LogEntryKind, *, strings: List[str], extra = None):
        now = time.time()
        self._entries.append((now, entryKind, strings, extra))

        prefix = entryKind.value[0]
        verbose = entryKind.value[1]

        if (not verbose) or self._verbose:

            localNow = time.localtime(now)

            string = "[{0}:{1:02}:{2:02}.{3:.3f}] [{6}] {4}{5}".format(
                localNow.tm_hour,
                localNow.tm_min,
                localNow.tm_sec,
                now - int(now),
                ("[" + prefix + "] ") if self._verbose else "",
                " ".join(strings),
                threading.get_native_id())

            print(string)

        if entryKind == LogEntryKind.HMCU_MARKER:
             self._markerCounts[strings[0]] = self._markerCounts.get(strings[0], 0) + 1

    def LogLocalString(self, string: str):
        self.Log(LogEntryKind.LOCAL_STRING, strings = [string])

    @property
    def Entries(self) -> List[Tuple[float, LogEntryKind, List[str], ]]:
        return self._entries

    @property
    def EntryCount(self) -> int:
        return len(self._entries)

    def EntryAt(self, index) -> Tuple[float, LogEntryKind, List[str], ]:
        return self._entries[index]

    def MarkerOccurrenceCount(self, marker: MarkerKind):
        return self._markerCounts.get(marker.value, 0)