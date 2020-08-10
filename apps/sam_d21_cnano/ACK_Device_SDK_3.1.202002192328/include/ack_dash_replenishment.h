/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_DASH_REPLENISHMENT_H__
#define __ACK_DASH_REPLENISHMENT_H__

#include "ack_user_config.h"
#include "details/ack_types.h"
#include <stdint.h>
#include "v3avs_types/V3Volume.pb.h"
#include "v3avs_types/V3Weight.pb.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef ACK_DASH_REPLENISHMENT

// Indicates the kind of inventory level described by ACKInventoryLevel_t.
typedef enum _ACKInventoryLevelKind_t
{
    ACK_INVENTORY_LEVEL_NONE,
    ACK_INVENTORY_LEVEL_COUNT,
    ACK_INVENTORY_LEVEL_WEIGHT,
    ACK_INVENTORY_LEVEL_VOLUME,
    ACK_INVENTORY_LEVEL_PERCENTAGE
}
ACKInventoryLevelKind_t;

// Describes an inventory level. Used as input parameters to inventory-related routines.
typedef struct _ACKInventoryLevel_t
{
    ACKInventoryLevelKind_t Kind;

    union
    {
        uint32_t Count;
        
        struct
        {
            float Value;
            v3avs_types_V3Weight_Unit Unit;
        }
        Weight;

        struct
        {
            float Value;
            v3avs_types_V3Volume_Unit Unit;
        }
        Volume;

        uint32_t Percentage;
    }
    Level;
}
ACKInventoryLevel_t;

// Call this to add an inventory level property to an event.
ACKError_t ACK_AddInventoryLevelProperty(
    uint32_t instance,
    const ACKStateCommon_t* pCommon,
    const ACKInventoryLevel_t* pInventoryLevel);

// Informs the Dash Replenishment Service of inventory consumption, for an Inventory.Usage controller.
ACKError_t ACK_SendDashReplenishmentUsageConsumedEvent(
    uint32_t instance,
    const ACKInventoryLevel_t* pLevel);

// Informs the Dash Replenishment Service of inventory consumption, for an Inventory.LevelUsage controller.
ACKError_t ACK_SendDashReplenishmentLevelUsageConsumedEvent(
    uint32_t instance,
    const ACKInventoryLevel_t* pLevel);

// Informs the Dash Replenishment Service of inventory replacement, for an Inventory.LevelUsage controller.
ACKError_t ACK_SendDashReplenishmentLevelUsageReplacedEvent(
    uint32_t instance,
    const ACKInventoryLevel_t* pLevel,
    uint64_t replacedDateTime);

#endif // def ACK_DASH_REPLENISHMENT

#ifdef __cplusplus
}
#endif

#endif // def __ACK_DASH_REPLENISHMENT_H__
