/*******************************************************************************
  Click interface header file

  Company:
    Microchip Technology Inc.

  File Name:
    click_interface.h

  Summary:

  Description:
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

#ifndef _CLICK_INTERFACES_H
#define _CLICK_INTERFACES_H

/**
  Section: Included Files
 */

#include <xc.h>
#include <stdint.h>

/**	Click routine interfaces/resources Macro Declarations
 *
 * 	1. SPI
 *  The eink bundle click example on SAM E51 Curiosity Nano uses
 *  mikroBUS socket #1 to mount EINK bundle click board.
 *  The SPI lines from MCU coming to this socket are from
 *  SERCOM1 peripheral. The SPI is configured to use manual chip select.
 *
 *
 * 2. Timer
 *  The eink bundle click  example on SAM E51 Curiosity Nano uses
 *  Systick timer module on the MCU to implement the time
 *  requirement weather click routines.
 *
 * 3. PORTs
 *  The eink bundle click uses the following ports pins.
 *  CLICK_EINK_BUNDLE_DC
 *  CLICK_EINK_BUNDLE_RST
 *  CLICK_EINK_BUNDLE_CS
 *  CLICK_EINK_BUNDLE_BSY
 *  The pins are configured using the MHC Pin configurator.
 */

// I2C Definitions
#define CLICK_EINK_BUNDLE_SPI_Write 			SERCOM1_SPI_Write
#define CLICK_EINK_BUNDLE_SPI_Read  			SERCOM1_SPI_Read
#define CLICK_EINK_BUNDLE_SPI_WriteRead			SERCOM1_SPI_WriteRead

// Timer Definitions
#define CLICK_EINK_BUNDLE_TimerStart 			SYSTICK_TimerStart
#define CLICK_EINK_BUNDLE_DelayMs				SYSTICK_DelayMs

/**	Click routine interfaces/resources Macro Declarations
 *
 * 	1. USART
 *  The heartrate9 click example on SAM E51 Curiosity Nano uses
 *  mikroBUS socket #1 on the Curiosity Nano Base for Click boards
 *  to mount heartrate9 click board. The USART lines from MCU coming to
 *  this socket are from SERCOM0 peripheral on the MCU.
 *
 * 2. Timer
 *  The heartrate9 click example on SAM E51 Curiosity Nano uses
 *  Systick timer module on the MCU to implement the time
 *  requirement of heartrate9 click routines.
 *
 */

// SERCOM USART Definitions
#define CLICK_HEARTRATE9_USART_Read                          SERCOM0_USART_Read
#define CLICK_HEARTRATE9_USART_ReadThresholdSet              SERCOM0_USART_ReadThresholdSet
#define CLICK_HEARTRATE9_USART_ReadNotificationEnable        SERCOM0_USART_ReadNotificationEnable
#define CLICK_HEARTRATE9_USART_ReadCallbackRegister          SERCOM0_USART_ReadCallbackRegister
#define CLICK_HEARTRATE9_USART_ReadCountGet                  SERCOM0_USART_ReadCountGet
#define CLICK_HEARTRATE9_USART_EVENT_READ_THRESHOLD_REACHED  SERCOM_USART_EVENT_READ_THRESHOLD_REACHED
#define CLICK_HEARTRATE9_USART_READ_BUFFER_SIZE              128                 //Define value same as SERCOM0_USART_READ_BUFFER_SIZE defined in the respective USART PLIB '.c' file

// Timer Definitions
#define CLICK_HEARTRATE9_TimerStart                         SYSTICK_TimerStart
#define CLICK_HEARTRATE9_DelayMs                            SYSTICK_DelayMs

#endif // _CLICK_INTERFACES_H
