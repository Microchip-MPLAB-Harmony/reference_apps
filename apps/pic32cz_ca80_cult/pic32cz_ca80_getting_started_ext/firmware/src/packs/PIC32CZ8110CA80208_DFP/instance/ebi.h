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
#ifndef _PIC32CZCA80_EBI_INSTANCE_
#define _PIC32CZCA80_EBI_INSTANCE_


/* ========== Instance Parameter definitions for EBI peripheral ========== */
#define EBI_ACTIVE_BS                            (0)        /* NBS signal porlarity */
#define EBI_ACTIVE_CS                            (0)        /* NCS signal polarity */
#define EBI_ACTIVE_RD                            (0)        /* NRD signal polarity */
#define EBI_ACTIVE_WR                            (0)        /* NWR signal polarity */
#define EBI_DATA_PATH_NBR_XOR_LAYERS             (2)        /* Number of XOR layers in datapath */
#define EBI_DIFF_CHIP_ID                         (0x554E)   /* 2 ASCII characters to differentiate chips (0x554E <--> "UN") */
#define EBI_EMC_DELAY_REGISTER                   (0)        /* Electro Magnetic Compatibility control registers embedded ? */
#define EBI_EX_WAIT                              (0)        /* External Wait signal polarity */
#define EBI_MEM_ADDR_SIZE                        (22)       /* Memory Interface size (aligned 32 bits) */
#define EBI_NB_CS                                (4)        /* Number of Chip Select */
#define EBI_NB_PAD_NOE                           (16)       /* Number of Pad Control */
#define EBI_OCMS_INTERFACE                       (0)        /* Off Chip Memory Scrambling implemented ? */
#define EBI_OVERLOADED                           (1)        /* Overloaded Mode implemented ? */
#define EBI_MCLK_ID_AHB                          (75)       /* Index for EBI AHB clock */
#define EBI_MCLK_ID_APB                          (76)       /* Index for EBI APB clock */

#endif /* _PIC32CZCA80_EBI_INSTANCE_ */
