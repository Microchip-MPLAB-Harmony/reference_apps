/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project, interrupt handler
    callback functions and Temperature conversion function. The "main"
    function calls the "SYS_Initialize" function to initialize all peripherals
    utilized in this project, calls the different interrupt handler callback
    initializations and the "main" function have the application code to
    toggles an LED on a timeout basis and to print the LED toggling rate
    (or current temperature value if a I/01 Xplained Pro Extension Kit board
    is connected) on the serial terminal.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
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
#include "device_cache.h"

#define TEMP_SENSOR_SLAVE_ADDR                  0x004F
#define TEMP_SENSOR_REG_ADDR                    0x00

/* Timer Counter Time period match values for input clock of 4096 Hz */
#define PERIOD_500MS                    512
#define PERIOD_1S                       1024
#define PERIOD_2S                       2048
#define PERIOD_4S                       4096

#define RX_BUFFER_SIZE 1
#define TX_BUFFER_SIZE 100
#define I2C_BUFFER_SIZE 2

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
static volatile bool isRTCExpired = false;
static volatile bool changeTempSamplingRate = false;
static volatile bool startTemperatureReading  = false;
static volatile uint8_t temperatureReadStartMsgLen  = 0x00;
static volatile bool isUARTTxComplete = true;
static volatile bool isUARTRxComplete = false;
static volatile bool isTemperatureRead = false;
static uint8_t temperatureVal;
static uint8_t i2cWrData = TEMP_SENSOR_REG_ADDR;
static uint8_t i2cRdData[I2C_BUFFER_SIZE] = {0};
static uint8_t uartTxBuffer[TX_BUFFER_SIZE] = {0};
char receiveBuffer[RX_BUFFER_SIZE] = {};
bool volatile getErrorStatus = false;
bool volatile readAppStatus = false;
typedef enum
{
    TEMP_SAMPLING_RATE_500MS = 0,
    TEMP_SAMPLING_RATE_1S = 1,
    TEMP_SAMPLING_RATE_2S = 2,
    TEMP_SAMPLING_RATE_4S = 3,
} TEMP_SAMPLING_RATE;

static TEMP_SAMPLING_RATE tempSampleRate = TEMP_SAMPLING_RATE_500MS;
static const char timeouts[4][20] = {"500 milliSeconds", "1 Second",  "2 Seconds",  "4 Seconds"};


static void sw0_userHandler(uintptr_t context)
{
        changeTempSamplingRate = true;
}

static void rtcEventHandler (RTC_TIMER32_INT_MASK intCause, uintptr_t context)
{
    if (intCause & RTC_MODE0_INTENSET_CMP0_Msk)
    {
        isRTCExpired    = true;
    }
}

static void i2cEventHandler(uintptr_t contextHandle)
{
    if (SERCOM3_I2C_ErrorGet() == SERCOM_I2C_ERROR_NONE)
    {
        isTemperatureRead = true;
    }
}

static void uartDmaChannelHandler_Tx(DMAC_TRANSFER_EVENT event, uintptr_t contextHandle)
{
    if (event == DMAC_TRANSFER_EVENT_COMPLETE)
    {
        isUARTTxComplete = true;
    }
}

