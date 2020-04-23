/******************************************************************************
* Title                 :   AT PARSER
* Filename              :   at_engine.h
* Author                :   MSV
* Origin Date           :   10/03/2016
* Notes                 :   None
*******************************************************************************/
/**************************CHANGE LIST ****************************************
*
*    Date    Software Version    Initials   Description
*  10/03/16        1.0.0           MSV      Interface Created.
*  15/02/18        2.0.0           ST       Custom Application
*  01/01/2020      3.0.0            MK         Custom Application   
*******************************************************************************/
/**************************CONTACT INFORMATION********************************
* ST: syed.thaseemuddin@microchip.com
* MK: mohan.kumar@microchip.com
*/
/**
 * @file at_engine.h
 * @brief AT Engine
 *
 * @par
 * Engine for AT command based devices.
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

#ifndef AT_ENGINE_H
#define AT_ENGINE_H

/******************************************************************************
* Includes
*******************************************************************************/

#include "config.h"
#include "at_parser.h"
#include "dev_timer.h"
#include "dev_adapter.h"

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
 * @brief AT Engine Initialization
 *
 * Initialization of engine should be done before execution of any other
 * function.
 */
void engine_init
(
                at_cmd_cb default_callback
);

/**
 * @brief AT Command
 *
 * @par
 * Executes provided AT command
 *
 * @param[in] input
 */
void at_cmd
(
                char *input
);

/**
 * @brief AT addition
 *
 * @par
 * Some AT commands requires additional data, this function is used to add the
 * data after the module resposes with specific output.
 *
 * @param[in] input
 */
void at_cmd_addition
(
                char *input
);

/**
 * @brief Save AT Command to Storage
 *
 * @par
 * Saves provided command with callbacks and timeout to the storage for later
 * parsing.
 *
 * @param[in] cmd
 * @param[in] timeout
 * @param[in] setter
 * @param[in] getter
 * @param[in] tester
 * @param[in] executer
 */
void at_cmd_save
(
                char *cmd,
        uint32_t timeout,
        at_cmd_cb getter,
        at_cmd_cb setter,
        at_cmd_cb tester,
        at_cmd_cb executer
);

/**
 * @brief AT Process
 *
 * This function should be placed inside the infinite while loop.
 */
void at_process
(
                void
);

#ifdef __cplusplus
}
#endif

#endif

/*******************************End of File ***********************************/
