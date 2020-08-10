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
#include "ack_brightness_controller.h"
#include "v3avs_capabilities/V3Alexa.pb.h"
#include "v3avs_capabilities/V3AlexaBrightnessController.pb.h"

#ifdef ACK_BRIGHTNESS_CONTROLLER

// Calls user-supplied routine to process the directive.
ACKError_t HandleBrightnessControllerDirective(void)
{
    V3AVS_AvsDirective* pOuterDirective;
    v3avs_capabilities_V3AlexaBrightnessController_Directive* pDirective;
    ACKError_t retval;
    bool protoResult;
    bool isDelta;
    int32_t value;

    pDirective = (v3avs_capabilities_V3AlexaBrightnessController_Directive*)HeapletSetSize(
        MEM_RECEIVED_DIRECTIVE_PAYLOAD,
        sizeof(v3avs_capabilities_V3AlexaBrightnessController_Directive));
    if (NULL == pDirective)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    protoResult = ProtobufDecode(
        HeapletAccess(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        HeapletGetSize(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        v3avs_capabilities_V3AlexaBrightnessController_Directive_fields,
        pDirective);

    if (!protoResult)
    {
        ACK_DEBUG_PRINT_E("Unable to decode brightness controller directive payload.");
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    pOuterDirective = (V3AVS_AvsDirective*)HeapletAccess(MEM_RECEIVED_AVS_DIRECTIVE_ENVELOPE);

    isDelta = pDirective->which_payload
        == v3avs_capabilities_V3AlexaBrightnessController_Directive_adjust_brightness_tag;

    if (isDelta)
    {
        value = pDirective->payload.adjust_brightness.brightness_delta.value;
        ACK_DEBUG_PRINT_D("BrightnessController directive; brightness %d", value);
    }
    else
    {
        value = pDirective->payload.set_brightness.brightness.value;
        ACK_DEBUG_PRINT_D("BrightnessController directive; absolute brightness %u", value);
    }

    ACK_REENTRY_SHIELDS_UP;

    ACKUser_OnBrightnessControllerDirective(pOuterDirective->correlation_id, isDelta, value);

    ACK_REENTRY_SHIELDS_DOWN;

    // NOTE! pDirective is now invalid, as processing above can be assumed to have resulted in
    // HeapletSetSize operations.

    retval = ACK_NO_ERROR;

cleanup0:
    HeapletFree(MEM_RECEIVED_DIRECTIVE_PAYLOAD);
    return retval;
}

ACKError_t ACK_AddBrightnessControllerProperty(
    const ACKStateCommon_t* pCommon,
    int32_t brightness)
{
    ACK_REENTRY_CHECK;

    v3avs_capabilities_V3AlexaBrightnessController_BrightnessProperty property;
    property.brightness.value = brightness;

    return CommonEncodeContextProperty(
        V3AVS_Namespace_V3_ALEXA_BRIGHTNESS_CONTROLLER,
        v3avs_capabilities_V3AlexaBrightnessController_PropertyName_BRIGHTNESS_PROP,
        0, // instance not used for this controller
        pCommon,
        v3avs_capabilities_V3AlexaBrightnessController_BrightnessProperty_fields,
        &property);
}

#endif // def ACK_BRIGHTNESS_CONTROLLER
