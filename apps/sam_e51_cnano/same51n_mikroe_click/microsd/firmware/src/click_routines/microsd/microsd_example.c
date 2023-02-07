 /*******************************************************************************
  microSD example source file

  Company:
    Microchip Technology Inc.

  File Name:
    microsd_example.c

  Summary:
    Source file which contains function calls of microSD functionality

  Description:
    This file contains function calls which navigates to State Machine which
    provides functionality to the microcontroller
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

#include "microsd.h"
#include "microsd_example.h"
#include "../click_interface.h"

#define SDCARD_MOUNT_NAME    "/mnt/mydrive"
#define SDCARD_DEV_NAME      "/dev/mmcblka1"
#define SDCARD_FILE_NAME     "mchp_sd.txt"
#define SDCARD_FILE_NAME_2   "mchp_sd2.txt"
#define SDCARD_DIR_NAME      "Dir1"
#define APP_DATA_LEN         512

// Text message which needs to be displayed in the file
static uint8_t BUFFER_ATTRIBUTES readWriteBuffer[APP_DATA_LEN] = "This is microSD Click Example";
static MICROSD_DATA microSdData;

// This function mounts the SD card and sets the path
bool microsd_initialize()
{
    microSdData.init_state = SD_MOUNT_DISK;
    switch ( microSdData.init_state )
    {
        case SD_MOUNT_DISK:
            if(CLICK_MICROSD_SYS_FS_Mount(SDCARD_DEV_NAME, SDCARD_MOUNT_NAME, FAT, 0, NULL) != 0)
            {
                /* The disk could not be mounted. Try
                 * mounting again until success.
                 */
                microSdData.init_state = SD_MOUNT_DISK;
            }
            else
            {
                // Mount was successful. Unmount the disk, for testing.
                microSdData.init_state = SD_UNMOUNT_DISK;
            }
            break;

        case SD_UNMOUNT_DISK:
            if(CLICK_MICROSD_SYS_FS_Unmount(SDCARD_MOUNT_NAME) != 0)
            {
                /* The disk could not be un mounted. Try
                 * un mounting again until success.
                 */

                microSdData.init_state = SD_UNMOUNT_DISK;
            }
            else
            {
                // UnMount was successful. Mount the disk again
                microSdData.init_state = SD_MOUNT_DISK_AGAIN;
            }
            break;

        case SD_MOUNT_DISK_AGAIN:
            if(CLICK_MICROSD_SYS_FS_Mount(SDCARD_DEV_NAME, SDCARD_MOUNT_NAME, FAT, 0, NULL) != 0)
            {
                /* The disk could not be mounted. Try
                 * mounting again until success.
                 */
                microSdData.init_state = SD_MOUNT_DISK_AGAIN;
            }
            else
            {
                /* Mount was successful. Set current drive so that
                 * we do not have to use absolute path.
                 */
                microSdData.init_state = SD_SET_CURRENT_DRIVE;
            }
            break;

        case SD_SET_CURRENT_DRIVE:
            if(CLICK_MICROSD_SYS_FS_CurrentDriveSet(SDCARD_MOUNT_NAME) == -1 )
            {
                // Error while setting current drive
                microSdData.init_state = SD_INIT_ERROR;
            }
            else
            {
                microSdData.init_state = SD_MOUNT_SUCCESS;
            }
            break;

        case SD_MOUNT_SUCCESS:
            break;

        case SD_INIT_ERROR:
            break;
    }
    return microSdData.init_state;
}

/* This function calls the function responsible for SD card mounting
 * and setting of current drive
 */
bool microsd_example_initialize(void)
{
    return microsd_initialize( );
}

/* This function writes into first file, creates a Directory
 * and then copies the content from first file and writes into file in the
 * created Directory
 */
