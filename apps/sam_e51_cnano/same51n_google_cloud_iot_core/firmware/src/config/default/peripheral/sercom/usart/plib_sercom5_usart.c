/*******************************************************************************
  SERCOM Universal Synchronous/Asynchrnous Receiver/Transmitter PLIB

  Company
    Microchip Technology Inc.

  File Name
    plib_sercom5_usart.c

  Summary
    USART peripheral library interface.

  Description
    This file defines the interface to the USART peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

  Remarks:
    None.
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "plib_sercom5_usart.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************


/* SERCOM5 USART baud value for 9600 Hz baud rate */
#define SERCOM5_USART_INT_BAUD_VALUE            (65368U)

SERCOM_USART_RING_BUFFER_OBJECT sercom5USARTObj;

// *****************************************************************************
// *****************************************************************************
// Section: SERCOM5 USART Interface Routines
// *****************************************************************************
// *****************************************************************************

#define SERCOM5_USART_READ_BUFFER_SIZE      128
#define SERCOM5_USART_RX_INT_DISABLE()      SERCOM5_REGS->USART_INT.SERCOM_INTENCLR = SERCOM_USART_INT_INTENCLR_RXC_Msk
#define SERCOM5_USART_RX_INT_ENABLE()       SERCOM5_REGS->USART_INT.SERCOM_INTENSET = SERCOM_USART_INT_INTENSET_RXC_Msk

static uint8_t SERCOM5_USART_ReadBuffer[SERCOM5_USART_READ_BUFFER_SIZE];

#define SERCOM5_USART_WRITE_BUFFER_SIZE     2048
#define SERCOM5_USART_TX_INT_DISABLE()      SERCOM5_REGS->USART_INT.SERCOM_INTENCLR = SERCOM_USART_INT_INTENCLR_DRE_Msk
#define SERCOM5_USART_TX_INT_ENABLE()       SERCOM5_REGS->USART_INT.SERCOM_INTENSET = SERCOM_USART_INT_INTENSET_DRE_Msk

static uint8_t SERCOM5_USART_WriteBuffer[SERCOM5_USART_WRITE_BUFFER_SIZE];

void SERCOM5_USART_Initialize( void )
{
    /*
     * Configures USART Clock Mode
     * Configures TXPO and RXPO
     * Configures Data Order
     * Configures Standby Mode
     * Configures Sampling rate
     * Configures IBON
     */
    SERCOM5_REGS->USART_INT.SERCOM_CTRLA = SERCOM_USART_INT_CTRLA_MODE_USART_INT_CLK | SERCOM_USART_INT_CTRLA_RXPO(0x1) | SERCOM_USART_INT_CTRLA_TXPO(0x0) | SERCOM_USART_INT_CTRLA_DORD_Msk | SERCOM_USART_INT_CTRLA_IBON_Msk | SERCOM_USART_INT_CTRLA_FORM(0x0) | SERCOM_USART_INT_CTRLA_SAMPR(0) ;

    /* Configure Baud Rate */
    SERCOM5_REGS->USART_INT.SERCOM_BAUD = SERCOM_USART_INT_BAUD_BAUD(SERCOM5_USART_INT_BAUD_VALUE);

    /*
     * Configures RXEN
     * Configures TXEN
     * Configures CHSIZE
     * Configures Parity
     * Configures Stop bits
     */
    SERCOM5_REGS->USART_INT.SERCOM_CTRLB = SERCOM_USART_INT_CTRLB_CHSIZE_8_BIT | SERCOM_USART_INT_CTRLB_SBMODE_1_BIT | SERCOM_USART_INT_CTRLB_RXEN_Msk | SERCOM_USART_INT_CTRLB_TXEN_Msk;

    /* Wait for sync */
    while(SERCOM5_REGS->USART_INT.SERCOM_SYNCBUSY);


    /* Enable the UART after the configurations */
    SERCOM5_REGS->USART_INT.SERCOM_CTRLA |= SERCOM_USART_INT_CTRLA_ENABLE_Msk;

    /* Wait for sync */
    while(SERCOM5_REGS->USART_INT.SERCOM_SYNCBUSY);

    /* Initialize instance object */
    sercom5USARTObj.rdCallback = NULL;
    sercom5USARTObj.rdInIndex = 0;
    sercom5USARTObj.rdOutIndex = 0;
    sercom5USARTObj.isRdNotificationEnabled = false;
    sercom5USARTObj.isRdNotifyPersistently = false;
    sercom5USARTObj.rdThreshold = 0;
    sercom5USARTObj.wrCallback = NULL;
    sercom5USARTObj.wrInIndex = 0;
    sercom5USARTObj.wrOutIndex = 0;
    sercom5USARTObj.isWrNotificationEnabled = false;
    sercom5USARTObj.isWrNotifyPersistently = false;
    sercom5USARTObj.wrThreshold = 0;
    /* Enable error interrupt */
    SERCOM5_REGS->USART_INT.SERCOM_INTENSET = SERCOM_USART_INT_INTENSET_ERROR_Msk;

    /* Enable Receive Complete interrupt */
    SERCOM5_REGS->USART_INT.SERCOM_INTENSET = SERCOM_USART_INT_INTENSET_RXC_Msk;
}

