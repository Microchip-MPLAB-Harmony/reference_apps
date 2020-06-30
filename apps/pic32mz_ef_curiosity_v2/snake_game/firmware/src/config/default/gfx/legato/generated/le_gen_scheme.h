#ifndef LEGATO_INIT_SCHEME_H
#define LEGATO_INIT_SCHEME_H

#include "gfx/legato/legato.h"

extern leScheme Bars_scheme;
extern leScheme Game_Over_scheme;
extern leScheme Gradient_scheme;
extern leScheme Level_label_scheme;
extern leScheme ListScheme;
extern leScheme PanelScheme;
extern leScheme RightPanelscheme;
extern leScheme SnakePart_sheme;
extern leScheme Splash_Panel;
extern leScheme Title_text_scheme;

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

void legato_initialize_schemes();

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LEGATO_INIT_SCHEME_H
