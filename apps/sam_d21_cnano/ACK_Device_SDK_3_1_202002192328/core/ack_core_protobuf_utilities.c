/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#include "pb.h"
#include "pb_decode.h"
#include "pb_encode.h"
#include "ack.h"
#include "ack_core_protobuf_utilities.h"

bool ProtobufDecodeCallbackField(
    pb_istream_t* pStream,
    const pb_field_t* pField,
    void** ppArg)
{
    ProtobufCallbackField_t* pArg = (ProtobufCallbackField_t*)*ppArg;

    pArg->Length = pStream->bytes_left;
    pArg->Value = (uint8_t*)pStream->state;

    return pb_read(pStream, NULL, pStream->bytes_left);
}

bool ProtobufEncodeCallbackField(
    pb_ostream_t* pStream,
    const pb_field_t* pField,
    void* const* ppArg)
{
    ProtobufCallbackField_t* pArg = (ProtobufCallbackField_t*)*ppArg;

    if (!pb_encode_tag_for_field(pStream, pField))
    {
        return false;
    }

   return pb_encode_string(pStream, pArg->Value, pArg->Length);
}

bool ProtobufEncodeArrayCallback(
    pb_ostream_t* pStream,
    const pb_field_t* pField,
    void* const* ppArg)
{
    const ProtobufEncodeArrayCallbackData_t* pArg;
    unsigned i;
    const uint8_t* pData;

    pArg = (const ProtobufEncodeArrayCallbackData_t*)*ppArg;
    pData = (const uint8_t*)pArg->Data;

    for (i = 0; i < pArg->ElementCount; ++i)
    {
        // Check whether the element should be included. If there's no filter, include the element.
        // Otherwise ask the filter whether to include the element.
        if ((NULL == pArg->ElementFilterCallback) || pArg->ElementFilterCallback(pData))
        {
            if (!pb_encode_tag_for_field(pStream, pField))
            {
                return false;
            }

            // pData points to the field being encoded.
            // pb_encode_submessage will consume only what it needs, and pArg->ElementSize (added to pData
            // below) can be larger than the struct being encoded. This allows there to be extra data in
            // each element.
            if (!pb_encode_submessage(pStream, (const pb_field_t*)pField->ptr, pData))
            {
                return false;
            }
        }

        pData += pArg->ElementSize;
    }

    return true;
}

bool ProtobufDecode(
    const uint8_t* pInput,
    size_t inputLength,
    const pb_field_t* pFields,
    void* pDestinationStruct)
{
    pb_istream_t stream = pb_istream_from_buffer(pInput, inputLength);

    return pb_decode(&stream, pFields, pDestinationStruct);
}

bool ProtobufDecodeSubmessage(
    const uint8_t* pInput,
    size_t inputLength,
    uint32_t submessageTag,
    const pb_field_t* pSubmessageFields,
    void* pDestinationStruct)
{
    pb_wire_type_t wireType;
    uint32_t tag;
    bool eof;
    pb_istream_t stream;
    pb_istream_t substream;

    stream = pb_istream_from_buffer(pInput, inputLength);

    while (pb_decode_tag(&stream, &wireType, &tag, &eof))
    {
        if ((PB_WT_STRING == wireType) && (submessageTag == tag))
        {
            if (!pb_make_string_substream(&stream, &substream))
            {
                return false;
            }

            // Note use of pb_decode_noinit instead of pb_decode. This lets us put sentinel values
            // in fields before decoding, and determine whether fields were present by watching for whether
            // the sentinel values were changed.
            if (0 == pb_decode_noinit(&substream, pSubmessageFields, pDestinationStruct))
            {
                return false;
            }

            return pb_close_string_substream(&stream, &substream);
        }

        // Wasn't our field.
        if (!pb_skip_field(&stream, wireType))
        {
            return false;
        }
    }

    return false;
}

// Locates the beginning of the encoded data for a variable-length (string wire type) submessage, and
// skips over the tag itself and the subsequent encoded size field. This leaves the stream pointing at the
// first byte of the encoded submessage payload.
bool ProtobufSkipToEncodedSubmessagePayload(pb_istream_t* pStream, uint32_t tag)
{
    pb_wire_type_t wireType;
    uint32_t t;
    bool eof;
    uint32_t size;

    while (pb_decode_tag(pStream, &wireType, &t, &eof))
    {
        if (t == tag)
        {
            if ((PB_WT_STRING != wireType)
                || !pb_decode_varint32(pStream, &size)
                || (pStream->bytes_left < size))
            {
                // Found the tag, but it's not string wire-type (and so would not be expected to be prefixed
                // by a size), or we can't decode the size, or the size is corrupted.
                return false;
            }

            return true;
        }

        // Wasn't our field.
        if (!pb_skip_field(pStream, wireType))
        {
            return false;
        }
    }

    return false;
}

size_t ProtobufGetEncodedSize(const pb_field_t* pFields, const void* pSourceStruct)
{
    size_t size = 0;

    return pb_get_encoded_size(&size, pFields, pSourceStruct) ? size : 0;
}

bool ProtobufEncode(
    uint8_t* pOutput,
    size_t outputLength,
    const pb_field_t* pFields,
    const void* pSourceStruct)
{
    pb_ostream_t stream = pb_ostream_from_buffer(pOutput, outputLength);

    if (0 == pb_encode(&stream, pFields, pSourceStruct))
    {
        return false;
    }

    ACK_ASSERT(stream.bytes_written == outputLength);
    return true;
}
