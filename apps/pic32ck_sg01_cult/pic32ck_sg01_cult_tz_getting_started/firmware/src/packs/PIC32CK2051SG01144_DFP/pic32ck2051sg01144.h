/*
 * Header file for PIC32CK2051SG01144
 *
 * Copyright (c) 2023 Microchip Technology Inc. and its subsidiaries.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/* File generated from device description file (ATDF) version 2023-11-16T06:44:02Z */
#ifndef _PIC32CK2051SG01144_H_
#define _PIC32CK2051SG01144_H_

/* Header version uses Semantic Versioning 2.0.0 (https://semver.org/) */
#define HEADER_FORMAT_VERSION "2.1.1"

#define HEADER_FORMAT_VERSION_MAJOR (2)
#define HEADER_FORMAT_VERSION_MINOR (1)
#define HEADER_FORMAT_VERSION_PATCH (1)

/* PIC32CK2051SG01144 definitions
  This file defines all structures and symbols for PIC32CK2051SG01144:
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
/* CMSIS DEFINITIONS FOR PIC32CK2051SG01144                                 */
/* ************************************************************************** */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* Interrupt Number Definition */
typedef enum IRQn
{
/******  CORTEX-M33 Processor Exceptions Numbers ******************************/
  Reset_IRQn                = -15, /* -15 Reset Vector, invoked on Power up and warm reset */
  NonMaskableInt_IRQn       = -14, /* -14 Non maskable Interrupt, cannot be stopped or preempted */
  HardFault_IRQn            = -13, /* -13 Hard Fault, all classes of Fault    */
  MemoryManagement_IRQn     = -12, /* -12 Memory Management, MPU mismatch, including Access Violation and No Match */
  BusFault_IRQn             = -11, /* -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
  UsageFault_IRQn           = -10, /* -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition */
  SecureFaultMonitor_IRQn   =  -9, /* -9  Secure Fault                        */
  SVCall_IRQn               =  -5, /* -5  System Service Call via SVC instruction */
  DebugMonitor_IRQn         =  -4, /* -4  Debug Monitor                       */
  PendSV_IRQn               =  -2, /* -2  Pendable request for system service */
  SysTick_IRQn              =  -1, /* -1  System Tick Timer                   */

/******  PIC32CK2051SG01144 specific Interrupt Numbers ***********************************/
  FCR_ERR_IRQn              =   0, /* 0   Flash Read Controller (FCR) (FCR)   */
  FCR_FLT_IRQn              =   1, /* 1   Flash Read Controller (FCR) (FCR)   */
  FCW_IRQn                  =   2, /* 2   Flash Write Control (FCW) (FCW)     */
  PM_IRQn                   =   3, /* 3   Power Manager (PM)                  */
  SUPC_IRQn                 =   4, /* 4   Supply Controller (SUPC)            */
  OSCCTRL_XOSC_IRQn         =   5, /* 5   Oscillators Control (OSCCTRL)       */
  OSCCTRL_DFLL_IRQn         =   6, /* 6   Oscillators Control (OSCCTRL)       */
  OSCCTRL_PLL0_IRQn         =   7, /* 7   Oscillators Control (OSCCTRL)       */
  OSC32KCTRL_IRQn           =   8, /* 8   32kHz Oscillators Control (OSC32KCTRL) */
  MCLK_IRQn                 =   9, /* 9   Main Clock (MCLK)                   */
  FREQM_IRQn                =  10, /* 10  Frequency Meter (FREQM)             */
  WDT_IRQn                  =  11, /* 11  Watchdog Timer (WDT)                */
  RTC_IRQn                  =  12, /* 12  Real-Time Counter (RTC)             */
  EIC_EXTINT_0_IRQn         =  13, /* 13  External Interrupt Controller (EIC) */
  EIC_EXTINT_1_IRQn         =  14, /* 14  External Interrupt Controller (EIC) */
  EIC_EXTINT_2_IRQn         =  15, /* 15  External Interrupt Controller (EIC) */
  EIC_EXTINT_3_IRQn         =  16, /* 16  External Interrupt Controller (EIC) */
  EIC_EXTINT_4_IRQn         =  17, /* 17  External Interrupt Controller (EIC) */
  EIC_EXTINT_5_IRQn         =  18, /* 18  External Interrupt Controller (EIC) */
  EIC_EXTINT_6_IRQn         =  19, /* 19  External Interrupt Controller (EIC) */
  EIC_EXTINT_7_IRQn         =  20, /* 20  External Interrupt Controller (EIC) */
  EIC_EXTINT_8_IRQn         =  21, /* 21  External Interrupt Controller (EIC) */
  EIC_EXTINT_9_IRQn         =  22, /* 22  External Interrupt Controller (EIC) */
  EIC_EXTINT_10_IRQn        =  23, /* 23  External Interrupt Controller (EIC) */
  EIC_EXTINT_11_IRQn        =  24, /* 24  External Interrupt Controller (EIC) */
  EIC_EXTINT_12_IRQn        =  25, /* 25  External Interrupt Controller (EIC) */
  EIC_EXTINT_13_IRQn        =  26, /* 26  External Interrupt Controller (EIC) */
  EIC_EXTINT_14_IRQn        =  27, /* 27  External Interrupt Controller (EIC) */
  EIC_EXTINT_15_IRQn        =  28, /* 28  External Interrupt Controller (EIC) */
  EIC_NSCHK_IRQn            =  29, /* 29  External Interrupt Controller (EIC) */
  PAC_IRQn                  =  30, /* 30  Peripheral Access Controller (PAC)  */
  TRAM_IRQn                 =  31, /* 31  TrustRAM (TRAM)                     */
  PORT_IRQn                 =  32, /* 32  Port Module (PORT)                  */
  DMA0_PRI0_IRQn            =  33, /* 33  Direct Memory Access Controller (DMA0) */
  DMA0_PRI1_IRQn            =  34, /* 34  Direct Memory Access Controller (DMA0) */
  DMA0_PRI2_IRQn            =  35, /* 35  Direct Memory Access Controller (DMA0) */
  DMA1_PRI0_IRQn            =  36, /* 36  Direct Memory Access Controller (DMA1) */
  DMA1_PRI1_IRQn            =  37, /* 37  Direct Memory Access Controller (DMA1) */
  HMATRIX_IRQn              =  38, /* 38  HSB Matrix (HMATRIX)                */
  EVSYS_0_IRQn              =  39, /* 39  Event System Interface (EVSYS)      */
  EVSYS_1_IRQn              =  40, /* 40  Event System Interface (EVSYS)      */
  EVSYS_2_IRQn              =  41, /* 41  Event System Interface (EVSYS)      */
  EVSYS_3_IRQn              =  42, /* 42  Event System Interface (EVSYS)      */
  EVSYS_OTHER_IRQn          =  43, /* 43  Event System Interface (EVSYS)      */
  SERCOM0_56_IRQn           =  44, /* 44  Serial Communication Interface (SERCOM0) */
  SERCOM0_0_IRQn            =  45, /* 45  Serial Communication Interface (SERCOM0) */
  SERCOM0_1_IRQn            =  46, /* 46  Serial Communication Interface (SERCOM0) */
  SERCOM0_2_IRQn            =  47, /* 47  Serial Communication Interface (SERCOM0) */
  SERCOM0_3_IRQn            =  48, /* 48  Serial Communication Interface (SERCOM0) */
  SERCOM0_4_IRQn            =  49, /* 49  Serial Communication Interface (SERCOM0) */
  SERCOM1_56_IRQn           =  50, /* 50  Serial Communication Interface (SERCOM1) */
  SERCOM1_0_IRQn            =  51, /* 51  Serial Communication Interface (SERCOM1) */
  SERCOM1_1_IRQn            =  52, /* 52  Serial Communication Interface (SERCOM1) */
  SERCOM1_2_IRQn            =  53, /* 53  Serial Communication Interface (SERCOM1) */
  SERCOM1_3_IRQn            =  54, /* 54  Serial Communication Interface (SERCOM1) */
  SERCOM1_4_IRQn            =  55, /* 55  Serial Communication Interface (SERCOM1) */
  SERCOM2_56_IRQn           =  56, /* 56  Serial Communication Interface (SERCOM2) */
  SERCOM2_0_IRQn            =  57, /* 57  Serial Communication Interface (SERCOM2) */
  SERCOM2_1_IRQn            =  58, /* 58  Serial Communication Interface (SERCOM2) */
  SERCOM2_2_IRQn            =  59, /* 59  Serial Communication Interface (SERCOM2) */
  SERCOM2_3_IRQn            =  60, /* 60  Serial Communication Interface (SERCOM2) */
  SERCOM2_4_IRQn            =  61, /* 61  Serial Communication Interface (SERCOM2) */
  SERCOM3_56_IRQn           =  62, /* 62  Serial Communication Interface (SERCOM3) */
  SERCOM3_0_IRQn            =  63, /* 63  Serial Communication Interface (SERCOM3) */
  SERCOM3_1_IRQn            =  64, /* 64  Serial Communication Interface (SERCOM3) */
  SERCOM3_2_IRQn            =  65, /* 65  Serial Communication Interface (SERCOM3) */
  SERCOM3_3_IRQn            =  66, /* 66  Serial Communication Interface (SERCOM3) */
  SERCOM3_4_IRQn            =  67, /* 67  Serial Communication Interface (SERCOM3) */
  TCC0_OTHER_IRQn           =  68, /* 68  Timer Counter for Control Applications (TCC0) */
  TCC0_MC0_IRQn             =  69, /* 69  Timer Counter for Control Applications (TCC0) */
  TCC0_MC1_IRQn             =  70, /* 70  Timer Counter for Control Applications (TCC0) */
  TCC0_MC2_IRQn             =  71, /* 71  Timer Counter for Control Applications (TCC0) */
  TCC0_MC3_IRQn             =  72, /* 72  Timer Counter for Control Applications (TCC0) */
  TCC0_MC4_IRQn             =  73, /* 73  Timer Counter for Control Applications (TCC0) */
  TCC0_MC5_IRQn             =  74, /* 74  Timer Counter for Control Applications (TCC0) */
  TCC1_OTHER_IRQn           =  75, /* 75  Timer Counter for Control Applications (TCC1) */
  TCC1_MC0_IRQn             =  76, /* 76  Timer Counter for Control Applications (TCC1) */
  TCC1_MC1_IRQn             =  77, /* 77  Timer Counter for Control Applications (TCC1) */
  TCC1_MC2_IRQn             =  78, /* 78  Timer Counter for Control Applications (TCC1) */
  TCC1_MC3_IRQn             =  79, /* 79  Timer Counter for Control Applications (TCC1) */
  TCC1_MC4_IRQn             =  80, /* 80  Timer Counter for Control Applications (TCC1) */
  TCC1_MC5_IRQn             =  81, /* 81  Timer Counter for Control Applications (TCC1) */
  TCC2_OTHER_IRQn           =  82, /* 82  Timer Counter for Control Applications (TCC2) */
  TCC2_MC0_IRQn             =  83, /* 83  Timer Counter for Control Applications (TCC2) */
  TCC2_MC1_IRQn             =  84, /* 84  Timer Counter for Control Applications (TCC2) */
  TCC2_MC2_IRQn             =  85, /* 85  Timer Counter for Control Applications (TCC2) */
  TCC2_MC3_IRQn             =  86, /* 86  Timer Counter for Control Applications (TCC2) */
  TCC2_MC4_IRQn             =  87, /* 87  Timer Counter for Control Applications (TCC2) */
  TCC2_MC5_IRQn             =  88, /* 88  Timer Counter for Control Applications (TCC2) */
  TCC3_OTHER_IRQn           =  89, /* 89  Timer Counter for Control Applications (TCC3) */
  TCC3_MC0_IRQn             =  90, /* 90  Timer Counter for Control Applications (TCC3) */
  TCC3_MC1_IRQn             =  91, /* 91  Timer Counter for Control Applications (TCC3) */
  TCC3_MC2_IRQn             =  92, /* 92  Timer Counter for Control Applications (TCC3) */
  TCC3_MC3_IRQn             =  93, /* 93  Timer Counter for Control Applications (TCC3) */
  TCC3_MC4_IRQn             =  94, /* 94  Timer Counter for Control Applications (TCC3) */
  TCC3_MC5_IRQn             =  95, /* 95  Timer Counter for Control Applications (TCC3) */
  SERCOM4_56_IRQn           =  96, /* 96  Serial Communication Interface (SERCOM4) */
  SERCOM4_0_IRQn            =  97, /* 97  Serial Communication Interface (SERCOM4) */
  SERCOM4_1_IRQn            =  98, /* 98  Serial Communication Interface (SERCOM4) */
  SERCOM4_2_IRQn            =  99, /* 99  Serial Communication Interface (SERCOM4) */
  SERCOM4_3_IRQn            = 100, /* 100 Serial Communication Interface (SERCOM4) */
  SERCOM4_4_IRQn            = 101, /* 101 Serial Communication Interface (SERCOM4) */
  SERCOM5_56_IRQn           = 102, /* 102 Serial Communication Interface (SERCOM5) */
  SERCOM5_0_IRQn            = 103, /* 103 Serial Communication Interface (SERCOM5) */
  SERCOM5_1_IRQn            = 104, /* 104 Serial Communication Interface (SERCOM5) */
  SERCOM5_2_IRQn            = 105, /* 105 Serial Communication Interface (SERCOM5) */
  SERCOM5_3_IRQn            = 106, /* 106 Serial Communication Interface (SERCOM5) */
  SERCOM5_4_IRQn            = 107, /* 107 Serial Communication Interface (SERCOM5) */
  SERCOM6_56_IRQn           = 108, /* 108 Serial Communication Interface (SERCOM6) */
  SERCOM6_0_IRQn            = 109, /* 109 Serial Communication Interface (SERCOM6) */
  SERCOM6_1_IRQn            = 110, /* 110 Serial Communication Interface (SERCOM6) */
  SERCOM6_2_IRQn            = 111, /* 111 Serial Communication Interface (SERCOM6) */
  SERCOM6_3_IRQn            = 112, /* 112 Serial Communication Interface (SERCOM6) */
  SERCOM6_4_IRQn            = 113, /* 113 Serial Communication Interface (SERCOM6) */
  SERCOM7_56_IRQn           = 114, /* 114 Serial Communication Interface (SERCOM7) */
  SERCOM7_0_IRQn            = 115, /* 115 Serial Communication Interface (SERCOM7) */
  SERCOM7_1_IRQn            = 116, /* 116 Serial Communication Interface (SERCOM7) */
  SERCOM7_2_IRQn            = 117, /* 117 Serial Communication Interface (SERCOM7) */
  SERCOM7_3_IRQn            = 118, /* 118 Serial Communication Interface (SERCOM7) */
  SERCOM7_4_IRQn            = 119, /* 119 Serial Communication Interface (SERCOM7) */
  TCC4_OTHER_IRQn           = 120, /* 120 Timer Counter for Control Applications (TCC4) */
  TCC4_MC0_IRQn             = 121, /* 121 Timer Counter for Control Applications (TCC4) */
  TCC4_MC1_IRQn             = 122, /* 122 Timer Counter for Control Applications (TCC4) */
  TCC5_OTHER_IRQn           = 123, /* 123 Timer Counter for Control Applications (TCC5) */
  TCC5_MC0_IRQn             = 124, /* 124 Timer Counter for Control Applications (TCC5) */
  TCC5_MC1_IRQn             = 125, /* 125 Timer Counter for Control Applications (TCC5) */
  TCC6_OTHER_IRQn           = 126, /* 126 Timer Counter for Control Applications (TCC6) */
  TCC6_MC0_IRQn             = 127, /* 127 Timer Counter for Control Applications (TCC6) */
  TCC6_MC1_IRQn             = 128, /* 128 Timer Counter for Control Applications (TCC6) */
  TCC7_OTHER_IRQn           = 129, /* 129 Timer Counter for Control Applications (TCC7) */
  TCC7_MC0_IRQn             = 130, /* 130 Timer Counter for Control Applications (TCC7) */
  TCC7_MC1_IRQn             = 131, /* 131 Timer Counter for Control Applications (TCC7) */
  ADC_GLOBAL_IRQn           = 132, /* 132 ADC Controller (ADC)                */
  ADC_CORE1_IRQn            = 133, /* 133 ADC Controller (ADC)                */
  Reserved2_IRQn            = 134, /* 134 ADC Controller (ADC)                */
  Reserved3_IRQn            = 135, /* 135 ADC Controller (ADC)                */
  Reserved4_IRQn            = 136, /* 136 ADC Controller (ADC)                */
  Reserved5_IRQn            = 137, /* 137 ADC Controller (ADC)                */
  AC_IRQn                   = 138, /* 138 Analog Comparator Controller (AC)   */
  PTC_IRQn                  = 139, /* 139 Peripheral Touch Controller (PTC)   */
  SPI_IXS_IRQn              = 140, /* 140 Audio SPI with 8 channels compatibilty (SPI_IXS) */
  PCC_IRQn                  = 141, /* 141 Parallel Capture Controller (PCC)   */
  PDEC_IRQn                 = 142, /* 142 Position Decoder (PDEC)             */
  CAN0_IRQn                 = 143, /* 143 Control Area Network (CAN0)         */
  CAN1_IRQn                 = 144, /* 144 Control Area Network (CAN1)         */
  ETH_IRQn                  = 145, /* 145 Ethernet Controller (ETH)           */
  SQI_IRQn                  = 146, /* 146 Polaris Serial Quad Interface SIB (SQI) */
  TRNG_IRQn                 = 147, /* 147 True Random Generator (TRNG)        */
  SDMMC0_IRQn               = 148, /* 148 SD/MMC Host Controller (SDMMC0)     */
  SDMMC1_IRQn               = 149, /* 149 SD/MMC Host Controller (SDMMC1)     */
  USB_OTHER_IRQn            = 150, /* 150 Full-Speed Universal Serial Bus (USB) */
  USB_SOF_IRQn              = 151, /* 151 Full-Speed Universal Serial Bus (USB) */
  USB_TRCPT0_IRQn           = 152, /* 152 Full-Speed Universal Serial Bus (USB) */
  USB_TRCPT1_IRQn           = 153, /* 153 Full-Speed Universal Serial Bus (USB) */
  USBHS_IRQn                = 154, /* 154 USB High Speed (USBHS)              */
  HSM_ERROR_IRQn            = 155, /* 155 Hardware Security Module (HSM)      */
  HSM_TXINT_IRQn            = 156, /* 156 Hardware Security Module (HSM)      */
  HSM_RXINT_IRQn            = 157, /* 157 Hardware Security Module (HSM)      */

  PERIPH_MAX_IRQn           = 157  /* Max peripheral ID */
} IRQn_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef struct _DeviceVectors
{
  /* Stack pointer */
  void* pvStack;
  /* CORTEX-M33 handlers */
  void* pfnReset_Handler;                        /* -15 Reset Vector, invoked on Power up and warm reset */
  void* pfnNonMaskableInt_Handler;               /* -14 Non maskable Interrupt, cannot be stopped or preempted */
  void* pfnHardFault_Handler;                    /* -13 Hard Fault, all classes of Fault */
  void* pfnMemoryManagement_Handler;             /* -12 Memory Management, MPU mismatch, including Access Violation and No Match */
  void* pfnBusFault_Handler;                     /* -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
  void* pfnUsageFault_Handler;                   /* -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition */
  void* pfnSecureFaultMonitor_Handler;           /*  -9 Secure Fault */
  void* pvReservedC8;
  void* pvReservedC7;
  void* pvReservedC6;
  void* pfnSVCall_Handler;                       /*  -5 System Service Call via SVC instruction */
  void* pfnDebugMonitor_Handler;                 /*  -4 Debug Monitor */
  void* pvReservedC3;
  void* pfnPendSV_Handler;                       /*  -2 Pendable request for system service */
  void* pfnSysTick_Handler;                      /*  -1 System Tick Timer */

  /* Peripheral handlers */
  void* pfnFCR_ERR_Handler;                      /*   0 Flash Read Controller (FCR) (FCR) */
  void* pfnFCR_FLT_Handler;                      /*   1 Flash Read Controller (FCR) (FCR) */
  void* pfnFCW_Handler;                          /*   2 Flash Write Control (FCW) (FCW) */
  void* pfnPM_Handler;                           /*   3 Power Manager (PM) */
  void* pfnSUPC_Handler;                         /*   4 Supply Controller (SUPC) */
  void* pfnOSCCTRL_XOSC_Handler;                 /*   5 Oscillators Control (OSCCTRL) */
  void* pfnOSCCTRL_DFLL_Handler;                 /*   6 Oscillators Control (OSCCTRL) */
  void* pfnOSCCTRL_PLL0_Handler;                 /*   7 Oscillators Control (OSCCTRL) */
  void* pfnOSC32KCTRL_Handler;                   /*   8 32kHz Oscillators Control (OSC32KCTRL) */
  void* pfnMCLK_Handler;                         /*   9 Main Clock (MCLK) */
  void* pfnFREQM_Handler;                        /*  10 Frequency Meter (FREQM) */
  void* pfnWDT_Handler;                          /*  11 Watchdog Timer (WDT) */
  void* pfnRTC_Handler;                          /*  12 Real-Time Counter (RTC) */
  void* pfnEIC_EXTINT_0_Handler;                 /*  13 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_1_Handler;                 /*  14 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_2_Handler;                 /*  15 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_3_Handler;                 /*  16 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_4_Handler;                 /*  17 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_5_Handler;                 /*  18 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_6_Handler;                 /*  19 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_7_Handler;                 /*  20 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_8_Handler;                 /*  21 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_9_Handler;                 /*  22 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_10_Handler;                /*  23 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_11_Handler;                /*  24 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_12_Handler;                /*  25 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_13_Handler;                /*  26 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_14_Handler;                /*  27 External Interrupt Controller (EIC) */
  void* pfnEIC_EXTINT_15_Handler;                /*  28 External Interrupt Controller (EIC) */
  void* pfnEIC_NSCHK_Handler;                    /*  29 External Interrupt Controller (EIC) */
  void* pfnPAC_Handler;                          /*  30 Peripheral Access Controller (PAC) */
  void* pfnTRAM_Handler;                         /*  31 TrustRAM (TRAM) */
  void* pfnPORT_Handler;                         /*  32 Port Module (PORT) */
  void* pfnDMA0_PRI0_Handler;                    /*  33 Direct Memory Access Controller (DMA0) */
  void* pfnDMA0_PRI1_Handler;                    /*  34 Direct Memory Access Controller (DMA0) */
  void* pfnDMA0_PRI2_Handler;                    /*  35 Direct Memory Access Controller (DMA0) */
  void* pfnDMA1_PRI0_Handler;                    /*  36 Direct Memory Access Controller (DMA1) */
  void* pfnDMA1_PRI1_Handler;                    /*  37 Direct Memory Access Controller (DMA1) */
  void* pfnHMATRIX_Handler;                      /*  38 HSB Matrix (HMATRIX) */
  void* pfnEVSYS_0_Handler;                      /*  39 Event System Interface (EVSYS) */
  void* pfnEVSYS_1_Handler;                      /*  40 Event System Interface (EVSYS) */
  void* pfnEVSYS_2_Handler;                      /*  41 Event System Interface (EVSYS) */
  void* pfnEVSYS_3_Handler;                      /*  42 Event System Interface (EVSYS) */
  void* pfnEVSYS_OTHER_Handler;                  /*  43 Event System Interface (EVSYS) */
  void* pfnSERCOM0_56_Handler;                   /*  44 Serial Communication Interface (SERCOM0) */
  void* pfnSERCOM0_0_Handler;                    /*  45 Serial Communication Interface (SERCOM0) */
  void* pfnSERCOM0_1_Handler;                    /*  46 Serial Communication Interface (SERCOM0) */
  void* pfnSERCOM0_2_Handler;                    /*  47 Serial Communication Interface (SERCOM0) */
  void* pfnSERCOM0_3_Handler;                    /*  48 Serial Communication Interface (SERCOM0) */
  void* pfnSERCOM0_4_Handler;                    /*  49 Serial Communication Interface (SERCOM0) */
  void* pfnSERCOM1_56_Handler;                   /*  50 Serial Communication Interface (SERCOM1) */
  void* pfnSERCOM1_0_Handler;                    /*  51 Serial Communication Interface (SERCOM1) */
  void* pfnSERCOM1_1_Handler;                    /*  52 Serial Communication Interface (SERCOM1) */
  void* pfnSERCOM1_2_Handler;                    /*  53 Serial Communication Interface (SERCOM1) */
  void* pfnSERCOM1_3_Handler;                    /*  54 Serial Communication Interface (SERCOM1) */
  void* pfnSERCOM1_4_Handler;                    /*  55 Serial Communication Interface (SERCOM1) */
  void* pfnSERCOM2_56_Handler;                   /*  56 Serial Communication Interface (SERCOM2) */
  void* pfnSERCOM2_0_Handler;                    /*  57 Serial Communication Interface (SERCOM2) */
  void* pfnSERCOM2_1_Handler;                    /*  58 Serial Communication Interface (SERCOM2) */
  void* pfnSERCOM2_2_Handler;                    /*  59 Serial Communication Interface (SERCOM2) */
  void* pfnSERCOM2_3_Handler;                    /*  60 Serial Communication Interface (SERCOM2) */
  void* pfnSERCOM2_4_Handler;                    /*  61 Serial Communication Interface (SERCOM2) */
  void* pfnSERCOM3_56_Handler;                   /*  62 Serial Communication Interface (SERCOM3) */
  void* pfnSERCOM3_0_Handler;                    /*  63 Serial Communication Interface (SERCOM3) */
  void* pfnSERCOM3_1_Handler;                    /*  64 Serial Communication Interface (SERCOM3) */
  void* pfnSERCOM3_2_Handler;                    /*  65 Serial Communication Interface (SERCOM3) */
  void* pfnSERCOM3_3_Handler;                    /*  66 Serial Communication Interface (SERCOM3) */
  void* pfnSERCOM3_4_Handler;                    /*  67 Serial Communication Interface (SERCOM3) */
  void* pfnTCC0_OTHER_Handler;                   /*  68 Timer Counter for Control Applications (TCC0) */
  void* pfnTCC0_MC0_Handler;                     /*  69 Timer Counter for Control Applications (TCC0) */
  void* pfnTCC0_MC1_Handler;                     /*  70 Timer Counter for Control Applications (TCC0) */
  void* pfnTCC0_MC2_Handler;                     /*  71 Timer Counter for Control Applications (TCC0) */
  void* pfnTCC0_MC3_Handler;                     /*  72 Timer Counter for Control Applications (TCC0) */
  void* pfnTCC0_MC4_Handler;                     /*  73 Timer Counter for Control Applications (TCC0) */
  void* pfnTCC0_MC5_Handler;                     /*  74 Timer Counter for Control Applications (TCC0) */
  void* pfnTCC1_OTHER_Handler;                   /*  75 Timer Counter for Control Applications (TCC1) */
  void* pfnTCC1_MC0_Handler;                     /*  76 Timer Counter for Control Applications (TCC1) */
  void* pfnTCC1_MC1_Handler;                     /*  77 Timer Counter for Control Applications (TCC1) */
  void* pfnTCC1_MC2_Handler;                     /*  78 Timer Counter for Control Applications (TCC1) */
  void* pfnTCC1_MC3_Handler;                     /*  79 Timer Counter for Control Applications (TCC1) */
  void* pfnTCC1_MC4_Handler;                     /*  80 Timer Counter for Control Applications (TCC1) */
  void* pfnTCC1_MC5_Handler;                     /*  81 Timer Counter for Control Applications (TCC1) */
  void* pfnTCC2_OTHER_Handler;                   /*  82 Timer Counter for Control Applications (TCC2) */
  void* pfnTCC2_MC0_Handler;                     /*  83 Timer Counter for Control Applications (TCC2) */
  void* pfnTCC2_MC1_Handler;                     /*  84 Timer Counter for Control Applications (TCC2) */
  void* pfnTCC2_MC2_Handler;                     /*  85 Timer Counter for Control Applications (TCC2) */
  void* pfnTCC2_MC3_Handler;                     /*  86 Timer Counter for Control Applications (TCC2) */
  void* pfnTCC2_MC4_Handler;                     /*  87 Timer Counter for Control Applications (TCC2) */
  void* pfnTCC2_MC5_Handler;                     /*  88 Timer Counter for Control Applications (TCC2) */
  void* pfnTCC3_OTHER_Handler;                   /*  89 Timer Counter for Control Applications (TCC3) */
  void* pfnTCC3_MC0_Handler;                     /*  90 Timer Counter for Control Applications (TCC3) */
  void* pfnTCC3_MC1_Handler;                     /*  91 Timer Counter for Control Applications (TCC3) */
  void* pfnTCC3_MC2_Handler;                     /*  92 Timer Counter for Control Applications (TCC3) */
  void* pfnTCC3_MC3_Handler;                     /*  93 Timer Counter for Control Applications (TCC3) */
  void* pfnTCC3_MC4_Handler;                     /*  94 Timer Counter for Control Applications (TCC3) */
  void* pfnTCC3_MC5_Handler;                     /*  95 Timer Counter for Control Applications (TCC3) */
  void* pfnSERCOM4_56_Handler;                   /*  96 Serial Communication Interface (SERCOM4) */
  void* pfnSERCOM4_0_Handler;                    /*  97 Serial Communication Interface (SERCOM4) */
  void* pfnSERCOM4_1_Handler;                    /*  98 Serial Communication Interface (SERCOM4) */
  void* pfnSERCOM4_2_Handler;                    /*  99 Serial Communication Interface (SERCOM4) */
  void* pfnSERCOM4_3_Handler;                    /* 100 Serial Communication Interface (SERCOM4) */
  void* pfnSERCOM4_4_Handler;                    /* 101 Serial Communication Interface (SERCOM4) */
  void* pfnSERCOM5_56_Handler;                   /* 102 Serial Communication Interface (SERCOM5) */
  void* pfnSERCOM5_0_Handler;                    /* 103 Serial Communication Interface (SERCOM5) */
  void* pfnSERCOM5_1_Handler;                    /* 104 Serial Communication Interface (SERCOM5) */
  void* pfnSERCOM5_2_Handler;                    /* 105 Serial Communication Interface (SERCOM5) */
  void* pfnSERCOM5_3_Handler;                    /* 106 Serial Communication Interface (SERCOM5) */
  void* pfnSERCOM5_4_Handler;                    /* 107 Serial Communication Interface (SERCOM5) */
  void* pfnSERCOM6_56_Handler;                   /* 108 Serial Communication Interface (SERCOM6) */
  void* pfnSERCOM6_0_Handler;                    /* 109 Serial Communication Interface (SERCOM6) */
  void* pfnSERCOM6_1_Handler;                    /* 110 Serial Communication Interface (SERCOM6) */
  void* pfnSERCOM6_2_Handler;                    /* 111 Serial Communication Interface (SERCOM6) */
  void* pfnSERCOM6_3_Handler;                    /* 112 Serial Communication Interface (SERCOM6) */
  void* pfnSERCOM6_4_Handler;                    /* 113 Serial Communication Interface (SERCOM6) */
  void* pfnSERCOM7_56_Handler;                   /* 114 Serial Communication Interface (SERCOM7) */
  void* pfnSERCOM7_0_Handler;                    /* 115 Serial Communication Interface (SERCOM7) */
  void* pfnSERCOM7_1_Handler;                    /* 116 Serial Communication Interface (SERCOM7) */
  void* pfnSERCOM7_2_Handler;                    /* 117 Serial Communication Interface (SERCOM7) */
  void* pfnSERCOM7_3_Handler;                    /* 118 Serial Communication Interface (SERCOM7) */
  void* pfnSERCOM7_4_Handler;                    /* 119 Serial Communication Interface (SERCOM7) */
  void* pfnTCC4_OTHER_Handler;                   /* 120 Timer Counter for Control Applications (TCC4) */
  void* pfnTCC4_MC0_Handler;                     /* 121 Timer Counter for Control Applications (TCC4) */
  void* pfnTCC4_MC1_Handler;                     /* 122 Timer Counter for Control Applications (TCC4) */
  void* pfnTCC5_OTHER_Handler;                   /* 123 Timer Counter for Control Applications (TCC5) */
  void* pfnTCC5_MC0_Handler;                     /* 124 Timer Counter for Control Applications (TCC5) */
  void* pfnTCC5_MC1_Handler;                     /* 125 Timer Counter for Control Applications (TCC5) */
  void* pfnTCC6_OTHER_Handler;                   /* 126 Timer Counter for Control Applications (TCC6) */
  void* pfnTCC6_MC0_Handler;                     /* 127 Timer Counter for Control Applications (TCC6) */
  void* pfnTCC6_MC1_Handler;                     /* 128 Timer Counter for Control Applications (TCC6) */
  void* pfnTCC7_OTHER_Handler;                   /* 129 Timer Counter for Control Applications (TCC7) */
  void* pfnTCC7_MC0_Handler;                     /* 130 Timer Counter for Control Applications (TCC7) */
  void* pfnTCC7_MC1_Handler;                     /* 131 Timer Counter for Control Applications (TCC7) */
  void* pfnADC_GLOBAL_Handler;                   /* 132 ADC Controller (ADC) */
  void* pfnADC_CORE1_Handler;                    /* 133 ADC Controller (ADC) */
  void* pfnReserved2_Handler;                    /* 134 ADC Controller (ADC) */
  void* pfnReserved3_Handler;                    /* 135 ADC Controller (ADC) */
  void* pfnReserved4_Handler;                    /* 136 ADC Controller (ADC) */
  void* pfnReserved5_Handler;                    /* 137 ADC Controller (ADC) */
  void* pfnAC_Handler;                           /* 138 Analog Comparator Controller (AC) */
  void* pfnPTC_Handler;                          /* 139 Peripheral Touch Controller (PTC) */
  void* pfnSPI_IXS_Handler;                      /* 140 Audio SPI with 8 channels compatibilty (SPI_IXS) */
  void* pfnPCC_Handler;                          /* 141 Parallel Capture Controller (PCC) */
  void* pfnPDEC_Handler;                         /* 142 Position Decoder (PDEC) */
  void* pfnCAN0_Handler;                         /* 143 Control Area Network (CAN0) */
  void* pfnCAN1_Handler;                         /* 144 Control Area Network (CAN1) */
  void* pfnETH_Handler;                          /* 145 Ethernet Controller (ETH) */
  void* pfnSQI_Handler;                          /* 146 Polaris Serial Quad Interface SIB (SQI) */
  void* pfnTRNG_Handler;                         /* 147 True Random Generator (TRNG) */
  void* pfnSDMMC0_Handler;                       /* 148 SD/MMC Host Controller (SDMMC0) */
  void* pfnSDMMC1_Handler;                       /* 149 SD/MMC Host Controller (SDMMC1) */
  void* pfnUSB_OTHER_Handler;                    /* 150 Full-Speed Universal Serial Bus (USB) */
  void* pfnUSB_SOF_Handler;                      /* 151 Full-Speed Universal Serial Bus (USB) */
  void* pfnUSB_TRCPT0_Handler;                   /* 152 Full-Speed Universal Serial Bus (USB) */
  void* pfnUSB_TRCPT1_Handler;                   /* 153 Full-Speed Universal Serial Bus (USB) */
  void* pfnUSBHS_Handler;                        /* 154 USB High Speed (USBHS) */
  void* pfnHSM_ERROR_Handler;                    /* 155 Hardware Security Module (HSM) */
  void* pfnHSM_TXINT_Handler;                    /* 156 Hardware Security Module (HSM) */
  void* pfnHSM_RXINT_Handler;                    /* 157 Hardware Security Module (HSM) */
} DeviceVectors;

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if !defined DONT_USE_PREDEFINED_CORE_HANDLERS
/* CORTEX-M33 exception handlers */
void Reset_Handler                 ( void );
void NonMaskableInt_Handler        ( void );
void HardFault_Handler             ( void );
void MemoryManagement_Handler      ( void );
void BusFault_Handler              ( void );
void UsageFault_Handler            ( void );
void SecureFaultMonitor_Handler    ( void );
void SVCall_Handler                ( void );
void DebugMonitor_Handler          ( void );
void PendSV_Handler                ( void );
void SysTick_Handler               ( void );
#endif /* DONT_USE_PREDEFINED_CORE_HANDLERS */

