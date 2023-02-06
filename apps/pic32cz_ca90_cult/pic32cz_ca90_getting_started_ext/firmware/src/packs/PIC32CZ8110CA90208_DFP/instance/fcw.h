/*
 * Instance header file for PIC32CZ8110CA90208
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
#define FCW_PFM_NUM_PAGES                        (1024)     /* No of PFM Pages Per panel */
#define FCW_PFM_NUM_RR                           (8)        /* Flash Memory Parameters */
#define FCW_PFM_PAGE_ADDR_MSB                    (11)       /* Flash Page Size MSB */
#define FCW_PFM_PAGE_SIZE                        (4096)     /* PFM page size */
#define FCW_PFM_PNL_ADDR_MSB                     (21)       /* Single flash panel read address MSbit (using byte addressing) */
#define FCW_PFM_PNL_DATA_MSB                     (271)      /* Flash Memory Parameters */
#define FCW_PFM_ROW_ADDR_MSB                     (9)        /* Flash Memory Parameters */
#define FCW_PFM_SIZE                             (10)       /* Flash Memory Parameters */
#define FCW_PFM_SYS_ADDR_MSB                     (22)       /* The MS bit of the system byte address needed to address the entire PFM region (both panels Main) */
#define FCW_FLASH_SIZE                           (8388608)  
#define FCW_PAGES                                (2048)     
#define FCW_PAGES_PR_REGION                      (128)      
#define FCW_INSTANCE_ID                          (1)        /* Instance index for FCW */
#define FCW_MCLK_ID_AHB                          (2)        /* Index for FCW AHB clock */
#define FCW_MCLK_ID_APB                          (3)        /* Index for FCW APB clock */
#define FCW_PAC_ID                               (1)        /* Index for FCW registers write protection */

#endif /* _PIC32CZCA90_FCW_INSTANCE_ */
