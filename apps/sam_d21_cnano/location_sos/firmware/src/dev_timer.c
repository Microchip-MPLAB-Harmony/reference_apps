/******************************************************************************
* Title                 :   AT PARSER
* Filename              :   at_timer.c
* Author                :   MSV
* Origin Date           :   10/03/2016
* Notes                 :   None
*******************************************************************************/
/**************************CHANGE LIST ****************************************
*
*    Date    Software Version    Initials   Description
*  10/03/16        1.0.0           MSV      Interface Created.
*  15/02/18        2.0.0           ST       Customized for Application 
* 01/01/2020      3.0.0            MK       Custom Application
*****************************************************************************/
/****************************************************************************
* Note: In version 3.00, This file has been modified by MK to meet the custom 
* application requirements. Should you need to contact the modifier, Write an 
* Email to mohan.kumar@microchip.com or alternatively, write to 
* Mohan Kumar, Microchip Technology India Pvt Ltd
* Plot No. 1498, EPIP, 1st Phase Industrial Area, Whitefield, Bengaluru, 
* Karnataka 560066
* Note: In version 2.00, This file has been modified by ST to meet the custom 
* application requirements. Should you need to contact the modifier, Write an 
* Email to syed.thaseemuddin@microchip.com or alternatively, write to 
* Syed Thaseemuddin, Microchip Technology India Pvt Ltd
* Plot No. 1498, EPIP, 1st Phase Industrial Area, Whitefield, Bengaluru, 
* Karnataka 560066
*******************************************************************************/
/**
 * @file dev_timer.c
 * @brief AT Timer
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

/******************************************************************************
* Includes
*******************************************************************************/
#include "dev_timer.h"

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

static volatile bool            timer_f;
static volatile uint32_t        timer_c;
static volatile uint32_t        timer;

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Private Function Definitions
*******************************************************************************/

/******************************************************************************
* Public Function Definitions
*******************************************************************************/

void dev_timer_init (void)
{
    timer       = 0;
    timer_c     = 0;
    timeout_f   = false;
    timer_f     = false;       
}

void dev_tick_isr (void) 
{
    if (timer_f)
    {
        if (timer_c++ > timer)
        {
            timeout_f = true;
        }
    }
}

void dev_timer_start (void) 
{
    timer_f = true;
    timer_c = 0;
}

void dev_timer_restart (void)
{
    timer_c = 0;
}

void dev_timer_stop (void)
{
    timer_f = false;
    timer_c = 0;
}

void dev_timer_load (uint32_t timeout)
{
    timer = timeout;
}
/*************** END OF FUNCTIONS *********************************************/
