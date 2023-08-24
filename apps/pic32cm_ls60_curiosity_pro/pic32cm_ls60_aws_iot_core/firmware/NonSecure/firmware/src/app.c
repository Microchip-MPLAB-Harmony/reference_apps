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

/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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
#include "../src/common/cloud_wifi_config.h"
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

static char printBuff[APP_PRINT_BUFFER_SIZ] __attribute__((aligned(4)));
static int printBuffPtr;
static OSAL_MUTEX_HANDLE_TYPE consoleMutex;
void WiFi_ProvisionCb(uint8_t sectype, uint8_t * SSID, uint8_t * password);
char config_thing_id[130] =  "BAAAAADD1DBAAADD1D";
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
void set_deviceId(char *id);
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

static void APP_DebugPrint(uint8_t *pBuf, size_t len)
{
    if ((len > 0) && (len < APP_PRINT_BUFFER_SIZ))
    {
        if (OSAL_RESULT_TRUE == OSAL_MUTEX_Lock(&consoleMutex, OSAL_WAIT_FOREVER))
        {
            if ((len + printBuffPtr) > APP_PRINT_BUFFER_SIZ)
            {
                printBuffPtr = 0;
            }

            memcpy(&printBuff[printBuffPtr], pBuf, len);
            SYS_CONSOLE_Write(0, &printBuff[printBuffPtr], len);

            printBuffPtr = (printBuffPtr + len + 3) & ~3;

            OSAL_MUTEX_Unlock(&consoleMutex);
        }
    }
}

void APP_DebugPrintf(const char* format, ...)
{
    char tmpBuf[APP_PRINT_BUFFER_SIZ];
    size_t len = 0;
    va_list args;
    va_start( args, format );

    len = vsnprintf(tmpBuf, APP_PRINT_BUFFER_SIZ, format, args);

    va_end( args );

    APP_DebugPrint((uint8_t*)tmpBuf, len);
}

char APP_HexToChar(uint8_t hex)
{
    if (hex < 10)
        return '0' + hex;

    if (hex < 16)
        return 'A' + (hex - 10);

    return '-';
}

void APP_DebugPrintBuffer(const uint8_t *pBuf, uint16_t bufLen)
{
    uint8_t tmpBuf[APP_PRINT_BUFFER_SIZ];
    size_t len = 0;
    uint16_t i;
    uint8_t *pB;

    if ((NULL == pBuf) || (0 == bufLen))
        return;

    if (bufLen > (APP_PRINT_BUFFER_SIZ/2))
        bufLen = (APP_PRINT_BUFFER_SIZ/2);

    pB = tmpBuf;
    for (i=0; i<bufLen; i++)
    {
        *pB++ = APP_HexToChar((pBuf[i] & 0xf0) >> 4);
        *pB++ = APP_HexToChar(pBuf[i] & 0x0f);
    }

    len = bufLen*2;

    APP_DebugPrint(tmpBuf, len);
}

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

void APP_Initialize(void)
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;
    config_set_thing_id();
    
    #ifdef CFG_ENABLE_CLI     
        set_deviceId(config_thing_id);
    #endif   
        debug_init(config_thing_id);
    //printBuffPtr = 0;
    //OSAL_MUTEX_Create(&consoleMutex);
    
    debug_printInfo("App Initialize");
  //  WiFi_ProvisionCb(2,(uint8_t *)WLAN_SSID,(uint8_t *)WLAN_PSK);
    WDRV_WINC_DebugRegisterCallback(debug_printf);
    
     sys_cmd_init();
    
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */
float APP_GetTempSensorValue(void)
{
    float retVal = 0;
    /* TA: AMBIENT TEMPERATURE REGISTER ADDRESS: 0x00 */
    uint8_t registerAddr = 0x00;
    /* Temp sensor read buffer */
    uint8_t rxBuffer[2];
    
    while (SERCOM5_I2C_IsBusy() == true);
    if (SERCOM5_I2C_WriteRead(0x004F, (uint8_t *)&registerAddr, 1, (uint8_t *)rxBuffer, 2) == true) {        
        /* Wait for the I2C transfer to complete */
        while (SERCOM5_I2C_IsBusy() == true);

        /* Transfer complete. Check if the transfer was successful */
        if (SERCOM5_I2C_ErrorGet() == SERCOM_I2C_ERROR_NONE) {
            int16_t temp;
           temp = (rxBuffer[0] << 8) | rxBuffer[1];
           temp = (temp >> 7) * 0.5;
           temp = (temp * 9/5) + 32;
           retVal = temp;
        }                   
    }            
    return retVal;
}        

//int32_t APP_GetLightSensorValue(void)
//{
//    uint32_t input_voltage = 0;
//    int32_t retVal = 0;
//    uint16_t adc_count = 0;
//            
//    //Obtain result from Light sensor 
//    while(!ADC_ConversionStatusGet());
//    /* Read the ADC result */
//    adc_count = ADC_ConversionResultGet();
//    input_voltage = adc_count * 1650 / 4095U;
//    //retVal = adc_count; 
//    retVal = input_voltage;
//    retVal=((3300 - retVal)*20)/1000;
//    return retVal;
//}        
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
                //APP_ExampleInitialize(wdrvHandle);
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
