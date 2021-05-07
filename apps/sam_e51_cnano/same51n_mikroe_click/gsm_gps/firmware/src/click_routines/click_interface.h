/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
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

#ifndef _CLICK_INTERFACES_H
#define _CLICK_INTERFACES_H

/**
  Section: Included Files
 */
#include <stdint.h>
#include <stdlib.h>

/**	Click routine interfaces/resources Macro Declarations
 *
 * 	1. UART
 *  The GSM GPS click example on SAM E51 Curiosity Nano uses
 *  mikroBUS socket #1 to mount GSM GPS click board.
 *  The UART lines from MCU coming to this socket are from
 *  SERCOM4 peripheral.
 *
 * 2. Timer
 *  The GSM GPS click example on SAM E51 Curiosity Nano uses
 *  Systick timer module on the MCU to implement the time
 *  requirement GSM GPS click routines.
 *
 *
 * 3. PORTs
 *  The GSM GPS click uses the following ports pins.
 *  CLICK_GSM_GPS_POWER
 *  The pins are configured using the MHC Pin configurator.
 */


// UART Definitions
#define CLICK_GSM_GPS_USART_Write 			        SERCOM4_USART_Write
#define CLICK_GSM_GPS_USART_Read 			        SERCOM4_USART_Read
#define CLICK_GSM_GPS_USART_ReadIsBusy		        SERCOM4_USART_ReadIsBusy
#define CLICK_GSM_GPS_USART_WriteCallbackRegister 	SERCOM4_USART_WriteCallbackRegister
#define CLICK_GSM_GPS_USART_ReadCallbackRegister    SERCOM4_USART_ReadCallbackRegister


// Timer Definitions
#define CLICK_GSM_GPS_TimerStart                    SYSTICK_TimerStart
#define CLICK_GSM_GPS_DelayMs                       SYSTICK_DelayMs
#define CLICK_GSM_GPS_TimerCallbackSet              SYSTICK_TimerCallbackSet


#endif // _CLICK_INTERFACES_H
