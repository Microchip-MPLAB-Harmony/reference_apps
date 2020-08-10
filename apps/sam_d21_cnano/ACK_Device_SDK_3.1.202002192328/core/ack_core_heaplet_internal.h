/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_HEAPLET_INTERNAL_H__
#define __ACK_HEAPLET_INTERNAL_H__

#include <stdint.h>
#include "ack_core_heaplet.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Structure at the head of every allocated block. The user area starts following this in memory, rounded up
// to an aligned boundary.
typedef struct _HeapletBlockHeader
{
    // Size passed to HeapletSetSize to allocate/resize the block.
    size_t Size;

    // Block tag.
    HeapletTag_t Tag;
}
HeapletBlockHeader_t;

// Alignment factor for blocks. Ensures that the user area of blocks are aligned suitably to contain any kind
// of data. Assuming alignment of pointer fields within blocks is the controlling factor for that, we'd want
// the alignment factor to be simply sizeof(void*). However it's also possible that natural alignment is
// smaller than sizeof(void*). One example is 8-bit MCUs, where memory access is byte-oriented and so
// alignment is not even required. Another example could be a 16-bit MCU with 4-byte pointers, where
// we'd expect natural alignment to be to even addresses (2-byte boundaries).
// To determine the actual required alignment, we can use the fact that in an array of structs, the compiler
// must ensure that all elements are aligned. Composing a void* field and a byte field into a struct, and
// taking the size delta between that and a simple void*, gives us the alignment used by the compiler.
// (We expect this to be a small power of 2, but don't explicitly check for that.)
struct HeapletAlignDummyStruct_t { void* _1; uint8_t _2; };
#define HEAPLET_ALIGNMENT (sizeof(struct HeapletAlignDummyStruct_t) - sizeof(void*))

#ifdef __cplusplus
}
#endif

#endif // def __ACK_HEAPLET_INTERNAL_H__
