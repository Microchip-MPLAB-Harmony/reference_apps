/*
 * Component description for DMA
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
#ifndef _PIC32CZCA90_DMA_COMPONENT_H_
#define _PIC32CZCA90_DMA_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR DMA                                          */
/* ************************************************************************** */

/* -------- DMA_BDNXT : (DMA Offset: 0x00) (R/W 32) NEXT BUFFER DESCRIPTOR ADDRESS POINTER -------- */
#define DMA_BDNXT_RESETVALUE                  _UINT32_(0x00)                                       /*  (DMA_BDNXT) NEXT BUFFER DESCRIPTOR ADDRESS POINTER  Reset Value */

#define DMA_BDNXT_NXT_Pos                     _UINT32_(0)                                          /* (DMA_BDNXT) Next Descriptor Pointer Position */
#define DMA_BDNXT_NXT_Msk                     (_UINT32_(0xFFFFFFFF) << DMA_BDNXT_NXT_Pos)          /* (DMA_BDNXT) Next Descriptor Pointer Mask */
#define DMA_BDNXT_NXT(value)                  (DMA_BDNXT_NXT_Msk & (_UINT32_(value) << DMA_BDNXT_NXT_Pos)) /* Assigment of value for NXT in the DMA_BDNXT register */
#define DMA_BDNXT_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (DMA_BDNXT) Register Mask  */


/* -------- DMA_BDCFG : (DMA Offset: 0x04) (R/W 32) CURRENT BUFFER DESCRIPTOR CONFIGURATION -------- */
#define DMA_BDCFG_RESETVALUE                  _UINT32_(0x00)                                       /*  (DMA_BDCFG) CURRENT BUFFER DESCRIPTOR CONFIGURATION  Reset Value */

#define DMA_BDCFG_CTRLB_Pos                   _UINT32_(0)                                          /* (DMA_BDCFG) CTRLB Register Descriptor Load Position */
#define DMA_BDCFG_CTRLB_Msk                   (_UINT32_(0x1) << DMA_BDCFG_CTRLB_Pos)               /* (DMA_BDCFG) CTRLB Register Descriptor Load Mask */
#define DMA_BDCFG_CTRLB(value)                (DMA_BDCFG_CTRLB_Msk & (_UINT32_(value) << DMA_BDCFG_CTRLB_Pos)) /* Assigment of value for CTRLB in the DMA_BDCFG register */
#define DMA_BDCFG_EVCTRL_Pos                  _UINT32_(1)                                          /* (DMA_BDCFG) EVCTRL Register Descriptor Load Position */
#define DMA_BDCFG_EVCTRL_Msk                  (_UINT32_(0x1) << DMA_BDCFG_EVCTRL_Pos)              /* (DMA_BDCFG) EVCTRL Register Descriptor Load Mask */
#define DMA_BDCFG_EVCTRL(value)               (DMA_BDCFG_EVCTRL_Msk & (_UINT32_(value) << DMA_BDCFG_EVCTRL_Pos)) /* Assigment of value for EVCTRL in the DMA_BDCFG register */
#define DMA_BDCFG_SSA_Pos                     _UINT32_(2)                                          /* (DMA_BDCFG) SSA Register Descriptor Load Position */
#define DMA_BDCFG_SSA_Msk                     (_UINT32_(0x1) << DMA_BDCFG_SSA_Pos)                 /* (DMA_BDCFG) SSA Register Descriptor Load Mask */
#define DMA_BDCFG_SSA(value)                  (DMA_BDCFG_SSA_Msk & (_UINT32_(value) << DMA_BDCFG_SSA_Pos)) /* Assigment of value for SSA in the DMA_BDCFG register */
#define DMA_BDCFG_DSA_Pos                     _UINT32_(3)                                          /* (DMA_BDCFG) DSA Register Descriptor Load Position */
#define DMA_BDCFG_DSA_Msk                     (_UINT32_(0x1) << DMA_BDCFG_DSA_Pos)                 /* (DMA_BDCFG) DSA Register Descriptor Load Mask */
#define DMA_BDCFG_DSA(value)                  (DMA_BDCFG_DSA_Msk & (_UINT32_(value) << DMA_BDCFG_DSA_Pos)) /* Assigment of value for DSA in the DMA_BDCFG register */
#define DMA_BDCFG_SSTRD_Pos                   _UINT32_(4)                                          /* (DMA_BDCFG) SSTRD Register Descriptor Load Position */
#define DMA_BDCFG_SSTRD_Msk                   (_UINT32_(0x1) << DMA_BDCFG_SSTRD_Pos)               /* (DMA_BDCFG) SSTRD Register Descriptor Load Mask */
#define DMA_BDCFG_SSTRD(value)                (DMA_BDCFG_SSTRD_Msk & (_UINT32_(value) << DMA_BDCFG_SSTRD_Pos)) /* Assigment of value for SSTRD in the DMA_BDCFG register */
#define DMA_BDCFG_DSTRD_Pos                   _UINT32_(5)                                          /* (DMA_BDCFG) DSTRD Register Descriptor Load Position */
#define DMA_BDCFG_DSTRD_Msk                   (_UINT32_(0x1) << DMA_BDCFG_DSTRD_Pos)               /* (DMA_BDCFG) DSTRD Register Descriptor Load Mask */
#define DMA_BDCFG_DSTRD(value)                (DMA_BDCFG_DSTRD_Msk & (_UINT32_(value) << DMA_BDCFG_DSTRD_Pos)) /* Assigment of value for DSTRD in the DMA_BDCFG register */
#define DMA_BDCFG_XSIZ_Pos                    _UINT32_(6)                                          /* (DMA_BDCFG) XSIZ Register Descriptor Load Position */
#define DMA_BDCFG_XSIZ_Msk                    (_UINT32_(0x1) << DMA_BDCFG_XSIZ_Pos)                /* (DMA_BDCFG) XSIZ Register Descriptor Load Mask */
#define DMA_BDCFG_XSIZ(value)                 (DMA_BDCFG_XSIZ_Msk & (_UINT32_(value) << DMA_BDCFG_XSIZ_Pos)) /* Assigment of value for XSIZ in the DMA_BDCFG register */
#define DMA_BDCFG_PDAT_Pos                    _UINT32_(7)                                          /* (DMA_BDCFG) PDAT Register Descriptor Load Position */
#define DMA_BDCFG_PDAT_Msk                    (_UINT32_(0x1) << DMA_BDCFG_PDAT_Pos)                /* (DMA_BDCFG) PDAT Register Descriptor Load Mask */
#define DMA_BDCFG_PDAT(value)                 (DMA_BDCFG_PDAT_Msk & (_UINT32_(value) << DMA_BDCFG_PDAT_Pos)) /* Assigment of value for PDAT in the DMA_BDCFG register */
#define DMA_BDCFG_CTRLCRC_Pos                 _UINT32_(8)                                          /* (DMA_BDCFG) CTRLCRC Register Descriptor Load Position */
#define DMA_BDCFG_CTRLCRC_Msk                 (_UINT32_(0x1) << DMA_BDCFG_CTRLCRC_Pos)             /* (DMA_BDCFG) CTRLCRC Register Descriptor Load Mask */
#define DMA_BDCFG_CTRLCRC(value)              (DMA_BDCFG_CTRLCRC_Msk & (_UINT32_(value) << DMA_BDCFG_CTRLCRC_Pos)) /* Assigment of value for CTRLCRC in the DMA_BDCFG register */
#define DMA_BDCFG_CRCDAT_Pos                  _UINT32_(9)                                          /* (DMA_BDCFG) CRCDAT Register Descriptor Load Position */
#define DMA_BDCFG_CRCDAT_Msk                  (_UINT32_(0x1) << DMA_BDCFG_CRCDAT_Pos)              /* (DMA_BDCFG) CRCDAT Register Descriptor Load Mask */
#define DMA_BDCFG_CRCDAT(value)               (DMA_BDCFG_CRCDAT_Msk & (_UINT32_(value) << DMA_BDCFG_CRCDAT_Pos)) /* Assigment of value for CRCDAT in the DMA_BDCFG register */
#define DMA_BDCFG_ENABLE_Pos                  _UINT32_(24)                                         /* (DMA_BDCFG) Channel Enable Position */
#define DMA_BDCFG_ENABLE_Msk                  (_UINT32_(0x1) << DMA_BDCFG_ENABLE_Pos)              /* (DMA_BDCFG) Channel Enable Mask */
#define DMA_BDCFG_ENABLE(value)               (DMA_BDCFG_ENABLE_Msk & (_UINT32_(value) << DMA_BDCFG_ENABLE_Pos)) /* Assigment of value for ENABLE in the DMA_BDCFG register */
#define DMA_BDCFG_LLEN_Pos                    _UINT32_(25)                                         /* (DMA_BDCFG) Linked List Enable Position */
#define DMA_BDCFG_LLEN_Msk                    (_UINT32_(0x1) << DMA_BDCFG_LLEN_Pos)                /* (DMA_BDCFG) Linked List Enable Mask */
#define DMA_BDCFG_LLEN(value)                 (DMA_BDCFG_LLEN_Msk & (_UINT32_(value) << DMA_BDCFG_LLEN_Pos)) /* Assigment of value for LLEN in the DMA_BDCFG register */
#define DMA_BDCFG_SWFRC_Pos                   _UINT32_(26)                                         /* (DMA_BDCFG) Software Forced Trigger Position */
#define DMA_BDCFG_SWFRC_Msk                   (_UINT32_(0x1) << DMA_BDCFG_SWFRC_Pos)               /* (DMA_BDCFG) Software Forced Trigger Mask */
#define DMA_BDCFG_SWFRC(value)                (DMA_BDCFG_SWFRC_Msk & (_UINT32_(value) << DMA_BDCFG_SWFRC_Pos)) /* Assigment of value for SWFRC in the DMA_BDCFG register */
#define DMA_BDCFG_RUNSTDBY_Pos                _UINT32_(27)                                         /* (DMA_BDCFG) Run In Standby Position */
#define DMA_BDCFG_RUNSTDBY_Msk                (_UINT32_(0x1) << DMA_BDCFG_RUNSTDBY_Pos)            /* (DMA_BDCFG) Run In Standby Mask */
#define DMA_BDCFG_RUNSTDBY(value)             (DMA_BDCFG_RUNSTDBY_Msk & (_UINT32_(value) << DMA_BDCFG_RUNSTDBY_Pos)) /* Assigment of value for RUNSTDBY in the DMA_BDCFG register */
#define DMA_BDCFG_Msk                         _UINT32_(0x0F0003FF)                                 /* (DMA_BDCFG) Register Mask  */


/* -------- DMA_BDCTRLB : (DMA Offset: 0x08) (R/W 32) CURRENT BUFFER DESCRIPTOR CONTROL REGISTER B -------- */
#define DMA_BDCTRLB_RESETVALUE                _UINT32_(0x00)                                       /*  (DMA_BDCTRLB) CURRENT BUFFER DESCRIPTOR CONTROL REGISTER B  Reset Value */

#define DMA_BDCTRLB_WAS_Pos                   _UINT32_(0)                                          /* (DMA_BDCTRLB) Channel Write Address Sequence. Position */
#define DMA_BDCTRLB_WAS_Msk                   (_UINT32_(0x7) << DMA_BDCTRLB_WAS_Pos)               /* (DMA_BDCTRLB) Channel Write Address Sequence. Mask */
#define DMA_BDCTRLB_WAS(value)                (DMA_BDCTRLB_WAS_Msk & (_UINT32_(value) << DMA_BDCTRLB_WAS_Pos)) /* Assigment of value for WAS in the DMA_BDCTRLB register */
#define   DMA_BDCTRLB_WAS_BYTE_ADDR_INCR_Val  _UINT32_(0x0)                                        /* (DMA_BDCTRLB) Incrementing Address+1 with Transfers of Byte Operands  */
#define   DMA_BDCTRLB_WAS_HALF_WORD_ADDR_INCR_Val _UINT32_(0x1)                                        /* (DMA_BDCTRLB) Incrementing Address+2 with Transfers of HalfWord Operands  */
#define   DMA_BDCTRLB_WAS_AUTO_ADDR_INCR_Val  _UINT32_(0x2)                                        /* (DMA_BDCTRLB) Auto Increment Address and Transfer Size  */
#define   DMA_BDCTRLB_WAS_FIXED_BYTE_ADDR_INCR_Val _UINT32_(0x3)                                        /* (DMA_BDCTRLB) Fixed Byte Address (Single Byte Address with Enable Based upon 2 LSBs)  */
#define   DMA_BDCTRLB_WAS_FIXED_HALF_WORD_ADDR_INCR_Val _UINT32_(0x4)                                        /* (DMA_BDCTRLB) Fixed Address of HalfWord Operand (Single HalfWord Aligned Address)  */
#define   DMA_BDCTRLB_WAS_FIXED_WORD_ADDR_INCR_Val _UINT32_(0x5)                                        /* (DMA_BDCTRLB) Fixed Address Word Burst Transfer  */
#define DMA_BDCTRLB_WAS_BYTE_ADDR_INCR        (DMA_BDCTRLB_WAS_BYTE_ADDR_INCR_Val << DMA_BDCTRLB_WAS_Pos) /* (DMA_BDCTRLB) Incrementing Address+1 with Transfers of Byte Operands Position  */
#define DMA_BDCTRLB_WAS_HALF_WORD_ADDR_INCR   (DMA_BDCTRLB_WAS_HALF_WORD_ADDR_INCR_Val << DMA_BDCTRLB_WAS_Pos) /* (DMA_BDCTRLB) Incrementing Address+2 with Transfers of HalfWord Operands Position  */
#define DMA_BDCTRLB_WAS_AUTO_ADDR_INCR        (DMA_BDCTRLB_WAS_AUTO_ADDR_INCR_Val << DMA_BDCTRLB_WAS_Pos) /* (DMA_BDCTRLB) Auto Increment Address and Transfer Size Position  */
#define DMA_BDCTRLB_WAS_FIXED_BYTE_ADDR_INCR  (DMA_BDCTRLB_WAS_FIXED_BYTE_ADDR_INCR_Val << DMA_BDCTRLB_WAS_Pos) /* (DMA_BDCTRLB) Fixed Byte Address (Single Byte Address with Enable Based upon 2 LSBs) Position  */
#define DMA_BDCTRLB_WAS_FIXED_HALF_WORD_ADDR_INCR (DMA_BDCTRLB_WAS_FIXED_HALF_WORD_ADDR_INCR_Val << DMA_BDCTRLB_WAS_Pos) /* (DMA_BDCTRLB) Fixed Address of HalfWord Operand (Single HalfWord Aligned Address) Position  */
#define DMA_BDCTRLB_WAS_FIXED_WORD_ADDR_INCR  (DMA_BDCTRLB_WAS_FIXED_WORD_ADDR_INCR_Val << DMA_BDCTRLB_WAS_Pos) /* (DMA_BDCTRLB) Fixed Address Word Burst Transfer Position  */
#define DMA_BDCTRLB_RAS_Pos                   _UINT32_(4)                                          /* (DMA_BDCTRLB) Channel Read Address Sequence Position */
#define DMA_BDCTRLB_RAS_Msk                   (_UINT32_(0x7) << DMA_BDCTRLB_RAS_Pos)               /* (DMA_BDCTRLB) Channel Read Address Sequence Mask */
#define DMA_BDCTRLB_RAS(value)                (DMA_BDCTRLB_RAS_Msk & (_UINT32_(value) << DMA_BDCTRLB_RAS_Pos)) /* Assigment of value for RAS in the DMA_BDCTRLB register */
#define   DMA_BDCTRLB_RAS_BYTE_ADDR_INCR_Val  _UINT32_(0x0)                                        /* (DMA_BDCTRLB) Incrementing Address+1 with Transfers of Byte Operands  */
#define   DMA_BDCTRLB_RAS_HALF_WORD_ADDR_INCR_Val _UINT32_(0x1)                                        /* (DMA_BDCTRLB) Incrementing Address+2 with Transfers of HalfWord Operands  */
#define   DMA_BDCTRLB_RAS_AUTO_ADDR_INCR_Val  _UINT32_(0x2)                                        /* (DMA_BDCTRLB) Auto Increment Address and Transfer Size  */
#define   DMA_BDCTRLB_RAS_FIXED_BYTE_ADDR_INCR_Val _UINT32_(0x3)                                        /* (DMA_BDCTRLB) Fixed Byte Address (Single Byte Address with Enable Based upon 2 LSBs)  */
#define   DMA_BDCTRLB_RAS_FIXED_HALF_WORD_ADDR_INCR_Val _UINT32_(0x4)                                        /* (DMA_BDCTRLB) Fixed Address of HalfWord Operand (Single HalfWord Aligned Address)  */
#define   DMA_BDCTRLB_RAS_FIXED_WORD_ADDR_INCR_Val _UINT32_(0x5)                                        /* (DMA_BDCTRLB) Fixed Address Word Burst Transfer  */
#define DMA_BDCTRLB_RAS_BYTE_ADDR_INCR        (DMA_BDCTRLB_RAS_BYTE_ADDR_INCR_Val << DMA_BDCTRLB_RAS_Pos) /* (DMA_BDCTRLB) Incrementing Address+1 with Transfers of Byte Operands Position  */
#define DMA_BDCTRLB_RAS_HALF_WORD_ADDR_INCR   (DMA_BDCTRLB_RAS_HALF_WORD_ADDR_INCR_Val << DMA_BDCTRLB_RAS_Pos) /* (DMA_BDCTRLB) Incrementing Address+2 with Transfers of HalfWord Operands Position  */
#define DMA_BDCTRLB_RAS_AUTO_ADDR_INCR        (DMA_BDCTRLB_RAS_AUTO_ADDR_INCR_Val << DMA_BDCTRLB_RAS_Pos) /* (DMA_BDCTRLB) Auto Increment Address and Transfer Size Position  */
#define DMA_BDCTRLB_RAS_FIXED_BYTE_ADDR_INCR  (DMA_BDCTRLB_RAS_FIXED_BYTE_ADDR_INCR_Val << DMA_BDCTRLB_RAS_Pos) /* (DMA_BDCTRLB) Fixed Byte Address (Single Byte Address with Enable Based upon 2 LSBs) Position  */
#define DMA_BDCTRLB_RAS_FIXED_HALF_WORD_ADDR_INCR (DMA_BDCTRLB_RAS_FIXED_HALF_WORD_ADDR_INCR_Val << DMA_BDCTRLB_RAS_Pos) /* (DMA_BDCTRLB) Fixed Address of HalfWord Operand (Single HalfWord Aligned Address) Position  */
#define DMA_BDCTRLB_RAS_FIXED_WORD_ADDR_INCR  (DMA_BDCTRLB_RAS_FIXED_WORD_ADDR_INCR_Val << DMA_BDCTRLB_RAS_Pos) /* (DMA_BDCTRLB) Fixed Address Word Burst Transfer Position  */
#define DMA_BDCTRLB_PRI_Pos                   _UINT32_(8)                                          /* (DMA_BDCTRLB) Channel Priority level. Position */
#define DMA_BDCTRLB_PRI_Msk                   (_UINT32_(0x3) << DMA_BDCTRLB_PRI_Pos)               /* (DMA_BDCTRLB) Channel Priority level. Mask */
#define DMA_BDCTRLB_PRI(value)                (DMA_BDCTRLB_PRI_Msk & (_UINT32_(value) << DMA_BDCTRLB_PRI_Pos)) /* Assigment of value for PRI in the DMA_BDCTRLB register */
#define   DMA_BDCTRLB_PRI_PRI_1_Val           _UINT32_(0x0)                                        /* (DMA_BDCTRLB) Channel Priority is 1  */
#define   DMA_BDCTRLB_PRI_PRI_2_Val           _UINT32_(0x1)                                        /* (DMA_BDCTRLB) Channel Priority is 2  */
#define   DMA_BDCTRLB_PRI_PRI_3_Val           _UINT32_(0x2)                                        /* (DMA_BDCTRLB) Channel Priority is 3  */
#define   DMA_BDCTRLB_PRI_PRI_4_Val           _UINT32_(0x3)                                        /* (DMA_BDCTRLB) Channel Priority is 4 (HIGHEST)  */
#define DMA_BDCTRLB_PRI_PRI_1                 (DMA_BDCTRLB_PRI_PRI_1_Val << DMA_BDCTRLB_PRI_Pos)   /* (DMA_BDCTRLB) Channel Priority is 1 Position  */
#define DMA_BDCTRLB_PRI_PRI_2                 (DMA_BDCTRLB_PRI_PRI_2_Val << DMA_BDCTRLB_PRI_Pos)   /* (DMA_BDCTRLB) Channel Priority is 2 Position  */
#define DMA_BDCTRLB_PRI_PRI_3                 (DMA_BDCTRLB_PRI_PRI_3_Val << DMA_BDCTRLB_PRI_Pos)   /* (DMA_BDCTRLB) Channel Priority is 3 Position  */
#define DMA_BDCTRLB_PRI_PRI_4                 (DMA_BDCTRLB_PRI_PRI_4_Val << DMA_BDCTRLB_PRI_Pos)   /* (DMA_BDCTRLB) Channel Priority is 4 (HIGHEST) Position  */
#define DMA_BDCTRLB_WBOEN_Pos                 _UINT32_(13)                                         /* (DMA_BDCTRLB) Write Byte Order Enable Position */
#define DMA_BDCTRLB_WBOEN_Msk                 (_UINT32_(0x1) << DMA_BDCTRLB_WBOEN_Pos)             /* (DMA_BDCTRLB) Write Byte Order Enable Mask */
#define DMA_BDCTRLB_WBOEN(value)              (DMA_BDCTRLB_WBOEN_Msk & (_UINT32_(value) << DMA_BDCTRLB_WBOEN_Pos)) /* Assigment of value for WBOEN in the DMA_BDCTRLB register */
#define DMA_BDCTRLB_BYTORD_Pos                _UINT32_(14)                                         /* (DMA_BDCTRLB) Byte Order Position */
#define DMA_BDCTRLB_BYTORD_Msk                (_UINT32_(0x3) << DMA_BDCTRLB_BYTORD_Pos)            /* (DMA_BDCTRLB) Byte Order Mask */
#define DMA_BDCTRLB_BYTORD(value)             (DMA_BDCTRLB_BYTORD_Msk & (_UINT32_(value) << DMA_BDCTRLB_BYTORD_Pos)) /* Assigment of value for BYTORD in the DMA_BDCTRLB register */
#define   DMA_BDCTRLB_BYTORD_BYTORD_NONE_Val  _UINT32_(0x0)                                        /* (DMA_BDCTRLB) Bytes are processed AS IS  */
#define   DMA_BDCTRLB_BYTORD_BYTORD_WORD_SWIZZLE_Val _UINT32_(0x1)                                        /* (DMA_BDCTRLB) Bytes are swapped as: BYTE3 to BYTE0, BYTE2 to BYTE1, BYTE1 to BYTE2, and BYTE0 to BYTE3  */
#define   DMA_BDCTRLB_BYTORD_BYTORD_HALF_WORD_SWIZZLE_Val _UINT32_(0x2)                                        /* (DMA_BDCTRLB) Bytes are swapped as: BYTE3 to BYTE1, BYTE2 to BYTE0, BYTE1 to BYTE3, and BYTE0 to BYTE2  */
#define   DMA_BDCTRLB_BYTORD_BYTORD_BYTE_SWIZZLE_Val _UINT32_(0x3)                                        /* (DMA_BDCTRLB) Bytes are swapped as: BYTE3 to BYTE2, BYTE2 to BYTE3, BYTE1 to BYTE1, and BYTE0 to BYTE1  */
#define DMA_BDCTRLB_BYTORD_BYTORD_NONE        (DMA_BDCTRLB_BYTORD_BYTORD_NONE_Val << DMA_BDCTRLB_BYTORD_Pos) /* (DMA_BDCTRLB) Bytes are processed AS IS Position  */
#define DMA_BDCTRLB_BYTORD_BYTORD_WORD_SWIZZLE (DMA_BDCTRLB_BYTORD_BYTORD_WORD_SWIZZLE_Val << DMA_BDCTRLB_BYTORD_Pos) /* (DMA_BDCTRLB) Bytes are swapped as: BYTE3 to BYTE0, BYTE2 to BYTE1, BYTE1 to BYTE2, and BYTE0 to BYTE3 Position  */
#define DMA_BDCTRLB_BYTORD_BYTORD_HALF_WORD_SWIZZLE (DMA_BDCTRLB_BYTORD_BYTORD_HALF_WORD_SWIZZLE_Val << DMA_BDCTRLB_BYTORD_Pos) /* (DMA_BDCTRLB) Bytes are swapped as: BYTE3 to BYTE1, BYTE2 to BYTE0, BYTE1 to BYTE3, and BYTE0 to BYTE2 Position  */
#define DMA_BDCTRLB_BYTORD_BYTORD_BYTE_SWIZZLE (DMA_BDCTRLB_BYTORD_BYTORD_BYTE_SWIZZLE_Val << DMA_BDCTRLB_BYTORD_Pos) /* (DMA_BDCTRLB) Bytes are swapped as: BYTE3 to BYTE2, BYTE2 to BYTE3, BYTE1 to BYTE1, and BYTE0 to BYTE1 Position  */
#define DMA_BDCTRLB_TRIG_Pos                  _UINT32_(16)                                         /* (DMA_BDCTRLB) Trigger that can Start a Channel Transfer Position */
#define DMA_BDCTRLB_TRIG_Msk                  (_UINT32_(0xFF) << DMA_BDCTRLB_TRIG_Pos)             /* (DMA_BDCTRLB) Trigger that can Start a Channel Transfer Mask */
#define DMA_BDCTRLB_TRIG(value)               (DMA_BDCTRLB_TRIG_Msk & (_UINT32_(value) << DMA_BDCTRLB_TRIG_Pos)) /* Assigment of value for TRIG in the DMA_BDCTRLB register */
#define DMA_BDCTRLB_PIGNEN_Pos                _UINT32_(24)                                         /* (DMA_BDCTRLB) Enable Pattern Ignore Byte Position */
#define DMA_BDCTRLB_PIGNEN_Msk                (_UINT32_(0x1) << DMA_BDCTRLB_PIGNEN_Pos)            /* (DMA_BDCTRLB) Enable Pattern Ignore Byte Mask */
#define DMA_BDCTRLB_PIGNEN(value)             (DMA_BDCTRLB_PIGNEN_Msk & (_UINT32_(value) << DMA_BDCTRLB_PIGNEN_Pos)) /* Assigment of value for PIGNEN in the DMA_BDCTRLB register */
#define DMA_BDCTRLB_PATLEN_Pos                _UINT32_(25)                                         /* (DMA_BDCTRLB) Pattern Match Length Position */
#define DMA_BDCTRLB_PATLEN_Msk                (_UINT32_(0x1) << DMA_BDCTRLB_PATLEN_Pos)            /* (DMA_BDCTRLB) Pattern Match Length Mask */
#define DMA_BDCTRLB_PATLEN(value)             (DMA_BDCTRLB_PATLEN_Msk & (_UINT32_(value) << DMA_BDCTRLB_PATLEN_Pos)) /* Assigment of value for PATLEN in the DMA_BDCTRLB register */
#define DMA_BDCTRLB_PATEN_Pos                 _UINT32_(26)                                         /* (DMA_BDCTRLB) Channel Pattern Match Abort Enable. Position */
#define DMA_BDCTRLB_PATEN_Msk                 (_UINT32_(0x1) << DMA_BDCTRLB_PATEN_Pos)             /* (DMA_BDCTRLB) Channel Pattern Match Abort Enable. Mask */
#define DMA_BDCTRLB_PATEN(value)              (DMA_BDCTRLB_PATEN_Msk & (_UINT32_(value) << DMA_BDCTRLB_PATEN_Pos)) /* Assigment of value for PATEN in the DMA_BDCTRLB register */
#define DMA_BDCTRLB_CASTEN_Pos                _UINT32_(29)                                         /* (DMA_BDCTRLB) Cell Auto Start Enable of Ensuing Transfers for this channel Position */
#define DMA_BDCTRLB_CASTEN_Msk                (_UINT32_(0x1) << DMA_BDCTRLB_CASTEN_Pos)            /* (DMA_BDCTRLB) Cell Auto Start Enable of Ensuing Transfers for this channel Mask */
#define DMA_BDCTRLB_CASTEN(value)             (DMA_BDCTRLB_CASTEN_Msk & (_UINT32_(value) << DMA_BDCTRLB_CASTEN_Pos)) /* Assigment of value for CASTEN in the DMA_BDCTRLB register */
#define DMA_BDCTRLB_CRCEN_Pos                 _UINT32_(31)                                         /* (DMA_BDCTRLB) CRC Enable bit Position */
#define DMA_BDCTRLB_CRCEN_Msk                 (_UINT32_(0x1) << DMA_BDCTRLB_CRCEN_Pos)             /* (DMA_BDCTRLB) CRC Enable bit Mask */
#define DMA_BDCTRLB_CRCEN(value)              (DMA_BDCTRLB_CRCEN_Msk & (_UINT32_(value) << DMA_BDCTRLB_CRCEN_Pos)) /* Assigment of value for CRCEN in the DMA_BDCTRLB register */
#define DMA_BDCTRLB_Msk                       _UINT32_(0xA7FFE377)                                 /* (DMA_BDCTRLB) Register Mask  */


