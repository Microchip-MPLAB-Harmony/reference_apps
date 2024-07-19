/*
 * Component description for IDAU
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
#ifndef _PIC32CKGC01_IDAU_COMPONENT_H_
#define _PIC32CKGC01_IDAU_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR IDAU                                         */
/* ************************************************************************** */

/* -------- IDAU_RCTRL : (IDAU Offset: 0x00) ( /W 32) Region Control -------- */
#define IDAU_RCTRL_RESETVALUE                 _UINT32_(0x00)                                       /*  (IDAU_RCTRL) Region Control  Reset Value */

#define IDAU_RCTRL_Msk                        _UINT32_(0x00000000)                                 /* (IDAU_RCTRL) Register Mask  */

/* BLOCK mode */
#define IDAU_RCTRL_BLOCK_ARG_Pos              _UINT32_(0)                                          /* (IDAU_RCTRL) Command Argument (Block ID) Position */
#define IDAU_RCTRL_BLOCK_ARG_Msk              (_UINT32_(0x1F) << IDAU_RCTRL_BLOCK_ARG_Pos)         /* (IDAU_RCTRL) Command Argument (Block ID) Mask */
#define IDAU_RCTRL_BLOCK_ARG(value)           (IDAU_RCTRL_BLOCK_ARG_Msk & (_UINT32_(value) << IDAU_RCTRL_BLOCK_ARG_Pos))
#define IDAU_RCTRL_BLOCK_CMD_Pos              _UINT32_(24)                                         /* (IDAU_RCTRL) Command Position */
#define IDAU_RCTRL_BLOCK_CMD_Msk              (_UINT32_(0xFF) << IDAU_RCTRL_BLOCK_CMD_Pos)         /* (IDAU_RCTRL) Command Mask */
#define IDAU_RCTRL_BLOCK_CMD(value)           (IDAU_RCTRL_BLOCK_CMD_Msk & (_UINT32_(value) << IDAU_RCTRL_BLOCK_CMD_Pos))
#define   IDAU_RCTRL_BLOCK_CMD_CLRNONSEC_Val  _UINT32_(0x5A)                                       /* (IDAU_RCTRL) Clear IDAU region x Non-Secure State of block ARG (RSTATUSB[x].NONSEC[ARG]=0)  */
#define   IDAU_RCTRL_BLOCK_CMD_SETNONSEC_Val  _UINT32_(0x5B)                                       /* (IDAU_RCTRL) Set IDAU region x Non-Secure State of block ARG (RSTATUSB[x].NONSEC[ARG]=1)  */
#define IDAU_RCTRL_BLOCK_CMD_CLRNONSEC        (IDAU_RCTRL_BLOCK_CMD_CLRNONSEC_Val << IDAU_RCTRL_BLOCK_CMD_Pos) /* (IDAU_RCTRL) Clear IDAU region x Non-Secure State of block ARG (RSTATUSB[x].NONSEC[ARG]=0) Position  */
#define IDAU_RCTRL_BLOCK_CMD_SETNONSEC        (IDAU_RCTRL_BLOCK_CMD_SETNONSEC_Val << IDAU_RCTRL_BLOCK_CMD_Pos) /* (IDAU_RCTRL) Set IDAU region x Non-Secure State of block ARG (RSTATUSB[x].NONSEC[ARG]=1) Position  */
#define IDAU_RCTRL_BLOCK_Msk                  _UINT32_(0xFF00001F)                                  /* (IDAU_RCTRL_BLOCK) Register Mask  */

