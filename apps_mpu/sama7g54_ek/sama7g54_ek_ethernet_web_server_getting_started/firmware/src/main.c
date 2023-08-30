/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes


#define APP_TMP102_DEVICE_ADDR         (0x48)
#define APP_ACK_DATA_LENGTH            (3)
/* TWI status enum*/
typedef enum
{
    APP_TRANSFER_STATUS_IN_PROGRESS,
    APP_TRANSFER_STATUS_SUCCESS,
    APP_TRANSFER_STATUS_ERROR,
    APP_TRANSFER_STATUS_IDLE,

} APP_TRANSFER_STATUS;


volatile APP_TRANSFER_STATUS transferStatus = APP_TRANSFER_STATUS_ERROR; 

/***********************************************************************************/
/*                                                                                 */
/*   Name:   APP_FLEXCOMTWICallback                                                */
/*                                                                                 */
/*   Arguments: uintptr_t                                                          */
/*                                                                                 */
/*   Return: None                                                                  */
/*                                                                                 */
/*   Description: This function is call back function registered for TWI.          */
/*                                                                                 */
/***********************************************************************************/
void APP_FLEXCOMTWICallback(uintptr_t context )
{
    APP_TRANSFER_STATUS* transferStatus = (APP_TRANSFER_STATUS*)context;

    if(FLEXCOM9_TWI_ErrorGet() == FLEXCOM_TWI_ERROR_NONE)
    {
        if (transferStatus)
        {
            *transferStatus = APP_TRANSFER_STATUS_SUCCESS;
        }
    }
    else
    {
        if (transferStatus)
        {
            *transferStatus = APP_TRANSFER_STATUS_ERROR;
        }
    }
}
/***********************************************************************************/
/*                                                                                 */
/*   Name:   Thermo_3_Click_Cfg                                                    */
/*                                                                                 */
/*   Arguments: None                                                               */
/*                                                                                 */
/*   Return: None                                                                  */
/*                                                                                 */
/*   Description: This function configures the TMP102 temperature sensor module.   */
/*                                                                                 */
/***********************************************************************************/
void Thermo_3_Click_Cfg(void)
{
    uint8_t Txbuf[3] = {0};
    /* Register the FLEXCOM TWI Callback with transfer status as context */
    FLEXCOM9_TWI_CallbackRegister( APP_FLEXCOMTWICallback, (uintptr_t)&transferStatus );
    
    while(FLEXCOM9_TWI_IsBusy( ));
    
    Txbuf[0] = 0x01;
    Txbuf[1] = 0x60;
    Txbuf[2] = 0xA0;
            
    FLEXCOM9_TWI_Write(APP_TMP102_DEVICE_ADDR,&Txbuf[0], APP_ACK_DATA_LENGTH);
    
    while(FLEXCOM9_TWI_IsBusy( ));
    if (transferStatus == APP_TRANSFER_STATUS_SUCCESS)
    {
        SYS_CONSOLE_MESSAGE("Temperature Sensor Config Success \r\n");        
    }
    else
    {
        SYS_CONSOLE_MESSAGE("Temperature Sensor Config Fail\r\n");
    }   
}

/***********************************************************************************/
/*                                                                                 */
/*   Name:   Thermo_3_Click_Cfg                                                    */
/*                                                                                 */
/*   Arguments: None                                                               */
/*                                                                                 */
/*   Return: float                                                                 */
/*                                                                                 */
/*   Description: This function returns the temperature data read from temperature */
/*                sensor.                                                           */
/*                                                                                 */
/***********************************************************************************/
float Thermo_3_Click_Get_Temp()
{
    uint8_t TxData = 0;
    uint8_t txDataTemp[2] = { 0 };
    uint16_t temperature_sum = 0;
    float temperature = 0.0;
    
    TxData = 0x00;
    FLEXCOM9_TWI_Write(APP_TMP102_DEVICE_ADDR,&TxData, 1);  
    
    while(FLEXCOM9_TWI_IsBusy( ));
    if (transferStatus == APP_TRANSFER_STATUS_SUCCESS)
    {                    
        txDataTemp[0] = 0x00;
        FLEXCOM9_TWI_Read(APP_TMP102_DEVICE_ADDR,&txDataTemp[0], 2);
    }    
    
    while(FLEXCOM9_TWI_IsBusy( ));
    
    if (transferStatus == APP_TRANSFER_STATUS_SUCCESS)
    {       
        temperature_sum = ((txDataTemp[0] << 8) | txDataTemp[1] ) >> 4;           
        temperature = (float)temperature_sum * 0.0625;       
    }
    return temperature;
}
// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
          
    /*Configure Temperature sensor*/
    Thermo_3_Click_Cfg();
    
    /*Get and print temperature value read from temperature sensor*/
    SYS_CONSOLE_PRINT("Temp:%.2f\r\n",Thermo_3_Click_Get_Temp());
    
    /*Blue Led turned ON*/
    LED_BLUE_On();
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

