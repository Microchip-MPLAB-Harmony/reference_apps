/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#include "ack_core_common.h"
#include "ack_core_communication.h"
#include "ack_core_directives.h"
#include "ack_core_event_builder.h"
#include "ack_core_heaplet.h"
#include "ack_core_lifecycle.h"
#include "ack_core_ota.h"
#include "ack_core_processevent.h"
#include "ack_core_protobuf_utilities.h"
#include "ack_core_validation.h"
#include "ack_user_config.h"
#include "acp.pb.h"
#include "ack_logging.h"
#include "ack_user_platform.h"
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include "v3avs_capabilities/V3Alexa.pb.h"

// Event processing advances through a series of states to avoid deep call trees and
// excessive stack usage.
typedef enum ProcessEventState
{
    ProcessEventState_ReceiveNextEvent,
    ProcessEventState_DirectiveExtractEncodedPayload,
    ProcessEventState_DirectiveProcess,
    ProcessEventState_ReceivedBootedEvent,
    ProcessEventState_ModuleReqestingRebootEvent,
    ProcessEventState_ReceivedFactoryResetEvent,
#ifdef ACK_HOST_FIRMWARE_UPDATE
    ProcessEventState_HostFirmwareUpdateReceived,
#endif
#ifdef ACK_LOGGING
    ProcessEventState_LogLevelChangedEvent,
#endif
    ProcessEventState_Max
}
ProcessEventState_t;

static ACKError_t ProcessNextEvent_(void);
static ACKError_t ProcessEventState_ReceiveNextEvent_(void);
static ACKError_t ProcessEventState_DirectiveExtractEncodedPayload_(void);
static ACKError_t ProcessEventState_DirectiveProcess_(void);
static ACKError_t ProcessEventState_ReceivedBootedEvent_(void);
static ACKError_t ProcessEventState_ModuleRequestingRebootEvent_(void);
static ACKError_t ProcessEventState_ReceivedFactoryResetEvent_(void);
#ifdef ACK_LOGGING
static ACKError_t ProcessEventState_LogLevelChangedEvent_(void);
#endif

#ifdef ACK_HOST_FIRMWARE_UPDATE
static ACKError_t ProcessEventState_HostFirmwareUpdateReceived_(void);
#endif

typedef ACKError_t (*ProcessEventStateProcessor)(void);

// When assertions are turned on, after processing each state we check the heaplet to ensure that only
// the memory we expect to be allocated is actually allocated.
typedef struct StateContext
{
    ProcessEventStateProcessor m_processor;
}
StateContext_t;

#define STATE(n) { ProcessEventState_##n##_ }

static const StateContext_t sg_processEventStateProcessors[] =
{
    STATE(ReceiveNextEvent),
    STATE(DirectiveExtractEncodedPayload),
    STATE(DirectiveProcess),
    STATE(ReceivedBootedEvent),
    STATE(ModuleRequestingRebootEvent),
    STATE(ReceivedFactoryResetEvent)
#ifdef ACK_HOST_FIRMWARE_UPDATE
   ,STATE(HostFirmwareUpdateReceived)
#endif
#ifdef ACK_LOGGING
   ,STATE(LogLevelChangedEvent)
#endif
};

static ProcessEventState_t sg_state;

ACKInboundEventInfo_t g_inboundEventInfo = {{0}};

ACKError_t ProcessEventIfAvailable(void)
{
    ACKError_t retval = ACK_NO_ERROR;

    g_inboundEventInfo.Bits.ProcessedDirective = false;

    if (ACK_IsHostInterruptAsserted())
    {
        ACK_DEBUG_PRINT_I("HOSTINT asserted; processing inbound event.");
			
        g_inboundEventInfo.Bits.Processing = true;

        retval = ProcessNextEvent_();
    }

    g_inboundEventInfo.Bits.Processing = false;

    return retval;
}

