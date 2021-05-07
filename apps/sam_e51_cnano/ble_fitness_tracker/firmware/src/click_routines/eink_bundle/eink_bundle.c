/*
 * eink_bundle.c
 *
 * Revision Log :
 * - 0.0.1 (Nov/2016) Module created                        MilosV
 * - 0.0.2 (Jan/2017) Documentation added                   MilosV
 * - 0.0.3 (Jan/2020) Modified                              MK
 * - 0.0.4 (Apr/2021) Modified                              ST
 * To Do List :
 * @todo
 *
 ******************************************************************************/
/****************************************************************************
* Note: In version 0.0.4, This file has been modified by ST to meet the custom
* application requirements. write to
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
#include <math.h>
#include <string.h>
#include "definitions.h"                // SYS function prototypes
#include "../click_interface.h"
#include "eink_bundle.h"

#define _EINK_RAW_IMG_SIZE      3096
#define _EINK_BMP_IMG_SIZE      24768

///@}
/**
 * @name                 TME21 Commands
 *
 * All commands are used with @c eink_write_cmd() function. Additional data
 * bytes sent alongside with command depends on the command type.
 ******************************************************************************/
///@{
/**
 * Driver Output Control
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1 [7:0]                   | MUX setting |
 *  | 2 [2:0]                   | Gate scanning sequence and direction |
 */
#define EINK_DRIVER_OUT_CTL                 0x01
/**
 * Gate Driving Voltage Control
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1 [7:4]                   | VGH 12 - 22 V in 0.5V steps |
 *  | 1 [3:0]                   | VGL (-15)-(-20) V in 0.5V steps |
 */
#define EINK_GATE_VOLTAGE_CTL                0x03
/**
 * Source Driving Voltage Control
 *
 *  | Additional Data   | Meaning |
 *  |:-----------------:|:-------:|
 *  | 1 [3:0]           | VCH/VSL 10 - 17 V in 0.5V steps |
 */
#define EINK_SOURCE_VOLTAGE_CTL             0x04
/**
 * Display Control
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1 [5:4]                   | Gate voltage level |
 *  | 1 [0]                     | Grey scale mode |
 */
#define EINK_DISPLAY_CTL                    0x07
/**
 * Gate and Source non Overlap Period Control
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1 [3:0]                   | Delay duration (1/Fosc)
 */
#define EING_NONOVERLAP_PERIOD              0x0B
/**
 * Gate Scan Start Position
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1 [7:0]                   | Start position in range 0 - 179 |
 */
#define EINK_G_SCAN_START                   0x0F
/**
 * Deep Sleep Mode
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1 [0]                     | 1 - Enter deep sleep |
 */
#define EINK_DEEP_SLEEP                     0x10
/**
 * Data Entry Setting
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1 [2]                     | Counter update direction |
 *  | 1 [1]                     | Increment / decrement for Y axis |
 *  | 1 [0]                     | Increment / decrement for X axis |
 */
#define EINK_DATA_ENTRY                     0x11
/**
 * Soft Reset
 */
#define EINK_SWRESET                        0x12
/**
 * Temperature Sensor Write to Register
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1 [7:0]                   | MSB |
 *  | 2 [7:4]                   | LSB |
 */
#define EINK_TEMPERATURE_WREG               0x1A
/**
 * Temperature Sensor Write Command
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1 [7:6]                   | Number of bytes |
 *  | 1 [5:0]                   | Ponter settings |
 *  | 2 [7:0]                   | Parameter 1 |
 *  | 3 [7:0]                   | Parameter 2 |
 */
#define EINK_TEMPERATURE_CMD                0x1C
/**
 * Temperature Sensor Load Sensor Reading
 */
#define EINK_TEMPERATURE_LOAD               0x1D
/**
 * Activate Display Update Sequence
 */
#define EINK_MASTER_ON                      0x20
/**
 * Option for Display Update
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1 [7]                     | Bypass option |
 *  | 1 [5:4]                   | Bypass value |
 *  | 1 [3:0]                   | Source control |
 */
#define EINK_DISPLAY_UPDATE_CTL1            0x21
/**
 * Display Update Sequence Option
 *
 * @note
 * Check datasheet for more informations.
 */
#define EINK_DISPLAY_UPDATE_CTL2            0x22
/**
 * Write RAM
 *
 * After this command data enteries will be written to RAM.
 */
