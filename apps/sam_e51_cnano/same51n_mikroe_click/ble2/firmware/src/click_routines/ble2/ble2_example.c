/*******************************************************************************
  BLE 2 click routine example source file

  Company
    Microchip Technology Inc.

  File Name
    ble2_example.c

  Summary
    BLE 2 click routine example implementation File.

  Description
    This file defines the usage of the BLE 2 click routine APIs.

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
#include <string.h>
#include "definitions.h"                // SYS function prototypes
#include "click_routines/click_interface.h"
#include "ble2.h"

volatile bool connection_status = false;
volatile bool connection_data = false;
 
const char resp_conn_notification[]="WC";
const char cmd_factoryreset[] = "SF,1\r\n";
const char cmd_userdefineprofile[] = "SS,F0000000\r\n";
const char cmd_peripheral[] = "SR,22000000\r\n";
const char cmd_name[]="SN,BLE2Click\r\n";
const char cmd_reboot[] = "R,1\r\n";
const char resp_AOK[]="AOK\r\n";
const char resp_reboot[] = "Reboot";
char batt[15] ;
/**
  Section: Example Code
 */

static void ble2_example_setup() {
    
    uint8_t rx_buf[512];
     
    BLE2_ResetReceiveBuffer();
    // issue a factory reset
    BLE2_SendString(cmd_factoryreset);
    
    CLICK_BLE2_DelayMs(50);
    
    BLE2_GetReceiveBuffer((uint8_t*)rx_buf);
    while(!(strcmp((char*)rx_buf,resp_AOK)?0:1));
    
    BLE2_ResetReceiveBuffer();
    
    BLE2_SendString(cmd_name);
    
    CLICK_BLE2_DelayMs(50);
    
    BLE2_GetReceiveBuffer((uint8_t*)rx_buf);
    while(!(strcmp((char*)rx_buf,resp_AOK)?0:1));
        
    BLE2_ResetReceiveBuffer();
    
    BLE2_SendString(cmd_userdefineprofile);
    
    CLICK_BLE2_DelayMs(50);
    
    BLE2_GetReceiveBuffer((uint8_t*)rx_buf);
    while(!(strcmp((char*)rx_buf,resp_AOK)?0:1));
    
    BLE2_ResetReceiveBuffer();
    // enable auto rescan when the BLE is disconnected
    BLE2_SendString(cmd_peripheral);
    
    CLICK_BLE2_DelayMs(50);
    
    BLE2_GetReceiveBuffer((uint8_t*)rx_buf);
    while(!(strcmp((char*)rx_buf,resp_AOK)?0:1)); 
    
    BLE2_ResetReceiveBuffer();                          
    // reboot BLE to make the configurations take effect
    BLE2_SendString(cmd_reboot);
    
    CLICK_BLE2_DelayMs(100);
    
    BLE2_GetReceiveBuffer((uint8_t*)rx_buf);
    while(!(strncmp((char*)rx_buf,resp_reboot,5)?0:1)); // Wait for "Reboot" Response
    
    CLICK_BLE2_DelayMs(2000);
    
   BLE2_ResetReceiveBuffer();

}

static void ble2_example_rx_parser(void)
{
    int i =0,j=0;
    uint8_t rx_buf[512];
    
    if(connection_data == false){
       
        while(CLICK_BLE2_USART_ReadCountGet() != 0);
        
        BLE2_GetReceiveBuffer((uint8_t*)rx_buf);
        
        for(i= 0; i < 512; i++)
        {
            j = i + 1;
            if(rx_buf[i] == 'W' && rx_buf[j] == 'C'){
                connection_data = true;
                 BLE2_ResetReceiveBuffer();
                break;
            }
        }
    }  
}


void ble2_example(void) {
    
    int i = 0;
    
    BLE2_Initialize();
    
    ble2_example_setup();
  
    while(1){

        if(BLE2_isConnected()) 
        {     
            ble2_example_rx_parser();
            
            if(connection_data)
            { 
                sprintf(batt,"SUW,2A19,%d\r\n",i++);
                if(i > 64){
                    i = 0;
                }        
                BLE2_SendString(batt); 
                CLICK_BLE2_DelayMs(200);

                BLE2_ResetReceiveBuffer();
            }
        }else{
            connection_data = false;
        }
    }
}
