/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_nonsecure_deadbolt_control.c

  Summary:
    Source code for deadbolt control.

  Description:
    This file contains the source code for the application's deadbolt control.  It
    implements the logic of the application's deadbolt control and calls
    API routines of other MPLAB Harmony modules in the system such as external interrupts, TCC and SysTime.
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

#include "app_nonsecure_deadbolt_control.h"
#include "trustZone/nonsecure_entry.h"

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_NONSECURE_DEADBOLT_CONTROL_Callback(uintptr_t context)

  Remarks:
    See prototype in app_nonsecure_db_motor.h.
 */
void APP_NONSECURE_DEADBOLT_CONTROL_Callback(uintptr_t context)
{
     switch (context)
    {
        case APP_NONSECURE_DEADBOLT_CONTROL_DOOR_OPENED:
        {
#if LIMIT_SW_USED
           if (LIMIT_SW_SIG1_PIN_Get() == 0)
            {
#endif
                EIC_InterruptDisable(EIC_PIN_3);
                ENABLE_6V_Clear();
                TCC0_PWM24bitDutySet(TCC0_CHANNEL3, 0);
                SYS_TIME_CallbackRegisterMS(APP_NONSECURE_DEADBOLT_CONTROL_Callback, APP_NONSECURE_DEADBOLT_CONTROL_DOOR_OPEN_TIMEOUT, 15000, SYS_TIME_SINGLE);
                if(app_db_motorData.sys_time_handle != SYS_TIME_HANDLE_INVALID)
                {
                    SYS_TIME_TimerStop(app_db_motorData.sys_time_handle);
                    SYS_TIME_TimerDestroy(app_db_motorData.sys_time_handle);
                }
                app_db_motorData.door_state = APP_NONSECURE_DEADBOLT_CONTROL_DOOR_OPENED;
                
               if (APP_NONSECURE_ENTRY_BLE_IsModuleConnected() == true)
                {
                    APP_NONSECURE_ENTRY_UpdateDoorStatus(false);
                }
#if LIMIT_SW_USED
           }
#endif
            break;
        }
        
        case APP_NONSECURE_DEADBOLT_CONTROL_DOOR_CLOSED:
        {
#if LIMIT_SW_USED
            if (LIMIT_SW_SIG2_PIN_Get() == 0)
            {
#endif
                EIC_InterruptDisable(EIC_PIN_4);
                ENABLE_6V_Clear();
                TCC0_PWM24bitDutySet(TCC0_CHANNEL2, 0);
                if(app_db_motorData.sys_time_handle != SYS_TIME_HANDLE_INVALID)
                {
                    SYS_TIME_TimerStop(app_db_motorData.sys_time_handle);
                    SYS_TIME_TimerDestroy(app_db_motorData.sys_time_handle);
                }
                app_db_motorData.door_state = APP_NONSECURE_DEADBOLT_CONTROL_DOOR_CLOSED;
                if (APP_NONSECURE_ENTRY_BLE_IsModuleConnected() == true)
                {
                    APP_NONSECURE_ENTRY_UpdateDoorStatus(true);
                }
#if LIMIT_SW_USED
            }
#endif
            break;
        }
        
        case APP_NONSECURE_DEADBOLT_CONTROL_DOOR_OPEN_TIMEOUT:
        {
            app_db_motorData.state = APP_NONSECURE_DEADBOLT_CONTROL_STATE_CLOSE;
            break;
        }

        case APP_NONSECURE_DEADBOLT_CONTROL_DOOR_UNDEFINED:
        {
           EIC_InterruptDisable(EIC_PIN_3);
           EIC_InterruptDisable(EIC_PIN_4);
           
           ENABLE_6V_Clear();
           TCC0_PWM24bitDutySet(TCC0_CHANNEL2, 0);
           TCC0_PWM24bitDutySet(TCC0_CHANNEL3, 0);
           app_db_motorData.door_state = APP_NONSECURE_DEADBOLT_CONTROL_DOOR_UNDEFINED;
           app_db_motorData.state = APP_NONSECURE_DEADBOLT_CONTROL_STATE_USERALERT;
           break;
        }

        default:
            break;
    }
}


// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/*******************************************************************************
  Function:
    void APP_NONSECURE_DEADBOLT_CONTROL_MotorOpen ( void )

  Remarks:
    See prototype in app_nonsecure_db_motor.h.
 */

void APP_NONSECURE_DEADBOLT_CONTROL_MotorOpen ( void )
{ 
    /* Start PWM*/
    TCC0_PWM24bitDutySet(TCC0_CHANNEL3, 800);
    /* Fallback in case of obstruction */
    app_db_motorData.sys_time_handle = SYS_TIME_CallbackRegisterMS(APP_NONSECURE_DEADBOLT_CONTROL_Callback, APP_NONSECURE_DEADBOLT_CONTROL_DOOR_UNDEFINED, 1500, SYS_TIME_SINGLE);
}

/*******************************************************************************
  Function:
    void APP_NONSECURE_DEADBOLT_CONTROL_MotorClose ( void )

  Remarks:
    See prototype in app_nonsecure_db_motor.h.
 */

