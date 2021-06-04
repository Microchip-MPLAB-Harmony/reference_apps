/*******************************************************************************
  SERCOM Universal Synchronous/Asynchrnous Receiver/Transmitter PLIB

  Company
    Microchip Technology Inc.

  File Name
    plib_sercom0_usart.c

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
#include "plib_sercom0_usart.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************


/* SERCOM0 USART baud value for 115200 Hz baud rate */
#define SERCOM0_USART_INT_BAUD_VALUE            (63522UL)

static SERCOM_USART_OBJECT sercom0USARTObj;

// *****************************************************************************
// *****************************************************************************
// Section: SERCOM0 USART Interface Routines
// *****************************************************************************
// *****************************************************************************

void static SERCOM0_USART_ErrorClear( void )
{
    uint8_t  u8dummyData = 0U;
    USART_ERROR errorStatus = (USART_ERROR) (SERCOM0_REGS->USART_INT.SERCOM_STATUS & (uint16_t)(SERCOM_USART_INT_STATUS_PERR_Msk | SERCOM_USART_INT_STATUS_FERR_Msk | SERCOM_USART_INT_STATUS_BUFOVF_Msk ));

    if(errorStatus != USART_ERROR_NONE)
    {
        /* Clear error flag */
        SERCOM0_REGS->USART_INT.SERCOM_INTFLAG = (uint8_t)SERCOM_USART_INT_INTFLAG_ERROR_Msk;
        /* Clear all errors */
        SERCOM0_REGS->USART_INT.SERCOM_STATUS = (uint16_t)(SERCOM_USART_INT_STATUS_PERR_Msk | SERCOM_USART_INT_STATUS_FERR_Msk | SERCOM_USART_INT_STATUS_BUFOVF_Msk);

        /* Flush existing error bytes from the RX FIFO */
        while((SERCOM0_REGS->USART_INT.SERCOM_INTFLAG & (uint8_t)SERCOM_USART_INT_INTFLAG_RXC_Msk) == (uint8_t)SERCOM_USART_INT_INTFLAG_RXC_Msk)
        {
            u8dummyData = (uint8_t)SERCOM0_REGS->USART_INT.SERCOM_DATA;
        }
    }

    /* Ignore the warning */
    (void)u8dummyData;
}

void SERCOM0_USART_Initialize( void )
{
    /*
     * Configures USART Clock Mode
     * Configures TXPO and RXPO
     * Configures Data Order
     * Configures Standby Mode
     * Configures Sampling rate
     * Configures IBON
     */
    SERCOM0_REGS->USART_INT.SERCOM_CTRLA = SERCOM_USART_INT_CTRLA_MODE_USART_INT_CLK | SERCOM_USART_INT_CTRLA_RXPO(0x1UL) | SERCOM_USART_INT_CTRLA_TXPO(0x2UL) | SERCOM_USART_INT_CTRLA_DORD_Msk | SERCOM_USART_INT_CTRLA_IBON_Msk | SERCOM_USART_INT_CTRLA_FORM(0x0UL) | SERCOM_USART_INT_CTRLA_SAMPR(0UL) ;

    /* Configure Baud Rate */
    SERCOM0_REGS->USART_INT.SERCOM_BAUD = (uint16_t)SERCOM_USART_INT_BAUD_BAUD(SERCOM0_USART_INT_BAUD_VALUE);

    /*
     * Configures RXEN
     * Configures TXEN
     * Configures CHSIZE
     * Configures Parity
     * Configures Stop bits
     */
    SERCOM0_REGS->USART_INT.SERCOM_CTRLB = SERCOM_USART_INT_CTRLB_CHSIZE_8_BIT | SERCOM_USART_INT_CTRLB_SBMODE_1_BIT | SERCOM_USART_INT_CTRLB_RXEN_Msk | SERCOM_USART_INT_CTRLB_TXEN_Msk;

    /* Wait for sync */
    while((SERCOM0_REGS->USART_INT.SERCOM_SYNCBUSY) != 0U)
    {
        /* Do nothing */
    }


    /* Enable the UART after the configurations */
    SERCOM0_REGS->USART_INT.SERCOM_CTRLA |= SERCOM_USART_INT_CTRLA_ENABLE_Msk;

    /* Wait for sync */
    while((SERCOM0_REGS->USART_INT.SERCOM_SYNCBUSY) != 0U)
    {
        /* Do nothing */
    }

    /* Initialize instance object */
    sercom0USARTObj.rxBuffer = NULL;
    sercom0USARTObj.rxSize = 0;
    sercom0USARTObj.rxProcessedSize = 0;
    sercom0USARTObj.rxBusyStatus = false;
    sercom0USARTObj.rxCallback = NULL;
    sercom0USARTObj.txBuffer = NULL;
    sercom0USARTObj.txSize = 0;
    sercom0USARTObj.txProcessedSize = 0;
    sercom0USARTObj.txBusyStatus = false;
    sercom0USARTObj.txCallback = NULL;
    sercom0USARTObj.errorStatus = USART_ERROR_NONE;
}

