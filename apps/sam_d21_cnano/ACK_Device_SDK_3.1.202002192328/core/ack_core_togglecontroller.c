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
#include "ack_toggle_controller.h"
#include "ack_user_config.h"
#include "v3avs_capabilities/V3AVS.pb.h"
#include "v3avs_capabilities/V3Alexa.pb.h"
#include "v3avs_capabilities/V3AlexaToggleController.pb.h"

#ifdef ACK_TOGGLE_CONTROLLER

// Calls user-supplied routine to process the directive.
ACKError_t HandleToggleControllerDirective(void)
{
    V3AVS_AvsDirective* pOuterDirective;
    v3avs_capabilities_V3AlexaToggleController_Directive* pDirective;
    ACKError_t retval;
    bool protoResult;
    bool value;

    pDirective = (v3avs_capabilities_V3AlexaToggleController_Directive*)HeapletSetSize(
        MEM_RECEIVED_DIRECTIVE_PAYLOAD,
        sizeof(v3avs_capabilities_V3AlexaToggleController_Directive));
    if (NULL == pDirective)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    protoResult = ProtobufDecode(
        HeapletAccess(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        HeapletGetSize(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        v3avs_capabilities_V3AlexaToggleController_Directive_fields,
        pDirective);

    if (!protoResult)
    {
        ACK_DEBUG_PRINT_E("Unable to decode ToggleController directive payload.");
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    pOuterDirective = (V3AVS_AvsDirective*)HeapletAccess(MEM_RECEIVED_AVS_DIRECTIVE_ENVELOPE);

    value = pDirective->which_payload == v3avs_capabilities_V3AlexaToggleController_Directive_turn_on_tag;
    ACK_DEBUG_PRINT_D("ToggleController directive; instance %u, state %u", pOuterDirective->instance, value);

    ACK_REENTRY_SHIELDS_UP;

    ACKUser_OnToggleControllerDirective(pOuterDirective->correlation_id, pOuterDirective->instance, value);

    ACK_REENTRY_SHIELDS_DOWN;

    // NOTE! pDirective and pOuterDirective are now invalid, as processing above can be assumed to have
    // resulted in HeapletSetSize operations.

    retval = ACK_NO_ERROR;

cleanup0:
    HeapletFree(MEM_RECEIVED_DIRECTIVE_PAYLOAD);
    return retval;
}

ACKError_t ACK_AddToggleControllerProperty(
    uint32_t instance,
    const ACKStateCommon_t* pCommon,
    bool value)
{
    ACK_REENTRY_CHECK;

    v3avs_capabilities_V3AlexaToggleController_ToggleStateProperty property;

    property.toggle_state.value = value
        ? v3avs_types_V3ToggleState_Value_ON
        : v3avs_types_V3ToggleState_Value_OFF;

    return CommonEncodeContextProperty(
        V3AVS_Namespace_V3_ALEXA_TOGGLE_CONTROLLER,
        v3avs_capabilities_V3AlexaToggleController_PropertyName_TOGGLE_STATE_PROP,
        instance,
        pCommon,
        v3avs_capabilities_V3AlexaToggleController_ToggleStateProperty_fields,
        &property);
}

#endif // def ACK_TOGGLE_CONTROLLER
