/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

/*
    The implementation is simple: a series of blocks each consisting of a header and a user area.
    Blocks grow upward in memory from the base of the buffer. Finding a block involves a linear search,
    as does finding the point in the buffer at which to insert a new block.

    +----------------------------------------------------+
    | block2 | block7 | block9 | ... -->  [unallocated]  |
    +----------------------------------------------------+
 */

#include "ack.h"
#include "ack_core_heaplet.h"
#include "ack_core_heaplet_internal.h"
#include "ack_user_config.h"
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#ifndef ACK_MEMORY_POOL_SIZE
#error You must define ACK_MEMORY_POOL_SIZE in ack_user_config.h.
#endif
static uint8_t sg_buffer[ACK_MEMORY_POOL_SIZE];
static uint8_t* sg_pBufferUsedEnd;

#ifdef ACK_MEMORY_DIAG

size_t g_maximumHeapletConsumed;
static HeapletTag_t sg_failureTag;
static void Dump_(void);

#endif // def ACK_MEMORY_DIAG

#define HEAPLET_SETSIZE_FLAG_IGNORE_HIGH_WATER_MARK 1
static void* SetSize_(HeapletTag_t tag, size_t newSize, unsigned flags);

static HeapletBlockHeader_t* FindBlock_(HeapletTag_t tag, HeapletBlockHeader_t** ppBlock);

#define ALIGN_UP(x) (((x) + (HEAPLET_ALIGNMENT - 1)) & ~(HEAPLET_ALIGNMENT - 1))
#define ALIGN_DOWN(x) ((x) & ~(HEAPLET_ALIGNMENT - 1))
#define ALIGN_UP_PTR(p) (uint8_t*)ALIGN_UP((uintptr_t)(p))
#define ALIGN_DOWN_PTR(p) (uint8_t*)ALIGN_DOWN((uintptr_t)(p))

// As an array of bytes, the buffer itself has no alignment requirement and could end up placed at any
// address. However we need block headers aligned properly, so the base address of the buffer must be
// aligned up.
#define FIRST_BLOCK_BASE ALIGN_UP_PTR(&sg_buffer[0])

void HeapletInit(void)
{
    // The heaplet implementation assumes that the block header structure size is itself aligned
    // so that pBlock+1 itself yields a block user area that is properly aligned.
    ACK_STATIC_ASSERT(ALIGN_DOWN(sizeof(HeapletBlockHeader_t)) == sizeof(HeapletBlockHeader_t));
    sg_pBufferUsedEnd = FIRST_BLOCK_BASE;

    ACK_DEBUG_PRINT_D(
        "Heaplet initializing; buffer %p, first block base %p, available size %u, alignment %u",
        &sg_buffer[0],
        sg_pBufferUsedEnd,
        (unsigned)(sizeof(sg_buffer) - (sg_pBufferUsedEnd - &sg_buffer[0])),
        HEAPLET_ALIGNMENT);

#ifdef ACK_MEMORY_DIAG
    g_maximumHeapletConsumed = sg_pBufferUsedEnd - &sg_buffer[0];
    sg_failureTag = MEM_NONE;
#endif
}

void* HeapletSetSize(HeapletTag_t tag, size_t newSize)
{
    return SetSize_(tag, newSize, 0);
}

