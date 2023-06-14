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
/* MISRA C-2012 Rule 8.6 deviated 206 times.  Deviation record ID -  H3_MISRAC_2012_R_8_6_DR_1 */
/* Device vectors list dummy definition*/
extern void SVCall_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PendSV_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SysTick_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void FCW_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void FCR_ECCERR_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void FCR_CRC_FAULT_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PM_Handler                 ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SUPC_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void OSCCTRL_FAIL_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void OSCCTRL_XOSCRDY_Handler    ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void OSCCTRL_DFLLRDY_Handler    ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void OSCCTRL_OTHER_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void OSCCTRL_LOCK_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void OSC32KCTRL_FAIL_Handler    ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void OSC32KCTRL_RDY_Handler     ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void MCLK_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void FREQM_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void WDT_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_0_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_1_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_2_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_3_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_4_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_5_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_6_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_9_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_10_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_11_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_12_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_13_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_14_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_15_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PAC_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void DRMTCM_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void MCRAMC_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TRAM_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_0_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_1_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_2_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_3_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_4_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_5_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_6_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_7_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_8_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_9_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_10_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_11_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM1_6_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM1_5_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM1_0_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM1_1_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM1_2_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM1_3_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM1_4_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM2_6_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM2_5_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM2_0_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM2_1_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM2_2_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM2_3_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM2_4_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM3_6_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM3_5_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM3_0_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM3_1_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM3_2_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM3_3_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM3_4_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM4_6_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM4_5_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM4_0_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM4_1_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM4_2_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM4_3_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM4_4_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM5_6_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM5_5_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM5_0_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM5_1_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM5_2_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM5_3_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM5_4_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM6_6_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM6_5_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM6_0_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM6_1_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM6_2_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM6_3_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM6_4_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM7_6_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM7_5_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM7_0_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM7_1_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM7_2_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM7_3_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM7_4_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM8_6_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM8_5_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM8_0_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM8_1_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM8_2_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM8_3_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM8_4_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM9_6_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM9_5_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM9_0_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM9_1_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM9_2_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM9_3_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM9_4_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC0_OTHER_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC0_CNT_TRIG_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC0_MC0_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC0_MC1_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC0_MC2_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC0_MC3_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC0_MC4_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC0_MC5_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC0_MC6_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC0_MC7_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC1_OTHER_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC1_CNT_TRIG_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC1_MC0_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC1_MC1_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC1_MC2_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC1_MC3_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC1_MC4_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC1_MC5_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC1_MC6_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC1_MC7_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC2_OTHER_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC2_CNT_TRIG_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC2_MC0_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC2_MC1_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC2_MC2_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC2_MC3_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC2_MC4_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC2_MC5_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC3_OTHER_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC3_CNT_TRIG_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC3_MC0_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC3_MC1_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC4_OTHER_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC4_CNT_TRIG_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC4_MC0_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC4_MC1_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC5_OTHER_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC5_CNT_TRIG_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC5_MC0_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC5_MC1_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC6_OTHER_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC6_CNT_TRIG_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC6_MC0_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC6_MC1_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC7_OTHER_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC7_CNT_TRIG_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC7_MC0_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC7_MC1_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC8_OTHER_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC8_CNT_TRIG_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC8_MC0_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC8_MC1_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC9_OTHER_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC9_CNT_TRIG_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC9_MC0_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC9_MC1_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC9_MC2_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC9_MC3_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC9_MC4_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC9_MC5_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ADC_GLOBAL_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ADC_CORE1_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ADC_CORE2_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ADC_CORE3_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ADC_CORE4_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void AC_Handler                 ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PTC_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SPI_IXS0_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SPI_IXS1_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void CAN0_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void CAN1_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void CAN2_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void CAN3_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void CAN4_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void CAN5_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ETH_PRI_Q_0_Handler        ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ETH_PRI_Q_1_Handler        ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ETH_PRI_Q_2_Handler        ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ETH_PRI_Q_3_Handler        ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ETH_PRI_Q_4_Handler        ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ETH_PRI_Q_5_Handler        ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SQI0_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SQI1_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TRNG_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SDMMC0_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SDMMC1_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void USBHS0_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void USBHS1_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void HSM_TAMPER_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void HSM_TXINT_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void HSM_RXINT_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void MLB_GENERAL_Handler        ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void MLB_BUSREQ_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void CM7H_CTIIRQ_0_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void CM7H_CTIIRQ_1_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));


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
    .pfnMemoryManagement_Handler   = MemoryManagement_Handler,
    .pfnBusFault_Handler           = BusFault_Handler,
    .pfnUsageFault_Handler         = UsageFault_Handler,
    .pfnSVCall_Handler             = SVCall_Handler,
    .pfnDebugMonitor_Handler       = DebugMonitor_Handler,
    .pfnPendSV_Handler             = PendSV_Handler,
    .pfnSysTick_Handler            = SysTick_Handler,
    .pfnFCW_Handler                = FCW_Handler,
    .pfnFCR_ECCERR_Handler         = FCR_ECCERR_Handler,
    .pfnFCR_CRC_FAULT_Handler      = FCR_CRC_FAULT_Handler,
    .pfnPM_Handler                 = PM_Handler,
    .pfnSUPC_Handler               = SUPC_Handler,
    .pfnOSCCTRL_FAIL_Handler       = OSCCTRL_FAIL_Handler,
    .pfnOSCCTRL_XOSCRDY_Handler    = OSCCTRL_XOSCRDY_Handler,
    .pfnOSCCTRL_DFLLRDY_Handler    = OSCCTRL_DFLLRDY_Handler,
    .pfnOSCCTRL_OTHER_Handler      = OSCCTRL_OTHER_Handler,
    .pfnOSCCTRL_LOCK_Handler       = OSCCTRL_LOCK_Handler,
    .pfnOSC32KCTRL_FAIL_Handler    = OSC32KCTRL_FAIL_Handler,
    .pfnOSC32KCTRL_RDY_Handler     = OSC32KCTRL_RDY_Handler,
    .pfnMCLK_Handler               = MCLK_Handler,
    .pfnFREQM_Handler              = FREQM_Handler,
    .pfnWDT_Handler                = WDT_Handler,
    .pfnRTC_TAMPER_Handler         = RTC_InterruptHandler,
    .pfnRTC_OVF_Handler            = RTC_InterruptHandler,
    .pfnRTC_PERIOD_Handler         = RTC_InterruptHandler,
    .pfnRTC_COMPARE_Handler        = RTC_InterruptHandler,
    .pfnEIC_EXTINT_0_Handler       = EIC_EXTINT_0_Handler,
    .pfnEIC_EXTINT_1_Handler       = EIC_EXTINT_1_Handler,
    .pfnEIC_EXTINT_2_Handler       = EIC_EXTINT_2_Handler,
    .pfnEIC_EXTINT_3_Handler       = EIC_EXTINT_3_Handler,
    .pfnEIC_EXTINT_4_Handler       = EIC_EXTINT_4_Handler,
    .pfnEIC_EXTINT_5_Handler       = EIC_EXTINT_5_Handler,
    .pfnEIC_EXTINT_6_Handler       = EIC_EXTINT_6_Handler,
    .pfnEIC_EXTINT_7_Handler       = EIC_EXTINT_7_InterruptHandler,
    .pfnEIC_EXTINT_8_Handler       = EIC_EXTINT_8_InterruptHandler,
    .pfnEIC_EXTINT_9_Handler       = EIC_EXTINT_9_Handler,
    .pfnEIC_EXTINT_10_Handler      = EIC_EXTINT_10_Handler,
    .pfnEIC_EXTINT_11_Handler      = EIC_EXTINT_11_Handler,
    .pfnEIC_EXTINT_12_Handler      = EIC_EXTINT_12_Handler,
    .pfnEIC_EXTINT_13_Handler      = EIC_EXTINT_13_Handler,
    .pfnEIC_EXTINT_14_Handler      = EIC_EXTINT_14_Handler,
    .pfnEIC_EXTINT_15_Handler      = EIC_EXTINT_15_Handler,
    .pfnPAC_Handler                = PAC_Handler,
    .pfnDRMTCM_Handler             = DRMTCM_Handler,
    .pfnMCRAMC_Handler             = MCRAMC_Handler,
    .pfnTRAM_Handler               = TRAM_Handler,
    .pfnDMA_PRI3_Handler           = DMA_PRI3_InterruptHandler,
    .pfnDMA_PRI2_Handler           = DMA_PRI2_InterruptHandler,
    .pfnDMA_PRI1_Handler           = DMA_PRI1_InterruptHandler,
    .pfnDMA_PRI0_Handler           = DMA_PRI0_InterruptHandler,
    .pfnEVSYS_0_Handler            = EVSYS_0_Handler,
    .pfnEVSYS_1_Handler            = EVSYS_1_Handler,
    .pfnEVSYS_2_Handler            = EVSYS_2_Handler,
    .pfnEVSYS_3_Handler            = EVSYS_3_Handler,
    .pfnEVSYS_4_Handler            = EVSYS_4_Handler,
    .pfnEVSYS_5_Handler            = EVSYS_5_Handler,
    .pfnEVSYS_6_Handler            = EVSYS_6_Handler,
    .pfnEVSYS_7_Handler            = EVSYS_7_Handler,
    .pfnEVSYS_8_Handler            = EVSYS_8_Handler,
    .pfnEVSYS_9_Handler            = EVSYS_9_Handler,
    .pfnEVSYS_10_Handler           = EVSYS_10_Handler,
    .pfnEVSYS_11_Handler           = EVSYS_11_Handler,
    .pfnSERCOM0_6_Handler          = SERCOM0_I2C_InterruptHandler,
    .pfnSERCOM0_5_Handler          = SERCOM0_I2C_InterruptHandler,
    .pfnSERCOM0_0_Handler          = SERCOM0_I2C_InterruptHandler,
    .pfnSERCOM0_1_Handler          = SERCOM0_I2C_InterruptHandler,
    .pfnSERCOM0_2_Handler          = SERCOM0_I2C_InterruptHandler,
    .pfnSERCOM0_3_Handler          = SERCOM0_I2C_InterruptHandler,
    .pfnSERCOM0_4_Handler          = SERCOM0_I2C_InterruptHandler,
    .pfnSERCOM1_6_Handler          = SERCOM1_6_Handler,
    .pfnSERCOM1_5_Handler          = SERCOM1_5_Handler,
    .pfnSERCOM1_0_Handler          = SERCOM1_0_Handler,
    .pfnSERCOM1_1_Handler          = SERCOM1_1_Handler,
    .pfnSERCOM1_2_Handler          = SERCOM1_2_Handler,
    .pfnSERCOM1_3_Handler          = SERCOM1_3_Handler,
    .pfnSERCOM1_4_Handler          = SERCOM1_4_Handler,
    .pfnSERCOM2_6_Handler          = SERCOM2_6_Handler,
    .pfnSERCOM2_5_Handler          = SERCOM2_5_Handler,
    .pfnSERCOM2_0_Handler          = SERCOM2_0_Handler,
    .pfnSERCOM2_1_Handler          = SERCOM2_1_Handler,
    .pfnSERCOM2_2_Handler          = SERCOM2_2_Handler,
    .pfnSERCOM2_3_Handler          = SERCOM2_3_Handler,
    .pfnSERCOM2_4_Handler          = SERCOM2_4_Handler,
    .pfnSERCOM3_6_Handler          = SERCOM3_6_Handler,
    .pfnSERCOM3_5_Handler          = SERCOM3_5_Handler,
    .pfnSERCOM3_0_Handler          = SERCOM3_0_Handler,
    .pfnSERCOM3_1_Handler          = SERCOM3_1_Handler,
    .pfnSERCOM3_2_Handler          = SERCOM3_2_Handler,
    .pfnSERCOM3_3_Handler          = SERCOM3_3_Handler,
    .pfnSERCOM3_4_Handler          = SERCOM3_4_Handler,
    .pfnSERCOM4_6_Handler          = SERCOM4_6_Handler,
    .pfnSERCOM4_5_Handler          = SERCOM4_5_Handler,
    .pfnSERCOM4_0_Handler          = SERCOM4_0_Handler,
    .pfnSERCOM4_1_Handler          = SERCOM4_1_Handler,
    .pfnSERCOM4_2_Handler          = SERCOM4_2_Handler,
    .pfnSERCOM4_3_Handler          = SERCOM4_3_Handler,
    .pfnSERCOM4_4_Handler          = SERCOM4_4_Handler,
    .pfnSERCOM5_6_Handler          = SERCOM5_6_Handler,
    .pfnSERCOM5_5_Handler          = SERCOM5_5_Handler,
    .pfnSERCOM5_0_Handler          = SERCOM5_0_Handler,
    .pfnSERCOM5_1_Handler          = SERCOM5_1_Handler,
    .pfnSERCOM5_2_Handler          = SERCOM5_2_Handler,
    .pfnSERCOM5_3_Handler          = SERCOM5_3_Handler,
    .pfnSERCOM5_4_Handler          = SERCOM5_4_Handler,
    .pfnSERCOM6_6_Handler          = SERCOM6_6_Handler,
    .pfnSERCOM6_5_Handler          = SERCOM6_5_Handler,
    .pfnSERCOM6_0_Handler          = SERCOM6_0_Handler,
    .pfnSERCOM6_1_Handler          = SERCOM6_1_Handler,
    .pfnSERCOM6_2_Handler          = SERCOM6_2_Handler,
    .pfnSERCOM6_3_Handler          = SERCOM6_3_Handler,
    .pfnSERCOM6_4_Handler          = SERCOM6_4_Handler,
    .pfnSERCOM7_6_Handler          = SERCOM7_6_Handler,
    .pfnSERCOM7_5_Handler          = SERCOM7_5_Handler,
    .pfnSERCOM7_0_Handler          = SERCOM7_0_Handler,
    .pfnSERCOM7_1_Handler          = SERCOM7_1_Handler,
    .pfnSERCOM7_2_Handler          = SERCOM7_2_Handler,
    .pfnSERCOM7_3_Handler          = SERCOM7_3_Handler,
    .pfnSERCOM7_4_Handler          = SERCOM7_4_Handler,
    .pfnSERCOM8_6_Handler          = SERCOM8_6_Handler,
    .pfnSERCOM8_5_Handler          = SERCOM8_5_Handler,
    .pfnSERCOM8_0_Handler          = SERCOM8_0_Handler,
    .pfnSERCOM8_1_Handler          = SERCOM8_1_Handler,
    .pfnSERCOM8_2_Handler          = SERCOM8_2_Handler,
    .pfnSERCOM8_3_Handler          = SERCOM8_3_Handler,
    .pfnSERCOM8_4_Handler          = SERCOM8_4_Handler,
    .pfnSERCOM9_6_Handler          = SERCOM9_6_Handler,
    .pfnSERCOM9_5_Handler          = SERCOM9_5_Handler,
    .pfnSERCOM9_0_Handler          = SERCOM9_0_Handler,
    .pfnSERCOM9_1_Handler          = SERCOM9_1_Handler,
    .pfnSERCOM9_2_Handler          = SERCOM9_2_Handler,
    .pfnSERCOM9_3_Handler          = SERCOM9_3_Handler,
    .pfnSERCOM9_4_Handler          = SERCOM9_4_Handler,
    .pfnTCC0_OTHER_Handler         = TCC0_OTHER_Handler,
    .pfnTCC0_CNT_TRIG_Handler      = TCC0_CNT_TRIG_Handler,
    .pfnTCC0_MC0_Handler           = TCC0_MC0_Handler,
    .pfnTCC0_MC1_Handler           = TCC0_MC1_Handler,
    .pfnTCC0_MC2_Handler           = TCC0_MC2_Handler,
    .pfnTCC0_MC3_Handler           = TCC0_MC3_Handler,
    .pfnTCC0_MC4_Handler           = TCC0_MC4_Handler,
    .pfnTCC0_MC5_Handler           = TCC0_MC5_Handler,
    .pfnTCC0_MC6_Handler           = TCC0_MC6_Handler,
    .pfnTCC0_MC7_Handler           = TCC0_MC7_Handler,
    .pfnTCC1_OTHER_Handler         = TCC1_OTHER_Handler,
    .pfnTCC1_CNT_TRIG_Handler      = TCC1_CNT_TRIG_Handler,
    .pfnTCC1_MC0_Handler           = TCC1_MC0_Handler,
    .pfnTCC1_MC1_Handler           = TCC1_MC1_Handler,
    .pfnTCC1_MC2_Handler           = TCC1_MC2_Handler,
    .pfnTCC1_MC3_Handler           = TCC1_MC3_Handler,
    .pfnTCC1_MC4_Handler           = TCC1_MC4_Handler,
    .pfnTCC1_MC5_Handler           = TCC1_MC5_Handler,
    .pfnTCC1_MC6_Handler           = TCC1_MC6_Handler,
    .pfnTCC1_MC7_Handler           = TCC1_MC7_Handler,
    .pfnTCC2_OTHER_Handler         = TCC2_OTHER_Handler,
    .pfnTCC2_CNT_TRIG_Handler      = TCC2_CNT_TRIG_Handler,
    .pfnTCC2_MC0_Handler           = TCC2_MC0_Handler,
    .pfnTCC2_MC1_Handler           = TCC2_MC1_Handler,
    .pfnTCC2_MC2_Handler           = TCC2_MC2_Handler,
    .pfnTCC2_MC3_Handler           = TCC2_MC3_Handler,
    .pfnTCC2_MC4_Handler           = TCC2_MC4_Handler,
    .pfnTCC2_MC5_Handler           = TCC2_MC5_Handler,
    .pfnTCC3_OTHER_Handler         = TCC3_OTHER_Handler,
    .pfnTCC3_CNT_TRIG_Handler      = TCC3_CNT_TRIG_Handler,
    .pfnTCC3_MC0_Handler           = TCC3_MC0_Handler,
    .pfnTCC3_MC1_Handler           = TCC3_MC1_Handler,
    .pfnTCC4_OTHER_Handler         = TCC4_OTHER_Handler,
    .pfnTCC4_CNT_TRIG_Handler      = TCC4_CNT_TRIG_Handler,
    .pfnTCC4_MC0_Handler           = TCC4_MC0_Handler,
    .pfnTCC4_MC1_Handler           = TCC4_MC1_Handler,
    .pfnTCC5_OTHER_Handler         = TCC5_OTHER_Handler,
    .pfnTCC5_CNT_TRIG_Handler      = TCC5_CNT_TRIG_Handler,
    .pfnTCC5_MC0_Handler           = TCC5_MC0_Handler,
    .pfnTCC5_MC1_Handler           = TCC5_MC1_Handler,
    .pfnTCC6_OTHER_Handler         = TCC6_OTHER_Handler,
    .pfnTCC6_CNT_TRIG_Handler      = TCC6_CNT_TRIG_Handler,
    .pfnTCC6_MC0_Handler           = TCC6_MC0_Handler,
    .pfnTCC6_MC1_Handler           = TCC6_MC1_Handler,
    .pfnTCC7_OTHER_Handler         = TCC7_OTHER_Handler,
    .pfnTCC7_CNT_TRIG_Handler      = TCC7_CNT_TRIG_Handler,
    .pfnTCC7_MC0_Handler           = TCC7_MC0_Handler,
    .pfnTCC7_MC1_Handler           = TCC7_MC1_Handler,
    .pfnTCC8_OTHER_Handler         = TCC8_OTHER_Handler,
    .pfnTCC8_CNT_TRIG_Handler      = TCC8_CNT_TRIG_Handler,
    .pfnTCC8_MC0_Handler           = TCC8_MC0_Handler,
    .pfnTCC8_MC1_Handler           = TCC8_MC1_Handler,
    .pfnTCC9_OTHER_Handler         = TCC9_OTHER_Handler,
    .pfnTCC9_CNT_TRIG_Handler      = TCC9_CNT_TRIG_Handler,
    .pfnTCC9_MC0_Handler           = TCC9_MC0_Handler,
    .pfnTCC9_MC1_Handler           = TCC9_MC1_Handler,
    .pfnTCC9_MC2_Handler           = TCC9_MC2_Handler,
    .pfnTCC9_MC3_Handler           = TCC9_MC3_Handler,
    .pfnTCC9_MC4_Handler           = TCC9_MC4_Handler,
    .pfnTCC9_MC5_Handler           = TCC9_MC5_Handler,
    .pfnADC_GLOBAL_Handler         = ADC_GLOBAL_Handler,
    .pfnADC_CORE1_Handler          = ADC_CORE1_Handler,
    .pfnADC_CORE2_Handler          = ADC_CORE2_Handler,
    .pfnADC_CORE3_Handler          = ADC_CORE3_Handler,
    .pfnADC_CORE4_Handler          = ADC_CORE4_Handler,
    .pfnAC_Handler                 = AC_Handler,
    .pfnPTC_Handler                = PTC_Handler,
    .pfnSPI_IXS0_Handler           = SPI_IXS0_Handler,
    .pfnSPI_IXS1_Handler           = SPI_IXS1_Handler,
    .pfnCAN0_Handler               = CAN0_Handler,
    .pfnCAN1_Handler               = CAN1_Handler,
    .pfnCAN2_Handler               = CAN2_Handler,
    .pfnCAN3_Handler               = CAN3_Handler,
    .pfnCAN4_Handler               = CAN4_Handler,
    .pfnCAN5_Handler               = CAN5_Handler,
    .pfnETH_PRI_Q_0_Handler        = ETH_PRI_Q_0_Handler,
    .pfnETH_PRI_Q_1_Handler        = ETH_PRI_Q_1_Handler,
    .pfnETH_PRI_Q_2_Handler        = ETH_PRI_Q_2_Handler,
    .pfnETH_PRI_Q_3_Handler        = ETH_PRI_Q_3_Handler,
    .pfnETH_PRI_Q_4_Handler        = ETH_PRI_Q_4_Handler,
    .pfnETH_PRI_Q_5_Handler        = ETH_PRI_Q_5_Handler,
    .pfnSQI0_Handler               = SQI0_Handler,
    .pfnSQI1_Handler               = SQI1_Handler,
    .pfnTRNG_Handler               = TRNG_Handler,
    .pfnSDMMC0_Handler             = SDMMC0_Handler,
    .pfnSDMMC1_Handler             = SDMMC1_Handler,
    .pfnUSBHS0_Handler             = USBHS0_Handler,
    .pfnUSBHS1_Handler             = USBHS1_Handler,
    .pfnHSM_TAMPER_Handler         = HSM_TAMPER_Handler,
    .pfnHSM_TXINT_Handler          = HSM_TXINT_Handler,
    .pfnHSM_RXINT_Handler          = HSM_RXINT_Handler,
    .pfnMLB_GENERAL_Handler        = MLB_GENERAL_Handler,
    .pfnMLB_BUSREQ_Handler         = MLB_BUSREQ_Handler,
    .pfnCM7H_CTIIRQ_0_Handler      = CM7H_CTIIRQ_0_Handler,
    .pfnCM7H_CTIIRQ_1_Handler      = CM7H_CTIIRQ_1_Handler,


};

/*******************************************************************************
 End of File
*/
