/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
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

#include "app.h"
#include "config/default/definitions.h"
#include "click_routines/oled_c/oled_c.h"
#include "click_routines/grid_eye/grid_eye.h"
#include "click_routines/click_interface.h"
#include "start_screen.h"

APP_DATA appData;

static uint8_t thermal_camera_temp_read_data[128] = {0};
static uint16_t thermal_camera_table_64_temp_data[GRID_EYE_FRAMEBUFFER_SIZE/2] = {0};
static uint8_t thermal_camera_buffer[10] = {0};
char thermal_camera_matrix[GRID_EYE_SAMPLES_PER_COLUMN][GRID_EYE_SAMPLES_PER_ROW] = {'\0'};
static bool thermal_camera_process_tatus = false;

// converts the grid array sensor data to temperature [in C]
static void Thermal_Camera_Process_TempRawData(uint8_t* raw_data, uint16_t* temp_table_64_buffer)
{
    uint8_t index_raw_data, index_temp_table;
    index_temp_table = 0;

    for(index_raw_data = 0; index_raw_data < 64; index_raw_data++)
    {
        temp_table_64_buffer[index_raw_data] = ((uint16_t)raw_data[index_temp_table] + (((uint16_t)raw_data[index_temp_table+1]<<8) & 0x00FF));
        temp_table_64_buffer[index_raw_data] = temp_table_64_buffer[index_raw_data] * THERMAL_CAMERA_TEMP_COEF;

        index_temp_table = index_temp_table + 2 ;
    }

    thermal_camera_process_tatus = true;
}

static void Thermal_Camera_Display_draw_data()
{
    leRect rect_temp, rect_fill;
    uint32_t x,y,index,color;
    uint8_t thermal_camera_table_64_current_row_addr;

    //Fill the all screen white yellow to eliminate the black rectangles

    rect_fill.height = 96;
    rect_fill.width =  96;
    rect_fill.x = 0;
    rect_fill.y = 0;

    leRenderer_RectFill(&rect_fill,LIGHT_YELLOW_COLOR,ALPHA_BLENDING_VALUE);

    color = BLUE;

    index = THERMAL_CAMERA_TABLE_64_FIRST_SAMPLE_INDEX;
    thermal_camera_table_64_current_row_addr = THERMAL_CAMERA_TABLE_64_FIRST_SAMPLE_INDEX;

    rect_temp.height = THERMAL_CAMERA_TEMP_RECTANGLE_SIZE;
    rect_temp.width =  THERMAL_CAMERA_TEMP_RECTANGLE_SIZE;

    for(y = 0; y<GRID_EYE_SAMPLES_PER_COLUMN; y++)
    {
        for(x = 0; x<GRID_EYE_SAMPLES_PER_ROW; x++)
        {
            rect_temp.x = x*THERMAL_CAMERA_TEMP_RECTANGLE_SIZE + DISPLAY_TABLE_X_START_POS;
            rect_temp.y = y*THERMAL_CAMERA_TEMP_RECTANGLE_SIZE + DISPLAY_TABLE_Y_START_POS;

            if(thermal_camera_table_64_temp_data[index] > GRID_EYE_RED_COLOR_UPPER_LIMIT)
            {
              color = RED;

            }else if((thermal_camera_table_64_temp_data[index] < GRID_EYE_RED_COLOR_UPPER_LIMIT)&&(thermal_camera_table_64_temp_data[index] > GRID_EYE_ORANGE_COLOR_UPPER_LIMIT))
            {
              color = ORANGE;

            }else if((thermal_camera_table_64_temp_data[index] < GRID_EYE_ORANGE_COLOR_UPPER_LIMIT)&&(thermal_camera_table_64_temp_data[index] > GRID_EYE_YELLOW_COLOR_UPPER_LIMIT))
            {
              color = YELLOW;

            }else if((thermal_camera_table_64_temp_data[index] < GRID_EYE_YELLOW_COLOR_UPPER_LIMIT)&&(thermal_camera_table_64_temp_data[index] > GRID_EYE_BLUE_COLOR_UPPER_LIMIT))
            {
                color = LIGHT_YELLOW;

            }else if((thermal_camera_table_64_temp_data[index] < GRID_EYE_BLUE_COLOR_UPPER_LIMIT)&&(thermal_camera_table_64_temp_data[index] > GRID_EYE_GREEN_COLOR_UPPER_LIMIT))
            {
                color = GREEN;
            }

            switch(color)
            {
                case LIGHT_YELLOW:
                {
                    leRenderer_RectFill(&rect_temp,LIGHT_YELLOW_COLOR,ALPHA_BLENDING_VALUE);
                    break;
                }

                case RED:
                {
                    leRenderer_RectFill(&rect_temp,RED_COLOR,ALPHA_BLENDING_VALUE);
                    break;
                }

                case ORANGE:
                {
                    leRenderer_RectFill(&rect_temp,ORANGE_COLOR,ALPHA_BLENDING_VALUE);
                    break;
                }

                case YELLOW:
                {
                    leRenderer_RectFill(&rect_temp,YELLOW_COLOR,ALPHA_BLENDING_VALUE);
                    break;
                }

                case GREEN:
                {
                    leRenderer_RectFill(&rect_temp,GREEN_COLOR,ALPHA_BLENDING_VALUE);
                    break;
                }
            }

            if((index - thermal_camera_table_64_current_row_addr + 1) == (GRID_EYE_SAMPLES_PER_ROW))
            {
                index = thermal_camera_table_64_current_row_addr - GRID_EYE_SAMPLES_PER_ROW;
                thermal_camera_table_64_current_row_addr = index;
                index--;
            }

            index++;
        }
    }
}

