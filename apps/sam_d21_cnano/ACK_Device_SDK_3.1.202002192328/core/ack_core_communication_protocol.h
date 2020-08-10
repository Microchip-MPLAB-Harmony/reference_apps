/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_COMMUNICATION_PROTOCOL_H__
#define __ACK_COMMUNICATION_PROTOCOL_H__

#include <stddef.h>
#include <stdint.h>

// Compiler-independent means of expressing structure packing.
#if defined(_MSC_VER)
#define BEGIN_PACKED_STRUCT __pragma(pack(push, 1))
#define END_PACKED_STRUCT __pragma(pack(pop))
#define PACKED_STRUCT1
#define PACKED_STRUCT2
#elif defined(__GNUC__) || defined(__clang__)
#define BEGIN_PACKED_STRUCT
#define END_PACKED_STRUCT
#define PACKED_STRUCT1 __attribute__((packed))
#define PACKED_STRUCT2
#elif defined(__CC_ARM)
#define BEGIN_PACKED_STRUCT
#define END_PACKED_STRUCT
#define PACKED_STRUCT1
#define PACKED_STRUCT2 __packed
#else
#error Unknown compiler; structure packing not configured
#endif

#ifdef __cplusplus
extern "C"
{
#endif

// This will be bumped when the contents of this file are changed
// or when there's changes in the communication sequence
#define ACP_PROTOCOL_MAJOR_VERSION  1
#define ACP_PROTOCOL_MINOR_VERSION  0

#define ACP_REQUEST_HDR_BYTES   {'~', 0xD4, '*', 0x94, 'J'}
#define ACP_REQUEST_HDR_LEN 5

typedef enum _AcpValue_t
{
    ACK_ACP_NO_ERROR = 0,
    ACK_ACP_DECODE_ERROR = 1,
    ACK_ACP_ENCODE_ERROR = 2,
    ACK_ACP_NO_PENDING_EVENT = 3,
    ACK_ACP_EXCEEDED_MAX_MESSAGE_SIZE = 4,
    ACK_ACP_NO_RESPONSE = 5,
    ACK_ACP_INVALID_REQUEST = 6,
    ACK_ACP_INVALID_CHECKSUM = 7,
    ACK_ACP_INTERNAL_ERROR = 8
}
AcpValue_t;

typedef enum _AcpRequestType_t
{
    ACP_REQUEST_WRITE_CMD,
    ACP_REQUEST_READ_RESPONSE_HEADER,
    ACP_REQUEST_READ_RESPONSE_BODY
}
AcpRequestType_t;

BEGIN_PACKED_STRUCT

typedef PACKED_STRUCT2 struct _AcpRequest_t
{
    uint8_t Header[ACP_REQUEST_HDR_LEN];

    // Version[0] major #, Version[1] minor #
    uint8_t Version[2];
    uint8_t Type;
    uint16_t Length;
    uint16_t Offset;

     // A 32bit CRC checksum over the payload of the request.
    uint32_t Crc32;

    uint8_t Reserved[8];
}
PACKED_STRUCT1 AcpRequest_t;

typedef PACKED_STRUCT2 struct _AcpAck_t
{
    uint8_t Value;
    uint8_t Version[2];
    uint8_t Reserved[5];
}
PACKED_STRUCT1 AcpAck_t;

typedef PACKED_STRUCT2 struct _AcpResponseHeader_t
{
    uint16_t Length;
    uint32_t Crc32; // A 32bit CRC checksum over the payload of the response
    uint8_t Reserved[6];
}
PACKED_STRUCT1 AcpResponseHeader_t;

END_PACKED_STRUCT

#ifdef __cplusplus
}
#endif

#endif // __ACK_COMMUNICATION_PROTOCOL_H__
