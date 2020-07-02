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

/**
 * @file eink_hal.h
 * @brief                   EINK click
 *
 ******************************************************************************/

#ifndef EINK_HAL_H_
#define EINK_HAL_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/* 			Functions
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief HAL Initialization
 *
 * Initialization of HAL layer.
 * Initializes function pointers and must be called first.
 */
void hal_eink_init( void );

/**
 * @brief HAL Delay
 *
 * @param[in]   ms          Amount of delay in miliseconds
 */
void hal_eink_delay( uint16_t ms );

/**
 * @brief SPI Write
 *
 * @param[in] 	*buffer     Data for writting
 * @param[in] 	count       Number of bytes to write
 *
 * @par
 * Writes data through SPI bus
 *
 * @note Function have no affect to the CS PIN state - chip select is
 * controled directly from HW layer.
 */
void hal_eink_write
(
        uint8_t* buffer,
        uint16_t count
);

/**
 * @brief SPI Read
 *
 * @param[out] 	*buffer     Buffer to store data from device
 * @param[in] 	count       Number of bytes to read
 *
 * @note Function have no affect to the CS PIN state - chip select is
 * controled directly from HW layer
 */
void hal_eink_read
(
        uint8_t* buffer,
        uint16_t count
);

/**
 * @brief SPI Transfer
 *
 * @param[in] 	*input      Data for writting
 * @param[out] 	*output     Buffer to store data from device
 * @param[in] 	count       Number of bytes to transfer
 *
 * @note Function have no affect to the CS PIN state - chip select is
 * controled directly from HW layer
 *
 */
void hal_eink_transfer
(
        uint8_t* input,
        uint8_t* output,
        uint16_t count
);

#ifdef __cplusplus
} // extern "C"
#endif
#endif
///@}
/**
 * @}                                                           End of File
 ******************************************************************************/
