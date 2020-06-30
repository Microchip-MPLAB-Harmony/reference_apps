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
 * Name:   Converted_135447_1586215954_M19899_medical_clear
 * Size:   40x38 pixels
 * Format: Raw
 * Mode: INDEX_4
 ***********************************/
extern leImage Converted_135447_1586215954_M19899_medical_clear;

/*********************************
 * Legato Image Asset
 * Name:   MicrochipLogoHorizontalWhiteRed
 * Size:   250x58 pixels
 * Format: Raw
 * Mode: RGB_565
 ***********************************/
extern leImage MicrochipLogoHorizontalWhiteRed;

/*********************************
 * Legato Image Asset
 * Name:   Bar_1
 * Size:   800x91 pixels
 * Format: Raw
 * Mode: RGB_565
 ***********************************/
extern leImage Bar_1;

/*********************************
 * Legato Image Asset
 * Name:   PIC32Logo
 * Size:   240x62 pixels
 * Format: Raw
 * Mode: RGB_888
 ***********************************/
extern leImage PIC32Logo;

/*****************************************************************************
* MPLAB Harmony Graphics Font Assets
*****************************************************************************/
/*********************************
 * Legato Font Asset
 * Name:         Level_label_font
 * Height:       76
 * Baseline:     57
 * Style:        Plain
 * Glyph Count:  96
 * Range Count:  1
 * Glyph Ranges: 0x20-0x7F
***********************************/
extern leRasterFont Level_label_font;

/*********************************
 * Legato Font Asset
 * Name:         Snake_size_text
 * Height:       23
 * Baseline:     17
 * Style:        Plain
 * Glyph Count:  96
 * Range Count:  1
 * Glyph Ranges: 0x20-0x7F
***********************************/
extern leRasterFont Snake_size_text;

/*********************************
 * Legato Font Asset
 * Name:         Snake_life_label
 * Height:       30
 * Baseline:     22
 * Style:        Plain
 * Glyph Count:  96
 * Range Count:  1
 * Glyph Ranges: 0x20-0x7F
***********************************/
extern leRasterFont Snake_life_label;

/*********************************
 * Legato Font Asset
 * Name:         Game_Over_label
 * Height:       86
 * Baseline:     65
 * Style:        Plain
 * Glyph Count:  96
 * Range Count:  1
 * Glyph Ranges: 0x20-0x7F
***********************************/
extern leRasterFont Game_Over_label;

/*********************************
 * Legato Font Asset
 * Name:         Game_title_font
 * Height:       34
 * Baseline:     26
 * Style:        Plain
 * Glyph Count:  13
 * Range Count:  10
 * Glyph Ranges: 0x20
                 0x33
                 0x47-0x48
                 0x53
                 0x61
                 0x65
                 0x6B
                 0x6D-0x6F
                 0x72
                 0x79
***********************************/
extern leRasterFont Game_title_font;

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 2
 * String Count:   10
*****************************************************************************/

// language IDs
#define language_default    0
#define language_New_Language    1

// string IDs
#define string_Game_Over_Text    0
#define string_Game_Won_Text    1
#define string_Game_title_label    2
#define string_Level1    3
#define string_Level2    4
#define string_Level3    5
#define string_Snake_Lifes_label    6
#define string_Snake_Size_text    7
#define string_Snake_size_value_level_1    8
#define string_Snake_size_value_level_2    9

extern const leStringTable stringTable;
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* LE_GEN_ASSETS_H */