#define EINK_WRITE_RAM                      0x24
/**
 * Enter VCOM Sensing conditions
 */
#define EINK_VCOM_SENSE                     0x28
/**
 * VCOM Sense Duration
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1 [7:0]                   | Duration in seconds + 1 |
 */
#define EINK_VCOM_SENSE_DUR                 0x29
/**
 * Program VCOM register into OTP
 */
#define EINK_VCOM_PROG_OTP                  0x2A
/**
 * Write VCOM register from MCU
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1 [7:0]                   | Data |
 */
#define EINK_VCOM_WREG                      0x2C
/**
 * Program OTP of Waveform settings
 */
#define EINK_OTP_WS                         0x30
/**
 * Write LUT
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 90 bytes                  | LUT content |
 */
#define EINK_WRITE_LUT                      0x32
/**
 * Program OTP Section
 */
#define EINK_OTP_PROG                       0x36
/**
 * OTP Selection
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1 [7]                     | Spare VCOM OTP |
 *  | 1 [6]                     | VCOM Status |
 *  | 1 [5]                     | Spare WS OTP |
 *  | 1 [4]                     | WS Status |
 *  | 1 [3:0]                   | Reserved OTP bits |
 */
#define EINK_OTP_SELECTION                  0x37
/**
 * Set Dummy Line Period
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1 [6:0]                   | Number of dummy line period in term of TGate |
 */
#define EINK_DUMMY_LINE_PER                 0x3A
/**
 * Set Gate Line Width
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1 [3:0]                   | Line width in us |
 */
#define EINK_G_LINE_WIDTH                   0x3B
/**
 * Select Border Waveform for VBD
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1 [7]                     | Follow source at initial update display |
 *  | 1 [6]                     | GS transition/fix level |
 *  | 1 [5:4]                   | Fix level settings |
 *  | 1 [3:0]                   | Transition settings |
 */
#define EINK_BORDER_WF                      0x3C
/**
 * RAM X Start/End Position
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1 [4:0]                   | Start position |
 *  | 2 [4:0]                   | End position |
 */
#define EINK_RAM_X_START_END                0x44
/**
 * RAM Y Start/End Position
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1 [7:0]                   | Start position |
 *  | 2 [7:0]                   | End position |
 */
#define EINK_RAM_Y_START_END                0x45
/**
 * RAM X Address Counter
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1 [4:0]                   | Start address |
 */
#define EINK_RAM_X_COUNTER                  0x4E
/**
 * RAM Y Address Counter
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1 [4:0]                   | End address |
 */
#define EINK_RAM_Y_COUNTER                  0x4F
/**
 * Booster Feedback
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1 [7:0]                   | Default (1Fh) |
 */
#define EINK_BOOSTER_SELSECTION             0xF0
/**
 * No Operation Command
 */
#define EINK_NOP
///@}


/*                Variables
 ******************************************************************************/

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

/******************************************************************************
* Private Function Prototypes
*******************************************************************************/

static void _frame_px( uint8_t x, uint8_t y, uint8_t font_col );
static void _char_wr( uint16_t ch_idx );
static void hal_eink_write (uint8_t* buffer, uint16_t count);
//static void hal_eink_read(uint8_t* buffer, uint16_t count);
//static void hal_eink_transfer(uint8_t* input,uint8_t* output,uint16_t count);
static void _eink_reset( void );
static void _eink_write_cmd( uint8_t command, uint8_t *args, uint16_t args_len );

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

static void _eink_reset( void )
{
    CLICK_EINK_BUNDLE_DelayMs( 1 );
    CLICK_EINK_BUNDLE_RST_Clear();
    CLICK_EINK_BUNDLE_DelayMs( 2 );
    CLICK_EINK_BUNDLE_RST_Set();
    CLICK_EINK_BUNDLE_DelayMs( 1000 );
}

void _eink_write_cmd( uint8_t command, uint8_t *args, uint16_t args_len )
{
    uint8_t *ptr = args;

    while( CLICK_EINK_BUNDLE_BSY_Get() == 1 );
    CLICK_EINK_BUNDLE_CS_Clear();
    CLICK_EINK_BUNDLE_DC_Clear();
    hal_eink_write( &command, 1  );
    CLICK_EINK_BUNDLE_DC_Set();
    if( args_len )
        hal_eink_write( ptr, args_len );
    CLICK_EINK_BUNDLE_CS_Set();
    while( CLICK_EINK_BUNDLE_BSY_Get() == 1 );
}

