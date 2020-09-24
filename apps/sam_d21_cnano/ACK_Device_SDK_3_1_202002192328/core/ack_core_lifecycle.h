/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_LIFECYCLE_H__
#define __ACK_LIFECYCLE_H__

#include "ack_user_config.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Advance lifecycle when the ACK Connectivity Module booted, or completed rebooting.
void LifecycleModuleBooted(void);

// Advance lifecycle when the ACK Connectivity Module is requesting to be rebooted. If force is set,
// the reboot will occur immediately regardless of whether the device is in use. Otherwise, the reboot
// will occur at a point in the future when the device is not in use.
void LifecycleModuleRequestingReboot(bool force);

// Advance lifecycle when a factory reset is being requested.
void LifecycleFactoryResetRequested(void);

// Minimum milliseconds between calls to ACK_GetStatus when checking connectivity state.
#define ACK_CONNECTIVITY_STATE_SAMPLE_INTERVAL_MS 2500

#ifdef ACK_HOST_FIRMWARE_UPDATE

// The size of the (statically allocated) update chunk retrieval buffer.
#define ACK_HOST_FIRMWARE_UPDATE_CHUNK_SIZE ((size_t)256U)

// The maximum amount of attempts that will be performed for retrieving a single update chunk before the
// update process is aborted.
#define ACK_HOST_FIRMWARE_UPDATE_MAX_RETRIEVE_ATTEMPT_COUNT 10

typedef struct _OtaState_t
{
    uint32_t ImageSize;
    uint32_t RetrieveRemaining;
    unsigned ChunkReadFailureCount;
    unsigned Force : 1;
    unsigned ApplicationPending : 1;
    unsigned StartedPlatform : 1; // non-0 if we called ACKPlatform_StartHostFirmwareUpdate.
}
OtaState_t;

extern OtaState_t g_otaState;

// Advance lifecycle when an Over-the-Air update is available.
void LifecycleHostFirmwareUpdateReceived(
    const char* pVersion,
    const char* pSignature,
    uint32_t size,
    bool force);

#endif

#ifdef __cplusplus
}
#endif

#endif // ndef __ACK_LIFECYCLE_H__
