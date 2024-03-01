/*******************************************************************************
  Application File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the "application" function for a project.

  Description:
    This file contains functions for the Secure CAN Host application.
 *******************************************************************************/

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

#include "app.h"
#include "image_pattern_hex_pic32cx_sg61_cultra.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************
APP_DATA    appData;

static uint32_t status = 0;
static uint8_t loop_count = 0;

uint32_t nTxBytes;
CAN_TX_BUFFER *txBuffer = NULL;
static uint8_t txFiFo[CAN0_TX_FIFO_BUFFER_SIZE];
static uint8_t rxFiFo0[CAN0_RX_FIFO0_SIZE];
static uint8_t CACHE_ALIGN          can1MessageRAM[CAN0_MESSAGE_RAM_CONFIG_SIZE];

uint8_t AesCipherimage[8192];
SECURE_TOKEN secure_token;


plib_spi_api_t sercom2_plib_spi_api = {
    .read = SERCOM2_SPI_Read,
    .write = SERCOM2_SPI_Write,
    .is_busy = SERCOM2_SPI_IsBusy,
    .select = &APP_SPI_SelectPin
};

spi_config hsm_spi;

// *****************************************************************************
// *****************************************************************************
// Section: External functions
// *****************************************************************************
// *****************************************************************************
extern void SECURELIB_Encrypt(uint8_t *image_patern, uint8_t *AesCipherimage, SECURE_TOKEN *secure_token);
extern void SECURELIB_HSM_Init (spi_config *cgf_data);

// *****************************************************************************
// *****************************************************************************
// Section: Local functions
// *****************************************************************************
// *****************************************************************************
/* Message Length to Data length code */
uint8_t APP_CANLengthToDlcGet(uint8_t length)
{
    uint8_t dlc = 0;

    if (length <= 8U)
    {
        dlc = length;
    }
    else if (length <= 12U)
    {
        dlc = 0x9U;
    }
    else if (length <= 16U)
    {
        dlc = 0xAU;
    }
    else if (length <= 20U)
    {
        dlc = 0xBU;
    }
    else if (length <= 24U)
    {
        dlc = 0xCU;
    }
    else if (length <= 32U)
    {
        dlc = 0xDU;
    }
    else if (length <= 48U)
    {
        dlc = 0xEU;
    }
    else
    {
        dlc = 0xFU;
    }
    return dlc;
}


uint8_t APP_CANDlcToLengthGet(uint8_t dlc)
{
    uint8_t msgLength[] = {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 12U, 16U, 20U, 24U, 32U, 48U, 64U};
    return msgLength[dlc];
}

void APP_RX_Message(uint8_t numberOfMessage, CAN_RX_BUFFER *rxBuf, uint8_t rxBufLen)
{
    uint8_t msgLength = 0;
    uint32_t id = 0;

    for (uint8_t count = 0; count < numberOfMessage; count++)
    {
        id = rxBuf->xtd ? rxBuf->id : READ_ID(rxBuf->id);
        msgLength = APP_CANDlcToLengthGet(rxBuf->dlc);
        if ((id == CAN_FILTER_ID) && (msgLength == 1))
        {
            if ((rxBuf->data[0] == BL_RESP_OK) || (rxBuf->data[0] == BL_RESP_CRC_OK))
            {
                appData.trasnferStatus = APP_TRANSFER_STATUS_SUCCESS;
            }
            else
            {
                appData.trasnferStatus = APP_TRANSFER_STATUS_ERROR;
            }
            break;
        }
        rxBuf += rxBufLen;
    }
}

void APP_Initialize(void)
{
    appData.appMemStartAddr = APP_IMAGE_START_ADDR;
    appData.nBytesWritten = 0;
    
    hsm_spi.baud = 100000;
    hsm_spi.select_pin = PORT_PIN_PB29;
    hsm_spi.cfg_data = &sercom2_plib_spi_api;
    
    SECURELIB_HSM_Init(&hsm_spi);
    
    /* Set CAN0 Message RAM Configuration */
    CAN0_MessageRAMConfigSet(can1MessageRAM);
    
    appData.state = APP_STATE_INIT;
    LED_OFF();   
}

