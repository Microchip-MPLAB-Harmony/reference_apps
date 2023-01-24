/*
 * Instance header file for PIC32CZ8110CA80208
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

/* file generated from device description version 2022-07-07T22:59:24Z */
#ifndef _PIC32CZCA80_OSCCTRL_INSTANCE_
#define _PIC32CZCA80_OSCCTRL_INSTANCE_


/* ========== Instance Parameter definitions for OSCCTRL peripheral ========== */
#define OSCCTRL_DFLL48M_ATEST_IMPLEMENTED        (1)        /* DFLL48M ATEST register implemented */
#define OSCCTRL_DFLL48M_ATEST_SIZE               (8)        /* number of effective bits in DFLL48M ATEST register */
#define OSCCTRL_DFLL48M_IS_STARTUP_OSCILLATOR    (1)        /* DFLL48M is startup oscillator */
#define OSCCTRL_DFLL48M_RC48MCAL0_PORVAL         (0x0)      /* Defines the RC48MCAL0 register reset value after POR. */
#define OSCCTRL_DIV_8MHZ_NUM                     (8)        
#define OSCCTRL_FRACDIVS_NUM                     (2)        /* Number of FRACDIVs */
#define OSCCTRL_FRACDIV_DIVIDER_RESET_VAL        (32)       /* Fracdiv Divider reset value */
#define OSCCTRL_FRACDIV_PLLSRC                   (1)        /* Indice of the PLL that is source of the FRACDIV */
#define OSCCTRL_GCLK_ID_DFLL48M                  (0)        /* Index of Generic Clock for DFLL48 */
#define OSCCTRL_GCLK_ID_PLL_0                    (1)        /* Index of Generic Clock for PLL 0 */
#define OSCCTRL_GCLK_ID_PLL_1                    (2)        /* Index of Generic Clock for PLL 1 */
#define OSCCTRL_PLLS_NUM                         (2)        /* Number of PLLs */
#define OSCCTRL_PLL0_OUTPUTS_NUM                 (4)        /* number of clock outputs for PLL0 */
#define OSCCTRL_PLL1_OUTPUTS_NUM                 (4)        /* number of clock outputs for PLL1 */
#define OSCCTRL_USBHS_NUM                        (2)        /* Number of usbhs clock requests */
#define OSCCTRL_XOSC_ATEST_IMPLEMENTED           (1)        /* XOSC ATEST register implemented */
#define OSCCTRL_XOSC_ATEST_SIZE                  (4)        /* number of effective bits in XOSC ATEST register */
#define OSCCTRL_XOSC_CFD_CLK_SELECT_SIZE         (4)        /* Clock fail prescaler size */
#define OSCCTRL_XOSC_CFD_HAS_RETENTION           (0)        /* Clock fail detected for xosc is in tetention domain */
#define OSCCTRL_INSTANCE_ID                      (6)        /* Instance index for OSCCTRL */
#define OSCCTRL_MCLK_ID_APB                      (9)        /* Index for OSCCTRL APB clock */
#define OSCCTRL_PAC_ID                           (6)        /* Index for OSCCTRL registers write protection */

#endif /* _PIC32CZCA80_OSCCTRL_INSTANCE_ */
