/*******************************************************************************
  FLEXCOM3 USART PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_flexcom3_usart.c

  Summary:
    FLEXCOM3 USART PLIB Implementation File

  Description
    This file defines the interface to the FLEXCOM3 USART
    peripheral library. This library provides access to and control of the
    associated peripheral instance.

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

#include "plib_flexcom3_usart.h"
#include "interrupts.h"

#define FLEXCOM_USART_RHR_8BIT_REG      (*(volatile uint8_t* const)((FLEXCOM3_BASE_ADDRESS + FLEX_US_RHR_REG_OFST)))
#define FLEXCOM_USART_RHR_9BIT_REG      (*(volatile uint16_t* const)((FLEXCOM3_BASE_ADDRESS + FLEX_US_RHR_REG_OFST)))

#define FLEXCOM_USART_THR_8BIT_REG      (*(volatile uint8_t* const)((FLEXCOM3_BASE_ADDRESS + FLEX_US_THR_REG_OFST)))
#define FLEXCOM_USART_THR_9BIT_REG      (*(volatile uint16_t* const)((FLEXCOM3_BASE_ADDRESS + FLEX_US_THR_REG_OFST)))

#define FLEXCOM3_USART_HW_RX_FIFO_THRES                 16U
#define FLEXCOM3_USART_HW_TX_FIFO_THRES                 16U

/* Disable Read, Overrun, Parity and Framing error interrupts */
#define FLEXCOM3_USART_RX_INT_DISABLE()      do { \
FLEXCOM3_REGS->FLEX_US_IDR = (FLEX_US_IDR_FRAME_Msk | FLEX_US_IDR_PARE_Msk | FLEX_US_IDR_OVRE_Msk); \
FLEXCOM3_REGS->FLEX_US_FIDR = FLEX_US_FIDR_RXFTHF_Msk; \
}while(false)

/* Enable Read, Overrun, Parity and Framing error interrupts */
#define FLEXCOM3_USART_RX_INT_ENABLE()       do { \
FLEXCOM3_REGS->FLEX_US_IER = (FLEX_US_IER_FRAME_Msk | FLEX_US_IER_PARE_Msk | FLEX_US_IER_OVRE_Msk); \
FLEXCOM3_REGS->FLEX_US_FIER = FLEX_US_FIER_RXFTHF_Msk; \
}while(false)

#define FLEXCOM3_USART_TX_INT_DISABLE()      do { \
FLEXCOM3_REGS->FLEX_US_IDR = FLEX_US_IDR_TXRDY_Msk; \
FLEXCOM3_REGS->FLEX_US_FIDR = (FLEX_US_FIDR_TXFTHF_Msk); \
}while(false)

#define FLEXCOM3_USART_TX_INT_ENABLE()       do { \
FLEXCOM3_REGS->FLEX_US_IER = FLEX_US_IER_TXRDY_Msk; \
FLEXCOM3_REGS->FLEX_US_FIER = (FLEX_US_FIER_TXFTHF_Msk); \
}while(false)

#define FLEXCOM3_USART_READ_BUFFER_SIZE             128U
#define FLEXCOM3_USART_9BIT_READ_BUFFER_SIZE        (128U >> 1U)

#define FLEXCOM3_USART_WRITE_BUFFER_SIZE            128U
#define FLEXCOM3_USART_9BIT_WRITE_BUFFER_SIZE       (128U >> 1U)

volatile static uint8_t FLEXCOM3_USART_ReadBuffer[FLEXCOM3_USART_READ_BUFFER_SIZE];
volatile static uint8_t FLEXCOM3_USART_WriteBuffer[FLEXCOM3_USART_WRITE_BUFFER_SIZE];

// *****************************************************************************
// *****************************************************************************
// Section: FLEXCOM3 USART Ring Buffer Implementation
// *****************************************************************************
// *****************************************************************************

volatile static FLEXCOM_USART_RING_BUFFER_OBJECT flexcom3UsartObj;

