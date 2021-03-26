/**
 *
 * Copyright (c) 2019 Microchip Technology Inc. and its subsidiaries.
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "platform.h"

#include "definitions.h"

#include "osal/osal.h"
#include "peripheral/sercom/usart/plib_sercom_usart_common.h"
#include "platform_sercom_data.h"

#define USART_RECEIVE_BUFFER_SIZE   512
#define USART_TRANSMIT_BUFFER_SIZE  512

static USART_SERIAL_SETUP sercomSetup;
static OSAL_MUTEX_HANDLE_TYPE usartWriteMutex;

static uint8_t usartReceiveBuffer[USART_RECEIVE_BUFFER_SIZE];
static size_t usartReceiveInOffset;
static size_t usartReceiveOutOffset;
static volatile size_t usartReceiveLength;

static char usartTransmitBuffer[USART_TRANSMIT_BUFFER_SIZE];
static size_t usartTransmitInOffset;
static size_t usartTransmitOutOffset;
static volatile size_t usartTransmitLength;

static void _USARTReceiveEventHandler(uintptr_t context)
{
    usartReceiveInOffset++;
    usartReceiveLength++;

    if (USART_RECEIVE_BUFFER_SIZE == usartReceiveInOffset)
    {
        usartReceiveInOffset = 0;
    }

    platformUsartPlibAPI.read(&usartReceiveBuffer[usartReceiveInOffset], 1);
}

static void _USARTTransmitEventHandler(uintptr_t context)
{
    usartTransmitOutOffset++;
    usartTransmitLength--;

    if (USART_TRANSMIT_BUFFER_SIZE == usartTransmitOutOffset)
    {
        usartTransmitOutOffset = 0;
    }

    if (usartTransmitLength > 0)
    {
        platformUsartPlibAPI.write(&usartTransmitBuffer[usartTransmitOutOffset], 1);
    }
}

static void _USARTInit(uint32_t baud)
{
    sercomSetup.baudRate    = baud;
    sercomSetup.dataWidth   = USART_DATA_8_BIT;
    sercomSetup.parity      = USART_PARITY_NONE;
    sercomSetup.stopBits    = USART_STOP_1_BIT;

    platformUsartPlibAPI.serialSetup(&sercomSetup, 0);

    platformUsartPlibAPI.writeCallbackRegister(&_USARTTransmitEventHandler, 0);
    platformUsartPlibAPI.readCallbackRegister(&_USARTReceiveEventHandler, 0);

    usartTransmitInOffset  = 0;
    usartTransmitOutOffset = 0;
    usartTransmitLength    = 0;

    usartReceiveInOffset   = 0;
    usartReceiveOutOffset  = 0;
    usartReceiveLength     = 0;

    platformUsartPlibAPI.read(&usartReceiveBuffer[usartReceiveInOffset], 1);
}

void SerialBridge_PlatformInit(void)
{
    OSAL_MUTEX_Create(&usartWriteMutex);

    _USARTInit(115200);
}

void SerialBridge_PlatformUARTSetBaudRate(uint32_t baud)
{
    if (sercomSetup.baudRate == baud)
    {
        return;
    }

    if (OSAL_RESULT_TRUE == OSAL_MUTEX_Lock(&usartWriteMutex, OSAL_WAIT_FOREVER))
    {
        while (-1)
        {
            if (false == platformUsartPlibAPI.writeIsBusy())
            {
                if (0 == usartTransmitLength)
                {
                    break;
                }

                platformUsartPlibAPI.write(&usartTransmitBuffer[usartTransmitOutOffset], 1);
            }
        }

        while (0 == (PLATFORM_USART_REGS->USART_INT.SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_TXC_Msk))
        {
        }

        OSAL_MUTEX_Unlock(&usartWriteMutex);
    }

    platformUsartPlibAPI.initialize();

    _USARTInit(baud);
}

size_t SerialBridge_PlatformUARTReadGetCount(void)
{
    size_t count;
    const DRV_USART_INTERRUPT_SOURCES* intInfo = &platformInterruptSources;
    const DRV_USART_MULTI_INT_SRC* multiVector = &(intInfo->intSources.multi);
    bool usartInterruptStatus = false;
    bool usartRxCompleteIntStatus = false;
            
    if (intInfo->isSingleIntSrc == true)
    {
        /* Disable USART interrupt */
        usartInterruptStatus = SYS_INT_SourceDisable((INT_SOURCE)intInfo->intSources.usartInterrupt);
    }
    else
    {
        /* Disable USART interrupt sources */
        if(multiVector->usartRxCompleteInt != -1)
        {
            usartRxCompleteIntStatus = SYS_INT_SourceDisable((INT_SOURCE)multiVector->usartRxCompleteInt);
        }
    }

    count = usartReceiveLength;

    if (intInfo->isSingleIntSrc == true)
    {
        if (true == usartInterruptStatus)
        {
            /* Enable USART interrupt */
            //SYS_INT_SourceRestore((INT_SOURCE)intInfo->intSources.usartInterrupt, usartInterruptStatus);
            SYS_INT_SourceEnable((INT_SOURCE)intInfo->intSources.usartInterrupt);
        }
    }
    else
    {
        if (true == usartRxCompleteIntStatus)
        {
            /* Enable USART interrupt sources */
            if(multiVector->usartRxCompleteInt != -1)
            {
                SYS_INT_SourceEnable((INT_SOURCE)multiVector->usartRxCompleteInt);
            }
        }
    }

    return count;
}

