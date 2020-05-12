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

/*******************************************************************************
  MPLAB Harmony Graphics Asset Header File

  File Name:
    gfx_assets.h

  Summary:
    Header file containing a list of asset specifications for use with the
	MPLAB Harmony Graphics Stack.

  Description:
    Header file containing a list of asset specifications for use with the
	MPLAB Harmony Graphics Stack.

    Created with MPLAB Harmony Version 3.0
*******************************************************************************/


#ifndef GFX_ASSETS_H
#define GFX_ASSETS_H

#include "gfx/utils/gfx_utils.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END 

/*** Generated Asset Descriptors ***/
/*****************************************************************************
 * MPLAB Harmony Graphics Asset Location IDs
 *****************************************************************************/
#define GFXU_ASSET_LOCATION_ID_INTERNAL    0
 
/*****************************************************************************
 * MPLAB Harmony Graphics Image Assets
 *****************************************************************************/
/*********************************
 * GFX Image Asset
 * Name:   AudioMute16_2
 * Size:   32x25 pixels
 * Mode:   INDEX_4
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset AudioMute16_2;
	
/*********************************
 * GFX Image Asset
 * Name:   AudioPlay16_2
 * Size:   29x22 pixels
 * Mode:   INDEX_4
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset AudioPlay16_2;
	
/*********************************
 * GFX Image Asset
 * Name:   MCHP_LOGO
 * Size:   122x30 pixels
 * Mode:   RGB_888
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset MCHP_LOGO;
	
/*****************************************************************************
 * MPLAB Harmony Graphics Palette Assets
 *****************************************************************************/
/*********************************
 * GFX Palette Asset
 * Name:   AudioMute16_2_palette
 * Colors: 6
 * Format: RGB_888
 ***********************************/
extern GFXU_PaletteAsset AudioMute16_2_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   AudioPlay16_2_palette
 * Colors: 5
 * Format: RGB_888
 ***********************************/
extern GFXU_PaletteAsset AudioPlay16_2_palette;
	
/*****************************************************************************
 * MPLAB Harmony Graphics Font Assets
 *****************************************************************************/
/*********************************
 * GFX Font Asset
 * Name:         Arial14pt
 * Height:       17
 * Style:        Plain
 * Glyph Count:  96
 * Range Count:  1
 * Glyph Ranges: 0x20-0x7F
 ***********************************/
extern GFXU_FontAsset Arial14pt;
	
/*********************************
 * GFX Font Asset
 * Name:         Arial18pt
 * Height:       22
 * Style:        Plain
 * Glyph Count:  1
 * Range Count:  1
 * Glyph Ranges: 0x5E
 ***********************************/
extern GFXU_FontAsset Arial18pt;
	
/*****************************************************************************
 * MPLAB Harmony Graphics String Table
 *****************************************************************************/
/*********************************
 * GFX String Table
 * Name:         stringTable
 * Encoding:     ASCII
 * Languages:    default
 * String Count: 7
 ***********************************/
// language IDs
#define language_default    0

// string IDs
#define string_GroupBoxTitle    0
#define string_NoFilesMessage    1
#define string_RadioButtonPlayer    2
#define string_RadioButtonReader    3
#define string_ScrollDown    4
#define string_ScrollUp    5
#define string_TitleString    6
 
extern GFXU_StringTableAsset stringTable;

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* GFX_ASSETS_H */

