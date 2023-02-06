/*
 * Peripheral I/O description for PIC32CZ8110CA90208
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

/* file generated from device description version 2022-07-07T23:00:10Z */
#ifndef _PIC32CZ8110CA90208_GPIO_H_
#define _PIC32CZ8110CA90208_GPIO_H_

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
#define PIN_PA29                    (   29)  /**< Pin Number for PA29 */
#define PIN_PA30                    (   30)  /**< Pin Number for PA30 */
#define PIN_PA31                    (   31)  /**< Pin Number for PA31 */
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
#define PIN_PB27                    (   59)  /**< Pin Number for PB27 */
#define PIN_PB28                    (   60)  /**< Pin Number for PB28 */
#define PIN_PB29                    (   61)  /**< Pin Number for PB29 */
#define PIN_PB30                    (   62)  /**< Pin Number for PB30 */
#define PIN_PB31                    (   63)  /**< Pin Number for PB31 */
#define PIN_PC00                    (   64)  /**< Pin Number for PC00 */
#define PIN_PC01                    (   65)  /**< Pin Number for PC01 */
#define PIN_PC02                    (   66)  /**< Pin Number for PC02 */
#define PIN_PC03                    (   67)  /**< Pin Number for PC03 */
#define PIN_PC04                    (   68)  /**< Pin Number for PC04 */
#define PIN_PC05                    (   69)  /**< Pin Number for PC05 */
#define PIN_PC06                    (   70)  /**< Pin Number for PC06 */
#define PIN_PC07                    (   71)  /**< Pin Number for PC07 */
#define PIN_PC08                    (   72)  /**< Pin Number for PC08 */
#define PIN_PC09                    (   73)  /**< Pin Number for PC09 */
#define PIN_PC10                    (   74)  /**< Pin Number for PC10 */
#define PIN_PC11                    (   75)  /**< Pin Number for PC11 */
#define PIN_PC12                    (   76)  /**< Pin Number for PC12 */
#define PIN_PC13                    (   77)  /**< Pin Number for PC13 */
#define PIN_PC14                    (   78)  /**< Pin Number for PC14 */
#define PIN_PC15                    (   79)  /**< Pin Number for PC15 */
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
#define PIN_PD23                    (  119)  /**< Pin Number for PD23 */
#define PIN_PD24                    (  120)  /**< Pin Number for PD24 */
#define PIN_PD25                    (  121)  /**< Pin Number for PD25 */
#define PIN_PD26                    (  122)  /**< Pin Number for PD26 */
#define PIN_PD27                    (  123)  /**< Pin Number for PD27 */
#define PIN_PD28                    (  124)  /**< Pin Number for PD28 */
#define PIN_PD29                    (  125)  /**< Pin Number for PD29 */
#define PIN_PE00                    (  128)  /**< Pin Number for PE00 */
#define PIN_PE01                    (  129)  /**< Pin Number for PE01 */
#define PIN_PE02                    (  130)  /**< Pin Number for PE02 */
#define PIN_PE03                    (  131)  /**< Pin Number for PE03 */
#define PIN_PE04                    (  132)  /**< Pin Number for PE04 */
#define PIN_PE05                    (  133)  /**< Pin Number for PE05 */
#define PIN_PE06                    (  134)  /**< Pin Number for PE06 */
#define PIN_PE07                    (  135)  /**< Pin Number for PE07 */
#define PIN_PE08                    (  136)  /**< Pin Number for PE08 */
#define PIN_PE09                    (  137)  /**< Pin Number for PE09 */
#define PIN_PE10                    (  138)  /**< Pin Number for PE10 */
#define PIN_PE11                    (  139)  /**< Pin Number for PE11 */
#define PIN_PF00                    (  160)  /**< Pin Number for PF00 */
#define PIN_PF01                    (  161)  /**< Pin Number for PF01 */
#define PIN_PF02                    (  162)  /**< Pin Number for PF02 */
#define PIN_PF03                    (  163)  /**< Pin Number for PF03 */
#define PIN_PF04                    (  164)  /**< Pin Number for PF04 */
#define PIN_PF05                    (  165)  /**< Pin Number for PF05 */
#define PIN_PF06                    (  166)  /**< Pin Number for PF06 */
#define PIN_PF07                    (  167)  /**< Pin Number for PF07 */
#define PIN_PF08                    (  168)  /**< Pin Number for PF08 */
#define PIN_PG00                    (  192)  /**< Pin Number for PG00 */
#define PIN_PG01                    (  193)  /**< Pin Number for PG01 */
#define PIN_PG02                    (  194)  /**< Pin Number for PG02 */
#define PIN_PG03                    (  195)  /**< Pin Number for PG03 */
#define PIN_PG04                    (  196)  /**< Pin Number for PG04 */
#define PIN_PG05                    (  197)  /**< Pin Number for PG05 */
#define PIN_PG06                    (  198)  /**< Pin Number for PG06 */
#define PIN_PG07                    (  199)  /**< Pin Number for PG07 */
#define PIN_PG08                    (  200)  /**< Pin Number for PG08 */
#define PIN_PG09                    (  201)  /**< Pin Number for PG09 */
#define PIN_PG10                    (  202)  /**< Pin Number for PG10 */
#define PIN_PG11                    (  203)  /**< Pin Number for PG11 */

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
#define PORT_PA29                   (_UINT32_(1) << 29) /**< PORT mask for PA29 */
#define PORT_PA30                   (_UINT32_(1) << 30) /**< PORT mask for PA30 */
#define PORT_PA31                   (_UINT32_(1) << 31) /**< PORT mask for PA31 */
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
#define PORT_PB27                   (_UINT32_(1) << 27) /**< PORT mask for PB27 */
#define PORT_PB28                   (_UINT32_(1) << 28) /**< PORT mask for PB28 */
#define PORT_PB29                   (_UINT32_(1) << 29) /**< PORT mask for PB29 */
#define PORT_PB30                   (_UINT32_(1) << 30) /**< PORT mask for PB30 */
#define PORT_PB31                   (_UINT32_(1) << 31) /**< PORT mask for PB31 */
#define PORT_PC00                   (_UINT32_(1) << 0) /**< PORT mask for PC00 */
#define PORT_PC01                   (_UINT32_(1) << 1) /**< PORT mask for PC01 */
#define PORT_PC02                   (_UINT32_(1) << 2) /**< PORT mask for PC02 */
#define PORT_PC03                   (_UINT32_(1) << 3) /**< PORT mask for PC03 */
#define PORT_PC04                   (_UINT32_(1) << 4) /**< PORT mask for PC04 */
#define PORT_PC05                   (_UINT32_(1) << 5) /**< PORT mask for PC05 */
#define PORT_PC06                   (_UINT32_(1) << 6) /**< PORT mask for PC06 */
#define PORT_PC07                   (_UINT32_(1) << 7) /**< PORT mask for PC07 */
#define PORT_PC08                   (_UINT32_(1) << 8) /**< PORT mask for PC08 */
#define PORT_PC09                   (_UINT32_(1) << 9) /**< PORT mask for PC09 */
#define PORT_PC10                   (_UINT32_(1) << 10) /**< PORT mask for PC10 */
#define PORT_PC11                   (_UINT32_(1) << 11) /**< PORT mask for PC11 */
#define PORT_PC12                   (_UINT32_(1) << 12) /**< PORT mask for PC12 */
#define PORT_PC13                   (_UINT32_(1) << 13) /**< PORT mask for PC13 */
#define PORT_PC14                   (_UINT32_(1) << 14) /**< PORT mask for PC14 */
#define PORT_PC15                   (_UINT32_(1) << 15) /**< PORT mask for PC15 */
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
#define PORT_PC30                   (_UINT32_(1) << 30) /**< PORT mask for PC30 */
#define PORT_PC31                   (_UINT32_(1) << 31) /**< PORT mask for PC31 */
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
#define PORT_PD23                   (_UINT32_(1) << 23) /**< PORT mask for PD23 */
#define PORT_PD24                   (_UINT32_(1) << 24) /**< PORT mask for PD24 */
#define PORT_PD25                   (_UINT32_(1) << 25) /**< PORT mask for PD25 */
#define PORT_PD26                   (_UINT32_(1) << 26) /**< PORT mask for PD26 */
#define PORT_PD27                   (_UINT32_(1) << 27) /**< PORT mask for PD27 */
#define PORT_PD28                   (_UINT32_(1) << 28) /**< PORT mask for PD28 */
#define PORT_PD29                   (_UINT32_(1) << 29) /**< PORT mask for PD29 */
#define PORT_PE00                   (_UINT32_(1) << 0) /**< PORT mask for PE00 */
#define PORT_PE01                   (_UINT32_(1) << 1) /**< PORT mask for PE01 */
#define PORT_PE02                   (_UINT32_(1) << 2) /**< PORT mask for PE02 */
#define PORT_PE03                   (_UINT32_(1) << 3) /**< PORT mask for PE03 */
#define PORT_PE04                   (_UINT32_(1) << 4) /**< PORT mask for PE04 */
#define PORT_PE05                   (_UINT32_(1) << 5) /**< PORT mask for PE05 */
#define PORT_PE06                   (_UINT32_(1) << 6) /**< PORT mask for PE06 */
#define PORT_PE07                   (_UINT32_(1) << 7) /**< PORT mask for PE07 */
#define PORT_PE08                   (_UINT32_(1) << 8) /**< PORT mask for PE08 */
#define PORT_PE09                   (_UINT32_(1) << 9) /**< PORT mask for PE09 */
#define PORT_PE10                   (_UINT32_(1) << 10) /**< PORT mask for PE10 */
#define PORT_PE11                   (_UINT32_(1) << 11) /**< PORT mask for PE11 */
#define PORT_PF00                   (_UINT32_(1) << 0) /**< PORT mask for PF00 */
#define PORT_PF01                   (_UINT32_(1) << 1) /**< PORT mask for PF01 */
#define PORT_PF02                   (_UINT32_(1) << 2) /**< PORT mask for PF02 */
#define PORT_PF03                   (_UINT32_(1) << 3) /**< PORT mask for PF03 */
#define PORT_PF04                   (_UINT32_(1) << 4) /**< PORT mask for PF04 */
#define PORT_PF05                   (_UINT32_(1) << 5) /**< PORT mask for PF05 */
#define PORT_PF06                   (_UINT32_(1) << 6) /**< PORT mask for PF06 */
#define PORT_PF07                   (_UINT32_(1) << 7) /**< PORT mask for PF07 */
#define PORT_PF08                   (_UINT32_(1) << 8) /**< PORT mask for PF08 */
#define PORT_PG00                   (_UINT32_(1) << 0) /**< PORT mask for PG00 */
#define PORT_PG01                   (_UINT32_(1) << 1) /**< PORT mask for PG01 */
#define PORT_PG02                   (_UINT32_(1) << 2) /**< PORT mask for PG02 */
#define PORT_PG03                   (_UINT32_(1) << 3) /**< PORT mask for PG03 */
#define PORT_PG04                   (_UINT32_(1) << 4) /**< PORT mask for PG04 */
#define PORT_PG05                   (_UINT32_(1) << 5) /**< PORT mask for PG05 */
#define PORT_PG06                   (_UINT32_(1) << 6) /**< PORT mask for PG06 */
#define PORT_PG07                   (_UINT32_(1) << 7) /**< PORT mask for PG07 */
#define PORT_PG08                   (_UINT32_(1) << 8) /**< PORT mask for PG08 */
#define PORT_PG09                   (_UINT32_(1) << 9) /**< PORT mask for PG09 */
#define PORT_PG10                   (_UINT32_(1) << 10) /**< PORT mask for PG10 */
#define PORT_PG11                   (_UINT32_(1) << 11) /**< PORT mask for PG11 */

/* ========== PORT definition for AC peripheral ========== */
#define PIN_PB01B_AC_AIN0                          _UINT32_(33)
#define MUX_PB01B_AC_AIN0                          _UINT32_(1) 
#define PINMUX_PB01B_AC_AIN0                       ((PIN_PB01B_AC_AIN0 << 16) | MUX_PB01B_AC_AIN0)
#define PORT_PB01B_AC_AIN0                         (_UINT32_(1) << 1)

#define PIN_PB00B_AC_AIN1                          _UINT32_(32)
#define MUX_PB00B_AC_AIN1                          _UINT32_(1) 
#define PINMUX_PB00B_AC_AIN1                       ((PIN_PB00B_AC_AIN1 << 16) | MUX_PB00B_AC_AIN1)
#define PORT_PB00B_AC_AIN1                         (_UINT32_(1) << 0)

#define PIN_PA20B_AC_AIN2                          _UINT32_(20)
#define MUX_PA20B_AC_AIN2                          _UINT32_(1) 
#define PINMUX_PA20B_AC_AIN2                       ((PIN_PA20B_AC_AIN2 << 16) | MUX_PA20B_AC_AIN2)
#define PORT_PA20B_AC_AIN2                         (_UINT32_(1) << 20)

#define PIN_PA19B_AC_AIN3                          _UINT32_(19)
#define MUX_PA19B_AC_AIN3                          _UINT32_(1) 
#define PINMUX_PA19B_AC_AIN3                       ((PIN_PA19B_AC_AIN3 << 16) | MUX_PA19B_AC_AIN3)
#define PORT_PA19B_AC_AIN3                         (_UINT32_(1) << 19)

#define PIN_PC07B_AC_CMP0                          _UINT32_(71)
#define MUX_PC07B_AC_CMP0                          _UINT32_(1) 
#define PINMUX_PC07B_AC_CMP0                       ((PIN_PC07B_AC_CMP0 << 16) | MUX_PC07B_AC_CMP0)
#define PORT_PC07B_AC_CMP0                         (_UINT32_(1) << 7)

#define PIN_PC06B_AC_CMP1                          _UINT32_(70)
#define MUX_PC06B_AC_CMP1                          _UINT32_(1) 
#define PINMUX_PC06B_AC_CMP1                       ((PIN_PC06B_AC_CMP1 << 16) | MUX_PC06B_AC_CMP1)
#define PORT_PC06B_AC_CMP1                         (_UINT32_(1) << 6)

/* ========== PORT definition for ADC peripheral ========== */
#define PIN_PA17B_ADC_VINM16                       _UINT32_(17)
#define MUX_PA17B_ADC_VINM16                       _UINT32_(1) 
#define PINMUX_PA17B_ADC_VINM16                    ((PIN_PA17B_ADC_VINM16 << 16) | MUX_PA17B_ADC_VINM16)
#define PORT_PA17B_ADC_VINM16                      (_UINT32_(1) << 17)

#define PIN_PA15B_ADC_VINM18                       _UINT32_(15)
#define MUX_PA15B_ADC_VINM18                       _UINT32_(1) 
#define PINMUX_PA15B_ADC_VINM18                    ((PIN_PA15B_ADC_VINM18 << 16) | MUX_PA15B_ADC_VINM18)
#define PORT_PA15B_ADC_VINM18                      (_UINT32_(1) << 15)

#define PIN_PA28B_ADC_VINM20                       _UINT32_(28)
#define MUX_PA28B_ADC_VINM20                       _UINT32_(1) 
#define PINMUX_PA28B_ADC_VINM20                    ((PIN_PA28B_ADC_VINM20 << 16) | MUX_PA28B_ADC_VINM20)
#define PORT_PA28B_ADC_VINM20                      (_UINT32_(1) << 28)

#define PIN_PA13B_ADC_VINM24                       _UINT32_(13)
#define MUX_PA13B_ADC_VINM24                       _UINT32_(1) 
#define PINMUX_PA13B_ADC_VINM24                    ((PIN_PA13B_ADC_VINM24 << 16) | MUX_PA13B_ADC_VINM24)
#define PORT_PA13B_ADC_VINM24                      (_UINT32_(1) << 13)

#define PIN_PA11B_ADC_VINM26                       _UINT32_(11)
#define MUX_PA11B_ADC_VINM26                       _UINT32_(1) 
#define PINMUX_PA11B_ADC_VINM26                    ((PIN_PA11B_ADC_VINM26 << 16) | MUX_PA11B_ADC_VINM26)
#define PORT_PA11B_ADC_VINM26                      (_UINT32_(1) << 11)

#define PIN_PA26B_ADC_VINM28                       _UINT32_(26)
#define MUX_PA26B_ADC_VINM28                       _UINT32_(1) 
#define PINMUX_PA26B_ADC_VINM28                    ((PIN_PA26B_ADC_VINM28 << 16) | MUX_PA26B_ADC_VINM28)
#define PORT_PA26B_ADC_VINM28                      (_UINT32_(1) << 26)

#define PIN_PA09B_ADC_VINM32                       _UINT32_(9) 
#define MUX_PA09B_ADC_VINM32                       _UINT32_(1) 
#define PINMUX_PA09B_ADC_VINM32                    ((PIN_PA09B_ADC_VINM32 << 16) | MUX_PA09B_ADC_VINM32)
#define PORT_PA09B_ADC_VINM32                      (_UINT32_(1) << 9)

#define PIN_PA07B_ADC_VINM34                       _UINT32_(7) 
#define MUX_PA07B_ADC_VINM34                       _UINT32_(1) 
#define PINMUX_PA07B_ADC_VINM34                    ((PIN_PA07B_ADC_VINM34 << 16) | MUX_PA07B_ADC_VINM34)
#define PORT_PA07B_ADC_VINM34                      (_UINT32_(1) << 7)

#define PIN_PA24B_ADC_VINM36                       _UINT32_(24)
#define MUX_PA24B_ADC_VINM36                       _UINT32_(1) 
#define PINMUX_PA24B_ADC_VINM36                    ((PIN_PA24B_ADC_VINM36 << 16) | MUX_PA24B_ADC_VINM36)
#define PORT_PA24B_ADC_VINM36                      (_UINT32_(1) << 24)

#define PIN_PB03B_ADC_VINP0                        _UINT32_(35)
#define MUX_PB03B_ADC_VINP0                        _UINT32_(1) 
#define PINMUX_PB03B_ADC_VINP0                     ((PIN_PB03B_ADC_VINP0 << 16) | MUX_PB03B_ADC_VINP0)
#define PORT_PB03B_ADC_VINP0                       (_UINT32_(1) << 3)

#define PIN_PB02B_ADC_VINP1                        _UINT32_(34)
#define MUX_PB02B_ADC_VINP1                        _UINT32_(1) 
#define PINMUX_PB02B_ADC_VINP1                     ((PIN_PB02B_ADC_VINP1 << 16) | MUX_PB02B_ADC_VINP1)
#define PORT_PB02B_ADC_VINP1                       (_UINT32_(1) << 2)

#define PIN_PB01B_ADC_VINP2                        _UINT32_(33)
#define MUX_PB01B_ADC_VINP2                        _UINT32_(1) 
#define PINMUX_PB01B_ADC_VINP2                     ((PIN_PB01B_ADC_VINP2 << 16) | MUX_PB01B_ADC_VINP2)
#define PORT_PB01B_ADC_VINP2                       (_UINT32_(1) << 1)

#define PIN_PB00B_ADC_VINP3                        _UINT32_(32)
#define MUX_PB00B_ADC_VINP3                        _UINT32_(1) 
#define PINMUX_PB00B_ADC_VINP3                     ((PIN_PB00B_ADC_VINP3 << 16) | MUX_PB00B_ADC_VINP3)
#define PORT_PB00B_ADC_VINP3                       (_UINT32_(1) << 0)

#define PIN_PA20B_ADC_VINP4                        _UINT32_(20)
#define MUX_PA20B_ADC_VINP4                        _UINT32_(1) 
#define PINMUX_PA20B_ADC_VINP4                     ((PIN_PA20B_ADC_VINP4 << 16) | MUX_PA20B_ADC_VINP4)
#define PORT_PA20B_ADC_VINP4                       (_UINT32_(1) << 20)

#define PIN_PA19B_ADC_VINP5                        _UINT32_(19)
#define MUX_PA19B_ADC_VINP5                        _UINT32_(1) 
#define PINMUX_PA19B_ADC_VINP5                     ((PIN_PA19B_ADC_VINP5 << 16) | MUX_PA19B_ADC_VINP5)
#define PORT_PA19B_ADC_VINP5                       (_UINT32_(1) << 19)

#define PIN_PB18B_ADC_VINP6                        _UINT32_(50)
#define MUX_PB18B_ADC_VINP6                        _UINT32_(1) 
#define PINMUX_PB18B_ADC_VINP6                     ((PIN_PB18B_ADC_VINP6 << 16) | MUX_PB18B_ADC_VINP6)
#define PORT_PB18B_ADC_VINP6                       (_UINT32_(1) << 18)

#define PIN_PB19B_ADC_VINP7                        _UINT32_(51)
#define MUX_PB19B_ADC_VINP7                        _UINT32_(1) 
#define PINMUX_PB19B_ADC_VINP7                     ((PIN_PB19B_ADC_VINP7 << 16) | MUX_PB19B_ADC_VINP7)
#define PORT_PB19B_ADC_VINP7                       (_UINT32_(1) << 19)

#define PIN_PB20B_ADC_VINP8                        _UINT32_(52)
#define MUX_PB20B_ADC_VINP8                        _UINT32_(1) 
#define PINMUX_PB20B_ADC_VINP8                     ((PIN_PB20B_ADC_VINP8 << 16) | MUX_PB20B_ADC_VINP8)
#define PORT_PB20B_ADC_VINP8                       (_UINT32_(1) << 20)

#define PIN_PE03B_ADC_VINP9                        _UINT32_(131)
#define MUX_PE03B_ADC_VINP9                        _UINT32_(1) 
#define PINMUX_PE03B_ADC_VINP9                     ((PIN_PE03B_ADC_VINP9 << 16) | MUX_PE03B_ADC_VINP9)
#define PORT_PE03B_ADC_VINP9                       (_UINT32_(1) << 3)

#define PIN_PE06B_ADC_VINP10                       _UINT32_(134)
#define MUX_PE06B_ADC_VINP10                       _UINT32_(1) 
#define PINMUX_PE06B_ADC_VINP10                    ((PIN_PE06B_ADC_VINP10 << 16) | MUX_PE06B_ADC_VINP10)
#define PORT_PE06B_ADC_VINP10                      (_UINT32_(1) << 6)

#define PIN_PE07B_ADC_VINP11                       _UINT32_(135)
#define MUX_PE07B_ADC_VINP11                       _UINT32_(1) 
#define PINMUX_PE07B_ADC_VINP11                    ((PIN_PE07B_ADC_VINP11 << 16) | MUX_PE07B_ADC_VINP11)
#define PORT_PE07B_ADC_VINP11                      (_UINT32_(1) << 7)

#define PIN_PE08B_ADC_VINP12                       _UINT32_(136)
#define MUX_PE08B_ADC_VINP12                       _UINT32_(1) 
#define PINMUX_PE08B_ADC_VINP12                    ((PIN_PE08B_ADC_VINP12 << 16) | MUX_PE08B_ADC_VINP12)
#define PORT_PE08B_ADC_VINP12                      (_UINT32_(1) << 8)

#define PIN_PE09B_ADC_VINP13                       _UINT32_(137)
#define MUX_PE09B_ADC_VINP13                       _UINT32_(1) 
#define PINMUX_PE09B_ADC_VINP13                    ((PIN_PE09B_ADC_VINP13 << 16) | MUX_PE09B_ADC_VINP13)
#define PORT_PE09B_ADC_VINP13                      (_UINT32_(1) << 9)

#define PIN_PE10B_ADC_VINP14                       _UINT32_(138)
#define MUX_PE10B_ADC_VINP14                       _UINT32_(1) 
#define PINMUX_PE10B_ADC_VINP14                    ((PIN_PE10B_ADC_VINP14 << 16) | MUX_PE10B_ADC_VINP14)
#define PORT_PE10B_ADC_VINP14                      (_UINT32_(1) << 10)

#define PIN_PE11B_ADC_VINP15                       _UINT32_(139)
#define MUX_PE11B_ADC_VINP15                       _UINT32_(1) 
#define PINMUX_PE11B_ADC_VINP15                    ((PIN_PE11B_ADC_VINP15 << 16) | MUX_PE11B_ADC_VINP15)
#define PORT_PE11B_ADC_VINP15                      (_UINT32_(1) << 11)

#define PIN_PA18B_ADC_VINP16                       _UINT32_(18)
#define MUX_PA18B_ADC_VINP16                       _UINT32_(1) 
#define PINMUX_PA18B_ADC_VINP16                    ((PIN_PA18B_ADC_VINP16 << 16) | MUX_PA18B_ADC_VINP16)
#define PORT_PA18B_ADC_VINP16                      (_UINT32_(1) << 18)

#define PIN_PA17B_ADC_VINP17                       _UINT32_(17)
#define MUX_PA17B_ADC_VINP17                       _UINT32_(1) 
#define PINMUX_PA17B_ADC_VINP17                    ((PIN_PA17B_ADC_VINP17 << 16) | MUX_PA17B_ADC_VINP17)
#define PORT_PA17B_ADC_VINP17                      (_UINT32_(1) << 17)

#define PIN_PA16B_ADC_VINP18                       _UINT32_(16)
#define MUX_PA16B_ADC_VINP18                       _UINT32_(1) 
#define PINMUX_PA16B_ADC_VINP18                    ((PIN_PA16B_ADC_VINP18 << 16) | MUX_PA16B_ADC_VINP18)
#define PORT_PA16B_ADC_VINP18                      (_UINT32_(1) << 16)

#define PIN_PA15B_ADC_VINP19                       _UINT32_(15)
#define MUX_PA15B_ADC_VINP19                       _UINT32_(1) 
#define PINMUX_PA15B_ADC_VINP19                    ((PIN_PA15B_ADC_VINP19 << 16) | MUX_PA15B_ADC_VINP19)
#define PORT_PA15B_ADC_VINP19                      (_UINT32_(1) << 15)