uint8_t SerialBridge_PlatformUARTReadGetByte(void)
{
    uint8_t byte = 0;

    if (0 == SerialBridge_PlatformUARTReadGetBuffer(&byte, 1))
    {
        return 0;
    }

    return byte;
}

size_t SerialBridge_PlatformUARTReadGetBuffer(void *pBuf, size_t numBytes)
{
    const DRV_USART_INTERRUPT_SOURCES* intInfo = &platformInterruptSources;
    const DRV_USART_MULTI_INT_SRC* multiVector = &(intInfo->intSources.multi);
    bool usartInterruptStatus = false;
    bool usartRxCompleteIntStatus = false;

    size_t count = SerialBridge_PlatformUARTReadGetCount();

    if (0 == count)
    {
        return 0;
    }

    if (numBytes > count)
    {
        numBytes = count;
    }

    if ((usartReceiveOutOffset + numBytes) > USART_RECEIVE_BUFFER_SIZE)
    {
        uint8_t *pByteBuf;
        size_t partialReadNum;

        pByteBuf = pBuf;
        partialReadNum = (USART_RECEIVE_BUFFER_SIZE - usartReceiveOutOffset);

        memcpy(pByteBuf, &usartReceiveBuffer[usartReceiveOutOffset], partialReadNum);

        pByteBuf += partialReadNum;
        numBytes -= partialReadNum;

        memcpy(pByteBuf, usartReceiveBuffer, numBytes);

        usartReceiveOutOffset = numBytes;

        numBytes += partialReadNum;
    }
    else
    {
        memcpy(pBuf, &usartReceiveBuffer[usartReceiveOutOffset], numBytes);

        usartReceiveOutOffset += numBytes;
    }

     if (intInfo->isSingleIntSrc == true)
    {
        /* Disable USART interrupt */
        usartInterruptStatus = SYS_INT_SourceDisable((INT_SOURCE)intInfo->intSources.usartInterrupt);
    }
    else
    {
        /* Disable USART interrupt sources */

        if(multiVector->usartRxCompleteInt != -1)
        {
           usartRxCompleteIntStatus = SYS_INT_SourceDisable((INT_SOURCE)multiVector->usartRxCompleteInt);
        }
    }

    usartReceiveLength -= numBytes;


    if (intInfo->isSingleIntSrc == true)
    {
        if (true == usartInterruptStatus)
        {
            /* Enable USART interrupt */
//            SYS_INT_SourceRestore((INT_SOURCE)intInfo->intSources.usartInterrupt, usartInterruptStatus);
            SYS_INT_SourceEnable((INT_SOURCE)intInfo->intSources.usartInterrupt);
        }
    }
    else
    {
        if (true == usartRxCompleteIntStatus)
        {
            /* Enable USART interrupt sources */
            if(multiVector->usartRxCompleteInt != -1)
            {
                SYS_INT_SourceEnable((INT_SOURCE)multiVector->usartRxCompleteInt);
            }
        }
    }

    return numBytes;
}

size_t SerialBridge_PlatformUARTWriteGetCount(void)
{
    size_t count;
    const DRV_USART_INTERRUPT_SOURCES* intInfo = &platformInterruptSources;
    const DRV_USART_MULTI_INT_SRC* multiVector = &(intInfo->intSources.multi);
    bool usartInterruptStatus = false;
    bool usartTxReadyIntStatus = false;
    bool usartTxCompleteIntStatus = false;
    
    if (intInfo->isSingleIntSrc == true)
    {
        /* Disable USART interrupt */
        usartInterruptStatus = SYS_INT_SourceDisable((INT_SOURCE)intInfo->intSources.usartInterrupt);
    }
    else
    {
        /* Disable USART interrupt sources */
        if(multiVector->usartTxReadyInt != -1)
        {
            usartTxReadyIntStatus = SYS_INT_SourceDisable((INT_SOURCE)multiVector->usartTxReadyInt);
        }

        if(multiVector->usartTxCompleteInt != -1)
        {
            usartTxCompleteIntStatus = SYS_INT_SourceDisable((INT_SOURCE)multiVector->usartTxCompleteInt);
        }
    }

    count = usartTransmitLength;

    if (intInfo->isSingleIntSrc == true)
    {
        if (true == usartInterruptStatus)
        {
            /* Enable USART interrupt */
            SYS_INT_SourceEnable((INT_SOURCE)intInfo->intSources.usartInterrupt);
        }
    }
    else
    {
        if (true == usartTxReadyIntStatus)
        {
            /* Enable USART interrupt sources */
            if(multiVector->usartTxReadyInt != -1)
            {
                SYS_INT_SourceEnable((INT_SOURCE)multiVector->usartTxReadyInt);
            }
        }

        if (true == usartTxCompleteIntStatus)
        {
            if(multiVector->usartTxCompleteInt != -1)
            {
                SYS_INT_SourceEnable((INT_SOURCE)multiVector->usartTxCompleteInt);                
            }
        }
    }

    return count;
}

