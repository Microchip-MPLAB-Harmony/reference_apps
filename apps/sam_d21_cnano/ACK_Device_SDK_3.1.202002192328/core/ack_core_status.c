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
#include "ack_core_heaplet.h"
#include "ack_user_platform.h"
#include <stdint.h>

// These represent the posix epoch most recently returned from a get-status ACP command (in seconds),
// and the local tick count (elapsed milliseconds since boot) at the time that most recent get-status
// ACP command completed. These are used by ACK_GetApproximateTime.
uint32_t g_realTimeEpochBaseSeconds = 0;
uint32_t g_realTimeTickBase = 0;

void ACK_GetStatus(ACKStatus_t* pStatus)
{
    acp_response* pRespStatus;
    ACKError_t retval;
    acp_response_get_ack_status* pStatusResponse;

    ACK_REENTRY_CHECK;

    ACK_DEBUG_PRINT_D("Sending get-status command.");

    // Send command and get response into MEM_RECEIVED_ENCODED_ACP_RESPONSE and MEM_RECEIVED_ACP_RESPONSE.
    retval = CommonAllocAndSendAcpCmdAndGetAcpResponse(acp_cmd_get_ack_status_obj_tag);
    if (ACK_NO_ERROR != retval)
    {
        ACK_DEBUG_PRINT_E("Send acp_cmd and get and decode acp_response failed, err %u", retval);
        goto cleanup0;
    }

    pRespStatus = (acp_response*)HeapletAccess(MEM_RECEIVED_ACP_RESPONSE);

    if (pRespStatus->which_type == acp_response_generic_obj_tag)
    {
        ACK_DEBUG_PRINT_E("Received generic error response %u", pRespStatus->type.generic_obj.code);
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    if (pRespStatus->which_type != acp_response_get_ack_status_obj_tag)
    {
        ACK_DEBUG_PRINT_E(
            "Incorrect response. Expected get_ProcessEventState_status response. Instead got %u.",
            pRespStatus->which_type);
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    // Fill out the output struct.
    pStatusResponse = &pRespStatus->type.get_ack_status_obj;

    pStatus->HH = (int)pStatusResponse->current_time.hh;
    pStatus->MM = (int)pStatusResponse->current_time.mm;
    pStatus->SS = (int)pStatusResponse->current_time.ss;
    pStatus->EpochSeconds = pStatusResponse->epoch_seconds;

    pStatus->SubStateInfo.InSetupMode.SetupStage = acp_setup_stages_none;
    pStatus->SubStateInfo.InSetupMode.IsUserGuidedSetupActive = 0;
    pStatus->SubStateInfo.InSetupMode.IsBarcodeScanSetupActive = 0;
    pStatus->SubStateInfo.InSetupMode.IsZeroTouchSetupActive = 0;

    if (pStatusResponse->setup_stage == acp_setup_stages_timeout)
    {
        // Timeout indicates ACK_NOT_REGISTERED and takes priority over other values.
        pStatus->ConnectivityState = ACK_NOT_REGISTERED;
    }
    else if (pStatusResponse->setup_mode)
    {
        pStatus->ConnectivityState = ACK_IN_SETUP_MODE;

        // Set the setup type if present by prioritized order and determined by
        // the lowest set bit in the setup_types field.
        pStatus->SubStateInfo.InSetupMode.IsUserGuidedSetupActive =
            (pStatusResponse->setup_types & acp_setup_types_ugs) ? 1 : 0;
        pStatus->SubStateInfo.InSetupMode.IsBarcodeScanSetupActive =
            (pStatusResponse->setup_types & acp_setup_types_bcs) ? 1 : 0;
        pStatus->SubStateInfo.InSetupMode.IsZeroTouchSetupActive =
            (pStatusResponse->setup_types & acp_setup_types_zts) ? 1 : 0;

        pStatus->SubStateInfo.InSetupMode.SetupStage = pStatusResponse->setup_stage;
    }
    else
    {
        pStatus->ConnectivityState = (acp_wifi_mode_connected == pStatusResponse->wifi_mode)
            ? ACK_CONNECTED_TO_ALEXA
            : ACK_NOT_CONNECTED_TO_ALEXA;
    }

    pStatus->ErrorCode = pStatusResponse->error_code;

    retval = ACK_NO_ERROR;

cleanup0:
    CommonFreeAcpResponse();

    if (ACK_NO_ERROR != retval)
    {
        pStatus->HH = -1;
        pStatus->MM = -1;
        pStatus->SS = -1;
        pStatus->EpochSeconds = 0;

        pStatus->ConnectivityState = ACK_CONNECTIVITY_UNKNOWN;

        pStatus->ErrorCode = acp_response_error_codes_no_error;
    }

    // Store the information that allows ACK_GetApproximateTime to work. In case of error sending the
    // get-status command, or if the epoch value wasn't known, pStatus->EpochSeconds is 0, causing
    // ACK_GetApproximateTime to return a not-known value. This is what we want.
    g_realTimeEpochBaseSeconds = pStatus->EpochSeconds;
    g_realTimeTickBase = ACKPlatform_TickCount();
}

uint64_t ACK_GetApproximateTime(void)
{
    // Note: this relies heavily on the lifecycle code (AckProcess) calling ACK_GetStatus frequently enough
    // to not have the tick count wrap (49.7 days). That's a safe bet because by design there isn't any way
    // to consume this codebase other than by calling ACK_Process from the main loop.
    return (g_realTimeEpochBaseSeconds && g_realTimeTickBase)
        ? ((1000 * (uint64_t)g_realTimeEpochBaseSeconds) + (ACKPlatform_TickCount() - g_realTimeTickBase))
        : 0;
}
