/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#include "ack_core_tick64.h"
#include "ack_tick64.h"
#include "ack_user_config.h"
#include "ack_user_platform.h"
#include <stdint.h>

#ifdef ACK_TICK64

// When asked for a 64-bit tick count, this value is compared against the current 32-bit tick count to
// determine whether it wrapped. Initialize to zero here and not in ACK_Initialize because a tick count
// must represent time since boot, independently of whether this codebase is re-initialized.
// The wrap detection in Tick64Loop does a less-than comparison against this value. Because no
// unsigned value can be less than zero, we don't need to worry about whether the first call to
// MaintainTickCount64 (called from ACK_Process) was done in the first 49.7 days. 
uint32_t g_tick64PreviousTicks = 0;

// High part of the 64-bit tick count. To save a small amount of space, we maintain this internally as a
// 16-bit value instead of a full 32-bit value. The resulting 48-bit tick count has a wrap period of
// ~8925 years, which is probably safe.
// If ACK_Process is not called within the first 49.7 days of uptime, the high part won't be the correct
// count of ticks, but can still be used for timing, so we don't worry about this case.
uint16_t g_tick64High = 0;

// Returns a 64-bit tick count.
uint64_t ACK_GetTickCount64(void)
{
    return ((uint64_t)g_tick64High << 32) | ACKPlatform_TickCount();
}

// Called from ACK_Process.
void Tick64Loop(void)
{
    uint32_t now;

    now = ACKPlatform_TickCount();

    if (now < g_tick64PreviousTicks)
    {
        // Wrapped.
        ++g_tick64High;
    }

    g_tick64PreviousTicks = now;
}

#endif // def ACK_TICK64
