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
#include "ack_core_event_builder.h"
#include "ack_core_factoryreset.h"
#include "ack_core_heaplet.h"
#include "ack_core_hostconfig.h"
#include "ack_core_lifecycle.h"
#include "ack_core_logging.h"
#include "ack_core_ota.h"
#include "ack_core_outbound_events.h"
#include "ack_core_processevent.h"
#include "ack_core_status.h"
#include "ack_core_tick64.h"
#include "ack_core_userguidedsetup.h"
#include "ack_core_validation.h"
#include "ack_user_device.h"
#include "ack_user_config.h"
#include "ack_logging.h"
#include "ack_module_diagnostics.h"
#include <inttypes.h>
#include <stdio.h>

// Represents the reboot state of the ACK Connectivity Module.
typedef enum _RebootPending_t
{
    // No reboot is pending.
    ACK_PENDING_REBOOT_NONE,

    // A reboot is pending, but can be deferred until the device is not in use.
    ACK_PENDING_REBOOT_DEFERRABLE,

    // A reboot is pending, which must happen immediately.
    ACK_PENDING_REBOOT_PENDING
}
RebootPending_t;

// The lifecycle state and substate. These variables are public (non-static, and declared in ack.h).
ACKLifecycleState_t ACK_LifecycleState = ACK_LIFECYCLE_INITIAL;
ACKLifecycleSubStateInfo_t ACK_LifecycleSubStateInfo;

// Start out with no pending reboot.
static RebootPending_t sg_ackModuleRebootPending = ACK_PENDING_REBOOT_NONE;

// After the module actually reboots, we need to send host config info to the Connectivity Module.
static bool sg_needToSendHostConfig = false;

// Flag to denote that the ACK Connectivity Module has requested a factory reset.
static bool sg_ackModuleInitiatedFactoryReset = false;

// Tracks the most recent time we checked connectivity.
static uint32_t sg_connectivityLastTick = 0;

// Forward declarations.
static bool SatisfyPendingUserGuidedSetupRequest(bool deviceInUse);
static bool SatisfyPendingModuleReboot(bool deviceInUse);
static bool SatisfyPendingFactoryReset(bool deviceInUse);
static bool SatisfySendHostConfig(void);
static void CheckAndUpdateConnectivityState(void);
static void SetLifecycleState(ACKLifecycleState_t newState);

#ifdef ACK_LOGGING
static void SatisfyPendingLogSubmission(void);
#endif // def ACK_LOGGING

#ifdef ACK_HOST_FIRMWARE_UPDATE

// TODO: should this be in the heaplet?
uint8_t sg_otaChunkBuffer[ACK_HOST_FIRMWARE_UPDATE_CHUNK_SIZE];

OtaState_t g_otaState = {0};
#define _IS_OTA_IN_PROGRESS (0 != g_otaState.ImageSize)
#define _CLEAR_OTA_IN_PROGRESS g_otaState.ImageSize = 0

static bool SatisfyOtaAvailable(void);
static uint32_t RetrieveNextOtaChunk(void);
static bool CheckOtaImageHeader(uint32_t* pTargetAddress, uint32_t* pCrc32);
static void OtaFailed(void);

#endif // def ACK_HOST_FIRMWARE_UPDATE

#ifdef ACK_MODULE_DIAGNOSTICS

static void DebugPrintModuleDiagnosticInfo(void);
static void DebugPrintDeviceType(void);
static void DebugPrintFirmwareVersion(void);
static void DebugPrintHardwareInfo(void);
static void DebugPrintProvisioningInfo(void);

#define ACK_DEVICE_TYPE_LENGTH 16
#define ACK_INCREMENTAL_FIRMWARE_VERSION_LENGTH 16
#define ACK_DSN_LENGTH 18

#endif // def ACK_MODULE_DIAGNOSTICS

