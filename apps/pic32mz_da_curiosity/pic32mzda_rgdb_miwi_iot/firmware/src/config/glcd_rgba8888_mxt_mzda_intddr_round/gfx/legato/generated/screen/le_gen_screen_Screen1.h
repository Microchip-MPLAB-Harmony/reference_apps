#ifndef LE_GEN_SCREEN_SCREEN1_H
#define LE_GEN_SCREEN_SCREEN1_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* Screen1_PanelBG;
extern leWidget* Screen1_PanelWidget_0;
extern leWidget* Screen1_PanelWidget_1;
extern leListWheelWidget* Screen1_ListWheelWidget_0;
extern leButtonWidget* Screen1_btnChoose;
extern leLabelWidget* Screen1_LabelWidget_0;
extern leLabelWidget* Screen1_lbonline;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_Screen1_ListWheelWidget_0_OnSelectionChanged(leListWheelWidget* wgt, int32_t idx);
void event_Screen1_btnChoose_OnPressed(leButtonWidget* btn);
void event_Screen1_btnChoose_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Screen1(void); // called when Legato is initialized
leResult screenShow_Screen1(void); // called when screen is shown
void screenHide_Screen1(void); // called when screen is hidden
void screenDestroy_Screen1(void); // called when Legato is destroyed
void screenUpdate_Screen1(void); // called when Legato is updating

leWidget* screenGetRoot_Screen1(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void Screen1_OnShow(void); // called when this screen is shown
void Screen1_OnHide(void); // called when this screen is hidden

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SCREEN1_H
