/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_TICK64_H__
#define __ACK_TICK64_H__

#include "ack_user_config.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef ACK_TICK64

// Returns tick count (elapsed milliseconds since boot) as a 64-bit value. Relies on ACK_Process being called
// at least once every 49.7 days (the wrap period for the 32-bit tick count returned by ACKPlatform_GetTick).
uint64_t ACK_GetTickCount64(void);

#endif

#ifdef __cplusplus
}
#endif

#endif // ndef __ACK_TICK64_H__
