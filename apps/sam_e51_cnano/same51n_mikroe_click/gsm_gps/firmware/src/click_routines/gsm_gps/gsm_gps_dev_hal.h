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
*  01/01/2020      3.0.0           MK       Custom Application
*  05/07/2021      4.0.0           ST       Custom Application
*******************************************************************************/
/****************************************************************************
* Note: In version 2.00, 3.00, 4.00 This file has been modified to meet the custom
* application requirements. Should you need to contact the modifier write to
* 32-bit Applications group, Microchip Technology India Pvt Ltd
* Plot No. 1498, EPIP, 1st Phase Industrial Area, Whitefield, Bengaluru,
* Karnataka 560066
*******************************************************************************/
/**
 * @file dev_adapter.h
 * @brief Device Adapter
 *
 * @par
 * Used for adaptation needed for the particular device.
 */
//DOM-IGNORE-BEGIN 
/*******************************************************************************
 Copyright (C) 2021  Microchip Technology Incorporated and its subsidiaries.

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
//DOM-IGNORE-END 

#ifndef _GSM_GPS_DEV_HAL_H
#define _GSM_GPS_DEV_HAL_H

/******************************************************************************
* Includes
*******************************************************************************/

#include "gsm_gps_config.h"

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

#endif // _GSM_GPS_DEV_HAL_H

/*** End of File **************************************************************/