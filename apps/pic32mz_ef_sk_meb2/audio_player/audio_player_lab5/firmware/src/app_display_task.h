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
Copyright (c) 2016-2017 released Microchip Technology Inc.  All rights reserved.

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
//DOM-IGNORE-END

#ifndef _APP_DISPLAY_TASK_H    /* Guard against multiple inclusion */
#define _APP_DISPLAY_TASK_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "definitions.h"
#include "driver\usb\drv_usb_external_dependencies.h"

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */


/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


#define APP_DISPLAY_VOLUME_MAX                          (255)

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

typedef enum
{
	/* Application's state machine's initial state. */
    APP_DISPLAY_MODE_UNCHANGED = -1,

	/* TODO: Define states used by the application state machine. */
    APP_DISPLAY_MODE_CHANGED_SDCARD_PLAYBACK = 0,

    APP_DISPLAY_MODE_CHANGED_SDCARD_READER = 1

} APP_DISPLAY_MODE;

typedef enum
{
    APP_DISPLAY_VOLUME_MUTE_UNCHANGED = -1,
    APP_DISPLAY_VOLUME_MUTE_ON = 0,
    APP_DISPLAY_VOLUME_MUTE_OFF = 1,
    APP_DISPLAY_VOLUME_MUTE_INCREASE_DECREASE = 2
} APP_DISPLAY_VOLUME_MUTE;


typedef struct
{
    /* The application's current state */
    volatile APP_DISPLAY_MODE displayMode;

    volatile APP_DISPLAY_VOLUME_MUTE volumeMute;
    uint16_t currentTrackId;

    SYS_TIME_HANDLE debounceTmrHandle;

} APP_DISPLAY_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************
void APP_DISPLAY_Initialize(void);
void APP_DISPLAY_Tasks(void);
int8_t *APP_DISPLAY_GetFileName(const int8_t *path);
void APP_DISPLAY_ModeSet(APP_DISPLAY_MODE appMode);
void APP_DISPLAY_VolumeMuteChange(APP_DISPLAY_VOLUME_MUTE volMuteChange);
void APP_DISPLAY_UpdateTrackList(void);
int32_t APP_DISPLAY_XlatTrackIdx(uint32_t trackidx);
int32_t APP_DISPLAY_XlatListIdx(uint32_t listidx);
void APP_DISPLAY_ScrollUp(void);
void APP_DISPLAY_ScrollDown(void);


    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _APP_DISPLAY_TASK_H */

/* *****************************************************************************
 End of File
 */
