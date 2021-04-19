/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_pir_sensor.c

  Summary:
    This file contains the source code for the PIR Click sensor module.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic to detects the natural infrared signature produced
    by humans.
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

#include "app_pir_sensor.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
volatile APP_TRANSFER_STATUS transferStatus = APP_TRANSFER_STATUS_IDLE;

float out_val;

OSAL_SEM_DECLARE(motionDetected);

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_PIR_SENSOR_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_PIR_SENSOR_DATA app_pir_sensorData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_PIR_SENSOR_Initialize ( void )

  Remarks:
    See prototype in app_pir_sensor.h.
 */

void APP_PIR_SENSOR_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_pir_sensorData.state = APP_PIR_SENSOR_STATE_INIT;
    app_pir_sensorData.enterIdleMode = false;

    if (OSAL_SEM_Create(&motionDetected, OSAL_SEM_TYPE_BINARY, 0, 0) == OSAL_RESULT_FALSE)
    {
        /* Handle error condition. Not sufficient memory to create semaphore */
    }
}

/******************************************************************************
  Function:
    void APP_PIR_SENSOR_Tasks ( void )

  Remarks:
    See prototype in app_pir_sensor.h.
 */

void APP_PIR_SENSOR_Tasks ( void )
{
    uint8_t registerAddr;

    /* Check the application's current state. */
    switch (app_pir_sensorData.state)
    {
        case APP_PIR_SENSOR_STATE_INIT:

            /* Open I2C driver instance */
            app_pir_sensorData.drvI2CHandle = DRV_I2C_Open( DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE);

            if(app_pir_sensorData.drvI2CHandle != DRV_HANDLE_INVALID)
            {
                app_pir_sensorData.state = APP_PIR_SENSOR_STATE_READ;
                SYS_CONSOLE_MESSAGE("APP_PIR_SENSOR_Task: Init Success.\r\n");
            }
            else
            {
                app_pir_sensorData.state = APP_PIR_SENSOR_STATE_XFER_ERROR;
            }
            break;

        case APP_PIR_SENSOR_STATE_READ:

            /* Read the PIR Sensor values */
            registerAddr = APP_PIR_REG_ADDR;

            /* Read PIR Sensor Values */
            if (DRV_I2C_WriteReadTransfer(app_pir_sensorData.drvI2CHandle, APP_PIR_SENSOR_ADDR, (void*)&registerAddr, 1, (void *)app_pir_sensorData.rxBuffer, 1 ) == true)
            {
                app_pir_sensorData.state = APP_PIR_SENSOR_STATE_WAIT_READ_COMPLETE;
            }
            else
            {
                app_pir_sensorData.state = APP_PIR_SENSOR_STATE_XFER_ERROR;
            }
            break;

        case APP_PIR_SENSOR_STATE_WAIT_READ_COMPLETE:
        {
            out_val  = ( float )( APP_PIR_OUT_MAX - APP_PIR_OUT_MIN );
            out_val *= app_pir_sensorData.rxBuffer[0];
            out_val /= APP_PIR_OUTPUT_CODE;
            out_val += APP_PIR_OUT_MIN;

            if (out_val >= APP_PIR_MOTION_DETECTED)
            {
                /* Motion detected */
                OSAL_SEM_Post(&motionDetected);
                LED2_Toggle();
            }
            app_pir_sensorData.state = APP_PIR_SENSOR_STATE_READ;
        }
            break;

        case APP_PIR_SENSOR_STATE_XFER_ERROR:
        {
            // PIR Sensor read error..!
            SYS_CONSOLE_MESSAGE("APP_PIR_SENSOR_Task: PIR Sensor read error...!\r\n");

            DRV_I2C_Close(app_pir_sensorData.drvI2CHandle);

            /* Allow other threads to run */
            vTaskSuspend(NULL);
        }
            break;

        default:
            break;
    }
}

/*******************************************************************************
 End of File
 */
