/*******************************************************************************
  SERIAL COMMUNICATION SERIAL PERIPHERAL INTERFACE(SERCOM1_SPI) PLIB

  Company
    Microchip Technology Inc.

  File Name
    plib_sercom1_spi_slave.c

  Summary
    SERCOM1_SPI PLIB Slave Implementation File.

  Description
    This file defines the interface to the SERCOM SPI Slave peripheral library.
    This library provides access to and control of the associated
    peripheral instance.

  Remarks:
    None.

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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
// DOM-IGNORE-END

#include "interrupts.h"
#include "plib_sercom1_spi_slave.h"
#include <string.h>

// *****************************************************************************
// *****************************************************************************
// Section: MACROS Definitions
// *****************************************************************************
// *****************************************************************************
#define SERCOM1_SPI_READ_BUFFER_SIZE            256U
#define SERCOM1_SPI_WRITE_BUFFER_SIZE           256U

static uint8_t SERCOM1_SPI_ReadBuffer[SERCOM1_SPI_READ_BUFFER_SIZE];
static uint8_t SERCOM1_SPI_WriteBuffer[SERCOM1_SPI_WRITE_BUFFER_SIZE];


/* Global object to save SPI Exchange related data  */
static SPI_SLAVE_OBJECT sercom1SPISObj;

// *****************************************************************************
// *****************************************************************************
// Section: SERCOM1_SPI Slave Implementation
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************

void SERCOM1_SPI_Initialize(void)
{
    /* CHSIZE - 8_BIT
     * PLOADEN - 1
     *  SSDE - 1 
     * RXEN - 1
     */
    SERCOM1_REGS->SPIS.SERCOM_CTRLB = SERCOM_SPIS_CTRLB_CHSIZE_8_BIT | SERCOM_SPIS_CTRLB_PLOADEN_Msk | SERCOM_SPIS_CTRLB_RXEN_Msk | SERCOM_SPIS_CTRLB_SSDE_Msk;

    /* Wait for synchronization */
    while(SERCOM1_REGS->SPIS.SERCOM_SYNCBUSY != 0U)
    {
        /* Do nothing */
    }

    /* Mode - SPI Slave
     * IBON - 1 (Set immediately upon buffer overflow)
     * DOPO - PAD0
     * DIPO - PAD3
     * CPHA - LEADING_EDGE
     * COPL - IDLE_LOW
     * DORD - MSB
     * ENABLE - 1
     */
    SERCOM1_REGS->SPIS.SERCOM_CTRLA = SERCOM_SPIS_CTRLA_MODE_SPI_SLAVE | SERCOM_SPIS_CTRLA_IBON_Msk | SERCOM_SPIS_CTRLA_DOPO_PAD0 | SERCOM_SPIS_CTRLA_DIPO_PAD3 | SERCOM_SPIS_CTRLA_CPOL_IDLE_LOW | SERCOM_SPIS_CTRLA_CPHA_LEADING_EDGE | SERCOM_SPIS_CTRLA_DORD_MSB | SERCOM_SPIS_CTRLA_ENABLE_Msk ;

    /* Wait for synchronization */
    while(SERCOM1_REGS->SPIS.SERCOM_SYNCBUSY != 0U)
    {
        /* Do nothing */
    }

    sercom1SPISObj.rdInIndex = 0U;
    sercom1SPISObj.wrOutIndex = 0U;
    sercom1SPISObj.nWrBytes = 0U;
    sercom1SPISObj.errorStatus = SPI_SLAVE_ERROR_NONE;
    sercom1SPISObj.callback = NULL ;
    sercom1SPISObj.transferIsBusy = false ;

    SERCOM1_REGS->SPIS.SERCOM_INTENSET = (uint8_t)(SERCOM_SPIS_INTENSET_SSL_Msk | SERCOM_SPIS_INTENCLR_RXC_Msk);

}

/* For 9-bit mode, the "size" must be specified in terms of 16-bit words */
size_t SERCOM1_SPI_Read(void* pRdBuffer, size_t size)
{
    uint8_t intState = SERCOM1_REGS->SPIS.SERCOM_INTENSET;
    size_t rdSize = size;

    SERCOM1_REGS->SPIS.SERCOM_INTENCLR = intState;

    if (rdSize > sercom1SPISObj.rdInIndex)
    {
        rdSize = sercom1SPISObj.rdInIndex;
    }

    memcpy(pRdBuffer, SERCOM1_SPI_ReadBuffer, rdSize);

    SERCOM1_REGS->SPIS.SERCOM_INTENSET = intState;

    return rdSize;
}

