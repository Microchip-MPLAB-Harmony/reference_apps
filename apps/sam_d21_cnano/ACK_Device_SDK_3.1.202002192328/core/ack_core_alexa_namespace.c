/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#include "ack.h"
#include "ack_core_alexa_namespace.h"
#include "ack_core_common.h"
#include "ack_core_communication.h"
#include "ack_core_directives.h"
#include "ack_core_event_builder.h"
#include "ack_core_heaplet.h"
#include "ack_core_outbound_events.h"
#include "ack_core_protobuf_utilities.h"
#include "ack_user_config.h"
#include "acp.pb.h"
#include <inttypes.h>
#include "v3avs_capabilities/V3Alexa.pb.h"
#include "v3avs_capabilities/V3AVS.pb.h"

static ACKError_t StartBuildResponse_(
    int32_t correlationId,
    v3avs_capabilities_V3Alexa_EventName eventName,
    pb_size_t whichPayload,
    unsigned eventBuilderFlags);

static bool IsChangeReportContextProperty_(const void* pData);
static bool IsChangeReportPayloadProperty_(const void* pData);

// Processes a directive in the Alexa namespace.
ACKError_t HandleAlexaInterfaceDirective(void)
{
    V3AVS_AvsDirective* pOuterDirective;
    v3avs_capabilities_V3Alexa_Directive* pDirective;
    ACKError_t retval;
    bool protoResult;

    pDirective = (v3avs_capabilities_V3Alexa_Directive*)HeapletSetSize(
        MEM_RECEIVED_DIRECTIVE_PAYLOAD,
        sizeof(v3avs_capabilities_V3Alexa_Directive));
    if (NULL == pDirective)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    protoResult = ProtobufDecode(
        HeapletAccess(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        HeapletGetSize(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        v3avs_capabilities_V3Alexa_Directive_fields,
        pDirective);

    if (!protoResult)
    {
        ACK_DEBUG_PRINT_E("Unable to decode Alexa interface directive payload.");
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    pOuterDirective = (V3AVS_AvsDirective*)HeapletAccess(MEM_RECEIVED_AVS_DIRECTIVE_ENVELOPE);

    // Report-state is the only directive we handle.
    if (v3avs_capabilities_V3Alexa_Directive_report_state_tag != pDirective->which_payload)
    {
        ACK_DEBUG_PRINT_W("Unhandled directive %u in Alexa namespace", pDirective->which_payload);
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    ACK_DEBUG_PRINT_I("Directive is a request to report state.");

    ACK_REENTRY_SHIELDS_UP;

    ACKUser_OnReportStateDirective(pOuterDirective->correlation_id);

    ACK_REENTRY_SHIELDS_DOWN;

    retval = ACK_NO_ERROR;

cleanup0:
    // OK to call if never allocated or already freed.
    HeapletFree(MEM_RECEIVED_DIRECTIVE_PAYLOAD);
    return retval;
}

ACKError_t ACK_CompleteDirectiveWithSuccess(
    int32_t correlationId,
    ACKPropertiesBits_t responsePropertiesBits,
    ACKPropertiesBits_t changeReportPropertiesBits)
{
    ACKError_t retval;

    ACK_DEBUG_PRINT_I("Creating Alexa response event, correlationId %"PRId32".", correlationId);

    OutboundEventReset();

    retval = AlexaNamespaceStartBuildDirectiveSuccessEvent(
        correlationId,
        responsePropertiesBits,
        changeReportPropertiesBits);
    if (ACK_NO_ERROR !=- retval)
    {
        goto cleanup0;
    }

    retval = OutboundEventSendIfNotProcessingInboundEvent();
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    retval = ACK_NO_ERROR;

cleanup0:
    if (ACK_NO_ERROR != retval)
    {
        EventBuilderEnd();
    }

    return retval;
}

ACKError_t AlexaNamespaceStartBuildDirectiveSuccessEvent(
    int32_t correlationId,
    ACKPropertiesBits_t responsePropertiesBits,
    ACKPropertiesBits_t changeReportPropertiesBits)
{
    ACKError_t retval;

    retval = StartBuildResponse_(
        correlationId,
        v3avs_capabilities_V3Alexa_EventName_RESPONSE,
        v3avs_capabilities_V3Alexa_Event_response_tag,
        EVENT_FLAG_CAN_HAVE_PROPERTIES);

    if (ACK_NO_ERROR == retval)
    {
        g_pendingOutboundEvent.Flags.Bits.EventPending = true;
        g_pendingOutboundEvent.Flags.Bits.SynthesizeChangeReport = true;

        g_pendingOutboundEvent.ChangeReportPayloadPropertiesBits = changeReportPropertiesBits;
        g_pendingOutboundEvent.PropertiesBits = responsePropertiesBits;
    }

    return retval;
}

ACKError_t ACK_CompleteDirectiveWithSimpleError(
    int32_t correlationId,
    v3avs_capabilities_V3Alexa_ErrorResponse_ErrorType type,
    const char* pOptionalMessage)
{
    ACKError_t retval;

    ACK_DEBUG_PRINT_I(
        "Creating Alexa error response event, correlationId %"PRId32", error Type %u.",
        correlationId,
        type);

    // More specific routine must be used if one is available.
#ifdef ACK_ENABLE_ASSERT
    bool mustUseMoreSpecific = (v3avs_capabilities_V3Alexa_ErrorResponse_ErrorType_VALUE_OUT_OF_RANGE == type)
        || (v3avs_capabilities_V3Alexa_ErrorResponse_ErrorType_TEMPERATURE_VALUE_OUT_OF_RANGE == type)
        || (v3avs_capabilities_V3Alexa_ErrorResponse_ErrorType_NOT_SUPPORTED_IN_CURRENT_MODE == type);
    if (mustUseMoreSpecific)
    {
        ACK_ASSERT(!
            "To report this kind of error, you must call a more specific ACK_CompleteDirectiveWith*Error "
            "routine. See comments in ack.h.");
    }
#endif // def ACK_ENABLE_ASSERT

    OutboundEventReset();

    retval = AlexaNamespaceStartBuildDirectiveErrorEvent(correlationId, type, pOptionalMessage, NULL);
    if (ACK_NO_ERROR != retval)
    {
        ACK_DEBUG_PRINT_E("Unable to encode payload for Alexa error response, err %u.", retval);
        goto cleanup0;
    }

    g_pendingOutboundEvent.Flags.Bits.EventPending = true;

    retval = OutboundEventSendIfNotProcessingInboundEvent();
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    // Success
    retval = ACK_NO_ERROR;

cleanup0:
    if (ACK_NO_ERROR != retval)
    {
        EventBuilderEnd();
    }

    return retval;
}

ACKError_t ACK_CompleteDirectiveWithOutOfRangeError(
    int32_t correlationId,
    float minimum,
    float maximum,
    const char* pOptionalMessage)
{
    ACKError_t retval;

    ACK_DEBUG_PRINT_I(
        "Creating Alexa value-out-of-range error response event, correlationId %"PRId32".",
        correlationId);

    OutboundEventReset();

    retval = AlexaNamespaceStartBuildDirectiveOutOfRangeErrorEvent(
        correlationId,
        minimum,
        maximum,
        pOptionalMessage);
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    retval = OutboundEventSendIfNotProcessingInboundEvent();
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    // Success.
    retval = ACK_NO_ERROR;

cleanup0:
    if (ACK_NO_ERROR != retval)
    {
        EventBuilderEnd();
    }

    return retval;
}

ACKError_t AlexaNamespaceStartBuildDirectiveOutOfRangeErrorEvent(
    int32_t correlationId,
    float minimum,
    float maximum,
    const char* pOptionalMessage)
{
    ACKError_t retval;
    v3avs_capabilities_V3Alexa_ValueOutOfRange* pValue;
    
    pValue = (v3avs_capabilities_V3Alexa_ValueOutOfRange*)HeapletSetSize(
        MEM_OUTBOUND_EVENT_ERROR_RESPONSE_DATA,
        sizeof(*pValue));
    if (NULL == pValue)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    pValue->which_minimumValue = v3avs_capabilities_V3Alexa_ValueOutOfRange_minValue_tag;
    pValue->which_maximumValue = v3avs_capabilities_V3Alexa_ValueOutOfRange_maxValue_tag;
    pValue->minimumValue.minValue = minimum;
    pValue->maximumValue.maxValue = maximum;

    retval = AlexaNamespaceStartBuildDirectiveErrorEvent(
        correlationId,
        v3avs_capabilities_V3Alexa_ErrorResponse_ErrorType_VALUE_OUT_OF_RANGE,
        pOptionalMessage,
        v3avs_capabilities_V3Alexa_ValueOutOfRange_fields);
    if (ACK_NO_ERROR != retval)
    {
        ACK_DEBUG_PRINT_E(
            "Unable to encode payload for value-of-out-range Alexa error response, err %u.",
            retval);
        goto cleanup0;
    }

    g_pendingOutboundEvent.Flags.Bits.EventPending = true;

    retval = ACK_NO_ERROR;

cleanup0:
    HeapletFree(MEM_OUTBOUND_EVENT_ERROR_RESPONSE_DATA);

    return retval;
}

ACKError_t ACK_CompleteDirectiveWithTemperatureOutOfRangeError(
    int32_t correlationId,
    v3avs_types_V3Temperature_Scale scale,
    float minimum,
    float maximum,
    const char* pOptionalMessage)
{
    ACKError_t retval;

    ACK_DEBUG_PRINT_I(
        "Creating Alexa temperature-value-out-of-range error response event, correlationId %"PRId32".",
        correlationId);

    OutboundEventReset();

    retval = AlexaNamespaceStartBuildDirectiveTemperatureOutOfRangeErrorEvent(
        correlationId,
        scale,
        minimum,
        maximum,
        pOptionalMessage);
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    retval = OutboundEventSendIfNotProcessingInboundEvent();
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    // Success.
    retval = ACK_NO_ERROR;

cleanup0:
    if (ACK_NO_ERROR != retval)
    {
        EventBuilderEnd();
    }

    return retval;
}

ACKError_t AlexaNamespaceStartBuildDirectiveTemperatureOutOfRangeErrorEvent(
    int32_t correlationId,
    v3avs_types_V3Temperature_Scale scale,
    float minimum,
    float maximum,
    const char* pOptionalMessage)
{
    ACKError_t retval;
    v3avs_capabilities_V3Alexa_ValueOutOfRange* pValue;

    pValue = (v3avs_capabilities_V3Alexa_ValueOutOfRange*)HeapletSetSize(
        MEM_OUTBOUND_EVENT_ERROR_RESPONSE_DATA,
        sizeof(*pValue));
    if (NULL == pValue)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    pValue->which_minimumValue = v3avs_capabilities_V3Alexa_ValueOutOfRange_minTemperature_tag;
    pValue->which_maximumValue = v3avs_capabilities_V3Alexa_ValueOutOfRange_maxTemperature_tag;
    pValue->minimumValue.minTemperature.value = minimum;
    pValue->maximumValue.maxTemperature.value = maximum;
    pValue->minimumValue.minTemperature.scale = scale;
    pValue->maximumValue.maxTemperature.scale = scale;

    retval = AlexaNamespaceStartBuildDirectiveErrorEvent(
        correlationId,
        v3avs_capabilities_V3Alexa_ErrorResponse_ErrorType_TEMPERATURE_VALUE_OUT_OF_RANGE,
        pOptionalMessage,
        v3avs_capabilities_V3Alexa_ValueOutOfRange_fields);
    if (ACK_NO_ERROR != retval)
    {
        ACK_DEBUG_PRINT_E(
            "Unable to encode payload for temperature-out-of-range Alexa error response, err %u.",
            retval);
        goto cleanup0;
    }

    g_pendingOutboundEvent.Flags.Bits.EventPending = true;

    retval = ACK_NO_ERROR;

cleanup0:
    HeapletFree(MEM_OUTBOUND_EVENT_ERROR_RESPONSE_DATA);

    return retval;
}

ACKError_t ACK_CompleteDirectiveWithNotSupportedInCurrentModeError(
    int32_t correlationId,
    v3avs_capabilities_V3Alexa_NotSupportedInCurrentMode_DeviceMode mode,
    const char* pOptionalMessage)
{
    ACKError_t retval;

    ACK_DEBUG_PRINT_I(
        "Creating Alexa not-supported-in-current-mode error response event, correlationId %"PRId32".",
        correlationId);

    OutboundEventReset();

    retval = AlexaNamespaceStartBuildDirectiveNotSupportedInCurrentModeErrorEvent(
        correlationId,
        mode,
        pOptionalMessage);
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    retval = OutboundEventSendIfNotProcessingInboundEvent();
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    // Success.
    retval = ACK_NO_ERROR;

cleanup0:
    if (ACK_NO_ERROR != retval)
    {
        EventBuilderEnd();
    }

    return retval;
}

ACKError_t AlexaNamespaceStartBuildDirectiveNotSupportedInCurrentModeErrorEvent(
    int32_t correlationId,
    v3avs_capabilities_V3Alexa_NotSupportedInCurrentMode_DeviceMode mode,
    const char* pOptionalMessage)
{
    ACKError_t retval;
    v3avs_capabilities_V3Alexa_NotSupportedInCurrentMode* pValue;

    pValue = (v3avs_capabilities_V3Alexa_NotSupportedInCurrentMode*)HeapletSetSize(
        MEM_OUTBOUND_EVENT_ERROR_RESPONSE_DATA,
        sizeof(*pValue));
    if (NULL == pValue)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    pValue->deviceMode = mode;

    retval = AlexaNamespaceStartBuildDirectiveErrorEvent(
        correlationId,
        v3avs_capabilities_V3Alexa_ErrorResponse_ErrorType_NOT_SUPPORTED_IN_CURRENT_MODE,
        pOptionalMessage,
        v3avs_capabilities_V3Alexa_NotSupportedInCurrentMode_fields);
    if (ACK_NO_ERROR != retval)
    {
        ACK_DEBUG_PRINT_E(
            "Unable to encode payload for not-supported-in-current-mode Alexa error response, err %u",
            retval);
        goto cleanup0;
    }

    g_pendingOutboundEvent.Flags.Bits.EventPending = true;

    retval = ACK_NO_ERROR;

cleanup0:
    HeapletFree(MEM_OUTBOUND_EVENT_ERROR_RESPONSE_DATA);

    return retval;
}

ACKError_t ACK_CompleteStateReportWithSuccess(int32_t correlationId)
{
    ACKError_t retval;

    ACK_DEBUG_PRINT_I("Creating Alexa state report event, correlationId %"PRId32".", correlationId);

    OutboundEventReset();

    retval = AlexaNamespaceStartBuildStateReportSuccessEvent(correlationId);
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    retval = OutboundEventSendIfNotProcessingInboundEvent();
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    retval = ACK_NO_ERROR;

cleanup0:
    if (ACK_NO_ERROR != retval)
    {
        EventBuilderEnd();
    }

    return retval;
}

ACKError_t AlexaNamespaceStartBuildStateReportSuccessEvent(int32_t correlationId)
{
    ACKError_t retval;

    retval = StartBuildResponse_(
        correlationId,
        v3avs_capabilities_V3Alexa_EventName_STATE_REPORT,
        v3avs_capabilities_V3Alexa_Event_state_report_tag,
        EVENT_FLAG_CAN_HAVE_PROPERTIES);
    if (ACK_NO_ERROR == retval)
    {
        g_pendingOutboundEvent.Flags.Bits.EventPending = true;
        g_pendingOutboundEvent.Flags.Bits.AddEndpointHealthProperty = true;

        g_pendingOutboundEvent.PropertiesBits = ACK_EVENT_ALL_PROPERTIES;
        g_pendingOutboundEvent.ChangeReportPayloadPropertiesBits = 0;
    }

    return retval;
}

ACKError_t ACK_SendChangeReport(
    v3avs_capabilities_V3Alexa_Cause_CauseType cause,
    ACKPropertiesBits_t changedProperiesBits,
    ACKPropertiesBits_t otherPropertiesBits)
{
    ACKError_t retval;

    ACK_DEBUG_PRINT_I("Sending Alexa change report event, cause %u.", cause);

    ACK_REENTRY_CHECK;

    OutboundEventReset();

    retval = AlexaNamespaceStartChangeReportEvent(cause);
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    g_pendingOutboundEvent.ChangeReportPayloadPropertiesBits = changedProperiesBits;
    g_pendingOutboundEvent.PropertiesBits = otherPropertiesBits;

    retval = OutboundEventSend();
    if (ACK_NO_ERROR != retval)
    {
        ACK_DEBUG_PRINT_E("Error %u sending change report event.", retval);
        goto cleanup0;
    }

    retval = ACK_NO_ERROR;

cleanup0:
    EventBuilderEnd();
    return retval;
}

ACKError_t AlexaNamespaceStartChangeReportEvent(v3avs_capabilities_V3Alexa_Cause_CauseType cause)
{
    ACKError_t retval;
    v3avs_capabilities_V3Alexa_Event* pEvent;

    retval = StartBuildResponse_(
        0, // No correlationId.
        v3avs_capabilities_V3Alexa_EventName_CHANGE_REPORT,
        v3avs_capabilities_V3Alexa_Event_change_report_tag,
        EVENT_FLAG_CAN_HAVE_PROPERTIES | EVENT_FLAG_CAN_HAVE_CHANGE_REPORT_PAYLOAD_PROPERTIES);

    if (ACK_NO_ERROR == retval)
    {
        pEvent = (v3avs_capabilities_V3Alexa_Event*)HeapletAccess(MEM_OUTBOUND_EVENT_ACP_STRUCT);
        pEvent->payload.change_report.change.cause.type = cause;

        g_pendingOutboundEvent.Flags.Bits.EventPending = true;
        g_pendingOutboundEvent.Flags.Bits.IsChangeReport = true;
        g_pendingOutboundEvent.Flags.Bits.AddEndpointHealthProperty = true;
    }

    return retval;
}

// Worker routine, begins building an Alexa response event.
ACKError_t StartBuildResponse_(
    int32_t correlationId,
    v3avs_capabilities_V3Alexa_EventName eventName,
    pb_size_t whichPayload,
    unsigned eventBuilderFlags)
{
    v3avs_capabilities_V3Alexa_Event* pEvent;
    ACKError_t retval;

    EventBuilderStart(
        correlationId,
        V3AVS_Namespace_V3_ALEXA,
        0, // instance not used for this namespace
        AlexaNamespaceEncodeEventPayload,
        eventBuilderFlags);

    pEvent = (v3avs_capabilities_V3Alexa_Event*)HeapletSetSize(
        MEM_OUTBOUND_EVENT_ACP_STRUCT,
        sizeof(v3avs_capabilities_V3Alexa_Event));
    if (NULL == pEvent)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    // v3avs_capabilities_V3Alexa_Event_init_default exists, but is ~192 bytes.
    // Just zero out here instead of pulling that large struct into the image.
    memset(pEvent, 0, sizeof(*pEvent));

    pEvent->name = eventName;
    pEvent->which_payload = whichPayload;

    // Success.
    retval = ACK_NO_ERROR;

cleanup0:
    // Not needed, since there are no operations that can fail above following the HeapletSetSize
    // to allocate this block.
    //if (ACK_NO_ERROR != retval)
    //{
    //    HeapletFree(MEM_OUTBOUND_EVENT_ACP_STRUCT);
    //}
    return retval;
}

// Struct to be encoded is in MEM_OUTBOUND_EVENT_ERROR_RESPONSE_DATA.
ACKError_t AlexaNamespaceStartBuildDirectiveErrorEvent(
    int32_t correlationId,
    v3avs_capabilities_V3Alexa_ErrorResponse_ErrorType type,
    const char* pLogMessage,
    const pb_field_t* pPayloadFields)
{
    v3avs_capabilities_V3Alexa_Event* pEvent;
    size_t dataSize;
    uint8_t* pData;
    size_t stringSize;
    ACKError_t retval;
    bool protoResult;

    retval = StartBuildResponse_(
        correlationId,
        v3avs_capabilities_V3Alexa_EventName_ERROR_RESPONSE,
        v3avs_capabilities_V3Alexa_Event_error_response_tag,
        EVENT_FLAG_CAN_HAVE_PROPERTIES);
    if (ACK_NO_ERROR != retval)
    {
        ACK_DEBUG_PRINT_E("Unable to set up for Alexa error response, err %u", retval);
        goto cleanup0;
    }

    // Determine size needed in the data block.
    dataSize = 0;
    stringSize = 0;
    if (pLogMessage)
    {
        stringSize = strlen(pLogMessage);
        dataSize += stringSize;
    }

    if (pPayloadFields)
    {
        dataSize += ProtobufGetEncodedSize(
            pPayloadFields,
            HeapletAccess(MEM_OUTBOUND_EVENT_ERROR_RESPONSE_DATA));
    }

    ACK_ASSERT(NULL == HeapletAccess(MEM_OUTBOUND_EVENT_ENCODED_PROPERTY_DATA));
    pData = (uint8_t*)HeapletSetSize(MEM_OUTBOUND_EVENT_ENCODED_PROPERTY_DATA, dataSize);

    if (NULL == pData)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    // A data structure representing the event was already created, when the user called
    // AlexaNamespaceStartErrorResponseEvent et al, before those routines call this one.
    pEvent = (v3avs_capabilities_V3Alexa_Event*)HeapletAccess(MEM_OUTBOUND_EVENT_ACP_STRUCT);
    pEvent->payload.error_response.type = type;

    // Save data in the data block.
    if (pLogMessage)
    {
        memcpy(pData, pLogMessage, stringSize);

        ACK_STATIC_ASSERT(sizeof(pEvent->payload.error_response.message.funcs.encode) >= sizeof(pData));
        pEvent->payload.error_response.message.funcs.encode = (ACKNanopbEncodeFunction_t)pData;

        ACK_STATIC_ASSERT(sizeof(pEvent->payload.error_response.message.arg) >= sizeof(stringSize));
        pEvent->payload.error_response.message.arg = (void*)stringSize;
    }

    if (pPayloadFields)
    {
        protoResult = ProtobufEncode(
            pData + stringSize,
            dataSize - stringSize,
            pPayloadFields,
            HeapletAccess(MEM_OUTBOUND_EVENT_ERROR_RESPONSE_DATA));

        if (!protoResult)
        {
            ACK_DEBUG_PRINT_E("Encoding error response payload failed.");
            retval = ACK_ERR_INTERNAL;
            goto cleanup0;
        }

        ACK_STATIC_ASSERT(
            sizeof(pEvent->payload.error_response.payload.funcs.encode) >= sizeof(pData + stringSize));
        pEvent->payload.error_response.payload.funcs.encode = (ACKNanopbEncodeFunction_t)(pData + stringSize);

        ACK_STATIC_ASSERT(
            sizeof(pEvent->payload.error_response.payload.arg) >= sizeof(dataSize - stringSize));
        pEvent->payload.error_response.payload.arg = (void*)(dataSize - stringSize);
    }

    // Success.
    retval = ACK_NO_ERROR;

cleanup0:
    if (ACK_NO_ERROR != retval)
    {
        EventBuilderEnd();
    }

    return retval;
}

// Encodes from MEM_OUTBOUND_EVENT_ACP_STRUCT, MEM_OUTBOUND_EVENT_PROPERTY_ARRAY, and
// MEM_OUTBOUND_EVENT_ENCODED_PROPERTY_DATA into MEM_OUTBOUND_EVENT_ENCODED_PAYLOAD.
ACKError_t AlexaNamespaceEncodeEventPayload(void)
{
    unsigned i;
    v3avs_capabilities_V3Alexa_Event* pEvent;
    unsigned propertyCount;
    unsigned allocFieldCount;
    unsigned arrayCount;
    ProtobufCallbackField_t* pFields;
    ProtobufEncodeArrayCallbackData_t* pArrayContexts;
    ACKError_t retval;
    PropertyArrayItem_t* pProperties;

    pEvent = (v3avs_capabilities_V3Alexa_Event*)HeapletAccess(MEM_OUTBOUND_EVENT_ACP_STRUCT);

    ACK_ASSERT(0 == (HeapletGetSize(MEM_OUTBOUND_EVENT_PROPERTY_ARRAY) % sizeof(*pProperties)));
    propertyCount = HeapletGetSize(MEM_OUTBOUND_EVENT_PROPERTY_ARRAY) / sizeof(*pProperties);

    ACK_DEBUG_PRINT_D(
        "Encoding Alexa event name %u with %u properties.",
        pEvent->name,
        (unsigned)propertyCount);

    // Fields for encoding error message and payload. We don't always use both (or either), but
    // allocating as if we do simplifies the code below considerably.
    allocFieldCount = (v3avs_capabilities_V3Alexa_Event_error_response_tag == pEvent->which_payload) ? 2 : 0;

    // Property arrays. For a change report, there are both context and payload property arrays.
    // For other events, there's just context.
    arrayCount = (v3avs_capabilities_V3Alexa_Event_change_report_tag == pEvent->which_payload) ? 2 : 1;

    // Allocate space for fields that need custom encoding.
    // Also add space for the callback data for the property array fields.
    pFields = (ProtobufCallbackField_t*)HeapletSetSize(
        MEM_OUTBOUND_EVENT_ENCODING_FIELDS_TEMP,
        (allocFieldCount * sizeof(*pFields)) + (arrayCount * sizeof(*pArrayContexts)));
    if (NULL == pFields)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    pArrayContexts = (ProtobufEncodeArrayCallbackData_t*)(pFields + allocFieldCount);

    // Allocating the encoded event memory should not have changed the address of the event because
    // MEM_OUTBOUND_EVENT_ACP_STRUCT is lower in memory than MEM_OUTBOUND_EVENT_ENCODING_FIELDS_TEMP.
    ACK_ASSERT(HeapletAccess(MEM_OUTBOUND_EVENT_ACP_STRUCT) == pEvent);

    pProperties = (PropertyArrayItem_t*)HeapletAccess(MEM_OUTBOUND_EVENT_PROPERTY_ARRAY);

    // Set up field pointers now that we know MEM_OUTBOUND_EVENT_PROPERTY_ARRAY will be stable.
    for (i = 0; i < propertyCount; ++i)
    {
        pProperties[i].Property.value.arg = &pProperties[i].Field;
    }

    if (v3avs_capabilities_V3Alexa_Event_error_response_tag == pEvent->which_payload)
    {
        if (pEvent->payload.error_response.message.funcs.encode)
        {
            pFields[0].Value = (void*)pEvent->payload.error_response.message.funcs.encode;
            pFields[0].Length = (size_t)pEvent->payload.error_response.message.arg;

            pEvent->payload.error_response.message.funcs.encode = ProtobufEncodeCallbackField;
            pEvent->payload.error_response.message.arg = &pFields[0];
        }

        if (pEvent->payload.error_response.payload.funcs.encode)
        {
            pFields[1].Value = (void*)pEvent->payload.error_response.payload.funcs.encode;
            pFields[1].Length = (size_t)pEvent->payload.error_response.payload.arg;

            pEvent->payload.error_response.payload.funcs.encode = ProtobufEncodeCallbackField;
            pEvent->payload.error_response.payload.arg = &pFields[1];
        }
    }

    // Context.properties field.
    pArrayContexts[0].Data = pProperties;
    pArrayContexts[0].ElementCount = propertyCount;
    pArrayContexts[0].ElementSize = sizeof(*pProperties);

    // No filter: we want all properties in the array. For a change report event, this gets updated below.
    pArrayContexts[0].ElementFilterCallback = NULL;

    pEvent->context.properties.funcs.encode = ProtobufEncodeArrayCallback;
    pEvent->context.properties.arg = &pArrayContexts[0];

    // For change reports we allocated and must fill out an extra array descriptor.
    // Also add a filter for elements in the main context properties array descriptor.
    if (v3avs_capabilities_V3Alexa_Event_change_report_tag == pEvent->which_payload)
    {
        pArrayContexts[1].Data = pProperties;
        pArrayContexts[1].ElementCount = propertyCount;
        pArrayContexts[1].ElementSize = sizeof(*pProperties);
        pArrayContexts[1].ElementFilterCallback = IsChangeReportPayloadProperty_;

        pEvent->payload.change_report.change.properties.funcs.encode = ProtobufEncodeArrayCallback;
        pEvent->payload.change_report.change.properties.arg = &pArrayContexts[1];

        pArrayContexts[0].ElementFilterCallback = IsChangeReportContextProperty_;
    }

    retval = EventBuilderCreateEncodedPayload(v3avs_capabilities_V3Alexa_Event_fields);
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    // Success.
    retval = ACK_NO_ERROR;

cleanup0:
    HeapletFree(MEM_OUTBOUND_EVENT_ENCODING_FIELDS_TEMP);
    return retval;
}

bool IsChangeReportContextProperty_(const void* pData)
{
    return 0 == (((const PropertyArrayItem_t*)pData)->Flags & ACK_PROPERTY_CHANGE_REPORT_PAYLOAD);
}

bool IsChangeReportPayloadProperty_(const void* pData)
{
    return 0 != (((const PropertyArrayItem_t*)pData)->Flags & ACK_PROPERTY_CHANGE_REPORT_PAYLOAD);
}