void FLEXCOM3_USART_Initialize( void )
{
    /* Set FLEXCOM USART operating mode */
    FLEXCOM3_REGS->FLEX_MR = FLEX_MR_OPMODE_USART;

    /* Reset FLEXCOM3 USART */
    FLEXCOM3_REGS->FLEX_US_CR = (FLEX_US_CR_RSTRX_Msk | FLEX_US_CR_RSTTX_Msk | FLEX_US_CR_RSTSTA_Msk);

    FLEXCOM3_REGS->FLEX_US_CR = FLEX_US_CR_FIFOEN_Msk;

    FLEXCOM3_REGS->FLEX_US_FMR = FLEX_US_FMR_RXFTHRES(FLEXCOM3_USART_HW_RX_FIFO_THRES) | FLEX_US_FMR_TXFTHRES(FLEXCOM3_USART_HW_TX_FIFO_THRES);

    FLEXCOM3_REGS->FLEX_US_TTGR = 0;

    /* Enable FLEXCOM3 USART */
    FLEXCOM3_REGS->FLEX_US_CR = (FLEX_US_CR_TXEN_Msk | FLEX_US_CR_RXEN_Msk);

    /* Configure FLEXCOM3 USART mode */
    FLEXCOM3_REGS->FLEX_US_MR = ( FLEX_US_MR_USART_MODE_NORMAL | FLEX_US_MR_USCLKS_MCK | FLEX_US_MR_CHRL_8_BIT | FLEX_US_MR_PAR_NO | FLEX_US_MR_NBSTOP_1_BIT | (0UL << FLEX_US_MR_OVER_Pos));

    /* Configure FLEXCOM3 USART Baud Rate */
    FLEXCOM3_REGS->FLEX_US_BRGR = FLEX_US_BRGR_CD(108) | FLEX_US_BRGR_FP(4);

    flexcom3UsartObj.rdCallback = NULL;
    flexcom3UsartObj.rdInIndex = 0;
    flexcom3UsartObj.rdOutIndex = 0;
    flexcom3UsartObj.isRdNotificationEnabled = false;
    flexcom3UsartObj.isRdNotifyPersistently = false;
    flexcom3UsartObj.rdThreshold = 0;
    flexcom3UsartObj.rdBufferSize = FLEXCOM3_USART_READ_BUFFER_SIZE;
    flexcom3UsartObj.wrCallback = NULL;
    flexcom3UsartObj.wrInIndex = 0;
    flexcom3UsartObj.wrOutIndex = 0;
    flexcom3UsartObj.isWrNotificationEnabled = false;
    flexcom3UsartObj.isWrNotifyPersistently = false;
    flexcom3UsartObj.wrThreshold = 0;
    flexcom3UsartObj.wrBufferSize = FLEXCOM3_USART_WRITE_BUFFER_SIZE;
    flexcom3UsartObj.errorStatus = FLEXCOM_USART_ERROR_NONE;
    flexcom3UsartObj.isInterruptActive = false;

    if ((FLEXCOM3_REGS->FLEX_US_MR & FLEX_US_MR_MODE9_Msk) != 0U)
    {
        flexcom3UsartObj.rdBufferSize = FLEXCOM3_USART_9BIT_READ_BUFFER_SIZE;
        flexcom3UsartObj.wrBufferSize = FLEXCOM3_USART_9BIT_WRITE_BUFFER_SIZE;
    }
    else
    {
        flexcom3UsartObj.rdBufferSize = FLEXCOM3_USART_READ_BUFFER_SIZE;
        flexcom3UsartObj.wrBufferSize = FLEXCOM3_USART_WRITE_BUFFER_SIZE;
    }

    FLEXCOM3_USART_RX_INT_ENABLE();
}

void static FLEXCOM3_USART_ErrorClear( void )
{
    /* Clear the error flags */
    FLEXCOM3_REGS->FLEX_US_CR = FLEX_US_CR_RSTSTA_Msk;

    /* Flush existing error bytes from the RX FIFO */
    while((FLEXCOM3_REGS->FLEX_US_CSR & FLEX_US_CSR_RXRDY_Msk) != 0U)
    {
        if ((FLEXCOM3_REGS->FLEX_US_MR & FLEX_US_MR_MODE9_Msk) != 0U)
        {
            (void)(FLEXCOM_USART_RHR_9BIT_REG);
        }
        else
        {
            (void)(FLEXCOM_USART_RHR_8BIT_REG);
        }
    }
}

FLEXCOM_USART_ERROR FLEXCOM3_USART_ErrorGet( void )
{
    FLEXCOM_USART_ERROR errors = flexcom3UsartObj.errorStatus;

    flexcom3UsartObj.errorStatus = FLEXCOM_USART_ERROR_NONE;

    /* All errors are cleared, but send the previous error state */
    return errors;
}