#if !defined DONT_USE_PREDEFINED_PERIPHERALS_HANDLERS
/* Peripherals interrupt handlers */
void FCR_ERR_Handler               ( void );
void FCR_FLT_Handler               ( void );
void FCW_Handler                   ( void );
void PM_Handler                    ( void );
void SUPC_Handler                  ( void );
void OSCCTRL_XOSC_Handler          ( void );
void OSCCTRL_DFLL_Handler          ( void );
void OSCCTRL_PLL0_Handler          ( void );
void OSC32KCTRL_Handler            ( void );
void MCLK_Handler                  ( void );
void FREQM_Handler                 ( void );
void WDT_Handler                   ( void );
void RTC_Handler                   ( void );
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
void EIC_NSCHK_Handler             ( void );
void PAC_Handler                   ( void );
void TRAM_Handler                  ( void );
void PORT_Handler                  ( void );
void DMA0_PRI0_Handler             ( void );
void DMA0_PRI1_Handler             ( void );
void DMA0_PRI2_Handler             ( void );
void DMA1_PRI0_Handler             ( void );
void DMA1_PRI1_Handler             ( void );
void HMATRIX_Handler               ( void );
void EVSYS_0_Handler               ( void );
void EVSYS_1_Handler               ( void );
void EVSYS_2_Handler               ( void );
void EVSYS_3_Handler               ( void );
void EVSYS_OTHER_Handler           ( void );
void SERCOM0_56_Handler            ( void );
void SERCOM0_0_Handler             ( void );
void SERCOM0_1_Handler             ( void );
void SERCOM0_2_Handler             ( void );
void SERCOM0_3_Handler             ( void );
void SERCOM0_4_Handler             ( void );
void SERCOM1_56_Handler            ( void );
void SERCOM1_0_Handler             ( void );
void SERCOM1_1_Handler             ( void );
void SERCOM1_2_Handler             ( void );
void SERCOM1_3_Handler             ( void );
void SERCOM1_4_Handler             ( void );
void SERCOM2_56_Handler            ( void );
void SERCOM2_0_Handler             ( void );
void SERCOM2_1_Handler             ( void );
void SERCOM2_2_Handler             ( void );
void SERCOM2_3_Handler             ( void );
void SERCOM2_4_Handler             ( void );
void SERCOM3_56_Handler            ( void );
void SERCOM3_0_Handler             ( void );
void SERCOM3_1_Handler             ( void );
void SERCOM3_2_Handler             ( void );
void SERCOM3_3_Handler             ( void );
void SERCOM3_4_Handler             ( void );
void TCC0_OTHER_Handler            ( void );
void TCC0_MC0_Handler              ( void );
void TCC0_MC1_Handler              ( void );
void TCC0_MC2_Handler              ( void );
void TCC0_MC3_Handler              ( void );
void TCC0_MC4_Handler              ( void );
void TCC0_MC5_Handler              ( void );
void TCC1_OTHER_Handler            ( void );
void TCC1_MC0_Handler              ( void );
void TCC1_MC1_Handler              ( void );
void TCC1_MC2_Handler              ( void );
void TCC1_MC3_Handler              ( void );
void TCC1_MC4_Handler              ( void );
void TCC1_MC5_Handler              ( void );
void TCC2_OTHER_Handler            ( void );
void TCC2_MC0_Handler              ( void );
void TCC2_MC1_Handler              ( void );
void TCC2_MC2_Handler              ( void );
void TCC2_MC3_Handler              ( void );
void TCC2_MC4_Handler              ( void );
void TCC2_MC5_Handler              ( void );
void TCC3_OTHER_Handler            ( void );
void TCC3_MC0_Handler              ( void );
void TCC3_MC1_Handler              ( void );
void TCC3_MC2_Handler              ( void );
void TCC3_MC3_Handler              ( void );
void TCC3_MC4_Handler              ( void );
void TCC3_MC5_Handler              ( void );
void SERCOM4_56_Handler            ( void );
void SERCOM4_0_Handler             ( void );
void SERCOM4_1_Handler             ( void );
void SERCOM4_2_Handler             ( void );
void SERCOM4_3_Handler             ( void );
void SERCOM4_4_Handler             ( void );
void SERCOM5_56_Handler            ( void );
void SERCOM5_0_Handler             ( void );
void SERCOM5_1_Handler             ( void );
void SERCOM5_2_Handler             ( void );
void SERCOM5_3_Handler             ( void );
void SERCOM5_4_Handler             ( void );
void SERCOM6_56_Handler            ( void );
void SERCOM6_0_Handler             ( void );
void SERCOM6_1_Handler             ( void );
void SERCOM6_2_Handler             ( void );
void SERCOM6_3_Handler             ( void );
void SERCOM6_4_Handler             ( void );
void SERCOM7_56_Handler            ( void );
void SERCOM7_0_Handler             ( void );
void SERCOM7_1_Handler             ( void );
void SERCOM7_2_Handler             ( void );
void SERCOM7_3_Handler             ( void );
void SERCOM7_4_Handler             ( void );
void TCC4_OTHER_Handler            ( void );
void TCC4_MC0_Handler              ( void );
void TCC4_MC1_Handler              ( void );
void TCC5_OTHER_Handler            ( void );
void TCC5_MC0_Handler              ( void );
void TCC5_MC1_Handler              ( void );
void TCC6_OTHER_Handler            ( void );
void TCC6_MC0_Handler              ( void );
void TCC6_MC1_Handler              ( void );
void TCC7_OTHER_Handler            ( void );
void TCC7_MC0_Handler              ( void );
void TCC7_MC1_Handler              ( void );
void ADC_GLOBAL_Handler            ( void );
void ADC_CORE1_Handler             ( void );
void Reserved2_Handler             ( void );
void Reserved3_Handler             ( void );
void Reserved4_Handler             ( void );
void Reserved5_Handler             ( void );
void AC_Handler                    ( void );
void PTC_Handler                   ( void );
void SPI_IXS_Handler               ( void );
void PCC_Handler                   ( void );
void PDEC_Handler                  ( void );
void CAN0_Handler                  ( void );
void CAN1_Handler                  ( void );
void ETH_Handler                   ( void );
void SQI_Handler                   ( void );
void TRNG_Handler                  ( void );
void SDMMC0_Handler                ( void );
void SDMMC1_Handler                ( void );
void USB_OTHER_Handler             ( void );
void USB_SOF_Handler               ( void );
void USB_TRCPT0_Handler            ( void );
void USB_TRCPT1_Handler            ( void );
void USBHS_Handler                 ( void );
void HSM_ERROR_Handler             ( void );
void HSM_TXINT_Handler             ( void );
void HSM_RXINT_Handler             ( void );
#endif /* DONT_USE_PREDEFINED_PERIPHERALS_HANDLERS */
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* Configuration of the CORTEX-M33 Processor and Core Peripherals */
#define __CM33_REV                    0x0000 /* Cortex-M33 Revision                                                       */
#define __DEBUG_LVL                        2 /* Debug Level                                                               */
#define __DSP_PRESENT                      1 /* DSP extension present or not                                              */
#define __FPU_PRESENT                      1 /* FPU present or not                                                        */
#define __MPU_PRESENT                      1 /* MPU present or not                                                        */
#define __NVIC_PRIO_BITS                   3 /* Number of NVIC Priority bits                                              */
#define __TRACE_LVL                        2 /* Trace Level                                                               */
#define __VTOR_PRESENT                     1 /* Vector Table Offset Register present or not                               */
#define __Vendor_SysTickConfig             0 /* Set to 1 if different SysTick Config is used                              */
#define __ARCH_ARM                         1
#define __ARCH_ARM_CORTEX_M                1

