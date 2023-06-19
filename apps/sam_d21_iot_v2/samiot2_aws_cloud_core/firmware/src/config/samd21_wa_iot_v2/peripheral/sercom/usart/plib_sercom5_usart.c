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

#include "interrupts.h"
#include "plib_sercom5_usart.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************


/* SERCOM5 USART baud value for 9600 Hz baud rate */
#define SERCOM5_USART_INT_BAUD_VALUE            (65326UL)

volatile static SERCOM_USART_RING_BUFFER_OBJECT sercom5USARTObj;

// *****************************************************************************
// *****************************************************************************
// Section: SERCOM5 USART Interface Routines
// *****************************************************************************
// *****************************************************************************

#define SERCOM5_USART_READ_BUFFER_SIZE      128U
#define SERCOM5_USART_READ_BUFFER_9BIT_SIZE     (128U >> 1U)
#define SERCOM5_USART_RX_INT_DISABLE()      SERCOM5_REGS->USART_INT.SERCOM_INTENCLR = SERCOM_USART_INT_INTENCLR_RXC_Msk
#define SERCOM5_USART_RX_INT_ENABLE()       SERCOM5_REGS->USART_INT.SERCOM_INTENSET = SERCOM_USART_INT_INTENSET_RXC_Msk

volatile static uint8_t SERCOM5_USART_ReadBuffer[SERCOM5_USART_READ_BUFFER_SIZE];

#define SERCOM5_USART_WRITE_BUFFER_SIZE     1024U
#define SERCOM5_USART_WRITE_BUFFER_9BIT_SIZE  (1024U >> 1U)
#define SERCOM5_USART_TX_INT_DISABLE()      SERCOM5_REGS->USART_INT.SERCOM_INTENCLR = SERCOM_USART_INT_INTENCLR_DRE_Msk
#define SERCOM5_USART_TX_INT_ENABLE()       SERCOM5_REGS->USART_INT.SERCOM_INTENSET = SERCOM_USART_INT_INTENSET_DRE_Msk

volatile static uint8_t SERCOM5_USART_WriteBuffer[SERCOM5_USART_WRITE_BUFFER_SIZE];

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
    SERCOM5_REGS->USART_INT.SERCOM_CTRLA = SERCOM_USART_INT_CTRLA_MODE_USART_INT_CLK | SERCOM_USART_INT_CTRLA_RXPO(0x1UL) | SERCOM_USART_INT_CTRLA_TXPO(0x0UL) | SERCOM_USART_INT_CTRLA_DORD_Msk | SERCOM_USART_INT_CTRLA_IBON_Msk | SERCOM_USART_INT_CTRLA_FORM(0x0UL) | SERCOM_USART_INT_CTRLA_SAMPR(0UL) ;

    /* Configure Baud Rate */
    SERCOM5_REGS->USART_INT.SERCOM_BAUD = (uint16_t)SERCOM_USART_INT_BAUD_BAUD(SERCOM5_USART_INT_BAUD_VALUE);

    /*
     * Configures RXEN
     * Configures TXEN
     * Configures CHSIZE
     * Configures Parity
     * Configures Stop bits
     */
    SERCOM5_REGS->USART_INT.SERCOM_CTRLB = SERCOM_USART_INT_CTRLB_CHSIZE_8_BIT | SERCOM_USART_INT_CTRLB_SBMODE_1_BIT | SERCOM_USART_INT_CTRLB_RXEN_Msk | SERCOM_USART_INT_CTRLB_TXEN_Msk;

    /* Wait for sync */
    while((SERCOM5_REGS->USART_INT.SERCOM_SYNCBUSY) != 0U)
    {
        /* Do nothing */
    }


    /* Enable the UART after the configurations */
    SERCOM5_REGS->USART_INT.SERCOM_CTRLA |= SERCOM_USART_INT_CTRLA_ENABLE_Msk;

    /* Wait for sync */
    while((SERCOM5_REGS->USART_INT.SERCOM_SYNCBUSY) != 0U)
    {
        /* Do nothing */
    }

    /* Initialize instance object */
    sercom5USARTObj.rdCallback = NULL;
    sercom5USARTObj.rdInIndex = 0U;
    sercom5USARTObj.rdOutIndex = 0U;
    sercom5USARTObj.isRdNotificationEnabled = false;
    sercom5USARTObj.isRdNotifyPersistently = false;
    sercom5USARTObj.rdThreshold = 0U;
    sercom5USARTObj.errorStatus = USART_ERROR_NONE;
    sercom5USARTObj.wrCallback = NULL;
    sercom5USARTObj.wrInIndex = 0U;
    sercom5USARTObj.wrOutIndex = 0U;
    sercom5USARTObj.isWrNotificationEnabled = false;
    sercom5USARTObj.isWrNotifyPersistently = false;
    sercom5USARTObj.wrThreshold = 0U;
    if (((SERCOM5_REGS->USART_INT.SERCOM_CTRLB & SERCOM_USART_INT_CTRLB_CHSIZE_Msk) >> SERCOM_USART_INT_CTRLB_CHSIZE_Pos) != 0x01U)
    {
        sercom5USARTObj.rdBufferSize = SERCOM5_USART_READ_BUFFER_SIZE;
        sercom5USARTObj.wrBufferSize = SERCOM5_USART_WRITE_BUFFER_SIZE;
    }
    else
    {
        sercom5USARTObj.rdBufferSize = SERCOM5_USART_READ_BUFFER_9BIT_SIZE;
        sercom5USARTObj.wrBufferSize = SERCOM5_USART_WRITE_BUFFER_9BIT_SIZE;
    }
    /* Enable error interrupt */
    SERCOM5_REGS->USART_INT.SERCOM_INTENSET = (uint8_t)SERCOM_USART_INT_INTENSET_ERROR_Msk;

    /* Enable Receive Complete interrupt */
    SERCOM5_REGS->USART_INT.SERCOM_INTENSET = (uint8_t)SERCOM_USART_INT_INTENSET_RXC_Msk;
}

