/*******************************************************************************
  Real Time Counter (RTC) PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_rtc_clock.c

  Summary:
    RTC PLIB Implementation file

  Description:
    This file defines the interface to the RTC peripheral library. This
    library provides access to and control of the associated peripheral
    instance in clock/calendar mode.

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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/* This section lists the other files that are included in this file.
*/

#include "plib_rtc.h"
#include "device.h"
#include <stdlib.h>
#include "interrupts.h"

/* Reference Year */
#define REFERENCE_YEAR              (2016U)

/* Refernce Year in tm structure year (C standard) */
#define TM_STRUCT_REFERENCE_YEAR    (1900U)

/* Adjust user year with respect to tm structure year (C Standard) */
#define ADJUST_TM_YEAR(year)        (year + TM_STRUCT_REFERENCE_YEAR)

/* Adjust user month */
#define ADJUST_MONTH(month)         (month + 1)

/* Adjust to tm structure month */
#define ADJUST_TM_STRUCT_MONTH(mon) (mon - 1)


static void RTC_ClockReadSynchronization(void)
{
   /* Read-synchronization for CLOCK register */
   RTC_REGS->MODE2.RTC_READREQ = RTC_READREQ_RREQ_Msk | RTC_READREQ_ADDR(0x10);
   while((RTC_REGS->MODE2.RTC_STATUS & RTC_STATUS_SYNCBUSY_Msk) == RTC_STATUS_SYNCBUSY_Msk)
   {
       /* Wait for Read-Synchronization */
   }
}

void RTC_Initialize(void)
{
    /* Writing to CTRL register will trigger write-synchronization */
    RTC_REGS->MODE2.RTC_CTRL |= RTC_MODE2_CTRL_SWRST_Msk;
    while((RTC_REGS->MODE2.RTC_STATUS & RTC_STATUS_SYNCBUSY_Msk) == RTC_STATUS_SYNCBUSY_Msk)
    {
        /* Wait for Write-Synchronization */
    }

    /* Writing to CTRL register will trigger write-synchronization */
    RTC_REGS->MODE2.RTC_CTRL = RTC_MODE2_CTRL_MODE(2) | RTC_MODE2_CTRL_PRESCALER(0xA) | RTC_MODE2_CTRL_ENABLE_Msk;
    while((RTC_REGS->MODE2.RTC_STATUS & RTC_STATUS_SYNCBUSY_Msk) == RTC_STATUS_SYNCBUSY_Msk)
    {
        /* Wait for Write-Synchronization */
    }

}

bool RTC_RTCCTimeSet (struct tm * initialTime )
{
    /* Writing to CLOCK register will trigger write-synchronization */
    RTC_REGS->MODE2.RTC_CLOCK = ((TM_STRUCT_REFERENCE_YEAR + initialTime->tm_year) - REFERENCE_YEAR) << RTC_MODE2_CLOCK_YEAR_Pos |
                    ((ADJUST_MONTH(initialTime->tm_mon)) << RTC_MODE2_CLOCK_MONTH_Pos) |
                    (initialTime->tm_mday << RTC_MODE2_CLOCK_DAY_Pos) |
                    (initialTime->tm_hour << RTC_MODE2_CLOCK_HOUR_Pos) |
                    (initialTime->tm_min << RTC_MODE2_CLOCK_MINUTE_Pos) |
                    (initialTime->tm_sec << RTC_MODE2_CLOCK_SECOND_Pos);
    while((RTC_REGS->MODE2.RTC_STATUS & RTC_STATUS_SYNCBUSY_Msk) == RTC_STATUS_SYNCBUSY_Msk)
    {
        /* Wait for Write-Synchronization */
    }
    return true;
}

void RTC_RTCCTimeGet ( struct tm * currentTime )
{
    uint32_t dataClockCalendar = 0;

    /* Enable read-synchronization for CLOCK register to avoid CPU stall */
    RTC_ClockReadSynchronization();
    dataClockCalendar = RTC_REGS->MODE2.RTC_CLOCK;

    currentTime->tm_hour =  (dataClockCalendar & RTC_MODE2_CLOCK_HOUR_Msk) >> RTC_MODE2_CLOCK_HOUR_Pos;
    currentTime->tm_min  =  (dataClockCalendar & RTC_MODE2_CLOCK_MINUTE_Msk) >> RTC_MODE2_CLOCK_MINUTE_Pos;
    currentTime->tm_sec  =  (dataClockCalendar & RTC_MODE2_CLOCK_SECOND_Msk) >> RTC_MODE2_CLOCK_SECOND_Pos;

    currentTime->tm_mon  =  ADJUST_TM_STRUCT_MONTH(((dataClockCalendar & RTC_MODE2_CLOCK_MONTH_Msk) >> RTC_MODE2_CLOCK_MONTH_Pos));
    currentTime->tm_year =  (((dataClockCalendar & RTC_MODE2_CLOCK_YEAR_Msk)>> RTC_MODE2_CLOCK_YEAR_Pos) + REFERENCE_YEAR) - TM_STRUCT_REFERENCE_YEAR;
    currentTime->tm_mday =  (dataClockCalendar & RTC_MODE2_CLOCK_DAY_Msk) >> RTC_MODE2_CLOCK_DAY_Pos;
}
