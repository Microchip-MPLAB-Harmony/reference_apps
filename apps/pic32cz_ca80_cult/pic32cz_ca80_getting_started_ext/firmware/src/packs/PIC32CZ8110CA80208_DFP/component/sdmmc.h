/*
 * Component description for SDMMC
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
#ifndef _PIC32CZCA80_SDMMC_COMPONENT_H_
#define _PIC32CZCA80_SDMMC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR SDMMC                                        */
/* ************************************************************************** */

/* -------- SDMMC_SSAR : (SDMMC Offset: 0x00) (R/W 32) SDMA System Address / Argument 2 -------- */
#define SDMMC_SSAR_RESETVALUE                 _UINT32_(0x00)                                       /*  (SDMMC_SSAR) SDMA System Address / Argument 2  Reset Value */

#define SDMMC_SSAR_ADDR_Pos                   _UINT32_(0)                                          /* (SDMMC_SSAR) SDMA System Address Position */
#define SDMMC_SSAR_ADDR_Msk                   (_UINT32_(0xFFFFFFFF) << SDMMC_SSAR_ADDR_Pos)        /* (SDMMC_SSAR) SDMA System Address Mask */
#define SDMMC_SSAR_ADDR(value)                (SDMMC_SSAR_ADDR_Msk & (_UINT32_(value) << SDMMC_SSAR_ADDR_Pos)) /* Assigment of value for ADDR in the SDMMC_SSAR register */
#define SDMMC_SSAR_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (SDMMC_SSAR) Register Mask  */

/* CMD23 mode */
#define SDMMC_SSAR_CMD23_ARG2_Pos             _UINT32_(0)                                          /* (SDMMC_SSAR) Argument 2 Position */
#define SDMMC_SSAR_CMD23_ARG2_Msk             (_UINT32_(0xFFFFFFFF) << SDMMC_SSAR_CMD23_ARG2_Pos)  /* (SDMMC_SSAR) Argument 2 Mask */
#define SDMMC_SSAR_CMD23_ARG2(value)          (SDMMC_SSAR_CMD23_ARG2_Msk & (_UINT32_(value) << SDMMC_SSAR_CMD23_ARG2_Pos))
#define SDMMC_SSAR_CMD23_Msk                  _UINT32_(0xFFFFFFFF)                                  /* (SDMMC_SSAR_CMD23) Register Mask  */


/* -------- SDMMC_BSR : (SDMMC Offset: 0x04) (R/W 16) Block Size -------- */
#define SDMMC_BSR_RESETVALUE                  _UINT16_(0x00)                                       /*  (SDMMC_BSR) Block Size  Reset Value */

#define SDMMC_BSR_BLOCKSIZE_Pos               _UINT16_(0)                                          /* (SDMMC_BSR) Transfer Block Size Position */
#define SDMMC_BSR_BLOCKSIZE_Msk               (_UINT16_(0x3FF) << SDMMC_BSR_BLOCKSIZE_Pos)         /* (SDMMC_BSR) Transfer Block Size Mask */
#define SDMMC_BSR_BLOCKSIZE(value)            (SDMMC_BSR_BLOCKSIZE_Msk & (_UINT16_(value) << SDMMC_BSR_BLOCKSIZE_Pos)) /* Assigment of value for BLOCKSIZE in the SDMMC_BSR register */
#define SDMMC_BSR_BOUNDARY_Pos                _UINT16_(12)                                         /* (SDMMC_BSR) SDMA Buffer Boundary Position */
#define SDMMC_BSR_BOUNDARY_Msk                (_UINT16_(0x7) << SDMMC_BSR_BOUNDARY_Pos)            /* (SDMMC_BSR) SDMA Buffer Boundary Mask */
#define SDMMC_BSR_BOUNDARY(value)             (SDMMC_BSR_BOUNDARY_Msk & (_UINT16_(value) << SDMMC_BSR_BOUNDARY_Pos)) /* Assigment of value for BOUNDARY in the SDMMC_BSR register */
#define   SDMMC_BSR_BOUNDARY_4K_Val           _UINT16_(0x0)                                        /* (SDMMC_BSR) 4k bytes  */
#define   SDMMC_BSR_BOUNDARY_8K_Val           _UINT16_(0x1)                                        /* (SDMMC_BSR) 8k bytes  */
#define   SDMMC_BSR_BOUNDARY_16K_Val          _UINT16_(0x2)                                        /* (SDMMC_BSR) 16k bytes  */
#define   SDMMC_BSR_BOUNDARY_32K_Val          _UINT16_(0x3)                                        /* (SDMMC_BSR) 32k bytes  */
#define   SDMMC_BSR_BOUNDARY_64K_Val          _UINT16_(0x4)                                        /* (SDMMC_BSR) 64k bytes  */
#define   SDMMC_BSR_BOUNDARY_128K_Val         _UINT16_(0x5)                                        /* (SDMMC_BSR) 128k bytes  */
#define   SDMMC_BSR_BOUNDARY_256K_Val         _UINT16_(0x6)                                        /* (SDMMC_BSR) 256k bytes  */
#define   SDMMC_BSR_BOUNDARY_512K_Val         _UINT16_(0x7)                                        /* (SDMMC_BSR) 512k bytes  */
#define SDMMC_BSR_BOUNDARY_4K                 (SDMMC_BSR_BOUNDARY_4K_Val << SDMMC_BSR_BOUNDARY_Pos) /* (SDMMC_BSR) 4k bytes Position  */
#define SDMMC_BSR_BOUNDARY_8K                 (SDMMC_BSR_BOUNDARY_8K_Val << SDMMC_BSR_BOUNDARY_Pos) /* (SDMMC_BSR) 8k bytes Position  */
#define SDMMC_BSR_BOUNDARY_16K                (SDMMC_BSR_BOUNDARY_16K_Val << SDMMC_BSR_BOUNDARY_Pos) /* (SDMMC_BSR) 16k bytes Position  */
#define SDMMC_BSR_BOUNDARY_32K                (SDMMC_BSR_BOUNDARY_32K_Val << SDMMC_BSR_BOUNDARY_Pos) /* (SDMMC_BSR) 32k bytes Position  */
#define SDMMC_BSR_BOUNDARY_64K                (SDMMC_BSR_BOUNDARY_64K_Val << SDMMC_BSR_BOUNDARY_Pos) /* (SDMMC_BSR) 64k bytes Position  */
#define SDMMC_BSR_BOUNDARY_128K               (SDMMC_BSR_BOUNDARY_128K_Val << SDMMC_BSR_BOUNDARY_Pos) /* (SDMMC_BSR) 128k bytes Position  */
#define SDMMC_BSR_BOUNDARY_256K               (SDMMC_BSR_BOUNDARY_256K_Val << SDMMC_BSR_BOUNDARY_Pos) /* (SDMMC_BSR) 256k bytes Position  */
#define SDMMC_BSR_BOUNDARY_512K               (SDMMC_BSR_BOUNDARY_512K_Val << SDMMC_BSR_BOUNDARY_Pos) /* (SDMMC_BSR) 512k bytes Position  */
#define SDMMC_BSR_Msk                         _UINT16_(0x73FF)                                     /* (SDMMC_BSR) Register Mask  */


/* -------- SDMMC_BCR : (SDMMC Offset: 0x06) (R/W 16) Block Count -------- */
#define SDMMC_BCR_RESETVALUE                  _UINT16_(0x00)                                       /*  (SDMMC_BCR) Block Count  Reset Value */

#define SDMMC_BCR_BCNT_Pos                    _UINT16_(0)                                          /* (SDMMC_BCR) Blocks Count for Current Transfer Position */
#define SDMMC_BCR_BCNT_Msk                    (_UINT16_(0xFFFF) << SDMMC_BCR_BCNT_Pos)             /* (SDMMC_BCR) Blocks Count for Current Transfer Mask */
#define SDMMC_BCR_BCNT(value)                 (SDMMC_BCR_BCNT_Msk & (_UINT16_(value) << SDMMC_BCR_BCNT_Pos)) /* Assigment of value for BCNT in the SDMMC_BCR register */
#define SDMMC_BCR_Msk                         _UINT16_(0xFFFF)                                     /* (SDMMC_BCR) Register Mask  */


/* -------- SDMMC_ARG1R : (SDMMC Offset: 0x08) (R/W 32) Argument 1 -------- */
#define SDMMC_ARG1R_RESETVALUE                _UINT32_(0x00)                                       /*  (SDMMC_ARG1R) Argument 1  Reset Value */

#define SDMMC_ARG1R_ARG_Pos                   _UINT32_(0)                                          /* (SDMMC_ARG1R) Argument 1 Position */
#define SDMMC_ARG1R_ARG_Msk                   (_UINT32_(0xFFFFFFFF) << SDMMC_ARG1R_ARG_Pos)        /* (SDMMC_ARG1R) Argument 1 Mask */
#define SDMMC_ARG1R_ARG(value)                (SDMMC_ARG1R_ARG_Msk & (_UINT32_(value) << SDMMC_ARG1R_ARG_Pos)) /* Assigment of value for ARG in the SDMMC_ARG1R register */
#define SDMMC_ARG1R_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (SDMMC_ARG1R) Register Mask  */


/* -------- SDMMC_TMR : (SDMMC Offset: 0x0C) (R/W 16) Transfer Mode -------- */
#define SDMMC_TMR_RESETVALUE                  _UINT16_(0x00)                                       /*  (SDMMC_TMR) Transfer Mode  Reset Value */

#define SDMMC_TMR_DMAEN_Pos                   _UINT16_(0)                                          /* (SDMMC_TMR) DMA Enable Position */
#define SDMMC_TMR_DMAEN_Msk                   (_UINT16_(0x1) << SDMMC_TMR_DMAEN_Pos)               /* (SDMMC_TMR) DMA Enable Mask */
#define SDMMC_TMR_DMAEN(value)                (SDMMC_TMR_DMAEN_Msk & (_UINT16_(value) << SDMMC_TMR_DMAEN_Pos)) /* Assigment of value for DMAEN in the SDMMC_TMR register */
#define   SDMMC_TMR_DMAEN_DISABLE_Val         _UINT16_(0x0)                                        /* (SDMMC_TMR) No data transfer or Non DMA data transfer  */
#define   SDMMC_TMR_DMAEN_ENABLE_Val          _UINT16_(0x1)                                        /* (SDMMC_TMR) DMA data transfer  */
#define SDMMC_TMR_DMAEN_DISABLE               (SDMMC_TMR_DMAEN_DISABLE_Val << SDMMC_TMR_DMAEN_Pos) /* (SDMMC_TMR) No data transfer or Non DMA data transfer Position  */
#define SDMMC_TMR_DMAEN_ENABLE                (SDMMC_TMR_DMAEN_ENABLE_Val << SDMMC_TMR_DMAEN_Pos)  /* (SDMMC_TMR) DMA data transfer Position  */
#define SDMMC_TMR_BCEN_Pos                    _UINT16_(1)                                          /* (SDMMC_TMR) Block Count Enable Position */
#define SDMMC_TMR_BCEN_Msk                    (_UINT16_(0x1) << SDMMC_TMR_BCEN_Pos)                /* (SDMMC_TMR) Block Count Enable Mask */
#define SDMMC_TMR_BCEN(value)                 (SDMMC_TMR_BCEN_Msk & (_UINT16_(value) << SDMMC_TMR_BCEN_Pos)) /* Assigment of value for BCEN in the SDMMC_TMR register */
#define   SDMMC_TMR_BCEN_DISABLE_Val          _UINT16_(0x0)                                        /* (SDMMC_TMR) Disable  */
#define   SDMMC_TMR_BCEN_ENABLE_Val           _UINT16_(0x1)                                        /* (SDMMC_TMR) Enable  */
#define SDMMC_TMR_BCEN_DISABLE                (SDMMC_TMR_BCEN_DISABLE_Val << SDMMC_TMR_BCEN_Pos)   /* (SDMMC_TMR) Disable Position  */
#define SDMMC_TMR_BCEN_ENABLE                 (SDMMC_TMR_BCEN_ENABLE_Val << SDMMC_TMR_BCEN_Pos)    /* (SDMMC_TMR) Enable Position  */
#define SDMMC_TMR_ACMDEN_Pos                  _UINT16_(2)                                          /* (SDMMC_TMR) Auto Command Enable Position */
#define SDMMC_TMR_ACMDEN_Msk                  (_UINT16_(0x3) << SDMMC_TMR_ACMDEN_Pos)              /* (SDMMC_TMR) Auto Command Enable Mask */
#define SDMMC_TMR_ACMDEN(value)               (SDMMC_TMR_ACMDEN_Msk & (_UINT16_(value) << SDMMC_TMR_ACMDEN_Pos)) /* Assigment of value for ACMDEN in the SDMMC_TMR register */
#define   SDMMC_TMR_ACMDEN_DISABLED_Val       _UINT16_(0x0)                                        /* (SDMMC_TMR) Auto Command Disabled  */
#define   SDMMC_TMR_ACMDEN_CMD12_Val          _UINT16_(0x1)                                        /* (SDMMC_TMR) Auto CMD12 Enable  */
#define   SDMMC_TMR_ACMDEN_CMD23_Val          _UINT16_(0x2)                                        /* (SDMMC_TMR) Auto CMD23 Enable  */
#define SDMMC_TMR_ACMDEN_DISABLED             (SDMMC_TMR_ACMDEN_DISABLED_Val << SDMMC_TMR_ACMDEN_Pos) /* (SDMMC_TMR) Auto Command Disabled Position  */
#define SDMMC_TMR_ACMDEN_CMD12                (SDMMC_TMR_ACMDEN_CMD12_Val << SDMMC_TMR_ACMDEN_Pos) /* (SDMMC_TMR) Auto CMD12 Enable Position  */
#define SDMMC_TMR_ACMDEN_CMD23                (SDMMC_TMR_ACMDEN_CMD23_Val << SDMMC_TMR_ACMDEN_Pos) /* (SDMMC_TMR) Auto CMD23 Enable Position  */
#define SDMMC_TMR_DTDSEL_Pos                  _UINT16_(4)                                          /* (SDMMC_TMR) Data Transfer Direction Selection Position */
#define SDMMC_TMR_DTDSEL_Msk                  (_UINT16_(0x1) << SDMMC_TMR_DTDSEL_Pos)              /* (SDMMC_TMR) Data Transfer Direction Selection Mask */
#define SDMMC_TMR_DTDSEL(value)               (SDMMC_TMR_DTDSEL_Msk & (_UINT16_(value) << SDMMC_TMR_DTDSEL_Pos)) /* Assigment of value for DTDSEL in the SDMMC_TMR register */
#define   SDMMC_TMR_DTDSEL_WRITE_Val          _UINT16_(0x0)                                        /* (SDMMC_TMR) Write (Host to Card)  */
#define   SDMMC_TMR_DTDSEL_READ_Val           _UINT16_(0x1)                                        /* (SDMMC_TMR) Read (Card to Host)  */
#define SDMMC_TMR_DTDSEL_WRITE                (SDMMC_TMR_DTDSEL_WRITE_Val << SDMMC_TMR_DTDSEL_Pos) /* (SDMMC_TMR) Write (Host to Card) Position  */
#define SDMMC_TMR_DTDSEL_READ                 (SDMMC_TMR_DTDSEL_READ_Val << SDMMC_TMR_DTDSEL_Pos)  /* (SDMMC_TMR) Read (Card to Host) Position  */
#define SDMMC_TMR_MSBSEL_Pos                  _UINT16_(5)                                          /* (SDMMC_TMR) Multi/Single Block Selection Position */
#define SDMMC_TMR_MSBSEL_Msk                  (_UINT16_(0x1) << SDMMC_TMR_MSBSEL_Pos)              /* (SDMMC_TMR) Multi/Single Block Selection Mask */
#define SDMMC_TMR_MSBSEL(value)               (SDMMC_TMR_MSBSEL_Msk & (_UINT16_(value) << SDMMC_TMR_MSBSEL_Pos)) /* Assigment of value for MSBSEL in the SDMMC_TMR register */
#define   SDMMC_TMR_MSBSEL_SINGLE_Val         _UINT16_(0x0)                                        /* (SDMMC_TMR) Single Block  */
#define   SDMMC_TMR_MSBSEL_MULTIPLE_Val       _UINT16_(0x1)                                        /* (SDMMC_TMR) Multiple Block  */
#define SDMMC_TMR_MSBSEL_SINGLE               (SDMMC_TMR_MSBSEL_SINGLE_Val << SDMMC_TMR_MSBSEL_Pos) /* (SDMMC_TMR) Single Block Position  */
#define SDMMC_TMR_MSBSEL_MULTIPLE             (SDMMC_TMR_MSBSEL_MULTIPLE_Val << SDMMC_TMR_MSBSEL_Pos) /* (SDMMC_TMR) Multiple Block Position  */
#define SDMMC_TMR_Msk                         _UINT16_(0x003F)                                     /* (SDMMC_TMR) Register Mask  */


/* -------- SDMMC_CR : (SDMMC Offset: 0x0E) (R/W 16) Command -------- */
#define SDMMC_CR_RESETVALUE                   _UINT16_(0x00)                                       /*  (SDMMC_CR) Command  Reset Value */

#define SDMMC_CR_RESPTYP_Pos                  _UINT16_(0)                                          /* (SDMMC_CR) Response Type Position */
#define SDMMC_CR_RESPTYP_Msk                  (_UINT16_(0x3) << SDMMC_CR_RESPTYP_Pos)              /* (SDMMC_CR) Response Type Mask */
#define SDMMC_CR_RESPTYP(value)               (SDMMC_CR_RESPTYP_Msk & (_UINT16_(value) << SDMMC_CR_RESPTYP_Pos)) /* Assigment of value for RESPTYP in the SDMMC_CR register */
#define   SDMMC_CR_RESPTYP_NONE_Val           _UINT16_(0x0)                                        /* (SDMMC_CR) No response  */
#define   SDMMC_CR_RESPTYP_136_BIT_Val        _UINT16_(0x1)                                        /* (SDMMC_CR) 136-bit response  */
#define   SDMMC_CR_RESPTYP_48_BIT_Val         _UINT16_(0x2)                                        /* (SDMMC_CR) 48-bit response  */
#define   SDMMC_CR_RESPTYP_48_BIT_BUSY_Val    _UINT16_(0x3)                                        /* (SDMMC_CR) 48-bit response check busy after response  */
#define SDMMC_CR_RESPTYP_NONE                 (SDMMC_CR_RESPTYP_NONE_Val << SDMMC_CR_RESPTYP_Pos)  /* (SDMMC_CR) No response Position  */
#define SDMMC_CR_RESPTYP_136_BIT              (SDMMC_CR_RESPTYP_136_BIT_Val << SDMMC_CR_RESPTYP_Pos) /* (SDMMC_CR) 136-bit response Position  */
#define SDMMC_CR_RESPTYP_48_BIT               (SDMMC_CR_RESPTYP_48_BIT_Val << SDMMC_CR_RESPTYP_Pos) /* (SDMMC_CR) 48-bit response Position  */
#define SDMMC_CR_RESPTYP_48_BIT_BUSY          (SDMMC_CR_RESPTYP_48_BIT_BUSY_Val << SDMMC_CR_RESPTYP_Pos) /* (SDMMC_CR) 48-bit response check busy after response Position  */
#define SDMMC_CR_CMDCCEN_Pos                  _UINT16_(3)                                          /* (SDMMC_CR) Command CRC Check Enable Position */
#define SDMMC_CR_CMDCCEN_Msk                  (_UINT16_(0x1) << SDMMC_CR_CMDCCEN_Pos)              /* (SDMMC_CR) Command CRC Check Enable Mask */
#define SDMMC_CR_CMDCCEN(value)               (SDMMC_CR_CMDCCEN_Msk & (_UINT16_(value) << SDMMC_CR_CMDCCEN_Pos)) /* Assigment of value for CMDCCEN in the SDMMC_CR register */
#define   SDMMC_CR_CMDCCEN_DISABLE_Val        _UINT16_(0x0)                                        /* (SDMMC_CR) Disable  */
#define   SDMMC_CR_CMDCCEN_ENABLE_Val         _UINT16_(0x1)                                        /* (SDMMC_CR) Enable  */
#define SDMMC_CR_CMDCCEN_DISABLE              (SDMMC_CR_CMDCCEN_DISABLE_Val << SDMMC_CR_CMDCCEN_Pos) /* (SDMMC_CR) Disable Position  */
#define SDMMC_CR_CMDCCEN_ENABLE               (SDMMC_CR_CMDCCEN_ENABLE_Val << SDMMC_CR_CMDCCEN_Pos) /* (SDMMC_CR) Enable Position  */
#define SDMMC_CR_CMDICEN_Pos                  _UINT16_(4)                                          /* (SDMMC_CR) Command Index Check Enable Position */
#define SDMMC_CR_CMDICEN_Msk                  (_UINT16_(0x1) << SDMMC_CR_CMDICEN_Pos)              /* (SDMMC_CR) Command Index Check Enable Mask */
#define SDMMC_CR_CMDICEN(value)               (SDMMC_CR_CMDICEN_Msk & (_UINT16_(value) << SDMMC_CR_CMDICEN_Pos)) /* Assigment of value for CMDICEN in the SDMMC_CR register */
#define   SDMMC_CR_CMDICEN_DISABLE_Val        _UINT16_(0x0)                                        /* (SDMMC_CR) Disable  */
#define   SDMMC_CR_CMDICEN_ENABLE_Val         _UINT16_(0x1)                                        /* (SDMMC_CR) Enable  */
#define SDMMC_CR_CMDICEN_DISABLE              (SDMMC_CR_CMDICEN_DISABLE_Val << SDMMC_CR_CMDICEN_Pos) /* (SDMMC_CR) Disable Position  */
#define SDMMC_CR_CMDICEN_ENABLE               (SDMMC_CR_CMDICEN_ENABLE_Val << SDMMC_CR_CMDICEN_Pos) /* (SDMMC_CR) Enable Position  */
#define SDMMC_CR_DPSEL_Pos                    _UINT16_(5)                                          /* (SDMMC_CR) Data Present Select Position */
#define SDMMC_CR_DPSEL_Msk                    (_UINT16_(0x1) << SDMMC_CR_DPSEL_Pos)                /* (SDMMC_CR) Data Present Select Mask */
#define SDMMC_CR_DPSEL(value)                 (SDMMC_CR_DPSEL_Msk & (_UINT16_(value) << SDMMC_CR_DPSEL_Pos)) /* Assigment of value for DPSEL in the SDMMC_CR register */
#define   SDMMC_CR_DPSEL_NO_DATA_Val          _UINT16_(0x0)                                        /* (SDMMC_CR) No Data Present  */
#define   SDMMC_CR_DPSEL_DATA_Val             _UINT16_(0x1)                                        /* (SDMMC_CR) Data Present  */
#define SDMMC_CR_DPSEL_NO_DATA                (SDMMC_CR_DPSEL_NO_DATA_Val << SDMMC_CR_DPSEL_Pos)   /* (SDMMC_CR) No Data Present Position  */
#define SDMMC_CR_DPSEL_DATA                   (SDMMC_CR_DPSEL_DATA_Val << SDMMC_CR_DPSEL_Pos)      /* (SDMMC_CR) Data Present Position  */
#define SDMMC_CR_CMDTYP_Pos                   _UINT16_(6)                                          /* (SDMMC_CR) Command Type Position */
#define SDMMC_CR_CMDTYP_Msk                   (_UINT16_(0x3) << SDMMC_CR_CMDTYP_Pos)               /* (SDMMC_CR) Command Type Mask */
#define SDMMC_CR_CMDTYP(value)                (SDMMC_CR_CMDTYP_Msk & (_UINT16_(value) << SDMMC_CR_CMDTYP_Pos)) /* Assigment of value for CMDTYP in the SDMMC_CR register */
#define   SDMMC_CR_CMDTYP_NORMAL_Val          _UINT16_(0x0)                                        /* (SDMMC_CR) Other commands  */
#define   SDMMC_CR_CMDTYP_SUSPEND_Val         _UINT16_(0x1)                                        /* (SDMMC_CR) CMD52 for writing Bus Suspend in CCCR  */
#define   SDMMC_CR_CMDTYP_RESUME_Val          _UINT16_(0x2)                                        /* (SDMMC_CR) CMD52 for writing Function Select in CCCR  */
#define   SDMMC_CR_CMDTYP_ABORT_Val           _UINT16_(0x3)                                        /* (SDMMC_CR) CMD12, CMD52 for writing I/O Abort in CCCR  */
#define SDMMC_CR_CMDTYP_NORMAL                (SDMMC_CR_CMDTYP_NORMAL_Val << SDMMC_CR_CMDTYP_Pos)  /* (SDMMC_CR) Other commands Position  */
#define SDMMC_CR_CMDTYP_SUSPEND               (SDMMC_CR_CMDTYP_SUSPEND_Val << SDMMC_CR_CMDTYP_Pos) /* (SDMMC_CR) CMD52 for writing Bus Suspend in CCCR Position  */
#define SDMMC_CR_CMDTYP_RESUME                (SDMMC_CR_CMDTYP_RESUME_Val << SDMMC_CR_CMDTYP_Pos)  /* (SDMMC_CR) CMD52 for writing Function Select in CCCR Position  */
#define SDMMC_CR_CMDTYP_ABORT                 (SDMMC_CR_CMDTYP_ABORT_Val << SDMMC_CR_CMDTYP_Pos)   /* (SDMMC_CR) CMD12, CMD52 for writing I/O Abort in CCCR Position  */
#define SDMMC_CR_CMDIDX_Pos                   _UINT16_(8)                                          /* (SDMMC_CR) Command Index Position */
#define SDMMC_CR_CMDIDX_Msk                   (_UINT16_(0x3F) << SDMMC_CR_CMDIDX_Pos)              /* (SDMMC_CR) Command Index Mask */
#define SDMMC_CR_CMDIDX(value)                (SDMMC_CR_CMDIDX_Msk & (_UINT16_(value) << SDMMC_CR_CMDIDX_Pos)) /* Assigment of value for CMDIDX in the SDMMC_CR register */
#define SDMMC_CR_Msk                          _UINT16_(0x3FFB)                                     /* (SDMMC_CR) Register Mask  */


/* -------- SDMMC_RR : (SDMMC Offset: 0x10) ( R/ 32) Response -------- */
#define SDMMC_RR_RESETVALUE                   _UINT32_(0x00)                                       /*  (SDMMC_RR) Response  Reset Value */

#define SDMMC_RR_CMDRESP_Pos                  _UINT32_(0)                                          /* (SDMMC_RR) Command Response Position */
#define SDMMC_RR_CMDRESP_Msk                  (_UINT32_(0xFFFFFFFF) << SDMMC_RR_CMDRESP_Pos)       /* (SDMMC_RR) Command Response Mask */
#define SDMMC_RR_CMDRESP(value)               (SDMMC_RR_CMDRESP_Msk & (_UINT32_(value) << SDMMC_RR_CMDRESP_Pos)) /* Assigment of value for CMDRESP in the SDMMC_RR register */
#define SDMMC_RR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (SDMMC_RR) Register Mask  */


/* -------- SDMMC_BDPR : (SDMMC Offset: 0x20) (R/W 32) Buffer Data Port -------- */
#define SDMMC_BDPR_RESETVALUE                 _UINT32_(0x00)                                       /*  (SDMMC_BDPR) Buffer Data Port  Reset Value */

#define SDMMC_BDPR_BUFDATA_Pos                _UINT32_(0)                                          /* (SDMMC_BDPR) Buffer Data Position */
#define SDMMC_BDPR_BUFDATA_Msk                (_UINT32_(0xFFFFFFFF) << SDMMC_BDPR_BUFDATA_Pos)     /* (SDMMC_BDPR) Buffer Data Mask */
#define SDMMC_BDPR_BUFDATA(value)             (SDMMC_BDPR_BUFDATA_Msk & (_UINT32_(value) << SDMMC_BDPR_BUFDATA_Pos)) /* Assigment of value for BUFDATA in the SDMMC_BDPR register */
#define SDMMC_BDPR_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (SDMMC_BDPR) Register Mask  */


/* -------- SDMMC_PSR : (SDMMC Offset: 0x24) ( R/ 32) Present State -------- */
#define SDMMC_PSR_RESETVALUE                  _UINT32_(0xF80000)                                   /*  (SDMMC_PSR) Present State  Reset Value */

#define SDMMC_PSR_CMDINHC_Pos                 _UINT32_(0)                                          /* (SDMMC_PSR) Command Inhibit (CMD) Position */
#define SDMMC_PSR_CMDINHC_Msk                 (_UINT32_(0x1) << SDMMC_PSR_CMDINHC_Pos)             /* (SDMMC_PSR) Command Inhibit (CMD) Mask */
#define SDMMC_PSR_CMDINHC(value)              (SDMMC_PSR_CMDINHC_Msk & (_UINT32_(value) << SDMMC_PSR_CMDINHC_Pos)) /* Assigment of value for CMDINHC in the SDMMC_PSR register */
#define   SDMMC_PSR_CMDINHC_CAN_Val           _UINT32_(0x0)                                        /* (SDMMC_PSR) Can issue command using only CMD line  */
#define   SDMMC_PSR_CMDINHC_CANNOT_Val        _UINT32_(0x1)                                        /* (SDMMC_PSR) Cannot issue command  */
#define SDMMC_PSR_CMDINHC_CAN                 (SDMMC_PSR_CMDINHC_CAN_Val << SDMMC_PSR_CMDINHC_Pos) /* (SDMMC_PSR) Can issue command using only CMD line Position  */
#define SDMMC_PSR_CMDINHC_CANNOT              (SDMMC_PSR_CMDINHC_CANNOT_Val << SDMMC_PSR_CMDINHC_Pos) /* (SDMMC_PSR) Cannot issue command Position  */
#define SDMMC_PSR_CMDINHD_Pos                 _UINT32_(1)                                          /* (SDMMC_PSR) Command Inhibit (DAT) Position */
#define SDMMC_PSR_CMDINHD_Msk                 (_UINT32_(0x1) << SDMMC_PSR_CMDINHD_Pos)             /* (SDMMC_PSR) Command Inhibit (DAT) Mask */
#define SDMMC_PSR_CMDINHD(value)              (SDMMC_PSR_CMDINHD_Msk & (_UINT32_(value) << SDMMC_PSR_CMDINHD_Pos)) /* Assigment of value for CMDINHD in the SDMMC_PSR register */
#define   SDMMC_PSR_CMDINHD_CAN_Val           _UINT32_(0x0)                                        /* (SDMMC_PSR) Can issue command which uses the DAT line  */
#define   SDMMC_PSR_CMDINHD_CANNOT_Val        _UINT32_(0x1)                                        /* (SDMMC_PSR) Cannot issue command which uses the DAT line  */
#define SDMMC_PSR_CMDINHD_CAN                 (SDMMC_PSR_CMDINHD_CAN_Val << SDMMC_PSR_CMDINHD_Pos) /* (SDMMC_PSR) Can issue command which uses the DAT line Position  */
#define SDMMC_PSR_CMDINHD_CANNOT              (SDMMC_PSR_CMDINHD_CANNOT_Val << SDMMC_PSR_CMDINHD_Pos) /* (SDMMC_PSR) Cannot issue command which uses the DAT line Position  */
#define SDMMC_PSR_DLACT_Pos                   _UINT32_(2)                                          /* (SDMMC_PSR) DAT Line Active Position */
#define SDMMC_PSR_DLACT_Msk                   (_UINT32_(0x1) << SDMMC_PSR_DLACT_Pos)               /* (SDMMC_PSR) DAT Line Active Mask */
#define SDMMC_PSR_DLACT(value)                (SDMMC_PSR_DLACT_Msk & (_UINT32_(value) << SDMMC_PSR_DLACT_Pos)) /* Assigment of value for DLACT in the SDMMC_PSR register */
#define   SDMMC_PSR_DLACT_INACTIVE_Val        _UINT32_(0x0)                                        /* (SDMMC_PSR) DAT Line Inactive  */
#define   SDMMC_PSR_DLACT_ACTIVE_Val          _UINT32_(0x1)                                        /* (SDMMC_PSR) DAT Line Active  */
#define SDMMC_PSR_DLACT_INACTIVE              (SDMMC_PSR_DLACT_INACTIVE_Val << SDMMC_PSR_DLACT_Pos) /* (SDMMC_PSR) DAT Line Inactive Position  */
#define SDMMC_PSR_DLACT_ACTIVE                (SDMMC_PSR_DLACT_ACTIVE_Val << SDMMC_PSR_DLACT_Pos)  /* (SDMMC_PSR) DAT Line Active Position  */
#define SDMMC_PSR_RTREQ_Pos                   _UINT32_(3)                                          /* (SDMMC_PSR) Re-Tuning Request Position */
#define SDMMC_PSR_RTREQ_Msk                   (_UINT32_(0x1) << SDMMC_PSR_RTREQ_Pos)               /* (SDMMC_PSR) Re-Tuning Request Mask */
#define SDMMC_PSR_RTREQ(value)                (SDMMC_PSR_RTREQ_Msk & (_UINT32_(value) << SDMMC_PSR_RTREQ_Pos)) /* Assigment of value for RTREQ in the SDMMC_PSR register */
#define   SDMMC_PSR_RTREQ_OK_Val              _UINT32_(0x0)                                        /* (SDMMC_PSR) Fixed or well-tuned sampling clock  */
#define   SDMMC_PSR_RTREQ_REQUIRED_Val        _UINT32_(0x1)                                        /* (SDMMC_PSR) Sampling clock needs re-tuning  */
#define SDMMC_PSR_RTREQ_OK                    (SDMMC_PSR_RTREQ_OK_Val << SDMMC_PSR_RTREQ_Pos)      /* (SDMMC_PSR) Fixed or well-tuned sampling clock Position  */
#define SDMMC_PSR_RTREQ_REQUIRED              (SDMMC_PSR_RTREQ_REQUIRED_Val << SDMMC_PSR_RTREQ_Pos) /* (SDMMC_PSR) Sampling clock needs re-tuning Position  */
#define SDMMC_PSR_WTACT_Pos                   _UINT32_(8)                                          /* (SDMMC_PSR) Write Transfer Active Position */
#define SDMMC_PSR_WTACT_Msk                   (_UINT32_(0x1) << SDMMC_PSR_WTACT_Pos)               /* (SDMMC_PSR) Write Transfer Active Mask */
#define SDMMC_PSR_WTACT(value)                (SDMMC_PSR_WTACT_Msk & (_UINT32_(value) << SDMMC_PSR_WTACT_Pos)) /* Assigment of value for WTACT in the SDMMC_PSR register */
#define   SDMMC_PSR_WTACT_NO_Val              _UINT32_(0x0)                                        /* (SDMMC_PSR) No valid data  */
#define   SDMMC_PSR_WTACT_YES_Val             _UINT32_(0x1)                                        /* (SDMMC_PSR) Transferring data  */
#define SDMMC_PSR_WTACT_NO                    (SDMMC_PSR_WTACT_NO_Val << SDMMC_PSR_WTACT_Pos)      /* (SDMMC_PSR) No valid data Position  */
#define SDMMC_PSR_WTACT_YES                   (SDMMC_PSR_WTACT_YES_Val << SDMMC_PSR_WTACT_Pos)     /* (SDMMC_PSR) Transferring data Position  */
#define SDMMC_PSR_RTACT_Pos                   _UINT32_(9)                                          /* (SDMMC_PSR) Read Transfer Active Position */
#define SDMMC_PSR_RTACT_Msk                   (_UINT32_(0x1) << SDMMC_PSR_RTACT_Pos)               /* (SDMMC_PSR) Read Transfer Active Mask */
#define SDMMC_PSR_RTACT(value)                (SDMMC_PSR_RTACT_Msk & (_UINT32_(value) << SDMMC_PSR_RTACT_Pos)) /* Assigment of value for RTACT in the SDMMC_PSR register */
#define   SDMMC_PSR_RTACT_NO_Val              _UINT32_(0x0)                                        /* (SDMMC_PSR) No valid data  */
#define   SDMMC_PSR_RTACT_YES_Val             _UINT32_(0x1)                                        /* (SDMMC_PSR) Transferring data  */
#define SDMMC_PSR_RTACT_NO                    (SDMMC_PSR_RTACT_NO_Val << SDMMC_PSR_RTACT_Pos)      /* (SDMMC_PSR) No valid data Position  */
#define SDMMC_PSR_RTACT_YES                   (SDMMC_PSR_RTACT_YES_Val << SDMMC_PSR_RTACT_Pos)     /* (SDMMC_PSR) Transferring data Position  */
#define SDMMC_PSR_BUFWREN_Pos                 _UINT32_(10)                                         /* (SDMMC_PSR) Buffer Write Enable Position */
#define SDMMC_PSR_BUFWREN_Msk                 (_UINT32_(0x1) << SDMMC_PSR_BUFWREN_Pos)             /* (SDMMC_PSR) Buffer Write Enable Mask */
#define SDMMC_PSR_BUFWREN(value)              (SDMMC_PSR_BUFWREN_Msk & (_UINT32_(value) << SDMMC_PSR_BUFWREN_Pos)) /* Assigment of value for BUFWREN in the SDMMC_PSR register */
#define   SDMMC_PSR_BUFWREN_DISABLE_Val       _UINT32_(0x0)                                        /* (SDMMC_PSR) Write disable  */
#define   SDMMC_PSR_BUFWREN_ENABLE_Val        _UINT32_(0x1)                                        /* (SDMMC_PSR) Write enable  */
#define SDMMC_PSR_BUFWREN_DISABLE             (SDMMC_PSR_BUFWREN_DISABLE_Val << SDMMC_PSR_BUFWREN_Pos) /* (SDMMC_PSR) Write disable Position  */
#define SDMMC_PSR_BUFWREN_ENABLE              (SDMMC_PSR_BUFWREN_ENABLE_Val << SDMMC_PSR_BUFWREN_Pos) /* (SDMMC_PSR) Write enable Position  */
#define SDMMC_PSR_BUFRDEN_Pos                 _UINT32_(11)                                         /* (SDMMC_PSR) Buffer Read Enable Position */
#define SDMMC_PSR_BUFRDEN_Msk                 (_UINT32_(0x1) << SDMMC_PSR_BUFRDEN_Pos)             /* (SDMMC_PSR) Buffer Read Enable Mask */
#define SDMMC_PSR_BUFRDEN(value)              (SDMMC_PSR_BUFRDEN_Msk & (_UINT32_(value) << SDMMC_PSR_BUFRDEN_Pos)) /* Assigment of value for BUFRDEN in the SDMMC_PSR register */
#define   SDMMC_PSR_BUFRDEN_DISABLE_Val       _UINT32_(0x0)                                        /* (SDMMC_PSR) Read disable  */
#define   SDMMC_PSR_BUFRDEN_ENABLE_Val        _UINT32_(0x1)                                        /* (SDMMC_PSR) Read enable  */
#define SDMMC_PSR_BUFRDEN_DISABLE             (SDMMC_PSR_BUFRDEN_DISABLE_Val << SDMMC_PSR_BUFRDEN_Pos) /* (SDMMC_PSR) Read disable Position  */
#define SDMMC_PSR_BUFRDEN_ENABLE              (SDMMC_PSR_BUFRDEN_ENABLE_Val << SDMMC_PSR_BUFRDEN_Pos) /* (SDMMC_PSR) Read enable Position  */
#define SDMMC_PSR_CARDINS_Pos                 _UINT32_(16)                                         /* (SDMMC_PSR) Card Inserted Position */
#define SDMMC_PSR_CARDINS_Msk                 (_UINT32_(0x1) << SDMMC_PSR_CARDINS_Pos)             /* (SDMMC_PSR) Card Inserted Mask */
#define SDMMC_PSR_CARDINS(value)              (SDMMC_PSR_CARDINS_Msk & (_UINT32_(value) << SDMMC_PSR_CARDINS_Pos)) /* Assigment of value for CARDINS in the SDMMC_PSR register */
#define   SDMMC_PSR_CARDINS_NO_Val            _UINT32_(0x0)                                        /* (SDMMC_PSR) Reset or Debouncing or No Card  */
#define   SDMMC_PSR_CARDINS_YES_Val           _UINT32_(0x1)                                        /* (SDMMC_PSR) Card inserted  */
#define SDMMC_PSR_CARDINS_NO                  (SDMMC_PSR_CARDINS_NO_Val << SDMMC_PSR_CARDINS_Pos)  /* (SDMMC_PSR) Reset or Debouncing or No Card Position  */
#define SDMMC_PSR_CARDINS_YES                 (SDMMC_PSR_CARDINS_YES_Val << SDMMC_PSR_CARDINS_Pos) /* (SDMMC_PSR) Card inserted Position  */
#define SDMMC_PSR_CARDSS_Pos                  _UINT32_(17)                                         /* (SDMMC_PSR) Card State Stable Position */
#define SDMMC_PSR_CARDSS_Msk                  (_UINT32_(0x1) << SDMMC_PSR_CARDSS_Pos)              /* (SDMMC_PSR) Card State Stable Mask */
#define SDMMC_PSR_CARDSS(value)               (SDMMC_PSR_CARDSS_Msk & (_UINT32_(value) << SDMMC_PSR_CARDSS_Pos)) /* Assigment of value for CARDSS in the SDMMC_PSR register */
#define   SDMMC_PSR_CARDSS_NO_Val             _UINT32_(0x0)                                        /* (SDMMC_PSR) Reset or Debouncing  */
#define   SDMMC_PSR_CARDSS_YES_Val            _UINT32_(0x1)                                        /* (SDMMC_PSR) No Card or Insered  */
#define SDMMC_PSR_CARDSS_NO                   (SDMMC_PSR_CARDSS_NO_Val << SDMMC_PSR_CARDSS_Pos)    /* (SDMMC_PSR) Reset or Debouncing Position  */
#define SDMMC_PSR_CARDSS_YES                  (SDMMC_PSR_CARDSS_YES_Val << SDMMC_PSR_CARDSS_Pos)   /* (SDMMC_PSR) No Card or Insered Position  */
#define SDMMC_PSR_CARDDPL_Pos                 _UINT32_(18)                                         /* (SDMMC_PSR) Card Detect Pin Level Position */
#define SDMMC_PSR_CARDDPL_Msk                 (_UINT32_(0x1) << SDMMC_PSR_CARDDPL_Pos)             /* (SDMMC_PSR) Card Detect Pin Level Mask */
#define SDMMC_PSR_CARDDPL(value)              (SDMMC_PSR_CARDDPL_Msk & (_UINT32_(value) << SDMMC_PSR_CARDDPL_Pos)) /* Assigment of value for CARDDPL in the SDMMC_PSR register */
#define   SDMMC_PSR_CARDDPL_NO_Val            _UINT32_(0x0)                                        /* (SDMMC_PSR) No card present (SDCD#=1)  */
#define   SDMMC_PSR_CARDDPL_YES_Val           _UINT32_(0x1)                                        /* (SDMMC_PSR) Card present (SDCD#=0)  */
#define SDMMC_PSR_CARDDPL_NO                  (SDMMC_PSR_CARDDPL_NO_Val << SDMMC_PSR_CARDDPL_Pos)  /* (SDMMC_PSR) No card present (SDCD#=1) Position  */
#define SDMMC_PSR_CARDDPL_YES                 (SDMMC_PSR_CARDDPL_YES_Val << SDMMC_PSR_CARDDPL_Pos) /* (SDMMC_PSR) Card present (SDCD#=0) Position  */
#define SDMMC_PSR_WRPPL_Pos                   _UINT32_(19)                                         /* (SDMMC_PSR) Write Protect Pin Level Position */
#define SDMMC_PSR_WRPPL_Msk                   (_UINT32_(0x1) << SDMMC_PSR_WRPPL_Pos)               /* (SDMMC_PSR) Write Protect Pin Level Mask */
#define SDMMC_PSR_WRPPL(value)                (SDMMC_PSR_WRPPL_Msk & (_UINT32_(value) << SDMMC_PSR_WRPPL_Pos)) /* Assigment of value for WRPPL in the SDMMC_PSR register */
#define   SDMMC_PSR_WRPPL_PROTECTED_Val       _UINT32_(0x0)                                        /* (SDMMC_PSR) Write protected (SDWP#=0)  */
#define   SDMMC_PSR_WRPPL_ENABLED_Val         _UINT32_(0x1)                                        /* (SDMMC_PSR) Write enabled (SDWP#=1)  */
#define SDMMC_PSR_WRPPL_PROTECTED             (SDMMC_PSR_WRPPL_PROTECTED_Val << SDMMC_PSR_WRPPL_Pos) /* (SDMMC_PSR) Write protected (SDWP#=0) Position  */
#define SDMMC_PSR_WRPPL_ENABLED               (SDMMC_PSR_WRPPL_ENABLED_Val << SDMMC_PSR_WRPPL_Pos) /* (SDMMC_PSR) Write enabled (SDWP#=1) Position  */
#define SDMMC_PSR_DATLL_Pos                   _UINT32_(20)                                         /* (SDMMC_PSR) DAT[3:0] Line Level Position */
#define SDMMC_PSR_DATLL_Msk                   (_UINT32_(0xF) << SDMMC_PSR_DATLL_Pos)               /* (SDMMC_PSR) DAT[3:0] Line Level Mask */
#define SDMMC_PSR_DATLL(value)                (SDMMC_PSR_DATLL_Msk & (_UINT32_(value) << SDMMC_PSR_DATLL_Pos)) /* Assigment of value for DATLL in the SDMMC_PSR register */
#define SDMMC_PSR_CMDLL_Pos                   _UINT32_(24)                                         /* (SDMMC_PSR) CMD Line Level Position */
#define SDMMC_PSR_CMDLL_Msk                   (_UINT32_(0x1) << SDMMC_PSR_CMDLL_Pos)               /* (SDMMC_PSR) CMD Line Level Mask */
#define SDMMC_PSR_CMDLL(value)                (SDMMC_PSR_CMDLL_Msk & (_UINT32_(value) << SDMMC_PSR_CMDLL_Pos)) /* Assigment of value for CMDLL in the SDMMC_PSR register */
#define SDMMC_PSR_Msk                         _UINT32_(0x01FF0F0F)                                 /* (SDMMC_PSR) Register Mask  */


