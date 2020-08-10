/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_CORE_ENDPOINT_HEALTH_H__
#define __ACK_CORE_ENDPOINT_HEALTH_H__

#include "details/ack_types.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Adds an endpoint health OK property to events.
ACKError_t EndpointHealthAddPropertyToEvent(const ACKStateCommon_t* pCommon);

#ifdef __cplusplus
}
#endif

#endif // ndef __ACK_CORE_ENDPOINT_HEALTH_H__
