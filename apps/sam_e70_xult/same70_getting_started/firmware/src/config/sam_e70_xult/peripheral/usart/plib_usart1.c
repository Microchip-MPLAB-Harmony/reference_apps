/*******************************************************************************
  USART1 PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_usart1.c

  Summary:
    USART1 PLIB Implementation File

  Description:
    None

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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

#include "device.h"
#include "plib_usart1.h"
#include "interrupts.h"

// *****************************************************************************
// *****************************************************************************
// Section: USART1 Implementation
// *****************************************************************************
// *****************************************************************************

static void USART1_ErrorClear( void )
{
    uint32_t dummyData = 0U;

   if ((USART1_REGS->US_CSR & (US_CSR_USART_OVRE_Msk | US_CSR_USART_PARE_Msk | US_CSR_USART_FRAME_Msk)) != 0U)
   {
        /* Clear the error flags */
        USART1_REGS->US_CR = US_CR_USART_RSTSTA_Msk;

        /* Flush existing error bytes from the RX FIFO */
        while ((USART1_REGS->US_CSR & US_CSR_USART_RXRDY_Msk) != 0U)
        {
            dummyData = USART1_REGS->US_RHR & US_RHR_RXCHR_Msk;
        }
   }

    /* Ignore the warning */
    (void)dummyData;
}


void USART1_Initialize( void )
{
    /* Reset USART1 */
    USART1_REGS->US_CR = (US_CR_USART_RSTRX_Msk | US_CR_USART_RSTTX_Msk | US_CR_USART_RSTSTA_Msk);

    /* Enable USART1 */
    USART1_REGS->US_CR = (US_CR_USART_TXEN_Msk | US_CR_USART_RXEN_Msk);

    /* Configure USART1 mode */
    USART1_REGS->US_MR = (US_MR_USART_USCLKS_MCK | US_MR_USART_CHRL_8_BIT | US_MR_USART_PAR_NO | US_MR_USART_NBSTOP_1_BIT | US_MR_USART_OVER(0));

    /* Configure USART1 Baud Rate */
    USART1_REGS->US_BRGR = US_BRGR_CD(81U);
}

USART_ERROR USART1_ErrorGet( void )
{
    USART_ERROR errors = USART_ERROR_NONE;

    uint32_t status = USART1_REGS->US_CSR;

    errors = (USART_ERROR)(status & (US_CSR_USART_OVRE_Msk | US_CSR_USART_PARE_Msk | US_CSR_USART_FRAME_Msk));

    if(errors != USART_ERROR_NONE)
    {
        USART1_ErrorClear();
    }

    /* All errors are cleared, but send the previous error state */
    return errors;
}

bool USART1_SerialSetup( USART_SERIAL_SETUP *setup, uint32_t srcClkFreq )
{
    uint32_t baud;
    uint32_t brgVal = 0;
    uint32_t overSampVal = 0;
    uint32_t usartMode;
    bool status = false;

    if (setup != NULL)
    {
        baud = setup->baudRate;

        if(srcClkFreq == 0U)
        {
            srcClkFreq = USART1_FrequencyGet();
        }

        /* Calculate BRG value */
        if (srcClkFreq >= (16U * baud))
        {
            brgVal = (srcClkFreq / (16U * baud));
        }
        else if (srcClkFreq >= (8U * baud))
        {
            brgVal = (srcClkFreq / (8U * baud));
            overSampVal = US_MR_USART_OVER(1U);
        }
        else
        {
            return false;
        }

        if (brgVal > 65535U)
        {
            /* The requested baud is so low that the ratio of srcClkFreq to baud exceeds the 16-bit register value of CD register */
            return false;
        }

        /* Configure USART1 mode */
        usartMode = USART1_REGS->US_MR;
        usartMode &= ~(US_MR_USART_CHRL_Msk | US_MR_USART_MODE9_Msk | US_MR_USART_PAR_Msk | US_MR_USART_NBSTOP_Msk | US_MR_USART_OVER_Msk);
        USART1_REGS->US_MR = usartMode | ((uint32_t)setup->dataWidth | (uint32_t)setup->parity | (uint32_t)setup->stopBits | (uint32_t)overSampVal);

        /* Configure USART1 Baud Rate */
        USART1_REGS->US_BRGR = US_BRGR_CD(brgVal);
        status = true;
    }

    return status;
}

bool USART1_Read( void *buffer, const size_t size )
{
    bool status = false;
    uint32_t errorStatus = 0;
    size_t processedSize = 0;
    if(buffer != NULL)
    {
        uint8_t* pu8Data = (uint8_t *)buffer;
        uint16_t* pu16Data = (uint16_t*)buffer;
        /* Clear errors that may have got generated when there was no active read request pending */
        USART1_ErrorClear();

        while( size > processedSize )
        {
            while ((USART1_REGS->US_CSR & US_CSR_USART_RXRDY_Msk) == 0U)
            {
                /* Wait for RXRDY flag */
            }

            /* Read error status */
            errorStatus = (USART1_REGS->US_CSR & (US_CSR_USART_OVRE_Msk | US_CSR_USART_FRAME_Msk | US_CSR_USART_PARE_Msk));
            if(errorStatus != 0U)
            {
                break;
            }

            if ((USART1_REGS->US_MR & US_MR_USART_MODE9_Msk) != 0U)
            {
                *pu16Data = (uint16_t)(USART1_REGS->US_RHR & US_RHR_RXCHR_Msk);
                pu16Data++;
            }
            else
            {
                *pu8Data = (uint8_t)(USART1_REGS->US_RHR & US_RHR_RXCHR_Msk);
                pu8Data++;
            }

            processedSize++;
        }

        if(size == processedSize)
        {
            status = true;
        }
    }

    return status;
}

bool USART1_Write( void *buffer, const size_t size )
{
    bool status = false;
    size_t processedSize = 0;
    if(NULL != buffer)
    {
        uint8_t* pu8Data = (uint8_t *)buffer;
        uint16_t* pu16Data = (uint16_t*)buffer;
        while( size > processedSize )
        {
            while ((USART1_REGS->US_CSR & US_CSR_USART_TXRDY_Msk) == 0U)
            {
                /*Wait for TXRDY */
            }

            if ((USART1_REGS->US_MR & US_MR_USART_MODE9_Msk) != 0U)
            {
                USART1_REGS->US_THR = pu16Data[processedSize] & US_THR_TXCHR_Msk;
            }
            else
            {
                USART1_REGS->US_THR = pu8Data[processedSize] & US_THR_TXCHR_Msk;
            }
            processedSize++;
        }

        status = true;
    }
    return status;
}

int USART1_ReadByte( void )
{
    uint32_t data = USART1_REGS->US_RHR & US_RHR_RXCHR_Msk;
    return (int)data;
}

void USART1_WriteByte( int data )
{
    while ((USART1_REGS->US_CSR & US_CSR_USART_TXRDY_Msk) == 0U)
    {
        /* Wait for TXRDY flag */
    }
    USART1_REGS->US_THR = US_THR_TXCHR(data);
}

bool USART1_TransmitterIsReady( void )
{
    return ((USART1_REGS->US_CSR & US_CSR_USART_TXRDY_Msk) != 0U);
}

bool USART1_ReceiverIsReady( void )
{
    return ((USART1_REGS->US_CSR & US_CSR_USART_RXRDY_Msk) != 0U);
}

bool USART1_TransmitComplete( void )
{
    return((USART1_REGS->US_CSR & US_CSR_USART_TXEMPTY_Msk) != 0U);

}

