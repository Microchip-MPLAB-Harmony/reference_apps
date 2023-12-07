/*
 * Instance header file for PIC32CK2051SG01144
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

/* file generated from device description file (ATDF) version 2023-11-16T06:44:02Z */
#ifndef _PIC32CKSG01_SUPC_INSTANCE_
#define _PIC32CKSG01_SUPC_INSTANCE_


/* ========== Instance Parameter definitions for SUPC peripheral ========== */
#define SUPC_ADDVREG_NUM                         (1)        /* Number of additional capless regulators for USB, PLL, ... */
#define SUPC_ADDVREG_PLL_NUM                     (0)        /* Number of additional capless regulators dedicated to PLL(s) (between 0 and ADDVREG_NUM) */
#define SUPC_ADDVREG_PLL_START_INDEX             (1)        /* Index of the first additional capless regulator dedicated to a PLL within [ADDVREG_NUM-1:0] range. Must be equal to 1 if ADDVREG_PLL_NUM=0. */
#define SUPC_BKOUT_NUM                           (2)        /* Number of BKOUT output pin */
#define SUPC_BORVDDUSB_NUM                       (1)        /* Number of BOR_USB */
#define SUPC_CHRG_PUMP_NUM                       (2)        /* Number of Charge Pump */
#define SUPC_INSTANCE_ID                         (4)        /* Instance index for SUPC */
#define SUPC_IOB_IMPLEMENTED                     (1)        /* one if IOB feature is implemented */
#define SUPC_MCLK_ID_APB                         (36)       /* Index for SUPC APB clock */
#define SUPC_PAC_ID                              (4)        /* Index for SUPC registers write protection */
#define SUPC_USER_LDO_IMPLEMENTED                (1)        /* one if USER_LDO feature is implemented */
#define SUPC_VBAT_IMPLEMENTED                    (1)        /* one if VBAT feature (battery backup feature) is implemented. */
#define SUPC_VREGSW_NUM                          (2)        /* Number of main voltage regulator (100mA). Example: 1 for Unicorn, 4 for Riverside. */

#endif /* _PIC32CKSG01_SUPC_INSTANCE_ */
