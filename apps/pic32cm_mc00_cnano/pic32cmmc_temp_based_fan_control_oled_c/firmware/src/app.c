/*******************************************************************************************
* © [2020] Microchip Technology Inc. and its subsidiaries
 
 * Subject to your compliance with these terms, you may use this Microchip software
 * and any derivatives exclusively with Microchip products. You are responsible for 
 * complying with third party license terms applicable to your use of third party 
 * software (including open source software) that may accompany this Microchip software.
 
 * SOFTWARE IS ?AS IS.? NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO 
 * THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, 
 * SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF 
 * THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, 
 * MICROCHIP?S TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT EXCEED AMOUNT 
 * OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE. ADDITIONALLY, MICROCHIP 
 * OFFERS NO SUPPORT FOR THE SOFTWARE. YOU MAY CONTACT YOUR LOCAL MICROCHIP FIELD SALES SUPPORT 
 * REPRESENTATIVE TO INQUIRE ABOUT SUPPORT SERVICES AND APPLICABLE FEES, IF ANY. THESE TERMS 
 * OVERRIDE ANY OTHER PRIOR OR SUBSEQUENT TERMS OR CONDITIONS THAT MIGHT APPLY TO THIS SOFTWARE 
 * AND BY USING THE SOFTWARE, YOU AGREE TO THESE TERMS. 
*******************************************************************************************/

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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "fan_click.h"
#include "../src/weather_click/include/bme280_definitions.h"
#include "../src/weather_click/include/bme280_driver.h"
#include "definitions.h"
#include "stdio.h"
// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
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

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

leFixedString startStr;
static leChar currTimeStr[15];



/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */
typedef struct
{
    volatile bool                   isBufferCompleteEvent;
    uint8_t                         slaveID;
    int16_t                         temperature;
    uint8_t                         txBuffer[100];
    uint8_t                         rxBuffer[100];
}BME_SENSOR_DATA;    
static BME_SENSOR_DATA BME280SensorData;

volatile bool                   i2cBufferCompleteEvent;

static void I2CBufferEventHandler(uintptr_t context)
{        
    if (SERCOM0_I2C_ErrorGet() == SERCOM_I2C_ERROR_NONE)
    {
        BME280SensorData.isBufferCompleteEvent = true;
        i2cBufferCompleteEvent = true;
    }
}

static bool BME280Sensor_WriteReg(uint8_t wrAddr, uint8_t wrData) 
{    
    BME280SensorData.txBuffer[0]            = wrAddr;
    BME280SensorData.txBuffer[1]            = wrData;
    BME280SensorData.isBufferCompleteEvent  = false;
    
    SERCOM0_I2C_Write(BME280SensorData.slaveID, BME280SensorData.txBuffer, 2);
    
    while(false == BME280SensorData.isBufferCompleteEvent);
    
    return true;
}

static uint8_t BME280Sensor_ReadReg(uint8_t rAddr) 
{
    BME280SensorData.txBuffer[0]            = rAddr;
    BME280SensorData.isBufferCompleteEvent  = false;
    
    SERCOM0_I2C_WriteRead(BME280SensorData.slaveID, BME280SensorData.txBuffer, 1, BME280SensorData.rxBuffer, 1);
    
    while(false == BME280SensorData.isBufferCompleteEvent);
            
    return BME280SensorData.rxBuffer[0];    
}

static bool BME280Sensor_Read(uint8_t rAddr, uint8_t* const pReadBuffer, uint8_t nBytes) 
{
    BME280SensorData.txBuffer[0]            = rAddr;
    BME280SensorData.isBufferCompleteEvent  = false;
    
    SERCOM0_I2C_WriteRead(BME280SensorData.slaveID, BME280SensorData.txBuffer, 1, pReadBuffer, nBytes);
    
    while(false == BME280SensorData.isBufferCompleteEvent);
            
    return true;
}

void BME280Sensor_Initialize(void)
{
    BME280SensorData.temperature   = 0;
    BME280SensorData.slaveID        = BME280_I2C_ADDRESS;
    BME280SensorData.isBufferCompleteEvent = false;
    
    /* Register with BME280 sensor */        
    BME280_RegisterDrvWriteReg(BME280Sensor_WriteReg);
    BME280_RegisterDrvReadReg(BME280Sensor_ReadReg);        
    BME280_RegisterDrvRead(BME280Sensor_Read);

    BME280_SoftReset();
    /* 100 m.sec delay */
   SYSTICK_DelayMs(100);

    if (BME280_CHIP_ID != BME280_ID_Get())
    {
        while(1);       /* Error Occurred */
    }
    BME280_CalibParams_Get();
    BME280_SetOversampling(BME280_PARAM_TEMP, BME280_OVERSAMPLING_1X);
    BME280_PowerMode_Set(BME280_NORMAL_MODE);
}

//uint8_t uartTxBuffer[20] = {0};

static uint16_t      temperatureVal;

void APP_Tasks ( void )
{   
    static char currTimeStr[15];           
    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            BME280Sensor_Initialize();
            SYSTICK_DelayMs(100);
            fan_click_init();
            fan_click_set_target_tach(0x1);
            SYSTICK_DelayMs(100);  
            appData.state = APP_STATE_SERVICE_TASKS;
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
            BME280_ReadRawWeatherData();

            /* The getting temperature is in DegC and resolution is 0.01 DegC. 
             * It means, if the output value is 5123 equals to 51.23 DegC */
            BME280SensorData.temperature   = BME280_GetTempReading();
                /* Celcius to Fahrenheit (°C to °F) Conversion (°F = (°C × 9/5) + 32) */
            temperatureVal = ((BME280SensorData.temperature * 9 / 5) * 0.01) + 32;
            
            sprintf( currTimeStr, "Temp = %02dF",temperatureVal);//
            startStr.fn->setFromCStr(&startStr, currTimeStr);
            Screen0_TextFieldWidget0->fn->setString(Screen0_TextFieldWidget0, (leString*)&startStr);
            
            if(temperatureVal >= 80)           //Temperature is greater than or equal to 27 C
            {
               fan_click_set_target_tach(0x1); // Fans rotates Fastly
            }else if(temperatureVal <= 68){    //Temperature is greater than or equal to 27 C
               fan_click_set_target_tach(0x0); // Zero internally sends 0XFF, switch off's the fan
            }else{
               fan_click_set_target_tach(0x7F); //  Rotates normally 
            }
            break;
        }

        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}
void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;

    leFixedString_Constructor(&startStr, currTimeStr, 10);
    startStr.fn->setFont(&startStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              string_String.index,
                                                              0));

    SERCOM0_I2C_CallbackRegister(I2CBufferEventHandler, 0);

    SYSTICK_TimerStart();
}

/*******************************************************************************
 End of File
 */
