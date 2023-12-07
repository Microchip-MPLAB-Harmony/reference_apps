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
#ifndef _PIC32CKSG01_FCW_INSTANCE_
#define _PIC32CKSG01_FCW_INSTANCE_


/* ========== Instance Parameter definitions for FCW peripheral ========== */
#define FCW_FLASH_SIZE                           (2097152)  
#define FCW_INSTANCE_ID                          (2)        /* Instance index for FCW */
#define FCW_MCLK_ID_AHB                          (5)        /* Index for FCW AHB clock */
#define FCW_MCLK_ID_APB                          (34)       /* Index for FCW APB clock */
#define FCW_PAC_ID                               (2)        /* Index for FCW registers write protection */
#define FCW_PAGES                                (512)      
#define FCW_PAGES_PR_REGION                      (32)       
#define FCW_PFM_NUM_PAGES                        (256)      /* No of PFM Pages Per panel */
#define FCW_PFM_PAGE_ADDR_MSB                    (11)       /* Flash Page Size MSB */
#define FCW_PFM_PAGE_SIZE                        (4096)     /* PFM page size */
#define FCW_PFM_PNL_ADDR_MSB                     (21)       /* Single flash panel read address MSbit (using byte addressing) */
#define FCW_PFM_SIZE                             (8)        /* Flash Memory Parameters */
#define FCW_PFM_SYS_ADDR_MSB                     (20)       /* The MS bit of the system byte address needed to address the entire PFM region (both panels Main) */

#endif /* _PIC32CKSG01_FCW_INSTANCE_ */
