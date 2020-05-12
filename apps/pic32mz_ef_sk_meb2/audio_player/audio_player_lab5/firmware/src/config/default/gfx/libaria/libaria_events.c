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

/*******************************************************************************
  MPLAB Harmony Graphics Composer Generated Implementation File

  File Name:
    libaria_events.c

  Summary:
    Build-time generated implementation from the MPLAB Harmony
    Graphics Composer.

  Description:
    Build-time generated implementation from the MPLAB Harmony
    Graphics Composer.

    Created with MPLAB Harmony Version 3.0
*******************************************************************************/

#include "gfx/libaria/libaria_events.h"
#include "app.h"

// RadioButtonPlayer - CheckedEvent
void RadioButtonPlayer_CheckedEvent(laRadioButtonWidget* cbox)
{
    // RadioButtonPlayerAction
    laWidget_SetEnabled(&(TrackListBox->widget), true);
    laWidget_SetEnabled(&(ScrollUpButton->widget), true);
    laWidget_SetEnabled(&(ScrollDownButton->widget), true);
    laWidget_SetEnabled(&(MessageTextBox->editWidget.widget), true);
    laWidget_SetEnabled(&(VolButton->widget), true);
    laWidget_SetEnabled(&(VolSlider->widget), true);
    
    APP_DISPLAY_ModeSet(0);
}

// RadioButtonReader - CheckedEvent
void RadioButtonReader_CheckedEvent(laRadioButtonWidget* cbox)
{
    // RadioButtonReaderAction
    laWidget_SetEnabled(&(TrackListBox->widget), false);
    laWidget_SetEnabled(&(ScrollUpButton->widget), false);
    laWidget_SetEnabled(&(ScrollDownButton->widget), false);
    laWidget_SetEnabled(&(MessageTextBox->editWidget.widget), false);
    laWidget_SetEnabled(&(VolButton->widget), false);
    laWidget_SetEnabled(&(VolSlider->widget), false);
    
    APP_DISPLAY_ModeSet(1);
}

// TrackListBox - SelectionChangedEvent
void TrackListBox_SelectionChangedEvent(laListWidget* img, uint32_t idx, laBool selected)
{
    // ListBoxAction
    if (selected && idx <= laListWidget_GetItemCount(img))
    {
    	APP_SDCARD_AUDIO_RandomTrackSet(APP_DISPLAY_XlatListIdx(idx));
    }
}

// ScrollUpButton - ReleasedEvent
void ScrollUpButton_ReleasedEvent(laButtonWidget* btn)
{
    // ScrollUpAction
    APP_DISPLAY_ScrollUp();
}

// ScrollDownButton - ReleasedEvent
void ScrollDownButton_ReleasedEvent(laButtonWidget* btn)
{
    // ScrollDownAction
    APP_DISPLAY_ScrollDown();
}

// VolSlider - ValueChangedEvent
void VolSlider_ValueChangedEvent(laSliderWidget* sld)
{
    // VolSliderAction
    APP_DISPLAY_VolumeMuteChange(2);
}

// VolButton - PressedEvent
void VolButton_PressedEvent(laButtonWidget* btn)
{
    // VolButtonPressedAction
    APP_DISPLAY_VolumeMuteChange(1);
}

// VolButton - ReleasedEvent
void VolButton_ReleasedEvent(laButtonWidget* btn)
{
    // VolButtonReleasedAction
    APP_DISPLAY_VolumeMuteChange(0);
}





