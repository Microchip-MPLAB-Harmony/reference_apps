/*******************************************************************************
  Motor Control PWM (MCPWM) Peripheral Library (PLIB)

  Company:
    Microchip Technology Inc.

  File Name:
    plib_mcpwm.c

  Summary:
    MCPWM Source File

  Description:
    None

*******************************************************************************/

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
#include "device.h"
#include "plib_mcpwm.h"
#include "interrupts.h"

// *****************************************************************************

// *****************************************************************************
// Section: MCPWM Implementation
// *****************************************************************************
// *****************************************************************************
volatile static MCPWM_CH_OBJECT mcpwmObj[12];

void MCPWM_Initialize (void)
{
    /* PTCON register  */
    /*  SEVTPS  = 0 */
    /*  PCLKDIV = 0 */
    /*  SEIEN   = false */
    PTCON = 0x0;

    /* STCON register  */
    /*  SEVTPS  = 0 */
    /*  SCLKDIV = 0 */
    /*  SSEIEN = false */
    STCON = 0x0;

    PTPER = 3000;
    STPER = 2000;
    SEVTCMP = 10;
    SSEVTCMP = 10;

    /*********** Channel 1 Configurations **********/
    /* PWMCON1 register  */
    /*  MTBS   = 0 */
    /*  PTDIR  =  0 */
    /*  ECAM   =  1 */
    /*  DTCP   =  0 */
    /*  DTC    =  0 */
    /*  ITB    = 0 */
    /*  PWMHIEN =  false */
    /*  PWMLIEN = false */
    /*  TRGIEN = false */
    /*  CLIEN = false */
    /*  FLTIEN = true */
    PWMCON1 = 0x800400;

    /* IOCON1 register  */
    /*  SWAP    = 0*/
    /*  PMOD    = 0*/
    /*  POLH    = 0*/
    /*  POLL    = 0*/
    /*  FLTDAT  = 0b00 */
    /*  FLTMOD  = 1 */
    /*  PENH  = 1 */
    /*  PENL  = 1 */
    /*  FLTPOL  = 1  */
    /*  FLTSRC  = 3  */
    /*  CLDAT  = 0b00 */
    /*  CLMOD  = 0 */
    /*  CLPOL  = 0  */
    /*  CLSRC  = 3  */
    IOCON1 = 0xc1dc000;

    PDC1 = 1000;
    SDC1 = 500;
    PHASE1 = 0;

    /* Dead Time */
    DTR1 = 120;
    ALTDTR1 = 120;

    /* Trigger Generator */
    TRGCON1 = 0x400;
    TRIG1 = 2990;
    STRIG1 = 0;

    /* leading edge blanking */
    /* LEBCON1 register  */
    /*  CLLEBEN    = false  */
    /*  FLTLEBEN   = false */
    /*  PLF        = 0  */
    /*  PLR        = 0  */
    /*  PHF        = 0  */
    /*  PHR        = 0  */
    LEBCON1 = 0x0;
    LEBDLY1 = 10;

    /* Enable interrupt */
    IEC5SET = _IEC5_PWM1IE_MASK;
    mcpwmObj[0].callback = NULL;

    /*********** Channel 2 Configurations **********/
    /* PWMCON2 register  */
    /*  MTBS   = 0 */
    /*  PTDIR  =  0 */
    /*  ECAM   =  1 */
    /*  DTCP   =  0 */
    /*  DTC    =  0 */
    /*  ITB    = 0 */
    /*  PWMHIEN =  false */
    /*  PWMLIEN = false */
    /*  TRGIEN = false */
    /*  CLIEN = false */
    /*  FLTIEN = false */
    PWMCON2 = 0x400;

    /* IOCON2 register  */
    /*  SWAP    = 0*/
    /*  PMOD    = 0*/
    /*  POLH    = 0*/
    /*  POLL    = 0*/
    /*  FLTDAT  = 0b00 */
    /*  FLTMOD  = 1 */
    /*  PENH  = 1 */
    /*  PENL  = 1 */
    /*  FLTPOL  = 1  */
    /*  FLTSRC  = 3  */
    /*  CLDAT  = 0b00 */
    /*  CLMOD  = 0 */
    /*  CLPOL  = 0  */
    /*  CLSRC  = 3  */
    IOCON2 = 0xc1dc000;

    PDC2 = 1000;
    SDC2 = 500;
    PHASE2 = 0;

    /* Dead Time */
    DTR2 = 120;
    ALTDTR2 = 120;

    /* Trigger Generator */
    TRGCON2 = 0x400;
    TRIG2 = 2990;
    STRIG2 = 0;

    /* leading edge blanking */
    /* LEBCON2 register  */
    /*  CLLEBEN    = false  */
    /*  FLTLEBEN   = false */
    /*  PLF        = 0  */
    /*  PLR        = 0  */
    /*  PHF        = 0  */
    /*  PHR        = 0  */
    LEBCON2 = 0x0;
    LEBDLY2 = 10;


    /*********** Channel 3 Configurations **********/
    /* PWMCON3 register  */
    /*  MTBS   = 0 */
    /*  PTDIR  =  0 */
    /*  ECAM   =  1 */
    /*  DTCP   =  0 */
    /*  DTC    =  0 */
    /*  ITB    = 0 */
    /*  PWMHIEN =  false */
    /*  PWMLIEN = false */
    /*  TRGIEN = false */
    /*  CLIEN = false */
    /*  FLTIEN = false */
    PWMCON3 = 0x400;

    /* IOCON3 register  */
    /*  SWAP    = 0*/
    /*  PMOD    = 0*/
    /*  POLH    = 0*/
    /*  POLL    = 0*/
    /*  FLTDAT  = 0b00 */
    /*  FLTMOD  = 1 */
    /*  PENH  = 1 */
    /*  PENL  = 1 */
    /*  FLTPOL  = 1  */
    /*  FLTSRC  = 3  */
    /*  CLDAT  = 0b00 */
    /*  CLMOD  = 0 */
    /*  CLPOL  = 0  */
    /*  CLSRC  = 3  */
    IOCON3 = 0xc1dc000;

    PDC3 = 1000;
    SDC3 = 500;
    PHASE3 = 0;

    /* Dead Time */
    DTR3 = 120;
    ALTDTR3 = 120;

    /* Trigger Generator */
    TRGCON3 = 0x400;
    TRIG3 = 2990;
    STRIG3 = 0;

    /* leading edge blanking */
    /* LEBCON3 register  */
    /*  CLLEBEN    = false  */
    /*  FLTLEBEN   = false */
    /*  PLF        = 0  */
    /*  PLR        = 0  */
    /*  PHF        = 0  */
    /*  PHR        = 0  */
    LEBCON3 = 0x0;
    LEBDLY3 = 10;


    /*********** Channel 7 Configurations **********/
    /* PWMCON7 register  */
    /*  MTBS   = 0 */
    /*  PTDIR  =  0 */
    /*  ECAM   =  1 */
    /*  DTCP   =  0 */
    /*  DTC    =  0 */
    /*  ITB    = 0 */
    /*  PWMHIEN =  false */
    /*  PWMLIEN = false */
    /*  TRGIEN = false */
    /*  CLIEN = false */
    /*  FLTIEN = true */
    PWMCON7 = 0x800400;

    /* IOCON7 register  */
    /*  SWAP    = 0*/
    /*  PMOD    = 0*/
    /*  POLH    = 0*/
    /*  POLL    = 0*/
    /*  FLTDAT  = 0b00 */
    /*  FLTMOD  = 1 */
    /*  PENH  = 1 */
    /*  PENL  = 1 */
    /*  FLTPOL  = 1  */
    /*  FLTSRC  = 7  */
    /*  CLDAT  = 0b00 */
    /*  CLMOD  = 0 */
    /*  CLPOL  = 0  */
    /*  CLSRC  = 7  */
    IOCON7 = 0x1c3dc000;

    PDC7 = 1000;
    SDC7 = 500;
    PHASE7 = 0;

    /* Dead Time */
    DTR7 = 120;
    ALTDTR7 = 120;

    /* Trigger Generator */
    TRGCON7 = 0x400;
    TRIG7 = 2990;
    STRIG7 = 0;

    /* leading edge blanking */
    /* LEBCON7 register  */
    /*  CLLEBEN    = false  */
    /*  FLTLEBEN   = false */
    /*  PLF        = 0  */
    /*  PLR        = 0  */
    /*  PHF        = 0  */
    /*  PHR        = 0  */
    LEBCON7 = 0x0;
    LEBDLY7 = 10;

    /* Enable interrupt */
    IEC7SET = _IEC7_PWM7IE_MASK;
    mcpwmObj[6].callback = NULL;

    /*********** Channel 8 Configurations **********/
    /* PWMCON8 register  */
    /*  MTBS   = 0 */
    /*  PTDIR  =  0 */
    /*  ECAM   =  1 */
    /*  DTCP   =  0 */
    /*  DTC    =  0 */
    /*  ITB    = 0 */
    /*  PWMHIEN =  false */
    /*  PWMLIEN = false */
    /*  TRGIEN = false */
    /*  CLIEN = false */
    /*  FLTIEN = false */
    PWMCON8 = 0x400;

    /* IOCON8 register  */
    /*  SWAP    = 0*/
    /*  PMOD    = 0*/
    /*  POLH    = 0*/
    /*  POLL    = 0*/
    /*  FLTDAT  = 0b00 */
    /*  FLTMOD  = 1 */
    /*  PENH  = 1 */
    /*  PENL  = 1 */
    /*  FLTPOL  = 1  */
    /*  FLTSRC  = 7  */
    /*  CLDAT  = 0b00 */
    /*  CLMOD  = 0 */
    /*  CLPOL  = 0  */
    /*  CLSRC  = 7  */
    IOCON8 = 0x1c3dc000;

    PDC8 = 1000;
    SDC8 = 500;
    PHASE8 = 0;

    /* Dead Time */
    DTR8 = 120;
    ALTDTR8 = 120;

    /* Trigger Generator */
    TRGCON8 = 0x400;
    TRIG8 = 2990;
    STRIG8 = 0;

    /* leading edge blanking */
    /* LEBCON8 register  */
    /*  CLLEBEN    = false  */
    /*  FLTLEBEN   = false */
    /*  PLF        = 0  */
    /*  PLR        = 0  */
    /*  PHF        = 0  */
    /*  PHR        = 0  */
    LEBCON8 = 0x0;
    LEBDLY8 = 10;


    /*********** Channel 9 Configurations **********/
    /* PWMCON9 register  */
    /*  MTBS   = 0 */
    /*  PTDIR  =  0 */
    /*  ECAM   =  1 */
    /*  DTCP   =  0 */
    /*  DTC    =  0 */
    /*  ITB    = 0 */
    /*  PWMHIEN =  false */
    /*  PWMLIEN = false */
    /*  TRGIEN = false */
    /*  CLIEN = false */
    /*  FLTIEN = false */
    PWMCON9 = 0x400;

    /* IOCON9 register  */
    /*  SWAP    = 0*/
    /*  PMOD    = 0*/
    /*  POLH    = 0*/
    /*  POLL    = 0*/
    /*  FLTDAT  = 0b00 */
    /*  FLTMOD  = 1 */
    /*  PENH  = 1 */
    /*  PENL  = 1 */
    /*  FLTPOL  = 1  */
    /*  FLTSRC  = 7  */
    /*  CLDAT  = 0b00 */
    /*  CLMOD  = 0 */
    /*  CLPOL  = 0  */
    /*  CLSRC  = 7  */
    IOCON9 = 0x1c3dc000;

    PDC9 = 1000;
    SDC9 = 500;
    PHASE9 = 0;

    /* Dead Time */
    DTR9 = 120;
    ALTDTR9 = 120;

    /* Trigger Generator */
    TRGCON9 = 0x400;
    TRIG9 = 2990;
    STRIG9 = 0;

    /* leading edge blanking */
    /* LEBCON9 register  */
    /*  CLLEBEN    = false  */
    /*  FLTLEBEN   = false */
    /*  PLF        = 0  */
    /*  PLR        = 0  */
    /*  PHF        = 0  */
    /*  PHR        = 0  */
    LEBCON9 = 0x0;
    LEBDLY9 = 10;


    /*********** Channel 10 Configurations **********/
    /* PWMCON10 register  */
    /*  MTBS   = 0 */
    /*  PTDIR  =  0 */
    /*  ECAM   =  1 */
    /*  DTCP   =  0 */
    /*  DTC    =  0 */
    /*  ITB    = 0 */
    /*  PWMHIEN =  false */
    /*  PWMLIEN = false */
    /*  TRGIEN = false */
    /*  CLIEN = false */
    /*  FLTIEN = true */
    PWMCON10 = 0x800400;

    /* IOCON10 register  */
    /*  SWAP    = 0*/
    /*  PMOD    = 0*/
    /*  POLH    = 0*/
    /*  POLL    = 0*/
    /*  FLTDAT  = 0b00 */
    /*  FLTMOD  = 1 */
    /*  PENH  = 1 */
    /*  PENL  = 1 */
    /*  FLTPOL  = 1  */
    /*  FLTSRC  = 2  */
    /*  CLDAT  = 0b00 */
    /*  CLMOD  = 0 */
    /*  CLPOL  = 0  */
    /*  CLSRC  = 2  */
    IOCON10 = 0x815c000;

    PDC10 = 1000;
    SDC10 = 500;
    PHASE10 = 0;

    /* Dead Time */
    DTR10 = 120;
    ALTDTR10 = 120;

    /* Trigger Generator */
    TRGCON10 = 0x400;
    TRIG10 = 2990;
    STRIG10 = 0;

    /* leading edge blanking */
    /* LEBCON10 register  */
    /*  CLLEBEN    = false  */
    /*  FLTLEBEN   = false */
    /*  PLF        = 0  */
    /*  PLR        = 0  */
    /*  PHF        = 0  */
    /*  PHR        = 0  */
    LEBCON10 = 0x0;
    LEBDLY10 = 10;

    /* Enable interrupt */
    IEC7SET = _IEC7_PWM10IE_MASK;
    mcpwmObj[9].callback = NULL;

    /*********** Channel 11 Configurations **********/
    /* PWMCON11 register  */
    /*  MTBS   = 0 */
    /*  PTDIR  =  0 */
    /*  ECAM   =  1 */
    /*  DTCP   =  0 */
    /*  DTC    =  0 */
    /*  ITB    = 0 */
    /*  PWMHIEN =  false */
    /*  PWMLIEN = false */
    /*  TRGIEN = false */
    /*  CLIEN = false */
    /*  FLTIEN = false */
    PWMCON11 = 0x400;

    /* IOCON11 register  */
    /*  SWAP    = 0*/
    /*  PMOD    = 0*/
    /*  POLH    = 0*/
    /*  POLL    = 0*/
    /*  FLTDAT  = 0b00 */
    /*  FLTMOD  = 1 */
    /*  PENH  = 1 */
    /*  PENL  = 1 */
    /*  FLTPOL  = 1  */
    /*  FLTSRC  = 2  */
    /*  CLDAT  = 0b00 */
    /*  CLMOD  = 0 */
    /*  CLPOL  = 0  */
    /*  CLSRC  = 2  */
    IOCON11 = 0x815c000;

    PDC11 = 1000;
    SDC11 = 500;
    PHASE11 = 0;

    /* Dead Time */
    DTR11 = 120;
    ALTDTR11 = 120;

    /* Trigger Generator */
    TRGCON11 = 0x400;
    TRIG11 = 2990;
    STRIG11 = 0;

    /* leading edge blanking */
    /* LEBCON11 register  */
    /*  CLLEBEN    = false  */
    /*  FLTLEBEN   = false */
    /*  PLF        = 0  */
    /*  PLR        = 0  */
    /*  PHF        = 0  */
    /*  PHR        = 0  */
    LEBCON11 = 0x0;
    LEBDLY11 = 10;


    /*********** Channel 12 Configurations **********/
    /* PWMCON12 register  */
    /*  MTBS   = 0 */
    /*  PTDIR  =  0 */
    /*  ECAM   =  1 */
    /*  DTCP   =  0 */
    /*  DTC    =  0 */
    /*  ITB    = 0 */
    /*  PWMHIEN =  false */
    /*  PWMLIEN = false */
    /*  TRGIEN = false */
    /*  CLIEN = false */
    /*  FLTIEN = false */
    PWMCON12 = 0x400;

    /* IOCON12 register  */
    /*  SWAP    = 0*/
    /*  PMOD    = 0*/
    /*  POLH    = 0*/
    /*  POLL    = 0*/
    /*  FLTDAT  = 0b00 */
    /*  FLTMOD  = 1 */
    /*  PENH  = 1 */
    /*  PENL  = 1 */
    /*  FLTPOL  = 1  */
    /*  FLTSRC  = 2  */
    /*  CLDAT  = 0b00 */
    /*  CLMOD  = 0 */
    /*  CLPOL  = 0  */
    /*  CLSRC  = 2  */
    IOCON12 = 0x815c000;

    PDC12 = 1000;
    SDC12 = 500;
    PHASE12 = 0;

    /* Dead Time */
    DTR12 = 120;
    ALTDTR12 = 120;

    /* Trigger Generator */
    TRGCON12 = 0x400;
    TRIG12 = 2990;
    STRIG12 = 0;

    /* leading edge blanking */
    /* LEBCON12 register  */
    /*  CLLEBEN    = false  */
    /*  FLTLEBEN   = false */
    /*  PLF        = 0  */
    /*  PLR        = 0  */
    /*  PHF        = 0  */
    /*  PHR        = 0  */
    LEBCON12 = 0x0;
    LEBDLY12 = 10;


}


