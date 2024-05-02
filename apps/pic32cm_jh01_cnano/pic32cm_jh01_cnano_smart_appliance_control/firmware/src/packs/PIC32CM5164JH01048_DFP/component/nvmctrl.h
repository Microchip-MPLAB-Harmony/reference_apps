/*
 * Component description for NVMCTRL
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

/* file generated from device description version 2023-04-26T09:03:33Z */
#ifndef _PIC32CMJH01_NVMCTRL_COMPONENT_H_
#define _PIC32CMJH01_NVMCTRL_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR NVMCTRL                                      */
/* ************************************************************************** */

/* -------- NVMCTRL_CTRLA : (NVMCTRL Offset: 0x00) (R/W 16) Control A -------- */
#define NVMCTRL_CTRLA_RESETVALUE              _UINT16_(0x00)                                       /*  (NVMCTRL_CTRLA) Control A  Reset Value */

#define NVMCTRL_CTRLA_CMD_Pos                 _UINT16_(0)                                          /* (NVMCTRL_CTRLA) Command Position */
#define NVMCTRL_CTRLA_CMD_Msk                 (_UINT16_(0x7F) << NVMCTRL_CTRLA_CMD_Pos)            /* (NVMCTRL_CTRLA) Command Mask */
#define NVMCTRL_CTRLA_CMD(value)              (NVMCTRL_CTRLA_CMD_Msk & (_UINT16_(value) << NVMCTRL_CTRLA_CMD_Pos)) /* Assigment of value for CMD in the NVMCTRL_CTRLA register */
#define   NVMCTRL_CTRLA_CMD_ER_Val            _UINT16_(0x2)                                        /* (NVMCTRL_CTRLA) Erase Row - Erases the row addressed by the ADDR register.  */
#define   NVMCTRL_CTRLA_CMD_WP_Val            _UINT16_(0x4)                                        /* (NVMCTRL_CTRLA) Write Page - Writes the contents of the page buffer to the page addressed by the ADDR register.  */
#define   NVMCTRL_CTRLA_CMD_EAR_Val           _UINT16_(0x5)                                        /* (NVMCTRL_CTRLA) Erase Auxiliary Row - Erases the auxiliary row addressed by the ADDR register. This command can be given only when the security bit is not set and only to the user configuration row.  */
#define   NVMCTRL_CTRLA_CMD_WAP_Val           _UINT16_(0x6)                                        /* (NVMCTRL_CTRLA) Write Auxiliary Page - Writes the contents of the page buffer to the page addressed by the ADDR register. This command can be given only when the security bit is not set and only to the user configuration row.  */
#define   NVMCTRL_CTRLA_CMD_DFER_Val          _UINT16_(0x1A)                                       /* (NVMCTRL_CTRLA) Data Flash Erase Row - Erases the row addressed by the ADDR register.  */
#define   NVMCTRL_CTRLA_CMD_DFWP_Val          _UINT16_(0x1C)                                       /* (NVMCTRL_CTRLA) Data Flash Write Page - Writes the contents of the page buffer to the page addressed by the ADDR register.  */
#define   NVMCTRL_CTRLA_CMD_LR_Val            _UINT16_(0x40)                                       /* (NVMCTRL_CTRLA) Lock Region - Locks the region containing the address location in the ADDR register.  */
#define   NVMCTRL_CTRLA_CMD_UR_Val            _UINT16_(0x41)                                       /* (NVMCTRL_CTRLA) Unlock Region - Unlocks the region containing the address location in the ADDR register.  */
#define   NVMCTRL_CTRLA_CMD_SPRM_Val          _UINT16_(0x42)                                       /* (NVMCTRL_CTRLA) Sets the power reduction mode.  */
#define   NVMCTRL_CTRLA_CMD_CPRM_Val          _UINT16_(0x43)                                       /* (NVMCTRL_CTRLA) Clears the power reduction mode.  */
#define   NVMCTRL_CTRLA_CMD_PBC_Val           _UINT16_(0x44)                                       /* (NVMCTRL_CTRLA) Page Buffer Clear - Clears the page buffer.  */
#define   NVMCTRL_CTRLA_CMD_SSB_Val           _UINT16_(0x45)                                       /* (NVMCTRL_CTRLA) Set Security Bit - Sets the security bit by writing 0x00 to the first byte in the lockbit row.  */
#define   NVMCTRL_CTRLA_CMD_INVALL_Val        _UINT16_(0x46)                                       /* (NVMCTRL_CTRLA) Invalidate all cache lines.  */
#define   NVMCTRL_CTRLA_CMD_SCEHL_Val         _UINT16_(0x7F)                                       /* (NVMCTRL_CTRLA) Set Chip Erase Hard Lock (SCEHL) flash controller command  */
#define NVMCTRL_CTRLA_CMD_ER                  (NVMCTRL_CTRLA_CMD_ER_Val << NVMCTRL_CTRLA_CMD_Pos)  /* (NVMCTRL_CTRLA) Erase Row - Erases the row addressed by the ADDR register. Position  */
#define NVMCTRL_CTRLA_CMD_WP                  (NVMCTRL_CTRLA_CMD_WP_Val << NVMCTRL_CTRLA_CMD_Pos)  /* (NVMCTRL_CTRLA) Write Page - Writes the contents of the page buffer to the page addressed by the ADDR register. Position  */
#define NVMCTRL_CTRLA_CMD_EAR                 (NVMCTRL_CTRLA_CMD_EAR_Val << NVMCTRL_CTRLA_CMD_Pos) /* (NVMCTRL_CTRLA) Erase Auxiliary Row - Erases the auxiliary row addressed by the ADDR register. This command can be given only when the security bit is not set and only to the user configuration row. Position  */
#define NVMCTRL_CTRLA_CMD_WAP                 (NVMCTRL_CTRLA_CMD_WAP_Val << NVMCTRL_CTRLA_CMD_Pos) /* (NVMCTRL_CTRLA) Write Auxiliary Page - Writes the contents of the page buffer to the page addressed by the ADDR register. This command can be given only when the security bit is not set and only to the user configuration row. Position  */
#define NVMCTRL_CTRLA_CMD_DFER                (NVMCTRL_CTRLA_CMD_DFER_Val << NVMCTRL_CTRLA_CMD_Pos) /* (NVMCTRL_CTRLA) Data Flash Erase Row - Erases the row addressed by the ADDR register. Position  */
#define NVMCTRL_CTRLA_CMD_DFWP                (NVMCTRL_CTRLA_CMD_DFWP_Val << NVMCTRL_CTRLA_CMD_Pos) /* (NVMCTRL_CTRLA) Data Flash Write Page - Writes the contents of the page buffer to the page addressed by the ADDR register. Position  */
#define NVMCTRL_CTRLA_CMD_LR                  (NVMCTRL_CTRLA_CMD_LR_Val << NVMCTRL_CTRLA_CMD_Pos)  /* (NVMCTRL_CTRLA) Lock Region - Locks the region containing the address location in the ADDR register. Position  */
#define NVMCTRL_CTRLA_CMD_UR                  (NVMCTRL_CTRLA_CMD_UR_Val << NVMCTRL_CTRLA_CMD_Pos)  /* (NVMCTRL_CTRLA) Unlock Region - Unlocks the region containing the address location in the ADDR register. Position  */
#define NVMCTRL_CTRLA_CMD_SPRM                (NVMCTRL_CTRLA_CMD_SPRM_Val << NVMCTRL_CTRLA_CMD_Pos) /* (NVMCTRL_CTRLA) Sets the power reduction mode. Position  */
#define NVMCTRL_CTRLA_CMD_CPRM                (NVMCTRL_CTRLA_CMD_CPRM_Val << NVMCTRL_CTRLA_CMD_Pos) /* (NVMCTRL_CTRLA) Clears the power reduction mode. Position  */
#define NVMCTRL_CTRLA_CMD_PBC                 (NVMCTRL_CTRLA_CMD_PBC_Val << NVMCTRL_CTRLA_CMD_Pos) /* (NVMCTRL_CTRLA) Page Buffer Clear - Clears the page buffer. Position  */
#define NVMCTRL_CTRLA_CMD_SSB                 (NVMCTRL_CTRLA_CMD_SSB_Val << NVMCTRL_CTRLA_CMD_Pos) /* (NVMCTRL_CTRLA) Set Security Bit - Sets the security bit by writing 0x00 to the first byte in the lockbit row. Position  */
#define NVMCTRL_CTRLA_CMD_INVALL              (NVMCTRL_CTRLA_CMD_INVALL_Val << NVMCTRL_CTRLA_CMD_Pos) /* (NVMCTRL_CTRLA) Invalidate all cache lines. Position  */
#define NVMCTRL_CTRLA_CMD_SCEHL               (NVMCTRL_CTRLA_CMD_SCEHL_Val << NVMCTRL_CTRLA_CMD_Pos) /* (NVMCTRL_CTRLA) Set Chip Erase Hard Lock (SCEHL) flash controller command Position  */
#define NVMCTRL_CTRLA_CMDEX_Pos               _UINT16_(8)                                          /* (NVMCTRL_CTRLA) Command Execution Position */
#define NVMCTRL_CTRLA_CMDEX_Msk               (_UINT16_(0xFF) << NVMCTRL_CTRLA_CMDEX_Pos)          /* (NVMCTRL_CTRLA) Command Execution Mask */
#define NVMCTRL_CTRLA_CMDEX(value)            (NVMCTRL_CTRLA_CMDEX_Msk & (_UINT16_(value) << NVMCTRL_CTRLA_CMDEX_Pos)) /* Assigment of value for CMDEX in the NVMCTRL_CTRLA register */
#define   NVMCTRL_CTRLA_CMDEX_KEY_Val         _UINT16_(0xA5)                                       /* (NVMCTRL_CTRLA) Execution Key  */
#define NVMCTRL_CTRLA_CMDEX_KEY               (NVMCTRL_CTRLA_CMDEX_KEY_Val << NVMCTRL_CTRLA_CMDEX_Pos) /* (NVMCTRL_CTRLA) Execution Key Position  */
#define NVMCTRL_CTRLA_Msk                     _UINT16_(0xFF7F)                                     /* (NVMCTRL_CTRLA) Register Mask  */


/* -------- NVMCTRL_CTRLB : (NVMCTRL Offset: 0x04) (R/W 32) Control B -------- */
#define NVMCTRL_CTRLB_RESETVALUE              _UINT32_(0x80)                                       /*  (NVMCTRL_CTRLB) Control B  Reset Value */

