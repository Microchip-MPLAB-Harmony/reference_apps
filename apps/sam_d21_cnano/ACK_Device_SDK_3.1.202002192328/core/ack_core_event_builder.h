/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#include "ack.h"
#include "pb.h"
#include <stdint.h>
#include "V3AVS.pb.h"

#ifndef __ACK_EVENT_BUILDER_H__
#define __ACK_EVENT_BUILDER_H__

#ifdef __cplusplus
extern "C"
{
#endif

// Diagnostics. Enabled if assertions are enabled.
#ifdef ACK_ENABLE_ASSERT
#define ACK_EVENT_BUILDER_DIAG
#else
#undef ACK_EVENT_BUILDER_DIAG
#endif
#if defined(ACK_EVENT_BUILDER_DIAG) && !defined(ACK_ENABLE_ASSERT)
#error Cannot have ACK_EVENT_BUILDER_DIAG without ACK_ENABLE_ASSERT
#endif

#define EVENT_FLAGS_NONE 0
#define EVENT_FLAG_CAN_HAVE_PROPERTIES 0x01
#define EVENT_FLAG_CAN_HAVE_CHANGE_REPORT_PAYLOAD_PROPERTIES 0x02

// Begins tracking the building of an event.
void EventBuilderStart(
    int32_t correlationId,
    V3AVS_Namespace v3Namespace,
    uint32_t instance,
    ACKError_t (*pEncodeRoutine)(void),
    unsigned flags);

// Ends tracking the building of an event.
void EventBuilderEnd(void);

// Send a completed event, after EventBuilderStart and adding any properties. This routine releases memory
// that was being used to build the event, even if a failure error is returned, so there is no need to call
// EventBuilderEnd in case EventBuilderSend fails.
ACKError_t EventBuilderSend(void);

#ifdef ACK_EVENT_BUILDER_DIAG

// Diagnostic to determine whether adding a property to the event being built is allowed.
void EventBuilderCheckCanAddProperty(bool changeReportPayloadProperty);
#define ACK_CHECK_CAN_ADD_PROPERTY_TO_EVENT(b) EventBuilderCheckCanAddProperty(b)

bool EventBuilderIsEventBeingBuilt(void);

#else

#define ACK_CHECK_CAN_ADD_PROPERTY_TO_EVENT(b)

#endif // def ACK_EVENT_BUILDER_DIAG

// Encodes an event from MEM_OUTBOUND_EVENT_ACP_STRUCT into MEM_OUTBOUND_EVENT_ENCODED_PAYLOAD.
ACKError_t EventBuilderCreateEncodedPayload(const pb_field_t* pFields);

#ifdef __cplusplus
}
#endif

#endif // ndef __ACK_EVENT_BUILDER_H__