/* CMSIS includes */
#include "core_cm33.h"
#if defined USE_CMSIS_INIT
#include "system_pic32cksg01.h"
#endif /* USE_CMSIS_INIT */

/* ************************************************************************** */
/*   SOFTWARE PERIPHERAL API DEFINITION FOR PIC32CK2051SG01144                */
/* ************************************************************************** */
#include "component/ac.h"
#include "component/adc.h"
#include "component/can.h"
#include "component/ccl.h"
#include "component/cmcc.h"
#include "component/dma.h"
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
#include "component/hmatrix2.h"
#include "component/hsm.h"
#include "component/idau.h"
#include "component/mclk.h"
#include "component/osc32kctrl.h"
#include "component/oscctrl.h"
#include "component/pac.h"
#include "component/pcc.h"
#include "component/pdec.h"
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
#include "component/usb.h"
#include "component/usbhs.h"
#include "component/wdt.h"

/* ************************************************************************** */
/*   INSTANCE DEFINITIONS FOR PIC32CK2051SG01144 */
/* ************************************************************************** */
#include "instance/ac.h"
#include "instance/adc.h"
#include "instance/can0.h"
#include "instance/can1.h"
#include "instance/ccl.h"
#include "instance/cmcc.h"
#include "instance/dma0.h"
#include "instance/dma1.h"
#include "instance/dsu.h"
#include "instance/ebi.h"
#include "instance/eic.h"
#include "instance/eth.h"
#include "instance/evsys.h"
#include "instance/fcr.h"
#include "instance/fcw.h"
#include "instance/fpu_ns.h"
#include "instance/freqm.h"
#include "instance/fuses.h"
#include "instance/gclk.h"
#include "instance/hmatrix.h"
#include "instance/hsm.h"
#include "instance/idau.h"
#include "instance/mclk.h"
#include "instance/osc32kctrl.h"
#include "instance/oscctrl.h"
#include "instance/pac.h"
#include "instance/pcc.h"
#include "instance/pdec.h"
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
#include "instance/spi_ixs.h"
#include "instance/sqi.h"
#include "instance/supc.h"
#include "instance/tcc0.h"
#include "instance/tcc1.h"
#include "instance/tcc2.h"
#include "instance/tcc3.h"
#include "instance/tcc4.h"
#include "instance/tcc5.h"
#include "instance/tcc6.h"
#include "instance/tcc7.h"
#include "instance/tram.h"
#include "instance/trng.h"
#include "instance/usb.h"
#include "instance/usbhs.h"
#include "instance/wdt.h"

