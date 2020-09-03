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

#include <stdio.h>
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <string.h>
#include "definitions.h"                // SYS function prototypes

#define TEMP_SENSOR_SLAVE_ADDR                  0x004B
#define TEMP_SENSOR_REG_ADDR                    0x00

#define EEPROM_I2C_SLAVE_ADDR                   0x0050
#define EEPROM_LOG_MEMORY_ADDR                  0x00
#define EEPROM_MAX_LOG_VALUES                   5

/* RTC Time period match values for input clock of 1 KHz */
#define PERIOD_500MS                            512
#define PERIOD_1S                               1024
#define PERIOD_2S                               2048
#define PERIOD_4S                               4096

/* typedef for non-secure callback functions */
typedef void (*funcptr_void) (void) __attribute__((cmse_nonsecure_call));

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
static volatile bool isRTCTimerExpired = false;
static volatile bool changeTempSamplingRate = false;
static volatile bool isI2CFree = true;
static volatile bool isTemperatureRead = false;
static volatile bool isEEPROMReadReq = false;

       volatile bool isEEPROMRead = false;
       volatile bool temperatureStatus = false;
       volatile bool eepromTemperatureDataReadStatus = false;
       uint8_t wrIndex  = 0;
       uint8_t temperatureVal;
static uint8_t i2cAddress;
static uint8_t i2cWrData = TEMP_SENSOR_REG_ADDR;
static uint8_t i2cRdData[2] = {0};
static uint8_t eepromTxBuffer[2] = {0};
       uint8_t *eepromRxBuffer;
       uint8_t secureUartTxBuffer[100] = {0};
typedef enum
{
    TEMP_SAMPLING_RATE_500MS = 0,
    TEMP_SAMPLING_RATE_1S = 1,
    TEMP_SAMPLING_RATE_2S = 2,
    TEMP_SAMPLING_RATE_4S = 3,
} TEMP_SAMPLING_RATE;
static TEMP_SAMPLING_RATE tempSampleRate = TEMP_SAMPLING_RATE_500MS;

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************
/******************************************************************************
  Function:
    void _EEPROM_Write ( int8_t temperature )

  Remarks:
    This function writes temperature value to EEPROM and polls the status of
    EEPROM until its internal write cycle is complete.
 */
 static void EEPROM_Write(int8_t temperature)
 {
    eepromTxBuffer[0] = EEPROM_LOG_MEMORY_ADDR + wrIndex;
    eepromTxBuffer[1] = temperature;

    /* Submit I2C transfer to store the temperature value in EEPROM */
    SERCOM1_I2C_Write(EEPROM_I2C_SLAVE_ADDR, (void *)eepromTxBuffer, 2);


    /* Increment the EEPROM memory index */
    if (++wrIndex >= EEPROM_MAX_LOG_VALUES)
    {
        wrIndex = 0;
    }
}

static void EIC_User_Handler(uintptr_t context)
{
    changeTempSamplingRate = true;      
}

static void rtcEventHandler (RTC_TIMER32_INT_MASK intCause, uintptr_t context)
{
    if (intCause & RTC_TIMER32_INT_MASK_CMP0)
    {            
        isRTCTimerExpired = true;                              
    }
}

static void i2cEventHandler(uintptr_t contextHandle)
{
    if (SERCOM1_I2C_ErrorGet() == SERCOM_I2C_ERROR_NONE)
    {
        if(i2cAddress == TEMP_SENSOR_SLAVE_ADDR)
        {
            isTemperatureRead       = true;
        }
        else if(isEEPROMReadReq == true)
        {
            isEEPROMReadReq         = false;
            eepromTemperatureDataReadStatus  = true;
        }
        isI2CFree                   = true;
    }
}

static uint8_t getTemperature(uint8_t* rawTempValue)
{
    int16_t temp;
    // Convert the temperature value read from sensor to readable format (Degree Celsius)
    // For demonstration purpose, temperature value is assumed to be positive.
    // The maximum positive temperature measured by sensor is +125 C
    temp = (rawTempValue[0] << 8) | rawTempValue[1];
    temp = (temp >> 7) * 0.5;
    temp = (temp * 9/5) + 32;
    return (uint8_t)temp;
}

