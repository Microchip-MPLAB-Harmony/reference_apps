/*
 * Peripheral I/O description for PIC32CK2051GC01144
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

/* file generated from device description version 2023-04-05T13:26:38Z */
#ifndef _PIC32CK2051GC01144_GPIO_H_
#define _PIC32CK2051GC01144_GPIO_H_

/* ========== Peripheral I/O pin numbers ========== */
#define PIN_PA00                    (    0)  /**< Pin Number for PA00 */
#define PIN_PA01                    (    1)  /**< Pin Number for PA01 */
#define PIN_PA02                    (    2)  /**< Pin Number for PA02 */
#define PIN_PA03                    (    3)  /**< Pin Number for PA03 */
#define PIN_PA04                    (    4)  /**< Pin Number for PA04 */
#define PIN_PA05                    (    5)  /**< Pin Number for PA05 */
#define PIN_PA06                    (    6)  /**< Pin Number for PA06 */
#define PIN_PA07                    (    7)  /**< Pin Number for PA07 */
#define PIN_PA08                    (    8)  /**< Pin Number for PA08 */
#define PIN_PA09                    (    9)  /**< Pin Number for PA09 */
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
#define PIN_PB00                    (   32)  /**< Pin Number for PB00 */
#define PIN_PB01                    (   33)  /**< Pin Number for PB01 */
#define PIN_PB02                    (   34)  /**< Pin Number for PB02 */
#define PIN_PB03                    (   35)  /**< Pin Number for PB03 */
#define PIN_PB04                    (   36)  /**< Pin Number for PB04 */
#define PIN_PB05                    (   37)  /**< Pin Number for PB05 */
#define PIN_PB06                    (   38)  /**< Pin Number for PB06 */
#define PIN_PB07                    (   39)  /**< Pin Number for PB07 */
#define PIN_PB08                    (   40)  /**< Pin Number for PB08 */
#define PIN_PB09                    (   41)  /**< Pin Number for PB09 */
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
#define PIN_PC00                    (   64)  /**< Pin Number for PC00 */
#define PIN_PC01                    (   65)  /**< Pin Number for PC01 */
#define PIN_PC02                    (   66)  /**< Pin Number for PC02 */
#define PIN_PC03                    (   67)  /**< Pin Number for PC03 */
#define PIN_PC04                    (   68)  /**< Pin Number for PC04 */
#define PIN_PC05                    (   69)  /**< Pin Number for PC05 */
#define PIN_PC06                    (   70)  /**< Pin Number for PC06 */
#define PIN_PC07                    (   71)  /**< Pin Number for PC07 */
#define PIN_PC09                    (   73)  /**< Pin Number for PC09 */
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
#define PIN_PD00                    (   96)  /**< Pin Number for PD00 */
#define PIN_PD01                    (   97)  /**< Pin Number for PD01 */
#define PIN_PD02                    (   98)  /**< Pin Number for PD02 */
#define PIN_PD03                    (   99)  /**< Pin Number for PD03 */
#define PIN_PD04                    (  100)  /**< Pin Number for PD04 */
#define PIN_PD05                    (  101)  /**< Pin Number for PD05 */
#define PIN_PD06                    (  102)  /**< Pin Number for PD06 */
#define PIN_PD07                    (  103)  /**< Pin Number for PD07 */
#define PIN_PD08                    (  104)  /**< Pin Number for PD08 */
#define PIN_PD09                    (  105)  /**< Pin Number for PD09 */
#define PIN_PD10                    (  106)  /**< Pin Number for PD10 */
#define PIN_PD11                    (  107)  /**< Pin Number for PD11 */
#define PIN_PD12                    (  108)  /**< Pin Number for PD12 */
#define PIN_PD13                    (  109)  /**< Pin Number for PD13 */
#define PIN_PD14                    (  110)  /**< Pin Number for PD14 */
#define PIN_PD15                    (  111)  /**< Pin Number for PD15 */
#define PIN_PD16                    (  112)  /**< Pin Number for PD16 */
#define PIN_PD17                    (  113)  /**< Pin Number for PD17 */
#define PIN_PD18                    (  114)  /**< Pin Number for PD18 */
#define PIN_PD19                    (  115)  /**< Pin Number for PD19 */
#define PIN_PD20                    (  116)  /**< Pin Number for PD20 */
#define PIN_PD21                    (  117)  /**< Pin Number for PD21 */

/* ========== Peripheral I/O masks ========== */
#define PORT_PA00                   (_UINT32_(1) << 0) /**< PORT mask for PA00 */
#define PORT_PA01                   (_UINT32_(1) << 1) /**< PORT mask for PA01 */
#define PORT_PA02                   (_UINT32_(1) << 2) /**< PORT mask for PA02 */
#define PORT_PA03                   (_UINT32_(1) << 3) /**< PORT mask for PA03 */
#define PORT_PA04                   (_UINT32_(1) << 4) /**< PORT mask for PA04 */
#define PORT_PA05                   (_UINT32_(1) << 5) /**< PORT mask for PA05 */
#define PORT_PA06                   (_UINT32_(1) << 6) /**< PORT mask for PA06 */
#define PORT_PA07                   (_UINT32_(1) << 7) /**< PORT mask for PA07 */
#define PORT_PA08                   (_UINT32_(1) << 8) /**< PORT mask for PA08 */
#define PORT_PA09                   (_UINT32_(1) << 9) /**< PORT mask for PA09 */
#define PORT_PA10                   (_UINT32_(1) << 10) /**< PORT mask for PA10 */
#define PORT_PA11                   (_UINT32_(1) << 11) /**< PORT mask for PA11 */
#define PORT_PA12                   (_UINT32_(1) << 12) /**< PORT mask for PA12 */
#define PORT_PA13                   (_UINT32_(1) << 13) /**< PORT mask for PA13 */
#define PORT_PA14                   (_UINT32_(1) << 14) /**< PORT mask for PA14 */
#define PORT_PA15                   (_UINT32_(1) << 15) /**< PORT mask for PA15 */
#define PORT_PA16                   (_UINT32_(1) << 16) /**< PORT mask for PA16 */
#define PORT_PA17                   (_UINT32_(1) << 17) /**< PORT mask for PA17 */
#define PORT_PA18                   (_UINT32_(1) << 18) /**< PORT mask for PA18 */
#define PORT_PA19                   (_UINT32_(1) << 19) /**< PORT mask for PA19 */
#define PORT_PA20                   (_UINT32_(1) << 20) /**< PORT mask for PA20 */
#define PORT_PA21                   (_UINT32_(1) << 21) /**< PORT mask for PA21 */
#define PORT_PA22                   (_UINT32_(1) << 22) /**< PORT mask for PA22 */
#define PORT_PA23                   (_UINT32_(1) << 23) /**< PORT mask for PA23 */
#define PORT_PA24                   (_UINT32_(1) << 24) /**< PORT mask for PA24 */
#define PORT_PA25                   (_UINT32_(1) << 25) /**< PORT mask for PA25 */
#define PORT_PA26                   (_UINT32_(1) << 26) /**< PORT mask for PA26 */
#define PORT_PA27                   (_UINT32_(1) << 27) /**< PORT mask for PA27 */
#define PORT_PA28                   (_UINT32_(1) << 28) /**< PORT mask for PA28 */
#define PORT_PB00                   (_UINT32_(1) << 0) /**< PORT mask for PB00 */
#define PORT_PB01                   (_UINT32_(1) << 1) /**< PORT mask for PB01 */
#define PORT_PB02                   (_UINT32_(1) << 2) /**< PORT mask for PB02 */
#define PORT_PB03                   (_UINT32_(1) << 3) /**< PORT mask for PB03 */
#define PORT_PB04                   (_UINT32_(1) << 4) /**< PORT mask for PB04 */
#define PORT_PB05                   (_UINT32_(1) << 5) /**< PORT mask for PB05 */
#define PORT_PB06                   (_UINT32_(1) << 6) /**< PORT mask for PB06 */
#define PORT_PB07                   (_UINT32_(1) << 7) /**< PORT mask for PB07 */
#define PORT_PB08                   (_UINT32_(1) << 8) /**< PORT mask for PB08 */
#define PORT_PB09                   (_UINT32_(1) << 9) /**< PORT mask for PB09 */
#define PORT_PB10                   (_UINT32_(1) << 10) /**< PORT mask for PB10 */
#define PORT_PB11                   (_UINT32_(1) << 11) /**< PORT mask for PB11 */
#define PORT_PB12                   (_UINT32_(1) << 12) /**< PORT mask for PB12 */
#define PORT_PB13                   (_UINT32_(1) << 13) /**< PORT mask for PB13 */
#define PORT_PB14                   (_UINT32_(1) << 14) /**< PORT mask for PB14 */
#define PORT_PB15                   (_UINT32_(1) << 15) /**< PORT mask for PB15 */
#define PORT_PB16                   (_UINT32_(1) << 16) /**< PORT mask for PB16 */
#define PORT_PB17                   (_UINT32_(1) << 17) /**< PORT mask for PB17 */
#define PORT_PB18                   (_UINT32_(1) << 18) /**< PORT mask for PB18 */
#define PORT_PB19                   (_UINT32_(1) << 19) /**< PORT mask for PB19 */
#define PORT_PB20                   (_UINT32_(1) << 20) /**< PORT mask for PB20 */
#define PORT_PB21                   (_UINT32_(1) << 21) /**< PORT mask for PB21 */
#define PORT_PB22                   (_UINT32_(1) << 22) /**< PORT mask for PB22 */
#define PORT_PB23                   (_UINT32_(1) << 23) /**< PORT mask for PB23 */
#define PORT_PB24                   (_UINT32_(1) << 24) /**< PORT mask for PB24 */
#define PORT_PB25                   (_UINT32_(1) << 25) /**< PORT mask for PB25 */
#define PORT_PB26                   (_UINT32_(1) << 26) /**< PORT mask for PB26 */
#define PORT_PC00                   (_UINT32_(1) << 0) /**< PORT mask for PC00 */
#define PORT_PC01                   (_UINT32_(1) << 1) /**< PORT mask for PC01 */
#define PORT_PC02                   (_UINT32_(1) << 2) /**< PORT mask for PC02 */
#define PORT_PC03                   (_UINT32_(1) << 3) /**< PORT mask for PC03 */
#define PORT_PC04                   (_UINT32_(1) << 4) /**< PORT mask for PC04 */
#define PORT_PC05                   (_UINT32_(1) << 5) /**< PORT mask for PC05 */
#define PORT_PC06                   (_UINT32_(1) << 6) /**< PORT mask for PC06 */
#define PORT_PC07                   (_UINT32_(1) << 7) /**< PORT mask for PC07 */
#define PORT_PC09                   (_UINT32_(1) << 9) /**< PORT mask for PC09 */
#define PORT_PC10                   (_UINT32_(1) << 10) /**< PORT mask for PC10 */
#define PORT_PC11                   (_UINT32_(1) << 11) /**< PORT mask for PC11 */
#define PORT_PC12                   (_UINT32_(1) << 12) /**< PORT mask for PC12 */
#define PORT_PC13                   (_UINT32_(1) << 13) /**< PORT mask for PC13 */
#define PORT_PC14                   (_UINT32_(1) << 14) /**< PORT mask for PC14 */
#define PORT_PC15                   (_UINT32_(1) << 15) /**< PORT mask for PC15 */
#define PORT_PC16                   (_UINT32_(1) << 16) /**< PORT mask for PC16 */
#define PORT_PC17                   (_UINT32_(1) << 17) /**< PORT mask for PC17 */
#define PORT_PC18                   (_UINT32_(1) << 18) /**< PORT mask for PC18 */
#define PORT_PC19                   (_UINT32_(1) << 19) /**< PORT mask for PC19 */
#define PORT_PC20                   (_UINT32_(1) << 20) /**< PORT mask for PC20 */
#define PORT_PC21                   (_UINT32_(1) << 21) /**< PORT mask for PC21 */
#define PORT_PC22                   (_UINT32_(1) << 22) /**< PORT mask for PC22 */
#define PORT_PC23                   (_UINT32_(1) << 23) /**< PORT mask for PC23 */
#define PORT_PC24                   (_UINT32_(1) << 24) /**< PORT mask for PC24 */
#define PORT_PC25                   (_UINT32_(1) << 25) /**< PORT mask for PC25 */
#define PORT_PC26                   (_UINT32_(1) << 26) /**< PORT mask for PC26 */
#define PORT_PC27                   (_UINT32_(1) << 27) /**< PORT mask for PC27 */
#define PORT_PC28                   (_UINT32_(1) << 28) /**< PORT mask for PC28 */
#define PORT_PC29                   (_UINT32_(1) << 29) /**< PORT mask for PC29 */
#define PORT_PD00                   (_UINT32_(1) << 0) /**< PORT mask for PD00 */
#define PORT_PD01                   (_UINT32_(1) << 1) /**< PORT mask for PD01 */
#define PORT_PD02                   (_UINT32_(1) << 2) /**< PORT mask for PD02 */
#define PORT_PD03                   (_UINT32_(1) << 3) /**< PORT mask for PD03 */
#define PORT_PD04                   (_UINT32_(1) << 4) /**< PORT mask for PD04 */
#define PORT_PD05                   (_UINT32_(1) << 5) /**< PORT mask for PD05 */
#define PORT_PD06                   (_UINT32_(1) << 6) /**< PORT mask for PD06 */
#define PORT_PD07                   (_UINT32_(1) << 7) /**< PORT mask for PD07 */
#define PORT_PD08                   (_UINT32_(1) << 8) /**< PORT mask for PD08 */
#define PORT_PD09                   (_UINT32_(1) << 9) /**< PORT mask for PD09 */
#define PORT_PD10                   (_UINT32_(1) << 10) /**< PORT mask for PD10 */
#define PORT_PD11                   (_UINT32_(1) << 11) /**< PORT mask for PD11 */
#define PORT_PD12                   (_UINT32_(1) << 12) /**< PORT mask for PD12 */
#define PORT_PD13                   (_UINT32_(1) << 13) /**< PORT mask for PD13 */
#define PORT_PD14                   (_UINT32_(1) << 14) /**< PORT mask for PD14 */
#define PORT_PD15                   (_UINT32_(1) << 15) /**< PORT mask for PD15 */
#define PORT_PD16                   (_UINT32_(1) << 16) /**< PORT mask for PD16 */
#define PORT_PD17                   (_UINT32_(1) << 17) /**< PORT mask for PD17 */
#define PORT_PD18                   (_UINT32_(1) << 18) /**< PORT mask for PD18 */
#define PORT_PD19                   (_UINT32_(1) << 19) /**< PORT mask for PD19 */
#define PORT_PD20                   (_UINT32_(1) << 20) /**< PORT mask for PD20 */
#define PORT_PD21                   (_UINT32_(1) << 21) /**< PORT mask for PD21 */

/* ========== PORT definition for AC peripheral ========== */
#define PIN_PA06B_AC_AIN0                          _UINT32_(6) 
#define MUX_PA06B_AC_AIN0                          _UINT32_(1) 
#define PINMUX_PA06B_AC_AIN0                       ((PIN_PA06B_AC_AIN0 << 16) | MUX_PA06B_AC_AIN0)
#define PORT_PA06B_AC_AIN0                         (_UINT32_(1) << 6)

#define PIN_PA07B_AC_AIN1                          _UINT32_(7) 
#define MUX_PA07B_AC_AIN1                          _UINT32_(1) 
#define PINMUX_PA07B_AC_AIN1                       ((PIN_PA07B_AC_AIN1 << 16) | MUX_PA07B_AC_AIN1)
#define PORT_PA07B_AC_AIN1                         (_UINT32_(1) << 7)

#define PIN_PC06B_AC_AIN2                          _UINT32_(70)
#define MUX_PC06B_AC_AIN2                          _UINT32_(1) 
#define PINMUX_PC06B_AC_AIN2                       ((PIN_PC06B_AC_AIN2 << 16) | MUX_PC06B_AC_AIN2)
#define PORT_PC06B_AC_AIN2                         (_UINT32_(1) << 6)

#define PIN_PC07B_AC_AIN3                          _UINT32_(71)
#define MUX_PC07B_AC_AIN3                          _UINT32_(1) 
#define PINMUX_PC07B_AC_AIN3                       ((PIN_PC07B_AC_AIN3 << 16) | MUX_PC07B_AC_AIN3)
#define PORT_PC07B_AC_AIN3                         (_UINT32_(1) << 7)

#define PIN_PA11M_AC_CMP0                          _UINT32_(11)
#define MUX_PA11M_AC_CMP0                          _UINT32_(12)
#define PINMUX_PA11M_AC_CMP0                       ((PIN_PA11M_AC_CMP0 << 16) | MUX_PA11M_AC_CMP0)
#define PORT_PA11M_AC_CMP0                         (_UINT32_(1) << 11)

#define PIN_PC09M_AC_CMP0                          _UINT32_(73)
#define MUX_PC09M_AC_CMP0                          _UINT32_(12)
#define PINMUX_PC09M_AC_CMP0                       ((PIN_PC09M_AC_CMP0 << 16) | MUX_PC09M_AC_CMP0)
#define PORT_PC09M_AC_CMP0                         (_UINT32_(1) << 9)

#define PIN_PC21M_AC_CMP0                          _UINT32_(85)
#define MUX_PC21M_AC_CMP0                          _UINT32_(12)
#define PINMUX_PC21M_AC_CMP0                       ((PIN_PC21M_AC_CMP0 << 16) | MUX_PC21M_AC_CMP0)
#define PORT_PC21M_AC_CMP0                         (_UINT32_(1) << 21)

#define PIN_PA12M_AC_CMP1                          _UINT32_(12)
#define MUX_PA12M_AC_CMP1                          _UINT32_(12)
#define PINMUX_PA12M_AC_CMP1                       ((PIN_PA12M_AC_CMP1 << 16) | MUX_PA12M_AC_CMP1)
#define PORT_PA12M_AC_CMP1                         (_UINT32_(1) << 12)

#define PIN_PC15M_AC_CMP1                          _UINT32_(79)
#define MUX_PC15M_AC_CMP1                          _UINT32_(12)
#define PINMUX_PC15M_AC_CMP1                       ((PIN_PC15M_AC_CMP1 << 16) | MUX_PC15M_AC_CMP1)
#define PORT_PC15M_AC_CMP1                         (_UINT32_(1) << 15)

#define PIN_PC22M_AC_CMP1                          _UINT32_(86)
#define MUX_PC22M_AC_CMP1                          _UINT32_(12)
#define PINMUX_PC22M_AC_CMP1                       ((PIN_PC22M_AC_CMP1 << 16) | MUX_PC22M_AC_CMP1)
#define PORT_PC22M_AC_CMP1                         (_UINT32_(1) << 22)

/* ========== PORT definition for ADC peripheral ========== */
#define PIN_PA05B_ADC_VINM0                        _UINT32_(5) 
#define MUX_PA05B_ADC_VINM0                        _UINT32_(1) 
#define PINMUX_PA05B_ADC_VINM0                     ((PIN_PA05B_ADC_VINM0 << 16) | MUX_PA05B_ADC_VINM0)
#define PORT_PA05B_ADC_VINM0                       (_UINT32_(1) << 5)

#define PIN_PA07B_ADC_VINM2                        _UINT32_(7) 
#define MUX_PA07B_ADC_VINM2                        _UINT32_(1) 
#define PINMUX_PA07B_ADC_VINM2                     ((PIN_PA07B_ADC_VINM2 << 16) | MUX_PA07B_ADC_VINM2)
#define PORT_PA07B_ADC_VINM2                       (_UINT32_(1) << 7)

#define PIN_PA18B_ADC_VINM4                        _UINT32_(18)
#define MUX_PA18B_ADC_VINM4                        _UINT32_(1) 
#define PINMUX_PA18B_ADC_VINM4                     ((PIN_PA18B_ADC_VINM4 << 16) | MUX_PA18B_ADC_VINM4)
#define PORT_PA18B_ADC_VINM4                       (_UINT32_(1) << 18)

#define PIN_PA04B_ADC_VINP0                        _UINT32_(4) 
#define MUX_PA04B_ADC_VINP0                        _UINT32_(1) 
#define PINMUX_PA04B_ADC_VINP0                     ((PIN_PA04B_ADC_VINP0 << 16) | MUX_PA04B_ADC_VINP0)
#define PORT_PA04B_ADC_VINP0                       (_UINT32_(1) << 4)

#define PIN_PA05B_ADC_VINP1                        _UINT32_(5) 
#define MUX_PA05B_ADC_VINP1                        _UINT32_(1) 
#define PINMUX_PA05B_ADC_VINP1                     ((PIN_PA05B_ADC_VINP1 << 16) | MUX_PA05B_ADC_VINP1)
#define PORT_PA05B_ADC_VINP1                       (_UINT32_(1) << 5)

#define PIN_PA06B_ADC_VINP2                        _UINT32_(6) 
#define MUX_PA06B_ADC_VINP2                        _UINT32_(1) 
#define PINMUX_PA06B_ADC_VINP2                     ((PIN_PA06B_ADC_VINP2 << 16) | MUX_PA06B_ADC_VINP2)
#define PORT_PA06B_ADC_VINP2                       (_UINT32_(1) << 6)

#define PIN_PA07B_ADC_VINP3                        _UINT32_(7) 
#define MUX_PA07B_ADC_VINP3                        _UINT32_(1) 
#define PINMUX_PA07B_ADC_VINP3                     ((PIN_PA07B_ADC_VINP3 << 16) | MUX_PA07B_ADC_VINP3)
#define PORT_PA07B_ADC_VINP3                       (_UINT32_(1) << 7)

#define PIN_PA08B_ADC_VINP4                        _UINT32_(8) 
#define MUX_PA08B_ADC_VINP4                        _UINT32_(1) 
#define PINMUX_PA08B_ADC_VINP4                     ((PIN_PA08B_ADC_VINP4 << 16) | MUX_PA08B_ADC_VINP4)
#define PORT_PA08B_ADC_VINP4                       (_UINT32_(1) << 8)

#define PIN_PA09B_ADC_VINP5                        _UINT32_(9) 
#define MUX_PA09B_ADC_VINP5                        _UINT32_(1) 
#define PINMUX_PA09B_ADC_VINP5                     ((PIN_PA09B_ADC_VINP5 << 16) | MUX_PA09B_ADC_VINP5)
#define PORT_PA09B_ADC_VINP5                       (_UINT32_(1) << 9)

#define PIN_PA10B_ADC_VINP6                        _UINT32_(10)
#define MUX_PA10B_ADC_VINP6                        _UINT32_(1) 
#define PINMUX_PA10B_ADC_VINP6                     ((PIN_PA10B_ADC_VINP6 << 16) | MUX_PA10B_ADC_VINP6)
#define PORT_PA10B_ADC_VINP6                       (_UINT32_(1) << 10)

#define PIN_PA11B_ADC_VINP7                        _UINT32_(11)
#define MUX_PA11B_ADC_VINP7                        _UINT32_(1) 
#define PINMUX_PA11B_ADC_VINP7                     ((PIN_PA11B_ADC_VINP7 << 16) | MUX_PA11B_ADC_VINP7)
#define PORT_PA11B_ADC_VINP7                       (_UINT32_(1) << 11)

#define PIN_PA12B_ADC_VINP8                        _UINT32_(12)
#define MUX_PA12B_ADC_VINP8                        _UINT32_(1) 
#define PINMUX_PA12B_ADC_VINP8                     ((PIN_PA12B_ADC_VINP8 << 16) | MUX_PA12B_ADC_VINP8)
#define PORT_PA12B_ADC_VINP8                       (_UINT32_(1) << 12)

#define PIN_PB00B_ADC_VINP9                        _UINT32_(32)
#define MUX_PB00B_ADC_VINP9                        _UINT32_(1) 
#define PINMUX_PB00B_ADC_VINP9                     ((PIN_PB00B_ADC_VINP9 << 16) | MUX_PB00B_ADC_VINP9)
#define PORT_PB00B_ADC_VINP9                       (_UINT32_(1) << 0)

#define PIN_PB11B_ADC_VINP10                       _UINT32_(43)
#define MUX_PB11B_ADC_VINP10                       _UINT32_(1) 
#define PINMUX_PB11B_ADC_VINP10                    ((PIN_PB11B_ADC_VINP10 << 16) | MUX_PB11B_ADC_VINP10)
#define PORT_PB11B_ADC_VINP10                      (_UINT32_(1) << 11)

#define PIN_PB12B_ADC_VINP11                       _UINT32_(44)
#define MUX_PB12B_ADC_VINP11                       _UINT32_(1) 
#define PINMUX_PB12B_ADC_VINP11                    ((PIN_PB12B_ADC_VINP11 << 16) | MUX_PB12B_ADC_VINP11)
#define PORT_PB12B_ADC_VINP11                      (_UINT32_(1) << 12)

#define PIN_PB01B_ADC_VREFP0                       _UINT32_(33)
#define MUX_PB01B_ADC_VREFP0                       _UINT32_(1) 
#define PINMUX_PB01B_ADC_VREFP0                    ((PIN_PB01B_ADC_VREFP0 << 16) | MUX_PB01B_ADC_VREFP0)
#define PORT_PB01B_ADC_VREFP0                      (_UINT32_(1) << 1)

/* ========== PORT definition for CAN0 peripheral ========== */
#define PIN_PB09H_CAN0_RX                          _UINT32_(41)
#define MUX_PB09H_CAN0_RX                          _UINT32_(7) 
#define PINMUX_PB09H_CAN0_RX                       ((PIN_PB09H_CAN0_RX << 16) | MUX_PB09H_CAN0_RX)
#define PORT_PB09H_CAN0_RX                         (_UINT32_(1) << 9)

#define PIN_PB17H_CAN0_RX                          _UINT32_(49)
#define MUX_PB17H_CAN0_RX                          _UINT32_(7) 
#define PINMUX_PB17H_CAN0_RX                       ((PIN_PB17H_CAN0_RX << 16) | MUX_PB17H_CAN0_RX)
#define PORT_PB17H_CAN0_RX                         (_UINT32_(1) << 17)

#define PIN_PB22H_CAN0_RX                          _UINT32_(54)
#define MUX_PB22H_CAN0_RX                          _UINT32_(7) 
#define PINMUX_PB22H_CAN0_RX                       ((PIN_PB22H_CAN0_RX << 16) | MUX_PB22H_CAN0_RX)
#define PORT_PB22H_CAN0_RX                         (_UINT32_(1) << 22)

#define PIN_PC03H_CAN0_RX                          _UINT32_(67)
#define MUX_PC03H_CAN0_RX                          _UINT32_(7) 
#define PINMUX_PC03H_CAN0_RX                       ((PIN_PC03H_CAN0_RX << 16) | MUX_PC03H_CAN0_RX)
#define PORT_PC03H_CAN0_RX                         (_UINT32_(1) << 3)

#define PIN_PD19H_CAN0_RX                          _UINT32_(115)
#define MUX_PD19H_CAN0_RX                          _UINT32_(7) 
#define PINMUX_PD19H_CAN0_RX                       ((PIN_PD19H_CAN0_RX << 16) | MUX_PD19H_CAN0_RX)
#define PORT_PD19H_CAN0_RX                         (_UINT32_(1) << 19)

#define PIN_PB08H_CAN0_TX                          _UINT32_(40)
#define MUX_PB08H_CAN0_TX                          _UINT32_(7) 
#define PINMUX_PB08H_CAN0_TX                       ((PIN_PB08H_CAN0_TX << 16) | MUX_PB08H_CAN0_TX)
#define PORT_PB08H_CAN0_TX                         (_UINT32_(1) << 8)

#define PIN_PB16H_CAN0_TX                          _UINT32_(48)
#define MUX_PB16H_CAN0_TX                          _UINT32_(7) 
#define PINMUX_PB16H_CAN0_TX                       ((PIN_PB16H_CAN0_TX << 16) | MUX_PB16H_CAN0_TX)
#define PORT_PB16H_CAN0_TX                         (_UINT32_(1) << 16)

#define PIN_PB21H_CAN0_TX                          _UINT32_(53)
#define MUX_PB21H_CAN0_TX                          _UINT32_(7) 
#define PINMUX_PB21H_CAN0_TX                       ((PIN_PB21H_CAN0_TX << 16) | MUX_PB21H_CAN0_TX)
#define PORT_PB21H_CAN0_TX                         (_UINT32_(1) << 21)

#define PIN_PC02H_CAN0_TX                          _UINT32_(66)
#define MUX_PC02H_CAN0_TX                          _UINT32_(7) 
#define PINMUX_PC02H_CAN0_TX                       ((PIN_PC02H_CAN0_TX << 16) | MUX_PC02H_CAN0_TX)
#define PORT_PC02H_CAN0_TX                         (_UINT32_(1) << 2)

#define PIN_PD18H_CAN0_TX                          _UINT32_(114)
#define MUX_PD18H_CAN0_TX                          _UINT32_(7) 
#define PINMUX_PD18H_CAN0_TX                       ((PIN_PD18H_CAN0_TX << 16) | MUX_PD18H_CAN0_TX)
#define PORT_PD18H_CAN0_TX                         (_UINT32_(1) << 18)

/* ========== PORT definition for CAN1 peripheral ========== */
#define PIN_PB01H_CAN1_RX                          _UINT32_(33)
#define MUX_PB01H_CAN1_RX                          _UINT32_(7) 
#define PINMUX_PB01H_CAN1_RX                       ((PIN_PB01H_CAN1_RX << 16) | MUX_PB01H_CAN1_RX)
#define PORT_PB01H_CAN1_RX                         (_UINT32_(1) << 1)

#define PIN_PB24H_CAN1_RX                          _UINT32_(56)
#define MUX_PB24H_CAN1_RX                          _UINT32_(7) 
#define PINMUX_PB24H_CAN1_RX                       ((PIN_PB24H_CAN1_RX << 16) | MUX_PB24H_CAN1_RX)
#define PORT_PB24H_CAN1_RX                         (_UINT32_(1) << 24)

#define PIN_PC07H_CAN1_RX                          _UINT32_(71)
#define MUX_PC07H_CAN1_RX                          _UINT32_(7) 
#define PINMUX_PC07H_CAN1_RX                       ((PIN_PC07H_CAN1_RX << 16) | MUX_PC07H_CAN1_RX)
#define PORT_PC07H_CAN1_RX                         (_UINT32_(1) << 7)

#define PIN_PD21H_CAN1_RX                          _UINT32_(117)
#define MUX_PD21H_CAN1_RX                          _UINT32_(7) 
#define PINMUX_PD21H_CAN1_RX                       ((PIN_PD21H_CAN1_RX << 16) | MUX_PD21H_CAN1_RX)
#define PORT_PD21H_CAN1_RX                         (_UINT32_(1) << 21)

#define PIN_PB00H_CAN1_TX                          _UINT32_(32)
#define MUX_PB00H_CAN1_TX                          _UINT32_(7) 
#define PINMUX_PB00H_CAN1_TX                       ((PIN_PB00H_CAN1_TX << 16) | MUX_PB00H_CAN1_TX)
#define PORT_PB00H_CAN1_TX                         (_UINT32_(1) << 0)

#define PIN_PB23H_CAN1_TX                          _UINT32_(55)
#define MUX_PB23H_CAN1_TX                          _UINT32_(7) 
#define PINMUX_PB23H_CAN1_TX                       ((PIN_PB23H_CAN1_TX << 16) | MUX_PB23H_CAN1_TX)
#define PORT_PB23H_CAN1_TX                         (_UINT32_(1) << 23)

#define PIN_PC06H_CAN1_TX                          _UINT32_(70)
#define MUX_PC06H_CAN1_TX                          _UINT32_(7) 
#define PINMUX_PC06H_CAN1_TX                       ((PIN_PC06H_CAN1_TX << 16) | MUX_PC06H_CAN1_TX)
#define PORT_PC06H_CAN1_TX                         (_UINT32_(1) << 6)

#define PIN_PD20H_CAN1_TX                          _UINT32_(116)
#define MUX_PD20H_CAN1_TX                          _UINT32_(7) 
#define PINMUX_PD20H_CAN1_TX                       ((PIN_PD20H_CAN1_TX << 16) | MUX_PD20H_CAN1_TX)
#define PORT_PD20H_CAN1_TX                         (_UINT32_(1) << 20)

/* ========== PORT definition for CCL peripheral ========== */
#define PIN_PB07M_CCL_IN0                          _UINT32_(39)
#define MUX_PB07M_CCL_IN0                          _UINT32_(12)
#define PINMUX_PB07M_CCL_IN0                       ((PIN_PB07M_CCL_IN0 << 16) | MUX_PB07M_CCL_IN0)
#define PORT_PB07M_CCL_IN0                         (_UINT32_(1) << 7)

#define PIN_PB22M_CCL_IN0                          _UINT32_(54)
#define MUX_PB22M_CCL_IN0                          _UINT32_(12)
#define PINMUX_PB22M_CCL_IN0                       ((PIN_PB22M_CCL_IN0 << 16) | MUX_PB22M_CCL_IN0)
#define PORT_PB22M_CCL_IN0                         (_UINT32_(1) << 22)

#define PIN_PB08M_CCL_IN1                          _UINT32_(40)
#define MUX_PB08M_CCL_IN1                          _UINT32_(12)
#define PINMUX_PB08M_CCL_IN1                       ((PIN_PB08M_CCL_IN1 << 16) | MUX_PB08M_CCL_IN1)
#define PORT_PB08M_CCL_IN1                         (_UINT32_(1) << 8)

#define PIN_PB23M_CCL_IN1                          _UINT32_(55)
#define MUX_PB23M_CCL_IN1                          _UINT32_(12)
#define PINMUX_PB23M_CCL_IN1                       ((PIN_PB23M_CCL_IN1 << 16) | MUX_PB23M_CCL_IN1)
#define PORT_PB23M_CCL_IN1                         (_UINT32_(1) << 23)

#define PIN_PB09M_CCL_IN2                          _UINT32_(41)
#define MUX_PB09M_CCL_IN2                          _UINT32_(12)
#define PINMUX_PB09M_CCL_IN2                       ((PIN_PB09M_CCL_IN2 << 16) | MUX_PB09M_CCL_IN2)
#define PORT_PB09M_CCL_IN2                         (_UINT32_(1) << 9)

#define PIN_PB24M_CCL_IN2                          _UINT32_(56)
#define MUX_PB24M_CCL_IN2                          _UINT32_(12)
#define PINMUX_PB24M_CCL_IN2                       ((PIN_PB24M_CCL_IN2 << 16) | MUX_PB24M_CCL_IN2)
#define PORT_PB24M_CCL_IN2                         (_UINT32_(1) << 24)

#define PIN_PC10M_CCL_IN3                          _UINT32_(74)
#define MUX_PC10M_CCL_IN3                          _UINT32_(12)
#define PINMUX_PC10M_CCL_IN3                       ((PIN_PC10M_CCL_IN3 << 16) | MUX_PC10M_CCL_IN3)
#define PORT_PC10M_CCL_IN3                         (_UINT32_(1) << 10)

#define PIN_PC24M_CCL_IN3                          _UINT32_(88)
#define MUX_PC24M_CCL_IN3                          _UINT32_(12)
#define PINMUX_PC24M_CCL_IN3                       ((PIN_PC24M_CCL_IN3 << 16) | MUX_PC24M_CCL_IN3)
#define PORT_PC24M_CCL_IN3                         (_UINT32_(1) << 24)

#define PIN_PC11M_CCL_IN4                          _UINT32_(75)
#define MUX_PC11M_CCL_IN4                          _UINT32_(12)
#define PINMUX_PC11M_CCL_IN4                       ((PIN_PC11M_CCL_IN4 << 16) | MUX_PC11M_CCL_IN4)
#define PORT_PC11M_CCL_IN4                         (_UINT32_(1) << 11)

#define PIN_PC25M_CCL_IN4                          _UINT32_(89)
#define MUX_PC25M_CCL_IN4                          _UINT32_(12)
#define PINMUX_PC25M_CCL_IN4                       ((PIN_PC25M_CCL_IN4 << 16) | MUX_PC25M_CCL_IN4)
#define PORT_PC25M_CCL_IN4                         (_UINT32_(1) << 25)