#define NVMCTRL_CTRLB_RWS_Pos                 _UINT32_(1)                                          /* (NVMCTRL_CTRLB) NVM Read Wait States Position */
#define NVMCTRL_CTRLB_RWS_Msk                 (_UINT32_(0xF) << NVMCTRL_CTRLB_RWS_Pos)             /* (NVMCTRL_CTRLB) NVM Read Wait States Mask */
#define NVMCTRL_CTRLB_RWS(value)              (NVMCTRL_CTRLB_RWS_Msk & (_UINT32_(value) << NVMCTRL_CTRLB_RWS_Pos)) /* Assigment of value for RWS in the NVMCTRL_CTRLB register */
#define   NVMCTRL_CTRLB_RWS_SINGLE_Val        _UINT32_(0x0)                                        /* (NVMCTRL_CTRLB) Single Auto Wait State  */
#define   NVMCTRL_CTRLB_RWS_HALF_Val          _UINT32_(0x1)                                        /* (NVMCTRL_CTRLB) Half Auto Wait State  */
#define   NVMCTRL_CTRLB_RWS_DUAL_Val          _UINT32_(0x2)                                        /* (NVMCTRL_CTRLB) Dual Auto Wait State  */
#define NVMCTRL_CTRLB_RWS_SINGLE              (NVMCTRL_CTRLB_RWS_SINGLE_Val << NVMCTRL_CTRLB_RWS_Pos) /* (NVMCTRL_CTRLB) Single Auto Wait State Position  */
#define NVMCTRL_CTRLB_RWS_HALF                (NVMCTRL_CTRLB_RWS_HALF_Val << NVMCTRL_CTRLB_RWS_Pos) /* (NVMCTRL_CTRLB) Half Auto Wait State Position  */
#define NVMCTRL_CTRLB_RWS_DUAL                (NVMCTRL_CTRLB_RWS_DUAL_Val << NVMCTRL_CTRLB_RWS_Pos) /* (NVMCTRL_CTRLB) Dual Auto Wait State Position  */
#define NVMCTRL_CTRLB_MANW_Pos                _UINT32_(7)                                          /* (NVMCTRL_CTRLB) Manual Write Position */
#define NVMCTRL_CTRLB_MANW_Msk                (_UINT32_(0x1) << NVMCTRL_CTRLB_MANW_Pos)            /* (NVMCTRL_CTRLB) Manual Write Mask */
#define NVMCTRL_CTRLB_MANW(value)             (NVMCTRL_CTRLB_MANW_Msk & (_UINT32_(value) << NVMCTRL_CTRLB_MANW_Pos)) /* Assigment of value for MANW in the NVMCTRL_CTRLB register */
#define NVMCTRL_CTRLB_SLEEPPRM_Pos            _UINT32_(8)                                          /* (NVMCTRL_CTRLB) Power Reduction Mode during Sleep Position */
#define NVMCTRL_CTRLB_SLEEPPRM_Msk            (_UINT32_(0x3) << NVMCTRL_CTRLB_SLEEPPRM_Pos)        /* (NVMCTRL_CTRLB) Power Reduction Mode during Sleep Mask */
#define NVMCTRL_CTRLB_SLEEPPRM(value)         (NVMCTRL_CTRLB_SLEEPPRM_Msk & (_UINT32_(value) << NVMCTRL_CTRLB_SLEEPPRM_Pos)) /* Assigment of value for SLEEPPRM in the NVMCTRL_CTRLB register */
#define   NVMCTRL_CTRLB_SLEEPPRM_WAKEONACCESS_Val _UINT32_(0x0)                                        /* (NVMCTRL_CTRLB) NVM block enters low-power mode when entering sleep.NVM block exits low-power mode upon first access.  */
#define   NVMCTRL_CTRLB_SLEEPPRM_WAKEUPINSTANT_Val _UINT32_(0x1)                                        /* (NVMCTRL_CTRLB) NVM block enters low-power mode when entering sleep.NVM block exits low-power mode when exiting sleep.  */
#define   NVMCTRL_CTRLB_SLEEPPRM_DISABLED_Val _UINT32_(0x3)                                        /* (NVMCTRL_CTRLB) Auto power reduction disabled.  */
#define NVMCTRL_CTRLB_SLEEPPRM_WAKEONACCESS   (NVMCTRL_CTRLB_SLEEPPRM_WAKEONACCESS_Val << NVMCTRL_CTRLB_SLEEPPRM_Pos) /* (NVMCTRL_CTRLB) NVM block enters low-power mode when entering sleep.NVM block exits low-power mode upon first access. Position  */
#define NVMCTRL_CTRLB_SLEEPPRM_WAKEUPINSTANT  (NVMCTRL_CTRLB_SLEEPPRM_WAKEUPINSTANT_Val << NVMCTRL_CTRLB_SLEEPPRM_Pos) /* (NVMCTRL_CTRLB) NVM block enters low-power mode when entering sleep.NVM block exits low-power mode when exiting sleep. Position  */
#define NVMCTRL_CTRLB_SLEEPPRM_DISABLED       (NVMCTRL_CTRLB_SLEEPPRM_DISABLED_Val << NVMCTRL_CTRLB_SLEEPPRM_Pos) /* (NVMCTRL_CTRLB) Auto power reduction disabled. Position  */
#define NVMCTRL_CTRLB_READMODE_Pos            _UINT32_(16)                                         /* (NVMCTRL_CTRLB) NVM Read Mode Position */
#define NVMCTRL_CTRLB_READMODE_Msk            (_UINT32_(0x3) << NVMCTRL_CTRLB_READMODE_Pos)        /* (NVMCTRL_CTRLB) NVM Read Mode Mask */
#define NVMCTRL_CTRLB_READMODE(value)         (NVMCTRL_CTRLB_READMODE_Msk & (_UINT32_(value) << NVMCTRL_CTRLB_READMODE_Pos)) /* Assigment of value for READMODE in the NVMCTRL_CTRLB register */
#define   NVMCTRL_CTRLB_READMODE_NO_MISS_PENALTY_Val _UINT32_(0x0)                                        /* (NVMCTRL_CTRLB) The NVM Controller (cache system) does not insert wait states on a cache miss. Gives the best system performance.  */
#define   NVMCTRL_CTRLB_READMODE_LOW_POWER_Val _UINT32_(0x1)                                        /* (NVMCTRL_CTRLB) Reduces power consumption of the cache system, but inserts a wait state each time there is a cache miss. This mode may not be relevant if CPU performance is required, as the application will be stalled and may lead to increase run time.  */
#define   NVMCTRL_CTRLB_READMODE_DETERMINISTIC_Val _UINT32_(0x2)                                        /* (NVMCTRL_CTRLB) The cache system ensures that a cache hit or miss takes the same amount of time, determined by the number of programmed flash wait states. This mode can be used for real-time applications that require deterministic execution timings.  */
#define NVMCTRL_CTRLB_READMODE_NO_MISS_PENALTY (NVMCTRL_CTRLB_READMODE_NO_MISS_PENALTY_Val << NVMCTRL_CTRLB_READMODE_Pos) /* (NVMCTRL_CTRLB) The NVM Controller (cache system) does not insert wait states on a cache miss. Gives the best system performance. Position  */
#define NVMCTRL_CTRLB_READMODE_LOW_POWER      (NVMCTRL_CTRLB_READMODE_LOW_POWER_Val << NVMCTRL_CTRLB_READMODE_Pos) /* (NVMCTRL_CTRLB) Reduces power consumption of the cache system, but inserts a wait state each time there is a cache miss. This mode may not be relevant if CPU performance is required, as the application will be stalled and may lead to increase run time. Position  */
#define NVMCTRL_CTRLB_READMODE_DETERMINISTIC  (NVMCTRL_CTRLB_READMODE_DETERMINISTIC_Val << NVMCTRL_CTRLB_READMODE_Pos) /* (NVMCTRL_CTRLB) The cache system ensures that a cache hit or miss takes the same amount of time, determined by the number of programmed flash wait states. This mode can be used for real-time applications that require deterministic execution timings. Position  */
#define NVMCTRL_CTRLB_CACHEDIS_Pos            _UINT32_(18)                                         /* (NVMCTRL_CTRLB) Cache Disable Position */
#define NVMCTRL_CTRLB_CACHEDIS_Msk            (_UINT32_(0x3) << NVMCTRL_CTRLB_CACHEDIS_Pos)        /* (NVMCTRL_CTRLB) Cache Disable Mask */
#define NVMCTRL_CTRLB_CACHEDIS(value)         (NVMCTRL_CTRLB_CACHEDIS_Msk & (_UINT32_(value) << NVMCTRL_CTRLB_CACHEDIS_Pos)) /* Assigment of value for CACHEDIS in the NVMCTRL_CTRLB register */
#define   NVMCTRL_CTRLB_CACHEDIS_CACHE_DF_DIS_MAIN_EN_Val _UINT32_(0x0)                                        /* (NVMCTRL_CTRLB) The Data Flash cache is disabled, the main array cache is enabled  */
#define   NVMCTRL_CTRLB_CACHEDIS_CACHE_DF_DIS_MAIN_DIS_Val _UINT32_(0x1)                                        /* (NVMCTRL_CTRLB) The Data Flash cache is disabled, the main array cache is disabled  */
#define   NVMCTRL_CTRLB_CACHEDIS_CACHE_DF_EN_MAIN_EN_Val _UINT32_(0x2)                                        /* (NVMCTRL_CTRLB) The Data Flash cache is enabled, the main array cache is enabled  */
#define   NVMCTRL_CTRLB_CACHEDIS_CACHE_DF_EN_MAIN_DIS_Val _UINT32_(0x3)                                        /* (NVMCTRL_CTRLB) The Data Flash cache is enabled, the main array cache is disabled  */
#define NVMCTRL_CTRLB_CACHEDIS_CACHE_DF_DIS_MAIN_EN (NVMCTRL_CTRLB_CACHEDIS_CACHE_DF_DIS_MAIN_EN_Val << NVMCTRL_CTRLB_CACHEDIS_Pos) /* (NVMCTRL_CTRLB) The Data Flash cache is disabled, the main array cache is enabled Position  */
#define NVMCTRL_CTRLB_CACHEDIS_CACHE_DF_DIS_MAIN_DIS (NVMCTRL_CTRLB_CACHEDIS_CACHE_DF_DIS_MAIN_DIS_Val << NVMCTRL_CTRLB_CACHEDIS_Pos) /* (NVMCTRL_CTRLB) The Data Flash cache is disabled, the main array cache is disabled Position  */
#define NVMCTRL_CTRLB_CACHEDIS_CACHE_DF_EN_MAIN_EN (NVMCTRL_CTRLB_CACHEDIS_CACHE_DF_EN_MAIN_EN_Val << NVMCTRL_CTRLB_CACHEDIS_Pos) /* (NVMCTRL_CTRLB) The Data Flash cache is enabled, the main array cache is enabled Position  */
#define NVMCTRL_CTRLB_CACHEDIS_CACHE_DF_EN_MAIN_DIS (NVMCTRL_CTRLB_CACHEDIS_CACHE_DF_EN_MAIN_DIS_Val << NVMCTRL_CTRLB_CACHEDIS_Pos) /* (NVMCTRL_CTRLB) The Data Flash cache is enabled, the main array cache is disabled Position  */
#define NVMCTRL_CTRLB_Msk                     _UINT32_(0x000F039E)                                 /* (NVMCTRL_CTRLB) Register Mask  */


