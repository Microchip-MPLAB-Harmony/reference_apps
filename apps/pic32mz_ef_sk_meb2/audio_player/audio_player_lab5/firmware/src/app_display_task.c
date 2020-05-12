/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_display_task.c

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
// DOM-IGNORE-END

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include "app_display_task.h"
#include "app_sdcard_audio_task.h"
#include "app_sdcard_reader_task.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

#define SYS_TIMER_PERIODIC_CALLBACK_RATE_MSEC       5
#define VOLUME_SLIDER_DEBOUNCE_PERIOD               50
/*  A brief description of a section can be given directly below the section
    banner.
 */
APP_DISPLAY_DATA AppDisplayData;
static bool isUpdateTrackList = false;
static bool AppDisplayDataIsListPopulated = false;
static uint32_t scrollBarPosition;
static uint32_t scrollBarDefaultPosition;
bool volumeSliderChangeInProgress = false;
uint16_t volatile volumeSliderDebounceCounter = 0;

uint16_t ScrollTrackId = 0;
uint16_t XlatOffset = 0;

/*
 * Forward declarations.
 */
static int8_t *_APP_DISPLAY_GetFileName(const int8_t *path);
static void _APP_DISPLAY_HandleMuteOn(void);
static void _APP_DISPLAY_HandleMuteOff(void);
static uint8_t _APP_DISPLAY_HandleVolumeIncreaseDecrease(void);
static void _APP_DISPLAY_VolumeSlider_DebounceTimerHandler(uintptr_t context);


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void APP_DISPLAY_Initialize(void)
{
    AppDisplayData.displayMode = APP_DISPLAY_MODE_UNCHANGED;

    AppDisplayData.volumeMute = APP_DISPLAY_VOLUME_MUTE_UNCHANGED;

    AppDisplayData.debounceTmrHandle = SYS_TMR_HANDLE_INVALID;

    APP_SetMode(APP_MODE_SD_CARD_PLAYBACK);
}



