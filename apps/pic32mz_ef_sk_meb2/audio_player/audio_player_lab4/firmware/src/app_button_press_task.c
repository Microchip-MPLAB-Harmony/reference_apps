/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_button_press_task.c

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
Copyright (c) 2015-2016 released Microchip Technology Inc.  All rights reserved.

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

#include "app_button_press_task.h"
#include "app_sdcard_reader_task.h"
void APP_SDCARD_AUDIO_Initialize(void); 
void APP_SDCARD_AUDIO_SuspendStreaming(void);

static APP_BUTTON_PRESS_TASK_DATA appButtonData;

void APP_BUTTON_PRESS_Initialize(void)
{
	appButtonData.state = APP_BUTTON_PRESS_TASK_STATE_INIT;
    appButtonData.ignoreButtonPress = false;
    appButtonData.tmrEventHasOccurred = false;
    appButtonData.debounceTmrHamdle = SYS_TIME_HANDLE_INVALID;
    
    APP_SetMode(APP_MODE_SD_CARD_PLAYBACK);
    /* Indicate application is in SD Card playback mode*/
     LED_D7_On();
}

static void _APP_BUTTON_PRESS_DebounceTimerHandler ( uintptr_t context )
{
    appButtonData.tmrEventHasOccurred = true;
}

void APP_BUTTON_PRESS_Tasks(void)
{
    switch(appButtonData.state)
    {
        case APP_BUTTON_PRESS_TASK_STATE_INIT:
            appButtonData.debounceTmrHamdle = SYS_TIME_CallbackRegisterMS( _APP_BUTTON_PRESS_DebounceTimerHandler, (uintptr_t)0, 250, SYS_TIME_PERIODIC );
            if(SYS_TIME_HANDLE_INVALID == appButtonData.debounceTmrHamdle)
            {
                appButtonData.state = APP_BUTTON_PRESS_TASK_STATE_ERROR;
            }
            else
            {
                appButtonData.state = APP_BUTTON_PRESS_TASK_STATE_POLL;
            }
            break;
        case APP_BUTTON_PRESS_TASK_STATE_POLL:
            if(SWITCH_S1_STATE_PRESSED == SWITCH_S1_Get())
            {
                if(appButtonData.ignoreButtonPress)
                {
                    if(appButtonData.tmrEventHasOccurred)
                    {
                        appButtonData.tmrEventHasOccurred = false;
                        if(APP_MODE_SD_CARD_PLAYBACK == APP_GetMode())
                        {
                            LED_D7_Off();
                            APP_SDCARD_AUDIO_SuspendStreaming();
                            APP_SDCARD_READER_AttachDevice();
                            APP_SetMode(APP_MODE_SD_CARD_READER);
                            /* Indicate application is in USB SD card reader mode*/
                            LED_D6_On();
                        }
                        else
                        {
                            LED_D6_Off();
                            APP_SDCARD_READER_DetachDevice();
                            APP_SDCARD_AUDIO_Initialize();
                            APP_SetMode(APP_MODE_SD_CARD_PLAYBACK);
                            /* Indicate application is in SD card playback mode*/
                            LED_D7_On();
                        }
                        appButtonData.ignoreButtonPress = false;
                    }
                }
                else
                {
                    appButtonData.ignoreButtonPress = true;
                }
            }
            else
            {
                /* No key press. Reset all the indicators. */
                appButtonData.ignoreButtonPress = false;
                appButtonData.tmrEventHasOccurred = false;
            }
            break;
        case APP_BUTTON_PRESS_TASK_STATE_ERROR:
            break;
        default:
            break;
    }


}
