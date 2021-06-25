/*******************************************************************************
  BM71 Bluetooth Static Driver implementation

  Company:
    Microchip Technology Inc.

  File Name:
    drv_bm71_ble.c

  Summary:
   BM71 Bluetooth Static Driver source file for BLE

  Description:
    This file is the implementation of the internal functions of the BM71
    driver related to BLE.
 
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

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "definitions.h"
#include "bt/driver/bm71/drv_bm71.h"
#include "bt/driver/bm71/drv_bm71_local.h"
#include "bt/driver/bm71/drv_bm71_ble.h"
#include "bt/driver/bm71/drv_bm71_command_send.h"
#include "bt/driver/bm71/drv_bm71_command_decode.h"

extern DRV_BM71_OBJ    gDrvBm71Obj;

// all #defines, enums and non-static functions and variables prefixed by
// DRV_BM71 to avoid name conflicts

void DRV_BM71_BLE_Query_status( void );

/*-----------------------global functions --------------------*/
// *****************************************************************************
/* Function DRV_BM71_BLE_QueryStatus:

        void DRV_BM71_BLE_QueryStatus(const DRV_HANDLE handle);

  Summary:
    Query BM71 LE status.

  Description:
    Queries the BM71 to respond with a DRV_BM71_EVENT_BLE_STATUS_CHANGED event,
    which will indicate if the BM71 BLE status is standby, advertising,
    scanning or connected.

  Precondition:
    DRV_BM71_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle      - valid handle to an opened BM71 device driver unique to client

  Returns:
    None.

  Remarks:
    RV_BM71_BLE_QueryStatus is non-blocking; it returns right away and sometime
    later (perhaps tens or hundreds of ms) the event handler callback will be
    called.
*/

void DRV_BM71_BLE_QueryStatus(const DRV_HANDLE handle)
{
    DRV_BM71_BLE_Query_status();
}

// *****************************************************************************
/* Function DRV_BM71_BLE_EnableAdvertising:

        void DRV_BM71_BLE_EnableAdvertising(const DRV_HANDLE handle, bool enable);

  Summary:
    Enable or disable advertising.

  Description:
    Enable or disable BLE advertising.
 
  Precondition:
    DRV_BM71_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle      - valid handle to an opened BM71 device driver unique to client
    enable      - true to enable advertising, false to disable advertising

  Returns:
    None.

  Remarks:
    None.
*/

void DRV_BM71_BLE_EnableAdvertising(const DRV_HANDLE handle, bool enable)
{
    DRV_BM71_BLE_EnabAdvertising(enable);
}

void DRV_BM71_BLE_Query_status( void )
{
    uint8_t command[5];
    uint8_t chksum;

    command[0] = 0xAA;      //header byte 0
    command[1] = 0x00;      //header byte 1
    command[2] = 0x01;      //length
    command[3] = BM_STATUS_READ;      //command ID
    chksum = command[2] + command[3];
    chksum = ~chksum + 1;
    command[4] = chksum;
    DRV_BM71_SendBytesAsCompleteCommand(&command[0], 5);  
}

void DRV_BM71_BLE_Reset( void )
{
    uint8_t command[5];
    uint8_t chksum;

    command[0] = 0xAA;      //header byte 0
    command[1] = 0x00;      //header byte 1
    command[2] = 0x01;      //length
    command[3] = BM_RESET;      //command ID
    chksum = command[2] + command[3];
    chksum = ~chksum + 1;
    command[4] = chksum;
    DRV_BM71_SendBytesAsCompleteCommand(&command[0], 5);
}

