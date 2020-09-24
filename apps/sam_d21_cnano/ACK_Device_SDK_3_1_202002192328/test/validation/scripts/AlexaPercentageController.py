# Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

import v3avs_capabilities.V3AlexaPercentageController_pb2 as V3AlexaPercentageController_pb2
import v3avs_capabilities.V3AVS_pb2 as V3AVS_pb2
import Capability

class SetPercentageDirectiveDefinition(Capability.DirectiveDefinition):
    def __init__(self):
        super().__init__(
            protoNameValue = V3AlexaPercentageController_pb2.V3AlexaPercentageController.DirectiveName.SET_PERCENTAGE,
            payloadSubmessageName = "set_percentage")

    @staticmethod
    def _PopulateCommandLineArguments(argparser):
        argparser.add_argument("--value", type = int, required = True)

    @staticmethod
    def _PopulateFromCommandLineArguments(protoDirective, args):
        protoDirective.set_percentage.percentage.value = args.value

class AdjustPercentageDirectiveDefinition(Capability.DirectiveDefinition):
    def __init__(self):
        super().__init__(
            protoNameValue = V3AlexaPercentageController_pb2.V3AlexaPercentageController.DirectiveName.ADJUST_PERCENTAGE,
            payloadSubmessageName = "adjust_percentage")

    @staticmethod
    def _PopulateCommandLineArguments(argparser):
        argparser.add_argument("--delta", type = int, required = True)

    @staticmethod
    def _PopulateFromCommandLineArguments(protoDirective, args):
        protoDirective.adjust_percentage.percentage_delta.value = args.delta

class PercentagePropertyDefinition(Capability.PropertyDefinition):
    def __init__(self):
        super().__init__(
            protoNameValue = V3AlexaPercentageController_pb2.V3AlexaPercentageController.PropertyName.PERCENTAGE_PROP,
            protoValueClass = V3AlexaPercentageController_pb2.V3AlexaPercentageController.PercentageProperty)

    @staticmethod
    def _PopulateCommandLineArguments(argparser):
        argparser.add_argument("--percentage", type = int, required = True)

    @staticmethod
    def _PopulateFromCommandLineArguments(protoPropertyValue, args):
        protoPropertyValue.percentage.value = args.percentage

    @staticmethod
    def _CompareValue(expectedValue, actualValue):
        return actualValue.percentage.value == expectedValue.percentage.value

Capability = Capability.Capability(
    V3AVS_pb2.V3AVS.Namespace.V3_ALEXA_PERCENTAGE_CONTROLLER,
    protoDirectiveClass = V3AlexaPercentageController_pb2.V3AlexaPercentageController.Directive,
    protoDirectiveClassNameField = "directive_name",
    protoDirectiveNameEnum = V3AlexaPercentageController_pb2.V3AlexaPercentageController.DirectiveName,
    protoPropertyNameEnum = V3AlexaPercentageController_pb2.V3AlexaPercentageController.PropertyName,
    directives = [ SetPercentageDirectiveDefinition(), AdjustPercentageDirectiveDefinition() ],
    properties = [ PercentagePropertyDefinition() ])
