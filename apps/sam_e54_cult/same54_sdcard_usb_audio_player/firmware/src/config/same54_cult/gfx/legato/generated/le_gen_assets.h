/*******************************************************************************
 Module for Microchip Legato Graphics Library

  Company:
    Microchip Technology Inc.

  File Name:
    generated/le_gen_assets.h

  Summary:
    Header file containing a list of asset specifications for use with the
    MPLAB Harmony Graphics Stack.

  Description:
    Header file containing a list of asset specifications for use with the
    MPLAB Harmony Graphics Stack.
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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

/*****************************************************************************
* MPLAB Harmony Graphics Asset Location IDs
*****************************************************************************/
/*****************************************************************************
* MPLAB Harmony Graphics Image Assets
*****************************************************************************/
/*********************************
 * Legato Image Asset
 * Name:   mchpLogo
 * Size:   32x32 pixels
 * Format: RLE
 * Mode: RGB_565
 ***********************************/
extern leImage mchpLogo;

/*********************************
 * Legato Image Asset
 * Name:   sdcard_sm
 * Size:   32x32 pixels
 * Format: RLE
 * Mode: RGB_565
 ***********************************/
extern leImage sdcard_sm;

/*********************************
 * Legato Image Asset
 * Name:   usb_icon_sm
 * Size:   32x32 pixels
 * Format: RLE
 * Mode: RGB_565
 ***********************************/
extern leImage usb_icon_sm;

/*********************************
 * Legato Image Asset
 * Name:   mplabharmonylogo
 * Size:   150x111 pixels
 * Format: Raw
 * Mode: ARGB_8888
 ***********************************/
extern leImage mplabharmonylogo;

/*********************************
 * Legato Image Asset
 * Name:   forward_music_1
 * Size:   110x92 pixels
 * Format: Raw
 * Mode: ARGB_8888
 ***********************************/
extern leImage forward_music_1;

/*********************************
 * Legato Image Asset
 * Name:   music_icon_1
 * Size:   20x24 pixels
 * Format: Raw
 * Mode: ARGB_8888
 ***********************************/
extern leImage music_icon_1;

/*********************************
 * Legato Image Asset
 * Name:   music_icon_3
 * Size:   20x20 pixels
 * Format: Raw
 * Mode: ARGB_8888
 ***********************************/
extern leImage music_icon_3;

/*********************************
 * Legato Image Asset
 * Name:   play_pause_music
 * Size:   83x71 pixels
 * Format: Raw
 * Mode: ARGB_8888
 ***********************************/
extern leImage play_pause_music;

/*********************************
 * Legato Image Asset
 * Name:   rewind_music_1
 * Size:   110x98 pixels
 * Format: Raw
 * Mode: ARGB_8888
 ***********************************/
extern leImage rewind_music_1;

/*********************************
 * Legato Image Asset
 * Name:   sdcard1
 * Size:   50x42 pixels
 * Format: Raw
 * Mode: ARGB_8888
 ***********************************/
extern leImage sdcard1;

/*********************************
 * Legato Image Asset
 * Name:   usbicon
 * Size:   83x49 pixels
 * Format: Raw
 * Mode: ARGB_8888
 ***********************************/
extern leImage usbicon;

/*****************************************************************************
* MPLAB Harmony Graphics Font Assets
*****************************************************************************/
/*********************************
 * Legato Font Asset
 * Name:         Arial
 * Height:       18
 * Baseline:     13
 * Style:        Antialias
 * Glyph Count:  96
 * Range Count:  1
 * Glyph Ranges: 0x20-0x7F
***********************************/
extern leRasterFont Arial;

/*********************************
 * Legato Font Asset
 * Name:         Arial_sm
 * Height:       18
 * Baseline:     13
 * Style:        Antialias
 * Glyph Count:  96
 * Range Count:  1
 * Glyph Ranges: 0x20-0x7F
***********************************/
extern leRasterFont Arial_sm;

/*********************************
 * Legato Font Asset
 * Name:         Arial_black_vsm
 * Height:       14
 * Baseline:     10
 * Style:        Antialias
 * Glyph Count:  96
 * Range Count:  1
 * Glyph Ranges: 0x20-0x7F
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
#define string_Done    0
#define string_FileNotFound1    1
#define string_FileNotFound2    2
#define string_Flashing    3
#define string_FlashingComplete    4
#define string_Initializing    5
#define string_InvalidFile    6
#define string_Musicplayertitle    7
#define string_NoMedium    8
#define string_NoValidMedium    9
#define string_NoValidMedium2    10
#define string_Numbers    11
#define string_Of    12
#define string_Ok    13
#define string_RecordCount    14
#define string_SDCard    15
#define string_SelectSource    16
#define string_Title    17
#define string_USB    18
#define string_UnknownError    19
#define string_endstring    20
#define string_startstring    21
#define string_stringNumberFiller    22
#define string_zFileNotFound    23

extern const leStringTable stringTable;
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* LE_GEN_ASSETS_H */
