/*
 * Header file for PIC32CZ8110CA80208
 *
 * Copyright (c) 2022 Microchip Technology Inc. and its subsidiaries.
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

/* File generated from device description version 2022-07-07T22:59:24Z */
#ifndef _PIC32CZ8110CA80208_H_
#define _PIC32CZ8110CA80208_H_

/* Header version uses Semantic Versioning 2.0.0 (https://semver.org/) */
#define HEADER_FORMAT_VERSION "2.1.0"

#define HEADER_FORMAT_VERSION_MAJOR (2)
#define HEADER_FORMAT_VERSION_MINOR (1)
#define HEADER_FORMAT_VERSION_PATCH (0)

/* PIC32CZ8110CA80208 definitions
  This file defines all structures and symbols for PIC32CZ8110CA80208:
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
/* CMSIS DEFINITIONS FOR PIC32CZ8110CA80208                                 */
/* ************************************************************************** */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* Interrupt Number Definition */
typedef enum IRQn
{
/******  CORTEX-M7 Processor Exceptions Numbers ******************************/
  Reset_IRQn                = -15, /* -15 Reset Vector, invoked on Power up and warm reset */
  NonMaskableInt_IRQn       = -14, /* -14 Non maskable Interrupt, cannot be stopped or preempted */
  HardFault_IRQn            = -13, /* -13 Hard Fault, all classes of Fault    */
  MemoryManagement_IRQn     = -12, /* -12 Memory Management, MPU mismatch, including Access Violation and No Match */
  BusFault_IRQn             = -11, /* -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
  UsageFault_IRQn           = -10, /* -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition */
  SVCall_IRQn               =  -5, /* -5  System Service Call via SVC instruction */
  DebugMonitor_IRQn         =  -4, /* -4  Debug Monitor                       */
  PendSV_IRQn               =  -2, /* -2  Pendable request for system service */
  SysTick_IRQn              =  -1, /* -1  System Tick Timer                   */

/******  PIC32CZ8110CA80208 specific Interrupt Numbers ***********************************/
  FCW_IRQn                  =   0, /* 0   Flash Write Control (FCW) (FCW)     */
  FCR_ECCERR_IRQn           =   1, /* 1   Flash Read Controller (FCR) (FCR)   */
  FCR_CRC_FAULT_IRQn        =   2, /* 2   Flash Read Controller (FCR) (FCR)   */
  PM_IRQn                   =   3, /* 3   Power Manager (PM)                  */
  SUPC_IRQn                 =   4, /* 4   Supply Controller (SUPC)            */
  OSCCTRL_FAIL_IRQn         =   5, /* 5   Oscillators Control (OSCCTRL)       */
  OSCCTRL_XOSCRDY_IRQn      =   6, /* 6   Oscillators Control (OSCCTRL)       */
  OSCCTRL_DFLLRDY_IRQn      =   7, /* 7   Oscillators Control (OSCCTRL)       */
  OSCCTRL_OTHER_IRQn        =   8, /* 8   Oscillators Control (OSCCTRL)       */
  OSCCTRL_LOCK_IRQn         =   9, /* 9   Oscillators Control (OSCCTRL)       */
  OSC32KCTRL_FAIL_IRQn      =  10, /* 10  32kHz Oscillators Control (OSC32KCTRL) */
  OSC32KCTRL_RDY_IRQn       =  11, /* 11  32kHz Oscillators Control (OSC32KCTRL) */
  MCLK_IRQn                 =  12, /* 12  Main Clock (MCLK)                   */
  FREQM_IRQn                =  13, /* 13  Frequency Meter (FREQM)             */
  WDT_IRQn                  =  14, /* 14  Watchdog Timer (WDT)                */
  RTC_TAMPER_IRQn           =  15, /* 15  Real-Time Counter (RTC)             */
  RTC_OVF_IRQn              =  16, /* 16  Real-Time Counter (RTC)             */
  RTC_PERIOD_IRQn           =  17, /* 17  Real-Time Counter (RTC)             */
  RTC_COMPARE_IRQn          =  18, /* 18  Real-Time Counter (RTC)             */
  EIC_EXTINT_0_IRQn         =  19, /* 19  External Interrupt Controller (EIC) */
  EIC_EXTINT_1_IRQn         =  20, /* 20  External Interrupt Controller (EIC) */
  EIC_EXTINT_2_IRQn         =  21, /* 21  External Interrupt Controller (EIC) */
  EIC_EXTINT_3_IRQn         =  22, /* 22  External Interrupt Controller (EIC) */
  EIC_EXTINT_4_IRQn         =  23, /* 23  External Interrupt Controller (EIC) */
  EIC_EXTINT_5_IRQn         =  24, /* 24  External Interrupt Controller (EIC) */
  EIC_EXTINT_6_IRQn         =  25, /* 25  External Interrupt Controller (EIC) */
  EIC_EXTINT_7_IRQn         =  26, /* 26  External Interrupt Controller (EIC) */
  EIC_EXTINT_8_IRQn         =  27, /* 27  External Interrupt Controller (EIC) */
  EIC_EXTINT_9_IRQn         =  28, /* 28  External Interrupt Controller (EIC) */
  EIC_EXTINT_10_IRQn        =  29, /* 29  External Interrupt Controller (EIC) */
  EIC_EXTINT_11_IRQn        =  30, /* 30  External Interrupt Controller (EIC) */
  EIC_EXTINT_12_IRQn        =  31, /* 31  External Interrupt Controller (EIC) */
  EIC_EXTINT_13_IRQn        =  32, /* 32  External Interrupt Controller (EIC) */
  EIC_EXTINT_14_IRQn        =  33, /* 33  External Interrupt Controller (EIC) */
  EIC_EXTINT_15_IRQn        =  34, /* 34  External Interrupt Controller (EIC) */
  PAC_IRQn                  =  35, /* 35  Peripheral Access Controller (PAC)  */
  DRMTCM_IRQn               =  36, /* 36  DRM TCM ECC (DRMTCM)                */
  MCRAMC_IRQn               =  37, /* 37  Multi-Channel RAM Controller (MCRAMC) */
  TRAM_IRQn                 =  38, /* 38  TrustRAM (TRAM)                     */
  DMA_PRI3_IRQn             =  39, /* 39  Direct Memory Access Controller (DMA) */
  DMA_PRI2_IRQn             =  40, /* 40  Direct Memory Access Controller (DMA) */
  DMA_PRI1_IRQn             =  41, /* 41  Direct Memory Access Controller (DMA) */
  DMA_PRI0_IRQn             =  42, /* 42  Direct Memory Access Controller (DMA) */
  EVSYS_0_IRQn              =  43, /* 43  Event System Interface (EVSYS)      */
  EVSYS_1_IRQn              =  44, /* 44  Event System Interface (EVSYS)      */
  EVSYS_2_IRQn              =  45, /* 45  Event System Interface (EVSYS)      */
  EVSYS_3_IRQn              =  46, /* 46  Event System Interface (EVSYS)      */
  EVSYS_4_IRQn              =  47, /* 47  Event System Interface (EVSYS)      */
  EVSYS_5_IRQn              =  48, /* 48  Event System Interface (EVSYS)      */
  EVSYS_6_IRQn              =  49, /* 49  Event System Interface (EVSYS)      */
  EVSYS_7_IRQn              =  50, /* 50  Event System Interface (EVSYS)      */
  EVSYS_8_IRQn              =  51, /* 51  Event System Interface (EVSYS)      */
  EVSYS_9_IRQn              =  52, /* 52  Event System Interface (EVSYS)      */
  EVSYS_10_IRQn             =  53, /* 53  Event System Interface (EVSYS)      */
  EVSYS_11_IRQn             =  54, /* 54  Event System Interface (EVSYS)      */
  SERCOM0_6_IRQn            =  55, /* 55  Serial Communication Interface (SERCOM0) */
  SERCOM0_5_IRQn            =  56, /* 56  Serial Communication Interface (SERCOM0) */
  SERCOM0_0_IRQn            =  57, /* 57  Serial Communication Interface (SERCOM0) */
  SERCOM0_1_IRQn            =  58, /* 58  Serial Communication Interface (SERCOM0) */
  SERCOM0_2_IRQn            =  59, /* 59  Serial Communication Interface (SERCOM0) */
  SERCOM0_3_IRQn            =  60, /* 60  Serial Communication Interface (SERCOM0) */
  SERCOM0_4_IRQn            =  61, /* 61  Serial Communication Interface (SERCOM0) */
  SERCOM1_6_IRQn            =  62, /* 62  Serial Communication Interface (SERCOM1) */
  SERCOM1_5_IRQn            =  63, /* 63  Serial Communication Interface (SERCOM1) */
  SERCOM1_0_IRQn            =  64, /* 64  Serial Communication Interface (SERCOM1) */
  SERCOM1_1_IRQn            =  65, /* 65  Serial Communication Interface (SERCOM1) */
  SERCOM1_2_IRQn            =  66, /* 66  Serial Communication Interface (SERCOM1) */
  SERCOM1_3_IRQn            =  67, /* 67  Serial Communication Interface (SERCOM1) */
  SERCOM1_4_IRQn            =  68, /* 68  Serial Communication Interface (SERCOM1) */
  SERCOM2_6_IRQn            =  69, /* 69  Serial Communication Interface (SERCOM2) */
  SERCOM2_5_IRQn            =  70, /* 70  Serial Communication Interface (SERCOM2) */
  SERCOM2_0_IRQn            =  71, /* 71  Serial Communication Interface (SERCOM2) */
  SERCOM2_1_IRQn            =  72, /* 72  Serial Communication Interface (SERCOM2) */
  SERCOM2_2_IRQn            =  73, /* 73  Serial Communication Interface (SERCOM2) */
  SERCOM2_3_IRQn            =  74, /* 74  Serial Communication Interface (SERCOM2) */
  SERCOM2_4_IRQn            =  75, /* 75  Serial Communication Interface (SERCOM2) */
  SERCOM3_6_IRQn            =  76, /* 76  Serial Communication Interface (SERCOM3) */
  SERCOM3_5_IRQn            =  77, /* 77  Serial Communication Interface (SERCOM3) */
  SERCOM3_0_IRQn            =  78, /* 78  Serial Communication Interface (SERCOM3) */
  SERCOM3_1_IRQn            =  79, /* 79  Serial Communication Interface (SERCOM3) */
  SERCOM3_2_IRQn            =  80, /* 80  Serial Communication Interface (SERCOM3) */
  SERCOM3_3_IRQn            =  81, /* 81  Serial Communication Interface (SERCOM3) */
  SERCOM3_4_IRQn            =  82, /* 82  Serial Communication Interface (SERCOM3) */
  SERCOM4_6_IRQn            =  83, /* 83  Serial Communication Interface (SERCOM4) */
  SERCOM4_5_IRQn            =  84, /* 84  Serial Communication Interface (SERCOM4) */
  SERCOM4_0_IRQn            =  85, /* 85  Serial Communication Interface (SERCOM4) */
  SERCOM4_1_IRQn            =  86, /* 86  Serial Communication Interface (SERCOM4) */
  SERCOM4_2_IRQn            =  87, /* 87  Serial Communication Interface (SERCOM4) */
  SERCOM4_3_IRQn            =  88, /* 88  Serial Communication Interface (SERCOM4) */
  SERCOM4_4_IRQn            =  89, /* 89  Serial Communication Interface (SERCOM4) */
  SERCOM5_6_IRQn            =  90, /* 90  Serial Communication Interface (SERCOM5) */
  SERCOM5_5_IRQn            =  91, /* 91  Serial Communication Interface (SERCOM5) */
  SERCOM5_0_IRQn            =  92, /* 92  Serial Communication Interface (SERCOM5) */
  SERCOM5_1_IRQn            =  93, /* 93  Serial Communication Interface (SERCOM5) */
  SERCOM5_2_IRQn            =  94, /* 94  Serial Communication Interface (SERCOM5) */
  SERCOM5_3_IRQn            =  95, /* 95  Serial Communication Interface (SERCOM5) */
  SERCOM5_4_IRQn            =  96, /* 96  Serial Communication Interface (SERCOM5) */
  SERCOM6_6_IRQn            =  97, /* 97  Serial Communication Interface (SERCOM6) */
  SERCOM6_5_IRQn            =  98, /* 98  Serial Communication Interface (SERCOM6) */
  SERCOM6_0_IRQn            =  99, /* 99  Serial Communication Interface (SERCOM6) */
  SERCOM6_1_IRQn            = 100, /* 100 Serial Communication Interface (SERCOM6) */
  SERCOM6_2_IRQn            = 101, /* 101 Serial Communication Interface (SERCOM6) */
  SERCOM6_3_IRQn            = 102, /* 102 Serial Communication Interface (SERCOM6) */
  SERCOM6_4_IRQn            = 103, /* 103 Serial Communication Interface (SERCOM6) */
  SERCOM7_6_IRQn            = 104, /* 104 Serial Communication Interface (SERCOM7) */
  SERCOM7_5_IRQn            = 105, /* 105 Serial Communication Interface (SERCOM7) */
  SERCOM7_0_IRQn            = 106, /* 106 Serial Communication Interface (SERCOM7) */
  SERCOM7_1_IRQn            = 107, /* 107 Serial Communication Interface (SERCOM7) */
  SERCOM7_2_IRQn            = 108, /* 108 Serial Communication Interface (SERCOM7) */
  SERCOM7_3_IRQn            = 109, /* 109 Serial Communication Interface (SERCOM7) */
  SERCOM7_4_IRQn            = 110, /* 110 Serial Communication Interface (SERCOM7) */
  SERCOM8_6_IRQn            = 111, /* 111 Serial Communication Interface (SERCOM8) */
  SERCOM8_5_IRQn            = 112, /* 112 Serial Communication Interface (SERCOM8) */
  SERCOM8_0_IRQn            = 113, /* 113 Serial Communication Interface (SERCOM8) */
  SERCOM8_1_IRQn            = 114, /* 114 Serial Communication Interface (SERCOM8) */
  SERCOM8_2_IRQn            = 115, /* 115 Serial Communication Interface (SERCOM8) */
  SERCOM8_3_IRQn            = 116, /* 116 Serial Communication Interface (SERCOM8) */
  SERCOM8_4_IRQn            = 117, /* 117 Serial Communication Interface (SERCOM8) */
  SERCOM9_6_IRQn            = 118, /* 118 Serial Communication Interface (SERCOM9) */
  SERCOM9_5_IRQn            = 119, /* 119 Serial Communication Interface (SERCOM9) */
  SERCOM9_0_IRQn            = 120, /* 120 Serial Communication Interface (SERCOM9) */
  SERCOM9_1_IRQn            = 121, /* 121 Serial Communication Interface (SERCOM9) */
  SERCOM9_2_IRQn            = 122, /* 122 Serial Communication Interface (SERCOM9) */
  SERCOM9_3_IRQn            = 123, /* 123 Serial Communication Interface (SERCOM9) */
  SERCOM9_4_IRQn            = 124, /* 124 Serial Communication Interface (SERCOM9) */
  TCC0_OTHER_IRQn           = 125, /* 125 Timer Counter for Control Applications (TCC0) */
  TCC0_CNT_TRIG_IRQn        = 126, /* 126 Timer Counter for Control Applications (TCC0) */
  TCC0_MC0_IRQn             = 127, /* 127 Timer Counter for Control Applications (TCC0) */
  TCC0_MC1_IRQn             = 128, /* 128 Timer Counter for Control Applications (TCC0) */
  TCC0_MC2_IRQn             = 129, /* 129 Timer Counter for Control Applications (TCC0) */
  TCC0_MC3_IRQn             = 130, /* 130 Timer Counter for Control Applications (TCC0) */
  TCC0_MC4_IRQn             = 131, /* 131 Timer Counter for Control Applications (TCC0) */
  TCC0_MC5_IRQn             = 132, /* 132 Timer Counter for Control Applications (TCC0) */
  TCC0_MC6_IRQn             = 133, /* 133 Timer Counter for Control Applications (TCC0) */
  TCC0_MC7_IRQn             = 134, /* 134 Timer Counter for Control Applications (TCC0) */
  TCC1_OTHER_IRQn           = 135, /* 135 Timer Counter for Control Applications (TCC1) */
  TCC1_CNT_TRIG_IRQn        = 136, /* 136 Timer Counter for Control Applications (TCC1) */
  TCC1_MC0_IRQn             = 137, /* 137 Timer Counter for Control Applications (TCC1) */
  TCC1_MC1_IRQn             = 138, /* 138 Timer Counter for Control Applications (TCC1) */
  TCC1_MC2_IRQn             = 139, /* 139 Timer Counter for Control Applications (TCC1) */
  TCC1_MC3_IRQn             = 140, /* 140 Timer Counter for Control Applications (TCC1) */
  TCC1_MC4_IRQn             = 141, /* 141 Timer Counter for Control Applications (TCC1) */
  TCC1_MC5_IRQn             = 142, /* 142 Timer Counter for Control Applications (TCC1) */
  TCC1_MC6_IRQn             = 143, /* 143 Timer Counter for Control Applications (TCC1) */
  TCC1_MC7_IRQn             = 144, /* 144 Timer Counter for Control Applications (TCC1) */
  TCC2_OTHER_IRQn           = 145, /* 145 Timer Counter for Control Applications (TCC2) */
  TCC2_CNT_TRIG_IRQn        = 146, /* 146 Timer Counter for Control Applications (TCC2) */
  TCC2_MC0_IRQn             = 147, /* 147 Timer Counter for Control Applications (TCC2) */
  TCC2_MC1_IRQn             = 148, /* 148 Timer Counter for Control Applications (TCC2) */
  TCC2_MC2_IRQn             = 149, /* 149 Timer Counter for Control Applications (TCC2) */
  TCC2_MC3_IRQn             = 150, /* 150 Timer Counter for Control Applications (TCC2) */
  TCC2_MC4_IRQn             = 151, /* 151 Timer Counter for Control Applications (TCC2) */
  TCC2_MC5_IRQn             = 152, /* 152 Timer Counter for Control Applications (TCC2) */
  TCC3_OTHER_IRQn           = 153, /* 153 Timer Counter for Control Applications (TCC3) */
  TCC3_CNT_TRIG_IRQn        = 154, /* 154 Timer Counter for Control Applications (TCC3) */
  TCC3_MC0_IRQn             = 155, /* 155 Timer Counter for Control Applications (TCC3) */
  TCC3_MC1_IRQn             = 156, /* 156 Timer Counter for Control Applications (TCC3) */
  TCC4_OTHER_IRQn           = 157, /* 157 Timer Counter for Control Applications (TCC4) */
  TCC4_CNT_TRIG_IRQn        = 158, /* 158 Timer Counter for Control Applications (TCC4) */
  TCC4_MC0_IRQn             = 159, /* 159 Timer Counter for Control Applications (TCC4) */
  TCC4_MC1_IRQn             = 160, /* 160 Timer Counter for Control Applications (TCC4) */
  TCC5_OTHER_IRQn           = 161, /* 161 Timer Counter for Control Applications (TCC5) */
  TCC5_CNT_TRIG_IRQn        = 162, /* 162 Timer Counter for Control Applications (TCC5) */
  TCC5_MC0_IRQn             = 163, /* 163 Timer Counter for Control Applications (TCC5) */
  TCC5_MC1_IRQn             = 164, /* 164 Timer Counter for Control Applications (TCC5) */
  TCC6_OTHER_IRQn           = 165, /* 165 Timer Counter for Control Applications (TCC6) */
  TCC6_CNT_TRIG_IRQn        = 166, /* 166 Timer Counter for Control Applications (TCC6) */
  TCC6_MC0_IRQn             = 167, /* 167 Timer Counter for Control Applications (TCC6) */
  TCC6_MC1_IRQn             = 168, /* 168 Timer Counter for Control Applications (TCC6) */
  TCC7_OTHER_IRQn           = 169, /* 169 Timer Counter for Control Applications (TCC7) */
  TCC7_CNT_TRIG_IRQn        = 170, /* 170 Timer Counter for Control Applications (TCC7) */
  TCC7_MC0_IRQn             = 171, /* 171 Timer Counter for Control Applications (TCC7) */
  TCC7_MC1_IRQn             = 172, /* 172 Timer Counter for Control Applications (TCC7) */
  TCC8_OTHER_IRQn           = 173, /* 173 Timer Counter for Control Applications (TCC8) */
  TCC8_CNT_TRIG_IRQn        = 174, /* 174 Timer Counter for Control Applications (TCC8) */
  TCC8_MC0_IRQn             = 175, /* 175 Timer Counter for Control Applications (TCC8) */
  TCC8_MC1_IRQn             = 176, /* 176 Timer Counter for Control Applications (TCC8) */
  TCC9_OTHER_IRQn           = 177, /* 177 Timer Counter for Control Applications (TCC9) */
  TCC9_CNT_TRIG_IRQn        = 178, /* 178 Timer Counter for Control Applications (TCC9) */
  TCC9_MC0_IRQn             = 179, /* 179 Timer Counter for Control Applications (TCC9) */
  TCC9_MC1_IRQn             = 180, /* 180 Timer Counter for Control Applications (TCC9) */
  TCC9_MC2_IRQn             = 181, /* 181 Timer Counter for Control Applications (TCC9) */
  TCC9_MC3_IRQn             = 182, /* 182 Timer Counter for Control Applications (TCC9) */
  TCC9_MC4_IRQn             = 183, /* 183 Timer Counter for Control Applications (TCC9) */
  TCC9_MC5_IRQn             = 184, /* 184 Timer Counter for Control Applications (TCC9) */
  ADC_GLOBAL_IRQn           = 185, /* 185 ADC Controller (ADC)                */
  ADC_CORE1_IRQn            = 186, /* 186 ADC Controller (ADC)                */
  ADC_CORE2_IRQn            = 187, /* 187 ADC Controller (ADC)                */
  ADC_CORE3_IRQn            = 188, /* 188 ADC Controller (ADC)                */
  ADC_CORE4_IRQn            = 189, /* 189 ADC Controller (ADC)                */
  AC_IRQn                   = 190, /* 190 Analog Comparator Controller (AC)   */
  PTC_IRQn                  = 191, /* 191 Peripheral Touch Controller (PTC)   */
  SPI_IXS0_IRQn             = 192, /* 192 Audio SPI with 8 channels compatibilty (SPI_IXS0) */
  SPI_IXS1_IRQn             = 193, /* 193 Audio SPI with 8 channels compatibilty (SPI_IXS1) */
  CAN0_IRQn                 = 194, /* 194 Control Area Network (CAN0)         */
  CAN1_IRQn                 = 195, /* 195 Control Area Network (CAN1)         */
  CAN2_IRQn                 = 196, /* 196 Control Area Network (CAN2)         */
  CAN3_IRQn                 = 197, /* 197 Control Area Network (CAN3)         */
  CAN4_IRQn                 = 198, /* 198 Control Area Network (CAN4)         */
  CAN5_IRQn                 = 199, /* 199 Control Area Network (CAN5)         */
  ETH_PRI_Q_0_IRQn          = 202, /* 202 Ethernet Controller (ETH)           */
  ETH_PRI_Q_1_IRQn          = 203, /* 203 Ethernet Controller (ETH)           */
  ETH_PRI_Q_2_IRQn          = 204, /* 204 Ethernet Controller (ETH)           */
  ETH_PRI_Q_3_IRQn          = 205, /* 205 Ethernet Controller (ETH)           */
  ETH_PRI_Q_4_IRQn          = 206, /* 206 Ethernet Controller (ETH)           */
  ETH_PRI_Q_5_IRQn          = 207, /* 207 Ethernet Controller (ETH)           */
  SQI0_IRQn                 = 208, /* 208 Polaris Serial Quad Interface SIB (SQI0) */
  SQI1_IRQn                 = 209, /* 209 Polaris Serial Quad Interface SIB (SQI1) */
  TRNG_IRQn                 = 210, /* 210 True Random Generator (TRNG)        */
  SDMMC0_IRQn               = 211, /* 211 SD/MMC Host Controller (SDMMC0)     */
  SDMMC1_IRQn               = 212, /* 212 SD/MMC Host Controller (SDMMC1)     */
  USBHS0_IRQn               = 213, /* 213 USB High Speed (USBHS0)             */
  USBHS1_IRQn               = 214, /* 214 USB High Speed (USBHS1)             */
  MLB_GENERAL_IRQn          = 218, /* 218 Media Local Bus (MLB)               */
  MLB_BUSREQ_IRQn           = 219, /* 219 Media Local Bus (MLB)               */
  CM7H_CTIIRQ_0_IRQn        = 220, /* 220 CM7H_CTIIRQ_0 (CM7H)                */
  CM7H_CTIIRQ_1_IRQn        = 221, /* 221 CM7H_CTIIRQ_1 (CM7H)                */

  PERIPH_MAX_IRQn           = 221  /* Max peripheral ID */
} IRQn_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef struct _DeviceVectors
{
  /* Stack pointer */
  void* pvStack;
  /* CORTEX-M7 handlers */
  void* pfnReset_Handler;                        /* -15 Reset Vector, invoked on Power up and warm reset */
  void* pfnNonMaskableInt_Handler;               /* -14 Non maskable Interrupt, cannot be stopped or preempted */
  void* pfnHardFault_Handler;                    /* -13 Hard Fault, all classes of Fault */
  void* pfnMemoryManagement_Handler;             /* -12 Memory Management, MPU mismatch, including Access Violation and No Match */
  void* pfnBusFault_Handler;                     /* -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
  void* pfnUsageFault_Handler;                   /* -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition */
  void* pvReservedC9;
  void* pvReservedC8;
  void* pvReservedC7;
  void* pvReservedC6;
  void* pfnSVCall_Handler;                       /*  -5 System Service Call via SVC instruction */
  void* pfnDebugMonitor_Handler;                 /*  -4 Debug Monitor */
  void* pvReservedC3;
  void* pfnPendSV_Handler;                       /*  -2 Pendable request for system service */
  void* pfnSysTick_Handler;                      /*  -1 System Tick Timer */

  /* Peripheral handlers */
  void* pfnFCW_Handler;                          /*   0 Flash Write Control (FCW) (FCW) */
  void* pfnFCR_ECCERR_Handler;                   /*   1 Flash Read Controller (FCR) (FCR) */
  void* pfnFCR_CRC_FAULT_Handler;                /*   2 Flash Read Controller (FCR) (FCR) */
  void* pfnPM_Handler;                           /*   3 Power Manager (PM) */
  void* pfnSUPC_Handler;                         /*   4 Supply Controller (SUPC) */
  void* pfnOSCCTRL_FAIL_Handler;                 /*   5 Oscillators Control (OSCCTRL) */
  void* pfnOSCCTRL_XOSCRDY_Handler;              /*   6 Oscillators Control (OSCCTRL) */
  void* pfnOSCCTRL_DFLLRDY_Handler;              /*   7 Oscillators Control (OSCCTRL) */
  void* pfnOSCCTRL_OTHER_Handler;                /*   8 Oscillators Control (OSCCTRL) */
  void* pfnOSCCTRL_LOCK_Handler;                 /*   9 Oscillators Control (OSCCTRL) */
  void* pfnOSC32KCTRL_FAIL_Handler;              /*  10 32kHz Oscillators Control (OSC32KCTRL) */
  void* pfnOSC32KCTRL_RDY_Handler;               /*  11 32kHz Oscillators Control (OSC32KCTRL) */
  void* pfnMCLK_Handler;                         /*  12 Main Clock (MCLK) */
  void* pfnFREQM_Handler;                        /*  13 Frequency Meter (FREQM) */
  void* pfnWDT_Handler;                          /*  14 Watchdog Timer (WDT) */
  void* pfnRTC_TAMPER_Handler;                   /*  15 Real-Time Counter (RTC) */
  void* pfnRTC_OVF_Handler;                      /*  16 Real-Time Counter (RTC) */
  void* pfnRTC_PERIOD_Handler;                   /*  17 Real-Time Counter (RTC) */
  void* pfnRTC_COMPARE_Handler;                  /*  18 Real-Time Counter (RTC) */
  void* pfnEIC_EXTINT_0_Handler;                 /*  19 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_1_Handler;                 /*  20 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_2_Handler;                 /*  21 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_3_Handler;                 /*  22 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_4_Handler;                 /*  23 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_5_Handler;                 /*  24 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_6_Handler;                 /*  25 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_7_Handler;                 /*  26 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_8_Handler;                 /*  27 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_9_Handler;                 /*  28 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_10_Handler;                /*  29 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_11_Handler;                /*  30 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_12_Handler;                /*  31 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_13_Handler;                /*  32 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_14_Handler;                /*  33 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_15_Handler;                /*  34 External Interrupt Controller (EIC) */
  void* pfnPAC_Handler;                          /*  35 Peripheral Access Controller (PAC) */
  void* pfnDRMTCM_Handler;                       /*  36 DRM TCM ECC (DRMTCM) */
  void* pfnMCRAMC_Handler;                       /*  37 Multi-Channel RAM Controller (MCRAMC) */
  void* pfnTRAM_Handler;                         /*  38 TrustRAM (TRAM) */
  void* pfnDMA_PRI3_Handler;                     /*  39 Direct Memory Access Controller (DMA) */
  void* pfnDMA_PRI2_Handler;                     /*  40 Direct Memory Access Controller (DMA) */
  void* pfnDMA_PRI1_Handler;                     /*  41 Direct Memory Access Controller (DMA) */
  void* pfnDMA_PRI0_Handler;                     /*  42 Direct Memory Access Controller (DMA) */
  void* pfnEVSYS_0_Handler;                      /*  43 Event System Interface (EVSYS) */
  void* pfnEVSYS_1_Handler;                      /*  44 Event System Interface (EVSYS) */
  void* pfnEVSYS_2_Handler;                      /*  45 Event System Interface (EVSYS) */
  void* pfnEVSYS_3_Handler;                      /*  46 Event System Interface (EVSYS) */
  void* pfnEVSYS_4_Handler;                      /*  47 Event System Interface (EVSYS) */
  void* pfnEVSYS_5_Handler;                      /*  48 Event System Interface (EVSYS) */
  void* pfnEVSYS_6_Handler;                      /*  49 Event System Interface (EVSYS) */
  void* pfnEVSYS_7_Handler;                      /*  50 Event System Interface (EVSYS) */
  void* pfnEVSYS_8_Handler;                      /*  51 Event System Interface (EVSYS) */
  void* pfnEVSYS_9_Handler;                      /*  52 Event System Interface (EVSYS) */
  void* pfnEVSYS_10_Handler;                     /*  53 Event System Interface (EVSYS) */
  void* pfnEVSYS_11_Handler;                     /*  54 Event System Interface (EVSYS) */
  void* pfnSERCOM0_6_Handler;                    /*  55 Serial Communication Interface (SERCOM0) */
  void* pfnSERCOM0_5_Handler;                    /*  56 Serial Communication Interface (SERCOM0) */
  void* pfnSERCOM0_0_Handler;                    /*  57 Serial Communication Interface (SERCOM0) */
  void* pfnSERCOM0_1_Handler;                    /*  58 Serial Communication Interface (SERCOM0) */
  void* pfnSERCOM0_2_Handler;                    /*  59 Serial Communication Interface (SERCOM0) */
  void* pfnSERCOM0_3_Handler;                    /*  60 Serial Communication Interface (SERCOM0) */
  void* pfnSERCOM0_4_Handler;                    /*  61 Serial Communication Interface (SERCOM0) */
  void* pfnSERCOM1_6_Handler;                    /*  62 Serial Communication Interface (SERCOM1) */
  void* pfnSERCOM1_5_Handler;                    /*  63 Serial Communication Interface (SERCOM1) */
  void* pfnSERCOM1_0_Handler;                    /*  64 Serial Communication Interface (SERCOM1) */
  void* pfnSERCOM1_1_Handler;                    /*  65 Serial Communication Interface (SERCOM1) */
  void* pfnSERCOM1_2_Handler;                    /*  66 Serial Communication Interface (SERCOM1) */
  void* pfnSERCOM1_3_Handler;                    /*  67 Serial Communication Interface (SERCOM1) */
  void* pfnSERCOM1_4_Handler;                    /*  68 Serial Communication Interface (SERCOM1) */
  void* pfnSERCOM2_6_Handler;                    /*  69 Serial Communication Interface (SERCOM2) */
  void* pfnSERCOM2_5_Handler;                    /*  70 Serial Communication Interface (SERCOM2) */
  void* pfnSERCOM2_0_Handler;                    /*  71 Serial Communication Interface (SERCOM2) */
  void* pfnSERCOM2_1_Handler;                    /*  72 Serial Communication Interface (SERCOM2) */
  void* pfnSERCOM2_2_Handler;                    /*  73 Serial Communication Interface (SERCOM2) */
  void* pfnSERCOM2_3_Handler;                    /*  74 Serial Communication Interface (SERCOM2) */
  void* pfnSERCOM2_4_Handler;                    /*  75 Serial Communication Interface (SERCOM2) */
  void* pfnSERCOM3_6_Handler;                    /*  76 Serial Communication Interface (SERCOM3) */
  void* pfnSERCOM3_5_Handler;                    /*  77 Serial Communication Interface (SERCOM3) */
  void* pfnSERCOM3_0_Handler;                    /*  78 Serial Communication Interface (SERCOM3) */
  void* pfnSERCOM3_1_Handler;                    /*  79 Serial Communication Interface (SERCOM3) */
  void* pfnSERCOM3_2_Handler;                    /*  80 Serial Communication Interface (SERCOM3) */
  void* pfnSERCOM3_3_Handler;                    /*  81 Serial Communication Interface (SERCOM3) */
  void* pfnSERCOM3_4_Handler;                    /*  82 Serial Communication Interface (SERCOM3) */
  void* pfnSERCOM4_6_Handler;                    /*  83 Serial Communication Interface (SERCOM4) */
  void* pfnSERCOM4_5_Handler;                    /*  84 Serial Communication Interface (SERCOM4) */
  void* pfnSERCOM4_0_Handler;                    /*  85 Serial Communication Interface (SERCOM4) */
  void* pfnSERCOM4_1_Handler;                    /*  86 Serial Communication Interface (SERCOM4) */
  void* pfnSERCOM4_2_Handler;                    /*  87 Serial Communication Interface (SERCOM4) */
  void* pfnSERCOM4_3_Handler;                    /*  88 Serial Communication Interface (SERCOM4) */
  void* pfnSERCOM4_4_Handler;                    /*  89 Serial Communication Interface (SERCOM4) */
  void* pfnSERCOM5_6_Handler;                    /*  90 Serial Communication Interface (SERCOM5) */
  void* pfnSERCOM5_5_Handler;                    /*  91 Serial Communication Interface (SERCOM5) */
  void* pfnSERCOM5_0_Handler;                    /*  92 Serial Communication Interface (SERCOM5) */
  void* pfnSERCOM5_1_Handler;                    /*  93 Serial Communication Interface (SERCOM5) */
  void* pfnSERCOM5_2_Handler;                    /*  94 Serial Communication Interface (SERCOM5) */
  void* pfnSERCOM5_3_Handler;                    /*  95 Serial Communication Interface (SERCOM5) */
  void* pfnSERCOM5_4_Handler;                    /*  96 Serial Communication Interface (SERCOM5) */
  void* pfnSERCOM6_6_Handler;                    /*  97 Serial Communication Interface (SERCOM6) */
  void* pfnSERCOM6_5_Handler;                    /*  98 Serial Communication Interface (SERCOM6) */
  void* pfnSERCOM6_0_Handler;                    /*  99 Serial Communication Interface (SERCOM6) */
  void* pfnSERCOM6_1_Handler;                    /* 100 Serial Communication Interface (SERCOM6) */
  void* pfnSERCOM6_2_Handler;                    /* 101 Serial Communication Interface (SERCOM6) */
  void* pfnSERCOM6_3_Handler;                    /* 102 Serial Communication Interface (SERCOM6) */
  void* pfnSERCOM6_4_Handler;                    /* 103 Serial Communication Interface (SERCOM6) */
  void* pfnSERCOM7_6_Handler;                    /* 104 Serial Communication Interface (SERCOM7) */
  void* pfnSERCOM7_5_Handler;                    /* 105 Serial Communication Interface (SERCOM7) */
  void* pfnSERCOM7_0_Handler;                    /* 106 Serial Communication Interface (SERCOM7) */
  void* pfnSERCOM7_1_Handler;                    /* 107 Serial Communication Interface (SERCOM7) */
  void* pfnSERCOM7_2_Handler;                    /* 108 Serial Communication Interface (SERCOM7) */
  void* pfnSERCOM7_3_Handler;                    /* 109 Serial Communication Interface (SERCOM7) */
  void* pfnSERCOM7_4_Handler;                    /* 110 Serial Communication Interface (SERCOM7) */
  void* pfnSERCOM8_6_Handler;                    /* 111 Serial Communication Interface (SERCOM8) */
  void* pfnSERCOM8_5_Handler;                    /* 112 Serial Communication Interface (SERCOM8) */
  void* pfnSERCOM8_0_Handler;                    /* 113 Serial Communication Interface (SERCOM8) */
  void* pfnSERCOM8_1_Handler;                    /* 114 Serial Communication Interface (SERCOM8) */
  void* pfnSERCOM8_2_Handler;                    /* 115 Serial Communication Interface (SERCOM8) */
  void* pfnSERCOM8_3_Handler;                    /* 116 Serial Communication Interface (SERCOM8) */
  void* pfnSERCOM8_4_Handler;                    /* 117 Serial Communication Interface (SERCOM8) */
  void* pfnSERCOM9_6_Handler;                    /* 118 Serial Communication Interface (SERCOM9) */
  void* pfnSERCOM9_5_Handler;                    /* 119 Serial Communication Interface (SERCOM9) */
  void* pfnSERCOM9_0_Handler;                    /* 120 Serial Communication Interface (SERCOM9) */
  void* pfnSERCOM9_1_Handler;                    /* 121 Serial Communication Interface (SERCOM9) */
  void* pfnSERCOM9_2_Handler;                    /* 122 Serial Communication Interface (SERCOM9) */
  void* pfnSERCOM9_3_Handler;                    /* 123 Serial Communication Interface (SERCOM9) */
  void* pfnSERCOM9_4_Handler;                    /* 124 Serial Communication Interface (SERCOM9) */
  void* pfnTCC0_OTHER_Handler;                   /* 125 Timer Counter for Control Applications (TCC0) */
  void* pfnTCC0_CNT_TRIG_Handler;                /* 126 Timer Counter for Control Applications (TCC0) */
  void* pfnTCC0_MC0_Handler;                     /* 127 Timer Counter for Control Applications (TCC0) */
  void* pfnTCC0_MC1_Handler;                     /* 128 Timer Counter for Control Applications (TCC0) */
  void* pfnTCC0_MC2_Handler;                     /* 129 Timer Counter for Control Applications (TCC0) */
  void* pfnTCC0_MC3_Handler;                     /* 130 Timer Counter for Control Applications (TCC0) */
  void* pfnTCC0_MC4_Handler;                     /* 131 Timer Counter for Control Applications (TCC0) */
  void* pfnTCC0_MC5_Handler;                     /* 132 Timer Counter for Control Applications (TCC0) */
  void* pfnTCC0_MC6_Handler;                     /* 133 Timer Counter for Control Applications (TCC0) */
  void* pfnTCC0_MC7_Handler;                     /* 134 Timer Counter for Control Applications (TCC0) */
  void* pfnTCC1_OTHER_Handler;                   /* 135 Timer Counter for Control Applications (TCC1) */
  void* pfnTCC1_CNT_TRIG_Handler;                /* 136 Timer Counter for Control Applications (TCC1) */
  void* pfnTCC1_MC0_Handler;                     /* 137 Timer Counter for Control Applications (TCC1) */
  void* pfnTCC1_MC1_Handler;                     /* 138 Timer Counter for Control Applications (TCC1) */
  void* pfnTCC1_MC2_Handler;                     /* 139 Timer Counter for Control Applications (TCC1) */
  void* pfnTCC1_MC3_Handler;                     /* 140 Timer Counter for Control Applications (TCC1) */
  void* pfnTCC1_MC4_Handler;                     /* 141 Timer Counter for Control Applications (TCC1) */
  void* pfnTCC1_MC5_Handler;                     /* 142 Timer Counter for Control Applications (TCC1) */
  void* pfnTCC1_MC6_Handler;                     /* 143 Timer Counter for Control Applications (TCC1) */
  void* pfnTCC1_MC7_Handler;                     /* 144 Timer Counter for Control Applications (TCC1) */
  void* pfnTCC2_OTHER_Handler;                   /* 145 Timer Counter for Control Applications (TCC2) */
  void* pfnTCC2_CNT_TRIG_Handler;                /* 146 Timer Counter for Control Applications (TCC2) */
  void* pfnTCC2_MC0_Handler;                     /* 147 Timer Counter for Control Applications (TCC2) */
  void* pfnTCC2_MC1_Handler;                     /* 148 Timer Counter for Control Applications (TCC2) */
  void* pfnTCC2_MC2_Handler;                     /* 149 Timer Counter for Control Applications (TCC2) */
  void* pfnTCC2_MC3_Handler;                     /* 150 Timer Counter for Control Applications (TCC2) */
  void* pfnTCC2_MC4_Handler;                     /* 151 Timer Counter for Control Applications (TCC2) */
  void* pfnTCC2_MC5_Handler;                     /* 152 Timer Counter for Control Applications (TCC2) */
  void* pfnTCC3_OTHER_Handler;                   /* 153 Timer Counter for Control Applications (TCC3) */
  void* pfnTCC3_CNT_TRIG_Handler;                /* 154 Timer Counter for Control Applications (TCC3) */
  void* pfnTCC3_MC0_Handler;                     /* 155 Timer Counter for Control Applications (TCC3) */
  void* pfnTCC3_MC1_Handler;                     /* 156 Timer Counter for Control Applications (TCC3) */
  void* pfnTCC4_OTHER_Handler;                   /* 157 Timer Counter for Control Applications (TCC4) */
  void* pfnTCC4_CNT_TRIG_Handler;                /* 158 Timer Counter for Control Applications (TCC4) */
  void* pfnTCC4_MC0_Handler;                     /* 159 Timer Counter for Control Applications (TCC4) */
  void* pfnTCC4_MC1_Handler;                     /* 160 Timer Counter for Control Applications (TCC4) */
  void* pfnTCC5_OTHER_Handler;                   /* 161 Timer Counter for Control Applications (TCC5) */
  void* pfnTCC5_CNT_TRIG_Handler;                /* 162 Timer Counter for Control Applications (TCC5) */
  void* pfnTCC5_MC0_Handler;                     /* 163 Timer Counter for Control Applications (TCC5) */
  void* pfnTCC5_MC1_Handler;                     /* 164 Timer Counter for Control Applications (TCC5) */
  void* pfnTCC6_OTHER_Handler;                   /* 165 Timer Counter for Control Applications (TCC6) */
  void* pfnTCC6_CNT_TRIG_Handler;                /* 166 Timer Counter for Control Applications (TCC6) */
  void* pfnTCC6_MC0_Handler;                     /* 167 Timer Counter for Control Applications (TCC6) */
  void* pfnTCC6_MC1_Handler;                     /* 168 Timer Counter for Control Applications (TCC6) */
  void* pfnTCC7_OTHER_Handler;                   /* 169 Timer Counter for Control Applications (TCC7) */
  void* pfnTCC7_CNT_TRIG_Handler;                /* 170 Timer Counter for Control Applications (TCC7) */
  void* pfnTCC7_MC0_Handler;                     /* 171 Timer Counter for Control Applications (TCC7) */
  void* pfnTCC7_MC1_Handler;                     /* 172 Timer Counter for Control Applications (TCC7) */
  void* pfnTCC8_OTHER_Handler;                   /* 173 Timer Counter for Control Applications (TCC8) */
  void* pfnTCC8_CNT_TRIG_Handler;                /* 174 Timer Counter for Control Applications (TCC8) */
  void* pfnTCC8_MC0_Handler;                     /* 175 Timer Counter for Control Applications (TCC8) */
  void* pfnTCC8_MC1_Handler;                     /* 176 Timer Counter for Control Applications (TCC8) */
  void* pfnTCC9_OTHER_Handler;                   /* 177 Timer Counter for Control Applications (TCC9) */
  void* pfnTCC9_CNT_TRIG_Handler;                /* 178 Timer Counter for Control Applications (TCC9) */
  void* pfnTCC9_MC0_Handler;                     /* 179 Timer Counter for Control Applications (TCC9) */
  void* pfnTCC9_MC1_Handler;                     /* 180 Timer Counter for Control Applications (TCC9) */
  void* pfnTCC9_MC2_Handler;                     /* 181 Timer Counter for Control Applications (TCC9) */
  void* pfnTCC9_MC3_Handler;                     /* 182 Timer Counter for Control Applications (TCC9) */
  void* pfnTCC9_MC4_Handler;                     /* 183 Timer Counter for Control Applications (TCC9) */
  void* pfnTCC9_MC5_Handler;                     /* 184 Timer Counter for Control Applications (TCC9) */
  void* pfnADC_GLOBAL_Handler;                   /* 185 ADC Controller (ADC) */
  void* pfnADC_CORE1_Handler;                    /* 186 ADC Controller (ADC) */
  void* pfnADC_CORE2_Handler;                    /* 187 ADC Controller (ADC) */
  void* pfnADC_CORE3_Handler;                    /* 188 ADC Controller (ADC) */
  void* pfnADC_CORE4_Handler;                    /* 189 ADC Controller (ADC) */
  void* pfnAC_Handler;                           /* 190 Analog Comparator Controller (AC) */
  void* pfnPTC_Handler;                          /* 191 Peripheral Touch Controller (PTC) */
  void* pfnSPI_IXS0_Handler;                     /* 192 Audio SPI with 8 channels compatibilty (SPI_IXS0) */
  void* pfnSPI_IXS1_Handler;                     /* 193 Audio SPI with 8 channels compatibilty (SPI_IXS1) */
  void* pfnCAN0_Handler;                         /* 194 Control Area Network (CAN0) */
  void* pfnCAN1_Handler;                         /* 195 Control Area Network (CAN1) */
  void* pfnCAN2_Handler;                         /* 196 Control Area Network (CAN2) */
  void* pfnCAN3_Handler;                         /* 197 Control Area Network (CAN3) */
  void* pfnCAN4_Handler;                         /* 198 Control Area Network (CAN4) */
  void* pfnCAN5_Handler;                         /* 199 Control Area Network (CAN5) */
  void* pvReserved200;
  void* pvReserved201;
  void* pfnETH_PRI_Q_0_Handler;                  /* 202 Ethernet Controller (ETH) */
  void* pfnETH_PRI_Q_1_Handler;                  /* 203 Ethernet Controller (ETH) */
  void* pfnETH_PRI_Q_2_Handler;                  /* 204 Ethernet Controller (ETH) */
  void* pfnETH_PRI_Q_3_Handler;                  /* 205 Ethernet Controller (ETH) */
  void* pfnETH_PRI_Q_4_Handler;                  /* 206 Ethernet Controller (ETH) */
  void* pfnETH_PRI_Q_5_Handler;                  /* 207 Ethernet Controller (ETH) */
  void* pfnSQI0_Handler;                         /* 208 Polaris Serial Quad Interface SIB (SQI0) */
  void* pfnSQI1_Handler;                         /* 209 Polaris Serial Quad Interface SIB (SQI1) */
  void* pfnTRNG_Handler;                         /* 210 True Random Generator (TRNG) */
  void* pfnSDMMC0_Handler;                       /* 211 SD/MMC Host Controller (SDMMC0) */
  void* pfnSDMMC1_Handler;                       /* 212 SD/MMC Host Controller (SDMMC1) */
  void* pfnUSBHS0_Handler;                       /* 213 USB High Speed (USBHS0) */
  void* pfnUSBHS1_Handler;                       /* 214 USB High Speed (USBHS1) */
  void* pvReserved215;
  void* pvReserved216;
  void* pvReserved217;
  void* pfnMLB_GENERAL_Handler;                  /* 218 Media Local Bus (MLB) */
  void* pfnMLB_BUSREQ_Handler;                   /* 219 Media Local Bus (MLB) */
  void* pvReserved220;
  void* pvReserved221;
} DeviceVectors;

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if !defined DONT_USE_PREDEFINED_CORE_HANDLERS
/* CORTEX-M7 exception handlers */
void Reset_Handler                 ( void );
void NonMaskableInt_Handler        ( void );
void HardFault_Handler             ( void );
void MemoryManagement_Handler      ( void );
void BusFault_Handler              ( void );
void UsageFault_Handler            ( void );
void SVCall_Handler                ( void );
void DebugMonitor_Handler          ( void );
void PendSV_Handler                ( void );
void SysTick_Handler               ( void );
#endif /* DONT_USE_PREDEFINED_CORE_HANDLERS */

