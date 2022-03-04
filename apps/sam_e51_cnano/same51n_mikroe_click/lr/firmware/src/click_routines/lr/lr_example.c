/*******************************************************************************
  LR click routine example source file

  Company
    Microchip Technology Inc.

  File Name
    lr_example.c

  Summary
    LR click routine example implementation File.

  Description
    This file defines the usage of the LR click routine APIs.

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
#include <string.h>
#include "lr.h"
#include "../click_interface.h"
/**
  Section: Example Code
 */

void lr_example(void)                      
{
    uint8_t lr_rx_buff[512] = {0};

    lr_click_initialize();      
    lr_get_response((uint8_t*)lr_rx_buff);            
    printf("LR firmware release version = %s\r\n",lr_rx_buff);
    CLICK_LR_DelayMs(1000); 
     
    lr_send_command("radio get mod\r\n");                       
    CLICK_LR_DelayMs(1000);                      
    lr_get_response((uint8_t*)lr_rx_buff);            
    printf("Radio Mode = %s\r\n",lr_rx_buff);
               
    lr_send_command("radio get freq\r\n");                        
    CLICK_LR_DelayMs(1000);                      
    lr_get_response((uint8_t*)lr_rx_buff);            
    printf("Radio Frequency in Hz = %s \r\n",lr_rx_buff);
}
