/*
 * Instance header file for PIC32CK2051GC01144
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
#ifndef _PIC32CKGC01_FCW_INSTANCE_
#define _PIC32CKGC01_FCW_INSTANCE_


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

#endif /* _PIC32CKGC01_FCW_INSTANCE_ */
