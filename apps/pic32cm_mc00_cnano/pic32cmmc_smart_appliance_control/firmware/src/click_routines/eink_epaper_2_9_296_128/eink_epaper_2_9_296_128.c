/*******************************************************************************
    eink_epaper_2_9_296_128 Source File

  Company:
    Microchip Technology Inc.

  File Name:
    eink_epaper_2_9_296_128.c

  Summary:
    E-Paper display implementation file

  Description:
    This file has the function definitions like text and image function which
    give functionality to eink_epaper_2_9_296_128 display.This file contains has the
    initialization of eink_epaper_2_9_296_128 display along with reset functionality.

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

/*!
 * \file
 *
 */
#include <math.h>
#include <string.h>
#include "definitions.h"                // SYS function prototypes
#include "../click_interface.h"
#include "eink_epaper_2_9_296_128.h"
// ------------------------------ PRIVATE MACROS ------------------------------

#define _RETVAL  uint8_t

#define _OK                                          0x00
#define EINK_EPAPER_2_9_296_128_INIT_ERROR                            0xFF

#define DISPLAY_WIDTH                                 128
#define DISPLAY_HEIGHT                                296
#define _EINK_EPAPER_2_9_296_128_BMP_IMG_SIZE                         4736


/**
 * Driver Output Control ,Setting for 296 gates is
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  |Set 1[8:0] = 127h          |         |
 *  |Set 2[7:0] = 00h           |         |
 */
#define EINK_EPAPER_2_9_296_128_DRIVER_OUT_CTL                       0x01

/**
 * Softstart Control
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1[7:0] = 8Eh              |         |
 *  | 2[7:0] = 8Ch              |         |
 *  | 3[7:0] = 86h              |         |
 *  | 4[7:0] = 3Fh              |         |
 */
#define EINK_EPAPER_2_9_296_128_BOOSTER_SELSECTION                   0x0C

#define EINK_EPAPER_2_9_296_128_CMD_GATE_SCAN_START_POSITION         0x0F
/**
 * Deep Sleep mode Control
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  |1[1:0]                     |Description              |
 *  |  00                       |Normal Mode [POR]        |
 *  |  01                       |Enter Deep Sleep Mode1   |
 *  |  11                       |Enter Deep Sleep Mode2   |
 */
#define EINK_EPAPER_2_9_296_128_DEEP_SLEEP                           0x10

/**
 * Define data entry sequence
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  |   1[2:0] = 3h [POR],      |         |
 *  |   1[1:0] = ID[1:0]        |         |
 *
 *  Address automatic increment / decrement setting 1[2] = AM
 *  Set the direction in which the address counter is updated automatically after
 *  data is written to the RAM.
 *  When AM = 0, the address counter is updated in the X direction. [POR]
 *  When AM = 1, the address counter is updated in the Y direction
 */
#define EINK_EPAPER_2_9_296_128_DATA_ENTRY                           0x11

/**
 * Software Reset
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  It resets the commands and parameters to their S/W Reset default values except
 *   R10h-Deep Sleep Mode
 *   During operation, BUSY pad will output high.
 *   Note: RAM are unaffected by this command.
 */
#define EINK_EPAPER_2_9_296_128_SWRESET                              0x12

/**
 * Temperature Sensor  Control
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1 [7:0] =  48h [POR]      |  external temperature sensor |
 *  | 1 [7:0] =  80h            |   Internal temperature sensor |
 */
#define EINK_EPAPER_2_9_296_128_TEMPERATURE_WREG                     0x1A

/**
 Activate Display Update Sequence

  The Display Update Sequence Option is located at R22h
   BUSY pad will output high during operation.
   User should not interrupt this operation to avoid corruption of panel images.
*/
#define EINK_EPAPER_2_9_296_128_MASTER_ON                            0x20

/**
 * Display Update Control 1
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1 [7:0] = 00h [POR]       | RAM content option for Display Update  |
 *
 */
#define EINK_EPAPER_2_9_296_128_DISPLAY_UPDATE_CTL1                  0x21

/**
 * Display Update Control 2
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1[7:0]=FFH (POR)           |  Enable the stage for Master Activation |
 *
 */
#define EINK_EPAPER_2_9_296_128_DISPLAY_UPDATE_CTL2                  0x22

/**
 * After this command, data entries will be written into the RAM until another command is written.
 * Address pointers will advance accordingly
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | Content of Write RAM(BW)=1| For White Pixel |
 *  | Content of Write RAM(BW)=1| For Black Pixel |
 */