/* WATERMARK mode */
#define IDAU_RCTRL_WATERMARK_ARG_Pos          _UINT32_(0)                                          /* (IDAU_RCTRL) Command Argument (Watermark) Position */
#define IDAU_RCTRL_WATERMARK_ARG_Msk          (_UINT32_(0xFFFFFF) << IDAU_RCTRL_WATERMARK_ARG_Pos) /* (IDAU_RCTRL) Command Argument (Watermark) Mask */
#define IDAU_RCTRL_WATERMARK_ARG(value)       (IDAU_RCTRL_WATERMARK_ARG_Msk & (_UINT32_(value) << IDAU_RCTRL_WATERMARK_ARG_Pos))
#define IDAU_RCTRL_WATERMARK_CMD_Pos          _UINT32_(24)                                         /* (IDAU_RCTRL) Command Position */
#define IDAU_RCTRL_WATERMARK_CMD_Msk          (_UINT32_(0xFF) << IDAU_RCTRL_WATERMARK_CMD_Pos)     /* (IDAU_RCTRL) Command Mask */
#define IDAU_RCTRL_WATERMARK_CMD(value)       (IDAU_RCTRL_WATERMARK_CMD_Msk & (_UINT32_(value) << IDAU_RCTRL_WATERMARK_CMD_Pos))
#define   IDAU_RCTRL_WATERMARK_CMD_WRSZ_Val   _UINT32_(0x5C)                                       /* (IDAU_RCTRL) Write IDAU region x Size (RSTATUSB[x].SIZE=ARG)  */
#define IDAU_RCTRL_WATERMARK_CMD_WRSZ         (IDAU_RCTRL_WATERMARK_CMD_WRSZ_Val << IDAU_RCTRL_WATERMARK_CMD_Pos) /* (IDAU_RCTRL) Write IDAU region x Size (RSTATUSB[x].SIZE=ARG) Position  */
#define IDAU_RCTRL_WATERMARK_Msk              _UINT32_(0xFFFFFFFF)                                  /* (IDAU_RCTRL_WATERMARK) Register Mask  */


/* -------- IDAU_RSTATUSA : (IDAU Offset: 0x04) ( R/ 32) Region Status A -------- */
#define IDAU_RSTATUSA_RESETVALUE              _UINT32_(0x00)                                       /*  (IDAU_RSTATUSA) Region Status A  Reset Value */

