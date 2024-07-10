/*
 * Peripheral I/O description for PIC32CM5164LS00048
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

/* file generated from device description version 2022-09-09T06:09:04Z */
#ifndef _PIC32CM5164LS00048_GPIO_H_
#define _PIC32CM5164LS00048_GPIO_H_

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
#define PIN_PA30                    (   30)  /**< Pin Number for PA30 */
#define PIN_PA31                    (   31)  /**< Pin Number for PA31 */
#define PIN_PB02                    (   34)  /**< Pin Number for PB02 */
#define PIN_PB03                    (   35)  /**< Pin Number for PB03 */
#define PIN_PB08                    (   40)  /**< Pin Number for PB08 */
#define PIN_PB09                    (   41)  /**< Pin Number for PB09 */
#define PIN_PB22                    (   54)  /**< Pin Number for PB22 */
#define PIN_PB23                    (   55)  /**< Pin Number for PB23 */

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
#define PORT_PA30                   (_UINT32_(1) << 30) /**< PORT mask for PA30 */
#define PORT_PA31                   (_UINT32_(1) << 31) /**< PORT mask for PA31 */
#define PORT_PB02                   (_UINT32_(1) << 2) /**< PORT mask for PB02 */
#define PORT_PB03                   (_UINT32_(1) << 3) /**< PORT mask for PB03 */
#define PORT_PB08                   (_UINT32_(1) << 8) /**< PORT mask for PB08 */
#define PORT_PB09                   (_UINT32_(1) << 9) /**< PORT mask for PB09 */
#define PORT_PB22                   (_UINT32_(1) << 22) /**< PORT mask for PB22 */
#define PORT_PB23                   (_UINT32_(1) << 23) /**< PORT mask for PB23 */

/* ========== PORT definition for AC peripheral ========== */
#define PIN_PA04B_AC_AIN0                          _UINT32_(4) 
#define MUX_PA04B_AC_AIN0                          _UINT32_(1) 
#define PINMUX_PA04B_AC_AIN0                       ((PIN_PA04B_AC_AIN0 << 16) | MUX_PA04B_AC_AIN0)
#define PORT_PA04B_AC_AIN0                         (_UINT32_(1) << 4)

#define PIN_PA05B_AC_AIN1                          _UINT32_(5) 
#define MUX_PA05B_AC_AIN1                          _UINT32_(1) 
#define PINMUX_PA05B_AC_AIN1                       ((PIN_PA05B_AC_AIN1 << 16) | MUX_PA05B_AC_AIN1)
#define PORT_PA05B_AC_AIN1                         (_UINT32_(1) << 5)

#define PIN_PA06B_AC_AIN2                          _UINT32_(6) 
#define MUX_PA06B_AC_AIN2                          _UINT32_(1) 
#define PINMUX_PA06B_AC_AIN2                       ((PIN_PA06B_AC_AIN2 << 16) | MUX_PA06B_AC_AIN2)
#define PORT_PA06B_AC_AIN2                         (_UINT32_(1) << 6)

#define PIN_PA07B_AC_AIN3                          _UINT32_(7) 
#define MUX_PA07B_AC_AIN3                          _UINT32_(1) 
#define PINMUX_PA07B_AC_AIN3                       ((PIN_PA07B_AC_AIN3 << 16) | MUX_PA07B_AC_AIN3)
#define PORT_PA07B_AC_AIN3                         (_UINT32_(1) << 7)

#define PIN_PB02B_AC_AIN4                          _UINT32_(34)
#define MUX_PB02B_AC_AIN4                          _UINT32_(1) 
#define PINMUX_PB02B_AC_AIN4                       ((PIN_PB02B_AC_AIN4 << 16) | MUX_PB02B_AC_AIN4)
#define PORT_PB02B_AC_AIN4                         (_UINT32_(1) << 2)

#define PIN_PB03B_AC_AIN5                          _UINT32_(35)
#define MUX_PB03B_AC_AIN5                          _UINT32_(1) 
#define PINMUX_PB03B_AC_AIN5                       ((PIN_PB03B_AC_AIN5 << 16) | MUX_PB03B_AC_AIN5)
#define PORT_PB03B_AC_AIN5                         (_UINT32_(1) << 3)

#define PIN_PA12H_AC_CMP0                          _UINT32_(12)
#define MUX_PA12H_AC_CMP0                          _UINT32_(7) 
#define PINMUX_PA12H_AC_CMP0                       ((PIN_PA12H_AC_CMP0 << 16) | MUX_PA12H_AC_CMP0)
#define PORT_PA12H_AC_CMP0                         (_UINT32_(1) << 12)

#define PIN_PA18H_AC_CMP0                          _UINT32_(18)
#define MUX_PA18H_AC_CMP0                          _UINT32_(7) 
#define PINMUX_PA18H_AC_CMP0                       ((PIN_PA18H_AC_CMP0 << 16) | MUX_PA18H_AC_CMP0)
#define PORT_PA18H_AC_CMP0                         (_UINT32_(1) << 18)

#define PIN_PA13H_AC_CMP1                          _UINT32_(13)
#define MUX_PA13H_AC_CMP1                          _UINT32_(7) 
#define PINMUX_PA13H_AC_CMP1                       ((PIN_PA13H_AC_CMP1 << 16) | MUX_PA13H_AC_CMP1)
#define PORT_PA13H_AC_CMP1                         (_UINT32_(1) << 13)

#define PIN_PA19H_AC_CMP1                          _UINT32_(19)
#define MUX_PA19H_AC_CMP1                          _UINT32_(7) 
#define PINMUX_PA19H_AC_CMP1                       ((PIN_PA19H_AC_CMP1 << 16) | MUX_PA19H_AC_CMP1)
#define PORT_PA19H_AC_CMP1                         (_UINT32_(1) << 19)

#define PIN_PA24H_AC_CMP2                          _UINT32_(24)
#define MUX_PA24H_AC_CMP2                          _UINT32_(7) 
#define PINMUX_PA24H_AC_CMP2                       ((PIN_PA24H_AC_CMP2 << 16) | MUX_PA24H_AC_CMP2)
#define PORT_PA24H_AC_CMP2                         (_UINT32_(1) << 24)

#define PIN_PA25H_AC_CMP3                          _UINT32_(25)
#define MUX_PA25H_AC_CMP3                          _UINT32_(7) 
#define PINMUX_PA25H_AC_CMP3                       ((PIN_PA25H_AC_CMP3 << 16) | MUX_PA25H_AC_CMP3)
#define PORT_PA25H_AC_CMP3                         (_UINT32_(1) << 25)

/* ========== PORT definition for ADC peripheral ========== */
#define PIN_PA02B_ADC_AIN0                         _UINT32_(2) 
#define MUX_PA02B_ADC_AIN0                         _UINT32_(1) 
#define PINMUX_PA02B_ADC_AIN0                      ((PIN_PA02B_ADC_AIN0 << 16) | MUX_PA02B_ADC_AIN0)
#define PORT_PA02B_ADC_AIN0                        (_UINT32_(1) << 2)

#define PIN_PA03B_ADC_AIN1                         _UINT32_(3) 
#define MUX_PA03B_ADC_AIN1                         _UINT32_(1) 
#define PINMUX_PA03B_ADC_AIN1                      ((PIN_PA03B_ADC_AIN1 << 16) | MUX_PA03B_ADC_AIN1)
#define PORT_PA03B_ADC_AIN1                        (_UINT32_(1) << 3)

#define PIN_PA04B_ADC_AIN2                         _UINT32_(4) 
#define MUX_PA04B_ADC_AIN2                         _UINT32_(1) 
#define PINMUX_PA04B_ADC_AIN2                      ((PIN_PA04B_ADC_AIN2 << 16) | MUX_PA04B_ADC_AIN2)
#define PORT_PA04B_ADC_AIN2                        (_UINT32_(1) << 4)

#define PIN_PA05B_ADC_AIN3                         _UINT32_(5) 
#define MUX_PA05B_ADC_AIN3                         _UINT32_(1) 
#define PINMUX_PA05B_ADC_AIN3                      ((PIN_PA05B_ADC_AIN3 << 16) | MUX_PA05B_ADC_AIN3)
#define PORT_PA05B_ADC_AIN3                        (_UINT32_(1) << 5)

#define PIN_PA06B_ADC_AIN4                         _UINT32_(6) 
#define MUX_PA06B_ADC_AIN4                         _UINT32_(1) 
#define PINMUX_PA06B_ADC_AIN4                      ((PIN_PA06B_ADC_AIN4 << 16) | MUX_PA06B_ADC_AIN4)
#define PORT_PA06B_ADC_AIN4                        (_UINT32_(1) << 6)

#define PIN_PA07B_ADC_AIN5                         _UINT32_(7) 
#define MUX_PA07B_ADC_AIN5                         _UINT32_(1) 
#define PINMUX_PA07B_ADC_AIN5                      ((PIN_PA07B_ADC_AIN5 << 16) | MUX_PA07B_ADC_AIN5)
#define PORT_PA07B_ADC_AIN5                        (_UINT32_(1) << 7)

#define PIN_PA08B_ADC_AIN6                         _UINT32_(8) 
#define MUX_PA08B_ADC_AIN6                         _UINT32_(1) 
#define PINMUX_PA08B_ADC_AIN6                      ((PIN_PA08B_ADC_AIN6 << 16) | MUX_PA08B_ADC_AIN6)
#define PORT_PA08B_ADC_AIN6                        (_UINT32_(1) << 8)

#define PIN_PA09B_ADC_AIN7                         _UINT32_(9) 
#define MUX_PA09B_ADC_AIN7                         _UINT32_(1) 
#define PINMUX_PA09B_ADC_AIN7                      ((PIN_PA09B_ADC_AIN7 << 16) | MUX_PA09B_ADC_AIN7)
#define PORT_PA09B_ADC_AIN7                        (_UINT32_(1) << 9)

#define PIN_PA10B_ADC_AIN8                         _UINT32_(10)
#define MUX_PA10B_ADC_AIN8                         _UINT32_(1) 
#define PINMUX_PA10B_ADC_AIN8                      ((PIN_PA10B_ADC_AIN8 << 16) | MUX_PA10B_ADC_AIN8)
#define PORT_PA10B_ADC_AIN8                        (_UINT32_(1) << 10)

#define PIN_PA11B_ADC_AIN9                         _UINT32_(11)
#define MUX_PA11B_ADC_AIN9                         _UINT32_(1) 
#define PINMUX_PA11B_ADC_AIN9                      ((PIN_PA11B_ADC_AIN9 << 16) | MUX_PA11B_ADC_AIN9)
#define PORT_PA11B_ADC_AIN9                        (_UINT32_(1) << 11)

#define PIN_PB02B_ADC_AIN10                        _UINT32_(34)
#define MUX_PB02B_ADC_AIN10                        _UINT32_(1) 
#define PINMUX_PB02B_ADC_AIN10                     ((PIN_PB02B_ADC_AIN10 << 16) | MUX_PB02B_ADC_AIN10)
#define PORT_PB02B_ADC_AIN10                       (_UINT32_(1) << 2)

#define PIN_PB03B_ADC_AIN11                        _UINT32_(35)
#define MUX_PB03B_ADC_AIN11                        _UINT32_(1) 
#define PINMUX_PB03B_ADC_AIN11                     ((PIN_PB03B_ADC_AIN11 << 16) | MUX_PB03B_ADC_AIN11)
#define PORT_PB03B_ADC_AIN11                       (_UINT32_(1) << 3)

#define PIN_PB08B_ADC_AIN18                        _UINT32_(40)
#define MUX_PB08B_ADC_AIN18                        _UINT32_(1) 
#define PINMUX_PB08B_ADC_AIN18                     ((PIN_PB08B_ADC_AIN18 << 16) | MUX_PB08B_ADC_AIN18)
#define PORT_PB08B_ADC_AIN18                       (_UINT32_(1) << 8)

#define PIN_PB09B_ADC_AIN19                        _UINT32_(41)
#define MUX_PB09B_ADC_AIN19                        _UINT32_(1) 
#define PINMUX_PB09B_ADC_AIN19                     ((PIN_PB09B_ADC_AIN19 << 16) | MUX_PB09B_ADC_AIN19)
#define PORT_PB09B_ADC_AIN19                       (_UINT32_(1) << 9)

#define PIN_PA04B_ADC_VREFP                        _UINT32_(4) 
#define MUX_PA04B_ADC_VREFP                        _UINT32_(1) 
#define PINMUX_PA04B_ADC_VREFP                     ((PIN_PA04B_ADC_VREFP << 16) | MUX_PA04B_ADC_VREFP)
#define PORT_PA04B_ADC_VREFP                       (_UINT32_(1) << 4)

/* ========== PORT definition for CCL peripheral ========== */
#define PIN_PA04I_CCL_IN0                          _UINT32_(4) 
#define MUX_PA04I_CCL_IN0                          _UINT32_(8) 
#define PINMUX_PA04I_CCL_IN0                       ((PIN_PA04I_CCL_IN0 << 16) | MUX_PA04I_CCL_IN0)
#define PORT_PA04I_CCL_IN0                         (_UINT32_(1) << 4)

#define PIN_PA16I_CCL_IN0                          _UINT32_(16)
#define MUX_PA16I_CCL_IN0                          _UINT32_(8) 
#define PINMUX_PA16I_CCL_IN0                       ((PIN_PA16I_CCL_IN0 << 16) | MUX_PA16I_CCL_IN0)
#define PORT_PA16I_CCL_IN0                         (_UINT32_(1) << 16)

#define PIN_PB22I_CCL_IN0                          _UINT32_(54)
#define MUX_PB22I_CCL_IN0                          _UINT32_(8) 
#define PINMUX_PB22I_CCL_IN0                       ((PIN_PB22I_CCL_IN0 << 16) | MUX_PB22I_CCL_IN0)
#define PORT_PB22I_CCL_IN0                         (_UINT32_(1) << 22)

#define PIN_PA05I_CCL_IN1                          _UINT32_(5) 
#define MUX_PA05I_CCL_IN1                          _UINT32_(8) 
#define PINMUX_PA05I_CCL_IN1                       ((PIN_PA05I_CCL_IN1 << 16) | MUX_PA05I_CCL_IN1)
#define PORT_PA05I_CCL_IN1                         (_UINT32_(1) << 5)

#define PIN_PA17I_CCL_IN1                          _UINT32_(17)
#define MUX_PA17I_CCL_IN1                          _UINT32_(8) 
#define PINMUX_PA17I_CCL_IN1                       ((PIN_PA17I_CCL_IN1 << 16) | MUX_PA17I_CCL_IN1)
#define PORT_PA17I_CCL_IN1                         (_UINT32_(1) << 17)

#define PIN_PA06I_CCL_IN2                          _UINT32_(6) 
#define MUX_PA06I_CCL_IN2                          _UINT32_(8) 
#define PINMUX_PA06I_CCL_IN2                       ((PIN_PA06I_CCL_IN2 << 16) | MUX_PA06I_CCL_IN2)
#define PORT_PA06I_CCL_IN2                         (_UINT32_(1) << 6)

#define PIN_PA18I_CCL_IN2                          _UINT32_(18)
#define MUX_PA18I_CCL_IN2                          _UINT32_(8) 
#define PINMUX_PA18I_CCL_IN2                       ((PIN_PA18I_CCL_IN2 << 16) | MUX_PA18I_CCL_IN2)
#define PORT_PA18I_CCL_IN2                         (_UINT32_(1) << 18)

#define PIN_PA08I_CCL_IN3                          _UINT32_(8) 
#define MUX_PA08I_CCL_IN3                          _UINT32_(8) 
#define PINMUX_PA08I_CCL_IN3                       ((PIN_PA08I_CCL_IN3 << 16) | MUX_PA08I_CCL_IN3)
#define PORT_PA08I_CCL_IN3                         (_UINT32_(1) << 8)

#define PIN_PA30I_CCL_IN3                          _UINT32_(30)
#define MUX_PA30I_CCL_IN3                          _UINT32_(8) 
#define PINMUX_PA30I_CCL_IN3                       ((PIN_PA30I_CCL_IN3 << 16) | MUX_PA30I_CCL_IN3)
#define PORT_PA30I_CCL_IN3                         (_UINT32_(1) << 30)

#define PIN_PA09I_CCL_IN4                          _UINT32_(9) 
#define MUX_PA09I_CCL_IN4                          _UINT32_(8) 
#define PINMUX_PA09I_CCL_IN4                       ((PIN_PA09I_CCL_IN4 << 16) | MUX_PA09I_CCL_IN4)
#define PORT_PA09I_CCL_IN4                         (_UINT32_(1) << 9)

#define PIN_PA10I_CCL_IN5                          _UINT32_(10)
#define MUX_PA10I_CCL_IN5                          _UINT32_(8) 
#define PINMUX_PA10I_CCL_IN5                       ((PIN_PA10I_CCL_IN5 << 16) | MUX_PA10I_CCL_IN5)
#define PORT_PA10I_CCL_IN5                         (_UINT32_(1) << 10)

#define PIN_PA20I_CCL_IN5                          _UINT32_(20)
#define MUX_PA20I_CCL_IN5                          _UINT32_(8) 
#define PINMUX_PA20I_CCL_IN5                       ((PIN_PA20I_CCL_IN5 << 16) | MUX_PA20I_CCL_IN5)
#define PORT_PA20I_CCL_IN5                         (_UINT32_(1) << 20)

#define PIN_PA22I_CCL_IN6                          _UINT32_(22)
#define MUX_PA22I_CCL_IN6                          _UINT32_(8) 
#define PINMUX_PA22I_CCL_IN6                       ((PIN_PA22I_CCL_IN6 << 16) | MUX_PA22I_CCL_IN6)
#define PORT_PA22I_CCL_IN6                         (_UINT32_(1) << 22)