static void FLEXCOM3_USART_BaudCalculate(uint32_t srcClkFreq, uint32_t reqBaud, uint8_t overSamp, uint32_t* cd, uint32_t* fp, uint32_t* baudError)
{
    uint32_t actualBaud = 0;

    *cd = srcClkFreq / (reqBaud * 8U * (2U - (uint32_t)overSamp));

    if (*cd > 0U)
    {
        *fp = ((srcClkFreq / (reqBaud * (2U - (uint32_t)overSamp))) - ((*cd) * 8U));
        actualBaud = (srcClkFreq / (((*cd) * 8U) + (*fp))) / (2U - overSamp);
        *baudError = ((100U * actualBaud)/reqBaud) - 100U;
    }
}

bool FLEXCOM3_USART_SerialSetup( FLEXCOM_USART_SERIAL_SETUP *setup, uint32_t srcClkFreq )
{
    uint32_t baud = 0;
    uint32_t overSampVal = 0;
    uint32_t usartMode;
    uint32_t cd0, fp0, cd1, fp1, baudError0, baudError1;
    bool status = false;

    cd0 = fp0 = cd1 = fp1 = baudError0 = baudError1 = 0U;

    if (setup != NULL)
    {
        baud = setup->baudRate;

        if(srcClkFreq == 0U)
        {
            srcClkFreq = FLEXCOM3_USART_FrequencyGet();
        }

        /* Calculate baud register values for 8x/16x oversampling values */

        FLEXCOM3_USART_BaudCalculate(srcClkFreq, baud, 0, &cd0, &fp0, &baudError0);
        FLEXCOM3_USART_BaudCalculate(srcClkFreq, baud, 1, &cd1, &fp1, &baudError1);

        if ( (!(cd0 > 0U && cd0 <= 65535U)) && (!(cd1 > 0U && cd1 <= 65535U)) )
        {
            /* Requested baud cannot be generated with current clock settings */
            return status;
        }

        if ( ((cd0 > 0U) && (cd0 <= 65535U)) && ((cd1 > 0U) && (cd1 <= 65535U)) )
        {
            /* Requested baud can be generated with both 8x and 16x oversampling. Select the one with less % error. */
            if (baudError1 < baudError0)
            {
                cd0 = cd1;
                fp0 = fp1;
                overSampVal = (1UL << FLEX_US_MR_OVER_Pos) & FLEX_US_MR_OVER_Msk;
            }
        }
        else
        {
            /* Requested baud can be generated with either with 8x oversampling or with 16x oversampling. Select valid one. */
            if ((cd1 > 0U) && (cd1 <= 65535U))
            {
                cd0 = cd1;
                fp0 = fp1;
                overSampVal = (1UL << FLEX_US_MR_OVER_Pos) & FLEX_US_MR_OVER_Msk;
            }
        }

        /* Configure FLEXCOM3 USART mode */
        usartMode = FLEXCOM3_REGS->FLEX_US_MR;
        usartMode &= ~(FLEX_US_MR_CHRL_Msk | FLEX_US_MR_MODE9_Msk | FLEX_US_MR_PAR_Msk | FLEX_US_MR_NBSTOP_Msk | FLEX_US_MR_OVER_Msk);
        FLEXCOM3_REGS->FLEX_US_MR = usartMode | ((uint32_t)setup->dataWidth | (uint32_t)setup->parity | (uint32_t)setup->stopBits | overSampVal);

        /* Configure FLEXCOM3 USART Baud Rate */
        FLEXCOM3_REGS->FLEX_US_BRGR = FLEX_US_BRGR_CD(cd0) | FLEX_US_BRGR_FP(fp0);

        if ((FLEXCOM3_REGS->FLEX_US_MR & FLEX_US_MR_MODE9_Msk) != 0U)
        {
            flexcom3UsartObj.rdBufferSize = FLEXCOM3_USART_9BIT_READ_BUFFER_SIZE;
            flexcom3UsartObj.wrBufferSize = FLEXCOM3_USART_9BIT_WRITE_BUFFER_SIZE;
        }
        else
        {
            flexcom3UsartObj.rdBufferSize = FLEXCOM3_USART_READ_BUFFER_SIZE;
            flexcom3UsartObj.wrBufferSize = FLEXCOM3_USART_WRITE_BUFFER_SIZE;
        }

        status = true;
    }

    return status;
}

