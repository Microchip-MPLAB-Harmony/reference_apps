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
#include "ack_core_cooking_common.h"
#include "ack_core_directives.h"
#include "ack_core_event_builder.h"
#include "ack_core_heaplet.h"
#include "ack_core_outbound_events.h"
#include "ack_core_protobuf_utilities.h"
#include "ack_user_config.h"
#include "ack_cooking.h"
#include <inttypes.h>
#include "v3avs_capabilities/V3AlexaCooking.pb.h"
#include "v3avs_capabilities/V3AVS.pb.h"

#ifdef ACK_COOKING

// Forward declarations.
static ACKError_t HandleSetCookingModeDirective_(
    v3avs_capabilities_V3AlexaCooking_SetCookingMode* pDirective);

static ACKError_t SendCookingSessionEventSendWorker_(void);

static ACKError_t StartBuildingCookingErrorResponse_(
    int32_t correlationId,
    v3avs_capabilities_V3AlexaCooking_ErrorResponse_ErrorType type,
    const char* pLogMessage,
    const pb_field_t* pPayloadFields);

static ACKError_t EncodeCookingErrorPayload_(void);

static v3avs_capabilities_V3AlexaCooking_Event* CreateCookingSessionEvent_(
    v3avs_capabilities_V3AlexaCooking_EventName eventName,
    unsigned eventTag);
    
static ACKError_t EncodeSessionEvent_(void);

