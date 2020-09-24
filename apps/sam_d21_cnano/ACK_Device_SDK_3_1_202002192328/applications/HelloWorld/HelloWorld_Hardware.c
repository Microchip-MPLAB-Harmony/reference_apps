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

#include "ack_user_platform.h"
#include "HelloWorld_Hardware.h"

// The implementations use ACKPlatform_ReadDigitalPin/ACKPlatform_WriteDigitalPin. In a real device,
// you would just touch your hardware directly. The ACKPlatform_xxx routines are used in this sample
// solely to achieve portability.

void Hardware_SetPowerState(bool powerOn)
{
    ACKPlatform_WriteDigitalPin(ACK_HW_PIN_SAMPLE_APPLICATIONS_LED, powerOn);
}

bool Hardware_IsPowerOn(void)
{
    return ACKPlatform_ReadDigitalPin(ACK_HW_PIN_SAMPLE_APPLICATIONS_LED);
}

bool Hardware_IsPowerToggleButtonDown(void)
{
    // TODO
    return false;
}

void Hardware_SetConnectivityLedState(HardwareConnectivityLedState state)
{
    // TODO
}

bool Hardware_IsLifecycleButtonDown(void)
{
    // TODO
    return false;
}
