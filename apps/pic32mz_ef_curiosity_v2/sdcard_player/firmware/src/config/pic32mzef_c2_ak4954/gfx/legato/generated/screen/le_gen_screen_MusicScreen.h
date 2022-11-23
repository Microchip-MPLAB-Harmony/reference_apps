#ifndef LE_GEN_SCREEN_MUSICSCREEN_H
#define LE_GEN_SCREEN_MUSICSCREEN_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* MusicScreen_Background;
extern leButtonWidget* MusicScreen_PlayPausebutton;
extern leSliderWidget* MusicScreen_volumecontrol;
extern leImageWidget* MusicScreen_ImageWidget0;
extern leLabelWidget* MusicScreen_LabelWidget2;
extern leListWheelWidget* MusicScreen_ListWheelWidget0;
extern leButtonWidget* MusicScreen_NextTrackButton;
extern leButtonWidget* MusicScreen_PreviousTrackButton;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_MusicScreen_PlayPausebutton_OnPressed(leButtonWidget* btn);
void event_MusicScreen_PlayPausebutton_OnReleased(leButtonWidget* btn);
void event_MusicScreen_volumecontrol_OnValueChanged(leSliderWidget* scr);
void event_MusicScreen_ListWheelWidget0_OnSelectionChanged(leListWheelWidget* wgt, int32_t idx);
void event_MusicScreen_NextTrackButton_OnReleased(leButtonWidget* btn);
void event_MusicScreen_PreviousTrackButton_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_MusicScreen(void); // called when Legato is initialized
leResult screenShow_MusicScreen(void); // called when screen is shown
void screenHide_MusicScreen(void); // called when screen is hidden
void screenDestroy_MusicScreen(void); // called when Legato is destroyed
void screenUpdate_MusicScreen(void); // called when Legato is updating

leWidget* screenGetRoot_MusicScreen(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void MusicScreen_OnShow(void); // called when this screen is shown
void MusicScreen_OnHide(void); // called when this screen is hidden
void MusicScreen_OnUpdate(void); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_MUSICSCREEN_H