#if !defined DONT_USE_PREDEFINED_PERIPHERALS_HANDLERS
/* Peripherals interrupt handlers */
void FCW_Handler                   ( void );
void FCR_ECCERR_Handler            ( void );
void FCR_CRC_FAULT_Handler         ( void );
void PM_Handler                    ( void );
void SUPC_Handler                  ( void );
void OSCCTRL_FAIL_Handler          ( void );
void OSCCTRL_XOSCRDY_Handler       ( void );
void OSCCTRL_DFLLRDY_Handler       ( void );
void OSCCTRL_OTHER_Handler         ( void );
void OSCCTRL_LOCK_Handler          ( void );
void OSC32KCTRL_FAIL_Handler       ( void );
void OSC32KCTRL_RDY_Handler        ( void );
void MCLK_Handler                  ( void );
void FREQM_Handler                 ( void );
void WDT_Handler                   ( void );
void RTC_TAMPER_Handler            ( void );
void RTC_OVF_Handler               ( void );
void RTC_PERIOD_Handler            ( void );
void RTC_COMPARE_Handler           ( void );
void EIC_EXTINT_0_Handler          ( void );
void EIC_EXTINT_1_Handler          ( void );
void EIC_EXTINT_2_Handler          ( void );
void EIC_EXTINT_3_Handler          ( void );
void EIC_EXTINT_4_Handler          ( void );
void EIC_EXTINT_5_Handler          ( void );
void EIC_EXTINT_6_Handler          ( void );
void EIC_EXTINT_7_Handler          ( void );
void EIC_EXTINT_8_Handler          ( void );
void EIC_EXTINT_9_Handler          ( void );
void EIC_EXTINT_10_Handler         ( void );
void EIC_EXTINT_11_Handler         ( void );
void EIC_EXTINT_12_Handler         ( void );
void EIC_EXTINT_13_Handler         ( void );
void EIC_EXTINT_14_Handler         ( void );
void EIC_EXTINT_15_Handler         ( void );
void PAC_Handler                   ( void );
void DRMTCM_Handler                ( void );
void MCRAMC_Handler                ( void );
void TRAM_Handler                  ( void );
void DMA_PRI3_Handler              ( void );
void DMA_PRI2_Handler              ( void );
void DMA_PRI1_Handler              ( void );
void DMA_PRI0_Handler              ( void );
void EVSYS_0_Handler               ( void );
void EVSYS_1_Handler               ( void );
void EVSYS_2_Handler               ( void );
void EVSYS_3_Handler               ( void );
void EVSYS_4_Handler               ( void );
void EVSYS_5_Handler               ( void );
void EVSYS_6_Handler               ( void );
void EVSYS_7_Handler               ( void );
void EVSYS_8_Handler               ( void );
void EVSYS_9_Handler               ( void );
void EVSYS_10_Handler              ( void );
void EVSYS_11_Handler              ( void );
void SERCOM0_6_Handler             ( void );
void SERCOM0_5_Handler             ( void );
void SERCOM0_0_Handler             ( void );
void SERCOM0_1_Handler             ( void );
void SERCOM0_2_Handler             ( void );
void SERCOM0_3_Handler             ( void );
void SERCOM0_4_Handler             ( void );
void SERCOM1_6_Handler             ( void );
void SERCOM1_5_Handler             ( void );
void SERCOM1_0_Handler             ( void );
void SERCOM1_1_Handler             ( void );
void SERCOM1_2_Handler             ( void );
void SERCOM1_3_Handler             ( void );
void SERCOM1_4_Handler             ( void );
void SERCOM2_6_Handler             ( void );
void SERCOM2_5_Handler             ( void );
void SERCOM2_0_Handler             ( void );
void SERCOM2_1_Handler             ( void );
void SERCOM2_2_Handler             ( void );
void SERCOM2_3_Handler             ( void );
void SERCOM2_4_Handler             ( void );
void SERCOM3_6_Handler             ( void );
void SERCOM3_5_Handler             ( void );
void SERCOM3_0_Handler             ( void );
void SERCOM3_1_Handler             ( void );
void SERCOM3_2_Handler             ( void );
void SERCOM3_3_Handler             ( void );
void SERCOM3_4_Handler             ( void );
void SERCOM4_6_Handler             ( void );
void SERCOM4_5_Handler             ( void );
void SERCOM4_0_Handler             ( void );
void SERCOM4_1_Handler             ( void );
void SERCOM4_2_Handler             ( void );
void SERCOM4_3_Handler             ( void );
void SERCOM4_4_Handler             ( void );
void SERCOM5_6_Handler             ( void );
void SERCOM5_5_Handler             ( void );
void SERCOM5_0_Handler             ( void );
void SERCOM5_1_Handler             ( void );
void SERCOM5_2_Handler             ( void );
void SERCOM5_3_Handler             ( void );
void SERCOM5_4_Handler             ( void );
void SERCOM6_6_Handler             ( void );
void SERCOM6_5_Handler             ( void );
void SERCOM6_0_Handler             ( void );
void SERCOM6_1_Handler             ( void );
void SERCOM6_2_Handler             ( void );
void SERCOM6_3_Handler             ( void );
void SERCOM6_4_Handler             ( void );
void SERCOM7_6_Handler             ( void );
void SERCOM7_5_Handler             ( void );
void SERCOM7_0_Handler             ( void );
void SERCOM7_1_Handler             ( void );
void SERCOM7_2_Handler             ( void );
void SERCOM7_3_Handler             ( void );
void SERCOM7_4_Handler             ( void );
void SERCOM8_6_Handler             ( void );
void SERCOM8_5_Handler             ( void );
void SERCOM8_0_Handler             ( void );
void SERCOM8_1_Handler             ( void );
void SERCOM8_2_Handler             ( void );
void SERCOM8_3_Handler             ( void );
void SERCOM8_4_Handler             ( void );
void SERCOM9_6_Handler             ( void );
void SERCOM9_5_Handler             ( void );
void SERCOM9_0_Handler             ( void );
void SERCOM9_1_Handler             ( void );
void SERCOM9_2_Handler             ( void );
void SERCOM9_3_Handler             ( void );
void SERCOM9_4_Handler             ( void );
void TCC0_OTHER_Handler            ( void );
void TCC0_CNT_TRIG_Handler         ( void );
void TCC0_MC0_Handler              ( void );
void TCC0_MC1_Handler              ( void );
void TCC0_MC2_Handler              ( void );
void TCC0_MC3_Handler              ( void );
void TCC0_MC4_Handler              ( void );
void TCC0_MC5_Handler              ( void );
void TCC0_MC6_Handler              ( void );
void TCC0_MC7_Handler              ( void );
void TCC1_OTHER_Handler            ( void );
void TCC1_CNT_TRIG_Handler         ( void );
void TCC1_MC0_Handler              ( void );
void TCC1_MC1_Handler              ( void );
void TCC1_MC2_Handler              ( void );
void TCC1_MC3_Handler              ( void );
void TCC1_MC4_Handler              ( void );
void TCC1_MC5_Handler              ( void );
void TCC1_MC6_Handler              ( void );
void TCC1_MC7_Handler              ( void );
void TCC2_OTHER_Handler            ( void );
void TCC2_CNT_TRIG_Handler         ( void );
void TCC2_MC0_Handler              ( void );
void TCC2_MC1_Handler              ( void );
void TCC2_MC2_Handler              ( void );
void TCC2_MC3_Handler              ( void );
void TCC2_MC4_Handler              ( void );
void TCC2_MC5_Handler              ( void );
void TCC3_OTHER_Handler            ( void );
void TCC3_CNT_TRIG_Handler         ( void );
void TCC3_MC0_Handler              ( void );
void TCC3_MC1_Handler              ( void );
void TCC4_OTHER_Handler            ( void );
void TCC4_CNT_TRIG_Handler         ( void );
void TCC4_MC0_Handler              ( void );
void TCC4_MC1_Handler              ( void );
void TCC5_OTHER_Handler            ( void );
void TCC5_CNT_TRIG_Handler         ( void );
void TCC5_MC0_Handler              ( void );
void TCC5_MC1_Handler              ( void );
void TCC6_OTHER_Handler            ( void );
void TCC6_CNT_TRIG_Handler         ( void );
void TCC6_MC0_Handler              ( void );
void TCC6_MC1_Handler              ( void );
void TCC7_OTHER_Handler            ( void );
void TCC7_CNT_TRIG_Handler         ( void );
void TCC7_MC0_Handler              ( void );
void TCC7_MC1_Handler              ( void );
void TCC8_OTHER_Handler            ( void );
void TCC8_CNT_TRIG_Handler         ( void );
void TCC8_MC0_Handler              ( void );
void TCC8_MC1_Handler              ( void );
void TCC9_OTHER_Handler            ( void );
void TCC9_CNT_TRIG_Handler         ( void );
void TCC9_MC0_Handler              ( void );
void TCC9_MC1_Handler              ( void );
void TCC9_MC2_Handler              ( void );
void TCC9_MC3_Handler              ( void );
void TCC9_MC4_Handler              ( void );
void TCC9_MC5_Handler              ( void );
void ADC_GLOBAL_Handler            ( void );
void ADC_CORE1_Handler             ( void );
void ADC_CORE2_Handler             ( void );
void ADC_CORE3_Handler             ( void );
void ADC_CORE4_Handler             ( void );
void AC_Handler                    ( void );
void PTC_Handler                   ( void );
void SPI_IXS0_Handler              ( void );
void SPI_IXS1_Handler              ( void );
void CAN0_Handler                  ( void );
void CAN1_Handler                  ( void );
void CAN2_Handler                  ( void );
void CAN3_Handler                  ( void );
void CAN4_Handler                  ( void );
void CAN5_Handler                  ( void );
void ETH_PRI_Q_0_Handler           ( void );
void ETH_PRI_Q_1_Handler           ( void );
void ETH_PRI_Q_2_Handler           ( void );
void ETH_PRI_Q_3_Handler           ( void );
void ETH_PRI_Q_4_Handler           ( void );
void ETH_PRI_Q_5_Handler           ( void );
void SQI0_Handler                  ( void );
void SQI1_Handler                  ( void );
void TRNG_Handler                  ( void );
void SDMMC0_Handler                ( void );
void SDMMC1_Handler                ( void );
void USBHS0_Handler                ( void );
void USBHS1_Handler                ( void );
void MLB_GENERAL_Handler           ( void );
void MLB_BUSREQ_Handler            ( void );
#endif /* DONT_USE_PREDEFINED_PERIPHERALS_HANDLERS */
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* Configuration of the CORTEX-M7 Processor and Core Peripherals */
#define __CM7_REV                     0x0101 /* Cortex-M7 Revision                                                        */
#define __DCACHE_PRESENT                   1 /* DCACHE present or not                                                     */
#define __DEBUG_LVL                        1 /* Debug Level                                                               */
#define __DTCM_PRESENT                     1 /* DTCM present or not                                                       */
#define __FPU_DP                           1 /* FPU double-precision or not                                               */
#define __FPU_PRESENT                      1 /* FPU present or not                                                        */
#define __ICACHE_PRESENT                   1 /* ICACHE present or not                                                     */
#define __ITCM_PRESENT                     1 /* ITCM present or not                                                       */
#define __MPU_PRESENT                      1 /* MPU present or not                                                        */
#define __NVIC_PRIO_BITS                   3 /* Number of NVIC Priority bits                                              */
#define __TRACE_LVL                        1 /* Trace Level                                                               */
#define __VTOR_PRESENT                     1 /* VTOR present or not                                                       */
#define __Vendor_SysTickConfig             0 /* Set to 1 if different SysTick Config is used                              */
#define __ARCH_ARM                         1
#define __ARCH_ARM_CORTEX_M                1

