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
#ifndef _PIC32CZCA90_EBI_INSTANCE_
#define _PIC32CZCA90_EBI_INSTANCE_


/* ========== Instance Parameter definitions for EBI peripheral ========== */
#define EBI_ACTIVE_BS                            (0)        /* NBS signal porlarity */
#define EBI_ACTIVE_CS                            (0)        /* NCS signal polarity */
#define EBI_ACTIVE_RD                            (0)        /* NRD signal polarity */
#define EBI_ACTIVE_WR                            (0)        /* NWR signal polarity */
#define EBI_DATA_PATH_NBR_XOR_LAYERS             (2)        /* Number of XOR layers in datapath */
#define EBI_DIFF_CHIP_ID                         (0x554E)   /* 2 ASCII characters to differentiate chips (0x554E <--> "UN") */
#define EBI_EMC_DELAY_REGISTER                   (0)        /* Electro Magnetic Compatibility control registers embedded ? */
#define EBI_EX_WAIT                              (0)        /* External Wait signal polarity */
#define EBI_MCLK_ID_AHB                          (75)       /* Index for EBI AHB clock */
#define EBI_MCLK_ID_APB                          (76)       /* Index for EBI APB clock */
#define EBI_MEM_ADDR_SIZE                        (22)       /* Memory Interface size (aligned 32 bits) */
#define EBI_NB_CS                                (4)        /* Number of Chip Select */
#define EBI_NB_PAD_NOE                           (16)       /* Number of Pad Control */
#define EBI_OCMS_INTERFACE                       (0)        /* Off Chip Memory Scrambling implemented ? */
#define EBI_OVERLOADED                           (1)        /* Overloaded Mode implemented ? */

#endif /* _PIC32CZCA90_EBI_INSTANCE_ */
