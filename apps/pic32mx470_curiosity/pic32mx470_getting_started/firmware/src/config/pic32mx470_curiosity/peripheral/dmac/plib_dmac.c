/*******************************************************************************
  Direct Memory Access Controller (DMAC) PLIB

  Company
    Microchip Technology Inc.

  File Name
    plib_dmac.c

  Summary
    Source for DMAC peripheral library interface Implementation.

  Description
    This file defines the interface to the DMAC peripheral library. This
    library provides access to and control of the DMAC controller.

  Remarks:
    None.

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

#include "plib_dmac.h"
#include "interrupts.h"


// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************

volatile static DMAC_CHANNEL_OBJECT  gDMAChannelObj[4];
static DMAC_CRC_SETUP gCRCSetup;

#define ConvertToPhysicalAddress(a) ((uint32_t)KVA_TO_PA(a))
#define ConvertToVirtualAddress(a)  PA_TO_KVA1(a)

// *****************************************************************************
// *****************************************************************************
// Section: DMAC PLib Local Functions
// *****************************************************************************
// *****************************************************************************

static void DMAC_ChannelSetAddresses(DMAC_CHANNEL channel, const void *srcAddr, const void *destAddr)
{
    const uint32_t *xsrcAddr = (const uint32_t *)srcAddr;
    const uint32_t *xdestAddr = (const uint32_t *)destAddr;

    uint32_t sourceAddress = (uint32_t)xsrcAddr;
    uint32_t destAddress = (uint32_t)xdestAddr;
    volatile uint32_t * regs;

    /* Set the source address */
    /* Check if the address lies in the KSEG2 for MZ devices */
    if ((sourceAddress >> 29) == 0x6U)
    {
        if ((sourceAddress >> 28)== 0xcU)
        {
            // EBI Address translation
            sourceAddress = ((sourceAddress | 0x20000000U) & 0x2FFFFFFFU);
        }
        else if((sourceAddress >> 28)== 0xDU)
        {
            //SQI Address translation
            sourceAddress = ((sourceAddress | 0x30000000U) & 0x3FFFFFFFU);
        }
        else
        {
            /* Do Nothing */
        }
    }
    else if ((sourceAddress >> 29) == 0x7U)
    {
        if ((sourceAddress >> 28)== 0xEU)
        {
            // EBI Address translation
            sourceAddress = ((sourceAddress | 0x20000000U) & 0x2FFFFFFFU);
        }
        else if ((sourceAddress >> 28)== 0xFU)
        {
            // SQI Address translation
            sourceAddress = ((sourceAddress | 0x30000000U) & 0x3FFFFFFFU);
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        /* For KSEG0 and KSEG1, The translation is done by KVA_TO_PA */
        sourceAddress = ConvertToPhysicalAddress(sourceAddress);
    }

    /* Set the source address, DCHxSSA */
    regs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60U + (channel * 0xC0U) + 0x30U);
    *(volatile uint32_t *)(regs) = sourceAddress;

    /* Set the destination address */
    /* Check if the address lies in the KSEG2 for MZ devices */
    if ((destAddress >> 29) == 0x6U)
    {
        // EBI Address translation
        if ((destAddress >> 28)== 0xcU)
        {
            destAddress = ((destAddress | 0x20000000U) & 0x2FFFFFFFU);
        }
        //SQI Address translation
        else if ((destAddress >> 28)== 0xdU)
        {
            destAddress = ((destAddress | 0x30000000U) & 0x3FFFFFFFU);
        }
        else
        {
            /* Do Nothing */
        }
    }
    else if ((destAddress >> 29) == 0x7U)
    {   /* Check if the address lies in the KSEG3 for MZ devices */
        // EBI Address translation
        if ((destAddress >> 28)== 0xeU)
        {
            destAddress = ((destAddress | 0x20000000U) & 0x2FFFFFFFU);
        }
        //SQI Address translation
        else if ((destAddress >> 28)== 0xfU)
        {
            destAddress = ((destAddress | 0x30000000U) & 0x3FFFFFFFU);
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        /* For KSEG0 and KSEG1, The translation is done by KVA_TO_PA */
        destAddress = ConvertToPhysicalAddress(destAddress);
    }

    /* Set destination address, DCHxDSA */
    regs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60U + (channel * 0xC0U) + 0x40U);
    *(volatile uint32_t *)(regs) = destAddress;
}