/* -------- DMA_BDEVCTRL : (DMA Offset: 0x0C) (R/W 16) CURRENT BUFFER DESCRIPTOR EVENT CONTROL -------- */
#define DMA_BDEVCTRL_RESETVALUE               _UINT16_(0x00)                                       /*  (DMA_BDEVCTRL) CURRENT BUFFER DESCRIPTOR EVENT CONTROL  Reset Value */

#define DMA_BDEVCTRL_EVAUXACT_Pos             _UINT16_(0)                                          /* (DMA_BDEVCTRL) Channel Auxiliary Event Input Action Position */
#define DMA_BDEVCTRL_EVAUXACT_Msk             (_UINT16_(0x3) << DMA_BDEVCTRL_EVAUXACT_Pos)         /* (DMA_BDEVCTRL) Channel Auxiliary Event Input Action Mask */
#define DMA_BDEVCTRL_EVAUXACT(value)          (DMA_BDEVCTRL_EVAUXACT_Msk & (_UINT16_(value) << DMA_BDEVCTRL_EVAUXACT_Pos)) /* Assigment of value for EVAUXACT in the DMA_BDEVCTRL register */
#define   DMA_BDEVCTRL_EVAUXACT_ABORT_BLK_XFER_Val _UINT16_(0x0)                                        /* (DMA_BDEVCTRL) Event Aborts Bock Transfer  */
#define   DMA_BDEVCTRL_EVAUXACT_INCR_CHN_PRI_Val _UINT16_(0x1)                                        /* (DMA_BDEVCTRL) Event Increments Channel Priority  */
#define   DMA_BDEVCTRL_EVAUXACT_COND_TRIG_Val _UINT16_(0x2)                                        /* (DMA_BDEVCTRL) Event acts as a Conditional Trigger  */
#define DMA_BDEVCTRL_EVAUXACT_ABORT_BLK_XFER  (DMA_BDEVCTRL_EVAUXACT_ABORT_BLK_XFER_Val << DMA_BDEVCTRL_EVAUXACT_Pos) /* (DMA_BDEVCTRL) Event Aborts Bock Transfer Position  */
#define DMA_BDEVCTRL_EVAUXACT_INCR_CHN_PRI    (DMA_BDEVCTRL_EVAUXACT_INCR_CHN_PRI_Val << DMA_BDEVCTRL_EVAUXACT_Pos) /* (DMA_BDEVCTRL) Event Increments Channel Priority Position  */
#define DMA_BDEVCTRL_EVAUXACT_COND_TRIG       (DMA_BDEVCTRL_EVAUXACT_COND_TRIG_Val << DMA_BDEVCTRL_EVAUXACT_Pos) /* (DMA_BDEVCTRL) Event acts as a Conditional Trigger Position  */
#define DMA_BDEVCTRL_EVOMODE_Pos              _UINT16_(2)                                          /* (DMA_BDEVCTRL) Channel Event Output Mode Position */
#define DMA_BDEVCTRL_EVOMODE_Msk              (_UINT16_(0x3) << DMA_BDEVCTRL_EVOMODE_Pos)          /* (DMA_BDEVCTRL) Channel Event Output Mode Mask */
#define DMA_BDEVCTRL_EVOMODE(value)           (DMA_BDEVCTRL_EVOMODE_Msk & (_UINT16_(value) << DMA_BDEVCTRL_EVOMODE_Pos)) /* Assigment of value for EVOMODE in the DMA_BDEVCTRL register */
#define   DMA_BDEVCTRL_EVOMODE_STRB_ON_BLCK_XFER_Val _UINT16_(0x0)                                        /* (DMA_BDEVCTRL) Generate a channel event strobe for 1 clock cycle at the end of block transfer  */
#define   DMA_BDEVCTRL_EVOMODE_STRB_ON_CELL_XFER_Val _UINT16_(0x1)                                        /* (DMA_BDEVCTRL) Generate a channel event strobe for 1 clock cycle at the end of cell transfer  */
#define   DMA_BDEVCTRL_EVOMODE_STRB_START_EVT_TRG_TO_CELL_XFER_READ_Val _UINT16_(0x2)                                        /* (DMA_BDEVCTRL) Generate a channel event strobe from start event trigger to the completion of cell transfer read  */
#define   DMA_BDEVCTRL_EVOMODE_STRB_START_EVT_TRG_TO_CELL_XFER_WRITE_Val _UINT16_(0x3)                                        /* (DMA_BDEVCTRL) Generate a channel event strobe from start event trigger to the completion of cell transfer write  */
#define DMA_BDEVCTRL_EVOMODE_STRB_ON_BLCK_XFER (DMA_BDEVCTRL_EVOMODE_STRB_ON_BLCK_XFER_Val << DMA_BDEVCTRL_EVOMODE_Pos) /* (DMA_BDEVCTRL) Generate a channel event strobe for 1 clock cycle at the end of block transfer Position  */
#define DMA_BDEVCTRL_EVOMODE_STRB_ON_CELL_XFER (DMA_BDEVCTRL_EVOMODE_STRB_ON_CELL_XFER_Val << DMA_BDEVCTRL_EVOMODE_Pos) /* (DMA_BDEVCTRL) Generate a channel event strobe for 1 clock cycle at the end of cell transfer Position  */
#define DMA_BDEVCTRL_EVOMODE_STRB_START_EVT_TRG_TO_CELL_XFER_READ (DMA_BDEVCTRL_EVOMODE_STRB_START_EVT_TRG_TO_CELL_XFER_READ_Val << DMA_BDEVCTRL_EVOMODE_Pos) /* (DMA_BDEVCTRL) Generate a channel event strobe from start event trigger to the completion of cell transfer read Position  */
#define DMA_BDEVCTRL_EVOMODE_STRB_START_EVT_TRG_TO_CELL_XFER_WRITE (DMA_BDEVCTRL_EVOMODE_STRB_START_EVT_TRG_TO_CELL_XFER_WRITE_Val << DMA_BDEVCTRL_EVOMODE_Pos) /* (DMA_BDEVCTRL) Generate a channel event strobe from start event trigger to the completion of cell transfer write Position  */
#define DMA_BDEVCTRL_EVAUXIE_Pos              _UINT16_(5)                                          /* (DMA_BDEVCTRL) Channel Auxiliary Event Enable (0: disable; 1: enable) Position */
#define DMA_BDEVCTRL_EVAUXIE_Msk              (_UINT16_(0x1) << DMA_BDEVCTRL_EVAUXIE_Pos)          /* (DMA_BDEVCTRL) Channel Auxiliary Event Enable (0: disable; 1: enable) Mask */
#define DMA_BDEVCTRL_EVAUXIE(value)           (DMA_BDEVCTRL_EVAUXIE_Msk & (_UINT16_(value) << DMA_BDEVCTRL_EVAUXIE_Pos)) /* Assigment of value for EVAUXIE in the DMA_BDEVCTRL register */
#define DMA_BDEVCTRL_EVSTRIE_Pos              _UINT16_(6)                                          /* (DMA_BDEVCTRL) Channel Start Event Input Enable (0: disable; 1:enable) Position */
#define DMA_BDEVCTRL_EVSTRIE_Msk              (_UINT16_(0x1) << DMA_BDEVCTRL_EVSTRIE_Pos)          /* (DMA_BDEVCTRL) Channel Start Event Input Enable (0: disable; 1:enable) Mask */
#define DMA_BDEVCTRL_EVSTRIE(value)           (DMA_BDEVCTRL_EVSTRIE_Msk & (_UINT16_(value) << DMA_BDEVCTRL_EVSTRIE_Pos)) /* Assigment of value for EVSTRIE in the DMA_BDEVCTRL register */
#define DMA_BDEVCTRL_EVOE_Pos                 _UINT16_(7)                                          /* (DMA_BDEVCTRL) Channel Event Output Enable (0: disable; 1: enable) Position */
#define DMA_BDEVCTRL_EVOE_Msk                 (_UINT16_(0x1) << DMA_BDEVCTRL_EVOE_Pos)             /* (DMA_BDEVCTRL) Channel Event Output Enable (0: disable; 1: enable) Mask */
#define DMA_BDEVCTRL_EVOE(value)              (DMA_BDEVCTRL_EVOE_Msk & (_UINT16_(value) << DMA_BDEVCTRL_EVOE_Pos)) /* Assigment of value for EVOE in the DMA_BDEVCTRL register */
#define DMA_BDEVCTRL_Msk                      _UINT16_(0x00EF)                                     /* (DMA_BDEVCTRL) Register Mask  */


/* -------- DMA_BDCTRLCRC : (DMA Offset: 0x0E) (R/W 16) CURRENT BUFFER DESCRIPTOR CRC CONTROL -------- */
#define DMA_BDCTRLCRC_RESETVALUE              _UINT16_(0x00)                                       /*  (DMA_BDCTRLCRC) CURRENT BUFFER DESCRIPTOR CRC CONTROL  Reset Value */

#define DMA_BDCTRLCRC_CRCMD_Pos               _UINT16_(0)                                          /* (DMA_BDCTRLCRC) CRC/Checksum Mode Position */
#define DMA_BDCTRLCRC_CRCMD_Msk               (_UINT16_(0x7) << DMA_BDCTRLCRC_CRCMD_Pos)           /* (DMA_BDCTRLCRC) CRC/Checksum Mode Mask */
#define DMA_BDCTRLCRC_CRCMD(value)            (DMA_BDCTRLCRC_CRCMD_Msk & (_UINT16_(value) << DMA_BDCTRLCRC_CRCMD_Pos)) /* Assigment of value for CRCMD in the DMA_BDCTRLCRC register */
#define   DMA_BDCTRLCRC_CRCMD_CRC_16_Val      _UINT16_(0x0)                                        /* (DMA_BDCTRLCRC) Normal (0x8005) CRC-16/CRC-16-IBM/CRC-16-ANSI  */
#define   DMA_BDCTRLCRC_CRCMD_CRC_16_CCITT_Val _UINT16_(0x1)                                        /* (DMA_BDCTRLCRC) Normal (0x1021) CRC-16-CCITT  */
#define   DMA_BDCTRLCRC_CRCMD_16_BIT_CRCPOLYA_Val _UINT16_(0x2)                                        /* (DMA_BDCTRLCRC) CRC-16 based on polynomial provided in CRCPOLYA (POLYA[15:0]) register  */
#define   DMA_BDCTRLCRC_CRCMD_16_BIT_CRCPOLYB_Val _UINT16_(0x3)                                        /* (DMA_BDCTRLCRC) CRC-16 based on polynomial provided in CRCPOLYB (POLYB[15:0]) register  */
#define   DMA_BDCTRLCRC_CRCMD_CRC_32_Val      _UINT16_(0x4)                                        /* (DMA_BDCTRLCRC) Normal (0x04C11DB7) CRC-32  */
#define   DMA_BDCTRLCRC_CRCMD_32_BIT_CRCPOLYA_Val _UINT16_(0x5)                                        /* (DMA_BDCTRLCRC) CRC-32 based on polynomial provided in CRCPOLYA register  */
#define   DMA_BDCTRLCRC_CRCMD_32_BIT_CRCPOLYB_Val _UINT16_(0x6)                                        /* (DMA_BDCTRLCRC) CRC-32 based on polynomial provided in CRCPOLYB register  */
#define   DMA_BDCTRLCRC_CRCMD_IP_HDR_CHECKSUM_Val _UINT16_(0x7)                                        /* (DMA_BDCTRLCRC) Calculate IP header checksum  */
#define DMA_BDCTRLCRC_CRCMD_CRC_16            (DMA_BDCTRLCRC_CRCMD_CRC_16_Val << DMA_BDCTRLCRC_CRCMD_Pos) /* (DMA_BDCTRLCRC) Normal (0x8005) CRC-16/CRC-16-IBM/CRC-16-ANSI Position  */
#define DMA_BDCTRLCRC_CRCMD_CRC_16_CCITT      (DMA_BDCTRLCRC_CRCMD_CRC_16_CCITT_Val << DMA_BDCTRLCRC_CRCMD_Pos) /* (DMA_BDCTRLCRC) Normal (0x1021) CRC-16-CCITT Position  */
#define DMA_BDCTRLCRC_CRCMD_16_BIT_CRCPOLYA   (DMA_BDCTRLCRC_CRCMD_16_BIT_CRCPOLYA_Val << DMA_BDCTRLCRC_CRCMD_Pos) /* (DMA_BDCTRLCRC) CRC-16 based on polynomial provided in CRCPOLYA (POLYA[15:0]) register Position  */
#define DMA_BDCTRLCRC_CRCMD_16_BIT_CRCPOLYB   (DMA_BDCTRLCRC_CRCMD_16_BIT_CRCPOLYB_Val << DMA_BDCTRLCRC_CRCMD_Pos) /* (DMA_BDCTRLCRC) CRC-16 based on polynomial provided in CRCPOLYB (POLYB[15:0]) register Position  */
#define DMA_BDCTRLCRC_CRCMD_CRC_32            (DMA_BDCTRLCRC_CRCMD_CRC_32_Val << DMA_BDCTRLCRC_CRCMD_Pos) /* (DMA_BDCTRLCRC) Normal (0x04C11DB7) CRC-32 Position  */
#define DMA_BDCTRLCRC_CRCMD_32_BIT_CRCPOLYA   (DMA_BDCTRLCRC_CRCMD_32_BIT_CRCPOLYA_Val << DMA_BDCTRLCRC_CRCMD_Pos) /* (DMA_BDCTRLCRC) CRC-32 based on polynomial provided in CRCPOLYA register Position  */
#define DMA_BDCTRLCRC_CRCMD_32_BIT_CRCPOLYB   (DMA_BDCTRLCRC_CRCMD_32_BIT_CRCPOLYB_Val << DMA_BDCTRLCRC_CRCMD_Pos) /* (DMA_BDCTRLCRC) CRC-32 based on polynomial provided in CRCPOLYB register Position  */
#define DMA_BDCTRLCRC_CRCMD_IP_HDR_CHECKSUM   (DMA_BDCTRLCRC_CRCMD_IP_HDR_CHECKSUM_Val << DMA_BDCTRLCRC_CRCMD_Pos) /* (DMA_BDCTRLCRC) Calculate IP header checksum Position  */
#define DMA_BDCTRLCRC_CRCAPP_Pos              _UINT16_(3)                                          /* (DMA_BDCTRLCRC) CRC Append Mode Position */
#define DMA_BDCTRLCRC_CRCAPP_Msk              (_UINT16_(0x1) << DMA_BDCTRLCRC_CRCAPP_Pos)          /* (DMA_BDCTRLCRC) CRC Append Mode Mask */
#define DMA_BDCTRLCRC_CRCAPP(value)           (DMA_BDCTRLCRC_CRCAPP_Msk & (_UINT16_(value) << DMA_BDCTRLCRC_CRCAPP_Pos)) /* Assigment of value for CRCAPP in the DMA_BDCTRLCRC register */
#define DMA_BDCTRLCRC_CRCXOR_Pos              _UINT16_(5)                                          /* (DMA_BDCTRLCRC) CRC XOR Mode Position */
#define DMA_BDCTRLCRC_CRCXOR_Msk              (_UINT16_(0x1) << DMA_BDCTRLCRC_CRCXOR_Pos)          /* (DMA_BDCTRLCRC) CRC XOR Mode Mask */
#define DMA_BDCTRLCRC_CRCXOR(value)           (DMA_BDCTRLCRC_CRCXOR_Msk & (_UINT16_(value) << DMA_BDCTRLCRC_CRCXOR_Pos)) /* Assigment of value for CRCXOR in the DMA_BDCTRLCRC register */
#define DMA_BDCTRLCRC_CRCROUT_Pos             _UINT16_(6)                                          /* (DMA_BDCTRLCRC) CRC Reflected Output Mode Position */
#define DMA_BDCTRLCRC_CRCROUT_Msk             (_UINT16_(0x1) << DMA_BDCTRLCRC_CRCROUT_Pos)         /* (DMA_BDCTRLCRC) CRC Reflected Output Mode Mask */
#define DMA_BDCTRLCRC_CRCROUT(value)          (DMA_BDCTRLCRC_CRCROUT_Msk & (_UINT16_(value) << DMA_BDCTRLCRC_CRCROUT_Pos)) /* Assigment of value for CRCROUT in the DMA_BDCTRLCRC register */
#define DMA_BDCTRLCRC_CRCRIN_Pos              _UINT16_(7)                                          /* (DMA_BDCTRLCRC) CRC Reflect Input Selection Position */
#define DMA_BDCTRLCRC_CRCRIN_Msk              (_UINT16_(0x1) << DMA_BDCTRLCRC_CRCRIN_Pos)          /* (DMA_BDCTRLCRC) CRC Reflect Input Selection Mask */
#define DMA_BDCTRLCRC_CRCRIN(value)           (DMA_BDCTRLCRC_CRCRIN_Msk & (_UINT16_(value) << DMA_BDCTRLCRC_CRCRIN_Pos)) /* Assigment of value for CRCRIN in the DMA_BDCTRLCRC register */
#define DMA_BDCTRLCRC_Msk                     _UINT16_(0x00EF)                                     /* (DMA_BDCTRLCRC) Register Mask  */


/* -------- DMA_BDSSA : (DMA Offset: 0x10) (R/W 32) CURRENT BUFFER DESCRIPTOR SOURCE START ADDRESS -------- */
#define DMA_BDSSA_RESETVALUE                  _UINT32_(0x00)                                       /*  (DMA_BDSSA) CURRENT BUFFER DESCRIPTOR SOURCE START ADDRESS  Reset Value */

#define DMA_BDSSA_SSA_Pos                     _UINT32_(0)                                          /* (DMA_BDSSA) Source Start Address Position */
#define DMA_BDSSA_SSA_Msk                     (_UINT32_(0xFFFFFFFF) << DMA_BDSSA_SSA_Pos)          /* (DMA_BDSSA) Source Start Address Mask */
#define DMA_BDSSA_SSA(value)                  (DMA_BDSSA_SSA_Msk & (_UINT32_(value) << DMA_BDSSA_SSA_Pos)) /* Assigment of value for SSA in the DMA_BDSSA register */
#define DMA_BDSSA_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (DMA_BDSSA) Register Mask  */


/* -------- DMA_BDDSA : (DMA Offset: 0x14) (R/W 32) CURRENT BUFFER DESCRIPTOR DESTINATION START ADDRESS -------- */
#define DMA_BDDSA_RESETVALUE                  _UINT32_(0x00)                                       /*  (DMA_BDDSA) CURRENT BUFFER DESCRIPTOR DESTINATION START ADDRESS  Reset Value */

#define DMA_BDDSA_DSA_Pos                     _UINT32_(0)                                          /* (DMA_BDDSA) Destination Start Address Position */
#define DMA_BDDSA_DSA_Msk                     (_UINT32_(0xFFFFFFFF) << DMA_BDDSA_DSA_Pos)          /* (DMA_BDDSA) Destination Start Address Mask */
#define DMA_BDDSA_DSA(value)                  (DMA_BDDSA_DSA_Msk & (_UINT32_(value) << DMA_BDDSA_DSA_Pos)) /* Assigment of value for DSA in the DMA_BDDSA register */
#define DMA_BDDSA_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (DMA_BDDSA) Register Mask  */


/* -------- DMA_BDSSTRD : (DMA Offset: 0x18) (R/W 16) CURRENT BUFFER DESCRIPTOR SOURCE CELL STRIDE -------- */
#define DMA_BDSSTRD_RESETVALUE                _UINT16_(0x00)                                       /*  (DMA_BDSSTRD) CURRENT BUFFER DESCRIPTOR SOURCE CELL STRIDE  Reset Value */

#define DMA_BDSSTRD_SSTRD_Pos                 _UINT16_(0)                                          /* (DMA_BDSSTRD) Source Stride Size Position */
#define DMA_BDSSTRD_SSTRD_Msk                 (_UINT16_(0xFFFF) << DMA_BDSSTRD_SSTRD_Pos)          /* (DMA_BDSSTRD) Source Stride Size Mask */
#define DMA_BDSSTRD_SSTRD(value)              (DMA_BDSSTRD_SSTRD_Msk & (_UINT16_(value) << DMA_BDSSTRD_SSTRD_Pos)) /* Assigment of value for SSTRD in the DMA_BDSSTRD register */
#define DMA_BDSSTRD_Msk                       _UINT16_(0xFFFF)                                     /* (DMA_BDSSTRD) Register Mask  */


/* -------- DMA_BDDSTRD : (DMA Offset: 0x1A) (R/W 16) CURRENT BUFFER DESCRIPTOR DESTINATION CELL STRIDE -------- */
#define DMA_BDDSTRD_RESETVALUE                _UINT16_(0x00)                                       /*  (DMA_BDDSTRD) CURRENT BUFFER DESCRIPTOR DESTINATION CELL STRIDE  Reset Value */

#define DMA_BDDSTRD_DSTRD_Pos                 _UINT16_(0)                                          /* (DMA_BDDSTRD) Destination Stride Size Position */
#define DMA_BDDSTRD_DSTRD_Msk                 (_UINT16_(0xFFFF) << DMA_BDDSTRD_DSTRD_Pos)          /* (DMA_BDDSTRD) Destination Stride Size Mask */
#define DMA_BDDSTRD_DSTRD(value)              (DMA_BDDSTRD_DSTRD_Msk & (_UINT16_(value) << DMA_BDDSTRD_DSTRD_Pos)) /* Assigment of value for DSTRD in the DMA_BDDSTRD register */
#define DMA_BDDSTRD_Msk                       _UINT16_(0xFFFF)                                     /* (DMA_BDDSTRD) Register Mask  */


/* -------- DMA_BDXSIZ : (DMA Offset: 0x1C) (R/W 32) CURRENT BUFFER DESCRIPTOR TRANSFER SIZE -------- */
#define DMA_BDXSIZ_RESETVALUE                 _UINT32_(0x00)                                       /*  (DMA_BDXSIZ) CURRENT BUFFER DESCRIPTOR TRANSFER SIZE  Reset Value */

