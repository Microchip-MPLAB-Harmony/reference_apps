/*******************************************************************************
  eink_epaper_2_9_296_128_example Source file

  Company:
    Microchip Technology Inc.

  File Name:
    eink_epaper_2_9_296_128_example.c

  Summary:
    This File has function calls necessary
    for navigating through various functions.

  Description:
    This File contains the char array/ string message which needs to be
    displayed on E-Paper.This file has complete flow of function calls starting
    from initialization of E-Paper then displaying of image.
    Finally it sets the text parameters and then goes to the text function call.
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
// ------------------------------------------------------------------- INCLUDES
#include "eink_epaper_2_9_296_128.h"
#include "eink_epaper_2_9_296_128_example.h"
#include "eink_epaper_2_9_296_128_image.h"
#include "eink_epaper_2_9_296_128_font.h"

char lcl_buffer[ ]  =   "E-Paper";
char lcl_buffer1[ ] = "Example";

void eink_epaper_2_9_296_128_example ( void )
{
    eink_epaper_2_9_296_128_init( );
    eink_epaper_2_9_296_128_image_bmp( mchp_logo );
    eink_epaper_2_9_296_128_fill_screen( EINK_EPAPER_2_9_296_128_COLOR_BLACK );
    eink_epaper_2_9_296_128_set_font( guiFont_Tahoma_10_Regular, EINK_EPAPER_2_9_296_128_COLOR_WHITE, FO_HORIZONTAL );
    eink_epaper_2_9_296_128_text(lcl_buffer, 14, 148 );
    eink_epaper_2_9_296_128_text(lcl_buffer1, 12, 170 );
}

// ------------------------------------------------------------------------ END
