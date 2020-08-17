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
*******************************************************************************/

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