#define DMA_BDXSIZ_CSZ_Pos                    _UINT32_(0)                                          /* (DMA_BDXSIZ) Cell transfer size in bytes. Position */
#define DMA_BDXSIZ_CSZ_Msk                    (_UINT32_(0x3FF) << DMA_BDXSIZ_CSZ_Pos)              /* (DMA_BDXSIZ) Cell transfer size in bytes. Mask */
#define DMA_BDXSIZ_CSZ(value)                 (DMA_BDXSIZ_CSZ_Msk & (_UINT32_(value) << DMA_BDXSIZ_CSZ_Pos)) /* Assigment of value for CSZ in the DMA_BDXSIZ register */
#define DMA_BDXSIZ_BLKSZ_Pos                  _UINT32_(16)                                         /* (DMA_BDXSIZ) Block transfer size in bytes. Position */
#define DMA_BDXSIZ_BLKSZ_Msk                  (_UINT32_(0xFFFF) << DMA_BDXSIZ_BLKSZ_Pos)           /* (DMA_BDXSIZ) Block transfer size in bytes. Mask */
#define DMA_BDXSIZ_BLKSZ(value)               (DMA_BDXSIZ_BLKSZ_Msk & (_UINT32_(value) << DMA_BDXSIZ_BLKSZ_Pos)) /* Assigment of value for BLKSZ in the DMA_BDXSIZ register */
#define DMA_BDXSIZ_Msk                        _UINT32_(0xFFFF03FF)                                 /* (DMA_BDXSIZ) Register Mask  */


/* -------- DMA_BDPDAT : (DMA Offset: 0x20) (R/W 32) CURRENT BUFFER DESCRIPTOR PATTERN MATCH DATA -------- */
#define DMA_BDPDAT_RESETVALUE                 _UINT32_(0x00)                                       /*  (DMA_BDPDAT) CURRENT BUFFER DESCRIPTOR PATTERN MATCH DATA  Reset Value */

#define DMA_BDPDAT_PDAT_Pos                   _UINT32_(0)                                          /* (DMA_BDPDAT) Channel Pattern Match Data Position */
#define DMA_BDPDAT_PDAT_Msk                   (_UINT32_(0xFFFF) << DMA_BDPDAT_PDAT_Pos)            /* (DMA_BDPDAT) Channel Pattern Match Data Mask */
#define DMA_BDPDAT_PDAT(value)                (DMA_BDPDAT_PDAT_Msk & (_UINT32_(value) << DMA_BDPDAT_PDAT_Pos)) /* Assigment of value for PDAT in the DMA_BDPDAT register */
#define DMA_BDPDAT_PIGN_Pos                   _UINT32_(24)                                         /* (DMA_BDPDAT) Channel Pattern Ignore Value Position */
#define DMA_BDPDAT_PIGN_Msk                   (_UINT32_(0xFF) << DMA_BDPDAT_PIGN_Pos)              /* (DMA_BDPDAT) Channel Pattern Ignore Value Mask */
#define DMA_BDPDAT_PIGN(value)                (DMA_BDPDAT_PIGN_Msk & (_UINT32_(value) << DMA_BDPDAT_PIGN_Pos)) /* Assigment of value for PIGN in the DMA_BDPDAT register */
#define DMA_BDPDAT_Msk                        _UINT32_(0xFF00FFFF)                                 /* (DMA_BDPDAT) Register Mask  */


/* -------- DMA_BDCRCDAT : (DMA Offset: 0x24) (R/W 32) CURRENT BUFFER DESCRIPTOR CRC/CHECKSUM DATA -------- */
#define DMA_BDCRCDAT_RESETVALUE               _UINT32_(0x00)                                       /*  (DMA_BDCRCDAT) CURRENT BUFFER DESCRIPTOR CRC/CHECKSUM DATA  Reset Value */

#define DMA_BDCRCDAT_CRCDAT_Pos               _UINT32_(0)                                          /* (DMA_BDCRCDAT) CRC/Checksum Data Register Position */
#define DMA_BDCRCDAT_CRCDAT_Msk               (_UINT32_(0xFFFFFFFF) << DMA_BDCRCDAT_CRCDAT_Pos)    /* (DMA_BDCRCDAT) CRC/Checksum Data Register Mask */
#define DMA_BDCRCDAT_CRCDAT(value)            (DMA_BDCRCDAT_CRCDAT_Msk & (_UINT32_(value) << DMA_BDCRCDAT_CRCDAT_Pos)) /* Assigment of value for CRCDAT in the DMA_BDCRCDAT register */
#define DMA_BDCRCDAT_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (DMA_BDCRCDAT) Register Mask  */


/* -------- DMA_CHCTRLA : (DMA Offset: 0x00) (R/W 32) CHANNEL CONTROL REGISTER A -------- */
#define DMA_CHCTRLA_RESETVALUE                _UINT32_(0x00)                                       /*  (DMA_CHCTRLA) CHANNEL CONTROL REGISTER A  Reset Value */

#define DMA_CHCTRLA_ENABLE_Pos                _UINT32_(0)                                          /* (DMA_CHCTRLA) Channel Enable Position */
#define DMA_CHCTRLA_ENABLE_Msk                (_UINT32_(0x1) << DMA_CHCTRLA_ENABLE_Pos)            /* (DMA_CHCTRLA) Channel Enable Mask */
#define DMA_CHCTRLA_ENABLE(value)             (DMA_CHCTRLA_ENABLE_Msk & (_UINT32_(value) << DMA_CHCTRLA_ENABLE_Pos)) /* Assigment of value for ENABLE in the DMA_CHCTRLA register */
#define DMA_CHCTRLA_LLEN_Pos                  _UINT32_(8)                                          /* (DMA_CHCTRLA) Linked List Enable Position */
#define DMA_CHCTRLA_LLEN_Msk                  (_UINT32_(0x1) << DMA_CHCTRLA_LLEN_Pos)              /* (DMA_CHCTRLA) Linked List Enable Mask */
#define DMA_CHCTRLA_LLEN(value)               (DMA_CHCTRLA_LLEN_Msk & (_UINT32_(value) << DMA_CHCTRLA_LLEN_Pos)) /* Assigment of value for LLEN in the DMA_CHCTRLA register */
#define DMA_CHCTRLA_SWFRC_Pos                 _UINT32_(16)                                         /* (DMA_CHCTRLA) Software Forced Trigger Position */
#define DMA_CHCTRLA_SWFRC_Msk                 (_UINT32_(0x1) << DMA_CHCTRLA_SWFRC_Pos)             /* (DMA_CHCTRLA) Software Forced Trigger Mask */
#define DMA_CHCTRLA_SWFRC(value)              (DMA_CHCTRLA_SWFRC_Msk & (_UINT32_(value) << DMA_CHCTRLA_SWFRC_Pos)) /* Assigment of value for SWFRC in the DMA_CHCTRLA register */
#define DMA_CHCTRLA_RUNSTDBY_Pos              _UINT32_(24)                                         /* (DMA_CHCTRLA) Run In Standby Position */
#define DMA_CHCTRLA_RUNSTDBY_Msk              (_UINT32_(0x1) << DMA_CHCTRLA_RUNSTDBY_Pos)          /* (DMA_CHCTRLA) Run In Standby Mask */
#define DMA_CHCTRLA_RUNSTDBY(value)           (DMA_CHCTRLA_RUNSTDBY_Msk & (_UINT32_(value) << DMA_CHCTRLA_RUNSTDBY_Pos)) /* Assigment of value for RUNSTDBY in the DMA_CHCTRLA register */
#define DMA_CHCTRLA_Msk                       _UINT32_(0x01010101)                                 /* (DMA_CHCTRLA) Register Mask  */


/* -------- DMA_CHCTRLB : (DMA Offset: 0x04) (R/W 32) CHANNEL CONTROL REGISTER B -------- */
#define DMA_CHCTRLB_RESETVALUE                _UINT32_(0x00)                                       /*  (DMA_CHCTRLB) CHANNEL CONTROL REGISTER B  Reset Value */

#define DMA_CHCTRLB_WAS_Pos                   _UINT32_(0)                                          /* (DMA_CHCTRLB) Channel Write Address Sequence. Position */
#define DMA_CHCTRLB_WAS_Msk                   (_UINT32_(0x7) << DMA_CHCTRLB_WAS_Pos)               /* (DMA_CHCTRLB) Channel Write Address Sequence. Mask */
#define DMA_CHCTRLB_WAS(value)                (DMA_CHCTRLB_WAS_Msk & (_UINT32_(value) << DMA_CHCTRLB_WAS_Pos)) /* Assigment of value for WAS in the DMA_CHCTRLB register */
#define   DMA_CHCTRLB_WAS_BYTE_ADDR_INCR_Val  _UINT32_(0x0)                                        /* (DMA_CHCTRLB) Incrementing Address+1 with Transfers of Byte Operands  */
#define   DMA_CHCTRLB_WAS_HALF_WORD_ADDR_INCR_Val _UINT32_(0x1)                                        /* (DMA_CHCTRLB) Incrementing Address+2 with Transfers of HalfWord Operands  */
#define   DMA_CHCTRLB_WAS_AUTO_ADDR_INCR_Val  _UINT32_(0x2)                                        /* (DMA_CHCTRLB) Auto Increment Address and Transfer Size  */
#define   DMA_CHCTRLB_WAS_FIXED_BYTE_ADDR_INCR_Val _UINT32_(0x3)                                        /* (DMA_CHCTRLB) Fixed Byte Address (Single Byte Address with Enable Based upon 2 LSBs)  */
#define   DMA_CHCTRLB_WAS_FIXED_HALF_WORD_ADDR_INCR_Val _UINT32_(0x4)                                        /* (DMA_CHCTRLB) Fixed Address of HalfWord Operand (Single HalfWord Aligned Address)  */
#define   DMA_CHCTRLB_WAS_FIXED_WORD_ADDR_INCR_Val _UINT32_(0x5)                                        /* (DMA_CHCTRLB) Fixed Address Word Burst Transfer  */
#define DMA_CHCTRLB_WAS_BYTE_ADDR_INCR        (DMA_CHCTRLB_WAS_BYTE_ADDR_INCR_Val << DMA_CHCTRLB_WAS_Pos) /* (DMA_CHCTRLB) Incrementing Address+1 with Transfers of Byte Operands Position  */
#define DMA_CHCTRLB_WAS_HALF_WORD_ADDR_INCR   (DMA_CHCTRLB_WAS_HALF_WORD_ADDR_INCR_Val << DMA_CHCTRLB_WAS_Pos) /* (DMA_CHCTRLB) Incrementing Address+2 with Transfers of HalfWord Operands Position  */
#define DMA_CHCTRLB_WAS_AUTO_ADDR_INCR        (DMA_CHCTRLB_WAS_AUTO_ADDR_INCR_Val << DMA_CHCTRLB_WAS_Pos) /* (DMA_CHCTRLB) Auto Increment Address and Transfer Size Position  */
#define DMA_CHCTRLB_WAS_FIXED_BYTE_ADDR_INCR  (DMA_CHCTRLB_WAS_FIXED_BYTE_ADDR_INCR_Val << DMA_CHCTRLB_WAS_Pos) /* (DMA_CHCTRLB) Fixed Byte Address (Single Byte Address with Enable Based upon 2 LSBs) Position  */
#define DMA_CHCTRLB_WAS_FIXED_HALF_WORD_ADDR_INCR (DMA_CHCTRLB_WAS_FIXED_HALF_WORD_ADDR_INCR_Val << DMA_CHCTRLB_WAS_Pos) /* (DMA_CHCTRLB) Fixed Address of HalfWord Operand (Single HalfWord Aligned Address) Position  */
#define DMA_CHCTRLB_WAS_FIXED_WORD_ADDR_INCR  (DMA_CHCTRLB_WAS_FIXED_WORD_ADDR_INCR_Val << DMA_CHCTRLB_WAS_Pos) /* (DMA_CHCTRLB) Fixed Address Word Burst Transfer Position  */
#define DMA_CHCTRLB_RAS_Pos                   _UINT32_(4)                                          /* (DMA_CHCTRLB) Channel Read Address Sequence Position */
#define DMA_CHCTRLB_RAS_Msk                   (_UINT32_(0x7) << DMA_CHCTRLB_RAS_Pos)               /* (DMA_CHCTRLB) Channel Read Address Sequence Mask */
#define DMA_CHCTRLB_RAS(value)                (DMA_CHCTRLB_RAS_Msk & (_UINT32_(value) << DMA_CHCTRLB_RAS_Pos)) /* Assigment of value for RAS in the DMA_CHCTRLB register */
#define   DMA_CHCTRLB_RAS_BYTE_ADDR_INCR_Val  _UINT32_(0x0)                                        /* (DMA_CHCTRLB) Incrementing Address+1 with Transfers of Byte Operands  */
#define   DMA_CHCTRLB_RAS_HALF_WORD_ADDR_INCR_Val _UINT32_(0x1)                                        /* (DMA_CHCTRLB) Incrementing Address+2 with Transfers of HalfWord Operands  */
#define   DMA_CHCTRLB_RAS_AUTO_ADDR_INCR_Val  _UINT32_(0x2)                                        /* (DMA_CHCTRLB) Auto Increment Address and Transfer Size  */
#define   DMA_CHCTRLB_RAS_FIXED_BYTE_ADDR_INCR_Val _UINT32_(0x3)                                        /* (DMA_CHCTRLB) Fixed Byte Address (Single Byte Address with Enable Based upon 2 LSBs)  */
#define   DMA_CHCTRLB_RAS_FIXED_HALF_WORD_ADDR_INCR_Val _UINT32_(0x4)                                        /* (DMA_CHCTRLB) Fixed Address of HalfWord Operand (Single HalfWord Aligned Address)  */
#define   DMA_CHCTRLB_RAS_FIXED_WORD_ADDR_INCR_Val _UINT32_(0x5)                                        /* (DMA_CHCTRLB) Fixed Address Word Burst Transfer  */
#define DMA_CHCTRLB_RAS_BYTE_ADDR_INCR        (DMA_CHCTRLB_RAS_BYTE_ADDR_INCR_Val << DMA_CHCTRLB_RAS_Pos) /* (DMA_CHCTRLB) Incrementing Address+1 with Transfers of Byte Operands Position  */
#define DMA_CHCTRLB_RAS_HALF_WORD_ADDR_INCR   (DMA_CHCTRLB_RAS_HALF_WORD_ADDR_INCR_Val << DMA_CHCTRLB_RAS_Pos) /* (DMA_CHCTRLB) Incrementing Address+2 with Transfers of HalfWord Operands Position  */
#define DMA_CHCTRLB_RAS_AUTO_ADDR_INCR        (DMA_CHCTRLB_RAS_AUTO_ADDR_INCR_Val << DMA_CHCTRLB_RAS_Pos) /* (DMA_CHCTRLB) Auto Increment Address and Transfer Size Position  */
#define DMA_CHCTRLB_RAS_FIXED_BYTE_ADDR_INCR  (DMA_CHCTRLB_RAS_FIXED_BYTE_ADDR_INCR_Val << DMA_CHCTRLB_RAS_Pos) /* (DMA_CHCTRLB) Fixed Byte Address (Single Byte Address with Enable Based upon 2 LSBs) Position  */
#define DMA_CHCTRLB_RAS_FIXED_HALF_WORD_ADDR_INCR (DMA_CHCTRLB_RAS_FIXED_HALF_WORD_ADDR_INCR_Val << DMA_CHCTRLB_RAS_Pos) /* (DMA_CHCTRLB) Fixed Address of HalfWord Operand (Single HalfWord Aligned Address) Position  */
#define DMA_CHCTRLB_RAS_FIXED_WORD_ADDR_INCR  (DMA_CHCTRLB_RAS_FIXED_WORD_ADDR_INCR_Val << DMA_CHCTRLB_RAS_Pos) /* (DMA_CHCTRLB) Fixed Address Word Burst Transfer Position  */
#define DMA_CHCTRLB_PRI_Pos                   _UINT32_(8)                                          /* (DMA_CHCTRLB) Channel Priority level. Position */
#define DMA_CHCTRLB_PRI_Msk                   (_UINT32_(0x3) << DMA_CHCTRLB_PRI_Pos)               /* (DMA_CHCTRLB) Channel Priority level. Mask */
#define DMA_CHCTRLB_PRI(value)                (DMA_CHCTRLB_PRI_Msk & (_UINT32_(value) << DMA_CHCTRLB_PRI_Pos)) /* Assigment of value for PRI in the DMA_CHCTRLB register */
#define   DMA_CHCTRLB_PRI_PRI_1_Val           _UINT32_(0x0)                                        /* (DMA_CHCTRLB) Channel Priority is 1  */
#define   DMA_CHCTRLB_PRI_PRI_2_Val           _UINT32_(0x1)                                        /* (DMA_CHCTRLB) Channel Priority is 2  */
#define   DMA_CHCTRLB_PRI_PRI_3_Val           _UINT32_(0x2)                                        /* (DMA_CHCTRLB) Channel Priority is 3  */
#define   DMA_CHCTRLB_PRI_PRI_4_Val           _UINT32_(0x3)                                        /* (DMA_CHCTRLB) Channel Priority is 4 (HIGHEST)  */
#define DMA_CHCTRLB_PRI_PRI_1                 (DMA_CHCTRLB_PRI_PRI_1_Val << DMA_CHCTRLB_PRI_Pos)   /* (DMA_CHCTRLB) Channel Priority is 1 Position  */
#define DMA_CHCTRLB_PRI_PRI_2                 (DMA_CHCTRLB_PRI_PRI_2_Val << DMA_CHCTRLB_PRI_Pos)   /* (DMA_CHCTRLB) Channel Priority is 2 Position  */
#define DMA_CHCTRLB_PRI_PRI_3                 (DMA_CHCTRLB_PRI_PRI_3_Val << DMA_CHCTRLB_PRI_Pos)   /* (DMA_CHCTRLB) Channel Priority is 3 Position  */
#define DMA_CHCTRLB_PRI_PRI_4                 (DMA_CHCTRLB_PRI_PRI_4_Val << DMA_CHCTRLB_PRI_Pos)   /* (DMA_CHCTRLB) Channel Priority is 4 (HIGHEST) Position  */
#define DMA_CHCTRLB_WBOEN_Pos                 _UINT32_(13)                                         /* (DMA_CHCTRLB) Write Byte Order Enable Position */
#define DMA_CHCTRLB_WBOEN_Msk                 (_UINT32_(0x1) << DMA_CHCTRLB_WBOEN_Pos)             /* (DMA_CHCTRLB) Write Byte Order Enable Mask */
#define DMA_CHCTRLB_WBOEN(value)              (DMA_CHCTRLB_WBOEN_Msk & (_UINT32_(value) << DMA_CHCTRLB_WBOEN_Pos)) /* Assigment of value for WBOEN in the DMA_CHCTRLB register */
#define DMA_CHCTRLB_BYTORD_Pos                _UINT32_(14)                                         /* (DMA_CHCTRLB) Byte Order Position */
#define DMA_CHCTRLB_BYTORD_Msk                (_UINT32_(0x3) << DMA_CHCTRLB_BYTORD_Pos)            /* (DMA_CHCTRLB) Byte Order Mask */
#define DMA_CHCTRLB_BYTORD(value)             (DMA_CHCTRLB_BYTORD_Msk & (_UINT32_(value) << DMA_CHCTRLB_BYTORD_Pos)) /* Assigment of value for BYTORD in the DMA_CHCTRLB register */
#define   DMA_CHCTRLB_BYTORD_BYTORD_NONE_Val  _UINT32_(0x0)                                        /* (DMA_CHCTRLB) Bytes are processed AS IS  */
#define   DMA_CHCTRLB_BYTORD_BYTORD_WORD_SWIZZLE_Val _UINT32_(0x1)                                        /* (DMA_CHCTRLB) Bytes are swapped as: BYTE3 to BYTE0, BYTE2 to BYTE1, BYTE1 to BYTE2, and BYTE0 to BYTE3  */
#define   DMA_CHCTRLB_BYTORD_BYTORD_HALF_WORD_SWIZZLE_Val _UINT32_(0x2)                                        /* (DMA_CHCTRLB) Bytes are swapped as: BYTE3 to BYTE1, BYTE2 to BYTE0, BYTE1 to BYTE3, and BYTE0 to BYTE2  */
#define   DMA_CHCTRLB_BYTORD_BYTORD_BYTE_SWIZZLE_Val _UINT32_(0x3)                                        /* (DMA_CHCTRLB) Bytes are swapped as: BYTE3 to BYTE2, BYTE2 to BYTE3, BYTE1 to BYTE1, and BYTE0 to BYTE1  */
#define DMA_CHCTRLB_BYTORD_BYTORD_NONE        (DMA_CHCTRLB_BYTORD_BYTORD_NONE_Val << DMA_CHCTRLB_BYTORD_Pos) /* (DMA_CHCTRLB) Bytes are processed AS IS Position  */
#define DMA_CHCTRLB_BYTORD_BYTORD_WORD_SWIZZLE (DMA_CHCTRLB_BYTORD_BYTORD_WORD_SWIZZLE_Val << DMA_CHCTRLB_BYTORD_Pos) /* (DMA_CHCTRLB) Bytes are swapped as: BYTE3 to BYTE0, BYTE2 to BYTE1, BYTE1 to BYTE2, and BYTE0 to BYTE3 Position  */
#define DMA_CHCTRLB_BYTORD_BYTORD_HALF_WORD_SWIZZLE (DMA_CHCTRLB_BYTORD_BYTORD_HALF_WORD_SWIZZLE_Val << DMA_CHCTRLB_BYTORD_Pos) /* (DMA_CHCTRLB) Bytes are swapped as: BYTE3 to BYTE1, BYTE2 to BYTE0, BYTE1 to BYTE3, and BYTE0 to BYTE2 Position  */
#define DMA_CHCTRLB_BYTORD_BYTORD_BYTE_SWIZZLE (DMA_CHCTRLB_BYTORD_BYTORD_BYTE_SWIZZLE_Val << DMA_CHCTRLB_BYTORD_Pos) /* (DMA_CHCTRLB) Bytes are swapped as: BYTE3 to BYTE2, BYTE2 to BYTE3, BYTE1 to BYTE1, and BYTE0 to BYTE1 Position  */
#define DMA_CHCTRLB_TRIG_Pos                  _UINT32_(16)                                         /* (DMA_CHCTRLB) Trigger that can Start a Channel Transfer Position */
#define DMA_CHCTRLB_TRIG_Msk                  (_UINT32_(0xFF) << DMA_CHCTRLB_TRIG_Pos)             /* (DMA_CHCTRLB) Trigger that can Start a Channel Transfer Mask */
#define DMA_CHCTRLB_TRIG(value)               (DMA_CHCTRLB_TRIG_Msk & (_UINT32_(value) << DMA_CHCTRLB_TRIG_Pos)) /* Assigment of value for TRIG in the DMA_CHCTRLB register */
#define DMA_CHCTRLB_PIGNEN_Pos                _UINT32_(24)                                         /* (DMA_CHCTRLB) Enable Pattern Ignore Byte Position */
#define DMA_CHCTRLB_PIGNEN_Msk                (_UINT32_(0x1) << DMA_CHCTRLB_PIGNEN_Pos)            /* (DMA_CHCTRLB) Enable Pattern Ignore Byte Mask */
#define DMA_CHCTRLB_PIGNEN(value)             (DMA_CHCTRLB_PIGNEN_Msk & (_UINT32_(value) << DMA_CHCTRLB_PIGNEN_Pos)) /* Assigment of value for PIGNEN in the DMA_CHCTRLB register */
#define DMA_CHCTRLB_PATLEN_Pos                _UINT32_(25)                                         /* (DMA_CHCTRLB) Pattern Match Length Position */
#define DMA_CHCTRLB_PATLEN_Msk                (_UINT32_(0x1) << DMA_CHCTRLB_PATLEN_Pos)            /* (DMA_CHCTRLB) Pattern Match Length Mask */
#define DMA_CHCTRLB_PATLEN(value)             (DMA_CHCTRLB_PATLEN_Msk & (_UINT32_(value) << DMA_CHCTRLB_PATLEN_Pos)) /* Assigment of value for PATLEN in the DMA_CHCTRLB register */
#define DMA_CHCTRLB_PATEN_Pos                 _UINT32_(26)                                         /* (DMA_CHCTRLB) Channel Pattern Match Abort Enable. Position */
#define DMA_CHCTRLB_PATEN_Msk                 (_UINT32_(0x1) << DMA_CHCTRLB_PATEN_Pos)             /* (DMA_CHCTRLB) Channel Pattern Match Abort Enable. Mask */
#define DMA_CHCTRLB_PATEN(value)              (DMA_CHCTRLB_PATEN_Msk & (_UINT32_(value) << DMA_CHCTRLB_PATEN_Pos)) /* Assigment of value for PATEN in the DMA_CHCTRLB register */
#define DMA_CHCTRLB_CASTEN_Pos                _UINT32_(29)                                         /* (DMA_CHCTRLB) Cell Auto Start Enable of Ensuing Transfers for this channel Position */
#define DMA_CHCTRLB_CASTEN_Msk                (_UINT32_(0x1) << DMA_CHCTRLB_CASTEN_Pos)            /* (DMA_CHCTRLB) Cell Auto Start Enable of Ensuing Transfers for this channel Mask */
#define DMA_CHCTRLB_CASTEN(value)             (DMA_CHCTRLB_CASTEN_Msk & (_UINT32_(value) << DMA_CHCTRLB_CASTEN_Pos)) /* Assigment of value for CASTEN in the DMA_CHCTRLB register */
#define DMA_CHCTRLB_CRCEN_Pos                 _UINT32_(31)                                         /* (DMA_CHCTRLB) CRC Enable bit Position */
#define DMA_CHCTRLB_CRCEN_Msk                 (_UINT32_(0x1) << DMA_CHCTRLB_CRCEN_Pos)             /* (DMA_CHCTRLB) CRC Enable bit Mask */
#define DMA_CHCTRLB_CRCEN(value)              (DMA_CHCTRLB_CRCEN_Msk & (_UINT32_(value) << DMA_CHCTRLB_CRCEN_Pos)) /* Assigment of value for CRCEN in the DMA_CHCTRLB register */
#define DMA_CHCTRLB_Msk                       _UINT32_(0xA7FFE377)                                 /* (DMA_CHCTRLB) Register Mask  */