#define PIN_PC12M_CCL_IN5                          _UINT32_(76)
#define MUX_PC12M_CCL_IN5                          _UINT32_(12)
#define PINMUX_PC12M_CCL_IN5                       ((PIN_PC12M_CCL_IN5 << 16) | MUX_PC12M_CCL_IN5)
#define PORT_PC12M_CCL_IN5                         (_UINT32_(1) << 12)

#define PIN_PC26M_CCL_IN5                          _UINT32_(90)
#define MUX_PC26M_CCL_IN5                          _UINT32_(12)
#define PINMUX_PC26M_CCL_IN5                       ((PIN_PC26M_CCL_IN5 << 16) | MUX_PC26M_CCL_IN5)
#define PORT_PC26M_CCL_IN5                         (_UINT32_(1) << 26)

#define PIN_PD08M_CCL_IN6                          _UINT32_(104)
#define MUX_PD08M_CCL_IN6                          _UINT32_(12)
#define PINMUX_PD08M_CCL_IN6                       ((PIN_PD08M_CCL_IN6 << 16) | MUX_PD08M_CCL_IN6)
#define PORT_PD08M_CCL_IN6                         (_UINT32_(1) << 8)

#define PIN_PD17M_CCL_IN6                          _UINT32_(113)
#define MUX_PD17M_CCL_IN6                          _UINT32_(12)
#define PINMUX_PD17M_CCL_IN6                       ((PIN_PD17M_CCL_IN6 << 16) | MUX_PD17M_CCL_IN6)
#define PORT_PD17M_CCL_IN6                         (_UINT32_(1) << 17)

#define PIN_PD09M_CCL_IN7                          _UINT32_(105)
#define MUX_PD09M_CCL_IN7                          _UINT32_(12)
#define PINMUX_PD09M_CCL_IN7                       ((PIN_PD09M_CCL_IN7 << 16) | MUX_PD09M_CCL_IN7)
#define PORT_PD09M_CCL_IN7                         (_UINT32_(1) << 9)

#define PIN_PD18M_CCL_IN7                          _UINT32_(114)
#define MUX_PD18M_CCL_IN7                          _UINT32_(12)
#define PINMUX_PD18M_CCL_IN7                       ((PIN_PD18M_CCL_IN7 << 16) | MUX_PD18M_CCL_IN7)
#define PORT_PD18M_CCL_IN7                         (_UINT32_(1) << 18)

#define PIN_PD10M_CCL_IN8                          _UINT32_(106)
#define MUX_PD10M_CCL_IN8                          _UINT32_(12)
#define PINMUX_PD10M_CCL_IN8                       ((PIN_PD10M_CCL_IN8 << 16) | MUX_PD10M_CCL_IN8)
#define PORT_PD10M_CCL_IN8                         (_UINT32_(1) << 10)

#define PIN_PD19M_CCL_IN8                          _UINT32_(115)
#define MUX_PD19M_CCL_IN8                          _UINT32_(12)
#define PINMUX_PD19M_CCL_IN8                       ((PIN_PD19M_CCL_IN8 << 16) | MUX_PD19M_CCL_IN8)
#define PORT_PD19M_CCL_IN8                         (_UINT32_(1) << 19)

#define PIN_PA04M_CCL_IN9                          _UINT32_(4) 
#define MUX_PA04M_CCL_IN9                          _UINT32_(12)
#define PINMUX_PA04M_CCL_IN9                       ((PIN_PA04M_CCL_IN9 << 16) | MUX_PA04M_CCL_IN9)
#define PORT_PA04M_CCL_IN9                         (_UINT32_(1) << 4)

#define PIN_PA13M_CCL_IN9                          _UINT32_(13)
#define MUX_PA13M_CCL_IN9                          _UINT32_(12)
#define PINMUX_PA13M_CCL_IN9                       ((PIN_PA13M_CCL_IN9 << 16) | MUX_PA13M_CCL_IN9)
#define PORT_PA13M_CCL_IN9                         (_UINT32_(1) << 13)

#define PIN_PA05M_CCL_IN10                         _UINT32_(5) 
#define MUX_PA05M_CCL_IN10                         _UINT32_(12)
#define PINMUX_PA05M_CCL_IN10                      ((PIN_PA05M_CCL_IN10 << 16) | MUX_PA05M_CCL_IN10)
#define PORT_PA05M_CCL_IN10                        (_UINT32_(1) << 5)

#define PIN_PA14M_CCL_IN10                         _UINT32_(14)
#define MUX_PA14M_CCL_IN10                         _UINT32_(12)
#define PINMUX_PA14M_CCL_IN10                      ((PIN_PA14M_CCL_IN10 << 16) | MUX_PA14M_CCL_IN10)
#define PORT_PA14M_CCL_IN10                        (_UINT32_(1) << 14)

#define PIN_PA06M_CCL_IN11                         _UINT32_(6) 
#define MUX_PA06M_CCL_IN11                         _UINT32_(12)
#define PINMUX_PA06M_CCL_IN11                      ((PIN_PA06M_CCL_IN11 << 16) | MUX_PA06M_CCL_IN11)
#define PORT_PA06M_CCL_IN11                        (_UINT32_(1) << 6)

#define PIN_PA15M_CCL_IN11                         _UINT32_(15)
#define MUX_PA15M_CCL_IN11                         _UINT32_(12)
#define PINMUX_PA15M_CCL_IN11                      ((PIN_PA15M_CCL_IN11 << 16) | MUX_PA15M_CCL_IN11)
#define PORT_PA15M_CCL_IN11                        (_UINT32_(1) << 15)

#define PIN_PB10M_CCL_OUT0                         _UINT32_(42)
#define MUX_PB10M_CCL_OUT0                         _UINT32_(12)
#define PINMUX_PB10M_CCL_OUT0                      ((PIN_PB10M_CCL_OUT0 << 16) | MUX_PB10M_CCL_OUT0)
#define PORT_PB10M_CCL_OUT0                        (_UINT32_(1) << 10)

#define PIN_PB25M_CCL_OUT0                         _UINT32_(57)
#define MUX_PB25M_CCL_OUT0                         _UINT32_(12)
#define PINMUX_PB25M_CCL_OUT0                      ((PIN_PB25M_CCL_OUT0 << 16) | MUX_PB25M_CCL_OUT0)
#define PORT_PB25M_CCL_OUT0                        (_UINT32_(1) << 25)

#define PIN_PC13M_CCL_OUT1                         _UINT32_(77)
#define MUX_PC13M_CCL_OUT1                         _UINT32_(12)
#define PINMUX_PC13M_CCL_OUT1                      ((PIN_PC13M_CCL_OUT1 << 16) | MUX_PC13M_CCL_OUT1)
#define PORT_PC13M_CCL_OUT1                        (_UINT32_(1) << 13)

#define PIN_PC27M_CCL_OUT1                         _UINT32_(91)
#define MUX_PC27M_CCL_OUT1                         _UINT32_(12)
#define PINMUX_PC27M_CCL_OUT1                      ((PIN_PC27M_CCL_OUT1 << 16) | MUX_PC27M_CCL_OUT1)
#define PORT_PC27M_CCL_OUT1                        (_UINT32_(1) << 27)

#define PIN_PD11M_CCL_OUT2                         _UINT32_(107)
#define MUX_PD11M_CCL_OUT2                         _UINT32_(12)
#define PINMUX_PD11M_CCL_OUT2                      ((PIN_PD11M_CCL_OUT2 << 16) | MUX_PD11M_CCL_OUT2)
#define PORT_PD11M_CCL_OUT2                        (_UINT32_(1) << 11)

#define PIN_PD20M_CCL_OUT2                         _UINT32_(116)
#define MUX_PD20M_CCL_OUT2                         _UINT32_(12)
#define PINMUX_PD20M_CCL_OUT2                      ((PIN_PD20M_CCL_OUT2 << 16) | MUX_PD20M_CCL_OUT2)
#define PORT_PD20M_CCL_OUT2                        (_UINT32_(1) << 20)

#define PIN_PA07M_CCL_OUT3                         _UINT32_(7) 
#define MUX_PA07M_CCL_OUT3                         _UINT32_(12)
#define PINMUX_PA07M_CCL_OUT3                      ((PIN_PA07M_CCL_OUT3 << 16) | MUX_PA07M_CCL_OUT3)
#define PORT_PA07M_CCL_OUT3                        (_UINT32_(1) << 7)

#define PIN_PA16M_CCL_OUT3                         _UINT32_(16)
#define MUX_PA16M_CCL_OUT3                         _UINT32_(12)
#define PINMUX_PA16M_CCL_OUT3                      ((PIN_PA16M_CCL_OUT3 << 16) | MUX_PA16M_CCL_OUT3)
#define PORT_PA16M_CCL_OUT3                        (_UINT32_(1) << 16)

/* ========== PORT definition for EBI peripheral ========== */
#define PIN_PC19E_EBI_A2                           _UINT32_(83)
#define MUX_PC19E_EBI_A2                           _UINT32_(4) 
#define PINMUX_PC19E_EBI_A2                        ((PIN_PC19E_EBI_A2 << 16) | MUX_PC19E_EBI_A2)
#define PORT_PC19E_EBI_A2                          (_UINT32_(1) << 19)

#define PIN_PC18E_EBI_A3                           _UINT32_(82)
#define MUX_PC18E_EBI_A3                           _UINT32_(4) 
#define PINMUX_PC18E_EBI_A3                        ((PIN_PC18E_EBI_A3 << 16) | MUX_PC18E_EBI_A3)
#define PORT_PC18E_EBI_A3                          (_UINT32_(1) << 18)

#define PIN_PC17E_EBI_A4                           _UINT32_(81)
#define MUX_PC17E_EBI_A4                           _UINT32_(4) 
#define PINMUX_PC17E_EBI_A4                        ((PIN_PC17E_EBI_A4 << 16) | MUX_PC17E_EBI_A4)
#define PORT_PC17E_EBI_A4                          (_UINT32_(1) << 17)

#define PIN_PC16E_EBI_A5                           _UINT32_(80)
#define MUX_PC16E_EBI_A5                           _UINT32_(4) 
#define PINMUX_PC16E_EBI_A5                        ((PIN_PC16E_EBI_A5 << 16) | MUX_PC16E_EBI_A5)
#define PORT_PC16E_EBI_A5                          (_UINT32_(1) << 16)

#define PIN_PC15E_EBI_A6                           _UINT32_(79)
#define MUX_PC15E_EBI_A6                           _UINT32_(4) 
#define PINMUX_PC15E_EBI_A6                        ((PIN_PC15E_EBI_A6 << 16) | MUX_PC15E_EBI_A6)
#define PORT_PC15E_EBI_A6                          (_UINT32_(1) << 15)

#define PIN_PC05E_EBI_A7                           _UINT32_(69)
#define MUX_PC05E_EBI_A7                           _UINT32_(4) 
#define PINMUX_PC05E_EBI_A7                        ((PIN_PC05E_EBI_A7 << 16) | MUX_PC05E_EBI_A7)
#define PORT_PC05E_EBI_A7                          (_UINT32_(1) << 5)

#define PIN_PC14E_EBI_A8                           _UINT32_(78)
#define MUX_PC14E_EBI_A8                           _UINT32_(4) 
#define PINMUX_PC14E_EBI_A8                        ((PIN_PC14E_EBI_A8 << 16) | MUX_PC14E_EBI_A8)
#define PORT_PC14E_EBI_A8                          (_UINT32_(1) << 14)

#define PIN_PC04E_EBI_A9                           _UINT32_(68)
#define MUX_PC04E_EBI_A9                           _UINT32_(4) 
#define PINMUX_PC04E_EBI_A9                        ((PIN_PC04E_EBI_A9 << 16) | MUX_PC04E_EBI_A9)
#define PORT_PC04E_EBI_A9                          (_UINT32_(1) << 4)

#define PIN_PC03E_EBI_A10                          _UINT32_(67)
#define MUX_PC03E_EBI_A10                          _UINT32_(4) 
#define PINMUX_PC03E_EBI_A10                       ((PIN_PC03E_EBI_A10 << 16) | MUX_PC03E_EBI_A10)
#define PORT_PC03E_EBI_A10                         (_UINT32_(1) << 3)

#define PIN_PC02E_EBI_A11                          _UINT32_(66)
#define MUX_PC02E_EBI_A11                          _UINT32_(4) 
#define PINMUX_PC02E_EBI_A11                       ((PIN_PC02E_EBI_A11 << 16) | MUX_PC02E_EBI_A11)
#define PORT_PC02E_EBI_A11                         (_UINT32_(1) << 2)

#define PIN_PC01E_EBI_A12                          _UINT32_(65)
#define MUX_PC01E_EBI_A12                          _UINT32_(4) 
#define PINMUX_PC01E_EBI_A12                       ((PIN_PC01E_EBI_A12 << 16) | MUX_PC01E_EBI_A12)
#define PORT_PC01E_EBI_A12                         (_UINT32_(1) << 1)

#define PIN_PC00E_EBI_A13                          _UINT32_(64)
#define MUX_PC00E_EBI_A13                          _UINT32_(4) 
#define PINMUX_PC00E_EBI_A13                       ((PIN_PC00E_EBI_A13 << 16) | MUX_PC00E_EBI_A13)
#define PORT_PC00E_EBI_A13                         (_UINT32_(1) << 0)

#define PIN_PB10E_EBI_A14                          _UINT32_(42)
#define MUX_PB10E_EBI_A14                          _UINT32_(4) 
#define PINMUX_PB10E_EBI_A14                       ((PIN_PB10E_EBI_A14 << 16) | MUX_PB10E_EBI_A14)
#define PORT_PB10E_EBI_A14                         (_UINT32_(1) << 10)

#define PIN_PB09E_EBI_A15                          _UINT32_(41)
#define MUX_PB09E_EBI_A15                          _UINT32_(4) 
#define PINMUX_PB09E_EBI_A15                       ((PIN_PB09E_EBI_A15 << 16) | MUX_PB09E_EBI_A15)
#define PORT_PB09E_EBI_A15                         (_UINT32_(1) << 9)

#define PIN_PC27E_EBI_A16                          _UINT32_(91)
#define MUX_PC27E_EBI_A16                          _UINT32_(4) 
#define PINMUX_PC27E_EBI_A16                       ((PIN_PC27E_EBI_A16 << 16) | MUX_PC27E_EBI_A16)
#define PORT_PC27E_EBI_A16                         (_UINT32_(1) << 27)

#define PIN_PD08E_EBI_A16                          _UINT32_(104)
#define MUX_PD08E_EBI_A16                          _UINT32_(4) 
#define PINMUX_PD08E_EBI_A16                       ((PIN_PD08E_EBI_A16 << 16) | MUX_PD08E_EBI_A16)
#define PORT_PD08E_EBI_A16                         (_UINT32_(1) << 8)

#define PIN_PC26E_EBI_A17                          _UINT32_(90)
#define MUX_PC26E_EBI_A17                          _UINT32_(4) 
#define PINMUX_PC26E_EBI_A17                       ((PIN_PC26E_EBI_A17 << 16) | MUX_PC26E_EBI_A17)
#define PORT_PC26E_EBI_A17                         (_UINT32_(1) << 26)

#define PIN_PD07E_EBI_A17                          _UINT32_(103)
#define MUX_PD07E_EBI_A17                          _UINT32_(4) 
#define PINMUX_PD07E_EBI_A17                       ((PIN_PD07E_EBI_A17 << 16) | MUX_PD07E_EBI_A17)
#define PORT_PD07E_EBI_A17                         (_UINT32_(1) << 7)

#define PIN_PB25E_EBI_A18                          _UINT32_(57)
#define MUX_PB25E_EBI_A18                          _UINT32_(4) 
#define PINMUX_PB25E_EBI_A18                       ((PIN_PB25E_EBI_A18 << 16) | MUX_PB25E_EBI_A18)
#define PORT_PB25E_EBI_A18                         (_UINT32_(1) << 25)

#define PIN_PD06E_EBI_A18                          _UINT32_(102)
#define MUX_PD06E_EBI_A18                          _UINT32_(4) 
#define PINMUX_PD06E_EBI_A18                       ((PIN_PD06E_EBI_A18 << 16) | MUX_PD06E_EBI_A18)
#define PORT_PD06E_EBI_A18                         (_UINT32_(1) << 6)

#define PIN_PB24E_EBI_A19                          _UINT32_(56)
#define MUX_PB24E_EBI_A19                          _UINT32_(4) 
#define PINMUX_PB24E_EBI_A19                       ((PIN_PB24E_EBI_A19 << 16) | MUX_PB24E_EBI_A19)
#define PORT_PB24E_EBI_A19                         (_UINT32_(1) << 24)

#define PIN_PD02E_EBI_A19                          _UINT32_(98)
#define MUX_PD02E_EBI_A19                          _UINT32_(4) 
#define PINMUX_PD02E_EBI_A19                       ((PIN_PD02E_EBI_A19 << 16) | MUX_PD02E_EBI_A19)
#define PORT_PD02E_EBI_A19                         (_UINT32_(1) << 2)

#define PIN_PB23E_EBI_A20                          _UINT32_(55)
#define MUX_PB23E_EBI_A20                          _UINT32_(4) 
#define PINMUX_PB23E_EBI_A20                       ((PIN_PB23E_EBI_A20 << 16) | MUX_PB23E_EBI_A20)
#define PORT_PB23E_EBI_A20                         (_UINT32_(1) << 23)

#define PIN_PB22E_EBI_A21                          _UINT32_(54)
#define MUX_PB22E_EBI_A21                          _UINT32_(4) 
#define PINMUX_PB22E_EBI_A21                       ((PIN_PB22E_EBI_A21 << 16) | MUX_PB22E_EBI_A21)
#define PORT_PB22E_EBI_A21                         (_UINT32_(1) << 22)

#define PIN_PB21E_EBI_A22                          _UINT32_(53)
#define MUX_PB21E_EBI_A22                          _UINT32_(4) 
#define PINMUX_PB21E_EBI_A22                       ((PIN_PB21E_EBI_A22 << 16) | MUX_PB21E_EBI_A22)
#define PORT_PB21E_EBI_A22                         (_UINT32_(1) << 21)

#define PIN_PC28E_EBI_A23                          _UINT32_(92)
#define MUX_PC28E_EBI_A23                          _UINT32_(4) 
#define PINMUX_PC28E_EBI_A23                       ((PIN_PC28E_EBI_A23 << 16) | MUX_PC28E_EBI_A23)
#define PORT_PC28E_EBI_A23                         (_UINT32_(1) << 28)

#define PIN_PA13E_EBI_D0                           _UINT32_(13)
#define MUX_PA13E_EBI_D0                           _UINT32_(4) 
#define PINMUX_PA13E_EBI_D0                        ((PIN_PA13E_EBI_D0 << 16) | MUX_PA13E_EBI_D0)
#define PORT_PA13E_EBI_D0                          (_UINT32_(1) << 13)

#define PIN_PA14E_EBI_D1                           _UINT32_(14)
#define MUX_PA14E_EBI_D1                           _UINT32_(4) 
#define PINMUX_PA14E_EBI_D1                        ((PIN_PA14E_EBI_D1 << 16) | MUX_PA14E_EBI_D1)
#define PORT_PA14E_EBI_D1                          (_UINT32_(1) << 14)

#define PIN_PA15E_EBI_D2                           _UINT32_(15)
#define MUX_PA15E_EBI_D2                           _UINT32_(4) 
#define PINMUX_PA15E_EBI_D2                        ((PIN_PA15E_EBI_D2 << 16) | MUX_PA15E_EBI_D2)
#define PORT_PA15E_EBI_D2                          (_UINT32_(1) << 15)

#define PIN_PA16E_EBI_D3                           _UINT32_(16)
#define MUX_PA16E_EBI_D3                           _UINT32_(4) 
#define PINMUX_PA16E_EBI_D3                        ((PIN_PA16E_EBI_D3 << 16) | MUX_PA16E_EBI_D3)
#define PORT_PA16E_EBI_D3                          (_UINT32_(1) << 16)

#define PIN_PA17E_EBI_D4                           _UINT32_(17)
#define MUX_PA17E_EBI_D4                           _UINT32_(4) 
#define PINMUX_PA17E_EBI_D4                        ((PIN_PA17E_EBI_D4 << 16) | MUX_PA17E_EBI_D4)
#define PORT_PA17E_EBI_D4                          (_UINT32_(1) << 17)

#define PIN_PA04E_EBI_D5                           _UINT32_(4) 
#define MUX_PA04E_EBI_D5                           _UINT32_(4) 
#define PINMUX_PA04E_EBI_D5                        ((PIN_PA04E_EBI_D5 << 16) | MUX_PA04E_EBI_D5)
#define PORT_PA04E_EBI_D5                          (_UINT32_(1) << 4)

#define PIN_PA05E_EBI_D6                           _UINT32_(5) 
#define MUX_PA05E_EBI_D6                           _UINT32_(4) 
#define PINMUX_PA05E_EBI_D6                        ((PIN_PA05E_EBI_D6 << 16) | MUX_PA05E_EBI_D6)
#define PORT_PA05E_EBI_D6                          (_UINT32_(1) << 5)

#define PIN_PA06E_EBI_D7                           _UINT32_(6) 
#define MUX_PA06E_EBI_D7                           _UINT32_(4) 
#define PINMUX_PA06E_EBI_D7                        ((PIN_PA06E_EBI_D7 << 16) | MUX_PA06E_EBI_D7)
#define PORT_PA06E_EBI_D7                          (_UINT32_(1) << 6)

#define PIN_PA07E_EBI_D8                           _UINT32_(7) 
#define MUX_PA07E_EBI_D8                           _UINT32_(4) 
#define PINMUX_PA07E_EBI_D8                        ((PIN_PA07E_EBI_D8 << 16) | MUX_PA07E_EBI_D8)
#define PORT_PA07E_EBI_D8                          (_UINT32_(1) << 7)

#define PIN_PA08E_EBI_D9                           _UINT32_(8) 
#define MUX_PA08E_EBI_D9                           _UINT32_(4) 
#define PINMUX_PA08E_EBI_D9                        ((PIN_PA08E_EBI_D9 << 16) | MUX_PA08E_EBI_D9)
#define PORT_PA08E_EBI_D9                          (_UINT32_(1) << 8)

#define PIN_PB11E_EBI_D10                          _UINT32_(43)
#define MUX_PB11E_EBI_D10                          _UINT32_(4) 
#define PINMUX_PB11E_EBI_D10                       ((PIN_PB11E_EBI_D10 << 16) | MUX_PB11E_EBI_D10)
#define PORT_PB11E_EBI_D10                         (_UINT32_(1) << 11)

#define PIN_PB12E_EBI_D11                          _UINT32_(44)
#define MUX_PB12E_EBI_D11                          _UINT32_(4) 
#define PINMUX_PB12E_EBI_D11                       ((PIN_PB12E_EBI_D11 << 16) | MUX_PB12E_EBI_D11)
#define PORT_PB12E_EBI_D11                         (_UINT32_(1) << 12)

#define PIN_PB05E_EBI_D12                          _UINT32_(37)
#define MUX_PB05E_EBI_D12                          _UINT32_(4) 
#define PINMUX_PB05E_EBI_D12                       ((PIN_PB05E_EBI_D12 << 16) | MUX_PB05E_EBI_D12)
#define PORT_PB05E_EBI_D12                         (_UINT32_(1) << 5)

#define PIN_PB13E_EBI_D13                          _UINT32_(45)
#define MUX_PB13E_EBI_D13                          _UINT32_(4) 
#define PINMUX_PB13E_EBI_D13                       ((PIN_PB13E_EBI_D13 << 16) | MUX_PB13E_EBI_D13)
#define PORT_PB13E_EBI_D13                         (_UINT32_(1) << 13)

#define PIN_PB06E_EBI_D14                          _UINT32_(38)
#define MUX_PB06E_EBI_D14                          _UINT32_(4) 
#define PINMUX_PB06E_EBI_D14                       ((PIN_PB06E_EBI_D14 << 16) | MUX_PB06E_EBI_D14)
#define PORT_PB06E_EBI_D14                         (_UINT32_(1) << 6)

#define PIN_PB14E_EBI_D15                          _UINT32_(46)
#define MUX_PB14E_EBI_D15                          _UINT32_(4) 
#define PINMUX_PB14E_EBI_D15                       ((PIN_PB14E_EBI_D15 << 16) | MUX_PB14E_EBI_D15)
#define PORT_PB14E_EBI_D15                         (_UINT32_(1) << 14)

#define PIN_PB08E_EBI_NBS0_A0                      _UINT32_(40)
#define MUX_PB08E_EBI_NBS0_A0                      _UINT32_(4) 
#define PINMUX_PB08E_EBI_NBS0_A0                   ((PIN_PB08E_EBI_NBS0_A0 << 16) | MUX_PB08E_EBI_NBS0_A0)
#define PORT_PB08E_EBI_NBS0_A0                     (_UINT32_(1) << 8)

#define PIN_PB07E_EBI_NBS1_NWR1                    _UINT32_(39)
#define MUX_PB07E_EBI_NBS1_NWR1                    _UINT32_(4) 
#define PINMUX_PB07E_EBI_NBS1_NWR1                 ((PIN_PB07E_EBI_NBS1_NWR1 << 16) | MUX_PB07E_EBI_NBS1_NWR1)
#define PORT_PB07E_EBI_NBS1_NWR1                   (_UINT32_(1) << 7)

#define PIN_PC20E_EBI_NBS2_NWR2_A1                 _UINT32_(84)
#define MUX_PC20E_EBI_NBS2_NWR2_A1                 _UINT32_(4) 
#define PINMUX_PC20E_EBI_NBS2_NWR2_A1              ((PIN_PC20E_EBI_NBS2_NWR2_A1 << 16) | MUX_PC20E_EBI_NBS2_NWR2_A1)
#define PORT_PC20E_EBI_NBS2_NWR2_A1                (_UINT32_(1) << 20)

#define PIN_PC25E_EBI_NCS0                         _UINT32_(89)
#define MUX_PC25E_EBI_NCS0                         _UINT32_(4) 
#define PINMUX_PC25E_EBI_NCS0                      ((PIN_PC25E_EBI_NCS0 << 16) | MUX_PC25E_EBI_NCS0)
#define PORT_PC25E_EBI_NCS0                        (_UINT32_(1) << 25)

#define PIN_PD12E_EBI_NCS0                         _UINT32_(108)
#define MUX_PD12E_EBI_NCS0                         _UINT32_(4) 
#define PINMUX_PD12E_EBI_NCS0                      ((PIN_PD12E_EBI_NCS0 << 16) | MUX_PD12E_EBI_NCS0)
#define PORT_PD12E_EBI_NCS0                        (_UINT32_(1) << 12)

#define PIN_PC23E_EBI_NCS1                         _UINT32_(87)
#define MUX_PC23E_EBI_NCS1                         _UINT32_(4) 
#define PINMUX_PC23E_EBI_NCS1                      ((PIN_PC23E_EBI_NCS1 << 16) | MUX_PC23E_EBI_NCS1)
#define PORT_PC23E_EBI_NCS1                        (_UINT32_(1) << 23)

#define PIN_PD09E_EBI_NCS1                         _UINT32_(105)
#define MUX_PD09E_EBI_NCS1                         _UINT32_(4) 
#define PINMUX_PD09E_EBI_NCS1                      ((PIN_PD09E_EBI_NCS1 << 16) | MUX_PD09E_EBI_NCS1)
#define PORT_PD09E_EBI_NCS1                        (_UINT32_(1) << 9)

#define PIN_PC29E_EBI_NCS2                         _UINT32_(93)
#define MUX_PC29E_EBI_NCS2                         _UINT32_(4) 
#define PINMUX_PC29E_EBI_NCS2                      ((PIN_PC29E_EBI_NCS2 << 16) | MUX_PC29E_EBI_NCS2)
#define PORT_PC29E_EBI_NCS2                        (_UINT32_(1) << 29)

#define PIN_PD15E_EBI_NCS3                         _UINT32_(111)
#define MUX_PD15E_EBI_NCS3                         _UINT32_(4) 
#define PINMUX_PD15E_EBI_NCS3                      ((PIN_PD15E_EBI_NCS3 << 16) | MUX_PD15E_EBI_NCS3)
#define PORT_PD15E_EBI_NCS3                        (_UINT32_(1) << 15)

#define PIN_PB15E_EBI_NRD                          _UINT32_(47)
#define MUX_PB15E_EBI_NRD                          _UINT32_(4) 
#define PINMUX_PB15E_EBI_NRD                       ((PIN_PB15E_EBI_NRD << 16) | MUX_PB15E_EBI_NRD)
#define PORT_PB15E_EBI_NRD                         (_UINT32_(1) << 15)

#define PIN_PA10E_EBI_NWAIT                        _UINT32_(10)
#define MUX_PA10E_EBI_NWAIT                        _UINT32_(4) 
#define PINMUX_PA10E_EBI_NWAIT                     ((PIN_PA10E_EBI_NWAIT << 16) | MUX_PA10E_EBI_NWAIT)
#define PORT_PA10E_EBI_NWAIT                       (_UINT32_(1) << 10)

#define PIN_PC22E_EBI_NWAIT                        _UINT32_(86)
#define MUX_PC22E_EBI_NWAIT                        _UINT32_(4) 
#define PINMUX_PC22E_EBI_NWAIT                     ((PIN_PC22E_EBI_NWAIT << 16) | MUX_PC22E_EBI_NWAIT)
#define PORT_PC22E_EBI_NWAIT                       (_UINT32_(1) << 22)

#define PIN_PD11E_EBI_NWAIT                        _UINT32_(107)
#define MUX_PD11E_EBI_NWAIT                        _UINT32_(4) 
#define PINMUX_PD11E_EBI_NWAIT                     ((PIN_PD11E_EBI_NWAIT << 16) | MUX_PD11E_EBI_NWAIT)
#define PORT_PD11E_EBI_NWAIT                       (_UINT32_(1) << 11)

#define PIN_PC24E_EBI_NWE_NWR0                     _UINT32_(88)
#define MUX_PC24E_EBI_NWE_NWR0                     _UINT32_(4) 
#define PINMUX_PC24E_EBI_NWE_NWR0                  ((PIN_PC24E_EBI_NWE_NWR0 << 16) | MUX_PC24E_EBI_NWE_NWR0)
#define PORT_PC24E_EBI_NWE_NWR0                    (_UINT32_(1) << 24)

#define PIN_PD05E_EBI_NWE_NWR0                     _UINT32_(101)
#define MUX_PD05E_EBI_NWE_NWR0                     _UINT32_(4) 
#define PINMUX_PD05E_EBI_NWE_NWR0                  ((PIN_PD05E_EBI_NWE_NWR0 << 16) | MUX_PD05E_EBI_NWE_NWR0)
#define PORT_PD05E_EBI_NWE_NWR0                    (_UINT32_(1) << 5)

/* ========== PORT definition for EIC peripheral ========== */
#define PIN_PA16A_EIC_EXTINT0                      _UINT32_(16)
#define MUX_PA16A_EIC_EXTINT0                      _UINT32_(0) 
#define PINMUX_PA16A_EIC_EXTINT0                   ((PIN_PA16A_EIC_EXTINT0 << 16) | MUX_PA16A_EIC_EXTINT0)
#define PORT_PA16A_EIC_EXTINT0                     (_UINT32_(1) << 16)
#define PIN_PA16A_EIC_EXTINT_NUM                   _UINT32_(0)  /* EIC signal: PIN_PA16 External Interrupt Line */

#define PIN_PB00A_EIC_EXTINT0                      _UINT32_(32)
#define MUX_PB00A_EIC_EXTINT0                      _UINT32_(0) 
#define PINMUX_PB00A_EIC_EXTINT0                   ((PIN_PB00A_EIC_EXTINT0 << 16) | MUX_PB00A_EIC_EXTINT0)
#define PORT_PB00A_EIC_EXTINT0                     (_UINT32_(1) << 0)
#define PIN_PB00A_EIC_EXTINT_NUM                   _UINT32_(0)  /* EIC signal: PIN_PB00 External Interrupt Line */

#define PIN_PB16A_EIC_EXTINT0                      _UINT32_(48)
#define MUX_PB16A_EIC_EXTINT0                      _UINT32_(0) 
#define PINMUX_PB16A_EIC_EXTINT0                   ((PIN_PB16A_EIC_EXTINT0 << 16) | MUX_PB16A_EIC_EXTINT0)
#define PORT_PB16A_EIC_EXTINT0                     (_UINT32_(1) << 16)
#define PIN_PB16A_EIC_EXTINT_NUM                   _UINT32_(0)  /* EIC signal: PIN_PB16 External Interrupt Line */

#define PIN_PC00A_EIC_EXTINT0                      _UINT32_(64)
#define MUX_PC00A_EIC_EXTINT0                      _UINT32_(0) 
#define PINMUX_PC00A_EIC_EXTINT0                   ((PIN_PC00A_EIC_EXTINT0 << 16) | MUX_PC00A_EIC_EXTINT0)
#define PORT_PC00A_EIC_EXTINT0                     (_UINT32_(1) << 0)
#define PIN_PC00A_EIC_EXTINT_NUM                   _UINT32_(0)  /* EIC signal: PIN_PC00 External Interrupt Line */

#define PIN_PC16A_EIC_EXTINT0                      _UINT32_(80)
#define MUX_PC16A_EIC_EXTINT0                      _UINT32_(0) 
#define PINMUX_PC16A_EIC_EXTINT0                   ((PIN_PC16A_EIC_EXTINT0 << 16) | MUX_PC16A_EIC_EXTINT0)
#define PORT_PC16A_EIC_EXTINT0                     (_UINT32_(1) << 16)
#define PIN_PC16A_EIC_EXTINT_NUM                   _UINT32_(0)  /* EIC signal: PIN_PC16 External Interrupt Line */

#define PIN_PD00A_EIC_EXTINT0                      _UINT32_(96)
#define MUX_PD00A_EIC_EXTINT0                      _UINT32_(0) 
#define PINMUX_PD00A_EIC_EXTINT0                   ((PIN_PD00A_EIC_EXTINT0 << 16) | MUX_PD00A_EIC_EXTINT0)
#define PORT_PD00A_EIC_EXTINT0                     (_UINT32_(1) << 0)
#define PIN_PD00A_EIC_EXTINT_NUM                   _UINT32_(0)  /* EIC signal: PIN_PD00 External Interrupt Line */

#define PIN_PD16A_EIC_EXTINT0                      _UINT32_(112)
#define MUX_PD16A_EIC_EXTINT0                      _UINT32_(0) 
#define PINMUX_PD16A_EIC_EXTINT0                   ((PIN_PD16A_EIC_EXTINT0 << 16) | MUX_PD16A_EIC_EXTINT0)
#define PORT_PD16A_EIC_EXTINT0                     (_UINT32_(1) << 16)
#define PIN_PD16A_EIC_EXTINT_NUM                   _UINT32_(0)  /* EIC signal: PIN_PD16 External Interrupt Line */

#define PIN_PA01A_EIC_EXTINT1                      _UINT32_(1) 
#define MUX_PA01A_EIC_EXTINT1                      _UINT32_(0) 
#define PINMUX_PA01A_EIC_EXTINT1                   ((PIN_PA01A_EIC_EXTINT1 << 16) | MUX_PA01A_EIC_EXTINT1)
#define PORT_PA01A_EIC_EXTINT1                     (_UINT32_(1) << 1)
#define PIN_PA01A_EIC_EXTINT_NUM                   _UINT32_(1)  /* EIC signal: PIN_PA01 External Interrupt Line */

#define PIN_PA17A_EIC_EXTINT1                      _UINT32_(17)
#define MUX_PA17A_EIC_EXTINT1                      _UINT32_(0) 
#define PINMUX_PA17A_EIC_EXTINT1                   ((PIN_PA17A_EIC_EXTINT1 << 16) | MUX_PA17A_EIC_EXTINT1)
#define PORT_PA17A_EIC_EXTINT1                     (_UINT32_(1) << 17)
#define PIN_PA17A_EIC_EXTINT_NUM                   _UINT32_(1)  /* EIC signal: PIN_PA17 External Interrupt Line */

