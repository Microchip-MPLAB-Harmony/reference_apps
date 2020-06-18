/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_eeprom.c

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

#include "app_eeprom.h"
#include "usart_common.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
#define APP_EEPROM_I2C_CLOCK_SPEED                  400000
#define APP_EEPROM_I2C_SLAVE_ADDR                   0x0050
#define APP_EEPROM_LOG_MEMORY_ADDR                  0x00
#define APP_EEPROM_MAX_LOG_VALUES                   5
// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_EEPROM_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_EEPROM_DATA app_eepromData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/******************************************************************************
  Function:
    void APP_EEPROM_I2CEventHandler (
    DRV_I2C_TRANSFER_EVENT event,
    DRV_I2C_TRANSFER_HANDLE transferHandle,
    uintptr_t context
   )

  Remarks:
    This function is registered by the EEPROM application client with the I2C
    driver. It is called by the I2C Driver when the requested I2C transfer is
    complete.
 */
void APP_EEPROM_I2CEventHandler(
    DRV_I2C_TRANSFER_EVENT event,
    DRV_I2C_TRANSFER_HANDLE transferHandle,
    uintptr_t context
)
{
    switch(event)
    {
        case DRV_I2C_TRANSFER_EVENT_COMPLETE:
            /* I2C read complete. */
            app_eepromData.reqStatus = APP_EEPROM_REQ_STATUS_DONE;
            break;
        case DRV_I2C_TRANSFER_EVENT_ERROR:
            app_eepromData.reqStatus = APP_EEPROM_REQ_STATUS_ERROR;
            break;
        default:
            break;
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************
/*******************************************************************************
  Function:
    void APP_EEPROM_PrintTemperature ( uint8_t* , uint8_t )

  Remarks:
    Prints the logged temperature values with oldest value first and latest value
    last
 */
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

    DRV_USART_WriteBufferAdd(usartHandle, (void*)app_eepromData.usartTxBuffer, len,
            &usartWriteBufferHandle);
}

/******************************************************************************
  Function:
    void APP_EEPROM_SetTempWriteRequest ( int8_t )

  Remarks:
    This function is called by the sensor task to let the EEPROM task know that
    the new temperature value. The EEPROM task then writes it to the EEPROM.
 */
void APP_EEPROM_SetTempWriteRequest(int8_t temperature)
{
    app_eepromData.temperature = temperature;
    app_eepromData.isEEPROMTempWriteReq = true;
}

/******************************************************************************
  Function:
    void _APP_EEPROM_Write ( int8_t temperature )

  Remarks:
    This function writes temperature value to EEPROM and polls the status of
    EEPROM until its internal write cycle is complete.
 */
 static void _APP_EEPROM_Write(int8_t temperature)
 {
    uint8_t dummyData = 0;

    app_eepromData.i2cTxBuffer[0] = APP_EEPROM_LOG_MEMORY_ADDR + app_eepromData.wrIndex;
    app_eepromData.i2cTxBuffer[1] = temperature;

    app_eepromData.reqStatus = APP_EEPROM_REQ_STATUS_IN_PROGRESS;

    /* Submit I2C transfer to store the temperature value in EEPROM */
    DRV_I2C_WriteTransferAdd(app_eepromData.i2cHandle, APP_EEPROM_I2C_SLAVE_ADDR,
        (void *)app_eepromData.i2cTxBuffer, 2, &app_eepromData.transferHandle);

    if (app_eepromData.transferHandle == DRV_I2C_TRANSFER_HANDLE_INVALID)
    {
        /* Handle error condition */
    }

    /* Wait till the transfer completes. Status is updated in the I2C callback */
    while (app_eepromData.reqStatus == APP_EEPROM_REQ_STATUS_IN_PROGRESS);

    do
    {
        /* EEPROM will NAK all requests until internal write cycle completes */
        app_eepromData.reqStatus = APP_EEPROM_REQ_STATUS_IN_PROGRESS;

        DRV_I2C_WriteTransferAdd(app_eepromData.i2cHandle, APP_EEPROM_I2C_SLAVE_ADDR,
                (void *)&dummyData, 1, &app_eepromData.transferHandle);

        if (app_eepromData.transferHandle == DRV_I2C_TRANSFER_HANDLE_INVALID)
        {
            /* Handle error condition */
        }

        while (app_eepromData.reqStatus == APP_EEPROM_REQ_STATUS_IN_PROGRESS);

    }while (app_eepromData.reqStatus == APP_EEPROM_REQ_STATUS_ERROR);

    /* Increment the EEPROM memory index */
    if (++app_eepromData.wrIndex >= APP_EEPROM_MAX_LOG_VALUES)
    {
        app_eepromData.wrIndex = 0;
    }
 }

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_EEPROM_Initialize ( void )

  Remarks:
    See prototype in app_eeprom.h.
 */

void APP_EEPROM_Initialize ( void )
{
    /* Place the EEPROM application state machine in its initial state. */
    app_eepromData.state = APP_EEPROM_STATE_INIT;
}


/******************************************************************************
  Function:
    void APP_EEPROM_Tasks ( void )

  Remarks:
    See prototype in app_eeprom.h.
 */

void APP_EEPROM_Tasks ( void )
{
    /* Check the application's current state. */
    switch ( app_eepromData.state )
    {
        /* Application's initial state. */
        case APP_EEPROM_STATE_INIT:

            /* Open I2C Driver to interface with EEPROM. */
            app_eepromData.i2cHandle = DRV_I2C_Open( DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE );

            if (app_eepromData.i2cHandle != DRV_HANDLE_INVALID)
            {
                app_eepromData.i2cSetup.clockSpeed = APP_EEPROM_I2C_CLOCK_SPEED;

                /* Setup I2C transfer @ 400 kHz to interface with EEPROM. */
                DRV_I2C_TransferSetup(app_eepromData.i2cHandle, &app_eepromData.i2cSetup);

                /* Register I2C transfer complete Event Handler for EEPROM. */
                DRV_I2C_TransferEventHandlerSet(app_eepromData.i2cHandle, APP_EEPROM_I2CEventHandler, 0);

                /* Submit a USART read request to read the entered character */
                if (usartHandle != DRV_HANDLE_INVALID)
                {
                    DRV_USART_ReadBufferAdd(usartHandle, (void*)app_eepromData.usartRxBuffer, 1,
                    &usartReadBufferHandle);

                    /* Initialization done. Enter idle state and wait for events */
                    app_eepromData.state = APP_EEPROM_STATE_IDLE;
                }
                else
                {
                    /* Handle error condition */
                    app_eepromData.state = APP_EEPROM_STATE_ERROR;
                }
            }
            else
            {
                /* Handle error condition */
                app_eepromData.state = APP_EEPROM_STATE_ERROR;
            }
            break;

        case APP_EEPROM_STATE_WRITE_TEMP_TO_EEPROM:

            /* Log the new temperature value to EEPROM */
            _APP_EEPROM_Write(app_eepromData.temperature);

            /* Go back to the idle state and wait for events */
            app_eepromData.state = APP_EEPROM_STATE_IDLE;
            break;

        case APP_EEPROM_STATE_READ_TEMP_FROM_EEPROM:
            /* Read temperature values from EEPROM */

            app_eepromData.i2cTxBuffer[0] = APP_EEPROM_LOG_MEMORY_ADDR;
            app_eepromData.reqStatus = APP_EEPROM_REQ_STATUS_IN_PROGRESS;

            /*Submit I2C transfer to read stored temperature values from EEPROM. */


            DRV_I2C_WriteReadTransferAdd(app_eepromData.i2cHandle, APP_EEPROM_I2C_SLAVE_ADDR,
                    app_eepromData.i2cTxBuffer, 1, app_eepromData.i2cRxBuffer, 5,
                    &app_eepromData.transferHandle);

			if (app_eepromData.transferHandle == DRV_I2C_TRANSFER_HANDLE_INVALID)
            {
                /* Handle error condition */
            }

            /* Wait for the I2C read to complete. The status is updated in the I2C event handler */
            while (app_eepromData.reqStatus == APP_EEPROM_REQ_STATUS_IN_PROGRESS);

            /* Now print the read EEPROM values to the serial terminal */
            app_eepromData.state = APP_EEPROM_STATE_PRINT_TEMPERATURE;
            break;

        case APP_EEPROM_STATE_PRINT_TEMPERATURE:
            /* Print the logged temperature values on the terminal */

            /* Make sure the USART is ready to write new data */
            if (isUsartWriteCompleted == true)
            {
                isUsartWriteCompleted = false;

                /* Print the values read from EEPROM to serial Terminal */
                APP_EEPROM_PrintTemperature(app_eepromData.i2cRxBuffer, app_eepromData.wrIndex);

                /* Submit a USART read request to read the entered character */
                DRV_USART_ReadBufferAdd(usartHandle, (void*)app_eepromData.usartRxBuffer, 1,
                    &usartReadBufferHandle);

                /* Go back to the idle state and wait for events */
                app_eepromData.state = APP_EEPROM_STATE_IDLE;
            }
            break;

        case APP_EEPROM_STATE_IDLE:
            /* Transition to the appropriate state based on the events */

            if (app_eepromData.isEEPROMTempWriteReq == true)
            {
                /* Temperature write request received */
                app_eepromData.isEEPROMTempWriteReq = false;
                app_eepromData.state = APP_EEPROM_STATE_WRITE_TEMP_TO_EEPROM;
            }
            else if (usartReadRequest == true)
            {
                /* Temperature read request received */
                usartReadRequest = false;
                app_eepromData.state = APP_EEPROM_STATE_READ_TEMP_FROM_EEPROM;
            }
            break;

        case APP_EEPROM_STATE_ERROR:
            /* Handle error conditions here */
            break;

        default:
            break;

    }
}
/*******************************************************************************
 End of File
 */
