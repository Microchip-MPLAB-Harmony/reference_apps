/*******************************************************************************
  Header File

  Company:
    Microchip Technology Inc.

  File Name:
    ack_samd21_ota.h

  Summary:

  Description:

 *******************************************************************************/
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

#ifndef __ACK_SAMD21_OTA_H__
#define __ACK_SAMD21_OTA_H__

#include "ack_samd21_ota_config.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define ACK_SAMD21_OTA_STATUS_PARTITION_SIZE 0x400
// ota memory start and end addresses.
#define ACK_SAMD21_OTA_LOADER_PARTITION_START ACK_SAMD21_OTA_FLASH_BASE
#define ACK_SAMD21_OTA_LOADER_PARTITION_END ((ACK_SAMD21_OTA_LOADER_PARTITION_START + \
    ACK_SAMD21_OTA_LOADER_PARTITION_SIZE) - 1)

#define ACK_SAMD21_OTA_STATUS_PARTITION_START (ACK_SAMD21_OTA_LOADER_PARTITION_END + 1)
#define ACK_SAMD21_OTA_STATUS_PARTITION_END ((ACK_SAMD21_OTA_STATUS_PARTITION_START + \
    ACK_SAMD21_OTA_STATUS_PARTITION_SIZE) - 1)

#define ACK_SAMD21_OTA_PRIMARY_PARTITION_START (ACK_SAMD21_OTA_STATUS_PARTITION_END + 1)
#define ACK_SAMD21_OTA_PRIMARY_PARTITION_END ((ACK_SAMD21_OTA_PRIMARY_PARTITION_START + \
    ACK_SAMD21_OTA_PRIMARY_PARTITION_SIZE) - 1)

#define ACK_SAMD21_OTA_STAGING_PARTITION_START (ACK_SAMD21_OTA_PRIMARY_PARTITION_END + 1)
#define ACK_SAMD21_OTA_STAGING_PARTITION_END ((ACK_SAMD21_OTA_STAGING_PARTITION_START + \
    ACK_SAMD21_OTA_STAGING_PARTITION_SIZE) - 1)

// Flash partition sizes.
#define ACK_SAMD21_OTA_PRIMARY_PARTITION_SIZE ((ACK_SAMD21_OTA_FLASH_SIZE - \
    (ACK_SAMD21_OTA_LOADER_PARTITION_SIZE + ACK_SAMD21_OTA_STATUS_PARTITION_SIZE)) / 2)
#define ACK_SAMD21_OTA_STAGING_PARTITION_SIZE ACK_SAMD21_OTA_PRIMARY_PARTITION_SIZE

// Sanity checks on partition sizes.
#if (ACK_SAMD21_OTA_LOADER_PARTITION_SIZE % ACK_SAMD21_OTA_FLASH_PAGE_SIZE) \
    || (ACK_SAMD21_OTA_STATUS_PARTITION_SIZE % ACK_SAMD21_OTA_FLASH_PAGE_SIZE) \
    || (ACK_SAMD21_OTA_PRIMARY_PARTITION_SIZE % ACK_SAMD21_OTA_FLASH_PAGE_SIZE) \
    || (ACK_SAMD21_OTA_STAGING_PARTITION_SIZE % ACK_SAMD21_OTA_FLASH_PAGE_SIZE) \
    || (ACK_SAMD21_OTA_STAGING_PARTITION_SIZE != ACK_SAMD21_OTA_PRIMARY_PARTITION_SIZE) \
    || ((ACK_SAMD21_OTA_LOADER_PARTITION_SIZE + ACK_SAMD21_OTA_STATUS_PARTITION_SIZE \
        + ACK_SAMD21_OTA_PRIMARY_PARTITION_SIZE + ACK_SAMD21_OTA_STAGING_PARTITION_SIZE) \
            != ACK_SAMD21_OTA_FLASH_SIZE)
//error
#endif

typedef struct Samd21OtaStatusPartition
{
    uint32_t ota_guardBytes;

    uint8_t ota_flashCmd; //OTA flash command = 0xA0

    uint8_t ota_status;  // 0xFF - applied or 0x4d - (pending) Firmware is not updated in main memory

    uint32_t ota_firmwareStartAddress;

    uint32_t ota_firmwarSize;

    uint32_t ota_firmwarCrc32;

}
ACKSamd21OtaStatusPrtion;

#define ACK_SAMD21_OTA_GUARD_BYTES 0x5048434D 
#define ACK_SAMD21_OTA_FLASH_CMD 0xA0
#define ACK_SAMD21_OTA_RECEIVED_PENDING 0x4D

unsigned Samd21Ota_FlashErase(
    uint32_t flashAddress,
    uint32_t sizeInBytes);

unsigned Samd21Ota_FlashWrite(
    uint32_t flashAddress,
    const void* ptrData,
    uint32_t size);

#ifdef __cplusplus
}
#endif

#endif 
