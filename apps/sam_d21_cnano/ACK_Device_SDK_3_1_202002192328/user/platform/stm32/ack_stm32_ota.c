/*
 * Copyright 2018-2020 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#include "ack_stm32_ota.h"
#include "stm32f0xx_hal.h"

void ACKStm32Ota_FlashBegin(void)
{
    // An error return code indicates that flash is already unlocked.
    // Ignore that.
    HAL_FLASH_Unlock();
}

void ACKStm32Ota_FlashEnd(void)
{
    HAL_FLASH_Lock();
}

unsigned ACKStm32Ota_FlashErase(uint32_t startPageOrdinal, uint32_t sizeBytes, uint32_t* pErrorAddress)
{
    // Erase the given range.
    FLASH_EraseInitTypeDef erase = {0};
    erase.TypeErase = FLASH_TYPEERASE_PAGES;
    erase.PageAddress = ACK_STM32_OTA_FLASH_BASE + (startPageOrdinal * ACK_STM32_OTA_FLASH_PAGE_SIZE);
    erase.NbPages = ((sizeBytes + ACK_STM32_OTA_FLASH_PAGE_SIZE) - 1) / ACK_STM32_OTA_FLASH_PAGE_SIZE;
    
    return HAL_FLASHEx_Erase(&erase, pErrorAddress);
}

unsigned ACKStm32Ota_FlashWrite(
    uint32_t address,
    const void* pData,
    uint32_t dataSize16BitValues,
    uint32_t* pErrorAddress)
{
    unsigned status;

    // Odd addresses or no data to program is an error condition.
    if ((address & 1) || ((uintptr_t)pData & 1) || (0 == dataSize16BitValues))
    {
        // A random value not in HAL_StatusTypeDef, to differentiate from errors that actually
        // come from the HAL.
        *pErrorAddress = address;
        return 0x7ffffffe;
    }
    
    // Calling HAL_FLASH_Program is most efficient with 64-bit values. The largest data access
    // on a Cortex-M0 is 32-bit, and memory accesses must be aligned. Assuming pData doesn't have
    // its low bit set (which should never happen, since we check for that above), pData can
    // either be aligned to a 32-bit boundary, or can be misaligned from a 32-bit boundary by
    // exactly one 16-bit half-word.
    if ((uintptr_t)pData & 0x2)
    {
        status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, address, *(const uint16_t*)(pData));
        if (HAL_OK != status)
        {
            *pErrorAddress = address;
            return status;
        }
        
        address += 2;
        pData = (const void*)((uintptr_t)pData + 2);
        --dataSize16BitValues;
    }
    
    // Process 64-bit chunks.
    while (dataSize16BitValues >= 4)
    {
        status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, address, *(const uint64_t*)(pData));
        if (HAL_OK != status)
        {
            *pErrorAddress = address;
            return status;
        }
        
        address += 8;
        pData = (const void*)((uintptr_t)pData + 8);
        dataSize16BitValues -= 4;
    }
    
    // Process any remaining 16-bit half-words.
    if (dataSize16BitValues >= 2)
    {
        status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, address, *(const uint32_t*)(pData));
        if (HAL_OK != status)
        {
            *pErrorAddress = address;
            return status;
        }
        
        address += 4;
        pData = (const void*)((uintptr_t)pData + 4);
        dataSize16BitValues -= 2;
    }

    if (dataSize16BitValues)
    {
        status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, address, *(const uint16_t*)(pData));
        if (HAL_OK != status)
        {
            *pErrorAddress = address;
            return status;
        }
    }
    
    return 0;
}
