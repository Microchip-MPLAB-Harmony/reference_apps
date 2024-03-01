/*******************************************************************************
  Controller Area Network (CAN) Peripheral Library Source File

  Company:
    Microchip Technology Inc.

  File Name:
    plib_can0.c

  Summary:
    CAN peripheral library interface.

  Description:
    This file defines the interface to the CAN peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

  Remarks:
    None.
*******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END
// *****************************************************************************
// *****************************************************************************
// Header Includes
// *****************************************************************************
// *****************************************************************************

#include "device.h"
#include "interrupts.h"
#include "plib_can0.h"

// *****************************************************************************
// *****************************************************************************
// Global Data
// *****************************************************************************
// *****************************************************************************
#define CAN_STD_ID_Msk        0x7FFU

static CAN_OBJ can0Obj;

// *****************************************************************************
// *****************************************************************************
// CAN0 PLib Interface Routines
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
/* Function:
    void CAN0_Initialize(void)

   Summary:
    Initializes given instance of the CAN peripheral.

   Precondition:
    None.

   Parameters:
    None.

   Returns:
    None
*/
void CAN0_Initialize(void)
{
    /* Start CAN initialization */
    CAN0_REGS->CAN_CCCR = CAN_CCCR_INIT_Msk;
    while ((CAN0_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) != CAN_CCCR_INIT_Msk)
    {
        /* Wait for initialization complete */
    }

    /* Set CCE to unlock the configuration registers */
    CAN0_REGS->CAN_CCCR |= CAN_CCCR_CCE_Msk;

    /* Set Data Bit Timing and Prescaler Register */
    CAN0_REGS->CAN_DBTP = CAN_DBTP_DTSEG2(4UL) | CAN_DBTP_DTSEG1(13UL) | CAN_DBTP_DBRP(0UL) | CAN_DBTP_DSJW(4UL);

    /* Set Nominal Bit timing and Prescaler Register */
    CAN0_REGS->CAN_NBTP  = CAN_NBTP_NTSEG2(4UL) | CAN_NBTP_NTSEG1(13UL) | CAN_NBTP_NBRP(5UL) | CAN_NBTP_NSJW(4UL);

    /* Receive Buffer / FIFO Element Size Configuration Register */
    CAN0_REGS->CAN_RXESC = 0UL  | CAN_RXESC_F0DS(0UL);
    /* Transmit Buffer/FIFO Element Size Configuration Register */
    CAN0_REGS->CAN_TXESC = CAN_TXESC_TBDS(7UL);

    /* Global Filter Configuration Register */
    CAN0_REGS->CAN_GFC = CAN_GFC_ANFS_RXF0 | CAN_GFC_ANFE_REJECT;

    /* Set the operation mode */
    CAN0_REGS->CAN_CCCR |= CAN_CCCR_FDOE_Msk | CAN_CCCR_BRSE_Msk;


    CAN0_REGS->CAN_CCCR &= ~CAN_CCCR_INIT_Msk;
    while ((CAN0_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) == CAN_CCCR_INIT_Msk)
    {
        /* Wait for initialization complete */
    }

   (void) memset(&can0Obj.msgRAMConfig, 0x00, sizeof(CAN_MSG_RAM_CONFIG));
}


