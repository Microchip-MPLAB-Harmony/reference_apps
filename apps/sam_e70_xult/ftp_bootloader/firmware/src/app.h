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
#include "system/fs/sys_fs.h"

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
// Application SYS_FS mount points
// Adjust as needed
#define APP_SYS_FS_SD_VOL          "/dev/mmcblka1"
#define APP_SYS_FS_MOUNT_POINT      "/mnt/mchpSite1"
#define APP_SYS_FS_TYPE             FAT
#define APP_SYS_FS_TYPE_STRING      "FATFS"
    
    
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
    /* The app mounts the disk */
    APP_MOUNT_WAIT = 0,
            
    /* In this state, the application waits for the initialization of the TCP/IP stack
     * to complete. */
    APP_TCPIP_WAIT_INIT,
            
     /* In this state, the application can do TCP/IP transactions. */
    APP_TCPIP_TRANSACT,
            
    /*Wait for connection with FTP server*/
    APP_Connect_FTP,
            
    /*Log in to FTP server*/
    APP_Login_FTP,
            
    /* Set the current drive */
    APP_SET_CURRENT_DRIVE,
            
            
    APP_DOWNLOAD_BIN,

    /* The app opens the file to read */
    APP_OPEN_FILE,

    /* The app reads from a file and writes to another file */
    APP_READ_FILE,
            
    /*Invokes bootloader to flash application program*/
    APP_BOOTLOAD,
    
    /* The app closes the file*/
    APP_CLOSE_FILE,
            
    /*Run the application*/
    RUN_APPLICATION,
            
    /* The application does nothing in the idle state. */
    APP_STATE_IDLE,

    APP_USERIO_LED_DEASSERTED,

    APP_USERIO_LED_ASSERTED,

    APP_TCPIP_ERROR,
            
    APP_ERROR,

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
    /* SYS_FS File handle for 1st file */
    SYS_FS_HANDLE      fileHandle;

    /* SYS_FS File handle for 2nd file */
    int32_t       fileSize;

    /* Application's current state */
    APP_STATES         state;

    int32_t            nBytesRead;

    /* Flag to indicate SDCARD mount status */
    volatile bool      sdCardMountFlag;
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

void APP_Timer( uintptr_t );

void APP_Run_Application(void);

bool APP_Bootloader_Enter(void);

void APP_Flash_Task( void );

void APP_Trig_Boot(void);


#endif /* _APP_H */

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

