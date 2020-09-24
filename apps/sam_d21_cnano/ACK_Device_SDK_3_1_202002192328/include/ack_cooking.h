/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_COOKING_H__
#define __ACK_COOKING_H__

#include "ack_user_config.h"
#include "details/ack_types.h"
#include <stdint.h>
#include "v3avs_capabilities/V3AlexaCooking.pb.h"
#include "v3avs_types/V3CookingMode.pb.h"
#include "v3avs_types/V3Duration.pb.h"
#include "v3avs_types/V3EnumeratedPowerLevel.pb.h"
#include "v3avs_types/V3FoodItem.pb.h"
#include "v3avs_types/V3IntegralPowerLevel.pb.h"
#include "v3avs_types/V3Temperature.pb.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef ACK_COOKING

// In some cooking-related directives, some fields are optional. These flags are used
// in the structs which are passed to user-supplied directive handler callbacks to indicate
// whether a given item was present in the directive, and thus whether related fields in
// the struct are valid.
#define ACK_COOKING_DIRECTIVE_COOKING_MODE_VALID 0x0001
#define ACK_COOKING_DIRECTIVE_TEMPERATURE_VALID 0x0002
#define ACK_COOKING_DIRECTIVE_POWER_LEVEL_VALID 0x0004
#define ACK_COOKING_DIRECTIVE_FOOD_QUANTITY_VALID 0x0008
#define ACK_COOKING_DIRECTIVE_DURATION_VALID 0x0010

typedef enum _ACKCookingPowerLevelKind_t
{
    ACK_COOKING_POWER_LEVEL_NONE,
    ACK_COOKING_POWER_LEVEL_INTEGRAL,
    ACK_COOKING_POWER_LEVEL_ENUMERATED
}
ACKCookingPowerLevelKind_t;

// Struct for ACKUser_OnCookingXxxDirective routines.
typedef struct _ACKCookingDirectiveParams_t
{
    // Contains ACK_COOKING_DIRECTIVE_xxx_VALID flags.
    unsigned Flags;

    // Valid if Flags contains ACK_COOKING_DIRECTIVE_MODE_VALID.
    // CustomModeName is non-NULL if CookingMode is CUSTOM.
    v3avs_types_V3CookingMode_Value CookingMode;
    const char* CustomModeName;

    // If non-NULL, the directive contained a food name.
    const char* FoodName;

    // Valid if Flags contains ACK_COOKING_DIRECTIVE_FOOD_QUANTITY_VALID.
    ACKItemQuantity_t FoodQuantity;

    // Valid if Flags contains ACK_COOKING_DIRECTIVE_TEMPERATURE_VALID.
    float Temperature;
    v3avs_types_V3Temperature_Scale TemperatureScale;

    // Valid if Flags contains ACK_COOKING_DIRECTIVE_POWER_LEVEL_VALID.
    ACKCookingPowerLevelKind_t PowerLevelKind;
    union
    {
        int32_t Integral;
        v3avs_types_V3EnumeratedPowerLevel_Value Enumerated;
    }
    PowerLevel;

    // Valid if Flags contains ACK_COOKING_DIRECTIVE_DURATION_VALID.
    // Value is in milliseconds.
    uint64_t Duration;

    // Non-NULL if the directive contained a preset name.
    const char* PresetName;
}
ACKCookingDirectiveParams_t;

// You must implement this routine.
void ACKUser_OnCookingSetModeDirective(
    int32_t correlationId,
    const ACKCookingDirectiveParams_t* pParams);

// Call this to add a property representing the cooking mode to a cooking-related outbound event.
ACKError_t ACK_AddCookingModeProperty(
    const ACKStateCommon_t* pCommon,
    v3avs_types_V3CookingMode_Value mode,
    const char* pCustomModeName);

// Call this to add a property representing the cooking time interval to an outbound event.
ACKError_t ACK_AddCookingTimeIntervalProperty(
    const ACKStateCommon_t* pCommon,
    uint64_t startTime, // epoch ms
    uint64_t endTime,
    uint64_t durationMilliseconds);

// Call this to add property representing the food item to an outbound event.
ACKError_t ACK_AddFoodItemProperty(
    const ACKStateCommon_t* pCommon,
    const char* pFoodName,
    const ACKItemQuantity_t* pFoodQuantity);

// Tells Alexa that you could not complete processing a cooking directive due to a cooking-related error.
// If there is a more specific routine for the error you want to send (see below) you must use that routine
// instead of this one.
ACKError_t ACK_CompleteDirectiveWithCookingError(
    int32_t correlationId,
    v3avs_capabilities_V3AlexaCooking_ErrorResponse_ErrorType type,
    const char* pOptionalMessage);

