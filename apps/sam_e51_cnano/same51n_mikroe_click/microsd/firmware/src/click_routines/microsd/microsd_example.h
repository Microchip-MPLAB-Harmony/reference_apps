 /*******************************************************************************
  microsd example Header file

  Company:
    Microchip Technology Inc.

  File Name:
    microsd_example.h

  Summary:
    This file contains function prototypes of functions in microsd_example.c
  Description:
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*
    (c) 2023 Microchip Technology Inc. and its subsidiaries. You may use this
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
#ifndef MICROSD_EXAMPLE_H
#define MICROSD_EXAMPLE_H

#include "microsd.h"


typedef enum
{
    // The app opens a file to write some content in it
    SD_OPEN_FIRST_FILE = 0,

    // The app writes text message in the opened file
    SD_WRITE_TO_FILE,

    // Create directory
    SD_CREATE_DIRECTORY,

    // The app opens the file to write
    SD_OPEN_SECOND_FILE,

    // The app reads from the first file and writes to the second file
    SD_READ_WRITE_TO_FILE,

    // The app closes the file
    SD_CLOSE_FILE,

    // The app closes the file and idles
    SD_IDLE,

    // An app error has occurred
    SD_ERROR

} MICROSD_STATES;

typedef enum
{
    // Application's state machine's initial state.
    // The app mounts the disk

    SD_MOUNT_DISK = 0,

    // The app unmounts the disk
    SD_UNMOUNT_DISK,

    // The app mounts the disk again
    SD_MOUNT_DISK_AGAIN,

    // Set the current drive
    SD_SET_CURRENT_DRIVE,

    // Enters this state when mount is successful
    SD_MOUNT_SUCCESS,

    // The app stops when it encounters error while initializing
    SD_INIT_ERROR

} MICROSD_INIT;

typedef struct
{
    // SYS_FS File handle for 1st file
    MICROSD_HANDLE               fileHandle;

    // SYS_FS File handle for 2nd file
    MICROSD_HANDLE               fileHandle1;

    // Application's current state
    MICROSD_STATES                  state;

    // Application's microSD initialization state
    MICROSD_INIT                init_state;

    // Size of the data which is to be read/written
    int32_t                     nBytesRead;

} MICROSD_DATA;

/* Function:
  bool microsd_example_initialize(void);

  Summary:
    This function calls microsd_initialize function

  Description:
    This function calls the function responsible for SD card mounting
    and setting of current drive

  Remarks:
    Refer microsd_example.c file for more information.
*/
bool microsd_example_initialize(void);

/* Function:
  bool microsd_example_tasks(void);

  Summary:
    This function takes care of all file operations.

  Description:
    This function writes into first file, creates a Directory
    and then copies the content from first file and writes into file in the
    created Directory

  Remarks:
    Refer microsd_example.c file for more information.
*/

bool microsd_example_tasks(void);
/* Function:
  bool microsd_initialize(void);

  Summary:
    This function takes care of all the preconditions
 * before starting file operations.

  Description:
    This function mounts the SD card and sets the path

  Remarks:
    Refer microsd_example.c file for more information.
*/
bool microsd_initialize(void);

#endif // MICROSD_EXAMPLE_H