/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#include "ack.h"
#include "ack_user_platform.h"

bool ACK_IsHostInterruptAsserted(void)
{
    // The Host Interrupt pin is active-low.
    return !ACKPlatform_ReadDigitalPin(ACK_HW_PIN_HOST_INTERRUPT);
}

void ACK_ResetConnectivityModule(void)
{
    // The Module Reset pin is active-low.
    ACKPlatform_WriteDigitalPin(ACK_HW_PIN_MODULE_RESET, false);
    ACKPlatform_Delay(250);
    ACKPlatform_WriteDigitalPin(ACK_HW_PIN_MODULE_RESET, true);
}
