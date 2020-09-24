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
#include "ack_core_heaplet.h"
#include "ack_module_diagnostics.h"
#include "acp.pb.h"
#include "pb_decode.h"

// Forward references.
static ACKError_t CreateAndSendProvisioningCommand_(uint32_t submessageTag);
static bool SkipToEncodedResponsePayload_(uint32_t tag1, uint32_t optionalTag2, size_t *pOffset);

// Retrieves device type info from the connectivity module.
ACKError_t ACK_GetDeviceType(char* pDeviceType, size_t deviceTypeBufferSize)
{
    size_t encodedPayloadOffset;
    ACKError_t retval;
    acp_response* pResponse;
    bool protoResult;
    ProtobufCallbackField_t deviceTypeField = {0};

    ACK_DEBUG_PRINT_I("Sending get-device-type command.");

    ACK_REENTRY_CHECK;

    retval = CreateAndSendProvisioningCommand_(acp_cmd_provisioning_get_device_type_obj_tag);
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    // Try to skip to the encoded payload for the get-device-type response. If we can't, then
    // we got back an unexpected or corrupted response.
    if (!SkipToEncodedResponsePayload_(
        acp_response_provisioning_obj_tag,
        acp_response_provisioning_device_type_obj_tag,
        &encodedPayloadOffset))
    {
        ACK_DEBUG_PRINT_E("Incorrect response to get-device-type diagnostic command.");
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    pResponse = (acp_response*)HeapletAccess(MEM_RECEIVED_ACP_RESPONSE);
    pResponse->type.provisioning_obj.response.device_type_obj.device_type.arg = &deviceTypeField;
    pResponse->type.provisioning_obj.response.device_type_obj.device_type.funcs.decode
        = ProtobufDecodeCallbackField;

    protoResult = ProtobufDecode(
        (uint8_t*)HeapletAccess(MEM_RECEIVED_ENCODED_ACP_RESPONSE) + encodedPayloadOffset,
        HeapletGetSize(MEM_RECEIVED_ENCODED_ACP_RESPONSE) - encodedPayloadOffset,
        acp_response_provisioning_device_type_fields,
        &pResponse->type.provisioning_obj.response.device_type_obj);
    if (!protoResult)
    {
        ACK_DEBUG_PRINT_E("Unable to decode get-manufacturing-info diagnostic command result.");
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    // Not much point in calling this function if we can't at least get a terminating nul in there.
    ACK_ASSERT(0 != deviceTypeBufferSize);
    if (deviceTypeField.Length >= deviceTypeBufferSize)
    {
        deviceTypeField.Length = deviceTypeBufferSize - 1;
    }

    memcpy(pDeviceType, deviceTypeField.Value, deviceTypeField.Length);
    pDeviceType[deviceTypeField.Length] = 0;

    retval = ACK_NO_ERROR;

cleanup0:
    CommonFreeAcpResponse();
    return retval;
}

#ifdef ACK_MODULE_DIAGNOSTICS

// Retrieves provisioning info from the connectivity module.
ACKError_t ACK_GetProvisioningInfo(acp_response_provisioning_provisioning_state* pState)
{
    size_t encodedPayloadOffset;
    ACKError_t retval;
    acp_response* pResponse;

    ACK_DEBUG_PRINT_I("Sending get-provisioning-info command.");

    ACK_REENTRY_CHECK;

    retval = CreateAndSendProvisioningCommand_(acp_cmd_provisioning_get_provisioning_state_obj_tag);
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    // Try to skip to the encoded payload for the get-device-type response. If we can't, then
    // we got back an unexpected or corrupted response.
    if (!SkipToEncodedResponsePayload_(
        acp_response_provisioning_obj_tag,
        acp_response_provisioning_provisioning_info_obj_tag,
        &encodedPayloadOffset))
    {
        ACK_DEBUG_PRINT_E("Incorrect response to get-provisioning-info diagnostic command.");
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    pResponse = (acp_response*)HeapletAccess(MEM_RECEIVED_ACP_RESPONSE);

    *pState = pResponse->type.provisioning_obj.response.provisioning_info_obj.state;

    retval = ACK_NO_ERROR;

cleanup0:
    CommonFreeAcpResponse();
    return retval;
}

// Retrieves hardware info from the connectivity module.
ACKError_t ACK_GetHardwareInfo(char* pDsn, size_t dsnBufferSize)
{
    size_t encodedPayloadOffset;
    ACKError_t retval;
    acp_response* pResponse;
    ProtobufCallbackField_t dsnField = {0};
    bool protoResult;

    ACK_DEBUG_PRINT_I("Sending get-hardware-info command.");

    ACK_REENTRY_CHECK;

    retval = CommonAllocAndSendAcpCmdAndGetAcpResponse(acp_cmd_get_ack_hardware_info_obj_tag);
    if (ACK_NO_ERROR != retval)
    {
        ACK_DEBUG_PRINT_E("Unable to send get-hardware-info command; err %u.", retval);
        goto cleanup0;
    }

    // Try to skip to the encoded payload for the get-hardware-info response. If we can't, then
    // we got back an unexpected or corrupted response.
    if (!SkipToEncodedResponsePayload_(
        acp_response_get_ack_hardware_info_obj_tag,
        0,
        &encodedPayloadOffset))
    {
        ACK_DEBUG_PRINT_E("Incorrect response to get-hardware-info diagnostic command.");
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    pResponse = (acp_response*)HeapletAccess(MEM_RECEIVED_ACP_RESPONSE);
    pResponse->type.get_ack_hardware_info_obj.dsn.arg = &dsnField;
    pResponse->type.get_ack_hardware_info_obj.dsn.funcs.decode = ProtobufDecodeCallbackField;

    protoResult = ProtobufDecode(
        (uint8_t*)HeapletAccess(MEM_RECEIVED_ENCODED_ACP_RESPONSE) + encodedPayloadOffset,
        HeapletGetSize(MEM_RECEIVED_ENCODED_ACP_RESPONSE) - encodedPayloadOffset,
        acp_response_get_ack_hardware_info_fields,
        &pResponse->type.get_ack_hardware_info_obj);
    if (!protoResult)
    {
        ACK_DEBUG_PRINT_E("Unable to decode get-hardware-info diagnostic command result.");
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    // Not much point in calling this function if the DSN buffer can't get anything written
    // into it (at least one character and a nul terminator).
    ACK_ASSERT(dsnBufferSize > 1);
    if (dsnField.Length >= dsnBufferSize)
    {
        dsnField.Length = dsnBufferSize - 1;
    }

    memcpy(pDsn, dsnField.Value, dsnField.Length);
    pDsn[dsnField.Length] = 0;

    retval = ACK_NO_ERROR;

cleanup0:
    CommonFreeAcpResponse();
    return retval;
}

// Retrieves firmware version info from the connectivity module.
ACKError_t ACK_GetFirmwareVersion(
    uint32_t* pProtocolNumber,
    uint32_t* pBuildNumber,
    char* pIncrementalVersion,
    size_t incrementalVersionBufferSize)
{
    size_t encodedPayloadOffset;
    ACKError_t retval;
    acp_response* pResponse;
    ProtobufCallbackField_t incrementalVersionField = {0};
    bool protoResult;

    ACK_DEBUG_PRINT_I("Sending get-firmware-version command.");

    ACK_REENTRY_CHECK;

    retval = CommonAllocAndSendAcpCmdAndGetAcpResponse(acp_cmd_get_firmware_version_obj_tag);
    if (ACK_NO_ERROR != retval)
    {
        ACK_DEBUG_PRINT_E("Unable to send get-firmware-version; err %u.", retval);
        goto cleanup0;
    }

    // Try to skip to the encoded payload for the get-firmware-version response. If we can't, then
    // we got back an unexpected or corrupted response.
    if (!SkipToEncodedResponsePayload_(
        acp_response_get_firmware_version_obj_tag,
        0,
        &encodedPayloadOffset))
    {
        ACK_DEBUG_PRINT_E("Incorrect response to get-firmware-version diagnostic command.");
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    pResponse = (acp_response*)HeapletAccess(MEM_RECEIVED_ACP_RESPONSE);
    pResponse->type.get_firmware_version_obj.incremental_version.arg = &incrementalVersionField;
    pResponse->type.get_firmware_version_obj.incremental_version.funcs.decode = ProtobufDecodeCallbackField;

    protoResult = ProtobufDecode(
        (uint8_t*)HeapletAccess(MEM_RECEIVED_ENCODED_ACP_RESPONSE) + encodedPayloadOffset,
        HeapletGetSize(MEM_RECEIVED_ENCODED_ACP_RESPONSE) - encodedPayloadOffset,
        acp_response_get_firmware_version_fields,
        &pResponse->type.get_firmware_version_obj);
    if (!protoResult)
    {
        ACK_DEBUG_PRINT_E("Unable to decode get-firmware-version diagnostic command result.");
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    // Not much point in calling this function if the incremental version buffer can't get anything written
    // into it (at least one character and a nul terminator).
    ACK_ASSERT(incrementalVersionBufferSize > 1);
    if (incrementalVersionField.Length >= incrementalVersionBufferSize)
    {
        incrementalVersionField.Length = incrementalVersionBufferSize - 1;
    }

    memcpy(pIncrementalVersion, incrementalVersionField.Value, incrementalVersionField.Length);
    pIncrementalVersion[incrementalVersionField.Length] = 0;

    *pProtocolNumber = pResponse->type.get_firmware_version_obj.protocol_number;
    *pBuildNumber = pResponse->type.get_firmware_version_obj.build_number;

    retval = ACK_NO_ERROR;

cleanup0:
    CommonFreeAcpResponse();
    return retval;
}

#endif // def ACK_MODULE_DIAGNOSTICS

// Sends a simple provisioning command (no payload) and gets a response into
// MEM_RECEIVED_ENCODED_ACP_RESPONSE and MEM_RECEIVED_ACP_RESPONSE.
static ACKError_t CreateAndSendProvisioningCommand_(uint32_t submessageTag)
{
    acp_cmd* pCmd;
    ACKError_t retval;

    pCmd = (acp_cmd*)HeapletSetSize(MEM_OUTBOUND_ACP_CMD, sizeof(*pCmd));
    if (NULL == pCmd)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    pCmd->which_type = acp_cmd_provisioning_obj_tag;
    pCmd->type.provisioning_obj.which_command = submessageTag;

    // Send command and get response into MEM_RECEIVED_ENCODED_ACP_RESPONSE and MEM_RECEIVED_ACP_RESPONSE.
    retval = CommonSendAcpCmdAndGetResponse();
    if (ACK_NO_ERROR != retval)
    {
        ACK_DEBUG_PRINT_E("Unable to send provisioning command, err %u.", retval);
        goto cleanup0;
    }

    retval = ACK_NO_ERROR;

cleanup0:
    HeapletFree(MEM_OUTBOUND_ACP_CMD);
    return retval;
}

// Assuming MEM_RECEIVED_ENCODED_ACP_RESPONSE contains a valid command response which itself
// is known to contain a specific submessage, skips to the first byte of the submessage's encoded payload.
// Returns an offset within MEM_RECEIVED_ENCODED_ACP_RESPONSE where the caller should start decoding.
static bool SkipToEncodedResponsePayload_(uint32_t tag1, uint32_t optionalTag2, size_t *pOffset)
{
    pb_istream_t stream;
    size_t streamSize;

    streamSize = HeapletGetSize(MEM_RECEIVED_ENCODED_ACP_RESPONSE);

    stream = pb_istream_from_buffer(HeapletAccess(MEM_RECEIVED_ENCODED_ACP_RESPONSE), streamSize);

    if (!ProtobufSkipToEncodedSubmessagePayload(&stream, tag1))
    {
        return false;
    }

    if (optionalTag2)
    {
        if (!ProtobufSkipToEncodedSubmessagePayload(&stream, optionalTag2))
        {
            return false;
        }
    }

    *pOffset = streamSize - stream.bytes_left;
    return true;
}