#define PIN_PA23I_CCL_IN7                          _UINT32_(23)
#define MUX_PA23I_CCL_IN7                          _UINT32_(8) 
#define PINMUX_PA23I_CCL_IN7                       ((PIN_PA23I_CCL_IN7 << 16) | MUX_PA23I_CCL_IN7)
#define PORT_PA23I_CCL_IN7                         (_UINT32_(1) << 23)

#define PIN_PA24I_CCL_IN8                          _UINT32_(24)
#define MUX_PA24I_CCL_IN8                          _UINT32_(8) 
#define PINMUX_PA24I_CCL_IN8                       ((PIN_PA24I_CCL_IN8 << 16) | MUX_PA24I_CCL_IN8)
#define PORT_PA24I_CCL_IN8                         (_UINT32_(1) << 24)

#define PIN_PB08I_CCL_IN8                          _UINT32_(40)
#define MUX_PB08I_CCL_IN8                          _UINT32_(8) 
#define PINMUX_PB08I_CCL_IN8                       ((PIN_PB08I_CCL_IN8 << 16) | MUX_PB08I_CCL_IN8)
#define PORT_PB08I_CCL_IN8                         (_UINT32_(1) << 8)

#define PIN_PA07I_CCL_OUT0                         _UINT32_(7) 
#define MUX_PA07I_CCL_OUT0                         _UINT32_(8) 
#define PINMUX_PA07I_CCL_OUT0                      ((PIN_PA07I_CCL_OUT0 << 16) | MUX_PA07I_CCL_OUT0)
#define PORT_PA07I_CCL_OUT0                        (_UINT32_(1) << 7)

#define PIN_PA19I_CCL_OUT0                         _UINT32_(19)
#define MUX_PA19I_CCL_OUT0                         _UINT32_(8) 
#define PINMUX_PA19I_CCL_OUT0                      ((PIN_PA19I_CCL_OUT0 << 16) | MUX_PA19I_CCL_OUT0)
#define PORT_PA19I_CCL_OUT0                        (_UINT32_(1) << 19)

#define PIN_PB02I_CCL_OUT0                         _UINT32_(34)
#define MUX_PB02I_CCL_OUT0                         _UINT32_(8) 
#define PINMUX_PB02I_CCL_OUT0                      ((PIN_PB02I_CCL_OUT0 << 16) | MUX_PB02I_CCL_OUT0)
#define PORT_PB02I_CCL_OUT0                        (_UINT32_(1) << 2)

#define PIN_PB23I_CCL_OUT0                         _UINT32_(55)
#define MUX_PB23I_CCL_OUT0                         _UINT32_(8) 
#define PINMUX_PB23I_CCL_OUT0                      ((PIN_PB23I_CCL_OUT0 << 16) | MUX_PB23I_CCL_OUT0)
#define PORT_PB23I_CCL_OUT0                        (_UINT32_(1) << 23)

#define PIN_PA11I_CCL_OUT1                         _UINT32_(11)
#define MUX_PA11I_CCL_OUT1                         _UINT32_(8) 
#define PINMUX_PA11I_CCL_OUT1                      ((PIN_PA11I_CCL_OUT1 << 16) | MUX_PA11I_CCL_OUT1)
#define PORT_PA11I_CCL_OUT1                        (_UINT32_(1) << 11)

#define PIN_PA31I_CCL_OUT1                         _UINT32_(31)
#define MUX_PA31I_CCL_OUT1                         _UINT32_(8) 
#define PINMUX_PA31I_CCL_OUT1                      ((PIN_PA31I_CCL_OUT1 << 16) | MUX_PA31I_CCL_OUT1)
#define PORT_PA31I_CCL_OUT1                        (_UINT32_(1) << 31)

#define PIN_PA25I_CCL_OUT2                         _UINT32_(25)
#define MUX_PA25I_CCL_OUT2                         _UINT32_(8) 
#define PINMUX_PA25I_CCL_OUT2                      ((PIN_PA25I_CCL_OUT2 << 16) | MUX_PA25I_CCL_OUT2)
#define PORT_PA25I_CCL_OUT2                        (_UINT32_(1) << 25)

#define PIN_PB09I_CCL_OUT2                         _UINT32_(41)
#define MUX_PB09I_CCL_OUT2                         _UINT32_(8) 
#define PINMUX_PB09I_CCL_OUT2                      ((PIN_PB09I_CCL_OUT2 << 16) | MUX_PB09I_CCL_OUT2)
#define PORT_PB09I_CCL_OUT2                        (_UINT32_(1) << 9)

/* ========== PORT definition for DAC peripheral ========== */
#define PIN_PA02B_DAC_VOUT0                        _UINT32_(2) 
#define MUX_PA02B_DAC_VOUT0                        _UINT32_(1) 
#define PINMUX_PA02B_DAC_VOUT0                     ((PIN_PA02B_DAC_VOUT0 << 16) | MUX_PA02B_DAC_VOUT0)
#define PORT_PA02B_DAC_VOUT0                       (_UINT32_(1) << 2)

#define PIN_PA07B_DAC_VOUT1                        _UINT32_(7) 
#define MUX_PA07B_DAC_VOUT1                        _UINT32_(1) 
#define PINMUX_PA07B_DAC_VOUT1                     ((PIN_PA07B_DAC_VOUT1 << 16) | MUX_PA07B_DAC_VOUT1)
#define PORT_PA07B_DAC_VOUT1                       (_UINT32_(1) << 7)

#define PIN_PA03B_DAC_VREFP                        _UINT32_(3) 
#define MUX_PA03B_DAC_VREFP                        _UINT32_(1) 
#define PINMUX_PA03B_DAC_VREFP                     ((PIN_PA03B_DAC_VREFP << 16) | MUX_PA03B_DAC_VREFP)
#define PORT_PA03B_DAC_VREFP                       (_UINT32_(1) << 3)

/* ========== PORT definition for EIC peripheral ========== */
#define PIN_PA09A_EIC_EXTINT0                      _UINT32_(9) 
#define MUX_PA09A_EIC_EXTINT0                      _UINT32_(0) 
#define PINMUX_PA09A_EIC_EXTINT0                   ((PIN_PA09A_EIC_EXTINT0 << 16) | MUX_PA09A_EIC_EXTINT0)
#define PORT_PA09A_EIC_EXTINT0                     (_UINT32_(1) << 9)
#define PIN_PA09A_EIC_EXTINT_NUM                   _UINT32_(0)  /* EIC signal: PIN_PA09 External Interrupt Line */

#define PIN_PA19A_EIC_EXTINT0                      _UINT32_(19)
#define MUX_PA19A_EIC_EXTINT0                      _UINT32_(0) 
#define PINMUX_PA19A_EIC_EXTINT0                   ((PIN_PA19A_EIC_EXTINT0 << 16) | MUX_PA19A_EIC_EXTINT0)
#define PORT_PA19A_EIC_EXTINT0                     (_UINT32_(1) << 19)
#define PIN_PA19A_EIC_EXTINT_NUM                   _UINT32_(0)  /* EIC signal: PIN_PA19 External Interrupt Line */

#define PIN_PA00A_EIC_EXTINT0                      _UINT32_(0) 
#define MUX_PA00A_EIC_EXTINT0                      _UINT32_(0) 
#define PINMUX_PA00A_EIC_EXTINT0                   ((PIN_PA00A_EIC_EXTINT0 << 16) | MUX_PA00A_EIC_EXTINT0)
#define PORT_PA00A_EIC_EXTINT0                     (_UINT32_(1) << 0)
#define PIN_PA00A_EIC_EXTINT_NUM                   _UINT32_(0)  /* EIC signal: PIN_PA00 External Interrupt Line */

#define PIN_PA10A_EIC_EXTINT1                      _UINT32_(10)
#define MUX_PA10A_EIC_EXTINT1                      _UINT32_(0) 
#define PINMUX_PA10A_EIC_EXTINT1                   ((PIN_PA10A_EIC_EXTINT1 << 16) | MUX_PA10A_EIC_EXTINT1)
#define PORT_PA10A_EIC_EXTINT1                     (_UINT32_(1) << 10)
#define PIN_PA10A_EIC_EXTINT_NUM                   _UINT32_(1)  /* EIC signal: PIN_PA10 External Interrupt Line */

#define PIN_PA22A_EIC_EXTINT1                      _UINT32_(22)
#define MUX_PA22A_EIC_EXTINT1                      _UINT32_(0) 
#define PINMUX_PA22A_EIC_EXTINT1                   ((PIN_PA22A_EIC_EXTINT1 << 16) | MUX_PA22A_EIC_EXTINT1)
#define PORT_PA22A_EIC_EXTINT1                     (_UINT32_(1) << 22)
#define PIN_PA22A_EIC_EXTINT_NUM                   _UINT32_(1)  /* EIC signal: PIN_PA22 External Interrupt Line */

#define PIN_PA01A_EIC_EXTINT1                      _UINT32_(1) 
#define MUX_PA01A_EIC_EXTINT1                      _UINT32_(0) 
#define PINMUX_PA01A_EIC_EXTINT1                   ((PIN_PA01A_EIC_EXTINT1 << 16) | MUX_PA01A_EIC_EXTINT1)
#define PORT_PA01A_EIC_EXTINT1                     (_UINT32_(1) << 1)
#define PIN_PA01A_EIC_EXTINT_NUM                   _UINT32_(1)  /* EIC signal: PIN_PA01 External Interrupt Line */

#define PIN_PA02A_EIC_EXTINT2                      _UINT32_(2) 
#define MUX_PA02A_EIC_EXTINT2                      _UINT32_(0) 
#define PINMUX_PA02A_EIC_EXTINT2                   ((PIN_PA02A_EIC_EXTINT2 << 16) | MUX_PA02A_EIC_EXTINT2)
#define PORT_PA02A_EIC_EXTINT2                     (_UINT32_(1) << 2)
#define PIN_PA02A_EIC_EXTINT_NUM                   _UINT32_(2)  /* EIC signal: PIN_PA02 External Interrupt Line */

#define PIN_PA11A_EIC_EXTINT2                      _UINT32_(11)
#define MUX_PA11A_EIC_EXTINT2                      _UINT32_(0) 
#define PINMUX_PA11A_EIC_EXTINT2                   ((PIN_PA11A_EIC_EXTINT2 << 16) | MUX_PA11A_EIC_EXTINT2)
#define PORT_PA11A_EIC_EXTINT2                     (_UINT32_(1) << 11)
#define PIN_PA11A_EIC_EXTINT_NUM                   _UINT32_(2)  /* EIC signal: PIN_PA11 External Interrupt Line */

#define PIN_PA23A_EIC_EXTINT2                      _UINT32_(23)
#define MUX_PA23A_EIC_EXTINT2                      _UINT32_(0) 
#define PINMUX_PA23A_EIC_EXTINT2                   ((PIN_PA23A_EIC_EXTINT2 << 16) | MUX_PA23A_EIC_EXTINT2)
#define PORT_PA23A_EIC_EXTINT2                     (_UINT32_(1) << 23)
#define PIN_PA23A_EIC_EXTINT_NUM                   _UINT32_(2)  /* EIC signal: PIN_PA23 External Interrupt Line */

#define PIN_PB02A_EIC_EXTINT2                      _UINT32_(34)
#define MUX_PB02A_EIC_EXTINT2                      _UINT32_(0) 
#define PINMUX_PB02A_EIC_EXTINT2                   ((PIN_PB02A_EIC_EXTINT2 << 16) | MUX_PB02A_EIC_EXTINT2)
#define PORT_PB02A_EIC_EXTINT2                     (_UINT32_(1) << 2)
#define PIN_PB02A_EIC_EXTINT_NUM                   _UINT32_(2)  /* EIC signal: PIN_PB02 External Interrupt Line */

#define PIN_PA03A_EIC_EXTINT3                      _UINT32_(3) 
#define MUX_PA03A_EIC_EXTINT3                      _UINT32_(0) 
#define PINMUX_PA03A_EIC_EXTINT3                   ((PIN_PA03A_EIC_EXTINT3 << 16) | MUX_PA03A_EIC_EXTINT3)
#define PORT_PA03A_EIC_EXTINT3                     (_UINT32_(1) << 3)
#define PIN_PA03A_EIC_EXTINT_NUM                   _UINT32_(3)  /* EIC signal: PIN_PA03 External Interrupt Line */

#define PIN_PA14A_EIC_EXTINT3                      _UINT32_(14)
#define MUX_PA14A_EIC_EXTINT3                      _UINT32_(0) 
#define PINMUX_PA14A_EIC_EXTINT3                   ((PIN_PA14A_EIC_EXTINT3 << 16) | MUX_PA14A_EIC_EXTINT3)
#define PORT_PA14A_EIC_EXTINT3                     (_UINT32_(1) << 14)
#define PIN_PA14A_EIC_EXTINT_NUM                   _UINT32_(3)  /* EIC signal: PIN_PA14 External Interrupt Line */

#define PIN_PA24A_EIC_EXTINT3                      _UINT32_(24)
#define MUX_PA24A_EIC_EXTINT3                      _UINT32_(0) 
#define PINMUX_PA24A_EIC_EXTINT3                   ((PIN_PA24A_EIC_EXTINT3 << 16) | MUX_PA24A_EIC_EXTINT3)
#define PORT_PA24A_EIC_EXTINT3                     (_UINT32_(1) << 24)
#define PIN_PA24A_EIC_EXTINT_NUM                   _UINT32_(3)  /* EIC signal: PIN_PA24 External Interrupt Line */

#define PIN_PB03A_EIC_EXTINT3                      _UINT32_(35)
#define MUX_PB03A_EIC_EXTINT3                      _UINT32_(0) 
#define PINMUX_PB03A_EIC_EXTINT3                   ((PIN_PB03A_EIC_EXTINT3 << 16) | MUX_PB03A_EIC_EXTINT3)
#define PORT_PB03A_EIC_EXTINT3                     (_UINT32_(1) << 3)
#define PIN_PB03A_EIC_EXTINT_NUM                   _UINT32_(3)  /* EIC signal: PIN_PB03 External Interrupt Line */

#define PIN_PA04A_EIC_EXTINT4                      _UINT32_(4) 
#define MUX_PA04A_EIC_EXTINT4                      _UINT32_(0) 
#define PINMUX_PA04A_EIC_EXTINT4                   ((PIN_PA04A_EIC_EXTINT4 << 16) | MUX_PA04A_EIC_EXTINT4)
#define PORT_PA04A_EIC_EXTINT4                     (_UINT32_(1) << 4)
#define PIN_PA04A_EIC_EXTINT_NUM                   _UINT32_(4)  /* EIC signal: PIN_PA04 External Interrupt Line */

#define PIN_PA15A_EIC_EXTINT4                      _UINT32_(15)
#define MUX_PA15A_EIC_EXTINT4                      _UINT32_(0) 
#define PINMUX_PA15A_EIC_EXTINT4                   ((PIN_PA15A_EIC_EXTINT4 << 16) | MUX_PA15A_EIC_EXTINT4)
#define PORT_PA15A_EIC_EXTINT4                     (_UINT32_(1) << 15)
#define PIN_PA15A_EIC_EXTINT_NUM                   _UINT32_(4)  /* EIC signal: PIN_PA15 External Interrupt Line */

#define PIN_PA20A_EIC_EXTINT4                      _UINT32_(20)
#define MUX_PA20A_EIC_EXTINT4                      _UINT32_(0) 
#define PINMUX_PA20A_EIC_EXTINT4                   ((PIN_PA20A_EIC_EXTINT4 << 16) | MUX_PA20A_EIC_EXTINT4)
#define PORT_PA20A_EIC_EXTINT4                     (_UINT32_(1) << 20)
#define PIN_PA20A_EIC_EXTINT_NUM                   _UINT32_(4)  /* EIC signal: PIN_PA20 External Interrupt Line */

#define PIN_PA25A_EIC_EXTINT4                      _UINT32_(25)
#define MUX_PA25A_EIC_EXTINT4                      _UINT32_(0) 
#define PINMUX_PA25A_EIC_EXTINT4                   ((PIN_PA25A_EIC_EXTINT4 << 16) | MUX_PA25A_EIC_EXTINT4)
#define PORT_PA25A_EIC_EXTINT4                     (_UINT32_(1) << 25)
#define PIN_PA25A_EIC_EXTINT_NUM                   _UINT32_(4)  /* EIC signal: PIN_PA25 External Interrupt Line */

#define PIN_PA05A_EIC_EXTINT5                      _UINT32_(5) 
#define MUX_PA05A_EIC_EXTINT5                      _UINT32_(0) 
#define PINMUX_PA05A_EIC_EXTINT5                   ((PIN_PA05A_EIC_EXTINT5 << 16) | MUX_PA05A_EIC_EXTINT5)
#define PORT_PA05A_EIC_EXTINT5                     (_UINT32_(1) << 5)
#define PIN_PA05A_EIC_EXTINT_NUM                   _UINT32_(5)  /* EIC signal: PIN_PA05 External Interrupt Line */

#define PIN_PA16A_EIC_EXTINT5                      _UINT32_(16)
#define MUX_PA16A_EIC_EXTINT5                      _UINT32_(0) 
#define PINMUX_PA16A_EIC_EXTINT5                   ((PIN_PA16A_EIC_EXTINT5 << 16) | MUX_PA16A_EIC_EXTINT5)
#define PORT_PA16A_EIC_EXTINT5                     (_UINT32_(1) << 16)
#define PIN_PA16A_EIC_EXTINT_NUM                   _UINT32_(5)  /* EIC signal: PIN_PA16 External Interrupt Line */

#define PIN_PA21A_EIC_EXTINT5                      _UINT32_(21)
#define MUX_PA21A_EIC_EXTINT5                      _UINT32_(0) 
#define PINMUX_PA21A_EIC_EXTINT5                   ((PIN_PA21A_EIC_EXTINT5 << 16) | MUX_PA21A_EIC_EXTINT5)
#define PORT_PA21A_EIC_EXTINT5                     (_UINT32_(1) << 21)
#define PIN_PA21A_EIC_EXTINT_NUM                   _UINT32_(5)  /* EIC signal: PIN_PA21 External Interrupt Line */

