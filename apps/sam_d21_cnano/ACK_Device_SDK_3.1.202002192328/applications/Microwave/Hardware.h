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

/*
    Models hardware in a hypothetical microwave oven, consisting of

    * The magnetron, which is either on at a given power level, or off, at any given time.

    * The door, which is either open or closed at any given time.

    * A keypad, which is used to initiate local cooking or perform certain reserved keystrokes that
      signal HMCU Implementation Core to perform various actions.

    * A clock display, which can be in various states such as showing the time, or flashing zeros.

    * A connectivity display lamp, which indicates to the user whether the device is connected to
      Alexa or not.

    Higher-level semantics such as timers, interaction of door status with cooking state, child lock,
    paused vs. stopped are handled in the microwave application, not here.
*/

#ifndef __HARDWARE_H__
#define __HARDWARE_H__

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

// Represents a power level.
typedef enum _HardwarePowerLevel
{
    HARDWARE_POWER_LEVEL_OFF,
    HARDWARE_POWER_LEVEL_LOW,
    HARDWARE_POWER_LEVEL_MEDIUM,
    HARDWARE_POWER_LEVEL_HIGH
}
HardwarePowerLevel;

// Keypad/buttons.
typedef enum _HardwareKeypadKey
{
    HARDWARE_KEYPAD_KEY_0 = 0x0001,
    HARDWARE_KEYPAD_KEY_1 = 0x0002,
    HARDWARE_KEYPAD_KEY_2 = 0x0004,
    HARDWARE_KEYPAD_KEY_3 = 0x0008,
    HARDWARE_KEYPAD_KEY_4 = 0x0010,
    HARDWARE_KEYPAD_KEY_5 = 0x0020,
    HARDWARE_KEYPAD_KEY_6 = 0x0040,
    HARDWARE_KEYPAD_KEY_7 = 0x0080,
    HARDWARE_KEYPAD_KEY_8 = 0x0100,
    HARDWARE_KEYPAD_KEY_9 = 0x0200,
    HARDWARE_KEYPAD_KEY_START = 0x0400,
    HARDWARE_KEYPAD_KEY_DEFROST_BY_WEIGHT = 0x0800,
    HARDWARE_KEYPAD_KEY_PAUSE_STOP = 0x1000
}
HardwareKeypadKey;

// State of connectivity LED.
typedef enum _HardwareConnectivityState
{
    HARDWARE_CONNECTIVITY_OFF,
    HARDWARE_CONNECTIVITY_BLINKING,
    HARDWARE_CONNECTIVITY_SOLID
}
HardwareConnectivityState;

// Mode for clock display. Assumes that the meta-hardware includes a real-time clock.
// We don't show how to keep that updated.
typedef enum _HardwareClockMode
{
    HARDWARE_CLOCK_OFF,
    HARDWARE_CLOCK_TIME,
    HARDWARE_CLOCK_MESSAGE,     // 6 chars message such as remaining time
    HARDWARE_CLOCK_FLASHING     // 6 chars message such as all zeros
}
HardwareClockMode;

// Used for HARDWARE_CLOCK_MESSAGE and HARDWARE_CLOCK_FLASHING modes.
typedef struct _HardwareClockDisplay
{
    char Chars[6];
}
HardwareClockDisplay;

bool Hardware_IsDoorOpen(void);
uint16_t Hardware_GetKeypadState(void);
void Hardware_SetClockDisplay(HardwareClockMode Mode, const HardwareClockDisplay* pDisplay);

// Added for a connectivity status display for ACK.
void Hardware_SetConnectivityLamp(HardwareConnectivityState state);

bool Hardware_GetPersistedChildLock(void);
void Hardware_PersistChildLock(bool locked);

void Hardware_StartCooking(HardwarePowerLevel level);
void Hardware_StopCooking(void);

void Hardware_EraseUserSettings(void);

#ifdef __cplusplus
}
#endif

#endif // ndef __HARDWARE_H__
