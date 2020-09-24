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
#include "ack_core_heaplet.h"
#include "ack_core_outbound_events.h"
#include "ack_dash_replenishment.h"
#include <inttypes.h>
#include "v3avs_capabilities/V3AlexaInventoryLevelSensor.pb.h"
#include "v3avs_capabilities/V3AlexaInventoryLevelUsageSensor.pb.h"
#include "v3avs_capabilities/V3AlexaInventoryUsageSensor.pb.h"

#ifdef ACK_DASH_REPLENISHMENT

// Forward references.
static void AckLevelToProtobufLevel_(
    const ACKInventoryLevel_t* pAckLevel,
    v3avs_types_V3Level* pProtobufLevel);

static ACKError_t SendDrsEventSendWorker_(void);

v3avs_capabilities_V3AlexaInventoryUsageSensor_Event* _CreateInventoryUsageEvent(
    uint32_t instance,
    v3avs_capabilities_V3AlexaInventoryUsageSensor_EventName eventName,
    unsigned eventTag);

v3avs_capabilities_V3AlexaInventoryLevelUsageSensor_Event* _CreateInventoryLevelUsageEvent(
    uint32_t instance,
    v3avs_capabilities_V3AlexaInventoryLevelUsageSensor_EventName eventName,
    unsigned eventTag);

static ACKError_t EncodeLevelUsageSensorEvent_(void);
static ACKError_t EncodeUsageSensorEvent_(void);

ACKError_t ACK_AddInventoryLevelProperty(
    uint32_t instance,
    const ACKStateCommon_t* pCommon,
    const ACKInventoryLevel_t* pInventoryLevel)
{
    ACK_REENTRY_CHECK;

    v3avs_capabilities_V3AlexaInventoryLevelSensor_LevelProperty property = { { 0 } };

    AckLevelToProtobufLevel_(pInventoryLevel, &property.level);

    return CommonEncodeContextProperty(
        V3AVS_Namespace_V3_ALEXA_INVENTORY_LEVEL_SENSOR,
        v3avs_capabilities_V3AlexaInventoryLevelSensor_PropertyName_LEVEL_PROP,
        instance,
        pCommon,
        v3avs_capabilities_V3AlexaInventoryLevelSensor_LevelProperty_fields,
        &property);
}

ACKError_t ACK_SendDashReplenishmentUsageConsumedEvent(
    uint32_t instance,
    const ACKInventoryLevel_t* pLevel)
{
    ACKError_t retval;
    v3avs_capabilities_V3AlexaInventoryUsageSensor_Event* pEvent;

    ACK_DEBUG_PRINT_I("Sending Alexa.InventoryUsageSensor consumed event, instance %"PRIu32".", instance);

    ACK_REENTRY_CHECK;

    OutboundEventReset();

    pEvent = _CreateInventoryUsageEvent(
        instance,
        v3avs_capabilities_V3AlexaInventoryUsageSensor_EventName_INVENTORY_CONSUMED,
        v3avs_capabilities_V3AlexaInventoryUsageSensor_Event_inventory_consumed_tag);
    if (NULL == pEvent)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    AckLevelToProtobufLevel_(pLevel, &pEvent->payload.inventory_consumed.inventory_consumed.usage);

    retval = SendDrsEventSendWorker_();
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    // Success.
    retval = ACK_NO_ERROR;

cleanup0:
    EventBuilderEnd();
    return retval;
}

ACKError_t ACK_SendDashReplenishmentLevelUsageConsumedEvent(
    uint32_t instance,
    const ACKInventoryLevel_t* pLevel)
{
    ACKError_t retval;
    v3avs_capabilities_V3AlexaInventoryLevelUsageSensor_Event* pEvent;

    ACK_DEBUG_PRINT_I(
        "Sending Alexa.InventoryLevelUsageSensor consumed event, instance %"PRIu32".",
        instance);

    ACK_REENTRY_CHECK;

    OutboundEventReset();

    pEvent = _CreateInventoryLevelUsageEvent(
        instance,
        v3avs_capabilities_V3AlexaInventoryLevelUsageSensor_EventName_INVENTORY_CONSUMED,
        v3avs_capabilities_V3AlexaInventoryLevelUsageSensor_Event_inventory_consumed_tag);
    if (NULL == pEvent)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    AckLevelToProtobufLevel_(pLevel, &pEvent->payload.inventory_consumed.inventory_consumed.usage);

    retval = SendDrsEventSendWorker_();
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    // Success.
    retval = ACK_NO_ERROR;

cleanup0:
    EventBuilderEnd();
    return retval;
}

ACKError_t ACK_SendDashReplenishmentLevelUsageReplacedEvent(
    uint32_t instance,
    const ACKInventoryLevel_t* pLevel,
    uint64_t replacedDateTime)
{
    ACKError_t retval;
    v3avs_capabilities_V3AlexaInventoryLevelUsageSensor_Event* pEvent;

    ACK_DEBUG_PRINT_I(
        "Sending Alexa.InventoryLevelUsageSensor replaced event, instance %"PRIu32".",
        instance);

    ACK_REENTRY_CHECK;

    OutboundEventReset();

    pEvent = _CreateInventoryLevelUsageEvent(
        instance,
        v3avs_capabilities_V3AlexaInventoryLevelUsageSensor_EventName_INVENTORY_REPLACED,
        v3avs_capabilities_V3AlexaInventoryLevelUsageSensor_Event_inventory_replaced_tag);
    if (NULL == pEvent)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    AckLevelToProtobufLevel_(
        pLevel,
        &pEvent->payload.inventory_replaced.inventory_replaced.new_absolute_level);

    pEvent->payload.inventory_replaced.inventory_replaced.replace_date = replacedDateTime;

    retval = SendDrsEventSendWorker_();
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    // Success.
    retval = ACK_NO_ERROR;

cleanup0:
    EventBuilderEnd();
    return retval;
}