/* -------- NVMCTRL_PARAM : (NVMCTRL Offset: 0x08) (R/W 32) NVM Parameter -------- */
#define NVMCTRL_PARAM_RESETVALUE              _UINT32_(0x00)                                       /*  (NVMCTRL_PARAM) NVM Parameter  Reset Value */

#define NVMCTRL_PARAM_NVMP_Pos                _UINT32_(0)                                          /* (NVMCTRL_PARAM) NVM Pages Position */
#define NVMCTRL_PARAM_NVMP_Msk                (_UINT32_(0xFFFF) << NVMCTRL_PARAM_NVMP_Pos)         /* (NVMCTRL_PARAM) NVM Pages Mask */
#define NVMCTRL_PARAM_NVMP(value)             (NVMCTRL_PARAM_NVMP_Msk & (_UINT32_(value) << NVMCTRL_PARAM_NVMP_Pos)) /* Assigment of value for NVMP in the NVMCTRL_PARAM register */
#define NVMCTRL_PARAM_PSZ_Pos                 _UINT32_(16)                                         /* (NVMCTRL_PARAM) Page Size Position */
#define NVMCTRL_PARAM_PSZ_Msk                 (_UINT32_(0x7) << NVMCTRL_PARAM_PSZ_Pos)             /* (NVMCTRL_PARAM) Page Size Mask */
#define NVMCTRL_PARAM_PSZ(value)              (NVMCTRL_PARAM_PSZ_Msk & (_UINT32_(value) << NVMCTRL_PARAM_PSZ_Pos)) /* Assigment of value for PSZ in the NVMCTRL_PARAM register */
#define   NVMCTRL_PARAM_PSZ_8_Val             _UINT32_(0x0)                                        /* (NVMCTRL_PARAM) 8 bytes  */
#define   NVMCTRL_PARAM_PSZ_16_Val            _UINT32_(0x1)                                        /* (NVMCTRL_PARAM) 16 bytes  */
#define   NVMCTRL_PARAM_PSZ_32_Val            _UINT32_(0x2)                                        /* (NVMCTRL_PARAM) 32 bytes  */
#define   NVMCTRL_PARAM_PSZ_64_Val            _UINT32_(0x3)                                        /* (NVMCTRL_PARAM) 64 bytes  */
#define   NVMCTRL_PARAM_PSZ_128_Val           _UINT32_(0x4)                                        /* (NVMCTRL_PARAM) 128 bytes  */
#define   NVMCTRL_PARAM_PSZ_256_Val           _UINT32_(0x5)                                        /* (NVMCTRL_PARAM) 256 bytes  */
#define   NVMCTRL_PARAM_PSZ_512_Val           _UINT32_(0x6)                                        /* (NVMCTRL_PARAM) 512 bytes  */
#define   NVMCTRL_PARAM_PSZ_1024_Val          _UINT32_(0x7)                                        /* (NVMCTRL_PARAM) 1024 bytes  */
#define NVMCTRL_PARAM_PSZ_8                   (NVMCTRL_PARAM_PSZ_8_Val << NVMCTRL_PARAM_PSZ_Pos)   /* (NVMCTRL_PARAM) 8 bytes Position  */
#define NVMCTRL_PARAM_PSZ_16                  (NVMCTRL_PARAM_PSZ_16_Val << NVMCTRL_PARAM_PSZ_Pos)  /* (NVMCTRL_PARAM) 16 bytes Position  */
#define NVMCTRL_PARAM_PSZ_32                  (NVMCTRL_PARAM_PSZ_32_Val << NVMCTRL_PARAM_PSZ_Pos)  /* (NVMCTRL_PARAM) 32 bytes Position  */
#define NVMCTRL_PARAM_PSZ_64                  (NVMCTRL_PARAM_PSZ_64_Val << NVMCTRL_PARAM_PSZ_Pos)  /* (NVMCTRL_PARAM) 64 bytes Position  */
#define NVMCTRL_PARAM_PSZ_128                 (NVMCTRL_PARAM_PSZ_128_Val << NVMCTRL_PARAM_PSZ_Pos) /* (NVMCTRL_PARAM) 128 bytes Position  */
#define NVMCTRL_PARAM_PSZ_256                 (NVMCTRL_PARAM_PSZ_256_Val << NVMCTRL_PARAM_PSZ_Pos) /* (NVMCTRL_PARAM) 256 bytes Position  */
#define NVMCTRL_PARAM_PSZ_512                 (NVMCTRL_PARAM_PSZ_512_Val << NVMCTRL_PARAM_PSZ_Pos) /* (NVMCTRL_PARAM) 512 bytes Position  */
#define NVMCTRL_PARAM_PSZ_1024                (NVMCTRL_PARAM_PSZ_1024_Val << NVMCTRL_PARAM_PSZ_Pos) /* (NVMCTRL_PARAM) 1024 bytes Position  */
#define NVMCTRL_PARAM_DFP_Pos                 _UINT32_(20)                                         /* (NVMCTRL_PARAM) Data Flash Pages Position */
#define NVMCTRL_PARAM_DFP_Msk                 (_UINT32_(0xFFF) << NVMCTRL_PARAM_DFP_Pos)           /* (NVMCTRL_PARAM) Data Flash Pages Mask */
#define NVMCTRL_PARAM_DFP(value)              (NVMCTRL_PARAM_DFP_Msk & (_UINT32_(value) << NVMCTRL_PARAM_DFP_Pos)) /* Assigment of value for DFP in the NVMCTRL_PARAM register */
#define NVMCTRL_PARAM_Msk                     _UINT32_(0xFFF7FFFF)                                 /* (NVMCTRL_PARAM) Register Mask  */


/* -------- NVMCTRL_INTENCLR : (NVMCTRL Offset: 0x0C) (R/W 32) Interrupt Enable Clear -------- */
#define NVMCTRL_INTENCLR_RESETVALUE           _UINT32_(0x00)                                       /*  (NVMCTRL_INTENCLR) Interrupt Enable Clear  Reset Value */

#define NVMCTRL_INTENCLR_READY_Pos            _UINT32_(0)                                          /* (NVMCTRL_INTENCLR) NVM Ready Interrupt Enable Position */
#define NVMCTRL_INTENCLR_READY_Msk            (_UINT32_(0x1) << NVMCTRL_INTENCLR_READY_Pos)        /* (NVMCTRL_INTENCLR) NVM Ready Interrupt Enable Mask */
#define NVMCTRL_INTENCLR_READY(value)         (NVMCTRL_INTENCLR_READY_Msk & (_UINT32_(value) << NVMCTRL_INTENCLR_READY_Pos)) /* Assigment of value for READY in the NVMCTRL_INTENCLR register */
#define NVMCTRL_INTENCLR_ERROR_Pos            _UINT32_(1)                                          /* (NVMCTRL_INTENCLR) Error Interrupt Enable Position */
#define NVMCTRL_INTENCLR_ERROR_Msk            (_UINT32_(0x1) << NVMCTRL_INTENCLR_ERROR_Pos)        /* (NVMCTRL_INTENCLR) Error Interrupt Enable Mask */
#define NVMCTRL_INTENCLR_ERROR(value)         (NVMCTRL_INTENCLR_ERROR_Msk & (_UINT32_(value) << NVMCTRL_INTENCLR_ERROR_Pos)) /* Assigment of value for ERROR in the NVMCTRL_INTENCLR register */
#define NVMCTRL_INTENCLR_SERR_Pos             _UINT32_(8)                                          /* (NVMCTRL_INTENCLR) Single Bit Error Detection Flag bit Disable Position */
#define NVMCTRL_INTENCLR_SERR_Msk             (_UINT32_(0x1) << NVMCTRL_INTENCLR_SERR_Pos)         /* (NVMCTRL_INTENCLR) Single Bit Error Detection Flag bit Disable Mask */
#define NVMCTRL_INTENCLR_SERR(value)          (NVMCTRL_INTENCLR_SERR_Msk & (_UINT32_(value) << NVMCTRL_INTENCLR_SERR_Pos)) /* Assigment of value for SERR in the NVMCTRL_INTENCLR register */
#define NVMCTRL_INTENCLR_DERR_Pos             _UINT32_(9)                                          /* (NVMCTRL_INTENCLR) Double Bit Error Detection Flag bit Disable Position */
#define NVMCTRL_INTENCLR_DERR_Msk             (_UINT32_(0x1) << NVMCTRL_INTENCLR_DERR_Pos)         /* (NVMCTRL_INTENCLR) Double Bit Error Detection Flag bit Disable Mask */
#define NVMCTRL_INTENCLR_DERR(value)          (NVMCTRL_INTENCLR_DERR_Msk & (_UINT32_(value) << NVMCTRL_INTENCLR_DERR_Pos)) /* Assigment of value for DERR in the NVMCTRL_INTENCLR register */
#define NVMCTRL_INTENCLR_FLTCAP_Pos           _UINT32_(24)                                         /* (NVMCTRL_INTENCLR) Fault Capture interrupt enable bit Disable Position */
#define NVMCTRL_INTENCLR_FLTCAP_Msk           (_UINT32_(0x1) << NVMCTRL_INTENCLR_FLTCAP_Pos)       /* (NVMCTRL_INTENCLR) Fault Capture interrupt enable bit Disable Mask */
#define NVMCTRL_INTENCLR_FLTCAP(value)        (NVMCTRL_INTENCLR_FLTCAP_Msk & (_UINT32_(value) << NVMCTRL_INTENCLR_FLTCAP_Pos)) /* Assigment of value for FLTCAP in the NVMCTRL_INTENCLR register */
#define NVMCTRL_INTENCLR_Msk                  _UINT32_(0x01000303)                                 /* (NVMCTRL_INTENCLR) Register Mask  */


