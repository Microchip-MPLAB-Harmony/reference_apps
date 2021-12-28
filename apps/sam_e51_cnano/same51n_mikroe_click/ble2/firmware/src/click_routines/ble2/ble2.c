/*******************************************************************************
  BLE 2 click routine source file

  Company
    Microchip Technology Inc.

  File Name
    ble2.c

  Summary
    BLE 2 click routine Implementation File.

  Description
    This file defines the interface to the BLE 2 click using USART PLIB.

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
#include "ble2.h"
#include "definitions.h"                // SYS function prototypes
#include "../click_interface.h"

uint8_t rxBuffer[512];
volatile uint32_t nBytesRead = 0;
/**
  Section: Macro Declarations
 */
void BLE2_EnterCommand_Mode(void)
{
    CLICK_BLE2_CMD_MLDP_Set();/* set BLE2_Cmd_Mldp output high */
    CLICK_BLE2_DelayMs(20);
    CLICK_BLE2_CMD_MLDP_Clear(); /* set BLE2_Cmd_Mldp output low */
    CLICK_BLE2_DelayMs(20);
}
void BLE2_ExitCommand_Mode(void)
{
    CLICK_BLE2_CMD_MLDP_Set(); /* set BLE2_Cmd_Mldp output high */
}
void BLE2_EnterMicrochipLowEnergyDataProfile_Mode(void)
{
     CLICK_BLE2_CMD_MLDP_Clear(); /* set BLE2_Cmd_Mldp output low */
}

void BLE2_DeepSleepModule(void)
{
    CLICK_BLE2_WAKE_Clear();/* set BLE2_Wake output low */
}
static void BLE2_WakeModule(void)
{
    CLICK_BLE2_WAKE_Set(); /* set BLE2_Wake output high */
}

bool BLE2_isConnected(void)
{
    return CLICK_BLE2_CONN_Get(); /* get BLE2_Conn value */;
}

void BLE2_SendString(const char* command)
{
    CLICK_BLE2_USART_Write((uint8_t *)command, strlen(command));
}

static void BLE2_UsartReadEventHandler(SERCOM_USART_EVENT event, uintptr_t context )
{
    uint32_t nBytesAvailable = 0;
    
    if (event == CLICK_BLE2_USART_EVENT_READ_THRESHOLD_REACHED)
    {
        /* Receiver should atleast have the thershold number of bytes in the ring buffer */
        nBytesAvailable = CLICK_BLE2_USART_ReadCountGet();

       nBytesRead += CLICK_BLE2_USART_Read((uint8_t*)&rxBuffer[nBytesRead],nBytesAvailable); 
    }
}

void BLE2_GetReceiveBuffer(uint8_t* pRxBuffer)
{
    int i = 0;
    for(i=0;i<512;i++)
        pRxBuffer[i] = rxBuffer[i];
}

void BLE2_ResetReceiveBuffer()
{
    nBytesRead = 0; 
    memset(rxBuffer,0,512);
}

void BLE2_Initialize () {
    
    CLICK_BLE2_TimerStart();
    
    /* Register a callback for read events */
    CLICK_BLE2_USART_ReadCallbackRegister(BLE2_UsartReadEventHandler, (uintptr_t) NULL); 
     
    CLICK_BLE2_USART_ReadThresholdSet(1);
    
    CLICK_BLE2_USART_ReadNotificationEnable(true, true);
    
    CLICK_BLE2_DelayMs(1000);
    
    // wake the BLE click from sleep
    BLE2_WakeModule();                              // Wake Module using GPIO
    
    CLICK_BLE2_DelayMs(500);
    
    while(CLICK_BLE2_USART_ReadCountGet() != 0);

}

