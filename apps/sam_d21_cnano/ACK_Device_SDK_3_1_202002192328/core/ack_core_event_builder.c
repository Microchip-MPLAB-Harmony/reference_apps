/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#include "ack.h"
#include "ack_core_common.h"
#include "ack_core_communication.h"
#include "ack_core_event_builder.h"
#include "ack_core_heaplet.h"
#include "ack_core_protobuf_utilities.h"
#include "acp.pb.h"
#include <inttypes.h>

static int32_t sg_correlationId;
static V3AVS_Namespace sg_namespace;
static uint32_t sg_instance;
static ACKError_t (*sg_pEncodeRoutine)(void) = NULL;

#ifdef ACK_EVENT_BUILDER_DIAG

static enum EventBuilderState
{
    EventBuilderState_NotBuilding,
    EventBuilderState_BuildingNoProperties,
    EventBuilderState_BuildingWithProperties,
    EventBuilderState_BuildingWithChangeReportPayloadProperties,
}
sg_state;

bool EventBuilderIsEventBeingBuilt(void)
{
    return EventBuilderState_NotBuilding != sg_state;
}

#endif // def ACK_EVENT_BUILDER_DIAG

// Begins building an event.
void EventBuilderStart(
    int32_t correlationId,
    V3AVS_Namespace v3_namespace,
    uint32_t instance,
    ACKError_t (*pEncodeRoutine)(void),
    unsigned flags)
{
    EventBuilderEnd();

    sg_correlationId = correlationId;
    sg_namespace = v3_namespace;
    sg_instance = instance;
    sg_pEncodeRoutine = pEncodeRoutine;

#ifdef ACK_EVENT_BUILDER_DIAG
    sg_state = EventBuilderState_BuildingNoProperties;
    if (flags & EVENT_FLAG_CAN_HAVE_PROPERTIES)
    {
        sg_state = EventBuilderState_BuildingWithProperties;

        if (flags & EVENT_FLAG_CAN_HAVE_CHANGE_REPORT_PAYLOAD_PROPERTIES)
        {
            sg_state = EventBuilderState_BuildingWithChangeReportPayloadProperties;
        }
    }
#endif
}

// Ends tracking the building of an event. Idempotent.
void EventBuilderEnd(void)
{
    // Free all memory blocks associated with building events.
    HeapletFree(MEM_OUTBOUND_EVENT_ENCODED_PROPERTY_DATA);
    HeapletFree(MEM_OUTBOUND_EVENT_PROPERTY_ARRAY);
    HeapletFree(MEM_OUTBOUND_EVENT_ACP_STRUCT);
    HeapletFree(MEM_OUTBOUND_EVENT_ENCODED_PAYLOAD);

#ifdef ACK_EVENT_BUILDER_DIAG
    sg_state = EventBuilderState_NotBuilding;
#endif
}

// Diagnostic to determine whether adding a property to the event being built is allowed.
#ifdef ACK_EVENT_BUILDER_DIAG

void EventBuilderCheckCanAddProperty(bool changeReportPayloadProperty)
{
    if (changeReportPayloadProperty)
    {
        ACK_ASSERT(EventBuilderState_BuildingWithChangeReportPayloadProperties == sg_state);
    }

    ACK_ASSERT((EventBuilderState_BuildingWithProperties == sg_state)
        || (EventBuilderState_BuildingWithChangeReportPayloadProperties == sg_state));
}

#endif

// Encodes an event from MEM_OUTBOUND_EVENT_ACP_STRUCT into MEM_OUTBOUND_EVENT_ENCODED_PAYLOAD.
ACKError_t EventBuilderCreateEncodedPayload(const pb_field_t* pFields)
{
    void* pSourceData;
    void* pEncodedData;
    size_t encodedSize;
    ACKError_t retval;

    pSourceData = HeapletAccess(MEM_OUTBOUND_EVENT_ACP_STRUCT);
    ACK_ASSERT(NULL != pSourceData);

    encodedSize = ProtobufGetEncodedSize(pFields, pSourceData);

    ACK_DEBUG_PRINT_D("Encoding event; encoded length %u.", (unsigned)encodedSize);

    pEncodedData = HeapletSetSize(MEM_OUTBOUND_EVENT_ENCODED_PAYLOAD, encodedSize);
    if (NULL == pEncodedData)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    // Reaccess source data in case HeapletSetSize moved it.
    pSourceData = HeapletAccess(MEM_OUTBOUND_EVENT_ACP_STRUCT);

    if (!ProtobufEncode((uint8_t*)pEncodedData, encodedSize, pFields, pSourceData))
    {
        ACK_DEBUG_PRINT_E("Unable to encode event.");
        retval = ACK_ERR_INTERNAL;
        goto cleanup0;
    }

    retval = ACK_NO_ERROR;

cleanup0:
    if (ACK_NO_ERROR != retval)
    {
        HeapletFree(MEM_OUTBOUND_EVENT_ENCODED_PAYLOAD);
    }

    return retval;
}