#define PIN_PA29B_ADC_VINP20                       _UINT32_(29)
#define MUX_PA29B_ADC_VINP20                       _UINT32_(1) 
#define PINMUX_PA29B_ADC_VINP20                    ((PIN_PA29B_ADC_VINP20 << 16) | MUX_PA29B_ADC_VINP20)
#define PORT_PA29B_ADC_VINP20                      (_UINT32_(1) << 29)

#define PIN_PA28B_ADC_VINP21                       _UINT32_(28)
#define MUX_PA28B_ADC_VINP21                       _UINT32_(1) 
#define PINMUX_PA28B_ADC_VINP21                    ((PIN_PA28B_ADC_VINP21 << 16) | MUX_PA28B_ADC_VINP21)
#define PORT_PA28B_ADC_VINP21                      (_UINT32_(1) << 28)

#define PIN_PA14B_ADC_VINP24                       _UINT32_(14)
#define MUX_PA14B_ADC_VINP24                       _UINT32_(1) 
#define PINMUX_PA14B_ADC_VINP24                    ((PIN_PA14B_ADC_VINP24 << 16) | MUX_PA14B_ADC_VINP24)
#define PORT_PA14B_ADC_VINP24                      (_UINT32_(1) << 14)

#define PIN_PA13B_ADC_VINP25                       _UINT32_(13)
#define MUX_PA13B_ADC_VINP25                       _UINT32_(1) 
#define PINMUX_PA13B_ADC_VINP25                    ((PIN_PA13B_ADC_VINP25 << 16) | MUX_PA13B_ADC_VINP25)
#define PORT_PA13B_ADC_VINP25                      (_UINT32_(1) << 13)

#define PIN_PA12B_ADC_VINP26                       _UINT32_(12)
#define MUX_PA12B_ADC_VINP26                       _UINT32_(1) 
#define PINMUX_PA12B_ADC_VINP26                    ((PIN_PA12B_ADC_VINP26 << 16) | MUX_PA12B_ADC_VINP26)
#define PORT_PA12B_ADC_VINP26                      (_UINT32_(1) << 12)

#define PIN_PA11B_ADC_VINP27                       _UINT32_(11)
#define MUX_PA11B_ADC_VINP27                       _UINT32_(1) 
#define PINMUX_PA11B_ADC_VINP27                    ((PIN_PA11B_ADC_VINP27 << 16) | MUX_PA11B_ADC_VINP27)
#define PORT_PA11B_ADC_VINP27                      (_UINT32_(1) << 11)

#define PIN_PA27B_ADC_VINP28                       _UINT32_(27)
#define MUX_PA27B_ADC_VINP28                       _UINT32_(1) 
#define PINMUX_PA27B_ADC_VINP28                    ((PIN_PA27B_ADC_VINP28 << 16) | MUX_PA27B_ADC_VINP28)
#define PORT_PA27B_ADC_VINP28                      (_UINT32_(1) << 27)

#define PIN_PA26B_ADC_VINP29                       _UINT32_(26)
#define MUX_PA26B_ADC_VINP29                       _UINT32_(1) 
#define PINMUX_PA26B_ADC_VINP29                    ((PIN_PA26B_ADC_VINP29 << 16) | MUX_PA26B_ADC_VINP29)
#define PORT_PA26B_ADC_VINP29                      (_UINT32_(1) << 26)

#define PIN_PA10B_ADC_VINP32                       _UINT32_(10)
#define MUX_PA10B_ADC_VINP32                       _UINT32_(1) 
#define PINMUX_PA10B_ADC_VINP32                    ((PIN_PA10B_ADC_VINP32 << 16) | MUX_PA10B_ADC_VINP32)
#define PORT_PA10B_ADC_VINP32                      (_UINT32_(1) << 10)

#define PIN_PA09B_ADC_VINP33                       _UINT32_(9) 
#define MUX_PA09B_ADC_VINP33                       _UINT32_(1) 
#define PINMUX_PA09B_ADC_VINP33                    ((PIN_PA09B_ADC_VINP33 << 16) | MUX_PA09B_ADC_VINP33)
#define PORT_PA09B_ADC_VINP33                      (_UINT32_(1) << 9)

#define PIN_PA08B_ADC_VINP34                       _UINT32_(8) 
#define MUX_PA08B_ADC_VINP34                       _UINT32_(1) 
#define PINMUX_PA08B_ADC_VINP34                    ((PIN_PA08B_ADC_VINP34 << 16) | MUX_PA08B_ADC_VINP34)
#define PORT_PA08B_ADC_VINP34                      (_UINT32_(1) << 8)

#define PIN_PA07B_ADC_VINP35                       _UINT32_(7) 
#define MUX_PA07B_ADC_VINP35                       _UINT32_(1) 
#define PINMUX_PA07B_ADC_VINP35                    ((PIN_PA07B_ADC_VINP35 << 16) | MUX_PA07B_ADC_VINP35)
#define PORT_PA07B_ADC_VINP35                      (_UINT32_(1) << 7)

#define PIN_PA25B_ADC_VINP36                       _UINT32_(25)
#define MUX_PA25B_ADC_VINP36                       _UINT32_(1) 
#define PINMUX_PA25B_ADC_VINP36                    ((PIN_PA25B_ADC_VINP36 << 16) | MUX_PA25B_ADC_VINP36)
#define PORT_PA25B_ADC_VINP36                      (_UINT32_(1) << 25)

#define PIN_PA24B_ADC_VINP37                       _UINT32_(24)
#define MUX_PA24B_ADC_VINP37                       _UINT32_(1) 
#define PINMUX_PA24B_ADC_VINP37                    ((PIN_PA24B_ADC_VINP37 << 16) | MUX_PA24B_ADC_VINP37)
#define PORT_PA24B_ADC_VINP37                      (_UINT32_(1) << 24)

/* ========== PORT definition for BSDAP peripheral ========== */
#define PIN_PC20G_BSDAP_TCK_SWCLK                  _UINT32_(84)
#define MUX_PC20G_BSDAP_TCK_SWCLK                  _UINT32_(6) 
#define PINMUX_PC20G_BSDAP_TCK_SWCLK               ((PIN_PC20G_BSDAP_TCK_SWCLK << 16) | MUX_PC20G_BSDAP_TCK_SWCLK)
#define PORT_PC20G_BSDAP_TCK_SWCLK                 (_UINT32_(1) << 20)

#define PIN_PC17G_BSDAP_TDI                        _UINT32_(81)
#define MUX_PC17G_BSDAP_TDI                        _UINT32_(6) 
#define PINMUX_PC17G_BSDAP_TDI                     ((PIN_PC17G_BSDAP_TDI << 16) | MUX_PC17G_BSDAP_TDI)
#define PORT_PC17G_BSDAP_TDI                       (_UINT32_(1) << 17)

#define PIN_PC19G_BSDAP_TDO                        _UINT32_(83)
#define MUX_PC19G_BSDAP_TDO                        _UINT32_(6) 
#define PINMUX_PC19G_BSDAP_TDO                     ((PIN_PC19G_BSDAP_TDO << 16) | MUX_PC19G_BSDAP_TDO)
#define PORT_PC19G_BSDAP_TDO                       (_UINT32_(1) << 19)

#define PIN_PC18G_BSDAP_TMS_SWDIO                  _UINT32_(82)
#define MUX_PC18G_BSDAP_TMS_SWDIO                  _UINT32_(6) 
#define PINMUX_PC18G_BSDAP_TMS_SWDIO               ((PIN_PC18G_BSDAP_TMS_SWDIO << 16) | MUX_PC18G_BSDAP_TMS_SWDIO)
#define PORT_PC18G_BSDAP_TMS_SWDIO                 (_UINT32_(1) << 18)

/* ========== PORT definition for CAN0 peripheral ========== */
#define PIN_PC04H_CAN0_RX                          _UINT32_(68)
#define MUX_PC04H_CAN0_RX                          _UINT32_(7) 
#define PINMUX_PC04H_CAN0_RX                       ((PIN_PC04H_CAN0_RX << 16) | MUX_PC04H_CAN0_RX)
#define PORT_PC04H_CAN0_RX                         (_UINT32_(1) << 4)

#define PIN_PC19H_CAN0_RX                          _UINT32_(83)
#define MUX_PC19H_CAN0_RX                          _UINT32_(7) 
#define PINMUX_PC19H_CAN0_RX                       ((PIN_PC19H_CAN0_RX << 16) | MUX_PC19H_CAN0_RX)
#define PORT_PC19H_CAN0_RX                         (_UINT32_(1) << 19)

#define PIN_PC05H_CAN0_TX                          _UINT32_(69)
#define MUX_PC05H_CAN0_TX                          _UINT32_(7) 
#define PINMUX_PC05H_CAN0_TX                       ((PIN_PC05H_CAN0_TX << 16) | MUX_PC05H_CAN0_TX)
#define PORT_PC05H_CAN0_TX                         (_UINT32_(1) << 5)

#define PIN_PC20H_CAN0_TX                          _UINT32_(84)
#define MUX_PC20H_CAN0_TX                          _UINT32_(7) 
#define PINMUX_PC20H_CAN0_TX                       ((PIN_PC20H_CAN0_TX << 16) | MUX_PC20H_CAN0_TX)
#define PORT_PC20H_CAN0_TX                         (_UINT32_(1) << 20)

/* ========== PORT definition for CAN1 peripheral ========== */
#define PIN_PC06H_CAN1_RX                          _UINT32_(70)
#define MUX_PC06H_CAN1_RX                          _UINT32_(7) 
#define PINMUX_PC06H_CAN1_RX                       ((PIN_PC06H_CAN1_RX << 16) | MUX_PC06H_CAN1_RX)
#define PORT_PC06H_CAN1_RX                         (_UINT32_(1) << 6)

#define PIN_PD08H_CAN1_RX                          _UINT32_(104)
#define MUX_PD08H_CAN1_RX                          _UINT32_(7) 
#define PINMUX_PD08H_CAN1_RX                       ((PIN_PD08H_CAN1_RX << 16) | MUX_PD08H_CAN1_RX)
#define PORT_PD08H_CAN1_RX                         (_UINT32_(1) << 8)

#define PIN_PC07H_CAN1_TX                          _UINT32_(71)
#define MUX_PC07H_CAN1_TX                          _UINT32_(7) 
#define PINMUX_PC07H_CAN1_TX                       ((PIN_PC07H_CAN1_TX << 16) | MUX_PC07H_CAN1_TX)
#define PORT_PC07H_CAN1_TX                         (_UINT32_(1) << 7)

#define PIN_PD09H_CAN1_TX                          _UINT32_(105)
#define MUX_PD09H_CAN1_TX                          _UINT32_(7) 
#define PINMUX_PD09H_CAN1_TX                       ((PIN_PD09H_CAN1_TX << 16) | MUX_PD09H_CAN1_TX)
#define PORT_PD09H_CAN1_TX                         (_UINT32_(1) << 9)

/* ========== PORT definition for CAN2 peripheral ========== */
#define PIN_PC25H_CAN2_RX                          _UINT32_(89)
#define MUX_PC25H_CAN2_RX                          _UINT32_(7) 
#define PINMUX_PC25H_CAN2_RX                       ((PIN_PC25H_CAN2_RX << 16) | MUX_PC25H_CAN2_RX)
#define PORT_PC25H_CAN2_RX                         (_UINT32_(1) << 25)

#define PIN_PC26H_CAN2_TX                          _UINT32_(90)
#define MUX_PC26H_CAN2_TX                          _UINT32_(7) 
#define PINMUX_PC26H_CAN2_TX                       ((PIN_PC26H_CAN2_TX << 16) | MUX_PC26H_CAN2_TX)
#define PORT_PC26H_CAN2_TX                         (_UINT32_(1) << 26)

/* ========== PORT definition for CAN3 peripheral ========== */
#define PIN_PC29H_CAN3_RX                          _UINT32_(93)
#define MUX_PC29H_CAN3_RX                          _UINT32_(7) 
#define PINMUX_PC29H_CAN3_RX                       ((PIN_PC29H_CAN3_RX << 16) | MUX_PC29H_CAN3_RX)
#define PORT_PC29H_CAN3_RX                         (_UINT32_(1) << 29)

#define PIN_PD13H_CAN3_TX                          _UINT32_(109)
#define MUX_PD13H_CAN3_TX                          _UINT32_(7) 
#define PINMUX_PD13H_CAN3_TX                       ((PIN_PD13H_CAN3_TX << 16) | MUX_PD13H_CAN3_TX)
#define PORT_PD13H_CAN3_TX                         (_UINT32_(1) << 13)

/* ========== PORT definition for CAN4 peripheral ========== */
#define PIN_PA30H_CAN4_RX                          _UINT32_(30)
#define MUX_PA30H_CAN4_RX                          _UINT32_(7) 
#define PINMUX_PA30H_CAN4_RX                       ((PIN_PA30H_CAN4_RX << 16) | MUX_PA30H_CAN4_RX)
#define PORT_PA30H_CAN4_RX                         (_UINT32_(1) << 30)

#define PIN_PA31H_CAN4_TX                          _UINT32_(31)
#define MUX_PA31H_CAN4_TX                          _UINT32_(7) 
#define PINMUX_PA31H_CAN4_TX                       ((PIN_PA31H_CAN4_TX << 16) | MUX_PA31H_CAN4_TX)
#define PORT_PA31H_CAN4_TX                         (_UINT32_(1) << 31)

/* ========== PORT definition for CAN5 peripheral ========== */
#define PIN_PD23H_CAN5_RX                          _UINT32_(119)
#define MUX_PD23H_CAN5_RX                          _UINT32_(7) 
#define PINMUX_PD23H_CAN5_RX                       ((PIN_PD23H_CAN5_RX << 16) | MUX_PD23H_CAN5_RX)
#define PORT_PD23H_CAN5_RX                         (_UINT32_(1) << 23)

#define PIN_PA21H_CAN5_TX                          _UINT32_(21)
#define MUX_PA21H_CAN5_TX                          _UINT32_(7) 
#define PINMUX_PA21H_CAN5_TX                       ((PIN_PA21H_CAN5_TX << 16) | MUX_PA21H_CAN5_TX)
#define PORT_PA21H_CAN5_TX                         (_UINT32_(1) << 21)

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

#define PIN_PC15E_EBI_A5                           _UINT32_(79)
#define MUX_PC15E_EBI_A5                           _UINT32_(4) 
#define PINMUX_PC15E_EBI_A5                        ((PIN_PC15E_EBI_A5 << 16) | MUX_PC15E_EBI_A5)
#define PORT_PC15E_EBI_A5                          (_UINT32_(1) << 15)

#define PIN_PC14E_EBI_A6                           _UINT32_(78)
#define MUX_PC14E_EBI_A6                           _UINT32_(4) 
#define PINMUX_PC14E_EBI_A6                        ((PIN_PC14E_EBI_A6 << 16) | MUX_PC14E_EBI_A6)
#define PORT_PC14E_EBI_A6                          (_UINT32_(1) << 14)

#define PIN_PC29E_EBI_A7                           _UINT32_(93)
#define MUX_PC29E_EBI_A7                           _UINT32_(4) 
#define PINMUX_PC29E_EBI_A7                        ((PIN_PC29E_EBI_A7 << 16) | MUX_PC29E_EBI_A7)
#define PORT_PC29E_EBI_A7                          (_UINT32_(1) << 29)

#define PIN_PC13E_EBI_A8                           _UINT32_(77)
#define MUX_PC13E_EBI_A8                           _UINT32_(4) 
#define PINMUX_PC13E_EBI_A8                        ((PIN_PC13E_EBI_A8 << 16) | MUX_PC13E_EBI_A8)
#define PORT_PC13E_EBI_A8                          (_UINT32_(1) << 13)

#define PIN_PC12E_EBI_A9                           _UINT32_(76)
#define MUX_PC12E_EBI_A9                           _UINT32_(4) 
#define PINMUX_PC12E_EBI_A9                        ((PIN_PC12E_EBI_A9 << 16) | MUX_PC12E_EBI_A9)
#define PORT_PC12E_EBI_A9                          (_UINT32_(1) << 12)

#define PIN_PC28E_EBI_A10                          _UINT32_(92)
#define MUX_PC28E_EBI_A10                          _UINT32_(4) 
#define PINMUX_PC28E_EBI_A10                       ((PIN_PC28E_EBI_A10 << 16) | MUX_PC28E_EBI_A10)
#define PORT_PC28E_EBI_A10                         (_UINT32_(1) << 28)

#define PIN_PG03E_EBI_A11                          _UINT32_(195)
#define MUX_PG03E_EBI_A11                          _UINT32_(4) 
#define PINMUX_PG03E_EBI_A11                       ((PIN_PG03E_EBI_A11 << 16) | MUX_PG03E_EBI_A11)
#define PORT_PG03E_EBI_A11                         (_UINT32_(1) << 3)

#define PIN_PC27E_EBI_A12                          _UINT32_(91)
#define MUX_PC27E_EBI_A12                          _UINT32_(4) 
#define PINMUX_PC27E_EBI_A12                       ((PIN_PC27E_EBI_A12 << 16) | MUX_PC27E_EBI_A12)
#define PORT_PC27E_EBI_A12                         (_UINT32_(1) << 27)

#define PIN_PC11E_EBI_A13                          _UINT32_(75)
#define MUX_PC11E_EBI_A13                          _UINT32_(4) 
#define PINMUX_PC11E_EBI_A13                       ((PIN_PC11E_EBI_A13 << 16) | MUX_PC11E_EBI_A13)
#define PORT_PC11E_EBI_A13                         (_UINT32_(1) << 11)

#define PIN_PC10E_EBI_A14                          _UINT32_(74)
#define MUX_PC10E_EBI_A14                          _UINT32_(4) 
#define PINMUX_PC10E_EBI_A14                       ((PIN_PC10E_EBI_A14 << 16) | MUX_PC10E_EBI_A14)
#define PORT_PC10E_EBI_A14                         (_UINT32_(1) << 10)

#define PIN_PG02E_EBI_A15                          _UINT32_(194)
#define MUX_PG02E_EBI_A15                          _UINT32_(4) 
#define PINMUX_PG02E_EBI_A15                       ((PIN_PG02E_EBI_A15 << 16) | MUX_PG02E_EBI_A15)
#define PORT_PG02E_EBI_A15                         (_UINT32_(1) << 2)

#define PIN_PG01E_EBI_A16                          _UINT32_(193)
#define MUX_PG01E_EBI_A16                          _UINT32_(4) 
#define PINMUX_PG01E_EBI_A16                       ((PIN_PG01E_EBI_A16 << 16) | MUX_PG01E_EBI_A16)
#define PORT_PG01E_EBI_A16                         (_UINT32_(1) << 1)

#define PIN_PG00E_EBI_A17                          _UINT32_(192)
#define MUX_PG00E_EBI_A17                          _UINT32_(4) 
#define PINMUX_PG00E_EBI_A17                       ((PIN_PG00E_EBI_A17 << 16) | MUX_PG00E_EBI_A17)
#define PORT_PG00E_EBI_A17                         (_UINT32_(1) << 0)

#define PIN_PC26E_EBI_A18                          _UINT32_(90)
#define MUX_PC26E_EBI_A18                          _UINT32_(4) 
#define PINMUX_PC26E_EBI_A18                       ((PIN_PC26E_EBI_A18 << 16) | MUX_PC26E_EBI_A18)
#define PORT_PC26E_EBI_A18                         (_UINT32_(1) << 26)

#define PIN_PC31E_EBI_A19                          _UINT32_(95)
#define MUX_PC31E_EBI_A19                          _UINT32_(4) 
#define PINMUX_PC31E_EBI_A19                       ((PIN_PC31E_EBI_A19 << 16) | MUX_PC31E_EBI_A19)
#define PORT_PC31E_EBI_A19                         (_UINT32_(1) << 31)

#define PIN_PC30E_EBI_A20                          _UINT32_(94)
#define MUX_PC30E_EBI_A20                          _UINT32_(4) 
#define PINMUX_PC30E_EBI_A20                       ((PIN_PC30E_EBI_A20 << 16) | MUX_PC30E_EBI_A20)
#define PORT_PC30E_EBI_A20                         (_UINT32_(1) << 30)

#define PIN_PC25E_EBI_A21                          _UINT32_(89)
#define MUX_PC25E_EBI_A21                          _UINT32_(4) 
#define PINMUX_PC25E_EBI_A21                       ((PIN_PC25E_EBI_A21 << 16) | MUX_PC25E_EBI_A21)
#define PORT_PC25E_EBI_A21                         (_UINT32_(1) << 25)

#define PIN_PC09E_EBI_A22                          _UINT32_(73)
#define MUX_PC09E_EBI_A22                          _UINT32_(4) 
#define PINMUX_PC09E_EBI_A22                       ((PIN_PC09E_EBI_A22 << 16) | MUX_PC09E_EBI_A22)
#define PORT_PC09E_EBI_A22                         (_UINT32_(1) << 9)

#define PIN_PC24E_EBI_A23                          _UINT32_(88)
#define MUX_PC24E_EBI_A23                          _UINT32_(4) 
#define PINMUX_PC24E_EBI_A23                       ((PIN_PC24E_EBI_A23 << 16) | MUX_PC24E_EBI_A23)
#define PORT_PC24E_EBI_A23                         (_UINT32_(1) << 24)

#define PIN_PD13E_EBI_D0                           _UINT32_(109)
#define MUX_PD13E_EBI_D0                           _UINT32_(4) 
#define PINMUX_PD13E_EBI_D0                        ((PIN_PD13E_EBI_D0 << 16) | MUX_PD13E_EBI_D0)
#define PORT_PD13E_EBI_D0                          (_UINT32_(1) << 13)

#define PIN_PD23E_EBI_D1                           _UINT32_(119)
#define MUX_PD23E_EBI_D1                           _UINT32_(4) 
#define PINMUX_PD23E_EBI_D1                        ((PIN_PD23E_EBI_D1 << 16) | MUX_PD23E_EBI_D1)
#define PORT_PD23E_EBI_D1                          (_UINT32_(1) << 23)

#define PIN_PD14E_EBI_D2                           _UINT32_(110)
#define MUX_PD14E_EBI_D2                           _UINT32_(4) 
#define PINMUX_PD14E_EBI_D2                        ((PIN_PD14E_EBI_D2 << 16) | MUX_PD14E_EBI_D2)
#define PORT_PD14E_EBI_D2                          (_UINT32_(1) << 14)

#define PIN_PD02E_EBI_D3                           _UINT32_(98)
#define MUX_PD02E_EBI_D3                           _UINT32_(4) 
#define PINMUX_PD02E_EBI_D3                        ((PIN_PD02E_EBI_D3 << 16) | MUX_PD02E_EBI_D3)
#define PORT_PD02E_EBI_D3                          (_UINT32_(1) << 2)

#define PIN_PD15E_EBI_D4                           _UINT32_(111)
#define MUX_PD15E_EBI_D4                           _UINT32_(4) 
#define PINMUX_PD15E_EBI_D4                        ((PIN_PD15E_EBI_D4 << 16) | MUX_PD15E_EBI_D4)
#define PORT_PD15E_EBI_D4                          (_UINT32_(1) << 15)

#define PIN_PD03E_EBI_D5                           _UINT32_(99)
#define MUX_PD03E_EBI_D5                           _UINT32_(4) 
#define PINMUX_PD03E_EBI_D5                        ((PIN_PD03E_EBI_D5 << 16) | MUX_PD03E_EBI_D5)
#define PORT_PD03E_EBI_D5                          (_UINT32_(1) << 3)

#define PIN_PD16E_EBI_D6                           _UINT32_(112)
#define MUX_PD16E_EBI_D6                           _UINT32_(4) 
#define PINMUX_PD16E_EBI_D6                        ((PIN_PD16E_EBI_D6 << 16) | MUX_PD16E_EBI_D6)
#define PORT_PD16E_EBI_D6                          (_UINT32_(1) << 16)

#define PIN_PD17E_EBI_D7                           _UINT32_(113)
#define MUX_PD17E_EBI_D7                           _UINT32_(4) 
#define PINMUX_PD17E_EBI_D7                        ((PIN_PD17E_EBI_D7 << 16) | MUX_PD17E_EBI_D7)
#define PORT_PD17E_EBI_D7                          (_UINT32_(1) << 17)

#define PIN_PD04E_EBI_D8                           _UINT32_(100)
#define MUX_PD04E_EBI_D8                           _UINT32_(4) 
#define PINMUX_PD04E_EBI_D8                        ((PIN_PD04E_EBI_D8 << 16) | MUX_PD04E_EBI_D8)
#define PORT_PD04E_EBI_D8                          (_UINT32_(1) << 4)

#define PIN_PD18E_EBI_D9                           _UINT32_(114)
#define MUX_PD18E_EBI_D9                           _UINT32_(4) 
#define PINMUX_PD18E_EBI_D9                        ((PIN_PD18E_EBI_D9 << 16) | MUX_PD18E_EBI_D9)
#define PORT_PD18E_EBI_D9                          (_UINT32_(1) << 18)

#define PIN_PD19E_EBI_D10                          _UINT32_(115)
#define MUX_PD19E_EBI_D10                          _UINT32_(4) 
#define PINMUX_PD19E_EBI_D10                       ((PIN_PD19E_EBI_D10 << 16) | MUX_PD19E_EBI_D10)
#define PORT_PD19E_EBI_D10                         (_UINT32_(1) << 19)

#define PIN_PD05E_EBI_D11                          _UINT32_(101)
#define MUX_PD05E_EBI_D11                          _UINT32_(4) 
#define PINMUX_PD05E_EBI_D11                       ((PIN_PD05E_EBI_D11 << 16) | MUX_PD05E_EBI_D11)
#define PORT_PD05E_EBI_D11                         (_UINT32_(1) << 5)