/* -------- NVMCTRL_INTENSET : (NVMCTRL Offset: 0x10) (R/W 32) Interrupt Enable Set -------- */
#define NVMCTRL_INTENSET_RESETVALUE           _UINT32_(0x00)                                       /*  (NVMCTRL_INTENSET) Interrupt Enable Set  Reset Value */

#define NVMCTRL_INTENSET_READY_Pos            _UINT32_(0)                                          /* (NVMCTRL_INTENSET) NVM Ready Interrupt Enable Position */
#define NVMCTRL_INTENSET_READY_Msk            (_UINT32_(0x1) << NVMCTRL_INTENSET_READY_Pos)        /* (NVMCTRL_INTENSET) NVM Ready Interrupt Enable Mask */
#define NVMCTRL_INTENSET_READY(value)         (NVMCTRL_INTENSET_READY_Msk & (_UINT32_(value) << NVMCTRL_INTENSET_READY_Pos)) /* Assigment of value for READY in the NVMCTRL_INTENSET register */
#define NVMCTRL_INTENSET_ERROR_Pos            _UINT32_(1)                                          /* (NVMCTRL_INTENSET) Error Interrupt Enable Position */
#define NVMCTRL_INTENSET_ERROR_Msk            (_UINT32_(0x1) << NVMCTRL_INTENSET_ERROR_Pos)        /* (NVMCTRL_INTENSET) Error Interrupt Enable Mask */
#define NVMCTRL_INTENSET_ERROR(value)         (NVMCTRL_INTENSET_ERROR_Msk & (_UINT32_(value) << NVMCTRL_INTENSET_ERROR_Pos)) /* Assigment of value for ERROR in the NVMCTRL_INTENSET register */
#define NVMCTRL_INTENSET_SERR_Pos             _UINT32_(8)                                          /* (NVMCTRL_INTENSET) Single Bit Error Detection Flag bit Enable Position */
#define NVMCTRL_INTENSET_SERR_Msk             (_UINT32_(0x1) << NVMCTRL_INTENSET_SERR_Pos)         /* (NVMCTRL_INTENSET) Single Bit Error Detection Flag bit Enable Mask */
#define NVMCTRL_INTENSET_SERR(value)          (NVMCTRL_INTENSET_SERR_Msk & (_UINT32_(value) << NVMCTRL_INTENSET_SERR_Pos)) /* Assigment of value for SERR in the NVMCTRL_INTENSET register */
#define NVMCTRL_INTENSET_DERR_Pos             _UINT32_(9)                                          /* (NVMCTRL_INTENSET) Double Bit Error Detection Flag bit Enable Position */
#define NVMCTRL_INTENSET_DERR_Msk             (_UINT32_(0x1) << NVMCTRL_INTENSET_DERR_Pos)         /* (NVMCTRL_INTENSET) Double Bit Error Detection Flag bit Enable Mask */
#define NVMCTRL_INTENSET_DERR(value)          (NVMCTRL_INTENSET_DERR_Msk & (_UINT32_(value) << NVMCTRL_INTENSET_DERR_Pos)) /* Assigment of value for DERR in the NVMCTRL_INTENSET register */
#define NVMCTRL_INTENSET_FLTCAP_Pos           _UINT32_(24)                                         /* (NVMCTRL_INTENSET) Fault Capture interrupt enable bit Enable Position */
#define NVMCTRL_INTENSET_FLTCAP_Msk           (_UINT32_(0x1) << NVMCTRL_INTENSET_FLTCAP_Pos)       /* (NVMCTRL_INTENSET) Fault Capture interrupt enable bit Enable Mask */
#define NVMCTRL_INTENSET_FLTCAP(value)        (NVMCTRL_INTENSET_FLTCAP_Msk & (_UINT32_(value) << NVMCTRL_INTENSET_FLTCAP_Pos)) /* Assigment of value for FLTCAP in the NVMCTRL_INTENSET register */
#define NVMCTRL_INTENSET_Msk                  _UINT32_(0x01000303)                                 /* (NVMCTRL_INTENSET) Register Mask  */


/* -------- NVMCTRL_INTFLAG : (NVMCTRL Offset: 0x14) (R/W 32) Interrupt Flag Status and Clear -------- */
#define NVMCTRL_INTFLAG_RESETVALUE            _UINT32_(0x00)                                       /*  (NVMCTRL_INTFLAG) Interrupt Flag Status and Clear  Reset Value */

#define NVMCTRL_INTFLAG_READY_Pos             _UINT32_(0)                                          /* (NVMCTRL_INTFLAG) NVM Ready Position */
#define NVMCTRL_INTFLAG_READY_Msk             (_UINT32_(0x1) << NVMCTRL_INTFLAG_READY_Pos)         /* (NVMCTRL_INTFLAG) NVM Ready Mask */
#define NVMCTRL_INTFLAG_READY(value)          (NVMCTRL_INTFLAG_READY_Msk & (_UINT32_(value) << NVMCTRL_INTFLAG_READY_Pos)) /* Assigment of value for READY in the NVMCTRL_INTFLAG register */
#define   NVMCTRL_INTFLAG_READY_Val_0_Val     _UINT32_(0x0)                                        /* (NVMCTRL_INTFLAG) The NVM controller is busy programming or erasing.  */
#define   NVMCTRL_INTFLAG_READY_Val_1_Val     _UINT32_(0x1)                                        /* (NVMCTRL_INTFLAG) The NVM controller is ready to accept a new command  */
#define NVMCTRL_INTFLAG_READY_Val_0           (NVMCTRL_INTFLAG_READY_Val_0_Val << NVMCTRL_INTFLAG_READY_Pos) /* (NVMCTRL_INTFLAG) The NVM controller is busy programming or erasing. Position  */
#define NVMCTRL_INTFLAG_READY_Val_1           (NVMCTRL_INTFLAG_READY_Val_1_Val << NVMCTRL_INTFLAG_READY_Pos) /* (NVMCTRL_INTFLAG) The NVM controller is ready to accept a new command Position  */
#define NVMCTRL_INTFLAG_ERROR_Pos             _UINT32_(1)                                          /* (NVMCTRL_INTFLAG) Error Position */
#define NVMCTRL_INTFLAG_ERROR_Msk             (_UINT32_(0x1) << NVMCTRL_INTFLAG_ERROR_Pos)         /* (NVMCTRL_INTFLAG) Error Mask */
#define NVMCTRL_INTFLAG_ERROR(value)          (NVMCTRL_INTFLAG_ERROR_Msk & (_UINT32_(value) << NVMCTRL_INTFLAG_ERROR_Pos)) /* Assigment of value for ERROR in the NVMCTRL_INTFLAG register */
#define   NVMCTRL_INTFLAG_ERROR_Val_0_Val     _UINT32_(0x0)                                        /* (NVMCTRL_INTFLAG) No errors have been received since the last clear  */
#define   NVMCTRL_INTFLAG_ERROR_Val_1_Val     _UINT32_(0x1)                                        /* (NVMCTRL_INTFLAG) At least one error has occurred since the last clear  */
#define NVMCTRL_INTFLAG_ERROR_Val_0           (NVMCTRL_INTFLAG_ERROR_Val_0_Val << NVMCTRL_INTFLAG_ERROR_Pos) /* (NVMCTRL_INTFLAG) No errors have been received since the last clear Position  */
#define NVMCTRL_INTFLAG_ERROR_Val_1           (NVMCTRL_INTFLAG_ERROR_Val_1_Val << NVMCTRL_INTFLAG_ERROR_Pos) /* (NVMCTRL_INTFLAG) At least one error has occurred since the last clear Position  */
#define NVMCTRL_INTFLAG_SERR_Pos              _UINT32_(8)                                          /* (NVMCTRL_INTFLAG) Single Bit Error Detection Flag Position */
#define NVMCTRL_INTFLAG_SERR_Msk              (_UINT32_(0x1) << NVMCTRL_INTFLAG_SERR_Pos)          /* (NVMCTRL_INTFLAG) Single Bit Error Detection Flag Mask */
#define NVMCTRL_INTFLAG_SERR(value)           (NVMCTRL_INTFLAG_SERR_Msk & (_UINT32_(value) << NVMCTRL_INTFLAG_SERR_Pos)) /* Assigment of value for SERR in the NVMCTRL_INTFLAG register */
#define NVMCTRL_INTFLAG_DERR_Pos              _UINT32_(9)                                          /* (NVMCTRL_INTFLAG) Double bit Error detection flag Position */
#define NVMCTRL_INTFLAG_DERR_Msk              (_UINT32_(0x1) << NVMCTRL_INTFLAG_DERR_Pos)          /* (NVMCTRL_INTFLAG) Double bit Error detection flag Mask */
#define NVMCTRL_INTFLAG_DERR(value)           (NVMCTRL_INTFLAG_DERR_Msk & (_UINT32_(value) << NVMCTRL_INTFLAG_DERR_Pos)) /* Assigment of value for DERR in the NVMCTRL_INTFLAG register */
#define NVMCTRL_INTFLAG_FLASHERR_Pos          _UINT32_(11)                                         /* (NVMCTRL_INTFLAG) FLASH Err Position */
#define NVMCTRL_INTFLAG_FLASHERR_Msk          (_UINT32_(0x1) << NVMCTRL_INTFLAG_FLASHERR_Pos)      /* (NVMCTRL_INTFLAG) FLASH Err Mask */
#define NVMCTRL_INTFLAG_FLASHERR(value)       (NVMCTRL_INTFLAG_FLASHERR_Msk & (_UINT32_(value) << NVMCTRL_INTFLAG_FLASHERR_Pos)) /* Assigment of value for FLASHERR in the NVMCTRL_INTFLAG register */
#define NVMCTRL_INTFLAG_FLTCAP_Pos            _UINT32_(24)                                         /* (NVMCTRL_INTFLAG) Fault Capture Interrupt Position */
#define NVMCTRL_INTFLAG_FLTCAP_Msk            (_UINT32_(0x1) << NVMCTRL_INTFLAG_FLTCAP_Pos)        /* (NVMCTRL_INTFLAG) Fault Capture Interrupt Mask */
#define NVMCTRL_INTFLAG_FLTCAP(value)         (NVMCTRL_INTFLAG_FLTCAP_Msk & (_UINT32_(value) << NVMCTRL_INTFLAG_FLTCAP_Pos)) /* Assigment of value for FLTCAP in the NVMCTRL_INTFLAG register */
#define NVMCTRL_INTFLAG_Msk                   _UINT32_(0x01000B03)                                 /* (NVMCTRL_INTFLAG) Register Mask  */


