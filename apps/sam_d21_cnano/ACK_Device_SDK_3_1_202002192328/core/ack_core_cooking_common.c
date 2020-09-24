/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#include "ack_core_common.h"
#include "ack_core_cooking_common.h"
#include "ack_core_heaplet.h"
#include "ack_core_math.h"
#include "ack_core_protobuf_utilities.h"
#include "ack_cooking.h"
#include <float.h>

#if defined(ACK_COOKING_FOOD_TEMPERATURE_CONTROLLER)

// Decodes a cook-by-food-temperature cooking directive and populates an instance of the
// ACKCookingDirectiveParams_t struct. That instance is expected to be in
// MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA at a given offset. That block is enlarged to contain any strings
// resulting from decoding, which are appended to the end of the block.
ACKError_t CookingDecodeCookByFoodTemperatureSubmessage(
    const void* pOptionalEncodedData,
    size_t optionalEncodedSize,
    v3avs_capabilities_V3AlexaCookingFoodTemperatureController_CookByFoodTemperature* pDirective,
    unsigned submessageTag,
    size_t paramsOffsetInDecodedVariableLengthData)
{
    ACKError_t retval;
    ACKCookingDirectiveParams_t* pParams;

    memset(pDirective, 0, sizeof(*pDirective));

    // There are three cases for where to find the ACKCookingDirectiveParams_t to populate:
    // 1. ACKCookingDirectiveParams_t not pre-allocated, paramsOffsetInDecodedVariableLengthData 0
    // 2. Pre-allocated ACKCookingDirectiveParams_t, paramsOffsetInDecodedVariableLengthData non-0
    // 3. Pre-allocated ACKCookingDirectiveParams_t, paramsOffsetInDecodedVariableLengthData 0
    // (The fourth case, with no pre-allocation and non-0 offset, should never occur.)
    //
    // In case 1, we expect MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA to not be allocated at all,
    // and paramsOffsetInDecodedVariableLengthData is 0. Thus pBlock + paramsOffsetInDecodedVariableLengthData
    // is NULL, which is what we want to pass as the preallocated params struct, to
    // CookingDecodeDirectiveCommon.
    //
    // In cases 2 and 3, MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA is allocated (we expect the pre-allocated
    // ACKCookingDirectiveParams_t to be in that block). The base of that block plus
    // paramsOffsetInDecodedVariableLengthData is what we want to pass as the preallocated params struct,
    // to CookingDecodeDirectiveCommon.
    ACK_ASSERT(HeapletAccess(MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA)
        || (0 == paramsOffsetInDecodedVariableLengthData));

    pParams = (ACKCookingDirectiveParams_t*)((char*)HeapletAccess(MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA)
        + paramsOffsetInDecodedVariableLengthData);

    retval = CookingDecodeDirectiveCommon(
        pDirective,
        &pDirective->cooking_mode,
        &pDirective->food_item,
        NULL, // no preset name
        submessageTag,
        v3avs_capabilities_V3AlexaCookingFoodTemperatureController_CookByFoodTemperature_fields,
        pOptionalEncodedData,
        optionalEncodedSize,
        pParams);
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    // Access the params we're filling out so we can deal with fields that aren't part of the
    // common decoder we invoked above.
    pParams = (ACKCookingDirectiveParams_t*)((char*)HeapletAccess(MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA)
        + paramsOffsetInDecodedVariableLengthData);

    // Temperature (always valid).
    pParams->Flags |= ACK_COOKING_DIRECTIVE_TEMPERATURE_VALID;
    pParams->Temperature = pDirective->target_food_temperature.value;
    pParams->TemperatureScale = pDirective->target_food_temperature.scale;

    // Success.
    retval = ACK_NO_ERROR;

cleanup0:
    return retval;
}

#endif // defined(ACK_COOKING_FOOD_TEMPERATURE_CONTROLLER)

#if defined(ACK_COOKING_TIME_CONTROLLER)

