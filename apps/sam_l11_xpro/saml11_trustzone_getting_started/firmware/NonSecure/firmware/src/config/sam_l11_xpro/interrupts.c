/*******************************************************************************
 System Interrupts File

  Company:
    Microchip Technology Inc.

  File Name:
    interrupt.c

  Summary:
    Interrupt vectors mapping

  Description:
    This file maps all the interrupt vectors to their corresponding
    implementations. If a particular module interrupt is used, then its ISR
    definition can be found in corresponding PLIB source file. If a module
    interrupt is not used, then its ISR implementation is mapped to dummy
    handler.
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

#include "device_vectors.h"
#include "interrupts.h"
#include "definitions.h"


// *****************************************************************************
// *****************************************************************************
// Section: System Interrupt Vector Functions
// *****************************************************************************
// *****************************************************************************

extern uint32_t _stack;
extern const H3DeviceVectors exception_table;

extern void Dummy_Handler(void);

/* Brief default interrupt handler for unused IRQs.*/
void __attribute__((optimize("-O1"),section(".text.Dummy_Handler"),long_call, noreturn))Dummy_Handler(void)
{
#if defined(__DEBUG) || defined(__DEBUG_D) && defined(__XC32)
    __builtin_software_breakpoint();
#endif
    while (true)
    {
    }
}
/* Device vectors list dummy definition*/
extern void SVCall_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PendSV_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SysTick_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));



/* Multiple handlers for vector */



__attribute__ ((section(".vectors")))
const H3DeviceVectors exception_table=
{
    /* Configure Initial Stack Pointer, using linker-generated symbols */
    .pvStack = &_stack,

    .pfnReset_Handler              = Reset_Handler,
    .pfnNonMaskableInt_Handler     = NonMaskableInt_Handler,
    .pfnHardFault_Handler          = HardFault_Handler,
    .pfnSVCall_Handler             = SVCall_Handler,
    .pfnPendSV_Handler             = PendSV_Handler,
    .pfnSysTick_Handler            = SysTick_Handler,
    .pfnDMAC_0_Handler             = DMAC_0_InterruptHandler,
    .pfnDMAC_1_Handler             = DMAC_1_InterruptHandler,
    .pfnDMAC_2_Handler             = DMAC_2_InterruptHandler,
    .pfnDMAC_3_Handler             = DMAC_3_InterruptHandler,
    .pfnDMAC_OTHER_Handler         = DMAC_OTHER_InterruptHandler,
    .pfnSERCOM0_0_Handler          = SERCOM0_USART_InterruptHandler,
    .pfnSERCOM0_1_Handler          = SERCOM0_USART_InterruptHandler,
    .pfnSERCOM0_2_Handler          = SERCOM0_USART_InterruptHandler,
    .pfnSERCOM0_OTHER_Handler      = SERCOM0_USART_InterruptHandler,


};

/*******************************************************************************
 End of File
*/
