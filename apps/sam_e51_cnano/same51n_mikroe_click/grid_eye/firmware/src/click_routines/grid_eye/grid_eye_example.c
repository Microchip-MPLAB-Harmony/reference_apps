/*******************************************************************************
  GRID EYE click routine example source file

  Company
    Microchip Technology Inc.

  File Name
    grid_eye_example.c

  Summary
    GRID EYE click routine example implementation file.

  Description
    This file defines the usage of the GRID EYE click routine APIs.

  Remarks:
    None.

 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*
    (c) 2022 Microchip Technology Inc. and its subsidiaries. You may use this
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

/**
  Section: Included Files
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "definitions.h"                // SYS function prototypes
#include "grid_eye.h"
#include "grid_eye_example.h"
#include "../click_interface.h"

static uint8_t grid_eye_temp_read_data[128] = {0};
static uint16_t grid_eye_table_64_temp_data[GRID_EYE_FRAMEBUFFER_SIZE/2] = {0};
static uint8_t grid_eye_buffer[10] = {0};
char grid_eye_matrix[GRID_EYE_SAMPLES_PER_COLUMN][GRID_EYE_SAMPLES_PER_ROW] = {'\0'};
static bool grid_eye_process_tatus = false;

// converts the grid array sensor data to temperature [in C]
static void GRID_EYE_Process_TempRawData(uint8_t* raw_data, uint16_t* temp_table_64_buffer)
{
    uint8_t index_raw_data, index_temp_table;
    index_temp_table = 0;

    for(index_raw_data = 0; index_raw_data < 64; index_raw_data++)
    {
        temp_table_64_buffer[index_raw_data] = ((uint16_t)raw_data[index_temp_table] + (((uint16_t)raw_data[index_temp_table+1]<<8) & 0x00FF));
        temp_table_64_buffer[index_raw_data] = temp_table_64_buffer[index_raw_data] * GRIDEYE_TEMP_COEF;

        index_temp_table = index_temp_table + 2 ;
    }

    grid_eye_process_tatus = true;
}

static void GRID_EYE_Example_Print(void)
{
    uint32_t x, y, index;
    uint8_t grid_eye_table_64_current_row_addr;

    index = GRID_EYE_TABLE_64_FIRST_SAMPLE_INDEX;
    grid_eye_table_64_current_row_addr = GRID_EYE_TABLE_64_FIRST_SAMPLE_INDEX;

    for(y = 0; y < GRID_EYE_SAMPLES_PER_COLUMN; y++)
    {
        for(x = 0; x < GRID_EYE_SAMPLES_PER_ROW; x++)
        {
            if(grid_eye_table_64_temp_data[index] > GRID_EYE_RED_COLOR_UPPER_LIMIT)
            {
                grid_eye_matrix[y][x] = 'R';    // Red | Above 30°C
            }
            else if((grid_eye_table_64_temp_data[index] < GRID_EYE_RED_COLOR_UPPER_LIMIT) && (grid_eye_table_64_temp_data[index] > GRID_EYE_ORANGE_COLOR_UPPER_LIMIT))
            {
                grid_eye_matrix[y][x] = 'O';    // Orange | 28°C - 30°C
            }
            else if((grid_eye_table_64_temp_data[index] < GRID_EYE_ORANGE_COLOR_UPPER_LIMIT) && (grid_eye_table_64_temp_data[index] > GRID_EYE_YELLOW_COLOR_UPPER_LIMIT))
            {
                grid_eye_matrix[y][x] = 'Y';    // Yellow | 26°C - 28°C
            }
            else if((grid_eye_table_64_temp_data[index] < GRID_EYE_YELLOW_COLOR_UPPER_LIMIT) && (grid_eye_table_64_temp_data[index] > GRID_EYE_BLUE_COLOR_UPPER_LIMIT))
            {
                grid_eye_matrix[y][x] = 'y';    // Light Yellow | 24°C - 26°C
            }
            else if((grid_eye_table_64_temp_data[index] < GRID_EYE_BLUE_COLOR_UPPER_LIMIT) && (grid_eye_table_64_temp_data[index] > GRID_EYE_GREEN_COLOR_UPPER_LIMIT))
            {
                grid_eye_matrix[y][x] = 'G';    // Green | 22°C - 24°C
            }
            else
            {
                grid_eye_matrix[y][x] = '|';    // No Color | Bellow 22°C
            }

            if((index - grid_eye_table_64_current_row_addr + 1) == (GRID_EYE_SAMPLES_PER_ROW))
            {
                index = grid_eye_table_64_current_row_addr - GRID_EYE_SAMPLES_PER_ROW;
                grid_eye_table_64_current_row_addr = index;
                index--;
            }

            index++;
        }
    }

    printf("\r\n");
    printf("--------------------------------------------------------------------\r\n");
    printf("Appropriate color decoding, depending on the temperature(T) detected\r\n");
    printf("--------------------------------------------------------------------\r\n");
    printf("R - Red          | T > 30C\r\n");
    printf("O - Orange       | T = 28C to 30C\r\n");
    printf("Y - Yellow       | T = 26C to 28C\r\n");
    printf("y - Light Yellow | T = 24C to 26C\r\n");
    printf("G - Green        | T = 22C to 24C\r\n");
    printf("| - No Color     | T < 22C\r\n");
    printf("--------------------------------------------------------------------\r\n");
    printf("GRID EYE Click (8x8) array values:\r\n");
    printf("--------------------------------------------------------------------\r\n");

    for (y = 0; y < GRID_EYE_SAMPLES_PER_COLUMN; y++)
    {
        for (x = 0; x < GRID_EYE_SAMPLES_PER_ROW; x++)
        {
           printf("%c ", grid_eye_matrix[y][x]);
        }
        printf(" \r\n");
    }
}

static void GRID_EYE_Example_Tasks(void)
{
    // Grid-EYE click initialization
    GRID_EYE_SensorInit();

    grid_eye_buffer[0] = GRID_EYE_TEMP_REG;
    GRID_EYE_WriteRead(GRID_EYE_SLAVE_ADDRESS, &grid_eye_buffer[0], GRID_EYE_TRANSFER_SIZE, &grid_eye_temp_read_data[0], GRID_EYE_FRAMEBUFFER_SIZE);

    if (GRID_EYE_GetWriteReadStatus() == true)
    {
        GRID_EYE_SetWriteReadStatus(false);
        GRID_EYE_Process_TempRawData(grid_eye_temp_read_data, grid_eye_table_64_temp_data);
    }
}

void GRID_EYE_Example(void)
{
    GRID_EYE_Example_Tasks();

    // Print the processed Grid-EYE values
    if (grid_eye_process_tatus == true)
    {
        GRID_EYE_Example_Print();
        grid_eye_process_tatus = false;
    }

    CLICK_GRID_EYE_SYSTICK_DelayMs(500);
}
