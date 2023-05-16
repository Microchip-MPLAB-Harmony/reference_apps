/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_eeprom_thread.c

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

#include "app_eeprom_thread.h"
#include <stdio.h>

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
#define APP_EEPROM_I2C_CLOCK_SPEED                  400000
#define APP_EEPROM_I2C_SLAVE_ADDR                   0x57
#define APP_EEPROM_LOG_MEMORY_ADDR                  0x00
#define APP_EEPROM_MAX_LOG_VALUES                   5
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_EEPROM_THREAD_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_EEPROM_THREAD_DATA app_eepromData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

void APP_EEPROM_PrintTemperature(uint8_t* pTemperatureValue, uint8_t wrIndex)
{
    char* pBuffer = (char*)app_eepromData.usartTxBuffer;
    uint8_t len;
    uint8_t i;
    
    len = sprintf((char*)pBuffer, "EEPROM:");
    for (i = wrIndex; i < APP_EEPROM_MAX_LOG_VALUES; i++)
    {
        len += sprintf((char*)&pBuffer[len], "%dF|", (int8_t)pTemperatureValue[i]);
    }
    if (wrIndex > 0)
    {
        for (i = 0; i < wrIndex; i++ )
        {
            len += sprintf((char*)&pBuffer[len], "%dF|", (int8_t)pTemperatureValue[i]);
        }
    }
    len += sprintf((char*)&pBuffer[len], "\r\n");    
    
    DRV_USART_WriteBuffer(app_eepromData.usartHandle,\
            app_eepromData.usartTxBuffer, len);
}


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
    void APP_EEPROM_THREAD_Initialize ( void )

  Remarks:
    See prototype in app_eeprom_thread.h.
 */

void APP_EEPROM_THREAD_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    
    app_eepromData.isInitDone = false; 
}


/******************************************************************************
  Function:
    void APP_EEPROM_THREAD_Tasks ( void )

  Remarks:
    See prototype in app_eeprom_thread.h.
 */

void APP_EEPROM_THREAD_Tasks ( void )
{

   uint8_t dummyData;                
    
    /* Open the drivers if not already opened */
    if (app_eepromData.isInitDone == false)
    {
            app_eepromData.i2cHandle = DRV_I2C_Open( DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE );
            if (app_eepromData.i2cHandle != DRV_HANDLE_INVALID)        
             {
            app_eepromData.i2cSetup.clockSpeed = APP_EEPROM_I2C_CLOCK_SPEED;
                
            DRV_I2C_TransferSetup(app_eepromData.i2cHandle, &app_eepromData.i2cSetup);
             }
            
            else
            {
                /* Handle error */
            }
            
            
            app_eepromData.usartHandle = DRV_USART_Open(DRV_USART_INDEX_0, 0);
            
            if (app_eepromData.usartHandle != DRV_HANDLE_INVALID)
            {
            /* All drivers opened successfully */
            app_eepromData.isInitDone = true;
            }
            else
            {
            /* Handle error */
            }
    }        
            xQueueReceive( eventQueue, &app_eepromData.eventInfo, portMAX_DELAY );
            
      if (app_eepromData.eventInfo.eventType == EVENT_TYPE_TEMP_WRITE_REQ)
       {
          app_eepromData.i2cTxBuffer[0] = APP_EEPROM_LOG_MEMORY_ADDR + app_eepromData.wrIndex;        
          app_eepromData.i2cTxBuffer[1] = (uint8_t)app_eepromData.eventInfo.eventData;   /* <--contains temperature */

          /* Write temperature to EEPROM */
            
            if (true == DRV_I2C_WriteTransfer(app_eepromData.i2cHandle, APP_EEPROM_I2C_SLAVE_ADDR, (void *)app_eepromData.i2cTxBuffer, 2))
            {                
            /* Check if EEPROM has completed the write operation */
            while (false == DRV_I2C_WriteTransfer(app_eepromData.i2cHandle, APP_EEPROM_I2C_SLAVE_ADDR, (void *)&dummyData, 1));
            }
        
             app_eepromData.wrIndex++;
             if (app_eepromData.wrIndex >= APP_EEPROM_MAX_LOG_VALUES)
                {
                app_eepromData.wrIndex = 0;
                }
       }
    
    if (app_eepromData.eventInfo.eventType == EVENT_TYPE_TEMP_READ_REQ)
        {                        
            app_eepromData.i2cTxBuffer[0] = APP_EEPROM_LOG_MEMORY_ADDR;        

           
            if (true == DRV_I2C_WriteReadTransfer(app_eepromData.i2cHandle, \
                APP_EEPROM_I2C_SLAVE_ADDR, app_eepromData.i2cTxBuffer, 1,\
                app_eepromData.i2cRxBuffer, 5))
            {
                APP_EEPROM_PrintTemperature(app_eepromData.i2cRxBuffer, app_eepromData.wrIndex);
            } 
                
        }
}        

   

/*******************************************************************************
 End of File
 */
