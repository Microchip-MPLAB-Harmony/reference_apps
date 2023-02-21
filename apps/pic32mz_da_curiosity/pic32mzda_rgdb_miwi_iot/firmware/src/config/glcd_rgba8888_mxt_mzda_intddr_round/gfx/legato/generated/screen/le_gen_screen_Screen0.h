#ifndef LE_GEN_SCREEN_SCREEN0_H
#define LE_GEN_SCREEN_SCREEN0_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* Screen0_PanelWidget_0;
extern leButtonWidget* Screen0_BTNled;
extern leButtonWidget* Screen0_BTNgpio1;
extern leButtonWidget* Screen0_BTNgpio2;
extern leButtonWidget* Screen0_BTNhome;
extern leLabelWidget* Screen0_LbDev;
extern leImageWidget* Screen0_ImageWidget_0;
extern leImageWidget* Screen0_ImageWidget_1;
extern leLabelWidget* Screen0_LabelWidget_3;
extern leLabelWidget* Screen0_LabelWidget_2;
extern leLabelWidget* Screen0_LabelWidget_0;
extern leLabelWidget* Screen0_LabelWidget_1;
extern leLabelWidget* Screen0_LbTemp;
extern leLabelWidget* Screen0_LabelWidget_5;
extern leLabelWidget* Screen0_LbRSSI;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_Screen0_BTNled_OnPressed(leButtonWidget* btn);
void event_Screen0_BTNgpio1_OnPressed(leButtonWidget* btn);
void event_Screen0_BTNgpio2_OnPressed(leButtonWidget* btn);
void event_Screen0_BTNhome_OnPressed(leButtonWidget* btn);
void event_Screen0_BTNhome_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Screen0(void); // called when Legato is initialized
leResult screenShow_Screen0(void); // called when screen is shown
void screenHide_Screen0(void); // called when screen is hidden
void screenDestroy_Screen0(void); // called when Legato is destroyed
void screenUpdate_Screen0(void); // called when Legato is updating

leWidget* screenGetRoot_Screen0(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void Screen0_OnShow(void); // called when this screen is shown
void Screen0_OnHide(void); // called when this screen is hidden

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SCREEN0_H
