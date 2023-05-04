/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_nonsecure_wifi_bridge.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
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

#ifdef WIFI_ENABLE

#include "app_nonsecure_wifi_bridge.h"
#include "definitions.h"
#include <stdbool.h>
#include "trustZone/nonsecure_entry.h"
#include <string.h>


// *****************************************************************************
// *****************************************************************************
// Section: Global Variables
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
char digest_string[6]="digest";
char * digest_ptr;
char digest_data[96];
char ssid[32] = {'\0'};
char password[32] = {'\0'};
unsigned int i;
uint8_t com_received=0;
volatile bool g_passkeyentry_stat=false;

// *****************************************************************************
// *****************************************************************************
// Section: External variables
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************

extern APP_NONSECURE_DEADBOLT_CONTROL_DATA app_db_motorData;

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_BRIDGE_WIFI_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_NONSECURE_WIFI_BRIDGE_DATA app_wifiData;

// *****************************************************************************
// *****************************************************************************
// Section: Application local Callback Functions
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_BRIDGE_WIFI_Initialize ( void )

  Remarks:
    See prototype in app_nonsecure_wifi_bridge.h.
 */

void APP_NONSECURE_WIFI_BRIDGE_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_wifiData.state = APP_NONSECURE_WIFI_BRIDGE_STATE_INIT;
    
    /* Register callback functions */
    
    APP_NONSECURE_ENTRY_USART_CallbacksRegister(); 

}


/******************************************************************************
  Function:
    void APP_BRIDGE_WIFI_Tasks ( void )

  Remarks:
    See prototype in app_nonsecure_wifi_bridge.h.
 */

void APP_NONSECURE_WIFI_BRIDGE_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( app_wifiData.state )
    {
        /* Application's initial state. */
        case APP_NONSECURE_WIFI_BRIDGE_STATE_INIT:
        {            
            APP_NONSECURE_ENTRY_USART_Read();
            app_wifiData.state = APP_NONSECURE_WIFI_BRIDGE_STATE_SERVICE_TASKS;
            break;
        }

        case APP_NONSECURE_WIFI_BRIDGE_STATE_SERVICE_TASKS:
        {

            if(APP_NONSECURE_ENTRY_USART_GetReadStatus() == true)
            {
                APP_NONSECURE_ENTRY_USART_SetReadStatus(false);
                app_wifiData.state = APP_NONSECURE_WIFI_BRIDGE_STATE_RECEIVE_INFO;
            }
   
            break;
        }
        
        case APP_NONSECURE_WIFI_BRIDGE_STATE_SEND_INFO:
        {
            if((APP_NONSECURE_ENTRY_USART_WriteBusy()==false)&&(APP_NONSECURE_ENTRY_USART_GetWriteStatus() ==false)){
            APP_NONSECURE_ENTRY_USART_Write(NULL,(size_t)NULL);
            APP_NONSECURE_ENTRY_simpleMAP_DebugOut((uint8_t *)"-> USARTS Written\n",18);}
            if(APP_NONSECURE_ENTRY_USART_GetWriteStatus() ==true){
            APP_NONSECURE_ENTRY_USART_SetWriteStatus(false);  
            APP_NONSECURE_ENTRY_simpleMAP_DebugOut((uint8_t *)"-> Digest Written\n",18);
            app_wifiData.state = APP_NONSECURE_WIFI_BRIDGE_STATE_INIT;
            }
            break;
        }
        
        case APP_NONSECURE_WIFI_BRIDGE_STATE_RECEIVE_INFO:
        {
            /*Print Open Command received notification*/
            if((com_received=APP_NONSECURE_ENTRY_CommancCheck())==1){
            
                APP_NONSECURE_ENTRY_simpleMAP_DebugOut((uint8_t *)"-> Open cmd received\n",21);
                g_passkeyentry_stat=true;                
            }
            else if((com_received=APP_NONSECURE_ENTRY_CommancCheck())==2)
            {
                APP_NONSECURE_ENTRY_simpleMAP_DebugOut((uint8_t *)"-> Close cmd received\n",22);   
                app_db_motorData.state = APP_NONSECURE_DEADBOLT_CONTROL_STATE_CLOSE;
            }
            com_received=0;            
            app_wifiData.state = APP_NONSECURE_WIFI_BRIDGE_STATE_INIT;
            
            break;
        }
        
        case APP_NONSECURE_WIFI_BRIDGE_STATE_SEND_SSID:
        {
            if((APP_NONSECURE_ENTRY_USART_WriteBusy()==false)&&(APP_NONSECURE_ENTRY_USART_GetWriteStatus() ==false)){
            APP_NONSECURE_ENTRY_USART_Write(ssid, sizeof(ssid));
            }
            
            if(APP_NONSECURE_ENTRY_USART_GetWriteStatus() ==true){
               APP_NONSECURE_ENTRY_USART_SetWriteStatus(false); 
               memset(ssid, 0, sizeof(ssid));
               app_wifiData.state = APP_NONSECURE_WIFI_BRIDGE_STATE_INIT;
            }
            
            break;
        }
        
        case APP_NONSECURE_WIFI_BRIDGE_STATE_SEND_PASSWORD:
        {
            if((APP_NONSECURE_ENTRY_USART_WriteBusy()==false)&&(APP_NONSECURE_ENTRY_USART_GetWriteStatus() ==false)){
            APP_NONSECURE_ENTRY_USART_Write(password, sizeof(password));
           
            }
            
            if(APP_NONSECURE_ENTRY_USART_GetWriteStatus() ==true){
               APP_NONSECURE_ENTRY_USART_SetWriteStatus(false); 
               memset(password, 0, sizeof(password));
               app_wifiData.state = APP_NONSECURE_WIFI_BRIDGE_STATE_INIT;
            }
            
            break;
        }

        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}

#endif

/* *****************************************************************************
 End of File
 */