/* CMSIS includes */
#include "core_cm7.h"
#if defined USE_CMSIS_INIT
#include "system_pic32czca80.h"
#endif /* USE_CMSIS_INIT */

/* ************************************************************************** */
/*   SOFTWARE PERIPHERAL API DEFINITION FOR PIC32CZ8110CA80208                */
/* ************************************************************************** */
#include "component/ac.h"
#include "component/adc.h"
#include "component/can.h"
#include "component/dma.h"
#include "component/drmtcm.h"
#include "component/dsu.h"
#include "component/ebi.h"
#include "component/eic.h"
#include "component/eth.h"
#include "component/evsys.h"
#include "component/fcr.h"
#include "component/fcw.h"
#include "component/freqm.h"
#include "component/fuses.h"
#include "component/gclk.h"
#include "component/mclk.h"
#include "component/mcramc.h"
#include "component/mlb.h"
#include "component/osc32kctrl.h"
#include "component/oscctrl.h"
#include "component/pac.h"
#include "component/pm.h"
#include "component/port.h"
#include "component/prm.h"
#include "component/ptc.h"
#include "component/rstc.h"
#include "component/rtc.h"
#include "component/sdmmc.h"
#include "component/sercom.h"
#include "component/spi_ixs.h"
#include "component/sqi.h"
#include "component/supc.h"
#include "component/tcc.h"
#include "component/tram.h"
#include "component/trng.h"
#include "component/usbhs.h"
#include "component/wdt.h"