void secureApp(void)
{
    if ((isI2CFree == true) && 
        (isRTCTimerExpired == true))  //Temperature Reading from Sensor
    {
        isRTCTimerExpired = false;
        isI2CFree = false;
        i2cAddress = TEMP_SENSOR_SLAVE_ADDR;
        SERCOM1_I2C_WriteRead(TEMP_SENSOR_SLAVE_ADDR, &i2cWrData, 1, i2cRdData, 2);
    }
    if ((isI2CFree == true) && 
        (isTemperatureRead == true))
    {
        isTemperatureRead = false;
        if(changeTempSamplingRate == false)    
        {
            temperatureVal = getTemperature(i2cRdData);
            memset((char*)secureUartTxBuffer, 0x00, 100);
            sprintf((char*)secureUartTxBuffer, "Temperature = %02d F\r\n", temperatureVal);
            LED_Toggle();
        // Temperature Writing to EEPROM
            i2cAddress = EEPROM_I2C_SLAVE_ADDR;
            isI2CFree = false;
            EEPROM_Write(temperatureVal);
        }
        else
        {
            changeTempSamplingRate = false;
            if(tempSampleRate == TEMP_SAMPLING_RATE_500MS)
            {
                tempSampleRate = TEMP_SAMPLING_RATE_1S;
                sprintf((char*)secureUartTxBuffer, "Sampling Temperature every 1 second \r\n");
                RTC_Timer32CompareSet(PERIOD_1S);
            }
            else if(tempSampleRate == TEMP_SAMPLING_RATE_1S)
            {
                tempSampleRate = TEMP_SAMPLING_RATE_2S;
                sprintf((char*)secureUartTxBuffer, "Sampling Temperature every 2 seconds \r\n");        
                RTC_Timer32CompareSet(PERIOD_2S);                        
            }
            else if(tempSampleRate == TEMP_SAMPLING_RATE_2S)
            {
                tempSampleRate = TEMP_SAMPLING_RATE_4S;
                sprintf((char*)secureUartTxBuffer, "Sampling Temperature every 4 seconds \r\n");        
                RTC_Timer32CompareSet(PERIOD_4S);                                        
            }    
            else if(tempSampleRate == TEMP_SAMPLING_RATE_4S)
            {
               tempSampleRate = TEMP_SAMPLING_RATE_500MS;
               sprintf((char*)secureUartTxBuffer, "Sampling Temperature every 500 ms \r\n");        
               RTC_Timer32CompareSet(PERIOD_500MS);
            }
            else
            {
                ;
            }
        }
        temperatureStatus = true;
    }
    if ((isI2CFree == true) && 
        (isEEPROMRead == true))       //Temperature Reading from EEPROM
    {
        isI2CFree           = false;
        isEEPROMRead        = false;
        isEEPROMReadReq     = true;
        i2cAddress          = EEPROM_I2C_SLAVE_ADDR;
        eepromTxBuffer[0]   = EEPROM_LOG_MEMORY_ADDR;
        SERCOM1_I2C_WriteRead(EEPROM_I2C_SLAVE_ADDR, eepromTxBuffer, 1, eepromRxBuffer, 6);
    }
}

int main ( void )
{
    uint32_t msp_ns = *((uint32_t *)(TZ_START_NS));
    volatile funcptr_void NonSecure_ResetHandler;

    /* Initialize all modules */
    SYS_Initialize ( NULL );

    SERCOM1_I2C_CallbackRegister(i2cEventHandler, 0);
    RTC_Timer32CallbackRegister(rtcEventHandler, 0);
    EIC_CallbackRegister(EIC_PIN_5,EIC_User_Handler, 0);

    RTC_Timer32Start();
    if (msp_ns != 0xFFFFFFFF)
    {
        /* Set non-secure main stack (MSP_NS) */
        __TZ_set_MSP_NS(msp_ns);

        /* Get non-secure reset handler */
        NonSecure_ResetHandler = (funcptr_void)(*((uint32_t *)((TZ_START_NS) + 4U)));

        /* Start non-secure state software application */
        NonSecure_ResetHandler();
    }

    while ( true )
    {
        secureApp();
    }
    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