#define PIN_PA06A_EIC_EXTINT6                      _UINT32_(6) 
#define MUX_PA06A_EIC_EXTINT6                      _UINT32_(0) 
#define PINMUX_PA06A_EIC_EXTINT6                   ((PIN_PA06A_EIC_EXTINT6 << 16) | MUX_PA06A_EIC_EXTINT6)
#define PORT_PA06A_EIC_EXTINT6                     (_UINT32_(1) << 6)
#define PIN_PA06A_EIC_EXTINT_NUM                   _UINT32_(6)  /* EIC signal: PIN_PA06 External Interrupt Line */

#define PIN_PA17A_EIC_EXTINT6                      _UINT32_(17)
#define MUX_PA17A_EIC_EXTINT6                      _UINT32_(0) 
#define PINMUX_PA17A_EIC_EXTINT6                   ((PIN_PA17A_EIC_EXTINT6 << 16) | MUX_PA17A_EIC_EXTINT6)
#define PORT_PA17A_EIC_EXTINT6                     (_UINT32_(1) << 17)
#define PIN_PA17A_EIC_EXTINT_NUM                   _UINT32_(6)  /* EIC signal: PIN_PA17 External Interrupt Line */

#define PIN_PA30A_EIC_EXTINT6                      _UINT32_(30)
#define MUX_PA30A_EIC_EXTINT6                      _UINT32_(0) 
#define PINMUX_PA30A_EIC_EXTINT6                   ((PIN_PA30A_EIC_EXTINT6 << 16) | MUX_PA30A_EIC_EXTINT6)
#define PORT_PA30A_EIC_EXTINT6                     (_UINT32_(1) << 30)
#define PIN_PA30A_EIC_EXTINT_NUM                   _UINT32_(6)  /* EIC signal: PIN_PA30 External Interrupt Line */

#define PIN_PB22A_EIC_EXTINT6                      _UINT32_(54)
#define MUX_PB22A_EIC_EXTINT6                      _UINT32_(0) 
#define PINMUX_PB22A_EIC_EXTINT6                   ((PIN_PB22A_EIC_EXTINT6 << 16) | MUX_PB22A_EIC_EXTINT6)
#define PORT_PB22A_EIC_EXTINT6                     (_UINT32_(1) << 22)
#define PIN_PB22A_EIC_EXTINT_NUM                   _UINT32_(6)  /* EIC signal: PIN_PB22 External Interrupt Line */

#define PIN_PA07A_EIC_EXTINT7                      _UINT32_(7) 
#define MUX_PA07A_EIC_EXTINT7                      _UINT32_(0) 
#define PINMUX_PA07A_EIC_EXTINT7                   ((PIN_PA07A_EIC_EXTINT7 << 16) | MUX_PA07A_EIC_EXTINT7)
#define PORT_PA07A_EIC_EXTINT7                     (_UINT32_(1) << 7)
#define PIN_PA07A_EIC_EXTINT_NUM                   _UINT32_(7)  /* EIC signal: PIN_PA07 External Interrupt Line */

#define PIN_PA18A_EIC_EXTINT7                      _UINT32_(18)
#define MUX_PA18A_EIC_EXTINT7                      _UINT32_(0) 
#define PINMUX_PA18A_EIC_EXTINT7                   ((PIN_PA18A_EIC_EXTINT7 << 16) | MUX_PA18A_EIC_EXTINT7)
#define PORT_PA18A_EIC_EXTINT7                     (_UINT32_(1) << 18)
#define PIN_PA18A_EIC_EXTINT_NUM                   _UINT32_(7)  /* EIC signal: PIN_PA18 External Interrupt Line */

#define PIN_PA31A_EIC_EXTINT7                      _UINT32_(31)
#define MUX_PA31A_EIC_EXTINT7                      _UINT32_(0) 
#define PINMUX_PA31A_EIC_EXTINT7                   ((PIN_PA31A_EIC_EXTINT7 << 16) | MUX_PA31A_EIC_EXTINT7)
#define PORT_PA31A_EIC_EXTINT7                     (_UINT32_(1) << 31)
#define PIN_PA31A_EIC_EXTINT_NUM                   _UINT32_(7)  /* EIC signal: PIN_PA31 External Interrupt Line */

#define PIN_PB23A_EIC_EXTINT7                      _UINT32_(55)
#define MUX_PB23A_EIC_EXTINT7                      _UINT32_(0) 
#define PINMUX_PB23A_EIC_EXTINT7                   ((PIN_PB23A_EIC_EXTINT7 << 16) | MUX_PB23A_EIC_EXTINT7)
#define PORT_PB23A_EIC_EXTINT7                     (_UINT32_(1) << 23)
#define PIN_PB23A_EIC_EXTINT_NUM                   _UINT32_(7)  /* EIC signal: PIN_PB23 External Interrupt Line */

#define PIN_PB08A_EIC_EXTINT8                      _UINT32_(40)
#define MUX_PB08A_EIC_EXTINT8                      _UINT32_(0) 
#define PINMUX_PB08A_EIC_EXTINT8                   ((PIN_PB08A_EIC_EXTINT8 << 16) | MUX_PB08A_EIC_EXTINT8)
#define PORT_PB08A_EIC_EXTINT8                     (_UINT32_(1) << 8)
#define PIN_PB08A_EIC_EXTINT_NUM                   _UINT32_(8)  /* EIC signal: PIN_PB08 External Interrupt Line */

#define PIN_PB09A_EIC_EXTINT9                      _UINT32_(41)
#define MUX_PB09A_EIC_EXTINT9                      _UINT32_(0) 
#define PINMUX_PB09A_EIC_EXTINT9                   ((PIN_PB09A_EIC_EXTINT9 << 16) | MUX_PB09A_EIC_EXTINT9)
#define PORT_PB09A_EIC_EXTINT9                     (_UINT32_(1) << 9)
#define PIN_PB09A_EIC_EXTINT_NUM                   _UINT32_(9)  /* EIC signal: PIN_PB09 External Interrupt Line */

#define PIN_PA12A_EIC_EXTINT12                     _UINT32_(12)
#define MUX_PA12A_EIC_EXTINT12                     _UINT32_(0) 
#define PINMUX_PA12A_EIC_EXTINT12                  ((PIN_PA12A_EIC_EXTINT12 << 16) | MUX_PA12A_EIC_EXTINT12)
#define PORT_PA12A_EIC_EXTINT12                    (_UINT32_(1) << 12)
#define PIN_PA12A_EIC_EXTINT_NUM                   _UINT32_(12) /* EIC signal: PIN_PA12 External Interrupt Line */

#define PIN_PA13A_EIC_EXTINT13                     _UINT32_(13)
#define MUX_PA13A_EIC_EXTINT13                     _UINT32_(0) 
#define PINMUX_PA13A_EIC_EXTINT13                  ((PIN_PA13A_EIC_EXTINT13 << 16) | MUX_PA13A_EIC_EXTINT13)
#define PORT_PA13A_EIC_EXTINT13                    (_UINT32_(1) << 13)
#define PIN_PA13A_EIC_EXTINT_NUM                   _UINT32_(13) /* EIC signal: PIN_PA13 External Interrupt Line */

#define PIN_PA08A_EIC_NMI                          _UINT32_(8) 
#define MUX_PA08A_EIC_NMI                          _UINT32_(0) 
#define PINMUX_PA08A_EIC_NMI                       ((PIN_PA08A_EIC_NMI << 16) | MUX_PA08A_EIC_NMI)
#define PORT_PA08A_EIC_NMI                         (_UINT32_(1) << 8)

/* ========== PORT definition for GCLK peripheral ========== */
#define PIN_PA30H_GCLK_IO0                         _UINT32_(30)
#define MUX_PA30H_GCLK_IO0                         _UINT32_(7) 
#define PINMUX_PA30H_GCLK_IO0                      ((PIN_PA30H_GCLK_IO0 << 16) | MUX_PA30H_GCLK_IO0)
#define PORT_PA30H_GCLK_IO0                        (_UINT32_(1) << 30)

#define PIN_PB22H_GCLK_IO0                         _UINT32_(54)
#define MUX_PB22H_GCLK_IO0                         _UINT32_(7) 
#define PINMUX_PB22H_GCLK_IO0                      ((PIN_PB22H_GCLK_IO0 << 16) | MUX_PB22H_GCLK_IO0)
#define PORT_PB22H_GCLK_IO0                        (_UINT32_(1) << 22)

#define PIN_PA14H_GCLK_IO0                         _UINT32_(14)
#define MUX_PA14H_GCLK_IO0                         _UINT32_(7) 
#define PINMUX_PA14H_GCLK_IO0                      ((PIN_PA14H_GCLK_IO0 << 16) | MUX_PA14H_GCLK_IO0)
#define PORT_PA14H_GCLK_IO0                        (_UINT32_(1) << 14)

#define PIN_PA23H_GCLK_IO1                         _UINT32_(23)
#define MUX_PA23H_GCLK_IO1                         _UINT32_(7) 
#define PINMUX_PA23H_GCLK_IO1                      ((PIN_PA23H_GCLK_IO1 << 16) | MUX_PA23H_GCLK_IO1)
#define PORT_PA23H_GCLK_IO1                        (_UINT32_(1) << 23)

#define PIN_PB23H_GCLK_IO1                         _UINT32_(55)
#define MUX_PB23H_GCLK_IO1                         _UINT32_(7) 
#define PINMUX_PB23H_GCLK_IO1                      ((PIN_PB23H_GCLK_IO1 << 16) | MUX_PB23H_GCLK_IO1)
#define PORT_PB23H_GCLK_IO1                        (_UINT32_(1) << 23)

#define PIN_PA15H_GCLK_IO1                         _UINT32_(15)
#define MUX_PA15H_GCLK_IO1                         _UINT32_(7) 
#define PINMUX_PA15H_GCLK_IO1                      ((PIN_PA15H_GCLK_IO1 << 16) | MUX_PA15H_GCLK_IO1)
#define PORT_PA15H_GCLK_IO1                        (_UINT32_(1) << 15)

#define PIN_PA16H_GCLK_IO2                         _UINT32_(16)
#define MUX_PA16H_GCLK_IO2                         _UINT32_(7) 
#define PINMUX_PA16H_GCLK_IO2                      ((PIN_PA16H_GCLK_IO2 << 16) | MUX_PA16H_GCLK_IO2)
#define PORT_PA16H_GCLK_IO2                        (_UINT32_(1) << 16)

#define PIN_PA22H_GCLK_IO2                         _UINT32_(22)
#define MUX_PA22H_GCLK_IO2                         _UINT32_(7) 
#define PINMUX_PA22H_GCLK_IO2                      ((PIN_PA22H_GCLK_IO2 << 16) | MUX_PA22H_GCLK_IO2)
#define PORT_PA22H_GCLK_IO2                        (_UINT32_(1) << 22)

#define PIN_PA11H_GCLK_IO3                         _UINT32_(11)
#define MUX_PA11H_GCLK_IO3                         _UINT32_(7) 
#define PINMUX_PA11H_GCLK_IO3                      ((PIN_PA11H_GCLK_IO3 << 16) | MUX_PA11H_GCLK_IO3)
#define PORT_PA11H_GCLK_IO3                        (_UINT32_(1) << 11)

#define PIN_PA17H_GCLK_IO3                         _UINT32_(17)
#define MUX_PA17H_GCLK_IO3                         _UINT32_(7) 
#define PINMUX_PA17H_GCLK_IO3                      ((PIN_PA17H_GCLK_IO3 << 16) | MUX_PA17H_GCLK_IO3)
#define PORT_PA17H_GCLK_IO3                        (_UINT32_(1) << 17)

#define PIN_PA10H_GCLK_IO4                         _UINT32_(10)
#define MUX_PA10H_GCLK_IO4                         _UINT32_(7) 
#define PINMUX_PA10H_GCLK_IO4                      ((PIN_PA10H_GCLK_IO4 << 16) | MUX_PA10H_GCLK_IO4)
#define PORT_PA10H_GCLK_IO4                        (_UINT32_(1) << 10)

#define PIN_PA20H_GCLK_IO4                         _UINT32_(20)
#define MUX_PA20H_GCLK_IO4                         _UINT32_(7) 
#define PINMUX_PA20H_GCLK_IO4                      ((PIN_PA20H_GCLK_IO4 << 16) | MUX_PA20H_GCLK_IO4)
#define PORT_PA20H_GCLK_IO4                        (_UINT32_(1) << 20)

#define PIN_PA21H_GCLK_IO5                         _UINT32_(21)
#define MUX_PA21H_GCLK_IO5                         _UINT32_(7) 
#define PINMUX_PA21H_GCLK_IO5                      ((PIN_PA21H_GCLK_IO5 << 16) | MUX_PA21H_GCLK_IO5)
#define PORT_PA21H_GCLK_IO5                        (_UINT32_(1) << 21)

/* ========== PORT definition for I2S peripheral ========== */
#define PIN_PA11K_I2S_FS0                          _UINT32_(11)
#define MUX_PA11K_I2S_FS0                          _UINT32_(10)
#define PINMUX_PA11K_I2S_FS0                       ((PIN_PA11K_I2S_FS0 << 16) | MUX_PA11K_I2S_FS0)
#define PORT_PA11K_I2S_FS0                         (_UINT32_(1) << 11)

#define PIN_PA18K_I2S_FS0                          _UINT32_(18)
#define MUX_PA18K_I2S_FS0                          _UINT32_(10)
#define PINMUX_PA18K_I2S_FS0                       ((PIN_PA18K_I2S_FS0 << 16) | MUX_PA18K_I2S_FS0)
#define PORT_PA18K_I2S_FS0                         (_UINT32_(1) << 18)

#define PIN_PA09K_I2S_MCK0                         _UINT32_(9) 
#define MUX_PA09K_I2S_MCK0                         _UINT32_(10)
#define PINMUX_PA09K_I2S_MCK0                      ((PIN_PA09K_I2S_MCK0 << 16) | MUX_PA09K_I2S_MCK0)
#define PORT_PA09K_I2S_MCK0                        (_UINT32_(1) << 9)

#define PIN_PA10K_I2S_SCK0                         _UINT32_(10)
#define MUX_PA10K_I2S_SCK0                         _UINT32_(10)
#define PINMUX_PA10K_I2S_SCK0                      ((PIN_PA10K_I2S_SCK0 << 16) | MUX_PA10K_I2S_SCK0)
#define PORT_PA10K_I2S_SCK0                        (_UINT32_(1) << 10)

#define PIN_PA20K_I2S_SCK0                         _UINT32_(20)
#define MUX_PA20K_I2S_SCK0                         _UINT32_(10)
#define PINMUX_PA20K_I2S_SCK0                      ((PIN_PA20K_I2S_SCK0 << 16) | MUX_PA20K_I2S_SCK0)
#define PORT_PA20K_I2S_SCK0                        (_UINT32_(1) << 20)

#define PIN_PA21K_I2S_SCK1                         _UINT32_(21)
#define MUX_PA21K_I2S_SCK1                         _UINT32_(10)
#define PINMUX_PA21K_I2S_SCK1                      ((PIN_PA21K_I2S_SCK1 << 16) | MUX_PA21K_I2S_SCK1)
#define PORT_PA21K_I2S_SCK1                        (_UINT32_(1) << 21)

#define PIN_PA08K_I2S_SDI                          _UINT32_(8) 
#define MUX_PA08K_I2S_SDI                          _UINT32_(10)
#define PINMUX_PA08K_I2S_SDI                       ((PIN_PA08K_I2S_SDI << 16) | MUX_PA08K_I2S_SDI)
#define PORT_PA08K_I2S_SDI                         (_UINT32_(1) << 8)

#define PIN_PA19K_I2S_SDO                          _UINT32_(19)
#define MUX_PA19K_I2S_SDO                          _UINT32_(10)
#define PINMUX_PA19K_I2S_SDO                       ((PIN_PA19K_I2S_SDO << 16) | MUX_PA19K_I2S_SDO)
#define PORT_PA19K_I2S_SDO                         (_UINT32_(1) << 19)

/* ========== PORT definition for OPAMP peripheral ========== */
#define PIN_PA02B_OPAMP_OANEG0                     _UINT32_(2) 
#define MUX_PA02B_OPAMP_OANEG0                     _UINT32_(1) 
#define PINMUX_PA02B_OPAMP_OANEG0                  ((PIN_PA02B_OPAMP_OANEG0 << 16) | MUX_PA02B_OPAMP_OANEG0)
#define PORT_PA02B_OPAMP_OANEG0                    (_UINT32_(1) << 2)

#define PIN_PA00B_OPAMP_OANEG1                     _UINT32_(0) 
#define MUX_PA00B_OPAMP_OANEG1                     _UINT32_(1) 
#define PINMUX_PA00B_OPAMP_OANEG1                  ((PIN_PA00B_OPAMP_OANEG1 << 16) | MUX_PA00B_OPAMP_OANEG1)
#define PORT_PA00B_OPAMP_OANEG1                    (_UINT32_(1) << 0)

#define PIN_PA03B_OPAMP_OANEG2                     _UINT32_(3) 
#define MUX_PA03B_OPAMP_OANEG2                     _UINT32_(1) 
#define PINMUX_PA03B_OPAMP_OANEG2                  ((PIN_PA03B_OPAMP_OANEG2 << 16) | MUX_PA03B_OPAMP_OANEG2)
#define PORT_PA03B_OPAMP_OANEG2                    (_UINT32_(1) << 3)

#define PIN_PA07B_OPAMP_OAOUT0                     _UINT32_(7) 
#define MUX_PA07B_OPAMP_OAOUT0                     _UINT32_(1) 
#define PINMUX_PA07B_OPAMP_OAOUT0                  ((PIN_PA07B_OPAMP_OAOUT0 << 16) | MUX_PA07B_OPAMP_OAOUT0)
#define PORT_PA07B_OPAMP_OAOUT0                    (_UINT32_(1) << 7)

