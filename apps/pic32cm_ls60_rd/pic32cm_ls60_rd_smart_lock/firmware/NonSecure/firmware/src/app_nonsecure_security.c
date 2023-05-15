
/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_nonsecure_security.c

  Summary:
    Source code for Security implementation.

  Description:
    This file contains the source code for the application's secure user interface.
    It implements the logic for creating, saving and verifying user passkeys.
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

#include "app_nonsecure_security.h"
#include "trustZone/nonsecure_entry.h"
#include "app_nonsecure_deadbolt_control.h"
#include "app_nonsecure_wifi_bridge.h"

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
    This structure should be initialized by the APP_NONSECURE_SECURITY_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_NONSECURE_SECURITY_DATA app_securityData;
APP_NONSECURE_PASSKEY_STATUS val_stat;


// *****************************************************************************
// *****************************************************************************
// Section: External variables
// *****************************************************************************
// *****************************************************************************

extern char passkey[32];
extern APP_NONSECURE_DEADBOLT_CONTROL_DATA app_db_motorData;
extern APP_NONSECURE_WIFI_BRIDGE_DATA app_wifiData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_NONSECURE_SECURITY_Initialize ( void )

  Remarks:
    See prototype in app_nonsecure_security.h.
 */

void APP_NONSECURE_SECURITY_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_securityData.state = APP_NONSECURE_SECURITY_STATE_INIT;

    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}

/******************************************************************************
  Function:
    void APP_NONSECURE_SECURITY_Tasks ( void )

  Remarks:
    See prototype in app_nonsecure_security.h.
 */

void APP_NONSECURE_SECURITY_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( app_securityData.state )
    {
        /* Application's initial state. */
        case APP_NONSECURE_SECURITY_STATE_INIT:
        {
           
           
            if(!APP_NONSECURE_ENTRY_CheckDeviceType())
            {
                #if DEBUG_PRINT
                printf("check_device_type_in_cfg() failed with ret=0x%08X\r\n", status);
                #endif
            }
            else
            {
                if (!APP_NONSECURE_ENTRY_atcabInit()) 
                {
                    #if DEBUG_PRINT
                    printf("atcab_init() failed with ret=0x%08X\r\n", status);
                    #endif
                }
                else
                {
                   // LowPower_Enter();
                }
            }
            
            if(!APP_NONSECURE_ENTRY_NVM_ReadDefaultKey())
            {
               APP_NONSECURE_ENTRY_DefaultPasskeyStore();
                   /*Write success*/                     
            }
            
            APP_NONSECURE_ENTRY_SetPasskeyData((uint8_t*)passkey);

            app_securityData.state = APP_NONSECURE_SECURITY_STATE_WAIT;
            break;
        }

        case APP_NONSECURE_SECURITY_STATE_VALIDATE_PASSKEY:
        {
            if((val_stat=APP_NONSECURE_ENTRY_ValidatePasskey()) == 1)
            {
                app_db_motorData.state = APP_NONSECURE_DEADBOLT_CONTROL_STATE_OPEN;
            }
          
          app_securityData.state = APP_NONSECURE_SECURITY_STATE_WAIT;
         break;
        }
        
        case APP_NONSECURE_SECURITY_STATE_NEW_PASSKEY:
        {
            if(APP_NONSECURE_ENTRY_SetNewPasskey())
                app_securityData.state = APP_NONSECURE_SECURITY_STATE_WAIT;
            
           app_securityData.state = APP_NONSECURE_SECURITY_STATE_WAIT;
           break;
        }
        
        case APP_NONSECURE_SECURITY_STATE_TEMP_PASSKEY:
        {
            if(APP_NONSECURE_ENTRY_SaveTempPasskey())
            {
                app_securityData.state = APP_NONSECURE_SECURITY_STATE_WAIT;
                #ifdef WIFI_ENABLE
                app_wifiData.state = APP_NONSECURE_WIFI_BRIDGE_STATE_SEND_INFO; //##Added to send digest and signature
                #endif
                break;
            }
            else
            {}
                
        }
        
        case APP_NONSECURE_SECURITY_STATE_WAIT:
        {
            APP_NONSECURE_ENTRY_SecurityWait();
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



/*******************************************************************************
 End of File
 */