// *****************************************************************************
/* Function:
    bool CAN0_MessageTransmitFifo(uint8_t numberOfMessage, CAN_TX_BUFFER *txBuffer)

   Summary:
    Transmit multiple messages into CAN bus from Tx FIFO.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    numberOfMessage - Total number of message.
    txBuffer        - Pointer to Tx buffer

   Returns:
    Request status.
    true  - Request was successful.
    false - Request has failed.
*/
bool CAN0_MessageTransmitFifo(uint8_t numberOfMessage, CAN_TX_BUFFER *txBuffer)
{
    uint8_t  *txFifo = NULL;
    uint8_t  *txBuf = (uint8_t *)txBuffer;
    uint32_t bufferNumber = 0U;
    uint8_t  tfqpi = 0U;
    uint8_t  count = 0U;
    bool transmitFifo_event = false;

    if (!(((numberOfMessage < 1U) || (numberOfMessage > 1U)) || (txBuffer == NULL)))
    {

        tfqpi = (uint8_t)((CAN0_REGS->CAN_TXFQS & CAN_TXFQS_TFQPI_Msk) >> CAN_TXFQS_TFQPI_Pos);

        for (count = 0U; count < numberOfMessage; count++)
        {
            txFifo = (uint8_t *)((uint8_t*)can0Obj.msgRAMConfig.txBuffersAddress + ((uint32_t)tfqpi * CAN0_TX_FIFO_BUFFER_ELEMENT_SIZE));

            (void) memcpy(txFifo, txBuf, CAN0_TX_FIFO_BUFFER_ELEMENT_SIZE);

            txBuf += CAN0_TX_FIFO_BUFFER_ELEMENT_SIZE;
            bufferNumber |= (1UL << tfqpi);
            tfqpi++;
            if (tfqpi == 1U)
            {
                tfqpi = 0U;
            }
        }

        __DSB();

        /* Set Transmission request */
        CAN0_REGS->CAN_TXBAR = bufferNumber;

        transmitFifo_event = true;
    }
    return transmitFifo_event;
}

// *****************************************************************************
/* Function:
    uint8_t CAN0_TxFifoFreeLevelGet(void)

   Summary:
    Returns Tx FIFO Free Level.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    None.

   Returns:
    Tx FIFO Free Level.
*/
uint8_t CAN0_TxFifoFreeLevelGet(void)
{
    return (uint8_t)(CAN0_REGS->CAN_TXFQS & CAN_TXFQS_TFFL_Msk);
}

// *****************************************************************************
/* Function:
    bool CAN0_TxBufferIsBusy(uint8_t bufferNumber)

   Summary:
    Check if Transmission request is pending for the specific Tx buffer.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    None.

   Returns:
    true  - Transmission request is pending.
    false - Transmission request is not pending.
*/
bool CAN0_TxBufferIsBusy(uint8_t bufferNumber)
{
    return ((CAN0_REGS->CAN_TXBRP & (1UL << bufferNumber)) != 0U);
}

// *****************************************************************************
/* Function:
    bool CAN0_TxEventFifoRead(uint8_t numberOfTxEvent, CAN_TX_EVENT_FIFO *txEventFifo)

   Summary:
    Read Tx Event FIFO for the transmitted messages.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    numberOfTxEvent - Total number of Tx Event
    txEventFifo     - Pointer to Tx Event FIFO

   Returns:
    Request status.
    true  - Request was successful.
    false - Request has failed.
*/
bool CAN0_TxEventFifoRead(uint8_t numberOfTxEvent, CAN_TX_EVENT_FIFO *txEventFifo)
{
    uint8_t txefgi     = 0U;
    uint8_t count      = 0U;
    uint8_t *txEvent   = NULL;
    uint8_t *txEvtFifo = (uint8_t *)txEventFifo;
    bool txFifo_event = false;

    if (txEventFifo != NULL)
    {
        /* Read data from the Rx FIFO0 */
        txefgi = (uint8_t)((CAN0_REGS->CAN_TXEFS & CAN_TXEFS_EFGI_Msk) >> CAN_TXEFS_EFGI_Pos);
        for (count = 0U; count < numberOfTxEvent; count++)
        {
            txEvent = (uint8_t *) ((uint8_t *)can0Obj.msgRAMConfig.txEventFIFOAddress + ((uint32_t)txefgi * sizeof(CAN_TX_EVENT_FIFO)));

            (void) memcpy(txEvtFifo, txEvent, sizeof(CAN_TX_EVENT_FIFO));

            if ((count + 1U) == numberOfTxEvent)
            {
                break;
            }
            txEvtFifo += sizeof(CAN_TX_EVENT_FIFO);
            txefgi++;
            if (txefgi == 1U)
            {
                txefgi = 0U;
            }
        }

        /* Ack the Tx Event FIFO position */
        CAN0_REGS->CAN_TXEFA = CAN_TXEFA_EFAI((uint32_t)txefgi);

        txFifo_event = true;
    }
    return txFifo_event;
}

// *****************************************************************************
/* Function:
    uint8_t CAN0_TxEventFifoFillLevelGet(void)

   Summary:
    Returns Tx Event FIFO Fill Level.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    None.

   Returns:
    Tx Event FIFO Fill Level.
*/
uint8_t CAN0_TxEventFifoFillLevelGet(void)
{
    return (uint8_t)(CAN0_REGS->CAN_TXEFS & CAN_TXEFS_EFFL_Msk);
}