/* -------- SDMMC_HC1R : (SDMMC Offset: 0x28) (R/W 8) Host Control 1 -------- */
#define SDMMC_HC1R_RESETVALUE                 _UINT8_(0x00)                                        /*  (SDMMC_HC1R) Host Control 1  Reset Value */

#define SDMMC_HC1R_LEDCTRL_Pos                _UINT8_(0)                                           /* (SDMMC_HC1R) LED Control Position */
#define SDMMC_HC1R_LEDCTRL_Msk                (_UINT8_(0x1) << SDMMC_HC1R_LEDCTRL_Pos)             /* (SDMMC_HC1R) LED Control Mask */
#define SDMMC_HC1R_LEDCTRL(value)             (SDMMC_HC1R_LEDCTRL_Msk & (_UINT8_(value) << SDMMC_HC1R_LEDCTRL_Pos)) /* Assigment of value for LEDCTRL in the SDMMC_HC1R register */
#define   SDMMC_HC1R_LEDCTRL_OFF_Val          _UINT8_(0x0)                                         /* (SDMMC_HC1R) LED off  */
#define   SDMMC_HC1R_LEDCTRL_ON_Val           _UINT8_(0x1)                                         /* (SDMMC_HC1R) LED on  */
#define SDMMC_HC1R_LEDCTRL_OFF                (SDMMC_HC1R_LEDCTRL_OFF_Val << SDMMC_HC1R_LEDCTRL_Pos) /* (SDMMC_HC1R) LED off Position  */
#define SDMMC_HC1R_LEDCTRL_ON                 (SDMMC_HC1R_LEDCTRL_ON_Val << SDMMC_HC1R_LEDCTRL_Pos) /* (SDMMC_HC1R) LED on Position  */
#define SDMMC_HC1R_DW_Pos                     _UINT8_(1)                                           /* (SDMMC_HC1R) Data Width Position */
#define SDMMC_HC1R_DW_Msk                     (_UINT8_(0x1) << SDMMC_HC1R_DW_Pos)                  /* (SDMMC_HC1R) Data Width Mask */
#define SDMMC_HC1R_DW(value)                  (SDMMC_HC1R_DW_Msk & (_UINT8_(value) << SDMMC_HC1R_DW_Pos)) /* Assigment of value for DW in the SDMMC_HC1R register */
#define   SDMMC_HC1R_DW_1BIT_Val              _UINT8_(0x0)                                         /* (SDMMC_HC1R) 1-bit mode  */
#define   SDMMC_HC1R_DW_4BIT_Val              _UINT8_(0x1)                                         /* (SDMMC_HC1R) 4-bit mode  */
#define SDMMC_HC1R_DW_1BIT                    (SDMMC_HC1R_DW_1BIT_Val << SDMMC_HC1R_DW_Pos)        /* (SDMMC_HC1R) 1-bit mode Position  */
#define SDMMC_HC1R_DW_4BIT                    (SDMMC_HC1R_DW_4BIT_Val << SDMMC_HC1R_DW_Pos)        /* (SDMMC_HC1R) 4-bit mode Position  */
#define SDMMC_HC1R_HSEN_Pos                   _UINT8_(2)                                           /* (SDMMC_HC1R) High Speed Enable Position */
#define SDMMC_HC1R_HSEN_Msk                   (_UINT8_(0x1) << SDMMC_HC1R_HSEN_Pos)                /* (SDMMC_HC1R) High Speed Enable Mask */
#define SDMMC_HC1R_HSEN(value)                (SDMMC_HC1R_HSEN_Msk & (_UINT8_(value) << SDMMC_HC1R_HSEN_Pos)) /* Assigment of value for HSEN in the SDMMC_HC1R register */
#define   SDMMC_HC1R_HSEN_NORMAL_Val          _UINT8_(0x0)                                         /* (SDMMC_HC1R) Normal Speed mode  */
#define   SDMMC_HC1R_HSEN_HIGH_Val            _UINT8_(0x1)                                         /* (SDMMC_HC1R) High Speed mode  */
#define SDMMC_HC1R_HSEN_NORMAL                (SDMMC_HC1R_HSEN_NORMAL_Val << SDMMC_HC1R_HSEN_Pos)  /* (SDMMC_HC1R) Normal Speed mode Position  */
#define SDMMC_HC1R_HSEN_HIGH                  (SDMMC_HC1R_HSEN_HIGH_Val << SDMMC_HC1R_HSEN_Pos)    /* (SDMMC_HC1R) High Speed mode Position  */
#define SDMMC_HC1R_DMASEL_Pos                 _UINT8_(3)                                           /* (SDMMC_HC1R) DMA Select Position */
#define SDMMC_HC1R_DMASEL_Msk                 (_UINT8_(0x3) << SDMMC_HC1R_DMASEL_Pos)              /* (SDMMC_HC1R) DMA Select Mask */
#define SDMMC_HC1R_DMASEL(value)              (SDMMC_HC1R_DMASEL_Msk & (_UINT8_(value) << SDMMC_HC1R_DMASEL_Pos)) /* Assigment of value for DMASEL in the SDMMC_HC1R register */
#define   SDMMC_HC1R_DMASEL_SDMA_Val          _UINT8_(0x0)                                         /* (SDMMC_HC1R) SDMA is selected  */
#define   SDMMC_HC1R_DMASEL_32BIT_Val         _UINT8_(0x2)                                         /* (SDMMC_HC1R) 32-bit Address ADMA2 is selected  */
#define SDMMC_HC1R_DMASEL_SDMA                (SDMMC_HC1R_DMASEL_SDMA_Val << SDMMC_HC1R_DMASEL_Pos) /* (SDMMC_HC1R) SDMA is selected Position  */
#define SDMMC_HC1R_DMASEL_32BIT               (SDMMC_HC1R_DMASEL_32BIT_Val << SDMMC_HC1R_DMASEL_Pos) /* (SDMMC_HC1R) 32-bit Address ADMA2 is selected Position  */
#define SDMMC_HC1R_CARDDTL_Pos                _UINT8_(6)                                           /* (SDMMC_HC1R) Card Detect Test Level Position */
#define SDMMC_HC1R_CARDDTL_Msk                (_UINT8_(0x1) << SDMMC_HC1R_CARDDTL_Pos)             /* (SDMMC_HC1R) Card Detect Test Level Mask */
#define SDMMC_HC1R_CARDDTL(value)             (SDMMC_HC1R_CARDDTL_Msk & (_UINT8_(value) << SDMMC_HC1R_CARDDTL_Pos)) /* Assigment of value for CARDDTL in the SDMMC_HC1R register */
#define   SDMMC_HC1R_CARDDTL_NO_Val           _UINT8_(0x0)                                         /* (SDMMC_HC1R) No Card  */
#define   SDMMC_HC1R_CARDDTL_YES_Val          _UINT8_(0x1)                                         /* (SDMMC_HC1R) Card Inserted  */
#define SDMMC_HC1R_CARDDTL_NO                 (SDMMC_HC1R_CARDDTL_NO_Val << SDMMC_HC1R_CARDDTL_Pos) /* (SDMMC_HC1R) No Card Position  */
#define SDMMC_HC1R_CARDDTL_YES                (SDMMC_HC1R_CARDDTL_YES_Val << SDMMC_HC1R_CARDDTL_Pos) /* (SDMMC_HC1R) Card Inserted Position  */
#define SDMMC_HC1R_CARDDSEL_Pos               _UINT8_(7)                                           /* (SDMMC_HC1R) Card Detect Signal Selection Position */
#define SDMMC_HC1R_CARDDSEL_Msk               (_UINT8_(0x1) << SDMMC_HC1R_CARDDSEL_Pos)            /* (SDMMC_HC1R) Card Detect Signal Selection Mask */
#define SDMMC_HC1R_CARDDSEL(value)            (SDMMC_HC1R_CARDDSEL_Msk & (_UINT8_(value) << SDMMC_HC1R_CARDDSEL_Pos)) /* Assigment of value for CARDDSEL in the SDMMC_HC1R register */
#define   SDMMC_HC1R_CARDDSEL_NORMAL_Val      _UINT8_(0x0)                                         /* (SDMMC_HC1R) SDCD# is selected (for normal use)  */
#define   SDMMC_HC1R_CARDDSEL_TEST_Val        _UINT8_(0x1)                                         /* (SDMMC_HC1R) The Card Select Test Level is selected (for test purpose)  */
#define SDMMC_HC1R_CARDDSEL_NORMAL            (SDMMC_HC1R_CARDDSEL_NORMAL_Val << SDMMC_HC1R_CARDDSEL_Pos) /* (SDMMC_HC1R) SDCD# is selected (for normal use) Position  */
#define SDMMC_HC1R_CARDDSEL_TEST              (SDMMC_HC1R_CARDDSEL_TEST_Val << SDMMC_HC1R_CARDDSEL_Pos) /* (SDMMC_HC1R) The Card Select Test Level is selected (for test purpose) Position  */
#define SDMMC_HC1R_Msk                        _UINT8_(0xDF)                                        /* (SDMMC_HC1R) Register Mask  */

/* EMMC mode */
#define SDMMC_HC1R_EMMC_Msk                   _UINT8_(0x00)                                         /* (SDMMC_HC1R_EMMC) Register Mask  */


/* -------- SDMMC_PCR : (SDMMC Offset: 0x29) (R/W 8) Power Control -------- */
#define SDMMC_PCR_RESETVALUE                  _UINT8_(0x0E)                                        /*  (SDMMC_PCR) Power Control  Reset Value */

#define SDMMC_PCR_SDBPWR_Pos                  _UINT8_(0)                                           /* (SDMMC_PCR) SD Bus Power Position */
#define SDMMC_PCR_SDBPWR_Msk                  (_UINT8_(0x1) << SDMMC_PCR_SDBPWR_Pos)               /* (SDMMC_PCR) SD Bus Power Mask */
#define SDMMC_PCR_SDBPWR(value)               (SDMMC_PCR_SDBPWR_Msk & (_UINT8_(value) << SDMMC_PCR_SDBPWR_Pos)) /* Assigment of value for SDBPWR in the SDMMC_PCR register */
#define   SDMMC_PCR_SDBPWR_OFF_Val            _UINT8_(0x0)                                         /* (SDMMC_PCR) Power off  */
#define   SDMMC_PCR_SDBPWR_ON_Val             _UINT8_(0x1)                                         /* (SDMMC_PCR) Power on  */
#define SDMMC_PCR_SDBPWR_OFF                  (SDMMC_PCR_SDBPWR_OFF_Val << SDMMC_PCR_SDBPWR_Pos)   /* (SDMMC_PCR) Power off Position  */
#define SDMMC_PCR_SDBPWR_ON                   (SDMMC_PCR_SDBPWR_ON_Val << SDMMC_PCR_SDBPWR_Pos)    /* (SDMMC_PCR) Power on Position  */
#define SDMMC_PCR_SDBVSEL_Pos                 _UINT8_(1)                                           /* (SDMMC_PCR) SD Bus Voltage Select Position */
#define SDMMC_PCR_SDBVSEL_Msk                 (_UINT8_(0x7) << SDMMC_PCR_SDBVSEL_Pos)              /* (SDMMC_PCR) SD Bus Voltage Select Mask */
#define SDMMC_PCR_SDBVSEL(value)              (SDMMC_PCR_SDBVSEL_Msk & (_UINT8_(value) << SDMMC_PCR_SDBVSEL_Pos)) /* Assigment of value for SDBVSEL in the SDMMC_PCR register */
#define   SDMMC_PCR_SDBVSEL_1V8_Val           _UINT8_(0x5)                                         /* (SDMMC_PCR) 1.8V (Typ.)  */
#define   SDMMC_PCR_SDBVSEL_3V0_Val           _UINT8_(0x6)                                         /* (SDMMC_PCR) 3.0V (Typ.)  */
#define   SDMMC_PCR_SDBVSEL_3V3_Val           _UINT8_(0x7)                                         /* (SDMMC_PCR) 3.3V (Typ.)  */
#define SDMMC_PCR_SDBVSEL_1V8                 (SDMMC_PCR_SDBVSEL_1V8_Val << SDMMC_PCR_SDBVSEL_Pos) /* (SDMMC_PCR) 1.8V (Typ.) Position  */
#define SDMMC_PCR_SDBVSEL_3V0                 (SDMMC_PCR_SDBVSEL_3V0_Val << SDMMC_PCR_SDBVSEL_Pos) /* (SDMMC_PCR) 3.0V (Typ.) Position  */
#define SDMMC_PCR_SDBVSEL_3V3                 (SDMMC_PCR_SDBVSEL_3V3_Val << SDMMC_PCR_SDBVSEL_Pos) /* (SDMMC_PCR) 3.3V (Typ.) Position  */
#define SDMMC_PCR_Msk                         _UINT8_(0x0F)                                        /* (SDMMC_PCR) Register Mask  */


/* -------- SDMMC_BGCR : (SDMMC Offset: 0x2A) (R/W 8) Block Gap Control -------- */
#define SDMMC_BGCR_RESETVALUE                 _UINT8_(0x00)                                        /*  (SDMMC_BGCR) Block Gap Control  Reset Value */

#define SDMMC_BGCR_STPBGR_Pos                 _UINT8_(0)                                           /* (SDMMC_BGCR) Stop at Block Gap Request Position */
#define SDMMC_BGCR_STPBGR_Msk                 (_UINT8_(0x1) << SDMMC_BGCR_STPBGR_Pos)              /* (SDMMC_BGCR) Stop at Block Gap Request Mask */
#define SDMMC_BGCR_STPBGR(value)              (SDMMC_BGCR_STPBGR_Msk & (_UINT8_(value) << SDMMC_BGCR_STPBGR_Pos)) /* Assigment of value for STPBGR in the SDMMC_BGCR register */
#define   SDMMC_BGCR_STPBGR_TRANSFER_Val      _UINT8_(0x0)                                         /* (SDMMC_BGCR) Transfer  */
#define   SDMMC_BGCR_STPBGR_STOP_Val          _UINT8_(0x1)                                         /* (SDMMC_BGCR) Stop  */
#define SDMMC_BGCR_STPBGR_TRANSFER            (SDMMC_BGCR_STPBGR_TRANSFER_Val << SDMMC_BGCR_STPBGR_Pos) /* (SDMMC_BGCR) Transfer Position  */
#define SDMMC_BGCR_STPBGR_STOP                (SDMMC_BGCR_STPBGR_STOP_Val << SDMMC_BGCR_STPBGR_Pos) /* (SDMMC_BGCR) Stop Position  */
#define SDMMC_BGCR_CONTR_Pos                  _UINT8_(1)                                           /* (SDMMC_BGCR) Continue Request Position */
#define SDMMC_BGCR_CONTR_Msk                  (_UINT8_(0x1) << SDMMC_BGCR_CONTR_Pos)               /* (SDMMC_BGCR) Continue Request Mask */
#define SDMMC_BGCR_CONTR(value)               (SDMMC_BGCR_CONTR_Msk & (_UINT8_(value) << SDMMC_BGCR_CONTR_Pos)) /* Assigment of value for CONTR in the SDMMC_BGCR register */
#define   SDMMC_BGCR_CONTR_GO_ON_Val          _UINT8_(0x0)                                         /* (SDMMC_BGCR) Not affected  */
#define   SDMMC_BGCR_CONTR_RESTART_Val        _UINT8_(0x1)                                         /* (SDMMC_BGCR) Restart  */
#define SDMMC_BGCR_CONTR_GO_ON                (SDMMC_BGCR_CONTR_GO_ON_Val << SDMMC_BGCR_CONTR_Pos) /* (SDMMC_BGCR) Not affected Position  */
#define SDMMC_BGCR_CONTR_RESTART              (SDMMC_BGCR_CONTR_RESTART_Val << SDMMC_BGCR_CONTR_Pos) /* (SDMMC_BGCR) Restart Position  */
#define SDMMC_BGCR_RWCTRL_Pos                 _UINT8_(2)                                           /* (SDMMC_BGCR) Read Wait Control Position */
#define SDMMC_BGCR_RWCTRL_Msk                 (_UINT8_(0x1) << SDMMC_BGCR_RWCTRL_Pos)              /* (SDMMC_BGCR) Read Wait Control Mask */
#define SDMMC_BGCR_RWCTRL(value)              (SDMMC_BGCR_RWCTRL_Msk & (_UINT8_(value) << SDMMC_BGCR_RWCTRL_Pos)) /* Assigment of value for RWCTRL in the SDMMC_BGCR register */
#define   SDMMC_BGCR_RWCTRL_DISABLE_Val       _UINT8_(0x0)                                         /* (SDMMC_BGCR) Disable Read Wait Control  */
#define   SDMMC_BGCR_RWCTRL_ENABLE_Val        _UINT8_(0x1)                                         /* (SDMMC_BGCR) Enable Read Wait Control  */
#define SDMMC_BGCR_RWCTRL_DISABLE             (SDMMC_BGCR_RWCTRL_DISABLE_Val << SDMMC_BGCR_RWCTRL_Pos) /* (SDMMC_BGCR) Disable Read Wait Control Position  */
#define SDMMC_BGCR_RWCTRL_ENABLE              (SDMMC_BGCR_RWCTRL_ENABLE_Val << SDMMC_BGCR_RWCTRL_Pos) /* (SDMMC_BGCR) Enable Read Wait Control Position  */
#define SDMMC_BGCR_INTBG_Pos                  _UINT8_(3)                                           /* (SDMMC_BGCR) Interrupt at Block Gap Position */
#define SDMMC_BGCR_INTBG_Msk                  (_UINT8_(0x1) << SDMMC_BGCR_INTBG_Pos)               /* (SDMMC_BGCR) Interrupt at Block Gap Mask */
#define SDMMC_BGCR_INTBG(value)               (SDMMC_BGCR_INTBG_Msk & (_UINT8_(value) << SDMMC_BGCR_INTBG_Pos)) /* Assigment of value for INTBG in the SDMMC_BGCR register */
#define   SDMMC_BGCR_INTBG_DISABLED_Val       _UINT8_(0x0)                                         /* (SDMMC_BGCR) Disabled  */
#define   SDMMC_BGCR_INTBG_ENABLED_Val        _UINT8_(0x1)                                         /* (SDMMC_BGCR) Enabled  */
#define SDMMC_BGCR_INTBG_DISABLED             (SDMMC_BGCR_INTBG_DISABLED_Val << SDMMC_BGCR_INTBG_Pos) /* (SDMMC_BGCR) Disabled Position  */
#define SDMMC_BGCR_INTBG_ENABLED              (SDMMC_BGCR_INTBG_ENABLED_Val << SDMMC_BGCR_INTBG_Pos) /* (SDMMC_BGCR) Enabled Position  */
#define SDMMC_BGCR_Msk                        _UINT8_(0x0F)                                        /* (SDMMC_BGCR) Register Mask  */

/* EMMC mode */
#define SDMMC_BGCR_EMMC_Msk                   _UINT8_(0x00)                                         /* (SDMMC_BGCR_EMMC) Register Mask  */


/* -------- SDMMC_WCR : (SDMMC Offset: 0x2B) (R/W 8) Wakeup Control -------- */
#define SDMMC_WCR_RESETVALUE                  _UINT8_(0x00)                                        /*  (SDMMC_WCR) Wakeup Control  Reset Value */

#define SDMMC_WCR_WKENCINT_Pos                _UINT8_(0)                                           /* (SDMMC_WCR) Wakeup Event Enable on Card Interrupt Position */
#define SDMMC_WCR_WKENCINT_Msk                (_UINT8_(0x1) << SDMMC_WCR_WKENCINT_Pos)             /* (SDMMC_WCR) Wakeup Event Enable on Card Interrupt Mask */
#define SDMMC_WCR_WKENCINT(value)             (SDMMC_WCR_WKENCINT_Msk & (_UINT8_(value) << SDMMC_WCR_WKENCINT_Pos)) /* Assigment of value for WKENCINT in the SDMMC_WCR register */
#define   SDMMC_WCR_WKENCINT_DISABLE_Val      _UINT8_(0x0)                                         /* (SDMMC_WCR) Disable  */
#define   SDMMC_WCR_WKENCINT_ENABLE_Val       _UINT8_(0x1)                                         /* (SDMMC_WCR) Enable  */
#define SDMMC_WCR_WKENCINT_DISABLE            (SDMMC_WCR_WKENCINT_DISABLE_Val << SDMMC_WCR_WKENCINT_Pos) /* (SDMMC_WCR) Disable Position  */
#define SDMMC_WCR_WKENCINT_ENABLE             (SDMMC_WCR_WKENCINT_ENABLE_Val << SDMMC_WCR_WKENCINT_Pos) /* (SDMMC_WCR) Enable Position  */
#define SDMMC_WCR_WKENCINS_Pos                _UINT8_(1)                                           /* (SDMMC_WCR) Wakeup Event Enable on Card Insertion Position */
#define SDMMC_WCR_WKENCINS_Msk                (_UINT8_(0x1) << SDMMC_WCR_WKENCINS_Pos)             /* (SDMMC_WCR) Wakeup Event Enable on Card Insertion Mask */
#define SDMMC_WCR_WKENCINS(value)             (SDMMC_WCR_WKENCINS_Msk & (_UINT8_(value) << SDMMC_WCR_WKENCINS_Pos)) /* Assigment of value for WKENCINS in the SDMMC_WCR register */
#define   SDMMC_WCR_WKENCINS_DISABLE_Val      _UINT8_(0x0)                                         /* (SDMMC_WCR) Disable  */
#define   SDMMC_WCR_WKENCINS_ENABLE_Val       _UINT8_(0x1)                                         /* (SDMMC_WCR) Enable  */
#define SDMMC_WCR_WKENCINS_DISABLE            (SDMMC_WCR_WKENCINS_DISABLE_Val << SDMMC_WCR_WKENCINS_Pos) /* (SDMMC_WCR) Disable Position  */
#define SDMMC_WCR_WKENCINS_ENABLE             (SDMMC_WCR_WKENCINS_ENABLE_Val << SDMMC_WCR_WKENCINS_Pos) /* (SDMMC_WCR) Enable Position  */
#define SDMMC_WCR_WKENCREM_Pos                _UINT8_(2)                                           /* (SDMMC_WCR) Wakeup Event Enable on Card Removal Position */
#define SDMMC_WCR_WKENCREM_Msk                (_UINT8_(0x1) << SDMMC_WCR_WKENCREM_Pos)             /* (SDMMC_WCR) Wakeup Event Enable on Card Removal Mask */
#define SDMMC_WCR_WKENCREM(value)             (SDMMC_WCR_WKENCREM_Msk & (_UINT8_(value) << SDMMC_WCR_WKENCREM_Pos)) /* Assigment of value for WKENCREM in the SDMMC_WCR register */
#define   SDMMC_WCR_WKENCREM_DISABLE_Val      _UINT8_(0x0)                                         /* (SDMMC_WCR) Disable  */
#define   SDMMC_WCR_WKENCREM_ENABLE_Val       _UINT8_(0x1)                                         /* (SDMMC_WCR) Enable  */
#define SDMMC_WCR_WKENCREM_DISABLE            (SDMMC_WCR_WKENCREM_DISABLE_Val << SDMMC_WCR_WKENCREM_Pos) /* (SDMMC_WCR) Disable Position  */
#define SDMMC_WCR_WKENCREM_ENABLE             (SDMMC_WCR_WKENCREM_ENABLE_Val << SDMMC_WCR_WKENCREM_Pos) /* (SDMMC_WCR) Enable Position  */
#define SDMMC_WCR_Msk                         _UINT8_(0x07)                                        /* (SDMMC_WCR) Register Mask  */


/* -------- SDMMC_CCR : (SDMMC Offset: 0x2C) (R/W 16) Clock Control -------- */
#define SDMMC_CCR_RESETVALUE                  _UINT16_(0x00)                                       /*  (SDMMC_CCR) Clock Control  Reset Value */

#define SDMMC_CCR_INTCLKEN_Pos                _UINT16_(0)                                          /* (SDMMC_CCR) Internal Clock Enable Position */
#define SDMMC_CCR_INTCLKEN_Msk                (_UINT16_(0x1) << SDMMC_CCR_INTCLKEN_Pos)            /* (SDMMC_CCR) Internal Clock Enable Mask */
#define SDMMC_CCR_INTCLKEN(value)             (SDMMC_CCR_INTCLKEN_Msk & (_UINT16_(value) << SDMMC_CCR_INTCLKEN_Pos)) /* Assigment of value for INTCLKEN in the SDMMC_CCR register */
#define   SDMMC_CCR_INTCLKEN_OFF_Val          _UINT16_(0x0)                                        /* (SDMMC_CCR) Stop  */
#define   SDMMC_CCR_INTCLKEN_ON_Val           _UINT16_(0x1)                                        /* (SDMMC_CCR) Oscillate  */
#define SDMMC_CCR_INTCLKEN_OFF                (SDMMC_CCR_INTCLKEN_OFF_Val << SDMMC_CCR_INTCLKEN_Pos) /* (SDMMC_CCR) Stop Position  */
#define SDMMC_CCR_INTCLKEN_ON                 (SDMMC_CCR_INTCLKEN_ON_Val << SDMMC_CCR_INTCLKEN_Pos) /* (SDMMC_CCR) Oscillate Position  */
#define SDMMC_CCR_INTCLKS_Pos                 _UINT16_(1)                                          /* (SDMMC_CCR) Internal Clock Stable Position */
#define SDMMC_CCR_INTCLKS_Msk                 (_UINT16_(0x1) << SDMMC_CCR_INTCLKS_Pos)             /* (SDMMC_CCR) Internal Clock Stable Mask */
#define SDMMC_CCR_INTCLKS(value)              (SDMMC_CCR_INTCLKS_Msk & (_UINT16_(value) << SDMMC_CCR_INTCLKS_Pos)) /* Assigment of value for INTCLKS in the SDMMC_CCR register */
#define   SDMMC_CCR_INTCLKS_NOT_READY_Val     _UINT16_(0x0)                                        /* (SDMMC_CCR) Not Ready  */
#define   SDMMC_CCR_INTCLKS_READY_Val         _UINT16_(0x1)                                        /* (SDMMC_CCR) Ready  */
#define SDMMC_CCR_INTCLKS_NOT_READY           (SDMMC_CCR_INTCLKS_NOT_READY_Val << SDMMC_CCR_INTCLKS_Pos) /* (SDMMC_CCR) Not Ready Position  */
#define SDMMC_CCR_INTCLKS_READY               (SDMMC_CCR_INTCLKS_READY_Val << SDMMC_CCR_INTCLKS_Pos) /* (SDMMC_CCR) Ready Position  */
#define SDMMC_CCR_SDCLKEN_Pos                 _UINT16_(2)                                          /* (SDMMC_CCR) SD Clock Enable Position */
#define SDMMC_CCR_SDCLKEN_Msk                 (_UINT16_(0x1) << SDMMC_CCR_SDCLKEN_Pos)             /* (SDMMC_CCR) SD Clock Enable Mask */
#define SDMMC_CCR_SDCLKEN(value)              (SDMMC_CCR_SDCLKEN_Msk & (_UINT16_(value) << SDMMC_CCR_SDCLKEN_Pos)) /* Assigment of value for SDCLKEN in the SDMMC_CCR register */
#define   SDMMC_CCR_SDCLKEN_DISABLE_Val       _UINT16_(0x0)                                        /* (SDMMC_CCR) Disable  */
#define   SDMMC_CCR_SDCLKEN_ENABLE_Val        _UINT16_(0x1)                                        /* (SDMMC_CCR) Enable  */
#define SDMMC_CCR_SDCLKEN_DISABLE             (SDMMC_CCR_SDCLKEN_DISABLE_Val << SDMMC_CCR_SDCLKEN_Pos) /* (SDMMC_CCR) Disable Position  */
#define SDMMC_CCR_SDCLKEN_ENABLE              (SDMMC_CCR_SDCLKEN_ENABLE_Val << SDMMC_CCR_SDCLKEN_Pos) /* (SDMMC_CCR) Enable Position  */
#define SDMMC_CCR_CLKGSEL_Pos                 _UINT16_(5)                                          /* (SDMMC_CCR) Clock Generator Select Position */
#define SDMMC_CCR_CLKGSEL_Msk                 (_UINT16_(0x1) << SDMMC_CCR_CLKGSEL_Pos)             /* (SDMMC_CCR) Clock Generator Select Mask */
#define SDMMC_CCR_CLKGSEL(value)              (SDMMC_CCR_CLKGSEL_Msk & (_UINT16_(value) << SDMMC_CCR_CLKGSEL_Pos)) /* Assigment of value for CLKGSEL in the SDMMC_CCR register */
#define   SDMMC_CCR_CLKGSEL_DIV_Val           _UINT16_(0x0)                                        /* (SDMMC_CCR) Divided Clock Mode  */
#define   SDMMC_CCR_CLKGSEL_PROG_Val          _UINT16_(0x1)                                        /* (SDMMC_CCR) Programmable Clock Mode  */
#define SDMMC_CCR_CLKGSEL_DIV                 (SDMMC_CCR_CLKGSEL_DIV_Val << SDMMC_CCR_CLKGSEL_Pos) /* (SDMMC_CCR) Divided Clock Mode Position  */
#define SDMMC_CCR_CLKGSEL_PROG                (SDMMC_CCR_CLKGSEL_PROG_Val << SDMMC_CCR_CLKGSEL_Pos) /* (SDMMC_CCR) Programmable Clock Mode Position  */
#define SDMMC_CCR_USDCLKFSEL_Pos              _UINT16_(6)                                          /* (SDMMC_CCR) Upper Bits of SDCLK Frequency Select Position */
#define SDMMC_CCR_USDCLKFSEL_Msk              (_UINT16_(0x3) << SDMMC_CCR_USDCLKFSEL_Pos)          /* (SDMMC_CCR) Upper Bits of SDCLK Frequency Select Mask */
#define SDMMC_CCR_USDCLKFSEL(value)           (SDMMC_CCR_USDCLKFSEL_Msk & (_UINT16_(value) << SDMMC_CCR_USDCLKFSEL_Pos)) /* Assigment of value for USDCLKFSEL in the SDMMC_CCR register */
#define SDMMC_CCR_SDCLKFSEL_Pos               _UINT16_(8)                                          /* (SDMMC_CCR) SDCLK Frequency Select Position */
#define SDMMC_CCR_SDCLKFSEL_Msk               (_UINT16_(0xFF) << SDMMC_CCR_SDCLKFSEL_Pos)          /* (SDMMC_CCR) SDCLK Frequency Select Mask */
#define SDMMC_CCR_SDCLKFSEL(value)            (SDMMC_CCR_SDCLKFSEL_Msk & (_UINT16_(value) << SDMMC_CCR_SDCLKFSEL_Pos)) /* Assigment of value for SDCLKFSEL in the SDMMC_CCR register */
#define SDMMC_CCR_Msk                         _UINT16_(0xFFE7)                                     /* (SDMMC_CCR) Register Mask  */


/* -------- SDMMC_TCR : (SDMMC Offset: 0x2E) (R/W 8) Timeout Control -------- */
#define SDMMC_TCR_RESETVALUE                  _UINT8_(0x00)                                        /*  (SDMMC_TCR) Timeout Control  Reset Value */

#define SDMMC_TCR_DTCVAL_Pos                  _UINT8_(0)                                           /* (SDMMC_TCR) Data Timeout Counter Value Position */
#define SDMMC_TCR_DTCVAL_Msk                  (_UINT8_(0xF) << SDMMC_TCR_DTCVAL_Pos)               /* (SDMMC_TCR) Data Timeout Counter Value Mask */
#define SDMMC_TCR_DTCVAL(value)               (SDMMC_TCR_DTCVAL_Msk & (_UINT8_(value) << SDMMC_TCR_DTCVAL_Pos)) /* Assigment of value for DTCVAL in the SDMMC_TCR register */
#define SDMMC_TCR_Msk                         _UINT8_(0x0F)                                        /* (SDMMC_TCR) Register Mask  */


