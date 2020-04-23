/******************************************************************************
* Title                 :   AT PARSER
* Filename              :   at_parser.h
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
 * @file at_parser.h
 * @brief AT Parser
 *
 * @par
 * Parser for AT commands.
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

#ifndef AT_PARSER_H
#define AT_PARSER_H

/******************************************************************************
* Includes
*******************************************************************************/

#include <stdbool.h>
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
/**
 * @enum at_ctl_t
 * @brief AT Command Type
 */
typedef enum
{
    /**
     * Unknown command */
    AT_CMD_UNKNOWN                              = 0,
    /**
     * AT Get command */
    AT_CMD_GET                                  = 1,
    /**
     * AT Set command */
    AT_CMD_SET                                  = 2,
    /**
     * AT Test command */
    AT_CMD_TEST                                 = 3,
    /**
     * AT Execute command */
    AT_CMD_EXEC                                 = 4,

}at_type_t;

/**
 * @struct at_cmd_t
 * @brief Parser Structure
 *
 * @par
 * This struct is used for storing the command with timeout and callbacks.
 * Command strings are converted to the hash code for easiest comparision.
 */
typedef struct
{
    /**
     * Command Hash Value */
    uint32_t                hash;
    /**
     * Command Timeout */
    uint32_t                timeout;
    /**
     * Get Callback */
    at_cmd_cb               getter;
    /**
     * Set Callback */
    at_cmd_cb               setter;
    /**
     * Test Callback */
    at_cmd_cb               tester;
    /**
     * Execute Callback */
    at_cmd_cb               executer;

}at_cmd_t;
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
 * @brief AT Parser Initialization
 *
 * @note
 * Must be executed before any other operation.
 */
void at_parser_init
(
                void
);

/**
 * @brief Store Command
 *
 * @par
 * Stores the command and function pointers for command provided.
 *
 * @param[in] command
 * @param[in] timeout
 * @param[in] getter
 * @param[in] setter
 * @param[in] tester
 * @param[in] executer
 */
void at_parser_store
(
                char *command,
        uint32_t timeout,
        at_cmd_cb getter,
        at_cmd_cb setter,
        at_cmd_cb tester,
        at_cmd_cb execute
);

/**
 * @brief Parse Command
 *
 * @par
 * Parses provided input and sets the callback and timeout for provided input.
 *
 * @param[in] cmd
 * @param[out] cb
 * @param[out] timeout
 */
void at_parse
(
    char *input,
    at_cmd_cb *cb,
    uint32_t *timeout
);

char* my_strncpy(char* dst, const char* src, size_t n);

#ifdef __cplusplus
} // extern "C"
#endif

#endif

/*** End of File **************************************************************/