// Calls user-supplied routine to process the directive.
ACKError_t HandleCookingControllerDirective(void)
{
    v3avs_capabilities_V3AlexaCooking_Directive* pDirective;
    ACKError_t retval;
    bool protoResult;

    pDirective = (v3avs_capabilities_V3AlexaCooking_Directive*)HeapletSetSize(
        MEM_RECEIVED_DIRECTIVE_PAYLOAD,
        sizeof(v3avs_capabilities_V3AlexaCooking_Directive));
    if (NULL == pDirective)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    protoResult = ProtobufDecode(
        HeapletAccess(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        HeapletGetSize(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        v3avs_capabilities_V3AlexaCooking_Directive_fields,
        pDirective);

    if (!protoResult)
    {
        ACK_DEBUG_PRINT_E("Unable to decode cooking controller directive payload.");
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    ACK_REENTRY_SHIELDS_UP;

    switch (pDirective->which_payload)
    {
    case v3avs_capabilities_V3AlexaCooking_Directive_set_cooking_mode_tag:
        ACK_DEBUG_PRINT_I("Processing cooking set mode directive");
        retval = HandleSetCookingModeDirective_(&pDirective->payload.set_cooking_mode);
        break;

    default:
        ACK_DEBUG_PRINT_W("Unhandled cooking directive payload %u", pDirective->which_payload);
        retval = ACK_ERR_PROTOCOL;
        break;
    }

    ACK_REENTRY_SHIELDS_DOWN;

    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    // NOTE! pDirective is now invalid, as processing above can be assumed to have resulted in
    // HeapletSetSize operations.

    retval = ACK_NO_ERROR;

cleanup0:
    HeapletFree(MEM_RECEIVED_DIRECTIVE_PAYLOAD);
    return retval;
}

static ACKError_t HandleSetCookingModeDirective_(v3avs_capabilities_V3AlexaCooking_SetCookingMode* pDirective)
{
    ACKError_t retval;
    ACKCookingDirectiveParams_t* pParams;

    retval = CookingDecodeDirectiveCommon(
        pDirective,
        &pDirective->cooking_mode,
        &pDirective->food_item,
        NULL,
        v3avs_capabilities_V3AlexaCooking_Directive_set_cooking_mode_tag,
        v3avs_capabilities_V3AlexaCooking_SetCookingMode_fields,
        NULL,   // No explicit encoded data, decode from MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD
        0,      // No explicit encoded data
        NULL);  // No pre-allocated ACKCookingDirectiveParams_t
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    // For this directive, the cooking mode is always valid, even if 0 (TIMECOOK).
    // Cooking mode.
    pParams = (ACKCookingDirectiveParams_t*)HeapletAccess(MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA);
    pParams->Flags |= ACK_COOKING_DIRECTIVE_COOKING_MODE_VALID;

    // Call the user-supplied handler.
    ACKUser_OnCookingSetModeDirective(
        ((V3AVS_AvsDirective*)HeapletAccess(MEM_RECEIVED_AVS_DIRECTIVE_ENVELOPE))->correlation_id,
        pParams);

    // Success.
    retval = ACK_NO_ERROR;

cleanup0:
    HeapletFree(MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA);
    return retval;
}

ACKError_t ACK_CompleteDirectiveWithCookingError(
    int32_t correlationId,
    v3avs_capabilities_V3AlexaCooking_ErrorResponse_ErrorType type,
    const char* pOptionalMessage)
{
    ACKError_t retval;

    ACK_DEBUG_PRINT_I(
        "Creating cooking error response event, correlationId %"PRId32", error type %u.",
        correlationId,
        type);

    // More specific routine must be used if one is available.
    if (v3avs_capabilities_V3AlexaCooking_ErrorResponse_ErrorType_COOK_DURATION_TOO_LONG == type)
    {
        ACK_ASSERT(!
            "To report this kind of cooking error, you must call a more specific "
            "ACK_CompleteDirectiveWithCooking*Error routine. See comments in ack_cooking.h.");
    }

    OutboundEventReset();

    retval = StartBuildingCookingErrorResponse_(correlationId, type, pOptionalMessage, NULL);
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    g_pendingOutboundEvent.Flags.Bits.EventPending = true;

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

ACKError_t ACK_CompleteDirectiveWithCookingDurationTooLongError(
    int32_t correlationId,
    uint64_t maxCookDurationMilliseconds,
    const char* pOptionalMessage)
{
    ACKError_t retval;
    v3avs_capabilities_V3AlexaCooking_CookDurationTooLong* pValue;

    ACK_DEBUG_PRINT_I(
        "Starting cooking duration-too-long error response event, correlationId %"PRId32".",
        correlationId);

    OutboundEventReset();

    pValue = (v3avs_capabilities_V3AlexaCooking_CookDurationTooLong*)HeapletSetSize(
        MEM_OUTBOUND_EVENT_ERROR_RESPONSE_DATA,
        sizeof(*pValue));
    if (NULL == pValue)
    {
        ACK_DEBUG_PRINT_E("Unable to allocate memory for cooking error payload.");
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    pValue->maxCookTime.value = maxCookDurationMilliseconds;

    retval = StartBuildingCookingErrorResponse_(
        correlationId,
        v3avs_capabilities_V3AlexaCooking_ErrorResponse_ErrorType_COOK_DURATION_TOO_LONG,
        pOptionalMessage,
        v3avs_capabilities_V3AlexaCooking_CookDurationTooLong_fields);
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    g_pendingOutboundEvent.Flags.Bits.EventPending = true;

    retval = OutboundEventSendIfNotProcessingInboundEvent();
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    // Success.
    retval = ACK_NO_ERROR;

cleanup0:
    HeapletFree(MEM_OUTBOUND_EVENT_ERROR_RESPONSE_DATA);

    if (ACK_NO_ERROR != retval)
    {
        EventBuilderEnd();
    }

    return retval;
}

ACKError_t ACK_SendCookingSessionCompletedEvent(uint64_t timeOfCompletion)
{
    ACKError_t retval;
    v3avs_capabilities_V3AlexaCooking_Event* pEvent;

    ACK_DEBUG_PRINT_I("Starting cooking session completed event.");

    ACK_REENTRY_CHECK;

    OutboundEventReset();

    pEvent = CreateCookingSessionEvent_(
        v3avs_capabilities_V3AlexaCooking_EventName_COOKING_SESSION_COMPLETED,
        v3avs_capabilities_V3AlexaCooking_Event_cooking_session_completed_tag);
    if (NULL == pEvent)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    pEvent->payload.cooking_session_completed.time_of_completion.value = timeOfCompletion;

    retval = SendCookingSessionEventSendWorker_();
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    // Success.
    retval = ACK_NO_ERROR;

cleanup0:
    EventBuilderEnd();
    return retval;
}

ACKError_t ACK_SendCookingSessionInteractionEvent(v3avs_types_V3RequiredInteraction_Value postStepInteraction)
{
    ACKError_t retval;
    v3avs_capabilities_V3AlexaCooking_Event* pEvent;

    ACK_DEBUG_PRINT_I("Starting cooking session interaction event.");

    ACK_REENTRY_CHECK;

    OutboundEventReset();

    pEvent = CreateCookingSessionEvent_(
        v3avs_capabilities_V3AlexaCooking_EventName_COOKING_SESSION_INTERACTION,
        v3avs_capabilities_V3AlexaCooking_Event_cooking_session_interaction_tag);
    if (NULL == pEvent)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    pEvent->payload.cooking_session_interaction.required_interaction.value = postStepInteraction;

    retval = SendCookingSessionEventSendWorker_();
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    // Success.
    retval = ACK_NO_ERROR;

cleanup0:
    EventBuilderEnd();
    return retval;
}

ACKError_t ACK_SendCookingDeviceStateChangeEvent(v3avs_types_V3DeviceState_Value deviceState)
{
    ACKError_t retval;
    v3avs_capabilities_V3AlexaCooking_Event* pEvent;

    ACK_DEBUG_PRINT_I("Starting cooking device state change event.");

    ACK_REENTRY_CHECK;

    OutboundEventReset();

    pEvent = CreateCookingSessionEvent_(
        v3avs_capabilities_V3AlexaCooking_EventName_DEVICE_STATE_CHANGE,
        v3avs_capabilities_V3AlexaCooking_Event_cooking_device_state_change_tag);
    if (NULL == pEvent)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    pEvent->payload.cooking_device_state_change.device_state.value = deviceState;

    retval = SendCookingSessionEventSendWorker_();
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    // Success.
    retval = ACK_NO_ERROR;

cleanup0:
    EventBuilderEnd();
    return retval;
}

static ACKError_t SendCookingSessionEventSendWorker_(void)
{
    ACKError_t retval;

    g_pendingOutboundEvent.Flags.Bits.EventPending = true;

    retval = OutboundEventSend();
    if (ACK_NO_ERROR != retval)
    {
        ACK_DEBUG_PRINT_E("Error %u sending cooking session event.", retval);
    }

    return retval;
}

ACKError_t ACK_AddCookingModeProperty(
    const ACKStateCommon_t* pCommon,
    v3avs_types_V3CookingMode_Value mode,
    const char* pCustomModeName)
{
    v3avs_capabilities_V3AlexaCooking_CookingModeProperty property;
    ProtobufCallbackField_t field = {0};

    // Check that name is specified if any only if the mode is custom.
    ACK_ASSERT((v3avs_types_V3CookingMode_Value_CUSTOM == mode) == (NULL != pCustomModeName));

    ACK_REENTRY_CHECK;

    property.cooking_mode.value = mode;

    if (pCustomModeName)
    {
        field.Value = (const uint8_t*)pCustomModeName;
        field.Length = strlen(pCustomModeName);

        property.cooking_mode.custom_name.funcs.encode = ProtobufEncodeCallbackField;
        property.cooking_mode.custom_name.arg = &field;
    }
    else
    {
        property.cooking_mode.custom_name.funcs.encode = NULL;
        property.cooking_mode.custom_name.arg = NULL;
    }

    return CommonEncodeContextProperty(
        V3AVS_Namespace_V3_ALEXA_COOKING_CONTROLLER,
        v3avs_capabilities_V3AlexaCooking_PropertyName_COOKING_MODE_PROP,
        0, // instance not used for this controller
        pCommon,
        v3avs_capabilities_V3AlexaCooking_CookingModeProperty_fields,
        &property);
}

ACKError_t ACK_AddCookingTimeIntervalProperty(
    const ACKStateCommon_t* pCommon,
    uint64_t startTime, // epoch ms
    uint64_t endTime,
    uint64_t durationMilliseconds)
{
    v3avs_capabilities_V3AlexaCooking_CookingTimeIntervalProperty property;

    ACK_REENTRY_CHECK;

    property.cooking_time_interval.start.value = startTime;
    property.cooking_time_interval.end.value = endTime;
    property.cooking_time_interval.duration.value = durationMilliseconds;

    return CommonEncodeContextProperty(
        V3AVS_Namespace_V3_ALEXA_COOKING_CONTROLLER,
        v3avs_capabilities_V3AlexaCooking_PropertyName_COOKING_TIME_INTERVAL_PROP,
        0, // instance not used for this controller
        pCommon,
        v3avs_capabilities_V3AlexaCooking_CookingTimeIntervalProperty_fields,
        &property);
}

ACKError_t ACK_AddFoodItemProperty(
    const ACKStateCommon_t* pCommon,
    const char* pFoodName,
    const ACKItemQuantity_t* pFoodQuantity)
{
    v3avs_capabilities_V3AlexaCooking_FoodItemProperty property;
    memset(&property, 0, sizeof(property));

    ProtobufCallbackField_t field = {0};
    ACKError_t retval;

    ACK_REENTRY_CHECK;

    if (!CommonConvertItemQuantityToProtobuf(pFoodQuantity, &property.food_item.food_quantity))
    {
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    if (pFoodName)
    {
        field.Value = (const uint8_t*)pFoodName;
        field.Length = strlen(pFoodName);
        property.food_item.food_name.funcs.encode = ProtobufEncodeCallbackField;
        property.food_item.food_name.arg = &field;
    }
    else
    {
        property.food_item.food_name.funcs.encode = NULL;
        property.food_item.food_name.arg = NULL;
    }

    retval = CommonEncodeContextProperty(
        V3AVS_Namespace_V3_ALEXA_COOKING_CONTROLLER,
        v3avs_capabilities_V3AlexaCooking_PropertyName_FOOD_ITEM_PROP,
        0, // instance not used for this controller
        pCommon,
        v3avs_capabilities_V3AlexaCooking_FoodItemProperty_fields,
        &property);

cleanup0:
    return retval;
}

// Struct to be encoded is in MEM_OUTBOUND_EVENT_ERROR_RESPONSE_DATA.
ACKError_t StartBuildingCookingErrorResponse_(
    int32_t correlationId,
    v3avs_capabilities_V3AlexaCooking_ErrorResponse_ErrorType type,
    const char* pLogMessage,
    const pb_field_t* pPayloadFields)
{
    v3avs_capabilities_V3AlexaCooking_Event* pEvent;
    size_t dataSize;
    uint8_t* pData;
    size_t stringSize;
    ACKError_t retval;
    bool protoResult;

    EventBuilderStart(
        correlationId,
        V3AVS_Namespace_V3_ALEXA_COOKING_CONTROLLER,
        0, // instance not used for this namespace
        EncodeCookingErrorPayload_,
        EVENT_FLAG_CAN_HAVE_PROPERTIES);

    pEvent = (v3avs_capabilities_V3AlexaCooking_Event*)HeapletSetSize(
        MEM_OUTBOUND_EVENT_ACP_STRUCT,
        sizeof(v3avs_capabilities_V3AlexaCooking_Event));
    if (NULL == pEvent)
    {
        ACK_DEBUG_PRINT_E("Unable to allocate memory for cooking error response struct.");
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    // v3avs_capabilities_V3Alexa_CookingEvent_init_default exists, but instead of bloating up the image
    // with default structs, just zero out here instead.
    memset(pEvent, 0, sizeof(*pEvent));

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
        ACK_DEBUG_PRINT_E("Unable to allocate memory for cooking error response data.");
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    // A data structure representing the event was already created, when the user called
    // CookingStartErrorResponseEvent et al, before those routines call this one.
    pEvent = (v3avs_capabilities_V3AlexaCooking_Event*)HeapletAccess(MEM_OUTBOUND_EVENT_ACP_STRUCT);
    pEvent->name = v3avs_capabilities_V3AlexaCooking_EventName_ERROR_RESPONSE;
    pEvent->which_payload = v3avs_capabilities_V3AlexaCooking_Event_error_response_tag;
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

static v3avs_capabilities_V3AlexaCooking_Event* CreateCookingSessionEvent_(
    v3avs_capabilities_V3AlexaCooking_EventName eventName,
    unsigned eventTag)
{
    v3avs_capabilities_V3AlexaCooking_Event* pEvent = NULL;

    EventBuilderStart(
        0, // no correlation id
        V3AVS_Namespace_V3_ALEXA_COOKING_CONTROLLER,
        0, // instance id not used for this capability
        EncodeSessionEvent_,
        EVENT_FLAGS_NONE);

    pEvent = (v3avs_capabilities_V3AlexaCooking_Event*)HeapletSetSize(
        MEM_OUTBOUND_EVENT_ACP_STRUCT,
        sizeof(v3avs_capabilities_V3AlexaCooking_Event));

    if (NULL == pEvent)
    {
        ACK_DEBUG_PRINT_E("Unable to allocate memory for cooking session event.");
        goto cleanup0;
    }

    memset(pEvent, 0, sizeof(*pEvent));
    pEvent->name = eventName;
    pEvent->which_payload = eventTag;

cleanup0:
    if (NULL == pEvent)
    {
        EventBuilderEnd();
    }

    return pEvent;
}

// Encodes from MEM_OUTBOUND_EVENT_ACP_STRUCT into MEM_OUTBOUND_EVENT_ENCODED_PAYLOAD.
ACKError_t EncodeCookingErrorPayload_(void)
{
    v3avs_capabilities_V3AlexaCooking_Event* pEvent;
    ProtobufCallbackField_t* pField;
    ACKError_t retval;

    pEvent = (v3avs_capabilities_V3AlexaCooking_Event*)HeapletAccess(MEM_OUTBOUND_EVENT_ACP_STRUCT);

    // We're not expecting any cooking error to include properties.
    ACK_ASSERT(0 == HeapletGetSize(MEM_OUTBOUND_EVENT_PROPERTY_ARRAY));

    ACK_DEBUG_PRINT_D("Encoding cooking error event, name %u.", pEvent->name);

    // Allocate space for custom encoding log message string and error response payload.
    // We don't always use both (or either), but allocating as if we do makes the logic easier to follow.
    // Also add space for the callback data for the Context.properties field.
    pField = (ProtobufCallbackField_t*)HeapletSetSize(
        MEM_OUTBOUND_EVENT_ENCODING_FIELDS_TEMP,
        2 * sizeof(ProtobufCallbackField_t));
    if (NULL == pField)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    // Allocating the encoded event memory should not have changed the address of the event because
    // MEM_OUTBOUND_EVENT_ACP_STRUCT is lower in memory than MEM_OUTBOUND_EVENT_ENCODING_FIELDS_TEMP.
    ACK_ASSERT(HeapletAccess(MEM_OUTBOUND_EVENT_ACP_STRUCT) == pEvent);

    // For cooking, when we get here we're always encoding an error response, but we may or may not
    // have a textual message and a payload to include.
    if (pEvent->payload.error_response.message.funcs.encode)
    {
        pField->Value = (void*)pEvent->payload.error_response.message.funcs.encode;
        pField->Length = (size_t)pEvent->payload.error_response.message.arg;

        pEvent->payload.error_response.message.funcs.encode = ProtobufEncodeCallbackField;
        pEvent->payload.error_response.message.arg = pField;

        ++pField;
    }

    if (pEvent->payload.error_response.payload.funcs.encode)
    {
        pField->Value = (void*)pEvent->payload.error_response.payload.funcs.encode;
        pField->Length = (size_t)pEvent->payload.error_response.payload.arg;

        pEvent->payload.error_response.payload.funcs.encode = ProtobufEncodeCallbackField;
        pEvent->payload.error_response.payload.arg = pField;

        ++pField;
    }

    retval = EventBuilderCreateEncodedPayload(v3avs_capabilities_V3AlexaCooking_Event_fields);
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

// Called back from within ACK_SendEvent.
static ACKError_t EncodeSessionEvent_(void)
{
    return EventBuilderCreateEncodedPayload(v3avs_capabilities_V3AlexaCooking_Event_fields);
}

#endif // def ACK_COOKING
