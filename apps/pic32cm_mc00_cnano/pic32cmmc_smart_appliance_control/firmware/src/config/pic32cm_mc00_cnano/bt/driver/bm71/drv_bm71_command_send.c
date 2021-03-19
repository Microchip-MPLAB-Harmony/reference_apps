/*******************************************************************************
  BM71 Bluetooth Static Driver implementation

  Company:
    Microchip Technology Inc.

  File Name:
    drv_bm71_command_send.c

  Summary:
   BM71 Bluetooth Static Driver source file for sending commands.

  Description:
    This file is the implementation of the internal functions of the BM71
    driver related to sending commands to the BM71 module.
 
*******************************************************************************/
// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

#include "definitions.h"
#include "bt/driver/bm71/drv_bm71.h"
#include "bt/driver/bm71/drv_bm71_local.h"
#include "bt/driver/bm71/drv_bm71_command_send.h"
#include "bt/driver/bm71/drv_bm71_command_decode.h"
#include "bt/driver/bm71/drv_bm71_gpio.h"
#include "bt/driver/bm71/drv_bm71_uart.h"

// all #defines, enums and non-static functions and variables prefixed by
// DRV_BM71 to avoid name conflicts

#define DRV_BM71_UR_TX_BUF_SIZE              300
static uint8_t      UR_TxBuf[DRV_BM71_UR_TX_BUF_SIZE];
static uint16_t     UR_TxBufHead;
static uint16_t     UR_TxBufTail;
typedef enum {
	DRV_BM71_TXRX_BUF_EMPTY,
	DRV_BM71_TXRX_BUF_OK,
	DRV_BM71_TXRX_BUF_FULL
} DRV_BM71_TXRX_BUF_STATUS;
static DRV_BM71_TXRX_BUF_STATUS  UR_TxBufStatus;

typedef enum {
    DRV_BM71_CMD_SEND_STATE_IDLE = 0,         //no data in the queue, MFB is low
    DRV_BM71_CMD_SEND_MFB_HIGH_WAITING,       //set MFB to high, and wait for 2ms
    DRV_BM71_CMD_SEND_DATA_SENDING,           //UART interface is working
    DRV_BM71_CMD_SEND_DATA_SENT_WAITING,      //wait for another 10ms after all data are sent out
} DRV_BM71_CMD_SEND_STATE;

DRV_BM71_CMD_SEND_STATE CMD_SendState;
static uint8_t CommandStartMFBWaitTimer;
static uint8_t CommandSentMFBWaitTimer;

/*======================================*/
/*  function implementation  */
/*======================================*/
/*------------------------------------------------------------*/
static void StartToSendCommand( void )
{
    switch(CMD_SendState)
    {
        case DRV_BM71_CMD_SEND_MFB_HIGH_WAITING:
            //MFB waiting, do nothing
            break;

        case DRV_BM71_CMD_SEND_DATA_SENDING:
            //data is going, do nothing
            break;

        case DRV_BM71_CMD_SEND_DATA_SENT_WAITING:
            CMD_SendState = DRV_BM71_CMD_SEND_DATA_SENDING;
            DRV_BM71_UART_TransferFirstByte();
            break;

        case DRV_BM71_CMD_SEND_STATE_IDLE:
            CMD_SendState = DRV_BM71_CMD_SEND_MFB_HIGH_WAITING;
            //DRV_BM71_MFB_SetHigh();
            CommandStartMFBWaitTimer = 3;      //wait 2 - 3ms
            break;
    }
}

/*------------------------------------------------------------*/
static bool copySendingCommandToBuffer(uint8_t* data, uint16_t size)
{
    bool buf_result = true;
    uint8_t ur_tx_buf_status_save = UR_TxBufStatus;
    uint16_t ur_tx_buf_head_save = UR_TxBufHead;

    if(UR_TxBufStatus !=  DRV_BM71_TXRX_BUF_FULL)
    {
        while(size--)
        {
            UR_TxBuf[UR_TxBufHead++] = *data++;

            if(UR_TxBufHead >= DRV_BM71_UR_TX_BUF_SIZE)
                UR_TxBufHead = 0;

            if(UR_TxBufHead ==  UR_TxBufTail)
            {
                if(size)
                {
                    buf_result = false;
                    UR_TxBufStatus = ur_tx_buf_status_save;		//restore in this case
                    UR_TxBufHead = ur_tx_buf_head_save;                 //restore in this case
                }
                else
                {
                    UR_TxBufStatus =  DRV_BM71_TXRX_BUF_FULL;
                }
                break;
            }
            else
            {
                UR_TxBufStatus = DRV_BM71_TXRX_BUF_OK;
            }
        }

        if(buf_result)
        {
            StartToSendCommand();
        }
    }
    else
    {
        buf_result = false;
    }
    return buf_result;
}

