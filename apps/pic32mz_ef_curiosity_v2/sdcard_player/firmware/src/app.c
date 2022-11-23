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

#include "bsp/bsp.h"
#include "app.h"
#include "app_sdcard_audio_task.h"
#include "app_display_task.h"


APP_DATA appData;

SYS_TIME_HANDLE tmr_audio_handle;

void APP_Initialize(void) {
    
    appData.state = APP_STATE_INIT;

    EXTERNAL_INT_RISING_SET();

    EVIC_ExternalInterruptEnable(EXTERNAL_INT_3);

    appData.streamSource = APP_STREAMING_SOURCE_SDCARD;

    APP_OFF_RGB_LED();

    APP_SDCARD_AUDIO_Initialize();
    
    APP_SDCARD_AUDIO_RegisterStreamSource(APP_StreamSourceGet);

    APP_SDCARD_READER_Initialize();

    APP_DISPLAY_Initialize();

}

void APP_Tasks(void) {


    switch (appData.state) {

        case APP_STATE_INIT:
        {
            
            EVIC_ExternalInterruptCallbackRegister(EXTERNAL_INT_3, APP_SDCARD_AUDIO_SDCard_Removed_Detection_Callback, (uintptr_t) NULL);
    
                    appData.state = APP_STATE_SERVICE_TASKS;

                break;
            
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
            APP_SDCARD_READER_Tasks();
            
            APP_DISPLAY_Screens_Task();
            
            APP_SDCARD_AUDIO_Tasks();

            break;
        }

        default:
        {

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

/*******************************************************************************
 End of File
 */
