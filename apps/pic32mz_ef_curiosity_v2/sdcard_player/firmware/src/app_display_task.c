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

#include "app_display_task.h"


// *****************************************************************************
// *****************************************************************************
// Section: Global Variable Definitions
// *****************************************************************************
// *****************************************************************************

APP_SDCARD_READER_DATA AppSdCardReaderData;

static uint16_t app_display_current_song_id;


static void APP_DISPLAY_Update_WidgetSongList();

static bool APP_DISPLAY_MSD_Attached_Get();

static bool APP_DISPLAY_SDcard_Attached();


void event_MusicScreen_PlayPausebutton_OnReleased(leButtonWidget* btn)
{
    APP_SDCARD_AUDIO_StopTrack(true);
}

void event_MusicScreen_PlayPausebutton_OnPressed(leButtonWidget* btn)
{
    
    APP_SDCARD_AUDIO_StopTrack(false);

}

void APP_DISPLAY_Initialize()
{
    app_display_state.app_display_task_state = APP_DISPLAY_STATE_START_SCREEN;
    
    app_display_state.sdcard_msd_updated = false;
    
    app_display_state.msd_attached = false;
}

void APP_DISPLAY_Screens_Task()
{ 
    switch(app_display_state.app_display_task_state)
    {
        
        case APP_DISPLAY_STATE_START_SCREEN:
            
            if(legato_getCurrentScreen() != screenID_default)
            {
               legato_showScreen(screenID_default);
            }
            
            break;
    
        case APP_DISPLAY_STATE_MUSIC_SCREEN_STATE:
            
             if(legato_getCurrentScreen() != screenID_MusicScreen)
                {
                   legato_showScreen(screenID_MusicScreen);
                }
            
            break;
            
        case APP_DISPLAY_STATE_USB_MSD_STATE:
            
            if(legato_getCurrentScreen() != screenID_default)
                {
                   legato_showScreen(screenID_default);
                }
            
            break;
    
    }

}

void APP_DISPLAY_USB_Configured_State_Set_True()
{
  app_display_state.usb_msd_configured = true;
}

void APP_DISPLAY_USB_Configured_State_Set_False()
{
  app_display_state.usb_msd_configured = false;
}


bool APP_DISPLAY_USB_Configured_State_Get()
{

    return app_display_state.usb_msd_configured;
    
}


void event_MusicScreen_volumecontrol_OnValueChanged(leSliderWidget* scr)
{
    int32_t volume_val;
    
      volume_val = scr->fn->getValue(scr);
   
      APP_SDCARD_AUDIO_VolumeSet(volume_val);

}


void event_MusicScreen_MuteButton_OnReleased(leButtonWidget* btn)
{
   

}

void event_MusicScreen_MuteButton_OnPressed(leButtonWidget* btn)
{

}

void event_MusicScreen_NextTrackButton_OnReleased(leButtonWidget* btn)
{
    uint16_t id,songs_number;
   
        songs_number = APP_SDCARD_AUDIO_FileCountGet();

        id = (APP_SDCARD_AUDIO_CurrentTrackIdGet() + 1) % songs_number;

        APP_SDCARD_AUDIO_RandomTrackSet(id);

        APP_DISPLAY_MUSIC_LIST_WIDGET->fn->setSelectedItem(APP_DISPLAY_MUSIC_LIST_WIDGET,(int32_t)(id));

        APP_DISPLAY_MUSCI_PLAY_PAUSE_BUTTON->fn->setPressed(APP_DISPLAY_MUSCI_PLAY_PAUSE_BUTTON,LE_TRUE);

}

void event_MusicScreen_PreviousTrackButton_OnReleased(leButtonWidget* btn)
{
    uint16_t id, audio_files_nr;

       id = APP_SDCARD_AUDIO_CurrentTrackIdGet();
       
       audio_files_nr = APP_SDCARD_AUDIO_FileCountGet();


       if(id == 0)
       {
           id = audio_files_nr - 1;
       } 
       else
       {
           id--;
       }

       APP_SDCARD_AUDIO_RandomTrackSet(id);
       
       APP_DISPLAY_MUSIC_LIST_WIDGET->fn->setSelectedItem(APP_DISPLAY_MUSIC_LIST_WIDGET,(int32_t)id);
       
       APP_DISPLAY_MUSCI_PLAY_PAUSE_BUTTON->fn->setPressed(APP_DISPLAY_MUSCI_PLAY_PAUSE_BUTTON,LE_TRUE);

}

void APP_DISPLAY_WheelWidgetSetString(leListWheelWidget* wheel_wgt,int id,leFont* font, char* text)
{
   ListWheel_set_string(wheel_wgt,id,font,text);
}



void ListWheel_set_string(leListWheelWidget* wheel_wgt,int id, leFont* font, char* text)
{
    static char cCharBuffer[32];
    
    static leDynamicString dynamic_str[20];
    
    static int8_t dynamic_string_index;
    
    dynamic_string_index = id;
    
    if(dynamic_str[dynamic_string_index].data == NULL)
    {
       leDynamicString_Constructor(&dynamic_str[dynamic_string_index]);
        
    }else if(dynamic_str[dynamic_string_index].data != NULL)
    {
       dynamic_str[dynamic_string_index].fn->destructor(&dynamic_str[dynamic_string_index]);
       
       leDynamicString_Constructor(&dynamic_str[dynamic_string_index]);
       
    }
        
        dynamic_str[dynamic_string_index].fn->setFont(&dynamic_str[dynamic_string_index],font);
    
        //create the c character array string counter value
        sprintf(cCharBuffer, "%d.%s", id, text); 

        dynamic_str[dynamic_string_index].fn->setFromCStr(&dynamic_str[dynamic_string_index], cCharBuffer);    

        //Set counterString string to label 
        wheel_wgt->fn->setItemString(wheel_wgt,id, (leString*)&dynamic_str[dynamic_string_index]);
}

