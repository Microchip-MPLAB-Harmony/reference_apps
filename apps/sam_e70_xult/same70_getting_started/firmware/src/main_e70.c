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

#define TEMP_SENSOR_SLAVE_ADDR                  0x004F
#define TEMP_SENSOR_REG_ADDR                    0x00

/* Timer Counter Time period match values for input clock of 1000 Hz */
#define PERIOD_500MS                            500
#define PERIOD_1S                               1000
#define PERIOD_2S                               2000
#define PERIOD_4S                               4000

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
static volatile bool isTC0TimerExpired = false;
static volatile bool changeTempSamplingRate = false;
static volatile bool isUSARTTxComplete = false;
static volatile bool isTemperatureRead = false;
static uint8_t temperatureVal;
static uint8_t i2cWrData = TEMP_SENSOR_REG_ADDR;
static uint8_t i2cRdData[2] = {0};
static uint8_t __attribute__ ((aligned(32))) uartTxBuffer[100] = {0};
typedef enum
{
    TEMP_SAMPLING_RATE_500MS = 0,
    TEMP_SAMPLING_RATE_1S = 1,
    TEMP_SAMPLING_RATE_2S = 2,
    TEMP_SAMPLING_RATE_4S = 3,
} TEMP_SAMPLING_RATE;
static TEMP_SAMPLING_RATE tempSampleRate = TEMP_SAMPLING_RATE_500MS;




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

static void PIO_User_Handler(PIO_PIN pin, uintptr_t context)
{
    changeTempSamplingRate = true;      
}

static void tc0EventHandler (TC_TIMER_STATUS status, uintptr_t context)
{
    isTC0TimerExpired = true;                              
}

static void i2cEventHandler(uintptr_t contextHandle)
{
    if (TWIHS0_ErrorGet() == TWIHS_ERROR_NONE)
    {
        isTemperatureRead = true;
    }
}

static void usartDmaChannelHandler(XDMAC_TRANSFER_EVENT event, uintptr_t contextHandle)
{
    if (event == XDMAC_TRANSFER_COMPLETE)
    {
        isUSARTTxComplete = true;
    }
}

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );

    TWIHS0_CallbackRegister(i2cEventHandler, 0);
    XDMAC_ChannelCallbackRegister(XDMAC_CHANNEL_0, usartDmaChannelHandler, 0);
    TC0_CH0_TimerCallbackRegister(tc0EventHandler, 0);
    PIO_PinInterruptCallbackRegister(SWITCH_PIN, PIO_User_Handler, 0);
    PIO_PinInterruptEnable(SWITCH_PIN);

    /* Start the timer channel 0*/
    TC0_CH0_TimerStart();

    while ( true )
    {
        if (isTC0TimerExpired == true)
        {
            isTC0TimerExpired = false;
            TWIHS0_WriteRead(TEMP_SENSOR_SLAVE_ADDR, &i2cWrData, 1, i2cRdData, 2);
        }
        if (isTemperatureRead == true)
        {
            isTemperatureRead = false;
            if(changeTempSamplingRate == false)
            {
                temperatureVal = getTemperature(i2cRdData);
                sprintf((char*)uartTxBuffer, "Temperature = %02d F\r\n", temperatureVal);
                LED_Toggle();
            }
            else
            {
                changeTempSamplingRate = false;
                if(tempSampleRate == TEMP_SAMPLING_RATE_500MS)
                {
                    tempSampleRate = TEMP_SAMPLING_RATE_1S;
                    sprintf((char*)uartTxBuffer, "Sampling Temperature every 1 second \r\n");
                    TC0_CH0_TimerPeriodSet(PERIOD_1S);
                }
                else if(tempSampleRate == TEMP_SAMPLING_RATE_1S)
                {
                    tempSampleRate = TEMP_SAMPLING_RATE_2S;
                    sprintf((char*)uartTxBuffer, "Sampling Temperature every 2 seconds \r\n");        
                    TC0_CH0_TimerPeriodSet(PERIOD_2S);                        
                }
                else if(tempSampleRate == TEMP_SAMPLING_RATE_2S)
                {
                    tempSampleRate = TEMP_SAMPLING_RATE_4S;
                    sprintf((char*)uartTxBuffer, "Sampling Temperature every 4 seconds \r\n");        
                    TC0_CH0_TimerPeriodSet(PERIOD_4S);                                        
                }    
                else if(tempSampleRate == TEMP_SAMPLING_RATE_4S)
                {
                   tempSampleRate = TEMP_SAMPLING_RATE_500MS;
                   sprintf((char*)uartTxBuffer, "Sampling Temperature every 500 ms \r\n");        
                   TC0_CH0_TimerPeriodSet(PERIOD_500MS);
                }
                else
                {
                    ;
                }
            }
            /* Clean cache lines having source buffer before submitting a transfer
             * request to DMA to load the latest data in the cache to the actual
             * memory */
            SCB_CleanDCache_by_Addr((uint32_t *)uartTxBuffer, 100);

            XDMAC_ChannelTransfer(XDMAC_CHANNEL_0, uartTxBuffer, (const void *)&(USART1_REGS->US_THR), strlen((const char*)uartTxBuffer));
        }
    }
    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

