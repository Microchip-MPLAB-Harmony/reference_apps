# Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

import Capability

from enum import Enum, auto
from typing import List

# Markers.
# The HMCU ones must match the values in ack_core_validation.h.
class MarkerKind(Enum):
    UNKNOWN = "UNKNOWN"

    # HMCU-originating markers.
    HMCU_LIFECYCLE_STATE = "LIFECYCLE-STATE"
    HMCU_PROTOCOL_ERROR = "PROTOCOL-ERROR"
    HMCU_READ_OTA_CHUNK_ERROR = "OTA-CHUNK-ERROR"
    HMCU_READ_OTA_CHUNK_SUCCESS = "OTA-CHUNK-DOWNLOADED"
    HMCU_OTA_COMPLETE = "OTA-COMPLETE"
    HMCU_OTA_RESTART_DEVICE = "OTA-RESTART"

    # Module-originating markers.
    MODULE_RECEIVED_HOST_CONFIG = "MODULE-RECEIVED-HOST-CONFIG"
    MODULE_RECEIVED_EVENT = "OUTBOUND_EVENT"

class Marker:
    def __init__(self, kind: MarkerKind, *, strings: List[str] = None, extra = None):
        self.Kind = kind
        self.Strings = [] if (strings is None) else strings
        self.Extra = extra

class ReceivedEventMarker(Marker):
    def __init__(self, correlation_id: int, namespace: int, *, instance: int = 0, avsEventAsExtra = None):
        super().__init__(
            MarkerKind.MODULE_RECEIVED_EVENT,
            strings =
            [
                str(correlation_id),
                str(namespace),
                str(instance)
            ],
            extra = avsEventAsExtra)

    @staticmethod
    def FromAvsEvent(avsEvent):
        return ReceivedEventMarker(
            avsEvent.correlation_id,
            avsEvent.v3_namespace,
            instance = avsEvent.instance,
            avsEventAsExtra = avsEvent)
    