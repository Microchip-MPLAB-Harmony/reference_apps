#ifndef LE_GEN_SCREEN_SPLASH_H
#define LE_GEN_SCREEN_SPLASH_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* Splash_Panel_splash_screen;
extern leImageWidget* Splash_PIC32_logo;
extern leImageWidget* Splash_Splash_bar;

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
