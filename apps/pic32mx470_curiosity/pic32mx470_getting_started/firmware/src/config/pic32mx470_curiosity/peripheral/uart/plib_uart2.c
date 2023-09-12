/*******************************************************************************
  UART2 PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_uart2.c

  Summary:
    UART2 PLIB Implementation File

  Description:
    None

*******************************************************************************/

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

#include "device.h"
#include "plib_uart2.h"
#include "interrupts.h"

// *****************************************************************************
// *****************************************************************************
// Section: UART2 Implementation
// *****************************************************************************
// *****************************************************************************


void static UART2_ErrorClear( void )
{
    UART_ERROR errors = UART_ERROR_NONE;
    uint8_t dummyData = 0u;

    errors = (UART_ERROR)(U2STA & (_U2STA_OERR_MASK | _U2STA_FERR_MASK | _U2STA_PERR_MASK));

    if(errors != UART_ERROR_NONE)
    {
        /* If it's a overrun error then clear it to flush FIFO */
        if((U2STA & _U2STA_OERR_MASK) != 0U)
        {
            U2STACLR = _U2STA_OERR_MASK;
        }

        /* Read existing error bytes from FIFO to clear parity and framing error flags */
        while((U2STA & _U2STA_URXDA_MASK) != 0U)
        {
            dummyData = (uint8_t)U2RXREG;
        }

    }

    // Ignore the warning
    (void)dummyData;
}

void UART2_Initialize( void )
{
    /* Set up UxMODE bits */
    /* STSEL  = 0 */
    /* PDSEL = 0 */
    /* UEN = 0 */

    U2MODE = 0x0;

    /* Enable UART2 Receiver and Transmitter */
    U2STASET = (_U2STA_UTXEN_MASK | _U2STA_URXEN_MASK | _U2STA_UTXISEL1_MASK );

    /* BAUD Rate register Setup */
    U2BRG = 25;

    /* Turn ON UART2 */
    U2MODESET = _U2MODE_ON_MASK;
}

bool UART2_SerialSetup( UART_SERIAL_SETUP *setup, uint32_t srcClkFreq )
{
    bool status = false;
    uint32_t baud;
    uint32_t status_ctrl;
    uint32_t uxbrg = 0;

    if (setup != NULL)
    {
        baud = setup->baudRate;

        if ((baud == 0U) || ((setup->dataWidth == UART_DATA_9_BIT) && (setup->parity != UART_PARITY_NONE)))
        {
            return status;
        }

        if(srcClkFreq == 0U)
        {
            srcClkFreq = UART2_FrequencyGet();
        }

        /* Calculate BRG value */
        uxbrg = (((srcClkFreq >> 4) + (baud >> 1)) / baud);
        /* Check if the baud value can be set with low baud settings */
        if (uxbrg < 1U)
        {
            return status;
        }

        uxbrg -= 1U;

        if (uxbrg > UINT16_MAX)
        {
            return status;
        }

        /* Turn OFF UART2. Save UTXEN, URXEN and UTXBRK bits as these are cleared upon disabling UART */

        status_ctrl = U2STA & (_U2STA_UTXEN_MASK | _U2STA_URXEN_MASK | _U2STA_UTXBRK_MASK);

        U2MODECLR = _U2MODE_ON_MASK;

        if(setup->dataWidth == UART_DATA_9_BIT)
        {
            /* Configure UART2 mode */
            U2MODE = (U2MODE & (~_U2MODE_PDSEL_MASK)) | setup->dataWidth;
        }
        else
        {
            /* Configure UART2 mode */
            U2MODE = (U2MODE & (~_U2MODE_PDSEL_MASK)) | setup->parity;
        }

        /* Configure UART2 mode */
        U2MODE = (U2MODE & (~_U2MODE_STSEL_MASK)) | setup->stopBits;

        /* Configure UART2 Baud Rate */
        U2BRG = uxbrg;

        U2MODESET = _U2MODE_ON_MASK;

        /* Restore UTXEN, URXEN and UTXBRK bits. */
        U2STASET = status_ctrl;

        status = true;
    }

    return status;
}

