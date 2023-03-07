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
 * Name:          DDR
 ***********************************/
#define LE_STREAM_LOCATION_ID_DDR    1

/*****************************************************************************
 * Legato Graphics Image Assets
 *****************************************************************************/
/*********************************
 * Legato Image Asset
 * Name:   home
 * Size:   80x80 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage home;

/*********************************
 * Legato Image Asset
 * Name:   oncircle
 * Size:   100x100 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage oncircle;

/*********************************
 * Legato Image Asset
 * Name:   offcircle
 * Size:   100x100 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage offcircle;

/*********************************
 * Legato Image Asset
 * Name:   tbox
 * Size:   147x80 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage tbox;

/*********************************
 * Legato Image Asset
 * Name:   homeL
 * Size:   90x90 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage homeL;

/*********************************
 * Legato Image Asset
 * Name:   n1
 * Size:   160x160 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage n1;

/*********************************
 * Legato Image Asset
 * Name:   n2
 * Size:   160x160 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage n2;

/*********************************
 * Legato Image Asset
 * Name:   n3
 * Size:   160x160 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage n3;

/*****************************************************************************
 * Legato Graphics Font Assets
 *****************************************************************************/
/*********************************
 * Legato Font Asset
 * Name:         NotoSans_Regular
 * Height:       21
 * Baseline:     20
 * Style:        Antialias
 * Glyph Count:  97
 * Range Count:  18
 * Glyph Ranges: 0x1F-0x7E
                 0xB0
***********************************/
extern leRasterFont NotoSans_Regular;

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 1
 * String Count:   18
 *****************************************************************************/

// language IDs
#define language_Default    0

// string IDs
#define stringID_Device3    0
#define stringID_Online    1
#define stringID_Offline    2
#define stringID_Connectivity    3
#define stringID_GPIO2    4
#define stringID_String55    5
#define stringID_Off    6
#define stringID_String23    7
#define stringID_On    8
#define stringID_title    9
#define stringID_dbm    10
#define stringID_device    11
#define stringID_GPIO1    12
#define stringID_String0    13
#define stringID_Device2    14
#define stringID_LED    15
#define stringID_String1    16
#define stringID_Cese    17

extern const leStringTable stringTable;


// string list
extern leTableString string_Device3;
extern leTableString string_Online;
extern leTableString string_Offline;
extern leTableString string_Connectivity;
extern leTableString string_GPIO2;
extern leTableString string_String55;
extern leTableString string_Off;
extern leTableString string_String23;
extern leTableString string_On;
extern leTableString string_title;
extern leTableString string_dbm;
extern leTableString string_device;
extern leTableString string_GPIO1;
extern leTableString string_String0;
extern leTableString string_Device2;
extern leTableString string_LED;
extern leTableString string_String1;
extern leTableString string_Cese;

void initializeStrings(void);
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* LE_GEN_ASSETS_H */