/* -------- NVMCTRL_STATUS : (NVMCTRL Offset: 0x18) (R/W 16) Status -------- */
#define NVMCTRL_STATUS_RESETVALUE             _UINT16_(0x00)                                       /*  (NVMCTRL_STATUS) Status  Reset Value */

#define NVMCTRL_STATUS_PRM_Pos                _UINT16_(0)                                          /* (NVMCTRL_STATUS) Power Reduction Mode Position */
#define NVMCTRL_STATUS_PRM_Msk                (_UINT16_(0x1) << NVMCTRL_STATUS_PRM_Pos)            /* (NVMCTRL_STATUS) Power Reduction Mode Mask */
#define NVMCTRL_STATUS_PRM(value)             (NVMCTRL_STATUS_PRM_Msk & (_UINT16_(value) << NVMCTRL_STATUS_PRM_Pos)) /* Assigment of value for PRM in the NVMCTRL_STATUS register */
#define NVMCTRL_STATUS_LOAD_Pos               _UINT16_(1)                                          /* (NVMCTRL_STATUS) NVM Page Buffer Active Loading Position */
#define NVMCTRL_STATUS_LOAD_Msk               (_UINT16_(0x1) << NVMCTRL_STATUS_LOAD_Pos)           /* (NVMCTRL_STATUS) NVM Page Buffer Active Loading Mask */
#define NVMCTRL_STATUS_LOAD(value)            (NVMCTRL_STATUS_LOAD_Msk & (_UINT16_(value) << NVMCTRL_STATUS_LOAD_Pos)) /* Assigment of value for LOAD in the NVMCTRL_STATUS register */
#define NVMCTRL_STATUS_PROGE_Pos              _UINT16_(2)                                          /* (NVMCTRL_STATUS) Programming Error Status Position */
#define NVMCTRL_STATUS_PROGE_Msk              (_UINT16_(0x1) << NVMCTRL_STATUS_PROGE_Pos)          /* (NVMCTRL_STATUS) Programming Error Status Mask */
#define NVMCTRL_STATUS_PROGE(value)           (NVMCTRL_STATUS_PROGE_Msk & (_UINT16_(value) << NVMCTRL_STATUS_PROGE_Pos)) /* Assigment of value for PROGE in the NVMCTRL_STATUS register */
#define NVMCTRL_STATUS_LOCKE_Pos              _UINT16_(3)                                          /* (NVMCTRL_STATUS) Lock Error Status Position */
#define NVMCTRL_STATUS_LOCKE_Msk              (_UINT16_(0x1) << NVMCTRL_STATUS_LOCKE_Pos)          /* (NVMCTRL_STATUS) Lock Error Status Mask */
#define NVMCTRL_STATUS_LOCKE(value)           (NVMCTRL_STATUS_LOCKE_Msk & (_UINT16_(value) << NVMCTRL_STATUS_LOCKE_Pos)) /* Assigment of value for LOCKE in the NVMCTRL_STATUS register */
#define NVMCTRL_STATUS_NVME_Pos               _UINT16_(4)                                          /* (NVMCTRL_STATUS) NVM Error Position */
#define NVMCTRL_STATUS_NVME_Msk               (_UINT16_(0x1) << NVMCTRL_STATUS_NVME_Pos)           /* (NVMCTRL_STATUS) NVM Error Mask */
#define NVMCTRL_STATUS_NVME(value)            (NVMCTRL_STATUS_NVME_Msk & (_UINT16_(value) << NVMCTRL_STATUS_NVME_Pos)) /* Assigment of value for NVME in the NVMCTRL_STATUS register */
#define NVMCTRL_STATUS_SB_Pos                 _UINT16_(8)                                          /* (NVMCTRL_STATUS) Security Bit Status Position */
#define NVMCTRL_STATUS_SB_Msk                 (_UINT16_(0x1) << NVMCTRL_STATUS_SB_Pos)             /* (NVMCTRL_STATUS) Security Bit Status Mask */
#define NVMCTRL_STATUS_SB(value)              (NVMCTRL_STATUS_SB_Msk & (_UINT16_(value) << NVMCTRL_STATUS_SB_Pos)) /* Assigment of value for SB in the NVMCTRL_STATUS register */
#define NVMCTRL_STATUS_Msk                    _UINT16_(0x011F)                                     /* (NVMCTRL_STATUS) Register Mask  */


/* -------- NVMCTRL_ADDR : (NVMCTRL Offset: 0x1C) (R/W 32) Address -------- */
#define NVMCTRL_ADDR_RESETVALUE               _UINT32_(0x00)                                       /*  (NVMCTRL_ADDR) Address  Reset Value */

#define NVMCTRL_ADDR_ADDR_Pos                 _UINT32_(0)                                          /* (NVMCTRL_ADDR) NVM Address Position */
#define NVMCTRL_ADDR_ADDR_Msk                 (_UINT32_(0x3FFFFF) << NVMCTRL_ADDR_ADDR_Pos)        /* (NVMCTRL_ADDR) NVM Address Mask */
#define NVMCTRL_ADDR_ADDR(value)              (NVMCTRL_ADDR_ADDR_Msk & (_UINT32_(value) << NVMCTRL_ADDR_ADDR_Pos)) /* Assigment of value for ADDR in the NVMCTRL_ADDR register */
#define NVMCTRL_ADDR_Msk                      _UINT32_(0x003FFFFF)                                 /* (NVMCTRL_ADDR) Register Mask  */


/* -------- NVMCTRL_LOCK : (NVMCTRL Offset: 0x20) (R/W 16) Lock Section -------- */
#define NVMCTRL_LOCK_RESETVALUE               _UINT16_(0x00)                                       /*  (NVMCTRL_LOCK) Lock Section  Reset Value */

#define NVMCTRL_LOCK_LOCK_Pos                 _UINT16_(0)                                          /* (NVMCTRL_LOCK) Region Lock Bits Position */
#define NVMCTRL_LOCK_LOCK_Msk                 (_UINT16_(0xFFFF) << NVMCTRL_LOCK_LOCK_Pos)          /* (NVMCTRL_LOCK) Region Lock Bits Mask */
#define NVMCTRL_LOCK_LOCK(value)              (NVMCTRL_LOCK_LOCK_Msk & (_UINT16_(value) << NVMCTRL_LOCK_LOCK_Pos)) /* Assigment of value for LOCK in the NVMCTRL_LOCK register */
#define NVMCTRL_LOCK_Msk                      _UINT16_(0xFFFF)                                     /* (NVMCTRL_LOCK) Register Mask  */


/* -------- NVMCTRL_PBLDATA0 : (NVMCTRL Offset: 0x28) ( R/ 32) Page Buffer Load Data 0 -------- */
#define NVMCTRL_PBLDATA0_RESETVALUE           _UINT32_(0xFFFFFFFF)                                 /*  (NVMCTRL_PBLDATA0) Page Buffer Load Data 0  Reset Value */

#define NVMCTRL_PBLDATA0_PBLDATA_Pos          _UINT32_(0)                                          /* (NVMCTRL_PBLDATA0) Page Buffer Load Data Position */
#define NVMCTRL_PBLDATA0_PBLDATA_Msk          (_UINT32_(0xFFFFFFFF) << NVMCTRL_PBLDATA0_PBLDATA_Pos) /* (NVMCTRL_PBLDATA0) Page Buffer Load Data Mask */
#define NVMCTRL_PBLDATA0_PBLDATA(value)       (NVMCTRL_PBLDATA0_PBLDATA_Msk & (_UINT32_(value) << NVMCTRL_PBLDATA0_PBLDATA_Pos)) /* Assigment of value for PBLDATA in the NVMCTRL_PBLDATA0 register */
#define NVMCTRL_PBLDATA0_Msk                  _UINT32_(0xFFFFFFFF)                                 /* (NVMCTRL_PBLDATA0) Register Mask  */


/* -------- NVMCTRL_PBLDATA1 : (NVMCTRL Offset: 0x2C) ( R/ 32) Page Buffer Load Data 1 -------- */
#define NVMCTRL_PBLDATA1_RESETVALUE           _UINT32_(0xFFFFFFFF)                                 /*  (NVMCTRL_PBLDATA1) Page Buffer Load Data 1  Reset Value */

#define NVMCTRL_PBLDATA1_PBLDATA_Pos          _UINT32_(0)                                          /* (NVMCTRL_PBLDATA1) Page Buffer Load Data Position */
#define NVMCTRL_PBLDATA1_PBLDATA_Msk          (_UINT32_(0xFFFFFFFF) << NVMCTRL_PBLDATA1_PBLDATA_Pos) /* (NVMCTRL_PBLDATA1) Page Buffer Load Data Mask */
#define NVMCTRL_PBLDATA1_PBLDATA(value)       (NVMCTRL_PBLDATA1_PBLDATA_Msk & (_UINT32_(value) << NVMCTRL_PBLDATA1_PBLDATA_Pos)) /* Assigment of value for PBLDATA in the NVMCTRL_PBLDATA1 register */
#define NVMCTRL_PBLDATA1_Msk                  _UINT32_(0xFFFFFFFF)                                 /* (NVMCTRL_PBLDATA1) Register Mask  */


/* -------- NVMCTRL_ECCCTRL : (NVMCTRL Offset: 0x80) (R/W 16) ECC control -------- */
#define NVMCTRL_ECCCTRL_RESETVALUE            _UINT16_(0x00)                                       /*  (NVMCTRL_ECCCTRL) ECC control  Reset Value */

