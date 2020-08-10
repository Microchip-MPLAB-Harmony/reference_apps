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
#include "ack_core_directives.h"
#include "ack_core_heaplet.h"
#include "ack_core_protobuf_utilities.h"
#include "ack_user_config.h"
#include "ack_color_temperature_controller.h"
#include "v3avs_capabilities/V3AVS.pb.h"
#include "v3avs_capabilities/V3Alexa.pb.h"
#include "v3avs_capabilities/V3AlexaColorTemperatureController.pb.h"

#ifdef ACK_COLOR_TEMPERATURE_CONTROLLER

// Calls user-supplied routine(s) to process the directive.
ACKError_t HandleColorTemperatureControllerDirective(void)
{
    V3AVS_AvsDirective* pOuterDirective;
    v3avs_capabilities_V3AlexaColorTemperatureController_Directive* pDirective;
    ACKError_t retval;
    bool protoResult;

    pDirective = (v3avs_capabilities_V3AlexaColorTemperatureController_Directive*)HeapletSetSize(
        MEM_RECEIVED_DIRECTIVE_PAYLOAD,
        sizeof(v3avs_capabilities_V3AlexaColorTemperatureController_Directive));
    if (NULL == pDirective)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    protoResult = ProtobufDecode(
        HeapletAccess(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        HeapletGetSize(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        v3avs_capabilities_V3AlexaColorTemperatureController_Directive_fields,
        pDirective);

    if (!protoResult)
    {
        ACK_DEBUG_PRINT_E("Unable to decode ColorTemperatureController directive payload.");
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    pOuterDirective = (V3AVS_AvsDirective*)HeapletAccess(MEM_RECEIVED_AVS_DIRECTIVE_ENVELOPE);
    retval = ACK_NO_ERROR;

    ACK_REENTRY_SHIELDS_UP;

    switch (pDirective->which_payload)
    {
    case v3avs_capabilities_V3AlexaColorTemperatureController_Directive_increase_color_temperature_tag:
        ACK_DEBUG_PRINT_I("Processing increase color temperature directive");
        ACKUser_OnColorTemperatureControllerIncreaseTemperatureDirective(pOuterDirective->correlation_id);
        break;

    case v3avs_capabilities_V3AlexaColorTemperatureController_Directive_decrease_color_temperature_tag:
        ACK_DEBUG_PRINT_I("Processing decrease color temperature directive");
        ACKUser_OnColorTemperatureControllerDecreaseTemperatureDirective(pOuterDirective->correlation_id);
        break;

    case v3avs_capabilities_V3AlexaColorTemperatureController_Directive_set_color_temperature_tag:
        ACK_DEBUG_PRINT_I("Processing set color temperature directive");
        ACKUser_OnColorTemperatureControllerSetTemperatureDirective(
            pOuterDirective->correlation_id,
            pDirective->payload.set_color_temperature.color_temperature_in_kelvin.value);
        break;

    default:
        ACK_DEBUG_PRINT_W("Unhandled color temp directive payload %u", pDirective->which_payload);
        retval = ACK_ERR_PROTOCOL;
        break;
    }

    ACK_REENTRY_SHIELDS_DOWN;

    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    // NOTE! pDirective and pOuterDirective are now invalid, as processing above can be assumed to have
    // resulted in HeapletSetSize operations.

    retval = ACK_NO_ERROR;

cleanup0:
    HeapletFree(MEM_RECEIVED_DIRECTIVE_PAYLOAD);
    return retval;
}

ACKError_t ACK_AddColorTemperatureControllerProperty(
    const ACKStateCommon_t* pCommon,
    uint32_t valueInKelvin)
{
    ACK_REENTRY_CHECK;

    v3avs_capabilities_V3AlexaColorTemperatureController_ColorTemperatureInKelvinProperty property;

    property.color_temperature_in_kelvin.value = valueInKelvin;

    return CommonEncodeContextProperty(
        V3AVS_Namespace_V3_ALEXA_COLOR_TEMPERATURE_CONTROLLER,
        v3avs_capabilities_V3AlexaColorTemperatureController_PropertyName_COLOR_TEMPERATURE_IN_KELVIN_PROP,
        0, // Instance is not used with this controller.
        pCommon,
        v3avs_capabilities_V3AlexaColorTemperatureController_ColorTemperatureInKelvinProperty_fields,
        &property);
}

#endif // def ACK_COLOR_TEMPERATURE_CONTROLLER
