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

// *****************************************************************************
// *****************************************************************************
// Section: UART2 Implementation
// *****************************************************************************
// *****************************************************************************

UART_RING_BUFFER_OBJECT uart2Obj;

#define UART2_READ_BUFFER_SIZE      128
#define UART2_READ_BUFFER_SIZE_9BIT (128 >> 1)
#define UART2_RX_INT_DISABLE()      IEC4CLR = _IEC4_U2RXIE_MASK;
#define UART2_RX_INT_ENABLE()       IEC4SET = _IEC4_U2RXIE_MASK;

static uint8_t UART2_ReadBuffer[UART2_READ_BUFFER_SIZE];

#define UART2_WRITE_BUFFER_SIZE     2
#define UART2_WRITE_BUFFER_SIZE_9BIT       (2 >> 1)
#define UART2_TX_INT_DISABLE()      IEC4CLR = _IEC4_U2TXIE_MASK;
#define UART2_TX_INT_ENABLE()       IEC4SET = _IEC4_U2TXIE_MASK;

static uint8_t UART2_WriteBuffer[UART2_WRITE_BUFFER_SIZE];

#define UART2_IS_9BIT_MODE_ENABLED()    ( U2MODE & (_U2MODE_PDSEL0_MASK | _U2MODE_PDSEL1_MASK)) == (_U2MODE_PDSEL0_MASK | _U2MODE_PDSEL1_MASK) ? true:false

void static UART2_ErrorClear( void )
{
    UART_ERROR errors = UART_ERROR_NONE;
    uint8_t dummyData = 0u;

    errors = (UART_ERROR)(U2STA & (_U2STA_OERR_MASK | _U2STA_FERR_MASK | _U2STA_PERR_MASK));

    if(errors != UART_ERROR_NONE)
    {
        /* If it's a overrun error then clear it to flush FIFO */
        if(U2STA & _U2STA_OERR_MASK)
        {
            U2STACLR = _U2STA_OERR_MASK;
        }

        /* Read existing error bytes from FIFO to clear parity and framing error flags */
        while(U2STA & _U2STA_URXDA_MASK)
        {
            dummyData = U2RXREG;
        }

        /* Clear error interrupt flag */
        IFS4CLR = _IFS4_U2EIF_MASK;

        /* Clear up the receive interrupt flag so that RX interrupt is not
         * triggered for error bytes */
        IFS4CLR = _IFS4_U2RXIF_MASK;

    }

    // Ignore the warning
    (void)dummyData;
}

void UART2_Initialize( void )
{
    /* Set up UxMODE bits */
    /* STSEL  = 0 */
    /* PDSEL = 0 */

    U2MODE = 0x8;

    /* Enable UART2 Receiver and Transmitter */
    U2STASET = (_U2STA_UTXEN_MASK | _U2STA_URXEN_MASK | _U2STA_UTXISEL1_MASK );

    /* BAUD Rate register Setup */
    U2BRG = 216;

    /* Disable Interrupts */
    IEC4CLR = _IEC4_U2EIE_MASK;

    IEC4CLR = _IEC4_U2RXIE_MASK;

    IEC4CLR = _IEC4_U2TXIE_MASK;

    /* Initialize instance object */
    uart2Obj.rdCallback = NULL;
    uart2Obj.rdInIndex = 0;
    uart2Obj.rdOutIndex = 0;
    uart2Obj.isRdNotificationEnabled = false;
    uart2Obj.isRdNotifyPersistently = false;
    uart2Obj.rdThreshold = 0;

    uart2Obj.wrCallback = NULL;
    uart2Obj.wrInIndex = 0;
    uart2Obj.wrOutIndex = 0;
    uart2Obj.isWrNotificationEnabled = false;
    uart2Obj.isWrNotifyPersistently = false;
    uart2Obj.wrThreshold = 0;

    uart2Obj.errors = UART_ERROR_NONE;

    if (UART2_IS_9BIT_MODE_ENABLED())
    {
        uart2Obj.rdBufferSize = UART2_READ_BUFFER_SIZE_9BIT;
        uart2Obj.wrBufferSize = UART2_WRITE_BUFFER_SIZE_9BIT;
    }
    else
    {
        uart2Obj.rdBufferSize = UART2_READ_BUFFER_SIZE;
        uart2Obj.wrBufferSize = UART2_WRITE_BUFFER_SIZE;
    }


    /* Turn ON UART2 */
    U2MODESET = _U2MODE_ON_MASK;

    /* Enable UART2_FAULT Interrupt */
    IEC4SET = _IEC4_U2EIE_MASK;

    /* Enable UART2_RX Interrupt */
    IEC4SET = _IEC4_U2RXIE_MASK;
}