/* -------- DMA_CHEVCTRL : (DMA Offset: 0x08) (R/W 32) CHANNEL EVENT CONTROL REGISTER -------- */
#define DMA_CHEVCTRL_RESETVALUE               _UINT32_(0x00)                                       /*  (DMA_CHEVCTRL) CHANNEL EVENT CONTROL REGISTER  Reset Value */

#define DMA_CHEVCTRL_EVAUXACT_Pos             _UINT32_(0)                                          /* (DMA_CHEVCTRL) Channel Auxiliary Event Input Action Position */
#define DMA_CHEVCTRL_EVAUXACT_Msk             (_UINT32_(0x3) << DMA_CHEVCTRL_EVAUXACT_Pos)         /* (DMA_CHEVCTRL) Channel Auxiliary Event Input Action Mask */
#define DMA_CHEVCTRL_EVAUXACT(value)          (DMA_CHEVCTRL_EVAUXACT_Msk & (_UINT32_(value) << DMA_CHEVCTRL_EVAUXACT_Pos)) /* Assigment of value for EVAUXACT in the DMA_CHEVCTRL register */
#define   DMA_CHEVCTRL_EVAUXACT_ABORT_BLK_XFER_Val _UINT32_(0x0)                                        /* (DMA_CHEVCTRL) Event Aborts Bock Transfer  */
#define   DMA_CHEVCTRL_EVAUXACT_INCR_CHN_PRI_Val _UINT32_(0x1)                                        /* (DMA_CHEVCTRL) Event Increments Channel Priority  */
#define   DMA_CHEVCTRL_EVAUXACT_COND_TRIG_Val _UINT32_(0x2)                                        /* (DMA_CHEVCTRL) Event acts as a Conditional Trigger  */
#define DMA_CHEVCTRL_EVAUXACT_ABORT_BLK_XFER  (DMA_CHEVCTRL_EVAUXACT_ABORT_BLK_XFER_Val << DMA_CHEVCTRL_EVAUXACT_Pos) /* (DMA_CHEVCTRL) Event Aborts Bock Transfer Position  */
#define DMA_CHEVCTRL_EVAUXACT_INCR_CHN_PRI    (DMA_CHEVCTRL_EVAUXACT_INCR_CHN_PRI_Val << DMA_CHEVCTRL_EVAUXACT_Pos) /* (DMA_CHEVCTRL) Event Increments Channel Priority Position  */
#define DMA_CHEVCTRL_EVAUXACT_COND_TRIG       (DMA_CHEVCTRL_EVAUXACT_COND_TRIG_Val << DMA_CHEVCTRL_EVAUXACT_Pos) /* (DMA_CHEVCTRL) Event acts as a Conditional Trigger Position  */
#define DMA_CHEVCTRL_EVOMODE_Pos              _UINT32_(2)                                          /* (DMA_CHEVCTRL) Channel Event Output Mode Position */
#define DMA_CHEVCTRL_EVOMODE_Msk              (_UINT32_(0x3) << DMA_CHEVCTRL_EVOMODE_Pos)          /* (DMA_CHEVCTRL) Channel Event Output Mode Mask */
#define DMA_CHEVCTRL_EVOMODE(value)           (DMA_CHEVCTRL_EVOMODE_Msk & (_UINT32_(value) << DMA_CHEVCTRL_EVOMODE_Pos)) /* Assigment of value for EVOMODE in the DMA_CHEVCTRL register */
#define   DMA_CHEVCTRL_EVOMODE_STRB_ON_BLCK_XFER_Val _UINT32_(0x0)                                        /* (DMA_CHEVCTRL) Generate a channel event strobe for 1 clock cycle at the end of block transfer  */
#define   DMA_CHEVCTRL_EVOMODE_STRB_ON_CELL_XFER_Val _UINT32_(0x1)                                        /* (DMA_CHEVCTRL) Generate a channel event strobe for 1 clock cycle at the end of cell transfer  */
#define   DMA_CHEVCTRL_EVOMODE_STRB_START_EVT_TRG_TO_CELL_XFER_READ_Val _UINT32_(0x2)                                        /* (DMA_CHEVCTRL) Generate a channel event strobe from start event trigger to the completion of cell transfer read  */
#define   DMA_CHEVCTRL_EVOMODE_STRB_START_EVT_TRG_TO_CELL_XFER_WRITE_Val _UINT32_(0x3)                                        /* (DMA_CHEVCTRL) Generate a channel event strobe from start event trigger to the completion of cell transfer write  */
#define DMA_CHEVCTRL_EVOMODE_STRB_ON_BLCK_XFER (DMA_CHEVCTRL_EVOMODE_STRB_ON_BLCK_XFER_Val << DMA_CHEVCTRL_EVOMODE_Pos) /* (DMA_CHEVCTRL) Generate a channel event strobe for 1 clock cycle at the end of block transfer Position  */
#define DMA_CHEVCTRL_EVOMODE_STRB_ON_CELL_XFER (DMA_CHEVCTRL_EVOMODE_STRB_ON_CELL_XFER_Val << DMA_CHEVCTRL_EVOMODE_Pos) /* (DMA_CHEVCTRL) Generate a channel event strobe for 1 clock cycle at the end of cell transfer Position  */
#define DMA_CHEVCTRL_EVOMODE_STRB_START_EVT_TRG_TO_CELL_XFER_READ (DMA_CHEVCTRL_EVOMODE_STRB_START_EVT_TRG_TO_CELL_XFER_READ_Val << DMA_CHEVCTRL_EVOMODE_Pos) /* (DMA_CHEVCTRL) Generate a channel event strobe from start event trigger to the completion of cell transfer read Position  */
#define DMA_CHEVCTRL_EVOMODE_STRB_START_EVT_TRG_TO_CELL_XFER_WRITE (DMA_CHEVCTRL_EVOMODE_STRB_START_EVT_TRG_TO_CELL_XFER_WRITE_Val << DMA_CHEVCTRL_EVOMODE_Pos) /* (DMA_CHEVCTRL) Generate a channel event strobe from start event trigger to the completion of cell transfer write Position  */
#define DMA_CHEVCTRL_EVAUXIE_Pos              _UINT32_(5)                                          /* (DMA_CHEVCTRL) Channel Auxiliary Event Enable (0: disable; 1: enable) Position */
#define DMA_CHEVCTRL_EVAUXIE_Msk              (_UINT32_(0x1) << DMA_CHEVCTRL_EVAUXIE_Pos)          /* (DMA_CHEVCTRL) Channel Auxiliary Event Enable (0: disable; 1: enable) Mask */
#define DMA_CHEVCTRL_EVAUXIE(value)           (DMA_CHEVCTRL_EVAUXIE_Msk & (_UINT32_(value) << DMA_CHEVCTRL_EVAUXIE_Pos)) /* Assigment of value for EVAUXIE in the DMA_CHEVCTRL register */
#define DMA_CHEVCTRL_EVSTRIE_Pos              _UINT32_(6)                                          /* (DMA_CHEVCTRL) Channel Start Event Input Enable (0: disable; 1:enable) Position */
#define DMA_CHEVCTRL_EVSTRIE_Msk              (_UINT32_(0x1) << DMA_CHEVCTRL_EVSTRIE_Pos)          /* (DMA_CHEVCTRL) Channel Start Event Input Enable (0: disable; 1:enable) Mask */
#define DMA_CHEVCTRL_EVSTRIE(value)           (DMA_CHEVCTRL_EVSTRIE_Msk & (_UINT32_(value) << DMA_CHEVCTRL_EVSTRIE_Pos)) /* Assigment of value for EVSTRIE in the DMA_CHEVCTRL register */
#define DMA_CHEVCTRL_EVOE_Pos                 _UINT32_(7)                                          /* (DMA_CHEVCTRL) Channel Event Output Enable (0: disable; 1: enable) Position */
#define DMA_CHEVCTRL_EVOE_Msk                 (_UINT32_(0x1) << DMA_CHEVCTRL_EVOE_Pos)             /* (DMA_CHEVCTRL) Channel Event Output Enable (0: disable; 1: enable) Mask */
#define DMA_CHEVCTRL_EVOE(value)              (DMA_CHEVCTRL_EVOE_Msk & (_UINT32_(value) << DMA_CHEVCTRL_EVOE_Pos)) /* Assigment of value for EVOE in the DMA_CHEVCTRL register */
#define DMA_CHEVCTRL_Msk                      _UINT32_(0x000000EF)                                 /* (DMA_CHEVCTRL) Register Mask  */


/* -------- DMA_CHINTENCLR : (DMA Offset: 0x0C) (R/W 32) CHANNEL INTERRUPT ENABLE CLEAR REGISTER -------- */
#define DMA_CHINTENCLR_RESETVALUE             _UINT32_(0x00)                                       /*  (DMA_CHINTENCLR) CHANNEL INTERRUPT ENABLE CLEAR REGISTER  Reset Value */

#define DMA_CHINTENCLR_SD_Pos                 _UINT32_(0)                                          /* (DMA_CHINTENCLR) Channel Event Output Enable Position */
#define DMA_CHINTENCLR_SD_Msk                 (_UINT32_(0x1) << DMA_CHINTENCLR_SD_Pos)             /* (DMA_CHINTENCLR) Channel Event Output Enable Mask */
#define DMA_CHINTENCLR_SD(value)              (DMA_CHINTENCLR_SD_Msk & (_UINT32_(value) << DMA_CHINTENCLR_SD_Pos)) /* Assigment of value for SD in the DMA_CHINTENCLR register */
#define DMA_CHINTENCLR_TA_Pos                 _UINT32_(1)                                          /* (DMA_CHINTENCLR) Clear Transfer Abort Interrupt Enable Position */
#define DMA_CHINTENCLR_TA_Msk                 (_UINT32_(0x1) << DMA_CHINTENCLR_TA_Pos)             /* (DMA_CHINTENCLR) Clear Transfer Abort Interrupt Enable Mask */
#define DMA_CHINTENCLR_TA(value)              (DMA_CHINTENCLR_TA_Msk & (_UINT32_(value) << DMA_CHINTENCLR_TA_Pos)) /* Assigment of value for TA in the DMA_CHINTENCLR register */
#define DMA_CHINTENCLR_CC_Pos                 _UINT32_(2)                                          /* (DMA_CHINTENCLR) Clear Cell Transfer Complete Interrupt Enable Position */
#define DMA_CHINTENCLR_CC_Msk                 (_UINT32_(0x1) << DMA_CHINTENCLR_CC_Pos)             /* (DMA_CHINTENCLR) Clear Cell Transfer Complete Interrupt Enable Mask */
#define DMA_CHINTENCLR_CC(value)              (DMA_CHINTENCLR_CC_Msk & (_UINT32_(value) << DMA_CHINTENCLR_CC_Pos)) /* Assigment of value for CC in the DMA_CHINTENCLR register */
#define DMA_CHINTENCLR_BC_Pos                 _UINT32_(3)                                          /* (DMA_CHINTENCLR) Clear Cell Transfer Complete Interrupt Enable Position */
#define DMA_CHINTENCLR_BC_Msk                 (_UINT32_(0x1) << DMA_CHINTENCLR_BC_Pos)             /* (DMA_CHINTENCLR) Clear Cell Transfer Complete Interrupt Enable Mask */
#define DMA_CHINTENCLR_BC(value)              (DMA_CHINTENCLR_BC_Msk & (_UINT32_(value) << DMA_CHINTENCLR_BC_Pos)) /* Assigment of value for BC in the DMA_CHINTENCLR register */
#define DMA_CHINTENCLR_BH_Pos                 _UINT32_(4)                                          /* (DMA_CHINTENCLR) Clear Block Transfer Half Complete Interrupt Enable Position */
#define DMA_CHINTENCLR_BH_Msk                 (_UINT32_(0x1) << DMA_CHINTENCLR_BH_Pos)             /* (DMA_CHINTENCLR) Clear Block Transfer Half Complete Interrupt Enable Mask */
#define DMA_CHINTENCLR_BH(value)              (DMA_CHINTENCLR_BH_Msk & (_UINT32_(value) << DMA_CHINTENCLR_BH_Pos)) /* Assigment of value for BH in the DMA_CHINTENCLR register */
#define DMA_CHINTENCLR_LL_Pos                 _UINT32_(5)                                          /* (DMA_CHINTENCLR) Clear Linked List Done Interrupt Enable Position */
#define DMA_CHINTENCLR_LL_Msk                 (_UINT32_(0x1) << DMA_CHINTENCLR_LL_Pos)             /* (DMA_CHINTENCLR) Clear Linked List Done Interrupt Enable Mask */
#define DMA_CHINTENCLR_LL(value)              (DMA_CHINTENCLR_LL_Msk & (_UINT32_(value) << DMA_CHINTENCLR_LL_Pos)) /* Assigment of value for LL in the DMA_CHINTENCLR register */
#define DMA_CHINTENCLR_Msk                    _UINT32_(0x0000003F)                                 /* (DMA_CHINTENCLR) Register Mask  */


/* -------- DMA_CHINTENSET : (DMA Offset: 0x10) (R/W 32) CHANNEL INTERRUPT ENABLE SET REGISTER -------- */
#define DMA_CHINTENSET_RESETVALUE             _UINT32_(0x00)                                       /*  (DMA_CHINTENSET) CHANNEL INTERRUPT ENABLE SET REGISTER  Reset Value */

#define DMA_CHINTENSET_SD_Pos                 _UINT32_(0)                                          /* (DMA_CHINTENSET) Channel Event Output Enable Position */
#define DMA_CHINTENSET_SD_Msk                 (_UINT32_(0x1) << DMA_CHINTENSET_SD_Pos)             /* (DMA_CHINTENSET) Channel Event Output Enable Mask */
#define DMA_CHINTENSET_SD(value)              (DMA_CHINTENSET_SD_Msk & (_UINT32_(value) << DMA_CHINTENSET_SD_Pos)) /* Assigment of value for SD in the DMA_CHINTENSET register */
#define DMA_CHINTENSET_TA_Pos                 _UINT32_(1)                                          /* (DMA_CHINTENSET) Set Transfer Abort Interrupt Enable Position */
#define DMA_CHINTENSET_TA_Msk                 (_UINT32_(0x1) << DMA_CHINTENSET_TA_Pos)             /* (DMA_CHINTENSET) Set Transfer Abort Interrupt Enable Mask */
#define DMA_CHINTENSET_TA(value)              (DMA_CHINTENSET_TA_Msk & (_UINT32_(value) << DMA_CHINTENSET_TA_Pos)) /* Assigment of value for TA in the DMA_CHINTENSET register */
#define DMA_CHINTENSET_CC_Pos                 _UINT32_(2)                                          /* (DMA_CHINTENSET) set Cell Transfer Complete Interrupt Enable Position */
#define DMA_CHINTENSET_CC_Msk                 (_UINT32_(0x1) << DMA_CHINTENSET_CC_Pos)             /* (DMA_CHINTENSET) set Cell Transfer Complete Interrupt Enable Mask */
#define DMA_CHINTENSET_CC(value)              (DMA_CHINTENSET_CC_Msk & (_UINT32_(value) << DMA_CHINTENSET_CC_Pos)) /* Assigment of value for CC in the DMA_CHINTENSET register */
#define DMA_CHINTENSET_BC_Pos                 _UINT32_(3)                                          /* (DMA_CHINTENSET) set Cell Transfer Complete Interrupt Enable Position */
#define DMA_CHINTENSET_BC_Msk                 (_UINT32_(0x1) << DMA_CHINTENSET_BC_Pos)             /* (DMA_CHINTENSET) set Cell Transfer Complete Interrupt Enable Mask */
#define DMA_CHINTENSET_BC(value)              (DMA_CHINTENSET_BC_Msk & (_UINT32_(value) << DMA_CHINTENSET_BC_Pos)) /* Assigment of value for BC in the DMA_CHINTENSET register */
#define DMA_CHINTENSET_BH_Pos                 _UINT32_(4)                                          /* (DMA_CHINTENSET) set Block Transfer Half Complete Interrupt Enable Position */
#define DMA_CHINTENSET_BH_Msk                 (_UINT32_(0x1) << DMA_CHINTENSET_BH_Pos)             /* (DMA_CHINTENSET) set Block Transfer Half Complete Interrupt Enable Mask */
#define DMA_CHINTENSET_BH(value)              (DMA_CHINTENSET_BH_Msk & (_UINT32_(value) << DMA_CHINTENSET_BH_Pos)) /* Assigment of value for BH in the DMA_CHINTENSET register */
#define DMA_CHINTENSET_LL_Pos                 _UINT32_(5)                                          /* (DMA_CHINTENSET) set Linked List Done Interrupt Enable Position */
#define DMA_CHINTENSET_LL_Msk                 (_UINT32_(0x1) << DMA_CHINTENSET_LL_Pos)             /* (DMA_CHINTENSET) set Linked List Done Interrupt Enable Mask */
#define DMA_CHINTENSET_LL(value)              (DMA_CHINTENSET_LL_Msk & (_UINT32_(value) << DMA_CHINTENSET_LL_Pos)) /* Assigment of value for LL in the DMA_CHINTENSET register */
#define DMA_CHINTENSET_Msk                    _UINT32_(0x0000003F)                                 /* (DMA_CHINTENSET) Register Mask  */


/* -------- DMA_CHINTF : (DMA Offset: 0x14) (R/W 32) CHANNEL INTERRUPT FLAG REGISTER -------- */
#define DMA_CHINTF_RESETVALUE                 _UINT32_(0x00)                                       /*  (DMA_CHINTF) CHANNEL INTERRUPT FLAG REGISTER  Reset Value */

#define DMA_CHINTF_SD_Pos                     _UINT32_(0)                                          /* (DMA_CHINTF) Start Detected Interrupt Flag (0: none ; 1: Start Detected) Position */
#define DMA_CHINTF_SD_Msk                     (_UINT32_(0x1) << DMA_CHINTF_SD_Pos)                 /* (DMA_CHINTF) Start Detected Interrupt Flag (0: none ; 1: Start Detected) Mask */
#define DMA_CHINTF_SD(value)                  (DMA_CHINTF_SD_Msk & (_UINT32_(value) << DMA_CHINTF_SD_Pos)) /* Assigment of value for SD in the DMA_CHINTF register */
#define DMA_CHINTF_TA_Pos                     _UINT32_(1)                                          /* (DMA_CHINTF) Transfer Abort Interrupt Flag (0: none; 1: Transfer Aborted) Position */
#define DMA_CHINTF_TA_Msk                     (_UINT32_(0x1) << DMA_CHINTF_TA_Pos)                 /* (DMA_CHINTF) Transfer Abort Interrupt Flag (0: none; 1: Transfer Aborted) Mask */
#define DMA_CHINTF_TA(value)                  (DMA_CHINTF_TA_Msk & (_UINT32_(value) << DMA_CHINTF_TA_Pos)) /* Assigment of value for TA in the DMA_CHINTF register */
#define DMA_CHINTF_CC_Pos                     _UINT32_(2)                                          /* (DMA_CHINTF) Cell Transfer Complete Interrupt Flag (0: none ; 1: complete) Position */
#define DMA_CHINTF_CC_Msk                     (_UINT32_(0x1) << DMA_CHINTF_CC_Pos)                 /* (DMA_CHINTF) Cell Transfer Complete Interrupt Flag (0: none ; 1: complete) Mask */
#define DMA_CHINTF_CC(value)                  (DMA_CHINTF_CC_Msk & (_UINT32_(value) << DMA_CHINTF_CC_Pos)) /* Assigment of value for CC in the DMA_CHINTF register */
#define DMA_CHINTF_BC_Pos                     _UINT32_(3)                                          /* (DMA_CHINTF) Block Transfer Complete Interrupt Flag (0: none; 1:complete;) Position */
#define DMA_CHINTF_BC_Msk                     (_UINT32_(0x1) << DMA_CHINTF_BC_Pos)                 /* (DMA_CHINTF) Block Transfer Complete Interrupt Flag (0: none; 1:complete;) Mask */
#define DMA_CHINTF_BC(value)                  (DMA_CHINTF_BC_Msk & (_UINT32_(value) << DMA_CHINTF_BC_Pos)) /* Assigment of value for BC in the DMA_CHINTF register */
#define DMA_CHINTF_BH_Pos                     _UINT32_(4)                                          /* (DMA_CHINTF) Block Transfer Half Complete Interrupt Flag (0: none; 1: half complete) Position */
#define DMA_CHINTF_BH_Msk                     (_UINT32_(0x1) << DMA_CHINTF_BH_Pos)                 /* (DMA_CHINTF) Block Transfer Half Complete Interrupt Flag (0: none; 1: half complete) Mask */
#define DMA_CHINTF_BH(value)                  (DMA_CHINTF_BH_Msk & (_UINT32_(value) << DMA_CHINTF_BH_Pos)) /* Assigment of value for BH in the DMA_CHINTF register */
#define DMA_CHINTF_LL_Pos                     _UINT32_(5)                                          /* (DMA_CHINTF) Linked List Done Interrupt Flag (0: none; 1: done) Position */
#define DMA_CHINTF_LL_Msk                     (_UINT32_(0x1) << DMA_CHINTF_LL_Pos)                 /* (DMA_CHINTF) Linked List Done Interrupt Flag (0: none; 1: done) Mask */
#define DMA_CHINTF_LL(value)                  (DMA_CHINTF_LL_Msk & (_UINT32_(value) << DMA_CHINTF_LL_Pos)) /* Assigment of value for LL in the DMA_CHINTF register */
#define DMA_CHINTF_WRE_Pos                    _UINT32_(17)                                         /* (DMA_CHINTF) Write Error Flag (0: none; 1: Write Error) Position */
#define DMA_CHINTF_WRE_Msk                    (_UINT32_(0x1) << DMA_CHINTF_WRE_Pos)                /* (DMA_CHINTF) Write Error Flag (0: none; 1: Write Error) Mask */
#define DMA_CHINTF_WRE(value)                 (DMA_CHINTF_WRE_Msk & (_UINT32_(value) << DMA_CHINTF_WRE_Pos)) /* Assigment of value for WRE in the DMA_CHINTF register */
#define DMA_CHINTF_RDE_Pos                    _UINT32_(18)                                         /* (DMA_CHINTF) Read Error Flag (0: none; 1: Read Error) Position */
#define DMA_CHINTF_RDE_Msk                    (_UINT32_(0x1) << DMA_CHINTF_RDE_Pos)                /* (DMA_CHINTF) Read Error Flag (0: none; 1: Read Error) Mask */
#define DMA_CHINTF_RDE(value)                 (DMA_CHINTF_RDE_Msk & (_UINT32_(value) << DMA_CHINTF_RDE_Pos)) /* Assigment of value for RDE in the DMA_CHINTF register */
#define DMA_CHINTF_Msk                        _UINT32_(0x0006003F)                                 /* (DMA_CHINTF) Register Mask  */


/* -------- DMA_CHSSA : (DMA Offset: 0x18) (R/W 32) CHANNEL SOURCE START ADDRESS -------- */
#define DMA_CHSSA_RESETVALUE                  _UINT32_(0x00)                                       /*  (DMA_CHSSA) CHANNEL SOURCE START ADDRESS  Reset Value */

#define DMA_CHSSA_SSA_Pos                     _UINT32_(0)                                          /* (DMA_CHSSA) Channel Source Start Address Position */
#define DMA_CHSSA_SSA_Msk                     (_UINT32_(0xFFFFFFFF) << DMA_CHSSA_SSA_Pos)          /* (DMA_CHSSA) Channel Source Start Address Mask */
#define DMA_CHSSA_SSA(value)                  (DMA_CHSSA_SSA_Msk & (_UINT32_(value) << DMA_CHSSA_SSA_Pos)) /* Assigment of value for SSA in the DMA_CHSSA register */
#define DMA_CHSSA_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (DMA_CHSSA) Register Mask  */


/* -------- DMA_CHDSA : (DMA Offset: 0x1C) (R/W 32) CHANNEL DESTINATION START ADDRESS -------- */
#define DMA_CHDSA_RESETVALUE                  _UINT32_(0x00)                                       /*  (DMA_CHDSA) CHANNEL DESTINATION START ADDRESS  Reset Value */

#define DMA_CHDSA_DSA_Pos                     _UINT32_(0)                                          /* (DMA_CHDSA) Channel Destination Start Address Position */
#define DMA_CHDSA_DSA_Msk                     (_UINT32_(0xFFFFFFFF) << DMA_CHDSA_DSA_Pos)          /* (DMA_CHDSA) Channel Destination Start Address Mask */
#define DMA_CHDSA_DSA(value)                  (DMA_CHDSA_DSA_Msk & (_UINT32_(value) << DMA_CHDSA_DSA_Pos)) /* Assigment of value for DSA in the DMA_CHDSA register */
#define DMA_CHDSA_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (DMA_CHDSA) Register Mask  */


/* -------- DMA_CHSSTRD : (DMA Offset: 0x20) (R/W 32) CHANNEL SOURCE CELL STRIDE SIZE REGISTER -------- */
#define DMA_CHSSTRD_RESETVALUE                _UINT32_(0x00)                                       /*  (DMA_CHSSTRD) CHANNEL SOURCE CELL STRIDE SIZE REGISTER  Reset Value */

