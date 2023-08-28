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
 * Name:          NewUserLocation_0
 ***********************************/
#define LE_STREAM_LOCATION_ID_NewUserLocation_0    1

/*****************************************************************************
 * Legato Graphics Image Assets
 *****************************************************************************/
/*********************************
 * Legato Image Asset
 * Name:   oled_c
 * Size:   96x96 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage oled_c;

/*********************************
 * Legato Image Asset
 * Name:   logo
 * Size:   20x19 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage logo;

/*********************************
 * Legato Image Asset
 * Name:   nonsecure
 * Size:   20x24 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage nonsecure;

/*********************************
 * Legato Image Asset
 * Name:   secure
 * Size:   16x20 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage secure;

/*********************************
 * Legato Image Asset
 * Name:   S
 * Size:   40x50 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage S;

/*********************************
 * Legato Image Asset
 * Name:   NS
 * Size:   40x49 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage NS;

/*********************************
 * Legato Image Asset
 * Name:   MCHP
 * Size:   20x18 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage MCHP;

/*********************************
 * Legato Image Asset
 * Name:   Orginal_NonSecure
 * Size:   30x45 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage Orginal_NonSecure;

/*********************************
 * Legato Image Asset
 * Name:   Orginal_Secure
 * Size:   30x46 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage Orginal_Secure;

/*****************************************************************************
 * Legato Graphics Font Assets
 *****************************************************************************/
/*********************************
 * Legato Font Asset
 * Name:         NotoSans_Bold
 * Height:       21
 * Baseline:     9
 * Style:        Plain
 * Glyph Count:  95
 * Range Count:  1
 * Glyph Ranges: 0x20-0x7E
***********************************/
extern leRasterFont NotoSans_Bold;

/*********************************
 * Legato Font Asset
 * Name:         NotoMono_Regular
 * Height:       37
 * Baseline:     9
 * Style:        Plain
 * Glyph Count:  95
 * Range Count:  9
 * Glyph Ranges: 0x20-0x7E
***********************************/
extern leRasterFont NotoMono_Regular;

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 1
 * String Count:   3
 *****************************************************************************/

// language IDs
#define language_Default    0

// string IDs
#define stringID_Temp    0
#define stringID_Light    1
#define stringID_String    2

extern const leStringTable stringTable;


// string list
extern leTableString string_Temp;
extern leTableString string_Light;
extern leTableString string_String;

void initializeStrings(void);
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* LE_GEN_ASSETS_H */
