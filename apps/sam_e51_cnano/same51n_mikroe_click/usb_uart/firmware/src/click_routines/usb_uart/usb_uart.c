/*******************************************************************************
  USB UART click routine source file

  Company
    Microchip Technology Inc.

  File Name
    usb_uart.c

  Summary
    USB UART click routine implementation file.

  Description
    This file defines the interface to the USB UART click using UART PLIB.
    This click routine provides to read and write on USB UART click.

  Remarks:
    None.
 
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*
    (c) 2021 Microchip Technology Inc. and its subsidiaries. You may use this
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

/**
  Section: Included Files
 */

#include <string.h>
#include "definitions.h"                // SYS function prototypes
#include "../click_interface.h"
#include "usb_uart.h"

bool usb_uart_USART_Read(uint8_t* pRdBuffer, const size_t size)
{
    return CLICK_USB_UART_USART_Read(pRdBuffer,size);
}

bool usb_uart_USART_Write(uint8_t* pWrBuffer, const size_t size)
{
    return CLICK_USB_UART_USART_Write(pWrBuffer, size);
}

bool usb_uart_USART_ReadIsBusy(void)
{
    return CLICK_USB_UART_USART_ReadIsBusy();
}

bool usb_uart_USART_WriteIsBusy(void)
{
    return CLICK_USB_UART_USART_WriteIsBusy();
}




