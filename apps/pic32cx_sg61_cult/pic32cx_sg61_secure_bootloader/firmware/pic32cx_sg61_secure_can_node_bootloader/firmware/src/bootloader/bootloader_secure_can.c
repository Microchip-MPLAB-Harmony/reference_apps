/*******************************************************************************
  CAN Bootloader Source File

  File Name:
    bootloader_can.c

  Summary:
    This file contains source code necessary to execute CAN bootloader.

  Description:
    This file contains source code necessary to execute CAN bootloader.
    It implements bootloader protocol which uses CAN peripheral to download
    application firmware into internal flash from HOST.
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

// *****************************************************************************
// *****************************************************************************
// Section: Include Files
// *****************************************************************************
// *****************************************************************************

#include "definitions.h"
#include <device.h>
#include "bootloader_common.h"
#include "bootloader_secure_can.h"

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

#define ADDR_OFFSET              1
#define SIZE_OFFSET              2
#define CRC_OFFSET               1

#define HEADER_CMD_OFFSET        0
#define HEADER_SEQ_OFFSET        1
#define HEADER_MAGIC_OFFSET      2
#define HEADER_SIZE_OFFSET       3

#define CRC_SIZE                 4
#define HEADER_SIZE              4
#define OFFSET_SIZE              4
#define SIZE_SIZE                4
#define MAX_DATA_SIZE            60


#define HEADER_MAGIC             0xE2
#define CAN_FILTER_ID 0x45A

/* Standard identifier id[28:18]*/
#define WRITE_ID(id)             (id << 18U)
#define READ_ID(id)              (id >> 18U)

#define WORDS(x)                 ((int)((x) / sizeof(uint32_t)))

#define OFFSET_ALIGN_MASK        (~ERASE_BLOCK_SIZE + 1)
#define SIZE_ALIGN_MASK          (~PAGE_SIZE + 1)


#define SIGN_BUF_SIZE               64
#define PUB_KEY_BUF_SIZE            64
#define AES_TAG_SIZE                144 

#define SECURE_TOKEN_SIZE           (SIGN_BUF_SIZE + PUB_KEY_BUF_SIZE + AES_TAG_SIZE)

typedef struct
{
    uint8_t signature[SIGN_BUF_SIZE];
    uint8_t pub_key[PUB_KEY_BUF_SIZE];
    uint8_t Aes_tag[AES_TAG_SIZE];       
}__attribute__((packed)) SECURE_TOKEN;


SECURE_TOKEN secure_token;


#define SECURE_TOKEN_ADDR           ((uint32_t)&secure_token)


enum
{
    BL_CMD_UNLOCK                   = 0xa0,
    BL_CMD_DATA                     = 0xa1,
    BL_CMD_VERIFY_AND_PROGRAM       = 0xa2,
    BL_CMD_RESET                    = 0xa3,
    BL_CMD_READ_VERSION             = 0xa6,
};

enum
{
    BL_RESP_OK          = 0x50,
    BL_RESP_ERROR       = 0x51,
    BL_RESP_INVALID     = 0x52,
    BL_RESP_CRC_OK      = 0x53,
    BL_RESP_CRC_FAIL    = 0x54,
    BL_RESP_SEQ_ERROR   = 0x55
};

// *****************************************************************************
// *****************************************************************************
// Section: Global objects
// *****************************************************************************
// *****************************************************************************

static uint8_t  flash_data[PAGE_SIZE];
static uint32_t flash_addr;
static uint32_t flash_size;
static uint32_t flash_ptr;
static uint32_t image_data_ptr;

__attribute__ ((aligned (32))) uint8_t rcvd_image[8192];
uint8_t Aesapplicationimage[8192];

static uint8_t  token_data[SECURE_TOKEN_SIZE];
static uint32_t token_ptr;

static uint32_t unlock_begin;
static uint32_t unlock_end;

static uint8_t CACHE_ALIGN can0MessageRAM[CAN0_MESSAGE_RAM_CONFIG_SIZE];
static uint8_t rxFiFo0[CAN0_RX_FIFO0_SIZE];
static uint8_t txFiFo[CAN0_TX_FIFO_BUFFER_SIZE];
static uint8_t data_seq;

static bool canBLInitDone      = false;

static bool canBLActive        = false;

volatile bool verified = false;

typedef bool (* spi_plib_read)( void * , size_t );
typedef bool (* spi_plib_write)( void *, size_t );
typedef bool (* spi_plib_is_busy)( void );
typedef void (* spi_plib_select)(uint32_t pin, bool value);

typedef struct plib_spi_api
{
    spi_plib_read              read;
    spi_plib_write             write;
    spi_plib_is_busy           is_busy;
    spi_plib_select            select;
} plib_spi_api_t;

static void APP_SPI_SelectPin(uint32_t pin, bool value)
{
    PORT_PinWrite(pin, value);
}

