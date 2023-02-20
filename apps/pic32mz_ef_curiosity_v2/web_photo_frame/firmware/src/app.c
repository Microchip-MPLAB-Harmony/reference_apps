/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "app_file_handler.h"

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
    // initialize the app state to wait for media attach.
    appData.state = APP_STATE_MEDIA_UNMOUNTED;
    
    // set the delay tick
    appData.delayTick = 0;
    
    // initialize the media handler
    APP_FileHandler_Initialize();
    
    return;
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */
void APP_Tasks ( void )
{
    // check for the media if it is mounted
    if (APP_FileHandler_IsMediaMounted() == false) {
        // change state
        appData.state = APP_STATE_MEDIA_UNMOUNTED;
    }
    
    // application state machine switch
    switch(appData.state)
    {
        case APP_STATE_MEDIA_UNMOUNTED:
        {
            LED1_On();
            LED2_Off();
            LED3_Off();
            
            // wait for the media to be mounted
            if (APP_FileHandler_IsMediaMounted() == true) {
                // change state
                appData.state = APP_STATE_MEDIA_MOUNTED;
            }
            break;
        }
        
        case APP_STATE_MEDIA_MOUNTED:
        {    
            LED1_Off();
            LED2_On();
            LED3_Off();
            
            // gather the media from the SD Card
            // the function should be called till it returns true            
            if (APP_FileHandler_GatherAvailableMedia() == true) {
                // change state
                appData.state = APP_GOING_ON;
            }
            
            break;
        }
        
        case APP_GOING_ON:
        {
            LED1_Off();
            LED2_On();
            
            if (APP_FileHandler_GetNumberOfMediaFiles() == 0) {
                // no media available to play
                LED1_On();
            } else {
                // blink LED 3
                if(SYS_TMR_TickCountGet() - appData.delayTick >= SYS_TMR_TickCounterFrequencyGet()/2ul)
                {
                    LED3_Toggle();

                    // update the tick to current value
                    appData.delayTick = SYS_TMR_TickCountGet();
                }
            }
            break;
        }

        default:
        {
            break;
        }
    }

// a bit of debugging
#ifdef APP_DEBUG_MEMORY
    static uint32_t debugDelayTick = 0;
    if(SYS_TMR_TickCountGet() - debugDelayTick >= SYS_TMR_TickCounterFrequencyGet() * APP_DEBUG_MEMORY_DELAY_SEC)
    {
        SYS_CONSOLE_PRINT("    HEAP DEBUG: FreeRTOS minimum heap remaining: %d\r\n", xPortGetMinimumEverFreeHeapSize());

        SYS_CONSOLE_PRINT("    HEAP DEBUG: APP Task used stack: %d\r\n", uxTaskGetStackHighWaterMark(NULL));

        // update the tick to current value
        debugDelayTick = SYS_TMR_TickCountGet();
    }
#endif
    return;
}

/* EOF */