void MCPWM_Start(void)
{
    /* Enable MCPWM module */
    PTCONbits.PTEN = 0x1;
}

void MCPWM_Stop(void)
{
    /* Disable MCPWM module */
    PTCONbits.PTEN = 0x0;
}

void MCPWM_PrimaryPeriodSet(uint16_t period)
{
    PTPER = period;
}

uint16_t MCPWM_PrimaryPeriodGet(void)
{
    return (uint16_t)PTPER;
}


void MCPWM_SecondaryPeriodSet(uint16_t period)
{
    STPER = period;
}

uint16_t MCPWM_SecondaryPeriodGet(void)
{
    return (uint16_t)STPER;
}

void MCPWM_ChannelPrimaryDutySet(MCPWM_CH_NUM channel, uint16_t duty)
{
    *(&PDC1 + (0x40U * (channel))) = duty;
}

void MCPWM_ChannelSecondaryDutySet(MCPWM_CH_NUM channel, uint16_t duty)
{
    *(&SDC1 + (0x40U * (channel))) = duty;
}

void MCPWM_ChannelDeadTimeSet(MCPWM_CH_NUM channel, uint16_t high_deadtime, uint16_t low_deadtime)
{
    *(&DTR1 + (0x40U * (channel))) = ((uint32_t)high_deadtime & (uint32_t)0x3FFFU);
    *(&ALTDTR1 + (0x40U * (channel))) = ((uint32_t)low_deadtime & (uint32_t)0x3FFFU);
}