static void Thermal_Camera_Sensor_task(void)
{
    // Grid-EYE click initialization
    GRID_EYE_SensorInit();

    thermal_camera_buffer[0] = GRID_EYE_TEMP_REG;
    GRID_EYE_WriteRead(GRID_EYE_SLAVE_ADDRESS, &thermal_camera_buffer[0], GRID_EYE_TRANSFER_SIZE, &thermal_camera_temp_read_data[0], GRID_EYE_FRAMEBUFFER_SIZE);

    if (GRID_EYE_GetWriteReadStatus() == true)
    {
        GRID_EYE_SetWriteReadStatus(false);
        Thermal_Camera_Process_TempRawData(thermal_camera_temp_read_data, thermal_camera_table_64_temp_data);
    }
}


leBool event_Screen0_DrawSurfaceWidget0_OnDraw(leDrawSurfaceWidget* sfc, leRect* bounds)
{
    Thermal_Camera_Display_draw_data();

    return 1;
}

void Thermal_Camera_Display_task()
{
    if(thermal_camera_process_tatus == true)
    {
        THERMAL_CAMERA_DRAW_SURFACE->fn->invalidate(THERMAL_CAMERA_DRAW_SURFACE);
    }
}

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */
void APP_Initialize ( void )
{
    oled_c_initialize();

    /* Place the App state machine in its initial state. */
    appData.state = THERMAL_CAMERA_INIT;

    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
    // OLED_C Click Display Refresh
    oled_c_dispaly_referesh();

    switch ( appData.state )
    {
        case THERMAL_CAMERA_INIT:
        {
            if(START_SCREEN_Task() == START_SCREEN_TASK_DONE)
            {
              appData.state = THERMAL_CAMERA_SENSOR_INIT;
            }

            break;
        }

        case THERMAL_CAMERA_SENSOR_INIT:
        {
            GRID_EYE_SensorInit();

            appData.state = THERMAL_CAMERA_DISPLAY_TASK;

            break;
        }

        case THERMAL_CAMERA_DISPLAY_TASK:
        {
            Thermal_Camera_Sensor_task();

            Thermal_Camera_Display_task();

            break;
        }

        default:
        {

            break;
        }
    }
}

/*******************************************************************************
 End of File
 */
