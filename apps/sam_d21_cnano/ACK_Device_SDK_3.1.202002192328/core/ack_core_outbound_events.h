/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_CORE_OUTBOUND_EVENTS_H__
#define __ACK_CORE_OUTBOUND_EVENTS_H__

#include "ack_user_config.h"
#include "ack.h"
#ifdef ACK_DASH_REPLENISHMENT
#include "ack_dash_replenishment.h"
#endif
#include <stdint.h>
#include "v3avs_capabilities/V3AlexaCooking.pb.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Information about a pending outbound event.
typedef struct _ACKOutboundEventInfo_t
{
    // Designates properties to be included in the outbound event, if any.
    ACKPropertiesBits_t PropertiesBits;

    // Indicates which properties actually changed, if any.
    ACKPropertiesBits_t ChangeReportPayloadPropertiesBits;

    union 
    {
        struct
        {
            unsigned EventPending : 1;
            unsigned SynthesizeChangeReport : 1;
            unsigned IsChangeReport : 1;
            unsigned AddEndpointHealthProperty : 1;
        }
        Bits;

        uint8_t All;
    }
    Flags;
}
ACKOutboundEventInfo_t;

extern ACKOutboundEventInfo_t g_pendingOutboundEvent;

ACKError_t OutboundEventSend(void);
ACKError_t OutboundEventSendIfNotProcessingInboundEvent(void);

void OutboundEventReset(void);

#ifdef __cplusplus
}
#endif

#endif // ndef __ACK_CORE_OUTBOUND_EVENTS_H__
