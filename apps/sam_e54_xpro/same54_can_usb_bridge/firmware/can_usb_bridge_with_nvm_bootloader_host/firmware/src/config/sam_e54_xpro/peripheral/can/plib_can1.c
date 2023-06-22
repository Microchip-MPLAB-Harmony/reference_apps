/*******************************************************************************
  Controller Area Network (CAN) Peripheral Library Source File

  Company:
    Microchip Technology Inc.

  File Name:
    plib_can1.c

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
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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
#include "plib_can1.h"

// *****************************************************************************
// *****************************************************************************
// Global Data
// *****************************************************************************
// *****************************************************************************
#define CAN_STD_ID_Msk        0x7FFU

volatile static CAN_TX_FIFO_CALLBACK_OBJ can1TxFifoCallbackObj;
volatile static CAN_TX_EVENT_FIFO_CALLBACK_OBJ can1TxEventFifoCallbackObj;
volatile static CAN_RX_FIFO_CALLBACK_OBJ can1RxFifoCallbackObj[2];
volatile static CAN_CALLBACK_OBJ can1CallbackObj;
volatile static CAN_OBJ can1Obj;

static const can_sidfe_registers_t can1StdFilter[] =
{
    {
        .CAN_SIDFE_0 = CAN_SIDFE_0_SFT(2UL) |
                  CAN_SIDFE_0_SFID1(0x469UL) |
                  CAN_SIDFE_0_SFID2(0x0UL) |
                  CAN_SIDFE_0_SFEC(1UL)
    },
};

static const can_xidfe_registers_t can1ExtFilter[] =
{
    {
        .CAN_XIDFE_0 = CAN_XIDFE_0_EFID1(0x100000a5UL) | CAN_XIDFE_0_EFEC(1UL),
        .CAN_XIDFE_1 = CAN_XIDFE_1_EFID2(0x0UL) | CAN_XIDFE_1_EFT(2UL),
    },
};

static inline void CAN1_ZeroInitialize(volatile void* pData, size_t dataSize)
{
    volatile uint8_t* data = (volatile uint8_t*)pData;
    for (uint32_t index = 0; index < dataSize; index++)
    {
        data[index] = 0U;
    }
}

// *****************************************************************************
// *****************************************************************************
// CAN1 PLib Interface Routines
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
/* Function:
    void CAN1_Initialize(void)

   Summary:
    Initializes given instance of the CAN peripheral.

   Precondition:
    None.

   Parameters:
    None.

   Returns:
    None
*/
void CAN1_Initialize(void)
{
    /* Start CAN initialization */
    CAN1_REGS->CAN_CCCR = CAN_CCCR_INIT_Msk;
    while ((CAN1_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) != CAN_CCCR_INIT_Msk)
    {
        /* Wait for initialization complete */
    }

    /* Set CCE to unlock the configuration registers */
    CAN1_REGS->CAN_CCCR |= CAN_CCCR_CCE_Msk;

    /* Set Data Bit Timing and Prescaler Register */
    CAN1_REGS->CAN_DBTP = CAN_DBTP_DTSEG2(4UL) | CAN_DBTP_DTSEG1(13UL) | CAN_DBTP_DBRP(0UL) | CAN_DBTP_DSJW(6UL);

    /* Set Nominal Bit timing and Prescaler Register */
    CAN1_REGS->CAN_NBTP  = CAN_NBTP_NTSEG2(4UL) | CAN_NBTP_NTSEG1(13UL) | CAN_NBTP_NBRP(5UL) | CAN_NBTP_NSJW(3UL);

    /* Receive Buffer / FIFO Element Size Configuration Register */
    CAN1_REGS->CAN_RXESC = 0UL  | CAN_RXESC_F0DS(7UL);
    /* Transmit Buffer/FIFO Element Size Configuration Register */
    CAN1_REGS->CAN_TXESC = CAN_TXESC_TBDS(7UL);

    /* Global Filter Configuration Register */
    CAN1_REGS->CAN_GFC = CAN_GFC_ANFS_RXF0 | CAN_GFC_ANFE_REJECT;

    /* Extended ID AND Mask Register */
    CAN1_REGS->CAN_XIDAM = CAN_XIDAM_Msk;

    /* Set the operation mode */
    CAN1_REGS->CAN_CCCR |= CAN_CCCR_FDOE_Msk | CAN_CCCR_BRSE_Msk;


    CAN1_REGS->CAN_CCCR &= ~CAN_CCCR_INIT_Msk;
    while ((CAN1_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) == CAN_CCCR_INIT_Msk)
    {
        /* Wait for initialization complete */
    }

    /* Select interrupt line */
    CAN1_REGS->CAN_ILS = 0x0U;

    /* Enable interrupt line */
    CAN1_REGS->CAN_ILE = CAN_ILE_EINT0_Msk;

    /* Enable CAN interrupts */
    CAN1_REGS->CAN_IE = CAN_IE_BOE_Msk | CAN_IE_ARAE_Msk | CAN_IE_PEDE_Msk | CAN_IE_PEAE_Msk | CAN_IE_WDIE_Msk
                                      | CAN_IE_EWE_Msk | CAN_IE_EPE_Msk | CAN_IE_ELOE_Msk | CAN_IE_BEUE_Msk | CAN_IE_BECE_Msk
                                       | CAN_IE_TFEE_Msk
                                       | CAN_IE_TEFNE_Msk | CAN_IE_TEFLE_Msk | CAN_IE_TEFFE_Msk | CAN_IE_TCFE_Msk | CAN_IE_HPME_Msk
                                       | CAN_IE_RF0NE_Msk | CAN_IE_RF0LE_Msk | CAN_IE_RF0FE_Msk
                                      
                                      
                                      | CAN_IE_MRAFE_Msk;

    CAN1_ZeroInitialize(&can1Obj.msgRAMConfig, sizeof(CAN_MSG_RAM_CONFIG));
}


