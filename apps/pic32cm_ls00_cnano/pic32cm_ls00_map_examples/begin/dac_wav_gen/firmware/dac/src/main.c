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
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
#define NUM_OF_SAMPLES (100)

typedef enum 
{    
    SINE_WAVE,
    TRIANGLE_WAVE
} WAVE_TYPE; 

volatile WAVE_TYPE wave = SINE_WAVE;
volatile uint8_t sample_number = 0;

const uint16_t sine_wave[NUM_OF_SAMPLES] = {
0x800,0x880,0x900,0x97f,0x9fd,0xa78,0xaf1,0xb67,0xbda,0xc49,
0xcb3,0xd19,0xd79,0xdd4,0xe29,0xe78,0xec0,0xf02,0xf3c,0xf6f,
0xf9b,0xfbf,0xfdb,0xfef,0xffb,0xfff,0xffb,0xfef,0xfdb,0xfbf,
0xf9b,0xf6f,0xf3c,0xf02,0xec0,0xe78,0xe29,0xdd4,0xd79,0xd19,
0xcb3,0xc49,0xbda,0xb67,0xaf1,0xa78,0x9fd,0x97f,0x900,0x880,
0x800,0x77f,0x6ff,0x680,0x602,0x587,0x50e,0x498,0x425,0x3b6,
0x34c,0x2e6,0x286,0x22b,0x1d6,0x187,0x13f,0xfd,0xc3,0x90,
0x64,0x40,0x24,0x10,0x4,0x0,0x4,0x10,0x24,0x40,
0x64,0x90,0xc3,0xfd,0x13f,0x187,0x1d6,0x22b,0x286,0x2e6,
0x34c,0x3b6,0x425,0x498,0x50e,0x587,0x602,0x680,0x6ff,0x77f,
};

const uint16_t triangle_wave[NUM_OF_SAMPLES] = {
0x52,0xa4,0xf6,0x148,0x19a,0x1eb,0x23d,0x28f,0x2e1,0x333,
0x385,0x3d7,0x429,0x47b,0x4cd,0x51e,0x570,0x5c2,0x614,0x666,
0x6b8,0x70a,0x75c,0x7ae,0x800,0x851,0x8a3,0x8f5,0x947,0x999,
0x9eb,0xa3d,0xa8f,0xae1,0xb33,0xb84,0xbd6,0xc28,0xc7a,0xccc,
0xd1e,0xd70,0xdc2,0xe14,0xe66,0xeb7,0xf09,0xf5b,0xfad,0xfff,
0x52,0xa4,0xf6,0x148,0x19a,0x1eb,0x23d,0x28f,0x2e1,0x333,
0x385,0x3d7,0x429,0x47b,0x4cd,0x51e,0x570,0x5c2,0x614,0x666,
0x6b8,0x70a,0x75c,0x7ae,0x800,0x851,0x8a3,0x8f5,0x947,0x999,
0x9eb,0xa3d,0xa8f,0xae1,0xb33,0xb84,0xbd6,0xc28,0xc7a,0xccc,
0xd1e,0xd70,0xdc2,0xe14,0xe66,0xeb7,0xf09,0xf5b,0xfad,0xfff,
};

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

void TC0_CallBack_Function (TC_TIMER_STATUS status, uintptr_t context)
{ 
    if ((DAC_IsReady(DAC_CHANNEL_0) == true))
    {	
		if (wave == SINE_WAVE)
		{
            DAC_DataWrite (DAC_CHANNEL_0, sine_wave[sample_number]);
		}
		else
		{
            DAC_DataWrite (DAC_CHANNEL_0, triangle_wave[sample_number]);
		}	

        sample_number++;

        if (sample_number >= 100)
        {
           sample_number = 0;
        }
    }
}

void Button_CallBack_Function (uintptr_t context)
{ 
    (wave == SINE_WAVE)?(wave = TRIANGLE_WAVE):(wave = SINE_WAVE);
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
    EIC_CallbackRegister(EIC_PIN_2,Button_CallBack_Function, 0);
    TC0_TimerCallbackRegister(TC0_CallBack_Function, (uintptr_t)NULL);
    TC0_TimerStart();
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}



/*******************************************************************************
 End of File
*/

