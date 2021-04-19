/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_ardu_cam.c

  Summary:
    This file contains the source code for the ArduCAM Camera module which uses
    SPI interface to send commands and receive the data from the Camera FIFO.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's to send commands to ArduCAM Slave
    module and receive the data from the Camera FIFO. This use SPI interface to
    communicate with the slave device.
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app_ardu_cam.h"
#include "app_pir_sensor.h"
#include "bsp/bsp.h"
#include <string.h>

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
/* Application data buffer */
volatile uint8_t buf[BUF_SIZE];
volatile uint32_t fifo_length   = 0;

uint8_t temp                    = 0;
uint8_t temp_last               = 0;
uint8_t temp_third_byte         = 0;
uint32_t length                 = 0;
int32_t i                       = 0;
uint8_t file_count              = 0;

bool is_header                  = false;

char fileNameArray[MAX_FILE_NAME_LEN];
char jpegFileName[JPEG_FILE_NAME];

// OV2640 sensor ready. This is defined in app_ov2640_sensor.c file
extern OSAL_SEM_DECLARE(ov2640Ready);

// PIR Sensor motion detected. This is defined in app_pir_sensor.c file
extern OSAL_SEM_DECLARE(motionDetected);

extern APP_PIR_SENSOR_DATA app_pir_sensorData;

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_ARDU_CAM_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_ARDU_CAM_DATA app_ardu_camData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

static void APP_SysFSEventHandler(SYS_FS_EVENT event,void* eventData,uintptr_t context)
{
    switch(event)
    {
        /* If the event is mount then check if SDCARD media has been mounted */
        case SYS_FS_EVENT_MOUNT:
            if(strcmp((const char *)eventData, SDCARD_MOUNT_NAME) == 0)
            {
                app_ardu_camData.sdCardMountFlag = true;
            }
            break;

        /* If the event is unmount then check if SDCARD media has been unmount */
        case SYS_FS_EVENT_UNMOUNT:
            if(strcmp((const char *)eventData, SDCARD_MOUNT_NAME) == 0)
            {
                app_ardu_camData.sdCardMountFlag = false;

                app_ardu_camData.state = APP_ARDU_CAM_STATE_MOUNT_WAIT;
            }
            break;
        case SYS_FS_EVENT_MOUNT_WITH_NO_FILESYSTEM:
        case SYS_FS_EVENT_ERROR:
            break;
    }
}

const char* APP_ARDU_CAM_Get_Image_Name(void)
{
    return (jpegFileName);
}
// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

static void APP_SetRTCTime(void)
{
    struct tm sys_time = { 0 };

    sys_time.tm_hour    = BUILD_TIME_HOUR;
    sys_time.tm_min     = BUILD_TIME_MIN;
    sys_time.tm_sec     = BUILD_TIME_SEC;

    sys_time.tm_mday    = BUILD_DAY;
    sys_time.tm_mon     = BUILD_MONTH;
    sys_time.tm_year    = BUILD_YEAR - APP_TM_STRUCT_REFERENCE_YEAR;

    /* Set RTC Time to current system time. */
    RTC_RTCCTimeSet(&sys_time);
}

/* This function overrides the default WEAK implementation
 * of get_fatttime() from diskio.c to use RTC.

 * This will be called from FAT FS code to update the timestamp
 * of modified files.
 */
uint32_t get_fattime(void)
{
    SYS_FS_TIME time    = { 0 };

    /* Get TimeStamp from RTC. */
    RTC_RTCCTimeGet(&app_ardu_camData.rtcTime);

    time.discreteTime.hour      = app_ardu_camData.rtcTime.tm_hour;
    time.discreteTime.minute    = app_ardu_camData.rtcTime.tm_min;
    time.discreteTime.second    = app_ardu_camData.rtcTime.tm_sec;

    time.discreteTime.day       = app_ardu_camData.rtcTime.tm_mday;
    time.discreteTime.month     = app_ardu_camData.rtcTime.tm_mon;

    /* For FAT FS, Years are calculated with offset from 1980 */
    time.discreteTime.year      = ((app_ardu_camData.rtcTime.tm_year + APP_TM_STRUCT_REFERENCE_YEAR) - APP_FAT_FS_REFERENCE_YEAR);

    return (time.packedTime);
}

