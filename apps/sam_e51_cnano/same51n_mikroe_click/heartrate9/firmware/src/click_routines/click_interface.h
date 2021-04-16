/*******************************************************************************
  Heart Rate 9 click routine interface header file

  Company
    Microchip Technology Inc.

  File Name
    click_interface.h

  Summary
    Heart Rate 9 click routine interface implementation File.

  Description
    This file defines the interface to the Heart Rate 9 click routines and MHC PLIB APIs.

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

#ifndef _CLICK_INTERFACES_H
#define _CLICK_INTERFACES_H

/**
  Section: Included Files
 */

#include <xc.h>
#include <stdint.h>

/**	Click routine interfaces/resources Macro Declarations
 *
 * 	1. UART
 *  The heartrate9 click example on SAM E51 Curiosity Nano uses
 *  mikroBUS socket #1 on the Curiosity Nano Base for Click boards
 *  to mount heartrate9 click board. The USART lines from MCU coming to
 *  this socket are from SERCOM4 peripheral on the MCU.
 *
 * 2. Timer
 *  The heartrate9 click example on SAM E51 Curiosity Nano uses
 *  Systick timer module on the MCU to implement the time
 *  requirement of heartrate9 click routines.
 *
 */

// SERCOM USART Definitions
#define CLICK_HEARTRATE9_UART_Read                          SERCOM4_USART_Read
#define CLICK_HEARTRATE9_UART_ReadThresholdSet              SERCOM4_USART_ReadThresholdSet
#define CLICK_HEARTRATE9_UART_ReadNotificationEnable        SERCOM4_USART_ReadNotificationEnable
#define CLICK_HEARTRATE9_UART_ReadCallbackRegister          SERCOM4_USART_ReadCallbackRegister
#define CLICK_HEARTRATE9_UART_ReadCountGet                  SERCOM4_USART_ReadCountGet
#define CLICK_HEARTRATE9_UART_EVENT_READ_THRESHOLD_REACHED  SERCOM_USART_EVENT_READ_THRESHOLD_REACHED
#define CLICK_HEARTRATE9_UART_READ_BUFFER_SIZE              128                 //Define value same as SERCOM4_USART_READ_BUFFER_SIZE defined in the respective USART PLIB '.c' file

// Timer Definitions
#define CLICK_HEARTRATE9_TimerStart                         SYSTICK_TimerStart
#define CLICK_HEARTRATE9_DelayMs                            SYSTICK_DelayMs

#endif // _CLICK_INTERFACES_H