static void* SetSize_(HeapletTag_t tag, size_t newSize, unsigned flags)
{
    ptrdiff_t alignedDelta;
    HeapletBlockHeader_t* pBlock;
    HeapletBlockHeader_t* pInsertionPoint;

    // Reserve tag 0.
    ACK_ASSERT(MEM_NONE != tag);

    pBlock = FindBlock_(tag, &pInsertionPoint);

    if (NULL == pBlock)
    {
        // Allocating a block; need new block header and data.
        alignedDelta = sizeof(HeapletBlockHeader_t) + ALIGN_UP(newSize);

        // Guard against buffer overrun. If newSize is *almost* the max value of a size_t, we could end up
        // allocating a very small buffer.
        if ((size_t)alignedDelta < newSize)
        {
            ACK_DEBUG_PRINT_C("Heaplet allocation overflow; tag %u, new size %u", tag, (unsigned)newSize);
            return NULL;
        }
    }
    else
    {
        // Resizing a block; just the data size changes.
        alignedDelta = ALIGN_UP(newSize) - ALIGN_UP(pBlock->Size);
    }

#ifdef ACK_MEMORY_DIAG
    if ((tag == sg_failureTag) && ((NULL == pBlock) || (newSize > pBlock->Size)))
    {
        ACK_DEBUG_PRINT_I(
            "Heaplet satisfying injected failure; tag %u from %u to %u bytes",
            tag,
            pBlock ? (unsigned)pBlock->Size : 0u,
            (unsigned)newSize);
        sg_failureTag = MEM_NONE;
        return NULL;
    }
#endif

    size_t unusedSpace = sizeof(sg_buffer) - (sg_pBufferUsedEnd - &sg_buffer[0]);
    if ((alignedDelta > 0) && ((size_t)alignedDelta > unusedSpace))
    {
        ACK_DEBUG_PRINT_C(
            "Heaplet resize failed; resize tag %u to %u bytes needs %u more bytes but %u bytes available",
            tag,
            (unsigned)newSize,
            (unsigned)alignedDelta,
            (unsigned)unusedSpace);
        ACK_DEBUG_PRINT_C("You probably need to increase ACK_MEMORY_POOL_SIZE in your ack_user_config.h.");

#ifdef ACK_MEMORY_DIAG
        Dump_();
#endif

        return NULL;
    }

    uint8_t* pBlockEnd = pBlock
        ? ((uint8_t*)(pBlock + 1) + ALIGN_UP(pBlock->Size))
        : (uint8_t*)pInsertionPoint;

    memmove(
        pBlockEnd + alignedDelta,
        pBlockEnd,
        sg_pBufferUsedEnd - pBlockEnd);

    pInsertionPoint->Tag = tag;
    pInsertionPoint->Size = newSize;

    sg_pBufferUsedEnd += alignedDelta;

#ifdef ACK_MEMORY_DIAG
    if ((0 == (flags & HEAPLET_SETSIZE_FLAG_IGNORE_HIGH_WATER_MARK))
        && ((sg_pBufferUsedEnd - sg_buffer) > g_maximumHeapletConsumed))
    {
        g_maximumHeapletConsumed = sg_pBufferUsedEnd - sg_buffer;

        ACK_DEBUG_PRINT_I("Heaplet high-water consumption: %u bytes", (unsigned)g_maximumHeapletConsumed);
    }
#endif

    return pInsertionPoint + 1;
}

void HeapletFree(HeapletTag_t tag)
{
    ptrdiff_t delta;

    // Reserve tag 0.
    ACK_ASSERT(MEM_NONE != tag);

    HeapletBlockHeader_t* pBlock = FindBlock_(tag, NULL);

    if (pBlock)
    {
        // Block header and data will go away.
        delta = sizeof(HeapletBlockHeader_t) + ALIGN_UP(pBlock->Size);

        memmove(
            pBlock,
            (uint8_t*)pBlock + delta,
            ((uintptr_t)sg_pBufferUsedEnd - (uintptr_t)pBlock) - delta);

        sg_pBufferUsedEnd -= delta;
    }
}

void* HeapletAccess(HeapletTag_t tag)
{
    HeapletBlockHeader_t* pBlock = FindBlock_(tag, NULL);
    return pBlock ? (pBlock + 1) : NULL;
}

size_t HeapletGetSize(HeapletTag_t tag)
{
    HeapletBlockHeader_t* pBlock = FindBlock_(tag, NULL);
    return pBlock ? pBlock->Size : 0;
}

void* HeapletSetToLargestPossibleSize(HeapletTag_t tag)
{
    size_t bufferFreeSpace = ALIGN_DOWN(sizeof(sg_buffer) - (sg_pBufferUsedEnd - &sg_buffer[0]));
    HeapletBlockHeader_t* pBlock = FindBlock_(tag, NULL);
    size_t newSize;

    if (pBlock)
    {
        // Block is already allocated. The max space for it is the currently allocated space
        // rounded up, plus remaining space in the buffer.
        newSize = ALIGN_UP(pBlock->Size) + bufferFreeSpace;
    }
    else
    {
        // Block is not allocated. Max space is the remaining space in the buffer minus space for
        // the header.
        if (bufferFreeSpace <= sizeof(HeapletBlockHeader_t))
        {
            return NULL;
        }

        newSize = bufferFreeSpace - sizeof(HeapletBlockHeader_t);
    }

    // Don't adjust the high-water mark, since that would cause it to always be the entire heaplet.
    return SetSize_(tag, newSize, HEAPLET_SETSIZE_FLAG_IGNORE_HIGH_WATER_MARK);
}

