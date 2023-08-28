/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_sec.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application for security protocols.
    It implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/


//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.
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
//DOM-IGNORE-END



// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdio.h>
#include "app_sec.h"
#include "app_transfer.h"
#include "cryptoauthlib.h"
#include "definitions.h"
#include "../../../../authentication.h"
#include "cloud_wifi_task.h"



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
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/


APP_SEC_DATA app_secData;
APP_TRANSFER_DATA app_transferData;

uint8_t ret_status;

#if defined(__XC32__)
extern ATCAIfaceCfg atecc608_0_init_data;
#endif

ATCAIfaceCfg *cfg =&atecc608_0_init_data;

extern uint8_t Client_ECC_Nack;

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_SEC_Initialize ( void )

  Remarks:
    See prototype in app_sec.h.
 */

void APP_SEC_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_secData.state = APP_SEC_STATE_INIT;


}


/******************************************************************************
  Function:
    void APP_SEC_Tasks ( void )

  Remarks:
    See prototype in app_sec.h.
 */

void APP_SEC_Tasks ( void )
{
    /* Check the application's current state. */
    switch ( app_secData.state )
    {
        /* Application's initial state. */
        case APP_SEC_STATE_INIT:
        {
            if(check_device_type_in_cfg(cfg,false)== ATCA_SUCCESS)
            {  
                if (ATCA_SUCCESS != (ret_status = atcab_init(cfg)))
                {
                  console_print_message("Device Init failed");
                  break;
                }
                else
                {                                                        
                    if(ATCA_SUCCESS != (ret_status= slot_write(6))){
                    console_print_message("Write failed in slot 6"); 
                    break;
                    }
                    
                    else{                        
                    if(ATCA_SUCCESS != (ret_status = slot_write(5))){
                    console_print_message("Write failed in slot 5");
                    break;
                    }
                    else
                        app_secData.state= APP_SEC_STATE_GENERATE_DEVICE_MAC;
                    
                    }
       
                }
                
            }
                       
            else
                console_print_error_message("Device check failed");           

                break;
        }      
        
        /*Generates Random number to be sent to client for authentication*/
        case APP_SEC_STATE_GENERATE_DEVICE_MAC:{
            if(ATCA_SUCCESS != (ret_status =generate_RNG()))
            {
                console_print_error_message("RNG generation unsuccessful");
                
            }
            else{
            app_secData.state = APP_SEC_STATE_SERVICE_TASKS;
            app_transferData.state = APP_STATE_TRANSMIT_RN;     
            }
            break;
    }
        case APP_SEC_STATE_CALCULATE_HOST_MAC:{
            if(Client_ECC_Nack)
            {
               console_print_error_message("No ECC Present at the Client Side");
               app_secData.state = APP_SEC_STATE_SERVICE_TASKS ;                
            }
            
           if(ATCA_SUCCESS != (ret_status =calculate_host_mac())){
               console_print_error_message("Host MAC generation unsuccessful");
               app_secData.state = APP_SEC_STATE_SERVICE_TASKS ;
           }
           else{
               console_print_success_message("Host MAC generation successful");
               app_secData.state = APP_SEC_STATE_CHECK_MAC;
           }
           
           break;
        }
        case APP_SEC_STATE_CHECK_MAC:{
            if(ATCA_SUCCESS != (ret_status = mac_compare()))
            {
                
            }
            else
            {
                app_transferData.state = APP_STATE_TRANSMIT_ACK;
            }
            app_secData.state = APP_SEC_STATE_SERVICE_TASKS;
            break;
        }
        

        case APP_SEC_STATE_SERVICE_TASKS:
        {
            
            break;
        }

        /* The default state should never be executed. */
        default:
        {
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