#define IDAU_RSTATUSA_TYPE_Pos                _UINT32_(0)                                          /* (IDAU_RSTATUSA) IDAU Region Type Position */
#define IDAU_RSTATUSA_TYPE_Msk                (_UINT32_(0xF) << IDAU_RSTATUSA_TYPE_Pos)            /* (IDAU_RSTATUSA) IDAU Region Type Mask */
#define IDAU_RSTATUSA_TYPE(value)             (IDAU_RSTATUSA_TYPE_Msk & (_UINT32_(value) << IDAU_RSTATUSA_TYPE_Pos)) /* Assigment of value for TYPE in the IDAU_RSTATUSA register */
#define   IDAU_RSTATUSA_TYPE_INVALID_Val      _UINT32_(0x0)                                        /* (IDAU_RSTATUSA) Region is invalid  */
#define   IDAU_RSTATUSA_TYPE_SEC_Val          _UINT32_(0x1)                                        /* (IDAU_RSTATUSA) Region is secure  */
#define   IDAU_RSTATUSA_TYPE_NONSEC_Val       _UINT32_(0x2)                                        /* (IDAU_RSTATUSA) Region is non secure  */
#define   IDAU_RSTATUSA_TYPE_NONSEC_W_Val     _UINT32_(0x3)                                        /* (IDAU_RSTATUSA) Region is non secure, the associated register group implements a watermark configuration  */
#define   IDAU_RSTATUSA_TYPE_SECnNONSEC_B_Val _UINT32_(0x4)                                        /* (IDAU_RSTATUSA) Region is either secure or non-secure, the associated register group implements a block configuration  */
#define   IDAU_RSTATUSA_TYPE_SECnNONSEC_L_Val _UINT32_(0x5)                                        /* (IDAU_RSTATUSA) Region is either secure or non-secure, configuration is linked to another IDAU region configuration bit (the linked configuration bit identification info is readable from the RSTATUSC register inside the same register group)  */
#define   IDAU_RSTATUSA_TYPE_NSC_W_Val        _UINT32_(0x6)                                        /* (IDAU_RSTATUSA) Region is non-secure callable, the associated register group implements a watermark configuration  */
#define   IDAU_RSTATUSA_TYPE_EXEMPT_B_Val     _UINT32_(0x7)                                        /* (IDAU_RSTATUSA) Region is exempt from security, the associated register group implements a block configuration  */
#define IDAU_RSTATUSA_TYPE_INVALID            (IDAU_RSTATUSA_TYPE_INVALID_Val << IDAU_RSTATUSA_TYPE_Pos) /* (IDAU_RSTATUSA) Region is invalid Position  */
#define IDAU_RSTATUSA_TYPE_SEC                (IDAU_RSTATUSA_TYPE_SEC_Val << IDAU_RSTATUSA_TYPE_Pos) /* (IDAU_RSTATUSA) Region is secure Position  */
#define IDAU_RSTATUSA_TYPE_NONSEC             (IDAU_RSTATUSA_TYPE_NONSEC_Val << IDAU_RSTATUSA_TYPE_Pos) /* (IDAU_RSTATUSA) Region is non secure Position  */
#define IDAU_RSTATUSA_TYPE_NONSEC_W           (IDAU_RSTATUSA_TYPE_NONSEC_W_Val << IDAU_RSTATUSA_TYPE_Pos) /* (IDAU_RSTATUSA) Region is non secure, the associated register group implements a watermark configuration Position  */
#define IDAU_RSTATUSA_TYPE_SECnNONSEC_B       (IDAU_RSTATUSA_TYPE_SECnNONSEC_B_Val << IDAU_RSTATUSA_TYPE_Pos) /* (IDAU_RSTATUSA) Region is either secure or non-secure, the associated register group implements a block configuration Position  */
#define IDAU_RSTATUSA_TYPE_SECnNONSEC_L       (IDAU_RSTATUSA_TYPE_SECnNONSEC_L_Val << IDAU_RSTATUSA_TYPE_Pos) /* (IDAU_RSTATUSA) Region is either secure or non-secure, configuration is linked to another IDAU region configuration bit (the linked configuration bit identification info is readable from the RSTATUSC register inside the same register group) Position  */
#define IDAU_RSTATUSA_TYPE_NSC_W              (IDAU_RSTATUSA_TYPE_NSC_W_Val << IDAU_RSTATUSA_TYPE_Pos) /* (IDAU_RSTATUSA) Region is non-secure callable, the associated register group implements a watermark configuration Position  */
#define IDAU_RSTATUSA_TYPE_EXEMPT_B           (IDAU_RSTATUSA_TYPE_EXEMPT_B_Val << IDAU_RSTATUSA_TYPE_Pos) /* (IDAU_RSTATUSA) Region is exempt from security, the associated register group implements a block configuration Position  */
#define IDAU_RSTATUSA_GRAN_Pos                _UINT32_(8)                                          /* (IDAU_RSTATUSA) Region Granularity Position */
#define IDAU_RSTATUSA_GRAN_Msk                (_UINT32_(0x3F) << IDAU_RSTATUSA_GRAN_Pos)           /* (IDAU_RSTATUSA) Region Granularity Mask */
#define IDAU_RSTATUSA_GRAN(value)             (IDAU_RSTATUSA_GRAN_Msk & (_UINT32_(value) << IDAU_RSTATUSA_GRAN_Pos)) /* Assigment of value for GRAN in the IDAU_RSTATUSA register */
#define   IDAU_RSTATUSA_GRAN_GRAN_NA_Val      _UINT32_(0x0)                                        /* (IDAU_RSTATUSA) Not Applicable  */
#define   IDAU_RSTATUSA_GRAN_GRAN_32B_Val     _UINT32_(0x5)                                        /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_64B_Val     _UINT32_(0x6)                                        /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_128B_Val    _UINT32_(0x7)                                        /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_256B_Val    _UINT32_(0x8)                                        /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_512B_Val    _UINT32_(0x9)                                        /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_1KB_Val     _UINT32_(0xA)                                        /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_2KB_Val     _UINT32_(0xB)                                        /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_4KB_Val     _UINT32_(0xC)                                        /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_8KB_Val     _UINT32_(0xD)                                        /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_16KB_Val    _UINT32_(0xE)                                        /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_32KB_Val    _UINT32_(0xF)                                        /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_64KB_Val    _UINT32_(0x10)                                       /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_128KB_Val   _UINT32_(0x11)                                       /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_256KB_Val   _UINT32_(0x12)                                       /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_512KB_Val   _UINT32_(0x13)                                       /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_1MB_Val     _UINT32_(0x14)                                       /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_2MB_Val     _UINT32_(0x15)                                       /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_4MB_Val     _UINT32_(0x16)                                       /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_8MB_Val     _UINT32_(0x17)                                       /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_16MB_Val    _UINT32_(0x18)                                       /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_32MB_Val    _UINT32_(0x19)                                       /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_64MB_Val    _UINT32_(0x1A)                                       /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_128MB_Val   _UINT32_(0x1B)                                       /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_256MB_Val   _UINT32_(0x1C)                                       /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_512MB_Val   _UINT32_(0x1D)                                       /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_1GB_Val     _UINT32_(0x1E)                                       /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_2GB_Val     _UINT32_(0x1F)                                       /* (IDAU_RSTATUSA)   */
#define   IDAU_RSTATUSA_GRAN_GRAN_4GB_Val     _UINT32_(0x20)                                       /* (IDAU_RSTATUSA)   */
#define IDAU_RSTATUSA_GRAN_GRAN_NA            (IDAU_RSTATUSA_GRAN_GRAN_NA_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA) Not Applicable Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_32B           (IDAU_RSTATUSA_GRAN_GRAN_32B_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_64B           (IDAU_RSTATUSA_GRAN_GRAN_64B_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_128B          (IDAU_RSTATUSA_GRAN_GRAN_128B_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_256B          (IDAU_RSTATUSA_GRAN_GRAN_256B_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_512B          (IDAU_RSTATUSA_GRAN_GRAN_512B_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_1KB           (IDAU_RSTATUSA_GRAN_GRAN_1KB_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_2KB           (IDAU_RSTATUSA_GRAN_GRAN_2KB_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_4KB           (IDAU_RSTATUSA_GRAN_GRAN_4KB_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_8KB           (IDAU_RSTATUSA_GRAN_GRAN_8KB_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_16KB          (IDAU_RSTATUSA_GRAN_GRAN_16KB_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_32KB          (IDAU_RSTATUSA_GRAN_GRAN_32KB_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_64KB          (IDAU_RSTATUSA_GRAN_GRAN_64KB_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_128KB         (IDAU_RSTATUSA_GRAN_GRAN_128KB_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_256KB         (IDAU_RSTATUSA_GRAN_GRAN_256KB_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_512KB         (IDAU_RSTATUSA_GRAN_GRAN_512KB_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_1MB           (IDAU_RSTATUSA_GRAN_GRAN_1MB_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_2MB           (IDAU_RSTATUSA_GRAN_GRAN_2MB_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_4MB           (IDAU_RSTATUSA_GRAN_GRAN_4MB_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_8MB           (IDAU_RSTATUSA_GRAN_GRAN_8MB_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_16MB          (IDAU_RSTATUSA_GRAN_GRAN_16MB_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_32MB          (IDAU_RSTATUSA_GRAN_GRAN_32MB_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_64MB          (IDAU_RSTATUSA_GRAN_GRAN_64MB_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_128MB         (IDAU_RSTATUSA_GRAN_GRAN_128MB_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_256MB         (IDAU_RSTATUSA_GRAN_GRAN_256MB_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_512MB         (IDAU_RSTATUSA_GRAN_GRAN_512MB_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_1GB           (IDAU_RSTATUSA_GRAN_GRAN_1GB_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_2GB           (IDAU_RSTATUSA_GRAN_GRAN_2GB_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_GRAN_GRAN_4GB           (IDAU_RSTATUSA_GRAN_GRAN_4GB_Val << IDAU_RSTATUSA_GRAN_Pos) /* (IDAU_RSTATUSA)  Position  */
#define IDAU_RSTATUSA_MAXSZ_Pos               _UINT32_(16)                                         /* (IDAU_RSTATUSA) Command Argument Maximum Size Position */
#define IDAU_RSTATUSA_MAXSZ_Msk               (_UINT32_(0x3F) << IDAU_RSTATUSA_MAXSZ_Pos)          /* (IDAU_RSTATUSA) Command Argument Maximum Size Mask */
#define IDAU_RSTATUSA_MAXSZ(value)            (IDAU_RSTATUSA_MAXSZ_Msk & (_UINT32_(value) << IDAU_RSTATUSA_MAXSZ_Pos)) /* Assigment of value for MAXSZ in the IDAU_RSTATUSA register */
#define IDAU_RSTATUSA_Msk                     _UINT32_(0x003F3F0F)                                 /* (IDAU_RSTATUSA) Register Mask  */


