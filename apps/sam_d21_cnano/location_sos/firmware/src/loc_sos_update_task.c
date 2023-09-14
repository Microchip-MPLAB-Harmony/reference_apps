 /*******************************************************************************
   location sos update task source file

  Company:
    Microchip Technology Inc.

  File Name:
    loc_sos_update_task.c

  Summary:
  Reads the GPS location, construct SOS message and sends to assigned phone number 

  Description:
    This file implements location sos functionality
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*
    (c) 2021 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/
// DOM-IGNORE-END

#include "click_routines/gsm_gps/gsm_gps.h"
#include "loc_sos_update_task.h"
#include "definitions.h"
#include "click_routines/click_interface.h"

static char latitude[ 10 ] = { 0 };
static char longitude[ 10 ] = { 0 };
static char altitude[ 9 ] = { 0 };
extern uint8_t nvm_user_start_address[NVMCTRL_FLASH_ROWSIZE];
static void _loc_sos_construct_message(char *msg);

void loc_sos_update_task(void)
{
    char msg[ 700 ] = { 0 };   
    char phn_num_updt_flg; 
    char phn_num1[20];
   
    gsm_gps_task();
    if(gsm_gps_get_location_data(latitude,longitude,altitude))
    {
        _loc_sos_construct_message(msg);
        
        NVMCTRL_Read((uint32_t *)&phn_num_updt_flg,1,(uint32_t)nvm_user_start_address+18);

        while(NVMCTRL_IsBusy());
    
        if(phn_num_updt_flg == 'S'){
            NVMCTRL_Read((uint32_t *)phn_num1,20,(uint32_t)nvm_user_start_address);
            while(NVMCTRL_IsBusy());
            gsm_gps_setup_sms_msg(phn_num1,msg);
        }else{     
            gsm_gps_setup_sms_msg(GSM_GPS_EXAMPLE_USER_MOBILE_NUMBER,msg);
        }
        gsm_gps_send_msg();
    }
    else
    {
        printf("Location information not found yet! Try Again\r\n");
    }
   
}


static void _loc_sos_construct_message(char *msg)
{
    strcpy( msg, "Please attend emergency at: \r\n" );
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
    
}