/* This routine is only called from ISR. Hence do not disable/enable USART interrupts. */
static bool FLEXCOM3_USART_TxPullByte(void* pWrData)
{
    bool isSuccess = false;
    uint32_t wrOutIndex = flexcom3UsartObj.wrOutIndex;
    uint32_t wrInIndex = flexcom3UsartObj.wrInIndex;
    uint8_t* pWrByte = (uint8_t*)pWrData;
    if (wrOutIndex != wrInIndex)
    {
        if ((FLEXCOM3_REGS->FLEX_US_MR & FLEX_US_MR_MODE9_Msk) != 0U)
        {
            uint32_t wrOutIdx = wrOutIndex << 1U;
            pWrByte[0] = FLEXCOM3_USART_WriteBuffer[wrOutIdx];
            pWrByte[1] = FLEXCOM3_USART_WriteBuffer[wrOutIdx + 1U];
        }
        else
        {
            *pWrByte = FLEXCOM3_USART_WriteBuffer[wrOutIndex];
        }
        wrOutIndex++;

        if (wrOutIndex >= flexcom3UsartObj.wrBufferSize)
        {
            wrOutIndex = 0U;
        }

        flexcom3UsartObj.wrOutIndex = wrOutIndex;
        isSuccess = true;
    }
    return isSuccess;
}

static inline bool FLEXCOM3_USART_TxPushByte(uint16_t wrByte)
{
    uint32_t tempInIndex;
    uint32_t wrOutIndex;
    uint32_t wrInIndex;
    bool isSuccess = false;

    /* Take a snapshot of indices to avoid creation of critical section */
    wrOutIndex = flexcom3UsartObj.wrOutIndex;
    wrInIndex = flexcom3UsartObj.wrInIndex;

    tempInIndex = wrInIndex + 1U;
    if (tempInIndex >= flexcom3UsartObj.wrBufferSize)
    {
        tempInIndex = 0U;
    }
    if (tempInIndex != wrOutIndex)
    {
        if ((FLEXCOM3_REGS->FLEX_US_MR & FLEX_US_MR_MODE9_Msk) != 0U)
        {
            uint32_t wrInIdx = wrInIndex << 1U;
            FLEXCOM3_USART_WriteBuffer[wrInIdx] = (uint8_t)wrByte;
            FLEXCOM3_USART_WriteBuffer[wrInIdx + 1U] = (uint8_t)(wrByte >> 8U);
        }
        else
        {
            FLEXCOM3_USART_WriteBuffer[wrInIndex] = (uint8_t)wrByte;
        }

        flexcom3UsartObj.wrInIndex = tempInIndex;
        isSuccess = true;
    }
    else
    {
        /* Queue is full. Report Error. */
    }
    return isSuccess;
}

/* This routine is only called from ISR. Hence do not disable/enable USART interrupts. */
static void FLEXCOM3_USART_SendWriteNotification(void)
{
    uint32_t nFreeWrBufferCount;

    if (flexcom3UsartObj.isWrNotificationEnabled == true)
    {
        nFreeWrBufferCount = FLEXCOM3_USART_WriteFreeBufferCountGet();

        if(flexcom3UsartObj.wrCallback != NULL)
        {
            uintptr_t wrContext = flexcom3UsartObj.wrContext;

            if (flexcom3UsartObj.isWrNotifyPersistently == true)
            {
                if (nFreeWrBufferCount >= flexcom3UsartObj.wrThreshold)
                {
                    flexcom3UsartObj.wrCallback(FLEXCOM_USART_EVENT_WRITE_THRESHOLD_REACHED, wrContext);
                }
            }
            else
            {
                if (nFreeWrBufferCount == flexcom3UsartObj.wrThreshold)
                {
                    flexcom3UsartObj.wrCallback(FLEXCOM_USART_EVENT_WRITE_THRESHOLD_REACHED, wrContext);
                }
            }
        }
    }
}

static size_t FLEXCOM3_USART_WritePendingBytesGet(void)
{
    size_t nPendingTxBytes;

    /* Take a snapshot of indices to avoid creation of critical section */

    uint32_t wrOutIndex = flexcom3UsartObj.wrOutIndex;
    uint32_t wrInIndex = flexcom3UsartObj.wrInIndex;

    if ( wrInIndex >=  wrOutIndex)
    {
        nPendingTxBytes =  wrInIndex -  wrOutIndex;
    }
    else
    {
        nPendingTxBytes =  (flexcom3UsartObj.wrBufferSize -  wrOutIndex) + wrInIndex;
    }

    return nPendingTxBytes;
}