/* -------- SDMMC_SRR : (SDMMC Offset: 0x2F) (R/W 8) Software Reset -------- */
#define SDMMC_SRR_RESETVALUE                  _UINT8_(0x00)                                        /*  (SDMMC_SRR) Software Reset  Reset Value */

#define SDMMC_SRR_SWRSTALL_Pos                _UINT8_(0)                                           /* (SDMMC_SRR) Software Reset For All Position */
#define SDMMC_SRR_SWRSTALL_Msk                (_UINT8_(0x1) << SDMMC_SRR_SWRSTALL_Pos)             /* (SDMMC_SRR) Software Reset For All Mask */
#define SDMMC_SRR_SWRSTALL(value)             (SDMMC_SRR_SWRSTALL_Msk & (_UINT8_(value) << SDMMC_SRR_SWRSTALL_Pos)) /* Assigment of value for SWRSTALL in the SDMMC_SRR register */
#define   SDMMC_SRR_SWRSTALL_WORK_Val         _UINT8_(0x0)                                         /* (SDMMC_SRR) Work  */
#define   SDMMC_SRR_SWRSTALL_RESET_Val        _UINT8_(0x1)                                         /* (SDMMC_SRR) Reset  */
#define SDMMC_SRR_SWRSTALL_WORK               (SDMMC_SRR_SWRSTALL_WORK_Val << SDMMC_SRR_SWRSTALL_Pos) /* (SDMMC_SRR) Work Position  */
#define SDMMC_SRR_SWRSTALL_RESET              (SDMMC_SRR_SWRSTALL_RESET_Val << SDMMC_SRR_SWRSTALL_Pos) /* (SDMMC_SRR) Reset Position  */
#define SDMMC_SRR_SWRSTCMD_Pos                _UINT8_(1)                                           /* (SDMMC_SRR) Software Reset For CMD Line Position */
#define SDMMC_SRR_SWRSTCMD_Msk                (_UINT8_(0x1) << SDMMC_SRR_SWRSTCMD_Pos)             /* (SDMMC_SRR) Software Reset For CMD Line Mask */
#define SDMMC_SRR_SWRSTCMD(value)             (SDMMC_SRR_SWRSTCMD_Msk & (_UINT8_(value) << SDMMC_SRR_SWRSTCMD_Pos)) /* Assigment of value for SWRSTCMD in the SDMMC_SRR register */
#define   SDMMC_SRR_SWRSTCMD_WORK_Val         _UINT8_(0x0)                                         /* (SDMMC_SRR) Work  */
#define   SDMMC_SRR_SWRSTCMD_RESET_Val        _UINT8_(0x1)                                         /* (SDMMC_SRR) Reset  */
#define SDMMC_SRR_SWRSTCMD_WORK               (SDMMC_SRR_SWRSTCMD_WORK_Val << SDMMC_SRR_SWRSTCMD_Pos) /* (SDMMC_SRR) Work Position  */
#define SDMMC_SRR_SWRSTCMD_RESET              (SDMMC_SRR_SWRSTCMD_RESET_Val << SDMMC_SRR_SWRSTCMD_Pos) /* (SDMMC_SRR) Reset Position  */
#define SDMMC_SRR_SWRSTDAT_Pos                _UINT8_(2)                                           /* (SDMMC_SRR) Software Reset For DAT Line Position */
#define SDMMC_SRR_SWRSTDAT_Msk                (_UINT8_(0x1) << SDMMC_SRR_SWRSTDAT_Pos)             /* (SDMMC_SRR) Software Reset For DAT Line Mask */
#define SDMMC_SRR_SWRSTDAT(value)             (SDMMC_SRR_SWRSTDAT_Msk & (_UINT8_(value) << SDMMC_SRR_SWRSTDAT_Pos)) /* Assigment of value for SWRSTDAT in the SDMMC_SRR register */
#define   SDMMC_SRR_SWRSTDAT_WORK_Val         _UINT8_(0x0)                                         /* (SDMMC_SRR) Work  */
#define   SDMMC_SRR_SWRSTDAT_RESET_Val        _UINT8_(0x1)                                         /* (SDMMC_SRR) Reset  */
#define SDMMC_SRR_SWRSTDAT_WORK               (SDMMC_SRR_SWRSTDAT_WORK_Val << SDMMC_SRR_SWRSTDAT_Pos) /* (SDMMC_SRR) Work Position  */
#define SDMMC_SRR_SWRSTDAT_RESET              (SDMMC_SRR_SWRSTDAT_RESET_Val << SDMMC_SRR_SWRSTDAT_Pos) /* (SDMMC_SRR) Reset Position  */
#define SDMMC_SRR_Msk                         _UINT8_(0x07)                                        /* (SDMMC_SRR) Register Mask  */


/* -------- SDMMC_NISTR : (SDMMC Offset: 0x30) (R/W 16) Normal Interrupt Status -------- */
#define SDMMC_NISTR_RESETVALUE                _UINT16_(0x00)                                       /*  (SDMMC_NISTR) Normal Interrupt Status  Reset Value */

#define SDMMC_NISTR_CMDC_Pos                  _UINT16_(0)                                          /* (SDMMC_NISTR) Command Complete Position */
#define SDMMC_NISTR_CMDC_Msk                  (_UINT16_(0x1) << SDMMC_NISTR_CMDC_Pos)              /* (SDMMC_NISTR) Command Complete Mask */
#define SDMMC_NISTR_CMDC(value)               (SDMMC_NISTR_CMDC_Msk & (_UINT16_(value) << SDMMC_NISTR_CMDC_Pos)) /* Assigment of value for CMDC in the SDMMC_NISTR register */
#define   SDMMC_NISTR_CMDC_NO_Val             _UINT16_(0x0)                                        /* (SDMMC_NISTR) No command complete  */
#define   SDMMC_NISTR_CMDC_YES_Val            _UINT16_(0x1)                                        /* (SDMMC_NISTR) Command complete  */
#define SDMMC_NISTR_CMDC_NO                   (SDMMC_NISTR_CMDC_NO_Val << SDMMC_NISTR_CMDC_Pos)    /* (SDMMC_NISTR) No command complete Position  */
#define SDMMC_NISTR_CMDC_YES                  (SDMMC_NISTR_CMDC_YES_Val << SDMMC_NISTR_CMDC_Pos)   /* (SDMMC_NISTR) Command complete Position  */
#define SDMMC_NISTR_TRFC_Pos                  _UINT16_(1)                                          /* (SDMMC_NISTR) Transfer Complete Position */
#define SDMMC_NISTR_TRFC_Msk                  (_UINT16_(0x1) << SDMMC_NISTR_TRFC_Pos)              /* (SDMMC_NISTR) Transfer Complete Mask */
#define SDMMC_NISTR_TRFC(value)               (SDMMC_NISTR_TRFC_Msk & (_UINT16_(value) << SDMMC_NISTR_TRFC_Pos)) /* Assigment of value for TRFC in the SDMMC_NISTR register */
#define   SDMMC_NISTR_TRFC_NO_Val             _UINT16_(0x0)                                        /* (SDMMC_NISTR) Not complete  */
#define   SDMMC_NISTR_TRFC_YES_Val            _UINT16_(0x1)                                        /* (SDMMC_NISTR) Command execution is completed  */
#define SDMMC_NISTR_TRFC_NO                   (SDMMC_NISTR_TRFC_NO_Val << SDMMC_NISTR_TRFC_Pos)    /* (SDMMC_NISTR) Not complete Position  */
#define SDMMC_NISTR_TRFC_YES                  (SDMMC_NISTR_TRFC_YES_Val << SDMMC_NISTR_TRFC_Pos)   /* (SDMMC_NISTR) Command execution is completed Position  */
#define SDMMC_NISTR_BLKGE_Pos                 _UINT16_(2)                                          /* (SDMMC_NISTR) Block Gap Event Position */
#define SDMMC_NISTR_BLKGE_Msk                 (_UINT16_(0x1) << SDMMC_NISTR_BLKGE_Pos)             /* (SDMMC_NISTR) Block Gap Event Mask */
#define SDMMC_NISTR_BLKGE(value)              (SDMMC_NISTR_BLKGE_Msk & (_UINT16_(value) << SDMMC_NISTR_BLKGE_Pos)) /* Assigment of value for BLKGE in the SDMMC_NISTR register */
#define   SDMMC_NISTR_BLKGE_NO_Val            _UINT16_(0x0)                                        /* (SDMMC_NISTR) No Block Gap Event  */
#define   SDMMC_NISTR_BLKGE_STOP_Val          _UINT16_(0x1)                                        /* (SDMMC_NISTR) Transaction stopped at block gap  */
#define SDMMC_NISTR_BLKGE_NO                  (SDMMC_NISTR_BLKGE_NO_Val << SDMMC_NISTR_BLKGE_Pos)  /* (SDMMC_NISTR) No Block Gap Event Position  */
#define SDMMC_NISTR_BLKGE_STOP                (SDMMC_NISTR_BLKGE_STOP_Val << SDMMC_NISTR_BLKGE_Pos) /* (SDMMC_NISTR) Transaction stopped at block gap Position  */
#define SDMMC_NISTR_DMAINT_Pos                _UINT16_(3)                                          /* (SDMMC_NISTR) DMA Interrupt Position */
#define SDMMC_NISTR_DMAINT_Msk                (_UINT16_(0x1) << SDMMC_NISTR_DMAINT_Pos)            /* (SDMMC_NISTR) DMA Interrupt Mask */
#define SDMMC_NISTR_DMAINT(value)             (SDMMC_NISTR_DMAINT_Msk & (_UINT16_(value) << SDMMC_NISTR_DMAINT_Pos)) /* Assigment of value for DMAINT in the SDMMC_NISTR register */
#define   SDMMC_NISTR_DMAINT_NO_Val           _UINT16_(0x0)                                        /* (SDMMC_NISTR) No DMA Interrupt  */
#define   SDMMC_NISTR_DMAINT_YES_Val          _UINT16_(0x1)                                        /* (SDMMC_NISTR) DMA Interrupt is generated  */
#define SDMMC_NISTR_DMAINT_NO                 (SDMMC_NISTR_DMAINT_NO_Val << SDMMC_NISTR_DMAINT_Pos) /* (SDMMC_NISTR) No DMA Interrupt Position  */
#define SDMMC_NISTR_DMAINT_YES                (SDMMC_NISTR_DMAINT_YES_Val << SDMMC_NISTR_DMAINT_Pos) /* (SDMMC_NISTR) DMA Interrupt is generated Position  */
#define SDMMC_NISTR_BWRRDY_Pos                _UINT16_(4)                                          /* (SDMMC_NISTR) Buffer Write Ready Position */
#define SDMMC_NISTR_BWRRDY_Msk                (_UINT16_(0x1) << SDMMC_NISTR_BWRRDY_Pos)            /* (SDMMC_NISTR) Buffer Write Ready Mask */
#define SDMMC_NISTR_BWRRDY(value)             (SDMMC_NISTR_BWRRDY_Msk & (_UINT16_(value) << SDMMC_NISTR_BWRRDY_Pos)) /* Assigment of value for BWRRDY in the SDMMC_NISTR register */
#define   SDMMC_NISTR_BWRRDY_NO_Val           _UINT16_(0x0)                                        /* (SDMMC_NISTR) Not ready to write buffer  */
#define   SDMMC_NISTR_BWRRDY_YES_Val          _UINT16_(0x1)                                        /* (SDMMC_NISTR) Ready to write buffer  */
#define SDMMC_NISTR_BWRRDY_NO                 (SDMMC_NISTR_BWRRDY_NO_Val << SDMMC_NISTR_BWRRDY_Pos) /* (SDMMC_NISTR) Not ready to write buffer Position  */
#define SDMMC_NISTR_BWRRDY_YES                (SDMMC_NISTR_BWRRDY_YES_Val << SDMMC_NISTR_BWRRDY_Pos) /* (SDMMC_NISTR) Ready to write buffer Position  */
#define SDMMC_NISTR_BRDRDY_Pos                _UINT16_(5)                                          /* (SDMMC_NISTR) Buffer Read Ready Position */
#define SDMMC_NISTR_BRDRDY_Msk                (_UINT16_(0x1) << SDMMC_NISTR_BRDRDY_Pos)            /* (SDMMC_NISTR) Buffer Read Ready Mask */
#define SDMMC_NISTR_BRDRDY(value)             (SDMMC_NISTR_BRDRDY_Msk & (_UINT16_(value) << SDMMC_NISTR_BRDRDY_Pos)) /* Assigment of value for BRDRDY in the SDMMC_NISTR register */
#define   SDMMC_NISTR_BRDRDY_NO_Val           _UINT16_(0x0)                                        /* (SDMMC_NISTR) Not ready to read buffer  */
#define   SDMMC_NISTR_BRDRDY_YES_Val          _UINT16_(0x1)                                        /* (SDMMC_NISTR) Ready to read buffer  */
#define SDMMC_NISTR_BRDRDY_NO                 (SDMMC_NISTR_BRDRDY_NO_Val << SDMMC_NISTR_BRDRDY_Pos) /* (SDMMC_NISTR) Not ready to read buffer Position  */
#define SDMMC_NISTR_BRDRDY_YES                (SDMMC_NISTR_BRDRDY_YES_Val << SDMMC_NISTR_BRDRDY_Pos) /* (SDMMC_NISTR) Ready to read buffer Position  */
#define SDMMC_NISTR_CINS_Pos                  _UINT16_(6)                                          /* (SDMMC_NISTR) Card Insertion Position */
#define SDMMC_NISTR_CINS_Msk                  (_UINT16_(0x1) << SDMMC_NISTR_CINS_Pos)              /* (SDMMC_NISTR) Card Insertion Mask */
#define SDMMC_NISTR_CINS(value)               (SDMMC_NISTR_CINS_Msk & (_UINT16_(value) << SDMMC_NISTR_CINS_Pos)) /* Assigment of value for CINS in the SDMMC_NISTR register */
#define   SDMMC_NISTR_CINS_NO_Val             _UINT16_(0x0)                                        /* (SDMMC_NISTR) Card state stable or Debouncing  */
#define   SDMMC_NISTR_CINS_YES_Val            _UINT16_(0x1)                                        /* (SDMMC_NISTR) Card inserted  */
#define SDMMC_NISTR_CINS_NO                   (SDMMC_NISTR_CINS_NO_Val << SDMMC_NISTR_CINS_Pos)    /* (SDMMC_NISTR) Card state stable or Debouncing Position  */
#define SDMMC_NISTR_CINS_YES                  (SDMMC_NISTR_CINS_YES_Val << SDMMC_NISTR_CINS_Pos)   /* (SDMMC_NISTR) Card inserted Position  */
#define SDMMC_NISTR_CREM_Pos                  _UINT16_(7)                                          /* (SDMMC_NISTR) Card Removal Position */
#define SDMMC_NISTR_CREM_Msk                  (_UINT16_(0x1) << SDMMC_NISTR_CREM_Pos)              /* (SDMMC_NISTR) Card Removal Mask */
#define SDMMC_NISTR_CREM(value)               (SDMMC_NISTR_CREM_Msk & (_UINT16_(value) << SDMMC_NISTR_CREM_Pos)) /* Assigment of value for CREM in the SDMMC_NISTR register */
#define   SDMMC_NISTR_CREM_NO_Val             _UINT16_(0x0)                                        /* (SDMMC_NISTR) Card state stable or Debouncing  */
#define   SDMMC_NISTR_CREM_YES_Val            _UINT16_(0x1)                                        /* (SDMMC_NISTR) Card Removed  */
#define SDMMC_NISTR_CREM_NO                   (SDMMC_NISTR_CREM_NO_Val << SDMMC_NISTR_CREM_Pos)    /* (SDMMC_NISTR) Card state stable or Debouncing Position  */
#define SDMMC_NISTR_CREM_YES                  (SDMMC_NISTR_CREM_YES_Val << SDMMC_NISTR_CREM_Pos)   /* (SDMMC_NISTR) Card Removed Position  */
#define SDMMC_NISTR_CINT_Pos                  _UINT16_(8)                                          /* (SDMMC_NISTR) Card Interrupt Position */
#define SDMMC_NISTR_CINT_Msk                  (_UINT16_(0x1) << SDMMC_NISTR_CINT_Pos)              /* (SDMMC_NISTR) Card Interrupt Mask */
#define SDMMC_NISTR_CINT(value)               (SDMMC_NISTR_CINT_Msk & (_UINT16_(value) << SDMMC_NISTR_CINT_Pos)) /* Assigment of value for CINT in the SDMMC_NISTR register */
#define   SDMMC_NISTR_CINT_NO_Val             _UINT16_(0x0)                                        /* (SDMMC_NISTR) No Card Interrupt  */
#define   SDMMC_NISTR_CINT_YES_Val            _UINT16_(0x1)                                        /* (SDMMC_NISTR) Generate Card Interrupt  */
#define SDMMC_NISTR_CINT_NO                   (SDMMC_NISTR_CINT_NO_Val << SDMMC_NISTR_CINT_Pos)    /* (SDMMC_NISTR) No Card Interrupt Position  */
#define SDMMC_NISTR_CINT_YES                  (SDMMC_NISTR_CINT_YES_Val << SDMMC_NISTR_CINT_Pos)   /* (SDMMC_NISTR) Generate Card Interrupt Position  */
#define SDMMC_NISTR_ERRINT_Pos                _UINT16_(15)                                         /* (SDMMC_NISTR) Error Interrupt Position */
#define SDMMC_NISTR_ERRINT_Msk                (_UINT16_(0x1) << SDMMC_NISTR_ERRINT_Pos)            /* (SDMMC_NISTR) Error Interrupt Mask */
#define SDMMC_NISTR_ERRINT(value)             (SDMMC_NISTR_ERRINT_Msk & (_UINT16_(value) << SDMMC_NISTR_ERRINT_Pos)) /* Assigment of value for ERRINT in the SDMMC_NISTR register */
#define   SDMMC_NISTR_ERRINT_NO_Val           _UINT16_(0x0)                                        /* (SDMMC_NISTR) No Error  */
#define   SDMMC_NISTR_ERRINT_YES_Val          _UINT16_(0x1)                                        /* (SDMMC_NISTR) Error  */
#define SDMMC_NISTR_ERRINT_NO                 (SDMMC_NISTR_ERRINT_NO_Val << SDMMC_NISTR_ERRINT_Pos) /* (SDMMC_NISTR) No Error Position  */
#define SDMMC_NISTR_ERRINT_YES                (SDMMC_NISTR_ERRINT_YES_Val << SDMMC_NISTR_ERRINT_Pos) /* (SDMMC_NISTR) Error Position  */
#define SDMMC_NISTR_Msk                       _UINT16_(0x81FF)                                     /* (SDMMC_NISTR) Register Mask  */

/* EMMC mode */
#define SDMMC_NISTR_EMMC_BOOTAR_Pos           _UINT16_(14)                                         /* (SDMMC_NISTR) Boot Acknowledge Received Position */
#define SDMMC_NISTR_EMMC_BOOTAR_Msk           (_UINT16_(0x1) << SDMMC_NISTR_EMMC_BOOTAR_Pos)       /* (SDMMC_NISTR) Boot Acknowledge Received Mask */
#define SDMMC_NISTR_EMMC_BOOTAR(value)        (SDMMC_NISTR_EMMC_BOOTAR_Msk & (_UINT16_(value) << SDMMC_NISTR_EMMC_BOOTAR_Pos))
#define SDMMC_NISTR_EMMC_Msk                  _UINT16_(0x4000)                                      /* (SDMMC_NISTR_EMMC) Register Mask  */


/* -------- SDMMC_EISTR : (SDMMC Offset: 0x32) (R/W 16) Error Interrupt Status -------- */
#define SDMMC_EISTR_RESETVALUE                _UINT16_(0x00)                                       /*  (SDMMC_EISTR) Error Interrupt Status  Reset Value */

#define SDMMC_EISTR_CMDTEO_Pos                _UINT16_(0)                                          /* (SDMMC_EISTR) Command Timeout Error Position */
#define SDMMC_EISTR_CMDTEO_Msk                (_UINT16_(0x1) << SDMMC_EISTR_CMDTEO_Pos)            /* (SDMMC_EISTR) Command Timeout Error Mask */
#define SDMMC_EISTR_CMDTEO(value)             (SDMMC_EISTR_CMDTEO_Msk & (_UINT16_(value) << SDMMC_EISTR_CMDTEO_Pos)) /* Assigment of value for CMDTEO in the SDMMC_EISTR register */
#define   SDMMC_EISTR_CMDTEO_NO_Val           _UINT16_(0x0)                                        /* (SDMMC_EISTR) No Error  */
#define   SDMMC_EISTR_CMDTEO_YES_Val          _UINT16_(0x1)                                        /* (SDMMC_EISTR) Timeout  */
#define SDMMC_EISTR_CMDTEO_NO                 (SDMMC_EISTR_CMDTEO_NO_Val << SDMMC_EISTR_CMDTEO_Pos) /* (SDMMC_EISTR) No Error Position  */
#define SDMMC_EISTR_CMDTEO_YES                (SDMMC_EISTR_CMDTEO_YES_Val << SDMMC_EISTR_CMDTEO_Pos) /* (SDMMC_EISTR) Timeout Position  */
#define SDMMC_EISTR_CMDCRC_Pos                _UINT16_(1)                                          /* (SDMMC_EISTR) Command CRC Error Position */
#define SDMMC_EISTR_CMDCRC_Msk                (_UINT16_(0x1) << SDMMC_EISTR_CMDCRC_Pos)            /* (SDMMC_EISTR) Command CRC Error Mask */
#define SDMMC_EISTR_CMDCRC(value)             (SDMMC_EISTR_CMDCRC_Msk & (_UINT16_(value) << SDMMC_EISTR_CMDCRC_Pos)) /* Assigment of value for CMDCRC in the SDMMC_EISTR register */
#define   SDMMC_EISTR_CMDCRC_NO_Val           _UINT16_(0x0)                                        /* (SDMMC_EISTR) No Error  */
#define   SDMMC_EISTR_CMDCRC_YES_Val          _UINT16_(0x1)                                        /* (SDMMC_EISTR) CRC Error Generated  */
#define SDMMC_EISTR_CMDCRC_NO                 (SDMMC_EISTR_CMDCRC_NO_Val << SDMMC_EISTR_CMDCRC_Pos) /* (SDMMC_EISTR) No Error Position  */
#define SDMMC_EISTR_CMDCRC_YES                (SDMMC_EISTR_CMDCRC_YES_Val << SDMMC_EISTR_CMDCRC_Pos) /* (SDMMC_EISTR) CRC Error Generated Position  */
#define SDMMC_EISTR_CMDEND_Pos                _UINT16_(2)                                          /* (SDMMC_EISTR) Command End Bit Error Position */
#define SDMMC_EISTR_CMDEND_Msk                (_UINT16_(0x1) << SDMMC_EISTR_CMDEND_Pos)            /* (SDMMC_EISTR) Command End Bit Error Mask */
#define SDMMC_EISTR_CMDEND(value)             (SDMMC_EISTR_CMDEND_Msk & (_UINT16_(value) << SDMMC_EISTR_CMDEND_Pos)) /* Assigment of value for CMDEND in the SDMMC_EISTR register */
#define   SDMMC_EISTR_CMDEND_NO_Val           _UINT16_(0x0)                                        /* (SDMMC_EISTR) No error  */
#define   SDMMC_EISTR_CMDEND_YES_Val          _UINT16_(0x1)                                        /* (SDMMC_EISTR) End Bit Error Generated  */
#define SDMMC_EISTR_CMDEND_NO                 (SDMMC_EISTR_CMDEND_NO_Val << SDMMC_EISTR_CMDEND_Pos) /* (SDMMC_EISTR) No error Position  */
#define SDMMC_EISTR_CMDEND_YES                (SDMMC_EISTR_CMDEND_YES_Val << SDMMC_EISTR_CMDEND_Pos) /* (SDMMC_EISTR) End Bit Error Generated Position  */
#define SDMMC_EISTR_CMDIDX_Pos                _UINT16_(3)                                          /* (SDMMC_EISTR) Command Index Error Position */
#define SDMMC_EISTR_CMDIDX_Msk                (_UINT16_(0x1) << SDMMC_EISTR_CMDIDX_Pos)            /* (SDMMC_EISTR) Command Index Error Mask */
#define SDMMC_EISTR_CMDIDX(value)             (SDMMC_EISTR_CMDIDX_Msk & (_UINT16_(value) << SDMMC_EISTR_CMDIDX_Pos)) /* Assigment of value for CMDIDX in the SDMMC_EISTR register */
#define   SDMMC_EISTR_CMDIDX_NO_Val           _UINT16_(0x0)                                        /* (SDMMC_EISTR) No Error  */
#define   SDMMC_EISTR_CMDIDX_YES_Val          _UINT16_(0x1)                                        /* (SDMMC_EISTR) Error  */
#define SDMMC_EISTR_CMDIDX_NO                 (SDMMC_EISTR_CMDIDX_NO_Val << SDMMC_EISTR_CMDIDX_Pos) /* (SDMMC_EISTR) No Error Position  */
#define SDMMC_EISTR_CMDIDX_YES                (SDMMC_EISTR_CMDIDX_YES_Val << SDMMC_EISTR_CMDIDX_Pos) /* (SDMMC_EISTR) Error Position  */
#define SDMMC_EISTR_DATTEO_Pos                _UINT16_(4)                                          /* (SDMMC_EISTR) Data Timeout Error Position */
#define SDMMC_EISTR_DATTEO_Msk                (_UINT16_(0x1) << SDMMC_EISTR_DATTEO_Pos)            /* (SDMMC_EISTR) Data Timeout Error Mask */
#define SDMMC_EISTR_DATTEO(value)             (SDMMC_EISTR_DATTEO_Msk & (_UINT16_(value) << SDMMC_EISTR_DATTEO_Pos)) /* Assigment of value for DATTEO in the SDMMC_EISTR register */
#define   SDMMC_EISTR_DATTEO_NO_Val           _UINT16_(0x0)                                        /* (SDMMC_EISTR) No Error  */
#define   SDMMC_EISTR_DATTEO_YES_Val          _UINT16_(0x1)                                        /* (SDMMC_EISTR) Timeout  */
#define SDMMC_EISTR_DATTEO_NO                 (SDMMC_EISTR_DATTEO_NO_Val << SDMMC_EISTR_DATTEO_Pos) /* (SDMMC_EISTR) No Error Position  */
#define SDMMC_EISTR_DATTEO_YES                (SDMMC_EISTR_DATTEO_YES_Val << SDMMC_EISTR_DATTEO_Pos) /* (SDMMC_EISTR) Timeout Position  */
#define SDMMC_EISTR_DATCRC_Pos                _UINT16_(5)                                          /* (SDMMC_EISTR) Data CRC Error Position */
#define SDMMC_EISTR_DATCRC_Msk                (_UINT16_(0x1) << SDMMC_EISTR_DATCRC_Pos)            /* (SDMMC_EISTR) Data CRC Error Mask */
#define SDMMC_EISTR_DATCRC(value)             (SDMMC_EISTR_DATCRC_Msk & (_UINT16_(value) << SDMMC_EISTR_DATCRC_Pos)) /* Assigment of value for DATCRC in the SDMMC_EISTR register */
#define   SDMMC_EISTR_DATCRC_NO_Val           _UINT16_(0x0)                                        /* (SDMMC_EISTR) No Error  */
#define   SDMMC_EISTR_DATCRC_YES_Val          _UINT16_(0x1)                                        /* (SDMMC_EISTR) Error  */
#define SDMMC_EISTR_DATCRC_NO                 (SDMMC_EISTR_DATCRC_NO_Val << SDMMC_EISTR_DATCRC_Pos) /* (SDMMC_EISTR) No Error Position  */
#define SDMMC_EISTR_DATCRC_YES                (SDMMC_EISTR_DATCRC_YES_Val << SDMMC_EISTR_DATCRC_Pos) /* (SDMMC_EISTR) Error Position  */
#define SDMMC_EISTR_DATEND_Pos                _UINT16_(6)                                          /* (SDMMC_EISTR) Data End Bit Error Position */
#define SDMMC_EISTR_DATEND_Msk                (_UINT16_(0x1) << SDMMC_EISTR_DATEND_Pos)            /* (SDMMC_EISTR) Data End Bit Error Mask */
#define SDMMC_EISTR_DATEND(value)             (SDMMC_EISTR_DATEND_Msk & (_UINT16_(value) << SDMMC_EISTR_DATEND_Pos)) /* Assigment of value for DATEND in the SDMMC_EISTR register */
#define   SDMMC_EISTR_DATEND_NO_Val           _UINT16_(0x0)                                        /* (SDMMC_EISTR) No Error  */
#define   SDMMC_EISTR_DATEND_YES_Val          _UINT16_(0x1)                                        /* (SDMMC_EISTR) Error  */
#define SDMMC_EISTR_DATEND_NO                 (SDMMC_EISTR_DATEND_NO_Val << SDMMC_EISTR_DATEND_Pos) /* (SDMMC_EISTR) No Error Position  */
#define SDMMC_EISTR_DATEND_YES                (SDMMC_EISTR_DATEND_YES_Val << SDMMC_EISTR_DATEND_Pos) /* (SDMMC_EISTR) Error Position  */
#define SDMMC_EISTR_CURLIM_Pos                _UINT16_(7)                                          /* (SDMMC_EISTR) Current Limit Error Position */
#define SDMMC_EISTR_CURLIM_Msk                (_UINT16_(0x1) << SDMMC_EISTR_CURLIM_Pos)            /* (SDMMC_EISTR) Current Limit Error Mask */
#define SDMMC_EISTR_CURLIM(value)             (SDMMC_EISTR_CURLIM_Msk & (_UINT16_(value) << SDMMC_EISTR_CURLIM_Pos)) /* Assigment of value for CURLIM in the SDMMC_EISTR register */
#define   SDMMC_EISTR_CURLIM_NO_Val           _UINT16_(0x0)                                        /* (SDMMC_EISTR) No Error  */
#define   SDMMC_EISTR_CURLIM_YES_Val          _UINT16_(0x1)                                        /* (SDMMC_EISTR) Power Fail  */
#define SDMMC_EISTR_CURLIM_NO                 (SDMMC_EISTR_CURLIM_NO_Val << SDMMC_EISTR_CURLIM_Pos) /* (SDMMC_EISTR) No Error Position  */
#define SDMMC_EISTR_CURLIM_YES                (SDMMC_EISTR_CURLIM_YES_Val << SDMMC_EISTR_CURLIM_Pos) /* (SDMMC_EISTR) Power Fail Position  */
#define SDMMC_EISTR_ACMD_Pos                  _UINT16_(8)                                          /* (SDMMC_EISTR) Auto CMD Error Position */
#define SDMMC_EISTR_ACMD_Msk                  (_UINT16_(0x1) << SDMMC_EISTR_ACMD_Pos)              /* (SDMMC_EISTR) Auto CMD Error Mask */
#define SDMMC_EISTR_ACMD(value)               (SDMMC_EISTR_ACMD_Msk & (_UINT16_(value) << SDMMC_EISTR_ACMD_Pos)) /* Assigment of value for ACMD in the SDMMC_EISTR register */
#define   SDMMC_EISTR_ACMD_NO_Val             _UINT16_(0x0)                                        /* (SDMMC_EISTR) No Error  */
#define   SDMMC_EISTR_ACMD_YES_Val            _UINT16_(0x1)                                        /* (SDMMC_EISTR) Error  */
#define SDMMC_EISTR_ACMD_NO                   (SDMMC_EISTR_ACMD_NO_Val << SDMMC_EISTR_ACMD_Pos)    /* (SDMMC_EISTR) No Error Position  */
#define SDMMC_EISTR_ACMD_YES                  (SDMMC_EISTR_ACMD_YES_Val << SDMMC_EISTR_ACMD_Pos)   /* (SDMMC_EISTR) Error Position  */
#define SDMMC_EISTR_ADMA_Pos                  _UINT16_(9)                                          /* (SDMMC_EISTR) ADMA Error Position */
#define SDMMC_EISTR_ADMA_Msk                  (_UINT16_(0x1) << SDMMC_EISTR_ADMA_Pos)              /* (SDMMC_EISTR) ADMA Error Mask */
#define SDMMC_EISTR_ADMA(value)               (SDMMC_EISTR_ADMA_Msk & (_UINT16_(value) << SDMMC_EISTR_ADMA_Pos)) /* Assigment of value for ADMA in the SDMMC_EISTR register */
#define   SDMMC_EISTR_ADMA_NO_Val             _UINT16_(0x0)                                        /* (SDMMC_EISTR) No Error  */
#define   SDMMC_EISTR_ADMA_YES_Val            _UINT16_(0x1)                                        /* (SDMMC_EISTR) Error  */
#define SDMMC_EISTR_ADMA_NO                   (SDMMC_EISTR_ADMA_NO_Val << SDMMC_EISTR_ADMA_Pos)    /* (SDMMC_EISTR) No Error Position  */
#define SDMMC_EISTR_ADMA_YES                  (SDMMC_EISTR_ADMA_YES_Val << SDMMC_EISTR_ADMA_Pos)   /* (SDMMC_EISTR) Error Position  */
#define SDMMC_EISTR_Msk                       _UINT16_(0x03FF)                                     /* (SDMMC_EISTR) Register Mask  */

/* EMMC mode */
#define SDMMC_EISTR_EMMC_BOOTAE_Pos           _UINT16_(12)                                         /* (SDMMC_EISTR) Boot Acknowledge Error Position */
#define SDMMC_EISTR_EMMC_BOOTAE_Msk           (_UINT16_(0x1) << SDMMC_EISTR_EMMC_BOOTAE_Pos)       /* (SDMMC_EISTR) Boot Acknowledge Error Mask */
#define SDMMC_EISTR_EMMC_BOOTAE(value)        (SDMMC_EISTR_EMMC_BOOTAE_Msk & (_UINT16_(value) << SDMMC_EISTR_EMMC_BOOTAE_Pos))
#define   SDMMC_EISTR_EMMC_BOOTAE_0_Val       _UINT16_(0x0)                                        /* (SDMMC_EISTR) FIFO contains at least one byte  */
#define   SDMMC_EISTR_EMMC_BOOTAE_1_Val       _UINT16_(0x1)                                        /* (SDMMC_EISTR) FIFO is empty  */
#define SDMMC_EISTR_EMMC_BOOTAE_0             (SDMMC_EISTR_EMMC_BOOTAE_0_Val << SDMMC_EISTR_EMMC_BOOTAE_Pos) /* (SDMMC_EISTR) FIFO contains at least one byte Position  */
#define SDMMC_EISTR_EMMC_BOOTAE_1             (SDMMC_EISTR_EMMC_BOOTAE_1_Val << SDMMC_EISTR_EMMC_BOOTAE_Pos) /* (SDMMC_EISTR) FIFO is empty Position  */
#define SDMMC_EISTR_EMMC_Msk                  _UINT16_(0x1000)                                      /* (SDMMC_EISTR_EMMC) Register Mask  */


/* -------- SDMMC_NISTER : (SDMMC Offset: 0x34) (R/W 16) Normal Interrupt Status Enable -------- */
#define SDMMC_NISTER_RESETVALUE               _UINT16_(0x00)                                       /*  (SDMMC_NISTER) Normal Interrupt Status Enable  Reset Value */