bool SerialBridge_PlatformUARTWritePutByte(uint8_t b)
{
    return SerialBridge_PlatformUARTWritePutBuffer((void*)&b, 1);
}

bool SerialBridge_PlatformUARTWritePutBuffer(const void *pBuf, size_t numBytes)
{
    const DRV_USART_INTERRUPT_SOURCES* intInfo = &platformInterruptSources;
    const DRV_USART_MULTI_INT_SRC* multiVector = &(intInfo->intSources.multi);
    bool usartInterruptStatus = false;
    bool usartTxReadyIntStatus = false;
    bool usartTxCompleteIntStatus = false;

    if ((NULL == pBuf) || (0 == numBytes))
    {
        return false;
    }

    if (OSAL_RESULT_TRUE == OSAL_MUTEX_Lock(&usartWriteMutex, OSAL_WAIT_FOREVER))
    {
        if ((SerialBridge_PlatformUARTWriteGetCount() + numBytes) > USART_TRANSMIT_BUFFER_SIZE)
        {
            OSAL_MUTEX_Unlock(&usartWriteMutex);
            return false;
        }

        if ((usartTransmitInOffset + numBytes) > USART_TRANSMIT_BUFFER_SIZE)
        {
            uint8_t *pByteBuf;
            size_t partialWriteNum;

            pByteBuf = (uint8_t*)pBuf;

            partialWriteNum = USART_TRANSMIT_BUFFER_SIZE - usartTransmitInOffset;

            memcpy(&usartTransmitBuffer[usartTransmitInOffset], pByteBuf, partialWriteNum);

            pByteBuf += partialWriteNum;
            numBytes -= partialWriteNum;

            memcpy(usartTransmitBuffer, pByteBuf, numBytes);

            usartTransmitInOffset = numBytes;

            numBytes += partialWriteNum;
        }
        else
        {
            memcpy(&usartTransmitBuffer[usartTransmitInOffset], pBuf, numBytes);

            usartTransmitInOffset += numBytes;
        }

        if (intInfo->isSingleIntSrc == true)
        {
            /* Disable USART interrupt */
            usartInterruptStatus = SYS_INT_SourceDisable((INT_SOURCE)intInfo->intSources.usartInterrupt);
        }
        else
        {
            /* Disable USART interrupt sources */
            if(multiVector->usartTxReadyInt != -1)
            {
                usartTxReadyIntStatus = SYS_INT_SourceDisable((INT_SOURCE)multiVector->usartTxReadyInt);
            }

            if(multiVector->usartTxCompleteInt != -1)
            {
                usartTxCompleteIntStatus = SYS_INT_SourceDisable((INT_SOURCE)multiVector->usartTxCompleteInt);
            }
        }
        
        usartTransmitLength += numBytes;

        if (intInfo->isSingleIntSrc == true)
        {
            if (true == usartInterruptStatus)
            {
                /* Enable USART interrupt */
                SYS_INT_SourceEnable((INT_SOURCE)intInfo->intSources.usartInterrupt);
            }
        }
        else
        {
            if (true == usartTxReadyIntStatus)
            {
                /* Enable USART interrupt sources */
                if(multiVector->usartTxReadyInt != -1)
                {
                    SYS_INT_SourceEnable((INT_SOURCE)multiVector->usartTxReadyInt);
                }
            }

            if (true == usartTxCompleteIntStatus)
            {
                if(multiVector->usartTxCompleteInt != -1)
                {
                    SYS_INT_SourceEnable((INT_SOURCE)multiVector->usartTxCompleteInt);                
                }
            }
        }

        if (false == platformUsartPlibAPI.writeIsBusy())
        {
            platformUsartPlibAPI.write(&usartTransmitBuffer[usartTransmitOutOffset], 1);
        }

        OSAL_MUTEX_Unlock(&usartWriteMutex);
    }

    return true;
}
