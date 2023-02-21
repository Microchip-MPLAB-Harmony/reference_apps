#ifndef LE_GEN_SCREEN_SCREEN2_H
#define LE_GEN_SCREEN_SCREEN2_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* Screen2_Panel_0;
extern leCircleWidget* Screen2_CircleWidget_0;
extern leButtonWidget* Screen2_BTNscr2Ret;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_Screen2_BTNscr2Ret_OnPressed(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Screen2(void); // called when Legato is initialized
leResult screenShow_Screen2(void); // called when screen is shown
void screenHide_Screen2(void); // called when screen is hidden
void screenDestroy_Screen2(void); // called when Legato is destroyed
void screenUpdate_Screen2(void); // called when Legato is updating

leWidget* screenGetRoot_Screen2(uint32_t lyrIdx); // gets a root widget for this screen

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SCREEN2_H