#define NVMCTRL_ECCCTRL_ECCDIS_Pos            _UINT16_(0)                                          /* (NVMCTRL_ECCCTRL) FLASH ECC Disable Position */
#define NVMCTRL_ECCCTRL_ECCDIS_Msk            (_UINT16_(0x1) << NVMCTRL_ECCCTRL_ECCDIS_Pos)        /* (NVMCTRL_ECCCTRL) FLASH ECC Disable Mask */
#define NVMCTRL_ECCCTRL_ECCDIS(value)         (NVMCTRL_ECCCTRL_ECCDIS_Msk & (_UINT16_(value) << NVMCTRL_ECCCTRL_ECCDIS_Pos)) /* Assigment of value for ECCDIS in the NVMCTRL_ECCCTRL register */
#define   NVMCTRL_ECCCTRL_ECCDIS_En_Val       _UINT16_(0x0)                                        /* (NVMCTRL_ECCCTRL) Flash ECC is Enabled  */
#define   NVMCTRL_ECCCTRL_ECCDIS_Dis_Val      _UINT16_(0x1)                                        /* (NVMCTRL_ECCCTRL) Flash ECC is Not Enabled, once written to 1 by user ECC can only be re-enabled only by a reset  */
#define NVMCTRL_ECCCTRL_ECCDIS_En             (NVMCTRL_ECCCTRL_ECCDIS_En_Val << NVMCTRL_ECCCTRL_ECCDIS_Pos) /* (NVMCTRL_ECCCTRL) Flash ECC is Enabled Position  */
#define NVMCTRL_ECCCTRL_ECCDIS_Dis            (NVMCTRL_ECCCTRL_ECCDIS_Dis_Val << NVMCTRL_ECCCTRL_ECCDIS_Pos) /* (NVMCTRL_ECCCTRL) Flash ECC is Not Enabled, once written to 1 by user ECC can only be re-enabled only by a reset Position  */
#define NVMCTRL_ECCCTRL_ECCDFDIS_Pos          _UINT16_(1)                                          /* (NVMCTRL_ECCCTRL) Data Flash ECC Disable Position */
#define NVMCTRL_ECCCTRL_ECCDFDIS_Msk          (_UINT16_(0x1) << NVMCTRL_ECCCTRL_ECCDFDIS_Pos)      /* (NVMCTRL_ECCCTRL) Data Flash ECC Disable Mask */
#define NVMCTRL_ECCCTRL_ECCDFDIS(value)       (NVMCTRL_ECCCTRL_ECCDFDIS_Msk & (_UINT16_(value) << NVMCTRL_ECCCTRL_ECCDFDIS_Pos)) /* Assigment of value for ECCDFDIS in the NVMCTRL_ECCCTRL register */
#define   NVMCTRL_ECCCTRL_ECCDFDIS_En_Val     _UINT16_(0x0)                                        /* (NVMCTRL_ECCCTRL) Data Flash ECC is Enabled  */
#define   NVMCTRL_ECCCTRL_ECCDFDIS_Dis_Val    _UINT16_(0x1)                                        /* (NVMCTRL_ECCCTRL) Data Flash ECC is Not Enabled, once written to 1 by user ECC can only be re-enabled only by a reset  */
#define NVMCTRL_ECCCTRL_ECCDFDIS_En           (NVMCTRL_ECCCTRL_ECCDFDIS_En_Val << NVMCTRL_ECCCTRL_ECCDFDIS_Pos) /* (NVMCTRL_ECCCTRL) Data Flash ECC is Enabled Position  */
#define NVMCTRL_ECCCTRL_ECCDFDIS_Dis          (NVMCTRL_ECCCTRL_ECCDFDIS_Dis_Val << NVMCTRL_ECCCTRL_ECCDFDIS_Pos) /* (NVMCTRL_ECCCTRL) Data Flash ECC is Not Enabled, once written to 1 by user ECC can only be re-enabled only by a reset Position  */
#define NVMCTRL_ECCCTRL_SECCNT_Pos            _UINT16_(8)                                          /* (NVMCTRL_ECCCTRL) Flash SEC Count Position */
#define NVMCTRL_ECCCTRL_SECCNT_Msk            (_UINT16_(0xFF) << NVMCTRL_ECCCTRL_SECCNT_Pos)       /* (NVMCTRL_ECCCTRL) Flash SEC Count Mask */
#define NVMCTRL_ECCCTRL_SECCNT(value)         (NVMCTRL_ECCCTRL_SECCNT_Msk & (_UINT16_(value) << NVMCTRL_ECCCTRL_SECCNT_Pos)) /* Assigment of value for SECCNT in the NVMCTRL_ECCCTRL register */
#define NVMCTRL_ECCCTRL_Msk                   _UINT16_(0xFF03)                                     /* (NVMCTRL_ECCCTRL) Register Mask  */


/* -------- NVMCTRL_FLTCTRL : (NVMCTRL Offset: 0x84) (R/W 16) Fault injection control -------- */
#define NVMCTRL_FLTCTRL_RESETVALUE            _UINT16_(0x00)                                       /*  (NVMCTRL_FLTCTRL) Fault injection control  Reset Value */

#define NVMCTRL_FLTCTRL_FLTRST_Pos            _UINT16_(0)                                          /* (NVMCTRL_FLTCTRL) Fault reset Position */
#define NVMCTRL_FLTCTRL_FLTRST_Msk            (_UINT16_(0x1) << NVMCTRL_FLTCTRL_FLTRST_Pos)        /* (NVMCTRL_FLTCTRL) Fault reset Mask */
#define NVMCTRL_FLTCTRL_FLTRST(value)         (NVMCTRL_FLTCTRL_FLTRST_Msk & (_UINT16_(value) << NVMCTRL_FLTCTRL_FLTRST_Pos)) /* Assigment of value for FLTRST in the NVMCTRL_FLTCTRL register */
#define   NVMCTRL_FLTCTRL_FLTRST_Val_0_Val    _UINT16_(0x0)                                        /* (NVMCTRL_FLTCTRL) No Effect  */
#define   NVMCTRL_FLTCTRL_FLTRST_Val_1_Val    _UINT16_(0x1)                                        /* (NVMCTRL_FLTCTRL) Resets all FLT SFR bits. {FLTCTRL, FFLTPTR, FFLTADR, FFLTCAP, FFLTPAR, FFLTSYN}  */
#define NVMCTRL_FLTCTRL_FLTRST_Val_0          (NVMCTRL_FLTCTRL_FLTRST_Val_0_Val << NVMCTRL_FLTCTRL_FLTRST_Pos) /* (NVMCTRL_FLTCTRL) No Effect Position  */
#define NVMCTRL_FLTCTRL_FLTRST_Val_1          (NVMCTRL_FLTCTRL_FLTRST_Val_1_Val << NVMCTRL_FLTCTRL_FLTRST_Pos) /* (NVMCTRL_FLTCTRL) Resets all FLT SFR bits. {FLTCTRL, FFLTPTR, FFLTADR, FFLTCAP, FFLTPAR, FFLTSYN} Position  */
#define NVMCTRL_FLTCTRL_FLTEN_Pos             _UINT16_(1)                                          /* (NVMCTRL_FLTCTRL) Fault Injection Enabled Position */
#define NVMCTRL_FLTCTRL_FLTEN_Msk             (_UINT16_(0x1) << NVMCTRL_FLTCTRL_FLTEN_Pos)         /* (NVMCTRL_FLTCTRL) Fault Injection Enabled Mask */
#define NVMCTRL_FLTCTRL_FLTEN(value)          (NVMCTRL_FLTCTRL_FLTEN_Msk & (_UINT16_(value) << NVMCTRL_FLTCTRL_FLTEN_Pos)) /* Assigment of value for FLTEN in the NVMCTRL_FLTCTRL register */
#define   NVMCTRL_FLTCTRL_FLTEN_Dis_Val       _UINT16_(0x0)                                        /* (NVMCTRL_FLTCTRL) Disables the Write/Read fault injection  */
#define   NVMCTRL_FLTCTRL_FLTEN_En_Val        _UINT16_(0x1)                                        /* (NVMCTRL_FLTCTRL) Enables the Write/Read fault injection to occur selected by FLTMD  */
#define NVMCTRL_FLTCTRL_FLTEN_Dis             (NVMCTRL_FLTCTRL_FLTEN_Dis_Val << NVMCTRL_FLTCTRL_FLTEN_Pos) /* (NVMCTRL_FLTCTRL) Disables the Write/Read fault injection Position  */
#define NVMCTRL_FLTCTRL_FLTEN_En              (NVMCTRL_FLTCTRL_FLTEN_En_Val << NVMCTRL_FLTCTRL_FLTEN_Pos) /* (NVMCTRL_FLTCTRL) Enables the Write/Read fault injection to occur selected by FLTMD Position  */
#define NVMCTRL_FLTCTRL_FLTMD_Pos             _UINT16_(12)                                         /* (NVMCTRL_FLTCTRL) Fault Mode Control Position */
#define NVMCTRL_FLTCTRL_FLTMD_Msk             (_UINT16_(0x7) << NVMCTRL_FLTCTRL_FLTMD_Pos)         /* (NVMCTRL_FLTCTRL) Fault Mode Control Mask */
#define NVMCTRL_FLTCTRL_FLTMD(value)          (NVMCTRL_FLTCTRL_FLTMD_Msk & (_UINT16_(value) << NVMCTRL_FLTCTRL_FLTMD_Pos)) /* Assigment of value for FLTMD in the NVMCTRL_FLTCTRL register */
#define   NVMCTRL_FLTCTRL_FLTMD_Val_0_Val     _UINT16_(0x0)                                        /* (NVMCTRL_FLTCTRL) Fault Injection Disabled  */
#define   NVMCTRL_FLTCTRL_FLTMD_Val_2_Val     _UINT16_(0x2)                                        /* (NVMCTRL_FLTCTRL) Fault Capture Mode Enabled (Capture the address (in FFLTCAP) and Syndrome in (FFLTSYND))  */
#define   NVMCTRL_FLTCTRL_FLTMD_Val_4_Val     _UINT16_(0x4)                                        /* (NVMCTRL_FLTCTRL) Single Fault Injection (at bit selected by FLT1PTR) for Reads  */
#define   NVMCTRL_FLTCTRL_FLTMD_Val_5_Val     _UINT16_(0x5)                                        /* (NVMCTRL_FLTCTRL) Double Fault Injection (uses FLT1PTR and FLT2PTR) for Reads  */
#define   NVMCTRL_FLTCTRL_FLTMD_Val_6_Val     _UINT16_(0x6)                                        /* (NVMCTRL_FLTCTRL) Single Fault Injection (at bit selected by FLT1PTR) for Writes  */
#define   NVMCTRL_FLTCTRL_FLTMD_Val_7_Val     _UINT16_(0x7)                                        /* (NVMCTRL_FLTCTRL) Double Fault Injection (uses FLT1PTR and FLT2PTR) for Writes  */
#define NVMCTRL_FLTCTRL_FLTMD_Val_0           (NVMCTRL_FLTCTRL_FLTMD_Val_0_Val << NVMCTRL_FLTCTRL_FLTMD_Pos) /* (NVMCTRL_FLTCTRL) Fault Injection Disabled Position  */
#define NVMCTRL_FLTCTRL_FLTMD_Val_2           (NVMCTRL_FLTCTRL_FLTMD_Val_2_Val << NVMCTRL_FLTCTRL_FLTMD_Pos) /* (NVMCTRL_FLTCTRL) Fault Capture Mode Enabled (Capture the address (in FFLTCAP) and Syndrome in (FFLTSYND)) Position  */
#define NVMCTRL_FLTCTRL_FLTMD_Val_4           (NVMCTRL_FLTCTRL_FLTMD_Val_4_Val << NVMCTRL_FLTCTRL_FLTMD_Pos) /* (NVMCTRL_FLTCTRL) Single Fault Injection (at bit selected by FLT1PTR) for Reads Position  */
#define NVMCTRL_FLTCTRL_FLTMD_Val_5           (NVMCTRL_FLTCTRL_FLTMD_Val_5_Val << NVMCTRL_FLTCTRL_FLTMD_Pos) /* (NVMCTRL_FLTCTRL) Double Fault Injection (uses FLT1PTR and FLT2PTR) for Reads Position  */
#define NVMCTRL_FLTCTRL_FLTMD_Val_6           (NVMCTRL_FLTCTRL_FLTMD_Val_6_Val << NVMCTRL_FLTCTRL_FLTMD_Pos) /* (NVMCTRL_FLTCTRL) Single Fault Injection (at bit selected by FLT1PTR) for Writes Position  */
#define NVMCTRL_FLTCTRL_FLTMD_Val_7           (NVMCTRL_FLTCTRL_FLTMD_Val_7_Val << NVMCTRL_FLTCTRL_FLTMD_Pos) /* (NVMCTRL_FLTCTRL) Double Fault Injection (uses FLT1PTR and FLT2PTR) for Writes Position  */
#define NVMCTRL_FLTCTRL_Msk                   _UINT16_(0x7003)                                     /* (NVMCTRL_FLTCTRL) Register Mask  */


