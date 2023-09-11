/*******************************************************************************
  UART6 PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_uart6.c

  Summary:
    UART6 PLIB Implementation File

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
#include "plib_uart6.h"
#include "interrupts.h"

// *****************************************************************************
// *****************************************************************************
// Section: UART6 Implementation
// *****************************************************************************
// *****************************************************************************


void static UART6_ErrorClear( void )
{
    UART_ERROR errors = UART_ERROR_NONE;
    uint8_t dummyData = 0u;

    errors = (UART_ERROR)(U6STA & (_U6STA_OERR_MASK | _U6STA_FERR_MASK | _U6STA_PERR_MASK));

    if(errors != UART_ERROR_NONE)
    {
        /* If it's a overrun error then clear it to flush FIFO */
        if((U6STA & _U6STA_OERR_MASK) != 0U)
        {
            U6STACLR = _U6STA_OERR_MASK;
        }

        /* Read existing error bytes from FIFO to clear parity and framing error flags */
        while((U6STA & _U6STA_URXDA_MASK) != 0U)
        {
            dummyData = (uint8_t)U6RXREG;
        }

    }

    // Ignore the warning
    (void)dummyData;
}

void UART6_Initialize( void )
{
    /* Set up UxMODE bits */
    /* STSEL  = 0 */
    /* PDSEL = 0 */
    /* UEN = 0 */

    U6MODE = 0x8;

    /* Enable UART6 Receiver and Transmitter */
    U6STASET = (_U6STA_UTXEN_MASK | _U6STA_URXEN_MASK | _U6STA_UTXISEL1_MASK );

    /* BAUD Rate register Setup */
    U6BRG = 216;

    /* Turn ON UART6 */
    U6MODESET = _U6MODE_ON_MASK;
}

bool UART6_SerialSetup( UART_SERIAL_SETUP *setup, uint32_t srcClkFreq )
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
            srcClkFreq = UART6_FrequencyGet();
        }

        /* Calculate BRG value */
        uxbrg = (((srcClkFreq >> 2) + (baud >> 1)) / baud);
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

        /* Turn OFF UART6. Save UTXEN, URXEN and UTXBRK bits as these are cleared upon disabling UART */

        status_ctrl = U6STA & (_U6STA_UTXEN_MASK | _U6STA_URXEN_MASK | _U6STA_UTXBRK_MASK);

        U6MODECLR = _U6MODE_ON_MASK;

        if(setup->dataWidth == UART_DATA_9_BIT)
        {
            /* Configure UART6 mode */
            U6MODE = (U6MODE & (~_U6MODE_PDSEL_MASK)) | setup->dataWidth;
        }
        else
        {
            /* Configure UART6 mode */
            U6MODE = (U6MODE & (~_U6MODE_PDSEL_MASK)) | setup->parity;
        }

        /* Configure UART6 mode */
        U6MODE = (U6MODE & (~_U6MODE_STSEL_MASK)) | setup->stopBits;

        /* Configure UART6 Baud Rate */
        U6BRG = uxbrg;

        U6MODESET = _U6MODE_ON_MASK;

        /* Restore UTXEN, URXEN and UTXBRK bits. */
        U6STASET = status_ctrl;

        status = true;
    }

    return status;
}

bool UART6_AutoBaudQuery( void )
{
    bool autobaudqcheck = false;
    if((U6MODE & _U6MODE_ABAUD_MASK) != 0U)
    {

       autobaudqcheck = true;
    }
    return autobaudqcheck;
}

void UART6_AutoBaudSet( bool enable )
{
    if( enable == true )
    {
        U6MODESET = _U6MODE_ABAUD_MASK;
    }

    /* Turning off ABAUD if it was on can lead to unpredictable behavior, so that
       direction of control is not allowed in this function.                      */
}

bool UART6_Read(void* buffer, const size_t size )
{
    bool status = false;
    uint32_t errorStatus = 0;
    size_t processedSize = 0;

    if(buffer != NULL)
    {

        /* Clear error flags and flush out error data that may have been received when no active request was pending */
        UART6_ErrorClear();

        while( size > processedSize )
        {
            while((U6STA & _U6STA_URXDA_MASK) == 0U)
            {
                /* Wait for receiver to be ready */
            }

            /* Error status */
            errorStatus = (U6STA & (_U6STA_OERR_MASK | _U6STA_FERR_MASK | _U6STA_PERR_MASK));

            if(errorStatus != 0U)
            {
                break;
            }
            if (( U6MODE & (_U6MODE_PDSEL0_MASK | _U6MODE_PDSEL1_MASK)) == (_U6MODE_PDSEL0_MASK | _U6MODE_PDSEL1_MASK))
            {
                /* 9-bit mode */
                ((uint16_t*)(buffer))[processedSize] = (uint16_t)(U6RXREG );
            }
            else
            {
                /* 8-bit mode */
                ((uint8_t*)(buffer))[processedSize] = (uint8_t)(U6RXREG);
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

bool UART6_Write( void* buffer, const size_t size )
{
    bool status = false;
    size_t processedSize = 0;

    if(buffer != NULL)
    {
        while( size > processedSize )
        {
            /* Wait while TX buffer is full */
            while ((U6STA & _U6STA_UTXBF_MASK) != 0U)
            {
                /* Wait for transmitter to be ready */
            }

            if (( U6MODE & (_U6MODE_PDSEL0_MASK | _U6MODE_PDSEL1_MASK)) == (_U6MODE_PDSEL0_MASK | _U6MODE_PDSEL1_MASK))
            {
                /* 9-bit mode */
                U6TXREG = ((uint16_t*)(buffer))[processedSize];
            }
            else
            {
                /* 8-bit mode */
                U6TXREG = ((uint8_t*)(buffer))[processedSize];
            }

            processedSize++;
        }

        status = true;
    }

    return status;
}

UART_ERROR UART6_ErrorGet( void )
{
    UART_ERROR errors = UART_ERROR_NONE;

    errors = (U6STA & (_U6STA_OERR_MASK | _U6STA_FERR_MASK | _U6STA_PERR_MASK));

    if(errors != UART_ERROR_NONE)
    {
        UART6_ErrorClear();
    }

    /* All errors are cleared, but send the previous error state */
    return errors;
}

void UART6_WriteByte(int data)
{
    while (((U6STA & _U6STA_UTXBF_MASK) != 0U))
    {
        /* Do Nothing */
    }

    U6TXREG = (uint32_t)data;
}

bool UART6_TransmitterIsReady( void )
{
    bool status = false;

    if((U6STA & _U6STA_UTXBF_MASK) == 0U)
    {
        status = true;
    }

    return status;
}

int UART6_ReadByte( void )
{
    return (int)(U6RXREG);
}

bool UART6_ReceiverIsReady( void )
{
    bool status = false;

    if(_U6STA_URXDA_MASK == (U6STA & _U6STA_URXDA_MASK))
    {
        status = true;
    }

    return status;
}

bool UART6_TransmitComplete( void )
{
    bool transmitComplete = false;

    if((U6STA & _U6STA_TRMT_MASK) != 0U)
    {
        transmitComplete = true;
    }

    return transmitComplete;
}