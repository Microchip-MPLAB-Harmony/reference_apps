/****************************************************************************
* Title                 :   Location tagged SOS Application
* Filename              :   app.h
* Author                :   ST
* Origin Date           :   15/08/2018
* Notes                 :   None
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date    Software Version    Initials   Description
*  15/02/18        1.0.0           ST       App Created. 
*  01/01/2020      2.0.0            MK      App Modified.
*****************************************************************************/
/****************************************************************************
* Note: In version 2.00, This file has been modified by MK to meet the custom 
* application requirements. Should you need to contact the modifier, Write an 
* Email to mohan.kumar@microchip.com or alternatively, write to 
* Mohan Kumar, Microchip Technology India Pvt Ltd
* Plot No. 1498, EPIP, 1st Phase Industrial Area, Whitefield, Bengaluru, 
* Karnataka 560066
* Note: In version 1.00, This file has been modified by ST to meet the custom 
* application requirements. Should you need to contact the modifier, Write an 
* Email to syed.thaseemuddin@microchip.com or alternatively, write to 
* Syed Thaseemuddin, Microchip Technology India Pvt Ltd
* Plot No. 1498, EPIP, 1st Phase Industrial Area, Whitefield, Bengaluru, 
* Karnataka 560066
*******************************************************************************/
/**
 * @file app.h
 * @brief Location tagged SOS App
 */
/*******************************************************************************
 Copyright (C) 2017  Microchip Technology Incorporated and its subsidiaries.

This program is free software; you can redistribute it and/or modify it under 
the terms of the GNU General Public License as published by the Free Software 
Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY 
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A 
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with 
this program; if not, write to the Free Software Foundation, Inc., 
51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*******************************************************************************/

#ifndef _APP_H
#define _APP_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "definitions.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************
#define APP_USART_READ_BUFFER_SIZE   500
#define APP_USART_WRITE_BUFFER_SIZE  500
// *****************************************************************************
/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/
      

typedef enum
{
	/* Application's state machine's initial state. */
	APP_STATE_INIT=0,
    APP_STATE_GSM_GPS_INIT_COMPLETE,
	APP_STATE_SERVICE_TASKS,
    APP_STATE_IDLE

	/* TODO: Define states used by the application state machine. */

} APP_STATES;

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
    /* The application's current state */
    APP_STATES state;
    bool ignoreButtonPress;
    bool tmrEventHasOccurred;
    /* USART driver handle */

    /* USART buffer for display */
    uint16_t writeBufferCount;
    uint16_t readBufferCount;
    char writeBuffer[APP_USART_WRITE_BUFFER_SIZE];
    char readBuffer[APP_USART_READ_BUFFER_SIZE];
    /* Data Size in the USART Buffer */
    uint32_t bufferSize;

} APP_DATA;


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    APP_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_Tasks ( void )

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_Tasks( void );

void EIC_User_Handler(uintptr_t context);
void TC4_Callback_InterruptHandler(TC_TIMER_STATUS status, uintptr_t context);
char* my_strncpy(char* dst, const char* src, size_t n);
#endif /* _APP_H */

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