// *****************************************************************************
/* Function:
    bool CAN1_MessageTransmitFifo(uint8_t numberOfMessage, CAN_TX_BUFFER *txBuffer)

   Summary:
    Transmit multiple messages into CAN bus from Tx FIFO.

   Precondition:
    CAN1_Initialize must have been called for the associated CAN instance.

   Parameters:
    numberOfMessage - Total number of message.
    txBuffer        - Pointer to Tx buffer

   Returns:
    Request status.
    true  - Request was successful.
    false - Request has failed.
*/
bool CAN1_MessageTransmitFifo(uint8_t numberOfMessage, CAN_TX_BUFFER *txBuffer)
{
    uint8_t  *txFifo = NULL;
    uint8_t  *txBuf = (uint8_t *)txBuffer;
    uint32_t bufferNumber = 0U;
    uint8_t  tfqpi = 0U;
    uint8_t  count = 0U;
    bool transmitFifo_event = false;

    if (!(((numberOfMessage < 1U) || (numberOfMessage > 1U)) || (txBuffer == NULL)))
    {
        tfqpi = (uint8_t)((CAN1_REGS->CAN_TXFQS & CAN_TXFQS_TFQPI_Msk) >> CAN_TXFQS_TFQPI_Pos);

        for (count = 0U; count < numberOfMessage; count++)
        {
            txFifo = (uint8_t *)((uint8_t*)can1Obj.msgRAMConfig.txBuffersAddress + ((uint32_t)tfqpi * CAN1_TX_FIFO_BUFFER_ELEMENT_SIZE));

            (void) memcpy(txFifo, txBuf, CAN1_TX_FIFO_BUFFER_ELEMENT_SIZE);

            txBuf += CAN1_TX_FIFO_BUFFER_ELEMENT_SIZE;
            bufferNumber |= (1UL << tfqpi);
            tfqpi++;
            if (tfqpi == 1U)
            {
                tfqpi = 0U;
            }
        }

        __DSB();

        /* Set Transmission request */
        CAN1_REGS->CAN_TXBAR = bufferNumber;

        transmitFifo_event = true;
    }
    return transmitFifo_event;
}

// *****************************************************************************
/* Function:
    uint8_t CAN1_TxFifoFreeLevelGet(void)

   Summary:
    Returns Tx FIFO Free Level.

   Precondition:
    CAN1_Initialize must have been called for the associated CAN instance.

   Parameters:
    None.

   Returns:
    Tx FIFO Free Level.
*/
uint8_t CAN1_TxFifoFreeLevelGet(void)
{
    return (uint8_t)(CAN1_REGS->CAN_TXFQS & CAN_TXFQS_TFFL_Msk);
}

