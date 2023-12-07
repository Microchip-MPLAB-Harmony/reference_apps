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
#ifndef _PIC32CKSG01_SDMMC1_INSTANCE_
#define _PIC32CKSG01_SDMMC1_INSTANCE_


/* ========== Instance Parameter definitions for SDMMC1 peripheral ========== */
#define SDMMC1_CARD_DATA_SIZE                    (4)        
#define SDMMC1_CLOCK_MULTIPLIER                  (2)        /* Multiplier between "sd_mult_src_clock" and "sd_src_clock" */
#define SDMMC1_DDR50_SUPPORT                     (0)        /* SD - UHS DDR50 Support Implemented */
#define SDMMC1_DIVBY2_FOR_SDSRCCLK               (1)        /* Div-by-2 Source Clock is Implemented */
#define SDMMC1_DLL_NB_OF_PHASES                  (16)       
#define SDMMC1_EIGHT_BITS_BUS_WIDTH              (0)        /* Data Bus Width */
#define SDMMC1_GCLK_ID                           (45)       
#define SDMMC1_GCLK_ID_SLOW                      (18)       
#define SDMMC1_GLOBAL_INTERRUPT                  (1)        /* Global Interrupt */
#define SDMMC1_HS200_SUPPORT                     (0)        /* e.MMC - HS200 Support Implemented */
#define SDMMC1_HSDDR_SUPPORT                     (0)        /* e.MMC - HSDDR Support Implemented */
#define SDMMC1_INSTANCE_ID                       (84)       /* Instance index for SDMMC1 */
#define SDMMC1_MAX_BLOCK_LENGTH                  (512)      /* Maximum Block Length */
#define SDMMC1_MCLK_ID_AHB                       (18)       /* Index for SDMMC1 AHB clock */
#define SDMMC1_MULTIPLE_SLOTS                    (1)        /* Multiple Slots Support Enabled */
#define SDMMC1_MULT_SRC_CLK_GATED                (1)        /* Internal Clock Gater is Implemented */
#define SDMMC1_PAC_ID                            (84)       /* Index for SDMMC1 registers write protection */
#define SDMMC1_PROGRAMMABLE_CLK_GENERATOR        (1)        /* Programmabe Clock Generator is Implemented */
#define SDMMC1_RETUNING_TIMER                    (0)        /* Retuning Timer */
#define SDMMC1_RETUNING_TIMER_MAX_VALUE          (0)        /* Retuning Timer Counter Max Value */
#define SDMMC1_SDCD_DEBOUNCE_PERIOD              (328)      /* Debounce Period Value */
#define SDMMC1_SDR104_SUPPORT                    (0)        /* SD - UHS SDR104 Support Implemented */
#define SDMMC1_SDR12_SUPPORT                     (0)        /* SD - UHS SDR12 Support Implemented */
#define SDMMC1_SDR25_SUPPORT                     (0)        /* SD - UHS SDR25 Support Implemented */
#define SDMMC1_SDR50_SUPPORT                     (0)        /* SD - UHS SDR50 Support Implemented */
#define SDMMC1_SD_SRC_CLOCK_FREQ                 (0)        /* Source Clock Frequency (MHz) */
#define SDMMC1_SHARED_BUS                        (0)        /* Shared Bus Enabled */
#define SDMMC1_SLOT_TYPE                         (0)        /* Slot Usage */
#define SDMMC1_TIMEOUT_CLK_DIVISION              (1)        /* Division of TIMEOUT CLOCK compared to "sd_src_clock" */
#define SDMMC1_TIMEOUT_CLK_FREQ                  (12)       /* TIMEOUT CLOCK frequency */
#define SDMMC1_TIMEOUT_CLK_FREQ_UNIT             (1)        /* TIMEOUT CLOCK frequency unit (0=KHz , 1=MHz) */
#define SDMMC1_TUNING_FOR_SDR50                  (0)        /* SDR50 Tuning Support Enabled */
#define SDMMC1_USER_DEBOUNCE                     (0)        /* User Debouncing */

#endif /* _PIC32CKSG01_SDMMC1_INSTANCE_ */
