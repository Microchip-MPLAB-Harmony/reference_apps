/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app_sensor.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_SENSOR_Initialize" and "APP_SENSOR_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_SENSOR_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

#ifndef _APP_SENSOR_H
#define _APP_SENSOR_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "configuration.h"
#include "driver/i2c/drv_i2c.h"
#include "driver/usart/drv_usart.h"
#include "system/time/sys_time.h"
#include "peripheral/usart/plib_usart1.h"
#include "peripheral/pio/plib_pio.h"
#include "app_eeprom.h"


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
    APP_SENSOR_STATE_INIT,                
    APP_SENSOR_STATE_READ_TEMPERATURE,                        
    APP_SENSOR_STATE_PRINT_TEMPERATURE,                                    
    APP_SENSOR_STATE_IDLE,                                                
    APP_SENSOR_STATE_ERROR
} APP_SENSOR_STATES;


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
    APP_SENSOR_STATES  state;     
    DRV_HANDLE i2cHandle;       
    SYS_TIME_HANDLE sysTimeHandle;
    DRV_I2C_TRANSFER_SETUP i2cSetup;         
    DRV_I2C_TRANSFER_HANDLE transferHandle;       
    uint8_t i2cTxBuffer[1];     
    uint8_t i2cRxBuffer[2];         
    uint8_t usartTxBuffer[30];     
    volatile bool isTemperatureReadComplete;
    volatile bool isTimerExpired;    
    int8_t temperature;     
} APP_SENSOR_DATA;


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
    void APP_SENSOR_Initialize ( void )

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
    APP_SENSOR_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_SENSOR_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_SENSOR_Tasks ( void )

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
    APP_SENSOR_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_SENSOR_Tasks( void );



#endif /* _APP_SENSOR_H */

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