#define PIN_PB01A_EIC_EXTINT1                      _UINT32_(33)
#define MUX_PB01A_EIC_EXTINT1                      _UINT32_(0) 
#define PINMUX_PB01A_EIC_EXTINT1                   ((PIN_PB01A_EIC_EXTINT1 << 16) | MUX_PB01A_EIC_EXTINT1)
#define PORT_PB01A_EIC_EXTINT1                     (_UINT32_(1) << 1)
#define PIN_PB01A_EIC_EXTINT_NUM                   _UINT32_(1)  /* EIC signal: PIN_PB01 External Interrupt Line */

#define PIN_PB17A_EIC_EXTINT1                      _UINT32_(49)
#define MUX_PB17A_EIC_EXTINT1                      _UINT32_(0) 
#define PINMUX_PB17A_EIC_EXTINT1                   ((PIN_PB17A_EIC_EXTINT1 << 16) | MUX_PB17A_EIC_EXTINT1)
#define PORT_PB17A_EIC_EXTINT1                     (_UINT32_(1) << 17)
#define PIN_PB17A_EIC_EXTINT_NUM                   _UINT32_(1)  /* EIC signal: PIN_PB17 External Interrupt Line */

#define PIN_PC01A_EIC_EXTINT1                      _UINT32_(65)
#define MUX_PC01A_EIC_EXTINT1                      _UINT32_(0) 
#define PINMUX_PC01A_EIC_EXTINT1                   ((PIN_PC01A_EIC_EXTINT1 << 16) | MUX_PC01A_EIC_EXTINT1)
#define PORT_PC01A_EIC_EXTINT1                     (_UINT32_(1) << 1)
#define PIN_PC01A_EIC_EXTINT_NUM                   _UINT32_(1)  /* EIC signal: PIN_PC01 External Interrupt Line */

#define PIN_PC17A_EIC_EXTINT1                      _UINT32_(81)
#define MUX_PC17A_EIC_EXTINT1                      _UINT32_(0) 
#define PINMUX_PC17A_EIC_EXTINT1                   ((PIN_PC17A_EIC_EXTINT1 << 16) | MUX_PC17A_EIC_EXTINT1)
#define PORT_PC17A_EIC_EXTINT1                     (_UINT32_(1) << 17)
#define PIN_PC17A_EIC_EXTINT_NUM                   _UINT32_(1)  /* EIC signal: PIN_PC17 External Interrupt Line */

#define PIN_PD01A_EIC_EXTINT1                      _UINT32_(97)
#define MUX_PD01A_EIC_EXTINT1                      _UINT32_(0) 
#define PINMUX_PD01A_EIC_EXTINT1                   ((PIN_PD01A_EIC_EXTINT1 << 16) | MUX_PD01A_EIC_EXTINT1)
#define PORT_PD01A_EIC_EXTINT1                     (_UINT32_(1) << 1)
#define PIN_PD01A_EIC_EXTINT_NUM                   _UINT32_(1)  /* EIC signal: PIN_PD01 External Interrupt Line */

#define PIN_PD17A_EIC_EXTINT1                      _UINT32_(113)
#define MUX_PD17A_EIC_EXTINT1                      _UINT32_(0) 
#define PINMUX_PD17A_EIC_EXTINT1                   ((PIN_PD17A_EIC_EXTINT1 << 16) | MUX_PD17A_EIC_EXTINT1)
#define PORT_PD17A_EIC_EXTINT1                     (_UINT32_(1) << 17)
#define PIN_PD17A_EIC_EXTINT_NUM                   _UINT32_(1)  /* EIC signal: PIN_PD17 External Interrupt Line */

#define PIN_PA02A_EIC_EXTINT2                      _UINT32_(2) 
#define MUX_PA02A_EIC_EXTINT2                      _UINT32_(0) 
#define PINMUX_PA02A_EIC_EXTINT2                   ((PIN_PA02A_EIC_EXTINT2 << 16) | MUX_PA02A_EIC_EXTINT2)
#define PORT_PA02A_EIC_EXTINT2                     (_UINT32_(1) << 2)
#define PIN_PA02A_EIC_EXTINT_NUM                   _UINT32_(2)  /* EIC signal: PIN_PA02 External Interrupt Line */

#define PIN_PA18A_EIC_EXTINT2                      _UINT32_(18)
#define MUX_PA18A_EIC_EXTINT2                      _UINT32_(0) 
#define PINMUX_PA18A_EIC_EXTINT2                   ((PIN_PA18A_EIC_EXTINT2 << 16) | MUX_PA18A_EIC_EXTINT2)
#define PORT_PA18A_EIC_EXTINT2                     (_UINT32_(1) << 18)
#define PIN_PA18A_EIC_EXTINT_NUM                   _UINT32_(2)  /* EIC signal: PIN_PA18 External Interrupt Line */

#define PIN_PB02A_EIC_EXTINT2                      _UINT32_(34)
#define MUX_PB02A_EIC_EXTINT2                      _UINT32_(0) 
#define PINMUX_PB02A_EIC_EXTINT2                   ((PIN_PB02A_EIC_EXTINT2 << 16) | MUX_PB02A_EIC_EXTINT2)
#define PORT_PB02A_EIC_EXTINT2                     (_UINT32_(1) << 2)
#define PIN_PB02A_EIC_EXTINT_NUM                   _UINT32_(2)  /* EIC signal: PIN_PB02 External Interrupt Line */

#define PIN_PB18A_EIC_EXTINT2                      _UINT32_(50)
#define MUX_PB18A_EIC_EXTINT2                      _UINT32_(0) 
#define PINMUX_PB18A_EIC_EXTINT2                   ((PIN_PB18A_EIC_EXTINT2 << 16) | MUX_PB18A_EIC_EXTINT2)
#define PORT_PB18A_EIC_EXTINT2                     (_UINT32_(1) << 18)
#define PIN_PB18A_EIC_EXTINT_NUM                   _UINT32_(2)  /* EIC signal: PIN_PB18 External Interrupt Line */

#define PIN_PC02A_EIC_EXTINT2                      _UINT32_(66)
#define MUX_PC02A_EIC_EXTINT2                      _UINT32_(0) 
#define PINMUX_PC02A_EIC_EXTINT2                   ((PIN_PC02A_EIC_EXTINT2 << 16) | MUX_PC02A_EIC_EXTINT2)
#define PORT_PC02A_EIC_EXTINT2                     (_UINT32_(1) << 2)
#define PIN_PC02A_EIC_EXTINT_NUM                   _UINT32_(2)  /* EIC signal: PIN_PC02 External Interrupt Line */

#define PIN_PC18A_EIC_EXTINT2                      _UINT32_(82)
#define MUX_PC18A_EIC_EXTINT2                      _UINT32_(0) 
#define PINMUX_PC18A_EIC_EXTINT2                   ((PIN_PC18A_EIC_EXTINT2 << 16) | MUX_PC18A_EIC_EXTINT2)
#define PORT_PC18A_EIC_EXTINT2                     (_UINT32_(1) << 18)
#define PIN_PC18A_EIC_EXTINT_NUM                   _UINT32_(2)  /* EIC signal: PIN_PC18 External Interrupt Line */

#define PIN_PD18A_EIC_EXTINT2                      _UINT32_(114)
#define MUX_PD18A_EIC_EXTINT2                      _UINT32_(0) 
#define PINMUX_PD18A_EIC_EXTINT2                   ((PIN_PD18A_EIC_EXTINT2 << 16) | MUX_PD18A_EIC_EXTINT2)
#define PORT_PD18A_EIC_EXTINT2                     (_UINT32_(1) << 18)
#define PIN_PD18A_EIC_EXTINT_NUM                   _UINT32_(2)  /* EIC signal: PIN_PD18 External Interrupt Line */

#define PIN_PA03A_EIC_EXTINT3                      _UINT32_(3) 
#define MUX_PA03A_EIC_EXTINT3                      _UINT32_(0) 
#define PINMUX_PA03A_EIC_EXTINT3                   ((PIN_PA03A_EIC_EXTINT3 << 16) | MUX_PA03A_EIC_EXTINT3)
#define PORT_PA03A_EIC_EXTINT3                     (_UINT32_(1) << 3)
#define PIN_PA03A_EIC_EXTINT_NUM                   _UINT32_(3)  /* EIC signal: PIN_PA03 External Interrupt Line */

#define PIN_PA19A_EIC_EXTINT3                      _UINT32_(19)
#define MUX_PA19A_EIC_EXTINT3                      _UINT32_(0) 
#define PINMUX_PA19A_EIC_EXTINT3                   ((PIN_PA19A_EIC_EXTINT3 << 16) | MUX_PA19A_EIC_EXTINT3)
#define PORT_PA19A_EIC_EXTINT3                     (_UINT32_(1) << 19)
#define PIN_PA19A_EIC_EXTINT_NUM                   _UINT32_(3)  /* EIC signal: PIN_PA19 External Interrupt Line */

#define PIN_PB03A_EIC_EXTINT3                      _UINT32_(35)
#define MUX_PB03A_EIC_EXTINT3                      _UINT32_(0) 
#define PINMUX_PB03A_EIC_EXTINT3                   ((PIN_PB03A_EIC_EXTINT3 << 16) | MUX_PB03A_EIC_EXTINT3)
#define PORT_PB03A_EIC_EXTINT3                     (_UINT32_(1) << 3)
#define PIN_PB03A_EIC_EXTINT_NUM                   _UINT32_(3)  /* EIC signal: PIN_PB03 External Interrupt Line */

#define PIN_PB19A_EIC_EXTINT3                      _UINT32_(51)
#define MUX_PB19A_EIC_EXTINT3                      _UINT32_(0) 
#define PINMUX_PB19A_EIC_EXTINT3                   ((PIN_PB19A_EIC_EXTINT3 << 16) | MUX_PB19A_EIC_EXTINT3)
#define PORT_PB19A_EIC_EXTINT3                     (_UINT32_(1) << 19)
#define PIN_PB19A_EIC_EXTINT_NUM                   _UINT32_(3)  /* EIC signal: PIN_PB19 External Interrupt Line */

#define PIN_PC03A_EIC_EXTINT3                      _UINT32_(67)
#define MUX_PC03A_EIC_EXTINT3                      _UINT32_(0) 
#define PINMUX_PC03A_EIC_EXTINT3                   ((PIN_PC03A_EIC_EXTINT3 << 16) | MUX_PC03A_EIC_EXTINT3)
#define PORT_PC03A_EIC_EXTINT3                     (_UINT32_(1) << 3)
#define PIN_PC03A_EIC_EXTINT_NUM                   _UINT32_(3)  /* EIC signal: PIN_PC03 External Interrupt Line */

#define PIN_PC19A_EIC_EXTINT3                      _UINT32_(83)
#define MUX_PC19A_EIC_EXTINT3                      _UINT32_(0) 
#define PINMUX_PC19A_EIC_EXTINT3                   ((PIN_PC19A_EIC_EXTINT3 << 16) | MUX_PC19A_EIC_EXTINT3)
#define PORT_PC19A_EIC_EXTINT3                     (_UINT32_(1) << 19)
#define PIN_PC19A_EIC_EXTINT_NUM                   _UINT32_(3)  /* EIC signal: PIN_PC19 External Interrupt Line */

#define PIN_PD03A_EIC_EXTINT3                      _UINT32_(99)
#define MUX_PD03A_EIC_EXTINT3                      _UINT32_(0) 
#define PINMUX_PD03A_EIC_EXTINT3                   ((PIN_PD03A_EIC_EXTINT3 << 16) | MUX_PD03A_EIC_EXTINT3)
#define PORT_PD03A_EIC_EXTINT3                     (_UINT32_(1) << 3)
#define PIN_PD03A_EIC_EXTINT_NUM                   _UINT32_(3)  /* EIC signal: PIN_PD03 External Interrupt Line */

#define PIN_PD19A_EIC_EXTINT3                      _UINT32_(115)
#define MUX_PD19A_EIC_EXTINT3                      _UINT32_(0) 
#define PINMUX_PD19A_EIC_EXTINT3                   ((PIN_PD19A_EIC_EXTINT3 << 16) | MUX_PD19A_EIC_EXTINT3)
#define PORT_PD19A_EIC_EXTINT3                     (_UINT32_(1) << 19)
#define PIN_PD19A_EIC_EXTINT_NUM                   _UINT32_(3)  /* EIC signal: PIN_PD19 External Interrupt Line */

#define PIN_PA04A_EIC_EXTINT4                      _UINT32_(4) 
#define MUX_PA04A_EIC_EXTINT4                      _UINT32_(0) 
#define PINMUX_PA04A_EIC_EXTINT4                   ((PIN_PA04A_EIC_EXTINT4 << 16) | MUX_PA04A_EIC_EXTINT4)
#define PORT_PA04A_EIC_EXTINT4                     (_UINT32_(1) << 4)
#define PIN_PA04A_EIC_EXTINT_NUM                   _UINT32_(4)  /* EIC signal: PIN_PA04 External Interrupt Line */

#define PIN_PA20A_EIC_EXTINT4                      _UINT32_(20)
#define MUX_PA20A_EIC_EXTINT4                      _UINT32_(0) 
#define PINMUX_PA20A_EIC_EXTINT4                   ((PIN_PA20A_EIC_EXTINT4 << 16) | MUX_PA20A_EIC_EXTINT4)
#define PORT_PA20A_EIC_EXTINT4                     (_UINT32_(1) << 20)
#define PIN_PA20A_EIC_EXTINT_NUM                   _UINT32_(4)  /* EIC signal: PIN_PA20 External Interrupt Line */

#define PIN_PB04A_EIC_EXTINT4                      _UINT32_(36)
#define MUX_PB04A_EIC_EXTINT4                      _UINT32_(0) 
#define PINMUX_PB04A_EIC_EXTINT4                   ((PIN_PB04A_EIC_EXTINT4 << 16) | MUX_PB04A_EIC_EXTINT4)
#define PORT_PB04A_EIC_EXTINT4                     (_UINT32_(1) << 4)
#define PIN_PB04A_EIC_EXTINT_NUM                   _UINT32_(4)  /* EIC signal: PIN_PB04 External Interrupt Line */

#define PIN_PB20A_EIC_EXTINT4                      _UINT32_(52)
#define MUX_PB20A_EIC_EXTINT4                      _UINT32_(0) 
#define PINMUX_PB20A_EIC_EXTINT4                   ((PIN_PB20A_EIC_EXTINT4 << 16) | MUX_PB20A_EIC_EXTINT4)
#define PORT_PB20A_EIC_EXTINT4                     (_UINT32_(1) << 20)
#define PIN_PB20A_EIC_EXTINT_NUM                   _UINT32_(4)  /* EIC signal: PIN_PB20 External Interrupt Line */

#define PIN_PC04A_EIC_EXTINT4                      _UINT32_(68)
#define MUX_PC04A_EIC_EXTINT4                      _UINT32_(0) 
#define PINMUX_PC04A_EIC_EXTINT4                   ((PIN_PC04A_EIC_EXTINT4 << 16) | MUX_PC04A_EIC_EXTINT4)
#define PORT_PC04A_EIC_EXTINT4                     (_UINT32_(1) << 4)
#define PIN_PC04A_EIC_EXTINT_NUM                   _UINT32_(4)  /* EIC signal: PIN_PC04 External Interrupt Line */

#define PIN_PC20A_EIC_EXTINT4                      _UINT32_(84)
#define MUX_PC20A_EIC_EXTINT4                      _UINT32_(0) 
#define PINMUX_PC20A_EIC_EXTINT4                   ((PIN_PC20A_EIC_EXTINT4 << 16) | MUX_PC20A_EIC_EXTINT4)
#define PORT_PC20A_EIC_EXTINT4                     (_UINT32_(1) << 20)
#define PIN_PC20A_EIC_EXTINT_NUM                   _UINT32_(4)  /* EIC signal: PIN_PC20 External Interrupt Line */

#define PIN_PD04A_EIC_EXTINT4                      _UINT32_(100)
#define MUX_PD04A_EIC_EXTINT4                      _UINT32_(0) 
#define PINMUX_PD04A_EIC_EXTINT4                   ((PIN_PD04A_EIC_EXTINT4 << 16) | MUX_PD04A_EIC_EXTINT4)
#define PORT_PD04A_EIC_EXTINT4                     (_UINT32_(1) << 4)
#define PIN_PD04A_EIC_EXTINT_NUM                   _UINT32_(4)  /* EIC signal: PIN_PD04 External Interrupt Line */

#define PIN_PD20A_EIC_EXTINT4                      _UINT32_(116)
#define MUX_PD20A_EIC_EXTINT4                      _UINT32_(0) 
#define PINMUX_PD20A_EIC_EXTINT4                   ((PIN_PD20A_EIC_EXTINT4 << 16) | MUX_PD20A_EIC_EXTINT4)
#define PORT_PD20A_EIC_EXTINT4                     (_UINT32_(1) << 20)
#define PIN_PD20A_EIC_EXTINT_NUM                   _UINT32_(4)  /* EIC signal: PIN_PD20 External Interrupt Line */

#define PIN_PA05A_EIC_EXTINT5                      _UINT32_(5) 
#define MUX_PA05A_EIC_EXTINT5                      _UINT32_(0) 
#define PINMUX_PA05A_EIC_EXTINT5                   ((PIN_PA05A_EIC_EXTINT5 << 16) | MUX_PA05A_EIC_EXTINT5)
#define PORT_PA05A_EIC_EXTINT5                     (_UINT32_(1) << 5)
#define PIN_PA05A_EIC_EXTINT_NUM                   _UINT32_(5)  /* EIC signal: PIN_PA05 External Interrupt Line */

#define PIN_PA21A_EIC_EXTINT5                      _UINT32_(21)
#define MUX_PA21A_EIC_EXTINT5                      _UINT32_(0) 
#define PINMUX_PA21A_EIC_EXTINT5                   ((PIN_PA21A_EIC_EXTINT5 << 16) | MUX_PA21A_EIC_EXTINT5)
#define PORT_PA21A_EIC_EXTINT5                     (_UINT32_(1) << 21)
#define PIN_PA21A_EIC_EXTINT_NUM                   _UINT32_(5)  /* EIC signal: PIN_PA21 External Interrupt Line */

#define PIN_PB05A_EIC_EXTINT5                      _UINT32_(37)
#define MUX_PB05A_EIC_EXTINT5                      _UINT32_(0) 
#define PINMUX_PB05A_EIC_EXTINT5                   ((PIN_PB05A_EIC_EXTINT5 << 16) | MUX_PB05A_EIC_EXTINT5)
#define PORT_PB05A_EIC_EXTINT5                     (_UINT32_(1) << 5)
#define PIN_PB05A_EIC_EXTINT_NUM                   _UINT32_(5)  /* EIC signal: PIN_PB05 External Interrupt Line */

#define PIN_PB21A_EIC_EXTINT5                      _UINT32_(53)
#define MUX_PB21A_EIC_EXTINT5                      _UINT32_(0) 
#define PINMUX_PB21A_EIC_EXTINT5                   ((PIN_PB21A_EIC_EXTINT5 << 16) | MUX_PB21A_EIC_EXTINT5)
#define PORT_PB21A_EIC_EXTINT5                     (_UINT32_(1) << 21)
#define PIN_PB21A_EIC_EXTINT_NUM                   _UINT32_(5)  /* EIC signal: PIN_PB21 External Interrupt Line */

#define PIN_PC05A_EIC_EXTINT5                      _UINT32_(69)
#define MUX_PC05A_EIC_EXTINT5                      _UINT32_(0) 
#define PINMUX_PC05A_EIC_EXTINT5                   ((PIN_PC05A_EIC_EXTINT5 << 16) | MUX_PC05A_EIC_EXTINT5)
#define PORT_PC05A_EIC_EXTINT5                     (_UINT32_(1) << 5)
#define PIN_PC05A_EIC_EXTINT_NUM                   _UINT32_(5)  /* EIC signal: PIN_PC05 External Interrupt Line */

#define PIN_PC21A_EIC_EXTINT5                      _UINT32_(85)
#define MUX_PC21A_EIC_EXTINT5                      _UINT32_(0) 
#define PINMUX_PC21A_EIC_EXTINT5                   ((PIN_PC21A_EIC_EXTINT5 << 16) | MUX_PC21A_EIC_EXTINT5)
#define PORT_PC21A_EIC_EXTINT5                     (_UINT32_(1) << 21)
#define PIN_PC21A_EIC_EXTINT_NUM                   _UINT32_(5)  /* EIC signal: PIN_PC21 External Interrupt Line */

#define PIN_PD05A_EIC_EXTINT5                      _UINT32_(101)
#define MUX_PD05A_EIC_EXTINT5                      _UINT32_(0) 
#define PINMUX_PD05A_EIC_EXTINT5                   ((PIN_PD05A_EIC_EXTINT5 << 16) | MUX_PD05A_EIC_EXTINT5)
#define PORT_PD05A_EIC_EXTINT5                     (_UINT32_(1) << 5)
#define PIN_PD05A_EIC_EXTINT_NUM                   _UINT32_(5)  /* EIC signal: PIN_PD05 External Interrupt Line */

#define PIN_PD21A_EIC_EXTINT5                      _UINT32_(117)
#define MUX_PD21A_EIC_EXTINT5                      _UINT32_(0) 
#define PINMUX_PD21A_EIC_EXTINT5                   ((PIN_PD21A_EIC_EXTINT5 << 16) | MUX_PD21A_EIC_EXTINT5)
#define PORT_PD21A_EIC_EXTINT5                     (_UINT32_(1) << 21)
#define PIN_PD21A_EIC_EXTINT_NUM                   _UINT32_(5)  /* EIC signal: PIN_PD21 External Interrupt Line */

#define PIN_PA06A_EIC_EXTINT6                      _UINT32_(6) 
#define MUX_PA06A_EIC_EXTINT6                      _UINT32_(0) 
#define PINMUX_PA06A_EIC_EXTINT6                   ((PIN_PA06A_EIC_EXTINT6 << 16) | MUX_PA06A_EIC_EXTINT6)
#define PORT_PA06A_EIC_EXTINT6                     (_UINT32_(1) << 6)
#define PIN_PA06A_EIC_EXTINT_NUM                   _UINT32_(6)  /* EIC signal: PIN_PA06 External Interrupt Line */

#define PIN_PA22A_EIC_EXTINT6                      _UINT32_(22)
#define MUX_PA22A_EIC_EXTINT6                      _UINT32_(0) 
#define PINMUX_PA22A_EIC_EXTINT6                   ((PIN_PA22A_EIC_EXTINT6 << 16) | MUX_PA22A_EIC_EXTINT6)
#define PORT_PA22A_EIC_EXTINT6                     (_UINT32_(1) << 22)
#define PIN_PA22A_EIC_EXTINT_NUM                   _UINT32_(6)  /* EIC signal: PIN_PA22 External Interrupt Line */

#define PIN_PB06A_EIC_EXTINT6                      _UINT32_(38)
#define MUX_PB06A_EIC_EXTINT6                      _UINT32_(0) 
#define PINMUX_PB06A_EIC_EXTINT6                   ((PIN_PB06A_EIC_EXTINT6 << 16) | MUX_PB06A_EIC_EXTINT6)
#define PORT_PB06A_EIC_EXTINT6                     (_UINT32_(1) << 6)
#define PIN_PB06A_EIC_EXTINT_NUM                   _UINT32_(6)  /* EIC signal: PIN_PB06 External Interrupt Line */

#define PIN_PB22A_EIC_EXTINT6                      _UINT32_(54)
#define MUX_PB22A_EIC_EXTINT6                      _UINT32_(0) 
#define PINMUX_PB22A_EIC_EXTINT6                   ((PIN_PB22A_EIC_EXTINT6 << 16) | MUX_PB22A_EIC_EXTINT6)
#define PORT_PB22A_EIC_EXTINT6                     (_UINT32_(1) << 22)
#define PIN_PB22A_EIC_EXTINT_NUM                   _UINT32_(6)  /* EIC signal: PIN_PB22 External Interrupt Line */

#define PIN_PC06A_EIC_EXTINT6                      _UINT32_(70)
#define MUX_PC06A_EIC_EXTINT6                      _UINT32_(0) 
#define PINMUX_PC06A_EIC_EXTINT6                   ((PIN_PC06A_EIC_EXTINT6 << 16) | MUX_PC06A_EIC_EXTINT6)
#define PORT_PC06A_EIC_EXTINT6                     (_UINT32_(1) << 6)
#define PIN_PC06A_EIC_EXTINT_NUM                   _UINT32_(6)  /* EIC signal: PIN_PC06 External Interrupt Line */

#define PIN_PC22A_EIC_EXTINT6                      _UINT32_(86)
#define MUX_PC22A_EIC_EXTINT6                      _UINT32_(0) 
#define PINMUX_PC22A_EIC_EXTINT6                   ((PIN_PC22A_EIC_EXTINT6 << 16) | MUX_PC22A_EIC_EXTINT6)
#define PORT_PC22A_EIC_EXTINT6                     (_UINT32_(1) << 22)
#define PIN_PC22A_EIC_EXTINT_NUM                   _UINT32_(6)  /* EIC signal: PIN_PC22 External Interrupt Line */

#define PIN_PD06A_EIC_EXTINT6                      _UINT32_(102)
#define MUX_PD06A_EIC_EXTINT6                      _UINT32_(0) 
#define PINMUX_PD06A_EIC_EXTINT6                   ((PIN_PD06A_EIC_EXTINT6 << 16) | MUX_PD06A_EIC_EXTINT6)
#define PORT_PD06A_EIC_EXTINT6                     (_UINT32_(1) << 6)
#define PIN_PD06A_EIC_EXTINT_NUM                   _UINT32_(6)  /* EIC signal: PIN_PD06 External Interrupt Line */

#define PIN_PA07A_EIC_EXTINT7                      _UINT32_(7) 
#define MUX_PA07A_EIC_EXTINT7                      _UINT32_(0) 
#define PINMUX_PA07A_EIC_EXTINT7                   ((PIN_PA07A_EIC_EXTINT7 << 16) | MUX_PA07A_EIC_EXTINT7)
#define PORT_PA07A_EIC_EXTINT7                     (_UINT32_(1) << 7)
#define PIN_PA07A_EIC_EXTINT_NUM                   _UINT32_(7)  /* EIC signal: PIN_PA07 External Interrupt Line */

#define PIN_PA23A_EIC_EXTINT7                      _UINT32_(23)
#define MUX_PA23A_EIC_EXTINT7                      _UINT32_(0) 
#define PINMUX_PA23A_EIC_EXTINT7                   ((PIN_PA23A_EIC_EXTINT7 << 16) | MUX_PA23A_EIC_EXTINT7)
#define PORT_PA23A_EIC_EXTINT7                     (_UINT32_(1) << 23)
#define PIN_PA23A_EIC_EXTINT_NUM                   _UINT32_(7)  /* EIC signal: PIN_PA23 External Interrupt Line */

#define PIN_PB07A_EIC_EXTINT7                      _UINT32_(39)
#define MUX_PB07A_EIC_EXTINT7                      _UINT32_(0) 
#define PINMUX_PB07A_EIC_EXTINT7                   ((PIN_PB07A_EIC_EXTINT7 << 16) | MUX_PB07A_EIC_EXTINT7)
#define PORT_PB07A_EIC_EXTINT7                     (_UINT32_(1) << 7)
#define PIN_PB07A_EIC_EXTINT_NUM                   _UINT32_(7)  /* EIC signal: PIN_PB07 External Interrupt Line */

#define PIN_PB23A_EIC_EXTINT7                      _UINT32_(55)
#define MUX_PB23A_EIC_EXTINT7                      _UINT32_(0) 
#define PINMUX_PB23A_EIC_EXTINT7                   ((PIN_PB23A_EIC_EXTINT7 << 16) | MUX_PB23A_EIC_EXTINT7)
#define PORT_PB23A_EIC_EXTINT7                     (_UINT32_(1) << 23)
#define PIN_PB23A_EIC_EXTINT_NUM                   _UINT32_(7)  /* EIC signal: PIN_PB23 External Interrupt Line */

#define PIN_PC07A_EIC_EXTINT7                      _UINT32_(71)
#define MUX_PC07A_EIC_EXTINT7                      _UINT32_(0) 
#define PINMUX_PC07A_EIC_EXTINT7                   ((PIN_PC07A_EIC_EXTINT7 << 16) | MUX_PC07A_EIC_EXTINT7)
#define PORT_PC07A_EIC_EXTINT7                     (_UINT32_(1) << 7)
#define PIN_PC07A_EIC_EXTINT_NUM                   _UINT32_(7)  /* EIC signal: PIN_PC07 External Interrupt Line */

#define PIN_PC23A_EIC_EXTINT7                      _UINT32_(87)
#define MUX_PC23A_EIC_EXTINT7                      _UINT32_(0) 
#define PINMUX_PC23A_EIC_EXTINT7                   ((PIN_PC23A_EIC_EXTINT7 << 16) | MUX_PC23A_EIC_EXTINT7)
#define PORT_PC23A_EIC_EXTINT7                     (_UINT32_(1) << 23)
#define PIN_PC23A_EIC_EXTINT_NUM                   _UINT32_(7)  /* EIC signal: PIN_PC23 External Interrupt Line */

#define PIN_PD07A_EIC_EXTINT7                      _UINT32_(103)
#define MUX_PD07A_EIC_EXTINT7                      _UINT32_(0) 
#define PINMUX_PD07A_EIC_EXTINT7                   ((PIN_PD07A_EIC_EXTINT7 << 16) | MUX_PD07A_EIC_EXTINT7)
#define PORT_PD07A_EIC_EXTINT7                     (_UINT32_(1) << 7)
#define PIN_PD07A_EIC_EXTINT_NUM                   _UINT32_(7)  /* EIC signal: PIN_PD07 External Interrupt Line */

#define PIN_PA08A_EIC_EXTINT8                      _UINT32_(8) 
#define MUX_PA08A_EIC_EXTINT8                      _UINT32_(0) 
#define PINMUX_PA08A_EIC_EXTINT8                   ((PIN_PA08A_EIC_EXTINT8 << 16) | MUX_PA08A_EIC_EXTINT8)
#define PORT_PA08A_EIC_EXTINT8                     (_UINT32_(1) << 8)
#define PIN_PA08A_EIC_EXTINT_NUM                   _UINT32_(8)  /* EIC signal: PIN_PA08 External Interrupt Line */

#define PIN_PA24A_EIC_EXTINT8                      _UINT32_(24)
#define MUX_PA24A_EIC_EXTINT8                      _UINT32_(0) 
#define PINMUX_PA24A_EIC_EXTINT8                   ((PIN_PA24A_EIC_EXTINT8 << 16) | MUX_PA24A_EIC_EXTINT8)
#define PORT_PA24A_EIC_EXTINT8                     (_UINT32_(1) << 24)
#define PIN_PA24A_EIC_EXTINT_NUM                   _UINT32_(8)  /* EIC signal: PIN_PA24 External Interrupt Line */

#define PIN_PB08A_EIC_EXTINT8                      _UINT32_(40)
#define MUX_PB08A_EIC_EXTINT8                      _UINT32_(0) 
#define PINMUX_PB08A_EIC_EXTINT8                   ((PIN_PB08A_EIC_EXTINT8 << 16) | MUX_PB08A_EIC_EXTINT8)
#define PORT_PB08A_EIC_EXTINT8                     (_UINT32_(1) << 8)
#define PIN_PB08A_EIC_EXTINT_NUM                   _UINT32_(8)  /* EIC signal: PIN_PB08 External Interrupt Line */

#define PIN_PB24A_EIC_EXTINT8                      _UINT32_(56)
#define MUX_PB24A_EIC_EXTINT8                      _UINT32_(0) 
#define PINMUX_PB24A_EIC_EXTINT8                   ((PIN_PB24A_EIC_EXTINT8 << 16) | MUX_PB24A_EIC_EXTINT8)
#define PORT_PB24A_EIC_EXTINT8                     (_UINT32_(1) << 24)
#define PIN_PB24A_EIC_EXTINT_NUM                   _UINT32_(8)  /* EIC signal: PIN_PB24 External Interrupt Line */

#define PIN_PC24A_EIC_EXTINT8                      _UINT32_(88)
#define MUX_PC24A_EIC_EXTINT8                      _UINT32_(0) 
#define PINMUX_PC24A_EIC_EXTINT8                   ((PIN_PC24A_EIC_EXTINT8 << 16) | MUX_PC24A_EIC_EXTINT8)
#define PORT_PC24A_EIC_EXTINT8                     (_UINT32_(1) << 24)
#define PIN_PC24A_EIC_EXTINT_NUM                   _UINT32_(8)  /* EIC signal: PIN_PC24 External Interrupt Line */

#define PIN_PD08A_EIC_EXTINT8                      _UINT32_(104)
#define MUX_PD08A_EIC_EXTINT8                      _UINT32_(0) 
#define PINMUX_PD08A_EIC_EXTINT8                   ((PIN_PD08A_EIC_EXTINT8 << 16) | MUX_PD08A_EIC_EXTINT8)
#define PORT_PD08A_EIC_EXTINT8                     (_UINT32_(1) << 8)
#define PIN_PD08A_EIC_EXTINT_NUM                   _UINT32_(8)  /* EIC signal: PIN_PD08 External Interrupt Line */

#define PIN_PA09A_EIC_EXTINT9                      _UINT32_(9) 
#define MUX_PA09A_EIC_EXTINT9                      _UINT32_(0) 
#define PINMUX_PA09A_EIC_EXTINT9                   ((PIN_PA09A_EIC_EXTINT9 << 16) | MUX_PA09A_EIC_EXTINT9)
#define PORT_PA09A_EIC_EXTINT9                     (_UINT32_(1) << 9)
#define PIN_PA09A_EIC_EXTINT_NUM                   _UINT32_(9)  /* EIC signal: PIN_PA09 External Interrupt Line */

#define PIN_PA25A_EIC_EXTINT9                      _UINT32_(25)
#define MUX_PA25A_EIC_EXTINT9                      _UINT32_(0) 
#define PINMUX_PA25A_EIC_EXTINT9                   ((PIN_PA25A_EIC_EXTINT9 << 16) | MUX_PA25A_EIC_EXTINT9)
#define PORT_PA25A_EIC_EXTINT9                     (_UINT32_(1) << 25)
#define PIN_PA25A_EIC_EXTINT_NUM                   _UINT32_(9)  /* EIC signal: PIN_PA25 External Interrupt Line */

#define PIN_PB09A_EIC_EXTINT9                      _UINT32_(41)
#define MUX_PB09A_EIC_EXTINT9                      _UINT32_(0) 
#define PINMUX_PB09A_EIC_EXTINT9                   ((PIN_PB09A_EIC_EXTINT9 << 16) | MUX_PB09A_EIC_EXTINT9)
#define PORT_PB09A_EIC_EXTINT9                     (_UINT32_(1) << 9)
#define PIN_PB09A_EIC_EXTINT_NUM                   _UINT32_(9)  /* EIC signal: PIN_PB09 External Interrupt Line */

#define PIN_PB25A_EIC_EXTINT9                      _UINT32_(57)
#define MUX_PB25A_EIC_EXTINT9                      _UINT32_(0) 
#define PINMUX_PB25A_EIC_EXTINT9                   ((PIN_PB25A_EIC_EXTINT9 << 16) | MUX_PB25A_EIC_EXTINT9)
#define PORT_PB25A_EIC_EXTINT9                     (_UINT32_(1) << 25)
#define PIN_PB25A_EIC_EXTINT_NUM                   _UINT32_(9)  /* EIC signal: PIN_PB25 External Interrupt Line */

#define PIN_PC09A_EIC_EXTINT9                      _UINT32_(73)
#define MUX_PC09A_EIC_EXTINT9                      _UINT32_(0) 
#define PINMUX_PC09A_EIC_EXTINT9                   ((PIN_PC09A_EIC_EXTINT9 << 16) | MUX_PC09A_EIC_EXTINT9)
#define PORT_PC09A_EIC_EXTINT9                     (_UINT32_(1) << 9)
#define PIN_PC09A_EIC_EXTINT_NUM                   _UINT32_(9)  /* EIC signal: PIN_PC09 External Interrupt Line */