static void APP_ARDU_CAM_Read_Fifo_Length(void)
{
    uint32_t len1       = 0;
    uint32_t len2       = 0;
    uint32_t len3       = 0;

    /* Read data Camera write FIFO size[7:0] */
    app_ardu_camData.writeReg[0] = FIFO_SIZE1;      // Address to read
    app_ardu_camData.writeReg[1] = 0x00;            // Send a dummy byte

    if (DRV_SPI_WriteReadTransfer(app_ardu_camData.spiHandle, app_ardu_camData.writeReg, 2, app_ardu_camData.readReg, 4) == true)
    {
        len1 = app_ardu_camData.readReg[1];

        /* Read data Camera write FIFO size[15:8] */
        app_ardu_camData.writeReg[0] = FIFO_SIZE2;      // Address to read
        app_ardu_camData.writeReg[1] = 0x00;            // Send a dummy byte

        if (DRV_SPI_WriteReadTransfer(app_ardu_camData.spiHandle, app_ardu_camData.writeReg, 2, app_ardu_camData.readReg, 4) == true)
        {
            len2 = app_ardu_camData.readReg[1];

            /* Read data Camera write FIFO size[18:16] */
            app_ardu_camData.writeReg[0] = FIFO_SIZE3;      // Address to read
            app_ardu_camData.writeReg[1] = 0x00;            // Send a dummy byte

            if (DRV_SPI_WriteReadTransfer(app_ardu_camData.spiHandle, app_ardu_camData.writeReg, 2, app_ardu_camData.readReg, 4) == true)
            {
                len3 = app_ardu_camData.readReg[1];
                len3 = len3 & 0x7F;

                // Calculate FIFO length
                fifo_length = ((len3 << 16) | (len2 << 8) | len1) & 0x07FFFFF;
            }
            else
            {
                app_ardu_camData.state = APP_ARDU_CAM_STATE_ERROR;
                return;
            }
        }
        else
        {
            app_ardu_camData.state = APP_ARDU_CAM_STATE_ERROR;
            return;
        }
    }
    else
    {
        app_ardu_camData.state = APP_ARDU_CAM_STATE_ERROR;
    }

    return;
}

static void APP_ARDU_CAM_Read_JpegHeader(void)
{
    app_ardu_camData.writeReg[0] = BURST_FIFO_READ; // Address to read
    app_ardu_camData.writeReg[1] = 0x00;            // Send a dummy byte

    if (DRV_SPI_WriteReadTransfer(app_ardu_camData.spiHandle, app_ardu_camData.writeReg, 2, app_ardu_camData.readReg, 4) == true)
    {
        temp_last       = app_ardu_camData.readReg[1];
        temp            = app_ardu_camData.readReg[2];
        temp_third_byte = app_ardu_camData.readReg[3];

        // Detect JPEG header information
        if ((temp == 0xD8) & (temp_last == 0xFF))
        {
            is_header = true;
            buf[i++] = temp_last;
            buf[i++] = temp;
            buf[i++] = temp_third_byte;
        }

        fifo_length = fifo_length - 3; // Read 3 bytes

        /* Write data into a file. */
        app_ardu_camData.state = APP_ARDU_CAM_STATE_SAVE_IMAGE;
    }
    else
    {
        app_ardu_camData.state = APP_ARDU_CAM_STATE_ERROR;
    }

    return;
}