bool UART2_SerialSetup( UART_SERIAL_SETUP *setup, uint32_t srcClkFreq )
{
    bool status = false;
    uint32_t baud;
    int32_t brgValHigh = 0;
    int32_t brgValLow = 0;
    uint32_t brgVal = 0;
    uint32_t uartMode;

    if (setup != NULL)
    {
        baud = setup->baudRate;

        if (baud == 0)
        {
            return status;
        }

        if(srcClkFreq == 0)
        {
            srcClkFreq = UART2_FrequencyGet();
        }

        /* Calculate BRG value */
        brgValLow = (((srcClkFreq >> 4) + (baud >> 1)) / baud ) - 1;
        brgValHigh = (((srcClkFreq >> 2) + (baud >> 1)) / baud ) - 1;

        /* Check if the baud value can be set with low baud settings */
        if((brgValLow >= 0) && (brgValLow <= UINT16_MAX))
        {
            brgVal =  brgValLow;
            U2MODECLR = _U2MODE_BRGH_MASK;
        }
        else if ((brgValHigh >= 0) && (brgValHigh <= UINT16_MAX))
        {
            brgVal = brgValHigh;
            U2MODESET = _U2MODE_BRGH_MASK;
        }
        else
        {
            return status;
        }

        if(setup->dataWidth == UART_DATA_9_BIT)
        {
            if(setup->parity != UART_PARITY_NONE)
            {
               return status;
            }
            else
            {
               /* Configure UART2 mode */
               uartMode = U2MODE;
               uartMode &= ~_U2MODE_PDSEL_MASK;
               U2MODE = uartMode | setup->dataWidth;
            }
        }
        else
        {
            /* Configure UART2 mode */
            uartMode = U2MODE;
            uartMode &= ~_U2MODE_PDSEL_MASK;
            U2MODE = uartMode | setup->parity ;
        }

        /* Configure UART2 mode */
        uartMode = U2MODE;
        uartMode &= ~_U2MODE_STSEL_MASK;
        U2MODE = uartMode | setup->stopBits ;

        /* Configure UART2 Baud Rate */
        U2BRG = brgVal;

        if (UART2_IS_9BIT_MODE_ENABLED())
        {
            uart2Obj.rdBufferSize = UART2_READ_BUFFER_SIZE_9BIT;
            uart2Obj.wrBufferSize = UART2_WRITE_BUFFER_SIZE_9BIT;
        }
        else
        {
            uart2Obj.rdBufferSize = UART2_READ_BUFFER_SIZE;
            uart2Obj.wrBufferSize = UART2_WRITE_BUFFER_SIZE;
        }

        status = true;
    }

    return status;
}

/* This routine is only called from ISR. Hence do not disable/enable USART interrupts. */
static inline bool UART2_RxPushByte(uint16_t rdByte)
{
    uint32_t tempInIndex;
    bool isSuccess = false;

    tempInIndex = uart2Obj.rdInIndex + 1;

    if (tempInIndex >= uart2Obj.rdBufferSize)
    {
        tempInIndex = 0;
    }

    if (tempInIndex == uart2Obj.rdOutIndex)
    {
        /* Queue is full - Report it to the application. Application gets a chance to free up space by reading data out from the RX ring buffer */
        if(uart2Obj.rdCallback != NULL)
        {
            uart2Obj.rdCallback(UART_EVENT_READ_BUFFER_FULL, uart2Obj.rdContext);

            /* Read the indices again in case application has freed up space in RX ring buffer */
            tempInIndex = uart2Obj.rdInIndex + 1;

            if (tempInIndex >= uart2Obj.rdBufferSize)
            {
                tempInIndex = 0;
            }
        }
    }

    /* Attempt to push the data into the ring buffer */
    if (tempInIndex != uart2Obj.rdOutIndex)
    {
        if (UART2_IS_9BIT_MODE_ENABLED())
        {
            ((uint16_t*)&UART2_ReadBuffer)[uart2Obj.rdInIndex] = rdByte;
        }
        else
        {
            UART2_ReadBuffer[uart2Obj.rdInIndex] = (uint8_t)rdByte;
        }

        uart2Obj.rdInIndex = tempInIndex;

        isSuccess = true;
    }
    else
    {
        /* Queue is full. Data will be lost. */
    }

    return isSuccess;
}

