/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app_nonsecure_deadbolt_control.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_NONSECURE_DEADBOLT_CONTROL_Initialize" and "APP_NONSECURE_DEADBOLT_CONTROL_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_NONSECURE_DEADBOLT_CONTROL_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************************
* Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.

 * Subject to your compliance with these terms, you may use this Microchip software
 * and any derivatives exclusively with Microchip products. You are responsible for
 * complying with third party license terms applicable to your use of third party
 * software (including open source software) that may accompany this Microchip software.

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
 *******************************************************************************************/
// DOM-IGNORE-END

#ifndef _APP_NONSECURE_DEADBOLT_CONTROL_H
#define _APP_NONSECURE_DEADBOLT_CONTROL_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "configuration.h"
#include "definitions.h"                // SYS function prototypes
#include <string.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Global Definitions
// *****************************************************************************
// *****************************************************************************    
    
#define LIMIT_SW_USED 1

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

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
    APP_NONSECURE_DEADBOLT_CONTROL_STATE_INIT=0,
    APP_NONSECURE_DEADBOLT_CONTROL_STATE_OPEN,
    APP_NONSECURE_DEADBOLT_CONTROL_STATE_CLOSE,
    APP_NONSECURE_DEADBOLT_CONTROL_STATE_UPDATE_STATUS_TO_APP,
    APP_NONSECURE_DEADBOLT_CONTROL_STATE_USERALERT,
    APP_NONSECURE_DEADBOLT_CONTROL_STATE_WAIT
} APP_NONSECURE_DEADBOLT_CONTROL_STATES;


// *****************************************************************************
/* Door lock state

  Summary:
    Enumeration to describe door's status

  Description:
    This enumeration defines the status of the door lock.
*/
typedef enum
{
    APP_NONSECURE_DEADBOLT_CONTROL_DOOR_OPENED = 0,
    APP_NONSECURE_DEADBOLT_CONTROL_DOOR_CLOSED,
    APP_NONSECURE_DEADBOLT_CONTROL_DOOR_OPEN_TIMEOUT,
    APP_NONSECURE_DEADBOLT_CONTROL_DOOR_BUSY,
    APP_NONSECURE_DEADBOLT_CONTROL_DOOR_UNDEFINED
}APP_NONSECURE_DEADBOLT_CONTROL_DOOR_STATE;


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
    APP_NONSECURE_DEADBOLT_CONTROL_STATES state;
    
    APP_NONSECURE_DEADBOLT_CONTROL_DOOR_STATE door_state;
    
    SYS_TIME_HANDLE sys_time_handle;


    /* TODO: Define any additional data used by the application. */

} APP_NONSECURE_DEADBOLT_CONTROL_DATA;

APP_NONSECURE_DEADBOLT_CONTROL_DATA app_db_motorData;

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
    void APP_NONSECURE_DEADBOLT_CONTROL_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    APP_NONSECURE_DEADBOLT_CONTROL_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_NONSECURE_DEADBOLT_CONTROL_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_NONSECURE_DEADBOLT_CONTROL_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_NONSECURE_DEADBOLT_CONTROL_Tasks ( void )

  Summary:
   Deadbolt motor tasks function

  Description:
    This routine controls the deadbolt motor based on user inputs
 * 
  Precondition:
 None.
  Parameters:
    None.

  Returns:
    None.
 */

void APP_NONSECURE_DEADBOLT_CONTROL_Tasks( void );


/*******************************************************************************
  Function:
    void APP_NONSECURE_DEADBOLT_CONTROL_MotorClose ( void )

  Summary:
   Deadbolt motor close function

  Description:
    This routine drives the motor to close the deadbolt
 * 
  Precondition:
     None.
  Parameters:
    None.
  Returns:
    None.
 */

void APP_NONSECURE_DEADBOLT_CONTROL_MotorClose ( void );


/*******************************************************************************
  Function:
    void APP_NONSECURE_DEADBOLT_CONTROL_MotorOpen ( void )

  Summary:
   Deadbolt motor Open function

  Description:
    This routine drives the motor to open the deadbolt
 * 
  Precondition:
     None.
  Parameters:
    None.
  Returns:
    None.
 */

void APP_NONSECURE_DEADBOLT_CONTROL_MotorOpen ( void );

/*******************************************************************************
  Function:
    void APP_NONSECURE_DEADBOLT_CONTROL_Callback(uintptr_t)

  Summary:
   Motor control Callback 

  Description:
    This routine is called after completion of the open or close of the deadbolt, when the motor drive needs to be stopped.
 * 
  Precondition:
     None.
  Parameters:
     Context of the current state of motor drive
  Returns:
    None.
 */

void APP_NONSECURE_DEADBOLT_CONTROL_Callback(uintptr_t context);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _APP_NONSECURE_DEADBOLT_CONTROL_H */

/*******************************************************************************
 End of File
 */