#define DMA_CHSSTRD_SSTRD_Pos                 _UINT32_(0)                                          /* (DMA_CHSSTRD) Source Cell Stride Size Position */
#define DMA_CHSSTRD_SSTRD_Msk                 (_UINT32_(0xFFFF) << DMA_CHSSTRD_SSTRD_Pos)          /* (DMA_CHSSTRD) Source Cell Stride Size Mask */
#define DMA_CHSSTRD_SSTRD(value)              (DMA_CHSSTRD_SSTRD_Msk & (_UINT32_(value) << DMA_CHSSTRD_SSTRD_Pos)) /* Assigment of value for SSTRD in the DMA_CHSSTRD register */
#define DMA_CHSSTRD_Msk                       _UINT32_(0x0000FFFF)                                 /* (DMA_CHSSTRD) Register Mask  */


/* -------- DMA_CHDSTRD : (DMA Offset: 0x24) (R/W 32) CHANNEL DESTINATION CELL STRIDE SIZE REGISTER -------- */
#define DMA_CHDSTRD_RESETVALUE                _UINT32_(0x00)                                       /*  (DMA_CHDSTRD) CHANNEL DESTINATION CELL STRIDE SIZE REGISTER  Reset Value */

#define DMA_CHDSTRD_DSTRD_Pos                 _UINT32_(0)                                          /* (DMA_CHDSTRD) Destination Cell Stride Size Position */
#define DMA_CHDSTRD_DSTRD_Msk                 (_UINT32_(0xFFFF) << DMA_CHDSTRD_DSTRD_Pos)          /* (DMA_CHDSTRD) Destination Cell Stride Size Mask */
#define DMA_CHDSTRD_DSTRD(value)              (DMA_CHDSTRD_DSTRD_Msk & (_UINT32_(value) << DMA_CHDSTRD_DSTRD_Pos)) /* Assigment of value for DSTRD in the DMA_CHDSTRD register */
#define DMA_CHDSTRD_Msk                       _UINT32_(0x0000FFFF)                                 /* (DMA_CHDSTRD) Register Mask  */


/* -------- DMA_CHXSIZ : (DMA Offset: 0x28) (R/W 32) CHANNEL TRANSFER SIZE REGISTER -------- */
#define DMA_CHXSIZ_RESETVALUE                 _UINT32_(0x00)                                       /*  (DMA_CHXSIZ) CHANNEL TRANSFER SIZE REGISTER  Reset Value */

#define DMA_CHXSIZ_CSZ_Pos                    _UINT32_(0)                                          /* (DMA_CHXSIZ) Cell transfer size in bytes. Position */
#define DMA_CHXSIZ_CSZ_Msk                    (_UINT32_(0x3FF) << DMA_CHXSIZ_CSZ_Pos)              /* (DMA_CHXSIZ) Cell transfer size in bytes. Mask */
#define DMA_CHXSIZ_CSZ(value)                 (DMA_CHXSIZ_CSZ_Msk & (_UINT32_(value) << DMA_CHXSIZ_CSZ_Pos)) /* Assigment of value for CSZ in the DMA_CHXSIZ register */
#define DMA_CHXSIZ_BLKSZ_Pos                  _UINT32_(16)                                         /* (DMA_CHXSIZ) Block transfer size in bytes. Position */
#define DMA_CHXSIZ_BLKSZ_Msk                  (_UINT32_(0xFFFF) << DMA_CHXSIZ_BLKSZ_Pos)           /* (DMA_CHXSIZ) Block transfer size in bytes. Mask */
#define DMA_CHXSIZ_BLKSZ(value)               (DMA_CHXSIZ_BLKSZ_Msk & (_UINT32_(value) << DMA_CHXSIZ_BLKSZ_Pos)) /* Assigment of value for BLKSZ in the DMA_CHXSIZ register */
#define DMA_CHXSIZ_Msk                        _UINT32_(0xFFFF03FF)                                 /* (DMA_CHXSIZ) Register Mask  */


/* -------- DMA_CHPDAT : (DMA Offset: 0x2C) (R/W 32) CHANNEL PATTERN MATCH DATA -------- */
#define DMA_CHPDAT_RESETVALUE                 _UINT32_(0x00)                                       /*  (DMA_CHPDAT) CHANNEL PATTERN MATCH DATA  Reset Value */

#define DMA_CHPDAT_PDAT_Pos                   _UINT32_(0)                                          /* (DMA_CHPDAT) Channel Pattern Match Data Position */
#define DMA_CHPDAT_PDAT_Msk                   (_UINT32_(0xFFFF) << DMA_CHPDAT_PDAT_Pos)            /* (DMA_CHPDAT) Channel Pattern Match Data Mask */
#define DMA_CHPDAT_PDAT(value)                (DMA_CHPDAT_PDAT_Msk & (_UINT32_(value) << DMA_CHPDAT_PDAT_Pos)) /* Assigment of value for PDAT in the DMA_CHPDAT register */
#define DMA_CHPDAT_PIGN_Pos                   _UINT32_(24)                                         /* (DMA_CHPDAT) Channel Pattern Ignore Value Position */
#define DMA_CHPDAT_PIGN_Msk                   (_UINT32_(0xFF) << DMA_CHPDAT_PIGN_Pos)              /* (DMA_CHPDAT) Channel Pattern Ignore Value Mask */
#define DMA_CHPDAT_PIGN(value)                (DMA_CHPDAT_PIGN_Msk & (_UINT32_(value) << DMA_CHPDAT_PIGN_Pos)) /* Assigment of value for PIGN in the DMA_CHPDAT register */
#define DMA_CHPDAT_Msk                        _UINT32_(0xFF00FFFF)                                 /* (DMA_CHPDAT) Register Mask  */


/* -------- DMA_CHCTRLCRC : (DMA Offset: 0x30) (R/W 32) CHANNEL CONTROL CRC -------- */
#define DMA_CHCTRLCRC_RESETVALUE              _UINT32_(0x00)                                       /*  (DMA_CHCTRLCRC) CHANNEL CONTROL CRC  Reset Value */

#define DMA_CHCTRLCRC_CRCMD_Pos               _UINT32_(0)                                          /* (DMA_CHCTRLCRC) CRC/Checksum Mode Position */
#define DMA_CHCTRLCRC_CRCMD_Msk               (_UINT32_(0x7) << DMA_CHCTRLCRC_CRCMD_Pos)           /* (DMA_CHCTRLCRC) CRC/Checksum Mode Mask */
#define DMA_CHCTRLCRC_CRCMD(value)            (DMA_CHCTRLCRC_CRCMD_Msk & (_UINT32_(value) << DMA_CHCTRLCRC_CRCMD_Pos)) /* Assigment of value for CRCMD in the DMA_CHCTRLCRC register */
#define   DMA_CHCTRLCRC_CRCMD_CRC_16_Val      _UINT32_(0x0)                                        /* (DMA_CHCTRLCRC) Normal (0x8005) CRC-16/CRC-16-IBM/CRC-16-ANSI  */
#define   DMA_CHCTRLCRC_CRCMD_CRC_16_CCITT_Val _UINT32_(0x1)                                        /* (DMA_CHCTRLCRC) Normal (0x1021) CRC-16-CCITT  */
#define   DMA_CHCTRLCRC_CRCMD_16_BIT_CRCPOLYA_Val _UINT32_(0x2)                                        /* (DMA_CHCTRLCRC) CRC-16 based on polynomial provided in CRCPOLYA (POLYA[15:0]) register  */
#define   DMA_CHCTRLCRC_CRCMD_16_BIT_CRCPOLYB_Val _UINT32_(0x3)                                        /* (DMA_CHCTRLCRC) CRC-16 based on polynomial provided in CRCPOLYB (POLYB[15:0]) register  */
#define   DMA_CHCTRLCRC_CRCMD_CRC_32_Val      _UINT32_(0x4)                                        /* (DMA_CHCTRLCRC) Normal (0x04C11DB7) CRC-32  */
#define   DMA_CHCTRLCRC_CRCMD_32_BIT_CRCPOLYA_Val _UINT32_(0x5)                                        /* (DMA_CHCTRLCRC) CRC-32 based on polynomial provided in CRCPOLYA register  */
#define   DMA_CHCTRLCRC_CRCMD_32_BIT_CRCPOLYB_Val _UINT32_(0x6)                                        /* (DMA_CHCTRLCRC) CRC-32 based on polynomial provided in CRCPOLYB register  */
#define   DMA_CHCTRLCRC_CRCMD_IP_HDR_CHECKSUM_Val _UINT32_(0x7)                                        /* (DMA_CHCTRLCRC) Calculate IP header checksum  */
#define DMA_CHCTRLCRC_CRCMD_CRC_16            (DMA_CHCTRLCRC_CRCMD_CRC_16_Val << DMA_CHCTRLCRC_CRCMD_Pos) /* (DMA_CHCTRLCRC) Normal (0x8005) CRC-16/CRC-16-IBM/CRC-16-ANSI Position  */
#define DMA_CHCTRLCRC_CRCMD_CRC_16_CCITT      (DMA_CHCTRLCRC_CRCMD_CRC_16_CCITT_Val << DMA_CHCTRLCRC_CRCMD_Pos) /* (DMA_CHCTRLCRC) Normal (0x1021) CRC-16-CCITT Position  */
#define DMA_CHCTRLCRC_CRCMD_16_BIT_CRCPOLYA   (DMA_CHCTRLCRC_CRCMD_16_BIT_CRCPOLYA_Val << DMA_CHCTRLCRC_CRCMD_Pos) /* (DMA_CHCTRLCRC) CRC-16 based on polynomial provided in CRCPOLYA (POLYA[15:0]) register Position  */
#define DMA_CHCTRLCRC_CRCMD_16_BIT_CRCPOLYB   (DMA_CHCTRLCRC_CRCMD_16_BIT_CRCPOLYB_Val << DMA_CHCTRLCRC_CRCMD_Pos) /* (DMA_CHCTRLCRC) CRC-16 based on polynomial provided in CRCPOLYB (POLYB[15:0]) register Position  */
#define DMA_CHCTRLCRC_CRCMD_CRC_32            (DMA_CHCTRLCRC_CRCMD_CRC_32_Val << DMA_CHCTRLCRC_CRCMD_Pos) /* (DMA_CHCTRLCRC) Normal (0x04C11DB7) CRC-32 Position  */
#define DMA_CHCTRLCRC_CRCMD_32_BIT_CRCPOLYA   (DMA_CHCTRLCRC_CRCMD_32_BIT_CRCPOLYA_Val << DMA_CHCTRLCRC_CRCMD_Pos) /* (DMA_CHCTRLCRC) CRC-32 based on polynomial provided in CRCPOLYA register Position  */
#define DMA_CHCTRLCRC_CRCMD_32_BIT_CRCPOLYB   (DMA_CHCTRLCRC_CRCMD_32_BIT_CRCPOLYB_Val << DMA_CHCTRLCRC_CRCMD_Pos) /* (DMA_CHCTRLCRC) CRC-32 based on polynomial provided in CRCPOLYB register Position  */
#define DMA_CHCTRLCRC_CRCMD_IP_HDR_CHECKSUM   (DMA_CHCTRLCRC_CRCMD_IP_HDR_CHECKSUM_Val << DMA_CHCTRLCRC_CRCMD_Pos) /* (DMA_CHCTRLCRC) Calculate IP header checksum Position  */
#define DMA_CHCTRLCRC_CRCAPP_Pos              _UINT32_(3)                                          /* (DMA_CHCTRLCRC) CRC Append Mode Position */
#define DMA_CHCTRLCRC_CRCAPP_Msk              (_UINT32_(0x1) << DMA_CHCTRLCRC_CRCAPP_Pos)          /* (DMA_CHCTRLCRC) CRC Append Mode Mask */
#define DMA_CHCTRLCRC_CRCAPP(value)           (DMA_CHCTRLCRC_CRCAPP_Msk & (_UINT32_(value) << DMA_CHCTRLCRC_CRCAPP_Pos)) /* Assigment of value for CRCAPP in the DMA_CHCTRLCRC register */
#define DMA_CHCTRLCRC_CRCXOR_Pos              _UINT32_(5)                                          /* (DMA_CHCTRLCRC) CRC XOR Mode Position */
#define DMA_CHCTRLCRC_CRCXOR_Msk              (_UINT32_(0x1) << DMA_CHCTRLCRC_CRCXOR_Pos)          /* (DMA_CHCTRLCRC) CRC XOR Mode Mask */
#define DMA_CHCTRLCRC_CRCXOR(value)           (DMA_CHCTRLCRC_CRCXOR_Msk & (_UINT32_(value) << DMA_CHCTRLCRC_CRCXOR_Pos)) /* Assigment of value for CRCXOR in the DMA_CHCTRLCRC register */
#define DMA_CHCTRLCRC_CRCROUT_Pos             _UINT32_(6)                                          /* (DMA_CHCTRLCRC) CRC Reflected Output Mode Position */
#define DMA_CHCTRLCRC_CRCROUT_Msk             (_UINT32_(0x1) << DMA_CHCTRLCRC_CRCROUT_Pos)         /* (DMA_CHCTRLCRC) CRC Reflected Output Mode Mask */
#define DMA_CHCTRLCRC_CRCROUT(value)          (DMA_CHCTRLCRC_CRCROUT_Msk & (_UINT32_(value) << DMA_CHCTRLCRC_CRCROUT_Pos)) /* Assigment of value for CRCROUT in the DMA_CHCTRLCRC register */
#define DMA_CHCTRLCRC_CRCRIN_Pos              _UINT32_(7)                                          /* (DMA_CHCTRLCRC) CRC Reflect Input Selection Position */
#define DMA_CHCTRLCRC_CRCRIN_Msk              (_UINT32_(0x1) << DMA_CHCTRLCRC_CRCRIN_Pos)          /* (DMA_CHCTRLCRC) CRC Reflect Input Selection Mask */
#define DMA_CHCTRLCRC_CRCRIN(value)           (DMA_CHCTRLCRC_CRCRIN_Msk & (_UINT32_(value) << DMA_CHCTRLCRC_CRCRIN_Pos)) /* Assigment of value for CRCRIN in the DMA_CHCTRLCRC register */
#define DMA_CHCTRLCRC_Msk                     _UINT32_(0x000000EF)                                 /* (DMA_CHCTRLCRC) Register Mask  */


/* -------- DMA_CHCRCDAT : (DMA Offset: 0x34) (R/W 32) CHANNEL CRC/CHECKSUM DATA REGISTER -------- */
#define DMA_CHCRCDAT_RESETVALUE               _UINT32_(0x00)                                       /*  (DMA_CHCRCDAT) CHANNEL CRC/CHECKSUM DATA REGISTER  Reset Value */

#define DMA_CHCRCDAT_CRCDAT_Pos               _UINT32_(0)                                          /* (DMA_CHCRCDAT) CRC Data Position */
#define DMA_CHCRCDAT_CRCDAT_Msk               (_UINT32_(0xFFFFFFFF) << DMA_CHCRCDAT_CRCDAT_Pos)    /* (DMA_CHCRCDAT) CRC Data Mask */
#define DMA_CHCRCDAT_CRCDAT(value)            (DMA_CHCRCDAT_CRCDAT_Msk & (_UINT32_(value) << DMA_CHCRCDAT_CRCDAT_Pos)) /* Assigment of value for CRCDAT in the DMA_CHCRCDAT register */
#define DMA_CHCRCDAT_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (DMA_CHCRCDAT) Register Mask  */


/* -------- DMA_CHNXT : (DMA Offset: 0x38) (R/W 32) CHANNEL NEXT DESCRIPTOR ADDRESS POINTER -------- */
#define DMA_CHNXT_RESETVALUE                  _UINT32_(0x00)                                       /*  (DMA_CHNXT) CHANNEL NEXT DESCRIPTOR ADDRESS POINTER  Reset Value */

#define DMA_CHNXT_NXT_Pos                     _UINT32_(0)                                          /* (DMA_CHNXT) Channel Address Pointer to Next Descriptor Position */
#define DMA_CHNXT_NXT_Msk                     (_UINT32_(0xFFFFFFFF) << DMA_CHNXT_NXT_Pos)          /* (DMA_CHNXT) Channel Address Pointer to Next Descriptor Mask */
#define DMA_CHNXT_NXT(value)                  (DMA_CHNXT_NXT_Msk & (_UINT32_(value) << DMA_CHNXT_NXT_Pos)) /* Assigment of value for NXT in the DMA_CHNXT register */
#define DMA_CHNXT_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (DMA_CHNXT) Register Mask  */


/* -------- DMA_CHLLCFGSTAT : (DMA Offset: 0x3C) ( R/ 32) CHANNEL LINKED LIST CONFIGURATION STATUS REGISTER -------- */
#define DMA_CHLLCFGSTAT_RESETVALUE            _UINT32_(0x00)                                       /*  (DMA_CHLLCFGSTAT) CHANNEL LINKED LIST CONFIGURATION STATUS REGISTER  Reset Value */

#define DMA_CHLLCFGSTAT_CTRLB_Pos             _UINT32_(0)                                          /* (DMA_CHLLCFGSTAT) CTRLB Register Descriptor Load Position */
#define DMA_CHLLCFGSTAT_CTRLB_Msk             (_UINT32_(0x1) << DMA_CHLLCFGSTAT_CTRLB_Pos)         /* (DMA_CHLLCFGSTAT) CTRLB Register Descriptor Load Mask */
#define DMA_CHLLCFGSTAT_CTRLB(value)          (DMA_CHLLCFGSTAT_CTRLB_Msk & (_UINT32_(value) << DMA_CHLLCFGSTAT_CTRLB_Pos)) /* Assigment of value for CTRLB in the DMA_CHLLCFGSTAT register */
#define DMA_CHLLCFGSTAT_EVCTRL_Pos            _UINT32_(1)                                          /* (DMA_CHLLCFGSTAT) EVCTRL Register Descriptor Load Position */
#define DMA_CHLLCFGSTAT_EVCTRL_Msk            (_UINT32_(0x1) << DMA_CHLLCFGSTAT_EVCTRL_Pos)        /* (DMA_CHLLCFGSTAT) EVCTRL Register Descriptor Load Mask */
#define DMA_CHLLCFGSTAT_EVCTRL(value)         (DMA_CHLLCFGSTAT_EVCTRL_Msk & (_UINT32_(value) << DMA_CHLLCFGSTAT_EVCTRL_Pos)) /* Assigment of value for EVCTRL in the DMA_CHLLCFGSTAT register */
#define DMA_CHLLCFGSTAT_SSA_Pos               _UINT32_(2)                                          /* (DMA_CHLLCFGSTAT) Source Start Address Descriptor Load Position */
#define DMA_CHLLCFGSTAT_SSA_Msk               (_UINT32_(0x1) << DMA_CHLLCFGSTAT_SSA_Pos)           /* (DMA_CHLLCFGSTAT) Source Start Address Descriptor Load Mask */
#define DMA_CHLLCFGSTAT_SSA(value)            (DMA_CHLLCFGSTAT_SSA_Msk & (_UINT32_(value) << DMA_CHLLCFGSTAT_SSA_Pos)) /* Assigment of value for SSA in the DMA_CHLLCFGSTAT register */
#define DMA_CHLLCFGSTAT_DSA_Pos               _UINT32_(3)                                          /* (DMA_CHLLCFGSTAT) Destination Start Address Descriptor Load Position */
#define DMA_CHLLCFGSTAT_DSA_Msk               (_UINT32_(0x1) << DMA_CHLLCFGSTAT_DSA_Pos)           /* (DMA_CHLLCFGSTAT) Destination Start Address Descriptor Load Mask */
#define DMA_CHLLCFGSTAT_DSA(value)            (DMA_CHLLCFGSTAT_DSA_Msk & (_UINT32_(value) << DMA_CHLLCFGSTAT_DSA_Pos)) /* Assigment of value for DSA in the DMA_CHLLCFGSTAT register */
#define DMA_CHLLCFGSTAT_SSTRD_Pos             _UINT32_(4)                                          /* (DMA_CHLLCFGSTAT) Source Cell Stride Size Descriptor Load Position */
#define DMA_CHLLCFGSTAT_SSTRD_Msk             (_UINT32_(0x1) << DMA_CHLLCFGSTAT_SSTRD_Pos)         /* (DMA_CHLLCFGSTAT) Source Cell Stride Size Descriptor Load Mask */
#define DMA_CHLLCFGSTAT_SSTRD(value)          (DMA_CHLLCFGSTAT_SSTRD_Msk & (_UINT32_(value) << DMA_CHLLCFGSTAT_SSTRD_Pos)) /* Assigment of value for SSTRD in the DMA_CHLLCFGSTAT register */
#define DMA_CHLLCFGSTAT_DSTRD_Pos             _UINT32_(5)                                          /* (DMA_CHLLCFGSTAT) Destination Cell Stride Size Descriptor Load Position */
#define DMA_CHLLCFGSTAT_DSTRD_Msk             (_UINT32_(0x1) << DMA_CHLLCFGSTAT_DSTRD_Pos)         /* (DMA_CHLLCFGSTAT) Destination Cell Stride Size Descriptor Load Mask */
#define DMA_CHLLCFGSTAT_DSTRD(value)          (DMA_CHLLCFGSTAT_DSTRD_Msk & (_UINT32_(value) << DMA_CHLLCFGSTAT_DSTRD_Pos)) /* Assigment of value for DSTRD in the DMA_CHLLCFGSTAT register */
#define DMA_CHLLCFGSTAT_XSIZ_Pos              _UINT32_(6)                                          /* (DMA_CHLLCFGSTAT) Transfer Size Descriptor Load Position */
#define DMA_CHLLCFGSTAT_XSIZ_Msk              (_UINT32_(0x1) << DMA_CHLLCFGSTAT_XSIZ_Pos)          /* (DMA_CHLLCFGSTAT) Transfer Size Descriptor Load Mask */
#define DMA_CHLLCFGSTAT_XSIZ(value)           (DMA_CHLLCFGSTAT_XSIZ_Msk & (_UINT32_(value) << DMA_CHLLCFGSTAT_XSIZ_Pos)) /* Assigment of value for XSIZ in the DMA_CHLLCFGSTAT register */
#define DMA_CHLLCFGSTAT_PDAT_Pos              _UINT32_(7)                                          /* (DMA_CHLLCFGSTAT) Match Pattern Descriptor Load Position */
#define DMA_CHLLCFGSTAT_PDAT_Msk              (_UINT32_(0x1) << DMA_CHLLCFGSTAT_PDAT_Pos)          /* (DMA_CHLLCFGSTAT) Match Pattern Descriptor Load Mask */
#define DMA_CHLLCFGSTAT_PDAT(value)           (DMA_CHLLCFGSTAT_PDAT_Msk & (_UINT32_(value) << DMA_CHLLCFGSTAT_PDAT_Pos)) /* Assigment of value for PDAT in the DMA_CHLLCFGSTAT register */
#define DMA_CHLLCFGSTAT_CTRLCRC_Pos           _UINT32_(8)                                          /* (DMA_CHLLCFGSTAT) Control CRC Descriptor Load Position */
#define DMA_CHLLCFGSTAT_CTRLCRC_Msk           (_UINT32_(0x1) << DMA_CHLLCFGSTAT_CTRLCRC_Pos)       /* (DMA_CHLLCFGSTAT) Control CRC Descriptor Load Mask */
#define DMA_CHLLCFGSTAT_CTRLCRC(value)        (DMA_CHLLCFGSTAT_CTRLCRC_Msk & (_UINT32_(value) << DMA_CHLLCFGSTAT_CTRLCRC_Pos)) /* Assigment of value for CTRLCRC in the DMA_CHLLCFGSTAT register */
#define DMA_CHLLCFGSTAT_CRCDAT_Pos            _UINT32_(9)                                          /* (DMA_CHLLCFGSTAT) CRC Data Descriptor Load Position */
#define DMA_CHLLCFGSTAT_CRCDAT_Msk            (_UINT32_(0x1) << DMA_CHLLCFGSTAT_CRCDAT_Pos)        /* (DMA_CHLLCFGSTAT) CRC Data Descriptor Load Mask */
#define DMA_CHLLCFGSTAT_CRCDAT(value)         (DMA_CHLLCFGSTAT_CRCDAT_Msk & (_UINT32_(value) << DMA_CHLLCFGSTAT_CRCDAT_Pos)) /* Assigment of value for CRCDAT in the DMA_CHLLCFGSTAT register */
#define DMA_CHLLCFGSTAT_Msk                   _UINT32_(0x000003FF)                                 /* (DMA_CHLLCFGSTAT) Register Mask  */


/* -------- DMA_CHSTATBC : (DMA Offset: 0x40) ( R/ 32) CHANNEL STATUS BLOCK COUNT REGISTER -------- */
#define DMA_CHSTATBC_RESETVALUE               _UINT32_(0x00)                                       /*  (DMA_CHSTATBC) CHANNEL STATUS BLOCK COUNT REGISTER  Reset Value */

#define DMA_CHSTATBC_BBTC_Pos                 _UINT32_(0)                                          /* (DMA_CHSTATBC) Bytes Transfered in the Block Counter Position */
#define DMA_CHSTATBC_BBTC_Msk                 (_UINT32_(0x1FFFF) << DMA_CHSTATBC_BBTC_Pos)         /* (DMA_CHSTATBC) Bytes Transfered in the Block Counter Mask */
#define DMA_CHSTATBC_BBTC(value)              (DMA_CHSTATBC_BBTC_Msk & (_UINT32_(value) << DMA_CHSTATBC_BBTC_Pos)) /* Assigment of value for BBTC in the DMA_CHSTATBC register */
#define DMA_CHSTATBC_Msk                      _UINT32_(0x0001FFFF)                                 /* (DMA_CHSTATBC) Register Mask  */


