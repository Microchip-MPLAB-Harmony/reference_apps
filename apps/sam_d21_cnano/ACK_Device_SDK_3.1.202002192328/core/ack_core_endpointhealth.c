/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#include "ack.h"
#include "ack_core_common.h"
#include "ack_core_protobuf_utilities.h"
#include "v3avs_capabilities/V3Alexa.pb.h"
#include "v3avs_capabilities/V3AlexaEndpointHealth.pb.h"

ACKError_t EndpointHealthAddPropertyToEvent(const ACKStateCommon_t* pCommon)
{
    v3avs_capabilities_V3AlexaEndpointHealth_ConnectivityProperty property;
    property.connectivity.value.value = v3avs_types_V3Connectivity_V3ConnectivityValueEnum_Value_OK;

    return CommonEncodeContextProperty(
        V3AVS_Namespace_V3_ALEXA_ENDPOINT_HEALTH,
        v3avs_capabilities_V3AlexaEndpointHealth_PropertyName_CONNECTIVITY_PROP,
        0, // instance not used for this controller
        pCommon,
        v3avs_capabilities_V3AlexaEndpointHealth_ConnectivityProperty_fields,
        &property);
}
