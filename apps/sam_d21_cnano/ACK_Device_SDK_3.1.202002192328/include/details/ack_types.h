/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

// Common data types and other shared constructs.
// This file does not need to be included directly; other headers that need it include it themselves.

#ifndef __ACK_TYPES_H__
#define __ACK_TYPES_H__

#include "ack_user_config.h"
#include "v3avs_capabilities/V3Alexa.pb.h"
#include "v3avs_types/V3Count.pb.h"
#include "v3avs_types/V3Volume.pb.h"
#include "v3avs_types/V3Weight.pb.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Portable compile-time assertion. If it fails, a "duplicate case value" error results.
#define ACK_STATIC_ASSERT(x) switch(0){case 0: case (x):;}

// Copy strings in a way that ensures nul termination.
// The target is intended to be a fixed array of characters, and truncation occurs if necessary.
#define ACK_SAFE_COPY_STRING(target, source) \
    if (sizeof(target)) \
    { \
        if (source) \
        { \
            strncpy(target, source, sizeof(target) - 1); \
            target[sizeof(target) - 1] = '\0'; \
        } \
        else \
        { \
            target[0] = '\0'; \
        } \
    }

// Assertion support. Enabled only if ACK_ENABLE_ASSERT is #define'd in ack_user_config.h.
#ifdef ACK_ENABLE_ASSERT

void ACK_AssertionFailed(const char* pCondition);
#define ACK_ASSERT(x) if (!(x)) { ACK_AssertionFailed(#x); }

// Provide a hook that for example allows test code to assess whether an assertion failed or not.
extern void (*ACK_AssertionFailedHook)(void);

#else

#define ACK_ASSERT(x)

#endif

#define ACK_COUNTOF(x) (sizeof(x) / sizeof((x)[0]))

// General error type.
typedef enum _ACKError_t
{
    // Success.
    ACK_NO_ERROR = 0,

    // Exhausted memory in the heaplet.
    ACK_ERR_OUT_OF_MEMORY,

    // I/O error reading from or writing to the UART.
    ACK_ERR_IO,

    // Protocol error, such as receiving an ACK indicating an error, or corrupt or unexpected data.
    // Also indicates that an operation is not supported.
    ACK_ERR_PROTOCOL,

    // Internal error.
    // TODO: maybe these should just be asserts.
    ACK_ERR_INTERNAL
}
ACKError_t;

// In a ChangeReport event, distinguishes a context property from a payload property.
// If set, the property is payload, e.g., associated with a change due to some local cause such as the user
// turning on a light switch. If clear, the property is context in a ChangeReport, e.g. the value of some
// other property on the device but not the one that changed.
// See https://developer.amazon.com/docs/device-apis/alexa-interface.html#changereport for more info.
// Ignored for non-ChangeReport events (plain responses, error responses, state reports).
#define ACK_PROPERTY_CHANGE_REPORT_PAYLOAD 0x01

typedef struct _ACKStateCommon_t
{
    uint64_t TimeOfSample;
    uint32_t UncertaintyMilliseconds;

    // A combination of ACK_PROPERTY_xxx values.
    unsigned Flags;
}
ACKStateCommon_t;

// Represents the POSIX epoch time of midnight 1/1/2019 UTC. This is the minimum timestamp Alexa
// accepts for properties in a Change Report. Properties with earlier timestamps cause the Change Report
// to be ignored. If a time-of-sample value in a property is less than this when Ack_AddXxxProperty
// is called, it is changed to this value.
#define ACK_MINIMUM_PROPERTY_TIMESTAMP 1546300800000

// Type for an item quantity.
typedef enum _ACKItemQuantityUnitType_t
{
    ACK_ITEM_QUANTITY_COUNT,
    ACK_ITEM_QUANTITY_VOLUME,
    ACK_ITEM_QUANTITY_WEIGHT
}
ACKItemQuantityUnitType_t;

// Represents an item quantity.
typedef struct _ACKItemQuantity_t
{
    ACKItemQuantityUnitType_t UnitType;

    union
    {
        v3avs_types_V3Count_Size Size;
        v3avs_types_V3Volume_Unit VolumeUnit;
        v3avs_types_V3Weight_Unit WeightUnit;
    }
    Unit;

    float Quantity;
}
ACKItemQuantity_t;

#ifdef __cplusplus
}
#endif

#endif // def __ACK_TYPES_H__
