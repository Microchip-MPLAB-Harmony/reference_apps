/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_LOGGING_H__
#define __ACK_LOGGING_H__

#include "ack_user_config.h"
#include "details/ack_types.h"
#include "acp.pb.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef ACK_LOGGING

// Call these routines to write into the log. The log is buffered on the Connectivity Module until an
// explicit command is sent to the Connectivity Module to send it to the cloud. That command is sent when
// your ACKUser_DoesUserWantFactoryReset routine returns true.
// The component and message strings are user-defined and not interpreted by ACK. The component string can be
// a maximum length of 63 characters and is truncated if longer than that. Use acp_log_level_info and
// acp_log_level_error as appropriate to log information that would be helpful to diagnose problems in
// production devices. Use log level acp_log_level_debug to log more verbose information helpful during
// development.

ACKError_t ACK_WriteLog(acp_log_level logLevel, const char* pComponent, const char* pMessage);

ACKError_t ACK_WriteLogFormatted(
    acp_log_level logLevel,
    const char* pComponent,
    const char* pMessageFormat,
    ...);

// Log level. Calls to ACK_WriteLog and ACK_WriteLogFormatted are no-ops when the message log level is
// less than this value.
extern acp_log_level ACK_LogLevel;

#endif // def ACK_LOGGING

#ifdef __cplusplus
}
#endif

#endif // def __ACK_LOGGING_H__
