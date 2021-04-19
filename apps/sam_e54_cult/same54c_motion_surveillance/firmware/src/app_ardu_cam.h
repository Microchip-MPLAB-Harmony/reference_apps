/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app_ardu_cam.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_ARDU_CAM_Initialize" and "APP_ARDU_CAM_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_ARDU_CAM_STATES" definition).  Both
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

#ifndef _APP_ARDU_CAM_H
#define _APP_ARDU_CAM_H

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
#include "driver/spi/drv_spi.h"
#include "system/fs/sys_fs.h"
#include "system/console/sys_console.h"
#include "peripheral/rtc/plib_rtc.h"
#include "app_ov2640_sensor.h"

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
#define ARDUCAM_CMD_WRITE                       0x01
#define ARDUCAM_CMD_READ                        0x00
#define ARDUCAM_CMD_RDSR                        0x05
#define ARDUCAM_CMD_WREN                        0x06
#define ARDUCAM_STATUS_BUSY_BIT                 0x01

#define APP_ARDUCAM_SPI_CLK_SPEED               1000000

#define APP_ARDUCAM_READ_WRITE_RATE_MS          1000

#define ARDUCAM_NUM_BYTES_RD_WR                 16

#define SDCARD_MOUNT_NAME                       SYS_FS_MEDIA_IDX0_MOUNT_NAME_VOLUME_IDX0
#define SDCARD_DEV_NAME                         SYS_FS_MEDIA_IDX0_DEVICE_NAME_VOLUME_IDX0
#define SDCARD_DIR_NAME                         "web_pages/arducam"

#define MAX_FILE_NAMES                          255
#define MAX_FILE_NAME_LEN                       255
#define JPEG_FILE_NAME                          24

#define APP_ARDUCAM_READ_REG_SIZE               4
#define APP_ARDUCAM_WRITE_REG_SIZE              2

#define OV2640_MAX_FIFO_SIZE                    0x5FFFF			//384KByte
#define BUF_SIZE                                4096

#define ARDUCHIP_TEST1                          0x00  //TEST register
#define ARDUCHIP_MODE                           0x02  //Mode register
#define MCU2LCD_MODE                            0x00
#define CAM2LCD_MODE                            0x01
#define LCD2MCU_MODE                            0x02

#define ARDUCHIP_TRIG                           0x41  //Trigger source
#define VSYNC_MASK                              0x01
#define SHUTTER_MASK                            0x02
#define CAP_DONE_MASK                           0x08

#define ARDUCHIP_FIFO                           0x04  //FIFO and I2C control
#define FIFO_CLEAR_MASK                         0x01
#define FIFO_START_MASK                         0x02
#define FIFO_RDPTR_RST_MASK                     0x10
#define FIFO_WRPTR_RST_MASK                     0x20

#define BURST_FIFO_READ                         0x3C  //Burst FIFO read operation
#define SINGLE_FIFO_READ                        0x3D  //Single FIFO read operation

#define FIFO_SIZE1                              0x42  //Camera write FIFO size[7:0] for burst to read
#define FIFO_SIZE2                              0x43  //Camera write FIFO size[15:8]
#define FIFO_SIZE3                              0x44  //Camera write FIFO size[18:16]


/* Reference Year in tm structure year (C standard) */
#define APP_TM_STRUCT_REFERENCE_YEAR            (1900U)

/* Reference Year for FAT FS */
#define APP_FAT_FS_REFERENCE_YEAR               (1980U)

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
    APP_ARDU_CAM_STATE_INIT=0,

    /* The app waits for SD Card to be mounted */
    APP_ARDU_CAM_STATE_MOUNT_WAIT,

    /* Set the current drive */
    APP_ARDU_CAM_STATE_SET_CURRENT_DRIVE,

    /* Check whether ArduCAM is mounted */
    APP_ARDU_CAM_STATE_ARDUCHIP_TEST_BIT,

    /* Change ArduCAM mode */
    APP_ARDU_CAM_STATE_ARDUCHIP_CHANGE_MODE,

    /* Flush ArduCAM FIFO */
    APP_ARDU_CAM_STATE_OV2640_READY_FLUSH_FIFO,

    /* Clear ArduCAM FIFO */
    APP_ARDU_CAM_STATE_CLEAR_FIFO_FLAG,

    /* Start ArduCAM capture */
    APP_ARDU_CAM_STATE_START_CAPTURE,

    /* Wait for ArduCAM capture done bit to be set */
    APP_ARDU_CAM_STATE_WAIT_FOR_FIFO_DONE,

    /* Get the FIFO length and read JPEG header */
    APP_ARDU_CAM_STATE_GET_FIFO_JPEG_HEADER,

    /* Saves the image on microSD card */
    APP_ARDU_CAM_STATE_SAVE_IMAGE,

    /* The app closes the file*/
    APP_ARDU_CAM_STATE_CLOSE_FILE,

    APP_ARDU_CAM_STATE_ERROR,

} APP_ARDU_CAM_STATES;


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
    APP_ARDU_CAM_STATES state;

    DRV_SPI_TRANSFER_SETUP spiSetup;

    DRV_HANDLE  spiHandle;

    /* SYS_FS File handle for 1st file */
    SYS_FS_HANDLE fileHandle;

    /* Flag to indicate SDCARD mount status */
    volatile bool sdCardMountFlag;

    volatile bool status;

    volatile bool arducamInit;

    uint8_t readReg[APP_ARDUCAM_READ_REG_SIZE];

    uint8_t writeReg[APP_ARDUCAM_WRITE_REG_SIZE];

    /* Stores the Current time from RTC */
    struct tm rtcTime;

} APP_ARDU_CAM_DATA;

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
    void APP_ARDU_CAM_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    APP_ARDU_CAM_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_ARDU_CAM_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_ARDU_CAM_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_ARDU_CAM_Tasks ( void )

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
    APP_ARDU_CAM_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_ARDU_CAM_Tasks( void );

/*******************************************************************************
  Function:
    bool APP_ARDU_CAM_Task_GetStatus ( void )

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    gets the ARDU CAM Task is initialized or not.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    true - ARDU CAM Task is initialized completely.
    false - ARDU CAM Task is not initialized completely.

  Example:
    <code>
    bool status = false;

    status = APP_ARDU_CAM_Task_GetStatus();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */
bool APP_ARDU_CAM_Task_GetStatus(void);

/*******************************************************************************
  Function:
    bool APP_ARDU_CAM_Get_Image_Name ( void )

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    gets the latest captured JPEG image filename.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    true - pointer to the latest captured JPEG image filename.

  Example:
    <code>
    char capturedFileName[24];
    const char *ptr =  NULL;

    if (ptr != NULL)
        ptr = APP_ARDU_CAM_Get_Image_Name();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */
const char* APP_ARDU_CAM_Get_Image_Name(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _APP_ARDU_CAM_H */

/*******************************************************************************
 End of File
 */