// *****************************************************************************
/* Function:
    bool CAN1_TxBufferIsBusy(uint8_t bufferNumber)

   Summary:
    Check if Transmission request is pending for the specific Tx buffer.

   Precondition:
    CAN1_Initialize must have been called for the associated CAN instance.

   Parameters:
    None.

   Returns:
    true  - Transmission request is pending.
    false - Transmission request is not pending.
*/
bool CAN1_TxBufferIsBusy(uint8_t bufferNumber)
{
    return ((CAN1_REGS->CAN_TXBRP & (1UL << bufferNumber)) != 0U);
}

// *****************************************************************************
/* Function:
    bool CAN1_TxEventFifoRead(uint8_t numberOfTxEvent, CAN_TX_EVENT_FIFO *txEventFifo)

   Summary:
    Read Tx Event FIFO for the transmitted messages.

   Precondition:
    CAN1_Initialize must have been called for the associated CAN instance.

   Parameters:
    numberOfTxEvent - Total number of Tx Event
    txEventFifo     - Pointer to Tx Event FIFO

   Returns:
    Request status.
    true  - Request was successful.
    false - Request has failed.
*/
bool CAN1_TxEventFifoRead(uint8_t numberOfTxEvent, CAN_TX_EVENT_FIFO *txEventFifo)
{
    uint8_t txefgi     = 0U;
    uint8_t count      = 0U;
    uint8_t *txEvent   = NULL;
    uint8_t *txEvtFifo = (uint8_t *)txEventFifo;
    bool txFifo_event = false;

    if (txEventFifo != NULL)
    {
        /* Read data from the Rx FIFO0 */
        txefgi = (uint8_t)((CAN1_REGS->CAN_TXEFS & CAN_TXEFS_EFGI_Msk) >> CAN_TXEFS_EFGI_Pos);
        for (count = 0U; count < numberOfTxEvent; count++)
        {
            txEvent = (uint8_t *) ((uint8_t *)can1Obj.msgRAMConfig.txEventFIFOAddress + ((uint32_t)txefgi * sizeof(CAN_TX_EVENT_FIFO)));

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
        CAN1_REGS->CAN_TXEFA = CAN_TXEFA_EFAI((uint32_t)txefgi);

        txFifo_event = true;
    }
    return txFifo_event;
}


// *****************************************************************************
/* Function:
    bool CAN1_MessageReceiveFifo(CAN_RX_FIFO_NUM rxFifoNum, uint8_t numberOfMessage, CAN_RX_BUFFER *rxBuffer)

   Summary:
    Read messages from Rx FIFO0/FIFO1.

   Precondition:
    CAN1_Initialize must have been called for the associated CAN instance.

   Parameters:
    rxFifoNum       - Rx FIFO number
    numberOfMessage - Total number of message
    rxBuffer        - Pointer to Rx buffer

   Returns:
    Request status.
    true  - Request was successful.
    false - Request has failed.
*/
bool CAN1_MessageReceiveFifo(CAN_RX_FIFO_NUM rxFifoNum, uint8_t numberOfMessage, CAN_RX_BUFFER *rxBuffer)
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
                rxgi = (uint8_t)((CAN1_REGS->CAN_RXF0S & CAN_RXF0S_F0GI_Msk) >> CAN_RXF0S_F0GI_Pos);
                for (count = 0U; count < numberOfMessage; count++)
                {
                    rxFifo = (uint8_t *) ((uint8_t *)can1Obj.msgRAMConfig.rxFIFO0Address + ((uint32_t)rxgi * CAN1_RX_FIFO0_ELEMENT_SIZE));

                    (void) memcpy(rxBuf, rxFifo, CAN1_RX_FIFO0_ELEMENT_SIZE);

                    if ((count + 1U) == numberOfMessage)
                    {
                        break;
                    }
                    rxBuf += CAN1_RX_FIFO0_ELEMENT_SIZE;
                    rxgi++;
                    if (rxgi == 1U)
                    {
                        rxgi = 0U;
                    }
                }

                /* Ack the fifo position */
                CAN1_REGS->CAN_RXF0A = CAN_RXF0A_F0AI((uint32_t)rxgi);

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
    CAN_ERROR CAN1_ErrorGet(void)

   Summary:
    Returns the error during transfer.

   Precondition:
    CAN1_Initialize must have been called for the associated CAN instance.

   Parameters:
    None.

   Returns:
    Error during transfer.
*/
CAN_ERROR CAN1_ErrorGet(void)
{
    CAN_ERROR error;
    uint32_t   errorStatus = CAN1_REGS->CAN_PSR;

    error = (CAN_ERROR) ((errorStatus & CAN_PSR_LEC_Msk) | (errorStatus & CAN_PSR_EP_Msk) | (errorStatus & CAN_PSR_EW_Msk)
            | (errorStatus & CAN_PSR_BO_Msk) | (errorStatus & CAN_PSR_DLEC_Msk) | (errorStatus & CAN_PSR_PXE_Msk));

    if ((CAN1_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) == CAN_CCCR_INIT_Msk)
    {
        CAN1_REGS->CAN_CCCR &= ~CAN_CCCR_INIT_Msk;
        while ((CAN1_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) == CAN_CCCR_INIT_Msk)
        {
            /* Wait for initialization complete */
        }
    }

    return error;
}

// *****************************************************************************
/* Function:
    void CAN1_ErrorCountGet(uint8_t *txErrorCount, uint8_t *rxErrorCount)

   Summary:
    Returns the transmit and receive error count during transfer.

   Precondition:
    CAN1_Initialize must have been called for the associated CAN instance.

   Parameters:
    txErrorCount - Transmit Error Count to be received
    rxErrorCount - Receive Error Count to be received

   Returns:
    None.
*/
void CAN1_ErrorCountGet(uint8_t *txErrorCount, uint8_t *rxErrorCount)
{
    *txErrorCount = (uint8_t)(CAN1_REGS->CAN_ECR & CAN_ECR_TEC_Msk);
    *rxErrorCount = (uint8_t)((CAN1_REGS->CAN_ECR & CAN_ECR_REC_Msk) >> CAN_ECR_REC_Pos);
}

// *****************************************************************************
/* Function:
    void CAN1_MessageRAMConfigSet(uint8_t *msgRAMConfigBaseAddress)

   Summary:
    Set the Message RAM Configuration.

   Precondition:
    CAN1_Initialize must have been called for the associated CAN instance.

   Parameters:
    msgRAMConfigBaseAddress - Pointer to application allocated buffer base address.
                              Application must allocate buffer from non-cached
                              contiguous memory and buffer size must be
                              CAN1_MESSAGE_RAM_CONFIG_SIZE

   Returns:
    None
*/
/* MISRA C-2012 Rule 11.3 violated 5 times below. Deviation record ID - H3_MISRAC_2012_R_11_3_DR_1*/
void CAN1_MessageRAMConfigSet(uint8_t *msgRAMConfigBaseAddress)
{
    uint32_t offset = 0U;
    uint32_t msgRAMConfigBaseAddr = (uint32_t)msgRAMConfigBaseAddress;

    (void) memset(msgRAMConfigBaseAddress, 0x00, CAN1_MESSAGE_RAM_CONFIG_SIZE);

    /* Set CAN CCCR Init for Message RAM Configuration */
    CAN1_REGS->CAN_CCCR |= CAN_CCCR_INIT_Msk;
    while ((CAN1_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) != CAN_CCCR_INIT_Msk)
    {
        /* Wait for initialization complete */
    }

    /* Set CCE to unlock the configuration registers */
    CAN1_REGS->CAN_CCCR |= CAN_CCCR_CCE_Msk;

    can1Obj.msgRAMConfig.rxFIFO0Address = (can_rxf0e_registers_t *)msgRAMConfigBaseAddr;
    offset = CAN1_RX_FIFO0_SIZE;
    /* Receive FIFO 0 Configuration Register */
    CAN1_REGS->CAN_RXF0C = CAN_RXF0C_F0S(1UL) | CAN_RXF0C_F0WM(0UL) | CAN_RXF0C_F0OM_Msk |
            CAN_RXF0C_F0SA((uint32_t)can1Obj.msgRAMConfig.rxFIFO0Address);

    can1Obj.msgRAMConfig.txBuffersAddress = (can_txbe_registers_t *)(msgRAMConfigBaseAddr + offset);
    offset += CAN1_TX_FIFO_BUFFER_SIZE;
    /* Transmit Buffer/FIFO Configuration Register */
    CAN1_REGS->CAN_TXBC = CAN_TXBC_TFQS(1UL) |
            CAN_TXBC_TBSA((uint32_t)can1Obj.msgRAMConfig.txBuffersAddress);

    can1Obj.msgRAMConfig.txEventFIFOAddress =  (can_txefe_registers_t *)(msgRAMConfigBaseAddr + offset);
    offset += CAN1_TX_EVENT_FIFO_SIZE;
    /* Transmit Event FIFO Configuration Register */
    CAN1_REGS->CAN_TXEFC = CAN_TXEFC_EFWM(0UL) | CAN_TXEFC_EFS(1UL) |
            CAN_TXEFC_EFSA((uint32_t)can1Obj.msgRAMConfig.txEventFIFOAddress);

    can1Obj.msgRAMConfig.stdMsgIDFilterAddress = (can_sidfe_registers_t *)(msgRAMConfigBaseAddr + offset);
    (void) memcpy((void*)can1Obj.msgRAMConfig.stdMsgIDFilterAddress,
           (const void*)can1StdFilter,
           CAN1_STD_MSG_ID_FILTER_SIZE);
    offset += CAN1_STD_MSG_ID_FILTER_SIZE;
    /* Standard ID Filter Configuration Register */
    CAN1_REGS->CAN_SIDFC = CAN_SIDFC_LSS(1UL) |
            CAN_SIDFC_FLSSA((uint32_t)can1Obj.msgRAMConfig.stdMsgIDFilterAddress);

    can1Obj.msgRAMConfig.extMsgIDFilterAddress = (can_xidfe_registers_t *)(msgRAMConfigBaseAddr + offset);
    (void) memcpy((void*)can1Obj.msgRAMConfig.extMsgIDFilterAddress,
           (const void*)can1ExtFilter,
           CAN1_EXT_MSG_ID_FILTER_SIZE);
    /* Extended ID Filter Configuration Register */
    CAN1_REGS->CAN_XIDFC = CAN_XIDFC_LSE(1UL) |
            CAN_XIDFC_FLESA((uint32_t)can1Obj.msgRAMConfig.extMsgIDFilterAddress);

    /* Reference offset variable once to remove warning about the variable not being used after increment */
    (void)offset;

    /* Complete Message RAM Configuration by clearing CAN CCCR Init */
    CAN1_REGS->CAN_CCCR &= ~CAN_CCCR_INIT_Msk;
    while ((CAN1_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) == CAN_CCCR_INIT_Msk)
    {
        /* Wait for configuration complete */
    }
}
/* MISRAC 2012 deviation block end for Rule 11.3*/


// *****************************************************************************
/* Function:
    bool CAN1_StandardFilterElementSet(uint8_t filterNumber, can_sidfe_registers_t *stdMsgIDFilterElement)

   Summary:
    Set a standard filter element configuration.

   Precondition:
    CAN1_Initialize and CAN1_MessageRAMConfigSet must have been called
    for the associated CAN instance.

   Parameters:
    filterNumber          - Standard Filter number to be configured.
    stdMsgIDFilterElement - Pointer to Standard Filter Element configuration to be set on specific filterNumber.

   Returns:
    Request status.
    true  - Request was successful.
    false - Request has failed.
*/
bool CAN1_StandardFilterElementSet(uint8_t filterNumber, can_sidfe_registers_t *stdMsgIDFilterElement)
{
    bool retval = false;
    if (!((filterNumber > 1U) || (stdMsgIDFilterElement == NULL)))
    {
        can1Obj.msgRAMConfig.stdMsgIDFilterAddress[filterNumber - 1U].CAN_SIDFE_0 = stdMsgIDFilterElement->CAN_SIDFE_0;
        retval = true;
    }
    return retval;
}

// *****************************************************************************
/* Function:
    bool CAN1_StandardFilterElementGet(uint8_t filterNumber, can_sidfe_registers_t *stdMsgIDFilterElement)

   Summary:
    Get a standard filter element configuration.

   Precondition:
    CAN1_Initialize and CAN1_MessageRAMConfigSet must have been called
    for the associated CAN instance.

   Parameters:
    filterNumber          - Standard Filter number to get filter configuration.
    stdMsgIDFilterElement - Pointer to Standard Filter Element configuration for storing filter configuration.

   Returns:
    Request status.
    true  - Request was successful.
    false - Request has failed.
*/
bool CAN1_StandardFilterElementGet(uint8_t filterNumber, can_sidfe_registers_t *stdMsgIDFilterElement)
{
    bool retval = false;
    if (!((filterNumber > 1U) || (stdMsgIDFilterElement == NULL)))
    {
        stdMsgIDFilterElement->CAN_SIDFE_0 = can1Obj.msgRAMConfig.stdMsgIDFilterAddress[filterNumber - 1U].CAN_SIDFE_0;
        retval = true;
    }
    return retval;
}

// *****************************************************************************
/* Function:
    bool CAN1_ExtendedFilterElementSet(uint8_t filterNumber, can_xidfe_registers_t *extMsgIDFilterElement)

   Summary:
    Set a Extended filter element configuration.

   Precondition:
    CAN1_Initialize and CAN1_MessageRAMConfigSet must have been called
    for the associated CAN instance.

   Parameters:
    filterNumber          - Extended Filter number to be configured.
    extMsgIDFilterElement - Pointer to Extended Filter Element configuration to be set on specific filterNumber.

   Returns:
    Request status.
    true  - Request was successful.
    false - Request has failed.
*/
bool CAN1_ExtendedFilterElementSet(uint8_t filterNumber, can_xidfe_registers_t *extMsgIDFilterElement)
{
    bool retval = false;
    if (!((filterNumber > 1U) || (extMsgIDFilterElement == NULL)))
    {
        can1Obj.msgRAMConfig.extMsgIDFilterAddress[filterNumber - 1U].CAN_XIDFE_0 = extMsgIDFilterElement->CAN_XIDFE_0;
        can1Obj.msgRAMConfig.extMsgIDFilterAddress[filterNumber - 1U].CAN_XIDFE_1 = extMsgIDFilterElement->CAN_XIDFE_1;
        retval = true;
    }
    return retval;
}

// *****************************************************************************
/* Function:
    bool CAN1_ExtendedFilterElementGet(uint8_t filterNumber, can_xidfe_registers_t *extMsgIDFilterElement)

   Summary:
    Get a Extended filter element configuration.

   Precondition:
    CAN1_Initialize and CAN1_MessageRAMConfigSet must have been called
    for the associated CAN instance.

   Parameters:
    filterNumber          - Extended Filter number to get filter configuration.
    extMsgIDFilterElement - Pointer to Extended Filter Element configuration for storing filter configuration.

   Returns:
    Request status.
    true  - Request was successful.
    false - Request has failed.
*/
bool CAN1_ExtendedFilterElementGet(uint8_t filterNumber, can_xidfe_registers_t *extMsgIDFilterElement)
{
    bool retval = false;
    if (!((filterNumber > 1U) || (extMsgIDFilterElement == NULL)))
    {
        extMsgIDFilterElement->CAN_XIDFE_0 = can1Obj.msgRAMConfig.extMsgIDFilterAddress[filterNumber - 1U].CAN_XIDFE_0;
        extMsgIDFilterElement->CAN_XIDFE_1 = can1Obj.msgRAMConfig.extMsgIDFilterAddress[filterNumber - 1U].CAN_XIDFE_1;
        retval = true;
    }
    return retval;
}

void CAN1_SleepModeEnter(void)
{
    CAN1_REGS->CAN_CCCR |=  CAN_CCCR_CSR_Msk;
    while ((CAN1_REGS->CAN_CCCR & CAN_CCCR_CSA_Msk) != CAN_CCCR_CSA_Msk)
    {
        /* Wait for clock stop request to complete */
    }
}

void CAN1_SleepModeExit(void)
{
    CAN1_REGS->CAN_CCCR &=  ~CAN_CCCR_CSR_Msk;
    while ((CAN1_REGS->CAN_CCCR & CAN_CCCR_CSA_Msk) == CAN_CCCR_CSA_Msk)
    {
        /* Wait for no clock stop */
    }
    CAN1_REGS->CAN_CCCR &= ~CAN_CCCR_INIT_Msk;
    while ((CAN1_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) == CAN_CCCR_INIT_Msk)
    {
        /* Wait for initialization complete */
    }
}

bool CAN1_BitTimingCalculationGet(CAN_BIT_TIMING_SETUP *setup, CAN_BIT_TIMING *bitTiming)
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
            numOfTimeQuanta = CAN1_CLOCK_FREQUENCY / (setup->nominalBitRate * ((uint32_t)setup->nominalPrescaler + 1U));
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
            numOfTimeQuanta = CAN1_CLOCK_FREQUENCY / (setup->dataBitRate * ((uint32_t)setup->dataPrescaler + 1U));
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

bool CAN1_BitTimingSet(CAN_BIT_TIMING *bitTiming)
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
        CAN1_REGS->CAN_CCCR = CAN_CCCR_INIT_Msk;
        while ((CAN1_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) != CAN_CCCR_INIT_Msk)
        {
            /* Wait for initialization complete */
        }

        /* Set CCE to unlock the configuration registers */
        CAN1_REGS->CAN_CCCR |= CAN_CCCR_CCE_Msk;

        if (dataBitTimingSet == true)
        {
            /* Set Data Bit Timing and Prescaler Register */
            CAN1_REGS->CAN_DBTP = CAN_DBTP_DTSEG2(bitTiming->dataBitTiming.dataTimeSegment2) | CAN_DBTP_DTSEG1(bitTiming->dataBitTiming.dataTimeSegment1) | CAN_DBTP_DBRP(bitTiming->dataBitTiming.dataPrescaler) | CAN_DBTP_DSJW(bitTiming->dataBitTiming.dataSJW);
        }
        if (nominalBitTimingSet == true)
        {
            /* Set Nominal Bit timing and Prescaler Register */
            CAN1_REGS->CAN_NBTP  = CAN_NBTP_NTSEG2(bitTiming->nominalBitTiming.nominalTimeSegment2) | CAN_NBTP_NTSEG1(bitTiming->nominalBitTiming.nominalTimeSegment1) | CAN_NBTP_NBRP(bitTiming->nominalBitTiming.nominalPrescaler) | CAN_NBTP_NSJW(bitTiming->nominalBitTiming.nominalSJW);
        }

        /* Set the operation mode */
        CAN1_REGS->CAN_CCCR |= CAN_CCCR_FDOE_Msk | CAN_CCCR_BRSE_Msk;


        CAN1_REGS->CAN_CCCR &= ~CAN_CCCR_INIT_Msk;
        while ((CAN1_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) == CAN_CCCR_INIT_Msk)
        {
            /* Wait for initialization complete */
        }
        status = true;
    }
    return status;
}