// *****************************************************************************
/* Function:
   static uint32_t DMAC_BitReverse( uint32_t num, uint32_t bits)

  Summary:
    Reverses the bits in the given number

  Description:
    Reverses the bits in the given number based on the size of the number.
    Example:
        number  = 10110011
        reverse = 11001101

  Parameters:
    num - Number to be reversed
    bits - size of the number (8, 16, 32)

  Returns:
    reversed number
*/
static uint32_t DMAC_BitReverse( uint32_t num, uint32_t bits)
{
    uint32_t out = 0;
    uint32_t i;

    for( i = 0U; i < bits; i++ )
    {
        out <<= 1;

        if(( num & 1U ) != 0U)
        {
            out |= 1U;
        }

        num >>= 1;
    }

    return out;
}

// *****************************************************************************
// *****************************************************************************
// Section: DMAC PLib Interface Implementations
// *****************************************************************************
// *****************************************************************************

void DMAC_Initialize(void)
{
    uint8_t chanIndex;
    volatile DMAC_CHANNEL_OBJECT *chanObj;

    /* Enable the DMA module */
    DMACONSET = _DMACON_ON_MASK;

    /* Initialize the available channel objects */
    chanObj = &gDMAChannelObj[0];

    for(chanIndex = 0U; chanIndex < 4U; chanIndex++)
    {
        chanObj->inUse          =    false;
        chanObj->pEventCallBack =    NULL;
        chanObj->hClientArg     =    0;
        chanObj->errorInfo      =    DMAC_ERROR_NONE;
        chanObj++; /* linked list 'next' */
    }

    /* DMACON register */
    /* ON = 1          */
    DMACON = 0x8000;

    /* DMA channel-level control registers.  They will have additional settings made when starting a transfer. */
    /* DMA channel 0 configuration */
    /* CHPRI = 0, CHAEN= 0, CHCHN= 0, CHCHNS= 0x0, CHAED= 0 */
    DCH0CON = 0x0;
    /* CHSIRQ = 58, SIRQEN = 1 */
    DCH0ECON = 0x3a10;
    /* CHBCIE = 1, CHTAIE=1, CHERIE=1, CHSHIE= 0, CHDHIE= 0 */
    DCH0INT = 0xb0000;

    /* Enable DMA channel interrupts */
    IEC2SET = 0U | 0x100U ;
}

void DMAC_ChannelCallbackRegister(DMAC_CHANNEL channel, const DMAC_CHANNEL_CALLBACK eventHandler, const uintptr_t contextHandle)
{
    gDMAChannelObj[channel].pEventCallBack = eventHandler;

    gDMAChannelObj[channel].hClientArg = contextHandle;
}

