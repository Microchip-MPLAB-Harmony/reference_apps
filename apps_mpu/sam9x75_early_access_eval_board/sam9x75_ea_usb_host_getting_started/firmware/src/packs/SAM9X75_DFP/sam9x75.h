/*
 * Header file for ATSAM9X75
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

/* File generated from device description version 2023-01-20T08:33:39Z */
#ifndef _SAM9X75_H_
#define _SAM9X75_H_

/* Header version uses Semantic Versioning 2.0.0 (https://semver.org/) */
#define HEADER_FORMAT_VERSION "2.1.0"

#define HEADER_FORMAT_VERSION_MAJOR (2)
#define HEADER_FORMAT_VERSION_MINOR (1)
#define HEADER_FORMAT_VERSION_PATCH (0)

/* SAM9X75 definitions
  This file defines all structures and symbols for SAM9X75:
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
/* INTERRUPTS DEFINITIONS FOR SAM9X75                                       */
/* ************************************************************************** */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* Interrupt Number Definition */
typedef enum IRQn
{
/******  SAM9X75 specific Interrupt Numbers ***********************************/
  EXT_FIQ_IRQn              =   0, /* 0   Advanced Interrupt Controller (AIC) */
  PIT_IRQn                  =   1, /* 1   Shared between PMC WDT PIT RSTC RTT RTC (PIT) */
  PMC_IRQn                  =   1, /* 1   Shared between PMC WDT PIT RSTC RTT RTC (PMC) */
  RSTC_IRQn                 =   1, /* 1   Shared between PMC WDT PIT RSTC RTT RTC (RSTC) */
  RTC_IRQn                  =   1, /* 1   Shared between PMC WDT PIT RSTC RTT RTC (RTC) */
  RTT_IRQn                  =   1, /* 1   Shared between PMC WDT PIT RSTC RTT RTC (RTT) */
  WDT_IRQn                  =   1, /* 1   Shared between PMC WDT PIT RSTC RTT RTC (WDT) */
  PIOA_IRQn                 =   2, /* 2   Parallel Input/Output Controller (PIOA) */
  PIOB_IRQn                 =   3, /* 3   Parallel Input/Output Controller (PIOB) */
  PIOC_IRQn                 =   4, /* 4   Parallel Input/Output Controller (PIOC) */
  FLEXCOM0_IRQn             =   5, /* 5   Flexible Serial Communication (FLEXCOM0) */
  FLEXCOM1_IRQn             =   6, /* 6   Flexible Serial Communication (FLEXCOM1) */
  FLEXCOM2_IRQn             =   7, /* 7   Flexible Serial Communication (FLEXCOM2) */
  FLEXCOM3_IRQn             =   8, /* 8   Flexible Serial Communication (FLEXCOM3) */
  FLEXCOM6_IRQn             =   9, /* 9   Flexible Serial Communication (FLEXCOM6) */
  FLEXCOM7_IRQn             =  10, /* 10  Flexible Serial Communication (FLEXCOM7) */
  FLEXCOM8_IRQn             =  11, /* 11  Flexible Serial Communication (FLEXCOM8) */
  SDMMC0_IRQn               =  12, /* 12  Secure Digital MultiMedia Card Controller (SDMMC0) */
  FLEXCOM4_IRQn             =  13, /* 13  Flexible Serial Communication (FLEXCOM4) */
  FLEXCOM5_IRQn             =  14, /* 14  Flexible Serial Communication (FLEXCOM5) */
  FLEXCOM9_IRQn             =  15, /* 15  Flexible Serial Communication (FLEXCOM9) */
  FLEXCOM10_IRQn            =  16, /* 16  Flexible Serial Communication (FLEXCOM10) */
  TC0_IRQn                  =  17, /* 17  Timer Counter (TC0)                 */
  PWM_IRQn                  =  18, /* 18  Pulse Width Modulation Controller (PWM) */
  ADC_IRQn                  =  19, /* 19  Analog-to-Digital Converter (ADC)   */
  XDMAC_IRQn                =  20, /* 20  Extensible DMA Controller (XDMAC)   */
  MATRIX_IRQn               =  21, /* 21  AHB Bus Matrix (MATRIX)             */
  UHPHS_IRQn                =  22, /* 22  USB Host High Speed Port (UHPHS)    */
  UDPHS_IRQn                =  23, /* 23  IP_Name (UDPHS)                     */
  GMAC_IRQn                 =  24, /* 24  Gigabit Ethernet MAC (GMAC)         */
  XLCDC_IRQn                =  25, /* 25  LCD Controller (XLCDC)              */
  SDMMC1_IRQn               =  26, /* 26  Secure Digital MultiMedia Card Controller (SDMMC1) */
  SSC_IRQn                  =  28, /* 28  Synchronous Serial Controller (SSC) */
  MCAN0_INT0_IRQn           =  29, /* 29  Controller Area Network (MCAN0)     */
  MCAN1_INT0_IRQn           =  30, /* 30  Controller Area Network (MCAN1)     */
  EXT_IRQ_IRQn              =  31, /* 31  Advanced Interrupt Controller (AIC) */
  FLEXCOM11_IRQn            =  32, /* 32  Flexible Serial Communication (FLEXCOM11) */
  FLEXCOM12_IRQn            =  33, /* 33  Flexible Serial Communication (FLEXCOM12) */
  I2SMCC_IRQn               =  34, /* 34  Inter-IC Sound Multi Channel Controller (I2SMCC) */
  QSPI_IRQn                 =  35, /* 35  Quad Serial Peripheral Interface (QSPI) */
  GFX2D_IRQn                =  36, /* 36  2D Graphics Engine (GFX2D)          */
  PIT64B0_IRQn              =  37, /* 37  Periodic Interval Timer 64-bit (PIT64B0) */
  TRNG_IRQn                 =  38, /* 38  True Random Number Generator (TRNG) */
  AES_IRQn                  =  39, /* 39  Advanced Encryption Standard (AES)  */
  TDES_IRQn                 =  40, /* 40  Triple Data Encryption Standard (TDES) */
  SHA_IRQn                  =  41, /* 41  Secure Hash Algorithm (SHA)         */
  CLASSD_IRQn               =  42, /* 42  Audio Class D Amplifier (CLASSD)    */
  ISC_IRQn                  =  43, /* 43  Image Sensor Controller (ISC)       */
  PIOD_IRQn                 =  44, /* 44  Parallel Input/Output Controller (PIOD) */
  TC1_IRQn                  =  45, /* 45  Timer Counter (TC1)                 */
  OTPC_IRQn                 =  46, /* 46  OTP Memory Controller (OTPC)        */
  DBGU_IRQn                 =  47, /* 47  Debug Unit (DBGU)                   */
  PMECC_IRQn                =  48, /* 48  Shared between PMECC PMERRLOC (PMECC) */
  PMERRLOC_IRQn             =  48, /* 48  Shared between PMECC PMERRLOC (PMERRLOC) */
  MPDDRC_IRQn               =  49, /* 49  Shared between MPDDRC SMC (MPDDRC)  */
  SMC_IRQn                  =  49, /* 49  Shared between MPDDRC SMC (SMC)     */
  CSI2DC_IRQn               =  52, /* 52  CSI-2 Demultiplexer Controller (CSI2DC) */
  CSI_IRQn                  =  53, /* 53  CSI Host Controller (CSI)           */
  DSI_IRQn                  =  54, /* 54  LCD Controller (DSI)                */
  MIPIPHY_IRQn              =  55, /* 55   (MIPIPHY)                          */
  LVDSC_IRQn                =  56, /* 56  LVDS Controller (LVDSC)             */
  LVDSPHY_IRQn              =  57, /* 57   (LVDSPHY)                          */
  PIT64B1_IRQn              =  58, /* 58  Periodic Interval Timer 64-bit (PIT64B1) */
  GMAC_Q1_IRQn              =  60, /* 60  Gigabit Ethernet MAC (GMAC)         */
  GMAC_Q2_IRQn              =  61, /* 61  Gigabit Ethernet MAC (GMAC)         */
  GMAC_Q3_IRQn              =  62, /* 62  Gigabit Ethernet MAC (GMAC)         */
  GMAC_Q4_IRQn              =  63, /* 63  Gigabit Ethernet MAC (GMAC)         */
  GMAC_Q5_IRQn              =  64, /* 64  Gigabit Ethernet MAC (GMAC)         */
  GMAC_EMAC_IRQn            =  65, /* 65  Gigabit Ethernet MAC (GMAC)         */
  GMAC_MMSL_IRQn            =  66, /* 66  Gigabit Ethernet MAC (GMAC)         */
  GMAC_TSU_IRQn             =  67, /* 67  Gigabit Ethernet MAC (GMAC)         */
  MCAN0_INT1_IRQn           =  68, /* 68  Controller Area Network (MCAN0)     */
  MCAN1_INT1_IRQn           =  69, /* 69  Controller Area Network (MCAN1)     */

  PERIPH_MAX_IRQn           =  69  /* Max peripheral ID */
} IRQn_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* CMSIS includes */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
   /* IO definitions (access restrictions to peripheral registers) */
   #ifdef __cplusplus
     #define __I  volatile       /* Defines 'read-only'  permissions */
   #else
     #define __I  volatile const /* Defines 'read-only'  permissions */
   #endif
   #define   __O  volatile       /* Defines 'write-only' permissions */
   #define   __IO volatile       /* Defines 'read/write' permissions */
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ************************************************************************** */
/*   SOFTWARE PERIPHERAL API DEFINITION FOR SAM9X75                           */
/* ************************************************************************** */
#include "component/adc.h"
#include "component/aes.h"
#include "component/aic.h"
#include "component/bsc.h"
#include "component/classd.h"
#include "component/csi.h"
#include "component/csi2dc.h"
#include "component/dbgu.h"
#include "component/dsi.h"
#include "component/flexcom.h"
#include "component/gfx2d.h"
#include "component/gmac.h"
#include "component/gpbr.h"
#include "component/i2smcc.h"
#include "component/isc.h"
#include "component/lcdc.h"
#include "component/lvdsc.h"
#include "component/matrix.h"
#include "component/mcan.h"
#include "component/mpddrc.h"
#include "component/otpc.h"
#include "component/pio.h"
#include "component/pit.h"
#include "component/pit64b.h"
#include "component/pmc.h"
#include "component/pmecc.h"
#include "component/pmerrloc.h"
#include "component/puf.h"
#include "component/pwm.h"
#include "component/qspi.h"
#include "component/rstc.h"
#include "component/rtc.h"
#include "component/rtt.h"
#include "component/sckc.h"
#include "component/sdmmc.h"
#include "component/sfr.h"
#include "component/sha.h"
#include "component/shdwc.h"
#include "component/smc.h"
#include "component/ssc.h"
#include "component/syscwp.h"
#include "component/tc.h"
#include "component/tdes.h"
#include "component/trng.h"
#include "component/udphs.h"
#include "component/uhphs.h"
#include "component/wdt.h"
#include "component/xdmac.h"

