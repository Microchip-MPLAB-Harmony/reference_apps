#ifndef LE_GEN_SCREEN_START_SCREEN_H
#define LE_GEN_SCREEN_START_SCREEN_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* Start_screen_PanelWidget0;
extern leImageWidget* Start_screen_ImageWidget0;

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Start_screen(void); // called when Legato is initialized
leResult screenShow_Start_screen(void); // called when screen is shown
void screenHide_Start_screen(void); // called when screen is hidden
void screenDestroy_Start_screen(void); // called when Legato is destroyed
void screenUpdate_Start_screen(void); // called when Legato is updating

leWidget* screenGetRoot_Start_screen(uint32_t lyrIdx); // gets a root widget for this screen

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_START_SCREEN_H
