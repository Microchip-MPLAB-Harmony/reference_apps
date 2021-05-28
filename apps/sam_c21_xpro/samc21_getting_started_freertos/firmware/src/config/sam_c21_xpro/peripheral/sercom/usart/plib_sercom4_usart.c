/*******************************************************************************
  SERCOM Universal Synchronous/Asynchrnous Receiver/Transmitter PLIB

  Company
    Microchip Technology Inc.

  File Name
    plib_sercom4_usart.c

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

#include "plib_sercom4_usart.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************


/* SERCOM4 USART baud value for 115200 Hz baud rate */
#define SERCOM4_USART_INT_BAUD_VALUE            (63019U)

SERCOM_USART_OBJECT sercom4USARTObj;

// *****************************************************************************
// *****************************************************************************
// Section: SERCOM4 USART Interface Routines
// *****************************************************************************
// *****************************************************************************

void static SERCOM4_USART_ErrorClear( void )
{
    uint8_t  u8dummyData = 0;

    /* Clear error flag */
    SERCOM4_REGS->USART_INT.SERCOM_INTFLAG = SERCOM_USART_INT_INTFLAG_ERROR_Msk;

    /* Clear all errors */
    SERCOM4_REGS->USART_INT.SERCOM_STATUS = SERCOM_USART_INT_STATUS_PERR_Msk | SERCOM_USART_INT_STATUS_FERR_Msk | SERCOM_USART_INT_STATUS_BUFOVF_Msk;

    /* Flush existing error bytes from the RX FIFO */
    while((SERCOM4_REGS->USART_INT.SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_RXC_Msk) == SERCOM_USART_INT_INTFLAG_RXC_Msk)
    {
        u8dummyData = SERCOM4_REGS->USART_INT.SERCOM_DATA;
    }

    /* Ignore the warning */
    (void)u8dummyData;
}

void SERCOM4_USART_Initialize( void )
{
    /*
     * Configures USART Clock Mode
     * Configures TXPO and RXPO
     * Configures Data Order
     * Configures Standby Mode
     * Configures Sampling rate
     * Configures IBON
     */
    SERCOM4_REGS->USART_INT.SERCOM_CTRLA = SERCOM_USART_INT_CTRLA_MODE_USART_INT_CLK | SERCOM_USART_INT_CTRLA_RXPO(0x3) | SERCOM_USART_INT_CTRLA_TXPO(0x1) | SERCOM_USART_INT_CTRLA_DORD_Msk | SERCOM_USART_INT_CTRLA_IBON_Msk | SERCOM_USART_INT_CTRLA_FORM(0x0) | SERCOM_USART_INT_CTRLA_SAMPR(0) ;

    /* Configure Baud Rate */
    SERCOM4_REGS->USART_INT.SERCOM_BAUD = SERCOM_USART_INT_BAUD_BAUD(SERCOM4_USART_INT_BAUD_VALUE);

    /*
     * Configures RXEN
     * Configures TXEN
     * Configures CHSIZE
     * Configures Parity
     * Configures Stop bits
     */
    SERCOM4_REGS->USART_INT.SERCOM_CTRLB = SERCOM_USART_INT_CTRLB_CHSIZE_8_BIT | SERCOM_USART_INT_CTRLB_SBMODE_1_BIT | SERCOM_USART_INT_CTRLB_RXEN_Msk | SERCOM_USART_INT_CTRLB_TXEN_Msk;

    /* Wait for sync */
    while(SERCOM4_REGS->USART_INT.SERCOM_SYNCBUSY);


    /* Enable the UART after the configurations */
    SERCOM4_REGS->USART_INT.SERCOM_CTRLA |= SERCOM_USART_INT_CTRLA_ENABLE_Msk;

    /* Wait for sync */
    while(SERCOM4_REGS->USART_INT.SERCOM_SYNCBUSY);

    /* Initialize instance object */
    sercom4USARTObj.rxBuffer = NULL;
    sercom4USARTObj.rxSize = 0;
    sercom4USARTObj.rxProcessedSize = 0;
    sercom4USARTObj.rxBusyStatus = false;
    sercom4USARTObj.rxCallback = NULL;
    sercom4USARTObj.txBuffer = NULL;
    sercom4USARTObj.txSize = 0;
    sercom4USARTObj.txProcessedSize = 0;
    sercom4USARTObj.txBusyStatus = false;
    sercom4USARTObj.txCallback = NULL;
}

uint32_t SERCOM4_USART_FrequencyGet( void )
{
    return (uint32_t) (48000000UL);
}

