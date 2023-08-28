/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_sec.c

  Summary:
    This file contains the source code for the MPLAB Harmony application for security functions.

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
/*
    (c) 2021 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app_sec.h"
#include <stdio.h>
#include "app_transfer.h"
#include "cryptoauthlib.h"
#include "security.h"


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
    This structure should be initialized by the APP_SEC_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_SEC_DATA app_secData;
APP_TRANSFER_DATA app_transfer_Data;
extern ATCAIfaceCfg atecc608_0_init_data;
extern uint8_t num_in[20];
extern uint8_t rand_out[32];
uint8_t ECC_Ack = 1;

bool secure_check_device_type_in_cfg(void)
{
    ATCAIfaceCfg *cfg;
    ATCA_STATUS status;
    cfg = &atecc608_0_init_data;
    if (ATCA_SUCCESS != (status = check_device_type_in_cfg(cfg, false)))
    {
       //ATCAB init fail
        return 0;
    }
        
    else
    {
      //ATCAB init success
        return true;
    }
}

bool secure_atcab_init(void)
{
    uint8_t io_protect=6;
    uint8_t slot_num=5;
    ATCA_STATUS status;
    ATCAIfaceCfg *cfg = &atecc608_0_init_data;
 
    if (ATCA_SUCCESS != (status = atcab_init(cfg)))
    {
      return 0;
    }
    else
    {   
        if(ATCA_SUCCESS != (status= slot_write(io_protect))){
          //Slot not written
            return 0;
        }
        else{
        if (ATCA_SUCCESS !=(status = atcab_nonce_rand(num_in, rand_out)))
        {
            return 0;
        }
        else{
        if(ATCA_SUCCESS != (status = slot_write(slot_num))){
           //Slot not written
            return 0;
        }
        else
        return true;
        }
        }
    }
}

bool secure_generate_device_mac(void)
{
    uint8_t status;
    status = generate_device_mac();
    return status;
}


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
            if(secure_check_device_type_in_cfg())
            {              
                if (secure_atcab_init()) 
                {
                    app_secData.state = APP_SEC_STATE_SERVICE_TASKS;                    
                }
                else
                {
                    /*No secure element*/
                    ECC_Ack = 0;
                                          
                }
               
            }
            else
            { 
                /*No secure element*/
                ECC_Ack = 0;                                      
                
            }

                break;
        }
          
        
        
        case APP_SEC_STATE_GENERATE_DEVICE_MAC:{

            if(secure_generate_device_mac())
            {
                              
            }
            else{
            app_secData.state = APP_SEC_STATE_SERVICE_TASKS;
            app_transfer_Data.state = APP_STATE_TRANSMIT_AUTH_DATA;                       
            }
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