#define PIN_PD06E_EBI_D12                          _UINT32_(102)
#define MUX_PD06E_EBI_D12                          _UINT32_(4) 
#define PINMUX_PD06E_EBI_D12                       ((PIN_PD06E_EBI_D12 << 16) | MUX_PD06E_EBI_D12)
#define PORT_PD06E_EBI_D12                         (_UINT32_(1) << 6)

#define PIN_PD20E_EBI_D13                          _UINT32_(116)
#define MUX_PD20E_EBI_D13                          _UINT32_(4) 
#define PINMUX_PD20E_EBI_D13                       ((PIN_PD20E_EBI_D13 << 16) | MUX_PD20E_EBI_D13)
#define PORT_PD20E_EBI_D13                         (_UINT32_(1) << 20)

#define PIN_PD21E_EBI_D14                          _UINT32_(117)
#define MUX_PD21E_EBI_D14                          _UINT32_(4) 
#define PINMUX_PD21E_EBI_D14                       ((PIN_PD21E_EBI_D14 << 16) | MUX_PD21E_EBI_D14)
#define PORT_PD21E_EBI_D14                         (_UINT32_(1) << 21)

#define PIN_PD07E_EBI_D15                          _UINT32_(103)
#define MUX_PD07E_EBI_D15                          _UINT32_(4) 
#define PINMUX_PD07E_EBI_D15                       ((PIN_PD07E_EBI_D15 << 16) | MUX_PD07E_EBI_D15)
#define PORT_PD07E_EBI_D15                         (_UINT32_(1) << 7)

#define PIN_PC23E_EBI_NBS0_A0                      _UINT32_(87)
#define MUX_PC23E_EBI_NBS0_A0                      _UINT32_(4) 
#define PINMUX_PC23E_EBI_NBS0_A0                   ((PIN_PC23E_EBI_NBS0_A0 << 16) | MUX_PC23E_EBI_NBS0_A0)
#define PORT_PC23E_EBI_NBS0_A0                     (_UINT32_(1) << 23)

#define PIN_PC06E_EBI_NBS1_NWR1                    _UINT32_(70)
#define MUX_PC06E_EBI_NBS1_NWR1                    _UINT32_(4) 
#define PINMUX_PC06E_EBI_NBS1_NWR1                 ((PIN_PC06E_EBI_NBS1_NWR1 << 16) | MUX_PC06E_EBI_NBS1_NWR1)
#define PORT_PC06E_EBI_NBS1_NWR1                   (_UINT32_(1) << 6)

#define PIN_PC20E_EBI_NBS2_NWR2_A1                 _UINT32_(84)
#define MUX_PC20E_EBI_NBS2_NWR2_A1                 _UINT32_(4) 
#define PINMUX_PC20E_EBI_NBS2_NWR2_A1              ((PIN_PC20E_EBI_NBS2_NWR2_A1 << 16) | MUX_PC20E_EBI_NBS2_NWR2_A1)
#define PORT_PC20E_EBI_NBS2_NWR2_A1                (_UINT32_(1) << 20)

#define PIN_PC08E_EBI_NCS0                         _UINT32_(72)
#define MUX_PC08E_EBI_NCS0                         _UINT32_(4) 
#define PINMUX_PC08E_EBI_NCS0                      ((PIN_PC08E_EBI_NCS0 << 16) | MUX_PC08E_EBI_NCS0)
#define PORT_PC08E_EBI_NCS0                        (_UINT32_(1) << 8)

#define PIN_PC07E_EBI_NCS1                         _UINT32_(71)
#define MUX_PC07E_EBI_NCS1                         _UINT32_(4) 
#define PINMUX_PC07E_EBI_NCS1                      ((PIN_PC07E_EBI_NCS1 << 16) | MUX_PC07E_EBI_NCS1)
#define PORT_PC07E_EBI_NCS1                        (_UINT32_(1) << 7)

#define PIN_PC22E_EBI_NCS2                         _UINT32_(86)
#define MUX_PC22E_EBI_NCS2                         _UINT32_(4) 
#define PINMUX_PC22E_EBI_NCS2                      ((PIN_PC22E_EBI_NCS2 << 16) | MUX_PC22E_EBI_NCS2)
#define PORT_PC22E_EBI_NCS2                        (_UINT32_(1) << 22)

#define PIN_PC21E_EBI_NCS3                         _UINT32_(85)
#define MUX_PC21E_EBI_NCS3                         _UINT32_(4) 
#define PINMUX_PC21E_EBI_NCS3                      ((PIN_PC21E_EBI_NCS3 << 16) | MUX_PC21E_EBI_NCS3)
#define PORT_PC21E_EBI_NCS3                        (_UINT32_(1) << 21)

#define PIN_PC05E_EBI_NRD                          _UINT32_(69)
#define MUX_PC05E_EBI_NRD                          _UINT32_(4) 
#define PINMUX_PC05E_EBI_NRD                       ((PIN_PC05E_EBI_NRD << 16) | MUX_PC05E_EBI_NRD)
#define PORT_PC05E_EBI_NRD                         (_UINT32_(1) << 5)

#define PIN_PD08E_EBI_NWAIT                        _UINT32_(104)
#define MUX_PD08E_EBI_NWAIT                        _UINT32_(4) 
#define PINMUX_PD08E_EBI_NWAIT                     ((PIN_PD08E_EBI_NWAIT << 16) | MUX_PD08E_EBI_NWAIT)
#define PORT_PD08E_EBI_NWAIT                       (_UINT32_(1) << 8)

#define PIN_PC04E_EBI_NWE_NWR0                     _UINT32_(68)
#define MUX_PC04E_EBI_NWE_NWR0                     _UINT32_(4) 
#define PINMUX_PC04E_EBI_NWE_NWR0                  ((PIN_PC04E_EBI_NWE_NWR0 << 16) | MUX_PC04E_EBI_NWE_NWR0)
#define PORT_PC04E_EBI_NWE_NWR0                    (_UINT32_(1) << 4)

#define PIN_PG04E_EBI_NWE_NWR0                     _UINT32_(196)
#define MUX_PG04E_EBI_NWE_NWR0                     _UINT32_(4) 
#define PINMUX_PG04E_EBI_NWE_NWR0                  ((PIN_PG04E_EBI_NWE_NWR0 << 16) | MUX_PG04E_EBI_NWE_NWR0)
#define PORT_PG04E_EBI_NWE_NWR0                    (_UINT32_(1) << 4)

/* ========== PORT definition for EIC peripheral ========== */
#define PIN_PA00A_EIC_EXTINT0                      _UINT32_(0) 
#define MUX_PA00A_EIC_EXTINT0                      _UINT32_(0) 
#define PINMUX_PA00A_EIC_EXTINT0                   ((PIN_PA00A_EIC_EXTINT0 << 16) | MUX_PA00A_EIC_EXTINT0)
#define PORT_PA00A_EIC_EXTINT0                     (_UINT32_(1) << 0)
#define PIN_PA00A_EIC_EXTINT_NUM                   _UINT32_(0)  /* EIC signal: PIN_PA00 External Interrupt Line */

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

#define PIN_PD00A_EIC_EXTINT0                      _UINT32_(96)
#define MUX_PD00A_EIC_EXTINT0                      _UINT32_(0) 
#define PINMUX_PD00A_EIC_EXTINT0                   ((PIN_PD00A_EIC_EXTINT0 << 16) | MUX_PD00A_EIC_EXTINT0)
#define PORT_PD00A_EIC_EXTINT0                     (_UINT32_(1) << 0)
#define PIN_PD00A_EIC_EXTINT_NUM                   _UINT32_(0)  /* EIC signal: PIN_PD00 External Interrupt Line */

#define PIN_PD15A_EIC_EXTINT0                      _UINT32_(111)
#define MUX_PD15A_EIC_EXTINT0                      _UINT32_(0) 
#define PINMUX_PD15A_EIC_EXTINT0                   ((PIN_PD15A_EIC_EXTINT0 << 16) | MUX_PD15A_EIC_EXTINT0)
#define PORT_PD15A_EIC_EXTINT0                     (_UINT32_(1) << 15)
#define PIN_PD15A_EIC_EXTINT_NUM                   _UINT32_(0)  /* EIC signal: PIN_PD15 External Interrupt Line */

#define PIN_PE00A_EIC_EXTINT0                      _UINT32_(128)
#define MUX_PE00A_EIC_EXTINT0                      _UINT32_(0) 
#define PINMUX_PE00A_EIC_EXTINT0                   ((PIN_PE00A_EIC_EXTINT0 << 16) | MUX_PE00A_EIC_EXTINT0)
#define PORT_PE00A_EIC_EXTINT0                     (_UINT32_(1) << 0)
#define PIN_PE00A_EIC_EXTINT_NUM                   _UINT32_(0)  /* EIC signal: PIN_PE00 External Interrupt Line */

#define PIN_PG00A_EIC_EXTINT0                      _UINT32_(192)
#define MUX_PG00A_EIC_EXTINT0                      _UINT32_(0) 
#define PINMUX_PG00A_EIC_EXTINT0                   ((PIN_PG00A_EIC_EXTINT0 << 16) | MUX_PG00A_EIC_EXTINT0)
#define PORT_PG00A_EIC_EXTINT0                     (_UINT32_(1) << 0)
#define PIN_PG00A_EIC_EXTINT_NUM                   _UINT32_(0)  /* EIC signal: PIN_PG00 External Interrupt Line */

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

#define PIN_PC02A_EIC_EXTINT1                      _UINT32_(66)
#define MUX_PC02A_EIC_EXTINT1                      _UINT32_(0) 
#define PINMUX_PC02A_EIC_EXTINT1                   ((PIN_PC02A_EIC_EXTINT1 << 16) | MUX_PC02A_EIC_EXTINT1)
#define PORT_PC02A_EIC_EXTINT1                     (_UINT32_(1) << 2)
#define PIN_PC02A_EIC_EXTINT_NUM                   _UINT32_(1)  /* EIC signal: PIN_PC02 External Interrupt Line */

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

#define PIN_PD16A_EIC_EXTINT1                      _UINT32_(112)
#define MUX_PD16A_EIC_EXTINT1                      _UINT32_(0) 
#define PINMUX_PD16A_EIC_EXTINT1                   ((PIN_PD16A_EIC_EXTINT1 << 16) | MUX_PD16A_EIC_EXTINT1)
#define PORT_PD16A_EIC_EXTINT1                     (_UINT32_(1) << 16)
#define PIN_PD16A_EIC_EXTINT_NUM                   _UINT32_(1)  /* EIC signal: PIN_PD16 External Interrupt Line */

#define PIN_PE01A_EIC_EXTINT1                      _UINT32_(129)
#define MUX_PE01A_EIC_EXTINT1                      _UINT32_(0) 
#define PINMUX_PE01A_EIC_EXTINT1                   ((PIN_PE01A_EIC_EXTINT1 << 16) | MUX_PE01A_EIC_EXTINT1)
#define PORT_PE01A_EIC_EXTINT1                     (_UINT32_(1) << 1)
#define PIN_PE01A_EIC_EXTINT_NUM                   _UINT32_(1)  /* EIC signal: PIN_PE01 External Interrupt Line */

#define PIN_PF00A_EIC_EXTINT1                      _UINT32_(160)
#define MUX_PF00A_EIC_EXTINT1                      _UINT32_(0) 
#define PINMUX_PF00A_EIC_EXTINT1                   ((PIN_PF00A_EIC_EXTINT1 << 16) | MUX_PF00A_EIC_EXTINT1)
#define PORT_PF00A_EIC_EXTINT1                     (_UINT32_(1) << 0)
#define PIN_PF00A_EIC_EXTINT_NUM                   _UINT32_(1)  /* EIC signal: PIN_PF00 External Interrupt Line */

#define PIN_PF01A_EIC_EXTINT1                      _UINT32_(161)
#define MUX_PF01A_EIC_EXTINT1                      _UINT32_(0) 
#define PINMUX_PF01A_EIC_EXTINT1                   ((PIN_PF01A_EIC_EXTINT1 << 16) | MUX_PF01A_EIC_EXTINT1)
#define PORT_PF01A_EIC_EXTINT1                     (_UINT32_(1) << 1)
#define PIN_PF01A_EIC_EXTINT_NUM                   _UINT32_(1)  /* EIC signal: PIN_PF01 External Interrupt Line */

#define PIN_PG01A_EIC_EXTINT1                      _UINT32_(193)
#define MUX_PG01A_EIC_EXTINT1                      _UINT32_(0) 
#define PINMUX_PG01A_EIC_EXTINT1                   ((PIN_PG01A_EIC_EXTINT1 << 16) | MUX_PG01A_EIC_EXTINT1)
#define PORT_PG01A_EIC_EXTINT1                     (_UINT32_(1) << 1)
#define PIN_PG01A_EIC_EXTINT_NUM                   _UINT32_(1)  /* EIC signal: PIN_PG01 External Interrupt Line */

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

#define PIN_PC18A_EIC_EXTINT2                      _UINT32_(82)
#define MUX_PC18A_EIC_EXTINT2                      _UINT32_(0) 
#define PINMUX_PC18A_EIC_EXTINT2                   ((PIN_PC18A_EIC_EXTINT2 << 16) | MUX_PC18A_EIC_EXTINT2)
#define PORT_PC18A_EIC_EXTINT2                     (_UINT32_(1) << 18)
#define PIN_PC18A_EIC_EXTINT_NUM                   _UINT32_(2)  /* EIC signal: PIN_PC18 External Interrupt Line */

#define PIN_PD02A_EIC_EXTINT2                      _UINT32_(98)
#define MUX_PD02A_EIC_EXTINT2                      _UINT32_(0) 
#define PINMUX_PD02A_EIC_EXTINT2                   ((PIN_PD02A_EIC_EXTINT2 << 16) | MUX_PD02A_EIC_EXTINT2)
#define PORT_PD02A_EIC_EXTINT2                     (_UINT32_(1) << 2)
#define PIN_PD02A_EIC_EXTINT_NUM                   _UINT32_(2)  /* EIC signal: PIN_PD02 External Interrupt Line */

#define PIN_PD17A_EIC_EXTINT2                      _UINT32_(113)
#define MUX_PD17A_EIC_EXTINT2                      _UINT32_(0) 
#define PINMUX_PD17A_EIC_EXTINT2                   ((PIN_PD17A_EIC_EXTINT2 << 16) | MUX_PD17A_EIC_EXTINT2)
#define PORT_PD17A_EIC_EXTINT2                     (_UINT32_(1) << 17)
#define PIN_PD17A_EIC_EXTINT_NUM                   _UINT32_(2)  /* EIC signal: PIN_PD17 External Interrupt Line */

#define PIN_PE02A_EIC_EXTINT2                      _UINT32_(130)
#define MUX_PE02A_EIC_EXTINT2                      _UINT32_(0) 
#define PINMUX_PE02A_EIC_EXTINT2                   ((PIN_PE02A_EIC_EXTINT2 << 16) | MUX_PE02A_EIC_EXTINT2)
#define PORT_PE02A_EIC_EXTINT2                     (_UINT32_(1) << 2)
#define PIN_PE02A_EIC_EXTINT_NUM                   _UINT32_(2)  /* EIC signal: PIN_PE02 External Interrupt Line */

#define PIN_PF02A_EIC_EXTINT2                      _UINT32_(162)
#define MUX_PF02A_EIC_EXTINT2                      _UINT32_(0) 
#define PINMUX_PF02A_EIC_EXTINT2                   ((PIN_PF02A_EIC_EXTINT2 << 16) | MUX_PF02A_EIC_EXTINT2)
#define PORT_PF02A_EIC_EXTINT2                     (_UINT32_(1) << 2)
#define PIN_PF02A_EIC_EXTINT_NUM                   _UINT32_(2)  /* EIC signal: PIN_PF02 External Interrupt Line */

#define PIN_PG02A_EIC_EXTINT2                      _UINT32_(194)
#define MUX_PG02A_EIC_EXTINT2                      _UINT32_(0) 
#define PINMUX_PG02A_EIC_EXTINT2                   ((PIN_PG02A_EIC_EXTINT2 << 16) | MUX_PG02A_EIC_EXTINT2)
#define PORT_PG02A_EIC_EXTINT2                     (_UINT32_(1) << 2)
#define PIN_PG02A_EIC_EXTINT_NUM                   _UINT32_(2)  /* EIC signal: PIN_PG02 External Interrupt Line */

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

#define PIN_PD18A_EIC_EXTINT3                      _UINT32_(114)
#define MUX_PD18A_EIC_EXTINT3                      _UINT32_(0) 
#define PINMUX_PD18A_EIC_EXTINT3                   ((PIN_PD18A_EIC_EXTINT3 << 16) | MUX_PD18A_EIC_EXTINT3)
#define PORT_PD18A_EIC_EXTINT3                     (_UINT32_(1) << 18)
#define PIN_PD18A_EIC_EXTINT_NUM                   _UINT32_(3)  /* EIC signal: PIN_PD18 External Interrupt Line */

#define PIN_PE03A_EIC_EXTINT3                      _UINT32_(131)
#define MUX_PE03A_EIC_EXTINT3                      _UINT32_(0) 
#define PINMUX_PE03A_EIC_EXTINT3                   ((PIN_PE03A_EIC_EXTINT3 << 16) | MUX_PE03A_EIC_EXTINT3)
#define PORT_PE03A_EIC_EXTINT3                     (_UINT32_(1) << 3)
#define PIN_PE03A_EIC_EXTINT_NUM                   _UINT32_(3)  /* EIC signal: PIN_PE03 External Interrupt Line */

#define PIN_PF03A_EIC_EXTINT3                      _UINT32_(163)
#define MUX_PF03A_EIC_EXTINT3                      _UINT32_(0) 
#define PINMUX_PF03A_EIC_EXTINT3                   ((PIN_PF03A_EIC_EXTINT3 << 16) | MUX_PF03A_EIC_EXTINT3)
#define PORT_PF03A_EIC_EXTINT3                     (_UINT32_(1) << 3)
#define PIN_PF03A_EIC_EXTINT_NUM                   _UINT32_(3)  /* EIC signal: PIN_PF03 External Interrupt Line */

#define PIN_PG03A_EIC_EXTINT3                      _UINT32_(195)
#define MUX_PG03A_EIC_EXTINT3                      _UINT32_(0) 
#define PINMUX_PG03A_EIC_EXTINT3                   ((PIN_PG03A_EIC_EXTINT3 << 16) | MUX_PG03A_EIC_EXTINT3)
#define PORT_PG03A_EIC_EXTINT3                     (_UINT32_(1) << 3)
#define PIN_PG03A_EIC_EXTINT_NUM                   _UINT32_(3)  /* EIC signal: PIN_PG03 External Interrupt Line */

#define PIN_PA04A_EIC_EXTINT4                      _UINT32_(4) 
#define MUX_PA04A_EIC_EXTINT4                      _UINT32_(0) 
#define PINMUX_PA04A_EIC_EXTINT4                   ((PIN_PA04A_EIC_EXTINT4 << 16) | MUX_PA04A_EIC_EXTINT4)
#define PORT_PA04A_EIC_EXTINT4                     (_UINT32_(1) << 4)
#define PIN_PA04A_EIC_EXTINT_NUM                   _UINT32_(4)  /* EIC signal: PIN_PA04 External Interrupt Line */

#define PIN_PA05A_EIC_EXTINT4                      _UINT32_(5) 
#define MUX_PA05A_EIC_EXTINT4                      _UINT32_(0) 
#define PINMUX_PA05A_EIC_EXTINT4                   ((PIN_PA05A_EIC_EXTINT4 << 16) | MUX_PA05A_EIC_EXTINT4)
#define PORT_PA05A_EIC_EXTINT4                     (_UINT32_(1) << 5)
#define PIN_PA05A_EIC_EXTINT_NUM                   _UINT32_(4)  /* EIC signal: PIN_PA05 External Interrupt Line */

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

#define PIN_PD04A_EIC_EXTINT4                      _UINT32_(100)
#define MUX_PD04A_EIC_EXTINT4                      _UINT32_(0) 
#define PINMUX_PD04A_EIC_EXTINT4                   ((PIN_PD04A_EIC_EXTINT4 << 16) | MUX_PD04A_EIC_EXTINT4)
#define PORT_PD04A_EIC_EXTINT4                     (_UINT32_(1) << 4)
#define PIN_PD04A_EIC_EXTINT_NUM                   _UINT32_(4)  /* EIC signal: PIN_PD04 External Interrupt Line */

#define PIN_PD19A_EIC_EXTINT4                      _UINT32_(115)
#define MUX_PD19A_EIC_EXTINT4                      _UINT32_(0) 
#define PINMUX_PD19A_EIC_EXTINT4                   ((PIN_PD19A_EIC_EXTINT4 << 16) | MUX_PD19A_EIC_EXTINT4)
#define PORT_PD19A_EIC_EXTINT4                     (_UINT32_(1) << 19)
#define PIN_PD19A_EIC_EXTINT_NUM                   _UINT32_(4)  /* EIC signal: PIN_PD19 External Interrupt Line */

#define PIN_PE04A_EIC_EXTINT4                      _UINT32_(132)
#define MUX_PE04A_EIC_EXTINT4                      _UINT32_(0) 
#define PINMUX_PE04A_EIC_EXTINT4                   ((PIN_PE04A_EIC_EXTINT4 << 16) | MUX_PE04A_EIC_EXTINT4)
#define PORT_PE04A_EIC_EXTINT4                     (_UINT32_(1) << 4)
#define PIN_PE04A_EIC_EXTINT_NUM                   _UINT32_(4)  /* EIC signal: PIN_PE04 External Interrupt Line */

#define PIN_PF04A_EIC_EXTINT4                      _UINT32_(164)
#define MUX_PF04A_EIC_EXTINT4                      _UINT32_(0) 
#define PINMUX_PF04A_EIC_EXTINT4                   ((PIN_PF04A_EIC_EXTINT4 << 16) | MUX_PF04A_EIC_EXTINT4)
#define PORT_PF04A_EIC_EXTINT4                     (_UINT32_(1) << 4)
#define PIN_PF04A_EIC_EXTINT_NUM                   _UINT32_(4)  /* EIC signal: PIN_PF04 External Interrupt Line */

#define PIN_PG04A_EIC_EXTINT4                      _UINT32_(196)
#define MUX_PG04A_EIC_EXTINT4                      _UINT32_(0) 
#define PINMUX_PG04A_EIC_EXTINT4                   ((PIN_PG04A_EIC_EXTINT4 << 16) | MUX_PG04A_EIC_EXTINT4)
#define PORT_PG04A_EIC_EXTINT4                     (_UINT32_(1) << 4)
#define PIN_PG04A_EIC_EXTINT_NUM                   _UINT32_(4)  /* EIC signal: PIN_PG04 External Interrupt Line */

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

#define PIN_PD20A_EIC_EXTINT5                      _UINT32_(116)
#define MUX_PD20A_EIC_EXTINT5                      _UINT32_(0) 
#define PINMUX_PD20A_EIC_EXTINT5                   ((PIN_PD20A_EIC_EXTINT5 << 16) | MUX_PD20A_EIC_EXTINT5)
#define PORT_PD20A_EIC_EXTINT5                     (_UINT32_(1) << 20)
#define PIN_PD20A_EIC_EXTINT_NUM                   _UINT32_(5)  /* EIC signal: PIN_PD20 External Interrupt Line */

#define PIN_PE05A_EIC_EXTINT5                      _UINT32_(133)
#define MUX_PE05A_EIC_EXTINT5                      _UINT32_(0) 
#define PINMUX_PE05A_EIC_EXTINT5                   ((PIN_PE05A_EIC_EXTINT5 << 16) | MUX_PE05A_EIC_EXTINT5)
#define PORT_PE05A_EIC_EXTINT5                     (_UINT32_(1) << 5)
#define PIN_PE05A_EIC_EXTINT_NUM                   _UINT32_(5)  /* EIC signal: PIN_PE05 External Interrupt Line */

#define PIN_PF05A_EIC_EXTINT5                      _UINT32_(165)
#define MUX_PF05A_EIC_EXTINT5                      _UINT32_(0) 
#define PINMUX_PF05A_EIC_EXTINT5                   ((PIN_PF05A_EIC_EXTINT5 << 16) | MUX_PF05A_EIC_EXTINT5)
#define PORT_PF05A_EIC_EXTINT5                     (_UINT32_(1) << 5)
#define PIN_PF05A_EIC_EXTINT_NUM                   _UINT32_(5)  /* EIC signal: PIN_PF05 External Interrupt Line */

#define PIN_PG05A_EIC_EXTINT5                      _UINT32_(197)
#define MUX_PG05A_EIC_EXTINT5                      _UINT32_(0) 
#define PINMUX_PG05A_EIC_EXTINT5                   ((PIN_PG05A_EIC_EXTINT5 << 16) | MUX_PG05A_EIC_EXTINT5)
#define PORT_PG05A_EIC_EXTINT5                     (_UINT32_(1) << 5)
#define PIN_PG05A_EIC_EXTINT_NUM                   _UINT32_(5)  /* EIC signal: PIN_PG05 External Interrupt Line */

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

#define PIN_PD21A_EIC_EXTINT6                      _UINT32_(117)
#define MUX_PD21A_EIC_EXTINT6                      _UINT32_(0) 
#define PINMUX_PD21A_EIC_EXTINT6                   ((PIN_PD21A_EIC_EXTINT6 << 16) | MUX_PD21A_EIC_EXTINT6)
#define PORT_PD21A_EIC_EXTINT6                     (_UINT32_(1) << 21)
#define PIN_PD21A_EIC_EXTINT_NUM                   _UINT32_(6)  /* EIC signal: PIN_PD21 External Interrupt Line */