uint32_t SERCOM5_USART_FrequencyGet( void )
{
    return (uint32_t) (60000000UL);
}

bool SERCOM5_USART_SerialSetup( USART_SERIAL_SETUP * serialSetup, uint32_t clkFrequency )
{
    bool setupStatus       = false;
    uint32_t baudValue     = 0;
    uint32_t sampleRate    = 0;

    if((serialSetup != NULL) & (serialSetup->baudRate != 0))
    {
        if(clkFrequency == 0)
        {
            clkFrequency = SERCOM5_USART_FrequencyGet();
        }

        if(clkFrequency >= (16 * serialSetup->baudRate))
        {
            baudValue = 65536 - ((uint64_t)65536 * 16 * serialSetup->baudRate) / clkFrequency;
            sampleRate = 0;
        }
        else if(clkFrequency >= (8 * serialSetup->baudRate))
        {
            baudValue = 65536 - ((uint64_t)65536 * 8 * serialSetup->baudRate) / clkFrequency;
            sampleRate = 2;
        }
        else if(clkFrequency >= (3 * serialSetup->baudRate))
        {
            baudValue = 65536 - ((uint64_t)65536 * 3 * serialSetup->baudRate) / clkFrequency;
            sampleRate = 4;
        }

        if(baudValue != 0)
        {
            /* Disable the USART before configurations */
            SERCOM5_REGS->USART_INT.SERCOM_CTRLA &= ~SERCOM_USART_INT_CTRLA_ENABLE_Msk;

            /* Wait for sync */
            while(SERCOM5_REGS->USART_INT.SERCOM_SYNCBUSY);

            /* Configure Baud Rate */
            SERCOM5_REGS->USART_INT.SERCOM_BAUD = SERCOM_USART_INT_BAUD_BAUD(baudValue);

            /* Configure Parity Options */
            if(serialSetup->parity == USART_PARITY_NONE)
            {
                SERCOM5_REGS->USART_INT.SERCOM_CTRLA =  (SERCOM5_REGS->USART_INT.SERCOM_CTRLA & ~(SERCOM_USART_INT_CTRLA_SAMPR_Msk | SERCOM_USART_INT_CTRLA_FORM_Msk)) | SERCOM_USART_INT_CTRLA_FORM(0x0) | SERCOM_USART_INT_CTRLA_SAMPR(sampleRate); 
                SERCOM5_REGS->USART_INT.SERCOM_CTRLB = (SERCOM5_REGS->USART_INT.SERCOM_CTRLB & ~(SERCOM_USART_INT_CTRLB_CHSIZE_Msk | SERCOM_USART_INT_CTRLB_SBMODE_Pos)) | ((uint32_t) serialSetup->dataWidth | (uint32_t) serialSetup->stopBits);
            }
            else
            {
                SERCOM5_REGS->USART_INT.SERCOM_CTRLA =  (SERCOM5_REGS->USART_INT.SERCOM_CTRLA & ~(SERCOM_USART_INT_CTRLA_SAMPR_Msk | SERCOM_USART_INT_CTRLA_FORM_Msk)) | SERCOM_USART_INT_CTRLA_FORM(0x1) | SERCOM_USART_INT_CTRLA_SAMPR(sampleRate); 
                SERCOM5_REGS->USART_INT.SERCOM_CTRLB = (SERCOM5_REGS->USART_INT.SERCOM_CTRLB & ~(SERCOM_USART_INT_CTRLB_CHSIZE_Msk | SERCOM_USART_INT_CTRLB_SBMODE_Pos | SERCOM_USART_INT_CTRLB_PMODE_Msk)) | (uint32_t) serialSetup->dataWidth | (uint32_t) serialSetup->stopBits | (uint32_t) serialSetup->parity ;
            }

            /* Wait for sync */
            while(SERCOM5_REGS->USART_INT.SERCOM_SYNCBUSY);

            /* Enable the USART after the configurations */
            SERCOM5_REGS->USART_INT.SERCOM_CTRLA |= SERCOM_USART_INT_CTRLA_ENABLE_Msk;

            /* Wait for sync */
            while(SERCOM5_REGS->USART_INT.SERCOM_SYNCBUSY);

            setupStatus = true;
        }
    }

    return setupStatus;
}