/* ************************************************************************** */
/*   INSTANCE DEFINITIONS FOR PIC32CZ8110CA80208 */
/* ************************************************************************** */
#include "instance/ac.h"
#include "instance/adc.h"
#include "instance/can0.h"
#include "instance/can1.h"
#include "instance/can2.h"
#include "instance/can3.h"
#include "instance/can4.h"
#include "instance/can5.h"
#include "instance/dma.h"
#include "instance/drmtcm.h"
#include "instance/dsu.h"
#include "instance/ebi.h"
#include "instance/eic.h"
#include "instance/eth.h"
#include "instance/evsys.h"
#include "instance/fcr.h"
#include "instance/fcw.h"
#include "instance/freqm.h"
#include "instance/fuses.h"
#include "instance/gclk.h"
#include "instance/mclk.h"
#include "instance/mcramc.h"
#include "instance/mlb.h"
#include "instance/osc32kctrl.h"
#include "instance/oscctrl.h"
#include "instance/pac.h"
#include "instance/pm.h"
#include "instance/port.h"
#include "instance/prm.h"
#include "instance/ptc.h"
#include "instance/rstc.h"
#include "instance/rtc.h"
#include "instance/sdmmc0.h"
#include "instance/sdmmc1.h"
#include "instance/sercom0.h"
#include "instance/sercom1.h"
#include "instance/sercom2.h"
#include "instance/sercom3.h"
#include "instance/sercom4.h"
#include "instance/sercom5.h"
#include "instance/sercom6.h"
#include "instance/sercom7.h"
#include "instance/sercom8.h"
#include "instance/sercom9.h"
#include "instance/spi_ixs0.h"
#include "instance/spi_ixs1.h"
#include "instance/sqi0.h"
#include "instance/sqi1.h"
#include "instance/supc.h"
#include "instance/tcc0.h"
#include "instance/tcc1.h"
#include "instance/tcc2.h"
#include "instance/tcc3.h"
#include "instance/tcc4.h"
#include "instance/tcc5.h"
#include "instance/tcc6.h"
#include "instance/tcc7.h"
#include "instance/tcc8.h"
#include "instance/tcc9.h"
#include "instance/tram.h"
#include "instance/trng.h"
#include "instance/usbhs0.h"
#include "instance/usbhs1.h"
#include "instance/wdt.h"

