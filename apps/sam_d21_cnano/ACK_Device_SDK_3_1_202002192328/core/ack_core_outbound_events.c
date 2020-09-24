/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#include "ack.h"
#include "ack_cooking.h"
#include "ack_core_alexa_namespace.h"
#include "ack_core_common.h"
#include "ack_core_endpointhealth.h"
#include "ack_core_event_builder.h"
#include "ack_core_outbound_events.h"
#include "ack_core_processevent.h"
#include "ack_user_config.h"
#include <inttypes.h>

ACKOutboundEventInfo_t g_pendingOutboundEvent = {0};

static ACKError_t AddPropertiesAndSend_(void);
static void AddProperties_(void);

void OutboundEventReset(void)
{
    g_pendingOutboundEvent.Flags.All = 0;
    g_pendingOutboundEvent.PropertiesBits = 0;
    g_pendingOutboundEvent.ChangeReportPayloadPropertiesBits = 0;
}

// If we're not currently processing an inbound event, send any pending outbound event.
// If we are currently processing an inbound event, an outbound event can't be sent now. Instead,
// the lifecycle code will send any pending outbound event, once it's safe to do so.
ACKError_t OutboundEventSendIfNotProcessingInboundEvent(void)
{
    return g_inboundEventInfo.Bits.Processing ? ACK_NO_ERROR : OutboundEventSend();
}

ACKError_t OutboundEventSend(void)
{
    ACKError_t retval;

    // If there's no event pending, nothing to do.
    if (g_pendingOutboundEvent.Flags.Bits.EventPending)
    {
        retval = AddPropertiesAndSend_();
        if (ACK_NO_ERROR != retval)
        {
            ACK_DEBUG_PRINT_E("Unable to send event.");
            goto cleanup0;
        }

        // Synthesize change report if needed.
        if (g_pendingOutboundEvent.Flags.Bits.SynthesizeChangeReport
            && g_pendingOutboundEvent.ChangeReportPayloadPropertiesBits)
        {
            ACK_DEBUG_PRINT_D("Synthesizing change report event.");

            retval = AlexaNamespaceStartChangeReportEvent(
                v3avs_capabilities_V3Alexa_Cause_CauseType_VOICE_INTERACTION);
            if (ACK_NO_ERROR != retval)
            {
                ACK_DEBUG_PRINT_E("Error %u starting synthesized change report event.", retval);
                goto cleanup0;
            }

            g_pendingOutboundEvent.Flags.Bits.SynthesizeChangeReport = false;

            retval = AddPropertiesAndSend_();
            if (ACK_NO_ERROR != retval)
            {
                ACK_DEBUG_PRINT_E("Unable to send synthesized change report event.");
                goto cleanup0;
            }
        }
    }

    retval = ACK_NO_ERROR;

cleanup0:
    EventBuilderEnd();
    OutboundEventReset();
    return retval;
}

static ACKError_t AddPropertiesAndSend_(void)
{
    ACKError_t retval;

    AddProperties_();

    retval = EventBuilderSend();
    if (ACK_NO_ERROR != retval)
    {
        ACK_DEBUG_PRINT_E("Error %u sending outbound event.", retval);
        goto cleanup0;
    }

    ACK_DEBUG_PRINT_D("Sent event.");

    retval = ACK_NO_ERROR;

cleanup0:
    return retval;
}

static void AddProperties_(void)
{
    ACKError_t error;
    uint32_t eventPropertyBits;
    uint32_t mapPropertyBit;
    const ACKPropertyTableEntry_t* pPropertiesMapEntry;

    eventPropertyBits = g_pendingOutboundEvent.PropertiesBits;

    if (g_pendingOutboundEvent.Flags.Bits.IsChangeReport)
    {
        // For change reports, make sure that payload properties don't also appear in the event context.
        eventPropertyBits &= ~g_pendingOutboundEvent.ChangeReportPayloadPropertiesBits;
    }

    // Add endpoint health property if needed.
    if (g_pendingOutboundEvent.Flags.Bits.AddEndpointHealthProperty)
    {
        ACKStateCommon_t common =
        {
            0, // Timestamp. No RTC assumed, so leave as 0.
            10, // Uncertainty (milliseconds).
            0 // These always go in context, not payload, so ACK_PROPERTY_CHANGE_REPORT_PAYLOAD isn't set.
        };

        // Best effort.
        error = EndpointHealthAddPropertyToEvent(&common);
        if (ACK_NO_ERROR != error)
        {
            ACK_DEBUG_PRINT_W("Error %u adding endpoint health property to event.", error);
        }
    }

    pPropertiesMapEntry = ACKUser_PropertyTable;

    while (pPropertiesMapEntry->AddPropertiesRoutine)
    {
        mapPropertyBit = ACK_PROPERTY_BIT(pPropertiesMapEntry->PropertyOrdinal);

        if (eventPropertyBits & mapPropertyBit)
        {
            // Best effort.
            if (!pPropertiesMapEntry->AddPropertiesRoutine(pPropertiesMapEntry->PropertyOrdinal, 0))
            {
                ACK_DEBUG_PRINT_W(
                    "Unable to add properties (ordinal %u) to event.",
                    pPropertiesMapEntry->PropertyOrdinal);
            }
        }

        if (g_pendingOutboundEvent.Flags.Bits.IsChangeReport
            && (g_pendingOutboundEvent.ChangeReportPayloadPropertiesBits & mapPropertyBit))
        {
            // Best effort.
            if (!pPropertiesMapEntry->AddPropertiesRoutine(
                pPropertiesMapEntry->PropertyOrdinal,
                ACK_PROPERTY_CHANGE_REPORT_PAYLOAD))
            {
                ACK_DEBUG_PRINT_W(
                    "Unable to add change report payload properties (ordinal %u) to event.",
                    pPropertiesMapEntry->PropertyOrdinal);
            }
        }

        ++pPropertiesMapEntry;
    }
}
