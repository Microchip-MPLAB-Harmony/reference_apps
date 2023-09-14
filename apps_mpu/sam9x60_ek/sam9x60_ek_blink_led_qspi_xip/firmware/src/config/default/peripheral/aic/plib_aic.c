/*******************************************************************************
  AIC PLIB Implementation

  Company:
    Microchip Technology Inc.

  File Name:
    plib_aic.h

  Summary:
    Function implementations for the AIC PLIB.

  Description:
    This PLIB provides a simple interface to configure the Advanced Interrupt
    Controller.

*******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END
#include <device.h>
#include "definitions.h"
#include "interrupts.h"

// *****************************************************************************
// *****************************************************************************
// Section: Local defines
// *****************************************************************************
// *****************************************************************************

typedef void (*pfn_handler_t)(void);

// *****************************************************************************
// *****************************************************************************
// Section: Local Variables
// *****************************************************************************
// *****************************************************************************
/* data for irq register initialization */
static struct
{
    uint32_t        peripheralId;
    pfn_handler_t   handler;
    uint32_t        srcType;
    uint32_t        priority;
}irqData[] =
{
    { 47U, DBGU_InterruptHandler,      AIC_SMR_SRCTYPE_INT_LEVEL_SENSITIVE_Val,  0x0U },
};

// *****************************************************************************
// *****************************************************************************
// Section: AIC Implementation
// *****************************************************************************
// *****************************************************************************

void AIC_INT_Initialize( void )
{
    const uint32_t MaxNumPeripherals = 50U;
    const uint32_t MaxInterruptDepth = 8U;
    uint32_t ii;
    uint32_t irqDataEntryCount = sizeof(irqData) / sizeof(irqData[0]);

    __disable_irq();
    __DMB();
    __ISB();

    /* Disable all interrupts */
    for( ii= 0; ii < MaxNumPeripherals; ++ii )
    {
        AIC_REGS->AIC_SSR = AIC_SSR_INTSEL(ii);
        AIC_REGS->AIC_IDCR = AIC_IDCR_Msk;
        AIC_REGS->AIC_FFDR = AIC_FFDR_Msk;
        AIC_REGS->AIC_SVRRDR = AIC_SVRRDR_Msk;
        __DSB();
        __ISB();
        AIC_REGS->AIC_ICCR = AIC_ICCR_INTCLR_Msk;
    }

    /* pop all possible nested interrupts from internal hw stack */
    for( ii = 0; ii < MaxInterruptDepth; ++ii )
    {
        AIC_REGS->AIC_EOICR = AIC_EOICR_ENDIT_Msk;
    }

    /* Configure active interrupts */
    for( ii = 0; ii < irqDataEntryCount; ++ii )
    {
        AIC_REGS->AIC_SSR = AIC_SSR_INTSEL(irqData[ii].peripheralId);
        AIC_REGS->AIC_SMR = (AIC_REGS->AIC_SMR & ~AIC_SMR_SRCTYPE_Msk) | AIC_SMR_SRCTYPE( irqData[ii].srcType );
        AIC_REGS->AIC_SMR = (AIC_REGS->AIC_SMR & ~AIC_SMR_PRIOR_Msk) | AIC_SMR_PRIOR(irqData[ii].priority);
        AIC_REGS->AIC_SPU = (uint32_t) SPURIOUS_INTERRUPT_Handler;
        AIC_REGS->AIC_SVR = (uint32_t) irqData[ii].handler;
        AIC_REGS->AIC_IECR = AIC_IECR_Msk;
    }

    __DSB();
    __enable_irq();
    __ISB();
}

void AIC_INT_IrqEnable( void )
{
    __DMB();
    __enable_irq();
}

bool AIC_INT_IrqDisable( void )
{
    /* Add a volatile qualifier to the return value to prevent the compiler from optimizing out this function */
    volatile bool previousValue = ((CPSR_I_Msk & __get_CPSR()) == 0U);
    __disable_irq();
    __DMB();
    return( previousValue );
}

void AIC_INT_IrqRestore( bool state )
{
    if(state)
    {
        __DMB();
        __enable_irq();
    }
    else
    {
        __disable_irq();
        __DMB();
    }
}
