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
#include "definitions.h"
/**	Click routine interfaces/resources Macro Declarations
 *
 * 	1. I2C
 *  The weather click example on SAM E51 Curiosity Nano uses
 *  mikroBUS socket #1 on the Curiosity Nano Base for Click boards
 *  to mount weather click board. The I2C lines from MCU coming to
 *  this socket are from SERCOM2 peripheral on the MCU.
 *
 * 2. Timer
 *  The weather click example on SAM E51 Curiosity Nano uses
 *  Systick timer module on the MCU to implement the time
 *  requirement of weather click routines.
 *
 */

// I2C Definitions
#define CLICK_WEATHER_I2C_Write 			SERCOM2_I2C_Write
#define CLICK_WEATHER_I2C_IsBusy 			SERCOM2_I2C_IsBusy
#define CLICK_WEATHER_I2C_WriteRead			SERCOM2_I2C_WriteRead

// Timer Definitions
#define CLICK_WEATHER_TimerStart 			SYSTICK_TimerStart
#define CLICK_WEATHER_DelayMs				SYSTICK_DelayMs

// I2C Definitions
#define CLICK_10DOF_I2C_Write 			SERCOM2_I2C_Write
#define CLICK_10DOF_I2C_IsBusy 			SERCOM2_I2C_IsBusy
#define CLICK_10DOF_I2C_WriteRead	    SERCOM2_I2C_WriteRead

// Timer Definitions
#define CLICK_10DOF_TimerStart          SYSTICK_TimerStart
#define CLICK_10DOF_DelayMs             SYSTICK_DelayMs

#endif // _CLICK_INTERFACES_H
