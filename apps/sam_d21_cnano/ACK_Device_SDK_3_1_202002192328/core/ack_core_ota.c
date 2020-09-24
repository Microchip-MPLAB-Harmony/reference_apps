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
#include "ack_core_protobuf_utilities.h"
#include "ack_user_config.h"
#include "acp.pb.h"

#ifdef ACK_HOST_FIRMWARE_UPDATE

ACKError_t OtaDownload(
    uint32_t readOffset,
    uint32_t maxReadLength,
    uint8_t* pBytes,
    uint32_t* pActualLength)
{
    acp_cmd* pCmd;
    acp_response* pResponse;
    acp_response_read_host_fw_update_bytes* pFirmwareUpdateResponse;
    ProtobufCallbackField_t field = {0};
    bool protoResult;
    ACKError_t retval;

    ACK_DEBUG_PRINT_I("Sending get host ota bytes command");

    pCmd = (acp_cmd*)HeapletSetSize(MEM_OUTBOUND_ACP_CMD, sizeof(*pCmd));
    if (NULL == pCmd)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    pCmd->which_type = acp_cmd_read_host_fw_update_bytes_obj_tag;
    pCmd->type.read_host_fw_update_bytes_obj.length = maxReadLength;
    pCmd->type.read_host_fw_update_bytes_obj.offset = readOffset;

    retval = CommonSendAcpCmdAndGetResponse();
    if (ACK_NO_ERROR != retval)
    {
        ACK_DEBUG_PRINT_E("Unable to send read host OTA update command, err %u", retval);
        goto cleanup0;
    }

    pResponse = (acp_response*)HeapletAccess(MEM_RECEIVED_ACP_RESPONSE);

    if (acp_response_read_host_fw_update_bytes_obj_tag != pResponse->which_type)
    {
        ACK_DEBUG_PRINT_E("Unexpected read host fw update response type %u", pResponse->which_type);
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    // Lower level response message decode.
    pFirmwareUpdateResponse = &pResponse->type.read_host_fw_update_bytes_obj;
    pFirmwareUpdateResponse->bytes.funcs.decode = ProtobufDecodeCallbackField;
    pFirmwareUpdateResponse->bytes.arg = &field;

    // 'Decode' here means that we get a pointer to the still-encoded submessage, within the original
    // encoded event.
    protoResult = ProtobufDecodeSubmessage(
        HeapletAccess(MEM_RECEIVED_ENCODED_ACP_RESPONSE),
        HeapletGetSize(MEM_RECEIVED_ENCODED_ACP_RESPONSE),
        acp_response_read_host_fw_update_bytes_obj_tag,
        acp_response_read_host_fw_update_bytes_fields,
        pFirmwareUpdateResponse);

    if (!protoResult)
    {
        ACK_DEBUG_PRINT_E("Unable to decode read host firmware bytes submessage");
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    if (field.Length > maxReadLength)
    {
        ACK_DEBUG_PRINT_E(
            "That's funny; read host firmware ota has %u bytes but we requested a max of %u bytes",
            (unsigned)field.Length,
            (unsigned)maxReadLength);
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    memcpy(pBytes, field.Value, field.Length);
    *pActualLength = field.Length;

    retval = ACK_NO_ERROR;

cleanup0:
    HeapletFree(MEM_OUTBOUND_ACP_CMD);
    CommonFreeAcpResponse();
    return retval;
}

#endif // def ACK_HOST_FIRMWARE_UPDATE