size_t FLEXCOM3_USART_WriteCountGet(void)
{
    size_t nPendingTxBytes;

    nPendingTxBytes = FLEXCOM3_USART_WritePendingBytesGet();

    return nPendingTxBytes;
}

size_t FLEXCOM3_USART_Write(uint8_t* pWrBuffer, const size_t size )
{
    size_t nBytesWritten  = 0;

    while (nBytesWritten < size)
    {
        if ((FLEXCOM3_REGS->FLEX_US_MR & FLEX_US_MR_MODE9_Msk) != 0U)
        {
            uint16_t halfWordData = (uint16_t)(pWrBuffer[(2U * nBytesWritten) + 1U]);
            halfWordData <<= 8U;
            halfWordData |= (uint16_t)pWrBuffer[2U * nBytesWritten];
            if (FLEXCOM3_USART_TxPushByte(halfWordData) == true)
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
            if (FLEXCOM3_USART_TxPushByte(pWrBuffer[nBytesWritten]) == true)
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
    if (FLEXCOM3_USART_WritePendingBytesGet() > 0U)
    {
        /* Enable TX interrupt as data is pending for transmission */
        FLEXCOM3_USART_TX_INT_ENABLE();
    }

    return nBytesWritten;
}

size_t FLEXCOM3_USART_WriteFreeBufferCountGet(void)
{
    return (flexcom3UsartObj.wrBufferSize - 1U) - FLEXCOM3_USART_WriteCountGet();
}

size_t FLEXCOM3_USART_WriteBufferSizeGet(void)
{
    return (flexcom3UsartObj.wrBufferSize - 1U);
}

bool FLEXCOM3_USART_TransmitComplete(void)
{
    bool status = false;

    if ((FLEXCOM3_REGS->FLEX_US_CSR & FLEX_US_CSR_TXEMPTY_Msk) != 0U)
    {
        status = true;
    }

    return status;
}

bool FLEXCOM3_USART_WriteNotificationEnable(bool isEnabled, bool isPersistent)
{
    bool previousStatus = flexcom3UsartObj.isWrNotificationEnabled;

    flexcom3UsartObj.isWrNotificationEnabled = isEnabled;

    flexcom3UsartObj.isWrNotifyPersistently = isPersistent;

    return previousStatus;
}

void FLEXCOM3_USART_WriteThresholdSet(uint32_t nBytesThreshold)
{
    if (nBytesThreshold > 0U)
    {
        flexcom3UsartObj.wrThreshold = nBytesThreshold;
    }
}

void FLEXCOM3_USART_WriteCallbackRegister( FLEXCOM_USART_RING_BUFFER_CALLBACK callback, uintptr_t context)
{
    flexcom3UsartObj.wrCallback = callback;

    flexcom3UsartObj.wrContext = context;
}

/* This routine is only called from ISR. Hence do not disable/enable USART interrupts. */
static inline bool FLEXCOM3_USART_RxPushByte(uint16_t rdByte)
{
    uint32_t tempInIndex;
    bool isSuccess = false;

    tempInIndex = flexcom3UsartObj.rdInIndex + 1U;

    if (tempInIndex >= flexcom3UsartObj.rdBufferSize)
    {
        tempInIndex = 0U;
    }

    if (tempInIndex == flexcom3UsartObj.rdOutIndex)
    {
        /* Queue is full - Report it to the application. Application gets a chance to free up space by reading data out from the RX ring buffer */
        if(flexcom3UsartObj.rdCallback != NULL)
        {
            uintptr_t rdContext = flexcom3UsartObj.rdContext;

            flexcom3UsartObj.rdCallback(FLEXCOM_USART_EVENT_READ_BUFFER_FULL, rdContext);

            /* Read the indices again in case application has freed up space in RX ring buffer */
            tempInIndex = flexcom3UsartObj.rdInIndex + 1U;

            if (tempInIndex >= flexcom3UsartObj.rdBufferSize)
            {
                tempInIndex = 0U;
            }
        }
    }

    /* Attempt to push the data into the ring buffer */
    if (tempInIndex != flexcom3UsartObj.rdOutIndex)
    {
        uint32_t rdInIdx;

        if ((FLEXCOM3_REGS->FLEX_US_MR & FLEX_US_MR_MODE9_Msk) != 0U)
        {
            rdInIdx = flexcom3UsartObj.rdInIndex << 1U;
            FLEXCOM3_USART_ReadBuffer[rdInIdx] = (uint8_t)rdByte;
            FLEXCOM3_USART_ReadBuffer[rdInIdx + 1U] = (uint8_t)(rdByte >> 8U);
        }
        else
        {
            rdInIdx = flexcom3UsartObj.rdInIndex;
            FLEXCOM3_USART_ReadBuffer[rdInIdx] = (uint8_t)rdByte;
        }

        flexcom3UsartObj.rdInIndex = tempInIndex;
        isSuccess = true;
    }
    else
    {
        /* Queue is full. Data will be lost. */
    }

    return isSuccess;
}

/* This routine is only called from ISR. Hence do not disable/enable USART interrupts. */
static void FLEXCOM3_USART_SendReadNotification(void)
{
    uint32_t nUnreadBytesAvailable;

    if (flexcom3UsartObj.isRdNotificationEnabled == true)
    {
        nUnreadBytesAvailable = FLEXCOM3_USART_ReadCountGet();

        if(flexcom3UsartObj.rdCallback != NULL)
        {
            uintptr_t rdContext = flexcom3UsartObj.rdContext;

            if (flexcom3UsartObj.isRdNotifyPersistently == true)
            {
                if (nUnreadBytesAvailable >= flexcom3UsartObj.rdThreshold)
                {
                    flexcom3UsartObj.rdCallback(FLEXCOM_USART_EVENT_READ_THRESHOLD_REACHED, rdContext);
                }
            }
            else
            {
                if (nUnreadBytesAvailable == flexcom3UsartObj.rdThreshold)
                {
                    flexcom3UsartObj.rdCallback(FLEXCOM_USART_EVENT_READ_THRESHOLD_REACHED, rdContext);
                }
            }
        }
    }
}

size_t FLEXCOM3_USART_Read(uint8_t* pRdBuffer, const size_t size)
{
    size_t nBytesRead = 0;
    uint32_t rdOutIndex = 0;
    uint32_t rdInIndex = 0;

    if (flexcom3UsartObj.isInterruptActive == false)
    {
        if ((FLEXCOM3_REGS->FLEX_US_CSR & FLEX_US_CSR_RXRDY_Msk) != 0U)
        {
            FLEXCOM3_REGS->FLEX_US_IER = FLEX_US_IER_RXRDY_Msk;
            while ((FLEXCOM3_REGS->FLEX_US_CSR & FLEX_US_CSR_RXRDY_Msk) != 0U)
            {
                /* Wait for RXRDY flag */
            }
            FLEXCOM3_REGS->FLEX_US_IDR = FLEX_US_IDR_RXRDY_Msk;
        }
    }

    /* Take a snapshot of indices to avoid creation of critical section */
    rdOutIndex = flexcom3UsartObj.rdOutIndex;
    rdInIndex = flexcom3UsartObj.rdInIndex;

    while (nBytesRead < size)
    {
        if (rdOutIndex != rdInIndex)
        {
            if ((FLEXCOM3_REGS->FLEX_US_MR & FLEX_US_MR_MODE9_Msk) != 0U)
            {
                uint32_t rdOutIdx = rdOutIndex << 1U;
                uint32_t nBytesReadIdx = nBytesRead << 1U;
                pRdBuffer[nBytesReadIdx] = FLEXCOM3_USART_ReadBuffer[rdOutIdx];
                pRdBuffer[nBytesReadIdx + 1U] = FLEXCOM3_USART_ReadBuffer[rdOutIdx + 1U];
                nBytesRead++;
                rdOutIndex++;
            }
            else
            {
                pRdBuffer[nBytesRead++] = FLEXCOM3_USART_ReadBuffer[rdOutIndex];
                rdOutIndex++;
            }

            if (rdOutIndex >= flexcom3UsartObj.rdBufferSize)
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

    flexcom3UsartObj.rdOutIndex = rdOutIndex;

    return nBytesRead;
}

size_t FLEXCOM3_USART_ReadCountGet(void)
{
    size_t nUnreadBytesAvailable;
    uint32_t rdOutIndex;
    uint32_t rdInIndex;

    if (flexcom3UsartObj.isInterruptActive == false)
    {
        if ((FLEXCOM3_REGS->FLEX_US_CSR & FLEX_US_CSR_RXRDY_Msk) != 0U)
        {
            FLEXCOM3_REGS->FLEX_US_IER = FLEX_US_IER_RXRDY_Msk;

            while ((FLEXCOM3_REGS->FLEX_US_CSR & FLEX_US_CSR_RXRDY_Msk) != 0U)
            {
                /* Wait for RXRDY flag */
            }

            FLEXCOM3_REGS->FLEX_US_IDR = FLEX_US_IDR_RXRDY_Msk;
        }
    }

    /* Take a snapshot of indices to avoid creation of critical section */
    rdOutIndex = flexcom3UsartObj.rdOutIndex;
    rdInIndex = flexcom3UsartObj.rdInIndex;

    if ( rdInIndex >=  rdOutIndex)
    {
        nUnreadBytesAvailable =  rdInIndex -  rdOutIndex;
    }
    else
    {
        nUnreadBytesAvailable =  (flexcom3UsartObj.rdBufferSize -  rdOutIndex) + rdInIndex;
    }

    return nUnreadBytesAvailable;
}

size_t FLEXCOM3_USART_ReadFreeBufferCountGet(void)
{
    return (flexcom3UsartObj.rdBufferSize - 1U) - FLEXCOM3_USART_ReadCountGet();
}

size_t FLEXCOM3_USART_ReadBufferSizeGet(void)
{
    return (flexcom3UsartObj.rdBufferSize - 1U);
}

static void FLEXCOM3_USART_UpdateRXFIFOThreshold(void)
{
    size_t nUnreadBytesAvailable = 0;
    size_t nBytesPendingForRDThreshold = 0;

    if (flexcom3UsartObj.isRdNotificationEnabled == true)
    {
        nUnreadBytesAvailable = FLEXCOM3_USART_ReadCountGet();

        if (flexcom3UsartObj.rdThreshold > nUnreadBytesAvailable)
        {
            /* Don't have RX threshold number of bytes in the receive buffer.
             * Setup the hardware FIFO threshold level based on number of bytes remaining to reach the rdThreshold level */

            nBytesPendingForRDThreshold = flexcom3UsartObj.rdThreshold - nUnreadBytesAvailable;

            if (nBytesPendingForRDThreshold > FLEXCOM3_USART_HW_RX_FIFO_THRES)
            {
                nBytesPendingForRDThreshold = FLEXCOM3_USART_HW_RX_FIFO_THRES;
            }

            /* Set the new threshold level for hardware RX FIFO */
            FLEXCOM3_REGS->FLEX_US_FMR = (FLEXCOM3_REGS->FLEX_US_FMR & ~FLEX_US_FMR_RXFTHRES_Msk) | FLEX_US_FMR_RXFTHRES(nBytesPendingForRDThreshold);
        }
        else
        {
            /* Set the threshold to generate interrupt when the HW RX FIFO has RX threshold number of bytes */
            FLEXCOM3_REGS->FLEX_US_FMR = (FLEXCOM3_REGS->FLEX_US_FMR & ~FLEX_US_FMR_RXFTHRES_Msk) | FLEX_US_FMR_RXFTHRES(FLEXCOM3_USART_HW_RX_FIFO_THRES);
        }
    }
}

bool FLEXCOM3_USART_ReadNotificationEnable(bool isEnabled, bool isPersistent)
{
    bool previousStatus = flexcom3UsartObj.isRdNotificationEnabled;

    flexcom3UsartObj.isRdNotificationEnabled = isEnabled;

    flexcom3UsartObj.isRdNotifyPersistently = isPersistent;

    FLEXCOM3_USART_UpdateRXFIFOThreshold();

    return previousStatus;
}

void FLEXCOM3_USART_ReadThresholdSet(uint32_t nBytesThreshold)
{
    if (nBytesThreshold > 0U)
    {
        flexcom3UsartObj.rdThreshold = nBytesThreshold;

        FLEXCOM3_USART_UpdateRXFIFOThreshold();
    }
}

void FLEXCOM3_USART_ReadCallbackRegister( FLEXCOM_USART_RING_BUFFER_CALLBACK callback, uintptr_t context)
{
    flexcom3UsartObj.rdCallback = callback;

    flexcom3UsartObj.rdContext = context;
}

void static __attribute__((used)) FLEXCOM3_USART_ISR_RX_Handler( void )
{
    uint16_t rdData = 0;

    /* Keep reading until there is a character availabe in the RX FIFO */
    while(FLEX_US_CSR_RXRDY_Msk == (FLEXCOM3_REGS->FLEX_US_CSR & FLEX_US_CSR_RXRDY_Msk))
    {
        if ((FLEXCOM3_REGS->FLEX_US_MR & FLEX_US_MR_MODE9_Msk) != 0U)
        {
            rdData = FLEXCOM_USART_RHR_9BIT_REG & (uint16_t)FLEX_US_RHR_RXCHR_Msk;
        }
        else
        {
            rdData = (uint8_t)FLEXCOM_USART_RHR_8BIT_REG;
        }

        if (FLEXCOM3_USART_RxPushByte( rdData ) == true)
        {
            FLEXCOM3_USART_SendReadNotification();
        }
        else
        {
            /* UART RX buffer is full */
        }
    }

    FLEXCOM3_USART_UpdateRXFIFOThreshold();

}

void static __attribute__((used)) FLEXCOM3_USART_ISR_TX_Handler( void )
{
    uint16_t wrByte;

    /* Keep writing to the TX FIFO as long as there is space */
    while(FLEX_US_CSR_TXRDY_Msk == (FLEXCOM3_REGS->FLEX_US_CSR & FLEX_US_CSR_TXRDY_Msk))
    {
        if (FLEXCOM3_USART_TxPullByte(&wrByte) == true)
        {
            if ((FLEXCOM3_REGS->FLEX_US_MR & FLEX_US_MR_MODE9_Msk) != 0U)
            {
                FLEXCOM_USART_THR_9BIT_REG = wrByte & (uint16_t)FLEX_US_THR_TXCHR_Msk;
            }
            else
            {
                FLEXCOM_USART_THR_8BIT_REG = (uint8_t)wrByte;
            }

            /* Send notification */
            FLEXCOM3_USART_SendWriteNotification();
        }
        else
        {
            /* Nothing to transmit. Disable the data register empty/fifo Threshold interrupt. */
            FLEXCOM3_USART_TX_INT_DISABLE();
            break;
        }
    }

    /* At this point, either FIFO is completly full or all bytes are transmitted (copied in FIFO). If FIFO is full, then threshold interrupt
    *  will be generated. If all bytes are transmitted then interrupts are disabled as interrupt generation is not needed in ring buffer mode
    */

    /* Always disable the TXRDY interrupt. It is only used to start off transmission. */
    FLEXCOM3_REGS->FLEX_US_IDR = FLEX_US_IDR_TXRDY_Msk;
}

void __attribute__((used)) FLEXCOM3_InterruptHandler( void )
{
    /* Channel status */
    uint32_t channelStatus = FLEXCOM3_REGS->FLEX_US_CSR;

    /* Error status */
    uint32_t errorStatus = (channelStatus & (FLEX_US_CSR_OVRE_Msk | FLEX_US_CSR_FRAME_Msk | FLEX_US_CSR_PARE_Msk));

    flexcom3UsartObj.isInterruptActive = true;

    if(errorStatus != 0U)
    {
        /* Save the error so that it can be reported when application calls the FLEXCOM3_USART_ErrorGet() API */
        flexcom3UsartObj.errorStatus = (FLEXCOM_USART_ERROR)errorStatus;

        /* Clear the error flags and flush out the error bytes */
        FLEXCOM3_USART_ErrorClear();

        /* USART errors are normally associated with the receiver, hence calling receiver context */
        if( flexcom3UsartObj.rdCallback != NULL )
        {
            uintptr_t rdContext = flexcom3UsartObj.rdContext;

            flexcom3UsartObj.rdCallback(FLEXCOM_USART_EVENT_READ_ERROR, rdContext);
        }
    }

    /* Clear FIFO related interrupt flags */
    FLEXCOM3_REGS->FLEX_US_CR = FLEX_US_CR_RSTSTA_Msk;

    FLEXCOM3_USART_ISR_RX_Handler();

    FLEXCOM3_USART_ISR_TX_Handler();

    flexcom3UsartObj.isInterruptActive = false;
}
