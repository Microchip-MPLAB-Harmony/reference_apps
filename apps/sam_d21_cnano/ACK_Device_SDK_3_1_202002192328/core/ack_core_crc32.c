/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 *
 * Adapted from code with original copyright notice:
 *	Copyright (c) 2013 Christopher Baker <https://christopherbaker.net>
 *	SPDX-License-Identifier: MIT
 */

#include "ack_crc32.h"

#define FLASH_READ_DWORD(x) (*(uint32_t*)(x))

static const uint32_t crc32Table[] =
{
    0x00000000, 0x1db71064, 0x3b6e20c8, 0x26d930ac,
    0x76dc4190, 0x6b6b51f4, 0x4db26158, 0x5005713c,
    0xedb88320, 0xf00f9344, 0xd6d6a3e8, 0xcb61b38c,
    0x9b64c2b0, 0x86d3d2d4, 0xa00ae278, 0xbdbdf21c
};

uint32_t ACK_CalculateCrc32(const void* pData, size_t length)
{
	const uint8_t* p = (const uint8_t*)pData;

	uint32_t state = ~0L;
	uint8_t data;

	while (length > 0)
	{
		data = *p++;
		--length;

		// via http://forum.arduino.cc/index.php?topic=91179.0
		uint8_t tbl_idx = 0;

		tbl_idx = state ^ (data >> (0 * 4));
		state = FLASH_READ_DWORD(crc32Table + (tbl_idx & 0x0f)) ^ (state >> 4);
		tbl_idx = state ^ (data >> (1 * 4));
		state = FLASH_READ_DWORD(crc32Table + (tbl_idx & 0x0f)) ^ (state >> 4);
	}

    return ~state;
}
