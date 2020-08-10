# Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

import Avs
import Exceptions
import google.protobuf.text_format
import typing
import Util
import v3avs_capabilities.V3Alexa_pb2 as V3Alexa_pb2
import v3avs_capabilities.V3AVS_pb2 as V3AVS_pb2

from Capability import DirectiveDefinition
from Capability import EventDefinition
from Capability import PropertyDefinition
from HumanReadableStrings import *
from Log import *

def _DecodeEventCommon(log, protoEvent: V3Alexa_pb2.V3Alexa.Event):
    if log is not None:
        logString = STR_DECODING_EVENT_IN_NAMESPACE.format(
            Util.NameForEnumValue(V3AVS_pb2.V3AVS.Namespace, V3AVS_pb2.V3AVS.Namespace.V3_ALEXA),
            Util.NameForEnumValue(V3Alexa_pb2.V3Alexa.EventName, protoEvent.name),
            len(protoEvent.context.properties))
        log.LogLocalString(logString)

    for protoProperty in protoEvent.context.properties:
        PropertyDefinition.Decode(log, protoProperty)

def _CompareEventCommon(expectedProtoEvent: V3Alexa_pb2.V3Alexa.Event, actualProtoEvent: V3Alexa_pb2.V3Alexa.Event):

    propertyCount = len(expectedProtoEvent.context.properties)
    if propertyCount != len(actualProtoEvent.context.properties):
        err = STR_MISMATCHED_PROPERTY_COUNT.format(
            len(expectedProtoEvent.context.properties),
            len(actualProtoEvent.context.properties))
        raise Exceptions.ValidationFailure(err)

    for index in range(propertyCount):
        expectedProtoProperty = expectedProtoEvent.context.properties[index]
        actualProtoProperty = actualProtoEvent.context.properties[index]
        PropertyDefinition.Compare(expectedProtoProperty, actualProtoProperty)

class StateReportDirectiveDefinition(DirectiveDefinition):
    def __init__(self):
        super().__init__(
            protoNameValue = V3Alexa_pb2.V3Alexa.DirectiveName.REPORT_STATE,
            payloadSubmessageName = "report_state")

    @staticmethod
    def _PopulateCommandLineArguments(argparser):
        pass # No args for this directive.

    @staticmethod
    def _PopulateFromCommandLineArguments(protoEvent: V3Alexa_pb2.V3Alexa.Event, args):
        pass # No args for this directive.

class DirectiveResponseEventDefinition(EventDefinition):
    def __init__(self):
        super().__init__(
            protoNameValue = V3Alexa_pb2.V3Alexa.EventName.RESPONSE,
            payloadSubmessageName = "response")

    @staticmethod
    def _PopulateCommandLineArguments(argparser):
        pass # No args for this event.

    @staticmethod
    def _PopulateFromCommandLineArguments(protoEvent: V3Alexa_pb2.V3Alexa.Event, args):
        pass # No args for this event; properties are handled by the caller.

    # Raises ValidationError in case of decoding failure.
    @staticmethod
    def _Decode(log, protoEvent: V3Alexa_pb2.V3Alexa.Event):
        _DecodeEventCommon(log, protoEvent)

    @staticmethod
    def _Compare(expectedProtoEvent: V3Alexa_pb2.V3Alexa.Event, actualProtoEvent: V3Alexa_pb2.V3Alexa.Event):
        _CompareEventCommon(expectedProtoEvent, actualProtoEvent)

class StateReportEventDefinition(EventDefinition):
    def __init__(self):
        super().__init__(
            protoNameValue = V3Alexa_pb2.V3Alexa.EventName.STATE_REPORT,
            payloadSubmessageName = "state_report")

    @staticmethod
    def _PopulateCommandLineArguments(argparser):
        pass # No args for this event.

    @staticmethod
    def _PopulateFromCommandLineArguments(protoEvent: V3Alexa_pb2.V3Alexa.Event, args):
        pass # No args for this event; properties are handled by the caller.

    # Raises ValidationError in case of decoding failure.
    @staticmethod
    def _Decode(log, protoEvent: V3Alexa_pb2.V3Alexa.Event):
        _DecodeEventCommon(log, protoEvent)

    @staticmethod
    def _Compare(expectedProtoEvent: V3Alexa_pb2.V3Alexa.Event, actualProtoEvent: V3Alexa_pb2.V3Alexa.Event):
        _CompareEventCommon(expectedProtoEvent, actualProtoEvent)

class ChangeReportEventDefinition(EventDefinition):
    def __init__(self):
        super().__init__(
            protoNameValue = V3Alexa_pb2.V3Alexa.EventName.CHANGE_REPORT,
            payloadSubmessageName = "change_report")

    @staticmethod
    def _PopulateCommandLineArguments(argparser):
        pass # No args for this event.

    @staticmethod
    def _PopulateFromCommandLineArguments(protoEvent: V3Alexa_pb2.V3Alexa.Event, args):
        pass # No args for this event; properties are handled by the caller.

    # Raises ValidationError in case of decoding failure.
    @staticmethod
    def _Decode(log, protoEvent: V3Alexa_pb2.V3Alexa.Event):
        _DecodeEventCommon(log, protoEvent)

    @staticmethod
    def _Compare(expectedProtoEvent: V3Alexa_pb2.V3Alexa.Event, actualProtoEvent: V3Alexa_pb2.V3Alexa.Event):
        _CompareEventCommon(expectedProtoEvent, actualProtoEvent)

Capability = Capability.Capability(
    V3AVS_pb2.V3AVS.Namespace.V3_ALEXA,
    protoDirectiveClass = V3Alexa_pb2.V3Alexa.Directive,
    protoDirectiveClassNameField = "directive_name",
    protoDirectiveNameEnum = V3Alexa_pb2.V3Alexa.DirectiveName,
    protoEventClass = V3Alexa_pb2.V3Alexa.Event,
    protoEventClassNameField = "name",
    protoEventNameEnum = V3Alexa_pb2.V3Alexa.EventName,
    directives = [ StateReportDirectiveDefinition() ],
    events = \
    [ \
        DirectiveResponseEventDefinition(),
        StateReportEventDefinition(),
        ChangeReportEventDefinition()
    ])