uint32_t APP_TokenDataWrite(uint32_t memAddr, uint32_t nBytes)
{
        uint32_t k;
    uint32_t nTxBytes = 0;
    uint32_t wrIndex = (memAddr - SECURE_TOKEN_ADDR);
    static uint8_t sequence = 0;
    
    uint8_t *arr_ptr = (uint8_t *) &secure_token;

    appData.wrBuffer[nTxBytes++] = APP_BL_COMMAND_VERIFY;
    appData.wrBuffer[nTxBytes++] = sequence++;
    appData.wrBuffer[nTxBytes++] = 0xE2;
    appData.wrBuffer[nTxBytes++] = nBytes & 0xFF;

    for (k = 0; k < nBytes; k++, nTxBytes++)
    {
        appData.wrBuffer[nTxBytes] = arr_ptr[wrIndex + k] ;
    }

    return nTxBytes;
}


uint32_t APP_ImageDataWrite(uint32_t memAddr, uint32_t nBytes)
{
    uint32_t k;
    uint32_t nTxBytes = 0;
    uint32_t wrIndex = (memAddr - APP_IMAGE_START_ADDR);
    static uint8_t sequence = 0;

    appData.wrBuffer[nTxBytes++] = APP_BL_COMMAND_DATA;
    appData.wrBuffer[nTxBytes++] = sequence++;
    appData.wrBuffer[nTxBytes++] = 0xE2;
    appData.wrBuffer[nTxBytes++] = nBytes & 0xFF;

    for (k = 0; k < nBytes; k++, nTxBytes++)
    {
        appData.wrBuffer[nTxBytes] = AesCipherimage[wrIndex + k];//image_pattern[wrIndex + k];
    }

    return nTxBytes;
}

uint32_t APP_UnlockCommandSend(uint32_t appStartAddr, uint32_t appSize)
{
    uint32_t nTxBytes = 0;

    appData.wrBuffer[nTxBytes++] = APP_BL_COMMAND_UNLOCK;
    appData.wrBuffer[nTxBytes++] = 0;
    appData.wrBuffer[nTxBytes++] = 0xE2;
    appData.wrBuffer[nTxBytes++] = 8;
    appData.wrBuffer[nTxBytes++] = appStartAddr;
    appData.wrBuffer[nTxBytes++] = (appStartAddr >> 8);
    appData.wrBuffer[nTxBytes++] = (appStartAddr >> 16);
    appData.wrBuffer[nTxBytes++] = (appStartAddr >> 24);
    appData.wrBuffer[nTxBytes++] = appSize;
    appData.wrBuffer[nTxBytes++] = (appSize >> 8);
    appData.wrBuffer[nTxBytes++] = (appSize >> 16);
    appData.wrBuffer[nTxBytes++] = (appSize >> 24);

    return nTxBytes;
}


uint32_t APP_ResetCommandSend(void)
{
    uint32_t nTxBytes = 0;

    appData.wrBuffer[nTxBytes++] = APP_BL_COMMAND_RESET;
    appData.wrBuffer[nTxBytes++] = 0;
    appData.wrBuffer[nTxBytes++] = 0xE2;
    appData.wrBuffer[nTxBytes++] = 0;

    return nTxBytes;
}

void APP_CheckBTLResponse(void)
{
    uint8_t numberOfMessage = 0;

    if (CAN0_InterruptGet(CAN_INTERRUPT_RF0N_MASK))
    {
        CAN0_InterruptClear(CAN_INTERRUPT_RF0N_MASK);

        /* Check CAN0 Status */
        status = CAN0_ErrorGet();
        if (((status & CAN_PSR_LEC_Msk) == CAN_ERROR_NONE) || ((status & CAN_PSR_LEC_Msk) == CAN_ERROR_LEC_NC))
        {
            numberOfMessage = CAN0_RxFifoFillLevelGet(CAN_RX_FIFO_0);
            if (numberOfMessage != 0)
            {
                memset(rxFiFo0, 0x00, (numberOfMessage * CAN0_RX_FIFO0_ELEMENT_SIZE));
                if (CAN0_MessageReceiveFifo(CAN_RX_FIFO_0, numberOfMessage, (CAN_RX_BUFFER *)rxFiFo0) == true)
                {
                    APP_RX_Message(numberOfMessage, (CAN_RX_BUFFER *)rxFiFo0, CAN0_RX_FIFO0_ELEMENT_SIZE);
                }
            }
        }
    }
}

void APP_SPI_SelectPin(uint32_t pin, bool value)
{
    PORT_PinWrite(pin, value);
}


// *****************************************************************************
// *****************************************************************************
// Section: Application Task
// *****************************************************************************
// *****************************************************************************

