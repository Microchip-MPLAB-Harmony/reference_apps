/*
 * eink.c
 *
 * Revision Log :
 * - 0.0.1 (Nov/2016) Module created                        MilosV
 * - 0.0.2 (Jan/2017) Documentation added                   MilosV
 * - 0.0.3 (Jan/2020) Modified                              MK
 * To Do List :
 * @todo
 *
 ******************************************************************************/
/****************************************************************************
* Note: In version 0.0.3, This file has been modified by MK to meet the custom 
* application requirements. Should you need to contact the modifier, Write an 
* Email to mohan.kumar@microchip.com or alternatively, write to 
* Mohan Kumar, Microchip Technology India Pvt Ltd
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
#include "../include/eink.h"
#include "peripheral/port/plib_port.h"
#include <math.h>
#include <string.h>

#define _EINK_RAW_IMG_SIZE      3096
#define _EINK_BMP_IMG_SIZE      24768

/*                Variables
 ******************************************************************************/

//extern sfr sbit EINK_C_CS;
//extern sfr sbit EINK_C_RST;
//extern sfr sbit EINK_C_DC;
//extern sfr sbit EINK_C_BSY;

/* Default settings */
//static uint8_t EINK_Y                           = 0xAB;
//static uint8_t EINK_X                           = 0x11;
static uint8_t EINK_SENSE_DURATION_DEF[ 1 ]     = { 0x04 };
static uint8_t EINK_DATA_SLEEP_DEF[ 1 ]         = { 0x00 };
static uint8_t EINK_DATA_ENTRY_DEF[ 1 ]         = { 0x03 };
static uint8_t EINK_RAM_X_START_END_DEF[ 2 ]    = { 0x00, 0x11 };
static uint8_t EINK_RAM_Y_START_END_DEF[ 2 ]    = { 0x00, 0xAB };
static uint8_t EINK_RAM_X_COUNTER_DEF[ 1 ]      = { 0x00 };
static uint8_t EINK_RAM_Y_COUNTER_DEF[ 1 ]      = { 0x00 };
static uint8_t EINK_BOOSTER_SELSECTION_DEF[ 1 ] = { 0x1F };
static uint8_t EINK_DISPLAY_UPDATE_CTL1_DEF[ 1 ]= { 0x03 };
static uint8_t EINK_VCOM_WREG_DEF[ 1 ]          = { 0xA0 };
static uint8_t EINK_BORDER_WF_DEF[ 1 ]          = { 0x63 };
static uint8_t EINK_DISPLAY_UPDATE_CTL2_1[ 1 ]  = { 0xC0 };
static uint8_t EINK_DISPLAY_UPDATE_CTL2_2[ 1 ]  = { 0xC4 };
static uint8_t EINK_DISPLAY_UPDATE_CTL2_3[ 1 ]  = { 0x02 };

/* Text Variables */
static const uint8_t*   _font;
static uint16_t         _font_color;
static uint8_t          _font_orientation;
static uint16_t         _font_first_char;
static uint16_t         _font_last_char;
static uint16_t         _font_height;
static uint16_t         x_cord;
static uint16_t         y_cord;

/* Frame buffer */
static uint8_t          _frame[ _EINK_RAW_IMG_SIZE ];

/******************************************************************************
* Private Function Prototypes
*******************************************************************************/

static void _frame_px( uint8_t x, uint8_t y, uint8_t font_col );
static void _char_wr( uint16_t ch_idx );

/******************************************************************************
* Private Function Definitions
*******************************************************************************/

static void _frame_px( uint8_t x, uint8_t y, uint8_t font_col )
{
    uint8_t  off;
    uint16_t pos;

    pos = (y * 18) + (x / 4);
    off = fabs(3 - (x % 4)) * 2;
    
    _frame[ pos ] &= ~( 0x03 << off );
    _frame[ pos ] |= ( ( font_col & 0x03 ) << off );
}