/* -------- IDAU_RSTATUSB : (IDAU Offset: 0x08) ( R/ 32) Region Status B -------- */
#define IDAU_RSTATUSB_RESETVALUE              _UINT32_(0x00)                                       /*  (IDAU_RSTATUSB) Region Status B  Reset Value */

#define IDAU_RSTATUSB_Msk                     _UINT32_(0x00000000)                                 /* (IDAU_RSTATUSB) Register Mask  */

/* BLOCK mode */
#define IDAU_RSTATUSB_BLOCK_NONSEC_Pos        _UINT32_(0)                                          /* (IDAU_RSTATUSB) Block Based Region Non-Secure State Position */
#define IDAU_RSTATUSB_BLOCK_NONSEC_Msk        (_UINT32_(0xFFFFFFFF) << IDAU_RSTATUSB_BLOCK_NONSEC_Pos) /* (IDAU_RSTATUSB) Block Based Region Non-Secure State Mask */
#define IDAU_RSTATUSB_BLOCK_NONSEC(value)     (IDAU_RSTATUSB_BLOCK_NONSEC_Msk & (_UINT32_(value) << IDAU_RSTATUSB_BLOCK_NONSEC_Pos))
#define IDAU_RSTATUSB_BLOCK_Msk               _UINT32_(0xFFFFFFFF)                                  /* (IDAU_RSTATUSB_BLOCK) Register Mask  */