#define PIN_PE06A_EIC_EXTINT6                      _UINT32_(134)
#define MUX_PE06A_EIC_EXTINT6                      _UINT32_(0) 
#define PINMUX_PE06A_EIC_EXTINT6                   ((PIN_PE06A_EIC_EXTINT6 << 16) | MUX_PE06A_EIC_EXTINT6)
#define PORT_PE06A_EIC_EXTINT6                     (_UINT32_(1) << 6)
#define PIN_PE06A_EIC_EXTINT_NUM                   _UINT32_(6)  /* EIC signal: PIN_PE06 External Interrupt Line */

#define PIN_PF06A_EIC_EXTINT6                      _UINT32_(166)
#define MUX_PF06A_EIC_EXTINT6                      _UINT32_(0) 
#define PINMUX_PF06A_EIC_EXTINT6                   ((PIN_PF06A_EIC_EXTINT6 << 16) | MUX_PF06A_EIC_EXTINT6)
#define PORT_PF06A_EIC_EXTINT6                     (_UINT32_(1) << 6)
#define PIN_PF06A_EIC_EXTINT_NUM                   _UINT32_(6)  /* EIC signal: PIN_PF06 External Interrupt Line */

#define PIN_PG06A_EIC_EXTINT6                      _UINT32_(198)
#define MUX_PG06A_EIC_EXTINT6                      _UINT32_(0) 
#define PINMUX_PG06A_EIC_EXTINT6                   ((PIN_PG06A_EIC_EXTINT6 << 16) | MUX_PG06A_EIC_EXTINT6)
#define PORT_PG06A_EIC_EXTINT6                     (_UINT32_(1) << 6)
#define PIN_PG06A_EIC_EXTINT_NUM                   _UINT32_(6)  /* EIC signal: PIN_PG06 External Interrupt Line */

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

#define PIN_PD23A_EIC_EXTINT7                      _UINT32_(119)
#define MUX_PD23A_EIC_EXTINT7                      _UINT32_(0) 
#define PINMUX_PD23A_EIC_EXTINT7                   ((PIN_PD23A_EIC_EXTINT7 << 16) | MUX_PD23A_EIC_EXTINT7)
#define PORT_PD23A_EIC_EXTINT7                     (_UINT32_(1) << 23)
#define PIN_PD23A_EIC_EXTINT_NUM                   _UINT32_(7)  /* EIC signal: PIN_PD23 External Interrupt Line */

#define PIN_PE07A_EIC_EXTINT7                      _UINT32_(135)
#define MUX_PE07A_EIC_EXTINT7                      _UINT32_(0) 
#define PINMUX_PE07A_EIC_EXTINT7                   ((PIN_PE07A_EIC_EXTINT7 << 16) | MUX_PE07A_EIC_EXTINT7)
#define PORT_PE07A_EIC_EXTINT7                     (_UINT32_(1) << 7)
#define PIN_PE07A_EIC_EXTINT_NUM                   _UINT32_(7)  /* EIC signal: PIN_PE07 External Interrupt Line */

#define PIN_PF07A_EIC_EXTINT7                      _UINT32_(167)
#define MUX_PF07A_EIC_EXTINT7                      _UINT32_(0) 
#define PINMUX_PF07A_EIC_EXTINT7                   ((PIN_PF07A_EIC_EXTINT7 << 16) | MUX_PF07A_EIC_EXTINT7)
#define PORT_PF07A_EIC_EXTINT7                     (_UINT32_(1) << 7)
#define PIN_PF07A_EIC_EXTINT_NUM                   _UINT32_(7)  /* EIC signal: PIN_PF07 External Interrupt Line */

#define PIN_PG07A_EIC_EXTINT7                      _UINT32_(199)
#define MUX_PG07A_EIC_EXTINT7                      _UINT32_(0) 
#define PINMUX_PG07A_EIC_EXTINT7                   ((PIN_PG07A_EIC_EXTINT7 << 16) | MUX_PG07A_EIC_EXTINT7)
#define PORT_PG07A_EIC_EXTINT7                     (_UINT32_(1) << 7)
#define PIN_PG07A_EIC_EXTINT_NUM                   _UINT32_(7)  /* EIC signal: PIN_PG07 External Interrupt Line */

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

#define PIN_PC08A_EIC_EXTINT8                      _UINT32_(72)
#define MUX_PC08A_EIC_EXTINT8                      _UINT32_(0) 
#define PINMUX_PC08A_EIC_EXTINT8                   ((PIN_PC08A_EIC_EXTINT8 << 16) | MUX_PC08A_EIC_EXTINT8)
#define PORT_PC08A_EIC_EXTINT8                     (_UINT32_(1) << 8)
#define PIN_PC08A_EIC_EXTINT_NUM                   _UINT32_(8)  /* EIC signal: PIN_PC08 External Interrupt Line */

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

#define PIN_PD24A_EIC_EXTINT8                      _UINT32_(120)
#define MUX_PD24A_EIC_EXTINT8                      _UINT32_(0) 
#define PINMUX_PD24A_EIC_EXTINT8                   ((PIN_PD24A_EIC_EXTINT8 << 16) | MUX_PD24A_EIC_EXTINT8)
#define PORT_PD24A_EIC_EXTINT8                     (_UINT32_(1) << 24)
#define PIN_PD24A_EIC_EXTINT_NUM                   _UINT32_(8)  /* EIC signal: PIN_PD24 External Interrupt Line */

#define PIN_PE08A_EIC_EXTINT8                      _UINT32_(136)
#define MUX_PE08A_EIC_EXTINT8                      _UINT32_(0) 
#define PINMUX_PE08A_EIC_EXTINT8                   ((PIN_PE08A_EIC_EXTINT8 << 16) | MUX_PE08A_EIC_EXTINT8)
#define PORT_PE08A_EIC_EXTINT8                     (_UINT32_(1) << 8)
#define PIN_PE08A_EIC_EXTINT_NUM                   _UINT32_(8)  /* EIC signal: PIN_PE08 External Interrupt Line */

#define PIN_PF08A_EIC_EXTINT8                      _UINT32_(168)
#define MUX_PF08A_EIC_EXTINT8                      _UINT32_(0) 
#define PINMUX_PF08A_EIC_EXTINT8                   ((PIN_PF08A_EIC_EXTINT8 << 16) | MUX_PF08A_EIC_EXTINT8)
#define PORT_PF08A_EIC_EXTINT8                     (_UINT32_(1) << 8)
#define PIN_PF08A_EIC_EXTINT_NUM                   _UINT32_(8)  /* EIC signal: PIN_PF08 External Interrupt Line */

#define PIN_PG08A_EIC_EXTINT8                      _UINT32_(200)
#define MUX_PG08A_EIC_EXTINT8                      _UINT32_(0) 
#define PINMUX_PG08A_EIC_EXTINT8                   ((PIN_PG08A_EIC_EXTINT8 << 16) | MUX_PG08A_EIC_EXTINT8)
#define PORT_PG08A_EIC_EXTINT8                     (_UINT32_(1) << 8)
#define PIN_PG08A_EIC_EXTINT_NUM                   _UINT32_(8)  /* EIC signal: PIN_PG08 External Interrupt Line */

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

#define PIN_PD25A_EIC_EXTINT9                      _UINT32_(121)
#define MUX_PD25A_EIC_EXTINT9                      _UINT32_(0) 
#define PINMUX_PD25A_EIC_EXTINT9                   ((PIN_PD25A_EIC_EXTINT9 << 16) | MUX_PD25A_EIC_EXTINT9)
#define PORT_PD25A_EIC_EXTINT9                     (_UINT32_(1) << 25)
#define PIN_PD25A_EIC_EXTINT_NUM                   _UINT32_(9)  /* EIC signal: PIN_PD25 External Interrupt Line */

#define PIN_PE09A_EIC_EXTINT9                      _UINT32_(137)
#define MUX_PE09A_EIC_EXTINT9                      _UINT32_(0) 
#define PINMUX_PE09A_EIC_EXTINT9                   ((PIN_PE09A_EIC_EXTINT9 << 16) | MUX_PE09A_EIC_EXTINT9)
#define PORT_PE09A_EIC_EXTINT9                     (_UINT32_(1) << 9)
#define PIN_PE09A_EIC_EXTINT_NUM                   _UINT32_(9)  /* EIC signal: PIN_PE09 External Interrupt Line */

#define PIN_PG09A_EIC_EXTINT9                      _UINT32_(201)
#define MUX_PG09A_EIC_EXTINT9                      _UINT32_(0) 
#define PINMUX_PG09A_EIC_EXTINT9                   ((PIN_PG09A_EIC_EXTINT9 << 16) | MUX_PG09A_EIC_EXTINT9)
#define PORT_PG09A_EIC_EXTINT9                     (_UINT32_(1) << 9)
#define PIN_PG09A_EIC_EXTINT_NUM                   _UINT32_(9)  /* EIC signal: PIN_PG09 External Interrupt Line */

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

#define PIN_PD26A_EIC_EXTINT10                     _UINT32_(122)
#define MUX_PD26A_EIC_EXTINT10                     _UINT32_(0) 
#define PINMUX_PD26A_EIC_EXTINT10                  ((PIN_PD26A_EIC_EXTINT10 << 16) | MUX_PD26A_EIC_EXTINT10)
#define PORT_PD26A_EIC_EXTINT10                    (_UINT32_(1) << 26)
#define PIN_PD26A_EIC_EXTINT_NUM                   _UINT32_(10) /* EIC signal: PIN_PD26 External Interrupt Line */

#define PIN_PE10A_EIC_EXTINT10                     _UINT32_(138)
#define MUX_PE10A_EIC_EXTINT10                     _UINT32_(0) 
#define PINMUX_PE10A_EIC_EXTINT10                  ((PIN_PE10A_EIC_EXTINT10 << 16) | MUX_PE10A_EIC_EXTINT10)
#define PORT_PE10A_EIC_EXTINT10                    (_UINT32_(1) << 10)
#define PIN_PE10A_EIC_EXTINT_NUM                   _UINT32_(10) /* EIC signal: PIN_PE10 External Interrupt Line */

#define PIN_PG10A_EIC_EXTINT10                     _UINT32_(202)
#define MUX_PG10A_EIC_EXTINT10                     _UINT32_(0) 
#define PINMUX_PG10A_EIC_EXTINT10                  ((PIN_PG10A_EIC_EXTINT10 << 16) | MUX_PG10A_EIC_EXTINT10)
#define PORT_PG10A_EIC_EXTINT10                    (_UINT32_(1) << 10)
#define PIN_PG10A_EIC_EXTINT_NUM                   _UINT32_(10) /* EIC signal: PIN_PG10 External Interrupt Line */

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

#define PIN_PB27A_EIC_EXTINT11                     _UINT32_(59)
#define MUX_PB27A_EIC_EXTINT11                     _UINT32_(0) 
#define PINMUX_PB27A_EIC_EXTINT11                  ((PIN_PB27A_EIC_EXTINT11 << 16) | MUX_PB27A_EIC_EXTINT11)
#define PORT_PB27A_EIC_EXTINT11                    (_UINT32_(1) << 27)
#define PIN_PB27A_EIC_EXTINT_NUM                   _UINT32_(11) /* EIC signal: PIN_PB27 External Interrupt Line */

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

#define PIN_PD27A_EIC_EXTINT11                     _UINT32_(123)
#define MUX_PD27A_EIC_EXTINT11                     _UINT32_(0) 
#define PINMUX_PD27A_EIC_EXTINT11                  ((PIN_PD27A_EIC_EXTINT11 << 16) | MUX_PD27A_EIC_EXTINT11)
#define PORT_PD27A_EIC_EXTINT11                    (_UINT32_(1) << 27)
#define PIN_PD27A_EIC_EXTINT_NUM                   _UINT32_(11) /* EIC signal: PIN_PD27 External Interrupt Line */

#define PIN_PE11A_EIC_EXTINT11                     _UINT32_(139)
#define MUX_PE11A_EIC_EXTINT11                     _UINT32_(0) 
#define PINMUX_PE11A_EIC_EXTINT11                  ((PIN_PE11A_EIC_EXTINT11 << 16) | MUX_PE11A_EIC_EXTINT11)
#define PORT_PE11A_EIC_EXTINT11                    (_UINT32_(1) << 11)
#define PIN_PE11A_EIC_EXTINT_NUM                   _UINT32_(11) /* EIC signal: PIN_PE11 External Interrupt Line */

#define PIN_PG11A_EIC_EXTINT11                     _UINT32_(203)
#define MUX_PG11A_EIC_EXTINT11                     _UINT32_(0) 
#define PINMUX_PG11A_EIC_EXTINT11                  ((PIN_PG11A_EIC_EXTINT11 << 16) | MUX_PG11A_EIC_EXTINT11)
#define PORT_PG11A_EIC_EXTINT11                    (_UINT32_(1) << 11)
#define PIN_PG11A_EIC_EXTINT_NUM                   _UINT32_(11) /* EIC signal: PIN_PG11 External Interrupt Line */

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

#define PIN_PB28A_EIC_EXTINT12                     _UINT32_(60)
#define MUX_PB28A_EIC_EXTINT12                     _UINT32_(0) 
#define PINMUX_PB28A_EIC_EXTINT12                  ((PIN_PB28A_EIC_EXTINT12 << 16) | MUX_PB28A_EIC_EXTINT12)
#define PORT_PB28A_EIC_EXTINT12                    (_UINT32_(1) << 28)
#define PIN_PB28A_EIC_EXTINT_NUM                   _UINT32_(12) /* EIC signal: PIN_PB28 External Interrupt Line */

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

#define PIN_PD28A_EIC_EXTINT12                     _UINT32_(124)
#define MUX_PD28A_EIC_EXTINT12                     _UINT32_(0) 
#define PINMUX_PD28A_EIC_EXTINT12                  ((PIN_PD28A_EIC_EXTINT12 << 16) | MUX_PD28A_EIC_EXTINT12)
#define PORT_PD28A_EIC_EXTINT12                    (_UINT32_(1) << 28)
#define PIN_PD28A_EIC_EXTINT_NUM                   _UINT32_(12) /* EIC signal: PIN_PD28 External Interrupt Line */

#define PIN_PA13A_EIC_EXTINT13                     _UINT32_(13)
#define MUX_PA13A_EIC_EXTINT13                     _UINT32_(0) 
#define PINMUX_PA13A_EIC_EXTINT13                  ((PIN_PA13A_EIC_EXTINT13 << 16) | MUX_PA13A_EIC_EXTINT13)
#define PORT_PA13A_EIC_EXTINT13                    (_UINT32_(1) << 13)
#define PIN_PA13A_EIC_EXTINT_NUM                   _UINT32_(13) /* EIC signal: PIN_PA13 External Interrupt Line */

#define PIN_PA29A_EIC_EXTINT13                     _UINT32_(29)
#define MUX_PA29A_EIC_EXTINT13                     _UINT32_(0) 
#define PINMUX_PA29A_EIC_EXTINT13                  ((PIN_PA29A_EIC_EXTINT13 << 16) | MUX_PA29A_EIC_EXTINT13)
#define PORT_PA29A_EIC_EXTINT13                    (_UINT32_(1) << 29)
#define PIN_PA29A_EIC_EXTINT_NUM                   _UINT32_(13) /* EIC signal: PIN_PA29 External Interrupt Line */

#define PIN_PB13A_EIC_EXTINT13                     _UINT32_(45)
#define MUX_PB13A_EIC_EXTINT13                     _UINT32_(0) 
#define PINMUX_PB13A_EIC_EXTINT13                  ((PIN_PB13A_EIC_EXTINT13 << 16) | MUX_PB13A_EIC_EXTINT13)
#define PORT_PB13A_EIC_EXTINT13                    (_UINT32_(1) << 13)
#define PIN_PB13A_EIC_EXTINT_NUM                   _UINT32_(13) /* EIC signal: PIN_PB13 External Interrupt Line */

#define PIN_PB29A_EIC_EXTINT13                     _UINT32_(61)
#define MUX_PB29A_EIC_EXTINT13                     _UINT32_(0) 
#define PINMUX_PB29A_EIC_EXTINT13                  ((PIN_PB29A_EIC_EXTINT13 << 16) | MUX_PB29A_EIC_EXTINT13)
#define PORT_PB29A_EIC_EXTINT13                    (_UINT32_(1) << 29)
#define PIN_PB29A_EIC_EXTINT_NUM                   _UINT32_(13) /* EIC signal: PIN_PB29 External Interrupt Line */

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

#define PIN_PD29A_EIC_EXTINT13                     _UINT32_(125)
#define MUX_PD29A_EIC_EXTINT13                     _UINT32_(0) 
#define PINMUX_PD29A_EIC_EXTINT13                  ((PIN_PD29A_EIC_EXTINT13 << 16) | MUX_PD29A_EIC_EXTINT13)
#define PORT_PD29A_EIC_EXTINT13                    (_UINT32_(1) << 29)
#define PIN_PD29A_EIC_EXTINT_NUM                   _UINT32_(13) /* EIC signal: PIN_PD29 External Interrupt Line */

#define PIN_PA14A_EIC_EXTINT14                     _UINT32_(14)
#define MUX_PA14A_EIC_EXTINT14                     _UINT32_(0) 
#define PINMUX_PA14A_EIC_EXTINT14                  ((PIN_PA14A_EIC_EXTINT14 << 16) | MUX_PA14A_EIC_EXTINT14)
#define PORT_PA14A_EIC_EXTINT14                    (_UINT32_(1) << 14)
#define PIN_PA14A_EIC_EXTINT_NUM                   _UINT32_(14) /* EIC signal: PIN_PA14 External Interrupt Line */

#define PIN_PA30A_EIC_EXTINT14                     _UINT32_(30)
#define MUX_PA30A_EIC_EXTINT14                     _UINT32_(0) 
#define PINMUX_PA30A_EIC_EXTINT14                  ((PIN_PA30A_EIC_EXTINT14 << 16) | MUX_PA30A_EIC_EXTINT14)
#define PORT_PA30A_EIC_EXTINT14                    (_UINT32_(1) << 30)
#define PIN_PA30A_EIC_EXTINT_NUM                   _UINT32_(14) /* EIC signal: PIN_PA30 External Interrupt Line */

#define PIN_PB14A_EIC_EXTINT14                     _UINT32_(46)
#define MUX_PB14A_EIC_EXTINT14                     _UINT32_(0) 
#define PINMUX_PB14A_EIC_EXTINT14                  ((PIN_PB14A_EIC_EXTINT14 << 16) | MUX_PB14A_EIC_EXTINT14)
#define PORT_PB14A_EIC_EXTINT14                    (_UINT32_(1) << 14)
#define PIN_PB14A_EIC_EXTINT_NUM                   _UINT32_(14) /* EIC signal: PIN_PB14 External Interrupt Line */

#define PIN_PB30A_EIC_EXTINT14                     _UINT32_(62)
#define MUX_PB30A_EIC_EXTINT14                     _UINT32_(0) 
#define PINMUX_PB30A_EIC_EXTINT14                  ((PIN_PB30A_EIC_EXTINT14 << 16) | MUX_PB30A_EIC_EXTINT14)
#define PORT_PB30A_EIC_EXTINT14                    (_UINT32_(1) << 30)
#define PIN_PB30A_EIC_EXTINT_NUM                   _UINT32_(14) /* EIC signal: PIN_PB30 External Interrupt Line */

#define PIN_PC14A_EIC_EXTINT14                     _UINT32_(78)
#define MUX_PC14A_EIC_EXTINT14                     _UINT32_(0) 
#define PINMUX_PC14A_EIC_EXTINT14                  ((PIN_PC14A_EIC_EXTINT14 << 16) | MUX_PC14A_EIC_EXTINT14)
#define PORT_PC14A_EIC_EXTINT14                    (_UINT32_(1) << 14)
#define PIN_PC14A_EIC_EXTINT_NUM                   _UINT32_(14) /* EIC signal: PIN_PC14 External Interrupt Line */

#define PIN_PC30A_EIC_EXTINT14                     _UINT32_(94)
#define MUX_PC30A_EIC_EXTINT14                     _UINT32_(0) 
#define PINMUX_PC30A_EIC_EXTINT14                  ((PIN_PC30A_EIC_EXTINT14 << 16) | MUX_PC30A_EIC_EXTINT14)
#define PORT_PC30A_EIC_EXTINT14                    (_UINT32_(1) << 30)
#define PIN_PC30A_EIC_EXTINT_NUM                   _UINT32_(14) /* EIC signal: PIN_PC30 External Interrupt Line */

#define PIN_PD13A_EIC_EXTINT14                     _UINT32_(109)
#define MUX_PD13A_EIC_EXTINT14                     _UINT32_(0) 
#define PINMUX_PD13A_EIC_EXTINT14                  ((PIN_PD13A_EIC_EXTINT14 << 16) | MUX_PD13A_EIC_EXTINT14)
#define PORT_PD13A_EIC_EXTINT14                    (_UINT32_(1) << 13)
#define PIN_PD13A_EIC_EXTINT_NUM                   _UINT32_(14) /* EIC signal: PIN_PD13 External Interrupt Line */

#define PIN_PA15A_EIC_EXTINT15                     _UINT32_(15)
#define MUX_PA15A_EIC_EXTINT15                     _UINT32_(0) 
#define PINMUX_PA15A_EIC_EXTINT15                  ((PIN_PA15A_EIC_EXTINT15 << 16) | MUX_PA15A_EIC_EXTINT15)
#define PORT_PA15A_EIC_EXTINT15                    (_UINT32_(1) << 15)
#define PIN_PA15A_EIC_EXTINT_NUM                   _UINT32_(15) /* EIC signal: PIN_PA15 External Interrupt Line */

#define PIN_PA31A_EIC_EXTINT15                     _UINT32_(31)
#define MUX_PA31A_EIC_EXTINT15                     _UINT32_(0) 
#define PINMUX_PA31A_EIC_EXTINT15                  ((PIN_PA31A_EIC_EXTINT15 << 16) | MUX_PA31A_EIC_EXTINT15)
#define PORT_PA31A_EIC_EXTINT15                    (_UINT32_(1) << 31)
#define PIN_PA31A_EIC_EXTINT_NUM                   _UINT32_(15) /* EIC signal: PIN_PA31 External Interrupt Line */

#define PIN_PB15A_EIC_EXTINT15                     _UINT32_(47)
#define MUX_PB15A_EIC_EXTINT15                     _UINT32_(0) 
#define PINMUX_PB15A_EIC_EXTINT15                  ((PIN_PB15A_EIC_EXTINT15 << 16) | MUX_PB15A_EIC_EXTINT15)
#define PORT_PB15A_EIC_EXTINT15                    (_UINT32_(1) << 15)
#define PIN_PB15A_EIC_EXTINT_NUM                   _UINT32_(15) /* EIC signal: PIN_PB15 External Interrupt Line */

#define PIN_PB31A_EIC_EXTINT15                     _UINT32_(63)
#define MUX_PB31A_EIC_EXTINT15                     _UINT32_(0) 
#define PINMUX_PB31A_EIC_EXTINT15                  ((PIN_PB31A_EIC_EXTINT15 << 16) | MUX_PB31A_EIC_EXTINT15)
#define PORT_PB31A_EIC_EXTINT15                    (_UINT32_(1) << 31)
#define PIN_PB31A_EIC_EXTINT_NUM                   _UINT32_(15) /* EIC signal: PIN_PB31 External Interrupt Line */

#define PIN_PC15A_EIC_EXTINT15                     _UINT32_(79)
#define MUX_PC15A_EIC_EXTINT15                     _UINT32_(0) 
#define PINMUX_PC15A_EIC_EXTINT15                  ((PIN_PC15A_EIC_EXTINT15 << 16) | MUX_PC15A_EIC_EXTINT15)
#define PORT_PC15A_EIC_EXTINT15                    (_UINT32_(1) << 15)
#define PIN_PC15A_EIC_EXTINT_NUM                   _UINT32_(15) /* EIC signal: PIN_PC15 External Interrupt Line */

#define PIN_PC31A_EIC_EXTINT15                     _UINT32_(95)
#define MUX_PC31A_EIC_EXTINT15                     _UINT32_(0) 
#define PINMUX_PC31A_EIC_EXTINT15                  ((PIN_PC31A_EIC_EXTINT15 << 16) | MUX_PC31A_EIC_EXTINT15)
#define PORT_PC31A_EIC_EXTINT15                    (_UINT32_(1) << 31)
#define PIN_PC31A_EIC_EXTINT_NUM                   _UINT32_(15) /* EIC signal: PIN_PC31 External Interrupt Line */

#define PIN_PD14A_EIC_EXTINT15                     _UINT32_(110)
#define MUX_PD14A_EIC_EXTINT15                     _UINT32_(0) 
#define PINMUX_PD14A_EIC_EXTINT15                  ((PIN_PD14A_EIC_EXTINT15 << 16) | MUX_PD14A_EIC_EXTINT15)
#define PORT_PD14A_EIC_EXTINT15                    (_UINT32_(1) << 14)
#define PIN_PD14A_EIC_EXTINT_NUM                   _UINT32_(15) /* EIC signal: PIN_PD14 External Interrupt Line */

#define PIN_PC20A_EIC_NMI                          _UINT32_(84)
#define MUX_PC20A_EIC_NMI                          _UINT32_(0) 
#define PINMUX_PC20A_EIC_NMI                       ((PIN_PC20A_EIC_NMI << 16) | MUX_PC20A_EIC_NMI)
#define PORT_PC20A_EIC_NMI                         (_UINT32_(1) << 20)

/* ========== PORT definition for ETH peripheral ========== */
#define PIN_PD08K_ETH_COL                          _UINT32_(104)
#define MUX_PD08K_ETH_COL                          _UINT32_(10)
#define PINMUX_PD08K_ETH_COL                       ((PIN_PD08K_ETH_COL << 16) | MUX_PD08K_ETH_COL)
#define PORT_PD08K_ETH_COL                         (_UINT32_(1) << 8)

