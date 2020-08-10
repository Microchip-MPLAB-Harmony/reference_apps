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
#include "ack_mode_controller.h"
#include "ack_core_protobuf_utilities.h"
#include "ack_user_config.h"
#include "v3avs_capabilities/V3AVS.pb.h"
#include "v3avs_capabilities/V3Alexa.pb.h"
#include "v3avs_capabilities/V3AlexaModeController.pb.h"

#ifdef ACK_MODE_CONTROLLER

// Calls user-supplied routine to process the directive.
ACKError_t HandleModeControllerDirective(void)
{
    V3AVS_AvsDirective* pOuterDirective;
    v3avs_capabilities_V3AlexaModeController_Directive* pDirective;
    ACKError_t retval;
    bool protoResult;
    bool isDelta;
    int32_t value;

    pDirective = (v3avs_capabilities_V3AlexaModeController_Directive*)HeapletSetSize(
        MEM_RECEIVED_DIRECTIVE_PAYLOAD,
        sizeof(v3avs_capabilities_V3AlexaModeController_Directive));
    if (NULL == pDirective)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    protoResult = ProtobufDecode(
        HeapletAccess(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        HeapletGetSize(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        v3avs_capabilities_V3AlexaModeController_Directive_fields,
        pDirective);

    if (!protoResult)
    {
        ACK_DEBUG_PRINT_E("Unable to decode ModeController directive payload.");
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    pOuterDirective = (V3AVS_AvsDirective*)HeapletAccess(MEM_RECEIVED_AVS_DIRECTIVE_ENVELOPE);

    isDelta = pDirective->which_payload
        == v3avs_capabilities_V3AlexaModeController_Directive_adjust_mode_tag;

    if (isDelta)
    {
        value = pDirective->payload.adjust_mode.mode_delta.value;

        ACK_DEBUG_PRINT_D(
            "ModeController directive; instance %u, mode delta %d",
            pOuterDirective->instance,
            value);
    }
    else
    {
        value = (int32_t)pDirective->payload.set_mode.mode.mode;
        ACK_DEBUG_PRINT_D("ModeController directive; instance %u, mode %u", pOuterDirective->instance, value);
    }

    ACK_REENTRY_SHIELDS_UP;

    ACKUser_OnModeControllerDirective(
        pOuterDirective->correlation_id,
        pOuterDirective->instance,
        isDelta,
        value);

    ACK_REENTRY_SHIELDS_DOWN;

    // NOTE! pDirective and pOuterDirective are now invalid, as processing above can be assumed to have
    // resulted in HeapletSetSize operations.

    retval = ACK_NO_ERROR;

cleanup0:
    HeapletFree(MEM_RECEIVED_DIRECTIVE_PAYLOAD);
    return retval;
}

ACKError_t ACK_AddModeControllerProperty(
    uint32_t instance,
    const ACKStateCommon_t* pCommon,
    uint32_t mode)
{
    ACK_REENTRY_CHECK;

    v3avs_capabilities_V3AlexaModeController_ModeProperty property;
    property.mode.mode = mode;

    return CommonEncodeContextProperty(
        V3AVS_Namespace_V3_ALEXA_MODE_CONTROLLER,
        v3avs_capabilities_V3AlexaModeController_PropertyName_MODE_PROP,
        instance,
        pCommon,
        v3avs_capabilities_V3AlexaModeController_ModeProperty_fields,
        &property);
}

#endif // def ACK_MODE_CONTROLLER