/* ************************************************************************** */
/*  PERIPHERAL ID DEFINITIONS FOR PIC32CK2051SG01144                          */
/* ************************************************************************** */
#define ID_DSU           (  0) /* Instance index for DSU (DSU) */
#define ID_FCR           (  1) /* Instance index for FCR (FCR) */
#define ID_FCW           (  2) /* Instance index for FCW (FCW) */
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
#define ID_TRAM          ( 15) /* Instance index for TRAM (TRAM) */
#define ID_PORT          ( 32) /* Instance index for PORT (PORT) */
#define ID_DMA0          ( 33) /* Instance index for DMA0 (DMA0) */
#define ID_DMA1          ( 34) /* Instance index for DMA1 (DMA1) */
#define ID_HMATRIX       ( 35) /* Instance index for HMATRIX (HMATRIX) */
#define ID_CMCC          ( 36) /* Instance index for CMCC (CMCC) */
#define ID_PRM           ( 37) /* Instance index for PRM (PRM) */
#define ID_IDAU          ( 38) /* Instance index for IDAU (IDAU) */
#define ID_EVSYS         ( 39) /* Instance index for EVSYS (EVSYS) */
#define ID_SERCOM0       ( 40) /* Instance index for SERCOM0 (SERCOM0) */
#define ID_SERCOM1       ( 41) /* Instance index for SERCOM1 (SERCOM1) */
#define ID_SERCOM2       ( 42) /* Instance index for SERCOM2 (SERCOM2) */
#define ID_SERCOM3       ( 43) /* Instance index for SERCOM3 (SERCOM3) */
#define ID_TCC0          ( 44) /* Instance index for TCC0 (TCC0) */
#define ID_TCC1          ( 45) /* Instance index for TCC1 (TCC1) */
#define ID_TCC2          ( 46) /* Instance index for TCC2 (TCC2) */
#define ID_TCC3          ( 47) /* Instance index for TCC3 (TCC3) */
#define ID_SERCOM4       ( 64) /* Instance index for SERCOM4 (SERCOM4) */
#define ID_SERCOM5       ( 65) /* Instance index for SERCOM5 (SERCOM5) */
#define ID_SERCOM6       ( 66) /* Instance index for SERCOM6 (SERCOM6) */
#define ID_SERCOM7       ( 67) /* Instance index for SERCOM7 (SERCOM7) */
#define ID_TCC4          ( 68) /* Instance index for TCC4 (TCC4) */
#define ID_TCC5          ( 69) /* Instance index for TCC5 (TCC5) */
#define ID_TCC6          ( 70) /* Instance index for TCC6 (TCC6) */
#define ID_TCC7          ( 71) /* Instance index for TCC7 (TCC7) */
#define ID_ADC           ( 72) /* Instance index for ADC (ADC) */
#define ID_AC            ( 73) /* Instance index for AC (AC) */
#define ID_PTC           ( 74) /* Instance index for PTC (PTC) */
#define ID_SPI_IXS       ( 75) /* Instance index for SPI_IXS (SPI_IXS) */
#define ID_PCC           ( 76) /* Instance index for PCC (PCC) */
#define ID_CCL           ( 77) /* Instance index for CCL (CCL) */
#define ID_PDEC          ( 78) /* Instance index for PDEC (PDEC) */
#define ID_CAN0          ( 79) /* Instance index for CAN0 (CAN0) */
#define ID_CAN1          ( 80) /* Instance index for CAN1 (CAN1) */
#define ID_ETH           ( 81) /* Instance index for ETH (ETH) */
#define ID_TRNG          ( 82) /* Instance index for TRNG (TRNG) */
#define ID_SDMMC0        ( 83) /* Instance index for SDMMC0 (SDMMC0) */
#define ID_SDMMC1        ( 84) /* Instance index for SDMMC1 (SDMMC1) */
#define ID_USB           ( 85) /* Instance index for USB (USB) */
#define ID_EBI           ( 86) /* Instance index for EBI (EBI) */
#define ID_SQI           ( 96) /* Instance index for SQI (SQI) */
#define ID_USBHS         ( 97) /* Instance index for USBHS (USBHS) */
#define ID_HSM           ( 98) /* Instance index for HSM (HSM) */

#define ID_PERIPH_MAX    ( 98) /* Number of peripheral IDs */