/* WATERMARK mode */
#define IDAU_RSTATUSB_WATERMARK_SIZE_Pos      _UINT32_(0)                                          /* (IDAU_RSTATUSB) Watermark Based Region Size in Bytes Position */
#define IDAU_RSTATUSB_WATERMARK_SIZE_Msk      (_UINT32_(0xFFFFFFFF) << IDAU_RSTATUSB_WATERMARK_SIZE_Pos) /* (IDAU_RSTATUSB) Watermark Based Region Size in Bytes Mask */
#define IDAU_RSTATUSB_WATERMARK_SIZE(value)   (IDAU_RSTATUSB_WATERMARK_SIZE_Msk & (_UINT32_(value) << IDAU_RSTATUSB_WATERMARK_SIZE_Pos))
#define IDAU_RSTATUSB_WATERMARK_Msk           _UINT32_(0xFFFFFFFF)                                  /* (IDAU_RSTATUSB_WATERMARK) Register Mask  */


/* -------- IDAU_RSTATUSC : (IDAU Offset: 0x0C) ( R/ 32) Region Status C -------- */
#define IDAU_RSTATUSC_RESETVALUE              _UINT32_(0x00)                                       /*  (IDAU_RSTATUSC) Region Status C  Reset Value */

#define IDAU_RSTATUSC_Msk                     _UINT32_(0x00000000)                                 /* (IDAU_RSTATUSC) Register Mask  */

/* BLOCK mode */
#define IDAU_RSTATUSC_BLOCK_CST_Pos           _UINT32_(0)                                          /* (IDAU_RSTATUSC) Constant Block Configuration Position */
#define IDAU_RSTATUSC_BLOCK_CST_Msk           (_UINT32_(0xFFFFFFFF) << IDAU_RSTATUSC_BLOCK_CST_Pos) /* (IDAU_RSTATUSC) Constant Block Configuration Mask */
#define IDAU_RSTATUSC_BLOCK_CST(value)        (IDAU_RSTATUSC_BLOCK_CST_Msk & (_UINT32_(value) << IDAU_RSTATUSC_BLOCK_CST_Pos))
#define IDAU_RSTATUSC_BLOCK_Msk               _UINT32_(0xFFFFFFFF)                                  /* (IDAU_RSTATUSC_BLOCK) Register Mask  */

