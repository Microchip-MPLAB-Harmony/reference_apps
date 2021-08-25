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
// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stdio.h>
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <string.h>
#include "definitions.h"                // SYS function prototypes
#include "click_routines/click_interface.h"
#include "click_routines/weather/weather.h"
#include "click_routines/fan/fan.h"
#include "click_routines/eink_bundle/eink_bundle.h"
#include "click_routines/eink_bundle/eink_bundle_image.h"
#include "click_routines/eink_bundle/eink_bundle_font.h"
#include "ble/ble.h"

char BLE_Cmd_buf[100];
// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    int16_t temperature = 0;
    int16_t dummy_temperature = 0;
    char  buffer1[10], buffer[10];
    char temp_buffer[10];
    /* Initialize all modules */
    SYS_Initialize ( NULL );

    CLICK_FAN_TimerStart(); 
    CLICK_FAN_DelayMs(1000);
    fan_init();    
    fan_switch_off();
    CLICK_FAN_DelayMs(1000);

    eink_init();
    
    eink_set_font( guiFont_Tahoma_14_Regular, EINK_COLOR_BLACK, FO_HORIZONTAL);
    eink_image_bmp(mchp_logo_fan);
    
    DRV_BM71_Initialize();
    bleInitialize(true);
    strcpy(BLE_Cmd_buf, (char *)"TEMP_CTRL");

     while ( true )
    {
        DRV_BM71_Tasks();
        bleTasks(); 

        if(!strncmp(BLE_Cmd_buf, "TEMP_CTRL", 9))
        {
            Weather_readSensors();
            temperature =(int16_t)Weather_getTemperatureDegC();

            if(temperature >=18 && temperature <=25 )
              {
                fan_set_speed(SPEED_LOW);
                sprintf(buffer1, "    LOW");
              }
              else if(temperature >=26 && temperature <=30 )
              {
                fan_set_speed(SPEED_MEDIUM);
                sprintf(buffer1, "MEDIUM");
              }
              else if(temperature > 30)
              {
                fan_set_speed(SPEED_HIGH);
                sprintf(buffer1, "    HIGH");
              }
              else if(temperature < 18)
              {
                fan_switch_off(); 
                sprintf(buffer1, "OFF");
              }
             sprintf(buffer, "%d C",temperature);
             if(Isble_adv_started() == true){
                if(((strcmp(temp_buffer,buffer1)) != 0)|(dummy_temperature != temperature ))
                {
                    strcpy(temp_buffer,buffer1);
                    dummy_temperature = temperature;
                    eink_image_bmp(mchp_logo_fan);
                    eink_text(buffer,18,73 );
                    eink_text("Tempr =",0,55 );
                    eink_text(buffer1,0,145 );
                    CLICK_FAN_DelayMs(1000);
                }    
            }
        }
        else if(!strncmp(BLE_Cmd_buf, "BLE_CTRL", 8))
        {
            if(!strcmp((char *)&BLE_Cmd_buf[8 + 1], "FAN_ON"))
            {
                fan_switch_on();
                 sprintf(buffer1, "    ON");
            }
            else if(!strcmp((char *)&BLE_Cmd_buf[8 + 1], "FAN_LOW"))
            {
                fan_set_speed(SPEED_LOW);
                sprintf(buffer1, "    LOW");
            }
            else if(!strcmp((char *)&BLE_Cmd_buf[8 + 1], "FAN_MID"))
            {
                fan_set_speed(SPEED_MEDIUM);
                sprintf(buffer1, "MEDIUM");
            }
            else if(!strcmp((char *)&BLE_Cmd_buf[8 + 1], "FAN_HIGH"))
            {
                fan_set_speed(SPEED_HIGH);
                sprintf(buffer1, "    HIGH");
            }
            else if(!strcmp((char *)&BLE_Cmd_buf[8 + 1], "FAN_OFF"))
            {
                fan_switch_off(); 
                 sprintf(buffer1, "    OFF");
            }
            else
            {
                ;
            }
            memset(BLE_Cmd_buf, 0x00, 100);
            if((strcmp(temp_buffer,buffer1)) != 0)
            {
                strcpy(temp_buffer,buffer1);
                eink_image_bmp(mchp_logo_fan);
                eink_text(buffer1,0,145 );
            }
        }
        else
        {
            ;
        }
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