// *****************************************************************************
/* Function:
    void CAN1_TxFifoCallbackRegister(CAN_TX_FIFO_CALLBACK callback, uintptr_t contextHandle)

   Summary:
    Sets the pointer to the function (and it's context) to be called when the
    given CAN's transfer events occur.

   Precondition:
    CAN1_Initialize must have been called for the associated CAN instance.

   Parameters:
    callback - A pointer to a function with a calling signature defined
    by the CAN_TX_FIFO_CALLBACK data type.

    contextHandle - A value (usually a pointer) passed (unused) into the function
    identified by the callback parameter.

   Returns:
    None.
*/
void CAN1_TxFifoCallbackRegister(CAN_TX_FIFO_CALLBACK callback, uintptr_t contextHandle)
{
    if (callback != NULL)
    {
        can1TxFifoCallbackObj.callback = callback;
        can1TxFifoCallbackObj.context = contextHandle;
    }
}

// *****************************************************************************
/* Function:
    void CAN1_TxEventFifoCallbackRegister(CAN_TX_EVENT_FIFO_CALLBACK callback, uintptr_t contextHandle)

   Summary:
    Sets the pointer to the function (and it's context) to be called when the
    given CAN's transfer events occur.

   Precondition:
    CAN1_Initialize must have been called for the associated CAN instance.

   Parameters:
    callback - A pointer to a function with a calling signature defined
    by the CAN_TX_EVENT_FIFO_CALLBACK data type.

    contextHandle - A value (usually a pointer) passed (unused) into the function
    identified by the callback parameter.

   Returns:
    None.
*/
void CAN1_TxEventFifoCallbackRegister(CAN_TX_EVENT_FIFO_CALLBACK callback, uintptr_t contextHandle)
{
    if (callback != NULL)
    {
        can1TxEventFifoCallbackObj.callback = callback;
        can1TxEventFifoCallbackObj.context = contextHandle;

    }
}


