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
* Copyright (C) 2024 Microchip Technology Inc. and its subsidiaries.
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

#define TEMP_SENSOR_SLAVE_ADDR                  0x004F
#define TEMP_SENSOR_REG_ADDR                    0x00
#define EEPROM_I2C_SLAVE_ADDR                   0x0057
#define EEPROM_LOG_MEMORY_ADDR                  0x00
#define EEPROM_MAX_LOG_VALUES                   5
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
static volatile bool changeSamplingRate = false;
static volatile bool isI2CFree = true;
static volatile bool isTemperatureRead = false;
static volatile bool isEEPROMReadReq = false;
static volatile bool printLedToggleRate = false;
static volatile bool printTempSampleRate = false;
static uint8_t i2cAddress;
static uint8_t i2cWrData = TEMP_SENSOR_REG_ADDR;
static uint8_t i2cRdData[2] = {0};
static uint8_t eepromTxBuffer[2] = {0};
static const char timeouts[4][20] = {"500 milliSeconds", "1 Second",  "2 Seconds",  "4 Seconds"};

volatile bool startTemperatureReading = false;
volatile bool isEEPROMRead = false;
volatile bool readUartTxStatus = false;
volatile bool eepromTemperatureDataReadStatus = false;

uint8_t wrIndex  = 0;
uint8_t temperatureVal;
uint8_t *eepromRxBuffer;
uint8_t uartTxTempBuffer[100] = {0};
bool showErrorMsg = false;

typedef enum
{
    SAMPLING_RATE_500MS = 0,
    SAMPLING_RATE_1S    = 1,
    SAMPLING_RATE_2S    = 2,
    SAMPLING_RATE_4S    = 3,
} SAMPLING_RATE;

static SAMPLING_RATE tempSampleRate = SAMPLING_RATE_500MS;

static void eepromWrite(int8_t temperature)
{
   eepromTxBuffer[0] = EEPROM_LOG_MEMORY_ADDR + wrIndex;
   eepromTxBuffer[1] = temperature;
   SERCOM4_I2C_Write(EEPROM_I2C_SLAVE_ADDR, (void *)eepromTxBuffer, 2);
   if (++wrIndex >= EEPROM_MAX_LOG_VALUES)
   {
       wrIndex = 0;
   }
}

static void SW0_eventHandler(uintptr_t context)
{
    changeSamplingRate = true;
}

static void SW1_eventHandler(uintptr_t context)
{
    if(false == startTemperatureReading)
    {
        startTemperatureReading = true;
        printTempSampleRate = true;
    }
    else
    {
        startTemperatureReading = false;
        printLedToggleRate = true;
    }
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
    if (SERCOM4_I2C_ErrorGet() == SERCOM_I2C_ERROR_NONE)
    {
        if(i2cAddress == TEMP_SENSOR_SLAVE_ADDR)
        {
            isTemperatureRead = true;
        }
        else if(isEEPROMReadReq == true)
        {
            isEEPROMReadReq = false;
            eepromTemperatureDataReadStatus  = true;
        }
        isI2CFree = true;
    }
    else if (SERCOM4_I2C_ErrorGet() == SERCOM_I2C_ERROR_NAK ||
             SERCOM4_I2C_ErrorGet() == SERCOM_I2C_ERROR_BUS)
    {
        showErrorMsg = true;
    }
}

static uint8_t getTemperature(uint8_t* rawTempValue)
{
    int16_t temp;
    temp = (rawTempValue[0] << 8) | rawTempValue[1];
    temp = (temp >> 7) * 0.5;
    temp = (temp * 9/5) + 32;
    return (uint8_t)temp;
}