void MCPWM_ChannelPrimaryTriggerSet(MCPWM_CH_NUM channel, uint16_t trigger)
{
    *(&TRIG1 + (0x40U * (channel))) = trigger;
}

void MCPWM_ChannelSecondaryTriggerSet(MCPWM_CH_NUM channel, uint16_t trigger)
{
    *(&STRIG1 + (0x40U * (channel))) = trigger;
}

void MCPWM_ChannelLeadingEdgeBlankingDelaySet(MCPWM_CH_NUM channel, uint16_t delay)
{
    *(&LEBDLY1 + (0x40U * (channel))) = delay;
}

void MCPWM_ChannelPinsOverrideEnable(MCPWM_CH_NUM channel)
{
    *(&IOCON1 + (0x40U * (channel))) |= _IOCON1_OVRENL_MASK | _IOCON1_OVRENH_MASK;
}

void MCPWM_ChannelPinsOverrideDisable(MCPWM_CH_NUM channel)
{
    *(&IOCON1 + (0x40U * (channel))) &= ~(_IOCON1_OVRENL_MASK | _IOCON1_OVRENH_MASK);
}

void MCPWM_ChannelPinsOwnershipEnable(MCPWM_CH_NUM channel)
{
    *(&IOCON1 + (0x40U * (channel))) |= _IOCON1_PENH_MASK | _IOCON1_PENL_MASK;
}

