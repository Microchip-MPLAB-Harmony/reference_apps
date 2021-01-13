#ifndef LEGATO_INIT_SCHEME_H
#define LEGATO_INIT_SCHEME_H

#include "gfx/legato/legato.h"

extern const leScheme SnakePart_sheme;
extern const leScheme Unselected_Level_label_scheme;
extern const leScheme Gradient_scheme;
extern const leScheme Title_text_scheme;
extern const leScheme RightPanelscheme;
extern const leScheme PanelScheme;
extern const leScheme Game_Over_scheme;
extern const leScheme ListScheme;
extern const leScheme Splash_Panel;
extern const leScheme Bars_scheme;
extern const leScheme Selected_Level_label_scheme;
extern const leScheme SnakePart_Scheme_RED;
extern const leScheme SnakePart_Scheme_BLUE;
extern const leScheme SnakePart_Scheme_GREEN;
extern const leScheme SnakePart_Scheme_YELLOW;
extern const leScheme SnakePart_Scheme_ORANGE;
extern const leScheme SnakePart_Scheme_PURPLE;

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

void legato_initialize_schemes(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LEGATO_INIT_SCHEME_H
