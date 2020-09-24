/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_DIRECTIVES_H__
#define __ACK_DIRECTIVES_H__

#include "ack.h"
#include "ack_user_config.h"

#ifdef __cplusplus
extern "C"
{
#endif

ACKError_t HandleAlexaInterfaceDirective(void);

#ifdef ACK_BRIGHTNESS_CONTROLLER
ACKError_t HandleBrightnessControllerDirective(void);
#endif

#ifdef ACK_COLOR_CONTROLLER
ACKError_t HandleColorControllerDirective(void);
#endif

#ifdef ACK_COLOR_TEMPERATURE_CONTROLLER
ACKError_t HandleColorTemperatureControllerDirective(void);
#endif

#ifdef ACK_COOKING
ACKError_t HandleCookingControllerDirective(void);
#endif

#ifdef ACK_COOKING_FOOD_TEMPERATURE_CONTROLLER
ACKError_t HandleCookingFoodTemperatureControllerDirective(void);
#endif

#ifdef ACK_COOKING_PRESET_CONTROLLER
ACKError_t HandleCookingPresetControllerDirective(void);
#endif

#ifdef ACK_COOKING_TEMPERATURE_CONTROLLER
ACKError_t HandleCookingTemperatureControllerDirective(void);
#endif

#ifdef ACK_COOKING_TIME_CONTROLLER
ACKError_t HandleCookingTimeControllerDirective(void);
#endif

#ifdef ACK_MODE_CONTROLLER
ACKError_t HandleModeControllerDirective(void);
#endif

#ifdef ACK_POWER_CONTROLLER
ACKError_t HandlePowerControllerDirective(void);
#endif

#ifdef ACK_PERCENTAGE_CONTROLLER
ACKError_t HandlePercentageControllerDirective(void);
#endif

#ifdef ACK_RANGE_CONTROLLER
ACKError_t HandleRangeControllerDirective(void);
#endif

#ifdef ACK_TIME_HOLD_CONTROLLER
ACKError_t HandleTimeHoldControllerDirective(void);
#endif

#ifdef ACK_TOGGLE_CONTROLLER
ACKError_t HandleToggleControllerDirective(void);
#endif

#ifdef __cplusplus
}
#endif

#endif // def __ACK_DIRECTIVES_H__