void MCPWM_ChannelPinsOwnershipDisable(MCPWM_CH_NUM channel)
{
    *(&IOCON1 + (0x40U * (channel))) &= ~(_IOCON1_PENH_MASK | _IOCON1_PENL_MASK);
}



void __attribute__((used)) PWM1_InterruptHandler(void)
{
    uint32_t tmp;
    uintptr_t context = mcpwmObj[0].context;
    uint32_t status = PWMCON1 & MCPWM_STATUS_MASK;

    tmp = PWMCON1bits.PWMHIF;
    if (((PWMCON1bits.PWMHIEN) != 0U) && (tmp != 0U))
    {
        PWMCON1bits.PWMHIF = 0;
    }

    tmp = PWMCON1bits.PWMLIF;
    if (((PWMCON1bits.PWMLIEN) != 0U) && (tmp != 0U))
    {
        PWMCON1bits.PWMLIF = 0;
    }

    tmp = PWMCON1bits.TRGIF;
    if (((PWMCON1bits.TRGIEN) != 0U) && (tmp != 0U))
    {
        PWMCON1bits.TRGIF = 0;
    }

    tmp = PWMCON1bits.CLIF;
    if (((PWMCON1bits.CLIEN) != 0U) && (tmp != 0U))
    {
        PWMCON1bits.CLIEN = 0;
        PWMCON1bits.CLIF = 0;
    }

    tmp = PWMCON1bits.FLTIF;
    if (((PWMCON1bits.FLTIEN) != 0U) && (tmp != 0U))
    {
        PWMCON1bits.FLTIEN = 0;
        PWMCON1bits.FLTIF = 0;
    }

    IFS5CLR = _IFS5_PWM1IF_MASK;    //Clear IRQ flag

    PWMCON1bits.FLTIEN = 1;

    if( (mcpwmObj[0].callback != NULL))
    {
        mcpwmObj[0].callback((MCPWM_CH_STATUS)status, context);
    }
}