#ifdef ACK_MEMORY_DIAG

size_t HeapletGetBlocksInUse(HeapletTag_t* pTags, size_t maxTags)
{
    size_t actualCount = 0;

    HeapletBlockHeader_t* pBlock = (HeapletBlockHeader_t*)FIRST_BLOCK_BASE;

    while ((void*)pBlock < (void*)sg_pBufferUsedEnd)
    {
        if (actualCount < maxTags)
        {
            *pTags++ = pBlock->Tag;
        }

        ++actualCount;

        pBlock = (HeapletBlockHeader_t*)((uintptr_t)(pBlock + 1) + ALIGN_UP(pBlock->Size));
    }

    if (actualCount < maxTags)
    {
        *pTags = MEM_NONE;
    }

    ++actualCount;

    return actualCount;
}

void HeapletAssertBlocksInUse(const HeapletTag_t* pExpectedTags)
{
    HeapletBlockHeader_t* pBlock = (HeapletBlockHeader_t*)FIRST_BLOCK_BASE;
    bool exhaustedHeaplet = ((void*)pBlock == (void*)sg_pBufferUsedEnd);
    bool exhaustedExpected = (MEM_NONE == *pExpectedTags);
    bool ok = true;

    while (!exhaustedHeaplet || !exhaustedExpected)
    {
        if (!exhaustedHeaplet && (exhaustedExpected || (pBlock->Tag < *pExpectedTags)))
        {
            ACK_DEBUG_PRINT_C("Tag %u unexpectedly present", pBlock->Tag);
            ok = false;

            pBlock = (HeapletBlockHeader_t*)((uintptr_t)(pBlock + 1) + ALIGN_UP(pBlock->Size));
        }
        else if (!exhaustedExpected && (exhaustedHeaplet || (pBlock->Tag > *pExpectedTags)))
        {
            ACK_DEBUG_PRINT_C("Tag %u unexpectedly absent", *pExpectedTags);
            ok = false;

            ++pExpectedTags;
        }
        else
        {
            pBlock = (HeapletBlockHeader_t*)((uintptr_t)(pBlock + 1) + ALIGN_UP(pBlock->Size));
            ++pExpectedTags;
        }

        exhaustedHeaplet = ((void*)pBlock == (void*)sg_pBufferUsedEnd);
        exhaustedExpected = (MEM_NONE == *pExpectedTags);
    }

    ACK_ASSERT(ok);
}

void HeapletInjectSetSizeFailure(HeapletTag_t tag)
{
    ACK_DEBUG_PRINT_D(
        "Heaplet failure pending on next set-size for tag %u (replaces tag %u)",
        tag,
        sg_failureTag);

    sg_failureTag = tag;
}

void Dump_(void)
{
    HeapletTag_t tags[25];
    unsigned i;
    size_t count;

    count = HeapletGetBlocksInUse(tags, ACK_COUNTOF(tags));
    if (count)
    {
        --count; // last tag is zero to terminate the list
        ACK_DEBUG_PRINT_E("HEAPLET: %u blocks currently allocated", (unsigned)count);

        for (i = 0; i < count; ++i)
        {
            ACK_DEBUG_PRINT_E("HEAPLET: block %u: %u bytes", tags[i], (unsigned)HeapletGetSize(tags[i]));
        }
    }
}

#endif // def ACK_MEMORY_DIAG

// Attempts to find a block by tag.
// Returns a pointer to the block header if the block was found (i.e. is currently allocated).
// Always returns an insertion point, which is the same as the block if the block was found,
// or the point at which a new block with the given tag should be inserted if the block was not found.
static HeapletBlockHeader_t* FindBlock_(HeapletTag_t tag, HeapletBlockHeader_t** ppBlock)
{
    HeapletBlockHeader_t* pBlock = (HeapletBlockHeader_t*)FIRST_BLOCK_BASE;
    bool found = false;

    while ((void*)pBlock < (void*)sg_pBufferUsedEnd)
    {
        if (pBlock->Tag >= tag)
        {
            found = (pBlock->Tag == tag);
            break;
        }

        pBlock = (HeapletBlockHeader_t*)((uintptr_t)(pBlock + 1) + ALIGN_UP(pBlock->Size));
    }

    if (ppBlock)
    {
        *ppBlock = pBlock;
    }

    return found ? pBlock : NULL;
}
