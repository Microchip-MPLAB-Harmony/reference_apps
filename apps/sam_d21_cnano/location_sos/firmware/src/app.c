/****************************************************************************
* Title                 :   Location tagged SOS Application
* Filename              :   app.c
* Author                :   ST
* Origin Date           :   15/08/2018
* Notes                 :   None
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date    Software Version    Initials   Description
*  15/02/18        1.0.0           ST       App Created. 
 * 01/01/2020      2.0.0           MK       App Modified.
*****************************************************************************/
/****************************************************************************
* Note: In version 2.00, This file has been modified by MK to meet the custom 
* application requirements. Should you need to contact the modifier, Write an 
* Email to mohan.kumar@microchip.com or alternatively, write to 
* Mohan Kumar, Microchip Technology India Pvt Ltd
* Plot No. 1498, EPIP, 1st Phase Industrial Area, Whitefield, Bengaluru, 
* Karnataka 560066
* Note: In version 1.00, This file has been modified by ST to meet the custom 
* application requirements. Should you need to contact the modifier, Write an 
* Email to syed.thaseemuddin@microchip.com or alternatively, write to 
* Syed Thaseemuddin, Microchip Technology India Pvt Ltd
* Plot No. 1498, EPIP, 1st Phase Industrial Area, Whitefield, Bengaluru, 
* Karnataka 560066
*******************************************************************************/
/**
 * @file app.c
 * @brief Location tagged SOS App
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


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "dev_hal.h"
#include "dev_adapter.h"
#include "driver/usart/drv_usart.h"
#include "gsm_gps.h"
// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;
// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************
static void _APP_BUTTON_PRESS_Tasks(void);
static void _APP_TimerTickHandler ( uintptr_t context, uint32_t currTick );
static void _APP_UART_ReceiveCallback(    DRV_USART_BUFFER_EVENT bufferEvent,
    DRV_USART_BUFFER_HANDLE bufferHandle,
    uintptr_t context);
/* TODO:  Add any necessary local functions.
*/
extern void gsm_gps_task();
extern void dev_tick_isr();
extern void gsm_gps_init(void);
extern void dev_rx(char);
// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************
const uint8_t nvm_user_start_address[NVMCTRL_FLASH_ROWSIZE] __attribute__((aligned(NVMCTRL_FLASH_ROWSIZE),keep,externally_visible,space(prog)))= {0};

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;

}
volatile uint16_t counter=0;
void TC4_Callback_InterruptHandler(TC_TIMER_STATUS status, uintptr_t context)
{
    /* Toggle LED */
    counter++;
}
volatile bool timedout=0;
void TC5_Callback_InterruptHandler(TC_TIMER_STATUS status, uintptr_t context)
{
   timedout = 1;
   TC5_TimerStop();
}
volatile bool switchLngpress = 0,switchsrtpress = 0;
volatile bool low_edge = 0;
void EIC_User_Handler(uintptr_t context)
{
    if(low_edge == 1){ 
       TC4_TimerStop();
        if(counter >= 4){
           switchLngpress = 1;
        }else{
           switchsrtpress = 1;
        }
       counter = 0;
       low_edge = 0;
    }else if(low_edge == 0){
      low_edge = 1;
      TC4_TimerStart();
    }
 

}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */
void APP_Tasks ( void )
{
    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {        
            SYSTICK_DelayMs(300);  

            appData.state = APP_STATE_TIMER_TICK_INIT;
        }
        break;

        case APP_STATE_TIMER_TICK_INIT:
        {
            
            SYSTICK_DelayMs(10);  
            _APP_TimerTickHandler(0,0);
            appData.state = APP_USART_DRIVER_INIT;
        }
        break;

        case APP_USART_DRIVER_INIT:
        {
            /* Open an instance of USART driver */
            appData.usartHandle = DRV_USART_Open(DRV_USART_INDEX_0,
                         (DRV_IO_INTENT_READWRITE | DRV_IO_INTENT_BLOCKING));
            
            
            /* Check the USART driver handler */
            if (appData.usartHandle != DRV_HANDLE_INVALID )
            {
                DRV_USART_BufferEventHandlerSet(appData.usartHandle,&_APP_UART_ReceiveCallback,0);
                appData.state = APP_STATE_DEV_ADAPTER_INIT_PWR_CTRL_1;
            }
            else
            {
                    // Try again to get handle
            }
        }
        break;

        case APP_STATE_DEV_ADAPTER_INIT_PWR_CTRL_1:
        {
            dev_hal_init();
            dev_hal_pwr_ctl(1);
            SYSTICK_DelayMs(1000);
            appData.state = APP_STATE_DEV_ADAPTER_INIT_PWR_CTRL_2;
            break;
        }

        case APP_STATE_DEV_ADAPTER_INIT_PWR_CTRL_2:
        {
            dev_hal_pwr_ctl(0);
            SYSTICK_DelayMs(5000);
            appData.state = APP_STATE_GSM_GPS_INIT_COMPLETE;
            break;
        }

        case APP_STATE_GSM_GPS_INIT_COMPLETE:
        {
            dev_adapter_init();
            gsm_gps_init();          
            printf("\r\nGSM-GPS Initialized\r\n");
            printf("-------------------INFO--------------------------");
            printf("\r\nLong press switch to configure phone number or \r\nShort press to send SMS\r\n");
            printf("-------------------------------------------------\r\n");
            LED_Clear();
            appData.state = APP_STATE_SERVICE_TASKS;
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
           // gsm_gps_task();
            _APP_BUTTON_PRESS_Tasks();

            break;
        }
        default:
        {      
            break;
        }
    }
}

