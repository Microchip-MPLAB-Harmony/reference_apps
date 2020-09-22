#ifndef LE_GEN_SCREEN_DEFAULT_H
#define LE_GEN_SCREEN_DEFAULT_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leGradientWidget* default_GradientWidget0;
extern leImageWidget* default_WatermarkImage;
extern leImageWidget* default_LogoImage;
extern leLabelWidget* default_TitleLabel;
extern leWidget* default_SelectMediumPanel;
extern leWidget* default_InfoPanel;
extern leLabelWidget* default_SelectMediumLabel;
extern leButtonWidget* default_SDCardButton;
extern leButtonWidget* default_USBButton;
extern leWidget* default_ErrorMsgPanel;
extern leLabelWidget* default_LabelWidget3;
extern leLabelWidget* default_NoMediumLabel2;
extern leLabelWidget* default_NoMediumLabel1;
extern leLabelWidget* default_InfoLabel1;
extern leLabelWidget* default_InfoLabel2;
extern leButtonWidget* default_InfoOKButton;

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_default(); // called when Legato is initialized
leResult screenShow_default(); // called when screen is shown
void screenHide_default(); // called when screen is hidden
void screenDestroy_default(); // called when Legato is destroyed
void screenUpdate_default(); // called when Legato is updating

leWidget* screenGetRoot_default(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void default_OnShow(); // called when this screen is shown
void default_OnHide(); // called when this screen is hidden

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_DEFAULT_H
