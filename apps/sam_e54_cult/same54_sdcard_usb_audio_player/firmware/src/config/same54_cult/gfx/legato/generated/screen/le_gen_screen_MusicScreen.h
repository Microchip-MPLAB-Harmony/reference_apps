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
extern leGradientWidget* MusicScreen_GradientWidget1;
extern leButtonWidget* MusicScreen_PlayPausebutton;
extern leButtonWidget* MusicScreen_ButtonWidget0;
extern leSliderWidget* MusicScreen_volumecontrol;
extern leRectangleWidget* MusicScreen_RectangleWidget1;
extern leRectangleWidget* MusicScreen_RectangleWidget0;
extern leLabelWidget* MusicScreen_LabelWidget0;
extern leLabelWidget* MusicScreen_LabelWidget1;
extern leImageWidget* MusicScreen_ImageWidget0;
extern leButtonWidget* MusicScreen_ButtonWidget1;
extern leLabelWidget* MusicScreen_LabelWidget2;
extern leListWheelWidget* MusicScreen_ListWheelWidget0;
extern leLabelWidget* MusicScreen_LabelWidget4;

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_MusicScreen(); // called when Legato is initialized
leResult screenShow_MusicScreen(); // called when screen is shown
void screenHide_MusicScreen(); // called when screen is hidden
void screenDestroy_MusicScreen(); // called when Legato is destroyed
void screenUpdate_MusicScreen(); // called when Legato is updating

leWidget* screenGetRoot_MusicScreen(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void MusicScreen_OnShow(); // called when this screen is shown
void MusicScreen_OnHide(); // called when this screen is hidden

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_MUSICSCREEN_H