static void APP_ARDU_CAM_Write_ToFile(void)
{
    while (fifo_length--)
    {
        temp_last = temp;

        app_ardu_camData.writeReg[0] = BURST_FIFO_READ; // Address to read
        app_ardu_camData.writeReg[1] = 0x00;            // Send a dummy byte

        if (DRV_SPI_WriteReadTransfer(app_ardu_camData.spiHandle, app_ardu_camData.writeReg, 1, app_ardu_camData.readReg, 2) == true)
        {
            /* Write data into a file. */
            temp =  app_ardu_camData.readReg[1];

            // Read JPEG data from FIFO
            if ( (temp == 0xD9) && (temp_last == 0xFF) ) //If find the end ,break while,
            {
                buf[i++] = temp;  //save the last  0XD9

                if(SYS_FS_FileWrite(app_ardu_camData.fileHandle, (const void *)buf, i) == -1)
                {
                    /* Write was not successful. Close the file and error out.*/
                    SYS_FS_FileClose(app_ardu_camData.fileHandle);
                    app_ardu_camData.state = APP_ARDU_CAM_STATE_ERROR;
                }
                app_ardu_camData.state = APP_ARDU_CAM_STATE_CLOSE_FILE;
                is_header = false;
                i = 0;
                break;
            }
            if (is_header == true)
            {
                //Write image data to buffer if not full
                if (i < BUF_SIZE)
                {
                    buf[i++] = temp;
                }
                else
                {
                    //Write BUF_SIZE bytes image data to file
                    if(SYS_FS_FileWrite(app_ardu_camData.fileHandle, (const void *)buf, BUF_SIZE) == -1)
                    {
                        /* Write was not successful. Close the file
                         * and error out.*/
                        SYS_FS_FileClose(app_ardu_camData.fileHandle);
                        app_ardu_camData.state = APP_ARDU_CAM_STATE_ERROR;
                    }
                    i = 0;
                    buf[i++] = temp;
                }
            }

        }
        else
        {
            app_ardu_camData.state = APP_ARDU_CAM_STATE_ERROR;
        }
    }
    app_ardu_camData.state = APP_ARDU_CAM_STATE_CLOSE_FILE;
    is_header = false;

    return;
}

bool APP_ARDU_CAM_Task_GetStatus(void)
{
    return app_ardu_camData.arducamInit;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_ARDU_CAM_Initialize ( void )

  Remarks:
    See prototype in app_ardu_cam.h.
 */

void APP_ARDU_CAM_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_ardu_camData.state          = APP_ARDU_CAM_STATE_MOUNT_WAIT;

    /* Place the App state machine in its initial state. */
    app_ardu_camData.status         = APP_ARDU_CAM_STATE_ERROR;
    app_ardu_camData.arducamInit    = false;

    /* Clear the read reg buffer */
    memset(app_ardu_camData.readReg, 0, sizeof(app_ardu_camData.readReg));

    /* Clear the write reg buffer */
    memset(app_ardu_camData.writeReg, 0, sizeof(app_ardu_camData.writeReg));

    /* Set RTC to current system time */
    APP_SetRTCTime();

    /* Register the File System Event handler */
    SYS_FS_EventHandlerSet((void const*)APP_SysFSEventHandler,(uintptr_t)NULL);
}

/******************************************************************************
  Function:
    void APP_ARDU_CAM_Tasks ( void )

  Remarks:
    See prototype in app_ardu_cam.h.
 */

