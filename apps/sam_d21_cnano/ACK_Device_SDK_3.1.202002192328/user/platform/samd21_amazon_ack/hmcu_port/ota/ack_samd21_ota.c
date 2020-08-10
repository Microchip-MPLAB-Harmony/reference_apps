/*******************************************************************************
  Source File

  Company:
    Microchip Technology Inc.

  File Name:
    ack_samd21_ota.c

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
#include "definitions.h"

#define WORDS(x)                ((int)((x) / sizeof(uint32_t)))

unsigned Samd21Ota_FlashErase(uint32_t flashAddress, uint32_t sizeInBytes)
{
    uint32_t totalEraseSectors = sizeInBytes/256;
    uint32_t i=0;
    
    for(i=0;i<totalEraseSectors;i++)
    {
         NVMCTRL_RegionUnlock(flashAddress + (i*256));

         while(NVMCTRL_IsBusy() == true);

         /* Erase the Current sector */
         NVMCTRL_RowErase(flashAddress + (i*256));
                  
         while(NVMCTRL_IsBusy() == true);
    }   
    
    return 0;
}

unsigned Samd21Ota_FlashWrite(
    uint32_t flashAddress,
    const void* ptrData,
    uint32_t size)
{     
    uint32_t PagesInEraseBlock = size/64; 
    uint32_t page       = 0;
    uint32_t write_idx  = 0;
    
    if(size%64 != 0)
        PagesInEraseBlock = PagesInEraseBlock + 1;
    
    NVMCTRL_RegionUnlock(flashAddress);
    
    while(NVMCTRL_IsBusy() == true);
    
    NVMCTRL_RowErase(flashAddress);
    
    while(NVMCTRL_IsBusy() == true);
    
   for (page = 0; page < PagesInEraseBlock; page++)
    {
        NVMCTRL_PageWrite((uint32_t*)ptrData + write_idx, flashAddress);

        while(NVMCTRL_IsBusy() == true);

        flashAddress += 64;
        write_idx += WORDS(64);
    }

    return 0;
}
