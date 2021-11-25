/*******************************************************************************
  Non-Volatile Memory Controller(NVMCTRL) PLIB.

  Company:
    Microchip Technology Inc.

  File Name:
    plib_nvmctrl.c

  Summary:
    Interface definition of NVMCTRL Plib.

  Description:
    This file defines the interface for the NVMCTRL Plib.
    It allows user to Program, Erase and lock the on-chip Non Volatile Flash
    Memory.
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <string.h>
#include "plib_nvmctrl.h"
#include "interrupts.h"

// *****************************************************************************
// *****************************************************************************
// Section: NVMCTRL Implementation
// *****************************************************************************
// *****************************************************************************


void NVMCTRL_Initialize(void)
{
    NVMCTRL_REGS->NVMCTRL_CTRLB = NVMCTRL_CTRLB_CACHEDIS_Msk | NVMCTRL_CTRLB_READMODE_NO_MISS_PENALTY | NVMCTRL_CTRLB_SLEEPPRM_WAKEUPINSTANT | NVMCTRL_CTRLB_RWS(1) ;
    NVMCTRL_REGS->NVMCTRL_CTRLC = NVMCTRL_CTRLC_MANW_Msk;
}


bool NVMCTRL_Read( uint32_t *data, uint32_t length, const uint32_t address )
{
    memcpy((void *)data, (void *)address, length);
    return true;
}

bool NVMCTRL_PageWrite( uint32_t *data, const uint32_t address )
{
    uint32_t i = 0;
    uint32_t * paddress = (uint32_t *)address;
    NVMCTRL_REGS->NVMCTRL_ADDR = 0;
    if((address & DATAFLASH_ADDR) == DATAFLASH_ADDR)
    {
        NVMCTRL_REGS->NVMCTRL_ADDR = NVMCTRL_ADDR_ARRAY_DATAFLASH;
    }

    /* writing 32-bit data into the given address */
    for (i = 0; i < (NVMCTRL_FLASH_PAGESIZE/4); i++)
    {
        *paddress++ = data[i];
    }

     /* Set address and command */
    NVMCTRL_REGS->NVMCTRL_ADDR |= address;

    NVMCTRL_REGS->NVMCTRL_CTRLA = NVMCTRL_CTRLA_CMD_WP_Val | NVMCTRL_CTRLA_CMDEX_KEY;

    return true;
}

bool NVMCTRL_RowErase( uint32_t address )
{
    NVMCTRL_REGS->NVMCTRL_ADDR = 0;
    if((address & DATAFLASH_ADDR) == DATAFLASH_ADDR)
    {
        NVMCTRL_REGS->NVMCTRL_ADDR = NVMCTRL_ADDR_ARRAY_DATAFLASH;
    }
    /* Set address and command */
    NVMCTRL_REGS->NVMCTRL_ADDR |= address;

    NVMCTRL_REGS->NVMCTRL_CTRLA = NVMCTRL_CTRLA_CMD_ER_Val | NVMCTRL_CTRLA_CMDEX_KEY;

    return true;
}

bool NVMCTRL_PageBufferWrite( uint32_t *data, const uint32_t address)
{
    uint32_t i = 0;
    uint32_t * paddress = (uint32_t *)address;

    if (!(NVMCTRL_REGS->NVMCTRL_STATUS & NVMCTRL_STATUS_LOAD_Msk))
    {
        NVMCTRL_REGS->NVMCTRL_ADDR = 0;

        if((address & DATAFLASH_ADDR) == DATAFLASH_ADDR)
        {
            NVMCTRL_REGS->NVMCTRL_ADDR = NVMCTRL_ADDR_ARRAY_DATAFLASH;
        }
    }

    /* writing 32-bit data into the given address */
    for (i = 0; i < (NVMCTRL_FLASH_PAGESIZE/4); i++)
    {
        *paddress++ = data[i];
    }

    return true;
}

bool NVMCTRL_PageBufferCommit( const uint32_t address)
{
     /* Set address and command */
    NVMCTRL_REGS->NVMCTRL_ADDR |= address;

    NVMCTRL_REGS->NVMCTRL_CTRLA = NVMCTRL_CTRLA_CMD_WP_Val | NVMCTRL_CTRLA_CMDEX_KEY;


    return true;
}

NVMCTRL_ERROR NVMCTRL_ErrorGet( void )
{
    volatile uint32_t nvm_error = 0;

    /* Get the error bits set */
    nvm_error = (NVMCTRL_REGS->NVMCTRL_INTFLAG & (NVMCTRL_INTFLAG_PROGE_Msk | NVMCTRL_INTFLAG_LOCKE_Msk | NVMCTRL_INTFLAG_NVME_Msk | NVMCTRL_INTFLAG_KEYE_Msk));

    /* Clear the error bits in INTFLAG register */
    NVMCTRL_REGS->NVMCTRL_INTFLAG |= nvm_error;

    return ((NVMCTRL_ERROR) nvm_error);
}

bool NVMCTRL_IsBusy(void)
{
    return (bool)(!(NVMCTRL_REGS->NVMCTRL_STATUS & NVMCTRL_STATUS_READY_Msk));
}

void NVMCTRL_RegionLock(NVMCTRL_MEMORY_REGION region)
{
    NVMCTRL_REGS->NVMCTRL_NSULCK = (NVMCTRL_REGS->NVMCTRL_NSULCK & ~(region)) | NVMCTRL_NSULCK_NSLKEY_KEY;
}

void NVMCTRL_RegionUnlock(NVMCTRL_MEMORY_REGION region)
{
    NVMCTRL_REGS->NVMCTRL_NSULCK |= NVMCTRL_NSULCK_NSLKEY_KEY | region;
}

