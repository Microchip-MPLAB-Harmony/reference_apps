/****************************************************************************
* Title                 :   HeartRate 3 click
* Filename              :   heartrate_3_hal.h
* Author                :   CAL
* Origin Date           :   04/04/2016
* Notes                 :   None
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date     Software Version    Initials      Description
*  04/04/2016    XXXXXXXXXXX        CAL      Interface Created.
*  28/01/2020    1.0.1              MK       Modified.
*****************************************************************************/
/**
 * @file heartrate_3_hal.h
 * @brief <h2> HAL layer </h2>
 *
 * @par
 * HAL layer for <a href="http://www.mikroe.com">MikroElektronika's</a>
 * Heart Rate 3 click board.
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
#ifndef HEARTRATE_3_HAL_H_
#define HEARTRATE_3_HAL_H_
/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define CMD_SIZE                1           // COMMAND OR REGISTER ADDRESS SIZE
#define BUFF_SIZE               256         // BUFFER SIZE
/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief <h3>HAL Initialization</h3>
 *
 * @par
 * Initialization of HAL layer used to initialize I2C bus and pins needed
 * for proper usage of click board.
 *
 * @param[in] address_id - hardware address
 */
void hr3_hal_init( uint8_t address_id );

/**
 * @brief <h3>HAL Reset</h3>
 *
 * @par
 * Resets the module using
 * @link HEARTRATE_3_RST @endlink .
 */
void hr3_hal_reset( void );


/**
 * @brief <h3>HAL Write</h3>
 *
 * @par
 * Generic write function adapted for I2C bus.
 *
 * @param[in] command - register address
 * @param[in] buffer - data buffer
 * @param[in] count - data size in bytes
 */
void hr3_hal_write( uint8_t *command, uint8_t *buffer, uint16_t count );

/**
 * @brief <h3>HAL Read</h3>
 *
 * @par
 * Generic read function adapted for SHT click.
 *
 * @param[in] command - register address
 * @param[out] buffer - data buffer
 * @param[in] count - data size in bytes
 */
void hr3_hal_read( uint8_t *command, uint8_t *buffer, uint16_t count );

void hr3_hal_delay( uint32_t ms );

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* HEARTRATE_3_HAL_H_ */

/*** End of File **************************************************************/