// *****************************************************************************
/* Function:
    bool CAN0_MessageReceiveFifo(CAN_RX_FIFO_NUM rxFifoNum, uint8_t numberOfMessage, CAN_RX_BUFFER *rxBuffer)

   Summary:
    Read messages from Rx FIFO0/FIFO1.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    rxFifoNum       - Rx FIFO number
    numberOfMessage - Total number of message
    rxBuffer        - Pointer to Rx buffer

   Returns:
    Request status.
    true  - Request was successful.
    false - Request has failed.
*/
bool CAN0_MessageReceiveFifo(CAN_RX_FIFO_NUM rxFifoNum, uint8_t numberOfMessage, CAN_RX_BUFFER *rxBuffer)
{
    uint8_t rxgi = 0U;
    uint8_t count = 0U;
    uint8_t *rxFifo = NULL;
    uint8_t *rxBuf = (uint8_t *)rxBuffer;
    bool status = false;

    if (rxBuffer != NULL)
    {
        switch (rxFifoNum)
        {
            case CAN_RX_FIFO_0:
                /* Read data from the Rx FIFO0 */
                rxgi = (uint8_t)((CAN0_REGS->CAN_RXF0S & CAN_RXF0S_F0GI_Msk) >> CAN_RXF0S_F0GI_Pos);
                for (count = 0U; count < numberOfMessage; count++)
                {
                    rxFifo = (uint8_t *) ((uint8_t *)can0Obj.msgRAMConfig.rxFIFO0Address + ((uint32_t)rxgi * CAN0_RX_FIFO0_ELEMENT_SIZE));

                    (void) memcpy(rxBuf, rxFifo, CAN0_RX_FIFO0_ELEMENT_SIZE);

                    if ((count + 1U) == numberOfMessage)
                    {
                        break;
                    }
                    rxBuf += CAN0_RX_FIFO0_ELEMENT_SIZE;
                    rxgi++;
                    if (rxgi == 1U)
                    {
                        rxgi = 0U;
                    }
                }

                /* Ack the fifo position */
                CAN0_REGS->CAN_RXF0A = CAN_RXF0A_F0AI((uint32_t)rxgi);

                status = true;
                break;
            default:
                /* Do nothing */
                break;
        }
    }
    return status;
}

// *****************************************************************************
/* Function:
    uint8_t CAN0_RxFifoFillLevelGet(CAN_RX_FIFO_NUM rxFifoNum)

   Summary:
    Returns Rx FIFO0/FIFO1 Fill Level.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    None.

   Returns:
    Rx FIFO0/FIFO1 Fill Level.
*/
uint8_t CAN0_RxFifoFillLevelGet(CAN_RX_FIFO_NUM rxFifoNum)
{
    uint8_t fillLevel = 0U;

    if (rxFifoNum == CAN_RX_FIFO_0)
    {
        fillLevel = (uint8_t)(CAN0_REGS->CAN_RXF0S & CAN_RXF0S_F0FL_Msk);
    }
    else
    {
        fillLevel = (uint8_t)(CAN0_REGS->CAN_RXF1S & CAN_RXF1S_F1FL_Msk);
    }
    return fillLevel;
}

// *****************************************************************************
/* Function:
    CAN_ERROR CAN0_ErrorGet(void)

   Summary:
    Returns the error during transfer.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    None.

   Returns:
    Error during transfer.
*/
CAN_ERROR CAN0_ErrorGet(void)
{
    CAN_ERROR error;
    uint32_t   errorStatus = CAN0_REGS->CAN_PSR;

    error = (CAN_ERROR) ((errorStatus & CAN_PSR_LEC_Msk) | (errorStatus & CAN_PSR_EP_Msk) | (errorStatus & CAN_PSR_EW_Msk)
            | (errorStatus & CAN_PSR_BO_Msk) | (errorStatus & CAN_PSR_DLEC_Msk) | (errorStatus & CAN_PSR_PXE_Msk));

    if ((CAN0_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) == CAN_CCCR_INIT_Msk)
    {
        CAN0_REGS->CAN_CCCR &= ~CAN_CCCR_INIT_Msk;
        while ((CAN0_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) == CAN_CCCR_INIT_Msk)
        {
            /* Wait for initialization complete */
        }
    }

    return error;
}

