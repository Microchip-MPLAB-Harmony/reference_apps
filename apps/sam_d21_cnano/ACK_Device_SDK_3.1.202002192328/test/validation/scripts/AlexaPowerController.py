# Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
#
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

import v3avs_capabilities.V3AlexaPowerController_pb2 as V3AlexaPowerController_pb2
import v3avs_capabilities.V3AVS_pb2 as V3AVS_pb2
import Capability

class TurnOnDirectiveDefinition(Capability.DirectiveDefinition):
    def __init__(self):
        super().__init__(
            protoNameValue = V3AlexaPowerController_pb2.V3AlexaPowerController.DirectiveName.TURN_ON,
            payloadSubmessageName = "turn_on")

    @staticmethod
    def _PopulateCommandLineArguments(argparser):
        pass # No args for this directive.

    @staticmethod
    def _PopulateFromCommandLineArguments(protoDirective, args):
        pass # No args for this directive.

class TurnOffDirectiveDefinition(Capability.DirectiveDefinition):
    def __init__(self):
        super().__init__(
            protoNameValue = V3AlexaPowerController_pb2.V3AlexaPowerController.DirectiveName.TURN_OFF,
            payloadSubmessageName = "turn_off")

    @staticmethod
    def _PopulateCommandLineArguments(argparser):
        pass # No args for this directive.

    @staticmethod
    def _PopulateFromCommandLineArguments(protoDirective, args):
        pass # No args for this directive.

class PowerStatePropertyDefinition(Capability.PropertyDefinition):
    def __init__(self):
        super().__init__(
            protoNameValue = V3AlexaPowerController_pb2.V3AlexaPowerController.PropertyName.POWER_STATE_PROP,
            protoValueClass = V3AlexaPowerController_pb2.V3AlexaPowerController.PowerStateProperty)

    @staticmethod
    def _PopulateCommandLineArguments(argparser):
        argparser.add_argument("--power-state", type = int, required = True)

    @staticmethod
    def _PopulateFromCommandLineArguments(protoPropertyValue, args):
        protoPropertyValue.power_state.value = args.power_state
        print("power_state = " + str(args))

    @staticmethod
    def _CompareValue(expectedValue, actualValue):
        return actualValue.power_state.value == expectedValue.power_state.value

Capability = Capability.Capability(
    V3AVS_pb2.V3AVS.Namespace.V3_ALEXA_POWER_CONTROLLER,
    protoDirectiveClass = V3AlexaPowerController_pb2.V3AlexaPowerController.Directive,
    protoDirectiveClassNameField = "directive_name",
    protoDirectiveNameEnum = V3AlexaPowerController_pb2.V3AlexaPowerController.DirectiveName,
    protoPropertyNameEnum = V3AlexaPowerController_pb2.V3AlexaPowerController.PropertyName,
    directives = [ TurnOnDirectiveDefinition(), TurnOffDirectiveDefinition() ],
    properties = [ PowerStatePropertyDefinition() ])