uint32_t SERCOM5_USART_FrequencyGet( void )
{
    return 48000000UL;
}

bool SERCOM5_USART_SerialSetup( USART_SERIAL_SETUP * serialSetup, uint32_t clkFrequency )
{
    bool setupStatus       = false;
    uint32_t baudValue     = 0U;
    uint32_t sampleRate    = 0U;

    if((serialSetup != NULL) && (serialSetup->baudRate != 0U))
    {
        if(clkFrequency == 0U)
        {
            clkFrequency = SERCOM5_USART_FrequencyGet();
        }

        if(clkFrequency >= (16U * serialSetup->baudRate))
        {
            baudValue = 65536U - (uint32_t)(((uint64_t)65536U * 16U * serialSetup->baudRate) / clkFrequency);
            sampleRate = 0U;
        }
        else if(clkFrequency >= (8U * serialSetup->baudRate))
        {
            baudValue = 65536U - (uint32_t)(((uint64_t)65536U * 8U * serialSetup->baudRate) / clkFrequency);
            sampleRate = 2U;
        }
        else if(clkFrequency >= (3U * serialSetup->baudRate))
        {
            baudValue = 65536U - (uint32_t)(((uint64_t)65536U * 3U * serialSetup->baudRate) / clkFrequency);
            sampleRate = 4U;
        }
        else
        {
            /* Do nothing */
        }

        /* Disable the USART before configurations */
        SERCOM5_REGS->USART_INT.SERCOM_CTRLA &= ~SERCOM_USART_INT_CTRLA_ENABLE_Msk;

        /* Wait for sync */
        while((SERCOM5_REGS->USART_INT.SERCOM_SYNCBUSY) != 0U)
        {
            /* Do nothing */
        }

        /* Configure Baud Rate */
        SERCOM5_REGS->USART_INT.SERCOM_BAUD = (uint16_t)SERCOM_USART_INT_BAUD_BAUD(baudValue);

        /* Configure Parity Options */
        if(serialSetup->parity == USART_PARITY_NONE)
        {
            SERCOM5_REGS->USART_INT.SERCOM_CTRLA =  (SERCOM5_REGS->USART_INT.SERCOM_CTRLA & ~(SERCOM_USART_INT_CTRLA_SAMPR_Msk | SERCOM_USART_INT_CTRLA_FORM_Msk)) | SERCOM_USART_INT_CTRLA_FORM(0x0UL) | SERCOM_USART_INT_CTRLA_SAMPR((uint32_t)sampleRate); 
            SERCOM5_REGS->USART_INT.SERCOM_CTRLB = (SERCOM5_REGS->USART_INT.SERCOM_CTRLB & ~(SERCOM_USART_INT_CTRLB_CHSIZE_Msk | SERCOM_USART_INT_CTRLB_SBMODE_Msk)) | ((uint32_t) serialSetup->dataWidth | (uint32_t) serialSetup->stopBits);
        }
        else
        {
            SERCOM5_REGS->USART_INT.SERCOM_CTRLA =  (SERCOM5_REGS->USART_INT.SERCOM_CTRLA & ~(SERCOM_USART_INT_CTRLA_SAMPR_Msk | SERCOM_USART_INT_CTRLA_FORM_Msk)) | SERCOM_USART_INT_CTRLA_FORM(0x1UL) | SERCOM_USART_INT_CTRLA_SAMPR((uint32_t)sampleRate); 
            SERCOM5_REGS->USART_INT.SERCOM_CTRLB = (SERCOM5_REGS->USART_INT.SERCOM_CTRLB & ~(SERCOM_USART_INT_CTRLB_CHSIZE_Msk | SERCOM_USART_INT_CTRLB_SBMODE_Msk | SERCOM_USART_INT_CTRLB_PMODE_Msk)) | (uint32_t) serialSetup->dataWidth | (uint32_t) serialSetup->stopBits | (uint32_t) serialSetup->parity ;
        }

        /* Wait for sync */
        while((SERCOM5_REGS->USART_INT.SERCOM_SYNCBUSY) != 0U)
        {
            /* Do nothing */
        }

        /* Enable the USART after the configurations */
        SERCOM5_REGS->USART_INT.SERCOM_CTRLA |= SERCOM_USART_INT_CTRLA_ENABLE_Msk;

        /* Wait for sync */
        while((SERCOM5_REGS->USART_INT.SERCOM_SYNCBUSY) != 0U)
        {
            /* Do nothing */
        }


        if (((SERCOM5_REGS->USART_INT.SERCOM_CTRLB & SERCOM_USART_INT_CTRLB_CHSIZE_Msk) >> SERCOM_USART_INT_CTRLB_CHSIZE_Pos) != 0x01U)
        {
            sercom5USARTObj.rdBufferSize = SERCOM5_USART_READ_BUFFER_SIZE;
            sercom5USARTObj.wrBufferSize = SERCOM5_USART_WRITE_BUFFER_SIZE;
        }
        else
        {
            sercom5USARTObj.rdBufferSize = SERCOM5_USART_READ_BUFFER_9BIT_SIZE;
            sercom5USARTObj.wrBufferSize = SERCOM5_USART_WRITE_BUFFER_9BIT_SIZE;
        }

        setupStatus = true;
    }

    return setupStatus;
}