plib_spi_api_t sercom2_plib_spi_api = {
    .read = SERCOM2_SPI_Read,
    .write = SERCOM2_SPI_Write,
    .is_busy = SERCOM2_SPI_IsBusy,
    .select = &APP_SPI_SelectPin
};

typedef struct
{
    uint8_t  select_pin; 
    uint32_t baud;
    void *   cfg_data;
    
}spi_config;


spi_config hsm_spi;

// *****************************************************************************
// *****************************************************************************
// Section: External functions
// *****************************************************************************
// *****************************************************************************
extern bool SECURELIB_DecryptVerify(uint8_t *image_pattern, uint8_t *Aesapplicationimage, SECURE_TOKEN *secure_token);
extern void SECURELIB_HSM_Init (spi_config *cgf_data);

// *****************************************************************************
// *****************************************************************************
// Section: Bootloader Local Functions
// *****************************************************************************
// *****************************************************************************

/* Data length code to Message Length */
static uint8_t BTL_CANDlcToLengthGet(uint8_t dlc)
{
    uint8_t msgLength[] = {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 12U, 16U, 20U, 24U, 32U, 48U, 64U};
    return msgLength[dlc];
}

/* Function to program received application firmware data into internal flash */
static void BTL_FlashWrite(void)
{
    if (0 == (flash_addr % ERASE_BLOCK_SIZE))
    {
        /* Lock region size is always bigger than the row size */
        NVMCTRL_RegionUnlock(flash_addr);

        while(NVMCTRL_IsBusy() == true);

        /* Erase the Current sector */
        NVMCTRL_BlockErase(flash_addr);

        while(NVMCTRL_IsBusy() == true)
        {
        }
    }

    /* Write Page */
    NVMCTRL_PageWrite((uint32_t *)&flash_data[0], flash_addr);

    while(NVMCTRL_IsBusy() == true)
    {
    }
}

/* Function to process command from the received message */
static void BTL_ProcessCommand(uint8_t *rx_message, uint8_t rx_messageLength)
{
    uint32_t command = rx_message[HEADER_CMD_OFFSET];
    uint32_t size = rx_message[HEADER_SIZE_OFFSET];
    uint32_t *data = (uint32_t *)rx_message;
    CAN_TX_BUFFER *txBuffer = NULL;

    memset(txFiFo, 0U, CAN0_TX_FIFO_BUFFER_ELEMENT_SIZE);
    txBuffer = (CAN_TX_BUFFER *)txFiFo;
    txBuffer->id = WRITE_ID(CAN_FILTER_ID);
    txBuffer->dlc = 1U;
    txBuffer->fdf = 1U;
    txBuffer->brs = 1U;

    if ((rx_messageLength < HEADER_SIZE) || (size > MAX_DATA_SIZE) ||
        (rx_messageLength < (HEADER_SIZE + size)) || (HEADER_MAGIC != rx_message[HEADER_MAGIC_OFFSET]))
    {
        txBuffer->data[0] = BL_RESP_ERROR;
        CAN0_MessageTransmitFifo(1U, txBuffer);
    }
    else if (BL_CMD_UNLOCK == command)
    {
        printf("\r\nReceiving Application Firmware");
        uint32_t begin  = (data[ADDR_OFFSET] & OFFSET_ALIGN_MASK);

        uint32_t end    = begin + (data[SIZE_OFFSET] & SIZE_ALIGN_MASK);

        if (end > begin && end <= (FLASH_START + FLASH_LENGTH) && size == (OFFSET_SIZE + SIZE_SIZE))
        {
            unlock_begin = begin;
            unlock_end = end;
            txBuffer->data[0] = BL_RESP_OK;
            CAN0_MessageTransmitFifo(1U, txBuffer);
        }
        else
        {
            unlock_begin = 0;
            unlock_end = 0;
            txBuffer->data[0] = BL_RESP_ERROR;
            CAN0_MessageTransmitFifo(1U, txBuffer);
        }
        data_seq = 0;
        image_data_ptr = 0;
        flash_addr = unlock_begin;
        flash_size = unlock_end;
    }
    else if (BL_CMD_DATA == command)
    {
        if (rx_message[HEADER_SEQ_OFFSET] != data_seq)
        {
            txBuffer->data[0] = BL_RESP_SEQ_ERROR;
            CAN0_MessageTransmitFifo(1U, txBuffer);
        }
        else
        {
            for (uint8_t i = 0; i < size; i++)
            {
                if (0 == flash_size)
                {
                    txBuffer->data[0] = BL_RESP_ERROR;
                    CAN0_MessageTransmitFifo(1U, txBuffer);
                    return;
                }

                rcvd_image[image_data_ptr++] = rx_message[HEADER_SIZE + i];
            }
            data_seq++;
            txBuffer->data[0] = BL_RESP_OK;
            CAN0_MessageTransmitFifo(1U, txBuffer);
        }
    }
    else if (BL_CMD_READ_VERSION == command)
    {
        uint16_t btlVersion = bootloader_GetVersion();

        txBuffer->data[0] = BL_RESP_OK;

        txBuffer->data[1] = (uint8_t)((btlVersion >> 8) & 0xFF);
        txBuffer->data[2] = (uint8_t)(btlVersion & 0xFF);

        CAN0_MessageTransmitFifo(3U, txBuffer);
    }
    else if (BL_CMD_VERIFY_AND_PROGRAM == command)
    {
            for (uint8_t i = 0; i < size; i++)
            {
                token_data[token_ptr++] = rx_message[HEADER_SIZE + i];
            }

            
            if (token_ptr == SECURE_TOKEN_SIZE)
            {
                printf("\r\nDecrypting and Verifying Application Firmware");
                token_ptr = 0;

                memcpy(&secure_token.signature, &token_data[0], SIGN_BUF_SIZE);
                memcpy(&secure_token.pub_key, &token_data[64], PUB_KEY_BUF_SIZE);
                memcpy(&secure_token.Aes_tag, &token_data[128], AES_TAG_SIZE);
                
                hsm_spi.baud = 100000;
                hsm_spi.select_pin = PORT_PIN_PB29;
                hsm_spi.cfg_data = &sercom2_plib_spi_api;

                SECURELIB_HSM_Init(&hsm_spi);
                
                
                verified = SECURELIB_DecryptVerify(&rcvd_image[0],&Aesapplicationimage[0] , &secure_token);
                        
                if (verified)
                {
                    printf("\r\nVerify successful!!\r\n");
                    for (uint32_t i = 0; i < 8192; i++)
                    {
                        flash_data[flash_ptr] = Aesapplicationimage[i];
                        flash_ptr++;
                        if (flash_ptr == PAGE_SIZE)
                        {
                            BTL_FlashWrite();

                            flash_ptr = 0;
                            flash_addr += PAGE_SIZE;
                            flash_size -= PAGE_SIZE;
                        }
                    }
                }
                
                else{
                    printf("Verify Failed!!\r\n");
                }
            }
            
            txBuffer->data[0] = BL_RESP_OK;
            CAN0_MessageTransmitFifo(1U, txBuffer);
    }
    else if (BL_CMD_RESET == command)
    {
        if (CAN0_InterruptGet(CAN_INTERRUPT_TFE_MASK))
        {
            CAN0_InterruptClear(CAN_INTERRUPT_TFE_MASK);
        }

        txBuffer->data[0] = BL_RESP_OK;
        CAN0_MessageTransmitFifo(1U, txBuffer);
        while (CAN0_InterruptGet(CAN_INTERRUPT_TFE_MASK) == false);

        NVIC_SystemReset();
    }
    else
    {
        txBuffer->data[0] = BL_RESP_INVALID;
        CAN0_MessageTransmitFifo(1U, txBuffer);
    }
}