#define PIN_PC25A_EIC_EXTINT9                      _UINT32_(89)
#define MUX_PC25A_EIC_EXTINT9                      _UINT32_(0) 
#define PINMUX_PC25A_EIC_EXTINT9                   ((PIN_PC25A_EIC_EXTINT9 << 16) | MUX_PC25A_EIC_EXTINT9)
#define PORT_PC25A_EIC_EXTINT9                     (_UINT32_(1) << 25)
#define PIN_PC25A_EIC_EXTINT_NUM                   _UINT32_(9)  /* EIC signal: PIN_PC25 External Interrupt Line */

#define PIN_PD09A_EIC_EXTINT9                      _UINT32_(105)
#define MUX_PD09A_EIC_EXTINT9                      _UINT32_(0) 
#define PINMUX_PD09A_EIC_EXTINT9                   ((PIN_PD09A_EIC_EXTINT9 << 16) | MUX_PD09A_EIC_EXTINT9)
#define PORT_PD09A_EIC_EXTINT9                     (_UINT32_(1) << 9)
#define PIN_PD09A_EIC_EXTINT_NUM                   _UINT32_(9)  /* EIC signal: PIN_PD09 External Interrupt Line */

#define PIN_PA10A_EIC_EXTINT10                     _UINT32_(10)
#define MUX_PA10A_EIC_EXTINT10                     _UINT32_(0) 
#define PINMUX_PA10A_EIC_EXTINT10                  ((PIN_PA10A_EIC_EXTINT10 << 16) | MUX_PA10A_EIC_EXTINT10)
#define PORT_PA10A_EIC_EXTINT10                    (_UINT32_(1) << 10)
#define PIN_PA10A_EIC_EXTINT_NUM                   _UINT32_(10) /* EIC signal: PIN_PA10 External Interrupt Line */

#define PIN_PA26A_EIC_EXTINT10                     _UINT32_(26)
#define MUX_PA26A_EIC_EXTINT10                     _UINT32_(0) 
#define PINMUX_PA26A_EIC_EXTINT10                  ((PIN_PA26A_EIC_EXTINT10 << 16) | MUX_PA26A_EIC_EXTINT10)
#define PORT_PA26A_EIC_EXTINT10                    (_UINT32_(1) << 26)
#define PIN_PA26A_EIC_EXTINT_NUM                   _UINT32_(10) /* EIC signal: PIN_PA26 External Interrupt Line */

#define PIN_PB10A_EIC_EXTINT10                     _UINT32_(42)
#define MUX_PB10A_EIC_EXTINT10                     _UINT32_(0) 
#define PINMUX_PB10A_EIC_EXTINT10                  ((PIN_PB10A_EIC_EXTINT10 << 16) | MUX_PB10A_EIC_EXTINT10)
#define PORT_PB10A_EIC_EXTINT10                    (_UINT32_(1) << 10)
#define PIN_PB10A_EIC_EXTINT_NUM                   _UINT32_(10) /* EIC signal: PIN_PB10 External Interrupt Line */

#define PIN_PB26A_EIC_EXTINT10                     _UINT32_(58)
#define MUX_PB26A_EIC_EXTINT10                     _UINT32_(0) 
#define PINMUX_PB26A_EIC_EXTINT10                  ((PIN_PB26A_EIC_EXTINT10 << 16) | MUX_PB26A_EIC_EXTINT10)
#define PORT_PB26A_EIC_EXTINT10                    (_UINT32_(1) << 26)
#define PIN_PB26A_EIC_EXTINT_NUM                   _UINT32_(10) /* EIC signal: PIN_PB26 External Interrupt Line */

#define PIN_PC10A_EIC_EXTINT10                     _UINT32_(74)
#define MUX_PC10A_EIC_EXTINT10                     _UINT32_(0) 
#define PINMUX_PC10A_EIC_EXTINT10                  ((PIN_PC10A_EIC_EXTINT10 << 16) | MUX_PC10A_EIC_EXTINT10)
#define PORT_PC10A_EIC_EXTINT10                    (_UINT32_(1) << 10)
#define PIN_PC10A_EIC_EXTINT_NUM                   _UINT32_(10) /* EIC signal: PIN_PC10 External Interrupt Line */

#define PIN_PC26A_EIC_EXTINT10                     _UINT32_(90)
#define MUX_PC26A_EIC_EXTINT10                     _UINT32_(0) 
#define PINMUX_PC26A_EIC_EXTINT10                  ((PIN_PC26A_EIC_EXTINT10 << 16) | MUX_PC26A_EIC_EXTINT10)
#define PORT_PC26A_EIC_EXTINT10                    (_UINT32_(1) << 26)
#define PIN_PC26A_EIC_EXTINT_NUM                   _UINT32_(10) /* EIC signal: PIN_PC26 External Interrupt Line */

#define PIN_PD10A_EIC_EXTINT10                     _UINT32_(106)
#define MUX_PD10A_EIC_EXTINT10                     _UINT32_(0) 
#define PINMUX_PD10A_EIC_EXTINT10                  ((PIN_PD10A_EIC_EXTINT10 << 16) | MUX_PD10A_EIC_EXTINT10)
#define PORT_PD10A_EIC_EXTINT10                    (_UINT32_(1) << 10)
#define PIN_PD10A_EIC_EXTINT_NUM                   _UINT32_(10) /* EIC signal: PIN_PD10 External Interrupt Line */

#define PIN_PA11A_EIC_EXTINT11                     _UINT32_(11)
#define MUX_PA11A_EIC_EXTINT11                     _UINT32_(0) 
#define PINMUX_PA11A_EIC_EXTINT11                  ((PIN_PA11A_EIC_EXTINT11 << 16) | MUX_PA11A_EIC_EXTINT11)
#define PORT_PA11A_EIC_EXTINT11                    (_UINT32_(1) << 11)
#define PIN_PA11A_EIC_EXTINT_NUM                   _UINT32_(11) /* EIC signal: PIN_PA11 External Interrupt Line */

#define PIN_PA27A_EIC_EXTINT11                     _UINT32_(27)
#define MUX_PA27A_EIC_EXTINT11                     _UINT32_(0) 
#define PINMUX_PA27A_EIC_EXTINT11                  ((PIN_PA27A_EIC_EXTINT11 << 16) | MUX_PA27A_EIC_EXTINT11)
#define PORT_PA27A_EIC_EXTINT11                    (_UINT32_(1) << 27)
#define PIN_PA27A_EIC_EXTINT_NUM                   _UINT32_(11) /* EIC signal: PIN_PA27 External Interrupt Line */

#define PIN_PB11A_EIC_EXTINT11                     _UINT32_(43)
#define MUX_PB11A_EIC_EXTINT11                     _UINT32_(0) 
#define PINMUX_PB11A_EIC_EXTINT11                  ((PIN_PB11A_EIC_EXTINT11 << 16) | MUX_PB11A_EIC_EXTINT11)
#define PORT_PB11A_EIC_EXTINT11                    (_UINT32_(1) << 11)
#define PIN_PB11A_EIC_EXTINT_NUM                   _UINT32_(11) /* EIC signal: PIN_PB11 External Interrupt Line */

#define PIN_PC11A_EIC_EXTINT11                     _UINT32_(75)
#define MUX_PC11A_EIC_EXTINT11                     _UINT32_(0) 
#define PINMUX_PC11A_EIC_EXTINT11                  ((PIN_PC11A_EIC_EXTINT11 << 16) | MUX_PC11A_EIC_EXTINT11)
#define PORT_PC11A_EIC_EXTINT11                    (_UINT32_(1) << 11)
#define PIN_PC11A_EIC_EXTINT_NUM                   _UINT32_(11) /* EIC signal: PIN_PC11 External Interrupt Line */

#define PIN_PC27A_EIC_EXTINT11                     _UINT32_(91)
#define MUX_PC27A_EIC_EXTINT11                     _UINT32_(0) 
#define PINMUX_PC27A_EIC_EXTINT11                  ((PIN_PC27A_EIC_EXTINT11 << 16) | MUX_PC27A_EIC_EXTINT11)
#define PORT_PC27A_EIC_EXTINT11                    (_UINT32_(1) << 27)
#define PIN_PC27A_EIC_EXTINT_NUM                   _UINT32_(11) /* EIC signal: PIN_PC27 External Interrupt Line */

#define PIN_PD11A_EIC_EXTINT11                     _UINT32_(107)
#define MUX_PD11A_EIC_EXTINT11                     _UINT32_(0) 
#define PINMUX_PD11A_EIC_EXTINT11                  ((PIN_PD11A_EIC_EXTINT11 << 16) | MUX_PD11A_EIC_EXTINT11)
#define PORT_PD11A_EIC_EXTINT11                    (_UINT32_(1) << 11)
#define PIN_PD11A_EIC_EXTINT_NUM                   _UINT32_(11) /* EIC signal: PIN_PD11 External Interrupt Line */

#define PIN_PA12A_EIC_EXTINT12                     _UINT32_(12)
#define MUX_PA12A_EIC_EXTINT12                     _UINT32_(0) 
#define PINMUX_PA12A_EIC_EXTINT12                  ((PIN_PA12A_EIC_EXTINT12 << 16) | MUX_PA12A_EIC_EXTINT12)
#define PORT_PA12A_EIC_EXTINT12                    (_UINT32_(1) << 12)
#define PIN_PA12A_EIC_EXTINT_NUM                   _UINT32_(12) /* EIC signal: PIN_PA12 External Interrupt Line */

#define PIN_PA28A_EIC_EXTINT12                     _UINT32_(28)
#define MUX_PA28A_EIC_EXTINT12                     _UINT32_(0) 
#define PINMUX_PA28A_EIC_EXTINT12                  ((PIN_PA28A_EIC_EXTINT12 << 16) | MUX_PA28A_EIC_EXTINT12)
#define PORT_PA28A_EIC_EXTINT12                    (_UINT32_(1) << 28)
#define PIN_PA28A_EIC_EXTINT_NUM                   _UINT32_(12) /* EIC signal: PIN_PA28 External Interrupt Line */

#define PIN_PB12A_EIC_EXTINT12                     _UINT32_(44)
#define MUX_PB12A_EIC_EXTINT12                     _UINT32_(0) 
#define PINMUX_PB12A_EIC_EXTINT12                  ((PIN_PB12A_EIC_EXTINT12 << 16) | MUX_PB12A_EIC_EXTINT12)
#define PORT_PB12A_EIC_EXTINT12                    (_UINT32_(1) << 12)
#define PIN_PB12A_EIC_EXTINT_NUM                   _UINT32_(12) /* EIC signal: PIN_PB12 External Interrupt Line */

#define PIN_PC12A_EIC_EXTINT12                     _UINT32_(76)
#define MUX_PC12A_EIC_EXTINT12                     _UINT32_(0) 
#define PINMUX_PC12A_EIC_EXTINT12                  ((PIN_PC12A_EIC_EXTINT12 << 16) | MUX_PC12A_EIC_EXTINT12)
#define PORT_PC12A_EIC_EXTINT12                    (_UINT32_(1) << 12)
#define PIN_PC12A_EIC_EXTINT_NUM                   _UINT32_(12) /* EIC signal: PIN_PC12 External Interrupt Line */

#define PIN_PC28A_EIC_EXTINT12                     _UINT32_(92)
#define MUX_PC28A_EIC_EXTINT12                     _UINT32_(0) 
#define PINMUX_PC28A_EIC_EXTINT12                  ((PIN_PC28A_EIC_EXTINT12 << 16) | MUX_PC28A_EIC_EXTINT12)
#define PORT_PC28A_EIC_EXTINT12                    (_UINT32_(1) << 28)
#define PIN_PC28A_EIC_EXTINT_NUM                   _UINT32_(12) /* EIC signal: PIN_PC28 External Interrupt Line */

#define PIN_PD12A_EIC_EXTINT12                     _UINT32_(108)
#define MUX_PD12A_EIC_EXTINT12                     _UINT32_(0) 
#define PINMUX_PD12A_EIC_EXTINT12                  ((PIN_PD12A_EIC_EXTINT12 << 16) | MUX_PD12A_EIC_EXTINT12)
#define PORT_PD12A_EIC_EXTINT12                    (_UINT32_(1) << 12)
#define PIN_PD12A_EIC_EXTINT_NUM                   _UINT32_(12) /* EIC signal: PIN_PD12 External Interrupt Line */

#define PIN_PA13A_EIC_EXTINT13                     _UINT32_(13)
#define MUX_PA13A_EIC_EXTINT13                     _UINT32_(0) 
#define PINMUX_PA13A_EIC_EXTINT13                  ((PIN_PA13A_EIC_EXTINT13 << 16) | MUX_PA13A_EIC_EXTINT13)
#define PORT_PA13A_EIC_EXTINT13                    (_UINT32_(1) << 13)
#define PIN_PA13A_EIC_EXTINT_NUM                   _UINT32_(13) /* EIC signal: PIN_PA13 External Interrupt Line */

#define PIN_PB13A_EIC_EXTINT13                     _UINT32_(45)
#define MUX_PB13A_EIC_EXTINT13                     _UINT32_(0) 
#define PINMUX_PB13A_EIC_EXTINT13                  ((PIN_PB13A_EIC_EXTINT13 << 16) | MUX_PB13A_EIC_EXTINT13)
#define PORT_PB13A_EIC_EXTINT13                    (_UINT32_(1) << 13)
#define PIN_PB13A_EIC_EXTINT_NUM                   _UINT32_(13) /* EIC signal: PIN_PB13 External Interrupt Line */

#define PIN_PC13A_EIC_EXTINT13                     _UINT32_(77)
#define MUX_PC13A_EIC_EXTINT13                     _UINT32_(0) 
#define PINMUX_PC13A_EIC_EXTINT13                  ((PIN_PC13A_EIC_EXTINT13 << 16) | MUX_PC13A_EIC_EXTINT13)
#define PORT_PC13A_EIC_EXTINT13                    (_UINT32_(1) << 13)
#define PIN_PC13A_EIC_EXTINT_NUM                   _UINT32_(13) /* EIC signal: PIN_PC13 External Interrupt Line */

#define PIN_PC29A_EIC_EXTINT13                     _UINT32_(93)
#define MUX_PC29A_EIC_EXTINT13                     _UINT32_(0) 
#define PINMUX_PC29A_EIC_EXTINT13                  ((PIN_PC29A_EIC_EXTINT13 << 16) | MUX_PC29A_EIC_EXTINT13)
#define PORT_PC29A_EIC_EXTINT13                    (_UINT32_(1) << 29)
#define PIN_PC29A_EIC_EXTINT_NUM                   _UINT32_(13) /* EIC signal: PIN_PC29 External Interrupt Line */

#define PIN_PD13A_EIC_EXTINT13                     _UINT32_(109)
#define MUX_PD13A_EIC_EXTINT13                     _UINT32_(0) 
#define PINMUX_PD13A_EIC_EXTINT13                  ((PIN_PD13A_EIC_EXTINT13 << 16) | MUX_PD13A_EIC_EXTINT13)
#define PORT_PD13A_EIC_EXTINT13                    (_UINT32_(1) << 13)
#define PIN_PD13A_EIC_EXTINT_NUM                   _UINT32_(13) /* EIC signal: PIN_PD13 External Interrupt Line */

#define PIN_PA00A_EIC_EXTINT14                     _UINT32_(0) 
#define MUX_PA00A_EIC_EXTINT14                     _UINT32_(0) 
#define PINMUX_PA00A_EIC_EXTINT14                  ((PIN_PA00A_EIC_EXTINT14 << 16) | MUX_PA00A_EIC_EXTINT14)
#define PORT_PA00A_EIC_EXTINT14                    (_UINT32_(1) << 0)
#define PIN_PA00A_EIC_EXTINT_NUM                   _UINT32_(14) /* EIC signal: PIN_PA00 External Interrupt Line */

#define PIN_PB14A_EIC_EXTINT14                     _UINT32_(46)
#define MUX_PB14A_EIC_EXTINT14                     _UINT32_(0) 
#define PINMUX_PB14A_EIC_EXTINT14                  ((PIN_PB14A_EIC_EXTINT14 << 16) | MUX_PB14A_EIC_EXTINT14)
#define PORT_PB14A_EIC_EXTINT14                    (_UINT32_(1) << 14)
#define PIN_PB14A_EIC_EXTINT_NUM                   _UINT32_(14) /* EIC signal: PIN_PB14 External Interrupt Line */

#define PIN_PC14A_EIC_EXTINT14                     _UINT32_(78)
#define MUX_PC14A_EIC_EXTINT14                     _UINT32_(0) 
#define PINMUX_PC14A_EIC_EXTINT14                  ((PIN_PC14A_EIC_EXTINT14 << 16) | MUX_PC14A_EIC_EXTINT14)
#define PORT_PC14A_EIC_EXTINT14                    (_UINT32_(1) << 14)
#define PIN_PC14A_EIC_EXTINT_NUM                   _UINT32_(14) /* EIC signal: PIN_PC14 External Interrupt Line */

#define PIN_PD14A_EIC_EXTINT14                     _UINT32_(110)
#define MUX_PD14A_EIC_EXTINT14                     _UINT32_(0) 
#define PINMUX_PD14A_EIC_EXTINT14                  ((PIN_PD14A_EIC_EXTINT14 << 16) | MUX_PD14A_EIC_EXTINT14)
#define PORT_PD14A_EIC_EXTINT14                    (_UINT32_(1) << 14)
#define PIN_PD14A_EIC_EXTINT_NUM                   _UINT32_(14) /* EIC signal: PIN_PD14 External Interrupt Line */

#define PIN_PA14A_EIC_EXTINT14                     _UINT32_(14)
#define MUX_PA14A_EIC_EXTINT14                     _UINT32_(0) 
#define PINMUX_PA14A_EIC_EXTINT14                  ((PIN_PA14A_EIC_EXTINT14 << 16) | MUX_PA14A_EIC_EXTINT14)
#define PORT_PA14A_EIC_EXTINT14                    (_UINT32_(1) << 14)
#define PIN_PA14A_EIC_EXTINT_NUM                   _UINT32_(14) /* EIC signal: PIN_PA14 External Interrupt Line */

#define PIN_PA15A_EIC_EXTINT15                     _UINT32_(15)
#define MUX_PA15A_EIC_EXTINT15                     _UINT32_(0) 
#define PINMUX_PA15A_EIC_EXTINT15                  ((PIN_PA15A_EIC_EXTINT15 << 16) | MUX_PA15A_EIC_EXTINT15)
#define PORT_PA15A_EIC_EXTINT15                    (_UINT32_(1) << 15)
#define PIN_PA15A_EIC_EXTINT_NUM                   _UINT32_(15) /* EIC signal: PIN_PA15 External Interrupt Line */

#define PIN_PB15A_EIC_EXTINT15                     _UINT32_(47)
#define MUX_PB15A_EIC_EXTINT15                     _UINT32_(0) 
#define PINMUX_PB15A_EIC_EXTINT15                  ((PIN_PB15A_EIC_EXTINT15 << 16) | MUX_PB15A_EIC_EXTINT15)
#define PORT_PB15A_EIC_EXTINT15                    (_UINT32_(1) << 15)
#define PIN_PB15A_EIC_EXTINT_NUM                   _UINT32_(15) /* EIC signal: PIN_PB15 External Interrupt Line */

#define PIN_PC15A_EIC_EXTINT15                     _UINT32_(79)
#define MUX_PC15A_EIC_EXTINT15                     _UINT32_(0) 
#define PINMUX_PC15A_EIC_EXTINT15                  ((PIN_PC15A_EIC_EXTINT15 << 16) | MUX_PC15A_EIC_EXTINT15)
#define PORT_PC15A_EIC_EXTINT15                    (_UINT32_(1) << 15)
#define PIN_PC15A_EIC_EXTINT_NUM                   _UINT32_(15) /* EIC signal: PIN_PC15 External Interrupt Line */

#define PIN_PD15A_EIC_EXTINT15                     _UINT32_(111)
#define MUX_PD15A_EIC_EXTINT15                     _UINT32_(0) 
#define PINMUX_PD15A_EIC_EXTINT15                  ((PIN_PD15A_EIC_EXTINT15 << 16) | MUX_PD15A_EIC_EXTINT15)
#define PORT_PD15A_EIC_EXTINT15                    (_UINT32_(1) << 15)
#define PIN_PD15A_EIC_EXTINT_NUM                   _UINT32_(15) /* EIC signal: PIN_PD15 External Interrupt Line */

#define PIN_PD02A_EIC_NMI                          _UINT32_(98)
#define MUX_PD02A_EIC_NMI                          _UINT32_(0) 
#define PINMUX_PD02A_EIC_NMI                       ((PIN_PD02A_EIC_NMI << 16) | MUX_PD02A_EIC_NMI)
#define PORT_PD02A_EIC_NMI                         (_UINT32_(1) << 2)

/* ========== PORT definition for ETH peripheral ========== */
#define PIN_PC18L_ETH_COL                          _UINT32_(82)
#define MUX_PC18L_ETH_COL                          _UINT32_(11)
#define PINMUX_PC18L_ETH_COL                       ((PIN_PC18L_ETH_COL << 16) | MUX_PC18L_ETH_COL)
#define PORT_PC18L_ETH_COL                         (_UINT32_(1) << 18)

#define PIN_PC17L_ETH_CRS                          _UINT32_(81)
#define MUX_PC17L_ETH_CRS                          _UINT32_(11)
#define PINMUX_PC17L_ETH_CRS                       ((PIN_PC17L_ETH_CRS << 16) | MUX_PC17L_ETH_CRS)
#define PORT_PC17L_ETH_CRS                         (_UINT32_(1) << 17)

#define PIN_PA11L_ETH_MDC                          _UINT32_(11)
#define MUX_PA11L_ETH_MDC                          _UINT32_(11)
#define PINMUX_PA11L_ETH_MDC                       ((PIN_PA11L_ETH_MDC << 16) | MUX_PA11L_ETH_MDC)
#define PORT_PA11L_ETH_MDC                         (_UINT32_(1) << 11)

#define PIN_PB10L_ETH_MDC                          _UINT32_(42)
#define MUX_PB10L_ETH_MDC                          _UINT32_(11)
#define PINMUX_PB10L_ETH_MDC                       ((PIN_PB10L_ETH_MDC << 16) | MUX_PB10L_ETH_MDC)
#define PORT_PB10L_ETH_MDC                         (_UINT32_(1) << 10)

#define PIN_PC03L_ETH_MDC                          _UINT32_(67)
#define MUX_PC03L_ETH_MDC                          _UINT32_(11)
#define PINMUX_PC03L_ETH_MDC                       ((PIN_PC03L_ETH_MDC << 16) | MUX_PC03L_ETH_MDC)
#define PORT_PC03L_ETH_MDC                         (_UINT32_(1) << 3)

#define PIN_PD07L_ETH_MDC                          _UINT32_(103)
#define MUX_PD07L_ETH_MDC                          _UINT32_(11)
#define PINMUX_PD07L_ETH_MDC                       ((PIN_PD07L_ETH_MDC << 16) | MUX_PD07L_ETH_MDC)
#define PORT_PD07L_ETH_MDC                         (_UINT32_(1) << 7)

#define PIN_PA12L_ETH_MDIO                         _UINT32_(12)
#define MUX_PA12L_ETH_MDIO                         _UINT32_(11)
#define PINMUX_PA12L_ETH_MDIO                      ((PIN_PA12L_ETH_MDIO << 16) | MUX_PA12L_ETH_MDIO)
#define PORT_PA12L_ETH_MDIO                        (_UINT32_(1) << 12)

#define PIN_PC02L_ETH_MDIO                         _UINT32_(66)
#define MUX_PC02L_ETH_MDIO                         _UINT32_(11)
#define PINMUX_PC02L_ETH_MDIO                      ((PIN_PC02L_ETH_MDIO << 16) | MUX_PC02L_ETH_MDIO)
#define PORT_PC02L_ETH_MDIO                        (_UINT32_(1) << 2)

#define PIN_PC04L_ETH_MDIO                         _UINT32_(68)
#define MUX_PC04L_ETH_MDIO                         _UINT32_(11)
#define PINMUX_PC04L_ETH_MDIO                      ((PIN_PC04L_ETH_MDIO << 16) | MUX_PC04L_ETH_MDIO)
#define PORT_PC04L_ETH_MDIO                        (_UINT32_(1) << 4)

#define PIN_PC21L_ETH_MDIO                         _UINT32_(85)
#define MUX_PC21L_ETH_MDIO                         _UINT32_(11)
#define PINMUX_PC21L_ETH_MDIO                      ((PIN_PC21L_ETH_MDIO << 16) | MUX_PC21L_ETH_MDIO)
#define PORT_PC21L_ETH_MDIO                        (_UINT32_(1) << 21)

#define PIN_PD06L_ETH_MDIO                         _UINT32_(102)
#define MUX_PD06L_ETH_MDIO                         _UINT32_(11)
#define PINMUX_PD06L_ETH_MDIO                      ((PIN_PD06L_ETH_MDIO << 16) | MUX_PD06L_ETH_MDIO)
#define PORT_PD06L_ETH_MDIO                        (_UINT32_(1) << 6)

#define PIN_PC00L_ETH_REF_CLK                      _UINT32_(64)
#define MUX_PC00L_ETH_REF_CLK                      _UINT32_(11)
#define PINMUX_PC00L_ETH_REF_CLK                   ((PIN_PC00L_ETH_REF_CLK << 16) | MUX_PC00L_ETH_REF_CLK)
#define PORT_PC00L_ETH_REF_CLK                     (_UINT32_(1) << 0)

#define PIN_PC07L_ETH_RXD0                         _UINT32_(71)
#define MUX_PC07L_ETH_RXD0                         _UINT32_(11)
#define PINMUX_PC07L_ETH_RXD0                      ((PIN_PC07L_ETH_RXD0 << 16) | MUX_PC07L_ETH_RXD0)
#define PORT_PC07L_ETH_RXD0                        (_UINT32_(1) << 7)

#define PIN_PC06L_ETH_RXD1                         _UINT32_(70)
#define MUX_PC06L_ETH_RXD1                         _UINT32_(11)
#define PINMUX_PC06L_ETH_RXD1                      ((PIN_PC06L_ETH_RXD1 << 16) | MUX_PC06L_ETH_RXD1)
#define PORT_PC06L_ETH_RXD1                        (_UINT32_(1) << 6)

#define PIN_PC05L_ETH_RXD2                         _UINT32_(69)
#define MUX_PC05L_ETH_RXD2                         _UINT32_(11)
#define PINMUX_PC05L_ETH_RXD2                      ((PIN_PC05L_ETH_RXD2 << 16) | MUX_PC05L_ETH_RXD2)
#define PORT_PC05L_ETH_RXD2                        (_UINT32_(1) << 5)

#define PIN_PC14L_ETH_RXD3                         _UINT32_(78)
#define MUX_PC14L_ETH_RXD3                         _UINT32_(11)
#define PINMUX_PC14L_ETH_RXD3                      ((PIN_PC14L_ETH_RXD3 << 16) | MUX_PC14L_ETH_RXD3)
#define PORT_PC14L_ETH_RXD3                        (_UINT32_(1) << 14)

#define PIN_PC10L_ETH_RXDV                         _UINT32_(74)
#define MUX_PC10L_ETH_RXDV                         _UINT32_(11)
#define PINMUX_PC10L_ETH_RXDV                      ((PIN_PC10L_ETH_RXDV << 16) | MUX_PC10L_ETH_RXDV)
#define PORT_PC10L_ETH_RXDV                        (_UINT32_(1) << 10)

#define PIN_PC09L_ETH_RXER                         _UINT32_(73)
#define MUX_PC09L_ETH_RXER                         _UINT32_(11)
#define PINMUX_PC09L_ETH_RXER                      ((PIN_PC09L_ETH_RXER << 16) | MUX_PC09L_ETH_RXER)
#define PORT_PC09L_ETH_RXER                        (_UINT32_(1) << 9)

#define PIN_PC15L_ETH_RX_CLK                       _UINT32_(79)
#define MUX_PC15L_ETH_RX_CLK                       _UINT32_(11)
#define PINMUX_PC15L_ETH_RX_CLK                    ((PIN_PC15L_ETH_RX_CLK << 16) | MUX_PC15L_ETH_RX_CLK)
#define PORT_PC15L_ETH_RX_CLK                      (_UINT32_(1) << 15)

#define PIN_PD02L_ETH_TSUCOMP                      _UINT32_(98)
#define MUX_PD02L_ETH_TSUCOMP                      _UINT32_(11)
#define PINMUX_PD02L_ETH_TSUCOMP                   ((PIN_PD02L_ETH_TSUCOMP << 16) | MUX_PD02L_ETH_TSUCOMP)
#define PORT_PD02L_ETH_TSUCOMP                     (_UINT32_(1) << 2)

#define PIN_PD16L_ETH_TSUCOMP                      _UINT32_(112)
#define MUX_PD16L_ETH_TSUCOMP                      _UINT32_(11)
#define PINMUX_PD16L_ETH_TSUCOMP                   ((PIN_PD16L_ETH_TSUCOMP << 16) | MUX_PD16L_ETH_TSUCOMP)
#define PORT_PD16L_ETH_TSUCOMP                     (_UINT32_(1) << 16)

#define PIN_PC12L_ETH_TXD0                         _UINT32_(76)
#define MUX_PC12L_ETH_TXD0                         _UINT32_(11)
#define PINMUX_PC12L_ETH_TXD0                      ((PIN_PC12L_ETH_TXD0 << 16) | MUX_PC12L_ETH_TXD0)
#define PORT_PC12L_ETH_TXD0                        (_UINT32_(1) << 12)

#define PIN_PC13L_ETH_TXD1                         _UINT32_(77)
#define MUX_PC13L_ETH_TXD1                         _UINT32_(11)
#define PINMUX_PC13L_ETH_TXD1                      ((PIN_PC13L_ETH_TXD1 << 16) | MUX_PC13L_ETH_TXD1)
#define PORT_PC13L_ETH_TXD1                        (_UINT32_(1) << 13)

#define PIN_PC19L_ETH_TXD2                         _UINT32_(83)
#define MUX_PC19L_ETH_TXD2                         _UINT32_(11)
#define PINMUX_PC19L_ETH_TXD2                      ((PIN_PC19L_ETH_TXD2 << 16) | MUX_PC19L_ETH_TXD2)
#define PORT_PC19L_ETH_TXD2                        (_UINT32_(1) << 19)

#define PIN_PC20L_ETH_TXD3                         _UINT32_(84)
#define MUX_PC20L_ETH_TXD3                         _UINT32_(11)
#define PINMUX_PC20L_ETH_TXD3                      ((PIN_PC20L_ETH_TXD3 << 16) | MUX_PC20L_ETH_TXD3)
#define PORT_PC20L_ETH_TXD3                        (_UINT32_(1) << 20)

#define PIN_PC11L_ETH_TXEN                         _UINT32_(75)
#define MUX_PC11L_ETH_TXEN                         _UINT32_(11)
#define PINMUX_PC11L_ETH_TXEN                      ((PIN_PC11L_ETH_TXEN << 16) | MUX_PC11L_ETH_TXEN)
#define PORT_PC11L_ETH_TXEN                        (_UINT32_(1) << 11)

#define PIN_PC16L_ETH_TXER                         _UINT32_(80)
#define MUX_PC16L_ETH_TXER                         _UINT32_(11)
#define PINMUX_PC16L_ETH_TXER                      ((PIN_PC16L_ETH_TXER << 16) | MUX_PC16L_ETH_TXER)
#define PORT_PC16L_ETH_TXER                        (_UINT32_(1) << 16)

#define PIN_PC00L_ETH_TX_CLK                       _UINT32_(64)
#define MUX_PC00L_ETH_TX_CLK                       _UINT32_(11)
#define PINMUX_PC00L_ETH_TX_CLK                    ((PIN_PC00L_ETH_TX_CLK << 16) | MUX_PC00L_ETH_TX_CLK)
#define PORT_PC00L_ETH_TX_CLK                      (_UINT32_(1) << 0)

/* ========== PORT definition for GCLK peripheral ========== */
#define PIN_PA09M_GCLK_IO0                         _UINT32_(9) 
#define MUX_PA09M_GCLK_IO0                         _UINT32_(12)
#define PINMUX_PA09M_GCLK_IO0                      ((PIN_PA09M_GCLK_IO0 << 16) | MUX_PA09M_GCLK_IO0)
#define PORT_PA09M_GCLK_IO0                        (_UINT32_(1) << 9)

#define PIN_PA03M_GCLK_IO0                         _UINT32_(3) 
#define MUX_PA03M_GCLK_IO0                         _UINT32_(12)
#define PINMUX_PA03M_GCLK_IO0                      ((PIN_PA03M_GCLK_IO0 << 16) | MUX_PA03M_GCLK_IO0)
#define PORT_PA03M_GCLK_IO0                        (_UINT32_(1) << 3)

#define PIN_PA01M_GCLK_IO1                         _UINT32_(1) 
#define MUX_PA01M_GCLK_IO1                         _UINT32_(12)
#define PINMUX_PA01M_GCLK_IO1                      ((PIN_PA01M_GCLK_IO1 << 16) | MUX_PA01M_GCLK_IO1)
#define PORT_PA01M_GCLK_IO1                        (_UINT32_(1) << 1)

#define PIN_PA10M_GCLK_IO1                         _UINT32_(10)
#define MUX_PA10M_GCLK_IO1                         _UINT32_(12)
#define PINMUX_PA10M_GCLK_IO1                      ((PIN_PA10M_GCLK_IO1 << 16) | MUX_PA10M_GCLK_IO1)
#define PORT_PA10M_GCLK_IO1                        (_UINT32_(1) << 10)

#define PIN_PA20M_GCLK_IO2                         _UINT32_(20)
#define MUX_PA20M_GCLK_IO2                         _UINT32_(12)
#define PINMUX_PA20M_GCLK_IO2                      ((PIN_PA20M_GCLK_IO2 << 16) | MUX_PA20M_GCLK_IO2)
#define PORT_PA20M_GCLK_IO2                        (_UINT32_(1) << 20)

#define PIN_PC00M_GCLK_IO2                         _UINT32_(64)
#define MUX_PC00M_GCLK_IO2                         _UINT32_(12)
#define PINMUX_PC00M_GCLK_IO2                      ((PIN_PC00M_GCLK_IO2 << 16) | MUX_PC00M_GCLK_IO2)
#define PORT_PC00M_GCLK_IO2                        (_UINT32_(1) << 0)

#define PIN_PD12M_GCLK_IO2                         _UINT32_(108)
#define MUX_PD12M_GCLK_IO2                         _UINT32_(12)
#define PINMUX_PD12M_GCLK_IO2                      ((PIN_PD12M_GCLK_IO2 << 16) | MUX_PD12M_GCLK_IO2)
#define PORT_PD12M_GCLK_IO2                        (_UINT32_(1) << 12)

#define PIN_PA21M_GCLK_IO3                         _UINT32_(21)
#define MUX_PA21M_GCLK_IO3                         _UINT32_(12)
#define PINMUX_PA21M_GCLK_IO3                      ((PIN_PA21M_GCLK_IO3 << 16) | MUX_PA21M_GCLK_IO3)
#define PORT_PA21M_GCLK_IO3                        (_UINT32_(1) << 21)

#define PIN_PC01M_GCLK_IO3                         _UINT32_(65)
#define MUX_PC01M_GCLK_IO3                         _UINT32_(12)
#define PINMUX_PC01M_GCLK_IO3                      ((PIN_PC01M_GCLK_IO3 << 16) | MUX_PC01M_GCLK_IO3)
#define PORT_PC01M_GCLK_IO3                        (_UINT32_(1) << 1)