void static SERCOM5_USART_ErrorClear( void )
{
    uint8_t  u8dummyData = 0;

    /* Clear error flag */
    SERCOM5_REGS->USART_INT.SERCOM_INTFLAG = SERCOM_USART_INT_INTFLAG_ERROR_Msk;

    /* Clear all errors */
    SERCOM5_REGS->USART_INT.SERCOM_STATUS = SERCOM_USART_INT_STATUS_PERR_Msk | SERCOM_USART_INT_STATUS_FERR_Msk | SERCOM_USART_INT_STATUS_BUFOVF_Msk ;

    /* Flush existing error bytes from the RX FIFO */
    while((SERCOM5_REGS->USART_INT.SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_RXC_Msk) == SERCOM_USART_INT_INTFLAG_RXC_Msk)
    {
        u8dummyData = SERCOM5_REGS->USART_INT.SERCOM_DATA;
    }

    /* Ignore the warning */
    (void)u8dummyData;
}

USART_ERROR SERCOM5_USART_ErrorGet( void )
{
    USART_ERROR errorStatus = USART_ERROR_NONE;

    errorStatus = (USART_ERROR) (SERCOM5_REGS->USART_INT.SERCOM_STATUS & (SERCOM_USART_INT_STATUS_PERR_Msk | SERCOM_USART_INT_STATUS_FERR_Msk | SERCOM_USART_INT_STATUS_BUFOVF_Msk ));

    if(errorStatus != USART_ERROR_NONE)
    {
        SERCOM5_USART_ErrorClear();
    }

    return errorStatus;
}


/* This routine is only called from ISR. Hence do not disable/enable USART interrupts. */
static inline bool SERCOM5_USART_RxPushByte(uint8_t rdByte)
{
    uint32_t tempInIndex;
    bool isSuccess = false;

    tempInIndex = sercom5USARTObj.rdInIndex + 1;

    if (tempInIndex >= SERCOM5_USART_READ_BUFFER_SIZE)
    {
        tempInIndex = 0;
    }

    if (tempInIndex == sercom5USARTObj.rdOutIndex)
    {
        /* Queue is full - Report it to the application. Application gets a chance to free up space by reading data out from the RX ring buffer */
        if(sercom5USARTObj.rdCallback != NULL)
        {
            sercom5USARTObj.rdCallback(SERCOM_USART_EVENT_READ_BUFFER_FULL, sercom5USARTObj.rdContext);

            /* Read the indices again in case application has freed up space in RX ring buffer */
            tempInIndex = sercom5USARTObj.rdInIndex + 1;

            if (tempInIndex >= SERCOM5_USART_READ_BUFFER_SIZE)
            {
                tempInIndex = 0;
            }
        }
    }

    /* Attempt to push the data into the ring buffer */
    if (tempInIndex != sercom5USARTObj.rdOutIndex)
    {
        SERCOM5_USART_ReadBuffer[sercom5USARTObj.rdInIndex] = rdByte;
        sercom5USARTObj.rdInIndex = tempInIndex;
        isSuccess = true;
    }
    else
    {
        /* Queue is full. Data will be lost. */
    }

    return isSuccess;
}

