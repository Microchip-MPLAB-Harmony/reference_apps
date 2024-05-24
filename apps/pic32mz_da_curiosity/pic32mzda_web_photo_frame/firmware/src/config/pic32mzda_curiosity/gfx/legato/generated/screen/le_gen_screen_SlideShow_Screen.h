#ifndef LE_GEN_SCREEN_SLIDESHOW_SCREEN_H
#define LE_GEN_SCREEN_SLIDESHOW_SCREEN_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* SlideShow_Screen_SS_PanelWidget;
extern leImageWidget* SlideShow_Screen_Images;

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_SlideShow_Screen(void); // called when Legato is initialized
leResult screenShow_SlideShow_Screen(void); // called when screen is shown
void screenHide_SlideShow_Screen(void); // called when screen is hidden
void screenDestroy_SlideShow_Screen(void); // called when Legato is destroyed
void screenUpdate_SlideShow_Screen(void); // called when Legato is updating

leWidget* screenGetRoot_SlideShow_Screen(uint32_t lyrIdx); // gets a root widget for this screen

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SLIDESHOW_SCREEN_H