/* -------- DMA_CHSTATCC : (DMA Offset: 0x44) ( R/ 32) CHANNEL STATUS CELL COUNT REGISTER -------- */
#define DMA_CHSTATCC_RESETVALUE               _UINT32_(0x00)                                       /*  (DMA_CHSTATCC) CHANNEL STATUS CELL COUNT REGISTER  Reset Value */

#define DMA_CHSTATCC_CBTC_Pos                 _UINT32_(0)                                          /* (DMA_CHSTATCC) Bytes Transfered in the Cell Counter Position */
#define DMA_CHSTATCC_CBTC_Msk                 (_UINT32_(0x7FF) << DMA_CHSTATCC_CBTC_Pos)           /* (DMA_CHSTATCC) Bytes Transfered in the Cell Counter Mask */
#define DMA_CHSTATCC_CBTC(value)              (DMA_CHSTATCC_CBTC_Msk & (_UINT32_(value) << DMA_CHSTATCC_CBTC_Pos)) /* Assigment of value for CBTC in the DMA_CHSTATCC register */
#define DMA_CHSTATCC_Msk                      _UINT32_(0x000007FF)                                 /* (DMA_CHSTATCC) Register Mask  */


/* -------- DMA_CHSTAT : (DMA Offset: 0x48) ( R/ 32) CHANNEL STATUS REGISTER -------- */
#define DMA_CHSTAT_RESETVALUE                 _UINT32_(0x00)                                       /*  (DMA_CHSTAT) CHANNEL STATUS REGISTER  Reset Value */

#define DMA_CHSTAT_BLKBUSY_Pos                _UINT32_(0)                                          /* (DMA_CHSTAT) Channel Block Transfer Busy Status Bit (0: none; 1: busy) Position */
#define DMA_CHSTAT_BLKBUSY_Msk                (_UINT32_(0x1) << DMA_CHSTAT_BLKBUSY_Pos)            /* (DMA_CHSTAT) Channel Block Transfer Busy Status Bit (0: none; 1: busy) Mask */
#define DMA_CHSTAT_BLKBUSY(value)             (DMA_CHSTAT_BLKBUSY_Msk & (_UINT32_(value) << DMA_CHSTAT_BLKBUSY_Pos)) /* Assigment of value for BLKBUSY in the DMA_CHSTAT register */
#define DMA_CHSTAT_CELLBUSY_Pos               _UINT32_(1)                                          /* (DMA_CHSTAT) Channel Cell Transfer Busy Status Bit (0: none; 1: busy) Position */
#define DMA_CHSTAT_CELLBUSY_Msk               (_UINT32_(0x1) << DMA_CHSTAT_CELLBUSY_Pos)           /* (DMA_CHSTAT) Channel Cell Transfer Busy Status Bit (0: none; 1: busy) Mask */
#define DMA_CHSTAT_CELLBUSY(value)            (DMA_CHSTAT_CELLBUSY_Msk & (_UINT32_(value) << DMA_CHSTAT_CELLBUSY_Pos)) /* Assigment of value for CELLBUSY in the DMA_CHSTAT register */
#define DMA_CHSTAT_DREAD_Pos                  _UINT32_(2)                                          /* (DMA_CHSTAT) Descriptor Read Status Bit (0: not read or not avail, 1: read and loaded) Position */
#define DMA_CHSTAT_DREAD_Msk                  (_UINT32_(0x1) << DMA_CHSTAT_DREAD_Pos)              /* (DMA_CHSTAT) Descriptor Read Status Bit (0: not read or not avail, 1: read and loaded) Mask */
#define DMA_CHSTAT_DREAD(value)               (DMA_CHSTAT_DREAD_Msk & (_UINT32_(value) << DMA_CHSTAT_DREAD_Pos)) /* Assigment of value for DREAD in the DMA_CHSTAT register */
#define DMA_CHSTAT_Msk                        _UINT32_(0x00000007)                                 /* (DMA_CHSTAT) Register Mask  */


/* -------- DMA_CTRLA : (DMA Offset: 0x00) (R/W 32) DMA CONTROL A REGISTER -------- */
#define DMA_CTRLA_RESETVALUE                  _UINT32_(0x00)                                       /*  (DMA_CTRLA) DMA CONTROL A REGISTER  Reset Value */

#define DMA_CTRLA_ENABLE_Pos                  _UINT32_(1)                                          /* (DMA_CTRLA) DMA Enable Position */
#define DMA_CTRLA_ENABLE_Msk                  (_UINT32_(0x1) << DMA_CTRLA_ENABLE_Pos)              /* (DMA_CTRLA) DMA Enable Mask */
#define DMA_CTRLA_ENABLE(value)               (DMA_CTRLA_ENABLE_Msk & (_UINT32_(value) << DMA_CTRLA_ENABLE_Pos)) /* Assigment of value for ENABLE in the DMA_CTRLA register */
#define DMA_CTRLA_Msk                         _UINT32_(0x00000002)                                 /* (DMA_CTRLA) Register Mask  */


/* -------- DMA_DBGCTRL : (DMA Offset: 0x08) (R/W 32) DEBUG CONTROL REGISTER -------- */
#define DMA_DBGCTRL_RESETVALUE                _UINT32_(0x00)                                       /*  (DMA_DBGCTRL) DEBUG CONTROL REGISTER  Reset Value */

#define DMA_DBGCTRL_DBGRUN_Pos                _UINT32_(0)                                          /* (DMA_DBGCTRL) Debug Run Position */
#define DMA_DBGCTRL_DBGRUN_Msk                (_UINT32_(0x1) << DMA_DBGCTRL_DBGRUN_Pos)            /* (DMA_DBGCTRL) Debug Run Mask */
#define DMA_DBGCTRL_DBGRUN(value)             (DMA_DBGCTRL_DBGRUN_Msk & (_UINT32_(value) << DMA_DBGCTRL_DBGRUN_Pos)) /* Assigment of value for DBGRUN in the DMA_DBGCTRL register */
#define DMA_DBGCTRL_Msk                       _UINT32_(0x00000001)                                 /* (DMA_DBGCTRL) Register Mask  */


/* -------- DMA_CRCPOLYA : (DMA Offset: 0x0C) (R/W 32) DMA CRC POLYNOMIAL A REGISTER -------- */
#define DMA_CRCPOLYA_RESETVALUE               _UINT32_(0x00)                                       /*  (DMA_CRCPOLYA) DMA CRC POLYNOMIAL A REGISTER  Reset Value */

#define DMA_CRCPOLYA_POLYA_Pos                _UINT32_(0)                                          /* (DMA_CRCPOLYA) CRC Polynomial Coefficients A Register Position */
#define DMA_CRCPOLYA_POLYA_Msk                (_UINT32_(0xFFFFFFFF) << DMA_CRCPOLYA_POLYA_Pos)     /* (DMA_CRCPOLYA) CRC Polynomial Coefficients A Register Mask */
#define DMA_CRCPOLYA_POLYA(value)             (DMA_CRCPOLYA_POLYA_Msk & (_UINT32_(value) << DMA_CRCPOLYA_POLYA_Pos)) /* Assigment of value for POLYA in the DMA_CRCPOLYA register */
#define DMA_CRCPOLYA_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (DMA_CRCPOLYA) Register Mask  */


/* -------- DMA_CRCPOLYB : (DMA Offset: 0x10) (R/W 32) DMA CRC POLYNOMIAL B REGISTER -------- */
#define DMA_CRCPOLYB_RESETVALUE               _UINT32_(0x00)                                       /*  (DMA_CRCPOLYB) DMA CRC POLYNOMIAL B REGISTER  Reset Value */

#define DMA_CRCPOLYB_POLYB_Pos                _UINT32_(0)                                          /* (DMA_CRCPOLYB) CRC Polynomial Coefficients B Register Position */
#define DMA_CRCPOLYB_POLYB_Msk                (_UINT32_(0xFFFFFFFF) << DMA_CRCPOLYB_POLYB_Pos)     /* (DMA_CRCPOLYB) CRC Polynomial Coefficients B Register Mask */
#define DMA_CRCPOLYB_POLYB(value)             (DMA_CRCPOLYB_POLYB_Msk & (_UINT32_(value) << DMA_CRCPOLYB_POLYB_Pos)) /* Assigment of value for POLYB in the DMA_CRCPOLYB register */
#define DMA_CRCPOLYB_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (DMA_CRCPOLYB) Register Mask  */


/* -------- DMA_INTSTAT4 : (DMA Offset: 0x14) ( R/ 32) DMA INTERRUPT PRIORITY 4 STATUS REGISTER -------- */
#define DMA_INTSTAT4_RESETVALUE               _UINT32_(0x00)                                       /*  (DMA_INTSTAT4) DMA INTERRUPT PRIORITY 4 STATUS REGISTER  Reset Value */

#define DMA_INTSTAT4_CH0_Pos                  _UINT32_(0)                                          /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Position */
#define DMA_INTSTAT4_CH0_Msk                  (_UINT32_(0x1) << DMA_INTSTAT4_CH0_Pos)              /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Mask */
#define DMA_INTSTAT4_CH0(value)               (DMA_INTSTAT4_CH0_Msk & (_UINT32_(value) << DMA_INTSTAT4_CH0_Pos)) /* Assigment of value for CH0 in the DMA_INTSTAT4 register */
#define DMA_INTSTAT4_CH1_Pos                  _UINT32_(1)                                          /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Position */
#define DMA_INTSTAT4_CH1_Msk                  (_UINT32_(0x1) << DMA_INTSTAT4_CH1_Pos)              /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Mask */
#define DMA_INTSTAT4_CH1(value)               (DMA_INTSTAT4_CH1_Msk & (_UINT32_(value) << DMA_INTSTAT4_CH1_Pos)) /* Assigment of value for CH1 in the DMA_INTSTAT4 register */
#define DMA_INTSTAT4_CH2_Pos                  _UINT32_(2)                                          /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Position */
#define DMA_INTSTAT4_CH2_Msk                  (_UINT32_(0x1) << DMA_INTSTAT4_CH2_Pos)              /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Mask */
#define DMA_INTSTAT4_CH2(value)               (DMA_INTSTAT4_CH2_Msk & (_UINT32_(value) << DMA_INTSTAT4_CH2_Pos)) /* Assigment of value for CH2 in the DMA_INTSTAT4 register */
#define DMA_INTSTAT4_CH3_Pos                  _UINT32_(3)                                          /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Position */
#define DMA_INTSTAT4_CH3_Msk                  (_UINT32_(0x1) << DMA_INTSTAT4_CH3_Pos)              /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Mask */
#define DMA_INTSTAT4_CH3(value)               (DMA_INTSTAT4_CH3_Msk & (_UINT32_(value) << DMA_INTSTAT4_CH3_Pos)) /* Assigment of value for CH3 in the DMA_INTSTAT4 register */
#define DMA_INTSTAT4_CH4_Pos                  _UINT32_(4)                                          /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Position */
#define DMA_INTSTAT4_CH4_Msk                  (_UINT32_(0x1) << DMA_INTSTAT4_CH4_Pos)              /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Mask */
#define DMA_INTSTAT4_CH4(value)               (DMA_INTSTAT4_CH4_Msk & (_UINT32_(value) << DMA_INTSTAT4_CH4_Pos)) /* Assigment of value for CH4 in the DMA_INTSTAT4 register */
#define DMA_INTSTAT4_CH5_Pos                  _UINT32_(5)                                          /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Position */
#define DMA_INTSTAT4_CH5_Msk                  (_UINT32_(0x1) << DMA_INTSTAT4_CH5_Pos)              /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Mask */
#define DMA_INTSTAT4_CH5(value)               (DMA_INTSTAT4_CH5_Msk & (_UINT32_(value) << DMA_INTSTAT4_CH5_Pos)) /* Assigment of value for CH5 in the DMA_INTSTAT4 register */
#define DMA_INTSTAT4_CH6_Pos                  _UINT32_(6)                                          /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Position */
#define DMA_INTSTAT4_CH6_Msk                  (_UINT32_(0x1) << DMA_INTSTAT4_CH6_Pos)              /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Mask */
#define DMA_INTSTAT4_CH6(value)               (DMA_INTSTAT4_CH6_Msk & (_UINT32_(value) << DMA_INTSTAT4_CH6_Pos)) /* Assigment of value for CH6 in the DMA_INTSTAT4 register */
#define DMA_INTSTAT4_CH7_Pos                  _UINT32_(7)                                          /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Position */
#define DMA_INTSTAT4_CH7_Msk                  (_UINT32_(0x1) << DMA_INTSTAT4_CH7_Pos)              /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Mask */
#define DMA_INTSTAT4_CH7(value)               (DMA_INTSTAT4_CH7_Msk & (_UINT32_(value) << DMA_INTSTAT4_CH7_Pos)) /* Assigment of value for CH7 in the DMA_INTSTAT4 register */
#define DMA_INTSTAT4_CH8_Pos                  _UINT32_(8)                                          /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Position */
#define DMA_INTSTAT4_CH8_Msk                  (_UINT32_(0x1) << DMA_INTSTAT4_CH8_Pos)              /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Mask */
#define DMA_INTSTAT4_CH8(value)               (DMA_INTSTAT4_CH8_Msk & (_UINT32_(value) << DMA_INTSTAT4_CH8_Pos)) /* Assigment of value for CH8 in the DMA_INTSTAT4 register */
#define DMA_INTSTAT4_CH9_Pos                  _UINT32_(9)                                          /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Position */
#define DMA_INTSTAT4_CH9_Msk                  (_UINT32_(0x1) << DMA_INTSTAT4_CH9_Pos)              /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Mask */
#define DMA_INTSTAT4_CH9(value)               (DMA_INTSTAT4_CH9_Msk & (_UINT32_(value) << DMA_INTSTAT4_CH9_Pos)) /* Assigment of value for CH9 in the DMA_INTSTAT4 register */
#define DMA_INTSTAT4_CH10_Pos                 _UINT32_(10)                                         /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Position */
#define DMA_INTSTAT4_CH10_Msk                 (_UINT32_(0x1) << DMA_INTSTAT4_CH10_Pos)             /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Mask */
#define DMA_INTSTAT4_CH10(value)              (DMA_INTSTAT4_CH10_Msk & (_UINT32_(value) << DMA_INTSTAT4_CH10_Pos)) /* Assigment of value for CH10 in the DMA_INTSTAT4 register */
#define DMA_INTSTAT4_CH11_Pos                 _UINT32_(11)                                         /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Position */
#define DMA_INTSTAT4_CH11_Msk                 (_UINT32_(0x1) << DMA_INTSTAT4_CH11_Pos)             /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Mask */
#define DMA_INTSTAT4_CH11(value)              (DMA_INTSTAT4_CH11_Msk & (_UINT32_(value) << DMA_INTSTAT4_CH11_Pos)) /* Assigment of value for CH11 in the DMA_INTSTAT4 register */
#define DMA_INTSTAT4_CH12_Pos                 _UINT32_(12)                                         /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Position */
#define DMA_INTSTAT4_CH12_Msk                 (_UINT32_(0x1) << DMA_INTSTAT4_CH12_Pos)             /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Mask */
#define DMA_INTSTAT4_CH12(value)              (DMA_INTSTAT4_CH12_Msk & (_UINT32_(value) << DMA_INTSTAT4_CH12_Pos)) /* Assigment of value for CH12 in the DMA_INTSTAT4 register */
#define DMA_INTSTAT4_CH13_Pos                 _UINT32_(13)                                         /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Position */
#define DMA_INTSTAT4_CH13_Msk                 (_UINT32_(0x1) << DMA_INTSTAT4_CH13_Pos)             /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Mask */
#define DMA_INTSTAT4_CH13(value)              (DMA_INTSTAT4_CH13_Msk & (_UINT32_(value) << DMA_INTSTAT4_CH13_Pos)) /* Assigment of value for CH13 in the DMA_INTSTAT4 register */
#define DMA_INTSTAT4_CH14_Pos                 _UINT32_(14)                                         /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Position */
#define DMA_INTSTAT4_CH14_Msk                 (_UINT32_(0x1) << DMA_INTSTAT4_CH14_Pos)             /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Mask */
#define DMA_INTSTAT4_CH14(value)              (DMA_INTSTAT4_CH14_Msk & (_UINT32_(value) << DMA_INTSTAT4_CH14_Pos)) /* Assigment of value for CH14 in the DMA_INTSTAT4 register */
#define DMA_INTSTAT4_CH15_Pos                 _UINT32_(15)                                         /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Position */
#define DMA_INTSTAT4_CH15_Msk                 (_UINT32_(0x1) << DMA_INTSTAT4_CH15_Pos)             /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Mask */
#define DMA_INTSTAT4_CH15(value)              (DMA_INTSTAT4_CH15_Msk & (_UINT32_(value) << DMA_INTSTAT4_CH15_Pos)) /* Assigment of value for CH15 in the DMA_INTSTAT4 register */
#define DMA_INTSTAT4_CH16_Pos                 _UINT32_(16)                                         /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Position */
#define DMA_INTSTAT4_CH16_Msk                 (_UINT32_(0x1) << DMA_INTSTAT4_CH16_Pos)             /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Mask */
#define DMA_INTSTAT4_CH16(value)              (DMA_INTSTAT4_CH16_Msk & (_UINT32_(value) << DMA_INTSTAT4_CH16_Pos)) /* Assigment of value for CH16 in the DMA_INTSTAT4 register */
#define DMA_INTSTAT4_CH17_Pos                 _UINT32_(17)                                         /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Position */
#define DMA_INTSTAT4_CH17_Msk                 (_UINT32_(0x1) << DMA_INTSTAT4_CH17_Pos)             /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Mask */
#define DMA_INTSTAT4_CH17(value)              (DMA_INTSTAT4_CH17_Msk & (_UINT32_(value) << DMA_INTSTAT4_CH17_Pos)) /* Assigment of value for CH17 in the DMA_INTSTAT4 register */
#define DMA_INTSTAT4_CH18_Pos                 _UINT32_(18)                                         /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Position */
#define DMA_INTSTAT4_CH18_Msk                 (_UINT32_(0x1) << DMA_INTSTAT4_CH18_Pos)             /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Mask */
#define DMA_INTSTAT4_CH18(value)              (DMA_INTSTAT4_CH18_Msk & (_UINT32_(value) << DMA_INTSTAT4_CH18_Pos)) /* Assigment of value for CH18 in the DMA_INTSTAT4 register */
#define DMA_INTSTAT4_CH19_Pos                 _UINT32_(19)                                         /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Position */
#define DMA_INTSTAT4_CH19_Msk                 (_UINT32_(0x1) << DMA_INTSTAT4_CH19_Pos)             /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Mask */
#define DMA_INTSTAT4_CH19(value)              (DMA_INTSTAT4_CH19_Msk & (_UINT32_(value) << DMA_INTSTAT4_CH19_Pos)) /* Assigment of value for CH19 in the DMA_INTSTAT4 register */
#define DMA_INTSTAT4_CH20_Pos                 _UINT32_(20)                                         /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Position */
#define DMA_INTSTAT4_CH20_Msk                 (_UINT32_(0x1) << DMA_INTSTAT4_CH20_Pos)             /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Mask */
#define DMA_INTSTAT4_CH20(value)              (DMA_INTSTAT4_CH20_Msk & (_UINT32_(value) << DMA_INTSTAT4_CH20_Pos)) /* Assigment of value for CH20 in the DMA_INTSTAT4 register */
#define DMA_INTSTAT4_CH21_Pos                 _UINT32_(21)                                         /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Position */
#define DMA_INTSTAT4_CH21_Msk                 (_UINT32_(0x1) << DMA_INTSTAT4_CH21_Pos)             /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Mask */
#define DMA_INTSTAT4_CH21(value)              (DMA_INTSTAT4_CH21_Msk & (_UINT32_(value) << DMA_INTSTAT4_CH21_Pos)) /* Assigment of value for CH21 in the DMA_INTSTAT4 register */
#define DMA_INTSTAT4_CH22_Pos                 _UINT32_(22)                                         /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Position */
#define DMA_INTSTAT4_CH22_Msk                 (_UINT32_(0x1) << DMA_INTSTAT4_CH22_Pos)             /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Mask */
#define DMA_INTSTAT4_CH22(value)              (DMA_INTSTAT4_CH22_Msk & (_UINT32_(value) << DMA_INTSTAT4_CH22_Pos)) /* Assigment of value for CH22 in the DMA_INTSTAT4 register */
#define DMA_INTSTAT4_CH23_Pos                 _UINT32_(23)                                         /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Position */
#define DMA_INTSTAT4_CH23_Msk                 (_UINT32_(0x1) << DMA_INTSTAT4_CH23_Pos)             /* (DMA_INTSTAT4) DMA Channel active interrupt at priority 4 Mask */
#define DMA_INTSTAT4_CH23(value)              (DMA_INTSTAT4_CH23_Msk & (_UINT32_(value) << DMA_INTSTAT4_CH23_Pos)) /* Assigment of value for CH23 in the DMA_INTSTAT4 register */
#define DMA_INTSTAT4_Msk                      _UINT32_(0x00FFFFFF)                                 /* (DMA_INTSTAT4) Register Mask  */

#define DMA_INTSTAT4_CH_Pos                   _UINT32_(0)                                          /* (DMA_INTSTAT4 Position) DMA Channel active interrupt at priority 4 */
#define DMA_INTSTAT4_CH_Msk                   (_UINT32_(0xFFFFFF) << DMA_INTSTAT4_CH_Pos)          /* (DMA_INTSTAT4 Mask) CH */
#define DMA_INTSTAT4_CH(value)                (DMA_INTSTAT4_CH_Msk & (_UINT32_(value) << DMA_INTSTAT4_CH_Pos)) 

/* -------- DMA_INTSTAT3 : (DMA Offset: 0x18) ( R/ 32) DMA INTERRUPT PRIORITY 3 STATUS REGISTER -------- */
#define DMA_INTSTAT3_RESETVALUE               _UINT32_(0x00)                                       /*  (DMA_INTSTAT3) DMA INTERRUPT PRIORITY 3 STATUS REGISTER  Reset Value */

