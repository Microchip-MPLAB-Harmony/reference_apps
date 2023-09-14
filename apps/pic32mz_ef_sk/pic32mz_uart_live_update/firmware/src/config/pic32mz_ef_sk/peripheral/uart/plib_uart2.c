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

volatile static UART_RING_BUFFER_OBJECT uart2Obj;

#define UART2_READ_BUFFER_SIZE      (128U)
#define UART2_READ_BUFFER_SIZE_9BIT (128U >> 1)
#define UART2_RX_INT_DISABLE()      IEC4CLR = _IEC4_U2RXIE_MASK;
#define UART2_RX_INT_ENABLE()       IEC4SET = _IEC4_U2RXIE_MASK;

volatile static uint8_t UART2_ReadBuffer[UART2_READ_BUFFER_SIZE];

#define UART2_WRITE_BUFFER_SIZE      (2U)
#define UART2_WRITE_BUFFER_SIZE_9BIT (2U >> 1)
#define UART2_TX_INT_DISABLE()       IEC4CLR = _IEC4_U2TXIE_MASK;
#define UART2_TX_INT_ENABLE()        IEC4SET = _IEC4_U2TXIE_MASK;

volatile static uint8_t UART2_WriteBuffer[UART2_WRITE_BUFFER_SIZE];

#define UART2_IS_9BIT_MODE_ENABLED()    ( (U2MODE) & (_U2MODE_PDSEL0_MASK | _U2MODE_PDSEL1_MASK)) == (_U2MODE_PDSEL0_MASK | _U2MODE_PDSEL1_MASK) ? true:false

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

        U2MODESET = _U2MODE_ON_MASK;

        /* Restore UTXEN, URXEN and UTXBRK bits. */
        U2STASET = status_ctrl;

        status = true;
    }

    return status;
}

