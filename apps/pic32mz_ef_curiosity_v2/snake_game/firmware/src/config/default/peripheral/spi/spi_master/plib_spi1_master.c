/*******************************************************************************
  SPI PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_spi1_master.c

  Summary:
    SPI1 Master Source File

  Description:
    This file has implementation of all the interfaces provided for particular
    SPI peripheral.

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2018-2019 Microchip Technology Inc. and its subsidiaries.
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

#include "plib_spi1_master.h"
#include "interrupts.h"

// *****************************************************************************
// *****************************************************************************
// Section: SPI1 Implementation
// *****************************************************************************
// *****************************************************************************

/* Global object to save SPI Exchange related data */
volatile static SPI_OBJECT spi1Obj;

#define SPI1_CON_MSTEN                      (1UL << _SPI1CON_MSTEN_POSITION)
#define SPI1_CON_CKP                        (0UL << _SPI1CON_CKP_POSITION)
#define SPI1_CON_CKE                        (1UL << _SPI1CON_CKE_POSITION)
#define SPI1_CON_MODE_32_MODE_16            (0UL << _SPI1CON_MODE16_POSITION)
#define SPI1_CON_ENHBUF                     (1UL << _SPI1CON_ENHBUF_POSITION)
#define SPI1_CON_MCLKSEL                    (0UL << _SPI1CON_MCLKSEL_POSITION)
#define SPI1_CON_MSSEN                      (1UL << _SPI1CON_MSSEN_POSITION)
#define SPI1_CON_SMP                        (0UL << _SPI1CON_SMP_POSITION)

void SPI1_Initialize ( void )
{
    uint32_t rdata = 0U;

    /* Disable SPI1 Interrupts */
    IEC3CLR = 0x2000;
    IEC3CLR = 0x4000;
    IEC3CLR = 0x8000;

    /* STOP and Reset the SPI */
    SPI1CON = 0;

    /* Clear the Receiver buffer */
    rdata = SPI1BUF;
    rdata = rdata;

    /* Clear SPI1 Interrupt flags */
    IFS3CLR = 0x2000;
    IFS3CLR = 0x4000;
    IFS3CLR = 0x8000;

    /* BAUD Rate register Setup */
    SPI1BRG = 49;

    /* CLear the Overflow */
    SPI1STATCLR = _SPI1STAT_SPIROV_MASK;

    /*
    MSTEN = 1
    CKP = 0
    CKE = 1
    MODE<32,16> = 0
    ENHBUF = 1
    MSSEN = 1
    MCLKSEL = 0
    */
    SPI1CONSET = (SPI1_CON_MSSEN | SPI1_CON_MCLKSEL | SPI1_CON_ENHBUF | SPI1_CON_MODE_32_MODE_16 | SPI1_CON_CKE | SPI1_CON_CKP | SPI1_CON_MSTEN | SPI1_CON_SMP);

    /* Enable transmit interrupt when transmit buffer is completely empty (STXISEL = '01') */
    /* Enable receive interrupt when the receive buffer is not empty (SRXISEL = '01') */
    SPI1CONSET = 0x00000005;

    /* Initialize global variables */
    spi1Obj.transferIsBusy = false;
    spi1Obj.callback = NULL;

    /* Enable SPI1 */
    SPI1CONSET = _SPI1CON_ON_MASK;
}

bool SPI1_TransferSetup (SPI_TRANSFER_SETUP* setup, uint32_t spiSourceClock )
{
    uint32_t t_brg;
    uint32_t baudHigh;
    uint32_t baudLow;
    uint32_t errorHigh;
    uint32_t errorLow;

    if ((setup == NULL) || (setup->clockFrequency == 0U))
    {
        return false;
    }

    if(spiSourceClock == 0U)
    {
        // Use Master Clock Frequency set in GUI
        spiSourceClock = 100000000;
    }

    t_brg = (((spiSourceClock / (setup->clockFrequency)) / 2u) - 1u);
    baudHigh = spiSourceClock / (2u * (t_brg + 1u));
    baudLow = spiSourceClock / (2u * (t_brg + 2u));
    errorHigh = baudHigh - setup->clockFrequency;
    errorLow = setup->clockFrequency - baudLow;

    if (errorHigh > errorLow)
    {
        t_brg++;
    }

    if(t_brg > 8191U)
    {
        return false;
    }

    SPI1BRG = t_brg;
    SPI1CON = (SPI1CON & (~(_SPI1CON_MODE16_MASK | _SPI1CON_MODE32_MASK | _SPI1CON_CKP_MASK | _SPI1CON_CKE_MASK))) |
                            ((uint32_t)setup->clockPolarity | (uint32_t)setup->clockPhase | (uint32_t)setup->dataBits);

    return true;
}

