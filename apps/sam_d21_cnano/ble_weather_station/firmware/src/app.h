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
#include "definitions.h"
#include "custom_bt/driver/bm71/custom_drv_bm71.h"
#include "ble_app_sensor_data.h"
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
	APP_STATE_INIT=0,
    APP_STATE_WAIT_INIT,
    APP_STATE_IDLE,            
} APP_STATES;      

#define QUERY_DELAY        500        // 1/2 sec

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
    
    /* handle to opened timer */
    DRV_HANDLE tmrHandle;
       
    uint16_t queryDelay;
    
    bool waitingToConnect;
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

void APP_Sensor_Tasks( void );

// make boards with multiple switches/LEDs compatible with those with just one
#ifdef LED1_On
#define LED_On                 LED1_On
#define LED_Off                LED1_Off
#define LED_Toggle             LED1_Toggle
#else
#define LED1_On                LED_Set
#define LED1_Off               LED_Clear
#define LED1_Toggle            LED_Toggle
#endif

#endif /* APP_H */

/*** Bluetooth Driver Configuration ***/

#define DRV_BM71_CLIENTS_NUMBER                 1
   
/* Bluetooth Driver Abstraction definition */
#define DRV_BT_Initialize                       DRV_BM71_Initialize
#define DRV_BT_Status                           DRV_BM71_Status
#define DRV_BT_Tasks                            DRV_BM71_Tasks
#define DRV_BT_Open                             DRV_BM71_Open
#define DRV_BT_Close                            DRV_BM71_Close
#define DRV_BT_EventHandlerSet                  DRV_BM71_EventHandlerSet
#define DRV_BT_GetPowerStatus                   DRV_BM71_GetPowerStatus

#define DRV_BT_EVENT_HANDLER                    DRV_BM71_EVENT_HANDLER
#define DRV_BT_EVENT                            DRV_BM71_EVENT
#define DRV_BT_EVENT_BLESPP_MSG_RECEIVED        DRV_BM71_EVENT_BLESPP_MSG_RECEIVED
#define DRV_BT_EVENT_BLE_STATUS_CHANGED         DRV_BM71_EVENT_BLE_STATUS_CHANGED

#define DRV_BT_PROTOCOL_BLE                     DRV_BM71_PROTOCOL_BLE               
#define DRV_BT_PROTOCOL                         DRV_BM71_PROTOCOL

#define DRV_BT_STATUS_READY                     DRV_BM71_STATUS_READY

#define DRV_BT_BLE_STATUS                       DRV_BM71_BLE_STATUS
#define DRV_BT_BLE_STATUS_STANDBY               DRV_BM71_BLE_STATUS_STANDBY
#define DRV_BT_BLE_STATUS_ADVERTISING           DRV_BM71_BLE_STATUS_ADVERTISING
#define DRV_BT_BLE_STATUS_SCANNING              DRV_BM71_BLE_STATUS_SCANNING
#define DRV_BT_BLE_STATUS_CONNECTED             DRV_BM71_BLE_STATUS_CONNECTED

#define DRV_BT_ClearBLEData                     DRV_BM71_ClearBLEData
#define DRV_BT_ReadDataFromBLE                  DRV_BM71_ReadDataFromBLE
#define DRV_BT_SendDataOverBLE                  DRV_BM71_SendDataOverBLE
#define DRV_BT_CustomSendDataOverBLE            DRV_BM71_CustomSendDataOverBLE
#define DRV_BT_BLE_QueryStatus                  DRV_BM71_BLE_QueryStatus
#define DRV_BT_BLE_EnableAdvertising            DRV_BM71_BLE_EnableAdvertising


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

