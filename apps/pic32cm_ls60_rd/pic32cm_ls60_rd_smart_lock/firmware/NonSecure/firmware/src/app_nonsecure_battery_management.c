/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_bat_mgmt.c

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

#include "app_nonsecure_battery_management.h"
#include "definitions.h"
#include "trustZone/nonsecure_entry.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************

#define ADC_VREF                (2.4f)

// *****************************************************************************
// *****************************************************************************
// Section: External variables
// *****************************************************************************
// *****************************************************************************

extern volatile uint8_t time_to_measure_touch_var;
extern volatile bool BLE_CONNECTED;
extern APP_NONSECURE_DEADBOLT_CONTROL_DATA app_db_motorData;

// *****************************************************************************
// *****************************************************************************
// Section: Global Variables
// *****************************************************************************
// *****************************************************************************
volatile bool Wakeup = false;

/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_NONSECURE_BATTERY_MANAGEMENT_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_NONSECURE_BATTERY_MANAGEMENT_DATA app_bat_mgmtData;



// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/
void adc_cb(ADC_STATUS status, uintptr_t context )
{
    app_bat_mgmtData.bat_low_det = true;
    app_bat_mgmtData.adc_result = ADC_ConversionResultGet();
    //APP_DebugPrintf("\r\n ADC Result = %d",app_bat_mgmtData.adc_result);
}
// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

void nonsecure_PeripheralDisable(void)
{
    TC1_TimerStop();
    TCC0_PWMStop();
}


void APP_NONSECURE_BATTERY_MANAGEMENT_LowPowerEnter(void)
{
    nonsecure_PeripheralDisable();
    APP_NONSECURE_ENTRY_SleepPrepare();
    APP_NONSECURE_ENTRY_StandbyEnter();
    TC1_TimerStart();
    TCC0_PWMStart();
}


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_NONSECURE_BATTERY_MANAGEMENT_Initialize ( void )

  Remarks:
    See prototype in app_nonsecure_battery_management.h.
 */

void APP_NONSECURE_BATTERY_MANAGEMENT_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_bat_mgmtData.state = APP_NONSECURE_BATTERY_MANAGEMENT_STATE_INIT;
    app_bat_mgmtData.adc_result = 0;
    app_bat_mgmtData.bat_low_det = false;

    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void APP_NONSECURE_BATTERY_MANAGEMENT_Tasks ( void )

  Remarks:
    See prototype in app_nonsecure_battery_management.h.
 */

void APP_NONSECURE_BATTERY_MANAGEMENT_Tasks ( void )
{
    /* Check the application's current state. */
    switch ( app_bat_mgmtData.state )
    {
        /* Application's initial state. */
        case APP_NONSECURE_BATTERY_MANAGEMENT_STATE_INIT:
        {
            ADC_Enable();
            app_bat_mgmtData.state = APP_NONSECURE_BATTERY_MANAGEMENT_STATE_LOW_POWER;
            break;
        }

        case APP_NONSECURE_BATTERY_MANAGEMENT_STATE_SERVICE_TASKS:
        {

           if(app_bat_mgmtData.bat_low_det == true)
            {
                /****Battery Low***/
               while(1)
               {
                  LED_Toggle();  //PB02
               }
               /* TODO: Take further action */               
            }
            break;
        }
        
        case APP_NONSECURE_BATTERY_MANAGEMENT_STATE_MEASUREMENT:
        {         
            
             /* Start ADC conversion */
            ADC_ConversionStart();

            /* Wait till ADC conversion result is available */
            while(!ADC_ConversionStatusGet())
            {

            };

            /* Read the ADC result */
            app_bat_mgmtData.adc_result = ADC_ConversionResultGet();
            app_bat_mgmtData.input_voltage = (float)app_bat_mgmtData.adc_result * ADC_VREF / 4095U;
            
            APP_NONSECURE_ENTRY_UpdateBatteryStatus(app_bat_mgmtData.input_voltage);
            app_bat_mgmtData.state = APP_NONSECURE_BATTERY_MANAGEMENT_STATE_LOW_POWER;
        }
            
        
        case APP_NONSECURE_BATTERY_MANAGEMENT_STATE_LOW_POWER:
        {   
           /*Enter low power when WiFi is not in use*/
           #ifndef WIFI_ENABLE
            if ((APP_NONSECURE_ENTRY_BLE_IsModuleConnected() == false) && (APP_NONSECURE_ENTRY_GetLowPowerMeasurementStatus() ==  true) && app_db_motorData.door_state == APP_NONSECURE_DEADBOLT_CONTROL_DOOR_CLOSED)
            {
                RX_IND_LP_Set();
                APP_NONSECURE_BATTERY_MANAGEMENT_LowPowerEnter();
                RX_IND_LP_Clear();
            }
           #endif
            break;
        }


        /* TODO: implement your application state machine.*/


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
