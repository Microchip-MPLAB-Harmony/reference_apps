/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_TIME_HOLD_CONTROLLER_H__
#define __ACK_TIME_HOLD_CONTROLLER_H__

#include "ack_user_config.h"
#include "details/ack_types.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef ACK_TIME_HOLD_CONTROLLER

// You must implement this routine.
void ACKUser_OnTimeHoldControllerHoldDirective(int32_t correlationId);

// You must implement this routine.
void ACKUser_OnTimeHoldControllerResumeDirective(int32_t correlationId);

#endif // def ACK_TIME_HOLD_CONTROLLER

#ifdef __cplusplus
}
#endif

#endif // def __ACK_TIME_HOLD_CONTROLLER_H__