// Decodes a cook-by-time cooking directive and populates an instance of the
// ACKCookingDirectiveParams_t struct. That instance is expected to be
// in MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA at a given offset. That block is enlarged to contain
// any strings resulting from decoding, which are appended to the end of the block.
ACKError_t CookingDecodeCookByTimeSubmessage(
    const void* pOptionalEncodedData,
    size_t optionalEncodedSize,
    v3avs_capabilities_V3AlexaCookingTimeController_CookByTime* pDirective,
    unsigned submessageTag,
    size_t paramsOffsetInDecodedVariableLengthData)
{
    ACKError_t retval;
    ACKCookingDirectiveParams_t* pParams;

    memset(pDirective, 0, sizeof(*pDirective));

    // Put sentinel values in the temperature fields so we can determine whether they were present in
    // the message.
#define _COOK_TEMP_SCALE_SENTINEL ((v3avs_types_V3Temperature_Scale)(-1))
#define _COOK_TEMP_VALUE_SENTINEL (FLT_MIN)
    pDirective->target_cooking_temperature.scale = _COOK_TEMP_SCALE_SENTINEL;
    pDirective->target_cooking_temperature.value = _COOK_TEMP_VALUE_SENTINEL;

    // There are three cases for where to find the ACKCookingDirectiveParams_t to populate:
    // 1. ACKCookingDirectiveParams_t not pre-allocated, paramsOffsetInDecodedVariableLengthData 0
    // 2. Pre-allocated ACKCookingDirectiveParams_t, paramsOffsetInDecodedVariableLengthData non-0
    // 3. Pre-allocated ACKCookingDirectiveParams_t, paramsOffsetInDecodedVariableLengthData 0
    // (The fourth case, with no pre-allocation and non-0 offset, should never occur.)
    //
    // In case 1, we expect MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA to not be allocated at all,
    // and paramsOffsetInDecodedVariableLengthData is 0. Thus pBlock + paramsOffsetInDecodedVariableLengthData
    // is NULL, which is what we want to pass as the preallocated params struct, to
    // CookingDecodeDirectiveCommon.
    //
    // In cases 2 and 3, MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA is allocated (we expect the pre-allocated
    // ACKCookingDirectiveParams_t to be in that block). The base of that block plus
    // paramsOffsetInDecodedVariableLengthData is what we want to pass as the preallocated params struct,
    // to CookingDecodeDirectiveCommon.
    ACK_ASSERT(HeapletAccess(MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA)
        || (0 == paramsOffsetInDecodedVariableLengthData));

    pParams = (ACKCookingDirectiveParams_t*)((char*)HeapletAccess(MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA)
        + paramsOffsetInDecodedVariableLengthData);

    retval = CookingDecodeDirectiveCommon(
        pDirective,
        &pDirective->cooking_mode,
        &pDirective->food_item,
        NULL, // no preset name
        submessageTag,
        v3avs_capabilities_V3AlexaCookingTimeController_CookByTime_fields,
        pOptionalEncodedData,
        optionalEncodedSize,
        pParams);
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    // Access the params we're filling out so we can deal with fields that aren't part of the
    // common decoder we invoked above.
    pParams = (ACKCookingDirectiveParams_t*)((char*)HeapletAccess(MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA)
        + paramsOffsetInDecodedVariableLengthData);

    // Power level (optional).
    switch (pDirective->cooking_power_level.which_payload)
    {
    case v3avs_capabilities_V3AlexaCookingTimeController_CookingPowerLevel_enumerated_power_level_tag:
        pParams->PowerLevelKind = ACK_COOKING_POWER_LEVEL_ENUMERATED;
        pParams->PowerLevel.Enumerated
            = pDirective->cooking_power_level.payload.enumerated_power_level.value;
        pParams->Flags |= ACK_COOKING_DIRECTIVE_POWER_LEVEL_VALID;
        ACK_DEBUG_PRINT_I("Enumerated power level present in cook-by-time directive.");
        break;
    case v3avs_capabilities_V3AlexaCookingTimeController_CookingPowerLevel_integral_power_level_tag:
        pParams->PowerLevelKind = ACK_COOKING_POWER_LEVEL_INTEGRAL;
        pParams->PowerLevel.Integral = pDirective->cooking_power_level.payload.integral_power_level.value;
        pParams->Flags |= ACK_COOKING_DIRECTIVE_POWER_LEVEL_VALID;
        ACK_DEBUG_PRINT_I("Integral power level present in cook-by-time directive.");
        break;
    default:
        ACK_DEBUG_PRINT_I(
            "Cooking power level payload %u indicates no power level in cook-by-time directive.",
            pDirective->cooking_power_level.which_payload);
        break;
    }

    // Temperature (optional).
    if ((_COOK_TEMP_SCALE_SENTINEL != pDirective->target_cooking_temperature.scale)
        || (_COOK_TEMP_VALUE_SENTINEL != pDirective->target_cooking_temperature.value))
    {
        pParams->Flags |= ACK_COOKING_DIRECTIVE_TEMPERATURE_VALID;
        pParams->TemperatureScale = pDirective->target_cooking_temperature.scale;
        pParams->Temperature = pDirective->target_cooking_temperature.value;
    }

    // Duration (always valid).
    pParams->Flags |= ACK_COOKING_DIRECTIVE_DURATION_VALID;
    pParams->Duration = pDirective->cook_time.value;

    // Success.
    retval = ACK_NO_ERROR;

cleanup0:
    return retval;
}

