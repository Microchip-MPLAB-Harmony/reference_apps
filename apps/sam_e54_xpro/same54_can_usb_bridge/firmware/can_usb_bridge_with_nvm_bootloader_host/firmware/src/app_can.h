/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app_can.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_CAN_Initialize" and "APP_CAN_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_CAN_STATES" definition).  Both
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

#ifndef _APP_CAN_H
#define _APP_CAN_H

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
#include "common.h"
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
    APP_CAN_STATE_INIT=0,

    /* Application waits for device configuration*/
    APP_CAN_STATE_WAIT_FOR_CONFIGURATION,

    /* Wait for a character receive */
    APP_CAN_STATE_SCHEDULE_READ,

    /* A character is received from host */
    APP_CAN_STATE_WAIT_FOR_READ,
            
    /* CAN read is completed */
    APP_CAN_STATE_READ_COMPLETE,

    /* Wait for the TX to get completed */
    APP_CAN_STATE_SCHEDULE_WRITE,

    /* Wait for the write to complete */
    APP_CAN_STATE_WAIT_FOR_WRITE_COMPLETE,
    
    /* Application Idle state*/
    APP_CAN_STATE_IDLE,

    /* Application Error state*/
    APP_CAN_STATE_ERROR

} APP_CAN_STATES;


// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */


/* Variable to save application state */
volatile static APP_CAN_STATES state = APP_CAN_STATE_INIT;

//uint8_t Can1MessageRAM[CAN1_MESSAGE_RAM_CONFIG_SIZE] __attribute__((aligned (32)));

typedef struct
{
    /* The application's current state */
    APP_CAN_STATES state;
    
    /* CAN data is ready to be sent via USB */
    bool is_CAN_Rx_DataReady;
    
    bool is_CAN_Data_Tx;
    
    uint8_t message_count;
    
    /* Test Counter */
  //  uint32_t testCounter;
    uint8_t *can_data;

} APP_CAN_DATA;

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
    void APP_CAN_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    APP_CAN_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_CAN_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_CAN_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_CAN_Tasks ( void )

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
    APP_CAN_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_CAN_Tasks( void );

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _APP_CAN_H */

/*******************************************************************************
 End of File
 */