#define SDMMC_NISTER_CMDC_Pos                 _UINT16_(0)                                          /* (SDMMC_NISTER) Command Complete Status Enable Position */
#define SDMMC_NISTER_CMDC_Msk                 (_UINT16_(0x1) << SDMMC_NISTER_CMDC_Pos)             /* (SDMMC_NISTER) Command Complete Status Enable Mask */
#define SDMMC_NISTER_CMDC(value)              (SDMMC_NISTER_CMDC_Msk & (_UINT16_(value) << SDMMC_NISTER_CMDC_Pos)) /* Assigment of value for CMDC in the SDMMC_NISTER register */
#define   SDMMC_NISTER_CMDC_MASKED_Val        _UINT16_(0x0)                                        /* (SDMMC_NISTER) Masked  */
#define   SDMMC_NISTER_CMDC_ENABLED_Val       _UINT16_(0x1)                                        /* (SDMMC_NISTER) Enabled  */
#define SDMMC_NISTER_CMDC_MASKED              (SDMMC_NISTER_CMDC_MASKED_Val << SDMMC_NISTER_CMDC_Pos) /* (SDMMC_NISTER) Masked Position  */
#define SDMMC_NISTER_CMDC_ENABLED             (SDMMC_NISTER_CMDC_ENABLED_Val << SDMMC_NISTER_CMDC_Pos) /* (SDMMC_NISTER) Enabled Position  */
#define SDMMC_NISTER_TRFC_Pos                 _UINT16_(1)                                          /* (SDMMC_NISTER) Transfer Complete Status Enable Position */
#define SDMMC_NISTER_TRFC_Msk                 (_UINT16_(0x1) << SDMMC_NISTER_TRFC_Pos)             /* (SDMMC_NISTER) Transfer Complete Status Enable Mask */
#define SDMMC_NISTER_TRFC(value)              (SDMMC_NISTER_TRFC_Msk & (_UINT16_(value) << SDMMC_NISTER_TRFC_Pos)) /* Assigment of value for TRFC in the SDMMC_NISTER register */
#define   SDMMC_NISTER_TRFC_MASKED_Val        _UINT16_(0x0)                                        /* (SDMMC_NISTER) Masked  */
#define   SDMMC_NISTER_TRFC_ENABLED_Val       _UINT16_(0x1)                                        /* (SDMMC_NISTER) Enabled  */
#define SDMMC_NISTER_TRFC_MASKED              (SDMMC_NISTER_TRFC_MASKED_Val << SDMMC_NISTER_TRFC_Pos) /* (SDMMC_NISTER) Masked Position  */
#define SDMMC_NISTER_TRFC_ENABLED             (SDMMC_NISTER_TRFC_ENABLED_Val << SDMMC_NISTER_TRFC_Pos) /* (SDMMC_NISTER) Enabled Position  */
#define SDMMC_NISTER_BLKGE_Pos                _UINT16_(2)                                          /* (SDMMC_NISTER) Block Gap Event Status Enable Position */
#define SDMMC_NISTER_BLKGE_Msk                (_UINT16_(0x1) << SDMMC_NISTER_BLKGE_Pos)            /* (SDMMC_NISTER) Block Gap Event Status Enable Mask */
#define SDMMC_NISTER_BLKGE(value)             (SDMMC_NISTER_BLKGE_Msk & (_UINT16_(value) << SDMMC_NISTER_BLKGE_Pos)) /* Assigment of value for BLKGE in the SDMMC_NISTER register */
#define   SDMMC_NISTER_BLKGE_MASKED_Val       _UINT16_(0x0)                                        /* (SDMMC_NISTER) Masked  */
#define   SDMMC_NISTER_BLKGE_ENABLED_Val      _UINT16_(0x1)                                        /* (SDMMC_NISTER) Enabled  */
#define SDMMC_NISTER_BLKGE_MASKED             (SDMMC_NISTER_BLKGE_MASKED_Val << SDMMC_NISTER_BLKGE_Pos) /* (SDMMC_NISTER) Masked Position  */
#define SDMMC_NISTER_BLKGE_ENABLED            (SDMMC_NISTER_BLKGE_ENABLED_Val << SDMMC_NISTER_BLKGE_Pos) /* (SDMMC_NISTER) Enabled Position  */
#define SDMMC_NISTER_DMAINT_Pos               _UINT16_(3)                                          /* (SDMMC_NISTER) DMA Interrupt Status Enable Position */
#define SDMMC_NISTER_DMAINT_Msk               (_UINT16_(0x1) << SDMMC_NISTER_DMAINT_Pos)           /* (SDMMC_NISTER) DMA Interrupt Status Enable Mask */
#define SDMMC_NISTER_DMAINT(value)            (SDMMC_NISTER_DMAINT_Msk & (_UINT16_(value) << SDMMC_NISTER_DMAINT_Pos)) /* Assigment of value for DMAINT in the SDMMC_NISTER register */
#define   SDMMC_NISTER_DMAINT_MASKED_Val      _UINT16_(0x0)                                        /* (SDMMC_NISTER) Masked  */
#define   SDMMC_NISTER_DMAINT_ENABLED_Val     _UINT16_(0x1)                                        /* (SDMMC_NISTER) Enabled  */
#define SDMMC_NISTER_DMAINT_MASKED            (SDMMC_NISTER_DMAINT_MASKED_Val << SDMMC_NISTER_DMAINT_Pos) /* (SDMMC_NISTER) Masked Position  */
#define SDMMC_NISTER_DMAINT_ENABLED           (SDMMC_NISTER_DMAINT_ENABLED_Val << SDMMC_NISTER_DMAINT_Pos) /* (SDMMC_NISTER) Enabled Position  */
#define SDMMC_NISTER_BWRRDY_Pos               _UINT16_(4)                                          /* (SDMMC_NISTER) Buffer Write Ready Status Enable Position */
#define SDMMC_NISTER_BWRRDY_Msk               (_UINT16_(0x1) << SDMMC_NISTER_BWRRDY_Pos)           /* (SDMMC_NISTER) Buffer Write Ready Status Enable Mask */
#define SDMMC_NISTER_BWRRDY(value)            (SDMMC_NISTER_BWRRDY_Msk & (_UINT16_(value) << SDMMC_NISTER_BWRRDY_Pos)) /* Assigment of value for BWRRDY in the SDMMC_NISTER register */
#define   SDMMC_NISTER_BWRRDY_MASKED_Val      _UINT16_(0x0)                                        /* (SDMMC_NISTER) Masked  */
#define   SDMMC_NISTER_BWRRDY_ENABLED_Val     _UINT16_(0x1)                                        /* (SDMMC_NISTER) Enabled  */
#define SDMMC_NISTER_BWRRDY_MASKED            (SDMMC_NISTER_BWRRDY_MASKED_Val << SDMMC_NISTER_BWRRDY_Pos) /* (SDMMC_NISTER) Masked Position  */
#define SDMMC_NISTER_BWRRDY_ENABLED           (SDMMC_NISTER_BWRRDY_ENABLED_Val << SDMMC_NISTER_BWRRDY_Pos) /* (SDMMC_NISTER) Enabled Position  */
#define SDMMC_NISTER_BRDRDY_Pos               _UINT16_(5)                                          /* (SDMMC_NISTER) Buffer Read Ready Status Enable Position */
#define SDMMC_NISTER_BRDRDY_Msk               (_UINT16_(0x1) << SDMMC_NISTER_BRDRDY_Pos)           /* (SDMMC_NISTER) Buffer Read Ready Status Enable Mask */
#define SDMMC_NISTER_BRDRDY(value)            (SDMMC_NISTER_BRDRDY_Msk & (_UINT16_(value) << SDMMC_NISTER_BRDRDY_Pos)) /* Assigment of value for BRDRDY in the SDMMC_NISTER register */
#define   SDMMC_NISTER_BRDRDY_MASKED_Val      _UINT16_(0x0)                                        /* (SDMMC_NISTER) Masked  */
#define   SDMMC_NISTER_BRDRDY_ENABLED_Val     _UINT16_(0x1)                                        /* (SDMMC_NISTER) Enabled  */
#define SDMMC_NISTER_BRDRDY_MASKED            (SDMMC_NISTER_BRDRDY_MASKED_Val << SDMMC_NISTER_BRDRDY_Pos) /* (SDMMC_NISTER) Masked Position  */
#define SDMMC_NISTER_BRDRDY_ENABLED           (SDMMC_NISTER_BRDRDY_ENABLED_Val << SDMMC_NISTER_BRDRDY_Pos) /* (SDMMC_NISTER) Enabled Position  */
#define SDMMC_NISTER_CINS_Pos                 _UINT16_(6)                                          /* (SDMMC_NISTER) Card Insertion Status Enable Position */
#define SDMMC_NISTER_CINS_Msk                 (_UINT16_(0x1) << SDMMC_NISTER_CINS_Pos)             /* (SDMMC_NISTER) Card Insertion Status Enable Mask */
#define SDMMC_NISTER_CINS(value)              (SDMMC_NISTER_CINS_Msk & (_UINT16_(value) << SDMMC_NISTER_CINS_Pos)) /* Assigment of value for CINS in the SDMMC_NISTER register */
#define   SDMMC_NISTER_CINS_MASKED_Val        _UINT16_(0x0)                                        /* (SDMMC_NISTER) Masked  */
#define   SDMMC_NISTER_CINS_ENABLED_Val       _UINT16_(0x1)                                        /* (SDMMC_NISTER) Enabled  */
#define SDMMC_NISTER_CINS_MASKED              (SDMMC_NISTER_CINS_MASKED_Val << SDMMC_NISTER_CINS_Pos) /* (SDMMC_NISTER) Masked Position  */
#define SDMMC_NISTER_CINS_ENABLED             (SDMMC_NISTER_CINS_ENABLED_Val << SDMMC_NISTER_CINS_Pos) /* (SDMMC_NISTER) Enabled Position  */
#define SDMMC_NISTER_CREM_Pos                 _UINT16_(7)                                          /* (SDMMC_NISTER) Card Removal Status Enable Position */
#define SDMMC_NISTER_CREM_Msk                 (_UINT16_(0x1) << SDMMC_NISTER_CREM_Pos)             /* (SDMMC_NISTER) Card Removal Status Enable Mask */
#define SDMMC_NISTER_CREM(value)              (SDMMC_NISTER_CREM_Msk & (_UINT16_(value) << SDMMC_NISTER_CREM_Pos)) /* Assigment of value for CREM in the SDMMC_NISTER register */
#define   SDMMC_NISTER_CREM_MASKED_Val        _UINT16_(0x0)                                        /* (SDMMC_NISTER) Masked  */
#define   SDMMC_NISTER_CREM_ENABLED_Val       _UINT16_(0x1)                                        /* (SDMMC_NISTER) Enabled  */
#define SDMMC_NISTER_CREM_MASKED              (SDMMC_NISTER_CREM_MASKED_Val << SDMMC_NISTER_CREM_Pos) /* (SDMMC_NISTER) Masked Position  */
#define SDMMC_NISTER_CREM_ENABLED             (SDMMC_NISTER_CREM_ENABLED_Val << SDMMC_NISTER_CREM_Pos) /* (SDMMC_NISTER) Enabled Position  */
#define SDMMC_NISTER_CINT_Pos                 _UINT16_(8)                                          /* (SDMMC_NISTER) Card Interrupt Status Enable Position */
#define SDMMC_NISTER_CINT_Msk                 (_UINT16_(0x1) << SDMMC_NISTER_CINT_Pos)             /* (SDMMC_NISTER) Card Interrupt Status Enable Mask */
#define SDMMC_NISTER_CINT(value)              (SDMMC_NISTER_CINT_Msk & (_UINT16_(value) << SDMMC_NISTER_CINT_Pos)) /* Assigment of value for CINT in the SDMMC_NISTER register */
#define   SDMMC_NISTER_CINT_MASKED_Val        _UINT16_(0x0)                                        /* (SDMMC_NISTER) Masked  */
#define   SDMMC_NISTER_CINT_ENABLED_Val       _UINT16_(0x1)                                        /* (SDMMC_NISTER) Enabled  */
#define SDMMC_NISTER_CINT_MASKED              (SDMMC_NISTER_CINT_MASKED_Val << SDMMC_NISTER_CINT_Pos) /* (SDMMC_NISTER) Masked Position  */
#define SDMMC_NISTER_CINT_ENABLED             (SDMMC_NISTER_CINT_ENABLED_Val << SDMMC_NISTER_CINT_Pos) /* (SDMMC_NISTER) Enabled Position  */
#define SDMMC_NISTER_Msk                      _UINT16_(0x01FF)                                     /* (SDMMC_NISTER) Register Mask  */

/* EMMC mode */
#define SDMMC_NISTER_EMMC_BOOTAR_Pos          _UINT16_(14)                                         /* (SDMMC_NISTER) Boot Acknowledge Received Status Enable Position */
#define SDMMC_NISTER_EMMC_BOOTAR_Msk          (_UINT16_(0x1) << SDMMC_NISTER_EMMC_BOOTAR_Pos)      /* (SDMMC_NISTER) Boot Acknowledge Received Status Enable Mask */
#define SDMMC_NISTER_EMMC_BOOTAR(value)       (SDMMC_NISTER_EMMC_BOOTAR_Msk & (_UINT16_(value) << SDMMC_NISTER_EMMC_BOOTAR_Pos))
#define SDMMC_NISTER_EMMC_Msk                 _UINT16_(0x4000)                                      /* (SDMMC_NISTER_EMMC) Register Mask  */


/* -------- SDMMC_EISTER : (SDMMC Offset: 0x36) (R/W 16) Error Interrupt Status Enable -------- */
#define SDMMC_EISTER_RESETVALUE               _UINT16_(0x00)                                       /*  (SDMMC_EISTER) Error Interrupt Status Enable  Reset Value */

#define SDMMC_EISTER_CMDTEO_Pos               _UINT16_(0)                                          /* (SDMMC_EISTER) Command Timeout Error Status Enable Position */
#define SDMMC_EISTER_CMDTEO_Msk               (_UINT16_(0x1) << SDMMC_EISTER_CMDTEO_Pos)           /* (SDMMC_EISTER) Command Timeout Error Status Enable Mask */
#define SDMMC_EISTER_CMDTEO(value)            (SDMMC_EISTER_CMDTEO_Msk & (_UINT16_(value) << SDMMC_EISTER_CMDTEO_Pos)) /* Assigment of value for CMDTEO in the SDMMC_EISTER register */
#define   SDMMC_EISTER_CMDTEO_MASKED_Val      _UINT16_(0x0)                                        /* (SDMMC_EISTER) Masked  */
#define   SDMMC_EISTER_CMDTEO_ENABLED_Val     _UINT16_(0x1)                                        /* (SDMMC_EISTER) Enabled  */
#define SDMMC_EISTER_CMDTEO_MASKED            (SDMMC_EISTER_CMDTEO_MASKED_Val << SDMMC_EISTER_CMDTEO_Pos) /* (SDMMC_EISTER) Masked Position  */
#define SDMMC_EISTER_CMDTEO_ENABLED           (SDMMC_EISTER_CMDTEO_ENABLED_Val << SDMMC_EISTER_CMDTEO_Pos) /* (SDMMC_EISTER) Enabled Position  */
#define SDMMC_EISTER_CMDCRC_Pos               _UINT16_(1)                                          /* (SDMMC_EISTER) Command CRC Error Status Enable Position */
#define SDMMC_EISTER_CMDCRC_Msk               (_UINT16_(0x1) << SDMMC_EISTER_CMDCRC_Pos)           /* (SDMMC_EISTER) Command CRC Error Status Enable Mask */
#define SDMMC_EISTER_CMDCRC(value)            (SDMMC_EISTER_CMDCRC_Msk & (_UINT16_(value) << SDMMC_EISTER_CMDCRC_Pos)) /* Assigment of value for CMDCRC in the SDMMC_EISTER register */
#define   SDMMC_EISTER_CMDCRC_MASKED_Val      _UINT16_(0x0)                                        /* (SDMMC_EISTER) Masked  */
#define   SDMMC_EISTER_CMDCRC_ENABLED_Val     _UINT16_(0x1)                                        /* (SDMMC_EISTER) Enabled  */
#define SDMMC_EISTER_CMDCRC_MASKED            (SDMMC_EISTER_CMDCRC_MASKED_Val << SDMMC_EISTER_CMDCRC_Pos) /* (SDMMC_EISTER) Masked Position  */
#define SDMMC_EISTER_CMDCRC_ENABLED           (SDMMC_EISTER_CMDCRC_ENABLED_Val << SDMMC_EISTER_CMDCRC_Pos) /* (SDMMC_EISTER) Enabled Position  */
#define SDMMC_EISTER_CMDEND_Pos               _UINT16_(2)                                          /* (SDMMC_EISTER) Command End Bit Error Status Enable Position */
#define SDMMC_EISTER_CMDEND_Msk               (_UINT16_(0x1) << SDMMC_EISTER_CMDEND_Pos)           /* (SDMMC_EISTER) Command End Bit Error Status Enable Mask */
#define SDMMC_EISTER_CMDEND(value)            (SDMMC_EISTER_CMDEND_Msk & (_UINT16_(value) << SDMMC_EISTER_CMDEND_Pos)) /* Assigment of value for CMDEND in the SDMMC_EISTER register */
#define   SDMMC_EISTER_CMDEND_MASKED_Val      _UINT16_(0x0)                                        /* (SDMMC_EISTER) Masked  */
#define   SDMMC_EISTER_CMDEND_ENABLED_Val     _UINT16_(0x1)                                        /* (SDMMC_EISTER) Enabled  */
#define SDMMC_EISTER_CMDEND_MASKED            (SDMMC_EISTER_CMDEND_MASKED_Val << SDMMC_EISTER_CMDEND_Pos) /* (SDMMC_EISTER) Masked Position  */
#define SDMMC_EISTER_CMDEND_ENABLED           (SDMMC_EISTER_CMDEND_ENABLED_Val << SDMMC_EISTER_CMDEND_Pos) /* (SDMMC_EISTER) Enabled Position  */
#define SDMMC_EISTER_CMDIDX_Pos               _UINT16_(3)                                          /* (SDMMC_EISTER) Command Index Error Status Enable Position */
#define SDMMC_EISTER_CMDIDX_Msk               (_UINT16_(0x1) << SDMMC_EISTER_CMDIDX_Pos)           /* (SDMMC_EISTER) Command Index Error Status Enable Mask */
#define SDMMC_EISTER_CMDIDX(value)            (SDMMC_EISTER_CMDIDX_Msk & (_UINT16_(value) << SDMMC_EISTER_CMDIDX_Pos)) /* Assigment of value for CMDIDX in the SDMMC_EISTER register */
#define   SDMMC_EISTER_CMDIDX_MASKED_Val      _UINT16_(0x0)                                        /* (SDMMC_EISTER) Masked  */
#define   SDMMC_EISTER_CMDIDX_ENABLED_Val     _UINT16_(0x1)                                        /* (SDMMC_EISTER) Enabled  */
#define SDMMC_EISTER_CMDIDX_MASKED            (SDMMC_EISTER_CMDIDX_MASKED_Val << SDMMC_EISTER_CMDIDX_Pos) /* (SDMMC_EISTER) Masked Position  */
#define SDMMC_EISTER_CMDIDX_ENABLED           (SDMMC_EISTER_CMDIDX_ENABLED_Val << SDMMC_EISTER_CMDIDX_Pos) /* (SDMMC_EISTER) Enabled Position  */
#define SDMMC_EISTER_DATTEO_Pos               _UINT16_(4)                                          /* (SDMMC_EISTER) Data Timeout Error Status Enable Position */
#define SDMMC_EISTER_DATTEO_Msk               (_UINT16_(0x1) << SDMMC_EISTER_DATTEO_Pos)           /* (SDMMC_EISTER) Data Timeout Error Status Enable Mask */
#define SDMMC_EISTER_DATTEO(value)            (SDMMC_EISTER_DATTEO_Msk & (_UINT16_(value) << SDMMC_EISTER_DATTEO_Pos)) /* Assigment of value for DATTEO in the SDMMC_EISTER register */
#define   SDMMC_EISTER_DATTEO_MASKED_Val      _UINT16_(0x0)                                        /* (SDMMC_EISTER) Masked  */
#define   SDMMC_EISTER_DATTEO_ENABLED_Val     _UINT16_(0x1)                                        /* (SDMMC_EISTER) Enabled  */
#define SDMMC_EISTER_DATTEO_MASKED            (SDMMC_EISTER_DATTEO_MASKED_Val << SDMMC_EISTER_DATTEO_Pos) /* (SDMMC_EISTER) Masked Position  */
#define SDMMC_EISTER_DATTEO_ENABLED           (SDMMC_EISTER_DATTEO_ENABLED_Val << SDMMC_EISTER_DATTEO_Pos) /* (SDMMC_EISTER) Enabled Position  */
#define SDMMC_EISTER_DATCRC_Pos               _UINT16_(5)                                          /* (SDMMC_EISTER) Data CRC Error Status Enable Position */
#define SDMMC_EISTER_DATCRC_Msk               (_UINT16_(0x1) << SDMMC_EISTER_DATCRC_Pos)           /* (SDMMC_EISTER) Data CRC Error Status Enable Mask */
#define SDMMC_EISTER_DATCRC(value)            (SDMMC_EISTER_DATCRC_Msk & (_UINT16_(value) << SDMMC_EISTER_DATCRC_Pos)) /* Assigment of value for DATCRC in the SDMMC_EISTER register */
#define   SDMMC_EISTER_DATCRC_MASKED_Val      _UINT16_(0x0)                                        /* (SDMMC_EISTER) Masked  */
#define   SDMMC_EISTER_DATCRC_ENABLED_Val     _UINT16_(0x1)                                        /* (SDMMC_EISTER) Enabled  */
#define SDMMC_EISTER_DATCRC_MASKED            (SDMMC_EISTER_DATCRC_MASKED_Val << SDMMC_EISTER_DATCRC_Pos) /* (SDMMC_EISTER) Masked Position  */
#define SDMMC_EISTER_DATCRC_ENABLED           (SDMMC_EISTER_DATCRC_ENABLED_Val << SDMMC_EISTER_DATCRC_Pos) /* (SDMMC_EISTER) Enabled Position  */
#define SDMMC_EISTER_DATEND_Pos               _UINT16_(6)                                          /* (SDMMC_EISTER) Data End Bit Error Status Enable Position */
#define SDMMC_EISTER_DATEND_Msk               (_UINT16_(0x1) << SDMMC_EISTER_DATEND_Pos)           /* (SDMMC_EISTER) Data End Bit Error Status Enable Mask */
#define SDMMC_EISTER_DATEND(value)            (SDMMC_EISTER_DATEND_Msk & (_UINT16_(value) << SDMMC_EISTER_DATEND_Pos)) /* Assigment of value for DATEND in the SDMMC_EISTER register */
#define   SDMMC_EISTER_DATEND_MASKED_Val      _UINT16_(0x0)                                        /* (SDMMC_EISTER) Masked  */
#define   SDMMC_EISTER_DATEND_ENABLED_Val     _UINT16_(0x1)                                        /* (SDMMC_EISTER) Enabled  */
#define SDMMC_EISTER_DATEND_MASKED            (SDMMC_EISTER_DATEND_MASKED_Val << SDMMC_EISTER_DATEND_Pos) /* (SDMMC_EISTER) Masked Position  */
#define SDMMC_EISTER_DATEND_ENABLED           (SDMMC_EISTER_DATEND_ENABLED_Val << SDMMC_EISTER_DATEND_Pos) /* (SDMMC_EISTER) Enabled Position  */
#define SDMMC_EISTER_CURLIM_Pos               _UINT16_(7)                                          /* (SDMMC_EISTER) Current Limit Error Status Enable Position */
#define SDMMC_EISTER_CURLIM_Msk               (_UINT16_(0x1) << SDMMC_EISTER_CURLIM_Pos)           /* (SDMMC_EISTER) Current Limit Error Status Enable Mask */
#define SDMMC_EISTER_CURLIM(value)            (SDMMC_EISTER_CURLIM_Msk & (_UINT16_(value) << SDMMC_EISTER_CURLIM_Pos)) /* Assigment of value for CURLIM in the SDMMC_EISTER register */
#define   SDMMC_EISTER_CURLIM_MASKED_Val      _UINT16_(0x0)                                        /* (SDMMC_EISTER) Masked  */
#define   SDMMC_EISTER_CURLIM_ENABLED_Val     _UINT16_(0x1)                                        /* (SDMMC_EISTER) Enabled  */
#define SDMMC_EISTER_CURLIM_MASKED            (SDMMC_EISTER_CURLIM_MASKED_Val << SDMMC_EISTER_CURLIM_Pos) /* (SDMMC_EISTER) Masked Position  */
#define SDMMC_EISTER_CURLIM_ENABLED           (SDMMC_EISTER_CURLIM_ENABLED_Val << SDMMC_EISTER_CURLIM_Pos) /* (SDMMC_EISTER) Enabled Position  */
#define SDMMC_EISTER_ACMD_Pos                 _UINT16_(8)                                          /* (SDMMC_EISTER) Auto CMD Error Status Enable Position */
#define SDMMC_EISTER_ACMD_Msk                 (_UINT16_(0x1) << SDMMC_EISTER_ACMD_Pos)             /* (SDMMC_EISTER) Auto CMD Error Status Enable Mask */
#define SDMMC_EISTER_ACMD(value)              (SDMMC_EISTER_ACMD_Msk & (_UINT16_(value) << SDMMC_EISTER_ACMD_Pos)) /* Assigment of value for ACMD in the SDMMC_EISTER register */
#define   SDMMC_EISTER_ACMD_MASKED_Val        _UINT16_(0x0)                                        /* (SDMMC_EISTER) Masked  */
#define   SDMMC_EISTER_ACMD_ENABLED_Val       _UINT16_(0x1)                                        /* (SDMMC_EISTER) Enabled  */
#define SDMMC_EISTER_ACMD_MASKED              (SDMMC_EISTER_ACMD_MASKED_Val << SDMMC_EISTER_ACMD_Pos) /* (SDMMC_EISTER) Masked Position  */
#define SDMMC_EISTER_ACMD_ENABLED             (SDMMC_EISTER_ACMD_ENABLED_Val << SDMMC_EISTER_ACMD_Pos) /* (SDMMC_EISTER) Enabled Position  */
#define SDMMC_EISTER_ADMA_Pos                 _UINT16_(9)                                          /* (SDMMC_EISTER) ADMA Error Status Enable Position */
#define SDMMC_EISTER_ADMA_Msk                 (_UINT16_(0x1) << SDMMC_EISTER_ADMA_Pos)             /* (SDMMC_EISTER) ADMA Error Status Enable Mask */
#define SDMMC_EISTER_ADMA(value)              (SDMMC_EISTER_ADMA_Msk & (_UINT16_(value) << SDMMC_EISTER_ADMA_Pos)) /* Assigment of value for ADMA in the SDMMC_EISTER register */
#define   SDMMC_EISTER_ADMA_MASKED_Val        _UINT16_(0x0)                                        /* (SDMMC_EISTER) Masked  */
#define   SDMMC_EISTER_ADMA_ENABLED_Val       _UINT16_(0x1)                                        /* (SDMMC_EISTER) Enabled  */
#define SDMMC_EISTER_ADMA_MASKED              (SDMMC_EISTER_ADMA_MASKED_Val << SDMMC_EISTER_ADMA_Pos) /* (SDMMC_EISTER) Masked Position  */
#define SDMMC_EISTER_ADMA_ENABLED             (SDMMC_EISTER_ADMA_ENABLED_Val << SDMMC_EISTER_ADMA_Pos) /* (SDMMC_EISTER) Enabled Position  */
#define SDMMC_EISTER_Msk                      _UINT16_(0x03FF)                                     /* (SDMMC_EISTER) Register Mask  */

/* EMMC mode */
#define SDMMC_EISTER_EMMC_BOOTAE_Pos          _UINT16_(12)                                         /* (SDMMC_EISTER) Boot Acknowledge Error Status Enable Position */
#define SDMMC_EISTER_EMMC_BOOTAE_Msk          (_UINT16_(0x1) << SDMMC_EISTER_EMMC_BOOTAE_Pos)      /* (SDMMC_EISTER) Boot Acknowledge Error Status Enable Mask */
#define SDMMC_EISTER_EMMC_BOOTAE(value)       (SDMMC_EISTER_EMMC_BOOTAE_Msk & (_UINT16_(value) << SDMMC_EISTER_EMMC_BOOTAE_Pos))
#define SDMMC_EISTER_EMMC_Msk                 _UINT16_(0x1000)                                      /* (SDMMC_EISTER_EMMC) Register Mask  */


/* -------- SDMMC_NISIER : (SDMMC Offset: 0x38) (R/W 16) Normal Interrupt Signal Enable -------- */
#define SDMMC_NISIER_RESETVALUE               _UINT16_(0x00)                                       /*  (SDMMC_NISIER) Normal Interrupt Signal Enable  Reset Value */

#define SDMMC_NISIER_CMDC_Pos                 _UINT16_(0)                                          /* (SDMMC_NISIER) Command Complete Signal Enable Position */
#define SDMMC_NISIER_CMDC_Msk                 (_UINT16_(0x1) << SDMMC_NISIER_CMDC_Pos)             /* (SDMMC_NISIER) Command Complete Signal Enable Mask */
#define SDMMC_NISIER_CMDC(value)              (SDMMC_NISIER_CMDC_Msk & (_UINT16_(value) << SDMMC_NISIER_CMDC_Pos)) /* Assigment of value for CMDC in the SDMMC_NISIER register */
#define   SDMMC_NISIER_CMDC_MASKED_Val        _UINT16_(0x0)                                        /* (SDMMC_NISIER) Masked  */
#define   SDMMC_NISIER_CMDC_ENABLED_Val       _UINT16_(0x1)                                        /* (SDMMC_NISIER) Enabled  */
#define SDMMC_NISIER_CMDC_MASKED              (SDMMC_NISIER_CMDC_MASKED_Val << SDMMC_NISIER_CMDC_Pos) /* (SDMMC_NISIER) Masked Position  */
#define SDMMC_NISIER_CMDC_ENABLED             (SDMMC_NISIER_CMDC_ENABLED_Val << SDMMC_NISIER_CMDC_Pos) /* (SDMMC_NISIER) Enabled Position  */
#define SDMMC_NISIER_TRFC_Pos                 _UINT16_(1)                                          /* (SDMMC_NISIER) Transfer Complete Signal Enable Position */
#define SDMMC_NISIER_TRFC_Msk                 (_UINT16_(0x1) << SDMMC_NISIER_TRFC_Pos)             /* (SDMMC_NISIER) Transfer Complete Signal Enable Mask */
#define SDMMC_NISIER_TRFC(value)              (SDMMC_NISIER_TRFC_Msk & (_UINT16_(value) << SDMMC_NISIER_TRFC_Pos)) /* Assigment of value for TRFC in the SDMMC_NISIER register */
#define   SDMMC_NISIER_TRFC_MASKED_Val        _UINT16_(0x0)                                        /* (SDMMC_NISIER) Masked  */
#define   SDMMC_NISIER_TRFC_ENABLED_Val       _UINT16_(0x1)                                        /* (SDMMC_NISIER) Enabled  */
#define SDMMC_NISIER_TRFC_MASKED              (SDMMC_NISIER_TRFC_MASKED_Val << SDMMC_NISIER_TRFC_Pos) /* (SDMMC_NISIER) Masked Position  */
#define SDMMC_NISIER_TRFC_ENABLED             (SDMMC_NISIER_TRFC_ENABLED_Val << SDMMC_NISIER_TRFC_Pos) /* (SDMMC_NISIER) Enabled Position  */
#define SDMMC_NISIER_BLKGE_Pos                _UINT16_(2)                                          /* (SDMMC_NISIER) Block Gap Event Signal Enable Position */
#define SDMMC_NISIER_BLKGE_Msk                (_UINT16_(0x1) << SDMMC_NISIER_BLKGE_Pos)            /* (SDMMC_NISIER) Block Gap Event Signal Enable Mask */
#define SDMMC_NISIER_BLKGE(value)             (SDMMC_NISIER_BLKGE_Msk & (_UINT16_(value) << SDMMC_NISIER_BLKGE_Pos)) /* Assigment of value for BLKGE in the SDMMC_NISIER register */
#define   SDMMC_NISIER_BLKGE_MASKED_Val       _UINT16_(0x0)                                        /* (SDMMC_NISIER) Masked  */
#define   SDMMC_NISIER_BLKGE_ENABLED_Val      _UINT16_(0x1)                                        /* (SDMMC_NISIER) Enabled  */
#define SDMMC_NISIER_BLKGE_MASKED             (SDMMC_NISIER_BLKGE_MASKED_Val << SDMMC_NISIER_BLKGE_Pos) /* (SDMMC_NISIER) Masked Position  */
#define SDMMC_NISIER_BLKGE_ENABLED            (SDMMC_NISIER_BLKGE_ENABLED_Val << SDMMC_NISIER_BLKGE_Pos) /* (SDMMC_NISIER) Enabled Position  */
#define SDMMC_NISIER_DMAINT_Pos               _UINT16_(3)                                          /* (SDMMC_NISIER) DMA Interrupt Signal Enable Position */
#define SDMMC_NISIER_DMAINT_Msk               (_UINT16_(0x1) << SDMMC_NISIER_DMAINT_Pos)           /* (SDMMC_NISIER) DMA Interrupt Signal Enable Mask */
#define SDMMC_NISIER_DMAINT(value)            (SDMMC_NISIER_DMAINT_Msk & (_UINT16_(value) << SDMMC_NISIER_DMAINT_Pos)) /* Assigment of value for DMAINT in the SDMMC_NISIER register */
#define   SDMMC_NISIER_DMAINT_MASKED_Val      _UINT16_(0x0)                                        /* (SDMMC_NISIER) Masked  */
#define   SDMMC_NISIER_DMAINT_ENABLED_Val     _UINT16_(0x1)                                        /* (SDMMC_NISIER) Enabled  */
#define SDMMC_NISIER_DMAINT_MASKED            (SDMMC_NISIER_DMAINT_MASKED_Val << SDMMC_NISIER_DMAINT_Pos) /* (SDMMC_NISIER) Masked Position  */
#define SDMMC_NISIER_DMAINT_ENABLED           (SDMMC_NISIER_DMAINT_ENABLED_Val << SDMMC_NISIER_DMAINT_Pos) /* (SDMMC_NISIER) Enabled Position  */
#define SDMMC_NISIER_BWRRDY_Pos               _UINT16_(4)                                          /* (SDMMC_NISIER) Buffer Write Ready Signal Enable Position */
#define SDMMC_NISIER_BWRRDY_Msk               (_UINT16_(0x1) << SDMMC_NISIER_BWRRDY_Pos)           /* (SDMMC_NISIER) Buffer Write Ready Signal Enable Mask */
#define SDMMC_NISIER_BWRRDY(value)            (SDMMC_NISIER_BWRRDY_Msk & (_UINT16_(value) << SDMMC_NISIER_BWRRDY_Pos)) /* Assigment of value for BWRRDY in the SDMMC_NISIER register */
#define   SDMMC_NISIER_BWRRDY_MASKED_Val      _UINT16_(0x0)                                        /* (SDMMC_NISIER) Masked  */
#define   SDMMC_NISIER_BWRRDY_ENABLED_Val     _UINT16_(0x1)                                        /* (SDMMC_NISIER) Enabled  */
#define SDMMC_NISIER_BWRRDY_MASKED            (SDMMC_NISIER_BWRRDY_MASKED_Val << SDMMC_NISIER_BWRRDY_Pos) /* (SDMMC_NISIER) Masked Position  */
#define SDMMC_NISIER_BWRRDY_ENABLED           (SDMMC_NISIER_BWRRDY_ENABLED_Val << SDMMC_NISIER_BWRRDY_Pos) /* (SDMMC_NISIER) Enabled Position  */
#define SDMMC_NISIER_BRDRDY_Pos               _UINT16_(5)                                          /* (SDMMC_NISIER) Buffer Read Ready Signal Enable Position */
#define SDMMC_NISIER_BRDRDY_Msk               (_UINT16_(0x1) << SDMMC_NISIER_BRDRDY_Pos)           /* (SDMMC_NISIER) Buffer Read Ready Signal Enable Mask */
#define SDMMC_NISIER_BRDRDY(value)            (SDMMC_NISIER_BRDRDY_Msk & (_UINT16_(value) << SDMMC_NISIER_BRDRDY_Pos)) /* Assigment of value for BRDRDY in the SDMMC_NISIER register */
#define   SDMMC_NISIER_BRDRDY_MASKED_Val      _UINT16_(0x0)                                        /* (SDMMC_NISIER) Masked  */
#define   SDMMC_NISIER_BRDRDY_ENABLED_Val     _UINT16_(0x1)                                        /* (SDMMC_NISIER) Enabled  */
#define SDMMC_NISIER_BRDRDY_MASKED            (SDMMC_NISIER_BRDRDY_MASKED_Val << SDMMC_NISIER_BRDRDY_Pos) /* (SDMMC_NISIER) Masked Position  */
#define SDMMC_NISIER_BRDRDY_ENABLED           (SDMMC_NISIER_BRDRDY_ENABLED_Val << SDMMC_NISIER_BRDRDY_Pos) /* (SDMMC_NISIER) Enabled Position  */
#define SDMMC_NISIER_CINS_Pos                 _UINT16_(6)                                          /* (SDMMC_NISIER) Card Insertion Signal Enable Position */
#define SDMMC_NISIER_CINS_Msk                 (_UINT16_(0x1) << SDMMC_NISIER_CINS_Pos)             /* (SDMMC_NISIER) Card Insertion Signal Enable Mask */
#define SDMMC_NISIER_CINS(value)              (SDMMC_NISIER_CINS_Msk & (_UINT16_(value) << SDMMC_NISIER_CINS_Pos)) /* Assigment of value for CINS in the SDMMC_NISIER register */
#define   SDMMC_NISIER_CINS_MASKED_Val        _UINT16_(0x0)                                        /* (SDMMC_NISIER) Masked  */
#define   SDMMC_NISIER_CINS_ENABLED_Val       _UINT16_(0x1)                                        /* (SDMMC_NISIER) Enabled  */
#define SDMMC_NISIER_CINS_MASKED              (SDMMC_NISIER_CINS_MASKED_Val << SDMMC_NISIER_CINS_Pos) /* (SDMMC_NISIER) Masked Position  */
#define SDMMC_NISIER_CINS_ENABLED             (SDMMC_NISIER_CINS_ENABLED_Val << SDMMC_NISIER_CINS_Pos) /* (SDMMC_NISIER) Enabled Position  */
#define SDMMC_NISIER_CREM_Pos                 _UINT16_(7)                                          /* (SDMMC_NISIER) Card Removal Signal Enable Position */
#define SDMMC_NISIER_CREM_Msk                 (_UINT16_(0x1) << SDMMC_NISIER_CREM_Pos)             /* (SDMMC_NISIER) Card Removal Signal Enable Mask */
#define SDMMC_NISIER_CREM(value)              (SDMMC_NISIER_CREM_Msk & (_UINT16_(value) << SDMMC_NISIER_CREM_Pos)) /* Assigment of value for CREM in the SDMMC_NISIER register */
#define   SDMMC_NISIER_CREM_MASKED_Val        _UINT16_(0x0)                                        /* (SDMMC_NISIER) Masked  */
#define   SDMMC_NISIER_CREM_ENABLED_Val       _UINT16_(0x1)                                        /* (SDMMC_NISIER) Enabled  */
#define SDMMC_NISIER_CREM_MASKED              (SDMMC_NISIER_CREM_MASKED_Val << SDMMC_NISIER_CREM_Pos) /* (SDMMC_NISIER) Masked Position  */
#define SDMMC_NISIER_CREM_ENABLED             (SDMMC_NISIER_CREM_ENABLED_Val << SDMMC_NISIER_CREM_Pos) /* (SDMMC_NISIER) Enabled Position  */
#define SDMMC_NISIER_CINT_Pos                 _UINT16_(8)                                          /* (SDMMC_NISIER) Card Interrupt Signal Enable Position */
#define SDMMC_NISIER_CINT_Msk                 (_UINT16_(0x1) << SDMMC_NISIER_CINT_Pos)             /* (SDMMC_NISIER) Card Interrupt Signal Enable Mask */
#define SDMMC_NISIER_CINT(value)              (SDMMC_NISIER_CINT_Msk & (_UINT16_(value) << SDMMC_NISIER_CINT_Pos)) /* Assigment of value for CINT in the SDMMC_NISIER register */
#define   SDMMC_NISIER_CINT_MASKED_Val        _UINT16_(0x0)                                        /* (SDMMC_NISIER) Masked  */
#define   SDMMC_NISIER_CINT_ENABLED_Val       _UINT16_(0x1)                                        /* (SDMMC_NISIER) Enabled  */
#define SDMMC_NISIER_CINT_MASKED              (SDMMC_NISIER_CINT_MASKED_Val << SDMMC_NISIER_CINT_Pos) /* (SDMMC_NISIER) Masked Position  */
#define SDMMC_NISIER_CINT_ENABLED             (SDMMC_NISIER_CINT_ENABLED_Val << SDMMC_NISIER_CINT_Pos) /* (SDMMC_NISIER) Enabled Position  */
#define SDMMC_NISIER_Msk                      _UINT16_(0x01FF)                                     /* (SDMMC_NISIER) Register Mask  */

/* EMMC mode */
#define SDMMC_NISIER_EMMC_BOOTAR_Pos          _UINT16_(14)                                         /* (SDMMC_NISIER) Boot Acknowledge Received Signal Enable Position */
#define SDMMC_NISIER_EMMC_BOOTAR_Msk          (_UINT16_(0x1) << SDMMC_NISIER_EMMC_BOOTAR_Pos)      /* (SDMMC_NISIER) Boot Acknowledge Received Signal Enable Mask */
#define SDMMC_NISIER_EMMC_BOOTAR(value)       (SDMMC_NISIER_EMMC_BOOTAR_Msk & (_UINT16_(value) << SDMMC_NISIER_EMMC_BOOTAR_Pos))
#define SDMMC_NISIER_EMMC_Msk                 _UINT16_(0x4000)                                      /* (SDMMC_NISIER_EMMC) Register Mask  */


/* -------- SDMMC_EISIER : (SDMMC Offset: 0x3A) (R/W 16) Error Interrupt Signal Enable -------- */
#define SDMMC_EISIER_RESETVALUE               _UINT16_(0x00)                                       /*  (SDMMC_EISIER) Error Interrupt Signal Enable  Reset Value */

