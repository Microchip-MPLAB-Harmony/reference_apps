/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

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
// DOM-IGNORE-BEGIN
/*
    (c) 2021 Microchip Technology Inc. and its subsidiaries. You may use this
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
// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stdio.h>
#include "app.h"
#include "click_routines/oled_c/oled_c_example.h"
#include "click_routines/oled_c/oled_c.h"
#include "definitions.h"
// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

#define TEMP_SENSOR_SLAVE_ADDR                  0x004F
#define TEMP_SENSOR_REG_ADDR                    0x00

static volatile bool isI2CFree = true;
static volatile bool isTemperatureRead = false;
uint8_t temperatureVal;
volatile bool temperatureStatus = false;
static uint8_t i2cAddress;
static uint8_t i2cWrData = TEMP_SENSOR_REG_ADDR;
static uint8_t i2cRdData[2] = {0};
uint8_t counter;
uint16_t adc_val;

uint32_t error_status;

/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;


static void i2cEventHandler(uintptr_t contextHandle)
{
    if ((error_status = SERCOM5_I2C_ErrorGet()) == SERCOM_I2C_ERROR_NONE)
    {
        if(i2cAddress == TEMP_SENSOR_SLAVE_ADDR)
        {
            isTemperatureRead       = true;
        }
        
        isI2CFree                   = true;
    }
    
    else
        printf("\r\nError :0x%x",error_status);
}


static uint8_t getTemperature(uint8_t* rawTempValue)
{
    int16_t temp;
    // Convert the temperature value read from sensor to readable format (Degree Celsius)
    // For demonstration purpose, temperature value is assumed to be positive.
    // The maximum positive temperature measured by sensor is +125 C
    temp = (rawTempValue[0] << 8) | rawTempValue[1];
    temp = (temp >> 7) * 0.5;
    temp = (temp * 9/5) + 32;
    return (uint8_t)temp;
}

void ReadSensorValue(void)
{
    /*Temperature Reading from Sensor*/
    if ((isI2CFree == true))   
    {
        isI2CFree = false;
        i2cAddress = TEMP_SENSOR_SLAVE_ADDR;
        SERCOM5_I2C_Read(TEMP_SENSOR_SLAVE_ADDR, i2cRdData, 2);
        temperatureVal = getTemperature(i2cRdData);        
        temperatureStatus = true;
    }   
  
    /*Light sensor value from ADC*/
    adc_val = ADC_ConversionResultGet();
 
    oled_c_example();
}

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;
    
    oled_c_example_initialize();
}

void APP_Tasks_CB (uintptr_t context)
{
    oled_c_dispaly_refresh();    

    ReadSensorValue();
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 *****************************************************************************/

void APP_Tasks ( void )
{    
    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;


            if (appInitialized)
            {
                SERCOM5_I2C_CallbackRegister(i2cEventHandler, 0);
                
                SERCOM5_I2C_WriteRead(TEMP_SENSOR_SLAVE_ADDR, &i2cWrData, 1, i2cRdData, 2);               
                
                SYS_TIME_CallbackRegisterMS (APP_Tasks_CB, 0, 3000, SYS_TIME_PERIODIC );
                
                ADC_Enable();
                
                ADC_ConversionStart();               
                
                appData.state = APP_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
            break;
        }

        default:
        {
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