#define PIN_PD09K_ETH_CRS                          _UINT32_(105)
#define MUX_PD09K_ETH_CRS                          _UINT32_(10)
#define PINMUX_PD09K_ETH_CRS                       ((PIN_PD09K_ETH_CRS << 16) | MUX_PD09K_ETH_CRS)
#define PORT_PD09K_ETH_CRS                         (_UINT32_(1) << 9)

#define PIN_PD05L_ETH_GTX_CLK                      _UINT32_(101)
#define MUX_PD05L_ETH_GTX_CLK                      _UINT32_(11)
#define PINMUX_PD05L_ETH_GTX_CLK                   ((PIN_PD05L_ETH_GTX_CLK << 16) | MUX_PD05L_ETH_GTX_CLK)
#define PORT_PD05L_ETH_GTX_CLK                     (_UINT32_(1) << 5)

#define PIN_PA03K_ETH_MDC                          _UINT32_(3) 
#define MUX_PA03K_ETH_MDC                          _UINT32_(10)
#define PINMUX_PA03K_ETH_MDC                       ((PIN_PA03K_ETH_MDC << 16) | MUX_PA03K_ETH_MDC)
#define PORT_PA03K_ETH_MDC                         (_UINT32_(1) << 3)

#define PIN_PA04K_ETH_MDIO                         _UINT32_(4) 
#define MUX_PA04K_ETH_MDIO                         _UINT32_(10)
#define PINMUX_PA04K_ETH_MDIO                      ((PIN_PA04K_ETH_MDIO << 16) | MUX_PA04K_ETH_MDIO)
#define PORT_PA04K_ETH_MDIO                        (_UINT32_(1) << 4)

#define PIN_PD12K_ETH_REF_CLK                      _UINT32_(108)
#define MUX_PD12K_ETH_REF_CLK                      _UINT32_(10)
#define PINMUX_PD12K_ETH_REF_CLK                   ((PIN_PD12K_ETH_REF_CLK << 16) | MUX_PD12K_ETH_REF_CLK)
#define PORT_PD12K_ETH_REF_CLK                     (_UINT32_(1) << 12)

#define PIN_PD11K_ETH_RXD0                         _UINT32_(107)
#define MUX_PD11K_ETH_RXD0                         _UINT32_(10)
#define PINMUX_PD11K_ETH_RXD0                      ((PIN_PD11K_ETH_RXD0 << 16) | MUX_PD11K_ETH_RXD0)
#define PORT_PD11K_ETH_RXD0                        (_UINT32_(1) << 11)

#define PIN_PD10K_ETH_RXD1                         _UINT32_(106)
#define MUX_PD10K_ETH_RXD1                         _UINT32_(10)
#define PINMUX_PD10K_ETH_RXD1                      ((PIN_PD10K_ETH_RXD1 << 16) | MUX_PD10K_ETH_RXD1)
#define PORT_PD10K_ETH_RXD1                        (_UINT32_(1) << 10)

#define PIN_PD07K_ETH_RXD2                         _UINT32_(103)
#define MUX_PD07K_ETH_RXD2                         _UINT32_(10)
#define PINMUX_PD07K_ETH_RXD2                      ((PIN_PD07K_ETH_RXD2 << 16) | MUX_PD07K_ETH_RXD2)
#define PORT_PD07K_ETH_RXD2                        (_UINT32_(1) << 7)

#define PIN_PD06K_ETH_RXD3                         _UINT32_(102)
#define MUX_PD06K_ETH_RXD3                         _UINT32_(10)
#define PINMUX_PD06K_ETH_RXD3                      ((PIN_PD06K_ETH_RXD3 << 16) | MUX_PD06K_ETH_RXD3)
#define PORT_PD06K_ETH_RXD3                        (_UINT32_(1) << 6)

#define PIN_PD20K_ETH_RXD4                         _UINT32_(116)
#define MUX_PD20K_ETH_RXD4                         _UINT32_(10)
#define PINMUX_PD20K_ETH_RXD4                      ((PIN_PD20K_ETH_RXD4 << 16) | MUX_PD20K_ETH_RXD4)
#define PORT_PD20K_ETH_RXD4                        (_UINT32_(1) << 20)

#define PIN_PD21K_ETH_RXD5                         _UINT32_(117)
#define MUX_PD21K_ETH_RXD5                         _UINT32_(10)
#define PINMUX_PD21K_ETH_RXD5                      ((PIN_PD21K_ETH_RXD5 << 16) | MUX_PD21K_ETH_RXD5)
#define PORT_PD21K_ETH_RXD5                        (_UINT32_(1) << 21)

#define PIN_PD19K_ETH_RXD6                         _UINT32_(115)
#define MUX_PD19K_ETH_RXD6                         _UINT32_(10)
#define PINMUX_PD19K_ETH_RXD6                      ((PIN_PD19K_ETH_RXD6 << 16) | MUX_PD19K_ETH_RXD6)
#define PORT_PD19K_ETH_RXD6                        (_UINT32_(1) << 19)

#define PIN_PD18K_ETH_RXD7                         _UINT32_(114)
#define MUX_PD18K_ETH_RXD7                         _UINT32_(10)
#define PINMUX_PD18K_ETH_RXD7                      ((PIN_PD18K_ETH_RXD7 << 16) | MUX_PD18K_ETH_RXD7)
#define PORT_PD18K_ETH_RXD7                        (_UINT32_(1) << 18)

#define PIN_PA05K_ETH_RXDV                         _UINT32_(5) 
#define MUX_PA05K_ETH_RXDV                         _UINT32_(10)
#define PINMUX_PA05K_ETH_RXDV                      ((PIN_PA05K_ETH_RXDV << 16) | MUX_PA05K_ETH_RXDV)
#define PORT_PA05K_ETH_RXDV                        (_UINT32_(1) << 5)

#define PIN_PA06K_ETH_RXER                         _UINT32_(6) 
#define MUX_PA06K_ETH_RXER                         _UINT32_(10)
#define PINMUX_PA06K_ETH_RXER                      ((PIN_PA06K_ETH_RXER << 16) | MUX_PA06K_ETH_RXER)
#define PORT_PA06K_ETH_RXER                        (_UINT32_(1) << 6)

#define PIN_PD12L_ETH_RX_CLK                       _UINT32_(108)
#define MUX_PD12L_ETH_RX_CLK                       _UINT32_(11)
#define PINMUX_PD12L_ETH_RX_CLK                    ((PIN_PD12L_ETH_RX_CLK << 16) | MUX_PD12L_ETH_RX_CLK)
#define PORT_PD12L_ETH_RX_CLK                      (_UINT32_(1) << 12)

#define PIN_PA22K_ETH_TSUCOMP                      _UINT32_(22)
#define MUX_PA22K_ETH_TSUCOMP                      _UINT32_(10)
#define PINMUX_PA22K_ETH_TSUCOMP                   ((PIN_PA22K_ETH_TSUCOMP << 16) | MUX_PA22K_ETH_TSUCOMP)
#define PORT_PA22K_ETH_TSUCOMP                     (_UINT32_(1) << 22)

#define PIN_PC05K_ETH_TSUCOMP                      _UINT32_(69)
#define MUX_PC05K_ETH_TSUCOMP                      _UINT32_(10)
#define PINMUX_PC05K_ETH_TSUCOMP                   ((PIN_PC05K_ETH_TSUCOMP << 16) | MUX_PC05K_ETH_TSUCOMP)
#define PORT_PC05K_ETH_TSUCOMP                     (_UINT32_(1) << 5)

#define PIN_PC17K_ETH_TSUCOMP                      _UINT32_(81)
#define MUX_PC17K_ETH_TSUCOMP                      _UINT32_(10)
#define PINMUX_PC17K_ETH_TSUCOMP                   ((PIN_PC17K_ETH_TSUCOMP << 16) | MUX_PC17K_ETH_TSUCOMP)
#define PORT_PC17K_ETH_TSUCOMP                     (_UINT32_(1) << 17)

#define PIN_PA01K_ETH_TXD0                         _UINT32_(1) 
#define MUX_PA01K_ETH_TXD0                         _UINT32_(10)
#define PINMUX_PA01K_ETH_TXD0                      ((PIN_PA01K_ETH_TXD0 << 16) | MUX_PA01K_ETH_TXD0)
#define PORT_PA01K_ETH_TXD0                        (_UINT32_(1) << 1)

#define PIN_PA00K_ETH_TXD1                         _UINT32_(0) 
#define MUX_PA00K_ETH_TXD1                         _UINT32_(10)
#define PINMUX_PA00K_ETH_TXD1                      ((PIN_PA00K_ETH_TXD1 << 16) | MUX_PA00K_ETH_TXD1)
#define PORT_PA00K_ETH_TXD1                        (_UINT32_(1) << 0)

#define PIN_PD04K_ETH_TXD2                         _UINT32_(100)
#define MUX_PD04K_ETH_TXD2                         _UINT32_(10)
#define PINMUX_PD04K_ETH_TXD2                      ((PIN_PD04K_ETH_TXD2 << 16) | MUX_PD04K_ETH_TXD2)
#define PORT_PD04K_ETH_TXD2                        (_UINT32_(1) << 4)

#define PIN_PD03K_ETH_TXD3                         _UINT32_(99)
#define MUX_PD03K_ETH_TXD3                         _UINT32_(10)
#define PINMUX_PD03K_ETH_TXD3                      ((PIN_PD03K_ETH_TXD3 << 16) | MUX_PD03K_ETH_TXD3)
#define PORT_PD03K_ETH_TXD3                        (_UINT32_(1) << 3)

#define PIN_PD17K_ETH_TXD4                         _UINT32_(113)
#define MUX_PD17K_ETH_TXD4                         _UINT32_(10)
#define PINMUX_PD17K_ETH_TXD4                      ((PIN_PD17K_ETH_TXD4 << 16) | MUX_PD17K_ETH_TXD4)
#define PORT_PD17K_ETH_TXD4                        (_UINT32_(1) << 17)

#define PIN_PD16K_ETH_TXD5                         _UINT32_(112)
#define MUX_PD16K_ETH_TXD5                         _UINT32_(10)
#define PINMUX_PD16K_ETH_TXD5                      ((PIN_PD16K_ETH_TXD5 << 16) | MUX_PD16K_ETH_TXD5)
#define PORT_PD16K_ETH_TXD5                        (_UINT32_(1) << 16)

#define PIN_PD15K_ETH_TXD6                         _UINT32_(111)
#define MUX_PD15K_ETH_TXD6                         _UINT32_(10)
#define PINMUX_PD15K_ETH_TXD6                      ((PIN_PD15K_ETH_TXD6 << 16) | MUX_PD15K_ETH_TXD6)
#define PORT_PD15K_ETH_TXD6                        (_UINT32_(1) << 15)

#define PIN_PD14K_ETH_TXD7                         _UINT32_(110)
#define MUX_PD14K_ETH_TXD7                         _UINT32_(10)
#define PINMUX_PD14K_ETH_TXD7                      ((PIN_PD14K_ETH_TXD7 << 16) | MUX_PD14K_ETH_TXD7)
#define PORT_PD14K_ETH_TXD7                        (_UINT32_(1) << 14)

#define PIN_PA02K_ETH_TXEN                         _UINT32_(2) 
#define MUX_PA02K_ETH_TXEN                         _UINT32_(10)
#define PINMUX_PA02K_ETH_TXEN                      ((PIN_PA02K_ETH_TXEN << 16) | MUX_PA02K_ETH_TXEN)
#define PORT_PA02K_ETH_TXEN                        (_UINT32_(1) << 2)

#define PIN_PD02K_ETH_TXER                         _UINT32_(98)
#define MUX_PD02K_ETH_TXER                         _UINT32_(10)
#define PINMUX_PD02K_ETH_TXER                      ((PIN_PD02K_ETH_TXER << 16) | MUX_PD02K_ETH_TXER)
#define PORT_PD02K_ETH_TXER                        (_UINT32_(1) << 2)

#define PIN_PA21K_ETH_TX_CLK                       _UINT32_(21)
#define MUX_PA21K_ETH_TX_CLK                       _UINT32_(10)
#define PINMUX_PA21K_ETH_TX_CLK                    ((PIN_PA21K_ETH_TX_CLK << 16) | MUX_PA21K_ETH_TX_CLK)
#define PORT_PA21K_ETH_TX_CLK                      (_UINT32_(1) << 21)

#define PIN_PD05K_ETH_TX_CLK                       _UINT32_(101)
#define MUX_PD05K_ETH_TX_CLK                       _UINT32_(10)
#define PINMUX_PD05K_ETH_TX_CLK                    ((PIN_PD05K_ETH_TX_CLK << 16) | MUX_PD05K_ETH_TX_CLK)
#define PORT_PD05K_ETH_TX_CLK                      (_UINT32_(1) << 5)

/* ========== PORT definition for GCLK peripheral ========== */
#define PIN_PC20M_GCLK_IO0                         _UINT32_(84)
#define MUX_PC20M_GCLK_IO0                         _UINT32_(12)
#define PINMUX_PC20M_GCLK_IO0                      ((PIN_PC20M_GCLK_IO0 << 16) | MUX_PC20M_GCLK_IO0)
#define PORT_PC20M_GCLK_IO0                        (_UINT32_(1) << 20)

#define PIN_PC19M_GCLK_IO1                         _UINT32_(83)
#define MUX_PC19M_GCLK_IO1                         _UINT32_(12)
#define PINMUX_PC19M_GCLK_IO1                      ((PIN_PC19M_GCLK_IO1 << 16) | MUX_PC19M_GCLK_IO1)
#define PORT_PC19M_GCLK_IO1                        (_UINT32_(1) << 19)

#define PIN_PD00M_GCLK_IO2                         _UINT32_(96)
#define MUX_PD00M_GCLK_IO2                         _UINT32_(12)
#define PINMUX_PD00M_GCLK_IO2                      ((PIN_PD00M_GCLK_IO2 << 16) | MUX_PD00M_GCLK_IO2)
#define PORT_PD00M_GCLK_IO2                        (_UINT32_(1) << 0)

#define PIN_PD01M_GCLK_IO3                         _UINT32_(97)
#define MUX_PD01M_GCLK_IO3                         _UINT32_(12)
#define PINMUX_PD01M_GCLK_IO3                      ((PIN_PD01M_GCLK_IO3 << 16) | MUX_PD01M_GCLK_IO3)
#define PORT_PD01M_GCLK_IO3                        (_UINT32_(1) << 1)

#define PIN_PC00M_GCLK_IO4                         _UINT32_(64)
#define MUX_PC00M_GCLK_IO4                         _UINT32_(12)
#define PINMUX_PC00M_GCLK_IO4                      ((PIN_PC00M_GCLK_IO4 << 16) | MUX_PC00M_GCLK_IO4)
#define PORT_PC00M_GCLK_IO4                        (_UINT32_(1) << 0)

#define PIN_PD18M_GCLK_IO4                         _UINT32_(114)
#define MUX_PD18M_GCLK_IO4                         _UINT32_(12)
#define PINMUX_PD18M_GCLK_IO4                      ((PIN_PD18M_GCLK_IO4 << 16) | MUX_PD18M_GCLK_IO4)
#define PORT_PD18M_GCLK_IO4                        (_UINT32_(1) << 18)

#define PIN_PC01M_GCLK_IO5                         _UINT32_(65)
#define MUX_PC01M_GCLK_IO5                         _UINT32_(12)
#define PINMUX_PC01M_GCLK_IO5                      ((PIN_PC01M_GCLK_IO5 << 16) | MUX_PC01M_GCLK_IO5)
#define PORT_PC01M_GCLK_IO5                        (_UINT32_(1) << 1)

#define PIN_PD19M_GCLK_IO5                         _UINT32_(115)
#define MUX_PD19M_GCLK_IO5                         _UINT32_(12)
#define PINMUX_PD19M_GCLK_IO5                      ((PIN_PD19M_GCLK_IO5 << 16) | MUX_PD19M_GCLK_IO5)
#define PORT_PD19M_GCLK_IO5                        (_UINT32_(1) << 19)

#define PIN_PC02M_GCLK_IO6                         _UINT32_(66)
#define MUX_PC02M_GCLK_IO6                         _UINT32_(12)
#define PINMUX_PC02M_GCLK_IO6                      ((PIN_PC02M_GCLK_IO6 << 16) | MUX_PC02M_GCLK_IO6)
#define PORT_PC02M_GCLK_IO6                        (_UINT32_(1) << 2)

#define PIN_PD20M_GCLK_IO6                         _UINT32_(116)
#define MUX_PD20M_GCLK_IO6                         _UINT32_(12)
#define PINMUX_PD20M_GCLK_IO6                      ((PIN_PD20M_GCLK_IO6 << 16) | MUX_PD20M_GCLK_IO6)
#define PORT_PD20M_GCLK_IO6                        (_UINT32_(1) << 20)

#define PIN_PC03M_GCLK_IO7                         _UINT32_(67)
#define MUX_PC03M_GCLK_IO7                         _UINT32_(12)
#define PINMUX_PC03M_GCLK_IO7                      ((PIN_PC03M_GCLK_IO7 << 16) | MUX_PC03M_GCLK_IO7)
#define PORT_PC03M_GCLK_IO7                        (_UINT32_(1) << 3)

#define PIN_PD21M_GCLK_IO7                         _UINT32_(117)
#define MUX_PD21M_GCLK_IO7                         _UINT32_(12)
#define PINMUX_PD21M_GCLK_IO7                      ((PIN_PD21M_GCLK_IO7 << 16) | MUX_PD21M_GCLK_IO7)
#define PORT_PD21M_GCLK_IO7                        (_UINT32_(1) << 21)

#define PIN_PC04J_GCLK_spi_ixs_mclk0               _UINT32_(68)
#define MUX_PC04J_GCLK_spi_ixs_mclk0               _UINT32_(9) 
#define PINMUX_PC04J_GCLK_spi_ixs_mclk0            ((PIN_PC04J_GCLK_spi_ixs_mclk0 << 16) | MUX_PC04J_GCLK_spi_ixs_mclk0)
#define PORT_PC04J_GCLK_spi_ixs_mclk0              (_UINT32_(1) << 4)

#define PIN_PD06J_GCLK_spi_ixs_mclk0               _UINT32_(102)
#define MUX_PD06J_GCLK_spi_ixs_mclk0               _UINT32_(9) 
#define PINMUX_PD06J_GCLK_spi_ixs_mclk0            ((PIN_PD06J_GCLK_spi_ixs_mclk0 << 16) | MUX_PD06J_GCLK_spi_ixs_mclk0)
#define PORT_PD06J_GCLK_spi_ixs_mclk0              (_UINT32_(1) << 6)

#define PIN_PA31J_GCLK_spi_ixs_mclk1               _UINT32_(31)
#define MUX_PA31J_GCLK_spi_ixs_mclk1               _UINT32_(9) 
#define PINMUX_PA31J_GCLK_spi_ixs_mclk1            ((PIN_PA31J_GCLK_spi_ixs_mclk1 << 16) | MUX_PA31J_GCLK_spi_ixs_mclk1)
#define PORT_PA31J_GCLK_spi_ixs_mclk1              (_UINT32_(1) << 31)

/* ========== PORT definition for MLB peripheral ========== */
#define PIN_PD07G_MLB_MLBC                         _UINT32_(103)
#define MUX_PD07G_MLB_MLBC                         _UINT32_(6) 
#define PINMUX_PD07G_MLB_MLBC                      ((PIN_PD07G_MLB_MLBC << 16) | MUX_PD07G_MLB_MLBC)
#define PORT_PD07G_MLB_MLBC                        (_UINT32_(1) << 7)

#define PIN_PD09G_MLB_MLBD                         _UINT32_(105)
#define MUX_PD09G_MLB_MLBD                         _UINT32_(6) 
#define PINMUX_PD09G_MLB_MLBD                      ((PIN_PD09G_MLB_MLBD << 16) | MUX_PD09G_MLB_MLBD)
#define PORT_PD09G_MLB_MLBD                        (_UINT32_(1) << 9)

#define PIN_PD08G_MLB_MLBS                         _UINT32_(104)
#define MUX_PD08G_MLB_MLBS                         _UINT32_(6) 
#define PINMUX_PD08G_MLB_MLBS                      ((PIN_PD08G_MLB_MLBS << 16) | MUX_PD08G_MLB_MLBS)
#define PORT_PD08G_MLB_MLBS                        (_UINT32_(1) << 8)

/* ========== PORT definition for PTC peripheral ========== */
#define PIN_PB17P_PTC_DRV0                         _UINT32_(49)
#define MUX_PB17P_PTC_DRV0                         _UINT32_(15)
#define PINMUX_PB17P_PTC_DRV0                      ((PIN_PB17P_PTC_DRV0 << 16) | MUX_PB17P_PTC_DRV0)
#define PORT_PB17P_PTC_DRV0                        (_UINT32_(1) << 17)

#define PIN_PB16P_PTC_DRV1                         _UINT32_(48)
#define MUX_PB16P_PTC_DRV1                         _UINT32_(15)
#define PINMUX_PB16P_PTC_DRV1                      ((PIN_PB16P_PTC_DRV1 << 16) | MUX_PB16P_PTC_DRV1)
#define PORT_PB16P_PTC_DRV1                        (_UINT32_(1) << 16)

#define PIN_PB15P_PTC_DRV2                         _UINT32_(47)
#define MUX_PB15P_PTC_DRV2                         _UINT32_(15)
#define PINMUX_PB15P_PTC_DRV2                      ((PIN_PB15P_PTC_DRV2 << 16) | MUX_PB15P_PTC_DRV2)
#define PORT_PB15P_PTC_DRV2                        (_UINT32_(1) << 15)

#define PIN_PB14P_PTC_DRV3                         _UINT32_(46)
#define MUX_PB14P_PTC_DRV3                         _UINT32_(15)
#define PINMUX_PB14P_PTC_DRV3                      ((PIN_PB14P_PTC_DRV3 << 16) | MUX_PB14P_PTC_DRV3)
#define PORT_PB14P_PTC_DRV3                        (_UINT32_(1) << 14)

#define PIN_PB13P_PTC_DRV4                         _UINT32_(45)
#define MUX_PB13P_PTC_DRV4                         _UINT32_(15)
#define PINMUX_PB13P_PTC_DRV4                      ((PIN_PB13P_PTC_DRV4 << 16) | MUX_PB13P_PTC_DRV4)
#define PORT_PB13P_PTC_DRV4                        (_UINT32_(1) << 13)

#define PIN_PB12P_PTC_DRV5                         _UINT32_(44)
#define MUX_PB12P_PTC_DRV5                         _UINT32_(15)
#define PINMUX_PB12P_PTC_DRV5                      ((PIN_PB12P_PTC_DRV5 << 16) | MUX_PB12P_PTC_DRV5)
#define PORT_PB12P_PTC_DRV5                        (_UINT32_(1) << 12)

#define PIN_PB11P_PTC_DRV6                         _UINT32_(43)
#define MUX_PB11P_PTC_DRV6                         _UINT32_(15)
#define PINMUX_PB11P_PTC_DRV6                      ((PIN_PB11P_PTC_DRV6 << 16) | MUX_PB11P_PTC_DRV6)
#define PORT_PB11P_PTC_DRV6                        (_UINT32_(1) << 11)

#define PIN_PB10P_PTC_DRV7                         _UINT32_(42)
#define MUX_PB10P_PTC_DRV7                         _UINT32_(15)
#define PINMUX_PB10P_PTC_DRV7                      ((PIN_PB10P_PTC_DRV7 << 16) | MUX_PB10P_PTC_DRV7)
#define PORT_PB10P_PTC_DRV7                        (_UINT32_(1) << 10)

#define PIN_PB09P_PTC_DRV8                         _UINT32_(41)
#define MUX_PB09P_PTC_DRV8                         _UINT32_(15)
#define PINMUX_PB09P_PTC_DRV8                      ((PIN_PB09P_PTC_DRV8 << 16) | MUX_PB09P_PTC_DRV8)
#define PORT_PB09P_PTC_DRV8                        (_UINT32_(1) << 9)

#define PIN_PB08P_PTC_DRV9                         _UINT32_(40)
#define MUX_PB08P_PTC_DRV9                         _UINT32_(15)
#define PINMUX_PB08P_PTC_DRV9                      ((PIN_PB08P_PTC_DRV9 << 16) | MUX_PB08P_PTC_DRV9)
#define PORT_PB08P_PTC_DRV9                        (_UINT32_(1) << 8)

#define PIN_PB07P_PTC_DRV10                        _UINT32_(39)
#define MUX_PB07P_PTC_DRV10                        _UINT32_(15)
#define PINMUX_PB07P_PTC_DRV10                     ((PIN_PB07P_PTC_DRV10 << 16) | MUX_PB07P_PTC_DRV10)
#define PORT_PB07P_PTC_DRV10                       (_UINT32_(1) << 7)

#define PIN_PB06P_PTC_DRV11                        _UINT32_(38)
#define MUX_PB06P_PTC_DRV11                        _UINT32_(15)
#define PINMUX_PB06P_PTC_DRV11                     ((PIN_PB06P_PTC_DRV11 << 16) | MUX_PB06P_PTC_DRV11)
#define PORT_PB06P_PTC_DRV11                       (_UINT32_(1) << 6)

#define PIN_PB26P_PTC_DRV12                        _UINT32_(58)
#define MUX_PB26P_PTC_DRV12                        _UINT32_(15)
#define PINMUX_PB26P_PTC_DRV12                     ((PIN_PB26P_PTC_DRV12 << 16) | MUX_PB26P_PTC_DRV12)
#define PORT_PB26P_PTC_DRV12                       (_UINT32_(1) << 26)

