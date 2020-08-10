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

#include "Hardware.h"

// See comments in Hardware.h for information about the code in this file.
// Implementations are empty, as this hardware abstraction is simply an illustration for a
// hypothetical microwave oven, and not part of the firmware implementation for any real device.

bool Hardware_IsDoorOpen(void)
{
    return false;
}

uint16_t Hardware_GetKeypadState(void)
{
    return 0;
}

void Hardware_SetClockDisplay(HardwareClockMode Mode, const HardwareClockDisplay* pDisplay)
{
}

// Added for a connectivity status display for ACK.
void Hardware_SetConnectivityLamp(HardwareConnectivityState state)
{
}

bool Hardware_GetPersistedChildLock(void)
{
    return false;
}

void Hardware_PersistChildLock(bool locked)
{
}

void Hardware_StartCooking(HardwarePowerLevel level)
{
}

void Hardware_StopCooking(void)
{
}

void Hardware_EraseUserSettings(void)
{
}