/* ************************************************************************** */
/*  PERIPHERAL ID DEFINITIONS FOR PIC32CZ8110CA80208                          */
/* ************************************************************************** */
#define ID_DSU           (  0) /* Instance index for DSU (DSU) */
#define ID_FCW           (  1) /* Instance index for FCW (FCW) */
#define ID_FCR           (  2) /* Instance index for FCR (FCR) */
#define ID_PM            (  3) /* Instance index for PM (PM) */
#define ID_SUPC          (  4) /* Instance index for SUPC (SUPC) */
#define ID_RSTC          (  5) /* Instance index for RSTC (RSTC) */
#define ID_OSCCTRL       (  6) /* Instance index for OSCCTRL (OSCCTRL) */
#define ID_OSC32KCTRL    (  7) /* Instance index for OSC32KCTRL (OSC32KCTRL) */
#define ID_GCLK          (  8) /* Instance index for GCLK (GCLK) */
#define ID_MCLK          (  9) /* Instance index for MCLK (MCLK) */
#define ID_FREQM         ( 10) /* Instance index for FREQM (FREQM) */
#define ID_WDT           ( 11) /* Instance index for WDT (WDT) */
#define ID_RTC           ( 12) /* Instance index for RTC (RTC) */
#define ID_EIC           ( 13) /* Instance index for EIC (EIC) */
#define ID_PAC           ( 14) /* Instance index for PAC (PAC) */
#define ID_DRMTCM        ( 15) /* Instance index for DRMTCM (DRMTCM) */
#define ID_MCRAMC        ( 16) /* Instance index for MCRAMC (MCRAMC) */
#define ID_TRAM          ( 17) /* Instance index for TRAM (TRAM) */
#define ID_PORT          ( 18) /* Instance index for PORT (PORT) */
#define ID_DMA           ( 19) /* Instance index for DMA (DMA) */
#define ID_PRM           ( 21) /* Instance index for PRM (PRM) */
#define ID_EVSYS         ( 22) /* Instance index for EVSYS (EVSYS) */
#define ID_SERCOM0       ( 23) /* Instance index for SERCOM0 (SERCOM0) */
#define ID_SERCOM1       ( 24) /* Instance index for SERCOM1 (SERCOM1) */
#define ID_SERCOM2       ( 25) /* Instance index for SERCOM2 (SERCOM2) */
#define ID_SERCOM3       ( 26) /* Instance index for SERCOM3 (SERCOM3) */
#define ID_SERCOM4       ( 27) /* Instance index for SERCOM4 (SERCOM4) */
#define ID_SERCOM5       ( 28) /* Instance index for SERCOM5 (SERCOM5) */
#define ID_SERCOM6       ( 29) /* Instance index for SERCOM6 (SERCOM6) */
#define ID_SERCOM7       ( 30) /* Instance index for SERCOM7 (SERCOM7) */
#define ID_SERCOM8       ( 31) /* Instance index for SERCOM8 (SERCOM8) */
#define ID_SERCOM9       ( 32) /* Instance index for SERCOM9 (SERCOM9) */
#define ID_TCC0          ( 33) /* Instance index for TCC0 (TCC0) */
#define ID_TCC1          ( 34) /* Instance index for TCC1 (TCC1) */
#define ID_TCC2          ( 35) /* Instance index for TCC2 (TCC2) */
#define ID_TCC3          ( 36) /* Instance index for TCC3 (TCC3) */
#define ID_TCC4          ( 37) /* Instance index for TCC4 (TCC4) */
#define ID_TCC5          ( 38) /* Instance index for TCC5 (TCC5) */
#define ID_TCC6          ( 39) /* Instance index for TCC6 (TCC6) */
#define ID_TCC7          ( 40) /* Instance index for TCC7 (TCC7) */
#define ID_TCC8          ( 41) /* Instance index for TCC8 (TCC8) */
#define ID_TCC9          ( 42) /* Instance index for TCC9 (TCC9) */
#define ID_ADC           ( 43) /* Instance index for ADC (ADC) */
#define ID_AC            ( 44) /* Instance index for AC (AC) */
#define ID_PTC           ( 45) /* Instance index for PTC (PTC) */
#define ID_SPI_IXS0      ( 46) /* Instance index for SPI_IXS0 (SPI_IXS0) */
#define ID_SPI_IXS1      ( 47) /* Instance index for SPI_IXS1 (SPI_IXS1) */
#define ID_CAN0          ( 48) /* Instance index for CAN0 (CAN0) */
#define ID_CAN1          ( 49) /* Instance index for CAN1 (CAN1) */
#define ID_CAN2          ( 50) /* Instance index for CAN2 (CAN2) */
#define ID_CAN3          ( 51) /* Instance index for CAN3 (CAN3) */
#define ID_CAN4          ( 52) /* Instance index for CAN4 (CAN4) */
#define ID_CAN5          ( 53) /* Instance index for CAN5 (CAN5) */
#define ID_ETH           ( 56) /* Instance index for ETH (ETH) */
#define ID_SQI0          ( 57) /* Instance index for SQI0 (SQI0) */
#define ID_SQI1          ( 58) /* Instance index for SQI1 (SQI1) */
#define ID_TRNG          ( 59) /* Instance index for TRNG (TRNG) */
#define ID_SDMMC0        ( 60) /* Instance index for SDMMC0 (SDMMC0) */
#define ID_SDMMC1        ( 61) /* Instance index for SDMMC1 (SDMMC1) */
#define ID_MLB           ( 66) /* Instance index for MLB (MLB) */

#define ID_PERIPH_MAX    ( 66) /* Number of peripheral IDs */

/* ************************************************************************** */
/*   REGISTER STRUCTURE ADDRESS DEFINITIONS FOR PIC32CZ8110CA80208            */
/* ************************************************************************** */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#define AC_REGS                          ((ac_registers_t*)0x46822000)                 /* AC Registers Address         */
#define ADC_REGS                         ((adc_registers_t*)0x46820000)                /* ADC Registers Address        */
#define CAN0_REGS                        ((can_registers_t*)0x45060000)                /* CAN0 Registers Address       */
#define CAN1_REGS                        ((can_registers_t*)0x46060000)                /* CAN1 Registers Address       */
#define CAN2_REGS                        ((can_registers_t*)0x46062000)                /* CAN2 Registers Address       */
#define CAN3_REGS                        ((can_registers_t*)0x45860000)                /* CAN3 Registers Address       */
#define CAN4_REGS                        ((can_registers_t*)0x45062000)                /* CAN4 Registers Address       */
#define CAN5_REGS                        ((can_registers_t*)0x46860000)                /* CAN5 Registers Address       */
#define DMA_REGS                         ((dma_registers_t*)0x44850000)                /* DMA Registers Address        */
#define DRMTCM_REGS                      ((drmtcm_registers_t*)0x44820000)             /* DRMTCM Registers Address     */
#define DSU_REGS                         ((dsu_registers_t*)0x44000000)                /* DSU Registers Address        */
#define EBI_REGS                         ((ebi_registers_t*)0x458b0000)                /* EBI Registers Address        */
#define EIC_REGS                         ((eic_registers_t*)0x44800000)                /* EIC Registers Address        */
#define ETH_REGS                         ((eth_registers_t*)0x45070000)                /* ETH Registers Address        */
#define EVSYS_REGS                       ((evsys_registers_t*)0x44860000)              /* EVSYS Registers Address      */
#define FCR_REGS                         ((fcr_registers_t*)0x44004000)                /* FCR Registers Address        */
#define FCW_REGS                         ((fcw_registers_t*)0x44002000)                /* FCW Registers Address        */
#define FREQM_REGS                       ((freqm_registers_t*)0x44060000)              /* FREQM Registers Address      */
#define FUSES_BOOTCFG1_REGS              ((fuses_bootcfg1_registers_t*)0x0a002000)     /* FUSES Registers Address      */
#define FUSES_BOOTCFG2_REGS              ((fuses_bootcfg1_registers_t*)0x0a00a000)     /* FUSES Registers Address      */
#define FUSES_CALOTP_REGS                ((fuses_calotp_registers_t*)0x0a007000)       /* FUSES Registers Address      */
#define FUSES_DALCFG_REGS                ((fuses_dalcfg_registers_t*)0x0a004000)       /* FUSES Registers Address      */
#define FUSES_USERCFG1_REGS              ((fuses_usercfg1_registers_t*)0x0a000000)     /* FUSES Registers Address      */
#define FUSES_USERCFG2_REGS              ((fuses_usercfg1_registers_t*)0x0a008000)     /* FUSES Registers Address      */
#define GCLK_REGS                        ((gclk_registers_t*)0x44050000)               /* GCLK Registers Address       */
#define MCLK_REGS                        ((mclk_registers_t*)0x44052000)               /* MCLK Registers Address       */
#define MCRAMC_REGS                      ((mcramc_registers_t*)0x44822000)             /* MCRAMC Registers Address     */
#define MLB_REGS                         ((mlb_registers_t*)0x458c0000)                /* MLB Registers Address        */
#define OSC32KCTRL_REGS                  ((osc32kctrl_registers_t*)0x44042000)         /* OSC32KCTRL Registers Address */
#define OSCCTRL_REGS                     ((oscctrl_registers_t*)0x44040000)            /* OSCCTRL Registers Address    */
#define PAC_REGS                         ((pac_registers_t*)0x44810000)                /* PAC Registers Address        */
#define PM_REGS                          ((pm_registers_t*)0x44010000)                 /* PM Registers Address         */
#define PORT_AHB_REGS                    ((port_registers_t*)0x40000000)               /* PORT Registers Address       */
#define PORT_REGS                        ((port_registers_t*)0x44840000)               /* PORT Registers Address       */
#define PRM_REGS                         ((prm_registers_t*)0x44080000)                /* PRM Registers Address        */
#define PTC_REGS                         ((ptc_registers_t*)0x46828000)                /* PTC Registers Address        */
#define RSTC_REGS                        ((rstc_registers_t*)0x44030000)               /* RSTC Registers Address       */
#define RTC_REGS                         ((rtc_registers_t*)0x44072000)                /* RTC Registers Address        */
#define SDMMC0_REGS                      ((sdmmc_registers_t*)0x458a0000)              /* SDMMC0 Registers Address     */
#define SDMMC1_REGS                      ((sdmmc_registers_t*)0x460a0000)              /* SDMMC1 Registers Address     */
#define SERCOM0_REGS                     ((sercom_registers_t*)0x46000000)             /* SERCOM0 Registers Address    */
#define SERCOM1_REGS                     ((sercom_registers_t*)0x46002000)             /* SERCOM1 Registers Address    */
#define SERCOM2_REGS                     ((sercom_registers_t*)0x45800000)             /* SERCOM2 Registers Address    */
#define SERCOM3_REGS                     ((sercom_registers_t*)0x45802000)             /* SERCOM3 Registers Address    */
#define SERCOM4_REGS                     ((sercom_registers_t*)0x46004000)             /* SERCOM4 Registers Address    */
#define SERCOM5_REGS                     ((sercom_registers_t*)0x45804000)             /* SERCOM5 Registers Address    */
#define SERCOM6_REGS                     ((sercom_registers_t*)0x45806000)             /* SERCOM6 Registers Address    */
#define SERCOM7_REGS                     ((sercom_registers_t*)0x45000000)             /* SERCOM7 Registers Address    */
#define SERCOM8_REGS                     ((sercom_registers_t*)0x45002000)             /* SERCOM8 Registers Address    */
#define SERCOM9_REGS                     ((sercom_registers_t*)0x45004000)             /* SERCOM9 Registers Address    */
#define SPI_IXS0_REGS                    ((spi_ixs_registers_t*)0x46030000)            /* SPI_IXS0 Registers Address   */
#define SPI_IXS1_REGS                    ((spi_ixs_registers_t*)0x45030000)            /* SPI_IXS1 Registers Address   */
#define SQI0_REGS                        ((sqi_registers_t*)0x4f008000)                /* SQI0 Registers Address       */
#define SQI1_REGS                        ((sqi_registers_t*)0x4f009000)                /* SQI1 Registers Address       */
#define SUPC_REGS                        ((supc_registers_t*)0x44020000)               /* SUPC Registers Address       */
#define TCC0_REGS                        ((tcc_registers_t*)0x45010000)                /* TCC0 Registers Address       */
#define TCC1_REGS                        ((tcc_registers_t*)0x45012000)                /* TCC1 Registers Address       */
#define TCC2_REGS                        ((tcc_registers_t*)0x45014000)                /* TCC2 Registers Address       */
#define TCC3_REGS                        ((tcc_registers_t*)0x45810000)                /* TCC3 Registers Address       */
#define TCC4_REGS                        ((tcc_registers_t*)0x45812000)                /* TCC4 Registers Address       */
#define TCC5_REGS                        ((tcc_registers_t*)0x46010000)                /* TCC5 Registers Address       */
#define TCC6_REGS                        ((tcc_registers_t*)0x46012000)                /* TCC6 Registers Address       */
#define TCC7_REGS                        ((tcc_registers_t*)0x46810000)                /* TCC7 Registers Address       */
#define TCC8_REGS                        ((tcc_registers_t*)0x46812000)                /* TCC8 Registers Address       */
#define TCC9_REGS                        ((tcc_registers_t*)0x46814000)                /* TCC9 Registers Address       */
#define TRAM_REGS                        ((tram_registers_t*)0x44824000)               /* TRAM Registers Address       */
#define TRNG_REGS                        ((trng_registers_t*)0x44870000)               /* TRNG Registers Address       */
#define USBHS0_REGS                      ((usbhs_registers_t*)0x4f010000)              /* USBHS0 Registers Address     */
#define USBHS1_REGS                      ((usbhs_registers_t*)0x4f012000)              /* USBHS1 Registers Address     */
#define WDT_REGS                         ((wdt_registers_t*)0x44070000)                /* WDT Registers Address        */
#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ************************************************************************** */
/*   BASE ADDRESS DEFINITIONS FOR PIC32CZ8110CA80208                          */
/* ************************************************************************** */
#define AC_BASE_ADDRESS                  _UINT32_(0x46822000)                          /* AC Base Address */
#define ADC_BASE_ADDRESS                 _UINT32_(0x46820000)                          /* ADC Base Address */
#define CAN0_BASE_ADDRESS                _UINT32_(0x45060000)                          /* CAN0 Base Address */
#define CAN1_BASE_ADDRESS                _UINT32_(0x46060000)                          /* CAN1 Base Address */
#define CAN2_BASE_ADDRESS                _UINT32_(0x46062000)                          /* CAN2 Base Address */
#define CAN3_BASE_ADDRESS                _UINT32_(0x45860000)                          /* CAN3 Base Address */
#define CAN4_BASE_ADDRESS                _UINT32_(0x45062000)                          /* CAN4 Base Address */
#define CAN5_BASE_ADDRESS                _UINT32_(0x46860000)                          /* CAN5 Base Address */
#define DMA_BASE_ADDRESS                 _UINT32_(0x44850000)                          /* DMA Base Address */
#define DRMTCM_BASE_ADDRESS              _UINT32_(0x44820000)                          /* DRMTCM Base Address */
#define DSU_BASE_ADDRESS                 _UINT32_(0x44000000)                          /* DSU Base Address */
#define EBI_BASE_ADDRESS                 _UINT32_(0x458b0000)                          /* EBI Base Address */
#define EIC_BASE_ADDRESS                 _UINT32_(0x44800000)                          /* EIC Base Address */
#define ETH_BASE_ADDRESS                 _UINT32_(0x45070000)                          /* ETH Base Address */
#define EVSYS_BASE_ADDRESS               _UINT32_(0x44860000)                          /* EVSYS Base Address */
#define FCR_BASE_ADDRESS                 _UINT32_(0x44004000)                          /* FCR Base Address */
#define FCW_BASE_ADDRESS                 _UINT32_(0x44002000)                          /* FCW Base Address */
#define FREQM_BASE_ADDRESS               _UINT32_(0x44060000)                          /* FREQM Base Address */
#define FUSES_BOOTCFG1_BASE_ADDRESS      _UINT32_(0x0a002000)                          /* FUSES Base Address */
#define FUSES_BOOTCFG2_BASE_ADDRESS      _UINT32_(0x0a00a000)                          /* FUSES Base Address */
#define FUSES_CALOTP_BASE_ADDRESS        _UINT32_(0x0a007000)                          /* FUSES Base Address */
#define FUSES_DALCFG_BASE_ADDRESS        _UINT32_(0x0a004000)                          /* FUSES Base Address */
#define FUSES_USERCFG1_BASE_ADDRESS      _UINT32_(0x0a000000)                          /* FUSES Base Address */
#define FUSES_USERCFG2_BASE_ADDRESS      _UINT32_(0x0a008000)                          /* FUSES Base Address */
#define GCLK_BASE_ADDRESS                _UINT32_(0x44050000)                          /* GCLK Base Address */
#define MCLK_BASE_ADDRESS                _UINT32_(0x44052000)                          /* MCLK Base Address */
#define MCRAMC_BASE_ADDRESS              _UINT32_(0x44822000)                          /* MCRAMC Base Address */
#define MLB_BASE_ADDRESS                 _UINT32_(0x458c0000)                          /* MLB Base Address */
#define OSC32KCTRL_BASE_ADDRESS          _UINT32_(0x44042000)                          /* OSC32KCTRL Base Address */
#define OSCCTRL_BASE_ADDRESS             _UINT32_(0x44040000)                          /* OSCCTRL Base Address */
#define PAC_BASE_ADDRESS                 _UINT32_(0x44810000)                          /* PAC Base Address */
#define PM_BASE_ADDRESS                  _UINT32_(0x44010000)                          /* PM Base Address */
#define PORT_AHB_BASE_ADDRESS            _UINT32_(0x40000000)                          /* PORT Base Address */
#define PORT_BASE_ADDRESS                _UINT32_(0x44840000)                          /* PORT Base Address */
#define PRM_BASE_ADDRESS                 _UINT32_(0x44080000)                          /* PRM Base Address */
#define PTC_BASE_ADDRESS                 _UINT32_(0x46828000)                          /* PTC Base Address */
#define RSTC_BASE_ADDRESS                _UINT32_(0x44030000)                          /* RSTC Base Address */
#define RTC_BASE_ADDRESS                 _UINT32_(0x44072000)                          /* RTC Base Address */
#define SDMMC0_BASE_ADDRESS              _UINT32_(0x458a0000)                          /* SDMMC0 Base Address */
#define SDMMC1_BASE_ADDRESS              _UINT32_(0x460a0000)                          /* SDMMC1 Base Address */
#define SERCOM0_BASE_ADDRESS             _UINT32_(0x46000000)                          /* SERCOM0 Base Address */
#define SERCOM1_BASE_ADDRESS             _UINT32_(0x46002000)                          /* SERCOM1 Base Address */
#define SERCOM2_BASE_ADDRESS             _UINT32_(0x45800000)                          /* SERCOM2 Base Address */
#define SERCOM3_BASE_ADDRESS             _UINT32_(0x45802000)                          /* SERCOM3 Base Address */
#define SERCOM4_BASE_ADDRESS             _UINT32_(0x46004000)                          /* SERCOM4 Base Address */
#define SERCOM5_BASE_ADDRESS             _UINT32_(0x45804000)                          /* SERCOM5 Base Address */
#define SERCOM6_BASE_ADDRESS             _UINT32_(0x45806000)                          /* SERCOM6 Base Address */
#define SERCOM7_BASE_ADDRESS             _UINT32_(0x45000000)                          /* SERCOM7 Base Address */
#define SERCOM8_BASE_ADDRESS             _UINT32_(0x45002000)                          /* SERCOM8 Base Address */
#define SERCOM9_BASE_ADDRESS             _UINT32_(0x45004000)                          /* SERCOM9 Base Address */
#define SPI_IXS0_BASE_ADDRESS            _UINT32_(0x46030000)                          /* SPI_IXS0 Base Address */
#define SPI_IXS1_BASE_ADDRESS            _UINT32_(0x45030000)                          /* SPI_IXS1 Base Address */
#define SQI0_BASE_ADDRESS                _UINT32_(0x4f008000)                          /* SQI0 Base Address */
#define SQI1_BASE_ADDRESS                _UINT32_(0x4f009000)                          /* SQI1 Base Address */
#define SUPC_BASE_ADDRESS                _UINT32_(0x44020000)                          /* SUPC Base Address */
#define TCC0_BASE_ADDRESS                _UINT32_(0x45010000)                          /* TCC0 Base Address */
#define TCC1_BASE_ADDRESS                _UINT32_(0x45012000)                          /* TCC1 Base Address */
#define TCC2_BASE_ADDRESS                _UINT32_(0x45014000)                          /* TCC2 Base Address */
#define TCC3_BASE_ADDRESS                _UINT32_(0x45810000)                          /* TCC3 Base Address */
#define TCC4_BASE_ADDRESS                _UINT32_(0x45812000)                          /* TCC4 Base Address */
#define TCC5_BASE_ADDRESS                _UINT32_(0x46010000)                          /* TCC5 Base Address */
#define TCC6_BASE_ADDRESS                _UINT32_(0x46012000)                          /* TCC6 Base Address */
#define TCC7_BASE_ADDRESS                _UINT32_(0x46810000)                          /* TCC7 Base Address */
#define TCC8_BASE_ADDRESS                _UINT32_(0x46812000)                          /* TCC8 Base Address */
#define TCC9_BASE_ADDRESS                _UINT32_(0x46814000)                          /* TCC9 Base Address */
#define TRAM_BASE_ADDRESS                _UINT32_(0x44824000)                          /* TRAM Base Address */
#define TRNG_BASE_ADDRESS                _UINT32_(0x44870000)                          /* TRNG Base Address */
#define USBHS0_BASE_ADDRESS              _UINT32_(0x4f010000)                          /* USBHS0 Base Address */
#define USBHS1_BASE_ADDRESS              _UINT32_(0x4f012000)                          /* USBHS1 Base Address */
#define WDT_BASE_ADDRESS                 _UINT32_(0x44070000)                          /* WDT Base Address */