/* This routine is only called from ISR. Hence do not disable/enable USART interrupts. */
static inline bool UART2_RxPushByte(uint16_t rdByte)
{
    uint32_t tempInIndex;
    bool isSuccess = false;
    uint32_t rdInIdx;

    tempInIndex = uart2Obj.rdInIndex + 1U;

    if (tempInIndex >= uart2Obj.rdBufferSize)
    {
        tempInIndex = 0U;
    }

    if (tempInIndex == uart2Obj.rdOutIndex)
    {
        /* Queue is full - Report it to the application. Application gets a chance to free up space by reading data out from the RX ring buffer */
        if(uart2Obj.rdCallback != NULL)
        {
            uintptr_t rdContext = uart2Obj.rdContext;

            uart2Obj.rdCallback(UART_EVENT_READ_BUFFER_FULL, rdContext);

            /* Read the indices again in case application has freed up space in RX ring buffer */
            tempInIndex = uart2Obj.rdInIndex + 1U;

            if (tempInIndex >= uart2Obj.rdBufferSize)
            {
                tempInIndex = 0U;
            }
        }
    }

    /* Attempt to push the data into the ring buffer */
    if (tempInIndex != uart2Obj.rdOutIndex)
    {
        uint32_t rdInIndex = uart2Obj.rdInIndex;

        if (UART2_IS_9BIT_MODE_ENABLED())
        {
            rdInIdx = uart2Obj.rdInIndex << 1U;
            UART2_ReadBuffer[rdInIdx] = (uint8_t)rdByte;
            UART2_ReadBuffer[rdInIdx + 1U] = (uint8_t)(rdByte >> 8U);
        }
        else
        {
            UART2_ReadBuffer[rdInIndex] = (uint8_t)rdByte;
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
            uintptr_t rdContext = uart2Obj.rdContext;

            if (uart2Obj.isRdNotifyPersistently == true)
            {
                if (nUnreadBytesAvailable >= uart2Obj.rdThreshold)
                {
                    uart2Obj.rdCallback(UART_EVENT_READ_THRESHOLD_REACHED, rdContext);
                }
            }
            else
            {
                if (nUnreadBytesAvailable == uart2Obj.rdThreshold)
                {
                    uart2Obj.rdCallback(UART_EVENT_READ_THRESHOLD_REACHED, rdContext);
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
    uint32_t rdOut16Idx;
    uint32_t nBytesRead16Idx;

    /* Take a snapshot of indices to avoid creation of critical section */
    rdOutIndex = uart2Obj.rdOutIndex;
    rdInIndex = uart2Obj.rdInIndex;

    while (nBytesRead < size)
    {
        if (rdOutIndex != rdInIndex)
        {
            if (UART2_IS_9BIT_MODE_ENABLED())
            {
                rdOut16Idx = rdOutIndex << 1U;
                nBytesRead16Idx = nBytesRead << 1U;

                pRdBuffer[nBytesRead16Idx] = UART2_ReadBuffer[rdOut16Idx];
                pRdBuffer[nBytesRead16Idx + 1U] = UART2_ReadBuffer[rdOut16Idx + 1U];
            }
            else
            {
                pRdBuffer[nBytesRead] = UART2_ReadBuffer[rdOutIndex];
            }
            nBytesRead++;
            rdOutIndex++;

            if (rdOutIndex >= uart2Obj.rdBufferSize)
            {
                rdOutIndex = 0U;
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
    return (uart2Obj.rdBufferSize - 1U) - UART2_ReadCountGet();
}

size_t UART2_ReadBufferSizeGet(void)
{
    return (uart2Obj.rdBufferSize - 1U);
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
    if (nBytesThreshold > 0U)
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
    uint32_t wrOut16Idx;

    if (wrOutIndex != wrInIndex)
    {
        if (UART2_IS_9BIT_MODE_ENABLED())
        {
            wrOut16Idx = wrOutIndex << 1U;
            pWrByte[0] = UART2_WriteBuffer[wrOut16Idx];
            pWrByte[1] = UART2_WriteBuffer[wrOut16Idx + 1U];
        }
        else
        {
            *pWrByte = UART2_WriteBuffer[wrOutIndex];
        }
        wrOutIndex++;

        if (wrOutIndex >= uart2Obj.wrBufferSize)
        {
            wrOutIndex = 0U;
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
    uint32_t wrIn16Idx;

    tempInIndex = wrInIndex + 1U;

    if (tempInIndex >= uart2Obj.wrBufferSize)
    {
        tempInIndex = 0U;
    }
    if (tempInIndex != wrOutIndex)
    {
        if (UART2_IS_9BIT_MODE_ENABLED())
        {
            wrIn16Idx = wrInIndex << 1U;
            UART2_WriteBuffer[wrIn16Idx] = (uint8_t)wrByte;
            UART2_WriteBuffer[wrIn16Idx + 1U] = (uint8_t)(wrByte >> 8U);
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
            uintptr_t wrContext = uart2Obj.wrContext;

            if (uart2Obj.isWrNotifyPersistently == true)
            {
                if (nFreeWrBufferCount >= uart2Obj.wrThreshold)
                {
                    uart2Obj.wrCallback(UART_EVENT_WRITE_THRESHOLD_REACHED, wrContext);
                }
            }
            else
            {
                if (nFreeWrBufferCount == uart2Obj.wrThreshold)
                {
                    uart2Obj.wrCallback(UART_EVENT_WRITE_THRESHOLD_REACHED, wrContext);
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
    uint16_t halfWordData = 0U;

    while (nBytesWritten < size)
    {
        if (UART2_IS_9BIT_MODE_ENABLED())
        {
            halfWordData = pWrBuffer[(2U * nBytesWritten) + 1U];
            halfWordData <<= 8U;
            halfWordData |= pWrBuffer[(2U * nBytesWritten)];
            if (UART2_TxPushByte(halfWordData) == true)
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
    if (UART2_WritePendingBytesGet() > 0U)
    {
        /* Enable TX interrupt as data is pending for transmission */
        UART2_TX_INT_ENABLE();
    }

    return nBytesWritten;
}

size_t UART2_WriteFreeBufferCountGet(void)
{
    return (uart2Obj.wrBufferSize - 1U) - UART2_WriteCountGet();
}

size_t UART2_WriteBufferSizeGet(void)
{
    return (uart2Obj.wrBufferSize - 1U);
}

bool UART2_TransmitComplete( void )
{
    bool transmitcompltecheck = false;
    if((U2STA & _U2STA_TRMT_MASK) != 0U)
    {
        transmitcompltecheck = true;
    }
    return transmitcompltecheck;
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
    if (nBytesThreshold > 0U)
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
    bool autobaudq_check = false;
    if((U2MODE & _U2MODE_ABAUD_MASK) != 0U)
    {
         autobaudq_check = true;
    }
     return autobaudq_check;
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

void __attribute__((used)) UART2_FAULT_InterruptHandler (void)
{
    /* Save the error to be reported later */
    uart2Obj.errors = (UART_ERROR)(U2STA & (_U2STA_OERR_MASK | _U2STA_FERR_MASK | _U2STA_PERR_MASK));

    UART2_ErrorClear();

    /* Client must call UARTx_ErrorGet() function to clear the errors */
    if( uart2Obj.rdCallback != NULL )
    {
        uintptr_t rdContext = uart2Obj.rdContext;

        uart2Obj.rdCallback(UART_EVENT_READ_ERROR, rdContext);
    }
}

void __attribute__((used)) UART2_RX_InterruptHandler (void)
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

void __attribute__((used)) UART2_TX_InterruptHandler (void)
{
    uint16_t wrByte;

    /* Check if any data is pending for transmission */
    if (UART2_WritePendingBytesGet() > 0U)
    {
        /* Keep writing to the TX FIFO as long as there is space */
        while((U2STA & _U2STA_UTXBF_MASK) == 0U)
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