/* LINK mode */
#define IDAU_RSTATUSC_LINK_RGN_Pos            _UINT32_(0)                                          /* (IDAU_RSTATUSC) Linked IDAU Region ID Position */
#define IDAU_RSTATUSC_LINK_RGN_Msk            (_UINT32_(0xFF) << IDAU_RSTATUSC_LINK_RGN_Pos)       /* (IDAU_RSTATUSC) Linked IDAU Region ID Mask */
#define IDAU_RSTATUSC_LINK_RGN(value)         (IDAU_RSTATUSC_LINK_RGN_Msk & (_UINT32_(value) << IDAU_RSTATUSC_LINK_RGN_Pos))
#define IDAU_RSTATUSC_LINK_BLK_Pos            _UINT32_(8)                                          /* (IDAU_RSTATUSC) Linked IDAU Region Block ID Position */
#define IDAU_RSTATUSC_LINK_BLK_Msk            (_UINT32_(0x1F) << IDAU_RSTATUSC_LINK_BLK_Pos)       /* (IDAU_RSTATUSC) Linked IDAU Region Block ID Mask */
#define IDAU_RSTATUSC_LINK_BLK(value)         (IDAU_RSTATUSC_LINK_BLK_Msk & (_UINT32_(value) << IDAU_RSTATUSC_LINK_BLK_Pos))
#define IDAU_RSTATUSC_LINK_Msk                _UINT32_(0x00001FFF)                                  /* (IDAU_RSTATUSC_LINK) Register Mask  */


/* -------- IDAU_CTRL : (IDAU Offset: 0x00) ( /W 32) Control -------- */
#define IDAU_CTRL_RESETVALUE                  _UINT32_(0x00)                                       /*  (IDAU_CTRL) Control  Reset Value */

#define IDAU_CTRL_CMD_Pos                     _UINT32_(16)                                         /* (IDAU_CTRL) Command Register Position */
#define IDAU_CTRL_CMD_Msk                     (_UINT32_(0xFFFF) << IDAU_CTRL_CMD_Pos)              /* (IDAU_CTRL) Command Register Mask */
#define IDAU_CTRL_CMD(value)                  (IDAU_CTRL_CMD_Msk & (_UINT32_(value) << IDAU_CTRL_CMD_Pos)) /* Assigment of value for CMD in the IDAU_CTRL register */
#define   IDAU_CTRL_CMD_ENABLE_Val            _UINT32_(0xA501)                                     /* (IDAU_CTRL) Module Enable  */
#define   IDAU_CTRL_CMD_DISABLE_Val           _UINT32_(0xA502)                                     /* (IDAU_CTRL) Module Disable  */
#define   IDAU_CTRL_CMD_WLCK_Val              _UINT32_(0xA503)                                     /* (IDAU_CTRL) Write Lock  */
#define IDAU_CTRL_CMD_ENABLE                  (IDAU_CTRL_CMD_ENABLE_Val << IDAU_CTRL_CMD_Pos)      /* (IDAU_CTRL) Module Enable Position  */
#define IDAU_CTRL_CMD_DISABLE                 (IDAU_CTRL_CMD_DISABLE_Val << IDAU_CTRL_CMD_Pos)     /* (IDAU_CTRL) Module Disable Position  */
#define IDAU_CTRL_CMD_WLCK                    (IDAU_CTRL_CMD_WLCK_Val << IDAU_CTRL_CMD_Pos)        /* (IDAU_CTRL) Write Lock Position  */
#define IDAU_CTRL_Msk                         _UINT32_(0xFFFF0000)                                 /* (IDAU_CTRL) Register Mask  */


/* -------- IDAU_STATUSA : (IDAU Offset: 0x04) ( R/ 32) Status A -------- */
#define IDAU_STATUSA_ENABLE_Pos               _UINT32_(0)                                          /* (IDAU_STATUSA) Enable Position */
#define IDAU_STATUSA_ENABLE_Msk               (_UINT32_(0x1) << IDAU_STATUSA_ENABLE_Pos)           /* (IDAU_STATUSA) Enable Mask */
#define IDAU_STATUSA_ENABLE(value)            (IDAU_STATUSA_ENABLE_Msk & (_UINT32_(value) << IDAU_STATUSA_ENABLE_Pos)) /* Assigment of value for ENABLE in the IDAU_STATUSA register */
#define IDAU_STATUSA_WLCK_Pos                 _UINT32_(1)                                          /* (IDAU_STATUSA) Write Lock Position */
#define IDAU_STATUSA_WLCK_Msk                 (_UINT32_(0x1) << IDAU_STATUSA_WLCK_Pos)             /* (IDAU_STATUSA) Write Lock Mask */
#define IDAU_STATUSA_WLCK(value)              (IDAU_STATUSA_WLCK_Msk & (_UINT32_(value) << IDAU_STATUSA_WLCK_Pos)) /* Assigment of value for WLCK in the IDAU_STATUSA register */
#define IDAU_STATUSA_NBRG_Pos                 _UINT32_(8)                                          /* (IDAU_STATUSA) Number Of IDAU Regions Position */
#define IDAU_STATUSA_NBRG_Msk                 (_UINT32_(0x1FF) << IDAU_STATUSA_NBRG_Pos)           /* (IDAU_STATUSA) Number Of IDAU Regions Mask */
#define IDAU_STATUSA_NBRG(value)              (IDAU_STATUSA_NBRG_Msk & (_UINT32_(value) << IDAU_STATUSA_NBRG_Pos)) /* Assigment of value for NBRG in the IDAU_STATUSA register */
#define IDAU_STATUSA_Msk                      _UINT32_(0x0001FF03)                                 /* (IDAU_STATUSA) Register Mask  */


