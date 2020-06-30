#ifndef LE_GEN_SCREEN_GAME_LEVEL2_H
#define LE_GEN_SCREEN_GAME_LEVEL2_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* PanelWidget1;
extern leRectangleWidget* Barrier_upper_left_horizontal;
extern leRectangleWidget* Barrier_upper_left_vertical;
extern leRectangleWidget* Barrier_lower_left_horizontal;
extern leRectangleWidget* Barrier_lower_left_vertical;
extern leRectangleWidget* Barrier_Upper_right_horizontal;
extern leRectangleWidget* Barrier_upper_right_vertical;
extern leRectangleWidget* Barrier_lower_right_horizontal;
extern leRectangleWidget* Barrier_lower_right_vertical;
extern leWidget* PanelWidget4;
extern leImageWidget* HeartImage1_level2;
extern leImageWidget* HeartImage2_level2;
extern leImageWidget* HeartImage3_level2;
extern leLabelWidget* Life_text_2;
extern leLabelWidget* Snake_size_text_2;
extern leLabelWidget* Snake_size_value_level2;
extern leLabelWidget* Game_Over_level2;
extern leGradientWidget* GradientWidget1;
extern leImageWidget* ImageWidget3;
extern leLabelWidget* LabelWidget2;
extern leLabelWidget* Game_Won_level2;


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
