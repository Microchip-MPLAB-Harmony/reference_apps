/*
 * Copyright 2018-2020 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_STM32_OTA_CONFIG_H__
#define __ACK_STM32_OTA_CONFIG_H__

#ifdef __cplusplus
extern "C"
{
#endif

// The Loader and Status Partition sizes must each be a multiple of the flash page size. (The size of the
// Loader Partition is always set to the flash page size. See ack_stm32_ota.h.)
// The sum of the Loader and Status Partition sizes must be an even multiple of the flash page size
// so that the remainder of flash can be equally divided among the Staging and Primary Partitions.

// For STM32F030x8: 64K flash and 8K RAM, 1K flash page size.
#ifdef STM32F030x8
#define ACK_STM32_OTA_FLASH_BASE 0x08000000U
#define ACK_STM32_OTA_FLASH_SIZE 0x10000U
#define ACK_STM32_OTA_FLASH_PAGE_SIZE 0x400U
#define ACK_STM32_OTA_INTERRUPT_VECTOR_COUNT 45
#define ACK_STM32_OTA_LOADER_PARTITION_SIZE 5120    // 5K -- see caveats above
#endif

// For STM32F030xC: 256KB flash and 32K RAM, 2K flash page size.
#ifdef STM32F030xC
#define ACK_STM32_OTA_FLASH_BASE 0x08000000U
#define ACK_STM32_OTA_FLASH_SIZE 0x40000U
#define ACK_STM32_OTA_FLASH_PAGE_SIZE 0x800U
#define ACK_STM32_OTA_INTERRUPT_VECTOR_COUNT 46
#define ACK_STM32_OTA_LOADER_PARTITION_SIZE 6144    // 6K -- see caveats above
#endif

#ifdef __cplusplus
}
#endif

#endif // ndef __ACK_STM32_OTA_CONFIG_H__
