/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_RANGE_CONTROLLER_H__
#define __ACK_RANGE_CONTROLLER_H__

#include "ack_user_config.h"
#include "details/ack_types.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef ACK_RANGE_CONTROLLER

// You must implement this routine.
// If is_delta is false, value is the absolute quantity to which to set the controller state.
// If is_delta is true, value is the amount by which to adjust the controller state. In this case,
// isDefaultDelta indicates whether value was a default value, vs. being explicitly specified by the user.
void ACKUser_OnRangeControllerDirective(
    int32_t correlationId,
    uint32_t instance,
    bool isDelta,
    double value,
    bool isDefaultDelta);

// Call this to add a property representing the state of a range controller to an outbound event.
ACKError_t ACK_AddRangeControllerProperty(
    uint32_t instance,
    const ACKStateCommon_t* pCommon,
    double value);

#endif // def ACK_RANGE_CONTROLLER

#ifdef __cplusplus
}
#endif

#endif // def __ACK_RANGE_CONTROLLER_H__
