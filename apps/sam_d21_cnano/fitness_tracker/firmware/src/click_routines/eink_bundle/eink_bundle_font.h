/**************************CHANGE LIST **************************************
*
*    Date    Software Version     Initials    Description
*  28/01/2020         1.0        MK        Modified.
*  15/04/2021         2.0        ST        Modified.
*****************************************************************************/

/****************************************************************************
* Note: In version 2.0, This file has been modified by ST to meet the custom
* application requirements. Should you need to contact the modifier write to
* Microchip Technology India Pvt Ltd
* Plot No. 1498, EPIP, 1st Phase Industrial Area, Whitefield, Bengaluru,
* Karnataka 560066
*******************************************************************************/
/*******************************************************************************
 Copyright (C) 2017  Microchip Technology Incorporated and its subsidiaries.

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*******************************************************************************/


#ifndef _EINK_BUNDLE_FONT_H_
#define _EINK_BUNDLE_FONT_H_


/* This file contains additional fonts.
   To use these fonts in your application, uncomment the below macro(s) */
#define EINK_BUNDLE_GUIFONT_TAHOMA_14_REGULAR
// #define EINK_BUNDLE_GUIFONT_TAHOMA_8_REGULAR
// #define EINK_BUNDLE_GUIFONT_TAHOMA_7_REGULAR
// #define EINK_BUNDLE_GUIFONT_TAHOMA_6_REGULAR
// #define EINK_BUNDLE_GUIFONT_TAHOMA_18_REGULAR
// #define EINK_BUNDLE_GUIFONT_EXO_2_CONDENSED21X32_REGULAR
// #define EINK_BUNDLE_GUIFONT_EXO_2_CONDENSED10X16_REGULAR
// #define EINK_BUNDLE_GUIFONT_EXO_2_CONDENSED15X23_REGULAR
// #define EINK_BUNDLE_GUIFONT_TAHOMA_16_REGULAR
// #define EINK_BUNDLE_GUIFONT_TAHOMA_10_REGULAR
// #define EINK_BUNDLE_GUIFONT_ROBOTO_MONO11X23_REGULAR


#include <stdint.h>

#ifdef EINK_BUNDLE_GUIFONT_TAHOMA_14_REGULAR
extern const uint8_t  guiFont_Tahoma_14_Regular[];
#endif

#ifdef EINK_BUNDLE_GUIFONT_TAHOMA_8_REGULAR
extern const uint8_t guiFont_Tahoma_8_Regular[];
#endif

#ifdef EINK_BUNDLE_GUIFONT_TAHOMA_7_REGULAR
extern const uint8_t guiFont_Tahoma_7_Regular[];
#endif

#ifdef EINK_BUNDLE_GUIFONT_TAHOMA_6_REGULAR
extern const uint8_t  guiFont_Tahoma_6_Regular[];
#endif

#ifdef EINK_BUNDLE_GUIFONT_TAHOMA_18_REGULAR
extern const uint8_t guiFont_Tahoma_18_Regular[];
#endif

#ifdef EINK_BUNDLE_GUIFONT_EXO_2_CONDENSED21X32_REGULAR
extern const uint8_t guiFont_Exo_2_Condensed21x32_Regular[];
#endif

#ifdef EINK_BUNDLE_GUIFONT_EXO_2_CONDENSED10X16_REGULAR
extern const uint8_t guiFont_Exo_2_Condensed10x16_Regular[];
#endif

#ifdef EINK_BUNDLE_GUIFONT_EXO_2_CONDENSED15X23_REGULAR
extern const uint8_t guiFont_Exo_2_Condensed15x23_Regular[];
#endif

#ifdef EINK_BUNDLE_GUIFONT_TAHOMA_16_REGULAR
extern const uint8_t guiFont_Tahoma_16_Regular[];
#endif

#ifdef EINK_BUNDLE_GUIFONT_TAHOMA_10_REGULAR
extern const uint8_t guiFont_Tahoma_10_Regular[];
#endif

#ifdef EINK_BUNDLE_GUIFONT_ROBOTO_MONO11X23_REGULAR
extern const uint8_t guiFont_Roboto_Mono11x23_Regular[];
#endif

#endif // _EINK_BUNDLE_FONT_H_