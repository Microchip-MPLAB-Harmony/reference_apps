/**
 * @file                  eink_bundle.h
 * @brief                 eINK
 *
 * @defgroup EINK
 * @brief eINK click Driver
 *
 * This is driver for eINK click board.
 *
 * @{
 *
 * ### Device Description ###
 *
 *
 *
 * ### Features ###
 *
 *
 * ### Library Description
 *
 * Library priovides access to all write functionalities.
 *
 * @example eink_ARM.c
 * @example eink_PIC.c
 * @example eink_PIC32.c
 * @example eink_dsPIC.c
 * @example eink_AVR.c
 * @example eink_FT90x.c
 *
 ******************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date    Software Version     Initials    Description
*  28/01/2020         1.0        MK        Modified.
*  15/04/2021         2.0        ST        Modified.
*****************************************************************************/
/****************************************************************************
* Note: In version 2.0, This file has been modified by ST to meet the custom
* application requirements. write to
* Microchip Technology India Pvt Ltd
* Plot No. 1498, EPIP, 1st Phase Industrial Area, Whitefield, Bengaluru,
* Karnataka 560066
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

#ifndef _EINK_BUNDLE_H_
#define _EINK_BUNDLE_H_

#include <stdint.h>

/**
 *
 * @name                 Display Colors
 ******************************************************************************/
///@{
#define EINK_COLOR_WHITE                    0xFF
#define EINK_COLOR_LIGHT_GREY               0xAA
#define EINK_COLOR_DARK_GREY                0x55
#define EINK_COLOR_BLACK                    0x00

/**
 * @name                 Font Direction
 ******************************************************************************/
///@{
#define FO_HORIZONTAL           (0)
#define FO_VERTICAL             (1)
#define FO_VERTICAL_COLUMN      (2)
///@}

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief eINK Initialization
 *
 * Initializes display with default settings.
 */
void eink_init( void );

/**
 * @brief eINK Set Font
 *
 * @param[in] font          Pointer to font definition
 * @param[in] color         Eink Display color
 * @param[in] orientation   Font direction
 *
 * Function must be called before text write function.
 */
void eink_set_font( const uint8_t *font, uint16_t color, uint8_t orientation );

/**
 * @brief Fills Screen Provided Color
 *
 * @param[in] color         Eink Display color
 */
void eink_fill_screen( uint8_t color );

/**
 * @brief Write Image in bmp format
 *
 * 2 bytes per pixel ( RGB 565 format )
 *
 * @param[in] img - pointer to the image
 *
 * @note Image must be 172x72 pixels size (24768 bytes)
 */
void eink_image_bmp( const uint8_t* img );

/**
 * @brief Write Text
 *
 * @param[in] text  input text
 * @param[in] x     horizontal offset
 * @param[in] y     vertical offset
 *
 * Writes text on eINK display.
 */
void eink_text( char *text, uint8_t x, uint8_t y );



#ifdef __cplusplus
} // extern "C"
#endif
#endif
///@}
/**
 * @}                                                           End of File
 ******************************************************************************/