/* ************************************************************************** */
/*   INSTANCE DEFINITIONS FOR SAM9X75 */
/* ************************************************************************** */
#include "instance/adc.h"
#include "instance/aes.h"
#include "instance/aic.h"
#include "instance/bsc.h"
#include "instance/classd.h"
#include "instance/csi.h"
#include "instance/csi2dc.h"
#include "instance/dbgu.h"
#include "instance/dsi.h"
#include "instance/flexcom0.h"
#include "instance/flexcom1.h"
#include "instance/flexcom10.h"
#include "instance/flexcom11.h"
#include "instance/flexcom12.h"
#include "instance/flexcom2.h"
#include "instance/flexcom3.h"
#include "instance/flexcom4.h"
#include "instance/flexcom5.h"
#include "instance/flexcom6.h"
#include "instance/flexcom7.h"
#include "instance/flexcom8.h"
#include "instance/flexcom9.h"
#include "instance/gfx2d.h"
#include "instance/gmac.h"
#include "instance/gpbr.h"
#include "instance/i2smcc.h"
#include "instance/isc.h"
#include "instance/lvdsc.h"
#include "instance/matrix.h"
#include "instance/mcan0.h"
#include "instance/mcan1.h"
#include "instance/mpddrc.h"
#include "instance/otpc.h"
#include "instance/pioa.h"
#include "instance/piob.h"
#include "instance/pioc.h"
#include "instance/piod.h"
#include "instance/pit.h"
#include "instance/pit64b0.h"
#include "instance/pit64b1.h"
#include "instance/pmc.h"
#include "instance/pmecc.h"
#include "instance/pmerrloc.h"
#include "instance/puf.h"
#include "instance/pwm.h"
#include "instance/qspi.h"
#include "instance/rstc.h"
#include "instance/rtc.h"
#include "instance/rtt.h"
#include "instance/sckc.h"
#include "instance/sdmmc0.h"
#include "instance/sdmmc1.h"
#include "instance/sfr.h"
#include "instance/sha.h"
#include "instance/shdwc.h"
#include "instance/smc.h"
#include "instance/ssc.h"
#include "instance/syscwp.h"
#include "instance/tc0.h"
#include "instance/tc1.h"
#include "instance/tdes.h"
#include "instance/trng.h"
#include "instance/udphs.h"
#include "instance/uhphs_ehci.h"
#include "instance/wdt.h"
#include "instance/xdmac.h"
#include "instance/xlcdc.h"