static ACKError_t ProcessNextEvent_(void)
{
    ACKError_t retval = ACK_NO_ERROR;

    // Because of the way memory is managed, we can't process an inbound event if there's an outbound one
    // pending. In some cases, user code may legitimately call ACK_Complete* but the event never got
    // sent. To avoid the need for an explicit ACK_AbandonEvent, we just remove any pending event here.
#ifdef ACK_EVENT_BUILDER_DIAG
    if (EventBuilderIsEventBeingBuilt())
    {
        ACK_DEBUG_PRINT_W("Deleting unsent pending outgoing event.");
    }
#endif
    EventBuilderEnd();

    sg_state = ProcessEventState_ReceiveNextEvent;

    while ((ProcessEventState_Max != sg_state) && (ACK_NO_ERROR == retval))
    {
        retval = sg_processEventStateProcessors[sg_state].m_processor();
    }

#ifdef ACK_MEMORY_DIAG
    // Make sure we didn't leak memory. However an ACKUser_xxx callback may have started an
    // outbound event, so allow that. That includes at most MEM_OUTBOUND_EVENT_ENCODED_PROPERTY_DATA
    // and MEM_OUTBOUND_EVENT_ACP_STRUCT.
    {
        HeapletTag_t tags[25];
        bool tagsOk;
        unsigned i;

        // Tag count returned from HeapletGetBlocksInUse includes the terminating MEM_NONE.
        size_t tagCount = HeapletGetBlocksInUse(tags, ACK_COUNTOF(tags));

        tagsOk = (1 == tagCount) // must be MEM_NONE
                    || ((2 == tagCount)
                        && (MEM_OUTBOUND_EVENT_ACP_STRUCT == tags[0])
                        && (MEM_NONE == tags[1]))
                    || ((3 == tagCount)
                        && (MEM_OUTBOUND_EVENT_ENCODED_PROPERTY_DATA == tags[0])
                        && (MEM_OUTBOUND_EVENT_ACP_STRUCT == tags[1])
                        && (MEM_NONE == tags[2]));

        if (!tagsOk)
        {
            if (tagCount > ACK_COUNTOF(tags))
            {
                tagCount = ACK_COUNTOF(tags);
            }

            for (i = 0; i < tagCount; ++i)
            {
                ACK_DEBUG_PRINT_I("At least block leaked: tag %u", tags[i]);
            }

            ACK_ASSERT(!"Processing incoming event leaked memory!");
        }
    }
#endif

    return retval;
}

// Processes the state wherein we send a request for the next event and read a response.
// At the end of this state, MEM_RECEIVED_ACP_RESPONSE contains the decoded acp_response.
// The next state depends on what kind of event we received.
static ACKError_t ProcessEventState_ReceiveNextEvent_(void)
{
    acp_response* pResponse;
    ACKError_t retval;

    retval = CommonAllocAndSendAcpCmdAndGetAcpResponse(acp_cmd_get_next_event_obj_tag);
    if (ACK_NO_ERROR != retval)
    {
        ACK_DEBUG_PRINT_E("Send acp_cmd and get and decode acp_response failed, err %u.", retval);
        goto cleanup0;
    }

    pResponse = (acp_response*)HeapletAccess(MEM_RECEIVED_ACP_RESPONSE);

    // Advance to next state, which depends on the kind of event.
    switch (pResponse->which_type)
    {
    case acp_response_alexa_directive_received_obj_tag:
        ACK_DEBUG_PRINT_I("Received Alexa directive.")
        sg_state = ProcessEventState_DirectiveExtractEncodedPayload;
        break;

    case acp_response_ack_booted_obj_tag:
        ACK_DEBUG_PRINT_I("Received connectivity module booted event.")
        sg_state = ProcessEventState_ReceivedBootedEvent;
        break;

    case acp_response_reboot_requested_obj_tag:
        ACK_DEBUG_PRINT_I("Received event indicating ACK connectivity module is requesting to be rebooted.")
        sg_state = ProcessEventState_ModuleReqestingRebootEvent;
        break;

    case acp_response_factory_reset_requested_obj_tag:
        ACK_DEBUG_PRINT_I("Received event indicating that host should factory reset itself.")
        sg_state = ProcessEventState_ReceivedFactoryResetEvent;
        break;

#ifdef ACK_HOST_FIRMWARE_UPDATE
    case acp_response_host_fw_update_received_obj_tag:
        ACK_DEBUG_PRINT_I("Received host firmware update received event.")
        sg_state = ProcessEventState_HostFirmwareUpdateReceived;
        break;
#endif

#ifdef ACK_LOGGING
    case acp_response_log_level_changed_obj_tag:
        ACK_DEBUG_PRINT_I("Received log level changed event.");
        sg_state = ProcessEventState_LogLevelChangedEvent;
        break;
#endif

    case 0:
        // This can happen when
        // (a) the payload is omitted for some reason at the sending end (unlikely). The tag was sent as 0.
        // (b) we simply don't have handling for the tag we received. The tag became 0 when decoded.
        // We simply ignore these messages.
        ACK_DEBUG_PRINT_D("Ignored message with no payload.");
        sg_state = ProcessEventState_Max;
        break;

    default:
        // Unknown message. This happens when the payload is something we understand and could
        // potentially handle, but for some reason we didn't code.
        ACK_DEBUG_PRINT_W("Event of acp_response type %u not handled.", pResponse->which_type);
        sg_state = ProcessEventState_Max;
        break;
    }

    retval = ACK_NO_ERROR;

cleanup0:
    // Upon error we don't want MEM_RECEIVED_ACP_RESPONSE, but the only error path above means that it won't
    // have been allocated, so we don't call HeapletFree(MEM_RECEIVED_ACP_RESPONSE) here.
    if ((ACK_NO_ERROR != retval) || (ProcessEventState_Max == sg_state))
    {
        CommonFreeAcpResponse();
    }

    return retval;
}

