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

volatile static UART_OBJECT uart6Obj;

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

        /* Clear error interrupt flag */
        IFS5CLR = _IFS5_U6EIF_MASK;

        /* Clear up the receive interrupt flag so that RX interrupt is not
         * triggered for error bytes */
        IFS5CLR = _IFS5_U6RXIF_MASK;
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

    /* Disable Interrupts */
    IEC5CLR = _IEC5_U6EIE_MASK;

    IEC5CLR = _IEC5_U6RXIE_MASK;

    IEC5CLR = _IEC5_U6TXIE_MASK;

    /* Initialize instance object */
    uart6Obj.rxBuffer = NULL;
    uart6Obj.rxSize = 0;
    uart6Obj.rxProcessedSize = 0;
    uart6Obj.rxBusyStatus = false;
    uart6Obj.rxCallback = NULL;
    uart6Obj.txBuffer = NULL;
    uart6Obj.txSize = 0;
    uart6Obj.txProcessedSize = 0;
    uart6Obj.txBusyStatus = false;
    uart6Obj.txCallback = NULL;
    uart6Obj.errors = UART_ERROR_NONE;

    /* Turn ON UART6 */
    U6MODESET = _U6MODE_ON_MASK;
}

bool UART6_SerialSetup( UART_SERIAL_SETUP *setup, uint32_t srcClkFreq )
{
    bool status = false;
    uint32_t baud;
    uint32_t status_ctrl;
    uint32_t uxbrg = 0;

    if(uart6Obj.rxBusyStatus == true)
    {
        /* Transaction is in progress, so return without updating settings */
        return status;
    }
    if (uart6Obj.txBusyStatus == true)
    {
        /* Transaction is in progress, so return without updating settings */
        return status;
    }

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

    if(buffer != NULL)
    {
        /* Check if receive request is in progress */
        if(uart6Obj.rxBusyStatus == false)
        {
            /* Clear error flags and flush out error data that may have been received when no active request was pending */
            UART6_ErrorClear();

            uart6Obj.rxBuffer = buffer;
            uart6Obj.rxSize = size;
            uart6Obj.rxProcessedSize = 0;
            uart6Obj.rxBusyStatus = true;
            uart6Obj.errors = UART_ERROR_NONE;
            status = true;

            /* Enable UART6_FAULT Interrupt */
            IEC5SET = _IEC5_U6EIE_MASK;

            /* Enable UART6_RX Interrupt */
            IEC5SET = _IEC5_U6RXIE_MASK;
        }
    }

    return status;
}

bool UART6_Write( void* buffer, const size_t size )
{
    bool status = false;

    if(buffer != NULL)
    {
        /* Check if transmit request is in progress */
        if(uart6Obj.txBusyStatus == false)
        {
            uart6Obj.txBuffer = buffer;
            uart6Obj.txSize = size;
            uart6Obj.txProcessedSize = 0;
            uart6Obj.txBusyStatus = true;
            status = true;

            size_t txProcessedSize = uart6Obj.txProcessedSize;
            size_t txSize = uart6Obj.txSize;

            /* Initiate the transfer by writing as many bytes as we can */
            while(((U6STA & _U6STA_UTXBF_MASK) == 0U) && (txSize > txProcessedSize) )
            {
                if (( U6MODE & (_U6MODE_PDSEL0_MASK | _U6MODE_PDSEL1_MASK)) == (_U6MODE_PDSEL0_MASK | _U6MODE_PDSEL1_MASK))
                {
                    /* 9-bit mode */
                    U6TXREG = ((uint16_t*)uart6Obj.txBuffer)[txProcessedSize];
                    txProcessedSize++;
                }
                else
                {
                    /* 8-bit mode */
                    U6TXREG = ((uint8_t*)uart6Obj.txBuffer)[txProcessedSize];
                    txProcessedSize++;
                }
            }

            uart6Obj.txProcessedSize = txProcessedSize;

            IEC5SET = _IEC5_U6TXIE_MASK;
        }
    }

    return status;
}

UART_ERROR UART6_ErrorGet( void )
{
    UART_ERROR errors = uart6Obj.errors;

    uart6Obj.errors = UART_ERROR_NONE;

    /* All errors are cleared, but send the previous error state */
    return errors;
}

void UART6_ReadCallbackRegister( UART_CALLBACK callback, uintptr_t context )
{
    uart6Obj.rxCallback = callback;

    uart6Obj.rxContext = context;
}

bool UART6_ReadIsBusy( void )
{
    return uart6Obj.rxBusyStatus;
}

size_t UART6_ReadCountGet( void )
{
    return uart6Obj.rxProcessedSize;
}

bool UART6_ReadAbort(void)
{
    if (uart6Obj.rxBusyStatus == true)
    {
        /* Disable the fault interrupt */
        IEC5CLR = _IEC5_U6EIE_MASK;

        /* Disable the receive interrupt */
        IEC5CLR = _IEC5_U6RXIE_MASK;

        uart6Obj.rxBusyStatus = false;

        /* If required application should read the num bytes processed prior to calling the read abort API */
        uart6Obj.rxSize = 0U;
        uart6Obj.rxProcessedSize = 0U;
    }

    return true;
}

