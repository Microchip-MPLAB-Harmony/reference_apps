/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

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
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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
// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <string.h>
#include "app.h"        // also beings in app_tone_lookup_table.h
#include "../src/ble/non_gui/ble.h"
extern BLE_DATA bleData;
extern volatile bool cmd_sent;
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

APP_DATA appData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/// *****************************************************************************
 /*
  Function:
        static void App_TimerCallback
        (
            uintptr_t context
        )

  Summary:
    Implements the handler for timer callback function.

  Description:
    Called every 1 ms by timer services.  It then decrements WM8904Delay if
    non-zero.

  Parameters:
    context      - Contains index into driver's instance object array

  Remarks:
    None
*/
static void App_TimerCallback( uintptr_t context)
{    
    if (appData.waitingToConnect)
    {
        appData.waitingToConnectTimer++;
        if ((appData.waitingToConnectTimer & 0xFF) == 0)    // about every 1/4 second
        {
            LED1_Toggle();
        }
    }
}

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
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */
void APP_Initialize ( void )
{
    /* TODO: Initialize your application's state machine and other
     * parameters.
     */   

	LED1_On();       // initially on, until connected
    appData.state = APP_STATE_INIT;   

    appData.queryDelay = 0;         // used for status queries

    appData.waitingToConnect = false;
    appData.waitingToConnectTimer = 0;

    bleInitialize(true);
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */
DRV_HANDLE tmrHandle;

void APP_Tasks ( void )
{    
    bleTasks(); 
    
    /* Check the application's current state. */
    switch ( appData.state )
    {       
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            /* Open the timer Driver */
            tmrHandle = SYS_TIME_CallbackRegisterMS(App_TimerCallback, 
                    (uintptr_t)0, 1/*ms*/, SYS_TIME_PERIODIC);

            if ( SYS_TIME_HANDLE_INVALID != tmrHandle )
            {
               appData.state = APP_STATE_WAIT_INIT;
            }            
        }
        break;
        
        case APP_STATE_WAIT_INIT:
        {
            if (DRV_BT_STATUS_READY == DRV_BT_GetPowerStatus())
            {           
                appData.state=APP_STATE_IDLE;
            }
        }
        break;
        
        // Initialized 
        case APP_STATE_IDLE:
        {
            APP_Sensor_Tasks();
            
            if (appData.queryDelay == 0)
            {
                DRV_BT_BLE_QueryStatus(bleData.bt.handle);
                appData.queryDelay = QUERY_DELAY;
            }
		}
		break;
         
        default:
        {
            /* TODO: Handle error in application's state machine. */
        }
        break;             
    }
}
volatile bool gyro_request = 0 ,environment_request = 0,cmd_successfull = 0,rotation_vector_request = 0;
volatile bool accel_request = 0;
void APP_Sensor_Tasks()
{
acc_sensor_t accel_xyz_data = {0};   
gyro_sensor_t gyro_xyz_data = {0};
quaternion_sensor_t quaternion_wxyz_data = {0};

 if((cmd_successfull == 1) || (cmd_sent == 0))
 {
    if(cmd_successfull == 1){
        cmd_successfull = 0;
    }   
    if(gyro_request){   
        bno055_read_gyro_xyz(&gyro_xyz_data);
        printgyro(&gyro_xyz_data);
        SYSTICK_DelayMs(200);
    }else if(accel_request){       
        bno055_read_accel_xyz(&accel_xyz_data);
        printaccel(&accel_xyz_data);
        SYSTICK_DelayMs(200);
    }else if(environment_request){
        read_bno055_pth_value();
        SYSTICK_DelayMs(20);  
    }else if(rotation_vector_request){
        bno055_read_quaternion_wxyz(&quaternion_wxyz_data);
        printquaternion(&quaternion_wxyz_data);
        SYSTICK_DelayMs(500);
        
    }
 }
}

/*******************************************************************************
 End of File
 */