#define SDMMC_EISIER_CMDTEO_Pos               _UINT16_(0)                                          /* (SDMMC_EISIER) Command Timeout Error Signal Enable Position */
#define SDMMC_EISIER_CMDTEO_Msk               (_UINT16_(0x1) << SDMMC_EISIER_CMDTEO_Pos)           /* (SDMMC_EISIER) Command Timeout Error Signal Enable Mask */
#define SDMMC_EISIER_CMDTEO(value)            (SDMMC_EISIER_CMDTEO_Msk & (_UINT16_(value) << SDMMC_EISIER_CMDTEO_Pos)) /* Assigment of value for CMDTEO in the SDMMC_EISIER register */
#define   SDMMC_EISIER_CMDTEO_MASKED_Val      _UINT16_(0x0)                                        /* (SDMMC_EISIER) Masked  */
#define   SDMMC_EISIER_CMDTEO_ENABLED_Val     _UINT16_(0x1)                                        /* (SDMMC_EISIER) Enabled  */
#define SDMMC_EISIER_CMDTEO_MASKED            (SDMMC_EISIER_CMDTEO_MASKED_Val << SDMMC_EISIER_CMDTEO_Pos) /* (SDMMC_EISIER) Masked Position  */
#define SDMMC_EISIER_CMDTEO_ENABLED           (SDMMC_EISIER_CMDTEO_ENABLED_Val << SDMMC_EISIER_CMDTEO_Pos) /* (SDMMC_EISIER) Enabled Position  */
#define SDMMC_EISIER_CMDCRC_Pos               _UINT16_(1)                                          /* (SDMMC_EISIER) Command CRC Error Signal Enable Position */
#define SDMMC_EISIER_CMDCRC_Msk               (_UINT16_(0x1) << SDMMC_EISIER_CMDCRC_Pos)           /* (SDMMC_EISIER) Command CRC Error Signal Enable Mask */
#define SDMMC_EISIER_CMDCRC(value)            (SDMMC_EISIER_CMDCRC_Msk & (_UINT16_(value) << SDMMC_EISIER_CMDCRC_Pos)) /* Assigment of value for CMDCRC in the SDMMC_EISIER register */
#define   SDMMC_EISIER_CMDCRC_MASKED_Val      _UINT16_(0x0)                                        /* (SDMMC_EISIER) Masked  */
#define   SDMMC_EISIER_CMDCRC_ENABLED_Val     _UINT16_(0x1)                                        /* (SDMMC_EISIER) Enabled  */
#define SDMMC_EISIER_CMDCRC_MASKED            (SDMMC_EISIER_CMDCRC_MASKED_Val << SDMMC_EISIER_CMDCRC_Pos) /* (SDMMC_EISIER) Masked Position  */
#define SDMMC_EISIER_CMDCRC_ENABLED           (SDMMC_EISIER_CMDCRC_ENABLED_Val << SDMMC_EISIER_CMDCRC_Pos) /* (SDMMC_EISIER) Enabled Position  */
#define SDMMC_EISIER_CMDEND_Pos               _UINT16_(2)                                          /* (SDMMC_EISIER) Command End Bit Error Signal Enable Position */
#define SDMMC_EISIER_CMDEND_Msk               (_UINT16_(0x1) << SDMMC_EISIER_CMDEND_Pos)           /* (SDMMC_EISIER) Command End Bit Error Signal Enable Mask */
#define SDMMC_EISIER_CMDEND(value)            (SDMMC_EISIER_CMDEND_Msk & (_UINT16_(value) << SDMMC_EISIER_CMDEND_Pos)) /* Assigment of value for CMDEND in the SDMMC_EISIER register */
#define   SDMMC_EISIER_CMDEND_MASKED_Val      _UINT16_(0x0)                                        /* (SDMMC_EISIER) Masked  */
#define   SDMMC_EISIER_CMDEND_ENABLED_Val     _UINT16_(0x1)                                        /* (SDMMC_EISIER) Enabled  */
#define SDMMC_EISIER_CMDEND_MASKED            (SDMMC_EISIER_CMDEND_MASKED_Val << SDMMC_EISIER_CMDEND_Pos) /* (SDMMC_EISIER) Masked Position  */
#define SDMMC_EISIER_CMDEND_ENABLED           (SDMMC_EISIER_CMDEND_ENABLED_Val << SDMMC_EISIER_CMDEND_Pos) /* (SDMMC_EISIER) Enabled Position  */
#define SDMMC_EISIER_CMDIDX_Pos               _UINT16_(3)                                          /* (SDMMC_EISIER) Command Index Error Signal Enable Position */
#define SDMMC_EISIER_CMDIDX_Msk               (_UINT16_(0x1) << SDMMC_EISIER_CMDIDX_Pos)           /* (SDMMC_EISIER) Command Index Error Signal Enable Mask */
#define SDMMC_EISIER_CMDIDX(value)            (SDMMC_EISIER_CMDIDX_Msk & (_UINT16_(value) << SDMMC_EISIER_CMDIDX_Pos)) /* Assigment of value for CMDIDX in the SDMMC_EISIER register */
#define   SDMMC_EISIER_CMDIDX_MASKED_Val      _UINT16_(0x0)                                        /* (SDMMC_EISIER) Masked  */
#define   SDMMC_EISIER_CMDIDX_ENABLED_Val     _UINT16_(0x1)                                        /* (SDMMC_EISIER) Enabled  */
#define SDMMC_EISIER_CMDIDX_MASKED            (SDMMC_EISIER_CMDIDX_MASKED_Val << SDMMC_EISIER_CMDIDX_Pos) /* (SDMMC_EISIER) Masked Position  */
#define SDMMC_EISIER_CMDIDX_ENABLED           (SDMMC_EISIER_CMDIDX_ENABLED_Val << SDMMC_EISIER_CMDIDX_Pos) /* (SDMMC_EISIER) Enabled Position  */
#define SDMMC_EISIER_DATTEO_Pos               _UINT16_(4)                                          /* (SDMMC_EISIER) Data Timeout Error Signal Enable Position */
#define SDMMC_EISIER_DATTEO_Msk               (_UINT16_(0x1) << SDMMC_EISIER_DATTEO_Pos)           /* (SDMMC_EISIER) Data Timeout Error Signal Enable Mask */
#define SDMMC_EISIER_DATTEO(value)            (SDMMC_EISIER_DATTEO_Msk & (_UINT16_(value) << SDMMC_EISIER_DATTEO_Pos)) /* Assigment of value for DATTEO in the SDMMC_EISIER register */
#define   SDMMC_EISIER_DATTEO_MASKED_Val      _UINT16_(0x0)                                        /* (SDMMC_EISIER) Masked  */
#define   SDMMC_EISIER_DATTEO_ENABLED_Val     _UINT16_(0x1)                                        /* (SDMMC_EISIER) Enabled  */
#define SDMMC_EISIER_DATTEO_MASKED            (SDMMC_EISIER_DATTEO_MASKED_Val << SDMMC_EISIER_DATTEO_Pos) /* (SDMMC_EISIER) Masked Position  */
#define SDMMC_EISIER_DATTEO_ENABLED           (SDMMC_EISIER_DATTEO_ENABLED_Val << SDMMC_EISIER_DATTEO_Pos) /* (SDMMC_EISIER) Enabled Position  */
#define SDMMC_EISIER_DATCRC_Pos               _UINT16_(5)                                          /* (SDMMC_EISIER) Data CRC Error Signal Enable Position */
#define SDMMC_EISIER_DATCRC_Msk               (_UINT16_(0x1) << SDMMC_EISIER_DATCRC_Pos)           /* (SDMMC_EISIER) Data CRC Error Signal Enable Mask */
#define SDMMC_EISIER_DATCRC(value)            (SDMMC_EISIER_DATCRC_Msk & (_UINT16_(value) << SDMMC_EISIER_DATCRC_Pos)) /* Assigment of value for DATCRC in the SDMMC_EISIER register */
#define   SDMMC_EISIER_DATCRC_MASKED_Val      _UINT16_(0x0)                                        /* (SDMMC_EISIER) Masked  */
#define   SDMMC_EISIER_DATCRC_ENABLED_Val     _UINT16_(0x1)                                        /* (SDMMC_EISIER) Enabled  */
#define SDMMC_EISIER_DATCRC_MASKED            (SDMMC_EISIER_DATCRC_MASKED_Val << SDMMC_EISIER_DATCRC_Pos) /* (SDMMC_EISIER) Masked Position  */
#define SDMMC_EISIER_DATCRC_ENABLED           (SDMMC_EISIER_DATCRC_ENABLED_Val << SDMMC_EISIER_DATCRC_Pos) /* (SDMMC_EISIER) Enabled Position  */
#define SDMMC_EISIER_DATEND_Pos               _UINT16_(6)                                          /* (SDMMC_EISIER) Data End Bit Error Signal Enable Position */
#define SDMMC_EISIER_DATEND_Msk               (_UINT16_(0x1) << SDMMC_EISIER_DATEND_Pos)           /* (SDMMC_EISIER) Data End Bit Error Signal Enable Mask */
#define SDMMC_EISIER_DATEND(value)            (SDMMC_EISIER_DATEND_Msk & (_UINT16_(value) << SDMMC_EISIER_DATEND_Pos)) /* Assigment of value for DATEND in the SDMMC_EISIER register */
#define   SDMMC_EISIER_DATEND_MASKED_Val      _UINT16_(0x0)                                        /* (SDMMC_EISIER) Masked  */
#define   SDMMC_EISIER_DATEND_ENABLED_Val     _UINT16_(0x1)                                        /* (SDMMC_EISIER) Enabled  */
#define SDMMC_EISIER_DATEND_MASKED            (SDMMC_EISIER_DATEND_MASKED_Val << SDMMC_EISIER_DATEND_Pos) /* (SDMMC_EISIER) Masked Position  */
#define SDMMC_EISIER_DATEND_ENABLED           (SDMMC_EISIER_DATEND_ENABLED_Val << SDMMC_EISIER_DATEND_Pos) /* (SDMMC_EISIER) Enabled Position  */
#define SDMMC_EISIER_CURLIM_Pos               _UINT16_(7)                                          /* (SDMMC_EISIER) Current Limit Error Signal Enable Position */
#define SDMMC_EISIER_CURLIM_Msk               (_UINT16_(0x1) << SDMMC_EISIER_CURLIM_Pos)           /* (SDMMC_EISIER) Current Limit Error Signal Enable Mask */
#define SDMMC_EISIER_CURLIM(value)            (SDMMC_EISIER_CURLIM_Msk & (_UINT16_(value) << SDMMC_EISIER_CURLIM_Pos)) /* Assigment of value for CURLIM in the SDMMC_EISIER register */
#define   SDMMC_EISIER_CURLIM_MASKED_Val      _UINT16_(0x0)                                        /* (SDMMC_EISIER) Masked  */
#define   SDMMC_EISIER_CURLIM_ENABLED_Val     _UINT16_(0x1)                                        /* (SDMMC_EISIER) Enabled  */
#define SDMMC_EISIER_CURLIM_MASKED            (SDMMC_EISIER_CURLIM_MASKED_Val << SDMMC_EISIER_CURLIM_Pos) /* (SDMMC_EISIER) Masked Position  */
#define SDMMC_EISIER_CURLIM_ENABLED           (SDMMC_EISIER_CURLIM_ENABLED_Val << SDMMC_EISIER_CURLIM_Pos) /* (SDMMC_EISIER) Enabled Position  */
#define SDMMC_EISIER_ACMD_Pos                 _UINT16_(8)                                          /* (SDMMC_EISIER) Auto CMD Error Signal Enable Position */
#define SDMMC_EISIER_ACMD_Msk                 (_UINT16_(0x1) << SDMMC_EISIER_ACMD_Pos)             /* (SDMMC_EISIER) Auto CMD Error Signal Enable Mask */
#define SDMMC_EISIER_ACMD(value)              (SDMMC_EISIER_ACMD_Msk & (_UINT16_(value) << SDMMC_EISIER_ACMD_Pos)) /* Assigment of value for ACMD in the SDMMC_EISIER register */
#define   SDMMC_EISIER_ACMD_MASKED_Val        _UINT16_(0x0)                                        /* (SDMMC_EISIER) Masked  */
#define   SDMMC_EISIER_ACMD_ENABLED_Val       _UINT16_(0x1)                                        /* (SDMMC_EISIER) Enabled  */
#define SDMMC_EISIER_ACMD_MASKED              (SDMMC_EISIER_ACMD_MASKED_Val << SDMMC_EISIER_ACMD_Pos) /* (SDMMC_EISIER) Masked Position  */
#define SDMMC_EISIER_ACMD_ENABLED             (SDMMC_EISIER_ACMD_ENABLED_Val << SDMMC_EISIER_ACMD_Pos) /* (SDMMC_EISIER) Enabled Position  */
#define SDMMC_EISIER_ADMA_Pos                 _UINT16_(9)                                          /* (SDMMC_EISIER) ADMA Error Signal Enable Position */
#define SDMMC_EISIER_ADMA_Msk                 (_UINT16_(0x1) << SDMMC_EISIER_ADMA_Pos)             /* (SDMMC_EISIER) ADMA Error Signal Enable Mask */
#define SDMMC_EISIER_ADMA(value)              (SDMMC_EISIER_ADMA_Msk & (_UINT16_(value) << SDMMC_EISIER_ADMA_Pos)) /* Assigment of value for ADMA in the SDMMC_EISIER register */
#define   SDMMC_EISIER_ADMA_MASKED_Val        _UINT16_(0x0)                                        /* (SDMMC_EISIER) Masked  */
#define   SDMMC_EISIER_ADMA_ENABLED_Val       _UINT16_(0x1)                                        /* (SDMMC_EISIER) Enabled  */
#define SDMMC_EISIER_ADMA_MASKED              (SDMMC_EISIER_ADMA_MASKED_Val << SDMMC_EISIER_ADMA_Pos) /* (SDMMC_EISIER) Masked Position  */
#define SDMMC_EISIER_ADMA_ENABLED             (SDMMC_EISIER_ADMA_ENABLED_Val << SDMMC_EISIER_ADMA_Pos) /* (SDMMC_EISIER) Enabled Position  */
#define SDMMC_EISIER_Msk                      _UINT16_(0x03FF)                                     /* (SDMMC_EISIER) Register Mask  */

/* EMMC mode */
#define SDMMC_EISIER_EMMC_BOOTAE_Pos          _UINT16_(12)                                         /* (SDMMC_EISIER) Boot Acknowledge Error Signal Enable Position */
#define SDMMC_EISIER_EMMC_BOOTAE_Msk          (_UINT16_(0x1) << SDMMC_EISIER_EMMC_BOOTAE_Pos)      /* (SDMMC_EISIER) Boot Acknowledge Error Signal Enable Mask */
#define SDMMC_EISIER_EMMC_BOOTAE(value)       (SDMMC_EISIER_EMMC_BOOTAE_Msk & (_UINT16_(value) << SDMMC_EISIER_EMMC_BOOTAE_Pos))
#define SDMMC_EISIER_EMMC_Msk                 _UINT16_(0x1000)                                      /* (SDMMC_EISIER_EMMC) Register Mask  */


/* -------- SDMMC_ACESR : (SDMMC Offset: 0x3C) ( R/ 16) Auto CMD Error Status -------- */
#define SDMMC_ACESR_RESETVALUE                _UINT16_(0x00)                                       /*  (SDMMC_ACESR) Auto CMD Error Status  Reset Value */

#define SDMMC_ACESR_ACMD12NE_Pos              _UINT16_(0)                                          /* (SDMMC_ACESR) Auto CMD12 Not Executed Position */
#define SDMMC_ACESR_ACMD12NE_Msk              (_UINT16_(0x1) << SDMMC_ACESR_ACMD12NE_Pos)          /* (SDMMC_ACESR) Auto CMD12 Not Executed Mask */
#define SDMMC_ACESR_ACMD12NE(value)           (SDMMC_ACESR_ACMD12NE_Msk & (_UINT16_(value) << SDMMC_ACESR_ACMD12NE_Pos)) /* Assigment of value for ACMD12NE in the SDMMC_ACESR register */
#define   SDMMC_ACESR_ACMD12NE_EXEC_Val       _UINT16_(0x0)                                        /* (SDMMC_ACESR) Executed  */
#define   SDMMC_ACESR_ACMD12NE_NOT_EXEC_Val   _UINT16_(0x1)                                        /* (SDMMC_ACESR) Not executed  */
#define SDMMC_ACESR_ACMD12NE_EXEC             (SDMMC_ACESR_ACMD12NE_EXEC_Val << SDMMC_ACESR_ACMD12NE_Pos) /* (SDMMC_ACESR) Executed Position  */
#define SDMMC_ACESR_ACMD12NE_NOT_EXEC         (SDMMC_ACESR_ACMD12NE_NOT_EXEC_Val << SDMMC_ACESR_ACMD12NE_Pos) /* (SDMMC_ACESR) Not executed Position  */
#define SDMMC_ACESR_ACMDTEO_Pos               _UINT16_(1)                                          /* (SDMMC_ACESR) Auto CMD Timeout Error Position */
#define SDMMC_ACESR_ACMDTEO_Msk               (_UINT16_(0x1) << SDMMC_ACESR_ACMDTEO_Pos)           /* (SDMMC_ACESR) Auto CMD Timeout Error Mask */
#define SDMMC_ACESR_ACMDTEO(value)            (SDMMC_ACESR_ACMDTEO_Msk & (_UINT16_(value) << SDMMC_ACESR_ACMDTEO_Pos)) /* Assigment of value for ACMDTEO in the SDMMC_ACESR register */
#define   SDMMC_ACESR_ACMDTEO_NO_Val          _UINT16_(0x0)                                        /* (SDMMC_ACESR) No error  */
#define   SDMMC_ACESR_ACMDTEO_YES_Val         _UINT16_(0x1)                                        /* (SDMMC_ACESR) Timeout  */
#define SDMMC_ACESR_ACMDTEO_NO                (SDMMC_ACESR_ACMDTEO_NO_Val << SDMMC_ACESR_ACMDTEO_Pos) /* (SDMMC_ACESR) No error Position  */
#define SDMMC_ACESR_ACMDTEO_YES               (SDMMC_ACESR_ACMDTEO_YES_Val << SDMMC_ACESR_ACMDTEO_Pos) /* (SDMMC_ACESR) Timeout Position  */
#define SDMMC_ACESR_ACMDCRC_Pos               _UINT16_(2)                                          /* (SDMMC_ACESR) Auto CMD CRC Error Position */
#define SDMMC_ACESR_ACMDCRC_Msk               (_UINT16_(0x1) << SDMMC_ACESR_ACMDCRC_Pos)           /* (SDMMC_ACESR) Auto CMD CRC Error Mask */
#define SDMMC_ACESR_ACMDCRC(value)            (SDMMC_ACESR_ACMDCRC_Msk & (_UINT16_(value) << SDMMC_ACESR_ACMDCRC_Pos)) /* Assigment of value for ACMDCRC in the SDMMC_ACESR register */
#define   SDMMC_ACESR_ACMDCRC_NO_Val          _UINT16_(0x0)                                        /* (SDMMC_ACESR) No error  */
#define   SDMMC_ACESR_ACMDCRC_YES_Val         _UINT16_(0x1)                                        /* (SDMMC_ACESR) CRC Error Generated  */
#define SDMMC_ACESR_ACMDCRC_NO                (SDMMC_ACESR_ACMDCRC_NO_Val << SDMMC_ACESR_ACMDCRC_Pos) /* (SDMMC_ACESR) No error Position  */
#define SDMMC_ACESR_ACMDCRC_YES               (SDMMC_ACESR_ACMDCRC_YES_Val << SDMMC_ACESR_ACMDCRC_Pos) /* (SDMMC_ACESR) CRC Error Generated Position  */
#define SDMMC_ACESR_ACMDEND_Pos               _UINT16_(3)                                          /* (SDMMC_ACESR) Auto CMD End Bit Error Position */
#define SDMMC_ACESR_ACMDEND_Msk               (_UINT16_(0x1) << SDMMC_ACESR_ACMDEND_Pos)           /* (SDMMC_ACESR) Auto CMD End Bit Error Mask */
#define SDMMC_ACESR_ACMDEND(value)            (SDMMC_ACESR_ACMDEND_Msk & (_UINT16_(value) << SDMMC_ACESR_ACMDEND_Pos)) /* Assigment of value for ACMDEND in the SDMMC_ACESR register */
#define   SDMMC_ACESR_ACMDEND_NO_Val          _UINT16_(0x0)                                        /* (SDMMC_ACESR) No error  */
#define   SDMMC_ACESR_ACMDEND_YES_Val         _UINT16_(0x1)                                        /* (SDMMC_ACESR) End Bit Error Generated  */
#define SDMMC_ACESR_ACMDEND_NO                (SDMMC_ACESR_ACMDEND_NO_Val << SDMMC_ACESR_ACMDEND_Pos) /* (SDMMC_ACESR) No error Position  */
#define SDMMC_ACESR_ACMDEND_YES               (SDMMC_ACESR_ACMDEND_YES_Val << SDMMC_ACESR_ACMDEND_Pos) /* (SDMMC_ACESR) End Bit Error Generated Position  */
#define SDMMC_ACESR_ACMDIDX_Pos               _UINT16_(4)                                          /* (SDMMC_ACESR) Auto CMD Index Error Position */
#define SDMMC_ACESR_ACMDIDX_Msk               (_UINT16_(0x1) << SDMMC_ACESR_ACMDIDX_Pos)           /* (SDMMC_ACESR) Auto CMD Index Error Mask */
#define SDMMC_ACESR_ACMDIDX(value)            (SDMMC_ACESR_ACMDIDX_Msk & (_UINT16_(value) << SDMMC_ACESR_ACMDIDX_Pos)) /* Assigment of value for ACMDIDX in the SDMMC_ACESR register */
#define   SDMMC_ACESR_ACMDIDX_NO_Val          _UINT16_(0x0)                                        /* (SDMMC_ACESR) No error  */
#define   SDMMC_ACESR_ACMDIDX_YES_Val         _UINT16_(0x1)                                        /* (SDMMC_ACESR) Error  */
#define SDMMC_ACESR_ACMDIDX_NO                (SDMMC_ACESR_ACMDIDX_NO_Val << SDMMC_ACESR_ACMDIDX_Pos) /* (SDMMC_ACESR) No error Position  */
#define SDMMC_ACESR_ACMDIDX_YES               (SDMMC_ACESR_ACMDIDX_YES_Val << SDMMC_ACESR_ACMDIDX_Pos) /* (SDMMC_ACESR) Error Position  */
#define SDMMC_ACESR_CMDNI_Pos                 _UINT16_(7)                                          /* (SDMMC_ACESR) Command not Issued By Auto CMD12 Error Position */
#define SDMMC_ACESR_CMDNI_Msk                 (_UINT16_(0x1) << SDMMC_ACESR_CMDNI_Pos)             /* (SDMMC_ACESR) Command not Issued By Auto CMD12 Error Mask */
#define SDMMC_ACESR_CMDNI(value)              (SDMMC_ACESR_CMDNI_Msk & (_UINT16_(value) << SDMMC_ACESR_CMDNI_Pos)) /* Assigment of value for CMDNI in the SDMMC_ACESR register */
#define   SDMMC_ACESR_CMDNI_OK_Val            _UINT16_(0x0)                                        /* (SDMMC_ACESR) No error  */
#define   SDMMC_ACESR_CMDNI_NOT_ISSUED_Val    _UINT16_(0x1)                                        /* (SDMMC_ACESR) Not Issued  */
#define SDMMC_ACESR_CMDNI_OK                  (SDMMC_ACESR_CMDNI_OK_Val << SDMMC_ACESR_CMDNI_Pos)  /* (SDMMC_ACESR) No error Position  */
#define SDMMC_ACESR_CMDNI_NOT_ISSUED          (SDMMC_ACESR_CMDNI_NOT_ISSUED_Val << SDMMC_ACESR_CMDNI_Pos) /* (SDMMC_ACESR) Not Issued Position  */
#define SDMMC_ACESR_Msk                       _UINT16_(0x009F)                                     /* (SDMMC_ACESR) Register Mask  */


/* -------- SDMMC_HC2R : (SDMMC Offset: 0x3E) (R/W 16) Host Control 2 -------- */
#define SDMMC_HC2R_RESETVALUE                 _UINT16_(0x00)                                       /*  (SDMMC_HC2R) Host Control 2  Reset Value */

#define SDMMC_HC2R_UHSMS_Pos                  _UINT16_(0)                                          /* (SDMMC_HC2R) UHS Mode Select Position */
#define SDMMC_HC2R_UHSMS_Msk                  (_UINT16_(0x7) << SDMMC_HC2R_UHSMS_Pos)              /* (SDMMC_HC2R) UHS Mode Select Mask */
#define SDMMC_HC2R_UHSMS(value)               (SDMMC_HC2R_UHSMS_Msk & (_UINT16_(value) << SDMMC_HC2R_UHSMS_Pos)) /* Assigment of value for UHSMS in the SDMMC_HC2R register */
#define   SDMMC_HC2R_UHSMS_SDR12_Val          _UINT16_(0x0)                                        /* (SDMMC_HC2R) SDR12  */
#define   SDMMC_HC2R_UHSMS_SDR25_Val          _UINT16_(0x1)                                        /* (SDMMC_HC2R) SDR25  */
#define   SDMMC_HC2R_UHSMS_SDR50_Val          _UINT16_(0x2)                                        /* (SDMMC_HC2R) SDR50  */
#define   SDMMC_HC2R_UHSMS_SDR104_Val         _UINT16_(0x3)                                        /* (SDMMC_HC2R) SDR104  */
#define   SDMMC_HC2R_UHSMS_DDR50_Val          _UINT16_(0x4)                                        /* (SDMMC_HC2R) DDR50  */
#define SDMMC_HC2R_UHSMS_SDR12                (SDMMC_HC2R_UHSMS_SDR12_Val << SDMMC_HC2R_UHSMS_Pos) /* (SDMMC_HC2R) SDR12 Position  */
#define SDMMC_HC2R_UHSMS_SDR25                (SDMMC_HC2R_UHSMS_SDR25_Val << SDMMC_HC2R_UHSMS_Pos) /* (SDMMC_HC2R) SDR25 Position  */
#define SDMMC_HC2R_UHSMS_SDR50                (SDMMC_HC2R_UHSMS_SDR50_Val << SDMMC_HC2R_UHSMS_Pos) /* (SDMMC_HC2R) SDR50 Position  */
#define SDMMC_HC2R_UHSMS_SDR104               (SDMMC_HC2R_UHSMS_SDR104_Val << SDMMC_HC2R_UHSMS_Pos) /* (SDMMC_HC2R) SDR104 Position  */
#define SDMMC_HC2R_UHSMS_DDR50                (SDMMC_HC2R_UHSMS_DDR50_Val << SDMMC_HC2R_UHSMS_Pos) /* (SDMMC_HC2R) DDR50 Position  */
#define SDMMC_HC2R_VS18EN_Pos                 _UINT16_(3)                                          /* (SDMMC_HC2R) 1.8V Signaling Enable Position */
#define SDMMC_HC2R_VS18EN_Msk                 (_UINT16_(0x1) << SDMMC_HC2R_VS18EN_Pos)             /* (SDMMC_HC2R) 1.8V Signaling Enable Mask */
#define SDMMC_HC2R_VS18EN(value)              (SDMMC_HC2R_VS18EN_Msk & (_UINT16_(value) << SDMMC_HC2R_VS18EN_Pos)) /* Assigment of value for VS18EN in the SDMMC_HC2R register */
#define   SDMMC_HC2R_VS18EN_S33V_Val          _UINT16_(0x0)                                        /* (SDMMC_HC2R) 3.3V Signaling  */
#define   SDMMC_HC2R_VS18EN_S18V_Val          _UINT16_(0x1)                                        /* (SDMMC_HC2R) 1.8V Signaling  */
#define SDMMC_HC2R_VS18EN_S33V                (SDMMC_HC2R_VS18EN_S33V_Val << SDMMC_HC2R_VS18EN_Pos) /* (SDMMC_HC2R) 3.3V Signaling Position  */
#define SDMMC_HC2R_VS18EN_S18V                (SDMMC_HC2R_VS18EN_S18V_Val << SDMMC_HC2R_VS18EN_Pos) /* (SDMMC_HC2R) 1.8V Signaling Position  */
#define SDMMC_HC2R_DRVSEL_Pos                 _UINT16_(4)                                          /* (SDMMC_HC2R) Driver Strength Select Position */
#define SDMMC_HC2R_DRVSEL_Msk                 (_UINT16_(0x3) << SDMMC_HC2R_DRVSEL_Pos)             /* (SDMMC_HC2R) Driver Strength Select Mask */
#define SDMMC_HC2R_DRVSEL(value)              (SDMMC_HC2R_DRVSEL_Msk & (_UINT16_(value) << SDMMC_HC2R_DRVSEL_Pos)) /* Assigment of value for DRVSEL in the SDMMC_HC2R register */
#define   SDMMC_HC2R_DRVSEL_B_Val             _UINT16_(0x0)                                        /* (SDMMC_HC2R) Driver Type B is Selected (Default)  */
#define   SDMMC_HC2R_DRVSEL_A_Val             _UINT16_(0x1)                                        /* (SDMMC_HC2R) Driver Type A is Selected  */
#define   SDMMC_HC2R_DRVSEL_C_Val             _UINT16_(0x2)                                        /* (SDMMC_HC2R) Driver Type C is Selected  */
#define   SDMMC_HC2R_DRVSEL_D_Val             _UINT16_(0x3)                                        /* (SDMMC_HC2R) Driver Type D is Selected  */
#define SDMMC_HC2R_DRVSEL_B                   (SDMMC_HC2R_DRVSEL_B_Val << SDMMC_HC2R_DRVSEL_Pos)   /* (SDMMC_HC2R) Driver Type B is Selected (Default) Position  */
#define SDMMC_HC2R_DRVSEL_A                   (SDMMC_HC2R_DRVSEL_A_Val << SDMMC_HC2R_DRVSEL_Pos)   /* (SDMMC_HC2R) Driver Type A is Selected Position  */
#define SDMMC_HC2R_DRVSEL_C                   (SDMMC_HC2R_DRVSEL_C_Val << SDMMC_HC2R_DRVSEL_Pos)   /* (SDMMC_HC2R) Driver Type C is Selected Position  */
#define SDMMC_HC2R_DRVSEL_D                   (SDMMC_HC2R_DRVSEL_D_Val << SDMMC_HC2R_DRVSEL_Pos)   /* (SDMMC_HC2R) Driver Type D is Selected Position  */
#define SDMMC_HC2R_EXTUN_Pos                  _UINT16_(6)                                          /* (SDMMC_HC2R) Execute Tuning Position */
#define SDMMC_HC2R_EXTUN_Msk                  (_UINT16_(0x1) << SDMMC_HC2R_EXTUN_Pos)              /* (SDMMC_HC2R) Execute Tuning Mask */
#define SDMMC_HC2R_EXTUN(value)               (SDMMC_HC2R_EXTUN_Msk & (_UINT16_(value) << SDMMC_HC2R_EXTUN_Pos)) /* Assigment of value for EXTUN in the SDMMC_HC2R register */
#define   SDMMC_HC2R_EXTUN_NO_Val             _UINT16_(0x0)                                        /* (SDMMC_HC2R) Not Tuned or Tuning Completed  */
#define   SDMMC_HC2R_EXTUN_REQUESTED_Val      _UINT16_(0x1)                                        /* (SDMMC_HC2R) Execute Tuning  */
#define SDMMC_HC2R_EXTUN_NO                   (SDMMC_HC2R_EXTUN_NO_Val << SDMMC_HC2R_EXTUN_Pos)    /* (SDMMC_HC2R) Not Tuned or Tuning Completed Position  */
#define SDMMC_HC2R_EXTUN_REQUESTED            (SDMMC_HC2R_EXTUN_REQUESTED_Val << SDMMC_HC2R_EXTUN_Pos) /* (SDMMC_HC2R) Execute Tuning Position  */
#define SDMMC_HC2R_SLCKSEL_Pos                _UINT16_(7)                                          /* (SDMMC_HC2R) Sampling Clock Select Position */
#define SDMMC_HC2R_SLCKSEL_Msk                (_UINT16_(0x1) << SDMMC_HC2R_SLCKSEL_Pos)            /* (SDMMC_HC2R) Sampling Clock Select Mask */
#define SDMMC_HC2R_SLCKSEL(value)             (SDMMC_HC2R_SLCKSEL_Msk & (_UINT16_(value) << SDMMC_HC2R_SLCKSEL_Pos)) /* Assigment of value for SLCKSEL in the SDMMC_HC2R register */
#define   SDMMC_HC2R_SLCKSEL_FIXED_Val        _UINT16_(0x0)                                        /* (SDMMC_HC2R) Fixed clock is used to sample data  */
#define   SDMMC_HC2R_SLCKSEL_TUNED_Val        _UINT16_(0x1)                                        /* (SDMMC_HC2R) Tuned clock is used to sample data  */
#define SDMMC_HC2R_SLCKSEL_FIXED              (SDMMC_HC2R_SLCKSEL_FIXED_Val << SDMMC_HC2R_SLCKSEL_Pos) /* (SDMMC_HC2R) Fixed clock is used to sample data Position  */
#define SDMMC_HC2R_SLCKSEL_TUNED              (SDMMC_HC2R_SLCKSEL_TUNED_Val << SDMMC_HC2R_SLCKSEL_Pos) /* (SDMMC_HC2R) Tuned clock is used to sample data Position  */
#define SDMMC_HC2R_ASINTEN_Pos                _UINT16_(14)                                         /* (SDMMC_HC2R) Asynchronous Interrupt Enable Position */
#define SDMMC_HC2R_ASINTEN_Msk                (_UINT16_(0x1) << SDMMC_HC2R_ASINTEN_Pos)            /* (SDMMC_HC2R) Asynchronous Interrupt Enable Mask */
#define SDMMC_HC2R_ASINTEN(value)             (SDMMC_HC2R_ASINTEN_Msk & (_UINT16_(value) << SDMMC_HC2R_ASINTEN_Pos)) /* Assigment of value for ASINTEN in the SDMMC_HC2R register */
#define   SDMMC_HC2R_ASINTEN_DISABLED_Val     _UINT16_(0x0)                                        /* (SDMMC_HC2R) Disabled  */
#define   SDMMC_HC2R_ASINTEN_ENABLED_Val      _UINT16_(0x1)                                        /* (SDMMC_HC2R) Enabled  */
#define SDMMC_HC2R_ASINTEN_DISABLED           (SDMMC_HC2R_ASINTEN_DISABLED_Val << SDMMC_HC2R_ASINTEN_Pos) /* (SDMMC_HC2R) Disabled Position  */
#define SDMMC_HC2R_ASINTEN_ENABLED            (SDMMC_HC2R_ASINTEN_ENABLED_Val << SDMMC_HC2R_ASINTEN_Pos) /* (SDMMC_HC2R) Enabled Position  */
#define SDMMC_HC2R_PVALEN_Pos                 _UINT16_(15)                                         /* (SDMMC_HC2R) Preset Value Enable Position */
#define SDMMC_HC2R_PVALEN_Msk                 (_UINT16_(0x1) << SDMMC_HC2R_PVALEN_Pos)             /* (SDMMC_HC2R) Preset Value Enable Mask */
#define SDMMC_HC2R_PVALEN(value)              (SDMMC_HC2R_PVALEN_Msk & (_UINT16_(value) << SDMMC_HC2R_PVALEN_Pos)) /* Assigment of value for PVALEN in the SDMMC_HC2R register */
#define   SDMMC_HC2R_PVALEN_HOST_Val          _UINT16_(0x0)                                        /* (SDMMC_HC2R) SDCLK and Driver Strength are controlled by Host Controller  */
#define   SDMMC_HC2R_PVALEN_AUTO_Val          _UINT16_(0x1)                                        /* (SDMMC_HC2R) Automatic Selection by Preset Value is Enabled  */
#define SDMMC_HC2R_PVALEN_HOST                (SDMMC_HC2R_PVALEN_HOST_Val << SDMMC_HC2R_PVALEN_Pos) /* (SDMMC_HC2R) SDCLK and Driver Strength are controlled by Host Controller Position  */
#define SDMMC_HC2R_PVALEN_AUTO                (SDMMC_HC2R_PVALEN_AUTO_Val << SDMMC_HC2R_PVALEN_Pos) /* (SDMMC_HC2R) Automatic Selection by Preset Value is Enabled Position  */
#define SDMMC_HC2R_Msk                        _UINT16_(0xC0FF)                                     /* (SDMMC_HC2R) Register Mask  */

/* EMMC mode */
#define SDMMC_HC2R_EMMC_HS200EN_Pos           _UINT16_(0)                                          /* (SDMMC_HC2R) HS200 Mode Enable Position */
#define SDMMC_HC2R_EMMC_HS200EN_Msk           (_UINT16_(0xF) << SDMMC_HC2R_EMMC_HS200EN_Pos)       /* (SDMMC_HC2R) HS200 Mode Enable Mask */
#define SDMMC_HC2R_EMMC_HS200EN(value)        (SDMMC_HC2R_EMMC_HS200EN_Msk & (_UINT16_(value) << SDMMC_HC2R_EMMC_HS200EN_Pos))
#define   SDMMC_HC2R_EMMC_HS200EN_SDR12_Val   _UINT16_(0x0)                                        /* (SDMMC_HC2R) SDR12  */
#define   SDMMC_HC2R_EMMC_HS200EN_SDR25_Val   _UINT16_(0x1)                                        /* (SDMMC_HC2R) SDR25  */
#define   SDMMC_HC2R_EMMC_HS200EN_SDR50_Val   _UINT16_(0x2)                                        /* (SDMMC_HC2R) SDR50  */
#define   SDMMC_HC2R_EMMC_HS200EN_SDR104_Val  _UINT16_(0x3)                                        /* (SDMMC_HC2R) SDR104  */
#define   SDMMC_HC2R_EMMC_HS200EN_DDR50_Val   _UINT16_(0x4)                                        /* (SDMMC_HC2R) DDR50  */
#define SDMMC_HC2R_EMMC_HS200EN_SDR12         (SDMMC_HC2R_EMMC_HS200EN_SDR12_Val << SDMMC_HC2R_EMMC_HS200EN_Pos) /* (SDMMC_HC2R) SDR12 Position  */
#define SDMMC_HC2R_EMMC_HS200EN_SDR25         (SDMMC_HC2R_EMMC_HS200EN_SDR25_Val << SDMMC_HC2R_EMMC_HS200EN_Pos) /* (SDMMC_HC2R) SDR25 Position  */
#define SDMMC_HC2R_EMMC_HS200EN_SDR50         (SDMMC_HC2R_EMMC_HS200EN_SDR50_Val << SDMMC_HC2R_EMMC_HS200EN_Pos) /* (SDMMC_HC2R) SDR50 Position  */
#define SDMMC_HC2R_EMMC_HS200EN_SDR104        (SDMMC_HC2R_EMMC_HS200EN_SDR104_Val << SDMMC_HC2R_EMMC_HS200EN_Pos) /* (SDMMC_HC2R) SDR104 Position  */
#define SDMMC_HC2R_EMMC_HS200EN_DDR50         (SDMMC_HC2R_EMMC_HS200EN_DDR50_Val << SDMMC_HC2R_EMMC_HS200EN_Pos) /* (SDMMC_HC2R) DDR50 Position  */
#define SDMMC_HC2R_EMMC_Msk                   _UINT16_(0x000F)                                      /* (SDMMC_HC2R_EMMC) Register Mask  */


