/*******************************************************************************
  BM71 Bluetooth Static Driver implementation

  Company:
    Microchip Technology Inc.

  File Name:
    drv_bm71_uart.h

  Summary:
   BM71 Bluetooth Static Driver header file for UART functions.

  Description:
    This file is the header file for the internal functions of the BM71
    driver related to sending and receiving data to/from the BM71 over UART.
 
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*****************************************************************************
 Copyright (C) 2017-2018 Microchip Technology Inc. and its subsidiaries.

Subject to your compliance with these terms, you may use Microchip software 
and any derivatives exclusively with Microchip products. It is your 
responsibility to comply with third party license terms applicable to your 
use of third party software (including open source software) that may 
accompany Microchip software.

THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A PARTICULAR 
PURPOSE.

IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE 
FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN 
ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY, 
THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*****************************************************************************/
//DOM-IGNORE-END

#ifndef DRV_BM71_UART_H
#define DRV_BM71_UART_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

//#include <stdint.h>
//#include <stdbool.h>
//#include <stddef.h>
//#include <stdlib.h>
#include "configuration.h"
#include "definitions.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END 

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************
#define TX_BUFFER_SIZE      50
#define RX_BUFFER_SIZE      50
    
#define UPDATE_BUFFER_INDEX(index, limit)  index = ((index+1) >= limit)? 0 : (index+1)
#define UART_TX_STRING      "This is a UART Test String !"
// *****************************************************************************
/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/
typedef enum
{
	/* Application's state machine's initial state. */
	DRV_BM71_UART_STATE_INIT=0,
    DRV_BM71_UART_STATE_TRANSMIT,
    DRV_BM71_UART_STATE_RECEIVE,
    DRV_BM71_UART_STATE_ERROR,	

	/* TODO: Define states used by the application state machine. */

} DRV_BM71_UART_STATES;



typedef struct
{
    /* The application's current state */
    DRV_BM71_UART_STATES state;
    
    DRV_HANDLE drvUSARTHandle;
      
    uint8_t rxBuffer[RX_BUFFER_SIZE];
    
    uint8_t rxHead;
    
    uint8_t rxTail;

    volatile uint8_t rxData;
    
    /* TODO: Define any additional data used by the application. */

} DRV_BM71_UART_DATA;

void DRV_BM71_UART_Initialize ( void );
void DRV_BM71_UART_Tasks( void );
void DRV_BM71_UART_ReceiveEventHandler(uintptr_t context);
void DRV_BM71_UART_TransmitEventHandler(uintptr_t context);
void DRV_BM71_EUSART_Write(uint8_t txData);
uint8_t DRV_BM71_EUSART_Read(void);

extern volatile uint8_t DRV_BM71_eusartRxCount;

#endif /* _APP_H */

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

