/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_STM32_OTA_SHARED_H__
#define __ACK_STM32_OTA_SHARED_H__

#include "ack_stm32_ota_config.h"
#include <stdint.h>
#include "stm32f0xx_hal.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define ACK_STM32_OTA_STATUS_PARTITION_SIZE ACK_STM32_OTA_FLASH_PAGE_SIZE

// Partition start and end addresses.
#define ACK_STM32_OTA_LOADER_PARTITION_START ACK_STM32_OTA_FLASH_BASE
#define ACK_STM32_OTA_LOADER_PARTITION_END ((ACK_STM32_OTA_LOADER_PARTITION_START + \
    ACK_STM32_OTA_LOADER_PARTITION_SIZE) - 1)

#define ACK_STM32_OTA_STATUS_PARTITION_START (ACK_STM32_OTA_LOADER_PARTITION_END + 1)
#define ACK_STM32_OTA_STATUS_PARTITION_END ((ACK_STM32_OTA_STATUS_PARTITION_START + \
    ACK_STM32_OTA_STATUS_PARTITION_SIZE) - 1)

#define ACK_STM32_OTA_PRIMARY_PARTITION_START (ACK_STM32_OTA_STATUS_PARTITION_END + 1)
#define ACK_STM32_OTA_PRIMARY_PARTITION_END ((ACK_STM32_OTA_PRIMARY_PARTITION_START + \
    ACK_STM32_OTA_PRIMARY_PARTITION_SIZE) - 1)

#define ACK_STM32_OTA_STAGING_PARTITION_START (ACK_STM32_OTA_PRIMARY_PARTITION_END + 1)
#define ACK_STM32_OTA_STAGING_PARTITION_END ((ACK_STM32_OTA_STAGING_PARTITION_START + \
    ACK_STM32_OTA_STAGING_PARTITION_SIZE) - 1)

// Flash partition sizes.
#define ACK_STM32_OTA_PRIMARY_PARTITION_SIZE ((ACK_STM32_OTA_FLASH_SIZE - \
    (ACK_STM32_OTA_LOADER_PARTITION_SIZE + ACK_STM32_OTA_STATUS_PARTITION_SIZE)) / 2)
#define ACK_STM32_OTA_STAGING_PARTITION_SIZE ACK_STM32_OTA_PRIMARY_PARTITION_SIZE

// Sanity checks on partition sizes.
#if (ACK_STM32_OTA_LOADER_PARTITION_SIZE % ACK_STM32_OTA_FLASH_PAGE_SIZE) \
    || (ACK_STM32_OTA_STATUS_PARTITION_SIZE % ACK_STM32_OTA_FLASH_PAGE_SIZE) \
    || (ACK_STM32_OTA_PRIMARY_PARTITION_SIZE % ACK_STM32_OTA_FLASH_PAGE_SIZE) \
    || (ACK_STM32_OTA_STAGING_PARTITION_SIZE % ACK_STM32_OTA_FLASH_PAGE_SIZE) \
    || (ACK_STM32_OTA_STAGING_PARTITION_SIZE != ACK_STM32_OTA_PRIMARY_PARTITION_SIZE) \
    || ((ACK_STM32_OTA_LOADER_PARTITION_SIZE + ACK_STM32_OTA_STATUS_PARTITION_SIZE \
        + ACK_STM32_OTA_PRIMARY_PARTITION_SIZE + ACK_STM32_OTA_STAGING_PARTITION_SIZE) \
            != ACK_STM32_OTA_FLASH_SIZE)
#error \
Partition sizes must be a multiple of the page size; \
Primary and Staging Partitions must be the same size,;\
and the sum of the sizes of the Loader, Status, Primary, \
and Staging Partitions must equal the total flash size.
#endif

typedef struct _ACKStm32OtaStatusPartition_t
{
    // Must be ACK_STM32_OTA_STATUS_PARTITION_SIGNATURE1.
    uint32_t Signature1;

    // Note that this is at the end of the structure so that it's the very final thing flashed
    // to make the Status Partition valid.
    // ACK_STM32_OTA_STATUS_PARTITION_STATE_UNAPPLIED_IMAGE: Unapplied image present in Staging Partition.
    // Anything else: No unapplied OTA image present in Staging Partition.
    uint8_t State;

    // Reserved. Must be 0.
    uint8_t Pad[3];

    // Address in the Primary partition where the program starts. Must match the base address of
    // the Primary Partition.
    uint32_t ImageStartAddress;

    // Size in bytes of the OTA image on the Staging Partition.
    uint32_t ImageSize;

    // CRC32 of image data, for image validation.
    uint32_t Crc32;

    // Must be ACK_STM32_OTA_STATUS_PARTITION_SIGNATURE2, or else State is ignored and considered 0.
    // This is deliberately placed at the end of the partition to avoid seeing the Status Partition
    // as valid unless the *entire* contents of this struct can be successfully flashed to it.
    uint32_t Signature2;
}
ACKStm32OtaStatusPartition_t;

// Value for ACK_Stm32OtaStatusPartition_t Signature1 and Signature2.
#define ACK_STM32_OTA_STATUS_PARTITION_SIGNATURE1 0x314b4341
#define ACK_STM32_OTA_STATUS_PARTITION_SIGNATURE2 0x324b4341

// Value for ACK_HostFirmwareUpdateStatusPartition_t State.
#define ACK_STM32_OTA_STATUS_PARTITION_STATE_UNAPPLIED_IMAGE 0xa5

// Routines shared with custom loader program.
void ACKStm32Ota_FlashBegin(void);
void ACKStm32Ota_FlashEnd(void);

// Returns 0 upon success or a HAL error (see HAL_StatusTypeDef) upon failure.
// Upon failure, *pErrorAddress is the address returned by the HAL where erasing failed.
unsigned ACKStm32Ota_FlashErase(
    uint32_t startPageOrdinal,
    uint32_t sizeBytes,
    uint32_t* pErrorAddress);

// Returns 0 upon success or a HAL error (see HAL_StatusTypeDef) upon failure.
// Upon failure, *pErrorAddress is the start address of the failing write operation.
unsigned ACKStm32Ota_FlashWrite(
    uint32_t address,
    const void* pData,
    uint32_t dataSize16BitValues,
    uint32_t* pErrorAddress);

#ifdef __cplusplus
}
#endif

#endif // ndef __ACK_STM32_OTA_SHARED_H__