// *****************************************************************************
/* Function:
    void CAN0_ErrorCountGet(uint8_t *txErrorCount, uint8_t *rxErrorCount)

   Summary:
    Returns the transmit and receive error count during transfer.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    txErrorCount - Transmit Error Count to be received
    rxErrorCount - Receive Error Count to be received

   Returns:
    None.
*/
void CAN0_ErrorCountGet(uint8_t *txErrorCount, uint8_t *rxErrorCount)
{
    *txErrorCount = (uint8_t)(CAN0_REGS->CAN_ECR & CAN_ECR_TEC_Msk);
    *rxErrorCount = (uint8_t)((CAN0_REGS->CAN_ECR & CAN_ECR_REC_Msk) >> CAN_ECR_REC_Pos);
}

// *****************************************************************************
/* Function:
    bool CAN0_InterruptGet(CAN_INTERRUPT_MASK interruptMask)

   Summary:
    Returns the Interrupt status.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    interruptMask - Interrupt source number

   Returns:
    true - Requested interrupt is occurred.
    false - Requested interrupt is not occurred.
*/
bool CAN0_InterruptGet(CAN_INTERRUPT_MASK interruptMask)
{
    return ((CAN0_REGS->CAN_IR & (uint32_t)interruptMask) != 0x0U);
}

// *****************************************************************************
/* Function:
    void CAN0_InterruptClear(CAN_INTERRUPT_MASK interruptMask)

   Summary:
    Clears Interrupt status.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    interruptMask - Interrupt to be cleared

   Returns:
    None
*/
void CAN0_InterruptClear(CAN_INTERRUPT_MASK interruptMask)
{
    CAN0_REGS->CAN_IR = (uint32_t)interruptMask;
}

// *****************************************************************************
/* Function:
    void CAN0_MessageRAMConfigSet(uint8_t *msgRAMConfigBaseAddress)

   Summary:
    Set the Message RAM Configuration.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    msgRAMConfigBaseAddress - Pointer to application allocated buffer base address.
                              Application must allocate buffer from non-cached
                              contiguous memory and buffer size must be
                              CAN0_MESSAGE_RAM_CONFIG_SIZE

   Returns:
    None
*/
/* MISRA C-2012 Rule 11.3 violated 3 times below. Deviation record ID - H3_MISRAC_2012_R_11_3_DR_1*/
void CAN0_MessageRAMConfigSet(uint8_t *msgRAMConfigBaseAddress)
{
    uint32_t offset = 0U;
    uint32_t msgRAMConfigBaseAddr = (uint32_t)msgRAMConfigBaseAddress;

    (void) memset(msgRAMConfigBaseAddress, 0x00, CAN0_MESSAGE_RAM_CONFIG_SIZE);

    /* Set CAN CCCR Init for Message RAM Configuration */
    CAN0_REGS->CAN_CCCR |= CAN_CCCR_INIT_Msk;
    while ((CAN0_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) != CAN_CCCR_INIT_Msk)
    {
        /* Wait for initialization complete */
    }

    /* Set CCE to unlock the configuration registers */
    CAN0_REGS->CAN_CCCR |= CAN_CCCR_CCE_Msk;

    can0Obj.msgRAMConfig.rxFIFO0Address = (can_rxf0e_registers_t *)msgRAMConfigBaseAddr;
    offset = CAN0_RX_FIFO0_SIZE;
    /* Receive FIFO 0 Configuration Register */
    CAN0_REGS->CAN_RXF0C = CAN_RXF0C_F0S(1UL) | CAN_RXF0C_F0WM(0UL) | CAN_RXF0C_F0OM_Msk |
            CAN_RXF0C_F0SA((uint32_t)can0Obj.msgRAMConfig.rxFIFO0Address);

    can0Obj.msgRAMConfig.txBuffersAddress = (can_txbe_registers_t *)(msgRAMConfigBaseAddr + offset);
    offset += CAN0_TX_FIFO_BUFFER_SIZE;
    /* Transmit Buffer/FIFO Configuration Register */
    CAN0_REGS->CAN_TXBC = CAN_TXBC_TFQS(1UL) |
            CAN_TXBC_TBSA((uint32_t)can0Obj.msgRAMConfig.txBuffersAddress);

    can0Obj.msgRAMConfig.txEventFIFOAddress =  (can_txefe_registers_t *)(msgRAMConfigBaseAddr + offset);
    offset += CAN0_TX_EVENT_FIFO_SIZE;
    /* Transmit Event FIFO Configuration Register */
    CAN0_REGS->CAN_TXEFC = CAN_TXEFC_EFWM(0UL) | CAN_TXEFC_EFS(1UL) |
            CAN_TXEFC_EFSA((uint32_t)can0Obj.msgRAMConfig.txEventFIFOAddress);


    /* Reference offset variable once to remove warning about the variable not being used after increment */
    (void)offset;

    /* Complete Message RAM Configuration by clearing CAN CCCR Init */
    CAN0_REGS->CAN_CCCR &= ~CAN_CCCR_INIT_Msk;
    while ((CAN0_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) == CAN_CCCR_INIT_Msk)
    {
        /* Wait for configuration complete */
    }
}
/* MISRAC 2012 deviation block end for 11.3 */




