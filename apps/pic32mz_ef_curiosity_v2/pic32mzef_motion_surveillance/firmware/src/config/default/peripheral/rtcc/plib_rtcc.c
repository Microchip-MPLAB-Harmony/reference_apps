/*******************************************************************************
  Real Time Counter (RTCC) PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_rtcc.c

  Summary:
    RTCC PLIB Implementation file

  Description:
    This file defines the interface to the RTC peripheral library. This
    library provides access to and control of the associated peripheral
    instance in clock/calendar mode.

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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

#include "plib_rtcc.h"
#include "interrupts.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************

/* Real Time Clock System Service Object */
typedef struct SYS_RTCC_OBJ_STRUCT
{
    /* Call back function for RTCC.*/
    RTCC_CALLBACK  callback;

    /* Client data (Event Context) that will be passed to callback */
    uintptr_t context;

} RTCC_OBJECT;

volatile static RTCC_OBJECT rtcc;


// *****************************************************************************
// *****************************************************************************
// Section: Local functions
// *****************************************************************************
// *****************************************************************************
__STATIC_INLINE uint32_t decimaltobcd( uint32_t aDecValue )
{
    uint32_t  decValueDiv10 = aDecValue / 10U;

    return( (decValueDiv10 << 4U) + ( aDecValue - (decValueDiv10 * 10U) ) );
}

__STATIC_INLINE uint32_t bcdtodecimal( uint32_t aBcdValue )
{
    return( (10U * ((aBcdValue & 0xF0U) >> 4U)) + (aBcdValue & 0x0FU) );
}


// *****************************************************************************
// *****************************************************************************
// Section: RTCC Implementation
// *****************************************************************************
// *****************************************************************************

void RTCC_Initialize( void )
{
    /* Unlock System */
    SYSKEY = 0x00000000;
    SYSKEY = 0xAA996655U;
    SYSKEY = 0x556699AA;

    RTCCONSET = _RTCCON_RTCWREN_MASK;  /* Enable writes to RTCC */

    /* Lock System */
    SYSKEY = 0x00000000;

    RTCCONbits.RTCOE = 0;  /* Disable RTCC output */

    /* Set RTCC clock source (LPRC/SOSC) */
    RTCCONbits.RTCCLKSEL = 0;

    RTCCONbits.ON = 0;   /* Disable clock to RTCC */
    while((RTCCONbits.RTCCLKON) != 0U)  
    {
        /* Wait for clock to stop */
    }

    RTCTIME = 0x00000000;   /* Set RTCC time */
    RTCDATE = 0x00000001;  /* Set RTCC date */

    /* Set alarm to repeat finite number of times */
    RTCALRMCLR = _RTCALRM_CHIME_MASK;
    RTCALRMbits.ARPT = 0;


    /* start the RTC */
    RTCCONSET = _RTCCON_ON_MASK;
}

void RTCC_InterruptEnable( RTCC_INT_MASK interrupt )
{
    IEC5SET = (uint32_t)interrupt;
}

void RTCC_InterruptDisable( RTCC_INT_MASK interrupt )
{
    IEC5CLR = (uint32_t)interrupt;
}

bool RTCC_TimeSet( struct tm *Time )
{
    uint32_t timeField = 0, dateField = 0;

    timeField = (decimaltobcd((uint32_t)Time->tm_hour) << _RTCTIME_HR01_POSITION) & (_RTCTIME_HR10_MASK | _RTCTIME_HR01_MASK);
    timeField |= (decimaltobcd((uint32_t)Time->tm_min) << _RTCTIME_MIN01_POSITION) & (_RTCTIME_MIN10_MASK | _RTCTIME_MIN01_MASK);
    timeField |= (decimaltobcd((uint32_t)Time->tm_sec) << _RTCTIME_SEC01_POSITION) & (_RTCTIME_SEC10_MASK | _RTCTIME_SEC01_MASK);

    while((RTCCON & _RTCCON_RTCSYNC_MASK) != 0U)
    {
        /* Wait for synchronization */
    }

    RTCTIME = timeField;

    dateField = (decimaltobcd(((uint32_t)Time->tm_year) % 100U) << _RTCDATE_YEAR01_POSITION) & (_RTCDATE_YEAR01_MASK | _RTCDATE_YEAR10_MASK);
    dateField |= (decimaltobcd(((uint32_t)Time->tm_mon + 1U)) << _RTCDATE_MONTH01_POSITION)&(_RTCDATE_MONTH01_MASK | _RTCDATE_MONTH10_MASK);
    dateField |= (decimaltobcd((uint32_t)Time->tm_mday) << _RTCDATE_DAY01_POSITION) & (_RTCDATE_DAY01_MASK | _RTCDATE_DAY10_MASK);
    dateField |= decimaltobcd((uint32_t)Time->tm_wday) & _RTCDATE_WDAY01_MASK;

    while((RTCCON & _RTCCON_RTCSYNC_MASK) != 0U)
    {
        /* Do Nothing */
    }

    RTCDATE = dateField;

    RTCCONSET = _RTCCON_ON_MASK;  /* Start the RTCC module */

    return true;    /* This PLIB has no way of indicating wrong device operation so always return true */
}

