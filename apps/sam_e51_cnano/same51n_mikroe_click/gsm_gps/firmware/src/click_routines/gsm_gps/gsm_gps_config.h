/******************************************************************************
* Title                 :   GSM GPS config
* Filename              :   gsm_gps_config.h
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
#ifndef _GSM_GPS_CONFIG_H
#define _GSM_GPS_CONFIG_H

/******************************************************************************
* Includes
*******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

/**
 * AT Head */
#define AT_HEAD                                         "AT"
#define AT_HEAD_SIZE                                    2

/**
 * General Error Message */
#define AT_CMS_ERROR                                    "+CMS ERROR:"
#define AT_CMS_ERROR_SIZE                               11

/**
 * Size of AT command. This should represent maximum size of request header */
#define AT_HEADER_SIZE                                  15

/**
 * Size of command storage. This represent number of commands that can be
 * stored to the module and later recognized by the library. */
#define AT_STORAGE_SIZE                                 50

/**
 * This is the maximum amount of characters that can be transfered per one
 * sequence in both directions. */
#define AT_TRANSFER_SIZE                                1024

/**
 * Default timeout in milliseconds for the specific module */
#define AT_DEFAULT_TIMEOUT                              500

/******************************************************************************
* Typedefs
*******************************************************************************/

typedef enum
{
    AT_OK,
    AT_ERROR,
    AT_UNKNOWN

}at_t;

typedef void ( *at_cmd_cb )( char *buffer );

#endif
/*******************************End of File ***********************************/
