/*******************************************************************************
  BM71 Bluetooth Static Driver implementation

  Company:
    Microchip Technology Inc.

  File Name:
    custom_bm71_command_decode.c

  Summary:
   BM71 Bluetooth Static Driver source file for decoding events.

  Description:
    This file is the implementation of the internal functions of the BM71
    driver related to decoding events coming back from the BM71 module.
 
*******************************************************************************/
// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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
#include "custom_bm71.h"
#include "custom_bm71_local.h"
#include "custom_bm71_command_decode.h"
#include "custom_bm71_command_send.h"
#include "custom_bm71_uart.h"

extern CUSTOM_BM71_OBJ    gBm71Obj;

extern  volatile    bool    cmd_sent, cmd_successfull;
extern  volatile    bool    hr_measurment_request;
extern  volatile    bool    button_pressed;
extern              uint8_t hr_measurment_handle;

// all #defines, enums and non-static functions and variables prefixed by
// CUSTOM_BM71 to avoid name conflicts

#define CUSTOM_BM71_CMD_SIZE_MAX   200

//command decode state machine
typedef enum {
	CUSTOM_BM71_RX_DECODE_CMD_SYNC_AA,
	CUSTOM_BM71_RX_DECODE_CMD_SYNC_00,
	CUSTOM_BM71_RX_DECODE_CMD_LENGTH,
	CUSTOM_BM71_RX_DECODE_CMD_DATA,
	CUSTOM_BM71_RX_DECODE_CMD_CHECKSUM
} CUSTOM_BM71_RX_DECODE_MODE;

//command decode: BM71 status
enum
{
  CUSTOM_BM71_BM71STATUS_OFF = 0x00,
  CUSTOM_BM71_BM71STATUS_DISCOVERABLE = 0x01,
  CUSTOM_BM71_BM71STATUS_ON = 0x02,
  CUSTOM_BM71_BM71STATUS_PAIRING_COMPLETE = 0x03,
  CUSTOM_BM71_BM71STATUS_PAIRING_FAIL = 0x04,
  CUSTOM_BM71_BM71STATUS_SPP_CONNECTED = 0x0D,
  CUSTOM_BM71_BM71STATUS_SPP_DISCONNECTED = 0x0E,
  CUSTOM_BM71_BM71STATUS_STANDBY = 0x0F,
};

/*======================*/
/*  external variables  */
/*======================*/
static uint8_t  CmdDecodedFlag;
static uint8_t  CmdBuffer[CUSTOM_BM71_CMD_SIZE_MAX];

/*======================================*/
/*  internal variables          */
/*======================================*/
static CUSTOM_BM71_RX_DECODE_MODE  CmdDecodeState;
static uint8_t  CmdDecodeCmdLength;
static uint8_t  CmdDecodeChecksum;			
static uint8_t  CmdDecodeDataCnt;                    //temporary variable in decoding
static unsigned short CmdBufferPt;

/*======================================*/
/*  function implemention       */
/*======================================*/
void CUSTOM_BM71_CommandDecodeInit( void )
{
    CmdDecodedFlag = 0;
    CmdDecodeState = CUSTOM_BM71_RX_DECODE_CMD_SYNC_AA;
    while(CUSTOM_BM71_eusartRxCount)
    {
        CUSTOM_BM71_EUSART_Read();     // flush buffer
    }
	CUSTOM_BM71_SPPBuffClear();
}

void CUSTOM_BM71_CommandDecodeMain( void )
{
	CUSTOM_BM71_CommandHandler();
	if(CmdDecodedFlag)
	{
            CUSTOM_BM71_CommandDecode();
            CmdDecodedFlag = 0;
	}
}

extern volatile uint8_t CUSTOM_BM71_eusartRxCount;

void CUSTOM_BM71_CommandHandler(void) {
    uint8_t current_byte;

    while (CUSTOM_BM71_eusartRxCount) {
        current_byte = CUSTOM_BM71_EUSART_Read();

        switch (CmdDecodeState) {
            case CUSTOM_BM71_RX_DECODE_CMD_SYNC_AA:
                if (current_byte == 0xaa)
                    CmdDecodeState = CUSTOM_BM71_RX_DECODE_CMD_SYNC_00;
                break;

            case CUSTOM_BM71_RX_DECODE_CMD_SYNC_00:
                if (current_byte == 0x00)
                    CmdDecodeState = CUSTOM_BM71_RX_DECODE_CMD_LENGTH;
                else
                    CmdDecodeState = CUSTOM_BM71_RX_DECODE_CMD_SYNC_AA;
                break;

            case CUSTOM_BM71_RX_DECODE_CMD_LENGTH:
                CmdDecodedFlag = 0; //command receive flag clear
                CmdBufferPt = 0; //buffer reset for command parameter
                CmdDecodeCmdLength = current_byte;
                CmdDecodeChecksum = current_byte; //checksum calculation start!
                CmdDecodeDataCnt = current_byte; //save bytes number, use to check where is command end
                CmdDecodeState = CUSTOM_BM71_RX_DECODE_CMD_DATA; //next state
                break;

            case CUSTOM_BM71_RX_DECODE_CMD_DATA:
                CmdDecodeChecksum += current_byte;
                CmdDecodeDataCnt--;
                CmdBuffer[CmdBufferPt++] = current_byte;
                if (CmdDecodeDataCnt == 0) //no data remained?
                    CmdDecodeState = CUSTOM_BM71_RX_DECODE_CMD_CHECKSUM; //yes, next mode: checksum
                break;

            case CUSTOM_BM71_RX_DECODE_CMD_CHECKSUM:
                if ((uint8_t) (CmdDecodeChecksum + current_byte) == 0) {
                    CmdDecodedFlag = 1;
                } else {
                }
                CmdDecodeState = CUSTOM_BM71_RX_DECODE_CMD_SYNC_AA;
                break;
            default:
                break;
        }

        if (CmdDecodedFlag) {
            break;
        }
    }
}

