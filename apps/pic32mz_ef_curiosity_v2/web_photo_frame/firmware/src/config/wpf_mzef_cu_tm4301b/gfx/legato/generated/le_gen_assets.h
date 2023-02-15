/*******************************************************************************
 Module for Microchip Legato Graphics Library

  Company:
    Microchip Technology Inc.

  File Name:
    le_gen_assets.h

  Summary:
    Header file containing a list of asset specifications for use with the
    Legato Graphics Stack.


  Description:
    Header file containing a list of asset specifications for use with the
    Legato Graphics Stack.

*******************************************************************************/


// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C)  Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

// DOM-IGNORE-END

#ifndef LE_GEN_ASSETS_H
#define LE_GEN_ASSETS_H

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

#include "gfx/legato/legato.h"

extern const lePalette leGlobalPalette;

/*****************************************************************************
 * Legato Graphics Asset Location IDs
 *****************************************************************************/
/*********************************
 * Legato Asset Memory Location
 * Name:          SD_CARD_FILE
 ***********************************/
#define LE_STREAM_LOCATION_ID_SD_CARD_FILE    1

/*****************************************************************************
 * Legato Graphics Image Assets
 *****************************************************************************/
/*********************************
 * Legato Image Asset
 * Name:   mchpLogo_light_palette
 * Size:   16x1 pixels
 * Type:   RGB Color Palette
 * Format: RGB_888
 ***********************************/
extern leImage mchpLogo_light_palette;

/*********************************
 * Legato Image Asset
 * Name:   mchpLogo_light
 * Size:   152x40 pixels
 * Type:   Color Lookup Map
 * Format: INDEX_8
 ***********************************/
extern leImage mchpLogo_light;

/*********************************
 * Legato Image Asset
 * Name:   slide_1
 * Size:   276x127 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage slide_1;

/*****************************************************************************
 * Legato Graphics Font Assets
 *****************************************************************************/
/*********************************
 * Legato Font Asset
 * Name:         Start_Screen_Font
 * Height:       21
 * Baseline:     22
 * Style:        Antialias
 * Glyph Count:  95
 * Range Count:  16
 * Glyph Ranges: 0x20-0x7E
***********************************/
extern leRasterFont Start_Screen_Font;

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 1
 * String Count:   5
 *****************************************************************************/

// language IDs
#define language_Default    0

// string IDs
#define stringID_Fast    0
#define stringID_Easy    1
#define stringID_Start_Screen_Text    2
#define stringID_Smart    3
#define stringID_Title    4

extern const leStringTable stringTable;


// string list
extern leTableString string_Fast;
extern leTableString string_Easy;
extern leTableString string_Start_Screen_Text;
extern leTableString string_Smart;
extern leTableString string_Title;

void initializeStrings(void);
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* LE_GEN_ASSETS_H */