#define PIN_PB25P_PTC_DRV13                        _UINT32_(57)
#define MUX_PB25P_PTC_DRV13                        _UINT32_(15)
#define PINMUX_PB25P_PTC_DRV13                     ((PIN_PB25P_PTC_DRV13 << 16) | MUX_PB25P_PTC_DRV13)
#define PORT_PB25P_PTC_DRV13                       (_UINT32_(1) << 25)

#define PIN_PB24P_PTC_DRV14                        _UINT32_(56)
#define MUX_PB24P_PTC_DRV14                        _UINT32_(15)
#define PINMUX_PB24P_PTC_DRV14                     ((PIN_PB24P_PTC_DRV14 << 16) | MUX_PB24P_PTC_DRV14)
#define PORT_PB24P_PTC_DRV14                       (_UINT32_(1) << 24)

#define PIN_PB23P_PTC_DRV15                        _UINT32_(55)
#define MUX_PB23P_PTC_DRV15                        _UINT32_(15)
#define PINMUX_PB23P_PTC_DRV15                     ((PIN_PB23P_PTC_DRV15 << 16) | MUX_PB23P_PTC_DRV15)
#define PORT_PB23P_PTC_DRV15                       (_UINT32_(1) << 23)

#define PIN_PB22P_PTC_DRV16                        _UINT32_(54)
#define MUX_PB22P_PTC_DRV16                        _UINT32_(15)
#define PINMUX_PB22P_PTC_DRV16                     ((PIN_PB22P_PTC_DRV16 << 16) | MUX_PB22P_PTC_DRV16)
#define PORT_PB22P_PTC_DRV16                       (_UINT32_(1) << 22)

#define PIN_PB21P_PTC_DRV17                        _UINT32_(53)
#define MUX_PB21P_PTC_DRV17                        _UINT32_(15)
#define PINMUX_PB21P_PTC_DRV17                     ((PIN_PB21P_PTC_DRV17 << 16) | MUX_PB21P_PTC_DRV17)
#define PORT_PB21P_PTC_DRV17                       (_UINT32_(1) << 21)

#define PIN_PB31P_PTC_DRV18                        _UINT32_(63)
#define MUX_PB31P_PTC_DRV18                        _UINT32_(15)
#define PINMUX_PB31P_PTC_DRV18                     ((PIN_PB31P_PTC_DRV18 << 16) | MUX_PB31P_PTC_DRV18)
#define PORT_PB31P_PTC_DRV18                       (_UINT32_(1) << 31)

#define PIN_PB30P_PTC_DRV19                        _UINT32_(62)
#define MUX_PB30P_PTC_DRV19                        _UINT32_(15)
#define PINMUX_PB30P_PTC_DRV19                     ((PIN_PB30P_PTC_DRV19 << 16) | MUX_PB30P_PTC_DRV19)
#define PORT_PB30P_PTC_DRV19                       (_UINT32_(1) << 30)

#define PIN_PB29P_PTC_DRV20                        _UINT32_(61)
#define MUX_PB29P_PTC_DRV20                        _UINT32_(15)
#define PINMUX_PB29P_PTC_DRV20                     ((PIN_PB29P_PTC_DRV20 << 16) | MUX_PB29P_PTC_DRV20)
#define PORT_PB29P_PTC_DRV20                       (_UINT32_(1) << 29)

#define PIN_PF05P_PTC_DRV21                        _UINT32_(165)
#define MUX_PF05P_PTC_DRV21                        _UINT32_(15)
#define PINMUX_PF05P_PTC_DRV21                     ((PIN_PF05P_PTC_DRV21 << 16) | MUX_PF05P_PTC_DRV21)
#define PORT_PF05P_PTC_DRV21                       (_UINT32_(1) << 5)

#define PIN_PB28P_PTC_DRV22                        _UINT32_(60)
#define MUX_PB28P_PTC_DRV22                        _UINT32_(15)
#define PINMUX_PB28P_PTC_DRV22                     ((PIN_PB28P_PTC_DRV22 << 16) | MUX_PB28P_PTC_DRV22)
#define PORT_PB28P_PTC_DRV22                       (_UINT32_(1) << 28)

#define PIN_PB27P_PTC_DRV23                        _UINT32_(59)
#define MUX_PB27P_PTC_DRV23                        _UINT32_(15)
#define PINMUX_PB27P_PTC_DRV23                     ((PIN_PB27P_PTC_DRV23 << 16) | MUX_PB27P_PTC_DRV23)
#define PORT_PB27P_PTC_DRV23                       (_UINT32_(1) << 27)

#define PIN_PF08P_PTC_DRV24                        _UINT32_(168)
#define MUX_PF08P_PTC_DRV24                        _UINT32_(15)
#define PINMUX_PF08P_PTC_DRV24                     ((PIN_PF08P_PTC_DRV24 << 16) | MUX_PF08P_PTC_DRV24)
#define PORT_PF08P_PTC_DRV24                       (_UINT32_(1) << 8)

#define PIN_PF07P_PTC_DRV25                        _UINT32_(167)
#define MUX_PF07P_PTC_DRV25                        _UINT32_(15)
#define PINMUX_PF07P_PTC_DRV25                     ((PIN_PF07P_PTC_DRV25 << 16) | MUX_PF07P_PTC_DRV25)
#define PORT_PF07P_PTC_DRV25                       (_UINT32_(1) << 7)

#define PIN_PF06P_PTC_DRV26                        _UINT32_(166)
#define MUX_PF06P_PTC_DRV26                        _UINT32_(15)
#define PINMUX_PF06P_PTC_DRV26                     ((PIN_PF06P_PTC_DRV26 << 16) | MUX_PF06P_PTC_DRV26)
#define PORT_PF06P_PTC_DRV26                       (_UINT32_(1) << 6)

#define PIN_PF04P_PTC_DRV27                        _UINT32_(164)
#define MUX_PF04P_PTC_DRV27                        _UINT32_(15)
#define PINMUX_PF04P_PTC_DRV27                     ((PIN_PF04P_PTC_DRV27 << 16) | MUX_PF04P_PTC_DRV27)
#define PORT_PF04P_PTC_DRV27                       (_UINT32_(1) << 4)

#define PIN_PF03P_PTC_DRV28                        _UINT32_(163)
#define MUX_PF03P_PTC_DRV28                        _UINT32_(15)
#define PINMUX_PF03P_PTC_DRV28                     ((PIN_PF03P_PTC_DRV28 << 16) | MUX_PF03P_PTC_DRV28)
#define PORT_PF03P_PTC_DRV28                       (_UINT32_(1) << 3)

#define PIN_PF02P_PTC_DRV29                        _UINT32_(162)
#define MUX_PF02P_PTC_DRV29                        _UINT32_(15)
#define PINMUX_PF02P_PTC_DRV29                     ((PIN_PF02P_PTC_DRV29 << 16) | MUX_PF02P_PTC_DRV29)
#define PORT_PF02P_PTC_DRV29                       (_UINT32_(1) << 2)

#define PIN_PF00P_PTC_DRV30                        _UINT32_(160)
#define MUX_PF00P_PTC_DRV30                        _UINT32_(15)
#define PINMUX_PF00P_PTC_DRV30                     ((PIN_PF00P_PTC_DRV30 << 16) | MUX_PF00P_PTC_DRV30)
#define PORT_PF00P_PTC_DRV30                       (_UINT32_(1) << 0)

#define PIN_PF01P_PTC_DRV31                        _UINT32_(161)
#define MUX_PF01P_PTC_DRV31                        _UINT32_(15)
#define PINMUX_PF01P_PTC_DRV31                     ((PIN_PF01P_PTC_DRV31 << 16) | MUX_PF01P_PTC_DRV31)
#define PORT_PF01P_PTC_DRV31                       (_UINT32_(1) << 1)

#define PIN_PC02P_PTC_ECI0                         _UINT32_(66)
#define MUX_PC02P_PTC_ECI0                         _UINT32_(15)
#define PINMUX_PC02P_PTC_ECI0                      ((PIN_PC02P_PTC_ECI0 << 16) | MUX_PC02P_PTC_ECI0)
#define PORT_PC02P_PTC_ECI0                        (_UINT32_(1) << 2)

#define PIN_PC03P_PTC_ECI1                         _UINT32_(67)
#define MUX_PC03P_PTC_ECI1                         _UINT32_(15)
#define PINMUX_PC03P_PTC_ECI1                      ((PIN_PC03P_PTC_ECI1 << 16) | MUX_PC03P_PTC_ECI1)
#define PORT_PC03P_PTC_ECI1                        (_UINT32_(1) << 3)

/* ========== PORT definition for SDMMC0 peripheral ========== */
#define PIN_PC15I_SDMMC0_SDCD                      _UINT32_(79)
#define MUX_PC15I_SDMMC0_SDCD                      _UINT32_(8) 
#define PINMUX_PC15I_SDMMC0_SDCD                   ((PIN_PC15I_SDMMC0_SDCD << 16) | MUX_PC15I_SDMMC0_SDCD)
#define PORT_PC15I_SDMMC0_SDCD                     (_UINT32_(1) << 15)

#define PIN_PC08I_SDMMC0_SDCK                      _UINT32_(72)
#define MUX_PC08I_SDMMC0_SDCK                      _UINT32_(8) 
#define PINMUX_PC08I_SDMMC0_SDCK                   ((PIN_PC08I_SDMMC0_SDCK << 16) | MUX_PC08I_SDMMC0_SDCK)
#define PORT_PC08I_SDMMC0_SDCK                     (_UINT32_(1) << 8)

#define PIN_PC13I_SDMMC0_SDCMD                     _UINT32_(77)
#define MUX_PC13I_SDMMC0_SDCMD                     _UINT32_(8) 
#define PINMUX_PC13I_SDMMC0_SDCMD                  ((PIN_PC13I_SDMMC0_SDCMD << 16) | MUX_PC13I_SDMMC0_SDCMD)
#define PORT_PC13I_SDMMC0_SDCMD                    (_UINT32_(1) << 13)

#define PIN_PC09I_SDMMC0_SDDAT0                    _UINT32_(73)
#define MUX_PC09I_SDMMC0_SDDAT0                    _UINT32_(8) 
#define PINMUX_PC09I_SDMMC0_SDDAT0                 ((PIN_PC09I_SDMMC0_SDDAT0 << 16) | MUX_PC09I_SDMMC0_SDDAT0)
#define PORT_PC09I_SDMMC0_SDDAT0                   (_UINT32_(1) << 9)

#define PIN_PC10I_SDMMC0_SDDAT1                    _UINT32_(74)
#define MUX_PC10I_SDMMC0_SDDAT1                    _UINT32_(8) 
#define PINMUX_PC10I_SDMMC0_SDDAT1                 ((PIN_PC10I_SDMMC0_SDDAT1 << 16) | MUX_PC10I_SDMMC0_SDDAT1)
#define PORT_PC10I_SDMMC0_SDDAT1                   (_UINT32_(1) << 10)

#define PIN_PC11I_SDMMC0_SDDAT2                    _UINT32_(75)
#define MUX_PC11I_SDMMC0_SDDAT2                    _UINT32_(8) 
#define PINMUX_PC11I_SDMMC0_SDDAT2                 ((PIN_PC11I_SDMMC0_SDDAT2 << 16) | MUX_PC11I_SDMMC0_SDDAT2)
#define PORT_PC11I_SDMMC0_SDDAT2                   (_UINT32_(1) << 11)

#define PIN_PC12I_SDMMC0_SDDAT3                    _UINT32_(76)
#define MUX_PC12I_SDMMC0_SDDAT3                    _UINT32_(8) 
#define PINMUX_PC12I_SDMMC0_SDDAT3                 ((PIN_PC12I_SDMMC0_SDDAT3 << 16) | MUX_PC12I_SDMMC0_SDDAT3)
#define PORT_PC12I_SDMMC0_SDDAT3                   (_UINT32_(1) << 12)

#define PIN_PC14I_SDMMC0_SDWP                      _UINT32_(78)
#define MUX_PC14I_SDMMC0_SDWP                      _UINT32_(8) 
#define PINMUX_PC14I_SDMMC0_SDWP                   ((PIN_PC14I_SDMMC0_SDWP << 16) | MUX_PC14I_SDMMC0_SDWP)
#define PORT_PC14I_SDMMC0_SDWP                     (_UINT32_(1) << 14)

/* ========== PORT definition for SDMMC1 peripheral ========== */
#define PIN_PC28I_SDMMC1_SDCD                      _UINT32_(92)
#define MUX_PC28I_SDMMC1_SDCD                      _UINT32_(8) 
#define PINMUX_PC28I_SDMMC1_SDCD                   ((PIN_PC28I_SDMMC1_SDCD << 16) | MUX_PC28I_SDMMC1_SDCD)
#define PORT_PC28I_SDMMC1_SDCD                     (_UINT32_(1) << 28)

#define PIN_PC30I_SDMMC1_SDCK                      _UINT32_(94)
#define MUX_PC30I_SDMMC1_SDCK                      _UINT32_(8) 
#define PINMUX_PC30I_SDMMC1_SDCK                   ((PIN_PC30I_SDMMC1_SDCK << 16) | MUX_PC30I_SDMMC1_SDCK)
#define PORT_PC30I_SDMMC1_SDCK                     (_UINT32_(1) << 30)

#define PIN_PG03I_SDMMC1_SDCMD                     _UINT32_(195)
#define MUX_PG03I_SDMMC1_SDCMD                     _UINT32_(8) 
#define PINMUX_PG03I_SDMMC1_SDCMD                  ((PIN_PG03I_SDMMC1_SDCMD << 16) | MUX_PG03I_SDMMC1_SDCMD)
#define PORT_PG03I_SDMMC1_SDCMD                    (_UINT32_(1) << 3)

#define PIN_PC31I_SDMMC1_SDDAT0                    _UINT32_(95)
#define MUX_PC31I_SDMMC1_SDDAT0                    _UINT32_(8) 
#define PINMUX_PC31I_SDMMC1_SDDAT0                 ((PIN_PC31I_SDMMC1_SDDAT0 << 16) | MUX_PC31I_SDMMC1_SDDAT0)
#define PORT_PC31I_SDMMC1_SDDAT0                   (_UINT32_(1) << 31)

#define PIN_PG00I_SDMMC1_SDDAT1                    _UINT32_(192)
#define MUX_PG00I_SDMMC1_SDDAT1                    _UINT32_(8) 
#define PINMUX_PG00I_SDMMC1_SDDAT1                 ((PIN_PG00I_SDMMC1_SDDAT1 << 16) | MUX_PG00I_SDMMC1_SDDAT1)
#define PORT_PG00I_SDMMC1_SDDAT1                   (_UINT32_(1) << 0)

#define PIN_PG01I_SDMMC1_SDDAT2                    _UINT32_(193)
#define MUX_PG01I_SDMMC1_SDDAT2                    _UINT32_(8) 
#define PINMUX_PG01I_SDMMC1_SDDAT2                 ((PIN_PG01I_SDMMC1_SDDAT2 << 16) | MUX_PG01I_SDMMC1_SDDAT2)
#define PORT_PG01I_SDMMC1_SDDAT2                   (_UINT32_(1) << 1)

#define PIN_PG02I_SDMMC1_SDDAT3                    _UINT32_(194)
#define MUX_PG02I_SDMMC1_SDDAT3                    _UINT32_(8) 
#define PINMUX_PG02I_SDMMC1_SDDAT3                 ((PIN_PG02I_SDMMC1_SDDAT3 << 16) | MUX_PG02I_SDMMC1_SDDAT3)
#define PORT_PG02I_SDMMC1_SDDAT3                   (_UINT32_(1) << 2)

#define PIN_PC27I_SDMMC1_SDWP                      _UINT32_(91)
#define MUX_PC27I_SDMMC1_SDWP                      _UINT32_(8) 
#define PINMUX_PC27I_SDMMC1_SDWP                   ((PIN_PC27I_SDMMC1_SDWP << 16) | MUX_PC27I_SDMMC1_SDWP)
#define PORT_PC27I_SDMMC1_SDWP                     (_UINT32_(1) << 27)

/* ========== PORT definition for SERCOM0 peripheral ========== */
#define PIN_PC00D_SERCOM0_PAD0                     _UINT32_(64)
#define MUX_PC00D_SERCOM0_PAD0                     _UINT32_(3) 
#define PINMUX_PC00D_SERCOM0_PAD0                  ((PIN_PC00D_SERCOM0_PAD0 << 16) | MUX_PC00D_SERCOM0_PAD0)
#define PORT_PC00D_SERCOM0_PAD0                    (_UINT32_(1) << 0)

#define PIN_PC01D_SERCOM0_PAD1                     _UINT32_(65)
#define MUX_PC01D_SERCOM0_PAD1                     _UINT32_(3) 
#define PINMUX_PC01D_SERCOM0_PAD1                  ((PIN_PC01D_SERCOM0_PAD1 << 16) | MUX_PC01D_SERCOM0_PAD1)
#define PORT_PC01D_SERCOM0_PAD1                    (_UINT32_(1) << 1)

#define PIN_PC02D_SERCOM0_PAD2                     _UINT32_(66)
#define MUX_PC02D_SERCOM0_PAD2                     _UINT32_(3) 
#define PINMUX_PC02D_SERCOM0_PAD2                  ((PIN_PC02D_SERCOM0_PAD2 << 16) | MUX_PC02D_SERCOM0_PAD2)
#define PORT_PC02D_SERCOM0_PAD2                    (_UINT32_(1) << 2)

#define PIN_PC03D_SERCOM0_PAD3                     _UINT32_(67)
#define MUX_PC03D_SERCOM0_PAD3                     _UINT32_(3) 
#define PINMUX_PC03D_SERCOM0_PAD3                  ((PIN_PC03D_SERCOM0_PAD3 << 16) | MUX_PC03D_SERCOM0_PAD3)
#define PORT_PC03D_SERCOM0_PAD3                    (_UINT32_(1) << 3)

/* ========== PORT definition for SERCOM1 peripheral ========== */
#define PIN_PC04D_SERCOM1_PAD0                     _UINT32_(68)
#define MUX_PC04D_SERCOM1_PAD0                     _UINT32_(3) 
#define PINMUX_PC04D_SERCOM1_PAD0                  ((PIN_PC04D_SERCOM1_PAD0 << 16) | MUX_PC04D_SERCOM1_PAD0)
#define PORT_PC04D_SERCOM1_PAD0                    (_UINT32_(1) << 4)

#define PIN_PC20D_SERCOM1_PAD0                     _UINT32_(84)
#define MUX_PC20D_SERCOM1_PAD0                     _UINT32_(3) 
#define PINMUX_PC20D_SERCOM1_PAD0                  ((PIN_PC20D_SERCOM1_PAD0 << 16) | MUX_PC20D_SERCOM1_PAD0)
#define PORT_PC20D_SERCOM1_PAD0                    (_UINT32_(1) << 20)

#define PIN_PC05D_SERCOM1_PAD1                     _UINT32_(69)
#define MUX_PC05D_SERCOM1_PAD1                     _UINT32_(3) 
#define PINMUX_PC05D_SERCOM1_PAD1                  ((PIN_PC05D_SERCOM1_PAD1 << 16) | MUX_PC05D_SERCOM1_PAD1)
#define PORT_PC05D_SERCOM1_PAD1                    (_UINT32_(1) << 5)

#define PIN_PC19D_SERCOM1_PAD1                     _UINT32_(83)
#define MUX_PC19D_SERCOM1_PAD1                     _UINT32_(3) 
#define PINMUX_PC19D_SERCOM1_PAD1                  ((PIN_PC19D_SERCOM1_PAD1 << 16) | MUX_PC19D_SERCOM1_PAD1)
#define PORT_PC19D_SERCOM1_PAD1                    (_UINT32_(1) << 19)

#define PIN_PC06D_SERCOM1_PAD2                     _UINT32_(70)
#define MUX_PC06D_SERCOM1_PAD2                     _UINT32_(3) 
#define PINMUX_PC06D_SERCOM1_PAD2                  ((PIN_PC06D_SERCOM1_PAD2 << 16) | MUX_PC06D_SERCOM1_PAD2)
#define PORT_PC06D_SERCOM1_PAD2                    (_UINT32_(1) << 6)

#define PIN_PC18D_SERCOM1_PAD2                     _UINT32_(82)
#define MUX_PC18D_SERCOM1_PAD2                     _UINT32_(3) 
#define PINMUX_PC18D_SERCOM1_PAD2                  ((PIN_PC18D_SERCOM1_PAD2 << 16) | MUX_PC18D_SERCOM1_PAD2)
#define PORT_PC18D_SERCOM1_PAD2                    (_UINT32_(1) << 18)

#define PIN_PC07D_SERCOM1_PAD3                     _UINT32_(71)
#define MUX_PC07D_SERCOM1_PAD3                     _UINT32_(3) 
#define PINMUX_PC07D_SERCOM1_PAD3                  ((PIN_PC07D_SERCOM1_PAD3 << 16) | MUX_PC07D_SERCOM1_PAD3)
#define PORT_PC07D_SERCOM1_PAD3                    (_UINT32_(1) << 7)

#define PIN_PC17D_SERCOM1_PAD3                     _UINT32_(81)
#define MUX_PC17D_SERCOM1_PAD3                     _UINT32_(3) 
#define PINMUX_PC17D_SERCOM1_PAD3                  ((PIN_PC17D_SERCOM1_PAD3 << 16) | MUX_PC17D_SERCOM1_PAD3)
#define PORT_PC17D_SERCOM1_PAD3                    (_UINT32_(1) << 17)

/* ========== PORT definition for SERCOM2 peripheral ========== */
#define PIN_PC08D_SERCOM2_PAD0                     _UINT32_(72)
#define MUX_PC08D_SERCOM2_PAD0                     _UINT32_(3) 
#define PINMUX_PC08D_SERCOM2_PAD0                  ((PIN_PC08D_SERCOM2_PAD0 << 16) | MUX_PC08D_SERCOM2_PAD0)
#define PORT_PC08D_SERCOM2_PAD0                    (_UINT32_(1) << 8)

#define PIN_PD11D_SERCOM2_PAD0                     _UINT32_(107)
#define MUX_PD11D_SERCOM2_PAD0                     _UINT32_(3) 
#define PINMUX_PD11D_SERCOM2_PAD0                  ((PIN_PD11D_SERCOM2_PAD0 << 16) | MUX_PD11D_SERCOM2_PAD0)
#define PORT_PD11D_SERCOM2_PAD0                    (_UINT32_(1) << 11)

#define PIN_PC09D_SERCOM2_PAD1                     _UINT32_(73)
#define MUX_PC09D_SERCOM2_PAD1                     _UINT32_(3) 
#define PINMUX_PC09D_SERCOM2_PAD1                  ((PIN_PC09D_SERCOM2_PAD1 << 16) | MUX_PC09D_SERCOM2_PAD1)
#define PORT_PC09D_SERCOM2_PAD1                    (_UINT32_(1) << 9)

#define PIN_PD12D_SERCOM2_PAD1                     _UINT32_(108)
#define MUX_PD12D_SERCOM2_PAD1                     _UINT32_(3) 
#define PINMUX_PD12D_SERCOM2_PAD1                  ((PIN_PD12D_SERCOM2_PAD1 << 16) | MUX_PD12D_SERCOM2_PAD1)
#define PORT_PD12D_SERCOM2_PAD1                    (_UINT32_(1) << 12)

#define PIN_PC10D_SERCOM2_PAD2                     _UINT32_(74)
#define MUX_PC10D_SERCOM2_PAD2                     _UINT32_(3) 
#define PINMUX_PC10D_SERCOM2_PAD2                  ((PIN_PC10D_SERCOM2_PAD2 << 16) | MUX_PC10D_SERCOM2_PAD2)
#define PORT_PC10D_SERCOM2_PAD2                    (_UINT32_(1) << 10)

#define PIN_PA04D_SERCOM2_PAD2                     _UINT32_(4) 
#define MUX_PA04D_SERCOM2_PAD2                     _UINT32_(3) 
#define PINMUX_PA04D_SERCOM2_PAD2                  ((PIN_PA04D_SERCOM2_PAD2 << 16) | MUX_PA04D_SERCOM2_PAD2)
#define PORT_PA04D_SERCOM2_PAD2                    (_UINT32_(1) << 4)

#define PIN_PC11D_SERCOM2_PAD3                     _UINT32_(75)
#define MUX_PC11D_SERCOM2_PAD3                     _UINT32_(3) 
#define PINMUX_PC11D_SERCOM2_PAD3                  ((PIN_PC11D_SERCOM2_PAD3 << 16) | MUX_PC11D_SERCOM2_PAD3)
#define PORT_PC11D_SERCOM2_PAD3                    (_UINT32_(1) << 11)

#define PIN_PA03D_SERCOM2_PAD3                     _UINT32_(3) 
#define MUX_PA03D_SERCOM2_PAD3                     _UINT32_(3) 
#define PINMUX_PA03D_SERCOM2_PAD3                  ((PIN_PA03D_SERCOM2_PAD3 << 16) | MUX_PA03D_SERCOM2_PAD3)
#define PORT_PA03D_SERCOM2_PAD3                    (_UINT32_(1) << 3)

/* ========== PORT definition for SERCOM3 peripheral ========== */
#define PIN_PC12D_SERCOM3_PAD0                     _UINT32_(76)
#define MUX_PC12D_SERCOM3_PAD0                     _UINT32_(3) 
#define PINMUX_PC12D_SERCOM3_PAD0                  ((PIN_PC12D_SERCOM3_PAD0 << 16) | MUX_PC12D_SERCOM3_PAD0)
#define PORT_PC12D_SERCOM3_PAD0                    (_UINT32_(1) << 12)