#define PIN_PA04B_OPAMP_OAOUT2                     _UINT32_(4) 
#define MUX_PA04B_OPAMP_OAOUT2                     _UINT32_(1) 
#define PINMUX_PA04B_OPAMP_OAOUT2                  ((PIN_PA04B_OPAMP_OAOUT2 << 16) | MUX_PA04B_OPAMP_OAOUT2)
#define PORT_PA04B_OPAMP_OAOUT2                    (_UINT32_(1) << 4)

#define PIN_PA06B_OPAMP_OAPOS0                     _UINT32_(6) 
#define MUX_PA06B_OPAMP_OAPOS0                     _UINT32_(1) 
#define PINMUX_PA06B_OPAMP_OAPOS0                  ((PIN_PA06B_OPAMP_OAPOS0 << 16) | MUX_PA06B_OPAMP_OAPOS0)
#define PORT_PA06B_OPAMP_OAPOS0                    (_UINT32_(1) << 6)

#define PIN_PA01B_OPAMP_OAPOS1                     _UINT32_(1) 
#define MUX_PA01B_OPAMP_OAPOS1                     _UINT32_(1) 
#define PINMUX_PA01B_OPAMP_OAPOS1                  ((PIN_PA01B_OPAMP_OAPOS1 << 16) | MUX_PA01B_OPAMP_OAPOS1)
#define PORT_PA01B_OPAMP_OAPOS1                    (_UINT32_(1) << 1)

#define PIN_PA05B_OPAMP_OAPOS2                     _UINT32_(5) 
#define MUX_PA05B_OPAMP_OAPOS2                     _UINT32_(1) 
#define PINMUX_PA05B_OPAMP_OAPOS2                  ((PIN_PA05B_OPAMP_OAPOS2 << 16) | MUX_PA05B_OPAMP_OAPOS2)
#define PORT_PA05B_OPAMP_OAPOS2                    (_UINT32_(1) << 5)

/* ========== PORT definition for PTC peripheral ========== */
#define PIN_PA00F_PTC_DRV0                         _UINT32_(0) 
#define MUX_PA00F_PTC_DRV0                         _UINT32_(5) 
#define PINMUX_PA00F_PTC_DRV0                      ((PIN_PA00F_PTC_DRV0 << 16) | MUX_PA00F_PTC_DRV0)
#define PORT_PA00F_PTC_DRV0                        (_UINT32_(1) << 0)

#define PIN_PA01F_PTC_DRV1                         _UINT32_(1) 
#define MUX_PA01F_PTC_DRV1                         _UINT32_(5) 
#define PINMUX_PA01F_PTC_DRV1                      ((PIN_PA01F_PTC_DRV1 << 16) | MUX_PA01F_PTC_DRV1)
#define PORT_PA01F_PTC_DRV1                        (_UINT32_(1) << 1)

#define PIN_PA02F_PTC_DRV2                         _UINT32_(2) 
#define MUX_PA02F_PTC_DRV2                         _UINT32_(5) 
#define PINMUX_PA02F_PTC_DRV2                      ((PIN_PA02F_PTC_DRV2 << 16) | MUX_PA02F_PTC_DRV2)
#define PORT_PA02F_PTC_DRV2                        (_UINT32_(1) << 2)

#define PIN_PA03F_PTC_DRV3                         _UINT32_(3) 
#define MUX_PA03F_PTC_DRV3                         _UINT32_(5) 
#define PINMUX_PA03F_PTC_DRV3                      ((PIN_PA03F_PTC_DRV3 << 16) | MUX_PA03F_PTC_DRV3)
#define PORT_PA03F_PTC_DRV3                        (_UINT32_(1) << 3)

#define PIN_PA05F_PTC_DRV4                         _UINT32_(5) 
#define MUX_PA05F_PTC_DRV4                         _UINT32_(5) 
#define PINMUX_PA05F_PTC_DRV4                      ((PIN_PA05F_PTC_DRV4 << 16) | MUX_PA05F_PTC_DRV4)
#define PORT_PA05F_PTC_DRV4                        (_UINT32_(1) << 5)

#define PIN_PA06F_PTC_DRV5                         _UINT32_(6) 
#define MUX_PA06F_PTC_DRV5                         _UINT32_(5) 
#define PINMUX_PA06F_PTC_DRV5                      ((PIN_PA06F_PTC_DRV5 << 16) | MUX_PA06F_PTC_DRV5)
#define PORT_PA06F_PTC_DRV5                        (_UINT32_(1) << 6)

#define PIN_PA08F_PTC_DRV6                         _UINT32_(8) 
#define MUX_PA08F_PTC_DRV6                         _UINT32_(5) 
#define PINMUX_PA08F_PTC_DRV6                      ((PIN_PA08F_PTC_DRV6 << 16) | MUX_PA08F_PTC_DRV6)
#define PORT_PA08F_PTC_DRV6                        (_UINT32_(1) << 8)

#define PIN_PA09F_PTC_DRV7                         _UINT32_(9) 
#define MUX_PA09F_PTC_DRV7                         _UINT32_(5) 
#define PINMUX_PA09F_PTC_DRV7                      ((PIN_PA09F_PTC_DRV7 << 16) | MUX_PA09F_PTC_DRV7)
#define PORT_PA09F_PTC_DRV7                        (_UINT32_(1) << 9)

#define PIN_PA10F_PTC_DRV8                         _UINT32_(10)
#define MUX_PA10F_PTC_DRV8                         _UINT32_(5) 
#define PINMUX_PA10F_PTC_DRV8                      ((PIN_PA10F_PTC_DRV8 << 16) | MUX_PA10F_PTC_DRV8)
#define PORT_PA10F_PTC_DRV8                        (_UINT32_(1) << 10)

#define PIN_PA11F_PTC_DRV9                         _UINT32_(11)
#define MUX_PA11F_PTC_DRV9                         _UINT32_(5) 
#define PINMUX_PA11F_PTC_DRV9                      ((PIN_PA11F_PTC_DRV9 << 16) | MUX_PA11F_PTC_DRV9)
#define PORT_PA11F_PTC_DRV9                        (_UINT32_(1) << 11)

#define PIN_PA14F_PTC_DRV10                        _UINT32_(14)
#define MUX_PA14F_PTC_DRV10                        _UINT32_(5) 
#define PINMUX_PA14F_PTC_DRV10                     ((PIN_PA14F_PTC_DRV10 << 16) | MUX_PA14F_PTC_DRV10)
#define PORT_PA14F_PTC_DRV10                       (_UINT32_(1) << 14)

#define PIN_PA15F_PTC_DRV11                        _UINT32_(15)
#define MUX_PA15F_PTC_DRV11                        _UINT32_(5) 
#define PINMUX_PA15F_PTC_DRV11                     ((PIN_PA15F_PTC_DRV11 << 16) | MUX_PA15F_PTC_DRV11)
#define PORT_PA15F_PTC_DRV11                       (_UINT32_(1) << 15)

#define PIN_PA16F_PTC_DRV12                        _UINT32_(16)
#define MUX_PA16F_PTC_DRV12                        _UINT32_(5) 
#define PINMUX_PA16F_PTC_DRV12                     ((PIN_PA16F_PTC_DRV12 << 16) | MUX_PA16F_PTC_DRV12)
#define PORT_PA16F_PTC_DRV12                       (_UINT32_(1) << 16)

#define PIN_PA17F_PTC_DRV13                        _UINT32_(17)
#define MUX_PA17F_PTC_DRV13                        _UINT32_(5) 
#define PINMUX_PA17F_PTC_DRV13                     ((PIN_PA17F_PTC_DRV13 << 16) | MUX_PA17F_PTC_DRV13)
#define PORT_PA17F_PTC_DRV13                       (_UINT32_(1) << 17)

#define PIN_PA18F_PTC_DRV14                        _UINT32_(18)
#define MUX_PA18F_PTC_DRV14                        _UINT32_(5) 
#define PINMUX_PA18F_PTC_DRV14                     ((PIN_PA18F_PTC_DRV14 << 16) | MUX_PA18F_PTC_DRV14)
#define PORT_PA18F_PTC_DRV14                       (_UINT32_(1) << 18)

#define PIN_PA19F_PTC_DRV15                        _UINT32_(19)
#define MUX_PA19F_PTC_DRV15                        _UINT32_(5) 
#define PINMUX_PA19F_PTC_DRV15                     ((PIN_PA19F_PTC_DRV15 << 16) | MUX_PA19F_PTC_DRV15)
#define PORT_PA19F_PTC_DRV15                       (_UINT32_(1) << 19)

#define PIN_PA22F_PTC_DRV16                        _UINT32_(22)
#define MUX_PA22F_PTC_DRV16                        _UINT32_(5) 
#define PINMUX_PA22F_PTC_DRV16                     ((PIN_PA22F_PTC_DRV16 << 16) | MUX_PA22F_PTC_DRV16)
#define PORT_PA22F_PTC_DRV16                       (_UINT32_(1) << 22)

#define PIN_PA23F_PTC_DRV17                        _UINT32_(23)
#define MUX_PA23F_PTC_DRV17                        _UINT32_(5) 
#define PINMUX_PA23F_PTC_DRV17                     ((PIN_PA23F_PTC_DRV17 << 16) | MUX_PA23F_PTC_DRV17)
#define PORT_PA23F_PTC_DRV17                       (_UINT32_(1) << 23)

#define PIN_PA30F_PTC_DRV18                        _UINT32_(30)
#define MUX_PA30F_PTC_DRV18                        _UINT32_(5) 
#define PINMUX_PA30F_PTC_DRV18                     ((PIN_PA30F_PTC_DRV18 << 16) | MUX_PA30F_PTC_DRV18)
#define PORT_PA30F_PTC_DRV18                       (_UINT32_(1) << 30)

#define PIN_PA31F_PTC_DRV19                        _UINT32_(31)
#define MUX_PA31F_PTC_DRV19                        _UINT32_(5) 
#define PINMUX_PA31F_PTC_DRV19                     ((PIN_PA31F_PTC_DRV19 << 16) | MUX_PA31F_PTC_DRV19)
#define PORT_PA31F_PTC_DRV19                       (_UINT32_(1) << 31)

#define PIN_PB08F_PTC_DRV20                        _UINT32_(40)
#define MUX_PB08F_PTC_DRV20                        _UINT32_(5) 
#define PINMUX_PB08F_PTC_DRV20                     ((PIN_PB08F_PTC_DRV20 << 16) | MUX_PB08F_PTC_DRV20)
#define PORT_PB08F_PTC_DRV20                       (_UINT32_(1) << 8)

#define PIN_PB09F_PTC_DRV21                        _UINT32_(41)
#define MUX_PB09F_PTC_DRV21                        _UINT32_(5) 
#define PINMUX_PB09F_PTC_DRV21                     ((PIN_PB09F_PTC_DRV21 << 16) | MUX_PB09F_PTC_DRV21)
#define PORT_PB09F_PTC_DRV21                       (_UINT32_(1) << 9)

#define PIN_PA20F_PTC_DRV22                        _UINT32_(20)
#define MUX_PA20F_PTC_DRV22                        _UINT32_(5) 
#define PINMUX_PA20F_PTC_DRV22                     ((PIN_PA20F_PTC_DRV22 << 16) | MUX_PA20F_PTC_DRV22)
#define PORT_PA20F_PTC_DRV22                       (_UINT32_(1) << 20)

#define PIN_PA21F_PTC_DRV23                        _UINT32_(21)
#define MUX_PA21F_PTC_DRV23                        _UINT32_(5) 
#define PINMUX_PA21F_PTC_DRV23                     ((PIN_PA21F_PTC_DRV23 << 16) | MUX_PA21F_PTC_DRV23)
#define PORT_PA21F_PTC_DRV23                       (_UINT32_(1) << 21)

#define PIN_PA12F_PTC_DRV24                        _UINT32_(12)
#define MUX_PA12F_PTC_DRV24                        _UINT32_(5) 
#define PINMUX_PA12F_PTC_DRV24                     ((PIN_PA12F_PTC_DRV24 << 16) | MUX_PA12F_PTC_DRV24)
#define PORT_PA12F_PTC_DRV24                       (_UINT32_(1) << 12)

#define PIN_PA13F_PTC_DRV25                        _UINT32_(13)
#define MUX_PA13F_PTC_DRV25                        _UINT32_(5) 
#define PINMUX_PA13F_PTC_DRV25                     ((PIN_PA13F_PTC_DRV25 << 16) | MUX_PA13F_PTC_DRV25)
#define PORT_PA13F_PTC_DRV25                       (_UINT32_(1) << 13)

#define PIN_PA03B_PTC_ECI0                         _UINT32_(3) 
#define MUX_PA03B_PTC_ECI0                         _UINT32_(1) 
#define PINMUX_PA03B_PTC_ECI0                      ((PIN_PA03B_PTC_ECI0 << 16) | MUX_PA03B_PTC_ECI0)
#define PORT_PA03B_PTC_ECI0                        (_UINT32_(1) << 3)

#define PIN_PA04B_PTC_ECI1                         _UINT32_(4) 
#define MUX_PA04B_PTC_ECI1                         _UINT32_(1) 
#define PINMUX_PA04B_PTC_ECI1                      ((PIN_PA04B_PTC_ECI1 << 16) | MUX_PA04B_PTC_ECI1)
#define PORT_PA04B_PTC_ECI1                        (_UINT32_(1) << 4)

#define PIN_PA05B_PTC_ECI2                         _UINT32_(5) 
#define MUX_PA05B_PTC_ECI2                         _UINT32_(1) 
#define PINMUX_PA05B_PTC_ECI2                      ((PIN_PA05B_PTC_ECI2 << 16) | MUX_PA05B_PTC_ECI2)
#define PORT_PA05B_PTC_ECI2                        (_UINT32_(1) << 5)

#define PIN_PA06B_PTC_ECI3                         _UINT32_(6) 
#define MUX_PA06B_PTC_ECI3                         _UINT32_(1) 
#define PINMUX_PA06B_PTC_ECI3                      ((PIN_PA06B_PTC_ECI3 << 16) | MUX_PA06B_PTC_ECI3)
#define PORT_PA06B_PTC_ECI3                        (_UINT32_(1) << 6)

#define PIN_PA00B_PTC_X0                           _UINT32_(0) 
#define MUX_PA00B_PTC_X0                           _UINT32_(1) 
#define PINMUX_PA00B_PTC_X0                        ((PIN_PA00B_PTC_X0 << 16) | MUX_PA00B_PTC_X0)
#define PORT_PA00B_PTC_X0                          (_UINT32_(1) << 0)

#define PIN_PA01B_PTC_X1                           _UINT32_(1) 
#define MUX_PA01B_PTC_X1                           _UINT32_(1) 
#define PINMUX_PA01B_PTC_X1                        ((PIN_PA01B_PTC_X1 << 16) | MUX_PA01B_PTC_X1)
#define PORT_PA01B_PTC_X1                          (_UINT32_(1) << 1)

#define PIN_PA02B_PTC_X2                           _UINT32_(2) 
#define MUX_PA02B_PTC_X2                           _UINT32_(1) 
#define PINMUX_PA02B_PTC_X2                        ((PIN_PA02B_PTC_X2 << 16) | MUX_PA02B_PTC_X2)
#define PORT_PA02B_PTC_X2                          (_UINT32_(1) << 2)

#define PIN_PA03B_PTC_X3                           _UINT32_(3) 
#define MUX_PA03B_PTC_X3                           _UINT32_(1) 
#define PINMUX_PA03B_PTC_X3                        ((PIN_PA03B_PTC_X3 << 16) | MUX_PA03B_PTC_X3)
#define PORT_PA03B_PTC_X3                          (_UINT32_(1) << 3)

#define PIN_PA05B_PTC_X4                           _UINT32_(5) 
#define MUX_PA05B_PTC_X4                           _UINT32_(1) 
#define PINMUX_PA05B_PTC_X4                        ((PIN_PA05B_PTC_X4 << 16) | MUX_PA05B_PTC_X4)
#define PORT_PA05B_PTC_X4                          (_UINT32_(1) << 5)

#define PIN_PA06B_PTC_X5                           _UINT32_(6) 
#define MUX_PA06B_PTC_X5                           _UINT32_(1) 
#define PINMUX_PA06B_PTC_X5                        ((PIN_PA06B_PTC_X5 << 16) | MUX_PA06B_PTC_X5)
#define PORT_PA06B_PTC_X5                          (_UINT32_(1) << 6)

#define PIN_PA08B_PTC_X6                           _UINT32_(8) 
#define MUX_PA08B_PTC_X6                           _UINT32_(1) 
#define PINMUX_PA08B_PTC_X6                        ((PIN_PA08B_PTC_X6 << 16) | MUX_PA08B_PTC_X6)
#define PORT_PA08B_PTC_X6                          (_UINT32_(1) << 8)

#define PIN_PA09B_PTC_X7                           _UINT32_(9) 
#define MUX_PA09B_PTC_X7                           _UINT32_(1) 
#define PINMUX_PA09B_PTC_X7                        ((PIN_PA09B_PTC_X7 << 16) | MUX_PA09B_PTC_X7)
#define PORT_PA09B_PTC_X7                          (_UINT32_(1) << 9)

#define PIN_PA10B_PTC_X8                           _UINT32_(10)
#define MUX_PA10B_PTC_X8                           _UINT32_(1) 
#define PINMUX_PA10B_PTC_X8                        ((PIN_PA10B_PTC_X8 << 16) | MUX_PA10B_PTC_X8)
#define PORT_PA10B_PTC_X8                          (_UINT32_(1) << 10)

#define PIN_PA11B_PTC_X9                           _UINT32_(11)
#define MUX_PA11B_PTC_X9                           _UINT32_(1) 
#define PINMUX_PA11B_PTC_X9                        ((PIN_PA11B_PTC_X9 << 16) | MUX_PA11B_PTC_X9)
#define PORT_PA11B_PTC_X9                          (_UINT32_(1) << 11)

