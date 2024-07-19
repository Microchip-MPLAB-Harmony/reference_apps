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
#ifndef _PIC32CZCA90_MCRAMC_INSTANCE_
#define _PIC32CZCA90_MCRAMC_INSTANCE_


/* ========== Instance Parameter definitions for MCRAMC peripheral ========== */
#define MCRAMC_AHB_CLOCK_ENABLE                  (1)        /* MCRAMC CLOCK GATER */
#define MCRAMC_AHB_ECC                           (1)        /* ECC LOGIC */
#define MCRAMC_AHB_PORTS_NB                      (1)        /* NUMBER OF AHB PORTS */
#define MCRAMC_AHB_READ_PREBUFFERING             (1)        /* AHB READ PREBUFFERING */
#define MCRAMC_AHB_REQUEST_ISOLATION_REGISTER    (1)        /* AHB REQUEST TIMING PATHS ISOLATION */
#define MCRAMC_ARBITRATION_TYPE                  (2)        /* ARBITRATION SCHEME, FIXED_PRIORITY = 0, HIGHLIGHT = 1, HOPSCOTCH = 2 */
#define MCRAMC_BIT_STROBE_RAM                    (0)        /* Set this parameter to TRUE if the ram_wem_bundle outputs are connected to ram bit-strobe write masks */
#define MCRAMC_CHANNELS_NB                       (1)        /* NUMBER OF RAM CHANNELS */
#define MCRAMC_ECC_SYNDROM_REGISTER              (1)        /* ECC TIMING PATH BALANCING */
#define MCRAMC_HADDR_READ_ISOLATION_REGISTER     (0)        /* Set to IMPLEMENTED to add 1 wait-state max (0 min) per memory new line read access for each of the AHB timing path isolations */
#define MCRAMC_HRDATA_ISOLATION_REGISTER         (1)        /* AHB REQUEST TIMING PATHS ISOLATION */
#define MCRAMC_INSTANCE_ID                       (16)       /* Instance index for MCRAMC */
#define MCRAMC_M0_CLOCK_ENABLE                   (0)        /* MCRAMC CLOCK GATER */
#define MCRAMC_M0_DATA_SIZE                      (32)       /* M0 DATA BUS SIZE */
#define MCRAMC_M0_HYBRID_READ_WRITE_ACCESS       (0)        /* M0 HYBRID SIMULTANEOUS READ + WRITE ACCESS */
#define MCRAMC_M0_PORT_SLICES_NB                 (0)        /* NUMBER OF PORT SLICES FOR THE 0 WS SRAM INTERFACE */
#define MCRAMC_MCLK_ID_APB                       (20)       /* Index for MCRAMC APB clock */
#define MCRAMC_CLK_GATER                         (1)        /* MCRAMC CLOCK GATER */
#define MCRAMC_PADDR_SIZE                        (8)        /* APB USER INTERFACE */
#define MCRAMC_MEMORY_AUTO_CORRECTION            (1)        /* Perform an automatic write-back of the corrected ram word after read */
#define MCRAMC_MEMORY_ENABLE_POLARITY            (0)        /* POSITIVE if Memory is selected when ram_me is 1'b1 */
#define MCRAMC_MW_CLOCK_ENABLE                   (0)        /* MCRAMC CLOCK GATER */
#define MCRAMC_MW_DATA_SIZE                      (32)       /* MW DATA BUS SIZE */
#define MCRAMC_MW_PORT_SLICES_NB                 (0)        /* NUMBER OF PORT SLICES FOR THE WAITED SRAM INTERFACE */
#define MCRAMC_PAC_ID                            (16)       /* Index for MCRAMC registers write protection */
#define MCRAMC_RAM_ADD_SIZE                      (14)       /* NUMBER OF ADDRESS BITS FOR ONE CHANNEL RAM CELL */
#define MCRAMC_RAM_AHB_ADDRESS_OFFSET            (0)        /* RAM BLOCK AHB ADDRESS OFFSET */
#define MCRAMC_STORE_BYTE_STROBE                 (0)        /* AHB byte strobes can be stored and read back through the M0 interface */
#define MCRAMC_ULTRA                             (1)        /* ULTRA USER INTERFACE */
#define MCRAMC_WRITE_ENABLE_POLARITY             (0)        /* POSITIVE if Memory is written when ram_we is 1'b1 */
#define MCRAMC_WRITE_ENABLE_USED                 (0)        /* TRUE  if the Memory makes use of a global per channel ram_we write enable */
#define MCRAMC_WRITE_MASK_POLARITY               (0)        /* POSITIVE if Memory is written when ram_wem is 1'b1 */

#endif /* _PIC32CZCA90_MCRAMC_INSTANCE_ */