/* This routine is only called from ISR. Hence do not disable/enable USART interrupts. */
static void UART2_ReadNotificationSend(void)
{
    uint32_t nUnreadBytesAvailable;

    if (uart2Obj.isRdNotificationEnabled == true)
    {
        nUnreadBytesAvailable = UART2_ReadCountGet();

        if(uart2Obj.rdCallback != NULL)
        {
            if (uart2Obj.isRdNotifyPersistently == true)
            {
                if (nUnreadBytesAvailable >= uart2Obj.rdThreshold)
                {
                    uart2Obj.rdCallback(UART_EVENT_READ_THRESHOLD_REACHED, uart2Obj.rdContext);
                }
            }
            else
            {
                if (nUnreadBytesAvailable == uart2Obj.rdThreshold)
                {
                    uart2Obj.rdCallback(UART_EVENT_READ_THRESHOLD_REACHED, uart2Obj.rdContext);
                }
            }
        }
    }
}

size_t UART2_Read(uint8_t* pRdBuffer, const size_t size)
{
    size_t nBytesRead = 0;
    uint32_t rdOutIndex = 0;
    uint32_t rdInIndex = 0;

    /* Take a snapshot of indices to avoid creation of critical section */
    rdOutIndex = uart2Obj.rdOutIndex;
    rdInIndex = uart2Obj.rdInIndex;

    while (nBytesRead < size)
    {
        if (rdOutIndex != rdInIndex)
        {
            if (UART2_IS_9BIT_MODE_ENABLED())
            {
                ((uint16_t*)pRdBuffer)[nBytesRead++] = ((uint16_t*)&UART2_ReadBuffer)[rdOutIndex++];
            }
            else
            {
                pRdBuffer[nBytesRead++] = UART2_ReadBuffer[rdOutIndex++];
            }

            if (rdOutIndex >= uart2Obj.rdBufferSize)
            {
                rdOutIndex = 0;
            }
        }
        else
        {
            /* No more data available in the RX buffer */
            break;
        }
    }

    uart2Obj.rdOutIndex = rdOutIndex;

    return nBytesRead;
}

size_t UART2_ReadCountGet(void)
{
    size_t nUnreadBytesAvailable;
    uint32_t rdInIndex;
    uint32_t rdOutIndex;

    /* Take a snapshot of indices to avoid processing in critical section */
    rdInIndex = uart2Obj.rdInIndex;
    rdOutIndex = uart2Obj.rdOutIndex;

    if ( rdInIndex >=  rdOutIndex)
    {
        nUnreadBytesAvailable =  rdInIndex -  rdOutIndex;
    }
    else
    {
        nUnreadBytesAvailable =  (uart2Obj.rdBufferSize -  rdOutIndex) + rdInIndex;
    }

    return nUnreadBytesAvailable;
}

size_t UART2_ReadFreeBufferCountGet(void)
{
    return (uart2Obj.rdBufferSize - 1) - UART2_ReadCountGet();
}

size_t UART2_ReadBufferSizeGet(void)
{
    return (uart2Obj.rdBufferSize - 1);
}

bool UART2_ReadNotificationEnable(bool isEnabled, bool isPersistent)
{
    bool previousStatus = uart2Obj.isRdNotificationEnabled;

    uart2Obj.isRdNotificationEnabled = isEnabled;

    uart2Obj.isRdNotifyPersistently = isPersistent;

    return previousStatus;
}

void UART2_ReadThresholdSet(uint32_t nBytesThreshold)
{
    if (nBytesThreshold > 0)
    {
        uart2Obj.rdThreshold = nBytesThreshold;
    }
}