/* ************************************************************************** */
/*   PIO DEFINITIONS FOR PIC32CZ8110CA80208                                   */
/* ************************************************************************** */
#include "pio/pic32cz8110ca80208.h"

/* ************************************************************************** */
/*   MEMORY MAPPING DEFINITIONS FOR PIC32CZ8110CA80208                        */
/* ************************************************************************** */
#define ITCM_SIZE                      _UINT32_(0x00020000)    /*  128kB Memory segment type: ram */
#define PRM_ROM_SIZE                   _UINT32_(0x00008000)    /*   32kB Memory segment type: rom */
#define FCR_BFM_SIZE                   _UINT32_(0x00020000)    /*  128kB Memory segment type: flash */
#define FCR_BFM_PAGE_SIZE              _UINT32_(      4096)
#define FCR_BFM_NB_OF_PAGES            _UINT32_(        32)

#define FCR_CFM_USERCFG1_SIZE          _UINT32_(0x00001000)    /*    4kB Memory segment type: flash */
#define FCR_CFM_USERCFG1_PAGE_SIZE     _UINT32_(      4096)
#define FCR_CFM_USERCFG1_NB_OF_PAGES   _UINT32_(         1)

#define FCR_CFM_USEROTP1_SIZE          _UINT32_(0x00001000)    /*    4kB Memory segment type: user_signatures */
#define FCR_CFM_USEROTP1_PAGE_SIZE     _UINT32_(      4096)
#define FCR_CFM_USEROTP1_NB_OF_PAGES   _UINT32_(         1)

#define FCR_CFM_BOOTCFG1_SIZE          _UINT32_(0x00001000)    /*    4kB Memory segment type: flash */
#define FCR_CFM_BOOTCFG1_PAGE_SIZE     _UINT32_(      4096)
#define FCR_CFM_BOOTCFG1_NB_OF_PAGES   _UINT32_(         1)

#define FCR_CFM_DALCFG_SIZE            _UINT32_(0x00001000)    /*    4kB Memory segment type: flash */
#define FCR_CFM_DALCFG_PAGE_SIZE       _UINT32_(      4096)
#define FCR_CFM_DALCFG_NB_OF_PAGES     _UINT32_(         1)

#define FCR_CFM_CALOTP_SIZE            _UINT32_(0x00001000)    /*    4kB Memory segment type: other */
#define FCR_CFM_CALOTP_PAGE_SIZE       _UINT32_(      4096)
#define FCR_CFM_CALOTP_NB_OF_PAGES     _UINT32_(         1)

#define FCR_CFM_USERCFG2_SIZE          _UINT32_(0x00001000)    /*    4kB Memory segment type: flash */
#define FCR_CFM_USERCFG2_PAGE_SIZE     _UINT32_(      4096)
#define FCR_CFM_USERCFG2_NB_OF_PAGES   _UINT32_(         1)

#define FCR_CFM_USEROTP2_SIZE          _UINT32_(0x00001000)    /*    4kB Memory segment type: user_signatures */
#define FCR_CFM_USEROTP2_PAGE_SIZE     _UINT32_(      4096)
#define FCR_CFM_USEROTP2_NB_OF_PAGES   _UINT32_(         1)

#define FCR_CFM_BOOTCFG2_SIZE          _UINT32_(0x00001000)    /*    4kB Memory segment type: flash */
#define FCR_CFM_BOOTCFG2_PAGE_SIZE     _UINT32_(      4096)
#define FCR_CFM_BOOTCFG2_NB_OF_PAGES   _UINT32_(         1)

#define FCR_PFM_SIZE                   _UINT32_(0x00800000)    /* 8192kB Memory segment type: flash */
#define FCR_PFM_PAGE_SIZE              _UINT32_(      4096)
#define FCR_PFM_NB_OF_PAGES            _UINT32_(      2048)

#define DTCM_SIZE                      _UINT32_(0x00020000)    /*  128kB Memory segment type: ram */
#define FLEXRAM_SIZE                   _UINT32_(0x00100000)    /* 1024kB Memory segment type: ram */
#define APBA_SIZE                      _UINT32_(0x00800000)    /* 8192kB Memory segment type: io */
#define APBB_SIZE                      _UINT32_(0x00800000)    /* 8192kB Memory segment type: io */
#define APBC_SIZE                      _UINT32_(0x00800000)    /* 8192kB Memory segment type: io */
#define APBD_SIZE                      _UINT32_(0x00800000)    /* 8192kB Memory segment type: io */
#define APBE_SIZE                      _UINT32_(0x00800000)    /* 8192kB Memory segment type: io */
#define APBF_SIZE                      _UINT32_(0x00800000)    /* 8192kB Memory segment type: io */
#define SQI0_SFR_SIZE                  _UINT32_(0x00001000)    /*    4kB Memory segment type: io */
#define SQI1_SFR_SIZE                  _UINT32_(0x00001000)    /*    4kB Memory segment type: io */
#define USBHS0_SFR_SIZE                _UINT32_(0x00002000)    /*    8kB Memory segment type: io */
#define USBHS1_SFR_SIZE                _UINT32_(0x00002000)    /*    8kB Memory segment type: io */
#define HSM_SFR_SIZE                   _UINT32_(0x00000400)    /*    1kB Memory segment type: io */
#define EBI_CS0_SIZE                   _UINT32_(0x01000000)    /* 16384kB Memory segment type: ram */
#define EBI_CS1_SIZE                   _UINT32_(0x01000000)    /* 16384kB Memory segment type: ram */
#define EBI_CS2_SIZE                   _UINT32_(0x01000000)    /* 16384kB Memory segment type: ram */
#define EBI_CS3_SIZE                   _UINT32_(0x01000000)    /* 16384kB Memory segment type: ram */
#define SQI0_XIP_SIZE                  _UINT32_(0x10000000)    /* 262144kB Memory segment type: ram */
#define SQI1_XIP_SIZE                  _UINT32_(0x10000000)    /* 262144kB Memory segment type: ram */
#define PPB_SIZE                       _UINT32_(0x20000000)    /* 524288kB Memory segment type: io */
#define CM7H_ROM_TABLE_SIZE            _UINT32_(0x00000100)    /*    0kB Memory segment type: rom */

#define ITCM_ADDR                      _UINT32_(0x00000000)    /* ITCM base address (type: ram)*/
#define PRM_ROM_ADDR                   _UINT32_(0x04000000)    /* PRM_ROM base address (type: rom)*/
#define FCR_BFM_ADDR                   _UINT32_(0x08000000)    /* FCR_BFM base address (type: flash)*/
#define FCR_CFM_USERCFG1_ADDR          _UINT32_(0x0a000000)    /* FCR_CFM_USERCFG1 base address (type: flash)*/
#define FCR_CFM_USEROTP1_ADDR          _UINT32_(0x0a001000)    /* FCR_CFM_USEROTP1 base address (type: user_signatures)*/
#define FCR_CFM_BOOTCFG1_ADDR          _UINT32_(0x0a002000)    /* FCR_CFM_BOOTCFG1 base address (type: flash)*/
#define FCR_CFM_DALCFG_ADDR            _UINT32_(0x0a004000)    /* FCR_CFM_DALCFG base address (type: flash)*/
#define FCR_CFM_CALOTP_ADDR            _UINT32_(0x0a007000)    /* FCR_CFM_CALOTP base address (type: other)*/
#define FCR_CFM_USERCFG2_ADDR          _UINT32_(0x0a008000)    /* FCR_CFM_USERCFG2 base address (type: flash)*/
#define FCR_CFM_USEROTP2_ADDR          _UINT32_(0x0a009000)    /* FCR_CFM_USEROTP2 base address (type: user_signatures)*/
#define FCR_CFM_BOOTCFG2_ADDR          _UINT32_(0x0a00a000)    /* FCR_CFM_BOOTCFG2 base address (type: flash)*/
#define FCR_PFM_ADDR                   _UINT32_(0x0c000000)    /* FCR_PFM base address (type: flash)*/
#define DTCM_ADDR                      _UINT32_(0x20000000)    /* DTCM base address (type: ram)*/
#define FLEXRAM_ADDR                   _UINT32_(0x20020000)    /* FLEXRAM base address (type: ram)*/
#define APBA_ADDR                      _UINT32_(0x44000000)    /* APBA base address (type: io)*/
#define APBB_ADDR                      _UINT32_(0x44800000)    /* APBB base address (type: io)*/
#define APBC_ADDR                      _UINT32_(0x45000000)    /* APBC base address (type: io)*/
#define APBD_ADDR                      _UINT32_(0x45800000)    /* APBD base address (type: io)*/
#define APBE_ADDR                      _UINT32_(0x46000000)    /* APBE base address (type: io)*/
#define APBF_ADDR                      _UINT32_(0x46800000)    /* APBF base address (type: io)*/
#define SQI0_SFR_ADDR                  _UINT32_(0x4f008000)    /* SQI0_SFR base address (type: io)*/
#define SQI1_SFR_ADDR                  _UINT32_(0x4f009000)    /* SQI1_SFR base address (type: io)*/
#define USBHS0_SFR_ADDR                _UINT32_(0x4f010000)    /* USBHS0_SFR base address (type: io)*/
#define USBHS1_SFR_ADDR                _UINT32_(0x4f012000)    /* USBHS1_SFR base address (type: io)*/
#define HSM_SFR_ADDR                   _UINT32_(0x4f018000)    /* HSM_SFR base address (type: io)*/
#define EBI_CS0_ADDR                   _UINT32_(0x60000000)    /* EBI_CS0 base address (type: ram)*/
#define EBI_CS1_ADDR                   _UINT32_(0x61000000)    /* EBI_CS1 base address (type: ram)*/
#define EBI_CS2_ADDR                   _UINT32_(0x62000000)    /* EBI_CS2 base address (type: ram)*/
#define EBI_CS3_ADDR                   _UINT32_(0x63000000)    /* EBI_CS3 base address (type: ram)*/
#define SQI0_XIP_ADDR                  _UINT32_(0x80000000)    /* SQI0_XIP base address (type: ram)*/
#define SQI1_XIP_ADDR                  _UINT32_(0x90000000)    /* SQI1_XIP base address (type: ram)*/
#define PPB_ADDR                       _UINT32_(0xe0000000)    /* PPB base address (type: io)*/
#define CM7H_ROM_TABLE_ADDR            _UINT32_(0xe00fe000)    /* CM7H_ROM_TABLE base address (type: rom)*/

