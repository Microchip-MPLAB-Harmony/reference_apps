
/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "trustZone/nonsecure_entry.h"
#include "app_nonsecure_deadbolt_control.h"
#include "app_nonsecure_security.h"
#include "app_nonsecure_battery_management.h"
#include "app_nonsecure_wifi_bridge.h"


//--- simpleMAP_message STRUCTURES FOR BUFFERING
struct simpleMAP_message SIMPLEMAPMESSAGE_RX_BUFFER;
struct simpleMAP_message SIMPLEMAPMESSAGE_TX_BUFFER;

extern APP_NONSECURE_DEADBOLT_CONTROL_DATA app_db_motorData;
extern APP_NONSECURE_SECURITY_DATA app_securityData;
extern APP_NONSECURE_BATTERY_MANAGEMENT_DATA app_bat_mgmtData;
extern APP_NONSECURE_WIFI_BRIDGE_DATA app_wifiData;

extern char passkey[32];

extern char ssid[32];
extern char password[32];

void Callback_from_simpleMAP(uint8_t callbacktype){
    switch(callbacktype){
        case simpleMAP_CB_TYPE_LOGFROMSECURE:
            //--- LOAD LOGS FROM SECURE IN LOCAL DEBUG BUFFER
            break;
        case simpleMAP_CB_TYPE_CONNECTED:
            //--- A VALID CONNECTION IS ACTIVE 
            /*Initiate Battery voltage Measurement*/
            app_bat_mgmtData.state = APP_NONSECURE_BATTERY_MANAGEMENT_STATE_MEASUREMENT;
            app_db_motorData.state = APP_NONSECURE_DEADBOLT_CONTROL_STATE_UPDATE_STATUS_TO_APP;
             break;
        case simpleMAP_CB_TYPE_DISCONNECTED:
            //--- A CONNECTION IS CLOSED
            break;
        case simpleMAP_CB_TYPE_TX_BUF_READY:
            //--- LAST TRANSMISSION HAS BEEN COMPLETED
            break;
        case simpleMAP_CB_TYPE_TX_ACK_RCV:
            //--- LAST MESSAGE WAS ACKNOWLEDGED
			break;
		case simpleMAP_CB_TYPE_ERROR:
            //--- AN ERROR OCCURRED ON SIMPLEMAP CHANNEL
			break;
		case simpleMAP_CB_TYPE_MESSAGE:
		case simpleMAP_CB_TYPE_MESSAGE_HMAC:
            //--- A MESSAGE WAS RECEIVED ON SIMPLEMAP CHANNEL
			if(SIMPLEMAPMESSAGE_RX_BUFFER.messagesize<=32){
				if(SIMPLEMAPMESSAGE_RX_BUFFER.data[0]==0xFF) // Close Door
                {
                    app_db_motorData.state = APP_NONSECURE_DEADBOLT_CONTROL_STATE_CLOSE;
                }
                else if (SIMPLEMAPMESSAGE_RX_BUFFER.data[0]==0xAA) // Open Door
                {
                    app_db_motorData.state = APP_NONSECURE_DEADBOLT_CONTROL_STATE_OPEN;
                }
                
                else if (SIMPLEMAPMESSAGE_RX_BUFFER.data[0]==0xBB) // wifi_On
                {
                    //Implement wifi on command here
                }
                
                else if (SIMPLEMAPMESSAGE_RX_BUFFER.data[0]==0xCC) // Generate Passkey
                {
                    app_securityData.state = APP_NONSECURE_SECURITY_STATE_TEMP_PASSKEY;
                }
                
                else if (SIMPLEMAPMESSAGE_RX_BUFFER.data[0]==0xDD) // BLE Disconnect
                {
                    //Take Disconnect action here
                    APP_NONSECURE_ENTRY_BLE_ModuleDisconnect();
                }
                
                else if (SIMPLEMAPMESSAGE_RX_BUFFER.data[0]==0xEE) // Set default passkey
                {                
                    memcpy(passkey,(char*)&SIMPLEMAPMESSAGE_RX_BUFFER.data[1], 5);
                    app_securityData.state = APP_NONSECURE_SECURITY_STATE_NEW_PASSKEY;
                    
                    APP_NONSECURE_ENTRY_SetDefaultKeyStore(true);
                    break;
                }
                
                #ifdef WIFI_ENABLE
                else if (SIMPLEMAPMESSAGE_RX_BUFFER.data[0]==0x88) // Set the SSID for WFI32 
                {                
                    memcpy(ssid,(char*)&SIMPLEMAPMESSAGE_RX_BUFFER.data[0], 25);
                    app_wifiData.state = APP_NONSECURE_WIFI_BRIDGE_STATE_SEND_SSID;
                    
                    break;
                }
                
                else if (SIMPLEMAPMESSAGE_RX_BUFFER.data[0]==0x99) // Set the password for WFI32 
                {                
                    memcpy(password,(char*)&SIMPLEMAPMESSAGE_RX_BUFFER.data[0], 25);
                    app_wifiData.state = APP_NONSECURE_WIFI_BRIDGE_STATE_SEND_PASSWORD;
                    
                    break;
                }
                #endif
                
			}else{
                
			}
		break;
    }
}




// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
   
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    QT_LED_COL0_Set();
    QT_LED_COL1_Set();
    QT_LED_COL2_Set();
    QT_LED_COL3_Set();

    QT_LED_ROW0_Set();
    QT_LED_ROW1_Set();
    QT_LED_ROW2_Set();
    QT_LED_ROW3_Set();
    
       
    //-- INITIALIZE SIMPLEMAP CALLBACK
    APP_NONSECURE_ENTRY_simpleMAP_Initialize(simpleMAP_SETTINGS_DEBUG,&SIMPLEMAPMESSAGE_RX_BUFFER,(funcptr_ns)Callback_from_simpleMAP);
    
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