bool SPI1_Write(void* pTransmitData, size_t txSize)
{
    return(SPI1_WriteRead(pTransmitData, txSize, NULL, 0));
}

bool SPI1_Read(void* pReceiveData, size_t rxSize)
{
    return(SPI1_WriteRead(NULL, 0, pReceiveData, rxSize));
}

bool SPI1_IsTransmitterBusy (void)
{
    return ((SPI1STAT & _SPI1STAT_SRMT_MASK) == 0U)? true : false;
}

bool SPI1_WriteRead (void* pTransmitData, size_t txSize, void* pReceiveData, size_t rxSize)
{
    bool isRequestAccepted = false;

    /* Verify the request */
    if((spi1Obj.transferIsBusy == false) && (((txSize > 0U) && (pTransmitData != NULL)) || ((rxSize > 0U) && (pReceiveData != NULL))))
    {
        isRequestAccepted = true;
        spi1Obj.txBuffer = pTransmitData;
        spi1Obj.rxBuffer = pReceiveData;
        spi1Obj.rxCount = 0;
        spi1Obj.txCount = 0;
        spi1Obj.dummySize = 0;

        if (pTransmitData != NULL)
        {
            spi1Obj.txSize = txSize;
        }
        else
        {
            spi1Obj.txSize = 0;
        }

        if (pReceiveData != NULL)
        {
            spi1Obj.rxSize = rxSize;
        }
        else
        {
            spi1Obj.rxSize = 0;
        }

        spi1Obj.transferIsBusy = true;

        size_t txSz = spi1Obj.txSize;
        if (spi1Obj.rxSize > txSz)
        {
            spi1Obj.dummySize = spi1Obj.rxSize - txSz;
        }

        /* Clear the receive overflow error if any */
        SPI1STATCLR = _SPI1STAT_SPIROV_MASK;

        /* Make sure there is no data pending in the RX FIFO */
        /* Depending on 8/16/32 bit mode, there may be 16/8/4 bytes in the FIFO */
        while ((SPI1STAT & _SPI1STAT_SPIRBE_MASK) == 0U)
        {
            (void)SPI1BUF;
        }

        /* Configure SPI to generate receive interrupt when receive buffer is empty (SRXISEL = '01') */
        SPI1CONCLR = _SPI1CON_SRXISEL_MASK;
        SPI1CONSET = 0x00000001;

        /* Configure SPI to generate transmit interrupt when the transmit shift register is empty (STXISEL = '00')*/
        SPI1CONCLR = _SPI1CON_STXISEL_MASK;

        /* Disable the receive interrupt */
        IEC3CLR = 0x4000;

        /* Disable the transmit interrupt */
        IEC3CLR = 0x8000;

        /* Clear the receive interrupt flag */
        IFS3CLR = 0x4000;

        /* Clear the transmit interrupt flag */
        IFS3CLR = 0x8000;

        /* Start the first write here itself, rest will happen in ISR context */
        if((_SPI1CON_MODE32_MASK) == (SPI1CON & (_SPI1CON_MODE32_MASK)))
        {
            spi1Obj.txSize >>= 2;
            spi1Obj.dummySize >>= 2;
            spi1Obj.rxSize >>= 2;

            txSz = spi1Obj.txSize;
            if(spi1Obj.txCount < txSz)
            {
                SPI1BUF = *((uint32_t*)spi1Obj.txBuffer);
                spi1Obj.txCount++;
            }
            else if (spi1Obj.dummySize > 0U)
            {
                SPI1BUF = (uint32_t)(0xffU);
                spi1Obj.dummySize--;
            }
            else
            {
                /* Nothing to process */
            }
        }
        else if((_SPI1CON_MODE16_MASK) == (SPI1CON & (_SPI1CON_MODE16_MASK)))
        {
            spi1Obj.txSize >>= 1;
            spi1Obj.dummySize >>= 1;
            spi1Obj.rxSize >>= 1;

            txSz = spi1Obj.txSize;
            if (spi1Obj.txCount < txSz)
            {
                SPI1BUF = *((uint16_t*)spi1Obj.txBuffer);
                spi1Obj.txCount++;
            }
            else if (spi1Obj.dummySize > 0U)
            {
                SPI1BUF = (uint16_t)(0xffU);
                spi1Obj.dummySize--;
            }
            else
            {
                /* Nothing to process */
            }
        }
        else
        {
            if (spi1Obj.txCount < txSz)
            {
                SPI1BUF = *((uint8_t*)spi1Obj.txBuffer);
                spi1Obj.txCount++;
            }
            else if (spi1Obj.dummySize > 0U)
            {
                SPI1BUF = (uint8_t)(0xffU);
                spi1Obj.dummySize--;
            }
            else
            {
                /* Nothing to process */
            }
        }

        if (rxSize > 0U)
        {
            /* Enable receive interrupt to complete the transfer in ISR context.
             * Keep the transmit interrupt disabled. Transmit interrupt will be
             * enabled later if txCount < txSize, when rxCount = rxSize.
             */
            IEC3SET = 0x4000;
        }
        else
        {
            if (spi1Obj.txCount != txSz)
            {
                /* Configure SPI to generate transmit buffer empty interrupt only if more than
                 * data is pending (STXISEL = '01')  */
                SPI1CONSET = 0x00000004;
            }
            /* Enable transmit interrupt to complete the transfer in ISR context */
            IEC3SET = 0x8000;
        }
    }

    return isRequestAccepted;
}

