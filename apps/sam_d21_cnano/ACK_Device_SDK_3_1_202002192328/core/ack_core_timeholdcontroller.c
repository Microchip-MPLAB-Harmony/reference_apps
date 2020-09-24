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
#include "ack_core_event_builder.h"
#include "ack_core_heaplet.h"
#include "ack_core_protobuf_utilities.h"
#include "ack_time_hold_controller.h"
#include "ack_user_config.h"
#include "v3avs_capabilities/V3AlexaTimeHoldController.pb.h"
#include "v3avs_capabilities/V3AVS.pb.h"

#ifdef ACK_TIME_HOLD_CONTROLLER

// Forward declarations.
static void HandleHoldDirective_(v3avs_capabilities_V3AlexaTimeHoldController_Hold* pDirective);
static void HandleResumeDirective_(v3avs_capabilities_V3AlexaTimeHoldController_Resume* pDirective);

// Calls user-supplied routine to process the directive.
ACKError_t HandleTimeHoldControllerDirective(void)
{
    v3avs_capabilities_V3AlexaTimeHoldController_Directive* pDirective;
    ACKError_t retval;
    bool protoResult;

    pDirective = (v3avs_capabilities_V3AlexaTimeHoldController_Directive*)HeapletSetSize(
        MEM_RECEIVED_DIRECTIVE_PAYLOAD,
        sizeof(v3avs_capabilities_V3AlexaTimeHoldController_Directive));
    if (NULL == pDirective)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    protoResult = ProtobufDecode(
        HeapletAccess(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        HeapletGetSize(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        v3avs_capabilities_V3AlexaTimeHoldController_Directive_fields,
        pDirective);

    if (!protoResult)
    {
        ACK_DEBUG_PRINT_E("Unable to decode time hold controller directive payload.");
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    ACK_REENTRY_SHIELDS_UP;

    retval = ACK_NO_ERROR;

    switch (pDirective->directive_name)
    {
    case v3avs_capabilities_V3AlexaTimeHoldController_DirectiveName_HOLD:
        ACK_DEBUG_PRINT_I("Processing time hold controller hold directive");
        HandleHoldDirective_(&pDirective->payload.hold);
        break;

    case v3avs_capabilities_V3AlexaTimeHoldController_DirectiveName_RESUME:
        ACK_DEBUG_PRINT_I("Processing time hold controller resume directive");
        HandleResumeDirective_(&pDirective->payload.resume);
        break;

    default:
        ACK_DEBUG_PRINT_W(
            "Unhandled time hold controller directive %u",
            pDirective->directive_name);
        retval = ACK_ERR_PROTOCOL;
        break;
    }

    ACK_REENTRY_SHIELDS_DOWN;

    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    // NOTE! pDirective is now invalid, as processing above can be assumed to have resulted in
    // HeapletSetSize operations.

    retval = ACK_NO_ERROR;

cleanup0:
    HeapletFree(MEM_RECEIVED_DIRECTIVE_PAYLOAD);
    return retval;
}

static void HandleHoldDirective_(v3avs_capabilities_V3AlexaTimeHoldController_Hold* pDirective)
{
    ACKUser_OnTimeHoldControllerHoldDirective(
        ((V3AVS_AvsDirective*)HeapletAccess(MEM_RECEIVED_AVS_DIRECTIVE_ENVELOPE))->correlation_id);
}

static void HandleResumeDirective_(v3avs_capabilities_V3AlexaTimeHoldController_Resume* pDirective)
{
    ACKUser_OnTimeHoldControllerResumeDirective(
        ((V3AVS_AvsDirective*)HeapletAccess(MEM_RECEIVED_AVS_DIRECTIVE_ENVELOPE))->correlation_id);
}

#endif // def ACK_TIME_HOLD_CONTROLLER
