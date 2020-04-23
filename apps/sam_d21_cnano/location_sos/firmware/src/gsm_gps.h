/****************************************************************************
* Title                 :   GSM GPS App
* Filename              :   gsm_gps.h
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
 * @file gsm_gps.h
 * @brief GSM GPS App
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

#include "at_engine.h"

#ifndef _GSM_GPS_H_
#define _GSM_GPS_H_

/* Initialization - Constructor
 ******************************************************************************/
void gsm_gps_init( void );
/* Event handlers
 ******************************************************************************/
void gsm_gps_evn_default (char *response);
void gsm_ev_ring (char *response);
void gsm_evn_call_id (char *response);
void gps_evn_location (char *response);

/* Actions
 ******************************************************************************/
void gsm_act_read_info (void);
void gsm_act_send_info (void);
void gps_act_pwr_control (bool state);

/* Task
 *****************************************************************************/
void gsm_gps_task(void);

#endif