void ACK_Initialize(void)
{
    uint64_t firmwareVersion;

    // Not re-entrant, since we re-initialize the Heaplet below, but don't want to free memory out from
    // underneath an executing function in this codebase.
    ACK_REENTRY_CHECK;

    ACKPlatform_Initialize();

    firmwareVersion = ACKUser_GetFirmwareVersion();

    // Use critical error level to guarantee that this prints *always*.
    ACK_DEBUG_PRINT_C(
        "ACK Device SDK Implementation Core (re-)started; firmware version %"PRIu64" (0x%"PRIx64").",
        firmwareVersion,
        firmwareVersion);

    ACK_DEBUG_PRINT_I("Resetting ACK module.");
    ACK_ResetConnectivityModule();

    EventBuilderEnd();

    HeapletInit();

    sg_connectivityLastTick = 0;

    // Reset real-time mechanism.
    g_realTimeEpochBaseSeconds = 0;
    g_realTimeTickBase = 0;

    // Causes ACKUser_OnLifecycleStateChange to be called inside re-entry guards.
    ACK_LifecycleState = ACK_LIFECYCLE_INITIAL;
    SetLifecycleState(ACK_LIFECYCLE_UNAVAILABLE);

    sg_ackModuleRebootPending = ACK_PENDING_REBOOT_NONE;
    sg_needToSendHostConfig = false;
    sg_ackModuleInitiatedFactoryReset = false;

    ACK_DEBUG_PRINT_I("ACK Device SDK Implementation Core fully initialized.");
}

// Main worker for processing ACK events and lifecycle.
void ACK_Process()
{
    ACKError_t retval;
    
    ACK_REENTRY_CHECK;

#ifdef ACK_TICK64
    // Ensure state for 64-bit tick count is up to date.
    Tick64Loop();
#endif

    ACK_REENTRY_SHIELDS_UP;
    bool deviceInUse = ACKUser_IsDeviceInUse();
    ACK_REENTRY_SHIELDS_DOWN;

#ifdef ACK_LOGGING
    // First priority is log submission. Customer service will be in need of logs as soon as possible.
    // Log submission does not really affect the life cycle. We can move on to the next task after this
    // instead of returning after this.
    SatisfyPendingLogSubmission();
#endif

#ifdef ACK_HOST_FIRMWARE_UPDATE
    if (g_otaState.ApplicationPending && !deviceInUse)
    {
        VALIDATION_SEND_MARKER(ACK_MARKER_OTA_RESTART_DEVICE, NULL);

        ACK_DEBUG_PRINT_I("Causing host firmware update image to be installed.");
        ACKPlatform_ApplyHostFirmwareUpdate();

        // Should never get here.
        ACK_ASSERT(false);
    }
#endif

    // Next priority: pending reboot.
    if (SatisfyPendingModuleReboot(deviceInUse))
    {
        return;
    }

    // Next priority: pending factory reset.
    if (SatisfyPendingFactoryReset(deviceInUse))
    {
        return;
    }

    // Next priority: pending user-guided setup.
    if (SatisfyPendingUserGuidedSetupRequest(deviceInUse))
    {
        return;
    }

    // Next priority: send host config params if necessary.
    if (SatisfySendHostConfig())
    {
        // For demonstrative purposes, each time we send host config data to the connectivity module,
        // also retrieve and dump module diagnostic info.
        // In production, the module diagnostic routines can be used at any time. But this is a convenient
        // point for demonstration purposes because it occurs shortly after we get notified that the
        // connectivity module has booted/rebooted (see LifecycleModuleBooted in this file).
#ifdef ACK_MODULE_DIAGNOSTICS
        DebugPrintModuleDiagnosticInfo();
#endif
        return;
    }

#ifdef ACK_HOST_FIRMWARE_UPDATE
    // Next priority: if a host update is available, try to retrieve a chunk of it.
    if (SatisfyOtaAvailable())
    {
        // If we get here, we just completed revrieving a complete OTA image from the connectivity module
        // and need to reboot ourselves to apply it. Return immediately so that the reboot happens next pass
        // through the main loop when the device isn't busy.
        ACK_ASSERT(g_otaState.ApplicationPending);
        return;
    }
#endif

    // If none of the above happened, check/update connectivity status.
    CheckAndUpdateConnectivityState();

    // Finally, process events (directives etc.).
    if (ACK_NO_ERROR == ProcessEventIfAvailable())
    {
        // If the inbound event was a directive, automatically send the directive reply.
        if (g_inboundEventInfo.Bits.ProcessedDirective)
        {
            if (g_pendingOutboundEvent.Flags.Bits.EventPending)
            {
                retval = OutboundEventSend();
                if (retval != ACK_NO_ERROR)
                {
                    ACK_DEBUG_PRINT_W("Error %u sending directive response event.", retval);
                }
            }
            else
            {
                ACK_DEBUG_PRINT_W(
                    "Processed a directive, but no response was created via ACK_Complete* routines.");
            }
        }
    }
    else
    {
        ACKPlatform_DrainRead();
    }
}

