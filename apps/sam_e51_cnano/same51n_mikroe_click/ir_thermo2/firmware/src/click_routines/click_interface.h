/*******************************************************************************
  IR Thermo 2 click routine interface header file

  Company
    Microchip Technology Inc.

  File Name
    click_interface.h

  Summary
    IR Thermo 2 click routine interface implementation File.

  Description
    This file defines the interface to the IR Thermo 2 click routines and MHC PLIB APIs.

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
 * 	1. I2C
 *  The IrThermo2 click example on SAM E51 Curiosity Nano uses
 *  mikroBUS socket #1 on the Curiosity Nano Base for Click boards
 *  to mount IrThermo2 click board. The USART lines from MCU coming to
 *  this socket are from SERCOM2 peripheral on the MCU.
 *
 */

// SERCOM USART Definitions
#define CLICK_IR_THERMO2_I2C_Write              SERCOM2_I2C_Write
#define CLICK_IR_THERMO2_I2C_IsBusy             SERCOM2_I2C_IsBusy
#define CLICK_IR_THERMO2_I2C_WriteRead          SERCOM2_I2C_WriteRead
#define CLICK_IR_THERMO2_I2C_ErrorGet           SERCOM2_I2C_ErrorGet


#endif // _CLICK_INTERFACES_H
