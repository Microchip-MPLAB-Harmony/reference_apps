/*******************************************************************************
  BM71 Bluetooth Static Driver implementation

  Company:
    Microchip Technology Inc.

  File Name:
    drv_bm71_command_decode.h

  Summary:
   BM71 Bluetooth Static Driver header file for decoding events.

  Description:
    This file is the header file for the internal functions of the BM71
    driver related to decoding events coming back from the BM71 module.
 
*******************************************************************************/

/*****************************************************************************
 Copyright (C) 2017-2018 Microchip Technology Inc. and its subsidiaries.

Subject to your compliance with these terms, you may use Microchip software 
and any derivatives exclusively with Microchip products. It is your 
responsibility to comply with third party license terms applicable to your 
use of third party software (including open source software) that may 
accompany Microchip software.

THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A PARTICULAR 
PURPOSE.

IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE 
FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN 
ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY, 
THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*****************************************************************************/

#ifndef DRV_BM71_COMMAND_DECODE_H
#define DRV_BM71_COMMAND_DECODE_H

//#include <stdbool.h>
//#include <stdint.h>

// events coming from the BM71 over the UART RX interface as defined in the document 
// BLEDK3 Command Set (1.20) and decoded here
typedef enum _bm71_application_event_opcode
{
	BM71_EVENT_NONE = 0x00,
    BM71_PASSKEY_REQUEST       	= 0x60,
    BM71_PAIR_COMPLETE,
    BM71_PASSKEY_YESNO_REQUEST,
    BM71_ADVERTISING_REPORT	  	= 0x70,
    BM71_LE_CONNECT_COMPLETE,
    BM71_DISCONNECT_COMPLETE,
    BM71_CONNECTION_PARAMTER_UPDATE,
    BM71_COMMAND_COMPLETE       	= 0x80,
    BM71_STATUS_REPORT,
	BM71_LE_END_TEST_RESULT,
    BM71_CONFIGURE_MODE_STATUS  	= 0x8F,
    BM71_CLIENT_DISCOVER_ALL_SERVICES_RESULT 	= 0x90,
    BM71_CLIENT_DISCOVER_CHARACTERISTICS_RESULT,
    BM71_CLIENT_DISCOVER_CHARACTERISTICS_DESCRIPTORS_RESULT,
    BM71_CLIENT_CHARACTERISTIC_VALUE_RECEIVED,
    BM71_SERVER_CHARACTERICTIC_VALUE_WRITE = 0x98,
    BM71_SERVER_CHARACTERISTIC_VALUE_READ,
    BM71_TRANSPARENT_DATA_RECEIVED    	= 0x9A,
    BM71_SERVER_PREPARE_WRITE_REQUEST,
    BM71_SERVER_EXECUTE_WRITE_REQUEST,
    BM71_SERVER_BLOB_READ_REQUEST = 0xA0,
    BM71_CLIENT_PREPARE_WRITE_RESPONSE,
    BM71_CLIENT_EXECUTE_WRITE_RESPONSE,
    BM71_ERROR = 0xFF
} BM71_APPLICATION_EVENT_OPCODE;

void DRV_BM71_CommandHandler( void );
void DRV_BM71_CommandDecode( void );

void DRV_BM71_CommandDecodeInit( void );
void DRV_BM71_CommandDecodeMain( void );
void DRV_BM71_CommandDecode1MS_event( void );
#endif