void UART2_ReadCallbackRegister( UART_RING_BUFFER_CALLBACK callback, uintptr_t context)
{
    uart2Obj.rdCallback = callback;

    uart2Obj.rdContext = context;
}

/* This routine is only called from ISR. Hence do not disable/enable USART interrupts. */
static bool UART2_TxPullByte(uint16_t* pWrByte)
{
    bool isSuccess = false;
    uint32_t wrOutIndex = uart2Obj.wrOutIndex;
    uint32_t wrInIndex = uart2Obj.wrInIndex;

    if (wrOutIndex != wrInIndex)
    {
        if (UART2_IS_9BIT_MODE_ENABLED())
        {
            *pWrByte = ((uint16_t*)&UART2_WriteBuffer)[wrOutIndex++];
        }
        else
        {
            *pWrByte = UART2_WriteBuffer[wrOutIndex++];
        }

        if (wrOutIndex >= uart2Obj.wrBufferSize)
        {
            wrOutIndex = 0;
        }

        uart2Obj.wrOutIndex = wrOutIndex;

        isSuccess = true;
    }

    return isSuccess;
}

static inline bool UART2_TxPushByte(uint16_t wrByte)
{
    uint32_t tempInIndex;
    bool isSuccess = false;

    uint32_t wrOutIndex = uart2Obj.wrOutIndex;
    uint32_t wrInIndex = uart2Obj.wrInIndex;

    tempInIndex = wrInIndex + 1;

    if (tempInIndex >= uart2Obj.wrBufferSize)
    {
        tempInIndex = 0;
    }
    if (tempInIndex != wrOutIndex)
    {
        if (UART2_IS_9BIT_MODE_ENABLED())
        {
            ((uint16_t*)&UART2_WriteBuffer)[wrInIndex] = wrByte;
        }
        else
        {
            UART2_WriteBuffer[wrInIndex] = (uint8_t)wrByte;
        }

        uart2Obj.wrInIndex = tempInIndex;

        isSuccess = true;
    }
    else
    {
        /* Queue is full. Report Error. */
    }

    return isSuccess;
}

/* This routine is only called from ISR. Hence do not disable/enable USART interrupts. */
static void UART2_WriteNotificationSend(void)
{
    uint32_t nFreeWrBufferCount;

    if (uart2Obj.isWrNotificationEnabled == true)
    {
        nFreeWrBufferCount = UART2_WriteFreeBufferCountGet();

        if(uart2Obj.wrCallback != NULL)
        {
            if (uart2Obj.isWrNotifyPersistently == true)
            {
                if (nFreeWrBufferCount >= uart2Obj.wrThreshold)
                {
                    uart2Obj.wrCallback(UART_EVENT_WRITE_THRESHOLD_REACHED, uart2Obj.wrContext);
                }
            }
            else
            {
                if (nFreeWrBufferCount == uart2Obj.wrThreshold)
                {
                    uart2Obj.wrCallback(UART_EVENT_WRITE_THRESHOLD_REACHED, uart2Obj.wrContext);
                }
            }
        }
    }
}

static size_t UART2_WritePendingBytesGet(void)
{
    size_t nPendingTxBytes;

    /* Take a snapshot of indices to avoid processing in critical section */

    uint32_t wrOutIndex = uart2Obj.wrOutIndex;
    uint32_t wrInIndex = uart2Obj.wrInIndex;

    if ( wrInIndex >=  wrOutIndex)
    {
        nPendingTxBytes =  wrInIndex - wrOutIndex;
    }
    else
    {
        nPendingTxBytes =  (uart2Obj.wrBufferSize -  wrOutIndex) + wrInIndex;
    }

    return nPendingTxBytes;
}

size_t UART2_WriteCountGet(void)
{
    size_t nPendingTxBytes;

    nPendingTxBytes = UART2_WritePendingBytesGet();

    return nPendingTxBytes;
}

