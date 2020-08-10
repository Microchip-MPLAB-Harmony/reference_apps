# Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

import v3avs_capabilities.V3AlexaEndpointHealth_pb2 as V3AlexaEndpointHealth_pb2
import v3avs_capabilities.V3AVS_pb2 as V3AVS_pb2
import Capability

class ConnectivityPropertyDefinition(Capability.PropertyDefinition):
    def __init__(self):
        super().__init__(
            protoNameValue = V3AlexaEndpointHealth_pb2.V3AlexaEndpointHealth.PropertyName.CONNECTIVITY_PROP,
            protoValueClass = V3AlexaEndpointHealth_pb2.V3AlexaEndpointHealth.ConnectivityProperty)

    @staticmethod
    def _PopulateCommandLineArguments(argparser):
        argparser.add_argument("--connectivity", type = int, required = True)

    @staticmethod
    def _PopulateFromCommandLineArguments(protoPropertyValue, args):
        protoPropertyValue.connectivity.value.value = args.connectivity

    @staticmethod
    def _CompareValue(expectedValue, actualValue):
        return actualValue.connectivity.value.value == expectedValue.connectivity.value.value

Capability = Capability.Capability(
    V3AVS_pb2.V3AVS.Namespace.V3_ALEXA_ENDPOINT_HEALTH,
    protoPropertyNameEnum = V3AlexaEndpointHealth_pb2.V3AlexaEndpointHealth.PropertyName,
    properties = [ ConnectivityPropertyDefinition() ])
