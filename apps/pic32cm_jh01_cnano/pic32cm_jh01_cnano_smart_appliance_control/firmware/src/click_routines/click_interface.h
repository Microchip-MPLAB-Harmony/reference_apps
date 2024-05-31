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
#include <rnbd/rnbd.h>
#include "rnbd/rnbd_interface.h"

/**	Click routine interfaces/resources Macro Declarations
 *
 * 	1. I2C
 *  The weather click example on PIC32CM MC Curiosity Nano uses
 *  mikroBUS socket #3 on the Curiosity Nano Base for Click boards
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
 *  mikroBUS socket #2 to mount Fan click board.
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
 *  The eink_epaper_2_9_296_128 click on PIC32CM MC Curiosity Nano uses
 *  mikroBUS socket #1 to mount EINK click board.
 *  The SPI lines from MCU coming to this socket are from
 *  SERCOM1 peripheral. The SPI is configured to use manual chip select.
 *
 *
 * 2. Timer
 *  The eink_epaper_2_9_296_128 click on PIC32CM MC Curiosity Nano uses
 *  Systick timer module on the MCU to implement the time
 *  requirement weather click routines.
 *
 * 3. PORTs
 *  The eink click uses the following ports pins.
 *  EPAPER_2_9_296_128_DC
 *  EPAPER_2_9_296_128_RST
 *  EPAPER_2_9_296_128_CS
 *  EPAPER_2_9_296_128_BSY
 *  The pins are configured using the MCC Pin configurator.
 */

// I2C Definitions
#define EPAPER_2_9_296_128_SPI_Write 			SERCOM2_SPI_Write
#define EPAPER_2_9_296_128_SPI_Read  			SERCOM2_SPI_Read
#define EPAPER_2_9_296_128_SPI_WriteRead		SERCOM2_SPI_WriteRead

// Timer Definitions
#define EPAPER_2_9_296_128_TimerStart 			SYSTICK_TimerStart
#define EPAPER_2_9_296_128_DelayMs				SYSTICK_DelayMs


//RNBD451 API
#define CLICK_RNBD451_Init                             RNBD_Init
#define CLICK_RNBD451_SetAsyncMessageHandler           RNBD_SetAsyncMessageHandler
#define CLICK_RNBD451_IsStreamopen                     RNBD_IsStreamopen
#define CLICK_RNBD451_IsOTABegin                       RNBD_IsOTABegin
#define CLICK_RNBD451_DataReady                        RNBD_DataReady
#define CLICK_RNBD451_Read                             RNBD_Read
#define CLICK_RNBD451_IsConnected                      RNBD_IsConnected                 
#define CLICK_RNBD451_EnterCmdMode                     RNBD_EnterCmdMode
#define CLICK_RNBD451_RebootCmd                        RNBD_RebootCmd
#define CLICK_RNBD451_FactoryReset                     RNBD_FactoryReset


#endif // _CLICK_INTERFACES_H