bool UART2_AutoBaudQuery( void )
{
    bool autobaudqcheck = false;
    if((U2MODE & _U2MODE_ABAUD_MASK) != 0U)
    {

       autobaudqcheck = true;
    }
    return autobaudqcheck;
}

void UART2_AutoBaudSet( bool enable )
{
    if( enable == true )
    {
        U2MODESET = _U2MODE_ABAUD_MASK;
    }

    /* Turning off ABAUD if it was on can lead to unpredictable behavior, so that
       direction of control is not allowed in this function.                      */
}

bool UART2_Read(void* buffer, const size_t size )
{
    bool status = false;
    uint32_t errorStatus = 0;
    size_t processedSize = 0;

    if(buffer != NULL)
    {

        /* Clear error flags and flush out error data that may have been received when no active request was pending */
        UART2_ErrorClear();

        while( size > processedSize )
        {
            while((U2STA & _U2STA_URXDA_MASK) == 0U)
            {
                /* Wait for receiver to be ready */
            }

            /* Error status */
            errorStatus = (U2STA & (_U2STA_OERR_MASK | _U2STA_FERR_MASK | _U2STA_PERR_MASK));

            if(errorStatus != 0U)
            {
                break;
            }
            if (( U2MODE & (_U2MODE_PDSEL0_MASK | _U2MODE_PDSEL1_MASK)) == (_U2MODE_PDSEL0_MASK | _U2MODE_PDSEL1_MASK))
            {
                /* 9-bit mode */
                ((uint16_t*)(buffer))[processedSize] = (uint16_t)(U2RXREG );
            }
            else
            {
                /* 8-bit mode */
                ((uint8_t*)(buffer))[processedSize] = (uint8_t)(U2RXREG);
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

bool UART2_Write( void* buffer, const size_t size )
{
    bool status = false;
    size_t processedSize = 0;

    if(buffer != NULL)
    {
        while( size > processedSize )
        {
            /* Wait while TX buffer is full */
            while ((U2STA & _U2STA_UTXBF_MASK) != 0U)
            {
                /* Wait for transmitter to be ready */
            }

            if (( U2MODE & (_U2MODE_PDSEL0_MASK | _U2MODE_PDSEL1_MASK)) == (_U2MODE_PDSEL0_MASK | _U2MODE_PDSEL1_MASK))
            {
                /* 9-bit mode */
                U2TXREG = ((uint16_t*)(buffer))[processedSize];
            }
            else
            {
                /* 8-bit mode */
                U2TXREG = ((uint8_t*)(buffer))[processedSize];
            }

            processedSize++;
        }

        status = true;
    }

    return status;
}

UART_ERROR UART2_ErrorGet( void )
{
    UART_ERROR errors = UART_ERROR_NONE;

    errors = (U2STA & (_U2STA_OERR_MASK | _U2STA_FERR_MASK | _U2STA_PERR_MASK));

    if(errors != UART_ERROR_NONE)
    {
        UART2_ErrorClear();
    }

    /* All errors are cleared, but send the previous error state */
    return errors;
}

void UART2_WriteByte(int data)
{
    while (((U2STA & _U2STA_UTXBF_MASK) != 0U))
    {
        /* Do Nothing */
    }

    U2TXREG = (uint32_t)data;
}

bool UART2_TransmitterIsReady( void )
{
    bool status = false;

    if((U2STA & _U2STA_UTXBF_MASK) == 0U)
    {
        status = true;
    }

    return status;
}

int UART2_ReadByte( void )
{
    return (int)(U2RXREG);
}

bool UART2_ReceiverIsReady( void )
{
    bool status = false;

    if(_U2STA_URXDA_MASK == (U2STA & _U2STA_URXDA_MASK))
    {
        status = true;
    }

    return status;
}

bool UART2_TransmitComplete( void )
{
    bool transmitComplete = false;

    if((U2STA & _U2STA_TRMT_MASK) != 0U)
    {
        transmitComplete = true;
    }

    return transmitComplete;
}