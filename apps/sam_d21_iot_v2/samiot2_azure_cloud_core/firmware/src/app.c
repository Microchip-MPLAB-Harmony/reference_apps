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
    (c) 2022 Microchip Technology Inc. and its subsidiaries. You may use this
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

#include <stdlib.h>
#include "app.h"
//#include "osal/osal.h"
#include "wdrv_winc_client_api.h"
#include "stdarg.h"
#include "debug_print.h"
#include "cloud_wifi_config.h"
#include "IoT_Sensor_Node_config.h"
void APP_ExampleInitialize(DRV_HANDLE handle);
void APP_ExampleTasks(DRV_HANDLE handle);
extern void sys_cmd_init();
#define APP_PRINT_BUFFER_SIZ    2048


// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************/

static DRV_HANDLE wdrvHandle;
void set_deviceId(char *id);
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
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */
static void testSequence (uint8_t ledState)
{
    if(LED_OFF == ledState){
        LED_BLUE_SetHigh();
        SYSTICK_DelayMs(300);
        LED_GREEN_SetHigh();
         SYSTICK_DelayMs(300);
        LED_YELLOW_SetHigh();
         SYSTICK_DelayMs(300);
        LED_RED_SetHigh();
         SYSTICK_DelayMs(300);
    } else {
        LED_BLUE_SetLow();
        SYSTICK_DelayMs(300);
        LED_GREEN_SetLow();
        SYSTICK_DelayMs(300);
        LED_YELLOW_SetLow();
         SYSTICK_DelayMs(300);
        LED_RED_SetLow();
         SYSTICK_DelayMs(300);
    }
}

void LED_test(void)
{
	testSequence(LED_ON);
	testSequence(LED_OFF);
}
void WiFi_ProvisionCb(uint8_t sectype, uint8_t * SSID, uint8_t * password);
char config_thing_id[130] =  "BAAAAADD1DBAAADD1D";

void APP_Initialize(void)
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;
    SYSTICK_TimerStart();
     LED_test();
    config_set_thing_id();
    
#ifdef CFG_ENABLE_CLI     
        set_deviceId(config_thing_id);
#endif   
        debug_init(config_thing_id); 
    
        debug_printInfo("App Initialize");
    
   WiFi_ProvisionCb(2,(uint8_t *)WLAN_SSID,(uint8_t *)WLAN_PSK);
    
    ADC_Enable();  
   
    WDRV_WINC_DebugRegisterCallback(debug_printf);
     sys_cmd_init();
    
}

float APP_GetTempSensorValue(void)
{
    float retVal = 0;
    /* TA: AMBIENT TEMPERATURE REGISTER ADDRESS: 0x5 */
    uint8_t registerAddr = 0x5;
    /* Temp sensor read buffer */
    uint8_t rxBuffer[2];
    
    while (SERCOM3_I2C_IsBusy() == true);
    if (SERCOM3_I2C_WriteRead(0x18, (uint8_t *)&registerAddr, 1, (uint8_t *)rxBuffer, 2) == true) {        
        /* Wait for the I2C transfer to complete */
        while (SERCOM3_I2C_IsBusy() == true);

        /* Transfer complete. Check if the transfer was successful */
        if (SERCOM3_I2C_ErrorGet() == SERCOM_I2C_ERROR_NONE) {
            rxBuffer[0] = rxBuffer[0] & 0x1F; //Clear flag bits
            if ((rxBuffer[0] & 0x10) == 0x10) { 
                rxBuffer[0] = rxBuffer[0] & 0x0F; //Clear SIGN
                retVal = 256.0 - (rxBuffer[0] * 16.0 + rxBuffer[1] / 16.0);
            } else {
                retVal = ((rxBuffer[0] * 16.0) + (rxBuffer[1] / 16.0));
            }
        }                   
    }            
    return retVal;
}        

int32_t APP_GetLightSensorValue(void)
{
    uint32_t input_voltage = 0;
    int32_t retVal = 0;
    uint16_t adc_count = 0;
            
    //Obtain result from Light sensor 
    while(!ADC_ConversionStatusGet());
    /* Read the ADC result */
    adc_count = ADC_ConversionResultGet();
    input_voltage = adc_count * 1650 / 4095U;
    retVal = input_voltage;
    
    return retVal;
}        

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks(void)
{
    switch(appData.state)
    {
        case APP_STATE_INIT:
        {
            if (SYS_STATUS_READY == WDRV_WINC_Status(sysObj.drvWifiWinc))
            {
                appData.state = APP_STATE_WDRV_INIT_READY;
            }

            break;
        }

        case APP_STATE_WDRV_INIT_READY:
        {
            wdrvHandle = WDRV_WINC_Open(0, (int)NULL);

            if (DRV_HANDLE_INVALID != wdrvHandle)
            {
                appData.state = APP_STATE_WDRV_OPEN;
            }
            break;
        }

        case APP_STATE_WDRV_OPEN:
        {
            APP_ExampleTasks(wdrvHandle);
            break;
        }

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
