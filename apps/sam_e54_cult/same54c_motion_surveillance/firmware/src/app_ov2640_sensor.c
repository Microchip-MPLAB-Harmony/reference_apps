/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_ov2640_sensor.c

  Summary:
    This file contains the source code for the OV2640 Sensor module..

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic to configure the OV2640 sensor module.
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

#include "app_ov2640_sensor.h"
#include "ov2640_regs.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
volatile uint32_t vid_cnt;
volatile uint32_t pid_cnt;

uint32_t OV2640_JPEG_INIT_Reg_count     = sizeof(OV2640_JPEG_INIT_Reg)/sizeof(uint8_t [2]);
uint32_t OV2640_YUV422_Reg_count        = sizeof(OV2640_YUV422_Reg)/sizeof(uint8_t [2]);
uint32_t OV2640_JPEG_Reg_count          = sizeof(OV2640_JPEG_Reg)/sizeof(uint8_t [2]);
uint32_t OV2640_320x240_JPEG_Reg_count  = sizeof(OV2640_320x240_JPEG_Reg)/sizeof(uint8_t [2]);

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_OV2640_SENSOR_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_OV2640_SENSOR_DATA app_ov2640_sensorData;

OSAL_SEM_DECLARE(ov2640Ready);

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************
bool APP_OV2640_SENSOR_Task_GetStatus(void)
{
    return app_ov2640_sensorData.ov2640SensorInit;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************
bool APP_OV2640_SENSOR_Write_Reg (uint8_t reg, uint8_t data)
{
    bool result = false;

    app_ov2640_sensorData.txBuffer[0] = reg;    // Device Control Register Address
    app_ov2640_sensorData.txBuffer[1] = data;   // Register Value

    result = DRV_I2C_WriteTransfer(app_ov2640_sensorData.drvI2CHandle, APP_OV2640_SENSOR_ADDR, (void *)app_ov2640_sensorData.txBuffer, 2);

    return (result);
}

/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_OV2640_SENSOR_Initialize ( void )

  Remarks:
    See prototype in app_ov2640_sensor.h.
 */

void APP_OV2640_SENSOR_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_ov2640_sensorData.state             = APP_OV2640_SENSOR_STATE_INIT;
    app_ov2640_sensorData.ov2640SensorInit  = false;
    app_ov2640_sensorData.vid               = 0;
    app_ov2640_sensorData.pid               = 0;

    if (OSAL_SEM_Create(&ov2640Ready, OSAL_SEM_TYPE_BINARY, 0, 0) == OSAL_RESULT_FALSE)
    {
        /* Handle error condition. Not sufficient memory to create semaphore */
    }

}


/******************************************************************************
  Function:
    void APP_OV2640_SENSOR_Tasks ( void )

  Remarks:
    See prototype in app_ov2640_sensor.h.
 */