static ACKError_t SendDrsEventSendWorker_(void)
{
    ACKError_t retval;

    g_pendingOutboundEvent.Flags.Bits.EventPending = true;

    retval = OutboundEventSend();
    if (ACK_NO_ERROR != retval)
    {
        ACK_DEBUG_PRINT_E("Error %u sending inventory event.", retval);
    }

    return retval;
}

v3avs_capabilities_V3AlexaInventoryUsageSensor_Event* _CreateInventoryUsageEvent(
    uint32_t instance,
    v3avs_capabilities_V3AlexaInventoryUsageSensor_EventName eventName,
    unsigned eventTag)
{
    v3avs_capabilities_V3AlexaInventoryUsageSensor_Event* pEvent;

    EventBuilderStart(
        0, // no correlation id
        V3AVS_Namespace_V3_ALEXA_INVENTORY_USAGE_SENSOR,
        instance,
        EncodeUsageSensorEvent_,
        EVENT_FLAGS_NONE);

    pEvent = (v3avs_capabilities_V3AlexaInventoryUsageSensor_Event*)HeapletSetSize(
        MEM_OUTBOUND_EVENT_ACP_STRUCT,
        sizeof(v3avs_capabilities_V3AlexaInventoryUsageSensor_Event));

    if (NULL == pEvent)
    {
        ACK_DEBUG_PRINT_E("Unable to allocate memory for inventory event.");
        goto cleanup0;
    }

    pEvent->name = eventName;
    pEvent->which_payload = eventTag;

cleanup0:
    return pEvent;
}

v3avs_capabilities_V3AlexaInventoryLevelUsageSensor_Event* _CreateInventoryLevelUsageEvent(
    uint32_t instance,
    v3avs_capabilities_V3AlexaInventoryLevelUsageSensor_EventName eventName,
    unsigned eventTag)
{
    v3avs_capabilities_V3AlexaInventoryLevelUsageSensor_Event* pEvent;

    EventBuilderStart(
        0, // no correlation id
        V3AVS_Namespace_V3_ALEXA_INVENTORY_LEVEL_USAGE_SENSOR,
        instance,
        EncodeLevelUsageSensorEvent_,
        EVENT_FLAGS_NONE);

    pEvent = (v3avs_capabilities_V3AlexaInventoryLevelUsageSensor_Event*)HeapletSetSize(
        MEM_OUTBOUND_EVENT_ACP_STRUCT,
        sizeof(v3avs_capabilities_V3AlexaInventoryLevelUsageSensor_Event));

    if (NULL == pEvent)
    {
        ACK_DEBUG_PRINT_E("Unable to allocate memory for inventory event.");
        goto cleanup0;
    }

    pEvent->name = eventName;
    pEvent->which_payload = eventTag;

cleanup0:
    return pEvent;
}

static void AckLevelToProtobufLevel_(
    const ACKInventoryLevel_t* pAckLevel,
    v3avs_types_V3Level* pProtobufLevel)
{
    switch (pAckLevel->Kind)
    {
    case ACK_INVENTORY_LEVEL_COUNT:
        pProtobufLevel->which_payload = v3avs_types_V3Level_count_tag;
        pProtobufLevel->payload.count.value = pAckLevel->Level.Count;
        break;

    case ACK_INVENTORY_LEVEL_PERCENTAGE:
        pProtobufLevel->which_payload = v3avs_types_V3Level_percentage_tag;
        pProtobufLevel->payload.percentage.value = pAckLevel->Level.Percentage;
        break;

    case ACK_INVENTORY_LEVEL_VOLUME:
        pProtobufLevel->which_payload = v3avs_types_V3Level_volume_tag;
        pProtobufLevel->payload.volume.unit = pAckLevel->Level.Volume.Unit;
        pProtobufLevel->payload.volume.value = pAckLevel->Level.Volume.Value;
        break;

    case ACK_INVENTORY_LEVEL_WEIGHT:
        pProtobufLevel->which_payload = v3avs_types_V3Level_weight_tag;
        pProtobufLevel->payload.weight.unit = pAckLevel->Level.Weight.Unit;
        pProtobufLevel->payload.weight.value = pAckLevel->Level.Weight.Value;
        break;

    default:
        ACK_ASSERT(false);
        break;
    }
}

// Called back from within EventBuilderSend.
static ACKError_t EncodeLevelUsageSensorEvent_(void)
{
    return EventBuilderCreateEncodedPayload(v3avs_capabilities_V3AlexaInventoryLevelUsageSensor_Event_fields);
}

// Called back from within EventBuilderSend.
static ACKError_t EncodeUsageSensorEvent_(void)
{
    return EventBuilderCreateEncodedPayload(v3avs_capabilities_V3AlexaInventoryUsageSensor_Event_fields);
}

#endif // def ACK_DASH_REPLENISHMENT
