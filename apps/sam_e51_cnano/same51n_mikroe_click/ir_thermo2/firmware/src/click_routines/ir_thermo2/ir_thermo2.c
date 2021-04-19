/*******************************************************************************
  IR Thermo 2 click routine source file

  Company
    Microchip Technology Inc.

  File Name
    ir_thermo2.c

  Summary
    IR Thermo 2 click routine Implementation File.

  Description
    This file defines the interface to the IR Thermo 2 click using I2C PLIB.
    This click routine provides to read the sensor data on IR Thermo 2 click.

  Remarks:
    None.
 
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

/**
  Section: Included Files
 */

#include <string.h>
#include "definitions.h"                // SYS function prototypes
#include "../click_interface.h"
#include "ir_thermo2.h"

/**
  Section: Macro Declarations
 */
#define TMP007_I2C_ADDR                 0x40            // TMP007 I2C address (ADD0 and ADD1 pins are connected to ground)

/**
  Section: Variable Definitions
 */

/**
  Section: Private function prototypes
 */

/**
  Section: Driver APIs
 */
/*******************************************************************************
* Function ir_thermo2_Get_Object_Temperature()
* ------------------------------------------------------------------------------
* Overview: Function gets temperature data from TMP007 sensor
* Input: Nothing
* Output: Temperature data
*******************************************************************************/
float ir_thermo2_Get_Object_Temperature(void)
{
    int     TemperatureSum;
    float   Temperature     = 0;
    uint8_t data_out[2];
    uint8_t registerAddr    = 0x03;

    while (CLICK_IR_THERMO2_I2C_IsBusy() == true);
    if(CLICK_IR_THERMO2_I2C_WriteRead(TMP007_I2C_ADDR, &registerAddr, 1,  (uint8_t *)data_out, 2) == true)
    {
        /* Wait for the I2C transfer to complete */
        while (CLICK_IR_THERMO2_I2C_IsBusy() == true);

        /* Transfer complete. Check if the transfer was successful */
        if (CLICK_IR_THERMO2_I2C_ErrorGet() == SERCOM_I2C_ERROR_NONE) 
        {
            TemperatureSum = ((data_out[0] << 8) | data_out[1]) >> 2;  // Justify temperature values

            if(TemperatureSum & (1 << 13))
            {
                TemperatureSum = TemperatureSum | ~((1 << 14) - 1); 
            }
            Temperature = (float)TemperatureSum * 0.03125;          // Multiply temperature value with 0.03125 (value per bit)            
        }                      
    }

    return Temperature;                                             // Return temperature data
}