bool SERCOM4_USART_SerialSetup( USART_SERIAL_SETUP * serialSetup, uint32_t clkFrequency )
{
    bool setupStatus       = false;
    uint32_t baudValue     = 0;
    uint32_t sampleRate    = 0;

    if((sercom4USARTObj.rxBusyStatus == true) || (sercom4USARTObj.txBusyStatus == true))
    {
        /* Transaction is in progress, so return without updating settings */
        return setupStatus;
    }

    if((serialSetup != NULL) & (serialSetup->baudRate != 0))
    {
        if(clkFrequency == 0)
        {
            clkFrequency = SERCOM4_USART_FrequencyGet();
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
            SERCOM4_REGS->USART_INT.SERCOM_CTRLA &= ~SERCOM_USART_INT_CTRLA_ENABLE_Msk;

            /* Wait for sync */
            while(SERCOM4_REGS->USART_INT.SERCOM_SYNCBUSY);

            /* Configure Baud Rate */
            SERCOM4_REGS->USART_INT.SERCOM_BAUD = SERCOM_USART_INT_BAUD_BAUD(baudValue);

            /* Configure Parity Options */
            if(serialSetup->parity == USART_PARITY_NONE)
            {
                SERCOM4_REGS->USART_INT.SERCOM_CTRLA =  (SERCOM4_REGS->USART_INT.SERCOM_CTRLA & ~(SERCOM_USART_INT_CTRLA_SAMPR_Msk | SERCOM_USART_INT_CTRLA_FORM_Msk)) | SERCOM_USART_INT_CTRLA_FORM(0x0) | SERCOM_USART_INT_CTRLA_SAMPR(sampleRate); 
                SERCOM4_REGS->USART_INT.SERCOM_CTRLB = (SERCOM4_REGS->USART_INT.SERCOM_CTRLB & ~(SERCOM_USART_INT_CTRLB_CHSIZE_Msk | SERCOM_USART_INT_CTRLB_SBMODE_Pos)) | ((uint32_t) serialSetup->dataWidth | (uint32_t) serialSetup->stopBits);
            }
            else
            {
                SERCOM4_REGS->USART_INT.SERCOM_CTRLA =  (SERCOM4_REGS->USART_INT.SERCOM_CTRLA & ~(SERCOM_USART_INT_CTRLA_SAMPR_Msk | SERCOM_USART_INT_CTRLA_FORM_Msk)) | SERCOM_USART_INT_CTRLA_FORM(0x1) | SERCOM_USART_INT_CTRLA_SAMPR(sampleRate); 
                SERCOM4_REGS->USART_INT.SERCOM_CTRLB = (SERCOM4_REGS->USART_INT.SERCOM_CTRLB & ~(SERCOM_USART_INT_CTRLB_CHSIZE_Msk | SERCOM_USART_INT_CTRLB_SBMODE_Pos | SERCOM_USART_INT_CTRLB_PMODE_Msk)) | (uint32_t) serialSetup->dataWidth | (uint32_t) serialSetup->stopBits | (uint32_t) serialSetup->parity ;
            }

            /* Wait for sync */
            while(SERCOM4_REGS->USART_INT.SERCOM_SYNCBUSY);

            /* Enable the USART after the configurations */
            SERCOM4_REGS->USART_INT.SERCOM_CTRLA |= SERCOM_USART_INT_CTRLA_ENABLE_Msk;

            /* Wait for sync */
            while(SERCOM4_REGS->USART_INT.SERCOM_SYNCBUSY);

            setupStatus = true;
        }
    }

    return setupStatus;
}

USART_ERROR SERCOM4_USART_ErrorGet( void )
{
    USART_ERROR errorStatus = USART_ERROR_NONE;

    errorStatus = (USART_ERROR) (SERCOM4_REGS->USART_INT.SERCOM_STATUS & (SERCOM_USART_INT_STATUS_PERR_Msk | SERCOM_USART_INT_STATUS_FERR_Msk | SERCOM_USART_INT_STATUS_BUFOVF_Msk));

    if(errorStatus != USART_ERROR_NONE)
    {
        SERCOM4_USART_ErrorClear();
    }

    return errorStatus;
}


void SERCOM4_USART_TransmitterEnable( void )
{
    SERCOM4_REGS->USART_INT.SERCOM_CTRLB |= SERCOM_USART_INT_CTRLB_TXEN_Msk;
	
	/* Wait for sync */
    while(SERCOM4_REGS->USART_INT.SERCOM_SYNCBUSY);
}

