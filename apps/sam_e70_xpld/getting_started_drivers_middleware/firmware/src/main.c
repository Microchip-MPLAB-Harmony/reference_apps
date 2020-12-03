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


// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );

    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
    }

    /* Execution should not come here during normal operation */
    return ( EXIT_FAILURE );
}

/*
 * Example Help:
 * 1. Connect the IO1 Xplained Pro to the SAME70 Xplained using the EXT1 
 *    connector.
 * 2. Connect the DEBUG USB Port to your computer using a Micro-USB Cable.
 * 3. Flash the SAME70 Xplained using the Make and Program Button
 * 4. Connect the TARGET USB port to your computer using a Micro-USB Cable
 * 5. Open the USB Serial Port using your preferred terminal (e.g. Tera Term)
 * 6. Once connected, send h/H to bring up the help menu.
 */

/*******************************************************************************
 End of File
*/

