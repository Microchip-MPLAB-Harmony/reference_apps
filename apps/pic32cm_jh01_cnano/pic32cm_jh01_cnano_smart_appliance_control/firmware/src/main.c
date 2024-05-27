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

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
//DOM-IGNORE-END

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
#include "config/pic32cm_jh01_cnano/definitions.h"
#include "click_routines/weather/bme280.h"
#include "click_routines/weather/weather.h"
#include "click_routines/click_interface.h"
#include "click_routines/eink_epaper_2_9_296_128/eink_epaper_2_9_296_128.h"
#include "click_routines/eink_epaper_2_9_296_128/eink_epaper_2_9_296_128_font.h"
#include "click_routines/eink_epaper_2_9_296_128/eink_epaper_2_9_296_128_image.h"
#include "click_routines/fan/fan.h"
#include "click_routines/rnbd451/rnbd451.h"
#include "click_routines/rnbd451/rnbd451_example.h"


// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************

//Touch
int touch_count;
uint8_t key_status0;

//RNBD
extern char ble_resp[10];

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

/** 
  @Function
    void  check_touch(void) 

  @Summary
 Check for any input on the touch button and navigate to the respective mode.

 */
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
    int16_t temperature = 0;
    int16_t dummy_temperature = 0;
    char  buffer1[12], buffer[100];
    char temp_buffer[10];

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
   
    rnbd451_app_initialize();
    
    while ( true )
    {
        check_touch();
        if(touch_count%2 == 0)
        { 
            //Temperature Control Mode
            
            LED_On();
            
            Weather_readSensors();
            temperature =(int16_t)Weather_getTemperatureDegC();

            if(temperature >=18 && temperature <=25 )
              {
                fan_set_speed(SPEED_LOW);
                sprintf(buffer1, "L");
              }
              else if(temperature >=26 && temperature <=30 )
              {
                fan_set_speed(SPEED_MEDIUM);
                sprintf(buffer1, "M");
              }
              else if(temperature > 30)
              {
                fan_set_speed(SPEED_HIGH);
                sprintf(buffer1, "H");
              }
              else if(temperature < 18)
              {
                fan_switch_off(); 
                sprintf(buffer1, "OFF");
              }

             sprintf(buffer, "%d'C                   %s", temperature, buffer1);

                if(((strcmp(temp_buffer,buffer1)) != 0)|(dummy_temperature != temperature ))    // Update display if there is any change in temperature
                {
                    strcpy(temp_buffer,buffer1);
                    dummy_temperature = temperature;
                    eink_epaper_2_9_296_128_fill_screen( EINK_EPAPER_2_9_296_128_COLOR_BLACK );
                    eink_epaper_2_9_296_128_text(buffer, 5, 175 );
                } 
        }
        
        else
        {
            //BlE Control Mode
            LED_Off();
            rnbd451_ble_tasks();
              
            if(!strcmp(ble_resp, "FAN_ON"))
            {        
               fan_switch_on();  
            }

            else if(!strcmp(ble_resp, "FAN_LOW"))
            {       
                fan_set_speed(SPEED_LOW);
            }

            else if(!strcmp(ble_resp, "FAN_MID"))
            {        
                fan_set_speed(SPEED_MEDIUM);
            }

            else if(!strcmp(ble_resp, "FAN_HIGH"))
            {       
                fan_set_speed(SPEED_HIGH);
            }

            else if(!strcmp(ble_resp, "FAN_OFF"))
            {
                fan_switch_off(); 
            }
            
            else if(!strcmp(ble_resp, "TEMP_MODE"))
            {          
                touch_count=0;
                rnbd451_init();
            }

            else
            {
                
            }
            
          }
        
    } 
    return ( EXIT_FAILURE );
}

/*******************************************************************************
 End of File
*/

