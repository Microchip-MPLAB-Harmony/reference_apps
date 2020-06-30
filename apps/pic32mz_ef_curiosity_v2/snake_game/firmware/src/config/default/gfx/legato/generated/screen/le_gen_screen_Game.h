#ifndef LE_GEN_SCREEN_GAME_H
#define LE_GEN_SCREEN_GAME_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* PanelWidget1;
extern leRectangleWidget* RectangleWidget2;
extern leRectangleWidget* RectangleWidget0;
extern leRectangleWidget* RectangleWidget1;
extern leRectangleWidget* RectangleWidget3;
extern leRectangleWidget* RectangleWidget4;
extern leRectangleWidget* RectangleWidget5;
extern leRectangleWidget* RectangleWidget6;
extern leRectangleWidget* RectangleWidget7;
extern leRectangleWidget* RectangleWidget8;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Game(); // called when Legato is initialized
leResult screenShow_Game(); // called when screen is shown
void screenHide_Game(); // called when screen is hidden
void screenDestroy_Game(); // called when Legato is destroyed
void screenUpdate_Game(); // called when Legato is updating

leWidget* screenGetRoot_Game(uint32_t lyrIdx); // gets a root widget for this screen

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_GAME_H
