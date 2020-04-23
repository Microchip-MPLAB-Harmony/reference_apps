/****************************************************************************
* Title                 :   AT PARSER
* Filename              :   dev_hal.h
* Author                :   MSV
* Origin Date           :   01/02/2016
* Notes                 :   None
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date    Software Version    Initials       Description
*  01/02/16       1.0.0             MSV        Module Created.
*  15/02/18       2.0.0             ST         Custom Application
*  01/01/2020      3.0.0            MK         Custom Application   
*******************************************************************************/
/**************************CONTACT INFORMATION********************************
* ST: syed.thaseemuddin@microchip.com
* MK: mohan.kumar@microchip.com
*/
/**
 * @file dev_hal.h
 * @brief HAL layer
 *
 * @par
 * HAL layer for AT parser
 */
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
#ifndef DEV_HAL_H
#define DEV_HAL_H

/******************************************************************************
* Includes
*******************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "definitions.h"
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

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
 * @brief PWR
 *
 * @par
 * Power pin control
 *
 * @param[in] state
 */
void dev_hal_pwr_ctl (bool state);

/**
 * @brief RTS
 *
 * @par
 * Hardware flow control of sending data
 *
 * @retval RTS pin state
 */
bool dev_hal_rts_ctl (void);

/**
 * @brief CTS
 *
 * @par
 * Hardware flow control of incoming data
 *
 * @param[in] state of CTS
 */
void dev_hal_cts_ctl (bool state);

/**
 * @brief HAL Initialization
 *
 * HAL layer initialization. Must be called before any other function.
 * Used for assigning the function pointers.
 */
void dev_hal_init (void);

/**
 * @brief HAL Write
 *
 * @par
 * Writes data through UART bus
 *
 * @param[in] buffer
 */
void dev_hal_write (char *ch, unsigned int len);

#ifdef __cplusplus
} // extern "C"
#endif
#endif