#define PIN_PD05M_GCLK_IO3                         _UINT32_(101)
#define MUX_PD05M_GCLK_IO3                         _UINT32_(12)
#define PINMUX_PD05M_GCLK_IO3                      ((PIN_PD05M_GCLK_IO3 << 16) | MUX_PD05M_GCLK_IO3)
#define PORT_PD05M_GCLK_IO3                        (_UINT32_(1) << 5)

#define PIN_PA22M_GCLK_IO4                         _UINT32_(22)
#define MUX_PA22M_GCLK_IO4                         _UINT32_(12)
#define PINMUX_PA22M_GCLK_IO4                      ((PIN_PA22M_GCLK_IO4 << 16) | MUX_PA22M_GCLK_IO4)
#define PORT_PA22M_GCLK_IO4                        (_UINT32_(1) << 22)

#define PIN_PC02M_GCLK_IO4                         _UINT32_(66)
#define MUX_PC02M_GCLK_IO4                         _UINT32_(12)
#define PINMUX_PC02M_GCLK_IO4                      ((PIN_PC02M_GCLK_IO4 << 16) | MUX_PC02M_GCLK_IO4)
#define PORT_PC02M_GCLK_IO4                        (_UINT32_(1) << 2)

#define PIN_PD06M_GCLK_IO4                         _UINT32_(102)
#define MUX_PD06M_GCLK_IO4                         _UINT32_(12)
#define PINMUX_PD06M_GCLK_IO4                      ((PIN_PD06M_GCLK_IO4 << 16) | MUX_PD06M_GCLK_IO4)
#define PORT_PD06M_GCLK_IO4                        (_UINT32_(1) << 6)

#define PIN_PA23M_GCLK_IO5                         _UINT32_(23)
#define MUX_PA23M_GCLK_IO5                         _UINT32_(12)
#define PINMUX_PA23M_GCLK_IO5                      ((PIN_PA23M_GCLK_IO5 << 16) | MUX_PA23M_GCLK_IO5)
#define PORT_PA23M_GCLK_IO5                        (_UINT32_(1) << 23)

#define PIN_PC03M_GCLK_IO5                         _UINT32_(67)
#define MUX_PC03M_GCLK_IO5                         _UINT32_(12)
#define PINMUX_PC03M_GCLK_IO5                      ((PIN_PC03M_GCLK_IO5 << 16) | MUX_PC03M_GCLK_IO5)
#define PORT_PC03M_GCLK_IO5                        (_UINT32_(1) << 3)

#define PIN_PD07M_GCLK_IO5                         _UINT32_(103)
#define MUX_PD07M_GCLK_IO5                         _UINT32_(12)
#define PINMUX_PD07M_GCLK_IO5                      ((PIN_PD07M_GCLK_IO5 << 16) | MUX_PD07M_GCLK_IO5)
#define PORT_PD07M_GCLK_IO5                        (_UINT32_(1) << 7)

#define PIN_PA17M_GCLK_IO6                         _UINT32_(17)
#define MUX_PA17M_GCLK_IO6                         _UINT32_(12)
#define PINMUX_PA17M_GCLK_IO6                      ((PIN_PA17M_GCLK_IO6 << 16) | MUX_PA17M_GCLK_IO6)
#define PORT_PA17M_GCLK_IO6                        (_UINT32_(1) << 17)

#define PIN_PC04M_GCLK_IO6                         _UINT32_(68)
#define MUX_PC04M_GCLK_IO6                         _UINT32_(12)
#define PINMUX_PC04M_GCLK_IO6                      ((PIN_PC04M_GCLK_IO6 << 16) | MUX_PC04M_GCLK_IO6)
#define PORT_PC04M_GCLK_IO6                        (_UINT32_(1) << 4)

#define PIN_PA24M_GCLK_IO7                         _UINT32_(24)
#define MUX_PA24M_GCLK_IO7                         _UINT32_(12)
#define PINMUX_PA24M_GCLK_IO7                      ((PIN_PA24M_GCLK_IO7 << 16) | MUX_PA24M_GCLK_IO7)
#define PORT_PA24M_GCLK_IO7                        (_UINT32_(1) << 24)

#define PIN_PC05M_GCLK_IO7                         _UINT32_(69)
#define MUX_PC05M_GCLK_IO7                         _UINT32_(12)
#define PINMUX_PC05M_GCLK_IO7                      ((PIN_PC05M_GCLK_IO7 << 16) | MUX_PC05M_GCLK_IO7)
#define PORT_PC05M_GCLK_IO7                        (_UINT32_(1) << 5)

/* ========== PORT definition for PCC peripheral ========== */
#define PIN_PA20K_PCC_CLK                          _UINT32_(20)
#define MUX_PA20K_PCC_CLK                          _UINT32_(10)
#define PINMUX_PA20K_PCC_CLK                       ((PIN_PA20K_PCC_CLK << 16) | MUX_PA20K_PCC_CLK)
#define PORT_PA20K_PCC_CLK                         (_UINT32_(1) << 20)

#define PIN_PC05K_PCC_CLK                          _UINT32_(69)
#define MUX_PC05K_PCC_CLK                          _UINT32_(10)
#define PINMUX_PC05K_PCC_CLK                       ((PIN_PC05K_PCC_CLK << 16) | MUX_PC05K_PCC_CLK)
#define PORT_PC05K_PCC_CLK                         (_UINT32_(1) << 5)

#define PIN_PA21K_PCC_DATA0                        _UINT32_(21)
#define MUX_PA21K_PCC_DATA0                        _UINT32_(10)
#define PINMUX_PA21K_PCC_DATA0                     ((PIN_PA21K_PCC_DATA0 << 16) | MUX_PA21K_PCC_DATA0)
#define PORT_PA21K_PCC_DATA0                       (_UINT32_(1) << 21)

#define PIN_PC01K_PCC_DATA0                        _UINT32_(65)
#define MUX_PC01K_PCC_DATA0                        _UINT32_(10)
#define PINMUX_PC01K_PCC_DATA0                     ((PIN_PC01K_PCC_DATA0 << 16) | MUX_PC01K_PCC_DATA0)
#define PORT_PC01K_PCC_DATA0                       (_UINT32_(1) << 1)

#define PIN_PA22K_PCC_DATA1                        _UINT32_(22)
#define MUX_PA22K_PCC_DATA1                        _UINT32_(10)
#define PINMUX_PA22K_PCC_DATA1                     ((PIN_PA22K_PCC_DATA1 << 16) | MUX_PA22K_PCC_DATA1)
#define PORT_PA22K_PCC_DATA1                       (_UINT32_(1) << 22)

#define PIN_PC02K_PCC_DATA1                        _UINT32_(66)
#define MUX_PC02K_PCC_DATA1                        _UINT32_(10)
#define PINMUX_PC02K_PCC_DATA1                     ((PIN_PC02K_PCC_DATA1 << 16) | MUX_PC02K_PCC_DATA1)
#define PORT_PC02K_PCC_DATA1                       (_UINT32_(1) << 2)

#define PIN_PA23K_PCC_DATA2                        _UINT32_(23)
#define MUX_PA23K_PCC_DATA2                        _UINT32_(10)
#define PINMUX_PA23K_PCC_DATA2                     ((PIN_PA23K_PCC_DATA2 << 16) | MUX_PA23K_PCC_DATA2)
#define PORT_PA23K_PCC_DATA2                       (_UINT32_(1) << 23)

#define PIN_PC03K_PCC_DATA2                        _UINT32_(67)
#define MUX_PC03K_PCC_DATA2                        _UINT32_(10)
#define PINMUX_PC03K_PCC_DATA2                     ((PIN_PC03K_PCC_DATA2 << 16) | MUX_PC03K_PCC_DATA2)
#define PORT_PC03K_PCC_DATA2                       (_UINT32_(1) << 3)

#define PIN_PA24K_PCC_DATA3                        _UINT32_(24)
#define MUX_PA24K_PCC_DATA3                        _UINT32_(10)
#define PINMUX_PA24K_PCC_DATA3                     ((PIN_PA24K_PCC_DATA3 << 16) | MUX_PA24K_PCC_DATA3)
#define PORT_PA24K_PCC_DATA3                       (_UINT32_(1) << 24)

#define PIN_PB07K_PCC_DATA3                        _UINT32_(39)
#define MUX_PB07K_PCC_DATA3                        _UINT32_(10)
#define PINMUX_PB07K_PCC_DATA3                     ((PIN_PB07K_PCC_DATA3 << 16) | MUX_PB07K_PCC_DATA3)
#define PORT_PB07K_PCC_DATA3                       (_UINT32_(1) << 7)

#define PIN_PA25K_PCC_DATA4                        _UINT32_(25)
#define MUX_PA25K_PCC_DATA4                        _UINT32_(10)
#define PINMUX_PA25K_PCC_DATA4                     ((PIN_PA25K_PCC_DATA4 << 16) | MUX_PA25K_PCC_DATA4)
#define PORT_PA25K_PCC_DATA4                       (_UINT32_(1) << 25)

#define PIN_PB08K_PCC_DATA4                        _UINT32_(40)
#define MUX_PB08K_PCC_DATA4                        _UINT32_(10)
#define PINMUX_PB08K_PCC_DATA4                     ((PIN_PB08K_PCC_DATA4 << 16) | MUX_PB08K_PCC_DATA4)
#define PORT_PB08K_PCC_DATA4                       (_UINT32_(1) << 8)

#define PIN_PA26K_PCC_DATA5                        _UINT32_(26)
#define MUX_PA26K_PCC_DATA5                        _UINT32_(10)
#define PINMUX_PA26K_PCC_DATA5                     ((PIN_PA26K_PCC_DATA5 << 16) | MUX_PA26K_PCC_DATA5)
#define PORT_PA26K_PCC_DATA5                       (_UINT32_(1) << 26)

#define PIN_PB09K_PCC_DATA5                        _UINT32_(41)
#define MUX_PB09K_PCC_DATA5                        _UINT32_(10)
#define PINMUX_PB09K_PCC_DATA5                     ((PIN_PB09K_PCC_DATA5 << 16) | MUX_PB09K_PCC_DATA5)
#define PORT_PB09K_PCC_DATA5                       (_UINT32_(1) << 9)

#define PIN_PA27K_PCC_DATA6                        _UINT32_(27)
#define MUX_PA27K_PCC_DATA6                        _UINT32_(10)
#define PINMUX_PA27K_PCC_DATA6                     ((PIN_PA27K_PCC_DATA6 << 16) | MUX_PA27K_PCC_DATA6)
#define PORT_PA27K_PCC_DATA6                       (_UINT32_(1) << 27)

#define PIN_PB10K_PCC_DATA6                        _UINT32_(42)
#define MUX_PB10K_PCC_DATA6                        _UINT32_(10)
#define PINMUX_PB10K_PCC_DATA6                     ((PIN_PB10K_PCC_DATA6 << 16) | MUX_PB10K_PCC_DATA6)
#define PORT_PB10K_PCC_DATA6                       (_UINT32_(1) << 10)

#define PIN_PA28K_PCC_DATA7                        _UINT32_(28)
#define MUX_PA28K_PCC_DATA7                        _UINT32_(10)
#define PINMUX_PA28K_PCC_DATA7                     ((PIN_PA28K_PCC_DATA7 << 16) | MUX_PA28K_PCC_DATA7)
#define PORT_PA28K_PCC_DATA7                       (_UINT32_(1) << 28)

#define PIN_PC00K_PCC_DATA7                        _UINT32_(64)
#define MUX_PC00K_PCC_DATA7                        _UINT32_(10)
#define PINMUX_PC00K_PCC_DATA7                     ((PIN_PC00K_PCC_DATA7 << 16) | MUX_PC00K_PCC_DATA7)
#define PORT_PC00K_PCC_DATA7                       (_UINT32_(1) << 0)

#define PIN_PB18K_PCC_DATA8                        _UINT32_(50)
#define MUX_PB18K_PCC_DATA8                        _UINT32_(10)
#define PINMUX_PB18K_PCC_DATA8                     ((PIN_PB18K_PCC_DATA8 << 16) | MUX_PB18K_PCC_DATA8)
#define PORT_PB18K_PCC_DATA8                       (_UINT32_(1) << 18)

#define PIN_PC15K_PCC_DATA8                        _UINT32_(79)
#define MUX_PC15K_PCC_DATA8                        _UINT32_(10)
#define PINMUX_PC15K_PCC_DATA8                     ((PIN_PC15K_PCC_DATA8 << 16) | MUX_PC15K_PCC_DATA8)
#define PORT_PC15K_PCC_DATA8                       (_UINT32_(1) << 15)

#define PIN_PB19K_PCC_DATA9                        _UINT32_(51)
#define MUX_PB19K_PCC_DATA9                        _UINT32_(10)
#define PINMUX_PB19K_PCC_DATA9                     ((PIN_PB19K_PCC_DATA9 << 16) | MUX_PB19K_PCC_DATA9)
#define PORT_PB19K_PCC_DATA9                       (_UINT32_(1) << 19)

#define PIN_PC16K_PCC_DATA9                        _UINT32_(80)
#define MUX_PC16K_PCC_DATA9                        _UINT32_(10)
#define PINMUX_PC16K_PCC_DATA9                     ((PIN_PC16K_PCC_DATA9 << 16) | MUX_PC16K_PCC_DATA9)
#define PORT_PC16K_PCC_DATA9                       (_UINT32_(1) << 16)

#define PIN_PB20K_PCC_DATA10                       _UINT32_(52)
#define MUX_PB20K_PCC_DATA10                       _UINT32_(10)
#define PINMUX_PB20K_PCC_DATA10                    ((PIN_PB20K_PCC_DATA10 << 16) | MUX_PB20K_PCC_DATA10)
#define PORT_PB20K_PCC_DATA10                      (_UINT32_(1) << 20)

#define PIN_PC17K_PCC_DATA10                       _UINT32_(81)
#define MUX_PC17K_PCC_DATA10                       _UINT32_(10)
#define PINMUX_PC17K_PCC_DATA10                    ((PIN_PC17K_PCC_DATA10 << 16) | MUX_PC17K_PCC_DATA10)
#define PORT_PC17K_PCC_DATA10                      (_UINT32_(1) << 17)

#define PIN_PB26K_PCC_DATA11                       _UINT32_(58)
#define MUX_PB26K_PCC_DATA11                       _UINT32_(10)
#define PINMUX_PB26K_PCC_DATA11                    ((PIN_PB26K_PCC_DATA11 << 16) | MUX_PB26K_PCC_DATA11)
#define PORT_PB26K_PCC_DATA11                      (_UINT32_(1) << 26)

#define PIN_PC18K_PCC_DATA11                       _UINT32_(82)
#define MUX_PC18K_PCC_DATA11                       _UINT32_(10)
#define PINMUX_PC18K_PCC_DATA11                    ((PIN_PC18K_PCC_DATA11 << 16) | MUX_PC18K_PCC_DATA11)
#define PORT_PC18K_PCC_DATA11                      (_UINT32_(1) << 18)

#define PIN_PC19K_PCC_DATA12                       _UINT32_(83)
#define MUX_PC19K_PCC_DATA12                       _UINT32_(10)
#define PINMUX_PC19K_PCC_DATA12                    ((PIN_PC19K_PCC_DATA12 << 16) | MUX_PC19K_PCC_DATA12)
#define PORT_PC19K_PCC_DATA12                      (_UINT32_(1) << 19)

#define PIN_PC21K_PCC_DATA12                       _UINT32_(85)
#define MUX_PC21K_PCC_DATA12                       _UINT32_(10)
#define PINMUX_PC21K_PCC_DATA12                    ((PIN_PC21K_PCC_DATA12 << 16) | MUX_PC21K_PCC_DATA12)
#define PORT_PC21K_PCC_DATA12                      (_UINT32_(1) << 21)

#define PIN_PC20K_PCC_DATA13                       _UINT32_(84)
#define MUX_PC20K_PCC_DATA13                       _UINT32_(10)
#define PINMUX_PC20K_PCC_DATA13                    ((PIN_PC20K_PCC_DATA13 << 16) | MUX_PC20K_PCC_DATA13)
#define PORT_PC20K_PCC_DATA13                      (_UINT32_(1) << 20)

#define PIN_PC22K_PCC_DATA13                       _UINT32_(86)
#define MUX_PC22K_PCC_DATA13                       _UINT32_(10)
#define PINMUX_PC22K_PCC_DATA13                    ((PIN_PC22K_PCC_DATA13 << 16) | MUX_PC22K_PCC_DATA13)
#define PORT_PC22K_PCC_DATA13                      (_UINT32_(1) << 22)

#define PIN_PA10K_PCC_DEN1                         _UINT32_(10)
#define MUX_PA10K_PCC_DEN1                         _UINT32_(10)
#define PINMUX_PA10K_PCC_DEN1                      ((PIN_PA10K_PCC_DEN1 << 16) | MUX_PA10K_PCC_DEN1)
#define PORT_PA10K_PCC_DEN1                        (_UINT32_(1) << 10)

#define PIN_PC04K_PCC_DEN1                         _UINT32_(68)
#define MUX_PC04K_PCC_DEN1                         _UINT32_(10)
#define PINMUX_PC04K_PCC_DEN1                      ((PIN_PC04K_PCC_DEN1 << 16) | MUX_PC04K_PCC_DEN1)
#define PORT_PC04K_PCC_DEN1                        (_UINT32_(1) << 4)

#define PIN_PD19K_PCC_DEN1                         _UINT32_(115)
#define MUX_PD19K_PCC_DEN1                         _UINT32_(10)
#define PINMUX_PD19K_PCC_DEN1                      ((PIN_PD19K_PCC_DEN1 << 16) | MUX_PD19K_PCC_DEN1)
#define PORT_PD19K_PCC_DEN1                        (_UINT32_(1) << 19)

#define PIN_PC14K_PCC_DEN2                         _UINT32_(78)
#define MUX_PC14K_PCC_DEN2                         _UINT32_(10)
#define PINMUX_PC14K_PCC_DEN2                      ((PIN_PC14K_PCC_DEN2 << 16) | MUX_PC14K_PCC_DEN2)
#define PORT_PC14K_PCC_DEN2                        (_UINT32_(1) << 14)

#define PIN_PD02K_PCC_DEN2                         _UINT32_(98)
#define MUX_PD02K_PCC_DEN2                         _UINT32_(10)
#define PINMUX_PD02K_PCC_DEN2                      ((PIN_PD02K_PCC_DEN2 << 16) | MUX_PD02K_PCC_DEN2)
#define PORT_PD02K_PCC_DEN2                        (_UINT32_(1) << 2)

#define PIN_PD20K_PCC_DEN2                         _UINT32_(116)
#define MUX_PD20K_PCC_DEN2                         _UINT32_(10)
#define PINMUX_PD20K_PCC_DEN2                      ((PIN_PD20K_PCC_DEN2 << 16) | MUX_PD20K_PCC_DEN2)
#define PORT_PD20K_PCC_DEN2                        (_UINT32_(1) << 20)

/* ========== PORT definition for PDEC peripheral ========== */
#define PIN_PA20G_PDEC_QDI0                        _UINT32_(20)
#define MUX_PA20G_PDEC_QDI0                        _UINT32_(6) 
#define PINMUX_PA20G_PDEC_QDI0                     ((PIN_PA20G_PDEC_QDI0 << 16) | MUX_PA20G_PDEC_QDI0)
#define PORT_PA20G_PDEC_QDI0                       (_UINT32_(1) << 20)

#define PIN_PB04G_PDEC_QDI0                        _UINT32_(36)
#define MUX_PB04G_PDEC_QDI0                        _UINT32_(6) 
#define PINMUX_PB04G_PDEC_QDI0                     ((PIN_PB04G_PDEC_QDI0 << 16) | MUX_PB04G_PDEC_QDI0)
#define PORT_PB04G_PDEC_QDI0                       (_UINT32_(1) << 4)

#define PIN_PB07G_PDEC_QDI0                        _UINT32_(39)
#define MUX_PB07G_PDEC_QDI0                        _UINT32_(6) 
#define PINMUX_PB07G_PDEC_QDI0                     ((PIN_PB07G_PDEC_QDI0 << 16) | MUX_PB07G_PDEC_QDI0)
#define PORT_PB07G_PDEC_QDI0                       (_UINT32_(1) << 7)

#define PIN_PA21G_PDEC_QDI1                        _UINT32_(21)
#define MUX_PA21G_PDEC_QDI1                        _UINT32_(6) 
#define PINMUX_PA21G_PDEC_QDI1                     ((PIN_PA21G_PDEC_QDI1 << 16) | MUX_PA21G_PDEC_QDI1)
#define PORT_PA21G_PDEC_QDI1                       (_UINT32_(1) << 21)

#define PIN_PB05G_PDEC_QDI1                        _UINT32_(37)
#define MUX_PB05G_PDEC_QDI1                        _UINT32_(6) 
#define PINMUX_PB05G_PDEC_QDI1                     ((PIN_PB05G_PDEC_QDI1 << 16) | MUX_PB05G_PDEC_QDI1)
#define PORT_PB05G_PDEC_QDI1                       (_UINT32_(1) << 5)

#define PIN_PB08G_PDEC_QDI1                        _UINT32_(40)
#define MUX_PB08G_PDEC_QDI1                        _UINT32_(6) 
#define PINMUX_PB08G_PDEC_QDI1                     ((PIN_PB08G_PDEC_QDI1 << 16) | MUX_PB08G_PDEC_QDI1)
#define PORT_PB08G_PDEC_QDI1                       (_UINT32_(1) << 8)

#define PIN_PA22G_PDEC_QDI2                        _UINT32_(22)
#define MUX_PA22G_PDEC_QDI2                        _UINT32_(6) 
#define PINMUX_PA22G_PDEC_QDI2                     ((PIN_PA22G_PDEC_QDI2 << 16) | MUX_PA22G_PDEC_QDI2)
#define PORT_PA22G_PDEC_QDI2                       (_UINT32_(1) << 22)

#define PIN_PB09G_PDEC_QDI2                        _UINT32_(41)
#define MUX_PB09G_PDEC_QDI2                        _UINT32_(6) 
#define PINMUX_PB09G_PDEC_QDI2                     ((PIN_PB09G_PDEC_QDI2 << 16) | MUX_PB09G_PDEC_QDI2)
#define PORT_PB09G_PDEC_QDI2                       (_UINT32_(1) << 9)

#define PIN_PB13G_PDEC_QDI2                        _UINT32_(45)
#define MUX_PB13G_PDEC_QDI2                        _UINT32_(6) 
#define PINMUX_PB13G_PDEC_QDI2                     ((PIN_PB13G_PDEC_QDI2 << 16) | MUX_PB13G_PDEC_QDI2)
#define PORT_PB13G_PDEC_QDI2                       (_UINT32_(1) << 13)

/* ========== PORT definition for PTC peripheral ========== */
#define PIN_PA09N_PTC_DRV0                         _UINT32_(9) 
#define MUX_PA09N_PTC_DRV0                         _UINT32_(13)
#define PINMUX_PA09N_PTC_DRV0                      ((PIN_PA09N_PTC_DRV0 << 16) | MUX_PA09N_PTC_DRV0)
#define PORT_PA09N_PTC_DRV0                        (_UINT32_(1) << 9)

#define PIN_PA10N_PTC_DRV1                         _UINT32_(10)
#define MUX_PA10N_PTC_DRV1                         _UINT32_(13)
#define PINMUX_PA10N_PTC_DRV1                      ((PIN_PA10N_PTC_DRV1 << 16) | MUX_PA10N_PTC_DRV1)
#define PORT_PA10N_PTC_DRV1                        (_UINT32_(1) << 10)

#define PIN_PA11N_PTC_DRV2                         _UINT32_(11)
#define MUX_PA11N_PTC_DRV2                         _UINT32_(13)
#define PINMUX_PA11N_PTC_DRV2                      ((PIN_PA11N_PTC_DRV2 << 16) | MUX_PA11N_PTC_DRV2)
#define PORT_PA11N_PTC_DRV2                        (_UINT32_(1) << 11)

#define PIN_PA12N_PTC_DRV3                         _UINT32_(12)
#define MUX_PA12N_PTC_DRV3                         _UINT32_(13)
#define PINMUX_PA12N_PTC_DRV3                      ((PIN_PA12N_PTC_DRV3 << 16) | MUX_PA12N_PTC_DRV3)
#define PORT_PA12N_PTC_DRV3                        (_UINT32_(1) << 12)

#define PIN_PB00N_PTC_DRV4                         _UINT32_(32)
#define MUX_PB00N_PTC_DRV4                         _UINT32_(13)
#define PINMUX_PB00N_PTC_DRV4                      ((PIN_PB00N_PTC_DRV4 << 16) | MUX_PB00N_PTC_DRV4)
#define PORT_PB00N_PTC_DRV4                        (_UINT32_(1) << 0)

#define PIN_PB01N_PTC_DRV5                         _UINT32_(33)
#define MUX_PB01N_PTC_DRV5                         _UINT32_(13)
#define PINMUX_PB01N_PTC_DRV5                      ((PIN_PB01N_PTC_DRV5 << 16) | MUX_PB01N_PTC_DRV5)
#define PORT_PB01N_PTC_DRV5                        (_UINT32_(1) << 1)

#define PIN_PB07N_PTC_DRV6                         _UINT32_(39)
#define MUX_PB07N_PTC_DRV6                         _UINT32_(13)
#define PINMUX_PB07N_PTC_DRV6                      ((PIN_PB07N_PTC_DRV6 << 16) | MUX_PB07N_PTC_DRV6)
#define PORT_PB07N_PTC_DRV6                        (_UINT32_(1) << 7)

#define PIN_PB08N_PTC_DRV7                         _UINT32_(40)
#define MUX_PB08N_PTC_DRV7                         _UINT32_(13)
#define PINMUX_PB08N_PTC_DRV7                      ((PIN_PB08N_PTC_DRV7 << 16) | MUX_PB08N_PTC_DRV7)
#define PORT_PB08N_PTC_DRV7                        (_UINT32_(1) << 8)

#define PIN_PB09N_PTC_DRV8                         _UINT32_(41)
#define MUX_PB09N_PTC_DRV8                         _UINT32_(13)
#define PINMUX_PB09N_PTC_DRV8                      ((PIN_PB09N_PTC_DRV8 << 16) | MUX_PB09N_PTC_DRV8)
#define PORT_PB09N_PTC_DRV8                        (_UINT32_(1) << 9)

#define PIN_PB10N_PTC_DRV9                         _UINT32_(42)
#define MUX_PB10N_PTC_DRV9                         _UINT32_(13)
#define PINMUX_PB10N_PTC_DRV9                      ((PIN_PB10N_PTC_DRV9 << 16) | MUX_PB10N_PTC_DRV9)
#define PORT_PB10N_PTC_DRV9                        (_UINT32_(1) << 10)

#define PIN_PC00N_PTC_DRV10                        _UINT32_(64)
#define MUX_PC00N_PTC_DRV10                        _UINT32_(13)
#define PINMUX_PC00N_PTC_DRV10                     ((PIN_PC00N_PTC_DRV10 << 16) | MUX_PC00N_PTC_DRV10)
#define PORT_PC00N_PTC_DRV10                       (_UINT32_(1) << 0)

#define PIN_PC01N_PTC_DRV11                        _UINT32_(65)
#define MUX_PC01N_PTC_DRV11                        _UINT32_(13)
#define PINMUX_PC01N_PTC_DRV11                     ((PIN_PC01N_PTC_DRV11 << 16) | MUX_PC01N_PTC_DRV11)
#define PORT_PC01N_PTC_DRV11                       (_UINT32_(1) << 1)

#define PIN_PC02N_PTC_DRV12                        _UINT32_(66)
#define MUX_PC02N_PTC_DRV12                        _UINT32_(13)
#define PINMUX_PC02N_PTC_DRV12                     ((PIN_PC02N_PTC_DRV12 << 16) | MUX_PC02N_PTC_DRV12)
#define PORT_PC02N_PTC_DRV12                       (_UINT32_(1) << 2)

#define PIN_PC03N_PTC_DRV13                        _UINT32_(67)
#define MUX_PC03N_PTC_DRV13                        _UINT32_(13)
#define PINMUX_PC03N_PTC_DRV13                     ((PIN_PC03N_PTC_DRV13 << 16) | MUX_PC03N_PTC_DRV13)
#define PORT_PC03N_PTC_DRV13                       (_UINT32_(1) << 3)

#define PIN_PC04N_PTC_DRV14                        _UINT32_(68)
#define MUX_PC04N_PTC_DRV14                        _UINT32_(13)
#define PINMUX_PC04N_PTC_DRV14                     ((PIN_PC04N_PTC_DRV14 << 16) | MUX_PC04N_PTC_DRV14)
#define PORT_PC04N_PTC_DRV14                       (_UINT32_(1) << 4)

#define PIN_PC05N_PTC_DRV15                        _UINT32_(69)
#define MUX_PC05N_PTC_DRV15                        _UINT32_(13)
#define PINMUX_PC05N_PTC_DRV15                     ((PIN_PC05N_PTC_DRV15 << 16) | MUX_PC05N_PTC_DRV15)
#define PORT_PC05N_PTC_DRV15                       (_UINT32_(1) << 5)

#define PIN_PC06N_PTC_DRV16                        _UINT32_(70)
#define MUX_PC06N_PTC_DRV16                        _UINT32_(13)
#define PINMUX_PC06N_PTC_DRV16                     ((PIN_PC06N_PTC_DRV16 << 16) | MUX_PC06N_PTC_DRV16)
#define PORT_PC06N_PTC_DRV16                       (_UINT32_(1) << 6)

#define PIN_PC07N_PTC_DRV17                        _UINT32_(71)
#define MUX_PC07N_PTC_DRV17                        _UINT32_(13)
#define PINMUX_PC07N_PTC_DRV17                     ((PIN_PC07N_PTC_DRV17 << 16) | MUX_PC07N_PTC_DRV17)
#define PORT_PC07N_PTC_DRV17                       (_UINT32_(1) << 7)

#define PIN_PC13N_PTC_DRV18                        _UINT32_(77)
#define MUX_PC13N_PTC_DRV18                        _UINT32_(13)
#define PINMUX_PC13N_PTC_DRV18                     ((PIN_PC13N_PTC_DRV18 << 16) | MUX_PC13N_PTC_DRV18)
#define PORT_PC13N_PTC_DRV18                       (_UINT32_(1) << 13)

#define PIN_PC09N_PTC_DRV19                        _UINT32_(73)
#define MUX_PC09N_PTC_DRV19                        _UINT32_(13)
#define PINMUX_PC09N_PTC_DRV19                     ((PIN_PC09N_PTC_DRV19 << 16) | MUX_PC09N_PTC_DRV19)
#define PORT_PC09N_PTC_DRV19                       (_UINT32_(1) << 9)

#define PIN_PC10N_PTC_DRV20                        _UINT32_(74)
#define MUX_PC10N_PTC_DRV20                        _UINT32_(13)
#define PINMUX_PC10N_PTC_DRV20                     ((PIN_PC10N_PTC_DRV20 << 16) | MUX_PC10N_PTC_DRV20)
#define PORT_PC10N_PTC_DRV20                       (_UINT32_(1) << 10)

#define PIN_PC11N_PTC_DRV21                        _UINT32_(75)
#define MUX_PC11N_PTC_DRV21                        _UINT32_(13)
#define PINMUX_PC11N_PTC_DRV21                     ((PIN_PC11N_PTC_DRV21 << 16) | MUX_PC11N_PTC_DRV21)
#define PORT_PC11N_PTC_DRV21                       (_UINT32_(1) << 11)

#define PIN_PC12N_PTC_DRV22                        _UINT32_(76)
#define MUX_PC12N_PTC_DRV22                        _UINT32_(13)
#define PINMUX_PC12N_PTC_DRV22                     ((PIN_PC12N_PTC_DRV22 << 16) | MUX_PC12N_PTC_DRV22)
#define PORT_PC12N_PTC_DRV22                       (_UINT32_(1) << 12)

#define PIN_PC20N_PTC_DRV23                        _UINT32_(84)
#define MUX_PC20N_PTC_DRV23                        _UINT32_(13)
#define PINMUX_PC20N_PTC_DRV23                     ((PIN_PC20N_PTC_DRV23 << 16) | MUX_PC20N_PTC_DRV23)
#define PORT_PC20N_PTC_DRV23                       (_UINT32_(1) << 20)

#define PIN_PB16N_PTC_DRV24                        _UINT32_(48)
#define MUX_PB16N_PTC_DRV24                        _UINT32_(13)
#define PINMUX_PB16N_PTC_DRV24                     ((PIN_PB16N_PTC_DRV24 << 16) | MUX_PB16N_PTC_DRV24)
#define PORT_PB16N_PTC_DRV24                       (_UINT32_(1) << 16)

#define PIN_PB17N_PTC_DRV25                        _UINT32_(49)
#define MUX_PB17N_PTC_DRV25                        _UINT32_(13)
#define PINMUX_PB17N_PTC_DRV25                     ((PIN_PB17N_PTC_DRV25 << 16) | MUX_PB17N_PTC_DRV25)
#define PORT_PB17N_PTC_DRV25                       (_UINT32_(1) << 17)

#define PIN_PC14N_PTC_DRV26                        _UINT32_(78)
#define MUX_PC14N_PTC_DRV26                        _UINT32_(13)
#define PINMUX_PC14N_PTC_DRV26                     ((PIN_PC14N_PTC_DRV26 << 16) | MUX_PC14N_PTC_DRV26)
#define PORT_PC14N_PTC_DRV26                       (_UINT32_(1) << 14)

#define PIN_PC15N_PTC_DRV27                        _UINT32_(79)
#define MUX_PC15N_PTC_DRV27                        _UINT32_(13)
#define PINMUX_PC15N_PTC_DRV27                     ((PIN_PC15N_PTC_DRV27 << 16) | MUX_PC15N_PTC_DRV27)
#define PORT_PC15N_PTC_DRV27                       (_UINT32_(1) << 15)

#define PIN_PC16N_PTC_DRV28                        _UINT32_(80)
#define MUX_PC16N_PTC_DRV28                        _UINT32_(13)
#define PINMUX_PC16N_PTC_DRV28                     ((PIN_PC16N_PTC_DRV28 << 16) | MUX_PC16N_PTC_DRV28)
#define PORT_PC16N_PTC_DRV28                       (_UINT32_(1) << 16)

#define PIN_PC17N_PTC_DRV29                        _UINT32_(81)
#define MUX_PC17N_PTC_DRV29                        _UINT32_(13)
#define PINMUX_PC17N_PTC_DRV29                     ((PIN_PC17N_PTC_DRV29 << 16) | MUX_PC17N_PTC_DRV29)
#define PORT_PC17N_PTC_DRV29                       (_UINT32_(1) << 17)

#define PIN_PC18N_PTC_DRV30                        _UINT32_(82)
#define MUX_PC18N_PTC_DRV30                        _UINT32_(13)
#define PINMUX_PC18N_PTC_DRV30                     ((PIN_PC18N_PTC_DRV30 << 16) | MUX_PC18N_PTC_DRV30)
#define PORT_PC18N_PTC_DRV30                       (_UINT32_(1) << 18)

#define PIN_PC19N_PTC_DRV31                        _UINT32_(83)
#define MUX_PC19N_PTC_DRV31                        _UINT32_(13)
#define PINMUX_PC19N_PTC_DRV31                     ((PIN_PC19N_PTC_DRV31 << 16) | MUX_PC19N_PTC_DRV31)
#define PORT_PC19N_PTC_DRV31                       (_UINT32_(1) << 19)

#define PIN_PA18N_PTC_ECI0                         _UINT32_(18)
#define MUX_PA18N_PTC_ECI0                         _UINT32_(13)
#define PINMUX_PA18N_PTC_ECI0                      ((PIN_PA18N_PTC_ECI0 << 16) | MUX_PA18N_PTC_ECI0)
#define PORT_PA18N_PTC_ECI0                        (_UINT32_(1) << 18)

