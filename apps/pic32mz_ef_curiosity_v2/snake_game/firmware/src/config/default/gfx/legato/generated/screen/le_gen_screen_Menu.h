#ifndef LE_GEN_SCREEN_MENU_H
#define LE_GEN_SCREEN_MENU_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* PanelWidget0;
extern leLabelWidget* Level1_label;
extern leLabelWidget* Level2_label;
extern leGradientWidget* GradientWidget2;
extern leImageWidget* ImageWidget1;
extern leLabelWidget* LabelWidget1;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Menu(); // called when Legato is initialized
leResult screenShow_Menu(); // called when screen is shown
void screenHide_Menu(); // called when screen is hidden
void screenDestroy_Menu(); // called when Legato is destroyed
void screenUpdate_Menu(); // called when Legato is updating

leWidget* screenGetRoot_Menu(uint32_t lyrIdx); // gets a root widget for this screen

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_MENU_H
