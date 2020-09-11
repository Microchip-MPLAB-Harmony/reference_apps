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

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

// *****************************************************************************
// *****************************************************************************
// Section: Data Variables
// *****************************************************************************
// *****************************************************************************

#define TEMP_SENSOR_SLAVE_ADDR                         0x004F
#define TEMP_SENSOR_REG_ADDR                           0x00

/* Interrupt flags for ADC WindowMonitoring, SERCOM3_I2C, DMA Transfer and Sleep mode*/
volatile bool isADCWinMonitorEvent = false;
volatile bool isTemperatureRead = false;
volatile bool isDMATransferComplete = false;
volatile bool sleepMode = false;

static uint8_t temperatureVal;
static uint8_t i2cWrData = TEMP_SENSOR_REG_ADDR;
static uint8_t i2cRdData[2] = {0};
static uint8_t uartTxBuffer[100] = {0};

uint8_t adcResult = 0;

// *****************************************************************************
// *****************************************************************************
// Section: Declared Functions
// *****************************************************************************
// *****************************************************************************

/* Handler for DMA channel transfer interrupt */
static void dmaChannel0Handler (DMAC_TRANSFER_EVENT event, uintptr_t contextHandle)
{
    /* Check the DMA transfer was completed before starting new transfer */
    if(event == DMAC_TRANSFER_EVENT_COMPLETE)
    {
        isDMATransferComplete = true;
    }
}

/* Handler for I�C interrupt */
static void i2cEventHandler (uintptr_t contextHandle)
{
    /* Check that there were no error during SERCOM3_I2C read for temperature */
    if(SERCOM3_I2C_ErrorGet() == SERCOM_I2C_ERROR_NONE)
    {
        isTemperatureRead = true;
    }
    
    else
    {
        /* Display message on terminal */
        printf ("\r\nThere were an error during I2C Transmit. Please ensure that the I/O1 Xplained Pro is connected to the board.\n\n\r\n");
    }
}

/* Handler for ADC Window Monitor Interrupt */
static void adcEventHandler (ADC_STATUS status, uintptr_t context)
{
    /* Set ADC WinMon flag after Window Monitoring Interrupt */
    isADCWinMonitorEvent = true;
}

/* Handler for button switch interrupt using EIC peripheral */
static void EIC_User_Handler (uintptr_t context)
{
    /* Set sleepmode flag after interrupt from button pressure */
    sleepMode = true;
}

/***************************************************************************************
 * Convert the temperature value read from sensor to readable format (Degree Fahrenheit)
 * For demonstration purpise, temperature value is assumed to be positive
 * The maximum positive temperature measured by sensor is +257 �F (+125 �C) 
 **************************************************************************************/
static uint8_t getTemperature (uint8_t* rawTempValue)
{
    uint16_t temp;
    /* Convert measured value in Degree Fahrenheit (�F) */
    temp = (rawTempValue[0] << 8) | rawTempValue[1];
    temp = (temp >> 7) * 0.5;
    temp = (temp * 9/5) + 32;
    
    return (uint8_t)temp;
}

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    /* Initialize the EIC callback register */
    EIC_CallbackRegister (EIC_PIN_15, EIC_User_Handler, 0);

    /* Initialize the SERCOM 2 I�C callback register */
    SERCOM3_I2C_CallbackRegister (i2cEventHandler, 0);

    /* Initialize the DMA channel 0 callback register */
    DMAC_ChannelCallbackRegister (DMAC_CHANNEL_0, dmaChannel0Handler, 0);

    /* Initialize the ADC1 callback register */
    ADC1_CallbackRegister (adcEventHandler, 0);
    
    /* Enable ADC */
    ADC1_Enable ();
    
    /* Start RTC counter */
    RTC_Timer32Start ();
    
    /* Display example title */
    printf ("\n\n\r---------------------------------------------------------");
    printf ("\n\r           Low-power Application on SAM E54 Xpro           ");
    printf ("\n\r---------------------------------------------------------\n\n\r");
    
    printf ("\r\nEnter in Standby sleep mode\n\n\r\n");
    /* Put the device in Standby mode */
    PM_StandbyModeEnter ();

    while ( true )
    {
        if (isADCWinMonitorEvent == true)
        {            
            isADCWinMonitorEvent = false;
            /* Switch on LED0 */
            LED0_Clear ();
            /* Display message on terminal */
            printf ("\r\nADC_WINMON Interrupt Detected. Wake-up from sleep mode.\r\n");
            /* Read the temperature sensor value from I/O1 Xplained Pro through SERCOM3 I�C */
            SERCOM3_I2C_WriteRead (TEMP_SENSOR_SLAVE_ADDR, &i2cWrData, 1, i2cRdData, 2);
        }
        
        if (isTemperatureRead == true)
        {
            isTemperatureRead = false;
            /* Store the temperature sensor value on temperatureVal */
            temperatureVal = getTemperature (i2cRdData);
            /* Fill uartTxBuffer variable with message containing temperature value to display on terminal */
            sprintf ((char*)uartTxBuffer, "\r\nTemperature = %02d F \r\n", temperatureVal);
            /* Check that the SERCOM3 USART is ready for new data */
            while (!SERCOM2_USART_TransmitterIsReady());
            /* Transmit the uartTxBuffer variable content to terminal through SERCOM3 USART peripheral */
            DMAC_ChannelTransfer (DMAC_CHANNEL_0, uartTxBuffer, (const void*)&(SERCOM2_REGS->USART_INT.SERCOM_DATA), sizeof(uartTxBuffer));
        }
        
        if (isDMATransferComplete == true)
        {      
            isDMATransferComplete = false;
            /* Display message on terminal */
            printf("\r\nDMA transfer completed. Enter in Standby sleep mode.\r\n");
            /* Switch off LED0 */
            LED0_Set ();
            /* Put device in Standby mode */
            PM_StandbyModeEnter ();
        }
        
        if (sleepMode == true)
        {
            sleepMode = false;
            /* Display message on terminal */
            printf ("\r\nSW0 button pressed. Enter in Idle sleep mode.\r\n");
            /* Switch off LED0 */
            LED0_Set ();
            /* Put the device in Idle mode */
            PM_IdleModeEnter ();
        }
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