#define PIN_PA19N_PTC_ECI1                         _UINT32_(19)
#define MUX_PA19N_PTC_ECI1                         _UINT32_(13)
#define PINMUX_PA19N_PTC_ECI1                      ((PIN_PA19N_PTC_ECI1 << 16) | MUX_PA19N_PTC_ECI1)
#define PORT_PA19N_PTC_ECI1                        (_UINT32_(1) << 19)

/* ========== PORT definition for SDMMC0 peripheral ========== */
#define PIN_PA10I_SDMMC0_SDCD                      _UINT32_(10)
#define MUX_PA10I_SDMMC0_SDCD                      _UINT32_(8) 
#define PINMUX_PA10I_SDMMC0_SDCD                   ((PIN_PA10I_SDMMC0_SDCD << 16) | MUX_PA10I_SDMMC0_SDCD)
#define PORT_PA10I_SDMMC0_SDCD                     (_UINT32_(1) << 10)

#define PIN_PA12I_SDMMC0_SDCD                      _UINT32_(12)
#define MUX_PA12I_SDMMC0_SDCD                      _UINT32_(8) 
#define PINMUX_PA12I_SDMMC0_SDCD                   ((PIN_PA12I_SDMMC0_SDCD << 16) | MUX_PA12I_SDMMC0_SDCD)
#define PORT_PA12I_SDMMC0_SDCD                     (_UINT32_(1) << 12)

#define PIN_PD12I_SDMMC0_SDCD                      _UINT32_(108)
#define MUX_PD12I_SDMMC0_SDCD                      _UINT32_(8) 
#define PINMUX_PD12I_SDMMC0_SDCD                   ((PIN_PD12I_SDMMC0_SDCD << 16) | MUX_PD12I_SDMMC0_SDCD)
#define PORT_PD12I_SDMMC0_SDCD                     (_UINT32_(1) << 12)

#define PIN_PD10I_SDMMC0_SDCK                      _UINT32_(106)
#define MUX_PD10I_SDMMC0_SDCK                      _UINT32_(8) 
#define PINMUX_PD10I_SDMMC0_SDCK                   ((PIN_PD10I_SDMMC0_SDCK << 16) | MUX_PD10I_SDMMC0_SDCK)
#define PORT_PD10I_SDMMC0_SDCK                     (_UINT32_(1) << 10)

#define PIN_PD06I_SDMMC0_SDCMD                     _UINT32_(102)
#define MUX_PD06I_SDMMC0_SDCMD                     _UINT32_(8) 
#define PINMUX_PD06I_SDMMC0_SDCMD                  ((PIN_PD06I_SDMMC0_SDCMD << 16) | MUX_PD06I_SDMMC0_SDCMD)
#define PORT_PD06I_SDMMC0_SDCMD                    (_UINT32_(1) << 6)

#define PIN_PD07I_SDMMC0_SDDAT0                    _UINT32_(103)
#define MUX_PD07I_SDMMC0_SDDAT0                    _UINT32_(8) 
#define PINMUX_PD07I_SDMMC0_SDDAT0                 ((PIN_PD07I_SDMMC0_SDDAT0 << 16) | MUX_PD07I_SDMMC0_SDDAT0)
#define PORT_PD07I_SDMMC0_SDDAT0                   (_UINT32_(1) << 7)

#define PIN_PD11I_SDMMC0_SDDAT1                    _UINT32_(107)
#define MUX_PD11I_SDMMC0_SDDAT1                    _UINT32_(8) 
#define PINMUX_PD11I_SDMMC0_SDDAT1                 ((PIN_PD11I_SDMMC0_SDDAT1 << 16) | MUX_PD11I_SDMMC0_SDDAT1)
#define PORT_PD11I_SDMMC0_SDDAT1                   (_UINT32_(1) << 11)

#define PIN_PD08I_SDMMC0_SDDAT2                    _UINT32_(104)
#define MUX_PD08I_SDMMC0_SDDAT2                    _UINT32_(8) 
#define PINMUX_PD08I_SDMMC0_SDDAT2                 ((PIN_PD08I_SDMMC0_SDDAT2 << 16) | MUX_PD08I_SDMMC0_SDDAT2)
#define PORT_PD08I_SDMMC0_SDDAT2                   (_UINT32_(1) << 8)

#define PIN_PD09I_SDMMC0_SDDAT3                    _UINT32_(105)
#define MUX_PD09I_SDMMC0_SDDAT3                    _UINT32_(8) 
#define PINMUX_PD09I_SDMMC0_SDDAT3                 ((PIN_PD09I_SDMMC0_SDDAT3 << 16) | MUX_PD09I_SDMMC0_SDDAT3)
#define PORT_PD09I_SDMMC0_SDDAT3                   (_UINT32_(1) << 9)

#define PIN_PB00I_SDMMC0_SDWP                      _UINT32_(32)
#define MUX_PB00I_SDMMC0_SDWP                      _UINT32_(8) 
#define PINMUX_PB00I_SDMMC0_SDWP                   ((PIN_PB00I_SDMMC0_SDWP << 16) | MUX_PB00I_SDMMC0_SDWP)
#define PORT_PB00I_SDMMC0_SDWP                     (_UINT32_(1) << 0)

#define PIN_PD05I_SDMMC0_SDWP                      _UINT32_(101)
#define MUX_PD05I_SDMMC0_SDWP                      _UINT32_(8) 
#define PINMUX_PD05I_SDMMC0_SDWP                   ((PIN_PD05I_SDMMC0_SDWP << 16) | MUX_PD05I_SDMMC0_SDWP)
#define PORT_PD05I_SDMMC0_SDWP                     (_UINT32_(1) << 5)

/* ========== PORT definition for SDMMC1 peripheral ========== */
#define PIN_PC04I_SDMMC1_SDCD                      _UINT32_(68)
#define MUX_PC04I_SDMMC1_SDCD                      _UINT32_(8) 
#define PINMUX_PC04I_SDMMC1_SDCD                   ((PIN_PC04I_SDMMC1_SDCD << 16) | MUX_PC04I_SDMMC1_SDCD)
#define PORT_PC04I_SDMMC1_SDCD                     (_UINT32_(1) << 4)

#define PIN_PC05I_SDMMC1_SDCK                      _UINT32_(69)
#define MUX_PC05I_SDMMC1_SDCK                      _UINT32_(8) 
#define PINMUX_PC05I_SDMMC1_SDCK                   ((PIN_PC05I_SDMMC1_SDCK << 16) | MUX_PC05I_SDMMC1_SDCK)
#define PORT_PC05I_SDMMC1_SDCK                     (_UINT32_(1) << 5)

#define PIN_PB07I_SDMMC1_SDCMD                     _UINT32_(39)
#define MUX_PB07I_SDMMC1_SDCMD                     _UINT32_(8) 
#define PINMUX_PB07I_SDMMC1_SDCMD                  ((PIN_PB07I_SDMMC1_SDCMD << 16) | MUX_PB07I_SDMMC1_SDCMD)
#define PORT_PB07I_SDMMC1_SDCMD                    (_UINT32_(1) << 7)

#define PIN_PB10I_SDMMC1_SDDAT0                    _UINT32_(42)
#define MUX_PB10I_SDMMC1_SDDAT0                    _UINT32_(8) 
#define PINMUX_PB10I_SDMMC1_SDDAT0                 ((PIN_PB10I_SDMMC1_SDDAT0 << 16) | MUX_PB10I_SDMMC1_SDDAT0)
#define PORT_PB10I_SDMMC1_SDDAT0                   (_UINT32_(1) << 10)

#define PIN_PC00I_SDMMC1_SDDAT1                    _UINT32_(64)
#define MUX_PC00I_SDMMC1_SDDAT1                    _UINT32_(8) 
#define PINMUX_PC00I_SDMMC1_SDDAT1                 ((PIN_PC00I_SDMMC1_SDDAT1 << 16) | MUX_PC00I_SDMMC1_SDDAT1)
#define PORT_PC00I_SDMMC1_SDDAT1                   (_UINT32_(1) << 0)

#define PIN_PC01I_SDMMC1_SDDAT2                    _UINT32_(65)
#define MUX_PC01I_SDMMC1_SDDAT2                    _UINT32_(8) 
#define PINMUX_PC01I_SDMMC1_SDDAT2                 ((PIN_PC01I_SDMMC1_SDDAT2 << 16) | MUX_PC01I_SDMMC1_SDDAT2)
#define PORT_PC01I_SDMMC1_SDDAT2                   (_UINT32_(1) << 1)

#define PIN_PC02I_SDMMC1_SDDAT3                    _UINT32_(66)
#define MUX_PC02I_SDMMC1_SDDAT3                    _UINT32_(8) 
#define PINMUX_PC02I_SDMMC1_SDDAT3                 ((PIN_PC02I_SDMMC1_SDDAT3 << 16) | MUX_PC02I_SDMMC1_SDDAT3)
#define PORT_PC02I_SDMMC1_SDDAT3                   (_UINT32_(1) << 2)

#define PIN_PC03I_SDMMC1_SDWP                      _UINT32_(67)
#define MUX_PC03I_SDMMC1_SDWP                      _UINT32_(8) 
#define PINMUX_PC03I_SDMMC1_SDWP                   ((PIN_PC03I_SDMMC1_SDWP << 16) | MUX_PC03I_SDMMC1_SDWP)
#define PORT_PC03I_SDMMC1_SDWP                     (_UINT32_(1) << 3)

/* ========== PORT definition for SERCOM0 peripheral ========== */
#define PIN_PC10C_SERCOM0_PAD0                     _UINT32_(74)
#define MUX_PC10C_SERCOM0_PAD0                     _UINT32_(2) 
#define PINMUX_PC10C_SERCOM0_PAD0                  ((PIN_PC10C_SERCOM0_PAD0 << 16) | MUX_PC10C_SERCOM0_PAD0)
#define PORT_PC10C_SERCOM0_PAD0                    (_UINT32_(1) << 10)

#define PIN_PD06C_SERCOM0_PAD0                     _UINT32_(102)
#define MUX_PD06C_SERCOM0_PAD0                     _UINT32_(2) 
#define PINMUX_PD06C_SERCOM0_PAD0                  ((PIN_PD06C_SERCOM0_PAD0 << 16) | MUX_PD06C_SERCOM0_PAD0)
#define PORT_PD06C_SERCOM0_PAD0                    (_UINT32_(1) << 6)

#define PIN_PD17C_SERCOM0_PAD0                     _UINT32_(113)
#define MUX_PD17C_SERCOM0_PAD0                     _UINT32_(2) 
#define PINMUX_PD17C_SERCOM0_PAD0                  ((PIN_PD17C_SERCOM0_PAD0 << 16) | MUX_PD17C_SERCOM0_PAD0)
#define PORT_PD17C_SERCOM0_PAD0                    (_UINT32_(1) << 17)

#define PIN_PC11C_SERCOM0_PAD1                     _UINT32_(75)
#define MUX_PC11C_SERCOM0_PAD1                     _UINT32_(2) 
#define PINMUX_PC11C_SERCOM0_PAD1                  ((PIN_PC11C_SERCOM0_PAD1 << 16) | MUX_PC11C_SERCOM0_PAD1)
#define PORT_PC11C_SERCOM0_PAD1                    (_UINT32_(1) << 11)

#define PIN_PD07C_SERCOM0_PAD1                     _UINT32_(103)
#define MUX_PD07C_SERCOM0_PAD1                     _UINT32_(2) 
#define PINMUX_PD07C_SERCOM0_PAD1                  ((PIN_PD07C_SERCOM0_PAD1 << 16) | MUX_PD07C_SERCOM0_PAD1)
#define PORT_PD07C_SERCOM0_PAD1                    (_UINT32_(1) << 7)

#define PIN_PD18C_SERCOM0_PAD1                     _UINT32_(114)
#define MUX_PD18C_SERCOM0_PAD1                     _UINT32_(2) 
#define PINMUX_PD18C_SERCOM0_PAD1                  ((PIN_PD18C_SERCOM0_PAD1 << 16) | MUX_PD18C_SERCOM0_PAD1)
#define PORT_PD18C_SERCOM0_PAD1                    (_UINT32_(1) << 18)

#define PIN_PC12C_SERCOM0_PAD2                     _UINT32_(76)
#define MUX_PC12C_SERCOM0_PAD2                     _UINT32_(2) 
#define PINMUX_PC12C_SERCOM0_PAD2                  ((PIN_PC12C_SERCOM0_PAD2 << 16) | MUX_PC12C_SERCOM0_PAD2)
#define PORT_PC12C_SERCOM0_PAD2                    (_UINT32_(1) << 12)

#define PIN_PD05C_SERCOM0_PAD2                     _UINT32_(101)
#define MUX_PD05C_SERCOM0_PAD2                     _UINT32_(2) 
#define PINMUX_PD05C_SERCOM0_PAD2                  ((PIN_PD05C_SERCOM0_PAD2 << 16) | MUX_PD05C_SERCOM0_PAD2)
#define PORT_PD05C_SERCOM0_PAD2                    (_UINT32_(1) << 5)

#define PIN_PD19C_SERCOM0_PAD2                     _UINT32_(115)
#define MUX_PD19C_SERCOM0_PAD2                     _UINT32_(2) 
#define PINMUX_PD19C_SERCOM0_PAD2                  ((PIN_PD19C_SERCOM0_PAD2 << 16) | MUX_PD19C_SERCOM0_PAD2)
#define PORT_PD19C_SERCOM0_PAD2                    (_UINT32_(1) << 19)

#define PIN_PC13C_SERCOM0_PAD3                     _UINT32_(77)
#define MUX_PC13C_SERCOM0_PAD3                     _UINT32_(2) 
#define PINMUX_PC13C_SERCOM0_PAD3                  ((PIN_PC13C_SERCOM0_PAD3 << 16) | MUX_PC13C_SERCOM0_PAD3)
#define PORT_PC13C_SERCOM0_PAD3                    (_UINT32_(1) << 13)

#define PIN_PD12C_SERCOM0_PAD3                     _UINT32_(108)
#define MUX_PD12C_SERCOM0_PAD3                     _UINT32_(2) 
#define PINMUX_PD12C_SERCOM0_PAD3                  ((PIN_PD12C_SERCOM0_PAD3 << 16) | MUX_PD12C_SERCOM0_PAD3)
#define PORT_PD12C_SERCOM0_PAD3                    (_UINT32_(1) << 12)

#define PIN_PD20C_SERCOM0_PAD3                     _UINT32_(116)
#define MUX_PD20C_SERCOM0_PAD3                     _UINT32_(2) 
#define PINMUX_PD20C_SERCOM0_PAD3                  ((PIN_PD20C_SERCOM0_PAD3 << 16) | MUX_PD20C_SERCOM0_PAD3)
#define PORT_PD20C_SERCOM0_PAD3                    (_UINT32_(1) << 20)

/* ========== PORT definition for SERCOM1 peripheral ========== */
#define PIN_PD08C_SERCOM1_PAD0                     _UINT32_(104)
#define MUX_PD08C_SERCOM1_PAD0                     _UINT32_(2) 
#define PINMUX_PD08C_SERCOM1_PAD0                  ((PIN_PD08C_SERCOM1_PAD0 << 16) | MUX_PD08C_SERCOM1_PAD0)
#define PORT_PD08C_SERCOM1_PAD0                    (_UINT32_(1) << 8)

#define PIN_PD13C_SERCOM1_PAD0                     _UINT32_(109)
#define MUX_PD13C_SERCOM1_PAD0                     _UINT32_(2) 
#define PINMUX_PD13C_SERCOM1_PAD0                  ((PIN_PD13C_SERCOM1_PAD0 << 16) | MUX_PD13C_SERCOM1_PAD0)
#define PORT_PD13C_SERCOM1_PAD0                    (_UINT32_(1) << 13)

#define PIN_PD09C_SERCOM1_PAD1                     _UINT32_(105)
#define MUX_PD09C_SERCOM1_PAD1                     _UINT32_(2) 
#define PINMUX_PD09C_SERCOM1_PAD1                  ((PIN_PD09C_SERCOM1_PAD1 << 16) | MUX_PD09C_SERCOM1_PAD1)
#define PORT_PD09C_SERCOM1_PAD1                    (_UINT32_(1) << 9)

#define PIN_PD14C_SERCOM1_PAD1                     _UINT32_(110)
#define MUX_PD14C_SERCOM1_PAD1                     _UINT32_(2) 
#define PINMUX_PD14C_SERCOM1_PAD1                  ((PIN_PD14C_SERCOM1_PAD1 << 16) | MUX_PD14C_SERCOM1_PAD1)
#define PORT_PD14C_SERCOM1_PAD1                    (_UINT32_(1) << 14)

#define PIN_PD10C_SERCOM1_PAD2                     _UINT32_(106)
#define MUX_PD10C_SERCOM1_PAD2                     _UINT32_(2) 
#define PINMUX_PD10C_SERCOM1_PAD2                  ((PIN_PD10C_SERCOM1_PAD2 << 16) | MUX_PD10C_SERCOM1_PAD2)
#define PORT_PD10C_SERCOM1_PAD2                    (_UINT32_(1) << 10)

#define PIN_PD15C_SERCOM1_PAD2                     _UINT32_(111)
#define MUX_PD15C_SERCOM1_PAD2                     _UINT32_(2) 
#define PINMUX_PD15C_SERCOM1_PAD2                  ((PIN_PD15C_SERCOM1_PAD2 << 16) | MUX_PD15C_SERCOM1_PAD2)
#define PORT_PD15C_SERCOM1_PAD2                    (_UINT32_(1) << 15)

#define PIN_PD11C_SERCOM1_PAD3                     _UINT32_(107)
#define MUX_PD11C_SERCOM1_PAD3                     _UINT32_(2) 
#define PINMUX_PD11C_SERCOM1_PAD3                  ((PIN_PD11C_SERCOM1_PAD3 << 16) | MUX_PD11C_SERCOM1_PAD3)
#define PORT_PD11C_SERCOM1_PAD3                    (_UINT32_(1) << 11)

#define PIN_PD16C_SERCOM1_PAD3                     _UINT32_(112)
#define MUX_PD16C_SERCOM1_PAD3                     _UINT32_(2) 
#define PINMUX_PD16C_SERCOM1_PAD3                  ((PIN_PD16C_SERCOM1_PAD3 << 16) | MUX_PD16C_SERCOM1_PAD3)
#define PORT_PD16C_SERCOM1_PAD3                    (_UINT32_(1) << 16)

/* ========== PORT definition for SERCOM2 peripheral ========== */
#define PIN_PC11D_SERCOM2_PAD0                     _UINT32_(75)
#define MUX_PC11D_SERCOM2_PAD0                     _UINT32_(3) 
#define PINMUX_PC11D_SERCOM2_PAD0                  ((PIN_PC11D_SERCOM2_PAD0 << 16) | MUX_PC11D_SERCOM2_PAD0)
#define PORT_PC11D_SERCOM2_PAD0                    (_UINT32_(1) << 11)

#define PIN_PC06C_SERCOM2_PAD0                     _UINT32_(70)
#define MUX_PC06C_SERCOM2_PAD0                     _UINT32_(2) 
#define PINMUX_PC06C_SERCOM2_PAD0                  ((PIN_PC06C_SERCOM2_PAD0 << 16) | MUX_PC06C_SERCOM2_PAD0)
#define PORT_PC06C_SERCOM2_PAD0                    (_UINT32_(1) << 6)

#define PIN_PC15C_SERCOM2_PAD0                     _UINT32_(79)
#define MUX_PC15C_SERCOM2_PAD0                     _UINT32_(2) 
#define PINMUX_PC15C_SERCOM2_PAD0                  ((PIN_PC15C_SERCOM2_PAD0 << 16) | MUX_PC15C_SERCOM2_PAD0)
#define PORT_PC15C_SERCOM2_PAD0                    (_UINT32_(1) << 15)

#define PIN_PC21C_SERCOM2_PAD0                     _UINT32_(85)
#define MUX_PC21C_SERCOM2_PAD0                     _UINT32_(2) 
#define PINMUX_PC21C_SERCOM2_PAD0                  ((PIN_PC21C_SERCOM2_PAD0 << 16) | MUX_PC21C_SERCOM2_PAD0)
#define PORT_PC21C_SERCOM2_PAD0                    (_UINT32_(1) << 21)

#define PIN_PC10D_SERCOM2_PAD1                     _UINT32_(74)
#define MUX_PC10D_SERCOM2_PAD1                     _UINT32_(3) 
#define PINMUX_PC10D_SERCOM2_PAD1                  ((PIN_PC10D_SERCOM2_PAD1 << 16) | MUX_PC10D_SERCOM2_PAD1)
#define PORT_PC10D_SERCOM2_PAD1                    (_UINT32_(1) << 10)

#define PIN_PC07C_SERCOM2_PAD1                     _UINT32_(71)
#define MUX_PC07C_SERCOM2_PAD1                     _UINT32_(2) 
#define PINMUX_PC07C_SERCOM2_PAD1                  ((PIN_PC07C_SERCOM2_PAD1 << 16) | MUX_PC07C_SERCOM2_PAD1)
#define PORT_PC07C_SERCOM2_PAD1                    (_UINT32_(1) << 7)

#define PIN_PC16C_SERCOM2_PAD1                     _UINT32_(80)
#define MUX_PC16C_SERCOM2_PAD1                     _UINT32_(2) 
#define PINMUX_PC16C_SERCOM2_PAD1                  ((PIN_PC16C_SERCOM2_PAD1 << 16) | MUX_PC16C_SERCOM2_PAD1)
#define PORT_PC16C_SERCOM2_PAD1                    (_UINT32_(1) << 16)

#define PIN_PC22C_SERCOM2_PAD1                     _UINT32_(86)
#define MUX_PC22C_SERCOM2_PAD1                     _UINT32_(2) 
#define PINMUX_PC22C_SERCOM2_PAD1                  ((PIN_PC22C_SERCOM2_PAD1 << 16) | MUX_PC22C_SERCOM2_PAD1)
#define PORT_PC22C_SERCOM2_PAD1                    (_UINT32_(1) << 22)

#define PIN_PC12D_SERCOM2_PAD2                     _UINT32_(76)
#define MUX_PC12D_SERCOM2_PAD2                     _UINT32_(3) 
#define PINMUX_PC12D_SERCOM2_PAD2                  ((PIN_PC12D_SERCOM2_PAD2 << 16) | MUX_PC12D_SERCOM2_PAD2)
#define PORT_PC12D_SERCOM2_PAD2                    (_UINT32_(1) << 12)

#define PIN_PC09C_SERCOM2_PAD2                     _UINT32_(73)
#define MUX_PC09C_SERCOM2_PAD2                     _UINT32_(2) 
#define PINMUX_PC09C_SERCOM2_PAD2                  ((PIN_PC09C_SERCOM2_PAD2 << 16) | MUX_PC09C_SERCOM2_PAD2)
#define PORT_PC09C_SERCOM2_PAD2                    (_UINT32_(1) << 9)

#define PIN_PC14C_SERCOM2_PAD2                     _UINT32_(78)
#define MUX_PC14C_SERCOM2_PAD2                     _UINT32_(2) 
#define PINMUX_PC14C_SERCOM2_PAD2                  ((PIN_PC14C_SERCOM2_PAD2 << 16) | MUX_PC14C_SERCOM2_PAD2)
#define PORT_PC14C_SERCOM2_PAD2                    (_UINT32_(1) << 14)

#define PIN_PC17C_SERCOM2_PAD2                     _UINT32_(81)
#define MUX_PC17C_SERCOM2_PAD2                     _UINT32_(2) 
#define PINMUX_PC17C_SERCOM2_PAD2                  ((PIN_PC17C_SERCOM2_PAD2 << 16) | MUX_PC17C_SERCOM2_PAD2)
#define PORT_PC17C_SERCOM2_PAD2                    (_UINT32_(1) << 17)

#define PIN_PC13D_SERCOM2_PAD3                     _UINT32_(77)
#define MUX_PC13D_SERCOM2_PAD3                     _UINT32_(3) 
#define PINMUX_PC13D_SERCOM2_PAD3                  ((PIN_PC13D_SERCOM2_PAD3 << 16) | MUX_PC13D_SERCOM2_PAD3)
#define PORT_PC13D_SERCOM2_PAD3                    (_UINT32_(1) << 13)

#define PIN_PC18C_SERCOM2_PAD3                     _UINT32_(82)
#define MUX_PC18C_SERCOM2_PAD3                     _UINT32_(2) 
#define PINMUX_PC18C_SERCOM2_PAD3                  ((PIN_PC18C_SERCOM2_PAD3 << 16) | MUX_PC18C_SERCOM2_PAD3)
#define PORT_PC18C_SERCOM2_PAD3                    (_UINT32_(1) << 18)

#define PIN_PC23C_SERCOM2_PAD3                     _UINT32_(87)
#define MUX_PC23C_SERCOM2_PAD3                     _UINT32_(2) 
#define PINMUX_PC23C_SERCOM2_PAD3                  ((PIN_PC23C_SERCOM2_PAD3 << 16) | MUX_PC23C_SERCOM2_PAD3)
#define PORT_PC23C_SERCOM2_PAD3                    (_UINT32_(1) << 23)

#define PIN_PC26C_SERCOM2_PAD3                     _UINT32_(90)
#define MUX_PC26C_SERCOM2_PAD3                     _UINT32_(2) 
#define PINMUX_PC26C_SERCOM2_PAD3                  ((PIN_PC26C_SERCOM2_PAD3 << 16) | MUX_PC26C_SERCOM2_PAD3)
#define PORT_PC26C_SERCOM2_PAD3                    (_UINT32_(1) << 26)

/* ========== PORT definition for SERCOM3 peripheral ========== */
#define PIN_PC07D_SERCOM3_PAD0                     _UINT32_(71)
#define MUX_PC07D_SERCOM3_PAD0                     _UINT32_(3) 
#define PINMUX_PC07D_SERCOM3_PAD0                  ((PIN_PC07D_SERCOM3_PAD0 << 16) | MUX_PC07D_SERCOM3_PAD0)
#define PORT_PC07D_SERCOM3_PAD0                    (_UINT32_(1) << 7)

#define PIN_PB16C_SERCOM3_PAD0                     _UINT32_(48)
#define MUX_PB16C_SERCOM3_PAD0                     _UINT32_(2) 
#define PINMUX_PB16C_SERCOM3_PAD0                  ((PIN_PB16C_SERCOM3_PAD0 << 16) | MUX_PB16C_SERCOM3_PAD0)
#define PORT_PB16C_SERCOM3_PAD0                    (_UINT32_(1) << 16)

#define PIN_PB21C_SERCOM3_PAD0                     _UINT32_(53)
#define MUX_PB21C_SERCOM3_PAD0                     _UINT32_(2) 
#define PINMUX_PB21C_SERCOM3_PAD0                  ((PIN_PB21C_SERCOM3_PAD0 << 16) | MUX_PB21C_SERCOM3_PAD0)
#define PORT_PB21C_SERCOM3_PAD0                    (_UINT32_(1) << 21)

#define PIN_PC02C_SERCOM3_PAD0                     _UINT32_(66)
#define MUX_PC02C_SERCOM3_PAD0                     _UINT32_(2) 
#define PINMUX_PC02C_SERCOM3_PAD0                  ((PIN_PC02C_SERCOM3_PAD0 << 16) | MUX_PC02C_SERCOM3_PAD0)
#define PORT_PC02C_SERCOM3_PAD0                    (_UINT32_(1) << 2)

#define PIN_PC06D_SERCOM3_PAD1                     _UINT32_(70)
#define MUX_PC06D_SERCOM3_PAD1                     _UINT32_(3) 
#define PINMUX_PC06D_SERCOM3_PAD1                  ((PIN_PC06D_SERCOM3_PAD1 << 16) | MUX_PC06D_SERCOM3_PAD1)
#define PORT_PC06D_SERCOM3_PAD1                    (_UINT32_(1) << 6)

#define PIN_PB17C_SERCOM3_PAD1                     _UINT32_(49)
#define MUX_PB17C_SERCOM3_PAD1                     _UINT32_(2) 
#define PINMUX_PB17C_SERCOM3_PAD1                  ((PIN_PB17C_SERCOM3_PAD1 << 16) | MUX_PB17C_SERCOM3_PAD1)
#define PORT_PB17C_SERCOM3_PAD1                    (_UINT32_(1) << 17)

#define PIN_PB22C_SERCOM3_PAD1                     _UINT32_(54)
#define MUX_PB22C_SERCOM3_PAD1                     _UINT32_(2) 
#define PINMUX_PB22C_SERCOM3_PAD1                  ((PIN_PB22C_SERCOM3_PAD1 << 16) | MUX_PB22C_SERCOM3_PAD1)
#define PORT_PB22C_SERCOM3_PAD1                    (_UINT32_(1) << 22)

#define PIN_PC03C_SERCOM3_PAD1                     _UINT32_(67)
#define MUX_PC03C_SERCOM3_PAD1                     _UINT32_(2) 
#define PINMUX_PC03C_SERCOM3_PAD1                  ((PIN_PC03C_SERCOM3_PAD1 << 16) | MUX_PC03C_SERCOM3_PAD1)
#define PORT_PC03C_SERCOM3_PAD1                    (_UINT32_(1) << 3)

#define PIN_PC09D_SERCOM3_PAD2                     _UINT32_(73)
#define MUX_PC09D_SERCOM3_PAD2                     _UINT32_(3) 
#define PINMUX_PC09D_SERCOM3_PAD2                  ((PIN_PC09D_SERCOM3_PAD2 << 16) | MUX_PC09D_SERCOM3_PAD2)
#define PORT_PC09D_SERCOM3_PAD2                    (_UINT32_(1) << 9)

#define PIN_PB07C_SERCOM3_PAD2                     _UINT32_(39)
#define MUX_PB07C_SERCOM3_PAD2                     _UINT32_(2) 
#define PINMUX_PB07C_SERCOM3_PAD2                  ((PIN_PB07C_SERCOM3_PAD2 << 16) | MUX_PB07C_SERCOM3_PAD2)
#define PORT_PB07C_SERCOM3_PAD2                    (_UINT32_(1) << 7)

#define PIN_PB23C_SERCOM3_PAD2                     _UINT32_(55)
#define MUX_PB23C_SERCOM3_PAD2                     _UINT32_(2) 
#define PINMUX_PB23C_SERCOM3_PAD2                  ((PIN_PB23C_SERCOM3_PAD2 << 16) | MUX_PB23C_SERCOM3_PAD2)
#define PORT_PB23C_SERCOM3_PAD2                    (_UINT32_(1) << 23)

#define PIN_PC04C_SERCOM3_PAD2                     _UINT32_(68)
#define MUX_PC04C_SERCOM3_PAD2                     _UINT32_(2) 
#define PINMUX_PC04C_SERCOM3_PAD2                  ((PIN_PC04C_SERCOM3_PAD2 << 16) | MUX_PC04C_SERCOM3_PAD2)
#define PORT_PC04C_SERCOM3_PAD2                    (_UINT32_(1) << 4)

#define PIN_PC15D_SERCOM3_PAD3                     _UINT32_(79)
#define MUX_PC15D_SERCOM3_PAD3                     _UINT32_(3) 
#define PINMUX_PC15D_SERCOM3_PAD3                  ((PIN_PC15D_SERCOM3_PAD3 << 16) | MUX_PC15D_SERCOM3_PAD3)
#define PORT_PC15D_SERCOM3_PAD3                    (_UINT32_(1) << 15)

#define PIN_PB08C_SERCOM3_PAD3                     _UINT32_(40)
#define MUX_PB08C_SERCOM3_PAD3                     _UINT32_(2) 
#define PINMUX_PB08C_SERCOM3_PAD3                  ((PIN_PB08C_SERCOM3_PAD3 << 16) | MUX_PB08C_SERCOM3_PAD3)
#define PORT_PB08C_SERCOM3_PAD3                    (_UINT32_(1) << 8)

#define PIN_PB24C_SERCOM3_PAD3                     _UINT32_(56)
#define MUX_PB24C_SERCOM3_PAD3                     _UINT32_(2) 
#define PINMUX_PB24C_SERCOM3_PAD3                  ((PIN_PB24C_SERCOM3_PAD3 << 16) | MUX_PB24C_SERCOM3_PAD3)
#define PORT_PB24C_SERCOM3_PAD3                    (_UINT32_(1) << 24)

#define PIN_PC05C_SERCOM3_PAD3                     _UINT32_(69)
#define MUX_PC05C_SERCOM3_PAD3                     _UINT32_(2) 
#define PINMUX_PC05C_SERCOM3_PAD3                  ((PIN_PC05C_SERCOM3_PAD3 << 16) | MUX_PC05C_SERCOM3_PAD3)
#define PORT_PC05C_SERCOM3_PAD3                    (_UINT32_(1) << 5)

/* ========== PORT definition for SERCOM4 peripheral ========== */
#define PIN_PB10D_SERCOM4_PAD0                     _UINT32_(42)
#define MUX_PB10D_SERCOM4_PAD0                     _UINT32_(3) 
#define PINMUX_PB10D_SERCOM4_PAD0                  ((PIN_PB10D_SERCOM4_PAD0 << 16) | MUX_PB10D_SERCOM4_PAD0)
#define PORT_PB10D_SERCOM4_PAD0                    (_UINT32_(1) << 10)

#define PIN_PB04C_SERCOM4_PAD0                     _UINT32_(36)
#define MUX_PB04C_SERCOM4_PAD0                     _UINT32_(2) 
#define PINMUX_PB04C_SERCOM4_PAD0                  ((PIN_PB04C_SERCOM4_PAD0 << 16) | MUX_PB04C_SERCOM4_PAD0)
#define PORT_PB04C_SERCOM4_PAD0                    (_UINT32_(1) << 4)

#define PIN_PB09C_SERCOM4_PAD0                     _UINT32_(41)
#define MUX_PB09C_SERCOM4_PAD0                     _UINT32_(2) 
#define PINMUX_PB09C_SERCOM4_PAD0                  ((PIN_PB09C_SERCOM4_PAD0 << 16) | MUX_PB09C_SERCOM4_PAD0)
#define PORT_PB09C_SERCOM4_PAD0                    (_UINT32_(1) << 9)

#define PIN_PB12C_SERCOM4_PAD0                     _UINT32_(44)
#define MUX_PB12C_SERCOM4_PAD0                     _UINT32_(2) 
#define PINMUX_PB12C_SERCOM4_PAD0                  ((PIN_PB12C_SERCOM4_PAD0 << 16) | MUX_PB12C_SERCOM4_PAD0)
#define PORT_PB12C_SERCOM4_PAD0                    (_UINT32_(1) << 12)

#define PIN_PB09D_SERCOM4_PAD1                     _UINT32_(41)
#define MUX_PB09D_SERCOM4_PAD1                     _UINT32_(3) 
#define PINMUX_PB09D_SERCOM4_PAD1                  ((PIN_PB09D_SERCOM4_PAD1 << 16) | MUX_PB09D_SERCOM4_PAD1)
#define PORT_PB09D_SERCOM4_PAD1                    (_UINT32_(1) << 9)

#define PIN_PB05C_SERCOM4_PAD1                     _UINT32_(37)
#define MUX_PB05C_SERCOM4_PAD1                     _UINT32_(2) 
#define PINMUX_PB05C_SERCOM4_PAD1                  ((PIN_PB05C_SERCOM4_PAD1 << 16) | MUX_PB05C_SERCOM4_PAD1)
#define PORT_PB05C_SERCOM4_PAD1                    (_UINT32_(1) << 5)

#define PIN_PB10C_SERCOM4_PAD1                     _UINT32_(42)
#define MUX_PB10C_SERCOM4_PAD1                     _UINT32_(2) 
#define PINMUX_PB10C_SERCOM4_PAD1                  ((PIN_PB10C_SERCOM4_PAD1 << 16) | MUX_PB10C_SERCOM4_PAD1)
#define PORT_PB10C_SERCOM4_PAD1                    (_UINT32_(1) << 10)

#define PIN_PB18C_SERCOM4_PAD1                     _UINT32_(50)
#define MUX_PB18C_SERCOM4_PAD1                     _UINT32_(2) 
#define PINMUX_PB18C_SERCOM4_PAD1                  ((PIN_PB18C_SERCOM4_PAD1 << 16) | MUX_PB18C_SERCOM4_PAD1)
#define PORT_PB18C_SERCOM4_PAD1                    (_UINT32_(1) << 18)

