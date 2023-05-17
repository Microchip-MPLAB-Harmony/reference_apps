/*******************************************************************************
    eink_epaper_2_9_296_128 Header File

  Company:
    Microchip Technology Inc.

  File Name:
    eink_epaper_2_9_296_128.h

  Summary:
    Header file of the E-Paper Display Functionality Application

  Description:
    This file contains prototypes of public functions
     and few macros used in the application
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

#ifndef EINK_EPAPER_2_9_296_128_H
#define EINK_EPAPER_2_9_296_128_H

#include <stdint.h>

// -------------------------------------------------------------- PUBLIC MACROS
/**
 * \defgroup macros Macros
 * \{
 */

#define EINK_EPAPER_2_9_296_128_COLOR_WHITE                              0xFF
#define EINK_EPAPER_2_9_296_128_COLOR_BLACK                              0x00
#define EINK_EPAPER_2_9_296_128_COLOR_LIGHT_GREY                         0xAA
#define EINK_EPAPER_2_9_296_128_COLOR_DARK_GREY                          0x55

#define FO_HORIZONTAL                                   0x00
#define FO_VERTICAL                                     0x01
#define FO_VERTICAL_COLUMN                              0x02

#ifdef __cplusplus
extern "C"{
#endif

/* Function:
  void eink_epaper_2_9_296_128_fill_screen ( uint16_t color);

  Summary:
    This function resets the frame.

  Description:
    This function resets the frame with specified color, frame and display size.

  Remarks:
    Refer eink_epaper_2_9_296_128.c file for more information.
*/
void eink_epaper_2_9_296_128_fill_screen( uint8_t color );

/* Function:
  eink_epaper_2_9_296_128_image_bmp ( const uint8_t* img );

  Summary:
    This function displays image.

  Description:
    This function displays image from the array present in epaper_image.c source file.

  Remarks:
    Refer eink_epaper_2_9_296_128.c file for more information.
*/
void eink_epaper_2_9_296_128_image_bmp ( const uint8_t* img );

/* Function:
  eink_epaper_2_9_296_128_text ( char *text, uint8_t x, uint8_t y );

  Summary:
    This function displays text.

  Description:
    This function displays text by using font parameters like buffer and
    coordinates

  Remarks:
    Refer eink_epaper_2_9_296_128.c file for more information.
*/
void eink_epaper_2_9_296_128_text( char *text, uint8_t x, uint8_t y );
/* Function:
  void eink_epaper_2_9_296_128_set_font( const uint8_t *font, uint16_t color, uint8_t orientation );

  Summary:
    This function sets the font.

  Description:
    This function sets the font style and size from array (eink_epaper_2_9_296_128_text.c) ,
    the position of the first character by taking x and y coordinates and sets
    the other parameters like orientation, color , width and height.

  Remarks:
    Refer eink_epaper_2_9_296_128.c file for more information.
*/
void eink_epaper_2_9_296_128_set_font( const uint8_t *font, uint16_t color, uint8_t orientation );

/* Function:
  void eink_epaper_2_9_296_128_init (void);

  Summary:
    Initializes E-Paper display module.

  Description:
    This function initializes E-Paper display module.
    It resets and configures the E-Paper display module.

  Remarks:
    Refer eink_epaper_2_9_296_128.c file for more information.
*/
void eink_epaper_2_9_296_128_init(void);

#ifdef __cplusplus
}
#endif
#endif  // EINK_EPAPER_2_9_296_128_H

/** \} */ // End public_function group
/// \}    // End click Driver group
/*! @} */
// ------------------------------------------------------------------------- END
