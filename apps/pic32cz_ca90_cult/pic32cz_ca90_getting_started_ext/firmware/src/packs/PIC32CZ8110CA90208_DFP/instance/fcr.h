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
#ifndef _PIC32CZCA90_FCR_INSTANCE_
#define _PIC32CZCA90_FCR_INSTANCE_


/* ========== Instance Parameter definitions for FCR peripheral ========== */
#define FCR_BFM_PNL_ADDR_MSB                     (15)       /* Flash Memory Parameters */
#define FCR_BFM_SYS_ADDR_MSB                     (16)       /* Flash Memory Parameters */
#define FCR_CFM_ADDR_BASE                        (0x07000000) /* Flash Read Controller Parameters */
#define FCR_CFM_PNL_ADDR_MSB                     (14)       /* Flash Memory Parameters */
#define FCR_CFM_SYS_ADDR_MSB                     (15)       /* Flash Memory Parameters */
#define FCR_AHB_PORTS_NB                         (4)        /* Flash Read Controller Parameters */
#define FCR_BFM_ADDR_BASE                        (0x06000000) /* Flash Read Controller Parameters */
#define FCR_CAL_ADDR                             (6000000)  /* Flash Read Controller Parameters */
#define FCR_CAL_NUM_READS                        (4)        /* Flash Read Controller Parameters */
#define FCR_CRC_PRESENT                          (1)        /* Flash Read Controller Parameters */
#define FCR_DAL_ADDR                             (1)        /* Flash Read Controller Parameters */
#define FCR_ECC_PRESENT                          (1)        /* Flash Read Controller Parameters */
#define FCR_FFF_ADDR                             (1)        /* Flash Read Controller Parameters */
#define FCR_FLT_PRESENT                          (0)        /* Flash Read Controller Parameters */
#define FCR_FUSES_DATA_CYCLES                    (4)        /* Flash Read Controller Parameters */
#define FCR_FUSES_READY_CYCLES                   (1)        /* Flash Read Controller Parameters */
#define FCR_F1RR_ADDR                            (1)        /* Flash Read Controller Parameters */
#define FCR_F2RR_ADDR                            (1)        /* Flash Read Controller Parameters */
#define FCR_HDATA_SIZE                           (64)       /* Flash Read Controller Parameters */
#define FCR_HSM_CFG0_BASE                        (64)       /* Flash Read Controller Parameters */
#define FCR_HSM_CFG1_BASE                        (64)       /* Flash Read Controller Parameters */
#define FCR_HSM_CFG2_BASE                        (64)       /* Flash Read Controller Parameters */
#define FCR_HSM_CFG3_BASE                        (64)       /* Flash Read Controller Parameters */
#define FCR_HSM_PRESENT                          (1)        /* Flash Read Controller Parameters */
#define FCR_NOT_FFF_VALUE                        (0xA5A5A5A5) /* Flash Read Controller Parameters */
#define FCR_NO_ECC_BUS_ERROR                     (0)        /* Flash Read Controller Parameters */
#define FCR_OTPLOCK_ADDR                         (0)        /* Flash Read Controller Parameters */
#define FCR_PADDR_MSB                            (15)       /* Flash Read Controller Parameters */
#define FCR_PERIOD_MIN                           (75)       /* Flash Read Controller Parameters */
#define FCR_PERIOD_NOM                           (116)      /* Flash Read Controller Parameters */
#define FCR_PFM_ADDR_BASE                        (0x08000000) /* Flash Read Controller Parameters */
#define FCR_RR_NUM_READS                         (1)        /* Flash Read Controller Parameters */
#define FCR_TCALH_NS                             (10000)    /* Flash Read Controller Parameters */
#define FCR_FUSES_DATA_MSB                       (127)      /* Flash Read Controller Parameters */
#define FCR_FUSES_RDY_MSB                        (8)        /* Flash Read Controller Parameters */
#define FCR_NVR_NUM_PAGES                        (24)       /* Flash Memory Parameters */
#define FCR_PFM_ACC_HT_NS                        (30)       /* Flash Read Controller Parameters */
#define FCR_PFM_ACC_NS                           (25)       /* Flash Read Controller Parameters */
#define FCR_PFM_ACC_RECALL_NS                    (70)       /* Flash Read Controller Parameters */
#define FCR_PFM_DATA_MSB                         (255)      /* Flash Memory Parameters */
#define FCR_PFM_NUM_PANELS                       (2)        /* Flash Memory Parameters */
#define FCR_PFM_NUM_RR                           (8)        /* Flash Memory Parameters */
#define FCR_PFM_PAGE_ADDR_MSB                    (11)       /* Flash Memory Parameters */
#define FCR_PFM_PNL_ADDR_MSB                     (21)       /* Flash Memory Parameters */
#define FCR_PFM_PNL_DATA_MSB                     (271)      /* Flash Memory Parameters */
#define FCR_PFM_ROW_ADDR_MSB                     (9)        /* Flash Memory Parameters */
#define FCR_PFM_SRHT_PRESENT                     (1)        /* Flash Read Controller Parameters */
#define FCR_PFM_SYS_ADDR_MSB                     (22)       /* Flash Memory Parameters */
#define FCR_PFM_TDPDH_NS                         (5000)     /* Flash Read Controller Parameters */
#define FCR_PFM_TDPDS_NS                         (100)      /* Flash Read Controller Parameters */
#define FCR_PFM_TLKCFG_NS                        (1000)     /* Flash Read Controller Parameters */
#define FCR_PFM_TMH_NS                           (100)      /* Flash Read Controller Parameters */
#define FCR_PFM_TMS_NS                           (5000)     /* Flash Read Controller Parameters */
#define FCR_PFM_TONWAIT_NS                       (6000)     /* Flash Read Controller Parameters */
#define FCR_PFM_TRHR_NS                          (1000)     /* Flash Read Controller Parameters */
#define FCR_PFM_TRT_NS                           (500)      /* Flash Read Controller Parameters */
#define FCR_INSTANCE_ID                          (2)        /* Instance index for FCR */
#define FCR_MCLK_ID_AHB                          (4)        /* Index for FCR AHB clock */
#define FCR_MCLK_ID_APB                          (5)        /* Index for FCR APB clock */
#define FCR_PAC_ID                               (2)        /* Index for FCR registers write protection */

#endif /* _PIC32CZCA90_FCR_INSTANCE_ */
