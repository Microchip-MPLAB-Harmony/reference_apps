/*******************************************************************************
  MPLAB Harmony GFX definition/porting Header File

  Company:
    Microchip Technology Inc.

  File Name:
    gfx_definitions.h

  Summary:
    This header file provides prototypes and definitions for the GFX library.

  Description:
    Add your GFX porting interface in this file.
    Note: this gfx library is ported from ASF.
*******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#ifndef _GFX_DEFINITIONS_H    /* Guard against multiple inclusion */
#define _GFX_DEFINITIONS_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include "definitions.h"

/*
 * Porting code definition for GFX mono library
 */
#define GFX_DELAY_FUNCTION(x)           vTaskDelay( pdMS_TO_TICKS( x ) )
#define GFX_SPI_WRITE_FUNCTION(x,y)     SERCOM4_SPI_Write(x, y)
#define GFX_SPI_IS_BUSY()               SERCOM4_SPI_IsBusy()
#define GFX_DISPLAY_RESET_CLEAR()       OLED_DISP_RESET_Clear()
#define GFX_DISPLAY_RESET_SET()         OLED_DISP_RESET_Set()
#define GFX_DISPLAY_SS_N_CLEAR()        OLED_DISP_CS_Clear()
#define GFX_DISPLAY_SS_N_SET()          OLED_DISP_CS_Set()
#define GFX_DATA_CMD_SEL_CLEAR()        OLED_DISP_DATA_CMD_SEL_Clear()
#define GFX_DATA_CMD_SEL_SET()          OLED_DISP_DATA_CMD_SEL_Set()

#define GFX_MONO_UG_2832HSWEG04
#include "gfx_mono/gfx_mono_text.h"

extern struct font sysfont;

#endif /* _GFX_DEFINITIONS_H */

/* *****************************************************************************
 End of File
 */
