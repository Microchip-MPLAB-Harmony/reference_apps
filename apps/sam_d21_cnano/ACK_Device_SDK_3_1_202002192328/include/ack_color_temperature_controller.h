/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_COLOR_TEMPERATURE_CONTROLLER_H__
#define __ACK_COLOR_TEMPERATURE_CONTROLLER_H__

#include "ack_user_config.h"
#include "details/ack_types.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef ACK_COLOR_TEMPERATURE_CONTROLLER

// You must implement these routines.
void ACKUser_OnColorTemperatureControllerIncreaseTemperatureDirective(int32_t correlationId);
void ACKUser_OnColorTemperatureControllerDecreaseTemperatureDirective(int32_t correlationId);

void ACKUser_OnColorTemperatureControllerSetTemperatureDirective(
    int32_t correlationId,
    uint32_t valueInKelvin);

// Call this to add a property representing the state of a color temperature controller to an outbound event.
ACKError_t ACK_AddColorTemperatureControllerProperty(
    const ACKStateCommon_t* pCommon,
    uint32_t valueInKelvin);

#endif // def ACK_COLOR_TEMPERATURE_CONTROLLER

#ifdef __cplusplus
}
#endif

#endif // def __ACK_COLOR_TEMPERATURE_CONTROLLER_H__