#define PIN_PA14B_PTC_X10                          _UINT32_(14)
#define MUX_PA14B_PTC_X10                          _UINT32_(1) 
#define PINMUX_PA14B_PTC_X10                       ((PIN_PA14B_PTC_X10 << 16) | MUX_PA14B_PTC_X10)
#define PORT_PA14B_PTC_X10                         (_UINT32_(1) << 14)

#define PIN_PA15B_PTC_X11                          _UINT32_(15)
#define MUX_PA15B_PTC_X11                          _UINT32_(1) 
#define PINMUX_PA15B_PTC_X11                       ((PIN_PA15B_PTC_X11 << 16) | MUX_PA15B_PTC_X11)
#define PORT_PA15B_PTC_X11                         (_UINT32_(1) << 15)

#define PIN_PA16B_PTC_X12                          _UINT32_(16)
#define MUX_PA16B_PTC_X12                          _UINT32_(1) 
#define PINMUX_PA16B_PTC_X12                       ((PIN_PA16B_PTC_X12 << 16) | MUX_PA16B_PTC_X12)
#define PORT_PA16B_PTC_X12                         (_UINT32_(1) << 16)

#define PIN_PA17B_PTC_X13                          _UINT32_(17)
#define MUX_PA17B_PTC_X13                          _UINT32_(1) 
#define PINMUX_PA17B_PTC_X13                       ((PIN_PA17B_PTC_X13 << 16) | MUX_PA17B_PTC_X13)
#define PORT_PA17B_PTC_X13                         (_UINT32_(1) << 17)

#define PIN_PA18B_PTC_X14                          _UINT32_(18)
#define MUX_PA18B_PTC_X14                          _UINT32_(1) 
#define PINMUX_PA18B_PTC_X14                       ((PIN_PA18B_PTC_X14 << 16) | MUX_PA18B_PTC_X14)
#define PORT_PA18B_PTC_X14                         (_UINT32_(1) << 18)

#define PIN_PA19B_PTC_X15                          _UINT32_(19)
#define MUX_PA19B_PTC_X15                          _UINT32_(1) 
#define PINMUX_PA19B_PTC_X15                       ((PIN_PA19B_PTC_X15 << 16) | MUX_PA19B_PTC_X15)
#define PORT_PA19B_PTC_X15                         (_UINT32_(1) << 19)

#define PIN_PA22B_PTC_X16                          _UINT32_(22)
#define MUX_PA22B_PTC_X16                          _UINT32_(1) 
#define PINMUX_PA22B_PTC_X16                       ((PIN_PA22B_PTC_X16 << 16) | MUX_PA22B_PTC_X16)
#define PORT_PA22B_PTC_X16                         (_UINT32_(1) << 22)

#define PIN_PA23B_PTC_X17                          _UINT32_(23)
#define MUX_PA23B_PTC_X17                          _UINT32_(1) 
#define PINMUX_PA23B_PTC_X17                       ((PIN_PA23B_PTC_X17 << 16) | MUX_PA23B_PTC_X17)
#define PORT_PA23B_PTC_X17                         (_UINT32_(1) << 23)

#define PIN_PA30B_PTC_X18                          _UINT32_(30)
#define MUX_PA30B_PTC_X18                          _UINT32_(1) 
#define PINMUX_PA30B_PTC_X18                       ((PIN_PA30B_PTC_X18 << 16) | MUX_PA30B_PTC_X18)
#define PORT_PA30B_PTC_X18                         (_UINT32_(1) << 30)

#define PIN_PA31B_PTC_X19                          _UINT32_(31)
#define MUX_PA31B_PTC_X19                          _UINT32_(1) 
#define PINMUX_PA31B_PTC_X19                       ((PIN_PA31B_PTC_X19 << 16) | MUX_PA31B_PTC_X19)
#define PORT_PA31B_PTC_X19                         (_UINT32_(1) << 31)

#define PIN_PB08B_PTC_X20                          _UINT32_(40)
#define MUX_PB08B_PTC_X20                          _UINT32_(1) 
#define PINMUX_PB08B_PTC_X20                       ((PIN_PB08B_PTC_X20 << 16) | MUX_PB08B_PTC_X20)
#define PORT_PB08B_PTC_X20                         (_UINT32_(1) << 8)

#define PIN_PB09B_PTC_X21                          _UINT32_(41)
#define MUX_PB09B_PTC_X21                          _UINT32_(1) 
#define PINMUX_PB09B_PTC_X21                       ((PIN_PB09B_PTC_X21 << 16) | MUX_PB09B_PTC_X21)
#define PORT_PB09B_PTC_X21                         (_UINT32_(1) << 9)

#define PIN_PA20B_PTC_X22                          _UINT32_(20)
#define MUX_PA20B_PTC_X22                          _UINT32_(1) 
#define PINMUX_PA20B_PTC_X22                       ((PIN_PA20B_PTC_X22 << 16) | MUX_PA20B_PTC_X22)
#define PORT_PA20B_PTC_X22                         (_UINT32_(1) << 20)

#define PIN_PA21B_PTC_X23                          _UINT32_(21)
#define MUX_PA21B_PTC_X23                          _UINT32_(1) 
#define PINMUX_PA21B_PTC_X23                       ((PIN_PA21B_PTC_X23 << 16) | MUX_PA21B_PTC_X23)
#define PORT_PA21B_PTC_X23                         (_UINT32_(1) << 21)

#define PIN_PA12B_PTC_X24                          _UINT32_(12)
#define MUX_PA12B_PTC_X24                          _UINT32_(1) 
#define PINMUX_PA12B_PTC_X24                       ((PIN_PA12B_PTC_X24 << 16) | MUX_PA12B_PTC_X24)
#define PORT_PA12B_PTC_X24                         (_UINT32_(1) << 12)

#define PIN_PA13B_PTC_X25                          _UINT32_(13)
#define MUX_PA13B_PTC_X25                          _UINT32_(1) 
#define PINMUX_PA13B_PTC_X25                       ((PIN_PA13B_PTC_X25 << 16) | MUX_PA13B_PTC_X25)
#define PORT_PA13B_PTC_X25                         (_UINT32_(1) << 13)

#define PIN_PA00B_PTC_Y0                           _UINT32_(0) 
#define MUX_PA00B_PTC_Y0                           _UINT32_(1) 
#define PINMUX_PA00B_PTC_Y0                        ((PIN_PA00B_PTC_Y0 << 16) | MUX_PA00B_PTC_Y0)
#define PORT_PA00B_PTC_Y0                          (_UINT32_(1) << 0)

#define PIN_PA01B_PTC_Y1                           _UINT32_(1) 
#define MUX_PA01B_PTC_Y1                           _UINT32_(1) 
#define PINMUX_PA01B_PTC_Y1                        ((PIN_PA01B_PTC_Y1 << 16) | MUX_PA01B_PTC_Y1)
#define PORT_PA01B_PTC_Y1                          (_UINT32_(1) << 1)

#define PIN_PA02B_PTC_Y2                           _UINT32_(2) 
#define MUX_PA02B_PTC_Y2                           _UINT32_(1) 
#define PINMUX_PA02B_PTC_Y2                        ((PIN_PA02B_PTC_Y2 << 16) | MUX_PA02B_PTC_Y2)
#define PORT_PA02B_PTC_Y2                          (_UINT32_(1) << 2)

#define PIN_PA03B_PTC_Y3                           _UINT32_(3) 
#define MUX_PA03B_PTC_Y3                           _UINT32_(1) 
#define PINMUX_PA03B_PTC_Y3                        ((PIN_PA03B_PTC_Y3 << 16) | MUX_PA03B_PTC_Y3)
#define PORT_PA03B_PTC_Y3                          (_UINT32_(1) << 3)

#define PIN_PA05B_PTC_Y4                           _UINT32_(5) 
#define MUX_PA05B_PTC_Y4                           _UINT32_(1) 
#define PINMUX_PA05B_PTC_Y4                        ((PIN_PA05B_PTC_Y4 << 16) | MUX_PA05B_PTC_Y4)
#define PORT_PA05B_PTC_Y4                          (_UINT32_(1) << 5)

#define PIN_PA06B_PTC_Y5                           _UINT32_(6) 
#define MUX_PA06B_PTC_Y5                           _UINT32_(1) 
#define PINMUX_PA06B_PTC_Y5                        ((PIN_PA06B_PTC_Y5 << 16) | MUX_PA06B_PTC_Y5)
#define PORT_PA06B_PTC_Y5                          (_UINT32_(1) << 6)

#define PIN_PA08B_PTC_Y6                           _UINT32_(8) 
#define MUX_PA08B_PTC_Y6                           _UINT32_(1) 
#define PINMUX_PA08B_PTC_Y6                        ((PIN_PA08B_PTC_Y6 << 16) | MUX_PA08B_PTC_Y6)
#define PORT_PA08B_PTC_Y6                          (_UINT32_(1) << 8)

#define PIN_PA09B_PTC_Y7                           _UINT32_(9) 
#define MUX_PA09B_PTC_Y7                           _UINT32_(1) 
#define PINMUX_PA09B_PTC_Y7                        ((PIN_PA09B_PTC_Y7 << 16) | MUX_PA09B_PTC_Y7)
#define PORT_PA09B_PTC_Y7                          (_UINT32_(1) << 9)

#define PIN_PA10B_PTC_Y8                           _UINT32_(10)
#define MUX_PA10B_PTC_Y8                           _UINT32_(1) 
#define PINMUX_PA10B_PTC_Y8                        ((PIN_PA10B_PTC_Y8 << 16) | MUX_PA10B_PTC_Y8)
#define PORT_PA10B_PTC_Y8                          (_UINT32_(1) << 10)

#define PIN_PA11B_PTC_Y9                           _UINT32_(11)
#define MUX_PA11B_PTC_Y9                           _UINT32_(1) 
#define PINMUX_PA11B_PTC_Y9                        ((PIN_PA11B_PTC_Y9 << 16) | MUX_PA11B_PTC_Y9)
#define PORT_PA11B_PTC_Y9                          (_UINT32_(1) << 11)

#define PIN_PA14B_PTC_Y10                          _UINT32_(14)
#define MUX_PA14B_PTC_Y10                          _UINT32_(1) 
#define PINMUX_PA14B_PTC_Y10                       ((PIN_PA14B_PTC_Y10 << 16) | MUX_PA14B_PTC_Y10)
#define PORT_PA14B_PTC_Y10                         (_UINT32_(1) << 14)

#define PIN_PA15B_PTC_Y11                          _UINT32_(15)
#define MUX_PA15B_PTC_Y11                          _UINT32_(1) 
#define PINMUX_PA15B_PTC_Y11                       ((PIN_PA15B_PTC_Y11 << 16) | MUX_PA15B_PTC_Y11)
#define PORT_PA15B_PTC_Y11                         (_UINT32_(1) << 15)

#define PIN_PA16B_PTC_Y12                          _UINT32_(16)
#define MUX_PA16B_PTC_Y12                          _UINT32_(1) 
#define PINMUX_PA16B_PTC_Y12                       ((PIN_PA16B_PTC_Y12 << 16) | MUX_PA16B_PTC_Y12)
#define PORT_PA16B_PTC_Y12                         (_UINT32_(1) << 16)

#define PIN_PA17B_PTC_Y13                          _UINT32_(17)
#define MUX_PA17B_PTC_Y13                          _UINT32_(1) 
#define PINMUX_PA17B_PTC_Y13                       ((PIN_PA17B_PTC_Y13 << 16) | MUX_PA17B_PTC_Y13)
#define PORT_PA17B_PTC_Y13                         (_UINT32_(1) << 17)

#define PIN_PA18B_PTC_Y14                          _UINT32_(18)
#define MUX_PA18B_PTC_Y14                          _UINT32_(1) 
#define PINMUX_PA18B_PTC_Y14                       ((PIN_PA18B_PTC_Y14 << 16) | MUX_PA18B_PTC_Y14)
#define PORT_PA18B_PTC_Y14                         (_UINT32_(1) << 18)

#define PIN_PA19B_PTC_Y15                          _UINT32_(19)
#define MUX_PA19B_PTC_Y15                          _UINT32_(1) 
#define PINMUX_PA19B_PTC_Y15                       ((PIN_PA19B_PTC_Y15 << 16) | MUX_PA19B_PTC_Y15)
#define PORT_PA19B_PTC_Y15                         (_UINT32_(1) << 19)

#define PIN_PA22B_PTC_Y16                          _UINT32_(22)
#define MUX_PA22B_PTC_Y16                          _UINT32_(1) 
#define PINMUX_PA22B_PTC_Y16                       ((PIN_PA22B_PTC_Y16 << 16) | MUX_PA22B_PTC_Y16)
#define PORT_PA22B_PTC_Y16                         (_UINT32_(1) << 22)

#define PIN_PA23B_PTC_Y17                          _UINT32_(23)
#define MUX_PA23B_PTC_Y17                          _UINT32_(1) 
#define PINMUX_PA23B_PTC_Y17                       ((PIN_PA23B_PTC_Y17 << 16) | MUX_PA23B_PTC_Y17)
#define PORT_PA23B_PTC_Y17                         (_UINT32_(1) << 23)

#define PIN_PA30B_PTC_Y18                          _UINT32_(30)
#define MUX_PA30B_PTC_Y18                          _UINT32_(1) 
#define PINMUX_PA30B_PTC_Y18                       ((PIN_PA30B_PTC_Y18 << 16) | MUX_PA30B_PTC_Y18)
#define PORT_PA30B_PTC_Y18                         (_UINT32_(1) << 30)

#define PIN_PA31B_PTC_Y19                          _UINT32_(31)
#define MUX_PA31B_PTC_Y19                          _UINT32_(1) 
#define PINMUX_PA31B_PTC_Y19                       ((PIN_PA31B_PTC_Y19 << 16) | MUX_PA31B_PTC_Y19)
#define PORT_PA31B_PTC_Y19                         (_UINT32_(1) << 31)

#define PIN_PB08B_PTC_Y20                          _UINT32_(40)
#define MUX_PB08B_PTC_Y20                          _UINT32_(1) 
#define PINMUX_PB08B_PTC_Y20                       ((PIN_PB08B_PTC_Y20 << 16) | MUX_PB08B_PTC_Y20)
#define PORT_PB08B_PTC_Y20                         (_UINT32_(1) << 8)

#define PIN_PB09B_PTC_Y21                          _UINT32_(41)
#define MUX_PB09B_PTC_Y21                          _UINT32_(1) 
#define PINMUX_PB09B_PTC_Y21                       ((PIN_PB09B_PTC_Y21 << 16) | MUX_PB09B_PTC_Y21)
#define PORT_PB09B_PTC_Y21                         (_UINT32_(1) << 9)

#define PIN_PA20B_PTC_Y22                          _UINT32_(20)
#define MUX_PA20B_PTC_Y22                          _UINT32_(1) 
#define PINMUX_PA20B_PTC_Y22                       ((PIN_PA20B_PTC_Y22 << 16) | MUX_PA20B_PTC_Y22)
#define PORT_PA20B_PTC_Y22                         (_UINT32_(1) << 20)

#define PIN_PA21B_PTC_Y23                          _UINT32_(21)
#define MUX_PA21B_PTC_Y23                          _UINT32_(1) 
#define PINMUX_PA21B_PTC_Y23                       ((PIN_PA21B_PTC_Y23 << 16) | MUX_PA21B_PTC_Y23)
#define PORT_PA21B_PTC_Y23                         (_UINT32_(1) << 21)

#define PIN_PA12B_PTC_Y24                          _UINT32_(12)
#define MUX_PA12B_PTC_Y24                          _UINT32_(1) 
#define PINMUX_PA12B_PTC_Y24                       ((PIN_PA12B_PTC_Y24 << 16) | MUX_PA12B_PTC_Y24)
#define PORT_PA12B_PTC_Y24                         (_UINT32_(1) << 12)

#define PIN_PA13B_PTC_Y25                          _UINT32_(13)
#define MUX_PA13B_PTC_Y25                          _UINT32_(1) 
#define PINMUX_PA13B_PTC_Y25                       ((PIN_PA13B_PTC_Y25 << 16) | MUX_PA13B_PTC_Y25)
#define PORT_PA13B_PTC_Y25                         (_UINT32_(1) << 13)

/* ========== PORT definition for RTC peripheral ========== */
#define PIN_PA08G_RTC_IN0                          _UINT32_(8) 
#define MUX_PA08G_RTC_IN0                          _UINT32_(6) 
#define PINMUX_PA08G_RTC_IN0                       ((PIN_PA08G_RTC_IN0 << 16) | MUX_PA08G_RTC_IN0)
#define PORT_PA08G_RTC_IN0                         (_UINT32_(1) << 8)

#define PIN_PA09G_RTC_IN1                          _UINT32_(9) 
#define MUX_PA09G_RTC_IN1                          _UINT32_(6) 
#define PINMUX_PA09G_RTC_IN1                       ((PIN_PA09G_RTC_IN1 << 16) | MUX_PA09G_RTC_IN1)
#define PORT_PA09G_RTC_IN1                         (_UINT32_(1) << 9)

#define PIN_PA16G_RTC_IN2                          _UINT32_(16)
#define MUX_PA16G_RTC_IN2                          _UINT32_(6) 
#define PINMUX_PA16G_RTC_IN2                       ((PIN_PA16G_RTC_IN2 << 16) | MUX_PA16G_RTC_IN2)
#define PORT_PA16G_RTC_IN2                         (_UINT32_(1) << 16)

#define PIN_PA17G_RTC_IN3                          _UINT32_(17)
#define MUX_PA17G_RTC_IN3                          _UINT32_(6) 
#define PINMUX_PA17G_RTC_IN3                       ((PIN_PA17G_RTC_IN3 << 16) | MUX_PA17G_RTC_IN3)
#define PORT_PA17G_RTC_IN3                         (_UINT32_(1) << 17)

