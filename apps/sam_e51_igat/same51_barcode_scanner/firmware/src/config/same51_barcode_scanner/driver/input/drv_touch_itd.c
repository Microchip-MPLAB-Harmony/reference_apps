// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END


/*******************************************************************************
 Input driver for the Integrated Touch Library

  File Name:
    drv_touch_itd.c

  Summary:
    Input driver for the integrated touch library.

  Description:
    This file consist the input driver implementation for the integrated touch
    controller library. This driver fetches the touch input information from the touch
    library and sends the input events to the input system service.
 ******************************************************************************/


#include "definitions.h"
#include "drv_touch_itd.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#if (ITD_SURFACE_CS_RESOLUTION_BITS == 12)
#define MAX_POS_VALUE 4095
#elif (ITD_SURFACE_CS_RESOLUTION_BITS == 10)
#define MAX_POS_VALUE 1023
#elif (ITD_SURFACE_CS_RESOLUTION_BITS == 8)
#define MAX_POS_VALUE 255
#else
#error "Invalid CS resolution"
#endif

#define DRV_TOUCH_PRINTF(...) //printf(__VA_ARGS__)

typedef struct 
{
    int xpos;
    int ypos;
    int xpos_initial;
    int ypos_initial;    
    DRV_TOUCH_ITD_TOUCH_STATE touch_state;
    DRV_TOUCH_ITD_STATE drv_state;
} DRV_TOUCH_ITD_OBJ;

DRV_TOUCH_ITD_OBJ drv_touch_itd_obj[TOUCH_POINTS_COUNT];

extern qtm_surface_cs_control_t qtm_surface_cs_control1;

extern volatile uint8_t time_to_measure_touch_var;
extern volatile uint8_t measurement_done_touch;

//Wrapper function that returns true if there is an active touch input
static inline bool drv_touch_itd_get_surface_active_status(unsigned int id)
{
    return qtm_surface_cs_control1.qtm_surface_contact_data[id].qt_surface_status & TOUCH_ACTIVE;
}

static inline uint8_t drv_touch_itd_get_surface_data_x_value(unsigned int id)
{
    return qtm_surface_cs_control1.qtm_surface_contact_data[id].h_position;
}

static inline uint8_t drv_touch_itd_get_surface_data_y_value(unsigned int id)
{
    return (MAX_POS_VALUE - qtm_surface_cs_control1.qtm_surface_contact_data[id].v_position);
}


void drv_touch_itd_init (void)
{
    unsigned int i = 0;
    
    for (i = 0; i < TOUCH_POINTS_COUNT; i++)
    {
        drv_touch_itd_obj[i].drv_state = DRV_TOUCH_ITD_INIT;
        drv_touch_itd_obj[i].touch_state = DRV_TOUCH_ITD_TOUCH_RELEASED;
        drv_touch_itd_obj[i].xpos = 0;
        drv_touch_itd_obj[i].ypos = 0;
        drv_touch_itd_obj[i].xpos_initial = 0;
        drv_touch_itd_obj[i].ypos_initial = 0;
    }
}

static void drv_touch_itd_subtask (unsigned int id)
{
    switch (drv_touch_itd_obj[id].drv_state)
    {
        case DRV_TOUCH_ITD_INIT:
        {
            drv_touch_itd_obj[id].drv_state = DRV_TOUCH_ITD_CHECK;
            break;
        }
        case DRV_TOUCH_ITD_CHECK:
        {
            touch_process();
            
            if (drv_touch_itd_get_surface_active_status(id) != 0)
            {
                drv_touch_itd_obj[id].drv_state = DRV_TOUCH_ITD_PROCESS;
            }
            else if (drv_touch_itd_obj[id].touch_state == DRV_TOUCH_ITD_TOUCH_PRESSED)
            {
                    drv_touch_itd_obj[id].touch_state = DRV_TOUCH_ITD_TOUCH_RELEASED;
                    DRV_TOUCH_PRINTF("%d) UP (%d, %d) \n\r", id, drv_touch_itd_obj[id].xpos, drv_touch_itd_obj[id].ypos);
                    SYS_INP_InjectTouchUp(id,
                                          drv_touch_itd_obj[id].xpos,
                                          drv_touch_itd_obj[id].ypos);
            }
            break;
        }
        case DRV_TOUCH_ITD_PROCESS:
        {
            int x, y, delta;
            
            x = drv_touch_itd_get_surface_data_x_value(id);
            y = drv_touch_itd_get_surface_data_y_value(id);
            
            delta = x - (MAX_POS_VALUE/2);
            delta = (delta * TOUCH_SCREEN_ACTIVE_WIDTH)/MAX_POS_VALUE;
            x = TOUCH_SCREEN_ACTIVE_WIDTH/2 + delta; 

            delta = y - (MAX_POS_VALUE/2);
            delta = (delta * TOUCH_SCREEN_ACTIVE_HEIGHT)/MAX_POS_VALUE;
            y = TOUCH_SCREEN_ACTIVE_HEIGHT/2 + delta;

            if (drv_touch_itd_obj[id].touch_state == DRV_TOUCH_ITD_TOUCH_PRESSED)
            {
                //check if moved
                if ((x != drv_touch_itd_obj[id].xpos) ||
                    (y != drv_touch_itd_obj[id].ypos))
                {
                    drv_touch_itd_obj[id].xpos = x;
                    drv_touch_itd_obj[id].ypos = y;

                    DRV_TOUCH_PRINTF("%d) MOVE (%d, %d) \n\r", id, drv_touch_itd_obj[id].xpos, drv_touch_itd_obj[id].ypos);
                    SYS_INP_InjectTouchMove(id,
                                            drv_touch_itd_obj[id].xpos,
                                            drv_touch_itd_obj[id].ypos);
                }
            }
            else if (drv_touch_itd_obj[id].touch_state == DRV_TOUCH_ITD_TOUCH_RELEASED)
            {            
                drv_touch_itd_obj[id].touch_state = DRV_TOUCH_ITD_TOUCH_PRESSED;

                drv_touch_itd_obj[id].xpos_initial = x;
                drv_touch_itd_obj[id].ypos_initial = y;                
                drv_touch_itd_obj[id].xpos = x;
                drv_touch_itd_obj[id].ypos = y;
                
                DRV_TOUCH_PRINTF("%d) DOWN (%d, %d) \n\r", id, drv_touch_itd_obj[id].xpos, drv_touch_itd_obj[id].ypos);
                SYS_INP_InjectTouchDown(id,
                                        drv_touch_itd_obj[id].xpos,
                                        drv_touch_itd_obj[id].ypos);
            }
            
            drv_touch_itd_obj[id].drv_state = DRV_TOUCH_ITD_CHECK;
            
            break;
        }
            
        default:
            break;
    }
}

void drv_touch_itd_task (void)
{
    drv_touch_itd_subtask(ITD_TOUCH_ID);
}