#define EINK_EPAPER_2_9_296_128_WRITE_RAM                            0x24

/**
 * Write VCOM register
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  |   1[7:0]=00h[POR]          | Write VCOM register from MCU interface |
 *
 */
#define EINK_EPAPER_2_9_296_128_VCOM_WREG                            0x2C

/**
 * Write LUT register
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 70 bytes                  | Write LUT register from MCU interface  |
 */
#define EINK_EPAPER_2_9_296_128_WRITE_LUT                            0x32

/**
 * Set Dummy Line Period
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1[7:0] = 0FH              |  Set Dummy Line Period       |
 */
#define EINK_EPAPER_2_9_296_128_DUMMY_LINE_PER                       0x3A

/**
 * Set Gate line width
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  |     Set 1[3:0] = 0CH      | Set Gate line width |
 */
#define EINK_EPAPER_2_9_296_128_G_LINE_WIDTH                         0x3B

/**
 * Select border waveform for VBD
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1 [7:6]                   |  Select VBD  |
 *
 */
#define EINK_EPAPER_2_9_296_128_BORDER_WF                            0x3C

/**
 * Specify the start/end positions of the window address in the X direction by an
 * address unit
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1[5:0] = 00H              |          |
 *  | 2[5:0] = 0FH              |          |
 */
#define EINK_EPAPER_2_9_296_128_RAM_X_START_END                      0x44

/**
 * Specify the start/end positions of the window address in the Y direction by an
 * address unit
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1[8:0] = 127H             |         |
 *  | 2[8:0] = 000H             |         |
 *
 */
#define EINK_EPAPER_2_9_296_128_RAM_Y_START_END                      0x45

/**
 * Set RAM X - address counter
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | 1 [7:4]                   | Make initial settings for the RAM X address in the address counter (AC) |
 */
#define EINK_EPAPER_2_9_296_128_RAM_X_COUNTER                        0x4E

/**
 * Set RAM Y - address counter
 *
 *  | Additional Data Bytes     | Meaning |
 *  |:-------------------------:|:-------:|
 *  | A[8:0] = 127H             | Make initial settings for the RAM Y address in the address counter (AC)  |
 */
#define EINK_EPAPER_2_9_296_128_RAM_Y_COUNTER                        0x4F

#define EINK_EPAPER_2_9_296_128_CMD_TERMINATE_FRAME_READ_WRITE       0xFF

#define X_START                                     0x0
#define X_START_TEXT                                0x3
#define X_END                                       (DISPLAY_WIDTH - 1)

#define Y_START                                     0x0
#define Y_START_TEXT                                160
#define Y_END                                       (DISPLAY_HEIGHT - 1)

#define X_MEM_START                                 0x0
#define Y_MEM_START                                 0x0

#define X_MEM_START_TEXT                            0x0
#define Y_MEM_START_TEXT                            160

// ----------------------- PRIVATE FUNCTION DECLARATIONS ----------------------
static void _frame_px( uint8_t x, uint8_t y, uint8_t font_col );
static void _char_wr( uint16_t ch_idx );

