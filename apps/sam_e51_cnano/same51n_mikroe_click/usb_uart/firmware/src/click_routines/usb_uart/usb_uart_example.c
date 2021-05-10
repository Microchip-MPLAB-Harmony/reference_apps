/*******************************************************************************
  USB UART click routine example source file

  Company
    Microchip Technology Inc.

  File Name
    usb_uart_example.c

  Summary
    USB UART click routine example implementation file.

  Description
    This file defines the usage of the USB UART click routine APIs.

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

#include <stdio.h>
#include <stdint.h>
#include "definitions.h"                // SYS function prototypes
#include "usb_uart.h"

/**
  Section: Example Code
 */

    
uint8_t message_string[] = "Enter a character: ";
char out_string[50];

void usb_uart_example(void) {   
    
    uint8_t read_char[1];
    
    printf("Check on the USB UART Terminal for Data transfer and receipt\r\n");
        
    while(1)
    {
        usb_uart_USART_Write(message_string,sizeof(message_string));
        while(usb_uart_USART_USART_WriteIsBusy());
        
        usb_uart_USART_Read(&read_char[0],1);
        while(usb_uart_USART_USART_ReadIsBusy());
        
        sprintf(out_string,"\r\nYou entered character '%c'\r\n", read_char[0]);
        usb_uart_USART_Write((uint8_t *)out_string,sizeof(out_string));
        while(usb_uart_USART_USART_WriteIsBusy());
    }
}
