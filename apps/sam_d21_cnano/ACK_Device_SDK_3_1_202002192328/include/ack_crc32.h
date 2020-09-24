/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 *
 * Adapted from code with original copyright notice:
 *  Copyright (c) 2013 Christopher Baker <https://christopherbaker.net>
 *  SPDX-License-Identifier: MIT
 */

/*
    Reference implementation of CRC32 algorithm that matches the one in the Alexa Connect Kit
    connectivity module.
*/

#ifndef __ACK_CRC32_H__
#define __ACK_CRC32_H__

#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C"
{
#endif

/// \sa http://forum.arduino.cc/index.php?topic=91179.0
uint32_t ACK_CalculateCrc32(const void* pData, size_t length);

#ifdef __cplusplus
}
#endif

#endif // def __ACK_CRC32_H__
