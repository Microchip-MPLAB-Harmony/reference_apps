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