/* ************************************************************************** */
/*   REGISTER STRUCTURE ADDRESS DEFINITIONS FOR PIC32CK2051SG01144            */
/* ************************************************************************** */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#define AC_REGS                          ((ac_registers_t*)0x45012000)                 /* AC Registers Address         */
#define ADC_REGS                         ((adc_registers_t*)0x45010000)                /* ADC Registers Address        */
#define CAN0_REGS                        ((can_registers_t*)0x4501e000)                /* CAN0 Registers Address       */
#define CAN1_REGS                        ((can_registers_t*)0x45020000)                /* CAN1 Registers Address       */
#define CCL_REGS                         ((ccl_registers_t*)0x4501a000)                /* CCL Registers Address        */
#define CMCC_REGS                        ((cmcc_registers_t*)0x44808000)               /* CMCC Registers Address       */
#define DMA0_REGS                        ((dma_registers_t*)0x44802000)                /* DMA0 Registers Address       */
#define DMA1_REGS                        ((dma_registers_t*)0x44804000)                /* DMA1 Registers Address       */
#define DSU_REGS                         ((dsu_registers_t*)0x44000000)                /* DSU Registers Address        */
#define EBI_REGS                         ((ebi_registers_t*)0x4502c000)                /* EBI Registers Address        */
#define EIC_REGS                         ((eic_registers_t*)0x4401a000)                /* EIC Registers Address        */
#define EIC_SEC_REGS                     ((eic_registers_t*)0x4401b000)                /* EIC Registers Address        */
#define ETH_REGS                         ((eth_registers_t*)0x45022000)                /* ETH Registers Address        */
#define EVSYS_REGS                       ((evsys_registers_t*)0x4480e000)              /* EVSYS Registers Address      */
#define FCR_REGS                         ((fcr_registers_t*)0x44002000)                /* FCR Registers Address        */
#define FCW_REGS                         ((fcw_registers_t*)0x44004000)                /* FCW Registers Address        */
#define FREQM_REGS                       ((freqm_registers_t*)0x44014000)              /* FREQM Registers Address      */
#define FUSES_BOOTCFG1_REGS              ((fuses_bootcfg1_registers_t*)0x0a002000)     /* FUSES Registers Address      */
#define FUSES_BOOTCFG2_REGS              ((fuses_bootcfg1_registers_t*)0x0a00a000)     /* FUSES Registers Address      */
#define FUSES_DALCFG_REGS                ((fuses_dalcfg_registers_t*)0x0a004000)       /* FUSES Registers Address      */
#define FUSES_USERCFG1_REGS              ((fuses_usercfg1_registers_t*)0x0a000000)     /* FUSES Registers Address      */
#define FUSES_USERCFG2_REGS              ((fuses_usercfg1_registers_t*)0x0a008000)     /* FUSES Registers Address      */
#define FUSES_CALOTP_REGS                ((fuses_calotp_registers_t*)0x0a007000)       /* FUSES Registers Address      */
#define GCLK_REGS                        ((gclk_registers_t*)0x44010000)               /* GCLK Registers Address       */
#define HMATRIX_REGS                     ((hmatrix2_registers_t*)0x44806000)           /* HMATRIX Registers Address    */
#define HSM_REGS                         ((hsm_registers_t*)0x48000000)                /* HSM Registers Address        */
#define IDAU_REGS                        ((idau_registers_t*)0x4480c000)               /* IDAU Registers Address       */
#define MCLK_REGS                        ((mclk_registers_t*)0x44012000)               /* MCLK Registers Address       */
#define OSC32KCTRL_REGS                  ((osc32kctrl_registers_t*)0x4400e000)         /* OSC32KCTRL Registers Address */
#define OSCCTRL_REGS                     ((oscctrl_registers_t*)0x4400c000)            /* OSCCTRL Registers Address    */
#define PAC_REGS                         ((pac_registers_t*)0x4401c000)                /* PAC Registers Address        */
#define PCC_REGS                         ((pcc_registers_t*)0x45018000)                /* PCC Registers Address        */
#define PDEC_REGS                        ((pdec_registers_t*)0x4501c000)               /* PDEC Registers Address       */
#define PM_REGS                          ((pm_registers_t*)0x44006000)                 /* PM Registers Address         */
#define PORT_REGS                        ((port_registers_t*)0x44800000)               /* PORT Registers Address       */
#define PORT_SEC_REGS                    ((port_registers_t*)0x44801000)               /* PORT Registers Address       */
#define PRM_REGS                         ((prm_registers_t*)0x4480a000)                /* PRM Registers Address        */
#define PTC_REGS                         ((ptc_registers_t*)0x45014000)                /* PTC Registers Address        */
#define RSTC_REGS                        ((rstc_registers_t*)0x4400a000)               /* RSTC Registers Address       */
#define RTC_REGS                         ((rtc_registers_t*)0x44018000)                /* RTC Registers Address        */
#define SDMMC0_REGS                      ((sdmmc_registers_t*)0x45026000)              /* SDMMC0 Registers Address     */
#define SDMMC1_REGS                      ((sdmmc_registers_t*)0x45028000)              /* SDMMC1 Registers Address     */
#define SERCOM0_REGS                     ((sercom_registers_t*)0x44810000)             /* SERCOM0 Registers Address    */
#define SERCOM1_REGS                     ((sercom_registers_t*)0x44812000)             /* SERCOM1 Registers Address    */
#define SERCOM2_REGS                     ((sercom_registers_t*)0x44814000)             /* SERCOM2 Registers Address    */
#define SERCOM3_REGS                     ((sercom_registers_t*)0x44816000)             /* SERCOM3 Registers Address    */
#define SERCOM4_REGS                     ((sercom_registers_t*)0x45000000)             /* SERCOM4 Registers Address    */
#define SERCOM5_REGS                     ((sercom_registers_t*)0x45002000)             /* SERCOM5 Registers Address    */
#define SERCOM6_REGS                     ((sercom_registers_t*)0x45004000)             /* SERCOM6 Registers Address    */
#define SERCOM7_REGS                     ((sercom_registers_t*)0x45006000)             /* SERCOM7 Registers Address    */
#define SPI_IXS_REGS                     ((spi_ixs_registers_t*)0x45016000)            /* SPI_IXS Registers Address    */
#define SQI_REGS                         ((sqi_registers_t*)0x0ffff000)                /* SQI Registers Address        */
#define SUPC_REGS                        ((supc_registers_t*)0x44008000)               /* SUPC Registers Address       */
#define TCC0_REGS                        ((tcc_registers_t*)0x44818000)                /* TCC0 Registers Address       */
#define TCC1_REGS                        ((tcc_registers_t*)0x4481a000)                /* TCC1 Registers Address       */
#define TCC2_REGS                        ((tcc_registers_t*)0x4481c000)                /* TCC2 Registers Address       */
#define TCC3_REGS                        ((tcc_registers_t*)0x4481e000)                /* TCC3 Registers Address       */
#define TCC4_REGS                        ((tcc_registers_t*)0x45008000)                /* TCC4 Registers Address       */
#define TCC5_REGS                        ((tcc_registers_t*)0x4500a000)                /* TCC5 Registers Address       */
#define TCC6_REGS                        ((tcc_registers_t*)0x4500c000)                /* TCC6 Registers Address       */
#define TCC7_REGS                        ((tcc_registers_t*)0x4500e000)                /* TCC7 Registers Address       */
#define TRAM_REGS                        ((tram_registers_t*)0x4401e000)               /* TRAM Registers Address       */
#define TRNG_REGS                        ((trng_registers_t*)0x45024000)               /* TRNG Registers Address       */
#define USB_REGS                         ((usb_registers_t*)0x4502a000)                /* USB Registers Address        */
#define USBHS_REGS                       ((usbhs_registers_t*)0x46000000)              /* USBHS Registers Address      */
#define WDT_REGS                         ((wdt_registers_t*)0x44016000)                /* WDT Registers Address        */
#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ************************************************************************** */
/*   BASE ADDRESS DEFINITIONS FOR PIC32CK2051SG01144                          */
/* ************************************************************************** */
#define AC_BASE_ADDRESS                  _UINT32_(0x45012000)                          /* AC Base Address */
#define ADC_BASE_ADDRESS                 _UINT32_(0x45010000)                          /* ADC Base Address */
#define CAN0_BASE_ADDRESS                _UINT32_(0x4501e000)                          /* CAN0 Base Address */
#define CAN1_BASE_ADDRESS                _UINT32_(0x45020000)                          /* CAN1 Base Address */
#define CCL_BASE_ADDRESS                 _UINT32_(0x4501a000)                          /* CCL Base Address */
#define CMCC_BASE_ADDRESS                _UINT32_(0x44808000)                          /* CMCC Base Address */
#define DMA0_BASE_ADDRESS                _UINT32_(0x44802000)                          /* DMA0 Base Address */
#define DMA1_BASE_ADDRESS                _UINT32_(0x44804000)                          /* DMA1 Base Address */
#define DSU_BASE_ADDRESS                 _UINT32_(0x44000000)                          /* DSU Base Address */
#define EBI_BASE_ADDRESS                 _UINT32_(0x4502c000)                          /* EBI Base Address */
#define EIC_BASE_ADDRESS                 _UINT32_(0x4401a000)                          /* EIC Base Address */
#define EIC_SEC_BASE_ADDRESS             _UINT32_(0x4401b000)                          /* EIC Base Address */
#define ETH_BASE_ADDRESS                 _UINT32_(0x45022000)                          /* ETH Base Address */
#define EVSYS_BASE_ADDRESS               _UINT32_(0x4480e000)                          /* EVSYS Base Address */
#define FCR_BASE_ADDRESS                 _UINT32_(0x44002000)                          /* FCR Base Address */
#define FCW_BASE_ADDRESS                 _UINT32_(0x44004000)                          /* FCW Base Address */
#define FREQM_BASE_ADDRESS               _UINT32_(0x44014000)                          /* FREQM Base Address */
#define FUSES_BOOTCFG1_BASE_ADDRESS      _UINT32_(0x0a002000)                          /* FUSES Base Address */
#define FUSES_BOOTCFG2_BASE_ADDRESS      _UINT32_(0x0a00a000)                          /* FUSES Base Address */
#define FUSES_DALCFG_BASE_ADDRESS        _UINT32_(0x0a004000)                          /* FUSES Base Address */
#define FUSES_USERCFG1_BASE_ADDRESS      _UINT32_(0x0a000000)                          /* FUSES Base Address */
#define FUSES_USERCFG2_BASE_ADDRESS      _UINT32_(0x0a008000)                          /* FUSES Base Address */
#define FUSES_CALOTP_BASE_ADDRESS        _UINT32_(0x0a007000)                          /* FUSES Base Address */
#define GCLK_BASE_ADDRESS                _UINT32_(0x44010000)                          /* GCLK Base Address */
#define HMATRIX_BASE_ADDRESS             _UINT32_(0x44806000)                          /* HMATRIX Base Address */
#define HSM_BASE_ADDRESS                 _UINT32_(0x48000000)                          /* HSM Base Address */
#define IDAU_BASE_ADDRESS                _UINT32_(0x4480c000)                          /* IDAU Base Address */
#define MCLK_BASE_ADDRESS                _UINT32_(0x44012000)                          /* MCLK Base Address */
#define OSC32KCTRL_BASE_ADDRESS          _UINT32_(0x4400e000)                          /* OSC32KCTRL Base Address */
#define OSCCTRL_BASE_ADDRESS             _UINT32_(0x4400c000)                          /* OSCCTRL Base Address */
#define PAC_BASE_ADDRESS                 _UINT32_(0x4401c000)                          /* PAC Base Address */
#define PCC_BASE_ADDRESS                 _UINT32_(0x45018000)                          /* PCC Base Address */
#define PDEC_BASE_ADDRESS                _UINT32_(0x4501c000)                          /* PDEC Base Address */
#define PM_BASE_ADDRESS                  _UINT32_(0x44006000)                          /* PM Base Address */
#define PORT_BASE_ADDRESS                _UINT32_(0x44800000)                          /* PORT Base Address */
#define PORT_SEC_BASE_ADDRESS            _UINT32_(0x44801000)                          /* PORT Base Address */
#define PRM_BASE_ADDRESS                 _UINT32_(0x4480a000)                          /* PRM Base Address */
#define PTC_BASE_ADDRESS                 _UINT32_(0x45014000)                          /* PTC Base Address */
#define RSTC_BASE_ADDRESS                _UINT32_(0x4400a000)                          /* RSTC Base Address */
#define RTC_BASE_ADDRESS                 _UINT32_(0x44018000)                          /* RTC Base Address */
#define SDMMC0_BASE_ADDRESS              _UINT32_(0x45026000)                          /* SDMMC0 Base Address */
#define SDMMC1_BASE_ADDRESS              _UINT32_(0x45028000)                          /* SDMMC1 Base Address */
#define SERCOM0_BASE_ADDRESS             _UINT32_(0x44810000)                          /* SERCOM0 Base Address */
#define SERCOM1_BASE_ADDRESS             _UINT32_(0x44812000)                          /* SERCOM1 Base Address */
#define SERCOM2_BASE_ADDRESS             _UINT32_(0x44814000)                          /* SERCOM2 Base Address */
#define SERCOM3_BASE_ADDRESS             _UINT32_(0x44816000)                          /* SERCOM3 Base Address */
#define SERCOM4_BASE_ADDRESS             _UINT32_(0x45000000)                          /* SERCOM4 Base Address */
#define SERCOM5_BASE_ADDRESS             _UINT32_(0x45002000)                          /* SERCOM5 Base Address */
#define SERCOM6_BASE_ADDRESS             _UINT32_(0x45004000)                          /* SERCOM6 Base Address */
#define SERCOM7_BASE_ADDRESS             _UINT32_(0x45006000)                          /* SERCOM7 Base Address */
#define SPI_IXS_BASE_ADDRESS             _UINT32_(0x45016000)                          /* SPI_IXS Base Address */
#define SQI_BASE_ADDRESS                 _UINT32_(0x0ffff000)                          /* SQI Base Address */
#define SUPC_BASE_ADDRESS                _UINT32_(0x44008000)                          /* SUPC Base Address */
#define TCC0_BASE_ADDRESS                _UINT32_(0x44818000)                          /* TCC0 Base Address */
#define TCC1_BASE_ADDRESS                _UINT32_(0x4481a000)                          /* TCC1 Base Address */
#define TCC2_BASE_ADDRESS                _UINT32_(0x4481c000)                          /* TCC2 Base Address */
#define TCC3_BASE_ADDRESS                _UINT32_(0x4481e000)                          /* TCC3 Base Address */
#define TCC4_BASE_ADDRESS                _UINT32_(0x45008000)                          /* TCC4 Base Address */
#define TCC5_BASE_ADDRESS                _UINT32_(0x4500a000)                          /* TCC5 Base Address */
#define TCC6_BASE_ADDRESS                _UINT32_(0x4500c000)                          /* TCC6 Base Address */
#define TCC7_BASE_ADDRESS                _UINT32_(0x4500e000)                          /* TCC7 Base Address */
#define TRAM_BASE_ADDRESS                _UINT32_(0x4401e000)                          /* TRAM Base Address */
#define TRNG_BASE_ADDRESS                _UINT32_(0x45024000)                          /* TRNG Base Address */
#define USB_BASE_ADDRESS                 _UINT32_(0x4502a000)                          /* USB Base Address */
#define USBHS_BASE_ADDRESS               _UINT32_(0x46000000)                          /* USBHS Base Address */
#define WDT_BASE_ADDRESS                 _UINT32_(0x44016000)                          /* WDT Base Address */

