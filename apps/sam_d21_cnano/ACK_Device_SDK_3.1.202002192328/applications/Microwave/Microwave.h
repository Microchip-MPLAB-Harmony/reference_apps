/*
 * Copyright 2018-2020 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

/*
    Note: this application is a sample only. It may omit functionality that would be required in a
    real device. The application’s source code is structured to maximize illustrative utility, and not
    to suggest a reference design for any category of device or to provide a definitive framework for
    a device’s firmware.
*/

#ifndef __MICROWAVE_H__
#define __MICROWAVE_H__

#include "Hardware.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

// Based on a 6-digit clock display,
//  Maximum cook duration is 99 hours, 99 minutes, 99 seconds.
//  Max ounces for weight-based cooking is 999999.
#define MAX_COOK_DURATION_SECONDS ((99 * (60 * 60)) + (99 * 60) + 99)
#define MAX_WEIGHT_OUNCES 999999

// Error conditions from a device operation.
typedef enum _MicrowaveError
{
    MICROWAVE_NO_ERROR,
    MICROWAVE_ERROR_DOOR_OPEN,
    MICROWAVE_ERROR_CHILD_LOCK_ENGAGED,
    MICROWAVE_ERROR_DOOR_CLOSED_TOO_LONG,
    MICROWAVE_ERROR_NOT_COOKING,
    MICROWAVE_ERROR_ALREADY_COOKING,
    MICROWAVE_ERROR_NOT_SUPPORTED_IN_CURRENT_MODE,
    MICROWAVE_ERROR_COOK_TIME_TOO_LONG
}
MicrowaveError;

typedef enum _MicrowaveCookingMode
{
    MICROWAVE_COOKING_NONE,
    MICROWAVE_COOKING_MODE_TIME_COOK,
    MICROWAVE_COOKING_MODE_DEFROST_BY_WEIGHT
}
MicrowaveCookingMode;

typedef enum _MicrowaveConnectivityState
{
    MICROWAVE_CONNECTIVITY_OTHER,
    MICROWAVE_CONNECTIVITY_NOT_CONNECTED,
    MICROWAVE_CONNECTIVITY_CONNECTED,
    MICROWAVE_CONNECTIVITY_FACTORY_RESET,
    MICROWAVE_CONNECTIVITY_ACK_SETUP
}
MicrowaveConnectivityState;

bool Microwave_IsDeviceInUse(void);

void Microwave_FactoryReset(void);

bool Microwave_DidUserInitiateFactoryReset(void);
bool Microwave_DidUserInitiateAckSetup(void);
bool Microwave_DidUserInitiateAckSubmitLogs(void);

void Microwave_UpdateConnectivityState(MicrowaveConnectivityState connectivityState);

MicrowaveError Microwave_StartCookingByTime(uint32_t timeSeconds, HardwarePowerLevel powerLevel);
MicrowaveError Microwave_StartDefrostingByWeight(uint32_t ouncesTimesTen);
MicrowaveError Microwave_StopCooking(void);
MicrowaveError Microwave_PauseCooking(void);
MicrowaveError Microwave_ResumeCooking(void);

MicrowaveCookingMode Microwave_GetCookingMode(void);

// These return false if not cooking or paused.
bool Microwave_GetCookTimeInfo(uint32_t* pRemainingTimeSeconds, uint32_t* pRequestedDurationSeconds);
bool Microwave_GetCookingPowerLevelInfo(HardwarePowerLevel *pPowerLevel);
bool Microwave_GetCookingWeightInfo(uint32_t* pOuncesTimesTen);

MicrowaveError Microwave_AdjustCookTime(int32_t timeDeltaSeconds);

#ifdef __cplusplus
}
#endif

#endif // ndef __MICROWAVE_H__