void UART6_WriteCallbackRegister( UART_CALLBACK callback, uintptr_t context )
{
    uart6Obj.txCallback = callback;

    uart6Obj.txContext = context;
}

bool UART6_WriteIsBusy( void )
{
    return uart6Obj.txBusyStatus;
}

size_t UART6_WriteCountGet( void )
{
    return uart6Obj.txProcessedSize;
}

void __attribute__((used)) UART6_FAULT_InterruptHandler (void)
{
    /* Save the error to be reported later */
    uart6Obj.errors = (U6STA & (_U6STA_OERR_MASK | _U6STA_FERR_MASK | _U6STA_PERR_MASK));

    /* Disable the fault interrupt */
    IEC5CLR = _IEC5_U6EIE_MASK;

    /* Disable the receive interrupt */
    IEC5CLR = _IEC5_U6RXIE_MASK;

    /* Clear rx status */
    uart6Obj.rxBusyStatus = false;

    UART6_ErrorClear();

    /* Client must call UARTx_ErrorGet() function to get the errors */
    if( uart6Obj.rxCallback != NULL )
    {
        uintptr_t rxContext = uart6Obj.rxContext;

        uart6Obj.rxCallback(rxContext);
    }
}

void __attribute__((used)) UART6_RX_InterruptHandler (void)
{
    if(uart6Obj.rxBusyStatus == true)
    {
        size_t rxSize = uart6Obj.rxSize;
        size_t rxProcessedSize = uart6Obj.rxProcessedSize;

        while((_U6STA_URXDA_MASK == (U6STA & _U6STA_URXDA_MASK)) && (rxSize > rxProcessedSize) )
        {
            if (( U6MODE & (_U6MODE_PDSEL0_MASK | _U6MODE_PDSEL1_MASK)) == (_U6MODE_PDSEL0_MASK | _U6MODE_PDSEL1_MASK))
            {
                /* 9-bit mode */
                ((uint16_t*)uart6Obj.rxBuffer)[rxProcessedSize] = (uint16_t)(U6RXREG);
            }
            else
            {
                /* 8-bit mode */
                ((uint8_t*)uart6Obj.rxBuffer)[rxProcessedSize] = (uint8_t)(U6RXREG);
            }
            rxProcessedSize++;
        }

        uart6Obj.rxProcessedSize = rxProcessedSize;

        /* Clear UART6 RX Interrupt flag */
        IFS5CLR = _IFS5_U6RXIF_MASK;

        /* Check if the buffer is done */
        if(uart6Obj.rxProcessedSize >= rxSize)
        {
            uart6Obj.rxBusyStatus = false;

            /* Disable the fault interrupt */
            IEC5CLR = _IEC5_U6EIE_MASK;

            /* Disable the receive interrupt */
            IEC5CLR = _IEC5_U6RXIE_MASK;


            if(uart6Obj.rxCallback != NULL)
            {
                uintptr_t rxContext = uart6Obj.rxContext;

                uart6Obj.rxCallback(rxContext);
            }
        }
    }
    else
    {
        /* Nothing to process */
    }
}

void __attribute__((used)) UART6_TX_InterruptHandler (void)
{
    if(uart6Obj.txBusyStatus == true)
    {
        size_t txSize = uart6Obj.txSize;
        size_t txProcessedSize = uart6Obj.txProcessedSize;

        while(((U6STA & _U6STA_UTXBF_MASK) == 0U) && (txSize > txProcessedSize) )
        {
            if (( U6MODE & (_U6MODE_PDSEL0_MASK | _U6MODE_PDSEL1_MASK)) == (_U6MODE_PDSEL0_MASK | _U6MODE_PDSEL1_MASK))
            {
                /* 9-bit mode */
                U6TXREG = ((uint16_t*)uart6Obj.txBuffer)[txProcessedSize];
            }
            else
            {
                /* 8-bit mode */
                U6TXREG = ((uint8_t*)uart6Obj.txBuffer)[txProcessedSize];
            }
            txProcessedSize++;
        }

        uart6Obj.txProcessedSize = txProcessedSize;

        /* Clear UART6TX Interrupt flag */
        IFS5CLR = _IFS5_U6TXIF_MASK;

        /* Check if the buffer is done */
        if(uart6Obj.txProcessedSize >= txSize)
        {
            uart6Obj.txBusyStatus = false;

            /* Disable the transmit interrupt, to avoid calling ISR continuously */
            IEC5CLR = _IEC5_U6TXIE_MASK;

            if(uart6Obj.txCallback != NULL)
            {
                uintptr_t txContext = uart6Obj.txContext;

                uart6Obj.txCallback(txContext);
            }
        }
    }
    else
    {
        // Nothing to process
        ;
    }
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