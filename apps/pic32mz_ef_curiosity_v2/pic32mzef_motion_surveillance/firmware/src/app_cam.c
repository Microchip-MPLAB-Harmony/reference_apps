/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_cam.c

  Summary:
    This file contains the source code for the PIR Click sensor module and for
    the ArduCAM Camera module which uses SPI interface to send commands and
    receive the data from the Camera FIFO.

  Description:
    This file contains the source code for the MPLAB Harmony application.   It
    implements the logic to detect the natural infrared radiation emitted by
    living beings such as humans. In addition, the application's logic is also
    designed to send commands to the ArduCAM Slave module and receive data from
    the Camera FIFO. This is achieved through the use of the SPI interface to
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

#include <stdint.h>
#include <stdio.h>
#include "app_cam.h"
#include "app_fs_tcp.h"
#include "arducam.h"


// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

#define jpegHeaderData1             0xFF
#define jpegHeaderData2             0xD8

uint8_t temp                    = 0;
uint8_t temp_last               = 0;
uint8_t file_count              = 0;

uint32_t i                      = 0;

bool is_header                  = false;

char fileNameArray[MAX_FILE_NAME_LEN];
char jpegFileName[JPEG_FILE_NAME];

uint8_t pir_rxBuffer[2]                 = {0};
static volatile bool pirIsRead      = false;
float pirOutputValue                = 0;


// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_CAM_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_CAM_DATA app_camData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

