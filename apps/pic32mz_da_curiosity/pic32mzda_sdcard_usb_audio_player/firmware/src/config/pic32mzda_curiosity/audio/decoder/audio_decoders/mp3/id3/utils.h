#ifndef CHAR_CODE_H
#define CHAR_CODE_H

//// DOM-IGNORE-BEGIN
#ifdef __cplusplus
extern "C" {
#endif
// DOM-IGNORE-END

//#include "app.h"
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "string.h"


#define ENCODING_ASCII          0x00
#define ENCODING_UTF16          0x01
#define ENCODING_UTF16_BE       0x02
#define ENCODING_UTF8           0x03

#define ENCODING_UNKNOWN_CODE   '?'

uint16_t ENCODING_FormatASCII ( uint8_t encoding, uint8_t* source, uint16_t sourceSize, int8_t* dest, uint16_t destSize );

#ifdef __cplusplus
}
#endif

#endif
