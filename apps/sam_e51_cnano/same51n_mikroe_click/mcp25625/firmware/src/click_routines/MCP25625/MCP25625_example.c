/*******************************************************************************
  MCP25625 click routine example source file

  Company
    Microchip Technology Inc.

  File Name
    MCP25625_example.c

  Summary
    MCP25625 click routine example implementation file.

  Description
    This file defines the usage of the MCP25625 click routine APIs.

  Remarks:
    None.

 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*
    (c) 2022 Microchip Technology Inc. and its subsidiaries. You may use this
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
#include "MCP25625.h"
#include "MCP25625_example.h"

char        cmd = 'a';

void display_menu (void)
{
    printf("\n\r\n\rSelect the application");
    printf("\n\ra) To initiate the CAN Message Transmit and wait for the response");
    printf("\n\rb) To wait for the CAN Message Receive and Transmit the response");
    
    printf("\n\rEnter your choice\r\n");
    
    SERCOM5_USART_Read(&cmd, 1);
}

void MCP25625_example(void)
{
    uCAN_MSG    txMessage;
    uCAN_MSG    rxMessage;

    /* Display example title */
    printf ("\n\n\r-----------------------------------------------------------");
    printf ("\n\r         MCP25625 Click Application on SAM E51 CNano         ");
    printf ("\n\r-----------------------------------------------------------");

    SYSTICK_TimerStart();
    MCP25625_Initialize();

    txMessage.frame.data0 = 0;

    for( ; ; )
    {
        display_menu();
        
        if(cmd == 'a')
        {
            printf("\n\rTransmit Message: ");
            txMessage.frame.id = 0x444;
            printf("%03ld ", txMessage.frame.id);
            txMessage.frame.dlc = 8;
            printf("%02X ", txMessage.frame.dlc);
            txMessage.frame.data0 = 0x01;
            printf("%02X ", txMessage.frame.data0);
            txMessage.frame.data1 = 'A';
            printf("%02X ", txMessage.frame.data1);
            txMessage.frame.data2 = 'B';
            printf("%02X ", txMessage.frame.data2);
            txMessage.frame.data3 = 'C';
            printf("%02X ", txMessage.frame.data3);
            txMessage.frame.data4 = 'D';
            printf("%02X ", txMessage.frame.data4);
            txMessage.frame.data5 = 'E';
            printf("%02X ", txMessage.frame.data5);
            txMessage.frame.data6 = 'F';
            printf("%02X ", txMessage.frame.data6);
            txMessage.frame.data7 = 0xFF;
            printf("%02X \n\r", txMessage.frame.data7);
            MCP25625_CANTransmit(&txMessage);
            break;
        }
        else if(cmd == 'b')
        {
            break;
        }
        else
        {
            printf("\n\rInvalid choice");
        }
    }

    while(1)
    {
        if(MCP25625_CANReceive(&rxMessage))
        {
            if(cmd == 'a')
            {
                printf("\n\rTransmit Message: ");
            }
            else
            {
                printf("\n\rReceive Message: ");
            }

            txMessage.frame.idType = rxMessage.frame.idType;
            txMessage.frame.id = rxMessage.frame.id;
            printf("%03ld ", rxMessage.frame.id);
            txMessage.frame.dlc = rxMessage.frame.dlc;
            printf("%02X ", rxMessage.frame.dlc);
            txMessage.frame.data0++;
            if(cmd == 'a')
            {
                printf("%02X ", txMessage.frame.data0);
            }
            else
            {
                printf("%02X ", rxMessage.frame.data0);
            }
            txMessage.frame.data1 = rxMessage.frame.data1;
            printf("%02X ", rxMessage.frame.data1);
            txMessage.frame.data2 = rxMessage.frame.data2;
            printf("%02X ", rxMessage.frame.data2);
            txMessage.frame.data3 = rxMessage.frame.data3;
            printf("%02X ", rxMessage.frame.data3);
            txMessage.frame.data4 = rxMessage.frame.data4;
            printf("%02X ", rxMessage.frame.data4);
            txMessage.frame.data5 = rxMessage.frame.data5;
            printf("%02X ", rxMessage.frame.data5);
            txMessage.frame.data6 = rxMessage.frame.data6;
            printf("%02X ", rxMessage.frame.data6);
            txMessage.frame.data7 = rxMessage.frame.data7;
            printf("%02X ", rxMessage.frame.data7);
            MCP25625_CANTransmit(&txMessage);
            
            SYSTICK_DelayMs(5000);
        }
    }  
}