void APP_Task()
{
    switch (appData.state)
        {
            case APP_STATE_INIT:
                APP_Initialize();
                printf("\r\nHost Initialized Successfully. \r\nPress SW1 to initiate transfer of encrypted application image ");
                appData.state = APP_STATE_WAIT_SW_PRESS;
                break;

            case APP_STATE_WAIT_SW_PRESS:
                if (SWITCH_GET() == SWITCH_PRESSED)
                {
                    appData.state = APP_STATE_ENCRYPT_IMAGE;
                }
                break;
                
            case APP_STATE_ENCRYPT_IMAGE:
                SECURELIB_Encrypt(&image_pattern[0],&AesCipherimage[0], &secure_token);
                printf("\r\nImage Encrypted and CAN Transfer Initiated");
                appData.state = APP_STATE_SEND_UNLOCK_COMMAND;
                break;

            case APP_STATE_SEND_UNLOCK_COMMAND:
                nTxBytes = APP_UnlockCommandSend(APP_IMAGE_START_ADDR, APP_IMAGE_SIZE);
                appData.trasnferStatus = APP_TRANSFER_STATUS_IN_PROGRESS;

                memset(txFiFo, 0x00, CAN0_TX_FIFO_BUFFER_ELEMENT_SIZE);
                txBuffer = (CAN_TX_BUFFER *)txFiFo;
                txBuffer->id = WRITE_ID(CAN_FILTER_ID);
                txBuffer->dlc = APP_CANLengthToDlcGet(nTxBytes);
                txBuffer->fdf = 1;
                txBuffer->brs = 1;
                for (loop_count = 0; loop_count < nTxBytes; loop_count++){
                    txBuffer->data[loop_count] = appData.wrBuffer[loop_count];
                }                
                if (CAN0_MessageTransmitFifo(1, txBuffer) == true)
                {
                    appData.state = APP_STATE_WAIT_UNLOCK_COMMAND_TRANSFER_COMPLETE;
                }
                else
                {
                    appData.state = APP_STATE_ERROR;
                }
                break;
            case APP_STATE_SEND_DATA_COMMAND:
                appData.nPendingBytes = APP_IMAGE_SIZE - appData.nBytesWritten;
                if (appData.nPendingBytes >= CAN_DATA_FRAME_SIZE)
                {
                    appData.nBytesSent = CAN_DATA_FRAME_SIZE - APP_PROTOCOL_HEADER_MAX_SIZE;
                }
                else if (appData.nPendingBytes >= APP_PROTOCOL_HEADER_MAX_SIZE)
                {
                    appData.nBytesSent = APP_PROTOCOL_HEADER_MAX_SIZE;
                }
                else
                {
                    appData.nBytesSent = appData.nPendingBytes;
                }
                nTxBytes = APP_ImageDataWrite((appData.appMemStartAddr + appData.nBytesWritten), appData.nBytesSent);
                appData.trasnferStatus = APP_TRANSFER_STATUS_IN_PROGRESS;

                memset(txFiFo, 0x00, CAN0_TX_FIFO_BUFFER_ELEMENT_SIZE);
                txBuffer = (CAN_TX_BUFFER *)txFiFo;
                txBuffer->id = WRITE_ID(CAN_FILTER_ID);
                txBuffer->dlc = APP_CANLengthToDlcGet(nTxBytes);
                txBuffer->fdf = 1;
                txBuffer->brs = 1;
                for (loop_count = 0; loop_count < nTxBytes; loop_count++){
                    txBuffer->data[loop_count] = appData.wrBuffer[loop_count];
                }                
                if (CAN0_MessageTransmitFifo(1, txBuffer) == true)
                {
                    appData.state = APP_STATE_WAIT_DATA_COMMAND_TRANSFER_COMPLETE;
                }
                else
                {
                    appData.state = APP_STATE_ERROR;
                }
                break;

            case APP_STATE_SEND_VERIFY_COMMAND:
                
                
                appData.nPendingBytes = SECURE_TOKEN_SIZE - appData.nBytesWritten;
                
                if (appData.nPendingBytes >= CAN_DATA_FRAME_SIZE)
                {
                    appData.nBytesSent = CAN_DATA_FRAME_SIZE - APP_PROTOCOL_HEADER_MAX_SIZE;
                }
                
                else if (appData.nPendingBytes >= APP_PROTOCOL_HEADER_MAX_SIZE)
                {
                    appData.nBytesSent = APP_PROTOCOL_HEADER_MAX_SIZE;
                }
                
                else
                {
                    appData.nBytesSent = appData.nPendingBytes;
                }
                
                nTxBytes = APP_TokenDataWrite((SECURE_TOKEN_ADDR + appData.nBytesWritten), appData.nBytesSent);
                
                appData.trasnferStatus = APP_TRANSFER_STATUS_IN_PROGRESS;

                memset(txFiFo, 0x00, CAN0_TX_FIFO_BUFFER_ELEMENT_SIZE);
                txBuffer = (CAN_TX_BUFFER *)txFiFo;
                txBuffer->id = WRITE_ID(CAN_FILTER_ID);
                txBuffer->dlc = APP_CANLengthToDlcGet(nTxBytes);
                txBuffer->fdf = 1;
                txBuffer->brs = 1;
                
                for (loop_count = 0; loop_count < nTxBytes; loop_count++)
                {
                    txBuffer->data[loop_count] = appData.wrBuffer[loop_count];
                }  
                
                if (CAN0_MessageTransmitFifo(1, txBuffer) == true)
                {
                    appData.state = APP_STATE_WAIT_VERIFY_COMMAND_TRANSFER_COMPLETE;
                }
                
                else
                {
                    appData.state = APP_STATE_ERROR;
                }

                
                
                break;

            case APP_STATE_SEND_RESET_COMMAND:
                nTxBytes = APP_ResetCommandSend();
                appData.trasnferStatus = APP_TRANSFER_STATUS_IN_PROGRESS;

                memset(txFiFo, 0x00, CAN0_TX_FIFO_BUFFER_ELEMENT_SIZE);
                txBuffer = (CAN_TX_BUFFER *)txFiFo;
                txBuffer->id = WRITE_ID(CAN_FILTER_ID);
                txBuffer->dlc = APP_CANLengthToDlcGet(nTxBytes);
                txBuffer->fdf = 1;
                txBuffer->brs = 1;
                for (loop_count = 0; loop_count < nTxBytes; loop_count++){
                    txBuffer->data[loop_count] = appData.wrBuffer[loop_count];
                }                
                if (CAN0_MessageTransmitFifo(1, txBuffer) == true)
                {
                    appData.state = APP_STATE_WAIT_RESET_COMMAND_TRANSFER_COMPLETE;
                }
                else
                {
                    appData.state = APP_STATE_ERROR;
                }
                break;

            case APP_STATE_WAIT_UNLOCK_COMMAND_TRANSFER_COMPLETE:
            case APP_STATE_WAIT_DATA_COMMAND_TRANSFER_COMPLETE:
            case APP_STATE_WAIT_VERIFY_COMMAND_TRANSFER_COMPLETE:
            case APP_STATE_WAIT_RESET_COMMAND_TRANSFER_COMPLETE:
                APP_CheckBTLResponse();
                if (appData.trasnferStatus == APP_TRANSFER_STATUS_SUCCESS)
                {
                    if (appData.state == APP_STATE_WAIT_UNLOCK_COMMAND_TRANSFER_COMPLETE)
                    {
                        appData.state = APP_STATE_SEND_DATA_COMMAND;
                    }
                    else if (appData.state == APP_STATE_WAIT_DATA_COMMAND_TRANSFER_COMPLETE)
                    {
                        appData.nBytesWritten += appData.nBytesSent;
                        if (appData.nBytesWritten < APP_IMAGE_SIZE)
                        {
                            appData.state = APP_STATE_SEND_DATA_COMMAND;
                        }
                        else
                        {
                            printf("\r\nData transfer complete");
                            appData.state = APP_STATE_SEND_VERIFY_COMMAND;
                            appData.nBytesWritten = 0;
                        }
                    }
                    else if(appData.state == APP_STATE_WAIT_VERIFY_COMMAND_TRANSFER_COMPLETE)
                    {
                        
                        appData.nBytesWritten += appData.nBytesSent;
                        
                        if (appData.nBytesWritten < SECURE_TOKEN_SIZE)
                        {
                            appData.state = APP_STATE_SEND_VERIFY_COMMAND;
                        }
                        
                        else
                        {
                            appData.state = APP_STATE_SEND_RESET_COMMAND;
                            appData.nBytesWritten = 0;
                        }                    
                        
                    }
                    else if(appData.state == APP_STATE_WAIT_RESET_COMMAND_TRANSFER_COMPLETE)
                    {
                        appData.state = APP_STATE_SUCCESSFUL;
                    }
                }
                else if (appData.trasnferStatus == APP_TRANSFER_STATUS_ERROR)
                {
                    appData.state = APP_STATE_ERROR;
                }
                break;

            case APP_STATE_SUCCESSFUL:

                LED_ON();
                appData.state = APP_STATE_IDLE;
                break;

            case APP_STATE_ERROR:

                LED_OFF();
                appData.state = APP_STATE_IDLE;
                break;

            case APP_STATE_IDLE:
                break;

            default:
                break;
        }
}