void uartRxCallback(uintptr_t context)
{
    if(SERCOM4_USART_ErrorGet() != USART_ERROR_NONE)
    {
        /* ErrorGet clears errors, set error flag to notify console */
        getErrorStatus = true;
    }
    else
    {
        if (readAppStatus == true)
        {
            // Print LED toggling rate
            readAppStatus = false;
            startTemperatureReading = false;
        }
        else
        {
            // Print Temperature
            readAppStatus = true;
            startTemperatureReading = true;
        }
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

int main ( void )
{
    uint8_t uartLocalTxBuffer[100] = {0};

    /* Initialize all modules */
    SYS_Initialize ( NULL );

    SERCOM3_I2C_CallbackRegister(i2cEventHandler, 0);
    DMAC_ChannelCallbackRegister(DMAC_CHANNEL_0, uartDmaChannelHandler_Tx, 0);
    SERCOM4_USART_ReadCallbackRegister(uartRxCallback, 0);    
    
    RTC_Timer32CallbackRegister(rtcEventHandler, 0);
    EIC_CallbackRegister(EIC_PIN_3, sw0_userHandler, 0);

    sprintf((char*)uartTxBuffer, "************* Printing Toggling LED rate *************\r\n");
    temperatureReadStartMsgLen = 0;
    DMAC_ChannelTransfer(DMAC_CHANNEL_0, uartTxBuffer, \
        (const void *)&(SERCOM4_REGS->USART_INT.SERCOM_DATA), \
        strlen((const char*)uartTxBuffer));

    /* Start the timer */
    RTC_Timer32Start();

    SERCOM4_USART_Read(&receiveBuffer[0], sizeof(receiveBuffer));

    while ( true )
    {
        while(false == startTemperatureReading && readAppStatus == false)
        {
            if ((isRTCExpired == true) && (true == isUARTTxComplete))
            {
                isRTCExpired = false;
                isUARTTxComplete = false;
                LED0_Toggle();
                sprintf((char*)(uartTxBuffer + temperatureReadStartMsgLen), "Toggling LED at %s rate \r\n", &timeouts[(uint8_t)tempSampleRate][0]);
                temperatureReadStartMsgLen = 0;
                DMAC_ChannelTransfer(DMAC_CHANNEL_0, uartTxBuffer, \
                    (const void *)&(SERCOM4_REGS->USART_INT.SERCOM_DATA), \
                    strlen((const char*)uartTxBuffer));
            }
            if(changeTempSamplingRate == true)
            {
                changeTempSamplingRate = false;
                if(tempSampleRate == TEMP_SAMPLING_RATE_500MS)
                {
                    tempSampleRate = TEMP_SAMPLING_RATE_1S;
                    RTC_Timer32CompareSet(PERIOD_1S);
                }
                else if(tempSampleRate == TEMP_SAMPLING_RATE_1S)
                {
                    tempSampleRate = TEMP_SAMPLING_RATE_2S;
                    RTC_Timer32CompareSet(PERIOD_2S);
                }
                else if(tempSampleRate == TEMP_SAMPLING_RATE_2S)
                {
                    tempSampleRate = TEMP_SAMPLING_RATE_4S;
                    RTC_Timer32CompareSet(PERIOD_4S);
                }
                else if(tempSampleRate == TEMP_SAMPLING_RATE_4S)
                {
                   tempSampleRate = TEMP_SAMPLING_RATE_500MS;
                   RTC_Timer32CompareSet(PERIOD_500MS);
                }
                else
                {
                    ;
                }
                RTC_Timer32CounterSet(0);
                sprintf((char*)uartLocalTxBuffer, "LED Toggling rate is changed to %s\r\n", &timeouts[(uint8_t)tempSampleRate][0]);
                DMAC_ChannelTransfer(DMAC_CHANNEL_0, uartLocalTxBuffer, \
                    (const void *)&(SERCOM4_REGS->USART_INT.SERCOM_DATA), \
                    strlen((const char*)uartLocalTxBuffer));
            }

            /* Submit buffer to read user data */
            SERCOM4_USART_Read(&receiveBuffer[0], sizeof(receiveBuffer));
        }
        
        if (isRTCExpired == true)
        {
            isRTCExpired = false;
            SERCOM3_I2C_WriteRead(TEMP_SENSOR_SLAVE_ADDR, &i2cWrData, 1, i2cRdData, 2);
        }
        if (isTemperatureRead == true && readAppStatus == true)
        {
            isTemperatureRead = false;
            if(changeTempSamplingRate == false)
            {
                temperatureVal = getTemperature(i2cRdData);
                sprintf((char*)(uartTxBuffer + temperatureReadStartMsgLen), "Temperature = %02d F\r\n", temperatureVal);
                temperatureReadStartMsgLen = 0;
                LED0_Toggle();
            }
            else
            {
                changeTempSamplingRate = false;
                RTC_Timer32CounterSet(0);
                if(tempSampleRate == TEMP_SAMPLING_RATE_500MS)
                {
                    tempSampleRate = TEMP_SAMPLING_RATE_1S;
                    sprintf((char*)uartTxBuffer, "Sampling Temperature every 1 second \r\n");
                    RTC_Timer32CompareSet(PERIOD_1S);
                }
                else if(tempSampleRate == TEMP_SAMPLING_RATE_1S)
                {
                    tempSampleRate = TEMP_SAMPLING_RATE_2S;
                    sprintf((char*)uartTxBuffer, "Sampling Temperature every 2 seconds \r\n");
                    RTC_Timer32CompareSet(PERIOD_2S);
                }
                else if(tempSampleRate == TEMP_SAMPLING_RATE_2S)
                {
                    tempSampleRate = TEMP_SAMPLING_RATE_4S;
                    sprintf((char*)uartTxBuffer, "Sampling Temperature every 4 seconds \r\n");
                    RTC_Timer32CompareSet(PERIOD_4S);
                }
                else if(tempSampleRate == TEMP_SAMPLING_RATE_4S)
                {
                   tempSampleRate = TEMP_SAMPLING_RATE_500MS;
                   sprintf((char*)uartTxBuffer, "Sampling Temperature every 500 ms \r\n");
                   RTC_Timer32CompareSet(PERIOD_500MS);
                }
                else
                {
                    ;
                }
                RTC_Timer32Start();
            }
            DMAC_ChannelTransfer(DMAC_CHANNEL_0, uartTxBuffer, \
                    (const void *)&(SERCOM4_REGS->USART_INT.SERCOM_DATA), \
                    strlen((const char*)uartTxBuffer));
        }

        /* Submit buffer to read user data */
        SERCOM4_USART_Read(&receiveBuffer[0], sizeof(receiveBuffer));
    }
    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

