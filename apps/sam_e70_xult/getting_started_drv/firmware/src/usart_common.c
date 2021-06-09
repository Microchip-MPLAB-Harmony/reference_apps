/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    usart_common.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the common USART application
    functions used between the sensor and eeprom tasks.
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

#include "usart_common.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

DRV_HANDLE usartHandle;
DRV_USART_BUFFER_HANDLE usartWriteBufferHandle;
DRV_USART_BUFFER_HANDLE usartReadBufferHandle;  
volatile bool isUsartWriteCompleted;
volatile bool usartReadRequest;

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
void APP_USARTBufferEventHandler( 
    DRV_USART_BUFFER_EVENT event, 
    DRV_USART_BUFFER_HANDLE bufferHandle, 
    uintptr_t context 
)
{
    switch (event)
    {
        case DRV_USART_BUFFER_EVENT_COMPLETE:
            if(bufferHandle == usartWriteBufferHandle)
            {
                isUsartWriteCompleted = true;
            }
            
            if(bufferHandle == usartReadBufferHandle)
            {
                usartReadRequest = true;
            }
            break;

        case DRV_USART_BUFFER_EVENT_ERROR:
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
 End of File
 */
