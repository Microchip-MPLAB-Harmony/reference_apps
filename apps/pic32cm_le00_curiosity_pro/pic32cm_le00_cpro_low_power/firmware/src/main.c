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
* Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.
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

/* Interrupt flags for ADC WindowMonitoring, SERCOM5_I2C, DMA Transfer and Sleep mode*/
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

/* Handler for I²C interrupt */
static void i2cEventHandler (uintptr_t contextHandle)
{
    /* Check that there were no error during SERCOM5_I2C read for temperature */
    if(SERCOM5_I2C_ErrorGet() == SERCOM_I2C_ERROR_NONE)
    {
        isTemperatureRead = true;
    }
    
    else
    {
        /* Display message on terminal */
        printf ("There were an error during I2C Transmit. Please ensure that the I/O1 Xplained Pro is connected to the board.\n\n\r");
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
    /* Set sleepmode flag after interrupt from button press */
    sleepMode = true;
}

/***************************************************************************************
 * Convert the temperature value read from sensor to readable format (Degree Fahrenheit)
 * For demonstration purpose, temperature value is assumed to be positive
 * The maximum positive temperature measured by sensor is +257 °F (+125 °C) 
 **************************************************************************************/
static uint8_t getTemperature (uint8_t* rawTempValue)
{
    uint16_t temp;
    /* Convert measured value in Degree Fahrenheit (°F) */
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
    /* Switch on LED0 */
    LED0_Clear ();
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    /* Initialize the EIC callback register */
    EIC_CallbackRegister (EIC_PIN_4, EIC_User_Handler, 0);

    /* Initialize the SERCOM 5 I²C callback register */
    SERCOM5_I2C_CallbackRegister (i2cEventHandler, 0);

    /* Initialize the DMA channel 0 callback register */
    DMAC_ChannelCallbackRegister (DMAC_CHANNEL_0, dmaChannel0Handler, 0);

    /* Initialize the ADC callback register */
    ADC_CallbackRegister (adcEventHandler, 0);
    
    /* Enable ADC */
    ADC_Enable ();
    
    /* Start RTC counter */
    RTC_Timer32Start ();
    
    /* Display example title */
    printf ("\n\n\r---------------------------------------------------------");
    printf ("\n\r           Low-power Application on PIC32CM LE00 Cpro           ");
    printf ("\n\r---------------------------------------------------------\n\n\r");
    
    printf ("Enter in Standby sleep mode\n\n\r");
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
            printf ("ADC_WINMON Interrupt Detected. Wake-up from sleep mode.\n\r");
            /* Read the temperature sensor value from I/O1 Xplained Pro through SERCOM5 I²C */
            SERCOM5_I2C_WriteRead (TEMP_SENSOR_SLAVE_ADDR, &i2cWrData, 1, i2cRdData, 2);
            /* Switch off LED0 */
            LED0_Set ();
            /* Put device in Standby mode */
            PM_StandbyModeEnter ();  
        }
        
        if (isTemperatureRead == true)
        {
            isTemperatureRead = false;
            /* Store the temperature sensor value on temperatureVal */
            temperatureVal = getTemperature (i2cRdData);
            /* Fill uartTxBuffer variable with message containing temperature value to display on terminal */
            sprintf ((char*)uartTxBuffer, "Temperature = %02d F \r\n", temperatureVal);
            /* Check that the SERCOM3 USART is ready for new data */
            while (!SERCOM3_USART_TransmitterIsReady());
            /* Transmit the uartTxBuffer variable content to terminal through SERCOM3 USART peripheral */
            DMAC_ChannelTransfer (DMAC_CHANNEL_0, uartTxBuffer, (const void*)&(SERCOM3_REGS->USART_INT.SERCOM_DATA), sizeof(uartTxBuffer));
        }
        
        if (isDMATransferComplete == true)
        {      
            isDMATransferComplete = false;
            /* Display message on terminal */
            printf("DMA transfer completed. Entering in Standby sleep mode.\n\n\r");
            /* Switch off LED0 */
            LED0_Set ();
            /* Put device in Standby mode */
            PM_StandbyModeEnter ();          
        }
        
        if (sleepMode == true)
        {
            sleepMode = false;
            /* Display message on terminal */
            printf ("SW1 button pressed. Entering in Idle sleep mode.\n\n\r");
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