/* ************************************************************************** */
/*  PERIPHERAL ID DEFINITIONS FOR SAM9X75                                     */
/* ************************************************************************** */
#define ID_FIQ           (  0) /* Advanced Interrupt Controller (FIQ) */
#define ID_PIOA          (  2) /* Parallel I/O Controller A (PIOA) */
#define ID_PIOB          (  3) /* Parallel I/O Controller B (PIOB) */
#define ID_PIOC          (  4) /* Parallel I/O Controller C (PIOC) */
#define ID_FLEXCOM0      (  5) /* Flexcom 0 (FLEXCOM0) */
#define ID_FLEXCOM1      (  6) /* Flexcom 1 (FLEXCOM1) */
#define ID_FLEXCOM2      (  7) /* Flexcom 2 (FLEXCOM2) */
#define ID_FLEXCOM3      (  8) /* Flexcom 3 (FLEXCOM3) */
#define ID_FLEXCOM6      (  9) /* Flexcom 6 (FLEXCOM6) */
#define ID_FLEXCOM7      ( 10) /* Flexcom 7 (FLEXCOM7) */
#define ID_FLEXCOM8      ( 11) /* Flexcom 8 (FLEXCOM8) */
#define ID_SDMMC0        ( 12) /* Secure Data Memory Card Controller 0 (SDMMC0) */
#define ID_FLEXCOM4      ( 13) /* Flexcom 4 (FLEXCOM4) */
#define ID_FLEXCOM5      ( 14) /* Flexcom 5 (FLEXCOM5) */
#define ID_FLEXCOM9      ( 15) /* Flexcom 9 (FLEXCOM9) */
#define ID_FLEXCOM10     ( 16) /* Flexcom 10 (FLEXCOM10) */
#define ID_TC0           ( 17) /* TC 0,1,2 (TC0) */
#define ID_PWM           ( 18) /* Pulse Width Modulation Controller (PWM) */
#define ID_ADC           ( 19) /* ADC Controller (ADC) */
#define ID_XDMAC         ( 20) /* Extended DMA Controller (XDMAC) */
#define ID_MATRIX        ( 21) /* Matrix (MATRIX) */
#define ID_UHPHS         ( 22) /* USB Host High Speed (UHPHS) */
#define ID_UDPHS         ( 23) /* USB Device High Speed (UDPHS) */
#define ID_GMAC          ( 24) /* Gigabit Ethernet MAC (GMAC) */
#define ID_XLCDC         ( 25) /* LCD Controller (XLCDC) */
#define ID_SDMMC1        ( 26) /* Secure Data Memory Card Controller 1 (SDMMC1) */
#define ID_SSC           ( 28) /* Synchronous Serial Controller (SSC) */
#define ID_MCAN0         ( 29) /* Master CAN 0 (MCAN0) */
#define ID_MCAN1         ( 30) /* Master CAN 1 (MCAN1) */
#define ID_IRQ           ( 31) /* Advanced Interrupt Controller (IRQ) */
#define ID_FLEXCOM11     ( 32) /* Flexcom 11 (FLEXCOM11) */
#define ID_FLEXCOM12     ( 33) /* Flexcom 12 (FLEXCOM12) */
#define ID_I2SMCC        ( 34) /* I2S Multi Channel Controller (I2SMCC) */
#define ID_QSPI          ( 35) /* Quad I/O SPI Controller (QSPI) */
#define ID_GFX2D         ( 36) /* 2D Graphic Controller (GFX2D) */
#define ID_PIT64B0       ( 37) /* 64-b Timer 0 (PIT64B0) */
#define ID_TRNG          ( 38) /* True Random Number Generator (TRNG) */
#define ID_AES           ( 39) /* Advanced Encryption Standard (AES) */
#define ID_TDES          ( 40) /* Triple Data Encryption Standard (TDES) */
#define ID_SHA           ( 41) /* Secure Hash Algorithm (SHA) */
#define ID_CLASSD        ( 42) /* CLASS D Controller (CLASSD) */
#define ID_ISC           ( 43) /* Camera Interface (ISC) */
#define ID_PIOD          ( 44) /* Parallel I/O Controller D (PIOD) */
#define ID_TC1           ( 45) /* TC 3,4,5 (TC1) */
#define ID_OTPC          ( 46) /* OTP Controller (OTPC) */
#define ID_DBGU          ( 47) /* DBGU (DBGU) */
#define ID_PMECC         ( 48) /* logical-OR interrupt of PMECC and PMERRLOC (PMECC) */
#define ID_MPDDRC        ( 49) /* logical-OR interrupt of MPDDRC and SMC (MPDDRC) */
#define ID_CSI2DC        ( 52) /* CSI to Demultiplexer Controller (CSI2DC) */
#define ID_CSI           ( 53) /* Camera Serial Interface 2 4-Lanes (CSI) */
#define ID_DSI           ( 54) /* Display Serial Interface 4-Lanes (DSI) */
#define ID_MIPIPHY       ( 55) /* MIPI DPHY interface (MIPIPHY) */
#define ID_LVDSC         ( 56) /* Display Serial Interface between XLCDC and LVDS interface (LVDSC) */
#define ID_LVDSPHY       ( 57) /* LVDS PHY (LVDSPHY) */
#define ID_PIT64B1       ( 58) /* 64-b Timer 1 (PIT64B1) */
#define ID_PUF           ( 59) /* HW PUF QuiddiKey IP (PUF) */
#define ID_GMAC_Q1       ( 60) /* GMAC Queue 1 Interrupt signal toggled on a DMA write to the first word of each DMA data buffer associated with queue 1 (GMAC_Q1) */
#define ID_GMAC_Q2       ( 61) /* GMAC Queue 2 Interrupt signal toggled on a DMA write to the first word of each DMA data buffer associated with queue 2 (GMAC_Q2) */
#define ID_GMAC_Q3       ( 62) /* GMAC Queue 3 Interrupt signal toggled on a DMA write to the first word of each DMA data buffer associated with queue 3 (GMAC_Q3) */
#define ID_GMAC_Q4       ( 63) /* GMAC Queue 4 Interrupt signal toggled on a DMA write to the first word of each DMA data buffer associated with queue 4 (GMAC_Q4) */
#define ID_GMAC_Q5       ( 64) /* GMAC Queue 5 Interrupt signal toggled on a DMA write to the first word of each DMA data buffer associated with queue 5 (GMAC_Q5) */
#define ID_GMAC_EMAC     ( 65) /* Gigabit Ethernet MAC - Express MAC (GMAC_EMAC) */
#define ID_GMAC_MMSL     ( 66) /* Gigabit Ethernet MAC - Mac Merge SubLayer (GMAC_MMSL) */
#define ID_GMAC_TSU      ( 67) /* Gigabit Ethernet MAC - Time Stamp Unit (GMAC_TSU) */

