/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app_display_task.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#ifndef _APP_DISPLAY_H
#define _APP_DISPLAY_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "definitions.h"
#include "configuration.h"


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
    // DOM-IGNORE-END


#define APP_DISPLAY_MUSIC_LIST_WIDGET MusicScreen_ListWheelWidget0

#define APP_DISPLAY_MUSIC_VOLUME_CONTROL MusicScreen_volumecontrol

#define APP_DISPLAY_MUSCI_PLAY_PAUSE_BUTTON MusicScreen_PlayPausebutton

#define APP_DISPLAY_MUSIC_USB_MSD_IMG_WIDGET default_USB_MSD_Icon

#define APP_DISPLAY_MUSIC_INSERT_SDCARD_LABEL default_InsertSDcardLabel

#define APP_DISPLAY_WHEEL_WIDGET_TEXT_FONT Arial

    typedef enum {
        APP_DISPLAY_STATE_MUSIC_SCREEN_STATE = 0,

        APP_DISPLAY_STATE_USB_MSD_STATE,

        APP_DISPLAY_STATE_START_SCREEN,


    } APP_DISPLAY_STATE;

    typedef struct {
        bool usb_msd_configured;

        uint8_t app_display_task_state;

        bool sdcard_msd_updated;

        bool msd_attached;

        bool sdcard_attached;

    } APP_DISPLAY_OBJ;


    APP_DISPLAY_OBJ app_display_state;

    void APP_SDCARD_READER_Initialize(void);

    void APP_SDCARD_READER_Tasks(void);

    void APP_DISPLAY_FillSongListFromSDCard();

    void APP_DISPLAY_Screens_Task();

    void APP_DISPLAY_Initialize();

#endif

    //DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