///////////////////////////////////////////////////////////////////////////////
void APP_DISPLAY_Tasks(void)
{
    uint8_t defaultvolume;
    uint8_t volume;

    if (SYS_TMR_HANDLE_INVALID == AppDisplayData.debounceTmrHandle)
    {
        AppDisplayData.debounceTmrHandle = SYS_TIME_CallbackRegisterMS ( _APP_DISPLAY_VolumeSlider_DebounceTimerHandler, (uintptr_t)0, SYS_TIMER_PERIODIC_CALLBACK_RATE_MSEC, SYS_TIME_PERIODIC );
    }

    if(!laContext_IsDrawing())
    {
        if(true == isUpdateTrackList)
        {
            uint32_t index, ListIdx;
            APP_SDCARD_AUDIO_CARD_FILE_PATH *TablePointer;
            TablePointer = APP_SDCARD_AUDIO_GetFileTablePointer();

            /* Clear the Track List box and re-populate with new data */
            if (true == AppDisplayDataIsListPopulated)
            {
                laListWidget_RemoveAllItems(TrackListBox);
                laListWidget_AppendItem(TrackListBox);
            }

            if(true == APP_SDCARD_AUDIO_isSonglistAvailable())
            {
                XlatOffset = laListWidget_GetItemCount(TrackListBox);
                for (index = 0; index < (APP_SDCARD_AUDIO_FileCountGet()); index++)
                {
                    ListIdx = laListWidget_AppendItem(TrackListBox);
                    laListWidget_SetItemText(TrackListBox, ListIdx, laString_CreateFromCharBuffer((char *)_APP_DISPLAY_GetFileName(TablePointer[index].path), &Arial14pt));
                }

                AppDisplayData.currentTrackId =  APP_SDCARD_AUDIO_CurrentTrackIdGet();
                laListWidget_SetItemSelected(TrackListBox, APP_DISPLAY_XlatTrackIdx(AppDisplayData.currentTrackId), true);
                ScrollTrackId = AppDisplayData.currentTrackId;
                laListWidget_SetItemVisible(TrackListBox, APP_DISPLAY_XlatTrackIdx(ScrollTrackId));
                laWidget_SetVisible(&(TrackListBox->scrollbar->widget), false);
                
                AppDisplayDataIsListPopulated = true;
            }
            else
            {
                /* No tracks available. Disable Track List Box and the Scroll Up/Down Buttons */
                laWidget_SetEnabled(&(TrackListBox->widget), false);
                laWidget_SetEnabled(&(ScrollUpButton->widget), false);
                laWidget_SetEnabled(&(ScrollDownButton->widget), false);

                laTextFieldWidget_SetText(MessageTextBox, laString_CreateFromID(string_NoFilesMessage));
                laWidget_SetVisible(&(MessageTextBox->editWidget.widget), true);

                AppDisplayDataIsListPopulated = false;
            }

            defaultvolume = APP_SDCARD_AUDIO_VolumeGet();

            scrollBarPosition = ((laSliderWidget_GetMaxinumValue(VolSlider) * defaultvolume)/APP_DISPLAY_VOLUME_MAX);
            laSliderWidget_SetSliderValue(VolSlider, scrollBarPosition);
            scrollBarDefaultPosition = scrollBarPosition;

            isUpdateTrackList = false;

        }
    }

    if(AppDisplayData.displayMode!=APP_DISPLAY_MODE_UNCHANGED)
    {
        if(AppDisplayData.displayMode == APP_DISPLAY_MODE_CHANGED_SDCARD_PLAYBACK)
        {
            APP_SDCARD_READER_DetachDevice();
            APP_SDCARD_AUDIO_Initialize();
            APP_SetMode(APP_MODE_SD_CARD_PLAYBACK);
        }
        else if(AppDisplayData.displayMode == APP_DISPLAY_MODE_CHANGED_SDCARD_READER)
        {
            APP_SDCARD_AUDIO_SuspendStreaming();
            APP_SDCARD_READER_AttachDevice();
            APP_SetMode(APP_MODE_SD_CARD_READER);
        }
        else
        {

        }

        laSliderWidget_SetSliderValue(VolSlider, scrollBarDefaultPosition);
        laButtonWidget_SetPressed(VolButton, true);

        AppDisplayData.displayMode = APP_DISPLAY_MODE_UNCHANGED;
    }



    if(AppDisplayData.volumeMute != APP_DISPLAY_VOLUME_MUTE_UNCHANGED)
    {
        if(AppDisplayData.volumeMute == APP_DISPLAY_VOLUME_MUTE_ON)
        {
            APP_SDCARD_AUDIO_MuteOn();
            _APP_DISPLAY_HandleMuteOn();
        }
        else if(AppDisplayData.volumeMute == APP_DISPLAY_VOLUME_MUTE_OFF)
        {
            APP_SDCARD_AUDIO_MuteOff();
            _APP_DISPLAY_HandleMuteOff();
        }
        else if(AppDisplayData.volumeMute == APP_DISPLAY_VOLUME_MUTE_INCREASE_DECREASE)
        {
            volumeSliderDebounceCounter = 0;
            volumeSliderChangeInProgress = true;
        }
        else
        {
        }
        AppDisplayData.volumeMute = APP_DISPLAY_VOLUME_MUTE_UNCHANGED;
    }

    if (true == volumeSliderChangeInProgress && volumeSliderDebounceCounter > VOLUME_SLIDER_DEBOUNCE_PERIOD)
    {
        volume = _APP_DISPLAY_HandleVolumeIncreaseDecrease();

        APP_SDCARD_AUDIO_VolumeSet(volume);

        volumeSliderChangeInProgress = false;
        volumeSliderDebounceCounter = 0;
    }

    if(AppDisplayDataIsListPopulated == true)
    {
        if(AppDisplayData.currentTrackId != APP_SDCARD_AUDIO_CurrentTrackIdGet())
        {
            AppDisplayData.currentTrackId = APP_SDCARD_AUDIO_CurrentTrackIdGet();
            laListWidget_SetItemSelected(TrackListBox, APP_DISPLAY_XlatTrackIdx(AppDisplayData.currentTrackId), true);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
void APP_DISPLAY_ModeSet(APP_DISPLAY_MODE mode)
{
    AppDisplayData.displayMode = mode;
}

///////////////////////////////////////////////////////////////////////////////
void APP_DISPLAY_VolumeMuteChange(APP_DISPLAY_VOLUME_MUTE volMuteChange)
{
    AppDisplayData.volumeMute = volMuteChange;
}

///////////////////////////////////////////////////////////////////////////////
void APP_DISPLAY_UpdateTrackList(void)
{
    isUpdateTrackList = true;
}

// Translate track index to list box index
int32_t APP_DISPLAY_XlatTrackIdx(uint32_t trackidx)
{
    return (trackidx + XlatOffset);
}

// Translate list box index to track index
int32_t APP_DISPLAY_XlatListIdx(uint32_t listidx)
{
    if (listidx >= XlatOffset)
        listidx -= XlatOffset;
    return (listidx);
}

// Scroll up audio tracks (track values are 0 thru APP_SDCARD_AUDIO_FileCountGet()-1)
void APP_DISPLAY_ScrollUp(void)
{
    if (ScrollTrackId != 0)
    {
        ScrollTrackId--;
    }
    laListWidget_SetItemVisible(TrackListBox, APP_DISPLAY_XlatTrackIdx(ScrollTrackId));
    return;
}

// Scroll down audio tracks (track values are 0 thru APP_SDCARD_AUDIO_FileCountGet()-1)
void APP_DISPLAY_ScrollDown(void)
{
    int32_t FileCount = APP_SDCARD_AUDIO_FileCountGet();
    if (FileCount > 0)
    {
        if (ScrollTrackId < (FileCount - 1))
        {
            ScrollTrackId++;
        }
        else
        {
            ScrollTrackId = (FileCount - 1);
        }
        laListWidget_SetItemVisible(TrackListBox, APP_DISPLAY_XlatTrackIdx(ScrollTrackId));
    }
    return;
}

///////////////////////////////////////////////////////////////////////////////
static int8_t *_APP_DISPLAY_GetFileName(const int8_t *path)
{
    int8_t *filename = (int8_t*)strrchr((const char*)path, '/');
    if (filename == NULL)
        filename = (int8_t *)path;
    else
        filename++;
    return filename;
}

///////////////////////////////////////////////////////////////////////////////
static void _APP_DISPLAY_HandleMuteOn(void)
{
    laSliderWidget_SetSliderValue(VolSlider, 0);
}

///////////////////////////////////////////////////////////////////////////////
static void _APP_DISPLAY_HandleMuteOff(void)
{
    laSliderWidget_SetSliderValue(VolSlider, scrollBarPosition);
}

///////////////////////////////////////////////////////////////////////////////
static uint8_t _APP_DISPLAY_HandleVolumeIncreaseDecrease(void)
{
    scrollBarPosition = laSliderWidget_GetSliderValue(VolSlider);
    return (scrollBarPosition * APP_DISPLAY_VOLUME_MAX)/laSliderWidget_GetMaxinumValue(VolSlider);
}

///////////////////////////////////////////////////////////////////////////////
static void _APP_DISPLAY_VolumeSlider_DebounceTimerHandler(uintptr_t context)
{
    if (true == volumeSliderChangeInProgress)
    {
        volumeSliderDebounceCounter++;
    }
}



/* *****************************************************************************
 End of File
 */