void SERCOM4_USART_TransmitterDisable( void )
{
    SERCOM4_REGS->USART_INT.SERCOM_CTRLB &= ~SERCOM_USART_INT_CTRLB_TXEN_Msk;
	
	/* Wait for sync */
    while(SERCOM4_REGS->USART_INT.SERCOM_SYNCBUSY);
}

bool SERCOM4_USART_Write( void *buffer, const size_t size )
{
    bool writeStatus      = false;
    uint8_t *pu8Data      = (uint8_t*)buffer;

    if(pu8Data != NULL)
    {
        if(sercom4USARTObj.txBusyStatus == false)
        {
            sercom4USARTObj.txBuffer = pu8Data;
            sercom4USARTObj.txSize = size;
            sercom4USARTObj.txProcessedSize = 0;
            sercom4USARTObj.txBusyStatus = true;

            /* Initiate the transfer by sending first byte */
            if((SERCOM4_REGS->USART_INT.SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_DRE_Msk) == SERCOM_USART_INT_INTFLAG_DRE_Msk)
            {
                SERCOM4_REGS->USART_INT.SERCOM_DATA = sercom4USARTObj.txBuffer[sercom4USARTObj.txProcessedSize++];
            }

            SERCOM4_REGS->USART_INT.SERCOM_INTENSET = SERCOM_USART_INT_INTFLAG_DRE_Msk;

            writeStatus = true;
        }
    }

    return writeStatus;
}


bool SERCOM4_USART_WriteIsBusy( void )
{
    return sercom4USARTObj.txBusyStatus;
}

size_t SERCOM4_USART_WriteCountGet( void )
{
    return sercom4USARTObj.txProcessedSize;
}

void SERCOM4_USART_WriteCallbackRegister( SERCOM_USART_CALLBACK callback, uintptr_t context )
{
    sercom4USARTObj.txCallback = callback;

    sercom4USARTObj.txContext = context;
}


void SERCOM4_USART_ReceiverEnable( void )
{
    SERCOM4_REGS->USART_INT.SERCOM_CTRLB |= SERCOM_USART_INT_CTRLB_RXEN_Msk;
	
	/* Wait for sync */
    while(SERCOM4_REGS->USART_INT.SERCOM_SYNCBUSY);
}

void SERCOM4_USART_ReceiverDisable( void )
{
    SERCOM4_REGS->USART_INT.SERCOM_CTRLB &= ~SERCOM_USART_INT_CTRLB_RXEN_Msk;
	
	/* Wait for sync */
    while(SERCOM4_REGS->USART_INT.SERCOM_SYNCBUSY);
}

bool SERCOM4_USART_Read( void *buffer, const size_t size )
{
    bool readStatus        = false;
    uint8_t *pu8Data       = (uint8_t*)buffer;

    if(pu8Data != NULL)
    {
        /* Clear errors before submitting the request.
         * ErrorGet clears errors internally.
         */
        SERCOM4_USART_ErrorGet();

        if(sercom4USARTObj.rxBusyStatus == false)
        {
            sercom4USARTObj.rxBuffer = pu8Data;
            sercom4USARTObj.rxSize = size;
            sercom4USARTObj.rxProcessedSize = 0;
            sercom4USARTObj.rxBusyStatus = true;
            readStatus = true;

            /* Enable error interrupt */
            SERCOM4_REGS->USART_INT.SERCOM_INTENSET = SERCOM_USART_INT_INTENSET_ERROR_Msk;

            /* Enable Receive Complete interrupt */
            SERCOM4_REGS->USART_INT.SERCOM_INTENSET = SERCOM_USART_INT_INTENSET_RXC_Msk;
        }
    }

    return readStatus;
}

bool SERCOM4_USART_ReadIsBusy( void )
{
    return sercom4USARTObj.rxBusyStatus;
}

size_t SERCOM4_USART_ReadCountGet( void )
{
    return sercom4USARTObj.rxProcessedSize;
}

bool SERCOM4_USART_ReadAbort(void)
{
    if (sercom4USARTObj.rxBusyStatus == true)
    {        
        /* Disable the receive interrupt */				
		SERCOM4_REGS->USART_INT.SERCOM_INTENCLR = SERCOM_USART_INT_INTENCLR_RXC_Msk;
						
		/* Disable error interrupt */
		SERCOM4_REGS->USART_INT.SERCOM_INTENCLR = SERCOM_USART_INT_INTENCLR_ERROR_Msk;
        
        sercom4USARTObj.rxBusyStatus = false;  		
        
		/* If required application should read the num bytes processed prior to calling the read abort API */
        sercom4USARTObj.rxSize = sercom4USARTObj.rxProcessedSize = 0;
    }	
	
	return true;	
}

