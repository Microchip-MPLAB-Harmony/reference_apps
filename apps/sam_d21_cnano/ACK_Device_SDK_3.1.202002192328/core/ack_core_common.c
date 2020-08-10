/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#include "acp.pb.h"
#include "ack.h"
#include "ack_core_common.h"
#include "ack_core_communication.h"
#include "ack_core_event_builder.h"
#include "ack_core_heaplet.h"
#include "ack_core_protobuf_utilities.h"
#include <inttypes.h>
#include "v3avs_capabilities/V3Alexa.pb.h"

#ifdef ACK_ENABLE_ASSERT

volatile bool g_reentryGuardActive = false;

#endif

// Forward references.
static ACKError_t SendAcpCmdAndGetResponse_(
    HeapletTag_t outboundAcpCmdTag,
    HeapletTag_t receivedEncodedAcpResponseTag,
    HeapletTag_t receivedDecodedAcpResponseTag,
    void (*pCleanupRoutine)(void));

static bool CheckGenericResponse_(HeapletTag_t tag);

// Called by directive-specific processing routines.
// Expects to augment MEM_OUTBOUND_EVENT_PROPERTY_ARRAY and MEM_OUTBOUND_EVENT_ENCODED_PROPERTY_DATA.
ACKError_t CommonEncodeContextProperty(
    V3AVS_Namespace v3Namespace,
    uint32_t propertyName,
    uint32_t instance,
    const ACKStateCommon_t* pCommon,
    const pb_field_t* pPropertyFields,
    const void* pPropertyValue)
{
    ACKError_t retval;
    size_t encodedSize;
    size_t existingSize;
    size_t originalSize;
    void* pEncodedData;
    PropertyArrayItem_t* pProperty;
    uint64_t epochTime;

    ACK_CHECK_CAN_ADD_PROPERTY_TO_EVENT(0 != (pCommon->Flags & ACK_PROPERTY_CHANGE_REPORT_PAYLOAD));

    // Determine the property's encoded size and allocate space for the encoded data in
    // MEM_OUTBOUND_EVENT_ENCODED_PROPERTY_DATA.
    encodedSize = ProtobufGetEncodedSize(pPropertyFields, pPropertyValue);
    existingSize = HeapletGetSize(MEM_OUTBOUND_EVENT_ENCODED_PROPERTY_DATA);
    originalSize = existingSize;

    pEncodedData = HeapletSetSize(MEM_OUTBOUND_EVENT_ENCODED_PROPERTY_DATA, existingSize + encodedSize);
    if (NULL == pEncodedData)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    pEncodedData = (uint8_t*)pEncodedData + existingSize;

    if (!ProtobufEncode(pEncodedData, encodedSize, pPropertyFields, pPropertyValue))
    {
        ACK_DEBUG_PRINT_E("Unable to encode property.");
        retval = ACK_ERR_INTERNAL;
        goto cleanup0;
    }

    // Maintain an array of structures describing the encoded properties, in
    // MEM_OUTBOUND_EVENT_PROPERTY_ARRAY.
    // Grow that memory block to be able to hold another property.
    existingSize = HeapletGetSize(MEM_OUTBOUND_EVENT_PROPERTY_ARRAY);
    ACK_ASSERT(0 == (existingSize % sizeof(*pProperty)));

    pProperty = (PropertyArrayItem_t*)HeapletSetSize(
        MEM_OUTBOUND_EVENT_PROPERTY_ARRAY,
        existingSize + sizeof(*pProperty));
    if (NULL == pProperty)
    {
        ACK_DEBUG_PRINT_E("Out of memory trying trying to grow property array.");
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    pProperty += existingSize / sizeof(*pProperty);
    pProperty->Property.v3_namespace = v3Namespace;
    pProperty->Property.name = propertyName;
    pProperty->Property.instance = instance;
    pProperty->Property.uncertainty_in_milliseconds = pCommon->UncertaintyMilliseconds;

    if (pCommon->TimeOfSample >= ACK_MINIMUM_PROPERTY_TIMESTAMP)
    {
        pProperty->Property.time_of_sample = pCommon->TimeOfSample;
    }
    else
    {
        epochTime = ACK_GetApproximateTime();
        pProperty->Property.time_of_sample = epochTime ? epochTime : ACK_MINIMUM_PROPERTY_TIMESTAMP;
    }

    // Set up the field for later encoding, but don't assign the pointers in pProperty->Property.value yet,
    // because MEM_OUTBOUND_EVENT_PROPERTY_ARRAY will move around in memory as the event is being built up.
    pProperty->Field.Value = (const uint8_t*)pEncodedData;
    pProperty->Field.Length = encodedSize;
    pProperty->Property.value.funcs.encode = ProtobufEncodeCallbackField;
#ifdef ACK_ENABLE_ASSERT
    pProperty->Property.value.arg = NULL;
#endif

    pProperty->Flags = pCommon->Flags;

    retval = ACK_NO_ERROR;

cleanup0:
    if (ACK_NO_ERROR != retval)
    {
        HeapletSetSize(MEM_OUTBOUND_EVENT_ENCODED_PROPERTY_DATA, originalSize);
    }

    return retval;
}

// Encodes and sends an acp_cmd, receives a response, and
//  * Returns it in MEM_RECEIVED_ENCODED_ACP_RESPONSE
//  * Decodes it to MEM_RECEIVED_ACP_RESPONSE
// Both the encoded and decoded forms may be needed for subsequent steps; for example the encoded form
// is still needed if there's a payload to decode.
ACKError_t CommonAllocAndSendAcpCmdAndGetAcpResponse(pb_size_t whichType)
{
    acp_cmd* pCmd;
    ACKError_t retval;

    pCmd = (acp_cmd*)HeapletSetSize(MEM_OUTBOUND_ACP_CMD, sizeof(*pCmd));
    if (NULL == pCmd)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    pCmd->which_type = whichType;

    retval = CommonSendAcpCmdAndGetResponse();

cleanup0:
    // OK to free if never allocated or already freed.
    HeapletFree(MEM_OUTBOUND_ACP_CMD);
    return retval;
}

// Encodes and sends the acp_cmd currently in MEM_OUTBOUND_ACP_CMD, receives a response, and
//  * Returns it in MEM_RECEIVED_ENCODED_ACP_RESPONSE
//  * Decodes it into MEM_RECEIVED_ACP_RESPONSE
// Both the encoded and decoded forms may be needed for subsequent steps; for example the encoded form
// is still needed if there's a payload to decode.
ACKError_t CommonSendAcpCmdAndGetResponse(void)
{
    return SendAcpCmdAndGetResponse_(
        MEM_OUTBOUND_ACP_CMD,
        MEM_RECEIVED_ENCODED_ACP_RESPONSE,
        MEM_RECEIVED_ACP_RESPONSE,
        CommonFreeAcpResponse);
}

// Encodes and sends the acp_cmd currently in MEM_ALT_OUTBOUND_ACP_CMD, receives a response, and
//  * Returns it in MEM_ALT_RECEIVED_ENCODED_ACP_RESPONSE
//  * Decodes it into MEM_ALT_RECEIVED_ACP_RESPONSE
// Both the encoded and decoded forms may be needed for subsequent steps; for example the encoded form
// is still needed if there's a payload to decode.
ACKError_t CommonSendAcpCmdAndGetResponseAltHeapletBlocks(void)
{
    return SendAcpCmdAndGetResponse_(
        MEM_ALT_OUTBOUND_ACP_CMD,
        MEM_ALT_RECEIVED_ENCODED_ACP_RESPONSE,
        MEM_ALT_RECEIVED_ACP_RESPONSE,
        CommonFreeAcpResponseAltHeapletBlocks);
}

static ACKError_t SendAcpCmdAndGetResponse_(
    HeapletTag_t outboundAcpCmdTag,
    HeapletTag_t receivedEncodedAcpResponseTag,
    HeapletTag_t receivedDecodedAcpResponseTag,
    void (*pCleanupRoutine)(void))
{
    acp_cmd* pCmd;
    acp_response* pResponse;
    size_t encodedSize;
    void* pEncoded;
    ACKError_t retval;
    bool protoResult;

    // Put the acp_cmd and its encoded form in a single memory block.
    // Determine how large the encoded form will be, and resize the block to accomodate the encoded form
    // as well as the acp_cmd that's in there now.
    pCmd = (acp_cmd*)HeapletAccess(outboundAcpCmdTag);
    encodedSize = ProtobufGetEncodedSize(acp_cmd_fields, pCmd);

    pCmd = (acp_cmd*)HeapletSetSize(outboundAcpCmdTag, sizeof(*pCmd) + encodedSize);
    if (NULL == pCmd)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    pEncoded = pCmd + 1;

    protoResult = ProtobufEncode(pEncoded, encodedSize, acp_cmd_fields, pCmd);
    if (!protoResult)
    {
        ACK_DEBUG_PRINT_E("Unable to encode acp_cmd.");
        retval = ACK_ERR_INTERNAL;
        goto cleanup0;
    }

    // Drain the receive buffer before sending out a request
    ACKPlatform_DrainRead();

    // Send out the encoded data.
    retval = CommsSendAcpProtobufCmd(pEncoded, encodedSize);
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    // Read the response into receivedEncodedAcpResponseTag.
    retval = CommsGetAcpResponse(receivedEncodedAcpResponseTag);
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    // Decode the received acp_response.
    pResponse = (acp_response*)HeapletSetSize(receivedDecodedAcpResponseTag, sizeof(acp_response));
    if (NULL == pResponse)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    protoResult = ProtobufDecode(
        HeapletAccess(receivedEncodedAcpResponseTag),
        HeapletGetSize(receivedEncodedAcpResponseTag),
        acp_response_fields,
        pResponse);

    if (!protoResult)
    {
        ACK_DEBUG_PRINT_E("Unable to decode acp_response.");
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    retval = ACK_NO_ERROR;

cleanup0:
    if (ACK_NO_ERROR != retval)
    {
        pCleanupRoutine();
    }

    return retval;
}

// Frees memory associated with the acp_response to an acp_cmd we sent out in CommonSendAcpCmdAndGetResponse.
// Call after state processing has advanced sufficiently that the original acp_response is no longer needed.
void CommonFreeAcpResponse(void)
{
    // HeapletFree is OK to call if a block was already freed or was never allocated.
    HeapletFree(MEM_RECEIVED_ENCODED_ACP_RESPONSE);
    HeapletFree(MEM_RECEIVED_ACP_RESPONSE);
}

// Frees memory associated with the acp_response to an acp_cmd we sent out in
// CommonSendAcpCmdAndGetResponseAltHeapletBlocks.
// Call after state processing has advanced sufficiently that the original acp_response is no longer needed.
void CommonFreeAcpResponseAltHeapletBlocks(void)
{
    // HeapletFree is OK to call if a block was already freed or was never allocated.
    HeapletFree(MEM_ALT_RECEIVED_ENCODED_ACP_RESPONSE);
    HeapletFree(MEM_ALT_RECEIVED_ACP_RESPONSE);
}

// Checks MEM_RECEIVED_ACP_RESPONSE to ensure it's a generic response.
bool CommonCheckGenericResponse(void)
{
    return CheckGenericResponse_(MEM_RECEIVED_ACP_RESPONSE);
}

bool CommonCheckGenericResponseAltHeapletBlocks(void)
{
    return CheckGenericResponse_(MEM_ALT_RECEIVED_ACP_RESPONSE);
}

static bool CheckGenericResponse_(HeapletTag_t tag)
{
    acp_response* pResponse = (acp_response*)HeapletAccess(tag);

    if (acp_response_generic_obj_tag != pResponse->which_type)
    {
        ACK_DEBUG_PRINT_E("Expected generic response; got %u.", pResponse->which_type);
        return false;
    }

    if (acp_response_generic_error_no_error != pResponse->type.generic_obj.code)
    {
        ACK_DEBUG_PRINT_E("Generic response indicates error %u.", pResponse->type.generic_obj.code);
        return false;
    }

    ACK_DEBUG_PRINT_I("Got generic response indicating no error.");
    return true;
}

bool CommonConvertItemQuantityFromProtobuf(
    const v3avs_types_V3ItemQuantity* pSourceQuantity,
    ACKItemQuantity_t* pTargetQuantity)
{
    switch (pSourceQuantity->which_payload)
    {
    case v3avs_types_V3ItemQuantity_count_tag:
        pTargetQuantity->UnitType = ACK_ITEM_QUANTITY_COUNT;
        pTargetQuantity->Unit.Size = pSourceQuantity->payload.count.size;
        pTargetQuantity->Quantity = pSourceQuantity->payload.count.value;
        break;
    case v3avs_types_V3ItemQuantity_volume_tag:
        pTargetQuantity->UnitType = ACK_ITEM_QUANTITY_VOLUME;
        pTargetQuantity->Unit.VolumeUnit = pSourceQuantity->payload.volume.unit;
        pTargetQuantity->Quantity = pSourceQuantity->payload.volume.value;
        break;
    case v3avs_types_V3ItemQuantity_weight_tag:
        pTargetQuantity->UnitType = ACK_ITEM_QUANTITY_WEIGHT;
        pTargetQuantity->Unit.WeightUnit = pSourceQuantity->payload.weight.unit;
        pTargetQuantity->Quantity = pSourceQuantity->payload.weight.value;
        break;
    default:
        ACK_DEBUG_PRINT_W("Unknown protobuf item quantity tag %u", pSourceQuantity->which_payload);
        return false;
    }

    return true;
}

bool CommonConvertItemQuantityToProtobuf(
    const ACKItemQuantity_t* pSourceQuantity,
    v3avs_types_V3ItemQuantity* pTargetQuantity)
{
    switch (pSourceQuantity->UnitType)
    {
    case ACK_ITEM_QUANTITY_COUNT:
        pTargetQuantity->quantity_type = v3avs_types_V3ItemQuantity_QuantityType_COUNT;
        pTargetQuantity->which_payload = v3avs_types_V3ItemQuantity_count_tag;
        pTargetQuantity->payload.count.size = pSourceQuantity->Unit.Size;
        pTargetQuantity->payload.count.value = pSourceQuantity->Quantity;
        break;
    case ACK_ITEM_QUANTITY_VOLUME:
        pTargetQuantity->quantity_type = v3avs_types_V3ItemQuantity_QuantityType_VOLUME;
        pTargetQuantity->which_payload = v3avs_types_V3ItemQuantity_volume_tag;
        pTargetQuantity->payload.volume.unit = pSourceQuantity->Unit.VolumeUnit;
        pTargetQuantity->payload.volume.value = pSourceQuantity->Quantity;
        break;
    case ACK_ITEM_QUANTITY_WEIGHT:
        pTargetQuantity->quantity_type = v3avs_types_V3ItemQuantity_QuantityType_WEIGHT;
        pTargetQuantity->which_payload = v3avs_types_V3ItemQuantity_weight_tag;
        pTargetQuantity->payload.weight.unit = pSourceQuantity->Unit.WeightUnit;
        pTargetQuantity->payload.weight.value = pSourceQuantity->Quantity;
        break;
    default:
        ACK_DEBUG_PRINT_W("Unknown item quantity %u", pSourceQuantity->UnitType);
        return false;
    }

    return true;
}

#ifdef ACK_ENABLE_ASSERT

void (*ACK_AssertionFailedHook)(void);

void ACK_AssertionFailed(const char* pCondition)
{
#ifndef ACK_DEBUG_PRINT_LEVEL
#error ACK_ENABLE_ASSERT requires debug print be enabled but ACK_DEBUG_PRINT_LEVEL is not defined
#endif
    ACK_DEBUG_PRINT_C("***** ASSERTION FAILED: %s.", pCondition);

    if (ACK_AssertionFailedHook)
    {
        ACK_AssertionFailedHook();
        return;
    }

spin:
    goto spin;
}

#endif // ACK_ENABLE_ASSERT
