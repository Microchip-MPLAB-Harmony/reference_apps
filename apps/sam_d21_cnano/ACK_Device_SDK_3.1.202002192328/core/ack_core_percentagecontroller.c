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
#include "ack_percentage_controller.h"
#include "ack_core_protobuf_utilities.h"
#include "ack_user_config.h"
#include "v3avs_capabilities/V3Alexa.pb.h"
#include "v3avs_capabilities/V3AlexaPercentageController.pb.h"

#ifdef ACK_PERCENTAGE_CONTROLLER

// Calls user-supplied routine to process the directive.
ACKError_t HandlePercentageControllerDirective(void)
{
    V3AVS_AvsDirective* pOuterDirective;
    v3avs_capabilities_V3AlexaPercentageController_Directive* pDirective;
    ACKError_t retval;
    bool protoResult;
    bool isDelta;
    int32_t value;

    pDirective = (v3avs_capabilities_V3AlexaPercentageController_Directive*)HeapletSetSize(
        MEM_RECEIVED_DIRECTIVE_PAYLOAD,
        sizeof(v3avs_capabilities_V3AlexaPercentageController_Directive));
    if (NULL == pDirective)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    protoResult = ProtobufDecode(
        HeapletAccess(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        HeapletGetSize(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        v3avs_capabilities_V3AlexaPercentageController_Directive_fields,
        pDirective);

    if (!protoResult)
    {
        ACK_DEBUG_PRINT_E("Unable to decode percentage controller directive payload.");
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    pOuterDirective = (V3AVS_AvsDirective*)HeapletAccess(MEM_RECEIVED_AVS_DIRECTIVE_ENVELOPE);

    isDelta = pDirective->which_payload
        == v3avs_capabilities_V3AlexaPercentageController_Directive_adjust_percentage_tag;

    if (isDelta)
    {
        value = pDirective->payload.adjust_percentage.percentage_delta.value;
        ACK_DEBUG_PRINT_D("PercentageController directive; percentage delta %d", value);
    }
    else
    {
        value = pDirective->payload.set_percentage.percentage.value;
        ACK_DEBUG_PRINT_D("PercentageController directive; absolute percentage %u", value);
    }

    ACK_REENTRY_SHIELDS_UP;

    ACKUser_OnPercentageControllerDirective(pOuterDirective->correlation_id, isDelta, value);

    ACK_REENTRY_SHIELDS_DOWN;

    // NOTE! pDirective is now invalid, as processing above can be assumed to have resulted in
    // HeapletSetSize operations.

    retval = ACK_NO_ERROR;

cleanup0:
    HeapletFree(MEM_RECEIVED_DIRECTIVE_PAYLOAD);
    return retval;
}

ACKError_t ACK_AddPercentageControllerProperty(
    const ACKStateCommon_t* pCommon,
    int32_t percentage)
{
    ACK_REENTRY_CHECK;

    v3avs_capabilities_V3AlexaPercentageController_PercentageProperty property;
    property.percentage.value = percentage;

    return CommonEncodeContextProperty(
        V3AVS_Namespace_V3_ALEXA_PERCENTAGE_CONTROLLER,
        v3avs_capabilities_V3AlexaPercentageController_PropertyName_PERCENTAGE_PROP,
        0, // instance not used for this controller
        pCommon,
        v3avs_capabilities_V3AlexaPercentageController_PercentageProperty_fields,
        &property);
}

#endif // def ACK_PERCENTAGE_CONTROLLER
