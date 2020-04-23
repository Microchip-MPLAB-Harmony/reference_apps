/******************************************************************************
* Title                 :   AT TIMER
* Filename              :   at_timer.h
* Author                :   MSV
* Origin Date           :   10/03/2016
* Notes                 :   None
*******************************************************************************/
/**************************CHANGE LIST ****************************************
*
*    Date    Software Version    Initials   Description
*  10/03/16    XXXXXXXXXXX         MSV      Interface Created.
*  15/02/18       2.0.0            ST       Custom Application 
*  01/01/2020      3.0.0            MK         Custom Application   
*******************************************************************************/
/**************************CONTACT INFORMATION********************************
* ST: syed.thaseemuddin@microchip.com
* MK: mohan.kumar@microchip.com
*/
/**
 * @file dev_timer.h
 * @brief AT Timer
 *
 * @par
 * Timer for GSM engine
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
#ifndef AT_TIMER_H
#define AT_TIMER_H
/******************************************************************************
* Includes
*******************************************************************************/

#include "config.h"

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

extern volatile bool                            timeout_f;

/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief AT Timer Initialisation
 *
 * @par
 * Must be executed before any other timer operation
 */
void dev_timer_init (void);

/**
 * @brief Tick ISR
 *
 * @par
 * This must be placed inside the ISR function that is going to be executed
 * every one millisecond
 */
void dev_tick_isr ( void);

/**
 * @brief AT Timer Start
 *
 * @par
 * Starts the timer
 */
void dev_timer_start (void);

/**
 * @brief AT Timer Restart
 *
 * @par
 * Restart the timer
 */
void dev_timer_restart (void);

/**
 * @brief AT Timer Stop
 *
 * @par
 * Stops the timer
 */
void dev_timer_stop (void);

/**
 * @brief AT Timer Load
 *
 * @par
 * Load new timer
 *
 * @param[in] timeout ( milliseconds)
 */
void dev_timer_load (uint32_t timeout);

#ifdef __cplusplus
}
#endif
#endif

/*******************************End of File ***********************************/
