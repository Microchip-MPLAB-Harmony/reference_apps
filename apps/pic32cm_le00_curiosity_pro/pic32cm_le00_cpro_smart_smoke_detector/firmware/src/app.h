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
/*
    (c) 2021 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/
// DOM-IGNORE-END
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
#include "configuration.h"
#include "rnbd/rnbd.h"
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
/* Application states*/
/* SD Card Application states

  Summary:
    SD Card Application states enumeration

  Description:
    This enumeration defines the valid SD Card application states.  These states
    determine the behavior of the SD Card application at various times.
*/

typedef enum
{
    /* SD_FS Application's state machine's initial state. */
    APP_SD_FS_STATE_INIT=0,

    /* The SD_FS app mounts the disk */
    APP_SD_FS_MOUNT_DISK,

    /* The SD_FS app unmounts the disk */
    APP_SD_FS_UNMOUNT_DISK,

    /* The SD_FS app mounts the disk again */
    APP_SD_FS_MOUNT_DISK_AGAIN,

    /* Set the current drive */
    APP_SD_FS_SET_CURRENT_DRIVE,

    /* The SD_FS app opens the file to read */
    APP_SD_FS_OPEN_FIRST_FILE,

    /* Create directory */
    APP_SD_FS_CREATE_DIRECTORY,

    /* The SD_FS app opens the file to write */
    APP_SD_FS_OPEN_THE_FILE,

    /* The SD_FS app reads from a file and writes to another file */
    APP_SD_FS_WRITE_TO_FILE,

    /* The SD_FS app closes the file*/
    APP_SD_FS_CLOSE_FILE,

    /* The SD_FS app closes the file and idles */
    APP_SD_FS_IDLE,

    /* An  SD_FS app error has occurred */
    APP_SD_FS_ERROR
    /* TODO: Define states used by the application state machine. */

} APP_SD_CARD_STATES;

// *****************************************************************************
/* RTC Application states

  Summary:
    RTC Application states enumeration

  Description:
    This enumeration defines the valid RTC application states.  These states
    determine the behavior of the RTC application at various times.
*/

typedef enum
{
    /* RTC Application's state machine's initial state. */
    APP_RTC_STATE_INIT=0,

    /* RTC App Reset Time and Data */
    APP_RTC_RESET_TIME_DATE,

    /* RTC App Start */
    APP_RTC_START_TIME_DATE,

    /* The RTC app idle state */
    APP_RTC_IDLE,

    /* An RTC app error has occurred */
    APP_RTC_ERROR,
    /* TODO: Define states used by the application state machine. */

} APP_RTC_STATES;


// *****************************************************************************
/* SD Card Application Data

  Summary:
    Holds SD Card application data

  Description:
    This structure holds the SD Card application's data.

  Remarks:
    SD Card Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
    /* SYS_FS File handle for 1st file */
    SYS_FS_HANDLE               fileHandle;

    /* SYS_FS File handle for 2nd file */
    SYS_FS_HANDLE               fileHandle1;

    /* Application's current state */
    APP_SD_CARD_STATES                  state;           

    int32_t                     nBytesRead;

    /* TODO: Define any additional data used by the application. */

} APP_SD_CARD_DATA;

// *****************************************************************************
/* RTC Application Data

  Summary:
    Holds RTC application data

  Description:
    This structure holds the RTC  application's data.

  Remarks:
    RTC  Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
    /* Application's current state */
    APP_RTC_STATES                  state;           

    int32_t                     nBytesRead;

    /* TODO: Define any additional data used by the application. */

} APP_RTC_DATA;

/*  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/

typedef enum
{
    /* Application's state machine's initial state. */
    APP_STATE_INIT=0,
    APP_STATE_SERVICE_TASKS,

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


} APP_DATA;

void APP_Tasks_Flame_Detector(void);
void APP_Tasks_SD_Card( void );
void APP_Tasks_Set_Time( void );
void APP_Tasks_RNBD (void);


static bool APP_RNBD_uart(void);

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

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _APP_H */

/*******************************************************************************
 End of File
 */

