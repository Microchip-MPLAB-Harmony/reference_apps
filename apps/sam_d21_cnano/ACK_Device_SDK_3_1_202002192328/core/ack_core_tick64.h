/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_CORE_TICK64_h__
#define __ACK_CORE_TICK64_h__

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

void Tick64Loop(void);

// These are here for testing purposes and should not be accessed directly by any code outside
// of ack_core_tick64.c.
extern uint32_t g_tick64PreviousTicks;
extern uint16_t g_tick64High;

#ifdef __cplusplus
}
#endif

#endif // ndef __ACK_CORE_TICK64_h__