#define PIN_PA18G_RTC_OUT0                         _UINT32_(18)
#define MUX_PA18G_RTC_OUT0                         _UINT32_(6) 
#define PINMUX_PA18G_RTC_OUT0                      ((PIN_PA18G_RTC_OUT0 << 16) | MUX_PA18G_RTC_OUT0)
#define PORT_PA18G_RTC_OUT0                        (_UINT32_(1) << 18)

#define PIN_PA19G_RTC_OUT1                         _UINT32_(19)
#define MUX_PA19G_RTC_OUT1                         _UINT32_(6) 
#define PINMUX_PA19G_RTC_OUT1                      ((PIN_PA19G_RTC_OUT1 << 16) | MUX_PA19G_RTC_OUT1)
#define PORT_PA19G_RTC_OUT1                        (_UINT32_(1) << 19)

#define PIN_PA22G_RTC_OUT2                         _UINT32_(22)
#define MUX_PA22G_RTC_OUT2                         _UINT32_(6) 
#define PINMUX_PA22G_RTC_OUT2                      ((PIN_PA22G_RTC_OUT2 << 16) | MUX_PA22G_RTC_OUT2)
#define PORT_PA22G_RTC_OUT2                        (_UINT32_(1) << 22)

#define PIN_PA23G_RTC_OUT3                         _UINT32_(23)
#define MUX_PA23G_RTC_OUT3                         _UINT32_(6) 
#define PINMUX_PA23G_RTC_OUT3                      ((PIN_PA23G_RTC_OUT3 << 16) | MUX_PA23G_RTC_OUT3)
#define PORT_PA23G_RTC_OUT3                        (_UINT32_(1) << 23)

/* ========== PORT definition for SERCOM0 peripheral ========== */
#define PIN_PA04D_SERCOM0_PAD0                     _UINT32_(4) 
#define MUX_PA04D_SERCOM0_PAD0                     _UINT32_(3) 
#define PINMUX_PA04D_SERCOM0_PAD0                  ((PIN_PA04D_SERCOM0_PAD0 << 16) | MUX_PA04D_SERCOM0_PAD0)
#define PORT_PA04D_SERCOM0_PAD0                    (_UINT32_(1) << 4)

#define PIN_PA16D_SERCOM0_PAD0                     _UINT32_(16)
#define MUX_PA16D_SERCOM0_PAD0                     _UINT32_(3) 
#define PINMUX_PA16D_SERCOM0_PAD0                  ((PIN_PA16D_SERCOM0_PAD0 << 16) | MUX_PA16D_SERCOM0_PAD0)
#define PORT_PA16D_SERCOM0_PAD0                    (_UINT32_(1) << 16)

#define PIN_PA22C_SERCOM0_PAD0                     _UINT32_(22)
#define MUX_PA22C_SERCOM0_PAD0                     _UINT32_(2) 
#define PINMUX_PA22C_SERCOM0_PAD0                  ((PIN_PA22C_SERCOM0_PAD0 << 16) | MUX_PA22C_SERCOM0_PAD0)
#define PORT_PA22C_SERCOM0_PAD0                    (_UINT32_(1) << 22)

#define PIN_PA05D_SERCOM0_PAD1                     _UINT32_(5) 
#define MUX_PA05D_SERCOM0_PAD1                     _UINT32_(3) 
#define PINMUX_PA05D_SERCOM0_PAD1                  ((PIN_PA05D_SERCOM0_PAD1 << 16) | MUX_PA05D_SERCOM0_PAD1)
#define PORT_PA05D_SERCOM0_PAD1                    (_UINT32_(1) << 5)

#define PIN_PA17D_SERCOM0_PAD1                     _UINT32_(17)
#define MUX_PA17D_SERCOM0_PAD1                     _UINT32_(3) 
#define PINMUX_PA17D_SERCOM0_PAD1                  ((PIN_PA17D_SERCOM0_PAD1 << 16) | MUX_PA17D_SERCOM0_PAD1)
#define PORT_PA17D_SERCOM0_PAD1                    (_UINT32_(1) << 17)

#define PIN_PA23C_SERCOM0_PAD1                     _UINT32_(23)
#define MUX_PA23C_SERCOM0_PAD1                     _UINT32_(2) 
#define PINMUX_PA23C_SERCOM0_PAD1                  ((PIN_PA23C_SERCOM0_PAD1 << 16) | MUX_PA23C_SERCOM0_PAD1)
#define PORT_PA23C_SERCOM0_PAD1                    (_UINT32_(1) << 23)

#define PIN_PA06D_SERCOM0_PAD2                     _UINT32_(6) 
#define MUX_PA06D_SERCOM0_PAD2                     _UINT32_(3) 
#define PINMUX_PA06D_SERCOM0_PAD2                  ((PIN_PA06D_SERCOM0_PAD2 << 16) | MUX_PA06D_SERCOM0_PAD2)
#define PORT_PA06D_SERCOM0_PAD2                    (_UINT32_(1) << 6)

#define PIN_PA14D_SERCOM0_PAD2                     _UINT32_(14)
#define MUX_PA14D_SERCOM0_PAD2                     _UINT32_(3) 
#define PINMUX_PA14D_SERCOM0_PAD2                  ((PIN_PA14D_SERCOM0_PAD2 << 16) | MUX_PA14D_SERCOM0_PAD2)
#define PORT_PA14D_SERCOM0_PAD2                    (_UINT32_(1) << 14)

#define PIN_PA18D_SERCOM0_PAD2                     _UINT32_(18)
#define MUX_PA18D_SERCOM0_PAD2                     _UINT32_(3) 
#define PINMUX_PA18D_SERCOM0_PAD2                  ((PIN_PA18D_SERCOM0_PAD2 << 16) | MUX_PA18D_SERCOM0_PAD2)
#define PORT_PA18D_SERCOM0_PAD2                    (_UINT32_(1) << 18)

#define PIN_PA24C_SERCOM0_PAD2                     _UINT32_(24)
#define MUX_PA24C_SERCOM0_PAD2                     _UINT32_(2) 
#define PINMUX_PA24C_SERCOM0_PAD2                  ((PIN_PA24C_SERCOM0_PAD2 << 16) | MUX_PA24C_SERCOM0_PAD2)
#define PORT_PA24C_SERCOM0_PAD2                    (_UINT32_(1) << 24)

#define PIN_PB22C_SERCOM0_PAD2                     _UINT32_(54)
#define MUX_PB22C_SERCOM0_PAD2                     _UINT32_(2) 
#define PINMUX_PB22C_SERCOM0_PAD2                  ((PIN_PB22C_SERCOM0_PAD2 << 16) | MUX_PB22C_SERCOM0_PAD2)
#define PORT_PB22C_SERCOM0_PAD2                    (_UINT32_(1) << 22)

#define PIN_PA02D_SERCOM0_PAD2                     _UINT32_(2) 
#define MUX_PA02D_SERCOM0_PAD2                     _UINT32_(3) 
#define PINMUX_PA02D_SERCOM0_PAD2                  ((PIN_PA02D_SERCOM0_PAD2 << 16) | MUX_PA02D_SERCOM0_PAD2)
#define PORT_PA02D_SERCOM0_PAD2                    (_UINT32_(1) << 2)

#define PIN_PA07D_SERCOM0_PAD3                     _UINT32_(7) 
#define MUX_PA07D_SERCOM0_PAD3                     _UINT32_(3) 
#define PINMUX_PA07D_SERCOM0_PAD3                  ((PIN_PA07D_SERCOM0_PAD3 << 16) | MUX_PA07D_SERCOM0_PAD3)
#define PORT_PA07D_SERCOM0_PAD3                    (_UINT32_(1) << 7)

#define PIN_PA15D_SERCOM0_PAD3                     _UINT32_(15)
#define MUX_PA15D_SERCOM0_PAD3                     _UINT32_(3) 
#define PINMUX_PA15D_SERCOM0_PAD3                  ((PIN_PA15D_SERCOM0_PAD3 << 16) | MUX_PA15D_SERCOM0_PAD3)
#define PORT_PA15D_SERCOM0_PAD3                    (_UINT32_(1) << 15)

#define PIN_PA19D_SERCOM0_PAD3                     _UINT32_(19)
#define MUX_PA19D_SERCOM0_PAD3                     _UINT32_(3) 
#define PINMUX_PA19D_SERCOM0_PAD3                  ((PIN_PA19D_SERCOM0_PAD3 << 16) | MUX_PA19D_SERCOM0_PAD3)
#define PORT_PA19D_SERCOM0_PAD3                    (_UINT32_(1) << 19)

#define PIN_PA25C_SERCOM0_PAD3                     _UINT32_(25)
#define MUX_PA25C_SERCOM0_PAD3                     _UINT32_(2) 
#define PINMUX_PA25C_SERCOM0_PAD3                  ((PIN_PA25C_SERCOM0_PAD3 << 16) | MUX_PA25C_SERCOM0_PAD3)
#define PORT_PA25C_SERCOM0_PAD3                    (_UINT32_(1) << 25)

#define PIN_PB23C_SERCOM0_PAD3                     _UINT32_(55)
#define MUX_PB23C_SERCOM0_PAD3                     _UINT32_(2) 
#define PINMUX_PB23C_SERCOM0_PAD3                  ((PIN_PB23C_SERCOM0_PAD3 << 16) | MUX_PB23C_SERCOM0_PAD3)
#define PORT_PB23C_SERCOM0_PAD3                    (_UINT32_(1) << 23)

#define PIN_PA03D_SERCOM0_PAD3                     _UINT32_(3) 
#define MUX_PA03D_SERCOM0_PAD3                     _UINT32_(3) 
#define PINMUX_PA03D_SERCOM0_PAD3                  ((PIN_PA03D_SERCOM0_PAD3 << 16) | MUX_PA03D_SERCOM0_PAD3)
#define PORT_PA03D_SERCOM0_PAD3                    (_UINT32_(1) << 3)

/* ========== PORT definition for SERCOM1 peripheral ========== */
#define PIN_PA16C_SERCOM1_PAD0                     _UINT32_(16)
#define MUX_PA16C_SERCOM1_PAD0                     _UINT32_(2) 
#define PINMUX_PA16C_SERCOM1_PAD0                  ((PIN_PA16C_SERCOM1_PAD0 << 16) | MUX_PA16C_SERCOM1_PAD0)
#define PORT_PA16C_SERCOM1_PAD0                    (_UINT32_(1) << 16)

#define PIN_PA08C_SERCOM1_PAD0                     _UINT32_(8) 
#define MUX_PA08C_SERCOM1_PAD0                     _UINT32_(2) 
#define PINMUX_PA08C_SERCOM1_PAD0                  ((PIN_PA08C_SERCOM1_PAD0 << 16) | MUX_PA08C_SERCOM1_PAD0)
#define PORT_PA08C_SERCOM1_PAD0                    (_UINT32_(1) << 8)

#define PIN_PA00D_SERCOM1_PAD0                     _UINT32_(0) 
#define MUX_PA00D_SERCOM1_PAD0                     _UINT32_(3) 
#define PINMUX_PA00D_SERCOM1_PAD0                  ((PIN_PA00D_SERCOM1_PAD0 << 16) | MUX_PA00D_SERCOM1_PAD0)
#define PORT_PA00D_SERCOM1_PAD0                    (_UINT32_(1) << 0)

#define PIN_PA17C_SERCOM1_PAD1                     _UINT32_(17)
#define MUX_PA17C_SERCOM1_PAD1                     _UINT32_(2) 
#define PINMUX_PA17C_SERCOM1_PAD1                  ((PIN_PA17C_SERCOM1_PAD1 << 16) | MUX_PA17C_SERCOM1_PAD1)
#define PORT_PA17C_SERCOM1_PAD1                    (_UINT32_(1) << 17)

#define PIN_PA09C_SERCOM1_PAD1                     _UINT32_(9) 
#define MUX_PA09C_SERCOM1_PAD1                     _UINT32_(2) 
#define PINMUX_PA09C_SERCOM1_PAD1                  ((PIN_PA09C_SERCOM1_PAD1 << 16) | MUX_PA09C_SERCOM1_PAD1)
#define PORT_PA09C_SERCOM1_PAD1                    (_UINT32_(1) << 9)

#define PIN_PA01D_SERCOM1_PAD1                     _UINT32_(1) 
#define MUX_PA01D_SERCOM1_PAD1                     _UINT32_(3) 
#define PINMUX_PA01D_SERCOM1_PAD1                  ((PIN_PA01D_SERCOM1_PAD1 << 16) | MUX_PA01D_SERCOM1_PAD1)
#define PORT_PA01D_SERCOM1_PAD1                    (_UINT32_(1) << 1)

#define PIN_PA18C_SERCOM1_PAD2                     _UINT32_(18)
#define MUX_PA18C_SERCOM1_PAD2                     _UINT32_(2) 
#define PINMUX_PA18C_SERCOM1_PAD2                  ((PIN_PA18C_SERCOM1_PAD2 << 16) | MUX_PA18C_SERCOM1_PAD2)
#define PORT_PA18C_SERCOM1_PAD2                    (_UINT32_(1) << 18)

#define PIN_PA10C_SERCOM1_PAD2                     _UINT32_(10)
#define MUX_PA10C_SERCOM1_PAD2                     _UINT32_(2) 
#define PINMUX_PA10C_SERCOM1_PAD2                  ((PIN_PA10C_SERCOM1_PAD2 << 16) | MUX_PA10C_SERCOM1_PAD2)
#define PORT_PA10C_SERCOM1_PAD2                    (_UINT32_(1) << 10)

#define PIN_PA30D_SERCOM1_PAD2                     _UINT32_(30)
#define MUX_PA30D_SERCOM1_PAD2                     _UINT32_(3) 
#define PINMUX_PA30D_SERCOM1_PAD2                  ((PIN_PA30D_SERCOM1_PAD2 << 16) | MUX_PA30D_SERCOM1_PAD2)
#define PORT_PA30D_SERCOM1_PAD2                    (_UINT32_(1) << 30)

#define PIN_PA19C_SERCOM1_PAD3                     _UINT32_(19)
#define MUX_PA19C_SERCOM1_PAD3                     _UINT32_(2) 
#define PINMUX_PA19C_SERCOM1_PAD3                  ((PIN_PA19C_SERCOM1_PAD3 << 16) | MUX_PA19C_SERCOM1_PAD3)
#define PORT_PA19C_SERCOM1_PAD3                    (_UINT32_(1) << 19)

#define PIN_PA11C_SERCOM1_PAD3                     _UINT32_(11)
#define MUX_PA11C_SERCOM1_PAD3                     _UINT32_(2) 
#define PINMUX_PA11C_SERCOM1_PAD3                  ((PIN_PA11C_SERCOM1_PAD3 << 16) | MUX_PA11C_SERCOM1_PAD3)
#define PORT_PA11C_SERCOM1_PAD3                    (_UINT32_(1) << 11)

#define PIN_PA31D_SERCOM1_PAD3                     _UINT32_(31)
#define MUX_PA31D_SERCOM1_PAD3                     _UINT32_(3) 
#define PINMUX_PA31D_SERCOM1_PAD3                  ((PIN_PA31D_SERCOM1_PAD3 << 16) | MUX_PA31D_SERCOM1_PAD3)
#define PORT_PA31D_SERCOM1_PAD3                    (_UINT32_(1) << 31)

/* ========== PORT definition for SERCOM2 peripheral ========== */
#define PIN_PA08D_SERCOM2_PAD0                     _UINT32_(8) 
#define MUX_PA08D_SERCOM2_PAD0                     _UINT32_(3) 
#define PINMUX_PA08D_SERCOM2_PAD0                  ((PIN_PA08D_SERCOM2_PAD0 << 16) | MUX_PA08D_SERCOM2_PAD0)
#define PORT_PA08D_SERCOM2_PAD0                    (_UINT32_(1) << 8)

#define PIN_PA22D_SERCOM2_PAD0                     _UINT32_(22)
#define MUX_PA22D_SERCOM2_PAD0                     _UINT32_(3) 
#define PINMUX_PA22D_SERCOM2_PAD0                  ((PIN_PA22D_SERCOM2_PAD0 << 16) | MUX_PA22D_SERCOM2_PAD0)
#define PORT_PA22D_SERCOM2_PAD0                    (_UINT32_(1) << 22)

#define PIN_PA12C_SERCOM2_PAD0                     _UINT32_(12)
#define MUX_PA12C_SERCOM2_PAD0                     _UINT32_(2) 
#define PINMUX_PA12C_SERCOM2_PAD0                  ((PIN_PA12C_SERCOM2_PAD0 << 16) | MUX_PA12C_SERCOM2_PAD0)
#define PORT_PA12C_SERCOM2_PAD0                    (_UINT32_(1) << 12)

#define PIN_PA09D_SERCOM2_PAD1                     _UINT32_(9) 
#define MUX_PA09D_SERCOM2_PAD1                     _UINT32_(3) 
#define PINMUX_PA09D_SERCOM2_PAD1                  ((PIN_PA09D_SERCOM2_PAD1 << 16) | MUX_PA09D_SERCOM2_PAD1)
#define PORT_PA09D_SERCOM2_PAD1                    (_UINT32_(1) << 9)

#define PIN_PA23D_SERCOM2_PAD1                     _UINT32_(23)
#define MUX_PA23D_SERCOM2_PAD1                     _UINT32_(3) 
#define PINMUX_PA23D_SERCOM2_PAD1                  ((PIN_PA23D_SERCOM2_PAD1 << 16) | MUX_PA23D_SERCOM2_PAD1)
#define PORT_PA23D_SERCOM2_PAD1                    (_UINT32_(1) << 23)

