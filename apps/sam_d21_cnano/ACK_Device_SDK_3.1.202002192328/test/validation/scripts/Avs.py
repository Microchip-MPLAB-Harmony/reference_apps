# Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

import Capability
import Exceptions
import Util
import v3avs_capabilities.V3AVS_pb2 as V3AVS_pb2

from HumanReadableStrings import *
from Log import *

# Decodes an AVS event.
# Raises ValidationFailure in case of failure.
# Returns the decoded event (AVS event payload).
def DecodeEvent(log: Log, avsEvent: V3AVS_pb2.V3AVS.AvsEvent):

    if log is not None:
        logString = STR_DECODING_AVS_EVENT.format(
            avsEvent.correlation_id,
            Util.NameForEnumValue(V3AVS_pb2.V3AVS.Namespace, avsEvent.v3_namespace),
            avsEvent.instance,
            Util.EpochToString(avsEvent.timestamp))
        log.LogLocalString(logString)

    return Capability.EventDefinition.Decode(log, avsEvent.v3_namespace, avsEvent.payload)

def CompareEvent(log: Log, expectedAvsEvent: V3AVS_pb2.V3AVS.AvsEvent, actualAvsEvent: V3AVS_pb2.V3AVS.AvsEvent):

    if actualAvsEvent.correlation_id != expectedAvsEvent.correlation_id:
        raise Exceptions.ValidationFailure(STR_MISMATCHED_CORRELATION_ID.format(
            expectedAvsEvent.correlation_id,
            actualAvsEvent.correlation_id))

    namespace = actualAvsEvent.v3_namespace
    if namespace != expectedAvsEvent.v3_namespace:
        raise Exceptions.ValidationFailure(STR_MISMATCHED_NAMESPACE.format(
            Util.NameForEnumValue(V3AVS_pb2.V3AVS.Namespace, expectedAvsEvent.v3_namespace),
            Util.NameForEnumValue(V3AVS_pb2.V3AVS.Namespace, actualAvsEvent.v3_namespace)))

    if actualAvsEvent.instance != expectedAvsEvent.instance:
        raise Exceptions.ValidationFailure(STR_MISMATCHED_INSTANCE_ID.format(
            expectedAvsEvent.instance,
            actualAvsEvent.instance))

    decodedExpected = DecodeEvent(None, expectedAvsEvent)
    decodedActual = DecodeEvent(None, actualAvsEvent)

    Capability.EventDefinition.Compare(log, namespace, decodedExpected, decodedActual)

# Creates an AVS event.
def CreateEvent(
    correlationId: int,
    namespace: int,
    unencodedPayload,
    *,
    instance: int = 0) -> V3AVS_pb2.V3AVS.AvsEvent:

    avsEvent = V3AVS_pb2.V3AVS.AvsEvent()

    if correlationId is not None:
        avsEvent.correlation_id = correlationId
    avsEvent.v3_namespace = namespace
    avsEvent.instance = instance

    avsEvent.payload = unencodedPayload.SerializeToString()

    return avsEvent