/*------------------------------------------------------------*/
#if 0
static uint8_t calculateChecksum(uint8_t* startByte, uint8_t* endByte)
{
    uint8_t checksum = 0;
    while(startByte <= endByte)
    {
        checksum += *startByte;
        startByte++;
    }
    checksum = ~checksum + 1;
    return checksum;
}

static uint8_t calculateChecksum2(uint8_t checksum, uint8_t* startByte, uint16_t length)
{
    while(length)
    {
        checksum += *startByte++;
        length--;
    }
    return checksum;
}
#endif

/*------------------------------------------------------------*/
void DRV_BM71_SendBytesAsCompleteCommand(uint8_t* command, uint8_t command_length)
{
    copySendingCommandToBuffer(command, command_length);
    //DRV_BM71_UpdateAckStatusWhenSent(command[3]);
}

/*------------------------------------------------------------*/
void DRV_BM71_CommandSendInit( void )
{
    UR_TxBufHead = 0;
    UR_TxBufTail = 0;
    UR_TxBufStatus = DRV_BM71_TXRX_BUF_EMPTY;
}

/*------------------------------------------------------------*/
void DRV_BM71_CommandSendTask( void )
{
    switch(CMD_SendState)
    {
        case DRV_BM71_CMD_SEND_MFB_HIGH_WAITING:
            //do nothing, timer interrupt will handle
            break;

        case DRV_BM71_CMD_SEND_DATA_SENDING:
            //do nothing, UART interrupt will handle
            break;

        case DRV_BM71_CMD_SEND_DATA_SENT_WAITING:
            if(!CommandSentMFBWaitTimer)
            {
                //DRV_BM71_MFB_SetLow();
                CMD_SendState = DRV_BM71_CMD_SEND_STATE_IDLE;
            }
            break;

        case DRV_BM71_CMD_SEND_STATE_IDLE:
            break;

        default:
            break;
    }
}

/*------------------------------------------------------------*/
void DRV_BM71_CommandSend1MS_event(void)        // gets control every 1 ms
{
    if(CommandSentMFBWaitTimer)
        --CommandSentMFBWaitTimer;

    if( CommandStartMFBWaitTimer)
    {
        -- CommandStartMFBWaitTimer;
        if(! CommandStartMFBWaitTimer)
        {
            if(CMD_SendState == DRV_BM71_CMD_SEND_MFB_HIGH_WAITING)
            {
                CMD_SendState = DRV_BM71_CMD_SEND_DATA_SENDING;
                DRV_BM71_UART_TransferFirstByte();
            }
        }
    }
}

/*------------------------------------------------------------*/
void DRV_BM71_UART_TransferFirstByte( void )
{
    uint8_t data;
    if(UR_TxBufStatus != DRV_BM71_TXRX_BUF_EMPTY)
    {
        data = UR_TxBuf[UR_TxBufTail++];
        if(UR_TxBufTail >= DRV_BM71_UR_TX_BUF_SIZE)
            UR_TxBufTail = 0;
        if(UR_TxBufHead == UR_TxBufTail)
            UR_TxBufStatus = DRV_BM71_TXRX_BUF_EMPTY;
        else
            UR_TxBufStatus = DRV_BM71_TXRX_BUF_OK;
        DRV_BM71_EUSART_Write(data);
    }
}

/*------------------------------------------------------------*/
void DRV_BM71_UART_TransferNextByte( void )
{
    uint8_t data;
    if(UR_TxBufStatus != DRV_BM71_TXRX_BUF_EMPTY)
    {
        data = UR_TxBuf[UR_TxBufTail++];
        if(UR_TxBufTail >= DRV_BM71_UR_TX_BUF_SIZE)
            UR_TxBufTail = 0;
        if(UR_TxBufHead == UR_TxBufTail)
            UR_TxBufStatus = DRV_BM71_TXRX_BUF_EMPTY;
        else
            UR_TxBufStatus = DRV_BM71_TXRX_BUF_OK;
        DRV_BM71_EUSART_Write(data);
    }
    else
    {
        if(CMD_SendState == DRV_BM71_CMD_SEND_DATA_SENDING)
        {
            CMD_SendState = DRV_BM71_CMD_SEND_DATA_SENT_WAITING;
            CommandSentMFBWaitTimer = 10;
        }
    }
}