/* -------- NVMCTRL_FFLTPTR : (NVMCTRL Offset: 0x88) (R/W 32) Fault injection pointer -------- */
#define NVMCTRL_FFLTPTR_RESETVALUE            _UINT32_(0x00)                                       /*  (NVMCTRL_FFLTPTR) Fault injection pointer  Reset Value */

#define NVMCTRL_FFLTPTR_FLT1PTR_Pos           _UINT32_(0)                                          /* (NVMCTRL_FFLTPTR) Fault Injection Pointer 1 Position */
#define NVMCTRL_FFLTPTR_FLT1PTR_Msk           (_UINT32_(0xFF) << NVMCTRL_FFLTPTR_FLT1PTR_Pos)      /* (NVMCTRL_FFLTPTR) Fault Injection Pointer 1 Mask */
#define NVMCTRL_FFLTPTR_FLT1PTR(value)        (NVMCTRL_FFLTPTR_FLT1PTR_Msk & (_UINT32_(value) << NVMCTRL_FFLTPTR_FLT1PTR_Pos)) /* Assigment of value for FLT1PTR in the NVMCTRL_FFLTPTR register */
#define NVMCTRL_FFLTPTR_FLT2PTR_Pos           _UINT32_(16)                                         /* (NVMCTRL_FFLTPTR) Fault Injection pointer 2 Position */
#define NVMCTRL_FFLTPTR_FLT2PTR_Msk           (_UINT32_(0xFF) << NVMCTRL_FFLTPTR_FLT2PTR_Pos)      /* (NVMCTRL_FFLTPTR) Fault Injection pointer 2 Mask */
#define NVMCTRL_FFLTPTR_FLT2PTR(value)        (NVMCTRL_FFLTPTR_FLT2PTR_Msk & (_UINT32_(value) << NVMCTRL_FFLTPTR_FLT2PTR_Pos)) /* Assigment of value for FLT2PTR in the NVMCTRL_FFLTPTR register */
#define NVMCTRL_FFLTPTR_Msk                   _UINT32_(0x00FF00FF)                                 /* (NVMCTRL_FFLTPTR) Register Mask  */


/* -------- NVMCTRL_FFLTADR : (NVMCTRL Offset: 0x8C) (R/W 32) Fault injection address -------- */
#define NVMCTRL_FFLTADR_RESETVALUE            _UINT32_(0x00)                                       /*  (NVMCTRL_FFLTADR) Fault injection address  Reset Value */

#define NVMCTRL_FFLTADR_FLTADR_Pos            _UINT32_(0)                                          /* (NVMCTRL_FFLTADR) Fault Injection Address Position */
#define NVMCTRL_FFLTADR_FLTADR_Msk            (_UINT32_(0xFFFFFF) << NVMCTRL_FFLTADR_FLTADR_Pos)   /* (NVMCTRL_FFLTADR) Fault Injection Address Mask */
#define NVMCTRL_FFLTADR_FLTADR(value)         (NVMCTRL_FFLTADR_FLTADR_Msk & (_UINT32_(value) << NVMCTRL_FFLTADR_FLTADR_Pos)) /* Assigment of value for FLTADR in the NVMCTRL_FFLTADR register */
#define NVMCTRL_FFLTADR_Msk                   _UINT32_(0x00FFFFFF)                                 /* (NVMCTRL_FFLTADR) Register Mask  */


/* -------- NVMCTRL_FFLTCAP : (NVMCTRL Offset: 0x90) ( R/ 32) Fault error capture addr -------- */
#define NVMCTRL_FFLTCAP_RESETVALUE            _UINT32_(0x00)                                       /*  (NVMCTRL_FFLTCAP) Fault error capture addr  Reset Value */

#define NVMCTRL_FFLTCAP_FLTADR_Pos            _UINT32_(0)                                          /* (NVMCTRL_FFLTCAP) Fault Capture Address Position */
#define NVMCTRL_FFLTCAP_FLTADR_Msk            (_UINT32_(0xFFFFFF) << NVMCTRL_FFLTCAP_FLTADR_Pos)   /* (NVMCTRL_FFLTCAP) Fault Capture Address Mask */
#define NVMCTRL_FFLTCAP_FLTADR(value)         (NVMCTRL_FFLTCAP_FLTADR_Msk & (_UINT32_(value) << NVMCTRL_FFLTCAP_FLTADR_Pos)) /* Assigment of value for FLTADR in the NVMCTRL_FFLTCAP register */
#define NVMCTRL_FFLTCAP_Msk                   _UINT32_(0x00FFFFFF)                                 /* (NVMCTRL_FFLTCAP) Register Mask  */


/* -------- NVMCTRL_FFLTPAR : (NVMCTRL Offset: 0x94) ( R/ 32) Fault parity -------- */
#define NVMCTRL_FFLTPAR_RESETVALUE            _UINT32_(0x00)                                       /*  (NVMCTRL_FFLTPAR) Fault parity  Reset Value */

#define NVMCTRL_FFLTPAR_SECIN_Pos             _UINT32_(0)                                          /* (NVMCTRL_FFLTPAR) Single Error Parity Bits Position */
#define NVMCTRL_FFLTPAR_SECIN_Msk             (_UINT32_(0xFF) << NVMCTRL_FFLTPAR_SECIN_Pos)        /* (NVMCTRL_FFLTPAR) Single Error Parity Bits Mask */
#define NVMCTRL_FFLTPAR_SECIN(value)          (NVMCTRL_FFLTPAR_SECIN_Msk & (_UINT32_(value) << NVMCTRL_FFLTPAR_SECIN_Pos)) /* Assigment of value for SECIN in the NVMCTRL_FFLTPAR register */
#define NVMCTRL_FFLTPAR_SECOUT_Pos            _UINT32_(16)                                         /* (NVMCTRL_FFLTPAR) The Calculated Single Error Parity Bits Position */
#define NVMCTRL_FFLTPAR_SECOUT_Msk            (_UINT32_(0xFF) << NVMCTRL_FFLTPAR_SECOUT_Pos)       /* (NVMCTRL_FFLTPAR) The Calculated Single Error Parity Bits Mask */
#define NVMCTRL_FFLTPAR_SECOUT(value)         (NVMCTRL_FFLTPAR_SECOUT_Msk & (_UINT32_(value) << NVMCTRL_FFLTPAR_SECOUT_Pos)) /* Assigment of value for SECOUT in the NVMCTRL_FFLTPAR register */
#define NVMCTRL_FFLTPAR_Msk                   _UINT32_(0x00FF00FF)                                 /* (NVMCTRL_FFLTPAR) Register Mask  */


/* -------- NVMCTRL_FFLTSYN : (NVMCTRL Offset: 0x98) ( R/ 32) Fault ECC syndrome -------- */
#define NVMCTRL_FFLTSYN_RESETVALUE            _UINT32_(0x00)                                       /*  (NVMCTRL_FFLTSYN) Fault ECC syndrome  Reset Value */

#define NVMCTRL_FFLTSYN_SECSYN_Pos            _UINT32_(0)                                          /* (NVMCTRL_FFLTSYN) Single Error Syndrome Position */
#define NVMCTRL_FFLTSYN_SECSYN_Msk            (_UINT32_(0xFF) << NVMCTRL_FFLTSYN_SECSYN_Pos)       /* (NVMCTRL_FFLTSYN) Single Error Syndrome Mask */
#define NVMCTRL_FFLTSYN_SECSYN(value)         (NVMCTRL_FFLTSYN_SECSYN_Msk & (_UINT32_(value) << NVMCTRL_FFLTSYN_SECSYN_Pos)) /* Assigment of value for SECSYN in the NVMCTRL_FFLTSYN register */
#define NVMCTRL_FFLTSYN_DERRSERR_Pos          _UINT32_(16)                                         /* (NVMCTRL_FFLTSYN) Double Error detected, Single error corrected Position */
#define NVMCTRL_FFLTSYN_DERRSERR_Msk          (_UINT32_(0x3) << NVMCTRL_FFLTSYN_DERRSERR_Pos)      /* (NVMCTRL_FFLTSYN) Double Error detected, Single error corrected Mask */
#define NVMCTRL_FFLTSYN_DERRSERR(value)       (NVMCTRL_FFLTSYN_DERRSERR_Msk & (_UINT32_(value) << NVMCTRL_FFLTSYN_DERRSERR_Pos)) /* Assigment of value for DERRSERR in the NVMCTRL_FFLTSYN register */
#define NVMCTRL_FFLTSYN_Msk                   _UINT32_(0x000300FF)                                 /* (NVMCTRL_FFLTSYN) Register Mask  */


