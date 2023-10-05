/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app_cam.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_CAM_Initialize" and "APP_CAM_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_CAM_STATES" definition).  Both
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

#ifndef _APP_CAM_H
#define _APP_CAM_H

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

/*PIR sensor Macros*/
#define PIR_SENSOR_ADDR                     0x4D
#define PIR_MOTION_THRESHOLD                (7.0) 
#define PIR_ADC_MAX                         4095   
#define PIR_ADC_MIN                         0
#define PIR_OUT_MAX                         3303

/* Note: With "APP_PIR_MOTION_DETECTED = 6.0" the PIR Sensor is capable of
 * detecting the motion from distance nearly 4-5 feet and with
 * "APP_PIR_MOTION_DETECTED = 7.0" the motion is detected from a distance
 * nearly 2-3 feet. Configure the value based on the requirement. */
    

/* Reference Year in tm structure year (C standard) */
#define APP_TM_STRUCT_REFERENCE_YEAR           (1900U)

/* Reference Year for FAT FS */
#define APP_FAT_FS_REFERENCE_YEAR              (1980U)

#define BUILD_TIME_HOUR     ((__TIME__[0] - '0') * 10 + __TIME__[1] - '0')
#define BUILD_TIME_MIN      ((__TIME__[3] - '0') * 10 + __TIME__[4] - '0')
#define BUILD_TIME_SEC      ((__TIME__[6] - '0') * 10 + __TIME__[7] - '0')

#define BUILD_MONTH_IS_JAN (__DATE__[0] == 'J' && __DATE__[1] == 'a' && __DATE__[2] == 'n')
#define BUILD_MONTH_IS_FEB (__DATE__[0] == 'F')
#define BUILD_MONTH_IS_MAR (__DATE__[0] == 'M' && __DATE__[1] == 'a' && __DATE__[2] == 'r')
#define BUILD_MONTH_IS_APR (__DATE__[0] == 'A' && __DATE__[1] == 'p')
#define BUILD_MONTH_IS_MAY (__DATE__[0] == 'M' && __DATE__[1] == 'a' && __DATE__[2] == 'y')
#define BUILD_MONTH_IS_JUN (__DATE__[0] == 'J' && __DATE__[1] == 'u' && __DATE__[2] == 'n')
#define BUILD_MONTH_IS_JUL (__DATE__[0] == 'J' && __DATE__[1] == 'u' && __DATE__[2] == 'l')
#define BUILD_MONTH_IS_AUG (__DATE__[0] == 'A' && __DATE__[1] == 'u')
#define BUILD_MONTH_IS_SEP (__DATE__[0] == 'S')
#define BUILD_MONTH_IS_OCT (__DATE__[0] == 'O')
#define BUILD_MONTH_IS_NOV (__DATE__[0] == 'N')
#define BUILD_MONTH_IS_DEC (__DATE__[0] == 'D')


#define BUILD_MONTH \
    ( \
        (BUILD_MONTH_IS_JAN) ?  1 : \
        (BUILD_MONTH_IS_FEB) ?  2 : \
        (BUILD_MONTH_IS_MAR) ?  3 : \
        (BUILD_MONTH_IS_APR) ?  4 : \
        (BUILD_MONTH_IS_MAY) ?  5 : \
        (BUILD_MONTH_IS_JUN) ?  6 : \
        (BUILD_MONTH_IS_JUL) ?  7 : \
        (BUILD_MONTH_IS_AUG) ?  8 : \
        (BUILD_MONTH_IS_SEP) ?  9 : \
        (BUILD_MONTH_IS_OCT) ? 10 : \
        (BUILD_MONTH_IS_NOV) ? 11 : \
        (BUILD_MONTH_IS_DEC) ? 12 : \
        /* error default */  99 \
    )

#define BUILD_DAY \
    ( \
        ((__DATE__[4] >= '0') ? (__DATE__[4] - '0') * 10 : 0) + \
        (__DATE__[5] - '0') \
    )

#define BUILD_YEAR \
    ( \
        (__DATE__[ 7] - '0') * 1000 + \
        (__DATE__[ 8] - '0') *  100 + \
        (__DATE__[ 9] - '0') *   10 + \
        (__DATE__[10] - '0') \
    )

#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
    
    
#define BUF_SIZE    (20 * 1024)
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
    APP_CAM_STATE_INIT=0,
    APP_CAM_STATE_ARDUCAM_RESET,
    APP_CAM_STATE_CHECK_CAMERA,
    APP_CAM_STATE_CAMERA_CONFIG,
    APP_CAM_STATE_SET_JPEG_FORMAT,
    APP_CAM_STATE_SET_RESOLUTION,
    APP_CAM_STATE_PIR_INPUT_READ,
    APP_CAM_STATE_CAPTURE,
    APP_CAM_STATE_CAPTURE_WAIT,
    APP_CAM_STATE_GET_FIFO_JPEG_HEADER,
    APP_CAM_STATE_SAVE_IMAGE_FILE,
    APP_CAM_STATE_CLOSE_FILE,
    APP_CAM_STATE_IDLE,
    APP_CAM_STATE_ERROR

} APP_CAM_STATES;


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
    APP_CAM_STATES state;
    
    DRV_SPI_TRANSFER_SETUP spiSetup;

    DRV_HANDLE  spiHandle;
    
    SYS_FS_HANDLE fileHandle;
    
    SYS_CONSOLE_HANDLE consoleHandle;
    
    SYS_TIME_HANDLE timeHandle;
    
    uint8_t writeReg[2];
    uint8_t readReg[4];
    
    /* FIFO Variables */
    uint32_t fifo_size;
    
    bool status;
    
    /* Buffer to store QVGA data */
    uint8_t captureBuffer[BUF_SIZE];
    
    char input;
    
    /* Stores the Current time from RTCC */
    struct tm rtcTime;

} APP_CAM_DATA;

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
    void APP_CAM_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    APP_CAM_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_CAM_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_CAM_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_CAM_Tasks ( void )

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
    APP_CAM_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_CAM_Tasks( void );

const char* APP_ARDU_CAM_Get_Image_Name(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _APP_CAM_H */

/*******************************************************************************
 End of File
 */

