/****************************************************************************
* Title                 :   GSM ENGINE
* Filename        :   at_engine.c
* Author            :   MSV
* Origin Date    :   10/03/2016
* Notes              :   None
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date    Software Version    Initials   Description
*  10/03/16        1.0.0               MSV      Interface Created.
*  15/02/18        2.0.0               ST       Customized for Application 
 * 01/01/2020      3.0.0               MK       Customized for Application
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
 * @file at_engine.c
 * @brief GSM Engine
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
#include "at_engine.h"
#include "app.h"
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

/* TEMPS */
static uint32_t     temp_timer;
static at_cmd_cb    temp_cb;

/* FLAGS */
volatile bool       timeout_f;
volatile bool       exception_f;
volatile bool       response_f;
volatile bool       cue_f;

/* CALLBACKS */
static at_cmd_cb    cb;
static at_cmd_cb    cb_default;

/* BUFFERS */
char                tx_buffer[ AT_TRANSFER_SIZE ];
char                rx_buffer[ AT_TRANSFER_SIZE ];

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Private Function Definitions
*******************************************************************************/

/******************************************************************************
* Public Function Definitions
*******************************************************************************/

void engine_init
(
                at_cmd_cb default_callback
)
{    
    dev_timer_init();
    at_parser_init();
    
    cb_default = default_callback;
    
    at_cmd_save( "+CMS ERROR :", AT_DEFAULT_TIMEOUT, default_callback, 
                                                  default_callback, 
                                                  default_callback, 
                                                  default_callback );

    exception_f   = false;
    response_f    = false;
    cue_f         = false;

    memset( ( void* )tx_buffer, 0, AT_TRANSFER_SIZE );
}

void at_cmd
(
                char *input
)
{
    char* temp_input = input;

    at_parse( temp_input, &temp_cb, &temp_timer );
    dev_timer_load( temp_timer );

    while( cue_f )
        at_process();

    while( !dev_tx( *( temp_input++ ) ) );

    dev_adapter_reset();
    dev_timer_start();
    
}

void at_cmd_addition
(
                char *input
)
{
    char* temp_input = input;

    while( !exception_f )
        at_process();

    dev_timer_stop();

    while( !dev_tx( *( temp_input++ ) ) );

    dev_adapter_reset();
    dev_timer_restart();
}

void at_cmd_save
(
                char *cmd,
        uint32_t timeout,
        at_cmd_cb getter,
        at_cmd_cb setter,
        at_cmd_cb tester,
        at_cmd_cb executer
)
{
    if ( !setter )
        setter = cb_default;

    if( !getter )
        getter = cb_default;

    if( !tester )
        tester = cb_default;

    if( !executer )
        executer = cb_default;

    if( !timeout )
        timeout = AT_DEFAULT_TIMEOUT;

    at_parser_store( cmd, timeout, getter, setter, tester, executer );
}

void at_process
(
                void
)
{
    //response_f = true;
    if( response_f )
    {
        dev_hal_cts_ctl( false );
        dev_timer_stop();
        at_parse( rx_buffer, &cb, &temp_timer );
        cb( rx_buffer );
        dev_adapter_reset();

        timeout_f = false;
        exception_f = false;
        response_f = false;
        cue_f = false;
    }

    if( timeout_f )
    {
        dev_hal_cts_ctl( false );
        dev_timer_stop();
        at_parse( rx_buffer, &cb, &temp_timer );
        cb( rx_buffer );
        dev_adapter_reset();

        timeout_f = false;
        exception_f = false;
        response_f = true;
        cue_f = false;
    }
}

/*************** END OF FUNCTIONS *********************************************/