extern bool req_pend_f;
extern bool loc_update_f;
bool updated_phn_num = 0;
static void _APP_BUTTON_PRESS_Tasks(void)
{
   
    uint8_t phn_num[20] = {0};  
    
    char select = 0,select1 = 0;
    
    
    if(switchsrtpress){
        LED_Set();
        DRV_USART_WriteQueuePurge(appData.usartHandle);
        DRV_USART_ReadQueuePurge(appData.usartHandle);
        loc_update_f = true;
        req_pend_f = true;
        gsm_gps_task();
        switchsrtpress = 0;           
    }else if(switchLngpress){
        LED_Set();
        printf("\r\nEnter phone number with '+' and country code\r\n");
        printf("\r\nExample: <+><country_code><mobile_no>, +919934567890 and press Enter\r\n");
        scanf("\r\n%s",phn_num);
        printf("\r\nVerify Phn number =%s",phn_num);
        scanf("%c",&select);
        printf("\r\nEnter 'y' to update phone number");
        scanf("%c",&select1);
        if(select1 == 'y'){
             phn_num[18] = 'S';
             while(NVMCTRL_IsBusy());

             NVMCTRL_RowErase((uint32_t)nvm_user_start_address);

             while(NVMCTRL_IsBusy());

             NVMCTRL_PageWrite((uint32_t *)phn_num, (uint32_t)nvm_user_start_address);

             while(NVMCTRL_IsBusy());

             printf("\r\nPhone number updated\r\n");
   
            
        }else{
            printf("\r\nPhone number not updated\r\n");
        }
        printf("-------------------INFO--------------------------");
        printf("\r\nLong press switch to configure phone number or \r\nShort press to send SMS\r\n");
        printf("-------------------------------------------------\r\n");
        switchLngpress = 0;
        LED_Clear();
    }

}

static void _APP_TimerTickHandler ( uintptr_t context, uint32_t currTick )
{
    dev_tick_isr();
}

volatile char transfer_status = 0;
volatile char rxChar ; 

static void _APP_UART_ReceiveCallback(    DRV_USART_BUFFER_EVENT bufferEvent,
    DRV_USART_BUFFER_HANDLE bufferHandle,
    uintptr_t context)
{
    
    DRV_USART_ReadBufferAdd(appData.usartHandle,(void*)&rxChar,1,&appData.bufferHandle);
    dev_rx( rxChar);
}

/*******************************************************************************
 End of File
 */
