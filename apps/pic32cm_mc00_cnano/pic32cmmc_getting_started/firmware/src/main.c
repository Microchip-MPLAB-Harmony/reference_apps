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
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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


/* RTC Time period match values for input clock of 1 KHz */
#define PERIOD_500MS                            512
#define PERIOD_1S                               1024
#define PERIOD_2S                               2048
#define PERIOD_4S                               4096

typedef enum
{
    TEMP_SAMPLING_RATE_500MS = 0,
    TEMP_SAMPLING_RATE_1S = 1,
    TEMP_SAMPLING_RATE_2S = 2,
    TEMP_SAMPLING_RATE_4S = 3,
} TEMP_SAMPLING_RATE;
static TEMP_SAMPLING_RATE tempSampleRate = TEMP_SAMPLING_RATE_500MS;
static const char timeouts[4][20] = {"500 milliSeconds", "1 Second",  "2 Seconds",  "4 Seconds"};

static volatile bool isRTCExpired = false;
static volatile bool changeTempSamplingRate = false;
static volatile bool isUSARTTxComplete = true;
static uint8_t uartTxBuffer[100] = {0};

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
static void EIC_User_Handler(uintptr_t context)
{
    changeTempSamplingRate = true;
}

static void usartDmaChannelHandler(DMAC_TRANSFER_EVENT event, uintptr_t contextHandle)
{
    if (event == DMAC_TRANSFER_EVENT_COMPLETE)
    {
        isUSARTTxComplete = true;
    }
}

static void rtcEventHandler (RTC_TIMER32_INT_MASK intCause, uintptr_t context)
{
    if (intCause & RTC_MODE0_INTENSET_CMP0_Msk)
    {            
        isRTCExpired    = true;
    }
}

int main ( void )
{
    uint8_t uartLocalTxBuffer[100] = {0};
    
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    EIC_CallbackRegister(EIC_PIN_6,EIC_User_Handler, 0);
    DMAC_ChannelCallbackRegister(DMAC_CHANNEL_0, usartDmaChannelHandler, 0);
    RTC_Timer32CallbackRegister(rtcEventHandler, 0);
    
    sprintf((char*)uartTxBuffer, "Toggling LED at 500 milliseconds rate \r\n");
    RTC_Timer32Start();
    
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */

        if ((isRTCExpired == true)&& (true == isUSARTTxComplete))
        {
            isRTCExpired = false;
            isUSARTTxComplete = false;
            LED0_Toggle();
            DMAC_ChannelTransfer(DMAC_CHANNEL_0, uartTxBuffer, \
                    (const void *)&(SERCOM1_REGS->USART_INT.SERCOM_DATA), \
                    strlen((const char*)uartTxBuffer));
        }
        
        /* Maintain state machines of all polled MPLAB Harmony modules. */
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
                    (const void *)&(SERCOM1_REGS->USART_INT.SERCOM_DATA), \
                    strlen((const char*)uartLocalTxBuffer));
            sprintf((char*)uartTxBuffer, "Toggling LED at %s rate \r\n", &timeouts[(uint8_t)tempSampleRate][0]);
        }        
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