void SERCOM5_USART_Enable( void )
{
    if((SERCOM5_REGS->USART_INT.SERCOM_CTRLA & SERCOM_USART_INT_CTRLA_ENABLE_Msk) == 0U)
    {
        SERCOM5_REGS->USART_INT.SERCOM_CTRLA |= SERCOM_USART_INT_CTRLA_ENABLE_Msk;

        /* Wait for sync */
        while((SERCOM5_REGS->USART_INT.SERCOM_SYNCBUSY) != 0U)
        {
            /* Do nothing */
        }
    }
}

void SERCOM5_USART_Disable( void )
{
    if((SERCOM5_REGS->USART_INT.SERCOM_CTRLA & SERCOM_USART_INT_CTRLA_ENABLE_Msk) != 0U)
    {
        SERCOM5_REGS->USART_INT.SERCOM_CTRLA &= ~SERCOM_USART_INT_CTRLA_ENABLE_Msk;

        /* Wait for sync */
        while((SERCOM5_REGS->USART_INT.SERCOM_SYNCBUSY) != 0U)
        {
            /* Do nothing */
        }
    }
}

void static SERCOM5_USART_ErrorClear( void )
{
    uint16_t  u16dummyData = 0;

    /* Clear error flag */
    SERCOM5_REGS->USART_INT.SERCOM_INTFLAG = SERCOM_USART_INT_INTFLAG_ERROR_Msk;

    /* Clear all errors */
    SERCOM5_REGS->USART_INT.SERCOM_STATUS = SERCOM_USART_INT_STATUS_PERR_Msk | SERCOM_USART_INT_STATUS_FERR_Msk | SERCOM_USART_INT_STATUS_BUFOVF_Msk ;

    /* Flush existing error bytes from the RX FIFO */
    while((SERCOM5_REGS->USART_INT.SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_RXC_Msk) == SERCOM_USART_INT_INTFLAG_RXC_Msk)
    {
        u16dummyData = (uint16_t)SERCOM5_REGS->USART_INT.SERCOM_DATA;
    }

    /* Ignore the warning */
    (void)u16dummyData;
}

