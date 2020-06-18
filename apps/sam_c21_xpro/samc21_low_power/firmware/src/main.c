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
// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include <stdio.h>
#include <string.h>

#define TEMP_SENSOR_SLAVE_ADDR                         0x004F
#define TEMP_SENSOR_REG_ADDR                           0x00

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

volatile bool isADCWinMonitorEvent = false;
volatile bool isTemperatureRead = false;
volatile bool isDMATransferComplete = false;
volatile bool sleepMode = false;

static uint8_t temperatureVal;
static uint8_t i2cWrData = TEMP_SENSOR_REG_ADDR;
static uint8_t i2cRdData[2] = {0};
static uint8_t uartTxBuffer[100] = {0};

 uint16_t adcResult;
 
static void dmaChannel0Handler(DMAC_TRANSFER_EVENT event, uintptr_t contextHandle){
    if(event == DMAC_TRANSFER_EVENT_COMPLETE)
    {
        isDMATransferComplete = true;
    }
}

static void i2cEventHandler(uintptr_t contextHandle){
    
    if(SERCOM2_I2C_ErrorGet() == SERCOM_I2C_ERROR_NONE)
    {
        isTemperatureRead = true;
    }
}

static void adcEventHandler(ADC_STATUS status, uintptr_t context)
{  
    if(status & ADC_STATUS_WINMON){
        adcResult = ADC1_ConversionResultGet();
        isADCWinMonitorEvent = true;
    }
}

static void EIC_User_Handler(uintptr_t context)
{
    sleepMode = true;
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
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    EIC_CallbackRegister(EIC_PIN_8,EIC_User_Handler, 0);
    
    SERCOM2_I2C_CallbackRegister(i2cEventHandler,0);
    
    DMAC_ChannelCallbackRegister(DMAC_CHANNEL_0,dmaChannel0Handler,0);
    
    ADC1_CallbackRegister(adcEventHandler,0);

    ADC1_Enable();
    
    RTC_Timer32Start();
    
    PM_StandbyModeEnter();
    
    while ( true )
    {    

        if(isADCWinMonitorEvent == true){
            
            isADCWinMonitorEvent = false;
            SERCOM2_I2C_WriteRead(TEMP_SENSOR_SLAVE_ADDR,&i2cWrData,1,i2cRdData,2 );
        }
        
        if(isTemperatureRead == true){
            isTemperatureRead = false;
            temperatureVal = getTemperature(i2cRdData);
            sprintf((char*)uartTxBuffer,"Temperature = %02d F \r\n",temperatureVal);
            DMAC_ChannelTransfer(DMAC_CHANNEL_0,uartTxBuffer,(const void*)&(SERCOM4_REGS->USART_INT.SERCOM_DATA),strlen((const char*)uartTxBuffer));
            LED_Toggle();
        }
        
        if(isDMATransferComplete == true)
        {      
            isDMATransferComplete = false;
            
            LED_Set();
            
            PM_StandbyModeEnter();
        }
        
        if(sleepMode == true)
        {
           sleepMode = false;
           
           PM_IdleModeEnter();
        }

    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

