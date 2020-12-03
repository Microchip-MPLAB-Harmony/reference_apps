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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app_sensor.h"
#include "common.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
#define APP_SENSOR_I2C_CLOCK_SPEED             100000
#define APP_SENSOR_I2C_SLAVE_ADDR              0x004F
#define APP_SENSOR_TEMPERATURE_REG_ADDR        0x00
#define APP_SENSOR_SAMPLING_RATE_IN_HZ         1

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
    
    /* Toggle LED*/
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

/*******************************************************************************
  Function
    int8_t COMMON_APP_SENSOR_GetTemperature ( void )

  Summary
    Get current temperature from app_sensor

  Returns
    Temperature in INT

  Example
    <code>
    int8_t temp = COMMON_APP_SENSOR_GetTemperature();
    </code>
 */
int8_t COMMON_APP_SENSOR_GetTemperature(void)
{
    /* Check if state machine is in error state. */
    if(app_sensorData.state != APP_SENSOR_STATE_ERROR)
    {   
        /* Return latest temperature value */
        return app_sensorData.temperature;
    }
    else
        return INT8_MIN;
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
            app_sensorData.i2cHandle = DRV_I2C_Open( DRV_I2C_INDEX_0, 
                    DRV_IO_INTENT_READWRITE );

            if (app_sensorData.i2cHandle != DRV_HANDLE_INVALID)
            {
                app_sensorData.i2cSetup.clockSpeed = APP_SENSOR_I2C_CLOCK_SPEED;

                /* Setup I2C transfer @ 100 kHz to interface with Sensor. */
                DRV_I2C_TransferSetup(app_sensorData.i2cHandle,
                        &app_sensorData.i2cSetup);

                /* Register I2C transfer complete Event Handler for Sensor. */
                DRV_I2C_TransferEventHandlerSet(app_sensorData.i2cHandle, 
                        APP_SENSOR_I2CEventHandler, 0);

                /* Register Timer Expiry Event Handler with 
                 * Time System Service. 
                 */
                SYS_TIME_CallbackRegisterMS(APP_SENSOR_TimerEventHandler, 0,
                        (1000*APP_SENSOR_SAMPLING_RATE_IN_HZ), 
                        SYS_TIME_PERIODIC);

                if (app_sensorData.sysTimeHandle != SYS_TIME_HANDLE_INVALID)
                {
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
            break;

        case APP_SENSOR_STATE_READ_TEMPERATURE:
            app_sensorData.i2cTxBuffer[0] = APP_SENSOR_TEMPERATURE_REG_ADDR;

            /* Submit I2C transfer to read temperature sensor value. */
            DRV_I2C_WriteReadTransferAdd( app_sensorData.i2cHandle,
                    APP_SENSOR_I2C_SLAVE_ADDR,
                    (void*)app_sensorData.i2cTxBuffer, 1,
                    (void*)app_sensorData.i2cRxBuffer, 2,
                    &app_sensorData.transferHandle );

			if (app_sensorData.transferHandle == DRV_I2C_TRANSFER_HANDLE_INVALID)
            {
                /* Handle error condition */
            }

            /* Go back to the idle state and wait for events */
            app_sensorData.state = APP_SENSOR_STATE_IDLE;

            break;

        case APP_SENSOR_STATE_STORE_TEMPERATURE:
            /* Calculate the temperature from raw value and add to EEPROM */
            app_sensorData.temperature = APP_SENSOR_CalcTemperature(app_sensorData.i2cRxBuffer);

            /* Notify the EEPROM task to log the temperature value to EEPROM. */
            APP_EEPROM_SetTempWriteRequest(app_sensorData.temperature);

            /* Go back to the idle state and wait for events */
            app_sensorData.state = APP_SENSOR_STATE_IDLE;

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
                /* Temperature read successfully. Time to store to EEPROM.*/
                app_sensorData.isTemperatureReadComplete = false;
                app_sensorData.state = APP_SENSOR_STATE_STORE_TEMPERATURE;
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
