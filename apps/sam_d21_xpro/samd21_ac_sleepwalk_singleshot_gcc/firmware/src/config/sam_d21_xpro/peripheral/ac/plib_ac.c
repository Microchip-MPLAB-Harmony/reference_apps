/*******************************************************************************
  Analog Comparator PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_ac.c

  Summary:
    AC Source File

  Description:
    This file defines the interface to the AC peripheral library.
    This library provides access to and control of the associated
    Analog Comparator.

  Remarks:
    None.

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
#include "device.h"
#include "plib_ac.h"
#include "interrupts.h"

volatile static AC_OBJECT acObj;

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************

void AC_Initialize(void)
{
    /*Reset AC registers*/
    AC_REGS->AC_CTRLA = AC_CTRLA_SWRST_Msk;
    while((AC_REGS->AC_STATUSB & AC_STATUSB_SYNCBUSY_Msk) == AC_STATUSB_SYNCBUSY_Msk)
    {
        /* Wait for Synchronization */
    }

    /**************** Comparator 0 Configurations ************************/
    AC_REGS->AC_COMPCTRL[0] = AC_COMPCTRL_MUXPOS_PIN0 | AC_COMPCTRL_MUXNEG_BANDGAP | AC_COMPCTRL_INTSEL_EOC | AC_COMPCTRL_OUT_OFF | AC_COMPCTRL_SPEED(0U) | AC_COMPCTRL_FLEN_OFF | AC_COMPCTRL_SINGLE_Msk;
    AC_REGS->AC_COMPCTRL[0] |= AC_COMPCTRL_ENABLE_Msk;
    AC_REGS->AC_SCALER[0] = 0U;

    AC_REGS->AC_EVCTRL =  AC_EVCTRL_COMPEI0_Msk;
    AC_REGS->AC_INTENSET =  AC_INTENSET_COMP0_Msk;
    AC_REGS->AC_CTRLA = AC_CTRLA_RUNSTDBY_Msk;

    AC_REGS->AC_CTRLA |= AC_CTRLA_ENABLE_Msk;
    while((AC_REGS->AC_STATUSB & AC_STATUSB_SYNCBUSY_Msk) == AC_STATUSB_SYNCBUSY_Msk)
    {
        /* Wait for Synchronization */
    }    
}

void AC_Start( AC_CHANNEL channel_id )
{
    /* Start Comparison */
    AC_REGS->AC_CTRLB |= (1U << (uint8_t)channel_id);
}

void AC_SetVddScalar( AC_CHANNEL channel_id , uint8_t vdd_scalar)
{
    AC_REGS->AC_SCALER[channel_id] = vdd_scalar;
}

void AC_SwapInputs( AC_CHANNEL channel_id )
{
    /* Disable comparator before swapping */
    AC_REGS->AC_COMPCTRL[channel_id] &= ~AC_COMPCTRL_ENABLE_Msk;
    /* Check Synchronization to ensure that the comparator is disabled */
    while((AC_REGS->AC_STATUSB & AC_STATUSB_SYNCBUSY_Msk) == AC_STATUSB_SYNCBUSY_Msk)
    {
        /* Wait for Synchronization */
    }
    /* Swap inputs of the given comparator */
    AC_REGS->AC_COMPCTRL[channel_id] |= AC_COMPCTRL_SWAP_Msk;
    AC_REGS->AC_COMPCTRL[channel_id] |= AC_COMPCTRL_ENABLE_Msk;
    while((AC_REGS->AC_STATUSB & AC_STATUSB_SYNCBUSY_Msk) == AC_STATUSB_SYNCBUSY_Msk)
    {
        /* Wait for Synchronization */
    }    
}

void AC_ChannelSelect( AC_CHANNEL channel_id , AC_POSINPUT positiveInput, AC_NEGINPUT negativeInput)
{
    /* Disable comparator before swapping */
    AC_REGS->AC_COMPCTRL[channel_id] &= ~AC_COMPCTRL_ENABLE_Msk;
    /* Check Synchronization to ensure that the comparator is disabled */
    while((AC_REGS->AC_STATUSB & AC_STATUSB_SYNCBUSY_Msk) == AC_STATUSB_SYNCBUSY_Msk)
    {
        /* Wait for Synchronization */
    }
    AC_REGS->AC_COMPCTRL[channel_id] &= ~(AC_COMPCTRL_MUXPOS_Msk | AC_COMPCTRL_MUXNEG_Msk);
    AC_REGS->AC_COMPCTRL[channel_id] |= ((uint32_t)positiveInput | (uint32_t)negativeInput);

    /* Enable comparator channel */
    AC_REGS->AC_COMPCTRL[channel_id] |= AC_COMPCTRL_ENABLE_Msk;
    while((AC_REGS->AC_STATUSB & AC_STATUSB_SYNCBUSY_Msk) == AC_STATUSB_SYNCBUSY_Msk)
    {
        /* Wait for Synchronization */
    }

}

bool AC_StatusGet (AC_CHANNEL channel)
{
    bool breturnVal = false;

    if((AC_REGS->AC_STATUSB & (AC_STATUSB_READY0_Msk << (uint8_t)channel)) == (AC_STATUSB_READY0_Msk << (uint8_t)channel))
    {
        if((AC_REGS->AC_STATUSA & (AC_STATUSA_STATE0_Msk << (uint8_t)channel)) == (AC_STATUSA_STATE0_Msk << (uint8_t)channel))
        {
            breturnVal = true;
        }
        else
        {
            breturnVal = false;
        }
    }

    return breturnVal;
}

void AC_CallbackRegister (AC_CALLBACK callback, uintptr_t context)
{
    acObj.callback = callback;
    acObj.context = context;
}

void __attribute__((used)) AC_InterruptHandler( void )
{
    /* Additional local variable to prevent MISRA C violations (Rule 13.x) */
    uintptr_t context;
    uint8_t status;
    context = acObj.context;      
    /* Copy the status to use inside the callback */
    acObj.int_flags = AC_REGS->AC_STATUSA;
    status = acObj.int_flags;
    /* Clear the interrupt flags*/
    AC_REGS->AC_INTFLAG = AC_INTFLAG_Msk;

    /* Callback user function */
    if(acObj.callback != NULL)
    {
        acObj.callback(status, context);
    }
}