USART_ERROR SERCOM5_USART_ErrorGet( void )
{
    USART_ERROR errorStatus = sercom5USARTObj.errorStatus;

    sercom5USARTObj.errorStatus = USART_ERROR_NONE;

    return errorStatus;
}


/* This routine is only called from ISR. Hence do not disable/enable USART interrupts. */
static inline bool SERCOM5_USART_RxPushByte(uint16_t rdByte)
{
    uint32_t tempInIndex;
    uint32_t rdInIdx;
    bool isSuccess = false;

    tempInIndex = sercom5USARTObj.rdInIndex + 1U;

    if (tempInIndex >= sercom5USARTObj.rdBufferSize)
    {
        tempInIndex = 0U;
    }

    if (tempInIndex == sercom5USARTObj.rdOutIndex)
    {
        /* Queue is full - Report it to the application. Application gets a chance to free up space by reading data out from the RX ring buffer */
        if(sercom5USARTObj.rdCallback != NULL)
        {
            uintptr_t rdContext = sercom5USARTObj.rdContext;
            sercom5USARTObj.rdCallback(SERCOM_USART_EVENT_READ_BUFFER_FULL, rdContext);

            /* Read the indices again in case application has freed up space in RX ring buffer */
            tempInIndex = sercom5USARTObj.rdInIndex + 1U;

            if (tempInIndex >= sercom5USARTObj.rdBufferSize)
            {
                tempInIndex = 0U;
            }
        }
    }

    /* Attempt to push the data into the ring buffer */
    if (tempInIndex != sercom5USARTObj.rdOutIndex)
    {
        if (((SERCOM5_REGS->USART_INT.SERCOM_CTRLB & SERCOM_USART_INT_CTRLB_CHSIZE_Msk) >> SERCOM_USART_INT_CTRLB_CHSIZE_Pos) != 0x01U)
        {
            /* 8-bit */
            rdInIdx = sercom5USARTObj.rdInIndex;

            SERCOM5_USART_ReadBuffer[rdInIdx] = (uint8_t)rdByte;
        }
        else
        {
            /* 9-bit */
            rdInIdx = sercom5USARTObj.rdInIndex << 1U;

            SERCOM5_USART_ReadBuffer[rdInIdx] = (uint8_t)rdByte;
            SERCOM5_USART_ReadBuffer[rdInIdx + 1U] = (uint8_t)(rdByte >> 8U);
        }

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
            uintptr_t rdContext = sercom5USARTObj.rdContext;

            if (sercom5USARTObj.isRdNotifyPersistently == true)
            {
                if (nUnreadBytesAvailable >= sercom5USARTObj.rdThreshold)
                {
                    sercom5USARTObj.rdCallback(SERCOM_USART_EVENT_READ_THRESHOLD_REACHED, rdContext);
                }
            }
            else
            {
                if (nUnreadBytesAvailable == sercom5USARTObj.rdThreshold)
                {
                    sercom5USARTObj.rdCallback(SERCOM_USART_EVENT_READ_THRESHOLD_REACHED, rdContext);
                }
            }
        }
    }
}

