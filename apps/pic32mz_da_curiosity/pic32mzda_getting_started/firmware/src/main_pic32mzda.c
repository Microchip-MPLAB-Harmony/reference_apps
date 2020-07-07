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
	initialiaztions and the "main" function have the application code to 
	toggles an LED on a timeout basis and to print the LED toggling rate 
	(or current temperature value if a I/01 Xplained Pro Extension Kit board 
	is connected) on the serial terminal.
*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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

#define TEMP_SENSOR_SLAVE_ADDR                  0x18
#define TEMP_SENSOR_REG_ADDR                    0x05

#define SWITCH_PRESSED_STATE                    0   // Active LOW switch

/* Timer Counter Time period match values for input clock of 4096 Hz */
#define PERIOD_500MS                            2048
#define PERIOD_1S                               4096
#define PERIOD_2S                               8192
#define PERIOD_4S                               16384

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
static volatile bool isTmr1Expired = false;
static volatile bool changeTempSamplingRate = false;
static volatile bool startTemperatureReading  = false;
static volatile uint8_t TemperatureReadStartMsgLen  = 0x00;
static volatile bool isUARTTxComplete = true;
static volatile bool isTemperatureRead = false;
static uint8_t temperatureVal;
static uint8_t i2cWrData = TEMP_SENSOR_REG_ADDR;
static uint8_t i2cRdData[2] = {0};
static uint8_t __attribute__ ((aligned (16))) uartTxBuffer[100] = {0};
typedef enum
{
    TEMP_SAMPLING_RATE_500MS = 0,
    TEMP_SAMPLING_RATE_1S = 1,
    TEMP_SAMPLING_RATE_2S = 2,
    TEMP_SAMPLING_RATE_4S = 3,
} TEMP_SAMPLING_RATE;
static TEMP_SAMPLING_RATE tempSampleRate = TEMP_SAMPLING_RATE_500MS;
static const char timeouts[4][20] = {"500 milliSeconds", "1 Second",  "2 Seconds",  "4 Seconds"};


static void SW1_User_Handler(GPIO_PIN pin, uintptr_t context)
{
    if(SW1_Get() == SWITCH_PRESSED_STATE)
    {
        changeTempSamplingRate = true;      
    }
}

static void SW2_User_Handler(GPIO_PIN pin, uintptr_t context)
{
    if(SW2_Get() == SWITCH_PRESSED_STATE)
    {
        if(false == startTemperatureReading)
        {
            startTemperatureReading = true;
            sprintf((char*)uartTxBuffer, "************* Printing Temperature *************\r\n");
            TemperatureReadStartMsgLen = strlen((const char*)uartTxBuffer);
        }
        else
        {
            startTemperatureReading = false;
            sprintf((char*)uartTxBuffer, "************* Printing Toggling LED rate *************\r\n");
            TemperatureReadStartMsgLen = strlen((const char*)uartTxBuffer);
        }
    }
}

static void tmr1EventHandler (uint32_t intCause, uintptr_t context)
{
    isTmr1Expired = true;
}

static void i2cEventHandler(uintptr_t contextHandle)
{
    if (I2C1_ErrorGet() == I2C_ERROR_NONE)
    {
        isTemperatureRead = true;
    }
}

static void UARTDmaChannelHandler(DMAC_TRANSFER_EVENT event, uintptr_t contextHandle)
{
    if (event == DMAC_TRANSFER_EVENT_COMPLETE)
    {
        isUARTTxComplete = true;
    }
}

static void MCP9808TempSensorInit(void)
{
    uint8_t config[3] = {0};
	config[0] = 0x01;
	config[1] = 0x00;
	config[2] = 0x00;
    
    I2C1_Write(TEMP_SENSOR_SLAVE_ADDR, config, 3);
    
    while (isTemperatureRead != true);
    isTemperatureRead = false;
    
    config[0] = 0x08;
	config[1] = 0x03;
	I2C1_Write(TEMP_SENSOR_SLAVE_ADDR, config, 2);
    
    while (isTemperatureRead != true);
    isTemperatureRead = false;    
}

static uint8_t getTemperature(uint8_t* rawTempValue)
{
    
    int temp = ((rawTempValue[0] & 0x1F) * 256 + rawTempValue[1]);
    if(temp > 4095)
    {
        temp -= 8192;
    }
    float cTemp = temp * 0.0625;
    float fTemp = cTemp * 1.8 + 32;
    return (uint8_t)fTemp;
}

