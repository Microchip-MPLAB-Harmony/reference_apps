/*******************************************************************************
  File Name:
    flexible_flash.c

  Summary:
    This module contains WINC1500 flexible flash map implementation.

  Description:
    This module contains WINC1500 flexible flash map implementation.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*
Copyright (C) 2022, Microchip Technology Inc., and its subsidiaries. All rights reserved.

The software and documentation is provided by microchip and its contributors
"as is" and any express, implied or statutory warranties, including, but not
limited to, the implied warranties of merchantability, fitness for a particular
purpose and non-infringement of third party intellectual property rights are
disclaimed to the fullest extent permitted by law. In no event shall microchip
or its contributors be liable for any direct, indirect, incidental, special,
exemplary, or consequential damages (including, but not limited to, procurement
of substitute goods or services; loss of use, data, or profits; or business
interruption) however caused and on any theory of liability, whether in contract,
strict liability, or tort (including negligence or otherwise) arising in any way
out of the use of the software and documentation, even if advised of the
possibility of such damage.

Except as expressly permitted hereunder and subject to the applicable license terms
for any third-party software incorporated in the software and any applicable open
source software license terms, no license or other rights, whether express or
implied, are granted under any patent or other intellectual property rights of
Microchip or any third party.
*/

#include "spi_flash.h"
#include "m2m_types.h"
#include "flexible_flash.h"

#define FLASH_MAP_TABLE_ADDR        (FLASH_SECTOR_SZ+sizeof(tstrOtaControlSec)+8)
#define N_ENTRIES_MAX               32

int8_t spi_flexible_flash_find_section(uint16_t u16EntryIDToLookFor, uint32_t *pu32StartOffset, uint32_t *pu32Size)
{
    int8_t s8Ret = M2M_ERR_INVALID_ARG;
    if((NULL == pu32StartOffset) || (NULL == pu32Size)) goto EXIT;

    uint8_t au8buff[8];
    uint8_t u8CurrEntry = 0;
    s8Ret = spi_flash_read(&au8buff[0], FLASH_MAP_TABLE_ADDR, 4);
    if(M2M_SUCCESS != s8Ret) goto EXIT;

    uint8_t u8nEntries = au8buff[0];     // Max number is 32, reading one byte will suffice
    if(u8nEntries > N_ENTRIES_MAX)
    {
        s8Ret = M2M_ERR_FAIL;
        goto EXIT;
    }

    while(u8nEntries > u8CurrEntry)
    {
        s8Ret = spi_flash_read(&au8buff[0], FLASH_MAP_TABLE_ADDR + 4 + (u8CurrEntry*8), 8);
        u8CurrEntry++;
        if(M2M_SUCCESS != s8Ret) break;
        uint16_t u16EntryID = (au8buff[1] << 8) | au8buff[0];
        if(u16EntryID != u16EntryIDToLookFor) continue;
        *pu32StartOffset = au8buff[2] * FLASH_SECTOR_SZ;
        *pu32Size        = au8buff[3] * FLASH_SECTOR_SZ;
        break;
    }
EXIT:
    return s8Ret;
}