// Processes the state wherein we find the directive payload, which will be nested inside the
// encoded event data we originally received.
// At the end of this state,
// * MEM_RECEIVED_AVS_DIRECTIVE_ENVELOPE contains the V3AVS_AvsDirective from the acp_response
// * MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD contains the extracted encoded directive payload
// and
// * MEM_RECEIVED_ENCODED_ACP_RESPONSE has been freed
// * MEM_RECEIVED_ACP_RESPONSE has been freed
static ACKError_t ProcessEventState_DirectiveExtractEncodedPayload_(void)
{
    acp_event_alexa_directive_received* pDirective;
    bool protoResult;
    ACKError_t retval;
    void* pEncodedPayload;
    V3AVS_AvsDirective* pDirectiveHeader;
    ProtobufCallbackField_t field = {0};

    pDirective
        = &((acp_response*)HeapletAccess(MEM_RECEIVED_ACP_RESPONSE))->type.alexa_directive_received_obj;
    pDirective->directive.payload.funcs.decode = ProtobufDecodeCallbackField;
    pDirective->directive.payload.arg = &field;

    // 'Decode' here means that we get a pointer to the still-encoded submessage, within the original
    // encoded event.
    protoResult = ProtobufDecodeSubmessage(
        HeapletAccess(MEM_RECEIVED_ENCODED_ACP_RESPONSE),
        HeapletGetSize(MEM_RECEIVED_ENCODED_ACP_RESPONSE),
        acp_response_alexa_directive_received_obj_tag,
        acp_event_alexa_directive_received_fields,
        pDirective);
    if (!protoResult)
    {
        ACK_DEBUG_PRINT_E("Unable to decode directive submessage.");
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    // Field length can legitimately be 0, but HeapletSetSize returns a valid block in such cases.
    pEncodedPayload = HeapletSetSize(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD, field.Length);
    if (NULL == pEncodedPayload)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    memcpy(pEncodedPayload, field.Value, field.Length);

    // The original event data is no longer needed, since we have now extracted from it both the
    // acp_response header and the directive payload at this point.
    HeapletFree(MEM_RECEIVED_ENCODED_ACP_RESPONSE);

    // Extract the V3AVS_AvsDirective from the acp_response, and throw away the acp_response.
    // !!! Note: Due to HeapletSetSize and HeapletFree above, and the alloc we're about to do here,
    // no pointers to Heaplet blocks are valid at this point, and we must re-access the acp_response. !!!
    pDirectiveHeader = (V3AVS_AvsDirective*)HeapletSetSize(
        MEM_RECEIVED_AVS_DIRECTIVE_ENVELOPE,
        sizeof(V3AVS_AvsDirective));
    if (NULL == pDirectiveHeader)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    pDirective
        = &((acp_response*)HeapletAccess(MEM_RECEIVED_ACP_RESPONSE))->type.alexa_directive_received_obj;
    *pDirectiveHeader = pDirective->directive;

    ACK_DEBUG_PRINT_I(
        "Received directive; correlation id %"PRId32", namespace %u",
        pDirective->directive.correlation_id,
        pDirective->directive.v3_namespace);

    // Advance to next state.
    sg_state = ProcessEventState_DirectiveProcess;
    retval = ACK_NO_ERROR;

cleanup0:
    // The original acp_response and decoded form are no longer needed.
    CommonFreeAcpResponse();

    if (ACK_NO_ERROR != retval)
    {
        HeapletFree(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD);
        HeapletFree(MEM_RECEIVED_AVS_DIRECTIVE_ENVELOPE);
    }

    return retval;
}

// Processes the state wherein a directive-specific handler is called to actually perform the processing
// associated with a directive.
// At the end of this state,
//  - MEM_RECEIVED_AVS_DIRECTIVE_ENVELOPE and MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD have been freed.
// The next state is completion.
static ACKError_t ProcessEventState_DirectiveProcess_(void)
{
    ACKError_t retval;

    // Directive-specific processing.
    switch (((V3AVS_AvsDirective*)HeapletAccess(MEM_RECEIVED_AVS_DIRECTIVE_ENVELOPE))->v3_namespace)
    {
    case V3AVS_Namespace_V3_ALEXA:
        retval = HandleAlexaInterfaceDirective();
        break;

#ifdef ACK_BRIGHTNESS_CONTROLLER
    case V3AVS_Namespace_V3_ALEXA_BRIGHTNESS_CONTROLLER:
        ACK_DEBUG_PRINT_I("Directive is for brightness controller.");
        retval = HandleBrightnessControllerDirective();
        break;
#endif

#ifdef ACK_COLOR_CONTROLLER
    case V3AVS_Namespace_V3_ALEXA_COLOR_CONTROLLER:
        ACK_DEBUG_PRINT_I("Directive is for color controller.");
        retval = HandleColorControllerDirective();
        break;
#endif

#ifdef ACK_COLOR_TEMPERATURE_CONTROLLER
    case V3AVS_Namespace_V3_ALEXA_COLOR_TEMPERATURE_CONTROLLER:
        ACK_DEBUG_PRINT_I("Directive is for color temperature controller.");
        retval = HandleColorTemperatureControllerDirective();
        break;
#endif

#ifdef ACK_COOKING
    case V3AVS_Namespace_V3_ALEXA_COOKING_CONTROLLER:
        ACK_DEBUG_PRINT_I("Directive is for cooking controller.");
        retval = HandleCookingControllerDirective();
        break;
#endif

#ifdef ACK_COOKING_FOOD_TEMPERATURE_CONTROLLER
    case V3AVS_Namespace_V3_ALEXA_FOOD_TEMPERATURE_COOKING_CONTROLLER:
        ACK_DEBUG_PRINT_I("Directive is for cooking food temperature controller.");
        retval = HandleCookingFoodTemperatureControllerDirective();
        break;
#endif

#ifdef ACK_COOKING_PRESET_CONTROLLER
    case V3AVS_Namespace_V3_ALEXA_COOKING_PRESET_CONTROLLER:
        ACK_DEBUG_PRINT_I("Directive is for cooking preset controller.");
        retval = HandleCookingPresetControllerDirective();
        break;
#endif

#ifdef ACK_COOKING_TEMPERATURE_CONTROLLER
    case V3AVS_Namespace_V3_ALEXA_COOKING_TEMPERATURE_CONTROLLER:
        ACK_DEBUG_PRINT_I("Directive is for cooking temperature controller.");
        retval = HandleCookingTemperatureControllerDirective();
        break;
#endif

#ifdef ACK_COOKING_TIME_CONTROLLER
    case V3AVS_Namespace_V3_ALEXA_COOKING_TIME_CONTROLLER:
        ACK_DEBUG_PRINT_I("Directive is for cooking time controller.");
        retval = HandleCookingTimeControllerDirective();
        break;
#endif

#ifdef ACK_MODE_CONTROLLER
    case V3AVS_Namespace_V3_ALEXA_MODE_CONTROLLER:
        ACK_DEBUG_PRINT_I("Directive is for mode controller.");
        retval = HandleModeControllerDirective();
        break;
#endif

#ifdef ACK_POWER_CONTROLLER
    case V3AVS_Namespace_V3_ALEXA_POWER_CONTROLLER:
        ACK_DEBUG_PRINT_I("Directive is for power controller.");
        retval = HandlePowerControllerDirective();
        break;
#endif

#ifdef ACK_PERCENTAGE_CONTROLLER
    case V3AVS_Namespace_V3_ALEXA_PERCENTAGE_CONTROLLER:
        ACK_DEBUG_PRINT_I("Directive is for percentage controller.");
        retval = HandlePercentageControllerDirective();
        break;
#endif

#ifdef ACK_RANGE_CONTROLLER
    case V3AVS_Namespace_V3_ALEXA_RANGE_CONTROLLER:
        ACK_DEBUG_PRINT_I("Directive is for range controller.");
        retval = HandleRangeControllerDirective();
        break;
#endif

#ifdef ACK_TIME_HOLD_CONTROLLER
    case V3AVS_Namespace_V3_ALEXA_TIME_HOLD_CONTROLLER:
        ACK_DEBUG_PRINT_I("Directive is for time hold controller.");
        retval = HandleTimeHoldControllerDirective();
        break;
#endif

#ifdef ACK_TOGGLE_CONTROLLER
    case V3AVS_Namespace_V3_ALEXA_TOGGLE_CONTROLLER:
        ACK_DEBUG_PRINT_I("Directive is for toggle controller.");
        retval = HandleToggleControllerDirective();
        break;
#endif

    default:
        ACK_DEBUG_PRINT_W(
            "Unhandled directive, namespace %u.",
            ((V3AVS_AvsDirective*)HeapletAccess(MEM_RECEIVED_AVS_DIRECTIVE_ENVELOPE))->v3_namespace);
        retval = ACK_ERR_PROTOCOL;
        break;
    }

    if (ACK_NO_ERROR != retval)
    {
        ACK_DEBUG_PRINT_E("Directive-specific processing failed, err %u.", retval);
        goto cleanup0;
    }

    g_inboundEventInfo.Bits.ProcessedDirective = true;

    // Advance to completion state.
    sg_state = ProcessEventState_Max;
    retval = ACK_NO_ERROR;

cleanup0:
    // We no longer need the outer directive or the directive payload.
    HeapletFree(MEM_RECEIVED_AVS_DIRECTIVE_ENVELOPE);
    HeapletFree(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD);

    return retval;
}

// Processes the state wherein we've received a booted event.
static ACKError_t ProcessEventState_ReceivedBootedEvent_(void)
{
    // The original acp_response and decoded form are no longer needed.
    CommonFreeAcpResponse();

    // Advance the lifecycle.
    LifecycleModuleBooted();

    // Done.
    sg_state = ProcessEventState_Max;
    return ACK_NO_ERROR;
}

// Processes the state wherein we've received a request from the connectivity module to be rebooted.
static ACKError_t ProcessEventState_ModuleRequestingRebootEvent_(void)
{
    bool force;

    force = ((acp_response*)HeapletAccess(MEM_RECEIVED_ACP_RESPONSE))->type.reboot_requested_obj.force;

    // The original acp_response and decoded form are now no longer needed.
    CommonFreeAcpResponse();

    // Advance the lifecycle.
    LifecycleModuleRequestingReboot(force);

    // Done.
    sg_state = ProcessEventState_Max;
    return ACK_NO_ERROR;
}

// Processes the state wherein we've received a factory reset event.
static ACKError_t ProcessEventState_ReceivedFactoryResetEvent_(void)
{
    // The original acp_response and decoded form are no longer needed.
    CommonFreeAcpResponse();

    // Advance the lifecycle.
    LifecycleFactoryResetRequested();

    // Done.
    sg_state = ProcessEventState_Max;
    return ACK_NO_ERROR;
}

#ifdef ACK_HOST_FIRMWARE_UPDATE

// Processes the state wherein we've received an update firmware event.
static ACKError_t ProcessEventState_HostFirmwareUpdateReceived_(void)
{
    acp_event_host_fw_update_received* pUpdateInfo;
    ACKError_t retval;

    ACK_DEBUG_PRINT_D("Calling host FW update received event handler.");

    pUpdateInfo
        = &((acp_response*)HeapletAccess(MEM_RECEIVED_ACP_RESPONSE))->type.host_fw_update_received_obj;

    // Data we received can't be completely trusted. The two strings are of particular interest;
    // make sure they are terminated.
    ACK_STATIC_ASSERT(sizeof(pUpdateInfo->version) > 0);
    pUpdateInfo->version[sizeof(pUpdateInfo->version) - 1] = '\0';

    ACK_STATIC_ASSERT(sizeof(pUpdateInfo->signature) > 0);
    pUpdateInfo->signature[sizeof(pUpdateInfo->signature) - 1] = '\0';

    // Advance the lifecycle.
    LifecycleHostFirmwareUpdateReceived(
        pUpdateInfo->version,
        pUpdateInfo->signature,
        pUpdateInfo->size,
        pUpdateInfo->force);

    // Done.
    sg_state = ProcessEventState_Max;
    retval = ACK_NO_ERROR;

// There is no error path, so no need for this label.
//cleanup0:
    CommonFreeAcpResponse();
    return retval;
}

#endif // def ACK_HOST_FIRMWARE_UPDATE

#ifdef ACK_LOGGING

// Processes the state wherein we've received the log level changed event.
static ACKError_t ProcessEventState_LogLevelChangedEvent_(void)
{
    acp_event_log_level_changed* pMessage;
    ACKError_t retval;

    pMessage = &((acp_response*)HeapletAccess(MEM_RECEIVED_ACP_RESPONSE))->type.log_level_changed_obj;
    ACK_DEBUG_PRINT_I("Log level change event received; new level is %u.", pMessage->log_level);

    // Simply adjust the global log level variable.
    ACK_LogLevel = pMessage->log_level;

    sg_state = ProcessEventState_Max;
    retval = ACK_NO_ERROR;

// There is no error path, so no need for this label.
//cleanup0:
    CommonFreeAcpResponse();
    return retval;
}

#endif // ACK_LOGGING
