/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <string.h>
#include <stdio.h>
#include"config/default/definitions.h"
#include "click_routines/weather/bme280.h"
#include "click_routines/click_interface.h"
#include "click_routines/eink_epaper_2_9_296_128/eink_epaper_2_9_296_128.h"
#include "click_routines/eink_epaper_2_9_296_128/eink_epaper_2_9_296_128_font.h"
#include "click_routines/eink_epaper_2_9_296_128/eink_epaper_2_9_296_128_image.h"
#include "click_routines/weather/weather.h"
#include "click_routines/fan/fan.h"
#include "app_ble.h"                                                 
/* ************************************************************************** */
/* ************************************************************************** */


int16_t temperature = 0;
int16_t dummy_temperature = 0;
char  buffer1[12], buffer[100];
char temp_buffer[10];


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */


/** 
  @Function
    void  APP_TEMP_Tasks(void) 

  @Summary
 In Temperature Control mode, based on the temperature value the speed of the DC fan is controlled and the temperature value and fan's speed will be displayed in the EINK paper display.

 */
void  APP_TEMP_Tasks(void) 
  {
  
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


/* *****************************************************************************
 End of File
 */