bool microsd_example_tasks(void)
{
    if( microsd_initialize() == true )
        microSdData.state = SD_OPEN_FIRST_FILE;
    switch (microSdData.state)
    {
        case SD_OPEN_FIRST_FILE:
            microSdData.fileHandle = microsd_file_open(SDCARD_FILE_NAME, (MICROSD_OPEN_WRITE));
            if(microSdData.fileHandle == MICROSD_HANDLE_INVALID)
            {
                // Could not open the file. Error out
                microSdData.state = SD_ERROR;
            }
            else
            {
                // Write into the file.
                microSdData.state = SD_WRITE_TO_FILE;
            }
            break;

        case SD_WRITE_TO_FILE:
            if(microsd_file_write(microSdData.fileHandle, (const void *)readWriteBuffer, sizeof(readWriteBuffer)) == -1)
            {
                // Could not write to the file. Error out
                   microsd_file_close(microSdData.fileHandle);
                   microSdData.state = SD_ERROR;
            }
            else if(CLICK_MICROSD_SYS_FS_FileEOF(microSdData.fileHandle) == 1) //Test for end of file
            {
                    /* Continue the read and write process,
                     * until the end of file is reached
                     */
                    microsd_file_close(microSdData.fileHandle);
                    microSdData.state = SD_CREATE_DIRECTORY;
            }
            break;

        case SD_CREATE_DIRECTORY:
            if(microsd_create_directory(SDCARD_DIR_NAME) == MICROSD_RES_FAILURE)
            {
                // Error while creating a new drive
                microSdData.state = SD_ERROR;
            }
            else
            {
                // Open a second file for writing.
                microSdData.state = SD_OPEN_SECOND_FILE;
            }
            break;

        case SD_OPEN_SECOND_FILE:
            // Open a second file inside "Dir1"
            microSdData.fileHandle1 = microsd_file_open(SDCARD_DIR_NAME"/"SDCARD_FILE_NAME_2,
                    (MICROSD_OPEN_WRITE));

            if(microSdData.fileHandle1 == MICROSD_HANDLE_INVALID)
            {
                // Could not open the file. Error out
                microSdData.state = SD_ERROR;
            }
            else
            {
                // Read from one file and write to another file
                microSdData.state = SD_READ_WRITE_TO_FILE;
            }
            break;

        case SD_READ_WRITE_TO_FILE:
            /* Open the first file in read mode now
             * and read the content of first file
             */
            microSdData.fileHandle = microsd_file_open(SDCARD_FILE_NAME, (MICROSD_OPEN_READ));
            microSdData.nBytesRead = microsd_file_read(microSdData.fileHandle, (void *)readWriteBuffer, sizeof(readWriteBuffer));

            if (microSdData.nBytesRead == -1)
            {
                /* There was an error while reading the file.
                 * Close the file and error out.
                 */
                microsd_file_close(microSdData.fileHandle);
                microSdData.state = SD_ERROR;
            }
            else
            {
                /* If read from first file was success,
                 * try writing this content to the new file
                 */
                if(microsd_file_write(microSdData.fileHandle1, (const void *)readWriteBuffer, microSdData.nBytesRead) == -1)
                {
                    /* Write was not successful. Close the file
                     * and error out.
                     */
                    microsd_file_close(microSdData.fileHandle1);
                    microSdData.state = SD_ERROR;
                }
                else if(CLICK_MICROSD_SYS_FS_FileEOF(microSdData.fileHandle) == 1)
                    // Test for end of file
                {
                    /* Continue the read and write process,
                     *  until the end of file is reached
                     */
                    microSdData.state = SD_CLOSE_FILE;
                }
            }
            break;

        case SD_CLOSE_FILE:
            // Close both files
            microsd_file_close(microSdData.fileHandle);
            microsd_file_close(microSdData.fileHandle1);

            // The test was successful. Lets idle.
            microSdData.state = SD_IDLE;
            break;

        case SD_IDLE:
            /* The application comes here when the demo has completed
             * successfully. Glow LED0.
             */
            LED_ON();
            break;

        case SD_ERROR:
            // The application comes here when the demo has failed.
            break;
    }
    return microSdData.state;
}