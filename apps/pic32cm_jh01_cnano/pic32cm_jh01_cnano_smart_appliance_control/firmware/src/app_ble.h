/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app_ble.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_BLE_Initialize" and "APP_BLE_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_BLE_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

#ifndef _APP_BLE_H
#define _APP_BLE_H

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
    APP_BLE_STATE_INIT=0,
    APP_BLE_STATE_SERVICE_TASKS,
    APP_BLE_WAIT_FOR_CONNECTION,
    APP_BLE_STATE_GET_LOCAL_INFO,
    APP_BLE_STATE_GET_FIRMWARE_VERS,
    APP_BLE_STATE_ADVERTISEMENT,
    APP_START_CONNECTION,
    APP_BLE_STATE_CONNECTED,
    APP_BLE_STATE_WRITE_DATA,
    APP_BLE_STATE_COMPLETE,
    /* TODO: Define states used by the application state machine. */

} APP_BLE_STATES;


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
    APP_BLE_STATES state;
     
} APP_BLE_DATA;


void APP_BLE_Initialize ( void );

void APP_BLE_Tasks( void );


#endif /* _APP_BLE_H */

/*******************************************************************************
 End of File
 */

