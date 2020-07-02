/**
 * @file                                                            eink.h
 * @brief                           eINK
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
*****************************************************************************/
/****************************************************************************
* Note: In version 1.0, This file has been modified by MK to meet the custom 
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
#ifndef EINK_HW_H_
#define EINK_HW_H_

#include <stdint.h>
#include "eink_hal.h"
//#include "eink_font.h"

/**
 *
 * @name                 Display Colors
 ******************************************************************************/
///@{
#define EINK_COLOR_WHITE                    0xFF
#define EINK_COLOR_LIGHT_GREY               0xAA
#define EINK_COLOR_DARK_GREY                0x55
#define EINK_COLOR_BLACK                    0x00
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



/**
 * @name                 Font Direction
 ******************************************************************************/
///@{
#define FO_HORIZONTAL           (0)
#define FO_VERTICAL             (1)
#define FO_VERTICAL_COLUMN      (2)
///@}

/**
 * @name                 Functions
 ******************************************************************************/
///@{
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
 * @brief eINK Reset
 *
 * Performs hardware reset of device using RST pin.
 */
void eink_reset( void );

/**
 * @brief eINK Command
 *
 * @param[in] command       Device Command
 * @param[in] args          Pointer to command agrument
 * @param[in] args_len      Argument size in bytes
 */
void eink_write_cmd( uint8_t command, uint8_t *args, uint16_t args_len );

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
