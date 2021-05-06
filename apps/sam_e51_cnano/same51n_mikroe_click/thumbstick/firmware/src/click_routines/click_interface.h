/*******************************************************************************
  Click interface header file

  Company:
    Microchip Technology Inc.

  File Name:
    click_interface.h

  Summary:
    Thumbstick click routine interface implementation File.

  Description
    This file defines the interface to the Thumbstick click routines and MHC
    PLIB APIs.

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

/** Click routine interfaces/resources Macro Declarations
 *
 *  1. SPI
 *  The thumbstick click example on SAM E51 Curiosity Nano uses
 *  mikroBUS socket #1 to mount thumbstick click board.
 *  The SPI lines from MCU coming to this socket are from
 *  SERCOM1 peripheral. The SPI is configured to use manual chip select.
 *
 *
 * 2. Timer
 *  The thumbstick click  example on SAM E51 Curiosity Nano uses
 *  Systick timer module on the MCU to implement the time
 *  requirement of the thumbstick click routines.
 *
 * 3. PORTs
 *  The thumbstick click uses the following ports pins.
 *  CLICK_THUMBSTICK_CS
 *  The pin is configured using the MHC Pin configurator.
 */

// SPI Definitions
#define CLICK_THUMBSTICK_SPI_WriteRead      SERCOM1_SPI_WriteRead
#define CLICK_THUMBSTICK_SPI_IsBusy         SERCOM1_SPI_IsBusy

// Timer Definitions
#define CLICK_THUMBSTICK_TimerStart         SYSTICK_TimerStart
#define CLICK_THUMBSTICK_DelayMs            SYSTICK_DelayMs

#endif // _CLICK_INTERFACES_H
