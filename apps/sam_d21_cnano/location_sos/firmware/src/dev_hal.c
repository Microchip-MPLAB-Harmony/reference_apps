/*******************************************************************************
* Title                 :   AT PARSER
* Filename              :   dev_hal.c
* Author                :   MSV
* Origin Date           :   01/02/2016
* Notes                 :   None
*******************************************************************************/
/*************** MODULE REVISION LOG ******************************************
*
*    Date    Software Version    Initials       Description
*  01/02/16       1.0.0             MSV        Module Created.
*  15/02/18        2.0.0            ST         Customized for Application 
*  01/01/2020      3.0.0            MK         Custom Application
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
 * @file dev_hal.c
 * @brief HAL layer
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
#include "dev_hal.h"
#include "app.h"
#include "driver/usart/drv_usart.h"
#include "dev_adapter.h"
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

/******************************************************************************
* Function Prototypes
*******************************************************************************/
extern void dev_rx( char ch );

/******************************************************************************
* Function Definitions
*******************************************************************************/
void dev_hal_pwr_ctl (bool state)
{
    if ( state )
    {        
          POWER_KEY_Set();    
    }
    else
    {
       POWER_KEY_Clear();           
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
}
extern volatile bool       response_f,exception_f,timeout_f;
extern volatile bool timedout;
extern APP_DATA appData;
void dev_hal_write (char *ch, unsigned int len)
{
    DRV_USART_WriteBufferAdd(appData.usartHandle, ch,len,&appData.bufferHandle);
    TC5_TimerStart();
    while(DRV_USART_BufferStatusGet(appData.bufferHandle) != DRV_USART_BUFFER_EVENT_COMPLETE)
    {
        if(response_f == 1 || exception_f == 1 ||timeout_f == 1 )
        {
            TC5_TimerStop();       
            printf("%s",rx_buffer);  
            break;
        }
        else if(timedout == 1)
        {
            printf("timedout\r\n");
            printf("%s",rx_buffer); 
            timeout_f = 1;
            timedout = 0;
            break;
        }
    }
    
  }

