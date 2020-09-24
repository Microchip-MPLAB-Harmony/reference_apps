/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_COMMUNICATION_H__
#define __ACK_COMMUNICATION_H__

#include "ack.h"
#include "ack_core_communication_protocol.h"
#include "ack_core_heaplet.h"
#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define ACP_IO_TIMEOUT_MS 500

ACKError_t CommsSendAcpProtobufCmd(const void* pBuffer, size_t length);

// Gets the response into the given tag.
ACKError_t CommsGetAcpResponse(HeapletTag_t targetHeapletTag);

#ifdef __cplusplus
}
#endif

#endif // def __ACK_COMMUNICATION_H__

