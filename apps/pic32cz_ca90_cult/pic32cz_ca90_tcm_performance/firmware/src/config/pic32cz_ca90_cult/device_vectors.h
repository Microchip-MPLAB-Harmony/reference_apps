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
typedef struct H3DeviceVectorsTag
{
  /* Stack pointer */
  uint32_t* pvStack;

  /* CORTEX-M7 handlers */ 
  pfn_handler_t pfnReset_Handler;                   /* -15 Reset Vector, invoked on Power up and warm reset */
  pfn_handler_t pfnNonMaskableInt_Handler;          /* -14 Non maskable Interrupt, cannot be stopped or preempted */
  pfn_handler_t pfnHardFault_Handler;               /* -13 Hard Fault, all classes of Fault */
  pfn_handler_t pfnMemoryManagement_Handler;        /* -12 Memory Management, MPU mismatch, including Access Violation and No Match */
  pfn_handler_t pfnBusFault_Handler;                /* -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
  pfn_handler_t pfnUsageFault_Handler;              /* -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition */
  pfn_handler_t pfnReservedC9;
  pfn_handler_t pfnReservedC8;
  pfn_handler_t pfnReservedC7;
  pfn_handler_t pfnReservedC6;
  pfn_handler_t pfnSVCall_Handler;                  /* -5 System Service Call via SVC instruction */
  pfn_handler_t pfnDebugMonitor_Handler;            /* -4 Debug Monitor */
  pfn_handler_t pfnReservedC3;
  pfn_handler_t pfnPendSV_Handler;                  /* -2 Pendable request for system service */
  pfn_handler_t pfnSysTick_Handler;                 /* -1 System Tick Timer */

  /* Peripheral handlers */
  pfn_handler_t pfnFCW_Handler;                     /* 0 Flash Write Controller Interrupt */
  pfn_handler_t pfnFCR_ECCERR_Handler;              /* 1 Flash Read Controller ECC Error */
  pfn_handler_t pfnFCR_CRC_FAULT_Handler;           /* 2 Flash Read Controller CRC Fault */
  pfn_handler_t pfnPM_Handler;                      /* 3 Power Manager */
  pfn_handler_t pfnSUPC_Handler;                    /* 4 Supply Controller */
  pfn_handler_t pfnOSCCTRL_FAIL_Handler;            /* 5 External Oscillator Fail */
  pfn_handler_t pfnOSCCTRL_XOSCRDY_Handler;         /* 6 External Oscillator Ready */
  pfn_handler_t pfnOSCCTRL_DFLLRDY_Handler;         /* 7 DFLL Ready */
  pfn_handler_t pfnOSCCTRL_OTHER_Handler;           /* 8 DFLL Other Interrupt */
  pfn_handler_t pfnOSCCTRL_LOCK_Handler;            /* 9 PLL Lock */
  pfn_handler_t pfnOSC32KCTRL_FAIL_Handler;         /* 10 32K Oscillator Fail */
  pfn_handler_t pfnOSC32KCTRL_RDY_Handler;          /* 11 32K Oscillator Ready */
  pfn_handler_t pfnMCLK_Handler;                    /* 12 Main Clock */
  pfn_handler_t pfnFREQM_Handler;                   /* 13 Frequency Meter */
  pfn_handler_t pfnWDT_Handler;                     /* 14 Watchdog Timer */
  pfn_handler_t pfnRTC_TAMPER_Handler;              /* 15 RTC Tamper */
  pfn_handler_t pfnRTC_OVF_Handler;                 /* 16 RTC Overflow */
  pfn_handler_t pfnRTC_PERIOD_Handler;              /* 17 RTC Period */
  pfn_handler_t pfnRTC_COMPARE_Handler;             /* 18 RTC Compare */
  pfn_handler_t pfnEIC_EXTINT_0_Handler;            /* 19 External Interrupt 0 */
  pfn_handler_t pfnEIC_EXTINT_1_Handler;            /* 20 External Interrupt 1 */
  pfn_handler_t pfnEIC_EXTINT_2_Handler;            /* 21 External Interrupt 2 */
  pfn_handler_t pfnEIC_EXTINT_3_Handler;            /* 22 External Interrupt 3 */
  pfn_handler_t pfnEIC_EXTINT_4_Handler;            /* 23 External Interrupt 4 */
  pfn_handler_t pfnEIC_EXTINT_5_Handler;            /* 24 External Interrupt 5 */
  pfn_handler_t pfnEIC_EXTINT_6_Handler;            /* 25 External Interrupt 6 */
  pfn_handler_t pfnEIC_EXTINT_7_Handler;            /* 26 External Interrupt 7 */
  pfn_handler_t pfnEIC_EXTINT_8_Handler;            /* 27 External Interrupt 8 */
  pfn_handler_t pfnEIC_EXTINT_9_Handler;            /* 28 External Interrupt 9 */
  pfn_handler_t pfnEIC_EXTINT_10_Handler;           /* 29 External Interrupt 10 */
  pfn_handler_t pfnEIC_EXTINT_11_Handler;           /* 30 External Interrupt 11 */
  pfn_handler_t pfnEIC_EXTINT_12_Handler;           /* 31 External Interrupt 12 */
  pfn_handler_t pfnEIC_EXTINT_13_Handler;           /* 32 External Interrupt 13 */
  pfn_handler_t pfnEIC_EXTINT_14_Handler;           /* 33 External Interrupt 14 */
  pfn_handler_t pfnEIC_EXTINT_15_Handler;           /* 34 External Interrupt 15 */
  pfn_handler_t pfnPAC_Handler;                     /* 35 Peripheral Access Controller */
  pfn_handler_t pfnDRMTCM_Handler;                  /* 36 TCM RAM ECC Interrupt */
  pfn_handler_t pfnMCRAMC_Handler;                  /* 37 Multi-Channel RAM Controller */
  pfn_handler_t pfnTRAM_Handler;                    /* 38 Trust RAM Interrupt */
  pfn_handler_t pfnDMA_PRI3_Handler;                /* 39 DMA Priority 3 Interrupt */
  pfn_handler_t pfnDMA_PRI2_Handler;                /* 40 DMA Priority 2 Interrupt */
  pfn_handler_t pfnDMA_PRI1_Handler;                /* 41 DMA Priority 1 Interrupt */
  pfn_handler_t pfnDMA_PRI0_Handler;                /* 42 DMA Priority 0 Interrupt */
  pfn_handler_t pfnEVSYS_0_Handler;                 /* 43 Event System  InterruptChannel 0 */
  pfn_handler_t pfnEVSYS_1_Handler;                 /* 44 Event System Channel 1 */
  pfn_handler_t pfnEVSYS_2_Handler;                 /* 45 Event System Channel 2 */
  pfn_handler_t pfnEVSYS_3_Handler;                 /* 46 Event System Channel 3 */
  pfn_handler_t pfnEVSYS_4_Handler;                 /* 47 Event System Channel 4 */
  pfn_handler_t pfnEVSYS_5_Handler;                 /* 48 Event System Channel 5 */
  pfn_handler_t pfnEVSYS_6_Handler;                 /* 49 Event System Channel 6 */
  pfn_handler_t pfnEVSYS_7_Handler;                 /* 50 Event System Channel 7 */
  pfn_handler_t pfnEVSYS_8_Handler;                 /* 51 Event System Channel 8 */
  pfn_handler_t pfnEVSYS_9_Handler;                 /* 52 Event System Channel 9 */
  pfn_handler_t pfnEVSYS_10_Handler;                /* 53 Event System Channel 10 */
  pfn_handler_t pfnEVSYS_11_Handler;                /* 54 Event System Channel 11 */
  pfn_handler_t pfnSERCOM0_6_Handler;               /* 55 USART/SPI/I2C Error */
  pfn_handler_t pfnSERCOM0_5_Handler;               /* 56 USART Receive Break */
  pfn_handler_t pfnSERCOM0_0_Handler;               /* 57 USART-SPI Data Register Empty/ I2C Stop Received */
  pfn_handler_t pfnSERCOM0_1_Handler;               /* 58 USART-SPI Transmit Complete/ I2C Address Match */
  pfn_handler_t pfnSERCOM0_2_Handler;               /* 59 USART-SPI Receive Complete/ I2C Data Ready */
  pfn_handler_t pfnSERCOM0_3_Handler;               /* 60 USART Receive Start/ SPI Slave Select Low/ I2C TX FIFO Empty */
  pfn_handler_t pfnSERCOM0_4_Handler;               /* 61 USART Clear To Send Input Change/ I2C RX FIFO Full */
  pfn_handler_t pfnSERCOM1_6_Handler;               /* 62 USART/SPI/I2C Error */
  pfn_handler_t pfnSERCOM1_5_Handler;               /* 63 USART Receive Break */
  pfn_handler_t pfnSERCOM1_0_Handler;               /* 64 USART-SPI Data Register Empty/ I2C Stop Received */
  pfn_handler_t pfnSERCOM1_1_Handler;               /* 65 USART-SPI Transmit Complete/ I2C Address Match */
  pfn_handler_t pfnSERCOM1_2_Handler;               /* 66 USART-SPI Receive Complete/ I2C Data Ready */
  pfn_handler_t pfnSERCOM1_3_Handler;               /* 67 USART Receive Start/ SPI Slave Select Low/ I2C TX FIFO Empty */
  pfn_handler_t pfnSERCOM1_4_Handler;               /* 68 USART Clear To Send Input Change/ I2C RX FIFO Full */
  pfn_handler_t pfnSERCOM2_6_Handler;               /* 69 USART/SPI/I2C Error */
  pfn_handler_t pfnSERCOM2_5_Handler;               /* 70 USART Receive Break */
  pfn_handler_t pfnSERCOM2_0_Handler;               /* 71 USART-SPI Data Register Empty/ I2C Stop Received */
  pfn_handler_t pfnSERCOM2_1_Handler;               /* 72 USART-SPI Transmit Complete/ I2C Address Match */
  pfn_handler_t pfnSERCOM2_2_Handler;               /* 73 USART-SPI Receive Complete/ I2C Data Ready */
  pfn_handler_t pfnSERCOM2_3_Handler;               /* 74 USART Receive Start/ SPI Slave Select Low/ I2C TX FIFO Empty */
  pfn_handler_t pfnSERCOM2_4_Handler;               /* 75 USART Clear To Send Input Change/ I2C RX FIFO Full */
  pfn_handler_t pfnSERCOM3_6_Handler;               /* 76 USART/SPI/I2C Error */
  pfn_handler_t pfnSERCOM3_5_Handler;               /* 77 USART Receive Break */
  pfn_handler_t pfnSERCOM3_0_Handler;               /* 78 USART-SPI Data Register Empty/ I2C Stop Received */
  pfn_handler_t pfnSERCOM3_1_Handler;               /* 79 USART-SPI Transmit Complete/ I2C Address Match */
  pfn_handler_t pfnSERCOM3_2_Handler;               /* 80 USART-SPI Receive Complete/ I2C Data Ready */
  pfn_handler_t pfnSERCOM3_3_Handler;               /* 81 USART Receive Start/ SPI Slave Select Low/ I2C TX FIFO Empty */
  pfn_handler_t pfnSERCOM3_4_Handler;               /* 82 USART Clear To Send Input Change/ I2C RX FIFO Full */
  pfn_handler_t pfnSERCOM4_6_Handler;               /* 83 USART/SPI/I2C Error */
  pfn_handler_t pfnSERCOM4_5_Handler;               /* 84 USART Receive Break */
  pfn_handler_t pfnSERCOM4_0_Handler;               /* 85 USART-SPI Data Register Empty/ I2C Stop Received */
  pfn_handler_t pfnSERCOM4_1_Handler;               /* 86 USART-SPI Transmit Complete/ I2C Address Match */
  pfn_handler_t pfnSERCOM4_2_Handler;               /* 87 USART-SPI Receive Complete/ I2C Data Ready */
  pfn_handler_t pfnSERCOM4_3_Handler;               /* 88 USART Receive Start/ SPI Slave Select Low/ I2C TX FIFO Empty */
  pfn_handler_t pfnSERCOM4_4_Handler;               /* 89 USART Clear To Send Input Change/ I2C RX FIFO Full */
  pfn_handler_t pfnSERCOM5_6_Handler;               /* 90 USART/SPI/I2C Error */
  pfn_handler_t pfnSERCOM5_5_Handler;               /* 91 USART Receive Break */
  pfn_handler_t pfnSERCOM5_0_Handler;               /* 92 USART-SPI Data Register Empty/ I2C Stop Received */
  pfn_handler_t pfnSERCOM5_1_Handler;               /* 93 USART-SPI Transmit Complete/ I2C Address Match */
  pfn_handler_t pfnSERCOM5_2_Handler;               /* 94 USART-SPI Receive Complete/ I2C Data Ready */
  pfn_handler_t pfnSERCOM5_3_Handler;               /* 95 USART Receive Start/ SPI Slave Select Low/ I2C TX FIFO Empty */
  pfn_handler_t pfnSERCOM5_4_Handler;               /* 96 USART Clear To Send Input Change/ I2C RX FIFO Full */
  pfn_handler_t pfnSERCOM6_6_Handler;               /* 97 USART/SPI/I2C Error */
  pfn_handler_t pfnSERCOM6_5_Handler;               /* 98 USART Receive Break */
  pfn_handler_t pfnSERCOM6_0_Handler;               /* 99 USART-SPI Data Register Empty/ I2C Stop Received */
  pfn_handler_t pfnSERCOM6_1_Handler;               /* 100 USART-SPI Transmit Complete/ I2C Address Match */
  pfn_handler_t pfnSERCOM6_2_Handler;               /* 101 USART-SPI Receive Complete/ I2C Data Ready */
  pfn_handler_t pfnSERCOM6_3_Handler;               /* 102 USART Receive Start/ SPI Slave Select Low/ I2C TX FIFO Empty */
  pfn_handler_t pfnSERCOM6_4_Handler;               /* 103 USART Clear To Send Input Change/ I2C RX FIFO Full */
  pfn_handler_t pfnSERCOM7_6_Handler;               /* 104 USART/SPI/I2C Error */
  pfn_handler_t pfnSERCOM7_5_Handler;               /* 105 USART Receive Break */
  pfn_handler_t pfnSERCOM7_0_Handler;               /* 106 USART-SPI Data Register Empty/ I2C Stop Received */
  pfn_handler_t pfnSERCOM7_1_Handler;               /* 107 USART-SPI Transmit Complete/ I2C Address Match */
  pfn_handler_t pfnSERCOM7_2_Handler;               /* 108 USART-SPI Receive Complete/ I2C Data Ready */
  pfn_handler_t pfnSERCOM7_3_Handler;               /* 109 USART Receive Start/ SPI Slave Select Low/ I2C TX FIFO Empty */
  pfn_handler_t pfnSERCOM7_4_Handler;               /* 110 USART Clear To Send Input Change/ I2C RX FIFO Full */
  pfn_handler_t pfnSERCOM8_6_Handler;               /* 111 USART/SPI/I2C Error */
  pfn_handler_t pfnSERCOM8_5_Handler;               /* 112 USART Receive Break */
  pfn_handler_t pfnSERCOM8_0_Handler;               /* 113 USART-SPI Data Register Empty/ I2C Stop Received */
  pfn_handler_t pfnSERCOM8_1_Handler;               /* 114 USART-SPI Transmit Complete/ I2C Address Match */
  pfn_handler_t pfnSERCOM8_2_Handler;               /* 115 USART-SPI Receive Complete/ I2C Data Ready */
  pfn_handler_t pfnSERCOM8_3_Handler;               /* 116 USART Receive Start/ SPI Slave Select Low/ I2C TX FIFO Empty */
  pfn_handler_t pfnSERCOM8_4_Handler;               /* 117 USART Clear To Send Input Change/ I2C RX FIFO Full */
  pfn_handler_t pfnSERCOM9_6_Handler;               /* 118 USART/SPI/I2C Error */
  pfn_handler_t pfnSERCOM9_5_Handler;               /* 119 USART Receive Break */
  pfn_handler_t pfnSERCOM9_0_Handler;               /* 120 USART-SPI Data Register Empty/ I2C Stop Received */
  pfn_handler_t pfnSERCOM9_1_Handler;               /* 121 USART-SPI Transmit Complete/ I2C Address Match */
  pfn_handler_t pfnSERCOM9_2_Handler;               /* 122 USART-SPI Receive Complete/ I2C Data Ready */
  pfn_handler_t pfnSERCOM9_3_Handler;               /* 123 USART Receive Start/ SPI Slave Select Low/ I2C TX FIFO Empty */
  pfn_handler_t pfnSERCOM9_4_Handler;               /* 124 USART Clear To Send Input Change/ I2C RX FIFO Full */
  pfn_handler_t pfnTCC0_OTHER_Handler;              /* 125 Error/Overflow/Underflow/Fault Interrupt */
  pfn_handler_t pfnTCC0_CNT_TRIG_Handler;           /* 126 Counter/Re-Trigger Interrupt */
  pfn_handler_t pfnTCC0_MC0_Handler;                /* 127 TCC Match/Compare 0 */
  pfn_handler_t pfnTCC0_MC1_Handler;                /* 128 TCC Match/Compare 1 */
  pfn_handler_t pfnTCC0_MC2_Handler;                /* 129 TCC Match/Compare 2 */
  pfn_handler_t pfnTCC0_MC3_Handler;                /* 130 TCC Match/Compare 3 */
  pfn_handler_t pfnTCC0_MC4_Handler;                /* 131 TCC Match/Compare 4 */
  pfn_handler_t pfnTCC0_MC5_Handler;                /* 132 TCC Match/Compare 5 */
  pfn_handler_t pfnTCC0_MC6_Handler;                /* 133 TCC Match/Compare 6 */
  pfn_handler_t pfnTCC0_MC7_Handler;                /* 134 TCC Match/Compare 7 */
  pfn_handler_t pfnTCC1_OTHER_Handler;              /* 135 Error/Overflow/Underflow/Fault Interrupt */
  pfn_handler_t pfnTCC1_CNT_TRIG_Handler;           /* 136 Counter/Re-Trigger Interrupt */
  pfn_handler_t pfnTCC1_MC0_Handler;                /* 137 TCC Match/Compare 0 */
  pfn_handler_t pfnTCC1_MC1_Handler;                /* 138 TCC Match/Compare 1 */
  pfn_handler_t pfnTCC1_MC2_Handler;                /* 139 TCC Match/Compare 2 */
  pfn_handler_t pfnTCC1_MC3_Handler;                /* 140 TCC Match/Compare 3 */
  pfn_handler_t pfnTCC1_MC4_Handler;                /* 141 TCC Match/Compare 4 */
  pfn_handler_t pfnTCC1_MC5_Handler;                /* 142 TCC Match/Compare 5 */
  pfn_handler_t pfnTCC1_MC6_Handler;                /* 143 TCC Match/Compare 6 */
  pfn_handler_t pfnTCC1_MC7_Handler;                /* 144 TCC Match/Compare 7 */
  pfn_handler_t pfnTCC2_OTHER_Handler;              /* 145 Error/Overflow/Underflow/Fault Interrupt */
  pfn_handler_t pfnTCC2_CNT_TRIG_Handler;           /* 146 Counter/Re-Trigger Interrupt */
  pfn_handler_t pfnTCC2_MC0_Handler;                /* 147 TCC Match/Compare 0 */
  pfn_handler_t pfnTCC2_MC1_Handler;                /* 148 TCC Match/Compare 1 */
  pfn_handler_t pfnTCC2_MC2_Handler;                /* 149 TCC Match/Compare 2 */
  pfn_handler_t pfnTCC2_MC3_Handler;                /* 150 TCC Match/Compare 3 */
  pfn_handler_t pfnTCC2_MC4_Handler;                /* 151 TCC Match/Compare 4 */
  pfn_handler_t pfnTCC2_MC5_Handler;                /* 152 TCC Match/Compare 5 */
  pfn_handler_t pfnTCC3_OTHER_Handler;              /* 153 Error/Overflow/Underflow/Fault Interrupt */
  pfn_handler_t pfnTCC3_CNT_TRIG_Handler;           /* 154 Counter/Re-Trigger Interrupt */
  pfn_handler_t pfnTCC3_MC0_Handler;                /* 155 TCC Match/Compare 0 */
  pfn_handler_t pfnTCC3_MC1_Handler;                /* 156 TCC Match/Compare 1 */
  pfn_handler_t pfnTCC4_OTHER_Handler;              /* 157 Error/Overflow/Underflow/Fault Interrupt */
  pfn_handler_t pfnTCC4_CNT_TRIG_Handler;           /* 158 Counter/Re-Trigger Interrupt */
  pfn_handler_t pfnTCC4_MC0_Handler;                /* 159 TCC Match/Compare 0 */
  pfn_handler_t pfnTCC4_MC1_Handler;                /* 160 TCC Match/Compare 1 */
  pfn_handler_t pfnTCC5_OTHER_Handler;              /* 161 Error/Overflow/Underflow/Fault Interrupt */
  pfn_handler_t pfnTCC5_CNT_TRIG_Handler;           /* 162 Counter/Re-Trigger Interrupt */
  pfn_handler_t pfnTCC5_MC0_Handler;                /* 163 TCC Match/Compare 0 */
  pfn_handler_t pfnTCC5_MC1_Handler;                /* 164 TCC Match/Compare 1 */
  pfn_handler_t pfnTCC6_OTHER_Handler;              /* 165 Error/Overflow/Underflow/Fault Interrupt */
  pfn_handler_t pfnTCC6_CNT_TRIG_Handler;           /* 166 Counter/Re-Trigger Interrupt */
  pfn_handler_t pfnTCC6_MC0_Handler;                /* 167 TCC Match/Compare 0 */
  pfn_handler_t pfnTCC6_MC1_Handler;                /* 168 TCC Match/Compare 1 */
  pfn_handler_t pfnTCC7_OTHER_Handler;              /* 169 Error/Overflow/Underflow/Fault Interrupt */
  pfn_handler_t pfnTCC7_CNT_TRIG_Handler;           /* 170 Counter/Re-Trigger Interrupt */
  pfn_handler_t pfnTCC7_MC0_Handler;                /* 171 TCC Match/Compare 0 */
  pfn_handler_t pfnTCC7_MC1_Handler;                /* 172 TCC Match/Compare 1 */
  pfn_handler_t pfnTCC8_OTHER_Handler;              /* 173 Error/Overflow/Underflow/Fault Interrupt */
  pfn_handler_t pfnTCC8_CNT_TRIG_Handler;           /* 174 Counter/Re-Trigger Interrupt */
  pfn_handler_t pfnTCC8_MC0_Handler;                /* 175 TCC Match/Compare 0 */
  pfn_handler_t pfnTCC8_MC1_Handler;                /* 176 TCC Match/Compare 1 */
  pfn_handler_t pfnTCC9_OTHER_Handler;              /* 177 Error/Overflow/Underflow/Fault Interrupt */
  pfn_handler_t pfnTCC9_CNT_TRIG_Handler;           /* 178 Counter/Re-Trigger Interrupt */
  pfn_handler_t pfnTCC9_MC0_Handler;                /* 179 TCC Match/Compare 0 */
  pfn_handler_t pfnTCC9_MC1_Handler;                /* 180 TCC Match/Compare 1 */
  pfn_handler_t pfnTCC9_MC2_Handler;                /* 181 TCC Match/Compare 2 */
  pfn_handler_t pfnTCC9_MC3_Handler;                /* 182 TCC Match/Compare 3 */
  pfn_handler_t pfnTCC9_MC4_Handler;                /* 183 TCC Match/Compare 4 */
  pfn_handler_t pfnTCC9_MC5_Handler;                /* 184 TCC Match/Compare 5 */
  pfn_handler_t pfnADC_GLOBAL_Handler;              /* 185 ADC Global Interrupt */
  pfn_handler_t pfnADC_CORE1_Handler;               /* 186 ADC Core 1 Interrupt */
  pfn_handler_t pfnADC_CORE2_Handler;               /* 187 ADC Core 2 Interrupt */
  pfn_handler_t pfnADC_CORE3_Handler;               /* 188 ADC Core 3 Interrupt */
  pfn_handler_t pfnADC_CORE4_Handler;               /* 189 ADC Core 4 Interrupt */
  pfn_handler_t pfnAC_Handler;                      /* 190 Analog Comparator Interrupt */
  pfn_handler_t pfnPTC_Handler;                     /* 191 Peripheral Touch Controller */
  pfn_handler_t pfnSPI_IXS0_Handler;                /* 192 Audio SPI Interrupt 0 */
  pfn_handler_t pfnSPI_IXS1_Handler;                /* 193 Audio SPI Interrupt 1 */
  pfn_handler_t pfnCAN0_Handler;                    /* 194 Controller Area Network 0 */
  pfn_handler_t pfnCAN1_Handler;                    /* 195 Controller Area Network 1 */
  pfn_handler_t pfnCAN2_Handler;                    /* 196 Controller Area Network 2 */
  pfn_handler_t pfnCAN3_Handler;                    /* 197 Controller Area Network 3 */
  pfn_handler_t pfnCAN4_Handler;                    /* 198 Controller Area Network 4 */
  pfn_handler_t pfnCAN5_Handler;                    /* 199 Controller Area Network 5 */
  pfn_handler_t pfnReserved200;
  pfn_handler_t pfnReserved201;
  pfn_handler_t pfnETH_PRI_Q_0_Handler;             /* 202 Ethernet MAC Interrupt */
  pfn_handler_t pfnETH_PRI_Q_1_Handler;             /* 203 Ethernet MAC Queue 1 Interrupt */
  pfn_handler_t pfnETH_PRI_Q_2_Handler;             /* 204 Ethernet MAC Queue 2 Interrupt */
  pfn_handler_t pfnETH_PRI_Q_3_Handler;             /* 205 Ethernet MAC Queue 3 Interrupt */
  pfn_handler_t pfnETH_PRI_Q_4_Handler;             /* 206 Ethernet MAC Queue 4 Interrupt */
  pfn_handler_t pfnETH_PRI_Q_5_Handler;             /* 207 Ethernet MAC Queue 5 Interrupt */
  pfn_handler_t pfnSQI0_Handler;                    /* 208 Quad SPI Interrupt 0 */
  pfn_handler_t pfnSQI1_Handler;                    /* 209 Quad SPI Interrupt 1 */
  pfn_handler_t pfnTRNG_Handler;                    /* 210 True Random Generator */
  pfn_handler_t pfnSDMMC0_Handler;                  /* 211 SD/MMC Host Controller Interrupt 0 */
  pfn_handler_t pfnSDMMC1_Handler;                  /* 212 SD/MMC Host Controller Interrupt 1 */
  pfn_handler_t pfnUSBHS0_Handler;                  /* 213 High Speed USB Interrupt 0 */
  pfn_handler_t pfnUSBHS1_Handler;                  /* 214 High Speed USB Interrupt 1 */
  pfn_handler_t pfnHSM_TAMPER_Handler;              /* 215 Hardware Security Module Tamper Interrupt */
  pfn_handler_t pfnHSM_TXINT_Handler;               /* 216 Hardware Security Module Transmit Interrupt */
  pfn_handler_t pfnHSM_RXINT_Handler;               /* 217 Hardware Security Module Receive Interrupt */
  pfn_handler_t pfnMLB_GENERAL_Handler;             /* 218 Media Local Bus General Interrupt */
  pfn_handler_t pfnMLB_BUSREQ_Handler;              /* 219 Media Local Bus Request Interrupt */
  pfn_handler_t pfnCM7H_CTIIRQ_0_Handler;           /* 220 Cross Trigger Interface Interrupt 0 */
  pfn_handler_t pfnCM7H_CTIIRQ_1_Handler;           /* 221 Cross Trigger Interface Interrupt 1 */
}H3DeviceVectors;

#endif //DEVICE_VECTORS_H
