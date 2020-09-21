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

#include <stdio.h>
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <string.h>
#include "definitions.h"                // SYS function prototypes
#include "trustZone/nonsecure_entry.h"

#define EEPROM_MAX_LOG_VALUES                   5

static volatile bool isUSARTTxComplete = false;
static volatile bool isUSARTRxComplete = false;
static volatile bool isEEPROMReadReq = false;
static volatile bool isTemperatureRead = false;
static uint8_t nonSecureUartTxBuffer[100] = {0};
static uint8_t uartRxBuffer[1] = {0};
static uint8_t eepromRxBuffer[6] = {0};
static uint8_t wrIndex  = 0;

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************
/*******************************************************************************
  Function:
    void EEPROM_PrintTemperature ( uint8_t* , uint8_t )

  Remarks:
    Prints the logged temperature values with oldest value first and latest value
    last
 */
void EEPROM_PrintTemperature(uint8_t* pTemperatureValue, uint8_t wrIndex)
{
    char* pBuffer = (char*)nonSecureUartTxBuffer;
    uint8_t len;
    uint8_t i;

    len = sprintf((char*)pBuffer, "EEPROM:");
    for (i = wrIndex; i < EEPROM_MAX_LOG_VALUES; i++)
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

    DMAC_ChannelTransfer(DMAC_CHANNEL_0, nonSecureUartTxBuffer, \
            (const void *)&(SERCOM0_REGS->USART_INT.SERCOM_DATA), \
            strlen((const char*)nonSecureUartTxBuffer));
}

static void usartTxDmaChannelHandler(DMAC_TRANSFER_EVENT event, uintptr_t contextHandle)
{
    if (event == DMAC_TRANSFER_EVENT_COMPLETE)
    {
        isUSARTTxComplete = true;
    }
}

static void usartRxDmaChannelHandler(DMAC_TRANSFER_EVENT event, uintptr_t contextHandle)
{
    if (event == DMAC_TRANSFER_EVENT_COMPLETE)
    {
        isEEPROMReadReq = true;
    }
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

    DMAC_ChannelCallbackRegister(DMAC_CHANNEL_0, usartTxDmaChannelHandler, 0);
    DMAC_ChannelCallbackRegister(DMAC_CHANNEL_1, usartRxDmaChannelHandler, 0);

    DMAC_ChannelTransfer(DMAC_CHANNEL_1, (const void *)&(SERCOM0_REGS->USART_INT.SERCOM_DATA), \
            uartRxBuffer, 1);
    while ( true )
    {
        if (readTemperatureData(nonSecureUartTxBuffer) == true)
        {
            // Printing Temperature value read from Sensor
            DMAC_ChannelTransfer(DMAC_CHANNEL_0, nonSecureUartTxBuffer, \
                    (const void *)&(SERCOM0_REGS->USART_INT.SERCOM_DATA), \
                    strlen((const char*)nonSecureUartTxBuffer));
        }
        if (isEEPROMReadReq == true)       //Request to Temperature Reading from EEPROM
        {
            isEEPROMReadReq     = false;
            readEEPROMTemperatureDataReq(&eepromRxBuffer[1]);
        }
        if (getEEPROMTemperatureDataReadStatus(&wrIndex) == true)   //Printing Temperature values read from EEPROM
        {
            isEEPROMReadReq = false;
            EEPROM_PrintTemperature(&eepromRxBuffer[1], wrIndex);
            DMAC_ChannelTransfer(DMAC_CHANNEL_1, (const void *)&(SERCOM0_REGS->USART_INT.SERCOM_DATA), \
                &uartRxBuffer[1], 1);
        }
        secureAppEntry();
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

