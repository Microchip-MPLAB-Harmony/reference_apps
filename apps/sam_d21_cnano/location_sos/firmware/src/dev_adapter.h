/******************************************************************************
* Title                 :   AT PARSER
* Filename              :   dev_adapter.h
* Author                :   MSV
* Origin Date           :   10/03/2016
* Notes                 :   None
*******************************************************************************/
/**************************CHANGE LIST ****************************************
*
*    Date    Software Version    Initials   Description
*  10/03/16    XXXXXXXXXXX         MSV      Interface Created.
*  15/02/18        2.0.0           ST       Custom Application 
*  01/01/2020      3.0.0            MK         Custom Application   
*******************************************************************************/
/**************************CONTACT INFORMATION********************************
* ST: syed.thaseemuddin@microchip.com
* MK: mohan.kumar@microchip.com
*/
/**
 * @file dev_adapter.h
 * @brief Device Adapter
 *
 * @par
 * Used for adaptation needed for the particular device.
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
#ifndef AT_ADAPTER_H
#define AT_ADAPTER_H

/******************************************************************************
* Includes
*******************************************************************************/

#include "config.h"
#include "dev_hal.h"
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

extern volatile bool            exception_f;
extern volatile bool            response_f;
extern volatile bool            cue_f;

extern char            tx_buffer[ AT_TRANSFER_SIZE ];
extern char            rx_buffer[ AT_TRANSFER_SIZE ];

/******************************************************************************
* Function Prototypes
*******************************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief Adapter Initialization
 */
void dev_adapter_init (void);

/**
 * @brief Adapter Flags Reset
 */
void dev_adapter_reset
(
                void
);

/**
 * @brief Transmission
 *
 * @param tx_input - character for transmission through UART bus
 */
int dev_tx
(
                char tx_input
);

/**
 * @brief Reception
 *
 * This function should be placed inside the RX interrupt routine.
 *
 * @param[in] rx_input - character received through UART bus
 */
void dev_rx
(
                char rx_input
);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // AT_RECEIVER_H

/*** End of File **************************************************************/