void __attribute__((used)) PWM7_InterruptHandler(void)
{
    uint32_t tmp;
    uintptr_t context = mcpwmObj[6].context;
    uint32_t status = PWMCON7 & MCPWM_STATUS_MASK;

    tmp = PWMCON7bits.PWMHIF;
    if (((PWMCON7bits.PWMHIEN) != 0U) && (tmp != 0U))
    {
        PWMCON7bits.PWMHIF = 0;
    }

    tmp = PWMCON7bits.PWMLIF;
    if (((PWMCON7bits.PWMLIEN) != 0U) && (tmp != 0U))
    {
        PWMCON7bits.PWMLIF = 0;
    }

    tmp = PWMCON7bits.TRGIF;
    if (((PWMCON7bits.TRGIEN) != 0U) && (tmp != 0U))
    {
        PWMCON7bits.TRGIF = 0;
    }

    tmp = PWMCON7bits.CLIF;
    if (((PWMCON7bits.CLIEN) != 0U) && (tmp != 0U))
    {
        PWMCON7bits.CLIEN = 0;
        PWMCON7bits.CLIF = 0;
    }

    tmp = PWMCON7bits.FLTIF;
    if (((PWMCON7bits.FLTIEN) != 0U) && (tmp != 0U))
    {
        PWMCON7bits.FLTIEN = 0;
        PWMCON7bits.FLTIF = 0;
    }

    IFS7CLR = _IFS7_PWM7IF_MASK;    //Clear IRQ flag

    PWMCON7bits.FLTIEN = 1;

    if( (mcpwmObj[6].callback != NULL))
    {
        mcpwmObj[6].callback((MCPWM_CH_STATUS)status, context);
    }
}