#define PIN_PB07D_SERCOM4_PAD2                     _UINT32_(39)
#define MUX_PB07D_SERCOM4_PAD2                     _UINT32_(3) 
#define PINMUX_PB07D_SERCOM4_PAD2                  ((PIN_PB07D_SERCOM4_PAD2 << 16) | MUX_PB07D_SERCOM4_PAD2)
#define PORT_PB07D_SERCOM4_PAD2                    (_UINT32_(1) << 7)

#define PIN_PB13C_SERCOM4_PAD2                     _UINT32_(45)
#define MUX_PB13C_SERCOM4_PAD2                     _UINT32_(2) 
#define PINMUX_PB13C_SERCOM4_PAD2                  ((PIN_PB13C_SERCOM4_PAD2 << 16) | MUX_PB13C_SERCOM4_PAD2)
#define PORT_PB13C_SERCOM4_PAD2                    (_UINT32_(1) << 13)

#define PIN_PB19C_SERCOM4_PAD2                     _UINT32_(51)
#define MUX_PB19C_SERCOM4_PAD2                     _UINT32_(2) 
#define PINMUX_PB19C_SERCOM4_PAD2                  ((PIN_PB19C_SERCOM4_PAD2 << 16) | MUX_PB19C_SERCOM4_PAD2)
#define PORT_PB19C_SERCOM4_PAD2                    (_UINT32_(1) << 19)

#define PIN_PC00C_SERCOM4_PAD2                     _UINT32_(64)
#define MUX_PC00C_SERCOM4_PAD2                     _UINT32_(2) 
#define PINMUX_PC00C_SERCOM4_PAD2                  ((PIN_PC00C_SERCOM4_PAD2 << 16) | MUX_PC00C_SERCOM4_PAD2)
#define PORT_PC00C_SERCOM4_PAD2                    (_UINT32_(1) << 0)

#define PIN_PB08D_SERCOM4_PAD3                     _UINT32_(40)
#define MUX_PB08D_SERCOM4_PAD3                     _UINT32_(3) 
#define PINMUX_PB08D_SERCOM4_PAD3                  ((PIN_PB08D_SERCOM4_PAD3 << 16) | MUX_PB08D_SERCOM4_PAD3)
#define PORT_PB08D_SERCOM4_PAD3                    (_UINT32_(1) << 8)

#define PIN_PB06C_SERCOM4_PAD3                     _UINT32_(38)
#define MUX_PB06C_SERCOM4_PAD3                     _UINT32_(2) 
#define PINMUX_PB06C_SERCOM4_PAD3                  ((PIN_PB06C_SERCOM4_PAD3 << 16) | MUX_PB06C_SERCOM4_PAD3)
#define PORT_PB06C_SERCOM4_PAD3                    (_UINT32_(1) << 6)

#define PIN_PB20C_SERCOM4_PAD3                     _UINT32_(52)
#define MUX_PB20C_SERCOM4_PAD3                     _UINT32_(2) 
#define PINMUX_PB20C_SERCOM4_PAD3                  ((PIN_PB20C_SERCOM4_PAD3 << 16) | MUX_PB20C_SERCOM4_PAD3)
#define PORT_PB20C_SERCOM4_PAD3                    (_UINT32_(1) << 20)

#define PIN_PC01C_SERCOM4_PAD3                     _UINT32_(65)
#define MUX_PC01C_SERCOM4_PAD3                     _UINT32_(2) 
#define PINMUX_PC01C_SERCOM4_PAD3                  ((PIN_PC01C_SERCOM4_PAD3 << 16) | MUX_PC01C_SERCOM4_PAD3)
#define PORT_PC01C_SERCOM4_PAD3                    (_UINT32_(1) << 1)

/* ========== PORT definition for SERCOM5 peripheral ========== */
#define PIN_PA05D_SERCOM5_PAD0                     _UINT32_(5) 
#define MUX_PA05D_SERCOM5_PAD0                     _UINT32_(3) 
#define PINMUX_PA05D_SERCOM5_PAD0                  ((PIN_PA05D_SERCOM5_PAD0 << 16) | MUX_PA05D_SERCOM5_PAD0)
#define PORT_PA05D_SERCOM5_PAD0                    (_UINT32_(1) << 5)

#define PIN_PA11C_SERCOM5_PAD0                     _UINT32_(11)
#define MUX_PA11C_SERCOM5_PAD0                     _UINT32_(2) 
#define PINMUX_PA11C_SERCOM5_PAD0                  ((PIN_PA11C_SERCOM5_PAD0 << 16) | MUX_PA11C_SERCOM5_PAD0)
#define PORT_PA11C_SERCOM5_PAD0                    (_UINT32_(1) << 11)

#define PIN_PA13C_SERCOM5_PAD0                     _UINT32_(13)
#define MUX_PA13C_SERCOM5_PAD0                     _UINT32_(2) 
#define PINMUX_PA13C_SERCOM5_PAD0                  ((PIN_PA13C_SERCOM5_PAD0 << 16) | MUX_PA13C_SERCOM5_PAD0)
#define PORT_PA13C_SERCOM5_PAD0                    (_UINT32_(1) << 13)

#define PIN_PA24C_SERCOM5_PAD0                     _UINT32_(24)
#define MUX_PA24C_SERCOM5_PAD0                     _UINT32_(2) 
#define PINMUX_PA24C_SERCOM5_PAD0                  ((PIN_PA24C_SERCOM5_PAD0 << 16) | MUX_PA24C_SERCOM5_PAD0)
#define PORT_PA24C_SERCOM5_PAD0                    (_UINT32_(1) << 24)

#define PIN_PA06D_SERCOM5_PAD1                     _UINT32_(6) 
#define MUX_PA06D_SERCOM5_PAD1                     _UINT32_(3) 
#define PINMUX_PA06D_SERCOM5_PAD1                  ((PIN_PA06D_SERCOM5_PAD1 << 16) | MUX_PA06D_SERCOM5_PAD1)
#define PORT_PA06D_SERCOM5_PAD1                    (_UINT32_(1) << 6)

#define PIN_PA12C_SERCOM5_PAD1                     _UINT32_(12)
#define MUX_PA12C_SERCOM5_PAD1                     _UINT32_(2) 
#define PINMUX_PA12C_SERCOM5_PAD1                  ((PIN_PA12C_SERCOM5_PAD1 << 16) | MUX_PA12C_SERCOM5_PAD1)
#define PORT_PA12C_SERCOM5_PAD1                    (_UINT32_(1) << 12)

#define PIN_PA14C_SERCOM5_PAD1                     _UINT32_(14)
#define MUX_PA14C_SERCOM5_PAD1                     _UINT32_(2) 
#define PINMUX_PA14C_SERCOM5_PAD1                  ((PIN_PA14C_SERCOM5_PAD1 << 16) | MUX_PA14C_SERCOM5_PAD1)
#define PORT_PA14C_SERCOM5_PAD1                    (_UINT32_(1) << 14)

#define PIN_PA25C_SERCOM5_PAD1                     _UINT32_(25)
#define MUX_PA25C_SERCOM5_PAD1                     _UINT32_(2) 
#define PINMUX_PA25C_SERCOM5_PAD1                  ((PIN_PA25C_SERCOM5_PAD1 << 16) | MUX_PA25C_SERCOM5_PAD1)
#define PORT_PA25C_SERCOM5_PAD1                    (_UINT32_(1) << 25)

#define PIN_PA07D_SERCOM5_PAD2                     _UINT32_(7) 
#define MUX_PA07D_SERCOM5_PAD2                     _UINT32_(3) 
#define PINMUX_PA07D_SERCOM5_PAD2                  ((PIN_PA07D_SERCOM5_PAD2 << 16) | MUX_PA07D_SERCOM5_PAD2)
#define PORT_PA07D_SERCOM5_PAD2                    (_UINT32_(1) << 7)

#define PIN_PA15C_SERCOM5_PAD2                     _UINT32_(15)
#define MUX_PA15C_SERCOM5_PAD2                     _UINT32_(2) 
#define PINMUX_PA15C_SERCOM5_PAD2                  ((PIN_PA15C_SERCOM5_PAD2 << 16) | MUX_PA15C_SERCOM5_PAD2)
#define PORT_PA15C_SERCOM5_PAD2                    (_UINT32_(1) << 15)

#define PIN_PA26C_SERCOM5_PAD2                     _UINT32_(26)
#define MUX_PA26C_SERCOM5_PAD2                     _UINT32_(2) 
#define PINMUX_PA26C_SERCOM5_PAD2                  ((PIN_PA26C_SERCOM5_PAD2 << 16) | MUX_PA26C_SERCOM5_PAD2)
#define PORT_PA26C_SERCOM5_PAD2                    (_UINT32_(1) << 26)

#define PIN_PB00C_SERCOM5_PAD2                     _UINT32_(32)
#define MUX_PB00C_SERCOM5_PAD2                     _UINT32_(2) 
#define PINMUX_PB00C_SERCOM5_PAD2                  ((PIN_PB00C_SERCOM5_PAD2 << 16) | MUX_PB00C_SERCOM5_PAD2)
#define PORT_PB00C_SERCOM5_PAD2                    (_UINT32_(1) << 0)

#define PIN_PA08D_SERCOM5_PAD3                     _UINT32_(8) 
#define MUX_PA08D_SERCOM5_PAD3                     _UINT32_(3) 
#define PINMUX_PA08D_SERCOM5_PAD3                  ((PIN_PA08D_SERCOM5_PAD3 << 16) | MUX_PA08D_SERCOM5_PAD3)
#define PORT_PA08D_SERCOM5_PAD3                    (_UINT32_(1) << 8)

#define PIN_PA16C_SERCOM5_PAD3                     _UINT32_(16)
#define MUX_PA16C_SERCOM5_PAD3                     _UINT32_(2) 
#define PINMUX_PA16C_SERCOM5_PAD3                  ((PIN_PA16C_SERCOM5_PAD3 << 16) | MUX_PA16C_SERCOM5_PAD3)
#define PORT_PA16C_SERCOM5_PAD3                    (_UINT32_(1) << 16)

#define PIN_PA27C_SERCOM5_PAD3                     _UINT32_(27)
#define MUX_PA27C_SERCOM5_PAD3                     _UINT32_(2) 
#define PINMUX_PA27C_SERCOM5_PAD3                  ((PIN_PA27C_SERCOM5_PAD3 << 16) | MUX_PA27C_SERCOM5_PAD3)
#define PORT_PA27C_SERCOM5_PAD3                    (_UINT32_(1) << 27)

#define PIN_PB01C_SERCOM5_PAD3                     _UINT32_(33)
#define MUX_PB01C_SERCOM5_PAD3                     _UINT32_(2) 
#define PINMUX_PB01C_SERCOM5_PAD3                  ((PIN_PB01C_SERCOM5_PAD3 << 16) | MUX_PB01C_SERCOM5_PAD3)
#define PORT_PB01C_SERCOM5_PAD3                    (_UINT32_(1) << 1)

/* ========== PORT definition for SERCOM6 peripheral ========== */
#define PIN_PA00D_SERCOM6_PAD0                     _UINT32_(0) 
#define MUX_PA00D_SERCOM6_PAD0                     _UINT32_(3) 
#define PINMUX_PA00D_SERCOM6_PAD0                  ((PIN_PA00D_SERCOM6_PAD0 << 16) | MUX_PA00D_SERCOM6_PAD0)
#define PORT_PA00D_SERCOM6_PAD0                    (_UINT32_(1) << 0)

#define PIN_PA18D_SERCOM6_PAD0                     _UINT32_(18)
#define MUX_PA18D_SERCOM6_PAD0                     _UINT32_(3) 
#define PINMUX_PA18D_SERCOM6_PAD0                  ((PIN_PA18D_SERCOM6_PAD0 << 16) | MUX_PA18D_SERCOM6_PAD0)
#define PORT_PA18D_SERCOM6_PAD0                    (_UINT32_(1) << 18)

#define PIN_PA07C_SERCOM6_PAD0                     _UINT32_(7) 
#define MUX_PA07C_SERCOM6_PAD0                     _UINT32_(2) 
#define PINMUX_PA07C_SERCOM6_PAD0                  ((PIN_PA07C_SERCOM6_PAD0 << 16) | MUX_PA07C_SERCOM6_PAD0)
#define PORT_PA07C_SERCOM6_PAD0                    (_UINT32_(1) << 7)

#define PIN_PA01D_SERCOM6_PAD1                     _UINT32_(1) 
#define MUX_PA01D_SERCOM6_PAD1                     _UINT32_(3) 
#define PINMUX_PA01D_SERCOM6_PAD1                  ((PIN_PA01D_SERCOM6_PAD1 << 16) | MUX_PA01D_SERCOM6_PAD1)
#define PORT_PA01D_SERCOM6_PAD1                    (_UINT32_(1) << 1)

#define PIN_PA28D_SERCOM6_PAD1                     _UINT32_(28)
#define MUX_PA28D_SERCOM6_PAD1                     _UINT32_(3) 
#define PINMUX_PA28D_SERCOM6_PAD1                  ((PIN_PA28D_SERCOM6_PAD1 << 16) | MUX_PA28D_SERCOM6_PAD1)
#define PORT_PA28D_SERCOM6_PAD1                    (_UINT32_(1) << 28)

#define PIN_PA08C_SERCOM6_PAD1                     _UINT32_(8) 
#define MUX_PA08C_SERCOM6_PAD1                     _UINT32_(2) 
#define PINMUX_PA08C_SERCOM6_PAD1                  ((PIN_PA08C_SERCOM6_PAD1 << 16) | MUX_PA08C_SERCOM6_PAD1)
#define PORT_PA08C_SERCOM6_PAD1                    (_UINT32_(1) << 8)

#define PIN_PA02D_SERCOM6_PAD2                     _UINT32_(2) 
#define MUX_PA02D_SERCOM6_PAD2                     _UINT32_(3) 
#define PINMUX_PA02D_SERCOM6_PAD2                  ((PIN_PA02D_SERCOM6_PAD2 << 16) | MUX_PA02D_SERCOM6_PAD2)
#define PORT_PA02D_SERCOM6_PAD2                    (_UINT32_(1) << 2)

#define PIN_PA19D_SERCOM6_PAD2                     _UINT32_(19)
#define MUX_PA19D_SERCOM6_PAD2                     _UINT32_(3) 
#define PINMUX_PA19D_SERCOM6_PAD2                  ((PIN_PA19D_SERCOM6_PAD2 << 16) | MUX_PA19D_SERCOM6_PAD2)
#define PORT_PA19D_SERCOM6_PAD2                    (_UINT32_(1) << 19)

#define PIN_PA09C_SERCOM6_PAD2                     _UINT32_(9) 
#define MUX_PA09C_SERCOM6_PAD2                     _UINT32_(2) 
#define PINMUX_PA09C_SERCOM6_PAD2                  ((PIN_PA09C_SERCOM6_PAD2 << 16) | MUX_PA09C_SERCOM6_PAD2)
#define PORT_PA09C_SERCOM6_PAD2                    (_UINT32_(1) << 9)

#define PIN_PA03D_SERCOM6_PAD3                     _UINT32_(3) 
#define MUX_PA03D_SERCOM6_PAD3                     _UINT32_(3) 
#define PINMUX_PA03D_SERCOM6_PAD3                  ((PIN_PA03D_SERCOM6_PAD3 << 16) | MUX_PA03D_SERCOM6_PAD3)
#define PORT_PA03D_SERCOM6_PAD3                    (_UINT32_(1) << 3)

#define PIN_PA09D_SERCOM6_PAD3                     _UINT32_(9) 
#define MUX_PA09D_SERCOM6_PAD3                     _UINT32_(3) 
#define PINMUX_PA09D_SERCOM6_PAD3                  ((PIN_PA09D_SERCOM6_PAD3 << 16) | MUX_PA09D_SERCOM6_PAD3)
#define PORT_PA09D_SERCOM6_PAD3                    (_UINT32_(1) << 9)

#define PIN_PA10C_SERCOM6_PAD3                     _UINT32_(10)
#define MUX_PA10C_SERCOM6_PAD3                     _UINT32_(2) 
#define PINMUX_PA10C_SERCOM6_PAD3                  ((PIN_PA10C_SERCOM6_PAD3 << 16) | MUX_PA10C_SERCOM6_PAD3)
#define PORT_PA10C_SERCOM6_PAD3                    (_UINT32_(1) << 10)

/* ========== PORT definition for SERCOM7 peripheral ========== */
#define PIN_PA12D_SERCOM7_PAD0                     _UINT32_(12)
#define MUX_PA12D_SERCOM7_PAD0                     _UINT32_(3) 
#define PINMUX_PA12D_SERCOM7_PAD0                  ((PIN_PA12D_SERCOM7_PAD0 << 16) | MUX_PA12D_SERCOM7_PAD0)
#define PORT_PA12D_SERCOM7_PAD0                    (_UINT32_(1) << 12)

#define PIN_PB18D_SERCOM7_PAD0                     _UINT32_(50)
#define MUX_PB18D_SERCOM7_PAD0                     _UINT32_(3) 
#define PINMUX_PB18D_SERCOM7_PAD0                  ((PIN_PB18D_SERCOM7_PAD0 << 16) | MUX_PB18D_SERCOM7_PAD0)
#define PORT_PB18D_SERCOM7_PAD0                    (_UINT32_(1) << 18)

#define PIN_PA21C_SERCOM7_PAD0                     _UINT32_(21)
#define MUX_PA21C_SERCOM7_PAD0                     _UINT32_(2) 
#define PINMUX_PA21C_SERCOM7_PAD0                  ((PIN_PA21C_SERCOM7_PAD0 << 16) | MUX_PA21C_SERCOM7_PAD0)
#define PORT_PA21C_SERCOM7_PAD0                    (_UINT32_(1) << 21)

#define PIN_PA01C_SERCOM7_PAD0                     _UINT32_(1) 
#define MUX_PA01C_SERCOM7_PAD0                     _UINT32_(2) 
#define PINMUX_PA01C_SERCOM7_PAD0                  ((PIN_PA01C_SERCOM7_PAD0 << 16) | MUX_PA01C_SERCOM7_PAD0)
#define PORT_PA01C_SERCOM7_PAD0                    (_UINT32_(1) << 1)

#define PIN_PA11D_SERCOM7_PAD1                     _UINT32_(11)
#define MUX_PA11D_SERCOM7_PAD1                     _UINT32_(3) 
#define PINMUX_PA11D_SERCOM7_PAD1                  ((PIN_PA11D_SERCOM7_PAD1 << 16) | MUX_PA11D_SERCOM7_PAD1)
#define PORT_PA11D_SERCOM7_PAD1                    (_UINT32_(1) << 11)

#define PIN_PB12D_SERCOM7_PAD1                     _UINT32_(44)
#define MUX_PB12D_SERCOM7_PAD1                     _UINT32_(3) 
#define PINMUX_PB12D_SERCOM7_PAD1                  ((PIN_PB12D_SERCOM7_PAD1 << 16) | MUX_PB12D_SERCOM7_PAD1)
#define PORT_PB12D_SERCOM7_PAD1                    (_UINT32_(1) << 12)

#define PIN_PA04C_SERCOM7_PAD1                     _UINT32_(4) 
#define MUX_PA04C_SERCOM7_PAD1                     _UINT32_(2) 
#define PINMUX_PA04C_SERCOM7_PAD1                  ((PIN_PA04C_SERCOM7_PAD1 << 16) | MUX_PA04C_SERCOM7_PAD1)
#define PORT_PA04C_SERCOM7_PAD1                    (_UINT32_(1) << 4)

#define PIN_PA20C_SERCOM7_PAD1                     _UINT32_(20)
#define MUX_PA20C_SERCOM7_PAD1                     _UINT32_(2) 
#define PINMUX_PA20C_SERCOM7_PAD1                  ((PIN_PA20C_SERCOM7_PAD1 << 16) | MUX_PA20C_SERCOM7_PAD1)
#define PORT_PA20C_SERCOM7_PAD1                    (_UINT32_(1) << 20)

#define PIN_PB00D_SERCOM7_PAD2                     _UINT32_(32)
#define MUX_PB00D_SERCOM7_PAD2                     _UINT32_(3) 
#define PINMUX_PB00D_SERCOM7_PAD2                  ((PIN_PB00D_SERCOM7_PAD2 << 16) | MUX_PB00D_SERCOM7_PAD2)
#define PORT_PB00D_SERCOM7_PAD2                    (_UINT32_(1) << 0)

#define PIN_PB19D_SERCOM7_PAD2                     _UINT32_(51)
#define MUX_PB19D_SERCOM7_PAD2                     _UINT32_(3) 
#define PINMUX_PB19D_SERCOM7_PAD2                  ((PIN_PB19D_SERCOM7_PAD2 << 16) | MUX_PB19D_SERCOM7_PAD2)
#define PORT_PB19D_SERCOM7_PAD2                    (_UINT32_(1) << 19)

#define PIN_PA05C_SERCOM7_PAD2                     _UINT32_(5) 
#define MUX_PA05C_SERCOM7_PAD2                     _UINT32_(2) 
#define PINMUX_PA05C_SERCOM7_PAD2                  ((PIN_PA05C_SERCOM7_PAD2 << 16) | MUX_PA05C_SERCOM7_PAD2)
#define PORT_PA05C_SERCOM7_PAD2                    (_UINT32_(1) << 5)

#define PIN_PA22C_SERCOM7_PAD2                     _UINT32_(22)
#define MUX_PA22C_SERCOM7_PAD2                     _UINT32_(2) 
#define PINMUX_PA22C_SERCOM7_PAD2                  ((PIN_PA22C_SERCOM7_PAD2 << 16) | MUX_PA22C_SERCOM7_PAD2)
#define PORT_PA22C_SERCOM7_PAD2                    (_UINT32_(1) << 22)

#define PIN_PB01D_SERCOM7_PAD3                     _UINT32_(33)
#define MUX_PB01D_SERCOM7_PAD3                     _UINT32_(3) 
#define PINMUX_PB01D_SERCOM7_PAD3                  ((PIN_PB01D_SERCOM7_PAD3 << 16) | MUX_PB01D_SERCOM7_PAD3)
#define PORT_PB01D_SERCOM7_PAD3                    (_UINT32_(1) << 1)

#define PIN_PB20D_SERCOM7_PAD3                     _UINT32_(52)
#define MUX_PB20D_SERCOM7_PAD3                     _UINT32_(3) 
#define PINMUX_PB20D_SERCOM7_PAD3                  ((PIN_PB20D_SERCOM7_PAD3 << 16) | MUX_PB20D_SERCOM7_PAD3)
#define PORT_PB20D_SERCOM7_PAD3                    (_UINT32_(1) << 20)

#define PIN_PA06C_SERCOM7_PAD3                     _UINT32_(6) 
#define MUX_PA06C_SERCOM7_PAD3                     _UINT32_(2) 
#define PINMUX_PA06C_SERCOM7_PAD3                  ((PIN_PA06C_SERCOM7_PAD3 << 16) | MUX_PA06C_SERCOM7_PAD3)
#define PORT_PA06C_SERCOM7_PAD3                    (_UINT32_(1) << 6)

#define PIN_PA23C_SERCOM7_PAD3                     _UINT32_(23)
#define MUX_PA23C_SERCOM7_PAD3                     _UINT32_(2) 
#define PINMUX_PA23C_SERCOM7_PAD3                  ((PIN_PA23C_SERCOM7_PAD3 << 16) | MUX_PA23C_SERCOM7_PAD3)
#define PORT_PA23C_SERCOM7_PAD3                    (_UINT32_(1) << 23)

/* ========== PORT definition for SPI_IXS peripheral ========== */
#define PIN_PA09J_SPI_IXS_FSYNC                    _UINT32_(9) 
#define MUX_PA09J_SPI_IXS_FSYNC                    _UINT32_(9) 
#define PINMUX_PA09J_SPI_IXS_FSYNC                 ((PIN_PA09J_SPI_IXS_FSYNC << 16) | MUX_PA09J_SPI_IXS_FSYNC)
#define PORT_PA09J_SPI_IXS_FSYNC                   (_UINT32_(1) << 9)

#define PIN_PD06J_SPI_IXS_FSYNC                    _UINT32_(102)
#define MUX_PD06J_SPI_IXS_FSYNC                    _UINT32_(9) 
#define PINMUX_PD06J_SPI_IXS_FSYNC                 ((PIN_PD06J_SPI_IXS_FSYNC << 16) | MUX_PD06J_SPI_IXS_FSYNC)
#define PORT_PD06J_SPI_IXS_FSYNC                   (_UINT32_(1) << 6)

#define PIN_PD13J_SPI_IXS_FSYNC                    _UINT32_(109)
#define MUX_PD13J_SPI_IXS_FSYNC                    _UINT32_(9) 
#define PINMUX_PD13J_SPI_IXS_FSYNC                 ((PIN_PD13J_SPI_IXS_FSYNC << 16) | MUX_PD13J_SPI_IXS_FSYNC)
#define PORT_PD13J_SPI_IXS_FSYNC                   (_UINT32_(1) << 13)

#define PIN_PA11J_SPI_IXS_SCK                      _UINT32_(11)
#define MUX_PA11J_SPI_IXS_SCK                      _UINT32_(9) 
#define PINMUX_PA11J_SPI_IXS_SCK                   ((PIN_PA11J_SPI_IXS_SCK << 16) | MUX_PA11J_SPI_IXS_SCK)
#define PORT_PA11J_SPI_IXS_SCK                     (_UINT32_(1) << 11)

#define PIN_PD10J_SPI_IXS_SCK                      _UINT32_(106)
#define MUX_PD10J_SPI_IXS_SCK                      _UINT32_(9) 
#define PINMUX_PD10J_SPI_IXS_SCK                   ((PIN_PD10J_SPI_IXS_SCK << 16) | MUX_PD10J_SPI_IXS_SCK)
#define PORT_PD10J_SPI_IXS_SCK                     (_UINT32_(1) << 10)

#define PIN_PD14J_SPI_IXS_SCK                      _UINT32_(110)
#define MUX_PD14J_SPI_IXS_SCK                      _UINT32_(9) 
#define PINMUX_PD14J_SPI_IXS_SCK                   ((PIN_PD14J_SPI_IXS_SCK << 16) | MUX_PD14J_SPI_IXS_SCK)
#define PORT_PD14J_SPI_IXS_SCK                     (_UINT32_(1) << 14)

#define PIN_PA12J_SPI_IXS_SDI                      _UINT32_(12)
#define MUX_PA12J_SPI_IXS_SDI                      _UINT32_(9) 
#define PINMUX_PA12J_SPI_IXS_SDI                   ((PIN_PA12J_SPI_IXS_SDI << 16) | MUX_PA12J_SPI_IXS_SDI)
#define PORT_PA12J_SPI_IXS_SDI                     (_UINT32_(1) << 12)

#define PIN_PD07J_SPI_IXS_SDI                      _UINT32_(103)
#define MUX_PD07J_SPI_IXS_SDI                      _UINT32_(9) 
#define PINMUX_PD07J_SPI_IXS_SDI                   ((PIN_PD07J_SPI_IXS_SDI << 16) | MUX_PD07J_SPI_IXS_SDI)
#define PORT_PD07J_SPI_IXS_SDI                     (_UINT32_(1) << 7)

#define PIN_PD16J_SPI_IXS_SDI                      _UINT32_(112)
#define MUX_PD16J_SPI_IXS_SDI                      _UINT32_(9) 
#define PINMUX_PD16J_SPI_IXS_SDI                   ((PIN_PD16J_SPI_IXS_SDI << 16) | MUX_PD16J_SPI_IXS_SDI)
#define PORT_PD16J_SPI_IXS_SDI                     (_UINT32_(1) << 16)

#define PIN_PB00J_SPI_IXS_SDO                      _UINT32_(32)
#define MUX_PB00J_SPI_IXS_SDO                      _UINT32_(9) 
#define PINMUX_PB00J_SPI_IXS_SDO                   ((PIN_PB00J_SPI_IXS_SDO << 16) | MUX_PB00J_SPI_IXS_SDO)
#define PORT_PB00J_SPI_IXS_SDO                     (_UINT32_(1) << 0)

#define PIN_PD08J_SPI_IXS_SDO                      _UINT32_(104)
#define MUX_PD08J_SPI_IXS_SDO                      _UINT32_(9) 
#define PINMUX_PD08J_SPI_IXS_SDO                   ((PIN_PD08J_SPI_IXS_SDO << 16) | MUX_PD08J_SPI_IXS_SDO)
#define PORT_PD08J_SPI_IXS_SDO                     (_UINT32_(1) << 8)

#define PIN_PD17J_SPI_IXS_SDO                      _UINT32_(113)
#define MUX_PD17J_SPI_IXS_SDO                      _UINT32_(9) 
#define PINMUX_PD17J_SPI_IXS_SDO                   ((PIN_PD17J_SPI_IXS_SDO << 16) | MUX_PD17J_SPI_IXS_SDO)
#define PORT_PD17J_SPI_IXS_SDO                     (_UINT32_(1) << 17)

/* ========== PORT definition for SQI peripheral ========== */
#define PIN_PD10H_SQI_CLK                          _UINT32_(106)
#define MUX_PD10H_SQI_CLK                          _UINT32_(7) 
#define PINMUX_PD10H_SQI_CLK                       ((PIN_PD10H_SQI_CLK << 16) | MUX_PD10H_SQI_CLK)
#define PORT_PD10H_SQI_CLK                         (_UINT32_(1) << 10)

#define PIN_PD06H_SQI_CS0                          _UINT32_(102)
#define MUX_PD06H_SQI_CS0                          _UINT32_(7) 
#define PINMUX_PD06H_SQI_CS0                       ((PIN_PD06H_SQI_CS0 << 16) | MUX_PD06H_SQI_CS0)
#define PORT_PD06H_SQI_CS0                         (_UINT32_(1) << 6)

#define PIN_PD05H_SQI_CS1                          _UINT32_(101)
#define MUX_PD05H_SQI_CS1                          _UINT32_(7) 
#define PINMUX_PD05H_SQI_CS1                       ((PIN_PD05H_SQI_CS1 << 16) | MUX_PD05H_SQI_CS1)
#define PORT_PD05H_SQI_CS1                         (_UINT32_(1) << 5)

#define PIN_PA10H_SQI_CS2                          _UINT32_(10)
#define MUX_PA10H_SQI_CS2                          _UINT32_(7) 
#define PINMUX_PA10H_SQI_CS2                       ((PIN_PA10H_SQI_CS2 << 16) | MUX_PA10H_SQI_CS2)
#define PORT_PA10H_SQI_CS2                         (_UINT32_(1) << 10)

#define PIN_PD12H_SQI_CS3                          _UINT32_(108)
#define MUX_PD12H_SQI_CS3                          _UINT32_(7) 
#define PINMUX_PD12H_SQI_CS3                       ((PIN_PD12H_SQI_CS3 << 16) | MUX_PD12H_SQI_CS3)
#define PORT_PD12H_SQI_CS3                         (_UINT32_(1) << 12)

#define PIN_PD07H_SQI_DATA0                        _UINT32_(103)
#define MUX_PD07H_SQI_DATA0                        _UINT32_(7) 
#define PINMUX_PD07H_SQI_DATA0                     ((PIN_PD07H_SQI_DATA0 << 16) | MUX_PD07H_SQI_DATA0)
#define PORT_PD07H_SQI_DATA0                       (_UINT32_(1) << 7)

#define PIN_PD11H_SQI_DATA1                        _UINT32_(107)
#define MUX_PD11H_SQI_DATA1                        _UINT32_(7) 
#define PINMUX_PD11H_SQI_DATA1                     ((PIN_PD11H_SQI_DATA1 << 16) | MUX_PD11H_SQI_DATA1)
#define PORT_PD11H_SQI_DATA1                       (_UINT32_(1) << 11)

#define PIN_PD08H_SQI_DATA2                        _UINT32_(104)
#define MUX_PD08H_SQI_DATA2                        _UINT32_(7) 
#define PINMUX_PD08H_SQI_DATA2                     ((PIN_PD08H_SQI_DATA2 << 16) | MUX_PD08H_SQI_DATA2)
#define PORT_PD08H_SQI_DATA2                       (_UINT32_(1) << 8)

#define PIN_PD09H_SQI_DATA3                        _UINT32_(105)
#define MUX_PD09H_SQI_DATA3                        _UINT32_(7) 
#define PINMUX_PD09H_SQI_DATA3                     ((PIN_PD09H_SQI_DATA3 << 16) | MUX_PD09H_SQI_DATA3)
#define PORT_PD09H_SQI_DATA3                       (_UINT32_(1) << 9)

/* ========== PORT definition for TCC0 peripheral ========== */
#define PIN_PB10G_TCC0_WO0                         _UINT32_(42)
#define MUX_PB10G_TCC0_WO0                         _UINT32_(6) 
#define PINMUX_PB10G_TCC0_WO0                      ((PIN_PB10G_TCC0_WO0 << 16) | MUX_PB10G_TCC0_WO0)
#define PORT_PB10G_TCC0_WO0                        (_UINT32_(1) << 10)

#define PIN_PB04F_TCC0_WO0                         _UINT32_(36)
#define MUX_PB04F_TCC0_WO0                         _UINT32_(5) 
#define PINMUX_PB04F_TCC0_WO0                      ((PIN_PB04F_TCC0_WO0 << 16) | MUX_PB04F_TCC0_WO0)
#define PORT_PB04F_TCC0_WO0                        (_UINT32_(1) << 4)

#define PIN_PC00G_TCC0_WO1                         _UINT32_(64)
#define MUX_PC00G_TCC0_WO1                         _UINT32_(6) 
#define PINMUX_PC00G_TCC0_WO1                      ((PIN_PC00G_TCC0_WO1 << 16) | MUX_PC00G_TCC0_WO1)
#define PORT_PC00G_TCC0_WO1                        (_UINT32_(1) << 0)

#define PIN_PB05F_TCC0_WO1                         _UINT32_(37)
#define MUX_PB05F_TCC0_WO1                         _UINT32_(5) 
#define PINMUX_PB05F_TCC0_WO1                      ((PIN_PB05F_TCC0_WO1 << 16) | MUX_PB05F_TCC0_WO1)
#define PORT_PB05F_TCC0_WO1                        (_UINT32_(1) << 5)

#define PIN_PC01G_TCC0_WO2                         _UINT32_(65)
#define MUX_PC01G_TCC0_WO2                         _UINT32_(6) 
#define PINMUX_PC01G_TCC0_WO2                      ((PIN_PC01G_TCC0_WO2 << 16) | MUX_PC01G_TCC0_WO2)
#define PORT_PC01G_TCC0_WO2                        (_UINT32_(1) << 1)

#define PIN_PB13F_TCC0_WO2                         _UINT32_(45)
#define MUX_PB13F_TCC0_WO2                         _UINT32_(5) 
#define PINMUX_PB13F_TCC0_WO2                      ((PIN_PB13F_TCC0_WO2 << 16) | MUX_PB13F_TCC0_WO2)
#define PORT_PB13F_TCC0_WO2                        (_UINT32_(1) << 13)

#define PIN_PC02G_TCC0_WO3                         _UINT32_(66)
#define MUX_PC02G_TCC0_WO3                         _UINT32_(6) 
#define PINMUX_PC02G_TCC0_WO3                      ((PIN_PC02G_TCC0_WO3 << 16) | MUX_PC02G_TCC0_WO3)
#define PORT_PC02G_TCC0_WO3                        (_UINT32_(1) << 2)

#define PIN_PB06F_TCC0_WO3                         _UINT32_(38)
#define MUX_PB06F_TCC0_WO3                         _UINT32_(5) 
#define PINMUX_PB06F_TCC0_WO3                      ((PIN_PB06F_TCC0_WO3 << 16) | MUX_PB06F_TCC0_WO3)
#define PORT_PB06F_TCC0_WO3                        (_UINT32_(1) << 6)