/* -------- NVMCTRL_DBGCTRL : (NVMCTRL Offset: 0x9C) (R/W 8) Debug control -------- */
#define NVMCTRL_DBGCTRL_RESETVALUE            _UINT8_(0x00)                                        /*  (NVMCTRL_DBGCTRL) Debug control  Reset Value */

#define NVMCTRL_DBGCTRL_DBGECC_Pos            _UINT8_(1)                                           /* (NVMCTRL_DBGCTRL) ECC errors from debugger reads are Position */
#define NVMCTRL_DBGCTRL_DBGECC_Msk            (_UINT8_(0x3) << NVMCTRL_DBGCTRL_DBGECC_Pos)         /* (NVMCTRL_DBGCTRL) ECC errors from debugger reads are Mask */
#define NVMCTRL_DBGCTRL_DBGECC(value)         (NVMCTRL_DBGCTRL_DBGECC_Msk & (_UINT8_(value) << NVMCTRL_DBGCTRL_DBGECC_Pos)) /* Assigment of value for DBGECC in the NVMCTRL_DBGCTRL register */
#define   NVMCTRL_DBGCTRL_DBGECC_VAL_0_Val    _UINT8_(0x0)                                         /* (NVMCTRL_DBGCTRL) Corrected, INTFLAG is not updated and FLT logic is not updated  */
#define   NVMCTRL_DBGCTRL_DBGECC_VAL_1_Val    _UINT8_(0x1)                                         /* (NVMCTRL_DBGCTRL) Not corrected, INTFLAG is not updated, and FLT logic is not updated  */
#define   NVMCTRL_DBGCTRL_DBGECC_VAL_2_Val    _UINT8_(0x2)                                         /* (NVMCTRL_DBGCTRL) Corrected, INTFLAG is updated and FLT logic operates as setup  */
#define   NVMCTRL_DBGCTRL_DBGECC_VAL_3_Val    _UINT8_(0x3)                                         /* (NVMCTRL_DBGCTRL) Not corrected, INTFLAG is not updated, and FLT logic is not updated  */
#define NVMCTRL_DBGCTRL_DBGECC_VAL_0          (NVMCTRL_DBGCTRL_DBGECC_VAL_0_Val << NVMCTRL_DBGCTRL_DBGECC_Pos) /* (NVMCTRL_DBGCTRL) Corrected, INTFLAG is not updated and FLT logic is not updated Position  */
#define NVMCTRL_DBGCTRL_DBGECC_VAL_1          (NVMCTRL_DBGCTRL_DBGECC_VAL_1_Val << NVMCTRL_DBGCTRL_DBGECC_Pos) /* (NVMCTRL_DBGCTRL) Not corrected, INTFLAG is not updated, and FLT logic is not updated Position  */
#define NVMCTRL_DBGCTRL_DBGECC_VAL_2          (NVMCTRL_DBGCTRL_DBGECC_VAL_2_Val << NVMCTRL_DBGCTRL_DBGECC_Pos) /* (NVMCTRL_DBGCTRL) Corrected, INTFLAG is updated and FLT logic operates as setup Position  */
#define NVMCTRL_DBGCTRL_DBGECC_VAL_3          (NVMCTRL_DBGCTRL_DBGECC_VAL_3_Val << NVMCTRL_DBGCTRL_DBGECC_Pos) /* (NVMCTRL_DBGCTRL) Not corrected, INTFLAG is not updated, and FLT logic is not updated Position  */
#define NVMCTRL_DBGCTRL_Msk                   _UINT8_(0x06)                                        /* (NVMCTRL_DBGCTRL) Register Mask  */


/** \brief NVMCTRL register offsets definitions */
#define NVMCTRL_CTRLA_REG_OFST         _UINT32_(0x00)      /* (NVMCTRL_CTRLA) Control A Offset */
#define NVMCTRL_CTRLB_REG_OFST         _UINT32_(0x04)      /* (NVMCTRL_CTRLB) Control B Offset */
#define NVMCTRL_PARAM_REG_OFST         _UINT32_(0x08)      /* (NVMCTRL_PARAM) NVM Parameter Offset */
#define NVMCTRL_INTENCLR_REG_OFST      _UINT32_(0x0C)      /* (NVMCTRL_INTENCLR) Interrupt Enable Clear Offset */
#define NVMCTRL_INTENSET_REG_OFST      _UINT32_(0x10)      /* (NVMCTRL_INTENSET) Interrupt Enable Set Offset */
#define NVMCTRL_INTFLAG_REG_OFST       _UINT32_(0x14)      /* (NVMCTRL_INTFLAG) Interrupt Flag Status and Clear Offset */
#define NVMCTRL_STATUS_REG_OFST        _UINT32_(0x18)      /* (NVMCTRL_STATUS) Status Offset */
#define NVMCTRL_ADDR_REG_OFST          _UINT32_(0x1C)      /* (NVMCTRL_ADDR) Address Offset */
#define NVMCTRL_LOCK_REG_OFST          _UINT32_(0x20)      /* (NVMCTRL_LOCK) Lock Section Offset */
#define NVMCTRL_PBLDATA0_REG_OFST      _UINT32_(0x28)      /* (NVMCTRL_PBLDATA0) Page Buffer Load Data 0 Offset */
#define NVMCTRL_PBLDATA1_REG_OFST      _UINT32_(0x2C)      /* (NVMCTRL_PBLDATA1) Page Buffer Load Data 1 Offset */
#define NVMCTRL_ECCCTRL_REG_OFST       _UINT32_(0x80)      /* (NVMCTRL_ECCCTRL) ECC control Offset */
#define NVMCTRL_FLTCTRL_REG_OFST       _UINT32_(0x84)      /* (NVMCTRL_FLTCTRL) Fault injection control Offset */
#define NVMCTRL_FFLTPTR_REG_OFST       _UINT32_(0x88)      /* (NVMCTRL_FFLTPTR) Fault injection pointer Offset */
#define NVMCTRL_FFLTADR_REG_OFST       _UINT32_(0x8C)      /* (NVMCTRL_FFLTADR) Fault injection address Offset */
#define NVMCTRL_FFLTCAP_REG_OFST       _UINT32_(0x90)      /* (NVMCTRL_FFLTCAP) Fault error capture addr Offset */
#define NVMCTRL_FFLTPAR_REG_OFST       _UINT32_(0x94)      /* (NVMCTRL_FFLTPAR) Fault parity Offset */
#define NVMCTRL_FFLTSYN_REG_OFST       _UINT32_(0x98)      /* (NVMCTRL_FFLTSYN) Fault ECC syndrome Offset */
#define NVMCTRL_DBGCTRL_REG_OFST       _UINT32_(0x9C)      /* (NVMCTRL_DBGCTRL) Debug control Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief NVMCTRL register API structure */
typedef struct
{  /* Non-Volatile Memory Controller */
  __IO  uint16_t                       NVMCTRL_CTRLA;      /**< Offset: 0x00 (R/W  16) Control A */
  __I   uint8_t                        Reserved1[0x02];
  __IO  uint32_t                       NVMCTRL_CTRLB;      /**< Offset: 0x04 (R/W  32) Control B */
  __IO  uint32_t                       NVMCTRL_PARAM;      /**< Offset: 0x08 (R/W  32) NVM Parameter */
  __IO  uint32_t                       NVMCTRL_INTENCLR;   /**< Offset: 0x0C (R/W  32) Interrupt Enable Clear */
  __IO  uint32_t                       NVMCTRL_INTENSET;   /**< Offset: 0x10 (R/W  32) Interrupt Enable Set */
  __IO  uint32_t                       NVMCTRL_INTFLAG;    /**< Offset: 0x14 (R/W  32) Interrupt Flag Status and Clear */
  __IO  uint16_t                       NVMCTRL_STATUS;     /**< Offset: 0x18 (R/W  16) Status */
  __I   uint8_t                        Reserved2[0x02];
  __IO  uint32_t                       NVMCTRL_ADDR;       /**< Offset: 0x1C (R/W  32) Address */
  __IO  uint16_t                       NVMCTRL_LOCK;       /**< Offset: 0x20 (R/W  16) Lock Section */
  __I   uint8_t                        Reserved3[0x06];
  __I   uint32_t                       NVMCTRL_PBLDATA0;   /**< Offset: 0x28 (R/   32) Page Buffer Load Data 0 */
  __I   uint32_t                       NVMCTRL_PBLDATA1;   /**< Offset: 0x2C (R/   32) Page Buffer Load Data 1 */
  __I   uint8_t                        Reserved4[0x50];
  __IO  uint16_t                       NVMCTRL_ECCCTRL;    /**< Offset: 0x80 (R/W  16) ECC control */
  __I   uint8_t                        Reserved5[0x02];
  __IO  uint16_t                       NVMCTRL_FLTCTRL;    /**< Offset: 0x84 (R/W  16) Fault injection control */
  __I   uint8_t                        Reserved6[0x02];
  __IO  uint32_t                       NVMCTRL_FFLTPTR;    /**< Offset: 0x88 (R/W  32) Fault injection pointer */
  __IO  uint32_t                       NVMCTRL_FFLTADR;    /**< Offset: 0x8C (R/W  32) Fault injection address */
  __I   uint32_t                       NVMCTRL_FFLTCAP;    /**< Offset: 0x90 (R/   32) Fault error capture addr */
  __I   uint32_t                       NVMCTRL_FFLTPAR;    /**< Offset: 0x94 (R/   32) Fault parity */
  __I   uint32_t                       NVMCTRL_FFLTSYN;    /**< Offset: 0x98 (R/   32) Fault ECC syndrome */
  __IO  uint8_t                        NVMCTRL_DBGCTRL;    /**< Offset: 0x9C (R/W  8) Debug control */
} nvmctrl_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CMJH01_NVMCTRL_COMPONENT_H_ */
