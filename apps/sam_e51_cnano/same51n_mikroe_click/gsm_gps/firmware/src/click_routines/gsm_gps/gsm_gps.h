/****************************************************************************
* Title                 :   GSM GPS
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

#include "gsm_gps_config.h"

#ifndef _GSM_GPS_H_
#define _GSM_GPS_H_

/* Initialization - Constructor
 ******************************************************************************/
void gsm_gps_init( void );
void gsm_gps_setup_sms_msg(char *mobile_number, char *message);
bool gsm_gps_get_location_data(char *lat, char *lon, char *alt);
void gsm_gps_send_msg(void);
/* Task
 *****************************************************************************/
void gsm_gps_task(void);

#endif