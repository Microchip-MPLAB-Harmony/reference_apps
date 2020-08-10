/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

/*
    Header file for application-level user-supplied routines. You replace the placeholder implementations of
    routines decelared in here with your own device-specific logic.
*/

#ifndef __ACK_USER_DEVICE_H__
#define __ACK_USER_DEVICE_H__

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

// Returns the version of your firmware. This can be any 64-bit value meaningful for your firmware
// versioning scheme.
uint64_t ACKUser_GetFirmwareVersion(void);

// Change the implementation of this routine to return a value indicating whether your device is in use.
// If a device is in use, certain lifecycle processing is deferred until the device is not in use. For
// example, firmware updates are not initiated until this returns false.
bool ACKUser_IsDeviceInUse(void);

// Change the implementation of this routine to return a value based on your device-specific factory reset
// initiation mechanism (the user presses and holds a "reset" button, or enters a certain keystroke on a
// keypad, etc.).
bool ACKUser_DoesUserWantFactoryReset(void);

// Change the implementation of this routine to return a value based on your device-specific
// User-Guided Setup initiation mechanism (the user presses and holds a "setup" button, or enters a certain
// keystroke on a keypad, etc.).
bool ACKUser_DoesUserWantUserGuidedSetup(void);

// Change the implementation of this routine to return a value based on your device-specific
// initiation mechanism for submitting logs (the user presses and holds a specific button on the device,
// or enters a certain keystroke on a keypad, etc.).
bool ACKUser_DoesUserWantToSubmitLogs(void);

// Update user-facing display elements relating to lifecycle and connectivity state. For example, lighting a
// "connected to Alexa" LED, or flashing an LED during factory reset, or flashing a clock when in setup mode.
// State is maintained in the global variables ACK_LifecycleState and ACK_LifecycleSubStateInfo.
void ACKUser_OnLifecycleStateChange(void);

// Change the implementation of this routine to erase persisted user settings.
void ACKUser_EraseUserSettings(void);

#ifdef __cplusplus
}
#endif

#endif // def __ACK_USER_DEVICE_H__
