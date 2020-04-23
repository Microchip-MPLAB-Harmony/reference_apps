/****************************************************************************
* Title                 :   GSM GPS App
* Filename              :   gsm_gps.c
* Author                :   MSV
* Origin Date           :   10/03/2016
* Notes                 :   None
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date    Software Version    Initials   Description
*  10/03/16        1.0.0           MSV      App Created.
*  15/02/18        2.0.0           ST       App Customized. 
*  01/01/2020      3.0.0           MK       Custom Application
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
 * @file gsm_gps.c
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

/******************************************************************************
* Includes
*******************************************************************************/
#include "gsm_gps.h"
#include "app.h"

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/
#define M_CMD_MSG_HEADER        ("AT+CMGS=")
#define M_CRLF                  ("\r\n")
#define M_CR                    ("\r")
#define M_QUOTES                ("\"")
#define M_CMD_MSG_END           (26)
// The Mobile Phone number to which the SMS would be sent
#define M_MOBILE_NUMBER         "+917892015627"

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/
extern APP_DATA appData;
/* Flags
 ******************************************************************************/
bool req_pend_f = false;
bool loc_update_f = false;
static bool ring_f = false;
static long latt = -1;
static long lonn = -1;
static long altt = -1;        
static char latitude[ 10 ] = { 0 };
static char longitude[ 10 ] = { 0 };
static char altitude[ 9 ] = { 0 };
static char tmp_num[ 20 ];
extern uint8_t nvm_user_start_address[NVMCTRL_FLASH_ROWSIZE];
/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Private Function Definitions
*******************************************************************************/

/******************************************************************************
* Public Function Definitions
*******************************************************************************/
void gsm_gps_init (void)
{
    engine_init( gsm_gps_evn_default );
    at_cmd_save( "+CGNSINF", 1000, NULL, NULL, NULL, gps_evn_location );
    gps_act_pwr_control( true ); 
    at_cmd( "AT+CGNSINF" );
    at_cmd( "AT+CSCS=\"GSM\"" );
    at_cmd( "AT+CMGF=1" );
}

void gsm_gps_evn_default (char *response)
{
}

void gsm_ev_ring (char *response)
{
    ring_f = true;
}


void gsm_evn_call_id (char *response)
{
    char *tmp_s = strchr( response, '\"' );
    char *tmp_e = strchr( tmp_s + 1, '\"' );

    strncpy( tmp_num, tmp_s , tmp_e - tmp_s + 1 );
   
}

void gsm_act_read_info (void)
{
    char tmp[ 60 ] = { 0 };    
    strcpy( tmp, "AT+CMGR=" );
    strcat( tmp, M_MOBILE_NUMBER );
    at_cmd( tmp ); 
}

void gsm_act_send_info (void)
{
    char phn_num_updt_flg; 
    char phn_num1[20];
    
    char tmp[ 60 ] = { 0 };
    char msg[ 700 ] = { 0 };
    uint16_t n=0;
    
    strcpy( tmp, "AT+CMGS=" );
    strcat( tmp, M_QUOTES );
    
    NVMCTRL_Read((uint32_t *)&phn_num_updt_flg,1,(uint32_t)nvm_user_start_address+18);

    while(NVMCTRL_IsBusy());
    
    if(phn_num_updt_flg == 'S'){
        NVMCTRL_Read((uint32_t *)phn_num1,20,(uint32_t)nvm_user_start_address);
        while(NVMCTRL_IsBusy());
        strcat(tmp,(char*)phn_num1);
    }else{     
        strcat( tmp, M_MOBILE_NUMBER );
    }
    strcat(tmp,M_QUOTES);    
    strcat(tmp,M_CR);      

    strcpy( msg, "SAM D21 Curiosity Nano Location tagged SOS.\r\n" );
    strcat( msg, "Please attend an Emergency @ \r\n" );
    strcat( msg, "Latitude : " );
    strcat( msg, latitude );
    strcat( msg, "\r\nLongitude : " );
    strcat( msg, longitude );
    strcat( msg, "\r\nAltitude : " );
    strcat( msg, altitude );
    strcat(msg, "\r\nhttp://maps.google.com/maps?q=loc:");
    strcat( msg, latitude );
    strcat(msg, ",");
    strcat( msg, longitude );

    n = strlen(msg);
    msg[n-1]=26;
    at_cmd( tmp );
    SYSTICK_DelayMs(10);
    at_cmd_addition( msg );
    
   
}

void gps_act_pwr_control (bool state)
{
    if( state )
    {
        at_cmd( "AT+CGNSPWR=1" );
    }
    else
        at_cmd( "AT+CGNSPWR=0" );
}

void gsm_gps_task (void)
{
    at_process();
    
    if (loc_update_f) 
    {
        //at_cmd( "AT" );
        at_cmd( "AT+CGNSINF" );       
        loc_update_f = false;
    }    
    
  
    if (req_pend_f) 
    {
        SYSTICK_DelayMs(50); 
        gsm_act_send_info(); // Send GPS info with SMS
        req_pend_f = false; 
        SYSTICK_DelayMs(100); 
        //at_cmd("AT");
        printf("-------------------INFO--------------------------");
        printf("\r\nLong press switch to configure phone number or \r\nShort press to send SMS\r\n");
        printf("-------------------------------------------------\r\n");
        LED_Clear();
    }
}

void gps_evn_location (char *response )
{
    char* end;
    end = strchr( response + 66, ',' );

    if(end != NULL)
    {
        if( *( end - 1 ) != ',' )
        {
            my_strncpy( latitude, response + 46, 9 );
            my_strncpy( longitude, response + 56, 9 );
            my_strncpy( altitude, response + 66, end - ( response + 66 ) );
            latt = atol( latitude );
            lonn = atol( longitude );    
            altt = atol( altitude );           
            if(latt <= 0 ||  lonn <= 0 || altt <= 0)
            {
                loc_update_f = true;
            }
            else
            {
                req_pend_f = true;
                latt = -1;
                lonn = -1;
                altt = -1;
            }
        }
        else 
        {   
            strcpy( latitude, "NA" );
            strcpy( longitude, "NA" );
            strcpy( altitude, "NA" );
            loc_update_f = true;
        }
    }
    else
    {
        loc_update_f = true;
    }
}

/*************** END OF FUNCTIONS *********************************************/