/* For 9-bit mode, the "size" must be specified in terms of 16-bit words */
size_t SERCOM1_SPI_Write(void* pWrBuffer, size_t size )
{
    uint8_t intState = SERCOM1_REGS->SPIS.SERCOM_INTENSET;
    size_t wrSize = size;
    bool writeReady = false;

    SERCOM1_REGS->SPIS.SERCOM_INTENCLR = intState;

    if (wrSize > SERCOM1_SPI_WRITE_BUFFER_SIZE)
    {
        wrSize = SERCOM1_SPI_WRITE_BUFFER_SIZE;
    }

    memcpy(SERCOM1_SPI_WriteBuffer, pWrBuffer, wrSize);

    sercom1SPISObj.nWrBytes = wrSize;
    sercom1SPISObj.wrOutIndex = 0U;

    writeReady = (sercom1SPISObj.wrOutIndex < sercom1SPISObj.nWrBytes);
    writeReady = ((SERCOM1_REGS->SPIS.SERCOM_INTFLAG & SERCOM_SPIS_INTFLAG_DRE_Msk) == SERCOM_SPIS_INTFLAG_DRE_Msk) && writeReady;
    while (writeReady)
    {
        SERCOM1_REGS->SPIS.SERCOM_DATA = SERCOM1_SPI_WriteBuffer[sercom1SPISObj.wrOutIndex++];
        writeReady = (sercom1SPISObj.wrOutIndex < sercom1SPISObj.nWrBytes);
        writeReady = ((SERCOM1_REGS->SPIS.SERCOM_INTFLAG & SERCOM_SPIS_INTFLAG_DRE_Msk) == SERCOM_SPIS_INTFLAG_DRE_Msk) && writeReady;
    }

    /* Restore interrupt enable state and also enable DRE interrupt to start pre-loading of DATA register */
    SERCOM1_REGS->SPIS.SERCOM_INTENSET = (intState | (uint8_t)SERCOM_SPIS_INTENSET_DRE_Msk);

    return wrSize;
}

/* For 9-bit mode, the return value is in terms of 16-bit words */
size_t SERCOM1_SPI_ReadCountGet(void)
{
    return sercom1SPISObj.rdInIndex;
}

/* For 9-bit mode, the return value is in terms of 16-bit words */
size_t SERCOM1_SPI_ReadBufferSizeGet(void)
{
    return SERCOM1_SPI_READ_BUFFER_SIZE;
}

/* For 9-bit mode, the return value is in terms of 16-bit words */
size_t SERCOM1_SPI_WriteBufferSizeGet(void)
{
    return SERCOM1_SPI_WRITE_BUFFER_SIZE;
}

void SERCOM1_SPI_CallbackRegister(SERCOM_SPI_SLAVE_CALLBACK callBack, uintptr_t context )
{
    sercom1SPISObj.callback = callBack;

    sercom1SPISObj.context = context;
}

/* The status is returned busy during the period the chip-select remains asserted */
bool SERCOM1_SPI_IsBusy(void)
{
    return sercom1SPISObj.transferIsBusy;
}


SPI_SLAVE_ERROR SERCOM1_SPI_ErrorGet(void)
{
    SPI_SLAVE_ERROR errorStatus = sercom1SPISObj.errorStatus;

    sercom1SPISObj.errorStatus = SPI_SLAVE_ERROR_NONE;

    return errorStatus;
}