int main ( void )
{
    uint8_t uartLocalTxBuffer[100] = {0};
    
    /* Initialize all modules */
    SYS_Initialize ( NULL );

    I2C1_CallbackRegister(i2cEventHandler, 0);
    MCP9808TempSensorInit();
    DMAC_ChannelCallbackRegister(DMAC_CHANNEL_0, UARTDmaChannelHandler, 0);
    TMR1_CallbackRegister(tmr1EventHandler, 0);
    GPIO_PinInterruptCallbackRegister(SW1_PIN, SW1_User_Handler, 0);
    GPIO_PinInterruptEnable(SW1_PIN);
    GPIO_PinInterruptCallbackRegister(SW2_PIN, SW2_User_Handler, 0);
    GPIO_PinInterruptEnable(SW2_PIN);   

    /* Start the timer 1 */
    TMR1_Start();

    while ( true )
    {
        while(false == startTemperatureReading)
        {
            if ((isTmr1Expired == true) && (true == isUARTTxComplete))
            {
                isTmr1Expired = false;
                isUARTTxComplete = false;
                LED1_Toggle();
                sprintf((char*)(uartTxBuffer + TemperatureReadStartMsgLen), "Toggling LED at %s rate \r\n", &timeouts[(uint8_t)tempSampleRate][0]);                
                TemperatureReadStartMsgLen = 0;
                DCACHE_CLEAN_BY_ADDR((uint32_t)uartTxBuffer, sizeof(uartTxBuffer));
                DMAC_ChannelTransfer(DMAC_CHANNEL_0, (const void *)uartTxBuffer, \
                        strlen((const char*)uartTxBuffer), \
                        (const void *)&U4TXREG, 1, 1);
            }
            if(changeTempSamplingRate == true)
            {
                changeTempSamplingRate = false;
                TMR1_Stop();
                if(tempSampleRate == TEMP_SAMPLING_RATE_500MS)
                {
                    tempSampleRate = TEMP_SAMPLING_RATE_1S;
                    TMR1_PeriodSet(PERIOD_1S);
                }
                else if(tempSampleRate == TEMP_SAMPLING_RATE_1S)
                {
                    tempSampleRate = TEMP_SAMPLING_RATE_2S;
                    TMR1_PeriodSet(PERIOD_2S);                        
                }
                else if(tempSampleRate == TEMP_SAMPLING_RATE_2S)
                {
                    tempSampleRate = TEMP_SAMPLING_RATE_4S;
                    TMR1_PeriodSet(PERIOD_4S);                                        
                }    
                else if(tempSampleRate == TEMP_SAMPLING_RATE_4S)
                {
                   tempSampleRate = TEMP_SAMPLING_RATE_500MS;
                   TMR1_PeriodSet(PERIOD_500MS);
                }
                else
                {
                    ;
                }
                TMR1_Start();
                sprintf((char*)uartLocalTxBuffer, "LED Toggling rate is changed to %s\r\n", &timeouts[(uint8_t)tempSampleRate][0]);
                DCACHE_CLEAN_BY_ADDR((uint32_t)uartLocalTxBuffer, sizeof(uartLocalTxBuffer));
                DMAC_ChannelTransfer(DMAC_CHANNEL_0, (const void *)uartLocalTxBuffer, \
                        strlen((const char*)uartLocalTxBuffer), \
                        (const void *)&U4TXREG, 1, 1);
            }
        }
        if (isTmr1Expired == true)
        {
            isTmr1Expired = false;
            //I2C1_WriteRead(TEMP_SENSOR_SLAVE_ADDR, &i2cWrData, 1, i2cRdData, 2);
            I2C1_WriteRead(TEMP_SENSOR_SLAVE_ADDR, &i2cWrData, 1, i2cRdData, 2);
        }
        if (isTemperatureRead == true)
        {
            isTemperatureRead = false;
            if(changeTempSamplingRate == false)
            {
                temperatureVal = getTemperature(i2cRdData);
                sprintf((char*)(uartTxBuffer + TemperatureReadStartMsgLen), "Temperature = %02d F\r\n", (int)temperatureVal);
                TemperatureReadStartMsgLen = 0;
                LED1_Toggle();
            }
            else
            {
                changeTempSamplingRate = false;
                TMR1_Stop();
                if(tempSampleRate == TEMP_SAMPLING_RATE_500MS)
                {
                    tempSampleRate = TEMP_SAMPLING_RATE_1S;
                    sprintf((char*)uartTxBuffer, "Sampling Temperature every 1 second \r\n");
                    TMR1_PeriodSet(PERIOD_1S);
                }
                else if(tempSampleRate == TEMP_SAMPLING_RATE_1S)
                {
                    tempSampleRate = TEMP_SAMPLING_RATE_2S;
                    sprintf((char*)uartTxBuffer, "Sampling Temperature every 2 seconds \r\n");        
                    TMR1_PeriodSet(PERIOD_2S);                        
                }
                else if(tempSampleRate == TEMP_SAMPLING_RATE_2S)
                {
                    tempSampleRate = TEMP_SAMPLING_RATE_4S;
                    sprintf((char*)uartTxBuffer, "Sampling Temperature every 4 seconds \r\n");        
                    TMR1_PeriodSet(PERIOD_4S);                                        
                }    
                else if(tempSampleRate == TEMP_SAMPLING_RATE_4S)
                {
                   tempSampleRate = TEMP_SAMPLING_RATE_500MS;
                   sprintf((char*)uartTxBuffer, "Sampling Temperature every 500 ms \r\n");        
                   TMR1_PeriodSet(PERIOD_500MS);
                }
                else
                {
                    ;
                }
                TMR1_Start();
            }
            DCACHE_CLEAN_BY_ADDR((uint32_t)uartTxBuffer, sizeof(uartTxBuffer));
            DMAC_ChannelTransfer(DMAC_CHANNEL_0, (const void *)uartTxBuffer, \
                    strlen((const char*)uartTxBuffer), \
                    (const void *)&U4TXREG, 1, 1);
        }
    }
    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