void RTCC_TimeGet( struct tm  *Time )
{
    uint32_t dataTime, dataDate;
    uint32_t tmp;

    while((RTCCON & _RTCCON_RTCSYNC_MASK) != 0U)
    {
        /* Wait for synchronization */
    }

    dataTime = RTCTIME;  /* read the time from the RTC */

    tmp = (10U * (bcdtodecimal((dataTime & _RTCTIME_HR10_MASK) >> _RTCTIME_HR10_POSITION)) +
                         bcdtodecimal((dataTime & _RTCTIME_HR01_MASK) >> _RTCTIME_HR01_POSITION));
    Time->tm_hour = (int)tmp;

    tmp = (10U * (bcdtodecimal((dataTime & _RTCTIME_MIN10_MASK) >> _RTCTIME_MIN10_POSITION)) +
                         bcdtodecimal((dataTime & _RTCTIME_MIN01_MASK) >> _RTCTIME_MIN01_POSITION));
    Time->tm_min = (int)tmp;

    tmp = (10U * (bcdtodecimal((dataTime & _RTCTIME_SEC10_MASK) >> _RTCTIME_SEC10_POSITION)) +
                         bcdtodecimal((dataTime & _RTCTIME_SEC01_MASK) >> _RTCTIME_SEC01_POSITION));
    Time->tm_sec = (int)tmp;

    while((RTCCON & _RTCCON_RTCSYNC_MASK) != 0U)
    {
        /* Do Nothing */
    }

    dataDate = RTCDATE;  /* read the date from the RTC */

    tmp = (10U * (bcdtodecimal((dataDate & _RTCDATE_YEAR10_MASK) >> _RTCDATE_YEAR10_POSITION)) +
                         bcdtodecimal((dataDate & _RTCDATE_YEAR01_MASK) >> _RTCDATE_YEAR01_POSITION));
    tmp += 2000U; /* This RTC designed for 0-99 year range.  Need to add 2000 to that. */
    Time->tm_year = (int)tmp;

    tmp = (10U * (bcdtodecimal((dataDate & _RTCDATE_MONTH10_MASK) >> _RTCDATE_MONTH10_POSITION)) +
                  bcdtodecimal((dataDate & _RTCDATE_MONTH01_MASK) >> _RTCDATE_MONTH01_POSITION)) - 1U;
    Time->tm_mon = (int)tmp;

    tmp = (10 * (bcdtodecimal((dataDate & _RTCDATE_DAY10_MASK) >> _RTCDATE_DAY10_POSITION)) +
                         bcdtodecimal((dataDate & _RTCDATE_DAY01_MASK) >> _RTCDATE_DAY01_POSITION));
    Time->tm_mday = (int)tmp;

    tmp = bcdtodecimal((dataDate & _RTCDATE_WDAY01_MASK) >> _RTCDATE_WDAY01_POSITION);
    Time->tm_wday = (int)tmp;

    Time->tm_yday = 0;  /* not used */
    Time->tm_isdst = 0;    /* not used */
}

bool RTCC_AlarmSet( struct tm *alarmTime, RTCC_ALARM_MASK alarmFreq )
{
    uint32_t dataDate, dataTime;

    /* Disable interrupt, if enabled, before setting up alarm */
    RTCC_InterruptDisable(RTCC_INT_ALARM);

    RTCALRMCLR = _RTCALRM_ALRMEN_MASK;  /* Disable alarm */
    while((RTCALRMbits.ALRMSYNC) != 0U) 
    {
        /* Wait for disable */
    }

    if(RTCC_ALARM_MASK_OFF != alarmFreq)
    {
        dataDate  = (decimaltobcd(((uint32_t)alarmTime->tm_mon + 1U)) << _RTCDATE_MONTH01_POSITION) & (_RTCDATE_MONTH01_MASK | _RTCDATE_MONTH10_MASK);
        dataDate |= (decimaltobcd((uint32_t)alarmTime->tm_mday) << _RTCDATE_DAY01_POSITION) & (_RTCDATE_DAY01_MASK | _RTCDATE_DAY10_MASK);
        dataDate |= decimaltobcd((uint32_t)alarmTime->tm_wday) & _RTCDATE_WDAY01_MASK;

        dataTime  = (decimaltobcd((uint32_t)alarmTime->tm_hour) << _RTCTIME_HR01_POSITION) & (_RTCTIME_HR10_MASK | _RTCTIME_HR01_MASK);
        dataTime |= (decimaltobcd((uint32_t)alarmTime->tm_min) << _RTCTIME_MIN01_POSITION) & (_RTCTIME_MIN10_MASK | _RTCTIME_MIN01_MASK);
        dataTime |= (decimaltobcd((uint32_t)alarmTime->tm_sec) << _RTCTIME_SEC01_POSITION) & (_RTCTIME_SEC10_MASK | _RTCTIME_SEC01_MASK);

        while((RTCCON & _RTCCON_RTCSYNC_MASK) != 0U)
        {
           /* Do Nothing */
        }

        ALRMDATE = dataDate;

        while((RTCCON & _RTCCON_RTCSYNC_MASK) != 0U)
        {
            /* Wait for synchronization */
        }

        ALRMTIME = dataTime;

        /* Configure alarm repetition */
        RTCALRMbits.AMASK = (uint8_t)alarmFreq;

        /* ALRMEN = 1 */
        RTCALRMSET = _RTCALRM_ALRMEN_MASK;  /* Enable the alarm */
    }

    RTCC_InterruptEnable(RTCC_INT_ALARM);  /* Enable the interrupt to the interrupt controller */

    return true;  /* This PLIB has no way of indicating wrong device operation so always return true */
}

void RTCC_CallbackRegister( RTCC_CALLBACK callback, uintptr_t context )
{
    rtcc.callback = callback;

    rtcc.context = context;
}

void __attribute__((used)) RTCC_InterruptHandler( void )
{
    /* Clear the status flag */
    IFS5CLR = 0x40;

    if(rtcc.callback != NULL)
    {
        uintptr_t context = rtcc.context;
        rtcc.callback(context);
    }
}

