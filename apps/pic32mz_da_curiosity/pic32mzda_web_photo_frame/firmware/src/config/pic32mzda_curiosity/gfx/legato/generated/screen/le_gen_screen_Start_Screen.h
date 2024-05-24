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
extern leWidget* Start_Screen_MM_PanelWidget;
extern leTextFieldWidget* Start_Screen_StartScreenLabel;
extern leTextFieldWidget* Start_Screen_TitleText;
extern leImageWidget* Start_Screen_MicrochipLogo;
extern leImageWidget* Start_Screen_HarmonyLogo;
extern leButtonWidget* Start_Screen_FullScreenButton;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_Start_Screen_FullScreenButton_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Start_Screen(void); // called when Legato is initialized
leResult screenShow_Start_Screen(void); // called when screen is shown
void screenHide_Start_Screen(void); // called when screen is hidden
void screenDestroy_Start_Screen(void); // called when Legato is destroyed
void screenUpdate_Start_Screen(void); // called when Legato is updating

leWidget* screenGetRoot_Start_Screen(uint32_t lyrIdx); // gets a root widget for this screen

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_START_SCREEN_H
