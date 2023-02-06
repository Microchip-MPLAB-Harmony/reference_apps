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
#ifndef _PIC32CZCA90_SDMMC0_INSTANCE_
#define _PIC32CZCA90_SDMMC0_INSTANCE_


/* ========== Instance Parameter definitions for SDMMC0 peripheral ========== */
#define SDMMC0_CARD_DATA_SIZE                    (4)        
#define SDMMC0_CLOCK_MULTIPLIER                  (2)        /* Multiplier between "sd_mult_src_clock" and "sd_src_clock" */
#define SDMMC0_DDR50_SUPPORT                     (0)        /* SD - UHS DDR50 Support Implemented */
#define SDMMC0_DIVBY2_FOR_SDSRCCLK               (1)        /* Div-by-2 Source Clock is Implemented */
#define SDMMC0_DLL_NB_OF_PHASES                  (16)       
#define SDMMC0_EIGHT_BITS_BUS_WIDTH              (0)        /* Data Bus Width */
#define SDMMC0_GCLK_ID                           (58)       
#define SDMMC0_GCLK_ID_SLOW                      (59)       
#define SDMMC0_GLOBAL_INTERRUPT                  (1)        /* Global Interrupt */
#define SDMMC0_HSDDR_SUPPORT                     (0)        /* e.MMC - HSDDR Support Implemented */
#define SDMMC0_HS200_SUPPORT                     (0)        /* e.MMC - HS200 Support Implemented */
#define SDMMC0_MAX_BLOCK_LENGTH                  (512)      /* Maximum Block Length */
#define SDMMC0_MULTIPLE_SLOTS                    (1)        /* Multiple Slots Support Enabled */
#define SDMMC0_MULT_SRC_CLK_GATED                (1)        /* Internal Clock Gater is Implemented */
#define SDMMC0_PROGRAMMABLE_CLK_GENERATOR        (1)        /* Programmabe Clock Generator is Implemented */
#define SDMMC0_RETUNING_TIMER                    (0)        /* Retuning Timer */
#define SDMMC0_RETUNING_TIMER_MAX_VALUE          (0)        /* Retuning Timer Counter Max Value */
#define SDMMC0_SDCD_DEBOUNCE_PERIOD              (328)      /* Debounce Period Value */
#define SDMMC0_SDR12_SUPPORT                     (0)        /* SD - UHS SDR12 Support Implemented */
#define SDMMC0_SDR25_SUPPORT                     (0)        /* SD - UHS SDR25 Support Implemented */
#define SDMMC0_SDR50_SUPPORT                     (0)        /* SD - UHS SDR50 Support Implemented */
#define SDMMC0_SDR104_SUPPORT                    (0)        /* SD - UHS SDR104 Support Implemented */
#define SDMMC0_SD_SRC_CLOCK_FREQ                 (0)        /* Source Clock Frequency (MHz) */
#define SDMMC0_SHARED_BUS                        (0)        /* Shared Bus Enabled */
#define SDMMC0_SLOT_TYPE                         (0)        /* Slot Usage */
#define SDMMC0_TIMEOUT_CLK_DIVISION              (1)        /* Division of TIMEOUT CLOCK compared to "sd_src_clock" */
#define SDMMC0_TIMEOUT_CLK_FREQ                  (12)       /* TIMEOUT CLOCK frequency */
#define SDMMC0_TIMEOUT_CLK_FREQ_UNIT             (1)        /* TIMEOUT CLOCK frequency unit (0=KHz , 1=MHz) */
#define SDMMC0_TUNING_FOR_SDR50                  (0)        /* SDR50 Tuning Support Enabled */
#define SDMMC0_USER_DEBOUNCE                     (0)        /* User Debouncing */
#define SDMMC0_INSTANCE_ID                       (60)       /* Instance index for SDMMC0 */
#define SDMMC0_MCLK_ID_AHB                       (69)       /* Index for SDMMC0 AHB clock */
#define SDMMC0_MCLK_ID_APB                       (70)       /* Index for SDMMC0 APB clock */
#define SDMMC0_PAC_ID                            (60)       /* Index for SDMMC0 registers write protection */

#endif /* _PIC32CZCA90_SDMMC0_INSTANCE_ */