#define DMA_INTSTAT3_CH0_Pos                  _UINT32_(0)                                          /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Position */
#define DMA_INTSTAT3_CH0_Msk                  (_UINT32_(0x1) << DMA_INTSTAT3_CH0_Pos)              /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Mask */
#define DMA_INTSTAT3_CH0(value)               (DMA_INTSTAT3_CH0_Msk & (_UINT32_(value) << DMA_INTSTAT3_CH0_Pos)) /* Assigment of value for CH0 in the DMA_INTSTAT3 register */
#define DMA_INTSTAT3_CH1_Pos                  _UINT32_(1)                                          /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Position */
#define DMA_INTSTAT3_CH1_Msk                  (_UINT32_(0x1) << DMA_INTSTAT3_CH1_Pos)              /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Mask */
#define DMA_INTSTAT3_CH1(value)               (DMA_INTSTAT3_CH1_Msk & (_UINT32_(value) << DMA_INTSTAT3_CH1_Pos)) /* Assigment of value for CH1 in the DMA_INTSTAT3 register */
#define DMA_INTSTAT3_CH2_Pos                  _UINT32_(2)                                          /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Position */
#define DMA_INTSTAT3_CH2_Msk                  (_UINT32_(0x1) << DMA_INTSTAT3_CH2_Pos)              /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Mask */
#define DMA_INTSTAT3_CH2(value)               (DMA_INTSTAT3_CH2_Msk & (_UINT32_(value) << DMA_INTSTAT3_CH2_Pos)) /* Assigment of value for CH2 in the DMA_INTSTAT3 register */
#define DMA_INTSTAT3_CH3_Pos                  _UINT32_(3)                                          /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Position */
#define DMA_INTSTAT3_CH3_Msk                  (_UINT32_(0x1) << DMA_INTSTAT3_CH3_Pos)              /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Mask */
#define DMA_INTSTAT3_CH3(value)               (DMA_INTSTAT3_CH3_Msk & (_UINT32_(value) << DMA_INTSTAT3_CH3_Pos)) /* Assigment of value for CH3 in the DMA_INTSTAT3 register */
#define DMA_INTSTAT3_CH4_Pos                  _UINT32_(4)                                          /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Position */
#define DMA_INTSTAT3_CH4_Msk                  (_UINT32_(0x1) << DMA_INTSTAT3_CH4_Pos)              /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Mask */
#define DMA_INTSTAT3_CH4(value)               (DMA_INTSTAT3_CH4_Msk & (_UINT32_(value) << DMA_INTSTAT3_CH4_Pos)) /* Assigment of value for CH4 in the DMA_INTSTAT3 register */
#define DMA_INTSTAT3_CH5_Pos                  _UINT32_(5)                                          /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Position */
#define DMA_INTSTAT3_CH5_Msk                  (_UINT32_(0x1) << DMA_INTSTAT3_CH5_Pos)              /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Mask */
#define DMA_INTSTAT3_CH5(value)               (DMA_INTSTAT3_CH5_Msk & (_UINT32_(value) << DMA_INTSTAT3_CH5_Pos)) /* Assigment of value for CH5 in the DMA_INTSTAT3 register */
#define DMA_INTSTAT3_CH6_Pos                  _UINT32_(6)                                          /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Position */
#define DMA_INTSTAT3_CH6_Msk                  (_UINT32_(0x1) << DMA_INTSTAT3_CH6_Pos)              /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Mask */
#define DMA_INTSTAT3_CH6(value)               (DMA_INTSTAT3_CH6_Msk & (_UINT32_(value) << DMA_INTSTAT3_CH6_Pos)) /* Assigment of value for CH6 in the DMA_INTSTAT3 register */
#define DMA_INTSTAT3_CH7_Pos                  _UINT32_(7)                                          /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Position */
#define DMA_INTSTAT3_CH7_Msk                  (_UINT32_(0x1) << DMA_INTSTAT3_CH7_Pos)              /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Mask */
#define DMA_INTSTAT3_CH7(value)               (DMA_INTSTAT3_CH7_Msk & (_UINT32_(value) << DMA_INTSTAT3_CH7_Pos)) /* Assigment of value for CH7 in the DMA_INTSTAT3 register */
#define DMA_INTSTAT3_CH8_Pos                  _UINT32_(8)                                          /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Position */
#define DMA_INTSTAT3_CH8_Msk                  (_UINT32_(0x1) << DMA_INTSTAT3_CH8_Pos)              /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Mask */
#define DMA_INTSTAT3_CH8(value)               (DMA_INTSTAT3_CH8_Msk & (_UINT32_(value) << DMA_INTSTAT3_CH8_Pos)) /* Assigment of value for CH8 in the DMA_INTSTAT3 register */
#define DMA_INTSTAT3_CH9_Pos                  _UINT32_(9)                                          /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Position */
#define DMA_INTSTAT3_CH9_Msk                  (_UINT32_(0x1) << DMA_INTSTAT3_CH9_Pos)              /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Mask */
#define DMA_INTSTAT3_CH9(value)               (DMA_INTSTAT3_CH9_Msk & (_UINT32_(value) << DMA_INTSTAT3_CH9_Pos)) /* Assigment of value for CH9 in the DMA_INTSTAT3 register */
#define DMA_INTSTAT3_CH10_Pos                 _UINT32_(10)                                         /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Position */
#define DMA_INTSTAT3_CH10_Msk                 (_UINT32_(0x1) << DMA_INTSTAT3_CH10_Pos)             /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Mask */
#define DMA_INTSTAT3_CH10(value)              (DMA_INTSTAT3_CH10_Msk & (_UINT32_(value) << DMA_INTSTAT3_CH10_Pos)) /* Assigment of value for CH10 in the DMA_INTSTAT3 register */
#define DMA_INTSTAT3_CH11_Pos                 _UINT32_(11)                                         /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Position */
#define DMA_INTSTAT3_CH11_Msk                 (_UINT32_(0x1) << DMA_INTSTAT3_CH11_Pos)             /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Mask */
#define DMA_INTSTAT3_CH11(value)              (DMA_INTSTAT3_CH11_Msk & (_UINT32_(value) << DMA_INTSTAT3_CH11_Pos)) /* Assigment of value for CH11 in the DMA_INTSTAT3 register */
#define DMA_INTSTAT3_CH12_Pos                 _UINT32_(12)                                         /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Position */
#define DMA_INTSTAT3_CH12_Msk                 (_UINT32_(0x1) << DMA_INTSTAT3_CH12_Pos)             /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Mask */
#define DMA_INTSTAT3_CH12(value)              (DMA_INTSTAT3_CH12_Msk & (_UINT32_(value) << DMA_INTSTAT3_CH12_Pos)) /* Assigment of value for CH12 in the DMA_INTSTAT3 register */
#define DMA_INTSTAT3_CH13_Pos                 _UINT32_(13)                                         /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Position */
#define DMA_INTSTAT3_CH13_Msk                 (_UINT32_(0x1) << DMA_INTSTAT3_CH13_Pos)             /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Mask */
#define DMA_INTSTAT3_CH13(value)              (DMA_INTSTAT3_CH13_Msk & (_UINT32_(value) << DMA_INTSTAT3_CH13_Pos)) /* Assigment of value for CH13 in the DMA_INTSTAT3 register */
#define DMA_INTSTAT3_CH14_Pos                 _UINT32_(14)                                         /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Position */
#define DMA_INTSTAT3_CH14_Msk                 (_UINT32_(0x1) << DMA_INTSTAT3_CH14_Pos)             /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Mask */
#define DMA_INTSTAT3_CH14(value)              (DMA_INTSTAT3_CH14_Msk & (_UINT32_(value) << DMA_INTSTAT3_CH14_Pos)) /* Assigment of value for CH14 in the DMA_INTSTAT3 register */
#define DMA_INTSTAT3_CH15_Pos                 _UINT32_(15)                                         /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Position */
#define DMA_INTSTAT3_CH15_Msk                 (_UINT32_(0x1) << DMA_INTSTAT3_CH15_Pos)             /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Mask */
#define DMA_INTSTAT3_CH15(value)              (DMA_INTSTAT3_CH15_Msk & (_UINT32_(value) << DMA_INTSTAT3_CH15_Pos)) /* Assigment of value for CH15 in the DMA_INTSTAT3 register */
#define DMA_INTSTAT3_CH16_Pos                 _UINT32_(16)                                         /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Position */
#define DMA_INTSTAT3_CH16_Msk                 (_UINT32_(0x1) << DMA_INTSTAT3_CH16_Pos)             /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Mask */
#define DMA_INTSTAT3_CH16(value)              (DMA_INTSTAT3_CH16_Msk & (_UINT32_(value) << DMA_INTSTAT3_CH16_Pos)) /* Assigment of value for CH16 in the DMA_INTSTAT3 register */
#define DMA_INTSTAT3_CH17_Pos                 _UINT32_(17)                                         /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Position */
#define DMA_INTSTAT3_CH17_Msk                 (_UINT32_(0x1) << DMA_INTSTAT3_CH17_Pos)             /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Mask */
#define DMA_INTSTAT3_CH17(value)              (DMA_INTSTAT3_CH17_Msk & (_UINT32_(value) << DMA_INTSTAT3_CH17_Pos)) /* Assigment of value for CH17 in the DMA_INTSTAT3 register */
#define DMA_INTSTAT3_CH18_Pos                 _UINT32_(18)                                         /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Position */
#define DMA_INTSTAT3_CH18_Msk                 (_UINT32_(0x1) << DMA_INTSTAT3_CH18_Pos)             /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Mask */
#define DMA_INTSTAT3_CH18(value)              (DMA_INTSTAT3_CH18_Msk & (_UINT32_(value) << DMA_INTSTAT3_CH18_Pos)) /* Assigment of value for CH18 in the DMA_INTSTAT3 register */
#define DMA_INTSTAT3_CH19_Pos                 _UINT32_(19)                                         /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Position */
#define DMA_INTSTAT3_CH19_Msk                 (_UINT32_(0x1) << DMA_INTSTAT3_CH19_Pos)             /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Mask */
#define DMA_INTSTAT3_CH19(value)              (DMA_INTSTAT3_CH19_Msk & (_UINT32_(value) << DMA_INTSTAT3_CH19_Pos)) /* Assigment of value for CH19 in the DMA_INTSTAT3 register */
#define DMA_INTSTAT3_CH20_Pos                 _UINT32_(20)                                         /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Position */
#define DMA_INTSTAT3_CH20_Msk                 (_UINT32_(0x1) << DMA_INTSTAT3_CH20_Pos)             /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Mask */
#define DMA_INTSTAT3_CH20(value)              (DMA_INTSTAT3_CH20_Msk & (_UINT32_(value) << DMA_INTSTAT3_CH20_Pos)) /* Assigment of value for CH20 in the DMA_INTSTAT3 register */
#define DMA_INTSTAT3_CH21_Pos                 _UINT32_(21)                                         /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Position */
#define DMA_INTSTAT3_CH21_Msk                 (_UINT32_(0x1) << DMA_INTSTAT3_CH21_Pos)             /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Mask */
#define DMA_INTSTAT3_CH21(value)              (DMA_INTSTAT3_CH21_Msk & (_UINT32_(value) << DMA_INTSTAT3_CH21_Pos)) /* Assigment of value for CH21 in the DMA_INTSTAT3 register */
#define DMA_INTSTAT3_CH22_Pos                 _UINT32_(22)                                         /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Position */
#define DMA_INTSTAT3_CH22_Msk                 (_UINT32_(0x1) << DMA_INTSTAT3_CH22_Pos)             /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Mask */
#define DMA_INTSTAT3_CH22(value)              (DMA_INTSTAT3_CH22_Msk & (_UINT32_(value) << DMA_INTSTAT3_CH22_Pos)) /* Assigment of value for CH22 in the DMA_INTSTAT3 register */
#define DMA_INTSTAT3_CH23_Pos                 _UINT32_(23)                                         /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Position */
#define DMA_INTSTAT3_CH23_Msk                 (_UINT32_(0x1) << DMA_INTSTAT3_CH23_Pos)             /* (DMA_INTSTAT3) DMA Channel active interrupt at priority 3 Mask */
#define DMA_INTSTAT3_CH23(value)              (DMA_INTSTAT3_CH23_Msk & (_UINT32_(value) << DMA_INTSTAT3_CH23_Pos)) /* Assigment of value for CH23 in the DMA_INTSTAT3 register */
#define DMA_INTSTAT3_Msk                      _UINT32_(0x00FFFFFF)                                 /* (DMA_INTSTAT3) Register Mask  */

#define DMA_INTSTAT3_CH_Pos                   _UINT32_(0)                                          /* (DMA_INTSTAT3 Position) DMA Channel active interrupt at priority 3 */
#define DMA_INTSTAT3_CH_Msk                   (_UINT32_(0xFFFFFF) << DMA_INTSTAT3_CH_Pos)          /* (DMA_INTSTAT3 Mask) CH */
#define DMA_INTSTAT3_CH(value)                (DMA_INTSTAT3_CH_Msk & (_UINT32_(value) << DMA_INTSTAT3_CH_Pos)) 

/* -------- DMA_INTSTAT2 : (DMA Offset: 0x1C) ( R/ 32) DMA INTERRUPT PRIORITY 2 STATUS REGISTER -------- */
#define DMA_INTSTAT2_RESETVALUE               _UINT32_(0x00)                                       /*  (DMA_INTSTAT2) DMA INTERRUPT PRIORITY 2 STATUS REGISTER  Reset Value */

#define DMA_INTSTAT2_CH0_Pos                  _UINT32_(0)                                          /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Position */
#define DMA_INTSTAT2_CH0_Msk                  (_UINT32_(0x1) << DMA_INTSTAT2_CH0_Pos)              /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Mask */
#define DMA_INTSTAT2_CH0(value)               (DMA_INTSTAT2_CH0_Msk & (_UINT32_(value) << DMA_INTSTAT2_CH0_Pos)) /* Assigment of value for CH0 in the DMA_INTSTAT2 register */
#define DMA_INTSTAT2_CH1_Pos                  _UINT32_(1)                                          /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Position */
#define DMA_INTSTAT2_CH1_Msk                  (_UINT32_(0x1) << DMA_INTSTAT2_CH1_Pos)              /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Mask */
#define DMA_INTSTAT2_CH1(value)               (DMA_INTSTAT2_CH1_Msk & (_UINT32_(value) << DMA_INTSTAT2_CH1_Pos)) /* Assigment of value for CH1 in the DMA_INTSTAT2 register */
#define DMA_INTSTAT2_CH2_Pos                  _UINT32_(2)                                          /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Position */
#define DMA_INTSTAT2_CH2_Msk                  (_UINT32_(0x1) << DMA_INTSTAT2_CH2_Pos)              /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Mask */
#define DMA_INTSTAT2_CH2(value)               (DMA_INTSTAT2_CH2_Msk & (_UINT32_(value) << DMA_INTSTAT2_CH2_Pos)) /* Assigment of value for CH2 in the DMA_INTSTAT2 register */
#define DMA_INTSTAT2_CH3_Pos                  _UINT32_(3)                                          /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Position */
#define DMA_INTSTAT2_CH3_Msk                  (_UINT32_(0x1) << DMA_INTSTAT2_CH3_Pos)              /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Mask */
#define DMA_INTSTAT2_CH3(value)               (DMA_INTSTAT2_CH3_Msk & (_UINT32_(value) << DMA_INTSTAT2_CH3_Pos)) /* Assigment of value for CH3 in the DMA_INTSTAT2 register */
#define DMA_INTSTAT2_CH4_Pos                  _UINT32_(4)                                          /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Position */
#define DMA_INTSTAT2_CH4_Msk                  (_UINT32_(0x1) << DMA_INTSTAT2_CH4_Pos)              /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Mask */
#define DMA_INTSTAT2_CH4(value)               (DMA_INTSTAT2_CH4_Msk & (_UINT32_(value) << DMA_INTSTAT2_CH4_Pos)) /* Assigment of value for CH4 in the DMA_INTSTAT2 register */
#define DMA_INTSTAT2_CH5_Pos                  _UINT32_(5)                                          /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Position */
#define DMA_INTSTAT2_CH5_Msk                  (_UINT32_(0x1) << DMA_INTSTAT2_CH5_Pos)              /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Mask */
#define DMA_INTSTAT2_CH5(value)               (DMA_INTSTAT2_CH5_Msk & (_UINT32_(value) << DMA_INTSTAT2_CH5_Pos)) /* Assigment of value for CH5 in the DMA_INTSTAT2 register */
#define DMA_INTSTAT2_CH6_Pos                  _UINT32_(6)                                          /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Position */
#define DMA_INTSTAT2_CH6_Msk                  (_UINT32_(0x1) << DMA_INTSTAT2_CH6_Pos)              /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Mask */
#define DMA_INTSTAT2_CH6(value)               (DMA_INTSTAT2_CH6_Msk & (_UINT32_(value) << DMA_INTSTAT2_CH6_Pos)) /* Assigment of value for CH6 in the DMA_INTSTAT2 register */
#define DMA_INTSTAT2_CH7_Pos                  _UINT32_(7)                                          /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Position */
#define DMA_INTSTAT2_CH7_Msk                  (_UINT32_(0x1) << DMA_INTSTAT2_CH7_Pos)              /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Mask */
#define DMA_INTSTAT2_CH7(value)               (DMA_INTSTAT2_CH7_Msk & (_UINT32_(value) << DMA_INTSTAT2_CH7_Pos)) /* Assigment of value for CH7 in the DMA_INTSTAT2 register */
#define DMA_INTSTAT2_CH8_Pos                  _UINT32_(8)                                          /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Position */
#define DMA_INTSTAT2_CH8_Msk                  (_UINT32_(0x1) << DMA_INTSTAT2_CH8_Pos)              /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Mask */
#define DMA_INTSTAT2_CH8(value)               (DMA_INTSTAT2_CH8_Msk & (_UINT32_(value) << DMA_INTSTAT2_CH8_Pos)) /* Assigment of value for CH8 in the DMA_INTSTAT2 register */
#define DMA_INTSTAT2_CH9_Pos                  _UINT32_(9)                                          /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Position */
#define DMA_INTSTAT2_CH9_Msk                  (_UINT32_(0x1) << DMA_INTSTAT2_CH9_Pos)              /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Mask */
#define DMA_INTSTAT2_CH9(value)               (DMA_INTSTAT2_CH9_Msk & (_UINT32_(value) << DMA_INTSTAT2_CH9_Pos)) /* Assigment of value for CH9 in the DMA_INTSTAT2 register */
#define DMA_INTSTAT2_CH10_Pos                 _UINT32_(10)                                         /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Position */
#define DMA_INTSTAT2_CH10_Msk                 (_UINT32_(0x1) << DMA_INTSTAT2_CH10_Pos)             /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Mask */
#define DMA_INTSTAT2_CH10(value)              (DMA_INTSTAT2_CH10_Msk & (_UINT32_(value) << DMA_INTSTAT2_CH10_Pos)) /* Assigment of value for CH10 in the DMA_INTSTAT2 register */
#define DMA_INTSTAT2_CH11_Pos                 _UINT32_(11)                                         /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Position */
#define DMA_INTSTAT2_CH11_Msk                 (_UINT32_(0x1) << DMA_INTSTAT2_CH11_Pos)             /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Mask */
#define DMA_INTSTAT2_CH11(value)              (DMA_INTSTAT2_CH11_Msk & (_UINT32_(value) << DMA_INTSTAT2_CH11_Pos)) /* Assigment of value for CH11 in the DMA_INTSTAT2 register */
#define DMA_INTSTAT2_CH12_Pos                 _UINT32_(12)                                         /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Position */
#define DMA_INTSTAT2_CH12_Msk                 (_UINT32_(0x1) << DMA_INTSTAT2_CH12_Pos)             /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Mask */
#define DMA_INTSTAT2_CH12(value)              (DMA_INTSTAT2_CH12_Msk & (_UINT32_(value) << DMA_INTSTAT2_CH12_Pos)) /* Assigment of value for CH12 in the DMA_INTSTAT2 register */
#define DMA_INTSTAT2_CH13_Pos                 _UINT32_(13)                                         /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Position */
#define DMA_INTSTAT2_CH13_Msk                 (_UINT32_(0x1) << DMA_INTSTAT2_CH13_Pos)             /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Mask */
#define DMA_INTSTAT2_CH13(value)              (DMA_INTSTAT2_CH13_Msk & (_UINT32_(value) << DMA_INTSTAT2_CH13_Pos)) /* Assigment of value for CH13 in the DMA_INTSTAT2 register */
#define DMA_INTSTAT2_CH14_Pos                 _UINT32_(14)                                         /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Position */
#define DMA_INTSTAT2_CH14_Msk                 (_UINT32_(0x1) << DMA_INTSTAT2_CH14_Pos)             /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Mask */
#define DMA_INTSTAT2_CH14(value)              (DMA_INTSTAT2_CH14_Msk & (_UINT32_(value) << DMA_INTSTAT2_CH14_Pos)) /* Assigment of value for CH14 in the DMA_INTSTAT2 register */
#define DMA_INTSTAT2_CH15_Pos                 _UINT32_(15)                                         /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Position */
#define DMA_INTSTAT2_CH15_Msk                 (_UINT32_(0x1) << DMA_INTSTAT2_CH15_Pos)             /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Mask */
#define DMA_INTSTAT2_CH15(value)              (DMA_INTSTAT2_CH15_Msk & (_UINT32_(value) << DMA_INTSTAT2_CH15_Pos)) /* Assigment of value for CH15 in the DMA_INTSTAT2 register */
#define DMA_INTSTAT2_CH16_Pos                 _UINT32_(16)                                         /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Position */
#define DMA_INTSTAT2_CH16_Msk                 (_UINT32_(0x1) << DMA_INTSTAT2_CH16_Pos)             /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Mask */
#define DMA_INTSTAT2_CH16(value)              (DMA_INTSTAT2_CH16_Msk & (_UINT32_(value) << DMA_INTSTAT2_CH16_Pos)) /* Assigment of value for CH16 in the DMA_INTSTAT2 register */
#define DMA_INTSTAT2_CH17_Pos                 _UINT32_(17)                                         /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Position */
#define DMA_INTSTAT2_CH17_Msk                 (_UINT32_(0x1) << DMA_INTSTAT2_CH17_Pos)             /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Mask */
#define DMA_INTSTAT2_CH17(value)              (DMA_INTSTAT2_CH17_Msk & (_UINT32_(value) << DMA_INTSTAT2_CH17_Pos)) /* Assigment of value for CH17 in the DMA_INTSTAT2 register */
#define DMA_INTSTAT2_CH18_Pos                 _UINT32_(18)                                         /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Position */
#define DMA_INTSTAT2_CH18_Msk                 (_UINT32_(0x1) << DMA_INTSTAT2_CH18_Pos)             /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Mask */
#define DMA_INTSTAT2_CH18(value)              (DMA_INTSTAT2_CH18_Msk & (_UINT32_(value) << DMA_INTSTAT2_CH18_Pos)) /* Assigment of value for CH18 in the DMA_INTSTAT2 register */
#define DMA_INTSTAT2_CH19_Pos                 _UINT32_(19)                                         /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Position */
#define DMA_INTSTAT2_CH19_Msk                 (_UINT32_(0x1) << DMA_INTSTAT2_CH19_Pos)             /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Mask */
#define DMA_INTSTAT2_CH19(value)              (DMA_INTSTAT2_CH19_Msk & (_UINT32_(value) << DMA_INTSTAT2_CH19_Pos)) /* Assigment of value for CH19 in the DMA_INTSTAT2 register */
#define DMA_INTSTAT2_CH20_Pos                 _UINT32_(20)                                         /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Position */
#define DMA_INTSTAT2_CH20_Msk                 (_UINT32_(0x1) << DMA_INTSTAT2_CH20_Pos)             /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Mask */
#define DMA_INTSTAT2_CH20(value)              (DMA_INTSTAT2_CH20_Msk & (_UINT32_(value) << DMA_INTSTAT2_CH20_Pos)) /* Assigment of value for CH20 in the DMA_INTSTAT2 register */
#define DMA_INTSTAT2_CH21_Pos                 _UINT32_(21)                                         /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Position */
#define DMA_INTSTAT2_CH21_Msk                 (_UINT32_(0x1) << DMA_INTSTAT2_CH21_Pos)             /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Mask */
#define DMA_INTSTAT2_CH21(value)              (DMA_INTSTAT2_CH21_Msk & (_UINT32_(value) << DMA_INTSTAT2_CH21_Pos)) /* Assigment of value for CH21 in the DMA_INTSTAT2 register */
#define DMA_INTSTAT2_CH22_Pos                 _UINT32_(22)                                         /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Position */
#define DMA_INTSTAT2_CH22_Msk                 (_UINT32_(0x1) << DMA_INTSTAT2_CH22_Pos)             /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Mask */
#define DMA_INTSTAT2_CH22(value)              (DMA_INTSTAT2_CH22_Msk & (_UINT32_(value) << DMA_INTSTAT2_CH22_Pos)) /* Assigment of value for CH22 in the DMA_INTSTAT2 register */
#define DMA_INTSTAT2_CH23_Pos                 _UINT32_(23)                                         /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Position */
#define DMA_INTSTAT2_CH23_Msk                 (_UINT32_(0x1) << DMA_INTSTAT2_CH23_Pos)             /* (DMA_INTSTAT2) DMA Channel active interrupt at priority 2 Mask */
#define DMA_INTSTAT2_CH23(value)              (DMA_INTSTAT2_CH23_Msk & (_UINT32_(value) << DMA_INTSTAT2_CH23_Pos)) /* Assigment of value for CH23 in the DMA_INTSTAT2 register */
#define DMA_INTSTAT2_Msk                      _UINT32_(0x00FFFFFF)                                 /* (DMA_INTSTAT2) Register Mask  */

#define DMA_INTSTAT2_CH_Pos                   _UINT32_(0)                                          /* (DMA_INTSTAT2 Position) DMA Channel active interrupt at priority 2 */
#define DMA_INTSTAT2_CH_Msk                   (_UINT32_(0xFFFFFF) << DMA_INTSTAT2_CH_Pos)          /* (DMA_INTSTAT2 Mask) CH */
#define DMA_INTSTAT2_CH(value)                (DMA_INTSTAT2_CH_Msk & (_UINT32_(value) << DMA_INTSTAT2_CH_Pos)) 

/* -------- DMA_INTSTAT1 : (DMA Offset: 0x20) ( R/ 32) DMA INTERRUPT PRIORITY 1 STATUS REGISTER -------- */
#define DMA_INTSTAT1_RESETVALUE               _UINT32_(0x00)                                       /*  (DMA_INTSTAT1) DMA INTERRUPT PRIORITY 1 STATUS REGISTER  Reset Value */