void secureApp(void)
{
    /* Basic Functionality: Demonstrates an LED toggle, i.e. LED0 toggles when
     * the SWitch SW0 is pressed on a timeout basis and prints the LED toggling
     * rate on the serial terminal.*/
    if (startTemperatureReading == false)
    {
        if (printLedToggleRate == true)
        {
            memset((char*)uartTxTempBuffer, 0x00, 100);
            sprintf((char*)uartTxTempBuffer, "************* Printing Toggling LED rate *************\r\n");
            printLedToggleRate = false;
            readUartTxStatus = true;
        }
        if (isRTCTimerExpired == true)
        {
            isRTCTimerExpired = false;
            memset((char*)uartTxTempBuffer, 0x00, 100);
            sprintf((char*)uartTxTempBuffer, "Toggling LED at %s rate \r\n", &timeouts[(uint8_t)tempSampleRate][0]);
            LED0_Toggle();
            readUartTxStatus = true;
        }
        if(changeSamplingRate == true)
        {
            changeSamplingRate = false;
            if(tempSampleRate == SAMPLING_RATE_500MS)
            {
                tempSampleRate = SAMPLING_RATE_1S;
                RTC_Timer32Compare0Set(PERIOD_1S);
            }
            else if(tempSampleRate == SAMPLING_RATE_1S)
            {
                tempSampleRate = SAMPLING_RATE_2S;
                RTC_Timer32Compare0Set(PERIOD_2S);
            }
            else if(tempSampleRate == SAMPLING_RATE_2S)
            {
                tempSampleRate = SAMPLING_RATE_4S;
                RTC_Timer32Compare0Set(PERIOD_4S);
            }
            else if(tempSampleRate == SAMPLING_RATE_4S)
            {
               tempSampleRate = SAMPLING_RATE_500MS;
               RTC_Timer32Compare0Set(PERIOD_500MS);
            }
            else
            {
                ;
            }
            RTC_Timer32CounterSet(0);
            sprintf((char*)uartTxTempBuffer, "LED Toggling rate is changed to %s\r\n", &timeouts[(uint8_t)tempSampleRate][0]);
            readUartTxStatus = true;
        }
    }
    else
    {
        /* Extended Functionality: Reads and prints the current room temperature
         * periodically when the extension header (EXT1) is plugged with the
         * I/O1 Xplained Pro Extension Kit. The temperature reading is displayed on
         * a serial console periodically every second.*/
        if (printTempSampleRate == true)
        {
            memset((char*)uartTxTempBuffer, 0x00, 100);
            sprintf((char*)uartTxTempBuffer, "************* Printing Temperature *************\r\n");
            printTempSampleRate = false;
            readUartTxStatus = true;
        }
        if ((isI2CFree == true) &&
            (isRTCTimerExpired == true))  //Temperature Reading from Sensor
        {
            isRTCTimerExpired = false;
            isI2CFree = false;
            i2cAddress = TEMP_SENSOR_SLAVE_ADDR;
            SERCOM4_I2C_WriteRead(TEMP_SENSOR_SLAVE_ADDR, &i2cWrData, 1, i2cRdData, 2);
        }
        if ((isI2CFree == true) &&
            (isTemperatureRead == true))
        {
            isTemperatureRead = false;
            if(changeSamplingRate == false)
            {
                temperatureVal = getTemperature(i2cRdData);
                memset((char*)uartTxTempBuffer, 0x00, 100);
                sprintf((char*)uartTxTempBuffer, "Temperature = %02d F\r\n", temperatureVal);
                LED0_Toggle();
                i2cAddress = EEPROM_I2C_SLAVE_ADDR;
                isI2CFree = false;
                eepromWrite(temperatureVal);
            }
            else
            {
                changeSamplingRate = false;
                RTC_Timer32CounterSet(0);
                if(tempSampleRate == SAMPLING_RATE_500MS)
                {
                    tempSampleRate = SAMPLING_RATE_1S;
                    sprintf((char*)uartTxTempBuffer, "Sampling Temperature every 1 second \r\n");
                    RTC_Timer32Compare0Set(PERIOD_1S);
                }
                else if(tempSampleRate == SAMPLING_RATE_1S)
                {
                    tempSampleRate = SAMPLING_RATE_2S;
                    sprintf((char*)uartTxTempBuffer, "Sampling Temperature every 2 seconds \r\n");
                    RTC_Timer32Compare0Set(PERIOD_2S);
                }
                else if(tempSampleRate == SAMPLING_RATE_2S)
                {
                    tempSampleRate = SAMPLING_RATE_4S;
                    sprintf((char*)uartTxTempBuffer, "Sampling Temperature every 4 seconds \r\n");
                    RTC_Timer32Compare0Set(PERIOD_4S);
                }
                else if(tempSampleRate == SAMPLING_RATE_4S)
                {
                    tempSampleRate = SAMPLING_RATE_500MS;
                    sprintf((char*)uartTxTempBuffer, "Sampling Temperature every 500 ms \r\n");
                    RTC_Timer32Compare0Set(PERIOD_500MS);
                }
                else
                {
                    ;
                }
            }
            readUartTxStatus = true;
        }
        else if (showErrorMsg == true)
        {
            memset((char*)uartTxTempBuffer, 0x00, 100);
            sprintf((char*)uartTxTempBuffer, "Error.! Connect IO1 Xplained Pro board and Restart the device.\r\n");
            readUartTxStatus = true;
            showErrorMsg = false;
        }
        if ((isI2CFree == true) &&
            (isEEPROMRead == true))       //Temperature Reading from EEPROM
        {
            isI2CFree           = false;
            isEEPROMRead        = false;
            isEEPROMReadReq     = true;
            i2cAddress          = EEPROM_I2C_SLAVE_ADDR;
            eepromTxBuffer[0]   = EEPROM_LOG_MEMORY_ADDR;
            SERCOM4_I2C_WriteRead(EEPROM_I2C_SLAVE_ADDR, eepromTxBuffer, 1, eepromRxBuffer, 6);
        }
    }
}

int main ( void )
{
    uint32_t msp_ns = *((uint32_t *)(TZ_START_NS));
    volatile funcptr_void NonSecure_ResetHandler;

    /* Initialize all modules */
    SYS_Initialize ( NULL );

    SERCOM4_I2C_CallbackRegister(i2cEventHandler, 0);
    RTC_Timer32CallbackRegister(rtcEventHandler, 0);
    EIC_CallbackRegister(EIC_PIN_10, SW0_eventHandler, 0);
    EIC_NMICallbackRegister(SW1_eventHandler, 0);

    sprintf((char*)uartTxTempBuffer, "************* Printing Toggling LED rate *************\r\n");
    readUartTxStatus = true;

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
    }

    /* Execution should not come here during normal operation */
    return ( EXIT_FAILURE );
}

/*******************************************************************************
 End of File
*/