/* This routine is only called from ISR. Hence do not disable/enable USART interrupts. */
static void SERCOM5_USART_ReadNotificationSend(void)
{
    uint32_t nUnreadBytesAvailable;

    if (sercom5USARTObj.isRdNotificationEnabled == true)
    {
        nUnreadBytesAvailable = SERCOM5_USART_ReadCountGet();

        if(sercom5USARTObj.rdCallback != NULL)
        {
            if (sercom5USARTObj.isRdNotifyPersistently == true)
            {
                if (nUnreadBytesAvailable >= sercom5USARTObj.rdThreshold)
                {
                    sercom5USARTObj.rdCallback(SERCOM_USART_EVENT_READ_THRESHOLD_REACHED, sercom5USARTObj.rdContext);
                }
            }
            else
            {
                if (nUnreadBytesAvailable == sercom5USARTObj.rdThreshold)
                {
                    sercom5USARTObj.rdCallback(SERCOM_USART_EVENT_READ_THRESHOLD_REACHED, sercom5USARTObj.rdContext);
                }
            }
        }
    }
}

size_t SERCOM5_USART_Read(uint8_t* pRdBuffer, const size_t size)
{
    size_t nBytesRead = 0;
    uint32_t rdOutIndex;
    uint32_t rdInIndex;

    while (nBytesRead < size)
    {
        SERCOM5_USART_RX_INT_DISABLE();

        rdOutIndex = sercom5USARTObj.rdOutIndex;
        rdInIndex = sercom5USARTObj.rdInIndex;

        if (rdOutIndex != rdInIndex)
        {
            pRdBuffer[nBytesRead++] = SERCOM5_USART_ReadBuffer[sercom5USARTObj.rdOutIndex++];

            if (sercom5USARTObj.rdOutIndex >= SERCOM5_USART_READ_BUFFER_SIZE)
            {
                sercom5USARTObj.rdOutIndex = 0;
            }
            SERCOM5_USART_RX_INT_ENABLE();
        }
        else
        {
            SERCOM5_USART_RX_INT_ENABLE();
            break;
        }
    }

    return nBytesRead;
}

size_t SERCOM5_USART_ReadCountGet(void)
{
    size_t nUnreadBytesAvailable;
    uint32_t rdOutIndex;
    uint32_t rdInIndex;

    /* Take a snapshot of indices to avoid creation of critical section */
    rdOutIndex = sercom5USARTObj.rdOutIndex;
    rdInIndex = sercom5USARTObj.rdInIndex;

    if ( rdInIndex >=  rdOutIndex)
    {
        nUnreadBytesAvailable =  rdInIndex - rdOutIndex;
    }
    else
    {
        nUnreadBytesAvailable =  (SERCOM5_USART_READ_BUFFER_SIZE -  rdOutIndex) + rdInIndex;
    }

    return nUnreadBytesAvailable;
}

size_t SERCOM5_USART_ReadFreeBufferCountGet(void)
{
    return (SERCOM5_USART_READ_BUFFER_SIZE - 1) - SERCOM5_USART_ReadCountGet();
}

size_t SERCOM5_USART_ReadBufferSizeGet(void)
{
    return (SERCOM5_USART_READ_BUFFER_SIZE - 1);
}

bool SERCOM5_USART_ReadNotificationEnable(bool isEnabled, bool isPersistent)
{
    bool previousStatus = sercom5USARTObj.isRdNotificationEnabled;

    sercom5USARTObj.isRdNotificationEnabled = isEnabled;

    sercom5USARTObj.isRdNotifyPersistently = isPersistent;

    return previousStatus;
}

void SERCOM5_USART_ReadThresholdSet(uint32_t nBytesThreshold)
{
    if (nBytesThreshold > 0)
    {
        sercom5USARTObj.rdThreshold = nBytesThreshold;
    }
}

void SERCOM5_USART_ReadCallbackRegister( SERCOM_USART_RING_BUFFER_CALLBACK callback, uintptr_t context)
{
    sercom5USARTObj.rdCallback = callback;

    sercom5USARTObj.rdContext = context;
}