void APP_ARDU_CAM_Tasks ( void )
{
    /* Check the application's current state. */
    switch ( app_ardu_camData.state )
    {
        case APP_ARDU_CAM_STATE_MOUNT_WAIT:

            /* Wait for SDCARD to be Auto Mounted */
            if(app_ardu_camData.sdCardMountFlag == true)
            {
                SYS_CONSOLE_MESSAGE("APP_ARDU_CAM_Task: Init Success. SD Card Mounted.\r\n");
                app_ardu_camData.state = APP_ARDU_CAM_STATE_SET_CURRENT_DRIVE;
            }
            break;

        case APP_ARDU_CAM_STATE_SET_CURRENT_DRIVE:

            if(SYS_FS_CurrentDriveSet(SDCARD_MOUNT_NAME) == SYS_FS_RES_FAILURE)
            {
                /* Error while setting current drive */
                app_ardu_camData.state = APP_ARDU_CAM_STATE_ERROR;
                break;
            }

            if(SYS_FS_DirectoryMake(SDCARD_DIR_NAME) == SYS_FS_RES_FAILURE)
            {
                if (SYS_FS_Error() != SYS_FS_ERROR_EXIST)
                {
                    /* Error while setting current drive */
                    app_ardu_camData.state = APP_ARDU_CAM_STATE_ERROR;
                    break;
                }
            }

            if (app_ardu_camData.arducamInit == false)
            {
                /* Open a file for reading. */
                app_ardu_camData.state = APP_ARDU_CAM_STATE_INIT;
            }
            else
            {
                app_ardu_camData.state = APP_ARDU_CAM_STATE_CLEAR_FIFO_FLAG;
            }
            break;

        /* Application's initial state. */
        case APP_ARDU_CAM_STATE_INIT:

            app_ardu_camData.spiSetup.baudRateInHz  = APP_ARDUCAM_SPI_CLK_SPEED;
            app_ardu_camData.spiSetup.clockPhase    = DRV_SPI_CLOCK_PHASE_VALID_LEADING_EDGE;
            app_ardu_camData.spiSetup.clockPolarity = DRV_SPI_CLOCK_POLARITY_IDLE_LOW;
            app_ardu_camData.spiSetup.dataBits      = DRV_SPI_DATA_BITS_8;
            app_ardu_camData.spiSetup.chipSelect    = (SYS_PORT_PIN)ARDUCAM_SLAVE_SS_PIN;
            app_ardu_camData.spiSetup.csPolarity    = DRV_SPI_CS_POLARITY_ACTIVE_LOW;

            app_ardu_camData.spiHandle = DRV_SPI_Open( DRV_SPI_INDEX_0, DRV_IO_INTENT_READWRITE );

            if (app_ardu_camData.spiHandle != DRV_HANDLE_INVALID)
            {
                DRV_SPI_TransferSetup(app_ardu_camData.spiHandle, &app_ardu_camData.spiSetup);
                app_ardu_camData.state          = APP_ARDU_CAM_STATE_ARDUCHIP_TEST_BIT;
                app_ardu_camData.arducamInit    = true;
            }
            else
            {
                app_ardu_camData.state = APP_ARDU_CAM_STATE_ERROR;
            }
            break;

        case APP_ARDU_CAM_STATE_ARDUCHIP_TEST_BIT:

            /* Read data from ArduCAM */
            /*
             * The first bit[7] of the command phase is read/write byte,
             * ?0? is for read and ?1? is for write, and the bit[6:0] is the
             * address to be read or write in the data phase.
             */
            // Register Address : 0x00 - Test Register
            app_ardu_camData.writeReg[0] = ARDUCHIP_TEST1 | 0x80; // set the bit[7] of the command phase to write
            app_ardu_camData.writeReg[1] = 0x55;

            if (DRV_SPI_WriteReadTransfer(app_ardu_camData.spiHandle, app_ardu_camData.writeReg, 2, app_ardu_camData.readReg, 4) == true)
            {
                if (app_ardu_camData.readReg[1] == 0x55)
                {
                    /* SPI interface OK. */
                    app_ardu_camData.state = APP_ARDU_CAM_STATE_ARDUCHIP_CHANGE_MODE;
                }
                else
                {
                    /* SPI interface Error! */
                    app_ardu_camData.state = APP_ARDU_CAM_STATE_ARDUCHIP_TEST_BIT;

                    // Delay of 1000ms
                    vTaskDelay(1000 /portTICK_PERIOD_MS);
                }
            }
            else
            {
                app_ardu_camData.state = APP_ARDU_CAM_STATE_ERROR;
            }
            break;

        /* Change to MCU mode */
        case APP_ARDU_CAM_STATE_ARDUCHIP_CHANGE_MODE:

            /* Change MCU mode */
            app_ardu_camData.writeReg[0] = ARDUCHIP_MODE | 0x80; // set the bit[7] of the command phase to write
            app_ardu_camData.writeReg[1] = 0x00;

            if (DRV_SPI_WriteTransfer(app_ardu_camData.spiHandle, app_ardu_camData.writeReg, sizeof (app_ardu_camData.writeReg)) == true)
            {
                app_ardu_camData.state = APP_ARDU_CAM_STATE_OV2640_READY_FLUSH_FIFO;
            }
            else
            {
                app_ardu_camData.state = APP_ARDU_CAM_STATE_ERROR;
            }
            break;

        case APP_ARDU_CAM_STATE_OV2640_READY_FLUSH_FIFO:

            if (APP_OV2640_SENSOR_Task_GetStatus() == false)
            {
                /* Wait for the OV2640 Sensor to be ready */
                OSAL_SEM_Pend( &ov2640Ready, OSAL_WAIT_FOREVER );
            }

            /* Flush the FIFO */
            app_ardu_camData.writeReg[0] = ARDUCHIP_FIFO | 0x80; // set the bit[7] of the command phase to write
            app_ardu_camData.writeReg[1] = FIFO_CLEAR_MASK;

            if (DRV_SPI_WriteTransfer(app_ardu_camData.spiHandle, app_ardu_camData.writeReg, sizeof (app_ardu_camData.writeReg)) == true)
            {
                app_ardu_camData.state = APP_ARDU_CAM_STATE_CLEAR_FIFO_FLAG;
            }
            else
            {
                app_ardu_camData.state = APP_ARDU_CAM_STATE_ERROR;
            }

            break;

        case APP_ARDU_CAM_STATE_CLEAR_FIFO_FLAG:

            /* Clear the FIFO */
            app_ardu_camData.writeReg[0] = ARDUCHIP_FIFO | 0x80; // set the bit[7] of the command phase to write
            app_ardu_camData.writeReg[1] = FIFO_CLEAR_MASK;

            if (DRV_SPI_WriteTransfer(app_ardu_camData.spiHandle, app_ardu_camData.writeReg, sizeof (app_ardu_camData.writeReg)) == true)
            {
                app_ardu_camData.state = APP_ARDU_CAM_STATE_START_CAPTURE;
            }
            else
            {
                app_ardu_camData.state = APP_ARDU_CAM_STATE_ERROR;
            }
            break;

        case APP_ARDU_CAM_STATE_START_CAPTURE:

            /* Wait for motion detection */
             OSAL_SEM_Pend( &motionDetected, OSAL_WAIT_FOREVER );

            SYS_CONSOLE_MESSAGE("APP_ARDU_CAM_Task: Motion Detected...!\r\n");

            /* Clear the FIFO */
            app_ardu_camData.writeReg[0] = ARDUCHIP_FIFO | 0x80; // set the bit[7] of the command phase to write
            app_ardu_camData.writeReg[1] = FIFO_START_MASK;

            if (DRV_SPI_WriteTransfer(app_ardu_camData.spiHandle, app_ardu_camData.writeReg, sizeof (app_ardu_camData.writeReg)) == true)
            {
                /* CAM Capture Done */
                SYS_CONSOLE_MESSAGE("APP_ARDU_CAM_Task: Start Capture.\r\n");
                app_ardu_camData.state = APP_ARDU_CAM_STATE_WAIT_FOR_FIFO_DONE;
            }
            else
            {
                app_ardu_camData.state = APP_ARDU_CAM_STATE_ERROR;
            }
            break;

        case APP_ARDU_CAM_STATE_WAIT_FOR_FIFO_DONE:

            /* Read whether capture is done..! */
            app_ardu_camData.writeReg[0] = ARDUCHIP_TRIG;   // Address to read
            app_ardu_camData.writeReg[1] = 0x00;            // Send a dummy byte

            if (DRV_SPI_WriteReadTransfer(app_ardu_camData.spiHandle, app_ardu_camData.writeReg, 2, app_ardu_camData.readReg, 4) == true)
            {
                /* Check whether Capture done bit is set */
                if (app_ardu_camData.readReg[1] & CAP_DONE_MASK)
                {
                    SYS_CONSOLE_MESSAGE("APP_ARDU_CAM_Task: Capture Done...!\r\n");
                    app_ardu_camData.state = APP_ARDU_CAM_STATE_GET_FIFO_JPEG_HEADER;
                    vTaskDelay(50 / portTICK_PERIOD_MS);
                }
                else
                {
                    /* SPI interface error */
                    app_ardu_camData.state = APP_ARDU_CAM_STATE_WAIT_FOR_FIFO_DONE;
                }
            }
            else
            {
                app_ardu_camData.state = APP_ARDU_CAM_STATE_ERROR;
            }
            break;

        case APP_ARDU_CAM_STATE_GET_FIFO_JPEG_HEADER:

            if (file_count >= MAX_FILE_NAMES)
            {
                file_count = 0;
            }

            // Generate unique filenames. Ex: IMAGE_0.JPG, IMAGE_1.JPG, ....
            sprintf((char *)&fileNameArray[0], SDCARD_DIR_NAME"/IMAGE_%d.JPG", file_count );
            // JPEG Filename to display on Webnet Server
            sprintf((char *)&jpegFileName[0],"IMAGE_%d.JPG", file_count );

            file_count++;

            SYS_CONSOLE_MESSAGE("APP_ARDU_CAM_Task: Save image: ");
            SYS_CONSOLE_MESSAGE(&fileNameArray[0]);
            SYS_CONSOLE_MESSAGE("\r\n");

            app_ardu_camData.fileHandle = SYS_FS_FileOpen((const char *) &fileNameArray[0], (SYS_FS_FILE_OPEN_WRITE));
            if(app_ardu_camData.fileHandle == SYS_FS_HANDLE_INVALID)
            {
                /* Could not open the file. Error out*/
                app_ardu_camData.state = APP_ARDU_CAM_STATE_ERROR;
                break;
            }

            // Get the FIFO Length
            APP_ARDU_CAM_Read_Fifo_Length();

            if (app_ardu_camData.state != APP_ARDU_CAM_STATE_ERROR)
            {
                if (fifo_length >= OV2640_MAX_FIFO_SIZE)
                {
                    // Over Size
                    SYS_CONSOLE_MESSAGE("APP_ARDU_CAM_Task: FIFO is over Size.\r\n");
                    app_ardu_camData.state = APP_ARDU_CAM_STATE_CLEAR_FIFO_FLAG;
                    break;
                }
                if (fifo_length == 0 )
                {
                    // Size is 0
                    SYS_CONSOLE_MESSAGE("APP_ARDU_CAM_Task: FIFO size is zero.\r\n");
                    app_ardu_camData.state = APP_ARDU_CAM_STATE_CLEAR_FIFO_FLAG;
                    break;
                }

                /* Read the JPEG Header information */
                APP_ARDU_CAM_Read_JpegHeader();
            }
            break;

        case APP_ARDU_CAM_STATE_SAVE_IMAGE:

            // Write the captured JPEG image file to SD Card
            APP_ARDU_CAM_Write_ToFile();
            break;

        case APP_ARDU_CAM_STATE_CLOSE_FILE:

            /* Close both files */
            SYS_FS_FileClose(app_ardu_camData.fileHandle);

            /* Capture successful. Recapture if motion detects. */
            app_ardu_camData.state = APP_ARDU_CAM_STATE_CLEAR_FIFO_FLAG;
            break;

        case APP_ARDU_CAM_STATE_ERROR:

            // APP_ARDU_CAM_Task error
            SYS_CONSOLE_MESSAGE("APP_ARDU_CAM_Task: Error...!\r\n");

            app_ardu_camData.status = APP_ARDU_CAM_STATE_ERROR;
            DRV_SPI_Close(app_ardu_camData.spiHandle);
            app_ardu_camData.arducamInit = false;

            /* Allow other threads to run */
            vTaskSuspend(NULL);

        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}

/*******************************************************************************
 End of File
 */