/* Function to receive application firmware via CAN0 */
static void CAN0_Task(void)
{
    uint32_t                   status = 0U;
    uint8_t                    numberOfMessage = 0U;
    uint8_t                    count = 0U;
    CAN_RX_BUFFER   *rxBuf = NULL;

    if (CAN0_InterruptGet(CAN_INTERRUPT_RF0N_MASK))
    {
        CAN0_InterruptClear(CAN_INTERRUPT_RF0N_MASK);

        /* Check CAN0 Status */
        status = CAN0_ErrorGet();
        if (((status & CAN_PSR_LEC_Msk) == CAN_ERROR_NONE) || ((status & CAN_PSR_LEC_Msk) == CAN_ERROR_LEC_NC))
        {
            numberOfMessage = CAN0_RxFifoFillLevelGet(CAN_RX_FIFO_0);
            if (numberOfMessage != 0U)
            {
                canBLActive = true;

                memset(rxFiFo0, 0U, (numberOfMessage * CAN0_RX_FIFO0_ELEMENT_SIZE));

                if (CAN0_MessageReceiveFifo(CAN_RX_FIFO_0, numberOfMessage, (CAN_RX_BUFFER *)rxFiFo0) == true)
                {
                    rxBuf = (CAN_RX_BUFFER *)rxFiFo0;

                    for (count = 0U; count < numberOfMessage; count++)
                    {
                        BTL_ProcessCommand(rxBuf->data, BTL_CANDlcToLengthGet(rxBuf->dlc));
                        rxBuf += CAN0_RX_FIFO0_ELEMENT_SIZE;
                    }
                }
            }
        }
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Bootloader Global Functions
// *****************************************************************************
// *****************************************************************************

void BTL_CAN_Tasks(void)
{
    if (canBLInitDone == false)
    {
        /* Set CAN0 Message RAM Configuration */
        CAN0_MessageRAMConfigSet(can0MessageRAM);

        canBLInitDone = true;
    }

    do
    {
        CAN0_Task();

    }  while (canBLActive);
}