// *****************************************************************************
/* Function:
    void CAN1_RxFifoCallbackRegister(CAN_RX_FIFO_NUM rxFifoNum, CAN_RX_FIFO_CALLBACK callback, uintptr_t contextHandle)

   Summary:
    Sets the pointer to the function (and it's context) to be called when the
    given CAN's transfer events occur.

   Precondition:
    CAN1_Initialize must have been called for the associated CAN instance.

   Parameters:
    rxFifoNum - Rx FIFO Number

    callback  - A pointer to a function with a calling signature defined
    by the CAN_RX_FIFO_CALLBACK data type.

    contextHandle - A value (usually a pointer) passed (unused) into the function
    identified by the callback parameter.

   Returns:
    None.
*/
void CAN1_RxFifoCallbackRegister(CAN_RX_FIFO_NUM rxFifoNum, CAN_RX_FIFO_CALLBACK callback, uintptr_t contextHandle)
{
    if (callback != NULL)
    {
        can1RxFifoCallbackObj[rxFifoNum].callback = callback;
        can1RxFifoCallbackObj[rxFifoNum].context = contextHandle;
    }
}

// *****************************************************************************
/* Function:
    void CAN1_CallbackRegister(CAN_CALLBACK callback, uintptr_t contextHandle)

   Summary:
    Sets the pointer to the function (and it's context) to be called when the
    given CAN's transfer events occur.

   Precondition:
    CAN1_Initialize must have been called for the associated CAN instance.

   Parameters:
    callback  - A pointer to a function with a calling signature defined
    by the CAN_CALLBACK data type.

    contextHandle - A value (usually a pointer) passed (unused) into the function
    identified by the callback parameter.

   Returns:
    None.
*/
void CAN1_CallbackRegister(CAN_CALLBACK callback, uintptr_t contextHandle)
{
    if (callback != NULL)
    {
        can1CallbackObj.callback = callback;
        can1CallbackObj.context = contextHandle;
    }
}

