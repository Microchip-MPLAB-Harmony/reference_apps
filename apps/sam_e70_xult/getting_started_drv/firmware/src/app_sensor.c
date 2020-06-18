/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_sensor.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

//DOM-IGNORE-BEGIN 
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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

#include "app_sensor.h"
#include "usart_common.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
#define APP_SENSOR_I2C_CLOCK_SPEED             100000
#define APP_SENSOR_I2C_SLAVE_ADDR              0x004B
#define APP_SENSOR_TEMPERATURE_REG_ADDR        0x00
#define APP_SENSOR_SAMPLING_RATE_IN_HZ         1

extern volatile bool isUsartWriteCompleted;
// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_SENSOR_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_SENSOR_DATA app_sensorData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/******************************************************************************
  Function:
    void APP_SENSOR_I2CEventHandler (
    DRV_I2C_TRANSFER_EVENT event,
    DRV_I2C_TRANSFER_HANDLE transferHandle,
    uintptr_t context
   )

  Remarks:
    This function is registered by the Sensor application client with the I2C
    driver. It is called by the I2C Driver when the requested I2C transfer is
    complete.
 */
void APP_SENSOR_I2CEventHandler(
    DRV_I2C_TRANSFER_EVENT event,
    DRV_I2C_TRANSFER_HANDLE transferHandle,
    uintptr_t context
)
{
    switch(event)
    {
        case DRV_I2C_TRANSFER_EVENT_COMPLETE:
            /* I2C read complete. */
            app_sensorData.isTemperatureReadComplete = true;
            break;
        case DRV_I2C_TRANSFER_EVENT_ERROR:
            /* Handle error case here.*/
        default:
            break;
    }
}






/******************************************************************************
  Function:
    void APP_SENSOR_TimerEventHandler ( uintptr_t )

  Remarks:
    This function is called by the Timer System Service when the requested time
    period has elapsed.
 */
