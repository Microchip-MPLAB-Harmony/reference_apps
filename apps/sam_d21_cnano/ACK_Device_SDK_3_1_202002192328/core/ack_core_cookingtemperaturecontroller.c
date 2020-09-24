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
#include "v3avs_capabilities/V3AlexaCookingTemperatureController.pb.h"
#include "v3avs_capabilities/V3AVS.pb.h"

#ifdef ACK_COOKING_TEMPERATURE_CONTROLLER

// Forward declarations.
static ACKError_t HandleCookByTemperatureDirective_(
    v3avs_capabilities_V3AlexaCookingTemperatureController_CookByTemperature* pDirective);

static ACKError_t HandleAdjustCookingTemperatureDirective_(
    v3avs_capabilities_V3AlexaCookingTemperatureController_AdjustCookingTemperature* pDirective);

// Calls user-supplied routine to process the directive.
ACKError_t HandleCookingTemperatureControllerDirective(void)
{
    v3avs_capabilities_V3AlexaCookingTemperatureController_Directive* pDirective;
    ACKError_t retval;
    bool protoResult;

    pDirective = (v3avs_capabilities_V3AlexaCookingTemperatureController_Directive*)HeapletSetSize(
        MEM_RECEIVED_DIRECTIVE_PAYLOAD,
        sizeof(v3avs_capabilities_V3AlexaCookingTemperatureController_Directive));
    if (NULL == pDirective)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    protoResult = ProtobufDecode(
        HeapletAccess(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        HeapletGetSize(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        v3avs_capabilities_V3AlexaCookingTemperatureController_Directive_fields,
        pDirective);

    if (!protoResult)
    {
        ACK_DEBUG_PRINT_E("Unable to decode cooking temperature controller directive payload.");
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    ACK_REENTRY_SHIELDS_UP;

    switch (pDirective->which_payload)
    {
    case v3avs_capabilities_V3AlexaCookingTemperatureController_Directive_cook_by_temperature_tag:
        ACK_DEBUG_PRINT_I("Processing cooking temperature cook-by-temperature directive");
        retval = HandleCookByTemperatureDirective_(&pDirective->payload.cook_by_temperature);
        break;

    case v3avs_capabilities_V3AlexaCookingTemperatureController_Directive_adjust_cooking_temperature_tag:
        ACK_DEBUG_PRINT_I("Processing cooking temperature adjust-cooking-temperature directive");
        retval = HandleAdjustCookingTemperatureDirective_(&pDirective->payload.adjust_cooking_temperature);
        break;

    default:
        ACK_DEBUG_PRINT_W(
            "Unhandled cooking temperature controller directive payload %u",
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

static ACKError_t HandleCookByTemperatureDirective_(
    v3avs_capabilities_V3AlexaCookingTemperatureController_CookByTemperature* pDirective)
{
    ACKError_t retval;
    ACKCookingDirectiveParams_t* pParams;

    retval = CookingDecodeDirectiveCommon(
        pDirective,
        &pDirective->cooking_mode,
        &pDirective->food_item,
        NULL,
        v3avs_capabilities_V3AlexaCookingTemperatureController_Directive_cook_by_temperature_tag,
        v3avs_capabilities_V3AlexaCookingTemperatureController_CookByTemperature_fields,
        NULL,   // No explicit encoded data, decode from MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD
        0,      // No explicit encoded data
        NULL);  // No pre-allocated ACKCookingDirectiveParams_t
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    pParams = (ACKCookingDirectiveParams_t*)HeapletAccess(MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA);

    pParams->Flags |= ACK_COOKING_DIRECTIVE_TEMPERATURE_VALID;
    pParams->Temperature = pDirective->target_cooking_temperature.value;
    pParams->TemperatureScale = pDirective->target_cooking_temperature.scale;

    // Call the user-supplied handler.
    ACKUser_OnCookingTemperatureControllerCookByTemperatureDirective(
        ((V3AVS_AvsDirective*)HeapletAccess(MEM_RECEIVED_AVS_DIRECTIVE_ENVELOPE))->correlation_id,
        pParams);

    // Success.
    retval = ACK_NO_ERROR;

cleanup0:
    HeapletFree(MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA);
    return retval;
}

static ACKError_t HandleAdjustCookingTemperatureDirective_(
    v3avs_capabilities_V3AlexaCookingTemperatureController_AdjustCookingTemperature* pDirective)
{
    bool protoResult;
    ACKError_t retval;

    protoResult = ProtobufDecodeSubmessage(
        HeapletAccess(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        HeapletGetSize(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        v3avs_capabilities_V3AlexaCookingTemperatureController_Directive_adjust_cooking_temperature_tag,
        v3avs_capabilities_V3AlexaCookingTemperatureController_AdjustCookingTemperature_fields,
        pDirective);
    if (!protoResult)
    {
        ACK_DEBUG_PRINT_E("Unable to decode cooking temperature controller adjust-temperature submessage.");
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    // Call the user-supplied handler.
    ACKUser_OnCookingTemperatureControllerAdjustCookingTemperatureDirective(
        ((V3AVS_AvsDirective*)HeapletAccess(MEM_RECEIVED_AVS_DIRECTIVE_ENVELOPE))->correlation_id,
        pDirective->target_cooking_temperature_delta.value,
        pDirective->target_cooking_temperature_delta.scale);

    // Success.
    retval = ACK_NO_ERROR;

cleanup0:
    return retval;
}

ACKError_t ACK_AddCookingTargetTemperatureProperty(
    const ACKStateCommon_t* pCommon,
    v3avs_types_V3Temperature_Scale scale,
    float temperature)
{
    v3avs_capabilities_V3AlexaCookingTemperatureController_TargetCookingTemperatureProperty property;

    property.target_cooking_temperature.value = temperature;
    property.target_cooking_temperature.scale = scale;

    ACK_REENTRY_CHECK;

    return CommonEncodeContextProperty(
        V3AVS_Namespace_V3_ALEXA_COOKING_TEMPERATURE_CONTROLLER,
        v3avs_capabilities_V3AlexaCookingTemperatureController_PropertyName_TARGET_COOKING_TEMPERATURE_PROP,
        0, // instance not used for this controller
        pCommon,
        v3avs_capabilities_V3AlexaCookingTemperatureController_TargetCookingTemperatureProperty_fields,
        &property);
}

// Call this to add a property representing the preheat time interval to an outbound event.
ACKError_t ACK_AddCookingPreheatTimeIntervalProperty(
    const ACKStateCommon_t* pCommon,
    uint64_t startTime, // epoch ms
    uint64_t endTime,
    uint64_t durationMilliseconds)
{
    v3avs_capabilities_V3AlexaCookingTemperatureController_PreheatTimeIntervalProperty property;

    property.preheat_time_interval.start.value = startTime;
    property.preheat_time_interval.end.value = endTime;
    property.preheat_time_interval.duration.value = durationMilliseconds;

    ACK_REENTRY_CHECK;

    return CommonEncodeContextProperty(
        V3AVS_Namespace_V3_ALEXA_COOKING_TEMPERATURE_CONTROLLER,
        v3avs_capabilities_V3AlexaCookingTemperatureController_PropertyName_PREHEAT_TIME_INTERVAL_PROP,
        0, // instance not used for this controller
        pCommon,
        v3avs_capabilities_V3AlexaCookingTemperatureController_PreheatTimeIntervalProperty_fields,
        &property);
}

#endif // ACK_COOKING_TEMPERATURE_CONTROLLER