#define ID_PERIPH_MAX    ( 67) /* Number of peripheral IDs */

/* ************************************************************************** */
/*   REGISTER STRUCTURE ADDRESS DEFINITIONS FOR SAM9X75                       */
/* ************************************************************************** */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#define ADC_REGS                         ((adc_registers_t*)0xf804c000)                /* ADC Registers Address        */
#define AES_REGS                         ((aes_registers_t*)0xf0034000)                /* AES Registers Address        */
#define AIC_REGS                         ((aic_registers_t*)0xfffff100)                /* AIC Registers Address        */
#define BSC_REGS                         ((bsc_registers_t*)0xfffffe54)                /* BSC Registers Address        */
#define CLASSD_REGS                      ((classd_registers_t*)0xf003c000)             /* CLASSD Registers Address     */
#define CSI_REGS                         ((csi_registers_t*)0xf8058000)                /* CSI Registers Address        */
#define CSI2DC_REGS                      ((csi2dc_registers_t*)0xf805c000)             /* CSI2DC Registers Address     */
#define DBGU_REGS                        ((dbgu_registers_t*)0xfffff200)               /* DBGU Registers Address       */
#define DSI_REGS                         ((dsi_registers_t*)0xf8054000)                /* DSI Registers Address        */
#define FLEXCOM0_REGS                    ((flexcom_registers_t*)0xf801c000)            /* FLEXCOM0 Registers Address   */
#define FLEXCOM1_REGS                    ((flexcom_registers_t*)0xf8020000)            /* FLEXCOM1 Registers Address   */
#define FLEXCOM2_REGS                    ((flexcom_registers_t*)0xf8024000)            /* FLEXCOM2 Registers Address   */
#define FLEXCOM3_REGS                    ((flexcom_registers_t*)0xf8028000)            /* FLEXCOM3 Registers Address   */
#define FLEXCOM4_REGS                    ((flexcom_registers_t*)0xf0000000)            /* FLEXCOM4 Registers Address   */
#define FLEXCOM5_REGS                    ((flexcom_registers_t*)0xf0004000)            /* FLEXCOM5 Registers Address   */
#define FLEXCOM6_REGS                    ((flexcom_registers_t*)0xf8010000)            /* FLEXCOM6 Registers Address   */
#define FLEXCOM7_REGS                    ((flexcom_registers_t*)0xf8014000)            /* FLEXCOM7 Registers Address   */
#define FLEXCOM8_REGS                    ((flexcom_registers_t*)0xf8018000)            /* FLEXCOM8 Registers Address   */
#define FLEXCOM9_REGS                    ((flexcom_registers_t*)0xf8040000)            /* FLEXCOM9 Registers Address   */
#define FLEXCOM10_REGS                   ((flexcom_registers_t*)0xf8044000)            /* FLEXCOM10 Registers Address  */
#define FLEXCOM11_REGS                   ((flexcom_registers_t*)0xf0020000)            /* FLEXCOM11 Registers Address  */
#define FLEXCOM12_REGS                   ((flexcom_registers_t*)0xf0024000)            /* FLEXCOM12 Registers Address  */
#define GFX2D_REGS                       ((gfx2d_registers_t*)0xf0018000)              /* GFX2D Registers Address      */
#define GMAC_REGS                        ((gmac_registers_t*)0xf802c000)               /* GMAC Registers Address       */
#define GPBR_REGS                        ((gpbr_registers_t*)0xfffffe60)               /* GPBR Registers Address       */
#define I2SMCC_REGS                      ((i2smcc_registers_t*)0xf001c000)             /* I2SMCC Registers Address     */
#define ISC_REGS                         ((isc_registers_t*)0xf8048000)                /* ISC Registers Address        */
#define XLCDC_REGS                       ((lcdc_registers_t*)0xf8038000)               /* XLCDC Registers Address      */
#define LVDSC_REGS                       ((lvdsc_registers_t*)0xf8060000)              /* LVDSC Registers Address      */
#define MATRIX_REGS                      ((matrix_registers_t*)0xffffde00)             /* MATRIX Registers Address     */
#define MCAN0_REGS                       ((mcan_registers_t*)0xf8000000)               /* MCAN0 Registers Address      */
#define MCAN1_REGS                       ((mcan_registers_t*)0xf8004000)               /* MCAN1 Registers Address      */
#define MPDDRC_REGS                      ((mpddrc_registers_t*)0xffffe800)             /* MPDDRC Registers Address     */
#define OTPC_REGS                        ((otpc_registers_t*)0xeff00000)               /* OTPC Registers Address       */
#define PIOA_REGS                        ((pio_registers_t*)0xfffff400)                /* PIOA Registers Address       */
#define PIOB_REGS                        ((pio_registers_t*)0xfffff600)                /* PIOB Registers Address       */
#define PIOC_REGS                        ((pio_registers_t*)0xfffff800)                /* PIOC Registers Address       */
#define PIOD_REGS                        ((pio_registers_t*)0xfffffa00)                /* PIOD Registers Address       */
#define PIT_REGS                         ((pit_registers_t*)0xfffffe40)                /* PIT Registers Address        */
#define PIT64B0_REGS                     ((pit64b_registers_t*)0xf0028000)             /* PIT64B0 Registers Address    */
#define PIT64B1_REGS                     ((pit64b_registers_t*)0xf0040000)             /* PIT64B1 Registers Address    */
#define PMC_REGS                         ((pmc_registers_t*)0xfffffc00)                /* PMC Registers Address        */
#define PMECC_REGS                       ((pmecc_registers_t*)0xffffe000)              /* PMECC Registers Address      */
#define PMERRLOC_REGS                    ((pmerrloc_registers_t*)0xffffe600)           /* PMERRLOC Registers Address   */
#define PUF_REGS                         ((puf_registers_t*)0xf8030000)                /* PUF Registers Address        */
#define PWM_REGS                         ((pwm_registers_t*)0xf8034000)                /* PWM Registers Address        */
#define QSPI_REGS                        ((qspi_registers_t*)0xf0014000)               /* QSPI Registers Address       */
#define RSTC_REGS                        ((rstc_registers_t*)0xfffffe00)               /* RSTC Registers Address       */
#define RTC_REGS                         ((rtc_registers_t*)0xfffffea8)                /* RTC Registers Address        */
#define RTT_REGS                         ((rtt_registers_t*)0xfffffe20)                /* RTT Registers Address        */
#define SCKC_REGS                        ((sckc_registers_t*)0xfffffe50)               /* SCKC Registers Address       */
#define SDMMC0_REGS                      ((sdmmc_registers_t*)0x80000000)              /* SDMMC0 Registers Address     */
#define SDMMC1_REGS                      ((sdmmc_registers_t*)0x90000000)              /* SDMMC1 Registers Address     */
#define SFR_REGS                         ((sfr_registers_t*)0xf8050000)                /* SFR Registers Address        */
#define SHA_REGS                         ((sha_registers_t*)0xf002c000)                /* SHA Registers Address        */
#define SHDWC_REGS                       ((shdwc_registers_t*)0xfffffe10)              /* SHDWC Registers Address      */
#define SMC_REGS                         ((smc_registers_t*)0xffffea00)                /* SMC Registers Address        */
#define SSC_REGS                         ((ssc_registers_t*)0xf0010000)                /* SSC Registers Address        */
#define SYSCWP_REGS                      ((syscwp_registers_t*)0xfffffedc)             /* SYSCWP Registers Address     */
#define TC0_REGS                         ((tc_registers_t*)0xf8008000)                 /* TC0 Registers Address        */
#define TC1_REGS                         ((tc_registers_t*)0xf800c000)                 /* TC1 Registers Address        */
#define TDES_REGS                        ((tdes_registers_t*)0xf0038000)               /* TDES Registers Address       */
#define TRNG_REGS                        ((trng_registers_t*)0xf0030000)               /* TRNG Registers Address       */
#define UDPHS_REGS                       ((udphs_registers_t*)0xf803c000)              /* UDPHS Registers Address      */
#define UHPHS_EHCI_REGS                  ((uhphs_registers_t*)0x00700000)              /* UHPHS_EHCI Registers Address */
#define WDT_REGS                         ((wdt_registers_t*)0xffffff80)                /* WDT Registers Address        */
#define XDMAC_REGS                       ((xdmac_registers_t*)0xf0008000)              /* XDMAC Registers Address      */
#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ************************************************************************** */
/*   BASE ADDRESS DEFINITIONS FOR SAM9X75                                     */
/* ************************************************************************** */
#define ADC_BASE_ADDRESS                 _UINT32_(0xf804c000)                          /* ADC Base Address */
#define AES_BASE_ADDRESS                 _UINT32_(0xf0034000)                          /* AES Base Address */
#define AIC_BASE_ADDRESS                 _UINT32_(0xfffff100)                          /* AIC Base Address */
#define BSC_BASE_ADDRESS                 _UINT32_(0xfffffe54)                          /* BSC Base Address */
#define CLASSD_BASE_ADDRESS              _UINT32_(0xf003c000)                          /* CLASSD Base Address */
#define CSI_BASE_ADDRESS                 _UINT32_(0xf8058000)                          /* CSI Base Address */
#define CSI2DC_BASE_ADDRESS              _UINT32_(0xf805c000)                          /* CSI2DC Base Address */
#define DBGU_BASE_ADDRESS                _UINT32_(0xfffff200)                          /* DBGU Base Address */
#define DSI_BASE_ADDRESS                 _UINT32_(0xf8054000)                          /* DSI Base Address */
#define FLEXCOM0_BASE_ADDRESS            _UINT32_(0xf801c000)                          /* FLEXCOM0 Base Address */
#define FLEXCOM1_BASE_ADDRESS            _UINT32_(0xf8020000)                          /* FLEXCOM1 Base Address */
#define FLEXCOM2_BASE_ADDRESS            _UINT32_(0xf8024000)                          /* FLEXCOM2 Base Address */
#define FLEXCOM3_BASE_ADDRESS            _UINT32_(0xf8028000)                          /* FLEXCOM3 Base Address */
#define FLEXCOM4_BASE_ADDRESS            _UINT32_(0xf0000000)                          /* FLEXCOM4 Base Address */
#define FLEXCOM5_BASE_ADDRESS            _UINT32_(0xf0004000)                          /* FLEXCOM5 Base Address */
#define FLEXCOM6_BASE_ADDRESS            _UINT32_(0xf8010000)                          /* FLEXCOM6 Base Address */
#define FLEXCOM7_BASE_ADDRESS            _UINT32_(0xf8014000)                          /* FLEXCOM7 Base Address */
#define FLEXCOM8_BASE_ADDRESS            _UINT32_(0xf8018000)                          /* FLEXCOM8 Base Address */
#define FLEXCOM9_BASE_ADDRESS            _UINT32_(0xf8040000)                          /* FLEXCOM9 Base Address */
#define FLEXCOM10_BASE_ADDRESS           _UINT32_(0xf8044000)                          /* FLEXCOM10 Base Address */
#define FLEXCOM11_BASE_ADDRESS           _UINT32_(0xf0020000)                          /* FLEXCOM11 Base Address */
#define FLEXCOM12_BASE_ADDRESS           _UINT32_(0xf0024000)                          /* FLEXCOM12 Base Address */
#define GFX2D_BASE_ADDRESS               _UINT32_(0xf0018000)                          /* GFX2D Base Address */
#define GMAC_BASE_ADDRESS                _UINT32_(0xf802c000)                          /* GMAC Base Address */
#define GPBR_BASE_ADDRESS                _UINT32_(0xfffffe60)                          /* GPBR Base Address */
#define I2SMCC_BASE_ADDRESS              _UINT32_(0xf001c000)                          /* I2SMCC Base Address */
#define ISC_BASE_ADDRESS                 _UINT32_(0xf8048000)                          /* ISC Base Address */
#define XLCDC_BASE_ADDRESS               _UINT32_(0xf8038000)                          /* XLCDC Base Address */
#define LVDSC_BASE_ADDRESS               _UINT32_(0xf8060000)                          /* LVDSC Base Address */
#define MATRIX_BASE_ADDRESS              _UINT32_(0xffffde00)                          /* MATRIX Base Address */
#define MCAN0_BASE_ADDRESS               _UINT32_(0xf8000000)                          /* MCAN0 Base Address */
#define MCAN1_BASE_ADDRESS               _UINT32_(0xf8004000)                          /* MCAN1 Base Address */
#define MPDDRC_BASE_ADDRESS              _UINT32_(0xffffe800)                          /* MPDDRC Base Address */
#define OTPC_BASE_ADDRESS                _UINT32_(0xeff00000)                          /* OTPC Base Address */
#define PIOA_BASE_ADDRESS                _UINT32_(0xfffff400)                          /* PIOA Base Address */
#define PIOB_BASE_ADDRESS                _UINT32_(0xfffff600)                          /* PIOB Base Address */
#define PIOC_BASE_ADDRESS                _UINT32_(0xfffff800)                          /* PIOC Base Address */
#define PIOD_BASE_ADDRESS                _UINT32_(0xfffffa00)                          /* PIOD Base Address */
#define PIT_BASE_ADDRESS                 _UINT32_(0xfffffe40)                          /* PIT Base Address */
#define PIT64B0_BASE_ADDRESS             _UINT32_(0xf0028000)                          /* PIT64B0 Base Address */
#define PIT64B1_BASE_ADDRESS             _UINT32_(0xf0040000)                          /* PIT64B1 Base Address */
#define PMC_BASE_ADDRESS                 _UINT32_(0xfffffc00)                          /* PMC Base Address */
#define PMECC_BASE_ADDRESS               _UINT32_(0xffffe000)                          /* PMECC Base Address */
#define PMERRLOC_BASE_ADDRESS            _UINT32_(0xffffe600)                          /* PMERRLOC Base Address */
#define PUF_BASE_ADDRESS                 _UINT32_(0xf8030000)                          /* PUF Base Address */
#define PWM_BASE_ADDRESS                 _UINT32_(0xf8034000)                          /* PWM Base Address */
#define QSPI_BASE_ADDRESS                _UINT32_(0xf0014000)                          /* QSPI Base Address */
#define RSTC_BASE_ADDRESS                _UINT32_(0xfffffe00)                          /* RSTC Base Address */
#define RTC_BASE_ADDRESS                 _UINT32_(0xfffffea8)                          /* RTC Base Address */
#define RTT_BASE_ADDRESS                 _UINT32_(0xfffffe20)                          /* RTT Base Address */
#define SCKC_BASE_ADDRESS                _UINT32_(0xfffffe50)                          /* SCKC Base Address */
#define SDMMC0_BASE_ADDRESS              _UINT32_(0x80000000)                          /* SDMMC0 Base Address */
#define SDMMC1_BASE_ADDRESS              _UINT32_(0x90000000)                          /* SDMMC1 Base Address */
#define SFR_BASE_ADDRESS                 _UINT32_(0xf8050000)                          /* SFR Base Address */
#define SHA_BASE_ADDRESS                 _UINT32_(0xf002c000)                          /* SHA Base Address */
#define SHDWC_BASE_ADDRESS               _UINT32_(0xfffffe10)                          /* SHDWC Base Address */
#define SMC_BASE_ADDRESS                 _UINT32_(0xffffea00)                          /* SMC Base Address */
#define SSC_BASE_ADDRESS                 _UINT32_(0xf0010000)                          /* SSC Base Address */
#define SYSCWP_BASE_ADDRESS              _UINT32_(0xfffffedc)                          /* SYSCWP Base Address */
#define TC0_BASE_ADDRESS                 _UINT32_(0xf8008000)                          /* TC0 Base Address */
#define TC1_BASE_ADDRESS                 _UINT32_(0xf800c000)                          /* TC1 Base Address */
#define TDES_BASE_ADDRESS                _UINT32_(0xf0038000)                          /* TDES Base Address */
#define TRNG_BASE_ADDRESS                _UINT32_(0xf0030000)                          /* TRNG Base Address */
#define UDPHS_BASE_ADDRESS               _UINT32_(0xf803c000)                          /* UDPHS Base Address */
#define UHPHS_EHCI_BASE_ADDRESS          _UINT32_(0x00700000)                          /* UHPHS_EHCI Base Address */
#define WDT_BASE_ADDRESS                 _UINT32_(0xffffff80)                          /* WDT Base Address */
#define XDMAC_BASE_ADDRESS               _UINT32_(0xf0008000)                          /* XDMAC Base Address */

