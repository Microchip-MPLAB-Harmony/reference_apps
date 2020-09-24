/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

// Routines for ACK Connectivity Module diagnostics.

#ifndef __ACK_MODULE_DIAGNOSTICS_H__
#define __ACK_MODULE_DIAGNOSTICS_H__

#include "ack_user_config.h"
#include "details/ack_types.h"
#include "acp.pb.h"
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

// Call this to get device type info from the ACK connectivity module.
// If an empty string is returned, the ACK module is in an early provisioning state, where no
// device type is assigned yet.
ACKError_t ACK_GetDeviceType(char* pDeviceType, size_t deviceTypeBufferSize);

#ifdef ACK_MODULE_DIAGNOSTICS

// Call this to provisioning info from the ACK connectivity module.
ACKError_t ACK_GetProvisioningInfo(acp_response_provisioning_provisioning_state* pState);

// Call this to get the device DSN from the ACK connectivity module.
ACKError_t ACK_GetHardwareInfo(char* pDsn, size_t dsnBufferSize);

// Call this to get the ACK connectivity module's firmware version.
ACKError_t ACK_GetFirmwareVersion(
    uint32_t* pProtocolNumber,
    uint32_t* pBuildNumber,
    char* pIncrementalVersion,
    size_t incrementalVersionBufferSize);

#endif // def ACK_MODULE_DIAGNOSTICS

#ifdef __cplusplus
}
#endif

#endif // def __ACK_MODULE_DIAGNOSTICS_H__