// Sends an event with payload from MEM_OUTBOUND_EVENT_ENCODED_PAYLOAD.
ACKError_t _SendEvent(void)
{
    ProtobufCallbackField_t desc;
    acp_cmd* pCommand;
    V3AVS_AvsEvent* pEvent;
    size_t encodedSize;
    void *pEncodedData;
    ACKError_t retval;

    pCommand = (acp_cmd*)HeapletSetSize(MEM_OUTBOUND_ACP_CMD, sizeof(acp_cmd));
    if (NULL == pCommand)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    pCommand->which_type = acp_cmd_send_alexa_event_obj_tag;
    pEvent = &pCommand->type.send_alexa_event_obj.event;

    // V3AVS_AvsEvent_init_zero exists, but is 24 bytes, so do this instead.
    memset(pEvent, 0, sizeof(*pEvent));

    pEvent->v3_namespace = sg_namespace;
    pEvent->instance = sg_instance;
    pEvent->correlation_id = sg_correlationId;
    pEvent->payload.funcs.encode = ProtobufEncodeCallbackField;
    pEvent->payload.arg = &desc;

    desc.Value = HeapletAccess(MEM_OUTBOUND_EVENT_ENCODED_PAYLOAD);
    desc.Length = HeapletGetSize(MEM_OUTBOUND_EVENT_ENCODED_PAYLOAD);

    encodedSize = ProtobufGetEncodedSize(acp_cmd_fields, pCommand);
    pEncodedData = HeapletSetSize(MEM_OUTBOUND_ENCODED_ACP_CMD, encodedSize);
    if (NULL == pEncodedData)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    // Allocation above must not have moved pCommand, and shouldn't have, because MEM_OUTBOUND_ACP_CMD is
    // less than MEM_OUTBOUND_ENCODED_ACP_CMD.
    ACK_ASSERT(HeapletAccess(MEM_OUTBOUND_ACP_CMD) == pCommand);

    ACK_DEBUG_PRINT_D("Encoding v3 event fields, encoded size is %u.", (unsigned)encodedSize);

    if (!ProtobufEncode(pEncodedData, encodedSize, acp_cmd_fields, pCommand))
    {
        ACK_DEBUG_PRINT_E(
            "Unable to encode the send Alexa response command. Buffer size is %u.",
            (unsigned)encodedSize);
        retval = ACK_ERR_INTERNAL;
        goto cleanup0;
    }

    // The encoded acp_cmd should not have moved because we haven't done any heaplet resizing.
    ACK_ASSERT(HeapletAccess(MEM_OUTBOUND_ENCODED_ACP_CMD) == pEncodedData);

    retval = CommsSendAcpProtobufCmd(pEncodedData, encodedSize);

    if (retval != ACK_NO_ERROR)
    {
        ACK_DEBUG_PRINT_E("Unable to send Alexa response command, err: %u.", retval);
        goto cleanup0;
    }

    // Done.
    retval = ACK_NO_ERROR;

cleanup0:
    // Free blocks we used internally. OK to do this evern if never allocated (such as in an error path),
    // or already freed.
    HeapletFree(MEM_OUTBOUND_ACP_CMD);
    HeapletFree(MEM_OUTBOUND_ENCODED_ACP_CMD);
    return retval;
}

// Sends the event being built.
ACKError_t EventBuilderSend(void)
{
    ACKError_t retval;

    ACK_DEBUG_PRINT_I(
        "Sending event, correlation id %"PRId32", namespace %u.",
        sg_correlationId,
        sg_namespace);

    // Encode.
    retval = sg_pEncodeRoutine();
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    retval = _SendEvent();
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    retval = ACK_NO_ERROR;

cleanup0:
    EventBuilderEnd();
    return retval;
}