/* ************************************************************************** */
/*   DEVICE SIGNATURES FOR PIC32CZ8110CA80208                                 */
/* ************************************************************************** */
#define CHIP_DSU_DID                   _UINT32_(0X09200053)

/* ************************************************************************** */
/*   ELECTRICAL DEFINITIONS FOR PIC32CZ8110CA80208                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* Event Generator IDs for C32CZ8110CA80208 */
/* ************************************************************************** */
#define EVENT_ID_GEN_SUPC_LVDET                           1 /* ID for SUPC event generator LVDET */
#define EVENT_ID_GEN_OSCCTRL_XOSC_FAIL                    2 /* ID for OSCCTRL event generator XOSC_FAIL */
#define EVENT_ID_GEN_OSC32KCTRL_XOSC32K_FAIL              3 /* ID for OSC32KCTRL event generator XOSC32K_FAIL */
#define EVENT_ID_GEN_FREQM_DONE                           4 /* ID for FREQM event generator DONE */
#define EVENT_ID_GEN_FREQM_WINMON                         5 /* ID for FREQM event generator WINMON */
#define EVENT_ID_GEN_RTC_PER_0                            6 /* ID for RTC event generator PER_0 */
#define EVENT_ID_GEN_RTC_PER_1                            7 /* ID for RTC event generator PER_1 */
#define EVENT_ID_GEN_RTC_PER_2                            8 /* ID for RTC event generator PER_2 */
#define EVENT_ID_GEN_RTC_PER_3                            9 /* ID for RTC event generator PER_3 */
#define EVENT_ID_GEN_RTC_PER_4                           10 /* ID for RTC event generator PER_4 */
#define EVENT_ID_GEN_RTC_PER_5                           11 /* ID for RTC event generator PER_5 */
#define EVENT_ID_GEN_RTC_PER_6                           12 /* ID for RTC event generator PER_6 */
#define EVENT_ID_GEN_RTC_PER_7                           13 /* ID for RTC event generator PER_7 */
#define EVENT_ID_GEN_RTC_CMP_0                           14 /* ID for RTC event generator CMP_0 */
#define EVENT_ID_GEN_RTC_CMP_1                           15 /* ID for RTC event generator CMP_1 */
#define EVENT_ID_GEN_RTC_CMP_2                           16 /* ID for RTC event generator CMP_2 */
#define EVENT_ID_GEN_RTC_CMP_3                           17 /* ID for RTC event generator CMP_3 */
#define EVENT_ID_GEN_RTC_TAMPER                          18 /* ID for RTC event generator TAMPER */
#define EVENT_ID_GEN_RTC_OVF                             19 /* ID for RTC event generator OVF */
#define EVENT_ID_GEN_RTC_PERD                            20 /* ID for RTC event generator PERD */
#define EVENT_ID_GEN_EIC_EXTINT_0                        21 /* ID for EIC event generator EXTINT_0 */
#define EVENT_ID_GEN_EIC_EXTINT_1                        22 /* ID for EIC event generator EXTINT_1 */
#define EVENT_ID_GEN_EIC_EXTINT_2                        23 /* ID for EIC event generator EXTINT_2 */
#define EVENT_ID_GEN_EIC_EXTINT_3                        24 /* ID for EIC event generator EXTINT_3 */
#define EVENT_ID_GEN_EIC_EXTINT_4                        25 /* ID for EIC event generator EXTINT_4 */
#define EVENT_ID_GEN_EIC_EXTINT_5                        26 /* ID for EIC event generator EXTINT_5 */
#define EVENT_ID_GEN_EIC_EXTINT_6                        27 /* ID for EIC event generator EXTINT_6 */
#define EVENT_ID_GEN_EIC_EXTINT_7                        28 /* ID for EIC event generator EXTINT_7 */
#define EVENT_ID_GEN_EIC_EXTINT_8                        29 /* ID for EIC event generator EXTINT_8 */
#define EVENT_ID_GEN_EIC_EXTINT_9                        30 /* ID for EIC event generator EXTINT_9 */
#define EVENT_ID_GEN_EIC_EXTINT_10                       31 /* ID for EIC event generator EXTINT_10 */
#define EVENT_ID_GEN_EIC_EXTINT_11                       32 /* ID for EIC event generator EXTINT_11 */
#define EVENT_ID_GEN_EIC_EXTINT_12                       33 /* ID for EIC event generator EXTINT_12 */
#define EVENT_ID_GEN_EIC_EXTINT_13                       34 /* ID for EIC event generator EXTINT_13 */
#define EVENT_ID_GEN_EIC_EXTINT_14                       35 /* ID for EIC event generator EXTINT_14 */
#define EVENT_ID_GEN_EIC_EXTINT_15                       36 /* ID for EIC event generator EXTINT_15 */
#define EVENT_ID_GEN_PAC_ACCERR                          37 /* ID for PAC event generator ACCERR */
#define EVENT_ID_GEN_DMA_CH_0                            38 /* ID for DMA event generator CH_0 */
#define EVENT_ID_GEN_DMA_CH_1                            39 /* ID for DMA event generator CH_1 */
#define EVENT_ID_GEN_DMA_CH_2                            40 /* ID for DMA event generator CH_2 */
#define EVENT_ID_GEN_DMA_CH_3                            41 /* ID for DMA event generator CH_3 */
#define EVENT_ID_GEN_DMA_CH_4                            42 /* ID for DMA event generator CH_4 */
#define EVENT_ID_GEN_DMA_CH_5                            43 /* ID for DMA event generator CH_5 */
#define EVENT_ID_GEN_DMA_CH_6                            44 /* ID for DMA event generator CH_6 */
#define EVENT_ID_GEN_DMA_CH_7                            45 /* ID for DMA event generator CH_7 */
#define EVENT_ID_GEN_DMA_CH_8                            46 /* ID for DMA event generator CH_8 */
#define EVENT_ID_GEN_DMA_CH_9                            47 /* ID for DMA event generator CH_9 */
#define EVENT_ID_GEN_DMA_CH_10                           48 /* ID for DMA event generator CH_10 */
#define EVENT_ID_GEN_DMA_CH_11                           49 /* ID for DMA event generator CH_11 */
#define EVENT_ID_GEN_DMA_CH_12                           50 /* ID for DMA event generator CH_12 */
#define EVENT_ID_GEN_DMA_CH_13                           51 /* ID for DMA event generator CH_13 */
#define EVENT_ID_GEN_DMA_CH_14                           52 /* ID for DMA event generator CH_14 */
#define EVENT_ID_GEN_DMA_CH_15                           53 /* ID for DMA event generator CH_15 */
#define EVENT_ID_GEN_TCC0_OVF                            54 /* ID for TCC0 event generator OVF */
#define EVENT_ID_GEN_TCC0_TRG                            55 /* ID for TCC0 event generator TRG */
#define EVENT_ID_GEN_TCC0_CNT                            56 /* ID for TCC0 event generator CNT */
#define EVENT_ID_GEN_TCC0_MC_0                           57 /* ID for TCC0 event generator MC_0 */
#define EVENT_ID_GEN_TCC0_MC_1                           58 /* ID for TCC0 event generator MC_1 */
#define EVENT_ID_GEN_TCC0_MC_2                           59 /* ID for TCC0 event generator MC_2 */
#define EVENT_ID_GEN_TCC0_MC_3                           60 /* ID for TCC0 event generator MC_3 */
#define EVENT_ID_GEN_TCC0_MC_4                           61 /* ID for TCC0 event generator MC_4 */
#define EVENT_ID_GEN_TCC0_MC_5                           62 /* ID for TCC0 event generator MC_5 */
#define EVENT_ID_GEN_TCC0_MC_6                           63 /* ID for TCC0 event generator MC_6 */
#define EVENT_ID_GEN_TCC0_MC_7                           64 /* ID for TCC0 event generator MC_7 */
#define EVENT_ID_GEN_TCC1_OVF                            65 /* ID for TCC1 event generator OVF */
#define EVENT_ID_GEN_TCC1_TRG                            66 /* ID for TCC1 event generator TRG */
#define EVENT_ID_GEN_TCC1_CNT                            67 /* ID for TCC1 event generator CNT */
#define EVENT_ID_GEN_TCC1_MC_0                           68 /* ID for TCC1 event generator MC_0 */
#define EVENT_ID_GEN_TCC1_MC_1                           69 /* ID for TCC1 event generator MC_1 */
#define EVENT_ID_GEN_TCC1_MC_2                           70 /* ID for TCC1 event generator MC_2 */
#define EVENT_ID_GEN_TCC1_MC_3                           71 /* ID for TCC1 event generator MC_3 */
#define EVENT_ID_GEN_TCC1_MC_4                           72 /* ID for TCC1 event generator MC_4 */
#define EVENT_ID_GEN_TCC1_MC_5                           73 /* ID for TCC1 event generator MC_5 */
#define EVENT_ID_GEN_TCC1_MC_6                           74 /* ID for TCC1 event generator MC_6 */
#define EVENT_ID_GEN_TCC1_MC_7                           75 /* ID for TCC1 event generator MC_7 */
#define EVENT_ID_GEN_TCC2_OVF                            76 /* ID for TCC2 event generator OVF */
#define EVENT_ID_GEN_TCC2_TRG                            77 /* ID for TCC2 event generator TRG */
#define EVENT_ID_GEN_TCC2_CNT                            78 /* ID for TCC2 event generator CNT */
#define EVENT_ID_GEN_TCC2_MC_0                           79 /* ID for TCC2 event generator MC_0 */
#define EVENT_ID_GEN_TCC2_MC_1                           80 /* ID for TCC2 event generator MC_1 */
#define EVENT_ID_GEN_TCC2_MC_2                           81 /* ID for TCC2 event generator MC_2 */
#define EVENT_ID_GEN_TCC2_MC_3                           82 /* ID for TCC2 event generator MC_3 */
#define EVENT_ID_GEN_TCC2_MC_4                           83 /* ID for TCC2 event generator MC_4 */
#define EVENT_ID_GEN_TCC2_MC_5                           84 /* ID for TCC2 event generator MC_5 */
#define EVENT_ID_GEN_TCC3_OVF                            85 /* ID for TCC3 event generator OVF */
#define EVENT_ID_GEN_TCC3_TRG                            86 /* ID for TCC3 event generator TRG */
#define EVENT_ID_GEN_TCC3_CNT                            87 /* ID for TCC3 event generator CNT */
#define EVENT_ID_GEN_TCC3_MC_0                           88 /* ID for TCC3 event generator MC_0 */
#define EVENT_ID_GEN_TCC3_MC_1                           89 /* ID for TCC3 event generator MC_1 */
#define EVENT_ID_GEN_TCC4_OVF                            90 /* ID for TCC4 event generator OVF */
#define EVENT_ID_GEN_TCC4_TRG                            91 /* ID for TCC4 event generator TRG */
#define EVENT_ID_GEN_TCC4_CNT                            92 /* ID for TCC4 event generator CNT */
#define EVENT_ID_GEN_TCC4_MC_0                           93 /* ID for TCC4 event generator MC_0 */
#define EVENT_ID_GEN_TCC4_MC_1                           94 /* ID for TCC4 event generator MC_1 */
#define EVENT_ID_GEN_TCC5_OVF                            95 /* ID for TCC5 event generator OVF */
#define EVENT_ID_GEN_TCC5_TRG                            96 /* ID for TCC5 event generator TRG */
#define EVENT_ID_GEN_TCC5_CNT                            97 /* ID for TCC5 event generator CNT */
#define EVENT_ID_GEN_TCC5_MC_0                           98 /* ID for TCC5 event generator MC_0 */
#define EVENT_ID_GEN_TCC5_MC_1                           99 /* ID for TCC5 event generator MC_1 */
#define EVENT_ID_GEN_TCC6_OVF                           100 /* ID for TCC6 event generator OVF */
#define EVENT_ID_GEN_TCC6_TRG                           101 /* ID for TCC6 event generator TRG */
#define EVENT_ID_GEN_TCC6_CNT                           102 /* ID for TCC6 event generator CNT */
#define EVENT_ID_GEN_TCC6_MC_0                          103 /* ID for TCC6 event generator MC_0 */
#define EVENT_ID_GEN_TCC6_MC_1                          104 /* ID for TCC6 event generator MC_1 */
#define EVENT_ID_GEN_TCC7_OVF                           105 /* ID for TCC7 event generator OVF */
#define EVENT_ID_GEN_TCC7_TRG                           106 /* ID for TCC7 event generator TRG */
#define EVENT_ID_GEN_TCC7_CNT                           107 /* ID for TCC7 event generator CNT */
#define EVENT_ID_GEN_TCC7_MC_0                          108 /* ID for TCC7 event generator MC_0 */
#define EVENT_ID_GEN_TCC7_MC_1                          109 /* ID for TCC7 event generator MC_1 */
#define EVENT_ID_GEN_TCC8_OVF                           110 /* ID for TCC8 event generator OVF */
#define EVENT_ID_GEN_TCC8_TRG                           111 /* ID for TCC8 event generator TRG */
#define EVENT_ID_GEN_TCC8_CNT                           112 /* ID for TCC8 event generator CNT */
#define EVENT_ID_GEN_TCC8_MC_0                          113 /* ID for TCC8 event generator MC_0 */
#define EVENT_ID_GEN_TCC8_MC_1                          114 /* ID for TCC8 event generator MC_1 */
#define EVENT_ID_GEN_TCC9_OVF                           115 /* ID for TCC9 event generator OVF */
#define EVENT_ID_GEN_TCC9_TRG                           116 /* ID for TCC9 event generator TRG */
#define EVENT_ID_GEN_TCC9_CNT                           117 /* ID for TCC9 event generator CNT */
#define EVENT_ID_GEN_TCC9_MC_0                          118 /* ID for TCC9 event generator MC_0 */
#define EVENT_ID_GEN_TCC9_MC_1                          119 /* ID for TCC9 event generator MC_1 */
#define EVENT_ID_GEN_TCC9_MC_2                          120 /* ID for TCC9 event generator MC_2 */
#define EVENT_ID_GEN_TCC9_MC_3                          121 /* ID for TCC9 event generator MC_3 */
#define EVENT_ID_GEN_TCC9_MC_4                          122 /* ID for TCC9 event generator MC_4 */
#define EVENT_ID_GEN_TCC9_MC_5                          123 /* ID for TCC9 event generator MC_5 */
#define EVENT_ID_GEN_ADC_CHRDYC_0                       124 /* ID for ADC event generator CHRDYC_0 */
#define EVENT_ID_GEN_ADC_CHRDYC_1                       125 /* ID for ADC event generator CHRDYC_1 */
#define EVENT_ID_GEN_ADC_CHRDYC_2                       126 /* ID for ADC event generator CHRDYC_2 */
#define EVENT_ID_GEN_ADC_CHRDYC_3                       127 /* ID for ADC event generator CHRDYC_3 */
#define EVENT_ID_GEN_ADC_CMP_0                          128 /* ID for ADC event generator CMP_0 */
#define EVENT_ID_GEN_ADC_CMP_1                          129 /* ID for ADC event generator CMP_1 */
#define EVENT_ID_GEN_ADC_CMP_2                          130 /* ID for ADC event generator CMP_2 */
#define EVENT_ID_GEN_ADC_CMP_3                          131 /* ID for ADC event generator CMP_3 */
#define EVENT_ID_GEN_AC_COMP_0                          132 /* ID for AC event generator COMP_0 */
#define EVENT_ID_GEN_AC_COMP_1                          133 /* ID for AC event generator COMP_1 */
#define EVENT_ID_GEN_AC_WIN_0                           134 /* ID for AC event generator WIN_0 */
#define EVENT_ID_GEN_PTC_EOC                            135 /* ID for PTC event generator EOC */
#define EVENT_ID_GEN_PTC_WCOMP                          136 /* ID for PTC event generator WCOMP */
#define EVENT_ID_GEN_ETH_TSU_CMP                        137 /* ID for ETH event generator TSU_CMP */
#define EVENT_ID_GEN_TRNG_READY                         138 /* ID for TRNG event generator READY */