#ifdef ACK_LOGGING    

// Satisfy a pending log submission request if life cycle state indicates device is connected to Alexa.
// Worker for ACK_Process.
static void SatisfyPendingLogSubmission(void)
{
    ACKError_t err;
    bool userWantsToSubmitLogs;

    if (ACK_LIFECYCLE_CONNECTED_TO_ALEXA != ACK_LifecycleState)
    {
        return;
    }

    ACK_REENTRY_SHIELDS_UP;
    userWantsToSubmitLogs = ACKUser_DoesUserWantToSubmitLogs();
    ACK_REENTRY_SHIELDS_DOWN;

    if (!userWantsToSubmitLogs)
    {
        return;
    }

    ACK_DEBUG_PRINT_I("Initiating log submission...");
    err = SubmitLogs();

    if (ACK_NO_ERROR != err)
    {
        ACK_DEBUG_PRINT_E("Unable to submit logs (err %u).", err);
        return;
    }

    ACK_DEBUG_PRINT_I("Logs submitted successfully.");
}

#endif // def ACK_LOGGING

// Satisfy a pending user-guided setup request if device is not in use, there is no factory
// reset in progress and if life cycle state is available.
// Worker for ACK_Process.
bool SatisfyPendingUserGuidedSetupRequest(bool deviceInUse)
{
    ACKError_t err;
    bool userWantsUserGuidedSetup;

    if ((ACK_LIFECYCLE_UNAVAILABLE == ACK_LifecycleState)
        || (ACK_LIFECYCLE_FACTORY_RESET_IN_PROGRESS == ACK_LifecycleState)
        || deviceInUse)
    {
        return false;
    }

    ACK_REENTRY_SHIELDS_UP;
    userWantsUserGuidedSetup = ACKUser_DoesUserWantUserGuidedSetup();
    ACK_REENTRY_SHIELDS_DOWN;

    if (!userWantsUserGuidedSetup)
    {
        return false;
    }

    ACK_DEBUG_PRINT_I("Initiating user-guided setup...");
    err = UserGuidedSetupInitiate();

    if (ACK_NO_ERROR != err)
    {
        ACK_DEBUG_PRINT_E("Unable to initiate user-guided setup (err %u).", err);
        return false;
    }

    ACK_DEBUG_PRINT_I("User-guided setup successfully initiated.");

    SetLifecycleState(ACK_LIFECYCLE_IN_SETUP_MODE);

    return true;
}

// Satisfy a pending reboot, unless the device is in use. If the device is in use, only forced
// pending reboots are satisfied.
bool SatisfyPendingModuleReboot(bool deviceInUse)
{
    if ((ACK_PENDING_REBOOT_PENDING == sg_ackModuleRebootPending)
        || ((ACK_PENDING_REBOOT_DEFERRABLE == sg_ackModuleRebootPending) && !deviceInUse))
    {
        SetLifecycleState(ACK_LIFECYCLE_UNAVAILABLE);

        ACK_DEBUG_PRINT_I("Rebooting ACK Connectivity Module.");

        ACK_ResetConnectivityModule();

        sg_ackModuleRebootPending = ACK_PENDING_REBOOT_NONE;
        return true;
    }

    return false;
}

