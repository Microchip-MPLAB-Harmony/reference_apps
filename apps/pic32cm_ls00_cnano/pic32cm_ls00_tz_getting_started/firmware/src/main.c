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
#include "trustZone/nonsecure_entry.h"

static volatile bool isUSARTTxComplete = false;
static uint8_t nonSecureUartTxBuffer[100] = {0};
// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
static void usartTxDmaChannelHandler(DMAC_TRANSFER_EVENT event, uintptr_t contextHandle)
{
    if (event == DMAC_TRANSFER_EVENT_COMPLETE)
    {
        isUSARTTxComplete = true;
    }
}
int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    DMAC_ChannelCallbackRegister(DMAC_CHANNEL_0, usartTxDmaChannelHandler, 0);
    while ( true )
    {
        
        if (readUartTxData(nonSecureUartTxBuffer) == true)
        {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
            DMAC_ChannelTransfer(DMAC_CHANNEL_0, nonSecureUartTxBuffer, \
                    (const void *)&(SERCOM3_REGS->USART_INT.SERCOM_DATA), \
                    strlen((const char*)nonSecureUartTxBuffer));
        }
        secureAppEntry();
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/




/*******************************************************************************
 End of File
*/

