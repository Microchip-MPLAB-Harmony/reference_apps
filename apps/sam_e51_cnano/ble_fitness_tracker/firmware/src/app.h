/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/
// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END
#ifndef APP_H
#define APP_H

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
#include "system/time/sys_time.h"
#include "peripheral/eic/plib_eic.h"
#include "peripheral/port/plib_port.h"
#include "definitions.h"
#include "custom_bt/bm71/custom_bm71.h"

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
    /* Initial state. */
    APP_INIT_STATE,

    /* Checking, is Heartrate 9 data ready */
    CHKNG_HEART_RATE_DATA_RDY_STATE,

    /* Process the Heartrate 9 sensor read data */
    HEART_RATE_SENSOR_DATA_PROSS_STATE,

    /* Error state */
    EINK_EPAPER_2_9_296_128_UPDATE_STATE,

    /* Idle state */
    APP_IDLE_STATE,

} APP_STATES;

#define QUERY_DELAY        500        // 1/2 sec

typedef struct
{
    /* The application's current state */
    volatile bool transferStatus;
       
    uint16_t queryDelay;
    
    bool waitingToConnect;
    APP_STATES app_state;
    uint16_t waitingToConnectTimer;
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

// make boards with multiple switches/LEDs compatible with those with just one
#ifdef LED1_On
#define LED_On                 LED1_On
#define LED_Off                LED1_Off
#define LED_Toggle             LED1_Toggle
#else
#define LED1_On                CNANO_LED_Set
#define LED1_Off               CNANO_LED_Clear
#define LED1_Toggle            CNANO_LED_Toggle
#endif

// *****************************************************************************
/*** Bluetooth Driver Configuration ***/

#define CUSTOM_BM71_CLIENTS_NUMBER                 1
   
/* Bluetooth Driver Abstraction definition */
#define CUSTOM_BT_Initialize                       CUSTOM_BM71_Initialize
#define CUSTOM_BT_Status                           CUSTOM_BM71_Status
#define CUSTOM_BT_Tasks                            CUSTOM_BM71_Tasks
#define CUSTOM_BT_Open                             CUSTOM_BM71_Open
#define CUSTOM_BT_Close                            CUSTOM_BM71_Close
#define CUSTOM_BT_EventHandlerSet                  CUSTOM_BM71_EventHandlerSet
#define CUSTOM_BT_GetPowerStatus                   CUSTOM_BM71_GetPowerStatus

#define CUSTOM_BT_EVENT_HANDLER                    CUSTOM_BM71_EVENT_HANDLER
#define CUSTOM_BT_EVENT                            CUSTOM_BM71_EVENT
#define CUSTOM_BT_EVENT_BLESPP_MSG_RECEIVED        CUSTOM_BM71_EVENT_BLESPP_MSG_RECEIVED
#define CUSTOM_BT_EVENT_BLE_STATUS_CHANGED         CUSTOM_BM71_EVENT_BLE_STATUS_CHANGED

#define CUSTOM_BT_PROTOCOL_BLE                     CUSTOM_BM71_PROTOCOL_BLE               
#define CUSTOM_BT_PROTOCOL                         CUSTOM_BM71_PROTOCOL

#define CUSTOM_BT_STATUS_READY                     CUSTOM_BM71_STATUS_READY

#define CUSTOM_BT_BLE_STATUS                       CUSTOM_BM71_BLE_STATUS
#define CUSTOM_BT_BLE_STATUS_STANDBY               CUSTOM_BM71_BLE_STATUS_STANDBY
#define CUSTOM_BT_BLE_STATUS_ADVERTISING           CUSTOM_BM71_BLE_STATUS_ADVERTISING
#define CUSTOM_BT_BLE_STATUS_SCANNING              CUSTOM_BM71_BLE_STATUS_SCANNING
#define CUSTOM_BT_BLE_STATUS_CONNECTED             CUSTOM_BM71_BLE_STATUS_CONNECTED

#define CUSTOM_BT_ClearBLEData                     CUSTOM_BM71_ClearBLEData
#define CUSTOM_BT_ReadDataFromBLE                  CUSTOM_BM71_ReadDataFromBLE
#define CUSTOM_BT_SendDataOverBLE                  CUSTOM_BM71_SendDataOverBLE

#define CUSTOM_BT_BLE_QueryStatus                  CUSTOM_BM71_BLE_QueryStatus
#define CUSTOM_BT_BLE_EnableAdvertising            CUSTOM_BM71_BLE_EnableAdvertising

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END


#endif /* APP_H */
/*******************************************************************************
 End of File
 */