void CAN0_SleepModeEnter(void)
{
    CAN0_REGS->CAN_CCCR |=  CAN_CCCR_CSR_Msk;
    while ((CAN0_REGS->CAN_CCCR & CAN_CCCR_CSA_Msk) != CAN_CCCR_CSA_Msk)
    {
        /* Wait for clock stop request to complete */
    }
}

void CAN0_SleepModeExit(void)
{
    CAN0_REGS->CAN_CCCR &=  ~CAN_CCCR_CSR_Msk;
    while ((CAN0_REGS->CAN_CCCR & CAN_CCCR_CSA_Msk) == CAN_CCCR_CSA_Msk)
    {
        /* Wait for no clock stop */
    }
    CAN0_REGS->CAN_CCCR &= ~CAN_CCCR_INIT_Msk;
    while ((CAN0_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) == CAN_CCCR_INIT_Msk)
    {
        /* Wait for initialization complete */
    }
}

bool CAN0_BitTimingCalculationGet(CAN_BIT_TIMING_SETUP *setup, CAN_BIT_TIMING *bitTiming)
{
    bool status = false;
    uint32_t numOfTimeQuanta;
    uint8_t tseg1;
    float temp1;
    float temp2;

    if ((setup != NULL) && (bitTiming != NULL))
    {
        if (setup->nominalBitTimingSet == true)
        {
            numOfTimeQuanta = CAN0_CLOCK_FREQUENCY / (setup->nominalBitRate * ((uint32_t)setup->nominalPrescaler + 1U));
            if ((numOfTimeQuanta >= 4U) && (numOfTimeQuanta <= 385U))
            {
                if (setup->nominalSamplePoint < 50.0f)
                {
                    setup->nominalSamplePoint = 50.0f;
                }
                temp1 = (float)numOfTimeQuanta;
                temp2 = (temp1 * setup->nominalSamplePoint) / 100.0f;
                tseg1 = (uint8_t)temp2;
                bitTiming->nominalBitTiming.nominalTimeSegment2 = (uint8_t)(numOfTimeQuanta - tseg1 - 1U);
                bitTiming->nominalBitTiming.nominalTimeSegment1 = tseg1 - 2U;
                bitTiming->nominalBitTiming.nominalSJW = bitTiming->nominalBitTiming.nominalTimeSegment2;
                bitTiming->nominalBitTiming.nominalPrescaler = setup->nominalPrescaler;
                bitTiming->nominalBitTimingSet = true;
                status = true;
            }
            else
            {
                bitTiming->nominalBitTimingSet = false;
            }
        }
        if (setup->dataBitTimingSet == true)
        {
            numOfTimeQuanta = CAN0_CLOCK_FREQUENCY / (setup->dataBitRate * ((uint32_t)setup->dataPrescaler + 1U));
            if ((numOfTimeQuanta >= 4U) && (numOfTimeQuanta <= 49U))
            {
                if (setup->dataSamplePoint < 50.0f)
                {
                    setup->dataSamplePoint = 50.0f;
                }
                temp1 = (float)numOfTimeQuanta;
                temp2 = (temp1 * setup->dataSamplePoint) / 100.0f;
                tseg1 = (uint8_t)temp2;
                bitTiming->dataBitTiming.dataTimeSegment2 = (uint8_t)(numOfTimeQuanta - tseg1 - 1U);
                bitTiming->dataBitTiming.dataTimeSegment1 = tseg1 - 2U;
                bitTiming->dataBitTiming.dataSJW = bitTiming->dataBitTiming.dataTimeSegment2;
                bitTiming->dataBitTiming.dataPrescaler = setup->dataPrescaler;
                bitTiming->dataBitTimingSet = true;
                status = true;
            }
            else
            {
                bitTiming->dataBitTimingSet = false;
                status = false;
            }
        }
    }

    return status;
}