// If the user is requesting a factory reset, and the device is not in use, initiate a factory reset
// of the ACK Connectivity Module. If there's already a factory reset in progress, or it's not currently
// possible to issue commands to the module, ignore the user's request.
// Worker for ACK_Process.
bool SatisfyPendingFactoryReset(bool deviceInUse)
{
    ACKError_t err;
    bool userWantsFactoryReset;

    if ((ACK_LIFECYCLE_UNAVAILABLE == ACK_LifecycleState)
        || (ACK_LIFECYCLE_FACTORY_RESET_IN_PROGRESS == ACK_LifecycleState)
        || deviceInUse)
    {
        return false;
    }

    // We want to prioritize the ACK Connectivity module initiated factory reset in the scenario
    // where both the user and the module initiate a factory reset.
    if (sg_ackModuleInitiatedFactoryReset)
    {
        sg_ackModuleInitiatedFactoryReset = false;
    }
    else
    {
        ACK_REENTRY_SHIELDS_UP;
        userWantsFactoryReset = ACKUser_DoesUserWantFactoryReset();
        ACK_REENTRY_SHIELDS_DOWN;

        if (!userWantsFactoryReset)
        {
            return false;
        }

        ACK_DEBUG_PRINT_I("Initiating ACK Connectivity Module factory reset...");

        err = FactoryResetInitiate();

        if (ACK_NO_ERROR != err)
        {
            ACK_DEBUG_PRINT_E("Unable to initiate ACK Connectivity Module factory reset (err %u).", err);
            return false;
        }
    }

    ACK_DEBUG_PRINT_I("ACK Connectivity Module factory reset in progress.");

    SetLifecycleState(ACK_LIFECYCLE_FACTORY_RESET_IN_PROGRESS);

    // Erase all persisted user settings.
    ACK_REENTRY_SHIELDS_UP;
    ACKUser_EraseUserSettings();
    ACK_REENTRY_SHIELDS_DOWN;

    return true;
}

// Send host config parameters to the ACK connectivity module if the current state indicates that we need
// to do so.
// Worker for ACK_Process.
bool SatisfySendHostConfig(void)
{
    ACKError_t err;
    uint64_t version;

    if (!sg_needToSendHostConfig)
    {
        return false;
    }

    ACK_DEBUG_PRINT_I("Sending host config to ACK Connectivity Module...");

    ACK_REENTRY_SHIELDS_UP;
    version = ACKUser_GetFirmwareVersion();
    ACK_REENTRY_SHIELDS_DOWN;

    err = HostConfigWrite(version);

    if (ACK_NO_ERROR != err)
    {
        ACK_DEBUG_PRINT_E("Unable to send host config to ACK Connectivity Module (err %u).", err);
        return false;
    }

    ACK_DEBUG_PRINT_I("Sent host config to ACK Connectivity Module.");

    sg_needToSendHostConfig = false;
    return true;
}

#ifdef ACK_HOST_FIRMWARE_UPDATE