/* -------- IDAU_STATUSB : (IDAU Offset: 0x08) (R/W 32) Status B -------- */
#define IDAU_STATUSB_RESETVALUE               _UINT32_(0x00)                                       /*  (IDAU_STATUSB) Status B  Reset Value */

#define IDAU_STATUSB_CFGERR_Pos               _UINT32_(0)                                          /* (IDAU_STATUSB) Configuration Error Position */
#define IDAU_STATUSB_CFGERR_Msk               (_UINT32_(0x1) << IDAU_STATUSB_CFGERR_Pos)           /* (IDAU_STATUSB) Configuration Error Mask */
#define IDAU_STATUSB_CFGERR(value)            (IDAU_STATUSB_CFGERR_Msk & (_UINT32_(value) << IDAU_STATUSB_CFGERR_Pos)) /* Assigment of value for CFGERR in the IDAU_STATUSB register */
#define IDAU_STATUSB_Msk                      _UINT32_(0x00000001)                                 /* (IDAU_STATUSB) Register Mask  */


/** \brief IDAU register offsets definitions */
#define IDAU_RCTRL_REG_OFST            _UINT32_(0x00)      /* (IDAU_RCTRL) Region Control Offset */
#define IDAU_RSTATUSA_REG_OFST         _UINT32_(0x04)      /* (IDAU_RSTATUSA) Region Status A Offset */
#define IDAU_RSTATUSB_REG_OFST         _UINT32_(0x08)      /* (IDAU_RSTATUSB) Region Status B Offset */
#define IDAU_RSTATUSC_REG_OFST         _UINT32_(0x0C)      /* (IDAU_RSTATUSC) Region Status C Offset */
#define IDAU_CTRL_REG_OFST             _UINT32_(0x00)      /* (IDAU_CTRL) Control Offset */
#define IDAU_STATUSA_REG_OFST          _UINT32_(0x04)      /* (IDAU_STATUSA) Status A Offset */
#define IDAU_STATUSB_REG_OFST          _UINT32_(0x08)      /* (IDAU_STATUSB) Status B Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief REGIONS register API structure */
typedef struct
{
  __O   uint32_t                       IDAU_RCTRL;         /**< Offset: 0x00 ( /W  32) Region Control */
  __I   uint32_t                       IDAU_RSTATUSA;      /**< Offset: 0x04 (R/   32) Region Status A */
  __I   uint32_t                       IDAU_RSTATUSB;      /**< Offset: 0x08 (R/   32) Region Status B */
  __I   uint32_t                       IDAU_RSTATUSC;      /**< Offset: 0x0C (R/   32) Region Status C */
} idau_regions_registers_t;

#define IDAU_REGIONS_NUMBER 24

/** \brief IDAU register API structure */
typedef struct
{  /* Implementation Defined Attribution Unit */
  __O   uint32_t                       IDAU_CTRL;          /**< Offset: 0x00 ( /W  32) Control */
  __I   uint32_t                       IDAU_STATUSA;       /**< Offset: 0x04 (R/   32) Status A */
  __IO  uint32_t                       IDAU_STATUSB;       /**< Offset: 0x08 (R/W  32) Status B */
  __I   uint8_t                        Reserved1[0xFF4];
        idau_regions_registers_t       REGIONS[IDAU_REGIONS_NUMBER]; /**< Offset: 0x1000  */
} idau_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CKGC01_IDAU_COMPONENT_H_ */