void MusicScreen_OnShow(void)
{   
   APP_DISPLAY_FillSongListFromSDCard();
   APP_DISPLAY_MUSIC_VOLUME_CONTROL->fn->setValue(APP_DISPLAY_MUSIC_VOLUME_CONTROL,APP_SDCARD_AUDIO_VolumeGet());
   
}
void MusicScreen_OnHide(void)
{

}
void MusicScreen_OnUpdate(void)
{
    if(app_display_state.sdcard_msd_updated == true)
    {
        app_display_state.sdcard_msd_updated = false;
      
        APP_DISPLAY_FillSongListFromSDCard();
    
    }
    
    APP_DISPLAY_Update_WidgetSongList();

}

void APP_DISPLAY_FillSongListFromSDCard()
{
    APP_SDCARD_AUDIO_CARD_FILE_PATH *tablePointer;
    int16_t index;
    int16_t diff;
    
    tablePointer = APP_SDCARD_AUDIO_GetFileTablePointer();
    
    APP_DISPLAY_MUSIC_LIST_WIDGET->fn->removeAllItems(APP_DISPLAY_MUSIC_LIST_WIDGET);
    
    diff = (int16_t)((uint16_t)APP_SDCARD_AUDIO_FileCountGet() - (uint16_t)APP_DISPLAY_MUSIC_LIST_WIDGET->fn->getItemCount(APP_DISPLAY_MUSIC_LIST_WIDGET));     
    
    if(diff > 0 )
    {
     
        for(index = 0;index < diff; index++)
        {
        
           APP_DISPLAY_MUSIC_LIST_WIDGET->fn->appendItem(APP_DISPLAY_MUSIC_LIST_WIDGET);
        
        }
      
    }
    
    for(index = 0;index < APP_SDCARD_AUDIO_FileCountGet(); index++)
    {
    
          APP_DISPLAY_WheelWidgetSetString(APP_DISPLAY_MUSIC_LIST_WIDGET,index,&APP_DISPLAY_WHEEL_WIDGET_TEXT_FONT,(char*)&tablePointer[index].path[sizeof(APP_SDCARD_AUDIO_MOUNT_NAME) - 1]);
          
    }
    
    app_display_current_song_id = 0;
}

void event_MusicScreen_ListWheelWidget0_OnSelectionChanged(leListWheelWidget* wgt, int32_t idx)
{
    APP_SDCARD_AUDIO_RandomTrackSet((uint16_t)idx);
    APP_DISPLAY_MUSCI_PLAY_PAUSE_BUTTON->fn->setPressed(APP_DISPLAY_MUSCI_PLAY_PAUSE_BUTTON,LE_TRUE);
    
}


static void APP_DISPLAY_Update_WidgetSongList()
{
    uint16_t id_song;
    
    id_song = APP_SDCARD_AUDIO_CurrentTrackIdGet();
    
    if(app_display_current_song_id != id_song)
    {
      APP_DISPLAY_MUSIC_LIST_WIDGET->fn->setSelectedItem(APP_DISPLAY_MUSIC_LIST_WIDGET,(int32_t)id_song);
      app_display_current_song_id = id_song;
    }
}

static bool APP_DISPLAY_MSD_Attached_Get()
{

    return app_display_state.msd_attached;

}

static bool APP_DISPLAY_SDcard_Attached()
{

    return app_display_state.sdcard_attached;
    
}

void default_OnShow(void)
{

     if(APP_DISPLAY_MSD_Attached_Get() == true)
       {
          APP_DISPLAY_MUSIC_USB_MSD_IMG_WIDGET->fn->setVisible(APP_DISPLAY_MUSIC_USB_MSD_IMG_WIDGET,LE_TRUE);
          
       }else {
   
          APP_DISPLAY_MUSIC_USB_MSD_IMG_WIDGET->fn->setVisible(APP_DISPLAY_MUSIC_USB_MSD_IMG_WIDGET,LE_FALSE);
   
        }

}


void default_OnUpdate(void)
{

    if(APP_DISPLAY_SDcard_Attached() == true)
    {
    
        APP_DISPLAY_MUSIC_INSERT_SDCARD_LABEL->fn->setVisible(APP_DISPLAY_MUSIC_INSERT_SDCARD_LABEL,LE_FALSE);
    
    }else{
    
        APP_DISPLAY_MUSIC_INSERT_SDCARD_LABEL->fn->setVisible(APP_DISPLAY_MUSIC_INSERT_SDCARD_LABEL,LE_TRUE);
    
    }
    
    
    if(APP_DISPLAY_MSD_Attached_Get() == true)
       {
          APP_DISPLAY_MUSIC_USB_MSD_IMG_WIDGET->fn->setVisible(APP_DISPLAY_MUSIC_USB_MSD_IMG_WIDGET,LE_TRUE);
          
       }else {
   
          APP_DISPLAY_MUSIC_USB_MSD_IMG_WIDGET->fn->setVisible(APP_DISPLAY_MUSIC_USB_MSD_IMG_WIDGET,LE_FALSE);
   
        }

}