// ------------------------------------------------------------------ VARIABLES
static uint8_t EINK_EPAPER_2_9_296_128_DRIVER_OUT_CTL_DEF[ 3 ]       = { ( ( DISPLAY_HEIGHT - 1 ) & 0xFF )  , ( ( ( DISPLAY_HEIGHT - 1 ) >> 8 ) & 0xFF ) , 0x00 };
static uint8_t EINK_EPAPER_2_9_296_128_DUMMY_LINE_PER_DEF[ 1 ]       = { 0x1A };
static uint8_t EINK_EPAPER_2_9_296_128_G_LINE_WIDTH_DEF[ 1 ]         = { 0x08 };
static uint8_t EINK_EPAPER_2_9_296_128_DATA_ENTRY_DEF[ 1 ]           = { 0x03 };
static uint8_t EINK_EPAPER_2_9_296_128_RAM_X_START_END_DEF[ 2 ]      = { ((X_START >> 3) & 0xFF), (((X_END) >> 3) & 0xFF) };
static uint8_t EINK_EPAPER_2_9_296_128_RAM_Y_START_END_DEF[ 4 ]      = { (Y_START & 0xFF), ((Y_START >> 8) & 0xFF), (Y_END & 0xFF), (((Y_END) >> 8) & 0xFF) };
static uint8_t EINK_EPAPER_2_9_296_128_RAM_X_START_END_DEF_TEXT[ 2 ] = { ((X_START_TEXT >> 3) & 0xFF), (((X_END) >> 3) & 0xFF)};
static uint8_t EINK_EPAPER_2_9_296_128_RAM_Y_START_END_DEF_TEXT[ 4 ] = { (Y_START_TEXT & 0xFF), ((Y_START_TEXT >> 8) & 0xFF), (Y_END & 0xFF), (((Y_END) >> 8) & 0xFF) };
static uint8_t EINK_EPAPER_2_9_296_128_VCOM_WREG_DEF[ 1 ]            = { 0x6E };
static uint8_t EINK_EPAPER_2_9_296_128_BORDER_WF_DEF[ 1 ]            = { 0x33 };
static uint8_t EINK_EPAPER_2_9_296_128_RAM_X_COUNTER_DEF[ 1 ]        = { (( X_MEM_START >> 3 ) & 0xFF ) };
static uint8_t EINK_EPAPER_2_9_296_128_RAM_Y_COUNTER_DEF[ 2 ]        = { ( Y_MEM_START & 0xFF ) ,( ( Y_MEM_START >> 8 ) & 0xFF )  };
static uint8_t EINK_EPAPER_2_9_296_128_RAM_X_COUNTER_DEF_TEXT[ 1 ]   = { (( X_MEM_START_TEXT >> 3 ) & 0xFF ) };
static uint8_t EINK_EPAPER_2_9_296_128_RAM_Y_COUNTER_DEF_TEXT[ 2 ]   = { ( Y_MEM_START_TEXT & 0xFF ) ,( ( Y_MEM_START_TEXT >> 8 ) & 0xFF ) };
static uint8_t EINK_EPAPER_2_9_296_128_DISPLAY_UPDATE_CTL2_DEF[ 1 ]  = { 0xC7 };
static uint8_t _frame[ _EINK_EPAPER_2_9_296_128_BMP_IMG_SIZE ];

/* Text Variables */
static const uint8_t*   _font;
static uint16_t         _font_color;
static uint8_t          _font_orientation;
static uint16_t         _font_first_char;
static uint16_t         _font_last_char;
static uint16_t         _font_height;
static uint16_t         x_cord;
static uint16_t         y_cord;

