 /*******************************************************************************
  GSM GPS click example source file

  Company:
    Microchip Technology Inc.

  File Name:
    gsm_gps_example.c

  Summary:
    GSM GPS click routine example implementation File.

  Description:
    This file implements the usage of the GSM GPS click routine APIs.
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

#include "gsm_gps.h"
#include "gsm_gps_example.h"
#include "definitions.h"
#include "../click_interface.h"

static char latitude[ 10 ] = { 0 };
static char longitude[ 10 ] = { 0 };
static char altitude[ 9 ] = { 0 };

static void _gsm_gps_example_construct_message(char *msg);

void gsm_gps_example(void)
{
    char msg[ 700 ] = { 0 };    
   
    gsm_gps_task();
    if(gsm_gps_get_location_data(latitude,longitude,altitude))
    {
        _gsm_gps_example_construct_message(msg);
        gsm_gps_setup_sms_msg(GSM_GPS_EXAMPLE_USER_MOBILE_NUMBER,msg);
        gsm_gps_send_msg();
    }
    else
    {
        printf("Location information not found yet! Try Again\r\n");
    }
   
}


static void _gsm_gps_example_construct_message(char *msg)
{
    strcpy( msg, "GSM GPS Click Example \r\n" );
    strcat( msg, "SMS with GPS coordinates \r\n" );
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