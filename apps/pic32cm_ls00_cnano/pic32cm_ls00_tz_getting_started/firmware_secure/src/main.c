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

#define PERIOD_500MS                            512
#define PERIOD_1S                               1024
#define PERIOD_2S                               2048
#define PERIOD_4S                               4096

/* typedef for non-secure callback functions */
typedef void (*funcptr_void) (void) __attribute__((cmse_nonsecure_call));

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
static volatile bool isRTCTimerExpired = false;
static volatile bool changeSamplingRate = false;
static volatile bool printLedToggleRate = false;
//static volatile bool printTempSampleRate = false;

volatile bool readUartTxStatus = false;
uint8_t uartTxTempBuffer[100] = {0};

static const char timeouts[4][20] = {"500 milliSeconds", "1 Second",  "2 Seconds",  "4 Seconds"};

typedef enum
{
    SAMPLING_RATE_500MS = 0,
    SAMPLING_RATE_1S    = 1,
    SAMPLING_RATE_2S    = 2,
    SAMPLING_RATE_4S    = 3,
} SAMPLING_RATE;

static SAMPLING_RATE tempSampleRate = SAMPLING_RATE_500MS;

static void sw1_eventHandler(uintptr_t context)
{
    changeSamplingRate = true;
}

static void rtcEventHandler (RTC_TIMER32_INT_MASK intCause, uintptr_t context)
{
    if (intCause & RTC_TIMER32_INT_MASK_CMP0)
    {
        isRTCTimerExpired = true;
    }
}
void secureApp(void)
{
/* Basic Functionality: Demonstrates an LED toggle, i.e. LED0 toggles when
* the switch SW0 is pressed on a timeout basis and prints the LED toggling
* rate on the serial terminal.*/
    if (printLedToggleRate == true)
    {
        memset((char*)uartTxTempBuffer, 0x00, 100);
        sprintf((char*)uartTxTempBuffer, "************* Printing Toggling LED rate*************\r\n");
        printLedToggleRate = false;
        readUartTxStatus = true;
    }
    if (isRTCTimerExpired == true)
    {
        isRTCTimerExpired = false;
        memset((char*)uartTxTempBuffer, 0x00, 100);
        sprintf((char*)uartTxTempBuffer, "Toggling LED at %s rate \r\n",
        &timeouts[(uint8_t)tempSampleRate][0]);
        LED1_Toggle();
        readUartTxStatus = true;
    }
    if(changeSamplingRate == true)
    {
        changeSamplingRate = false;
        if(tempSampleRate == SAMPLING_RATE_500MS)
        {
        tempSampleRate = SAMPLING_RATE_1S;
        RTC_Timer32CompareSet(PERIOD_1S);
        }
        else if(tempSampleRate == SAMPLING_RATE_1S)
        {
        tempSampleRate = SAMPLING_RATE_2S;
        RTC_Timer32CompareSet(PERIOD_2S);
        }
        else if(tempSampleRate == SAMPLING_RATE_2S)
        {
        tempSampleRate = SAMPLING_RATE_4S;
        RTC_Timer32CompareSet(PERIOD_4S);
        }
        else if(tempSampleRate == SAMPLING_RATE_4S)
        {
        tempSampleRate = SAMPLING_RATE_500MS;
        RTC_Timer32CompareSet(PERIOD_500MS);
        }
        else
        {
        ;
        }
        RTC_Timer32CounterSet(0);
        sprintf((char*)uartTxTempBuffer, "LED Toggling rate is changed to %s\r\n",
        &timeouts[(uint8_t)tempSampleRate][0]);
        readUartTxStatus = true;
    }
}
int main ( void )
{
    uint32_t msp_ns = *((uint32_t *)(TZ_START_NS));
    volatile funcptr_void NonSecure_ResetHandler;

    /* Initialize all modules */
    SYS_Initialize ( NULL );
    RTC_Timer32CallbackRegister(rtcEventHandler, 0);
    EIC_CallbackRegister(EIC_PIN_2, sw1_eventHandler, 0);
    readUartTxStatus = true;

    RTC_Timer32Start();
    if (msp_ns != 0xFFFFFFFF)
    {
        /* Set non-secure main stack (MSP_NS) */
        __TZ_set_MSP_NS(msp_ns);

        /* Get non-secure reset handler */
        NonSecure_ResetHandler = (funcptr_void)(*((uint32_t *)((TZ_START_NS) + 4U)));

        /* Start non-secure state software application */
        NonSecure_ResetHandler();
    }

    while ( true )
    {
        secureApp();
    }

    /* Execution should not come here during normal operation */
    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