/* ************************************************************************** */
/*   PIO DEFINITIONS FOR SAM9X75                                              */
/* ************************************************************************** */
#include "pio/sam9x75.h"

/* ************************************************************************** */
/*   MEMORY MAPPING DEFINITIONS FOR SAM9X75                                   */
/* ************************************************************************** */
#define ECC_ROM_SIZE                   _UINT32_(0x00100000)    /* 1024kB Memory segment type: rom */
#define SRAM0_SIZE                     _UINT32_(0x00100000)    /* 1024kB Memory segment type: ram */
#define SRAM1_SIZE                     _UINT32_(0x00100000)    /* 1024kB Memory segment type: ram */
#define UDPHS_RAM_SIZE                 _UINT32_(0x00100000)    /* 1024kB Memory segment type: ram */
#define UHPHS_OHCI_SIZE                _UINT32_(0x00100000)    /* 1024kB Memory segment type: ram */
#define UHPHS_EHCI_SIZE                _UINT32_(0x00100000)    /* 1024kB Memory segment type: ram */
#define EBI_CS0_SIZE                   _UINT32_(0x10000000)    /* 262144kB Memory segment type: ram */
#define EBI_CS1_SIZE                   _UINT32_(0x10000000)    /* 262144kB Memory segment type: ram */
#define EBI_MPDDR_SIZE                 _UINT32_(0x10000000)    /* 262144kB Memory segment type: ram */
#define SDRAM_CS_SIZE                  _UINT32_(0x10000000)    /* 262144kB Memory segment type: ram */
#define EBI_CS2_SIZE                   _UINT32_(0x10000000)    /* 262144kB Memory segment type: ram */
#define EBI_NF_SIZE                    _UINT32_(0x10000000)    /* 262144kB Memory segment type: ram */
#define QSPIMEM_SIZE                   _UINT32_(0x20000000)    /* 524288kB Memory segment type: ram */
#define SDMMC0_SIZE                    _UINT32_(0x10000000)    /* 262144kB Memory segment type: ram */
#define SDMMC1_SIZE                    _UINT32_(0x10000000)    /* 262144kB Memory segment type: ram */
#define CSI2DC_META_SIZE               _UINT32_(0x00100000)    /* 1024kB Memory segment type: ram */
#define OTPC_SIZE                      _UINT32_(0x00001000)    /*    4kB Memory segment type: ram */

