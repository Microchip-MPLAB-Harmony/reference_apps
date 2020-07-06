#ifndef LE_GEN_SCREEN_MUSICSCREEN_H
#define LE_GEN_SCREEN_MUSICSCREEN_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leGradientWidget* GradientWidget1;
extern leButtonWidget* PlayPausebutton;
extern leButtonWidget* ButtonWidget0;
extern leSliderWidget* volumecontrol;
extern leRectangleWidget* RectangleWidget1;
extern leRectangleWidget* RectangleWidget0;
extern leLabelWidget* LabelWidget0;
extern leLabelWidget* LabelWidget1;
extern leImageWidget* ImageWidget0;
extern leButtonWidget* ButtonWidget1;
extern leLabelWidget* LabelWidget2;
extern leListWheelWidget* ListWheelWidget0;
extern leLabelWidget* LabelWidget4;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_MusicScreen(); // called when Legato is initialized
leResult screenShow_MusicScreen(); // called when screen is shown
void screenHide_MusicScreen(); // called when screen is hidden
void screenDestroy_MusicScreen(); // called when Legato is destroyed
void screenUpdate_MusicScreen(); // called when Legato is updating

leWidget* screenGetRoot_MusicScreen(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void MusicScreen_OnShow(void);

void MusicScreen_OnHide(void);

void MusicScreen_OnUpdate(void);


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_MUSICSCREEN_H