// Retrieves a chunk of firmware update, if one is available.
// Worker for ACK_Process.
bool SatisfyOtaAvailable(void)
{
    uint32_t chunkSize;
    uint32_t targetAddress;
    uint32_t crc32;
    uint32_t imageBodyOffset;

    if (!_IS_OTA_IN_PROGRESS)
    {
        // No OTA retrieval in progress.
        return false;
    }

    chunkSize = RetrieveNextOtaChunk();
    if (0 == chunkSize)
    {
        // Note: don't call OtaFailed here. There might still be retries remaining for this chunk.
        return false;
    }

    if (g_otaState.ImageSize == g_otaState.RetrieveRemaining)
    {
        // We read the OTA image header.
        ACK_ASSERT(chunkSize == sizeof(ACKHostFirmwareUpdateImageHeader_t));
        if (!CheckOtaImageHeader(&targetAddress, &crc32))
        {
            OtaFailed();
            return false;
        }

        ACK_ASSERT(g_otaState.ImageSize > sizeof(ACKHostFirmwareUpdateImageHeader_t));
        if (!ACKPlatform_StartHostFirmwareUpdate(
            g_otaState.ImageSize - sizeof(ACKHostFirmwareUpdateImageHeader_t),
            targetAddress,
            crc32))
        {
            ACK_DEBUG_PRINT_E("Platform failed starting host update.");

            OtaFailed();
            return false;
        }

        ACK_ASSERT(!g_otaState.StartedPlatform);
        g_otaState.StartedPlatform = true;

        ACK_DEBUG_PRINT_D("Host update image header looks good; continuing retrieval.");
    }
    else
    {
        // We read a chunk of the image.
        imageBodyOffset = (g_otaState.ImageSize - g_otaState.RetrieveRemaining)
            - sizeof(ACKHostFirmwareUpdateImageHeader_t);

        if (!ACKPlatform_SaveHostFirmwareUpdateChunk(imageBodyOffset, sg_otaChunkBuffer, chunkSize))
        {
            ACK_DEBUG_PRINT_E("Platform failed saving a host firmware update chunk.");

            OtaFailed();
            return false;
        }
    }

    g_otaState.RetrieveRemaining -= chunkSize;
    g_otaState.ChunkReadFailureCount = 0;

    if (0 == g_otaState.RetrieveRemaining)
    {
        // Finished retrieving.
        if (!ACKPlatform_HostFirmwareUpdateSuccessfullyRetrieved())
        {
            ACK_DEBUG_PRINT_E("Platform failed processing the retrieved host firmware update image.");

            OtaFailed();
            return false;
        }

        ACK_DEBUG_PRINT_I("Host firmware update image successfully retrieved.");

        // Success, and there's no longer an OTA retrieval in progress.
        _CLEAR_OTA_IN_PROGRESS;
        g_otaState.ApplicationPending = true;
        VALIDATION_SEND_MARKER(ACK_MARKER_OTA_COMPLETE, NULL);
        return true;
    }

    // Success, but there's still an OTA download in progress.
    return false;
}

// Retrieves the next OTA chunk from the Connectivity Module.
// At offset 0, reads the OTA image header. Otherwise reads as much of the body of the update image
// as will fit in sg_otaChunkBuffer.
static uint32_t RetrieveNextOtaChunk(void)
{
    uint32_t offset;
    uint32_t readSize;
    uint32_t retrievedSize;
    ACKError_t err;

    offset = g_otaState.ImageSize - g_otaState.RetrieveRemaining;

    // At offset 0, read the OTA image header. Otherwise, read chunks of the body.
    if (0 == offset)
    {
        // We should have ignored the update if it isn't large enough to have any data in it.
        ACK_ASSERT(g_otaState.RetrieveRemaining > sizeof(ACKHostFirmwareUpdateImageHeader_t))

        ACK_STATIC_ASSERT(sizeof(sg_otaChunkBuffer) >= sizeof(ACKHostFirmwareUpdateImageHeader_t));
        readSize = sizeof(ACKHostFirmwareUpdateImageHeader_t);
    }
    else
    {
        readSize = g_otaState.RetrieveRemaining;
        if (readSize > sizeof(sg_otaChunkBuffer))
        {
            readSize = sizeof(sg_otaChunkBuffer);
        }
    }

    ACK_DEBUG_PRINT_D(
        "Retrieving host firmware update image chunk at offset %"PRIu32", size %"PRIu32".",
        offset,
        readSize);

    err = OtaDownload(offset, readSize, sg_otaChunkBuffer, &retrievedSize);
    if (ACK_NO_ERROR == err)
    {
        if (retrievedSize != readSize)
        {
            ACK_DEBUG_PRINT_W(
                "Retrieved host firmware update image chunk at offset %"PRIu32" expected %"PRIu32" bytes "
                "but got %"PRIu32".",
                offset,
                readSize,
                retrievedSize);

            err = ACK_ERR_INTERNAL;
        }
    }
    else
    {
        ACK_DEBUG_PRINT_W(
            "Unable to retrieve host firmware update image chunk at offset %"PRIu32", err %u.",
            offset,
            err);
    }

    if (ACK_NO_ERROR == err)
    {
        VALIDATION_SEND_MARKER(ACK_MARKER_READ_OTA_CHUNK_SUCCESS, NULL);
    }
    else
    {
        if (0 == g_otaState.ChunkReadFailureCount)
        {
            VALIDATION_SEND_MARKER(ACK_MARKER_READ_OTA_CHUNK_ERROR, NULL);
        }

        // Error.
        // Since we don't update the offset, we will retry the downloading the chunk when this function
        // is called again in the next iteration.
        ++g_otaState.ChunkReadFailureCount;
        if (ACK_HOST_FIRMWARE_UPDATE_MAX_RETRIEVE_ATTEMPT_COUNT == g_otaState.ChunkReadFailureCount)
        {
            ACK_DEBUG_PRINT_E("Aborting host fimware update due to retrieval errors.");

            OtaFailed();
        }

        retrievedSize = 0;
    }

    return retrievedSize;
}

