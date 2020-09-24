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
#include "ack_color_controller.h"
#include "v3avs_capabilities/V3AVS.pb.h"
#include "v3avs_capabilities/V3Alexa.pb.h"
#include "v3avs_capabilities/V3AlexaColorController.pb.h"

#ifdef ACK_COLOR_CONTROLLER

// Calls user-supplied routine to process the directive.
ACKError_t HandleColorControllerDirective(void)
{
    V3AVS_AvsDirective* pOuterDirective;
    v3avs_capabilities_V3AlexaColorController_Directive* pDirective;
    ACKError_t retval;
    bool protoResult;

    pDirective = (v3avs_capabilities_V3AlexaColorController_Directive*)HeapletSetSize(
        MEM_RECEIVED_DIRECTIVE_PAYLOAD,
        sizeof(v3avs_capabilities_V3AlexaColorController_Directive));
    if (NULL == pDirective)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    protoResult = ProtobufDecode(
        HeapletAccess(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        HeapletGetSize(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        v3avs_capabilities_V3AlexaColorController_Directive_fields,
        pDirective);

    if (!protoResult)
    {
        ACK_DEBUG_PRINT_E("Unable to decode ColorController directive payload.");
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    pOuterDirective = (V3AVS_AvsDirective*)HeapletAccess(MEM_RECEIVED_AVS_DIRECTIVE_ENVELOPE);

    if (v3avs_capabilities_V3AlexaColorController_Directive_set_color_tag != pDirective->which_payload)
    {
        ACK_DEBUG_PRINT_E(
            "For ColorController, currently only set-color payloads are handled, not payloads with tag %u",
            pDirective->which_payload)
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    ACK_DEBUG_PRINT_D(
        "ColorController set-color directive; hue %f, saturation %f, brigthness %f",
        pDirective->payload.set_color.color.hue,
        pDirective->payload.set_color.color.saturation,
        pDirective->payload.set_color.color.brightness);

    ACK_REENTRY_SHIELDS_UP;

    ACKUser_OnColorControllerDirective(
        pOuterDirective->correlation_id,
        pDirective->payload.set_color.color.hue,
        pDirective->payload.set_color.color.saturation,
        pDirective->payload.set_color.color.brightness);

    ACK_REENTRY_SHIELDS_DOWN;

    // NOTE! pDirective and pOuterDirective are now invalid, as processing above can be assumed to have
    // resulted in HeapletSetSize operations.

    retval = ACK_NO_ERROR;

cleanup0:
    HeapletFree(MEM_RECEIVED_DIRECTIVE_PAYLOAD);
    return retval;
}

ACKError_t ACK_AddColorControllerProperty(
    const ACKStateCommon_t* pCommon,
    double hue,
    double saturation,
    double brightness)
{
    ACK_REENTRY_CHECK;

    v3avs_capabilities_V3AlexaColorController_ColorProperty property;

    property.color.hue = hue;
    property.color.saturation = saturation;
    property.color.brightness = brightness;

    return CommonEncodeContextProperty(
        V3AVS_Namespace_V3_ALEXA_COLOR_CONTROLLER,
        v3avs_capabilities_V3AlexaColorController_PropertyName_COLOR_PROP,
        0, // Instance is not used with this controller.
        pCommon,
        v3avs_capabilities_V3AlexaColorController_ColorProperty_fields,
        &property);
}

#endif // def ACK_COLOR_CONTROLLER