#define ECC_ROM_ADDR                   _UINT32_(0x00100000)    /* ECC_ROM base address (type: rom)*/
#define SRAM0_ADDR                     _UINT32_(0x00300000)    /* SRAM0 base address (type: ram)*/
#define SRAM1_ADDR                     _UINT32_(0x00400000)    /* SRAM1 base address (type: ram)*/
#define UDPHS_RAM_ADDR                 _UINT32_(0x00500000)    /* UDPHS_RAM base address (type: ram)*/
#define UHPHS_OHCI_ADDR                _UINT32_(0x00600000)    /* UHPHS_OHCI base address (type: ram)*/
#define UHPHS_EHCI_ADDR                _UINT32_(0x00700000)    /* UHPHS_EHCI base address (type: ram)*/
#define EBI_CS0_ADDR                   _UINT32_(0x10000000)    /* EBI_CS0 base address (type: ram)*/
#define EBI_CS1_ADDR                   _UINT32_(0x20000000)    /* EBI_CS1 base address (type: ram)*/
#define EBI_MPDDR_ADDR                 _UINT32_(0x20000000)    /* EBI_MPDDR base address (type: ram)*/
#define SDRAM_CS_ADDR                  _UINT32_(0x20000000)    /* SDRAM_CS base address (type: ram)*/
#define EBI_CS2_ADDR                   _UINT32_(0x30000000)    /* EBI_CS2 base address (type: ram)*/
#define EBI_NF_ADDR                    _UINT32_(0x30000000)    /* EBI_NF base address (type: ram)*/
#define QSPIMEM_ADDR                   _UINT32_(0x60000000)    /* QSPIMEM base address (type: ram)*/
#define SDMMC0_ADDR                    _UINT32_(0x80000000)    /* SDMMC0 base address (type: ram)*/
#define SDMMC1_ADDR                    _UINT32_(0x90000000)    /* SDMMC1 base address (type: ram)*/
#define CSI2DC_META_ADDR               _UINT32_(0xd0000000)    /* CSI2DC_META base address (type: ram)*/
#define OTPC_ADDR                      _UINT32_(0xeff00000)    /* OTPC base address (type: ram)*/

/* ************************************************************************** */
/*   DEVICE SIGNATURES FOR SAM9X75                                            */
/* ************************************************************************** */
#define CHIP_JTAGID                    _UINT32_(0X00000000)
#define CHIP_CIDR                      _UINT32_(0X89750030)
#define CHIP_EXID                      _UINT32_(0X00000085)

/* ************************************************************************** */
/*   ELECTRICAL DEFINITIONS FOR SAM9X75                                       */
/* ************************************************************************** */



#ifdef __cplusplus
}
#endif

#endif /* _SAM9X75_H_ */