bool SPI1_IsBusy (void)
{
    uint32_t StatRead = SPI1STAT;
    return (((spi1Obj.transferIsBusy) != false) || (( StatRead & _SPI1STAT_SRMT_MASK) == 0U));
}

void SPI1_CallbackRegister (SPI_CALLBACK callback, uintptr_t context)
{
    spi1Obj.callback = callback;

    spi1Obj.context = context;
}

void __attribute__((used)) SPI1_RX_InterruptHandler (void)
{
    uint32_t receivedData = 0;

    /* Check if the receive buffer is empty or not */
    if ((SPI1STAT & _SPI1STAT_SPIRBE_MASK) == 0U)
    {
        /* Receive buffer is not empty. Read the received data. */
        receivedData = SPI1BUF;

        size_t rxCount = spi1Obj.rxCount;
        size_t txCount = spi1Obj.txCount;
        if (rxCount < spi1Obj.rxSize)
        {
            /* Copy the received data to the user buffer */
            if((_SPI1CON_MODE32_MASK) == (SPI1CON & (_SPI1CON_MODE32_MASK)))
            {
                ((uint32_t*)spi1Obj.rxBuffer)[rxCount] = receivedData;
                rxCount++;
            }
            else if((_SPI1CON_MODE16_MASK) == (SPI1CON & (_SPI1CON_MODE16_MASK)))
            {
                ((uint16_t*)spi1Obj.rxBuffer)[rxCount] = (uint16_t)receivedData;
                rxCount++;
            }
            else
            {
                ((uint8_t*)spi1Obj.rxBuffer)[rxCount] = (uint8_t)receivedData;
                rxCount++;
            }

            spi1Obj.rxCount = rxCount;

            if (rxCount == spi1Obj.rxSize)
            {
                if (txCount < spi1Obj.txSize)
                {
                    /* Reception of all bytes is complete. However, there are few more
                     * bytes to be transmitted as txCount != txSize. Finish the
                     * transmission of the remaining bytes from the transmit interrupt. */

                    /* Disable the receive interrupt */
                    IEC3CLR = 0x4000;

                    /* Generate TX interrupt when buffer is completely empty (STXISEL = '00') */
                    SPI1CONCLR = _SPI1CON_STXISEL_MASK;
                    SPI1CONSET = 0x00000004;

                    /* Enable the transmit interrupt. Callback will be given from the
                     * transmit interrupt, when all bytes are shifted out. */
                    IEC3SET = 0x8000;
                }
            }
        }
        if (rxCount < spi1Obj.rxSize)
        {
            /* More bytes pending to be received .. */
            if((_SPI1CON_MODE32_MASK) == (SPI1CON & (_SPI1CON_MODE32_MASK)))
            {
                if (txCount < spi1Obj.txSize)
                {
                    SPI1BUF = ((uint32_t*)spi1Obj.txBuffer)[txCount];
                    txCount++;
                }
                else if (spi1Obj.dummySize > 0U)
                {
                    SPI1BUF = (uint32_t)(0xffU);
                    spi1Obj.dummySize--;
                }
                else
                {
                    /* Do Nothing */
                }
            }
            else if((_SPI1CON_MODE16_MASK) == (SPI1CON & (_SPI1CON_MODE16_MASK)))
            {
                if (txCount < spi1Obj.txSize)
                {
                    SPI1BUF = ((uint16_t*)spi1Obj.txBuffer)[txCount];
                    txCount++;
                }
                else if (spi1Obj.dummySize > 0U)
                {
                    SPI1BUF = (uint16_t)(0xffU);
                    spi1Obj.dummySize--;
                }
                else
                {
                    /* Do Nothing */
                }
            }
            else
            {
                if (txCount < spi1Obj.txSize)
                {
                    SPI1BUF = ((uint8_t*)spi1Obj.txBuffer)[txCount];
                    txCount++;
                }
                else if (spi1Obj.dummySize > 0U)
                {
                    SPI1BUF = (uint8_t)(0xffU);
                    spi1Obj.dummySize--;
                }
                else
                {
                    /* Do Nothing */
                }
            }
            spi1Obj.txCount = txCount;
        }
        else
        {
            if(rxCount == spi1Obj.rxSize)
            {
                if (txCount == spi1Obj.txSize)
                {
                    /* Clear receiver overflow error if any */
                    SPI1STATCLR = _SPI1STAT_SPIROV_MASK;

                    /* Disable receive interrupt */
                    IEC3CLR = 0x4000;

                    /* Transfer complete. Give a callback */
                    spi1Obj.transferIsBusy = false;

                    if(spi1Obj.callback != NULL)
                    {
                        uintptr_t context = spi1Obj.context;
                        spi1Obj.callback(context);
                    }
                }
            }
        }
    }

    /* Clear SPI1 RX Interrupt flag */
    /* This flag should cleared only after reading buffer */
    IFS3CLR = 0x4000;
}