void SERCOM4_USART_ReadCallbackRegister( SERCOM_USART_CALLBACK callback, uintptr_t context )
{
    sercom4USARTObj.rxCallback = callback;

    sercom4USARTObj.rxContext = context;
}


void static SERCOM4_USART_ISR_ERR_Handler( void )
{
    USART_ERROR errorStatus = USART_ERROR_NONE;

    errorStatus = (USART_ERROR) (SERCOM4_REGS->USART_INT.SERCOM_STATUS &
                  (SERCOM_USART_INT_STATUS_PERR_Msk |
                  SERCOM_USART_INT_STATUS_FERR_Msk |
                  SERCOM_USART_INT_STATUS_BUFOVF_Msk));

    if(errorStatus != USART_ERROR_NONE)
    {
        /* Clear error and receive interrupt to abort on-going transfer */
        SERCOM4_REGS->USART_INT.SERCOM_INTENCLR = SERCOM_USART_INT_INTENCLR_ERROR_Msk | SERCOM_USART_INT_INTENCLR_RXC_Msk;

        if(sercom4USARTObj.rxCallback != NULL)
        {
            sercom4USARTObj.rxCallback(sercom4USARTObj.rxContext);
        }

        /* In case of errors are not cleared by client using ErrorGet API */
        SERCOM4_USART_ErrorClear();
    }
}

void static SERCOM4_USART_ISR_RX_Handler( void )
{
    uint16_t temp;

    if(sercom4USARTObj.rxBusyStatus == true)
    {
        if(sercom4USARTObj.rxProcessedSize < sercom4USARTObj.rxSize)
        {
            temp = SERCOM4_REGS->USART_INT.SERCOM_DATA;
            sercom4USARTObj.rxBuffer[sercom4USARTObj.rxProcessedSize++] = (uint8_t) (temp);

            if(sercom4USARTObj.rxProcessedSize == sercom4USARTObj.rxSize)
            {
                sercom4USARTObj.rxBusyStatus = false;
                sercom4USARTObj.rxSize = 0;
                SERCOM4_REGS->USART_INT.SERCOM_INTENCLR = SERCOM_USART_INT_INTENCLR_RXC_Msk;
				
				SERCOM4_REGS->USART_INT.SERCOM_INTENCLR = SERCOM_USART_INT_INTENCLR_ERROR_Msk;

                if(sercom4USARTObj.rxCallback != NULL)
                {
                    sercom4USARTObj.rxCallback(sercom4USARTObj.rxContext);
                }
            }
        }
    }
}

void static SERCOM4_USART_ISR_TX_Handler( void )
{
    if(sercom4USARTObj.txBusyStatus == true)
    {
        if(sercom4USARTObj.txProcessedSize < sercom4USARTObj.txSize)
        {
            SERCOM4_REGS->USART_INT.SERCOM_DATA = sercom4USARTObj.txBuffer[sercom4USARTObj.txProcessedSize++];
        }

        if(sercom4USARTObj.txProcessedSize >= sercom4USARTObj.txSize)
        {
            sercom4USARTObj.txBusyStatus = false;
            sercom4USARTObj.txSize = 0;
            SERCOM4_REGS->USART_INT.SERCOM_INTENCLR = SERCOM_USART_INT_INTENCLR_DRE_Msk;

            if(sercom4USARTObj.txCallback != NULL)
            {
                sercom4USARTObj.txCallback(sercom4USARTObj.txContext);
            }
        }
    }
}

void SERCOM4_USART_InterruptHandler( void )
{
    if(SERCOM4_REGS->USART_INT.SERCOM_INTENSET != 0)
    {
        /* Checks for data register empty flag */
        if((SERCOM4_REGS->USART_INT.SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_DRE_Msk) == SERCOM_USART_INT_INTFLAG_DRE_Msk)
        {
            SERCOM4_USART_ISR_TX_Handler();
        }

        /* Checks for receive complete empty flag */
        if((SERCOM4_REGS->USART_INT.SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_RXC_Msk) == SERCOM_USART_INT_INTFLAG_RXC_Msk)
        {
            SERCOM4_USART_ISR_RX_Handler();
        }

        /* Checks for error flag */
        if((SERCOM4_REGS->USART_INT.SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_ERROR_Msk) == SERCOM_USART_INT_INTFLAG_ERROR_Msk)
        {
            SERCOM4_USART_ISR_ERR_Handler();
        }
    }
}
