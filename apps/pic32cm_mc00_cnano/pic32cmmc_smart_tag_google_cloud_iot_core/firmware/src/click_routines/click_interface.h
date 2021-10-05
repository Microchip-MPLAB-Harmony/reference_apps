/*******************************************************************************
  Common click routine interface header file

  Company
    Microchip Technology Inc.

  File Name
    click_interface.h

  Summary
    Common click routine interface implementation File.

  Description
    This file defines the interface to the common click routines and MHC PLIB APIs.

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

#ifndef _CLICK_INTERFACE_H
#define _CLICK_INTERFACE_H

/**
  Section: Included Files
 */

#include <xc.h>
#include <stdint.h>

/**	Click routine interfaces/resources Macro Declarations
 *
 * 	1. I2C
 *  The IR Thermo2 click uses mikroBUS socket #2 on the Curiosity Nano 
 *  Base for Click boards to mount IR Thermo2 click board to interface 
 *  with PIC32CM MC00 Curiosity Nano. The I2C lines from MCU coming to this 
 *  socket are from SERCOM0 peripheral on the MCU.
 *
 *  The led driver 3 click uses XPlained Pro Extension on PIC32CM MC00 Curiosity
 *  Nano Base to mount led driver 3 click board using mikroBus Xplained Pro 
 *  Adapter. The I2C lines from MCU coming to this Xplained Pro are from  
 *  SERCOM0 peripheral on the MCU.
 *
 * 	2. SPI
 *  The RFID click uses mikroBUS socket #3 on the Curiosity Nano 
 *  Base for Click boards to mount led driver 3 click board to interface 
 *  with PIC32CM MC00 Curiosity Nano. The I2C lines from MCU coming to this 
 *  socket are from SERCOM3 peripheral on the MCU.
 *
 *  3. Timer
 *  The click board interfaced with PIC32CM MC00 Curiosity Nano uses Systick 
 *  timer module on the MCU to implement the time requirement RFID click routines.
 *
 */

// I2C Definitions
#define CLICK_LEDDRIVER3_I2C_Write 			    SERCOM0_I2C_Write
#define CLICK_LEDDRIVER3_I2C_IsBusy 			SERCOM0_I2C_IsBusy

#define CLICK_IR_THERMO2_I2C_Write              SERCOM0_I2C_Write
#define CLICK_IR_THERMO2_I2C_IsBusy             SERCOM0_I2C_IsBusy
#define CLICK_IR_THERMO2_I2C_WriteRead          SERCOM0_I2C_WriteRead
#define CLICK_IR_THERMO2_I2C_ErrorGet           SERCOM0_I2C_ErrorGet

// SPI Definitions
#define CLICK_RFID_SPI_Write                    SERCOM3_SPI_Write
#define CLICK_RFID_SPI_Read  			        SERCOM3_SPI_Read
#define CLICK_RFID_SPI_RegisterCallback			SERCOM3_SPI_CallbackRegister

// Timer Definitions
#define CLICK_RFID_TimerStart 			        SYSTICK_TimerStart
#define CLICK_RFID_DelayMs				        SYSTICK_DelayMs

#define CLICK_LEDDRIVER3_TimerStart 			SYSTICK_TimerStart
#define CLICK_LEDDRIVER3_DelayMs				SYSTICK_DelayMs

#endif // _CLICK_INTERFACE_H
