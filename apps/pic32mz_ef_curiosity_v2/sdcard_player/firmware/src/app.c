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
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

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


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "bsp/bsp.h"
#include "app.h"

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

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************
static void _APP_BUTTON_PRESS_Initialize(void);
static void _APP_BUTTON_PRESS_DebounceTimerHandler ( uintptr_t context);
static void _APP_BUTTON_PRESS_Tasks(void);

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
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;

    appData.streamSource = APP_STREAMING_SOURCE_SDCARD;

    APP_OFF_RGB_LED();
    APP_SDCARD_AUDIO_SRC_ON();

    APP_SDCARD_AUDIO_Initialize();
    APP_SDCARD_AUDIO_RegisterStreamSource(APP_StreamSourceGet);

    _APP_BUTTON_PRESS_Initialize();
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;


            if (appInitialized)
            {
                if(
                        //SYS_TMR_CallbackPeriodic ( 250, 1, _APP_BUTTON_PRESS_DebounceTimerHandler )                       
                SYS_TIME_CallbackRegisterMS(_APP_BUTTON_PRESS_DebounceTimerHandler, (uintptr_t)1, 250, SYS_TIME_PERIODIC)                     
                    == SYS_TIME_HANDLE_INVALID)
                {
                    // Try again to get handle
                }
                else
                {
                    appData.state = APP_STATE_SERVICE_TASKS;
                }
                break;
            }
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
            APP_SDCARD_AUDIO_Tasks();

            _APP_BUTTON_PRESS_Tasks();

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


 void APP_StreamSourceSet(APP_STREAMING_SOURCE streamSrc)
 {
     appData.streamSource = streamSrc;
 }

 APP_STREAMING_SOURCE APP_StreamSourceGet(void)
{
    return appData.streamSource;
}

static void _APP_BUTTON_PRESS_Initialize(void)
{
    appData.ignoreButtonPress = false;
    appData.tmrEventHasOccurred = false;
}

static void _APP_BUTTON_PRESS_Tasks(void)
{
    if(SWITCH1_STATE_PRESSED == SWITCH1_Get())
    {
        if(appData.ignoreButtonPress)
        {
            if(appData.tmrEventHasOccurred)
            {
                appData.tmrEventHasOccurred = false;

                APP_SDCARD_AUDIO_NextTrackSet();
                APP_TRACK_CHANGE_INDICATE();

                appData.ignoreButtonPress = false;
            }
        }
        else
        {
            appData.ignoreButtonPress = true;
        }
    }
    else
    {
        /* No key press. Reset all the indicators. */
        appData.ignoreButtonPress = false;
        appData.tmrEventHasOccurred = false;
    }
}

static void _APP_BUTTON_PRESS_DebounceTimerHandler ( uintptr_t context)
{
    appData.tmrEventHasOccurred = true;
}

/*******************************************************************************
 End of File
 */