bool DMAC_ChannelTransfer(DMAC_CHANNEL channel, const void *srcAddr, size_t srcSize, const void *destAddr, size_t destSize, size_t cellSize)
{
    bool returnStatus = false;
    volatile uint32_t *regs;
    uint32_t DCHxINT_Flags;

    regs = ((volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60U + (channel * 0xC0U) + 0x20U));
    DCHxINT_Flags = *(volatile uint32_t *)(regs) & (_DCH0INT_CHERIF_MASK | _DCH0INT_CHTAIF_MASK | _DCH0INT_CHBCIF_MASK);

    if((gDMAChannelObj[channel].inUse == false) || (DCHxINT_Flags != 0U))
    {
        /* Clear all the interrupt flags */
        regs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60U + (channel * 0xC0U) + 0x20U) + 1U;
        *(volatile uint32_t *)(regs) = (_DCH0INT_CHSHIF_MASK |_DCH0INT_CHDHIF_MASK | _DCH0INT_CHBCIF_MASK | _DCH0INT_CHTAIF_MASK| _DCH0INT_CHERIF_MASK);

        gDMAChannelObj[channel].inUse = true;
        returnStatus = true;

        /* Set the source / destination addresses, DCHxSSA and DCHxDSA */
        DMAC_ChannelSetAddresses(channel, srcAddr, destAddr);

        /* Set the source size, DCHxSSIZ */
        regs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60U + (channel * 0xC0U) + 0x50U);
        *(volatile uint32_t *)(regs) = srcSize;

        /* Set the destination size, DCHxDSIZ */
        regs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60U + (channel * 0xC0U) + 0x60U);
        *(volatile uint32_t *)(regs) = destSize;

        /* Set the cell size, DCHxCSIZ */
        regs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60U + (channel * 0xC0U) + 0x90U);
        *(volatile uint32_t *)(regs) = cellSize;

        /* Enable the channel */
        /* CHEN = 1 */
        regs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60U + (channel * 0xC0U) + 0x0U)+2U;
        *(volatile uint32_t *)(regs) = _DCH0CON_CHEN_MASK;

        /* Check Channel Start IRQ Enable bit - SIRQEN */
         regs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60U + (channel * 0xC0U) + 0x10U);

        /* Initiate transfer if user did not set up channel for interrupt-initiated transfer. */
        if((*(volatile uint32_t *)(regs) & _DCH1ECON_SIRQEN_MASK) == 0U)
        {
            /* CFORCE = 1 */
            regs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60U + (channel * 0xC0U) + 0x10U)+2U;
            *(volatile uint32_t *)(regs) = _DCH0ECON_CFORCE_MASK;
        }
    }

    return returnStatus;
}

bool DMAC_ChainTransferSetup( DMAC_CHANNEL channel, const void *srcAddr, size_t srcSize, const void *destAddr, size_t destSize, size_t cellSize)
{
    bool returnStatus = false;
    volatile uint32_t *regs;
    uint32_t DCHxINT_Flags;

    regs = ((volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60U + (channel * 0xC0U) + 0x20U));
    DCHxINT_Flags = *(volatile uint32_t *)(regs) & (_DCH0INT_CHERIF_MASK | _DCH0INT_CHTAIF_MASK | _DCH0INT_CHBCIF_MASK);

    if((gDMAChannelObj[channel].inUse == false) || (DCHxINT_Flags != 0U))
    {
        /* Clear all the interrupt flags */
        regs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60U + (channel * 0xC0U) + 0x20U) + 1U;
        *(volatile uint32_t *)(regs) = (_DCH0INT_CHSHIF_MASK |_DCH0INT_CHDHIF_MASK | _DCH0INT_CHBCIF_MASK | _DCH0INT_CHTAIF_MASK| _DCH0INT_CHERIF_MASK);

        gDMAChannelObj[channel].inUse = true;
        returnStatus = true;

        /* Set the source / destination addresses, DCHxSSA and DCHxDSA */
        DMAC_ChannelSetAddresses(channel, srcAddr, destAddr);

        /* Set the source size, DCHxSSIZ */
        regs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60U + (channel * 0xC0U) + 0x50U);
        *(volatile uint32_t *)(regs) = srcSize;

        /* Set the destination size, DCHxDSIZ */
        regs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60U + (channel * 0xC0U) + 0x60U);
        *(volatile uint32_t *)(regs) = destSize;

        /* Set the cell size, DCHxCSIZ */
        regs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60U + (channel * 0xC0U) + 0x90U);
        *(volatile uint32_t *)(regs) = cellSize;
    }

    return returnStatus;
}