// Checks characteristics of the OTA image header to ensure that the OTA image is targeted at the
// expected address. Also saves the CRC value from the header.
static bool CheckOtaImageHeader(uint32_t* pTargetAddress, uint32_t* pCrc32)
{
    const ACKHostFirmwareUpdateImageHeader_t* pImageHeader;
    char thisDeviceType[sizeof(pImageHeader->DeviceType) + 1];
    char headerDeviceType[sizeof(pImageHeader->DeviceType) + 1];
    ACKError_t error;
    bool valid;

    pImageHeader = (const ACKHostFirmwareUpdateImageHeader_t*)&sg_otaChunkBuffer[0];

    valid = ((ACK_HOST_FIRMWARE_UPDATE_IMAGE_HEADER_SIGNATURE == pImageHeader->Signature)
        && (pImageHeader->Size == (g_otaState.ImageSize - sizeof(ACKHostFirmwareUpdateImageHeader_t))));

    if (!valid)
    {
        ACK_DEBUG_PRINT_E(
            "Host firmware update image corrupt; signature 0x%"PRIx32" or size 0x%"PRIx32" invalid.",
            pImageHeader->Signature,
            pImageHeader->Size);

        goto cleanup0;
    }

    // Check Device Type.
    error = ACK_GetDeviceType(thisDeviceType, sizeof(thisDeviceType));
    if (ACK_NO_ERROR != error)
    {
        ACK_DEBUG_PRINT_E(
            "Unable to retrieve device type from connectivity module; ignoring host firmware update.");

        valid = false;
        goto cleanup0;
    }

    memcpy(headerDeviceType, pImageHeader->DeviceType, sizeof(headerDeviceType));
    headerDeviceType[sizeof(headerDeviceType) - 1] = 0;
    if (0 != strcmp(thisDeviceType, headerDeviceType))
    {
        ACK_DEBUG_PRINT_E(
            "This device type is '%s' but the host firmware update image is for '%s'; ignoring update.",
            thisDeviceType,
            headerDeviceType);

        valid = false;
        goto cleanup0;
    }

    *pTargetAddress = pImageHeader->TargetAddress;
    *pCrc32 = pImageHeader->Crc32;
    
    valid = true;

cleanup0:
    return valid;
}

static void OtaFailed()
{
    _CLEAR_OTA_IN_PROGRESS;

    if (g_otaState.StartedPlatform)
    {
        ACKPlatform_HostFirmwareUpdateFailed();
    }

    VALIDATION_SEND_MARKER(ACK_MARKER_OTA_COMPLETE, NULL);
}

#endif // def ACK_HOST_FIRMWARE_UPDATE

