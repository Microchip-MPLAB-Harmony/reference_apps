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
 * Legato Graphics Image Assets
 *****************************************************************************/
/*********************************
 * Legato Image Asset
 * Name:   mchpLogo
 * Size:   32x32 pixels
 * Type:   RGB Data
 * Format: RGB_332
 ***********************************/
extern leImage mchpLogo;

/*********************************
 * Legato Image Asset
 * Name:   sdcard_sm
 * Size:   32x32 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage sdcard_sm;

/*********************************
 * Legato Image Asset
 * Name:   usb_icon_sm
 * Size:   32x32 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage usb_icon_sm;

/*********************************
 * Legato Image Asset
 * Name:   mplabharmonylogo
 * Size:   270x200 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage mplabharmonylogo;

/*********************************
 * Legato Image Asset
 * Name:   usbicon
 * Size:   83x49 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage usbicon;

/*********************************
 * Legato Image Asset
 * Name:   harmony
 * Size:   180x125 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage harmony;

/*********************************
 * Legato Image Asset
 * Name:   forward_music
 * Size:   100x84 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage forward_music;

/*********************************
 * Legato Image Asset
 * Name:   play_pause_music_0
 * Size:   100x75 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage play_pause_music_0;

/*********************************
 * Legato Image Asset
 * Name:   rewind_music
 * Size:   100x89 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage rewind_music;

/*********************************
 * Legato Image Asset
 * Name:   music_icon_1
 * Size:   30x34 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage music_icon_1;

/*********************************
 * Legato Image Asset
 * Name:   music_icon_3
 * Size:   30x30 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage music_icon_3;

/*********************************
 * Legato Image Asset
 * Name:   sdcard1_1
 * Size:   60x50 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage sdcard1_1;

/*****************************************************************************
 * Legato Graphics Font Assets
 *****************************************************************************/
/*********************************
 * Legato Font Asset
 * Name:         Arial
 * Height:       21
 * Baseline:     13
 * Style:        Antialias
 * Glyph Count:  95
 * Range Count:  16
 * Glyph Ranges: 0x20-0x7E
***********************************/
extern leRasterFont Arial;

/*********************************
 * Legato Font Asset
 * Name:         Arial_sm
 * Height:       21
 * Baseline:     13
 * Style:        Antialias
 * Glyph Count:  95
 * Range Count:  15
 * Glyph Ranges: 0x20-0x7E
***********************************/
extern leRasterFont Arial_sm;

/*********************************
 * Legato Font Asset
 * Name:         NotoMono_Regular
 * Height:       37
 * Baseline:     9
 * Style:        Plain
 * Glyph Count:  95
 * Range Count:  1
 * Glyph Ranges: 0x20-0x7E
***********************************/
extern leRasterFont NotoMono_Regular;

/*********************************
 * Legato Font Asset
 * Name:         Arial_black_vsm
 * Height:       21
 * Baseline:     10
 * Style:        Antialias
 * Glyph Count:  95
 * Range Count:  3
 * Glyph Ranges: 0x20-0x7E
***********************************/
extern leRasterFont Arial_black_vsm;

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 1
 * String Count:   24
 *****************************************************************************/

// language IDs
#define language_default    0

// string IDs
#define stringID_Of    0
#define stringID_NoMedium    1
#define stringID_zFileNotFound    2
#define stringID_SelectSource    3
#define stringID_FlashingComplete    4
#define stringID_endstring    5
#define stringID_Numbers    6
#define stringID_Ok    7
#define stringID_FileNotFound1    8
#define stringID_stringNumberFiller    9
#define stringID_RecordCount    10
#define stringID_Flashing    11
#define stringID_Musicplayertitle    12
#define stringID_NoValidMedium2    13
#define stringID_USB    14
#define stringID_Done    15
#define stringID_startstring    16
#define stringID_Title    17
#define stringID_FileNotFound2    18
#define stringID_SDCard    19
#define stringID_UnknownError    20
#define stringID_Initializing    21
#define stringID_InvalidFile    22
#define stringID_NoValidMedium    23

extern const leStringTable stringTable;


// string list
extern leTableString string_Of;
extern leTableString string_NoMedium;
extern leTableString string_zFileNotFound;
extern leTableString string_SelectSource;
extern leTableString string_FlashingComplete;
extern leTableString string_endstring;
extern leTableString string_Numbers;
extern leTableString string_Ok;
extern leTableString string_FileNotFound1;
extern leTableString string_stringNumberFiller;
extern leTableString string_RecordCount;
extern leTableString string_Flashing;
extern leTableString string_Musicplayertitle;
extern leTableString string_NoValidMedium2;
extern leTableString string_USB;
extern leTableString string_Done;
extern leTableString string_startstring;
extern leTableString string_Title;
extern leTableString string_FileNotFound2;
extern leTableString string_SDCard;
extern leTableString string_UnknownError;
extern leTableString string_Initializing;
extern leTableString string_InvalidFile;
extern leTableString string_NoValidMedium;

void initializeStrings(void);
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* LE_GEN_ASSETS_H */
