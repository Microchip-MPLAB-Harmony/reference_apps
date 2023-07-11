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

#include "interrupts.h"
#include "definitions.h"


// *****************************************************************************
// *****************************************************************************
// Section: System Interrupt Vector Functions
// *****************************************************************************
// *****************************************************************************

/* Brief default interrupt handler for unused IRQs */
void __attribute__((optimize("-O1"),section(".text.DefaultInterruptHandler"),long_call, noreturn))DefaultInterruptHandler( void )
{
#if defined(__DEBUG) || defined(__DEBUG_D)
    asm("BKPT");
#endif
    while( true ){
    }
}
/*  Weak definitions for default handlers.  Users may override these with
    implementations of their own or provide alternate functions to the 
    interrupt controller.  PLIB implementations provide alternate functions, 
    with the name {periph}_InterruptHandler so as they will not collide with
    user {periph}_Handler definitions.
*/
void VirtMaint_Handler( void )           __attribute__((weak, alias("DefaultInterruptHandler")));
void HyperVTimer_Handler( void )         __attribute__((weak, alias("DefaultInterruptHandler")));
void VirtTimer_Handler( void )           __attribute__((weak, alias("DefaultInterruptHandler")));
void LegacynFIQ_Handler( void )          __attribute__((weak, alias("DefaultInterruptHandler")));
void SecPhysTimer_Handler( void )        __attribute__((weak, alias("DefaultInterruptHandler")));
void NonSecPhysTimer_Handler( void )     __attribute__((weak, alias("DefaultInterruptHandler")));
void LegacynIRQ_Handler( void )          __attribute__((weak, alias("DefaultInterruptHandler")));
void DWDT_SW_Handler( void )             __attribute__((weak, alias("DefaultInterruptHandler")));
void DWDT_NSW_Handler( void )            __attribute__((weak, alias("DefaultInterruptHandler")));
void DWDT_NSW_ALARM_Handler( void )      __attribute__((weak, alias("DefaultInterruptHandler")));
void SCKC_Handler( void )                __attribute__((weak, alias("DefaultInterruptHandler")));
void SHDWC_Handler( void )               __attribute__((weak, alias("DefaultInterruptHandler")));
void RSTC_Handler( void )                __attribute__((weak, alias("DefaultInterruptHandler")));
void RTC_Handler( void )                 __attribute__((weak, alias("DefaultInterruptHandler")));
void RTT_Handler( void )                 __attribute__((weak, alias("DefaultInterruptHandler")));
void PMC_Handler( void )                 __attribute__((weak, alias("DefaultInterruptHandler")));
void PIOA_Handler( void )                __attribute__((weak, alias("DefaultInterruptHandler")));
void PIOB_Handler( void )                __attribute__((weak, alias("DefaultInterruptHandler")));
void PIOC_Handler( void )                __attribute__((weak, alias("DefaultInterruptHandler")));
void PIOD_Handler( void )                __attribute__((weak, alias("DefaultInterruptHandler")));
void PIOE_Handler( void )                __attribute__((weak, alias("DefaultInterruptHandler")));
void SECUMOD_Handler( void )             __attribute__((weak, alias("DefaultInterruptHandler")));
void SECURAM_Handler( void )             __attribute__((weak, alias("DefaultInterruptHandler")));
void SFR_Handler( void )                 __attribute__((weak, alias("DefaultInterruptHandler")));
void HSMC_Handler( void )                __attribute__((weak, alias("DefaultInterruptHandler")));
void XDMAC0_Handler( void )              __attribute__((weak, alias("DefaultInterruptHandler")));
void XDMAC1_Handler( void )              __attribute__((weak, alias("DefaultInterruptHandler")));
void XDMAC2_Handler( void )              __attribute__((weak, alias("DefaultInterruptHandler")));
void ACC_Handler( void )                 __attribute__((weak, alias("DefaultInterruptHandler")));
void ADC_Handler( void )                 __attribute__((weak, alias("DefaultInterruptHandler")));
void AES_Handler( void )                 __attribute__((weak, alias("DefaultInterruptHandler")));
void ARM_Handler( void )                 __attribute__((weak, alias("DefaultInterruptHandler")));
void ASRC_Handler( void )                __attribute__((weak, alias("DefaultInterruptHandler")));
void CPKCC_Handler( void )               __attribute__((weak, alias("DefaultInterruptHandler")));
void CSI_Handler( void )                 __attribute__((weak, alias("DefaultInterruptHandler")));
void CSI2DC_Handler( void )              __attribute__((weak, alias("DefaultInterruptHandler")));
void FLEXCOM0_Handler( void )            __attribute__((weak, alias("DefaultInterruptHandler")));
void FLEXCOM1_Handler( void )            __attribute__((weak, alias("DefaultInterruptHandler")));
void FLEXCOM2_Handler( void )            __attribute__((weak, alias("DefaultInterruptHandler")));
void FLEXCOM3_Handler( void )            __attribute__((weak, alias("DefaultInterruptHandler")));
void FLEXCOM4_Handler( void )            __attribute__((weak, alias("DefaultInterruptHandler")));
void FLEXCOM5_Handler( void )            __attribute__((weak, alias("DefaultInterruptHandler")));
void FLEXCOM6_Handler( void )            __attribute__((weak, alias("DefaultInterruptHandler")));
void FLEXCOM7_Handler( void )            __attribute__((weak, alias("DefaultInterruptHandler")));
void FLEXCOM8_Handler( void )            __attribute__((weak, alias("DefaultInterruptHandler")));
void FLEXCOM9_Handler( void )            __attribute__((weak, alias("DefaultInterruptHandler")));
void FLEXCOM10_Handler( void )           __attribute__((weak, alias("DefaultInterruptHandler")));
void FLEXCOM11_Handler( void )           __attribute__((weak, alias("DefaultInterruptHandler")));
void GMAC0_Handler( void )               __attribute__((weak, alias("DefaultInterruptHandler")));
void GMAC1_Handler( void )               __attribute__((weak, alias("DefaultInterruptHandler")));
void GMAC0_TSU_Handler( void )           __attribute__((weak, alias("DefaultInterruptHandler")));
void GMAC1_TSU_Handler( void )           __attribute__((weak, alias("DefaultInterruptHandler")));
void ICM_Handler( void )                 __attribute__((weak, alias("DefaultInterruptHandler")));
void ISC_Handler( void )                 __attribute__((weak, alias("DefaultInterruptHandler")));
void I2SMCC0_Handler( void )             __attribute__((weak, alias("DefaultInterruptHandler")));
void I2SMCC1_Handler( void )             __attribute__((weak, alias("DefaultInterruptHandler")));
void MATRIX_Handler( void )              __attribute__((weak, alias("DefaultInterruptHandler")));
void MCAN0_INT0_Handler( void )          __attribute__((weak, alias("DefaultInterruptHandler")));
void MCAN1_INT0_Handler( void )          __attribute__((weak, alias("DefaultInterruptHandler")));
void MCAN2_INT0_Handler( void )          __attribute__((weak, alias("DefaultInterruptHandler")));
void MCAN3_INT0_Handler( void )          __attribute__((weak, alias("DefaultInterruptHandler")));
void MCAN4_INT0_Handler( void )          __attribute__((weak, alias("DefaultInterruptHandler")));
void MCAN5_INT0_Handler( void )          __attribute__((weak, alias("DefaultInterruptHandler")));
void OTPC_Handler( void )                __attribute__((weak, alias("DefaultInterruptHandler")));
void PDMC0_Handler( void )               __attribute__((weak, alias("DefaultInterruptHandler")));
void PDMC1_Handler( void )               __attribute__((weak, alias("DefaultInterruptHandler")));
void PIT64B0_Handler( void )             __attribute__((weak, alias("DefaultInterruptHandler")));
void PIT64B1_Handler( void )             __attribute__((weak, alias("DefaultInterruptHandler")));
void PIT64B2_Handler( void )             __attribute__((weak, alias("DefaultInterruptHandler")));
void PIT64B3_Handler( void )             __attribute__((weak, alias("DefaultInterruptHandler")));
void PIT64B4_Handler( void )             __attribute__((weak, alias("DefaultInterruptHandler")));
void PIT64B5_Handler( void )             __attribute__((weak, alias("DefaultInterruptHandler")));
void PWM_Handler( void )                 __attribute__((weak, alias("DefaultInterruptHandler")));
void QSPI0_Handler( void )               __attribute__((weak, alias("DefaultInterruptHandler")));
void QSPI1_Handler( void )               __attribute__((weak, alias("DefaultInterruptHandler")));
void SDMMC0_Handler( void )              __attribute__((weak, alias("DefaultInterruptHandler")));
void SDMMC1_Handler( void )              __attribute__((weak, alias("DefaultInterruptHandler")));
void SDMMC2_Handler( void )              __attribute__((weak, alias("DefaultInterruptHandler")));
void SHA_Handler( void )                 __attribute__((weak, alias("DefaultInterruptHandler")));
void SPDIFRX_Handler( void )             __attribute__((weak, alias("DefaultInterruptHandler")));
void SPDIFTX_Handler( void )             __attribute__((weak, alias("DefaultInterruptHandler")));
void SSC0_Handler( void )                __attribute__((weak, alias("DefaultInterruptHandler")));
void SSC1_Handler( void )                __attribute__((weak, alias("DefaultInterruptHandler")));
void TC0_CH0_Handler( void )             __attribute__((weak, alias("DefaultInterruptHandler")));
void TC0_CH1_Handler( void )             __attribute__((weak, alias("DefaultInterruptHandler")));
void TC0_CH2_Handler( void )             __attribute__((weak, alias("DefaultInterruptHandler")));
void TC1_CH0_Handler( void )             __attribute__((weak, alias("DefaultInterruptHandler")));
void TC1_CH1_Handler( void )             __attribute__((weak, alias("DefaultInterruptHandler")));
void TC1_CH2_Handler( void )             __attribute__((weak, alias("DefaultInterruptHandler")));
void TCPCA_Handler( void )               __attribute__((weak, alias("DefaultInterruptHandler")));
void TCPCB_Handler( void )               __attribute__((weak, alias("DefaultInterruptHandler")));
void TDES_Handler( void )                __attribute__((weak, alias("DefaultInterruptHandler")));
void TRNG_Handler( void )                __attribute__((weak, alias("DefaultInterruptHandler")));
void TZAESB_NS_Handler( void )           __attribute__((weak, alias("DefaultInterruptHandler")));
void TZAESB_NS_SINT_Handler( void )      __attribute__((weak, alias("DefaultInterruptHandler")));
void TZAESB_S_Handler( void )            __attribute__((weak, alias("DefaultInterruptHandler")));
void TZAESB_S_SINT_Handler( void )       __attribute__((weak, alias("DefaultInterruptHandler")));
void TZC_Handler( void )                 __attribute__((weak, alias("DefaultInterruptHandler")));
void TZPM_Handler( void )                __attribute__((weak, alias("DefaultInterruptHandler")));
void UDPHSA_Handler( void )              __attribute__((weak, alias("DefaultInterruptHandler")));
void UDPHSB_Handler( void )              __attribute__((weak, alias("DefaultInterruptHandler")));
void UHPHS_Handler( void )               __attribute__((weak, alias("DefaultInterruptHandler")));
void ARM_NPMUIRQ_Handler( void )         __attribute__((weak, alias("DefaultInterruptHandler")));
void ARM_NAXIERRIRQ_Handler( void )      __attribute__((weak, alias("DefaultInterruptHandler")));
void XDMAC0_SINT_Handler( void )         __attribute__((weak, alias("DefaultInterruptHandler")));
void XDMAC1_SINT_Handler( void )         __attribute__((weak, alias("DefaultInterruptHandler")));
void XDMAC2_SINT_Handler( void )         __attribute__((weak, alias("DefaultInterruptHandler")));
void AES_SINT_Handler( void )            __attribute__((weak, alias("DefaultInterruptHandler")));
void GMAC0_Q1_Handler( void )            __attribute__((weak, alias("DefaultInterruptHandler")));
void GMAC0_Q2_Handler( void )            __attribute__((weak, alias("DefaultInterruptHandler")));
void GMAC0_Q3_Handler( void )            __attribute__((weak, alias("DefaultInterruptHandler")));
void GMAC0_Q4_Handler( void )            __attribute__((weak, alias("DefaultInterruptHandler")));
void GMAC0_Q5_Handler( void )            __attribute__((weak, alias("DefaultInterruptHandler")));
void GMAC1_Q1_Handler( void )            __attribute__((weak, alias("DefaultInterruptHandler")));
void ICM_SINT_Handler( void )            __attribute__((weak, alias("DefaultInterruptHandler")));
void MCAN0_INT1_Handler( void )          __attribute__((weak, alias("DefaultInterruptHandler")));
void MCAN1_INT1_Handler( void )          __attribute__((weak, alias("DefaultInterruptHandler")));
void MCAN2_INT1_Handler( void )          __attribute__((weak, alias("DefaultInterruptHandler")));
void MCAN3_INT1_Handler( void )          __attribute__((weak, alias("DefaultInterruptHandler")));
void MCAN4_INT1_Handler( void )          __attribute__((weak, alias("DefaultInterruptHandler")));
void MCAN5_INT1_Handler( void )          __attribute__((weak, alias("DefaultInterruptHandler")));
void PIOA_SINT_Handler( void )           __attribute__((weak, alias("DefaultInterruptHandler")));
void PIOB_SINT_Handler( void )           __attribute__((weak, alias("DefaultInterruptHandler")));
void PIOC_SINT_Handler( void )           __attribute__((weak, alias("DefaultInterruptHandler")));
void PIOD_SINT_Handler( void )           __attribute__((weak, alias("DefaultInterruptHandler")));
void PIOE_SINT_Handler( void )           __attribute__((weak, alias("DefaultInterruptHandler")));
void PIT64B0_SINT_Handler( void )        __attribute__((weak, alias("DefaultInterruptHandler")));
void PIT64B1_SINT_Handler( void )        __attribute__((weak, alias("DefaultInterruptHandler")));
void PIT64B2_SINT_Handler( void )        __attribute__((weak, alias("DefaultInterruptHandler")));
void PIT64B3_SINT_Handler( void )        __attribute__((weak, alias("DefaultInterruptHandler")));
void PIT64B4_SINT_Handler( void )        __attribute__((weak, alias("DefaultInterruptHandler")));
void PIT64B5_SINT_Handler( void )        __attribute__((weak, alias("DefaultInterruptHandler")));
void SDMMC0_TIMER_Handler( void )        __attribute__((weak, alias("DefaultInterruptHandler")));
void SDMMC1_TIMER_Handler( void )        __attribute__((weak, alias("DefaultInterruptHandler")));
void SDMMC2_TIMER_Handler( void )        __attribute__((weak, alias("DefaultInterruptHandler")));
void SHA_SINT_Handler( void )            __attribute__((weak, alias("DefaultInterruptHandler")));
void TC0_SINT0_Handler( void )           __attribute__((weak, alias("DefaultInterruptHandler")));
void TC0_SINT1_Handler( void )           __attribute__((weak, alias("DefaultInterruptHandler")));
void TC0_SINT2_Handler( void )           __attribute__((weak, alias("DefaultInterruptHandler")));
void TC1_SINT0_Handler( void )           __attribute__((weak, alias("DefaultInterruptHandler")));
void TC1_SINT1_Handler( void )           __attribute__((weak, alias("DefaultInterruptHandler")));
void TC1_SINT2_Handler( void )           __attribute__((weak, alias("DefaultInterruptHandler")));
void TDES_SINT_Handler( void )           __attribute__((weak, alias("DefaultInterruptHandler")));
void TRNG_SINT_Handler( void )           __attribute__((weak, alias("DefaultInterruptHandler")));
void EIC_EXT_IRQ0_Handler( void )        __attribute__((weak, alias("DefaultInterruptHandler")));
void EIC_EXT_IRQ1_Handler( void )        __attribute__((weak, alias("DefaultInterruptHandler")));


