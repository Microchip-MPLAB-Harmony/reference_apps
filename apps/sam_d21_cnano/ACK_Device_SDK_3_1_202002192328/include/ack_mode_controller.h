/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_MODE_CONTROLLER_H__
#define __ACK_MODE_CONTROLLER_H__

#include "ack_user_config.h"
#include "details/ack_types.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef ACK_MODE_CONTROLLER

// You must implement this routine.
// Note: if is_delta is 0, value can be cast to a uint32_t.
void ACKUser_OnModeControllerDirective(int32_t correlationId, uint32_t instance, bool isDelta, int32_t value);

// Call this to add a property representing the state of a mode controller to an outbound event.
ACKError_t ACK_AddModeControllerProperty(
    uint32_t instance,
    const ACKStateCommon_t* pCommon,
    uint32_t mode);

#endif // def ACK_MODE_CONTROLLER

#ifdef __cplusplus
}
#endif

#endif // def __ACK_MODE_CONTROLLER_H__
