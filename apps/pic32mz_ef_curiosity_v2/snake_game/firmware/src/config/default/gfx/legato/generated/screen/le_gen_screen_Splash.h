#ifndef LE_GEN_SCREEN_SPLASH_H
#define LE_GEN_SCREEN_SPLASH_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* Panel_splash_screen;
extern leImageWidget* PIC32_logo;
extern leImageWidget* Splash_bar;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Splash(); // called when Legato is initialized
leResult screenShow_Splash(); // called when screen is shown
void screenHide_Splash(); // called when screen is hidden
void screenDestroy_Splash(); // called when Legato is destroyed
void screenUpdate_Splash(); // called when Legato is updating

leWidget* screenGetRoot_Splash(uint32_t lyrIdx); // gets a root widget for this screen

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SPLASH_H