// Update connectivity status, unless the ACK module is unavailable such as after rebooting it but
// before we get the booted event. We also skip this if a factory reset is in progress because
// we don't want to clobber factory-reset-in-progress state with a state determined from ACK_GetStatus.
// We don't need to do this every pass through the loop. Doing it every few seconds is a good interval.
void CheckAndUpdateConnectivityState(void)
{
    uint32_t tick;
    ACKStatus_t ackStatus;
    ACKLifecycleState_t newState = ACK_LifecycleState;

    if ((ACK_LIFECYCLE_UNAVAILABLE != ACK_LifecycleState)
        && (ACK_LIFECYCLE_FACTORY_RESET_IN_PROGRESS != ACK_LifecycleState))
    {
        // After we get a booted event following a factory reset, or have successfully initiated
        // setup mode, or are in setup mode, we could call GetStatus more frequently, and degrade the
        // general case to more like every 5 or 10 seconds. For now, we do this every 2.5 seconds.
        tick = ACKPlatform_TickCount();
        if ((0 == sg_connectivityLastTick)
            || ((tick - sg_connectivityLastTick) >= ACK_CONNECTIVITY_STATE_SAMPLE_INTERVAL_MS))
        {
            sg_connectivityLastTick = tick;

            ACK_GetStatus(&ackStatus);

            switch (ackStatus.ConnectivityState)
            {
            case ACK_CONNECTIVITY_UNKNOWN:
                // Error issuing the command. Really this should result in UNAVAILABLE state but
                // we don't want to preclude checking state in the future, so we put ourselves back in
                // BOOTED state (there's no need to send host config again).
                newState = ACK_LIFECYCLE_BOOTED;
                sg_needToSendHostConfig = false;
                break;

            case ACK_NOT_REGISTERED:
                newState = ACK_LIFECYCLE_NOT_REGISTERED;
                break;

            case ACK_IN_SETUP_MODE:
                newState = ACK_LIFECYCLE_IN_SETUP_MODE;
                ACK_LifecycleSubStateInfo.InSetupMode = ackStatus.SubStateInfo.InSetupMode;
                break;

            case ACK_NOT_CONNECTED_TO_ALEXA:
                newState = ACK_LIFECYCLE_NOT_CONNECTED_TO_ALEXA;
                break;

            case ACK_CONNECTED_TO_ALEXA:
                newState = ACK_LIFECYCLE_CONNECTED_TO_ALEXA;
                break;
            }

            SetLifecycleState(newState);
        }
    }
}

static void SetLifecycleState(ACKLifecycleState_t newState)
{
    if (newState != ACK_LifecycleState)
    {
        ACK_LifecycleState = newState;

        ACK_REENTRY_SHIELDS_UP;
        ACKUser_OnLifecycleStateChange();
        ACK_REENTRY_SHIELDS_DOWN;

        #ifdef ACK_VALIDATION
        {
            char stateStr[6];
            snprintf(stateStr, sizeof(stateStr), "%"PRIu16, newState);
            VALIDATION_SEND_MARKER(ACK_MARKER_LIFECYCLE_STATE, stateStr, NULL);
        }
        #endif        
    }
}

// Call we get when the ACK Connectivity Module is requesting to be rebooted.
// If forced, reboot will occur soon (more or less immediately). If not, reboot will occur later when
// the device is not in use.
void LifecycleModuleRequestingReboot(bool force)
{
    ACK_DEBUG_PRINT_I(
        "The Connectivity Module is requesting to be rebooted (%s).",
        force ? "forced" : "not forced");

    // Remember that a reboot has been requested, but don't inadvertently downgrade an existing forced
    // request to a non-forced one.
    if (force)
    {
        sg_ackModuleRebootPending = ACK_PENDING_REBOOT_PENDING;
    }
    else if (ACK_PENDING_REBOOT_PENDING != sg_ackModuleRebootPending)
    {
        sg_ackModuleRebootPending = ACK_PENDING_REBOOT_DEFERRABLE;
    }
}

// Call we get when the ACK Connectivity Module has completed booting/rebooting.
// If there's a factory reset in progress, this event indicates that the factory reset is now complete.
void LifecycleModuleBooted(void)
{
    ACK_DEBUG_PRINT_I("Connectivity Module finished booting or rebooting.");

    if (ACK_LIFECYCLE_FACTORY_RESET_IN_PROGRESS == ACK_LifecycleState)
    {
        ACK_DEBUG_PRINT_I("Connectivity Module factory reset complete.");
    }

    // Module is now booted. Need to send host config.
    sg_needToSendHostConfig = true;

    SetLifecycleState(ACK_LIFECYCLE_BOOTED);
}

// Call we get when the ACK Connectivity Module requests a factory reset.
void LifecycleFactoryResetRequested(void)
{
    ACK_DEBUG_PRINT_I("Factory reset requested.");

    sg_ackModuleInitiatedFactoryReset = true;
}

#ifdef ACK_HOST_FIRMWARE_UPDATE