static void hal_eink_write(uint8_t* buffer,uint16_t count)
{
    //DRV_SPI_WriteTransferAdd(appData.drvSPIHandle, buffer, count, &appData.transferHandle);
    CLICK_EINK_BUNDLE_SPI_Write(buffer, count);

}
#if 0
static void hal_eink_read (uint8_t* buffer, uint16_t count)
{
    //DRV_SPI_ReadTransferAdd(appData.drvSPIHandle, buffer, count, &appData.transferHandle);
    CLICK_EINK_BUNDLE_SPI_Read(buffer,count);
}

static void hal_eink_transfer(uint8_t* input,uint8_t* output, uint16_t count)
{
   // DRV_SPI_WriteReadTransferAdd(appData.drvSPIHandle,input,count,output,count,&appData.transferHandle);
    CLICK_EINK_BUNDLE_SPI_WriteRead(output, count, input, count);
}
#endif

/******************************************************************************
* Function Definitions
*******************************************************************************/

void eink_init( void )
{
    CLICK_EINK_BUNDLE_TimerStart();
    CLICK_EINK_BUNDLE_DC_Set();
    CLICK_EINK_BUNDLE_CS_Set();
    CLICK_EINK_BUNDLE_RST_Set();
    _eink_reset();
    CLICK_EINK_BUNDLE_DelayMs(1000);
    _eink_write_cmd(EINK_DEEP_SLEEP,           EINK_DATA_SLEEP_DEF, 1);
    _eink_write_cmd(EINK_DATA_ENTRY,           EINK_DATA_ENTRY_DEF, 1);
    _eink_write_cmd(EINK_RAM_X_START_END,      EINK_RAM_X_START_END_DEF, 2);
    _eink_write_cmd(EINK_RAM_Y_START_END,      EINK_RAM_Y_START_END_DEF, 2);
    _eink_write_cmd(EINK_RAM_X_COUNTER,        EINK_RAM_X_COUNTER_DEF, 1);
    _eink_write_cmd(EINK_RAM_Y_COUNTER,        EINK_RAM_Y_COUNTER_DEF, 1);
    _eink_write_cmd(EINK_VCOM_SENSE_DUR,       EINK_SENSE_DURATION_DEF, 1);
    _eink_write_cmd(EINK_VCOM_SENSE,           NULL, 0);
    _eink_write_cmd(EINK_DISPLAY_UPDATE_CTL2,  EINK_DISPLAY_UPDATE_CTL2_1, 1);
    _eink_write_cmd(EINK_MASTER_ON,            NULL, 0);
    _eink_write_cmd(EINK_TEMPERATURE_LOAD,     NULL, 0);
    _eink_write_cmd(EINK_BOOSTER_SELSECTION,   EINK_BOOSTER_SELSECTION_DEF, 1);
    _eink_write_cmd(EINK_DISPLAY_UPDATE_CTL1,  EINK_DISPLAY_UPDATE_CTL1_DEF, 1);
    _eink_write_cmd(EINK_VCOM_WREG,            EINK_VCOM_WREG_DEF, 1);
    _eink_write_cmd(EINK_BORDER_WF,            EINK_BORDER_WF_DEF, 1);
    _eink_write_cmd(EINK_DISPLAY_UPDATE_CTL2,  EINK_DISPLAY_UPDATE_CTL2_2, 1);
    _eink_write_cmd(EINK_WRITE_LUT,            LUT_TME21, sizeof(LUT_TME21));
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

    _eink_write_cmd( EINK_RAM_X_START_END, EINK_RAM_X_START_END_DEF, 2 );
    _eink_write_cmd( EINK_RAM_Y_START_END, EINK_RAM_Y_START_END_DEF, 2 );
    _eink_write_cmd( EINK_RAM_X_COUNTER, EINK_RAM_X_COUNTER_DEF, 1 );
    _eink_write_cmd( EINK_RAM_Y_COUNTER, EINK_RAM_Y_COUNTER_DEF, 1 );
    _eink_write_cmd( EINK_BOOSTER_SELSECTION, EINK_BOOSTER_SELSECTION_DEF, 1 );
    _eink_write_cmd( EINK_DISPLAY_UPDATE_CTL1, EINK_DISPLAY_UPDATE_CTL1_DEF, 1 );
    _eink_write_cmd( EINK_VCOM_WREG, EINK_VCOM_WREG_DEF, 1 );
    _eink_write_cmd( EINK_BORDER_WF, EINK_BORDER_WF_DEF, 1 );
    _eink_write_cmd( EINK_DISPLAY_UPDATE_CTL2, EINK_DISPLAY_UPDATE_CTL2_2, 1 );
    while( CLICK_EINK_BUNDLE_BSY_Get() == 1 );
    CLICK_EINK_BUNDLE_CS_Clear();
    CLICK_EINK_BUNDLE_DC_Clear();
    hal_eink_write( &command, 1 );
    CLICK_EINK_BUNDLE_DC_Clear();
    while( repeats-- )
        hal_eink_write( &color, 1 );
    CLICK_EINK_BUNDLE_CS_Set();
    _eink_write_cmd( EINK_MASTER_ON, NULL, 0);
    _eink_write_cmd( EINK_DISPLAY_UPDATE_CTL2, EINK_DISPLAY_UPDATE_CTL2_3, 1 );
    _eink_write_cmd( EINK_MASTER_ON, NULL, 0);
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
    _eink_write_cmd(EINK_RAM_X_START_END, EINK_RAM_X_START_END_DEF, 2);
    _eink_write_cmd(EINK_RAM_Y_START_END, EINK_RAM_Y_START_END_DEF, 2);
    _eink_write_cmd(EINK_RAM_X_COUNTER, EINK_RAM_X_COUNTER_DEF, 1);
    _eink_write_cmd(EINK_RAM_Y_COUNTER, EINK_RAM_Y_COUNTER_DEF, 1);
    _eink_write_cmd(EINK_BOOSTER_SELSECTION, EINK_BOOSTER_SELSECTION_DEF, 1);
    CLICK_EINK_BUNDLE_CS_Clear();
    CLICK_EINK_BUNDLE_DC_Clear();
    hal_eink_write( &cmd, 1 );
    CLICK_EINK_BUNDLE_DC_Set();
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
    CLICK_EINK_BUNDLE_CS_Set();
    _eink_write_cmd( EINK_MASTER_ON, NULL, 0);
    _eink_write_cmd( EINK_DISPLAY_UPDATE_CTL2, EINK_DISPLAY_UPDATE_CTL2_3, 1 );
    _eink_write_cmd( EINK_MASTER_ON, NULL, 0);
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
    _eink_write_cmd( EINK_RAM_X_START_END, EINK_RAM_X_START_END_DEF, 2 );
    _eink_write_cmd( EINK_RAM_Y_START_END, EINK_RAM_Y_START_END_DEF, 2 );
    _eink_write_cmd( EINK_RAM_X_COUNTER, EINK_RAM_X_COUNTER_DEF, 1 );
    _eink_write_cmd( EINK_RAM_Y_COUNTER, EINK_RAM_Y_COUNTER_DEF, 1 );
    _eink_write_cmd( EINK_BOOSTER_SELSECTION, EINK_BOOSTER_SELSECTION_DEF, 1 );
    _eink_write_cmd( EINK_VCOM_WREG, EINK_VCOM_WREG_DEF, 1 );
    _eink_write_cmd( EINK_BORDER_WF, EINK_BORDER_WF_DEF, 1 );
    _eink_write_cmd( EINK_DISPLAY_UPDATE_CTL2, EINK_DISPLAY_UPDATE_CTL2_2, 1 );
    CLICK_EINK_BUNDLE_CS_Clear();
    CLICK_EINK_BUNDLE_DC_Clear();
    hal_eink_write( &cmd, 1 );
    CLICK_EINK_BUNDLE_DC_Set();
    for( cnt = 0; cnt < _EINK_RAW_IMG_SIZE; cnt ++ )
    {
        hal_eink_write( fr++, 1 );
    }
    CLICK_EINK_BUNDLE_CS_Set();
    _eink_write_cmd( EINK_MASTER_ON, NULL, 0);
    _eink_write_cmd( EINK_DISPLAY_UPDATE_CTL2, EINK_DISPLAY_UPDATE_CTL2_3, 1 );
    _eink_write_cmd( EINK_MASTER_ON, NULL, 0);
}

/*************** END OF FUNCTIONS ***************************************************************************/