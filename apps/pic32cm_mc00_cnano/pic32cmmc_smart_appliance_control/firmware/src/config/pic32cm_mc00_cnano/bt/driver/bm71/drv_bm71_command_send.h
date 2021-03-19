/*******************************************************************************
  BM71 Bluetooth Static Driver implementation

  Company:
    Microchip Technology Inc.

  File Name:
    drv_bm71_command_send.h

  Summary:
   BM71 Bluetooth Static Driver header file for sending commands.

  Description:
    This file is the header file for the internal functions of the BM71
    driver related to sending commands to the BM71 module.
 
*******************************************************************************/

/*****************************************************************************
 Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.

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

#ifndef DRV_BM71_COMMAND_SEND_H
#define DRV_BM71_COMMAND_SEND_H

//#include <stdbool.h>
//#include <stdint.h>

void DRV_BM71_CommandSendInit(void);
void DRV_BM71_CommandSendTask( void );
void DRV_BM71_CommandSend1MS_event(void);

void DRV_BM71_UART_TransferFirstByte( void );
void DRV_BM71_UART_TransferNextByte( void );

void DRV_BM71_SendBytesAsCompleteCommand(uint8_t* command, uint8_t command_length);

void DRV_BM71_SendSPPData(uint8_t* addr, uint16_t size, uint8_t link_index);

#endif
