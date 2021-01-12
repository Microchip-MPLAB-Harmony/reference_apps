#ifndef LEGATO_INIT_SCHEME_H
#define LEGATO_INIT_SCHEME_H

#include "gfx/legato/legato.h"

extern const leScheme ListWheelScheme;
extern const leScheme defaultScheme;
extern const leScheme ProgressScheme;
extern const leScheme whiteScheme;
extern const leScheme volumeScheme;
extern const leScheme gradientScheme;
extern const leScheme NewScheme;
extern const leScheme Backgroundgradientscheme;

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
