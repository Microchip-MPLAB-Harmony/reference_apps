/*******************************************************************************
  Thumbstick click source file

  Company:
    Microchip Technology Inc.

  File Name:
    thumbstick.c

  Summary:
    Thumbstick click routine implementation file.

  Description:
    This file defines the interface to the Thumbstick click using the SPI PLIB.
    This click routine gets the final direction of the X and Y axis of the
    Thumbstick.
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

#include "definitions.h"                // SYS function prototypes
#include "../click_interface.h"
#include "thumbstick.h"


#define byte_1                          0b00000110
#define channel_0                       0x00000000
#define channel_1                       0b01000000
#define byte_3                          0x00000000

struct Thumbstick
{
    uint8_t cmd[3];
    uint8_t RxBuffer[3];

    uint16_t X_raw_value;
    uint16_t Y_raw_value;

    float X_voltage_value;
    float Y_voltage_value;

    uint8_t final_direction;
};

static uint16_t Thumbstick_GetXRawValue();
static uint16_t Thumbstick_GetYRawValue();

struct Thumbstick thumbstick;

// Calculate the X-axis raw value
static uint16_t Thumbstick_GetXRawValue()
{
    thumbstick.X_raw_value = 0;
    thumbstick.X_raw_value = (uint16_t)thumbstick.RxBuffer[1];
    thumbstick.X_raw_value = (uint16_t)((thumbstick.X_raw_value<<12));
    thumbstick.X_raw_value = (uint16_t)(thumbstick.X_raw_value>>4);
    thumbstick.X_raw_value = (uint16_t)(thumbstick.X_raw_value | ((uint16_t)thumbstick.RxBuffer[2]));

    return thumbstick.X_raw_value;
}

// Calculate the Y-axis raw value
static uint16_t Thumbstick_GetYRawValue()
{
    thumbstick.Y_raw_value = 0;
    thumbstick.Y_raw_value = (uint16_t)thumbstick.RxBuffer[1];
    thumbstick.Y_raw_value = (uint16_t)((thumbstick.Y_raw_value<<12));
    thumbstick.Y_raw_value = (uint16_t)(thumbstick.Y_raw_value>>4);
    thumbstick.Y_raw_value = (uint16_t)(thumbstick.Y_raw_value | ((uint16_t)thumbstick.RxBuffer[2]));

    return thumbstick.Y_raw_value;
}

void Thumbstick_Initialize(void)
{
   CLICK_THUMBSTICK_CS_Set();
   thumbstick.final_direction = DEFAULT_POSITION;

   CLICK_THUMBSTICK_TimerStart();
}

uint8_t Thumbstick_GetFinalDirection(void)
{
    // Get the X-axis sample first
    thumbstick.cmd[0] = byte_1;
    thumbstick.cmd[1] = channel_1;
    thumbstick.cmd[2] = byte_3;

    CLICK_THUMBSTICK_CS_Clear();
    CLICK_THUMBSTICK_SPI_WriteRead(thumbstick.cmd,3,thumbstick.RxBuffer, 3);

    while(CLICK_THUMBSTICK_SPI_IsBusy() == true)
    {
        ;
    }

    CLICK_THUMBSTICK_CS_Set();

    // Calculate the X-axis voltage
    thumbstick.X_voltage_value = (float)(((float)Thumbstick_GetXRawValue() * 3.3)/4096);

    // Identify the direction
    if(thumbstick.X_voltage_value  >= 3.0)
    {
        thumbstick.final_direction = LEFT;

    }else if(thumbstick.X_voltage_value  <= 0.5)
    {
        thumbstick.final_direction = RIGHT;
    }
    // Get the Y-axis sample
    else
    {
        thumbstick.cmd[0] = byte_1;
        thumbstick.cmd[1] = channel_0;
        thumbstick.cmd[2] = byte_3;

        CLICK_THUMBSTICK_CS_Clear();
        CLICK_THUMBSTICK_SPI_WriteRead(thumbstick.cmd,3,thumbstick.RxBuffer, 3);

        while(CLICK_THUMBSTICK_SPI_IsBusy() == true)
        {
            ;
        }

        CLICK_THUMBSTICK_CS_Set();

        // Calculate the Y-axis voltage
        thumbstick.Y_voltage_value = (float)(((float)Thumbstick_GetYRawValue() * 3.3)/4096);

        // Identify the direction
        if(thumbstick.Y_voltage_value  >= 3.0)
        {
            thumbstick.final_direction = UP;

        }else if(thumbstick.Y_voltage_value  <= 0.3)
        {
            thumbstick.final_direction = DOWN;

        }
        else
        {
            /* Default position. i.e.,
             * X_AXIS_DEFAULT_VOLTAGE_VALUE                 1.56
             * Y_AXIS_DEFAULT_VOLTAGE_VALUE                 1.79
             */
            thumbstick.final_direction = DEFAULT_POSITION;
        }
    }
    return thumbstick.final_direction;
}