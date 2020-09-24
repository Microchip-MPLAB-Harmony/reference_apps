/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_COOKING_COMMON_H__
#define __ACK_COOKING_COMMON_H__

#include "ack.h"
#include "ack_user_config.h"
#include "ack_cooking.h"
#include <stddef.h>
#include "v3avs_capabilities/V3AlexaCooking.pb.h"
#include "v3avs_capabilities/V3AlexaCookingFoodTemperatureController.pb.h"
#include "v3avs_capabilities/V3AlexaCookingPresetController.pb.h"
#include "v3avs_capabilities/V3AlexaCookingTimeController.pb.h"

#ifdef __cplusplus
extern "C"
{
#endif

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
    size_t paramsOffsetInDecodedVariableLengthData);

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
    size_t paramsOffsetInDecodedVariableLengthData);

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
    ACKCookingDirectiveParams_t* pOptionalPreallocatedParams);

#endif

#ifdef __cplusplus
}
#endif

#endif // ndef __ACK_COOKING_COMMON_H__
