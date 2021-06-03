/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_sensor_thread.c

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

#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "app_sensor_thread.h"
#include "definitions.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

#define APP_SENSOR_I2C_CLOCK_SPEED             100000
#define APP_SENSOR_I2C_SLAVE_ADDR              0x004F
#define APP_SENSOR_TEMPERATURE_REG_ADDR        0x00
#define APP_SENSOR_SAMPLING_RATE_IN_MSEC       1000


// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_SENSOR_THREAD_Initialize function.

    Application strings and buffers are be defined outside this structure.
 */

APP_SENSOR_THREAD_DATA app_sensorData;

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




// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_SENSOR_THREAD_Initialize ( void )

  Remarks:
    See prototype in app_sensor_thread.h.
 */

void APP_SENSOR_THREAD_Initialize(void) 
{
    /* Place the App state machine in its initial state. */
    app_sensorData.isInitDone = false;
}

/******************************************************************************
  Function:
    void APP_SENSOR_THREAD_Tasks ( void )

  Remarks:
    See prototype in app_sensor_thread.h.
 */

void APP_SENSOR_THREAD_Tasks(void) 
{

    uint8_t registerAddr = APP_SENSOR_TEMPERATURE_REG_ADDR;                
    uint8_t strlen;                        
    
    /* Open the drivers if not already opened */
    if (app_sensorData.isInitDone == false)
    {
        /* Open I2C driver to interact with the temperature sensor */  
            
            app_sensorData.i2cHandle = DRV_I2C_Open(DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE);
            
            if (app_sensorData.i2cHandle != DRV_HANDLE_INVALID)
            {
              /* Got valid handle, now configure the I2C clock speed for sensor */
               app_sensorData.i2cSetup.clockSpeed = APP_SENSOR_I2C_CLOCK_SPEED;
            
               /* Setup I2C transfer @ 100 kHz to interface with Sensor */  
               DRV_I2C_TransferSetup(app_sensorData.i2cHandle, &app_sensorData.i2cSetup);
            }
            
            else
            {
                /* Handle error */
            }
               app_sensorData.usartHandle = DRV_USART_Open(DRV_USART_INDEX_0, 0);
               
            
              if (app_sensorData.usartHandle != DRV_HANDLE_INVALID )
              {
               /* All drivers opened successfully */
                  app_sensorData.isInitDone = true;
              }
              else
              {
                   /* Handle Error */
              }   
               
     }
    
    
            vTaskDelay(APP_SENSOR_SAMPLING_RATE_IN_MSEC / portTICK_PERIOD_MS);
            
            LED_Toggle();
            //LED_Toggle();
            
            /* Submit a blocking I2C write-read request for temperature*/
            if (true == DRV_I2C_WriteReadTransfer(app_sensorData.i2cHandle, APP_SENSOR_I2C_SLAVE_ADDR, (void*) &registerAddr, 1, (void*) app_sensorData.i2cRxBuffer, 2)) 
            {   
                app_sensorData.temperature = APP_SENSOR_CalcTemperature(app_sensorData.i2cRxBuffer);

                app_sensorData.eventInfo.eventType = EVENT_TYPE_TEMP_WRITE_REQ;
                app_sensorData.eventInfo.eventData = app_sensorData.temperature;

                /* Use FreeRTOS Queue to notify the temperature write event and temperature 
                * value to EEPROM thread. */    
                
                
                
                xQueueSend(eventQueue, (void*) &app_sensorData.eventInfo, portMAX_DELAY); //use FreeRTOS Queue to nottify the temp write event and temperature value to eeprom thread*/ 
                strlen = sprintf((char*)app_sensorData.usartTxBuffer, "Temperature = %d F\r\n", app_sensorData.temperature); 
                
                DRV_USART_WriteBuffer(app_sensorData.usartHandle, app_sensorData.usartTxBuffer, strlen);
            }
           
}

            


/*******************************************************************************
 End of File
 */