/* -------- SDMMC_CA0R : (SDMMC Offset: 0x40) (R/W 32) Capabilities 0 -------- */
#define SDMMC_CA0R_RESETVALUE                 _UINT32_(0x27E8008C)                                 /*  (SDMMC_CA0R) Capabilities 0  Reset Value */

#define SDMMC_CA0R_TEOCLKF_Pos                _UINT32_(0)                                          /* (SDMMC_CA0R) Timeout Clock Frequency Position */
#define SDMMC_CA0R_TEOCLKF_Msk                (_UINT32_(0x3F) << SDMMC_CA0R_TEOCLKF_Pos)           /* (SDMMC_CA0R) Timeout Clock Frequency Mask */
#define SDMMC_CA0R_TEOCLKF(value)             (SDMMC_CA0R_TEOCLKF_Msk & (_UINT32_(value) << SDMMC_CA0R_TEOCLKF_Pos)) /* Assigment of value for TEOCLKF in the SDMMC_CA0R register */
#define   SDMMC_CA0R_TEOCLKF_OTHER_Val        _UINT32_(0x0)                                        /* (SDMMC_CA0R) Get information via another method  */
#define SDMMC_CA0R_TEOCLKF_OTHER              (SDMMC_CA0R_TEOCLKF_OTHER_Val << SDMMC_CA0R_TEOCLKF_Pos) /* (SDMMC_CA0R) Get information via another method Position  */
#define SDMMC_CA0R_TEOCLKU_Pos                _UINT32_(7)                                          /* (SDMMC_CA0R) Timeout Clock Unit Position */
#define SDMMC_CA0R_TEOCLKU_Msk                (_UINT32_(0x1) << SDMMC_CA0R_TEOCLKU_Pos)            /* (SDMMC_CA0R) Timeout Clock Unit Mask */
#define SDMMC_CA0R_TEOCLKU(value)             (SDMMC_CA0R_TEOCLKU_Msk & (_UINT32_(value) << SDMMC_CA0R_TEOCLKU_Pos)) /* Assigment of value for TEOCLKU in the SDMMC_CA0R register */
#define   SDMMC_CA0R_TEOCLKU_KHZ_Val          _UINT32_(0x0)                                        /* (SDMMC_CA0R) KHz  */
#define   SDMMC_CA0R_TEOCLKU_MHZ_Val          _UINT32_(0x1)                                        /* (SDMMC_CA0R) MHz  */
#define SDMMC_CA0R_TEOCLKU_KHZ                (SDMMC_CA0R_TEOCLKU_KHZ_Val << SDMMC_CA0R_TEOCLKU_Pos) /* (SDMMC_CA0R) KHz Position  */
#define SDMMC_CA0R_TEOCLKU_MHZ                (SDMMC_CA0R_TEOCLKU_MHZ_Val << SDMMC_CA0R_TEOCLKU_Pos) /* (SDMMC_CA0R) MHz Position  */
#define SDMMC_CA0R_BASECLKF_Pos               _UINT32_(8)                                          /* (SDMMC_CA0R) Base Clock Frequency Position */
#define SDMMC_CA0R_BASECLKF_Msk               (_UINT32_(0xFF) << SDMMC_CA0R_BASECLKF_Pos)          /* (SDMMC_CA0R) Base Clock Frequency Mask */
#define SDMMC_CA0R_BASECLKF(value)            (SDMMC_CA0R_BASECLKF_Msk & (_UINT32_(value) << SDMMC_CA0R_BASECLKF_Pos)) /* Assigment of value for BASECLKF in the SDMMC_CA0R register */
#define   SDMMC_CA0R_BASECLKF_OTHER_Val       _UINT32_(0x0)                                        /* (SDMMC_CA0R) Get information via another method  */
#define SDMMC_CA0R_BASECLKF_OTHER             (SDMMC_CA0R_BASECLKF_OTHER_Val << SDMMC_CA0R_BASECLKF_Pos) /* (SDMMC_CA0R) Get information via another method Position  */
#define SDMMC_CA0R_MAXBLKL_Pos                _UINT32_(16)                                         /* (SDMMC_CA0R) Max Block Length Position */
#define SDMMC_CA0R_MAXBLKL_Msk                (_UINT32_(0x3) << SDMMC_CA0R_MAXBLKL_Pos)            /* (SDMMC_CA0R) Max Block Length Mask */
#define SDMMC_CA0R_MAXBLKL(value)             (SDMMC_CA0R_MAXBLKL_Msk & (_UINT32_(value) << SDMMC_CA0R_MAXBLKL_Pos)) /* Assigment of value for MAXBLKL in the SDMMC_CA0R register */
#define   SDMMC_CA0R_MAXBLKL_512_Val          _UINT32_(0x0)                                        /* (SDMMC_CA0R) 512 bytes  */
#define   SDMMC_CA0R_MAXBLKL_1024_Val         _UINT32_(0x1)                                        /* (SDMMC_CA0R) 1024 bytes  */
#define   SDMMC_CA0R_MAXBLKL_2048_Val         _UINT32_(0x2)                                        /* (SDMMC_CA0R) 2048 bytes  */
#define SDMMC_CA0R_MAXBLKL_512                (SDMMC_CA0R_MAXBLKL_512_Val << SDMMC_CA0R_MAXBLKL_Pos) /* (SDMMC_CA0R) 512 bytes Position  */
#define SDMMC_CA0R_MAXBLKL_1024               (SDMMC_CA0R_MAXBLKL_1024_Val << SDMMC_CA0R_MAXBLKL_Pos) /* (SDMMC_CA0R) 1024 bytes Position  */
#define SDMMC_CA0R_MAXBLKL_2048               (SDMMC_CA0R_MAXBLKL_2048_Val << SDMMC_CA0R_MAXBLKL_Pos) /* (SDMMC_CA0R) 2048 bytes Position  */
#define SDMMC_CA0R_ED8SUP_Pos                 _UINT32_(18)                                         /* (SDMMC_CA0R) 8-bit Support for Embedded Device Position */
#define SDMMC_CA0R_ED8SUP_Msk                 (_UINT32_(0x1) << SDMMC_CA0R_ED8SUP_Pos)             /* (SDMMC_CA0R) 8-bit Support for Embedded Device Mask */
#define SDMMC_CA0R_ED8SUP(value)              (SDMMC_CA0R_ED8SUP_Msk & (_UINT32_(value) << SDMMC_CA0R_ED8SUP_Pos)) /* Assigment of value for ED8SUP in the SDMMC_CA0R register */
#define   SDMMC_CA0R_ED8SUP_NO_Val            _UINT32_(0x0)                                        /* (SDMMC_CA0R) 8-bit Bus Width not Supported  */
#define   SDMMC_CA0R_ED8SUP_YES_Val           _UINT32_(0x1)                                        /* (SDMMC_CA0R) 8-bit Bus Width Supported  */
#define SDMMC_CA0R_ED8SUP_NO                  (SDMMC_CA0R_ED8SUP_NO_Val << SDMMC_CA0R_ED8SUP_Pos)  /* (SDMMC_CA0R) 8-bit Bus Width not Supported Position  */
#define SDMMC_CA0R_ED8SUP_YES                 (SDMMC_CA0R_ED8SUP_YES_Val << SDMMC_CA0R_ED8SUP_Pos) /* (SDMMC_CA0R) 8-bit Bus Width Supported Position  */
#define SDMMC_CA0R_ADMA2SUP_Pos               _UINT32_(19)                                         /* (SDMMC_CA0R) ADMA2 Support Position */
#define SDMMC_CA0R_ADMA2SUP_Msk               (_UINT32_(0x1) << SDMMC_CA0R_ADMA2SUP_Pos)           /* (SDMMC_CA0R) ADMA2 Support Mask */
#define SDMMC_CA0R_ADMA2SUP(value)            (SDMMC_CA0R_ADMA2SUP_Msk & (_UINT32_(value) << SDMMC_CA0R_ADMA2SUP_Pos)) /* Assigment of value for ADMA2SUP in the SDMMC_CA0R register */
#define   SDMMC_CA0R_ADMA2SUP_NO_Val          _UINT32_(0x0)                                        /* (SDMMC_CA0R) ADMA2 not Supported  */
#define   SDMMC_CA0R_ADMA2SUP_YES_Val         _UINT32_(0x1)                                        /* (SDMMC_CA0R) ADMA2 Supported  */
#define SDMMC_CA0R_ADMA2SUP_NO                (SDMMC_CA0R_ADMA2SUP_NO_Val << SDMMC_CA0R_ADMA2SUP_Pos) /* (SDMMC_CA0R) ADMA2 not Supported Position  */
#define SDMMC_CA0R_ADMA2SUP_YES               (SDMMC_CA0R_ADMA2SUP_YES_Val << SDMMC_CA0R_ADMA2SUP_Pos) /* (SDMMC_CA0R) ADMA2 Supported Position  */
#define SDMMC_CA0R_HSSUP_Pos                  _UINT32_(21)                                         /* (SDMMC_CA0R) High Speed Support Position */
#define SDMMC_CA0R_HSSUP_Msk                  (_UINT32_(0x1) << SDMMC_CA0R_HSSUP_Pos)              /* (SDMMC_CA0R) High Speed Support Mask */
#define SDMMC_CA0R_HSSUP(value)               (SDMMC_CA0R_HSSUP_Msk & (_UINT32_(value) << SDMMC_CA0R_HSSUP_Pos)) /* Assigment of value for HSSUP in the SDMMC_CA0R register */
#define   SDMMC_CA0R_HSSUP_NO_Val             _UINT32_(0x0)                                        /* (SDMMC_CA0R) High Speed not Supported  */
#define   SDMMC_CA0R_HSSUP_YES_Val            _UINT32_(0x1)                                        /* (SDMMC_CA0R) High Speed Supported  */
#define SDMMC_CA0R_HSSUP_NO                   (SDMMC_CA0R_HSSUP_NO_Val << SDMMC_CA0R_HSSUP_Pos)    /* (SDMMC_CA0R) High Speed not Supported Position  */
#define SDMMC_CA0R_HSSUP_YES                  (SDMMC_CA0R_HSSUP_YES_Val << SDMMC_CA0R_HSSUP_Pos)   /* (SDMMC_CA0R) High Speed Supported Position  */
#define SDMMC_CA0R_SDMASUP_Pos                _UINT32_(22)                                         /* (SDMMC_CA0R) SDMA Support Position */
#define SDMMC_CA0R_SDMASUP_Msk                (_UINT32_(0x1) << SDMMC_CA0R_SDMASUP_Pos)            /* (SDMMC_CA0R) SDMA Support Mask */
#define SDMMC_CA0R_SDMASUP(value)             (SDMMC_CA0R_SDMASUP_Msk & (_UINT32_(value) << SDMMC_CA0R_SDMASUP_Pos)) /* Assigment of value for SDMASUP in the SDMMC_CA0R register */
#define   SDMMC_CA0R_SDMASUP_NO_Val           _UINT32_(0x0)                                        /* (SDMMC_CA0R) SDMA not Supported  */
#define   SDMMC_CA0R_SDMASUP_YES_Val          _UINT32_(0x1)                                        /* (SDMMC_CA0R) SDMA Supported  */
#define SDMMC_CA0R_SDMASUP_NO                 (SDMMC_CA0R_SDMASUP_NO_Val << SDMMC_CA0R_SDMASUP_Pos) /* (SDMMC_CA0R) SDMA not Supported Position  */
#define SDMMC_CA0R_SDMASUP_YES                (SDMMC_CA0R_SDMASUP_YES_Val << SDMMC_CA0R_SDMASUP_Pos) /* (SDMMC_CA0R) SDMA Supported Position  */
#define SDMMC_CA0R_SRSUP_Pos                  _UINT32_(23)                                         /* (SDMMC_CA0R) Suspend/Resume Support Position */
#define SDMMC_CA0R_SRSUP_Msk                  (_UINT32_(0x1) << SDMMC_CA0R_SRSUP_Pos)              /* (SDMMC_CA0R) Suspend/Resume Support Mask */
#define SDMMC_CA0R_SRSUP(value)               (SDMMC_CA0R_SRSUP_Msk & (_UINT32_(value) << SDMMC_CA0R_SRSUP_Pos)) /* Assigment of value for SRSUP in the SDMMC_CA0R register */
#define   SDMMC_CA0R_SRSUP_NO_Val             _UINT32_(0x0)                                        /* (SDMMC_CA0R) Suspend/Resume not Supported  */
#define   SDMMC_CA0R_SRSUP_YES_Val            _UINT32_(0x1)                                        /* (SDMMC_CA0R) Suspend/Resume Supported  */
#define SDMMC_CA0R_SRSUP_NO                   (SDMMC_CA0R_SRSUP_NO_Val << SDMMC_CA0R_SRSUP_Pos)    /* (SDMMC_CA0R) Suspend/Resume not Supported Position  */
#define SDMMC_CA0R_SRSUP_YES                  (SDMMC_CA0R_SRSUP_YES_Val << SDMMC_CA0R_SRSUP_Pos)   /* (SDMMC_CA0R) Suspend/Resume Supported Position  */
#define SDMMC_CA0R_V33VSUP_Pos                _UINT32_(24)                                         /* (SDMMC_CA0R) Voltage Support 3.3V Position */
#define SDMMC_CA0R_V33VSUP_Msk                (_UINT32_(0x1) << SDMMC_CA0R_V33VSUP_Pos)            /* (SDMMC_CA0R) Voltage Support 3.3V Mask */
#define SDMMC_CA0R_V33VSUP(value)             (SDMMC_CA0R_V33VSUP_Msk & (_UINT32_(value) << SDMMC_CA0R_V33VSUP_Pos)) /* Assigment of value for V33VSUP in the SDMMC_CA0R register */
#define   SDMMC_CA0R_V33VSUP_NO_Val           _UINT32_(0x0)                                        /* (SDMMC_CA0R) 3.3V Not Supported  */
#define   SDMMC_CA0R_V33VSUP_YES_Val          _UINT32_(0x1)                                        /* (SDMMC_CA0R) 3.3V Supported  */
#define SDMMC_CA0R_V33VSUP_NO                 (SDMMC_CA0R_V33VSUP_NO_Val << SDMMC_CA0R_V33VSUP_Pos) /* (SDMMC_CA0R) 3.3V Not Supported Position  */
#define SDMMC_CA0R_V33VSUP_YES                (SDMMC_CA0R_V33VSUP_YES_Val << SDMMC_CA0R_V33VSUP_Pos) /* (SDMMC_CA0R) 3.3V Supported Position  */
#define SDMMC_CA0R_V30VSUP_Pos                _UINT32_(25)                                         /* (SDMMC_CA0R) Voltage Support 3.0V Position */
#define SDMMC_CA0R_V30VSUP_Msk                (_UINT32_(0x1) << SDMMC_CA0R_V30VSUP_Pos)            /* (SDMMC_CA0R) Voltage Support 3.0V Mask */
#define SDMMC_CA0R_V30VSUP(value)             (SDMMC_CA0R_V30VSUP_Msk & (_UINT32_(value) << SDMMC_CA0R_V30VSUP_Pos)) /* Assigment of value for V30VSUP in the SDMMC_CA0R register */
#define   SDMMC_CA0R_V30VSUP_NO_Val           _UINT32_(0x0)                                        /* (SDMMC_CA0R) 3.0V Not Supported  */
#define   SDMMC_CA0R_V30VSUP_YES_Val          _UINT32_(0x1)                                        /* (SDMMC_CA0R) 3.0V Supported  */
#define SDMMC_CA0R_V30VSUP_NO                 (SDMMC_CA0R_V30VSUP_NO_Val << SDMMC_CA0R_V30VSUP_Pos) /* (SDMMC_CA0R) 3.0V Not Supported Position  */
#define SDMMC_CA0R_V30VSUP_YES                (SDMMC_CA0R_V30VSUP_YES_Val << SDMMC_CA0R_V30VSUP_Pos) /* (SDMMC_CA0R) 3.0V Supported Position  */
#define SDMMC_CA0R_V18VSUP_Pos                _UINT32_(26)                                         /* (SDMMC_CA0R) Voltage Support 1.8V Position */
#define SDMMC_CA0R_V18VSUP_Msk                (_UINT32_(0x1) << SDMMC_CA0R_V18VSUP_Pos)            /* (SDMMC_CA0R) Voltage Support 1.8V Mask */
#define SDMMC_CA0R_V18VSUP(value)             (SDMMC_CA0R_V18VSUP_Msk & (_UINT32_(value) << SDMMC_CA0R_V18VSUP_Pos)) /* Assigment of value for V18VSUP in the SDMMC_CA0R register */
#define   SDMMC_CA0R_V18VSUP_NO_Val           _UINT32_(0x0)                                        /* (SDMMC_CA0R) 1.8V Not Supported  */
#define   SDMMC_CA0R_V18VSUP_YES_Val          _UINT32_(0x1)                                        /* (SDMMC_CA0R) 1.8V Supported  */
#define SDMMC_CA0R_V18VSUP_NO                 (SDMMC_CA0R_V18VSUP_NO_Val << SDMMC_CA0R_V18VSUP_Pos) /* (SDMMC_CA0R) 1.8V Not Supported Position  */
#define SDMMC_CA0R_V18VSUP_YES                (SDMMC_CA0R_V18VSUP_YES_Val << SDMMC_CA0R_V18VSUP_Pos) /* (SDMMC_CA0R) 1.8V Supported Position  */
#define SDMMC_CA0R_SB64SUP_Pos                _UINT32_(28)                                         /* (SDMMC_CA0R) 64-Bit System Bus Support Position */
#define SDMMC_CA0R_SB64SUP_Msk                (_UINT32_(0x1) << SDMMC_CA0R_SB64SUP_Pos)            /* (SDMMC_CA0R) 64-Bit System Bus Support Mask */
#define SDMMC_CA0R_SB64SUP(value)             (SDMMC_CA0R_SB64SUP_Msk & (_UINT32_(value) << SDMMC_CA0R_SB64SUP_Pos)) /* Assigment of value for SB64SUP in the SDMMC_CA0R register */
#define   SDMMC_CA0R_SB64SUP_NO_Val           _UINT32_(0x0)                                        /* (SDMMC_CA0R) 32-bit Address Descriptors and System Bus  */
#define   SDMMC_CA0R_SB64SUP_YES_Val          _UINT32_(0x1)                                        /* (SDMMC_CA0R) 64-bit Address Descriptors and System Bus  */
#define SDMMC_CA0R_SB64SUP_NO                 (SDMMC_CA0R_SB64SUP_NO_Val << SDMMC_CA0R_SB64SUP_Pos) /* (SDMMC_CA0R) 32-bit Address Descriptors and System Bus Position  */
#define SDMMC_CA0R_SB64SUP_YES                (SDMMC_CA0R_SB64SUP_YES_Val << SDMMC_CA0R_SB64SUP_Pos) /* (SDMMC_CA0R) 64-bit Address Descriptors and System Bus Position  */
#define SDMMC_CA0R_ASINTSUP_Pos               _UINT32_(29)                                         /* (SDMMC_CA0R) Asynchronous Interrupt Support Position */
#define SDMMC_CA0R_ASINTSUP_Msk               (_UINT32_(0x1) << SDMMC_CA0R_ASINTSUP_Pos)           /* (SDMMC_CA0R) Asynchronous Interrupt Support Mask */
#define SDMMC_CA0R_ASINTSUP(value)            (SDMMC_CA0R_ASINTSUP_Msk & (_UINT32_(value) << SDMMC_CA0R_ASINTSUP_Pos)) /* Assigment of value for ASINTSUP in the SDMMC_CA0R register */
#define   SDMMC_CA0R_ASINTSUP_NO_Val          _UINT32_(0x0)                                        /* (SDMMC_CA0R) Asynchronous Interrupt not Supported  */
#define   SDMMC_CA0R_ASINTSUP_YES_Val         _UINT32_(0x1)                                        /* (SDMMC_CA0R) Asynchronous Interrupt supported  */
#define SDMMC_CA0R_ASINTSUP_NO                (SDMMC_CA0R_ASINTSUP_NO_Val << SDMMC_CA0R_ASINTSUP_Pos) /* (SDMMC_CA0R) Asynchronous Interrupt not Supported Position  */
#define SDMMC_CA0R_ASINTSUP_YES               (SDMMC_CA0R_ASINTSUP_YES_Val << SDMMC_CA0R_ASINTSUP_Pos) /* (SDMMC_CA0R) Asynchronous Interrupt supported Position  */
#define SDMMC_CA0R_SLTYPE_Pos                 _UINT32_(30)                                         /* (SDMMC_CA0R) Slot Type Position */
#define SDMMC_CA0R_SLTYPE_Msk                 (_UINT32_(0x3) << SDMMC_CA0R_SLTYPE_Pos)             /* (SDMMC_CA0R) Slot Type Mask */
#define SDMMC_CA0R_SLTYPE(value)              (SDMMC_CA0R_SLTYPE_Msk & (_UINT32_(value) << SDMMC_CA0R_SLTYPE_Pos)) /* Assigment of value for SLTYPE in the SDMMC_CA0R register */
#define   SDMMC_CA0R_SLTYPE_REMOVABLE_Val     _UINT32_(0x0)                                        /* (SDMMC_CA0R) Removable Card Slot  */
#define   SDMMC_CA0R_SLTYPE_EMBEDDED_Val      _UINT32_(0x1)                                        /* (SDMMC_CA0R) Embedded Slot for One Device  */
#define SDMMC_CA0R_SLTYPE_REMOVABLE           (SDMMC_CA0R_SLTYPE_REMOVABLE_Val << SDMMC_CA0R_SLTYPE_Pos) /* (SDMMC_CA0R) Removable Card Slot Position  */
#define SDMMC_CA0R_SLTYPE_EMBEDDED            (SDMMC_CA0R_SLTYPE_EMBEDDED_Val << SDMMC_CA0R_SLTYPE_Pos) /* (SDMMC_CA0R) Embedded Slot for One Device Position  */
#define SDMMC_CA0R_Msk                        _UINT32_(0xF7EFFFBF)                                 /* (SDMMC_CA0R) Register Mask  */


/* -------- SDMMC_CA1R : (SDMMC Offset: 0x44) (R/W 32) Capabilities 1 -------- */
#define SDMMC_CA1R_RESETVALUE                 _UINT32_(0x10070)                                    /*  (SDMMC_CA1R) Capabilities 1  Reset Value */

#define SDMMC_CA1R_SDR50SUP_Pos               _UINT32_(0)                                          /* (SDMMC_CA1R) SDR50 Support Position */
#define SDMMC_CA1R_SDR50SUP_Msk               (_UINT32_(0x1) << SDMMC_CA1R_SDR50SUP_Pos)           /* (SDMMC_CA1R) SDR50 Support Mask */
#define SDMMC_CA1R_SDR50SUP(value)            (SDMMC_CA1R_SDR50SUP_Msk & (_UINT32_(value) << SDMMC_CA1R_SDR50SUP_Pos)) /* Assigment of value for SDR50SUP in the SDMMC_CA1R register */
#define   SDMMC_CA1R_SDR50SUP_NO_Val          _UINT32_(0x0)                                        /* (SDMMC_CA1R) SDR50 is Not Supported  */
#define   SDMMC_CA1R_SDR50SUP_YES_Val         _UINT32_(0x1)                                        /* (SDMMC_CA1R) SDR50 is Supported  */
#define SDMMC_CA1R_SDR50SUP_NO                (SDMMC_CA1R_SDR50SUP_NO_Val << SDMMC_CA1R_SDR50SUP_Pos) /* (SDMMC_CA1R) SDR50 is Not Supported Position  */
#define SDMMC_CA1R_SDR50SUP_YES               (SDMMC_CA1R_SDR50SUP_YES_Val << SDMMC_CA1R_SDR50SUP_Pos) /* (SDMMC_CA1R) SDR50 is Supported Position  */
#define SDMMC_CA1R_SDR104SUP_Pos              _UINT32_(1)                                          /* (SDMMC_CA1R) SDR104 Support Position */
#define SDMMC_CA1R_SDR104SUP_Msk              (_UINT32_(0x1) << SDMMC_CA1R_SDR104SUP_Pos)          /* (SDMMC_CA1R) SDR104 Support Mask */
#define SDMMC_CA1R_SDR104SUP(value)           (SDMMC_CA1R_SDR104SUP_Msk & (_UINT32_(value) << SDMMC_CA1R_SDR104SUP_Pos)) /* Assigment of value for SDR104SUP in the SDMMC_CA1R register */
#define   SDMMC_CA1R_SDR104SUP_NO_Val         _UINT32_(0x0)                                        /* (SDMMC_CA1R) SDR104 is Not Supported  */
#define   SDMMC_CA1R_SDR104SUP_YES_Val        _UINT32_(0x1)                                        /* (SDMMC_CA1R) SDR104 is Supported  */
#define SDMMC_CA1R_SDR104SUP_NO               (SDMMC_CA1R_SDR104SUP_NO_Val << SDMMC_CA1R_SDR104SUP_Pos) /* (SDMMC_CA1R) SDR104 is Not Supported Position  */
#define SDMMC_CA1R_SDR104SUP_YES              (SDMMC_CA1R_SDR104SUP_YES_Val << SDMMC_CA1R_SDR104SUP_Pos) /* (SDMMC_CA1R) SDR104 is Supported Position  */
#define SDMMC_CA1R_DDR50SUP_Pos               _UINT32_(2)                                          /* (SDMMC_CA1R) DDR50 Support Position */
#define SDMMC_CA1R_DDR50SUP_Msk               (_UINT32_(0x1) << SDMMC_CA1R_DDR50SUP_Pos)           /* (SDMMC_CA1R) DDR50 Support Mask */
#define SDMMC_CA1R_DDR50SUP(value)            (SDMMC_CA1R_DDR50SUP_Msk & (_UINT32_(value) << SDMMC_CA1R_DDR50SUP_Pos)) /* Assigment of value for DDR50SUP in the SDMMC_CA1R register */
#define   SDMMC_CA1R_DDR50SUP_NO_Val          _UINT32_(0x0)                                        /* (SDMMC_CA1R) DDR50 is Not Supported  */
#define   SDMMC_CA1R_DDR50SUP_YES_Val         _UINT32_(0x1)                                        /* (SDMMC_CA1R) DDR50 is Supported  */
#define SDMMC_CA1R_DDR50SUP_NO                (SDMMC_CA1R_DDR50SUP_NO_Val << SDMMC_CA1R_DDR50SUP_Pos) /* (SDMMC_CA1R) DDR50 is Not Supported Position  */
#define SDMMC_CA1R_DDR50SUP_YES               (SDMMC_CA1R_DDR50SUP_YES_Val << SDMMC_CA1R_DDR50SUP_Pos) /* (SDMMC_CA1R) DDR50 is Supported Position  */
#define SDMMC_CA1R_DRVASUP_Pos                _UINT32_(4)                                          /* (SDMMC_CA1R) Driver Type A Support Position */
#define SDMMC_CA1R_DRVASUP_Msk                (_UINT32_(0x1) << SDMMC_CA1R_DRVASUP_Pos)            /* (SDMMC_CA1R) Driver Type A Support Mask */
#define SDMMC_CA1R_DRVASUP(value)             (SDMMC_CA1R_DRVASUP_Msk & (_UINT32_(value) << SDMMC_CA1R_DRVASUP_Pos)) /* Assigment of value for DRVASUP in the SDMMC_CA1R register */
#define   SDMMC_CA1R_DRVASUP_NO_Val           _UINT32_(0x0)                                        /* (SDMMC_CA1R) Driver Type A is Not Supported  */
#define   SDMMC_CA1R_DRVASUP_YES_Val          _UINT32_(0x1)                                        /* (SDMMC_CA1R) Driver Type A is Supported  */
#define SDMMC_CA1R_DRVASUP_NO                 (SDMMC_CA1R_DRVASUP_NO_Val << SDMMC_CA1R_DRVASUP_Pos) /* (SDMMC_CA1R) Driver Type A is Not Supported Position  */
#define SDMMC_CA1R_DRVASUP_YES                (SDMMC_CA1R_DRVASUP_YES_Val << SDMMC_CA1R_DRVASUP_Pos) /* (SDMMC_CA1R) Driver Type A is Supported Position  */
#define SDMMC_CA1R_DRVCSUP_Pos                _UINT32_(5)                                          /* (SDMMC_CA1R) Driver Type C Support Position */
#define SDMMC_CA1R_DRVCSUP_Msk                (_UINT32_(0x1) << SDMMC_CA1R_DRVCSUP_Pos)            /* (SDMMC_CA1R) Driver Type C Support Mask */
#define SDMMC_CA1R_DRVCSUP(value)             (SDMMC_CA1R_DRVCSUP_Msk & (_UINT32_(value) << SDMMC_CA1R_DRVCSUP_Pos)) /* Assigment of value for DRVCSUP in the SDMMC_CA1R register */
#define   SDMMC_CA1R_DRVCSUP_NO_Val           _UINT32_(0x0)                                        /* (SDMMC_CA1R) Driver Type C is Not Supported  */
#define   SDMMC_CA1R_DRVCSUP_YES_Val          _UINT32_(0x1)                                        /* (SDMMC_CA1R) Driver Type C is Supported  */
#define SDMMC_CA1R_DRVCSUP_NO                 (SDMMC_CA1R_DRVCSUP_NO_Val << SDMMC_CA1R_DRVCSUP_Pos) /* (SDMMC_CA1R) Driver Type C is Not Supported Position  */
#define SDMMC_CA1R_DRVCSUP_YES                (SDMMC_CA1R_DRVCSUP_YES_Val << SDMMC_CA1R_DRVCSUP_Pos) /* (SDMMC_CA1R) Driver Type C is Supported Position  */
#define SDMMC_CA1R_DRVDSUP_Pos                _UINT32_(6)                                          /* (SDMMC_CA1R) Driver Type D Support Position */
#define SDMMC_CA1R_DRVDSUP_Msk                (_UINT32_(0x1) << SDMMC_CA1R_DRVDSUP_Pos)            /* (SDMMC_CA1R) Driver Type D Support Mask */
#define SDMMC_CA1R_DRVDSUP(value)             (SDMMC_CA1R_DRVDSUP_Msk & (_UINT32_(value) << SDMMC_CA1R_DRVDSUP_Pos)) /* Assigment of value for DRVDSUP in the SDMMC_CA1R register */
#define   SDMMC_CA1R_DRVDSUP_NO_Val           _UINT32_(0x0)                                        /* (SDMMC_CA1R) Driver Type D is Not Supported  */
#define   SDMMC_CA1R_DRVDSUP_YES_Val          _UINT32_(0x1)                                        /* (SDMMC_CA1R) Driver Type D is Supported  */
#define SDMMC_CA1R_DRVDSUP_NO                 (SDMMC_CA1R_DRVDSUP_NO_Val << SDMMC_CA1R_DRVDSUP_Pos) /* (SDMMC_CA1R) Driver Type D is Not Supported Position  */
#define SDMMC_CA1R_DRVDSUP_YES                (SDMMC_CA1R_DRVDSUP_YES_Val << SDMMC_CA1R_DRVDSUP_Pos) /* (SDMMC_CA1R) Driver Type D is Supported Position  */
#define SDMMC_CA1R_TCNTRT_Pos                 _UINT32_(8)                                          /* (SDMMC_CA1R) Timer Count for Re-Tuning Position */
#define SDMMC_CA1R_TCNTRT_Msk                 (_UINT32_(0xF) << SDMMC_CA1R_TCNTRT_Pos)             /* (SDMMC_CA1R) Timer Count for Re-Tuning Mask */
#define SDMMC_CA1R_TCNTRT(value)              (SDMMC_CA1R_TCNTRT_Msk & (_UINT32_(value) << SDMMC_CA1R_TCNTRT_Pos)) /* Assigment of value for TCNTRT in the SDMMC_CA1R register */
#define   SDMMC_CA1R_TCNTRT_DISABLED_Val      _UINT32_(0x0)                                        /* (SDMMC_CA1R) Re-Tuning Timer disabled  */
#define   SDMMC_CA1R_TCNTRT_1S_Val            _UINT32_(0x1)                                        /* (SDMMC_CA1R) 1 second  */
#define   SDMMC_CA1R_TCNTRT_2S_Val            _UINT32_(0x2)                                        /* (SDMMC_CA1R) 2 seconds  */
#define   SDMMC_CA1R_TCNTRT_4S_Val            _UINT32_(0x3)                                        /* (SDMMC_CA1R) 4 seconds  */
#define   SDMMC_CA1R_TCNTRT_8S_Val            _UINT32_(0x4)                                        /* (SDMMC_CA1R) 8 seconds  */
#define   SDMMC_CA1R_TCNTRT_16S_Val           _UINT32_(0x5)                                        /* (SDMMC_CA1R) 16 seconds  */
#define   SDMMC_CA1R_TCNTRT_32S_Val           _UINT32_(0x6)                                        /* (SDMMC_CA1R) 32 seconds  */
#define   SDMMC_CA1R_TCNTRT_64S_Val           _UINT32_(0x7)                                        /* (SDMMC_CA1R) 64 seconds  */
#define   SDMMC_CA1R_TCNTRT_128S_Val          _UINT32_(0x8)                                        /* (SDMMC_CA1R) 128 seconds  */
#define   SDMMC_CA1R_TCNTRT_256S_Val          _UINT32_(0x9)                                        /* (SDMMC_CA1R) 256 seconds  */
#define   SDMMC_CA1R_TCNTRT_512S_Val          _UINT32_(0xA)                                        /* (SDMMC_CA1R) 512 seconds  */
#define   SDMMC_CA1R_TCNTRT_1024S_Val         _UINT32_(0xB)                                        /* (SDMMC_CA1R) 1024 seconds  */
#define   SDMMC_CA1R_TCNTRT_OTHER_Val         _UINT32_(0xF)                                        /* (SDMMC_CA1R) Get information from other source  */
#define SDMMC_CA1R_TCNTRT_DISABLED            (SDMMC_CA1R_TCNTRT_DISABLED_Val << SDMMC_CA1R_TCNTRT_Pos) /* (SDMMC_CA1R) Re-Tuning Timer disabled Position  */
#define SDMMC_CA1R_TCNTRT_1S                  (SDMMC_CA1R_TCNTRT_1S_Val << SDMMC_CA1R_TCNTRT_Pos)  /* (SDMMC_CA1R) 1 second Position  */
#define SDMMC_CA1R_TCNTRT_2S                  (SDMMC_CA1R_TCNTRT_2S_Val << SDMMC_CA1R_TCNTRT_Pos)  /* (SDMMC_CA1R) 2 seconds Position  */
#define SDMMC_CA1R_TCNTRT_4S                  (SDMMC_CA1R_TCNTRT_4S_Val << SDMMC_CA1R_TCNTRT_Pos)  /* (SDMMC_CA1R) 4 seconds Position  */
#define SDMMC_CA1R_TCNTRT_8S                  (SDMMC_CA1R_TCNTRT_8S_Val << SDMMC_CA1R_TCNTRT_Pos)  /* (SDMMC_CA1R) 8 seconds Position  */
#define SDMMC_CA1R_TCNTRT_16S                 (SDMMC_CA1R_TCNTRT_16S_Val << SDMMC_CA1R_TCNTRT_Pos) /* (SDMMC_CA1R) 16 seconds Position  */
#define SDMMC_CA1R_TCNTRT_32S                 (SDMMC_CA1R_TCNTRT_32S_Val << SDMMC_CA1R_TCNTRT_Pos) /* (SDMMC_CA1R) 32 seconds Position  */
#define SDMMC_CA1R_TCNTRT_64S                 (SDMMC_CA1R_TCNTRT_64S_Val << SDMMC_CA1R_TCNTRT_Pos) /* (SDMMC_CA1R) 64 seconds Position  */
#define SDMMC_CA1R_TCNTRT_128S                (SDMMC_CA1R_TCNTRT_128S_Val << SDMMC_CA1R_TCNTRT_Pos) /* (SDMMC_CA1R) 128 seconds Position  */
#define SDMMC_CA1R_TCNTRT_256S                (SDMMC_CA1R_TCNTRT_256S_Val << SDMMC_CA1R_TCNTRT_Pos) /* (SDMMC_CA1R) 256 seconds Position  */
#define SDMMC_CA1R_TCNTRT_512S                (SDMMC_CA1R_TCNTRT_512S_Val << SDMMC_CA1R_TCNTRT_Pos) /* (SDMMC_CA1R) 512 seconds Position  */
#define SDMMC_CA1R_TCNTRT_1024S               (SDMMC_CA1R_TCNTRT_1024S_Val << SDMMC_CA1R_TCNTRT_Pos) /* (SDMMC_CA1R) 1024 seconds Position  */
#define SDMMC_CA1R_TCNTRT_OTHER               (SDMMC_CA1R_TCNTRT_OTHER_Val << SDMMC_CA1R_TCNTRT_Pos) /* (SDMMC_CA1R) Get information from other source Position  */
#define SDMMC_CA1R_TSDR50_Pos                 _UINT32_(13)                                         /* (SDMMC_CA1R) Use Tuning for SDR50 Position */
#define SDMMC_CA1R_TSDR50_Msk                 (_UINT32_(0x1) << SDMMC_CA1R_TSDR50_Pos)             /* (SDMMC_CA1R) Use Tuning for SDR50 Mask */
#define SDMMC_CA1R_TSDR50(value)              (SDMMC_CA1R_TSDR50_Msk & (_UINT32_(value) << SDMMC_CA1R_TSDR50_Pos)) /* Assigment of value for TSDR50 in the SDMMC_CA1R register */
#define   SDMMC_CA1R_TSDR50_NO_Val            _UINT32_(0x0)                                        /* (SDMMC_CA1R) SDR50 does not require tuning  */
#define   SDMMC_CA1R_TSDR50_YES_Val           _UINT32_(0x1)                                        /* (SDMMC_CA1R) SDR50 requires tuning  */
#define SDMMC_CA1R_TSDR50_NO                  (SDMMC_CA1R_TSDR50_NO_Val << SDMMC_CA1R_TSDR50_Pos)  /* (SDMMC_CA1R) SDR50 does not require tuning Position  */
#define SDMMC_CA1R_TSDR50_YES                 (SDMMC_CA1R_TSDR50_YES_Val << SDMMC_CA1R_TSDR50_Pos) /* (SDMMC_CA1R) SDR50 requires tuning Position  */
#define SDMMC_CA1R_CLKMULT_Pos                _UINT32_(16)                                         /* (SDMMC_CA1R) Clock Multiplier Position */
#define SDMMC_CA1R_CLKMULT_Msk                (_UINT32_(0xFF) << SDMMC_CA1R_CLKMULT_Pos)           /* (SDMMC_CA1R) Clock Multiplier Mask */
#define SDMMC_CA1R_CLKMULT(value)             (SDMMC_CA1R_CLKMULT_Msk & (_UINT32_(value) << SDMMC_CA1R_CLKMULT_Pos)) /* Assigment of value for CLKMULT in the SDMMC_CA1R register */
#define   SDMMC_CA1R_CLKMULT_NO_Val           _UINT32_(0x0)                                        /* (SDMMC_CA1R) Clock Multiplier is Not Supported  */
#define SDMMC_CA1R_CLKMULT_NO                 (SDMMC_CA1R_CLKMULT_NO_Val << SDMMC_CA1R_CLKMULT_Pos) /* (SDMMC_CA1R) Clock Multiplier is Not Supported Position  */
#define SDMMC_CA1R_Msk                        _UINT32_(0x00FF2F77)                                 /* (SDMMC_CA1R) Register Mask  */