#define PIN_PA13C_SERCOM2_PAD1                     _UINT32_(13)
#define MUX_PA13C_SERCOM2_PAD1                     _UINT32_(2) 
#define PINMUX_PA13C_SERCOM2_PAD1                  ((PIN_PA13C_SERCOM2_PAD1 << 16) | MUX_PA13C_SERCOM2_PAD1)
#define PORT_PA13C_SERCOM2_PAD1                    (_UINT32_(1) << 13)

#define PIN_PA10D_SERCOM2_PAD2                     _UINT32_(10)
#define MUX_PA10D_SERCOM2_PAD2                     _UINT32_(3) 
#define PINMUX_PA10D_SERCOM2_PAD2                  ((PIN_PA10D_SERCOM2_PAD2 << 16) | MUX_PA10D_SERCOM2_PAD2)
#define PORT_PA10D_SERCOM2_PAD2                    (_UINT32_(1) << 10)

#define PIN_PA20D_SERCOM2_PAD2                     _UINT32_(20)
#define MUX_PA20D_SERCOM2_PAD2                     _UINT32_(3) 
#define PINMUX_PA20D_SERCOM2_PAD2                  ((PIN_PA20D_SERCOM2_PAD2 << 16) | MUX_PA20D_SERCOM2_PAD2)
#define PORT_PA20D_SERCOM2_PAD2                    (_UINT32_(1) << 20)

#define PIN_PA24D_SERCOM2_PAD2                     _UINT32_(24)
#define MUX_PA24D_SERCOM2_PAD2                     _UINT32_(3) 
#define PINMUX_PA24D_SERCOM2_PAD2                  ((PIN_PA24D_SERCOM2_PAD2 << 16) | MUX_PA24D_SERCOM2_PAD2)
#define PORT_PA24D_SERCOM2_PAD2                    (_UINT32_(1) << 24)

#define PIN_PA14C_SERCOM2_PAD2                     _UINT32_(14)
#define MUX_PA14C_SERCOM2_PAD2                     _UINT32_(2) 
#define PINMUX_PA14C_SERCOM2_PAD2                  ((PIN_PA14C_SERCOM2_PAD2 << 16) | MUX_PA14C_SERCOM2_PAD2)
#define PORT_PA14C_SERCOM2_PAD2                    (_UINT32_(1) << 14)

#define PIN_PA11D_SERCOM2_PAD3                     _UINT32_(11)
#define MUX_PA11D_SERCOM2_PAD3                     _UINT32_(3) 
#define PINMUX_PA11D_SERCOM2_PAD3                  ((PIN_PA11D_SERCOM2_PAD3 << 16) | MUX_PA11D_SERCOM2_PAD3)
#define PORT_PA11D_SERCOM2_PAD3                    (_UINT32_(1) << 11)

#define PIN_PA21D_SERCOM2_PAD3                     _UINT32_(21)
#define MUX_PA21D_SERCOM2_PAD3                     _UINT32_(3) 
#define PINMUX_PA21D_SERCOM2_PAD3                  ((PIN_PA21D_SERCOM2_PAD3 << 16) | MUX_PA21D_SERCOM2_PAD3)
#define PORT_PA21D_SERCOM2_PAD3                    (_UINT32_(1) << 21)

#define PIN_PA25D_SERCOM2_PAD3                     _UINT32_(25)
#define MUX_PA25D_SERCOM2_PAD3                     _UINT32_(3) 
#define PINMUX_PA25D_SERCOM2_PAD3                  ((PIN_PA25D_SERCOM2_PAD3 << 16) | MUX_PA25D_SERCOM2_PAD3)
#define PORT_PA25D_SERCOM2_PAD3                    (_UINT32_(1) << 25)

#define PIN_PA15C_SERCOM2_PAD3                     _UINT32_(15)
#define MUX_PA15C_SERCOM2_PAD3                     _UINT32_(2) 
#define PINMUX_PA15C_SERCOM2_PAD3                  ((PIN_PA15C_SERCOM2_PAD3 << 16) | MUX_PA15C_SERCOM2_PAD3)
#define PORT_PA15C_SERCOM2_PAD3                    (_UINT32_(1) << 15)

/* ========== PORT definition for SERCOM3 peripheral ========== */
#define PIN_PB08D_SERCOM3_PAD0                     _UINT32_(40)
#define MUX_PB08D_SERCOM3_PAD0                     _UINT32_(3) 
#define PINMUX_PB08D_SERCOM3_PAD0                  ((PIN_PB08D_SERCOM3_PAD0 << 16) | MUX_PB08D_SERCOM3_PAD0)
#define PORT_PB08D_SERCOM3_PAD0                    (_UINT32_(1) << 8)

#define PIN_PB02C_SERCOM3_PAD0                     _UINT32_(34)
#define MUX_PB02C_SERCOM3_PAD0                     _UINT32_(2) 
#define PINMUX_PB02C_SERCOM3_PAD0                  ((PIN_PB02C_SERCOM3_PAD0 << 16) | MUX_PB02C_SERCOM3_PAD0)
#define PORT_PB02C_SERCOM3_PAD0                    (_UINT32_(1) << 2)

#define PIN_PB09D_SERCOM3_PAD1                     _UINT32_(41)
#define MUX_PB09D_SERCOM3_PAD1                     _UINT32_(3) 
#define PINMUX_PB09D_SERCOM3_PAD1                  ((PIN_PB09D_SERCOM3_PAD1 << 16) | MUX_PB09D_SERCOM3_PAD1)
#define PORT_PB09D_SERCOM3_PAD1                    (_UINT32_(1) << 9)

#define PIN_PB03C_SERCOM3_PAD1                     _UINT32_(35)
#define MUX_PB03C_SERCOM3_PAD1                     _UINT32_(2) 
#define PINMUX_PB03C_SERCOM3_PAD1                  ((PIN_PB03C_SERCOM3_PAD1 << 16) | MUX_PB03C_SERCOM3_PAD1)
#define PORT_PB03C_SERCOM3_PAD1                    (_UINT32_(1) << 3)

#define PIN_PA20C_SERCOM3_PAD2                     _UINT32_(20)
#define MUX_PA20C_SERCOM3_PAD2                     _UINT32_(2) 
#define PINMUX_PA20C_SERCOM3_PAD2                  ((PIN_PA20C_SERCOM3_PAD2 << 16) | MUX_PA20C_SERCOM3_PAD2)
#define PORT_PA20C_SERCOM3_PAD2                    (_UINT32_(1) << 20)

#define PIN_PA21C_SERCOM3_PAD3                     _UINT32_(21)
#define MUX_PA21C_SERCOM3_PAD3                     _UINT32_(2) 
#define PINMUX_PA21C_SERCOM3_PAD3                  ((PIN_PA21C_SERCOM3_PAD3 << 16) | MUX_PA21C_SERCOM3_PAD3)
#define PORT_PA21C_SERCOM3_PAD3                    (_UINT32_(1) << 21)

/* ========== PORT definition for SERCOM4 peripheral ========== */
#define PIN_PA12D_SERCOM4_PAD0                     _UINT32_(12)
#define MUX_PA12D_SERCOM4_PAD0                     _UINT32_(3) 
#define PINMUX_PA12D_SERCOM4_PAD0                  ((PIN_PA12D_SERCOM4_PAD0 << 16) | MUX_PA12D_SERCOM4_PAD0)
#define PORT_PA12D_SERCOM4_PAD0                    (_UINT32_(1) << 12)

#define PIN_PA13D_SERCOM4_PAD1                     _UINT32_(13)
#define MUX_PA13D_SERCOM4_PAD1                     _UINT32_(3) 
#define PINMUX_PA13D_SERCOM4_PAD1                  ((PIN_PA13D_SERCOM4_PAD1 << 16) | MUX_PA13D_SERCOM4_PAD1)
#define PORT_PA13D_SERCOM4_PAD1                    (_UINT32_(1) << 13)

/* ========== PORT definition for SERCOM5 peripheral ========== */
#define PIN_PB02D_SERCOM5_PAD0                     _UINT32_(34)
#define MUX_PB02D_SERCOM5_PAD0                     _UINT32_(3) 
#define PINMUX_PB02D_SERCOM5_PAD0                  ((PIN_PB02D_SERCOM5_PAD0 << 16) | MUX_PB02D_SERCOM5_PAD0)
#define PORT_PB02D_SERCOM5_PAD0                    (_UINT32_(1) << 2)

#define PIN_PB03D_SERCOM5_PAD1                     _UINT32_(35)
#define MUX_PB03D_SERCOM5_PAD1                     _UINT32_(3) 
#define PINMUX_PB03D_SERCOM5_PAD1                  ((PIN_PB03D_SERCOM5_PAD1 << 16) | MUX_PB03D_SERCOM5_PAD1)
#define PORT_PB03D_SERCOM5_PAD1                    (_UINT32_(1) << 3)

#define PIN_PB22D_SERCOM5_PAD2                     _UINT32_(54)
#define MUX_PB22D_SERCOM5_PAD2                     _UINT32_(3) 
#define PINMUX_PB22D_SERCOM5_PAD2                  ((PIN_PB22D_SERCOM5_PAD2 << 16) | MUX_PB22D_SERCOM5_PAD2)
#define PORT_PB22D_SERCOM5_PAD2                    (_UINT32_(1) << 22)

#define PIN_PB23D_SERCOM5_PAD3                     _UINT32_(55)
#define MUX_PB23D_SERCOM5_PAD3                     _UINT32_(3) 
#define PINMUX_PB23D_SERCOM5_PAD3                  ((PIN_PB23D_SERCOM5_PAD3 << 16) | MUX_PB23D_SERCOM5_PAD3)
#define PORT_PB23D_SERCOM5_PAD3                    (_UINT32_(1) << 23)

/* ========== PORT definition for TC0 peripheral ========== */
#define PIN_PA22E_TC0_WO0                          _UINT32_(22)
#define MUX_PA22E_TC0_WO0                          _UINT32_(4) 
#define PINMUX_PA22E_TC0_WO0                       ((PIN_PA22E_TC0_WO0 << 16) | MUX_PA22E_TC0_WO0)
#define PORT_PA22E_TC0_WO0                         (_UINT32_(1) << 22)

#define PIN_PB08E_TC0_WO0                          _UINT32_(40)
#define MUX_PB08E_TC0_WO0                          _UINT32_(4) 
#define PINMUX_PB08E_TC0_WO0                       ((PIN_PB08E_TC0_WO0 << 16) | MUX_PB08E_TC0_WO0)
#define PORT_PB08E_TC0_WO0                         (_UINT32_(1) << 8)

#define PIN_PA14E_TC0_WO0                          _UINT32_(14)
#define MUX_PA14E_TC0_WO0                          _UINT32_(4) 
#define PINMUX_PA14E_TC0_WO0                       ((PIN_PA14E_TC0_WO0 << 16) | MUX_PA14E_TC0_WO0)
#define PORT_PA14E_TC0_WO0                         (_UINT32_(1) << 14)

#define PIN_PA23E_TC0_WO1                          _UINT32_(23)
#define MUX_PA23E_TC0_WO1                          _UINT32_(4) 
#define PINMUX_PA23E_TC0_WO1                       ((PIN_PA23E_TC0_WO1 << 16) | MUX_PA23E_TC0_WO1)
#define PORT_PA23E_TC0_WO1                         (_UINT32_(1) << 23)

#define PIN_PB09E_TC0_WO1                          _UINT32_(41)
#define MUX_PB09E_TC0_WO1                          _UINT32_(4) 
#define PINMUX_PB09E_TC0_WO1                       ((PIN_PB09E_TC0_WO1 << 16) | MUX_PB09E_TC0_WO1)
#define PORT_PB09E_TC0_WO1                         (_UINT32_(1) << 9)

#define PIN_PA15E_TC0_WO1                          _UINT32_(15)
#define MUX_PA15E_TC0_WO1                          _UINT32_(4) 
#define PINMUX_PA15E_TC0_WO1                       ((PIN_PA15E_TC0_WO1 << 16) | MUX_PA15E_TC0_WO1)
#define PORT_PA15E_TC0_WO1                         (_UINT32_(1) << 15)

/* ========== PORT definition for TC1 peripheral ========== */
#define PIN_PA20E_TC1_WO0                          _UINT32_(20)
#define MUX_PA20E_TC1_WO0                          _UINT32_(4) 
#define PINMUX_PA20E_TC1_WO0                       ((PIN_PA20E_TC1_WO0 << 16) | MUX_PA20E_TC1_WO0)
#define PORT_PA20E_TC1_WO0                         (_UINT32_(1) << 20)

#define PIN_PA24E_TC1_WO0                          _UINT32_(24)
#define MUX_PA24E_TC1_WO0                          _UINT32_(4) 
#define PINMUX_PA24E_TC1_WO0                       ((PIN_PA24E_TC1_WO0 << 16) | MUX_PA24E_TC1_WO0)
#define PORT_PA24E_TC1_WO0                         (_UINT32_(1) << 24)

#define PIN_PA25E_TC1_WO1                          _UINT32_(25)
#define MUX_PA25E_TC1_WO1                          _UINT32_(4) 
#define PINMUX_PA25E_TC1_WO1                       ((PIN_PA25E_TC1_WO1 << 16) | MUX_PA25E_TC1_WO1)
#define PORT_PA25E_TC1_WO1                         (_UINT32_(1) << 25)

/* ========== PORT definition for TC2 peripheral ========== */
#define PIN_PA18E_TC2_WO0                          _UINT32_(18)
#define MUX_PA18E_TC2_WO0                          _UINT32_(4) 
#define PINMUX_PA18E_TC2_WO0                       ((PIN_PA18E_TC2_WO0 << 16) | MUX_PA18E_TC2_WO0)
#define PORT_PA18E_TC2_WO0                         (_UINT32_(1) << 18)

#define PIN_PB02E_TC2_WO0                          _UINT32_(34)
#define MUX_PB02E_TC2_WO0                          _UINT32_(4) 
#define PINMUX_PB02E_TC2_WO0                       ((PIN_PB02E_TC2_WO0 << 16) | MUX_PB02E_TC2_WO0)
#define PORT_PB02E_TC2_WO0                         (_UINT32_(1) << 2)

#define PIN_PA19E_TC2_WO1                          _UINT32_(19)
#define MUX_PA19E_TC2_WO1                          _UINT32_(4) 
#define PINMUX_PA19E_TC2_WO1                       ((PIN_PA19E_TC2_WO1 << 16) | MUX_PA19E_TC2_WO1)
#define PORT_PA19E_TC2_WO1                         (_UINT32_(1) << 19)

#define PIN_PB03E_TC2_WO1                          _UINT32_(35)
#define MUX_PB03E_TC2_WO1                          _UINT32_(4) 
#define PINMUX_PB03E_TC2_WO1                       ((PIN_PB03E_TC2_WO1 << 16) | MUX_PB03E_TC2_WO1)
#define PORT_PB03E_TC2_WO1                         (_UINT32_(1) << 3)

/* ========== PORT definition for TCC0 peripheral ========== */
#define PIN_PA04E_TCC0_WO0                         _UINT32_(4) 
#define MUX_PA04E_TCC0_WO0                         _UINT32_(4) 
#define PINMUX_PA04E_TCC0_WO0                      ((PIN_PA04E_TCC0_WO0 << 16) | MUX_PA04E_TCC0_WO0)
#define PORT_PA04E_TCC0_WO0                        (_UINT32_(1) << 4)

#define PIN_PA08E_TCC0_WO0                         _UINT32_(8) 
#define MUX_PA08E_TCC0_WO0                         _UINT32_(4) 
#define PINMUX_PA08E_TCC0_WO0                      ((PIN_PA08E_TCC0_WO0 << 16) | MUX_PA08E_TCC0_WO0)
#define PORT_PA08E_TCC0_WO0                        (_UINT32_(1) << 8)

#define PIN_PA05E_TCC0_WO1                         _UINT32_(5) 
#define MUX_PA05E_TCC0_WO1                         _UINT32_(4) 
#define PINMUX_PA05E_TCC0_WO1                      ((PIN_PA05E_TCC0_WO1 << 16) | MUX_PA05E_TCC0_WO1)
#define PORT_PA05E_TCC0_WO1                        (_UINT32_(1) << 5)

#define PIN_PA09E_TCC0_WO1                         _UINT32_(9) 
#define MUX_PA09E_TCC0_WO1                         _UINT32_(4) 
#define PINMUX_PA09E_TCC0_WO1                      ((PIN_PA09E_TCC0_WO1 << 16) | MUX_PA09E_TCC0_WO1)
#define PORT_PA09E_TCC0_WO1                        (_UINT32_(1) << 9)

#define PIN_PA10J_TCC0_WO2                         _UINT32_(10)
#define MUX_PA10J_TCC0_WO2                         _UINT32_(9) 
#define PINMUX_PA10J_TCC0_WO2                      ((PIN_PA10J_TCC0_WO2 << 16) | MUX_PA10J_TCC0_WO2)
#define PORT_PA10J_TCC0_WO2                        (_UINT32_(1) << 10)

#define PIN_PA18J_TCC0_WO2                         _UINT32_(18)
#define MUX_PA18J_TCC0_WO2                         _UINT32_(9) 
#define PINMUX_PA18J_TCC0_WO2                      ((PIN_PA18J_TCC0_WO2 << 16) | MUX_PA18J_TCC0_WO2)
#define PORT_PA18J_TCC0_WO2                        (_UINT32_(1) << 18)

#define PIN_PA11J_TCC0_WO3                         _UINT32_(11)
#define MUX_PA11J_TCC0_WO3                         _UINT32_(9) 
#define PINMUX_PA11J_TCC0_WO3                      ((PIN_PA11J_TCC0_WO3 << 16) | MUX_PA11J_TCC0_WO3)
#define PORT_PA11J_TCC0_WO3                        (_UINT32_(1) << 11)

#define PIN_PA19J_TCC0_WO3                         _UINT32_(19)
#define MUX_PA19J_TCC0_WO3                         _UINT32_(9) 
#define PINMUX_PA19J_TCC0_WO3                      ((PIN_PA19J_TCC0_WO3 << 16) | MUX_PA19J_TCC0_WO3)
#define PORT_PA19J_TCC0_WO3                        (_UINT32_(1) << 19)