void __attribute__((used)) SPI1_TX_InterruptHandler (void)
{
    /* If there are more words to be transmitted, then transmit them here and keep track of the count */
    if((SPI1STAT & _SPI1STAT_SPITBE_MASK) == _SPI1STAT_SPITBE_MASK)
    {
        size_t txCount = spi1Obj.txCount;
        if (txCount < spi1Obj.txSize)
        {
            if((_SPI1CON_MODE32_MASK) == (SPI1CON & (_SPI1CON_MODE32_MASK)))
            {
                SPI1BUF = ((uint32_t*)spi1Obj.txBuffer)[txCount];
                txCount++;
            }
            else if((_SPI1CON_MODE16_MASK) == (SPI1CON & (_SPI1CON_MODE16_MASK)))
            {
                SPI1BUF = ((uint16_t*)spi1Obj.txBuffer)[txCount];
                txCount++;
            }
            else
            {
                SPI1BUF = ((uint8_t*)spi1Obj.txBuffer)[txCount];
                txCount++;
            }

            spi1Obj.txCount = txCount;

            if (txCount == spi1Obj.txSize)
            {
                /* All bytes are submitted to the SPI module. Now, enable transmit
                 * interrupt when the shift register is empty (STXISEL = '00')*/
                SPI1CONCLR = _SPI1CON_STXISEL_MASK;
            }
        }
        else if (txCount == spi1Obj.txSize)
        {
            if ((SPI1STAT & _SPI1STAT_SRMT_MASK) != 0U)
            {
                /* This part of code is executed when the shift register is empty. */

                /* Clear receiver overflow error if any */
                SPI1STATCLR = _SPI1STAT_SPIROV_MASK;

                /* Disable transmit interrupt */
                IEC3CLR = 0x8000;

                /* Transfer complete. Give a callback */
                spi1Obj.transferIsBusy = false;

                if(spi1Obj.callback != NULL)
                {
                    uintptr_t context = spi1Obj.context;
                    spi1Obj.callback(context);
                }
            }
        }
        else
        {
            /* Do Nothing */
        }
    }
    /* Clear the transmit interrupt flag */
    IFS3CLR = 0x8000;
}