#define PIN_PD03D_SERCOM3_PAD0                     _UINT32_(99)
#define MUX_PD03D_SERCOM3_PAD0                     _UINT32_(3) 
#define PINMUX_PD03D_SERCOM3_PAD0                  ((PIN_PD03D_SERCOM3_PAD0 << 16) | MUX_PD03D_SERCOM3_PAD0)
#define PORT_PD03D_SERCOM3_PAD0                    (_UINT32_(1) << 3)

#define PIN_PC13D_SERCOM3_PAD1                     _UINT32_(77)
#define MUX_PC13D_SERCOM3_PAD1                     _UINT32_(3) 
#define PINMUX_PC13D_SERCOM3_PAD1                  ((PIN_PC13D_SERCOM3_PAD1 << 16) | MUX_PC13D_SERCOM3_PAD1)
#define PORT_PC13D_SERCOM3_PAD1                    (_UINT32_(1) << 13)

#define PIN_PD04D_SERCOM3_PAD1                     _UINT32_(100)
#define MUX_PD04D_SERCOM3_PAD1                     _UINT32_(3) 
#define PINMUX_PD04D_SERCOM3_PAD1                  ((PIN_PD04D_SERCOM3_PAD1 << 16) | MUX_PD04D_SERCOM3_PAD1)
#define PORT_PD04D_SERCOM3_PAD1                    (_UINT32_(1) << 4)

#define PIN_PC14D_SERCOM3_PAD2                     _UINT32_(78)
#define MUX_PC14D_SERCOM3_PAD2                     _UINT32_(3) 
#define PINMUX_PC14D_SERCOM3_PAD2                  ((PIN_PC14D_SERCOM3_PAD2 << 16) | MUX_PC14D_SERCOM3_PAD2)
#define PORT_PC14D_SERCOM3_PAD2                    (_UINT32_(1) << 14)

#define PIN_PD05D_SERCOM3_PAD2                     _UINT32_(101)
#define MUX_PD05D_SERCOM3_PAD2                     _UINT32_(3) 
#define PINMUX_PD05D_SERCOM3_PAD2                  ((PIN_PD05D_SERCOM3_PAD2 << 16) | MUX_PD05D_SERCOM3_PAD2)
#define PORT_PD05D_SERCOM3_PAD2                    (_UINT32_(1) << 5)

#define PIN_PC15D_SERCOM3_PAD3                     _UINT32_(79)
#define MUX_PC15D_SERCOM3_PAD3                     _UINT32_(3) 
#define PINMUX_PC15D_SERCOM3_PAD3                  ((PIN_PC15D_SERCOM3_PAD3 << 16) | MUX_PC15D_SERCOM3_PAD3)
#define PORT_PC15D_SERCOM3_PAD3                    (_UINT32_(1) << 15)

#define PIN_PD06D_SERCOM3_PAD3                     _UINT32_(102)
#define MUX_PD06D_SERCOM3_PAD3                     _UINT32_(3) 
#define PINMUX_PD06D_SERCOM3_PAD3                  ((PIN_PD06D_SERCOM3_PAD3 << 16) | MUX_PD06D_SERCOM3_PAD3)
#define PORT_PD06D_SERCOM3_PAD3                    (_UINT32_(1) << 6)

/* ========== PORT definition for SERCOM4 peripheral ========== */
#define PIN_PC21D_SERCOM4_PAD0                     _UINT32_(85)
#define MUX_PC21D_SERCOM4_PAD0                     _UINT32_(3) 
#define PINMUX_PC21D_SERCOM4_PAD0                  ((PIN_PC21D_SERCOM4_PAD0 << 16) | MUX_PC21D_SERCOM4_PAD0)
#define PORT_PC21D_SERCOM4_PAD0                    (_UINT32_(1) << 21)

#define PIN_PC22D_SERCOM4_PAD1                     _UINT32_(86)
#define MUX_PC22D_SERCOM4_PAD1                     _UINT32_(3) 
#define PINMUX_PC22D_SERCOM4_PAD1                  ((PIN_PC22D_SERCOM4_PAD1 << 16) | MUX_PC22D_SERCOM4_PAD1)
#define PORT_PC22D_SERCOM4_PAD1                    (_UINT32_(1) << 22)

#define PIN_PC23D_SERCOM4_PAD2                     _UINT32_(87)
#define MUX_PC23D_SERCOM4_PAD2                     _UINT32_(3) 
#define PINMUX_PC23D_SERCOM4_PAD2                  ((PIN_PC23D_SERCOM4_PAD2 << 16) | MUX_PC23D_SERCOM4_PAD2)
#define PORT_PC23D_SERCOM4_PAD2                    (_UINT32_(1) << 23)

#define PIN_PC24D_SERCOM4_PAD3                     _UINT32_(88)
#define MUX_PC24D_SERCOM4_PAD3                     _UINT32_(3) 
#define PINMUX_PC24D_SERCOM4_PAD3                  ((PIN_PC24D_SERCOM4_PAD3 << 16) | MUX_PC24D_SERCOM4_PAD3)
#define PORT_PC24D_SERCOM4_PAD3                    (_UINT32_(1) << 24)

/* ========== PORT definition for SERCOM5 peripheral ========== */
#define PIN_PC25D_SERCOM5_PAD0                     _UINT32_(89)
#define MUX_PC25D_SERCOM5_PAD0                     _UINT32_(3) 
#define PINMUX_PC25D_SERCOM5_PAD0                  ((PIN_PC25D_SERCOM5_PAD0 << 16) | MUX_PC25D_SERCOM5_PAD0)
#define PORT_PC25D_SERCOM5_PAD0                    (_UINT32_(1) << 25)

#define PIN_PC26D_SERCOM5_PAD1                     _UINT32_(90)
#define MUX_PC26D_SERCOM5_PAD1                     _UINT32_(3) 
#define PINMUX_PC26D_SERCOM5_PAD1                  ((PIN_PC26D_SERCOM5_PAD1 << 16) | MUX_PC26D_SERCOM5_PAD1)
#define PORT_PC26D_SERCOM5_PAD1                    (_UINT32_(1) << 26)

#define PIN_PC27D_SERCOM5_PAD2                     _UINT32_(91)
#define MUX_PC27D_SERCOM5_PAD2                     _UINT32_(3) 
#define PINMUX_PC27D_SERCOM5_PAD2                  ((PIN_PC27D_SERCOM5_PAD2 << 16) | MUX_PC27D_SERCOM5_PAD2)
#define PORT_PC27D_SERCOM5_PAD2                    (_UINT32_(1) << 27)

#define PIN_PC28D_SERCOM5_PAD3                     _UINT32_(92)
#define MUX_PC28D_SERCOM5_PAD3                     _UINT32_(3) 
#define PINMUX_PC28D_SERCOM5_PAD3                  ((PIN_PC28D_SERCOM5_PAD3 << 16) | MUX_PC28D_SERCOM5_PAD3)
#define PORT_PC28D_SERCOM5_PAD3                    (_UINT32_(1) << 28)

/* ========== PORT definition for SERCOM6 peripheral ========== */
#define PIN_PC30D_SERCOM6_PAD0                     _UINT32_(94)
#define MUX_PC30D_SERCOM6_PAD0                     _UINT32_(3) 
#define PINMUX_PC30D_SERCOM6_PAD0                  ((PIN_PC30D_SERCOM6_PAD0 << 16) | MUX_PC30D_SERCOM6_PAD0)
#define PORT_PC30D_SERCOM6_PAD0                    (_UINT32_(1) << 30)

#define PIN_PC31D_SERCOM6_PAD1                     _UINT32_(95)
#define MUX_PC31D_SERCOM6_PAD1                     _UINT32_(3) 
#define PINMUX_PC31D_SERCOM6_PAD1                  ((PIN_PC31D_SERCOM6_PAD1 << 16) | MUX_PC31D_SERCOM6_PAD1)
#define PORT_PC31D_SERCOM6_PAD1                    (_UINT32_(1) << 31)

#define PIN_PG00D_SERCOM6_PAD2                     _UINT32_(192)
#define MUX_PG00D_SERCOM6_PAD2                     _UINT32_(3) 
#define PINMUX_PG00D_SERCOM6_PAD2                  ((PIN_PG00D_SERCOM6_PAD2 << 16) | MUX_PG00D_SERCOM6_PAD2)
#define PORT_PG00D_SERCOM6_PAD2                    (_UINT32_(1) << 0)

#define PIN_PG01D_SERCOM6_PAD3                     _UINT32_(193)
#define MUX_PG01D_SERCOM6_PAD3                     _UINT32_(3) 
#define PINMUX_PG01D_SERCOM6_PAD3                  ((PIN_PG01D_SERCOM6_PAD3 << 16) | MUX_PG01D_SERCOM6_PAD3)
#define PORT_PG01D_SERCOM6_PAD3                    (_UINT32_(1) << 1)

/* ========== PORT definition for SERCOM7 peripheral ========== */
#define PIN_PD14D_SERCOM7_PAD0                     _UINT32_(110)
#define MUX_PD14D_SERCOM7_PAD0                     _UINT32_(3) 
#define PINMUX_PD14D_SERCOM7_PAD0                  ((PIN_PD14D_SERCOM7_PAD0 << 16) | MUX_PD14D_SERCOM7_PAD0)
#define PORT_PD14D_SERCOM7_PAD0                    (_UINT32_(1) << 14)

#define PIN_PD15D_SERCOM7_PAD1                     _UINT32_(111)
#define MUX_PD15D_SERCOM7_PAD1                     _UINT32_(3) 
#define PINMUX_PD15D_SERCOM7_PAD1                  ((PIN_PD15D_SERCOM7_PAD1 << 16) | MUX_PD15D_SERCOM7_PAD1)
#define PORT_PD15D_SERCOM7_PAD1                    (_UINT32_(1) << 15)

#define PIN_PD16D_SERCOM7_PAD2                     _UINT32_(112)
#define MUX_PD16D_SERCOM7_PAD2                     _UINT32_(3) 
#define PINMUX_PD16D_SERCOM7_PAD2                  ((PIN_PD16D_SERCOM7_PAD2 << 16) | MUX_PD16D_SERCOM7_PAD2)
#define PORT_PD16D_SERCOM7_PAD2                    (_UINT32_(1) << 16)

#define PIN_PD17D_SERCOM7_PAD3                     _UINT32_(113)
#define MUX_PD17D_SERCOM7_PAD3                     _UINT32_(3) 
#define PINMUX_PD17D_SERCOM7_PAD3                  ((PIN_PD17D_SERCOM7_PAD3 << 16) | MUX_PD17D_SERCOM7_PAD3)
#define PORT_PD17D_SERCOM7_PAD3                    (_UINT32_(1) << 17)

/* ========== PORT definition for SERCOM8 peripheral ========== */
#define PIN_PD24D_SERCOM8_PAD0                     _UINT32_(120)
#define MUX_PD24D_SERCOM8_PAD0                     _UINT32_(3) 
#define PINMUX_PD24D_SERCOM8_PAD0                  ((PIN_PD24D_SERCOM8_PAD0 << 16) | MUX_PD24D_SERCOM8_PAD0)
#define PORT_PD24D_SERCOM8_PAD0                    (_UINT32_(1) << 24)

#define PIN_PD25D_SERCOM8_PAD1                     _UINT32_(121)
#define MUX_PD25D_SERCOM8_PAD1                     _UINT32_(3) 
#define PINMUX_PD25D_SERCOM8_PAD1                  ((PIN_PD25D_SERCOM8_PAD1 << 16) | MUX_PD25D_SERCOM8_PAD1)
#define PORT_PD25D_SERCOM8_PAD1                    (_UINT32_(1) << 25)

#define PIN_PD26D_SERCOM8_PAD2                     _UINT32_(122)
#define MUX_PD26D_SERCOM8_PAD2                     _UINT32_(3) 
#define PINMUX_PD26D_SERCOM8_PAD2                  ((PIN_PD26D_SERCOM8_PAD2 << 16) | MUX_PD26D_SERCOM8_PAD2)
#define PORT_PD26D_SERCOM8_PAD2                    (_UINT32_(1) << 26)

#define PIN_PD27D_SERCOM8_PAD3                     _UINT32_(123)
#define MUX_PD27D_SERCOM8_PAD3                     _UINT32_(3) 
#define PINMUX_PD27D_SERCOM8_PAD3                  ((PIN_PD27D_SERCOM8_PAD3 << 16) | MUX_PD27D_SERCOM8_PAD3)
#define PORT_PD27D_SERCOM8_PAD3                    (_UINT32_(1) << 27)

/* ========== PORT definition for SERCOM9 peripheral ========== */
#define PIN_PD28D_SERCOM9_PAD0                     _UINT32_(124)
#define MUX_PD28D_SERCOM9_PAD0                     _UINT32_(3) 
#define PINMUX_PD28D_SERCOM9_PAD0                  ((PIN_PD28D_SERCOM9_PAD0 << 16) | MUX_PD28D_SERCOM9_PAD0)
#define PORT_PD28D_SERCOM9_PAD0                    (_UINT32_(1) << 28)

#define PIN_PD29D_SERCOM9_PAD1                     _UINT32_(125)
#define MUX_PD29D_SERCOM9_PAD1                     _UINT32_(3) 
#define PINMUX_PD29D_SERCOM9_PAD1                  ((PIN_PD29D_SERCOM9_PAD1 << 16) | MUX_PD29D_SERCOM9_PAD1)
#define PORT_PD29D_SERCOM9_PAD1                    (_UINT32_(1) << 29)

#define PIN_PE04D_SERCOM9_PAD2                     _UINT32_(132)
#define MUX_PE04D_SERCOM9_PAD2                     _UINT32_(3) 
#define PINMUX_PE04D_SERCOM9_PAD2                  ((PIN_PE04D_SERCOM9_PAD2 << 16) | MUX_PE04D_SERCOM9_PAD2)
#define PORT_PE04D_SERCOM9_PAD2                    (_UINT32_(1) << 4)

#define PIN_PE05D_SERCOM9_PAD3                     _UINT32_(133)
#define MUX_PE05D_SERCOM9_PAD3                     _UINT32_(3) 
#define PINMUX_PE05D_SERCOM9_PAD3                  ((PIN_PE05D_SERCOM9_PAD3 << 16) | MUX_PE05D_SERCOM9_PAD3)
#define PORT_PE05D_SERCOM9_PAD3                    (_UINT32_(1) << 5)

/* ========== PORT definition for SPI_IXS0 peripheral ========== */
#define PIN_PC00J_SPI_IXS0_FSYNC                   _UINT32_(64)
#define MUX_PC00J_SPI_IXS0_FSYNC                   _UINT32_(9) 
#define PINMUX_PC00J_SPI_IXS0_FSYNC                ((PIN_PC00J_SPI_IXS0_FSYNC << 16) | MUX_PC00J_SPI_IXS0_FSYNC)
#define PORT_PC00J_SPI_IXS0_FSYNC                  (_UINT32_(1) << 0)

#define PIN_PD02J_SPI_IXS0_FSYNC                   _UINT32_(98)
#define MUX_PD02J_SPI_IXS0_FSYNC                   _UINT32_(9) 
#define PINMUX_PD02J_SPI_IXS0_FSYNC                ((PIN_PD02J_SPI_IXS0_FSYNC << 16) | MUX_PD02J_SPI_IXS0_FSYNC)
#define PORT_PD02J_SPI_IXS0_FSYNC                  (_UINT32_(1) << 2)

#define PIN_PC01J_SPI_IXS0_SCK                     _UINT32_(65)
#define MUX_PC01J_SPI_IXS0_SCK                     _UINT32_(9) 
#define PINMUX_PC01J_SPI_IXS0_SCK                  ((PIN_PC01J_SPI_IXS0_SCK << 16) | MUX_PC01J_SPI_IXS0_SCK)
#define PORT_PC01J_SPI_IXS0_SCK                    (_UINT32_(1) << 1)

#define PIN_PD04J_SPI_IXS0_SCK                     _UINT32_(100)
#define MUX_PD04J_SPI_IXS0_SCK                     _UINT32_(9) 
#define PINMUX_PD04J_SPI_IXS0_SCK                  ((PIN_PD04J_SPI_IXS0_SCK << 16) | MUX_PD04J_SPI_IXS0_SCK)
#define PORT_PD04J_SPI_IXS0_SCK                    (_UINT32_(1) << 4)

#define PIN_PC02J_SPI_IXS0_SDI                     _UINT32_(66)
#define MUX_PC02J_SPI_IXS0_SDI                     _UINT32_(9) 
#define PINMUX_PC02J_SPI_IXS0_SDI                  ((PIN_PC02J_SPI_IXS0_SDI << 16) | MUX_PC02J_SPI_IXS0_SDI)
#define PORT_PC02J_SPI_IXS0_SDI                    (_UINT32_(1) << 2)

#define PIN_PD03J_SPI_IXS0_SDI                     _UINT32_(99)
#define MUX_PD03J_SPI_IXS0_SDI                     _UINT32_(9) 
#define PINMUX_PD03J_SPI_IXS0_SDI                  ((PIN_PD03J_SPI_IXS0_SDI << 16) | MUX_PD03J_SPI_IXS0_SDI)
#define PORT_PD03J_SPI_IXS0_SDI                    (_UINT32_(1) << 3)

#define PIN_PC03J_SPI_IXS0_SDO                     _UINT32_(67)
#define MUX_PC03J_SPI_IXS0_SDO                     _UINT32_(9) 
#define PINMUX_PC03J_SPI_IXS0_SDO                  ((PIN_PC03J_SPI_IXS0_SDO << 16) | MUX_PC03J_SPI_IXS0_SDO)
#define PORT_PC03J_SPI_IXS0_SDO                    (_UINT32_(1) << 3)

#define PIN_PD05J_SPI_IXS0_SDO                     _UINT32_(101)
#define MUX_PD05J_SPI_IXS0_SDO                     _UINT32_(9) 
#define PINMUX_PD05J_SPI_IXS0_SDO                  ((PIN_PD05J_SPI_IXS0_SDO << 16) | MUX_PD05J_SPI_IXS0_SDO)
#define PORT_PD05J_SPI_IXS0_SDO                    (_UINT32_(1) << 5)

/* ========== PORT definition for SPI_IXS1 peripheral ========== */
#define PIN_PA30J_SPI_IXS1_FSYNC                   _UINT32_(30)
#define MUX_PA30J_SPI_IXS1_FSYNC                   _UINT32_(9) 
#define PINMUX_PA30J_SPI_IXS1_FSYNC                ((PIN_PA30J_SPI_IXS1_FSYNC << 16) | MUX_PA30J_SPI_IXS1_FSYNC)
#define PORT_PA30J_SPI_IXS1_FSYNC                  (_UINT32_(1) << 30)

#define PIN_PE01J_SPI_IXS1_SCK                     _UINT32_(129)
#define MUX_PE01J_SPI_IXS1_SCK                     _UINT32_(9) 
#define PINMUX_PE01J_SPI_IXS1_SCK                  ((PIN_PE01J_SPI_IXS1_SCK << 16) | MUX_PE01J_SPI_IXS1_SCK)
#define PORT_PE01J_SPI_IXS1_SCK                    (_UINT32_(1) << 1)

#define PIN_PE02J_SPI_IXS1_SDI                     _UINT32_(130)
#define MUX_PE02J_SPI_IXS1_SDI                     _UINT32_(9) 
#define PINMUX_PE02J_SPI_IXS1_SDI                  ((PIN_PE02J_SPI_IXS1_SDI << 16) | MUX_PE02J_SPI_IXS1_SDI)
#define PORT_PE02J_SPI_IXS1_SDI                    (_UINT32_(1) << 2)

#define PIN_PE00J_SPI_IXS1_SDO                     _UINT32_(128)
#define MUX_PE00J_SPI_IXS1_SDO                     _UINT32_(9) 
#define PINMUX_PE00J_SPI_IXS1_SDO                  ((PIN_PE00J_SPI_IXS1_SDO << 16) | MUX_PE00J_SPI_IXS1_SDO)
#define PORT_PE00J_SPI_IXS1_SDO                    (_UINT32_(1) << 0)

/* ========== PORT definition for SQI0 peripheral ========== */
#define PIN_PC08H_SQI0_CLK                         _UINT32_(72)
#define MUX_PC08H_SQI0_CLK                         _UINT32_(7) 
#define PINMUX_PC08H_SQI0_CLK                      ((PIN_PC08H_SQI0_CLK << 16) | MUX_PC08H_SQI0_CLK)
#define PORT_PC08H_SQI0_CLK                        (_UINT32_(1) << 8)

#define PIN_PC13H_SQI0_CS0                         _UINT32_(77)
#define MUX_PC13H_SQI0_CS0                         _UINT32_(7) 
#define PINMUX_PC13H_SQI0_CS0                      ((PIN_PC13H_SQI0_CS0 << 16) | MUX_PC13H_SQI0_CS0)
#define PORT_PC13H_SQI0_CS0                        (_UINT32_(1) << 13)

#define PIN_PC15H_SQI0_CS1                         _UINT32_(79)
#define MUX_PC15H_SQI0_CS1                         _UINT32_(7) 
#define PINMUX_PC15H_SQI0_CS1                      ((PIN_PC15H_SQI0_CS1 << 16) | MUX_PC15H_SQI0_CS1)
#define PORT_PC15H_SQI0_CS1                        (_UINT32_(1) << 15)

#define PIN_PC09H_SQI0_DATA0                       _UINT32_(73)
#define MUX_PC09H_SQI0_DATA0                       _UINT32_(7) 
#define PINMUX_PC09H_SQI0_DATA0                    ((PIN_PC09H_SQI0_DATA0 << 16) | MUX_PC09H_SQI0_DATA0)
#define PORT_PC09H_SQI0_DATA0                      (_UINT32_(1) << 9)

#define PIN_PC10H_SQI0_DATA1                       _UINT32_(74)
#define MUX_PC10H_SQI0_DATA1                       _UINT32_(7) 
#define PINMUX_PC10H_SQI0_DATA1                    ((PIN_PC10H_SQI0_DATA1 << 16) | MUX_PC10H_SQI0_DATA1)
#define PORT_PC10H_SQI0_DATA1                      (_UINT32_(1) << 10)

#define PIN_PC11H_SQI0_DATA2                       _UINT32_(75)
#define MUX_PC11H_SQI0_DATA2                       _UINT32_(7) 
#define PINMUX_PC11H_SQI0_DATA2                    ((PIN_PC11H_SQI0_DATA2 << 16) | MUX_PC11H_SQI0_DATA2)
#define PORT_PC11H_SQI0_DATA2                      (_UINT32_(1) << 11)

#define PIN_PC12H_SQI0_DATA3                       _UINT32_(76)
#define MUX_PC12H_SQI0_DATA3                       _UINT32_(7) 
#define PINMUX_PC12H_SQI0_DATA3                    ((PIN_PC12H_SQI0_DATA3 << 16) | MUX_PC12H_SQI0_DATA3)
#define PORT_PC12H_SQI0_DATA3                      (_UINT32_(1) << 12)

/* ========== PORT definition for SQI1 peripheral ========== */
#define PIN_PC30H_SQI1_CLK                         _UINT32_(94)
#define MUX_PC30H_SQI1_CLK                         _UINT32_(7) 
#define PINMUX_PC30H_SQI1_CLK                      ((PIN_PC30H_SQI1_CLK << 16) | MUX_PC30H_SQI1_CLK)
#define PORT_PC30H_SQI1_CLK                        (_UINT32_(1) << 30)

#define PIN_PG03H_SQI1_CS0                         _UINT32_(195)
#define MUX_PG03H_SQI1_CS0                         _UINT32_(7) 
#define PINMUX_PG03H_SQI1_CS0                      ((PIN_PG03H_SQI1_CS0 << 16) | MUX_PG03H_SQI1_CS0)
#define PORT_PG03H_SQI1_CS0                        (_UINT32_(1) << 3)

#define PIN_PC28H_SQI1_CS1                         _UINT32_(92)
#define MUX_PC28H_SQI1_CS1                         _UINT32_(7) 
#define PINMUX_PC28H_SQI1_CS1                      ((PIN_PC28H_SQI1_CS1 << 16) | MUX_PC28H_SQI1_CS1)
#define PORT_PC28H_SQI1_CS1                        (_UINT32_(1) << 28)

#define PIN_PC31H_SQI1_DATA0                       _UINT32_(95)
#define MUX_PC31H_SQI1_DATA0                       _UINT32_(7) 
#define PINMUX_PC31H_SQI1_DATA0                    ((PIN_PC31H_SQI1_DATA0 << 16) | MUX_PC31H_SQI1_DATA0)
#define PORT_PC31H_SQI1_DATA0                      (_UINT32_(1) << 31)

#define PIN_PG00H_SQI1_DATA1                       _UINT32_(192)
#define MUX_PG00H_SQI1_DATA1                       _UINT32_(7) 
#define PINMUX_PG00H_SQI1_DATA1                    ((PIN_PG00H_SQI1_DATA1 << 16) | MUX_PG00H_SQI1_DATA1)
#define PORT_PG00H_SQI1_DATA1                      (_UINT32_(1) << 0)

#define PIN_PG01H_SQI1_DATA2                       _UINT32_(193)
#define MUX_PG01H_SQI1_DATA2                       _UINT32_(7) 
#define PINMUX_PG01H_SQI1_DATA2                    ((PIN_PG01H_SQI1_DATA2 << 16) | MUX_PG01H_SQI1_DATA2)
#define PORT_PG01H_SQI1_DATA2                      (_UINT32_(1) << 1)

#define PIN_PG02H_SQI1_DATA3                       _UINT32_(194)
#define MUX_PG02H_SQI1_DATA3                       _UINT32_(7) 
#define PINMUX_PG02H_SQI1_DATA3                    ((PIN_PG02H_SQI1_DATA3 << 16) | MUX_PG02H_SQI1_DATA3)
#define PORT_PG02H_SQI1_DATA3                      (_UINT32_(1) << 2)