size_t UART2_Write(uint8_t* pWrBuffer, const size_t size )
{
    size_t nBytesWritten  = 0;

    while (nBytesWritten < size)
    {
        if (UART2_IS_9BIT_MODE_ENABLED())
        {
            if (UART2_TxPushByte(((uint16_t*)pWrBuffer)[nBytesWritten]) == true)
            {
                nBytesWritten++;
            }
            else
            {
                /* Queue is full, exit the loop */
                break;
            }
        }
        else
        {
            if (UART2_TxPushByte(pWrBuffer[nBytesWritten]) == true)
            {
                nBytesWritten++;
            }
            else
            {
                /* Queue is full, exit the loop */
                break;
            }
        }

    }

    /* Check if any data is pending for transmission */
    if (UART2_WritePendingBytesGet() > 0)
    {
        /* Enable TX interrupt as data is pending for transmission */
        UART2_TX_INT_ENABLE();
    }

    return nBytesWritten;
}

size_t UART2_WriteFreeBufferCountGet(void)
{
    return (uart2Obj.wrBufferSize - 1) - UART2_WriteCountGet();
}

size_t UART2_WriteBufferSizeGet(void)
{
    return (uart2Obj.wrBufferSize - 1);
}

bool UART2_WriteNotificationEnable(bool isEnabled, bool isPersistent)
{
    bool previousStatus = uart2Obj.isWrNotificationEnabled;

    uart2Obj.isWrNotificationEnabled = isEnabled;

    uart2Obj.isWrNotifyPersistently = isPersistent;

    return previousStatus;
}

void UART2_WriteThresholdSet(uint32_t nBytesThreshold)
{
    if (nBytesThreshold > 0)
    {
        uart2Obj.wrThreshold = nBytesThreshold;
    }
}

void UART2_WriteCallbackRegister( UART_RING_BUFFER_CALLBACK callback, uintptr_t context)
{
    uart2Obj.wrCallback = callback;

    uart2Obj.wrContext = context;
}

UART_ERROR UART2_ErrorGet( void )
{
    UART_ERROR errors = uart2Obj.errors;

    uart2Obj.errors = UART_ERROR_NONE;

    /* All errors are cleared, but send the previous error state */
    return errors;
}

bool UART2_AutoBaudQuery( void )
{
    if(U2MODE & _U2MODE_ABAUD_MASK)
        return true;
    else
        return false;
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

void UART2_FAULT_InterruptHandler (void)
{
    /* Save the error to be reported later */
    uart2Obj.errors = (UART_ERROR)(U2STA & (_U2STA_OERR_MASK | _U2STA_FERR_MASK | _U2STA_PERR_MASK));

    UART2_ErrorClear();

    /* Client must call UARTx_ErrorGet() function to clear the errors */
    if( uart2Obj.rdCallback != NULL )
    {
        uart2Obj.rdCallback(UART_EVENT_READ_ERROR, uart2Obj.rdContext);
    }
}

void UART2_RX_InterruptHandler (void)
{
    /* Keep reading until there is a character availabe in the RX FIFO */
    while((U2STA & _U2STA_URXDA_MASK) == _U2STA_URXDA_MASK)
    {
        if (UART2_RxPushByte( (uint16_t )(U2RXREG) ) == true)
        {
            UART2_ReadNotificationSend();
        }
        else
        {
            /* UART RX buffer is full */
        }
    }

    /* Clear UART2 RX Interrupt flag */
    IFS4CLR = _IFS4_U2RXIF_MASK;
}

void UART2_TX_InterruptHandler (void)
{
    uint16_t wrByte;

    /* Check if any data is pending for transmission */
    if (UART2_WritePendingBytesGet() > 0)
    {
        /* Keep writing to the TX FIFO as long as there is space */
        while(!(U2STA & _U2STA_UTXBF_MASK))
        {
            if (UART2_TxPullByte(&wrByte) == true)
            {
                if (UART2_IS_9BIT_MODE_ENABLED())
                {
                    U2TXREG = wrByte;
                }
                else
                {
                    U2TXREG = (uint8_t)wrByte;
                }

                /* Send notification */
                UART2_WriteNotificationSend();
            }
            else
            {
                /* Nothing to transmit. Disable the data register empty interrupt. */
                UART2_TX_INT_DISABLE();
                break;
            }
        }

        /* Clear UART2TX Interrupt flag */
        IFS4CLR = _IFS4_U2TXIF_MASK;
    }
    else
    {
        /* Nothing to transmit. Disable the data register empty interrupt. */
        UART2_TX_INT_DISABLE();

        /* Clear UART2TX Interrupt flag */
        IFS4CLR = _IFS4_U2TXIF_MASK;
    }
}