void APP_OV2640_SENSOR_Tasks ( void )
{
    uint8_t registerAddr;

    /* Check the application's current state. */
    switch ( app_ov2640_sensorData.state )
    {
        /* Application's initial state. */
        case APP_OV2640_SENSOR_STATE_INIT:
        {
            /* Open I2C driver instance */
            app_ov2640_sensorData.drvI2CHandle = DRV_I2C_Open( DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE);

            if(app_ov2640_sensorData.drvI2CHandle != DRV_HANDLE_INVALID)
            {
                app_ov2640_sensorData.state = APP_OV2640_SENSOR_STATE_CHECK_SENSOR_TYPE;
            }
            else
            {
                app_ov2640_sensorData.state = APP_OV2640_SENSOR_STATE_XFER_ERROR;
            }
        }

        case APP_OV2640_SENSOR_STATE_CHECK_SENSOR_TYPE: //fall-through
        {
            if (APP_OV2640_SENSOR_Write_Reg(OV2640_DEV_CTRL_REG, 0x01))
            {
                registerAddr = OV2640_CHIPID_HIGH;

                /* Check if the camera module sensor type is OV2640 */
                if (DRV_I2C_WriteReadTransfer(app_ov2640_sensorData.drvI2CHandle, APP_OV2640_SENSOR_ADDR, (void*)&registerAddr, 1, (void *)&app_ov2640_sensorData.vid, sizeof(app_ov2640_sensorData.vid) ) == true)
                {
                    vid_cnt++;

                    registerAddr = OV2640_CHIPID_LOW;

                    if (DRV_I2C_WriteReadTransfer(app_ov2640_sensorData.drvI2CHandle, APP_OV2640_SENSOR_ADDR, (void*)&registerAddr, 1, (void *)&app_ov2640_sensorData.pid, sizeof(app_ov2640_sensorData.pid) ) == true)
                    {
                        pid_cnt++;

                        if ((app_ov2640_sensorData.vid != 0x26 ) && (( app_ov2640_sensorData.pid != 0x41 ) || ( app_ov2640_sensorData.pid != 0x42 )))
                        {
                            /* Can't find OV2640 module! */
                            app_ov2640_sensorData.state = APP_OV2640_SENSOR_STATE_CHECK_SENSOR_TYPE;

                            vTaskDelay((APP_OV2640_SENSOR_DELAY*10) /portTICK_PERIOD_MS);
                        }
                        else
                        {
                            /* OV2640 detected. */
                            SYS_CONSOLE_MESSAGE("APP_OV2640_SENSOR_Task: Init Success. OV2640 Detected.\r\n");
                            app_ov2640_sensorData.state = APP_OV2640_SENSOR_STATE_WRITE_CTRL_REG_COM7;
                        }
                    }
                    else
                    {
                        app_ov2640_sensorData.state = APP_OV2640_SENSOR_STATE_XFER_ERROR;
                    }
                }
                else
                {
                    app_ov2640_sensorData.state = APP_OV2640_SENSOR_STATE_XFER_ERROR;
                }
            }
            else
            {
                app_ov2640_sensorData.state = APP_OV2640_SENSOR_STATE_XFER_ERROR;
            }
        }

        case APP_OV2640_SENSOR_STATE_WRITE_CTRL_REG_COM7: //fall-through
        {
            if (APP_OV2640_SENSOR_Write_Reg(OV2640_DEV_CTRL_REG, 0x01))
            {
                if (APP_OV2640_SENSOR_Write_Reg(OV2640_DEV_CTRL_REG_COM7, 0x80))
                {
                    app_ov2640_sensorData.state = APP_OV2640_SENSOR_STATE_MEDIA_JPEG_INIT;

                    /* Delay of 100 ms. */
                    vTaskDelay(APP_OV2640_SENSOR_DELAY /portTICK_PERIOD_MS);

                }
                else
                {
                    app_ov2640_sensorData.state = APP_OV2640_SENSOR_STATE_XFER_ERROR;
                }
            }
            else
            {
                app_ov2640_sensorData.state = APP_OV2640_SENSOR_STATE_XFER_ERROR;
            }
        }

        case APP_OV2640_SENSOR_STATE_MEDIA_JPEG_INIT:   //fall-through
        {
            for (uint32_t i = 0; i < OV2640_JPEG_INIT_Reg_count ;i++)
            {
                if (DRV_I2C_WriteTransfer(app_ov2640_sensorData.drvI2CHandle, APP_OV2640_SENSOR_ADDR, (void *)&OV2640_JPEG_INIT_Reg[i], 2) == true)
                {
                    vTaskDelay(1 /portTICK_PERIOD_MS);
                    app_ov2640_sensorData.state = APP_OV2640_SENSOR_STATE_MEDIA_YUV422;
                }
                else
                {
                    app_ov2640_sensorData.state = APP_OV2640_SENSOR_STATE_XFER_ERROR;
                }
            }
        }

        case APP_OV2640_SENSOR_STATE_MEDIA_YUV422:  //fall-through
        {
            for (uint32_t i = 0; i < OV2640_YUV422_Reg_count ;i++)
            {
                if (DRV_I2C_WriteTransfer(app_ov2640_sensorData.drvI2CHandle, APP_OV2640_SENSOR_ADDR, (void *)&OV2640_YUV422_Reg[i], 2) == true)
                {
                    vTaskDelay(1 /portTICK_PERIOD_MS);
                    app_ov2640_sensorData.state = APP_OV2640_SENSOR_STATE_MEDIA_JPEG;
                }
                else
                {
                    app_ov2640_sensorData.state = APP_OV2640_SENSOR_STATE_XFER_ERROR;
                }
            }
        }

        case APP_OV2640_SENSOR_STATE_MEDIA_JPEG:    //fall-through
        {
            for (uint32_t i = 0; i < OV2640_JPEG_Reg_count ;i++)
            {
                if (DRV_I2C_WriteTransfer(app_ov2640_sensorData.drvI2CHandle, APP_OV2640_SENSOR_ADDR, (void *)&OV2640_JPEG_Reg[i], 2) == true)
                {
                    vTaskDelay(1 /portTICK_PERIOD_MS);
                    app_ov2640_sensorData.state = APP_OV2640_SENSOR_STATE_WRITE_CTRL_REG_COM10;
                }
                else
                {
                    app_ov2640_sensorData.state = APP_OV2640_SENSOR_STATE_XFER_ERROR;
                }
            }
        }

        case APP_OV2640_SENSOR_STATE_WRITE_CTRL_REG_COM10:  //fall-through
        {
            if (APP_OV2640_SENSOR_Write_Reg(OV2640_DEV_CTRL_REG, 0x01))
            {
                vTaskDelay(1 /portTICK_PERIOD_MS);
                if (APP_OV2640_SENSOR_Write_Reg(OV2640_DEV_CTRL_REG_COM10, 0x00))
                {
                    vTaskDelay(1 /portTICK_PERIOD_MS);
                    app_ov2640_sensorData.state = APP_OV2640_SENSOR_STATE_MEDIA_320x240_JPEG;
                }
                else
                {
                    app_ov2640_sensorData.state = APP_OV2640_SENSOR_STATE_XFER_ERROR;
                }
            }
            else
            {
                app_ov2640_sensorData.state = APP_OV2640_SENSOR_STATE_XFER_ERROR;
            }

            /* Delay of 100 ms. */
            vTaskDelay(APP_OV2640_SENSOR_DELAY /portTICK_PERIOD_MS);
        }

        case APP_OV2640_SENSOR_STATE_MEDIA_320x240_JPEG:    //fall-through
        {
            app_ov2640_sensorData.state = APP_OV2640_SENSOR_STATE_XFER_ERROR;

            for (uint32_t i = 0; i < OV2640_320x240_JPEG_Reg_count ;i++)
            {
                if (DRV_I2C_WriteTransfer(app_ov2640_sensorData.drvI2CHandle, APP_OV2640_SENSOR_ADDR, (void *)&OV2640_320x240_JPEG_Reg[i], 2) == true)
                {
                    vTaskDelay(1 /portTICK_PERIOD_MS);
                    app_ov2640_sensorData.state = APP_OV2640_SENSOR_STATE_SUCCESS;
                }
                else
                {
                    app_ov2640_sensorData.state = APP_OV2640_SENSOR_STATE_XFER_ERROR;
                }
            }

            /* Delay of 1000 ms. */
            vTaskDelay(APP_OV2640_SENSOR_DELAY /portTICK_PERIOD_MS);

            if (app_ov2640_sensorData.state == APP_OV2640_SENSOR_STATE_SUCCESS)
            {
                SYS_CONSOLE_MESSAGE("APP_OV2640_SENSOR_Task: OV2640 is Ready...!\r\n");

                /* Notify the ARDUCAM task to capture the images */
                OSAL_SEM_Post(&ov2640Ready);
            }
            else
            {
                app_ov2640_sensorData.state = APP_OV2640_SENSOR_STATE_XFER_ERROR;
            }
        }

        case APP_OV2640_SENSOR_STATE_SUCCESS:   //fall-through
            DRV_I2C_Close(app_ov2640_sensorData.drvI2CHandle);

            app_ov2640_sensorData.ov2640SensorInit  = true;

            /* Allow other threads to run */
            vTaskSuspend(NULL);
            break;

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
