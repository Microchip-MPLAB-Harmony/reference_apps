/* ************************************************************************** */
/** BLE CHANNEL MANAGER FOR BM70 MODULE

  Company:
    MICROCHIP TECHNOLOGY INC

  File Name:
    app_secure_ble_manager.c

  Summary:
    Manages BM70 Connections.

  Description:
    Implements specific BM70 managing functions.
 */
/* ************************************************************************** */

// DOM-IGNORE-BEGIN
/*******************************************************************************************
* Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.

 * Subject to your compliance with these terms, you may use this Microchip software
 * and any derivatives exclusively with Microchip products. You are responsible for
 * complying with third party license terms applicable to your use of third party
 * software (including open source software) that may accompany this Microchip software.

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
 *******************************************************************************************/
// DOM-IGNORE-END

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include <stdbool.h>
#include "config/default/definitions.h"
#include "app_secure_ble_manager.h"
#include "../src/simpleMAP/simpleMAP_HAL.h"
#include "../src/simpleMAP/simpleMAP_library.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */
#define     MAX_INVALID_PEER_CONNECTED      5000
uint16_t    BLE_TIME_COUNTER;
bool        BLE_CONNECTED;
bool        BLE_CHANNEL_VALID;
bool        DISCONNECT_IN_COURSE;

/* ************************************************************************** */
/** RESET BLE BM70 MODULE
 */
void APP_SECURE_BLE_MANAGER_ModuleReset( void ){
    EIC_SEC_REGS->EIC_INTENSET = 0x00; 
    BLE_RESET_Clear();
    BLE_DISCONNECT_Set();
    pic32cm_sleep_ms(700);
    BLE_RESET_Set();
    pic32cm_sleep_ms(300);
    BLE_TIME_COUNTER = MAX_INVALID_PEER_CONNECTED;
    BLE_CHANNEL_VALID = false;
    BLE_CONNECTED = false;
    DISCONNECT_IN_COURSE = false;
}


/* ************************************************************************** */
/** READ FROM STATUS GPIO IF BM70 IS CONNECTED
 */
bool APP_SECURE_BLE_MANAGER_ModuleConnected( void ){
    return !BLE_STATUS_Get();
}


/* ************************************************************************** */
/** VALIDATE/INVALIDATE CONNECTED PEER from external task
 *  immediately after a call to this, if invalidated, the connection will be 
 *  terminated. if valid, the MAX_INVALID_PEER_CONNECTED timing will be nulled 
 *  and the validity of the channel will be checked continuously
 */
void APP_SECURE_BLE_MANAGER_IsPeerValid( bool valid ){
    BLE_CHANNEL_VALID = valid;
    BLE_TIME_COUNTER = 0;
}


/* ************************************************************************** */
/** FORCE BM70 TO DISCONNECT
 */
void APP_SECURE_BLE_MANAGER_BleModuleDisconnect( void ){
    BLE_DISCONNECT_Clear();
    pic32cm_sleep_ms(15);
    BLE_DISCONNECT_Set();
    pic32cm_sleep_ms(5);
}


/* ************************************************************************** */
/** MANAGES CONNECTIONS:
 *  - Must be called every milisecond
 *  - Notifies status of connection
 *  - Allows a connection MAX_INVALID_PEER_CONNECTED milliseconds: after that,
 *    BLE_CHANNEL will be validated each time and will eventually trigger a
 *    disconnection
 */
void APP_SECURE_BLE_MANAGER_Task( void )
{
    if(!BLE_CONNECTED){
        if(APP_SECURE_BLE_MANAGER_ModuleConnected()){
            BLE_CONNECTED = true;
            BLE_CHANNEL_VALID = true;
            DISCONNECT_IN_COURSE = false;
            simpleMAP_debug_out((uint8_t *)" BLE CONNECTED ",16);
        }
        return;
    }
    if(BLE_CONNECTED){
        if(!APP_SECURE_BLE_MANAGER_ModuleConnected()){
            BLE_TIME_COUNTER = MAX_INVALID_PEER_CONNECTED;
            BLE_CHANNEL_VALID = false;
            BLE_CONNECTED = false;
            simpleMAP_channel_reset();
            if(DISCONNECT_IN_COURSE) 
                simpleMAP_debug_out((uint8_t *)"BLE DISCONNECTED",16);
            else
                simpleMAP_debug_out((uint8_t *)"PHO DISCONNECTED",16);
            if(simpleMAP_APPLICATION_CALLBACK!=NULL)simpleMAP_APPLICATION_CALLBACK(simpleMAP_CB_TYPE_DISCONNECTED);
            DISCONNECT_IN_COURSE = false;
            return;
        }
        if(BLE_TIME_COUNTER>0) BLE_TIME_COUNTER--;
        if(BLE_TIME_COUNTER == 0 && !BLE_CHANNEL_VALID)
        {
            BLE_TIME_COUNTER = MAX_INVALID_PEER_CONNECTED;
            DISCONNECT_IN_COURSE = true;
        }
    }
}

void APP_SECURE_BLE_MANAGER_BleDisconnect(void)
{
    if(!APP_SECURE_BLE_MANAGER_ModuleConnected()){
            BLE_TIME_COUNTER = MAX_INVALID_PEER_CONNECTED;
            BLE_CHANNEL_VALID = false;
            BLE_CONNECTED = false;
            simpleMAP_channel_reset();
            if(DISCONNECT_IN_COURSE) 
                simpleMAP_debug_out((uint8_t *)"BLE DISCONNECTED",16);
            else
                simpleMAP_debug_out((uint8_t *)"PHO DISCONNECTED",16);
            if(simpleMAP_APPLICATION_CALLBACK!=NULL)simpleMAP_APPLICATION_CALLBACK(simpleMAP_CB_TYPE_DISCONNECTED);
            DISCONNECT_IN_COURSE = false;
        }
}


/* *****************************************************************************
 End of File
 */
