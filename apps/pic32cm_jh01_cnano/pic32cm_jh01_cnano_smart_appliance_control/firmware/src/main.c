/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <string.h>
#include <stdio.h>
#include "config/default/definitions.h"
#include "click_routines/weather/bme280.h"
#include "click_routines/weather/weather.h"
#include "click_routines/click_interface.h"
#include "click_routines/eink_epaper_2_9_296_128/eink_epaper_2_9_296_128.h"
#include "click_routines/eink_epaper_2_9_296_128/eink_epaper_2_9_296_128_font.h"
#include "click_routines/eink_epaper_2_9_296_128/eink_epaper_2_9_296_128_image.h"
#include "click_routines/fan/fan.h"
#include "app_ble.h"
#include "app_temp.h"
extern int touch_count;
extern uint8_t key_status0;

/****************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************/
extern void check_touch();

void check_touch()
{
    SYSTICK_DelayMs(1);
    touch_process();
	if (measurement_done_touch == 1)
    {
        measurement_done_touch = 0;
 		key_status0 = get_sensor_state(0) & 0x80;
        
		if (0u != key_status0 ) 
        {
          do
          {
             LED_On();
             touch_process();
		     if (measurement_done_touch == 1) 
             {
			  measurement_done_touch = 0;
              key_status0 = get_sensor_state(0) & 0x80; 
             }
          }while(0u != key_status0);
               
          touch_count++;
              
        }
		else
        {
           
		 LED_Off();
                 
        }

	}
 
}
    

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************/



int main ( void )
{
    key_status0 = 0;
    touch_count = 0;
    SYS_Initialize ( NULL );
    
    CLICK_FAN_TimerStart(); 
    CLICK_FAN_DelayMs(1000);
    fan_init();    
    fan_switch_off();
    CLICK_FAN_DelayMs(1000);

    eink_epaper_2_9_296_128_init();
    eink_epaper_2_9_296_128_set_font( guiFont_Tahoma_10_Regular, EINK_EPAPER_2_9_296_128_COLOR_WHITE, FO_HORIZONTAL);
    eink_epaper_2_9_296_128_image_bmp(mchp_logo_fan);
   
   
    while ( true )
    {
        
        check_touch();
        
        if(touch_count%2 == 0)
        { 
         APP_TEMP_Tasks();          // printf("\r\n Entered Temperature Control Mode");
        }
        
        else
        {
         APP_BLE_Tasks();           // printf("\r\n Entered BLE Control Mode");
        }
        
           
    } 
    return ( EXIT_FAILURE );
}

/*******************************************************************************
 End of File
*/