void CUSTOM_BM71_CommandDecode( void )
{
    uint8_t i= 0;
    printf("\r\nResponse buffer = ");
    while(i < CmdDecodeCmdLength){
        printf("0x%02x ",CmdBuffer[i]);
        i++;
    }
    printf("\r\n");
    if (CmdBuffer[0]!=BM71_STATUS_REPORT)
    {
       // printf("event: 0x%02x 0x%02x 0x%02x\r\n",CmdBuffer[0],CmdBuffer[1],CmdBuffer[2]);               
    }
    else
    {
      //  printf("event: 0x%02x 0x%02x\r\n",CmdBuffer[0],CmdBuffer[1]);        
    }
    
    switch(CmdBuffer[0])
    {
        case BM71_LE_CONNECT_COMPLETE:        // 0x71
            // CmdBuffer[1] is status (0 == success)
            // CmdBuffer[2] is connection handle
            // CmdBuffer[3] is master(0)/slave(1)
            // CmdBuffer[4] is public(0)/random dev address(1)
            // CmdBuffer[5-10] is public or random device address (6 bytes)
            // CmdBuffer[11-12] is connection interval
            // CmdBuffer[13-14] is connection latency
            // CmdBuffer[15-16] is connection supervision timeout
            gBm71Obj.linkIndex = CmdBuffer[2];
            gBm71Obj.state = CUSTOM_BM71_STATE_BLE_CONNECTED;
            break;

        case BM71_DISCONNECT_COMPLETE:        // 0x72
            // CmdBuffer[1] is connection handle
            // CmdBuffer[2] is reason (0x13 == remote termination)
            gBm71Obj.state = CUSTOM_BM71_STATE_BLE_DISCONNECTED;
            cmd_successfull = 0;
            cmd_sent = 0;
            hr_measurment_request = 0;
            break;

        case BM71_COMMAND_COMPLETE:           // 0x80
            if(CmdBuffer[1] == 0x38 && CmdBuffer[2] == 0x00)
            {
                cmd_successfull = 1;
            }
            // CmdBuffer[1] is command that completed
            // CmdBuffer[2] is status (0 == success)
            // CmdBuffer[3-] are optional parametersis status (0 == success)
            break;
            
        case BM71_STATUS_REPORT:              // 0x81
            // CmdBuffer[1] is status
            // 0x01 -- Scanning Mode
            // 0x02 -- Connecting Mode
            // 0x03 -- Standby Mode
            // 0x05 -- Broadcast Mode
            // 0x08 -- Transparent Service Enabled Mode
            // 0x09 -- Idle Mode
            // 0x0a -- Shutdown Mode
            // 0x0b -- Configue Mode
            // 0x0c -- BLE connected
            switch(CmdBuffer[1])
            { 
                case 0x09:
                    CUSTOM_BM71_UpdateClientStatus(CUSTOM_BM71_BLE_STATUS_STANDBY);
                    break;

                case 0x03:
                    CUSTOM_BM71_UpdateClientStatus(CUSTOM_BM71_BLE_STATUS_ADVERTISING);
                    break;

                case 0x08:
                case 0x0c:
                    CUSTOM_BM71_UpdateClientStatus(CUSTOM_BM71_BLE_STATUS_CONNECTED);
                    break;
            }
            break;

        case BM71_SERVER_CHARACTERICTIC_VALUE_WRITE:  // 0x98
            // CmdBuffer[1] is connection handle
            // CmdBuffer[2-3] is characteristic value handle
            // CmdBuffer[4-] is characteristic value (max 20 bytes)
            // not currently used
            if (CmdBuffer[1] == 0x80 && CmdBuffer[2] == 0x80){
                if(CmdBuffer[3] == 0x03 && CmdBuffer[4] == 0x01)
                {
                    hr_measurment_request = 1;
                    button_pressed  = 1;
                    hr_measurment_handle = CmdBuffer[3] - 1;
                }
                else if(CmdBuffer[3] == 0x03 && CmdBuffer[4] == 0x00)
                {
                    cmd_sent = 0;
                    hr_measurment_request = 0;
                }
            }
            break;

        case BM71_TRANSPARENT_DATA_RECEIVED:  // 0x9a
            // CmdDecodeCmdLength is length of string + 2
            // CmdBuffer[1] is connection handle
            // CmdBuffer[2-] is transparent data
            CUSTOM_BM71_AddBytesToSPPBuff(&CmdBuffer[2], CmdDecodeCmdLength-2);
            break;
             
        default:
            break;
    }
}

