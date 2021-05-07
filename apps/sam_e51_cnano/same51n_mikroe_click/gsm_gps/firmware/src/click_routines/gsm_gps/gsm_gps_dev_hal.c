/****************************************************************************
* Title                 :   GSM ADAPTER
* Filename              :   gsm_adapter.h
* Author                :   MSV
* Origin Date           :   10/03/2016
* Notes                 :   None
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date    Software Version    Initials   Description
*  10/03/16    XXXXXXXXXXX         MSV      Interface Created.
*  15/02/18        2.0.0           ST       Custom Application
*  05/07/2021      3.0.0           ST       Custom Application
*****************************************************************************/
/****************************************************************************
* Note: In version 2.00, 3.00 This file has been modified to meet the custom
* application requirements. Should you need to contact the modifier write to
* 32-bit Applications group, Microchip Technology India Pvt Ltd
* Plot No. 1498, EPIP, 1st Phase Industrial Area, Whitefield, Bengaluru,
* Karnataka 560066
*******************************************************************************/
/**
 * @file gsm_gps.c
 * @brief GSM GPS App
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
/******************************************************************************
* Includes
*******************************************************************************/
#include "definitions.h"                // SYS function prototypes
#include "../click_interface.h"
#include "gsm_gps_dev_hal.h"

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
static volatile uint16_t        rx_idx;
static volatile uint16_t        tx_idx;

/* Fragment flags */
static volatile bool            head_f;
static volatile bool            data_f;
static volatile bool            summ_f;

/* Fragment triggers */
static volatile bool            head_t;
static volatile bool            data_t;
static volatile bool            summ_t;

/* Sentence flags */
static volatile bool            term_f;
static volatile bool            frag_f;

/* Error check variables */
static uint8_t         err_c;
static bool            err_f;
static char*           data_ptr;
static char            error[ AT_HEADER_SIZE ];


/* Timer variable definitions
*******************************************************************************/
static volatile bool            timer_f;
static volatile uint32_t        timer_c;
static volatile uint32_t        timer;
static volatile uint32_t        timerTicks = 0;

extern volatile bool       response_f,exception_f,timeout_f,cue_f;
extern char                tx_buffer[ AT_TRANSFER_SIZE ];
extern char                rx_buffer[ AT_TRANSFER_SIZE ];

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Private Function Definitions
*******************************************************************************/
/* Timer functions
*******************************************************************************/
static void timerCallback ( uintptr_t context );


/******************************************************************************
* Public Function Definitions
*******************************************************************************/
void dev_adapter_init (void)
{
    dev_adapter_reset();
    err_c       = 0;
    err_f       = false;
    strcpy( error, ( char* )AT_CMS_ERROR );
    memset( ( void* )tx_buffer, 0, AT_TRANSFER_SIZE );
    memset( ( void* )rx_buffer, 0, AT_TRANSFER_SIZE );
}

void dev_adapter_reset (void)
{
    rx_idx      = 0;

    term_f      = false;
    frag_f      = false;

    head_f      = false;
    data_f      = false;
    summ_f      = false;

    head_t      = false;
    data_t      = false;
    summ_t      = false;

    dev_hal_cts_ctl( true );
}

int dev_tx (char tx_input)
{
    if (tx_input != '\0')
    {
        tx_buffer[ tx_idx++ ] = tx_input;

    }
    else
    {
        if (!exception_f)
        {
            tx_buffer[ tx_idx++ ] = '\r';
            tx_buffer[ tx_idx++ ] = '\n';
            tx_buffer[ tx_idx ] = '\0';
        }
        else
        {
            tx_buffer[ tx_idx++ ] = 0x1A;
            tx_buffer[ tx_idx++ ] = '\r';
            tx_buffer[ tx_idx ] = '\0';
        }

        dev_hal_write(tx_buffer,tx_idx);
        tx_idx = 0;
        cue_f = true;
        return 1;
    }

    if (tx_idx == AT_TRANSFER_SIZE)
    {
        tx_buffer[ tx_idx ] = '\0';
        dev_hal_write(tx_buffer,tx_idx);
        tx_idx = 0;
        return 0;
    }
    return 0;
}

void dev_rx (char rx_input)
{
    if (rx_input == '\r')
    {
        term_f = true;
    }

    if (rx_input == '\n' && term_f)
    {
        term_f = false;
        frag_f = true;
    }

    if (!frag_f)
    {
        if (!head_f && !data_f && !summ_f)
        {
            if (rx_input == 'A')
            {
                head_f = true;
            }
            else if (rx_input == 'O' || rx_input == 'E' ||
                     rx_input == 'B' || rx_input == 'C' ||
                     rx_input == 'R' || rx_input == 'N' || rx_input == 'P')
            {
                summ_f = true;
            }
            else if (rx_input == '+' || data_t)
            {
                data_f = true;
            }
        }
        if (rx_input == '>')
        {
            exception_f = true;
        }
    }

    if (head_f)
    {
        if (!head_t)
        {
            head_t = true;
        }
        rx_buffer[ rx_idx++ ] = rx_input;
    }

    if (data_f)
    {
        if (!data_t)
        {
            data_t = true;
            data_ptr = &rx_buffer[ rx_idx ];
        }
        rx_buffer[ rx_idx++ ] = rx_input;
    }

    if (summ_f)
    {
        if (!summ_t)
        {
            summ_t = true;
        }
        rx_buffer[ rx_idx++ ] = rx_input;
    }

    if (frag_f)
    {
        if (head_f)
        {
            head_f = false;
        }
        if (data_f)
        {
            while (*error)
            {
                if (error[err_c] == *(data_ptr + err_c))
                {
                    err_f = true;
                }
                else
                {
                    err_f = false;
                    break;
                }
                err_c++;
            }
            if (err_f)
            {
                rx_buffer[ rx_idx ] = '\0';
                response_f = true;
            }

            if (!head_t)
            {
                rx_buffer[ rx_idx ] = '\0';
                response_f = true;
            }
            err_c = 0;
            data_f = false;
        }

        if (summ_f)
        {
            rx_buffer[ rx_idx ] = '\0';
            response_f = true;
        }
        frag_f = false;
    }

    if (rx_idx == AT_TRANSFER_SIZE)
    {
        rx_buffer[ rx_idx ] = '\0';
        response_f = true;
    }
}


/* Timer functions
*******************************************************************************/
extern volatile bool                            timeout_f;

static void timerCallback ( uintptr_t context )
{
	timerTicks++;
}

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



/* Dev uart functions
*******************************************************************************/
void dev_hal_pwr_ctl (bool state)
{
    if ( state )
    {
        CLICK_GSM_GPS_POWER_Set();
    }
    else
    {
        CLICK_GSM_GPS_POWER_Clear();
    }
}

bool dev_hal_rts_ctl()
{
    return true;
}

void dev_hal_cts_ctl (bool state)
{
}


void dev_hal_init ()
{
	CLICK_GSM_GPS_TimerCallbackSet(timerCallback, (uintptr_t) NULL);

}

void dev_hal_write (char *ch, unsigned int len)
{
    CLICK_GSM_GPS_USART_Write(ch,len);
    timerTicks = 0;
    while(true == CLICK_GSM_GPS_USART_ReadIsBusy())
    {
        if(response_f == 1 || exception_f == 1 ||timeout_f == 1 )
        {
            timerTicks = 0;
            break;
        }
        else if(timerTicks == 1000)
        {
            printf("timedout\r\n");
            timeout_f = 1;
            break;
        }
    }

  }

/*************** END OF FUNCTIONS *********************************************/