/* ************************************************************************** */
/*   PIO DEFINITIONS FOR PIC32CK2051SG01144                                   */
/* ************************************************************************** */
#include "pio/pic32ck2051sg01144.h"

/* ************************************************************************** */
/*   MEMORY MAPPING DEFINITIONS FOR PIC32CK2051SG01144                        */
/* ************************************************************************** */
#define CMCC_DATARAM_SIZE              _UINT32_(0x00001000)    /*    4kB Memory segment type: ram */
#define CMCC_TAGRAM_SIZE               _UINT32_(0x00000400)    /*    1kB Memory segment type: ram */
#define CMCC_VALIDRAM_SIZE             _UINT32_(0x00000040)    /*    0kB Memory segment type: ram */
#define PRM_ROM_SIZE                   _UINT32_(0x00008000)    /*   32kB Memory segment type: rom */
#define FLASH_BFM_SIZE                 _UINT32_(0x00020000)    /*  128kB Memory segment type: flash */
#define FLASH_BFM_PAGE_SIZE            _UINT32_(      4096)
#define FLASH_BFM_NB_OF_PAGES          _UINT32_(        32)

#define FLASH_CFM_USERCFG1_SIZE        _UINT32_(0x00001000)    /*    4kB Memory segment type: flash */
#define FLASH_CFM_USERCFG1_PAGE_SIZE   _UINT32_(      4096)
#define FLASH_CFM_USERCFG1_NB_OF_PAGES _UINT32_(         1)

#define FLASH_CFM_USEROTP1_SIZE        _UINT32_(0x00001000)    /*    4kB Memory segment type: user_signatures */
#define FLASH_CFM_USEROTP1_PAGE_SIZE   _UINT32_(      4096)
#define FLASH_CFM_USEROTP1_NB_OF_PAGES _UINT32_(         1)

#define FLASH_CFM_BOOTCFG1_SIZE        _UINT32_(0x00001000)    /*    4kB Memory segment type: flash */
#define FLASH_CFM_BOOTCFG1_PAGE_SIZE   _UINT32_(      4096)
#define FLASH_CFM_BOOTCFG1_NB_OF_PAGES _UINT32_(         1)

#define FLASH_CFM_DALCFG_SIZE          _UINT32_(0x00001000)    /*    4kB Memory segment type: flash */
#define FLASH_CFM_DALCFG_PAGE_SIZE     _UINT32_(      4096)
#define FLASH_CFM_DALCFG_NB_OF_PAGES   _UINT32_(         1)

#define FLASH_CFM_CALBACKUP_SIZE       _UINT32_(0x00001000)    /*    4kB Memory segment type: flash */
#define FLASH_CFM_CALBACKUP_PAGE_SIZE  _UINT32_(      4096)
#define FLASH_CFM_CALBACKUP_NB_OF_PAGES _UINT32_(         1)

#define FLASH_CFM_CALOTP_SIZE          _UINT32_(0x00001000)    /*    4kB Memory segment type: other */
#define FLASH_CFM_CALOTP_PAGE_SIZE     _UINT32_(      4096)
#define FLASH_CFM_CALOTP_NB_OF_PAGES   _UINT32_(         1)

#define FLASH_CFM_USERCFG2_SIZE        _UINT32_(0x00001000)    /*    4kB Memory segment type: flash */
#define FLASH_CFM_USERCFG2_PAGE_SIZE   _UINT32_(      4096)
#define FLASH_CFM_USERCFG2_NB_OF_PAGES _UINT32_(         1)

#define FLASH_CFM_USEROTP2_SIZE        _UINT32_(0x00001000)    /*    4kB Memory segment type: user_signatures */
#define FLASH_CFM_USEROTP2_PAGE_SIZE   _UINT32_(      4096)
#define FLASH_CFM_USEROTP2_NB_OF_PAGES _UINT32_(         1)

#define FLASH_CFM_BOOTCFG2_SIZE        _UINT32_(0x00001000)    /*    4kB Memory segment type: flash */
#define FLASH_CFM_BOOTCFG2_PAGE_SIZE   _UINT32_(      4096)
#define FLASH_CFM_BOOTCFG2_NB_OF_PAGES _UINT32_(         1)

#define FLASH_PFM_SIZE                 _UINT32_(0x00200000)    /* 2048kB Memory segment type: flash */
#define FLASH_PFM_PAGE_SIZE            _UINT32_(      4096)
#define FLASH_PFM_NB_OF_PAGES          _UINT32_(       512)

#define SQI_SFR_SIZE                   _UINT32_(0x00001000)    /*    4kB Memory segment type: io */
#define SQI_XIP_SIZE                   _UINT32_(0x10000000)    /* 262144kB Memory segment type: ram */
#define HSRAM_RET_SIZE                 _UINT32_(0x00080000)    /*  512kB Memory segment type: ram */
#define HPB0_BRIDGE_SIZE               _UINT32_(0x00030000)    /*  192kB Memory segment type: io */
#define HPB1_BRIDGE_SIZE               _UINT32_(0x00030000)    /*  192kB Memory segment type: io */
#define HPB2_BRIDGE_SIZE               _UINT32_(0x00030000)    /*  192kB Memory segment type: io */
#define USBHS_SFR_SIZE                 _UINT32_(0x00001600)    /*    5kB Memory segment type: io */
#define HSM_SFR_SIZE                   _UINT32_(0x00001000)    /*    4kB Memory segment type: io */
#define EBI_CS0_SIZE                   _UINT32_(0x01000000)    /* 16384kB Memory segment type: ram */
#define EBI_CS1_SIZE                   _UINT32_(0x01000000)    /* 16384kB Memory segment type: ram */
#define EBI_CS2_SIZE                   _UINT32_(0x01000000)    /* 16384kB Memory segment type: ram */
#define EBI_CS3_SIZE                   _UINT32_(0x01000000)    /* 16384kB Memory segment type: ram */
#define PPB_SIZE                       _UINT32_(0x00100000)    /* 1024kB Memory segment type: io */

#define CMCC_DATARAM_ADDR              _UINT32_(0x00000000)    /* CMCC_DATARAM base address (type: ram)*/
#define CMCC_TAGRAM_ADDR               _UINT32_(0x00001000)    /* CMCC_TAGRAM base address (type: ram)*/
#define CMCC_VALIDRAM_ADDR             _UINT32_(0x00003000)    /* CMCC_VALIDRAM base address (type: ram)*/
#define PRM_ROM_ADDR                   _UINT32_(0x04000000)    /* PRM_ROM base address (type: rom)*/
#define FLASH_BFM_ADDR                 _UINT32_(0x08000000)    /* FLASH_BFM base address (type: flash)*/
#define FLASH_CFM_USERCFG1_ADDR        _UINT32_(0x0a000000)    /* FLASH_CFM_USERCFG1 base address (type: flash)*/
#define FLASH_CFM_USEROTP1_ADDR        _UINT32_(0x0a001000)    /* FLASH_CFM_USEROTP1 base address (type: user_signatures)*/
#define FLASH_CFM_BOOTCFG1_ADDR        _UINT32_(0x0a002000)    /* FLASH_CFM_BOOTCFG1 base address (type: flash)*/
#define FLASH_CFM_DALCFG_ADDR          _UINT32_(0x0a004000)    /* FLASH_CFM_DALCFG base address (type: flash)*/
#define FLASH_CFM_CALBACKUP_ADDR       _UINT32_(0x0a006000)    /* FLASH_CFM_CALBACKUP base address (type: flash)*/
#define FLASH_CFM_CALOTP_ADDR          _UINT32_(0x0a007000)    /* FLASH_CFM_CALOTP base address (type: other)*/
#define FLASH_CFM_USERCFG2_ADDR        _UINT32_(0x0a008000)    /* FLASH_CFM_USERCFG2 base address (type: flash)*/
#define FLASH_CFM_USEROTP2_ADDR        _UINT32_(0x0a009000)    /* FLASH_CFM_USEROTP2 base address (type: user_signatures)*/
#define FLASH_CFM_BOOTCFG2_ADDR        _UINT32_(0x0a00a000)    /* FLASH_CFM_BOOTCFG2 base address (type: flash)*/
#define FLASH_PFM_ADDR                 _UINT32_(0x0c000000)    /* FLASH_PFM base address (type: flash)*/
#define SQI_SFR_ADDR                   _UINT32_(0x0ffff000)    /* SQI_SFR base address (type: io)*/
#define SQI_XIP_ADDR                   _UINT32_(0x10000000)    /* SQI_XIP base address (type: ram)*/
#define HSRAM_RET_ADDR                 _UINT32_(0x20000000)    /* HSRAM_RET base address (type: ram)*/
#define HPB0_BRIDGE_ADDR               _UINT32_(0x44000000)    /* HPB0_BRIDGE base address (type: io)*/
#define HPB1_BRIDGE_ADDR               _UINT32_(0x44800000)    /* HPB1_BRIDGE base address (type: io)*/
#define HPB2_BRIDGE_ADDR               _UINT32_(0x45000000)    /* HPB2_BRIDGE base address (type: io)*/
#define USBHS_SFR_ADDR                 _UINT32_(0x46000000)    /* USBHS_SFR base address (type: io)*/
#define HSM_SFR_ADDR                   _UINT32_(0x48000000)    /* HSM_SFR base address (type: io)*/
#define EBI_CS0_ADDR                   _UINT32_(0x60000000)    /* EBI_CS0 base address (type: ram)*/
#define EBI_CS1_ADDR                   _UINT32_(0x61000000)    /* EBI_CS1 base address (type: ram)*/
#define EBI_CS2_ADDR                   _UINT32_(0x62000000)    /* EBI_CS2 base address (type: ram)*/
#define EBI_CS3_ADDR                   _UINT32_(0x63000000)    /* EBI_CS3 base address (type: ram)*/
#define PPB_ADDR                       _UINT32_(0xe0000000)    /* PPB base address (type: io)*/

/* ************************************************************************** */
/*   DEVICE SIGNATURES FOR PIC32CK2051SG01144                                 */
/* ************************************************************************** */
#define CHIP_DSU_DID                   _UINT32_(0X09506053)