size_t SERCOM5_USART_Read(uint8_t* pRdBuffer, const size_t size)
{
    size_t nBytesRead = 0U;
    uint32_t rdOutIndex;
    uint32_t rdInIndex;
    uint32_t rdOutIdx;
    uint32_t nBytesReadIdx;

    /* Take a snapshot of indices to avoid creation of critical section */

    rdOutIndex = sercom5USARTObj.rdOutIndex;
    rdInIndex = sercom5USARTObj.rdInIndex;

    while (nBytesRead < size)
    {
        if (rdOutIndex != rdInIndex)
        {
            if (((SERCOM5_REGS->USART_INT.SERCOM_CTRLB & SERCOM_USART_INT_CTRLB_CHSIZE_Msk) >> SERCOM_USART_INT_CTRLB_CHSIZE_Pos) != 0x01U)
            {
                pRdBuffer[nBytesRead] = SERCOM5_USART_ReadBuffer[rdOutIndex];
                nBytesRead += 1U;
                rdOutIndex += 1U;
            }
            else
            {
                rdOutIdx = rdOutIndex << 1U;
                nBytesReadIdx = nBytesRead << 1U;

                pRdBuffer[nBytesReadIdx] = SERCOM5_USART_ReadBuffer[rdOutIdx];
                pRdBuffer[nBytesReadIdx + 1U] = SERCOM5_USART_ReadBuffer[rdOutIdx + 1U];

                rdOutIndex += 1U;
                nBytesRead += 1U;
            }

            if (rdOutIndex >= sercom5USARTObj.rdBufferSize)
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

    sercom5USARTObj.rdOutIndex = rdOutIndex;

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
        nUnreadBytesAvailable =  (sercom5USARTObj.rdBufferSize -  rdOutIndex) + rdInIndex;
    }

    return nUnreadBytesAvailable;
}

size_t SERCOM5_USART_ReadFreeBufferCountGet(void)
{
    return (sercom5USARTObj.rdBufferSize - 1U) - SERCOM5_USART_ReadCountGet();
}

size_t SERCOM5_USART_ReadBufferSizeGet(void)
{
    return (sercom5USARTObj.rdBufferSize - 1U);
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
    if (nBytesThreshold > 0U)
    {
        sercom5USARTObj.rdThreshold = nBytesThreshold;
    }
}

void SERCOM5_USART_ReadCallbackRegister( SERCOM_USART_RING_BUFFER_CALLBACK callback, uintptr_t context)
{
    sercom5USARTObj.rdCallback = callback;

    sercom5USARTObj.rdContext = context;
}


bool SERCOM5_USART_TransmitComplete( void )
{
    bool transmitComplete = false;

    if ((SERCOM5_REGS->USART_INT.SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_TXC_Msk) == SERCOM_USART_INT_INTFLAG_TXC_Msk)
    {
        transmitComplete = true;
    }

    return transmitComplete;
}

/* This routine is only called from ISR. Hence do not disable/enable USART interrupts. */
static bool SERCOM5_USART_TxPullByte(void* pWrData)
{
    bool isSuccess = false;
    uint32_t wrInIndex = sercom5USARTObj.wrInIndex;
    uint32_t wrOutIndex = sercom5USARTObj.wrOutIndex;
    uint32_t wrOutIdx;
    uint8_t* pWrByte = (uint8_t*)pWrData;

    if (wrOutIndex != wrInIndex)
    {
        if (((SERCOM5_REGS->USART_INT.SERCOM_CTRLB & SERCOM_USART_INT_CTRLB_CHSIZE_Msk) >> SERCOM_USART_INT_CTRLB_CHSIZE_Pos) != 0x01U)
        {
            *pWrByte = SERCOM5_USART_WriteBuffer[wrOutIndex];
            wrOutIndex++;
        }
        else
        {
            wrOutIdx = wrOutIndex << 1U;
            pWrByte[0] = SERCOM5_USART_WriteBuffer[wrOutIdx];
            pWrByte[1] = SERCOM5_USART_WriteBuffer[wrOutIdx + 1U];

            wrOutIndex++;
        }


        if (wrOutIndex >= sercom5USARTObj.wrBufferSize)
        {
            wrOutIndex = 0U;
        }

        sercom5USARTObj.wrOutIndex = wrOutIndex;

        isSuccess = true;
    }

    return isSuccess;
}

static inline bool SERCOM5_USART_TxPushByte(uint16_t wrByte)
{
    uint32_t tempInIndex;
    uint32_t wrInIndex = sercom5USARTObj.wrInIndex;
    uint32_t wrOutIndex = sercom5USARTObj.wrOutIndex;
    uint32_t wrInIdx;

    bool isSuccess = false;

    tempInIndex = wrInIndex + 1U;

    if (tempInIndex >= sercom5USARTObj.wrBufferSize)
    {
        tempInIndex = 0U;
    }
    if (tempInIndex != wrOutIndex)
    {
        if (((SERCOM5_REGS->USART_INT.SERCOM_CTRLB & SERCOM_USART_INT_CTRLB_CHSIZE_Msk) >> SERCOM_USART_INT_CTRLB_CHSIZE_Pos) != 0x01U)
        {
            SERCOM5_USART_WriteBuffer[wrInIndex] = (uint8_t)wrByte;
        }
        else
        {
            wrInIdx = wrInIndex << 1U;

            SERCOM5_USART_WriteBuffer[wrInIdx] = (uint8_t)wrByte;
            wrInIdx++;
            SERCOM5_USART_WriteBuffer[wrInIdx] = (uint8_t)(wrByte >> 8U);
        }

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
static void SERCOM5_USART_SendWriteNotification(void)
{
    uint32_t nFreeWrBufferCount;

    if (sercom5USARTObj.isWrNotificationEnabled == true)
    {
        nFreeWrBufferCount = SERCOM5_USART_WriteFreeBufferCountGet();

        if(sercom5USARTObj.wrCallback != NULL)
        {
            uintptr_t wrContext = sercom5USARTObj.wrContext;

            if (sercom5USARTObj.isWrNotifyPersistently == true)
            {
                if (nFreeWrBufferCount >= sercom5USARTObj.wrThreshold)
                {
                    sercom5USARTObj.wrCallback(SERCOM_USART_EVENT_WRITE_THRESHOLD_REACHED, wrContext);
                }
            }
            else
            {
                if (nFreeWrBufferCount == sercom5USARTObj.wrThreshold)
                {
                    sercom5USARTObj.wrCallback(SERCOM_USART_EVENT_WRITE_THRESHOLD_REACHED, wrContext);
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
        nPendingTxBytes =  (sercom5USARTObj.wrBufferSize -  wrOutIndex) + wrInIndex;
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
    size_t nBytesWritten  = 0U;

    while (nBytesWritten < size)
    {
        if (((SERCOM5_REGS->USART_INT.SERCOM_CTRLB & SERCOM_USART_INT_CTRLB_CHSIZE_Msk) >> SERCOM_USART_INT_CTRLB_CHSIZE_Pos) != 0x01U)
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
        else
        {
            uint16_t halfWordData = (uint16_t)(pWrBuffer[(2U * nBytesWritten) + 1U]);
            halfWordData <<= 8U;
            halfWordData |= (uint16_t)pWrBuffer[2U * nBytesWritten];
            if (SERCOM5_USART_TxPushByte(halfWordData) == true)
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
    if (SERCOM5_USART_WritePendingBytesGet() > 0U)
    {
        /* Enable TX interrupt as data is pending for transmission */
        SERCOM5_USART_TX_INT_ENABLE();
    }

    return nBytesWritten;
}

size_t SERCOM5_USART_WriteFreeBufferCountGet(void)
{
    return (sercom5USARTObj.wrBufferSize - 1U) - SERCOM5_USART_WriteCountGet();
}

size_t SERCOM5_USART_WriteBufferSizeGet(void)
{
    return (sercom5USARTObj.wrBufferSize - 1U);
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
    if (nBytesThreshold > 0U)
    {
        sercom5USARTObj.wrThreshold = nBytesThreshold;
    }
}

void SERCOM5_USART_WriteCallbackRegister( SERCOM_USART_RING_BUFFER_CALLBACK callback, uintptr_t context)
{
    sercom5USARTObj.wrCallback = callback;

    sercom5USARTObj.wrContext = context;
}



void static __attribute__((used)) SERCOM5_USART_ISR_ERR_Handler( void )
{
    USART_ERROR errorStatus = (USART_ERROR)(SERCOM5_REGS->USART_INT.SERCOM_STATUS & (SERCOM_USART_INT_STATUS_PERR_Msk | SERCOM_USART_INT_STATUS_FERR_Msk | SERCOM_USART_INT_STATUS_BUFOVF_Msk ));

    if(errorStatus != USART_ERROR_NONE)
    {
        /* Save the error to report later */
        sercom5USARTObj.errorStatus = errorStatus;

        /* Clear error flags and flush the error bytes */
        SERCOM5_USART_ErrorClear();

        if(sercom5USARTObj.rdCallback != NULL)
        {
            uintptr_t rdContext = sercom5USARTObj.rdContext;

            sercom5USARTObj.rdCallback(SERCOM_USART_EVENT_READ_ERROR, rdContext);
        }
    }
}

void static __attribute__((used)) SERCOM5_USART_ISR_RX_Handler( void )
{


    while ((SERCOM5_REGS->USART_INT.SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_RXC_Msk) == SERCOM_USART_INT_INTFLAG_RXC_Msk)
    {
        if (SERCOM5_USART_RxPushByte( (uint16_t)SERCOM5_REGS->USART_INT.SERCOM_DATA) == true)
        {
            SERCOM5_USART_ReadNotificationSend();
        }
        else
        {
            /* UART RX buffer is full */
        }
    }
}

void static __attribute__((used)) SERCOM5_USART_ISR_TX_Handler( void )
{
    uint16_t wrByte;

    while ((SERCOM5_REGS->USART_INT.SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_DRE_Msk) == SERCOM_USART_INT_INTFLAG_DRE_Msk)
    {
        if (SERCOM5_USART_TxPullByte(&wrByte) == true)
        {
            if (((SERCOM5_REGS->USART_INT.SERCOM_CTRLB & SERCOM_USART_INT_CTRLB_CHSIZE_Msk) >> SERCOM_USART_INT_CTRLB_CHSIZE_Pos) != 0x01U)
            {
                SERCOM5_REGS->USART_INT.SERCOM_DATA = (uint8_t)wrByte;
            }
            else
            {
                SERCOM5_REGS->USART_INT.SERCOM_DATA = wrByte;
            }

            SERCOM5_USART_SendWriteNotification();
        }
        else
        {
            /* Nothing to transmit. Disable the data register empty interrupt. */
            SERCOM5_USART_TX_INT_DISABLE();
            break;
        }
    }
}

void __attribute__((used)) SERCOM5_USART_InterruptHandler( void )
{
    bool testCondition = false;
    if(SERCOM5_REGS->USART_INT.SERCOM_INTENSET != 0U)
    {
        /* Checks for error flag */
        testCondition = ((SERCOM5_REGS->USART_INT.SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_ERROR_Msk) == SERCOM_USART_INT_INTFLAG_ERROR_Msk);
        testCondition = ((SERCOM5_REGS->USART_INT.SERCOM_INTENSET & SERCOM_USART_INT_INTENSET_ERROR_Msk) == SERCOM_USART_INT_INTENSET_ERROR_Msk) && testCondition;
        if(testCondition)
        {
            SERCOM5_USART_ISR_ERR_Handler();
        }

        testCondition = ((SERCOM5_REGS->USART_INT.SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_DRE_Msk) == SERCOM_USART_INT_INTFLAG_DRE_Msk);
        testCondition = ((SERCOM5_REGS->USART_INT.SERCOM_INTENSET & SERCOM_USART_INT_INTENSET_DRE_Msk) == SERCOM_USART_INT_INTENSET_DRE_Msk) && testCondition;
        /* Checks for data register empty flag */
        if(testCondition)
        {
            SERCOM5_USART_ISR_TX_Handler();
        }

        /* Checks for receive complete empty flag */
        testCondition = ((SERCOM5_REGS->USART_INT.SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_RXC_Msk) != 0U);
        testCondition = ((SERCOM5_REGS->USART_INT.SERCOM_INTENSET & SERCOM_USART_INT_INTENSET_RXC_Msk) != 0U) && testCondition;
        if(testCondition)
        {
            SERCOM5_USART_ISR_RX_Handler();
        }
    }
}