void DRV_BM71_SendSPPData(uint8_t *data, uint16_t size, uint8_t connHandle)
{
    uint8_t command[646];
    uint8_t chksum;
    uint16_t i;

    if (size > 640)
    {
        size = 640;
    }
    uint8_t *p = data;  

    command[0] = 0xAA;      //header byte 0
    command[1] = 0x00;      //header byte 1
    command[2] = 0x02+size;
    command[3] = BM_TRANSPARENT_DATA_SEND;  //command ID
    command[4] = connHandle; 
    chksum = command[2] + command[3] + command[4];
    
    for(i = 0; i<size; i++)
    {
        command[5+i] = *p;
        chksum += *p++;
    }
    
    chksum = ~chksum + 1;
    command[5+size] = chksum;
    DRV_BM71_SendBytesAsCompleteCommand(&command[0], 6+size);
}

void DRV_BM71_BLE_WriteAdvertisingData(void)
{
    uint8_t command[50];
    uint8_t chksum;
    uint8_t i,size;

    const char *name = "TransparentUARTDemo";
    size = strlen(name);
    const char *p = name;   

    command[0] = 0xAA;      //header byte 0
    command[1] = 0x00;      //header byte 1
    command[2] = 0x07+size;
    command[3] = BM_ADV_DATA_WRITE;      //command ID
    command[4] = 0x01;
    command[5] = 0x02;    
    command[6] = ADV_FLAGS;
    command[7] = 0x05;
    command[8] = size+1;   
    command[9] = ADV_COMPLETE_NAME;  
    chksum = command[2] + command[3] + command[4] + command[5] + command[6] + command[7] + command[8] + command[9];
    
    for(i = 0; i<size; i++)
    {
        command[10+i] = (uint8_t)*p;
        chksum += (uint8_t)*p++;
    }
    
    chksum = ~chksum + 1;
    command[10+size] = chksum;
    DRV_BM71_SendBytesAsCompleteCommand(&command[0], 11+size);
}

void DRV_BM71_BLE_EnabAdvertising(bool enable)
{
    uint8_t command[6];
    uint8_t chksum;

    command[0] = 0xAA;      //header byte 0
    command[1] = 0x00;      //header byte 1
    command[2] = 0x02;      //length
    command[3] = BM_SET_ADV_ENABLE;      //command ID
    command[4] = (enable) ? 0x81 : 0;      //0x81=enter stby, beacon enabled, 0=leave standby
    chksum = command[2] + command[3] + command[4];
    chksum = ~chksum + 1;
    command[5] = chksum;
    DRV_BM71_SendBytesAsCompleteCommand(&command[0], 6);
}

void DRV_BM71_BLE_SetAdvertisingParams(void)
{
    uint8_t command[15];
    uint8_t chksum;

    command[0] = 0xAA;      //header byte 0
    command[1] = 0x00;      //header byte 1
    command[2] = 0x0B;      //length
    command[3] = BM_ADV_PARAM_SET;      //command ID
    command[4] = 0x06;      // advertising interval (1600*0.625 ms = 1 sec)
    command[5] = 0x40;      // advertising interval (lo byte)
    command[6] = 0x00;      // advertising type      
    command[7] = 0x00;      // direct address type      
    command[8] = 0x00;      // public or random device address
    command[9] = 0x00;
    command[10] = 0x00;
    command[11] = 0x00;
    command[12] = 0x00;
    command[13] = 0x00;
    chksum = command[2] + command[3] + command[4] + command[5]; // remainder 0
    chksum = ~chksum + 1;
    command[14] = chksum;
    DRV_BM71_SendBytesAsCompleteCommand(&command[0], 15);
}

void DRV_BM71_BLE_EnabTransparentMode(bool enable)
{
    uint8_t command[8];
    uint8_t chksum;

    command[0] = 0xAA;      //header byte 0
    command[1] = 0x00;      //header byte 1
    command[2] = 0x04;      //length
    command[3] = BM_TRANSPARENT_ENABLE;      //command ID
    command[4] = gDrvBm71Obj.linkIndex;      // last conn handle
    command[5] = (enable) ? 0x01 : 0;
    command[6] = 0x00;
    chksum = command[2] + command[3] + command[4] + command[5] + command[6];
    chksum = ~chksum + 1;
    command[7] = chksum;
    DRV_BM71_SendBytesAsCompleteCommand(&command[0], 8);
}


