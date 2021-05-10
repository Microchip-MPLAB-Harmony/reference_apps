/*******************************************************************************
  I/O1 Xpro temperature tensor source file

  Company:
    Microchip Technology Inc.

  File Name:
    io1_xpro_temp_sens.c

  Summary:
    XPRO Adapter click routine implementation file.

  Description:
    This file defines the interface to the XPRO ADapter click using the I2C PLIB.
    This click routine gets the temperature.
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
//DOM-IGNORE-END

/**
  Section: Included Files
 */

#include "io1_xpro_temp_sens.h"
#include "definitions.h"

/**
  Section: Macro Declarations
 */

#define IO_XPRO_TEMP_SENSOR_SLAVE_ADDR                  0x004F
#define IO_XPRO_TEMP_SENSOR_REG_ADDR                    0x00

static uint8_t i2cWrData = IO_XPRO_TEMP_SENSOR_REG_ADDR;
static uint8_t i2cRdData[2] = {0};


static uint8_t convertTemperature(uint8_t* rawTempValue)
{
    int16_t temp;
    // Convert the temperature value read from sensor to readable format 
    // (Fahrenheit Celsius)
    // For demonstration purpose, temperature value is assumed to be 
    // positive.
    // The maximum positive temperature measured by sensor is +257 F
    temp = (rawTempValue[0] << 8) | rawTempValue[1];
    temp = (temp >> 7) * 0.5;
    temp = (temp * 9/5) + 32;
    return (uint8_t)temp;
}

uint8_t io1_xpro_get_temperature(void)
{
    uint8_t temperatureVal = 0;

    CLICK_XPRO_ADAPTER_I2C_WriteRead(IO_XPRO_TEMP_SENSOR_SLAVE_ADDR, &i2cWrData, 1, i2cRdData, 2);
    while(CLICK_XPRO_ADAPTER_I2C_IsBusy() == true);
    
    temperatureVal = convertTemperature(i2cRdData);
    return temperatureVal;
}
