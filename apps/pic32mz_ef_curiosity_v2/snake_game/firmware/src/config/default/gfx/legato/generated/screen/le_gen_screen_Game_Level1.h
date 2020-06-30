#ifndef LE_GEN_SCREEN_GAME_LEVEL1_H
#define LE_GEN_SCREEN_GAME_LEVEL1_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* PanelWidget2;
extern leWidget* PanelWidget3;
extern leImageWidget* HeartImage1_level1;
extern leImageWidget* HeartImage2_level1;
extern leImageWidget* HeartImage3_level1;
extern leLabelWidget* Snake_size_text_1;
extern leLabelWidget* LIfe_text_1;
extern leLabelWidget* Snake_size_value_level1;
extern leGradientWidget* GradientWidget0;
extern leImageWidget* ImageWidget0;
extern leLabelWidget* Game_Over_level1;
extern leLabelWidget* Title_label_game_level_1;
extern leLabelWidget* Game_Won_level1;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Game_Level1(); // called when Legato is initialized
leResult screenShow_Game_Level1(); // called when screen is shown
void screenHide_Game_Level1(); // called when screen is hidden
void screenDestroy_Game_Level1(); // called when Legato is destroyed
void screenUpdate_Game_Level1(); // called when Legato is updating

leWidget* screenGetRoot_Game_Level1(uint32_t lyrIdx); // gets a root widget for this screen

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_GAME_LEVEL1_H