#define DMA_INTSTAT1_CH0_Pos                  _UINT32_(0)                                          /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Position */
#define DMA_INTSTAT1_CH0_Msk                  (_UINT32_(0x1) << DMA_INTSTAT1_CH0_Pos)              /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Mask */
#define DMA_INTSTAT1_CH0(value)               (DMA_INTSTAT1_CH0_Msk & (_UINT32_(value) << DMA_INTSTAT1_CH0_Pos)) /* Assigment of value for CH0 in the DMA_INTSTAT1 register */
#define DMA_INTSTAT1_CH1_Pos                  _UINT32_(1)                                          /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Position */
#define DMA_INTSTAT1_CH1_Msk                  (_UINT32_(0x1) << DMA_INTSTAT1_CH1_Pos)              /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Mask */
#define DMA_INTSTAT1_CH1(value)               (DMA_INTSTAT1_CH1_Msk & (_UINT32_(value) << DMA_INTSTAT1_CH1_Pos)) /* Assigment of value for CH1 in the DMA_INTSTAT1 register */
#define DMA_INTSTAT1_CH2_Pos                  _UINT32_(2)                                          /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Position */
#define DMA_INTSTAT1_CH2_Msk                  (_UINT32_(0x1) << DMA_INTSTAT1_CH2_Pos)              /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Mask */
#define DMA_INTSTAT1_CH2(value)               (DMA_INTSTAT1_CH2_Msk & (_UINT32_(value) << DMA_INTSTAT1_CH2_Pos)) /* Assigment of value for CH2 in the DMA_INTSTAT1 register */
#define DMA_INTSTAT1_CH3_Pos                  _UINT32_(3)                                          /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Position */
#define DMA_INTSTAT1_CH3_Msk                  (_UINT32_(0x1) << DMA_INTSTAT1_CH3_Pos)              /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Mask */
#define DMA_INTSTAT1_CH3(value)               (DMA_INTSTAT1_CH3_Msk & (_UINT32_(value) << DMA_INTSTAT1_CH3_Pos)) /* Assigment of value for CH3 in the DMA_INTSTAT1 register */
#define DMA_INTSTAT1_CH4_Pos                  _UINT32_(4)                                          /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Position */
#define DMA_INTSTAT1_CH4_Msk                  (_UINT32_(0x1) << DMA_INTSTAT1_CH4_Pos)              /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Mask */
#define DMA_INTSTAT1_CH4(value)               (DMA_INTSTAT1_CH4_Msk & (_UINT32_(value) << DMA_INTSTAT1_CH4_Pos)) /* Assigment of value for CH4 in the DMA_INTSTAT1 register */
#define DMA_INTSTAT1_CH5_Pos                  _UINT32_(5)                                          /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Position */
#define DMA_INTSTAT1_CH5_Msk                  (_UINT32_(0x1) << DMA_INTSTAT1_CH5_Pos)              /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Mask */
#define DMA_INTSTAT1_CH5(value)               (DMA_INTSTAT1_CH5_Msk & (_UINT32_(value) << DMA_INTSTAT1_CH5_Pos)) /* Assigment of value for CH5 in the DMA_INTSTAT1 register */
#define DMA_INTSTAT1_CH6_Pos                  _UINT32_(6)                                          /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Position */
#define DMA_INTSTAT1_CH6_Msk                  (_UINT32_(0x1) << DMA_INTSTAT1_CH6_Pos)              /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Mask */
#define DMA_INTSTAT1_CH6(value)               (DMA_INTSTAT1_CH6_Msk & (_UINT32_(value) << DMA_INTSTAT1_CH6_Pos)) /* Assigment of value for CH6 in the DMA_INTSTAT1 register */
#define DMA_INTSTAT1_CH7_Pos                  _UINT32_(7)                                          /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Position */
#define DMA_INTSTAT1_CH7_Msk                  (_UINT32_(0x1) << DMA_INTSTAT1_CH7_Pos)              /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Mask */
#define DMA_INTSTAT1_CH7(value)               (DMA_INTSTAT1_CH7_Msk & (_UINT32_(value) << DMA_INTSTAT1_CH7_Pos)) /* Assigment of value for CH7 in the DMA_INTSTAT1 register */
#define DMA_INTSTAT1_CH8_Pos                  _UINT32_(8)                                          /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Position */
#define DMA_INTSTAT1_CH8_Msk                  (_UINT32_(0x1) << DMA_INTSTAT1_CH8_Pos)              /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Mask */
#define DMA_INTSTAT1_CH8(value)               (DMA_INTSTAT1_CH8_Msk & (_UINT32_(value) << DMA_INTSTAT1_CH8_Pos)) /* Assigment of value for CH8 in the DMA_INTSTAT1 register */
#define DMA_INTSTAT1_CH9_Pos                  _UINT32_(9)                                          /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Position */
#define DMA_INTSTAT1_CH9_Msk                  (_UINT32_(0x1) << DMA_INTSTAT1_CH9_Pos)              /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Mask */
#define DMA_INTSTAT1_CH9(value)               (DMA_INTSTAT1_CH9_Msk & (_UINT32_(value) << DMA_INTSTAT1_CH9_Pos)) /* Assigment of value for CH9 in the DMA_INTSTAT1 register */
#define DMA_INTSTAT1_CH10_Pos                 _UINT32_(10)                                         /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Position */
#define DMA_INTSTAT1_CH10_Msk                 (_UINT32_(0x1) << DMA_INTSTAT1_CH10_Pos)             /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Mask */
#define DMA_INTSTAT1_CH10(value)              (DMA_INTSTAT1_CH10_Msk & (_UINT32_(value) << DMA_INTSTAT1_CH10_Pos)) /* Assigment of value for CH10 in the DMA_INTSTAT1 register */
#define DMA_INTSTAT1_CH11_Pos                 _UINT32_(11)                                         /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Position */
#define DMA_INTSTAT1_CH11_Msk                 (_UINT32_(0x1) << DMA_INTSTAT1_CH11_Pos)             /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Mask */
#define DMA_INTSTAT1_CH11(value)              (DMA_INTSTAT1_CH11_Msk & (_UINT32_(value) << DMA_INTSTAT1_CH11_Pos)) /* Assigment of value for CH11 in the DMA_INTSTAT1 register */
#define DMA_INTSTAT1_CH12_Pos                 _UINT32_(12)                                         /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Position */
#define DMA_INTSTAT1_CH12_Msk                 (_UINT32_(0x1) << DMA_INTSTAT1_CH12_Pos)             /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Mask */
#define DMA_INTSTAT1_CH12(value)              (DMA_INTSTAT1_CH12_Msk & (_UINT32_(value) << DMA_INTSTAT1_CH12_Pos)) /* Assigment of value for CH12 in the DMA_INTSTAT1 register */
#define DMA_INTSTAT1_CH13_Pos                 _UINT32_(13)                                         /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Position */
#define DMA_INTSTAT1_CH13_Msk                 (_UINT32_(0x1) << DMA_INTSTAT1_CH13_Pos)             /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Mask */
#define DMA_INTSTAT1_CH13(value)              (DMA_INTSTAT1_CH13_Msk & (_UINT32_(value) << DMA_INTSTAT1_CH13_Pos)) /* Assigment of value for CH13 in the DMA_INTSTAT1 register */
#define DMA_INTSTAT1_CH14_Pos                 _UINT32_(14)                                         /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Position */
#define DMA_INTSTAT1_CH14_Msk                 (_UINT32_(0x1) << DMA_INTSTAT1_CH14_Pos)             /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Mask */
#define DMA_INTSTAT1_CH14(value)              (DMA_INTSTAT1_CH14_Msk & (_UINT32_(value) << DMA_INTSTAT1_CH14_Pos)) /* Assigment of value for CH14 in the DMA_INTSTAT1 register */
#define DMA_INTSTAT1_CH15_Pos                 _UINT32_(15)                                         /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Position */
#define DMA_INTSTAT1_CH15_Msk                 (_UINT32_(0x1) << DMA_INTSTAT1_CH15_Pos)             /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Mask */
#define DMA_INTSTAT1_CH15(value)              (DMA_INTSTAT1_CH15_Msk & (_UINT32_(value) << DMA_INTSTAT1_CH15_Pos)) /* Assigment of value for CH15 in the DMA_INTSTAT1 register */
#define DMA_INTSTAT1_CH16_Pos                 _UINT32_(16)                                         /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Position */
#define DMA_INTSTAT1_CH16_Msk                 (_UINT32_(0x1) << DMA_INTSTAT1_CH16_Pos)             /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Mask */
#define DMA_INTSTAT1_CH16(value)              (DMA_INTSTAT1_CH16_Msk & (_UINT32_(value) << DMA_INTSTAT1_CH16_Pos)) /* Assigment of value for CH16 in the DMA_INTSTAT1 register */
#define DMA_INTSTAT1_CH17_Pos                 _UINT32_(17)                                         /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Position */
#define DMA_INTSTAT1_CH17_Msk                 (_UINT32_(0x1) << DMA_INTSTAT1_CH17_Pos)             /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Mask */
#define DMA_INTSTAT1_CH17(value)              (DMA_INTSTAT1_CH17_Msk & (_UINT32_(value) << DMA_INTSTAT1_CH17_Pos)) /* Assigment of value for CH17 in the DMA_INTSTAT1 register */
#define DMA_INTSTAT1_CH18_Pos                 _UINT32_(18)                                         /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Position */
#define DMA_INTSTAT1_CH18_Msk                 (_UINT32_(0x1) << DMA_INTSTAT1_CH18_Pos)             /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Mask */
#define DMA_INTSTAT1_CH18(value)              (DMA_INTSTAT1_CH18_Msk & (_UINT32_(value) << DMA_INTSTAT1_CH18_Pos)) /* Assigment of value for CH18 in the DMA_INTSTAT1 register */
#define DMA_INTSTAT1_CH19_Pos                 _UINT32_(19)                                         /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Position */
#define DMA_INTSTAT1_CH19_Msk                 (_UINT32_(0x1) << DMA_INTSTAT1_CH19_Pos)             /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Mask */
#define DMA_INTSTAT1_CH19(value)              (DMA_INTSTAT1_CH19_Msk & (_UINT32_(value) << DMA_INTSTAT1_CH19_Pos)) /* Assigment of value for CH19 in the DMA_INTSTAT1 register */
#define DMA_INTSTAT1_CH20_Pos                 _UINT32_(20)                                         /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Position */
#define DMA_INTSTAT1_CH20_Msk                 (_UINT32_(0x1) << DMA_INTSTAT1_CH20_Pos)             /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Mask */
#define DMA_INTSTAT1_CH20(value)              (DMA_INTSTAT1_CH20_Msk & (_UINT32_(value) << DMA_INTSTAT1_CH20_Pos)) /* Assigment of value for CH20 in the DMA_INTSTAT1 register */
#define DMA_INTSTAT1_CH21_Pos                 _UINT32_(21)                                         /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Position */
#define DMA_INTSTAT1_CH21_Msk                 (_UINT32_(0x1) << DMA_INTSTAT1_CH21_Pos)             /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Mask */
#define DMA_INTSTAT1_CH21(value)              (DMA_INTSTAT1_CH21_Msk & (_UINT32_(value) << DMA_INTSTAT1_CH21_Pos)) /* Assigment of value for CH21 in the DMA_INTSTAT1 register */
#define DMA_INTSTAT1_CH22_Pos                 _UINT32_(22)                                         /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Position */
#define DMA_INTSTAT1_CH22_Msk                 (_UINT32_(0x1) << DMA_INTSTAT1_CH22_Pos)             /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Mask */
#define DMA_INTSTAT1_CH22(value)              (DMA_INTSTAT1_CH22_Msk & (_UINT32_(value) << DMA_INTSTAT1_CH22_Pos)) /* Assigment of value for CH22 in the DMA_INTSTAT1 register */
#define DMA_INTSTAT1_CH23_Pos                 _UINT32_(23)                                         /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Position */
#define DMA_INTSTAT1_CH23_Msk                 (_UINT32_(0x1) << DMA_INTSTAT1_CH23_Pos)             /* (DMA_INTSTAT1) DMA Channel active interrupt at priority 1 Mask */
#define DMA_INTSTAT1_CH23(value)              (DMA_INTSTAT1_CH23_Msk & (_UINT32_(value) << DMA_INTSTAT1_CH23_Pos)) /* Assigment of value for CH23 in the DMA_INTSTAT1 register */
#define DMA_INTSTAT1_Msk                      _UINT32_(0x00FFFFFF)                                 /* (DMA_INTSTAT1) Register Mask  */

#define DMA_INTSTAT1_CH_Pos                   _UINT32_(0)                                          /* (DMA_INTSTAT1 Position) DMA Channel active interrupt at priority x */
#define DMA_INTSTAT1_CH_Msk                   (_UINT32_(0xFFFFFF) << DMA_INTSTAT1_CH_Pos)          /* (DMA_INTSTAT1 Mask) CH */
#define DMA_INTSTAT1_CH(value)                (DMA_INTSTAT1_CH_Msk & (_UINT32_(value) << DMA_INTSTAT1_CH_Pos)) 

/** \brief DMA register offsets definitions */
#define DMA_BDNXT_REG_OFST             _UINT32_(0x00)      /* (DMA_BDNXT) NEXT BUFFER DESCRIPTOR ADDRESS POINTER Offset */
#define DMA_BDCFG_REG_OFST             _UINT32_(0x04)      /* (DMA_BDCFG) CURRENT BUFFER DESCRIPTOR CONFIGURATION Offset */
#define DMA_BDCTRLB_REG_OFST           _UINT32_(0x08)      /* (DMA_BDCTRLB) CURRENT BUFFER DESCRIPTOR CONTROL REGISTER B Offset */
#define DMA_BDEVCTRL_REG_OFST          _UINT32_(0x0C)      /* (DMA_BDEVCTRL) CURRENT BUFFER DESCRIPTOR EVENT CONTROL Offset */
#define DMA_BDCTRLCRC_REG_OFST         _UINT32_(0x0E)      /* (DMA_BDCTRLCRC) CURRENT BUFFER DESCRIPTOR CRC CONTROL Offset */
#define DMA_BDSSA_REG_OFST             _UINT32_(0x10)      /* (DMA_BDSSA) CURRENT BUFFER DESCRIPTOR SOURCE START ADDRESS Offset */
#define DMA_BDDSA_REG_OFST             _UINT32_(0x14)      /* (DMA_BDDSA) CURRENT BUFFER DESCRIPTOR DESTINATION START ADDRESS Offset */
#define DMA_BDSSTRD_REG_OFST           _UINT32_(0x18)      /* (DMA_BDSSTRD) CURRENT BUFFER DESCRIPTOR SOURCE CELL STRIDE Offset */
#define DMA_BDDSTRD_REG_OFST           _UINT32_(0x1A)      /* (DMA_BDDSTRD) CURRENT BUFFER DESCRIPTOR DESTINATION CELL STRIDE Offset */
#define DMA_BDXSIZ_REG_OFST            _UINT32_(0x1C)      /* (DMA_BDXSIZ) CURRENT BUFFER DESCRIPTOR TRANSFER SIZE Offset */
#define DMA_BDPDAT_REG_OFST            _UINT32_(0x20)      /* (DMA_BDPDAT) CURRENT BUFFER DESCRIPTOR PATTERN MATCH DATA Offset */
#define DMA_BDCRCDAT_REG_OFST          _UINT32_(0x24)      /* (DMA_BDCRCDAT) CURRENT BUFFER DESCRIPTOR CRC/CHECKSUM DATA Offset */
#define DMA_CHCTRLA_REG_OFST           _UINT32_(0x00)      /* (DMA_CHCTRLA) CHANNEL CONTROL REGISTER A Offset */
#define DMA_CHCTRLB_REG_OFST           _UINT32_(0x04)      /* (DMA_CHCTRLB) CHANNEL CONTROL REGISTER B Offset */
#define DMA_CHEVCTRL_REG_OFST          _UINT32_(0x08)      /* (DMA_CHEVCTRL) CHANNEL EVENT CONTROL REGISTER Offset */
#define DMA_CHINTENCLR_REG_OFST        _UINT32_(0x0C)      /* (DMA_CHINTENCLR) CHANNEL INTERRUPT ENABLE CLEAR REGISTER Offset */
#define DMA_CHINTENSET_REG_OFST        _UINT32_(0x10)      /* (DMA_CHINTENSET) CHANNEL INTERRUPT ENABLE SET REGISTER Offset */
#define DMA_CHINTF_REG_OFST            _UINT32_(0x14)      /* (DMA_CHINTF) CHANNEL INTERRUPT FLAG REGISTER Offset */
#define DMA_CHSSA_REG_OFST             _UINT32_(0x18)      /* (DMA_CHSSA) CHANNEL SOURCE START ADDRESS Offset */
#define DMA_CHDSA_REG_OFST             _UINT32_(0x1C)      /* (DMA_CHDSA) CHANNEL DESTINATION START ADDRESS Offset */
#define DMA_CHSSTRD_REG_OFST           _UINT32_(0x20)      /* (DMA_CHSSTRD) CHANNEL SOURCE CELL STRIDE SIZE REGISTER Offset */
#define DMA_CHDSTRD_REG_OFST           _UINT32_(0x24)      /* (DMA_CHDSTRD) CHANNEL DESTINATION CELL STRIDE SIZE REGISTER Offset */
#define DMA_CHXSIZ_REG_OFST            _UINT32_(0x28)      /* (DMA_CHXSIZ) CHANNEL TRANSFER SIZE REGISTER Offset */
#define DMA_CHPDAT_REG_OFST            _UINT32_(0x2C)      /* (DMA_CHPDAT) CHANNEL PATTERN MATCH DATA Offset */
#define DMA_CHCTRLCRC_REG_OFST         _UINT32_(0x30)      /* (DMA_CHCTRLCRC) CHANNEL CONTROL CRC Offset */
#define DMA_CHCRCDAT_REG_OFST          _UINT32_(0x34)      /* (DMA_CHCRCDAT) CHANNEL CRC/CHECKSUM DATA REGISTER Offset */
#define DMA_CHNXT_REG_OFST             _UINT32_(0x38)      /* (DMA_CHNXT) CHANNEL NEXT DESCRIPTOR ADDRESS POINTER Offset */
#define DMA_CHLLCFGSTAT_REG_OFST       _UINT32_(0x3C)      /* (DMA_CHLLCFGSTAT) CHANNEL LINKED LIST CONFIGURATION STATUS REGISTER Offset */
#define DMA_CHSTATBC_REG_OFST          _UINT32_(0x40)      /* (DMA_CHSTATBC) CHANNEL STATUS BLOCK COUNT REGISTER Offset */
#define DMA_CHSTATCC_REG_OFST          _UINT32_(0x44)      /* (DMA_CHSTATCC) CHANNEL STATUS CELL COUNT REGISTER Offset */
#define DMA_CHSTAT_REG_OFST            _UINT32_(0x48)      /* (DMA_CHSTAT) CHANNEL STATUS REGISTER Offset */
#define DMA_CTRLA_REG_OFST             _UINT32_(0x00)      /* (DMA_CTRLA) DMA CONTROL A REGISTER Offset */
#define DMA_DBGCTRL_REG_OFST           _UINT32_(0x08)      /* (DMA_DBGCTRL) DEBUG CONTROL REGISTER Offset */
#define DMA_CRCPOLYA_REG_OFST          _UINT32_(0x0C)      /* (DMA_CRCPOLYA) DMA CRC POLYNOMIAL A REGISTER Offset */
#define DMA_CRCPOLYB_REG_OFST          _UINT32_(0x10)      /* (DMA_CRCPOLYB) DMA CRC POLYNOMIAL B REGISTER Offset */
#define DMA_INTSTAT4_REG_OFST          _UINT32_(0x14)      /* (DMA_INTSTAT4) DMA INTERRUPT PRIORITY 4 STATUS REGISTER Offset */
#define DMA_INTSTAT3_REG_OFST          _UINT32_(0x18)      /* (DMA_INTSTAT3) DMA INTERRUPT PRIORITY 3 STATUS REGISTER Offset */
#define DMA_INTSTAT2_REG_OFST          _UINT32_(0x1C)      /* (DMA_INTSTAT2) DMA INTERRUPT PRIORITY 2 STATUS REGISTER Offset */
#define DMA_INTSTAT1_REG_OFST          _UINT32_(0x20)      /* (DMA_INTSTAT1) DMA INTERRUPT PRIORITY 1 STATUS REGISTER Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief DMA_DESCRIPTOR register API structure */
typedef struct
{  /* Direct Memory Access Controller */
  __IO  uint32_t                       DMA_BDNXT;          /**< Offset: 0x00 (R/W  32) NEXT BUFFER DESCRIPTOR ADDRESS POINTER */
  __IO  uint32_t                       DMA_BDCFG;          /**< Offset: 0x04 (R/W  32) CURRENT BUFFER DESCRIPTOR CONFIGURATION */
  __IO  uint32_t                       DMA_BDCTRLB;        /**< Offset: 0x08 (R/W  32) CURRENT BUFFER DESCRIPTOR CONTROL REGISTER B */
  __IO  uint16_t                       DMA_BDEVCTRL;       /**< Offset: 0x0C (R/W  16) CURRENT BUFFER DESCRIPTOR EVENT CONTROL */
  __IO  uint16_t                       DMA_BDCTRLCRC;      /**< Offset: 0x0E (R/W  16) CURRENT BUFFER DESCRIPTOR CRC CONTROL */
  __IO  uint32_t                       DMA_BDSSA;          /**< Offset: 0x10 (R/W  32) CURRENT BUFFER DESCRIPTOR SOURCE START ADDRESS */
  __IO  uint32_t                       DMA_BDDSA;          /**< Offset: 0x14 (R/W  32) CURRENT BUFFER DESCRIPTOR DESTINATION START ADDRESS */
  __IO  uint16_t                       DMA_BDSSTRD;        /**< Offset: 0x18 (R/W  16) CURRENT BUFFER DESCRIPTOR SOURCE CELL STRIDE */
  __IO  uint16_t                       DMA_BDDSTRD;        /**< Offset: 0x1A (R/W  16) CURRENT BUFFER DESCRIPTOR DESTINATION CELL STRIDE */
  __IO  uint32_t                       DMA_BDXSIZ;         /**< Offset: 0x1C (R/W  32) CURRENT BUFFER DESCRIPTOR TRANSFER SIZE */
  __IO  uint32_t                       DMA_BDPDAT;         /**< Offset: 0x20 (R/W  32) CURRENT BUFFER DESCRIPTOR PATTERN MATCH DATA */
  __IO  uint32_t                       DMA_BDCRCDAT;       /**< Offset: 0x24 (R/W  32) CURRENT BUFFER DESCRIPTOR CRC/CHECKSUM DATA */
} dma_descriptor_registers_t
#ifdef __GNUC__
  __attribute__ ((aligned (4)))
#endif
;

/** \brief CHANNEL register API structure */
typedef struct
{
  __IO  uint32_t                       DMA_CHCTRLA;        /**< Offset: 0x00 (R/W  32) CHANNEL CONTROL REGISTER A */
  __IO  uint32_t                       DMA_CHCTRLB;        /**< Offset: 0x04 (R/W  32) CHANNEL CONTROL REGISTER B */
  __IO  uint32_t                       DMA_CHEVCTRL;       /**< Offset: 0x08 (R/W  32) CHANNEL EVENT CONTROL REGISTER */
  __IO  uint32_t                       DMA_CHINTENCLR;     /**< Offset: 0x0C (R/W  32) CHANNEL INTERRUPT ENABLE CLEAR REGISTER */
  __IO  uint32_t                       DMA_CHINTENSET;     /**< Offset: 0x10 (R/W  32) CHANNEL INTERRUPT ENABLE SET REGISTER */
  __IO  uint32_t                       DMA_CHINTF;         /**< Offset: 0x14 (R/W  32) CHANNEL INTERRUPT FLAG REGISTER */
  __IO  uint32_t                       DMA_CHSSA;          /**< Offset: 0x18 (R/W  32) CHANNEL SOURCE START ADDRESS */
  __IO  uint32_t                       DMA_CHDSA;          /**< Offset: 0x1C (R/W  32) CHANNEL DESTINATION START ADDRESS */
  __IO  uint32_t                       DMA_CHSSTRD;        /**< Offset: 0x20 (R/W  32) CHANNEL SOURCE CELL STRIDE SIZE REGISTER */
  __IO  uint32_t                       DMA_CHDSTRD;        /**< Offset: 0x24 (R/W  32) CHANNEL DESTINATION CELL STRIDE SIZE REGISTER */
  __IO  uint32_t                       DMA_CHXSIZ;         /**< Offset: 0x28 (R/W  32) CHANNEL TRANSFER SIZE REGISTER */
  __IO  uint32_t                       DMA_CHPDAT;         /**< Offset: 0x2C (R/W  32) CHANNEL PATTERN MATCH DATA */
  __IO  uint32_t                       DMA_CHCTRLCRC;      /**< Offset: 0x30 (R/W  32) CHANNEL CONTROL CRC */
  __IO  uint32_t                       DMA_CHCRCDAT;       /**< Offset: 0x34 (R/W  32) CHANNEL CRC/CHECKSUM DATA REGISTER */
  __IO  uint32_t                       DMA_CHNXT;          /**< Offset: 0x38 (R/W  32) CHANNEL NEXT DESCRIPTOR ADDRESS POINTER */
  __I   uint32_t                       DMA_CHLLCFGSTAT;    /**< Offset: 0x3C (R/   32) CHANNEL LINKED LIST CONFIGURATION STATUS REGISTER */
  __I   uint32_t                       DMA_CHSTATBC;       /**< Offset: 0x40 (R/   32) CHANNEL STATUS BLOCK COUNT REGISTER */
  __I   uint32_t                       DMA_CHSTATCC;       /**< Offset: 0x44 (R/   32) CHANNEL STATUS CELL COUNT REGISTER */
  __I   uint32_t                       DMA_CHSTAT;         /**< Offset: 0x48 (R/   32) CHANNEL STATUS REGISTER */
  __I   uint8_t                        Reserved1[0x04];
} dma_channel_registers_t;

#define DMA_CHANNEL_NUMBER 16

/** \brief DMA register API structure */
typedef struct
{  /* Direct Memory Access Controller */
  __IO  uint32_t                       DMA_CTRLA;          /**< Offset: 0x00 (R/W  32) DMA CONTROL A REGISTER */
  __I   uint8_t                        Reserved1[0x04];
  __IO  uint32_t                       DMA_DBGCTRL;        /**< Offset: 0x08 (R/W  32) DEBUG CONTROL REGISTER */
  __IO  uint32_t                       DMA_CRCPOLYA;       /**< Offset: 0x0C (R/W  32) DMA CRC POLYNOMIAL A REGISTER */
  __IO  uint32_t                       DMA_CRCPOLYB;       /**< Offset: 0x10 (R/W  32) DMA CRC POLYNOMIAL B REGISTER */
  __I   uint32_t                       DMA_INTSTAT4;       /**< Offset: 0x14 (R/   32) DMA INTERRUPT PRIORITY 4 STATUS REGISTER */
  __I   uint32_t                       DMA_INTSTAT3;       /**< Offset: 0x18 (R/   32) DMA INTERRUPT PRIORITY 3 STATUS REGISTER */
  __I   uint32_t                       DMA_INTSTAT2;       /**< Offset: 0x1C (R/   32) DMA INTERRUPT PRIORITY 2 STATUS REGISTER */
  __I   uint32_t                       DMA_INTSTAT1;       /**< Offset: 0x20 (R/   32) DMA INTERRUPT PRIORITY 1 STATUS REGISTER */
  __I   uint8_t                        Reserved2[0x2C];
        dma_channel_registers_t        CHANNEL[DMA_CHANNEL_NUMBER]; /**< Offset: 0x50  */
} dma_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
/** \brief DMA_DESCRIPTOR memory section attribute */
#if defined (__GNUC__) || defined (__CC_ARM)
 #define SECTION_DMA_DESCRIPTOR       __attribute__ ((section(".flexram")))
#elif defined (__ICCARM__)
 #define SECTION_DMA_DESCRIPTOR       @".flexram"
#else
 #ifndef SECTION_DMA_DESCRIPTOR
  #error SECTION_DMA_DESCRIPTOR must be defined for compiler to use memory section .flexram
 #endif
#endif

#endif /* _PIC32CZCA90_DMA_COMPONENT_H_ */