/* Array of interrupt handlers indexed by its IRQn_Type IDs */

PPI_SPI_HANDLER gicPIVectorTable[171U] = 
{
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    VirtMaint_Handler,
    HyperVTimer_Handler,
    VirtTimer_Handler,
    LegacynFIQ_Handler,
    SecPhysTimer_Handler,
    NonSecPhysTimer_Handler,
    LegacynIRQ_Handler,
    DWDT_SW_Handler,
    DWDT_NSW_Handler,
    DWDT_NSW_ALARM_Handler,
    NULL,
    SCKC_Handler,
    SHDWC_Handler,
    RSTC_Handler,
    RTC_Handler,
    RTT_Handler,
    NULL,
    PMC_Handler,
    PIOA_Handler,
    PIOB_Handler,
    PIOC_Handler,
    PIOD_Handler,
    PIOE_Handler,
    NULL,
    SECUMOD_Handler,
    SECURAM_Handler,
    SFR_Handler,
    NULL,
    HSMC_Handler,
    XDMAC0_Handler,
    XDMAC1_Handler,
    XDMAC2_Handler,
    ACC_Handler,
    ADC_Handler,
    AES_Handler,
    NULL,
    ARM_Handler,
    ASRC_Handler,
    NULL,
    CPKCC_Handler,
    CSI_Handler,
    CSI2DC_Handler,
    NULL,
    NULL,
    NULL,
    FLEXCOM0_Handler,
    FLEXCOM1_Handler,
    FLEXCOM2_Handler,
    FLEXCOM3_Handler,
    FLEXCOM4_Handler,
    FLEXCOM5_Handler,
    FLEXCOM6_Handler,
    FLEXCOM7_Handler,
    FLEXCOM8_Handler,
    FLEXCOM9_Handler,
    FLEXCOM10_Handler,
    FLEXCOM11_Handler,
    NULL,
    GMAC0_Handler,
    GMAC1_Handler,
    GMAC0_TSU_Handler,
    GMAC1_TSU_Handler,
    ICM_Handler,
    ISC_Handler,
    I2SMCC0_Handler,
    I2SMCC1_Handler,
    NULL,
    MATRIX_Handler,
    MCAN0_INT0_Handler,
    MCAN1_INT0_Handler,
    MCAN2_INT0_Handler,
    MCAN3_INT0_Handler,
    MCAN4_INT0_Handler,
    MCAN5_INT0_Handler,
    OTPC_Handler,
    PDMC0_Handler,
    PDMC1_Handler,
    PIT64B0_Handler,
    PIT64B1_Handler,
    PIT64B2_Handler,
    PIT64B3_Handler,
    PIT64B4_Handler,
    PIT64B5_Handler,
    NULL,
    PWM_Handler,
    QSPI0_Handler,
    QSPI1_Handler,
    SDMMC0_Handler,
    SDMMC1_Handler,
    SDMMC2_Handler,
    SHA_Handler,
    SPDIFRX_Handler,
    SPDIFTX_Handler,
    SSC0_Handler,
    SSC1_Handler,
    TC0_CH0_Handler,
    TC0_CH1_Handler,
    TC0_CH2_Handler,
    TC1_CH0_Handler,
    TC1_CH1_Handler,
    TC1_CH2_Handler,
    TCPCA_Handler,
    TCPCB_Handler,
    TDES_Handler,
    TRNG_Handler,
    TZAESB_NS_Handler,
    TZAESB_NS_SINT_Handler,
    TZAESB_S_Handler,
    TZAESB_S_SINT_Handler,
    TZC_Handler,
    TZPM_Handler,
    UDPHSA_Handler,
    UDPHSB_Handler,
    UHPHS_Handler,
    NULL,
    NULL,
    NULL,
    ARM_NPMUIRQ_Handler,
    ARM_NAXIERRIRQ_Handler,
    XDMAC0_SINT_Handler,
    XDMAC1_SINT_Handler,
    XDMAC2_SINT_Handler,
    AES_SINT_Handler,
    GMAC0_Q1_Handler,
    GMAC0_Q2_Handler,
    GMAC0_Q3_Handler,
    GMAC0_Q4_Handler,
    GMAC0_Q5_Handler,
    GMAC1_Q1_Handler,
    ICM_SINT_Handler,
    MCAN0_INT1_Handler,
    MCAN1_INT1_Handler,
    MCAN2_INT1_Handler,
    MCAN3_INT1_Handler,
    MCAN4_INT1_Handler,
    MCAN5_INT1_Handler,
    PIOA_SINT_Handler,
    PIOB_SINT_Handler,
    PIOC_SINT_Handler,
    PIOD_SINT_Handler,
    PIOE_SINT_Handler,
    NULL,
    PIT64B0_SINT_Handler,
    PIT64B1_SINT_Handler,
    PIT64B2_SINT_Handler,
    PIT64B3_SINT_Handler,
    PIT64B4_SINT_Handler,
    PIT64B5_SINT_Handler,
    SDMMC0_TIMER_Handler,
    SDMMC1_TIMER_Handler,
    SDMMC2_TIMER_Handler,
    SHA_SINT_Handler,
    TC0_SINT0_Handler,
    TC0_SINT1_Handler,
    TC0_SINT2_Handler,
    TC1_SINT0_Handler,
    TC1_SINT1_Handler,
    TC1_SINT2_Handler,
    TDES_SINT_Handler,
    TRNG_SINT_Handler,
    EIC_EXT_IRQ0_Handler,
    EIC_EXT_IRQ1_Handler
};







/*******************************************************************************
 End of File
*/