#define PIN_PC03G_TCC0_WO4                         _UINT32_(67)
#define MUX_PC03G_TCC0_WO4                         _UINT32_(6) 
#define PINMUX_PC03G_TCC0_WO4                      ((PIN_PC03G_TCC0_WO4 << 16) | MUX_PC03G_TCC0_WO4)
#define PORT_PC03G_TCC0_WO4                        (_UINT32_(1) << 3)

#define PIN_PB14F_TCC0_WO4                         _UINT32_(46)
#define MUX_PB14F_TCC0_WO4                         _UINT32_(5) 
#define PINMUX_PB14F_TCC0_WO4                      ((PIN_PB14F_TCC0_WO4 << 16) | MUX_PB14F_TCC0_WO4)
#define PORT_PB14F_TCC0_WO4                        (_UINT32_(1) << 14)

#define PIN_PC04G_TCC0_WO5                         _UINT32_(68)
#define MUX_PC04G_TCC0_WO5                         _UINT32_(6) 
#define PINMUX_PC04G_TCC0_WO5                      ((PIN_PC04G_TCC0_WO5 << 16) | MUX_PC04G_TCC0_WO5)
#define PORT_PC04G_TCC0_WO5                        (_UINT32_(1) << 4)

#define PIN_PB15F_TCC0_WO5                         _UINT32_(47)
#define MUX_PB15F_TCC0_WO5                         _UINT32_(5) 
#define PINMUX_PB15F_TCC0_WO5                      ((PIN_PB15F_TCC0_WO5 << 16) | MUX_PB15F_TCC0_WO5)
#define PORT_PB15F_TCC0_WO5                        (_UINT32_(1) << 15)

#define PIN_PC21G_TCC0_WO6                         _UINT32_(85)
#define MUX_PC21G_TCC0_WO6                         _UINT32_(6) 
#define PINMUX_PC21G_TCC0_WO6                      ((PIN_PC21G_TCC0_WO6 << 16) | MUX_PC21G_TCC0_WO6)
#define PORT_PC21G_TCC0_WO6                        (_UINT32_(1) << 21)

#define PIN_PB21F_TCC0_WO6                         _UINT32_(53)
#define MUX_PB21F_TCC0_WO6                         _UINT32_(5) 
#define PINMUX_PB21F_TCC0_WO6                      ((PIN_PB21F_TCC0_WO6 << 16) | MUX_PB21F_TCC0_WO6)
#define PORT_PB21F_TCC0_WO6                        (_UINT32_(1) << 21)

#define PIN_PC22G_TCC0_WO7                         _UINT32_(86)
#define MUX_PC22G_TCC0_WO7                         _UINT32_(6) 
#define PINMUX_PC22G_TCC0_WO7                      ((PIN_PC22G_TCC0_WO7 << 16) | MUX_PC22G_TCC0_WO7)
#define PORT_PC22G_TCC0_WO7                        (_UINT32_(1) << 22)

#define PIN_PB22F_TCC0_WO7                         _UINT32_(54)
#define MUX_PB22F_TCC0_WO7                         _UINT32_(5) 
#define PINMUX_PB22F_TCC0_WO7                      ((PIN_PB22F_TCC0_WO7 << 16) | MUX_PB22F_TCC0_WO7)
#define PORT_PB22F_TCC0_WO7                        (_UINT32_(1) << 22)

/* ========== PORT definition for TCC1 peripheral ========== */
#define PIN_PC05G_TCC1_WO0                         _UINT32_(69)
#define MUX_PC05G_TCC1_WO0                         _UINT32_(6) 
#define PINMUX_PC05G_TCC1_WO0                      ((PIN_PC05G_TCC1_WO0 << 16) | MUX_PC05G_TCC1_WO0)
#define PORT_PC05G_TCC1_WO0                        (_UINT32_(1) << 5)

#define PIN_PC15F_TCC1_WO0                         _UINT32_(79)
#define MUX_PC15F_TCC1_WO0                         _UINT32_(5) 
#define PINMUX_PC15F_TCC1_WO0                      ((PIN_PC15F_TCC1_WO0 << 16) | MUX_PC15F_TCC1_WO0)
#define PORT_PC15F_TCC1_WO0                        (_UINT32_(1) << 15)

#define PIN_PC06G_TCC1_WO1                         _UINT32_(70)
#define MUX_PC06G_TCC1_WO1                         _UINT32_(6) 
#define PINMUX_PC06G_TCC1_WO1                      ((PIN_PC06G_TCC1_WO1 << 16) | MUX_PC06G_TCC1_WO1)
#define PORT_PC06G_TCC1_WO1                        (_UINT32_(1) << 6)

#define PIN_PC16F_TCC1_WO1                         _UINT32_(80)
#define MUX_PC16F_TCC1_WO1                         _UINT32_(5) 
#define PINMUX_PC16F_TCC1_WO1                      ((PIN_PC16F_TCC1_WO1 << 16) | MUX_PC16F_TCC1_WO1)
#define PORT_PC16F_TCC1_WO1                        (_UINT32_(1) << 16)

#define PIN_PC07G_TCC1_WO2                         _UINT32_(71)
#define MUX_PC07G_TCC1_WO2                         _UINT32_(6) 
#define PINMUX_PC07G_TCC1_WO2                      ((PIN_PC07G_TCC1_WO2 << 16) | MUX_PC07G_TCC1_WO2)
#define PORT_PC07G_TCC1_WO2                        (_UINT32_(1) << 7)

#define PIN_PC17F_TCC1_WO2                         _UINT32_(81)
#define MUX_PC17F_TCC1_WO2                         _UINT32_(5) 
#define PINMUX_PC17F_TCC1_WO2                      ((PIN_PC17F_TCC1_WO2 << 16) | MUX_PC17F_TCC1_WO2)
#define PORT_PC17F_TCC1_WO2                        (_UINT32_(1) << 17)

#define PIN_PC09G_TCC1_WO3                         _UINT32_(73)
#define MUX_PC09G_TCC1_WO3                         _UINT32_(6) 
#define PINMUX_PC09G_TCC1_WO3                      ((PIN_PC09G_TCC1_WO3 << 16) | MUX_PC09G_TCC1_WO3)
#define PORT_PC09G_TCC1_WO3                        (_UINT32_(1) << 9)

#define PIN_PC18F_TCC1_WO3                         _UINT32_(82)
#define MUX_PC18F_TCC1_WO3                         _UINT32_(5) 
#define PINMUX_PC18F_TCC1_WO3                      ((PIN_PC18F_TCC1_WO3 << 16) | MUX_PC18F_TCC1_WO3)
#define PORT_PC18F_TCC1_WO3                        (_UINT32_(1) << 18)

#define PIN_PC15G_TCC1_WO4                         _UINT32_(79)
#define MUX_PC15G_TCC1_WO4                         _UINT32_(6) 
#define PINMUX_PC15G_TCC1_WO4                      ((PIN_PC15G_TCC1_WO4 << 16) | MUX_PC15G_TCC1_WO4)
#define PORT_PC15G_TCC1_WO4                        (_UINT32_(1) << 15)

#define PIN_PC19F_TCC1_WO4                         _UINT32_(83)
#define MUX_PC19F_TCC1_WO4                         _UINT32_(5) 
#define PINMUX_PC19F_TCC1_WO4                      ((PIN_PC19F_TCC1_WO4 << 16) | MUX_PC19F_TCC1_WO4)
#define PORT_PC19F_TCC1_WO4                        (_UINT32_(1) << 19)

#define PIN_PC10G_TCC1_WO5                         _UINT32_(74)
#define MUX_PC10G_TCC1_WO5                         _UINT32_(6) 
#define PINMUX_PC10G_TCC1_WO5                      ((PIN_PC10G_TCC1_WO5 << 16) | MUX_PC10G_TCC1_WO5)
#define PORT_PC10G_TCC1_WO5                        (_UINT32_(1) << 10)

#define PIN_PC20F_TCC1_WO5                         _UINT32_(84)
#define MUX_PC20F_TCC1_WO5                         _UINT32_(5) 
#define PINMUX_PC20F_TCC1_WO5                      ((PIN_PC20F_TCC1_WO5 << 16) | MUX_PC20F_TCC1_WO5)
#define PORT_PC20F_TCC1_WO5                        (_UINT32_(1) << 20)

#define PIN_PC11G_TCC1_WO6                         _UINT32_(75)
#define MUX_PC11G_TCC1_WO6                         _UINT32_(6) 
#define PINMUX_PC11G_TCC1_WO6                      ((PIN_PC11G_TCC1_WO6 << 16) | MUX_PC11G_TCC1_WO6)
#define PORT_PC11G_TCC1_WO6                        (_UINT32_(1) << 11)

#define PIN_PC28F_TCC1_WO6                         _UINT32_(92)
#define MUX_PC28F_TCC1_WO6                         _UINT32_(5) 
#define PINMUX_PC28F_TCC1_WO6                      ((PIN_PC28F_TCC1_WO6 << 16) | MUX_PC28F_TCC1_WO6)
#define PORT_PC28F_TCC1_WO6                        (_UINT32_(1) << 28)

#define PIN_PC12G_TCC1_WO7                         _UINT32_(76)
#define MUX_PC12G_TCC1_WO7                         _UINT32_(6) 
#define PINMUX_PC12G_TCC1_WO7                      ((PIN_PC12G_TCC1_WO7 << 16) | MUX_PC12G_TCC1_WO7)
#define PORT_PC12G_TCC1_WO7                        (_UINT32_(1) << 12)

#define PIN_PC29F_TCC1_WO7                         _UINT32_(93)
#define MUX_PC29F_TCC1_WO7                         _UINT32_(5) 
#define PINMUX_PC29F_TCC1_WO7                      ((PIN_PC29F_TCC1_WO7 << 16) | MUX_PC29F_TCC1_WO7)
#define PORT_PC29F_TCC1_WO7                        (_UINT32_(1) << 29)

/* ========== PORT definition for TCC2 peripheral ========== */
#define PIN_PD05G_TCC2_WO0                         _UINT32_(101)
#define MUX_PD05G_TCC2_WO0                         _UINT32_(6) 
#define PINMUX_PD05G_TCC2_WO0                      ((PIN_PD05G_TCC2_WO0 << 16) | MUX_PD05G_TCC2_WO0)
#define PORT_PD05G_TCC2_WO0                        (_UINT32_(1) << 5)

#define PIN_PA00F_TCC2_WO0                         _UINT32_(0) 
#define MUX_PA00F_TCC2_WO0                         _UINT32_(5) 
#define PINMUX_PA00F_TCC2_WO0                      ((PIN_PA00F_TCC2_WO0 << 16) | MUX_PA00F_TCC2_WO0)
#define PORT_PA00F_TCC2_WO0                        (_UINT32_(1) << 0)

#define PIN_PD06G_TCC2_WO1                         _UINT32_(102)
#define MUX_PD06G_TCC2_WO1                         _UINT32_(6) 
#define PINMUX_PD06G_TCC2_WO1                      ((PIN_PD06G_TCC2_WO1 << 16) | MUX_PD06G_TCC2_WO1)
#define PORT_PD06G_TCC2_WO1                        (_UINT32_(1) << 6)

#define PIN_PD12F_TCC2_WO1                         _UINT32_(108)
#define MUX_PD12F_TCC2_WO1                         _UINT32_(5) 
#define PINMUX_PD12F_TCC2_WO1                      ((PIN_PD12F_TCC2_WO1 << 16) | MUX_PD12F_TCC2_WO1)
#define PORT_PD12F_TCC2_WO1                        (_UINT32_(1) << 12)

#define PIN_PD07G_TCC2_WO2                         _UINT32_(103)
#define MUX_PD07G_TCC2_WO2                         _UINT32_(6) 
#define PINMUX_PD07G_TCC2_WO2                      ((PIN_PD07G_TCC2_WO2 << 16) | MUX_PD07G_TCC2_WO2)
#define PORT_PD07G_TCC2_WO2                        (_UINT32_(1) << 7)

#define PIN_PD11F_TCC2_WO2                         _UINT32_(107)
#define MUX_PD11F_TCC2_WO2                         _UINT32_(5) 
#define PINMUX_PD11F_TCC2_WO2                      ((PIN_PD11F_TCC2_WO2 << 16) | MUX_PD11F_TCC2_WO2)
#define PORT_PD11F_TCC2_WO2                        (_UINT32_(1) << 11)

#define PIN_PD08G_TCC2_WO3                         _UINT32_(104)
#define MUX_PD08G_TCC2_WO3                         _UINT32_(6) 
#define PINMUX_PD08G_TCC2_WO3                      ((PIN_PD08G_TCC2_WO3 << 16) | MUX_PD08G_TCC2_WO3)
#define PORT_PD08G_TCC2_WO3                        (_UINT32_(1) << 8)

#define PIN_PA01F_TCC2_WO3                         _UINT32_(1) 
#define MUX_PA01F_TCC2_WO3                         _UINT32_(5) 
#define PINMUX_PA01F_TCC2_WO3                      ((PIN_PA01F_TCC2_WO3 << 16) | MUX_PA01F_TCC2_WO3)
#define PORT_PA01F_TCC2_WO3                        (_UINT32_(1) << 1)

#define PIN_PD09G_TCC2_WO4                         _UINT32_(105)
#define MUX_PD09G_TCC2_WO4                         _UINT32_(6) 
#define PINMUX_PD09G_TCC2_WO4                      ((PIN_PD09G_TCC2_WO4 << 16) | MUX_PD09G_TCC2_WO4)
#define PORT_PD09G_TCC2_WO4                        (_UINT32_(1) << 9)

#define PIN_PD06F_TCC2_WO4                         _UINT32_(102)
#define MUX_PD06F_TCC2_WO4                         _UINT32_(5) 
#define PINMUX_PD06F_TCC2_WO4                      ((PIN_PD06F_TCC2_WO4 << 16) | MUX_PD06F_TCC2_WO4)
#define PORT_PD06F_TCC2_WO4                        (_UINT32_(1) << 6)

#define PIN_PD10G_TCC2_WO5                         _UINT32_(106)
#define MUX_PD10G_TCC2_WO5                         _UINT32_(6) 
#define PINMUX_PD10G_TCC2_WO5                      ((PIN_PD10G_TCC2_WO5 << 16) | MUX_PD10G_TCC2_WO5)
#define PORT_PD10G_TCC2_WO5                        (_UINT32_(1) << 10)

#define PIN_PD07F_TCC2_WO5                         _UINT32_(103)
#define MUX_PD07F_TCC2_WO5                         _UINT32_(5) 
#define PINMUX_PD07F_TCC2_WO5                      ((PIN_PD07F_TCC2_WO5 << 16) | MUX_PD07F_TCC2_WO5)
#define PORT_PD07F_TCC2_WO5                        (_UINT32_(1) << 7)

#define PIN_PD11G_TCC2_WO6                         _UINT32_(107)
#define MUX_PD11G_TCC2_WO6                         _UINT32_(6) 
#define PINMUX_PD11G_TCC2_WO6                      ((PIN_PD11G_TCC2_WO6 << 16) | MUX_PD11G_TCC2_WO6)
#define PORT_PD11G_TCC2_WO6                        (_UINT32_(1) << 11)

#define PIN_PD13F_TCC2_WO6                         _UINT32_(109)
#define MUX_PD13F_TCC2_WO6                         _UINT32_(5) 
#define PINMUX_PD13F_TCC2_WO6                      ((PIN_PD13F_TCC2_WO6 << 16) | MUX_PD13F_TCC2_WO6)
#define PORT_PD13F_TCC2_WO6                        (_UINT32_(1) << 13)

#define PIN_PD12G_TCC2_WO7                         _UINT32_(108)
#define MUX_PD12G_TCC2_WO7                         _UINT32_(6) 
#define PINMUX_PD12G_TCC2_WO7                      ((PIN_PD12G_TCC2_WO7 << 16) | MUX_PD12G_TCC2_WO7)
#define PORT_PD12G_TCC2_WO7                        (_UINT32_(1) << 12)

#define PIN_PD14F_TCC2_WO7                         _UINT32_(110)
#define MUX_PD14F_TCC2_WO7                         _UINT32_(5) 
#define PINMUX_PD14F_TCC2_WO7                      ((PIN_PD14F_TCC2_WO7 << 16) | MUX_PD14F_TCC2_WO7)
#define PORT_PD14F_TCC2_WO7                        (_UINT32_(1) << 14)

/* ========== PORT definition for TCC3 peripheral ========== */
#define PIN_PA09G_TCC3_WO0                         _UINT32_(9) 
#define MUX_PA09G_TCC3_WO0                         _UINT32_(6) 
#define PINMUX_PA09G_TCC3_WO0                      ((PIN_PA09G_TCC3_WO0 << 16) | MUX_PA09G_TCC3_WO0)
#define PORT_PA09G_TCC3_WO0                        (_UINT32_(1) << 9)

#define PIN_PA04F_TCC3_WO0                         _UINT32_(4) 
#define MUX_PA04F_TCC3_WO0                         _UINT32_(5) 
#define PINMUX_PA04F_TCC3_WO0                      ((PIN_PA04F_TCC3_WO0 << 16) | MUX_PA04F_TCC3_WO0)
#define PORT_PA04F_TCC3_WO0                        (_UINT32_(1) << 4)

#define PIN_PA10G_TCC3_WO1                         _UINT32_(10)
#define MUX_PA10G_TCC3_WO1                         _UINT32_(6) 
#define PINMUX_PA10G_TCC3_WO1                      ((PIN_PA10G_TCC3_WO1 << 16) | MUX_PA10G_TCC3_WO1)
#define PORT_PA10G_TCC3_WO1                        (_UINT32_(1) << 10)

#define PIN_PA05F_TCC3_WO1                         _UINT32_(5) 
#define MUX_PA05F_TCC3_WO1                         _UINT32_(5) 
#define PINMUX_PA05F_TCC3_WO1                      ((PIN_PA05F_TCC3_WO1 << 16) | MUX_PA05F_TCC3_WO1)
#define PORT_PA05F_TCC3_WO1                        (_UINT32_(1) << 5)

#define PIN_PA11G_TCC3_WO2                         _UINT32_(11)
#define MUX_PA11G_TCC3_WO2                         _UINT32_(6) 
#define PINMUX_PA11G_TCC3_WO2                      ((PIN_PA11G_TCC3_WO2 << 16) | MUX_PA11G_TCC3_WO2)
#define PORT_PA11G_TCC3_WO2                        (_UINT32_(1) << 11)

#define PIN_PA06F_TCC3_WO2                         _UINT32_(6) 
#define MUX_PA06F_TCC3_WO2                         _UINT32_(5) 
#define PINMUX_PA06F_TCC3_WO2                      ((PIN_PA06F_TCC3_WO2 << 16) | MUX_PA06F_TCC3_WO2)
#define PORT_PA06F_TCC3_WO2                        (_UINT32_(1) << 6)

#define PIN_PA12G_TCC3_WO3                         _UINT32_(12)
#define MUX_PA12G_TCC3_WO3                         _UINT32_(6) 
#define PINMUX_PA12G_TCC3_WO3                      ((PIN_PA12G_TCC3_WO3 << 16) | MUX_PA12G_TCC3_WO3)
#define PORT_PA12G_TCC3_WO3                        (_UINT32_(1) << 12)

#define PIN_PA07F_TCC3_WO3                         _UINT32_(7) 
#define MUX_PA07F_TCC3_WO3                         _UINT32_(5) 
#define PINMUX_PA07F_TCC3_WO3                      ((PIN_PA07F_TCC3_WO3 << 16) | MUX_PA07F_TCC3_WO3)
#define PORT_PA07F_TCC3_WO3                        (_UINT32_(1) << 7)

#define PIN_PB00G_TCC3_WO4                         _UINT32_(32)
#define MUX_PB00G_TCC3_WO4                         _UINT32_(6) 
#define PINMUX_PB00G_TCC3_WO4                      ((PIN_PB00G_TCC3_WO4 << 16) | MUX_PB00G_TCC3_WO4)
#define PORT_PB00G_TCC3_WO4                        (_UINT32_(1) << 0)

#define PIN_PA08F_TCC3_WO4                         _UINT32_(8) 
#define MUX_PA08F_TCC3_WO4                         _UINT32_(5) 
#define PINMUX_PA08F_TCC3_WO4                      ((PIN_PA08F_TCC3_WO4 << 16) | MUX_PA08F_TCC3_WO4)
#define PORT_PA08F_TCC3_WO4                        (_UINT32_(1) << 8)

#define PIN_PB01G_TCC3_WO5                         _UINT32_(33)
#define MUX_PB01G_TCC3_WO5                         _UINT32_(6) 
#define PINMUX_PB01G_TCC3_WO5                      ((PIN_PB01G_TCC3_WO5 << 16) | MUX_PB01G_TCC3_WO5)
#define PORT_PB01G_TCC3_WO5                        (_UINT32_(1) << 1)

#define PIN_PA18F_TCC3_WO5                         _UINT32_(18)
#define MUX_PA18F_TCC3_WO5                         _UINT32_(5) 
#define PINMUX_PA18F_TCC3_WO5                      ((PIN_PA18F_TCC3_WO5 << 16) | MUX_PA18F_TCC3_WO5)
#define PORT_PA18F_TCC3_WO5                        (_UINT32_(1) << 18)

#define PIN_PB11G_TCC3_WO6                         _UINT32_(43)
#define MUX_PB11G_TCC3_WO6                         _UINT32_(6) 
#define PINMUX_PB11G_TCC3_WO6                      ((PIN_PB11G_TCC3_WO6 << 16) | MUX_PB11G_TCC3_WO6)
#define PORT_PB11G_TCC3_WO6                        (_UINT32_(1) << 11)

#define PIN_PA28F_TCC3_WO6                         _UINT32_(28)
#define MUX_PA28F_TCC3_WO6                         _UINT32_(5) 
#define PINMUX_PA28F_TCC3_WO6                      ((PIN_PA28F_TCC3_WO6 << 16) | MUX_PA28F_TCC3_WO6)
#define PORT_PA28F_TCC3_WO6                        (_UINT32_(1) << 28)

#define PIN_PB12G_TCC3_WO7                         _UINT32_(44)
#define MUX_PB12G_TCC3_WO7                         _UINT32_(6) 
#define PINMUX_PB12G_TCC3_WO7                      ((PIN_PB12G_TCC3_WO7 << 16) | MUX_PB12G_TCC3_WO7)
#define PORT_PB12G_TCC3_WO7                        (_UINT32_(1) << 12)

#define PIN_PA19F_TCC3_WO7                         _UINT32_(19)
#define MUX_PA19F_TCC3_WO7                         _UINT32_(5) 
#define PINMUX_PA19F_TCC3_WO7                      ((PIN_PA19F_TCC3_WO7 << 16) | MUX_PA19F_TCC3_WO7)
#define PORT_PA19F_TCC3_WO7                        (_UINT32_(1) << 19)

/* ========== PORT definition for TCC4 peripheral ========== */
#define PIN_PA11F_TCC4_WO0                         _UINT32_(11)
#define MUX_PA11F_TCC4_WO0                         _UINT32_(5) 
#define PINMUX_PA11F_TCC4_WO0                      ((PIN_PA11F_TCC4_WO0 << 16) | MUX_PA11F_TCC4_WO0)
#define PORT_PA11F_TCC4_WO0                        (_UINT32_(1) << 11)

#define PIN_PA13F_TCC4_WO0                         _UINT32_(13)
#define MUX_PA13F_TCC4_WO0                         _UINT32_(5) 
#define PINMUX_PA13F_TCC4_WO0                      ((PIN_PA13F_TCC4_WO0 << 16) | MUX_PA13F_TCC4_WO0)
#define PORT_PA13F_TCC4_WO0                        (_UINT32_(1) << 13)

#define PIN_PA20F_TCC4_WO0                         _UINT32_(20)
#define MUX_PA20F_TCC4_WO0                         _UINT32_(5) 
#define PINMUX_PA20F_TCC4_WO0                      ((PIN_PA20F_TCC4_WO0 << 16) | MUX_PA20F_TCC4_WO0)
#define PORT_PA20F_TCC4_WO0                        (_UINT32_(1) << 20)

#define PIN_PB12F_TCC4_WO0                         _UINT32_(44)
#define MUX_PB12F_TCC4_WO0                         _UINT32_(5) 
#define PINMUX_PB12F_TCC4_WO0                      ((PIN_PB12F_TCC4_WO0 << 16) | MUX_PB12F_TCC4_WO0)
#define PORT_PB12F_TCC4_WO0                        (_UINT32_(1) << 12)

#define PIN_PA12F_TCC4_WO1                         _UINT32_(12)
#define MUX_PA12F_TCC4_WO1                         _UINT32_(5) 
#define PINMUX_PA12F_TCC4_WO1                      ((PIN_PA12F_TCC4_WO1 << 16) | MUX_PA12F_TCC4_WO1)
#define PORT_PA12F_TCC4_WO1                        (_UINT32_(1) << 12)

#define PIN_PA14F_TCC4_WO1                         _UINT32_(14)
#define MUX_PA14F_TCC4_WO1                         _UINT32_(5) 
#define PINMUX_PA14F_TCC4_WO1                      ((PIN_PA14F_TCC4_WO1 << 16) | MUX_PA14F_TCC4_WO1)
#define PORT_PA14F_TCC4_WO1                        (_UINT32_(1) << 14)

#define PIN_PA21F_TCC4_WO1                         _UINT32_(21)
#define MUX_PA21F_TCC4_WO1                         _UINT32_(5) 
#define PINMUX_PA21F_TCC4_WO1                      ((PIN_PA21F_TCC4_WO1 << 16) | MUX_PA21F_TCC4_WO1)
#define PORT_PA21F_TCC4_WO1                        (_UINT32_(1) << 21)

#define PIN_PB18F_TCC4_WO1                         _UINT32_(50)
#define MUX_PB18F_TCC4_WO1                         _UINT32_(5) 
#define PINMUX_PB18F_TCC4_WO1                      ((PIN_PB18F_TCC4_WO1 << 16) | MUX_PB18F_TCC4_WO1)
#define PORT_PB18F_TCC4_WO1                        (_UINT32_(1) << 18)

/* ========== PORT definition for TCC5 peripheral ========== */
#define PIN_PA15F_TCC5_WO0                         _UINT32_(15)
#define MUX_PA15F_TCC5_WO0                         _UINT32_(5) 
#define PINMUX_PA15F_TCC5_WO0                      ((PIN_PA15F_TCC5_WO0 << 16) | MUX_PA15F_TCC5_WO0)
#define PORT_PA15F_TCC5_WO0                        (_UINT32_(1) << 15)

#define PIN_PA22F_TCC5_WO0                         _UINT32_(22)
#define MUX_PA22F_TCC5_WO0                         _UINT32_(5) 
#define PINMUX_PA22F_TCC5_WO0                      ((PIN_PA22F_TCC5_WO0 << 16) | MUX_PA22F_TCC5_WO0)
#define PORT_PA22F_TCC5_WO0                        (_UINT32_(1) << 22)

#define PIN_PB00F_TCC5_WO0                         _UINT32_(32)
#define MUX_PB00F_TCC5_WO0                         _UINT32_(5) 
#define PINMUX_PB00F_TCC5_WO0                      ((PIN_PB00F_TCC5_WO0 << 16) | MUX_PB00F_TCC5_WO0)
#define PORT_PB00F_TCC5_WO0                        (_UINT32_(1) << 0)

#define PIN_PB19F_TCC5_WO0                         _UINT32_(51)
#define MUX_PB19F_TCC5_WO0                         _UINT32_(5) 
#define PINMUX_PB19F_TCC5_WO0                      ((PIN_PB19F_TCC5_WO0 << 16) | MUX_PB19F_TCC5_WO0)
#define PORT_PB19F_TCC5_WO0                        (_UINT32_(1) << 19)

#define PIN_PA16F_TCC5_WO1                         _UINT32_(16)
#define MUX_PA16F_TCC5_WO1                         _UINT32_(5) 
#define PINMUX_PA16F_TCC5_WO1                      ((PIN_PA16F_TCC5_WO1 << 16) | MUX_PA16F_TCC5_WO1)
#define PORT_PA16F_TCC5_WO1                        (_UINT32_(1) << 16)

#define PIN_PA23F_TCC5_WO1                         _UINT32_(23)
#define MUX_PA23F_TCC5_WO1                         _UINT32_(5) 
#define PINMUX_PA23F_TCC5_WO1                      ((PIN_PA23F_TCC5_WO1 << 16) | MUX_PA23F_TCC5_WO1)
#define PORT_PA23F_TCC5_WO1                        (_UINT32_(1) << 23)

#define PIN_PB01F_TCC5_WO1                         _UINT32_(33)
#define MUX_PB01F_TCC5_WO1                         _UINT32_(5) 
#define PINMUX_PB01F_TCC5_WO1                      ((PIN_PB01F_TCC5_WO1 << 16) | MUX_PB01F_TCC5_WO1)
#define PORT_PB01F_TCC5_WO1                        (_UINT32_(1) << 1)

#define PIN_PB20F_TCC5_WO1                         _UINT32_(52)
#define MUX_PB20F_TCC5_WO1                         _UINT32_(5) 
#define PINMUX_PB20F_TCC5_WO1                      ((PIN_PB20F_TCC5_WO1 << 16) | MUX_PB20F_TCC5_WO1)
#define PORT_PB20F_TCC5_WO1                        (_UINT32_(1) << 20)

/* ========== PORT definition for TCC6 peripheral ========== */
#define PIN_PB16F_TCC6_WO0                         _UINT32_(48)
#define MUX_PB16F_TCC6_WO0                         _UINT32_(5) 
#define PINMUX_PB16F_TCC6_WO0                      ((PIN_PB16F_TCC6_WO0 << 16) | MUX_PB16F_TCC6_WO0)
#define PORT_PB16F_TCC6_WO0                        (_UINT32_(1) << 16)

#define PIN_PB23F_TCC6_WO0                         _UINT32_(55)
#define MUX_PB23F_TCC6_WO0                         _UINT32_(5) 
#define PINMUX_PB23F_TCC6_WO0                      ((PIN_PB23F_TCC6_WO0 << 16) | MUX_PB23F_TCC6_WO0)
#define PORT_PB23F_TCC6_WO0                        (_UINT32_(1) << 23)

#define PIN_PC01F_TCC6_WO0                         _UINT32_(65)
#define MUX_PC01F_TCC6_WO0                         _UINT32_(5) 
#define PINMUX_PC01F_TCC6_WO0                      ((PIN_PC01F_TCC6_WO0 << 16) | MUX_PC01F_TCC6_WO0)
#define PORT_PC01F_TCC6_WO0                        (_UINT32_(1) << 1)

#define PIN_PB17F_TCC6_WO1                         _UINT32_(49)
#define MUX_PB17F_TCC6_WO1                         _UINT32_(5) 
#define PINMUX_PB17F_TCC6_WO1                      ((PIN_PB17F_TCC6_WO1 << 16) | MUX_PB17F_TCC6_WO1)
#define PORT_PB17F_TCC6_WO1                        (_UINT32_(1) << 17)

#define PIN_PB24F_TCC6_WO1                         _UINT32_(56)
#define MUX_PB24F_TCC6_WO1                         _UINT32_(5) 
#define PINMUX_PB24F_TCC6_WO1                      ((PIN_PB24F_TCC6_WO1 << 16) | MUX_PB24F_TCC6_WO1)
#define PORT_PB24F_TCC6_WO1                        (_UINT32_(1) << 24)

#define PIN_PC02F_TCC6_WO1                         _UINT32_(66)
#define MUX_PC02F_TCC6_WO1                         _UINT32_(5) 
#define PINMUX_PC02F_TCC6_WO1                      ((PIN_PC02F_TCC6_WO1 << 16) | MUX_PC02F_TCC6_WO1)
#define PORT_PC02F_TCC6_WO1                        (_UINT32_(1) << 2)

/* ========== PORT definition for TCC7 peripheral ========== */
#define PIN_PB07F_TCC7_WO0                         _UINT32_(39)
#define MUX_PB07F_TCC7_WO0                         _UINT32_(5) 
#define PINMUX_PB07F_TCC7_WO0                      ((PIN_PB07F_TCC7_WO0 << 16) | MUX_PB07F_TCC7_WO0)
#define PORT_PB07F_TCC7_WO0                        (_UINT32_(1) << 7)

#define PIN_PB25F_TCC7_WO0                         _UINT32_(57)
#define MUX_PB25F_TCC7_WO0                         _UINT32_(5) 
#define PINMUX_PB25F_TCC7_WO0                      ((PIN_PB25F_TCC7_WO0 << 16) | MUX_PB25F_TCC7_WO0)
#define PORT_PB25F_TCC7_WO0                        (_UINT32_(1) << 25)

#define PIN_PC03F_TCC7_WO0                         _UINT32_(67)
#define MUX_PC03F_TCC7_WO0                         _UINT32_(5) 
#define PINMUX_PC03F_TCC7_WO0                      ((PIN_PC03F_TCC7_WO0 << 16) | MUX_PC03F_TCC7_WO0)
#define PORT_PC03F_TCC7_WO0                        (_UINT32_(1) << 3)

#define PIN_PB08F_TCC7_WO1                         _UINT32_(40)
#define MUX_PB08F_TCC7_WO1                         _UINT32_(5) 
#define PINMUX_PB08F_TCC7_WO1                      ((PIN_PB08F_TCC7_WO1 << 16) | MUX_PB08F_TCC7_WO1)
#define PORT_PB08F_TCC7_WO1                        (_UINT32_(1) << 8)

#define PIN_PB26F_TCC7_WO1                         _UINT32_(58)
#define MUX_PB26F_TCC7_WO1                         _UINT32_(5) 
#define PINMUX_PB26F_TCC7_WO1                      ((PIN_PB26F_TCC7_WO1 << 16) | MUX_PB26F_TCC7_WO1)
#define PORT_PB26F_TCC7_WO1                        (_UINT32_(1) << 26)

#define PIN_PC04F_TCC7_WO1                         _UINT32_(68)
#define MUX_PC04F_TCC7_WO1                         _UINT32_(5) 
#define PINMUX_PC04F_TCC7_WO1                      ((PIN_PC04F_TCC7_WO1 << 16) | MUX_PC04F_TCC7_WO1)
#define PORT_PC04F_TCC7_WO1                        (_UINT32_(1) << 4)

/* ========== PORT definition for USB peripheral ========== */
#define PIN_PD03H_USB_DM                           _UINT32_(99)
#define MUX_PD03H_USB_DM                           _UINT32_(7) 
#define PINMUX_PD03H_USB_DM                        ((PIN_PD03H_USB_DM << 16) | MUX_PD03H_USB_DM)
#define PORT_PD03H_USB_DM                          (_UINT32_(1) << 3)

#define PIN_PD04H_USB_DP                           _UINT32_(100)
#define MUX_PD04H_USB_DP                           _UINT32_(7) 
#define PINMUX_PD04H_USB_DP                        ((PIN_PD04H_USB_DP << 16) | MUX_PD04H_USB_DP)
#define PORT_PD04H_USB_DP                          (_UINT32_(1) << 4)

#define PIN_PC01H_USB_SOF_1KHZ                     _UINT32_(65)
#define MUX_PC01H_USB_SOF_1KHZ                     _UINT32_(7) 
#define PINMUX_PC01H_USB_SOF_1KHZ                  ((PIN_PC01H_USB_SOF_1KHZ << 16) | MUX_PC01H_USB_SOF_1KHZ)
#define PORT_PC01H_USB_SOF_1KHZ                    (_UINT32_(1) << 1)

#define PIN_PD02H_USB_SOF_1KHZ                     _UINT32_(98)
#define MUX_PD02H_USB_SOF_1KHZ                     _UINT32_(7) 
#define PINMUX_PD02H_USB_SOF_1KHZ                  ((PIN_PD02H_USB_SOF_1KHZ << 16) | MUX_PD02H_USB_SOF_1KHZ)
#define PORT_PD02H_USB_SOF_1KHZ                    (_UINT32_(1) << 2)



#endif /* _PIC32CK2051GC01144_GPIO_H_ */

