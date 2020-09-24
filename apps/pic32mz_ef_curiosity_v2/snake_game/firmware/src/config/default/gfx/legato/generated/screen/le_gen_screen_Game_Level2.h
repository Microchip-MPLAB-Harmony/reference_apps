#ifndef LE_GEN_SCREEN_GAME_LEVEL2_H
#define LE_GEN_SCREEN_GAME_LEVEL2_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* Game_Level2_PanelWidget1;
extern leRectangleWidget* Game_Level2_Barrier_upper_left_horizontal;
extern leRectangleWidget* Game_Level2_Barrier_upper_left_vertical;
extern leRectangleWidget* Game_Level2_Barrier_lower_left_horizontal;
extern leRectangleWidget* Game_Level2_Barrier_lower_left_vertical;
extern leRectangleWidget* Game_Level2_Barrier_Upper_right_horizontal;
extern leRectangleWidget* Game_Level2_Barrier_upper_right_vertical;
extern leRectangleWidget* Game_Level2_Barrier_lower_right_horizontal;
extern leRectangleWidget* Game_Level2_Barrier_lower_right_vertical;
extern leWidget* Game_Level2_PanelWidget4;
extern leImageWidget* Game_Level2_HeartImage1_level2;
extern leImageWidget* Game_Level2_HeartImage2_level2;
extern leImageWidget* Game_Level2_HeartImage3_level2;
extern leLabelWidget* Game_Level2_Life_text_2;
extern leLabelWidget* Game_Level2_Snake_size_text_2;
extern leLabelWidget* Game_Level2_Snake_size_value_level2;
extern leLabelWidget* Game_Level2_Game_Over_level2;
extern leGradientWidget* Game_Level2_GradientWidget1;
extern leImageWidget* Game_Level2_ImageWidget3;
extern leLabelWidget* Game_Level2_LabelWidget2;
extern leLabelWidget* Game_Level2_Game_Won_level2;

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Game_Level2(); // called when Legato is initialized
leResult screenShow_Game_Level2(); // called when screen is shown
void screenHide_Game_Level2(); // called when screen is hidden
void screenDestroy_Game_Level2(); // called when Legato is destroyed
void screenUpdate_Game_Level2(); // called when Legato is updating

leWidget* screenGetRoot_Game_Level2(uint32_t lyrIdx); // gets a root widget for this screen

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_GAME_LEVEL2_H
