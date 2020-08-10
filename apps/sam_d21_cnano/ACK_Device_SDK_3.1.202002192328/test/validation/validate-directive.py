# Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

ProgramVersion = "0.5"

import os.path
import sys

sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "generated-python")))
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "generated-python", "v3avs_capabilities")))
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "generated-python", "v3avs_types")))
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "scripts")))

import AckModule
import AcpChannel
import Avs
import Capability
import DirectiveArgs
import Exceptions
import Log
import Marker
import Program
import Util
import v3avs_capabilities.V3AVS_pb2 as V3AVS_pb2

from HumanReadableStrings import *
from Orchestrator import Orchestrator

# Human-readable strings.
STR_DIRECTIVE_VALIDATOR = "ACK Device SDK directive validator version {0}."
STR_WAIT_FOR_EVENT = "Await event in response to directive"

Program.PrintBanner(STR_DIRECTIVE_VALIDATOR, ProgramVersion)

try:
    # Create the directive.
    args = DirectiveArgs.ParseArgs()

    expectedAvsEvents = []
    protoDirectives = []

    for directiveArgs in args.Directives:
        protoDirective = directiveArgs.Create(directiveArgs)

        expectedAvsEventsForDirective = []
        for eventArgs in directiveArgs.Events:
            protoEvent = eventArgs.Create(eventArgs)

            # Add properties from command line, to the event.
            for propertyArgs in eventArgs.Properties:
                protoProperty = propertyArgs.Create(propertyArgs)
                protoEvent.context.properties.append(protoProperty)

            expectedAvsEvent = Avs.CreateEvent(
                eventArgs.correlation_id,
                V3AVS_pb2.V3AVS.Namespace.Value(eventArgs.event_namespace),
                protoEvent,
                instance = eventArgs.instance)

            expectedAvsEventsForDirective.append(expectedAvsEvent)

        expectedAvsEvents.append(expectedAvsEventsForDirective)
        protoDirectives.append(protoDirective)

except Exceptions.ArgumentFailure as ex:
    print(str(ex))
    sys.exit(1)

log, debugPort, ackModule = Program.InitializeProgram(args)
orchestrator = Orchestrator(log, ackModule, debugPort)

try:
    orchestrator.StandardStartupProgressionToConnected()

    for i in range(len(args.Directives)):
        directiveArgs = args.Directives[i]
        expectedAvsEventsForDirective = expectedAvsEvents[i]
        protoDirective = protoDirectives[i]

        ackModule.SendDirective(
            correlationId = directiveArgs.correlation_id,
            instance = directiveArgs.instance,
            directive = protoDirective,
            namespace = V3AVS_pb2.V3AVS.Namespace.Value(directiveArgs.directive_namespace))

        # Wait for each expected resulting event.
        for expectedAvsEvent in expectedAvsEventsForDirective:
            markers = orchestrator.WaitForMarkers(
                Marker.ReceivedEventMarker(expectedAvsEvent.correlation_id, expectedAvsEvent.v3_namespace),
                timeout = 5,
                description = STR_WAIT_FOR_EVENT)

            # We only asked for one marker, and we should have just that one here.
            assert len(markers) == 1
            actualAvsEvent = markers[0].Extra
            Avs.DecodeEvent(log, actualAvsEvent)
            Avs.CompareEvent(log, expectedAvsEvent, actualAvsEvent)

    success = True

except Exceptions.ValidationFailure as ex:
    log.LogLocalString(str(ex))
    success = False

orchestrator.Close()

log.LogLocalString(STR_PASS if success else STR_FAIL)
sys.exit(0 if success else 1)