uint32_t SERCOM0_USART_FrequencyGet( void )
{
    return 60000000UL;
}

bool SERCOM0_USART_SerialSetup( USART_SERIAL_SETUP * serialSetup, uint32_t clkFrequency )
{
    bool setupStatus       = false;
    uint32_t baudValue     = 0U;
    uint32_t sampleRate    = 0U;

    bool transferProgress = sercom0USARTObj.txBusyStatus;
    transferProgress = sercom0USARTObj.rxBusyStatus || transferProgress; 
    if(transferProgress)
    {
        /* Transaction is in progress, so return without updating settings */
        return setupStatus;
    }

    if((serialSetup != NULL) && (serialSetup->baudRate != 0U))
    {
        if(clkFrequency == 0U)
        {
            clkFrequency = SERCOM0_USART_FrequencyGet();
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

        if(baudValue != 0U)
        {
            /* Disable the USART before configurations */
            SERCOM0_REGS->USART_INT.SERCOM_CTRLA &= ~SERCOM_USART_INT_CTRLA_ENABLE_Msk;

            /* Wait for sync */
            while((SERCOM0_REGS->USART_INT.SERCOM_SYNCBUSY) != 0U)
            {
                /* Do nothing */
            }

            /* Configure Baud Rate */
            SERCOM0_REGS->USART_INT.SERCOM_BAUD = (uint16_t)SERCOM_USART_INT_BAUD_BAUD(baudValue);

            /* Configure Parity Options */
            if(serialSetup->parity == USART_PARITY_NONE)
            {
                SERCOM0_REGS->USART_INT.SERCOM_CTRLA =  (SERCOM0_REGS->USART_INT.SERCOM_CTRLA & ~(SERCOM_USART_INT_CTRLA_SAMPR_Msk | SERCOM_USART_INT_CTRLA_FORM_Msk)) | SERCOM_USART_INT_CTRLA_FORM(0x0UL) | SERCOM_USART_INT_CTRLA_SAMPR((uint32_t)sampleRate); 
                SERCOM0_REGS->USART_INT.SERCOM_CTRLB = (SERCOM0_REGS->USART_INT.SERCOM_CTRLB & ~(SERCOM_USART_INT_CTRLB_CHSIZE_Msk | SERCOM_USART_INT_CTRLB_SBMODE_Msk)) | ((uint32_t) serialSetup->dataWidth | (uint32_t) serialSetup->stopBits);
            }
            else
            {
                SERCOM0_REGS->USART_INT.SERCOM_CTRLA =  (SERCOM0_REGS->USART_INT.SERCOM_CTRLA & ~(SERCOM_USART_INT_CTRLA_SAMPR_Msk | SERCOM_USART_INT_CTRLA_FORM_Msk)) | SERCOM_USART_INT_CTRLA_FORM(0x1UL) | SERCOM_USART_INT_CTRLA_SAMPR((uint32_t)sampleRate); 
                SERCOM0_REGS->USART_INT.SERCOM_CTRLB = (SERCOM0_REGS->USART_INT.SERCOM_CTRLB & ~(SERCOM_USART_INT_CTRLB_CHSIZE_Msk | SERCOM_USART_INT_CTRLB_SBMODE_Msk | SERCOM_USART_INT_CTRLB_PMODE_Msk)) | (uint32_t) serialSetup->dataWidth | (uint32_t) serialSetup->stopBits | (uint32_t) serialSetup->parity ;
            }

            /* Wait for sync */
            while((SERCOM0_REGS->USART_INT.SERCOM_SYNCBUSY) != 0U)
            {
                /* Do nothing */
            }

            /* Enable the USART after the configurations */
            SERCOM0_REGS->USART_INT.SERCOM_CTRLA |= SERCOM_USART_INT_CTRLA_ENABLE_Msk;

            /* Wait for sync */
            while((SERCOM0_REGS->USART_INT.SERCOM_SYNCBUSY) != 0U)
            {
                /* Do nothing */
            }

            setupStatus = true;
        }
    }

    return setupStatus;
}

USART_ERROR SERCOM0_USART_ErrorGet( void )
{
    USART_ERROR errorStatus = sercom0USARTObj.errorStatus;

    sercom0USARTObj.errorStatus = USART_ERROR_NONE;

    return errorStatus;
}


void SERCOM0_USART_TransmitterEnable( void )
{
    SERCOM0_REGS->USART_INT.SERCOM_CTRLB |= SERCOM_USART_INT_CTRLB_TXEN_Msk;

    /* Wait for sync */
    while((SERCOM0_REGS->USART_INT.SERCOM_SYNCBUSY) != 0U)
    {
        /* Do nothing */
    }
}

void SERCOM0_USART_TransmitterDisable( void )
{
    SERCOM0_REGS->USART_INT.SERCOM_CTRLB &= ~SERCOM_USART_INT_CTRLB_TXEN_Msk;

    /* Wait for sync */
    while((SERCOM0_REGS->USART_INT.SERCOM_SYNCBUSY) != 0U)
    {
        /* Do nothing */
    }
}

bool SERCOM0_USART_Write( void *buffer, const size_t size )
{
    bool writeStatus      = false;
    uint8_t *pu8Data      = (uint8_t*)buffer;
    uint32_t processedSize = 0U;

    if(pu8Data != NULL)
    {
        if(sercom0USARTObj.txBusyStatus == false)
        {
            sercom0USARTObj.txBuffer = pu8Data;
            sercom0USARTObj.txSize = size;
            sercom0USARTObj.txBusyStatus = true;

            /* Initiate the transfer by sending first byte */
            while (((SERCOM0_REGS->USART_INT.SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_DRE_Msk) == SERCOM_USART_INT_INTFLAG_DRE_Msk) &&
                    (processedSize < sercom0USARTObj.txSize))
            {
                if (((SERCOM0_REGS->USART_INT.SERCOM_CTRLB & SERCOM_USART_INT_CTRLB_CHSIZE_Msk) >> SERCOM_USART_INT_CTRLB_CHSIZE_Pos) != 0x01U)
                {
                    /* 8-bit mode */
                    SERCOM0_REGS->USART_INT.SERCOM_DATA = sercom0USARTObj.txBuffer[processedSize++];
                }
                else
                {
                    /* 9-bit mode */
                    SERCOM0_REGS->USART_INT.SERCOM_DATA = ((uint16_t*)sercom0USARTObj.txBuffer)[processedSize++];
                }
            }
            sercom0USARTObj.txProcessedSize = processedSize;
            SERCOM0_REGS->USART_INT.SERCOM_INTENSET = (uint8_t)SERCOM_USART_INT_INTFLAG_DRE_Msk;

            writeStatus = true;
        }
    }

    return writeStatus;
}


bool SERCOM0_USART_WriteIsBusy( void )
{
    return sercom0USARTObj.txBusyStatus;
}

size_t SERCOM0_USART_WriteCountGet( void )
{
    return sercom0USARTObj.txProcessedSize;
}

void SERCOM0_USART_WriteCallbackRegister( SERCOM_USART_CALLBACK callback, uintptr_t context )
{
    sercom0USARTObj.txCallback = callback;

    sercom0USARTObj.txContext = context;
}


void SERCOM0_USART_ReceiverEnable( void )
{
    SERCOM0_REGS->USART_INT.SERCOM_CTRLB |= SERCOM_USART_INT_CTRLB_RXEN_Msk;

    /* Wait for sync */
    while((SERCOM0_REGS->USART_INT.SERCOM_SYNCBUSY) != 0U)
    {
        /* Do nothing */
    }
}

void SERCOM0_USART_ReceiverDisable( void )
{
    SERCOM0_REGS->USART_INT.SERCOM_CTRLB &= ~SERCOM_USART_INT_CTRLB_RXEN_Msk;

    /* Wait for sync */
    while((SERCOM0_REGS->USART_INT.SERCOM_SYNCBUSY) != 0U)
    {
        /* Do nothing */
    }
}

bool SERCOM0_USART_Read( void *buffer, const size_t size )
{
    bool readStatus        = false;
    uint8_t* pu8Data       = (uint8_t*)buffer;

    if(pu8Data != NULL)
    {
        if(sercom0USARTObj.rxBusyStatus == false)
        {
            /* Clear error flags and flush out error data that may have been received when no active request was pending */
            SERCOM0_USART_ErrorClear();

            sercom0USARTObj.rxBuffer = pu8Data;
            sercom0USARTObj.rxSize = size;
            sercom0USARTObj.rxProcessedSize = 0U;
            sercom0USARTObj.rxBusyStatus = true;
            sercom0USARTObj.errorStatus = USART_ERROR_NONE;

            readStatus = true;

            /* Enable receive and error interrupt */
            SERCOM0_REGS->USART_INT.SERCOM_INTENSET = (uint8_t)(SERCOM_USART_INT_INTENSET_ERROR_Msk | SERCOM_USART_INT_INTENSET_RXC_Msk);
        }
    }

    return readStatus;
}

bool SERCOM0_USART_ReadIsBusy( void )
{
    return sercom0USARTObj.rxBusyStatus;
}

size_t SERCOM0_USART_ReadCountGet( void )
{
    return sercom0USARTObj.rxProcessedSize;
}

bool SERCOM0_USART_ReadAbort(void)
{
    if (sercom0USARTObj.rxBusyStatus == true)
    {
        /* Disable receive and error interrupt */
        SERCOM0_REGS->USART_INT.SERCOM_INTENCLR = (uint8_t)(SERCOM_USART_INT_INTENCLR_ERROR_Msk | SERCOM_USART_INT_INTENCLR_RXC_Msk);

        sercom0USARTObj.rxBusyStatus = false;

        /* If required application should read the num bytes processed prior to calling the read abort API */
        sercom0USARTObj.rxSize = sercom0USARTObj.rxProcessedSize = 0U;
    }

    return true;
}

void SERCOM0_USART_ReadCallbackRegister( SERCOM_USART_CALLBACK callback, uintptr_t context )
{
    sercom0USARTObj.rxCallback = callback;

    sercom0USARTObj.rxContext = context;
}


void static SERCOM0_USART_ISR_ERR_Handler( void )
{
    USART_ERROR errorStatus = USART_ERROR_NONE;

    errorStatus = (USART_ERROR) (SERCOM0_REGS->USART_INT.SERCOM_STATUS & (uint16_t)(SERCOM_USART_INT_STATUS_PERR_Msk | SERCOM_USART_INT_STATUS_FERR_Msk | SERCOM_USART_INT_STATUS_BUFOVF_Msk));

    if(errorStatus != USART_ERROR_NONE)
    {
        /* Save the error to be reported later */
        sercom0USARTObj.errorStatus = errorStatus;

        /* Clear the error flags and flush out the error bytes */
        SERCOM0_USART_ErrorClear();

        /* Disable error and receive interrupt to abort on-going transfer */
        SERCOM0_REGS->USART_INT.SERCOM_INTENCLR = (uint8_t)(SERCOM_USART_INT_INTENCLR_ERROR_Msk | SERCOM_USART_INT_INTENCLR_RXC_Msk);

        /* Clear the RX busy flag */
        sercom0USARTObj.rxBusyStatus = false;

        if(sercom0USARTObj.rxCallback != NULL)
        {
            sercom0USARTObj.rxCallback(sercom0USARTObj.rxContext);
        }
    }
}

void static SERCOM0_USART_ISR_RX_Handler( void )
{
    uint16_t temp;


    if(sercom0USARTObj.rxBusyStatus == true)
    {
        if(sercom0USARTObj.rxProcessedSize < sercom0USARTObj.rxSize)
        {
            temp = SERCOM0_REGS->USART_INT.SERCOM_DATA;

            if (((SERCOM0_REGS->USART_INT.SERCOM_CTRLB & SERCOM_USART_INT_CTRLB_CHSIZE_Msk) >> SERCOM_USART_INT_CTRLB_CHSIZE_Pos) != 0x01U)
            {
                /* 8-bit mode */
                sercom0USARTObj.rxBuffer[sercom0USARTObj.rxProcessedSize++] = (uint8_t) (temp);
            }
            else
            {
                /* 9-bit mode */
                ((uint16_t*)sercom0USARTObj.rxBuffer)[sercom0USARTObj.rxProcessedSize++] = (uint16_t) (temp);
            }

            if(sercom0USARTObj.rxProcessedSize == sercom0USARTObj.rxSize)
            {
                sercom0USARTObj.rxBusyStatus = false;
                sercom0USARTObj.rxSize = 0U;
                SERCOM0_REGS->USART_INT.SERCOM_INTENCLR = (uint8_t)(SERCOM_USART_INT_INTENCLR_RXC_Msk | SERCOM_USART_INT_INTENCLR_ERROR_Msk);

                if(sercom0USARTObj.rxCallback != NULL)
                {
                    sercom0USARTObj.rxCallback(sercom0USARTObj.rxContext);
                }
            }

        }
    }
}

void static SERCOM0_USART_ISR_TX_Handler( void )
{
    bool  dataRegisterEmpty= false;
    bool  dataAvailable = false;
    if(sercom0USARTObj.txBusyStatus == true)
    {
        dataAvailable = (sercom0USARTObj.txProcessedSize < sercom0USARTObj.txSize);
        dataRegisterEmpty = ((SERCOM0_REGS->USART_INT.SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_DRE_Msk) == SERCOM_USART_INT_INTFLAG_DRE_Msk);
        
        while(dataRegisterEmpty && dataAvailable)
        {
            if (((SERCOM0_REGS->USART_INT.SERCOM_CTRLB & SERCOM_USART_INT_CTRLB_CHSIZE_Msk) >> SERCOM_USART_INT_CTRLB_CHSIZE_Pos) != 0x01U)
            {
                /* 8-bit mode */
                SERCOM0_REGS->USART_INT.SERCOM_DATA = sercom0USARTObj.txBuffer[sercom0USARTObj.txProcessedSize++];
            }
            else
            {
                /* 9-bit mode */
                SERCOM0_REGS->USART_INT.SERCOM_DATA = ((uint16_t*)sercom0USARTObj.txBuffer)[sercom0USARTObj.txProcessedSize++];
            }
            dataAvailable = (sercom0USARTObj.txProcessedSize < sercom0USARTObj.txSize);
            dataRegisterEmpty = ((SERCOM0_REGS->USART_INT.SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_DRE_Msk) == SERCOM_USART_INT_INTFLAG_DRE_Msk);
        }

        if(sercom0USARTObj.txProcessedSize >= sercom0USARTObj.txSize)
        {
            sercom0USARTObj.txBusyStatus = false;
            sercom0USARTObj.txSize = 0U;
            SERCOM0_REGS->USART_INT.SERCOM_INTENCLR = (uint8_t)SERCOM_USART_INT_INTENCLR_DRE_Msk;

            if(sercom0USARTObj.txCallback != NULL)
            {
                sercom0USARTObj.txCallback(sercom0USARTObj.txContext);
            }
        }
    }
}

void SERCOM0_USART_InterruptHandler( void )
{
    bool testCondition = false;
    if(SERCOM0_REGS->USART_INT.SERCOM_INTENSET != 0U)
    {
        /* Checks for error flag */
        testCondition = ((SERCOM0_REGS->USART_INT.SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_ERROR_Msk) == SERCOM_USART_INT_INTFLAG_ERROR_Msk);
        testCondition = ((SERCOM0_REGS->USART_INT.SERCOM_INTENSET & SERCOM_USART_INT_INTENSET_ERROR_Msk) == SERCOM_USART_INT_INTENSET_ERROR_Msk) && testCondition;
        if(testCondition)
        {
            SERCOM0_USART_ISR_ERR_Handler();
        }

        testCondition = ((SERCOM0_REGS->USART_INT.SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_DRE_Msk) == SERCOM_USART_INT_INTFLAG_DRE_Msk);
        testCondition = ((SERCOM0_REGS->USART_INT.SERCOM_INTENSET & SERCOM_USART_INT_INTENSET_DRE_Msk) == SERCOM_USART_INT_INTENSET_DRE_Msk) && testCondition;
        /* Checks for data register empty flag */
        if(testCondition)
        {
            SERCOM0_USART_ISR_TX_Handler();
        }

        testCondition = ((SERCOM0_REGS->USART_INT.SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_RXC_Msk) == SERCOM_USART_INT_INTFLAG_RXC_Msk);
        testCondition = ((SERCOM0_REGS->USART_INT.SERCOM_INTENSET & SERCOM_USART_INT_INTENSET_RXC_Msk) == SERCOM_USART_INT_INTENSET_RXC_Msk) && testCondition;
        /* Checks for receive complete empty flag */
        if(testCondition)
        {
            SERCOM0_USART_ISR_RX_Handler();
        }
    }
}