void SERCOM1_SPI_InterruptHandler(void)
{
    uint8_t txRxData;
    uint8_t intFlag = SERCOM1_REGS->SPIS.SERCOM_INTFLAG;

    if((SERCOM1_REGS->SPIS.SERCOM_INTFLAG & SERCOM_SPIS_INTFLAG_SSL_Msk) == SERCOM_SPIS_INTFLAG_SSL_Msk)
    {
        /* Clear the SSL flag and enable TXC interrupt */
        SERCOM1_REGS->SPIS.SERCOM_INTFLAG = (uint8_t)SERCOM_SPIS_INTFLAG_SSL_Msk;
        SERCOM1_REGS->SPIS.SERCOM_INTENSET = (uint8_t)SERCOM_SPIS_INTENSET_TXC_Msk;
        sercom1SPISObj.rdInIndex = 0U;
        sercom1SPISObj.transferIsBusy = true;
    }

    if ((SERCOM1_REGS->SPIS.SERCOM_STATUS & SERCOM_SPIS_STATUS_BUFOVF_Msk) == SERCOM_SPIS_STATUS_BUFOVF_Msk)
    {
        /* Save the error to report it to application later, when the transfer is complete (TXC = 1) */
        sercom1SPISObj.errorStatus = SERCOM_SPIS_STATUS_BUFOVF_Msk;

        /* Clear the status register */
        SERCOM1_REGS->SPIS.SERCOM_STATUS = (uint16_t)SERCOM_SPIS_STATUS_BUFOVF_Msk;

        /* Flush out the received data until RXC flag is set */
        while((SERCOM1_REGS->SPIS.SERCOM_INTFLAG & SERCOM_SPIS_INTFLAG_RXC_Msk) == SERCOM_SPIS_INTFLAG_RXC_Msk)
        {
            /* Reading DATA register will also clear the RXC flag */
            txRxData = (uint8_t)SERCOM1_REGS->SPIS.SERCOM_DATA;
        }

        /* Clear the Error Interrupt Flag */
        SERCOM1_REGS->SPIS.SERCOM_INTFLAG = (uint8_t)SERCOM_SPIS_INTFLAG_ERROR_Msk;
    }

    if((SERCOM1_REGS->SPIS.SERCOM_INTFLAG & SERCOM_SPIS_INTFLAG_RXC_Msk) == SERCOM_SPIS_INTFLAG_RXC_Msk)
    {
        /* Reading DATA register will also clear the RXC flag */
        txRxData = (uint8_t)SERCOM1_REGS->SPIS.SERCOM_DATA;     

        if (sercom1SPISObj.rdInIndex < SERCOM1_SPI_READ_BUFFER_SIZE)
        {
            SERCOM1_SPI_ReadBuffer[sercom1SPISObj.rdInIndex++] = txRxData;
        }
    }

    if((SERCOM1_REGS->SPIS.SERCOM_INTFLAG & SERCOM_SPIS_INTFLAG_DRE_Msk) == SERCOM_SPIS_INTFLAG_DRE_Msk)
    {
        if (sercom1SPISObj.wrOutIndex < sercom1SPISObj.nWrBytes)
        {
            txRxData = SERCOM1_SPI_WriteBuffer[sercom1SPISObj.wrOutIndex++];

            /* Before writing to DATA register (which clears TXC flag), check if TXC flag is set */
            if((SERCOM1_REGS->SPIS.SERCOM_INTFLAG & SERCOM_SPIS_INTFLAG_TXC_Msk) == SERCOM_SPIS_INTFLAG_TXC_Msk)
            {
                intFlag = (uint8_t)SERCOM_SPIS_INTFLAG_TXC_Msk;
            }
            SERCOM1_REGS->SPIS.SERCOM_DATA = (uint32_t)txRxData;
        }
        else
        {
            /* Disable DRE interrupt. The last byte sent by the master will be shifted out automatically */
            SERCOM1_REGS->SPIS.SERCOM_INTENCLR = (uint8_t)SERCOM_SPIS_INTENCLR_DRE_Msk;
        }
    }

    if((intFlag & SERCOM_SPIS_INTFLAG_TXC_Msk) == SERCOM_SPIS_INTFLAG_TXC_Msk)
    {
        /* Clear TXC flag */
        SERCOM1_REGS->SPIS.SERCOM_INTFLAG = (uint8_t)SERCOM_SPIS_INTFLAG_TXC_Msk;

        sercom1SPISObj.transferIsBusy = false;

        sercom1SPISObj.wrOutIndex = 0U;
        sercom1SPISObj.nWrBytes = 0U;

        if(sercom1SPISObj.callback != NULL)
        {
            sercom1SPISObj.callback(sercom1SPISObj.context);
        }
    }
}