const char* APP_ARDU_CAM_Get_Image_Name(void)
{
    return (jpegFileName);
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

static void APP_CAM_SetRTCCTime(void)
{
    struct tm sys_time = { 0 };

    sys_time.tm_hour    = BUILD_TIME_HOUR;
    sys_time.tm_min     = BUILD_TIME_MIN;
    sys_time.tm_sec     = BUILD_TIME_SEC;

    sys_time.tm_mday    = BUILD_DAY;
    sys_time.tm_mon     = BUILD_MONTH;
    sys_time.tm_year    = BUILD_YEAR - APP_TM_STRUCT_REFERENCE_YEAR;

    /* Set RTCC Time to current system time. */
    if (RTCC_TimeSet(&sys_time) == false)
    {
        /* Error setting up time */
        while(1);
    }
}


uint32_t get_fattime(void)
{
    SYS_FS_TIME time    = { 0 };

    // Get TimeStamp from RTCC.
    RTCC_TimeGet(&app_camData.rtcTime);
    time.discreteTime.hour      = app_camData.rtcTime.tm_hour;
    time.discreteTime.minute    = app_camData.rtcTime.tm_min;
    time.discreteTime.second    = app_camData.rtcTime.tm_sec;
    time.discreteTime.day       = app_camData.rtcTime.tm_mday;
    time.discreteTime.month     = app_camData.rtcTime.tm_mon;

    // For FAT FS, Years are calculated with offset from 1980
    time.discreteTime.year      = 43; // 2022-1980 = 42 => year 2022

    return (time.packedTime);
}

bool spi_write_reg(uint8_t reg, uint8_t data)
{
    app_camData.writeReg[0] = reg | 0x80;
    app_camData.writeReg[1] = data;

    app_camData.status = DRV_SPI_WriteTransfer(app_camData.spiHandle, app_camData.writeReg,2);
    vTaskDelay(1 / portTICK_PERIOD_MS);

    return app_camData.status;
}

bool spi_read_reg(uint8_t reg)
{
    app_camData.writeReg[0] = reg & 0x7F;

    app_camData.status = DRV_SPI_WriteReadTransfer(app_camData.spiHandle, app_camData.writeReg, 1, app_camData.readReg, 3);
    vTaskDelay(1 / portTICK_PERIOD_MS);

    return app_camData.status;
}


bool APP_CAM_Camera_Is_Ready(void)
{
    uint8_t timeout = 50;

    while (timeout != 0)
    {
        spi_read_reg(CAM_REG_SENSOR_STATE);
        if ((app_camData.readReg[2] & 0x03) == CAM_REG_SENSOR_STATE_IDLE)
        {
            timeout = 0;
            app_camData.status = true;
        }

        else
        {
            timeout--;
            app_camData.status = false;
        }

        vTaskDelay(2 / portTICK_PERIOD_MS);
    }

    return app_camData.status;
}

static void APP_CAM_Read_Fifo_Length(void)
{
    uint32_t len1       = 0;
    uint32_t len2       = 0;
    uint32_t len3       = 0;

    if (spi_read_reg(FIFO_SIZE1) == true)
    {
        len1 = app_camData.readReg[1] & 0xFF;

        if (spi_read_reg(FIFO_SIZE2) == true)
        {
            len2 = app_camData.readReg[1] & 0xFF;

            if (spi_read_reg(FIFO_SIZE3) == true)
            {
                len3 = app_camData.readReg[1] & 0x7F;

                // Calculate FIFO length
                app_camData.fifo_size = ((len3 << 16) | (len2 << 8) | len1);
            }
            else
            {
                app_camData.state = APP_CAM_STATE_ERROR;
                return;
            }
        }

        else
        {
            app_camData.state = APP_CAM_STATE_ERROR;
            return;
        }
    }

    else
    {
        app_camData.state = APP_CAM_STATE_ERROR;
    }
}

static void APP_CAM_Read_JpegHeader(void)
{
    while (!is_header)
    {
        app_camData.writeReg[0] = BURST_FIFO_READ; // Address to read

        if (DRV_SPI_WriteReadTransfer(app_camData.spiHandle, app_camData.writeReg, 1, app_camData.readReg, 7) == true)
        {
            temp       = app_camData.readReg[2];
            temp_last  = app_camData.readReg[3];

            // Detect JPEG header information
            if ((temp == jpegHeaderData1) & (temp_last == jpegHeaderData2))
            {
                is_header = true;
                app_camData.captureBuffer[i++] = app_camData.readReg[2];
                app_camData.captureBuffer[i++] = app_camData.readReg[3];
                app_camData.captureBuffer[i++] = app_camData.readReg[4];
                app_camData.captureBuffer[i++] = app_camData.readReg[5];
                app_camData.captureBuffer[i++] = app_camData.readReg[6];

            }

            app_camData.fifo_size = app_camData.fifo_size - 5; // Read 3 bytes

            /* Write data into a file. */
            app_camData.state = APP_CAM_STATE_SAVE_IMAGE_FILE;
        }
        else
        {
            app_camData.state = APP_CAM_STATE_ERROR;
        }
    }
    return;
}

static void APP_CAM_Write_ToFile(void)
{
    while (app_camData.fifo_size--)
    {
        temp_last = temp;

        app_camData.writeReg[0] = BURST_FIFO_READ; // Address to read
        app_camData.writeReg[1] = 0x00;            // Send a dummy byte

        if (DRV_SPI_WriteReadTransfer(app_camData.spiHandle, app_camData.writeReg, 1, app_camData.readReg, 2) == true)
        {
            /* Write data into a file. */
            temp =  app_camData.readReg[1];

            // Read JPEG data from FIFO
            if ( (temp == 0xD9) && (temp_last == 0xFF) ) //If find the end ,break while,
            {
                app_camData.captureBuffer[i++] = temp;  //save the last  0XD9

                if(SYS_FS_FileWrite(app_camData.fileHandle, (const void *)app_camData.captureBuffer, i) == -1)
                {
                    /* Write was not successful. Close the file and error out.*/
                    SYS_FS_FileClose(app_camData.fileHandle);
                    app_camData.state = APP_CAM_STATE_ERROR;
                }
                app_camData.state = APP_CAM_STATE_CLOSE_FILE;
                is_header = false;
                i = 0;
                break;
            }

            if (i < BUF_SIZE)
            {
                app_camData.captureBuffer[i++] = temp;
            }
        }
        else
        {
            app_camData.state = APP_CAM_STATE_ERROR;
        }
    }

    SYS_CONSOLE_PRINT("APP_CAM_Task: Image Stored ...!\n\r");
    app_camData.state = APP_CAM_STATE_CLOSE_FILE;

    return;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_CAM_Initialize ( void )

  Remarks:
    See prototype in app_cam.h.
 */

void APP_CAM_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_camData.state = APP_CAM_STATE_INIT;
    /* Set RTCC to current system time */
    APP_CAM_SetRTCCTime();
}


/******************************************************************************
  Function:
    void APP_CAM_Tasks ( void )

  Remarks:
    See prototype in app_cam.h.
 */


void APP_CAM_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( app_camData.state )
    {
        /* Application's initial state. */
        case APP_CAM_STATE_INIT:
        {
            if(APP_FS_SystemIsReady() == true)
            {
                app_camData.spiSetup.baudRateInHz  = 8000000;
                app_camData.spiSetup.clockPhase    = DRV_SPI_CLOCK_PHASE_VALID_LEADING_EDGE;
                app_camData.spiSetup.clockPolarity = DRV_SPI_CLOCK_POLARITY_IDLE_LOW;
                app_camData.spiSetup.dataBits      = DRV_SPI_DATA_BITS_8;
                app_camData.spiSetup.chipSelect    = (SYS_PORT_PIN)SPI_CS_PIN;
                app_camData.spiSetup.csPolarity    = DRV_SPI_CS_POLARITY_ACTIVE_LOW;

                app_camData.spiHandle = DRV_SPI_Open( DRV_SPI_INDEX_0, DRV_IO_INTENT_READWRITE );

                if (app_camData.spiHandle != DRV_HANDLE_INVALID)
                {
                    DRV_SPI_TransferSetup(app_camData.spiHandle, &app_camData.spiSetup);
                    app_camData.state = APP_CAM_STATE_ARDUCAM_RESET;

                    SYS_CONSOLE_PRINT("\n\r");
                    SYS_CONSOLE_PRINT("APP_CAM_Task: ArduCAM Start! \n\r");

                }

                else
                {
                    app_camData.state = APP_CAM_STATE_ERROR;
                }
            }
            break;
        }

        case APP_CAM_STATE_ARDUCAM_RESET:
        {
            if (spi_write_reg(CAM_REG_SENSOR_RESET, CAM_SENSOR_RESET_ENABLE))
            {
                if( APP_CAM_Camera_Is_Ready() == true)
                {
                    app_camData.state = APP_CAM_STATE_CHECK_CAMERA;

                }

                else
                {
                    app_camData.state = APP_CAM_STATE_ERROR;
                }

            }

            else
            {
                app_camData.state = APP_CAM_STATE_ERROR;
            }

            break;
        }

        case APP_CAM_STATE_CHECK_CAMERA:
        {
            if(spi_read_reg(CAM_REG_SENSOR_ID))
            {
                // Change the CAMERA_TYPE macro based on the model
                #if CAMERA_TYPE == CAMERA_OV5640
                    if (app_camData.readReg[2] == CAMERA_OV5640_ID)

                #else
                    if (app_camData.readReg[2] == CAMERA_OV3640_ID)

                #endif
                {
                    if( APP_CAM_Camera_Is_Ready() == true)
                    {
                        app_camData.state = APP_CAM_STATE_CAMERA_CONFIG;
                    }

                    else
                    {
                        app_camData.state = APP_CAM_STATE_ERROR;
                    }

                }

                else
                {
                    app_camData.state = APP_CAM_STATE_CHECK_CAMERA;
                }
            }

            else
            {
                app_camData.state = APP_CAM_STATE_ERROR;
            }

            break;
        }

        case APP_CAM_STATE_CAMERA_CONFIG:
        {
            if (spi_write_reg(CAM_REG_DEBUG_DEVICE_ADDRESS, CAMERA_DEVICE_ADDRESS))
            {
                if( APP_CAM_Camera_Is_Ready() == true)
                {
                    app_camData.state = APP_CAM_STATE_SET_JPEG_FORMAT;
                    SYS_CONSOLE_PRINT("APP_CAM_Task: ArduCAM configuration is completed! \n\r");
                }

                else
                {
                    app_camData.state = APP_CAM_STATE_ERROR;
                }

            }

            else
            {
                app_camData.state = APP_CAM_STATE_ERROR;
            }

            break;
        }

        case APP_CAM_STATE_SET_JPEG_FORMAT:
        {
           if (spi_write_reg(CAM_REG_FORMAT, CAM_IMAGE_PIX_FMT_JPG))
            {
                if( APP_CAM_Camera_Is_Ready() == true)
                {
                    app_camData.state = APP_CAM_STATE_SET_RESOLUTION;
                }

                else
                {
                    app_camData.state = APP_CAM_STATE_ERROR;
                }

            }
        }

        case APP_CAM_STATE_SET_RESOLUTION:
        {
            // Change the CAMERA_TYPE macro based on the model
            #if CAMERA_TYPE == CAMERA_OV5640
                if (spi_write_reg(CAM_REG_CAPTURE_RESOLUTION, CAM_SET_CAPTURE_MODE | CAM_IMAGE_MODE_QVGA))

            #else
                if (spi_write_reg(CAM_REG_CAPTURE_RESOLUTION, CAM_SET_CAPTURE_MODE | CAM_IMAGE_MODE_QVGA))

            #endif

            {
                if( APP_CAM_Camera_Is_Ready() == true)
                {
                    SYS_CONSOLE_PRINT("APP_CAM_Task: APP_CAM_STATE_SET_RESOLUTION is completed! \n\r");
                    app_camData.state = APP_CAM_STATE_CAPTURE;
                }

                else
                {
                    app_camData.state = APP_CAM_STATE_ERROR;
                }

            }
        }

        case APP_CAM_STATE_CAPTURE:
        {
           if (spi_write_reg(ARDUCHIP_FIFO, FIFO_CLEAR_MASK))
            {

                if (spi_write_reg(ARDUCHIP_FIFO, FIFO_CLEAR_MASK))
                {

                    if (spi_write_reg(ARDUCHIP_FIFO, FIFO_START_MASK))
                    {
                        app_camData.state = APP_CAM_STATE_CAPTURE_WAIT;
                    }

                    else
                    {
                        app_camData.state = APP_CAM_STATE_ERROR;
                    }
                }

                else
                {
                    app_camData.state = APP_CAM_STATE_ERROR;
                }
            }

            else
            {
                app_camData.state = APP_CAM_STATE_ERROR;
            }

        }

        case APP_CAM_STATE_CAPTURE_WAIT:
        {
            spi_read_reg(ARDUCHIP_TRIG);

            if ((app_camData.readReg[2] & CAP_DONE_MASK) == CAP_DONE_MASK)
            {
                app_camData.state = APP_CAM_STATE_GET_FIFO_JPEG_HEADER;
            }

            vTaskDelay(25 / portTICK_PERIOD_MS);
            break;
        }

        case APP_CAM_STATE_GET_FIFO_JPEG_HEADER:
        {
            if (file_count >= MAX_FILE_NAMES)
            {
                file_count = 0;
            }

            // Generate unique filenames. Ex: IMAGE_0.JPG, IMAGE_1.JPG, ....
            sprintf((char *)&fileNameArray[0], SDCARD_DIR_NAME"/IMAGE_%d.jpg", file_count );
            // JPEG Filename to display on Webnet Server
            sprintf((char *)&jpegFileName[0],"IMAGE_%d.jpg", file_count );

            file_count++;

            SYS_CONSOLE_MESSAGE("APP_CAM_Task: Saving image: ");
            SYS_CONSOLE_MESSAGE(&fileNameArray[0]);
            SYS_CONSOLE_MESSAGE("\r\n");

            app_camData.fileHandle = SYS_FS_FileOpen((const char *) &fileNameArray[0], (SYS_FS_FILE_OPEN_WRITE));

            if(app_camData.fileHandle == SYS_FS_HANDLE_INVALID)
            {
                /* Could not open the file. Error out*/
                app_camData.state = APP_CAM_STATE_ERROR;
                break;
            }

            // Get the FIFO Length
            APP_CAM_Read_Fifo_Length();

            SYS_CONSOLE_PRINT("APP_CAM_Task: FIFO size is %lu \r\n", app_camData.fifo_size);

            APP_CAM_Read_JpegHeader();
            break;
        }


        case APP_CAM_STATE_SAVE_IMAGE_FILE:
        {
            // Write the captured JPEG image file to SD Card
            APP_CAM_Write_ToFile();

            app_camData.state = APP_CAM_STATE_CLOSE_FILE;
            break;
        }


        case APP_CAM_STATE_CLOSE_FILE:
        {
            /* Close both files */
            SYS_FS_FileClose(app_camData.fileHandle);
            vTaskDelay(500 / portTICK_PERIOD_MS);
            /* IMAGE_0.jpg captured and stored successfully. Recapture if motion detects. */
            app_camData.state = APP_CAM_STATE_PIR_INPUT_READ;

            break;
        }

        case APP_CAM_STATE_PIR_INPUT_READ:
        {

            I2C1_Read(PIR_SENSOR_ADDR, pir_rxBuffer, 2);
            while (I2C1_IsBusy());
            vTaskDelay(300 / portTICK_PERIOD_MS);

            pirOutputValue  = ( float )( PIR_OUT_MAX - PIR_ADC_MIN );
            // Actual range of ADC digital output is 0 to 4095. Desired range is 0 to 3303
            // scaling ADC conversion data to desired range

            pirOutputValue *= pir_rxBuffer[0];
            pirOutputValue /= PIR_ADC_MAX;
            pirOutputValue += PIR_ADC_MIN;

            if (pirOutputValue >= PIR_MOTION_THRESHOLD)
            {
                /* Motion detected*/
                SYS_CONSOLE_PRINT("\n\rAPP_CAM_Task: Motion Detected...!\n\r");
                pirIsRead = false;
                pirOutputValue  = 0;
                MOTION_DETECTION_LED_ON();

                if(APP_CAM_Camera_Is_Ready() == true)
                {
                    app_camData.state = APP_CAM_STATE_CAPTURE;
                }

                vTaskDelay(2 / portTICK_PERIOD_MS);
            }
            else
            {
                /* If Motion is not detected read PIR input again*/
                app_camData.state = APP_CAM_STATE_PIR_INPUT_READ;
            }

            MOTION_DETECTION_LED_OFF();

        }

        case APP_CAM_STATE_IDLE:
        {
            break;
        }

        case APP_CAM_STATE_ERROR:
        {
            SYS_CONSOLE_PRINT("APP_CAM_Task: Task Error...! \n\r");

            app_camData.state = APP_CAM_STATE_IDLE;

            /* Allow other threads to run */
            vTaskSuspend(NULL);
            break;
        }

        /* The default state should never be executed. */
        default:
        {
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
