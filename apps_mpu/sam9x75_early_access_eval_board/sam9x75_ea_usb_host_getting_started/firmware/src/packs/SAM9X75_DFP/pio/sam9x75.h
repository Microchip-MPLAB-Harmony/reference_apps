/*
 * Peripheral I/O description for SAM9X75
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

/* file generated from device description version 2023-01-20T08:33:39Z */
#ifndef _SAM9X75_GPIO_H_
#define _SAM9X75_GPIO_H_

/* ========== Peripheral I/O pin numbers ========== */
#define PIN_PA0                     (    0)  /**< Pin Number for PA0 */
#define PIN_PA1                     (    1)  /**< Pin Number for PA1 */
#define PIN_PA2                     (    2)  /**< Pin Number for PA2 */
#define PIN_PA3                     (    3)  /**< Pin Number for PA3 */
#define PIN_PA4                     (    4)  /**< Pin Number for PA4 */
#define PIN_PA5                     (    5)  /**< Pin Number for PA5 */
#define PIN_PA6                     (    6)  /**< Pin Number for PA6 */
#define PIN_PA7                     (    7)  /**< Pin Number for PA7 */
#define PIN_PA8                     (    8)  /**< Pin Number for PA8 */
#define PIN_PA9                     (    9)  /**< Pin Number for PA9 */
#define PIN_PA10                    (   10)  /**< Pin Number for PA10 */
#define PIN_PA11                    (   11)  /**< Pin Number for PA11 */
#define PIN_PA12                    (   12)  /**< Pin Number for PA12 */
#define PIN_PA13                    (   13)  /**< Pin Number for PA13 */
#define PIN_PA14                    (   14)  /**< Pin Number for PA14 */
#define PIN_PA15                    (   15)  /**< Pin Number for PA15 */
#define PIN_PA16                    (   16)  /**< Pin Number for PA16 */
#define PIN_PA17                    (   17)  /**< Pin Number for PA17 */
#define PIN_PA18                    (   18)  /**< Pin Number for PA18 */
#define PIN_PA19                    (   19)  /**< Pin Number for PA19 */
#define PIN_PA20                    (   20)  /**< Pin Number for PA20 */
#define PIN_PA21                    (   21)  /**< Pin Number for PA21 */
#define PIN_PA22                    (   22)  /**< Pin Number for PA22 */
#define PIN_PA23                    (   23)  /**< Pin Number for PA23 */
#define PIN_PA24                    (   24)  /**< Pin Number for PA24 */
#define PIN_PA25                    (   25)  /**< Pin Number for PA25 */
#define PIN_PA26                    (   26)  /**< Pin Number for PA26 */
#define PIN_PA27                    (   27)  /**< Pin Number for PA27 */
#define PIN_PA28                    (   28)  /**< Pin Number for PA28 */
#define PIN_PA29                    (   29)  /**< Pin Number for PA29 */
#define PIN_PA30                    (   30)  /**< Pin Number for PA30 */
#define PIN_PA31                    (   31)  /**< Pin Number for PA31 */
#define PIN_PB0                     (   32)  /**< Pin Number for PB0 */
#define PIN_PB1                     (   33)  /**< Pin Number for PB1 */
#define PIN_PB2                     (   34)  /**< Pin Number for PB2 */
#define PIN_PB3                     (   35)  /**< Pin Number for PB3 */
#define PIN_PB4                     (   36)  /**< Pin Number for PB4 */
#define PIN_PB5                     (   37)  /**< Pin Number for PB5 */
#define PIN_PB6                     (   38)  /**< Pin Number for PB6 */
#define PIN_PB7                     (   39)  /**< Pin Number for PB7 */
#define PIN_PB8                     (   40)  /**< Pin Number for PB8 */
#define PIN_PB9                     (   41)  /**< Pin Number for PB9 */
#define PIN_PB10                    (   42)  /**< Pin Number for PB10 */
#define PIN_PB11                    (   43)  /**< Pin Number for PB11 */
#define PIN_PB12                    (   44)  /**< Pin Number for PB12 */
#define PIN_PB13                    (   45)  /**< Pin Number for PB13 */
#define PIN_PB14                    (   46)  /**< Pin Number for PB14 */
#define PIN_PB15                    (   47)  /**< Pin Number for PB15 */
#define PIN_PB16                    (   48)  /**< Pin Number for PB16 */
#define PIN_PB17                    (   49)  /**< Pin Number for PB17 */
#define PIN_PB18                    (   50)  /**< Pin Number for PB18 */
#define PIN_PB19                    (   51)  /**< Pin Number for PB19 */
#define PIN_PB20                    (   52)  /**< Pin Number for PB20 */
#define PIN_PB21                    (   53)  /**< Pin Number for PB21 */
#define PIN_PB22                    (   54)  /**< Pin Number for PB22 */
#define PIN_PB23                    (   55)  /**< Pin Number for PB23 */
#define PIN_PB24                    (   56)  /**< Pin Number for PB24 */
#define PIN_PB25                    (   57)  /**< Pin Number for PB25 */
#define PIN_PB26                    (   58)  /**< Pin Number for PB26 */
#define PIN_PC0                     (   64)  /**< Pin Number for PC0 */
#define PIN_PC1                     (   65)  /**< Pin Number for PC1 */
#define PIN_PC2                     (   66)  /**< Pin Number for PC2 */
#define PIN_PC3                     (   67)  /**< Pin Number for PC3 */
#define PIN_PC4                     (   68)  /**< Pin Number for PC4 */
#define PIN_PC5                     (   69)  /**< Pin Number for PC5 */
#define PIN_PC6                     (   70)  /**< Pin Number for PC6 */
#define PIN_PC7                     (   71)  /**< Pin Number for PC7 */
#define PIN_PC8                     (   72)  /**< Pin Number for PC8 */
#define PIN_PC9                     (   73)  /**< Pin Number for PC9 */
#define PIN_PC10                    (   74)  /**< Pin Number for PC10 */
#define PIN_PC11                    (   75)  /**< Pin Number for PC11 */
#define PIN_PC12                    (   76)  /**< Pin Number for PC12 */
#define PIN_PC13                    (   77)  /**< Pin Number for PC13 */
#define PIN_PC14                    (   78)  /**< Pin Number for PC14 */
#define PIN_PC15                    (   79)  /**< Pin Number for PC15 */
#define PIN_PC16                    (   80)  /**< Pin Number for PC16 */
#define PIN_PC17                    (   81)  /**< Pin Number for PC17 */
#define PIN_PC18                    (   82)  /**< Pin Number for PC18 */
#define PIN_PC19                    (   83)  /**< Pin Number for PC19 */
#define PIN_PC20                    (   84)  /**< Pin Number for PC20 */
#define PIN_PC21                    (   85)  /**< Pin Number for PC21 */
#define PIN_PC22                    (   86)  /**< Pin Number for PC22 */
#define PIN_PC23                    (   87)  /**< Pin Number for PC23 */
#define PIN_PC24                    (   88)  /**< Pin Number for PC24 */
#define PIN_PC25                    (   89)  /**< Pin Number for PC25 */
#define PIN_PC26                    (   90)  /**< Pin Number for PC26 */
#define PIN_PC27                    (   91)  /**< Pin Number for PC27 */
#define PIN_PC28                    (   92)  /**< Pin Number for PC28 */
#define PIN_PC29                    (   93)  /**< Pin Number for PC29 */
#define PIN_PC30                    (   94)  /**< Pin Number for PC30 */
#define PIN_PC31                    (   95)  /**< Pin Number for PC31 */
#define PIN_PD0                     (   96)  /**< Pin Number for PD0 */
#define PIN_PD1                     (   97)  /**< Pin Number for PD1 */
#define PIN_PD2                     (   98)  /**< Pin Number for PD2 */
#define PIN_PD3                     (   99)  /**< Pin Number for PD3 */
#define PIN_PD4                     (  100)  /**< Pin Number for PD4 */
#define PIN_PD5                     (  101)  /**< Pin Number for PD5 */
#define PIN_PD6                     (  102)  /**< Pin Number for PD6 */
#define PIN_PD7                     (  103)  /**< Pin Number for PD7 */
#define PIN_PD8                     (  104)  /**< Pin Number for PD8 */
#define PIN_PD9                     (  105)  /**< Pin Number for PD9 */
#define PIN_PD10                    (  106)  /**< Pin Number for PD10 */
#define PIN_PD11                    (  107)  /**< Pin Number for PD11 */
#define PIN_PD12                    (  108)  /**< Pin Number for PD12 */
#define PIN_PD13                    (  109)  /**< Pin Number for PD13 */
#define PIN_PD14                    (  110)  /**< Pin Number for PD14 */

/* ========== Peripheral I/O masks ========== */
#define PIO_PA0                     (_UINT32_(1) << 0) /**< PIO mask for PA0 */
#define PIO_PA1                     (_UINT32_(1) << 1) /**< PIO mask for PA1 */
#define PIO_PA2                     (_UINT32_(1) << 2) /**< PIO mask for PA2 */
#define PIO_PA3                     (_UINT32_(1) << 3) /**< PIO mask for PA3 */
#define PIO_PA4                     (_UINT32_(1) << 4) /**< PIO mask for PA4 */
#define PIO_PA5                     (_UINT32_(1) << 5) /**< PIO mask for PA5 */
#define PIO_PA6                     (_UINT32_(1) << 6) /**< PIO mask for PA6 */
#define PIO_PA7                     (_UINT32_(1) << 7) /**< PIO mask for PA7 */
#define PIO_PA8                     (_UINT32_(1) << 8) /**< PIO mask for PA8 */
#define PIO_PA9                     (_UINT32_(1) << 9) /**< PIO mask for PA9 */
#define PIO_PA10                    (_UINT32_(1) << 10) /**< PIO mask for PA10 */
#define PIO_PA11                    (_UINT32_(1) << 11) /**< PIO mask for PA11 */
#define PIO_PA12                    (_UINT32_(1) << 12) /**< PIO mask for PA12 */
#define PIO_PA13                    (_UINT32_(1) << 13) /**< PIO mask for PA13 */
#define PIO_PA14                    (_UINT32_(1) << 14) /**< PIO mask for PA14 */
#define PIO_PA15                    (_UINT32_(1) << 15) /**< PIO mask for PA15 */
#define PIO_PA16                    (_UINT32_(1) << 16) /**< PIO mask for PA16 */
#define PIO_PA17                    (_UINT32_(1) << 17) /**< PIO mask for PA17 */
#define PIO_PA18                    (_UINT32_(1) << 18) /**< PIO mask for PA18 */
#define PIO_PA19                    (_UINT32_(1) << 19) /**< PIO mask for PA19 */
#define PIO_PA20                    (_UINT32_(1) << 20) /**< PIO mask for PA20 */
#define PIO_PA21                    (_UINT32_(1) << 21) /**< PIO mask for PA21 */
#define PIO_PA22                    (_UINT32_(1) << 22) /**< PIO mask for PA22 */
#define PIO_PA23                    (_UINT32_(1) << 23) /**< PIO mask for PA23 */
#define PIO_PA24                    (_UINT32_(1) << 24) /**< PIO mask for PA24 */
#define PIO_PA25                    (_UINT32_(1) << 25) /**< PIO mask for PA25 */
#define PIO_PA26                    (_UINT32_(1) << 26) /**< PIO mask for PA26 */
#define PIO_PA27                    (_UINT32_(1) << 27) /**< PIO mask for PA27 */
#define PIO_PA28                    (_UINT32_(1) << 28) /**< PIO mask for PA28 */
#define PIO_PA29                    (_UINT32_(1) << 29) /**< PIO mask for PA29 */
#define PIO_PA30                    (_UINT32_(1) << 30) /**< PIO mask for PA30 */
#define PIO_PA31                    (_UINT32_(1) << 31) /**< PIO mask for PA31 */
#define PIO_PB0                     (_UINT32_(1) << 0) /**< PIO mask for PB0 */
#define PIO_PB1                     (_UINT32_(1) << 1) /**< PIO mask for PB1 */
#define PIO_PB2                     (_UINT32_(1) << 2) /**< PIO mask for PB2 */
#define PIO_PB3                     (_UINT32_(1) << 3) /**< PIO mask for PB3 */
#define PIO_PB4                     (_UINT32_(1) << 4) /**< PIO mask for PB4 */
#define PIO_PB5                     (_UINT32_(1) << 5) /**< PIO mask for PB5 */
#define PIO_PB6                     (_UINT32_(1) << 6) /**< PIO mask for PB6 */
#define PIO_PB7                     (_UINT32_(1) << 7) /**< PIO mask for PB7 */
#define PIO_PB8                     (_UINT32_(1) << 8) /**< PIO mask for PB8 */
#define PIO_PB9                     (_UINT32_(1) << 9) /**< PIO mask for PB9 */
#define PIO_PB10                    (_UINT32_(1) << 10) /**< PIO mask for PB10 */
#define PIO_PB11                    (_UINT32_(1) << 11) /**< PIO mask for PB11 */
#define PIO_PB12                    (_UINT32_(1) << 12) /**< PIO mask for PB12 */
#define PIO_PB13                    (_UINT32_(1) << 13) /**< PIO mask for PB13 */
#define PIO_PB14                    (_UINT32_(1) << 14) /**< PIO mask for PB14 */
#define PIO_PB15                    (_UINT32_(1) << 15) /**< PIO mask for PB15 */
#define PIO_PB16                    (_UINT32_(1) << 16) /**< PIO mask for PB16 */
#define PIO_PB17                    (_UINT32_(1) << 17) /**< PIO mask for PB17 */
#define PIO_PB18                    (_UINT32_(1) << 18) /**< PIO mask for PB18 */
#define PIO_PB19                    (_UINT32_(1) << 19) /**< PIO mask for PB19 */
#define PIO_PB20                    (_UINT32_(1) << 20) /**< PIO mask for PB20 */
#define PIO_PB21                    (_UINT32_(1) << 21) /**< PIO mask for PB21 */
#define PIO_PB22                    (_UINT32_(1) << 22) /**< PIO mask for PB22 */
#define PIO_PB23                    (_UINT32_(1) << 23) /**< PIO mask for PB23 */
#define PIO_PB24                    (_UINT32_(1) << 24) /**< PIO mask for PB24 */
#define PIO_PB25                    (_UINT32_(1) << 25) /**< PIO mask for PB25 */
#define PIO_PB26                    (_UINT32_(1) << 26) /**< PIO mask for PB26 */
#define PIO_PC0                     (_UINT32_(1) << 0) /**< PIO mask for PC0 */
#define PIO_PC1                     (_UINT32_(1) << 1) /**< PIO mask for PC1 */
#define PIO_PC2                     (_UINT32_(1) << 2) /**< PIO mask for PC2 */
#define PIO_PC3                     (_UINT32_(1) << 3) /**< PIO mask for PC3 */
#define PIO_PC4                     (_UINT32_(1) << 4) /**< PIO mask for PC4 */
#define PIO_PC5                     (_UINT32_(1) << 5) /**< PIO mask for PC5 */
#define PIO_PC6                     (_UINT32_(1) << 6) /**< PIO mask for PC6 */
#define PIO_PC7                     (_UINT32_(1) << 7) /**< PIO mask for PC7 */
#define PIO_PC8                     (_UINT32_(1) << 8) /**< PIO mask for PC8 */
#define PIO_PC9                     (_UINT32_(1) << 9) /**< PIO mask for PC9 */
#define PIO_PC10                    (_UINT32_(1) << 10) /**< PIO mask for PC10 */
#define PIO_PC11                    (_UINT32_(1) << 11) /**< PIO mask for PC11 */
#define PIO_PC12                    (_UINT32_(1) << 12) /**< PIO mask for PC12 */
#define PIO_PC13                    (_UINT32_(1) << 13) /**< PIO mask for PC13 */
#define PIO_PC14                    (_UINT32_(1) << 14) /**< PIO mask for PC14 */
#define PIO_PC15                    (_UINT32_(1) << 15) /**< PIO mask for PC15 */
#define PIO_PC16                    (_UINT32_(1) << 16) /**< PIO mask for PC16 */
#define PIO_PC17                    (_UINT32_(1) << 17) /**< PIO mask for PC17 */
#define PIO_PC18                    (_UINT32_(1) << 18) /**< PIO mask for PC18 */
#define PIO_PC19                    (_UINT32_(1) << 19) /**< PIO mask for PC19 */
#define PIO_PC20                    (_UINT32_(1) << 20) /**< PIO mask for PC20 */
#define PIO_PC21                    (_UINT32_(1) << 21) /**< PIO mask for PC21 */
#define PIO_PC22                    (_UINT32_(1) << 22) /**< PIO mask for PC22 */
#define PIO_PC23                    (_UINT32_(1) << 23) /**< PIO mask for PC23 */
#define PIO_PC24                    (_UINT32_(1) << 24) /**< PIO mask for PC24 */
#define PIO_PC25                    (_UINT32_(1) << 25) /**< PIO mask for PC25 */
#define PIO_PC26                    (_UINT32_(1) << 26) /**< PIO mask for PC26 */
#define PIO_PC27                    (_UINT32_(1) << 27) /**< PIO mask for PC27 */
#define PIO_PC28                    (_UINT32_(1) << 28) /**< PIO mask for PC28 */
#define PIO_PC29                    (_UINT32_(1) << 29) /**< PIO mask for PC29 */
#define PIO_PC30                    (_UINT32_(1) << 30) /**< PIO mask for PC30 */
#define PIO_PC31                    (_UINT32_(1) << 31) /**< PIO mask for PC31 */
#define PIO_PD0                     (_UINT32_(1) << 0) /**< PIO mask for PD0 */
#define PIO_PD1                     (_UINT32_(1) << 1) /**< PIO mask for PD1 */
#define PIO_PD2                     (_UINT32_(1) << 2) /**< PIO mask for PD2 */
#define PIO_PD3                     (_UINT32_(1) << 3) /**< PIO mask for PD3 */
#define PIO_PD4                     (_UINT32_(1) << 4) /**< PIO mask for PD4 */
#define PIO_PD5                     (_UINT32_(1) << 5) /**< PIO mask for PD5 */
#define PIO_PD6                     (_UINT32_(1) << 6) /**< PIO mask for PD6 */
#define PIO_PD7                     (_UINT32_(1) << 7) /**< PIO mask for PD7 */
#define PIO_PD8                     (_UINT32_(1) << 8) /**< PIO mask for PD8 */
#define PIO_PD9                     (_UINT32_(1) << 9) /**< PIO mask for PD9 */
#define PIO_PD10                    (_UINT32_(1) << 10) /**< PIO mask for PD10 */
#define PIO_PD11                    (_UINT32_(1) << 11) /**< PIO mask for PD11 */
#define PIO_PD12                    (_UINT32_(1) << 12) /**< PIO mask for PD12 */
#define PIO_PD13                    (_UINT32_(1) << 13) /**< PIO mask for PD13 */
#define PIO_PD14                    (_UINT32_(1) << 14) /**< PIO mask for PD14 */