static void _char_wr( uint16_t ch_idx )
{
    uint8_t     ch_width = 0;
    uint8_t     x_cnt;
    uint8_t     y_cnt;
    uint16_t    x = 0;
    uint16_t    y = 0;
    uint16_t    tmp;
    uint8_t     temp = 0;
    uint8_t     mask = 0;
    uint32_t    offset;
    const uint8_t *ch_table;
    const uint8_t *ch_bitmap;

    if( ch_idx < _font_first_char )
        return;

    if( ch_idx > _font_last_char )
        return;

    offset = 0;
    tmp = (ch_idx - _font_first_char) << 2;
    ch_table = _font + 8 + tmp;
    ch_width = *ch_table;

    offset = (uint32_t)ch_table[1] + ((uint32_t)ch_table[2] << 8) + ((uint32_t)ch_table[3] << 16);

    ch_bitmap = _font + offset;

    if( ( _font_orientation == FO_HORIZONTAL ) ||
        ( _font_orientation == FO_VERTICAL_COLUMN ) )
    {
        y = y_cord;
        for (y_cnt = 0; y_cnt < _font_height; y_cnt++)
        {
            x = x_cord;
            mask = 0;
            for( x_cnt = 0; x_cnt < ch_width; x_cnt++ )
            {
                if( !mask )
                {
                    temp = *ch_bitmap++;
                    mask = 0x01;
                }

                if( temp & mask )
                {
                    _frame_px( x, y, _font_color );
                }

                x++;
                mask <<= 1;
            }
            y++;
        }

        if ( _font_orientation == FO_HORIZONTAL )
            x_cord = x + 1;
        else
            y_cord = y;
    }
    else
    {
        y = x_cord;

        for( y_cnt = 0; y_cnt < _font_height; y_cnt++ )
        {
            x = y_cord;
            mask = 0;

            for( x_cnt = 0; x_cnt < ch_width; x_cnt++ )
            {
                if( mask == 0 )
                {
                    temp = *ch_bitmap++;
                    mask = 0x01;
                }

                if( temp & mask )
                {
                    _frame_px( x, y, _font_color );
                }

                x--;
                mask <<= 1;
            }
            y++;
        }
        y_cord = x - 1;
    }
}

/******************************************************************************
* Function Definitions
*******************************************************************************/
static uint8_t LUT_TME21[]=
{
0x82,0x00,0x00,0x00,0xAA,0x00,0x00,0x00,0xAA,
0xAA,0x00,0x00,0xAA,0xAA,0xAA,0x00,0x55,0xAA,
0xAA,0x00,0x55,0x55,0x55,0x55,0xAA,0xAA,0xAA,
0xAA,0x55,0x55,0x55,0x55,0xAA,0xAA,0xAA,0xAA,
0x15,0x15,0x15,0x15,0x05,0x05,0x05,0x05,0x01,
0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x41,
0x45,0xF1,0xFF,0x5F,0x55,0x01,0x00,0x00,0x00
};
void eink_init( void )
{
    hal_eink_init();
    EINK_C_DC_Set(); 
    EINK_C_CS_Set();
    EINK_C_RST_Set();
    eink_reset();
    hal_eink_delay(1000);
    eink_write_cmd(EINK_DEEP_SLEEP,           EINK_DATA_SLEEP_DEF, 1);
    eink_write_cmd(EINK_DATA_ENTRY,           EINK_DATA_ENTRY_DEF, 1);
    eink_write_cmd(EINK_RAM_X_START_END,      EINK_RAM_X_START_END_DEF, 2);
    eink_write_cmd(EINK_RAM_Y_START_END,      EINK_RAM_Y_START_END_DEF, 2);
    eink_write_cmd(EINK_RAM_X_COUNTER,        EINK_RAM_X_COUNTER_DEF, 1);
    eink_write_cmd(EINK_RAM_Y_COUNTER,        EINK_RAM_Y_COUNTER_DEF, 1);
    eink_write_cmd(EINK_VCOM_SENSE_DUR,       EINK_SENSE_DURATION_DEF, 1);
    eink_write_cmd(EINK_VCOM_SENSE,           NULL, 0);
    eink_write_cmd(EINK_DISPLAY_UPDATE_CTL2,  EINK_DISPLAY_UPDATE_CTL2_1, 1);
    eink_write_cmd(EINK_MASTER_ON,            NULL, 0);
    eink_write_cmd(EINK_TEMPERATURE_LOAD,     NULL, 0);
    eink_write_cmd(EINK_BOOSTER_SELSECTION,   EINK_BOOSTER_SELSECTION_DEF, 1);
    eink_write_cmd(EINK_DISPLAY_UPDATE_CTL1,  EINK_DISPLAY_UPDATE_CTL1_DEF, 1);
    eink_write_cmd(EINK_VCOM_WREG,            EINK_VCOM_WREG_DEF, 1);
    eink_write_cmd(EINK_BORDER_WF,            EINK_BORDER_WF_DEF, 1);
    eink_write_cmd(EINK_DISPLAY_UPDATE_CTL2,  EINK_DISPLAY_UPDATE_CTL2_2, 1);
    eink_write_cmd(EINK_WRITE_LUT,            LUT_TME21, sizeof(LUT_TME21));
}