#define SDMMC_CA1R_TSDR_Pos                   _UINT32_(13)                                         /* (SDMMC_CA1R Position) Use Tuning for SDR5x */
#define SDMMC_CA1R_TSDR_Msk                   (_UINT32_(0x1) << SDMMC_CA1R_TSDR_Pos)               /* (SDMMC_CA1R Mask) TSDR */
#define SDMMC_CA1R_TSDR(value)                (SDMMC_CA1R_TSDR_Msk & (_UINT32_(value) << SDMMC_CA1R_TSDR_Pos)) 

/* -------- SDMMC_MCCAR : (SDMMC Offset: 0x48) ( R/ 32) Maximum Current Capabilities -------- */
#define SDMMC_MCCAR_RESETVALUE                _UINT32_(0x00)                                       /*  (SDMMC_MCCAR) Maximum Current Capabilities  Reset Value */

#define SDMMC_MCCAR_MAXCUR33V_Pos             _UINT32_(0)                                          /* (SDMMC_MCCAR) Maximum Current for 3.3V Position */
#define SDMMC_MCCAR_MAXCUR33V_Msk             (_UINT32_(0xFF) << SDMMC_MCCAR_MAXCUR33V_Pos)        /* (SDMMC_MCCAR) Maximum Current for 3.3V Mask */
#define SDMMC_MCCAR_MAXCUR33V(value)          (SDMMC_MCCAR_MAXCUR33V_Msk & (_UINT32_(value) << SDMMC_MCCAR_MAXCUR33V_Pos)) /* Assigment of value for MAXCUR33V in the SDMMC_MCCAR register */
#define   SDMMC_MCCAR_MAXCUR33V_OTHER_Val     _UINT32_(0x0)                                        /* (SDMMC_MCCAR) Get information via another method  */
#define   SDMMC_MCCAR_MAXCUR33V_4MA_Val       _UINT32_(0x1)                                        /* (SDMMC_MCCAR) 4mA  */
#define   SDMMC_MCCAR_MAXCUR33V_8MA_Val       _UINT32_(0x2)                                        /* (SDMMC_MCCAR) 8mA  */
#define   SDMMC_MCCAR_MAXCUR33V_12MA_Val      _UINT32_(0x3)                                        /* (SDMMC_MCCAR) 12mA  */
#define SDMMC_MCCAR_MAXCUR33V_OTHER           (SDMMC_MCCAR_MAXCUR33V_OTHER_Val << SDMMC_MCCAR_MAXCUR33V_Pos) /* (SDMMC_MCCAR) Get information via another method Position  */
#define SDMMC_MCCAR_MAXCUR33V_4MA             (SDMMC_MCCAR_MAXCUR33V_4MA_Val << SDMMC_MCCAR_MAXCUR33V_Pos) /* (SDMMC_MCCAR) 4mA Position  */
#define SDMMC_MCCAR_MAXCUR33V_8MA             (SDMMC_MCCAR_MAXCUR33V_8MA_Val << SDMMC_MCCAR_MAXCUR33V_Pos) /* (SDMMC_MCCAR) 8mA Position  */
#define SDMMC_MCCAR_MAXCUR33V_12MA            (SDMMC_MCCAR_MAXCUR33V_12MA_Val << SDMMC_MCCAR_MAXCUR33V_Pos) /* (SDMMC_MCCAR) 12mA Position  */
#define SDMMC_MCCAR_MAXCUR30V_Pos             _UINT32_(8)                                          /* (SDMMC_MCCAR) Maximum Current for 3.0V Position */
#define SDMMC_MCCAR_MAXCUR30V_Msk             (_UINT32_(0xFF) << SDMMC_MCCAR_MAXCUR30V_Pos)        /* (SDMMC_MCCAR) Maximum Current for 3.0V Mask */
#define SDMMC_MCCAR_MAXCUR30V(value)          (SDMMC_MCCAR_MAXCUR30V_Msk & (_UINT32_(value) << SDMMC_MCCAR_MAXCUR30V_Pos)) /* Assigment of value for MAXCUR30V in the SDMMC_MCCAR register */
#define   SDMMC_MCCAR_MAXCUR30V_OTHER_Val     _UINT32_(0x0)                                        /* (SDMMC_MCCAR) Get information via another method  */
#define   SDMMC_MCCAR_MAXCUR30V_4MA_Val       _UINT32_(0x1)                                        /* (SDMMC_MCCAR) 4mA  */
#define   SDMMC_MCCAR_MAXCUR30V_8MA_Val       _UINT32_(0x2)                                        /* (SDMMC_MCCAR) 8mA  */
#define   SDMMC_MCCAR_MAXCUR30V_12MA_Val      _UINT32_(0x3)                                        /* (SDMMC_MCCAR) 12mA  */
#define SDMMC_MCCAR_MAXCUR30V_OTHER           (SDMMC_MCCAR_MAXCUR30V_OTHER_Val << SDMMC_MCCAR_MAXCUR30V_Pos) /* (SDMMC_MCCAR) Get information via another method Position  */
#define SDMMC_MCCAR_MAXCUR30V_4MA             (SDMMC_MCCAR_MAXCUR30V_4MA_Val << SDMMC_MCCAR_MAXCUR30V_Pos) /* (SDMMC_MCCAR) 4mA Position  */
#define SDMMC_MCCAR_MAXCUR30V_8MA             (SDMMC_MCCAR_MAXCUR30V_8MA_Val << SDMMC_MCCAR_MAXCUR30V_Pos) /* (SDMMC_MCCAR) 8mA Position  */
#define SDMMC_MCCAR_MAXCUR30V_12MA            (SDMMC_MCCAR_MAXCUR30V_12MA_Val << SDMMC_MCCAR_MAXCUR30V_Pos) /* (SDMMC_MCCAR) 12mA Position  */
#define SDMMC_MCCAR_MAXCUR18V_Pos             _UINT32_(16)                                         /* (SDMMC_MCCAR) Maximum Current for 1.8V Position */
#define SDMMC_MCCAR_MAXCUR18V_Msk             (_UINT32_(0xFF) << SDMMC_MCCAR_MAXCUR18V_Pos)        /* (SDMMC_MCCAR) Maximum Current for 1.8V Mask */
#define SDMMC_MCCAR_MAXCUR18V(value)          (SDMMC_MCCAR_MAXCUR18V_Msk & (_UINT32_(value) << SDMMC_MCCAR_MAXCUR18V_Pos)) /* Assigment of value for MAXCUR18V in the SDMMC_MCCAR register */
#define   SDMMC_MCCAR_MAXCUR18V_OTHER_Val     _UINT32_(0x0)                                        /* (SDMMC_MCCAR) Get information via another method  */
#define   SDMMC_MCCAR_MAXCUR18V_4MA_Val       _UINT32_(0x1)                                        /* (SDMMC_MCCAR) 4mA  */
#define   SDMMC_MCCAR_MAXCUR18V_8MA_Val       _UINT32_(0x2)                                        /* (SDMMC_MCCAR) 8mA  */
#define   SDMMC_MCCAR_MAXCUR18V_12MA_Val      _UINT32_(0x3)                                        /* (SDMMC_MCCAR) 12mA  */
#define SDMMC_MCCAR_MAXCUR18V_OTHER           (SDMMC_MCCAR_MAXCUR18V_OTHER_Val << SDMMC_MCCAR_MAXCUR18V_Pos) /* (SDMMC_MCCAR) Get information via another method Position  */
#define SDMMC_MCCAR_MAXCUR18V_4MA             (SDMMC_MCCAR_MAXCUR18V_4MA_Val << SDMMC_MCCAR_MAXCUR18V_Pos) /* (SDMMC_MCCAR) 4mA Position  */
#define SDMMC_MCCAR_MAXCUR18V_8MA             (SDMMC_MCCAR_MAXCUR18V_8MA_Val << SDMMC_MCCAR_MAXCUR18V_Pos) /* (SDMMC_MCCAR) 8mA Position  */
#define SDMMC_MCCAR_MAXCUR18V_12MA            (SDMMC_MCCAR_MAXCUR18V_12MA_Val << SDMMC_MCCAR_MAXCUR18V_Pos) /* (SDMMC_MCCAR) 12mA Position  */
#define SDMMC_MCCAR_Msk                       _UINT32_(0x00FFFFFF)                                 /* (SDMMC_MCCAR) Register Mask  */


/* -------- SDMMC_FERACES : (SDMMC Offset: 0x50) ( /W 16) Force Event for Auto CMD Error Status -------- */
#define SDMMC_FERACES_RESETVALUE              _UINT16_(0x00)                                       /*  (SDMMC_FERACES) Force Event for Auto CMD Error Status  Reset Value */

#define SDMMC_FERACES_ACMD12NE_Pos            _UINT16_(0)                                          /* (SDMMC_FERACES) Force Event for Auto CMD12 Not Executed Position */
#define SDMMC_FERACES_ACMD12NE_Msk            (_UINT16_(0x1) << SDMMC_FERACES_ACMD12NE_Pos)        /* (SDMMC_FERACES) Force Event for Auto CMD12 Not Executed Mask */
#define SDMMC_FERACES_ACMD12NE(value)         (SDMMC_FERACES_ACMD12NE_Msk & (_UINT16_(value) << SDMMC_FERACES_ACMD12NE_Pos)) /* Assigment of value for ACMD12NE in the SDMMC_FERACES register */
#define   SDMMC_FERACES_ACMD12NE_NO_Val       _UINT16_(0x0)                                        /* (SDMMC_FERACES) No Interrupt  */
#define   SDMMC_FERACES_ACMD12NE_YES_Val      _UINT16_(0x1)                                        /* (SDMMC_FERACES) Interrupt is generated  */
#define SDMMC_FERACES_ACMD12NE_NO             (SDMMC_FERACES_ACMD12NE_NO_Val << SDMMC_FERACES_ACMD12NE_Pos) /* (SDMMC_FERACES) No Interrupt Position  */
#define SDMMC_FERACES_ACMD12NE_YES            (SDMMC_FERACES_ACMD12NE_YES_Val << SDMMC_FERACES_ACMD12NE_Pos) /* (SDMMC_FERACES) Interrupt is generated Position  */
#define SDMMC_FERACES_ACMDTEO_Pos             _UINT16_(1)                                          /* (SDMMC_FERACES) Force Event for Auto CMD Timeout Error Position */
#define SDMMC_FERACES_ACMDTEO_Msk             (_UINT16_(0x1) << SDMMC_FERACES_ACMDTEO_Pos)         /* (SDMMC_FERACES) Force Event for Auto CMD Timeout Error Mask */
#define SDMMC_FERACES_ACMDTEO(value)          (SDMMC_FERACES_ACMDTEO_Msk & (_UINT16_(value) << SDMMC_FERACES_ACMDTEO_Pos)) /* Assigment of value for ACMDTEO in the SDMMC_FERACES register */
#define   SDMMC_FERACES_ACMDTEO_NO_Val        _UINT16_(0x0)                                        /* (SDMMC_FERACES) No Interrupt  */
#define   SDMMC_FERACES_ACMDTEO_YES_Val       _UINT16_(0x1)                                        /* (SDMMC_FERACES) Interrupt is generated  */
#define SDMMC_FERACES_ACMDTEO_NO              (SDMMC_FERACES_ACMDTEO_NO_Val << SDMMC_FERACES_ACMDTEO_Pos) /* (SDMMC_FERACES) No Interrupt Position  */
#define SDMMC_FERACES_ACMDTEO_YES             (SDMMC_FERACES_ACMDTEO_YES_Val << SDMMC_FERACES_ACMDTEO_Pos) /* (SDMMC_FERACES) Interrupt is generated Position  */
#define SDMMC_FERACES_ACMDCRC_Pos             _UINT16_(2)                                          /* (SDMMC_FERACES) Force Event for Auto CMD CRC Error Position */
#define SDMMC_FERACES_ACMDCRC_Msk             (_UINT16_(0x1) << SDMMC_FERACES_ACMDCRC_Pos)         /* (SDMMC_FERACES) Force Event for Auto CMD CRC Error Mask */
#define SDMMC_FERACES_ACMDCRC(value)          (SDMMC_FERACES_ACMDCRC_Msk & (_UINT16_(value) << SDMMC_FERACES_ACMDCRC_Pos)) /* Assigment of value for ACMDCRC in the SDMMC_FERACES register */
#define   SDMMC_FERACES_ACMDCRC_NO_Val        _UINT16_(0x0)                                        /* (SDMMC_FERACES) No Interrupt  */
#define   SDMMC_FERACES_ACMDCRC_YES_Val       _UINT16_(0x1)                                        /* (SDMMC_FERACES) Interrupt is generated  */
#define SDMMC_FERACES_ACMDCRC_NO              (SDMMC_FERACES_ACMDCRC_NO_Val << SDMMC_FERACES_ACMDCRC_Pos) /* (SDMMC_FERACES) No Interrupt Position  */
#define SDMMC_FERACES_ACMDCRC_YES             (SDMMC_FERACES_ACMDCRC_YES_Val << SDMMC_FERACES_ACMDCRC_Pos) /* (SDMMC_FERACES) Interrupt is generated Position  */
#define SDMMC_FERACES_ACMDEND_Pos             _UINT16_(3)                                          /* (SDMMC_FERACES) Force Event for Auto CMD End Bit Error Position */
#define SDMMC_FERACES_ACMDEND_Msk             (_UINT16_(0x1) << SDMMC_FERACES_ACMDEND_Pos)         /* (SDMMC_FERACES) Force Event for Auto CMD End Bit Error Mask */
#define SDMMC_FERACES_ACMDEND(value)          (SDMMC_FERACES_ACMDEND_Msk & (_UINT16_(value) << SDMMC_FERACES_ACMDEND_Pos)) /* Assigment of value for ACMDEND in the SDMMC_FERACES register */
#define   SDMMC_FERACES_ACMDEND_NO_Val        _UINT16_(0x0)                                        /* (SDMMC_FERACES) No Interrupt  */
#define   SDMMC_FERACES_ACMDEND_YES_Val       _UINT16_(0x1)                                        /* (SDMMC_FERACES) Interrupt is generated  */
#define SDMMC_FERACES_ACMDEND_NO              (SDMMC_FERACES_ACMDEND_NO_Val << SDMMC_FERACES_ACMDEND_Pos) /* (SDMMC_FERACES) No Interrupt Position  */
#define SDMMC_FERACES_ACMDEND_YES             (SDMMC_FERACES_ACMDEND_YES_Val << SDMMC_FERACES_ACMDEND_Pos) /* (SDMMC_FERACES) Interrupt is generated Position  */
#define SDMMC_FERACES_ACMDIDX_Pos             _UINT16_(4)                                          /* (SDMMC_FERACES) Force Event for Auto CMD Index Error Position */
#define SDMMC_FERACES_ACMDIDX_Msk             (_UINT16_(0x1) << SDMMC_FERACES_ACMDIDX_Pos)         /* (SDMMC_FERACES) Force Event for Auto CMD Index Error Mask */
#define SDMMC_FERACES_ACMDIDX(value)          (SDMMC_FERACES_ACMDIDX_Msk & (_UINT16_(value) << SDMMC_FERACES_ACMDIDX_Pos)) /* Assigment of value for ACMDIDX in the SDMMC_FERACES register */
#define   SDMMC_FERACES_ACMDIDX_NO_Val        _UINT16_(0x0)                                        /* (SDMMC_FERACES) No Interrupt  */
#define   SDMMC_FERACES_ACMDIDX_YES_Val       _UINT16_(0x1)                                        /* (SDMMC_FERACES) Interrupt is generated  */
#define SDMMC_FERACES_ACMDIDX_NO              (SDMMC_FERACES_ACMDIDX_NO_Val << SDMMC_FERACES_ACMDIDX_Pos) /* (SDMMC_FERACES) No Interrupt Position  */
#define SDMMC_FERACES_ACMDIDX_YES             (SDMMC_FERACES_ACMDIDX_YES_Val << SDMMC_FERACES_ACMDIDX_Pos) /* (SDMMC_FERACES) Interrupt is generated Position  */
#define SDMMC_FERACES_CMDNI_Pos               _UINT16_(7)                                          /* (SDMMC_FERACES) Force Event for Command Not Issued By Auto CMD12 Error Position */
#define SDMMC_FERACES_CMDNI_Msk               (_UINT16_(0x1) << SDMMC_FERACES_CMDNI_Pos)           /* (SDMMC_FERACES) Force Event for Command Not Issued By Auto CMD12 Error Mask */
#define SDMMC_FERACES_CMDNI(value)            (SDMMC_FERACES_CMDNI_Msk & (_UINT16_(value) << SDMMC_FERACES_CMDNI_Pos)) /* Assigment of value for CMDNI in the SDMMC_FERACES register */
#define   SDMMC_FERACES_CMDNI_NO_Val          _UINT16_(0x0)                                        /* (SDMMC_FERACES) No Interrupt  */
#define   SDMMC_FERACES_CMDNI_YES_Val         _UINT16_(0x1)                                        /* (SDMMC_FERACES) Interrupt is generated  */
#define SDMMC_FERACES_CMDNI_NO                (SDMMC_FERACES_CMDNI_NO_Val << SDMMC_FERACES_CMDNI_Pos) /* (SDMMC_FERACES) No Interrupt Position  */
#define SDMMC_FERACES_CMDNI_YES               (SDMMC_FERACES_CMDNI_YES_Val << SDMMC_FERACES_CMDNI_Pos) /* (SDMMC_FERACES) Interrupt is generated Position  */
#define SDMMC_FERACES_Msk                     _UINT16_(0x009F)                                     /* (SDMMC_FERACES) Register Mask  */


/* -------- SDMMC_FEREIS : (SDMMC Offset: 0x52) ( /W 16) Force Event for Error Interrupt Status -------- */
#define SDMMC_FEREIS_RESETVALUE               _UINT16_(0x00)                                       /*  (SDMMC_FEREIS) Force Event for Error Interrupt Status  Reset Value */

#define SDMMC_FEREIS_CMDTEO_Pos               _UINT16_(0)                                          /* (SDMMC_FEREIS) Force Event for Command Timeout Error Position */
#define SDMMC_FEREIS_CMDTEO_Msk               (_UINT16_(0x1) << SDMMC_FEREIS_CMDTEO_Pos)           /* (SDMMC_FEREIS) Force Event for Command Timeout Error Mask */
#define SDMMC_FEREIS_CMDTEO(value)            (SDMMC_FEREIS_CMDTEO_Msk & (_UINT16_(value) << SDMMC_FEREIS_CMDTEO_Pos)) /* Assigment of value for CMDTEO in the SDMMC_FEREIS register */
#define   SDMMC_FEREIS_CMDTEO_NO_Val          _UINT16_(0x0)                                        /* (SDMMC_FEREIS) No Interrupt  */
#define   SDMMC_FEREIS_CMDTEO_YES_Val         _UINT16_(0x1)                                        /* (SDMMC_FEREIS) Interrupt is generated  */
#define SDMMC_FEREIS_CMDTEO_NO                (SDMMC_FEREIS_CMDTEO_NO_Val << SDMMC_FEREIS_CMDTEO_Pos) /* (SDMMC_FEREIS) No Interrupt Position  */
#define SDMMC_FEREIS_CMDTEO_YES               (SDMMC_FEREIS_CMDTEO_YES_Val << SDMMC_FEREIS_CMDTEO_Pos) /* (SDMMC_FEREIS) Interrupt is generated Position  */
#define SDMMC_FEREIS_CMDCRC_Pos               _UINT16_(1)                                          /* (SDMMC_FEREIS) Force Event for Command CRC Error Position */
#define SDMMC_FEREIS_CMDCRC_Msk               (_UINT16_(0x1) << SDMMC_FEREIS_CMDCRC_Pos)           /* (SDMMC_FEREIS) Force Event for Command CRC Error Mask */
#define SDMMC_FEREIS_CMDCRC(value)            (SDMMC_FEREIS_CMDCRC_Msk & (_UINT16_(value) << SDMMC_FEREIS_CMDCRC_Pos)) /* Assigment of value for CMDCRC in the SDMMC_FEREIS register */
#define   SDMMC_FEREIS_CMDCRC_NO_Val          _UINT16_(0x0)                                        /* (SDMMC_FEREIS) No Interrupt  */
#define   SDMMC_FEREIS_CMDCRC_YES_Val         _UINT16_(0x1)                                        /* (SDMMC_FEREIS) Interrupt is generated  */
#define SDMMC_FEREIS_CMDCRC_NO                (SDMMC_FEREIS_CMDCRC_NO_Val << SDMMC_FEREIS_CMDCRC_Pos) /* (SDMMC_FEREIS) No Interrupt Position  */
#define SDMMC_FEREIS_CMDCRC_YES               (SDMMC_FEREIS_CMDCRC_YES_Val << SDMMC_FEREIS_CMDCRC_Pos) /* (SDMMC_FEREIS) Interrupt is generated Position  */
#define SDMMC_FEREIS_CMDEND_Pos               _UINT16_(2)                                          /* (SDMMC_FEREIS) Force Event for Command End Bit Error Position */
#define SDMMC_FEREIS_CMDEND_Msk               (_UINT16_(0x1) << SDMMC_FEREIS_CMDEND_Pos)           /* (SDMMC_FEREIS) Force Event for Command End Bit Error Mask */
#define SDMMC_FEREIS_CMDEND(value)            (SDMMC_FEREIS_CMDEND_Msk & (_UINT16_(value) << SDMMC_FEREIS_CMDEND_Pos)) /* Assigment of value for CMDEND in the SDMMC_FEREIS register */
#define   SDMMC_FEREIS_CMDEND_NO_Val          _UINT16_(0x0)                                        /* (SDMMC_FEREIS) No Interrupt  */
#define   SDMMC_FEREIS_CMDEND_YES_Val         _UINT16_(0x1)                                        /* (SDMMC_FEREIS) Interrupt is generated  */
#define SDMMC_FEREIS_CMDEND_NO                (SDMMC_FEREIS_CMDEND_NO_Val << SDMMC_FEREIS_CMDEND_Pos) /* (SDMMC_FEREIS) No Interrupt Position  */
#define SDMMC_FEREIS_CMDEND_YES               (SDMMC_FEREIS_CMDEND_YES_Val << SDMMC_FEREIS_CMDEND_Pos) /* (SDMMC_FEREIS) Interrupt is generated Position  */
#define SDMMC_FEREIS_CMDIDX_Pos               _UINT16_(3)                                          /* (SDMMC_FEREIS) Force Event for Command Index Error Position */
#define SDMMC_FEREIS_CMDIDX_Msk               (_UINT16_(0x1) << SDMMC_FEREIS_CMDIDX_Pos)           /* (SDMMC_FEREIS) Force Event for Command Index Error Mask */
#define SDMMC_FEREIS_CMDIDX(value)            (SDMMC_FEREIS_CMDIDX_Msk & (_UINT16_(value) << SDMMC_FEREIS_CMDIDX_Pos)) /* Assigment of value for CMDIDX in the SDMMC_FEREIS register */
#define   SDMMC_FEREIS_CMDIDX_NO_Val          _UINT16_(0x0)                                        /* (SDMMC_FEREIS) No Interrupt  */
#define   SDMMC_FEREIS_CMDIDX_YES_Val         _UINT16_(0x1)                                        /* (SDMMC_FEREIS) Interrupt is generated  */
#define SDMMC_FEREIS_CMDIDX_NO                (SDMMC_FEREIS_CMDIDX_NO_Val << SDMMC_FEREIS_CMDIDX_Pos) /* (SDMMC_FEREIS) No Interrupt Position  */
#define SDMMC_FEREIS_CMDIDX_YES               (SDMMC_FEREIS_CMDIDX_YES_Val << SDMMC_FEREIS_CMDIDX_Pos) /* (SDMMC_FEREIS) Interrupt is generated Position  */
#define SDMMC_FEREIS_DATTEO_Pos               _UINT16_(4)                                          /* (SDMMC_FEREIS) Force Event for Data Timeout Error Position */
#define SDMMC_FEREIS_DATTEO_Msk               (_UINT16_(0x1) << SDMMC_FEREIS_DATTEO_Pos)           /* (SDMMC_FEREIS) Force Event for Data Timeout Error Mask */
#define SDMMC_FEREIS_DATTEO(value)            (SDMMC_FEREIS_DATTEO_Msk & (_UINT16_(value) << SDMMC_FEREIS_DATTEO_Pos)) /* Assigment of value for DATTEO in the SDMMC_FEREIS register */
#define   SDMMC_FEREIS_DATTEO_NO_Val          _UINT16_(0x0)                                        /* (SDMMC_FEREIS) No Interrupt  */
#define   SDMMC_FEREIS_DATTEO_YES_Val         _UINT16_(0x1)                                        /* (SDMMC_FEREIS) Interrupt is generated  */
#define SDMMC_FEREIS_DATTEO_NO                (SDMMC_FEREIS_DATTEO_NO_Val << SDMMC_FEREIS_DATTEO_Pos) /* (SDMMC_FEREIS) No Interrupt Position  */
#define SDMMC_FEREIS_DATTEO_YES               (SDMMC_FEREIS_DATTEO_YES_Val << SDMMC_FEREIS_DATTEO_Pos) /* (SDMMC_FEREIS) Interrupt is generated Position  */
#define SDMMC_FEREIS_DATCRC_Pos               _UINT16_(5)                                          /* (SDMMC_FEREIS) Force Event for Data CRC Error Position */
#define SDMMC_FEREIS_DATCRC_Msk               (_UINT16_(0x1) << SDMMC_FEREIS_DATCRC_Pos)           /* (SDMMC_FEREIS) Force Event for Data CRC Error Mask */
#define SDMMC_FEREIS_DATCRC(value)            (SDMMC_FEREIS_DATCRC_Msk & (_UINT16_(value) << SDMMC_FEREIS_DATCRC_Pos)) /* Assigment of value for DATCRC in the SDMMC_FEREIS register */
#define   SDMMC_FEREIS_DATCRC_NO_Val          _UINT16_(0x0)                                        /* (SDMMC_FEREIS) No Interrupt  */
#define   SDMMC_FEREIS_DATCRC_YES_Val         _UINT16_(0x1)                                        /* (SDMMC_FEREIS) Interrupt is generated  */
#define SDMMC_FEREIS_DATCRC_NO                (SDMMC_FEREIS_DATCRC_NO_Val << SDMMC_FEREIS_DATCRC_Pos) /* (SDMMC_FEREIS) No Interrupt Position  */
#define SDMMC_FEREIS_DATCRC_YES               (SDMMC_FEREIS_DATCRC_YES_Val << SDMMC_FEREIS_DATCRC_Pos) /* (SDMMC_FEREIS) Interrupt is generated Position  */
#define SDMMC_FEREIS_DATEND_Pos               _UINT16_(6)                                          /* (SDMMC_FEREIS) Force Event for Data End Bit Error Position */
#define SDMMC_FEREIS_DATEND_Msk               (_UINT16_(0x1) << SDMMC_FEREIS_DATEND_Pos)           /* (SDMMC_FEREIS) Force Event for Data End Bit Error Mask */
#define SDMMC_FEREIS_DATEND(value)            (SDMMC_FEREIS_DATEND_Msk & (_UINT16_(value) << SDMMC_FEREIS_DATEND_Pos)) /* Assigment of value for DATEND in the SDMMC_FEREIS register */
#define   SDMMC_FEREIS_DATEND_NO_Val          _UINT16_(0x0)                                        /* (SDMMC_FEREIS) No Interrupt  */
#define   SDMMC_FEREIS_DATEND_YES_Val         _UINT16_(0x1)                                        /* (SDMMC_FEREIS) Interrupt is generated  */
#define SDMMC_FEREIS_DATEND_NO                (SDMMC_FEREIS_DATEND_NO_Val << SDMMC_FEREIS_DATEND_Pos) /* (SDMMC_FEREIS) No Interrupt Position  */
#define SDMMC_FEREIS_DATEND_YES               (SDMMC_FEREIS_DATEND_YES_Val << SDMMC_FEREIS_DATEND_Pos) /* (SDMMC_FEREIS) Interrupt is generated Position  */
#define SDMMC_FEREIS_CURLIM_Pos               _UINT16_(7)                                          /* (SDMMC_FEREIS) Force Event for Current Limit Error Position */
#define SDMMC_FEREIS_CURLIM_Msk               (_UINT16_(0x1) << SDMMC_FEREIS_CURLIM_Pos)           /* (SDMMC_FEREIS) Force Event for Current Limit Error Mask */
#define SDMMC_FEREIS_CURLIM(value)            (SDMMC_FEREIS_CURLIM_Msk & (_UINT16_(value) << SDMMC_FEREIS_CURLIM_Pos)) /* Assigment of value for CURLIM in the SDMMC_FEREIS register */
#define   SDMMC_FEREIS_CURLIM_NO_Val          _UINT16_(0x0)                                        /* (SDMMC_FEREIS) No Interrupt  */
#define   SDMMC_FEREIS_CURLIM_YES_Val         _UINT16_(0x1)                                        /* (SDMMC_FEREIS) Interrupt is generated  */
#define SDMMC_FEREIS_CURLIM_NO                (SDMMC_FEREIS_CURLIM_NO_Val << SDMMC_FEREIS_CURLIM_Pos) /* (SDMMC_FEREIS) No Interrupt Position  */
#define SDMMC_FEREIS_CURLIM_YES               (SDMMC_FEREIS_CURLIM_YES_Val << SDMMC_FEREIS_CURLIM_Pos) /* (SDMMC_FEREIS) Interrupt is generated Position  */
#define SDMMC_FEREIS_ACMD_Pos                 _UINT16_(8)                                          /* (SDMMC_FEREIS) Force Event for Auto CMD Error Position */
#define SDMMC_FEREIS_ACMD_Msk                 (_UINT16_(0x1) << SDMMC_FEREIS_ACMD_Pos)             /* (SDMMC_FEREIS) Force Event for Auto CMD Error Mask */
#define SDMMC_FEREIS_ACMD(value)              (SDMMC_FEREIS_ACMD_Msk & (_UINT16_(value) << SDMMC_FEREIS_ACMD_Pos)) /* Assigment of value for ACMD in the SDMMC_FEREIS register */
#define   SDMMC_FEREIS_ACMD_NO_Val            _UINT16_(0x0)                                        /* (SDMMC_FEREIS) No Interrupt  */
#define   SDMMC_FEREIS_ACMD_YES_Val           _UINT16_(0x1)                                        /* (SDMMC_FEREIS) Interrupt is generated  */
#define SDMMC_FEREIS_ACMD_NO                  (SDMMC_FEREIS_ACMD_NO_Val << SDMMC_FEREIS_ACMD_Pos)  /* (SDMMC_FEREIS) No Interrupt Position  */
#define SDMMC_FEREIS_ACMD_YES                 (SDMMC_FEREIS_ACMD_YES_Val << SDMMC_FEREIS_ACMD_Pos) /* (SDMMC_FEREIS) Interrupt is generated Position  */
#define SDMMC_FEREIS_ADMA_Pos                 _UINT16_(9)                                          /* (SDMMC_FEREIS) Force Event for ADMA Error Position */
#define SDMMC_FEREIS_ADMA_Msk                 (_UINT16_(0x1) << SDMMC_FEREIS_ADMA_Pos)             /* (SDMMC_FEREIS) Force Event for ADMA Error Mask */
#define SDMMC_FEREIS_ADMA(value)              (SDMMC_FEREIS_ADMA_Msk & (_UINT16_(value) << SDMMC_FEREIS_ADMA_Pos)) /* Assigment of value for ADMA in the SDMMC_FEREIS register */
#define   SDMMC_FEREIS_ADMA_NO_Val            _UINT16_(0x0)                                        /* (SDMMC_FEREIS) No Interrupt  */
#define   SDMMC_FEREIS_ADMA_YES_Val           _UINT16_(0x1)                                        /* (SDMMC_FEREIS) Interrupt is generated  */
#define SDMMC_FEREIS_ADMA_NO                  (SDMMC_FEREIS_ADMA_NO_Val << SDMMC_FEREIS_ADMA_Pos)  /* (SDMMC_FEREIS) No Interrupt Position  */
#define SDMMC_FEREIS_ADMA_YES                 (SDMMC_FEREIS_ADMA_YES_Val << SDMMC_FEREIS_ADMA_Pos) /* (SDMMC_FEREIS) Interrupt is generated Position  */
#define SDMMC_FEREIS_BOOTAE_Pos               _UINT16_(12)                                         /* (SDMMC_FEREIS) Force Event for Boot Acknowledge Error Position */
#define SDMMC_FEREIS_BOOTAE_Msk               (_UINT16_(0x1) << SDMMC_FEREIS_BOOTAE_Pos)           /* (SDMMC_FEREIS) Force Event for Boot Acknowledge Error Mask */
#define SDMMC_FEREIS_BOOTAE(value)            (SDMMC_FEREIS_BOOTAE_Msk & (_UINT16_(value) << SDMMC_FEREIS_BOOTAE_Pos)) /* Assigment of value for BOOTAE in the SDMMC_FEREIS register */
#define   SDMMC_FEREIS_BOOTAE_NO_Val          _UINT16_(0x0)                                        /* (SDMMC_FEREIS) No Interrupt  */
#define   SDMMC_FEREIS_BOOTAE_YES_Val         _UINT16_(0x1)                                        /* (SDMMC_FEREIS) Interrupt is generated  */
#define SDMMC_FEREIS_BOOTAE_NO                (SDMMC_FEREIS_BOOTAE_NO_Val << SDMMC_FEREIS_BOOTAE_Pos) /* (SDMMC_FEREIS) No Interrupt Position  */
#define SDMMC_FEREIS_BOOTAE_YES               (SDMMC_FEREIS_BOOTAE_YES_Val << SDMMC_FEREIS_BOOTAE_Pos) /* (SDMMC_FEREIS) Interrupt is generated Position  */
#define SDMMC_FEREIS_Msk                      _UINT16_(0x13FF)                                     /* (SDMMC_FEREIS) Register Mask  */


/* -------- SDMMC_AESR : (SDMMC Offset: 0x54) ( R/ 8) ADMA Error Status -------- */
#define SDMMC_AESR_RESETVALUE                 _UINT8_(0x00)                                        /*  (SDMMC_AESR) ADMA Error Status  Reset Value */

#define SDMMC_AESR_ERRST_Pos                  _UINT8_(0)                                           /* (SDMMC_AESR) ADMA Error State Position */
#define SDMMC_AESR_ERRST_Msk                  (_UINT8_(0x3) << SDMMC_AESR_ERRST_Pos)               /* (SDMMC_AESR) ADMA Error State Mask */
#define SDMMC_AESR_ERRST(value)               (SDMMC_AESR_ERRST_Msk & (_UINT8_(value) << SDMMC_AESR_ERRST_Pos)) /* Assigment of value for ERRST in the SDMMC_AESR register */
#define   SDMMC_AESR_ERRST_STOP_Val           _UINT8_(0x0)                                         /* (SDMMC_AESR) ST_STOP (Stop DMA)  */
#define   SDMMC_AESR_ERRST_FDS_Val            _UINT8_(0x1)                                         /* (SDMMC_AESR) ST_FDS (Fetch Descriptor)  */
#define   SDMMC_AESR_ERRST_TFR_Val            _UINT8_(0x3)                                         /* (SDMMC_AESR) ST_TFR (Transfer Data)  */
#define SDMMC_AESR_ERRST_STOP                 (SDMMC_AESR_ERRST_STOP_Val << SDMMC_AESR_ERRST_Pos)  /* (SDMMC_AESR) ST_STOP (Stop DMA) Position  */
#define SDMMC_AESR_ERRST_FDS                  (SDMMC_AESR_ERRST_FDS_Val << SDMMC_AESR_ERRST_Pos)   /* (SDMMC_AESR) ST_FDS (Fetch Descriptor) Position  */
#define SDMMC_AESR_ERRST_TFR                  (SDMMC_AESR_ERRST_TFR_Val << SDMMC_AESR_ERRST_Pos)   /* (SDMMC_AESR) ST_TFR (Transfer Data) Position  */
#define SDMMC_AESR_LMIS_Pos                   _UINT8_(2)                                           /* (SDMMC_AESR) ADMA Length Mismatch Error Position */
#define SDMMC_AESR_LMIS_Msk                   (_UINT8_(0x1) << SDMMC_AESR_LMIS_Pos)                /* (SDMMC_AESR) ADMA Length Mismatch Error Mask */
#define SDMMC_AESR_LMIS(value)                (SDMMC_AESR_LMIS_Msk & (_UINT8_(value) << SDMMC_AESR_LMIS_Pos)) /* Assigment of value for LMIS in the SDMMC_AESR register */
#define   SDMMC_AESR_LMIS_NO_Val              _UINT8_(0x0)                                         /* (SDMMC_AESR) No Error  */
#define   SDMMC_AESR_LMIS_YES_Val             _UINT8_(0x1)                                         /* (SDMMC_AESR) Error  */
#define SDMMC_AESR_LMIS_NO                    (SDMMC_AESR_LMIS_NO_Val << SDMMC_AESR_LMIS_Pos)      /* (SDMMC_AESR) No Error Position  */
#define SDMMC_AESR_LMIS_YES                   (SDMMC_AESR_LMIS_YES_Val << SDMMC_AESR_LMIS_Pos)     /* (SDMMC_AESR) Error Position  */
#define SDMMC_AESR_Msk                        _UINT8_(0x07)                                        /* (SDMMC_AESR) Register Mask  */


/* -------- SDMMC_ASAR : (SDMMC Offset: 0x58) (R/W 32) ADMA System Address n -------- */
#define SDMMC_ASAR_RESETVALUE                 _UINT32_(0x00)                                       /*  (SDMMC_ASAR) ADMA System Address n  Reset Value */

