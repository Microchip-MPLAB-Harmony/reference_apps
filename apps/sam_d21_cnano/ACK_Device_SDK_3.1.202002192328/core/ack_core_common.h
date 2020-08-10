/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_COMMON_H__
#define __ACK_COMMON_H__

#include "ack.h"
#include "ack_core_protobuf_utilities.h"
#include "pb.h"
#include "V3Alexa.pb.h"
#include "V3AVS.pb.h"
#include "V3ItemQuantity.pb.h"

#ifdef __cplusplus
extern "C"
{
#endif

ACKError_t CommonAllocAndSendAcpCmdAndGetAcpResponse(pb_size_t whichType);
ACKError_t CommonSendAcpCmdAndGetResponse(void);
bool CommonCheckGenericResponse(void);
void CommonFreeAcpResponse(void);

// These are the same as the routines above, but use heaplet blocks MEM_ALT_xxx instead of MEM_xxx.
// This allows logging and metrics outbound ACP commands to be sent, and the response received and decoded,
// without disturbing any other blocks that may be in use, which in turn allows logging and metrics
// to be used from ACKUser_Onxxx (such as while processing directives).
ACKError_t CommonSendAcpCmdAndGetResponseAltHeapletBlocks(void);
bool CommonCheckGenericResponseAltHeapletBlocks(void);
void CommonFreeAcpResponseAltHeapletBlocks(void);

// Worker routine to encode one context property to protobuf.
ACKError_t CommonEncodeContextProperty(
    V3AVS_Namespace namespaceId,
    uint32_t propertyName,
    uint32_t instance,
    const ACKStateCommon_t* pCommon,
    const pb_field_t* pPropertyFields,
    const void* pPropertyValue);

// Transcode an item quantity to the struct we use for it in this codebase.
bool CommonConvertItemQuantityFromProtobuf(
    const v3avs_types_V3ItemQuantity* pSourceQuantity,
    ACKItemQuantity_t* pTargetQuantity);

bool CommonConvertItemQuantityToProtobuf(
    const ACKItemQuantity_t* pSourceQuantity,
    v3avs_types_V3ItemQuantity* pTargetQuantity);

// Struct for items in MEM_OUTBOUND_EVENT_PROPERTY_ARRAY.
typedef struct _PropertyArrayItem_t
{
    // The property itself. This contains a pb_callback_t, whose fields will be configured during encoding
    // to point at the Field value in this struct.
    // Note: this field MUST be first in the struct. Code in ProtobufEncodeArrayCallback relies on it.
    v3avs_capabilities_V3Alexa_Property Property;
    ProtobufCallbackField_t Field;

    // The value of ACKStateCommon_t::Flags, i.e. a combination of ACK_PROPERTY_xxx values.
    unsigned Flags;
}
PropertyArrayItem_t;

// In general, code is not re-entrant. When calling a user-supplied routine, guard against
// re-entry. An example is that we don't want the user to try to send an event from a directive
// handler callback.
#ifdef ACK_ENABLE_ASSERT
extern volatile bool g_reentryGuardActive;
#define ACK_REENTRY_SHIELDS_UP g_reentryGuardActive = true
#define ACK_REENTRY_SHIELDS_DOWN g_reentryGuardActive = false

// Checks to see if re-entry guard is asserted. If so, debug-prints a critical error message and causes
// an assertion failure.
#define ACK_REENTRY_CHECK ACK_REENTRY_CHECK_(NULL)

// Same as ACK_REENTRY_CHECK, except accepts an optional string that if present is also debug-printed as
// a critical error message.
#define ACK_REENTRY_CHECK_(extraMessage) \
    if (g_reentryGuardActive) \
    { \
        ACK_DEBUG_PRINT_C( \
            "%s must not be called from within your handler callbacks " \
            "(e.g. routines whose names begin with 'ACKUser_On').", \
            __FUNCTION__); \
        if (extraMessage) \
        { \
            ACK_DEBUG_PRINT_C("%s", extraMessage);\
        } \
        ACK_AssertionFailed("re-entry check"); \
    }

#else
#define ACK_REENTRY_SHIELDS_UP
#define ACK_REENTRY_SHIELDS_DOWN
#define ACK_REENTRY_CHECK
#define ACK_REENTRY_CHECK_(extraMessage)
#endif

// This type is used in casts when we assign arbitrary data pointers to pb_callback_s::funcs::encode.
// In C, strictly speaking void* and void(*)() are not compatible and so we need to cast values
// we assigning into that struct to this type instead of void*, to avoid warnings.
typedef bool (*ACKNanopbEncodeFunction_t)(pb_ostream_t*, const pb_field_t*, void* const*);

#ifdef __cplusplus
}
#endif

#endif // def __ACK_COMMON_H__