void eink_reset( void )
{
    hal_eink_delay( 1 );
    EINK_C_RST_Clear();
    hal_eink_delay( 2 );
    EINK_C_RST_Set();
    hal_eink_delay( 1000 );
}

void eink_write_cmd( uint8_t command, uint8_t *args, uint16_t args_len )
{
    uint8_t *ptr = args;

    while( EINK_C_BSY_Get() == 1 );
    EINK_C_CS_Clear();
    EINK_C_DC_Clear();
    hal_eink_write( &command, 1  );
    EINK_C_DC_Set();
    if( args_len )
        hal_eink_write( ptr, args_len );
    EINK_C_CS_Set();
    while( EINK_C_BSY_Get() == 1 );
}

void eink_set_font( const uint8_t *font, uint16_t color, uint8_t orientation )
{
    _font               = font;
    _font_first_char    = font[2] + (font[3] << 8);
    _font_last_char     = font[4] + (font[5] << 8);
    _font_height        = font[6];
    _font_color         = color;
    _font_orientation   = orientation ;
}

void eink_fill_screen( uint8_t color )
{
    uint8_t     command = EINK_WRITE_RAM;
    uint16_t    repeats = _EINK_RAW_IMG_SIZE;

    eink_write_cmd( EINK_RAM_X_START_END, EINK_RAM_X_START_END_DEF, 2 );
    eink_write_cmd( EINK_RAM_Y_START_END, EINK_RAM_Y_START_END_DEF, 2 );
    eink_write_cmd( EINK_RAM_X_COUNTER, EINK_RAM_X_COUNTER_DEF, 1 );
    eink_write_cmd( EINK_RAM_Y_COUNTER, EINK_RAM_Y_COUNTER_DEF, 1 );
    eink_write_cmd( EINK_BOOSTER_SELSECTION, EINK_BOOSTER_SELSECTION_DEF, 1 );
    eink_write_cmd( EINK_DISPLAY_UPDATE_CTL1, EINK_DISPLAY_UPDATE_CTL1_DEF, 1 );
    eink_write_cmd( EINK_VCOM_WREG, EINK_VCOM_WREG_DEF, 1 );
    eink_write_cmd( EINK_BORDER_WF, EINK_BORDER_WF_DEF, 1 );
    eink_write_cmd( EINK_DISPLAY_UPDATE_CTL2, EINK_DISPLAY_UPDATE_CTL2_2, 1 );
    while( EINK_C_BSY_Get() == 1 );
    EINK_C_CS_Clear(); 
    EINK_C_DC_Clear(); 
    hal_eink_write( &command, 1 );
    EINK_C_DC_Clear(); 
    while( repeats-- )
        hal_eink_write( &color, 1 );
    EINK_C_CS_Set();
    eink_write_cmd( EINK_MASTER_ON, NULL, 0);
    eink_write_cmd( EINK_DISPLAY_UPDATE_CTL2, EINK_DISPLAY_UPDATE_CTL2_3, 1 );
    eink_write_cmd( EINK_MASTER_ON, NULL, 0);
    memset( _frame, color, _EINK_RAW_IMG_SIZE );
}

