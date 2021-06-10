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
// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END
// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "fan_click.h"
#include "../src/ble/non_gui/ble.h"
#include "definitions.h"
#include "stdio.h"

extern BLE_DATA bleData;

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
//dynamic_modes_t dynamic_modes;
// *****************************************************************************
volatile    bool    button_pressed = false;
volatile    bool    i2cBufferCompleteEvent;

// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************
static void I2CBufferEventHandler(uintptr_t context)
{        
    if (SERCOM0_I2C_ErrorGet() == SERCOM_I2C_ERROR_NONE)
    {
        i2cBufferCompleteEvent = true;
    }
}

static void EIC_Button_Handler(uintptr_t context)
{
    button_pressed = ((button_pressed + 1) & 0x01);
    if(button_pressed == false)
    {
        strcpy(appData.BLE_Cmd_buf, (char *)"FAN_OFF");
    }
    else
    {
        strcpy(appData.BLE_Cmd_buf, (char *)"FAN_ON");
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
    DRV_BM71_Initialize();
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;

    EIC_CallbackRegister(EIC_PIN_15, EIC_Button_Handler, 0);
    bleInitialize(true);
    SERCOM0_I2C_CallbackRegister(I2CBufferEventHandler, 0);

    SYSTICK_TimerStart();
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
    DRV_BM71_Tasks();
    bleTasks(); 

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            SYSTICK_DelayMs(100);
            fan_click_init();
            fan_click_set_target_tach(0x1);
            SYSTICK_DelayMs(100);  
            strcpy(appData.BLE_Cmd_buf, (char *)"FAN_ON");
            appData.state = APP_STATE_SERVICE_TASKS;
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
            if(!strcmp(appData.BLE_Cmd_buf, "FAN_ON"))
            {
                fan_click_set_target_tach(0xBF);    // Fans rotates slow
                memset(appData.BLE_Cmd_buf, 0x00, 100);
            }
            else if(!strcmp(appData.BLE_Cmd_buf, "FAN_LOW"))
            {
                fan_click_set_target_tach(0xBF);    // Fans rotates slow
                memset(appData.BLE_Cmd_buf, 0x00, 100);
            }
            else if(!strcmp(appData.BLE_Cmd_buf, "FAN_MID"))
            {
                fan_click_set_target_tach(0x7F);    //  Rotates normally
                memset(appData.BLE_Cmd_buf, 0x00, 100);
            }
            else if(!strcmp(appData.BLE_Cmd_buf, "FAN_HIGH"))
            {
                fan_click_set_target_tach(0x01);    // Fans rotates Fastly
                memset(appData.BLE_Cmd_buf, 0x00, 100);
            }
            else if(!strcmp(appData.BLE_Cmd_buf, "FAN_OFF"))
            {
                fan_click_set_target_tach(0x00);    // Zero internally sends 0XFF, switch off's the fan
                memset(appData.BLE_Cmd_buf, 0x00, 100);
            }
            else
            {
                ;
            }
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