/* Note: The change in LUT values affects the performance of the display */
const uint8_t EINK_EPAPER_2_9_296_128_LUT_TABLE_1[70]=
{
    0xA0,0x90,0x50,0x00,0x00,0x00,0x00,
    0x50,0x90,0xA0,0x00,0x00,0x00,0x00,
    0xA0,0x90,0x50,0x00,0x00,0x00,0x00,
    0x50,0x90,0xA0,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x0F,0x0F,0x0F,0x0F,0x02,0x10,0x10,
    0x0A,0x0A,0x03,0x08,0x08,0x09,0x43,
    0x07,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

// --------------------------- ADDITIONAL FUNCTIONS --------------------------
/**
 * Writes command or data using SPI Protocol
 */
static void hal_eink_epaper_2_9_296_128_write(uint8_t* buffer, uint16_t count)
{
    CLICK_EINK_EPAPER_2_9_296_128_SPI_Write( buffer, count );
}

/**
 * Sets the position and color by using x , y and font_col parameters.
 */
static void _frame_px( uint8_t x, uint8_t y, uint8_t font_col )
{
    uint8_t off;
    uint16_t pos;

    pos = ( y * ( DISPLAY_WIDTH / 8 ) ) + ( x / 4 );
    off = ( 3 - ( x % 4 ) ) * 2;

    _frame[ pos ] &= ~( 0x03 << off );
    _frame[ pos ] |= ( ( font_col & 0x03 ) << off );
}

/**
 * Writes the characters individually into the frame based on the parameters
 * like orientation, height and width of each character from font function.
 */
static void _char_wr( uint16_t ch_idx )
{
    uint8_t   ch_width = 0;
    uint8_t   x_cnt;
    uint8_t   y_cnt;
    uint16_t  x = 0;
    uint16_t  y = 0;
    uint16_t  tmp;
    uint8_t   temp = 0;
    uint8_t   mask = 0;
    uint32_t  offset;
    const uint8_t *ch_table;
    const uint8_t *ch_bitmap;

    if ( ch_idx < _font_first_char )
    {
        return;
    }
    if ( ch_idx > _font_last_char )
    {
        return;
    }

    offset = 0;
    tmp = (ch_idx - _font_first_char) << 2;
    ch_table = _font + 8 + tmp;
    ch_width = *ch_table;

    offset = ( uint32_t ) ch_table[ 1 ] + ( ( uint32_t ) ch_table [ 2 ] << 8 ) + ( ( uint32_t ) ch_table[ 3 ] << 16 );

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

// ------------------------- PUBLIC FUNCTION DEFINITIONS ----------------------
/**
 * Resets the display device
 */
static void _eink_epaper_2_9_296_128_reset( void )
{
    CLICK_EINK_EPAPER_2_9_296_128_DelayMs( 200 );
    CLICK_EINK_EPAPER_2_9_296_128_RST_Clear();
    CLICK_EINK_EPAPER_2_9_296_128_DelayMs( 200 );
    CLICK_EINK_EPAPER_2_9_296_128_RST_Set();
    CLICK_EINK_EPAPER_2_9_296_128_DelayMs( 200 );
}

/**
 * Reads the function args and its length, then sends either
 * data or command based on the DC and CS pins.
 * If DC is clear it sends a command
 * If DC pin is set it sends data
 */
void _eink_epaper_2_9_296_128_write_cmd( uint8_t command, uint8_t *args, uint16_t args_len )
{
    uint8_t *ptr = args;

    while( CLICK_EINK_EPAPER_2_9_296_128_BSY_Get() == 1 );
    CLICK_EINK_EPAPER_2_9_296_128_CS_Clear();
    CLICK_EINK_EPAPER_2_9_296_128_DC_Clear();
    hal_eink_epaper_2_9_296_128_write( &command, 1 );
    CLICK_EINK_EPAPER_2_9_296_128_DC_Set();
    if( args_len )
        hal_eink_epaper_2_9_296_128_write( ptr, args_len );
    CLICK_EINK_EPAPER_2_9_296_128_CS_Set();
    while( CLICK_EINK_EPAPER_2_9_296_128_BSY_Get() == 1 );
}

/**
 * Resets the frame with specified color based on the display size
 */
void eink_epaper_2_9_296_128_fill_screen( uint8_t color )
{
    memset( _frame, color, _EINK_EPAPER_2_9_296_128_BMP_IMG_SIZE );
}

/**
 * Displays image from the array present in epaper_image.c source file
 */
void eink_epaper_2_9_296_128_image_bmp (  const uint8_t*  img )
{
    uint16_t cnt;

    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_RAM_X_START_END, EINK_EPAPER_2_9_296_128_RAM_X_START_END_DEF, 2 );
    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_RAM_Y_START_END, EINK_EPAPER_2_9_296_128_RAM_Y_START_END_DEF, 4 );
    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_RAM_X_COUNTER, EINK_EPAPER_2_9_296_128_RAM_X_COUNTER_DEF, 1);
    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_RAM_Y_COUNTER, EINK_EPAPER_2_9_296_128_RAM_Y_COUNTER_DEF, 2 );
    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_WRITE_RAM, NULL, 0 );

    CLICK_EINK_EPAPER_2_9_296_128_CS_Clear();
    CLICK_EINK_EPAPER_2_9_296_128_DC_Set();
    for ( cnt = 0; cnt < _EINK_EPAPER_2_9_296_128_BMP_IMG_SIZE; cnt++)
    {
        hal_eink_epaper_2_9_296_128_write((uint8_t*) &img[ cnt ], 1);
    }
    CLICK_EINK_EPAPER_2_9_296_128_CS_Set();

    // Display delay
    CLICK_EINK_EPAPER_2_9_296_128_DelayMs( 2 );
    CLICK_EINK_EPAPER_2_9_296_128_DelayMs( 100 );
    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_DISPLAY_UPDATE_CTL2, EINK_EPAPER_2_9_296_128_DISPLAY_UPDATE_CTL2_DEF, 1);
    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_MASTER_ON, NULL, 0);
    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_CMD_TERMINATE_FRAME_READ_WRITE, NULL, 0 );
    CLICK_EINK_EPAPER_2_9_296_128_DelayMs( 1000 );
}

/**
 * Displays text by using font parameters like buffer and co-ordinates
 */