void APP_SENSOR_TimerEventHandler( uintptr_t context )
{
    /* Timer expired. */
     app_sensorData.isTimerExpired = true;

     LED_Toggle();
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

/******************************************************************************
  Function:
    int8_t APP_SENSOR_CalcTemperature ( uint8_t* )

  Remarks:
    This function returns the temperature in degree Fahrenheit.
 */
int8_t APP_SENSOR_CalcTemperature(uint8_t* pRawValue)
{
    int16_t temp;

    temp = (pRawValue[0] << 8) | pRawValue[1];
    if ((temp & 0x8000) == 0)
    {
        temp = (temp >> 7) * 0.5;
    }
    else
    {
        temp = (~temp) + 1;
        temp = (temp >> 7);
        temp *= -0.5;
    }

    temp = (temp * (float)9/5) + 32;

    return (int8_t)temp;
}

/******************************************************************************
  Function:
    void APP_SENSOR_PrintTemperature ( uint8_t*, int8_t*, int8_t )

  Remarks:
    This function prints the sensor temperature on the USART terminal.
 */
void APP_SENSOR_PrintTemperature(uint8_t* txBuffer, int8_t* format, int8_t value)
{
    uint8_t len;
    len = sprintf((char*)txBuffer, (char*)format, value);

    DRV_USART_WriteBufferAdd(usartHandle, (void*)txBuffer, len,
            &usartWriteBufferHandle);
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_SENSOR_Initialize ( void )

  Remarks:
    See prototype in app_sensor.h.
 */

void APP_SENSOR_Initialize ( void )
{
    /* Place the sensor application state machine in its initial state. */
    app_sensorData.state = APP_SENSOR_STATE_INIT;

    isUsartWriteCompleted = true;
}


/******************************************************************************
  Function:
    void APP_SENSOR_Tasks ( void )

  Remarks:
    See prototype in app_sensor.h.
 */

void APP_SENSOR_Tasks ( void )
{
    /* Check the application's current state. */
    switch ( app_sensorData.state )
    {
        /* Application's initial state. */
        case APP_SENSOR_STATE_INIT:

            /* Open I2C Driver to interface with Sensor. */
            app_sensorData.i2cHandle = DRV_I2C_Open( DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE );

            if (app_sensorData.i2cHandle != DRV_HANDLE_INVALID)
            {
                app_sensorData.i2cSetup.clockSpeed = APP_SENSOR_I2C_CLOCK_SPEED;

                /* Setup I2C transfer @ 100 kHz to interface with Sensor. */
                DRV_I2C_TransferSetup(app_sensorData.i2cHandle, &app_sensorData.i2cSetup);

                /* Register I2C transfer complete Event Handler for Sensor. */
                DRV_I2C_TransferEventHandlerSet(app_sensorData.i2cHandle, APP_SENSOR_I2CEventHandler, 0);

                /* Register Timer Expiry Event Handler with Timer System Service. */
                SYS_TIME_CallbackRegisterMS(APP_SENSOR_TimerEventHandler, 0,
                        (1000*APP_SENSOR_SAMPLING_RATE_IN_HZ), SYS_TIME_PERIODIC);

                if (app_sensorData.sysTimeHandle != SYS_TIME_HANDLE_INVALID)
                {
				   /* Open USART Driver. */
                   usartHandle = DRV_USART_Open(DRV_USART_INDEX_0, DRV_IO_INTENT_READWRITE);
                    if (usartHandle != DRV_HANDLE_INVALID)
                    {
						/* Register USART transfer complete Event Handler. */
                        DRV_USART_BufferEventHandlerSet(usartHandle,
                                APP_USARTBufferEventHandler, 0);

                        /* Initialization done. Enter idle state and wait for events */
                        app_sensorData.state = APP_SENSOR_STATE_IDLE;
                    }
                    else
                    {
                        /* Handle error condition */
                        app_sensorData.state = APP_SENSOR_STATE_ERROR;
                    }
                }
                else
                {
                    /* Handle error condition */
                    app_sensorData.state = APP_SENSOR_STATE_ERROR;
                }
            }
            else
            {
                /* Handle error condition */
                app_sensorData.state = APP_SENSOR_STATE_ERROR;
            }
            break;

        case APP_SENSOR_STATE_READ_TEMPERATURE:
            app_sensorData.i2cTxBuffer[0] = APP_SENSOR_TEMPERATURE_REG_ADDR;

            /* Submit I2C transfer to read temperature sensor value. */

            DRV_I2C_WriteReadTransferAdd( app_sensorData.i2cHandle,
                    APP_SENSOR_I2C_SLAVE_ADDR, (void*)app_sensorData.i2cTxBuffer, 1,
                    (void *)app_sensorData.i2cRxBuffer, 2, &app_sensorData.transferHandle );

			if (app_sensorData.transferHandle == DRV_I2C_TRANSFER_HANDLE_INVALID)
            {
                /* Handle error condition */
            }

            /* Go back to the idle state and wait for events */
            app_sensorData.state = APP_SENSOR_STATE_IDLE;

            break;

        case APP_SENSOR_STATE_PRINT_TEMPERATURE:
            /* Calculate the temperature from raw value and print on the terminal */

            /* Make sure the USART is ready to write new data */
            if (isUsartWriteCompleted == true)
            {
                isUsartWriteCompleted = false;
                app_sensorData.temperature = APP_SENSOR_CalcTemperature(app_sensorData.i2cRxBuffer);

				/* Print the latest read temperature value on the serial terminal */
                APP_SENSOR_PrintTemperature(app_sensorData.usartTxBuffer, \
                        (int8_t *)"Temperature = %d F\r\n", app_sensorData.temperature);

                /* Notify the EEPROM task to log the temperature value to EEPROM. */
                APP_EEPROM_SetTempWriteRequest(app_sensorData.temperature);

                /* Go back to the idle state and wait for events */
                app_sensorData.state = APP_SENSOR_STATE_IDLE;
            }
            break;

        case APP_SENSOR_STATE_IDLE:
            /* Transition to the appropriate state based on the events */
            if (app_sensorData.isTimerExpired == true)
            {
                /* Periodic timer has expired. Time to read temperature. */
                app_sensorData.isTimerExpired = false;
                app_sensorData.state = APP_SENSOR_STATE_READ_TEMPERATURE;
            }
            else if (app_sensorData.isTemperatureReadComplete == true)
            {
                /* Temperature read successfully. Time to display on serial terminal.*/
                app_sensorData.isTemperatureReadComplete = false;
                app_sensorData.state = APP_SENSOR_STATE_PRINT_TEMPERATURE;
            }

            break;

        case APP_SENSOR_STATE_ERROR:
            /* Handle error conditions here */
            break;

        default:

            break;

    }
}


/*******************************************************************************
 End of File
 */
