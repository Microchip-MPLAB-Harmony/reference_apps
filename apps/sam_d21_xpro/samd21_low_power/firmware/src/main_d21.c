/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main_d21.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
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
// DOM-IGNORE-END

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

typedef enum
{
    STANDBY_SLEEP_MODE = 0,
    IDLE_SLEEP_MODE = 1,
}SLEEP_MODE_TYPE;

/* Interrupt flags for ADC WindowMonitoring, SERCOM3_I2C, DMA Transfer and Sleep mode*/
volatile bool isTemperatureRead = false;
volatile bool TemperatureReadInitiated = false;

volatile SLEEP_MODE_TYPE sleepMode = STANDBY_SLEEP_MODE;

static uint8_t temperatureVal;
static uint8_t i2cWrData = TEMP_SENSOR_REG_ADDR;
static uint8_t i2cRdData[2] = {0};
static uint8_t uartTxBuffer[100] = {0};

uintptr_t comparator_context;
volatile bool ac_comparison_done = false;
char cmd = 'a';

// *****************************************************************************
// *****************************************************************************
// Section: Declared Functions
// *****************************************************************************
// *****************************************************************************

/* Handler for I²C interrupt */
static void i2cEventHandler (uintptr_t contextHandle)
{
    /* Check that there were no error during SERCOM3_I2C read for temperature */
    if(SERCOM2_I2C_ErrorGet() == SERCOM_I2C_ERROR_NONE)
    {
        isTemperatureRead = true;
    }
    
    else
    {
        /* Display message on terminal */
        printf ("\n\rThere were an error during I2C Transmit. Please ensure that the I/O1 Xplained Pro is connected to the board.");
    }
}

/* Handler for AC interrupt */
void acEventHandler(uint8_t int_flag, uintptr_t ac_context)
{
    ac_comparison_done = true;
    
    /* Indication that a comparison is done */
    LED0_Toggle();
}


/* Handler for button switch interrupt using EIC peripheral */
static void EIC_User_Handler (uintptr_t context)
{
    /* Set sleepmode flag after interrupt from button pressure */
    if(cmd == 'a')
    {
        sleepMode = IDLE_SLEEP_MODE;
    }
}

/***************************************************************************************
 * Convert the temperature value read from sensor to readable format (Degree Fahrenheit)
 * For demonstration purpise, temperature value is assumed to be positive
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

void display_menu (void)
{
    printf("\n\rSelect the Measurement type to ");
    printf("\n\ra) Measure the Sleep Mode Power values for SAM D21");
    printf("\n\rb) Measure the Wakeup Time");
    
    printf("\n\rEnter your choice");
    scanf("%c", &cmd);
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

    /* Initialize the SERCOM 2 I²C callback register */
    SERCOM2_I2C_CallbackRegister (i2cEventHandler, 0);

    /* Initialize the AC callback register */
    AC_CallbackRegister(acEventHandler, comparator_context);
    
    /* Start RTC counter */
    RTC_Timer32Start ();
    
    /* Display example title */
    printf ("\n\n\r-----------------------------------------------------------");
    printf ("\n\r           Low-power Application on SAM D21 Xpro           ");
    printf ("\n\r-----------------------------------------------------------");

    for( ; ; )
    {
        display_menu();
        
        if(cmd == 'a')
        {
            printf("\n\rEntering into Power Measurement Mode");
            break;
        }
        else if(cmd == 'b')
        {
            printf("\n\rEntering into Wakeup Time Measurement Mode");

            /* To run EIC using CPU clock through GCLK0, set the DFLLCTRL to run in standby mode and set the EIC peripheral clock source as GLCK2 */
            /* Configure DFLL    */
            SYSCTRL_REGS->SYSCTRL_DFLLCTRL = SYSCTRL_DFLLCTRL_ENABLE_Msk | SYSCTRL_DFLLCTRL_MODE_Msk | SYSCTRL_DFLLCTRL_RUNSTDBY_Msk ;
            /* Selection of the Generator and write Lock for EIC */
            GCLK_REGS->GCLK_CLKCTRL = GCLK_CLKCTRL_ID(5) | GCLK_CLKCTRL_GEN(0x0)  | GCLK_CLKCTRL_CLKEN_Msk;

            break;
        }
        else
        {
            printf("\n\rInvalid choice");
        }
    }
    
    printf ("\n\rEntering into Standby sleep mode");
    /* Put device in Standby mode */
    ac_comparison_done = false;
    sleepMode = STANDBY_SLEEP_MODE;
    PM_StandbyModeEnter ();

    while ( true )
    {
        if(cmd == 'a')                              /* Power Measurement Mode */
        {
            if(ac_comparison_done)
            {
                printf ("\n\n\n\rPA04 voltage is above detect level, Wake-up from sleep mode.");
                ac_comparison_done = false;
                /* Switch on LED0 */
                LED0_Clear ();
                /* Read the temperature sensor value from I/O1 Xplained Pro through SERCOM3 I²C */
                SERCOM2_I2C_WriteRead (TEMP_SENSOR_SLAVE_ADDR, &i2cWrData, 1, i2cRdData, 2);
                TemperatureReadInitiated = true;
            }
            else if (sleepMode == IDLE_SLEEP_MODE)
            {
                printf ("\n\n\n\rSW0 Pressed, Wake-up from sleep mode......");
            }

            if (isTemperatureRead == true)
            {
                isTemperatureRead = false;
                /* Store the temperature sensor value on temperatureVal */
                temperatureVal = getTemperature (i2cRdData);
                /* Fill uartTxBuffer variable with message containing temperature value to display on terminal */
                sprintf ((char*)uartTxBuffer, "\n\rTemperature = %02d F", temperatureVal);
                /* Check that the SERCOM3 USART is ready for new data */
                while (!SERCOM3_USART_TransmitterIsReady());
                /* Transmit the uartTxBuffer variable content to terminal through SERCOM3 USART peripheral */
                printf("%s", (char *)uartTxBuffer);
                TemperatureReadInitiated = false;
            }
            if(TemperatureReadInitiated == false)
            {
                /* Switch off LED0 */
                LED0_Set ();
                if (sleepMode == IDLE_SLEEP_MODE)
                {
                    sleepMode = STANDBY_SLEEP_MODE;
                    /* Display message on terminal */
                    printf ("\n\rEntering into Idle sleep mode.");
                    /* Put the device in Idle mode */
                    PM_IdleModeEnter ();
                }
                else
                {
                    printf ("\n\rEntering into Standby sleep mode");
                    /* Put device in Standby mode */
                    PM_StandbyModeEnter ();
                }
            }
        }
        else                                        /* Wakeup Time Measurement */
        {
            if(ac_comparison_done)
            {
                ac_comparison_done = false;
                printf ("\n\n\n\rPA04 voltage is above detect level, Wake-up from sleep mode......");
            }
            else
            {
                printf ("\n\n\n\rSW0 Pressed, Wake-up from sleep mode......");
                sleepMode = ((sleepMode == IDLE_SLEEP_MODE) ? STANDBY_SLEEP_MODE : IDLE_SLEEP_MODE);
            }
            /* Switch off LED0 */
            LED0_Set ();
            if (sleepMode == IDLE_SLEEP_MODE)
            {
                /* Display message on terminal */
                printf ("\n\rEntering into Idle sleep mode.");
                /* Put the device in Idle mode */
                PM_IdleModeEnter ();
            }
            else
            {
                printf ("\n\rEntering into Standby sleep mode");
                /* Put device in Standby mode */
                PM_StandbyModeEnter ();
            }
        }
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