void eink_epaper_2_9_296_128_text( char *text, uint8_t x, uint8_t y )
{
    uint16_t cnt;
    uint8_t *fr = _frame;
    char *ptr = text;

    if ( ( x >= DISPLAY_WIDTH ) || ( y >= DISPLAY_HEIGHT ) )
    {
        return;
    }
     x_cord = x;
     y_cord = y;
    while( *ptr )
        _char_wr( *ptr++ );

    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_RAM_X_START_END, EINK_EPAPER_2_9_296_128_RAM_X_START_END_DEF_TEXT, 2 );
    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_RAM_Y_START_END, EINK_EPAPER_2_9_296_128_RAM_Y_START_END_DEF_TEXT, 4 );
    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_RAM_X_COUNTER, EINK_EPAPER_2_9_296_128_RAM_X_COUNTER_DEF_TEXT, 1 );
    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_RAM_Y_COUNTER, EINK_EPAPER_2_9_296_128_RAM_Y_COUNTER_DEF_TEXT, 2 );
    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_WRITE_RAM , NULL, 0);
    CLICK_EINK_EPAPER_2_9_296_128_CS_Clear();
    CLICK_EINK_EPAPER_2_9_296_128_DC_Set();
    for ( cnt = 0; cnt < _EINK_EPAPER_2_9_296_128_BMP_IMG_SIZE; cnt++ )
    {
        hal_eink_epaper_2_9_296_128_write( fr++, 1);
    }
    CLICK_EINK_EPAPER_2_9_296_128_CS_Set();
    // Display delay
    CLICK_EINK_EPAPER_2_9_296_128_DelayMs(2);
    CLICK_EINK_EPAPER_2_9_296_128_DelayMs( 100 );
    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_DISPLAY_UPDATE_CTL2 , EINK_EPAPER_2_9_296_128_DISPLAY_UPDATE_CTL2_DEF,1 );
    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_MASTER_ON   ,NULL ,0 );
    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_CMD_TERMINATE_FRAME_READ_WRITE, NULL, 0 );
    CLICK_EINK_EPAPER_2_9_296_128_DelayMs( 1000 );
}

 /**
 * Sets the font style and size from array (eink_epaper_2_9_296_128_text.c),
 * the position of the first character by taking x and y coordinates and sets
 * the other parameters like orientation, color , width and height.
 */
void eink_epaper_2_9_296_128_set_font( const uint8_t *font, uint16_t color, uint8_t orientation )
{
    _font               = font;
    _font_first_char    = font[2] + (font[3] << 8);
    _font_last_char     = font[4] + (font[5] << 8);
    _font_height        = font[6];
    _font_color         = color;
    _font_orientation   = orientation ;
}

// -------------------------- APPLICATION FUNCTIONS ---------------------------
/**
 * Initializes E-Paper display module.
 * It resets and configures the E-Paper display module
 */
void eink_epaper_2_9_296_128_init ( void )
{
    CLICK_EINK_EPAPER_2_9_296_128_TimerStart( );
    CLICK_EINK_EPAPER_2_9_296_128_DC_Set( );
    CLICK_EINK_EPAPER_2_9_296_128_CS_Set( );
    CLICK_EINK_EPAPER_2_9_296_128_RST_Set( );
    _eink_epaper_2_9_296_128_reset( );
    CLICK_EINK_EPAPER_2_9_296_128_DelayMs( 200 );
    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_DRIVER_OUT_CTL, EINK_EPAPER_2_9_296_128_DRIVER_OUT_CTL_DEF, 3 );
    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_DUMMY_LINE_PER, EINK_EPAPER_2_9_296_128_DUMMY_LINE_PER_DEF, 1 );
    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_G_LINE_WIDTH, EINK_EPAPER_2_9_296_128_G_LINE_WIDTH_DEF, 1 );
    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_DATA_ENTRY, EINK_EPAPER_2_9_296_128_DATA_ENTRY_DEF, 1 );
    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_RAM_X_START_END, EINK_EPAPER_2_9_296_128_RAM_X_START_END_DEF, 2 );
    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_RAM_Y_START_END, EINK_EPAPER_2_9_296_128_RAM_Y_START_END_DEF, 4 );
    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_VCOM_WREG, EINK_EPAPER_2_9_296_128_VCOM_WREG_DEF, 1 );
    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_BORDER_WF, EINK_EPAPER_2_9_296_128_BORDER_WF_DEF, 1 );
    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_DATA_ENTRY, EINK_EPAPER_2_9_296_128_DATA_ENTRY_DEF, 1 );

    // Display delay
    CLICK_EINK_EPAPER_2_9_296_128_DelayMs( 2 );
    _eink_epaper_2_9_296_128_write_cmd( EINK_EPAPER_2_9_296_128_WRITE_LUT, (uint8_t*)&EINK_EPAPER_2_9_296_128_LUT_TABLE_1, sizeof(EINK_EPAPER_2_9_296_128_LUT_TABLE_1) );
    CLICK_EINK_EPAPER_2_9_296_128_DelayMs( 1000 );
}
