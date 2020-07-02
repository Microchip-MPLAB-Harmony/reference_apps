/*******************************************************************************
* Title                 :   HeartRate 3 click
* Filename              :   heartrate_3_hal.c
* Author                :   CAL
* Origin Date           :   04/06/2016
* Notes                 :   None
*******************************************************************************/
/*************** MODULE REVISION LOG ******************************************
*
*    Date     Software Version    Initials      Description
*  04/06/2016    XXXXXXXXXXX        CAL      Interface Created.
*  28/01/2020    1.0.1              MK       Modified
*******************************************************************************/
/**
 * @file heartrate_3_hal.c
 * @brief <h2> HAL layer </h2>
 */

/****************************************************************************
* Note: In version 1.0.1, This file has been modified by MK to meet the custom 
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
/******************************************************************************
* Includes
*******************************************************************************/
#include "../include/heartrate_3_hal.h"
#include "app.h"

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/
#define READ_BIT                1
#define WRITE_BIT               0
#define NACK_BIT                1
#define ACK_BIT                 0
#define PIC_NACK_BIT            0
#define PIC_ACK_BIT             1
/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/
static uint8_t _i2c_hw_address;

static void ( *write_i2c_p )( unsigned char slave_address,
                                    unsigned char *buffer,
                                    unsigned long count,
                                    unsigned long end_mode );
static void ( *read_i2c_p )( unsigned char slave_address,
                            unsigned char *buffer,
                            unsigned long count,
                            unsigned long end_mode );
static void ( *write_read_i2c_p )( unsigned char slave_address,
                                unsigned char *txbuffer,
                                unsigned long txcount,
                                unsigned char *rxbuffer,
                                unsigned long rxcount,
                                unsigned long end_mode );
/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/
void hr3_hal_init( uint8_t address_id )
{
    write_i2c_p = APP_HR3_I2C_Write_Ptr;
    read_i2c_p  = APP_HR3_I2C_Read_Ptr;
    write_read_i2c_p = APP_HR3_I2C_Write_Read_Ptr;
    _i2c_hw_address = address_id;
}

void hr3_hal_write( uint8_t *command, uint8_t *buffer, uint16_t count )
{
    uint8_t temp[ BUFF_SIZE ];

    uint8_t cmd_size    = 1;
    uint16_t i          = 0;
    uint8_t *temp_ptr   = temp;
    uint8_t *buff_ptr   = buffer;
    uint8_t *cmd_ptr    = command;

    /* Fill the temp buffer with data*/
    while( cmd_size-- )
        temp[ i++ ] = *( cmd_ptr++ );

    while ( count-- )
        temp[ i++ ] = *( buff_ptr++ );

    write_i2c_p( _i2c_hw_address, temp_ptr, i, 0 );
}

void hr3_hal_read( uint8_t *command, uint8_t *buffer, uint16_t count )
{
    uint8_t cmd_size    =  1;
    write_read_i2c_p( _i2c_hw_address, command, cmd_size, buffer, count, 0 );
}

void hr3_hal_delay( uint32_t ms )
{
    //Handle Timer delay service
}

/*************** END OF FUNCTIONS *********************************************/