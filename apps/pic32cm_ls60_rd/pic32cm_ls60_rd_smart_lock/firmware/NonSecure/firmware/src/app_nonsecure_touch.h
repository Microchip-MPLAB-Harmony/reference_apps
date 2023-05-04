/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app_nonsecure_touch.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_NONSECURE_TOUCH_Initialize" and "APP_NONSECURE_TOUCH_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_NONSECURE_TOUCH_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.

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

#ifndef _APP_NONSECURE_TOUCH_H
#define _APP_NONSECURE_TOUCH_H

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
    APP_NONSECURE_TOUCH_STATE_INIT,
    APP_NONSECURE_TOUCH_STATE_MEASURE,
    APP_NONSECURE_TOUCH_STATE_LUMP_MEASURE,
    APP_NONSECURE_TOUCH_STATE_READ,
    APP_NONSECURE_TOUCH_STATE_DISABLE,
    APP_NONSECURE_TOUCH_STATE_UPDATE_LED,        
    APP_NONSECURE_TOUCH_STATE_ENABLE_WAIT
    /* TODO: Define states used by the application state machine. */

} APP_NONSECURE_TOUCH_STATES;


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
    APP_NONSECURE_TOUCH_STATES state;

    /* TODO: Define any additional data used by the application. */

} APP_NONSECURE_TOUCH_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/

/*******************************************************************************
  Function:
    void APP_NONSECURE_BLEWakeCallback(void)

  Summary:
   Callback triggered by BLE wakeup interrupt
  Returns:
    None.
 */

void APP_NONSECURE_BLEWakeCallback ( void );
// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_NONSECURE_TOUCH_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    APP_NONSECURE_TOUCH_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_NONSECURE_TOUCH_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function. */

void APP_NONSECURE_TOUCH_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_NONSECURE_TOUCH_Tasks ( void )

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
    APP_NONSECURE_TOUCH_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_NONSECURE_TOUCH_Tasks( void );


// *****************************************************************************
// *****************************************************************************
// Section: Application Local functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_NONSECURE_TOUCH_Backlight(bool backlight)

  Summary:  
    Used to turn on and off the touch keypad's backlight
  Returns:
    None.
 */
void APP_NONSECURE_TOUCH_Backlight (bool backlight);

/*******************************************************************************
  Function:
    void APP_NONSECURE_TOUCH_Backlight_FalseBlink(void)

  Summary:
    Blinks the touch keypad's backlight several times, as an indication of a false input
  Returns:
    None.
 */
void APP_NONSECURE_TOUCH_Backlight_FalseBlink (void);

/*******************************************************************************
  Function:
    void APP_NONSECURE_TOUCH_BuzzerOffCallback(uintptr_t context)

  Summary:
   Callback triggered after a specified timeout, to turn off the Buzzer
  Returns:
    None.
 */
void APP_NONSECURE_TOUCH_BuzzerOffCallback(uintptr_t context);

/*******************************************************************************
  Function:
    void APP_NONSECURE_TOUCH_BuzzerOn(uint16_t time_ms)

  Summary:
     Turn on the buzzer
  Returns:
    None.
 */
void APP_NONSECURE_TOUCH_BuzzerOn(uint16_t time_ms);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _APP_TOUCH_H */

/*******************************************************************************
 End of File
 */