/* ========== PORT definition for TCC0 peripheral ========== */
#define PIN_PC00F_TCC0_WO0                         _UINT32_(64)
#define MUX_PC00F_TCC0_WO0                         _UINT32_(5) 
#define PINMUX_PC00F_TCC0_WO0                      ((PIN_PC00F_TCC0_WO0 << 16) | MUX_PC00F_TCC0_WO0)
#define PORT_PC00F_TCC0_WO0                        (_UINT32_(1) << 0)

#define PIN_PC01F_TCC0_WO1                         _UINT32_(65)
#define MUX_PC01F_TCC0_WO1                         _UINT32_(5) 
#define PINMUX_PC01F_TCC0_WO1                      ((PIN_PC01F_TCC0_WO1 << 16) | MUX_PC01F_TCC0_WO1)
#define PORT_PC01F_TCC0_WO1                        (_UINT32_(1) << 1)

#define PIN_PC02F_TCC0_WO2                         _UINT32_(66)
#define MUX_PC02F_TCC0_WO2                         _UINT32_(5) 
#define PINMUX_PC02F_TCC0_WO2                      ((PIN_PC02F_TCC0_WO2 << 16) | MUX_PC02F_TCC0_WO2)
#define PORT_PC02F_TCC0_WO2                        (_UINT32_(1) << 2)

#define PIN_PC03F_TCC0_WO3                         _UINT32_(67)
#define MUX_PC03F_TCC0_WO3                         _UINT32_(5) 
#define PINMUX_PC03F_TCC0_WO3                      ((PIN_PC03F_TCC0_WO3 << 16) | MUX_PC03F_TCC0_WO3)
#define PORT_PC03F_TCC0_WO3                        (_UINT32_(1) << 3)

#define PIN_PC04F_TCC0_WO4                         _UINT32_(68)
#define MUX_PC04F_TCC0_WO4                         _UINT32_(5) 
#define PINMUX_PC04F_TCC0_WO4                      ((PIN_PC04F_TCC0_WO4 << 16) | MUX_PC04F_TCC0_WO4)
#define PORT_PC04F_TCC0_WO4                        (_UINT32_(1) << 4)

#define PIN_PC05F_TCC0_WO5                         _UINT32_(69)
#define MUX_PC05F_TCC0_WO5                         _UINT32_(5) 
#define PINMUX_PC05F_TCC0_WO5                      ((PIN_PC05F_TCC0_WO5 << 16) | MUX_PC05F_TCC0_WO5)
#define PORT_PC05F_TCC0_WO5                        (_UINT32_(1) << 5)

#define PIN_PC06F_TCC0_WO6                         _UINT32_(70)
#define MUX_PC06F_TCC0_WO6                         _UINT32_(5) 
#define PINMUX_PC06F_TCC0_WO6                      ((PIN_PC06F_TCC0_WO6 << 16) | MUX_PC06F_TCC0_WO6)
#define PORT_PC06F_TCC0_WO6                        (_UINT32_(1) << 6)

#define PIN_PC07F_TCC0_WO7                         _UINT32_(71)
#define MUX_PC07F_TCC0_WO7                         _UINT32_(5) 
#define PINMUX_PC07F_TCC0_WO7                      ((PIN_PC07F_TCC0_WO7 << 16) | MUX_PC07F_TCC0_WO7)
#define PORT_PC07F_TCC0_WO7                        (_UINT32_(1) << 7)

/* ========== PORT definition for TCC1 peripheral ========== */
#define PIN_PB10F_TCC1_WO0                         _UINT32_(42)
#define MUX_PB10F_TCC1_WO0                         _UINT32_(5) 
#define PINMUX_PB10F_TCC1_WO0                      ((PIN_PB10F_TCC1_WO0 << 16) | MUX_PB10F_TCC1_WO0)
#define PORT_PB10F_TCC1_WO0                        (_UINT32_(1) << 10)

#define PIN_PB11F_TCC1_WO1                         _UINT32_(43)
#define MUX_PB11F_TCC1_WO1                         _UINT32_(5) 
#define PINMUX_PB11F_TCC1_WO1                      ((PIN_PB11F_TCC1_WO1 << 16) | MUX_PB11F_TCC1_WO1)
#define PORT_PB11F_TCC1_WO1                        (_UINT32_(1) << 11)

#define PIN_PB12F_TCC1_WO2                         _UINT32_(44)
#define MUX_PB12F_TCC1_WO2                         _UINT32_(5) 
#define PINMUX_PB12F_TCC1_WO2                      ((PIN_PB12F_TCC1_WO2 << 16) | MUX_PB12F_TCC1_WO2)
#define PORT_PB12F_TCC1_WO2                        (_UINT32_(1) << 12)

#define PIN_PB13F_TCC1_WO3                         _UINT32_(45)
#define MUX_PB13F_TCC1_WO3                         _UINT32_(5) 
#define PINMUX_PB13F_TCC1_WO3                      ((PIN_PB13F_TCC1_WO3 << 16) | MUX_PB13F_TCC1_WO3)
#define PORT_PB13F_TCC1_WO3                        (_UINT32_(1) << 13)

#define PIN_PB14F_TCC1_WO4                         _UINT32_(46)
#define MUX_PB14F_TCC1_WO4                         _UINT32_(5) 
#define PINMUX_PB14F_TCC1_WO4                      ((PIN_PB14F_TCC1_WO4 << 16) | MUX_PB14F_TCC1_WO4)
#define PORT_PB14F_TCC1_WO4                        (_UINT32_(1) << 14)

#define PIN_PB15F_TCC1_WO5                         _UINT32_(47)
#define MUX_PB15F_TCC1_WO5                         _UINT32_(5) 
#define PINMUX_PB15F_TCC1_WO5                      ((PIN_PB15F_TCC1_WO5 << 16) | MUX_PB15F_TCC1_WO5)
#define PORT_PB15F_TCC1_WO5                        (_UINT32_(1) << 15)

#define PIN_PB16F_TCC1_WO6                         _UINT32_(48)
#define MUX_PB16F_TCC1_WO6                         _UINT32_(5) 
#define PINMUX_PB16F_TCC1_WO6                      ((PIN_PB16F_TCC1_WO6 << 16) | MUX_PB16F_TCC1_WO6)
#define PORT_PB16F_TCC1_WO6                        (_UINT32_(1) << 16)

#define PIN_PB17F_TCC1_WO7                         _UINT32_(49)
#define MUX_PB17F_TCC1_WO7                         _UINT32_(5) 
#define PINMUX_PB17F_TCC1_WO7                      ((PIN_PB17F_TCC1_WO7 << 16) | MUX_PB17F_TCC1_WO7)
#define PORT_PB17F_TCC1_WO7                        (_UINT32_(1) << 17)

/* ========== PORT definition for TCC2 peripheral ========== */
#define PIN_PD10F_TCC2_WO0                         _UINT32_(106)
#define MUX_PD10F_TCC2_WO0                         _UINT32_(5) 
#define PINMUX_PD10F_TCC2_WO0                      ((PIN_PD10F_TCC2_WO0 << 16) | MUX_PD10F_TCC2_WO0)
#define PORT_PD10F_TCC2_WO0                        (_UINT32_(1) << 10)

#define PIN_PD26F_TCC2_WO0                         _UINT32_(122)
#define MUX_PD26F_TCC2_WO0                         _UINT32_(5) 
#define PINMUX_PD26F_TCC2_WO0                      ((PIN_PD26F_TCC2_WO0 << 16) | MUX_PD26F_TCC2_WO0)
#define PORT_PD26F_TCC2_WO0                        (_UINT32_(1) << 26)

#define PIN_PD11F_TCC2_WO1                         _UINT32_(107)
#define MUX_PD11F_TCC2_WO1                         _UINT32_(5) 
#define PINMUX_PD11F_TCC2_WO1                      ((PIN_PD11F_TCC2_WO1 << 16) | MUX_PD11F_TCC2_WO1)
#define PORT_PD11F_TCC2_WO1                        (_UINT32_(1) << 11)

#define PIN_PD27F_TCC2_WO1                         _UINT32_(123)
#define MUX_PD27F_TCC2_WO1                         _UINT32_(5) 
#define PINMUX_PD27F_TCC2_WO1                      ((PIN_PD27F_TCC2_WO1 << 16) | MUX_PD27F_TCC2_WO1)
#define PORT_PD27F_TCC2_WO1                        (_UINT32_(1) << 27)

#define PIN_PD12F_TCC2_WO2                         _UINT32_(108)
#define MUX_PD12F_TCC2_WO2                         _UINT32_(5) 
#define PINMUX_PD12F_TCC2_WO2                      ((PIN_PD12F_TCC2_WO2 << 16) | MUX_PD12F_TCC2_WO2)
#define PORT_PD12F_TCC2_WO2                        (_UINT32_(1) << 12)

#define PIN_PD28F_TCC2_WO2                         _UINT32_(124)
#define MUX_PD28F_TCC2_WO2                         _UINT32_(5) 
#define PINMUX_PD28F_TCC2_WO2                      ((PIN_PD28F_TCC2_WO2 << 16) | MUX_PD28F_TCC2_WO2)
#define PORT_PD28F_TCC2_WO2                        (_UINT32_(1) << 28)

#define PIN_PA04F_TCC2_WO3                         _UINT32_(4) 
#define MUX_PA04F_TCC2_WO3                         _UINT32_(5) 
#define PINMUX_PA04F_TCC2_WO3                      ((PIN_PA04F_TCC2_WO3 << 16) | MUX_PA04F_TCC2_WO3)
#define PORT_PA04F_TCC2_WO3                        (_UINT32_(1) << 4)

#define PIN_PD29F_TCC2_WO3                         _UINT32_(125)
#define MUX_PD29F_TCC2_WO3                         _UINT32_(5) 
#define PINMUX_PD29F_TCC2_WO3                      ((PIN_PD29F_TCC2_WO3 << 16) | MUX_PD29F_TCC2_WO3)
#define PORT_PD29F_TCC2_WO3                        (_UINT32_(1) << 29)

#define PIN_PA03F_TCC2_WO4                         _UINT32_(3) 
#define MUX_PA03F_TCC2_WO4                         _UINT32_(5) 
#define PINMUX_PA03F_TCC2_WO4                      ((PIN_PA03F_TCC2_WO4 << 16) | MUX_PA03F_TCC2_WO4)
#define PORT_PA03F_TCC2_WO4                        (_UINT32_(1) << 3)

#define PIN_PE04F_TCC2_WO4                         _UINT32_(132)
#define MUX_PE04F_TCC2_WO4                         _UINT32_(5) 
#define PINMUX_PE04F_TCC2_WO4                      ((PIN_PE04F_TCC2_WO4 << 16) | MUX_PE04F_TCC2_WO4)
#define PORT_PE04F_TCC2_WO4                        (_UINT32_(1) << 4)

#define PIN_PA02F_TCC2_WO5                         _UINT32_(2) 
#define MUX_PA02F_TCC2_WO5                         _UINT32_(5) 
#define PINMUX_PA02F_TCC2_WO5                      ((PIN_PA02F_TCC2_WO5 << 16) | MUX_PA02F_TCC2_WO5)
#define PORT_PA02F_TCC2_WO5                        (_UINT32_(1) << 2)

#define PIN_PE05F_TCC2_WO5                         _UINT32_(133)
#define MUX_PE05F_TCC2_WO5                         _UINT32_(5) 
#define PINMUX_PE05F_TCC2_WO5                      ((PIN_PE05F_TCC2_WO5 << 16) | MUX_PE05F_TCC2_WO5)
#define PORT_PE05F_TCC2_WO5                        (_UINT32_(1) << 5)

/* ========== PORT definition for TCC3 peripheral ========== */
#define PIN_PA05F_TCC3_WO0                         _UINT32_(5) 
#define MUX_PA05F_TCC3_WO0                         _UINT32_(5) 
#define PINMUX_PA05F_TCC3_WO0                      ((PIN_PA05F_TCC3_WO0 << 16) | MUX_PA05F_TCC3_WO0)
#define PORT_PA05F_TCC3_WO0                        (_UINT32_(1) << 5)

#define PIN_PA06F_TCC3_WO1                         _UINT32_(6) 
#define MUX_PA06F_TCC3_WO1                         _UINT32_(5) 
#define PINMUX_PA06F_TCC3_WO1                      ((PIN_PA06F_TCC3_WO1 << 16) | MUX_PA06F_TCC3_WO1)
#define PORT_PA06F_TCC3_WO1                        (_UINT32_(1) << 6)

/* ========== PORT definition for TCC4 peripheral ========== */
#define PIN_PC12F_TCC4_WO0                         _UINT32_(76)
#define MUX_PC12F_TCC4_WO0                         _UINT32_(5) 
#define PINMUX_PC12F_TCC4_WO0                      ((PIN_PC12F_TCC4_WO0 << 16) | MUX_PC12F_TCC4_WO0)
#define PORT_PC12F_TCC4_WO0                        (_UINT32_(1) << 12)

#define PIN_PC29F_TCC4_WO0                         _UINT32_(93)
#define MUX_PC29F_TCC4_WO0                         _UINT32_(5) 
#define PINMUX_PC29F_TCC4_WO0                      ((PIN_PC29F_TCC4_WO0 << 16) | MUX_PC29F_TCC4_WO0)
#define PORT_PC29F_TCC4_WO0                        (_UINT32_(1) << 29)

#define PIN_PC13F_TCC4_WO1                         _UINT32_(77)
#define MUX_PC13F_TCC4_WO1                         _UINT32_(5) 
#define PINMUX_PC13F_TCC4_WO1                      ((PIN_PC13F_TCC4_WO1 << 16) | MUX_PC13F_TCC4_WO1)
#define PORT_PC13F_TCC4_WO1                        (_UINT32_(1) << 13)

#define PIN_PD13F_TCC4_WO1                         _UINT32_(109)
#define MUX_PD13F_TCC4_WO1                         _UINT32_(5) 
#define PINMUX_PD13F_TCC4_WO1                      ((PIN_PD13F_TCC4_WO1 << 16) | MUX_PD13F_TCC4_WO1)
#define PORT_PD13F_TCC4_WO1                        (_UINT32_(1) << 13)

/* ========== PORT definition for TCC5 peripheral ========== */
#define PIN_PC08F_TCC5_WO0                         _UINT32_(72)
#define MUX_PC08F_TCC5_WO0                         _UINT32_(5) 
#define PINMUX_PC08F_TCC5_WO0                      ((PIN_PC08F_TCC5_WO0 << 16) | MUX_PC08F_TCC5_WO0)
#define PORT_PC08F_TCC5_WO0                        (_UINT32_(1) << 8)

#define PIN_PC23F_TCC5_WO0                         _UINT32_(87)
#define MUX_PC23F_TCC5_WO0                         _UINT32_(5) 
#define PINMUX_PC23F_TCC5_WO0                      ((PIN_PC23F_TCC5_WO0 << 16) | MUX_PC23F_TCC5_WO0)
#define PORT_PC23F_TCC5_WO0                        (_UINT32_(1) << 23)

#define PIN_PC09F_TCC5_WO1                         _UINT32_(73)
#define MUX_PC09F_TCC5_WO1                         _UINT32_(5) 
#define PINMUX_PC09F_TCC5_WO1                      ((PIN_PC09F_TCC5_WO1 << 16) | MUX_PC09F_TCC5_WO1)
#define PORT_PC09F_TCC5_WO1                        (_UINT32_(1) << 9)

#define PIN_PC24F_TCC5_WO1                         _UINT32_(88)
#define MUX_PC24F_TCC5_WO1                         _UINT32_(5) 
#define PINMUX_PC24F_TCC5_WO1                      ((PIN_PC24F_TCC5_WO1 << 16) | MUX_PC24F_TCC5_WO1)
#define PORT_PC24F_TCC5_WO1                        (_UINT32_(1) << 24)

/* ========== PORT definition for TCC6 peripheral ========== */
#define PIN_PC10F_TCC6_WO0                         _UINT32_(74)
#define MUX_PC10F_TCC6_WO0                         _UINT32_(5) 
#define PINMUX_PC10F_TCC6_WO0                      ((PIN_PC10F_TCC6_WO0 << 16) | MUX_PC10F_TCC6_WO0)
#define PORT_PC10F_TCC6_WO0                        (_UINT32_(1) << 10)

#define PIN_PC21F_TCC6_WO0                         _UINT32_(85)
#define MUX_PC21F_TCC6_WO0                         _UINT32_(5) 
#define PINMUX_PC21F_TCC6_WO0                      ((PIN_PC21F_TCC6_WO0 << 16) | MUX_PC21F_TCC6_WO0)
#define PORT_PC21F_TCC6_WO0                        (_UINT32_(1) << 21)

#define PIN_PC11F_TCC6_WO1                         _UINT32_(75)
#define MUX_PC11F_TCC6_WO1                         _UINT32_(5) 
#define PINMUX_PC11F_TCC6_WO1                      ((PIN_PC11F_TCC6_WO1 << 16) | MUX_PC11F_TCC6_WO1)
#define PORT_PC11F_TCC6_WO1                        (_UINT32_(1) << 11)

#define PIN_PC22F_TCC6_WO1                         _UINT32_(86)
#define MUX_PC22F_TCC6_WO1                         _UINT32_(5) 
#define PINMUX_PC22F_TCC6_WO1                      ((PIN_PC22F_TCC6_WO1 << 16) | MUX_PC22F_TCC6_WO1)
#define PORT_PC22F_TCC6_WO1                        (_UINT32_(1) << 22)

/* ========== PORT definition for TCC7 peripheral ========== */
#define PIN_PA22F_TCC7_WO0                         _UINT32_(22)
#define MUX_PA22F_TCC7_WO0                         _UINT32_(5) 
#define PINMUX_PA22F_TCC7_WO0                      ((PIN_PA22F_TCC7_WO0 << 16) | MUX_PA22F_TCC7_WO0)
#define PORT_PA22F_TCC7_WO0                        (_UINT32_(1) << 22)

#define PIN_PD08F_TCC7_WO0                         _UINT32_(104)
#define MUX_PD08F_TCC7_WO0                         _UINT32_(5) 
#define PINMUX_PD08F_TCC7_WO0                      ((PIN_PD08F_TCC7_WO0 << 16) | MUX_PD08F_TCC7_WO0)
#define PORT_PD08F_TCC7_WO0                        (_UINT32_(1) << 8)

#define PIN_PA23F_TCC7_WO1                         _UINT32_(23)
#define MUX_PA23F_TCC7_WO1                         _UINT32_(5) 
#define PINMUX_PA23F_TCC7_WO1                      ((PIN_PA23F_TCC7_WO1 << 16) | MUX_PA23F_TCC7_WO1)
#define PORT_PA23F_TCC7_WO1                        (_UINT32_(1) << 23)

#define PIN_PD07F_TCC7_WO1                         _UINT32_(103)
#define MUX_PD07F_TCC7_WO1                         _UINT32_(5) 
#define PINMUX_PD07F_TCC7_WO1                      ((PIN_PD07F_TCC7_WO1 << 16) | MUX_PD07F_TCC7_WO1)
#define PORT_PD07F_TCC7_WO1                        (_UINT32_(1) << 7)

/* ========== PORT definition for TCC8 peripheral ========== */
#define PIN_PA21F_TCC8_WO0                         _UINT32_(21)
#define MUX_PA21F_TCC8_WO0                         _UINT32_(5) 
#define PINMUX_PA21F_TCC8_WO0                      ((PIN_PA21F_TCC8_WO0 << 16) | MUX_PA21F_TCC8_WO0)
#define PORT_PA21F_TCC8_WO0                        (_UINT32_(1) << 21)

#define PIN_PC14F_TCC8_WO0                         _UINT32_(78)
#define MUX_PC14F_TCC8_WO0                         _UINT32_(5) 
#define PINMUX_PC14F_TCC8_WO0                      ((PIN_PC14F_TCC8_WO0 << 16) | MUX_PC14F_TCC8_WO0)
#define PORT_PC14F_TCC8_WO0                        (_UINT32_(1) << 14)

#define PIN_PC15F_TCC8_WO1                         _UINT32_(79)
#define MUX_PC15F_TCC8_WO1                         _UINT32_(5) 
#define PINMUX_PC15F_TCC8_WO1                      ((PIN_PC15F_TCC8_WO1 << 16) | MUX_PC15F_TCC8_WO1)
#define PORT_PC15F_TCC8_WO1                        (_UINT32_(1) << 15)

#define PIN_PD23F_TCC8_WO1                         _UINT32_(119)
#define MUX_PD23F_TCC8_WO1                         _UINT32_(5) 
#define PINMUX_PD23F_TCC8_WO1                      ((PIN_PD23F_TCC8_WO1 << 16) | MUX_PD23F_TCC8_WO1)
#define PORT_PD23F_TCC8_WO1                        (_UINT32_(1) << 23)

/* ========== PORT definition for TCC9 peripheral ========== */
#define PIN_PD04F_TCC9_WO0                         _UINT32_(100)
#define MUX_PD04F_TCC9_WO0                         _UINT32_(5) 
#define PINMUX_PD04F_TCC9_WO0                      ((PIN_PD04F_TCC9_WO0 << 16) | MUX_PD04F_TCC9_WO0)
#define PORT_PD04F_TCC9_WO0                        (_UINT32_(1) << 4)

#define PIN_PG05F_TCC9_WO0                         _UINT32_(197)
#define MUX_PG05F_TCC9_WO0                         _UINT32_(5) 
#define PINMUX_PG05F_TCC9_WO0                      ((PIN_PG05F_TCC9_WO0 << 16) | MUX_PG05F_TCC9_WO0)
#define PORT_PG05F_TCC9_WO0                        (_UINT32_(1) << 5)

#define PIN_PD05F_TCC9_WO1                         _UINT32_(101)
#define MUX_PD05F_TCC9_WO1                         _UINT32_(5) 
#define PINMUX_PD05F_TCC9_WO1                      ((PIN_PD05F_TCC9_WO1 << 16) | MUX_PD05F_TCC9_WO1)
#define PORT_PD05F_TCC9_WO1                        (_UINT32_(1) << 5)

#define PIN_PG06F_TCC9_WO1                         _UINT32_(198)
#define MUX_PG06F_TCC9_WO1                         _UINT32_(5) 
#define PINMUX_PG06F_TCC9_WO1                      ((PIN_PG06F_TCC9_WO1 << 16) | MUX_PG06F_TCC9_WO1)
#define PORT_PG06F_TCC9_WO1                        (_UINT32_(1) << 6)

#define PIN_PD06F_TCC9_WO2                         _UINT32_(102)
#define MUX_PD06F_TCC9_WO2                         _UINT32_(5) 
#define PINMUX_PD06F_TCC9_WO2                      ((PIN_PD06F_TCC9_WO2 << 16) | MUX_PD06F_TCC9_WO2)
#define PORT_PD06F_TCC9_WO2                        (_UINT32_(1) << 6)

#define PIN_PG07F_TCC9_WO2                         _UINT32_(199)
#define MUX_PG07F_TCC9_WO2                         _UINT32_(5) 
#define PINMUX_PG07F_TCC9_WO2                      ((PIN_PG07F_TCC9_WO2 << 16) | MUX_PG07F_TCC9_WO2)
#define PORT_PG07F_TCC9_WO2                        (_UINT32_(1) << 7)

#define PIN_PD03F_TCC9_WO3                         _UINT32_(99)
#define MUX_PD03F_TCC9_WO3                         _UINT32_(5) 
#define PINMUX_PD03F_TCC9_WO3                      ((PIN_PD03F_TCC9_WO3 << 16) | MUX_PD03F_TCC9_WO3)
#define PORT_PD03F_TCC9_WO3                        (_UINT32_(1) << 3)

#define PIN_PG09F_TCC9_WO3                         _UINT32_(201)
#define MUX_PG09F_TCC9_WO3                         _UINT32_(5) 
#define PINMUX_PG09F_TCC9_WO3                      ((PIN_PG09F_TCC9_WO3 << 16) | MUX_PG09F_TCC9_WO3)
#define PORT_PG09F_TCC9_WO3                        (_UINT32_(1) << 9)

#define PIN_PD02F_TCC9_WO4                         _UINT32_(98)
#define MUX_PD02F_TCC9_WO4                         _UINT32_(5) 
#define PINMUX_PD02F_TCC9_WO4                      ((PIN_PD02F_TCC9_WO4 << 16) | MUX_PD02F_TCC9_WO4)
#define PORT_PD02F_TCC9_WO4                        (_UINT32_(1) << 2)

#define PIN_PG10F_TCC9_WO4                         _UINT32_(202)
#define MUX_PG10F_TCC9_WO4                         _UINT32_(5) 
#define PINMUX_PG10F_TCC9_WO4                      ((PIN_PG10F_TCC9_WO4 << 16) | MUX_PG10F_TCC9_WO4)
#define PORT_PG10F_TCC9_WO4                        (_UINT32_(1) << 10)

#define PIN_PC20F_TCC9_WO5                         _UINT32_(84)
#define MUX_PC20F_TCC9_WO5                         _UINT32_(5) 
#define PINMUX_PC20F_TCC9_WO5                      ((PIN_PC20F_TCC9_WO5 << 16) | MUX_PC20F_TCC9_WO5)
#define PORT_PC20F_TCC9_WO5                        (_UINT32_(1) << 20)

#define PIN_PG11F_TCC9_WO5                         _UINT32_(203)
#define MUX_PG11F_TCC9_WO5                         _UINT32_(5) 
#define PINMUX_PG11F_TCC9_WO5                      ((PIN_PG11F_TCC9_WO5 << 16) | MUX_PG11F_TCC9_WO5)
#define PORT_PG11F_TCC9_WO5                        (_UINT32_(1) << 11)



#endif /* _PIC32CZ8110CA90208_GPIO_H_ */