void DMAC_ChannelPatternMatchSetup(DMAC_CHANNEL channel, uint8_t patternMatchData)
{
    volatile uint32_t * patternRegs;
    patternRegs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60U + (channel * 0xC0U) + 0xB0U);
    *(volatile uint32_t *)(patternRegs) = patternMatchData;

    /* Enable Pattern Match */
    volatile uint32_t * eventConRegs;
    eventConRegs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60U + (channel * 0xC0U) + 0x10U)+2U;
    *(volatile uint32_t *)(eventConRegs) = _DCH0ECON_PATEN_MASK;
}

void DMAC_ChannelPatternMatchDisable(DMAC_CHANNEL channel)
{
    volatile uint32_t * eventConRegs;
    eventConRegs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60U + (channel * 0xC0U) + 0x10U)+1U;
    *(volatile uint32_t *)(eventConRegs) = _DCH0ECON_PATEN_MASK;
}
void DMAC_ChannelDisable(DMAC_CHANNEL channel)
{
    volatile uint32_t * regs;

    if(channel < 4U)
    {
        /* Disable channel in register DCHxCON */
        /* CHEN = 0 */
        regs = (volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60U + (channel * 0xC0U) + 0x0U)+1U;
        *(volatile uint32_t *)(regs) = _DCH0CON_CHEN_MASK;

        gDMAChannelObj[channel].inUse = false;
    }
}

bool DMAC_ChannelIsBusy(DMAC_CHANNEL channel)
{
    uint32_t DCHxINT_Flags;
    bool channelstatus = false;

    DCHxINT_Flags = *(volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60U + (channel * 0xC0U) + 0x20U);
    DCHxINT_Flags = DCHxINT_Flags & (_DCH0INT_CHERIF_MASK | _DCH0INT_CHTAIF_MASK | _DCH0INT_CHBCIF_MASK);

    if ((gDMAChannelObj[channel].inUse == true) && (DCHxINT_Flags == 0U))
    {
        channelstatus = true;
    }

    return channelstatus;
}

DMAC_TRANSFER_EVENT DMAC_ChannelTransferStatusGet(DMAC_CHANNEL channel)
{
    uint32_t DCHxINT_Flags;

    DMAC_TRANSFER_EVENT dmaEvent = DMAC_TRANSFER_EVENT_NONE;

    DCHxINT_Flags = *(volatile uint32_t *)(_DMAC_BASE_ADDRESS + 0x60U + (channel * 0xC0U) + 0x20U);

    if ((DCHxINT_Flags & (_DCH0INT_CHSHIF_MASK | _DCH0INT_CHDHIF_MASK)) != 0U)  /* Dest Half-full or Src Half-empty flags */
    {
        dmaEvent = DMAC_TRANSFER_EVENT_HALF_COMPLETE;
    }
    if ((DCHxINT_Flags & (_DCH0INT_CHTAIF_MASK | _DCH0INT_CHERIF_MASK)) != 0U)  /* Abort or Error flags*/
    {
        dmaEvent = DMAC_TRANSFER_EVENT_ERROR;
    }
    if ((DCHxINT_Flags & _DCH0INT_CHBCIF_MASK) != 0U)   /* Block Transfer complete flag */
    {
        dmaEvent = DMAC_TRANSFER_EVENT_COMPLETE;
    }

    return dmaEvent;
}

void DMAC_ChannelCRCSetup( DMAC_CHANNEL channel, DMAC_CRC_SETUP CRCSetup )
{
    uint32_t mask = 0;

    gCRCSetup.append_mode           = CRCSetup.append_mode;
    gCRCSetup.reverse_crc_input     = CRCSetup.reverse_crc_input;
    gCRCSetup.polynomial_length     = CRCSetup.polynomial_length;
    gCRCSetup.polynomial            = CRCSetup.polynomial;
    gCRCSetup.non_direct_seed       = CRCSetup.non_direct_seed;
    gCRCSetup.final_xor_value       = CRCSetup.final_xor_value;
    gCRCSetup.reverse_crc_output    = CRCSetup.reverse_crc_output;

    if (gCRCSetup.append_mode == true)
    {
        mask |= _DCRCCON_CRCAPP_MASK;
    }

    if (gCRCSetup.reverse_crc_input == true)
    {
        mask |= _DCRCCON_BITO_MASK;
    }

    mask |= (channel | _DCRCCON_CRCEN_MASK | (((uint32_t)gCRCSetup.polynomial_length - 1U) << _DCRCCON_PLEN_POSITION));

    /* Setup the DMA CRCCON register */
    DCRCCON = mask;

    /* Store the polynomial value */
    DCRCXOR = gCRCSetup.polynomial;

    /* Store the Initial seed value */
    DCRCDATA = gCRCSetup.non_direct_seed;
}

