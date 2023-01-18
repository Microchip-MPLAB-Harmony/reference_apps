/*******************************************************************************
  eink_epaper_2_9_296_128_font Header File

  Company:
    Microchip Technology Inc.

  File Name:
    eink_epaper_2_9_296_128_font.h

  Summary:
    Font Header File which contains various Fonts

  Description:
    This file contains prototypes for various font style arrays
 *******************************************************************************/
// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
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


#ifndef EINK_EPAPER_2_9_296_128_FONT_H
#define EINK_EPAPER_2_9_296_128_FONT_H


/* This file contains additional fonts.
   To use these fonts in your application, uncomment the below macro(s) */
//#define EINK_EPAPER_2_9_296_128__GUIFONT_TAHOMA_14_REGULAR
// #define EINK_EPAPER_2_9_296_128__GUIFONT_TAHOMA_8_REGULAR
// #define EINK_EPAPER_2_9_296_128__GUIFONT_TAHOMA_7_REGULAR
// #define EINK_EPAPER_2_9_296_128__GUIFONT_TAHOMA_6_REGULAR
// #define EINK_EPAPER_2_9_296_128__GUIFONT_TAHOMA_18_REGULAR
// #define EINK_EPAPER_2_9_296_128__GUIFONT_EXO_2_CONDENSED21X32_REGULAR
// #define EINK_EPAPER_2_9_296_128__GUIFONT_EXO_2_CONDENSED10X16_REGULAR
// #define EINK_EPAPER_2_9_296_128__GUIFONT_EXO_2_CONDENSED15X23_REGULAR
// #define EINK_EPAPER_2_9_296_128__GUIFONT_TAHOMA_16_REGULAR
 #define EINK_EPAPER_2_9_296_128__GUIFONT_TAHOMA_10_REGULAR
// #define EINK_EPAPER_2_9_296_128__GUIFONT_ROBOTO_MONO11X23_REGULAR


#include <stdint.h>

#ifdef EINK_EPAPER_2_9_296_128__GUIFONT_TAHOMA_14_REGULAR
extern const uint8_t  guiFont_Tahoma_14_Regular[];
#endif

#ifdef EINK_EPAPER_2_9_296_128__GUIFONT_TAHOMA_8_REGULAR
extern const uint8_t guiFont_Tahoma_8_Regular[];
#endif

#ifdef EINK_EPAPER_2_9_296_128__GUIFONT_TAHOMA_7_REGULAR
extern const uint8_t guiFont_Tahoma_7_Regular[];
#endif

#ifdef EINK_EPAPER_2_9_296_128__GUIFONT_TAHOMA_6_REGULAR
extern const uint8_t  guiFont_Tahoma_6_Regular[];
#endif

#ifdef EINK_EPAPER_2_9_296_128__GUIFONT_TAHOMA_18_REGULAR
extern const uint8_t guiFont_Tahoma_18_Regular[];
#endif

#ifdef EINK_EPAPER_2_9_296_128__GUIFONT_EXO_2_CONDENSED21X32_REGULAR
extern const uint8_t guiFont_Exo_2_Condensed21x32_Regular[];
#endif

#ifdef EINK_EPAPER_2_9_296_128__GUIFONT_EXO_2_CONDENSED10X16_REGULAR
extern const uint8_t guiFont_Exo_2_Condensed10x16_Regular[];
#endif

#ifdef EINK_EPAPER_2_9_296_128__GUIFONT_EXO_2_CONDENSED15X23_REGULAR
extern const uint8_t guiFont_Exo_2_Condensed15x23_Regular[];
#endif

#ifdef EINK_EPAPER_2_9_296_128__GUIFONT_TAHOMA_16_REGULAR
extern const uint8_t guiFont_Tahoma_16_Regular[];
#endif

#ifdef EINK_EPAPER_2_9_296_128__GUIFONT_TAHOMA_10_REGULAR
extern const uint8_t guiFont_Tahoma_10_Regular[];
#endif

#ifdef EINK_EPAPER_2_9_296_128__GUIFONT_ROBOTO_MONO11X23_REGULAR
extern const uint8_t guiFont_Roboto_Mono11x23_Regular[];
#endif

#endif // EINK_EPAPER_2_9_296_128_FONT_H