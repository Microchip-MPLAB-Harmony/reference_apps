#ifndef LE_GEN_SCREEN_DEFAULT_H
#define LE_GEN_SCREEN_DEFAULT_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leGradientWidget* GradientWidget0;
extern leImageWidget* WatermarkImage;
extern leImageWidget* LogoImage;
extern leLabelWidget* TitleLabel;
extern leWidget* SelectMediumPanel;
extern leLabelWidget* SelectMediumLabel;
extern leButtonWidget* SDCardButton;
extern leButtonWidget* USBButton;
extern leWidget* ErrorMsgPanel;
extern leLabelWidget* NoMediumLabel2;
extern leLabelWidget* NoMediumLabel1;
extern leLabelWidget* LabelWidget3;
extern leWidget* InfoPanel;
extern leLabelWidget* InfoLabel1;
extern leLabelWidget* InfoLabel2;
extern leButtonWidget* InfoOKButton;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_default(); // called when Legato is initialized
leResult screenShow_default(); // called when screen is shown
void screenHide_default(); // called when screen is hidden
void screenDestroy_default(); // called when Legato is destroyed
void screenUpdate_default(); // called when Legato is updating

leWidget* screenGetRoot_default(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void default_OnShow(void);

void default_OnHide(void);

void default_OnUpdate(void);


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_DEFAULT_H
