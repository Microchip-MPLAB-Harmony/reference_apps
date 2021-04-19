/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app_ov2640_sensor.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_OV2640_SENSOR_Initialize" and "APP_OV2640_SENSOR_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_OV2640_SENSOR_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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
//DOM-IGNORE-END

#ifndef _APP_OV2640_SENSOR_H
#define _APP_OV2640_SENSOR_H

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
#include "driver/i2c/drv_i2c.h"
#include "system/console/sys_console.h"

#define APP_RECEIVE_DATA_LENGTH             2
#define APP_RECEIVE_DUMMY_WRITE_LENGTH      1

#define APP_OV2640_SENSOR_ADDR              (0x60 >> 1)
#define APP_OV2640_REG_ADDR                 0x00

#define OV2640_160x120                      0	//160x120
#define OV2640_176x144                      1	//176x144
#define OV2640_320x240                      2	//320x240
#define OV2640_352x288                      3	//352x288
#define OV2640_640x480                      4	//640x480
#define OV2640_800x600                      5	//800x600
#define OV2640_1024x768                     6	//1024x768
#define OV2640_1280x1024                    7	//1280x1024
#define OV2640_1600x1200                    8	//1600x1200

#define APP_OV2640_SENSOR_DELAY             100

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
    APP_OV2640_SENSOR_STATE_INIT=0,
    APP_OV2640_SENSOR_STATE_CHECK_SENSOR_TYPE,
    APP_OV2640_SENSOR_STATE_WRITE_CTRL_REG_COM7,
    APP_OV2640_SENSOR_STATE_MEDIA_JPEG_INIT,
    APP_OV2640_SENSOR_STATE_MEDIA_YUV422,
    APP_OV2640_SENSOR_STATE_MEDIA_JPEG,
    APP_OV2640_SENSOR_STATE_WRITE_CTRL_REG_COM10,
    APP_OV2640_SENSOR_STATE_MEDIA_320x240_JPEG,
    APP_OV2640_SENSOR_STATE_SERVICE_TASKS,
    APP_OV2640_SENSOR_STATE_XFER_ERROR,
    APP_OV2640_SENSOR_STATE_SUCCESS,
    /* TODO: Define states used by the application state machine. */

} APP_OV2640_SENSOR_STATES;


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
    APP_OV2640_SENSOR_STATES state;

    /* TODO: Define any additional data used by the application. */
    DRV_HANDLE drvI2CHandle;

    uint8_t txBuffer[APP_RECEIVE_DATA_LENGTH];

    uint8_t vid;    // To check the camera module type is OV2640

    uint8_t pid;    // To check the camera module type is OV2640

    volatile bool ov2640SensorInit;
} APP_OV2640_SENSOR_DATA;

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
    void APP_OV2640_SENSOR_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    APP_OV2640_SENSOR_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_OV2640_SENSOR_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_OV2640_SENSOR_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_OV2640_SENSOR_Tasks ( void )

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
    APP_OV2640_SENSOR_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_OV2640_SENSOR_Tasks( void );

/*******************************************************************************
  Function:
    bool APP_OV2640_SENSOR_Task_GetStatus ( void )

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
    true - OV2640 Sensor Task is initialized completely.
    false - OV2640 Sensor Task is not initialized completely.

  Example:
    <code>
    bool status = false;

    status = APP_OV2640_SENSOR_Task_GetStatus();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

bool APP_OV2640_SENSOR_Task_GetStatus(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _APP_OV2640_SENSOR_H */

/*******************************************************************************
 End of File
 */