void eink_image_bmp(const uint8_t* img )
{
    uint8_t     cmd;
    uint8_t     tmp;
    uint8_t     tmp_pix;
    uint16_t    cnt;
    uint16_t    fr_cnt;
    uint16_t    pixel;

    fr_cnt = 0;
    cmd     = EINK_WRITE_RAM;
    eink_write_cmd(EINK_RAM_X_START_END, EINK_RAM_X_START_END_DEF, 2);
    eink_write_cmd(EINK_RAM_Y_START_END, EINK_RAM_Y_START_END_DEF, 2);
    eink_write_cmd(EINK_RAM_X_COUNTER, EINK_RAM_X_COUNTER_DEF, 1);
    eink_write_cmd(EINK_RAM_Y_COUNTER, EINK_RAM_Y_COUNTER_DEF, 1);
    eink_write_cmd(EINK_BOOSTER_SELSECTION, EINK_BOOSTER_SELSECTION_DEF, 1);
//   eink_write_cmd(EINK_DISPLAY_UPDATE_CTL1, EINK_DISPLAY_UPDATE_CTL1_DEF, 1);
//  eink_write_cmd(EINK_VCOM_WREG, EINK_VCOM_WREG_DEF, 1);
//   eink_write_cmd(EINK_BORDER_WF, EINK_BORDER_WF_DEF, 1);
//  eink_write_cmd(EINK_DISPLAY_UPDATE_CTL2, EINK_DISPLAY_UPDATE_CTL2_2, 1);
    EINK_C_CS_Clear();
    EINK_C_DC_Clear();
    hal_eink_write( &cmd, 1 );
    EINK_C_DC_Set();
    for( cnt = 0; cnt < _EINK_BMP_IMG_SIZE; cnt +=2 )
    {
        tmp = 0;
        pixel = 0;
        pixel |= img[ cnt + 1 ];
        pixel <<= 8;
        pixel |= img[ cnt ];

        tmp += ( pixel & 0xF800 ) >> 11;
        tmp += ( pixel & 0x07E0 ) >> 5;
        tmp += ( pixel & 0x001F );

        if( tmp < 32 )
        {
            tmp_pix |= 0x00;

        }
        else if( tmp < 64 )
        {
            tmp_pix |= 0x01;

        }
        else if( tmp < 96 )
        {
            tmp_pix |= 0x02;
        }
        else
        {
            tmp_pix |= 0x03;
        }

        if(((cnt % 8) == 0) && (cnt != 0))
        {
            hal_eink_write( &tmp_pix, 1 );
            _frame[ fr_cnt++ ] = tmp_pix;
            tmp_pix = 0;
        }
        else
        {
            tmp_pix <<= 2;
        }
    }
    EINK_C_CS_Set();
    eink_write_cmd( EINK_MASTER_ON, NULL, 0);
    eink_write_cmd( EINK_DISPLAY_UPDATE_CTL2, EINK_DISPLAY_UPDATE_CTL2_3, 1 );
    eink_write_cmd( EINK_MASTER_ON, NULL, 0);
}

void eink_text( char *text, uint8_t x, uint8_t y )
{
    uint16_t     cnt;
    uint8_t      cmd;
    char *ptr   = text;
    uint8_t *fr = _frame;

    if((x >= 72) || (y >= 172))
        return;

    x_cord = x;
    y_cord = y;

    while( *ptr )
        _char_wr( *ptr++ );

    cmd = EINK_WRITE_RAM;
    eink_write_cmd( EINK_RAM_X_START_END, EINK_RAM_X_START_END_DEF, 2 );
    eink_write_cmd( EINK_RAM_Y_START_END, EINK_RAM_Y_START_END_DEF, 2 );
    eink_write_cmd( EINK_RAM_X_COUNTER, EINK_RAM_X_COUNTER_DEF, 1 );
    eink_write_cmd( EINK_RAM_Y_COUNTER, EINK_RAM_Y_COUNTER_DEF, 1 );
    eink_write_cmd( EINK_BOOSTER_SELSECTION, EINK_BOOSTER_SELSECTION_DEF, 1 );
  //  eink_write_cmd( EINK_DISPLAY_UPDATE_CTL1, EINK_DISPLAY_UPDATE_CTL1_DEF, 1 );
    eink_write_cmd( EINK_VCOM_WREG, EINK_VCOM_WREG_DEF, 1 );
    eink_write_cmd( EINK_BORDER_WF, EINK_BORDER_WF_DEF, 1 );
    eink_write_cmd( EINK_DISPLAY_UPDATE_CTL2, EINK_DISPLAY_UPDATE_CTL2_2, 1 );
    EINK_C_CS_Clear();
    EINK_C_DC_Clear();
    hal_eink_write( &cmd, 1 );
    EINK_C_DC_Set();
    for( cnt = 0; cnt < _EINK_RAW_IMG_SIZE; cnt ++ )
    {
        hal_eink_write( fr++, 1 );
    }
    EINK_C_CS_Set();
    eink_write_cmd( EINK_MASTER_ON, NULL, 0);
    eink_write_cmd( EINK_DISPLAY_UPDATE_CTL2, EINK_DISPLAY_UPDATE_CTL2_3, 1 );
    eink_write_cmd( EINK_MASTER_ON, NULL, 0);
}



/*************** END OF FUNCTIONS ***************************************************************************/