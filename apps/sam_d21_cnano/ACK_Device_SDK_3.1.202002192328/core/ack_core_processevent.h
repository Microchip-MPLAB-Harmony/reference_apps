/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_PROCESSEVENT_H__
#define __ACK_PROCESSEVENT_H__

#include "details/ack_types.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Processes an event from the connectivity module if one is available.
// If no event is available, returns immediately with ACK_NO_ERROR.
// If the return value is ACK_NO_ERROR, an event may or may not have been processed. The caller
// must maintain state to determine whether a reply event is to be sent on a subsequent pass
// through the main loop.
ACKError_t ProcessEventIfAvailable(void);

// Information about inbound event processing state.
typedef union _ACKInboundEventInfo_t
{
    struct
    {
        // 1 if currently nested inside ProcessEventIfAvailable.
        unsigned Processing : 1;

        // 1 if most recent call to ProcessEventIfAvailable processed a directive.
        unsigned ProcessedDirective : 1;
    }
    Bits;

    uint8_t All;
}
ACKInboundEventInfo_t;

extern ACKInboundEventInfo_t g_inboundEventInfo;

#ifdef __cplusplus
}
#endif

#endif // ndef __ACK_PROCESSEVENT_H__