// *****************************************************************************
/* Function:
    void CAN1_InterruptHandler(void)

   Summary:
    CAN1 Peripheral Interrupt Handler.

   Description:
    This function is CAN1 Peripheral Interrupt Handler and will
    called on every CAN1 interrupt.

   Precondition:
    None.

   Parameters:
    None.

   Returns:
    None.

   Remarks:
    The function is called as peripheral instance's interrupt handler if the
    instance interrupt is enabled. If peripheral instance's interrupt is not
    enabled user need to call it from the main while loop of the application.
*/
void __attribute__((used)) CAN1_InterruptHandler(void)
{
    uint8_t numberOfMessage = 0;
    uint8_t numberOfTxEvent = 0;

    uint32_t ir = CAN1_REGS->CAN_IR;

    /* Additional temporary variable used to prevent MISRA violations (Rule 13.x) */
    uintptr_t context;

    if ((ir & (~(CAN_IR_RF0N_Msk | CAN_IR_TFE_Msk | CAN_IR_TEFN_Msk))) != 0U)
    {
        CAN1_REGS->CAN_IR = (ir & (~(CAN_IR_RF0N_Msk | CAN_IR_TFE_Msk | CAN_IR_TEFN_Msk)));
        if (can1CallbackObj.callback != NULL)
        {
            context = can1CallbackObj.context;
            can1CallbackObj.callback(ir, context);
        }
    }
    /* New Message in Rx FIFO 0 */
    if ((ir & CAN_IR_RF0N_Msk) != 0U)
    {
        CAN1_REGS->CAN_IR = CAN_IR_RF0N_Msk;

        numberOfMessage = (uint8_t)(CAN1_REGS->CAN_RXF0S & CAN_RXF0S_F0FL_Msk);

        if (can1RxFifoCallbackObj[CAN_RX_FIFO_0].callback != NULL)
        {
            context = can1RxFifoCallbackObj[CAN_RX_FIFO_0].context;
            can1RxFifoCallbackObj[CAN_RX_FIFO_0].callback(numberOfMessage, context);
        }
    }

    /* TX FIFO is empty */
    if ((ir & CAN_IR_TFE_Msk) != 0U)
    {
        CAN1_REGS->CAN_IR = CAN_IR_TFE_Msk;
        if (can1TxFifoCallbackObj.callback != NULL)
        {
            context = can1TxFifoCallbackObj.context;
            can1TxFifoCallbackObj.callback(context);
        }
    }
    /* Tx Event FIFO new entry */
    if ((ir & CAN_IR_TEFN_Msk) != 0U)
    {
        CAN1_REGS->CAN_IR = CAN_IR_TEFN_Msk;

        numberOfTxEvent = (uint8_t)(CAN1_REGS->CAN_TXEFS & CAN_TXEFS_EFFL_Msk);

        if (can1TxEventFifoCallbackObj.callback != NULL)
        {
            context = can1TxEventFifoCallbackObj.context;
            can1TxEventFifoCallbackObj.callback(numberOfTxEvent, context);
        }
    }
}

/*******************************************************************************
 End of File
*/