bool CAN0_BitTimingSet(CAN_BIT_TIMING *bitTiming)
{
    bool status = false;
    bool nominalBitTimingSet = false;
    bool dataBitTimingSet = false;

    if ((bitTiming->nominalBitTimingSet == true)
    && (bitTiming->nominalBitTiming.nominalTimeSegment1 >= 0x1U)
    && (bitTiming->nominalBitTiming.nominalTimeSegment2 <= 0x7FU)
    && (bitTiming->nominalBitTiming.nominalPrescaler <= 0x1FFU)
    && (bitTiming->nominalBitTiming.nominalSJW <= 0x7FU))
    {
        nominalBitTimingSet = true;
    }

    if  ((bitTiming->dataBitTimingSet == true)
    &&  ((bitTiming->dataBitTiming.dataTimeSegment1 >= 0x1U) && (bitTiming->dataBitTiming.dataTimeSegment1 <= 0x1FU))
    &&  (bitTiming->dataBitTiming.dataTimeSegment2 <= 0xFU)
    &&  (bitTiming->dataBitTiming.dataPrescaler <= 0x1FU)
    &&  (bitTiming->dataBitTiming.dataSJW <= 0xFU))
    {
        dataBitTimingSet = true;
    }

    if ((nominalBitTimingSet == true) || (dataBitTimingSet == true))
    {
        /* Start CAN initialization */
        CAN0_REGS->CAN_CCCR = CAN_CCCR_INIT_Msk;
        while ((CAN0_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) != CAN_CCCR_INIT_Msk)
        {
            /* Wait for initialization complete */
        }

        /* Set CCE to unlock the configuration registers */
        CAN0_REGS->CAN_CCCR |= CAN_CCCR_CCE_Msk;

        if (dataBitTimingSet == true)
        {
            /* Set Data Bit Timing and Prescaler Register */
            CAN0_REGS->CAN_DBTP = CAN_DBTP_DTSEG2(bitTiming->dataBitTiming.dataTimeSegment2) | CAN_DBTP_DTSEG1(bitTiming->dataBitTiming.dataTimeSegment1) | CAN_DBTP_DBRP(bitTiming->dataBitTiming.dataPrescaler) | CAN_DBTP_DSJW(bitTiming->dataBitTiming.dataSJW);
        }

        if (nominalBitTimingSet == true)
        {
            /* Set Nominal Bit timing and Prescaler Register */
            CAN0_REGS->CAN_NBTP  = CAN_NBTP_NTSEG2(bitTiming->nominalBitTiming.nominalTimeSegment2) | CAN_NBTP_NTSEG1(bitTiming->nominalBitTiming.nominalTimeSegment1) | CAN_NBTP_NBRP(bitTiming->nominalBitTiming.nominalPrescaler) | CAN_NBTP_NSJW(bitTiming->nominalBitTiming.nominalSJW);
        }

        /* Set the operation mode */
        CAN0_REGS->CAN_CCCR |= CAN_CCCR_FDOE_Msk | CAN_CCCR_BRSE_Msk;


        CAN0_REGS->CAN_CCCR &= ~CAN_CCCR_INIT_Msk;
        while ((CAN0_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) == CAN_CCCR_INIT_Msk)
        {
            /* Wait for initialization complete */
        }
        status = true;
    }
    return status;
}

/*******************************************************************************
 End of File
*/
