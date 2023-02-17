#ifndef LE_GEN_SCREEN_GAME_LEVEL1_H
#define LE_GEN_SCREEN_GAME_LEVEL1_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* Game_Level1_PanelWidget2;
extern leWidget* Game_Level1_PanelWidget3;
extern leImageWidget* Game_Level1_HeartImage1_level1;
extern leImageWidget* Game_Level1_HeartImage2_level1;
extern leImageWidget* Game_Level1_HeartImage3_level1;
extern leLabelWidget* Game_Level1_Snake_size_text_1;
extern leLabelWidget* Game_Level1_LIfe_text_1;
extern leLabelWidget* Game_Level1_Snake_size_value_level1;
extern leGradientWidget* Game_Level1_GradientWidget0;
extern leImageWidget* Game_Level1_ImageWidget0;
extern leLabelWidget* Game_Level1_Game_Over_level1;
extern leLabelWidget* Game_Level1_Title_label_game_level_1;
extern leLabelWidget* Game_Level1_Game_Won_level1;
extern leButtonWidget* Game_Level1_ButtonWidget1;

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Game_Level1(void); // called when Legato is initialized
leResult screenShow_Game_Level1(void); // called when screen is shown
void screenHide_Game_Level1(void); // called when screen is hidden
void screenDestroy_Game_Level1(void); // called when Legato is destroyed
void screenUpdate_Game_Level1(void); // called when Legato is updating

leWidget* screenGetRoot_Game_Level1(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void Game_Level1_OnShow(void); // called when this screen is shown

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_GAME_LEVEL1_H
