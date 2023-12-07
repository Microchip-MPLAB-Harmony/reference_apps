/*******************************************************************************
 Cortex-M device vectors file

  Company:
    Microchip Technology Inc.

  File Name:
    device_vectors.h

  Summary:
    Harmony3 device handler structure for cortex-M devices

  Description:
    This file contains Harmony3 device handler structure for cortex-M devices
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

#ifndef DEVICE_VECTORS_H
#define DEVICE_VECTORS_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stdint.h>

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

/* Function pointer type for vector handlers */
typedef void (*pfn_handler_t)(void);

/* Structure defining device vector types */
typedef struct _H3DeviceVectors
{
  /* Stack pointer */
  uint32_t* pvStack;

  /* CORTEX-M33 handlers */ 
  pfn_handler_t pfnReset_Handler;                   /* -15 Reset Vector, invoked on Power up and warm reset */
  pfn_handler_t pfnNonMaskableInt_Handler;          /* -14 Non maskable Interrupt, cannot be stopped or preempted */
  pfn_handler_t pfnHardFault_Handler;               /* -13 Hard Fault, all classes of Fault */
  pfn_handler_t pfnMemoryManagement_Handler;        /* -12 Memory Management, MPU mismatch, including Access Violation and No Match */
  pfn_handler_t pfnBusFault_Handler;                /* -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
  pfn_handler_t pfnUsageFault_Handler;              /* -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition */
  pfn_handler_t pfnSecureFaultMonitor_Handler;      /* -9 Secure Fault */
  pfn_handler_t pfnReservedC8;
  pfn_handler_t pfnReservedC7;
  pfn_handler_t pfnReservedC6;
  pfn_handler_t pfnSVCall_Handler;                  /* -5 System Service Call via SVC instruction */
  pfn_handler_t pfnDebugMonitor_Handler;            /* -4 Debug Monitor */
  pfn_handler_t pfnReservedC3;
  pfn_handler_t pfnPendSV_Handler;                  /* -2 Pendable request for system service */
  pfn_handler_t pfnSysTick_Handler;                 /* -1 System Tick Timer */

  /* Peripheral handlers */
  pfn_handler_t pfnFCR_ERR_Handler;                 /* 0 Flash Read Controller ECC Error */
  pfn_handler_t pfnFCR_FLT_Handler;                 /* 1 Flash Read Controller CRC Fault */
  pfn_handler_t pfnFCW_Handler;                     /* 2 Flash Write Controller Interrupt */
  pfn_handler_t pfnPM_Handler;                      /* 3 Power Manager */
  pfn_handler_t pfnSUPC_Handler;                    /* 4 Supply Controller */
  pfn_handler_t pfnOSCCTRL_XOSC_Handler;            /* 5 External Oscillator */
  pfn_handler_t pfnOSCCTRL_DFLL_Handler;            /* 6 DFLL */
  pfn_handler_t pfnOSCCTRL_PLL0_Handler;            /* 7 PLL */
  pfn_handler_t pfnOSC32KCTRL_Handler;              /* 8 32K Oscillator */
  pfn_handler_t pfnMCLK_Handler;                    /* 9 Main Clock */
  pfn_handler_t pfnFREQM_Handler;                   /* 10 Frequency Meter */
  pfn_handler_t pfnWDT_Handler;                     /* 11 Watchdog Timer */
  pfn_handler_t pfnRTC_Handler;                     /* 12 RTC */
  pfn_handler_t pfnEIC_EXTINT_0_Handler;            /* 13 External Interrupt 0 */
  pfn_handler_t pfnEIC_EXTINT_1_Handler;            /* 14 External Interrupt 1 */
  pfn_handler_t pfnEIC_EXTINT_2_Handler;            /* 15 External Interrupt 2 */
  pfn_handler_t pfnEIC_EXTINT_3_Handler;            /* 16 External Interrupt 3 */
  pfn_handler_t pfnEIC_EXTINT_4_Handler;            /* 17 External Interrupt 4 */
  pfn_handler_t pfnEIC_EXTINT_5_Handler;            /* 18 External Interrupt 5 */
  pfn_handler_t pfnEIC_EXTINT_6_Handler;            /* 19 External Interrupt 6 */
  pfn_handler_t pfnEIC_EXTINT_7_Handler;            /* 20 External Interrupt 7 */
  pfn_handler_t pfnEIC_EXTINT_8_Handler;            /* 21 External Interrupt 8 */
  pfn_handler_t pfnEIC_EXTINT_9_Handler;            /* 22 External Interrupt 9 */
  pfn_handler_t pfnEIC_EXTINT_10_Handler;           /* 23 External Interrupt 10 */
  pfn_handler_t pfnEIC_EXTINT_11_Handler;           /* 24 External Interrupt 11 */
  pfn_handler_t pfnEIC_EXTINT_12_Handler;           /* 25 External Interrupt 12 */
  pfn_handler_t pfnEIC_EXTINT_13_Handler;           /* 26 External Interrupt 13 */
  pfn_handler_t pfnEIC_EXTINT_14_Handler;           /* 27 External Interrupt 14 */
  pfn_handler_t pfnEIC_EXTINT_15_Handler;           /* 28 External Interrupt 15 */
  pfn_handler_t pfnEIC_NSCHK_Handler;               /* 29 External Interrupt Non-Secure Check */
  pfn_handler_t pfnPAC_Handler;                     /* 30 Peripheral Access Controller */
  pfn_handler_t pfnTRAM_Handler;                    /* 31 Trust RAM Interrupt */
  pfn_handler_t pfnPORT_Handler;                    /* 32 Port */
  pfn_handler_t pfnDMA0_PRI0_Handler;               /* 33 DMA 0 Priority 0 Interrupt */
  pfn_handler_t pfnDMA0_PRI1_Handler;               /* 34 DMA 0 Priority 1 Interrupt */
  pfn_handler_t pfnDMA0_PRI2_Handler;               /* 35 DMA 0 Priority 2 Interrupt */
  pfn_handler_t pfnDMA1_PRI0_Handler;               /* 36 DMA 1 Priority 0 Interrupt */
  pfn_handler_t pfnDMA1_PRI1_Handler;               /* 37 DMA 1 Priority 1 Interrupt */
  pfn_handler_t pfnHMATRIX_Handler;                 /* 38 HMATRIX */
  pfn_handler_t pfnEVSYS_0_Handler;                 /* 39 Event System Channel 0 */
  pfn_handler_t pfnEVSYS_1_Handler;                 /* 40 Event System Channel 1 */
  pfn_handler_t pfnEVSYS_2_Handler;                 /* 41 Event System Channel 2 */
  pfn_handler_t pfnEVSYS_3_Handler;                 /* 42 Event System Channel 3 */
  pfn_handler_t pfnEVSYS_OTHER_Handler;             /* 43 Event System Channel 4..X */
  pfn_handler_t pfnSERCOM0_56_Handler;              /* 44 Serial Communication Interface 0 */
  pfn_handler_t pfnSERCOM0_0_Handler;               /* 45 Serial Communication Interface 0 */
  pfn_handler_t pfnSERCOM0_1_Handler;               /* 46 Serial Communication Interface 0 */
  pfn_handler_t pfnSERCOM0_2_Handler;               /* 47 Serial Communication Interface 0 */
  pfn_handler_t pfnSERCOM0_3_Handler;               /* 48 Serial Communication Interface 0 */
  pfn_handler_t pfnSERCOM0_4_Handler;               /* 49 Serial Communication Interface 0 */
  pfn_handler_t pfnSERCOM1_56_Handler;              /* 50 Serial Communication Interface 1 */
  pfn_handler_t pfnSERCOM1_0_Handler;               /* 51 Serial Communication Interface 1 */
  pfn_handler_t pfnSERCOM1_1_Handler;               /* 52 Serial Communication Interface 1 */
  pfn_handler_t pfnSERCOM1_2_Handler;               /* 53 Serial Communication Interface 1 */
  pfn_handler_t pfnSERCOM1_3_Handler;               /* 54 Serial Communication Interface 1 */
  pfn_handler_t pfnSERCOM1_4_Handler;               /* 55 Serial Communication Interface 1 */
  pfn_handler_t pfnSERCOM2_56_Handler;              /* 56 Serial Communication Interface 2 */
  pfn_handler_t pfnSERCOM2_0_Handler;               /* 57 Serial Communication Interface 2 */
  pfn_handler_t pfnSERCOM2_1_Handler;               /* 58 Serial Communication Interface 2 */
  pfn_handler_t pfnSERCOM2_2_Handler;               /* 59 Serial Communication Interface 2 */
  pfn_handler_t pfnSERCOM2_3_Handler;               /* 60 Serial Communication Interface 2 */
  pfn_handler_t pfnSERCOM2_4_Handler;               /* 61 Serial Communication Interface 2 */
  pfn_handler_t pfnSERCOM3_56_Handler;              /* 62 Serial Communication Interface 3 */
  pfn_handler_t pfnSERCOM3_0_Handler;               /* 63 Serial Communication Interface 3 */
  pfn_handler_t pfnSERCOM3_1_Handler;               /* 64 Serial Communication Interface 3 */
  pfn_handler_t pfnSERCOM3_2_Handler;               /* 65 Serial Communication Interface 3 */
  pfn_handler_t pfnSERCOM3_3_Handler;               /* 66 Serial Communication Interface 3 */
  pfn_handler_t pfnSERCOM3_4_Handler;               /* 67 Serial Communication Interface 3 */
  pfn_handler_t pfnTCC0_OTHER_Handler;              /* 68 Error/Overflow/Underflow/Fault Interrupt */
  pfn_handler_t pfnTCC0_MC0_Handler;                /* 69 TCC Match/Compare 0 */
  pfn_handler_t pfnTCC0_MC1_Handler;                /* 70 TCC Match/Compare 1 */
  pfn_handler_t pfnTCC0_MC2_Handler;                /* 71 TCC Match/Compare 2 */
  pfn_handler_t pfnTCC0_MC3_Handler;                /* 72 TCC Match/Compare 3 */
  pfn_handler_t pfnTCC0_MC4_Handler;                /* 73 TCC Match/Compare 4 */
  pfn_handler_t pfnTCC0_MC5_Handler;                /* 74 TCC Match/Compare 5 */
  pfn_handler_t pfnTCC1_OTHER_Handler;              /* 75 Error/Overflow/Underflow/Fault Interrupt */
  pfn_handler_t pfnTCC1_MC0_Handler;                /* 76 TCC Match/Compare 0 */
  pfn_handler_t pfnTCC1_MC1_Handler;                /* 77 TCC Match/Compare 1 */
  pfn_handler_t pfnTCC1_MC2_Handler;                /* 78 TCC Match/Compare 2 */
  pfn_handler_t pfnTCC1_MC3_Handler;                /* 79 TCC Match/Compare 3 */
  pfn_handler_t pfnTCC1_MC4_Handler;                /* 80 TCC Match/Compare 4 */
  pfn_handler_t pfnTCC1_MC5_Handler;                /* 81 TCC Match/Compare 5 */
  pfn_handler_t pfnTCC2_OTHER_Handler;              /* 82 Error/Overflow/Underflow/Fault Interrupt */
  pfn_handler_t pfnTCC2_MC0_Handler;                /* 83 TCC Match/Compare 0 */
  pfn_handler_t pfnTCC2_MC1_Handler;                /* 84 TCC Match/Compare 1 */
  pfn_handler_t pfnTCC2_MC2_Handler;                /* 85 TCC Match/Compare 2 */
  pfn_handler_t pfnTCC2_MC3_Handler;                /* 86 TCC Match/Compare 3 */
  pfn_handler_t pfnTCC2_MC4_Handler;                /* 87 TCC Match/Compare 4 */
  pfn_handler_t pfnTCC2_MC5_Handler;                /* 88 TCC Match/Compare 5 */
  pfn_handler_t pfnTCC3_OTHER_Handler;              /* 89 Error/Overflow/Underflow/Fault Interrupt */
  pfn_handler_t pfnTCC3_MC0_Handler;                /* 90 TCC Match/Compare 0 */
  pfn_handler_t pfnTCC3_MC1_Handler;                /* 91 TCC Match/Compare 1 */
  pfn_handler_t pfnTCC3_MC2_Handler;                /* 92 TCC Match/Compare 2 */
  pfn_handler_t pfnTCC3_MC3_Handler;                /* 93 TCC Match/Compare 3 */
  pfn_handler_t pfnTCC3_MC4_Handler;                /* 94 TCC Match/Compare 4 */
  pfn_handler_t pfnTCC3_MC5_Handler;                /* 95 TCC Match/Compare 5 */
  pfn_handler_t pfnSERCOM4_56_Handler;              /* 96 Serial Communication Interface 4 */
  pfn_handler_t pfnSERCOM4_0_Handler;               /* 97 Serial Communication Interface 4 */
  pfn_handler_t pfnSERCOM4_1_Handler;               /* 98 Serial Communication Interface 4 */
  pfn_handler_t pfnSERCOM4_2_Handler;               /* 99 Serial Communication Interface 4 */
  pfn_handler_t pfnSERCOM4_3_Handler;               /* 100 Serial Communication Interface 4 */
  pfn_handler_t pfnSERCOM4_4_Handler;               /* 101 Serial Communication Interface 4 */
  pfn_handler_t pfnSERCOM5_56_Handler;              /* 102 Serial Communication Interface 5 */
  pfn_handler_t pfnSERCOM5_0_Handler;               /* 103 Serial Communication Interface 5 */
  pfn_handler_t pfnSERCOM5_1_Handler;               /* 104 Serial Communication Interface 5 */
  pfn_handler_t pfnSERCOM5_2_Handler;               /* 105 Serial Communication Interface 5 */
  pfn_handler_t pfnSERCOM5_3_Handler;               /* 106 Serial Communication Interface 5 */
  pfn_handler_t pfnSERCOM5_4_Handler;               /* 107 Serial Communication Interface 5 */
  pfn_handler_t pfnSERCOM6_56_Handler;              /* 108 Serial Communication Interface 6 */
  pfn_handler_t pfnSERCOM6_0_Handler;               /* 109 Serial Communication Interface 6 */
  pfn_handler_t pfnSERCOM6_1_Handler;               /* 110 Serial Communication Interface 6 */
  pfn_handler_t pfnSERCOM6_2_Handler;               /* 111 Serial Communication Interface 6 */
  pfn_handler_t pfnSERCOM6_3_Handler;               /* 112 Serial Communication Interface 6 */
  pfn_handler_t pfnSERCOM6_4_Handler;               /* 113 Serial Communication Interface 6 */
  pfn_handler_t pfnSERCOM7_56_Handler;              /* 114 Serial Communication Interface 7 */
  pfn_handler_t pfnSERCOM7_0_Handler;               /* 115 Serial Communication Interface 7 */
  pfn_handler_t pfnSERCOM7_1_Handler;               /* 116 Serial Communication Interface 7 */
  pfn_handler_t pfnSERCOM7_2_Handler;               /* 117 Serial Communication Interface 7 */
  pfn_handler_t pfnSERCOM7_3_Handler;               /* 118 Serial Communication Interface 7 */
  pfn_handler_t pfnSERCOM7_4_Handler;               /* 119 Serial Communication Interface 7 */
  pfn_handler_t pfnTCC4_OTHER_Handler;              /* 120 Error/Overflow/Underflow/Fault Interrupt */
  pfn_handler_t pfnTCC4_MC0_Handler;                /* 121 TCC Match/Compare 0 */
  pfn_handler_t pfnTCC4_MC1_Handler;                /* 122 TCC Match/Compare 1 */
  pfn_handler_t pfnTCC5_OTHER_Handler;              /* 123 Error/Overflow/Underflow/Fault Interrupt */
  pfn_handler_t pfnTCC5_MC0_Handler;                /* 124 TCC Match/Compare 0 */
  pfn_handler_t pfnTCC5_MC1_Handler;                /* 125 TCC Match/Compare 1 */
  pfn_handler_t pfnTCC6_OTHER_Handler;              /* 126 Error/Overflow/Underflow/Fault Interrupt */
  pfn_handler_t pfnTCC6_MC0_Handler;                /* 127 TCC Match/Compare 0 */
  pfn_handler_t pfnTCC6_MC1_Handler;                /* 128 TCC Match/Compare 1 */
  pfn_handler_t pfnTCC7_OTHER_Handler;              /* 129 Error/Overflow/Underflow/Fault Interrupt */
  pfn_handler_t pfnTCC7_MC0_Handler;                /* 130 TCC Match/Compare 0 */
  pfn_handler_t pfnTCC7_MC1_Handler;                /* 131 TCC Match/Compare 1 */
  pfn_handler_t pfnADC_GLOBAL_Handler;              /* 132 ADC Global Interrupt */
  pfn_handler_t pfnADC_CORE1_Handler;               /* 133 ADC Core 1 Interrupt */
  pfn_handler_t pfnReserved2_Handler;               /* 134 ADC Unused/Reserved */
  pfn_handler_t pfnReserved3_Handler;               /* 135 ADC Unused/Reserved */
  pfn_handler_t pfnReserved4_Handler;               /* 136 ADC Unused/Reserved */
  pfn_handler_t pfnReserved5_Handler;               /* 137 ADC Unused/Reserved */
  pfn_handler_t pfnAC_Handler;                      /* 138 Analog Comparator Interrupt */
  pfn_handler_t pfnPTC_Handler;                     /* 139 Peripheral Touch Controller */
  pfn_handler_t pfnSPI_IXS_Handler;                 /* 140 Audio SPI Interrupt */
  pfn_handler_t pfnPCC_Handler;                     /* 141 PCC */
  pfn_handler_t pfnPDEC_Handler;                    /* 142 PDEC */
  pfn_handler_t pfnCAN0_Handler;                    /* 143 Controller Area Network 0 */
  pfn_handler_t pfnCAN1_Handler;                    /* 144 Controller Area Network 1 */
  pfn_handler_t pfnETH_Handler;                     /* 145 Ethernet MAC Interrupt */
  pfn_handler_t pfnSQI_Handler;                     /* 146 Quad SPI Interrupt */
  pfn_handler_t pfnTRNG_Handler;                    /* 147 True Random Generator */
  pfn_handler_t pfnSDMMC0_Handler;                  /* 148 SD/MMC Host Controller Interrupt 0 */
  pfn_handler_t pfnSDMMC1_Handler;                  /* 149 SD/MMC Host Controller Interrupt 1 */
  pfn_handler_t pfnUSB_OTHER_Handler;               /* 150 USB Other Interrupt */
  pfn_handler_t pfnUSB_SOF_Handler;                 /* 151 USB SOF Interrupt */
  pfn_handler_t pfnUSB_TRCPT0_Handler;              /* 152 USB TRCPT0 Interrupt */
  pfn_handler_t pfnUSB_TRCPT1_Handler;              /* 153 USB TRCPT1 Interrupt */
  pfn_handler_t pfnUSBHS_Handler;                   /* 154 High Speed USB Interrupt */
  pfn_handler_t pfnHSM_ERROR_Handler;               /* 155 Hardware Security Module Error Interrupt */
  pfn_handler_t pfnHSM_TXINT_Handler;               /* 156 Hardware Security Module Transmit Interrupt */
  pfn_handler_t pfnHSM_RXINT_Handler;               /* 157 Hardware Security Module Receive Interrupt */
}H3DeviceVectors;

#endif //DEVICE_VECTORS_H
