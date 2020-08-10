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
#include "v3avs_capabilities/V3AlexaCookingFoodTemperatureController.pb.h"
#include "v3avs_capabilities/V3AVS.pb.h"

#ifdef ACK_COOKING_FOOD_TEMPERATURE_CONTROLLER

// Forward declarations.
static ACKError_t HandleCookByFoodTemperatureDirective_(
    v3avs_capabilities_V3AlexaCookingFoodTemperatureController_CookByFoodTemperature* pDirective);

// Calls user-supplied routine to process the directive.
ACKError_t HandleCookingFoodTemperatureControllerDirective(void)
{
    v3avs_capabilities_V3AlexaCookingFoodTemperatureController_Directive* pDirective;
    ACKError_t retval;
    bool protoResult;

    pDirective = (v3avs_capabilities_V3AlexaCookingFoodTemperatureController_Directive*)HeapletSetSize(
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
        v3avs_capabilities_V3AlexaCookingFoodTemperatureController_Directive_fields,
        pDirective);

    if (!protoResult)
    {
        ACK_DEBUG_PRINT_E("Unable to decode cooking food temperature controller directive payload.");
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    ACK_REENTRY_SHIELDS_UP;

    switch (pDirective->which_payload)
    {
    case v3avs_capabilities_V3AlexaCookingFoodTemperatureController_Directive_cook_by_food_temperature_tag:
        ACK_DEBUG_PRINT_I("Processing cooking food temp cook-by-food-temperature directive");
        retval = HandleCookByFoodTemperatureDirective_(&pDirective->payload.cook_by_food_temperature);
        break;

    default:
        ACK_DEBUG_PRINT_W(
            "Unhandled cooking food temperature controller directive payload %u",
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

static ACKError_t HandleCookByFoodTemperatureDirective_(
    v3avs_capabilities_V3AlexaCookingFoodTemperatureController_CookByFoodTemperature* pDirective)
{
    ACKError_t retval;
    ACKCookingDirectiveParams_t* pParams;

    retval = CookingDecodeCookByFoodTemperatureSubmessage(
        NULL, // Get from MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD
        0, // Get from MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD
        pDirective,
        v3avs_capabilities_V3AlexaCookingFoodTemperatureController_Directive_cook_by_food_temperature_tag,
        0); // ACKCookingDirectiveParams_t at start of MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA
    if (ACK_NO_ERROR != retval)
    {
        ACK_DEBUG_PRINT_E("Unable to decode cook-by-food-temperature directive submessage, err %u.", retval);
        goto cleanup0;
    }

    pParams = (ACKCookingDirectiveParams_t*)HeapletAccess(MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA);

    // Call the user-supplied handler.
    ACKUser_OnCookingFoodTemperatureControllerCookByFoodTemperatureDirective(
        ((V3AVS_AvsDirective*)HeapletAccess(MEM_RECEIVED_AVS_DIRECTIVE_ENVELOPE))->correlation_id,
        pParams);

    // Success.
    retval = ACK_NO_ERROR;

cleanup0:
    HeapletFree(MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA);
    return retval;
}

ACKError_t ACK_AddTargetFoodTemperatureProperty(
    const ACKStateCommon_t* pCommon,
    v3avs_types_V3Temperature_Scale scale,
    float temperature)
{
    v3avs_capabilities_V3AlexaCookingFoodTemperatureController_TargetFoodTemperatureProperty property;

    ACK_REENTRY_CHECK;

    property.target_food_temperature.scale = scale;
    property.target_food_temperature.value = temperature;

    return CommonEncodeContextProperty(
        V3AVS_Namespace_V3_ALEXA_FOOD_TEMPERATURE_COOKING_CONTROLLER,
        v3avs_capabilities_V3AlexaCookingFoodTemperatureController_PropertyName_TARGET_FOOD_TEMPERATURE_PROP,
        0, // instance not used for this controller
        pCommon,
        v3avs_capabilities_V3AlexaCookingFoodTemperatureController_TargetFoodTemperatureProperty_fields,
        &property);
}

#endif // def ACK_COOKING_FOOD_TEMPERATURE_CONTROLLER