void DMAC_CRCDisable( void )
{
    DCRCCONCLR = _DCRCCON_CRCEN_MASK;
}

uint32_t DMAC_CRCRead( void )
{
    uint32_t crc = 0;

    /* Read the generated CRC value.
     * Once read DMAC_CRCEnable() has to be called again before DMA Transfer for new CRC.
    */
    crc = DCRCDATA;

    /* Reverse the final crc value */
    if (gCRCSetup.reverse_crc_output == true)
    {
        crc = DMAC_BitReverse(crc, gCRCSetup.polynomial_length);
    }

    crc ^= gCRCSetup.final_xor_value;

    return crc;
}

void __attribute__((used)) DMA_0_InterruptHandler(void)
{
    volatile DMAC_CHANNEL_OBJECT *chanObj;
    DMAC_TRANSFER_EVENT dmaEvent = DMAC_TRANSFER_EVENT_NONE;
    uint32_t VarRead = 0;

    /* Find out the channel object */
    chanObj = &gDMAChannelObj[0];

    /* Check whether the active DMA channel event has occurred */
    VarRead = DCH0INTbits.CHDHIF;
    if((DCH0INTbits.CHSHIF == 1U) || ( VarRead == 1U))/* irq due to half complete */
    {
        /* Do not clear the flag here, it should be cleared with block transfer complete flag*/

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_NONE;
        dmaEvent = DMAC_TRANSFER_EVENT_HALF_COMPLETE;
        /* Since transfer is only half done yet, do not make inUse flag false */
    }
    if(DCH0INTbits.CHTAIF == 1U) /* irq due to transfer abort */
    {
        /* Channel is by default disabled on Transfer Abortion */
        /* Clear the Abort transfer complete flag */
        DCH0INTCLR = _DCH0INT_CHTAIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_NONE;
        dmaEvent = DMAC_TRANSFER_EVENT_ERROR;
        chanObj->inUse = false;
    }
    if(DCH0INTbits.CHBCIF == 1U) /* irq due to transfer complete */
    {
        /* Channel is by default disabled on completion of a block transfer */
        /* Clear the Block transfer complete, half empty and half full interrupt flag */
        DCH0INTCLR = _DCH0INT_CHBCIF_MASK | _DCH0INT_CHSHIF_MASK | _DCH0INT_CHDHIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_NONE;
        dmaEvent = DMAC_TRANSFER_EVENT_COMPLETE;
        chanObj->inUse = false;
    }
    if(DCH0INTbits.CHERIF == 1U) /* irq due to address error */
    {
        /* Clear the address error flag */
        DCH0INTCLR = _DCH0INT_CHERIF_MASK;

        /* Update error and event */
        chanObj->errorInfo = DMAC_ERROR_ADDRESS_ERROR;
        dmaEvent = DMAC_TRANSFER_EVENT_ERROR;
        chanObj->inUse = false;
    }

    /* Clear the interrupt flag and call event handler */
    IFS2CLR = 0x100;

    if((chanObj->pEventCallBack != NULL) && (dmaEvent != DMAC_TRANSFER_EVENT_NONE))
    {
        uintptr_t hClientArg = chanObj->hClientArg;

        chanObj->pEventCallBack(dmaEvent, hClientArg);
    }
}
