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

// *****************************************************************************
// *****************************************************************************
// Section: Data Entry
// *****************************************************************************
// *****************************************************************************

/* Define application mode and previous sleep mode variables to switch from different modes */
typedef enum
{
    STDBY_MODE_IRQ,
    STDBY_MODE_EVSYS,
    ACTIVE_MODE
}APP_MODES;

APP_MODES app_mode = STDBY_MODE_IRQ;
APP_MODES previous_sleep_mode;

/* Interrupt Flag for SW0 and DMA */
volatile bool SW0_Flag = false;
volatile bool ADC0_WINMON_Flag = false;

/* RTC Handler */
void RTC_Handler ( void )
{
    /* Unset RTC COMP0 Interrupt flag */
    RTC_REGS->MODE0.RTC_INTFLAG = RTC_MODE0_INTFLAG_CMP0_Msk;
    
    /* Start Conversion on ADC0 AIN12 */
    ADC0_ConversionStart ();
}

/* EIC Callback Routine */
static void EIC_Callback_Routine (uintptr_t context)
{
    /* Set Interrupt Flag for SW0 */
    SW0_Flag = true;
}

/* ADC0 Callback Routine */
static void ADC0_Callback_Routine (ADC_STATUS status, uintptr_t context)
{
    /* Set ADC0_WINMON Flag after Window Monitoring Interrupt */
    ADC0_WINMON_Flag = true;
}

/* Configure RTC to work on Interrupts */
void RTC_Initialize_for_IRQ ( void )
{
    /* RTC Software Reset */
    RTC_REGS->MODE0.RTC_CTRLA = RTC_MODE0_CTRLA_SWRST_Msk;

    /* Wait for RTC synchronization */
    while((RTC_REGS->MODE0.RTC_SYNCBUSY & RTC_MODE0_SYNCBUSY_SWRST_Msk) == RTC_MODE0_SYNCBUSY_SWRST_Msk);
    
    /* RTC 32-bit Mode (Mode 0) - Prescaler = 1 - Count Sync - Clear on Match enabled */
    RTC_REGS->MODE0.RTC_CTRLA = RTC_MODE0_CTRLA_MODE(0) | RTC_MODE0_CTRLA_PRESCALER(0x1) | RTC_MODE0_CTRLA_COUNTSYNC_Msk |RTC_MODE0_CTRLA_MATCHCLR_Msk ;

    /* Set the RTC COMP0 value at 0x147 to generate an Interrupt every 10 ms */
    RTC_Timer32Compare0Set (0x147);

    /* Enable Interrupts on RTC */
    RTC_REGS->MODE0.RTC_INTENSET = 0x0100;
    
    /* Enable RTC Interrupt at core level and Set Priority Level to 7 */
    NVIC_EnableIRQ ( RTC_IRQn );
    NVIC_SetPriority (RTC_IRQn, 7);
}

/* Configure ADC0 to work on Interrupts */
void ADC0_Disable_STARTEI ( void )
{
    /* Disable ADC Conversion Start on Event Input */
    ADC0_REGS->ADC_EVCTRL &= ~ADC_EVCTRL_STARTEI_Msk;
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
    
    /* ADC0 Callback Register on Window Monitoring Events */
    ADC0_CallbackRegister (ADC0_Callback_Routine, (uintptr_t) NULL);
    
    /* Set Voltage Regulator as a Buck Converter */
    SUPC_SelectVoltageRegulator (SUPC_VREGSEL_BUCK);
    
    /* Define EIC Callback Register */
    EIC_CallbackRegister (EIC_PIN_15, EIC_Callback_Routine, (uintptr_t) NULL);

    /* Display example title */
    printf("\n\n\r---------------------------------------------------------");
    printf("\n\r            SleepWalking with Event System               ");
    printf("\n\r---------------------------------------------------------\n\n\r");

    /* Enter in Infinite loop */
    while ( true )
    {
        if (SW0_Flag)
        {
            /* Clear SW0 user button flag */
            SW0_Flag = false;
            
            /* Switch application mode to STDBY_MODE_IRQ if previous sleep mode is STDBY_MODE_EVSYS */
            if (previous_sleep_mode == STDBY_MODE_EVSYS)
            {
                app_mode = STDBY_MODE_IRQ;
            }
            /* Switch application mode to STDBY_MODE_EVSYS if previous sleep mode is STDBY_MODE_IRQ */
            else
            {
                app_mode = STDBY_MODE_EVSYS;
            }
        }
        
        switch (app_mode)
        {
            case ACTIVE_MODE:
                /* Display ACTIVE_MODE message */
                printf ("An ADC Window monitoring interrupt occurred. Wake-up from Standby mode to Active mode.\n\r");
                printf ("Press SW0 button to switch mode.\n\n\r");
                
                /* Start the SysTick timer */
                SYSTICK_TimerStart ();
                
                while (!SW0_Flag)
                {
                    LED0_Toggle ();
                    /* Generate a 200 ms delay */
                    SYSTICK_DelayMs (200);
                }
            
                /* Stop the SysTick timer */
                SYSTICK_TimerStop ();
                
                /* Clear ADC0 Window Monitoring flag and User LED */
                ADC0_WINMON_Flag = false;
                LED0_Set ();
                
                break;
            
            case STDBY_MODE_IRQ:
                /* Display STDBY_MODE_IRQ message */
                printf ("Standby mode with IRQ.\n\r");
                printf ("Press SW0 button to switch mode.\n\n\r");
                    
                /* Configure RTC to works on Interrupts */
                RTC_Initialize_for_IRQ ();
                
                /* Configure ADC0 to works on Interrupts */
                ADC0_Disable_STARTEI ();
                
                /* Enable ADC0 */
                ADC0_Enable ();
    
                /* Start RTC Clock Count */
                RTC_Timer32Start ();
                
                while (!(ADC0_WINMON_Flag | SW0_Flag))
                {
                    /* Put the device in Standby Sleep Mode */
                    PM_StandbyModeEnter ();
                }
                
                /* Clear ADC0 Window Monitoring flag */
                ADC0_WINMON_Flag = false;
                
                /* Set application mode flag to ACTIVE_MODE and save previous sleep mode state */
                app_mode = ACTIVE_MODE;
                previous_sleep_mode = STDBY_MODE_IRQ;
                
                break;
            
            case STDBY_MODE_EVSYS:
                /* Display STDBY_MODE_EVSYS message */
                printf ("Standby mode with Event System.\n\r");
                printf ("Press SW0 button to switch mode.\n\n\r");
                    
                /* Initialize ADC0 to start conversion on RTC COMP0 Event */
                ADC0_Initialize ();
                    
                /* Initialize RTC to generate Events Output */
                RTC_Initialize ();
                    
                /* Enable ADC0 */
                ADC0_Enable ();
    
                /* Start RTC Clock Count */
                RTC_Timer32Start ();
                
                /* Put the device in Standby Sleep Mode */
                PM_StandbyModeEnter ();
                    
                /* Clear ADC0 Window Monitoring flag */
                ADC0_WINMON_Flag = false;
                
                /* Set application mode flag to ACTIVE_MODE and save previous sleep mode state */
                app_mode = ACTIVE_MODE;
                previous_sleep_mode = STDBY_MODE_EVSYS;
                
                break;
        }
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

