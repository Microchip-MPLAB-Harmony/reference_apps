/*******************************************************************************
  BM71 Bluetooth Static Driver implementation

  Company:
    Microchip Technology Inc.

  File Name:
    custom_bm71_uart.c

  Summary:
   BM71 Bluetooth Static Driver source file for UART functions.

  Description:
    This file is the implementation of the internal functions of the BM71
    driver related to sending and receiving data to/from the BM71 over UART.

*******************************************************************************/
// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "definitions.h"
#include "custom_bm71.h"
#include "custom_bm71_local.h"
#include "custom_bm71_command_send.h"
#include "custom_bm71_uart.h"

// all #defines, enums and non-static functions and variables prefixed by
// CUSTOM_BM71 to avoid name conflicts

static CUSTOM_BM71_UART_DATA uartData;
volatile uint8_t CUSTOM_BM71_eusartRxCount;
volatile uint8_t CUSTOM_BM71_txByteQueued;

// called from CUSTOM_BM71_Initialize, not the directly by the user
void CUSTOM_BM71_UART_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    uartData.state = CUSTOM_BM71_UART_STATE_INIT;

    uartData.rxHead = 0;

    uartData.rxTail = 0;

    CUSTOM_BM71_txByteQueued = 0;

    CUSTOM_BM71_eusartRxCount=0;
}


/******************************************************************************
  Function:
    void CUSTOM_BM71_EUSART_Write(uint8_t txData)

  Return:
    true - if actual number of bytes transmitted is same as the argument size.
    false - in case of an error

  Remarks:

 */


void CUSTOM_BM71_EUSART_Write(uint8_t txData)
{
    SERCOM1_USART_Write(&txData,1);
}

uint8_t CUSTOM_BM71_EUSART_Read(void)
{
    uint8_t readByte;

    readByte=uartData.rxBuffer[uartData.rxTail++];

    if(uartData.rxTail >= RX_BUFFER_SIZE)
    {
        uartData.rxTail = 0;
    }

    CUSTOM_BM71_eusartRxCount--;

    return readByte;

}

void CUSTOM_BM71_UART_TransmitEventHandler(uintptr_t context)
{
    CUSTOM_BM71_txByteQueued += 2;
}

void CUSTOM_BM71_UART_ReceiveEventHandler(uintptr_t context)
{
    uartData.rxBuffer[uartData.rxHead++] = uartData.rxData;
   SERCOM1_USART_Read((void*)&uartData.rxData, 1);    // set up first read

    if(uartData.rxHead >= RX_BUFFER_SIZE)
    {
        uartData.rxHead = 0;
    }

    CUSTOM_BM71_eusartRxCount++;
}
/******************************************************************************
  Function:
    void CUSTOM_BM71_UART_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

 void CUSTOM_BM71_UART_Tasks ( void )
{
    /* Check the application's current state. */
    switch ( uartData.state )
    {
        /* Application's initial state. */
        case CUSTOM_BM71_UART_STATE_INIT:

            // Register an event handler with driver. This is done once
           SERCOM1_USART_WriteCallbackRegister(CUSTOM_BM71_UART_TransmitEventHandler, 0);
           SERCOM1_USART_ReadCallbackRegister(CUSTOM_BM71_UART_ReceiveEventHandler, 0);

           SERCOM1_USART_Read((void*)&uartData.rxData, 1);    // set up first read

            uartData.state = CUSTOM_BM71_UART_STATE_TRANSMIT;

            break;

        case CUSTOM_BM71_UART_STATE_TRANSMIT:
            if (((CUSTOM_BM71_txByteQueued&1)==1) && (!SERCOM1_USART_WriteIsBusy()))
            {
                CUSTOM_BM71_UART_TransferNextByte();
                CUSTOM_BM71_txByteQueued--;
            }

            break;


        /* The default state should never be executed. */
        default:
            /* TODO: Handle error in application's state machine. */
            break;
    }
}

/*******************************************************************************
 End of File
 */