/* This routine is only called from ISR. Hence do not disable/enable USART interrupts. */
static bool SERCOM5_USART_TxPullByte(uint8_t* pWrByte)
{
    bool isSuccess = false;
    uint32_t wrInIndex = sercom5USARTObj.wrInIndex;
    uint32_t wrOutIndex = sercom5USARTObj.wrOutIndex;

    if (wrOutIndex != wrInIndex)
    {
        *pWrByte = SERCOM5_USART_WriteBuffer[sercom5USARTObj.wrOutIndex++];

        if (sercom5USARTObj.wrOutIndex >= SERCOM5_USART_WRITE_BUFFER_SIZE)
        {
            sercom5USARTObj.wrOutIndex = 0;
        }
        isSuccess = true;
    }

    return isSuccess;
}

static inline bool SERCOM5_USART_TxPushByte(uint8_t wrByte)
{
    uint32_t tempInIndex;
    bool isSuccess = false;

    tempInIndex = sercom5USARTObj.wrInIndex + 1;

    if (tempInIndex >= SERCOM5_USART_WRITE_BUFFER_SIZE)
    {
        tempInIndex = 0;
    }
    if (tempInIndex != sercom5USARTObj.wrOutIndex)
    {
        SERCOM5_USART_WriteBuffer[sercom5USARTObj.wrInIndex] = wrByte;
        sercom5USARTObj.wrInIndex = tempInIndex;
        isSuccess = true;
    }
    else
    {
        /* Queue is full. Report Error. */
    }

    return isSuccess;
}

/* This routine is only called from ISR. Hence do not disable/enable USART interrupts. */
static void SERCOM5_USART_WriteNotificationSend(void)
{
    uint32_t nFreeWrBufferCount;

    if (sercom5USARTObj.isWrNotificationEnabled == true)
    {
        nFreeWrBufferCount = SERCOM5_USART_WriteFreeBufferCountGet();

        if(sercom5USARTObj.wrCallback != NULL)
        {
            if (sercom5USARTObj.isWrNotifyPersistently == true)
            {
                if (nFreeWrBufferCount >= sercom5USARTObj.wrThreshold)
                {
                    sercom5USARTObj.wrCallback(SERCOM_USART_EVENT_WRITE_THRESHOLD_REACHED, sercom5USARTObj.wrContext);
                }
            }
            else
            {
                if (nFreeWrBufferCount == sercom5USARTObj.wrThreshold)
                {
                    sercom5USARTObj.wrCallback(SERCOM_USART_EVENT_WRITE_THRESHOLD_REACHED, sercom5USARTObj.wrContext);
                }
            }
        }
    }
}

static size_t SERCOM5_USART_WritePendingBytesGet(void)
{
    size_t nPendingTxBytes;

    /* Take a snapshot of indices to avoid creation of critical section */
    uint32_t wrInIndex = sercom5USARTObj.wrInIndex;
    uint32_t wrOutIndex = sercom5USARTObj.wrOutIndex;

    if ( wrInIndex >= wrOutIndex)
    {
        nPendingTxBytes =  wrInIndex - wrOutIndex;
    }
    else
    {
        nPendingTxBytes =  (SERCOM5_USART_WRITE_BUFFER_SIZE -  wrOutIndex) + wrInIndex;
    }

    return nPendingTxBytes;
}

size_t SERCOM5_USART_WriteCountGet(void)
{
    size_t nPendingTxBytes;

    nPendingTxBytes = SERCOM5_USART_WritePendingBytesGet();

    return nPendingTxBytes;
}

size_t SERCOM5_USART_Write(uint8_t* pWrBuffer, const size_t size )
{
    size_t nBytesWritten  = 0;

    SERCOM5_USART_TX_INT_DISABLE();

    while (nBytesWritten < size)
    {
        if (SERCOM5_USART_TxPushByte(pWrBuffer[nBytesWritten]) == true)
        {
            nBytesWritten++;
        }
        else
        {
            /* Queue is full, exit the loop */
            break;
        }
    }

    /* Check if any data is pending for transmission */
    if (SERCOM5_USART_WritePendingBytesGet() > 0)
    {
        /* Enable TX interrupt as data is pending for transmission */
        SERCOM5_USART_TX_INT_ENABLE();
    }

    return nBytesWritten;
}

