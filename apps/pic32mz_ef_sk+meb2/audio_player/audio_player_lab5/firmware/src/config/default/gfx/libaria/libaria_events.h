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
  MPLAB Harmony Graphics Composer Generated Definitions Header

  File Name:
    libaria_events.h

  Summary:
    Build-time generated definitions header based on output by the MPLAB Harmony
    Graphics Composer.

  Description:
    Build-time generated definitions header based on output by the MPLAB Harmony
    Graphics Composer.

    Created with MPLAB Harmony Version 3.0
*******************************************************************************/


#ifndef _LIBARIA_EVENTS_H
#define _LIBARIA_EVENTS_H

#include "gfx/libaria/libaria.h"
#include "gfx/libaria/libaria_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END 

// Generated Event Handler - Origin: RadioButtonPlayer, Event: CheckedEvent
void RadioButtonPlayer_CheckedEvent(laRadioButtonWidget* cbox);

// Generated Event Handler - Origin: RadioButtonReader, Event: CheckedEvent
void RadioButtonReader_CheckedEvent(laRadioButtonWidget* cbox);

// Generated Event Handler - Origin: TrackListBox, Event: SelectionChangedEvent
void TrackListBox_SelectionChangedEvent(laListWidget* img, uint32_t idx, laBool selected);

// Generated Event Handler - Origin: ScrollUpButton, Event: ReleasedEvent
void ScrollUpButton_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ScrollDownButton, Event: ReleasedEvent
void ScrollDownButton_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: VolSlider, Event: ValueChangedEvent
void VolSlider_ValueChangedEvent(laSliderWidget* sld);

// Generated Event Handler - Origin: VolButton, Event: PressedEvent
void VolButton_PressedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: VolButton, Event: ReleasedEvent
void VolButton_ReleasedEvent(laButtonWidget* btn);



//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // _LIBARIA_EVENTS_H
/*******************************************************************************
 End of File
*/