// Tells Alexa that you could not complete processing a cooking directive because a cook duration received
// in the directive is too long.
ACKError_t ACK_CompleteDirectiveWithCookingDurationTooLongError(
    int32_t correlationId,
    uint64_t maxCookDurationMilliseconds,
    const char* pOptionalMessage);

// Cooking food temperature controller.
#ifdef ACK_COOKING_FOOD_TEMPERATURE_CONTROLLER

// You must implement this routine.
void ACKUser_OnCookingFoodTemperatureControllerCookByFoodTemperatureDirective(
    int32_t correlationId,
    const ACKCookingDirectiveParams_t* pParams);

// Call this to add a property representing the food temperature to an outbound event.
ACKError_t ACK_AddTargetFoodTemperatureProperty(
    const ACKStateCommon_t* pCommon,
    v3avs_types_V3Temperature_Scale scale,
    float temperature);

#endif // def ACK_COOKING_FOOD_TEMPERATURE_CONTROLLER

// Cooking food temperature sensor.
#ifdef ACK_COOKING_FOOD_TEMPERATURE_SENSOR

// Call this to add a property representing the food temperature to an outbound event.
ACKError_t ACK_AddFoodTemperatureProperty(
    const ACKStateCommon_t* pCommon,
    v3avs_types_V3Temperature_Scale scale,
    float temperature);

#endif // def ACK_COOKING_FOOD_TEMPERATURE_SENSOR

// Cooking preset controller.
#ifdef ACK_COOKING_PRESET_CONTROLLER

// You must implement this routine.
void ACKUser_OnCookingPresetControllerCookByPresetDirective(
    int32_t correlationId,
    const ACKCookingDirectiveParams_t* pParams);

// Call this to add a property representing preset name to an outbound event.
ACKError_t ACK_AddCookingPresetControllerPresetNameProperty(
    const ACKStateCommon_t* pCommon,
    const char* pPresetName);

#endif // def ACK_COOKING_PRESET_CONTROLLER

// Cooking temperature controller.
#ifdef ACK_COOKING_TEMPERATURE_CONTROLLER

void ACKUser_OnCookingTemperatureControllerCookByTemperatureDirective(
    int32_t correlationId,
    const ACKCookingDirectiveParams_t* pParams);

void ACKUser_OnCookingTemperatureControllerAdjustCookingTemperatureDirective(
    int32_t correlationId,
    float TargetFoodTemperatureDelta,
    v3avs_types_V3Temperature_Scale TemperatureScale);

// Call this to add a property representing the target cooking temperature to an outbound event.
ACKError_t ACK_AddCookingTargetTemperatureProperty(
    const ACKStateCommon_t* pCommon,
    v3avs_types_V3Temperature_Scale scale,
    float temperature);

// Call this to add a property representing the preheat time interval to an outbound event.
ACKError_t ACK_AddCookingPreheatTimeIntervalProperty(
    const ACKStateCommon_t* pCommon,
    uint64_t startTime, // epoch ms
    uint64_t endTime,
    uint64_t durationMilliseconds);

#endif // def ACK_COOKING_TEMPERATURE_CONTROLLER

// Cooking temperature sensor.
#ifdef ACK_COOKING_TEMPERATURE_SENSOR

// Call this to add a property representing the temperature to an outbound event.
ACKError_t ACK_AddCookingTemperatureProperty(
    const ACKStateCommon_t* pCommon,
    v3avs_types_V3Temperature_Scale scale,
    float temperature);

#endif // def ACK_COOKING_TEMPERATURE_SENSOR

// Cooking time controller.
#ifdef ACK_COOKING_TIME_CONTROLLER

// You must implement this routine.
void ACKUser_OnCookingTimeControllerCookByTimeDirective(
    int32_t correlationId,
    const ACKCookingDirectiveParams_t* pParams);

// You must implement this routine.
void ACKUser_OnCookingTimeControllerAdjustCookTimeDirective(
    int32_t correlationId,
    int64_t timeDeltaMilliseconds);

// Call this to add a property representing requested cook time to an outbound event.
ACKError_t ACK_AddCookingTimeControllerRequestedCookTimeProperty(
    const ACKStateCommon_t* pCommon,
    uint64_t durationMilliseconds);

// Call this to add a property representing cooking power level to an outbound event.
ACKError_t ACK_AddCookingTimeControllerCookingPowerLevelProperty(
    const ACKStateCommon_t* pCommon,
    ACKCookingPowerLevelKind_t powerLevelKind,
    int32_t integralPowerLevel,
    v3avs_types_V3EnumeratedPowerLevel_Value enumeratedPowerLevel);

#endif // def ACK_COOKING_TIME_CONTROLLER

#endif // def ACK_COOKING

#ifdef __cplusplus
}
#endif

#endif // def __ACK_COOKING_H__
