/*******************************************************************************
  LR click routine source file

  Company
    Microchip Technology Inc.

  File Name
    lr.c

  Summary
    LR click routine Implementation File.

  Description
    This file defines the interface to the LR click using USART PLIB.
    This click routine provides to read the sensor data on LR click.

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
#include "lr.h"

static uint8_t rxBuffer[512];
static volatile uint32_t nBytesRead = 0;

static void lr_read_callback(SERCOM_USART_EVENT event, uintptr_t context)
{
    uint32_t nBytesAvailable = 0;
    
    if (event == CLICK_LR_USART_EVENT_READ_THRESHOLD_REACHED)
    {
        /* Receiver should atleast have the thershold number of bytes in the ring buffer */
        nBytesAvailable = CLICK_LR_USART_ReadCountGet();
        
        nBytesRead += CLICK_LR_USART_Read((uint8_t*)&rxBuffer[nBytesRead], nBytesAvailable);
        
    }
}


void lr_click_initialize(void)
{
    /* Register callback functions and send start message */
    CLICK_LR_USART_ReadCallbackRegister(lr_read_callback, 0);
    CLICK_LR_USART_ReadThresholdSet(1);
    CLICK_LR_USART_ReadNotificationEnable(true, true);
    CLICK_LR_TimerStart();
    nBytesRead = 0; 
    memset(rxBuffer,0,512);
    CLICK_LR_RST_Clear();                   // Toggle Module HW Reset   
    CLICK_LR_DelayMs(30);
    CLICK_LR_RST_Set(); 
    CLICK_LR_DelayMs(1000);                      // Wait for Module Information Response     
}

void lr_send_command(const char* command)
{
    nBytesRead = 0; 
    memset(rxBuffer,0,512);
    CLICK_LR_USART_WRITE((uint8_t *)command, strlen(command));
}

void lr_get_response(uint8_t* pRxBuffer)
{
    int i = 0;
    for(i=0;i<512;i++)
        pRxBuffer[i] = rxBuffer[i];
}