/* ************************************************************************** */
/*   ELECTRICAL DEFINITIONS FOR PIC32CK2051SG01144                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* Event Generator IDs for C32CK2051SG01144 */
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
#define EVENT_ID_GEN_RTC_PERD                            14 /* ID for RTC event generator PERD */
#define EVENT_ID_GEN_RTC_CMP_0                           15 /* ID for RTC event generator CMP_0 */
#define EVENT_ID_GEN_RTC_CMP_1                           16 /* ID for RTC event generator CMP_1 */
#define EVENT_ID_GEN_RTC_CMP_2                           17 /* ID for RTC event generator CMP_2 */
#define EVENT_ID_GEN_RTC_CMP_3                           18 /* ID for RTC event generator CMP_3 */
#define EVENT_ID_GEN_RTC_TAMPER                          19 /* ID for RTC event generator TAMPER */
#define EVENT_ID_GEN_RTC_OVF                             20 /* ID for RTC event generator OVF */
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
#define EVENT_ID_GEN_DMA0_CH_0                           38 /* ID for DMA0 event generator CH_0 */
#define EVENT_ID_GEN_DMA0_CH_1                           39 /* ID for DMA0 event generator CH_1 */
#define EVENT_ID_GEN_DMA0_CH_2                           40 /* ID for DMA0 event generator CH_2 */
#define EVENT_ID_GEN_DMA0_CH_3                           41 /* ID for DMA0 event generator CH_3 */
#define EVENT_ID_GEN_DMA0_CH_4                           42 /* ID for DMA0 event generator CH_4 */
#define EVENT_ID_GEN_DMA0_CH_5                           43 /* ID for DMA0 event generator CH_5 */
#define EVENT_ID_GEN_DMA0_CH_6                           44 /* ID for DMA0 event generator CH_6 */
#define EVENT_ID_GEN_DMA0_CH_7                           45 /* ID for DMA0 event generator CH_7 */
#define EVENT_ID_GEN_DMA1_CH_0                           46 /* ID for DMA1 event generator CH_0 */
#define EVENT_ID_GEN_DMA1_CH_1                           47 /* ID for DMA1 event generator CH_1 */
#define EVENT_ID_GEN_DMA1_CH_2                           48 /* ID for DMA1 event generator CH_2 */
#define EVENT_ID_GEN_DMA1_CH_3                           49 /* ID for DMA1 event generator CH_3 */
#define EVENT_ID_GEN_TCC0_OVF                            50 /* ID for TCC0 event generator OVF */
#define EVENT_ID_GEN_TCC0_TRG                            51 /* ID for TCC0 event generator TRG */
#define EVENT_ID_GEN_TCC0_CNT                            52 /* ID for TCC0 event generator CNT */
#define EVENT_ID_GEN_TCC0_MC_0                           53 /* ID for TCC0 event generator MC_0 */
#define EVENT_ID_GEN_TCC0_MC_1                           54 /* ID for TCC0 event generator MC_1 */
#define EVENT_ID_GEN_TCC0_MC_2                           55 /* ID for TCC0 event generator MC_2 */
#define EVENT_ID_GEN_TCC0_MC_3                           56 /* ID for TCC0 event generator MC_3 */
#define EVENT_ID_GEN_TCC0_MC_4                           57 /* ID for TCC0 event generator MC_4 */
#define EVENT_ID_GEN_TCC0_MC_5                           58 /* ID for TCC0 event generator MC_5 */
#define EVENT_ID_GEN_TCC1_OVF                            59 /* ID for TCC1 event generator OVF */
#define EVENT_ID_GEN_TCC1_TRG                            60 /* ID for TCC1 event generator TRG */
#define EVENT_ID_GEN_TCC1_CNT                            61 /* ID for TCC1 event generator CNT */
#define EVENT_ID_GEN_TCC1_MC_0                           62 /* ID for TCC1 event generator MC_0 */
#define EVENT_ID_GEN_TCC1_MC_1                           63 /* ID for TCC1 event generator MC_1 */
#define EVENT_ID_GEN_TCC1_MC_2                           64 /* ID for TCC1 event generator MC_2 */
#define EVENT_ID_GEN_TCC1_MC_3                           65 /* ID for TCC1 event generator MC_3 */
#define EVENT_ID_GEN_TCC1_MC_4                           66 /* ID for TCC1 event generator MC_4 */
#define EVENT_ID_GEN_TCC1_MC_5                           67 /* ID for TCC1 event generator MC_5 */
#define EVENT_ID_GEN_TCC2_OVF                            68 /* ID for TCC2 event generator OVF */
#define EVENT_ID_GEN_TCC2_TRG                            69 /* ID for TCC2 event generator TRG */
#define EVENT_ID_GEN_TCC2_CNT                            70 /* ID for TCC2 event generator CNT */
#define EVENT_ID_GEN_TCC2_MC_0                           71 /* ID for TCC2 event generator MC_0 */
#define EVENT_ID_GEN_TCC2_MC_1                           72 /* ID for TCC2 event generator MC_1 */
#define EVENT_ID_GEN_TCC2_MC_2                           73 /* ID for TCC2 event generator MC_2 */
#define EVENT_ID_GEN_TCC2_MC_3                           74 /* ID for TCC2 event generator MC_3 */
#define EVENT_ID_GEN_TCC2_MC_4                           75 /* ID for TCC2 event generator MC_4 */
#define EVENT_ID_GEN_TCC2_MC_5                           76 /* ID for TCC2 event generator MC_5 */
#define EVENT_ID_GEN_TCC3_OVF                            77 /* ID for TCC3 event generator OVF */
#define EVENT_ID_GEN_TCC3_TRG                            78 /* ID for TCC3 event generator TRG */
#define EVENT_ID_GEN_TCC3_CNT                            79 /* ID for TCC3 event generator CNT */
#define EVENT_ID_GEN_TCC3_MC_0                           80 /* ID for TCC3 event generator MC_0 */
#define EVENT_ID_GEN_TCC3_MC_1                           81 /* ID for TCC3 event generator MC_1 */
#define EVENT_ID_GEN_TCC3_MC_2                           82 /* ID for TCC3 event generator MC_2 */
#define EVENT_ID_GEN_TCC3_MC_3                           83 /* ID for TCC3 event generator MC_3 */
#define EVENT_ID_GEN_TCC3_MC_4                           84 /* ID for TCC3 event generator MC_4 */
#define EVENT_ID_GEN_TCC3_MC_5                           85 /* ID for TCC3 event generator MC_5 */
#define EVENT_ID_GEN_TCC4_OVF                            86 /* ID for TCC4 event generator OVF */
#define EVENT_ID_GEN_TCC4_TRG                            87 /* ID for TCC4 event generator TRG */
#define EVENT_ID_GEN_TCC4_CNT                            88 /* ID for TCC4 event generator CNT */
#define EVENT_ID_GEN_TCC4_MC_0                           89 /* ID for TCC4 event generator MC_0 */
#define EVENT_ID_GEN_TCC4_MC_1                           90 /* ID for TCC4 event generator MC_1 */
#define EVENT_ID_GEN_TCC5_OVF                            91 /* ID for TCC5 event generator OVF */
#define EVENT_ID_GEN_TCC5_TRG                            92 /* ID for TCC5 event generator TRG */
#define EVENT_ID_GEN_TCC5_CNT                            93 /* ID for TCC5 event generator CNT */
#define EVENT_ID_GEN_TCC5_MC_0                           94 /* ID for TCC5 event generator MC_0 */
#define EVENT_ID_GEN_TCC5_MC_1                           95 /* ID for TCC5 event generator MC_1 */
#define EVENT_ID_GEN_TCC6_OVF                            96 /* ID for TCC6 event generator OVF */
#define EVENT_ID_GEN_TCC6_TRG                            97 /* ID for TCC6 event generator TRG */
#define EVENT_ID_GEN_TCC6_CNT                            98 /* ID for TCC6 event generator CNT */
#define EVENT_ID_GEN_TCC6_MC_0                           99 /* ID for TCC6 event generator MC_0 */
#define EVENT_ID_GEN_TCC6_MC_1                          100 /* ID for TCC6 event generator MC_1 */
#define EVENT_ID_GEN_TCC7_OVF                           101 /* ID for TCC7 event generator OVF */
#define EVENT_ID_GEN_TCC7_TRG                           102 /* ID for TCC7 event generator TRG */
#define EVENT_ID_GEN_TCC7_CNT                           103 /* ID for TCC7 event generator CNT */
#define EVENT_ID_GEN_TCC7_MC_0                          104 /* ID for TCC7 event generator MC_0 */
#define EVENT_ID_GEN_TCC7_MC_1                          105 /* ID for TCC7 event generator MC_1 */
#define EVENT_ID_GEN_ADC_CHRDYC_0                       106 /* ID for ADC event generator CHRDYC_0 */
#define EVENT_ID_GEN_ADC_CMP_0                          107 /* ID for ADC event generator CMP_0 */
#define EVENT_ID_GEN_AC_COMP_0                          108 /* ID for AC event generator COMP_0 */
#define EVENT_ID_GEN_AC_COMP_1                          109 /* ID for AC event generator COMP_1 */
#define EVENT_ID_GEN_AC_WIN_0                           110 /* ID for AC event generator WIN_0 */
#define EVENT_ID_GEN_SPI_IXS_GEN                        113 /* ID for SPI event generator IXS_GEN */
#define EVENT_ID_GEN_CCL_LUTOUT_0                       114 /* ID for CCL event generator LUTOUT_0 */
#define EVENT_ID_GEN_CCL_LUTOUT_1                       115 /* ID for CCL event generator LUTOUT_1 */
#define EVENT_ID_GEN_CCL_LUTOUT_2                       116 /* ID for CCL event generator LUTOUT_2 */
#define EVENT_ID_GEN_CCL_LUTOUT_3                       117 /* ID for CCL event generator LUTOUT_3 */
#define EVENT_ID_GEN_PDEC_DIR                           118 /* ID for PDEC event generator DIR */
#define EVENT_ID_GEN_PDEC_ERR                           119 /* ID for PDEC event generator ERR */
#define EVENT_ID_GEN_PDEC_MC_0                          120 /* ID for PDEC event generator MC_0 */
#define EVENT_ID_GEN_PDEC_MC_1                          121 /* ID for PDEC event generator MC_1 */
#define EVENT_ID_GEN_PDEC_OVF                           122 /* ID for PDEC event generator OVF */
#define EVENT_ID_GEN_PDEC_VLC                           123 /* ID for PDEC event generator VLC */
#define EVENT_ID_GEN_ETH_TSU_CMP                        124 /* ID for ETH event generator TSU_CMP */
#define EVENT_ID_GEN_TRNG_READY                         125 /* ID for TRNG event generator READY */

