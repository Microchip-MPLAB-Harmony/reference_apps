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
#include "configuration.h"
#include "device_vectors.h"
#include "interrupts.h"
#include "definitions.h"



// *****************************************************************************
// *****************************************************************************
// Section: System Interrupt Vector Functions
// *****************************************************************************
// *****************************************************************************

/* MISRA C-2012 Rule 8.6 deviated below. Deviation record ID -  H3_MISRAC_2012_R_8_6_DR_1 */
extern uint32_t _stack;
extern const H3DeviceVectors exception_table;

extern void Dummy_Handler(void);

/* Brief default interrupt handler for unused IRQs.*/
void __attribute__((optimize("-O1"), long_call, noreturn, used))Dummy_Handler(void)
{
#if defined(__DEBUG) || defined(__DEBUG_D) && defined(__XC32)
    __builtin_software_breakpoint();
#endif
    while (true)
    {
    }
}

/* MISRAC 2012 deviation block start */
/* MISRA C-2012 Rule 8.6 deviated 6 times.  Deviation record ID -  H3_MISRAC_2012_R_8_6_DR_1 */
/* Device vectors list dummy definition*/
extern void SVCall_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PendSV_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SysTick_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void DMAC_2_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void DMAC_3_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void DMAC_OTHER_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));


/* MISRAC 2012 deviation block end */

/* Multiple handlers for vector */



__attribute__ ((section(".vectors"), used))
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
    .pfnRTC_Handler                = RTC_InterruptHandler,
    .pfnEIC_EXTINT_4_Handler       = EIC_EXTINT_4_InterruptHandler,
    .pfnEIC_EXTINT_6_Handler       = EIC_EXTINT_6_InterruptHandler,
    .pfnEIC_OTHER_Handler          = EIC_OTHER_InterruptHandler,
    .pfnDMAC_0_Handler             = DMAC_0_InterruptHandler,
    .pfnDMAC_1_Handler             = DMAC_1_InterruptHandler,
    .pfnDMAC_2_Handler             = DMAC_2_Handler,
    .pfnDMAC_3_Handler             = DMAC_3_Handler,
    .pfnDMAC_OTHER_Handler         = DMAC_OTHER_Handler,
    .pfnSERCOM0_0_Handler          = SERCOM0_SPI_InterruptHandler,
    .pfnSERCOM0_1_Handler          = SERCOM0_SPI_InterruptHandler,
    .pfnSERCOM0_2_Handler          = SERCOM0_SPI_InterruptHandler,
    .pfnSERCOM0_OTHER_Handler      = SERCOM0_SPI_InterruptHandler,
    .pfnSERCOM1_0_Handler          = SERCOM1_I2C_InterruptHandler,
    .pfnSERCOM1_1_Handler          = SERCOM1_I2C_InterruptHandler,
    .pfnSERCOM1_2_Handler          = SERCOM1_I2C_InterruptHandler,
    .pfnSERCOM1_OTHER_Handler      = SERCOM1_I2C_InterruptHandler,
    .pfnSERCOM3_0_Handler          = SERCOM3_USART_InterruptHandler,
    .pfnSERCOM3_1_Handler          = SERCOM3_USART_InterruptHandler,
    .pfnSERCOM3_2_Handler          = SERCOM3_USART_InterruptHandler,
    .pfnSERCOM3_OTHER_Handler      = SERCOM3_USART_InterruptHandler,
    .pfnSERCOM5_0_Handler          = SERCOM5_I2C_InterruptHandler,
    .pfnSERCOM5_1_Handler          = SERCOM5_I2C_InterruptHandler,
    .pfnSERCOM5_2_Handler          = SERCOM5_I2C_InterruptHandler,
    .pfnSERCOM5_OTHER_Handler      = SERCOM5_I2C_InterruptHandler,
    .pfnTC2_Handler                = TC2_TimerInterruptHandler,


};

/*******************************************************************************
 End of File
*/
