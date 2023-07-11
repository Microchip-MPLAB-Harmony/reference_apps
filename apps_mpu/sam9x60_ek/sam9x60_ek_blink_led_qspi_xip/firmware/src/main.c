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
char messageStart[] = "\n\n**** This application is getting executed from QSPI-offset 0x40000(0x70040000).\r\n **** Blue LED turns ON when user input key is pressed****\r\n\n";
int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    DBGU_Write(&messageStart, sizeof(messageStart));
    while(DBGU_WriteIsBusy());
    while ( true )
    {
        
        /* Maintain state machines of all polled MPLAB Harmony modules. */
         SYS_Tasks ( );
         LED_BLUE_Off();
         if(SW1_Get()==SW1_STATE_PRESSED)
         {         
            LED_BLUE_On();
         }
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