#endif // defined(ACK_COOKING_TIME_CONTROLLER)

#if defined(ACK_COOKING) \
    || defined(ACK_COOKING_FOOD_TEMPERATURE_CONTROLLER) \
    || defined(ACK_COOKING_PRESET_CONTROLLER) \
    || defined(ACK_COOKING_TEMPERATURE_CONTROLLER) \
    || defined(ACK_COOKING_TIME_CONTROLLER)

ACKError_t CookingDecodeDirectiveCommon(
    void* pDirective,
    v3avs_types_V3CookingMode* pDirectiveCookingMode,
    v3avs_types_V3FoodItem* pDirectiveFoodItem,
#ifdef ACK_COOKING_PRESET_CONTROLLER    
    v3avs_types_V3PresetName* pDirectivePresetName,
#else
    const void* pUnused,
#endif    
    unsigned submessageTag,
    const pb_field_t* pSubmessageFields,
    const void* pOptionalEncodedData,
    size_t optionalEncodedSize,
    ACKCookingDirectiveParams_t* pOptionalPreallocatedParams)
{
    ProtobufCallbackField_t customNameField = {0};
    ProtobufCallbackField_t foodNameField = {0};
    ProtobufCallbackField_t presetNameField = {0};
    bool protoResult;
    ACKError_t retval;
    ACKCookingDirectiveParams_t* pParams;
    char* pString;
    size_t offsetToStringData;
    size_t blockSize;

    if (pDirectiveCookingMode)
    {
        pDirectiveCookingMode->custom_name.funcs.decode = ProtobufDecodeCallbackField;
        pDirectiveCookingMode->custom_name.arg = &customNameField;
    }

    if (pDirectiveFoodItem)
    {
        pDirectiveFoodItem->food_name.funcs.decode = ProtobufDecodeCallbackField;
        pDirectiveFoodItem->food_name.arg = &foodNameField;
    }

#ifdef ACK_COOKING_PRESET_CONTROLLER

    if (pDirectivePresetName)
    {
        pDirectivePresetName->value.funcs.decode = ProtobufDecodeCallbackField;
        pDirectivePresetName->value.arg = &presetNameField;
    }

#endif

    // If we were given encoded data, decode from there. Otherwise, decode from
    // MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD.
    protoResult = ProtobufDecodeSubmessage(
        pOptionalEncodedData ? pOptionalEncodedData : HeapletAccess(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        pOptionalEncodedData ? optionalEncodedSize : HeapletGetSize(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        submessageTag,
        pSubmessageFields,
        pDirective);
    if (!protoResult)
    {
        ACK_DEBUG_PRINT_E("Unable to decode cooking directive submessage tag %u.", submessageTag);
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    // If the ACKCookingDirectiveParams_t was preallocated, assume MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA
    // already contains data we don't want to clobber. In this case, strings go at the end of the newly-
    // enlarged block.
    // If the ACKCookingDirectiveParams_t was not preallocated, then create a new block consisting of
    // an ACKCookingDirectiveParams_t, followed by strings.
    offsetToStringData = pOptionalPreallocatedParams
        ? HeapletGetSize(MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA)
        : sizeof(ACKCookingDirectiveParams_t);

    // We're going to allocate a heaplet block based on user-supplied size info that arrived in a
    // protobuf message, which we must consider untrusted. Ensure we don't overflow, thus causing
    // a buffer overrun condition.
    if (!MathSafeAddSizeT(
        &blockSize,
        4,
        offsetToStringData,
        customNameField.Value ? (customNameField.Length + 1) : 0,
        foodNameField.Value ? (foodNameField.Length + 1) : 0,
        presetNameField.Value ? (presetNameField.Length + 1) : 0))
    {
        ACK_DEBUG_PRINT_C("Cooking directive strings overflow a size_t.")
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    pParams = (ACKCookingDirectiveParams_t*)HeapletSetSize(
        MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA,
        blockSize);
    if (NULL == pParams)
    {
        ACK_DEBUG_PRINT_E("Unable to allocate memory for cooking directive strings.");
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    // Strings will go after the other data in the block created/enlarged above.
    pString = (char*)pParams + offsetToStringData;

    // If we were given a preallocated ACKCookingDirectiveParams_t, use it.
    if (pOptionalPreallocatedParams)
    {
        pParams = pOptionalPreallocatedParams;
    }

    memset(pParams, 0, sizeof(*pParams));

    if (pDirectiveCookingMode)
    {
        // Cooking mode.
        // A value of 'timecook' means there's no mode.
        if ((pParams->CookingMode = pDirectiveCookingMode->value) != v3avs_types_V3CookingMode_Value_TIMECOOK)
        {
            ACK_DEBUG_PRINT_I("Cooking mode present in cooking directive.");

            pParams->Flags |= ACK_COOKING_DIRECTIVE_COOKING_MODE_VALID;
        }
        else
        {
            ACK_DEBUG_PRINT_I("Cooking mode not present in cooking directive (set to TIMECOOK).");
        }

        if (NULL != customNameField.Value)
        {
            memcpy(pString, customNameField.Value, customNameField.Length);
            pString[customNameField.Length] = 0;
            pParams->CustomModeName = pString;
            pString += customNameField.Length + 1;
        }
    }

    if (pDirectiveFoodItem)
    {
        // Food item.
        if (CommonConvertItemQuantityFromProtobuf(&pDirectiveFoodItem->food_quantity, &pParams->FoodQuantity))
        {
            ACK_DEBUG_PRINT_I("Food quantity present in cooking directive");

            pParams->Flags |= ACK_COOKING_DIRECTIVE_FOOD_QUANTITY_VALID;
        }
        else
        {
            ACK_DEBUG_PRINT_I("Food quantity not present or invalid in set-cooking-mode directive");
        }

        if (NULL != foodNameField.Value)
        {
            memcpy(pString, foodNameField.Value, foodNameField.Length);
            pString[foodNameField.Length] = 0;
            pParams->FoodName = pString;
            pString += foodNameField.Length + 1;
        }
    }

#ifdef ACK_COOKING_PRESET_CONTROLLER

    if (pDirectivePresetName)
    {
        // Preset name.
        if (NULL != presetNameField.Value)
        {
            memcpy(pString, presetNameField.Value, presetNameField.Length);
            pString[presetNameField.Length] = 0;
            pParams->PresetName = pString;
            // pString += presetNameField.Length + 1; // Not needed, we're done packing strings.
        }
    }

#endif

    // Done.
    retval = ACK_NO_ERROR;

cleanup0:
    return retval;
}

#endif