#define PIN_PA22J_TCC0_WO4                         _UINT32_(22)
#define MUX_PA22J_TCC0_WO4                         _UINT32_(9) 
#define PINMUX_PA22J_TCC0_WO4                      ((PIN_PA22J_TCC0_WO4 << 16) | MUX_PA22J_TCC0_WO4)
#define PORT_PA22J_TCC0_WO4                        (_UINT32_(1) << 22)

#define PIN_PA14J_TCC0_WO4                         _UINT32_(14)
#define MUX_PA14J_TCC0_WO4                         _UINT32_(9) 
#define PINMUX_PA14J_TCC0_WO4                      ((PIN_PA14J_TCC0_WO4 << 16) | MUX_PA14J_TCC0_WO4)
#define PORT_PA14J_TCC0_WO4                        (_UINT32_(1) << 14)

#define PIN_PA15J_TCC0_WO5                         _UINT32_(15)
#define MUX_PA15J_TCC0_WO5                         _UINT32_(9) 
#define PINMUX_PA15J_TCC0_WO5                      ((PIN_PA15J_TCC0_WO5 << 16) | MUX_PA15J_TCC0_WO5)
#define PORT_PA15J_TCC0_WO5                        (_UINT32_(1) << 15)

#define PIN_PA23J_TCC0_WO5                         _UINT32_(23)
#define MUX_PA23J_TCC0_WO5                         _UINT32_(9) 
#define PINMUX_PA23J_TCC0_WO5                      ((PIN_PA23J_TCC0_WO5 << 16) | MUX_PA23J_TCC0_WO5)
#define PORT_PA23J_TCC0_WO5                        (_UINT32_(1) << 23)

#define PIN_PA12J_TCC0_WO6                         _UINT32_(12)
#define MUX_PA12J_TCC0_WO6                         _UINT32_(9) 
#define PINMUX_PA12J_TCC0_WO6                      ((PIN_PA12J_TCC0_WO6 << 16) | MUX_PA12J_TCC0_WO6)
#define PORT_PA12J_TCC0_WO6                        (_UINT32_(1) << 12)

#define PIN_PA16J_TCC0_WO6                         _UINT32_(16)
#define MUX_PA16J_TCC0_WO6                         _UINT32_(9) 
#define PINMUX_PA16J_TCC0_WO6                      ((PIN_PA16J_TCC0_WO6 << 16) | MUX_PA16J_TCC0_WO6)
#define PORT_PA16J_TCC0_WO6                        (_UINT32_(1) << 16)

#define PIN_PA20J_TCC0_WO6                         _UINT32_(20)
#define MUX_PA20J_TCC0_WO6                         _UINT32_(9) 
#define PINMUX_PA20J_TCC0_WO6                      ((PIN_PA20J_TCC0_WO6 << 16) | MUX_PA20J_TCC0_WO6)
#define PORT_PA20J_TCC0_WO6                        (_UINT32_(1) << 20)

#define PIN_PA13J_TCC0_WO7                         _UINT32_(13)
#define MUX_PA13J_TCC0_WO7                         _UINT32_(9) 
#define PINMUX_PA13J_TCC0_WO7                      ((PIN_PA13J_TCC0_WO7 << 16) | MUX_PA13J_TCC0_WO7)
#define PORT_PA13J_TCC0_WO7                        (_UINT32_(1) << 13)

#define PIN_PA17J_TCC0_WO7                         _UINT32_(17)
#define MUX_PA17J_TCC0_WO7                         _UINT32_(9) 
#define PINMUX_PA17J_TCC0_WO7                      ((PIN_PA17J_TCC0_WO7 << 16) | MUX_PA17J_TCC0_WO7)
#define PORT_PA17J_TCC0_WO7                        (_UINT32_(1) << 17)

#define PIN_PA21J_TCC0_WO7                         _UINT32_(21)
#define MUX_PA21J_TCC0_WO7                         _UINT32_(9) 
#define PINMUX_PA21J_TCC0_WO7                      ((PIN_PA21J_TCC0_WO7 << 16) | MUX_PA21J_TCC0_WO7)
#define PORT_PA21J_TCC0_WO7                        (_UINT32_(1) << 21)

/* ========== PORT definition for TCC1 peripheral ========== */
#define PIN_PA06E_TCC1_WO0                         _UINT32_(6) 
#define MUX_PA06E_TCC1_WO0                         _UINT32_(4) 
#define PINMUX_PA06E_TCC1_WO0                      ((PIN_PA06E_TCC1_WO0 << 16) | MUX_PA06E_TCC1_WO0)
#define PORT_PA06E_TCC1_WO0                        (_UINT32_(1) << 6)

#define PIN_PA10E_TCC1_WO0                         _UINT32_(10)
#define MUX_PA10E_TCC1_WO0                         _UINT32_(4) 
#define PINMUX_PA10E_TCC1_WO0                      ((PIN_PA10E_TCC1_WO0 << 16) | MUX_PA10E_TCC1_WO0)
#define PORT_PA10E_TCC1_WO0                        (_UINT32_(1) << 10)

#define PIN_PA30E_TCC1_WO0                         _UINT32_(30)
#define MUX_PA30E_TCC1_WO0                         _UINT32_(4) 
#define PINMUX_PA30E_TCC1_WO0                      ((PIN_PA30E_TCC1_WO0 << 16) | MUX_PA30E_TCC1_WO0)
#define PORT_PA30E_TCC1_WO0                        (_UINT32_(1) << 30)

#define PIN_PA07E_TCC1_WO1                         _UINT32_(7) 
#define MUX_PA07E_TCC1_WO1                         _UINT32_(4) 
#define PINMUX_PA07E_TCC1_WO1                      ((PIN_PA07E_TCC1_WO1 << 16) | MUX_PA07E_TCC1_WO1)
#define PORT_PA07E_TCC1_WO1                        (_UINT32_(1) << 7)

#define PIN_PA11E_TCC1_WO1                         _UINT32_(11)
#define MUX_PA11E_TCC1_WO1                         _UINT32_(4) 
#define PINMUX_PA11E_TCC1_WO1                      ((PIN_PA11E_TCC1_WO1 << 16) | MUX_PA11E_TCC1_WO1)
#define PORT_PA11E_TCC1_WO1                        (_UINT32_(1) << 11)

#define PIN_PA31E_TCC1_WO1                         _UINT32_(31)
#define MUX_PA31E_TCC1_WO1                         _UINT32_(4) 
#define PINMUX_PA31E_TCC1_WO1                      ((PIN_PA31E_TCC1_WO1 << 16) | MUX_PA31E_TCC1_WO1)
#define PORT_PA31E_TCC1_WO1                        (_UINT32_(1) << 31)

#define PIN_PA08J_TCC1_WO2                         _UINT32_(8) 
#define MUX_PA08J_TCC1_WO2                         _UINT32_(9) 
#define PINMUX_PA08J_TCC1_WO2                      ((PIN_PA08J_TCC1_WO2 << 16) | MUX_PA08J_TCC1_WO2)
#define PORT_PA08J_TCC1_WO2                        (_UINT32_(1) << 8)

#define PIN_PA24J_TCC1_WO2                         _UINT32_(24)
#define MUX_PA24J_TCC1_WO2                         _UINT32_(9) 
#define PINMUX_PA24J_TCC1_WO2                      ((PIN_PA24J_TCC1_WO2 << 16) | MUX_PA24J_TCC1_WO2)
#define PORT_PA24J_TCC1_WO2                        (_UINT32_(1) << 24)

#define PIN_PA09J_TCC1_WO3                         _UINT32_(9) 
#define MUX_PA09J_TCC1_WO3                         _UINT32_(9) 
#define PINMUX_PA09J_TCC1_WO3                      ((PIN_PA09J_TCC1_WO3 << 16) | MUX_PA09J_TCC1_WO3)
#define PORT_PA09J_TCC1_WO3                        (_UINT32_(1) << 9)

#define PIN_PA25J_TCC1_WO3                         _UINT32_(25)
#define MUX_PA25J_TCC1_WO3                         _UINT32_(9) 
#define PINMUX_PA25J_TCC1_WO3                      ((PIN_PA25J_TCC1_WO3 << 16) | MUX_PA25J_TCC1_WO3)
#define PORT_PA25J_TCC1_WO3                        (_UINT32_(1) << 25)

/* ========== PORT definition for TCC2 peripheral ========== */
#define PIN_PA12E_TCC2_WO0                         _UINT32_(12)
#define MUX_PA12E_TCC2_WO0                         _UINT32_(4) 
#define PINMUX_PA12E_TCC2_WO0                      ((PIN_PA12E_TCC2_WO0 << 16) | MUX_PA12E_TCC2_WO0)
#define PORT_PA12E_TCC2_WO0                        (_UINT32_(1) << 12)

#define PIN_PA16E_TCC2_WO0                         _UINT32_(16)
#define MUX_PA16E_TCC2_WO0                         _UINT32_(4) 
#define PINMUX_PA16E_TCC2_WO0                      ((PIN_PA16E_TCC2_WO0 << 16) | MUX_PA16E_TCC2_WO0)
#define PORT_PA16E_TCC2_WO0                        (_UINT32_(1) << 16)

#define PIN_PA00E_TCC2_WO0                         _UINT32_(0) 
#define MUX_PA00E_TCC2_WO0                         _UINT32_(4) 
#define PINMUX_PA00E_TCC2_WO0                      ((PIN_PA00E_TCC2_WO0 << 16) | MUX_PA00E_TCC2_WO0)
#define PORT_PA00E_TCC2_WO0                        (_UINT32_(1) << 0)

#define PIN_PA13E_TCC2_WO1                         _UINT32_(13)
#define MUX_PA13E_TCC2_WO1                         _UINT32_(4) 
#define PINMUX_PA13E_TCC2_WO1                      ((PIN_PA13E_TCC2_WO1 << 16) | MUX_PA13E_TCC2_WO1)
#define PORT_PA13E_TCC2_WO1                        (_UINT32_(1) << 13)

#define PIN_PA17E_TCC2_WO1                         _UINT32_(17)
#define MUX_PA17E_TCC2_WO1                         _UINT32_(4) 
#define PINMUX_PA17E_TCC2_WO1                      ((PIN_PA17E_TCC2_WO1 << 16) | MUX_PA17E_TCC2_WO1)
#define PORT_PA17E_TCC2_WO1                        (_UINT32_(1) << 17)

#define PIN_PA01E_TCC2_WO1                         _UINT32_(1) 
#define MUX_PA01E_TCC2_WO1                         _UINT32_(4) 
#define PINMUX_PA01E_TCC2_WO1                      ((PIN_PA01E_TCC2_WO1 << 16) | MUX_PA01E_TCC2_WO1)
#define PORT_PA01E_TCC2_WO1                        (_UINT32_(1) << 1)

/* ========== PORT definition for TCC3 peripheral ========== */
#define PIN_PA02J_TCC3_WO0                         _UINT32_(2) 
#define MUX_PA02J_TCC3_WO0                         _UINT32_(9) 
#define PINMUX_PA02J_TCC3_WO0                      ((PIN_PA02J_TCC3_WO0 << 16) | MUX_PA02J_TCC3_WO0)
#define PORT_PA02J_TCC3_WO0                        (_UINT32_(1) << 2)

#define PIN_PB22J_TCC3_WO0                         _UINT32_(54)
#define MUX_PB22J_TCC3_WO0                         _UINT32_(9) 
#define PINMUX_PB22J_TCC3_WO0                      ((PIN_PB22J_TCC3_WO0 << 16) | MUX_PB22J_TCC3_WO0)
#define PORT_PB22J_TCC3_WO0                        (_UINT32_(1) << 22)

#define PIN_PA03J_TCC3_WO1                         _UINT32_(3) 
#define MUX_PA03J_TCC3_WO1                         _UINT32_(9) 
#define PINMUX_PA03J_TCC3_WO1                      ((PIN_PA03J_TCC3_WO1 << 16) | MUX_PA03J_TCC3_WO1)
#define PORT_PA03J_TCC3_WO1                        (_UINT32_(1) << 3)

#define PIN_PB23J_TCC3_WO1                         _UINT32_(55)
#define MUX_PB23J_TCC3_WO1                         _UINT32_(9) 
#define PINMUX_PB23J_TCC3_WO1                      ((PIN_PB23J_TCC3_WO1 << 16) | MUX_PB23J_TCC3_WO1)
#define PORT_PB23J_TCC3_WO1                        (_UINT32_(1) << 23)

#define PIN_PA04J_TCC3_WO2                         _UINT32_(4) 
#define MUX_PA04J_TCC3_WO2                         _UINT32_(9) 
#define PINMUX_PA04J_TCC3_WO2                      ((PIN_PA04J_TCC3_WO2 << 16) | MUX_PA04J_TCC3_WO2)
#define PORT_PA04J_TCC3_WO2                        (_UINT32_(1) << 4)

#define PIN_PB02J_TCC3_WO2                         _UINT32_(34)
#define MUX_PB02J_TCC3_WO2                         _UINT32_(9) 
#define PINMUX_PB02J_TCC3_WO2                      ((PIN_PB02J_TCC3_WO2 << 16) | MUX_PB02J_TCC3_WO2)
#define PORT_PB02J_TCC3_WO2                        (_UINT32_(1) << 2)

#define PIN_PA05J_TCC3_WO3                         _UINT32_(5) 
#define MUX_PA05J_TCC3_WO3                         _UINT32_(9) 
#define PINMUX_PA05J_TCC3_WO3                      ((PIN_PA05J_TCC3_WO3 << 16) | MUX_PA05J_TCC3_WO3)
#define PORT_PA05J_TCC3_WO3                        (_UINT32_(1) << 5)

#define PIN_PB03J_TCC3_WO3                         _UINT32_(35)
#define MUX_PB03J_TCC3_WO3                         _UINT32_(9) 
#define PINMUX_PB03J_TCC3_WO3                      ((PIN_PB03J_TCC3_WO3 << 16) | MUX_PB03J_TCC3_WO3)
#define PORT_PB03J_TCC3_WO3                        (_UINT32_(1) << 3)

#define PIN_PA06J_TCC3_WO4                         _UINT32_(6) 
#define MUX_PA06J_TCC3_WO4                         _UINT32_(9) 
#define PINMUX_PA06J_TCC3_WO4                      ((PIN_PA06J_TCC3_WO4 << 16) | MUX_PA06J_TCC3_WO4)
#define PORT_PA06J_TCC3_WO4                        (_UINT32_(1) << 6)

#define PIN_PA30J_TCC3_WO4                         _UINT32_(30)
#define MUX_PA30J_TCC3_WO4                         _UINT32_(9) 
#define PINMUX_PA30J_TCC3_WO4                      ((PIN_PA30J_TCC3_WO4 << 16) | MUX_PA30J_TCC3_WO4)
#define PORT_PA30J_TCC3_WO4                        (_UINT32_(1) << 30)

#define PIN_PA07J_TCC3_WO5                         _UINT32_(7) 
#define MUX_PA07J_TCC3_WO5                         _UINT32_(9) 
#define PINMUX_PA07J_TCC3_WO5                      ((PIN_PA07J_TCC3_WO5 << 16) | MUX_PA07J_TCC3_WO5)
#define PORT_PA07J_TCC3_WO5                        (_UINT32_(1) << 7)

#define PIN_PA31J_TCC3_WO5                         _UINT32_(31)
#define MUX_PA31J_TCC3_WO5                         _UINT32_(9) 
#define PINMUX_PA31J_TCC3_WO5                      ((PIN_PA31J_TCC3_WO5 << 16) | MUX_PA31J_TCC3_WO5)
#define PORT_PA31J_TCC3_WO5                        (_UINT32_(1) << 31)

#define PIN_PB08J_TCC3_WO6                         _UINT32_(40)
#define MUX_PB08J_TCC3_WO6                         _UINT32_(9) 
#define PINMUX_PB08J_TCC3_WO6                      ((PIN_PB08J_TCC3_WO6 << 16) | MUX_PB08J_TCC3_WO6)
#define PORT_PB08J_TCC3_WO6                        (_UINT32_(1) << 8)

#define PIN_PB09J_TCC3_WO7                         _UINT32_(41)
#define MUX_PB09J_TCC3_WO7                         _UINT32_(9) 
#define PINMUX_PB09J_TCC3_WO7                      ((PIN_PB09J_TCC3_WO7 << 16) | MUX_PB09J_TCC3_WO7)
#define PORT_PB09J_TCC3_WO7                        (_UINT32_(1) << 9)

/* ========== PORT definition for USB peripheral ========== */
#define PIN_PA24G_USB_DM                           _UINT32_(24)
#define MUX_PA24G_USB_DM                           _UINT32_(6) 
#define PINMUX_PA24G_USB_DM                        ((PIN_PA24G_USB_DM << 16) | MUX_PA24G_USB_DM)
#define PORT_PA24G_USB_DM                          (_UINT32_(1) << 24)

#define PIN_PA25G_USB_DP                           _UINT32_(25)
#define MUX_PA25G_USB_DP                           _UINT32_(6) 
#define PINMUX_PA25G_USB_DP                        ((PIN_PA25G_USB_DP << 16) | MUX_PA25G_USB_DP)
#define PORT_PA25G_USB_DP                          (_UINT32_(1) << 25)

#define PIN_PB22G_USB_SOF_1KHZ                     _UINT32_(54)
#define MUX_PB22G_USB_SOF_1KHZ                     _UINT32_(6) 
#define PINMUX_PB22G_USB_SOF_1KHZ                  ((PIN_PB22G_USB_SOF_1KHZ << 16) | MUX_PB22G_USB_SOF_1KHZ)
#define PORT_PB22G_USB_SOF_1KHZ                    (_UINT32_(1) << 22)



#endif /* _PIC32CM5164LS00048_GPIO_H_ */

