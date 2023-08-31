
/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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
// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "interrupts.h"
#include "plib_gic.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */
// *****************************************************************************
#define GIC_IRQ_CONFIG_LEVEL            0U
#define GIC_IRQ_CONFIG_EDGE             2U

#define GIC_IRQ_GROUP_SECURE            0U
#define GIC_IRQ_GROUP_NON_SECURE        1U

#define GIC_IRQ_TARGET_CPU0             1U

#define IAR_CPU_ID_Mask                 3U
#define IAR_CPU_ID_Pos                  10U
#define GET_IAR_CPU_ID(iarRegVal)       (((iarRegVal) & (IAR_CPU_ID_Mask)) >> IAR_CPU_ID_Pos)

#define IAR_INTERRUPT_ID_Mask           0x3FFU
#define IAR_INTERRUPT_ID_Pos            0x0U
#define GET_IAR_INTERRUPT_ID(iarRegVal) (((iarRegVal) & (IAR_INTERRUPT_ID_Mask)) >> IAR_INTERRUPT_ID_Pos)

#define TOTAL_SGI_INTERRUPTS            0x10U
#define MAX_SGI_INTERRUPT_ID            0x00FU
#define MAX_PPI_INTERRUPT_ID            0x01FU
#define MAX_SPI_INTERRUPT_ID            186U
#define SPURIOUS_INTERRUPT_ID           0x3FFU

void GIC_IRQHandler(uint32_t  iarRegVal);
void GIC_FIQHandler(uint32_t  iarRegVal);


volatile static PPI_SPI_HANDLER gicPIVectorTable[171U];
volatile static SGI_HANDLER gicSGIHandler;

static const struct {
    IRQn_Type irqID;
    PPI_SPI_HANDLER irqHandler;
    uint32_t  irqCfg;
    uint32_t  irqPriority;
    uint32_t  irqSecurity;
}gicIrqConfig[] =
{
    {FLEXCOM3_IRQn, FLEXCOM3_InterruptHandler, GIC_IRQ_CONFIG_LEVEL, 0, GIC_IRQ_GROUP_SECURE},
    {FLEXCOM9_IRQn, FLEXCOM9_InterruptHandler, GIC_IRQ_CONFIG_LEVEL, 0, GIC_IRQ_GROUP_SECURE},
    {GMAC0_IRQn, GMAC0_InterruptHandler, GIC_IRQ_CONFIG_LEVEL, 0, GIC_IRQ_GROUP_SECURE},
    {SDMMC1_IRQn, SDMMC1_InterruptHandler, GIC_IRQ_CONFIG_LEVEL, 0, GIC_IRQ_GROUP_SECURE},
    {TC0_CH0_IRQn, TC0_CH0_InterruptHandler, GIC_IRQ_CONFIG_LEVEL, 0, GIC_IRQ_GROUP_SECURE},
};

// *****************************************************************************
// *****************************************************************************
// Section: GIC Implementation
// *****************************************************************************
// *****************************************************************************
void GIC_IRQHandler(uint32_t  iarRegVal)
{
    uint32_t irqNum = GET_IAR_INTERRUPT_ID(iarRegVal);

    /* SGI interrupt, dispatch SGI handler if set */
    if (irqNum <= MAX_SGI_INTERRUPT_ID)
    {
        if(gicSGIHandler != NULL)
        {
            gicSGIHandler(irqNum, GET_IAR_CPU_ID(iarRegVal));
        }
    }
    /* Peripheral interrupt, dispatch peripheral handler if set */
    else if (irqNum <= MAX_SPI_INTERRUPT_ID)
    {
        PPI_SPI_HANDLER pHandler = gicPIVectorTable[ irqNum - TOTAL_SGI_INTERRUPTS];
        if(pHandler != NULL)
        {
            pHandler();
        }
    }
    else
    {
        /* Do nothing */
    }
}

void GIC_FIQHandler(uint32_t  iarRegVal)
{
    uint32_t irqNum = GET_IAR_INTERRUPT_ID(iarRegVal);

    /* SGI interrupt, dispatch SGI handler if set */
    if (irqNum <= MAX_SGI_INTERRUPT_ID)
    {
        if(gicSGIHandler != NULL)
        {
            gicSGIHandler(irqNum, GET_IAR_CPU_ID(iarRegVal));
        }
    }
    /* Peripheral interrupt, dispatch peripheral handler if set */
    else if (irqNum <= MAX_SPI_INTERRUPT_ID)
    {
        PPI_SPI_HANDLER pHandler = gicPIVectorTable[ irqNum - TOTAL_SGI_INTERRUPTS];
        if(pHandler != NULL)
        {
            pHandler();
        }
    }
    else
    {
        /* Do nothing */
    }
}

void __attribute__((used)) GIC_RegisterSGIInterruptHandler(SGI_HANDLER pHandler)
{
    gicSGIHandler = pHandler;
}


void __attribute__((used)) GIC_RegisterPeripheralInterruptHandler(IRQn_Type irqID, PPI_SPI_HANDLER pHandler)
{
    gicPIVectorTable[ (uint32_t)irqID - TOTAL_SGI_INTERRUPTS] = pHandler;
}


void GIC_Initialize(void)
{
    __disable_irq();

    GIC_Enable();

    uint32_t irqCount = sizeof(gicIrqConfig) / sizeof(gicIrqConfig[0]);

    for (uint32_t i = 0; i < irqCount; i++)
    {
        GIC_SetConfiguration(gicIrqConfig[i].irqID, gicIrqConfig[i].irqCfg);
        GIC_SetTarget(gicIrqConfig[i].irqID, GIC_IRQ_TARGET_CPU0);
        GIC_SetPriority(gicIrqConfig[i].irqID, gicIrqConfig[i].irqPriority);
        GIC_SetSecurity(gicIrqConfig[i].irqID, gicIrqConfig[i].irqSecurity);
        GIC_EnableIRQ (gicIrqConfig[i].irqID);
        gicPIVectorTable[(uint32_t)gicIrqConfig[i].irqID - TOTAL_SGI_INTERRUPTS] = gicIrqConfig[i].irqHandler;
    }

    __enable_irq();

}

void GIC_INT_IrqEnable(void)
{
    __DMB();
    __enable_irq();
}

bool GIC_INT_IrqDisable(void)
{
    /* Add a volatile qualifier to the return value to prevent the compiler from optimizing out this function */
    volatile bool previousValue = ((CPSR_I_Msk & __get_CPSR()) == 0U);
    __disable_irq();
    __DMB();
    return previousValue;
}

void GIC_INT_IrqRestore(bool state)
{
    if(state == true)
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