size_t SERCOM5_USART_WriteFreeBufferCountGet(void)
{
    return (SERCOM5_USART_WRITE_BUFFER_SIZE - 1) - SERCOM5_USART_WriteCountGet();
}

size_t SERCOM5_USART_WriteBufferSizeGet(void)
{
    return (SERCOM5_USART_WRITE_BUFFER_SIZE - 1);
}

bool SERCOM5_USART_WriteNotificationEnable(bool isEnabled, bool isPersistent)
{
    bool previousStatus = sercom5USARTObj.isWrNotificationEnabled;

    sercom5USARTObj.isWrNotificationEnabled = isEnabled;

    sercom5USARTObj.isWrNotifyPersistently = isPersistent;

    return previousStatus;
}

void SERCOM5_USART_WriteThresholdSet(uint32_t nBytesThreshold)
{
    if (nBytesThreshold > 0)
    {
        sercom5USARTObj.wrThreshold = nBytesThreshold;
    }
}

void SERCOM5_USART_WriteCallbackRegister( SERCOM_USART_RING_BUFFER_CALLBACK callback, uintptr_t context)
{
    sercom5USARTObj.wrCallback = callback;

    sercom5USARTObj.wrContext = context;
}



void static SERCOM5_USART_ISR_ERR_Handler( void )
{
    USART_ERROR errorStatus = USART_ERROR_NONE;

    errorStatus = (SERCOM5_REGS->USART_INT.SERCOM_STATUS &
                  (SERCOM_USART_INT_STATUS_PERR_Msk |
                  SERCOM_USART_INT_STATUS_FERR_Msk |
                  SERCOM_USART_INT_STATUS_BUFOVF_Msk ));

    if(errorStatus != USART_ERROR_NONE)
    {
        SERCOM5_REGS->USART_INT.SERCOM_INTENCLR = SERCOM_USART_INT_INTENCLR_ERROR_Msk;

        if(sercom5USARTObj.rdCallback != NULL)
        {
            sercom5USARTObj.rdCallback(SERCOM_USART_EVENT_READ_ERROR, sercom5USARTObj.rdContext);
        }

        /* In case of errors are not cleared by client using ErrorGet API */
        SERCOM5_USART_ErrorClear();
    }
}

void static SERCOM5_USART_ISR_RX_Handler( void )
{
    if (SERCOM5_USART_RxPushByte( SERCOM5_REGS->USART_INT.SERCOM_DATA) == true)
    {
        SERCOM5_USART_ReadNotificationSend();
    }
    else
    {
        /* UART RX buffer is full */
    }
}

void static SERCOM5_USART_ISR_TX_Handler( void )
{
    uint8_t wrByte;

    if (SERCOM5_USART_TxPullByte(&wrByte) == true)
    {
        SERCOM5_REGS->USART_INT.SERCOM_DATA = wrByte;
    }
    else
    {
        /* Nothing to transmit. Disable the data register empty interrupt. */
        SERCOM5_USART_TX_INT_DISABLE();
    }

    SERCOM5_USART_WriteNotificationSend();
}

void SERCOM5_USART_InterruptHandler( void )
{
    if(SERCOM5_REGS->USART_INT.SERCOM_INTENSET != 0)
    {
        /* Checks for data register empty flag */
        if((SERCOM5_REGS->USART_INT.SERCOM_INTENSET & SERCOM_USART_INT_INTENSET_DRE_Msk) && (SERCOM5_REGS->USART_INT.SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_DRE_Msk))
        {
            SERCOM5_USART_ISR_TX_Handler();
        }

        /* Checks for receive complete empty flag */
        if((SERCOM5_REGS->USART_INT.SERCOM_INTENSET & SERCOM_USART_INT_INTENSET_RXC_Msk) && (SERCOM5_REGS->USART_INT.SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_RXC_Msk))
        {
            SERCOM5_USART_ISR_RX_Handler();
        }

        /* Checks for error flag */
        if((SERCOM5_REGS->USART_INT.SERCOM_INTENSET & SERCOM_USART_INT_INTENSET_ERROR_Msk) && (SERCOM5_REGS->USART_INT.SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_ERROR_Msk))
        {
            SERCOM5_USART_ISR_ERR_Handler();
        }
    }
}