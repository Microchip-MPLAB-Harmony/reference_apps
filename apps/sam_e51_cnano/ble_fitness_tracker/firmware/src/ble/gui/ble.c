/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    ble.c

  Summary:
    Source code for BLE operations

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's BLE state machine and calls
    API routines of other MPLAB Harmony modules in the system, including the
    Bluetooth driver and system services.

 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2017 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END

#include <stdint.h> 
#include <string.h>
#include <ctype.h>      // for tolower

#include "ble.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Variable Definitions
// *****************************************************************************
// *****************************************************************************

static uint32_t _appBleContext;

BLE_DATA bleData;
extern APP_DATA appData;

#define MAX_BLE_BUFSIZE 21

static char message_buf1 [MAX_BLE_BUFSIZE];
static char message_buf2 [MAX_BLE_BUFSIZE];
static char message_buf3 [MAX_BLE_BUFSIZE]; 

static void _BLEEventHandler(DRV_BT_EVENT event, uint32_t param, uintptr_t context);

void bleInitialize(bool all)
{
    if (all)
    {
        bleData.state = BLE_STATE_OPEN;    
        bleData.bt.context = (uintptr_t) &_appBleContext;  
        bleData.bt.eventHandler = 
            (DRV_BT_EVENT_HANDLER) _BLEEventHandler;
    }
    
    laWidget_SetVisible((laWidget*)SendMessageButton, LA_FALSE);
    
    laWidget_SetVisible((laWidget*)ReceivedMessages, LA_FALSE);                                
    laWidget_SetVisible((laWidget*)TextMessage1, LA_FALSE);                                
    laWidget_SetVisible((laWidget*)TextMessage2, LA_FALSE); 
    laWidget_SetVisible((laWidget*)TextMessage3, LA_FALSE); 
    
    strcpy(message_buf1," ");
    strcpy(message_buf2," ");
    strcpy(message_buf3," ");    
   
} //End bleInitialize()

void bleTasks()
{               
    switch(bleData.state)
    {
        //----------------------------------------------------------------------
        // Open BT module 
        //----------------------------------------------------------------------
        case BLE_STATE_OPEN:
        {
            if (SYS_STATUS_READY == DRV_BT_Status())
            {            
                // open BT module
                bleData.bt.handle = DRV_BT_Open(DRV_IO_INTENT_READ, DRV_BT_PROTOCOL_ALL);

                if(bleData.bt.handle != DRV_HANDLE_INVALID)
                {
                        bleData.state = BLE_STATE_SET_BT_EVENT_HANDLER;
                }
                else
                {
                    /* Got an Invalid Handle.  Wait for BT module to Initialize */;
                }
            }
        }
        break;
        
        //----------------------------------------------------------------------
        //Set the BT RX Buffer Handler
        //----------------------------------------------------------------------
        case BLE_STATE_SET_BT_EVENT_HANDLER:
        {          
            DRV_BT_EventHandlerSet(bleData.bt.handle,
                                          bleData.bt.eventHandler,
                                          (uintptr_t)0);                                  

            bleData.state = BLE_STATE_INIT_DONE;            
        }
        break;               
        
        // Initialized 
        case BLE_STATE_INIT_DONE:
        {
            // waits in this state
            break;
        }        

        default:
        {
        }
        break;

    } //End switch(bleData.state)

}

static void _BLEEventHandler(DRV_BT_EVENT event, uint32_t param, uintptr_t context)
{
    switch(event)
    {
        case DRV_BT_EVENT_BLESPP_MSG_RECEIVED:
        {           
            laString tempStr;                                      
            char buf[MAX_BLE_BUFSIZE];
            
            if (DRV_BT_ReadDataFromBLE(bleData.bt.handle, (uint8_t*)buf, MAX_BLE_BUFSIZE ))
            {
                strcpy(message_buf1, message_buf2);
                strcpy(message_buf2, message_buf3);
                strcpy(message_buf3, buf);
            
                laWidget_SetVisible((laWidget*)ReceivedMessages, LA_TRUE);                                
                
                laWidget_SetVisible((laWidget*)TextMessage1, LA_TRUE);                                
                tempStr = laString_CreateFromCharBuffer(message_buf1, &LiberationSans12);
                laLabelWidget_SetText(TextMessage1, tempStr);
                laString_Destroy(&tempStr); 

                laWidget_SetVisible((laWidget*)TextMessage2, LA_TRUE);                                
                tempStr = laString_CreateFromCharBuffer(message_buf2, &LiberationSans12);
                laLabelWidget_SetText(TextMessage2, tempStr);
                laString_Destroy(&tempStr); 

                laWidget_SetVisible((laWidget*)TextMessage3, LA_TRUE);                                
                tempStr = laString_CreateFromCharBuffer(message_buf3, &LiberationSans12);
                laLabelWidget_SetText(TextMessage3, tempStr);
                laString_Destroy(&tempStr);

                int i;
                for (i=0; i < strlen(buf); i++)
                {
                    buf[i] = tolower(buf[i]);
                }
                if (!strcmp(buf,"led on"))
                {
                    LED1_On();
                }
                else if (!strcmp(buf,"led off"))
                {
                    LED1_Off();
                }                
            }
        }
        break;
        
        case DRV_BT_EVENT_BLE_STATUS_CHANGED:
        {           
            switch(param)
            {             
                case DRV_BM64_BLE_STATUS_STANDBY:
                case DRV_BM64_BLE_STATUS_SCANNING:
                    laWidget_SetVisible((laWidget*)Connected_Image, LA_FALSE);
                    laWidget_SetVisible((laWidget*)PairedImage, LA_FALSE);
                    laWidget_SetVisible((laWidget*)No_pair_no_connection_Image, LA_TRUE);
                    LED1_On();
                    appData.waitingToConnect = true;
                    bleInitialize(false);
                    break;
                case DRV_BM64_BLE_STATUS_ADVERTISING:
                    laWidget_SetVisible((laWidget*)Connected_Image, LA_FALSE);
                    laWidget_SetVisible((laWidget*)PairedImage, LA_TRUE);        // actually, advertising
                    laWidget_SetVisible((laWidget*)No_pair_no_connection_Image, LA_FALSE);
                    LED1_On();
                    appData.waitingToConnect = true;
                    bleInitialize(false);                    
                    break;
                case DRV_BM64_BLE_STATUS_CONNECTED:
                    laWidget_SetVisible((laWidget*)Connected_Image, LA_TRUE);
                    laWidget_SetVisible((laWidget*)PairedImage, LA_FALSE);
                    laWidget_SetVisible((laWidget*)No_pair_no_connection_Image, LA_FALSE);
                    LED1_Off();
                    laWidget_SetVisible((laWidget*)SendMessageButton, LA_TRUE);
                    appData.waitingToConnect = false;                    
                    break;                    
            }           
        }
        break;
        
        default:
            break;
    }
}
