/*******************************************************************************
  Real Time Counter (RTC) PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_rtc_timer.c

  Summary:
    RTC PLIB Implementation file

  Description:
    This file defines the interface to the RTC peripheral library. This
    library provides access to and control of the associated peripheral
    instance in timer mode.

*******************************************************************************/
// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#include "interrupts.h"
#include "plib_rtc.h"
#include <stdlib.h>

volatile static RTC_OBJECT rtcObj;


void RTC_Initialize(void)
{
    RTC_REGS->MODE0.RTC_CTRLA = RTC_MODE0_CTRLA_SWRST_Msk;

    while((RTC_REGS->MODE0.RTC_SYNCBUSY & RTC_MODE0_SYNCBUSY_SWRST_Msk) == RTC_MODE0_SYNCBUSY_SWRST_Msk)
    {
        /* Wait for Synchronization after Software Reset */
    }


    RTC_REGS->MODE0.RTC_CTRLA = (uint16_t)(RTC_MODE0_CTRLA_MODE(0UL) | RTC_MODE0_CTRLA_PRESCALER(0x1UL) | RTC_MODE0_CTRLA_COUNTSYNC_Msk |RTC_MODE0_CTRLA_MATCHCLR_Msk );
    while((RTC_REGS->MODE0.RTC_SYNCBUSY & RTC_MODE0_SYNCBUSY_COUNTSYNC_Msk) == RTC_MODE0_SYNCBUSY_COUNTSYNC_Msk)
    {
       /* Wait for Synchronization */
    }
   RTC_REGS->MODE0.RTC_COMP = 0x200U;
    while((RTC_REGS->MODE0.RTC_SYNCBUSY & RTC_MODE0_SYNCBUSY_COMP0_Msk) == RTC_MODE0_SYNCBUSY_COMP0_Msk)
    {
        /* Wait for Synchronization after writing Compare Value */
    }

    RTC_REGS->MODE0.RTC_INTENSET = 0x100U;

}


void RTC_Timer32CountSyncEnable ( void )
{
    RTC_REGS->MODE0.RTC_CTRLA |= RTC_MODE0_CTRLA_COUNTSYNC_Msk;

    while((RTC_REGS->MODE0.RTC_SYNCBUSY & RTC_MODE0_SYNCBUSY_COUNTSYNC_Msk) == RTC_MODE0_SYNCBUSY_COUNTSYNC_Msk)
    {
        /* Wait for Synchronization */
    }
}

void RTC_Timer32CountSyncDisable ( void )
{
    RTC_REGS->MODE0.RTC_CTRLA &= (uint16_t)(~RTC_MODE0_CTRLA_COUNTSYNC_Msk);

    while((RTC_REGS->MODE0.RTC_SYNCBUSY & RTC_MODE0_SYNCBUSY_COUNTSYNC_Msk) == RTC_MODE0_SYNCBUSY_COUNTSYNC_Msk)
    {
        /* Wait for Synchronization */
    }
}

void RTC_Timer32Start ( void )
{
    RTC_REGS->MODE0.RTC_CTRLA |= RTC_MODE0_CTRLA_ENABLE_Msk;

    while((RTC_REGS->MODE0.RTC_SYNCBUSY & RTC_MODE0_SYNCBUSY_ENABLE_Msk) == RTC_MODE0_SYNCBUSY_ENABLE_Msk)
    {
        /* Wait for synchronization after Enabling RTC */
    }
}


void RTC_Timer32Stop ( void )
{
    RTC_REGS->MODE0.RTC_CTRLA &= (uint16_t)(~RTC_MODE0_CTRLA_ENABLE_Msk);

    while((RTC_REGS->MODE0.RTC_SYNCBUSY & RTC_MODE0_SYNCBUSY_ENABLE_Msk) == RTC_MODE0_SYNCBUSY_ENABLE_Msk)
    {
        /* Wait for Synchronization after Disabling RTC */
    }
}

void RTC_Timer32CounterSet ( uint32_t count )
{
    RTC_REGS->MODE0.RTC_COUNT = count;

    while((RTC_REGS->MODE0.RTC_SYNCBUSY & RTC_MODE0_SYNCBUSY_COUNT_Msk) == RTC_MODE0_SYNCBUSY_COUNT_Msk)
    {
        /* Wait for Synchronization after writing value to Count Register */
    }
}

void RTC_Timer32CompareSet ( uint32_t compareValue )
{
    RTC_REGS->MODE0.RTC_COMP = compareValue;

    while((RTC_REGS->MODE0.RTC_SYNCBUSY & RTC_MODE0_SYNCBUSY_COMP0_Msk) == RTC_MODE0_SYNCBUSY_COMP0_Msk)
    {
        /* Wait for Synchronization after writing Compare Value */
    }
}
uint32_t RTC_Timer32CounterGet ( void )
{
    if ((RTC_REGS->MODE0.RTC_CTRLA & RTC_MODE0_CTRLA_COUNTSYNC_Msk) == 0U)
    {
        RTC_REGS->MODE0.RTC_CTRLA |= RTC_MODE0_CTRLA_COUNTSYNC_Msk;

        while((RTC_REGS->MODE0.RTC_SYNCBUSY & RTC_MODE0_SYNCBUSY_COUNTSYNC_Msk) == RTC_MODE0_SYNCBUSY_COUNTSYNC_Msk)
        {
           /* Wait for Synchronization */
        }
    }
    while((RTC_REGS->MODE0.RTC_SYNCBUSY & RTC_MODE0_SYNCBUSY_COUNT_Msk) == RTC_MODE0_SYNCBUSY_COUNT_Msk)
    {
        /* Wait for Synchronization before reading value from Count Register */
    }
   return(RTC_REGS->MODE0.RTC_COUNT);
}

uint32_t RTC_Timer32PeriodGet ( void )
{
    /* Get 32Bit Compare Value */
             /*lint -e{9048} PC lint incorrectly reports a missing 'U' Suffix */
    return (RTC_MODE0_COUNT_COUNT_Msk);
}

uint32_t RTC_Timer32FrequencyGet ( void )
{
    /* Return Frequency of RTC Clock */
    return RTC_COUNTER_CLOCK_FREQUENCY;
}

void RTC_Timer32InterruptEnable(RTC_TIMER32_INT_MASK interruptMask)
{
    RTC_REGS->MODE0.RTC_INTENSET = (uint16_t)interruptMask;
}

void RTC_Timer32InterruptDisable(RTC_TIMER32_INT_MASK interruptMask)
{
    RTC_REGS->MODE0.RTC_INTENCLR = (uint16_t)interruptMask;
}


void RTC_Timer32CallbackRegister ( RTC_TIMER32_CALLBACK callback, uintptr_t context )
{
    rtcObj.timer32BitCallback = callback;
    rtcObj.context            = context;
}

void __attribute__((used)) RTC_InterruptHandler( void )
{
    rtcObj.timer32intCause = (RTC_TIMER32_INT_MASK) RTC_REGS->MODE0.RTC_INTFLAG;
    RTC_REGS->MODE0.RTC_INTFLAG = (uint16_t)RTC_MODE0_INTFLAG_Msk;
    (void)RTC_REGS->MODE0.RTC_INTFLAG;

    /* Invoke registered Callback function */
    if(rtcObj.timer32BitCallback != NULL)
    {
        RTC_TIMER32_INT_MASK timer32intCause = rtcObj.timer32intCause;
        uintptr_t context = rtcObj.context;
        rtcObj.timer32BitCallback( timer32intCause, context );
    }
}
