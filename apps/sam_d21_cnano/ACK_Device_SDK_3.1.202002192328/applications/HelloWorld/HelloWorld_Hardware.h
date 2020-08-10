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

#ifndef __HELLO_WORLD_HARDWARE_H__
#define __HELLO_WORLD_HARDWARE_H__

#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

// State of connectivity LED.
typedef enum _HardwareConnectivityLedState
{
    HARDWARE_CONNECTIVITY_LED_OFF,
    HARDWARE_CONNECTIVITY_LED_BLINKING,
    HARDWARE_CONNECTIVITY_LED_SOLID
}
HardwareConnectivityLedState;

void Hardware_SetPowerState(bool powerOn);
bool Hardware_IsPowerOn(void);
bool Hardware_IsPowerToggleButtonDown(void);

// Added for ACK.
void Hardware_SetConnectivityLedState(HardwareConnectivityLedState state);
bool Hardware_IsLifecycleButtonDown(void);

#ifdef __cplusplus
}
#endif

#endif // ndef __HELLO_WORLD_HARDWARE_H__
