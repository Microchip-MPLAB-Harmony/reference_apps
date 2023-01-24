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
#ifndef _PIC32CZCA80_SUPC_INSTANCE_
#define _PIC32CZCA80_SUPC_INSTANCE_


/* ========== Instance Parameter definitions for SUPC peripheral ========== */
#define SUPC_ADDVREG_NUM                         (3)        /* Number of additional capless regulators for USB, PLL, ... */
#define SUPC_ADDVREG_PLL_NUM                     (1)        /* Number of additional capless regulators dedicated to PLL(s) (between 0 and ADDVREG_NUM) */
#define SUPC_ADDVREG_PLL_START_INDEX             (2)        /* Index of the first additional capless regulator dedicated to a PLL within [ADDVREG_NUM-1:0] range. Must be equal to 1 if ADDVREG_PLL_NUM=0. */
#define SUPC_BKOUT_NUM                           (2)        /* Number of BKOUT output pin */
#define SUPC_BORVDDUSB_NUM                       (2)        /* Number of BOR_USB */
#define SUPC_CHRG_PUMP_NUM                       (3)        /* Number of Charge Pump */
#define SUPC_IOB_IMPLEMENTED                     (0)        /* one if IOB feature is implemented */
#define SUPC_USER_LDO_IMPLEMENTED                (0)        /* one if USER_LDO feature is implemented */
#define SUPC_VBAT_IMPLEMENTED                    (0)        /* one if VBAT feature (battery backup feature) is implemented. */
#define SUPC_VREGSW_NUM                          (4)        /* Number of main voltage regulator (100mA). Example: 1 for Unicorn, 4 for Riverside. */
#define SUPC_INSTANCE_ID                         (4)        /* Instance index for SUPC */
#define SUPC_MCLK_ID_APB                         (7)        /* Index for SUPC APB clock */
#define SUPC_PAC_ID                              (4)        /* Index for SUPC registers write protection */

#endif /* _PIC32CZCA80_SUPC_INSTANCE_ */
