/*******************************************************************************
  Source File

  Company:
    Microchip Technology Inc.

  File Name:
    ack_samd21_custom_loader.c

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

#include "ack_samd21_ota.h"
#include <stdbool.h>
#include <stdint.h>
#include "definitions.h"
#include <string.h>
#include "ack_crc32.h"

static bool CheckForOtaImagePresent(void);
static bool UpgradeOtaBinary(void);
static bool ClearStatusMemory(void);
static void RunToApplication(void);
static uint32_t CalculateCRC32(const void* ptrData, uint32_t dataSize);


/*******************************************************************************
  Function:
    ota_Loader(void)

  Summary:
    On Reset, checks whether OTA firmware is present, if yes upgrades and switches to new firmware or runs the old binary 

  Remarks:
 */
void ota_Loader(void)
{
    if (CheckForOtaImagePresent())
    {
        if (UpgradeOtaBinary())
        {
            ClearStatusMemory();
        }
    }
    
    RunToApplication();
}

/*******************************************************************************
  Function:
    bool CheckForOtaImagePresent(void)

  Summary:
    Checks whether valid ota firmware is present

  Remarks:
 */

bool CheckForOtaImagePresent(void)
{
    volatile ACKSamd21OtaStatusPrtion* ptrStatusPrtion
        = (ACKSamd21OtaStatusPrtion*)ACK_SAMD21_OTA_STATUS_PARTITION_START;

    if ((ptrStatusPrtion->ota_guardBytes != ACK_SAMD21_OTA_GUARD_BYTES)
        || (ptrStatusPrtion->ota_flashCmd != ACK_SAMD21_OTA_FLASH_CMD)
        || (ptrStatusPrtion->ota_status != ACK_SAMD21_OTA_RECEIVED_PENDING)   
        || (ptrStatusPrtion->ota_firmwarSize > ACK_SAMD21_OTA_PRIMARY_PARTITION_SIZE)
        || (ptrStatusPrtion->ota_firmwareStartAddress != ACK_SAMD21_OTA_PRIMARY_PARTITION_START))
    {
        //valid ota firmware not found!!!
        return false;
    }

    uint32_t crc = CalculateCRC32(
        (const void*)ACK_SAMD21_OTA_STAGING_PARTITION_START,
        ptrStatusPrtion->ota_firmwarSize);
    if (crc != ptrStatusPrtion->ota_firmwarCrc32)
    {
        // CRC not matching 
        return false;
    }
    return true;
}

/*******************************************************************************
  Function:
    bool UpgradeOtaBinary(void)

  Summary:
    Upgrades ota binary from backup memory to main memory

  Remarks:
 */
bool UpgradeOtaBinary(void)
{
    unsigned status;
    volatile ACKSamd21OtaStatusPrtion* ptrStatusPrtion 
        = (ACKSamd21OtaStatusPrtion*)ACK_SAMD21_OTA_STATUS_PARTITION_START;

#if (ACK_SAMD21_OTA_PRIMARY_PARTITION_START % ACK_SAMD21_OTA_FLASH_PAGE_SIZE)
#error 
#endif
    status = Samd21Ota_FlashErase(
        ACK_SAMD21_OTA_PRIMARY_PARTITION_START ,
       ACK_SAMD21_OTA_PRIMARY_PARTITION_SIZE);
    
    if (0 == status)
    {
        status = Samd21Ota_FlashWrite(
            ACK_SAMD21_OTA_PRIMARY_PARTITION_START,
            (const void*)ACK_SAMD21_OTA_STAGING_PARTITION_START,
            ptrStatusPrtion->ota_firmwarSize);
    }


    return 0 == status;
}

/*******************************************************************************
  Function:
    bool ClearStatusMemory(void)

  Summary:
   Clears status memory for next ota reception.

  Remarks:
 */
bool ClearStatusMemory(void)
{
    unsigned status;

#if (ACK_SAMD21_OTA_STAGING_PARTITION_START % ACK_SAMD21_OTA_FLASH_PAGE_SIZE)
//    #error
#endif
    status = Samd21Ota_FlashErase(
        ACK_SAMD21_OTA_STATUS_PARTITION_START,
        ACK_SAMD21_OTA_STATUS_PARTITION_SIZE);

    return 0 == status;
}


/*******************************************************************************
  Function:
    void RunToApplication(void)

  Summary:
    Switches application to run from main memory 

  Remarks:
 */
void RunToApplication(void)
{
    //mapping main stack pointer & Program counter

    uint32_t msp            = *(uint32_t *)(ACK_SAMD21_OTA_PRIMARY_PARTITION_START);
    uint32_t reset_vector   = *(uint32_t *)(ACK_SAMD21_OTA_PRIMARY_PARTITION_START + 4);

    if (msp == 0xffffffff)
    {
        return;
    }

    __set_MSP(msp);

    asm("bx %0"::"r" (reset_vector));
    
    // Never reaches
}

/*******************************************************************************
  Function:
    uint32_t CalculateCRC32(const void* ptrData, uint32_t dataSize)

  Summary:
    calculates CRC 

  Remarks:
 */
uint32_t CalculateCRC32(const void* ptrData, uint32_t dataSize)
{
    return  ACK_CalculateCrc32(ptrData,dataSize);
}
