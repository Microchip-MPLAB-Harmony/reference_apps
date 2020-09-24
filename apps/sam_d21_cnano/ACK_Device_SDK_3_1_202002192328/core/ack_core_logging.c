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
#include "ack_core_logging.h"
#include "ack_logging.h"
#include "ack_core_protobuf_utilities.h"
#include "ack_user_config.h"
#include "acp.pb.h"
#include <stdio.h>
#include <stdarg.h>

#ifdef ACK_LOGGING

acp_log_level ACK_LogLevel = acp_log_level_info;

// Forward declarations.
static ACKError_t WriteLog_(acp_log_level logLevel, const char* pComponent, const char* pMessage);
static void DebugPrint(acp_log_level logLevel, const char* pMessage);

ACKError_t ACK_WriteLogFormatted(
    acp_log_level logLevel,
    const char* pComponent,
    const char* pMessageFormat,
    ...)
{
    ACKError_t retval;
    va_list ap;
    int charsWritten;
    char* pLogMessageBuffer = NULL;
    size_t bufferSize;

    ACK_ASSERT(NULL != pComponent);
    ACK_ASSERT(NULL != pMessageFormat);

    if (logLevel < ACK_LogLevel)
    {
        retval = ACK_NO_ERROR;
        goto cleanup0;
    }

    // NOTE: no reentry check. We use the alt heap blocks for sending out the ACP command and reading and
    // processing the result.

    // We'd like to use vsnprintf(NULL, 0, ...) to determine the required size, but some CRTs don't do
    // what we expect -- they return 0 or -1 if the buffer size is 0 or too small.
    // Instead, temporarily grab all available heaplet memory and use that as the buffer for vsnprintf.
    // That works more predictably across CRT variations. Once we know how large of a buffer we need,
    // immediately shrink the heaplet block so that subsequent operations needing memory can work.
    pLogMessageBuffer = (char*)HeapletSetToLargestPossibleSize(MEM_OUTBOUND_LOG_AND_METRICS_DATA);
    if (NULL == pLogMessageBuffer)
    {
        ACK_DEBUG_PRINT_E("No buffer space available for formatting the log message.");
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    bufferSize = HeapletGetSize(MEM_OUTBOUND_LOG_AND_METRICS_DATA);
    ACK_ASSERT(bufferSize > 0);

    va_start(ap, pMessageFormat);
    charsWritten = vsnprintf(pLogMessageBuffer, bufferSize, pMessageFormat, ap);
    va_end(ap);
    if ((charsWritten < 0) || (charsWritten >= bufferSize))
    {
        ACK_DEBUG_PRINT_E("vsnprintf failed, or not enough buffer space available.");
        retval = ACK_ERR_INTERNAL;
        goto cleanup0;
    }

    // Shrink the buffer down to only the required size. Since we're shrinking, we expect this
    // to always work.
    pLogMessageBuffer = (char*)HeapletSetSize(MEM_OUTBOUND_LOG_AND_METRICS_DATA, charsWritten + 1);
    ACK_ASSERT(pLogMessageBuffer)
    bufferSize = charsWritten + 1;

    // Format the string.
    // Need to create a new va_list because reusing the one above is not sufficiently portable C.
    va_start(ap, pMessageFormat);
    charsWritten = vsnprintf(pLogMessageBuffer, bufferSize, pMessageFormat, ap);
    va_end(ap);
    ACK_ASSERT(charsWritten >= 0);

    retval = WriteLog_(logLevel, pComponent, pLogMessageBuffer);

cleanup0:
    // No harm in freeing this even if it was never allocated above due to error.
    HeapletFree(MEM_OUTBOUND_LOG_AND_METRICS_DATA);
    return retval;
}

ACKError_t ACK_WriteLog(acp_log_level logLevel, const char* pComponent, const char* pMessage)
{
    ACK_ASSERT(NULL != pComponent);
    ACK_ASSERT(NULL != pMessage);

    if (logLevel < ACK_LogLevel)
    {
        return ACK_NO_ERROR;
    }

    // NOTE: no reentry check. We use the alt heap blocks for sending out the ACP command and reading and
    // processing the result.

    return WriteLog_(logLevel, pComponent, pMessage);
}

// Note carefully that this routine uses "AltHeapletBlocks" common routines to send the write-log ACP command
// and receive the response. This is a set of heaplet tags that when used will not move or overwrite
// existing blocks that may be in use when the user call ACK_WriteLog/ACK_WriteLogFormatted. Because of this,
// it is safe to call those routines when in a handler callback (ACKUser_Onxxx).
static ACKError_t WriteLog_(acp_log_level logLevel, const char* pComponent, const char* pMessage)
{
    acp_cmd* pCmd;
    ACKError_t retval;

    // Put these on the stack for now. If there are more, or more memory is needed, consider changing to
    // putting these in the heaplet.
    ProtobufCallbackField_t componentStringCallback = {0};
    ProtobufCallbackField_t messageStringCallback = {0};

    // Print the log message to the debug port also.
    DebugPrint(logLevel, pMessage);

    pCmd = (acp_cmd*)HeapletSetSize(MEM_ALT_OUTBOUND_ACP_CMD, sizeof(*pCmd));
    if (NULL == pCmd)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    memset(pCmd, 0, sizeof(*pCmd));

    pCmd->which_type = acp_cmd_write_log_obj_tag;
    pCmd->type.write_log_obj.log_level = logLevel;

    pCmd->type.write_log_obj.component.arg = &componentStringCallback;
    pCmd->type.write_log_obj.component.funcs.encode = ProtobufEncodeCallbackField;

    // Note: the ACK Connectivity Module ignores characters after the 63rd in the component string
    // (which has a fixed length of 64 bytes, including the nul terminator), but we don't try to enforce
    // that here.
    componentStringCallback.Value = (const uint8_t*)pComponent;
    componentStringCallback.Length = strlen(pComponent);

    pCmd->type.write_log_obj.message.arg = &messageStringCallback;
    pCmd->type.write_log_obj.message.funcs.encode = ProtobufEncodeCallbackField;

    messageStringCallback.Value = (const uint8_t*)pMessage;
    messageStringCallback.Length = strlen(pMessage);

    retval = CommonSendAcpCmdAndGetResponseAltHeapletBlocks();

    if (ACK_NO_ERROR != retval)
    {
        ACK_DEBUG_PRINT_E("Error encoding and sending command, err %u", retval);
        goto cleanup0;
    }

    if (!CommonCheckGenericResponseAltHeapletBlocks())
    {
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    retval = ACK_NO_ERROR;

cleanup0:
    HeapletFree(MEM_ALT_OUTBOUND_ACP_CMD);
    CommonFreeAcpResponseAltHeapletBlocks();
    return retval;
}

ACKError_t SubmitLogs(void)
{
    ACKError_t retval;

    ACK_DEBUG_PRINT_I("Sending submit logs command");

    retval = CommonAllocAndSendAcpCmdAndGetAcpResponse(acp_cmd_submit_logs_obj_tag);

    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    if (!CommonCheckGenericResponse())
    {
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    retval = ACK_NO_ERROR;

cleanup0:
    CommonFreeAcpResponse();
    return retval;
}

static void DebugPrint(acp_log_level logLevel, const char* pMessage)
{
    switch (logLevel)
    {
    case acp_log_level_info:
        ACK_DEBUG_PRINT_I("LOG: %s", pMessage);
        break;
    case acp_log_level_error:
        ACK_DEBUG_PRINT_E("LOG: %s", pMessage);
        break;
    default:
        ACK_ASSERT(acp_log_level_debug == logLevel);
        ACK_DEBUG_PRINT_D("LOG: %s", pMessage);
        break;
    }
}

#endif // def ACK_LOGGING