/* ************************************************************************** */
/*  Event User IDs for C32CK2051SG01144 */
/* ************************************************************************** */
#define EVENT_ID_USER_FREQM_START                         0 /* ID for FREQM event user START */
#define EVENT_ID_USER_RTC_TAMPER                          1 /* ID for RTC event user TAMPER */
#define EVENT_ID_USER_PORT_EV_0                           2 /* ID for PORT event user EV_0 */
#define EVENT_ID_USER_PORT_EV_1                           3 /* ID for PORT event user EV_1 */
#define EVENT_ID_USER_PORT_EV_2                           4 /* ID for PORT event user EV_2 */
#define EVENT_ID_USER_PORT_EV_3                           5 /* ID for PORT event user EV_3 */
#define EVENT_ID_USER_DMA0_CHSTRT_0                       6 /* ID for DMA0 event user CHSTRT_0 */
#define EVENT_ID_USER_DMA0_CHSTRT_1                       7 /* ID for DMA0 event user CHSTRT_1 */
#define EVENT_ID_USER_DMA0_CHSTRT_2                       8 /* ID for DMA0 event user CHSTRT_2 */
#define EVENT_ID_USER_DMA0_CHSTRT_3                       9 /* ID for DMA0 event user CHSTRT_3 */
#define EVENT_ID_USER_DMA0_CHSTRT_4                      10 /* ID for DMA0 event user CHSTRT_4 */
#define EVENT_ID_USER_DMA0_CHSTRT_5                      11 /* ID for DMA0 event user CHSTRT_5 */
#define EVENT_ID_USER_DMA0_CHSTRT_6                      12 /* ID for DMA0 event user CHSTRT_6 */
#define EVENT_ID_USER_DMA0_CHSTRT_7                      13 /* ID for DMA0 event user CHSTRT_7 */
#define EVENT_ID_USER_DMA0_CHAUX_0                       14 /* ID for DMA0 event user CHAUX_0 */
#define EVENT_ID_USER_DMA0_CHAUX_1                       15 /* ID for DMA0 event user CHAUX_1 */
#define EVENT_ID_USER_DMA0_CHAUX_2                       16 /* ID for DMA0 event user CHAUX_2 */
#define EVENT_ID_USER_DMA0_CHAUX_3                       17 /* ID for DMA0 event user CHAUX_3 */
#define EVENT_ID_USER_DMA0_CHAUX_4                       18 /* ID for DMA0 event user CHAUX_4 */
#define EVENT_ID_USER_DMA0_CHAUX_5                       19 /* ID for DMA0 event user CHAUX_5 */
#define EVENT_ID_USER_DMA0_CHAUX_6                       20 /* ID for DMA0 event user CHAUX_6 */
#define EVENT_ID_USER_DMA0_CHAUX_7                       21 /* ID for DMA0 event user CHAUX_7 */
#define EVENT_ID_USER_DMA1_CHSTRT_0                      22 /* ID for DMA1 event user CHSTRT_0 */
#define EVENT_ID_USER_DMA1_CHSTRT_1                      23 /* ID for DMA1 event user CHSTRT_1 */
#define EVENT_ID_USER_DMA1_CHSTRT_2                      24 /* ID for DMA1 event user CHSTRT_2 */
#define EVENT_ID_USER_DMA1_CHSTRT_3                      25 /* ID for DMA1 event user CHSTRT_3 */
#define EVENT_ID_USER_DMA1_CHAUX_0                       26 /* ID for DMA1 event user CHAUX_0 */
#define EVENT_ID_USER_DMA1_CHAUX_1                       27 /* ID for DMA1 event user CHAUX_1 */
#define EVENT_ID_USER_DMA1_CHAUX_2                       28 /* ID for DMA1 event user CHAUX_2 */
#define EVENT_ID_USER_DMA1_CHAUX_3                       29 /* ID for DMA1 event user CHAUX_3 */
#define EVENT_ID_USER_TCC0_EV_0                          30 /* ID for TCC0 event user EV_0 */
#define EVENT_ID_USER_TCC0_EV_1                          31 /* ID for TCC0 event user EV_1 */
#define EVENT_ID_USER_TCC0_MC_0                          32 /* ID for TCC0 event user MC_0 */
#define EVENT_ID_USER_TCC0_MC_1                          33 /* ID for TCC0 event user MC_1 */
#define EVENT_ID_USER_TCC0_MC_2                          34 /* ID for TCC0 event user MC_2 */
#define EVENT_ID_USER_TCC0_MC_3                          35 /* ID for TCC0 event user MC_3 */
#define EVENT_ID_USER_TCC0_MC_4                          36 /* ID for TCC0 event user MC_4 */
#define EVENT_ID_USER_TCC0_MC_5                          37 /* ID for TCC0 event user MC_5 */
#define EVENT_ID_USER_TCC1_EV_0                          38 /* ID for TCC1 event user EV_0 */
#define EVENT_ID_USER_TCC1_EV_1                          39 /* ID for TCC1 event user EV_1 */
#define EVENT_ID_USER_TCC1_MC_0                          40 /* ID for TCC1 event user MC_0 */
#define EVENT_ID_USER_TCC1_MC_1                          41 /* ID for TCC1 event user MC_1 */
#define EVENT_ID_USER_TCC1_MC_2                          42 /* ID for TCC1 event user MC_2 */
#define EVENT_ID_USER_TCC1_MC_3                          43 /* ID for TCC1 event user MC_3 */
#define EVENT_ID_USER_TCC1_MC_4                          44 /* ID for TCC1 event user MC_4 */
#define EVENT_ID_USER_TCC1_MC_5                          45 /* ID for TCC1 event user MC_5 */
#define EVENT_ID_USER_TCC2_EV_0                          46 /* ID for TCC2 event user EV_0 */
#define EVENT_ID_USER_TCC2_EV_1                          47 /* ID for TCC2 event user EV_1 */
#define EVENT_ID_USER_TCC2_MC_0                          48 /* ID for TCC2 event user MC_0 */
#define EVENT_ID_USER_TCC2_MC_1                          49 /* ID for TCC2 event user MC_1 */
#define EVENT_ID_USER_TCC2_MC_2                          50 /* ID for TCC2 event user MC_2 */
#define EVENT_ID_USER_TCC2_MC_3                          51 /* ID for TCC2 event user MC_3 */
#define EVENT_ID_USER_TCC2_MC_4                          52 /* ID for TCC2 event user MC_4 */
#define EVENT_ID_USER_TCC2_MC_5                          53 /* ID for TCC2 event user MC_5 */
#define EVENT_ID_USER_TCC3_EV_0                          54 /* ID for TCC3 event user EV_0 */
#define EVENT_ID_USER_TCC3_EV_1                          55 /* ID for TCC3 event user EV_1 */
#define EVENT_ID_USER_TCC3_MC_0                          56 /* ID for TCC3 event user MC_0 */
#define EVENT_ID_USER_TCC3_MC_1                          57 /* ID for TCC3 event user MC_1 */
#define EVENT_ID_USER_TCC3_MC_2                          58 /* ID for TCC3 event user MC_2 */
#define EVENT_ID_USER_TCC3_MC_3                          59 /* ID for TCC3 event user MC_3 */
#define EVENT_ID_USER_TCC3_MC_4                          60 /* ID for TCC3 event user MC_4 */
#define EVENT_ID_USER_TCC3_MC_5                          61 /* ID for TCC3 event user MC_5 */
#define EVENT_ID_USER_TCC4_EV_0                          62 /* ID for TCC4 event user EV_0 */
#define EVENT_ID_USER_TCC4_EV_1                          63 /* ID for TCC4 event user EV_1 */
#define EVENT_ID_USER_TCC4_MC_0                          64 /* ID for TCC4 event user MC_0 */
#define EVENT_ID_USER_TCC4_MC_1                          65 /* ID for TCC4 event user MC_1 */
#define EVENT_ID_USER_TCC5_EV_0                          66 /* ID for TCC5 event user EV_0 */
#define EVENT_ID_USER_TCC5_EV_1                          67 /* ID for TCC5 event user EV_1 */
#define EVENT_ID_USER_TCC5_MC_0                          68 /* ID for TCC5 event user MC_0 */
#define EVENT_ID_USER_TCC5_MC_1                          69 /* ID for TCC5 event user MC_1 */
#define EVENT_ID_USER_TCC6_EV_0                          70 /* ID for TCC6 event user EV_0 */
#define EVENT_ID_USER_TCC6_EV_1                          71 /* ID for TCC6 event user EV_1 */
#define EVENT_ID_USER_TCC6_MC_0                          72 /* ID for TCC6 event user MC_0 */
#define EVENT_ID_USER_TCC6_MC_1                          73 /* ID for TCC6 event user MC_1 */
#define EVENT_ID_USER_TCC7_EV_0                          74 /* ID for TCC7 event user EV_0 */
#define EVENT_ID_USER_TCC7_EV_1                          75 /* ID for TCC7 event user EV_1 */
#define EVENT_ID_USER_TCC7_MC_0                          76 /* ID for TCC7 event user MC_0 */
#define EVENT_ID_USER_TCC7_MC_1                          77 /* ID for TCC7 event user MC_1 */
#define EVENT_ID_USER_ADC_TRIGGERS_0                     78 /* ID for ADC event user TRIGGERS_0 */
#define EVENT_ID_USER_ADC_TRIGGERS_1                     79 /* ID for ADC event user TRIGGERS_1 */
#define EVENT_ID_USER_ADC_TRIGGERS_2                     80 /* ID for ADC event user TRIGGERS_2 */
#define EVENT_ID_USER_ADC_TRIGGERS_3                     81 /* ID for ADC event user TRIGGERS_3 */
#define EVENT_ID_USER_ADC_TRIGGERS_4                     82 /* ID for ADC event user TRIGGERS_4 */
#define EVENT_ID_USER_ADC_TRIGGERS_5                     83 /* ID for ADC event user TRIGGERS_5 */
#define EVENT_ID_USER_ADC_TRIGGERS_6                     84 /* ID for ADC event user TRIGGERS_6 */
#define EVENT_ID_USER_ADC_TRIGGERS_7                     85 /* ID for ADC event user TRIGGERS_7 */
#define EVENT_ID_USER_ADC_TRIGGERS_8                     86 /* ID for ADC event user TRIGGERS_8 */
#define EVENT_ID_USER_ADC_TRIGGERS_9                     87 /* ID for ADC event user TRIGGERS_9 */
#define EVENT_ID_USER_ADC_TRIGGERS_10                    88 /* ID for ADC event user TRIGGERS_10 */
#define EVENT_ID_USER_AC_SOC_0                           89 /* ID for AC event user SOC_0 */
#define EVENT_ID_USER_AC_SOC_1                           90 /* ID for AC event user SOC_1 */
#define EVENT_ID_USER_CCL_LUTIN_0                        93 /* ID for CCL event user LUTIN_0 */
#define EVENT_ID_USER_CCL_LUTIN_1                        94 /* ID for CCL event user LUTIN_1 */
#define EVENT_ID_USER_CCL_LUTIN_2                        95 /* ID for CCL event user LUTIN_2 */
#define EVENT_ID_USER_CCL_LUTIN_3                        96 /* ID for CCL event user LUTIN_3 */
#define EVENT_ID_USER_PDEC_EVU_0                         97 /* ID for PDEC event user EVU_0 */
#define EVENT_ID_USER_PDEC_EVU_1                         98 /* ID for PDEC event user EVU_1 */
#define EVENT_ID_USER_PDEC_EVU_2                         99 /* ID for PDEC event user EVU_2 */
#define EVENT_ID_USER_HSM_TAMPER_0                      100 /* ID for HSM event user TAMPER_0 */
#define EVENT_ID_USER_HSM_TAMPER_1                      101 /* ID for HSM event user TAMPER_1 */
#define EVENT_ID_USER_HSM_TAMPER_2                      102 /* ID for HSM event user TAMPER_2 */
#define EVENT_ID_USER_HSM_TAMPER_3                      103 /* ID for HSM event user TAMPER_3 */

/* ************************************************************************** */
/* IDAU TrustZone REGION DEFINITIONS FOR PIC32CK2051SG01144 */
/* ************************************************************************** */
#define IDAU_REGION_CMCC_DATARAM_SEC             _UINT32_(1) /* IDAU region number for CMCC_DATARAM_SEC */
#define IDAU_REGION_CMCC_TAGRAM_SEC              _UINT32_(2) /* IDAU region number for CMCC_TAGRAM_SEC */
#define IDAU_REGION_CMCC_VALIDRAM_SEC            _UINT32_(3) /* IDAU region number for CMCC_VALIDRAM_SEC */
#define IDAU_REGION_PRM_ROM_SEC                  _UINT32_(4) /* IDAU region number for PRM_ROM_SEC */
#define IDAU_REGION_FLASH_BFM_SEC                _UINT32_(5) /* IDAU region number for FLASH_BFM_SEC */
#define IDAU_REGION_FLASH_BFM_NSC                _UINT32_(6) /* IDAU region number for FLASH_BFM_NSC */
#define IDAU_REGION_FLASH_CFM_SEC                _UINT32_(7) /* IDAU region number for FLASH_CFM_SEC */
#define IDAU_REGION_FLASH_PFM_SEC                _UINT32_(8) /* IDAU region number for FLASH_PFM_SEC */
#define IDAU_REGION_FLASH_PFM_NSC                _UINT32_(9) /* IDAU region number for FLASH_PFM_NSC */
#define IDAU_REGION_FLASH_PFM_NS                 _UINT32_(10) /* IDAU region number for FLASH_PFM_NS */
#define IDAU_REGION_SQI_SFR                      _UINT32_(11) /* IDAU region number for SQI_SFR */
#define IDAU_REGION_SQI_XIP                      _UINT32_(12) /* IDAU region number for SQI_XIP */
#define IDAU_REGION_HSRAM_RET_SEC                _UINT32_(13) /* IDAU region number for HSRAM_RET_SEC */
#define IDAU_REGION_HSRAM_RET_NS                 _UINT32_(14) /* IDAU region number for HSRAM_RET_NS */
#define IDAU_REGION_HPB0_BRIDGE                  _UINT32_(15) /* IDAU region number for HPB0_BRIDGE */
#define IDAU_REGION_HPB1_BRIDGE                  _UINT32_(16) /* IDAU region number for HPB1_BRIDGE */
#define IDAU_REGION_HPB2_BRIDGE                  _UINT32_(17) /* IDAU region number for HPB2_BRIDGE */
#define IDAU_REGION_USBHS_SFR                    _UINT32_(18) /* IDAU region number for USBHS_SFR */
#define IDAU_REGION_HSM_SFR                      _UINT32_(19) /* IDAU region number for HSM_SFR */
#define IDAU_REGION_EBI_CS0                      _UINT32_(20) /* IDAU region number for EBI_CS0 */
#define IDAU_REGION_EBI_CS1                      _UINT32_(21) /* IDAU region number for EBI_CS1 */
#define IDAU_REGION_EBI_CS2                      _UINT32_(22) /* IDAU region number for EBI_CS2 */
#define IDAU_REGION_EBI_CS3                      _UINT32_(23) /* IDAU region number for EBI_CS3 */

#ifdef __cplusplus
}
#endif

#endif /* _PIC32CK2051SG01144_H_ */