void APP_NONSECURE_DEADBOLT_CONTROL_MotorClose ( void )
{
    /* Start PWM*/
    TCC0_PWM24bitDutySet(TCC0_CHANNEL2, 800);
    /* Fallback in case of obstruction */
    app_db_motorData.sys_time_handle = SYS_TIME_CallbackRegisterMS(APP_NONSECURE_DEADBOLT_CONTROL_Callback, APP_NONSECURE_DEADBOLT_CONTROL_DOOR_UNDEFINED, 1500, SYS_TIME_SINGLE);
}


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_NONSECURE_DEADBOLT_CONTROL_Initialize ( void )

  Remarks:
    See prototype in app_nonsecure_db_motor.h.
 */

void APP_NONSECURE_DEADBOLT_CONTROL_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_db_motorData.state = APP_NONSECURE_DEADBOLT_CONTROL_STATE_INIT;
    app_db_motorData.door_state = APP_NONSECURE_DEADBOLT_CONTROL_DOOR_UNDEFINED;

}


/******************************************************************************
  Function:
    void APP_NONSECURE_DEADBOLT_CONTROL_Tasks ( void )

  Remarks:
    See prototype in app_nonsecure_db_motor.h.
 */

void APP_NONSECURE_DEADBOLT_CONTROL_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( app_db_motorData.state )
    {
        /* Application's initial state. */
        
        case APP_NONSECURE_DEADBOLT_CONTROL_STATE_INIT:
        {  
            EIC_CallbackRegister(EIC_PIN_4, (EIC_CALLBACK)APP_NONSECURE_DEADBOLT_CONTROL_Callback, APP_NONSECURE_DEADBOLT_CONTROL_DOOR_CLOSED);
            EIC_CallbackRegister(EIC_PIN_3, (EIC_CALLBACK)APP_NONSECURE_DEADBOLT_CONTROL_Callback, APP_NONSECURE_DEADBOLT_CONTROL_DOOR_OPENED);
            
            EIC_InterruptDisable(EIC_PIN_3);
            EIC_InterruptDisable(EIC_PIN_4);
            
            TCC0_PWM24bitDutySet(TCC0_CHANNEL2, 0);
            TCC0_PWM24bitDutySet(TCC0_CHANNEL3, 0);
            
            /* Start PWM with 0 duty cycle*/
            TCC0_PWMStart();

            app_db_motorData.state = APP_NONSECURE_DEADBOLT_CONTROL_STATE_WAIT;
            
#if LIMIT_SW_USED
            if(LIMIT_SW_SIG1_PIN_Get() == 0)
            { 
                app_db_motorData.door_state = APP_NONSECURE_DEADBOLT_CONTROL_DOOR_OPENED;
                app_db_motorData.state = APP_NONSECURE_DEADBOLT_CONTROL_STATE_CLOSE;
            }

            else if (LIMIT_SW_SIG2_PIN_Get() == 0)
            {
               app_db_motorData.door_state = APP_NONSECURE_DEADBOLT_CONTROL_DOOR_CLOSED;
            }
#endif
            break;
        }       
        

        case APP_NONSECURE_DEADBOLT_CONTROL_STATE_OPEN:
        {
        if(app_db_motorData.door_state != APP_NONSECURE_DEADBOLT_CONTROL_DOOR_OPENED)
            {   
                #if LIMIT_SW_USED
                EIC_InterruptEnable(EIC_PIN_3);
                #endif
                ENABLE_6V_Set();
                APP_NONSECURE_DEADBOLT_CONTROL_MotorOpen(); 
                LED_Clear();
            }

            app_db_motorData.state = APP_NONSECURE_DEADBOLT_CONTROL_STATE_WAIT;
            break;
        }
        
        case APP_NONSECURE_DEADBOLT_CONTROL_STATE_CLOSE:
        {
            if(app_db_motorData.door_state != APP_NONSECURE_DEADBOLT_CONTROL_DOOR_CLOSED)
            {
                #if LIMIT_SW_USED
                EIC_InterruptEnable(EIC_PIN_4);
                #endif
                ENABLE_6V_Set();
                APP_NONSECURE_DEADBOLT_CONTROL_MotorClose(); 
                LED_Set();
            }
            
            app_db_motorData.state = APP_NONSECURE_DEADBOLT_CONTROL_STATE_WAIT;
            break;
        }
        
        case APP_NONSECURE_DEADBOLT_CONTROL_STATE_UPDATE_STATUS_TO_APP:
        {
            if(app_db_motorData.door_state == APP_NONSECURE_DEADBOLT_CONTROL_DOOR_OPENED)
            {
                if (APP_NONSECURE_ENTRY_BLE_IsModuleConnected() == true)
                {
                    APP_NONSECURE_ENTRY_UpdateDoorStatus(false);
                }
            }
            
            else if(app_db_motorData.door_state == APP_NONSECURE_DEADBOLT_CONTROL_DOOR_CLOSED)
            {
                if (APP_NONSECURE_ENTRY_BLE_IsModuleConnected() == true)
                {
                    APP_NONSECURE_ENTRY_UpdateDoorStatus(true);
                }
            }
            app_db_motorData.state = APP_NONSECURE_DEADBOLT_CONTROL_STATE_WAIT;
            break;
        }
        
        case APP_NONSECURE_DEADBOLT_CONTROL_STATE_USERALERT:
        {
  //#         Buzzer_On(500); //Set Buzzer to alert user
            break;
        }

        case APP_NONSECURE_DEADBOLT_CONTROL_STATE_WAIT:
        {
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
