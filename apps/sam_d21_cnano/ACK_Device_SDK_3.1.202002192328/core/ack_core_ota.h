/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_OTA_H__
#define __ACK_OTA_H__

#include "ack_user_config.h"
#include "details/ack_types.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef ACK_HOST_FIRMWARE_UPDATE

// Reads host over-the-air update bytes from Alexa Connect Kit connectivity module.
ACKError_t OtaDownload(
    uint32_t readOffset,
    uint32_t maxReadLength,
    uint8_t* pBytes,
    uint32_t* pActualLength);

#endif // def ACK_HOST_FIRMWARE_UPDATE

#ifdef __cplusplus
}
#endif

#endif // ndef __ACK_OTA_H__