// Called when the ACK Connectivity Module has received an update for the Host.
void LifecycleHostFirmwareUpdateReceived(
    const char* pVersion,
    const char* pSignature,
    uint32_t size,
    bool force)
{
    _CLEAR_OTA_IN_PROGRESS;

    // Sanity check the image. We need to have some data in it.
    if (size <= sizeof(ACKHostFirmwareUpdateImageHeader_t))
    {
        ACK_DEBUG_PRINT_E("Host firmware update of size %"PRIu32" ignored; too small.", size);
        return;
    }

    ACK_DEBUG_PRINT_I("A host firmware update of size %"PRIu32" is available.", size);

    // Persist information about the update, so that we can retrieve and process it later on.
    g_otaState.ImageSize = size;
    g_otaState.RetrieveRemaining = size;
    g_otaState.ChunkReadFailureCount = 0;
    g_otaState.Force = (0 != force);
    g_otaState.ApplicationPending = false;
    g_otaState.StartedPlatform = false;
}

#endif

#ifdef ACK_MODULE_DIAGNOSTICS

// Main routine to dump all module diagnostic info.
void DebugPrintModuleDiagnosticInfo(void)
{
    DebugPrintDeviceType();
    DebugPrintFirmwareVersion();
    DebugPrintHardwareInfo();
    DebugPrintProvisioningInfo();
}

// Dumps module device type diagnostic information to the debug port.
static void DebugPrintDeviceType(void)
{
#ifdef ACK_DEBUG_PRINT_LEVEL
    char deviceType[ACK_DEVICE_TYPE_LENGTH];
    ACKError_t retval;

    retval = ACK_GetDeviceType(deviceType, sizeof(deviceType));
    if (ACK_NO_ERROR != retval)
    {
        ACK_DEBUG_PRINT_E("Unable to retrieve module device type diagnostic info (err %u)", retval);
        return;
    }

    ACK_DEBUG_PRINT_I("Module diagnostic device type: %s", deviceType);
#endif
}

// Dumps module firmware version diagnostic information to the debug port.
static void DebugPrintFirmwareVersion(void)
{
#ifdef ACK_DEBUG_PRINT_LEVEL
    uint32_t protocolNumber;
    uint32_t buildNumber;
    char incrementalVersion[ACK_INCREMENTAL_FIRMWARE_VERSION_LENGTH];
    ACKError_t retval;

    retval = ACK_GetFirmwareVersion(
        &protocolNumber,
        &buildNumber,
        incrementalVersion,
        sizeof(incrementalVersion));

    if (ACK_NO_ERROR != retval)
    {
        ACK_DEBUG_PRINT_E("Unable to retrieve module firmware diagnostic info (err %u)", retval);
        return;
    }

    ACK_DEBUG_PRINT_I(
        "Module diagnostic firmware version: protocol %u, build %u, incremental version %s",
        protocolNumber,
        buildNumber,
        incrementalVersion);
#endif
}

// Dumps module hardware diagnostic information to the debug port.
static void DebugPrintHardwareInfo(void)
{
#ifdef ACK_DEBUG_PRINT_LEVEL
    char dsn[ACK_DSN_LENGTH];
    ACKError_t retval;

    retval = ACK_GetHardwareInfo(dsn, sizeof(dsn));
    if (ACK_NO_ERROR != retval)
    {
        ACK_DEBUG_PRINT_E("Unable to retrieve module hardware diagnostic info (err %u)", retval);
        return;
    }

    ACK_DEBUG_PRINT_I("Module DSN: %s", dsn);
#endif
}

// Dumps module provisioning diagnostic information to the debug port.
static void DebugPrintProvisioningInfo(void)
{
#ifdef ACK_DEBUG_PRINT_LEVEL
    acp_response_provisioning_provisioning_state provisioningState;
    ACKError_t retval;

    retval = ACK_GetProvisioningInfo(&provisioningState);
    if (ACK_NO_ERROR != retval)
    {
        ACK_DEBUG_PRINT_E("Unable to retrieve provisioning info (err %u)", retval);
        return;
    }

    ACK_DEBUG_PRINT_I("Module provisioning state: %u", provisioningState);
#endif
}

#endif // def ACK_MODULE_DIAGNOSTICS