void __attribute__((used)) PWM10_InterruptHandler(void)
{
    uint32_t tmp;
    uintptr_t context = mcpwmObj[9].context;
    uint32_t status = PWMCON10 & MCPWM_STATUS_MASK;

    tmp = PWMCON10bits.PWMHIF;
    if (((PWMCON10bits.PWMHIEN) != 0U) && (tmp != 0U))
    {
        PWMCON10bits.PWMHIF = 0;
    }

    tmp = PWMCON10bits.PWMLIF;
    if (((PWMCON10bits.PWMLIEN) != 0U) && (tmp != 0U))
    {
        PWMCON10bits.PWMLIF = 0;
    }

    tmp = PWMCON10bits.TRGIF;
    if (((PWMCON10bits.TRGIEN) != 0U) && (tmp != 0U))
    {
        PWMCON10bits.TRGIF = 0;
    }

    tmp = PWMCON10bits.CLIF;
    if (((PWMCON10bits.CLIEN) != 0U) && (tmp != 0U))
    {
        PWMCON10bits.CLIEN = 0;
        PWMCON10bits.CLIF = 0;
    }

    tmp = PWMCON10bits.FLTIF;
    if (((PWMCON10bits.FLTIEN) != 0U) && (tmp != 0U))
    {
        PWMCON10bits.FLTIEN = 0;
        PWMCON10bits.FLTIF = 0;
    }

    IFS7CLR = _IFS7_PWM10IF_MASK;    //Clear IRQ flag

    PWMCON10bits.FLTIEN = 1;

    if( (mcpwmObj[9].callback != NULL))
    {
        mcpwmObj[9].callback((MCPWM_CH_STATUS)status, context);
    }
}


void MCPWM_CallbackRegister(MCPWM_CH_NUM channel, MCPWM_CH_CALLBACK callback, uintptr_t context)
{
    mcpwmObj[channel].callback = callback;
    mcpwmObj[channel].context = context;
}
