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

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
extern int secureAppEntry(void);
int32_t lightSensorData;
static volatile bool readSensorData = false;
volatile bool sendToCloud = false;
// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
static void sw0_eventHandler(uintptr_t context)
{
    readSensorData = true;
}

static void sw1_eventHandler(uintptr_t context)
{
    readSensorData = false;
    sendToCloud = false;
}
int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    EIC_CallbackRegister(EIC_PIN_12, sw0_eventHandler, 0);
    EIC_CallbackRegister(EIC_PIN_4, sw1_eventHandler, 0);
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        
        if (readSensorData == true)
        {
         lightSensorData = secureAppEntry();
         sendToCloud = true;
        }
       
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

