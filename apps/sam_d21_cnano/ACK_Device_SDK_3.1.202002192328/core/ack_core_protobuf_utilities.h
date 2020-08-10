/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_PROTOBUF_UTILITIES_H__
#define __ACK_PROTOBUF_UTILITIES_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pb.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct _ProtobufCallbackField_t
{
    const uint8_t* Value;
    size_t Length;
}
ProtobufCallbackField_t;

typedef struct _ProtobufEncodeArrayCallbackData_t
{
    // If this is set, allows a filter to determine on a per-element basis whether the element should be
    // included in the output. If NULL, all elements are included.
    bool (*ElementFilterCallback)(const void* pElement);

    // Points to the base of the array.
    const void* Data;

    // Count of elements in the array.
    unsigned ElementCount;

    // Size in bytes of each element in the array.
    unsigned ElementSize;
}
ProtobufEncodeArrayCallbackData_t;

bool ProtobufDecodeCallbackField(
    pb_istream_t* pStream,
    const pb_field_t* pField,
    void** ppArg);

bool ProtobufEncodeCallbackField(
    pb_ostream_t* pStream,
    const pb_field_t* pField,
    void* const* pArg);

bool ProtobufEncodeArrayCallback(
    pb_ostream_t* pStream,
    const pb_field_t* pField,
    void* const* ppArg);

bool ProtobufDecode(
    const uint8_t* pInput,
    size_t inputLength,
    const pb_field_t* pFields,
    void* pDestinationStruct);

bool ProtobufDecodeSubmessage(
    const uint8_t* pInput,
    size_t inputLength,
    uint32_t submessageTag,
    const pb_field_t* pSubmessageFields,
    void* pDestinationStruct);

bool ProtobufSkipToEncodedSubmessagePayload(
    pb_istream_t* pStream,
    uint32_t tag);

size_t ProtobufGetEncodedSize(
    const pb_field_t* pFields,
    const void* pSourceStruct);

bool ProtobufEncode(
    uint8_t* pOutput,
    size_t outputLength,
    const pb_field_t* pFields,
    const void* pSourceStruct);

#ifdef __cplusplus
}
#endif

#endif // __ACK_PROTOBUF_UTILITIES_H__