/* ========== PIO definition for ADC peripheral ========== */
#define PIN_PA24X1_ADC_AD0                         _UINT32_(24) /**< ADC signal: ADC_AD0 on PA24 mux X1 */
#define PIO_PA24X1_ADC_AD0                         (_UINT32_(1) << 24) /**< ADC signal: ADC_AD0 */
#define PIN_PA25X1_ADC_AD1                         _UINT32_(25) /**< ADC signal: ADC_AD1 on PA25 mux X1 */
#define PIO_PA25X1_ADC_AD1                         (_UINT32_(1) << 25) /**< ADC signal: ADC_AD1 */
#define PIN_PA26X1_ADC_AD2                         _UINT32_(26) /**< ADC signal: ADC_AD2 on PA26 mux X1 */
#define PIO_PA26X1_ADC_AD2                         (_UINT32_(1) << 26) /**< ADC signal: ADC_AD2 */
#define PIN_PA27X1_ADC_AD3                         _UINT32_(27) /**< ADC signal: ADC_AD3 on PA27 mux X1 */
#define PIO_PA27X1_ADC_AD3                         (_UINT32_(1) << 27) /**< ADC signal: ADC_AD3 */
#define PIN_PA28X1_ADC_AD4                         _UINT32_(28) /**< ADC signal: ADC_AD4 on PA28 mux X1 */
#define PIO_PA28X1_ADC_AD4                         (_UINT32_(1) << 28) /**< ADC signal: ADC_AD4 */
#define PIN_PA29X1_ADC_AD5                         _UINT32_(29) /**< ADC signal: ADC_AD5 on PA29 mux X1 */
#define PIO_PA29X1_ADC_AD5                         (_UINT32_(1) << 29) /**< ADC signal: ADC_AD5 */
#define PIN_PA30X1_ADC_AD6                         _UINT32_(30) /**< ADC signal: ADC_AD6 on PA30 mux X1 */
#define PIO_PA30X1_ADC_AD6                         (_UINT32_(1) << 30) /**< ADC signal: ADC_AD6 */
#define PIN_PA31X1_ADC_AD7                         _UINT32_(31) /**< ADC signal: ADC_AD7 on PA31 mux X1 */
#define PIO_PA31X1_ADC_AD7                         (_UINT32_(1) << 31) /**< ADC signal: ADC_AD7 */
#define PIN_PB18B_ADC_ADTRG                        _UINT32_(50) /**< ADC signal: ADC_ADTRG on PB18 mux B */
#define MUX_PB18B_ADC_ADTRG                        _UINT32_(1)  /**< ADC signal line function value: ADC_ADTRG */
#define PIO_PB18B_ADC_ADTRG                        (_UINT32_(1) << 18) /**< ADC signal: ADC_ADTRG */
/* ========== PIO definition for AIC peripheral ========== */
#define PIN_PC31A_AIC_FIQ                          _UINT32_(95) /**< AIC signal: AIC_FIQ on PC31 mux A */
#define MUX_PC31A_AIC_FIQ                          _UINT32_(0)  /**< AIC signal line function value: AIC_FIQ */
#define PIO_PC31A_AIC_FIQ                          (_UINT32_(1) << 31) /**< AIC signal: AIC_FIQ */
#define PIN_PB18D_AIC_IRQ                          _UINT32_(50) /**< AIC signal: AIC_IRQ on PB18 mux D */
#define MUX_PB18D_AIC_IRQ                          _UINT32_(3)  /**< AIC signal line function value: AIC_IRQ */
#define PIO_PB18D_AIC_IRQ                          (_UINT32_(1) << 18) /**< AIC signal: AIC_IRQ */
/* ========== PIO definition for CLASSD peripheral ========== */
#define PIN_PA18C_CLASSD_L0                        _UINT32_(18) /**< CLASSD signal: CLASSD_L0 on PA18 mux C */
#define MUX_PA18C_CLASSD_L0                        _UINT32_(2)  /**< CLASSD signal line function value: CLASSD_L0 */
#define PIO_PA18C_CLASSD_L0                        (_UINT32_(1) << 18) /**< CLASSD signal: CLASSD_L0 */
#define PIN_PA19C_CLASSD_L1                        _UINT32_(19) /**< CLASSD signal: CLASSD_L1 on PA19 mux C */
#define MUX_PA19C_CLASSD_L1                        _UINT32_(2)  /**< CLASSD signal line function value: CLASSD_L1 */
#define PIO_PA19C_CLASSD_L1                        (_UINT32_(1) << 19) /**< CLASSD signal: CLASSD_L1 */
#define PIN_PA20C_CLASSD_L2                        _UINT32_(20) /**< CLASSD signal: CLASSD_L2 on PA20 mux C */
#define MUX_PA20C_CLASSD_L2                        _UINT32_(2)  /**< CLASSD signal line function value: CLASSD_L2 */
#define PIO_PA20C_CLASSD_L2                        (_UINT32_(1) << 20) /**< CLASSD signal: CLASSD_L2 */
#define PIN_PA21C_CLASSD_L3                        _UINT32_(21) /**< CLASSD signal: CLASSD_L3 on PA21 mux C */
#define MUX_PA21C_CLASSD_L3                        _UINT32_(2)  /**< CLASSD signal line function value: CLASSD_L3 */
#define PIO_PA21C_CLASSD_L3                        (_UINT32_(1) << 21) /**< CLASSD signal: CLASSD_L3 */
#define PIN_PA15C_CLASSD_R0                        _UINT32_(15) /**< CLASSD signal: CLASSD_R0 on PA15 mux C */
#define MUX_PA15C_CLASSD_R0                        _UINT32_(2)  /**< CLASSD signal line function value: CLASSD_R0 */
#define PIO_PA15C_CLASSD_R0                        (_UINT32_(1) << 15) /**< CLASSD signal: CLASSD_R0 */
#define PIN_PA16C_CLASSD_R1                        _UINT32_(16) /**< CLASSD signal: CLASSD_R1 on PA16 mux C */
#define MUX_PA16C_CLASSD_R1                        _UINT32_(2)  /**< CLASSD signal line function value: CLASSD_R1 */
#define PIO_PA16C_CLASSD_R1                        (_UINT32_(1) << 16) /**< CLASSD signal: CLASSD_R1 */
#define PIN_PA17C_CLASSD_R2                        _UINT32_(17) /**< CLASSD signal: CLASSD_R2 on PA17 mux C */
#define MUX_PA17C_CLASSD_R2                        _UINT32_(2)  /**< CLASSD signal line function value: CLASSD_R2 */
#define PIO_PA17C_CLASSD_R2                        (_UINT32_(1) << 17) /**< CLASSD signal: CLASSD_R2 */
#define PIN_PA22C_CLASSD_R3                        _UINT32_(22) /**< CLASSD signal: CLASSD_R3 on PA22 mux C */
#define MUX_PA22C_CLASSD_R3                        _UINT32_(2)  /**< CLASSD signal line function value: CLASSD_R3 */
#define PIO_PA22C_CLASSD_R3                        (_UINT32_(1) << 22) /**< CLASSD signal: CLASSD_R3 */
/* ========== PIO definition for DBGU peripheral ========== */
#define PIN_PA26A_DBGU_DRXD                        _UINT32_(26) /**< DBGU signal: DBGU_DRXD on PA26 mux A */
#define MUX_PA26A_DBGU_DRXD                        _UINT32_(0)  /**< DBGU signal line function value: DBGU_DRXD */
#define PIO_PA26A_DBGU_DRXD                        (_UINT32_(1) << 26) /**< DBGU signal: DBGU_DRXD */
#define PIN_PA27A_DBGU_DTXD                        _UINT32_(27) /**< DBGU signal: DBGU_DTXD on PA27 mux A */
#define MUX_PA27A_DBGU_DTXD                        _UINT32_(0)  /**< DBGU signal line function value: DBGU_DTXD */
#define PIO_PA27A_DBGU_DTXD                        (_UINT32_(1) << 27) /**< DBGU signal: DBGU_DTXD */
/* ========== PIO definition for EBI peripheral ========== */
#define PIN_PD12B_EBI_A0                           _UINT32_(108) /**< EBI signal: EBI_A0 on PD12 mux B */
#define MUX_PD12B_EBI_A0                           _UINT32_(1)  /**< EBI signal line function value: EBI_A0 */
#define PIO_PD12B_EBI_A0                           (_UINT32_(1) << 12) /**< EBI signal: EBI_A0 */
#define PIN_PD6B_EBI_A1                            _UINT32_(102) /**< EBI signal: EBI_A1 on PD6 mux B */
#define MUX_PD6B_EBI_A1                            _UINT32_(1)  /**< EBI signal line function value: EBI_A1 */
#define PIO_PD6B_EBI_A1                            (_UINT32_(1) << 6) /**< EBI signal: EBI_A1 */
#define PIN_PD7B_EBI_A12                           _UINT32_(103) /**< EBI signal: EBI_A12 on PD7 mux B */
#define MUX_PD7B_EBI_A12                           _UINT32_(1)  /**< EBI signal line function value: EBI_A12 */
#define PIO_PD7B_EBI_A12                           (_UINT32_(1) << 7) /**< EBI signal: EBI_A12 */
#define PIN_PD8B_EBI_A19                           _UINT32_(104) /**< EBI signal: EBI_A19 on PD8 mux B */
#define MUX_PD8B_EBI_A19                           _UINT32_(1)  /**< EBI signal line function value: EBI_A19 */
#define PIO_PD8B_EBI_A19                           (_UINT32_(1) << 8) /**< EBI signal: EBI_A19 */
#define PIN_PD9B_EBI_A20                           _UINT32_(105) /**< EBI signal: EBI_A20 on PD9 mux B */
#define MUX_PD9B_EBI_A20                           _UINT32_(1)  /**< EBI signal line function value: EBI_A20 */
#define PIO_PD9B_EBI_A20                           (_UINT32_(1) << 9) /**< EBI signal: EBI_A20 */
#define PIN_PD2A_EBI_A21                           _UINT32_(98) /**< EBI signal: EBI_A21 on PD2 mux A */
#define MUX_PD2A_EBI_A21                           _UINT32_(0)  /**< EBI signal line function value: EBI_A21 */
#define PIO_PD2A_EBI_A21                           (_UINT32_(1) << 2) /**< EBI signal: EBI_A21 */
#define PIN_PD3A_EBI_A22                           _UINT32_(99) /**< EBI signal: EBI_A22 on PD3 mux A */
#define MUX_PD3A_EBI_A22                           _UINT32_(0)  /**< EBI signal line function value: EBI_A22 */
#define PIO_PD3A_EBI_A22                           (_UINT32_(1) << 3) /**< EBI signal: EBI_A22 */
#define PIN_PD2A_EBI_NANDALE                       _UINT32_(98) /**< EBI signal: EBI_NANDALE on PD2 mux A */
#define MUX_PD2A_EBI_NANDALE                       _UINT32_(0)  /**< EBI signal line function value: EBI_NANDALE */
#define PIO_PD2A_EBI_NANDALE                       (_UINT32_(1) << 2) /**< EBI signal: EBI_NANDALE */
#define PIN_PD3A_EBI_NANDCLE                       _UINT32_(99) /**< EBI signal: EBI_NANDCLE on PD3 mux A */
#define MUX_PD3A_EBI_NANDCLE                       _UINT32_(0)  /**< EBI signal line function value: EBI_NANDCLE */
#define PIO_PD3A_EBI_NANDCLE                       (_UINT32_(1) << 3) /**< EBI signal: EBI_NANDCLE */
#define PIN_PD4A_EBI_NANDCS                        _UINT32_(100) /**< EBI signal: EBI_NANDCS on PD4 mux A */
#define MUX_PD4A_EBI_NANDCS                        _UINT32_(0)  /**< EBI signal line function value: EBI_NANDCS */
#define PIO_PD4A_EBI_NANDCS                        (_UINT32_(1) << 4) /**< EBI signal: EBI_NANDCS */
#define PIN_PD6A_EBI_NANDDAT0                      _UINT32_(102) /**< EBI signal: EBI_NANDDAT0 on PD6 mux A */
#define MUX_PD6A_EBI_NANDDAT0                      _UINT32_(0)  /**< EBI signal line function value: EBI_NANDDAT0 */
#define PIO_PD6A_EBI_NANDDAT0                      (_UINT32_(1) << 6) /**< EBI signal: EBI_NANDDAT0 */
#define PIN_PD7A_EBI_NANDDAT1                      _UINT32_(103) /**< EBI signal: EBI_NANDDAT1 on PD7 mux A */
#define MUX_PD7A_EBI_NANDDAT1                      _UINT32_(0)  /**< EBI signal line function value: EBI_NANDDAT1 */
#define PIO_PD7A_EBI_NANDDAT1                      (_UINT32_(1) << 7) /**< EBI signal: EBI_NANDDAT1 */
#define PIN_PD8A_EBI_NANDDAT2                      _UINT32_(104) /**< EBI signal: EBI_NANDDAT2 on PD8 mux A */
#define MUX_PD8A_EBI_NANDDAT2                      _UINT32_(0)  /**< EBI signal line function value: EBI_NANDDAT2 */
#define PIO_PD8A_EBI_NANDDAT2                      (_UINT32_(1) << 8) /**< EBI signal: EBI_NANDDAT2 */
#define PIN_PD9A_EBI_NANDDAT3                      _UINT32_(105) /**< EBI signal: EBI_NANDDAT3 on PD9 mux A */
#define MUX_PD9A_EBI_NANDDAT3                      _UINT32_(0)  /**< EBI signal line function value: EBI_NANDDAT3 */
#define PIO_PD9A_EBI_NANDDAT3                      (_UINT32_(1) << 9) /**< EBI signal: EBI_NANDDAT3 */
#define PIN_PD10A_EBI_NANDDAT4                     _UINT32_(106) /**< EBI signal: EBI_NANDDAT4 on PD10 mux A */
#define MUX_PD10A_EBI_NANDDAT4                     _UINT32_(0)  /**< EBI signal line function value: EBI_NANDDAT4 */
#define PIO_PD10A_EBI_NANDDAT4                     (_UINT32_(1) << 10) /**< EBI signal: EBI_NANDDAT4 */
#define PIN_PD11A_EBI_NANDDAT5                     _UINT32_(107) /**< EBI signal: EBI_NANDDAT5 on PD11 mux A */
#define MUX_PD11A_EBI_NANDDAT5                     _UINT32_(0)  /**< EBI signal line function value: EBI_NANDDAT5 */
#define PIO_PD11A_EBI_NANDDAT5                     (_UINT32_(1) << 11) /**< EBI signal: EBI_NANDDAT5 */
#define PIN_PD12A_EBI_NANDDAT6                     _UINT32_(108) /**< EBI signal: EBI_NANDDAT6 on PD12 mux A */
#define MUX_PD12A_EBI_NANDDAT6                     _UINT32_(0)  /**< EBI signal line function value: EBI_NANDDAT6 */
#define PIO_PD12A_EBI_NANDDAT6                     (_UINT32_(1) << 12) /**< EBI signal: EBI_NANDDAT6 */
#define PIN_PD13A_EBI_NANDDAT7                     _UINT32_(109) /**< EBI signal: EBI_NANDDAT7 on PD13 mux A */
#define MUX_PD13A_EBI_NANDDAT7                     _UINT32_(0)  /**< EBI signal line function value: EBI_NANDDAT7 */
#define PIO_PD13A_EBI_NANDDAT7                     (_UINT32_(1) << 13) /**< EBI signal: EBI_NANDDAT7 */
#define PIN_PD0A_EBI_NANDOE                        _UINT32_(96) /**< EBI signal: EBI_NANDOE on PD0 mux A */
#define MUX_PD0A_EBI_NANDOE                        _UINT32_(0)  /**< EBI signal line function value: EBI_NANDOE */
#define PIO_PD0A_EBI_NANDOE                        (_UINT32_(1) << 0) /**< EBI signal: EBI_NANDOE */
#define PIN_PD14A_EBI_NANDRDY                      _UINT32_(110) /**< EBI signal: EBI_NANDRDY on PD14 mux A */
#define MUX_PD14A_EBI_NANDRDY                      _UINT32_(0)  /**< EBI signal line function value: EBI_NANDRDY */
#define PIO_PD14A_EBI_NANDRDY                      (_UINT32_(1) << 14) /**< EBI signal: EBI_NANDRDY */
#define PIN_PD1A_EBI_NANDWE                        _UINT32_(97) /**< EBI signal: EBI_NANDWE on PD1 mux A */
#define MUX_PD1A_EBI_NANDWE                        _UINT32_(0)  /**< EBI signal line function value: EBI_NANDWE */
#define PIO_PD1A_EBI_NANDWE                        (_UINT32_(1) << 1) /**< EBI signal: EBI_NANDWE */
#define PIN_PD12B_EBI_NBS0                         _UINT32_(108) /**< EBI signal: EBI_NBS0 on PD12 mux B */
#define MUX_PD12B_EBI_NBS0                         _UINT32_(1)  /**< EBI signal line function value: EBI_NBS0 */
#define PIO_PD12B_EBI_NBS0                         (_UINT32_(1) << 12) /**< EBI signal: EBI_NBS0 */
#define PIN_PD13B_EBI_NBS1                         _UINT32_(109) /**< EBI signal: EBI_NBS1 on PD13 mux B */
#define MUX_PD13B_EBI_NBS1                         _UINT32_(1)  /**< EBI signal line function value: EBI_NBS1 */
#define PIO_PD13B_EBI_NBS1                         (_UINT32_(1) << 13) /**< EBI signal: EBI_NBS1 */
#define PIN_PD5B_EBI_NCS0                          _UINT32_(101) /**< EBI signal: EBI_NCS0 on PD5 mux B */
#define MUX_PD5B_EBI_NCS0                          _UINT32_(1)  /**< EBI signal line function value: EBI_NCS0 */
#define PIO_PD5B_EBI_NCS0                          (_UINT32_(1) << 5) /**< EBI signal: EBI_NCS0 */
#define PIN_PD4A_EBI_NCS2                          _UINT32_(100) /**< EBI signal: EBI_NCS2 on PD4 mux A */
#define MUX_PD4A_EBI_NCS2                          _UINT32_(0)  /**< EBI signal line function value: EBI_NCS2 */
#define PIO_PD4A_EBI_NCS2                          (_UINT32_(1) << 4) /**< EBI signal: EBI_NCS2 */
#define PIN_PD10B_EBI_NRD                          _UINT32_(106) /**< EBI signal: EBI_NRD on PD10 mux B */
#define MUX_PD10B_EBI_NRD                          _UINT32_(1)  /**< EBI signal line function value: EBI_NRD */
#define PIO_PD10B_EBI_NRD                          (_UINT32_(1) << 10) /**< EBI signal: EBI_NRD */
#define PIN_PD14A_EBI_NWAIT                        _UINT32_(110) /**< EBI signal: EBI_NWAIT on PD14 mux A */
#define MUX_PD14A_EBI_NWAIT                        _UINT32_(0)  /**< EBI signal line function value: EBI_NWAIT */
#define PIO_PD14A_EBI_NWAIT                        (_UINT32_(1) << 14) /**< EBI signal: EBI_NWAIT */
#define PIN_PD11B_EBI_NWE                          _UINT32_(107) /**< EBI signal: EBI_NWE on PD11 mux B */
#define MUX_PD11B_EBI_NWE                          _UINT32_(1)  /**< EBI signal line function value: EBI_NWE */
#define PIO_PD11B_EBI_NWE                          (_UINT32_(1) << 11) /**< EBI signal: EBI_NWE */
#define PIN_PD11B_EBI_NWR0                         _UINT32_(107) /**< EBI signal: EBI_NWR0 on PD11 mux B */
#define MUX_PD11B_EBI_NWR0                         _UINT32_(1)  /**< EBI signal line function value: EBI_NWR0 */
#define PIO_PD11B_EBI_NWR0                         (_UINT32_(1) << 11) /**< EBI signal: EBI_NWR0 */
#define PIN_PD13B_EBI_NWR1                         _UINT32_(109) /**< EBI signal: EBI_NWR1 on PD13 mux B */
#define MUX_PD13B_EBI_NWR1                         _UINT32_(1)  /**< EBI signal line function value: EBI_NWR1 */
#define PIO_PD13B_EBI_NWR1                         (_UINT32_(1) << 13) /**< EBI signal: EBI_NWR1 */
/* ========== PIO definition for FLEXCOM0 peripheral ========== */
#define PIN_PA30A_FLEXCOM0_IO0                     _UINT32_(30) /**< FLEXCOM0 signal: FLEXCOM0_IO0 on PA30 mux A */
#define MUX_PA30A_FLEXCOM0_IO0                     _UINT32_(0)  /**< FLEXCOM0 signal line function value: FLEXCOM0_IO0 */
#define PIO_PA30A_FLEXCOM0_IO0                     (_UINT32_(1) << 30) /**< FLEXCOM0 signal: FLEXCOM0_IO0 */
#define PIN_PA31A_FLEXCOM0_IO1                     _UINT32_(31) /**< FLEXCOM0 signal: FLEXCOM0_IO1 on PA31 mux A */
#define MUX_PA31A_FLEXCOM0_IO1                     _UINT32_(0)  /**< FLEXCOM0 signal line function value: FLEXCOM0_IO1 */
#define PIO_PA31A_FLEXCOM0_IO1                     (_UINT32_(1) << 31) /**< FLEXCOM0 signal: FLEXCOM0_IO1 */
#define PIN_PA8A_FLEXCOM0_IO2                      _UINT32_(8)  /**< FLEXCOM0 signal: FLEXCOM0_IO2 on PA8 mux A */
#define MUX_PA8A_FLEXCOM0_IO2                      _UINT32_(0)  /**< FLEXCOM0 signal line function value: FLEXCOM0_IO2 */
#define PIO_PA8A_FLEXCOM0_IO2                      (_UINT32_(1) << 8) /**< FLEXCOM0 signal: FLEXCOM0_IO2 */
#define PIN_PA7A_FLEXCOM0_IO3                      _UINT32_(7)  /**< FLEXCOM0 signal: FLEXCOM0_IO3 on PA7 mux A */
#define MUX_PA7A_FLEXCOM0_IO3                      _UINT32_(0)  /**< FLEXCOM0 signal line function value: FLEXCOM0_IO3 */
#define PIO_PA7A_FLEXCOM0_IO3                      (_UINT32_(1) << 7) /**< FLEXCOM0 signal: FLEXCOM0_IO3 */
#define PIN_PA6A_FLEXCOM0_IO4                      _UINT32_(6)  /**< FLEXCOM0 signal: FLEXCOM0_IO4 on PA6 mux A */
#define MUX_PA6A_FLEXCOM0_IO4                      _UINT32_(0)  /**< FLEXCOM0 signal line function value: FLEXCOM0_IO4 */
#define PIO_PA6A_FLEXCOM0_IO4                      (_UINT32_(1) << 6) /**< FLEXCOM0 signal: FLEXCOM0_IO4 */
#define PIN_PB6B_FLEXCOM0_IO7                      _UINT32_(38) /**< FLEXCOM0 signal: FLEXCOM0_IO7 on PB6 mux B */
#define MUX_PB6B_FLEXCOM0_IO7                      _UINT32_(1)  /**< FLEXCOM0 signal line function value: FLEXCOM0_IO7 */
#define PIO_PB6B_FLEXCOM0_IO7                      (_UINT32_(1) << 6) /**< FLEXCOM0 signal: FLEXCOM0_IO7 */
/* ========== PIO definition for FLEXCOM1 peripheral ========== */
#define PIN_PA28A_FLEXCOM1_IO0                     _UINT32_(28) /**< FLEXCOM1 signal: FLEXCOM1_IO0 on PA28 mux A */
#define MUX_PA28A_FLEXCOM1_IO0                     _UINT32_(0)  /**< FLEXCOM1 signal line function value: FLEXCOM1_IO0 */
#define PIO_PA28A_FLEXCOM1_IO0                     (_UINT32_(1) << 28) /**< FLEXCOM1 signal: FLEXCOM1_IO0 */
#define PIN_PA29A_FLEXCOM1_IO1                     _UINT32_(29) /**< FLEXCOM1 signal: FLEXCOM1_IO1 on PA29 mux A */
#define MUX_PA29A_FLEXCOM1_IO1                     _UINT32_(0)  /**< FLEXCOM1 signal line function value: FLEXCOM1_IO1 */
#define PIO_PA29A_FLEXCOM1_IO1                     (_UINT32_(1) << 29) /**< FLEXCOM1 signal: FLEXCOM1_IO1 */
#define PIN_PC29C_FLEXCOM1_IO2                     _UINT32_(93) /**< FLEXCOM1 signal: FLEXCOM1_IO2 on PC29 mux C */
#define MUX_PC29C_FLEXCOM1_IO2                     _UINT32_(2)  /**< FLEXCOM1 signal line function value: FLEXCOM1_IO2 */
#define PIO_PC29C_FLEXCOM1_IO2                     (_UINT32_(1) << 29) /**< FLEXCOM1 signal: FLEXCOM1_IO2 */
#define PIN_PC28C_FLEXCOM1_IO3                     _UINT32_(92) /**< FLEXCOM1 signal: FLEXCOM1_IO3 on PC28 mux C */
#define MUX_PC28C_FLEXCOM1_IO3                     _UINT32_(2)  /**< FLEXCOM1 signal line function value: FLEXCOM1_IO3 */
#define PIO_PC28C_FLEXCOM1_IO3                     (_UINT32_(1) << 28) /**< FLEXCOM1 signal: FLEXCOM1_IO3 */
#define PIN_PC27C_FLEXCOM1_IO4                     _UINT32_(91) /**< FLEXCOM1 signal: FLEXCOM1_IO4 on PC27 mux C */
#define MUX_PC27C_FLEXCOM1_IO4                     _UINT32_(2)  /**< FLEXCOM1 signal line function value: FLEXCOM1_IO4 */
#define PIO_PC27C_FLEXCOM1_IO4                     (_UINT32_(1) << 27) /**< FLEXCOM1 signal: FLEXCOM1_IO4 */
#define PIN_PC17B_FLEXCOM1_IO7                     _UINT32_(81) /**< FLEXCOM1 signal: FLEXCOM1_IO7 on PC17 mux B */
#define MUX_PC17B_FLEXCOM1_IO7                     _UINT32_(1)  /**< FLEXCOM1 signal line function value: FLEXCOM1_IO7 */
#define PIO_PC17B_FLEXCOM1_IO7                     (_UINT32_(1) << 17) /**< FLEXCOM1 signal: FLEXCOM1_IO7 */
/* ========== PIO definition for FLEXCOM2 peripheral ========== */
#define PIN_PA13A_FLEXCOM2_IO0                     _UINT32_(13) /**< FLEXCOM2 signal: FLEXCOM2_IO0 on PA13 mux A */
#define MUX_PA13A_FLEXCOM2_IO0                     _UINT32_(0)  /**< FLEXCOM2 signal line function value: FLEXCOM2_IO0 */
#define PIO_PA13A_FLEXCOM2_IO0                     (_UINT32_(1) << 13) /**< FLEXCOM2 signal: FLEXCOM2_IO0 */
#define PIN_PA14A_FLEXCOM2_IO1                     _UINT32_(14) /**< FLEXCOM2 signal: FLEXCOM2_IO1 on PA14 mux A */
#define MUX_PA14A_FLEXCOM2_IO1                     _UINT32_(0)  /**< FLEXCOM2 signal line function value: FLEXCOM2_IO1 */
#define PIO_PA14A_FLEXCOM2_IO1                     (_UINT32_(1) << 14) /**< FLEXCOM2 signal: FLEXCOM2_IO1 */
#define PIN_PB2B_FLEXCOM2_IO2                      _UINT32_(34) /**< FLEXCOM2 signal: FLEXCOM2_IO2 on PB2 mux B */
#define MUX_PB2B_FLEXCOM2_IO2                      _UINT32_(1)  /**< FLEXCOM2 signal line function value: FLEXCOM2_IO2 */
#define PIO_PB2B_FLEXCOM2_IO2                      (_UINT32_(1) << 2) /**< FLEXCOM2 signal: FLEXCOM2_IO2 */
#define PIN_PB1B_FLEXCOM2_IO3                      _UINT32_(33) /**< FLEXCOM2 signal: FLEXCOM2_IO3 on PB1 mux B */
#define MUX_PB1B_FLEXCOM2_IO3                      _UINT32_(1)  /**< FLEXCOM2 signal line function value: FLEXCOM2_IO3 */
#define PIO_PB1B_FLEXCOM2_IO3                      (_UINT32_(1) << 1) /**< FLEXCOM2 signal: FLEXCOM2_IO3 */
#define PIN_PB0B_FLEXCOM2_IO4                      _UINT32_(32) /**< FLEXCOM2 signal: FLEXCOM2_IO4 on PB0 mux B */
#define MUX_PB0B_FLEXCOM2_IO4                      _UINT32_(1)  /**< FLEXCOM2 signal line function value: FLEXCOM2_IO4 */
#define PIO_PB0B_FLEXCOM2_IO4                      (_UINT32_(1) << 0) /**< FLEXCOM2 signal: FLEXCOM2_IO4 */
#define PIN_PA23C_FLEXCOM2_IO7                     _UINT32_(23) /**< FLEXCOM2 signal: FLEXCOM2_IO7 on PA23 mux C */
#define MUX_PA23C_FLEXCOM2_IO7                     _UINT32_(2)  /**< FLEXCOM2 signal line function value: FLEXCOM2_IO7 */
#define PIO_PA23C_FLEXCOM2_IO7                     (_UINT32_(1) << 23) /**< FLEXCOM2 signal: FLEXCOM2_IO7 */
/* ========== PIO definition for FLEXCOM3 peripheral ========== */
#define PIN_PC22B_FLEXCOM3_IO0                     _UINT32_(86) /**< FLEXCOM3 signal: FLEXCOM3_IO0 on PC22 mux B */
#define MUX_PC22B_FLEXCOM3_IO0                     _UINT32_(1)  /**< FLEXCOM3 signal line function value: FLEXCOM3_IO0 */
#define PIO_PC22B_FLEXCOM3_IO0                     (_UINT32_(1) << 22) /**< FLEXCOM3 signal: FLEXCOM3_IO0 */
#define PIN_PC23B_FLEXCOM3_IO1                     _UINT32_(87) /**< FLEXCOM3 signal: FLEXCOM3_IO1 on PC23 mux B */
#define MUX_PC23B_FLEXCOM3_IO1                     _UINT32_(1)  /**< FLEXCOM3 signal line function value: FLEXCOM3_IO1 */
#define PIO_PC23B_FLEXCOM3_IO1                     (_UINT32_(1) << 23) /**< FLEXCOM3 signal: FLEXCOM3_IO1 */
#define PIN_PC26B_FLEXCOM3_IO2                     _UINT32_(90) /**< FLEXCOM3 signal: FLEXCOM3_IO2 on PC26 mux B */
#define MUX_PC26B_FLEXCOM3_IO2                     _UINT32_(1)  /**< FLEXCOM3 signal line function value: FLEXCOM3_IO2 */
#define PIO_PC26B_FLEXCOM3_IO2                     (_UINT32_(1) << 26) /**< FLEXCOM3 signal: FLEXCOM3_IO2 */
#define PIN_PC25B_FLEXCOM3_IO3                     _UINT32_(89) /**< FLEXCOM3 signal: FLEXCOM3_IO3 on PC25 mux B */
#define MUX_PC25B_FLEXCOM3_IO3                     _UINT32_(1)  /**< FLEXCOM3 signal line function value: FLEXCOM3_IO3 */
#define PIO_PC25B_FLEXCOM3_IO3                     (_UINT32_(1) << 25) /**< FLEXCOM3 signal: FLEXCOM3_IO3 */
#define PIN_PC24B_FLEXCOM3_IO4                     _UINT32_(88) /**< FLEXCOM3 signal: FLEXCOM3_IO4 on PC24 mux B */
#define MUX_PC24B_FLEXCOM3_IO4                     _UINT32_(1)  /**< FLEXCOM3 signal line function value: FLEXCOM3_IO4 */
#define PIO_PC24B_FLEXCOM3_IO4                     (_UINT32_(1) << 24) /**< FLEXCOM3 signal: FLEXCOM3_IO4 */
#define PIN_PC30C_FLEXCOM3_IO7                     _UINT32_(94) /**< FLEXCOM3 signal: FLEXCOM3_IO7 on PC30 mux C */
#define MUX_PC30C_FLEXCOM3_IO7                     _UINT32_(2)  /**< FLEXCOM3 signal line function value: FLEXCOM3_IO7 */
#define PIO_PC30C_FLEXCOM3_IO7                     (_UINT32_(1) << 30) /**< FLEXCOM3 signal: FLEXCOM3_IO7 */
/* ========== PIO definition for FLEXCOM4 peripheral ========== */
#define PIN_PA10A_FLEXCOM4_IO0                     _UINT32_(10) /**< FLEXCOM4 signal: FLEXCOM4_IO0 on PA10 mux A */
#define MUX_PA10A_FLEXCOM4_IO0                     _UINT32_(0)  /**< FLEXCOM4 signal line function value: FLEXCOM4_IO0 */
#define PIO_PA10A_FLEXCOM4_IO0                     (_UINT32_(1) << 10) /**< FLEXCOM4 signal: FLEXCOM4_IO0 */
#define PIN_PA9A_FLEXCOM4_IO1                      _UINT32_(9)  /**< FLEXCOM4 signal: FLEXCOM4_IO1 on PA9 mux A */
#define MUX_PA9A_FLEXCOM4_IO1                      _UINT32_(0)  /**< FLEXCOM4 signal line function value: FLEXCOM4_IO1 */
#define PIO_PA9A_FLEXCOM4_IO1                      (_UINT32_(1) << 9) /**< FLEXCOM4 signal: FLEXCOM4_IO1 */
#define PIN_PA11A_FLEXCOM4_IO2                     _UINT32_(11) /**< FLEXCOM4 signal: FLEXCOM4_IO2 on PA11 mux A */
#define MUX_PA11A_FLEXCOM4_IO2                     _UINT32_(0)  /**< FLEXCOM4 signal line function value: FLEXCOM4_IO2 */
#define PIO_PA11A_FLEXCOM4_IO2                     (_UINT32_(1) << 11) /**< FLEXCOM4 signal: FLEXCOM4_IO2 */
#define PIN_PA12A_FLEXCOM4_IO3                     _UINT32_(12) /**< FLEXCOM4 signal: FLEXCOM4_IO3 on PA12 mux A */
#define MUX_PA12A_FLEXCOM4_IO3                     _UINT32_(0)  /**< FLEXCOM4 signal line function value: FLEXCOM4_IO3 */
#define PIO_PA12A_FLEXCOM4_IO3                     (_UINT32_(1) << 12) /**< FLEXCOM4 signal: FLEXCOM4_IO3 */
#define PIN_PA13B_FLEXCOM4_IO4                     _UINT32_(13) /**< FLEXCOM4 signal: FLEXCOM4_IO4 on PA13 mux B */
#define MUX_PA13B_FLEXCOM4_IO4                     _UINT32_(1)  /**< FLEXCOM4 signal line function value: FLEXCOM4_IO4 */
#define PIO_PA13B_FLEXCOM4_IO4                     (_UINT32_(1) << 13) /**< FLEXCOM4 signal: FLEXCOM4_IO4 */
#define PIN_PA30C_FLEXCOM4_IO4                     _UINT32_(30) /**< FLEXCOM4 signal: FLEXCOM4_IO4 on PA30 mux C */
#define MUX_PA30C_FLEXCOM4_IO4                     _UINT32_(2)  /**< FLEXCOM4 signal line function value: FLEXCOM4_IO4 */
#define PIO_PA30C_FLEXCOM4_IO4                     (_UINT32_(1) << 30) /**< FLEXCOM4 signal: FLEXCOM4_IO4 */
#define PIN_PA14C_FLEXCOM4_IO5                     _UINT32_(14) /**< FLEXCOM4 signal: FLEXCOM4_IO5 on PA14 mux C */
#define MUX_PA14C_FLEXCOM4_IO5                     _UINT32_(2)  /**< FLEXCOM4 signal line function value: FLEXCOM4_IO5 */
#define PIO_PA14C_FLEXCOM4_IO5                     (_UINT32_(1) << 14) /**< FLEXCOM4 signal: FLEXCOM4_IO5 */
#define PIN_PA31B_FLEXCOM4_IO5                     _UINT32_(31) /**< FLEXCOM4 signal: FLEXCOM4_IO5 on PA31 mux B */
#define MUX_PA31B_FLEXCOM4_IO5                     _UINT32_(1)  /**< FLEXCOM4 signal line function value: FLEXCOM4_IO5 */
#define PIO_PA31B_FLEXCOM4_IO5                     (_UINT32_(1) << 31) /**< FLEXCOM4 signal: FLEXCOM4_IO5 */
#define PIN_PB3B_FLEXCOM4_IO6                      _UINT32_(35) /**< FLEXCOM4 signal: FLEXCOM4_IO6 on PB3 mux B */
#define MUX_PB3B_FLEXCOM4_IO6                      _UINT32_(1)  /**< FLEXCOM4 signal line function value: FLEXCOM4_IO6 */
#define PIO_PB3B_FLEXCOM4_IO6                      (_UINT32_(1) << 3) /**< FLEXCOM4 signal: FLEXCOM4_IO6 */
/* ========== PIO definition for FLEXCOM5 peripheral ========== */
#define PIN_PA16B_FLEXCOM5_IO0                     _UINT32_(16) /**< FLEXCOM5 signal: FLEXCOM5_IO0 on PA16 mux B */
#define MUX_PA16B_FLEXCOM5_IO0                     _UINT32_(1)  /**< FLEXCOM5 signal line function value: FLEXCOM5_IO0 */
#define PIO_PA16B_FLEXCOM5_IO0                     (_UINT32_(1) << 16) /**< FLEXCOM5 signal: FLEXCOM5_IO0 */
#define PIN_PA15B_FLEXCOM5_IO1                     _UINT32_(15) /**< FLEXCOM5 signal: FLEXCOM5_IO1 on PA15 mux B */
#define MUX_PA15B_FLEXCOM5_IO1                     _UINT32_(1)  /**< FLEXCOM5 signal line function value: FLEXCOM5_IO1 */
#define PIO_PA15B_FLEXCOM5_IO1                     (_UINT32_(1) << 15) /**< FLEXCOM5 signal: FLEXCOM5_IO1 */
#define PIN_PA17B_FLEXCOM5_IO2                     _UINT32_(17) /**< FLEXCOM5 signal: FLEXCOM5_IO2 on PA17 mux B */
#define MUX_PA17B_FLEXCOM5_IO2                     _UINT32_(1)  /**< FLEXCOM5 signal line function value: FLEXCOM5_IO2 */
#define PIO_PA17B_FLEXCOM5_IO2                     (_UINT32_(1) << 17) /**< FLEXCOM5 signal: FLEXCOM5_IO2 */
#define PIN_PA14B_FLEXCOM5_IO3                     _UINT32_(14) /**< FLEXCOM5 signal: FLEXCOM5_IO3 on PA14 mux B */
#define MUX_PA14B_FLEXCOM5_IO3                     _UINT32_(1)  /**< FLEXCOM5 signal line function value: FLEXCOM5_IO3 */
#define PIO_PA14B_FLEXCOM5_IO3                     (_UINT32_(1) << 14) /**< FLEXCOM5 signal: FLEXCOM5_IO3 */
#define PIN_PA12C_FLEXCOM5_IO4                     _UINT32_(12) /**< FLEXCOM5 signal: FLEXCOM5_IO4 on PA12 mux C */
#define MUX_PA12C_FLEXCOM5_IO4                     _UINT32_(2)  /**< FLEXCOM5 signal line function value: FLEXCOM5_IO4 */
#define PIO_PA12C_FLEXCOM5_IO4                     (_UINT32_(1) << 12) /**< FLEXCOM5 signal: FLEXCOM5_IO4 */
#define PIN_PA30B_FLEXCOM5_IO4                     _UINT32_(30) /**< FLEXCOM5 signal: FLEXCOM5_IO4 on PA30 mux B */
#define MUX_PA30B_FLEXCOM5_IO4                     _UINT32_(1)  /**< FLEXCOM5 signal line function value: FLEXCOM5_IO4 */
#define PIO_PA30B_FLEXCOM5_IO4                     (_UINT32_(1) << 30) /**< FLEXCOM5 signal: FLEXCOM5_IO4 */
#define PIN_PA25B_FLEXCOM5_IO5                     _UINT32_(25) /**< FLEXCOM5 signal: FLEXCOM5_IO5 on PA25 mux B */
#define MUX_PA25B_FLEXCOM5_IO5                     _UINT32_(1)  /**< FLEXCOM5 signal line function value: FLEXCOM5_IO5 */
#define PIO_PA25B_FLEXCOM5_IO5                     (_UINT32_(1) << 25) /**< FLEXCOM5 signal: FLEXCOM5_IO5 */
#define PIN_PA24B_FLEXCOM5_IO6                     _UINT32_(24) /**< FLEXCOM5 signal: FLEXCOM5_IO6 on PA24 mux B */
#define MUX_PA24B_FLEXCOM5_IO6                     _UINT32_(1)  /**< FLEXCOM5 signal line function value: FLEXCOM5_IO6 */
#define PIO_PA24B_FLEXCOM5_IO6                     (_UINT32_(1) << 24) /**< FLEXCOM5 signal: FLEXCOM5_IO6 */
/* ========== PIO definition for FLEXCOM6 peripheral ========== */
#define PIN_PA24A_FLEXCOM6_IO0                     _UINT32_(24) /**< FLEXCOM6 signal: FLEXCOM6_IO0 on PA24 mux A */
#define MUX_PA24A_FLEXCOM6_IO0                     _UINT32_(0)  /**< FLEXCOM6 signal line function value: FLEXCOM6_IO0 */
#define PIO_PA24A_FLEXCOM6_IO0                     (_UINT32_(1) << 24) /**< FLEXCOM6 signal: FLEXCOM6_IO0 */
#define PIN_PA25A_FLEXCOM6_IO1                     _UINT32_(25) /**< FLEXCOM6 signal: FLEXCOM6_IO1 on PA25 mux A */
#define MUX_PA25A_FLEXCOM6_IO1                     _UINT32_(0)  /**< FLEXCOM6 signal line function value: FLEXCOM6_IO1 */
#define PIO_PA25A_FLEXCOM6_IO1                     (_UINT32_(1) << 25) /**< FLEXCOM6 signal: FLEXCOM6_IO1 */
#define PIN_PB7C_FLEXCOM6_IO2                      _UINT32_(39) /**< FLEXCOM6 signal: FLEXCOM6_IO2 on PB7 mux C */
#define MUX_PB7C_FLEXCOM6_IO2                      _UINT32_(2)  /**< FLEXCOM6 signal line function value: FLEXCOM6_IO2 */
#define PIO_PB7C_FLEXCOM6_IO2                      (_UINT32_(1) << 7) /**< FLEXCOM6 signal: FLEXCOM6_IO2 */
#define PIN_PB8C_FLEXCOM6_IO3                      _UINT32_(40) /**< FLEXCOM6 signal: FLEXCOM6_IO3 on PB8 mux C */
#define MUX_PB8C_FLEXCOM6_IO3                      _UINT32_(2)  /**< FLEXCOM6 signal line function value: FLEXCOM6_IO3 */
#define PIO_PB8C_FLEXCOM6_IO3                      (_UINT32_(1) << 8) /**< FLEXCOM6 signal: FLEXCOM6_IO3 */
#define PIN_PB9C_FLEXCOM6_IO4                      _UINT32_(41) /**< FLEXCOM6 signal: FLEXCOM6_IO4 on PB9 mux C */
#define MUX_PB9C_FLEXCOM6_IO4                      _UINT32_(2)  /**< FLEXCOM6 signal line function value: FLEXCOM6_IO4 */
#define PIO_PB9C_FLEXCOM6_IO4                      (_UINT32_(1) << 9) /**< FLEXCOM6 signal: FLEXCOM6_IO4 */
/* ========== PIO definition for FLEXCOM7 peripheral ========== */
#define PIN_PC0C_FLEXCOM7_IO0                      _UINT32_(64) /**< FLEXCOM7 signal: FLEXCOM7_IO0 on PC0 mux C */
#define MUX_PC0C_FLEXCOM7_IO0                      _UINT32_(2)  /**< FLEXCOM7 signal line function value: FLEXCOM7_IO0 */
#define PIO_PC0C_FLEXCOM7_IO0                      (_UINT32_(1) << 0) /**< FLEXCOM7 signal: FLEXCOM7_IO0 */
#define PIN_PC1C_FLEXCOM7_IO1                      _UINT32_(65) /**< FLEXCOM7 signal: FLEXCOM7_IO1 on PC1 mux C */
#define MUX_PC1C_FLEXCOM7_IO1                      _UINT32_(2)  /**< FLEXCOM7 signal line function value: FLEXCOM7_IO1 */
#define PIO_PC1C_FLEXCOM7_IO1                      (_UINT32_(1) << 1) /**< FLEXCOM7 signal: FLEXCOM7_IO1 */
#define PIN_PD0C_FLEXCOM7_IO2                      _UINT32_(96) /**< FLEXCOM7 signal: FLEXCOM7_IO2 on PD0 mux C */
#define MUX_PD0C_FLEXCOM7_IO2                      _UINT32_(2)  /**< FLEXCOM7 signal line function value: FLEXCOM7_IO2 */
#define PIO_PD0C_FLEXCOM7_IO2                      (_UINT32_(1) << 0) /**< FLEXCOM7 signal: FLEXCOM7_IO2 */
#define PIN_PD1C_FLEXCOM7_IO3                      _UINT32_(97) /**< FLEXCOM7 signal: FLEXCOM7_IO3 on PD1 mux C */
#define MUX_PD1C_FLEXCOM7_IO3                      _UINT32_(2)  /**< FLEXCOM7 signal line function value: FLEXCOM7_IO3 */
#define PIO_PD1C_FLEXCOM7_IO3                      (_UINT32_(1) << 1) /**< FLEXCOM7 signal: FLEXCOM7_IO3 */
#define PIN_PD2C_FLEXCOM7_IO4                      _UINT32_(98) /**< FLEXCOM7 signal: FLEXCOM7_IO4 on PD2 mux C */
#define MUX_PD2C_FLEXCOM7_IO4                      _UINT32_(2)  /**< FLEXCOM7 signal line function value: FLEXCOM7_IO4 */
#define PIO_PD2C_FLEXCOM7_IO4                      (_UINT32_(1) << 2) /**< FLEXCOM7 signal: FLEXCOM7_IO4 */
/* ========== PIO definition for FLEXCOM8 peripheral ========== */
#define PIN_PB4B_FLEXCOM8_IO0                      _UINT32_(36) /**< FLEXCOM8 signal: FLEXCOM8_IO0 on PB4 mux B */
#define MUX_PB4B_FLEXCOM8_IO0                      _UINT32_(1)  /**< FLEXCOM8 signal line function value: FLEXCOM8_IO0 */
#define PIO_PB4B_FLEXCOM8_IO0                      (_UINT32_(1) << 4) /**< FLEXCOM8 signal: FLEXCOM8_IO0 */
#define PIN_PB5B_FLEXCOM8_IO1                      _UINT32_(37) /**< FLEXCOM8 signal: FLEXCOM8_IO1 on PB5 mux B */
#define MUX_PB5B_FLEXCOM8_IO1                      _UINT32_(1)  /**< FLEXCOM8 signal line function value: FLEXCOM8_IO1 */
#define PIO_PB5B_FLEXCOM8_IO1                      (_UINT32_(1) << 5) /**< FLEXCOM8 signal: FLEXCOM8_IO1 */
#define PIN_PB10C_FLEXCOM8_IO2                     _UINT32_(42) /**< FLEXCOM8 signal: FLEXCOM8_IO2 on PB10 mux C */
#define MUX_PB10C_FLEXCOM8_IO2                     _UINT32_(2)  /**< FLEXCOM8 signal line function value: FLEXCOM8_IO2 */
#define PIO_PB10C_FLEXCOM8_IO2                     (_UINT32_(1) << 10) /**< FLEXCOM8 signal: FLEXCOM8_IO2 */
#define PIN_PB11C_FLEXCOM8_IO3                     _UINT32_(43) /**< FLEXCOM8 signal: FLEXCOM8_IO3 on PB11 mux C */
#define MUX_PB11C_FLEXCOM8_IO3                     _UINT32_(2)  /**< FLEXCOM8 signal line function value: FLEXCOM8_IO3 */
#define PIO_PB11C_FLEXCOM8_IO3                     (_UINT32_(1) << 11) /**< FLEXCOM8 signal: FLEXCOM8_IO3 */
#define PIN_PB12C_FLEXCOM8_IO4                     _UINT32_(44) /**< FLEXCOM8 signal: FLEXCOM8_IO4 on PB12 mux C */
#define MUX_PB12C_FLEXCOM8_IO4                     _UINT32_(2)  /**< FLEXCOM8 signal line function value: FLEXCOM8_IO4 */
#define PIO_PB12C_FLEXCOM8_IO4                     (_UINT32_(1) << 12) /**< FLEXCOM8 signal: FLEXCOM8_IO4 */
/* ========== PIO definition for FLEXCOM9 peripheral ========== */
#define PIN_PC8C_FLEXCOM9_IO0                      _UINT32_(72) /**< FLEXCOM9 signal: FLEXCOM9_IO0 on PC8 mux C */
#define MUX_PC8C_FLEXCOM9_IO0                      _UINT32_(2)  /**< FLEXCOM9 signal line function value: FLEXCOM9_IO0 */
#define PIO_PC8C_FLEXCOM9_IO0                      (_UINT32_(1) << 8) /**< FLEXCOM9 signal: FLEXCOM9_IO0 */
#define PIN_PC9C_FLEXCOM9_IO1                      _UINT32_(73) /**< FLEXCOM9 signal: FLEXCOM9_IO1 on PC9 mux C */
#define MUX_PC9C_FLEXCOM9_IO1                      _UINT32_(2)  /**< FLEXCOM9 signal line function value: FLEXCOM9_IO1 */
#define PIO_PC9C_FLEXCOM9_IO1                      (_UINT32_(1) << 9) /**< FLEXCOM9 signal: FLEXCOM9_IO1 */
#define PIN_PB22C_FLEXCOM9_IO2                     _UINT32_(54) /**< FLEXCOM9 signal: FLEXCOM9_IO2 on PB22 mux C */
#define MUX_PB22C_FLEXCOM9_IO2                     _UINT32_(2)  /**< FLEXCOM9 signal line function value: FLEXCOM9_IO2 */
#define PIO_PB22C_FLEXCOM9_IO2                     (_UINT32_(1) << 22) /**< FLEXCOM9 signal: FLEXCOM9_IO2 */
#define PIN_PB23C_FLEXCOM9_IO3                     _UINT32_(55) /**< FLEXCOM9 signal: FLEXCOM9_IO3 on PB23 mux C */
#define MUX_PB23C_FLEXCOM9_IO3                     _UINT32_(2)  /**< FLEXCOM9 signal line function value: FLEXCOM9_IO3 */
#define PIO_PB23C_FLEXCOM9_IO3                     (_UINT32_(1) << 23) /**< FLEXCOM9 signal: FLEXCOM9_IO3 */
#define PIN_PB24C_FLEXCOM9_IO4                     _UINT32_(56) /**< FLEXCOM9 signal: FLEXCOM9_IO4 on PB24 mux C */
#define MUX_PB24C_FLEXCOM9_IO4                     _UINT32_(2)  /**< FLEXCOM9 signal line function value: FLEXCOM9_IO4 */
#define PIO_PB24C_FLEXCOM9_IO4                     (_UINT32_(1) << 24) /**< FLEXCOM9 signal: FLEXCOM9_IO4 */
/* ========== PIO definition for FLEXCOM10 peripheral ========== */
#define PIN_PC16C_FLEXCOM10_IO0                    _UINT32_(80) /**< FLEXCOM10 signal: FLEXCOM10_IO0 on PC16 mux C */
#define MUX_PC16C_FLEXCOM10_IO0                    _UINT32_(2)  /**< FLEXCOM10 signal line function value: FLEXCOM10_IO0 */
#define PIO_PC16C_FLEXCOM10_IO0                    (_UINT32_(1) << 16) /**< FLEXCOM10 signal: FLEXCOM10_IO0 */
#define PIN_PC17C_FLEXCOM10_IO1                    _UINT32_(81) /**< FLEXCOM10 signal: FLEXCOM10_IO1 on PC17 mux C */
#define MUX_PC17C_FLEXCOM10_IO1                    _UINT32_(2)  /**< FLEXCOM10 signal line function value: FLEXCOM10_IO1 */
#define PIO_PC17C_FLEXCOM10_IO1                    (_UINT32_(1) << 17) /**< FLEXCOM10 signal: FLEXCOM10_IO1 */
#define PIN_PC18B_FLEXCOM10_IO2                    _UINT32_(82) /**< FLEXCOM10 signal: FLEXCOM10_IO2 on PC18 mux B */
#define MUX_PC18B_FLEXCOM10_IO2                    _UINT32_(1)  /**< FLEXCOM10 signal line function value: FLEXCOM10_IO2 */
#define PIO_PC18B_FLEXCOM10_IO2                    (_UINT32_(1) << 18) /**< FLEXCOM10 signal: FLEXCOM10_IO2 */
#define PIN_PC19B_FLEXCOM10_IO3                    _UINT32_(83) /**< FLEXCOM10 signal: FLEXCOM10_IO3 on PC19 mux B */
#define MUX_PC19B_FLEXCOM10_IO3                    _UINT32_(1)  /**< FLEXCOM10 signal line function value: FLEXCOM10_IO3 */
#define PIO_PC19B_FLEXCOM10_IO3                    (_UINT32_(1) << 19) /**< FLEXCOM10 signal: FLEXCOM10_IO3 */
#define PIN_PC20B_FLEXCOM10_IO4                    _UINT32_(84) /**< FLEXCOM10 signal: FLEXCOM10_IO4 on PC20 mux B */
#define MUX_PC20B_FLEXCOM10_IO4                    _UINT32_(1)  /**< FLEXCOM10 signal line function value: FLEXCOM10_IO4 */
#define PIO_PC20B_FLEXCOM10_IO4                    (_UINT32_(1) << 20) /**< FLEXCOM10 signal: FLEXCOM10_IO4 */
/* ========== PIO definition for FLEXCOM11 peripheral ========== */
#define PIN_PB15C_FLEXCOM11_IO0                    _UINT32_(47) /**< FLEXCOM11 signal: FLEXCOM11_IO0 on PB15 mux C */
#define MUX_PB15C_FLEXCOM11_IO0                    _UINT32_(2)  /**< FLEXCOM11 signal line function value: FLEXCOM11_IO0 */
#define PIO_PB15C_FLEXCOM11_IO0                    (_UINT32_(1) << 15) /**< FLEXCOM11 signal: FLEXCOM11_IO0 */
#define PIN_PB16C_FLEXCOM11_IO1                    _UINT32_(48) /**< FLEXCOM11 signal: FLEXCOM11_IO1 on PB16 mux C */
#define MUX_PB16C_FLEXCOM11_IO1                    _UINT32_(2)  /**< FLEXCOM11 signal line function value: FLEXCOM11_IO1 */
#define PIO_PB16C_FLEXCOM11_IO1                    (_UINT32_(1) << 16) /**< FLEXCOM11 signal: FLEXCOM11_IO1 */
#define PIN_PD3C_FLEXCOM11_IO2                     _UINT32_(99) /**< FLEXCOM11 signal: FLEXCOM11_IO2 on PD3 mux C */
#define MUX_PD3C_FLEXCOM11_IO2                     _UINT32_(2)  /**< FLEXCOM11 signal line function value: FLEXCOM11_IO2 */
#define PIO_PD3C_FLEXCOM11_IO2                     (_UINT32_(1) << 3) /**< FLEXCOM11 signal: FLEXCOM11_IO2 */
#define PIN_PD4C_FLEXCOM11_IO3                     _UINT32_(100) /**< FLEXCOM11 signal: FLEXCOM11_IO3 on PD4 mux C */
#define MUX_PD4C_FLEXCOM11_IO3                     _UINT32_(2)  /**< FLEXCOM11 signal line function value: FLEXCOM11_IO3 */
#define PIO_PD4C_FLEXCOM11_IO3                     (_UINT32_(1) << 4) /**< FLEXCOM11 signal: FLEXCOM11_IO3 */
#define PIN_PD5C_FLEXCOM11_IO4                     _UINT32_(101) /**< FLEXCOM11 signal: FLEXCOM11_IO4 on PD5 mux C */
#define MUX_PD5C_FLEXCOM11_IO4                     _UINT32_(2)  /**< FLEXCOM11 signal line function value: FLEXCOM11_IO4 */
#define PIO_PD5C_FLEXCOM11_IO4                     (_UINT32_(1) << 5) /**< FLEXCOM11 signal: FLEXCOM11_IO4 */
/* ========== PIO definition for FLEXCOM12 peripheral ========== */
#define PIN_PB17C_FLEXCOM12_IO0                    _UINT32_(49) /**< FLEXCOM12 signal: FLEXCOM12_IO0 on PB17 mux C */
#define MUX_PB17C_FLEXCOM12_IO0                    _UINT32_(2)  /**< FLEXCOM12 signal line function value: FLEXCOM12_IO0 */
#define PIO_PB17C_FLEXCOM12_IO0                    (_UINT32_(1) << 17) /**< FLEXCOM12 signal: FLEXCOM12_IO0 */
#define PIN_PB18C_FLEXCOM12_IO1                    _UINT32_(50) /**< FLEXCOM12 signal: FLEXCOM12_IO1 on PB18 mux C */
#define MUX_PB18C_FLEXCOM12_IO1                    _UINT32_(2)  /**< FLEXCOM12 signal line function value: FLEXCOM12_IO1 */
#define PIO_PB18C_FLEXCOM12_IO1                    (_UINT32_(1) << 18) /**< FLEXCOM12 signal: FLEXCOM12_IO1 */
#define PIN_PB19C_FLEXCOM12_IO2                    _UINT32_(51) /**< FLEXCOM12 signal: FLEXCOM12_IO2 on PB19 mux C */
#define MUX_PB19C_FLEXCOM12_IO2                    _UINT32_(2)  /**< FLEXCOM12 signal line function value: FLEXCOM12_IO2 */
#define PIO_PB19C_FLEXCOM12_IO2                    (_UINT32_(1) << 19) /**< FLEXCOM12 signal: FLEXCOM12_IO2 */
#define PIN_PB20C_FLEXCOM12_IO3                    _UINT32_(52) /**< FLEXCOM12 signal: FLEXCOM12_IO3 on PB20 mux C */
#define MUX_PB20C_FLEXCOM12_IO3                    _UINT32_(2)  /**< FLEXCOM12 signal line function value: FLEXCOM12_IO3 */
#define PIO_PB20C_FLEXCOM12_IO3                    (_UINT32_(1) << 20) /**< FLEXCOM12 signal: FLEXCOM12_IO3 */
#define PIN_PB21C_FLEXCOM12_IO4                    _UINT32_(53) /**< FLEXCOM12 signal: FLEXCOM12_IO4 on PB21 mux C */
#define MUX_PB21C_FLEXCOM12_IO4                    _UINT32_(2)  /**< FLEXCOM12 signal line function value: FLEXCOM12_IO4 */
#define PIO_PB21C_FLEXCOM12_IO4                    (_UINT32_(1) << 21) /**< FLEXCOM12 signal: FLEXCOM12_IO4 */
/* ========== PIO definition for GMAC peripheral ========== */
#define PIN_PB2A_GMAC_G125CK                       _UINT32_(34) /**< GMAC signal: GMAC_G125CK on PB2 mux A */
#define MUX_PB2A_GMAC_G125CK                       _UINT32_(0)  /**< GMAC signal line function value: GMAC_G125CK */
#define PIO_PB2A_GMAC_G125CK                       (_UINT32_(1) << 2) /**< GMAC signal: GMAC_G125CK */
#define PIN_PB3A_GMAC_GCRSDV                       _UINT32_(35) /**< GMAC signal: GMAC_GCRSDV on PB3 mux A */
#define MUX_PB3A_GMAC_GCRSDV                       _UINT32_(0)  /**< GMAC signal line function value: GMAC_GCRSDV */
#define PIO_PB3A_GMAC_GCRSDV                       (_UINT32_(1) << 3) /**< GMAC signal: GMAC_GCRSDV */
#define PIN_PB10A_GMAC_GMDC                        _UINT32_(42) /**< GMAC signal: GMAC_GMDC on PB10 mux A */
#define MUX_PB10A_GMAC_GMDC                        _UINT32_(0)  /**< GMAC signal line function value: GMAC_GMDC */
#define PIO_PB10A_GMAC_GMDC                        (_UINT32_(1) << 10) /**< GMAC signal: GMAC_GMDC */
#define PIN_PB9A_GMAC_GMDIO                        _UINT32_(41) /**< GMAC signal: GMAC_GMDIO on PB9 mux A */
#define MUX_PB9A_GMAC_GMDIO                        _UINT32_(0)  /**< GMAC signal line function value: GMAC_GMDIO */
#define PIO_PB9A_GMAC_GMDIO                        (_UINT32_(1) << 9) /**< GMAC signal: GMAC_GMDIO */
#define PIN_PB6A_GMAC_GREFCK                       _UINT32_(38) /**< GMAC signal: GMAC_GREFCK on PB6 mux A */
#define MUX_PB6A_GMAC_GREFCK                       _UINT32_(0)  /**< GMAC signal line function value: GMAC_GREFCK */
#define PIO_PB6A_GMAC_GREFCK                       (_UINT32_(1) << 6) /**< GMAC signal: GMAC_GREFCK */
#define PIN_PB11A_GMAC_GRX0                        _UINT32_(43) /**< GMAC signal: GMAC_GRX0 on PB11 mux A */
#define MUX_PB11A_GMAC_GRX0                        _UINT32_(0)  /**< GMAC signal line function value: GMAC_GRX0 */
#define PIO_PB11A_GMAC_GRX0                        (_UINT32_(1) << 11) /**< GMAC signal: GMAC_GRX0 */
#define PIN_PB12A_GMAC_GRX1                        _UINT32_(44) /**< GMAC signal: GMAC_GRX1 on PB12 mux A */
#define MUX_PB12A_GMAC_GRX1                        _UINT32_(0)  /**< GMAC signal line function value: GMAC_GRX1 */
#define PIO_PB12A_GMAC_GRX1                        (_UINT32_(1) << 12) /**< GMAC signal: GMAC_GRX1 */
#define PIN_PB0A_GMAC_GRX2                         _UINT32_(32) /**< GMAC signal: GMAC_GRX2 on PB0 mux A */
#define MUX_PB0A_GMAC_GRX2                         _UINT32_(0)  /**< GMAC signal line function value: GMAC_GRX2 */
#define PIO_PB0A_GMAC_GRX2                         (_UINT32_(1) << 0) /**< GMAC signal: GMAC_GRX2 */
#define PIN_PB1A_GMAC_GRX3                         _UINT32_(33) /**< GMAC signal: GMAC_GRX3 on PB1 mux A */
#define MUX_PB1A_GMAC_GRX3                         _UINT32_(0)  /**< GMAC signal line function value: GMAC_GRX3 */
#define PIO_PB1A_GMAC_GRX3                         (_UINT32_(1) << 1) /**< GMAC signal: GMAC_GRX3 */
#define PIN_PB8A_GMAC_GRXCK                        _UINT32_(40) /**< GMAC signal: GMAC_GRXCK on PB8 mux A */
#define MUX_PB8A_GMAC_GRXCK                        _UINT32_(0)  /**< GMAC signal line function value: GMAC_GRXCK */
#define PIO_PB8A_GMAC_GRXCK                        (_UINT32_(1) << 8) /**< GMAC signal: GMAC_GRXCK */
#define PIN_PB3A_GMAC_GRXCTL                       _UINT32_(35) /**< GMAC signal: GMAC_GRXCTL on PB3 mux A */
#define MUX_PB3A_GMAC_GRXCTL                       _UINT32_(0)  /**< GMAC signal line function value: GMAC_GRXCTL */
#define PIO_PB3A_GMAC_GRXCTL                       (_UINT32_(1) << 3) /**< GMAC signal: GMAC_GRXCTL */
#define PIN_PB0C_GMAC_GRXER                        _UINT32_(32) /**< GMAC signal: GMAC_GRXER on PB0 mux C */
#define MUX_PB0C_GMAC_GRXER                        _UINT32_(2)  /**< GMAC signal line function value: GMAC_GRXER */
#define PIO_PB0C_GMAC_GRXER                        (_UINT32_(1) << 0) /**< GMAC signal: GMAC_GRXER */
#define PIN_PA31C_GMAC_GTSUCOMP                    _UINT32_(31) /**< GMAC signal: GMAC_GTSUCOMP on PA31 mux C */
#define MUX_PA31C_GMAC_GTSUCOMP                    _UINT32_(2)  /**< GMAC signal line function value: GMAC_GTSUCOMP */
#define PIO_PA31C_GMAC_GTSUCOMP                    (_UINT32_(1) << 31) /**< GMAC signal: GMAC_GTSUCOMP */
#define PIN_PB13A_GMAC_GTX0                        _UINT32_(45) /**< GMAC signal: GMAC_GTX0 on PB13 mux A */
#define MUX_PB13A_GMAC_GTX0                        _UINT32_(0)  /**< GMAC signal line function value: GMAC_GTX0 */
#define PIO_PB13A_GMAC_GTX0                        (_UINT32_(1) << 13) /**< GMAC signal: GMAC_GTX0 */
#define PIN_PB14A_GMAC_GTX1                        _UINT32_(46) /**< GMAC signal: GMAC_GTX1 on PB14 mux A */
#define MUX_PB14A_GMAC_GTX1                        _UINT32_(0)  /**< GMAC signal line function value: GMAC_GTX1 */
#define PIO_PB14A_GMAC_GTX1                        (_UINT32_(1) << 14) /**< GMAC signal: GMAC_GTX1 */
#define PIN_PB4A_GMAC_GTX2                         _UINT32_(36) /**< GMAC signal: GMAC_GTX2 on PB4 mux A */
#define MUX_PB4A_GMAC_GTX2                         _UINT32_(0)  /**< GMAC signal line function value: GMAC_GTX2 */
#define PIO_PB4A_GMAC_GTX2                         (_UINT32_(1) << 4) /**< GMAC signal: GMAC_GTX2 */
#define PIN_PB5A_GMAC_GTX3                         _UINT32_(37) /**< GMAC signal: GMAC_GTX3 on PB5 mux A */
#define MUX_PB5A_GMAC_GTX3                         _UINT32_(0)  /**< GMAC signal line function value: GMAC_GTX3 */
#define PIO_PB5A_GMAC_GTX3                         (_UINT32_(1) << 5) /**< GMAC signal: GMAC_GTX3 */
#define PIN_PB6A_GMAC_GTXCK                        _UINT32_(38) /**< GMAC signal: GMAC_GTXCK on PB6 mux A */
#define MUX_PB6A_GMAC_GTXCK                        _UINT32_(0)  /**< GMAC signal line function value: GMAC_GTXCK */
#define PIO_PB6A_GMAC_GTXCK                        (_UINT32_(1) << 6) /**< GMAC signal: GMAC_GTXCK */
#define PIN_PB7A_GMAC_GTXCTL                       _UINT32_(39) /**< GMAC signal: GMAC_GTXCTL on PB7 mux A */
#define MUX_PB7A_GMAC_GTXCTL                       _UINT32_(0)  /**< GMAC signal line function value: GMAC_GTXCTL */
#define PIO_PB7A_GMAC_GTXCTL                       (_UINT32_(1) << 7) /**< GMAC signal: GMAC_GTXCTL */
#define PIN_PB7A_GMAC_GTXEN                        _UINT32_(39) /**< GMAC signal: GMAC_GTXEN on PB7 mux A */
#define MUX_PB7A_GMAC_GTXEN                        _UINT32_(0)  /**< GMAC signal line function value: GMAC_GTXEN */
#define PIO_PB7A_GMAC_GTXEN                        (_UINT32_(1) << 7) /**< GMAC signal: GMAC_GTXEN */
/* ========== PIO definition for I2SMCC peripheral ========== */
#define PIN_PB26D_I2SMCC_CK                        _UINT32_(58) /**< I2SMCC signal: I2SMCC_CK on PB26 mux D */
#define MUX_PB26D_I2SMCC_CK                        _UINT32_(3)  /**< I2SMCC signal line function value: I2SMCC_CK */
#define PIO_PB26D_I2SMCC_CK                        (_UINT32_(1) << 26) /**< I2SMCC signal: I2SMCC_CK */
#define PIN_PB16D_I2SMCC_DIN0                      _UINT32_(48) /**< I2SMCC signal: I2SMCC_DIN0 on PB16 mux D */
#define MUX_PB16D_I2SMCC_DIN0                      _UINT32_(3)  /**< I2SMCC signal line function value: I2SMCC_DIN0 */
#define PIO_PB16D_I2SMCC_DIN0                      (_UINT32_(1) << 16) /**< I2SMCC signal: I2SMCC_DIN0 */
#define PIN_PB17D_I2SMCC_DOUT0                     _UINT32_(49) /**< I2SMCC signal: I2SMCC_DOUT0 on PB17 mux D */
#define MUX_PB17D_I2SMCC_DOUT0                     _UINT32_(3)  /**< I2SMCC signal line function value: I2SMCC_DOUT0 */
#define PIO_PB17D_I2SMCC_DOUT0                     (_UINT32_(1) << 17) /**< I2SMCC signal: I2SMCC_DOUT0 */
#define PIN_PB25D_I2SMCC_MCK                       _UINT32_(57) /**< I2SMCC signal: I2SMCC_MCK on PB25 mux D */
#define MUX_PB25D_I2SMCC_MCK                       _UINT32_(3)  /**< I2SMCC signal line function value: I2SMCC_MCK */
#define PIO_PB25D_I2SMCC_MCK                       (_UINT32_(1) << 25) /**< I2SMCC signal: I2SMCC_MCK */
#define PIN_PB15D_I2SMCC_WS                        _UINT32_(47) /**< I2SMCC signal: I2SMCC_WS on PB15 mux D */
#define MUX_PB15D_I2SMCC_WS                        _UINT32_(3)  /**< I2SMCC signal line function value: I2SMCC_WS */
#define PIO_PB15D_I2SMCC_WS                        (_UINT32_(1) << 15) /**< I2SMCC signal: I2SMCC_WS */
/* ========== PIO definition for ISC peripheral ========== */
#define PIN_PC0B_ISC_D0                            _UINT32_(64) /**< ISC signal: ISC_D0 on PC0 mux B */
#define MUX_PC0B_ISC_D0                            _UINT32_(1)  /**< ISC signal line function value: ISC_D0 */
#define PIO_PC0B_ISC_D0                            (_UINT32_(1) << 0) /**< ISC signal: ISC_D0 */
#define PIN_PC1B_ISC_D1                            _UINT32_(65) /**< ISC signal: ISC_D1 on PC1 mux B */
#define MUX_PC1B_ISC_D1                            _UINT32_(1)  /**< ISC signal line function value: ISC_D1 */
#define PIO_PC1B_ISC_D1                            (_UINT32_(1) << 1) /**< ISC signal: ISC_D1 */
#define PIN_PC2B_ISC_D2                            _UINT32_(66) /**< ISC signal: ISC_D2 on PC2 mux B */
#define MUX_PC2B_ISC_D2                            _UINT32_(1)  /**< ISC signal line function value: ISC_D2 */
#define PIO_PC2B_ISC_D2                            (_UINT32_(1) << 2) /**< ISC signal: ISC_D2 */
#define PIN_PC3B_ISC_D3                            _UINT32_(67) /**< ISC signal: ISC_D3 on PC3 mux B */
#define MUX_PC3B_ISC_D3                            _UINT32_(1)  /**< ISC signal line function value: ISC_D3 */
#define PIO_PC3B_ISC_D3                            (_UINT32_(1) << 3) /**< ISC signal: ISC_D3 */
#define PIN_PC4B_ISC_D4                            _UINT32_(68) /**< ISC signal: ISC_D4 on PC4 mux B */
#define MUX_PC4B_ISC_D4                            _UINT32_(1)  /**< ISC signal line function value: ISC_D4 */
#define PIO_PC4B_ISC_D4                            (_UINT32_(1) << 4) /**< ISC signal: ISC_D4 */
#define PIN_PC5B_ISC_D5                            _UINT32_(69) /**< ISC signal: ISC_D5 on PC5 mux B */
#define MUX_PC5B_ISC_D5                            _UINT32_(1)  /**< ISC signal line function value: ISC_D5 */
#define PIO_PC5B_ISC_D5                            (_UINT32_(1) << 5) /**< ISC signal: ISC_D5 */
#define PIN_PC6B_ISC_D6                            _UINT32_(70) /**< ISC signal: ISC_D6 on PC6 mux B */
#define MUX_PC6B_ISC_D6                            _UINT32_(1)  /**< ISC signal line function value: ISC_D6 */
#define PIO_PC6B_ISC_D6                            (_UINT32_(1) << 6) /**< ISC signal: ISC_D6 */
#define PIN_PC7B_ISC_D7                            _UINT32_(71) /**< ISC signal: ISC_D7 on PC7 mux B */
#define MUX_PC7B_ISC_D7                            _UINT32_(1)  /**< ISC signal line function value: ISC_D7 */
#define PIO_PC7B_ISC_D7                            (_UINT32_(1) << 7) /**< ISC signal: ISC_D7 */
#define PIN_PC8B_ISC_D8                            _UINT32_(72) /**< ISC signal: ISC_D8 on PC8 mux B */
#define MUX_PC8B_ISC_D8                            _UINT32_(1)  /**< ISC signal line function value: ISC_D8 */
#define PIO_PC8B_ISC_D8                            (_UINT32_(1) << 8) /**< ISC signal: ISC_D8 */
#define PIN_PC9B_ISC_D9                            _UINT32_(73) /**< ISC signal: ISC_D9 on PC9 mux B */
#define MUX_PC9B_ISC_D9                            _UINT32_(1)  /**< ISC signal line function value: ISC_D9 */
#define PIO_PC9B_ISC_D9                            (_UINT32_(1) << 9) /**< ISC signal: ISC_D9 */
#define PIN_PC10B_ISC_D10                          _UINT32_(74) /**< ISC signal: ISC_D10 on PC10 mux B */
#define MUX_PC10B_ISC_D10                          _UINT32_(1)  /**< ISC signal line function value: ISC_D10 */
#define PIO_PC10B_ISC_D10                          (_UINT32_(1) << 10) /**< ISC signal: ISC_D10 */
#define PIN_PC11B_ISC_D11                          _UINT32_(75) /**< ISC signal: ISC_D11 on PC11 mux B */
#define MUX_PC11B_ISC_D11                          _UINT32_(1)  /**< ISC signal line function value: ISC_D11 */
#define PIO_PC11B_ISC_D11                          (_UINT32_(1) << 11) /**< ISC signal: ISC_D11 */
#define PIN_PC16B_ISC_FIELD                        _UINT32_(80) /**< ISC signal: ISC_FIELD on PC16 mux B */
#define MUX_PC16B_ISC_FIELD                        _UINT32_(1)  /**< ISC signal line function value: ISC_FIELD */
#define PIO_PC16B_ISC_FIELD                        (_UINT32_(1) << 16) /**< ISC signal: ISC_FIELD */
#define PIN_PC14B_ISC_HSYNC                        _UINT32_(78) /**< ISC signal: ISC_HSYNC on PC14 mux B */
#define MUX_PC14B_ISC_HSYNC                        _UINT32_(1)  /**< ISC signal line function value: ISC_HSYNC */
#define PIO_PC14B_ISC_HSYNC                        (_UINT32_(1) << 14) /**< ISC signal: ISC_HSYNC */
#define PIN_PC15B_ISC_MCK                          _UINT32_(79) /**< ISC signal: ISC_MCK on PC15 mux B */
#define MUX_PC15B_ISC_MCK                          _UINT32_(1)  /**< ISC signal line function value: ISC_MCK */
#define PIO_PC15B_ISC_MCK                          (_UINT32_(1) << 15) /**< ISC signal: ISC_MCK */
#define PIN_PC12B_ISC_PCK                          _UINT32_(76) /**< ISC signal: ISC_PCK on PC12 mux B */
#define MUX_PC12B_ISC_PCK                          _UINT32_(1)  /**< ISC signal line function value: ISC_PCK */
#define PIO_PC12B_ISC_PCK                          (_UINT32_(1) << 12) /**< ISC signal: ISC_PCK */
#define PIN_PC13B_ISC_VSYNC                        _UINT32_(77) /**< ISC signal: ISC_VSYNC on PC13 mux B */
#define MUX_PC13B_ISC_VSYNC                        _UINT32_(1)  /**< ISC signal line function value: ISC_VSYNC */
#define PIO_PC13B_ISC_VSYNC                        (_UINT32_(1) << 13) /**< ISC signal: ISC_VSYNC */
/* ========== PIO definition for LVDSPHY peripheral ========== */
#define PIN_PC2X1_LVDSPHY_LVDS_A0M                 _UINT32_(66) /**< LVDSPHY signal: LVDSPHY_LVDS_A0M on PC2 mux X1 */
#define PIO_PC2X1_LVDSPHY_LVDS_A0M                 (_UINT32_(1) << 2) /**< LVDSPHY signal: LVDSPHY_LVDS_A0M */
#define PIN_PC3X1_LVDSPHY_LVDS_A0P                 _UINT32_(67) /**< LVDSPHY signal: LVDSPHY_LVDS_A0P on PC3 mux X1 */
#define PIO_PC3X1_LVDSPHY_LVDS_A0P                 (_UINT32_(1) << 3) /**< LVDSPHY signal: LVDSPHY_LVDS_A0P */
#define PIN_PC4X1_LVDSPHY_LVDS_A1M                 _UINT32_(68) /**< LVDSPHY signal: LVDSPHY_LVDS_A1M on PC4 mux X1 */
#define PIO_PC4X1_LVDSPHY_LVDS_A1M                 (_UINT32_(1) << 4) /**< LVDSPHY signal: LVDSPHY_LVDS_A1M */
#define PIN_PC5X1_LVDSPHY_LVDS_A1P                 _UINT32_(69) /**< LVDSPHY signal: LVDSPHY_LVDS_A1P on PC5 mux X1 */
#define PIO_PC5X1_LVDSPHY_LVDS_A1P                 (_UINT32_(1) << 5) /**< LVDSPHY signal: LVDSPHY_LVDS_A1P */
#define PIN_PC6X1_LVDSPHY_LVDS_A2M                 _UINT32_(70) /**< LVDSPHY signal: LVDSPHY_LVDS_A2M on PC6 mux X1 */
#define PIO_PC6X1_LVDSPHY_LVDS_A2M                 (_UINT32_(1) << 6) /**< LVDSPHY signal: LVDSPHY_LVDS_A2M */
#define PIN_PC7X1_LVDSPHY_LVDS_A2P                 _UINT32_(71) /**< LVDSPHY signal: LVDSPHY_LVDS_A2P on PC7 mux X1 */
#define PIO_PC7X1_LVDSPHY_LVDS_A2P                 (_UINT32_(1) << 7) /**< LVDSPHY signal: LVDSPHY_LVDS_A2P */
#define PIN_PC12X1_LVDSPHY_LVDS_A3M                _UINT32_(76) /**< LVDSPHY signal: LVDSPHY_LVDS_A3M on PC12 mux X1 */
#define PIO_PC12X1_LVDSPHY_LVDS_A3M                (_UINT32_(1) << 12) /**< LVDSPHY signal: LVDSPHY_LVDS_A3M */
#define PIN_PC13X1_LVDSPHY_LVDS_A3P                _UINT32_(77) /**< LVDSPHY signal: LVDSPHY_LVDS_A3P on PC13 mux X1 */
#define PIO_PC13X1_LVDSPHY_LVDS_A3P                (_UINT32_(1) << 13) /**< LVDSPHY signal: LVDSPHY_LVDS_A3P */
#define PIN_PC10X1_LVDSPHY_LVDS_CLK1M              _UINT32_(74) /**< LVDSPHY signal: LVDSPHY_LVDS_CLK1M on PC10 mux X1 */
#define PIO_PC10X1_LVDSPHY_LVDS_CLK1M              (_UINT32_(1) << 10) /**< LVDSPHY signal: LVDSPHY_LVDS_CLK1M */
#define PIN_PC11X1_LVDSPHY_LVDS_CLK1P              _UINT32_(75) /**< LVDSPHY signal: LVDSPHY_LVDS_CLK1P on PC11 mux X1 */
#define PIO_PC11X1_LVDSPHY_LVDS_CLK1P              (_UINT32_(1) << 11) /**< LVDSPHY signal: LVDSPHY_LVDS_CLK1P */
/* ========== PIO definition for MCAN0 peripheral ========== */
#define PIN_PA26B_MCAN0_CANRX0                     _UINT32_(26) /**< MCAN0 signal: MCAN0_CANRX0 on PA26 mux B */
#define MUX_PA26B_MCAN0_CANRX0                     _UINT32_(1)  /**< MCAN0 signal line function value: MCAN0_CANRX0 */
#define PIO_PA26B_MCAN0_CANRX0                     (_UINT32_(1) << 26) /**< MCAN0 signal: MCAN0_CANRX0 */
#define PIN_PA27B_MCAN0_CANTX0                     _UINT32_(27) /**< MCAN0 signal: MCAN0_CANTX0 on PA27 mux B */
#define MUX_PA27B_MCAN0_CANTX0                     _UINT32_(1)  /**< MCAN0 signal line function value: MCAN0_CANTX0 */
#define PIO_PA27B_MCAN0_CANTX0                     (_UINT32_(1) << 27) /**< MCAN0 signal: MCAN0_CANTX0 */
/* ========== PIO definition for MCAN1 peripheral ========== */
#define PIN_PA29B_MCAN1_CANRX1                     _UINT32_(29) /**< MCAN1 signal: MCAN1_CANRX1 on PA29 mux B */
#define MUX_PA29B_MCAN1_CANRX1                     _UINT32_(1)  /**< MCAN1 signal line function value: MCAN1_CANRX1 */
#define PIO_PA29B_MCAN1_CANRX1                     (_UINT32_(1) << 29) /**< MCAN1 signal: MCAN1_CANRX1 */
#define PIN_PA28B_MCAN1_CANTX1                     _UINT32_(28) /**< MCAN1 signal: MCAN1_CANTX1 on PA28 mux B */
#define MUX_PA28B_MCAN1_CANTX1                     _UINT32_(1)  /**< MCAN1 signal line function value: MCAN1_CANTX1 */
#define PIO_PA28B_MCAN1_CANTX1                     (_UINT32_(1) << 28) /**< MCAN1 signal: MCAN1_CANTX1 */
/* ========== PIO definition for PMC peripheral ========== */
#define PIN_PB10B_PMC_PCK0                         _UINT32_(42) /**< PMC signal: PMC_PCK0 on PB10 mux B */
#define MUX_PB10B_PMC_PCK0                         _UINT32_(1)  /**< PMC signal line function value: PMC_PCK0 */
#define PIO_PB10B_PMC_PCK0                         (_UINT32_(1) << 10) /**< PMC signal: PMC_PCK0 */
#define PIN_PC15C_PMC_PCK0                         _UINT32_(79) /**< PMC signal: PMC_PCK0 on PC15 mux C */
#define MUX_PC15C_PMC_PCK0                         _UINT32_(2)  /**< PMC signal line function value: PMC_PCK0 */
#define PIO_PC15C_PMC_PCK0                         (_UINT32_(1) << 15) /**< PMC signal: PMC_PCK0 */
#define PIN_PB9B_PMC_PCK1                          _UINT32_(41) /**< PMC signal: PMC_PCK1 on PB9 mux B */
#define MUX_PB9B_PMC_PCK1                          _UINT32_(1)  /**< PMC signal line function value: PMC_PCK1 */
#define PIO_PB9B_PMC_PCK1                          (_UINT32_(1) << 9) /**< PMC signal: PMC_PCK1 */
#define PIN_PC31C_PMC_PCK1                         _UINT32_(95) /**< PMC signal: PMC_PCK1 on PC31 mux C */
#define MUX_PC31C_PMC_PCK1                         _UINT32_(2)  /**< PMC signal line function value: PMC_PCK1 */
#define PIO_PC31C_PMC_PCK1                         (_UINT32_(1) << 31) /**< PMC signal: PMC_PCK1 */
/* ========== PIO definition for PWM peripheral ========== */
#define PIN_PB11B_PWM_PWM0                         _UINT32_(43) /**< PWM signal: PWM_PWM0 on PB11 mux B */
#define MUX_PB11B_PWM_PWM0                         _UINT32_(1)  /**< PWM signal line function value: PWM_PWM0 */
#define PIO_PB11B_PWM_PWM0                         (_UINT32_(1) << 11) /**< PWM signal: PWM_PWM0 */
#define PIN_PC10C_PWM_PWM0                         _UINT32_(74) /**< PWM signal: PWM_PWM0 on PC10 mux C */
#define MUX_PC10C_PWM_PWM0                         _UINT32_(2)  /**< PWM signal line function value: PWM_PWM0 */
#define PIO_PC10C_PWM_PWM0                         (_UINT32_(1) << 10) /**< PWM signal: PWM_PWM0 */
#define PIN_PC18C_PWM_PWM0                         _UINT32_(82) /**< PWM signal: PWM_PWM0 on PC18 mux C */
#define MUX_PC18C_PWM_PWM0                         _UINT32_(2)  /**< PWM signal line function value: PWM_PWM0 */
#define PIO_PC18C_PWM_PWM0                         (_UINT32_(1) << 18) /**< PWM signal: PWM_PWM0 */
#define PIN_PB12B_PWM_PWM1                         _UINT32_(44) /**< PWM signal: PWM_PWM1 on PB12 mux B */
#define MUX_PB12B_PWM_PWM1                         _UINT32_(1)  /**< PWM signal line function value: PWM_PWM1 */
#define PIO_PB12B_PWM_PWM1                         (_UINT32_(1) << 12) /**< PWM signal: PWM_PWM1 */
#define PIN_PC11C_PWM_PWM1                         _UINT32_(75) /**< PWM signal: PWM_PWM1 on PC11 mux C */
#define MUX_PC11C_PWM_PWM1                         _UINT32_(2)  /**< PWM signal line function value: PWM_PWM1 */
#define PIO_PC11C_PWM_PWM1                         (_UINT32_(1) << 11) /**< PWM signal: PWM_PWM1 */
#define PIN_PC19C_PWM_PWM1                         _UINT32_(83) /**< PWM signal: PWM_PWM1 on PC19 mux C */
#define MUX_PC19C_PWM_PWM1                         _UINT32_(2)  /**< PWM signal line function value: PWM_PWM1 */
#define PIO_PC19C_PWM_PWM1                         (_UINT32_(1) << 19) /**< PWM signal: PWM_PWM1 */
#define PIN_PB13B_PWM_PWM2                         _UINT32_(45) /**< PWM signal: PWM_PWM2 on PB13 mux B */
#define MUX_PB13B_PWM_PWM2                         _UINT32_(1)  /**< PWM signal line function value: PWM_PWM2 */
#define PIO_PB13B_PWM_PWM2                         (_UINT32_(1) << 13) /**< PWM signal: PWM_PWM2 */
#define PIN_PC20C_PWM_PWM2                         _UINT32_(84) /**< PWM signal: PWM_PWM2 on PC20 mux C */
#define MUX_PC20C_PWM_PWM2                         _UINT32_(2)  /**< PWM signal line function value: PWM_PWM2 */
#define PIO_PC20C_PWM_PWM2                         (_UINT32_(1) << 20) /**< PWM signal: PWM_PWM2 */
#define PIN_PB14B_PWM_PWM3                         _UINT32_(46) /**< PWM signal: PWM_PWM3 on PB14 mux B */
#define MUX_PB14B_PWM_PWM3                         _UINT32_(1)  /**< PWM signal line function value: PWM_PWM3 */
#define PIO_PB14B_PWM_PWM3                         (_UINT32_(1) << 14) /**< PWM signal: PWM_PWM3 */
#define PIN_PC21C_PWM_PWM3                         _UINT32_(85) /**< PWM signal: PWM_PWM3 on PC21 mux C */
#define MUX_PC21C_PWM_PWM3                         _UINT32_(2)  /**< PWM signal line function value: PWM_PWM3 */
#define PIO_PC21C_PWM_PWM3                         (_UINT32_(1) << 21) /**< PWM signal: PWM_PWM3 */
/* ========== PIO definition for QSPI peripheral ========== */
#define PIN_PB20A_QSPI_QCS                         _UINT32_(52) /**< QSPI signal: QSPI_QCS on PB20 mux A */
#define MUX_PB20A_QSPI_QCS                         _UINT32_(0)  /**< QSPI signal line function value: QSPI_QCS */
#define PIO_PB20A_QSPI_QCS                         (_UINT32_(1) << 20) /**< QSPI signal: QSPI_QCS */
#define PIN_PB18A_QSPI_QDQS                        _UINT32_(50) /**< QSPI signal: QSPI_QDQS on PB18 mux A */
#define MUX_PB18A_QSPI_QDQS                        _UINT32_(0)  /**< QSPI signal line function value: QSPI_QDQS */
#define PIO_PB18A_QSPI_QDQS                        (_UINT32_(1) << 18) /**< QSPI signal: QSPI_QDQS */
#define PIN_PB25A_QSPI_QINT                        _UINT32_(57) /**< QSPI signal: QSPI_QINT on PB25 mux A */
#define MUX_PB25A_QSPI_QINT                        _UINT32_(0)  /**< QSPI signal line function value: QSPI_QINT */
#define PIO_PB25A_QSPI_QINT                        (_UINT32_(1) << 25) /**< QSPI signal: QSPI_QINT */
#define PIN_PB21A_QSPI_QIO0                        _UINT32_(53) /**< QSPI signal: QSPI_QIO0 on PB21 mux A */
#define MUX_PB21A_QSPI_QIO0                        _UINT32_(0)  /**< QSPI signal line function value: QSPI_QIO0 */
#define PIO_PB21A_QSPI_QIO0                        (_UINT32_(1) << 21) /**< QSPI signal: QSPI_QIO0 */
#define PIN_PB22A_QSPI_QIO1                        _UINT32_(54) /**< QSPI signal: QSPI_QIO1 on PB22 mux A */
#define MUX_PB22A_QSPI_QIO1                        _UINT32_(0)  /**< QSPI signal line function value: QSPI_QIO1 */
#define PIO_PB22A_QSPI_QIO1                        (_UINT32_(1) << 22) /**< QSPI signal: QSPI_QIO1 */
#define PIN_PB23A_QSPI_QIO2                        _UINT32_(55) /**< QSPI signal: QSPI_QIO2 on PB23 mux A */
#define MUX_PB23A_QSPI_QIO2                        _UINT32_(0)  /**< QSPI signal line function value: QSPI_QIO2 */
#define PIO_PB23A_QSPI_QIO2                        (_UINT32_(1) << 23) /**< QSPI signal: QSPI_QIO2 */
#define PIN_PB24A_QSPI_QIO3                        _UINT32_(56) /**< QSPI signal: QSPI_QIO3 on PB24 mux A */
#define MUX_PB24A_QSPI_QIO3                        _UINT32_(0)  /**< QSPI signal line function value: QSPI_QIO3 */
#define PIO_PB24A_QSPI_QIO3                        (_UINT32_(1) << 24) /**< QSPI signal: QSPI_QIO3 */
#define PIN_PB26A_QSPI_QIO4                        _UINT32_(58) /**< QSPI signal: QSPI_QIO4 on PB26 mux A */
#define MUX_PB26A_QSPI_QIO4                        _UINT32_(0)  /**< QSPI signal line function value: QSPI_QIO4 */
#define PIO_PB26A_QSPI_QIO4                        (_UINT32_(1) << 26) /**< QSPI signal: QSPI_QIO4 */
#define PIN_PB15A_QSPI_QIO5                        _UINT32_(47) /**< QSPI signal: QSPI_QIO5 on PB15 mux A */
#define MUX_PB15A_QSPI_QIO5                        _UINT32_(0)  /**< QSPI signal line function value: QSPI_QIO5 */
#define PIO_PB15A_QSPI_QIO5                        (_UINT32_(1) << 15) /**< QSPI signal: QSPI_QIO5 */
#define PIN_PB16A_QSPI_QIO6                        _UINT32_(48) /**< QSPI signal: QSPI_QIO6 on PB16 mux A */
#define MUX_PB16A_QSPI_QIO6                        _UINT32_(0)  /**< QSPI signal line function value: QSPI_QIO6 */
#define PIO_PB16A_QSPI_QIO6                        (_UINT32_(1) << 16) /**< QSPI signal: QSPI_QIO6 */
#define PIN_PB17A_QSPI_QIO7                        _UINT32_(49) /**< QSPI signal: QSPI_QIO7 on PB17 mux A */
#define MUX_PB17A_QSPI_QIO7                        _UINT32_(0)  /**< QSPI signal line function value: QSPI_QIO7 */
#define PIO_PB17A_QSPI_QIO7                        (_UINT32_(1) << 17) /**< QSPI signal: QSPI_QIO7 */
#define PIN_PB19A_QSPI_QSCK                        _UINT32_(51) /**< QSPI signal: QSPI_QSCK on PB19 mux A */
#define MUX_PB19A_QSPI_QSCK                        _UINT32_(0)  /**< QSPI signal line function value: QSPI_QSCK */
#define PIO_PB19A_QSPI_QSCK                        (_UINT32_(1) << 19) /**< QSPI signal: QSPI_QSCK */
/* ========== PIO definition for SDMMC0 peripheral ========== */
#define PIN_PA2A_SDMMC0_CK                         _UINT32_(2)  /**< SDMMC0 signal: SDMMC0_CK on PA2 mux A */
#define MUX_PA2A_SDMMC0_CK                         _UINT32_(0)  /**< SDMMC0 signal line function value: SDMMC0_CK */
#define PIO_PA2A_SDMMC0_CK                         (_UINT32_(1) << 2) /**< SDMMC0 signal: SDMMC0_CK */
#define PIN_PA1A_SDMMC0_CMD                        _UINT32_(1)  /**< SDMMC0 signal: SDMMC0_CMD on PA1 mux A */
#define MUX_PA1A_SDMMC0_CMD                        _UINT32_(0)  /**< SDMMC0 signal line function value: SDMMC0_CMD */
#define PIO_PA1A_SDMMC0_CMD                        (_UINT32_(1) << 1) /**< SDMMC0 signal: SDMMC0_CMD */
#define PIN_PA0A_SDMMC0_DAT0                       _UINT32_(0)  /**< SDMMC0 signal: SDMMC0_DAT0 on PA0 mux A */
#define MUX_PA0A_SDMMC0_DAT0                       _UINT32_(0)  /**< SDMMC0 signal line function value: SDMMC0_DAT0 */
#define PIO_PA0A_SDMMC0_DAT0                       (_UINT32_(1) << 0) /**< SDMMC0 signal: SDMMC0_DAT0 */
#define PIN_PA3A_SDMMC0_DAT1                       _UINT32_(3)  /**< SDMMC0 signal: SDMMC0_DAT1 on PA3 mux A */
#define MUX_PA3A_SDMMC0_DAT1                       _UINT32_(0)  /**< SDMMC0 signal line function value: SDMMC0_DAT1 */
#define PIO_PA3A_SDMMC0_DAT1                       (_UINT32_(1) << 3) /**< SDMMC0 signal: SDMMC0_DAT1 */
#define PIN_PA4A_SDMMC0_DAT2                       _UINT32_(4)  /**< SDMMC0 signal: SDMMC0_DAT2 on PA4 mux A */
#define MUX_PA4A_SDMMC0_DAT2                       _UINT32_(0)  /**< SDMMC0 signal line function value: SDMMC0_DAT2 */
#define PIO_PA4A_SDMMC0_DAT2                       (_UINT32_(1) << 4) /**< SDMMC0 signal: SDMMC0_DAT2 */
#define PIN_PA5A_SDMMC0_DAT3                       _UINT32_(5)  /**< SDMMC0 signal: SDMMC0_DAT3 on PA5 mux A */
#define MUX_PA5A_SDMMC0_DAT3                       _UINT32_(0)  /**< SDMMC0 signal line function value: SDMMC0_DAT3 */
#define PIO_PA5A_SDMMC0_DAT3                       (_UINT32_(1) << 5) /**< SDMMC0 signal: SDMMC0_DAT3 */
/* ========== PIO definition for SDMMC1 peripheral ========== */
#define PIN_PA11B_SDMMC1_CK                        _UINT32_(11) /**< SDMMC1 signal: SDMMC1_CK on PA11 mux B */
#define MUX_PA11B_SDMMC1_CK                        _UINT32_(1)  /**< SDMMC1 signal line function value: SDMMC1_CK */
#define PIO_PA11B_SDMMC1_CK                        (_UINT32_(1) << 11) /**< SDMMC1 signal: SDMMC1_CK */
#define PIN_PA10B_SDMMC1_CMD                       _UINT32_(10) /**< SDMMC1 signal: SDMMC1_CMD on PA10 mux B */
#define MUX_PA10B_SDMMC1_CMD                       _UINT32_(1)  /**< SDMMC1 signal line function value: SDMMC1_CMD */
#define PIO_PA10B_SDMMC1_CMD                       (_UINT32_(1) << 10) /**< SDMMC1 signal: SDMMC1_CMD */
#define PIN_PA9B_SDMMC1_DAT0                       _UINT32_(9)  /**< SDMMC1 signal: SDMMC1_DAT0 on PA9 mux B */
#define MUX_PA9B_SDMMC1_DAT0                       _UINT32_(1)  /**< SDMMC1 signal line function value: SDMMC1_DAT0 */
#define PIO_PA9B_SDMMC1_DAT0                       (_UINT32_(1) << 9) /**< SDMMC1 signal: SDMMC1_DAT0 */
#define PIN_PA6B_SDMMC1_DAT1                       _UINT32_(6)  /**< SDMMC1 signal: SDMMC1_DAT1 on PA6 mux B */
#define MUX_PA6B_SDMMC1_DAT1                       _UINT32_(1)  /**< SDMMC1 signal line function value: SDMMC1_DAT1 */
#define PIO_PA6B_SDMMC1_DAT1                       (_UINT32_(1) << 6) /**< SDMMC1 signal: SDMMC1_DAT1 */
#define PIN_PA7B_SDMMC1_DAT2                       _UINT32_(7)  /**< SDMMC1 signal: SDMMC1_DAT2 on PA7 mux B */
#define MUX_PA7B_SDMMC1_DAT2                       _UINT32_(1)  /**< SDMMC1 signal line function value: SDMMC1_DAT2 */
#define PIO_PA7B_SDMMC1_DAT2                       (_UINT32_(1) << 7) /**< SDMMC1 signal: SDMMC1_DAT2 */
#define PIN_PA8B_SDMMC1_DAT3                       _UINT32_(8)  /**< SDMMC1 signal: SDMMC1_DAT3 on PA8 mux B */
#define MUX_PA8B_SDMMC1_DAT3                       _UINT32_(1)  /**< SDMMC1 signal line function value: SDMMC1_DAT3 */
#define PIO_PA8B_SDMMC1_DAT3                       (_UINT32_(1) << 8) /**< SDMMC1 signal: SDMMC1_DAT3 */
/* ========== PIO definition for SSC peripheral ========== */
#define PIN_PA21B_SSC_RD                           _UINT32_(21) /**< SSC signal: SSC_RD on PA21 mux B */
#define MUX_PA21B_SSC_RD                           _UINT32_(1)  /**< SSC signal line function value: SSC_RD */
#define PIO_PA21B_SSC_RD                           (_UINT32_(1) << 21) /**< SSC signal: SSC_RD */
#define PIN_PA23B_SSC_RF                           _UINT32_(23) /**< SSC signal: SSC_RF on PA23 mux B */
#define MUX_PA23B_SSC_RF                           _UINT32_(1)  /**< SSC signal line function value: SSC_RF */
#define PIO_PA23B_SSC_RF                           (_UINT32_(1) << 23) /**< SSC signal: SSC_RF */
#define PIN_PA22B_SSC_RK                           _UINT32_(22) /**< SSC signal: SSC_RK on PA22 mux B */
#define MUX_PA22B_SSC_RK                           _UINT32_(1)  /**< SSC signal line function value: SSC_RK */
#define PIO_PA22B_SSC_RK                           (_UINT32_(1) << 22) /**< SSC signal: SSC_RK */
#define PIN_PA20B_SSC_TD                           _UINT32_(20) /**< SSC signal: SSC_TD on PA20 mux B */
#define MUX_PA20B_SSC_TD                           _UINT32_(1)  /**< SSC signal line function value: SSC_TD */
#define PIO_PA20B_SSC_TD                           (_UINT32_(1) << 20) /**< SSC signal: SSC_TD */
#define PIN_PA19B_SSC_TF                           _UINT32_(19) /**< SSC signal: SSC_TF on PA19 mux B */
#define MUX_PA19B_SSC_TF                           _UINT32_(1)  /**< SSC signal line function value: SSC_TF */
#define PIO_PA19B_SSC_TF                           (_UINT32_(1) << 19) /**< SSC signal: SSC_TF */
#define PIN_PA18B_SSC_TK                           _UINT32_(18) /**< SSC signal: SSC_TK on PA18 mux B */
#define MUX_PA18B_SSC_TK                           _UINT32_(1)  /**< SSC signal line function value: SSC_TK */
#define PIO_PA18B_SSC_TK                           (_UINT32_(1) << 18) /**< SSC signal: SSC_TK */
/* ========== PIO definition for TC0 peripheral ========== */
#define PIN_PA18A_TC0_TCLK0                        _UINT32_(18) /**< TC0 signal: TC0_TCLK0 on PA18 mux A */
#define MUX_PA18A_TC0_TCLK0                        _UINT32_(0)  /**< TC0 signal line function value: TC0_TCLK0 */
#define PIO_PA18A_TC0_TCLK0                        (_UINT32_(1) << 18) /**< TC0 signal: TC0_TCLK0 */
#define PIN_PA19A_TC0_TCLK1                        _UINT32_(19) /**< TC0 signal: TC0_TCLK1 on PA19 mux A */
#define MUX_PA19A_TC0_TCLK1                        _UINT32_(0)  /**< TC0 signal line function value: TC0_TCLK1 */
#define PIO_PA19A_TC0_TCLK1                        (_UINT32_(1) << 19) /**< TC0 signal: TC0_TCLK1 */
#define PIN_PA20A_TC0_TCLK2                        _UINT32_(20) /**< TC0 signal: TC0_TCLK2 on PA20 mux A */
#define MUX_PA20A_TC0_TCLK2                        _UINT32_(0)  /**< TC0 signal line function value: TC0_TCLK2 */
#define PIO_PA20A_TC0_TCLK2                        (_UINT32_(1) << 20) /**< TC0 signal: TC0_TCLK2 */
#define PIN_PA15A_TC0_TIOA0                        _UINT32_(15) /**< TC0 signal: TC0_TIOA0 on PA15 mux A */
#define MUX_PA15A_TC0_TIOA0                        _UINT32_(0)  /**< TC0 signal line function value: TC0_TIOA0 */
#define PIO_PA15A_TC0_TIOA0                        (_UINT32_(1) << 15) /**< TC0 signal: TC0_TIOA0 */
#define PIN_PA16A_TC0_TIOA1                        _UINT32_(16) /**< TC0 signal: TC0_TIOA1 on PA16 mux A */
#define MUX_PA16A_TC0_TIOA1                        _UINT32_(0)  /**< TC0 signal line function value: TC0_TIOA1 */
#define PIO_PA16A_TC0_TIOA1                        (_UINT32_(1) << 16) /**< TC0 signal: TC0_TIOA1 */
#define PIN_PA17A_TC0_TIOA2                        _UINT32_(17) /**< TC0 signal: TC0_TIOA2 on PA17 mux A */
#define MUX_PA17A_TC0_TIOA2                        _UINT32_(0)  /**< TC0 signal line function value: TC0_TIOA2 */
#define PIO_PA17A_TC0_TIOA2                        (_UINT32_(1) << 17) /**< TC0 signal: TC0_TIOA2 */
#define PIN_PA21A_TC0_TIOB0                        _UINT32_(21) /**< TC0 signal: TC0_TIOB0 on PA21 mux A */
#define MUX_PA21A_TC0_TIOB0                        _UINT32_(0)  /**< TC0 signal line function value: TC0_TIOB0 */
#define PIO_PA21A_TC0_TIOB0                        (_UINT32_(1) << 21) /**< TC0 signal: TC0_TIOB0 */
#define PIN_PA22A_TC0_TIOB1                        _UINT32_(22) /**< TC0 signal: TC0_TIOB1 on PA22 mux A */
#define MUX_PA22A_TC0_TIOB1                        _UINT32_(0)  /**< TC0 signal line function value: TC0_TIOB1 */
#define PIO_PA22A_TC0_TIOB1                        (_UINT32_(1) << 22) /**< TC0 signal: TC0_TIOB1 */
#define PIN_PA23A_TC0_TIOB2                        _UINT32_(23) /**< TC0 signal: TC0_TIOB2 on PA23 mux A */
#define MUX_PA23A_TC0_TIOB2                        _UINT32_(0)  /**< TC0 signal line function value: TC0_TIOB2 */
#define PIO_PA23A_TC0_TIOB2                        (_UINT32_(1) << 23) /**< TC0 signal: TC0_TIOB2 */
/* ========== PIO definition for TC1 peripheral ========== */
#define PIN_PC4C_TC1_TCLK3                         _UINT32_(68) /**< TC1 signal: TC1_TCLK3 on PC4 mux C */
#define MUX_PC4C_TC1_TCLK3                         _UINT32_(2)  /**< TC1 signal line function value: TC1_TCLK3 */
#define PIO_PC4C_TC1_TCLK3                         (_UINT32_(1) << 4) /**< TC1 signal: TC1_TCLK3 */
#define PIN_PC7C_TC1_TCLK4                         _UINT32_(71) /**< TC1 signal: TC1_TCLK4 on PC7 mux C */
#define MUX_PC7C_TC1_TCLK4                         _UINT32_(2)  /**< TC1 signal line function value: TC1_TCLK4 */
#define PIO_PC7C_TC1_TCLK4                         (_UINT32_(1) << 7) /**< TC1 signal: TC1_TCLK4 */
#define PIN_PC14C_TC1_TCLK5                        _UINT32_(78) /**< TC1 signal: TC1_TCLK5 on PC14 mux C */
#define MUX_PC14C_TC1_TCLK5                        _UINT32_(2)  /**< TC1 signal line function value: TC1_TCLK5 */
#define PIO_PC14C_TC1_TCLK5                        (_UINT32_(1) << 14) /**< TC1 signal: TC1_TCLK5 */
#define PIN_PC2C_TC1_TIOA3                         _UINT32_(66) /**< TC1 signal: TC1_TIOA3 on PC2 mux C */
#define MUX_PC2C_TC1_TIOA3                         _UINT32_(2)  /**< TC1 signal line function value: TC1_TIOA3 */
#define PIO_PC2C_TC1_TIOA3                         (_UINT32_(1) << 2) /**< TC1 signal: TC1_TIOA3 */
#define PIN_PC5C_TC1_TIOA4                         _UINT32_(69) /**< TC1 signal: TC1_TIOA4 on PC5 mux C */
#define MUX_PC5C_TC1_TIOA4                         _UINT32_(2)  /**< TC1 signal line function value: TC1_TIOA4 */
#define PIO_PC5C_TC1_TIOA4                         (_UINT32_(1) << 5) /**< TC1 signal: TC1_TIOA4 */
#define PIN_PC12C_TC1_TIOA5                        _UINT32_(76) /**< TC1 signal: TC1_TIOA5 on PC12 mux C */
#define MUX_PC12C_TC1_TIOA5                        _UINT32_(2)  /**< TC1 signal line function value: TC1_TIOA5 */
#define PIO_PC12C_TC1_TIOA5                        (_UINT32_(1) << 12) /**< TC1 signal: TC1_TIOA5 */
#define PIN_PC3C_TC1_TIOB3                         _UINT32_(67) /**< TC1 signal: TC1_TIOB3 on PC3 mux C */
#define MUX_PC3C_TC1_TIOB3                         _UINT32_(2)  /**< TC1 signal line function value: TC1_TIOB3 */
#define PIO_PC3C_TC1_TIOB3                         (_UINT32_(1) << 3) /**< TC1 signal: TC1_TIOB3 */
#define PIN_PC6C_TC1_TIOB4                         _UINT32_(70) /**< TC1 signal: TC1_TIOB4 on PC6 mux C */
#define MUX_PC6C_TC1_TIOB4                         _UINT32_(2)  /**< TC1 signal line function value: TC1_TIOB4 */
#define PIO_PC6C_TC1_TIOB4                         (_UINT32_(1) << 6) /**< TC1 signal: TC1_TIOB4 */
#define PIN_PC13C_TC1_TIOB5                        _UINT32_(77) /**< TC1 signal: TC1_TIOB5 on PC13 mux C */
#define MUX_PC13C_TC1_TIOB5                        _UINT32_(2)  /**< TC1 signal line function value: TC1_TIOB5 */
#define PIO_PC13C_TC1_TIOB5                        (_UINT32_(1) << 13) /**< TC1 signal: TC1_TIOB5 */

#endif /* _SAM9X75_GPIO_H_ */

