/*
 * Header file for PIC32CM5164JH01048
 *
 * Copyright (c) 2023 Microchip Technology Inc. and its subsidiaries.
 *
 * Subject to your compliance with these terms, you may use Microchip software and any derivatives
 * exclusively with Microchip products. It is your responsibility to comply with third party license
 * terms applicable to your use of third party software (including open source software) that may
 * accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY,
 * APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF
 * MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT
 * EXCEED THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/* File generated from device description version 2023-04-26T09:03:27Z */
#ifndef _PIC32CM5164JH01048_H_
#define _PIC32CM5164JH01048_H_

/* Header version uses Semantic Versioning 2.0.0 (https://semver.org/) */
#define HEADER_FORMAT_VERSION "2.1.0"

#define HEADER_FORMAT_VERSION_MAJOR (2)
#define HEADER_FORMAT_VERSION_MINOR (1)
#define HEADER_FORMAT_VERSION_PATCH (0)

/* PIC32CM5164JH01048 definitions
  This file defines all structures and symbols for PIC32CM5164JH01048:
    - registers and bitfields
    - peripheral base address
    - peripheral ID
    - PIO definitions
*/

#ifdef __cplusplus
 extern "C" {
#endif

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  include <stdint.h>
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !defined(SKIP_INTEGER_LITERALS)
#  if defined(_UINT8_) || defined(_UINT16_) || defined(_UINT32_)
#    error "Integer constant value macros already defined elsewhere"
#  endif

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* Macros that deal with sizes of integer constants for C/C++ */
#  define _UINT8_(x)   ((uint8_t)(x))    /* C code: 8-bits unsigned integer constant value */
#  define _UINT16_(x)  ((uint16_t)(x))   /* C code: 16-bits unsigned integer constant value */
#  define _UINT32_(x)  ((uint32_t)(x))   /* C code: 32-bits unsigned integer constant value */

#else /* Assembler */

#  define _UINT8_(x) x    /* Assembler: 8-bits unsigned integer constant value */
#  define _UINT16_(x) x   /* Assembler: 16-bits unsigned integer constant value */
#  define _UINT32_(x) x   /* Assembler: 32-bits unsigned integer constant value */
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* SKIP_INTEGER_LITERALS */

/* ************************************************************************** */
/* CMSIS DEFINITIONS FOR PIC32CM5164JH01048                                 */
/* ************************************************************************** */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* Interrupt Number Definition */
typedef enum IRQn
{
/******  CORTEX-M0PLUS Processor Exceptions Numbers ******************************/
  Reset_IRQn                = -15, /* -15 Reset Vector, invoked on Power up and warm reset */
  NonMaskableInt_IRQn       = -14, /* -14 Non maskable Interrupt, cannot be stopped or preempted */
  HardFault_IRQn            = -13, /* -13 Hard Fault, all classes of Fault    */
  SVCall_IRQn               =  -5, /* -5  System Service Call via SVC instruction */
  PendSV_IRQn               =  -2, /* -2  Pendable request for system service */
  SysTick_IRQn              =  -1, /* -1  System Tick Timer                   */

/******  PIC32CM5164JH01048 specific Interrupt Numbers ***********************************/
  MCLK_IRQn                 =   0, /* 0   Shared between MCLK OSCCTRL OSC32KCTRL PAC PM SUPC (MCLK) */
  OSC32KCTRL_IRQn           =   0, /* 0   Shared between MCLK OSCCTRL OSC32KCTRL PAC PM SUPC (OSC32KCTRL) */
  OSCCTRL_IRQn              =   0, /* 0   Shared between MCLK OSCCTRL OSC32KCTRL PAC PM SUPC (OSCCTRL) */
  PAC_IRQn                  =   0, /* 0   Shared between MCLK OSCCTRL OSC32KCTRL PAC PM SUPC (PAC) */
  PM_IRQn                   =   0, /* 0   Shared between MCLK OSCCTRL OSC32KCTRL PAC PM SUPC (PM) */
  SUPC_IRQn                 =   0, /* 0   Shared between MCLK OSCCTRL OSC32KCTRL PAC PM SUPC (SUPC) */
  WDT_IRQn                  =   1, /* 1   Watchdog Timer (WDT)                */
  RTC_IRQn                  =   2, /* 2   Real-Time Counter (RTC)             */
  EIC_IRQn                  =   3, /* 3   External Interrupt Controller (EIC) */
  FREQM_IRQn                =   4, /* 4   Frequency Meter (FREQM)             */
  MCRAMC_IRQn               =   5, /* 5   Multi-Channel RAM Controller (MCRAMC) */
  NVMCTRL_IRQn              =   6, /* 6   Non-Volatile Memory Controller (NVMCTRL) */
  DMAC_IRQn                 =   7, /* 7   Direct Memory Access Controller (DMAC) */
  EVSYS_IRQn                =   8, /* 8   Event System Interface (EVSYS)      */
  SERCOM0_IRQn              =   9, /* 9   Serial Communication Interface (SERCOM0) */
  SERCOM1_IRQn              =  10, /* 10  Serial Communication Interface (SERCOM1) */
  SERCOM2_IRQn              =  11, /* 11  Serial Communication Interface (SERCOM2) */
  SERCOM3_IRQn              =  12, /* 12  Serial Communication Interface (SERCOM3) */
  SERCOM4_IRQn              =  13, /* 13  Serial Communication Interface (SERCOM4) */
  SERCOM5_IRQn              =  14, /* 14  Serial Communication Interface (SERCOM5) */
  CAN0_IRQn                 =  15, /* 15  Control Area Network (CAN0)         */
  CAN1_IRQn                 =  16, /* 16  Control Area Network (CAN1)         */
  TCC0_IRQn                 =  17, /* 17  Timer Counter for Control Applications (TCC0) */
  TCC1_IRQn                 =  18, /* 18  Timer Counter for Control Applications (TCC1) */
  TCC2_IRQn                 =  19, /* 19  Timer Counter for Control Applications (TCC2) */
  TC0_IRQn                  =  20, /* 20  Shared between TC0 TC5 (TC0)        */
  TC5_IRQn                  =  20, /* 20  Shared between TC0 TC5 (TC5)        */
  TC1_IRQn                  =  21, /* 21  Shared between TC1 TC6 (TC1)        */
  TC6_IRQn                  =  21, /* 21  Shared between TC1 TC6 (TC6)        */
  TC2_IRQn                  =  22, /* 22  Shared between TC2 TC7 (TC2)        */
  TC7_IRQn                  =  22, /* 22  Shared between TC2 TC7 (TC7)        */
  TC3_IRQn                  =  23, /* 23  Basic Timer Counter (TC3)           */
  TC4_IRQn                  =  24, /* 24  Basic Timer Counter (TC4)           */
  ADC0_IRQn                 =  25, /* 25  Analog Digital Converter (ADC0)     */
  ADC1_IRQn                 =  26, /* 26  Analog Digital Converter (ADC1)     */
  AC_IRQn                   =  27, /* 27  Analog Comparators (AC)             */
  DAC_IRQn                  =  28, /* 28  Digital Analog Converter (DAC)      */
  PDEC_IRQn                 =  29, /* 29  Quadrature Decodeur (PDEC)          */
  PTC_IRQn                  =  30, /* 30  Peripheral Touch Controller (PTC)   */
  ICM_IRQn                  =  31, /* 31  Integrity Check Monitor (ICM)       */

  PERIPH_MAX_IRQn           =  31  /* Max peripheral ID */
} IRQn_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef struct _DeviceVectors
{
  /* Stack pointer */
  void* pvStack;
  /* CORTEX-M0PLUS handlers */
  void* pfnReset_Handler;                        /* -15 Reset Vector, invoked on Power up and warm reset */
  void* pfnNonMaskableInt_Handler;               /* -14 Non maskable Interrupt, cannot be stopped or preempted */
  void* pfnHardFault_Handler;                    /* -13 Hard Fault, all classes of Fault */
  void* pvReservedC12;
  void* pvReservedC11;
  void* pvReservedC10;
  void* pvReservedC9;
  void* pvReservedC8;
  void* pvReservedC7;
  void* pvReservedC6;
  void* pfnSVCall_Handler;                       /*  -5 System Service Call via SVC instruction */
  void* pvReservedC4;
  void* pvReservedC3;
  void* pfnPendSV_Handler;                       /*  -2 Pendable request for system service */
  void* pfnSysTick_Handler;                      /*  -1 System Tick Timer */

  /* Peripheral handlers */
  void* pfnSYSTEM_Handler;                       /*   0 System peripherals shared interrupt (MCLK OSCCTRL OSC32KCTRL PAC PM SUPC) */
  void* pfnWDT_Handler;                          /*   1 Watchdog Timer (WDT) */
  void* pfnRTC_Handler;                          /*   2 Real-Time Counter (RTC) */
  void* pfnEIC_Handler;                          /*   3 External Interrupt Controller (EIC) */
  void* pfnFREQM_Handler;                        /*   4 Frequency Meter (FREQM) */
  void* pfnMCRAMC_Handler;                       /*   5 Multi-Channel RAM Controller (MCRAMC) */
  void* pfnNVMCTRL_Handler;                      /*   6 Non-Volatile Memory Controller (NVMCTRL) */
  void* pfnDMAC_Handler;                         /*   7 Direct Memory Access Controller (DMAC) */
  void* pfnEVSYS_Handler;                        /*   8 Event System Interface (EVSYS) */
  void* pfnSERCOM0_Handler;                      /*   9 Serial Communication Interface (SERCOM0) */
  void* pfnSERCOM1_Handler;                      /*  10 Serial Communication Interface (SERCOM1) */
  void* pfnSERCOM2_Handler;                      /*  11 Serial Communication Interface (SERCOM2) */
  void* pfnSERCOM3_Handler;                      /*  12 Serial Communication Interface (SERCOM3) */
  void* pfnSERCOM4_Handler;                      /*  13 Serial Communication Interface (SERCOM4) */
  void* pfnSERCOM5_Handler;                      /*  14 Serial Communication Interface (SERCOM5) */
  void* pfnCAN0_Handler;                         /*  15 Control Area Network (CAN0) */
  void* pfnCAN1_Handler;                         /*  16 Control Area Network (CAN1) */
  void* pfnTCC0_Handler;                         /*  17 Timer Counter for Control Applications (TCC0) */
  void* pfnTCC1_Handler;                         /*  18 Timer Counter for Control Applications (TCC1) */
  void* pfnTCC2_Handler;                         /*  19 Timer Counter for Control Applications (TCC2) */
  void* pfnTC0_5_Handler;                        /*  20 Timer/Counter 0_5 (TC0 TC5) */
  void* pfnTC1_6_Handler;                        /*  21 Timer/Counter 1_6 (TC1 TC6) */
  void* pfnTC2_7_Handler;                        /*  22 Timer/Counter 2_7 (TC2 TC7) */
  void* pfnTC3_Handler;                          /*  23 Basic Timer Counter (TC3) */
  void* pfnTC4_Handler;                          /*  24 Basic Timer Counter (TC4) */
  void* pfnADC0_Handler;                         /*  25 Analog Digital Converter (ADC0) */
  void* pfnADC1_Handler;                         /*  26 Analog Digital Converter (ADC1) */
  void* pfnAC_Handler;                           /*  27 Analog Comparators (AC) */
  void* pfnDAC_Handler;                          /*  28 Digital Analog Converter (DAC) */
  void* pfnPDEC_Handler;                         /*  29 Quadrature Decodeur (PDEC) */
  void* pfnPTC_Handler;                          /*  30 Peripheral Touch Controller (PTC) */
  void* pfnICM_Handler;                          /*  31 Integrity Check Monitor (ICM) */
} DeviceVectors;

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if !defined DONT_USE_PREDEFINED_CORE_HANDLERS
/* CORTEX-M0PLUS exception handlers */
void Reset_Handler                 ( void );
void NonMaskableInt_Handler        ( void );
void HardFault_Handler             ( void );
void SVCall_Handler                ( void );
void PendSV_Handler                ( void );
void SysTick_Handler               ( void );
#endif /* DONT_USE_PREDEFINED_CORE_HANDLERS */

#if !defined DONT_USE_PREDEFINED_PERIPHERALS_HANDLERS
/* Peripherals interrupt handlers */
void SYSTEM_Handler                ( void );
void WDT_Handler                   ( void );
void RTC_Handler                   ( void );
void EIC_Handler                   ( void );
void FREQM_Handler                 ( void );
void MCRAMC_Handler                ( void );
void NVMCTRL_Handler               ( void );
void DMAC_Handler                  ( void );
void EVSYS_Handler                 ( void );
void SERCOM0_Handler               ( void );
void SERCOM1_Handler               ( void );
void SERCOM2_Handler               ( void );
void SERCOM3_Handler               ( void );
void SERCOM4_Handler               ( void );
void SERCOM5_Handler               ( void );
void CAN0_Handler                  ( void );
void CAN1_Handler                  ( void );
void TCC0_Handler                  ( void );
void TCC1_Handler                  ( void );
void TCC2_Handler                  ( void );
void TC0_5_Handler                 ( void );
void TC1_6_Handler                 ( void );
void TC2_7_Handler                 ( void );
void TC3_Handler                   ( void );
void TC4_Handler                   ( void );
void ADC0_Handler                  ( void );
void ADC1_Handler                  ( void );
void AC_Handler                    ( void );
void DAC_Handler                   ( void );
void PDEC_Handler                  ( void );
void PTC_Handler                   ( void );
void ICM_Handler                   ( void );
#endif /* DONT_USE_PREDEFINED_PERIPHERALS_HANDLERS */
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* Configuration of the CORTEX-M0PLUS Processor and Core Peripherals */
#define __MPU_PRESENT                      1 /* MPU present or not                                                        */
#define __NVIC_PRIO_BITS                   2 /* Number of Bits used for Priority Levels                                   */
#define __VTOR_PRESENT                     1 /* Vector Table Offset Register present or not                               */
#define __Vendor_SysTickConfig             0 /* Set to 1 if different SysTick Config is used                              */
#define __ARCH_ARM                         1
#define __ARCH_ARM_CORTEX_M                1

/* CMSIS includes */
#include "core_cm0plus.h"
#if defined USE_CMSIS_INIT
#include "system_pic32cmjh01.h"
#endif /* USE_CMSIS_INIT */

/* ************************************************************************** */
/*   SOFTWARE PERIPHERAL API DEFINITION FOR PIC32CM5164JH01048                */
/* ************************************************************************** */
#include "component/ac.h"
#include "component/adc.h"
#include "component/can.h"
#include "component/ccl.h"
#include "component/dac.h"
#include "component/divas.h"
#include "component/dmac.h"
#include "component/dsu.h"
#include "component/eic.h"
#include "component/evsys.h"
#include "component/freqm.h"
#include "component/fuses.h"
#include "component/gclk.h"
#include "component/icm.h"
#include "component/mclk.h"
#include "component/mcramc.h"
#include "component/mtb.h"
#include "component/nvmctrl.h"
#include "component/osc32kctrl.h"
#include "component/oscctrl.h"
#include "component/pac.h"
#include "component/pdec.h"
#include "component/pm.h"
#include "component/port.h"
#include "component/ptc.h"
#include "component/rstc.h"
#include "component/rtc.h"
#include "component/sercom.h"
#include "component/smbist.h"
#include "component/supc.h"
#include "component/tc.h"
#include "component/tcc.h"
#include "component/wdt.h"

/* ************************************************************************** */
/*   INSTANCE DEFINITIONS FOR PIC32CM5164JH01048 */
/* ************************************************************************** */
#include "instance/ac.h"
#include "instance/adc0.h"
#include "instance/adc1.h"
#include "instance/can0.h"
#include "instance/can1.h"
#include "instance/ccl.h"
#include "instance/dac.h"
#include "instance/divas.h"
#include "instance/dmac.h"
#include "instance/dsu.h"
#include "instance/eic.h"
#include "instance/evsys.h"
#include "instance/freqm.h"
#include "instance/fuses.h"
#include "instance/gclk.h"
#include "instance/icm.h"
#include "instance/mclk.h"
#include "instance/mcramc.h"
#include "instance/mtb.h"
#include "instance/nvmctrl.h"
#include "instance/osc32kctrl.h"
#include "instance/oscctrl.h"
#include "instance/pac.h"
#include "instance/pdec.h"
#include "instance/pm.h"
#include "instance/port.h"
#include "instance/ptc.h"
#include "instance/rstc.h"
#include "instance/rtc.h"
#include "instance/sercom0.h"
#include "instance/sercom1.h"
#include "instance/sercom2.h"
#include "instance/sercom3.h"
#include "instance/sercom4.h"
#include "instance/sercom5.h"
#include "instance/smbist.h"
#include "instance/supc.h"
#include "instance/tc0.h"
#include "instance/tc1.h"
#include "instance/tc2.h"
#include "instance/tc3.h"
#include "instance/tc4.h"
#include "instance/tc5.h"
#include "instance/tc6.h"
#include "instance/tc7.h"
#include "instance/tcc0.h"
#include "instance/tcc1.h"
#include "instance/tcc2.h"
#include "instance/wdt.h"

/* ************************************************************************** */
/*  PERIPHERAL ID DEFINITIONS FOR PIC32CM5164JH01048                          */
/* ************************************************************************** */
#define ID_PAC           (  0) /* Instance index for PAC (PAC) */
#define ID_PM            (  1) /* Instance index for PM (PM) */
#define ID_MCLK          (  2) /* Instance index for MCLK (MCLK) */
#define ID_RSTC          (  3) /* Instance index for RSTC (RSTC) */
#define ID_OSCCTRL       (  4) /* Instance index for OSCCTRL (OSCCTRL) */
#define ID_OSC32KCTRL    (  5) /* Instance index for OSC32KCTRL (OSC32KCTRL) */
#define ID_SUPC          (  6) /* Instance index for SUPC (SUPC) */
#define ID_GCLK          (  7) /* Instance index for GCLK (GCLK) */
#define ID_WDT           (  8) /* Instance index for WDT (WDT) */
#define ID_RTC           (  9) /* Instance index for RTC (RTC) */
#define ID_EIC           ( 10) /* Instance index for EIC (EIC) */
#define ID_FREQM         ( 11) /* Instance index for FREQM (FREQM) */
#define ID_MCRAMC        ( 12) /* Instance index for MCRAMC (MCRAMC) */
#define ID_PORT          ( 32) /* Instance index for PORT (PORT) */
#define ID_DSU           ( 33) /* Instance index for DSU (DSU) */
#define ID_NVMCTRL       ( 34) /* Instance index for NVMCTRL (NVMCTRL) */
#define ID_DMAC          ( 35) /* Instance index for DMAC (DMAC) */
#define ID_MTB           ( 36) /* Instance index for MTB (MTB) */
#define ID_EVSYS         ( 64) /* Instance index for EVSYS (EVSYS) */
#define ID_SERCOM0       ( 65) /* Instance index for SERCOM0 (SERCOM0) */
#define ID_SERCOM1       ( 66) /* Instance index for SERCOM1 (SERCOM1) */
#define ID_SERCOM2       ( 67) /* Instance index for SERCOM2 (SERCOM2) */
#define ID_SERCOM3       ( 68) /* Instance index for SERCOM3 (SERCOM3) */
#define ID_SERCOM4       ( 69) /* Instance index for SERCOM4 (SERCOM4) */
#define ID_SERCOM5       ( 70) /* Instance index for SERCOM5 (SERCOM5) */
#define ID_CAN0          ( 71) /* Instance index for CAN0 (CAN0) */
#define ID_CAN1          ( 72) /* Instance index for CAN1 (CAN1) */
#define ID_TCC0          ( 73) /* Instance index for TCC0 (TCC0) */
#define ID_TCC1          ( 74) /* Instance index for TCC1 (TCC1) */
#define ID_TCC2          ( 75) /* Instance index for TCC2 (TCC2) */
#define ID_TC0           ( 76) /* Instance index for TC0 (TC0) */
#define ID_TC1           ( 77) /* Instance index for TC1 (TC1) */
#define ID_TC2           ( 78) /* Instance index for TC2 (TC2) */
#define ID_TC3           ( 79) /* Instance index for TC3 (TC3) */
#define ID_TC4           ( 80) /* Instance index for TC4 (TC4) */
#define ID_ADC0          ( 81) /* Instance index for ADC0 (ADC0) */
#define ID_ADC1          ( 82) /* Instance index for ADC1 (ADC1) */
#define ID_AC            ( 83) /* Instance index for AC (AC) */
#define ID_DAC           ( 84) /* Instance index for DAC (DAC) */
#define ID_PTC           ( 85) /* Instance index for PTC (PTC) */
#define ID_CCL           ( 86) /* Instance index for CCL (CCL) */
#define ID_ICM           ( 89) /* Instance index for ICM (ICM) */
#define ID_PDEC          ( 90) /* Instance index for PDEC (PDEC) */
#define ID_SMBIST        ( 91) /* Instance index for SMBIST. (SMBIST) */
#define ID_TC5           ( 98) /* Instance index for TC5 (TC5) */
#define ID_TC6           ( 99) /* Instance index for TC6 (TC6) */
#define ID_TC7           (100) /* Instance index for TC7 (TC7) */

#define ID_PERIPH_MAX    (100) /* Number of peripheral IDs */

/* ************************************************************************** */
/*   REGISTER STRUCTURE ADDRESS DEFINITIONS FOR PIC32CM5164JH01048            */
/* ************************************************************************** */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#define AC_REGS                          ((ac_registers_t*)0x42004c00)                 /* AC Registers Address         */
#define ADC0_REGS                        ((adc_registers_t*)0x42004400)                /* ADC0 Registers Address       */
#define ADC1_REGS                        ((adc_registers_t*)0x42004800)                /* ADC1 Registers Address       */
#define CAN0_REGS                        ((can_registers_t*)0x42001c00)                /* CAN0 Registers Address       */
#define CAN1_REGS                        ((can_registers_t*)0x42002000)                /* CAN1 Registers Address       */
#define CCL_REGS                         ((ccl_registers_t*)0x42005800)                /* CCL Registers Address        */
#define DAC_REGS                         ((dac_registers_t*)0x42005000)                /* DAC Registers Address        */
#define DIVAS_REGS                       ((divas_registers_t*)0x48000000)              /* DIVAS Registers Address      */
#define DIVAS_IOBUS_REGS                 ((divas_registers_t*)0x60000200)              /* DIVAS Registers Address      */
#define DMAC_REGS                        ((dmac_registers_t*)0x41006000)               /* DMAC Registers Address       */
#define DSU_REGS                         ((dsu_registers_t*)0x41002000)                /* DSU Registers Address        */
#define DSU_EXT_REGS                     ((dsu_registers_t*)0x41002100)                /* DSU Registers Address        */
#define EIC_REGS                         ((eic_registers_t*)0x40002800)                /* EIC Registers Address        */
#define EVSYS_REGS                       ((evsys_registers_t*)0x42000000)              /* EVSYS Registers Address      */
#define FREQM_REGS                       ((freqm_registers_t*)0x40002c00)              /* FREQM Registers Address      */
#define GCLK_REGS                        ((gclk_registers_t*)0x40001c00)               /* GCLK Registers Address       */
#define ICM_REGS                         ((icm_registers_t*)0x42006400)                /* ICM Registers Address        */
#define SMBIST_REGS                      ((smbist_registers_t*)0x42006c00)             /* SMBIST Registers Address     */
#define MCLK_REGS                        ((mclk_registers_t*)0x40000800)               /* MCLK Registers Address       */
#define MCRAMC_REGS                      ((mcramc_registers_t*)0x40003000)             /* MCRAMC Registers Address     */
#define MTB_REGS                         ((mtb_registers_t*)0x41008000)                /* MTB Registers Address        */
#define NVMCTRL_REGS                     ((nvmctrl_registers_t*)0x41004000)            /* NVMCTRL Registers Address    */
#define LOCKBIT_FUSES_REGS               ((fuses_lockbit_fuses_registers_t*)0x00802000) /* FUSES Registers Address      */
#define OTP1_FUSES_REGS                  ((fuses_otp1_fuses_registers_t*)0x00806000)   /* FUSES Registers Address      */
#define OTP2_FUSES_REGS                  ((fuses_otp2_fuses_registers_t*)0x00806008)   /* FUSES Registers Address      */
#define OTP3_FUSES_REGS                  ((fuses_otp3_fuses_registers_t*)0x00806010)   /* FUSES Registers Address      */
#define OTP4_FUSES_REGS                  ((fuses_otp4_fuses_registers_t*)0x00806018)   /* FUSES Registers Address      */
#define OTP5_FUSES_REGS                  ((fuses_otp5_fuses_registers_t*)0x00806020)   /* FUSES Registers Address      */
#define USER_FUSES_REGS                  ((fuses_user_fuses_registers_t*)0x00804000)   /* FUSES Registers Address      */
#define OSC32KCTRL_REGS                  ((osc32kctrl_registers_t*)0x40001400)         /* OSC32KCTRL Registers Address */
#define OSCCTRL_REGS                     ((oscctrl_registers_t*)0x40001000)            /* OSCCTRL Registers Address    */
#define PAC_REGS                         ((pac_registers_t*)0x40000000)                /* PAC Registers Address        */
#define PDEC_REGS                        ((pdec_registers_t*)0x42006800)               /* PDEC Registers Address       */
#define PM_REGS                          ((pm_registers_t*)0x40000400)                 /* PM Registers Address         */
#define PORT_REGS                        ((port_registers_t*)0x41000000)               /* PORT Registers Address       */
#define PORT_IOBUS_REGS                  ((port_registers_t*)0x60000000)               /* PORT Registers Address       */
#define PTC_REGS                         ((ptc_registers_t*)0x42005400)                /* PTC Registers Address        */
#define RSTC_REGS                        ((rstc_registers_t*)0x40000c00)               /* RSTC Registers Address       */
#define RTC_REGS                         ((rtc_registers_t*)0x40002400)                /* RTC Registers Address        */
#define SERCOM0_REGS                     ((sercom_registers_t*)0x42000400)             /* SERCOM0 Registers Address    */
#define SERCOM1_REGS                     ((sercom_registers_t*)0x42000800)             /* SERCOM1 Registers Address    */
#define SERCOM2_REGS                     ((sercom_registers_t*)0x42000c00)             /* SERCOM2 Registers Address    */
#define SERCOM3_REGS                     ((sercom_registers_t*)0x42001000)             /* SERCOM3 Registers Address    */
#define SERCOM4_REGS                     ((sercom_registers_t*)0x42001400)             /* SERCOM4 Registers Address    */
#define SERCOM5_REGS                     ((sercom_registers_t*)0x42001800)             /* SERCOM5 Registers Address    */
#define SUPC_REGS                        ((supc_registers_t*)0x40001800)               /* SUPC Registers Address       */
#define TC0_REGS                         ((tc_registers_t*)0x42003000)                 /* TC0 Registers Address        */
#define TC1_REGS                         ((tc_registers_t*)0x42003400)                 /* TC1 Registers Address        */
#define TC2_REGS                         ((tc_registers_t*)0x42003800)                 /* TC2 Registers Address        */
#define TC3_REGS                         ((tc_registers_t*)0x42003c00)                 /* TC3 Registers Address        */
#define TC4_REGS                         ((tc_registers_t*)0x42004000)                 /* TC4 Registers Address        */
#define TC5_REGS                         ((tc_registers_t*)0x43000800)                 /* TC5 Registers Address        */
#define TC6_REGS                         ((tc_registers_t*)0x43000c00)                 /* TC6 Registers Address        */
#define TC7_REGS                         ((tc_registers_t*)0x43001000)                 /* TC7 Registers Address        */
#define TCC0_REGS                        ((tcc_registers_t*)0x42002400)                /* TCC0 Registers Address       */
#define TCC1_REGS                        ((tcc_registers_t*)0x42002800)                /* TCC1 Registers Address       */
#define TCC2_REGS                        ((tcc_registers_t*)0x42002c00)                /* TCC2 Registers Address       */
#define WDT_REGS                         ((wdt_registers_t*)0x40002000)                /* WDT Registers Address        */
#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ************************************************************************** */
/*   BASE ADDRESS DEFINITIONS FOR PIC32CM5164JH01048                          */
/* ************************************************************************** */
#define AC_BASE_ADDRESS                  _UINT32_(0x42004c00)                          /* AC Base Address */
#define ADC0_BASE_ADDRESS                _UINT32_(0x42004400)                          /* ADC0 Base Address */
#define ADC1_BASE_ADDRESS                _UINT32_(0x42004800)                          /* ADC1 Base Address */
#define CAN0_BASE_ADDRESS                _UINT32_(0x42001c00)                          /* CAN0 Base Address */
#define CAN1_BASE_ADDRESS                _UINT32_(0x42002000)                          /* CAN1 Base Address */
#define CCL_BASE_ADDRESS                 _UINT32_(0x42005800)                          /* CCL Base Address */
#define DAC_BASE_ADDRESS                 _UINT32_(0x42005000)                          /* DAC Base Address */
#define DIVAS_BASE_ADDRESS               _UINT32_(0x48000000)                          /* DIVAS Base Address */
#define DIVAS_IOBUS_BASE_ADDRESS         _UINT32_(0x60000200)                          /* DIVAS Base Address */
#define DMAC_BASE_ADDRESS                _UINT32_(0x41006000)                          /* DMAC Base Address */
#define DSU_BASE_ADDRESS                 _UINT32_(0x41002000)                          /* DSU Base Address */
#define DSU_EXT_BASE_ADDRESS             _UINT32_(0x41002100)                          /* DSU Base Address */
#define EIC_BASE_ADDRESS                 _UINT32_(0x40002800)                          /* EIC Base Address */
#define EVSYS_BASE_ADDRESS               _UINT32_(0x42000000)                          /* EVSYS Base Address */
#define FREQM_BASE_ADDRESS               _UINT32_(0x40002c00)                          /* FREQM Base Address */
#define GCLK_BASE_ADDRESS                _UINT32_(0x40001c00)                          /* GCLK Base Address */
#define ICM_BASE_ADDRESS                 _UINT32_(0x42006400)                          /* ICM Base Address */
#define SMBIST_BASE_ADDRESS              _UINT32_(0x42006c00)                          /* SMBIST Base Address */
#define MCLK_BASE_ADDRESS                _UINT32_(0x40000800)                          /* MCLK Base Address */
#define MCRAMC_BASE_ADDRESS              _UINT32_(0x40003000)                          /* MCRAMC Base Address */
#define MTB_BASE_ADDRESS                 _UINT32_(0x41008000)                          /* MTB Base Address */
#define NVMCTRL_BASE_ADDRESS             _UINT32_(0x41004000)                          /* NVMCTRL Base Address */
#define LOCKBIT_FUSES_BASE_ADDRESS       _UINT32_(0x00802000)                          /* FUSES Base Address */
#define OTP1_FUSES_BASE_ADDRESS          _UINT32_(0x00806000)                          /* FUSES Base Address */
#define OTP2_FUSES_BASE_ADDRESS          _UINT32_(0x00806008)                          /* FUSES Base Address */
#define OTP3_FUSES_BASE_ADDRESS          _UINT32_(0x00806010)                          /* FUSES Base Address */
#define OTP4_FUSES_BASE_ADDRESS          _UINT32_(0x00806018)                          /* FUSES Base Address */
#define OTP5_FUSES_BASE_ADDRESS          _UINT32_(0x00806020)                          /* FUSES Base Address */
#define USER_FUSES_BASE_ADDRESS          _UINT32_(0x00804000)                          /* FUSES Base Address */
#define OSC32KCTRL_BASE_ADDRESS          _UINT32_(0x40001400)                          /* OSC32KCTRL Base Address */
#define OSCCTRL_BASE_ADDRESS             _UINT32_(0x40001000)                          /* OSCCTRL Base Address */
#define PAC_BASE_ADDRESS                 _UINT32_(0x40000000)                          /* PAC Base Address */
#define PDEC_BASE_ADDRESS                _UINT32_(0x42006800)                          /* PDEC Base Address */
#define PM_BASE_ADDRESS                  _UINT32_(0x40000400)                          /* PM Base Address */
#define PORT_BASE_ADDRESS                _UINT32_(0x41000000)                          /* PORT Base Address */
#define PORT_IOBUS_BASE_ADDRESS          _UINT32_(0x60000000)                          /* PORT Base Address */
#define PTC_BASE_ADDRESS                 _UINT32_(0x42005400)                          /* PTC Base Address */
#define RSTC_BASE_ADDRESS                _UINT32_(0x40000c00)                          /* RSTC Base Address */
#define RTC_BASE_ADDRESS                 _UINT32_(0x40002400)                          /* RTC Base Address */
#define SERCOM0_BASE_ADDRESS             _UINT32_(0x42000400)                          /* SERCOM0 Base Address */
#define SERCOM1_BASE_ADDRESS             _UINT32_(0x42000800)                          /* SERCOM1 Base Address */
#define SERCOM2_BASE_ADDRESS             _UINT32_(0x42000c00)                          /* SERCOM2 Base Address */
#define SERCOM3_BASE_ADDRESS             _UINT32_(0x42001000)                          /* SERCOM3 Base Address */
#define SERCOM4_BASE_ADDRESS             _UINT32_(0x42001400)                          /* SERCOM4 Base Address */
#define SERCOM5_BASE_ADDRESS             _UINT32_(0x42001800)                          /* SERCOM5 Base Address */
#define SUPC_BASE_ADDRESS                _UINT32_(0x40001800)                          /* SUPC Base Address */
#define TC0_BASE_ADDRESS                 _UINT32_(0x42003000)                          /* TC0 Base Address */
#define TC1_BASE_ADDRESS                 _UINT32_(0x42003400)                          /* TC1 Base Address */
#define TC2_BASE_ADDRESS                 _UINT32_(0x42003800)                          /* TC2 Base Address */
#define TC3_BASE_ADDRESS                 _UINT32_(0x42003c00)                          /* TC3 Base Address */
#define TC4_BASE_ADDRESS                 _UINT32_(0x42004000)                          /* TC4 Base Address */
#define TC5_BASE_ADDRESS                 _UINT32_(0x43000800)                          /* TC5 Base Address */
#define TC6_BASE_ADDRESS                 _UINT32_(0x43000c00)                          /* TC6 Base Address */
#define TC7_BASE_ADDRESS                 _UINT32_(0x43001000)                          /* TC7 Base Address */
#define TCC0_BASE_ADDRESS                _UINT32_(0x42002400)                          /* TCC0 Base Address */
#define TCC1_BASE_ADDRESS                _UINT32_(0x42002800)                          /* TCC1 Base Address */
#define TCC2_BASE_ADDRESS                _UINT32_(0x42002c00)                          /* TCC2 Base Address */
#define WDT_BASE_ADDRESS                 _UINT32_(0x40002000)                          /* WDT Base Address */

/* ************************************************************************** */
/*   PIO DEFINITIONS FOR PIC32CM5164JH01048                                   */
/* ************************************************************************** */
#include "pio/pic32cm5164jh01048.h"

/* ************************************************************************** */
/*   MEMORY MAPPING DEFINITIONS FOR PIC32CM5164JH01048                        */
/* ************************************************************************** */
#define FLASH_SIZE                     _UINT32_(0x00080000)    /*  512kB Memory segment type: flash */
#define FLASH_PAGE_SIZE                _UINT32_(        64)
#define FLASH_NB_OF_PAGES              _UINT32_(      8192)

#define CAL_SIZE                       _UINT32_(0x00000008)    /*    0kB Memory segment type: fuses */
#define LOCKBIT_SIZE                   _UINT32_(0x00000004)    /*    0kB Memory segment type: fuses */
#define OTP1_SIZE                      _UINT32_(0x00000008)    /*    0kB Memory segment type: fuses */
#define OTP2_SIZE                      _UINT32_(0x00000008)    /*    0kB Memory segment type: fuses */
#define OTP3_SIZE                      _UINT32_(0x00000008)    /*    0kB Memory segment type: fuses */
#define OTP4_SIZE                      _UINT32_(0x00000008)    /*    0kB Memory segment type: fuses */
#define OTP5_SIZE                      _UINT32_(0x00000008)    /*    0kB Memory segment type: fuses */
#define TEMP_LOG_SIZE                  _UINT32_(0x00000008)    /*    0kB Memory segment type: fuses */
#define USER_PAGE_SIZE                 _UINT32_(0x00000100)    /*    0kB Memory segment type: user_page */
#define USER_PAGE_PAGE_SIZE            _UINT32_(        64)
#define USER_PAGE_NB_OF_PAGES          _UINT32_(         4)

#define DATAFLASH_SIZE                 _UINT32_(0x00002000)    /*    8kB Memory segment type: flash */
#define DATAFLASH_PAGE_SIZE            _UINT32_(        64)
#define DATAFLASH_NB_OF_PAGES          _UINT32_(       128)

#define DRAM_SIZE                      _UINT32_(0x00010000)    /*   64kB Memory segment type: ram */
#define HPB0_SIZE                      _UINT32_(0x00004000)    /*   16kB Memory segment type: io */
#define HPB1_SIZE                      _UINT32_(0x00010000)    /*   64kB Memory segment type: io */
#define HPB2_SIZE                      _UINT32_(0x00008000)    /*   32kB Memory segment type: io */
#define HPB3_SIZE                      _UINT32_(0x00001800)    /*    6kB Memory segment type: io */
#define DIVAS_SIZE                     _UINT32_(0x00000020)    /*    0kB Memory segment type: io */
#define PPB_SIZE                       _UINT32_(0x00100000)    /* 1024kB Memory segment type: io */

#define FLASH_ADDR                     _UINT32_(0x00000000)    /* FLASH base address (type: flash)*/
#define CAL_ADDR                       _UINT32_(0x00800000)    /* CAL base address (type: fuses)*/
#define LOCKBIT_ADDR                   _UINT32_(0x00802000)    /* LOCKBIT base address (type: fuses)*/
#define OTP1_ADDR                      _UINT32_(0x00806000)    /* OTP1 base address (type: fuses)*/
#define OTP2_ADDR                      _UINT32_(0x00806008)    /* OTP2 base address (type: fuses)*/
#define OTP3_ADDR                      _UINT32_(0x00806010)    /* OTP3 base address (type: fuses)*/
#define OTP4_ADDR                      _UINT32_(0x00806018)    /* OTP4 base address (type: fuses)*/
#define OTP5_ADDR                      _UINT32_(0x00806020)    /* OTP5 base address (type: fuses)*/
#define TEMP_LOG_ADDR                  _UINT32_(0x00806030)    /* TEMP_LOG base address (type: fuses)*/
#define USER_PAGE_ADDR                 _UINT32_(0x00804000)    /* USER_PAGE base address (type: user_page)*/
#define DATAFLASH_ADDR                 _UINT32_(0x00400000)    /* DATAFLASH base address (type: flash)*/
#define DRAM_ADDR                      _UINT32_(0x20000000)    /* DRAM base address (type: ram)*/
#define HPB0_ADDR                      _UINT32_(0x40000000)    /* HPB0 base address (type: io)*/
#define HPB1_ADDR                      _UINT32_(0x41000000)    /* HPB1 base address (type: io)*/
#define HPB2_ADDR                      _UINT32_(0x42000000)    /* HPB2 base address (type: io)*/
#define HPB3_ADDR                      _UINT32_(0x43000000)    /* HPB3 base address (type: io)*/
#define DIVAS_ADDR                     _UINT32_(0x48000000)    /* DIVAS base address (type: io)*/
#define PPB_ADDR                       _UINT32_(0xe0000000)    /* PPB base address (type: io)*/

/* ************************************************************************** */
/*   DEVICE SIGNATURES FOR PIC32CM5164JH01048                                 */
/* ************************************************************************** */
#define CHIP_DSU_DID                   _UINT32_(0X11060002)

/* ************************************************************************** */
/*   ELECTRICAL DEFINITIONS FOR PIC32CM5164JH01048                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* Event Generator IDs for C32CM5164JH01048 */
/* ************************************************************************** */
#define EVENT_ID_GEN_RTC_PERD                             1 /* ID for RTC event generator PERD */
#define EVENT_ID_GEN_OSCCTRL_XOSC_FAIL                    3 /* ID for OSCCTRL event generator XOSC_FAIL */
#define EVENT_ID_GEN_OSC32KCTRL_XOSC32K_FAIL              4 /* ID for OSC32KCTRL event generator XOSC32K_FAIL */
#define EVENT_ID_GEN_RTC_CMP_0                            5 /* ID for RTC event generator CMP_0 */
#define EVENT_ID_GEN_RTC_CMP_1                            6 /* ID for RTC event generator CMP_1 */
#define EVENT_ID_GEN_RTC_OVF                              7 /* ID for RTC event generator OVF */
#define EVENT_ID_GEN_RTC_PER_0                            8 /* ID for RTC event generator PER_0 */
#define EVENT_ID_GEN_RTC_PER_1                            9 /* ID for RTC event generator PER_1 */
#define EVENT_ID_GEN_RTC_PER_2                           10 /* ID for RTC event generator PER_2 */
#define EVENT_ID_GEN_RTC_PER_3                           11 /* ID for RTC event generator PER_3 */
#define EVENT_ID_GEN_RTC_PER_4                           12 /* ID for RTC event generator PER_4 */
#define EVENT_ID_GEN_RTC_PER_5                           13 /* ID for RTC event generator PER_5 */
#define EVENT_ID_GEN_RTC_PER_6                           14 /* ID for RTC event generator PER_6 */
#define EVENT_ID_GEN_RTC_PER_7                           15 /* ID for RTC event generator PER_7 */
#define EVENT_ID_GEN_EIC_EXTINT_0                        16 /* ID for EIC event generator EXTINT_0 */
#define EVENT_ID_GEN_EIC_EXTINT_1                        17 /* ID for EIC event generator EXTINT_1 */
#define EVENT_ID_GEN_EIC_EXTINT_2                        18 /* ID for EIC event generator EXTINT_2 */
#define EVENT_ID_GEN_EIC_EXTINT_3                        19 /* ID for EIC event generator EXTINT_3 */
#define EVENT_ID_GEN_EIC_EXTINT_4                        20 /* ID for EIC event generator EXTINT_4 */
#define EVENT_ID_GEN_EIC_EXTINT_5                        21 /* ID for EIC event generator EXTINT_5 */
#define EVENT_ID_GEN_EIC_EXTINT_6                        22 /* ID for EIC event generator EXTINT_6 */
#define EVENT_ID_GEN_EIC_EXTINT_7                        23 /* ID for EIC event generator EXTINT_7 */
#define EVENT_ID_GEN_EIC_EXTINT_8                        24 /* ID for EIC event generator EXTINT_8 */
#define EVENT_ID_GEN_EIC_EXTINT_9                        25 /* ID for EIC event generator EXTINT_9 */
#define EVENT_ID_GEN_EIC_EXTINT_10                       26 /* ID for EIC event generator EXTINT_10 */
#define EVENT_ID_GEN_EIC_EXTINT_11                       27 /* ID for EIC event generator EXTINT_11 */
#define EVENT_ID_GEN_EIC_EXTINT_12                       28 /* ID for EIC event generator EXTINT_12 */
#define EVENT_ID_GEN_EIC_EXTINT_13                       29 /* ID for EIC event generator EXTINT_13 */
#define EVENT_ID_GEN_EIC_EXTINT_14                       30 /* ID for EIC event generator EXTINT_14 */
#define EVENT_ID_GEN_EIC_EXTINT_15                       31 /* ID for EIC event generator EXTINT_15 */
#define EVENT_ID_GEN_DMAC_CH_0                           32 /* ID for DMAC event generator CH_0 */
#define EVENT_ID_GEN_DMAC_CH_1                           33 /* ID for DMAC event generator CH_1 */
#define EVENT_ID_GEN_DMAC_CH_2                           34 /* ID for DMAC event generator CH_2 */
#define EVENT_ID_GEN_DMAC_CH_3                           35 /* ID for DMAC event generator CH_3 */
#define EVENT_ID_GEN_TCC0_OVF                            36 /* ID for TCC0 event generator OVF */
#define EVENT_ID_GEN_TCC0_TRG                            37 /* ID for TCC0 event generator TRG */
#define EVENT_ID_GEN_TCC0_CNT                            38 /* ID for TCC0 event generator CNT */
#define EVENT_ID_GEN_TCC0_MC_0                           39 /* ID for TCC0 event generator MC_0 */
#define EVENT_ID_GEN_TCC0_MC_1                           40 /* ID for TCC0 event generator MC_1 */
#define EVENT_ID_GEN_TCC0_MC_2                           41 /* ID for TCC0 event generator MC_2 */
#define EVENT_ID_GEN_TCC0_MC_3                           42 /* ID for TCC0 event generator MC_3 */
#define EVENT_ID_GEN_TCC1_OVF                            43 /* ID for TCC1 event generator OVF */
#define EVENT_ID_GEN_TCC1_TRG                            44 /* ID for TCC1 event generator TRG */
#define EVENT_ID_GEN_TCC1_CNT                            45 /* ID for TCC1 event generator CNT */
#define EVENT_ID_GEN_TCC1_MC_0                           46 /* ID for TCC1 event generator MC_0 */
#define EVENT_ID_GEN_TCC1_MC_1                           47 /* ID for TCC1 event generator MC_1 */
#define EVENT_ID_GEN_TCC2_OVF                            48 /* ID for TCC2 event generator OVF */
#define EVENT_ID_GEN_TCC2_TRG                            49 /* ID for TCC2 event generator TRG */
#define EVENT_ID_GEN_TCC2_CNT                            50 /* ID for TCC2 event generator CNT */
#define EVENT_ID_GEN_TCC2_MC_0                           51 /* ID for TCC2 event generator MC_0 */
#define EVENT_ID_GEN_TCC2_MC_1                           52 /* ID for TCC2 event generator MC_1 */
#define EVENT_ID_GEN_TC0_OVF                             53 /* ID for TC0 event generator OVF */
#define EVENT_ID_GEN_TC0_MC_0                            54 /* ID for TC0 event generator MC_0 */
#define EVENT_ID_GEN_TC0_MC_1                            55 /* ID for TC0 event generator MC_1 */
#define EVENT_ID_GEN_TC1_OVF                             56 /* ID for TC1 event generator OVF */
#define EVENT_ID_GEN_TC1_MC_0                            57 /* ID for TC1 event generator MC_0 */
#define EVENT_ID_GEN_TC1_MC_1                            58 /* ID for TC1 event generator MC_1 */
#define EVENT_ID_GEN_TC2_OVF                             59 /* ID for TC2 event generator OVF */
#define EVENT_ID_GEN_TC2_MC_0                            60 /* ID for TC2 event generator MC_0 */
#define EVENT_ID_GEN_TC2_MC_1                            61 /* ID for TC2 event generator MC_1 */
#define EVENT_ID_GEN_TC3_OVF                             62 /* ID for TC3 event generator OVF */
#define EVENT_ID_GEN_TC3_MC_0                            63 /* ID for TC3 event generator MC_0 */
#define EVENT_ID_GEN_TC3_MC_1                            64 /* ID for TC3 event generator MC_1 */
#define EVENT_ID_GEN_TC4_OVF                             65 /* ID for TC4 event generator OVF */
#define EVENT_ID_GEN_TC4_MC_0                            66 /* ID for TC4 event generator MC_0 */
#define EVENT_ID_GEN_TC4_MC_1                            67 /* ID for TC4 event generator MC_1 */
#define EVENT_ID_GEN_ADC0_RESRDY                         68 /* ID for ADC0 event generator RESRDY */
#define EVENT_ID_GEN_ADC0_WINMON                         69 /* ID for ADC0 event generator WINMON */
#define EVENT_ID_GEN_ADC1_RESRDY                         70 /* ID for ADC1 event generator RESRDY */
#define EVENT_ID_GEN_ADC1_WINMON                         71 /* ID for ADC1 event generator WINMON */
#define EVENT_ID_GEN_AC_COMP_0                           72 /* ID for AC event generator COMP_0 */
#define EVENT_ID_GEN_AC_COMP_1                           73 /* ID for AC event generator COMP_1 */
#define EVENT_ID_GEN_AC_COMP_2                           74 /* ID for AC event generator COMP_2 */
#define EVENT_ID_GEN_AC_COMP_3                           75 /* ID for AC event generator COMP_3 */
#define EVENT_ID_GEN_AC_WIN_0                            76 /* ID for AC event generator WIN_0 */
#define EVENT_ID_GEN_AC_WIN_1                            77 /* ID for AC event generator WIN_1 */
#define EVENT_ID_GEN_DAC_EMPTY                           78 /* ID for DAC event generator EMPTY */
#define EVENT_ID_GEN_PTC_EOC                             79 /* ID for PTC event generator EOC */
#define EVENT_ID_GEN_PTC_WCOMP                           80 /* ID for PTC event generator WCOMP */
#define EVENT_ID_GEN_CCL_LUTOUT_0                        81 /* ID for CCL event generator LUTOUT_0 */
#define EVENT_ID_GEN_CCL_LUTOUT_1                        82 /* ID for CCL event generator LUTOUT_1 */
#define EVENT_ID_GEN_CCL_LUTOUT_2                        83 /* ID for CCL event generator LUTOUT_2 */
#define EVENT_ID_GEN_CCL_LUTOUT_3                        84 /* ID for CCL event generator LUTOUT_3 */
#define EVENT_ID_GEN_PAC_ACCERR                          85 /* ID for PAC event generator ACCERR */
#define EVENT_ID_GEN_TC5_OVF                             87 /* ID for TC5 event generator OVF */
#define EVENT_ID_GEN_TC5_MC_0                            88 /* ID for TC5 event generator MC_0 */
#define EVENT_ID_GEN_TC5_MC_1                            89 /* ID for TC5 event generator MC_1 */
#define EVENT_ID_GEN_TC6_OVF                             90 /* ID for TC6 event generator OVF */
#define EVENT_ID_GEN_TC6_MC_0                            91 /* ID for TC6 event generator MC_0 */
#define EVENT_ID_GEN_TC6_MC_1                            92 /* ID for TC6 event generator MC_1 */
#define EVENT_ID_GEN_TC7_OVF                             93 /* ID for TC7 event generator OVF */
#define EVENT_ID_GEN_TC7_MC_0                            94 /* ID for TC7 event generator MC_0 */
#define EVENT_ID_GEN_TC7_MC_1                            95 /* ID for TC7 event generator MC_1 */
#define EVENT_ID_GEN_PDEC_OVF                            96 /* ID for PDEC event generator OVF */
#define EVENT_ID_GEN_PDEC_ERR                            97 /* ID for PDEC event generator ERR */
#define EVENT_ID_GEN_PDEC_DIR                            98 /* ID for PDEC event generator DIR */
#define EVENT_ID_GEN_PDEC_VLC                            99 /* ID for PDEC event generator VLC */
#define EVENT_ID_GEN_PDEC_MC_0                          100 /* ID for PDEC event generator MC_0 */
#define EVENT_ID_GEN_PDEC_MC_1                          101 /* ID for PDEC event generator MC_1 */

/* ************************************************************************** */
/*  Event User IDs for C32CM5164JH01048 */
/* ************************************************************************** */
#define EVENT_ID_USER_PORT_EV_0                           1 /* ID for PORT event user EV_0 */
#define EVENT_ID_USER_PORT_EV_1                           2 /* ID for PORT event user EV_1 */
#define EVENT_ID_USER_PORT_EV_2                           3 /* ID for PORT event user EV_2 */
#define EVENT_ID_USER_PORT_EV_3                           4 /* ID for PORT event user EV_3 */
#define EVENT_ID_USER_DMAC_CH_0                           5 /* ID for DMAC event user CH_0 */
#define EVENT_ID_USER_DMAC_CH_1                           6 /* ID for DMAC event user CH_1 */
#define EVENT_ID_USER_DMAC_CH_2                           7 /* ID for DMAC event user CH_2 */
#define EVENT_ID_USER_DMAC_CH_3                           8 /* ID for DMAC event user CH_3 */
#define EVENT_ID_USER_TCC0_EV_0                           9 /* ID for TCC0 event user EV_0 */
#define EVENT_ID_USER_TCC0_EV_1                          10 /* ID for TCC0 event user EV_1 */
#define EVENT_ID_USER_TCC0_MC_0                          11 /* ID for TCC0 event user MC_0 */
#define EVENT_ID_USER_TCC0_MC_1                          12 /* ID for TCC0 event user MC_1 */
#define EVENT_ID_USER_TCC0_MC_2                          13 /* ID for TCC0 event user MC_2 */
#define EVENT_ID_USER_TCC0_MC_3                          14 /* ID for TCC0 event user MC_3 */
#define EVENT_ID_USER_TCC1_EV_0                          15 /* ID for TCC1 event user EV_0 */
#define EVENT_ID_USER_TCC1_EV_1                          16 /* ID for TCC1 event user EV_1 */
#define EVENT_ID_USER_TCC1_MC_0                          17 /* ID for TCC1 event user MC_0 */
#define EVENT_ID_USER_TCC1_MC_1                          18 /* ID for TCC1 event user MC_1 */
#define EVENT_ID_USER_TCC2_EV_0                          19 /* ID for TCC2 event user EV_0 */
#define EVENT_ID_USER_TCC2_EV_1                          20 /* ID for TCC2 event user EV_1 */
#define EVENT_ID_USER_TCC2_MC_0                          21 /* ID for TCC2 event user MC_0 */
#define EVENT_ID_USER_TCC2_MC_1                          22 /* ID for TCC2 event user MC_1 */
#define EVENT_ID_USER_TC0_EVU                            23 /* ID for TC0 event user EVU */
#define EVENT_ID_USER_TC1_EVU                            24 /* ID for TC1 event user EVU */
#define EVENT_ID_USER_TC2_EVU                            25 /* ID for TC2 event user EVU */
#define EVENT_ID_USER_TC3_EVU                            26 /* ID for TC3 event user EVU */
#define EVENT_ID_USER_TC4_EVU                            27 /* ID for TC4 event user EVU */
#define EVENT_ID_USER_ADC0_START                         28 /* ID for ADC0 event user START */
#define EVENT_ID_USER_ADC0_SYNC                          29 /* ID for ADC0 event user SYNC */
#define EVENT_ID_USER_ADC1_START                         30 /* ID for ADC1 event user START */
#define EVENT_ID_USER_ADC1_SYNC                          31 /* ID for ADC1 event user SYNC */
#define EVENT_ID_USER_AC_SOC_0                           32 /* ID for AC event user SOC_0 */
#define EVENT_ID_USER_AC_SOC_1                           33 /* ID for AC event user SOC_1 */
#define EVENT_ID_USER_AC_SOC_2                           34 /* ID for AC event user SOC_2 */
#define EVENT_ID_USER_AC_SOC_3                           35 /* ID for AC event user SOC_3 */
#define EVENT_ID_USER_DAC_START                          36 /* ID for DAC event user START */
#define EVENT_ID_USER_PTC_STCONV                         37 /* ID for DAC event user PTC_STCONV */
#define EVENT_ID_USER_CCL_LUTIN_0                        38 /* ID for CCL event user LUTIN_0 */
#define EVENT_ID_USER_CCL_LUTIN_1                        39 /* ID for CCL event user LUTIN_1 */
#define EVENT_ID_USER_CCL_LUTIN_2                        40 /* ID for CCL event user LUTIN_2 */
#define EVENT_ID_USER_CCL_LUTIN_3                        41 /* ID for CCL event user LUTIN_3 */
#define EVENT_ID_USER_MTB_START                          43 /* ID for MTB event user START */
#define EVENT_ID_USER_MTB_STOP                           44 /* ID for MTB event user STOP */
#define EVENT_ID_USER_TC5_EVU                            45 /* ID for TC5 event user EVU */
#define EVENT_ID_USER_TC6_EVU                            46 /* ID for TC6 event user EVU */
#define EVENT_ID_USER_TC7_EVU                            47 /* ID for TC7 event user EVU */
#define EVENT_ID_USER_PDEC_EVU_0                         48 /* ID for PDEC event user EVU_0 */
#define EVENT_ID_USER_PDEC_EVU_1                         49 /* ID for PDEC event user EVU_1 */
#define EVENT_ID_USER_PDEC_EVU_2                         50 /* ID for PDEC event user EVU_2 */

#ifdef __cplusplus
}
#endif

#endif /* _PIC32CM5164JH01048_H_ */

