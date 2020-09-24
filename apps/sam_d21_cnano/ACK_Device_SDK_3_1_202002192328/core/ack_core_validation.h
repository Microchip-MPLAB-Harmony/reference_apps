/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_CORE_VALIDATION_H__
#define __ACK_CORE_VALIDATION_H__

#include "ack_user_config.h"

// These must match the values in the ACK module simulator Python script(s).
#define ACK_MARKER_LIFECYCLE_STATE "LIFECYCLE-STATE"
#define ACK_MARKER_PROTOCOL_ERROR "PROTOCOL-ERROR"
#define ACK_MARKER_READ_OTA_CHUNK_ERROR "OTA-CHUNK-ERROR"
#define ACK_MARKER_READ_OTA_CHUNK_SUCCESS "OTA-CHUNK-DOWNLOADED"
#define ACK_MARKER_OTA_COMPLETE "OTA-COMPLETE"
#define ACK_MARKER_OTA_RESTART_DEVICE "OTA-RESTART"

#ifdef ACK_VALIDATION

#ifdef __cplusplus
extern "C"
{
#endif

// NULL terminates the list.
void ValidationSendMarker(const char* pName, ...);

// There has to be at least one string, to terminate an empty list.
// Don't use ##__VA_ARGS__ because that strips the comma ahead of an empty list, potentially hiding
// a bug if someone forgets to put in a NULL.
#define VALIDATION_SEND_MARKER(name, ...) ValidationSendMarker(name, __VA_ARGS__)

#ifdef __cplusplus
}
#endif

#else // ndef ACK_VALIDATION

#define VALIDATION_SEND_MARKER(name, ...)

#endif // def ACK_VALIDATION

#endif // ndef __ACK_CORE_VALIDATION_H__
