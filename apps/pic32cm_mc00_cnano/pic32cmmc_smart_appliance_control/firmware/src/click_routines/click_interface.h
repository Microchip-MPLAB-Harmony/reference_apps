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
//DOM-IGNORE-END
        
#ifndef _CLICK_INTERFACES_H
#define _CLICK_INTERFACES_H

/**
  Section: Included Files
 */

#include <xc.h>
#include <stdint.h>

/**	Click routine interfaces/resources Macro Declarations
 *
 * 	1. I2C
 *  The weather click example on PIC32CM MC Curiosity Nano uses
 *  mikroBUS socket #1 on the Curiosity Nano Base for Click boards
 *  to mount weather click board. The I2C lines from MCU coming to
 *  this socket are from SERCOM0 peripheral on the MCU.
 *
 * 2. Timer
 *  The weather click example on PIC32CM MC Curiosity Nano uses
 *  Systick timer module on the MCU to implement the time
 *  requirement of weather click routines.
 *
 */

// I2C Definitions
#define CLICK_WEATHER_I2C_Write 			SERCOM0_I2C_Write
#define CLICK_WEATHER_I2C_IsBusy 			SERCOM0_I2C_IsBusy
#define CLICK_WEATHER_I2C_WriteRead			SERCOM0_I2C_WriteRead

// Timer Definitions
#define CLICK_WEATHER_TimerStart 			SYSTICK_TimerStart
#define CLICK_WEATHER_DelayMs				SYSTICK_DelayMs

/**	Click routine interfaces/resources Macro Declarations
 *
 * 	1. I2C
 *  The Fan click example on PIC32CM MC Curiosity Nano uses
 *  mikroBUS socket #1 to mount Fan click board.
 *  The I2C lines from MCU coming to this socket are from
 *  SERCOM0 peripheral.
 *
 */

// I2C Definitions
#define CLICK_FAN_I2C_Write 			SERCOM0_I2C_Write
#define CLICK_FAN_I2C_IsBusy 			SERCOM0_I2C_IsBusy
#define CLICK_FAN_I2C_WriteRead			SERCOM0_I2C_WriteRead

// Timer Definitions
#define CLICK_FAN_TimerStart 			SYSTICK_TimerStart
#define CLICK_FAN_DelayMs				SYSTICK_DelayMs


/**	Click routine interfaces/resources Macro Declarations
 *
 * 	1. SPI
 *  The eink bundle click example on PIC32CM MC Curiosity Nano uses
 *  mikroBUS socket #1 to mount EINK bundle click board.
 *  The SPI lines from MCU coming to this socket are from
 *  SERCOM1 peripheral. The SPI is configured to use manual chip select.
 *
 *
 * 2. Timer
 *  The eink bundle click  example on PIC32CM MC Curiosity Nano uses
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

#endif // _CLICK_INTERFACES_H