#define SDMMC_ASAR_ADMASA_Pos                 _UINT32_(0)                                          /* (SDMMC_ASAR) ADMA System Address Position */
#define SDMMC_ASAR_ADMASA_Msk                 (_UINT32_(0xFFFFFFFF) << SDMMC_ASAR_ADMASA_Pos)      /* (SDMMC_ASAR) ADMA System Address Mask */
#define SDMMC_ASAR_ADMASA(value)              (SDMMC_ASAR_ADMASA_Msk & (_UINT32_(value) << SDMMC_ASAR_ADMASA_Pos)) /* Assigment of value for ADMASA in the SDMMC_ASAR register */
#define SDMMC_ASAR_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (SDMMC_ASAR) Register Mask  */


/* -------- SDMMC_PVR : (SDMMC Offset: 0x60) (R/W 16) Preset Value n -------- */
#define SDMMC_PVR_RESETVALUE                  _UINT16_(0x00)                                       /*  (SDMMC_PVR) Preset Value n  Reset Value */

#define SDMMC_PVR_SDCLKFSEL_Pos               _UINT16_(0)                                          /* (SDMMC_PVR) SDCLK Frequency Select Value for Initialization Position */
#define SDMMC_PVR_SDCLKFSEL_Msk               (_UINT16_(0x3FF) << SDMMC_PVR_SDCLKFSEL_Pos)         /* (SDMMC_PVR) SDCLK Frequency Select Value for Initialization Mask */
#define SDMMC_PVR_SDCLKFSEL(value)            (SDMMC_PVR_SDCLKFSEL_Msk & (_UINT16_(value) << SDMMC_PVR_SDCLKFSEL_Pos)) /* Assigment of value for SDCLKFSEL in the SDMMC_PVR register */
#define SDMMC_PVR_CLKGSEL_Pos                 _UINT16_(10)                                         /* (SDMMC_PVR) Clock Generator Select Value for Initialization Position */
#define SDMMC_PVR_CLKGSEL_Msk                 (_UINT16_(0x1) << SDMMC_PVR_CLKGSEL_Pos)             /* (SDMMC_PVR) Clock Generator Select Value for Initialization Mask */
#define SDMMC_PVR_CLKGSEL(value)              (SDMMC_PVR_CLKGSEL_Msk & (_UINT16_(value) << SDMMC_PVR_CLKGSEL_Pos)) /* Assigment of value for CLKGSEL in the SDMMC_PVR register */
#define   SDMMC_PVR_CLKGSEL_DIV_Val           _UINT16_(0x0)                                        /* (SDMMC_PVR) Host Controller Ver2.00 Compatible Clock Generator (Divider)  */
#define   SDMMC_PVR_CLKGSEL_PROG_Val          _UINT16_(0x1)                                        /* (SDMMC_PVR) Programmable Clock Generator  */
#define SDMMC_PVR_CLKGSEL_DIV                 (SDMMC_PVR_CLKGSEL_DIV_Val << SDMMC_PVR_CLKGSEL_Pos) /* (SDMMC_PVR) Host Controller Ver2.00 Compatible Clock Generator (Divider) Position  */
#define SDMMC_PVR_CLKGSEL_PROG                (SDMMC_PVR_CLKGSEL_PROG_Val << SDMMC_PVR_CLKGSEL_Pos) /* (SDMMC_PVR) Programmable Clock Generator Position  */
#define SDMMC_PVR_DRVSEL_Pos                  _UINT16_(14)                                         /* (SDMMC_PVR) Driver Strength Select Value for Initialization Position */
#define SDMMC_PVR_DRVSEL_Msk                  (_UINT16_(0x3) << SDMMC_PVR_DRVSEL_Pos)              /* (SDMMC_PVR) Driver Strength Select Value for Initialization Mask */
#define SDMMC_PVR_DRVSEL(value)               (SDMMC_PVR_DRVSEL_Msk & (_UINT16_(value) << SDMMC_PVR_DRVSEL_Pos)) /* Assigment of value for DRVSEL in the SDMMC_PVR register */
#define   SDMMC_PVR_DRVSEL_B_Val              _UINT16_(0x0)                                        /* (SDMMC_PVR) Driver Type B is Selected  */
#define   SDMMC_PVR_DRVSEL_A_Val              _UINT16_(0x1)                                        /* (SDMMC_PVR) Driver Type A is Selected  */
#define   SDMMC_PVR_DRVSEL_C_Val              _UINT16_(0x2)                                        /* (SDMMC_PVR) Driver Type C is Selected  */
#define   SDMMC_PVR_DRVSEL_D_Val              _UINT16_(0x3)                                        /* (SDMMC_PVR) Driver Type D is Selected  */
#define SDMMC_PVR_DRVSEL_B                    (SDMMC_PVR_DRVSEL_B_Val << SDMMC_PVR_DRVSEL_Pos)     /* (SDMMC_PVR) Driver Type B is Selected Position  */
#define SDMMC_PVR_DRVSEL_A                    (SDMMC_PVR_DRVSEL_A_Val << SDMMC_PVR_DRVSEL_Pos)     /* (SDMMC_PVR) Driver Type A is Selected Position  */
#define SDMMC_PVR_DRVSEL_C                    (SDMMC_PVR_DRVSEL_C_Val << SDMMC_PVR_DRVSEL_Pos)     /* (SDMMC_PVR) Driver Type C is Selected Position  */
#define SDMMC_PVR_DRVSEL_D                    (SDMMC_PVR_DRVSEL_D_Val << SDMMC_PVR_DRVSEL_Pos)     /* (SDMMC_PVR) Driver Type D is Selected Position  */
#define SDMMC_PVR_Msk                         _UINT16_(0xC7FF)                                     /* (SDMMC_PVR) Register Mask  */


/* -------- SDMMC_SISR : (SDMMC Offset: 0xFC) ( R/ 16) Slot Interrupt Status -------- */
#define SDMMC_SISR_RESETVALUE                 _UINT16_(0x00)                                       /*  (SDMMC_SISR) Slot Interrupt Status  Reset Value */

#define SDMMC_SISR_INTSSL_Pos                 _UINT16_(0)                                          /* (SDMMC_SISR) Interrupt Signal for Each Slot Position */
#define SDMMC_SISR_INTSSL_Msk                 (_UINT16_(0x3) << SDMMC_SISR_INTSSL_Pos)             /* (SDMMC_SISR) Interrupt Signal for Each Slot Mask */
#define SDMMC_SISR_INTSSL(value)              (SDMMC_SISR_INTSSL_Msk & (_UINT16_(value) << SDMMC_SISR_INTSSL_Pos)) /* Assigment of value for INTSSL in the SDMMC_SISR register */
#define SDMMC_SISR_Msk                        _UINT16_(0x0003)                                     /* (SDMMC_SISR) Register Mask  */


/* -------- SDMMC_HCVR : (SDMMC Offset: 0xFE) ( R/ 16) Host Controller Version -------- */
#define SDMMC_HCVR_RESETVALUE                 _UINT16_(0x2002)                                     /*  (SDMMC_HCVR) Host Controller Version  Reset Value */

#define SDMMC_HCVR_SVER_Pos                   _UINT16_(0)                                          /* (SDMMC_HCVR) Spec Version Position */
#define SDMMC_HCVR_SVER_Msk                   (_UINT16_(0xFF) << SDMMC_HCVR_SVER_Pos)              /* (SDMMC_HCVR) Spec Version Mask */
#define SDMMC_HCVR_SVER(value)                (SDMMC_HCVR_SVER_Msk & (_UINT16_(value) << SDMMC_HCVR_SVER_Pos)) /* Assigment of value for SVER in the SDMMC_HCVR register */
#define SDMMC_HCVR_VVER_Pos                   _UINT16_(8)                                          /* (SDMMC_HCVR) Vendor Version Position */
#define SDMMC_HCVR_VVER_Msk                   (_UINT16_(0xFF) << SDMMC_HCVR_VVER_Pos)              /* (SDMMC_HCVR) Vendor Version Mask */
#define SDMMC_HCVR_VVER(value)                (SDMMC_HCVR_VVER_Msk & (_UINT16_(value) << SDMMC_HCVR_VVER_Pos)) /* Assigment of value for VVER in the SDMMC_HCVR register */
#define SDMMC_HCVR_Msk                        _UINT16_(0xFFFF)                                     /* (SDMMC_HCVR) Register Mask  */


/* -------- SDMMC_MC1R : (SDMMC Offset: 0x204) (R/W 8) e.MMC Control 1 -------- */
#define SDMMC_MC1R_RESETVALUE                 _UINT8_(0x00)                                        /*  (SDMMC_MC1R) e.MMC Control 1  Reset Value */

#define SDMMC_MC1R_CMDTYP_Pos                 _UINT8_(0)                                           /* (SDMMC_MC1R) e.MMC Command Type Position */
#define SDMMC_MC1R_CMDTYP_Msk                 (_UINT8_(0x3) << SDMMC_MC1R_CMDTYP_Pos)              /* (SDMMC_MC1R) e.MMC Command Type Mask */
#define SDMMC_MC1R_CMDTYP(value)              (SDMMC_MC1R_CMDTYP_Msk & (_UINT8_(value) << SDMMC_MC1R_CMDTYP_Pos)) /* Assigment of value for CMDTYP in the SDMMC_MC1R register */
#define   SDMMC_MC1R_CMDTYP_NORMAL_Val        _UINT8_(0x0)                                         /* (SDMMC_MC1R) Not a MMC specific command  */
#define   SDMMC_MC1R_CMDTYP_WAITIRQ_Val       _UINT8_(0x1)                                         /* (SDMMC_MC1R) Wait IRQ Command  */
#define   SDMMC_MC1R_CMDTYP_STREAM_Val        _UINT8_(0x2)                                         /* (SDMMC_MC1R) Stream Command  */
#define   SDMMC_MC1R_CMDTYP_BOOT_Val          _UINT8_(0x3)                                         /* (SDMMC_MC1R) Boot Command  */
#define SDMMC_MC1R_CMDTYP_NORMAL              (SDMMC_MC1R_CMDTYP_NORMAL_Val << SDMMC_MC1R_CMDTYP_Pos) /* (SDMMC_MC1R) Not a MMC specific command Position  */
#define SDMMC_MC1R_CMDTYP_WAITIRQ             (SDMMC_MC1R_CMDTYP_WAITIRQ_Val << SDMMC_MC1R_CMDTYP_Pos) /* (SDMMC_MC1R) Wait IRQ Command Position  */
#define SDMMC_MC1R_CMDTYP_STREAM              (SDMMC_MC1R_CMDTYP_STREAM_Val << SDMMC_MC1R_CMDTYP_Pos) /* (SDMMC_MC1R) Stream Command Position  */
#define SDMMC_MC1R_CMDTYP_BOOT                (SDMMC_MC1R_CMDTYP_BOOT_Val << SDMMC_MC1R_CMDTYP_Pos) /* (SDMMC_MC1R) Boot Command Position  */
#define SDMMC_MC1R_DDR_Pos                    _UINT8_(3)                                           /* (SDMMC_MC1R) e.MMC HSDDR Mode Position */
#define SDMMC_MC1R_DDR_Msk                    (_UINT8_(0x1) << SDMMC_MC1R_DDR_Pos)                 /* (SDMMC_MC1R) e.MMC HSDDR Mode Mask */
#define SDMMC_MC1R_DDR(value)                 (SDMMC_MC1R_DDR_Msk & (_UINT8_(value) << SDMMC_MC1R_DDR_Pos)) /* Assigment of value for DDR in the SDMMC_MC1R register */
#define SDMMC_MC1R_OPD_Pos                    _UINT8_(4)                                           /* (SDMMC_MC1R) e.MMC Open Drain Mode Position */
#define SDMMC_MC1R_OPD_Msk                    (_UINT8_(0x1) << SDMMC_MC1R_OPD_Pos)                 /* (SDMMC_MC1R) e.MMC Open Drain Mode Mask */
#define SDMMC_MC1R_OPD(value)                 (SDMMC_MC1R_OPD_Msk & (_UINT8_(value) << SDMMC_MC1R_OPD_Pos)) /* Assigment of value for OPD in the SDMMC_MC1R register */
#define SDMMC_MC1R_BOOTA_Pos                  _UINT8_(5)                                           /* (SDMMC_MC1R) e.MMC Boot Acknowledge Enable Position */
#define SDMMC_MC1R_BOOTA_Msk                  (_UINT8_(0x1) << SDMMC_MC1R_BOOTA_Pos)               /* (SDMMC_MC1R) e.MMC Boot Acknowledge Enable Mask */
#define SDMMC_MC1R_BOOTA(value)               (SDMMC_MC1R_BOOTA_Msk & (_UINT8_(value) << SDMMC_MC1R_BOOTA_Pos)) /* Assigment of value for BOOTA in the SDMMC_MC1R register */
#define SDMMC_MC1R_RSTN_Pos                   _UINT8_(6)                                           /* (SDMMC_MC1R) e.MMC Reset Signal Position */
#define SDMMC_MC1R_RSTN_Msk                   (_UINT8_(0x1) << SDMMC_MC1R_RSTN_Pos)                /* (SDMMC_MC1R) e.MMC Reset Signal Mask */
#define SDMMC_MC1R_RSTN(value)                (SDMMC_MC1R_RSTN_Msk & (_UINT8_(value) << SDMMC_MC1R_RSTN_Pos)) /* Assigment of value for RSTN in the SDMMC_MC1R register */
#define SDMMC_MC1R_FCD_Pos                    _UINT8_(7)                                           /* (SDMMC_MC1R) e.MMC Force Card Detect Position */
#define SDMMC_MC1R_FCD_Msk                    (_UINT8_(0x1) << SDMMC_MC1R_FCD_Pos)                 /* (SDMMC_MC1R) e.MMC Force Card Detect Mask */
#define SDMMC_MC1R_FCD(value)                 (SDMMC_MC1R_FCD_Msk & (_UINT8_(value) << SDMMC_MC1R_FCD_Pos)) /* Assigment of value for FCD in the SDMMC_MC1R register */
#define SDMMC_MC1R_Msk                        _UINT8_(0xFB)                                        /* (SDMMC_MC1R) Register Mask  */


/* -------- SDMMC_MC2R : (SDMMC Offset: 0x205) ( /W 8) e.MMC Control 2 -------- */
#define SDMMC_MC2R_RESETVALUE                 _UINT8_(0x00)                                        /*  (SDMMC_MC2R) e.MMC Control 2  Reset Value */

#define SDMMC_MC2R_SRESP_Pos                  _UINT8_(0)                                           /* (SDMMC_MC2R) e.MMC Abort Wait IRQ Position */
#define SDMMC_MC2R_SRESP_Msk                  (_UINT8_(0x1) << SDMMC_MC2R_SRESP_Pos)               /* (SDMMC_MC2R) e.MMC Abort Wait IRQ Mask */
#define SDMMC_MC2R_SRESP(value)               (SDMMC_MC2R_SRESP_Msk & (_UINT8_(value) << SDMMC_MC2R_SRESP_Pos)) /* Assigment of value for SRESP in the SDMMC_MC2R register */
#define SDMMC_MC2R_ABOOT_Pos                  _UINT8_(1)                                           /* (SDMMC_MC2R) e.MMC Abort Boot Position */
#define SDMMC_MC2R_ABOOT_Msk                  (_UINT8_(0x1) << SDMMC_MC2R_ABOOT_Pos)               /* (SDMMC_MC2R) e.MMC Abort Boot Mask */
#define SDMMC_MC2R_ABOOT(value)               (SDMMC_MC2R_ABOOT_Msk & (_UINT8_(value) << SDMMC_MC2R_ABOOT_Pos)) /* Assigment of value for ABOOT in the SDMMC_MC2R register */
#define SDMMC_MC2R_Msk                        _UINT8_(0x03)                                        /* (SDMMC_MC2R) Register Mask  */


/* -------- SDMMC_DEBR : (SDMMC Offset: 0x207) (R/W 8) Debounce Register -------- */
#define SDMMC_DEBR_RESETVALUE                 _UINT8_(0x03)                                        /*  (SDMMC_DEBR) Debounce Register  Reset Value */

#define SDMMC_DEBR_CDDVAL_Pos                 _UINT8_(0)                                           /* (SDMMC_DEBR) Card Detect Debounce Value Position */
#define SDMMC_DEBR_CDDVAL_Msk                 (_UINT8_(0x3) << SDMMC_DEBR_CDDVAL_Pos)              /* (SDMMC_DEBR) Card Detect Debounce Value Mask */
#define SDMMC_DEBR_CDDVAL(value)              (SDMMC_DEBR_CDDVAL_Msk & (_UINT8_(value) << SDMMC_DEBR_CDDVAL_Pos)) /* Assigment of value for CDDVAL in the SDMMC_DEBR register */
#define   SDMMC_DEBR_CDDVAL_1CYCLE_Val        _UINT8_(0x0)                                         /* (SDMMC_DEBR) 1 slow clock cycle  */
#define   SDMMC_DEBR_CDDVAL_8CYCLES_Val       _UINT8_(0x1)                                         /* (SDMMC_DEBR) 8 slow clock cycles  */
#define   SDMMC_DEBR_CDDVAL_33CYCLES_Val      _UINT8_(0x2)                                         /* (SDMMC_DEBR) 33 slow clock cycle  */
#define   SDMMC_DEBR_CDDVAL_328CYCLES_Val     _UINT8_(0x3)                                         /* (SDMMC_DEBR) 328 slow clock cycle  */
#define SDMMC_DEBR_CDDVAL_1CYCLE              (SDMMC_DEBR_CDDVAL_1CYCLE_Val << SDMMC_DEBR_CDDVAL_Pos) /* (SDMMC_DEBR) 1 slow clock cycle Position  */
#define SDMMC_DEBR_CDDVAL_8CYCLES             (SDMMC_DEBR_CDDVAL_8CYCLES_Val << SDMMC_DEBR_CDDVAL_Pos) /* (SDMMC_DEBR) 8 slow clock cycles Position  */
#define SDMMC_DEBR_CDDVAL_33CYCLES            (SDMMC_DEBR_CDDVAL_33CYCLES_Val << SDMMC_DEBR_CDDVAL_Pos) /* (SDMMC_DEBR) 33 slow clock cycle Position  */
#define SDMMC_DEBR_CDDVAL_328CYCLES           (SDMMC_DEBR_CDDVAL_328CYCLES_Val << SDMMC_DEBR_CDDVAL_Pos) /* (SDMMC_DEBR) 328 slow clock cycle Position  */
#define SDMMC_DEBR_Msk                        _UINT8_(0x03)                                        /* (SDMMC_DEBR) Register Mask  */


/* -------- SDMMC_ACR : (SDMMC Offset: 0x208) (R/W 32) AHB Control -------- */
#define SDMMC_ACR_RESETVALUE                  _UINT32_(0x00)                                       /*  (SDMMC_ACR) AHB Control  Reset Value */

#define SDMMC_ACR_BMAX_Pos                    _UINT32_(0)                                          /* (SDMMC_ACR) AHB Maximum Burst Position */
#define SDMMC_ACR_BMAX_Msk                    (_UINT32_(0x3) << SDMMC_ACR_BMAX_Pos)                /* (SDMMC_ACR) AHB Maximum Burst Mask */
#define SDMMC_ACR_BMAX(value)                 (SDMMC_ACR_BMAX_Msk & (_UINT32_(value) << SDMMC_ACR_BMAX_Pos)) /* Assigment of value for BMAX in the SDMMC_ACR register */
#define   SDMMC_ACR_BMAX_INCR16_Val           _UINT32_(0x0)                                        /* (SDMMC_ACR)   */
#define   SDMMC_ACR_BMAX_INCR8_Val            _UINT32_(0x1)                                        /* (SDMMC_ACR)   */
#define   SDMMC_ACR_BMAX_INCR4_Val            _UINT32_(0x2)                                        /* (SDMMC_ACR)   */
#define   SDMMC_ACR_BMAX_SINGLE_Val           _UINT32_(0x3)                                        /* (SDMMC_ACR)   */
#define SDMMC_ACR_BMAX_INCR16                 (SDMMC_ACR_BMAX_INCR16_Val << SDMMC_ACR_BMAX_Pos)    /* (SDMMC_ACR)  Position  */
#define SDMMC_ACR_BMAX_INCR8                  (SDMMC_ACR_BMAX_INCR8_Val << SDMMC_ACR_BMAX_Pos)     /* (SDMMC_ACR)  Position  */
#define SDMMC_ACR_BMAX_INCR4                  (SDMMC_ACR_BMAX_INCR4_Val << SDMMC_ACR_BMAX_Pos)     /* (SDMMC_ACR)  Position  */
#define SDMMC_ACR_BMAX_SINGLE                 (SDMMC_ACR_BMAX_SINGLE_Val << SDMMC_ACR_BMAX_Pos)    /* (SDMMC_ACR)  Position  */
#define SDMMC_ACR_Msk                         _UINT32_(0x00000003)                                 /* (SDMMC_ACR) Register Mask  */


/* -------- SDMMC_CC2R : (SDMMC Offset: 0x20C) (R/W 32) Clock Control 2 -------- */
#define SDMMC_CC2R_RESETVALUE                 _UINT32_(0x00)                                       /*  (SDMMC_CC2R) Clock Control 2  Reset Value */

#define SDMMC_CC2R_FSDCLKD_Pos                _UINT32_(0)                                          /* (SDMMC_CC2R) Force SDCK Disabled Position */
#define SDMMC_CC2R_FSDCLKD_Msk                (_UINT32_(0x1) << SDMMC_CC2R_FSDCLKD_Pos)            /* (SDMMC_CC2R) Force SDCK Disabled Mask */
#define SDMMC_CC2R_FSDCLKD(value)             (SDMMC_CC2R_FSDCLKD_Msk & (_UINT32_(value) << SDMMC_CC2R_FSDCLKD_Pos)) /* Assigment of value for FSDCLKD in the SDMMC_CC2R register */
#define   SDMMC_CC2R_FSDCLKD_NOEFFECT_Val     _UINT32_(0x0)                                        /* (SDMMC_CC2R) No effect  */
#define   SDMMC_CC2R_FSDCLKD_DISABLE_Val      _UINT32_(0x1)                                        /* (SDMMC_CC2R) SDCLK can be stopped at any time after DATA transfer.SDCLK enable forcing for 8 SDCLK cycles is disabled  */
#define SDMMC_CC2R_FSDCLKD_NOEFFECT           (SDMMC_CC2R_FSDCLKD_NOEFFECT_Val << SDMMC_CC2R_FSDCLKD_Pos) /* (SDMMC_CC2R) No effect Position  */
#define SDMMC_CC2R_FSDCLKD_DISABLE            (SDMMC_CC2R_FSDCLKD_DISABLE_Val << SDMMC_CC2R_FSDCLKD_Pos) /* (SDMMC_CC2R) SDCLK can be stopped at any time after DATA transfer.SDCLK enable forcing for 8 SDCLK cycles is disabled Position  */
#define SDMMC_CC2R_Msk                        _UINT32_(0x00000001)                                 /* (SDMMC_CC2R) Register Mask  */


/* -------- SDMMC_CACR : (SDMMC Offset: 0x230) (R/W 32) Capabilities Control -------- */
#define SDMMC_CACR_RESETVALUE                 _UINT32_(0x00)                                       /*  (SDMMC_CACR) Capabilities Control  Reset Value */

#define SDMMC_CACR_CAPWREN_Pos                _UINT32_(0)                                          /* (SDMMC_CACR) Capabilities Registers Write Enable (Required to write the correct frequencies in the Capabilities Registers) Position */
#define SDMMC_CACR_CAPWREN_Msk                (_UINT32_(0x1) << SDMMC_CACR_CAPWREN_Pos)            /* (SDMMC_CACR) Capabilities Registers Write Enable (Required to write the correct frequencies in the Capabilities Registers) Mask */
#define SDMMC_CACR_CAPWREN(value)             (SDMMC_CACR_CAPWREN_Msk & (_UINT32_(value) << SDMMC_CACR_CAPWREN_Pos)) /* Assigment of value for CAPWREN in the SDMMC_CACR register */
#define SDMMC_CACR_KEY_Pos                    _UINT32_(8)                                          /* (SDMMC_CACR) Key (0x46) Position */
#define SDMMC_CACR_KEY_Msk                    (_UINT32_(0xFF) << SDMMC_CACR_KEY_Pos)               /* (SDMMC_CACR) Key (0x46) Mask */
#define SDMMC_CACR_KEY(value)                 (SDMMC_CACR_KEY_Msk & (_UINT32_(value) << SDMMC_CACR_KEY_Pos)) /* Assigment of value for KEY in the SDMMC_CACR register */
#define SDMMC_CACR_Msk                        _UINT32_(0x0000FF01)                                 /* (SDMMC_CACR) Register Mask  */


/* -------- SDMMC_DBGR : (SDMMC Offset: 0x234) (R/W 32) Debug -------- */
#define SDMMC_DBGR_RESETVALUE                 _UINT32_(0x02)                                       /*  (SDMMC_DBGR) Debug  Reset Value */

#define SDMMC_DBGR_NIDBG_Pos                  _UINT32_(0)                                          /* (SDMMC_DBGR) Non-intrusive debug enable Position */
#define SDMMC_DBGR_NIDBG_Msk                  (_UINT32_(0x1) << SDMMC_DBGR_NIDBG_Pos)              /* (SDMMC_DBGR) Non-intrusive debug enable Mask */
#define SDMMC_DBGR_NIDBG(value)               (SDMMC_DBGR_NIDBG_Msk & (_UINT32_(value) << SDMMC_DBGR_NIDBG_Pos)) /* Assigment of value for NIDBG in the SDMMC_DBGR register */
#define   SDMMC_DBGR_NIDBG_IDBG_Val           _UINT32_(0x0)                                        /* (SDMMC_DBGR) Debugging is intrusive (reads of BDPR from debugger are considered and increment the internal buffer pointer)  */
#define   SDMMC_DBGR_NIDBG_NIDBG_Val          _UINT32_(0x1)                                        /* (SDMMC_DBGR) Debugging is not intrusive (reads of BDPR from debugger are discarded and do not increment the internal buffer pointer)  */
#define SDMMC_DBGR_NIDBG_IDBG                 (SDMMC_DBGR_NIDBG_IDBG_Val << SDMMC_DBGR_NIDBG_Pos)  /* (SDMMC_DBGR) Debugging is intrusive (reads of BDPR from debugger are considered and increment the internal buffer pointer) Position  */
#define SDMMC_DBGR_NIDBG_NIDBG                (SDMMC_DBGR_NIDBG_NIDBG_Val << SDMMC_DBGR_NIDBG_Pos) /* (SDMMC_DBGR) Debugging is not intrusive (reads of BDPR from debugger are discarded and do not increment the internal buffer pointer) Position  */
#define SDMMC_DBGR_Msk                        _UINT32_(0x00000001)                                 /* (SDMMC_DBGR) Register Mask  */


/** \brief SDMMC register offsets definitions */
#define SDMMC_SSAR_REG_OFST            _UINT32_(0x00)      /* (SDMMC_SSAR) SDMA System Address / Argument 2 Offset */
#define SDMMC_BSR_REG_OFST             _UINT32_(0x04)      /* (SDMMC_BSR) Block Size Offset */
#define SDMMC_BCR_REG_OFST             _UINT32_(0x06)      /* (SDMMC_BCR) Block Count Offset */
#define SDMMC_ARG1R_REG_OFST           _UINT32_(0x08)      /* (SDMMC_ARG1R) Argument 1 Offset */
#define SDMMC_TMR_REG_OFST             _UINT32_(0x0C)      /* (SDMMC_TMR) Transfer Mode Offset */
#define SDMMC_CR_REG_OFST              _UINT32_(0x0E)      /* (SDMMC_CR) Command Offset */
#define SDMMC_RR_REG_OFST              _UINT32_(0x10)      /* (SDMMC_RR) Response Offset */
#define SDMMC_RR0_REG_OFST             _UINT32_(0x10)      /* (SDMMC_RR0) Response Offset */
#define SDMMC_RR1_REG_OFST             _UINT32_(0x14)      /* (SDMMC_RR1) Response Offset */
#define SDMMC_RR2_REG_OFST             _UINT32_(0x18)      /* (SDMMC_RR2) Response Offset */
#define SDMMC_RR3_REG_OFST             _UINT32_(0x1C)      /* (SDMMC_RR3) Response Offset */
#define SDMMC_BDPR_REG_OFST            _UINT32_(0x20)      /* (SDMMC_BDPR) Buffer Data Port Offset */
#define SDMMC_PSR_REG_OFST             _UINT32_(0x24)      /* (SDMMC_PSR) Present State Offset */
#define SDMMC_HC1R_REG_OFST            _UINT32_(0x28)      /* (SDMMC_HC1R) Host Control 1 Offset */
#define SDMMC_PCR_REG_OFST             _UINT32_(0x29)      /* (SDMMC_PCR) Power Control Offset */
#define SDMMC_BGCR_REG_OFST            _UINT32_(0x2A)      /* (SDMMC_BGCR) Block Gap Control Offset */
#define SDMMC_WCR_REG_OFST             _UINT32_(0x2B)      /* (SDMMC_WCR) Wakeup Control Offset */
#define SDMMC_CCR_REG_OFST             _UINT32_(0x2C)      /* (SDMMC_CCR) Clock Control Offset */
#define SDMMC_TCR_REG_OFST             _UINT32_(0x2E)      /* (SDMMC_TCR) Timeout Control Offset */
#define SDMMC_SRR_REG_OFST             _UINT32_(0x2F)      /* (SDMMC_SRR) Software Reset Offset */
#define SDMMC_NISTR_REG_OFST           _UINT32_(0x30)      /* (SDMMC_NISTR) Normal Interrupt Status Offset */
#define SDMMC_EISTR_REG_OFST           _UINT32_(0x32)      /* (SDMMC_EISTR) Error Interrupt Status Offset */
#define SDMMC_NISTER_REG_OFST          _UINT32_(0x34)      /* (SDMMC_NISTER) Normal Interrupt Status Enable Offset */
#define SDMMC_EISTER_REG_OFST          _UINT32_(0x36)      /* (SDMMC_EISTER) Error Interrupt Status Enable Offset */
#define SDMMC_NISIER_REG_OFST          _UINT32_(0x38)      /* (SDMMC_NISIER) Normal Interrupt Signal Enable Offset */
#define SDMMC_EISIER_REG_OFST          _UINT32_(0x3A)      /* (SDMMC_EISIER) Error Interrupt Signal Enable Offset */
#define SDMMC_ACESR_REG_OFST           _UINT32_(0x3C)      /* (SDMMC_ACESR) Auto CMD Error Status Offset */
#define SDMMC_HC2R_REG_OFST            _UINT32_(0x3E)      /* (SDMMC_HC2R) Host Control 2 Offset */
#define SDMMC_CA0R_REG_OFST            _UINT32_(0x40)      /* (SDMMC_CA0R) Capabilities 0 Offset */
#define SDMMC_CA1R_REG_OFST            _UINT32_(0x44)      /* (SDMMC_CA1R) Capabilities 1 Offset */
#define SDMMC_MCCAR_REG_OFST           _UINT32_(0x48)      /* (SDMMC_MCCAR) Maximum Current Capabilities Offset */
#define SDMMC_FERACES_REG_OFST         _UINT32_(0x50)      /* (SDMMC_FERACES) Force Event for Auto CMD Error Status Offset */
#define SDMMC_FEREIS_REG_OFST          _UINT32_(0x52)      /* (SDMMC_FEREIS) Force Event for Error Interrupt Status Offset */
#define SDMMC_AESR_REG_OFST            _UINT32_(0x54)      /* (SDMMC_AESR) ADMA Error Status Offset */
#define SDMMC_ASAR_REG_OFST            _UINT32_(0x58)      /* (SDMMC_ASAR) ADMA System Address n Offset */
#define SDMMC_PVR_REG_OFST             _UINT32_(0x60)      /* (SDMMC_PVR) Preset Value n Offset */
#define SDMMC_PVR0_REG_OFST            _UINT32_(0x60)      /* (SDMMC_PVR0) Preset Value n Offset */
#define SDMMC_PVR1_REG_OFST            _UINT32_(0x62)      /* (SDMMC_PVR1) Preset Value n Offset */
#define SDMMC_PVR2_REG_OFST            _UINT32_(0x64)      /* (SDMMC_PVR2) Preset Value n Offset */
#define SDMMC_SISR_REG_OFST            _UINT32_(0xFC)      /* (SDMMC_SISR) Slot Interrupt Status Offset */
#define SDMMC_HCVR_REG_OFST            _UINT32_(0xFE)      /* (SDMMC_HCVR) Host Controller Version Offset */
#define SDMMC_MC1R_REG_OFST            _UINT32_(0x204)     /* (SDMMC_MC1R) e.MMC Control 1 Offset */
#define SDMMC_MC2R_REG_OFST            _UINT32_(0x205)     /* (SDMMC_MC2R) e.MMC Control 2 Offset */
#define SDMMC_DEBR_REG_OFST            _UINT32_(0x207)     /* (SDMMC_DEBR) Debounce Register Offset */
#define SDMMC_ACR_REG_OFST             _UINT32_(0x208)     /* (SDMMC_ACR) AHB Control Offset */
#define SDMMC_CC2R_REG_OFST            _UINT32_(0x20C)     /* (SDMMC_CC2R) Clock Control 2 Offset */
#define SDMMC_CACR_REG_OFST            _UINT32_(0x230)     /* (SDMMC_CACR) Capabilities Control Offset */
#define SDMMC_DBGR_REG_OFST            _UINT32_(0x234)     /* (SDMMC_DBGR) Debug Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief SDMMC register API structure */
typedef struct
{  /* SD/MMC Host Controller */
  __IO  uint32_t                       SDMMC_SSAR;         /**< Offset: 0x00 (R/W  32) SDMA System Address / Argument 2 */
  __IO  uint16_t                       SDMMC_BSR;          /**< Offset: 0x04 (R/W  16) Block Size */
  __IO  uint16_t                       SDMMC_BCR;          /**< Offset: 0x06 (R/W  16) Block Count */
  __IO  uint32_t                       SDMMC_ARG1R;        /**< Offset: 0x08 (R/W  32) Argument 1 */
  __IO  uint16_t                       SDMMC_TMR;          /**< Offset: 0x0C (R/W  16) Transfer Mode */
  __IO  uint16_t                       SDMMC_CR;           /**< Offset: 0x0E (R/W  16) Command */
  __I   uint32_t                       SDMMC_RR[4];        /**< Offset: 0x10 (R/   32) Response */
  __IO  uint32_t                       SDMMC_BDPR;         /**< Offset: 0x20 (R/W  32) Buffer Data Port */
  __I   uint32_t                       SDMMC_PSR;          /**< Offset: 0x24 (R/   32) Present State */
  __IO  uint8_t                        SDMMC_HC1R;         /**< Offset: 0x28 (R/W  8) Host Control 1 */
  __IO  uint8_t                        SDMMC_PCR;          /**< Offset: 0x29 (R/W  8) Power Control */
  __IO  uint8_t                        SDMMC_BGCR;         /**< Offset: 0x2A (R/W  8) Block Gap Control */
  __IO  uint8_t                        SDMMC_WCR;          /**< Offset: 0x2B (R/W  8) Wakeup Control */
  __IO  uint16_t                       SDMMC_CCR;          /**< Offset: 0x2C (R/W  16) Clock Control */
  __IO  uint8_t                        SDMMC_TCR;          /**< Offset: 0x2E (R/W  8) Timeout Control */
  __IO  uint8_t                        SDMMC_SRR;          /**< Offset: 0x2F (R/W  8) Software Reset */
  __IO  uint16_t                       SDMMC_NISTR;        /**< Offset: 0x30 (R/W  16) Normal Interrupt Status */
  __IO  uint16_t                       SDMMC_EISTR;        /**< Offset: 0x32 (R/W  16) Error Interrupt Status */
  __IO  uint16_t                       SDMMC_NISTER;       /**< Offset: 0x34 (R/W  16) Normal Interrupt Status Enable */
  __IO  uint16_t                       SDMMC_EISTER;       /**< Offset: 0x36 (R/W  16) Error Interrupt Status Enable */
  __IO  uint16_t                       SDMMC_NISIER;       /**< Offset: 0x38 (R/W  16) Normal Interrupt Signal Enable */
  __IO  uint16_t                       SDMMC_EISIER;       /**< Offset: 0x3A (R/W  16) Error Interrupt Signal Enable */
  __I   uint16_t                       SDMMC_ACESR;        /**< Offset: 0x3C (R/   16) Auto CMD Error Status */
  __IO  uint16_t                       SDMMC_HC2R;         /**< Offset: 0x3E (R/W  16) Host Control 2 */
  __IO  uint32_t                       SDMMC_CA0R;         /**< Offset: 0x40 (R/W  32) Capabilities 0 */
  __IO  uint32_t                       SDMMC_CA1R;         /**< Offset: 0x44 (R/W  32) Capabilities 1 */
  __I   uint32_t                       SDMMC_MCCAR;        /**< Offset: 0x48 (R/   32) Maximum Current Capabilities */
  __I   uint8_t                        Reserved1[0x04];
  __O   uint16_t                       SDMMC_FERACES;      /**< Offset: 0x50 ( /W  16) Force Event for Auto CMD Error Status */
  __O   uint16_t                       SDMMC_FEREIS;       /**< Offset: 0x52 ( /W  16) Force Event for Error Interrupt Status */
  __I   uint8_t                        SDMMC_AESR;         /**< Offset: 0x54 (R/   8) ADMA Error Status */
  __I   uint8_t                        Reserved2[0x03];
  __IO  uint32_t                       SDMMC_ASAR;         /**< Offset: 0x58 (R/W  32) ADMA System Address n */
  __I   uint8_t                        Reserved3[0x04];
  __IO  uint16_t                       SDMMC_PVR[3];       /**< Offset: 0x60 (R/W  16) Preset Value n */
  __I   uint8_t                        Reserved4[0x96];
  __I   uint16_t                       SDMMC_SISR;         /**< Offset: 0xFC (R/   16) Slot Interrupt Status */
  __I   uint16_t                       SDMMC_HCVR;         /**< Offset: 0xFE (R/   16) Host Controller Version */
  __I   uint8_t                        Reserved5[0x104];
  __IO  uint8_t                        SDMMC_MC1R;         /**< Offset: 0x204 (R/W  8) e.MMC Control 1 */
  __O   uint8_t                        SDMMC_MC2R;         /**< Offset: 0x205 ( /W  8) e.MMC Control 2 */
  __I   uint8_t                        Reserved6[0x01];
  __IO  uint8_t                        SDMMC_DEBR;         /**< Offset: 0x207 (R/W  8) Debounce Register */
  __IO  uint32_t                       SDMMC_ACR;          /**< Offset: 0x208 (R/W  32) AHB Control */
  __IO  uint32_t                       SDMMC_CC2R;         /**< Offset: 0x20C (R/W  32) Clock Control 2 */
  __I   uint8_t                        Reserved7[0x20];
  __IO  uint32_t                       SDMMC_CACR;         /**< Offset: 0x230 (R/W  32) Capabilities Control */
  __IO  uint32_t                       SDMMC_DBGR;         /**< Offset: 0x234 (R/W  32) Debug */
} sdmmc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA80_SDMMC_COMPONENT_H_ */
