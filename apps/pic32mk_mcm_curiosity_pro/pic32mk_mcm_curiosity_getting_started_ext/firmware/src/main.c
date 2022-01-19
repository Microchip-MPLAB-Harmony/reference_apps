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
    (or current temperature value if a MikroElectronika Weather click board
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
#include <stdint.h>
#include "definitions.h"                // SYS function prototypes
#include "bme280_definitions.h"
#include "bme280_driver.h"

/* Timer Counter Time period match values for input clock of 60000000 Hz */
#define PERIOD_500MS                            30000000U
#define PERIOD_1S                               60000000U
#define PERIOD_2S                               120000000U
#define PERIOD_4S                               240000000U

#define SWITCH_PRESSED_STATE                    0   // Active LOW switch

#define MAX_SPI_TX_BUFFER_SIZE                  100
#define MAX_SPI_RX_BUFFER_SIZE                  100

#define SWITCH_1                                1   // Switch 1 is pressed
#define SWITCH_3                                3   // Switch 3 is pressed

typedef struct
{
    volatile bool                   isBufferCompleteEvent;
    uint8_t                         slaveID;
    int16_t                         temperature;
    uint8_t                         txBuffer[MAX_SPI_TX_BUFFER_SIZE];
    uint8_t                         rxBuffer[MAX_SPI_RX_BUFFER_SIZE];
}BME_SENSOR_DATA;
static BME_SENSOR_DATA BME280SensorData;

typedef enum
{
    TEMP_SAMPLING_RATE_500MS = 0,
    TEMP_SAMPLING_RATE_1S = 1,
    TEMP_SAMPLING_RATE_2S = 2,
    TEMP_SAMPLING_RATE_4S = 3,
} TEMP_SAMPLING_RATE;
static volatile TEMP_SAMPLING_RATE tempSampleRate = TEMP_SAMPLING_RATE_500MS;
static const char timeouts[4][20] = {"500 milliSeconds", "1 Second",  "2 Seconds",  "4 Seconds"};

static volatile bool isTmr2Expired = false;
static volatile bool changeTempSamplingRate = false;
static volatile bool startTemperatureReading  = false;
static volatile uint8_t TemperatureReadStartMsgLen  = 0x00;
static volatile bool isUARTTxComplete = true;
static uint16_t      temperatureVal;
static volatile bool isTemperatureRead = false;
static volatile uint8_t prevSwitchPressedState = SWITCH_1;
static volatile uint8_t currSwitchPressedState = SWITCH_1;
static volatile uint8_t switchFrom_4s_to_500ms = false;
static volatile bool bme280SensorInit =  false;

static uint8_t __attribute__ ((aligned (16))) uartTxBuffer[100] = {0};

static void SW1_User_Handler(GPIO_PIN pin, uintptr_t context)
{
    if(SW1_Get() == SWITCH_PRESSED_STATE)
    {
        currSwitchPressedState = SWITCH_1;

        if (prevSwitchPressedState == currSwitchPressedState)
        {
            changeTempSamplingRate = true;
        }
        prevSwitchPressedState = SWITCH_1;
    }
}

static void SW3_User_Handler(GPIO_PIN pin, uintptr_t context)
{
    if(SW3_Get() == SWITCH_PRESSED_STATE)
    {
        currSwitchPressedState = SWITCH_3;

        if (prevSwitchPressedState == currSwitchPressedState)
        {
            changeTempSamplingRate = true;
        }
        prevSwitchPressedState = SWITCH_3;
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

static void toggleLED_BasedOnSwitchPress(void)
{
    if (currSwitchPressedState == SWITCH_1)
    {
        LED3_Clear();
        LED1_Toggle();
    }
    else
    {
        LED1_Clear();
        LED3_Toggle();
    }
}

static void tmr2EventHandler (uint32_t intCause, uintptr_t context)
{
    isTmr2Expired = true;

    if (switchFrom_4s_to_500ms == true)
    {
        TMR2_PeriodSet(PERIOD_500MS);
        switchFrom_4s_to_500ms = false;
        tempSampleRate = TEMP_SAMPLING_RATE_500MS;
    }
}

static void SPIBufferEventHandler(uintptr_t context)
{
    SENSOR_CS_Set();
    BME280SensorData.isBufferCompleteEvent = true;
    isTemperatureRead = true;
}

static void UARTDmaChannelHandler(DMAC_TRANSFER_EVENT event, uintptr_t contextHandle)
{
    if (event == DMAC_TRANSFER_EVENT_COMPLETE)
    {
        isUARTTxComplete = true;
    }
}

static bool BME280Sensor_WriteReg(uint8_t wrAddr, uint8_t wrData)
{
    BME280SensorData.txBuffer[0]            = wrAddr & 0x7F;
    BME280SensorData.txBuffer[1]            = wrData;
    BME280SensorData.isBufferCompleteEvent  = false;

    SENSOR_CS_Clear();
    SPI6_Write(BME280SensorData.txBuffer, 2);

    while(false == BME280SensorData.isBufferCompleteEvent);

    return true;
}

static uint8_t BME280Sensor_ReadReg(uint8_t rAddr)
{
    BME280SensorData.txBuffer[0]            = rAddr;
    BME280SensorData.isBufferCompleteEvent  = false;

    SENSOR_CS_Clear();
    SPI6_WriteRead(BME280SensorData.txBuffer, 1, BME280SensorData.rxBuffer, 2);

    while(false == BME280SensorData.isBufferCompleteEvent);

    return BME280SensorData.rxBuffer[1];
}

static bool BME280Sensor_Read(uint8_t rAddr, uint8_t* const pReadBuffer, uint8_t nBytes)
{
    BME280SensorData.txBuffer[0]            = rAddr;
    BME280SensorData.isBufferCompleteEvent  = false;

    SENSOR_CS_Clear();
    SPI6_WriteRead(BME280SensorData.txBuffer, 1, BME280SensorData.rxBuffer, (nBytes + 1));

    while(false == BME280SensorData.isBufferCompleteEvent);
    memcpy(pReadBuffer, &BME280SensorData.rxBuffer[1], nBytes);

    return true;
}

void BME280Sensor_Initialize(void)
{
    BME280SensorData.temperature   = 0;
    BME280SensorData.slaveID        = BME280_SPI_ADDRESS;
    BME280SensorData.isBufferCompleteEvent = false;

    /* Register with BME280 sensor */
    BME280_RegisterDrvWriteReg(BME280Sensor_WriteReg);
    BME280_RegisterDrvReadReg(BME280Sensor_ReadReg);
    BME280_RegisterDrvRead(BME280Sensor_Read);

    BME280_SoftReset();
    /* 100 m.sec delay */
    CORETIMER_DelayMs(100);

    if (BME280_CHIP_ID != BME280_ID_Get())
    {
        while(1);       /* Error Occurred */
    }
    BME280_CalibParams_Get();
    BME280_SetOversampling(BME280_PARAM_TEMP, BME280_OVERSAMPLING_1X);
    BME280_PowerMode_Set(BME280_NORMAL_MODE);
}

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
int main ( void )
{
    uint8_t uartLocalTxBuffer[100] = {0};

    /* Initialize all modules */
    SYS_Initialize ( NULL );

    LED1_Clear();
    LED3_Clear();

    SPI6_CallbackRegister(SPIBufferEventHandler, 0);
    DMAC_ChannelCallbackRegister(DMAC_CHANNEL_0, UARTDmaChannelHandler, 0);
    TMR2_CallbackRegister(tmr2EventHandler, 0);
    GPIO_PinInterruptCallbackRegister(SW1_PIN, SW1_User_Handler, 0);
    GPIO_PinInterruptEnable(SW1_PIN);
    GPIO_PinInterruptCallbackRegister(SW2_PIN, SW2_User_Handler, 0);
    GPIO_PinInterruptEnable(SW2_PIN);
    GPIO_PinInterruptCallbackRegister(SW3_PIN, SW3_User_Handler, 0);
    GPIO_PinInterruptEnable(SW3_PIN);

    U6STASET |= _U6STA_UTXISEL0_MASK;

    /* Start the timer 2 */
    TMR2_Start();

    while ( true )
    {
        while(false == startTemperatureReading)
        {
            if ((isTmr2Expired == true) && (true == isUARTTxComplete))
            {
                isTmr2Expired = false;
                isUARTTxComplete = false;
                toggleLED_BasedOnSwitchPress();
                sprintf((char*)(uartTxBuffer + TemperatureReadStartMsgLen), "Toggling LED at %s rate \r\n", &timeouts[(uint8_t)tempSampleRate][0]);
                TemperatureReadStartMsgLen = 0;
                DMAC_ChannelTransfer(DMAC_CHANNEL_0, (const void *)uartTxBuffer, \
                        strlen((const char*)uartTxBuffer), \
                        (const void *)&U6TXREG, 1, 1);
                DCH0ECON |= _DCH0ECON_CFORCE_MASK;
            }
            if(changeTempSamplingRate == true)
            {
                changeTempSamplingRate = false;
                TMR2_Stop();
                if(tempSampleRate == TEMP_SAMPLING_RATE_500MS)
                {
                    tempSampleRate = TEMP_SAMPLING_RATE_1S;
                    TMR2_PeriodSet(PERIOD_1S);
                }
                else if(tempSampleRate == TEMP_SAMPLING_RATE_1S)
                {
                    tempSampleRate = TEMP_SAMPLING_RATE_2S;
                    TMR2_PeriodSet(PERIOD_2S);
                }
                else if(tempSampleRate == TEMP_SAMPLING_RATE_2S)
                {
                    tempSampleRate = TEMP_SAMPLING_RATE_4S;
                    TMR2_PeriodSet(PERIOD_4S);
                }
                else if(tempSampleRate == TEMP_SAMPLING_RATE_4S)
                {
                    if (TMR2_CounterGet() > PERIOD_500MS)
                    {
                        TMR2_PeriodSet(TMR2_CounterGet() + 1);
                        switchFrom_4s_to_500ms = true;
                    }
                    else
                    {
                        tempSampleRate = TEMP_SAMPLING_RATE_500MS;
                        TMR2_PeriodSet(PERIOD_500MS);
                    }
                }
                else
                {
                    ;
                }
                TMR2_Start();
                sprintf((char*)uartLocalTxBuffer, "LED Toggling rate is changed to %s\r\n", &timeouts[(uint8_t)tempSampleRate][0]);
                DMAC_ChannelTransfer(DMAC_CHANNEL_0, (const void *)uartLocalTxBuffer, \
                        strlen((const char*)uartLocalTxBuffer), \
                        (const void *)&U6TXREG, 1, 1);
                DCH0ECON |= _DCH0ECON_CFORCE_MASK;
            }
        }

        /* To test the extended functionality using MikroElectronika Weather Click Board. */
        while(true == startTemperatureReading)
        {
            if (bme280SensorInit == false )
            {
                BME280Sensor_Initialize();
                bme280SensorInit = true;
            }
            if (isTemperatureRead == true && isTmr2Expired == true)
            {
                isTemperatureRead = false;
                isTmr2Expired = false;
                BME280_ReadRawWeatherData();

                /* The getting temperature is in DegC and resolution is 0.01 DegC.
                 * It means, if the output value is 5123 equals to 51.23 DegC */
                BME280SensorData.temperature   = BME280_GetTempReading();
                if(changeTempSamplingRate == false)
                {
                    /* Celcius to Fahrenheit (°C to °F) Conversion (°F = (°C × 9/5) + 32) */
                    temperatureVal = ((BME280SensorData.temperature * 9 / 5) * 0.01) + 32;

                    sprintf((char*)(uartTxBuffer + TemperatureReadStartMsgLen), "Temperature = %02d F\r\n", temperatureVal);
                    TemperatureReadStartMsgLen = 0;
                    toggleLED_BasedOnSwitchPress();
                }
                else
                {
                    changeTempSamplingRate = false;
                    TMR2_Stop();
                    if(tempSampleRate == TEMP_SAMPLING_RATE_500MS)
                    {
                        tempSampleRate = TEMP_SAMPLING_RATE_1S;
                        sprintf((char*)uartTxBuffer, "Sampling Temperature every 1 second \r\n");
                        TMR2_PeriodSet(PERIOD_1S);
                    }
                    else if(tempSampleRate == TEMP_SAMPLING_RATE_1S)
                    {
                        tempSampleRate = TEMP_SAMPLING_RATE_2S;
                        sprintf((char*)uartTxBuffer, "Sampling Temperature every 2 seconds \r\n");
                        TMR2_PeriodSet(PERIOD_2S);
                    }
                    else if(tempSampleRate == TEMP_SAMPLING_RATE_2S)
                    {
                        tempSampleRate = TEMP_SAMPLING_RATE_4S;
                        sprintf((char*)uartTxBuffer, "Sampling Temperature every 4 seconds \r\n");
                        TMR2_PeriodSet(PERIOD_4S);
                    }
                    else if(tempSampleRate == TEMP_SAMPLING_RATE_4S)
                    {
                        if (TMR2_CounterGet() > PERIOD_500MS)
                        {
                            TMR2_PeriodSet(TMR2_CounterGet() + 1);
                            switchFrom_4s_to_500ms = true;
                        }
                        else
                        {
                            tempSampleRate = TEMP_SAMPLING_RATE_500MS;
                            TMR2_PeriodSet(PERIOD_500MS);
                        }
                        sprintf((char*)uartTxBuffer, "Sampling Temperature every 500 ms \r\n");
                    }
                    else
                    {
                        ;
                    }
                    TMR2_Start();
                }
                DMAC_ChannelTransfer(DMAC_CHANNEL_0, (const void *)uartTxBuffer, \
                                strlen((const char*)uartTxBuffer), \
                                (const void *)&U6TXREG, 1, 1);
                DCH0ECON |= _DCH0ECON_CFORCE_MASK;
            }
        }
    }
    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

