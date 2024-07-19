/*
 * Instance header file for PIC32CZ8110CA90208
 *
 * Copyright (c) 2024 Microchip Technology Inc. and its subsidiaries.
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

/* file generated from device description file (ATDF) version 2024-06-28T20:38:26Z */
#ifndef _PIC32CZCA90_FCW_INSTANCE_
#define _PIC32CZCA90_FCW_INSTANCE_


/* ========== Instance Parameter definitions for FCW peripheral ========== */
#define FCW_BFM_PNL_ADDR_MSB                     (15)       /* Flash Memory Parameters */
#define FCW_BFM_SYS_ADDR_MSB                     (16)       /* Flash Memory Parameters */
#define FCW_CFM_PNL_ADDR_MSB                     (14)       /* Flash Memory Parameters */
#define FCW_CFM_SYS_ADDR_MSB                     (15)       /* Flash Memory Parameters */
#define FCW_BFM_ADDR_BASE                        (0x06000000) /* Flash System Address (byte addresses) */
#define FCW_CFM_ADDR_BASE                        (0x07000000) /* Flash System Address (byte addresses) */
#define FCW_CPUS_PRESENT                         (3)        /* Flash System Address (byte addresses) */
#define FCW_DAL0_VALUE                           (0x81)     /* Flash System Address (byte addresses) */
#define FCW_DAL1_VALUE                           (0x99)     /* Flash System Address (byte addresses) */
#define FCW_DAL2_VALUE                           (0xDB)     /* Flash System Address (byte addresses) */
#define FCW_HSM_PRESENT                          (1)        /* Flash System Address (byte addresses) */
#define FCW_PADDR_MSB                            (10)       /* Flash System Address (byte addresses) */
#define FCW_PERIOD_MIN                           (75)       /* Flash System Address (byte addresses) */
#define FCW_PERIOD_NOM                           (116)      /* Flash System Address (byte addresses) */
#define FCW_PFM_ADDR_BASE                        (0x08000000) /* Flash System Address (byte addresses) */
#define FCW_FLASH_SIZE                           (8388608)  
#define FCW_INSTANCE_ID                          (1)        /* Instance index for FCW */
#define FCW_MCLK_ID_AHB                          (2)        /* Index for FCW AHB clock */
#define FCW_MCLK_ID_APB                          (3)        /* Index for FCW APB clock */
#define FCW_PAC_ID                               (1)        /* Index for FCW registers write protection */
#define FCW_PAGES                                (2048)     
#define FCW_PAGES_PR_REGION                      (128)      
#define FCW_PFM_NUM_PAGES                        (1024)     /* No of PFM Pages Per panel */
#define FCW_PFM_NUM_RR                           (8)        /* Flash Memory Parameters */
#define FCW_PFM_PAGE_ADDR_MSB                    (11)       /* Flash Page Size MSB */
#define FCW_PFM_PAGE_SIZE                        (4096)     /* PFM page size */
#define FCW_PFM_PNL_ADDR_MSB                     (21)       /* Single flash panel read address MSbit (using byte addressing) */
#define FCW_PFM_PNL_DATA_MSB                     (271)      /* Flash Memory Parameters */
#define FCW_PFM_ROW_ADDR_MSB                     (9)        /* Flash Memory Parameters */
#define FCW_PFM_SIZE                             (10)       /* Flash Memory Parameters */
#define FCW_PFM_SYS_ADDR_MSB                     (22)       /* The MS bit of the system byte address needed to address the entire PFM region (both panels Main) */

#endif /* _PIC32CZCA90_FCW_INSTANCE_ */
