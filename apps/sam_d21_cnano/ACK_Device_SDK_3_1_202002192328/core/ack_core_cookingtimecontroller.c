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
#include "ack_core_cooking_common.h"
#include "ack_core_directives.h"
#include "ack_core_event_builder.h"
#include "ack_core_heaplet.h"
#include "ack_core_protobuf_utilities.h"
#include "ack_user_config.h"
#include "ack_cooking.h"
#include "v3avs_capabilities/V3AlexaCookingTimeController.pb.h"
#include "v3avs_capabilities/V3AVS.pb.h"

#ifdef ACK_COOKING_TIME_CONTROLLER

// Forward declarations.
static ACKError_t HandleCookByTimeDirective_(
    v3avs_capabilities_V3AlexaCookingTimeController_CookByTime* pDirective);

static ACKError_t HandleAdjustCookTimeDirective_(
    v3avs_capabilities_V3AlexaCookingTimeController_AdjustCookTime* pDirective);

// Calls user-supplied routine to process the directive.
ACKError_t HandleCookingTimeControllerDirective(void)
{
    v3avs_capabilities_V3AlexaCookingTimeController_Directive* pDirective;
    ACKError_t retval;
    bool protoResult;

    pDirective = (v3avs_capabilities_V3AlexaCookingTimeController_Directive*)HeapletSetSize(
        MEM_RECEIVED_DIRECTIVE_PAYLOAD,
        sizeof(*pDirective));
    if (NULL == pDirective)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    protoResult = ProtobufDecode(
        HeapletAccess(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        HeapletGetSize(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        v3avs_capabilities_V3AlexaCookingTimeController_Directive_fields,
        pDirective);

    if (!protoResult)
    {
        ACK_DEBUG_PRINT_E("Unable to decode cooking time controller directive payload.");
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    ACK_REENTRY_SHIELDS_UP;

    switch (pDirective->which_payload)
    {
    case v3avs_capabilities_V3AlexaCookingTimeController_Directive_cook_by_time_tag:
        ACK_DEBUG_PRINT_I("Processing cooking time cook-by-time directive");
        retval = HandleCookByTimeDirective_(&pDirective->payload.cook_by_time);
        break;

    case v3avs_capabilities_V3AlexaCookingTimeController_Directive_adjust_cook_time_tag:
        ACK_DEBUG_PRINT_I("Processing cooking time adjust-cook-time directive");
        retval = HandleAdjustCookTimeDirective_(&pDirective->payload.adjust_cook_time);
        break;

    default:
        ACK_DEBUG_PRINT_W(
            "Unhandled cooking time controller directive payload %u",
            pDirective->which_payload);
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

static ACKError_t HandleCookByTimeDirective_(
    v3avs_capabilities_V3AlexaCookingTimeController_CookByTime* pDirective)
{
    ACKError_t retval;
    ACKCookingDirectiveParams_t* pParams;

    retval = CookingDecodeCookByTimeSubmessage(
        NULL, // Get from MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD
        0, // Get from MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD
        pDirective,
        v3avs_capabilities_V3AlexaCookingTimeController_Directive_cook_by_time_tag,
        0); // ACKCookingDirectiveParams_t at start of MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA
    if (ACK_NO_ERROR != retval)
    {
        ACK_DEBUG_PRINT_E("Unable to decode cook-by-time directive submessage, err %u.", retval);
        goto cleanup0;
    }

    pParams = (ACKCookingDirectiveParams_t*)HeapletAccess(MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA);

    // Call the user-supplied handler.
    ACKUser_OnCookingTimeControllerCookByTimeDirective(
        ((V3AVS_AvsDirective*)HeapletAccess(MEM_RECEIVED_AVS_DIRECTIVE_ENVELOPE))->correlation_id,
        pParams);

    // Success.
    retval = ACK_NO_ERROR;

cleanup0:
    HeapletFree(MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA);
    return retval;
}

static ACKError_t HandleAdjustCookTimeDirective_(
    v3avs_capabilities_V3AlexaCookingTimeController_AdjustCookTime* pDirective)
{
    ACKUser_OnCookingTimeControllerAdjustCookTimeDirective(
        ((V3AVS_AvsDirective*)HeapletAccess(MEM_RECEIVED_AVS_DIRECTIVE_ENVELOPE))->correlation_id,
        (int64_t)pDirective->cook_time_delta.value);

    return ACK_NO_ERROR;
}

ACKError_t ACK_AddCookingTimeControllerRequestedCookTimeProperty(
    const ACKStateCommon_t* pCommon,
    uint64_t durationMilliseconds)
{
    v3avs_capabilities_V3AlexaCookingTimeController_RequestedCookTimeProperty property;

    ACK_REENTRY_CHECK;

    property.requested_cook_time.value = durationMilliseconds;

    return CommonEncodeContextProperty(
        V3AVS_Namespace_V3_ALEXA_COOKING_TIME_CONTROLLER,
        v3avs_capabilities_V3AlexaCookingTimeController_PropertyName_REQUESTED_COOK_TIME_PROP,
        0, // instance not used for this controller
        pCommon,
        v3avs_capabilities_V3AlexaCookingTimeController_RequestedCookTimeProperty_fields,
        &property);
}

ACKError_t ACK_AddCookingTimeControllerCookingPowerLevelProperty(
    const ACKStateCommon_t* pCommon,
    ACKCookingPowerLevelKind_t powerLevelKind,
    int32_t integralPowerLevel,
    v3avs_types_V3EnumeratedPowerLevel_Value enumeratedPowerLevel)
{
    v3avs_capabilities_V3AlexaCookingTimeController_CookingPowerLevelProperty property;

    ACK_REENTRY_CHECK;

    switch (powerLevelKind)
    {
    case ACK_COOKING_POWER_LEVEL_ENUMERATED:
        property.power_level.payload.enumerated_power_level.value = enumeratedPowerLevel;

        property.power_level.cooking_power_level_type
            = v3avs_capabilities_V3AlexaCookingTimeController_CookingPowerLevelType_ENUMERATED_POWER_LEVEL;
        property.power_level.which_payload
            = v3avs_capabilities_V3AlexaCookingTimeController_CookingPowerLevel_enumerated_power_level_tag;

        break;

    case ACK_COOKING_POWER_LEVEL_INTEGRAL:
        property.power_level.payload.integral_power_level.value = integralPowerLevel;

        property.power_level.cooking_power_level_type
            = v3avs_capabilities_V3AlexaCookingTimeController_CookingPowerLevelType_INTEGRAL_POWER_LEVEL;
        property.power_level.which_payload
            = v3avs_capabilities_V3AlexaCookingTimeController_CookingPowerLevel_integral_power_level_tag;

        break;

    default:
        property.power_level.which_payload = 0;
        break;
    }

    return CommonEncodeContextProperty(
        V3AVS_Namespace_V3_ALEXA_COOKING_TIME_CONTROLLER,
        v3avs_capabilities_V3AlexaCookingTimeController_PropertyName_COOKING_POWER_LEVEL_PROP,
        0, // instance not used for this controller
        pCommon,
        v3avs_capabilities_V3AlexaCookingTimeController_CookingPowerLevelProperty_fields,
        &property);
}

#endif // def ACK_COOKING_TIME_CONTROLLER
