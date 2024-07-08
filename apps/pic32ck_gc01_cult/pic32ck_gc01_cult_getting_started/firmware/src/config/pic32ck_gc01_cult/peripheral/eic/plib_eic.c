/*******************************************************************************
  External Interrupt Controller (EIC) PLIB

  Company
    Microchip Technology Inc.

  File Name
    plib_eic.c

  Summary
    Source for EIC peripheral library interface Implementation.

  Description
    This file defines the interface to the EIC peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/* This section lists the other files that are included in this file.
*/

#include "plib_eic.h"
#include "interrupts.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************

/* EIC Channel Callback object */
volatile static EIC_CALLBACK_OBJ    eicCallbackObject[EXTINT_COUNT];

/* EIC NMI Callback object */
EIC_NMI_CALLBACK_OBJ eicNMICallbackObject;


void EIC_Initialize (void)
{
    /* Reset all registers in the EIC module to their initial state and
       EIC will be disabled. */
    EIC_REGS->EIC_CTRLA |= EIC_CTRLA_SWRST_Msk;

    while((EIC_REGS->EIC_SYNCBUSY & EIC_SYNCBUSY_SWRST_Msk) == EIC_SYNCBUSY_SWRST_Msk)
    {
        /* Wait for sync */
    }

    /* EIC is clocked by ultra low power clock */
    EIC_REGS->EIC_CTRLA |= EIC_CTRLA_CKSEL_Msk;

    /* NMI Control register */
    EIC_REGS->EIC_NMICTRL = EIC_NMICTRL_NMIASYNCH(1) | EIC_NMICTRL_NMISENSE_RISE | EIC_NMICTRL_NMIFILTEN_Msk;

    /* Interrupt sense type and filter control for EXTINT channels 0 to (16-1) */
    EIC_REGS->EIC_CONFIG0 =  EIC_CONFIG0_SENSE0_NONE 
        | EIC_CONFIG0_SENSE1_NONE 
        | EIC_CONFIG0_SENSE2_NONE 
        | EIC_CONFIG0_SENSE3_NONE 
        | EIC_CONFIG0_SENSE4_NONE 
        | EIC_CONFIG0_SENSE5_NONE 
        | EIC_CONFIG0_SENSE6_NONE 
        | EIC_CONFIG0_SENSE7_NONE ;

    EIC_REGS->EIC_CONFIG1 =  EIC_CONFIG1_SENSE8_NONE 
        | EIC_CONFIG1_SENSE9_NONE 
        | EIC_CONFIG1_SENSE10_RISE | EIC_CONFIG1_FILTEN10_Msk
        | EIC_CONFIG1_SENSE11_NONE 
        | EIC_CONFIG1_SENSE12_NONE 
        | EIC_CONFIG1_SENSE13_NONE 
        | EIC_CONFIG1_SENSE14_NONE 
        | EIC_CONFIG1_SENSE15_NONE ;

    /* External Interrupt Asynchronous Mode enable */
    EIC_REGS->EIC_ASYNCH = 0x400;

    /* Debouncer enable */
    EIC_REGS->EIC_DEBOUNCEN = 0x400;


    /* Debouncer Setting */
    EIC_REGS->EIC_DPRESCALER = EIC_DPRESCALER_PRESCALER0(0) | EIC_DPRESCALER_PRESCALER1(0) ;

    /* External Interrupt enable*/
    EIC_REGS->EIC_INTENSET = 0x400;
    /* Callbacks for enabled interrupts */
    eicCallbackObject[0].eicPinNo = EIC_PIN_MAX;
    eicCallbackObject[1].eicPinNo = EIC_PIN_MAX;
    eicCallbackObject[2].eicPinNo = EIC_PIN_MAX;
    eicCallbackObject[3].eicPinNo = EIC_PIN_MAX;
    eicCallbackObject[4].eicPinNo = EIC_PIN_MAX;
    eicCallbackObject[5].eicPinNo = EIC_PIN_MAX;
    eicCallbackObject[6].eicPinNo = EIC_PIN_MAX;
    eicCallbackObject[7].eicPinNo = EIC_PIN_MAX;
    eicCallbackObject[8].eicPinNo = EIC_PIN_MAX;
    eicCallbackObject[9].eicPinNo = EIC_PIN_MAX;
    eicCallbackObject[10].eicPinNo = EIC_PIN_10;
    eicCallbackObject[11].eicPinNo = EIC_PIN_MAX;
    eicCallbackObject[12].eicPinNo = EIC_PIN_MAX;
    eicCallbackObject[13].eicPinNo = EIC_PIN_MAX;
    eicCallbackObject[14].eicPinNo = EIC_PIN_MAX;
    eicCallbackObject[15].eicPinNo = EIC_PIN_MAX;

    /* Enable the EIC */
    EIC_REGS->EIC_CTRLA |= EIC_CTRLA_ENABLE_Msk;

    while((EIC_REGS->EIC_SYNCBUSY & EIC_SYNCBUSY_ENABLE_Msk) == EIC_SYNCBUSY_ENABLE_Msk)
    {
        /* Wait for sync */
    }
}

void EIC_InterruptEnable (EIC_PIN pin)
{
    EIC_REGS->EIC_INTENSET = (1UL << (uint32_t)pin);
}

void EIC_InterruptDisable (EIC_PIN pin)
{
    EIC_REGS->EIC_INTENCLR = (1UL << (uint32_t)pin);
}

void EIC_CallbackRegister(EIC_PIN pin, EIC_CALLBACK callback, uintptr_t context)
{
    if (eicCallbackObject[pin].eicPinNo == pin)
    {
        eicCallbackObject[pin].callback = callback;

        eicCallbackObject[pin].context  = context;
    }
}

void EIC_NMICallbackRegister(EIC_NMI_CALLBACK callback, uintptr_t context)
{
    eicNMICallbackObject.callback = callback;

    eicNMICallbackObject.context  = context;
}

void __attribute__((used)) EIC_EXTINT_10_InterruptHandler(void)
{
    /* Clear interrupt flag */
    EIC_REGS->EIC_INTFLAG = (1UL << 10);
    (void)EIC_REGS->EIC_INTFLAG;
    /* Find any associated callback entries in the callback table */
    if ((eicCallbackObject[10].callback != NULL))
    {
        uintptr_t context = eicCallbackObject[10].context;
        eicCallbackObject[10].callback(context);
    }

}

void __attribute__((used)) NMI_InterruptHandler(void)
{
    /* Find the triggered, run associated callback handlers */
    if ((EIC_REGS->EIC_NMIFLAG & EIC_NMIFLAG_NMI_Msk) == EIC_NMIFLAG_NMI_Msk)
    {
        /* Clear flag */
        EIC_REGS->EIC_NMIFLAG = EIC_NMIFLAG_NMI_Msk;

        /* Find any associated callback entries in the callback table */
        if (eicNMICallbackObject.callback != NULL)
        {
            uintptr_t context = eicNMICallbackObject.context;
            eicNMICallbackObject.callback(context);
        }
    }
}