/* ************************************************************************** */
/*  Event User IDs for C32CZ8110CA80208 */
/* ************************************************************************** */
#define EVENT_ID_USER_FREQM_START                         0 /* ID for FREQM event user START */
#define EVENT_ID_USER_RTC_TAMPER                          1 /* ID for RTC event user TAMPER */
#define EVENT_ID_USER_PORT_EV_0                           2 /* ID for PORT event user EV_0 */
#define EVENT_ID_USER_PORT_EV_1                           3 /* ID for PORT event user EV_1 */
#define EVENT_ID_USER_PORT_EV_2                           4 /* ID for PORT event user EV_2 */
#define EVENT_ID_USER_PORT_EV_3                           5 /* ID for PORT event user EV_3 */
#define EVENT_ID_USER_DMA_CHSTRT_0                        6 /* ID for DMA event user CHSTRT_0 */
#define EVENT_ID_USER_DMA_CHSTRT_1                        7 /* ID for DMA event user CHSTRT_1 */
#define EVENT_ID_USER_DMA_CHSTRT_2                        8 /* ID for DMA event user CHSTRT_2 */
#define EVENT_ID_USER_DMA_CHSTRT_3                        9 /* ID for DMA event user CHSTRT_3 */
#define EVENT_ID_USER_DMA_CHSTRT_4                       10 /* ID for DMA event user CHSTRT_4 */
#define EVENT_ID_USER_DMA_CHSTRT_5                       11 /* ID for DMA event user CHSTRT_5 */
#define EVENT_ID_USER_DMA_CHSTRT_6                       12 /* ID for DMA event user CHSTRT_6 */
#define EVENT_ID_USER_DMA_CHSTRT_7                       13 /* ID for DMA event user CHSTRT_7 */
#define EVENT_ID_USER_DMA_CHSTRT_8                       14 /* ID for DMA event user CHSTRT_8 */
#define EVENT_ID_USER_DMA_CHSTRT_9                       15 /* ID for DMA event user CHSTRT_9 */
#define EVENT_ID_USER_DMA_CHSTRT_10                      16 /* ID for DMA event user CHSTRT_10 */
#define EVENT_ID_USER_DMA_CHSTRT_11                      17 /* ID for DMA event user CHSTRT_11 */
#define EVENT_ID_USER_DMA_CHSTRT_12                      18 /* ID for DMA event user CHSTRT_12 */
#define EVENT_ID_USER_DMA_CHSTRT_13                      19 /* ID for DMA event user CHSTRT_13 */
#define EVENT_ID_USER_DMA_CHSTRT_14                      20 /* ID for DMA event user CHSTRT_14 */
#define EVENT_ID_USER_DMA_CHSTRT_15                      21 /* ID for DMA event user CHSTRT_15 */
#define EVENT_ID_USER_DMA_CHAUX_0                        22 /* ID for DMA event user CHAUX_0 */
#define EVENT_ID_USER_DMA_CHAUX_1                        23 /* ID for DMA event user CHAUX_1 */
#define EVENT_ID_USER_DMA_CHAUX_2                        24 /* ID for DMA event user CHAUX_2 */
#define EVENT_ID_USER_DMA_CHAUX_3                        25 /* ID for DMA event user CHAUX_3 */
#define EVENT_ID_USER_DMA_CHAUX_4                        26 /* ID for DMA event user CHAUX_4 */
#define EVENT_ID_USER_DMA_CHAUX_5                        27 /* ID for DMA event user CHAUX_5 */
#define EVENT_ID_USER_DMA_CHAUX_6                        28 /* ID for DMA event user CHAUX_6 */
#define EVENT_ID_USER_DMA_CHAUX_7                        29 /* ID for DMA event user CHAUX_7 */
#define EVENT_ID_USER_DMA_CHAUX_8                        30 /* ID for DMA event user CHAUX_8 */
#define EVENT_ID_USER_DMA_CHAUX_9                        31 /* ID for DMA event user CHAUX_9 */
#define EVENT_ID_USER_DMA_CHAUX_10                       32 /* ID for DMA event user CHAUX_10 */
#define EVENT_ID_USER_DMA_CHAUX_11                       33 /* ID for DMA event user CHAUX_11 */
#define EVENT_ID_USER_DMA_CHAUX_12                       34 /* ID for DMA event user CHAUX_12 */
#define EVENT_ID_USER_DMA_CHAUX_13                       35 /* ID for DMA event user CHAUX_13 */
#define EVENT_ID_USER_DMA_CHAUX_14                       36 /* ID for DMA event user CHAUX_14 */
#define EVENT_ID_USER_DMA_CHAUX_15                       37 /* ID for DMA event user CHAUX_15 */
#define EVENT_ID_USER_TCC0_EV_0                          38 /* ID for TCC0 event user EV_0 */
#define EVENT_ID_USER_TCC0_EV_1                          39 /* ID for TCC0 event user EV_1 */
#define EVENT_ID_USER_TCC0_MC_0                          40 /* ID for TCC0 event user MC_0 */
#define EVENT_ID_USER_TCC0_MC_1                          41 /* ID for TCC0 event user MC_1 */
#define EVENT_ID_USER_TCC0_MC_2                          42 /* ID for TCC0 event user MC_2 */
#define EVENT_ID_USER_TCC0_MC_3                          43 /* ID for TCC0 event user MC_3 */
#define EVENT_ID_USER_TCC0_MC_4                          44 /* ID for TCC0 event user MC_4 */
#define EVENT_ID_USER_TCC0_MC_5                          45 /* ID for TCC0 event user MC_5 */
#define EVENT_ID_USER_TCC0_MC_6                          46 /* ID for TCC0 event user MC_6 */
#define EVENT_ID_USER_TCC0_MC_7                          47 /* ID for TCC0 event user MC_7 */
#define EVENT_ID_USER_TCC1_EV_0                          48 /* ID for TCC1 event user EV_0 */
#define EVENT_ID_USER_TCC1_EV_1                          49 /* ID for TCC1 event user EV_1 */
#define EVENT_ID_USER_TCC1_MC_0                          50 /* ID for TCC1 event user MC_0 */
#define EVENT_ID_USER_TCC1_MC_1                          51 /* ID for TCC1 event user MC_1 */
#define EVENT_ID_USER_TCC1_MC_2                          52 /* ID for TCC1 event user MC_2 */
#define EVENT_ID_USER_TCC1_MC_3                          53 /* ID for TCC1 event user MC_3 */
#define EVENT_ID_USER_TCC1_MC_4                          54 /* ID for TCC1 event user MC_4 */
#define EVENT_ID_USER_TCC1_MC_5                          55 /* ID for TCC1 event user MC_5 */
#define EVENT_ID_USER_TCC1_MC_6                          56 /* ID for TCC1 event user MC_6 */
#define EVENT_ID_USER_TCC1_MC_7                          57 /* ID for TCC1 event user MC_7 */
#define EVENT_ID_USER_TCC2_EV_0                          58 /* ID for TCC2 event user EV_0 */
#define EVENT_ID_USER_TCC2_EV_1                          59 /* ID for TCC2 event user EV_1 */
#define EVENT_ID_USER_TCC2_MC_0                          60 /* ID for TCC2 event user MC_0 */
#define EVENT_ID_USER_TCC2_MC_1                          61 /* ID for TCC2 event user MC_1 */
#define EVENT_ID_USER_TCC2_MC_2                          62 /* ID for TCC2 event user MC_2 */
#define EVENT_ID_USER_TCC2_MC_3                          63 /* ID for TCC2 event user MC_3 */
#define EVENT_ID_USER_TCC2_MC_4                          64 /* ID for TCC2 event user MC_4 */
#define EVENT_ID_USER_TCC2_MC_5                          65 /* ID for TCC2 event user MC_5 */
#define EVENT_ID_USER_TCC3_EV_0                          66 /* ID for TCC3 event user EV_0 */
#define EVENT_ID_USER_TCC3_EV_1                          67 /* ID for TCC3 event user EV_1 */
#define EVENT_ID_USER_TCC3_MC_0                          68 /* ID for TCC3 event user MC_0 */
#define EVENT_ID_USER_TCC3_MC_1                          69 /* ID for TCC3 event user MC_1 */
#define EVENT_ID_USER_TCC4_EV_0                          70 /* ID for TCC4 event user EV_0 */
#define EVENT_ID_USER_TCC4_EV_1                          71 /* ID for TCC4 event user EV_1 */
#define EVENT_ID_USER_TCC4_MC_0                          72 /* ID for TCC4 event user MC_0 */
#define EVENT_ID_USER_TCC4_MC_1                          73 /* ID for TCC4 event user MC_1 */
#define EVENT_ID_USER_TCC5_EV_0                          74 /* ID for TCC5 event user EV_0 */
#define EVENT_ID_USER_TCC5_EV_1                          75 /* ID for TCC5 event user EV_1 */
#define EVENT_ID_USER_TCC5_MC_0                          76 /* ID for TCC5 event user MC_0 */
#define EVENT_ID_USER_TCC5_MC_1                          77 /* ID for TCC5 event user MC_1 */
#define EVENT_ID_USER_TCC6_EV_0                          78 /* ID for TCC6 event user EV_0 */
#define EVENT_ID_USER_TCC6_EV_1                          79 /* ID for TCC6 event user EV_1 */
#define EVENT_ID_USER_TCC6_MC_0                          80 /* ID for TCC6 event user MC_0 */
#define EVENT_ID_USER_TCC6_MC_1                          81 /* ID for TCC6 event user MC_1 */
#define EVENT_ID_USER_TCC7_EV_0                          82 /* ID for TCC7 event user EV_0 */
#define EVENT_ID_USER_TCC7_EV_1                          83 /* ID for TCC7 event user EV_1 */
#define EVENT_ID_USER_TCC7_MC_0                          84 /* ID for TCC7 event user MC_0 */
#define EVENT_ID_USER_TCC7_MC_1                          85 /* ID for TCC7 event user MC_1 */
#define EVENT_ID_USER_TCC8_EV_0                          86 /* ID for TCC8 event user EV_0 */
#define EVENT_ID_USER_TCC8_EV_1                          87 /* ID for TCC8 event user EV_1 */
#define EVENT_ID_USER_TCC8_MC_0                          88 /* ID for TCC8 event user MC_0 */
#define EVENT_ID_USER_TCC8_MC_1                          89 /* ID for TCC8 event user MC_1 */
#define EVENT_ID_USER_TCC9_EV_0                          90 /* ID for TCC9 event user EV_0 */
#define EVENT_ID_USER_TCC9_EV_1                          91 /* ID for TCC9 event user EV_1 */
#define EVENT_ID_USER_TCC9_MC_0                          92 /* ID for TCC9 event user MC_0 */
#define EVENT_ID_USER_TCC9_MC_1                          93 /* ID for TCC9 event user MC_1 */
#define EVENT_ID_USER_TCC9_MC_2                          94 /* ID for TCC9 event user MC_2 */
#define EVENT_ID_USER_TCC9_MC_3                          95 /* ID for TCC9 event user MC_3 */
#define EVENT_ID_USER_TCC9_MC_4                          96 /* ID for TCC9 event user MC_4 */
#define EVENT_ID_USER_TCC9_MC_5                          97 /* ID for TCC9 event user MC_5 */
#define EVENT_ID_USER_ADC_TRIGGERS_0                     98 /* ID for ADC event user TRIGGERS_0 */
#define EVENT_ID_USER_ADC_TRIGGERS_1                     99 /* ID for ADC event user TRIGGERS_1 */
#define EVENT_ID_USER_ADC_TRIGGERS_2                    100 /* ID for ADC event user TRIGGERS_2 */
#define EVENT_ID_USER_ADC_TRIGGERS_3                    101 /* ID for ADC event user TRIGGERS_3 */
#define EVENT_ID_USER_ADC_TRIGGERS_4                    102 /* ID for ADC event user TRIGGERS_4 */
#define EVENT_ID_USER_ADC_TRIGGERS_5                    103 /* ID for ADC event user TRIGGERS_5 */
#define EVENT_ID_USER_ADC_TRIGGERS_6                    104 /* ID for ADC event user TRIGGERS_6 */
#define EVENT_ID_USER_ADC_TRIGGERS_7                    105 /* ID for ADC event user TRIGGERS_7 */
#define EVENT_ID_USER_ADC_TRIGGERS_8                    106 /* ID for ADC event user TRIGGERS_8 */
#define EVENT_ID_USER_ADC_TRIGGERS_9                    107 /* ID for ADC event user TRIGGERS_9 */
#define EVENT_ID_USER_ADC_TRIGGERS_10                   108 /* ID for ADC event user TRIGGERS_10 */
#define EVENT_ID_USER_AC_SOC_0                          109 /* ID for AC event user SOC_0 */
#define EVENT_ID_USER_AC_SOC_1                          110 /* ID for AC event user SOC_1 */
#define EVENT_ID_USER_PTC_DSEQR                         111 /* ID for PTC event user DSEQR */
#define EVENT_ID_USER_PTC_STCONV                        112 /* ID for PTC event user STCONV */
#define EVENT_ID_USER_HSM_TAMPER_0                      113 /* ID for HSM event user TAMPER_0 */
#define EVENT_ID_USER_HSM_TAMPER_1                      114 /* ID for HSM event user TAMPER_1 */
#define EVENT_ID_USER_HSM_TAMPER_2                      115 /* ID for HSM event user TAMPER_2 */
#define EVENT_ID_USER_HSM_TAMPER_3                      116 /* ID for HSM event user TAMPER_3 */

#ifdef __cplusplus
}
#endif

#endif /* _PIC32CZ8110CA80208_H_ */

