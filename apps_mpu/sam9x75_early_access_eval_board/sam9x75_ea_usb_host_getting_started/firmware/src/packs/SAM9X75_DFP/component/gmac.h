/*
 * Component description for GMAC
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

/* file generated from device description version 2023-01-20T08:33:42Z */
#ifndef _SAM9X7_GMAC_COMPONENT_H_
#define _SAM9X7_GMAC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR GMAC                                         */
/* ************************************************************************** */

/* -------- GMAC_EMAC_ASAB : (GMAC Offset: 0x00) (R/W 32) Express MAC Additional Specific Address Bottom Register  -------- */
#define GMAC_EMAC_ASAB_RESETVALUE             _UINT32_(0x00)                                       /*  (GMAC_EMAC_ASAB) Express MAC Additional Specific Address Bottom Register   Reset Value */

#define GMAC_EMAC_ASAB_ADDR_Pos               _UINT32_(0)                                          /* (GMAC_EMAC_ASAB) Specific Address Position */
#define GMAC_EMAC_ASAB_ADDR_Msk               (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_ASAB_ADDR_Pos)    /* (GMAC_EMAC_ASAB) Specific Address Mask */
#define GMAC_EMAC_ASAB_ADDR(value)            (GMAC_EMAC_ASAB_ADDR_Msk & (_UINT32_(value) << GMAC_EMAC_ASAB_ADDR_Pos)) /* Assigment of value for ADDR in the GMAC_EMAC_ASAB register */
#define GMAC_EMAC_ASAB_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_ASAB) Register Mask  */


/* -------- GMAC_EMAC_ASAT : (GMAC Offset: 0x04) (R/W 32) Express MAC Additional Specific Address Top Register  -------- */
#define GMAC_EMAC_ASAT_RESETVALUE             _UINT32_(0x00)                                       /*  (GMAC_EMAC_ASAT) Express MAC Additional Specific Address Top Register   Reset Value */

#define GMAC_EMAC_ASAT_ADDR_Pos               _UINT32_(0)                                          /* (GMAC_EMAC_ASAT) Specific Address Position */
#define GMAC_EMAC_ASAT_ADDR_Msk               (_UINT32_(0xFFFF) << GMAC_EMAC_ASAT_ADDR_Pos)        /* (GMAC_EMAC_ASAT) Specific Address Mask */
#define GMAC_EMAC_ASAT_ADDR(value)            (GMAC_EMAC_ASAT_ADDR_Msk & (_UINT32_(value) << GMAC_EMAC_ASAT_ADDR_Pos)) /* Assigment of value for ADDR in the GMAC_EMAC_ASAT register */
#define GMAC_EMAC_ASAT_FILTSORD_Pos           _UINT32_(16)                                         /* (GMAC_EMAC_ASAT) Filter Source or Destination MAC Address Position */
#define GMAC_EMAC_ASAT_FILTSORD_Msk           (_UINT32_(0x1) << GMAC_EMAC_ASAT_FILTSORD_Pos)       /* (GMAC_EMAC_ASAT) Filter Source or Destination MAC Address Mask */
#define GMAC_EMAC_ASAT_FILTSORD(value)        (GMAC_EMAC_ASAT_FILTSORD_Msk & (_UINT32_(value) << GMAC_EMAC_ASAT_FILTSORD_Pos)) /* Assigment of value for FILTSORD in the GMAC_EMAC_ASAT register */
#define   GMAC_EMAC_ASAT_FILTSORD_0_Val       _UINT32_(0x0)                                        /* (GMAC_EMAC_ASAT) The filter is a destination address filter.  */
#define   GMAC_EMAC_ASAT_FILTSORD_1_Val       _UINT32_(0x1)                                        /* (GMAC_EMAC_ASAT) The filter is a source address filter.  */
#define GMAC_EMAC_ASAT_FILTSORD_0             (GMAC_EMAC_ASAT_FILTSORD_0_Val << GMAC_EMAC_ASAT_FILTSORD_Pos) /* (GMAC_EMAC_ASAT) The filter is a destination address filter. Position  */
#define GMAC_EMAC_ASAT_FILTSORD_1             (GMAC_EMAC_ASAT_FILTSORD_1_Val << GMAC_EMAC_ASAT_FILTSORD_Pos) /* (GMAC_EMAC_ASAT) The filter is a source address filter. Position  */
#define GMAC_EMAC_ASAT_FILTBMASK_Pos          _UINT32_(24)                                         /* (GMAC_EMAC_ASAT) Filter Bytes Mask Position */
#define GMAC_EMAC_ASAT_FILTBMASK_Msk          (_UINT32_(0x3F) << GMAC_EMAC_ASAT_FILTBMASK_Pos)     /* (GMAC_EMAC_ASAT) Filter Bytes Mask Mask */
#define GMAC_EMAC_ASAT_FILTBMASK(value)       (GMAC_EMAC_ASAT_FILTBMASK_Msk & (_UINT32_(value) << GMAC_EMAC_ASAT_FILTBMASK_Pos)) /* Assigment of value for FILTBMASK in the GMAC_EMAC_ASAT register */
#define   GMAC_EMAC_ASAT_FILTBMASK_BIT1_Val   _UINT32_(0x1)                                        /* (GMAC_EMAC_ASAT) Controls whether the first byte has been received.  */
#define   GMAC_EMAC_ASAT_FILTBMASK_BIT2_Val   _UINT32_(0x2)                                        /* (GMAC_EMAC_ASAT) Controls whether the second byte has been received.  */
#define   GMAC_EMAC_ASAT_FILTBMASK_BIT3_Val   _UINT32_(0x4)                                        /* (GMAC_EMAC_ASAT) Controls whether the third byte has been received.  */
#define   GMAC_EMAC_ASAT_FILTBMASK_BIT4_Val   _UINT32_(0x8)                                        /* (GMAC_EMAC_ASAT) Controls whether the fourth byte has been received.  */
#define   GMAC_EMAC_ASAT_FILTBMASK_BIT5_Val   _UINT32_(0x10)                                       /* (GMAC_EMAC_ASAT) Controls whether the fifth byte has been received.  */
#define   GMAC_EMAC_ASAT_FILTBMASK_BIT6_Val   _UINT32_(0x20)                                       /* (GMAC_EMAC_ASAT) Controls whether the sixth byte has been received  */
#define GMAC_EMAC_ASAT_FILTBMASK_BIT1         (GMAC_EMAC_ASAT_FILTBMASK_BIT1_Val << GMAC_EMAC_ASAT_FILTBMASK_Pos) /* (GMAC_EMAC_ASAT) Controls whether the first byte has been received. Position  */
#define GMAC_EMAC_ASAT_FILTBMASK_BIT2         (GMAC_EMAC_ASAT_FILTBMASK_BIT2_Val << GMAC_EMAC_ASAT_FILTBMASK_Pos) /* (GMAC_EMAC_ASAT) Controls whether the second byte has been received. Position  */
#define GMAC_EMAC_ASAT_FILTBMASK_BIT3         (GMAC_EMAC_ASAT_FILTBMASK_BIT3_Val << GMAC_EMAC_ASAT_FILTBMASK_Pos) /* (GMAC_EMAC_ASAT) Controls whether the third byte has been received. Position  */
#define GMAC_EMAC_ASAT_FILTBMASK_BIT4         (GMAC_EMAC_ASAT_FILTBMASK_BIT4_Val << GMAC_EMAC_ASAT_FILTBMASK_Pos) /* (GMAC_EMAC_ASAT) Controls whether the fourth byte has been received. Position  */
#define GMAC_EMAC_ASAT_FILTBMASK_BIT5         (GMAC_EMAC_ASAT_FILTBMASK_BIT5_Val << GMAC_EMAC_ASAT_FILTBMASK_Pos) /* (GMAC_EMAC_ASAT) Controls whether the fifth byte has been received. Position  */
#define GMAC_EMAC_ASAT_FILTBMASK_BIT6         (GMAC_EMAC_ASAT_FILTBMASK_BIT6_Val << GMAC_EMAC_ASAT_FILTBMASK_Pos) /* (GMAC_EMAC_ASAT) Controls whether the sixth byte has been received Position  */
#define GMAC_EMAC_ASAT_Msk                    _UINT32_(0x3F01FFFF)                                 /* (GMAC_EMAC_ASAT) Register Mask  */


/* -------- GMAC_EMAC_FRER_CTRLx_A : (GMAC Offset: 0x00) (R/W 32) Express MAC Frame Elimination Control1 A Register -------- */
#define GMAC_EMAC_FRER_CTRLx_A_RESETVALUE     _UINT32_(0x00)                                       /*  (GMAC_EMAC_FRER_CTRLx_A) Express MAC Frame Elimination Control1 A Register  Reset Value */

#define GMAC_EMAC_FRER_CTRLx_A_MEMBER_STREAM_1_Pos _UINT32_(0)                                          /* (GMAC_EMAC_FRER_CTRLx_A) Pointer to Screener Type 2 Register Position */
#define GMAC_EMAC_FRER_CTRLx_A_MEMBER_STREAM_1_Msk (_UINT32_(0xF) << GMAC_EMAC_FRER_CTRLx_A_MEMBER_STREAM_1_Pos) /* (GMAC_EMAC_FRER_CTRLx_A) Pointer to Screener Type 2 Register Mask */
#define GMAC_EMAC_FRER_CTRLx_A_MEMBER_STREAM_1(value) (GMAC_EMAC_FRER_CTRLx_A_MEMBER_STREAM_1_Msk & (_UINT32_(value) << GMAC_EMAC_FRER_CTRLx_A_MEMBER_STREAM_1_Pos)) /* Assigment of value for MEMBER_STREAM_1 in the GMAC_EMAC_FRER_CTRLx_A register */
#define GMAC_EMAC_FRER_CTRLx_A_MEMBER_STREAM_2_Pos _UINT32_(4)                                          /* (GMAC_EMAC_FRER_CTRLx_A) Pointer to Screener Type 2 Register Position */
#define GMAC_EMAC_FRER_CTRLx_A_MEMBER_STREAM_2_Msk (_UINT32_(0xF) << GMAC_EMAC_FRER_CTRLx_A_MEMBER_STREAM_2_Pos) /* (GMAC_EMAC_FRER_CTRLx_A) Pointer to Screener Type 2 Register Mask */
#define GMAC_EMAC_FRER_CTRLx_A_MEMBER_STREAM_2(value) (GMAC_EMAC_FRER_CTRLx_A_MEMBER_STREAM_2_Msk & (_UINT32_(value) << GMAC_EMAC_FRER_CTRLx_A_MEMBER_STREAM_2_Pos)) /* Assigment of value for MEMBER_STREAM_2 in the GMAC_EMAC_FRER_CTRLx_A register */
#define GMAC_EMAC_FRER_CTRLx_A_OFFSET_VALUE_Pos _UINT32_(8)                                          /* (GMAC_EMAC_FRER_CTRLx_A) Offset in Bytes from Start Packet Delimiter to MSB for 802.1CB Sequence Number Position */
#define GMAC_EMAC_FRER_CTRLx_A_OFFSET_VALUE_Msk (_UINT32_(0x1FF) << GMAC_EMAC_FRER_CTRLx_A_OFFSET_VALUE_Pos) /* (GMAC_EMAC_FRER_CTRLx_A) Offset in Bytes from Start Packet Delimiter to MSB for 802.1CB Sequence Number Mask */
#define GMAC_EMAC_FRER_CTRLx_A_OFFSET_VALUE(value) (GMAC_EMAC_FRER_CTRLx_A_OFFSET_VALUE_Msk & (_UINT32_(value) << GMAC_EMAC_FRER_CTRLx_A_OFFSET_VALUE_Pos)) /* Assigment of value for OFFSET_VALUE in the GMAC_EMAC_FRER_CTRLx_A register */
#define GMAC_EMAC_FRER_CTRLx_A_USE_R_TAG_Pos  _UINT32_(28)                                         /* (GMAC_EMAC_FRER_CTRLx_A) Redundancy Tag Enable Position */
#define GMAC_EMAC_FRER_CTRLx_A_USE_R_TAG_Msk  (_UINT32_(0x1) << GMAC_EMAC_FRER_CTRLx_A_USE_R_TAG_Pos) /* (GMAC_EMAC_FRER_CTRLx_A) Redundancy Tag Enable Mask */
#define GMAC_EMAC_FRER_CTRLx_A_USE_R_TAG(value) (GMAC_EMAC_FRER_CTRLx_A_USE_R_TAG_Msk & (_UINT32_(value) << GMAC_EMAC_FRER_CTRLx_A_USE_R_TAG_Pos)) /* Assigment of value for USE_R_TAG in the GMAC_EMAC_FRER_CTRLx_A register */
#define   GMAC_EMAC_FRER_CTRLx_A_USE_R_TAG_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_FRER_CTRLx_A) Identifies bottom of sequence number with OFFSET_VALUE.  */
#define   GMAC_EMAC_FRER_CTRLx_A_USE_R_TAG_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_FRER_CTRLx_A) Identifies sequence number with redundancy tag.  */
#define GMAC_EMAC_FRER_CTRLx_A_USE_R_TAG_0    (GMAC_EMAC_FRER_CTRLx_A_USE_R_TAG_0_Val << GMAC_EMAC_FRER_CTRLx_A_USE_R_TAG_Pos) /* (GMAC_EMAC_FRER_CTRLx_A) Identifies bottom of sequence number with OFFSET_VALUE. Position  */
#define GMAC_EMAC_FRER_CTRLx_A_USE_R_TAG_1    (GMAC_EMAC_FRER_CTRLx_A_USE_R_TAG_1_Val << GMAC_EMAC_FRER_CTRLx_A_USE_R_TAG_Pos) /* (GMAC_EMAC_FRER_CTRLx_A) Identifies sequence number with redundancy tag. Position  */
#define GMAC_EMAC_FRER_CTRLx_A_EN_SEQRECRST_TIMER_Pos _UINT32_(29)                                         /* (GMAC_EMAC_FRER_CTRLx_A) 802.1CB Sequence Recovery Reset Timer Enable Position */
#define GMAC_EMAC_FRER_CTRLx_A_EN_SEQRECRST_TIMER_Msk (_UINT32_(0x1) << GMAC_EMAC_FRER_CTRLx_A_EN_SEQRECRST_TIMER_Pos) /* (GMAC_EMAC_FRER_CTRLx_A) 802.1CB Sequence Recovery Reset Timer Enable Mask */
#define GMAC_EMAC_FRER_CTRLx_A_EN_SEQRECRST_TIMER(value) (GMAC_EMAC_FRER_CTRLx_A_EN_SEQRECRST_TIMER_Msk & (_UINT32_(value) << GMAC_EMAC_FRER_CTRLx_A_EN_SEQRECRST_TIMER_Pos)) /* Assigment of value for EN_SEQRECRST_TIMER in the GMAC_EMAC_FRER_CTRLx_A register */
#define   GMAC_EMAC_FRER_CTRLx_A_EN_SEQRECRST_TIMER_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_FRER_CTRLx_A) Disables the sequence recovery reset timer.  */
#define   GMAC_EMAC_FRER_CTRLx_A_EN_SEQRECRST_TIMER_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_FRER_CTRLx_A) Enables the sequence recovery reset timer.  */
#define GMAC_EMAC_FRER_CTRLx_A_EN_SEQRECRST_TIMER_0 (GMAC_EMAC_FRER_CTRLx_A_EN_SEQRECRST_TIMER_0_Val << GMAC_EMAC_FRER_CTRLx_A_EN_SEQRECRST_TIMER_Pos) /* (GMAC_EMAC_FRER_CTRLx_A) Disables the sequence recovery reset timer. Position  */
#define GMAC_EMAC_FRER_CTRLx_A_EN_SEQRECRST_TIMER_1 (GMAC_EMAC_FRER_CTRLx_A_EN_SEQRECRST_TIMER_1_Val << GMAC_EMAC_FRER_CTRLx_A_EN_SEQRECRST_TIMER_Pos) /* (GMAC_EMAC_FRER_CTRLx_A) Enables the sequence recovery reset timer. Position  */
#define GMAC_EMAC_FRER_CTRLx_A_EN_VECTOR_REC_ALG_Pos _UINT32_(30)                                         /* (GMAC_EMAC_FRER_CTRLx_A) 802.1CB Vector Recovery Algorithm Enable Position */
#define GMAC_EMAC_FRER_CTRLx_A_EN_VECTOR_REC_ALG_Msk (_UINT32_(0x1) << GMAC_EMAC_FRER_CTRLx_A_EN_VECTOR_REC_ALG_Pos) /* (GMAC_EMAC_FRER_CTRLx_A) 802.1CB Vector Recovery Algorithm Enable Mask */
#define GMAC_EMAC_FRER_CTRLx_A_EN_VECTOR_REC_ALG(value) (GMAC_EMAC_FRER_CTRLx_A_EN_VECTOR_REC_ALG_Msk & (_UINT32_(value) << GMAC_EMAC_FRER_CTRLx_A_EN_VECTOR_REC_ALG_Pos)) /* Assigment of value for EN_VECTOR_REC_ALG in the GMAC_EMAC_FRER_CTRLx_A register */
#define   GMAC_EMAC_FRER_CTRLx_A_EN_VECTOR_REC_ALG_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_FRER_CTRLx_A) Enables the match recovery algorithm.  */
#define   GMAC_EMAC_FRER_CTRLx_A_EN_VECTOR_REC_ALG_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_FRER_CTRLx_A) Enables the vector recovery algorithm.  */
#define GMAC_EMAC_FRER_CTRLx_A_EN_VECTOR_REC_ALG_0 (GMAC_EMAC_FRER_CTRLx_A_EN_VECTOR_REC_ALG_0_Val << GMAC_EMAC_FRER_CTRLx_A_EN_VECTOR_REC_ALG_Pos) /* (GMAC_EMAC_FRER_CTRLx_A) Enables the match recovery algorithm. Position  */
#define GMAC_EMAC_FRER_CTRLx_A_EN_VECTOR_REC_ALG_1 (GMAC_EMAC_FRER_CTRLx_A_EN_VECTOR_REC_ALG_1_Val << GMAC_EMAC_FRER_CTRLx_A_EN_VECTOR_REC_ALG_Pos) /* (GMAC_EMAC_FRER_CTRLx_A) Enables the vector recovery algorithm. Position  */
#define GMAC_EMAC_FRER_CTRLx_A_EN_ELIMINATION_Pos _UINT32_(31)                                         /* (GMAC_EMAC_FRER_CTRLx_A) 802.1CB Elimination of Received Frames Enable Position */
#define GMAC_EMAC_FRER_CTRLx_A_EN_ELIMINATION_Msk (_UINT32_(0x1) << GMAC_EMAC_FRER_CTRLx_A_EN_ELIMINATION_Pos) /* (GMAC_EMAC_FRER_CTRLx_A) 802.1CB Elimination of Received Frames Enable Mask */
#define GMAC_EMAC_FRER_CTRLx_A_EN_ELIMINATION(value) (GMAC_EMAC_FRER_CTRLx_A_EN_ELIMINATION_Msk & (_UINT32_(value) << GMAC_EMAC_FRER_CTRLx_A_EN_ELIMINATION_Pos)) /* Assigment of value for EN_ELIMINATION in the GMAC_EMAC_FRER_CTRLx_A register */
#define   GMAC_EMAC_FRER_CTRLx_A_EN_ELIMINATION_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_FRER_CTRLx_A) Disables the elimination of received frames.  */
#define   GMAC_EMAC_FRER_CTRLx_A_EN_ELIMINATION_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_FRER_CTRLx_A) Enables the elimination of received frames.  */
#define GMAC_EMAC_FRER_CTRLx_A_EN_ELIMINATION_0 (GMAC_EMAC_FRER_CTRLx_A_EN_ELIMINATION_0_Val << GMAC_EMAC_FRER_CTRLx_A_EN_ELIMINATION_Pos) /* (GMAC_EMAC_FRER_CTRLx_A) Disables the elimination of received frames. Position  */
#define GMAC_EMAC_FRER_CTRLx_A_EN_ELIMINATION_1 (GMAC_EMAC_FRER_CTRLx_A_EN_ELIMINATION_1_Val << GMAC_EMAC_FRER_CTRLx_A_EN_ELIMINATION_Pos) /* (GMAC_EMAC_FRER_CTRLx_A) Enables the elimination of received frames. Position  */
#define GMAC_EMAC_FRER_CTRLx_A_Msk            _UINT32_(0xF001FFFF)                                 /* (GMAC_EMAC_FRER_CTRLx_A) Register Mask  */


/* -------- GMAC_EMAC_FRER_CTRLx_B : (GMAC Offset: 0x04) (R/W 32) Express MAC Frame Elimination Control1 B Register -------- */
#define GMAC_EMAC_FRER_CTRLx_B_RESETVALUE     _UINT32_(0x00)                                       /*  (GMAC_EMAC_FRER_CTRLx_B) Express MAC Frame Elimination Control1 B Register  Reset Value */

#define GMAC_EMAC_FRER_CTRLx_B_SEQ_REC_WINDOW_Pos _UINT32_(0)                                          /* (GMAC_EMAC_FRER_CTRLx_B) Vector Recovery Window Position */
#define GMAC_EMAC_FRER_CTRLx_B_SEQ_REC_WINDOW_Msk (_UINT32_(0x3F) << GMAC_EMAC_FRER_CTRLx_B_SEQ_REC_WINDOW_Pos) /* (GMAC_EMAC_FRER_CTRLx_B) Vector Recovery Window Mask */
#define GMAC_EMAC_FRER_CTRLx_B_SEQ_REC_WINDOW(value) (GMAC_EMAC_FRER_CTRLx_B_SEQ_REC_WINDOW_Msk & (_UINT32_(value) << GMAC_EMAC_FRER_CTRLx_B_SEQ_REC_WINDOW_Pos)) /* Assigment of value for SEQ_REC_WINDOW in the GMAC_EMAC_FRER_CTRLx_B register */
#define GMAC_EMAC_FRER_CTRLx_B_SEQ_NUM_LENGTH_Pos _UINT32_(8)                                          /* (GMAC_EMAC_FRER_CTRLx_B) Number of Significants bits of the 802.1CB Sequence Number Position */
#define GMAC_EMAC_FRER_CTRLx_B_SEQ_NUM_LENGTH_Msk (_UINT32_(0x1F) << GMAC_EMAC_FRER_CTRLx_B_SEQ_NUM_LENGTH_Pos) /* (GMAC_EMAC_FRER_CTRLx_B) Number of Significants bits of the 802.1CB Sequence Number Mask */
#define GMAC_EMAC_FRER_CTRLx_B_SEQ_NUM_LENGTH(value) (GMAC_EMAC_FRER_CTRLx_B_SEQ_NUM_LENGTH_Msk & (_UINT32_(value) << GMAC_EMAC_FRER_CTRLx_B_SEQ_NUM_LENGTH_Pos)) /* Assigment of value for SEQ_NUM_LENGTH in the GMAC_EMAC_FRER_CTRLx_B register */
#define GMAC_EMAC_FRER_CTRLx_B_Msk            _UINT32_(0x00001F3F)                                 /* (GMAC_EMAC_FRER_CTRLx_B) Register Mask  */


/* -------- GMAC_EMAC_FRER_STATx_A : (GMAC Offset: 0x08) (R/W 32) Express MAC Frame Elimination Statistics1 A Register -------- */
#define GMAC_EMAC_FRER_STATx_A_RESETVALUE     _UINT32_(0x00)                                       /*  (GMAC_EMAC_FRER_STATx_A) Express MAC Frame Elimination Statistics1 A Register  Reset Value */

#define GMAC_EMAC_FRER_STATx_A_LATENT_ERRS_Pos _UINT32_(0)                                          /* (GMAC_EMAC_FRER_STATx_A) Number of Sequence Numbers Seen Without a Duplicate (Clear on read) Position */
#define GMAC_EMAC_FRER_STATx_A_LATENT_ERRS_Msk (_UINT32_(0x3FF) << GMAC_EMAC_FRER_STATx_A_LATENT_ERRS_Pos) /* (GMAC_EMAC_FRER_STATx_A) Number of Sequence Numbers Seen Without a Duplicate (Clear on read) Mask */
#define GMAC_EMAC_FRER_STATx_A_LATENT_ERRS(value) (GMAC_EMAC_FRER_STATx_A_LATENT_ERRS_Msk & (_UINT32_(value) << GMAC_EMAC_FRER_STATx_A_LATENT_ERRS_Pos)) /* Assigment of value for LATENT_ERRS in the GMAC_EMAC_FRER_STATx_A register */
#define GMAC_EMAC_FRER_STATx_A_VEC_REC_ROGUE_Pos _UINT32_(16)                                         /* (GMAC_EMAC_FRER_STATx_A) Number of Dropped Frames (Clear on read) Position */
#define GMAC_EMAC_FRER_STATx_A_VEC_REC_ROGUE_Msk (_UINT32_(0x3FF) << GMAC_EMAC_FRER_STATx_A_VEC_REC_ROGUE_Pos) /* (GMAC_EMAC_FRER_STATx_A) Number of Dropped Frames (Clear on read) Mask */
#define GMAC_EMAC_FRER_STATx_A_VEC_REC_ROGUE(value) (GMAC_EMAC_FRER_STATx_A_VEC_REC_ROGUE_Msk & (_UINT32_(value) << GMAC_EMAC_FRER_STATx_A_VEC_REC_ROGUE_Pos)) /* Assigment of value for VEC_REC_ROGUE in the GMAC_EMAC_FRER_STATx_A register */
#define GMAC_EMAC_FRER_STATx_A_Msk            _UINT32_(0x03FF03FF)                                 /* (GMAC_EMAC_FRER_STATx_A) Register Mask  */


/* -------- GMAC_EMAC_FRER_STATx_B : (GMAC Offset: 0x0C) (R/W 32) Express MAC Frame Elimination Statistics1 B Register -------- */
#define GMAC_EMAC_FRER_STATx_B_RESETVALUE     _UINT32_(0x00)                                       /*  (GMAC_EMAC_FRER_STATx_B) Express MAC Frame Elimination Statistics1 B Register  Reset Value */

#define GMAC_EMAC_FRER_STATx_B_OUT_OF_ORDER_Pos _UINT32_(0)                                          /* (GMAC_EMAC_FRER_STATx_B) Out of Order Sequence Numbers Received (Clear on read) Position */
#define GMAC_EMAC_FRER_STATx_B_OUT_OF_ORDER_Msk (_UINT32_(0x3FF) << GMAC_EMAC_FRER_STATx_B_OUT_OF_ORDER_Pos) /* (GMAC_EMAC_FRER_STATx_B) Out of Order Sequence Numbers Received (Clear on read) Mask */
#define GMAC_EMAC_FRER_STATx_B_OUT_OF_ORDER(value) (GMAC_EMAC_FRER_STATx_B_OUT_OF_ORDER_Msk & (_UINT32_(value) << GMAC_EMAC_FRER_STATx_B_OUT_OF_ORDER_Pos)) /* Assigment of value for OUT_OF_ORDER in the GMAC_EMAC_FRER_STATx_B register */
#define GMAC_EMAC_FRER_STATx_B_SEQRST_COUNT_Pos _UINT32_(16)                                         /* (GMAC_EMAC_FRER_STATx_B) Number of Times the Sequence Recovery Reset Timer Decrements to Zero (Clear on read) Position */
#define GMAC_EMAC_FRER_STATx_B_SEQRST_COUNT_Msk (_UINT32_(0x3FF) << GMAC_EMAC_FRER_STATx_B_SEQRST_COUNT_Pos) /* (GMAC_EMAC_FRER_STATx_B) Number of Times the Sequence Recovery Reset Timer Decrements to Zero (Clear on read) Mask */
#define GMAC_EMAC_FRER_STATx_B_SEQRST_COUNT(value) (GMAC_EMAC_FRER_STATx_B_SEQRST_COUNT_Msk & (_UINT32_(value) << GMAC_EMAC_FRER_STATx_B_SEQRST_COUNT_Pos)) /* Assigment of value for SEQRST_COUNT in the GMAC_EMAC_FRER_STATx_B register */
#define GMAC_EMAC_FRER_STATx_B_Msk            _UINT32_(0x03FF03FF)                                 /* (GMAC_EMAC_FRER_STATx_B) Register Mask  */


/* -------- GMAC_EMAC_SAB : (GMAC Offset: 0x00) (R/W 32) Express MAC Specific Address Bottom Register  -------- */
#define GMAC_EMAC_SAB_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_SAB) Express MAC Specific Address Bottom Register   Reset Value */

#define GMAC_EMAC_SAB_ADDR_Pos                _UINT32_(0)                                          /* (GMAC_EMAC_SAB) Specific Address Position */
#define GMAC_EMAC_SAB_ADDR_Msk                (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_SAB_ADDR_Pos)     /* (GMAC_EMAC_SAB) Specific Address Mask */
#define GMAC_EMAC_SAB_ADDR(value)             (GMAC_EMAC_SAB_ADDR_Msk & (_UINT32_(value) << GMAC_EMAC_SAB_ADDR_Pos)) /* Assigment of value for ADDR in the GMAC_EMAC_SAB register */
#define GMAC_EMAC_SAB_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_SAB) Register Mask  */


/* -------- GMAC_EMAC_SAT : (GMAC Offset: 0x04) (R/W 32) Express MAC Specific Address Top Register  -------- */
#define GMAC_EMAC_SAT_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_SAT) Express MAC Specific Address Top Register   Reset Value */

#define GMAC_EMAC_SAT_ADDR_Pos                _UINT32_(0)                                          /* (GMAC_EMAC_SAT) Specific Address Position */
#define GMAC_EMAC_SAT_ADDR_Msk                (_UINT32_(0xFFFF) << GMAC_EMAC_SAT_ADDR_Pos)         /* (GMAC_EMAC_SAT) Specific Address Mask */
#define GMAC_EMAC_SAT_ADDR(value)             (GMAC_EMAC_SAT_ADDR_Msk & (_UINT32_(value) << GMAC_EMAC_SAT_ADDR_Pos)) /* Assigment of value for ADDR in the GMAC_EMAC_SAT register */
#define GMAC_EMAC_SAT_FILTSORD_Pos            _UINT32_(16)                                         /* (GMAC_EMAC_SAT) Filter Source or Destination MAC Address Position */
#define GMAC_EMAC_SAT_FILTSORD_Msk            (_UINT32_(0x1) << GMAC_EMAC_SAT_FILTSORD_Pos)        /* (GMAC_EMAC_SAT) Filter Source or Destination MAC Address Mask */
#define GMAC_EMAC_SAT_FILTSORD(value)         (GMAC_EMAC_SAT_FILTSORD_Msk & (_UINT32_(value) << GMAC_EMAC_SAT_FILTSORD_Pos)) /* Assigment of value for FILTSORD in the GMAC_EMAC_SAT register */
#define   GMAC_EMAC_SAT_FILTSORD_0_Val        _UINT32_(0x0)                                        /* (GMAC_EMAC_SAT) The filter is a destination address filter.  */
#define   GMAC_EMAC_SAT_FILTSORD_1_Val        _UINT32_(0x1)                                        /* (GMAC_EMAC_SAT) The filter is a source address filter.  */
#define GMAC_EMAC_SAT_FILTSORD_0              (GMAC_EMAC_SAT_FILTSORD_0_Val << GMAC_EMAC_SAT_FILTSORD_Pos) /* (GMAC_EMAC_SAT) The filter is a destination address filter. Position  */
#define GMAC_EMAC_SAT_FILTSORD_1              (GMAC_EMAC_SAT_FILTSORD_1_Val << GMAC_EMAC_SAT_FILTSORD_Pos) /* (GMAC_EMAC_SAT) The filter is a source address filter. Position  */
#define GMAC_EMAC_SAT_FILTBMASK_Pos           _UINT32_(24)                                         /* (GMAC_EMAC_SAT) Filter Bytes Mask Position */
#define GMAC_EMAC_SAT_FILTBMASK_Msk           (_UINT32_(0x3F) << GMAC_EMAC_SAT_FILTBMASK_Pos)      /* (GMAC_EMAC_SAT) Filter Bytes Mask Mask */
#define GMAC_EMAC_SAT_FILTBMASK(value)        (GMAC_EMAC_SAT_FILTBMASK_Msk & (_UINT32_(value) << GMAC_EMAC_SAT_FILTBMASK_Pos)) /* Assigment of value for FILTBMASK in the GMAC_EMAC_SAT register */
#define   GMAC_EMAC_SAT_FILTBMASK_BIT1_Val    _UINT32_(0x1)                                        /* (GMAC_EMAC_SAT) Controls whether the first byte has been received.  */
#define   GMAC_EMAC_SAT_FILTBMASK_BIT2_Val    _UINT32_(0x2)                                        /* (GMAC_EMAC_SAT) Controls whether the second byte has been received.  */
#define   GMAC_EMAC_SAT_FILTBMASK_BIT3_Val    _UINT32_(0x4)                                        /* (GMAC_EMAC_SAT) Controls whether the third byte has been received.  */
#define   GMAC_EMAC_SAT_FILTBMASK_BIT4_Val    _UINT32_(0x8)                                        /* (GMAC_EMAC_SAT) Controls whether the fourth byte has been received.  */
#define   GMAC_EMAC_SAT_FILTBMASK_BIT5_Val    _UINT32_(0x10)                                       /* (GMAC_EMAC_SAT) Controls whether the fifth byte has been received.  */
#define   GMAC_EMAC_SAT_FILTBMASK_BIT6_Val    _UINT32_(0x20)                                       /* (GMAC_EMAC_SAT) Controls whether the sixth byte has been received  */
#define GMAC_EMAC_SAT_FILTBMASK_BIT1          (GMAC_EMAC_SAT_FILTBMASK_BIT1_Val << GMAC_EMAC_SAT_FILTBMASK_Pos) /* (GMAC_EMAC_SAT) Controls whether the first byte has been received. Position  */
#define GMAC_EMAC_SAT_FILTBMASK_BIT2          (GMAC_EMAC_SAT_FILTBMASK_BIT2_Val << GMAC_EMAC_SAT_FILTBMASK_Pos) /* (GMAC_EMAC_SAT) Controls whether the second byte has been received. Position  */
#define GMAC_EMAC_SAT_FILTBMASK_BIT3          (GMAC_EMAC_SAT_FILTBMASK_BIT3_Val << GMAC_EMAC_SAT_FILTBMASK_Pos) /* (GMAC_EMAC_SAT) Controls whether the third byte has been received. Position  */
#define GMAC_EMAC_SAT_FILTBMASK_BIT4          (GMAC_EMAC_SAT_FILTBMASK_BIT4_Val << GMAC_EMAC_SAT_FILTBMASK_Pos) /* (GMAC_EMAC_SAT) Controls whether the fourth byte has been received. Position  */
#define GMAC_EMAC_SAT_FILTBMASK_BIT5          (GMAC_EMAC_SAT_FILTBMASK_BIT5_Val << GMAC_EMAC_SAT_FILTBMASK_Pos) /* (GMAC_EMAC_SAT) Controls whether the fifth byte has been received. Position  */
#define GMAC_EMAC_SAT_FILTBMASK_BIT6          (GMAC_EMAC_SAT_FILTBMASK_BIT6_Val << GMAC_EMAC_SAT_FILTBMASK_Pos) /* (GMAC_EMAC_SAT) Controls whether the sixth byte has been received Position  */
#define GMAC_EMAC_SAT_Msk                     _UINT32_(0x3F01FFFF)                                 /* (GMAC_EMAC_SAT) Register Mask  */


/* -------- GMAC_EMAC_ST2CW0R : (GMAC Offset: 0x00) (R/W 32) Express MAC Screening Type 2 Compare Word 0 Register  -------- */
#define GMAC_EMAC_ST2CW0R_RESETVALUE          _UINT32_(0x00)                                       /*  (GMAC_EMAC_ST2CW0R) Express MAC Screening Type 2 Compare Word 0 Register   Reset Value */

#define GMAC_EMAC_ST2CW0R_MASKVAL_Pos         _UINT32_(0)                                          /* (GMAC_EMAC_ST2CW0R) Mask Value Position */
#define GMAC_EMAC_ST2CW0R_MASKVAL_Msk         (_UINT32_(0xFFFF) << GMAC_EMAC_ST2CW0R_MASKVAL_Pos)  /* (GMAC_EMAC_ST2CW0R) Mask Value Mask */
#define GMAC_EMAC_ST2CW0R_MASKVAL(value)      (GMAC_EMAC_ST2CW0R_MASKVAL_Msk & (_UINT32_(value) << GMAC_EMAC_ST2CW0R_MASKVAL_Pos)) /* Assigment of value for MASKVAL in the GMAC_EMAC_ST2CW0R register */
#define GMAC_EMAC_ST2CW0R_COMPVAL_Pos         _UINT32_(16)                                         /* (GMAC_EMAC_ST2CW0R) Compare Value Position */
#define GMAC_EMAC_ST2CW0R_COMPVAL_Msk         (_UINT32_(0xFFFF) << GMAC_EMAC_ST2CW0R_COMPVAL_Pos)  /* (GMAC_EMAC_ST2CW0R) Compare Value Mask */
#define GMAC_EMAC_ST2CW0R_COMPVAL(value)      (GMAC_EMAC_ST2CW0R_COMPVAL_Msk & (_UINT32_(value) << GMAC_EMAC_ST2CW0R_COMPVAL_Pos)) /* Assigment of value for COMPVAL in the GMAC_EMAC_ST2CW0R register */
#define GMAC_EMAC_ST2CW0R_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_ST2CW0R) Register Mask  */


/* -------- GMAC_EMAC_ST2CW1R : (GMAC Offset: 0x04) (R/W 32) Express MAC Screening Type 2 Compare Word 1 Register  -------- */
#define GMAC_EMAC_ST2CW1R_RESETVALUE          _UINT32_(0x00)                                       /*  (GMAC_EMAC_ST2CW1R) Express MAC Screening Type 2 Compare Word 1 Register   Reset Value */

#define GMAC_EMAC_ST2CW1R_OFFSVAL_Pos         _UINT32_(0)                                          /* (GMAC_EMAC_ST2CW1R) Offset Value in Bytes Position */
#define GMAC_EMAC_ST2CW1R_OFFSVAL_Msk         (_UINT32_(0x7F) << GMAC_EMAC_ST2CW1R_OFFSVAL_Pos)    /* (GMAC_EMAC_ST2CW1R) Offset Value in Bytes Mask */
#define GMAC_EMAC_ST2CW1R_OFFSVAL(value)      (GMAC_EMAC_ST2CW1R_OFFSVAL_Msk & (_UINT32_(value) << GMAC_EMAC_ST2CW1R_OFFSVAL_Pos)) /* Assigment of value for OFFSVAL in the GMAC_EMAC_ST2CW1R register */
#define GMAC_EMAC_ST2CW1R_OFFSSTRT_Pos        _UINT32_(7)                                          /* (GMAC_EMAC_ST2CW1R) Ethernet Frame Offset Start Position */
#define GMAC_EMAC_ST2CW1R_OFFSSTRT_Msk        (_UINT32_(0x3) << GMAC_EMAC_ST2CW1R_OFFSSTRT_Pos)    /* (GMAC_EMAC_ST2CW1R) Ethernet Frame Offset Start Mask */
#define GMAC_EMAC_ST2CW1R_OFFSSTRT(value)     (GMAC_EMAC_ST2CW1R_OFFSSTRT_Msk & (_UINT32_(value) << GMAC_EMAC_ST2CW1R_OFFSSTRT_Pos)) /* Assigment of value for OFFSSTRT in the GMAC_EMAC_ST2CW1R register */
#define   GMAC_EMAC_ST2CW1R_OFFSSTRT_FRAMESTART_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_ST2CW1R) Offset from the start of the frame  */
#define   GMAC_EMAC_ST2CW1R_OFFSSTRT_ETHERTYPE_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_ST2CW1R) Offset from the byte after the EtherType field  */
#define   GMAC_EMAC_ST2CW1R_OFFSSTRT_IP_Val   _UINT32_(0x2)                                        /* (GMAC_EMAC_ST2CW1R) Offset from the byte after the IP header field  */
#define   GMAC_EMAC_ST2CW1R_OFFSSTRT_TCP_UDP_Val _UINT32_(0x3)                                        /* (GMAC_EMAC_ST2CW1R) Offset from the byte after the TCP/UDP header field  */
#define GMAC_EMAC_ST2CW1R_OFFSSTRT_FRAMESTART (GMAC_EMAC_ST2CW1R_OFFSSTRT_FRAMESTART_Val << GMAC_EMAC_ST2CW1R_OFFSSTRT_Pos) /* (GMAC_EMAC_ST2CW1R) Offset from the start of the frame Position  */
#define GMAC_EMAC_ST2CW1R_OFFSSTRT_ETHERTYPE  (GMAC_EMAC_ST2CW1R_OFFSSTRT_ETHERTYPE_Val << GMAC_EMAC_ST2CW1R_OFFSSTRT_Pos) /* (GMAC_EMAC_ST2CW1R) Offset from the byte after the EtherType field Position  */
#define GMAC_EMAC_ST2CW1R_OFFSSTRT_IP         (GMAC_EMAC_ST2CW1R_OFFSSTRT_IP_Val << GMAC_EMAC_ST2CW1R_OFFSSTRT_Pos) /* (GMAC_EMAC_ST2CW1R) Offset from the byte after the IP header field Position  */
#define GMAC_EMAC_ST2CW1R_OFFSSTRT_TCP_UDP    (GMAC_EMAC_ST2CW1R_OFFSSTRT_TCP_UDP_Val << GMAC_EMAC_ST2CW1R_OFFSSTRT_Pos) /* (GMAC_EMAC_ST2CW1R) Offset from the byte after the TCP/UDP header field Position  */
#define GMAC_EMAC_ST2CW1R_DISMASK_Pos         _UINT32_(9)                                          /* (GMAC_EMAC_ST2CW1R) Disable Mask Position */
#define GMAC_EMAC_ST2CW1R_DISMASK_Msk         (_UINT32_(0x1) << GMAC_EMAC_ST2CW1R_DISMASK_Pos)     /* (GMAC_EMAC_ST2CW1R) Disable Mask Mask */
#define GMAC_EMAC_ST2CW1R_DISMASK(value)      (GMAC_EMAC_ST2CW1R_DISMASK_Msk & (_UINT32_(value) << GMAC_EMAC_ST2CW1R_DISMASK_Pos)) /* Assigment of value for DISMASK in the GMAC_EMAC_ST2CW1R register */
#define   GMAC_EMAC_ST2CW1R_DISMASK_0_Val     _UINT32_(0x0)                                        /* (GMAC_EMAC_ST2CW1R) GMAC_EMAC_ST2CW0R contains a 2-byte compare value with a 2-byte mask value.  */
#define   GMAC_EMAC_ST2CW1R_DISMASK_1_Val     _UINT32_(0x1)                                        /* (GMAC_EMAC_ST2CW1R) GMAC_EMAC_ST2CW0R contains a 4-byte compare value.  */
#define GMAC_EMAC_ST2CW1R_DISMASK_0           (GMAC_EMAC_ST2CW1R_DISMASK_0_Val << GMAC_EMAC_ST2CW1R_DISMASK_Pos) /* (GMAC_EMAC_ST2CW1R) GMAC_EMAC_ST2CW0R contains a 2-byte compare value with a 2-byte mask value. Position  */
#define GMAC_EMAC_ST2CW1R_DISMASK_1           (GMAC_EMAC_ST2CW1R_DISMASK_1_Val << GMAC_EMAC_ST2CW1R_DISMASK_Pos) /* (GMAC_EMAC_ST2CW1R) GMAC_EMAC_ST2CW0R contains a 4-byte compare value. Position  */
#define GMAC_EMAC_ST2CW1R_Msk                 _UINT32_(0x000003FF)                                 /* (GMAC_EMAC_ST2CW1R) Register Mask  */


/* -------- GMAC_FRER_CTRL_A : (GMAC Offset: 0x00) (R/W 32) Frame Elimination Control A Register  -------- */
#define GMAC_FRER_CTRL_A_RESETVALUE           _UINT32_(0x00)                                       /*  (GMAC_FRER_CTRL_A) Frame Elimination Control A Register   Reset Value */

#define GMAC_FRER_CTRL_A_MEMBER_STREAM_1_Pos  _UINT32_(0)                                          /* (GMAC_FRER_CTRL_A) Pointer to Screener Type 2 Register Position */
#define GMAC_FRER_CTRL_A_MEMBER_STREAM_1_Msk  (_UINT32_(0xF) << GMAC_FRER_CTRL_A_MEMBER_STREAM_1_Pos) /* (GMAC_FRER_CTRL_A) Pointer to Screener Type 2 Register Mask */
#define GMAC_FRER_CTRL_A_MEMBER_STREAM_1(value) (GMAC_FRER_CTRL_A_MEMBER_STREAM_1_Msk & (_UINT32_(value) << GMAC_FRER_CTRL_A_MEMBER_STREAM_1_Pos)) /* Assigment of value for MEMBER_STREAM_1 in the GMAC_FRER_CTRL_A register */
#define GMAC_FRER_CTRL_A_MEMBER_STREAM_2_Pos  _UINT32_(4)                                          /* (GMAC_FRER_CTRL_A) Pointer to Screener Type 2 Register Position */
#define GMAC_FRER_CTRL_A_MEMBER_STREAM_2_Msk  (_UINT32_(0xF) << GMAC_FRER_CTRL_A_MEMBER_STREAM_2_Pos) /* (GMAC_FRER_CTRL_A) Pointer to Screener Type 2 Register Mask */
#define GMAC_FRER_CTRL_A_MEMBER_STREAM_2(value) (GMAC_FRER_CTRL_A_MEMBER_STREAM_2_Msk & (_UINT32_(value) << GMAC_FRER_CTRL_A_MEMBER_STREAM_2_Pos)) /* Assigment of value for MEMBER_STREAM_2 in the GMAC_FRER_CTRL_A register */
#define GMAC_FRER_CTRL_A_OFFSET_VALUE_Pos     _UINT32_(8)                                          /* (GMAC_FRER_CTRL_A) Offset in Bytes from Start Packet Delimiter to MSB for 802.1CB Sequence Number Position */
#define GMAC_FRER_CTRL_A_OFFSET_VALUE_Msk     (_UINT32_(0x1FF) << GMAC_FRER_CTRL_A_OFFSET_VALUE_Pos) /* (GMAC_FRER_CTRL_A) Offset in Bytes from Start Packet Delimiter to MSB for 802.1CB Sequence Number Mask */
#define GMAC_FRER_CTRL_A_OFFSET_VALUE(value)  (GMAC_FRER_CTRL_A_OFFSET_VALUE_Msk & (_UINT32_(value) << GMAC_FRER_CTRL_A_OFFSET_VALUE_Pos)) /* Assigment of value for OFFSET_VALUE in the GMAC_FRER_CTRL_A register */
#define GMAC_FRER_CTRL_A_USE_R_TAG_Pos        _UINT32_(28)                                         /* (GMAC_FRER_CTRL_A) Redundancy Tag Enable Position */
#define GMAC_FRER_CTRL_A_USE_R_TAG_Msk        (_UINT32_(0x1) << GMAC_FRER_CTRL_A_USE_R_TAG_Pos)    /* (GMAC_FRER_CTRL_A) Redundancy Tag Enable Mask */
#define GMAC_FRER_CTRL_A_USE_R_TAG(value)     (GMAC_FRER_CTRL_A_USE_R_TAG_Msk & (_UINT32_(value) << GMAC_FRER_CTRL_A_USE_R_TAG_Pos)) /* Assigment of value for USE_R_TAG in the GMAC_FRER_CTRL_A register */
#define   GMAC_FRER_CTRL_A_USE_R_TAG_0_Val    _UINT32_(0x0)                                        /* (GMAC_FRER_CTRL_A) Identifies bottom of sequence number with OFFSET_VALUE.  */
#define   GMAC_FRER_CTRL_A_USE_R_TAG_1_Val    _UINT32_(0x1)                                        /* (GMAC_FRER_CTRL_A) Identifies sequence number with redundancy tag.  */
#define GMAC_FRER_CTRL_A_USE_R_TAG_0          (GMAC_FRER_CTRL_A_USE_R_TAG_0_Val << GMAC_FRER_CTRL_A_USE_R_TAG_Pos) /* (GMAC_FRER_CTRL_A) Identifies bottom of sequence number with OFFSET_VALUE. Position  */
#define GMAC_FRER_CTRL_A_USE_R_TAG_1          (GMAC_FRER_CTRL_A_USE_R_TAG_1_Val << GMAC_FRER_CTRL_A_USE_R_TAG_Pos) /* (GMAC_FRER_CTRL_A) Identifies sequence number with redundancy tag. Position  */
#define GMAC_FRER_CTRL_A_EN_SEQRECRST_TIMER_Pos _UINT32_(29)                                         /* (GMAC_FRER_CTRL_A) 802.1CB Sequence Recovery Reset Timer Enable Position */
#define GMAC_FRER_CTRL_A_EN_SEQRECRST_TIMER_Msk (_UINT32_(0x1) << GMAC_FRER_CTRL_A_EN_SEQRECRST_TIMER_Pos) /* (GMAC_FRER_CTRL_A) 802.1CB Sequence Recovery Reset Timer Enable Mask */
#define GMAC_FRER_CTRL_A_EN_SEQRECRST_TIMER(value) (GMAC_FRER_CTRL_A_EN_SEQRECRST_TIMER_Msk & (_UINT32_(value) << GMAC_FRER_CTRL_A_EN_SEQRECRST_TIMER_Pos)) /* Assigment of value for EN_SEQRECRST_TIMER in the GMAC_FRER_CTRL_A register */
#define   GMAC_FRER_CTRL_A_EN_SEQRECRST_TIMER_0_Val _UINT32_(0x0)                                        /* (GMAC_FRER_CTRL_A) Disables the sequence recovery reset timer.  */
#define   GMAC_FRER_CTRL_A_EN_SEQRECRST_TIMER_1_Val _UINT32_(0x1)                                        /* (GMAC_FRER_CTRL_A) Enables the sequence recovery reset timer.  */
#define GMAC_FRER_CTRL_A_EN_SEQRECRST_TIMER_0 (GMAC_FRER_CTRL_A_EN_SEQRECRST_TIMER_0_Val << GMAC_FRER_CTRL_A_EN_SEQRECRST_TIMER_Pos) /* (GMAC_FRER_CTRL_A) Disables the sequence recovery reset timer. Position  */
#define GMAC_FRER_CTRL_A_EN_SEQRECRST_TIMER_1 (GMAC_FRER_CTRL_A_EN_SEQRECRST_TIMER_1_Val << GMAC_FRER_CTRL_A_EN_SEQRECRST_TIMER_Pos) /* (GMAC_FRER_CTRL_A) Enables the sequence recovery reset timer. Position  */
#define GMAC_FRER_CTRL_A_EN_VECTOR_REC_ALG_Pos _UINT32_(30)                                         /* (GMAC_FRER_CTRL_A) 802.1CB Vector Recovery Algorithm Enable Position */
#define GMAC_FRER_CTRL_A_EN_VECTOR_REC_ALG_Msk (_UINT32_(0x1) << GMAC_FRER_CTRL_A_EN_VECTOR_REC_ALG_Pos) /* (GMAC_FRER_CTRL_A) 802.1CB Vector Recovery Algorithm Enable Mask */
#define GMAC_FRER_CTRL_A_EN_VECTOR_REC_ALG(value) (GMAC_FRER_CTRL_A_EN_VECTOR_REC_ALG_Msk & (_UINT32_(value) << GMAC_FRER_CTRL_A_EN_VECTOR_REC_ALG_Pos)) /* Assigment of value for EN_VECTOR_REC_ALG in the GMAC_FRER_CTRL_A register */
#define   GMAC_FRER_CTRL_A_EN_VECTOR_REC_ALG_0_Val _UINT32_(0x0)                                        /* (GMAC_FRER_CTRL_A) Enables the match recovery algorithm.  */
#define   GMAC_FRER_CTRL_A_EN_VECTOR_REC_ALG_1_Val _UINT32_(0x1)                                        /* (GMAC_FRER_CTRL_A) Enables the vector recovery algorithm.  */
#define GMAC_FRER_CTRL_A_EN_VECTOR_REC_ALG_0  (GMAC_FRER_CTRL_A_EN_VECTOR_REC_ALG_0_Val << GMAC_FRER_CTRL_A_EN_VECTOR_REC_ALG_Pos) /* (GMAC_FRER_CTRL_A) Enables the match recovery algorithm. Position  */
#define GMAC_FRER_CTRL_A_EN_VECTOR_REC_ALG_1  (GMAC_FRER_CTRL_A_EN_VECTOR_REC_ALG_1_Val << GMAC_FRER_CTRL_A_EN_VECTOR_REC_ALG_Pos) /* (GMAC_FRER_CTRL_A) Enables the vector recovery algorithm. Position  */
#define GMAC_FRER_CTRL_A_EN_ELIMINATION_Pos   _UINT32_(31)                                         /* (GMAC_FRER_CTRL_A) 802.1CB Elimination of Received Frames Enable Position */
#define GMAC_FRER_CTRL_A_EN_ELIMINATION_Msk   (_UINT32_(0x1) << GMAC_FRER_CTRL_A_EN_ELIMINATION_Pos) /* (GMAC_FRER_CTRL_A) 802.1CB Elimination of Received Frames Enable Mask */
#define GMAC_FRER_CTRL_A_EN_ELIMINATION(value) (GMAC_FRER_CTRL_A_EN_ELIMINATION_Msk & (_UINT32_(value) << GMAC_FRER_CTRL_A_EN_ELIMINATION_Pos)) /* Assigment of value for EN_ELIMINATION in the GMAC_FRER_CTRL_A register */
#define   GMAC_FRER_CTRL_A_EN_ELIMINATION_0_Val _UINT32_(0x0)                                        /* (GMAC_FRER_CTRL_A) Disables the elimination of received frames.  */
#define   GMAC_FRER_CTRL_A_EN_ELIMINATION_1_Val _UINT32_(0x1)                                        /* (GMAC_FRER_CTRL_A) Enables the elimination of received frames.  */
#define GMAC_FRER_CTRL_A_EN_ELIMINATION_0     (GMAC_FRER_CTRL_A_EN_ELIMINATION_0_Val << GMAC_FRER_CTRL_A_EN_ELIMINATION_Pos) /* (GMAC_FRER_CTRL_A) Disables the elimination of received frames. Position  */
#define GMAC_FRER_CTRL_A_EN_ELIMINATION_1     (GMAC_FRER_CTRL_A_EN_ELIMINATION_1_Val << GMAC_FRER_CTRL_A_EN_ELIMINATION_Pos) /* (GMAC_FRER_CTRL_A) Enables the elimination of received frames. Position  */
#define GMAC_FRER_CTRL_A_Msk                  _UINT32_(0xF001FFFF)                                 /* (GMAC_FRER_CTRL_A) Register Mask  */


/* -------- GMAC_FRER_CTRL_B : (GMAC Offset: 0x04) (R/W 32) Frame Elimination Control B Register  -------- */
#define GMAC_FRER_CTRL_B_RESETVALUE           _UINT32_(0x00)                                       /*  (GMAC_FRER_CTRL_B) Frame Elimination Control B Register   Reset Value */

#define GMAC_FRER_CTRL_B_SEQ_REC_WINDOW_Pos   _UINT32_(0)                                          /* (GMAC_FRER_CTRL_B) Vector Recovery Window Position */
#define GMAC_FRER_CTRL_B_SEQ_REC_WINDOW_Msk   (_UINT32_(0x3F) << GMAC_FRER_CTRL_B_SEQ_REC_WINDOW_Pos) /* (GMAC_FRER_CTRL_B) Vector Recovery Window Mask */
#define GMAC_FRER_CTRL_B_SEQ_REC_WINDOW(value) (GMAC_FRER_CTRL_B_SEQ_REC_WINDOW_Msk & (_UINT32_(value) << GMAC_FRER_CTRL_B_SEQ_REC_WINDOW_Pos)) /* Assigment of value for SEQ_REC_WINDOW in the GMAC_FRER_CTRL_B register */
#define GMAC_FRER_CTRL_B_SEQ_NUM_LENGTH_Pos   _UINT32_(8)                                          /* (GMAC_FRER_CTRL_B) Number of Significants bits of the 802.1CB Sequence Number Position */
#define GMAC_FRER_CTRL_B_SEQ_NUM_LENGTH_Msk   (_UINT32_(0x1F) << GMAC_FRER_CTRL_B_SEQ_NUM_LENGTH_Pos) /* (GMAC_FRER_CTRL_B) Number of Significants bits of the 802.1CB Sequence Number Mask */
#define GMAC_FRER_CTRL_B_SEQ_NUM_LENGTH(value) (GMAC_FRER_CTRL_B_SEQ_NUM_LENGTH_Msk & (_UINT32_(value) << GMAC_FRER_CTRL_B_SEQ_NUM_LENGTH_Pos)) /* Assigment of value for SEQ_NUM_LENGTH in the GMAC_FRER_CTRL_B register */
#define GMAC_FRER_CTRL_B_Msk                  _UINT32_(0x00001F3F)                                 /* (GMAC_FRER_CTRL_B) Register Mask  */


/* -------- GMAC_FRER_STAT_A : (GMAC Offset: 0x08) ( R/ 32) Frame Elimination Statistics A Register  -------- */
#define GMAC_FRER_STAT_A_RESETVALUE           _UINT32_(0x00)                                       /*  (GMAC_FRER_STAT_A) Frame Elimination Statistics A Register   Reset Value */

#define GMAC_FRER_STAT_A_LATENT_ERRS_Pos      _UINT32_(0)                                          /* (GMAC_FRER_STAT_A) Number of Sequence Numbers Seen Without a Duplicate (Clear on read) Position */
#define GMAC_FRER_STAT_A_LATENT_ERRS_Msk      (_UINT32_(0x3FF) << GMAC_FRER_STAT_A_LATENT_ERRS_Pos) /* (GMAC_FRER_STAT_A) Number of Sequence Numbers Seen Without a Duplicate (Clear on read) Mask */
#define GMAC_FRER_STAT_A_LATENT_ERRS(value)   (GMAC_FRER_STAT_A_LATENT_ERRS_Msk & (_UINT32_(value) << GMAC_FRER_STAT_A_LATENT_ERRS_Pos)) /* Assigment of value for LATENT_ERRS in the GMAC_FRER_STAT_A register */
#define GMAC_FRER_STAT_A_VEC_REC_ROGUE_Pos    _UINT32_(16)                                         /* (GMAC_FRER_STAT_A) Number of Dropped Frames (Clear on read) Position */
#define GMAC_FRER_STAT_A_VEC_REC_ROGUE_Msk    (_UINT32_(0x3FF) << GMAC_FRER_STAT_A_VEC_REC_ROGUE_Pos) /* (GMAC_FRER_STAT_A) Number of Dropped Frames (Clear on read) Mask */
#define GMAC_FRER_STAT_A_VEC_REC_ROGUE(value) (GMAC_FRER_STAT_A_VEC_REC_ROGUE_Msk & (_UINT32_(value) << GMAC_FRER_STAT_A_VEC_REC_ROGUE_Pos)) /* Assigment of value for VEC_REC_ROGUE in the GMAC_FRER_STAT_A register */
#define GMAC_FRER_STAT_A_Msk                  _UINT32_(0x03FF03FF)                                 /* (GMAC_FRER_STAT_A) Register Mask  */


/* -------- GMAC_FRER_STAT_B : (GMAC Offset: 0x0C) ( R/ 32) Frame Elimination Statistics B Register  -------- */
#define GMAC_FRER_STAT_B_RESETVALUE           _UINT32_(0x00)                                       /*  (GMAC_FRER_STAT_B) Frame Elimination Statistics B Register   Reset Value */

#define GMAC_FRER_STAT_B_OUT_OF_ORDER_Pos     _UINT32_(0)                                          /* (GMAC_FRER_STAT_B) Out of Order Sequence Numbers Received (Clear on read) Position */
#define GMAC_FRER_STAT_B_OUT_OF_ORDER_Msk     (_UINT32_(0x3FF) << GMAC_FRER_STAT_B_OUT_OF_ORDER_Pos) /* (GMAC_FRER_STAT_B) Out of Order Sequence Numbers Received (Clear on read) Mask */
#define GMAC_FRER_STAT_B_OUT_OF_ORDER(value)  (GMAC_FRER_STAT_B_OUT_OF_ORDER_Msk & (_UINT32_(value) << GMAC_FRER_STAT_B_OUT_OF_ORDER_Pos)) /* Assigment of value for OUT_OF_ORDER in the GMAC_FRER_STAT_B register */
#define GMAC_FRER_STAT_B_SEQRST_COUNT_Pos     _UINT32_(16)                                         /* (GMAC_FRER_STAT_B) Number of Times the Sequence Recovery Reset Timer Decrements to Zero (Clear on read) Position */
#define GMAC_FRER_STAT_B_SEQRST_COUNT_Msk     (_UINT32_(0x3FF) << GMAC_FRER_STAT_B_SEQRST_COUNT_Pos) /* (GMAC_FRER_STAT_B) Number of Times the Sequence Recovery Reset Timer Decrements to Zero (Clear on read) Mask */
#define GMAC_FRER_STAT_B_SEQRST_COUNT(value)  (GMAC_FRER_STAT_B_SEQRST_COUNT_Msk & (_UINT32_(value) << GMAC_FRER_STAT_B_SEQRST_COUNT_Pos)) /* Assigment of value for SEQRST_COUNT in the GMAC_FRER_STAT_B register */
#define GMAC_FRER_STAT_B_Msk                  _UINT32_(0x03FF03FF)                                 /* (GMAC_FRER_STAT_B) Register Mask  */


/* -------- GMAC_ST2CW0R : (GMAC Offset: 0x00) (R/W 32) Screening Type 2 Compare Word 0 Register  -------- */
#define GMAC_ST2CW0R_RESETVALUE               _UINT32_(0x00)                                       /*  (GMAC_ST2CW0R) Screening Type 2 Compare Word 0 Register   Reset Value */

#define GMAC_ST2CW0R_MASKVAL_Pos              _UINT32_(0)                                          /* (GMAC_ST2CW0R) Mask Value Position */
#define GMAC_ST2CW0R_MASKVAL_Msk              (_UINT32_(0xFFFF) << GMAC_ST2CW0R_MASKVAL_Pos)       /* (GMAC_ST2CW0R) Mask Value Mask */
#define GMAC_ST2CW0R_MASKVAL(value)           (GMAC_ST2CW0R_MASKVAL_Msk & (_UINT32_(value) << GMAC_ST2CW0R_MASKVAL_Pos)) /* Assigment of value for MASKVAL in the GMAC_ST2CW0R register */
#define GMAC_ST2CW0R_COMPVAL_Pos              _UINT32_(16)                                         /* (GMAC_ST2CW0R) Compare Value Position */
#define GMAC_ST2CW0R_COMPVAL_Msk              (_UINT32_(0xFFFF) << GMAC_ST2CW0R_COMPVAL_Pos)       /* (GMAC_ST2CW0R) Compare Value Mask */
#define GMAC_ST2CW0R_COMPVAL(value)           (GMAC_ST2CW0R_COMPVAL_Msk & (_UINT32_(value) << GMAC_ST2CW0R_COMPVAL_Pos)) /* Assigment of value for COMPVAL in the GMAC_ST2CW0R register */
#define GMAC_ST2CW0R_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (GMAC_ST2CW0R) Register Mask  */


/* -------- GMAC_ST2CW1R : (GMAC Offset: 0x04) (R/W 32) Screening Type 2 Compare Word 1 Register  -------- */
#define GMAC_ST2CW1R_RESETVALUE               _UINT32_(0x00)                                       /*  (GMAC_ST2CW1R) Screening Type 2 Compare Word 1 Register   Reset Value */

#define GMAC_ST2CW1R_OFFSVAL_Pos              _UINT32_(0)                                          /* (GMAC_ST2CW1R) Offset Value in Bytes Position */
#define GMAC_ST2CW1R_OFFSVAL_Msk              (_UINT32_(0x7F) << GMAC_ST2CW1R_OFFSVAL_Pos)         /* (GMAC_ST2CW1R) Offset Value in Bytes Mask */
#define GMAC_ST2CW1R_OFFSVAL(value)           (GMAC_ST2CW1R_OFFSVAL_Msk & (_UINT32_(value) << GMAC_ST2CW1R_OFFSVAL_Pos)) /* Assigment of value for OFFSVAL in the GMAC_ST2CW1R register */
#define GMAC_ST2CW1R_OFFSSTRT_Pos             _UINT32_(7)                                          /* (GMAC_ST2CW1R) Ethernet Frame Offset Start Position */
#define GMAC_ST2CW1R_OFFSSTRT_Msk             (_UINT32_(0x3) << GMAC_ST2CW1R_OFFSSTRT_Pos)         /* (GMAC_ST2CW1R) Ethernet Frame Offset Start Mask */
#define GMAC_ST2CW1R_OFFSSTRT(value)          (GMAC_ST2CW1R_OFFSSTRT_Msk & (_UINT32_(value) << GMAC_ST2CW1R_OFFSSTRT_Pos)) /* Assigment of value for OFFSSTRT in the GMAC_ST2CW1R register */
#define   GMAC_ST2CW1R_OFFSSTRT_FRAMESTART_Val _UINT32_(0x0)                                        /* (GMAC_ST2CW1R) Offset from the start of the frame  */
#define   GMAC_ST2CW1R_OFFSSTRT_ETHERTYPE_Val _UINT32_(0x1)                                        /* (GMAC_ST2CW1R) Offset from the byte after the EtherType field  */
#define   GMAC_ST2CW1R_OFFSSTRT_IP_Val        _UINT32_(0x2)                                        /* (GMAC_ST2CW1R) Offset from the byte after the IP header field  */
#define   GMAC_ST2CW1R_OFFSSTRT_TCP_UDP_Val   _UINT32_(0x3)                                        /* (GMAC_ST2CW1R) Offset from the byte after the TCP/UDP header field  */
#define GMAC_ST2CW1R_OFFSSTRT_FRAMESTART      (GMAC_ST2CW1R_OFFSSTRT_FRAMESTART_Val << GMAC_ST2CW1R_OFFSSTRT_Pos) /* (GMAC_ST2CW1R) Offset from the start of the frame Position  */
#define GMAC_ST2CW1R_OFFSSTRT_ETHERTYPE       (GMAC_ST2CW1R_OFFSSTRT_ETHERTYPE_Val << GMAC_ST2CW1R_OFFSSTRT_Pos) /* (GMAC_ST2CW1R) Offset from the byte after the EtherType field Position  */
#define GMAC_ST2CW1R_OFFSSTRT_IP              (GMAC_ST2CW1R_OFFSSTRT_IP_Val << GMAC_ST2CW1R_OFFSSTRT_Pos) /* (GMAC_ST2CW1R) Offset from the byte after the IP header field Position  */
#define GMAC_ST2CW1R_OFFSSTRT_TCP_UDP         (GMAC_ST2CW1R_OFFSSTRT_TCP_UDP_Val << GMAC_ST2CW1R_OFFSSTRT_Pos) /* (GMAC_ST2CW1R) Offset from the byte after the TCP/UDP header field Position  */
#define GMAC_ST2CW1R_DISMASK_Pos              _UINT32_(9)                                          /* (GMAC_ST2CW1R) Disable Mask Position */
#define GMAC_ST2CW1R_DISMASK_Msk              (_UINT32_(0x1) << GMAC_ST2CW1R_DISMASK_Pos)          /* (GMAC_ST2CW1R) Disable Mask Mask */
#define GMAC_ST2CW1R_DISMASK(value)           (GMAC_ST2CW1R_DISMASK_Msk & (_UINT32_(value) << GMAC_ST2CW1R_DISMASK_Pos)) /* Assigment of value for DISMASK in the GMAC_ST2CW1R register */
#define   GMAC_ST2CW1R_DISMASK_0_Val          _UINT32_(0x0)                                        /* (GMAC_ST2CW1R) GMAC_ST2CW0R contains a 2-byte compare value with a 2-byte mask value.  */
#define   GMAC_ST2CW1R_DISMASK_1_Val          _UINT32_(0x1)                                        /* (GMAC_ST2CW1R) GMAC_ST2CW0R contains a 4-byte compare value.  */
#define GMAC_ST2CW1R_DISMASK_0                (GMAC_ST2CW1R_DISMASK_0_Val << GMAC_ST2CW1R_DISMASK_Pos) /* (GMAC_ST2CW1R) GMAC_ST2CW0R contains a 2-byte compare value with a 2-byte mask value. Position  */
#define GMAC_ST2CW1R_DISMASK_1                (GMAC_ST2CW1R_DISMASK_1_Val << GMAC_ST2CW1R_DISMASK_Pos) /* (GMAC_ST2CW1R) GMAC_ST2CW0R contains a 4-byte compare value. Position  */
#define GMAC_ST2CW1R_Msk                      _UINT32_(0x000003FF)                                 /* (GMAC_ST2CW1R) Register Mask  */


/* -------- GMAC_NCR : (GMAC Offset: 0x00) (R/W 32) Network Control Register -------- */
#define GMAC_NCR_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_NCR) Network Control Register  Reset Value */

#define GMAC_NCR_LBL_Pos                      _UINT32_(1)                                          /* (GMAC_NCR) Loop Back Local Position */
#define GMAC_NCR_LBL_Msk                      (_UINT32_(0x1) << GMAC_NCR_LBL_Pos)                  /* (GMAC_NCR) Loop Back Local Mask */
#define GMAC_NCR_LBL(value)                   (GMAC_NCR_LBL_Msk & (_UINT32_(value) << GMAC_NCR_LBL_Pos)) /* Assigment of value for LBL in the GMAC_NCR register */
#define   GMAC_NCR_LBL_0_Val                  _UINT32_(0x0)                                        /* (GMAC_NCR) Normal operating mode (no loop back).  */
#define   GMAC_NCR_LBL_1_Val                  _UINT32_(0x1)                                        /* (GMAC_NCR) Connects GTX to GRX, GTXEN to GRXDV and forces Full Duplex mode. GRXCK and GTXCK may malfunction as the GMAC is switched into and out of internal loop back. It is important that receive and transmit circuits have already been disabled when making the switch into and out of internal loop back.  */
#define GMAC_NCR_LBL_0                        (GMAC_NCR_LBL_0_Val << GMAC_NCR_LBL_Pos)             /* (GMAC_NCR) Normal operating mode (no loop back). Position  */
#define GMAC_NCR_LBL_1                        (GMAC_NCR_LBL_1_Val << GMAC_NCR_LBL_Pos)             /* (GMAC_NCR) Connects GTX to GRX, GTXEN to GRXDV and forces Full Duplex mode. GRXCK and GTXCK may malfunction as the GMAC is switched into and out of internal loop back. It is important that receive and transmit circuits have already been disabled when making the switch into and out of internal loop back. Position  */
#define GMAC_NCR_RXEN_Pos                     _UINT32_(2)                                          /* (GMAC_NCR) Receive Enable Position */
#define GMAC_NCR_RXEN_Msk                     (_UINT32_(0x1) << GMAC_NCR_RXEN_Pos)                 /* (GMAC_NCR) Receive Enable Mask */
#define GMAC_NCR_RXEN(value)                  (GMAC_NCR_RXEN_Msk & (_UINT32_(value) << GMAC_NCR_RXEN_Pos)) /* Assigment of value for RXEN in the GMAC_NCR register */
#define   GMAC_NCR_RXEN_0_Val                 _UINT32_(0x0)                                        /* (GMAC_NCR) Stops frame reception immediately and the receive pipeline will be cleared. The Receive Queue Pointer register is unaffected.  */
#define   GMAC_NCR_RXEN_1_Val                 _UINT32_(0x1)                                        /* (GMAC_NCR) Enables the GMAC to receive data.  */
#define GMAC_NCR_RXEN_0                       (GMAC_NCR_RXEN_0_Val << GMAC_NCR_RXEN_Pos)           /* (GMAC_NCR) Stops frame reception immediately and the receive pipeline will be cleared. The Receive Queue Pointer register is unaffected. Position  */
#define GMAC_NCR_RXEN_1                       (GMAC_NCR_RXEN_1_Val << GMAC_NCR_RXEN_Pos)           /* (GMAC_NCR) Enables the GMAC to receive data. Position  */
#define GMAC_NCR_TXEN_Pos                     _UINT32_(3)                                          /* (GMAC_NCR) Transmit Enable Position */
#define GMAC_NCR_TXEN_Msk                     (_UINT32_(0x1) << GMAC_NCR_TXEN_Pos)                 /* (GMAC_NCR) Transmit Enable Mask */
#define GMAC_NCR_TXEN(value)                  (GMAC_NCR_TXEN_Msk & (_UINT32_(value) << GMAC_NCR_TXEN_Pos)) /* Assigment of value for TXEN in the GMAC_NCR register */
#define   GMAC_NCR_TXEN_0_Val                 _UINT32_(0x0)                                        /* (GMAC_NCR) Stops transmission immediately, the transmit pipeline and control registers will be cleared and the Transmit Queue Pointer Register will reset to point to the start of the transmit descriptor list.  */
#define   GMAC_NCR_TXEN_1_Val                 _UINT32_(0x1)                                        /* (GMAC_NCR) Enables the GMAC transmitter to send data.  */
#define GMAC_NCR_TXEN_0                       (GMAC_NCR_TXEN_0_Val << GMAC_NCR_TXEN_Pos)           /* (GMAC_NCR) Stops transmission immediately, the transmit pipeline and control registers will be cleared and the Transmit Queue Pointer Register will reset to point to the start of the transmit descriptor list. Position  */
#define GMAC_NCR_TXEN_1                       (GMAC_NCR_TXEN_1_Val << GMAC_NCR_TXEN_Pos)           /* (GMAC_NCR) Enables the GMAC transmitter to send data. Position  */
#define GMAC_NCR_MPE_Pos                      _UINT32_(4)                                          /* (GMAC_NCR) Management Port Enable Position */
#define GMAC_NCR_MPE_Msk                      (_UINT32_(0x1) << GMAC_NCR_MPE_Pos)                  /* (GMAC_NCR) Management Port Enable Mask */
#define GMAC_NCR_MPE(value)                   (GMAC_NCR_MPE_Msk & (_UINT32_(value) << GMAC_NCR_MPE_Pos)) /* Assigment of value for MPE in the GMAC_NCR register */
#define   GMAC_NCR_MPE_0_Val                  _UINT32_(0x0)                                        /* (GMAC_NCR) Forces GMDIO to high impedance state and MDC low.  */
#define   GMAC_NCR_MPE_1_Val                  _UINT32_(0x1)                                        /* (GMAC_NCR) Enables the management port.  */
#define GMAC_NCR_MPE_0                        (GMAC_NCR_MPE_0_Val << GMAC_NCR_MPE_Pos)             /* (GMAC_NCR) Forces GMDIO to high impedance state and MDC low. Position  */
#define GMAC_NCR_MPE_1                        (GMAC_NCR_MPE_1_Val << GMAC_NCR_MPE_Pos)             /* (GMAC_NCR) Enables the management port. Position  */
#define GMAC_NCR_CLRSTAT_Pos                  _UINT32_(5)                                          /* (GMAC_NCR) Clear Statistics Registers (Write-only) Position */
#define GMAC_NCR_CLRSTAT_Msk                  (_UINT32_(0x1) << GMAC_NCR_CLRSTAT_Pos)              /* (GMAC_NCR) Clear Statistics Registers (Write-only) Mask */
#define GMAC_NCR_CLRSTAT(value)               (GMAC_NCR_CLRSTAT_Msk & (_UINT32_(value) << GMAC_NCR_CLRSTAT_Pos)) /* Assigment of value for CLRSTAT in the GMAC_NCR register */
#define   GMAC_NCR_CLRSTAT_0_Val              _UINT32_(0x0)                                        /* (GMAC_NCR) No effect.  */
#define   GMAC_NCR_CLRSTAT_1_Val              _UINT32_(0x1)                                        /* (GMAC_NCR) Clears the statistics registers.  */
#define GMAC_NCR_CLRSTAT_0                    (GMAC_NCR_CLRSTAT_0_Val << GMAC_NCR_CLRSTAT_Pos)     /* (GMAC_NCR) No effect. Position  */
#define GMAC_NCR_CLRSTAT_1                    (GMAC_NCR_CLRSTAT_1_Val << GMAC_NCR_CLRSTAT_Pos)     /* (GMAC_NCR) Clears the statistics registers. Position  */
#define GMAC_NCR_INCSTAT_Pos                  _UINT32_(6)                                          /* (GMAC_NCR) Increment Statistics Registers (Write-only) Position */
#define GMAC_NCR_INCSTAT_Msk                  (_UINT32_(0x1) << GMAC_NCR_INCSTAT_Pos)              /* (GMAC_NCR) Increment Statistics Registers (Write-only) Mask */
#define GMAC_NCR_INCSTAT(value)               (GMAC_NCR_INCSTAT_Msk & (_UINT32_(value) << GMAC_NCR_INCSTAT_Pos)) /* Assigment of value for INCSTAT in the GMAC_NCR register */
#define GMAC_NCR_WESTAT_Pos                   _UINT32_(7)                                          /* (GMAC_NCR) Write Enable for Statistics Registers Position */
#define GMAC_NCR_WESTAT_Msk                   (_UINT32_(0x1) << GMAC_NCR_WESTAT_Pos)               /* (GMAC_NCR) Write Enable for Statistics Registers Mask */
#define GMAC_NCR_WESTAT(value)                (GMAC_NCR_WESTAT_Msk & (_UINT32_(value) << GMAC_NCR_WESTAT_Pos)) /* Assigment of value for WESTAT in the GMAC_NCR register */
#define   GMAC_NCR_WESTAT_0_Val               _UINT32_(0x0)                                        /* (GMAC_NCR) Forces the statistics registers to be in read-only mode for normal operation mode.  */
#define   GMAC_NCR_WESTAT_1_Val               _UINT32_(0x1)                                        /* (GMAC_NCR) Makes the statistics registers writable for functional test purposes.  */
#define GMAC_NCR_WESTAT_0                     (GMAC_NCR_WESTAT_0_Val << GMAC_NCR_WESTAT_Pos)       /* (GMAC_NCR) Forces the statistics registers to be in read-only mode for normal operation mode. Position  */
#define GMAC_NCR_WESTAT_1                     (GMAC_NCR_WESTAT_1_Val << GMAC_NCR_WESTAT_Pos)       /* (GMAC_NCR) Makes the statistics registers writable for functional test purposes. Position  */
#define GMAC_NCR_BP_Pos                       _UINT32_(8)                                          /* (GMAC_NCR) Back Pressure Position */
#define GMAC_NCR_BP_Msk                       (_UINT32_(0x1) << GMAC_NCR_BP_Pos)                   /* (GMAC_NCR) Back Pressure Mask */
#define GMAC_NCR_BP(value)                    (GMAC_NCR_BP_Msk & (_UINT32_(value) << GMAC_NCR_BP_Pos)) /* Assigment of value for BP in the GMAC_NCR register */
#define   GMAC_NCR_BP_0_Val                   _UINT32_(0x0)                                        /* (GMAC_NCR) No effect  */
#define   GMAC_NCR_BP_1_Val                   _UINT32_(0x1)                                        /* (GMAC_NCR) When the MAC is set in 10M or 100M Half Duplex mode, forces collisions on all received frames. Ignored in Gigabit Half Duplex mode.  */
#define GMAC_NCR_BP_0                         (GMAC_NCR_BP_0_Val << GMAC_NCR_BP_Pos)               /* (GMAC_NCR) No effect Position  */
#define GMAC_NCR_BP_1                         (GMAC_NCR_BP_1_Val << GMAC_NCR_BP_Pos)               /* (GMAC_NCR) When the MAC is set in 10M or 100M Half Duplex mode, forces collisions on all received frames. Ignored in Gigabit Half Duplex mode. Position  */
#define GMAC_NCR_TSTART_Pos                   _UINT32_(9)                                          /* (GMAC_NCR) Start Transmission (Write-only) Position */
#define GMAC_NCR_TSTART_Msk                   (_UINT32_(0x1) << GMAC_NCR_TSTART_Pos)               /* (GMAC_NCR) Start Transmission (Write-only) Mask */
#define GMAC_NCR_TSTART(value)                (GMAC_NCR_TSTART_Msk & (_UINT32_(value) << GMAC_NCR_TSTART_Pos)) /* Assigment of value for TSTART in the GMAC_NCR register */
#define   GMAC_NCR_TSTART_0_Val               _UINT32_(0x0)                                        /* (GMAC_NCR) No effect.  */
#define   GMAC_NCR_TSTART_1_Val               _UINT32_(0x1)                                        /* (GMAC_NCR) Starts transmission.  */
#define GMAC_NCR_TSTART_0                     (GMAC_NCR_TSTART_0_Val << GMAC_NCR_TSTART_Pos)       /* (GMAC_NCR) No effect. Position  */
#define GMAC_NCR_TSTART_1                     (GMAC_NCR_TSTART_1_Val << GMAC_NCR_TSTART_Pos)       /* (GMAC_NCR) Starts transmission. Position  */
#define GMAC_NCR_THALT_Pos                    _UINT32_(10)                                         /* (GMAC_NCR) Transmit Halt (Write-only) Position */
#define GMAC_NCR_THALT_Msk                    (_UINT32_(0x1) << GMAC_NCR_THALT_Pos)                /* (GMAC_NCR) Transmit Halt (Write-only) Mask */
#define GMAC_NCR_THALT(value)                 (GMAC_NCR_THALT_Msk & (_UINT32_(value) << GMAC_NCR_THALT_Pos)) /* Assigment of value for THALT in the GMAC_NCR register */
#define   GMAC_NCR_THALT_0_Val                _UINT32_(0x0)                                        /* (GMAC_NCR) No effect.  */
#define   GMAC_NCR_THALT_1_Val                _UINT32_(0x1)                                        /* (GMAC_NCR) Halts transmission as soon as any ongoing frame transmission ends.  */
#define GMAC_NCR_THALT_0                      (GMAC_NCR_THALT_0_Val << GMAC_NCR_THALT_Pos)         /* (GMAC_NCR) No effect. Position  */
#define GMAC_NCR_THALT_1                      (GMAC_NCR_THALT_1_Val << GMAC_NCR_THALT_Pos)         /* (GMAC_NCR) Halts transmission as soon as any ongoing frame transmission ends. Position  */
#define GMAC_NCR_TXPF_Pos                     _UINT32_(11)                                         /* (GMAC_NCR) Transmit Pause Frame (Write-only) Position */
#define GMAC_NCR_TXPF_Msk                     (_UINT32_(0x1) << GMAC_NCR_TXPF_Pos)                 /* (GMAC_NCR) Transmit Pause Frame (Write-only) Mask */
#define GMAC_NCR_TXPF(value)                  (GMAC_NCR_TXPF_Msk & (_UINT32_(value) << GMAC_NCR_TXPF_Pos)) /* Assigment of value for TXPF in the GMAC_NCR register */
#define   GMAC_NCR_TXPF_0_Val                 _UINT32_(0x0)                                        /* (GMAC_NCR) No effect.  */
#define   GMAC_NCR_TXPF_1_Val                 _UINT32_(0x1)                                        /* (GMAC_NCR) Generates a pause frame to be transmitted.  */
#define GMAC_NCR_TXPF_0                       (GMAC_NCR_TXPF_0_Val << GMAC_NCR_TXPF_Pos)           /* (GMAC_NCR) No effect. Position  */
#define GMAC_NCR_TXPF_1                       (GMAC_NCR_TXPF_1_Val << GMAC_NCR_TXPF_Pos)           /* (GMAC_NCR) Generates a pause frame to be transmitted. Position  */
#define GMAC_NCR_TXZQPF_Pos                   _UINT32_(12)                                         /* (GMAC_NCR) Transmit Zero Quantum Pause Frame (Write-only) Position */
#define GMAC_NCR_TXZQPF_Msk                   (_UINT32_(0x1) << GMAC_NCR_TXZQPF_Pos)               /* (GMAC_NCR) Transmit Zero Quantum Pause Frame (Write-only) Mask */
#define GMAC_NCR_TXZQPF(value)                (GMAC_NCR_TXZQPF_Msk & (_UINT32_(value) << GMAC_NCR_TXZQPF_Pos)) /* Assigment of value for TXZQPF in the GMAC_NCR register */
#define   GMAC_NCR_TXZQPF_0_Val               _UINT32_(0x0)                                        /* (GMAC_NCR) No effect.  */
#define   GMAC_NCR_TXZQPF_1_Val               _UINT32_(0x1)                                        /* (GMAC_NCR) Generates a pause frame with zero quantum to be transmitted.  */
#define GMAC_NCR_TXZQPF_0                     (GMAC_NCR_TXZQPF_0_Val << GMAC_NCR_TXZQPF_Pos)       /* (GMAC_NCR) No effect. Position  */
#define GMAC_NCR_TXZQPF_1                     (GMAC_NCR_TXZQPF_1_Val << GMAC_NCR_TXZQPF_Pos)       /* (GMAC_NCR) Generates a pause frame with zero quantum to be transmitted. Position  */
#define GMAC_NCR_SRTSM_Pos                    _UINT32_(15)                                         /* (GMAC_NCR) Store Receive Timestamp to Memory Position */
#define GMAC_NCR_SRTSM_Msk                    (_UINT32_(0x1) << GMAC_NCR_SRTSM_Pos)                /* (GMAC_NCR) Store Receive Timestamp to Memory Mask */
#define GMAC_NCR_SRTSM(value)                 (GMAC_NCR_SRTSM_Msk & (_UINT32_(value) << GMAC_NCR_SRTSM_Pos)) /* Assigment of value for SRTSM in the GMAC_NCR register */
#define   GMAC_NCR_SRTSM_0_Val                _UINT32_(0x0)                                        /* (GMAC_NCR) No effect.  */
#define   GMAC_NCR_SRTSM_1_Val                _UINT32_(0x1)                                        /* (GMAC_NCR) Causes the CRC of every received frame to be replaced with the value of the nanoseconds field of the 1588 timer that was captured as the receive frame passed the message timestamp point. Note that bit RFCS in register GMAC_NCFGR may not be set to 1 when the timer should be captured.  */
#define GMAC_NCR_SRTSM_0                      (GMAC_NCR_SRTSM_0_Val << GMAC_NCR_SRTSM_Pos)         /* (GMAC_NCR) No effect. Position  */
#define GMAC_NCR_SRTSM_1                      (GMAC_NCR_SRTSM_1_Val << GMAC_NCR_SRTSM_Pos)         /* (GMAC_NCR) Causes the CRC of every received frame to be replaced with the value of the nanoseconds field of the 1588 timer that was captured as the receive frame passed the message timestamp point. Note that bit RFCS in register GMAC_NCFGR may not be set to 1 when the timer should be captured. Position  */
#define GMAC_NCR_ENPBPR_Pos                   _UINT32_(16)                                         /* (GMAC_NCR) Enable PFC Priority-based Pause Reception Position */
#define GMAC_NCR_ENPBPR_Msk                   (_UINT32_(0x1) << GMAC_NCR_ENPBPR_Pos)               /* (GMAC_NCR) Enable PFC Priority-based Pause Reception Mask */
#define GMAC_NCR_ENPBPR(value)                (GMAC_NCR_ENPBPR_Msk & (_UINT32_(value) << GMAC_NCR_ENPBPR_Pos)) /* Assigment of value for ENPBPR in the GMAC_NCR register */
#define GMAC_NCR_TXPBPF_Pos                   _UINT32_(17)                                         /* (GMAC_NCR) Transmit PFC Priority-based Pause Frame Position */
#define GMAC_NCR_TXPBPF_Msk                   (_UINT32_(0x1) << GMAC_NCR_TXPBPF_Pos)               /* (GMAC_NCR) Transmit PFC Priority-based Pause Frame Mask */
#define GMAC_NCR_TXPBPF(value)                (GMAC_NCR_TXPBPF_Msk & (_UINT32_(value) << GMAC_NCR_TXPBPF_Pos)) /* Assigment of value for TXPBPF in the GMAC_NCR register */
#define   GMAC_NCR_TXPBPF_0_Val               _UINT32_(0x0)                                        /* (GMAC_NCR) No effect.  */
#define   GMAC_NCR_TXPBPF_1_Val               _UINT32_(0x1)                                        /* (GMAC_NCR) Takes the values stored in the Transmit PFC Pause Register.  */
#define GMAC_NCR_TXPBPF_0                     (GMAC_NCR_TXPBPF_0_Val << GMAC_NCR_TXPBPF_Pos)       /* (GMAC_NCR) No effect. Position  */
#define GMAC_NCR_TXPBPF_1                     (GMAC_NCR_TXPBPF_1_Val << GMAC_NCR_TXPBPF_Pos)       /* (GMAC_NCR) Takes the values stored in the Transmit PFC Pause Register. Position  */
#define GMAC_NCR_FNP_Pos                      _UINT32_(18)                                         /* (GMAC_NCR) Flush Next Packet Position */
#define GMAC_NCR_FNP_Msk                      (_UINT32_(0x1) << GMAC_NCR_FNP_Pos)                  /* (GMAC_NCR) Flush Next Packet Mask */
#define GMAC_NCR_FNP(value)                   (GMAC_NCR_FNP_Msk & (_UINT32_(value) << GMAC_NCR_FNP_Pos)) /* Assigment of value for FNP in the GMAC_NCR register */
#define   GMAC_NCR_FNP_0_Val                  _UINT32_(0x0)                                        /* (GMAC_NCR) No effect.  */
#define   GMAC_NCR_FNP_1_Val                  _UINT32_(0x1)                                        /* (GMAC_NCR) Flushes the next packet from the receive memory. This will only have an effect if the DMA is not currently writing a packet already stored in the receive memory to system memory.  */
#define GMAC_NCR_FNP_0                        (GMAC_NCR_FNP_0_Val << GMAC_NCR_FNP_Pos)             /* (GMAC_NCR) No effect. Position  */
#define GMAC_NCR_FNP_1                        (GMAC_NCR_FNP_1_Val << GMAC_NCR_FNP_Pos)             /* (GMAC_NCR) Flushes the next packet from the receive memory. This will only have an effect if the DMA is not currently writing a packet already stored in the receive memory to system memory. Position  */
#define GMAC_NCR_TXLPIEN_Pos                  _UINT32_(19)                                         /* (GMAC_NCR) Enable LPI Transmission Position */
#define GMAC_NCR_TXLPIEN_Msk                  (_UINT32_(0x1) << GMAC_NCR_TXLPIEN_Pos)              /* (GMAC_NCR) Enable LPI Transmission Mask */
#define GMAC_NCR_TXLPIEN(value)               (GMAC_NCR_TXLPIEN_Msk & (_UINT32_(value) << GMAC_NCR_TXLPIEN_Pos)) /* Assigment of value for TXLPIEN in the GMAC_NCR register */
#define GMAC_NCR_PTPUNIENA_Pos                _UINT32_(20)                                         /* (GMAC_NCR) Detection of Unicast PTP Frames Enable Position */
#define GMAC_NCR_PTPUNIENA_Msk                (_UINT32_(0x1) << GMAC_NCR_PTPUNIENA_Pos)            /* (GMAC_NCR) Detection of Unicast PTP Frames Enable Mask */
#define GMAC_NCR_PTPUNIENA(value)             (GMAC_NCR_PTPUNIENA_Msk & (_UINT32_(value) << GMAC_NCR_PTPUNIENA_Pos)) /* Assigment of value for PTPUNIENA in the GMAC_NCR register */
#define   GMAC_NCR_PTPUNIENA_0_Val            _UINT32_(0x0)                                        /* (GMAC_NCR) Disables detection of unicast PTP frames.  */
#define   GMAC_NCR_PTPUNIENA_1_Val            _UINT32_(0x1)                                        /* (GMAC_NCR) Enables detection of unicast PTP frames.  */
#define GMAC_NCR_PTPUNIENA_0                  (GMAC_NCR_PTPUNIENA_0_Val << GMAC_NCR_PTPUNIENA_Pos) /* (GMAC_NCR) Disables detection of unicast PTP frames. Position  */
#define GMAC_NCR_PTPUNIENA_1                  (GMAC_NCR_PTPUNIENA_1_Val << GMAC_NCR_PTPUNIENA_Pos) /* (GMAC_NCR) Enables detection of unicast PTP frames. Position  */
#define GMAC_NCR_STUDPOFFSET_Pos              _UINT32_(22)                                         /* (GMAC_NCR) Store UDP Offset Position */
#define GMAC_NCR_STUDPOFFSET_Msk              (_UINT32_(0x1) << GMAC_NCR_STUDPOFFSET_Pos)          /* (GMAC_NCR) Store UDP Offset Mask */
#define GMAC_NCR_STUDPOFFSET(value)           (GMAC_NCR_STUDPOFFSET_Msk & (_UINT32_(value) << GMAC_NCR_STUDPOFFSET_Pos)) /* Assigment of value for STUDPOFFSET in the GMAC_NCR register */
#define   GMAC_NCR_STUDPOFFSET_0_Val          _UINT32_(0x0)                                        /* (GMAC_NCR) Normal operations.  */
#define   GMAC_NCR_STUDPOFFSET_1_Val          _UINT32_(0x1)                                        /* (GMAC_NCR) The upper 16 bits of the CRC of every received frame are replaced with the offset from start of frame to the beginning of the UDP or TCP header. The lower 16 bits of the CRC are replaced with zero and reserved for future use. The offset is measured in units of 2 bytes.  */
#define GMAC_NCR_STUDPOFFSET_0                (GMAC_NCR_STUDPOFFSET_0_Val << GMAC_NCR_STUDPOFFSET_Pos) /* (GMAC_NCR) Normal operations. Position  */
#define GMAC_NCR_STUDPOFFSET_1                (GMAC_NCR_STUDPOFFSET_1_Val << GMAC_NCR_STUDPOFFSET_Pos) /* (GMAC_NCR) The upper 16 bits of the CRC of every received frame are replaced with the offset from start of frame to the beginning of the UDP or TCP header. The lower 16 bits of the CRC are replaced with zero and reserved for future use. The offset is measured in units of 2 bytes. Position  */
#define GMAC_NCR_OSSMODE_Pos                  _UINT32_(24)                                         /* (GMAC_NCR) One Step Sync Mode Position */
#define GMAC_NCR_OSSMODE_Msk                  (_UINT32_(0x1) << GMAC_NCR_OSSMODE_Pos)              /* (GMAC_NCR) One Step Sync Mode Mask */
#define GMAC_NCR_OSSMODE(value)               (GMAC_NCR_OSSMODE_Msk & (_UINT32_(value) << GMAC_NCR_OSSMODE_Pos)) /* Assigment of value for OSSMODE in the GMAC_NCR register */
#define   GMAC_NCR_OSSMODE_0_Val              _UINT32_(0x0)                                        /* (GMAC_NCR) 1588 One Step Sync Mode is disabled.  */
#define   GMAC_NCR_OSSMODE_1_Val              _UINT32_(0x1)                                        /* (GMAC_NCR) 1588 One Step Sync Mode is enabled. Replaces timestamp field in the 1588 header for TX Sync Frames with the current TSU timer value.  */
#define GMAC_NCR_OSSMODE_0                    (GMAC_NCR_OSSMODE_0_Val << GMAC_NCR_OSSMODE_Pos)     /* (GMAC_NCR) 1588 One Step Sync Mode is disabled. Position  */
#define GMAC_NCR_OSSMODE_1                    (GMAC_NCR_OSSMODE_1_Val << GMAC_NCR_OSSMODE_Pos)     /* (GMAC_NCR) 1588 One Step Sync Mode is enabled. Replaces timestamp field in the 1588 header for TX Sync Frames with the current TSU timer value. Position  */
#define GMAC_NCR_PFCCTL_Pos                   _UINT32_(25)                                         /* (GMAC_NCR) Multiple PFC Pause quantum Enable Position */
#define GMAC_NCR_PFCCTL_Msk                   (_UINT32_(0x1) << GMAC_NCR_PFCCTL_Pos)               /* (GMAC_NCR) Multiple PFC Pause quantum Enable Mask */
#define GMAC_NCR_PFCCTL(value)                (GMAC_NCR_PFCCTL_Msk & (_UINT32_(value) << GMAC_NCR_PFCCTL_Pos)) /* Assigment of value for PFCCTL in the GMAC_NCR register */
#define   GMAC_NCR_PFCCTL_0_Val               _UINT32_(0x0)                                        /* (GMAC_NCR) Disables multiple PFC pause quantums.  */
#define   GMAC_NCR_PFCCTL_1_Val               _UINT32_(0x1)                                        /* (GMAC_NCR) Enables multiple PFC pause quantums, one per pause priority.  */
#define GMAC_NCR_PFCCTL_0                     (GMAC_NCR_PFCCTL_0_Val << GMAC_NCR_PFCCTL_Pos)       /* (GMAC_NCR) Disables multiple PFC pause quantums. Position  */
#define GMAC_NCR_PFCCTL_1                     (GMAC_NCR_PFCCTL_1_Val << GMAC_NCR_PFCCTL_Pos)       /* (GMAC_NCR) Enables multiple PFC pause quantums, one per pause priority. Position  */
#define GMAC_NCR_EXTSELRQEN_Pos               _UINT32_(26)                                         /* (GMAC_NCR) External Selection of Receive Queue Enable Position */
#define GMAC_NCR_EXTSELRQEN_Msk               (_UINT32_(0x1) << GMAC_NCR_EXTSELRQEN_Pos)           /* (GMAC_NCR) External Selection of Receive Queue Enable Mask */
#define GMAC_NCR_EXTSELRQEN(value)            (GMAC_NCR_EXTSELRQEN_Msk & (_UINT32_(value) << GMAC_NCR_EXTSELRQEN_Pos)) /* Assigment of value for EXTSELRQEN in the GMAC_NCR register */
#define   GMAC_NCR_EXTSELRQEN_0_Val           _UINT32_(0x0)                                        /* (GMAC_NCR) Disables external selection of receive queue.  */
#define   GMAC_NCR_EXTSELRQEN_1_Val           _UINT32_(0x1)                                        /* (GMAC_NCR) Enables external selection of receive queue.  */
#define GMAC_NCR_EXTSELRQEN_0                 (GMAC_NCR_EXTSELRQEN_0_Val << GMAC_NCR_EXTSELRQEN_Pos) /* (GMAC_NCR) Disables external selection of receive queue. Position  */
#define GMAC_NCR_EXTSELRQEN_1                 (GMAC_NCR_EXTSELRQEN_1_Val << GMAC_NCR_EXTSELRQEN_Pos) /* (GMAC_NCR) Enables external selection of receive queue. Position  */
#define GMAC_NCR_OSSCORR_Pos                  _UINT32_(27)                                         /* (GMAC_NCR) OSS Correction Field Position */
#define GMAC_NCR_OSSCORR_Msk                  (_UINT32_(0x1) << GMAC_NCR_OSSCORR_Pos)              /* (GMAC_NCR) OSS Correction Field Mask */
#define GMAC_NCR_OSSCORR(value)               (GMAC_NCR_OSSCORR_Msk & (_UINT32_(value) << GMAC_NCR_OSSCORR_Pos)) /* Assigment of value for OSSCORR in the GMAC_NCR register */
#define GMAC_NCR_IFGQAVCRED_Pos               _UINT32_(30)                                         /* (GMAC_NCR) Credit-Based Shaping Algorithm Modification Position */
#define GMAC_NCR_IFGQAVCRED_Msk               (_UINT32_(0x1) << GMAC_NCR_IFGQAVCRED_Pos)           /* (GMAC_NCR) Credit-Based Shaping Algorithm Modification Mask */
#define GMAC_NCR_IFGQAVCRED(value)            (GMAC_NCR_IFGQAVCRED_Msk & (_UINT32_(value) << GMAC_NCR_IFGQAVCRED_Pos)) /* Assigment of value for IFGQAVCRED in the GMAC_NCR register */
#define   GMAC_NCR_IFGQAVCRED_0_Val           _UINT32_(0x0)                                        /* (GMAC_NCR) No modification of the CBS algorithm.  */
#define   GMAC_NCR_IFGQAVCRED_1_Val           _UINT32_(0x1)                                        /* (GMAC_NCR) Modifies the CBS algorithm so the IFG/IPG associated with a transmit frame counts towards its 802.1Qav credit.  */
#define GMAC_NCR_IFGQAVCRED_0                 (GMAC_NCR_IFGQAVCRED_0_Val << GMAC_NCR_IFGQAVCRED_Pos) /* (GMAC_NCR) No modification of the CBS algorithm. Position  */
#define GMAC_NCR_IFGQAVCRED_1                 (GMAC_NCR_IFGQAVCRED_1_Val << GMAC_NCR_IFGQAVCRED_Pos) /* (GMAC_NCR) Modifies the CBS algorithm so the IFG/IPG associated with a transmit frame counts towards its 802.1Qav credit. Position  */
#define GMAC_NCR_Msk                          _UINT32_(0x4F5F9FFE)                                 /* (GMAC_NCR) Register Mask  */


/* -------- GMAC_NCFGR : (GMAC Offset: 0x04) (R/W 32) Network Configuration Register -------- */
#define GMAC_NCFGR_RESETVALUE                 _UINT32_(0x80000)                                    /*  (GMAC_NCFGR) Network Configuration Register  Reset Value */

#define GMAC_NCFGR_SPD_Pos                    _UINT32_(0)                                          /* (GMAC_NCFGR) Speed Position */
#define GMAC_NCFGR_SPD_Msk                    (_UINT32_(0x1) << GMAC_NCFGR_SPD_Pos)                /* (GMAC_NCFGR) Speed Mask */
#define GMAC_NCFGR_SPD(value)                 (GMAC_NCFGR_SPD_Msk & (_UINT32_(value) << GMAC_NCFGR_SPD_Pos)) /* Assigment of value for SPD in the GMAC_NCFGR register */
#define GMAC_NCFGR_FD_Pos                     _UINT32_(1)                                          /* (GMAC_NCFGR) Full Duplex Position */
#define GMAC_NCFGR_FD_Msk                     (_UINT32_(0x1) << GMAC_NCFGR_FD_Pos)                 /* (GMAC_NCFGR) Full Duplex Mask */
#define GMAC_NCFGR_FD(value)                  (GMAC_NCFGR_FD_Msk & (_UINT32_(value) << GMAC_NCFGR_FD_Pos)) /* Assigment of value for FD in the GMAC_NCFGR register */
#define GMAC_NCFGR_DNVLAN_Pos                 _UINT32_(2)                                          /* (GMAC_NCFGR) Discard Non-VLAN FRAMES Position */
#define GMAC_NCFGR_DNVLAN_Msk                 (_UINT32_(0x1) << GMAC_NCFGR_DNVLAN_Pos)             /* (GMAC_NCFGR) Discard Non-VLAN FRAMES Mask */
#define GMAC_NCFGR_DNVLAN(value)              (GMAC_NCFGR_DNVLAN_Msk & (_UINT32_(value) << GMAC_NCFGR_DNVLAN_Pos)) /* Assigment of value for DNVLAN in the GMAC_NCFGR register */
#define GMAC_NCFGR_JFRAME_Pos                 _UINT32_(3)                                          /* (GMAC_NCFGR) Jumbo Frame Size Position */
#define GMAC_NCFGR_JFRAME_Msk                 (_UINT32_(0x1) << GMAC_NCFGR_JFRAME_Pos)             /* (GMAC_NCFGR) Jumbo Frame Size Mask */
#define GMAC_NCFGR_JFRAME(value)              (GMAC_NCFGR_JFRAME_Msk & (_UINT32_(value) << GMAC_NCFGR_JFRAME_Pos)) /* Assigment of value for JFRAME in the GMAC_NCFGR register */
#define GMAC_NCFGR_CAF_Pos                    _UINT32_(4)                                          /* (GMAC_NCFGR) Copy All Frames Position */
#define GMAC_NCFGR_CAF_Msk                    (_UINT32_(0x1) << GMAC_NCFGR_CAF_Pos)                /* (GMAC_NCFGR) Copy All Frames Mask */
#define GMAC_NCFGR_CAF(value)                 (GMAC_NCFGR_CAF_Msk & (_UINT32_(value) << GMAC_NCFGR_CAF_Pos)) /* Assigment of value for CAF in the GMAC_NCFGR register */
#define GMAC_NCFGR_NBC_Pos                    _UINT32_(5)                                          /* (GMAC_NCFGR) No Broadcast Position */
#define GMAC_NCFGR_NBC_Msk                    (_UINT32_(0x1) << GMAC_NCFGR_NBC_Pos)                /* (GMAC_NCFGR) No Broadcast Mask */
#define GMAC_NCFGR_NBC(value)                 (GMAC_NCFGR_NBC_Msk & (_UINT32_(value) << GMAC_NCFGR_NBC_Pos)) /* Assigment of value for NBC in the GMAC_NCFGR register */
#define GMAC_NCFGR_MTIHEN_Pos                 _UINT32_(6)                                          /* (GMAC_NCFGR) Multicast Hash Enable Position */
#define GMAC_NCFGR_MTIHEN_Msk                 (_UINT32_(0x1) << GMAC_NCFGR_MTIHEN_Pos)             /* (GMAC_NCFGR) Multicast Hash Enable Mask */
#define GMAC_NCFGR_MTIHEN(value)              (GMAC_NCFGR_MTIHEN_Msk & (_UINT32_(value) << GMAC_NCFGR_MTIHEN_Pos)) /* Assigment of value for MTIHEN in the GMAC_NCFGR register */
#define GMAC_NCFGR_UNIHEN_Pos                 _UINT32_(7)                                          /* (GMAC_NCFGR) Unicast Hash Enable Position */
#define GMAC_NCFGR_UNIHEN_Msk                 (_UINT32_(0x1) << GMAC_NCFGR_UNIHEN_Pos)             /* (GMAC_NCFGR) Unicast Hash Enable Mask */
#define GMAC_NCFGR_UNIHEN(value)              (GMAC_NCFGR_UNIHEN_Msk & (_UINT32_(value) << GMAC_NCFGR_UNIHEN_Pos)) /* Assigment of value for UNIHEN in the GMAC_NCFGR register */
#define GMAC_NCFGR_MAXFS_Pos                  _UINT32_(8)                                          /* (GMAC_NCFGR) 1536 Maximum Frame Size Position */
#define GMAC_NCFGR_MAXFS_Msk                  (_UINT32_(0x1) << GMAC_NCFGR_MAXFS_Pos)              /* (GMAC_NCFGR) 1536 Maximum Frame Size Mask */
#define GMAC_NCFGR_MAXFS(value)               (GMAC_NCFGR_MAXFS_Msk & (_UINT32_(value) << GMAC_NCFGR_MAXFS_Pos)) /* Assigment of value for MAXFS in the GMAC_NCFGR register */
#define GMAC_NCFGR_GBE_Pos                    _UINT32_(10)                                         /* (GMAC_NCFGR) Gigabit Mode Enable Position */
#define GMAC_NCFGR_GBE_Msk                    (_UINT32_(0x1) << GMAC_NCFGR_GBE_Pos)                /* (GMAC_NCFGR) Gigabit Mode Enable Mask */
#define GMAC_NCFGR_GBE(value)                 (GMAC_NCFGR_GBE_Msk & (_UINT32_(value) << GMAC_NCFGR_GBE_Pos)) /* Assigment of value for GBE in the GMAC_NCFGR register */
#define   GMAC_NCFGR_GBE_0_Val                _UINT32_(0x0)                                        /* (GMAC_NCFGR) 10/100 operation.  */
#define   GMAC_NCFGR_GBE_1_Val                _UINT32_(0x1)                                        /* (GMAC_NCFGR) Gigabit operation.  */
#define GMAC_NCFGR_GBE_0                      (GMAC_NCFGR_GBE_0_Val << GMAC_NCFGR_GBE_Pos)         /* (GMAC_NCFGR) 10/100 operation. Position  */
#define GMAC_NCFGR_GBE_1                      (GMAC_NCFGR_GBE_1_Val << GMAC_NCFGR_GBE_Pos)         /* (GMAC_NCFGR) Gigabit operation. Position  */
#define GMAC_NCFGR_RTY_Pos                    _UINT32_(12)                                         /* (GMAC_NCFGR) Retry Test0 Position */
#define GMAC_NCFGR_RTY_Msk                    (_UINT32_(0x1) << GMAC_NCFGR_RTY_Pos)                /* (GMAC_NCFGR) Retry Test0 Mask */
#define GMAC_NCFGR_RTY(value)                 (GMAC_NCFGR_RTY_Msk & (_UINT32_(value) << GMAC_NCFGR_RTY_Pos)) /* Assigment of value for RTY in the GMAC_NCFGR register */
#define GMAC_NCFGR_PEN_Pos                    _UINT32_(13)                                         /* (GMAC_NCFGR) Pause Enable Position */
#define GMAC_NCFGR_PEN_Msk                    (_UINT32_(0x1) << GMAC_NCFGR_PEN_Pos)                /* (GMAC_NCFGR) Pause Enable Mask */
#define GMAC_NCFGR_PEN(value)                 (GMAC_NCFGR_PEN_Msk & (_UINT32_(value) << GMAC_NCFGR_PEN_Pos)) /* Assigment of value for PEN in the GMAC_NCFGR register */
#define GMAC_NCFGR_RXBUFO_Pos                 _UINT32_(14)                                         /* (GMAC_NCFGR) Receive Buffer Offset Position */
#define GMAC_NCFGR_RXBUFO_Msk                 (_UINT32_(0x3) << GMAC_NCFGR_RXBUFO_Pos)             /* (GMAC_NCFGR) Receive Buffer Offset Mask */
#define GMAC_NCFGR_RXBUFO(value)              (GMAC_NCFGR_RXBUFO_Msk & (_UINT32_(value) << GMAC_NCFGR_RXBUFO_Pos)) /* Assigment of value for RXBUFO in the GMAC_NCFGR register */
#define GMAC_NCFGR_LFERD_Pos                  _UINT32_(16)                                         /* (GMAC_NCFGR) Length Field Error Frame Discard Position */
#define GMAC_NCFGR_LFERD_Msk                  (_UINT32_(0x1) << GMAC_NCFGR_LFERD_Pos)              /* (GMAC_NCFGR) Length Field Error Frame Discard Mask */
#define GMAC_NCFGR_LFERD(value)               (GMAC_NCFGR_LFERD_Msk & (_UINT32_(value) << GMAC_NCFGR_LFERD_Pos)) /* Assigment of value for LFERD in the GMAC_NCFGR register */
#define GMAC_NCFGR_RFCS_Pos                   _UINT32_(17)                                         /* (GMAC_NCFGR) Remove FCS Position */
#define GMAC_NCFGR_RFCS_Msk                   (_UINT32_(0x1) << GMAC_NCFGR_RFCS_Pos)               /* (GMAC_NCFGR) Remove FCS Mask */
#define GMAC_NCFGR_RFCS(value)                (GMAC_NCFGR_RFCS_Msk & (_UINT32_(value) << GMAC_NCFGR_RFCS_Pos)) /* Assigment of value for RFCS in the GMAC_NCFGR register */
#define GMAC_NCFGR_CLK_Pos                    _UINT32_(18)                                         /* (GMAC_NCFGR) MDC CLock Division Position */
#define GMAC_NCFGR_CLK_Msk                    (_UINT32_(0x7) << GMAC_NCFGR_CLK_Pos)                /* (GMAC_NCFGR) MDC CLock Division Mask */
#define GMAC_NCFGR_CLK(value)                 (GMAC_NCFGR_CLK_Msk & (_UINT32_(value) << GMAC_NCFGR_CLK_Pos)) /* Assigment of value for CLK in the GMAC_NCFGR register */
#define   GMAC_NCFGR_CLK_MCK_8_Val            _UINT32_(0x0)                                        /* (GMAC_NCFGR) MCK divided by 8 (MCK up to 20 MHz)  */
#define   GMAC_NCFGR_CLK_MCK_16_Val           _UINT32_(0x1)                                        /* (GMAC_NCFGR) MCK divided by 16 (MCK up to 40 MHz)  */
#define   GMAC_NCFGR_CLK_MCK_32_Val           _UINT32_(0x2)                                        /* (GMAC_NCFGR) MCK divided by 32 (MCK up to 80 MHz)  */
#define   GMAC_NCFGR_CLK_MCK_48_Val           _UINT32_(0x3)                                        /* (GMAC_NCFGR) MCK divided by 48 (MCK up to 120 MHz)  */
#define   GMAC_NCFGR_CLK_MCK_64_Val           _UINT32_(0x4)                                        /* (GMAC_NCFGR) MCK divided by 64 (MCK up to 160 MHz)  */
#define   GMAC_NCFGR_CLK_MCK_96_Val           _UINT32_(0x5)                                        /* (GMAC_NCFGR) MCK divided by 96 (MCK up to 240 MHz)  */
#define GMAC_NCFGR_CLK_MCK_8                  (GMAC_NCFGR_CLK_MCK_8_Val << GMAC_NCFGR_CLK_Pos)     /* (GMAC_NCFGR) MCK divided by 8 (MCK up to 20 MHz) Position  */
#define GMAC_NCFGR_CLK_MCK_16                 (GMAC_NCFGR_CLK_MCK_16_Val << GMAC_NCFGR_CLK_Pos)    /* (GMAC_NCFGR) MCK divided by 16 (MCK up to 40 MHz) Position  */
#define GMAC_NCFGR_CLK_MCK_32                 (GMAC_NCFGR_CLK_MCK_32_Val << GMAC_NCFGR_CLK_Pos)    /* (GMAC_NCFGR) MCK divided by 32 (MCK up to 80 MHz) Position  */
#define GMAC_NCFGR_CLK_MCK_48                 (GMAC_NCFGR_CLK_MCK_48_Val << GMAC_NCFGR_CLK_Pos)    /* (GMAC_NCFGR) MCK divided by 48 (MCK up to 120 MHz) Position  */
#define GMAC_NCFGR_CLK_MCK_64                 (GMAC_NCFGR_CLK_MCK_64_Val << GMAC_NCFGR_CLK_Pos)    /* (GMAC_NCFGR) MCK divided by 64 (MCK up to 160 MHz) Position  */
#define GMAC_NCFGR_CLK_MCK_96                 (GMAC_NCFGR_CLK_MCK_96_Val << GMAC_NCFGR_CLK_Pos)    /* (GMAC_NCFGR) MCK divided by 96 (MCK up to 240 MHz) Position  */
#define GMAC_NCFGR_DBW_Pos                    _UINT32_(21)                                         /* (GMAC_NCFGR) Data Bus Width Position */
#define GMAC_NCFGR_DBW_Msk                    (_UINT32_(0x3) << GMAC_NCFGR_DBW_Pos)                /* (GMAC_NCFGR) Data Bus Width Mask */
#define GMAC_NCFGR_DBW(value)                 (GMAC_NCFGR_DBW_Msk & (_UINT32_(value) << GMAC_NCFGR_DBW_Pos)) /* Assigment of value for DBW in the GMAC_NCFGR register */
#define GMAC_NCFGR_DCPF_Pos                   _UINT32_(23)                                         /* (GMAC_NCFGR) Disable Copy of Pause Frames Position */
#define GMAC_NCFGR_DCPF_Msk                   (_UINT32_(0x1) << GMAC_NCFGR_DCPF_Pos)               /* (GMAC_NCFGR) Disable Copy of Pause Frames Mask */
#define GMAC_NCFGR_DCPF(value)                (GMAC_NCFGR_DCPF_Msk & (_UINT32_(value) << GMAC_NCFGR_DCPF_Pos)) /* Assigment of value for DCPF in the GMAC_NCFGR register */
#define GMAC_NCFGR_RXCOEN_Pos                 _UINT32_(24)                                         /* (GMAC_NCFGR) Receive Checksum Offload Enable Position */
#define GMAC_NCFGR_RXCOEN_Msk                 (_UINT32_(0x1) << GMAC_NCFGR_RXCOEN_Pos)             /* (GMAC_NCFGR) Receive Checksum Offload Enable Mask */
#define GMAC_NCFGR_RXCOEN(value)              (GMAC_NCFGR_RXCOEN_Msk & (_UINT32_(value) << GMAC_NCFGR_RXCOEN_Pos)) /* Assigment of value for RXCOEN in the GMAC_NCFGR register */
#define GMAC_NCFGR_EFRHD_Pos                  _UINT32_(25)                                         /* (GMAC_NCFGR) Enable Frames Received in Half Duplex Position */
#define GMAC_NCFGR_EFRHD_Msk                  (_UINT32_(0x1) << GMAC_NCFGR_EFRHD_Pos)              /* (GMAC_NCFGR) Enable Frames Received in Half Duplex Mask */
#define GMAC_NCFGR_EFRHD(value)               (GMAC_NCFGR_EFRHD_Msk & (_UINT32_(value) << GMAC_NCFGR_EFRHD_Pos)) /* Assigment of value for EFRHD in the GMAC_NCFGR register */
#define GMAC_NCFGR_IRXFCS_Pos                 _UINT32_(26)                                         /* (GMAC_NCFGR) Ignore RX FCS Position */
#define GMAC_NCFGR_IRXFCS_Msk                 (_UINT32_(0x1) << GMAC_NCFGR_IRXFCS_Pos)             /* (GMAC_NCFGR) Ignore RX FCS Mask */
#define GMAC_NCFGR_IRXFCS(value)              (GMAC_NCFGR_IRXFCS_Msk & (_UINT32_(value) << GMAC_NCFGR_IRXFCS_Pos)) /* Assigment of value for IRXFCS in the GMAC_NCFGR register */
#define GMAC_NCFGR_IPGSEN_Pos                 _UINT32_(28)                                         /* (GMAC_NCFGR) IP Stretch Enable Position */
#define GMAC_NCFGR_IPGSEN_Msk                 (_UINT32_(0x1) << GMAC_NCFGR_IPGSEN_Pos)             /* (GMAC_NCFGR) IP Stretch Enable Mask */
#define GMAC_NCFGR_IPGSEN(value)              (GMAC_NCFGR_IPGSEN_Msk & (_UINT32_(value) << GMAC_NCFGR_IPGSEN_Pos)) /* Assigment of value for IPGSEN in the GMAC_NCFGR register */
#define GMAC_NCFGR_RXBP_Pos                   _UINT32_(29)                                         /* (GMAC_NCFGR) Receive Bad Preamble Position */
#define GMAC_NCFGR_RXBP_Msk                   (_UINT32_(0x1) << GMAC_NCFGR_RXBP_Pos)               /* (GMAC_NCFGR) Receive Bad Preamble Mask */
#define GMAC_NCFGR_RXBP(value)                (GMAC_NCFGR_RXBP_Msk & (_UINT32_(value) << GMAC_NCFGR_RXBP_Pos)) /* Assigment of value for RXBP in the GMAC_NCFGR register */
#define GMAC_NCFGR_IRXER_Pos                  _UINT32_(30)                                         /* (GMAC_NCFGR) Ignore Receive Error from PHY Position */
#define GMAC_NCFGR_IRXER_Msk                  (_UINT32_(0x1) << GMAC_NCFGR_IRXER_Pos)              /* (GMAC_NCFGR) Ignore Receive Error from PHY Mask */
#define GMAC_NCFGR_IRXER(value)               (GMAC_NCFGR_IRXER_Msk & (_UINT32_(value) << GMAC_NCFGR_IRXER_Pos)) /* Assigment of value for IRXER in the GMAC_NCFGR register */
#define GMAC_NCFGR_Msk                        _UINT32_(0x77FFF5FF)                                 /* (GMAC_NCFGR) Register Mask  */


/* -------- GMAC_NSR : (GMAC Offset: 0x08) ( R/ 32) Network Status Register -------- */
#define GMAC_NSR_MDIO_Pos                     _UINT32_(1)                                          /* (GMAC_NSR) MDIO Input Status Position */
#define GMAC_NSR_MDIO_Msk                     (_UINT32_(0x1) << GMAC_NSR_MDIO_Pos)                 /* (GMAC_NSR) MDIO Input Status Mask */
#define GMAC_NSR_MDIO(value)                  (GMAC_NSR_MDIO_Msk & (_UINT32_(value) << GMAC_NSR_MDIO_Pos)) /* Assigment of value for MDIO in the GMAC_NSR register */
#define GMAC_NSR_IDLE_Pos                     _UINT32_(2)                                          /* (GMAC_NSR) PHY Management Logic Idle Position */
#define GMAC_NSR_IDLE_Msk                     (_UINT32_(0x1) << GMAC_NSR_IDLE_Pos)                 /* (GMAC_NSR) PHY Management Logic Idle Mask */
#define GMAC_NSR_IDLE(value)                  (GMAC_NSR_IDLE_Msk & (_UINT32_(value) << GMAC_NSR_IDLE_Pos)) /* Assigment of value for IDLE in the GMAC_NSR register */
#define GMAC_NSR_PFCPAUSN_Pos                 _UINT32_(6)                                          /* (GMAC_NSR) PFC Pause Negotiated Position */
#define GMAC_NSR_PFCPAUSN_Msk                 (_UINT32_(0x1) << GMAC_NSR_PFCPAUSN_Pos)             /* (GMAC_NSR) PFC Pause Negotiated Mask */
#define GMAC_NSR_PFCPAUSN(value)              (GMAC_NSR_PFCPAUSN_Msk & (_UINT32_(value) << GMAC_NSR_PFCPAUSN_Pos)) /* Assigment of value for PFCPAUSN in the GMAC_NSR register */
#define GMAC_NSR_RXLPIS_Pos                   _UINT32_(7)                                          /* (GMAC_NSR) LPI Indication Position */
#define GMAC_NSR_RXLPIS_Msk                   (_UINT32_(0x1) << GMAC_NSR_RXLPIS_Pos)               /* (GMAC_NSR) LPI Indication Mask */
#define GMAC_NSR_RXLPIS(value)                (GMAC_NSR_RXLPIS_Msk & (_UINT32_(value) << GMAC_NSR_RXLPIS_Pos)) /* Assigment of value for RXLPIS in the GMAC_NSR register */
#define GMAC_NSR_Msk                          _UINT32_(0x000000C6)                                 /* (GMAC_NSR) Register Mask  */


/* -------- GMAC_UR : (GMAC Offset: 0x0C) (R/W 32) User Register -------- */
#define GMAC_UR_RESETVALUE                    _UINT32_(0x00)                                       /*  (GMAC_UR) User Register  Reset Value */

#define GMAC_UR_MIM_Pos                       _UINT32_(0)                                          /* (GMAC_UR) Media Interface Mode Position */
#define GMAC_UR_MIM_Msk                       (_UINT32_(0x3) << GMAC_UR_MIM_Pos)                   /* (GMAC_UR) Media Interface Mode Mask */
#define GMAC_UR_MIM(value)                    (GMAC_UR_MIM_Msk & (_UINT32_(value) << GMAC_UR_MIM_Pos)) /* Assigment of value for MIM in the GMAC_UR register */
#define   GMAC_UR_MIM_RMII_Val                _UINT32_(0x1)                                        /* (GMAC_UR) Selects the RMII mode.  */
#define   GMAC_UR_MIM_RGMII_Val               _UINT32_(0x2)                                        /* (GMAC_UR) Selects the RGMII mode.  */
#define GMAC_UR_MIM_RMII                      (GMAC_UR_MIM_RMII_Val << GMAC_UR_MIM_Pos)            /* (GMAC_UR) Selects the RMII mode. Position  */
#define GMAC_UR_MIM_RGMII                     (GMAC_UR_MIM_RGMII_Val << GMAC_UR_MIM_Pos)           /* (GMAC_UR) Selects the RGMII mode. Position  */
#define GMAC_UR_REFCLK_Pos                    _UINT32_(2)                                          /* (GMAC_UR) Source for the GMAC Reference Clock Position */
#define GMAC_UR_REFCLK_Msk                    (_UINT32_(0x1) << GMAC_UR_REFCLK_Pos)                /* (GMAC_UR) Source for the GMAC Reference Clock Mask */
#define GMAC_UR_REFCLK(value)                 (GMAC_UR_REFCLK_Msk & (_UINT32_(value) << GMAC_UR_REFCLK_Pos)) /* Assigment of value for REFCLK in the GMAC_UR register */
#define   GMAC_UR_REFCLK_INTERNAL_GCLK_Val    _UINT32_(0x0)                                        /* (GMAC_UR) Selects the GCLK from PMC  */
#define   GMAC_UR_REFCLK_EXTERNAL_Val         _UINT32_(0x1)                                        /* (GMAC_UR) Selects the clock from an IO  */
#define GMAC_UR_REFCLK_INTERNAL_GCLK          (GMAC_UR_REFCLK_INTERNAL_GCLK_Val << GMAC_UR_REFCLK_Pos) /* (GMAC_UR) Selects the GCLK from PMC Position  */
#define GMAC_UR_REFCLK_EXTERNAL               (GMAC_UR_REFCLK_EXTERNAL_Val << GMAC_UR_REFCLK_Pos)  /* (GMAC_UR) Selects the clock from an IO Position  */
#define GMAC_UR_HDFLCTLEN_Pos                 _UINT32_(6)                                          /* (GMAC_UR) Half Duplex Flow Control Enable Position */
#define GMAC_UR_HDFLCTLEN_Msk                 (_UINT32_(0x1) << GMAC_UR_HDFLCTLEN_Pos)             /* (GMAC_UR) Half Duplex Flow Control Enable Mask */
#define GMAC_UR_HDFLCTLEN(value)              (GMAC_UR_HDFLCTLEN_Msk & (_UINT32_(value) << GMAC_UR_HDFLCTLEN_Pos)) /* Assigment of value for HDFLCTLEN in the GMAC_UR register */
#define   GMAC_UR_HDFLCTLEN_0_Val             _UINT32_(0x0)                                        /* (GMAC_UR) Half duplex flow control is disabled.  */
#define   GMAC_UR_HDFLCTLEN_1_Val             _UINT32_(0x1)                                        /* (GMAC_UR) Half duplex flow control is enabled.  */
#define GMAC_UR_HDFLCTLEN_0                   (GMAC_UR_HDFLCTLEN_0_Val << GMAC_UR_HDFLCTLEN_Pos)   /* (GMAC_UR) Half duplex flow control is disabled. Position  */
#define GMAC_UR_HDFLCTLEN_1                   (GMAC_UR_HDFLCTLEN_1_Val << GMAC_UR_HDFLCTLEN_Pos)   /* (GMAC_UR) Half duplex flow control is enabled. Position  */
#define GMAC_UR_Msk                           _UINT32_(0x00000047)                                 /* (GMAC_UR) Register Mask  */


/* -------- GMAC_DCFGR : (GMAC Offset: 0x10) (R/W 32) DMA Configuration Register -------- */
#define GMAC_DCFGR_RESETVALUE                 _UINT32_(0x20004)                                    /*  (GMAC_DCFGR) DMA Configuration Register  Reset Value */

#define GMAC_DCFGR_FBLDO_Pos                  _UINT32_(0)                                          /* (GMAC_DCFGR) Fixed Burst Length for DMA Data Operations: Position */
#define GMAC_DCFGR_FBLDO_Msk                  (_UINT32_(0x1F) << GMAC_DCFGR_FBLDO_Pos)             /* (GMAC_DCFGR) Fixed Burst Length for DMA Data Operations: Mask */
#define GMAC_DCFGR_FBLDO(value)               (GMAC_DCFGR_FBLDO_Msk & (_UINT32_(value) << GMAC_DCFGR_FBLDO_Pos)) /* Assigment of value for FBLDO in the GMAC_DCFGR register */
#define   GMAC_DCFGR_FBLDO_SINGLE_Val         _UINT32_(0x1)                                        /* (GMAC_DCFGR) Always use single access on system bus  */
#define   GMAC_DCFGR_FBLDO_INCR4_Val          _UINT32_(0x4)                                        /* (GMAC_DCFGR) Attempt to use 4-beat bursts on system bus (Default)  */
#define   GMAC_DCFGR_FBLDO_INCR8_Val          _UINT32_(0x8)                                        /* (GMAC_DCFGR) Attempt to use 8-beat bursts on system bus bursts  */
#define   GMAC_DCFGR_FBLDO_INCR16_Val         _UINT32_(0x10)                                       /* (GMAC_DCFGR) Attempt to use 16-beat bursts on system bus bursts  */
#define GMAC_DCFGR_FBLDO_SINGLE               (GMAC_DCFGR_FBLDO_SINGLE_Val << GMAC_DCFGR_FBLDO_Pos) /* (GMAC_DCFGR) Always use single access on system bus Position  */
#define GMAC_DCFGR_FBLDO_INCR4                (GMAC_DCFGR_FBLDO_INCR4_Val << GMAC_DCFGR_FBLDO_Pos) /* (GMAC_DCFGR) Attempt to use 4-beat bursts on system bus (Default) Position  */
#define GMAC_DCFGR_FBLDO_INCR8                (GMAC_DCFGR_FBLDO_INCR8_Val << GMAC_DCFGR_FBLDO_Pos) /* (GMAC_DCFGR) Attempt to use 8-beat bursts on system bus bursts Position  */
#define GMAC_DCFGR_FBLDO_INCR16               (GMAC_DCFGR_FBLDO_INCR16_Val << GMAC_DCFGR_FBLDO_Pos) /* (GMAC_DCFGR) Attempt to use 16-beat bursts on system bus bursts Position  */
#define GMAC_DCFGR_ESMA_Pos                   _UINT32_(6)                                          /* (GMAC_DCFGR) Endian Swap Mode Enable for Management Descriptor Accesses Position */
#define GMAC_DCFGR_ESMA_Msk                   (_UINT32_(0x1) << GMAC_DCFGR_ESMA_Pos)               /* (GMAC_DCFGR) Endian Swap Mode Enable for Management Descriptor Accesses Mask */
#define GMAC_DCFGR_ESMA(value)                (GMAC_DCFGR_ESMA_Msk & (_UINT32_(value) << GMAC_DCFGR_ESMA_Pos)) /* Assigment of value for ESMA in the GMAC_DCFGR register */
#define   GMAC_DCFGR_ESMA_LITTLE_ENDIAN_Val   _UINT32_(0x0)                                        /* (GMAC_DCFGR) Selects Little-endian endianism for system bus transfers.  */
#define   GMAC_DCFGR_ESMA_BIG_ENDIAN_Val      _UINT32_(0x1)                                        /* (GMAC_DCFGR) Selects swapped endianism for system bus transfers.  */
#define GMAC_DCFGR_ESMA_LITTLE_ENDIAN         (GMAC_DCFGR_ESMA_LITTLE_ENDIAN_Val << GMAC_DCFGR_ESMA_Pos) /* (GMAC_DCFGR) Selects Little-endian endianism for system bus transfers. Position  */
#define GMAC_DCFGR_ESMA_BIG_ENDIAN            (GMAC_DCFGR_ESMA_BIG_ENDIAN_Val << GMAC_DCFGR_ESMA_Pos) /* (GMAC_DCFGR) Selects swapped endianism for system bus transfers. Position  */
#define GMAC_DCFGR_ESPA_Pos                   _UINT32_(7)                                          /* (GMAC_DCFGR) Endian Swap Mode Enable for Packet Data Accesses Position */
#define GMAC_DCFGR_ESPA_Msk                   (_UINT32_(0x1) << GMAC_DCFGR_ESPA_Pos)               /* (GMAC_DCFGR) Endian Swap Mode Enable for Packet Data Accesses Mask */
#define GMAC_DCFGR_ESPA(value)                (GMAC_DCFGR_ESPA_Msk & (_UINT32_(value) << GMAC_DCFGR_ESPA_Pos)) /* Assigment of value for ESPA in the GMAC_DCFGR register */
#define   GMAC_DCFGR_ESPA_LITTLE_ENDIAN_Val   _UINT32_(0x0)                                        /* (GMAC_DCFGR) Selects Little-endian endianism for system bus transfers.  */
#define   GMAC_DCFGR_ESPA_BIG_ENDIAN_Val      _UINT32_(0x1)                                        /* (GMAC_DCFGR) Selects swapped endianism for system bus transfers.  */
#define GMAC_DCFGR_ESPA_LITTLE_ENDIAN         (GMAC_DCFGR_ESPA_LITTLE_ENDIAN_Val << GMAC_DCFGR_ESPA_Pos) /* (GMAC_DCFGR) Selects Little-endian endianism for system bus transfers. Position  */
#define GMAC_DCFGR_ESPA_BIG_ENDIAN            (GMAC_DCFGR_ESPA_BIG_ENDIAN_Val << GMAC_DCFGR_ESPA_Pos) /* (GMAC_DCFGR) Selects swapped endianism for system bus transfers. Position  */
#define GMAC_DCFGR_RXBMS_Pos                  _UINT32_(8)                                          /* (GMAC_DCFGR) Receiver Packet Buffer Memory Size Select Position */
#define GMAC_DCFGR_RXBMS_Msk                  (_UINT32_(0x3) << GMAC_DCFGR_RXBMS_Pos)              /* (GMAC_DCFGR) Receiver Packet Buffer Memory Size Select Mask */
#define GMAC_DCFGR_RXBMS(value)               (GMAC_DCFGR_RXBMS_Msk & (_UINT32_(value) << GMAC_DCFGR_RXBMS_Pos)) /* Assigment of value for RXBMS in the GMAC_DCFGR register */
#define   GMAC_DCFGR_RXBMS_EIGHTH_Val         _UINT32_(0x0)                                        /* (GMAC_DCFGR) 4/8 Kbyte Memory Size  */
#define   GMAC_DCFGR_RXBMS_QUARTER_Val        _UINT32_(0x1)                                        /* (GMAC_DCFGR) 4/4 Kbytes Memory Size  */
#define   GMAC_DCFGR_RXBMS_HALF_Val           _UINT32_(0x2)                                        /* (GMAC_DCFGR) 4/2 Kbytes Memory Size  */
#define   GMAC_DCFGR_RXBMS_FULL_Val           _UINT32_(0x3)                                        /* (GMAC_DCFGR) 4 Kbytes Memory Size  */
#define GMAC_DCFGR_RXBMS_EIGHTH               (GMAC_DCFGR_RXBMS_EIGHTH_Val << GMAC_DCFGR_RXBMS_Pos) /* (GMAC_DCFGR) 4/8 Kbyte Memory Size Position  */
#define GMAC_DCFGR_RXBMS_QUARTER              (GMAC_DCFGR_RXBMS_QUARTER_Val << GMAC_DCFGR_RXBMS_Pos) /* (GMAC_DCFGR) 4/4 Kbytes Memory Size Position  */
#define GMAC_DCFGR_RXBMS_HALF                 (GMAC_DCFGR_RXBMS_HALF_Val << GMAC_DCFGR_RXBMS_Pos)  /* (GMAC_DCFGR) 4/2 Kbytes Memory Size Position  */
#define GMAC_DCFGR_RXBMS_FULL                 (GMAC_DCFGR_RXBMS_FULL_Val << GMAC_DCFGR_RXBMS_Pos)  /* (GMAC_DCFGR) 4 Kbytes Memory Size Position  */
#define GMAC_DCFGR_TXPBMS_Pos                 _UINT32_(10)                                         /* (GMAC_DCFGR) Transmitter Packet Buffer Memory Size Select Position */
#define GMAC_DCFGR_TXPBMS_Msk                 (_UINT32_(0x1) << GMAC_DCFGR_TXPBMS_Pos)             /* (GMAC_DCFGR) Transmitter Packet Buffer Memory Size Select Mask */
#define GMAC_DCFGR_TXPBMS(value)              (GMAC_DCFGR_TXPBMS_Msk & (_UINT32_(value) << GMAC_DCFGR_TXPBMS_Pos)) /* Assigment of value for TXPBMS in the GMAC_DCFGR register */
#define   GMAC_DCFGR_TXPBMS_TWO_KB_Val        _UINT32_(0x0)                                        /* (GMAC_DCFGR) Do not use top address bit (2 Kbytes).  */
#define   GMAC_DCFGR_TXPBMS_FOUR_KB_Val       _UINT32_(0x1)                                        /* (GMAC_DCFGR) Use full configured addressable space (4 Kbytes).  */
#define GMAC_DCFGR_TXPBMS_TWO_KB              (GMAC_DCFGR_TXPBMS_TWO_KB_Val << GMAC_DCFGR_TXPBMS_Pos) /* (GMAC_DCFGR) Do not use top address bit (2 Kbytes). Position  */
#define GMAC_DCFGR_TXPBMS_FOUR_KB             (GMAC_DCFGR_TXPBMS_FOUR_KB_Val << GMAC_DCFGR_TXPBMS_Pos) /* (GMAC_DCFGR) Use full configured addressable space (4 Kbytes). Position  */
#define GMAC_DCFGR_TXCOEN_Pos                 _UINT32_(11)                                         /* (GMAC_DCFGR) Transmitter Checksum Generation Offload Enable Position */
#define GMAC_DCFGR_TXCOEN_Msk                 (_UINT32_(0x1) << GMAC_DCFGR_TXCOEN_Pos)             /* (GMAC_DCFGR) Transmitter Checksum Generation Offload Enable Mask */
#define GMAC_DCFGR_TXCOEN(value)              (GMAC_DCFGR_TXCOEN_Msk & (_UINT32_(value) << GMAC_DCFGR_TXCOEN_Pos)) /* Assigment of value for TXCOEN in the GMAC_DCFGR register */
#define GMAC_DCFGR_INFLASTEN_Pos              _UINT32_(12)                                         /* (GMAC_DCFGR) Infinite Size for Last Buffer Enable Position */
#define GMAC_DCFGR_INFLASTEN_Msk              (_UINT32_(0x1) << GMAC_DCFGR_INFLASTEN_Pos)          /* (GMAC_DCFGR) Infinite Size for Last Buffer Enable Mask */
#define GMAC_DCFGR_INFLASTEN(value)           (GMAC_DCFGR_INFLASTEN_Msk & (_UINT32_(value) << GMAC_DCFGR_INFLASTEN_Pos)) /* Assigment of value for INFLASTEN in the GMAC_DCFGR register */
#define GMAC_DCFGR_CRCERRREP_Pos              _UINT32_(13)                                         /* (GMAC_DCFGR) CRC Errors Report Position */
#define GMAC_DCFGR_CRCERRREP_Msk              (_UINT32_(0x1) << GMAC_DCFGR_CRCERRREP_Pos)          /* (GMAC_DCFGR) CRC Errors Report Mask */
#define GMAC_DCFGR_CRCERRREP(value)           (GMAC_DCFGR_CRCERRREP_Msk & (_UINT32_(value) << GMAC_DCFGR_CRCERRREP_Pos)) /* Assigment of value for CRCERRREP in the GMAC_DCFGR register */
#define   GMAC_DCFGR_CRCERRREP_0_Val          _UINT32_(0x0)                                        /* (GMAC_DCFGR) Bit 16 of the receive buffer descriptor represents the Canonical format indicator (CFI) bit as extracted from the receive frame (if the receive buffer descriptor is pointing to the last data buffer of the receive frame and the received frame was VLAN tagged).  */
#define   GMAC_DCFGR_CRCERRREP_1_Val          _UINT32_(0x1)                                        /* (GMAC_DCFGR) Bit 16 of the receive buffer descriptor represents the FCS/CRC error (only if frames with FCS are copied to memory as enabled by bit 26 in the Network Configuration register).  */
#define GMAC_DCFGR_CRCERRREP_0                (GMAC_DCFGR_CRCERRREP_0_Val << GMAC_DCFGR_CRCERRREP_Pos) /* (GMAC_DCFGR) Bit 16 of the receive buffer descriptor represents the Canonical format indicator (CFI) bit as extracted from the receive frame (if the receive buffer descriptor is pointing to the last data buffer of the receive frame and the received frame was VLAN tagged). Position  */
#define GMAC_DCFGR_CRCERRREP_1                (GMAC_DCFGR_CRCERRREP_1_Val << GMAC_DCFGR_CRCERRREP_Pos) /* (GMAC_DCFGR) Bit 16 of the receive buffer descriptor represents the FCS/CRC error (only if frames with FCS are copied to memory as enabled by bit 26 in the Network Configuration register). Position  */
#define GMAC_DCFGR_DRBS_Pos                   _UINT32_(16)                                         /* (GMAC_DCFGR) DMA Receive Buffer Size Position */
#define GMAC_DCFGR_DRBS_Msk                   (_UINT32_(0xFF) << GMAC_DCFGR_DRBS_Pos)              /* (GMAC_DCFGR) DMA Receive Buffer Size Mask */
#define GMAC_DCFGR_DRBS(value)                (GMAC_DCFGR_DRBS_Msk & (_UINT32_(value) << GMAC_DCFGR_DRBS_Pos)) /* Assigment of value for DRBS in the GMAC_DCFGR register */
#define   GMAC_DCFGR_DRBS_0x02_Val            _UINT32_(0x2)                                        /* (GMAC_DCFGR) 128 bytes  */
#define   GMAC_DCFGR_DRBS_0x18_Val            _UINT32_(0x18)                                       /* (GMAC_DCFGR) 1536 bytes (1 x max length frame/buffer)  */
#define   GMAC_DCFGR_DRBS_0xA0_Val            _UINT32_(0xA0)                                       /* (GMAC_DCFGR) 10240 bytes (1 x 10K jumbo frame/buffer)  */
#define GMAC_DCFGR_DRBS_0x02                  (GMAC_DCFGR_DRBS_0x02_Val << GMAC_DCFGR_DRBS_Pos)    /* (GMAC_DCFGR) 128 bytes Position  */
#define GMAC_DCFGR_DRBS_0x18                  (GMAC_DCFGR_DRBS_0x18_Val << GMAC_DCFGR_DRBS_Pos)    /* (GMAC_DCFGR) 1536 bytes (1 x max length frame/buffer) Position  */
#define GMAC_DCFGR_DRBS_0xA0                  (GMAC_DCFGR_DRBS_0xA0_Val << GMAC_DCFGR_DRBS_Pos)    /* (GMAC_DCFGR) 10240 bytes (1 x 10K jumbo frame/buffer) Position  */
#define GMAC_DCFGR_DDRP_Pos                   _UINT32_(24)                                         /* (GMAC_DCFGR) DMA Discard Receive Packets Position */
#define GMAC_DCFGR_DDRP_Msk                   (_UINT32_(0x1) << GMAC_DCFGR_DDRP_Pos)               /* (GMAC_DCFGR) DMA Discard Receive Packets Mask */
#define GMAC_DCFGR_DDRP(value)                (GMAC_DCFGR_DDRP_Msk & (_UINT32_(value) << GMAC_DCFGR_DDRP_Pos)) /* Assigment of value for DDRP in the GMAC_DCFGR register */
#define GMAC_DCFGR_RXFOMAXB_Pos               _UINT32_(25)                                         /* (GMAC_DCFGR) Force Receive Max Burst Length Position */
#define GMAC_DCFGR_RXFOMAXB_Msk               (_UINT32_(0x1) << GMAC_DCFGR_RXFOMAXB_Pos)           /* (GMAC_DCFGR) Force Receive Max Burst Length Mask */
#define GMAC_DCFGR_RXFOMAXB(value)            (GMAC_DCFGR_RXFOMAXB_Msk & (_UINT32_(value) << GMAC_DCFGR_RXFOMAXB_Pos)) /* Assigment of value for RXFOMAXB in the GMAC_DCFGR register */
#define GMAC_DCFGR_TXFOMAXB_Pos               _UINT32_(26)                                         /* (GMAC_DCFGR) Force Transmit Max Burst Length Position */
#define GMAC_DCFGR_TXFOMAXB_Msk               (_UINT32_(0x1) << GMAC_DCFGR_TXFOMAXB_Pos)           /* (GMAC_DCFGR) Force Transmit Max Burst Length Mask */
#define GMAC_DCFGR_TXFOMAXB(value)            (GMAC_DCFGR_TXFOMAXB_Msk & (_UINT32_(value) << GMAC_DCFGR_TXFOMAXB_Pos)) /* Assigment of value for TXFOMAXB in the GMAC_DCFGR register */
#define GMAC_DCFGR_RXBD_EXTENDED_Pos          _UINT32_(28)                                         /* (GMAC_DCFGR) Receive Buffer Descriptor Extended Mode Position */
#define GMAC_DCFGR_RXBD_EXTENDED_Msk          (_UINT32_(0x1) << GMAC_DCFGR_RXBD_EXTENDED_Pos)      /* (GMAC_DCFGR) Receive Buffer Descriptor Extended Mode Mask */
#define GMAC_DCFGR_RXBD_EXTENDED(value)       (GMAC_DCFGR_RXBD_EXTENDED_Msk & (_UINT32_(value) << GMAC_DCFGR_RXBD_EXTENDED_Pos)) /* Assigment of value for RXBD_EXTENDED in the GMAC_DCFGR register */
#define   GMAC_DCFGR_RXBD_EXTENDED_0_Val      _UINT32_(0x0)                                        /* (GMAC_DCFGR) Disables Receive Buffer Data Extended mode.  */
#define   GMAC_DCFGR_RXBD_EXTENDED_1_Val      _UINT32_(0x1)                                        /* (GMAC_DCFGR) Enables Receive Buffer Data Extended mode.  */
#define GMAC_DCFGR_RXBD_EXTENDED_0            (GMAC_DCFGR_RXBD_EXTENDED_0_Val << GMAC_DCFGR_RXBD_EXTENDED_Pos) /* (GMAC_DCFGR) Disables Receive Buffer Data Extended mode. Position  */
#define GMAC_DCFGR_RXBD_EXTENDED_1            (GMAC_DCFGR_RXBD_EXTENDED_1_Val << GMAC_DCFGR_RXBD_EXTENDED_Pos) /* (GMAC_DCFGR) Enables Receive Buffer Data Extended mode. Position  */
#define GMAC_DCFGR_TXBD_EXTENDED_Pos          _UINT32_(29)                                         /* (GMAC_DCFGR) Transmit Buffer Descriptor Extended Mode Position */
#define GMAC_DCFGR_TXBD_EXTENDED_Msk          (_UINT32_(0x1) << GMAC_DCFGR_TXBD_EXTENDED_Pos)      /* (GMAC_DCFGR) Transmit Buffer Descriptor Extended Mode Mask */
#define GMAC_DCFGR_TXBD_EXTENDED(value)       (GMAC_DCFGR_TXBD_EXTENDED_Msk & (_UINT32_(value) << GMAC_DCFGR_TXBD_EXTENDED_Pos)) /* Assigment of value for TXBD_EXTENDED in the GMAC_DCFGR register */
#define   GMAC_DCFGR_TXBD_EXTENDED_0_Val      _UINT32_(0x0)                                        /* (GMAC_DCFGR) Disables Transmit Buffer Data Extended mode.  */
#define   GMAC_DCFGR_TXBD_EXTENDED_1_Val      _UINT32_(0x1)                                        /* (GMAC_DCFGR) Enables Transmit Buffer Data Extended mode.  */
#define GMAC_DCFGR_TXBD_EXTENDED_0            (GMAC_DCFGR_TXBD_EXTENDED_0_Val << GMAC_DCFGR_TXBD_EXTENDED_Pos) /* (GMAC_DCFGR) Disables Transmit Buffer Data Extended mode. Position  */
#define GMAC_DCFGR_TXBD_EXTENDED_1            (GMAC_DCFGR_TXBD_EXTENDED_1_Val << GMAC_DCFGR_TXBD_EXTENDED_Pos) /* (GMAC_DCFGR) Enables Transmit Buffer Data Extended mode. Position  */
#define GMAC_DCFGR_Msk                        _UINT32_(0x37FF3FDF)                                 /* (GMAC_DCFGR) Register Mask  */


/* -------- GMAC_TSR : (GMAC Offset: 0x14) (R/W 32) Transmit Status Register -------- */
#define GMAC_TSR_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_TSR) Transmit Status Register  Reset Value */

#define GMAC_TSR_UBR_Pos                      _UINT32_(0)                                          /* (GMAC_TSR) Used Bit Read Position */
#define GMAC_TSR_UBR_Msk                      (_UINT32_(0x1) << GMAC_TSR_UBR_Pos)                  /* (GMAC_TSR) Used Bit Read Mask */
#define GMAC_TSR_UBR(value)                   (GMAC_TSR_UBR_Msk & (_UINT32_(value) << GMAC_TSR_UBR_Pos)) /* Assigment of value for UBR in the GMAC_TSR register */
#define GMAC_TSR_COL_Pos                      _UINT32_(1)                                          /* (GMAC_TSR) Collision Occurred Position */
#define GMAC_TSR_COL_Msk                      (_UINT32_(0x1) << GMAC_TSR_COL_Pos)                  /* (GMAC_TSR) Collision Occurred Mask */
#define GMAC_TSR_COL(value)                   (GMAC_TSR_COL_Msk & (_UINT32_(value) << GMAC_TSR_COL_Pos)) /* Assigment of value for COL in the GMAC_TSR register */
#define GMAC_TSR_RLE_Pos                      _UINT32_(2)                                          /* (GMAC_TSR) Retry Limit Exceeded Position */
#define GMAC_TSR_RLE_Msk                      (_UINT32_(0x1) << GMAC_TSR_RLE_Pos)                  /* (GMAC_TSR) Retry Limit Exceeded Mask */
#define GMAC_TSR_RLE(value)                   (GMAC_TSR_RLE_Msk & (_UINT32_(value) << GMAC_TSR_RLE_Pos)) /* Assigment of value for RLE in the GMAC_TSR register */
#define GMAC_TSR_TXGO_Pos                     _UINT32_(3)                                          /* (GMAC_TSR) Transmit Go (Read only) Position */
#define GMAC_TSR_TXGO_Msk                     (_UINT32_(0x1) << GMAC_TSR_TXGO_Pos)                 /* (GMAC_TSR) Transmit Go (Read only) Mask */
#define GMAC_TSR_TXGO(value)                  (GMAC_TSR_TXGO_Msk & (_UINT32_(value) << GMAC_TSR_TXGO_Pos)) /* Assigment of value for TXGO in the GMAC_TSR register */
#define GMAC_TSR_TFC_Pos                      _UINT32_(4)                                          /* (GMAC_TSR) Transmit Frame Corruption Due to System Bus Error Position */
#define GMAC_TSR_TFC_Msk                      (_UINT32_(0x1) << GMAC_TSR_TFC_Pos)                  /* (GMAC_TSR) Transmit Frame Corruption Due to System Bus Error Mask */
#define GMAC_TSR_TFC(value)                   (GMAC_TSR_TFC_Msk & (_UINT32_(value) << GMAC_TSR_TFC_Pos)) /* Assigment of value for TFC in the GMAC_TSR register */
#define GMAC_TSR_TXCOMP_Pos                   _UINT32_(5)                                          /* (GMAC_TSR) Transmit Complete Position */
#define GMAC_TSR_TXCOMP_Msk                   (_UINT32_(0x1) << GMAC_TSR_TXCOMP_Pos)               /* (GMAC_TSR) Transmit Complete Mask */
#define GMAC_TSR_TXCOMP(value)                (GMAC_TSR_TXCOMP_Msk & (_UINT32_(value) << GMAC_TSR_TXCOMP_Pos)) /* Assigment of value for TXCOMP in the GMAC_TSR register */
#define GMAC_TSR_LCO_Pos                      _UINT32_(7)                                          /* (GMAC_TSR) Late Collision Occurred Position */
#define GMAC_TSR_LCO_Msk                      (_UINT32_(0x1) << GMAC_TSR_LCO_Pos)                  /* (GMAC_TSR) Late Collision Occurred Mask */
#define GMAC_TSR_LCO(value)                   (GMAC_TSR_LCO_Msk & (_UINT32_(value) << GMAC_TSR_LCO_Pos)) /* Assigment of value for LCO in the GMAC_TSR register */
#define GMAC_TSR_HRESP_Pos                    _UINT32_(8)                                          /* (GMAC_TSR) System Bus Response Position */
#define GMAC_TSR_HRESP_Msk                    (_UINT32_(0x1) << GMAC_TSR_HRESP_Pos)                /* (GMAC_TSR) System Bus Response Mask */
#define GMAC_TSR_HRESP(value)                 (GMAC_TSR_HRESP_Msk & (_UINT32_(value) << GMAC_TSR_HRESP_Pos)) /* Assigment of value for HRESP in the GMAC_TSR register */
#define GMAC_TSR_TXMACLCK_Pos                 _UINT32_(9)                                          /* (GMAC_TSR) Transmit MAC Lockup (Clear by Writing a 1) Position */
#define GMAC_TSR_TXMACLCK_Msk                 (_UINT32_(0x1) << GMAC_TSR_TXMACLCK_Pos)             /* (GMAC_TSR) Transmit MAC Lockup (Clear by Writing a 1) Mask */
#define GMAC_TSR_TXMACLCK(value)              (GMAC_TSR_TXMACLCK_Msk & (_UINT32_(value) << GMAC_TSR_TXMACLCK_Pos)) /* Assigment of value for TXMACLCK in the GMAC_TSR register */
#define GMAC_TSR_TXDMALCK_Pos                 _UINT32_(10)                                         /* (GMAC_TSR) Transmit DMA Lockup (Clear by Writing a 1) Position */
#define GMAC_TSR_TXDMALCK_Msk                 (_UINT32_(0x1) << GMAC_TSR_TXDMALCK_Pos)             /* (GMAC_TSR) Transmit DMA Lockup (Clear by Writing a 1) Mask */
#define GMAC_TSR_TXDMALCK(value)              (GMAC_TSR_TXDMALCK_Msk & (_UINT32_(value) << GMAC_TSR_TXDMALCK_Pos)) /* Assigment of value for TXDMALCK in the GMAC_TSR register */
#define GMAC_TSR_Msk                          _UINT32_(0x000007BF)                                 /* (GMAC_TSR) Register Mask  */


/* -------- GMAC_RBQB : (GMAC Offset: 0x18) (R/W 32) Receive Buffer Queue Base Address Register -------- */
#define GMAC_RBQB_RESETVALUE                  _UINT32_(0x00)                                       /*  (GMAC_RBQB) Receive Buffer Queue Base Address Register  Reset Value */

#define GMAC_RBQB_RXQDIS_Pos                  _UINT32_(0)                                          /* (GMAC_RBQB) Receive Queue Disable Position */
#define GMAC_RBQB_RXQDIS_Msk                  (_UINT32_(0x1) << GMAC_RBQB_RXQDIS_Pos)              /* (GMAC_RBQB) Receive Queue Disable Mask */
#define GMAC_RBQB_RXQDIS(value)               (GMAC_RBQB_RXQDIS_Msk & (_UINT32_(value) << GMAC_RBQB_RXQDIS_Pos)) /* Assigment of value for RXQDIS in the GMAC_RBQB register */
#define   GMAC_RBQB_RXQDIS_0_Val              _UINT32_(0x0)                                        /* (GMAC_RBQB) Queue is enabled.  */
#define   GMAC_RBQB_RXQDIS_1_Val              _UINT32_(0x1)                                        /* (GMAC_RBQB) Queue is disabled. Used to reduce the number of active queues and should only be changed while receive is not enabled.  */
#define GMAC_RBQB_RXQDIS_0                    (GMAC_RBQB_RXQDIS_0_Val << GMAC_RBQB_RXQDIS_Pos)     /* (GMAC_RBQB) Queue is enabled. Position  */
#define GMAC_RBQB_RXQDIS_1                    (GMAC_RBQB_RXQDIS_1_Val << GMAC_RBQB_RXQDIS_Pos)     /* (GMAC_RBQB) Queue is disabled. Used to reduce the number of active queues and should only be changed while receive is not enabled. Position  */
#define GMAC_RBQB_ADDR_Pos                    _UINT32_(2)                                          /* (GMAC_RBQB) Receive Buffer Queue Base Address Position */
#define GMAC_RBQB_ADDR_Msk                    (_UINT32_(0x3FFFFFFF) << GMAC_RBQB_ADDR_Pos)         /* (GMAC_RBQB) Receive Buffer Queue Base Address Mask */
#define GMAC_RBQB_ADDR(value)                 (GMAC_RBQB_ADDR_Msk & (_UINT32_(value) << GMAC_RBQB_ADDR_Pos)) /* Assigment of value for ADDR in the GMAC_RBQB register */
#define GMAC_RBQB_Msk                         _UINT32_(0xFFFFFFFD)                                 /* (GMAC_RBQB) Register Mask  */


/* -------- GMAC_TBQB : (GMAC Offset: 0x1C) (R/W 32) Transmit Buffer Queue Base Address Register -------- */
#define GMAC_TBQB_RESETVALUE                  _UINT32_(0x00)                                       /*  (GMAC_TBQB) Transmit Buffer Queue Base Address Register  Reset Value */

#define GMAC_TBQB_TXQDIS_Pos                  _UINT32_(0)                                          /* (GMAC_TBQB) Transmit Queue Disable Position */
#define GMAC_TBQB_TXQDIS_Msk                  (_UINT32_(0x1) << GMAC_TBQB_TXQDIS_Pos)              /* (GMAC_TBQB) Transmit Queue Disable Mask */
#define GMAC_TBQB_TXQDIS(value)               (GMAC_TBQB_TXQDIS_Msk & (_UINT32_(value) << GMAC_TBQB_TXQDIS_Pos)) /* Assigment of value for TXQDIS in the GMAC_TBQB register */
#define   GMAC_TBQB_TXQDIS_0_Val              _UINT32_(0x0)                                        /* (GMAC_TBQB) Queue is enabled.  */
#define   GMAC_TBQB_TXQDIS_1_Val              _UINT32_(0x1)                                        /* (GMAC_TBQB) Queue is disabled. Used to reduce the number of active queues and should only be changed while transmit is not enabled.  */
#define GMAC_TBQB_TXQDIS_0                    (GMAC_TBQB_TXQDIS_0_Val << GMAC_TBQB_TXQDIS_Pos)     /* (GMAC_TBQB) Queue is enabled. Position  */
#define GMAC_TBQB_TXQDIS_1                    (GMAC_TBQB_TXQDIS_1_Val << GMAC_TBQB_TXQDIS_Pos)     /* (GMAC_TBQB) Queue is disabled. Used to reduce the number of active queues and should only be changed while transmit is not enabled. Position  */
#define GMAC_TBQB_ADDR_Pos                    _UINT32_(2)                                          /* (GMAC_TBQB) Transmit Buffer Queue Base Address Position */
#define GMAC_TBQB_ADDR_Msk                    (_UINT32_(0x3FFFFFFF) << GMAC_TBQB_ADDR_Pos)         /* (GMAC_TBQB) Transmit Buffer Queue Base Address Mask */
#define GMAC_TBQB_ADDR(value)                 (GMAC_TBQB_ADDR_Msk & (_UINT32_(value) << GMAC_TBQB_ADDR_Pos)) /* Assigment of value for ADDR in the GMAC_TBQB register */
#define GMAC_TBQB_Msk                         _UINT32_(0xFFFFFFFD)                                 /* (GMAC_TBQB) Register Mask  */


/* -------- GMAC_RSR : (GMAC Offset: 0x20) (R/W 32) Receive Status Register -------- */
#define GMAC_RSR_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_RSR) Receive Status Register  Reset Value */

#define GMAC_RSR_BNA_Pos                      _UINT32_(0)                                          /* (GMAC_RSR) Buffer Not Available Position */
#define GMAC_RSR_BNA_Msk                      (_UINT32_(0x1) << GMAC_RSR_BNA_Pos)                  /* (GMAC_RSR) Buffer Not Available Mask */
#define GMAC_RSR_BNA(value)                   (GMAC_RSR_BNA_Msk & (_UINT32_(value) << GMAC_RSR_BNA_Pos)) /* Assigment of value for BNA in the GMAC_RSR register */
#define GMAC_RSR_REC_Pos                      _UINT32_(1)                                          /* (GMAC_RSR) Frame Received Position */
#define GMAC_RSR_REC_Msk                      (_UINT32_(0x1) << GMAC_RSR_REC_Pos)                  /* (GMAC_RSR) Frame Received Mask */
#define GMAC_RSR_REC(value)                   (GMAC_RSR_REC_Msk & (_UINT32_(value) << GMAC_RSR_REC_Pos)) /* Assigment of value for REC in the GMAC_RSR register */
#define GMAC_RSR_RXOVR_Pos                    _UINT32_(2)                                          /* (GMAC_RSR) Receive Overrun Position */
#define GMAC_RSR_RXOVR_Msk                    (_UINT32_(0x1) << GMAC_RSR_RXOVR_Pos)                /* (GMAC_RSR) Receive Overrun Mask */
#define GMAC_RSR_RXOVR(value)                 (GMAC_RSR_RXOVR_Msk & (_UINT32_(value) << GMAC_RSR_RXOVR_Pos)) /* Assigment of value for RXOVR in the GMAC_RSR register */
#define GMAC_RSR_HNO_Pos                      _UINT32_(3)                                          /* (GMAC_RSR) System Bus Error Position */
#define GMAC_RSR_HNO_Msk                      (_UINT32_(0x1) << GMAC_RSR_HNO_Pos)                  /* (GMAC_RSR) System Bus Error Mask */
#define GMAC_RSR_HNO(value)                   (GMAC_RSR_HNO_Msk & (_UINT32_(value) << GMAC_RSR_HNO_Pos)) /* Assigment of value for HNO in the GMAC_RSR register */
#define GMAC_RSR_RXMACLCK_Pos                 _UINT32_(4)                                          /* (GMAC_RSR) Receive MAC Lockup (Clear by Writing a 1) Position */
#define GMAC_RSR_RXMACLCK_Msk                 (_UINT32_(0x1) << GMAC_RSR_RXMACLCK_Pos)             /* (GMAC_RSR) Receive MAC Lockup (Clear by Writing a 1) Mask */
#define GMAC_RSR_RXMACLCK(value)              (GMAC_RSR_RXMACLCK_Msk & (_UINT32_(value) << GMAC_RSR_RXMACLCK_Pos)) /* Assigment of value for RXMACLCK in the GMAC_RSR register */
#define GMAC_RSR_RXDMALCK_Pos                 _UINT32_(5)                                          /* (GMAC_RSR) Receive DMA Lockup (Clear by Writing a 1) Position */
#define GMAC_RSR_RXDMALCK_Msk                 (_UINT32_(0x1) << GMAC_RSR_RXDMALCK_Pos)             /* (GMAC_RSR) Receive DMA Lockup (Clear by Writing a 1) Mask */
#define GMAC_RSR_RXDMALCK(value)              (GMAC_RSR_RXDMALCK_Msk & (_UINT32_(value) << GMAC_RSR_RXDMALCK_Pos)) /* Assigment of value for RXDMALCK in the GMAC_RSR register */
#define GMAC_RSR_Msk                          _UINT32_(0x0000003F)                                 /* (GMAC_RSR) Register Mask  */


/* -------- GMAC_ISR : (GMAC Offset: 0x24) ( R/ 32) Interrupt Status Register -------- */
#define GMAC_ISR_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_ISR) Interrupt Status Register  Reset Value */

#define GMAC_ISR_MFS_Pos                      _UINT32_(0)                                          /* (GMAC_ISR) Management Frame Sent (Cleared on read) Position */
#define GMAC_ISR_MFS_Msk                      (_UINT32_(0x1) << GMAC_ISR_MFS_Pos)                  /* (GMAC_ISR) Management Frame Sent (Cleared on read) Mask */
#define GMAC_ISR_MFS(value)                   (GMAC_ISR_MFS_Msk & (_UINT32_(value) << GMAC_ISR_MFS_Pos)) /* Assigment of value for MFS in the GMAC_ISR register */
#define GMAC_ISR_RCOMP_Pos                    _UINT32_(1)                                          /* (GMAC_ISR) Receive Complete (Cleared on read) Position */
#define GMAC_ISR_RCOMP_Msk                    (_UINT32_(0x1) << GMAC_ISR_RCOMP_Pos)                /* (GMAC_ISR) Receive Complete (Cleared on read) Mask */
#define GMAC_ISR_RCOMP(value)                 (GMAC_ISR_RCOMP_Msk & (_UINT32_(value) << GMAC_ISR_RCOMP_Pos)) /* Assigment of value for RCOMP in the GMAC_ISR register */
#define GMAC_ISR_RXUBR_Pos                    _UINT32_(2)                                          /* (GMAC_ISR) RX Used Bit Read (Cleared on read) Position */
#define GMAC_ISR_RXUBR_Msk                    (_UINT32_(0x1) << GMAC_ISR_RXUBR_Pos)                /* (GMAC_ISR) RX Used Bit Read (Cleared on read) Mask */
#define GMAC_ISR_RXUBR(value)                 (GMAC_ISR_RXUBR_Msk & (_UINT32_(value) << GMAC_ISR_RXUBR_Pos)) /* Assigment of value for RXUBR in the GMAC_ISR register */
#define GMAC_ISR_TXUBR_Pos                    _UINT32_(3)                                          /* (GMAC_ISR) TX Used Bit Read (Cleared on read) Position */
#define GMAC_ISR_TXUBR_Msk                    (_UINT32_(0x1) << GMAC_ISR_TXUBR_Pos)                /* (GMAC_ISR) TX Used Bit Read (Cleared on read) Mask */
#define GMAC_ISR_TXUBR(value)                 (GMAC_ISR_TXUBR_Msk & (_UINT32_(value) << GMAC_ISR_TXUBR_Pos)) /* Assigment of value for TXUBR in the GMAC_ISR register */
#define GMAC_ISR_TUR_Pos                      _UINT32_(4)                                          /* (GMAC_ISR) Transmit Underrun (Cleared on read) Position */
#define GMAC_ISR_TUR_Msk                      (_UINT32_(0x1) << GMAC_ISR_TUR_Pos)                  /* (GMAC_ISR) Transmit Underrun (Cleared on read) Mask */
#define GMAC_ISR_TUR(value)                   (GMAC_ISR_TUR_Msk & (_UINT32_(value) << GMAC_ISR_TUR_Pos)) /* Assigment of value for TUR in the GMAC_ISR register */
#define GMAC_ISR_RLEX_Pos                     _UINT32_(5)                                          /* (GMAC_ISR) Retry Limit Exceeded or Late Collision (Cleared on read) Position */
#define GMAC_ISR_RLEX_Msk                     (_UINT32_(0x1) << GMAC_ISR_RLEX_Pos)                 /* (GMAC_ISR) Retry Limit Exceeded or Late Collision (Cleared on read) Mask */
#define GMAC_ISR_RLEX(value)                  (GMAC_ISR_RLEX_Msk & (_UINT32_(value) << GMAC_ISR_RLEX_Pos)) /* Assigment of value for RLEX in the GMAC_ISR register */
#define GMAC_ISR_TFC_Pos                      _UINT32_(6)                                          /* (GMAC_ISR) Transmit Frame Corruption Due to System Bus Error (Cleared on read) Position */
#define GMAC_ISR_TFC_Msk                      (_UINT32_(0x1) << GMAC_ISR_TFC_Pos)                  /* (GMAC_ISR) Transmit Frame Corruption Due to System Bus Error (Cleared on read) Mask */
#define GMAC_ISR_TFC(value)                   (GMAC_ISR_TFC_Msk & (_UINT32_(value) << GMAC_ISR_TFC_Pos)) /* Assigment of value for TFC in the GMAC_ISR register */
#define GMAC_ISR_TCOMP_Pos                    _UINT32_(7)                                          /* (GMAC_ISR) Transmit Complete (Cleared on read) Position */
#define GMAC_ISR_TCOMP_Msk                    (_UINT32_(0x1) << GMAC_ISR_TCOMP_Pos)                /* (GMAC_ISR) Transmit Complete (Cleared on read) Mask */
#define GMAC_ISR_TCOMP(value)                 (GMAC_ISR_TCOMP_Msk & (_UINT32_(value) << GMAC_ISR_TCOMP_Pos)) /* Assigment of value for TCOMP in the GMAC_ISR register */
#define GMAC_ISR_ROVR_Pos                     _UINT32_(10)                                         /* (GMAC_ISR) Receive Overrun (Cleared on read) Position */
#define GMAC_ISR_ROVR_Msk                     (_UINT32_(0x1) << GMAC_ISR_ROVR_Pos)                 /* (GMAC_ISR) Receive Overrun (Cleared on read) Mask */
#define GMAC_ISR_ROVR(value)                  (GMAC_ISR_ROVR_Msk & (_UINT32_(value) << GMAC_ISR_ROVR_Pos)) /* Assigment of value for ROVR in the GMAC_ISR register */
#define GMAC_ISR_HRESP_Pos                    _UINT32_(11)                                         /* (GMAC_ISR) System Bus Error (Cleared on read) Position */
#define GMAC_ISR_HRESP_Msk                    (_UINT32_(0x1) << GMAC_ISR_HRESP_Pos)                /* (GMAC_ISR) System Bus Error (Cleared on read) Mask */
#define GMAC_ISR_HRESP(value)                 (GMAC_ISR_HRESP_Msk & (_UINT32_(value) << GMAC_ISR_HRESP_Pos)) /* Assigment of value for HRESP in the GMAC_ISR register */
#define GMAC_ISR_PFNZ_Pos                     _UINT32_(12)                                         /* (GMAC_ISR) Pause Frame with Non-zero Pause Quantum Received (Cleared on read) Position */
#define GMAC_ISR_PFNZ_Msk                     (_UINT32_(0x1) << GMAC_ISR_PFNZ_Pos)                 /* (GMAC_ISR) Pause Frame with Non-zero Pause Quantum Received (Cleared on read) Mask */
#define GMAC_ISR_PFNZ(value)                  (GMAC_ISR_PFNZ_Msk & (_UINT32_(value) << GMAC_ISR_PFNZ_Pos)) /* Assigment of value for PFNZ in the GMAC_ISR register */
#define GMAC_ISR_PTZ_Pos                      _UINT32_(13)                                         /* (GMAC_ISR) Pause Time Zero (Cleared on read) Position */
#define GMAC_ISR_PTZ_Msk                      (_UINT32_(0x1) << GMAC_ISR_PTZ_Pos)                  /* (GMAC_ISR) Pause Time Zero (Cleared on read) Mask */
#define GMAC_ISR_PTZ(value)                   (GMAC_ISR_PTZ_Msk & (_UINT32_(value) << GMAC_ISR_PTZ_Pos)) /* Assigment of value for PTZ in the GMAC_ISR register */
#define GMAC_ISR_PFTR_Pos                     _UINT32_(14)                                         /* (GMAC_ISR) Pause Frame Transmitted (Cleared on read) Position */
#define GMAC_ISR_PFTR_Msk                     (_UINT32_(0x1) << GMAC_ISR_PFTR_Pos)                 /* (GMAC_ISR) Pause Frame Transmitted (Cleared on read) Mask */
#define GMAC_ISR_PFTR(value)                  (GMAC_ISR_PFTR_Msk & (_UINT32_(value) << GMAC_ISR_PFTR_Pos)) /* Assigment of value for PFTR in the GMAC_ISR register */
#define GMAC_ISR_DRQFR_Pos                    _UINT32_(18)                                         /* (GMAC_ISR) PTP Delay Request Frame Received (Cleared on read) Position */
#define GMAC_ISR_DRQFR_Msk                    (_UINT32_(0x1) << GMAC_ISR_DRQFR_Pos)                /* (GMAC_ISR) PTP Delay Request Frame Received (Cleared on read) Mask */
#define GMAC_ISR_DRQFR(value)                 (GMAC_ISR_DRQFR_Msk & (_UINT32_(value) << GMAC_ISR_DRQFR_Pos)) /* Assigment of value for DRQFR in the GMAC_ISR register */
#define GMAC_ISR_SFR_Pos                      _UINT32_(19)                                         /* (GMAC_ISR) PTP Sync Frame Received (Cleared on read) Position */
#define GMAC_ISR_SFR_Msk                      (_UINT32_(0x1) << GMAC_ISR_SFR_Pos)                  /* (GMAC_ISR) PTP Sync Frame Received (Cleared on read) Mask */
#define GMAC_ISR_SFR(value)                   (GMAC_ISR_SFR_Msk & (_UINT32_(value) << GMAC_ISR_SFR_Pos)) /* Assigment of value for SFR in the GMAC_ISR register */
#define GMAC_ISR_DRQFT_Pos                    _UINT32_(20)                                         /* (GMAC_ISR) PTP Delay Request Frame Transmitted (Cleared on read) Position */
#define GMAC_ISR_DRQFT_Msk                    (_UINT32_(0x1) << GMAC_ISR_DRQFT_Pos)                /* (GMAC_ISR) PTP Delay Request Frame Transmitted (Cleared on read) Mask */
#define GMAC_ISR_DRQFT(value)                 (GMAC_ISR_DRQFT_Msk & (_UINT32_(value) << GMAC_ISR_DRQFT_Pos)) /* Assigment of value for DRQFT in the GMAC_ISR register */
#define GMAC_ISR_SFT_Pos                      _UINT32_(21)                                         /* (GMAC_ISR) PTP Sync Frame Transmitted (Cleared on read) Position */
#define GMAC_ISR_SFT_Msk                      (_UINT32_(0x1) << GMAC_ISR_SFT_Pos)                  /* (GMAC_ISR) PTP Sync Frame Transmitted (Cleared on read) Mask */
#define GMAC_ISR_SFT(value)                   (GMAC_ISR_SFT_Msk & (_UINT32_(value) << GMAC_ISR_SFT_Pos)) /* Assigment of value for SFT in the GMAC_ISR register */
#define GMAC_ISR_PDRQFR_Pos                   _UINT32_(22)                                         /* (GMAC_ISR) PDelay Request Frame Received (Cleared on read) Position */
#define GMAC_ISR_PDRQFR_Msk                   (_UINT32_(0x1) << GMAC_ISR_PDRQFR_Pos)               /* (GMAC_ISR) PDelay Request Frame Received (Cleared on read) Mask */
#define GMAC_ISR_PDRQFR(value)                (GMAC_ISR_PDRQFR_Msk & (_UINT32_(value) << GMAC_ISR_PDRQFR_Pos)) /* Assigment of value for PDRQFR in the GMAC_ISR register */
#define GMAC_ISR_PDRSFR_Pos                   _UINT32_(23)                                         /* (GMAC_ISR) PDelay Response Frame Received (Cleared on read) Position */
#define GMAC_ISR_PDRSFR_Msk                   (_UINT32_(0x1) << GMAC_ISR_PDRSFR_Pos)               /* (GMAC_ISR) PDelay Response Frame Received (Cleared on read) Mask */
#define GMAC_ISR_PDRSFR(value)                (GMAC_ISR_PDRSFR_Msk & (_UINT32_(value) << GMAC_ISR_PDRSFR_Pos)) /* Assigment of value for PDRSFR in the GMAC_ISR register */
#define GMAC_ISR_PDRQFT_Pos                   _UINT32_(24)                                         /* (GMAC_ISR) PDelay Request Frame Transmitted (Cleared on read) Position */
#define GMAC_ISR_PDRQFT_Msk                   (_UINT32_(0x1) << GMAC_ISR_PDRQFT_Pos)               /* (GMAC_ISR) PDelay Request Frame Transmitted (Cleared on read) Mask */
#define GMAC_ISR_PDRQFT(value)                (GMAC_ISR_PDRQFT_Msk & (_UINT32_(value) << GMAC_ISR_PDRQFT_Pos)) /* Assigment of value for PDRQFT in the GMAC_ISR register */
#define GMAC_ISR_PDRSFT_Pos                   _UINT32_(25)                                         /* (GMAC_ISR) PDelay Response Frame Transmitted (Cleared on read) Position */
#define GMAC_ISR_PDRSFT_Msk                   (_UINT32_(0x1) << GMAC_ISR_PDRSFT_Pos)               /* (GMAC_ISR) PDelay Response Frame Transmitted (Cleared on read) Mask */
#define GMAC_ISR_PDRSFT(value)                (GMAC_ISR_PDRSFT_Msk & (_UINT32_(value) << GMAC_ISR_PDRSFT_Pos)) /* Assigment of value for PDRSFT in the GMAC_ISR register */
#define GMAC_ISR_SRI_Pos                      _UINT32_(26)                                         /* (GMAC_ISR) TSU Seconds Register Increment (Cleared on read) Position */
#define GMAC_ISR_SRI_Msk                      (_UINT32_(0x1) << GMAC_ISR_SRI_Pos)                  /* (GMAC_ISR) TSU Seconds Register Increment (Cleared on read) Mask */
#define GMAC_ISR_SRI(value)                   (GMAC_ISR_SRI_Msk & (_UINT32_(value) << GMAC_ISR_SRI_Pos)) /* Assigment of value for SRI in the GMAC_ISR register */
#define GMAC_ISR_RXLPISBC_Pos                 _UINT32_(27)                                         /* (GMAC_ISR) Receive LPI indication Status Bit Change (Cleared on read) Position */
#define GMAC_ISR_RXLPISBC_Msk                 (_UINT32_(0x1) << GMAC_ISR_RXLPISBC_Pos)             /* (GMAC_ISR) Receive LPI indication Status Bit Change (Cleared on read) Mask */
#define GMAC_ISR_RXLPISBC(value)              (GMAC_ISR_RXLPISBC_Msk & (_UINT32_(value) << GMAC_ISR_RXLPISBC_Pos)) /* Assigment of value for RXLPISBC in the GMAC_ISR register */
#define GMAC_ISR_WOL_Pos                      _UINT32_(28)                                         /* (GMAC_ISR) Wake On LAN Position */
#define GMAC_ISR_WOL_Msk                      (_UINT32_(0x1) << GMAC_ISR_WOL_Pos)                  /* (GMAC_ISR) Wake On LAN Mask */
#define GMAC_ISR_WOL(value)                   (GMAC_ISR_WOL_Msk & (_UINT32_(value) << GMAC_ISR_WOL_Pos)) /* Assigment of value for WOL in the GMAC_ISR register */
#define GMAC_ISR_TSUTIMCOMP_Pos               _UINT32_(29)                                         /* (GMAC_ISR) TSU Timer Comparison (Cleared on read) Position */
#define GMAC_ISR_TSUTIMCOMP_Msk               (_UINT32_(0x1) << GMAC_ISR_TSUTIMCOMP_Pos)           /* (GMAC_ISR) TSU Timer Comparison (Cleared on read) Mask */
#define GMAC_ISR_TSUTIMCOMP(value)            (GMAC_ISR_TSUTIMCOMP_Msk & (_UINT32_(value) << GMAC_ISR_TSUTIMCOMP_Pos)) /* Assigment of value for TSUTIMCOMP in the GMAC_ISR register */
#define GMAC_ISR_RXLCK_Pos                    _UINT32_(30)                                         /* (GMAC_ISR) Receive Path Lockup Detected Position */
#define GMAC_ISR_RXLCK_Msk                    (_UINT32_(0x1) << GMAC_ISR_RXLCK_Pos)                /* (GMAC_ISR) Receive Path Lockup Detected Mask */
#define GMAC_ISR_RXLCK(value)                 (GMAC_ISR_RXLCK_Msk & (_UINT32_(value) << GMAC_ISR_RXLCK_Pos)) /* Assigment of value for RXLCK in the GMAC_ISR register */
#define GMAC_ISR_TXLCK_Pos                    _UINT32_(31)                                         /* (GMAC_ISR) Transmit Path Lockup Detected Position */
#define GMAC_ISR_TXLCK_Msk                    (_UINT32_(0x1) << GMAC_ISR_TXLCK_Pos)                /* (GMAC_ISR) Transmit Path Lockup Detected Mask */
#define GMAC_ISR_TXLCK(value)                 (GMAC_ISR_TXLCK_Msk & (_UINT32_(value) << GMAC_ISR_TXLCK_Pos)) /* Assigment of value for TXLCK in the GMAC_ISR register */
#define GMAC_ISR_Msk                          _UINT32_(0xFFFC7CFF)                                 /* (GMAC_ISR) Register Mask  */


/* -------- GMAC_IER : (GMAC Offset: 0x28) ( /W 32) Interrupt Enable Register -------- */
#define GMAC_IER_MFS_Pos                      _UINT32_(0)                                          /* (GMAC_IER) Management Frame Sent Position */
#define GMAC_IER_MFS_Msk                      (_UINT32_(0x1) << GMAC_IER_MFS_Pos)                  /* (GMAC_IER) Management Frame Sent Mask */
#define GMAC_IER_MFS(value)                   (GMAC_IER_MFS_Msk & (_UINT32_(value) << GMAC_IER_MFS_Pos)) /* Assigment of value for MFS in the GMAC_IER register */
#define GMAC_IER_RCOMP_Pos                    _UINT32_(1)                                          /* (GMAC_IER) Receive Complete Position */
#define GMAC_IER_RCOMP_Msk                    (_UINT32_(0x1) << GMAC_IER_RCOMP_Pos)                /* (GMAC_IER) Receive Complete Mask */
#define GMAC_IER_RCOMP(value)                 (GMAC_IER_RCOMP_Msk & (_UINT32_(value) << GMAC_IER_RCOMP_Pos)) /* Assigment of value for RCOMP in the GMAC_IER register */
#define GMAC_IER_RXUBR_Pos                    _UINT32_(2)                                          /* (GMAC_IER) RX Used Bit Read Position */
#define GMAC_IER_RXUBR_Msk                    (_UINT32_(0x1) << GMAC_IER_RXUBR_Pos)                /* (GMAC_IER) RX Used Bit Read Mask */
#define GMAC_IER_RXUBR(value)                 (GMAC_IER_RXUBR_Msk & (_UINT32_(value) << GMAC_IER_RXUBR_Pos)) /* Assigment of value for RXUBR in the GMAC_IER register */
#define GMAC_IER_TXUBR_Pos                    _UINT32_(3)                                          /* (GMAC_IER) TX Used Bit Read Position */
#define GMAC_IER_TXUBR_Msk                    (_UINT32_(0x1) << GMAC_IER_TXUBR_Pos)                /* (GMAC_IER) TX Used Bit Read Mask */
#define GMAC_IER_TXUBR(value)                 (GMAC_IER_TXUBR_Msk & (_UINT32_(value) << GMAC_IER_TXUBR_Pos)) /* Assigment of value for TXUBR in the GMAC_IER register */
#define GMAC_IER_TUR_Pos                      _UINT32_(4)                                          /* (GMAC_IER) Transmit Underrun Position */
#define GMAC_IER_TUR_Msk                      (_UINT32_(0x1) << GMAC_IER_TUR_Pos)                  /* (GMAC_IER) Transmit Underrun Mask */
#define GMAC_IER_TUR(value)                   (GMAC_IER_TUR_Msk & (_UINT32_(value) << GMAC_IER_TUR_Pos)) /* Assigment of value for TUR in the GMAC_IER register */
#define GMAC_IER_RLEX_Pos                     _UINT32_(5)                                          /* (GMAC_IER) Retry Limit Exceeded or Late Collision Position */
#define GMAC_IER_RLEX_Msk                     (_UINT32_(0x1) << GMAC_IER_RLEX_Pos)                 /* (GMAC_IER) Retry Limit Exceeded or Late Collision Mask */
#define GMAC_IER_RLEX(value)                  (GMAC_IER_RLEX_Msk & (_UINT32_(value) << GMAC_IER_RLEX_Pos)) /* Assigment of value for RLEX in the GMAC_IER register */
#define GMAC_IER_TFC_Pos                      _UINT32_(6)                                          /* (GMAC_IER) Transmit Frame Corruption Due to System Bus Error Position */
#define GMAC_IER_TFC_Msk                      (_UINT32_(0x1) << GMAC_IER_TFC_Pos)                  /* (GMAC_IER) Transmit Frame Corruption Due to System Bus Error Mask */
#define GMAC_IER_TFC(value)                   (GMAC_IER_TFC_Msk & (_UINT32_(value) << GMAC_IER_TFC_Pos)) /* Assigment of value for TFC in the GMAC_IER register */
#define GMAC_IER_TCOMP_Pos                    _UINT32_(7)                                          /* (GMAC_IER) Transmit Complete Position */
#define GMAC_IER_TCOMP_Msk                    (_UINT32_(0x1) << GMAC_IER_TCOMP_Pos)                /* (GMAC_IER) Transmit Complete Mask */
#define GMAC_IER_TCOMP(value)                 (GMAC_IER_TCOMP_Msk & (_UINT32_(value) << GMAC_IER_TCOMP_Pos)) /* Assigment of value for TCOMP in the GMAC_IER register */
#define GMAC_IER_ROVR_Pos                     _UINT32_(10)                                         /* (GMAC_IER) Receive Overrun Position */
#define GMAC_IER_ROVR_Msk                     (_UINT32_(0x1) << GMAC_IER_ROVR_Pos)                 /* (GMAC_IER) Receive Overrun Mask */
#define GMAC_IER_ROVR(value)                  (GMAC_IER_ROVR_Msk & (_UINT32_(value) << GMAC_IER_ROVR_Pos)) /* Assigment of value for ROVR in the GMAC_IER register */
#define GMAC_IER_HRESP_Pos                    _UINT32_(11)                                         /* (GMAC_IER) System Bus Error Position */
#define GMAC_IER_HRESP_Msk                    (_UINT32_(0x1) << GMAC_IER_HRESP_Pos)                /* (GMAC_IER) System Bus Error Mask */
#define GMAC_IER_HRESP(value)                 (GMAC_IER_HRESP_Msk & (_UINT32_(value) << GMAC_IER_HRESP_Pos)) /* Assigment of value for HRESP in the GMAC_IER register */
#define GMAC_IER_PFNZ_Pos                     _UINT32_(12)                                         /* (GMAC_IER) Pause Frame with Non-zero Pause Quantum Received Position */
#define GMAC_IER_PFNZ_Msk                     (_UINT32_(0x1) << GMAC_IER_PFNZ_Pos)                 /* (GMAC_IER) Pause Frame with Non-zero Pause Quantum Received Mask */
#define GMAC_IER_PFNZ(value)                  (GMAC_IER_PFNZ_Msk & (_UINT32_(value) << GMAC_IER_PFNZ_Pos)) /* Assigment of value for PFNZ in the GMAC_IER register */
#define GMAC_IER_PTZ_Pos                      _UINT32_(13)                                         /* (GMAC_IER) Pause Time Zero Position */
#define GMAC_IER_PTZ_Msk                      (_UINT32_(0x1) << GMAC_IER_PTZ_Pos)                  /* (GMAC_IER) Pause Time Zero Mask */
#define GMAC_IER_PTZ(value)                   (GMAC_IER_PTZ_Msk & (_UINT32_(value) << GMAC_IER_PTZ_Pos)) /* Assigment of value for PTZ in the GMAC_IER register */
#define GMAC_IER_PFTR_Pos                     _UINT32_(14)                                         /* (GMAC_IER) Pause Frame Transmitted Position */
#define GMAC_IER_PFTR_Msk                     (_UINT32_(0x1) << GMAC_IER_PFTR_Pos)                 /* (GMAC_IER) Pause Frame Transmitted Mask */
#define GMAC_IER_PFTR(value)                  (GMAC_IER_PFTR_Msk & (_UINT32_(value) << GMAC_IER_PFTR_Pos)) /* Assigment of value for PFTR in the GMAC_IER register */
#define GMAC_IER_EXINT_Pos                    _UINT32_(15)                                         /* (GMAC_IER) External Interrupt Position */
#define GMAC_IER_EXINT_Msk                    (_UINT32_(0x1) << GMAC_IER_EXINT_Pos)                /* (GMAC_IER) External Interrupt Mask */
#define GMAC_IER_EXINT(value)                 (GMAC_IER_EXINT_Msk & (_UINT32_(value) << GMAC_IER_EXINT_Pos)) /* Assigment of value for EXINT in the GMAC_IER register */
#define GMAC_IER_DRQFR_Pos                    _UINT32_(18)                                         /* (GMAC_IER) PTP Delay Request Frame Received Position */
#define GMAC_IER_DRQFR_Msk                    (_UINT32_(0x1) << GMAC_IER_DRQFR_Pos)                /* (GMAC_IER) PTP Delay Request Frame Received Mask */
#define GMAC_IER_DRQFR(value)                 (GMAC_IER_DRQFR_Msk & (_UINT32_(value) << GMAC_IER_DRQFR_Pos)) /* Assigment of value for DRQFR in the GMAC_IER register */
#define GMAC_IER_SFR_Pos                      _UINT32_(19)                                         /* (GMAC_IER) PTP Sync Frame Received Position */
#define GMAC_IER_SFR_Msk                      (_UINT32_(0x1) << GMAC_IER_SFR_Pos)                  /* (GMAC_IER) PTP Sync Frame Received Mask */
#define GMAC_IER_SFR(value)                   (GMAC_IER_SFR_Msk & (_UINT32_(value) << GMAC_IER_SFR_Pos)) /* Assigment of value for SFR in the GMAC_IER register */
#define GMAC_IER_DRQFT_Pos                    _UINT32_(20)                                         /* (GMAC_IER) PTP Delay Request Frame Transmitted Position */
#define GMAC_IER_DRQFT_Msk                    (_UINT32_(0x1) << GMAC_IER_DRQFT_Pos)                /* (GMAC_IER) PTP Delay Request Frame Transmitted Mask */
#define GMAC_IER_DRQFT(value)                 (GMAC_IER_DRQFT_Msk & (_UINT32_(value) << GMAC_IER_DRQFT_Pos)) /* Assigment of value for DRQFT in the GMAC_IER register */
#define GMAC_IER_SFT_Pos                      _UINT32_(21)                                         /* (GMAC_IER) PTP Sync Frame Transmitted Position */
#define GMAC_IER_SFT_Msk                      (_UINT32_(0x1) << GMAC_IER_SFT_Pos)                  /* (GMAC_IER) PTP Sync Frame Transmitted Mask */
#define GMAC_IER_SFT(value)                   (GMAC_IER_SFT_Msk & (_UINT32_(value) << GMAC_IER_SFT_Pos)) /* Assigment of value for SFT in the GMAC_IER register */
#define GMAC_IER_PDRQFR_Pos                   _UINT32_(22)                                         /* (GMAC_IER) PDelay Request Frame Received Position */
#define GMAC_IER_PDRQFR_Msk                   (_UINT32_(0x1) << GMAC_IER_PDRQFR_Pos)               /* (GMAC_IER) PDelay Request Frame Received Mask */
#define GMAC_IER_PDRQFR(value)                (GMAC_IER_PDRQFR_Msk & (_UINT32_(value) << GMAC_IER_PDRQFR_Pos)) /* Assigment of value for PDRQFR in the GMAC_IER register */
#define GMAC_IER_PDRSFR_Pos                   _UINT32_(23)                                         /* (GMAC_IER) PDelay Response Frame Received Position */
#define GMAC_IER_PDRSFR_Msk                   (_UINT32_(0x1) << GMAC_IER_PDRSFR_Pos)               /* (GMAC_IER) PDelay Response Frame Received Mask */
#define GMAC_IER_PDRSFR(value)                (GMAC_IER_PDRSFR_Msk & (_UINT32_(value) << GMAC_IER_PDRSFR_Pos)) /* Assigment of value for PDRSFR in the GMAC_IER register */
#define GMAC_IER_PDRQFT_Pos                   _UINT32_(24)                                         /* (GMAC_IER) PDelay Request Frame Transmitted Position */
#define GMAC_IER_PDRQFT_Msk                   (_UINT32_(0x1) << GMAC_IER_PDRQFT_Pos)               /* (GMAC_IER) PDelay Request Frame Transmitted Mask */
#define GMAC_IER_PDRQFT(value)                (GMAC_IER_PDRQFT_Msk & (_UINT32_(value) << GMAC_IER_PDRQFT_Pos)) /* Assigment of value for PDRQFT in the GMAC_IER register */
#define GMAC_IER_PDRSFT_Pos                   _UINT32_(25)                                         /* (GMAC_IER) PDelay Response Frame Transmitted Position */
#define GMAC_IER_PDRSFT_Msk                   (_UINT32_(0x1) << GMAC_IER_PDRSFT_Pos)               /* (GMAC_IER) PDelay Response Frame Transmitted Mask */
#define GMAC_IER_PDRSFT(value)                (GMAC_IER_PDRSFT_Msk & (_UINT32_(value) << GMAC_IER_PDRSFT_Pos)) /* Assigment of value for PDRSFT in the GMAC_IER register */
#define GMAC_IER_SRI_Pos                      _UINT32_(26)                                         /* (GMAC_IER) TSU Seconds Register Increment Position */
#define GMAC_IER_SRI_Msk                      (_UINT32_(0x1) << GMAC_IER_SRI_Pos)                  /* (GMAC_IER) TSU Seconds Register Increment Mask */
#define GMAC_IER_SRI(value)                   (GMAC_IER_SRI_Msk & (_UINT32_(value) << GMAC_IER_SRI_Pos)) /* Assigment of value for SRI in the GMAC_IER register */
#define GMAC_IER_RXLPISBC_Pos                 _UINT32_(27)                                         /* (GMAC_IER) Enable RX LPI Indication Position */
#define GMAC_IER_RXLPISBC_Msk                 (_UINT32_(0x1) << GMAC_IER_RXLPISBC_Pos)             /* (GMAC_IER) Enable RX LPI Indication Mask */
#define GMAC_IER_RXLPISBC(value)              (GMAC_IER_RXLPISBC_Msk & (_UINT32_(value) << GMAC_IER_RXLPISBC_Pos)) /* Assigment of value for RXLPISBC in the GMAC_IER register */
#define GMAC_IER_WOL_Pos                      _UINT32_(28)                                         /* (GMAC_IER) Wake On LAN Position */
#define GMAC_IER_WOL_Msk                      (_UINT32_(0x1) << GMAC_IER_WOL_Pos)                  /* (GMAC_IER) Wake On LAN Mask */
#define GMAC_IER_WOL(value)                   (GMAC_IER_WOL_Msk & (_UINT32_(value) << GMAC_IER_WOL_Pos)) /* Assigment of value for WOL in the GMAC_IER register */
#define GMAC_IER_TSUTIMCOMP_Pos               _UINT32_(29)                                         /* (GMAC_IER) TSU Timer Comparison Position */
#define GMAC_IER_TSUTIMCOMP_Msk               (_UINT32_(0x1) << GMAC_IER_TSUTIMCOMP_Pos)           /* (GMAC_IER) TSU Timer Comparison Mask */
#define GMAC_IER_TSUTIMCOMP(value)            (GMAC_IER_TSUTIMCOMP_Msk & (_UINT32_(value) << GMAC_IER_TSUTIMCOMP_Pos)) /* Assigment of value for TSUTIMCOMP in the GMAC_IER register */
#define GMAC_IER_RXLCK_Pos                    _UINT32_(30)                                         /* (GMAC_IER) Receive Path Lockup Detected Position */
#define GMAC_IER_RXLCK_Msk                    (_UINT32_(0x1) << GMAC_IER_RXLCK_Pos)                /* (GMAC_IER) Receive Path Lockup Detected Mask */
#define GMAC_IER_RXLCK(value)                 (GMAC_IER_RXLCK_Msk & (_UINT32_(value) << GMAC_IER_RXLCK_Pos)) /* Assigment of value for RXLCK in the GMAC_IER register */
#define GMAC_IER_TXLCK_Pos                    _UINT32_(31)                                         /* (GMAC_IER) Transmit Path Lockup Detected Position */
#define GMAC_IER_TXLCK_Msk                    (_UINT32_(0x1) << GMAC_IER_TXLCK_Pos)                /* (GMAC_IER) Transmit Path Lockup Detected Mask */
#define GMAC_IER_TXLCK(value)                 (GMAC_IER_TXLCK_Msk & (_UINT32_(value) << GMAC_IER_TXLCK_Pos)) /* Assigment of value for TXLCK in the GMAC_IER register */
#define GMAC_IER_Msk                          _UINT32_(0xFFFCFCFF)                                 /* (GMAC_IER) Register Mask  */


/* -------- GMAC_IDR : (GMAC Offset: 0x2C) ( /W 32) Interrupt Disable Register -------- */
#define GMAC_IDR_MFS_Pos                      _UINT32_(0)                                          /* (GMAC_IDR) Management Frame Sent Position */
#define GMAC_IDR_MFS_Msk                      (_UINT32_(0x1) << GMAC_IDR_MFS_Pos)                  /* (GMAC_IDR) Management Frame Sent Mask */
#define GMAC_IDR_MFS(value)                   (GMAC_IDR_MFS_Msk & (_UINT32_(value) << GMAC_IDR_MFS_Pos)) /* Assigment of value for MFS in the GMAC_IDR register */
#define GMAC_IDR_RCOMP_Pos                    _UINT32_(1)                                          /* (GMAC_IDR) Receive Complete Position */
#define GMAC_IDR_RCOMP_Msk                    (_UINT32_(0x1) << GMAC_IDR_RCOMP_Pos)                /* (GMAC_IDR) Receive Complete Mask */
#define GMAC_IDR_RCOMP(value)                 (GMAC_IDR_RCOMP_Msk & (_UINT32_(value) << GMAC_IDR_RCOMP_Pos)) /* Assigment of value for RCOMP in the GMAC_IDR register */
#define GMAC_IDR_RXUBR_Pos                    _UINT32_(2)                                          /* (GMAC_IDR) RX Used Bit Read Position */
#define GMAC_IDR_RXUBR_Msk                    (_UINT32_(0x1) << GMAC_IDR_RXUBR_Pos)                /* (GMAC_IDR) RX Used Bit Read Mask */
#define GMAC_IDR_RXUBR(value)                 (GMAC_IDR_RXUBR_Msk & (_UINT32_(value) << GMAC_IDR_RXUBR_Pos)) /* Assigment of value for RXUBR in the GMAC_IDR register */
#define GMAC_IDR_TXUBR_Pos                    _UINT32_(3)                                          /* (GMAC_IDR) TX Used Bit Read Position */
#define GMAC_IDR_TXUBR_Msk                    (_UINT32_(0x1) << GMAC_IDR_TXUBR_Pos)                /* (GMAC_IDR) TX Used Bit Read Mask */
#define GMAC_IDR_TXUBR(value)                 (GMAC_IDR_TXUBR_Msk & (_UINT32_(value) << GMAC_IDR_TXUBR_Pos)) /* Assigment of value for TXUBR in the GMAC_IDR register */
#define GMAC_IDR_TUR_Pos                      _UINT32_(4)                                          /* (GMAC_IDR) Transmit Underrun Position */
#define GMAC_IDR_TUR_Msk                      (_UINT32_(0x1) << GMAC_IDR_TUR_Pos)                  /* (GMAC_IDR) Transmit Underrun Mask */
#define GMAC_IDR_TUR(value)                   (GMAC_IDR_TUR_Msk & (_UINT32_(value) << GMAC_IDR_TUR_Pos)) /* Assigment of value for TUR in the GMAC_IDR register */
#define GMAC_IDR_RLEX_Pos                     _UINT32_(5)                                          /* (GMAC_IDR) Retry Limit Exceeded or Late Collision Position */
#define GMAC_IDR_RLEX_Msk                     (_UINT32_(0x1) << GMAC_IDR_RLEX_Pos)                 /* (GMAC_IDR) Retry Limit Exceeded or Late Collision Mask */
#define GMAC_IDR_RLEX(value)                  (GMAC_IDR_RLEX_Msk & (_UINT32_(value) << GMAC_IDR_RLEX_Pos)) /* Assigment of value for RLEX in the GMAC_IDR register */
#define GMAC_IDR_TFC_Pos                      _UINT32_(6)                                          /* (GMAC_IDR) Transmit Frame Corruption Due to System Bus Error Position */
#define GMAC_IDR_TFC_Msk                      (_UINT32_(0x1) << GMAC_IDR_TFC_Pos)                  /* (GMAC_IDR) Transmit Frame Corruption Due to System Bus Error Mask */
#define GMAC_IDR_TFC(value)                   (GMAC_IDR_TFC_Msk & (_UINT32_(value) << GMAC_IDR_TFC_Pos)) /* Assigment of value for TFC in the GMAC_IDR register */
#define GMAC_IDR_TCOMP_Pos                    _UINT32_(7)                                          /* (GMAC_IDR) Transmit Complete Position */
#define GMAC_IDR_TCOMP_Msk                    (_UINT32_(0x1) << GMAC_IDR_TCOMP_Pos)                /* (GMAC_IDR) Transmit Complete Mask */
#define GMAC_IDR_TCOMP(value)                 (GMAC_IDR_TCOMP_Msk & (_UINT32_(value) << GMAC_IDR_TCOMP_Pos)) /* Assigment of value for TCOMP in the GMAC_IDR register */
#define GMAC_IDR_ROVR_Pos                     _UINT32_(10)                                         /* (GMAC_IDR) Receive Overrun Position */
#define GMAC_IDR_ROVR_Msk                     (_UINT32_(0x1) << GMAC_IDR_ROVR_Pos)                 /* (GMAC_IDR) Receive Overrun Mask */
#define GMAC_IDR_ROVR(value)                  (GMAC_IDR_ROVR_Msk & (_UINT32_(value) << GMAC_IDR_ROVR_Pos)) /* Assigment of value for ROVR in the GMAC_IDR register */
#define GMAC_IDR_HRESP_Pos                    _UINT32_(11)                                         /* (GMAC_IDR) System Bus Error Position */
#define GMAC_IDR_HRESP_Msk                    (_UINT32_(0x1) << GMAC_IDR_HRESP_Pos)                /* (GMAC_IDR) System Bus Error Mask */
#define GMAC_IDR_HRESP(value)                 (GMAC_IDR_HRESP_Msk & (_UINT32_(value) << GMAC_IDR_HRESP_Pos)) /* Assigment of value for HRESP in the GMAC_IDR register */
#define GMAC_IDR_PFNZ_Pos                     _UINT32_(12)                                         /* (GMAC_IDR) Pause Frame with Non-zero Pause Quantum Received Position */
#define GMAC_IDR_PFNZ_Msk                     (_UINT32_(0x1) << GMAC_IDR_PFNZ_Pos)                 /* (GMAC_IDR) Pause Frame with Non-zero Pause Quantum Received Mask */
#define GMAC_IDR_PFNZ(value)                  (GMAC_IDR_PFNZ_Msk & (_UINT32_(value) << GMAC_IDR_PFNZ_Pos)) /* Assigment of value for PFNZ in the GMAC_IDR register */
#define GMAC_IDR_PTZ_Pos                      _UINT32_(13)                                         /* (GMAC_IDR) Pause Time Zero Position */
#define GMAC_IDR_PTZ_Msk                      (_UINT32_(0x1) << GMAC_IDR_PTZ_Pos)                  /* (GMAC_IDR) Pause Time Zero Mask */
#define GMAC_IDR_PTZ(value)                   (GMAC_IDR_PTZ_Msk & (_UINT32_(value) << GMAC_IDR_PTZ_Pos)) /* Assigment of value for PTZ in the GMAC_IDR register */
#define GMAC_IDR_PFTR_Pos                     _UINT32_(14)                                         /* (GMAC_IDR) Pause Frame Transmitted Position */
#define GMAC_IDR_PFTR_Msk                     (_UINT32_(0x1) << GMAC_IDR_PFTR_Pos)                 /* (GMAC_IDR) Pause Frame Transmitted Mask */
#define GMAC_IDR_PFTR(value)                  (GMAC_IDR_PFTR_Msk & (_UINT32_(value) << GMAC_IDR_PFTR_Pos)) /* Assigment of value for PFTR in the GMAC_IDR register */
#define GMAC_IDR_EXINT_Pos                    _UINT32_(15)                                         /* (GMAC_IDR) External Interrupt Position */
#define GMAC_IDR_EXINT_Msk                    (_UINT32_(0x1) << GMAC_IDR_EXINT_Pos)                /* (GMAC_IDR) External Interrupt Mask */
#define GMAC_IDR_EXINT(value)                 (GMAC_IDR_EXINT_Msk & (_UINT32_(value) << GMAC_IDR_EXINT_Pos)) /* Assigment of value for EXINT in the GMAC_IDR register */
#define GMAC_IDR_DRQFR_Pos                    _UINT32_(18)                                         /* (GMAC_IDR) PTP Delay Request Frame Received Position */
#define GMAC_IDR_DRQFR_Msk                    (_UINT32_(0x1) << GMAC_IDR_DRQFR_Pos)                /* (GMAC_IDR) PTP Delay Request Frame Received Mask */
#define GMAC_IDR_DRQFR(value)                 (GMAC_IDR_DRQFR_Msk & (_UINT32_(value) << GMAC_IDR_DRQFR_Pos)) /* Assigment of value for DRQFR in the GMAC_IDR register */
#define GMAC_IDR_SFR_Pos                      _UINT32_(19)                                         /* (GMAC_IDR) PTP Sync Frame Received Position */
#define GMAC_IDR_SFR_Msk                      (_UINT32_(0x1) << GMAC_IDR_SFR_Pos)                  /* (GMAC_IDR) PTP Sync Frame Received Mask */
#define GMAC_IDR_SFR(value)                   (GMAC_IDR_SFR_Msk & (_UINT32_(value) << GMAC_IDR_SFR_Pos)) /* Assigment of value for SFR in the GMAC_IDR register */
#define GMAC_IDR_DRQFT_Pos                    _UINT32_(20)                                         /* (GMAC_IDR) PTP Delay Request Frame Transmitted Position */
#define GMAC_IDR_DRQFT_Msk                    (_UINT32_(0x1) << GMAC_IDR_DRQFT_Pos)                /* (GMAC_IDR) PTP Delay Request Frame Transmitted Mask */
#define GMAC_IDR_DRQFT(value)                 (GMAC_IDR_DRQFT_Msk & (_UINT32_(value) << GMAC_IDR_DRQFT_Pos)) /* Assigment of value for DRQFT in the GMAC_IDR register */
#define GMAC_IDR_SFT_Pos                      _UINT32_(21)                                         /* (GMAC_IDR) PTP Sync Frame Transmitted Position */
#define GMAC_IDR_SFT_Msk                      (_UINT32_(0x1) << GMAC_IDR_SFT_Pos)                  /* (GMAC_IDR) PTP Sync Frame Transmitted Mask */
#define GMAC_IDR_SFT(value)                   (GMAC_IDR_SFT_Msk & (_UINT32_(value) << GMAC_IDR_SFT_Pos)) /* Assigment of value for SFT in the GMAC_IDR register */
#define GMAC_IDR_PDRQFR_Pos                   _UINT32_(22)                                         /* (GMAC_IDR) PDelay Request Frame Received Position */
#define GMAC_IDR_PDRQFR_Msk                   (_UINT32_(0x1) << GMAC_IDR_PDRQFR_Pos)               /* (GMAC_IDR) PDelay Request Frame Received Mask */
#define GMAC_IDR_PDRQFR(value)                (GMAC_IDR_PDRQFR_Msk & (_UINT32_(value) << GMAC_IDR_PDRQFR_Pos)) /* Assigment of value for PDRQFR in the GMAC_IDR register */
#define GMAC_IDR_PDRSFR_Pos                   _UINT32_(23)                                         /* (GMAC_IDR) PDelay Response Frame Received Position */
#define GMAC_IDR_PDRSFR_Msk                   (_UINT32_(0x1) << GMAC_IDR_PDRSFR_Pos)               /* (GMAC_IDR) PDelay Response Frame Received Mask */
#define GMAC_IDR_PDRSFR(value)                (GMAC_IDR_PDRSFR_Msk & (_UINT32_(value) << GMAC_IDR_PDRSFR_Pos)) /* Assigment of value for PDRSFR in the GMAC_IDR register */
#define GMAC_IDR_PDRQFT_Pos                   _UINT32_(24)                                         /* (GMAC_IDR) PDelay Request Frame Transmitted Position */
#define GMAC_IDR_PDRQFT_Msk                   (_UINT32_(0x1) << GMAC_IDR_PDRQFT_Pos)               /* (GMAC_IDR) PDelay Request Frame Transmitted Mask */
#define GMAC_IDR_PDRQFT(value)                (GMAC_IDR_PDRQFT_Msk & (_UINT32_(value) << GMAC_IDR_PDRQFT_Pos)) /* Assigment of value for PDRQFT in the GMAC_IDR register */
#define GMAC_IDR_PDRSFT_Pos                   _UINT32_(25)                                         /* (GMAC_IDR) PDelay Response Frame Transmitted Position */
#define GMAC_IDR_PDRSFT_Msk                   (_UINT32_(0x1) << GMAC_IDR_PDRSFT_Pos)               /* (GMAC_IDR) PDelay Response Frame Transmitted Mask */
#define GMAC_IDR_PDRSFT(value)                (GMAC_IDR_PDRSFT_Msk & (_UINT32_(value) << GMAC_IDR_PDRSFT_Pos)) /* Assigment of value for PDRSFT in the GMAC_IDR register */
#define GMAC_IDR_SRI_Pos                      _UINT32_(26)                                         /* (GMAC_IDR) TSU Seconds Register Increment Position */
#define GMAC_IDR_SRI_Msk                      (_UINT32_(0x1) << GMAC_IDR_SRI_Pos)                  /* (GMAC_IDR) TSU Seconds Register Increment Mask */
#define GMAC_IDR_SRI(value)                   (GMAC_IDR_SRI_Msk & (_UINT32_(value) << GMAC_IDR_SRI_Pos)) /* Assigment of value for SRI in the GMAC_IDR register */
#define GMAC_IDR_RXLPISBC_Pos                 _UINT32_(27)                                         /* (GMAC_IDR) Enable RX LPI Indication Position */
#define GMAC_IDR_RXLPISBC_Msk                 (_UINT32_(0x1) << GMAC_IDR_RXLPISBC_Pos)             /* (GMAC_IDR) Enable RX LPI Indication Mask */
#define GMAC_IDR_RXLPISBC(value)              (GMAC_IDR_RXLPISBC_Msk & (_UINT32_(value) << GMAC_IDR_RXLPISBC_Pos)) /* Assigment of value for RXLPISBC in the GMAC_IDR register */
#define GMAC_IDR_WOL_Pos                      _UINT32_(28)                                         /* (GMAC_IDR) Wake On LAN Position */
#define GMAC_IDR_WOL_Msk                      (_UINT32_(0x1) << GMAC_IDR_WOL_Pos)                  /* (GMAC_IDR) Wake On LAN Mask */
#define GMAC_IDR_WOL(value)                   (GMAC_IDR_WOL_Msk & (_UINT32_(value) << GMAC_IDR_WOL_Pos)) /* Assigment of value for WOL in the GMAC_IDR register */
#define GMAC_IDR_TSUTIMCOMP_Pos               _UINT32_(29)                                         /* (GMAC_IDR) TSU Timer Comparison Position */
#define GMAC_IDR_TSUTIMCOMP_Msk               (_UINT32_(0x1) << GMAC_IDR_TSUTIMCOMP_Pos)           /* (GMAC_IDR) TSU Timer Comparison Mask */
#define GMAC_IDR_TSUTIMCOMP(value)            (GMAC_IDR_TSUTIMCOMP_Msk & (_UINT32_(value) << GMAC_IDR_TSUTIMCOMP_Pos)) /* Assigment of value for TSUTIMCOMP in the GMAC_IDR register */
#define GMAC_IDR_RXLCK_Pos                    _UINT32_(30)                                         /* (GMAC_IDR) Receive Path Lockup Detected Position */
#define GMAC_IDR_RXLCK_Msk                    (_UINT32_(0x1) << GMAC_IDR_RXLCK_Pos)                /* (GMAC_IDR) Receive Path Lockup Detected Mask */
#define GMAC_IDR_RXLCK(value)                 (GMAC_IDR_RXLCK_Msk & (_UINT32_(value) << GMAC_IDR_RXLCK_Pos)) /* Assigment of value for RXLCK in the GMAC_IDR register */
#define GMAC_IDR_TXLCK_Pos                    _UINT32_(31)                                         /* (GMAC_IDR) Transmit Path Lockup Detected Position */
#define GMAC_IDR_TXLCK_Msk                    (_UINT32_(0x1) << GMAC_IDR_TXLCK_Pos)                /* (GMAC_IDR) Transmit Path Lockup Detected Mask */
#define GMAC_IDR_TXLCK(value)                 (GMAC_IDR_TXLCK_Msk & (_UINT32_(value) << GMAC_IDR_TXLCK_Pos)) /* Assigment of value for TXLCK in the GMAC_IDR register */
#define GMAC_IDR_Msk                          _UINT32_(0xFFFCFCFF)                                 /* (GMAC_IDR) Register Mask  */


/* -------- GMAC_IMR : (GMAC Offset: 0x30) (R/W 32) Interrupt Mask Register -------- */
#define GMAC_IMR_RESETVALUE                   _UINT32_(0x7FFFFFF)                                  /*  (GMAC_IMR) Interrupt Mask Register  Reset Value */

#define GMAC_IMR_MFS_Pos                      _UINT32_(0)                                          /* (GMAC_IMR) Management Frame Sent Position */
#define GMAC_IMR_MFS_Msk                      (_UINT32_(0x1) << GMAC_IMR_MFS_Pos)                  /* (GMAC_IMR) Management Frame Sent Mask */
#define GMAC_IMR_MFS(value)                   (GMAC_IMR_MFS_Msk & (_UINT32_(value) << GMAC_IMR_MFS_Pos)) /* Assigment of value for MFS in the GMAC_IMR register */
#define GMAC_IMR_RCOMP_Pos                    _UINT32_(1)                                          /* (GMAC_IMR) Receive Complete Position */
#define GMAC_IMR_RCOMP_Msk                    (_UINT32_(0x1) << GMAC_IMR_RCOMP_Pos)                /* (GMAC_IMR) Receive Complete Mask */
#define GMAC_IMR_RCOMP(value)                 (GMAC_IMR_RCOMP_Msk & (_UINT32_(value) << GMAC_IMR_RCOMP_Pos)) /* Assigment of value for RCOMP in the GMAC_IMR register */
#define GMAC_IMR_RXUBR_Pos                    _UINT32_(2)                                          /* (GMAC_IMR) RX Used Bit Read Position */
#define GMAC_IMR_RXUBR_Msk                    (_UINT32_(0x1) << GMAC_IMR_RXUBR_Pos)                /* (GMAC_IMR) RX Used Bit Read Mask */
#define GMAC_IMR_RXUBR(value)                 (GMAC_IMR_RXUBR_Msk & (_UINT32_(value) << GMAC_IMR_RXUBR_Pos)) /* Assigment of value for RXUBR in the GMAC_IMR register */
#define GMAC_IMR_TXUBR_Pos                    _UINT32_(3)                                          /* (GMAC_IMR) TX Used Bit Read Position */
#define GMAC_IMR_TXUBR_Msk                    (_UINT32_(0x1) << GMAC_IMR_TXUBR_Pos)                /* (GMAC_IMR) TX Used Bit Read Mask */
#define GMAC_IMR_TXUBR(value)                 (GMAC_IMR_TXUBR_Msk & (_UINT32_(value) << GMAC_IMR_TXUBR_Pos)) /* Assigment of value for TXUBR in the GMAC_IMR register */
#define GMAC_IMR_TUR_Pos                      _UINT32_(4)                                          /* (GMAC_IMR) Transmit Underrun Position */
#define GMAC_IMR_TUR_Msk                      (_UINT32_(0x1) << GMAC_IMR_TUR_Pos)                  /* (GMAC_IMR) Transmit Underrun Mask */
#define GMAC_IMR_TUR(value)                   (GMAC_IMR_TUR_Msk & (_UINT32_(value) << GMAC_IMR_TUR_Pos)) /* Assigment of value for TUR in the GMAC_IMR register */
#define GMAC_IMR_RLEX_Pos                     _UINT32_(5)                                          /* (GMAC_IMR) Retry Limit Exceeded or Late Collision Position */
#define GMAC_IMR_RLEX_Msk                     (_UINT32_(0x1) << GMAC_IMR_RLEX_Pos)                 /* (GMAC_IMR) Retry Limit Exceeded or Late Collision Mask */
#define GMAC_IMR_RLEX(value)                  (GMAC_IMR_RLEX_Msk & (_UINT32_(value) << GMAC_IMR_RLEX_Pos)) /* Assigment of value for RLEX in the GMAC_IMR register */
#define GMAC_IMR_TFC_Pos                      _UINT32_(6)                                          /* (GMAC_IMR) Transmit Frame Corruption Due to System Bus Error Position */
#define GMAC_IMR_TFC_Msk                      (_UINT32_(0x1) << GMAC_IMR_TFC_Pos)                  /* (GMAC_IMR) Transmit Frame Corruption Due to System Bus Error Mask */
#define GMAC_IMR_TFC(value)                   (GMAC_IMR_TFC_Msk & (_UINT32_(value) << GMAC_IMR_TFC_Pos)) /* Assigment of value for TFC in the GMAC_IMR register */
#define GMAC_IMR_TCOMP_Pos                    _UINT32_(7)                                          /* (GMAC_IMR) Transmit Complete Position */
#define GMAC_IMR_TCOMP_Msk                    (_UINT32_(0x1) << GMAC_IMR_TCOMP_Pos)                /* (GMAC_IMR) Transmit Complete Mask */
#define GMAC_IMR_TCOMP(value)                 (GMAC_IMR_TCOMP_Msk & (_UINT32_(value) << GMAC_IMR_TCOMP_Pos)) /* Assigment of value for TCOMP in the GMAC_IMR register */
#define GMAC_IMR_ROVR_Pos                     _UINT32_(10)                                         /* (GMAC_IMR) Receive Overrun Position */
#define GMAC_IMR_ROVR_Msk                     (_UINT32_(0x1) << GMAC_IMR_ROVR_Pos)                 /* (GMAC_IMR) Receive Overrun Mask */
#define GMAC_IMR_ROVR(value)                  (GMAC_IMR_ROVR_Msk & (_UINT32_(value) << GMAC_IMR_ROVR_Pos)) /* Assigment of value for ROVR in the GMAC_IMR register */
#define GMAC_IMR_HRESP_Pos                    _UINT32_(11)                                         /* (GMAC_IMR) System Bus Error Position */
#define GMAC_IMR_HRESP_Msk                    (_UINT32_(0x1) << GMAC_IMR_HRESP_Pos)                /* (GMAC_IMR) System Bus Error Mask */
#define GMAC_IMR_HRESP(value)                 (GMAC_IMR_HRESP_Msk & (_UINT32_(value) << GMAC_IMR_HRESP_Pos)) /* Assigment of value for HRESP in the GMAC_IMR register */
#define GMAC_IMR_PFNZ_Pos                     _UINT32_(12)                                         /* (GMAC_IMR) Pause Frame with Non-zero Pause Quantum Received Position */
#define GMAC_IMR_PFNZ_Msk                     (_UINT32_(0x1) << GMAC_IMR_PFNZ_Pos)                 /* (GMAC_IMR) Pause Frame with Non-zero Pause Quantum Received Mask */
#define GMAC_IMR_PFNZ(value)                  (GMAC_IMR_PFNZ_Msk & (_UINT32_(value) << GMAC_IMR_PFNZ_Pos)) /* Assigment of value for PFNZ in the GMAC_IMR register */
#define GMAC_IMR_PTZ_Pos                      _UINT32_(13)                                         /* (GMAC_IMR) Pause Time Zero Position */
#define GMAC_IMR_PTZ_Msk                      (_UINT32_(0x1) << GMAC_IMR_PTZ_Pos)                  /* (GMAC_IMR) Pause Time Zero Mask */
#define GMAC_IMR_PTZ(value)                   (GMAC_IMR_PTZ_Msk & (_UINT32_(value) << GMAC_IMR_PTZ_Pos)) /* Assigment of value for PTZ in the GMAC_IMR register */
#define GMAC_IMR_PFTR_Pos                     _UINT32_(14)                                         /* (GMAC_IMR) Pause Frame Transmitted Position */
#define GMAC_IMR_PFTR_Msk                     (_UINT32_(0x1) << GMAC_IMR_PFTR_Pos)                 /* (GMAC_IMR) Pause Frame Transmitted Mask */
#define GMAC_IMR_PFTR(value)                  (GMAC_IMR_PFTR_Msk & (_UINT32_(value) << GMAC_IMR_PFTR_Pos)) /* Assigment of value for PFTR in the GMAC_IMR register */
#define GMAC_IMR_EXINT_Pos                    _UINT32_(15)                                         /* (GMAC_IMR) External Interrupt Position */
#define GMAC_IMR_EXINT_Msk                    (_UINT32_(0x1) << GMAC_IMR_EXINT_Pos)                /* (GMAC_IMR) External Interrupt Mask */
#define GMAC_IMR_EXINT(value)                 (GMAC_IMR_EXINT_Msk & (_UINT32_(value) << GMAC_IMR_EXINT_Pos)) /* Assigment of value for EXINT in the GMAC_IMR register */
#define GMAC_IMR_DRQFR_Pos                    _UINT32_(18)                                         /* (GMAC_IMR) PTP Delay Request Frame Received Position */
#define GMAC_IMR_DRQFR_Msk                    (_UINT32_(0x1) << GMAC_IMR_DRQFR_Pos)                /* (GMAC_IMR) PTP Delay Request Frame Received Mask */
#define GMAC_IMR_DRQFR(value)                 (GMAC_IMR_DRQFR_Msk & (_UINT32_(value) << GMAC_IMR_DRQFR_Pos)) /* Assigment of value for DRQFR in the GMAC_IMR register */
#define GMAC_IMR_SFR_Pos                      _UINT32_(19)                                         /* (GMAC_IMR) PTP Sync Frame Received Position */
#define GMAC_IMR_SFR_Msk                      (_UINT32_(0x1) << GMAC_IMR_SFR_Pos)                  /* (GMAC_IMR) PTP Sync Frame Received Mask */
#define GMAC_IMR_SFR(value)                   (GMAC_IMR_SFR_Msk & (_UINT32_(value) << GMAC_IMR_SFR_Pos)) /* Assigment of value for SFR in the GMAC_IMR register */
#define GMAC_IMR_DRQFT_Pos                    _UINT32_(20)                                         /* (GMAC_IMR) PTP Delay Request Frame Transmitted Position */
#define GMAC_IMR_DRQFT_Msk                    (_UINT32_(0x1) << GMAC_IMR_DRQFT_Pos)                /* (GMAC_IMR) PTP Delay Request Frame Transmitted Mask */
#define GMAC_IMR_DRQFT(value)                 (GMAC_IMR_DRQFT_Msk & (_UINT32_(value) << GMAC_IMR_DRQFT_Pos)) /* Assigment of value for DRQFT in the GMAC_IMR register */
#define GMAC_IMR_SFT_Pos                      _UINT32_(21)                                         /* (GMAC_IMR) PTP Sync Frame Transmitted Position */
#define GMAC_IMR_SFT_Msk                      (_UINT32_(0x1) << GMAC_IMR_SFT_Pos)                  /* (GMAC_IMR) PTP Sync Frame Transmitted Mask */
#define GMAC_IMR_SFT(value)                   (GMAC_IMR_SFT_Msk & (_UINT32_(value) << GMAC_IMR_SFT_Pos)) /* Assigment of value for SFT in the GMAC_IMR register */
#define GMAC_IMR_PDRQFR_Pos                   _UINT32_(22)                                         /* (GMAC_IMR) PDelay Request Frame Received Position */
#define GMAC_IMR_PDRQFR_Msk                   (_UINT32_(0x1) << GMAC_IMR_PDRQFR_Pos)               /* (GMAC_IMR) PDelay Request Frame Received Mask */
#define GMAC_IMR_PDRQFR(value)                (GMAC_IMR_PDRQFR_Msk & (_UINT32_(value) << GMAC_IMR_PDRQFR_Pos)) /* Assigment of value for PDRQFR in the GMAC_IMR register */
#define GMAC_IMR_PDRSFR_Pos                   _UINT32_(23)                                         /* (GMAC_IMR) PDelay Response Frame Received Position */
#define GMAC_IMR_PDRSFR_Msk                   (_UINT32_(0x1) << GMAC_IMR_PDRSFR_Pos)               /* (GMAC_IMR) PDelay Response Frame Received Mask */
#define GMAC_IMR_PDRSFR(value)                (GMAC_IMR_PDRSFR_Msk & (_UINT32_(value) << GMAC_IMR_PDRSFR_Pos)) /* Assigment of value for PDRSFR in the GMAC_IMR register */
#define GMAC_IMR_PDRQFT_Pos                   _UINT32_(24)                                         /* (GMAC_IMR) PDelay Request Frame Transmitted Position */
#define GMAC_IMR_PDRQFT_Msk                   (_UINT32_(0x1) << GMAC_IMR_PDRQFT_Pos)               /* (GMAC_IMR) PDelay Request Frame Transmitted Mask */
#define GMAC_IMR_PDRQFT(value)                (GMAC_IMR_PDRQFT_Msk & (_UINT32_(value) << GMAC_IMR_PDRQFT_Pos)) /* Assigment of value for PDRQFT in the GMAC_IMR register */
#define GMAC_IMR_PDRSFT_Pos                   _UINT32_(25)                                         /* (GMAC_IMR) PDelay Response Frame Transmitted Position */
#define GMAC_IMR_PDRSFT_Msk                   (_UINT32_(0x1) << GMAC_IMR_PDRSFT_Pos)               /* (GMAC_IMR) PDelay Response Frame Transmitted Mask */
#define GMAC_IMR_PDRSFT(value)                (GMAC_IMR_PDRSFT_Msk & (_UINT32_(value) << GMAC_IMR_PDRSFT_Pos)) /* Assigment of value for PDRSFT in the GMAC_IMR register */
#define GMAC_IMR_SRI_Pos                      _UINT32_(26)                                         /* (GMAC_IMR) TSU Seconds Register Increment Position */
#define GMAC_IMR_SRI_Msk                      (_UINT32_(0x1) << GMAC_IMR_SRI_Pos)                  /* (GMAC_IMR) TSU Seconds Register Increment Mask */
#define GMAC_IMR_SRI(value)                   (GMAC_IMR_SRI_Msk & (_UINT32_(value) << GMAC_IMR_SRI_Pos)) /* Assigment of value for SRI in the GMAC_IMR register */
#define GMAC_IMR_RXLPISBC_Pos                 _UINT32_(27)                                         /* (GMAC_IMR) Enable RX LPI Indication Position */
#define GMAC_IMR_RXLPISBC_Msk                 (_UINT32_(0x1) << GMAC_IMR_RXLPISBC_Pos)             /* (GMAC_IMR) Enable RX LPI Indication Mask */
#define GMAC_IMR_RXLPISBC(value)              (GMAC_IMR_RXLPISBC_Msk & (_UINT32_(value) << GMAC_IMR_RXLPISBC_Pos)) /* Assigment of value for RXLPISBC in the GMAC_IMR register */
#define GMAC_IMR_WOL_Pos                      _UINT32_(28)                                         /* (GMAC_IMR) Wake On LAN Position */
#define GMAC_IMR_WOL_Msk                      (_UINT32_(0x1) << GMAC_IMR_WOL_Pos)                  /* (GMAC_IMR) Wake On LAN Mask */
#define GMAC_IMR_WOL(value)                   (GMAC_IMR_WOL_Msk & (_UINT32_(value) << GMAC_IMR_WOL_Pos)) /* Assigment of value for WOL in the GMAC_IMR register */
#define GMAC_IMR_TSUTIMCOMP_Pos               _UINT32_(29)                                         /* (GMAC_IMR) TSU Timer Comparison Position */
#define GMAC_IMR_TSUTIMCOMP_Msk               (_UINT32_(0x1) << GMAC_IMR_TSUTIMCOMP_Pos)           /* (GMAC_IMR) TSU Timer Comparison Mask */
#define GMAC_IMR_TSUTIMCOMP(value)            (GMAC_IMR_TSUTIMCOMP_Msk & (_UINT32_(value) << GMAC_IMR_TSUTIMCOMP_Pos)) /* Assigment of value for TSUTIMCOMP in the GMAC_IMR register */
#define GMAC_IMR_RXLCK_Pos                    _UINT32_(30)                                         /* (GMAC_IMR) Receive Path Lockup Detected Position */
#define GMAC_IMR_RXLCK_Msk                    (_UINT32_(0x1) << GMAC_IMR_RXLCK_Pos)                /* (GMAC_IMR) Receive Path Lockup Detected Mask */
#define GMAC_IMR_RXLCK(value)                 (GMAC_IMR_RXLCK_Msk & (_UINT32_(value) << GMAC_IMR_RXLCK_Pos)) /* Assigment of value for RXLCK in the GMAC_IMR register */
#define GMAC_IMR_TXLCK_Pos                    _UINT32_(31)                                         /* (GMAC_IMR) Transmit Path Lockup Detected Position */
#define GMAC_IMR_TXLCK_Msk                    (_UINT32_(0x1) << GMAC_IMR_TXLCK_Pos)                /* (GMAC_IMR) Transmit Path Lockup Detected Mask */
#define GMAC_IMR_TXLCK(value)                 (GMAC_IMR_TXLCK_Msk & (_UINT32_(value) << GMAC_IMR_TXLCK_Pos)) /* Assigment of value for TXLCK in the GMAC_IMR register */
#define GMAC_IMR_Msk                          _UINT32_(0xFFFCFCFF)                                 /* (GMAC_IMR) Register Mask  */


/* -------- GMAC_MAN : (GMAC Offset: 0x34) (R/W 32) PHY Maintenance Register -------- */
#define GMAC_MAN_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_MAN) PHY Maintenance Register  Reset Value */

#define GMAC_MAN_DATA_Pos                     _UINT32_(0)                                          /* (GMAC_MAN) PHY Data Position */
#define GMAC_MAN_DATA_Msk                     (_UINT32_(0xFFFF) << GMAC_MAN_DATA_Pos)              /* (GMAC_MAN) PHY Data Mask */
#define GMAC_MAN_DATA(value)                  (GMAC_MAN_DATA_Msk & (_UINT32_(value) << GMAC_MAN_DATA_Pos)) /* Assigment of value for DATA in the GMAC_MAN register */
#define GMAC_MAN_WTN_Pos                      _UINT32_(16)                                         /* (GMAC_MAN) Write Ten Position */
#define GMAC_MAN_WTN_Msk                      (_UINT32_(0x3) << GMAC_MAN_WTN_Pos)                  /* (GMAC_MAN) Write Ten Mask */
#define GMAC_MAN_WTN(value)                   (GMAC_MAN_WTN_Msk & (_UINT32_(value) << GMAC_MAN_WTN_Pos)) /* Assigment of value for WTN in the GMAC_MAN register */
#define GMAC_MAN_REGA_Pos                     _UINT32_(18)                                         /* (GMAC_MAN) Register Address Position */
#define GMAC_MAN_REGA_Msk                     (_UINT32_(0x1F) << GMAC_MAN_REGA_Pos)                /* (GMAC_MAN) Register Address Mask */
#define GMAC_MAN_REGA(value)                  (GMAC_MAN_REGA_Msk & (_UINT32_(value) << GMAC_MAN_REGA_Pos)) /* Assigment of value for REGA in the GMAC_MAN register */
#define GMAC_MAN_PHYA_Pos                     _UINT32_(23)                                         /* (GMAC_MAN) PHY Address Position */
#define GMAC_MAN_PHYA_Msk                     (_UINT32_(0x1F) << GMAC_MAN_PHYA_Pos)                /* (GMAC_MAN) PHY Address Mask */
#define GMAC_MAN_PHYA(value)                  (GMAC_MAN_PHYA_Msk & (_UINT32_(value) << GMAC_MAN_PHYA_Pos)) /* Assigment of value for PHYA in the GMAC_MAN register */
#define GMAC_MAN_OP_Pos                       _UINT32_(28)                                         /* (GMAC_MAN) Operation Position */
#define GMAC_MAN_OP_Msk                       (_UINT32_(0x3) << GMAC_MAN_OP_Pos)                   /* (GMAC_MAN) Operation Mask */
#define GMAC_MAN_OP(value)                    (GMAC_MAN_OP_Msk & (_UINT32_(value) << GMAC_MAN_OP_Pos)) /* Assigment of value for OP in the GMAC_MAN register */
#define   GMAC_MAN_OP_1_Val                   _UINT32_(0x1)                                        /* (GMAC_MAN) Write  */
#define   GMAC_MAN_OP_2_Val                   _UINT32_(0x2)                                        /* (GMAC_MAN) Read  */
#define GMAC_MAN_OP_1                         (GMAC_MAN_OP_1_Val << GMAC_MAN_OP_Pos)               /* (GMAC_MAN) Write Position  */
#define GMAC_MAN_OP_2                         (GMAC_MAN_OP_2_Val << GMAC_MAN_OP_Pos)               /* (GMAC_MAN) Read Position  */
#define GMAC_MAN_CLTTO_Pos                    _UINT32_(30)                                         /* (GMAC_MAN) Clause 22 Operation Position */
#define GMAC_MAN_CLTTO_Msk                    (_UINT32_(0x1) << GMAC_MAN_CLTTO_Pos)                /* (GMAC_MAN) Clause 22 Operation Mask */
#define GMAC_MAN_CLTTO(value)                 (GMAC_MAN_CLTTO_Msk & (_UINT32_(value) << GMAC_MAN_CLTTO_Pos)) /* Assigment of value for CLTTO in the GMAC_MAN register */
#define   GMAC_MAN_CLTTO_0_Val                _UINT32_(0x0)                                        /* (GMAC_MAN) Clause 45 operation  */
#define   GMAC_MAN_CLTTO_1_Val                _UINT32_(0x1)                                        /* (GMAC_MAN) Clause 22 operation  */
#define GMAC_MAN_CLTTO_0                      (GMAC_MAN_CLTTO_0_Val << GMAC_MAN_CLTTO_Pos)         /* (GMAC_MAN) Clause 45 operation Position  */
#define GMAC_MAN_CLTTO_1                      (GMAC_MAN_CLTTO_1_Val << GMAC_MAN_CLTTO_Pos)         /* (GMAC_MAN) Clause 22 operation Position  */
#define GMAC_MAN_WZO_Pos                      _UINT32_(31)                                         /* (GMAC_MAN) Write ZERO Position */
#define GMAC_MAN_WZO_Msk                      (_UINT32_(0x1) << GMAC_MAN_WZO_Pos)                  /* (GMAC_MAN) Write ZERO Mask */
#define GMAC_MAN_WZO(value)                   (GMAC_MAN_WZO_Msk & (_UINT32_(value) << GMAC_MAN_WZO_Pos)) /* Assigment of value for WZO in the GMAC_MAN register */
#define GMAC_MAN_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (GMAC_MAN) Register Mask  */


/* -------- GMAC_RPQ : (GMAC Offset: 0x38) ( R/ 32) Receive Pause Quantum Register -------- */
#define GMAC_RPQ_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_RPQ) Receive Pause Quantum Register  Reset Value */

#define GMAC_RPQ_RPQ_Pos                      _UINT32_(0)                                          /* (GMAC_RPQ) Received Pause Quantum Position */
#define GMAC_RPQ_RPQ_Msk                      (_UINT32_(0xFFFF) << GMAC_RPQ_RPQ_Pos)               /* (GMAC_RPQ) Received Pause Quantum Mask */
#define GMAC_RPQ_RPQ(value)                   (GMAC_RPQ_RPQ_Msk & (_UINT32_(value) << GMAC_RPQ_RPQ_Pos)) /* Assigment of value for RPQ in the GMAC_RPQ register */
#define GMAC_RPQ_Msk                          _UINT32_(0x0000FFFF)                                 /* (GMAC_RPQ) Register Mask  */


/* -------- GMAC_TPQ : (GMAC Offset: 0x3C) (R/W 32) Transmit Pause Quantum Register -------- */
#define GMAC_TPQ_RESETVALUE                   _UINT32_(0xFFFFFFFF)                                 /*  (GMAC_TPQ) Transmit Pause Quantum Register  Reset Value */

#define GMAC_TPQ_TPQ_Pos                      _UINT32_(0)                                          /* (GMAC_TPQ) Transmit Pause Quantum Position */
#define GMAC_TPQ_TPQ_Msk                      (_UINT32_(0xFFFF) << GMAC_TPQ_TPQ_Pos)               /* (GMAC_TPQ) Transmit Pause Quantum Mask */
#define GMAC_TPQ_TPQ(value)                   (GMAC_TPQ_TPQ_Msk & (_UINT32_(value) << GMAC_TPQ_TPQ_Pos)) /* Assigment of value for TPQ in the GMAC_TPQ register */
#define GMAC_TPQ_P1TPQ_Pos                    _UINT32_(16)                                         /* (GMAC_TPQ) Priority 1 Transmit Pause Quantum Position */
#define GMAC_TPQ_P1TPQ_Msk                    (_UINT32_(0xFFFF) << GMAC_TPQ_P1TPQ_Pos)             /* (GMAC_TPQ) Priority 1 Transmit Pause Quantum Mask */
#define GMAC_TPQ_P1TPQ(value)                 (GMAC_TPQ_P1TPQ_Msk & (_UINT32_(value) << GMAC_TPQ_P1TPQ_Pos)) /* Assigment of value for P1TPQ in the GMAC_TPQ register */
#define GMAC_TPQ_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (GMAC_TPQ) Register Mask  */


/* -------- GMAC_TPSF : (GMAC Offset: 0x40) (R/W 32) TX Partial Store and Forward Register -------- */
#define GMAC_TPSF_RESETVALUE                  _UINT32_(0xFFF)                                      /*  (GMAC_TPSF) TX Partial Store and Forward Register  Reset Value */

#define GMAC_TPSF_TPB1ADR_Pos                 _UINT32_(0)                                          /* (GMAC_TPSF) Transmit Partial Store and Forward Address Position */
#define GMAC_TPSF_TPB1ADR_Msk                 (_UINT32_(0xFFF) << GMAC_TPSF_TPB1ADR_Pos)           /* (GMAC_TPSF) Transmit Partial Store and Forward Address Mask */
#define GMAC_TPSF_TPB1ADR(value)              (GMAC_TPSF_TPB1ADR_Msk & (_UINT32_(value) << GMAC_TPSF_TPB1ADR_Pos)) /* Assigment of value for TPB1ADR in the GMAC_TPSF register */
#define GMAC_TPSF_ENTXP_Pos                   _UINT32_(31)                                         /* (GMAC_TPSF) Enable TX Partial Store and Forward Operation Position */
#define GMAC_TPSF_ENTXP_Msk                   (_UINT32_(0x1) << GMAC_TPSF_ENTXP_Pos)               /* (GMAC_TPSF) Enable TX Partial Store and Forward Operation Mask */
#define GMAC_TPSF_ENTXP(value)                (GMAC_TPSF_ENTXP_Msk & (_UINT32_(value) << GMAC_TPSF_ENTXP_Pos)) /* Assigment of value for ENTXP in the GMAC_TPSF register */
#define GMAC_TPSF_Msk                         _UINT32_(0x80000FFF)                                 /* (GMAC_TPSF) Register Mask  */


/* -------- GMAC_RPSF : (GMAC Offset: 0x44) (R/W 32) RX Partial Store and Forward Register -------- */
#define GMAC_RPSF_RESETVALUE                  _UINT32_(0xFFF)                                      /*  (GMAC_RPSF) RX Partial Store and Forward Register  Reset Value */

#define GMAC_RPSF_RPB1ADR_Pos                 _UINT32_(0)                                          /* (GMAC_RPSF) Receive Partial Store and Forward Address Position */
#define GMAC_RPSF_RPB1ADR_Msk                 (_UINT32_(0x3FF) << GMAC_RPSF_RPB1ADR_Pos)           /* (GMAC_RPSF) Receive Partial Store and Forward Address Mask */
#define GMAC_RPSF_RPB1ADR(value)              (GMAC_RPSF_RPB1ADR_Msk & (_UINT32_(value) << GMAC_RPSF_RPB1ADR_Pos)) /* Assigment of value for RPB1ADR in the GMAC_RPSF register */
#define GMAC_RPSF_ENRXP_Pos                   _UINT32_(31)                                         /* (GMAC_RPSF) Enable RX Partial Store and Forward Operation Position */
#define GMAC_RPSF_ENRXP_Msk                   (_UINT32_(0x1) << GMAC_RPSF_ENRXP_Pos)               /* (GMAC_RPSF) Enable RX Partial Store and Forward Operation Mask */
#define GMAC_RPSF_ENRXP(value)                (GMAC_RPSF_ENRXP_Msk & (_UINT32_(value) << GMAC_RPSF_ENRXP_Pos)) /* Assigment of value for ENRXP in the GMAC_RPSF register */
#define GMAC_RPSF_Msk                         _UINT32_(0x800003FF)                                 /* (GMAC_RPSF) Register Mask  */


/* -------- GMAC_RJFML : (GMAC Offset: 0x48) (R/W 32) RX Jumbo Frame Max Length Register -------- */
#define GMAC_RJFML_RESETVALUE                 _UINT32_(0x3FFF)                                     /*  (GMAC_RJFML) RX Jumbo Frame Max Length Register  Reset Value */

#define GMAC_RJFML_FML_Pos                    _UINT32_(0)                                          /* (GMAC_RJFML) Frame Max Length Position */
#define GMAC_RJFML_FML_Msk                    (_UINT32_(0x3FFF) << GMAC_RJFML_FML_Pos)             /* (GMAC_RJFML) Frame Max Length Mask */
#define GMAC_RJFML_FML(value)                 (GMAC_RJFML_FML_Msk & (_UINT32_(value) << GMAC_RJFML_FML_Pos)) /* Assigment of value for FML in the GMAC_RJFML register */
#define GMAC_RJFML_Msk                        _UINT32_(0x00003FFF)                                 /* (GMAC_RJFML) Register Mask  */


/* -------- GMAC_INTM : (GMAC Offset: 0x5C) (R/W 32) Interrupt Moderation Register -------- */
#define GMAC_INTM_RESETVALUE                  _UINT32_(0x00)                                       /*  (GMAC_INTM) Interrupt Moderation Register  Reset Value */

#define GMAC_INTM_RXINTMOD_Pos                _UINT32_(0)                                          /* (GMAC_INTM) Receive Interrupt Moderation Position */
#define GMAC_INTM_RXINTMOD_Msk                (_UINT32_(0xFF) << GMAC_INTM_RXINTMOD_Pos)           /* (GMAC_INTM) Receive Interrupt Moderation Mask */
#define GMAC_INTM_RXINTMOD(value)             (GMAC_INTM_RXINTMOD_Msk & (_UINT32_(value) << GMAC_INTM_RXINTMOD_Pos)) /* Assigment of value for RXINTMOD in the GMAC_INTM register */
#define GMAC_INTM_TXINTMOD_Pos                _UINT32_(16)                                         /* (GMAC_INTM) Transmit Interrupt Moderation Position */
#define GMAC_INTM_TXINTMOD_Msk                (_UINT32_(0xFF) << GMAC_INTM_TXINTMOD_Pos)           /* (GMAC_INTM) Transmit Interrupt Moderation Mask */
#define GMAC_INTM_TXINTMOD(value)             (GMAC_INTM_TXINTMOD_Msk & (_UINT32_(value) << GMAC_INTM_TXINTMOD_Pos)) /* Assigment of value for TXINTMOD in the GMAC_INTM register */
#define GMAC_INTM_Msk                         _UINT32_(0x00FF00FF)                                 /* (GMAC_INTM) Register Mask  */


/* -------- GMAC_SYSWT : (GMAC Offset: 0x60) (R/W 32) System Wake-Up Time Register -------- */
#define GMAC_SYSWT_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_SYSWT) System Wake-Up Time Register  Reset Value */

#define GMAC_SYSWT_SYSWKUPTIME_Pos            _UINT32_(0)                                          /* (GMAC_SYSWT) System Wake-up Time Position */
#define GMAC_SYSWT_SYSWKUPTIME_Msk            (_UINT32_(0xFFFF) << GMAC_SYSWT_SYSWKUPTIME_Pos)     /* (GMAC_SYSWT) System Wake-up Time Mask */
#define GMAC_SYSWT_SYSWKUPTIME(value)         (GMAC_SYSWT_SYSWKUPTIME_Msk & (_UINT32_(value) << GMAC_SYSWT_SYSWKUPTIME_Pos)) /* Assigment of value for SYSWKUPTIME in the GMAC_SYSWT register */
#define GMAC_SYSWT_Msk                        _UINT32_(0x0000FFFF)                                 /* (GMAC_SYSWT) Register Mask  */


/* -------- GMAC_LCKUP_CFGR : (GMAC Offset: 0x68) (R/W 32) Lockup Configuration Register -------- */
#define GMAC_LCKUP_CFGR_RESETVALUE            _UINT32_(0x7FFFFFF)                                  /*  (GMAC_LCKUP_CFGR) Lockup Configuration Register  Reset Value */

#define GMAC_LCKUP_CFGR_PRESCALER_Pos         _UINT32_(0)                                          /* (GMAC_LCKUP_CFGR) Prescaler Value for Timeout Position */
#define GMAC_LCKUP_CFGR_PRESCALER_Msk         (_UINT32_(0xFFFF) << GMAC_LCKUP_CFGR_PRESCALER_Pos)  /* (GMAC_LCKUP_CFGR) Prescaler Value for Timeout Mask */
#define GMAC_LCKUP_CFGR_PRESCALER(value)      (GMAC_LCKUP_CFGR_PRESCALER_Msk & (_UINT32_(value) << GMAC_LCKUP_CFGR_PRESCALER_Pos)) /* Assigment of value for PRESCALER in the GMAC_LCKUP_CFGR register */
#define GMAC_LCKUP_CFGR_DMA_LOCKUP_TIME_Pos   _UINT32_(16)                                         /* (GMAC_LCKUP_CFGR) Timeout Value for Receive and Transmit DMA Position */
#define GMAC_LCKUP_CFGR_DMA_LOCKUP_TIME_Msk   (_UINT32_(0x7FF) << GMAC_LCKUP_CFGR_DMA_LOCKUP_TIME_Pos) /* (GMAC_LCKUP_CFGR) Timeout Value for Receive and Transmit DMA Mask */
#define GMAC_LCKUP_CFGR_DMA_LOCKUP_TIME(value) (GMAC_LCKUP_CFGR_DMA_LOCKUP_TIME_Msk & (_UINT32_(value) << GMAC_LCKUP_CFGR_DMA_LOCKUP_TIME_Pos)) /* Assigment of value for DMA_LOCKUP_TIME in the GMAC_LCKUP_CFGR register */
#define GMAC_LCKUP_CFGR_LCKUP_REC_EN_Pos      _UINT32_(27)                                         /* (GMAC_LCKUP_CFGR) Lockup RecoveryEnable Position */
#define GMAC_LCKUP_CFGR_LCKUP_REC_EN_Msk      (_UINT32_(0x1) << GMAC_LCKUP_CFGR_LCKUP_REC_EN_Pos)  /* (GMAC_LCKUP_CFGR) Lockup RecoveryEnable Mask */
#define GMAC_LCKUP_CFGR_LCKUP_REC_EN(value)   (GMAC_LCKUP_CFGR_LCKUP_REC_EN_Msk & (_UINT32_(value) << GMAC_LCKUP_CFGR_LCKUP_REC_EN_Pos)) /* Assigment of value for LCKUP_REC_EN in the GMAC_LCKUP_CFGR register */
#define   GMAC_LCKUP_CFGR_LCKUP_REC_EN_0_Val  _UINT32_(0x0)                                        /* (GMAC_LCKUP_CFGR) No effect.  */
#define   GMAC_LCKUP_CFGR_LCKUP_REC_EN_1_Val  _UINT32_(0x1)                                        /* (GMAC_LCKUP_CFGR) Forces the MAC in Reset mode when a lockup.is detected on the transmit or receive data paths.  */
#define GMAC_LCKUP_CFGR_LCKUP_REC_EN_0        (GMAC_LCKUP_CFGR_LCKUP_REC_EN_0_Val << GMAC_LCKUP_CFGR_LCKUP_REC_EN_Pos) /* (GMAC_LCKUP_CFGR) No effect. Position  */
#define GMAC_LCKUP_CFGR_LCKUP_REC_EN_1        (GMAC_LCKUP_CFGR_LCKUP_REC_EN_1_Val << GMAC_LCKUP_CFGR_LCKUP_REC_EN_Pos) /* (GMAC_LCKUP_CFGR) Forces the MAC in Reset mode when a lockup.is detected on the transmit or receive data paths. Position  */
#define GMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_Pos    _UINT32_(28)                                         /* (GMAC_LCKUP_CFGR) Receive MAC Lockup Detector Enable Position */
#define GMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_Msk    (_UINT32_(0x1) << GMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_Pos) /* (GMAC_LCKUP_CFGR) Receive MAC Lockup Detector Enable Mask */
#define GMAC_LCKUP_CFGR_RXMAC_LCKUP_EN(value) (GMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_Msk & (_UINT32_(value) << GMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_Pos)) /* Assigment of value for RXMAC_LCKUP_EN in the GMAC_LCKUP_CFGR register */
#define   GMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_0_Val _UINT32_(0x0)                                        /* (GMAC_LCKUP_CFGR) Disables the monitor that detects lockups in the receive MAC.  */
#define   GMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_1_Val _UINT32_(0x1)                                        /* (GMAC_LCKUP_CFGR) Enables the monitor that detects lockups in the receive MAC.  */
#define GMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_0      (GMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_0_Val << GMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_Pos) /* (GMAC_LCKUP_CFGR) Disables the monitor that detects lockups in the receive MAC. Position  */
#define GMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_1      (GMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_1_Val << GMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_Pos) /* (GMAC_LCKUP_CFGR) Enables the monitor that detects lockups in the receive MAC. Position  */
#define GMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_Pos    _UINT32_(29)                                         /* (GMAC_LCKUP_CFGR) Receive DMA Lockup Detector Enable Position */
#define GMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_Msk    (_UINT32_(0x1) << GMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_Pos) /* (GMAC_LCKUP_CFGR) Receive DMA Lockup Detector Enable Mask */
#define GMAC_LCKUP_CFGR_RXDMA_LCKUP_EN(value) (GMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_Msk & (_UINT32_(value) << GMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_Pos)) /* Assigment of value for RXDMA_LCKUP_EN in the GMAC_LCKUP_CFGR register */
#define   GMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_0_Val _UINT32_(0x0)                                        /* (GMAC_LCKUP_CFGR) Disables the monitor that detects lockups in the receive DMA.  */
#define   GMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_1_Val _UINT32_(0x1)                                        /* (GMAC_LCKUP_CFGR) Enables the monitor that detects lockups in the receive DMA.  */
#define GMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_0      (GMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_0_Val << GMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_Pos) /* (GMAC_LCKUP_CFGR) Disables the monitor that detects lockups in the receive DMA. Position  */
#define GMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_1      (GMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_1_Val << GMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_Pos) /* (GMAC_LCKUP_CFGR) Enables the monitor that detects lockups in the receive DMA. Position  */
#define GMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_Pos    _UINT32_(30)                                         /* (GMAC_LCKUP_CFGR) Transmit MAC Lockup Detector Enable Position */
#define GMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_Msk    (_UINT32_(0x1) << GMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_Pos) /* (GMAC_LCKUP_CFGR) Transmit MAC Lockup Detector Enable Mask */
#define GMAC_LCKUP_CFGR_TXMAC_LCKUP_EN(value) (GMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_Msk & (_UINT32_(value) << GMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_Pos)) /* Assigment of value for TXMAC_LCKUP_EN in the GMAC_LCKUP_CFGR register */
#define   GMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_0_Val _UINT32_(0x0)                                        /* (GMAC_LCKUP_CFGR) Disables the monitor that detects lockups in the transmit MAC.  */
#define   GMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_1_Val _UINT32_(0x1)                                        /* (GMAC_LCKUP_CFGR) Enables the monitor that detects lockups in the transmit MAC.  */
#define GMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_0      (GMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_0_Val << GMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_Pos) /* (GMAC_LCKUP_CFGR) Disables the monitor that detects lockups in the transmit MAC. Position  */
#define GMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_1      (GMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_1_Val << GMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_Pos) /* (GMAC_LCKUP_CFGR) Enables the monitor that detects lockups in the transmit MAC. Position  */
#define GMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_Pos    _UINT32_(31)                                         /* (GMAC_LCKUP_CFGR) Transmit DMA Lockup Detector Enable Position */
#define GMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_Msk    (_UINT32_(0x1) << GMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_Pos) /* (GMAC_LCKUP_CFGR) Transmit DMA Lockup Detector Enable Mask */
#define GMAC_LCKUP_CFGR_TXDMA_LCKUP_EN(value) (GMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_Msk & (_UINT32_(value) << GMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_Pos)) /* Assigment of value for TXDMA_LCKUP_EN in the GMAC_LCKUP_CFGR register */
#define   GMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_0_Val _UINT32_(0x0)                                        /* (GMAC_LCKUP_CFGR) Disables the monitor that detects lockups in the transmit DMA.  */
#define   GMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_1_Val _UINT32_(0x1)                                        /* (GMAC_LCKUP_CFGR) Enables the monitor that detects lockups in the transmit DMA.  */
#define GMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_0      (GMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_0_Val << GMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_Pos) /* (GMAC_LCKUP_CFGR) Disables the monitor that detects lockups in the transmit DMA. Position  */
#define GMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_1      (GMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_1_Val << GMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_Pos) /* (GMAC_LCKUP_CFGR) Enables the monitor that detects lockups in the transmit DMA. Position  */
#define GMAC_LCKUP_CFGR_Msk                   _UINT32_(0xFFFFFFFF)                                 /* (GMAC_LCKUP_CFGR) Register Mask  */


/* -------- GMAC_LCKUP_TIME : (GMAC Offset: 0x6C) (R/W 32) MAC Lockup Detection Time register -------- */
#define GMAC_LCKUP_TIME_RESETVALUE            _UINT32_(0x7FFFFFF)                                  /*  (GMAC_LCKUP_TIME) MAC Lockup Detection Time register  Reset Value */

#define GMAC_LCKUP_TIME_RX_MAC_LOCKUP_TIME_Pos _UINT32_(0)                                          /* (GMAC_LCKUP_TIME) Receive MAC Lockup Detector Time Position */
#define GMAC_LCKUP_TIME_RX_MAC_LOCKUP_TIME_Msk (_UINT32_(0xFFFF) << GMAC_LCKUP_TIME_RX_MAC_LOCKUP_TIME_Pos) /* (GMAC_LCKUP_TIME) Receive MAC Lockup Detector Time Mask */
#define GMAC_LCKUP_TIME_RX_MAC_LOCKUP_TIME(value) (GMAC_LCKUP_TIME_RX_MAC_LOCKUP_TIME_Msk & (_UINT32_(value) << GMAC_LCKUP_TIME_RX_MAC_LOCKUP_TIME_Pos)) /* Assigment of value for RX_MAC_LOCKUP_TIME in the GMAC_LCKUP_TIME register */
#define GMAC_LCKUP_TIME_TX_MAC_LOCKUP_TIME_Pos _UINT32_(16)                                         /* (GMAC_LCKUP_TIME) Transmit MAC Lockup Detector Time Position */
#define GMAC_LCKUP_TIME_TX_MAC_LOCKUP_TIME_Msk (_UINT32_(0x7FF) << GMAC_LCKUP_TIME_TX_MAC_LOCKUP_TIME_Pos) /* (GMAC_LCKUP_TIME) Transmit MAC Lockup Detector Time Mask */
#define GMAC_LCKUP_TIME_TX_MAC_LOCKUP_TIME(value) (GMAC_LCKUP_TIME_TX_MAC_LOCKUP_TIME_Msk & (_UINT32_(value) << GMAC_LCKUP_TIME_TX_MAC_LOCKUP_TIME_Pos)) /* Assigment of value for TX_MAC_LOCKUP_TIME in the GMAC_LCKUP_TIME register */
#define GMAC_LCKUP_TIME_Msk                   _UINT32_(0x07FFFFFF)                                 /* (GMAC_LCKUP_TIME) Register Mask  */


/* -------- GMAC_TXDMA_LCKUP_CR : (GMAC Offset: 0x70) (R/W 32) Transmit DMA Lockup Control Register -------- */
#define GMAC_TXDMA_LCKUP_CR_RESETVALUE        _UINT32_(0x00)                                       /*  (GMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Control Register  Reset Value */

#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_Pos   _UINT32_(0)                                          /* (GMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Detector Enable for Queue 0 Position */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_Msk   (_UINT32_(0x1) << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_Pos) /* (GMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Detector Enable for Queue 0 Mask */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0(value) (GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_Msk & (_UINT32_(value) << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_Pos)) /* Assigment of value for LCKUP_EN_Q0 in the GMAC_TXDMA_LCKUP_CR register */
#define   GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_0_Val _UINT32_(0x0)                                        /* (GMAC_TXDMA_LCKUP_CR) Disables the transmit DMA lockup timer for queue x. The number of outstanding packets are still counted but the actual timer does not run.  */
#define   GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_1_Val _UINT32_(0x1)                                        /* (GMAC_TXDMA_LCKUP_CR) Enables the transmit DMA lockup timer for queue x.  */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_0     (GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_0_Val << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_Pos) /* (GMAC_TXDMA_LCKUP_CR) Disables the transmit DMA lockup timer for queue x. The number of outstanding packets are still counted but the actual timer does not run. Position  */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_1     (GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_1_Val << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_Pos) /* (GMAC_TXDMA_LCKUP_CR) Enables the transmit DMA lockup timer for queue x. Position  */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_Pos   _UINT32_(1)                                          /* (GMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Detector Enable for Queue 1 Position */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_Msk   (_UINT32_(0x1) << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_Pos) /* (GMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Detector Enable for Queue 1 Mask */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1(value) (GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_Msk & (_UINT32_(value) << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_Pos)) /* Assigment of value for LCKUP_EN_Q1 in the GMAC_TXDMA_LCKUP_CR register */
#define   GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_0_Val _UINT32_(0x0)                                        /* (GMAC_TXDMA_LCKUP_CR) Disables the transmit DMA lockup timer for queue x. The number of outstanding packets are still counted but the actual timer does not run.  */
#define   GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_1_Val _UINT32_(0x1)                                        /* (GMAC_TXDMA_LCKUP_CR) Enables the transmit DMA lockup timer for queue x.  */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_0     (GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_0_Val << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_Pos) /* (GMAC_TXDMA_LCKUP_CR) Disables the transmit DMA lockup timer for queue x. The number of outstanding packets are still counted but the actual timer does not run. Position  */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_1     (GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_1_Val << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_Pos) /* (GMAC_TXDMA_LCKUP_CR) Enables the transmit DMA lockup timer for queue x. Position  */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_Pos   _UINT32_(2)                                          /* (GMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Detector Enable for Queue 2 Position */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_Msk   (_UINT32_(0x1) << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_Pos) /* (GMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Detector Enable for Queue 2 Mask */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2(value) (GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_Msk & (_UINT32_(value) << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_Pos)) /* Assigment of value for LCKUP_EN_Q2 in the GMAC_TXDMA_LCKUP_CR register */
#define   GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_0_Val _UINT32_(0x0)                                        /* (GMAC_TXDMA_LCKUP_CR) Disables the transmit DMA lockup timer for queue x. The number of outstanding packets are still counted but the actual timer does not run.  */
#define   GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_1_Val _UINT32_(0x1)                                        /* (GMAC_TXDMA_LCKUP_CR) Enables the transmit DMA lockup timer for queue x.  */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_0     (GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_0_Val << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_Pos) /* (GMAC_TXDMA_LCKUP_CR) Disables the transmit DMA lockup timer for queue x. The number of outstanding packets are still counted but the actual timer does not run. Position  */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_1     (GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_1_Val << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_Pos) /* (GMAC_TXDMA_LCKUP_CR) Enables the transmit DMA lockup timer for queue x. Position  */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_Pos   _UINT32_(3)                                          /* (GMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Detector Enable for Queue 3 Position */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_Msk   (_UINT32_(0x1) << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_Pos) /* (GMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Detector Enable for Queue 3 Mask */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3(value) (GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_Msk & (_UINT32_(value) << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_Pos)) /* Assigment of value for LCKUP_EN_Q3 in the GMAC_TXDMA_LCKUP_CR register */
#define   GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_0_Val _UINT32_(0x0)                                        /* (GMAC_TXDMA_LCKUP_CR) Disables the transmit DMA lockup timer for queue x. The number of outstanding packets are still counted but the actual timer does not run.  */
#define   GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_1_Val _UINT32_(0x1)                                        /* (GMAC_TXDMA_LCKUP_CR) Enables the transmit DMA lockup timer for queue x.  */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_0     (GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_0_Val << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_Pos) /* (GMAC_TXDMA_LCKUP_CR) Disables the transmit DMA lockup timer for queue x. The number of outstanding packets are still counted but the actual timer does not run. Position  */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_1     (GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_1_Val << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_Pos) /* (GMAC_TXDMA_LCKUP_CR) Enables the transmit DMA lockup timer for queue x. Position  */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_Pos   _UINT32_(4)                                          /* (GMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Detector Enable for Queue 4 Position */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_Msk   (_UINT32_(0x1) << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_Pos) /* (GMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Detector Enable for Queue 4 Mask */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4(value) (GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_Msk & (_UINT32_(value) << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_Pos)) /* Assigment of value for LCKUP_EN_Q4 in the GMAC_TXDMA_LCKUP_CR register */
#define   GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_0_Val _UINT32_(0x0)                                        /* (GMAC_TXDMA_LCKUP_CR) Disables the transmit DMA lockup timer for queue x. The number of outstanding packets are still counted but the actual timer does not run.  */
#define   GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_1_Val _UINT32_(0x1)                                        /* (GMAC_TXDMA_LCKUP_CR) Enables the transmit DMA lockup timer for queue x.  */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_0     (GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_0_Val << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_Pos) /* (GMAC_TXDMA_LCKUP_CR) Disables the transmit DMA lockup timer for queue x. The number of outstanding packets are still counted but the actual timer does not run. Position  */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_1     (GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_1_Val << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_Pos) /* (GMAC_TXDMA_LCKUP_CR) Enables the transmit DMA lockup timer for queue x. Position  */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_Pos   _UINT32_(5)                                          /* (GMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Detector Enable for Queue 5 Position */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_Msk   (_UINT32_(0x1) << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_Pos) /* (GMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Detector Enable for Queue 5 Mask */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5(value) (GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_Msk & (_UINT32_(value) << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_Pos)) /* Assigment of value for LCKUP_EN_Q5 in the GMAC_TXDMA_LCKUP_CR register */
#define   GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_0_Val _UINT32_(0x0)                                        /* (GMAC_TXDMA_LCKUP_CR) Disables the transmit DMA lockup timer for queue x. The number of outstanding packets are still counted but the actual timer does not run.  */
#define   GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_1_Val _UINT32_(0x1)                                        /* (GMAC_TXDMA_LCKUP_CR) Enables the transmit DMA lockup timer for queue x.  */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_0     (GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_0_Val << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_Pos) /* (GMAC_TXDMA_LCKUP_CR) Disables the transmit DMA lockup timer for queue x. The number of outstanding packets are still counted but the actual timer does not run. Position  */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_1     (GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_1_Val << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_Pos) /* (GMAC_TXDMA_LCKUP_CR) Enables the transmit DMA lockup timer for queue x. Position  */
#define GMAC_TXDMA_LCKUP_CR_Msk               _UINT32_(0x0000003F)                                 /* (GMAC_TXDMA_LCKUP_CR) Register Mask  */

#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q_Pos    _UINT32_(0)                                          /* (GMAC_TXDMA_LCKUP_CR Position) Transmit DMA Lockup Detector Enable for Queue 5 */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q_Msk    (_UINT32_(0x3F) << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q_Pos) /* (GMAC_TXDMA_LCKUP_CR Mask) LCKUP_EN_Q */
#define GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q(value) (GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q_Msk & (_UINT32_(value) << GMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q_Pos)) 

/* -------- GMAC_RX_WATERMARK : (GMAC Offset: 0x7C) (R/W 32) Receive Watermark Register -------- */
#define GMAC_RX_WATERMARK_RESETVALUE          _UINT32_(0x00)                                       /*  (GMAC_RX_WATERMARK) Receive Watermark Register  Reset Value */

#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK0_Pos _UINT32_(0)                                          /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 0 Position */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK0_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK0_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 0 Mask */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK0(value) (GMAC_RX_WATERMARK_RX_HIGH_WATERMARK0_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK0_Pos)) /* Assigment of value for RX_HIGH_WATERMARK0 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK1_Pos _UINT32_(1)                                          /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 1 Position */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK1_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK1_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 1 Mask */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK1(value) (GMAC_RX_WATERMARK_RX_HIGH_WATERMARK1_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK1_Pos)) /* Assigment of value for RX_HIGH_WATERMARK1 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK2_Pos _UINT32_(2)                                          /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 2 Position */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK2_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK2_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 2 Mask */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK2(value) (GMAC_RX_WATERMARK_RX_HIGH_WATERMARK2_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK2_Pos)) /* Assigment of value for RX_HIGH_WATERMARK2 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK3_Pos _UINT32_(3)                                          /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 3 Position */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK3_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK3_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 3 Mask */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK3(value) (GMAC_RX_WATERMARK_RX_HIGH_WATERMARK3_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK3_Pos)) /* Assigment of value for RX_HIGH_WATERMARK3 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK4_Pos _UINT32_(4)                                          /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 4 Position */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK4_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK4_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 4 Mask */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK4(value) (GMAC_RX_WATERMARK_RX_HIGH_WATERMARK4_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK4_Pos)) /* Assigment of value for RX_HIGH_WATERMARK4 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK5_Pos _UINT32_(5)                                          /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 5 Position */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK5_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK5_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 5 Mask */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK5(value) (GMAC_RX_WATERMARK_RX_HIGH_WATERMARK5_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK5_Pos)) /* Assigment of value for RX_HIGH_WATERMARK5 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK6_Pos _UINT32_(6)                                          /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 6 Position */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK6_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK6_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 6 Mask */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK6(value) (GMAC_RX_WATERMARK_RX_HIGH_WATERMARK6_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK6_Pos)) /* Assigment of value for RX_HIGH_WATERMARK6 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK7_Pos _UINT32_(7)                                          /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 7 Position */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK7_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK7_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 7 Mask */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK7(value) (GMAC_RX_WATERMARK_RX_HIGH_WATERMARK7_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK7_Pos)) /* Assigment of value for RX_HIGH_WATERMARK7 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK8_Pos _UINT32_(8)                                          /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 8 Position */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK8_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK8_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 8 Mask */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK8(value) (GMAC_RX_WATERMARK_RX_HIGH_WATERMARK8_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK8_Pos)) /* Assigment of value for RX_HIGH_WATERMARK8 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK9_Pos _UINT32_(9)                                          /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 9 Position */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK9_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK9_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 9 Mask */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK9(value) (GMAC_RX_WATERMARK_RX_HIGH_WATERMARK9_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK9_Pos)) /* Assigment of value for RX_HIGH_WATERMARK9 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK10_Pos _UINT32_(10)                                         /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 10 Position */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK10_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK10_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 10 Mask */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK10(value) (GMAC_RX_WATERMARK_RX_HIGH_WATERMARK10_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK10_Pos)) /* Assigment of value for RX_HIGH_WATERMARK10 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK11_Pos _UINT32_(11)                                         /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 11 Position */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK11_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK11_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 11 Mask */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK11(value) (GMAC_RX_WATERMARK_RX_HIGH_WATERMARK11_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK11_Pos)) /* Assigment of value for RX_HIGH_WATERMARK11 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK12_Pos _UINT32_(12)                                         /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 12 Position */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK12_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK12_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 12 Mask */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK12(value) (GMAC_RX_WATERMARK_RX_HIGH_WATERMARK12_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK12_Pos)) /* Assigment of value for RX_HIGH_WATERMARK12 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK13_Pos _UINT32_(13)                                         /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 13 Position */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK13_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK13_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 13 Mask */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK13(value) (GMAC_RX_WATERMARK_RX_HIGH_WATERMARK13_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK13_Pos)) /* Assigment of value for RX_HIGH_WATERMARK13 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK14_Pos _UINT32_(14)                                         /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 14 Position */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK14_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK14_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 14 Mask */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK14(value) (GMAC_RX_WATERMARK_RX_HIGH_WATERMARK14_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK14_Pos)) /* Assigment of value for RX_HIGH_WATERMARK14 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK15_Pos _UINT32_(15)                                         /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 15 Position */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK15_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK15_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 15 Mask */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK15(value) (GMAC_RX_WATERMARK_RX_HIGH_WATERMARK15_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK15_Pos)) /* Assigment of value for RX_HIGH_WATERMARK15 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK0_Pos _UINT32_(16)                                         /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 0 Position */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK0_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK0_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 0 Mask */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK0(value) (GMAC_RX_WATERMARK_RX_LOW_WATERMARK0_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK0_Pos)) /* Assigment of value for RX_LOW_WATERMARK0 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK1_Pos _UINT32_(17)                                         /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 1 Position */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK1_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK1_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 1 Mask */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK1(value) (GMAC_RX_WATERMARK_RX_LOW_WATERMARK1_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK1_Pos)) /* Assigment of value for RX_LOW_WATERMARK1 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK2_Pos _UINT32_(18)                                         /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 2 Position */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK2_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK2_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 2 Mask */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK2(value) (GMAC_RX_WATERMARK_RX_LOW_WATERMARK2_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK2_Pos)) /* Assigment of value for RX_LOW_WATERMARK2 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK3_Pos _UINT32_(19)                                         /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 3 Position */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK3_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK3_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 3 Mask */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK3(value) (GMAC_RX_WATERMARK_RX_LOW_WATERMARK3_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK3_Pos)) /* Assigment of value for RX_LOW_WATERMARK3 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK4_Pos _UINT32_(20)                                         /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 4 Position */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK4_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK4_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 4 Mask */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK4(value) (GMAC_RX_WATERMARK_RX_LOW_WATERMARK4_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK4_Pos)) /* Assigment of value for RX_LOW_WATERMARK4 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK5_Pos _UINT32_(21)                                         /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 5 Position */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK5_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK5_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 5 Mask */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK5(value) (GMAC_RX_WATERMARK_RX_LOW_WATERMARK5_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK5_Pos)) /* Assigment of value for RX_LOW_WATERMARK5 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK6_Pos _UINT32_(22)                                         /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 6 Position */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK6_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK6_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 6 Mask */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK6(value) (GMAC_RX_WATERMARK_RX_LOW_WATERMARK6_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK6_Pos)) /* Assigment of value for RX_LOW_WATERMARK6 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK7_Pos _UINT32_(23)                                         /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 7 Position */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK7_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK7_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 7 Mask */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK7(value) (GMAC_RX_WATERMARK_RX_LOW_WATERMARK7_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK7_Pos)) /* Assigment of value for RX_LOW_WATERMARK7 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK8_Pos _UINT32_(24)                                         /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 8 Position */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK8_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK8_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 8 Mask */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK8(value) (GMAC_RX_WATERMARK_RX_LOW_WATERMARK8_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK8_Pos)) /* Assigment of value for RX_LOW_WATERMARK8 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK9_Pos _UINT32_(25)                                         /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 9 Position */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK9_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK9_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 9 Mask */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK9(value) (GMAC_RX_WATERMARK_RX_LOW_WATERMARK9_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK9_Pos)) /* Assigment of value for RX_LOW_WATERMARK9 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK10_Pos _UINT32_(26)                                         /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 10 Position */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK10_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK10_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 10 Mask */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK10(value) (GMAC_RX_WATERMARK_RX_LOW_WATERMARK10_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK10_Pos)) /* Assigment of value for RX_LOW_WATERMARK10 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK11_Pos _UINT32_(27)                                         /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 11 Position */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK11_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK11_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 11 Mask */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK11(value) (GMAC_RX_WATERMARK_RX_LOW_WATERMARK11_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK11_Pos)) /* Assigment of value for RX_LOW_WATERMARK11 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK12_Pos _UINT32_(28)                                         /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 12 Position */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK12_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK12_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 12 Mask */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK12(value) (GMAC_RX_WATERMARK_RX_LOW_WATERMARK12_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK12_Pos)) /* Assigment of value for RX_LOW_WATERMARK12 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK13_Pos _UINT32_(29)                                         /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 13 Position */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK13_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK13_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 13 Mask */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK13(value) (GMAC_RX_WATERMARK_RX_LOW_WATERMARK13_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK13_Pos)) /* Assigment of value for RX_LOW_WATERMARK13 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK14_Pos _UINT32_(30)                                         /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 14 Position */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK14_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK14_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 14 Mask */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK14(value) (GMAC_RX_WATERMARK_RX_LOW_WATERMARK14_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK14_Pos)) /* Assigment of value for RX_LOW_WATERMARK14 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK15_Pos _UINT32_(31)                                         /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 15 Position */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK15_Msk (_UINT32_(0x1) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK15_Pos) /* (GMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 15 Mask */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK15(value) (GMAC_RX_WATERMARK_RX_LOW_WATERMARK15_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK15_Pos)) /* Assigment of value for RX_LOW_WATERMARK15 in the GMAC_RX_WATERMARK register */
#define GMAC_RX_WATERMARK_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (GMAC_RX_WATERMARK) Register Mask  */

#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK_Pos _UINT32_(0)                                          /* (GMAC_RX_WATERMARK Position) Transmit DMA Lockup Detector Enable for Queue x */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK_Msk (_UINT32_(0xFFFF) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK_Pos) /* (GMAC_RX_WATERMARK Mask) RX_HIGH_WATERMARK */
#define GMAC_RX_WATERMARK_RX_HIGH_WATERMARK(value) (GMAC_RX_WATERMARK_RX_HIGH_WATERMARK_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_HIGH_WATERMARK_Pos)) 
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK_Pos _UINT32_(16)                                         /* (GMAC_RX_WATERMARK Position) Transmit DMA Lockup Detector Enable for Queue x5 */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK_Msk (_UINT32_(0xFFFF) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK_Pos) /* (GMAC_RX_WATERMARK Mask) RX_LOW_WATERMARK */
#define GMAC_RX_WATERMARK_RX_LOW_WATERMARK(value) (GMAC_RX_WATERMARK_RX_LOW_WATERMARK_Msk & (_UINT32_(value) << GMAC_RX_WATERMARK_RX_LOW_WATERMARK_Pos)) 

/* -------- GMAC_HRB : (GMAC Offset: 0x80) (R/W 32) Hash Register Bottom -------- */
#define GMAC_HRB_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_HRB) Hash Register Bottom  Reset Value */

#define GMAC_HRB_ADDR_Pos                     _UINT32_(0)                                          /* (GMAC_HRB) Hash Address Position */
#define GMAC_HRB_ADDR_Msk                     (_UINT32_(0xFFFFFFFF) << GMAC_HRB_ADDR_Pos)          /* (GMAC_HRB) Hash Address Mask */
#define GMAC_HRB_ADDR(value)                  (GMAC_HRB_ADDR_Msk & (_UINT32_(value) << GMAC_HRB_ADDR_Pos)) /* Assigment of value for ADDR in the GMAC_HRB register */
#define GMAC_HRB_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (GMAC_HRB) Register Mask  */


/* -------- GMAC_HRT : (GMAC Offset: 0x84) (R/W 32) Hash Register Top -------- */
#define GMAC_HRT_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_HRT) Hash Register Top  Reset Value */

#define GMAC_HRT_ADDR_Pos                     _UINT32_(0)                                          /* (GMAC_HRT) Hash Address Position */
#define GMAC_HRT_ADDR_Msk                     (_UINT32_(0xFFFFFFFF) << GMAC_HRT_ADDR_Pos)          /* (GMAC_HRT) Hash Address Mask */
#define GMAC_HRT_ADDR(value)                  (GMAC_HRT_ADDR_Msk & (_UINT32_(value) << GMAC_HRT_ADDR_Pos)) /* Assigment of value for ADDR in the GMAC_HRT register */
#define GMAC_HRT_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (GMAC_HRT) Register Mask  */


/* -------- GMAC_SAB1 : (GMAC Offset: 0x88) (R/W 32) Specific Address 1 Bottom Register -------- */
#define GMAC_SAB1_RESETVALUE                  _UINT32_(0x00)                                       /*  (GMAC_SAB1) Specific Address 1 Bottom Register  Reset Value */

#define GMAC_SAB1_ADDR_Pos                    _UINT32_(0)                                          /* (GMAC_SAB1) Specific Address 1 Position */
#define GMAC_SAB1_ADDR_Msk                    (_UINT32_(0xFFFFFFFF) << GMAC_SAB1_ADDR_Pos)         /* (GMAC_SAB1) Specific Address 1 Mask */
#define GMAC_SAB1_ADDR(value)                 (GMAC_SAB1_ADDR_Msk & (_UINT32_(value) << GMAC_SAB1_ADDR_Pos)) /* Assigment of value for ADDR in the GMAC_SAB1 register */
#define GMAC_SAB1_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (GMAC_SAB1) Register Mask  */


/* -------- GMAC_SAT1 : (GMAC Offset: 0x8C) (R/W 32) Specific Address 1 Top Register -------- */
#define GMAC_SAT1_RESETVALUE                  _UINT32_(0x00)                                       /*  (GMAC_SAT1) Specific Address 1 Top Register  Reset Value */

#define GMAC_SAT1_ADDR_Pos                    _UINT32_(0)                                          /* (GMAC_SAT1) Specific Address 1 Position */
#define GMAC_SAT1_ADDR_Msk                    (_UINT32_(0xFFFF) << GMAC_SAT1_ADDR_Pos)             /* (GMAC_SAT1) Specific Address 1 Mask */
#define GMAC_SAT1_ADDR(value)                 (GMAC_SAT1_ADDR_Msk & (_UINT32_(value) << GMAC_SAT1_ADDR_Pos)) /* Assigment of value for ADDR in the GMAC_SAT1 register */
#define GMAC_SAT1_FILTSORD_Pos                _UINT32_(16)                                         /* (GMAC_SAT1) Filter Source or Destination MAC Address Position */
#define GMAC_SAT1_FILTSORD_Msk                (_UINT32_(0x1) << GMAC_SAT1_FILTSORD_Pos)            /* (GMAC_SAT1) Filter Source or Destination MAC Address Mask */
#define GMAC_SAT1_FILTSORD(value)             (GMAC_SAT1_FILTSORD_Msk & (_UINT32_(value) << GMAC_SAT1_FILTSORD_Pos)) /* Assigment of value for FILTSORD in the GMAC_SAT1 register */
#define   GMAC_SAT1_FILTSORD_0_Val            _UINT32_(0x0)                                        /* (GMAC_SAT1) The filter is a destination address filter.  */
#define   GMAC_SAT1_FILTSORD_1_Val            _UINT32_(0x1)                                        /* (GMAC_SAT1) The filter is a source address filter.  */
#define GMAC_SAT1_FILTSORD_0                  (GMAC_SAT1_FILTSORD_0_Val << GMAC_SAT1_FILTSORD_Pos) /* (GMAC_SAT1) The filter is a destination address filter. Position  */
#define GMAC_SAT1_FILTSORD_1                  (GMAC_SAT1_FILTSORD_1_Val << GMAC_SAT1_FILTSORD_Pos) /* (GMAC_SAT1) The filter is a source address filter. Position  */
#define GMAC_SAT1_Msk                         _UINT32_(0x0001FFFF)                                 /* (GMAC_SAT1) Register Mask  */


/* -------- GMAC_SAB2 : (GMAC Offset: 0x90) (R/W 32) Specific Address 2 Bottom Register -------- */
#define GMAC_SAB2_RESETVALUE                  _UINT32_(0x00)                                       /*  (GMAC_SAB2) Specific Address 2 Bottom Register  Reset Value */

#define GMAC_SAB2_ADDR_Pos                    _UINT32_(0)                                          /* (GMAC_SAB2) Specific Address 2 Position */
#define GMAC_SAB2_ADDR_Msk                    (_UINT32_(0xFFFFFFFF) << GMAC_SAB2_ADDR_Pos)         /* (GMAC_SAB2) Specific Address 2 Mask */
#define GMAC_SAB2_ADDR(value)                 (GMAC_SAB2_ADDR_Msk & (_UINT32_(value) << GMAC_SAB2_ADDR_Pos)) /* Assigment of value for ADDR in the GMAC_SAB2 register */
#define GMAC_SAB2_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (GMAC_SAB2) Register Mask  */


/* -------- GMAC_SAT2 : (GMAC Offset: 0x94) (R/W 32) Specific Address 2 Top Register -------- */
#define GMAC_SAT2_RESETVALUE                  _UINT32_(0x00)                                       /*  (GMAC_SAT2) Specific Address 2 Top Register  Reset Value */

#define GMAC_SAT2_ADDR_Pos                    _UINT32_(0)                                          /* (GMAC_SAT2) Specific Address 2 Position */
#define GMAC_SAT2_ADDR_Msk                    (_UINT32_(0xFFFF) << GMAC_SAT2_ADDR_Pos)             /* (GMAC_SAT2) Specific Address 2 Mask */
#define GMAC_SAT2_ADDR(value)                 (GMAC_SAT2_ADDR_Msk & (_UINT32_(value) << GMAC_SAT2_ADDR_Pos)) /* Assigment of value for ADDR in the GMAC_SAT2 register */
#define GMAC_SAT2_FILTSORD_Pos                _UINT32_(16)                                         /* (GMAC_SAT2) Filter Source or Destination MAC Address Position */
#define GMAC_SAT2_FILTSORD_Msk                (_UINT32_(0x1) << GMAC_SAT2_FILTSORD_Pos)            /* (GMAC_SAT2) Filter Source or Destination MAC Address Mask */
#define GMAC_SAT2_FILTSORD(value)             (GMAC_SAT2_FILTSORD_Msk & (_UINT32_(value) << GMAC_SAT2_FILTSORD_Pos)) /* Assigment of value for FILTSORD in the GMAC_SAT2 register */
#define   GMAC_SAT2_FILTSORD_0_Val            _UINT32_(0x0)                                        /* (GMAC_SAT2) The filter is a destination address filter.  */
#define   GMAC_SAT2_FILTSORD_1_Val            _UINT32_(0x1)                                        /* (GMAC_SAT2) The filter is a source address filter.  */
#define GMAC_SAT2_FILTSORD_0                  (GMAC_SAT2_FILTSORD_0_Val << GMAC_SAT2_FILTSORD_Pos) /* (GMAC_SAT2) The filter is a destination address filter. Position  */
#define GMAC_SAT2_FILTSORD_1                  (GMAC_SAT2_FILTSORD_1_Val << GMAC_SAT2_FILTSORD_Pos) /* (GMAC_SAT2) The filter is a source address filter. Position  */
#define GMAC_SAT2_FILTBMASK_Pos               _UINT32_(24)                                         /* (GMAC_SAT2) Filter Bytes Mask Position */
#define GMAC_SAT2_FILTBMASK_Msk               (_UINT32_(0x3F) << GMAC_SAT2_FILTBMASK_Pos)          /* (GMAC_SAT2) Filter Bytes Mask Mask */
#define GMAC_SAT2_FILTBMASK(value)            (GMAC_SAT2_FILTBMASK_Msk & (_UINT32_(value) << GMAC_SAT2_FILTBMASK_Pos)) /* Assigment of value for FILTBMASK in the GMAC_SAT2 register */
#define   GMAC_SAT2_FILTBMASK_BIT1_Val        _UINT32_(0x1)                                        /* (GMAC_SAT2) Controls whether the first byte has been received.  */
#define   GMAC_SAT2_FILTBMASK_BIT2_Val        _UINT32_(0x2)                                        /* (GMAC_SAT2) Controls whether the second byte has been received.  */
#define   GMAC_SAT2_FILTBMASK_BIT3_Val        _UINT32_(0x4)                                        /* (GMAC_SAT2) Controls whether the third byte has been received.  */
#define   GMAC_SAT2_FILTBMASK_BIT4_Val        _UINT32_(0x8)                                        /* (GMAC_SAT2) Controls whether the fourth byte has been received.  */
#define   GMAC_SAT2_FILTBMASK_BIT5_Val        _UINT32_(0x10)                                       /* (GMAC_SAT2) Controls whether the fifth byte has been received.  */
#define   GMAC_SAT2_FILTBMASK_BIT6_Val        _UINT32_(0x20)                                       /* (GMAC_SAT2) Controls whether the sixth byte has been received  */
#define GMAC_SAT2_FILTBMASK_BIT1              (GMAC_SAT2_FILTBMASK_BIT1_Val << GMAC_SAT2_FILTBMASK_Pos) /* (GMAC_SAT2) Controls whether the first byte has been received. Position  */
#define GMAC_SAT2_FILTBMASK_BIT2              (GMAC_SAT2_FILTBMASK_BIT2_Val << GMAC_SAT2_FILTBMASK_Pos) /* (GMAC_SAT2) Controls whether the second byte has been received. Position  */
#define GMAC_SAT2_FILTBMASK_BIT3              (GMAC_SAT2_FILTBMASK_BIT3_Val << GMAC_SAT2_FILTBMASK_Pos) /* (GMAC_SAT2) Controls whether the third byte has been received. Position  */
#define GMAC_SAT2_FILTBMASK_BIT4              (GMAC_SAT2_FILTBMASK_BIT4_Val << GMAC_SAT2_FILTBMASK_Pos) /* (GMAC_SAT2) Controls whether the fourth byte has been received. Position  */
#define GMAC_SAT2_FILTBMASK_BIT5              (GMAC_SAT2_FILTBMASK_BIT5_Val << GMAC_SAT2_FILTBMASK_Pos) /* (GMAC_SAT2) Controls whether the fifth byte has been received. Position  */
#define GMAC_SAT2_FILTBMASK_BIT6              (GMAC_SAT2_FILTBMASK_BIT6_Val << GMAC_SAT2_FILTBMASK_Pos) /* (GMAC_SAT2) Controls whether the sixth byte has been received Position  */
#define GMAC_SAT2_Msk                         _UINT32_(0x3F01FFFF)                                 /* (GMAC_SAT2) Register Mask  */


/* -------- GMAC_SAB3 : (GMAC Offset: 0x98) (R/W 32) Specific Address 3 Bottom Register -------- */
#define GMAC_SAB3_RESETVALUE                  _UINT32_(0x00)                                       /*  (GMAC_SAB3) Specific Address 3 Bottom Register  Reset Value */

#define GMAC_SAB3_ADDR_Pos                    _UINT32_(0)                                          /* (GMAC_SAB3) Specific Address 3 Position */
#define GMAC_SAB3_ADDR_Msk                    (_UINT32_(0xFFFFFFFF) << GMAC_SAB3_ADDR_Pos)         /* (GMAC_SAB3) Specific Address 3 Mask */
#define GMAC_SAB3_ADDR(value)                 (GMAC_SAB3_ADDR_Msk & (_UINT32_(value) << GMAC_SAB3_ADDR_Pos)) /* Assigment of value for ADDR in the GMAC_SAB3 register */
#define GMAC_SAB3_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (GMAC_SAB3) Register Mask  */


/* -------- GMAC_SAT3 : (GMAC Offset: 0x9C) (R/W 32) Specific Address 3 Top Register -------- */
#define GMAC_SAT3_RESETVALUE                  _UINT32_(0x00)                                       /*  (GMAC_SAT3) Specific Address 3 Top Register  Reset Value */

#define GMAC_SAT3_ADDR_Pos                    _UINT32_(0)                                          /* (GMAC_SAT3) Specific Address 3 Position */
#define GMAC_SAT3_ADDR_Msk                    (_UINT32_(0xFFFF) << GMAC_SAT3_ADDR_Pos)             /* (GMAC_SAT3) Specific Address 3 Mask */
#define GMAC_SAT3_ADDR(value)                 (GMAC_SAT3_ADDR_Msk & (_UINT32_(value) << GMAC_SAT3_ADDR_Pos)) /* Assigment of value for ADDR in the GMAC_SAT3 register */
#define GMAC_SAT3_FILTSORD_Pos                _UINT32_(16)                                         /* (GMAC_SAT3) Filter Source or Destination MAC Address Position */
#define GMAC_SAT3_FILTSORD_Msk                (_UINT32_(0x1) << GMAC_SAT3_FILTSORD_Pos)            /* (GMAC_SAT3) Filter Source or Destination MAC Address Mask */
#define GMAC_SAT3_FILTSORD(value)             (GMAC_SAT3_FILTSORD_Msk & (_UINT32_(value) << GMAC_SAT3_FILTSORD_Pos)) /* Assigment of value for FILTSORD in the GMAC_SAT3 register */
#define   GMAC_SAT3_FILTSORD_0_Val            _UINT32_(0x0)                                        /* (GMAC_SAT3) The filter is a destination address filter.  */
#define   GMAC_SAT3_FILTSORD_1_Val            _UINT32_(0x1)                                        /* (GMAC_SAT3) The filter is a source address filter.  */
#define GMAC_SAT3_FILTSORD_0                  (GMAC_SAT3_FILTSORD_0_Val << GMAC_SAT3_FILTSORD_Pos) /* (GMAC_SAT3) The filter is a destination address filter. Position  */
#define GMAC_SAT3_FILTSORD_1                  (GMAC_SAT3_FILTSORD_1_Val << GMAC_SAT3_FILTSORD_Pos) /* (GMAC_SAT3) The filter is a source address filter. Position  */
#define GMAC_SAT3_FILTBMASK_Pos               _UINT32_(24)                                         /* (GMAC_SAT3) Filter Bytes Mask Position */
#define GMAC_SAT3_FILTBMASK_Msk               (_UINT32_(0x3F) << GMAC_SAT3_FILTBMASK_Pos)          /* (GMAC_SAT3) Filter Bytes Mask Mask */
#define GMAC_SAT3_FILTBMASK(value)            (GMAC_SAT3_FILTBMASK_Msk & (_UINT32_(value) << GMAC_SAT3_FILTBMASK_Pos)) /* Assigment of value for FILTBMASK in the GMAC_SAT3 register */
#define   GMAC_SAT3_FILTBMASK_BIT1_Val        _UINT32_(0x1)                                        /* (GMAC_SAT3) Controls whether the first byte has been received.  */
#define   GMAC_SAT3_FILTBMASK_BIT2_Val        _UINT32_(0x2)                                        /* (GMAC_SAT3) Controls whether the second byte has been received.  */
#define   GMAC_SAT3_FILTBMASK_BIT3_Val        _UINT32_(0x4)                                        /* (GMAC_SAT3) Controls whether the third byte has been received.  */
#define   GMAC_SAT3_FILTBMASK_BIT4_Val        _UINT32_(0x8)                                        /* (GMAC_SAT3) Controls whether the fourth byte has been received.  */
#define   GMAC_SAT3_FILTBMASK_BIT5_Val        _UINT32_(0x10)                                       /* (GMAC_SAT3) Controls whether the fifth byte has been received.  */
#define   GMAC_SAT3_FILTBMASK_BIT6_Val        _UINT32_(0x20)                                       /* (GMAC_SAT3) Controls whether the sixth byte has been received  */
#define GMAC_SAT3_FILTBMASK_BIT1              (GMAC_SAT3_FILTBMASK_BIT1_Val << GMAC_SAT3_FILTBMASK_Pos) /* (GMAC_SAT3) Controls whether the first byte has been received. Position  */
#define GMAC_SAT3_FILTBMASK_BIT2              (GMAC_SAT3_FILTBMASK_BIT2_Val << GMAC_SAT3_FILTBMASK_Pos) /* (GMAC_SAT3) Controls whether the second byte has been received. Position  */
#define GMAC_SAT3_FILTBMASK_BIT3              (GMAC_SAT3_FILTBMASK_BIT3_Val << GMAC_SAT3_FILTBMASK_Pos) /* (GMAC_SAT3) Controls whether the third byte has been received. Position  */
#define GMAC_SAT3_FILTBMASK_BIT4              (GMAC_SAT3_FILTBMASK_BIT4_Val << GMAC_SAT3_FILTBMASK_Pos) /* (GMAC_SAT3) Controls whether the fourth byte has been received. Position  */
#define GMAC_SAT3_FILTBMASK_BIT5              (GMAC_SAT3_FILTBMASK_BIT5_Val << GMAC_SAT3_FILTBMASK_Pos) /* (GMAC_SAT3) Controls whether the fifth byte has been received. Position  */
#define GMAC_SAT3_FILTBMASK_BIT6              (GMAC_SAT3_FILTBMASK_BIT6_Val << GMAC_SAT3_FILTBMASK_Pos) /* (GMAC_SAT3) Controls whether the sixth byte has been received Position  */
#define GMAC_SAT3_Msk                         _UINT32_(0x3F01FFFF)                                 /* (GMAC_SAT3) Register Mask  */


/* -------- GMAC_SAB4 : (GMAC Offset: 0xA0) (R/W 32) Specific Address 4 Bottom Register -------- */
#define GMAC_SAB4_RESETVALUE                  _UINT32_(0x00)                                       /*  (GMAC_SAB4) Specific Address 4 Bottom Register  Reset Value */

#define GMAC_SAB4_ADDR_Pos                    _UINT32_(0)                                          /* (GMAC_SAB4) Specific Address 4 Position */
#define GMAC_SAB4_ADDR_Msk                    (_UINT32_(0xFFFFFFFF) << GMAC_SAB4_ADDR_Pos)         /* (GMAC_SAB4) Specific Address 4 Mask */
#define GMAC_SAB4_ADDR(value)                 (GMAC_SAB4_ADDR_Msk & (_UINT32_(value) << GMAC_SAB4_ADDR_Pos)) /* Assigment of value for ADDR in the GMAC_SAB4 register */
#define GMAC_SAB4_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (GMAC_SAB4) Register Mask  */


/* -------- GMAC_SAT4 : (GMAC Offset: 0xA4) (R/W 32) Specific Address 4 Top Register -------- */
#define GMAC_SAT4_RESETVALUE                  _UINT32_(0x00)                                       /*  (GMAC_SAT4) Specific Address 4 Top Register  Reset Value */

#define GMAC_SAT4_ADDR_Pos                    _UINT32_(0)                                          /* (GMAC_SAT4) Specific Address 4 Position */
#define GMAC_SAT4_ADDR_Msk                    (_UINT32_(0xFFFF) << GMAC_SAT4_ADDR_Pos)             /* (GMAC_SAT4) Specific Address 4 Mask */
#define GMAC_SAT4_ADDR(value)                 (GMAC_SAT4_ADDR_Msk & (_UINT32_(value) << GMAC_SAT4_ADDR_Pos)) /* Assigment of value for ADDR in the GMAC_SAT4 register */
#define GMAC_SAT4_FILTSORD_Pos                _UINT32_(16)                                         /* (GMAC_SAT4) Filter Source or Destination MAC Address Position */
#define GMAC_SAT4_FILTSORD_Msk                (_UINT32_(0x1) << GMAC_SAT4_FILTSORD_Pos)            /* (GMAC_SAT4) Filter Source or Destination MAC Address Mask */
#define GMAC_SAT4_FILTSORD(value)             (GMAC_SAT4_FILTSORD_Msk & (_UINT32_(value) << GMAC_SAT4_FILTSORD_Pos)) /* Assigment of value for FILTSORD in the GMAC_SAT4 register */
#define   GMAC_SAT4_FILTSORD_0_Val            _UINT32_(0x0)                                        /* (GMAC_SAT4) The filter is a destination address filter.  */
#define   GMAC_SAT4_FILTSORD_1_Val            _UINT32_(0x1)                                        /* (GMAC_SAT4) The filter is a source address filter.  */
#define GMAC_SAT4_FILTSORD_0                  (GMAC_SAT4_FILTSORD_0_Val << GMAC_SAT4_FILTSORD_Pos) /* (GMAC_SAT4) The filter is a destination address filter. Position  */
#define GMAC_SAT4_FILTSORD_1                  (GMAC_SAT4_FILTSORD_1_Val << GMAC_SAT4_FILTSORD_Pos) /* (GMAC_SAT4) The filter is a source address filter. Position  */
#define GMAC_SAT4_FILTBMASK_Pos               _UINT32_(24)                                         /* (GMAC_SAT4) Filter Bytes Mask Position */
#define GMAC_SAT4_FILTBMASK_Msk               (_UINT32_(0x3F) << GMAC_SAT4_FILTBMASK_Pos)          /* (GMAC_SAT4) Filter Bytes Mask Mask */
#define GMAC_SAT4_FILTBMASK(value)            (GMAC_SAT4_FILTBMASK_Msk & (_UINT32_(value) << GMAC_SAT4_FILTBMASK_Pos)) /* Assigment of value for FILTBMASK in the GMAC_SAT4 register */
#define   GMAC_SAT4_FILTBMASK_BIT1_Val        _UINT32_(0x1)                                        /* (GMAC_SAT4) Controls whether the first byte has been received.  */
#define   GMAC_SAT4_FILTBMASK_BIT2_Val        _UINT32_(0x2)                                        /* (GMAC_SAT4) Controls whether the second byte has been received.  */
#define   GMAC_SAT4_FILTBMASK_BIT3_Val        _UINT32_(0x4)                                        /* (GMAC_SAT4) Controls whether the third byte has been received.  */
#define   GMAC_SAT4_FILTBMASK_BIT4_Val        _UINT32_(0x8)                                        /* (GMAC_SAT4) Controls whether the fourth byte has been received.  */
#define   GMAC_SAT4_FILTBMASK_BIT5_Val        _UINT32_(0x10)                                       /* (GMAC_SAT4) Controls whether the fifth byte has been received.  */
#define   GMAC_SAT4_FILTBMASK_BIT6_Val        _UINT32_(0x20)                                       /* (GMAC_SAT4) Controls whether the sixth byte has been received  */
#define GMAC_SAT4_FILTBMASK_BIT1              (GMAC_SAT4_FILTBMASK_BIT1_Val << GMAC_SAT4_FILTBMASK_Pos) /* (GMAC_SAT4) Controls whether the first byte has been received. Position  */
#define GMAC_SAT4_FILTBMASK_BIT2              (GMAC_SAT4_FILTBMASK_BIT2_Val << GMAC_SAT4_FILTBMASK_Pos) /* (GMAC_SAT4) Controls whether the second byte has been received. Position  */
#define GMAC_SAT4_FILTBMASK_BIT3              (GMAC_SAT4_FILTBMASK_BIT3_Val << GMAC_SAT4_FILTBMASK_Pos) /* (GMAC_SAT4) Controls whether the third byte has been received. Position  */
#define GMAC_SAT4_FILTBMASK_BIT4              (GMAC_SAT4_FILTBMASK_BIT4_Val << GMAC_SAT4_FILTBMASK_Pos) /* (GMAC_SAT4) Controls whether the fourth byte has been received. Position  */
#define GMAC_SAT4_FILTBMASK_BIT5              (GMAC_SAT4_FILTBMASK_BIT5_Val << GMAC_SAT4_FILTBMASK_Pos) /* (GMAC_SAT4) Controls whether the fifth byte has been received. Position  */
#define GMAC_SAT4_FILTBMASK_BIT6              (GMAC_SAT4_FILTBMASK_BIT6_Val << GMAC_SAT4_FILTBMASK_Pos) /* (GMAC_SAT4) Controls whether the sixth byte has been received Position  */
#define GMAC_SAT4_Msk                         _UINT32_(0x3F01FFFF)                                 /* (GMAC_SAT4) Register Mask  */


/* -------- GMAC_TIDM1 : (GMAC Offset: 0xA8) (R/W 32) Type ID Match 1 Register -------- */
#define GMAC_TIDM1_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_TIDM1) Type ID Match 1 Register  Reset Value */

#define GMAC_TIDM1_TID_Pos                    _UINT32_(0)                                          /* (GMAC_TIDM1) Type ID Match 1 Position */
#define GMAC_TIDM1_TID_Msk                    (_UINT32_(0xFFFF) << GMAC_TIDM1_TID_Pos)             /* (GMAC_TIDM1) Type ID Match 1 Mask */
#define GMAC_TIDM1_TID(value)                 (GMAC_TIDM1_TID_Msk & (_UINT32_(value) << GMAC_TIDM1_TID_Pos)) /* Assigment of value for TID in the GMAC_TIDM1 register */
#define GMAC_TIDM1_ENID1_Pos                  _UINT32_(31)                                         /* (GMAC_TIDM1) Enable Copying of TID Matched Frames Position */
#define GMAC_TIDM1_ENID1_Msk                  (_UINT32_(0x1) << GMAC_TIDM1_ENID1_Pos)              /* (GMAC_TIDM1) Enable Copying of TID Matched Frames Mask */
#define GMAC_TIDM1_ENID1(value)               (GMAC_TIDM1_ENID1_Msk & (_UINT32_(value) << GMAC_TIDM1_ENID1_Pos)) /* Assigment of value for ENID1 in the GMAC_TIDM1 register */
#define   GMAC_TIDM1_ENID1_0_Val              _UINT32_(0x0)                                        /* (GMAC_TIDM1) TID is not part of the comparison match.  */
#define   GMAC_TIDM1_ENID1_1_Val              _UINT32_(0x1)                                        /* (GMAC_TIDM1) TID is processed for the comparison match.  */
#define GMAC_TIDM1_ENID1_0                    (GMAC_TIDM1_ENID1_0_Val << GMAC_TIDM1_ENID1_Pos)     /* (GMAC_TIDM1) TID is not part of the comparison match. Position  */
#define GMAC_TIDM1_ENID1_1                    (GMAC_TIDM1_ENID1_1_Val << GMAC_TIDM1_ENID1_Pos)     /* (GMAC_TIDM1) TID is processed for the comparison match. Position  */
#define GMAC_TIDM1_Msk                        _UINT32_(0x8000FFFF)                                 /* (GMAC_TIDM1) Register Mask  */

#define GMAC_TIDM1_ENID_Pos                   _UINT32_(31)                                         /* (GMAC_TIDM1 Position) Enable Copying of TID Matched Frames */
#define GMAC_TIDM1_ENID_Msk                   (_UINT32_(0x1) << GMAC_TIDM1_ENID_Pos)               /* (GMAC_TIDM1 Mask) ENID */
#define GMAC_TIDM1_ENID(value)                (GMAC_TIDM1_ENID_Msk & (_UINT32_(value) << GMAC_TIDM1_ENID_Pos)) 

/* -------- GMAC_TIDM2 : (GMAC Offset: 0xAC) (R/W 32) Type ID Match 2 Register -------- */
#define GMAC_TIDM2_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_TIDM2) Type ID Match 2 Register  Reset Value */

#define GMAC_TIDM2_TID_Pos                    _UINT32_(0)                                          /* (GMAC_TIDM2) Type ID Match 2 Position */
#define GMAC_TIDM2_TID_Msk                    (_UINT32_(0xFFFF) << GMAC_TIDM2_TID_Pos)             /* (GMAC_TIDM2) Type ID Match 2 Mask */
#define GMAC_TIDM2_TID(value)                 (GMAC_TIDM2_TID_Msk & (_UINT32_(value) << GMAC_TIDM2_TID_Pos)) /* Assigment of value for TID in the GMAC_TIDM2 register */
#define GMAC_TIDM2_ENID2_Pos                  _UINT32_(31)                                         /* (GMAC_TIDM2) Enable Copying of TID Matched Frames Position */
#define GMAC_TIDM2_ENID2_Msk                  (_UINT32_(0x1) << GMAC_TIDM2_ENID2_Pos)              /* (GMAC_TIDM2) Enable Copying of TID Matched Frames Mask */
#define GMAC_TIDM2_ENID2(value)               (GMAC_TIDM2_ENID2_Msk & (_UINT32_(value) << GMAC_TIDM2_ENID2_Pos)) /* Assigment of value for ENID2 in the GMAC_TIDM2 register */
#define   GMAC_TIDM2_ENID2_0_Val              _UINT32_(0x0)                                        /* (GMAC_TIDM2) TID is not part of the comparison match.  */
#define   GMAC_TIDM2_ENID2_1_Val              _UINT32_(0x1)                                        /* (GMAC_TIDM2) TID is processed for the comparison match.  */
#define GMAC_TIDM2_ENID2_0                    (GMAC_TIDM2_ENID2_0_Val << GMAC_TIDM2_ENID2_Pos)     /* (GMAC_TIDM2) TID is not part of the comparison match. Position  */
#define GMAC_TIDM2_ENID2_1                    (GMAC_TIDM2_ENID2_1_Val << GMAC_TIDM2_ENID2_Pos)     /* (GMAC_TIDM2) TID is processed for the comparison match. Position  */
#define GMAC_TIDM2_Msk                        _UINT32_(0x8000FFFF)                                 /* (GMAC_TIDM2) Register Mask  */

#define GMAC_TIDM2_ENID_Pos                   _UINT32_(31)                                         /* (GMAC_TIDM2 Position) Enable Copying of TID Matched Frames */
#define GMAC_TIDM2_ENID_Msk                   (_UINT32_(0x1) << GMAC_TIDM2_ENID_Pos)               /* (GMAC_TIDM2 Mask) ENID */
#define GMAC_TIDM2_ENID(value)                (GMAC_TIDM2_ENID_Msk & (_UINT32_(value) << GMAC_TIDM2_ENID_Pos)) 

/* -------- GMAC_TIDM3 : (GMAC Offset: 0xB0) (R/W 32) Type ID Match 3 Register -------- */
#define GMAC_TIDM3_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_TIDM3) Type ID Match 3 Register  Reset Value */

#define GMAC_TIDM3_TID_Pos                    _UINT32_(0)                                          /* (GMAC_TIDM3) Type ID Match 3 Position */
#define GMAC_TIDM3_TID_Msk                    (_UINT32_(0xFFFF) << GMAC_TIDM3_TID_Pos)             /* (GMAC_TIDM3) Type ID Match 3 Mask */
#define GMAC_TIDM3_TID(value)                 (GMAC_TIDM3_TID_Msk & (_UINT32_(value) << GMAC_TIDM3_TID_Pos)) /* Assigment of value for TID in the GMAC_TIDM3 register */
#define GMAC_TIDM3_ENID3_Pos                  _UINT32_(31)                                         /* (GMAC_TIDM3) Enable Copying of TID Matched Frames Position */
#define GMAC_TIDM3_ENID3_Msk                  (_UINT32_(0x1) << GMAC_TIDM3_ENID3_Pos)              /* (GMAC_TIDM3) Enable Copying of TID Matched Frames Mask */
#define GMAC_TIDM3_ENID3(value)               (GMAC_TIDM3_ENID3_Msk & (_UINT32_(value) << GMAC_TIDM3_ENID3_Pos)) /* Assigment of value for ENID3 in the GMAC_TIDM3 register */
#define   GMAC_TIDM3_ENID3_0_Val              _UINT32_(0x0)                                        /* (GMAC_TIDM3) TID is not part of the comparison match.  */
#define   GMAC_TIDM3_ENID3_1_Val              _UINT32_(0x1)                                        /* (GMAC_TIDM3) TID is processed for the comparison match.  */
#define GMAC_TIDM3_ENID3_0                    (GMAC_TIDM3_ENID3_0_Val << GMAC_TIDM3_ENID3_Pos)     /* (GMAC_TIDM3) TID is not part of the comparison match. Position  */
#define GMAC_TIDM3_ENID3_1                    (GMAC_TIDM3_ENID3_1_Val << GMAC_TIDM3_ENID3_Pos)     /* (GMAC_TIDM3) TID is processed for the comparison match. Position  */
#define GMAC_TIDM3_Msk                        _UINT32_(0x8000FFFF)                                 /* (GMAC_TIDM3) Register Mask  */

#define GMAC_TIDM3_ENID_Pos                   _UINT32_(31)                                         /* (GMAC_TIDM3 Position) Enable Copying of TID Matched Frames */
#define GMAC_TIDM3_ENID_Msk                   (_UINT32_(0x1) << GMAC_TIDM3_ENID_Pos)               /* (GMAC_TIDM3 Mask) ENID */
#define GMAC_TIDM3_ENID(value)                (GMAC_TIDM3_ENID_Msk & (_UINT32_(value) << GMAC_TIDM3_ENID_Pos)) 

/* -------- GMAC_TIDM4 : (GMAC Offset: 0xB4) (R/W 32) Type ID Match 4 Register -------- */
#define GMAC_TIDM4_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_TIDM4) Type ID Match 4 Register  Reset Value */

#define GMAC_TIDM4_TID_Pos                    _UINT32_(0)                                          /* (GMAC_TIDM4) Type ID Match 4 Position */
#define GMAC_TIDM4_TID_Msk                    (_UINT32_(0xFFFF) << GMAC_TIDM4_TID_Pos)             /* (GMAC_TIDM4) Type ID Match 4 Mask */
#define GMAC_TIDM4_TID(value)                 (GMAC_TIDM4_TID_Msk & (_UINT32_(value) << GMAC_TIDM4_TID_Pos)) /* Assigment of value for TID in the GMAC_TIDM4 register */
#define GMAC_TIDM4_ENID4_Pos                  _UINT32_(31)                                         /* (GMAC_TIDM4) Enable Copying of TID Matched Frames Position */
#define GMAC_TIDM4_ENID4_Msk                  (_UINT32_(0x1) << GMAC_TIDM4_ENID4_Pos)              /* (GMAC_TIDM4) Enable Copying of TID Matched Frames Mask */
#define GMAC_TIDM4_ENID4(value)               (GMAC_TIDM4_ENID4_Msk & (_UINT32_(value) << GMAC_TIDM4_ENID4_Pos)) /* Assigment of value for ENID4 in the GMAC_TIDM4 register */
#define   GMAC_TIDM4_ENID4_0_Val              _UINT32_(0x0)                                        /* (GMAC_TIDM4) TID is not part of the comparison match.  */
#define   GMAC_TIDM4_ENID4_1_Val              _UINT32_(0x1)                                        /* (GMAC_TIDM4) TID is processed for the comparison match.  */
#define GMAC_TIDM4_ENID4_0                    (GMAC_TIDM4_ENID4_0_Val << GMAC_TIDM4_ENID4_Pos)     /* (GMAC_TIDM4) TID is not part of the comparison match. Position  */
#define GMAC_TIDM4_ENID4_1                    (GMAC_TIDM4_ENID4_1_Val << GMAC_TIDM4_ENID4_Pos)     /* (GMAC_TIDM4) TID is processed for the comparison match. Position  */
#define GMAC_TIDM4_Msk                        _UINT32_(0x8000FFFF)                                 /* (GMAC_TIDM4) Register Mask  */

#define GMAC_TIDM4_ENID_Pos                   _UINT32_(31)                                         /* (GMAC_TIDM4 Position) Enable Copying of TID Matched Frames */
#define GMAC_TIDM4_ENID_Msk                   (_UINT32_(0x1) << GMAC_TIDM4_ENID_Pos)               /* (GMAC_TIDM4 Mask) ENID */
#define GMAC_TIDM4_ENID(value)                (GMAC_TIDM4_ENID_Msk & (_UINT32_(value) << GMAC_TIDM4_ENID_Pos)) 

/* -------- GMAC_WOL : (GMAC Offset: 0xB8) (R/W 32) Wake on LAN Register -------- */
#define GMAC_WOL_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_WOL) Wake on LAN Register  Reset Value */

#define GMAC_WOL_IP_Pos                       _UINT32_(0)                                          /* (GMAC_WOL) ARP Request IP Address Position */
#define GMAC_WOL_IP_Msk                       (_UINT32_(0xFFFF) << GMAC_WOL_IP_Pos)                /* (GMAC_WOL) ARP Request IP Address Mask */
#define GMAC_WOL_IP(value)                    (GMAC_WOL_IP_Msk & (_UINT32_(value) << GMAC_WOL_IP_Pos)) /* Assigment of value for IP in the GMAC_WOL register */
#define GMAC_WOL_MAG_Pos                      _UINT32_(16)                                         /* (GMAC_WOL) Magic Packet Event Enable Position */
#define GMAC_WOL_MAG_Msk                      (_UINT32_(0x1) << GMAC_WOL_MAG_Pos)                  /* (GMAC_WOL) Magic Packet Event Enable Mask */
#define GMAC_WOL_MAG(value)                   (GMAC_WOL_MAG_Msk & (_UINT32_(value) << GMAC_WOL_MAG_Pos)) /* Assigment of value for MAG in the GMAC_WOL register */
#define GMAC_WOL_ARP_Pos                      _UINT32_(17)                                         /* (GMAC_WOL) ARP Request Event Enable Position */
#define GMAC_WOL_ARP_Msk                      (_UINT32_(0x1) << GMAC_WOL_ARP_Pos)                  /* (GMAC_WOL) ARP Request Event Enable Mask */
#define GMAC_WOL_ARP(value)                   (GMAC_WOL_ARP_Msk & (_UINT32_(value) << GMAC_WOL_ARP_Pos)) /* Assigment of value for ARP in the GMAC_WOL register */
#define GMAC_WOL_SA1_Pos                      _UINT32_(18)                                         /* (GMAC_WOL) Specific Address Register 1 Event Enable Position */
#define GMAC_WOL_SA1_Msk                      (_UINT32_(0x1) << GMAC_WOL_SA1_Pos)                  /* (GMAC_WOL) Specific Address Register 1 Event Enable Mask */
#define GMAC_WOL_SA1(value)                   (GMAC_WOL_SA1_Msk & (_UINT32_(value) << GMAC_WOL_SA1_Pos)) /* Assigment of value for SA1 in the GMAC_WOL register */
#define GMAC_WOL_MTI_Pos                      _UINT32_(19)                                         /* (GMAC_WOL) Multicast Hash Event Enable Position */
#define GMAC_WOL_MTI_Msk                      (_UINT32_(0x1) << GMAC_WOL_MTI_Pos)                  /* (GMAC_WOL) Multicast Hash Event Enable Mask */
#define GMAC_WOL_MTI(value)                   (GMAC_WOL_MTI_Msk & (_UINT32_(value) << GMAC_WOL_MTI_Pos)) /* Assigment of value for MTI in the GMAC_WOL register */
#define GMAC_WOL_Msk                          _UINT32_(0x000FFFFF)                                 /* (GMAC_WOL) Register Mask  */

#define GMAC_WOL_SA_Pos                       _UINT32_(18)                                         /* (GMAC_WOL Position) Specific Address Register x Event Enable */
#define GMAC_WOL_SA_Msk                       (_UINT32_(0x1) << GMAC_WOL_SA_Pos)                   /* (GMAC_WOL Mask) SA */
#define GMAC_WOL_SA(value)                    (GMAC_WOL_SA_Msk & (_UINT32_(value) << GMAC_WOL_SA_Pos)) 

/* -------- GMAC_IPGS : (GMAC Offset: 0xBC) (R/W 32) IPG Stretch Register -------- */
#define GMAC_IPGS_RESETVALUE                  _UINT32_(0x00)                                       /*  (GMAC_IPGS) IPG Stretch Register  Reset Value */

#define GMAC_IPGS_FL_Pos                      _UINT32_(0)                                          /* (GMAC_IPGS) Frame Length Position */
#define GMAC_IPGS_FL_Msk                      (_UINT32_(0xFFFF) << GMAC_IPGS_FL_Pos)               /* (GMAC_IPGS) Frame Length Mask */
#define GMAC_IPGS_FL(value)                   (GMAC_IPGS_FL_Msk & (_UINT32_(value) << GMAC_IPGS_FL_Pos)) /* Assigment of value for FL in the GMAC_IPGS register */
#define GMAC_IPGS_Msk                         _UINT32_(0x0000FFFF)                                 /* (GMAC_IPGS) Register Mask  */


/* -------- GMAC_SVLAN : (GMAC Offset: 0xC0) (R/W 32) Stacked VLAN Register -------- */
#define GMAC_SVLAN_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_SVLAN) Stacked VLAN Register  Reset Value */

#define GMAC_SVLAN_VLAN_TYPE_Pos              _UINT32_(0)                                          /* (GMAC_SVLAN) User Defined VLAN_TYPE Field Position */
#define GMAC_SVLAN_VLAN_TYPE_Msk              (_UINT32_(0xFFFF) << GMAC_SVLAN_VLAN_TYPE_Pos)       /* (GMAC_SVLAN) User Defined VLAN_TYPE Field Mask */
#define GMAC_SVLAN_VLAN_TYPE(value)           (GMAC_SVLAN_VLAN_TYPE_Msk & (_UINT32_(value) << GMAC_SVLAN_VLAN_TYPE_Pos)) /* Assigment of value for VLAN_TYPE in the GMAC_SVLAN register */
#define GMAC_SVLAN_ESVLAN_Pos                 _UINT32_(31)                                         /* (GMAC_SVLAN) Enable Stacked VLAN Processing Mode Position */
#define GMAC_SVLAN_ESVLAN_Msk                 (_UINT32_(0x1) << GMAC_SVLAN_ESVLAN_Pos)             /* (GMAC_SVLAN) Enable Stacked VLAN Processing Mode Mask */
#define GMAC_SVLAN_ESVLAN(value)              (GMAC_SVLAN_ESVLAN_Msk & (_UINT32_(value) << GMAC_SVLAN_ESVLAN_Pos)) /* Assigment of value for ESVLAN in the GMAC_SVLAN register */
#define   GMAC_SVLAN_ESVLAN_0_Val             _UINT32_(0x0)                                        /* (GMAC_SVLAN) Disable the stacked VLAN Processing mode  */
#define   GMAC_SVLAN_ESVLAN_1_Val             _UINT32_(0x1)                                        /* (GMAC_SVLAN) Enable the stacked VLAN Processing mode  */
#define GMAC_SVLAN_ESVLAN_0                   (GMAC_SVLAN_ESVLAN_0_Val << GMAC_SVLAN_ESVLAN_Pos)   /* (GMAC_SVLAN) Disable the stacked VLAN Processing mode Position  */
#define GMAC_SVLAN_ESVLAN_1                   (GMAC_SVLAN_ESVLAN_1_Val << GMAC_SVLAN_ESVLAN_Pos)   /* (GMAC_SVLAN) Enable the stacked VLAN Processing mode Position  */
#define GMAC_SVLAN_Msk                        _UINT32_(0x8000FFFF)                                 /* (GMAC_SVLAN) Register Mask  */


/* -------- GMAC_TPFCP : (GMAC Offset: 0xC4) (R/W 32) Transmit PFC Pause Register -------- */
#define GMAC_TPFCP_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_TPFCP) Transmit PFC Pause Register  Reset Value */

#define GMAC_TPFCP_PEV_Pos                    _UINT32_(0)                                          /* (GMAC_TPFCP) Priority Enable Vector Position */
#define GMAC_TPFCP_PEV_Msk                    (_UINT32_(0xFF) << GMAC_TPFCP_PEV_Pos)               /* (GMAC_TPFCP) Priority Enable Vector Mask */
#define GMAC_TPFCP_PEV(value)                 (GMAC_TPFCP_PEV_Msk & (_UINT32_(value) << GMAC_TPFCP_PEV_Pos)) /* Assigment of value for PEV in the GMAC_TPFCP register */
#define GMAC_TPFCP_PQ_Pos                     _UINT32_(8)                                          /* (GMAC_TPFCP) Pause Quantum Position */
#define GMAC_TPFCP_PQ_Msk                     (_UINT32_(0xFF) << GMAC_TPFCP_PQ_Pos)                /* (GMAC_TPFCP) Pause Quantum Mask */
#define GMAC_TPFCP_PQ(value)                  (GMAC_TPFCP_PQ_Msk & (_UINT32_(value) << GMAC_TPFCP_PQ_Pos)) /* Assigment of value for PQ in the GMAC_TPFCP register */
#define GMAC_TPFCP_Msk                        _UINT32_(0x0000FFFF)                                 /* (GMAC_TPFCP) Register Mask  */


/* -------- GMAC_SAMB1 : (GMAC Offset: 0xC8) (R/W 32) Specific Address 1 Mask Bottom Register -------- */
#define GMAC_SAMB1_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_SAMB1) Specific Address 1 Mask Bottom Register  Reset Value */

#define GMAC_SAMB1_ADDR_Pos                   _UINT32_(0)                                          /* (GMAC_SAMB1) Specific Address 1 Mask Position */
#define GMAC_SAMB1_ADDR_Msk                   (_UINT32_(0xFFFFFFFF) << GMAC_SAMB1_ADDR_Pos)        /* (GMAC_SAMB1) Specific Address 1 Mask Mask */
#define GMAC_SAMB1_ADDR(value)                (GMAC_SAMB1_ADDR_Msk & (_UINT32_(value) << GMAC_SAMB1_ADDR_Pos)) /* Assigment of value for ADDR in the GMAC_SAMB1 register */
#define GMAC_SAMB1_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (GMAC_SAMB1) Register Mask  */


/* -------- GMAC_SAMT1 : (GMAC Offset: 0xCC) (R/W 32) Specific Address 1 Mask Top Register -------- */
#define GMAC_SAMT1_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_SAMT1) Specific Address 1 Mask Top Register  Reset Value */

#define GMAC_SAMT1_ADDR_Pos                   _UINT32_(0)                                          /* (GMAC_SAMT1) Specific Address 1 Mask Position */
#define GMAC_SAMT1_ADDR_Msk                   (_UINT32_(0xFFFF) << GMAC_SAMT1_ADDR_Pos)            /* (GMAC_SAMT1) Specific Address 1 Mask Mask */
#define GMAC_SAMT1_ADDR(value)                (GMAC_SAMT1_ADDR_Msk & (_UINT32_(value) << GMAC_SAMT1_ADDR_Pos)) /* Assigment of value for ADDR in the GMAC_SAMT1 register */
#define GMAC_SAMT1_Msk                        _UINT32_(0x0000FFFF)                                 /* (GMAC_SAMT1) Register Mask  */


/* -------- GMAC_AMRX : (GMAC Offset: 0xD0) (R/W 32) System Memory Address Mask for RX Data Buffer Accesses Register -------- */
#define GMAC_AMRX_RESETVALUE                  _UINT32_(0x00)                                       /*  (GMAC_AMRX) System Memory Address Mask for RX Data Buffer Accesses Register  Reset Value */

#define GMAC_AMRX_MSBADDRMSK_Pos              _UINT32_(0)                                          /* (GMAC_AMRX) Mask of the Receive Data Buffer Address Position */
#define GMAC_AMRX_MSBADDRMSK_Msk              (_UINT32_(0xF) << GMAC_AMRX_MSBADDRMSK_Pos)          /* (GMAC_AMRX) Mask of the Receive Data Buffer Address Mask */
#define GMAC_AMRX_MSBADDRMSK(value)           (GMAC_AMRX_MSBADDRMSK_Msk & (_UINT32_(value) << GMAC_AMRX_MSBADDRMSK_Pos)) /* Assigment of value for MSBADDRMSK in the GMAC_AMRX register */
#define GMAC_AMRX_MSBADDR_Pos                 _UINT32_(28)                                         /* (GMAC_AMRX) MSB of the Receive Data Buffer Address Position */
#define GMAC_AMRX_MSBADDR_Msk                 (_UINT32_(0xF) << GMAC_AMRX_MSBADDR_Pos)             /* (GMAC_AMRX) MSB of the Receive Data Buffer Address Mask */
#define GMAC_AMRX_MSBADDR(value)              (GMAC_AMRX_MSBADDR_Msk & (_UINT32_(value) << GMAC_AMRX_MSBADDR_Pos)) /* Assigment of value for MSBADDR in the GMAC_AMRX register */
#define GMAC_AMRX_Msk                         _UINT32_(0xF000000F)                                 /* (GMAC_AMRX) Register Mask  */


/* -------- GMAC_RXUDAR : (GMAC Offset: 0xD4) (R/W 32) PTP RX Unicast IP Destination Address Register -------- */
#define GMAC_RXUDAR_RESETVALUE                _UINT32_(0x00)                                       /*  (GMAC_RXUDAR) PTP RX Unicast IP Destination Address Register  Reset Value */

#define GMAC_RXUDAR_RXUDA_Pos                 _UINT32_(0)                                          /* (GMAC_RXUDAR) Receive Unicast Destination Address Position */
#define GMAC_RXUDAR_RXUDA_Msk                 (_UINT32_(0xFFFFFFFF) << GMAC_RXUDAR_RXUDA_Pos)      /* (GMAC_RXUDAR) Receive Unicast Destination Address Mask */
#define GMAC_RXUDAR_RXUDA(value)              (GMAC_RXUDAR_RXUDA_Msk & (_UINT32_(value) << GMAC_RXUDAR_RXUDA_Pos)) /* Assigment of value for RXUDA in the GMAC_RXUDAR register */
#define GMAC_RXUDAR_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (GMAC_RXUDAR) Register Mask  */


/* -------- GMAC_TXUDAR : (GMAC Offset: 0xD8) (R/W 32) PTP TX Unicast IP Destination Address Register -------- */
#define GMAC_TXUDAR_RESETVALUE                _UINT32_(0x00)                                       /*  (GMAC_TXUDAR) PTP TX Unicast IP Destination Address Register  Reset Value */

#define GMAC_TXUDAR_TXUDA_Pos                 _UINT32_(0)                                          /* (GMAC_TXUDAR) Transmit Unicast Destination Address Position */
#define GMAC_TXUDAR_TXUDA_Msk                 (_UINT32_(0xFFFFFFFF) << GMAC_TXUDAR_TXUDA_Pos)      /* (GMAC_TXUDAR) Transmit Unicast Destination Address Mask */
#define GMAC_TXUDAR_TXUDA(value)              (GMAC_TXUDAR_TXUDA_Msk & (_UINT32_(value) << GMAC_TXUDAR_TXUDA_Pos)) /* Assigment of value for TXUDA in the GMAC_TXUDAR register */
#define GMAC_TXUDAR_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (GMAC_TXUDAR) Register Mask  */


/* -------- GMAC_NSC : (GMAC Offset: 0xDC) (R/W 32) 1588 Timer Nanosecond Comparison Register -------- */
#define GMAC_NSC_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_NSC) 1588 Timer Nanosecond Comparison Register  Reset Value */

#define GMAC_NSC_NANOSEC_Pos                  _UINT32_(0)                                          /* (GMAC_NSC) 1588 Timer Nanosecond Comparison Value Position */
#define GMAC_NSC_NANOSEC_Msk                  (_UINT32_(0x3FFFFF) << GMAC_NSC_NANOSEC_Pos)         /* (GMAC_NSC) 1588 Timer Nanosecond Comparison Value Mask */
#define GMAC_NSC_NANOSEC(value)               (GMAC_NSC_NANOSEC_Msk & (_UINT32_(value) << GMAC_NSC_NANOSEC_Pos)) /* Assigment of value for NANOSEC in the GMAC_NSC register */
#define GMAC_NSC_Msk                          _UINT32_(0x003FFFFF)                                 /* (GMAC_NSC) Register Mask  */


/* -------- GMAC_SCL : (GMAC Offset: 0xE0) (R/W 32) 1588 Timer Second Comparison Low Register -------- */
#define GMAC_SCL_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_SCL) 1588 Timer Second Comparison Low Register  Reset Value */

#define GMAC_SCL_SEC_Pos                      _UINT32_(0)                                          /* (GMAC_SCL) 1588 Timer Second Comparison Value Position */
#define GMAC_SCL_SEC_Msk                      (_UINT32_(0xFFFFFFFF) << GMAC_SCL_SEC_Pos)           /* (GMAC_SCL) 1588 Timer Second Comparison Value Mask */
#define GMAC_SCL_SEC(value)                   (GMAC_SCL_SEC_Msk & (_UINT32_(value) << GMAC_SCL_SEC_Pos)) /* Assigment of value for SEC in the GMAC_SCL register */
#define GMAC_SCL_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (GMAC_SCL) Register Mask  */


/* -------- GMAC_SCH : (GMAC Offset: 0xE4) (R/W 32) 1588 Timer Second Comparison High Register -------- */
#define GMAC_SCH_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_SCH) 1588 Timer Second Comparison High Register  Reset Value */

#define GMAC_SCH_SEC_Pos                      _UINT32_(0)                                          /* (GMAC_SCH) 1588 Timer Second Comparison Value Position */
#define GMAC_SCH_SEC_Msk                      (_UINT32_(0xFFFF) << GMAC_SCH_SEC_Pos)               /* (GMAC_SCH) 1588 Timer Second Comparison Value Mask */
#define GMAC_SCH_SEC(value)                   (GMAC_SCH_SEC_Msk & (_UINT32_(value) << GMAC_SCH_SEC_Pos)) /* Assigment of value for SEC in the GMAC_SCH register */
#define GMAC_SCH_Msk                          _UINT32_(0x0000FFFF)                                 /* (GMAC_SCH) Register Mask  */


/* -------- GMAC_EFTSH : (GMAC Offset: 0xE8) ( R/ 32) PTP Event Frame Transmitted Seconds High Register -------- */
#define GMAC_EFTSH_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_EFTSH) PTP Event Frame Transmitted Seconds High Register  Reset Value */

#define GMAC_EFTSH_RUD_Pos                    _UINT32_(0)                                          /* (GMAC_EFTSH) Register Update Position */
#define GMAC_EFTSH_RUD_Msk                    (_UINT32_(0xFFFF) << GMAC_EFTSH_RUD_Pos)             /* (GMAC_EFTSH) Register Update Mask */
#define GMAC_EFTSH_RUD(value)                 (GMAC_EFTSH_RUD_Msk & (_UINT32_(value) << GMAC_EFTSH_RUD_Pos)) /* Assigment of value for RUD in the GMAC_EFTSH register */
#define GMAC_EFTSH_Msk                        _UINT32_(0x0000FFFF)                                 /* (GMAC_EFTSH) Register Mask  */


/* -------- GMAC_EFRSH : (GMAC Offset: 0xEC) ( R/ 32) PTP Event Frame Received Seconds High Register -------- */
#define GMAC_EFRSH_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_EFRSH) PTP Event Frame Received Seconds High Register  Reset Value */

#define GMAC_EFRSH_RUD_Pos                    _UINT32_(0)                                          /* (GMAC_EFRSH) Register Update Position */
#define GMAC_EFRSH_RUD_Msk                    (_UINT32_(0xFFFF) << GMAC_EFRSH_RUD_Pos)             /* (GMAC_EFRSH) Register Update Mask */
#define GMAC_EFRSH_RUD(value)                 (GMAC_EFRSH_RUD_Msk & (_UINT32_(value) << GMAC_EFRSH_RUD_Pos)) /* Assigment of value for RUD in the GMAC_EFRSH register */
#define GMAC_EFRSH_Msk                        _UINT32_(0x0000FFFF)                                 /* (GMAC_EFRSH) Register Mask  */


/* -------- GMAC_PEFTSH : (GMAC Offset: 0xF0) ( R/ 32) PTP Peer Event Frame Transmitted Seconds High Register -------- */
#define GMAC_PEFTSH_RESETVALUE                _UINT32_(0x00)                                       /*  (GMAC_PEFTSH) PTP Peer Event Frame Transmitted Seconds High Register  Reset Value */

#define GMAC_PEFTSH_RUD_Pos                   _UINT32_(0)                                          /* (GMAC_PEFTSH) Register Update Position */
#define GMAC_PEFTSH_RUD_Msk                   (_UINT32_(0xFFFF) << GMAC_PEFTSH_RUD_Pos)            /* (GMAC_PEFTSH) Register Update Mask */
#define GMAC_PEFTSH_RUD(value)                (GMAC_PEFTSH_RUD_Msk & (_UINT32_(value) << GMAC_PEFTSH_RUD_Pos)) /* Assigment of value for RUD in the GMAC_PEFTSH register */
#define GMAC_PEFTSH_Msk                       _UINT32_(0x0000FFFF)                                 /* (GMAC_PEFTSH) Register Mask  */


/* -------- GMAC_PEFRSH : (GMAC Offset: 0xF4) ( R/ 32) PTP Peer Event Frame Received Seconds High Register -------- */
#define GMAC_PEFRSH_RESETVALUE                _UINT32_(0x00)                                       /*  (GMAC_PEFRSH) PTP Peer Event Frame Received Seconds High Register  Reset Value */

#define GMAC_PEFRSH_RUD_Pos                   _UINT32_(0)                                          /* (GMAC_PEFRSH) Register Update Position */
#define GMAC_PEFRSH_RUD_Msk                   (_UINT32_(0xFFFF) << GMAC_PEFRSH_RUD_Pos)            /* (GMAC_PEFRSH) Register Update Mask */
#define GMAC_PEFRSH_RUD(value)                (GMAC_PEFRSH_RUD_Msk & (_UINT32_(value) << GMAC_PEFRSH_RUD_Pos)) /* Assigment of value for RUD in the GMAC_PEFRSH register */
#define GMAC_PEFRSH_Msk                       _UINT32_(0x0000FFFF)                                 /* (GMAC_PEFRSH) Register Mask  */


/* -------- GMAC_OTLO : (GMAC Offset: 0x100) ( R/ 32) Octets Transmitted Low Register -------- */
#define GMAC_OTLO_RESETVALUE                  _UINT32_(0x00)                                       /*  (GMAC_OTLO) Octets Transmitted Low Register  Reset Value */

#define GMAC_OTLO_TXO_Pos                     _UINT32_(0)                                          /* (GMAC_OTLO) Transmitted Octets Position */
#define GMAC_OTLO_TXO_Msk                     (_UINT32_(0xFFFFFFFF) << GMAC_OTLO_TXO_Pos)          /* (GMAC_OTLO) Transmitted Octets Mask */
#define GMAC_OTLO_TXO(value)                  (GMAC_OTLO_TXO_Msk & (_UINT32_(value) << GMAC_OTLO_TXO_Pos)) /* Assigment of value for TXO in the GMAC_OTLO register */
#define GMAC_OTLO_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (GMAC_OTLO) Register Mask  */


/* -------- GMAC_OTHI : (GMAC Offset: 0x104) ( R/ 32) Octets Transmitted High Register -------- */
#define GMAC_OTHI_RESETVALUE                  _UINT32_(0x00)                                       /*  (GMAC_OTHI) Octets Transmitted High Register  Reset Value */

#define GMAC_OTHI_TXO_Pos                     _UINT32_(0)                                          /* (GMAC_OTHI) Transmitted Octets Position */
#define GMAC_OTHI_TXO_Msk                     (_UINT32_(0xFFFF) << GMAC_OTHI_TXO_Pos)              /* (GMAC_OTHI) Transmitted Octets Mask */
#define GMAC_OTHI_TXO(value)                  (GMAC_OTHI_TXO_Msk & (_UINT32_(value) << GMAC_OTHI_TXO_Pos)) /* Assigment of value for TXO in the GMAC_OTHI register */
#define GMAC_OTHI_Msk                         _UINT32_(0x0000FFFF)                                 /* (GMAC_OTHI) Register Mask  */


/* -------- GMAC_FT : (GMAC Offset: 0x108) ( R/ 32) Frames Transmitted Register -------- */
#define GMAC_FT_RESETVALUE                    _UINT32_(0x00)                                       /*  (GMAC_FT) Frames Transmitted Register  Reset Value */

#define GMAC_FT_FTX_Pos                       _UINT32_(0)                                          /* (GMAC_FT) Frames Transmitted without Error Position */
#define GMAC_FT_FTX_Msk                       (_UINT32_(0xFFFFFFFF) << GMAC_FT_FTX_Pos)            /* (GMAC_FT) Frames Transmitted without Error Mask */
#define GMAC_FT_FTX(value)                    (GMAC_FT_FTX_Msk & (_UINT32_(value) << GMAC_FT_FTX_Pos)) /* Assigment of value for FTX in the GMAC_FT register */
#define GMAC_FT_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (GMAC_FT) Register Mask  */


/* -------- GMAC_BCFT : (GMAC Offset: 0x10C) ( R/ 32) Broadcast Frames Transmitted Register -------- */
#define GMAC_BCFT_RESETVALUE                  _UINT32_(0x00)                                       /*  (GMAC_BCFT) Broadcast Frames Transmitted Register  Reset Value */

#define GMAC_BCFT_BFTX_Pos                    _UINT32_(0)                                          /* (GMAC_BCFT) Broadcast Frames Transmitted without Error Position */
#define GMAC_BCFT_BFTX_Msk                    (_UINT32_(0xFFFFFFFF) << GMAC_BCFT_BFTX_Pos)         /* (GMAC_BCFT) Broadcast Frames Transmitted without Error Mask */
#define GMAC_BCFT_BFTX(value)                 (GMAC_BCFT_BFTX_Msk & (_UINT32_(value) << GMAC_BCFT_BFTX_Pos)) /* Assigment of value for BFTX in the GMAC_BCFT register */
#define GMAC_BCFT_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (GMAC_BCFT) Register Mask  */


/* -------- GMAC_MFT : (GMAC Offset: 0x110) ( R/ 32) Multicast Frames Transmitted Register -------- */
#define GMAC_MFT_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_MFT) Multicast Frames Transmitted Register  Reset Value */

#define GMAC_MFT_MFTX_Pos                     _UINT32_(0)                                          /* (GMAC_MFT) Multicast Frames Transmitted without Error Position */
#define GMAC_MFT_MFTX_Msk                     (_UINT32_(0xFFFFFFFF) << GMAC_MFT_MFTX_Pos)          /* (GMAC_MFT) Multicast Frames Transmitted without Error Mask */
#define GMAC_MFT_MFTX(value)                  (GMAC_MFT_MFTX_Msk & (_UINT32_(value) << GMAC_MFT_MFTX_Pos)) /* Assigment of value for MFTX in the GMAC_MFT register */
#define GMAC_MFT_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (GMAC_MFT) Register Mask  */


/* -------- GMAC_PFT : (GMAC Offset: 0x114) ( R/ 32) Pause Frames Transmitted Register -------- */
#define GMAC_PFT_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_PFT) Pause Frames Transmitted Register  Reset Value */

#define GMAC_PFT_PFTX_Pos                     _UINT32_(0)                                          /* (GMAC_PFT) Pause Frames Transmitted Register Position */
#define GMAC_PFT_PFTX_Msk                     (_UINT32_(0xFFFF) << GMAC_PFT_PFTX_Pos)              /* (GMAC_PFT) Pause Frames Transmitted Register Mask */
#define GMAC_PFT_PFTX(value)                  (GMAC_PFT_PFTX_Msk & (_UINT32_(value) << GMAC_PFT_PFTX_Pos)) /* Assigment of value for PFTX in the GMAC_PFT register */
#define GMAC_PFT_Msk                          _UINT32_(0x0000FFFF)                                 /* (GMAC_PFT) Register Mask  */


/* -------- GMAC_BFT64 : (GMAC Offset: 0x118) ( R/ 32) 64 Byte Frames Transmitted Register -------- */
#define GMAC_BFT64_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_BFT64) 64 Byte Frames Transmitted Register  Reset Value */

#define GMAC_BFT64_NFTX_Pos                   _UINT32_(0)                                          /* (GMAC_BFT64) 64 Byte Frames Transmitted without Error Position */
#define GMAC_BFT64_NFTX_Msk                   (_UINT32_(0xFFFFFFFF) << GMAC_BFT64_NFTX_Pos)        /* (GMAC_BFT64) 64 Byte Frames Transmitted without Error Mask */
#define GMAC_BFT64_NFTX(value)                (GMAC_BFT64_NFTX_Msk & (_UINT32_(value) << GMAC_BFT64_NFTX_Pos)) /* Assigment of value for NFTX in the GMAC_BFT64 register */
#define GMAC_BFT64_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (GMAC_BFT64) Register Mask  */


/* -------- GMAC_TBFT127 : (GMAC Offset: 0x11C) ( R/ 32) 65 to 127 Byte Frames Transmitted Register -------- */
#define GMAC_TBFT127_RESETVALUE               _UINT32_(0x00)                                       /*  (GMAC_TBFT127) 65 to 127 Byte Frames Transmitted Register  Reset Value */

#define GMAC_TBFT127_NFTX_Pos                 _UINT32_(0)                                          /* (GMAC_TBFT127) 65 to 127 Byte Frames Transmitted without Error Position */
#define GMAC_TBFT127_NFTX_Msk                 (_UINT32_(0xFFFFFFFF) << GMAC_TBFT127_NFTX_Pos)      /* (GMAC_TBFT127) 65 to 127 Byte Frames Transmitted without Error Mask */
#define GMAC_TBFT127_NFTX(value)              (GMAC_TBFT127_NFTX_Msk & (_UINT32_(value) << GMAC_TBFT127_NFTX_Pos)) /* Assigment of value for NFTX in the GMAC_TBFT127 register */
#define GMAC_TBFT127_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (GMAC_TBFT127) Register Mask  */


/* -------- GMAC_TBFT255 : (GMAC Offset: 0x120) ( R/ 32) 128 to 255 Byte Frames Transmitted Register -------- */
#define GMAC_TBFT255_RESETVALUE               _UINT32_(0x00)                                       /*  (GMAC_TBFT255) 128 to 255 Byte Frames Transmitted Register  Reset Value */

#define GMAC_TBFT255_NFTX_Pos                 _UINT32_(0)                                          /* (GMAC_TBFT255) 128 to 255 Byte Frames Transmitted without Error Position */
#define GMAC_TBFT255_NFTX_Msk                 (_UINT32_(0xFFFFFFFF) << GMAC_TBFT255_NFTX_Pos)      /* (GMAC_TBFT255) 128 to 255 Byte Frames Transmitted without Error Mask */
#define GMAC_TBFT255_NFTX(value)              (GMAC_TBFT255_NFTX_Msk & (_UINT32_(value) << GMAC_TBFT255_NFTX_Pos)) /* Assigment of value for NFTX in the GMAC_TBFT255 register */
#define GMAC_TBFT255_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (GMAC_TBFT255) Register Mask  */


/* -------- GMAC_TBFT511 : (GMAC Offset: 0x124) ( R/ 32) 256 to 511 Byte Frames Transmitted Register -------- */
#define GMAC_TBFT511_RESETVALUE               _UINT32_(0x00)                                       /*  (GMAC_TBFT511) 256 to 511 Byte Frames Transmitted Register  Reset Value */

#define GMAC_TBFT511_NFTX_Pos                 _UINT32_(0)                                          /* (GMAC_TBFT511) 256 to 511 Byte Frames Transmitted without Error Position */
#define GMAC_TBFT511_NFTX_Msk                 (_UINT32_(0xFFFFFFFF) << GMAC_TBFT511_NFTX_Pos)      /* (GMAC_TBFT511) 256 to 511 Byte Frames Transmitted without Error Mask */
#define GMAC_TBFT511_NFTX(value)              (GMAC_TBFT511_NFTX_Msk & (_UINT32_(value) << GMAC_TBFT511_NFTX_Pos)) /* Assigment of value for NFTX in the GMAC_TBFT511 register */
#define GMAC_TBFT511_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (GMAC_TBFT511) Register Mask  */


/* -------- GMAC_TBFT1023 : (GMAC Offset: 0x128) ( R/ 32) 512 to 1023 Byte Frames Transmitted Register -------- */
#define GMAC_TBFT1023_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_TBFT1023) 512 to 1023 Byte Frames Transmitted Register  Reset Value */

#define GMAC_TBFT1023_NFTX_Pos                _UINT32_(0)                                          /* (GMAC_TBFT1023) 512 to 1023 Byte Frames Transmitted without Error Position */
#define GMAC_TBFT1023_NFTX_Msk                (_UINT32_(0xFFFFFFFF) << GMAC_TBFT1023_NFTX_Pos)     /* (GMAC_TBFT1023) 512 to 1023 Byte Frames Transmitted without Error Mask */
#define GMAC_TBFT1023_NFTX(value)             (GMAC_TBFT1023_NFTX_Msk & (_UINT32_(value) << GMAC_TBFT1023_NFTX_Pos)) /* Assigment of value for NFTX in the GMAC_TBFT1023 register */
#define GMAC_TBFT1023_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (GMAC_TBFT1023) Register Mask  */


/* -------- GMAC_TBFT1518 : (GMAC Offset: 0x12C) ( R/ 32) 1024 to 1518 Byte Frames Transmitted Register -------- */
#define GMAC_TBFT1518_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_TBFT1518) 1024 to 1518 Byte Frames Transmitted Register  Reset Value */

#define GMAC_TBFT1518_NFTX_Pos                _UINT32_(0)                                          /* (GMAC_TBFT1518) 1024 to 1518 Byte Frames Transmitted without Error Position */
#define GMAC_TBFT1518_NFTX_Msk                (_UINT32_(0xFFFFFFFF) << GMAC_TBFT1518_NFTX_Pos)     /* (GMAC_TBFT1518) 1024 to 1518 Byte Frames Transmitted without Error Mask */
#define GMAC_TBFT1518_NFTX(value)             (GMAC_TBFT1518_NFTX_Msk & (_UINT32_(value) << GMAC_TBFT1518_NFTX_Pos)) /* Assigment of value for NFTX in the GMAC_TBFT1518 register */
#define GMAC_TBFT1518_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (GMAC_TBFT1518) Register Mask  */


/* -------- GMAC_GTBFT1518 : (GMAC Offset: 0x130) ( R/ 32) Greater Than 1518 Byte Frames Transmitted Register -------- */
#define GMAC_GTBFT1518_RESETVALUE             _UINT32_(0x00)                                       /*  (GMAC_GTBFT1518) Greater Than 1518 Byte Frames Transmitted Register  Reset Value */

#define GMAC_GTBFT1518_NFTX_Pos               _UINT32_(0)                                          /* (GMAC_GTBFT1518) Greater than 1518 Byte Frames Transmitted without Error Position */
#define GMAC_GTBFT1518_NFTX_Msk               (_UINT32_(0xFFFFFFFF) << GMAC_GTBFT1518_NFTX_Pos)    /* (GMAC_GTBFT1518) Greater than 1518 Byte Frames Transmitted without Error Mask */
#define GMAC_GTBFT1518_NFTX(value)            (GMAC_GTBFT1518_NFTX_Msk & (_UINT32_(value) << GMAC_GTBFT1518_NFTX_Pos)) /* Assigment of value for NFTX in the GMAC_GTBFT1518 register */
#define GMAC_GTBFT1518_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (GMAC_GTBFT1518) Register Mask  */


/* -------- GMAC_TUR : (GMAC Offset: 0x134) ( R/ 32) Transmit Underruns Register -------- */
#define GMAC_TUR_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_TUR) Transmit Underruns Register  Reset Value */

#define GMAC_TUR_TXUNR_Pos                    _UINT32_(0)                                          /* (GMAC_TUR) Transmit Underruns Position */
#define GMAC_TUR_TXUNR_Msk                    (_UINT32_(0x3FF) << GMAC_TUR_TXUNR_Pos)              /* (GMAC_TUR) Transmit Underruns Mask */
#define GMAC_TUR_TXUNR(value)                 (GMAC_TUR_TXUNR_Msk & (_UINT32_(value) << GMAC_TUR_TXUNR_Pos)) /* Assigment of value for TXUNR in the GMAC_TUR register */
#define GMAC_TUR_Msk                          _UINT32_(0x000003FF)                                 /* (GMAC_TUR) Register Mask  */


/* -------- GMAC_SCF : (GMAC Offset: 0x138) ( R/ 32) Single Collision Frames Register -------- */
#define GMAC_SCF_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_SCF) Single Collision Frames Register  Reset Value */

#define GMAC_SCF_SCOL_Pos                     _UINT32_(0)                                          /* (GMAC_SCF) Single Collision Position */
#define GMAC_SCF_SCOL_Msk                     (_UINT32_(0x3FFFF) << GMAC_SCF_SCOL_Pos)             /* (GMAC_SCF) Single Collision Mask */
#define GMAC_SCF_SCOL(value)                  (GMAC_SCF_SCOL_Msk & (_UINT32_(value) << GMAC_SCF_SCOL_Pos)) /* Assigment of value for SCOL in the GMAC_SCF register */
#define GMAC_SCF_Msk                          _UINT32_(0x0003FFFF)                                 /* (GMAC_SCF) Register Mask  */


/* -------- GMAC_MCF : (GMAC Offset: 0x13C) ( R/ 32) Multiple Collision Frames Register -------- */
#define GMAC_MCF_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_MCF) Multiple Collision Frames Register  Reset Value */

#define GMAC_MCF_MCOL_Pos                     _UINT32_(0)                                          /* (GMAC_MCF) Multiple Collision Position */
#define GMAC_MCF_MCOL_Msk                     (_UINT32_(0x3FFFF) << GMAC_MCF_MCOL_Pos)             /* (GMAC_MCF) Multiple Collision Mask */
#define GMAC_MCF_MCOL(value)                  (GMAC_MCF_MCOL_Msk & (_UINT32_(value) << GMAC_MCF_MCOL_Pos)) /* Assigment of value for MCOL in the GMAC_MCF register */
#define GMAC_MCF_Msk                          _UINT32_(0x0003FFFF)                                 /* (GMAC_MCF) Register Mask  */


/* -------- GMAC_EC : (GMAC Offset: 0x140) ( R/ 32) Excessive Collisions Register -------- */
#define GMAC_EC_RESETVALUE                    _UINT32_(0x00)                                       /*  (GMAC_EC) Excessive Collisions Register  Reset Value */

#define GMAC_EC_XCOL_Pos                      _UINT32_(0)                                          /* (GMAC_EC) Excessive Collisions Position */
#define GMAC_EC_XCOL_Msk                      (_UINT32_(0x3FF) << GMAC_EC_XCOL_Pos)                /* (GMAC_EC) Excessive Collisions Mask */
#define GMAC_EC_XCOL(value)                   (GMAC_EC_XCOL_Msk & (_UINT32_(value) << GMAC_EC_XCOL_Pos)) /* Assigment of value for XCOL in the GMAC_EC register */
#define GMAC_EC_Msk                           _UINT32_(0x000003FF)                                 /* (GMAC_EC) Register Mask  */


/* -------- GMAC_LC : (GMAC Offset: 0x144) ( R/ 32) Late Collisions Register -------- */
#define GMAC_LC_RESETVALUE                    _UINT32_(0x00)                                       /*  (GMAC_LC) Late Collisions Register  Reset Value */

#define GMAC_LC_LCOL_Pos                      _UINT32_(0)                                          /* (GMAC_LC) Late Collisions Position */
#define GMAC_LC_LCOL_Msk                      (_UINT32_(0x3FF) << GMAC_LC_LCOL_Pos)                /* (GMAC_LC) Late Collisions Mask */
#define GMAC_LC_LCOL(value)                   (GMAC_LC_LCOL_Msk & (_UINT32_(value) << GMAC_LC_LCOL_Pos)) /* Assigment of value for LCOL in the GMAC_LC register */
#define GMAC_LC_Msk                           _UINT32_(0x000003FF)                                 /* (GMAC_LC) Register Mask  */


/* -------- GMAC_DTF : (GMAC Offset: 0x148) ( R/ 32) Deferred Transmission Frames Register -------- */
#define GMAC_DTF_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_DTF) Deferred Transmission Frames Register  Reset Value */

#define GMAC_DTF_DEFT_Pos                     _UINT32_(0)                                          /* (GMAC_DTF) Deferred Transmission Position */
#define GMAC_DTF_DEFT_Msk                     (_UINT32_(0x3FFFF) << GMAC_DTF_DEFT_Pos)             /* (GMAC_DTF) Deferred Transmission Mask */
#define GMAC_DTF_DEFT(value)                  (GMAC_DTF_DEFT_Msk & (_UINT32_(value) << GMAC_DTF_DEFT_Pos)) /* Assigment of value for DEFT in the GMAC_DTF register */
#define GMAC_DTF_Msk                          _UINT32_(0x0003FFFF)                                 /* (GMAC_DTF) Register Mask  */


/* -------- GMAC_CSE : (GMAC Offset: 0x14C) ( R/ 32) Carrier Sense Errors Register -------- */
#define GMAC_CSE_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_CSE) Carrier Sense Errors Register  Reset Value */

#define GMAC_CSE_CSR_Pos                      _UINT32_(0)                                          /* (GMAC_CSE) Carrier Sense Error Position */
#define GMAC_CSE_CSR_Msk                      (_UINT32_(0x3FF) << GMAC_CSE_CSR_Pos)                /* (GMAC_CSE) Carrier Sense Error Mask */
#define GMAC_CSE_CSR(value)                   (GMAC_CSE_CSR_Msk & (_UINT32_(value) << GMAC_CSE_CSR_Pos)) /* Assigment of value for CSR in the GMAC_CSE register */
#define GMAC_CSE_Msk                          _UINT32_(0x000003FF)                                 /* (GMAC_CSE) Register Mask  */


/* -------- GMAC_ORLO : (GMAC Offset: 0x150) ( R/ 32) Octets Received Low Received Register -------- */
#define GMAC_ORLO_RESETVALUE                  _UINT32_(0x00)                                       /*  (GMAC_ORLO) Octets Received Low Received Register  Reset Value */

#define GMAC_ORLO_RXO_Pos                     _UINT32_(0)                                          /* (GMAC_ORLO) Received Octets Position */
#define GMAC_ORLO_RXO_Msk                     (_UINT32_(0xFFFFFFFF) << GMAC_ORLO_RXO_Pos)          /* (GMAC_ORLO) Received Octets Mask */
#define GMAC_ORLO_RXO(value)                  (GMAC_ORLO_RXO_Msk & (_UINT32_(value) << GMAC_ORLO_RXO_Pos)) /* Assigment of value for RXO in the GMAC_ORLO register */
#define GMAC_ORLO_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (GMAC_ORLO) Register Mask  */


/* -------- GMAC_ORHI : (GMAC Offset: 0x154) ( R/ 32) Octets Received High Received Register -------- */
#define GMAC_ORHI_RESETVALUE                  _UINT32_(0x00)                                       /*  (GMAC_ORHI) Octets Received High Received Register  Reset Value */

#define GMAC_ORHI_RXO_Pos                     _UINT32_(0)                                          /* (GMAC_ORHI) Received Octets Position */
#define GMAC_ORHI_RXO_Msk                     (_UINT32_(0xFFFF) << GMAC_ORHI_RXO_Pos)              /* (GMAC_ORHI) Received Octets Mask */
#define GMAC_ORHI_RXO(value)                  (GMAC_ORHI_RXO_Msk & (_UINT32_(value) << GMAC_ORHI_RXO_Pos)) /* Assigment of value for RXO in the GMAC_ORHI register */
#define GMAC_ORHI_Msk                         _UINT32_(0x0000FFFF)                                 /* (GMAC_ORHI) Register Mask  */


/* -------- GMAC_FR : (GMAC Offset: 0x158) ( R/ 32) Frames Received Register -------- */
#define GMAC_FR_RESETVALUE                    _UINT32_(0x00)                                       /*  (GMAC_FR) Frames Received Register  Reset Value */

#define GMAC_FR_FRX_Pos                       _UINT32_(0)                                          /* (GMAC_FR) Frames Received without Error Position */
#define GMAC_FR_FRX_Msk                       (_UINT32_(0xFFFFFFFF) << GMAC_FR_FRX_Pos)            /* (GMAC_FR) Frames Received without Error Mask */
#define GMAC_FR_FRX(value)                    (GMAC_FR_FRX_Msk & (_UINT32_(value) << GMAC_FR_FRX_Pos)) /* Assigment of value for FRX in the GMAC_FR register */
#define GMAC_FR_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (GMAC_FR) Register Mask  */


/* -------- GMAC_BCFR : (GMAC Offset: 0x15C) ( R/ 32) Broadcast Frames Received Register -------- */
#define GMAC_BCFR_RESETVALUE                  _UINT32_(0x00)                                       /*  (GMAC_BCFR) Broadcast Frames Received Register  Reset Value */

#define GMAC_BCFR_BFRX_Pos                    _UINT32_(0)                                          /* (GMAC_BCFR) Broadcast Frames Received without Error Position */
#define GMAC_BCFR_BFRX_Msk                    (_UINT32_(0xFFFFFFFF) << GMAC_BCFR_BFRX_Pos)         /* (GMAC_BCFR) Broadcast Frames Received without Error Mask */
#define GMAC_BCFR_BFRX(value)                 (GMAC_BCFR_BFRX_Msk & (_UINT32_(value) << GMAC_BCFR_BFRX_Pos)) /* Assigment of value for BFRX in the GMAC_BCFR register */
#define GMAC_BCFR_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (GMAC_BCFR) Register Mask  */


/* -------- GMAC_MFR : (GMAC Offset: 0x160) ( R/ 32) Multicast Frames Received Register -------- */
#define GMAC_MFR_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_MFR) Multicast Frames Received Register  Reset Value */

#define GMAC_MFR_MFRX_Pos                     _UINT32_(0)                                          /* (GMAC_MFR) Multicast Frames Received without Error Position */
#define GMAC_MFR_MFRX_Msk                     (_UINT32_(0xFFFFFFFF) << GMAC_MFR_MFRX_Pos)          /* (GMAC_MFR) Multicast Frames Received without Error Mask */
#define GMAC_MFR_MFRX(value)                  (GMAC_MFR_MFRX_Msk & (_UINT32_(value) << GMAC_MFR_MFRX_Pos)) /* Assigment of value for MFRX in the GMAC_MFR register */
#define GMAC_MFR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (GMAC_MFR) Register Mask  */


/* -------- GMAC_PFR : (GMAC Offset: 0x164) ( R/ 32) Pause Frames Received Register -------- */
#define GMAC_PFR_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_PFR) Pause Frames Received Register  Reset Value */

#define GMAC_PFR_PFRX_Pos                     _UINT32_(0)                                          /* (GMAC_PFR) Pause Frames Received Register Position */
#define GMAC_PFR_PFRX_Msk                     (_UINT32_(0xFFFF) << GMAC_PFR_PFRX_Pos)              /* (GMAC_PFR) Pause Frames Received Register Mask */
#define GMAC_PFR_PFRX(value)                  (GMAC_PFR_PFRX_Msk & (_UINT32_(value) << GMAC_PFR_PFRX_Pos)) /* Assigment of value for PFRX in the GMAC_PFR register */
#define GMAC_PFR_Msk                          _UINT32_(0x0000FFFF)                                 /* (GMAC_PFR) Register Mask  */


/* -------- GMAC_BFR64 : (GMAC Offset: 0x168) ( R/ 32) 64 Byte Frames Received Register -------- */
#define GMAC_BFR64_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_BFR64) 64 Byte Frames Received Register  Reset Value */

#define GMAC_BFR64_NFRX_Pos                   _UINT32_(0)                                          /* (GMAC_BFR64) 64 Byte Frames Received without Error Position */
#define GMAC_BFR64_NFRX_Msk                   (_UINT32_(0xFFFFFFFF) << GMAC_BFR64_NFRX_Pos)        /* (GMAC_BFR64) 64 Byte Frames Received without Error Mask */
#define GMAC_BFR64_NFRX(value)                (GMAC_BFR64_NFRX_Msk & (_UINT32_(value) << GMAC_BFR64_NFRX_Pos)) /* Assigment of value for NFRX in the GMAC_BFR64 register */
#define GMAC_BFR64_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (GMAC_BFR64) Register Mask  */


/* -------- GMAC_TBFR127 : (GMAC Offset: 0x16C) ( R/ 32) 65 to 127 Byte Frames Received Register -------- */
#define GMAC_TBFR127_RESETVALUE               _UINT32_(0x00)                                       /*  (GMAC_TBFR127) 65 to 127 Byte Frames Received Register  Reset Value */

#define GMAC_TBFR127_NFRX_Pos                 _UINT32_(0)                                          /* (GMAC_TBFR127) 65 to 127 Byte Frames Received without Error Position */
#define GMAC_TBFR127_NFRX_Msk                 (_UINT32_(0xFFFFFFFF) << GMAC_TBFR127_NFRX_Pos)      /* (GMAC_TBFR127) 65 to 127 Byte Frames Received without Error Mask */
#define GMAC_TBFR127_NFRX(value)              (GMAC_TBFR127_NFRX_Msk & (_UINT32_(value) << GMAC_TBFR127_NFRX_Pos)) /* Assigment of value for NFRX in the GMAC_TBFR127 register */
#define GMAC_TBFR127_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (GMAC_TBFR127) Register Mask  */


/* -------- GMAC_TBFR255 : (GMAC Offset: 0x170) ( R/ 32) 128 to 255 Byte Frames Received Register -------- */
#define GMAC_TBFR255_RESETVALUE               _UINT32_(0x00)                                       /*  (GMAC_TBFR255) 128 to 255 Byte Frames Received Register  Reset Value */

#define GMAC_TBFR255_NFRX_Pos                 _UINT32_(0)                                          /* (GMAC_TBFR255) 128 to 255 Byte Frames Received without Error Position */
#define GMAC_TBFR255_NFRX_Msk                 (_UINT32_(0xFFFFFFFF) << GMAC_TBFR255_NFRX_Pos)      /* (GMAC_TBFR255) 128 to 255 Byte Frames Received without Error Mask */
#define GMAC_TBFR255_NFRX(value)              (GMAC_TBFR255_NFRX_Msk & (_UINT32_(value) << GMAC_TBFR255_NFRX_Pos)) /* Assigment of value for NFRX in the GMAC_TBFR255 register */
#define GMAC_TBFR255_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (GMAC_TBFR255) Register Mask  */


/* -------- GMAC_TBFR511 : (GMAC Offset: 0x174) ( R/ 32) 256 to 511 Byte Frames Received Register -------- */
#define GMAC_TBFR511_RESETVALUE               _UINT32_(0x00)                                       /*  (GMAC_TBFR511) 256 to 511 Byte Frames Received Register  Reset Value */

#define GMAC_TBFR511_NFRX_Pos                 _UINT32_(0)                                          /* (GMAC_TBFR511) 256 to 511 Byte Frames Received without Error Position */
#define GMAC_TBFR511_NFRX_Msk                 (_UINT32_(0xFFFFFFFF) << GMAC_TBFR511_NFRX_Pos)      /* (GMAC_TBFR511) 256 to 511 Byte Frames Received without Error Mask */
#define GMAC_TBFR511_NFRX(value)              (GMAC_TBFR511_NFRX_Msk & (_UINT32_(value) << GMAC_TBFR511_NFRX_Pos)) /* Assigment of value for NFRX in the GMAC_TBFR511 register */
#define GMAC_TBFR511_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (GMAC_TBFR511) Register Mask  */


/* -------- GMAC_TBFR1023 : (GMAC Offset: 0x178) ( R/ 32) 512 to 1023 Byte Frames Received Register -------- */
#define GMAC_TBFR1023_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_TBFR1023) 512 to 1023 Byte Frames Received Register  Reset Value */

#define GMAC_TBFR1023_NFRX_Pos                _UINT32_(0)                                          /* (GMAC_TBFR1023) 512 to 1023 Byte Frames Received without Error Position */
#define GMAC_TBFR1023_NFRX_Msk                (_UINT32_(0xFFFFFFFF) << GMAC_TBFR1023_NFRX_Pos)     /* (GMAC_TBFR1023) 512 to 1023 Byte Frames Received without Error Mask */
#define GMAC_TBFR1023_NFRX(value)             (GMAC_TBFR1023_NFRX_Msk & (_UINT32_(value) << GMAC_TBFR1023_NFRX_Pos)) /* Assigment of value for NFRX in the GMAC_TBFR1023 register */
#define GMAC_TBFR1023_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (GMAC_TBFR1023) Register Mask  */


/* -------- GMAC_TBFR1518 : (GMAC Offset: 0x17C) ( R/ 32) 1024 to 1518 Byte Frames Received Register -------- */
#define GMAC_TBFR1518_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_TBFR1518) 1024 to 1518 Byte Frames Received Register  Reset Value */

#define GMAC_TBFR1518_NFRX_Pos                _UINT32_(0)                                          /* (GMAC_TBFR1518) 1024 to 1518 Byte Frames Received without Error Position */
#define GMAC_TBFR1518_NFRX_Msk                (_UINT32_(0xFFFFFFFF) << GMAC_TBFR1518_NFRX_Pos)     /* (GMAC_TBFR1518) 1024 to 1518 Byte Frames Received without Error Mask */
#define GMAC_TBFR1518_NFRX(value)             (GMAC_TBFR1518_NFRX_Msk & (_UINT32_(value) << GMAC_TBFR1518_NFRX_Pos)) /* Assigment of value for NFRX in the GMAC_TBFR1518 register */
#define GMAC_TBFR1518_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (GMAC_TBFR1518) Register Mask  */


/* -------- GMAC_TMXBFR : (GMAC Offset: 0x180) ( R/ 32) 1519 to Maximum Byte Frames Received Register -------- */
#define GMAC_TMXBFR_RESETVALUE                _UINT32_(0x00)                                       /*  (GMAC_TMXBFR) 1519 to Maximum Byte Frames Received Register  Reset Value */

#define GMAC_TMXBFR_NFRX_Pos                  _UINT32_(0)                                          /* (GMAC_TMXBFR) 1519 to Maximum Byte Frames Received without Error Position */
#define GMAC_TMXBFR_NFRX_Msk                  (_UINT32_(0xFFFFFFFF) << GMAC_TMXBFR_NFRX_Pos)       /* (GMAC_TMXBFR) 1519 to Maximum Byte Frames Received without Error Mask */
#define GMAC_TMXBFR_NFRX(value)               (GMAC_TMXBFR_NFRX_Msk & (_UINT32_(value) << GMAC_TMXBFR_NFRX_Pos)) /* Assigment of value for NFRX in the GMAC_TMXBFR register */
#define GMAC_TMXBFR_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (GMAC_TMXBFR) Register Mask  */


/* -------- GMAC_UFR : (GMAC Offset: 0x184) ( R/ 32) Undersize Frames Received Register -------- */
#define GMAC_UFR_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_UFR) Undersize Frames Received Register  Reset Value */

#define GMAC_UFR_UFRX_Pos                     _UINT32_(0)                                          /* (GMAC_UFR) Undersize Frames Received Position */
#define GMAC_UFR_UFRX_Msk                     (_UINT32_(0x3FF) << GMAC_UFR_UFRX_Pos)               /* (GMAC_UFR) Undersize Frames Received Mask */
#define GMAC_UFR_UFRX(value)                  (GMAC_UFR_UFRX_Msk & (_UINT32_(value) << GMAC_UFR_UFRX_Pos)) /* Assigment of value for UFRX in the GMAC_UFR register */
#define GMAC_UFR_Msk                          _UINT32_(0x000003FF)                                 /* (GMAC_UFR) Register Mask  */


/* -------- GMAC_OFR : (GMAC Offset: 0x188) ( R/ 32) Oversize Frames Received Register -------- */
#define GMAC_OFR_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_OFR) Oversize Frames Received Register  Reset Value */

#define GMAC_OFR_OFRX_Pos                     _UINT32_(0)                                          /* (GMAC_OFR) Oversized Frames Received Position */
#define GMAC_OFR_OFRX_Msk                     (_UINT32_(0x3FF) << GMAC_OFR_OFRX_Pos)               /* (GMAC_OFR) Oversized Frames Received Mask */
#define GMAC_OFR_OFRX(value)                  (GMAC_OFR_OFRX_Msk & (_UINT32_(value) << GMAC_OFR_OFRX_Pos)) /* Assigment of value for OFRX in the GMAC_OFR register */
#define GMAC_OFR_Msk                          _UINT32_(0x000003FF)                                 /* (GMAC_OFR) Register Mask  */


/* -------- GMAC_JR : (GMAC Offset: 0x18C) ( R/ 32) Jabbers Received Register -------- */
#define GMAC_JR_RESETVALUE                    _UINT32_(0x00)                                       /*  (GMAC_JR) Jabbers Received Register  Reset Value */

#define GMAC_JR_JRX_Pos                       _UINT32_(0)                                          /* (GMAC_JR) Jabbers Received Position */
#define GMAC_JR_JRX_Msk                       (_UINT32_(0x3FF) << GMAC_JR_JRX_Pos)                 /* (GMAC_JR) Jabbers Received Mask */
#define GMAC_JR_JRX(value)                    (GMAC_JR_JRX_Msk & (_UINT32_(value) << GMAC_JR_JRX_Pos)) /* Assigment of value for JRX in the GMAC_JR register */
#define GMAC_JR_Msk                           _UINT32_(0x000003FF)                                 /* (GMAC_JR) Register Mask  */


/* -------- GMAC_FCSE : (GMAC Offset: 0x190) ( R/ 32) Frame Check Sequence Errors Register -------- */
#define GMAC_FCSE_RESETVALUE                  _UINT32_(0x00)                                       /*  (GMAC_FCSE) Frame Check Sequence Errors Register  Reset Value */

#define GMAC_FCSE_FCKR_Pos                    _UINT32_(0)                                          /* (GMAC_FCSE) Frame Check Sequence Errors Position */
#define GMAC_FCSE_FCKR_Msk                    (_UINT32_(0x3FF) << GMAC_FCSE_FCKR_Pos)              /* (GMAC_FCSE) Frame Check Sequence Errors Mask */
#define GMAC_FCSE_FCKR(value)                 (GMAC_FCSE_FCKR_Msk & (_UINT32_(value) << GMAC_FCSE_FCKR_Pos)) /* Assigment of value for FCKR in the GMAC_FCSE register */
#define GMAC_FCSE_Msk                         _UINT32_(0x000003FF)                                 /* (GMAC_FCSE) Register Mask  */


/* -------- GMAC_LFFE : (GMAC Offset: 0x194) ( R/ 32) Length Field Frame Errors Register -------- */
#define GMAC_LFFE_RESETVALUE                  _UINT32_(0x00)                                       /*  (GMAC_LFFE) Length Field Frame Errors Register  Reset Value */

#define GMAC_LFFE_LFER_Pos                    _UINT32_(0)                                          /* (GMAC_LFFE) Length Field Frame Errors Position */
#define GMAC_LFFE_LFER_Msk                    (_UINT32_(0x3FF) << GMAC_LFFE_LFER_Pos)              /* (GMAC_LFFE) Length Field Frame Errors Mask */
#define GMAC_LFFE_LFER(value)                 (GMAC_LFFE_LFER_Msk & (_UINT32_(value) << GMAC_LFFE_LFER_Pos)) /* Assigment of value for LFER in the GMAC_LFFE register */
#define GMAC_LFFE_Msk                         _UINT32_(0x000003FF)                                 /* (GMAC_LFFE) Register Mask  */


/* -------- GMAC_RSE : (GMAC Offset: 0x198) ( R/ 32) Receive Symbol Errors Register -------- */
#define GMAC_RSE_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_RSE) Receive Symbol Errors Register  Reset Value */

#define GMAC_RSE_RXSE_Pos                     _UINT32_(0)                                          /* (GMAC_RSE) Receive Symbol Errors Position */
#define GMAC_RSE_RXSE_Msk                     (_UINT32_(0x3FF) << GMAC_RSE_RXSE_Pos)               /* (GMAC_RSE) Receive Symbol Errors Mask */
#define GMAC_RSE_RXSE(value)                  (GMAC_RSE_RXSE_Msk & (_UINT32_(value) << GMAC_RSE_RXSE_Pos)) /* Assigment of value for RXSE in the GMAC_RSE register */
#define GMAC_RSE_Msk                          _UINT32_(0x000003FF)                                 /* (GMAC_RSE) Register Mask  */


/* -------- GMAC_AE : (GMAC Offset: 0x19C) ( R/ 32) Alignment Errors Register -------- */
#define GMAC_AE_RESETVALUE                    _UINT32_(0x00)                                       /*  (GMAC_AE) Alignment Errors Register  Reset Value */

#define GMAC_AE_AER_Pos                       _UINT32_(0)                                          /* (GMAC_AE) Alignment Errors Position */
#define GMAC_AE_AER_Msk                       (_UINT32_(0x3FF) << GMAC_AE_AER_Pos)                 /* (GMAC_AE) Alignment Errors Mask */
#define GMAC_AE_AER(value)                    (GMAC_AE_AER_Msk & (_UINT32_(value) << GMAC_AE_AER_Pos)) /* Assigment of value for AER in the GMAC_AE register */
#define GMAC_AE_Msk                           _UINT32_(0x000003FF)                                 /* (GMAC_AE) Register Mask  */


/* -------- GMAC_RRE : (GMAC Offset: 0x1A0) ( R/ 32) Receive Resource Errors Register -------- */
#define GMAC_RRE_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_RRE) Receive Resource Errors Register  Reset Value */

#define GMAC_RRE_RXRER_Pos                    _UINT32_(0)                                          /* (GMAC_RRE) Receive Resource Errors Position */
#define GMAC_RRE_RXRER_Msk                    (_UINT32_(0x3FFFF) << GMAC_RRE_RXRER_Pos)            /* (GMAC_RRE) Receive Resource Errors Mask */
#define GMAC_RRE_RXRER(value)                 (GMAC_RRE_RXRER_Msk & (_UINT32_(value) << GMAC_RRE_RXRER_Pos)) /* Assigment of value for RXRER in the GMAC_RRE register */
#define GMAC_RRE_Msk                          _UINT32_(0x0003FFFF)                                 /* (GMAC_RRE) Register Mask  */


/* -------- GMAC_ROE : (GMAC Offset: 0x1A4) ( R/ 32) Receive Overrun Register -------- */
#define GMAC_ROE_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_ROE) Receive Overrun Register  Reset Value */

#define GMAC_ROE_RXOVR_Pos                    _UINT32_(0)                                          /* (GMAC_ROE) Receive Overruns Position */
#define GMAC_ROE_RXOVR_Msk                    (_UINT32_(0x3FF) << GMAC_ROE_RXOVR_Pos)              /* (GMAC_ROE) Receive Overruns Mask */
#define GMAC_ROE_RXOVR(value)                 (GMAC_ROE_RXOVR_Msk & (_UINT32_(value) << GMAC_ROE_RXOVR_Pos)) /* Assigment of value for RXOVR in the GMAC_ROE register */
#define GMAC_ROE_Msk                          _UINT32_(0x000003FF)                                 /* (GMAC_ROE) Register Mask  */


/* -------- GMAC_IHCE : (GMAC Offset: 0x1A8) ( R/ 32) IP Header Checksum Errors Register -------- */
#define GMAC_IHCE_RESETVALUE                  _UINT32_(0x00)                                       /*  (GMAC_IHCE) IP Header Checksum Errors Register  Reset Value */

#define GMAC_IHCE_HCKER_Pos                   _UINT32_(0)                                          /* (GMAC_IHCE) IP Header Checksum Errors Position */
#define GMAC_IHCE_HCKER_Msk                   (_UINT32_(0xFF) << GMAC_IHCE_HCKER_Pos)              /* (GMAC_IHCE) IP Header Checksum Errors Mask */
#define GMAC_IHCE_HCKER(value)                (GMAC_IHCE_HCKER_Msk & (_UINT32_(value) << GMAC_IHCE_HCKER_Pos)) /* Assigment of value for HCKER in the GMAC_IHCE register */
#define GMAC_IHCE_Msk                         _UINT32_(0x000000FF)                                 /* (GMAC_IHCE) Register Mask  */


/* -------- GMAC_TCE : (GMAC Offset: 0x1AC) ( R/ 32) TCP Checksum Errors Register -------- */
#define GMAC_TCE_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_TCE) TCP Checksum Errors Register  Reset Value */

#define GMAC_TCE_TCKER_Pos                    _UINT32_(0)                                          /* (GMAC_TCE) TCP Checksum Errors Position */
#define GMAC_TCE_TCKER_Msk                    (_UINT32_(0xFF) << GMAC_TCE_TCKER_Pos)               /* (GMAC_TCE) TCP Checksum Errors Mask */
#define GMAC_TCE_TCKER(value)                 (GMAC_TCE_TCKER_Msk & (_UINT32_(value) << GMAC_TCE_TCKER_Pos)) /* Assigment of value for TCKER in the GMAC_TCE register */
#define GMAC_TCE_Msk                          _UINT32_(0x000000FF)                                 /* (GMAC_TCE) Register Mask  */


/* -------- GMAC_UCE : (GMAC Offset: 0x1B0) ( R/ 32) UDP Checksum Errors Register -------- */
#define GMAC_UCE_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_UCE) UDP Checksum Errors Register  Reset Value */

#define GMAC_UCE_UCKER_Pos                    _UINT32_(0)                                          /* (GMAC_UCE) UDP Checksum Errors Position */
#define GMAC_UCE_UCKER_Msk                    (_UINT32_(0xFF) << GMAC_UCE_UCKER_Pos)               /* (GMAC_UCE) UDP Checksum Errors Mask */
#define GMAC_UCE_UCKER(value)                 (GMAC_UCE_UCKER_Msk & (_UINT32_(value) << GMAC_UCE_UCKER_Pos)) /* Assigment of value for UCKER in the GMAC_UCE register */
#define GMAC_UCE_Msk                          _UINT32_(0x000000FF)                                 /* (GMAC_UCE) Register Mask  */


/* -------- GMAC_FLRXPCR : (GMAC Offset: 0x1B4) ( R/ 32) Flushed Received Packets Counter Register -------- */
#define GMAC_FLRXPCR_RESETVALUE               _UINT32_(0x00)                                       /*  (GMAC_FLRXPCR) Flushed Received Packets Counter Register  Reset Value */

#define GMAC_FLRXPCR_COUNT_Pos                _UINT32_(0)                                          /* (GMAC_FLRXPCR) Flushed Received Packets Count (cleared on read) Position */
#define GMAC_FLRXPCR_COUNT_Msk                (_UINT32_(0xFFFF) << GMAC_FLRXPCR_COUNT_Pos)         /* (GMAC_FLRXPCR) Flushed Received Packets Count (cleared on read) Mask */
#define GMAC_FLRXPCR_COUNT(value)             (GMAC_FLRXPCR_COUNT_Msk & (_UINT32_(value) << GMAC_FLRXPCR_COUNT_Pos)) /* Assigment of value for COUNT in the GMAC_FLRXPCR register */
#define GMAC_FLRXPCR_Msk                      _UINT32_(0x0000FFFF)                                 /* (GMAC_FLRXPCR) Register Mask  */


/* -------- GMAC_TISUBN : (GMAC Offset: 0x1BC) (R/W 32) 1588 Timer Increment Sub-nanoseconds Register -------- */
#define GMAC_TISUBN_RESETVALUE                _UINT32_(0x00)                                       /*  (GMAC_TISUBN) 1588 Timer Increment Sub-nanoseconds Register  Reset Value */

#define GMAC_TISUBN_MSBTIR_Pos                _UINT32_(0)                                          /* (GMAC_TISUBN) Most Significant Bits of Timer Increment Register Position */
#define GMAC_TISUBN_MSBTIR_Msk                (_UINT32_(0xFFFF) << GMAC_TISUBN_MSBTIR_Pos)         /* (GMAC_TISUBN) Most Significant Bits of Timer Increment Register Mask */
#define GMAC_TISUBN_MSBTIR(value)             (GMAC_TISUBN_MSBTIR_Msk & (_UINT32_(value) << GMAC_TISUBN_MSBTIR_Pos)) /* Assigment of value for MSBTIR in the GMAC_TISUBN register */
#define GMAC_TISUBN_LSBTIR_Pos                _UINT32_(24)                                         /* (GMAC_TISUBN) Lower Significant Bits of Timer Increment Register Position */
#define GMAC_TISUBN_LSBTIR_Msk                (_UINT32_(0xFF) << GMAC_TISUBN_LSBTIR_Pos)           /* (GMAC_TISUBN) Lower Significant Bits of Timer Increment Register Mask */
#define GMAC_TISUBN_LSBTIR(value)             (GMAC_TISUBN_LSBTIR_Msk & (_UINT32_(value) << GMAC_TISUBN_LSBTIR_Pos)) /* Assigment of value for LSBTIR in the GMAC_TISUBN register */
#define GMAC_TISUBN_Msk                       _UINT32_(0xFF00FFFF)                                 /* (GMAC_TISUBN) Register Mask  */


/* -------- GMAC_TSH : (GMAC Offset: 0x1C0) (R/W 32) 1588 Timer Seconds High Register -------- */
#define GMAC_TSH_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_TSH) 1588 Timer Seconds High Register  Reset Value */

#define GMAC_TSH_TCS_Pos                      _UINT32_(0)                                          /* (GMAC_TSH) Timer Count in Seconds Position */
#define GMAC_TSH_TCS_Msk                      (_UINT32_(0xFFFF) << GMAC_TSH_TCS_Pos)               /* (GMAC_TSH) Timer Count in Seconds Mask */
#define GMAC_TSH_TCS(value)                   (GMAC_TSH_TCS_Msk & (_UINT32_(value) << GMAC_TSH_TCS_Pos)) /* Assigment of value for TCS in the GMAC_TSH register */
#define GMAC_TSH_Msk                          _UINT32_(0x0000FFFF)                                 /* (GMAC_TSH) Register Mask  */


/* -------- GMAC_TSL : (GMAC Offset: 0x1D0) (R/W 32) 1588 Timer Seconds Low Register -------- */
#define GMAC_TSL_RESETVALUE                   _UINT32_(0x00)                                       /*  (GMAC_TSL) 1588 Timer Seconds Low Register  Reset Value */

#define GMAC_TSL_TCS_Pos                      _UINT32_(0)                                          /* (GMAC_TSL) Timer Count in Seconds Position */
#define GMAC_TSL_TCS_Msk                      (_UINT32_(0xFFFFFFFF) << GMAC_TSL_TCS_Pos)           /* (GMAC_TSL) Timer Count in Seconds Mask */
#define GMAC_TSL_TCS(value)                   (GMAC_TSL_TCS_Msk & (_UINT32_(value) << GMAC_TSL_TCS_Pos)) /* Assigment of value for TCS in the GMAC_TSL register */
#define GMAC_TSL_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (GMAC_TSL) Register Mask  */


/* -------- GMAC_TN : (GMAC Offset: 0x1D4) (R/W 32) 1588 Timer Nanoseconds Register -------- */
#define GMAC_TN_RESETVALUE                    _UINT32_(0x00)                                       /*  (GMAC_TN) 1588 Timer Nanoseconds Register  Reset Value */

#define GMAC_TN_TNS_Pos                       _UINT32_(0)                                          /* (GMAC_TN) Timer Count in Nanoseconds Position */
#define GMAC_TN_TNS_Msk                       (_UINT32_(0x3FFFFFFF) << GMAC_TN_TNS_Pos)            /* (GMAC_TN) Timer Count in Nanoseconds Mask */
#define GMAC_TN_TNS(value)                    (GMAC_TN_TNS_Msk & (_UINT32_(value) << GMAC_TN_TNS_Pos)) /* Assigment of value for TNS in the GMAC_TN register */
#define GMAC_TN_Msk                           _UINT32_(0x3FFFFFFF)                                 /* (GMAC_TN) Register Mask  */


/* -------- GMAC_TA : (GMAC Offset: 0x1D8) ( /W 32) 1588 Timer Adjust Register -------- */
#define GMAC_TA_ITDT_Pos                      _UINT32_(0)                                          /* (GMAC_TA) Increment/Decrement Position */
#define GMAC_TA_ITDT_Msk                      (_UINT32_(0x3FFFFFFF) << GMAC_TA_ITDT_Pos)           /* (GMAC_TA) Increment/Decrement Mask */
#define GMAC_TA_ITDT(value)                   (GMAC_TA_ITDT_Msk & (_UINT32_(value) << GMAC_TA_ITDT_Pos)) /* Assigment of value for ITDT in the GMAC_TA register */
#define GMAC_TA_ADJ_Pos                       _UINT32_(31)                                         /* (GMAC_TA) Adjust 1588 Timer Position */
#define GMAC_TA_ADJ_Msk                       (_UINT32_(0x1) << GMAC_TA_ADJ_Pos)                   /* (GMAC_TA) Adjust 1588 Timer Mask */
#define GMAC_TA_ADJ(value)                    (GMAC_TA_ADJ_Msk & (_UINT32_(value) << GMAC_TA_ADJ_Pos)) /* Assigment of value for ADJ in the GMAC_TA register */
#define GMAC_TA_Msk                           _UINT32_(0xBFFFFFFF)                                 /* (GMAC_TA) Register Mask  */


/* -------- GMAC_TI : (GMAC Offset: 0x1DC) (R/W 32) 1588 Timer Increment Register -------- */
#define GMAC_TI_RESETVALUE                    _UINT32_(0x00)                                       /*  (GMAC_TI) 1588 Timer Increment Register  Reset Value */

#define GMAC_TI_CNS_Pos                       _UINT32_(0)                                          /* (GMAC_TI) Count Nanoseconds Position */
#define GMAC_TI_CNS_Msk                       (_UINT32_(0xFF) << GMAC_TI_CNS_Pos)                  /* (GMAC_TI) Count Nanoseconds Mask */
#define GMAC_TI_CNS(value)                    (GMAC_TI_CNS_Msk & (_UINT32_(value) << GMAC_TI_CNS_Pos)) /* Assigment of value for CNS in the GMAC_TI register */
#define GMAC_TI_ACNS_Pos                      _UINT32_(8)                                          /* (GMAC_TI) Alternative Count Nanoseconds Position */
#define GMAC_TI_ACNS_Msk                      (_UINT32_(0xFF) << GMAC_TI_ACNS_Pos)                 /* (GMAC_TI) Alternative Count Nanoseconds Mask */
#define GMAC_TI_ACNS(value)                   (GMAC_TI_ACNS_Msk & (_UINT32_(value) << GMAC_TI_ACNS_Pos)) /* Assigment of value for ACNS in the GMAC_TI register */
#define GMAC_TI_NIT_Pos                       _UINT32_(16)                                         /* (GMAC_TI) Number of Increments Position */
#define GMAC_TI_NIT_Msk                       (_UINT32_(0xFF) << GMAC_TI_NIT_Pos)                  /* (GMAC_TI) Number of Increments Mask */
#define GMAC_TI_NIT(value)                    (GMAC_TI_NIT_Msk & (_UINT32_(value) << GMAC_TI_NIT_Pos)) /* Assigment of value for NIT in the GMAC_TI register */
#define GMAC_TI_Msk                           _UINT32_(0x00FFFFFF)                                 /* (GMAC_TI) Register Mask  */


/* -------- GMAC_EFTSL : (GMAC Offset: 0x1E0) ( R/ 32) PTP Event Frame Transmitted Seconds Low Register -------- */
#define GMAC_EFTSL_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_EFTSL) PTP Event Frame Transmitted Seconds Low Register  Reset Value */

#define GMAC_EFTSL_RUD_Pos                    _UINT32_(0)                                          /* (GMAC_EFTSL) Register Update Position */
#define GMAC_EFTSL_RUD_Msk                    (_UINT32_(0xFFFFFFFF) << GMAC_EFTSL_RUD_Pos)         /* (GMAC_EFTSL) Register Update Mask */
#define GMAC_EFTSL_RUD(value)                 (GMAC_EFTSL_RUD_Msk & (_UINT32_(value) << GMAC_EFTSL_RUD_Pos)) /* Assigment of value for RUD in the GMAC_EFTSL register */
#define GMAC_EFTSL_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EFTSL) Register Mask  */


/* -------- GMAC_EFTN : (GMAC Offset: 0x1E4) ( R/ 32) PTP Event Frame Transmitted Nanoseconds Register -------- */
#define GMAC_EFTN_RESETVALUE                  _UINT32_(0x00)                                       /*  (GMAC_EFTN) PTP Event Frame Transmitted Nanoseconds Register  Reset Value */

#define GMAC_EFTN_RUD_Pos                     _UINT32_(0)                                          /* (GMAC_EFTN) Register Update Position */
#define GMAC_EFTN_RUD_Msk                     (_UINT32_(0x3FFFFFFF) << GMAC_EFTN_RUD_Pos)          /* (GMAC_EFTN) Register Update Mask */
#define GMAC_EFTN_RUD(value)                  (GMAC_EFTN_RUD_Msk & (_UINT32_(value) << GMAC_EFTN_RUD_Pos)) /* Assigment of value for RUD in the GMAC_EFTN register */
#define GMAC_EFTN_Msk                         _UINT32_(0x3FFFFFFF)                                 /* (GMAC_EFTN) Register Mask  */


/* -------- GMAC_EFRSL : (GMAC Offset: 0x1E8) ( R/ 32) PTP Event Frame Received Seconds Low Register -------- */
#define GMAC_EFRSL_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_EFRSL) PTP Event Frame Received Seconds Low Register  Reset Value */

#define GMAC_EFRSL_RUD_Pos                    _UINT32_(0)                                          /* (GMAC_EFRSL) Register Update Position */
#define GMAC_EFRSL_RUD_Msk                    (_UINT32_(0xFFFFFFFF) << GMAC_EFRSL_RUD_Pos)         /* (GMAC_EFRSL) Register Update Mask */
#define GMAC_EFRSL_RUD(value)                 (GMAC_EFRSL_RUD_Msk & (_UINT32_(value) << GMAC_EFRSL_RUD_Pos)) /* Assigment of value for RUD in the GMAC_EFRSL register */
#define GMAC_EFRSL_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EFRSL) Register Mask  */


/* -------- GMAC_EFRN : (GMAC Offset: 0x1EC) ( R/ 32) PTP Event Frame Received Nanoseconds Register -------- */
#define GMAC_EFRN_RESETVALUE                  _UINT32_(0x00)                                       /*  (GMAC_EFRN) PTP Event Frame Received Nanoseconds Register  Reset Value */

#define GMAC_EFRN_RUD_Pos                     _UINT32_(0)                                          /* (GMAC_EFRN) Register Update Position */
#define GMAC_EFRN_RUD_Msk                     (_UINT32_(0x3FFFFFFF) << GMAC_EFRN_RUD_Pos)          /* (GMAC_EFRN) Register Update Mask */
#define GMAC_EFRN_RUD(value)                  (GMAC_EFRN_RUD_Msk & (_UINT32_(value) << GMAC_EFRN_RUD_Pos)) /* Assigment of value for RUD in the GMAC_EFRN register */
#define GMAC_EFRN_Msk                         _UINT32_(0x3FFFFFFF)                                 /* (GMAC_EFRN) Register Mask  */


/* -------- GMAC_PEFTSL : (GMAC Offset: 0x1F0) ( R/ 32) PTP Peer Event Frame Transmitted Seconds Low Register -------- */
#define GMAC_PEFTSL_RESETVALUE                _UINT32_(0x00)                                       /*  (GMAC_PEFTSL) PTP Peer Event Frame Transmitted Seconds Low Register  Reset Value */

#define GMAC_PEFTSL_RUD_Pos                   _UINT32_(0)                                          /* (GMAC_PEFTSL) Register Update Position */
#define GMAC_PEFTSL_RUD_Msk                   (_UINT32_(0xFFFFFFFF) << GMAC_PEFTSL_RUD_Pos)        /* (GMAC_PEFTSL) Register Update Mask */
#define GMAC_PEFTSL_RUD(value)                (GMAC_PEFTSL_RUD_Msk & (_UINT32_(value) << GMAC_PEFTSL_RUD_Pos)) /* Assigment of value for RUD in the GMAC_PEFTSL register */
#define GMAC_PEFTSL_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (GMAC_PEFTSL) Register Mask  */


/* -------- GMAC_PEFTN : (GMAC Offset: 0x1F4) ( R/ 32) PTP Peer Event Frame Transmitted Nanoseconds Register -------- */
#define GMAC_PEFTN_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_PEFTN) PTP Peer Event Frame Transmitted Nanoseconds Register  Reset Value */

#define GMAC_PEFTN_RUD_Pos                    _UINT32_(0)                                          /* (GMAC_PEFTN) Register Update Position */
#define GMAC_PEFTN_RUD_Msk                    (_UINT32_(0x3FFFFFFF) << GMAC_PEFTN_RUD_Pos)         /* (GMAC_PEFTN) Register Update Mask */
#define GMAC_PEFTN_RUD(value)                 (GMAC_PEFTN_RUD_Msk & (_UINT32_(value) << GMAC_PEFTN_RUD_Pos)) /* Assigment of value for RUD in the GMAC_PEFTN register */
#define GMAC_PEFTN_Msk                        _UINT32_(0x3FFFFFFF)                                 /* (GMAC_PEFTN) Register Mask  */


/* -------- GMAC_PEFRSL : (GMAC Offset: 0x1F8) ( R/ 32) PTP Peer Event Frame Received Seconds Low Register -------- */
#define GMAC_PEFRSL_RESETVALUE                _UINT32_(0x00)                                       /*  (GMAC_PEFRSL) PTP Peer Event Frame Received Seconds Low Register  Reset Value */

#define GMAC_PEFRSL_RUD_Pos                   _UINT32_(0)                                          /* (GMAC_PEFRSL) Register Update Position */
#define GMAC_PEFRSL_RUD_Msk                   (_UINT32_(0xFFFFFFFF) << GMAC_PEFRSL_RUD_Pos)        /* (GMAC_PEFRSL) Register Update Mask */
#define GMAC_PEFRSL_RUD(value)                (GMAC_PEFRSL_RUD_Msk & (_UINT32_(value) << GMAC_PEFRSL_RUD_Pos)) /* Assigment of value for RUD in the GMAC_PEFRSL register */
#define GMAC_PEFRSL_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (GMAC_PEFRSL) Register Mask  */


/* -------- GMAC_PEFRN : (GMAC Offset: 0x1FC) ( R/ 32) PTP Peer Event Frame Received Nanoseconds Register -------- */
#define GMAC_PEFRN_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_PEFRN) PTP Peer Event Frame Received Nanoseconds Register  Reset Value */

#define GMAC_PEFRN_RUD_Pos                    _UINT32_(0)                                          /* (GMAC_PEFRN) Register Update Position */
#define GMAC_PEFRN_RUD_Msk                    (_UINT32_(0x3FFFFFFF) << GMAC_PEFRN_RUD_Pos)         /* (GMAC_PEFRN) Register Update Mask */
#define GMAC_PEFRN_RUD(value)                 (GMAC_PEFRN_RUD_Msk & (_UINT32_(value) << GMAC_PEFRN_RUD_Pos)) /* Assigment of value for RUD in the GMAC_PEFRN register */
#define GMAC_PEFRN_Msk                        _UINT32_(0x3FFFFFFF)                                 /* (GMAC_PEFRN) Register Mask  */


/* -------- GMAC_RXLPI : (GMAC Offset: 0x270) ( R/ 32) Received LPI Transitions -------- */
#define GMAC_RXLPI_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_RXLPI) Received LPI Transitions  Reset Value */

#define GMAC_RXLPI_COUNT_Pos                  _UINT32_(0)                                          /* (GMAC_RXLPI) Count of Received LPI transitions (cleared on read) Position */
#define GMAC_RXLPI_COUNT_Msk                  (_UINT32_(0xFFFF) << GMAC_RXLPI_COUNT_Pos)           /* (GMAC_RXLPI) Count of Received LPI transitions (cleared on read) Mask */
#define GMAC_RXLPI_COUNT(value)               (GMAC_RXLPI_COUNT_Msk & (_UINT32_(value) << GMAC_RXLPI_COUNT_Pos)) /* Assigment of value for COUNT in the GMAC_RXLPI register */
#define GMAC_RXLPI_Msk                        _UINT32_(0x0000FFFF)                                 /* (GMAC_RXLPI) Register Mask  */


/* -------- GMAC_RXLPITIME : (GMAC Offset: 0x274) ( R/ 32) Received LPI Time -------- */
#define GMAC_RXLPITIME_RESETVALUE             _UINT32_(0x00)                                       /*  (GMAC_RXLPITIME) Received LPI Time  Reset Value */

#define GMAC_RXLPITIME_LPITIME_Pos            _UINT32_(0)                                          /* (GMAC_RXLPITIME) Time in LPI (cleared on read) Position */
#define GMAC_RXLPITIME_LPITIME_Msk            (_UINT32_(0xFFFFFF) << GMAC_RXLPITIME_LPITIME_Pos)   /* (GMAC_RXLPITIME) Time in LPI (cleared on read) Mask */
#define GMAC_RXLPITIME_LPITIME(value)         (GMAC_RXLPITIME_LPITIME_Msk & (_UINT32_(value) << GMAC_RXLPITIME_LPITIME_Pos)) /* Assigment of value for LPITIME in the GMAC_RXLPITIME register */
#define GMAC_RXLPITIME_Msk                    _UINT32_(0x00FFFFFF)                                 /* (GMAC_RXLPITIME) Register Mask  */


/* -------- GMAC_TXLPI : (GMAC Offset: 0x278) ( R/ 32) Transmit LPI Transitions -------- */
#define GMAC_TXLPI_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_TXLPI) Transmit LPI Transitions  Reset Value */

#define GMAC_TXLPI_COUNT_Pos                  _UINT32_(0)                                          /* (GMAC_TXLPI) Count of LPI transitions (cleared on read) Position */
#define GMAC_TXLPI_COUNT_Msk                  (_UINT32_(0xFFFF) << GMAC_TXLPI_COUNT_Pos)           /* (GMAC_TXLPI) Count of LPI transitions (cleared on read) Mask */
#define GMAC_TXLPI_COUNT(value)               (GMAC_TXLPI_COUNT_Msk & (_UINT32_(value) << GMAC_TXLPI_COUNT_Pos)) /* Assigment of value for COUNT in the GMAC_TXLPI register */
#define GMAC_TXLPI_Msk                        _UINT32_(0x0000FFFF)                                 /* (GMAC_TXLPI) Register Mask  */


/* -------- GMAC_TXLPITIME : (GMAC Offset: 0x27C) ( R/ 32) Transmit LPI Time -------- */
#define GMAC_TXLPITIME_RESETVALUE             _UINT32_(0x00)                                       /*  (GMAC_TXLPITIME) Transmit LPI Time  Reset Value */

#define GMAC_TXLPITIME_LPITIME_Pos            _UINT32_(0)                                          /* (GMAC_TXLPITIME) Time in LPI (cleared on read) Position */
#define GMAC_TXLPITIME_LPITIME_Msk            (_UINT32_(0xFFFFFF) << GMAC_TXLPITIME_LPITIME_Pos)   /* (GMAC_TXLPITIME) Time in LPI (cleared on read) Mask */
#define GMAC_TXLPITIME_LPITIME(value)         (GMAC_TXLPITIME_LPITIME_Msk & (_UINT32_(value) << GMAC_TXLPITIME_LPITIME_Pos)) /* Assigment of value for LPITIME in the GMAC_TXLPITIME register */
#define GMAC_TXLPITIME_Msk                    _UINT32_(0x00FFFFFF)                                 /* (GMAC_TXLPITIME) Register Mask  */


/* -------- GMAC_ISRPQ : (GMAC Offset: 0x400) ( R/ 32) Interrupt Status Register Priority Queue (index = 1) -------- */
#define GMAC_ISRPQ_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_ISRPQ) Interrupt Status Register Priority Queue (index = 1)  Reset Value */

#define GMAC_ISRPQ_RCOMP_Pos                  _UINT32_(1)                                          /* (GMAC_ISRPQ) Receive Complete Position */
#define GMAC_ISRPQ_RCOMP_Msk                  (_UINT32_(0x1) << GMAC_ISRPQ_RCOMP_Pos)              /* (GMAC_ISRPQ) Receive Complete Mask */
#define GMAC_ISRPQ_RCOMP(value)               (GMAC_ISRPQ_RCOMP_Msk & (_UINT32_(value) << GMAC_ISRPQ_RCOMP_Pos)) /* Assigment of value for RCOMP in the GMAC_ISRPQ register */
#define GMAC_ISRPQ_RXUBR_Pos                  _UINT32_(2)                                          /* (GMAC_ISRPQ) RX Used Bit Read Position */
#define GMAC_ISRPQ_RXUBR_Msk                  (_UINT32_(0x1) << GMAC_ISRPQ_RXUBR_Pos)              /* (GMAC_ISRPQ) RX Used Bit Read Mask */
#define GMAC_ISRPQ_RXUBR(value)               (GMAC_ISRPQ_RXUBR_Msk & (_UINT32_(value) << GMAC_ISRPQ_RXUBR_Pos)) /* Assigment of value for RXUBR in the GMAC_ISRPQ register */
#define GMAC_ISRPQ_RLEX_Pos                   _UINT32_(5)                                          /* (GMAC_ISRPQ) Retry Limit Exceeded or Late Collision Position */
#define GMAC_ISRPQ_RLEX_Msk                   (_UINT32_(0x1) << GMAC_ISRPQ_RLEX_Pos)               /* (GMAC_ISRPQ) Retry Limit Exceeded or Late Collision Mask */
#define GMAC_ISRPQ_RLEX(value)                (GMAC_ISRPQ_RLEX_Msk & (_UINT32_(value) << GMAC_ISRPQ_RLEX_Pos)) /* Assigment of value for RLEX in the GMAC_ISRPQ register */
#define GMAC_ISRPQ_TFC_Pos                    _UINT32_(6)                                          /* (GMAC_ISRPQ) Transmit Frame Corruption Due to System Bus Error Position */
#define GMAC_ISRPQ_TFC_Msk                    (_UINT32_(0x1) << GMAC_ISRPQ_TFC_Pos)                /* (GMAC_ISRPQ) Transmit Frame Corruption Due to System Bus Error Mask */
#define GMAC_ISRPQ_TFC(value)                 (GMAC_ISRPQ_TFC_Msk & (_UINT32_(value) << GMAC_ISRPQ_TFC_Pos)) /* Assigment of value for TFC in the GMAC_ISRPQ register */
#define GMAC_ISRPQ_TCOMP_Pos                  _UINT32_(7)                                          /* (GMAC_ISRPQ) Transmit Complete Position */
#define GMAC_ISRPQ_TCOMP_Msk                  (_UINT32_(0x1) << GMAC_ISRPQ_TCOMP_Pos)              /* (GMAC_ISRPQ) Transmit Complete Mask */
#define GMAC_ISRPQ_TCOMP(value)               (GMAC_ISRPQ_TCOMP_Msk & (_UINT32_(value) << GMAC_ISRPQ_TCOMP_Pos)) /* Assigment of value for TCOMP in the GMAC_ISRPQ register */
#define GMAC_ISRPQ_HRESP_Pos                  _UINT32_(11)                                         /* (GMAC_ISRPQ) System Bus Error Position */
#define GMAC_ISRPQ_HRESP_Msk                  (_UINT32_(0x1) << GMAC_ISRPQ_HRESP_Pos)              /* (GMAC_ISRPQ) System Bus Error Mask */
#define GMAC_ISRPQ_HRESP(value)               (GMAC_ISRPQ_HRESP_Msk & (_UINT32_(value) << GMAC_ISRPQ_HRESP_Pos)) /* Assigment of value for HRESP in the GMAC_ISRPQ register */
#define GMAC_ISRPQ_Msk                        _UINT32_(0x000008E6)                                 /* (GMAC_ISRPQ) Register Mask  */


/* -------- GMAC_TBQBAPQ : (GMAC Offset: 0x440) (R/W 32) Transmit Buffer Queue Base Address Register Priority Queue (index = 1) -------- */
#define GMAC_TBQBAPQ_RESETVALUE               _UINT32_(0x00)                                       /*  (GMAC_TBQBAPQ) Transmit Buffer Queue Base Address Register Priority Queue (index = 1)  Reset Value */

#define GMAC_TBQBAPQ_TXBQDIS_Pos              _UINT32_(0)                                          /* (GMAC_TBQBAPQ) Transmit Buffer Queue Disable Position */
#define GMAC_TBQBAPQ_TXBQDIS_Msk              (_UINT32_(0x1) << GMAC_TBQBAPQ_TXBQDIS_Pos)          /* (GMAC_TBQBAPQ) Transmit Buffer Queue Disable Mask */
#define GMAC_TBQBAPQ_TXBQDIS(value)           (GMAC_TBQBAPQ_TXBQDIS_Msk & (_UINT32_(value) << GMAC_TBQBAPQ_TXBQDIS_Pos)) /* Assigment of value for TXBQDIS in the GMAC_TBQBAPQ register */
#define   GMAC_TBQBAPQ_TXBQDIS_0_Val          _UINT32_(0x0)                                        /* (GMAC_TBQBAPQ) No effect.  */
#define   GMAC_TBQBAPQ_TXBQDIS_1_Val          _UINT32_(0x1)                                        /* (GMAC_TBQBAPQ) Disables the transmit queue. This can be used to reduce the number of active queues and must be changed only while transmit is disabled.  */
#define GMAC_TBQBAPQ_TXBQDIS_0                (GMAC_TBQBAPQ_TXBQDIS_0_Val << GMAC_TBQBAPQ_TXBQDIS_Pos) /* (GMAC_TBQBAPQ) No effect. Position  */
#define GMAC_TBQBAPQ_TXBQDIS_1                (GMAC_TBQBAPQ_TXBQDIS_1_Val << GMAC_TBQBAPQ_TXBQDIS_Pos) /* (GMAC_TBQBAPQ) Disables the transmit queue. This can be used to reduce the number of active queues and must be changed only while transmit is disabled. Position  */
#define GMAC_TBQBAPQ_TXBQBA_Pos               _UINT32_(2)                                          /* (GMAC_TBQBAPQ) Transmit Buffer Queue Base Address Position */
#define GMAC_TBQBAPQ_TXBQBA_Msk               (_UINT32_(0x3FFFFFFF) << GMAC_TBQBAPQ_TXBQBA_Pos)    /* (GMAC_TBQBAPQ) Transmit Buffer Queue Base Address Mask */
#define GMAC_TBQBAPQ_TXBQBA(value)            (GMAC_TBQBAPQ_TXBQBA_Msk & (_UINT32_(value) << GMAC_TBQBAPQ_TXBQBA_Pos)) /* Assigment of value for TXBQBA in the GMAC_TBQBAPQ register */
#define GMAC_TBQBAPQ_Msk                      _UINT32_(0xFFFFFFFD)                                 /* (GMAC_TBQBAPQ) Register Mask  */


/* -------- GMAC_RBQBAPQ : (GMAC Offset: 0x480) (R/W 32) Receive Buffer Queue Base Address Register Priority Queue (index = 1) -------- */
#define GMAC_RBQBAPQ_RESETVALUE               _UINT32_(0x00)                                       /*  (GMAC_RBQBAPQ) Receive Buffer Queue Base Address Register Priority Queue (index = 1)  Reset Value */

#define GMAC_RBQBAPQ_RXBQDIS_Pos              _UINT32_(0)                                          /* (GMAC_RBQBAPQ) Receive Buffer Queue Disable Position */
#define GMAC_RBQBAPQ_RXBQDIS_Msk              (_UINT32_(0x1) << GMAC_RBQBAPQ_RXBQDIS_Pos)          /* (GMAC_RBQBAPQ) Receive Buffer Queue Disable Mask */
#define GMAC_RBQBAPQ_RXBQDIS(value)           (GMAC_RBQBAPQ_RXBQDIS_Msk & (_UINT32_(value) << GMAC_RBQBAPQ_RXBQDIS_Pos)) /* Assigment of value for RXBQDIS in the GMAC_RBQBAPQ register */
#define   GMAC_RBQBAPQ_RXBQDIS_0_Val          _UINT32_(0x0)                                        /* (GMAC_RBQBAPQ) No effect.  */
#define   GMAC_RBQBAPQ_RXBQDIS_1_Val          _UINT32_(0x1)                                        /* (GMAC_RBQBAPQ) Disables the receive queue. This can be used to reduce the number of active queues and must be changed only while receive is disabled.  */
#define GMAC_RBQBAPQ_RXBQDIS_0                (GMAC_RBQBAPQ_RXBQDIS_0_Val << GMAC_RBQBAPQ_RXBQDIS_Pos) /* (GMAC_RBQBAPQ) No effect. Position  */
#define GMAC_RBQBAPQ_RXBQDIS_1                (GMAC_RBQBAPQ_RXBQDIS_1_Val << GMAC_RBQBAPQ_RXBQDIS_Pos) /* (GMAC_RBQBAPQ) Disables the receive queue. This can be used to reduce the number of active queues and must be changed only while receive is disabled. Position  */
#define GMAC_RBQBAPQ_RXBQBA_Pos               _UINT32_(2)                                          /* (GMAC_RBQBAPQ) Receive Buffer Queue Base Address Position */
#define GMAC_RBQBAPQ_RXBQBA_Msk               (_UINT32_(0x3FFFFFFF) << GMAC_RBQBAPQ_RXBQBA_Pos)    /* (GMAC_RBQBAPQ) Receive Buffer Queue Base Address Mask */
#define GMAC_RBQBAPQ_RXBQBA(value)            (GMAC_RBQBAPQ_RXBQBA_Msk & (_UINT32_(value) << GMAC_RBQBAPQ_RXBQBA_Pos)) /* Assigment of value for RXBQBA in the GMAC_RBQBAPQ register */
#define GMAC_RBQBAPQ_Msk                      _UINT32_(0xFFFFFFFD)                                 /* (GMAC_RBQBAPQ) Register Mask  */


/* -------- GMAC_RBSRPQ : (GMAC Offset: 0x4A0) (R/W 32) Receive Buffer Size Register Priority Queue (index = 1) -------- */
#define GMAC_RBSRPQ_RESETVALUE                _UINT32_(0x02)                                       /*  (GMAC_RBSRPQ) Receive Buffer Size Register Priority Queue (index = 1)  Reset Value */

#define GMAC_RBSRPQ_RBS_Pos                   _UINT32_(0)                                          /* (GMAC_RBSRPQ) Receive Buffer Size Position */
#define GMAC_RBSRPQ_RBS_Msk                   (_UINT32_(0xFF) << GMAC_RBSRPQ_RBS_Pos)              /* (GMAC_RBSRPQ) Receive Buffer Size Mask */
#define GMAC_RBSRPQ_RBS(value)                (GMAC_RBSRPQ_RBS_Msk & (_UINT32_(value) << GMAC_RBSRPQ_RBS_Pos)) /* Assigment of value for RBS in the GMAC_RBSRPQ register */
#define   GMAC_RBSRPQ_RBS_0x02_Val            _UINT32_(0x2)                                        /* (GMAC_RBSRPQ) 128 bytes  */
#define   GMAC_RBSRPQ_RBS_0x18_Val            _UINT32_(0x18)                                       /* (GMAC_RBSRPQ) 1536 bytes (1 x max length frame/buffer)  */
#define   GMAC_RBSRPQ_RBS_0xA0_Val            _UINT32_(0xA0)                                       /* (GMAC_RBSRPQ) 10240 bytes (1 x 10K jumbo frame/buffer)  */
#define GMAC_RBSRPQ_RBS_0x02                  (GMAC_RBSRPQ_RBS_0x02_Val << GMAC_RBSRPQ_RBS_Pos)    /* (GMAC_RBSRPQ) 128 bytes Position  */
#define GMAC_RBSRPQ_RBS_0x18                  (GMAC_RBSRPQ_RBS_0x18_Val << GMAC_RBSRPQ_RBS_Pos)    /* (GMAC_RBSRPQ) 1536 bytes (1 x max length frame/buffer) Position  */
#define GMAC_RBSRPQ_RBS_0xA0                  (GMAC_RBSRPQ_RBS_0xA0_Val << GMAC_RBSRPQ_RBS_Pos)    /* (GMAC_RBSRPQ) 10240 bytes (1 x 10K jumbo frame/buffer) Position  */
#define GMAC_RBSRPQ_Msk                       _UINT32_(0x000000FF)                                 /* (GMAC_RBSRPQ) Register Mask  */


/* -------- GMAC_CBSCR : (GMAC Offset: 0x4BC) (R/W 32) Credit-Based Shaping Control Register -------- */
#define GMAC_CBSCR_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_CBSCR) Credit-Based Shaping Control Register  Reset Value */

#define GMAC_CBSCR_QAE_Pos                    _UINT32_(0)                                          /* (GMAC_CBSCR) Queue A CBS Enable Position */
#define GMAC_CBSCR_QAE_Msk                    (_UINT32_(0x1) << GMAC_CBSCR_QAE_Pos)                /* (GMAC_CBSCR) Queue A CBS Enable Mask */
#define GMAC_CBSCR_QAE(value)                 (GMAC_CBSCR_QAE_Msk & (_UINT32_(value) << GMAC_CBSCR_QAE_Pos)) /* Assigment of value for QAE in the GMAC_CBSCR register */
#define   GMAC_CBSCR_QAE_0_Val                _UINT32_(0x0)                                        /* (GMAC_CBSCR) Credit-based shaping on the second highest priority queue (queue A) is disabled.  */
#define   GMAC_CBSCR_QAE_1_Val                _UINT32_(0x1)                                        /* (GMAC_CBSCR) Credit-based shaping on the second highest priority queue (queue A) is enabled.  */
#define GMAC_CBSCR_QAE_0                      (GMAC_CBSCR_QAE_0_Val << GMAC_CBSCR_QAE_Pos)         /* (GMAC_CBSCR) Credit-based shaping on the second highest priority queue (queue A) is disabled. Position  */
#define GMAC_CBSCR_QAE_1                      (GMAC_CBSCR_QAE_1_Val << GMAC_CBSCR_QAE_Pos)         /* (GMAC_CBSCR) Credit-based shaping on the second highest priority queue (queue A) is enabled. Position  */
#define GMAC_CBSCR_QBE_Pos                    _UINT32_(1)                                          /* (GMAC_CBSCR) Queue B CBS Enable Position */
#define GMAC_CBSCR_QBE_Msk                    (_UINT32_(0x1) << GMAC_CBSCR_QBE_Pos)                /* (GMAC_CBSCR) Queue B CBS Enable Mask */
#define GMAC_CBSCR_QBE(value)                 (GMAC_CBSCR_QBE_Msk & (_UINT32_(value) << GMAC_CBSCR_QBE_Pos)) /* Assigment of value for QBE in the GMAC_CBSCR register */
#define   GMAC_CBSCR_QBE_0_Val                _UINT32_(0x0)                                        /* (GMAC_CBSCR) Credit-based shaping on the highest priority queue (queue B) is disabled.  */
#define   GMAC_CBSCR_QBE_1_Val                _UINT32_(0x1)                                        /* (GMAC_CBSCR) Credit-based shaping on the highest priority queue (queue B) is enabled.  */
#define GMAC_CBSCR_QBE_0                      (GMAC_CBSCR_QBE_0_Val << GMAC_CBSCR_QBE_Pos)         /* (GMAC_CBSCR) Credit-based shaping on the highest priority queue (queue B) is disabled. Position  */
#define GMAC_CBSCR_QBE_1                      (GMAC_CBSCR_QBE_1_Val << GMAC_CBSCR_QBE_Pos)         /* (GMAC_CBSCR) Credit-based shaping on the highest priority queue (queue B) is enabled. Position  */
#define GMAC_CBSCR_Msk                        _UINT32_(0x00000003)                                 /* (GMAC_CBSCR) Register Mask  */


/* -------- GMAC_CBSISQA : (GMAC Offset: 0x4C0) (R/W 32) Credit-Based Shaping IdleSlope Register for Queue A -------- */
#define GMAC_CBSISQA_RESETVALUE               _UINT32_(0x00)                                       /*  (GMAC_CBSISQA) Credit-Based Shaping IdleSlope Register for Queue A  Reset Value */

#define GMAC_CBSISQA_IS_Pos                   _UINT32_(0)                                          /* (GMAC_CBSISQA) IdleSlope Position */
#define GMAC_CBSISQA_IS_Msk                   (_UINT32_(0xFFFFFFFF) << GMAC_CBSISQA_IS_Pos)        /* (GMAC_CBSISQA) IdleSlope Mask */
#define GMAC_CBSISQA_IS(value)                (GMAC_CBSISQA_IS_Msk & (_UINT32_(value) << GMAC_CBSISQA_IS_Pos)) /* Assigment of value for IS in the GMAC_CBSISQA register */
#define GMAC_CBSISQA_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (GMAC_CBSISQA) Register Mask  */


/* -------- GMAC_CBSISQB : (GMAC Offset: 0x4C4) (R/W 32) Credit-Based Shaping IdleSlope Register for Queue B -------- */
#define GMAC_CBSISQB_RESETVALUE               _UINT32_(0x00)                                       /*  (GMAC_CBSISQB) Credit-Based Shaping IdleSlope Register for Queue B  Reset Value */

#define GMAC_CBSISQB_IS_Pos                   _UINT32_(0)                                          /* (GMAC_CBSISQB) IdleSlope Position */
#define GMAC_CBSISQB_IS_Msk                   (_UINT32_(0xFFFFFFFF) << GMAC_CBSISQB_IS_Pos)        /* (GMAC_CBSISQB) IdleSlope Mask */
#define GMAC_CBSISQB_IS(value)                (GMAC_CBSISQB_IS_Msk & (_UINT32_(value) << GMAC_CBSISQB_IS_Pos)) /* Assigment of value for IS in the GMAC_CBSISQB register */
#define GMAC_CBSISQB_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (GMAC_CBSISQB) Register Mask  */


/* -------- GMAC_TQUBA : (GMAC Offset: 0x4C8) (R/W 32) 32 MSB Transmit Buffer Descriptor Queue Base Address Register -------- */
#define GMAC_TQUBA_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_TQUBA) 32 MSB Transmit Buffer Descriptor Queue Base Address Register  Reset Value */

#define GMAC_TQUBA_TQUBA_Pos                  _UINT32_(0)                                          /* (GMAC_TQUBA) Transmit Queue Upper Buffer Address Position */
#define GMAC_TQUBA_TQUBA_Msk                  (_UINT32_(0xFFFFFFFF) << GMAC_TQUBA_TQUBA_Pos)       /* (GMAC_TQUBA) Transmit Queue Upper Buffer Address Mask */
#define GMAC_TQUBA_TQUBA(value)               (GMAC_TQUBA_TQUBA_Msk & (_UINT32_(value) << GMAC_TQUBA_TQUBA_Pos)) /* Assigment of value for TQUBA in the GMAC_TQUBA register */
#define GMAC_TQUBA_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (GMAC_TQUBA) Register Mask  */


/* -------- GMAC_TXBDCTRL : (GMAC Offset: 0x4CC) (R/W 32) Transmit Buffer Data Control Register -------- */
#define GMAC_TXBDCTRL_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_TXBDCTRL) Transmit Buffer Data Control Register  Reset Value */

#define GMAC_TXBDCTRL_TSMODE_Pos              _UINT32_(4)                                          /* (GMAC_TXBDCTRL) Transmit Descriptor Timestamp Insertion Mode Position */
#define GMAC_TXBDCTRL_TSMODE_Msk              (_UINT32_(0x3) << GMAC_TXBDCTRL_TSMODE_Pos)          /* (GMAC_TXBDCTRL) Transmit Descriptor Timestamp Insertion Mode Mask */
#define GMAC_TXBDCTRL_TSMODE(value)           (GMAC_TXBDCTRL_TSMODE_Msk & (_UINT32_(value) << GMAC_TXBDCTRL_TSMODE_Pos)) /* Assigment of value for TSMODE in the GMAC_TXBDCTRL register */
#define   GMAC_TXBDCTRL_TSMODE_DISABLE_Val    _UINT32_(0x0)                                        /* (GMAC_TXBDCTRL) Timestamp insertion disable.  */
#define   GMAC_TXBDCTRL_TSMODE_PTPEVENT_Val   _UINT32_(0x1)                                        /* (GMAC_TXBDCTRL) Timestamp inserted for PTP Event Frames only.  */
#define   GMAC_TXBDCTRL_TSMODE_PTPALL_Val     _UINT32_(0x2)                                        /* (GMAC_TXBDCTRL) Timestamp inserted for All PTP Frames only.  */
#define   GMAC_TXBDCTRL_TSMODE_ALL_Val        _UINT32_(0x3)                                        /* (GMAC_TXBDCTRL) Timestamp inserted for All Frames.  */
#define GMAC_TXBDCTRL_TSMODE_DISABLE          (GMAC_TXBDCTRL_TSMODE_DISABLE_Val << GMAC_TXBDCTRL_TSMODE_Pos) /* (GMAC_TXBDCTRL) Timestamp insertion disable. Position  */
#define GMAC_TXBDCTRL_TSMODE_PTPEVENT         (GMAC_TXBDCTRL_TSMODE_PTPEVENT_Val << GMAC_TXBDCTRL_TSMODE_Pos) /* (GMAC_TXBDCTRL) Timestamp inserted for PTP Event Frames only. Position  */
#define GMAC_TXBDCTRL_TSMODE_PTPALL           (GMAC_TXBDCTRL_TSMODE_PTPALL_Val << GMAC_TXBDCTRL_TSMODE_Pos) /* (GMAC_TXBDCTRL) Timestamp inserted for All PTP Frames only. Position  */
#define GMAC_TXBDCTRL_TSMODE_ALL              (GMAC_TXBDCTRL_TSMODE_ALL_Val << GMAC_TXBDCTRL_TSMODE_Pos) /* (GMAC_TXBDCTRL) Timestamp inserted for All Frames. Position  */
#define GMAC_TXBDCTRL_Msk                     _UINT32_(0x00000030)                                 /* (GMAC_TXBDCTRL) Register Mask  */


/* -------- GMAC_RXBDCTRL : (GMAC Offset: 0x4D0) (R/W 32) Receive Buffer Data Control Register -------- */
#define GMAC_RXBDCTRL_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_RXBDCTRL) Receive Buffer Data Control Register  Reset Value */

#define GMAC_RXBDCTRL_TSMODE_Pos              _UINT32_(4)                                          /* (GMAC_RXBDCTRL) Receive Descriptor Timestamp Insertion Mode Position */
#define GMAC_RXBDCTRL_TSMODE_Msk              (_UINT32_(0x3) << GMAC_RXBDCTRL_TSMODE_Pos)          /* (GMAC_RXBDCTRL) Receive Descriptor Timestamp Insertion Mode Mask */
#define GMAC_RXBDCTRL_TSMODE(value)           (GMAC_RXBDCTRL_TSMODE_Msk & (_UINT32_(value) << GMAC_RXBDCTRL_TSMODE_Pos)) /* Assigment of value for TSMODE in the GMAC_RXBDCTRL register */
#define   GMAC_RXBDCTRL_TSMODE_DISABLE_Val    _UINT32_(0x0)                                        /* (GMAC_RXBDCTRL) Timestamp insertion disable.  */
#define   GMAC_RXBDCTRL_TSMODE_PTPEVENT_Val   _UINT32_(0x1)                                        /* (GMAC_RXBDCTRL) Timestamp inserted for PTP Event Frames only.  */
#define   GMAC_RXBDCTRL_TSMODE_PTPALL_Val     _UINT32_(0x2)                                        /* (GMAC_RXBDCTRL) Timestamp inserted for All PTP Frames only.  */
#define   GMAC_RXBDCTRL_TSMODE_ALL_Val        _UINT32_(0x3)                                        /* (GMAC_RXBDCTRL) Timestamp inserted for All Frames.  */
#define GMAC_RXBDCTRL_TSMODE_DISABLE          (GMAC_RXBDCTRL_TSMODE_DISABLE_Val << GMAC_RXBDCTRL_TSMODE_Pos) /* (GMAC_RXBDCTRL) Timestamp insertion disable. Position  */
#define GMAC_RXBDCTRL_TSMODE_PTPEVENT         (GMAC_RXBDCTRL_TSMODE_PTPEVENT_Val << GMAC_RXBDCTRL_TSMODE_Pos) /* (GMAC_RXBDCTRL) Timestamp inserted for PTP Event Frames only. Position  */
#define GMAC_RXBDCTRL_TSMODE_PTPALL           (GMAC_RXBDCTRL_TSMODE_PTPALL_Val << GMAC_RXBDCTRL_TSMODE_Pos) /* (GMAC_RXBDCTRL) Timestamp inserted for All PTP Frames only. Position  */
#define GMAC_RXBDCTRL_TSMODE_ALL              (GMAC_RXBDCTRL_TSMODE_ALL_Val << GMAC_RXBDCTRL_TSMODE_Pos) /* (GMAC_RXBDCTRL) Timestamp inserted for All Frames. Position  */
#define GMAC_RXBDCTRL_Msk                     _UINT32_(0x00000030)                                 /* (GMAC_RXBDCTRL) Register Mask  */


/* -------- GMAC_RQUBA : (GMAC Offset: 0x4D4) (R/W 32) 32 MSB Receive Buffer Descriptor Queue Base Address Register -------- */
#define GMAC_RQUBA_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_RQUBA) 32 MSB Receive Buffer Descriptor Queue Base Address Register  Reset Value */

#define GMAC_RQUBA_RQUBA_Pos                  _UINT32_(0)                                          /* (GMAC_RQUBA) Receive Queue Upper Buffer Address Position */
#define GMAC_RQUBA_RQUBA_Msk                  (_UINT32_(0xFFFFFFFF) << GMAC_RQUBA_RQUBA_Pos)       /* (GMAC_RQUBA) Receive Queue Upper Buffer Address Mask */
#define GMAC_RQUBA_RQUBA(value)               (GMAC_RQUBA_RQUBA_Msk & (_UINT32_(value) << GMAC_RQUBA_RQUBA_Pos)) /* Assigment of value for RQUBA in the GMAC_RQUBA register */
#define GMAC_RQUBA_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (GMAC_RQUBA) Register Mask  */


/* -------- GMAC_ST1RPQ : (GMAC Offset: 0x500) (R/W 32) Screening Type 1 Register Priority Queue (index = 0) -------- */
#define GMAC_ST1RPQ_RESETVALUE                _UINT32_(0x00)                                       /*  (GMAC_ST1RPQ) Screening Type 1 Register Priority Queue (index = 0)  Reset Value */

#define GMAC_ST1RPQ_QNB_Pos                   _UINT32_(0)                                          /* (GMAC_ST1RPQ) Queue Number (0-5) Position */
#define GMAC_ST1RPQ_QNB_Msk                   (_UINT32_(0x7) << GMAC_ST1RPQ_QNB_Pos)               /* (GMAC_ST1RPQ) Queue Number (0-5) Mask */
#define GMAC_ST1RPQ_QNB(value)                (GMAC_ST1RPQ_QNB_Msk & (_UINT32_(value) << GMAC_ST1RPQ_QNB_Pos)) /* Assigment of value for QNB in the GMAC_ST1RPQ register */
#define GMAC_ST1RPQ_DSTCM_Pos                 _UINT32_(4)                                          /* (GMAC_ST1RPQ) Differentiated Services or Traffic Class Match Position */
#define GMAC_ST1RPQ_DSTCM_Msk                 (_UINT32_(0xFF) << GMAC_ST1RPQ_DSTCM_Pos)            /* (GMAC_ST1RPQ) Differentiated Services or Traffic Class Match Mask */
#define GMAC_ST1RPQ_DSTCM(value)              (GMAC_ST1RPQ_DSTCM_Msk & (_UINT32_(value) << GMAC_ST1RPQ_DSTCM_Pos)) /* Assigment of value for DSTCM in the GMAC_ST1RPQ register */
#define GMAC_ST1RPQ_UDPM_Pos                  _UINT32_(12)                                         /* (GMAC_ST1RPQ) UDP Port Match Position */
#define GMAC_ST1RPQ_UDPM_Msk                  (_UINT32_(0xFFFF) << GMAC_ST1RPQ_UDPM_Pos)           /* (GMAC_ST1RPQ) UDP Port Match Mask */
#define GMAC_ST1RPQ_UDPM(value)               (GMAC_ST1RPQ_UDPM_Msk & (_UINT32_(value) << GMAC_ST1RPQ_UDPM_Pos)) /* Assigment of value for UDPM in the GMAC_ST1RPQ register */
#define GMAC_ST1RPQ_DSTCE_Pos                 _UINT32_(28)                                         /* (GMAC_ST1RPQ) Differentiated Services or Traffic Class Match Enable Position */
#define GMAC_ST1RPQ_DSTCE_Msk                 (_UINT32_(0x1) << GMAC_ST1RPQ_DSTCE_Pos)             /* (GMAC_ST1RPQ) Differentiated Services or Traffic Class Match Enable Mask */
#define GMAC_ST1RPQ_DSTCE(value)              (GMAC_ST1RPQ_DSTCE_Msk & (_UINT32_(value) << GMAC_ST1RPQ_DSTCE_Pos)) /* Assigment of value for DSTCE in the GMAC_ST1RPQ register */
#define GMAC_ST1RPQ_UDPE_Pos                  _UINT32_(29)                                         /* (GMAC_ST1RPQ) UDP Port Match Enable Position */
#define GMAC_ST1RPQ_UDPE_Msk                  (_UINT32_(0x1) << GMAC_ST1RPQ_UDPE_Pos)              /* (GMAC_ST1RPQ) UDP Port Match Enable Mask */
#define GMAC_ST1RPQ_UDPE(value)               (GMAC_ST1RPQ_UDPE_Msk & (_UINT32_(value) << GMAC_ST1RPQ_UDPE_Pos)) /* Assigment of value for UDPE in the GMAC_ST1RPQ register */
#define GMAC_ST1RPQ_Msk                       _UINT32_(0x3FFFFFF7)                                 /* (GMAC_ST1RPQ) Register Mask  */


/* -------- GMAC_ST2RPQ : (GMAC Offset: 0x540) (R/W 32) Screening Type 2 Register Priority Queue (index = 0) -------- */
#define GMAC_ST2RPQ_RESETVALUE                _UINT32_(0x00)                                       /*  (GMAC_ST2RPQ) Screening Type 2 Register Priority Queue (index = 0)  Reset Value */

#define GMAC_ST2RPQ_QNB_Pos                   _UINT32_(0)                                          /* (GMAC_ST2RPQ) Queue Number (0-5) Position */
#define GMAC_ST2RPQ_QNB_Msk                   (_UINT32_(0x7) << GMAC_ST2RPQ_QNB_Pos)               /* (GMAC_ST2RPQ) Queue Number (0-5) Mask */
#define GMAC_ST2RPQ_QNB(value)                (GMAC_ST2RPQ_QNB_Msk & (_UINT32_(value) << GMAC_ST2RPQ_QNB_Pos)) /* Assigment of value for QNB in the GMAC_ST2RPQ register */
#define GMAC_ST2RPQ_VLANP_Pos                 _UINT32_(4)                                          /* (GMAC_ST2RPQ) VLAN Priority Position */
#define GMAC_ST2RPQ_VLANP_Msk                 (_UINT32_(0x7) << GMAC_ST2RPQ_VLANP_Pos)             /* (GMAC_ST2RPQ) VLAN Priority Mask */
#define GMAC_ST2RPQ_VLANP(value)              (GMAC_ST2RPQ_VLANP_Msk & (_UINT32_(value) << GMAC_ST2RPQ_VLANP_Pos)) /* Assigment of value for VLANP in the GMAC_ST2RPQ register */
#define GMAC_ST2RPQ_VLANE_Pos                 _UINT32_(8)                                          /* (GMAC_ST2RPQ) VLAN Enable Position */
#define GMAC_ST2RPQ_VLANE_Msk                 (_UINT32_(0x1) << GMAC_ST2RPQ_VLANE_Pos)             /* (GMAC_ST2RPQ) VLAN Enable Mask */
#define GMAC_ST2RPQ_VLANE(value)              (GMAC_ST2RPQ_VLANE_Msk & (_UINT32_(value) << GMAC_ST2RPQ_VLANE_Pos)) /* Assigment of value for VLANE in the GMAC_ST2RPQ register */
#define   GMAC_ST2RPQ_VLANE_0_Val             _UINT32_(0x0)                                        /* (GMAC_ST2RPQ) VLAN match is disabled.  */
#define   GMAC_ST2RPQ_VLANE_1_Val             _UINT32_(0x1)                                        /* (GMAC_ST2RPQ) VLAN match is enabled.  */
#define GMAC_ST2RPQ_VLANE_0                   (GMAC_ST2RPQ_VLANE_0_Val << GMAC_ST2RPQ_VLANE_Pos)   /* (GMAC_ST2RPQ) VLAN match is disabled. Position  */
#define GMAC_ST2RPQ_VLANE_1                   (GMAC_ST2RPQ_VLANE_1_Val << GMAC_ST2RPQ_VLANE_Pos)   /* (GMAC_ST2RPQ) VLAN match is enabled. Position  */
#define GMAC_ST2RPQ_I2ETH_Pos                 _UINT32_(9)                                          /* (GMAC_ST2RPQ) Index of Screening Type 2 EtherType register Position */
#define GMAC_ST2RPQ_I2ETH_Msk                 (_UINT32_(0x7) << GMAC_ST2RPQ_I2ETH_Pos)             /* (GMAC_ST2RPQ) Index of Screening Type 2 EtherType register Mask */
#define GMAC_ST2RPQ_I2ETH(value)              (GMAC_ST2RPQ_I2ETH_Msk & (_UINT32_(value) << GMAC_ST2RPQ_I2ETH_Pos)) /* Assigment of value for I2ETH in the GMAC_ST2RPQ register */
#define GMAC_ST2RPQ_ETHE_Pos                  _UINT32_(12)                                         /* (GMAC_ST2RPQ) EtherType Enable Position */
#define GMAC_ST2RPQ_ETHE_Msk                  (_UINT32_(0x1) << GMAC_ST2RPQ_ETHE_Pos)              /* (GMAC_ST2RPQ) EtherType Enable Mask */
#define GMAC_ST2RPQ_ETHE(value)               (GMAC_ST2RPQ_ETHE_Msk & (_UINT32_(value) << GMAC_ST2RPQ_ETHE_Pos)) /* Assigment of value for ETHE in the GMAC_ST2RPQ register */
#define   GMAC_ST2RPQ_ETHE_0_Val              _UINT32_(0x0)                                        /* (GMAC_ST2RPQ) EtherType match with bits 15:0 in the register designated by the value of I2ETH is disabled.  */
#define   GMAC_ST2RPQ_ETHE_1_Val              _UINT32_(0x1)                                        /* (GMAC_ST2RPQ) EtherType match with bits 15:0 in the register designated by the value of I2ETH is enabled.  */
#define GMAC_ST2RPQ_ETHE_0                    (GMAC_ST2RPQ_ETHE_0_Val << GMAC_ST2RPQ_ETHE_Pos)     /* (GMAC_ST2RPQ) EtherType match with bits 15:0 in the register designated by the value of I2ETH is disabled. Position  */
#define GMAC_ST2RPQ_ETHE_1                    (GMAC_ST2RPQ_ETHE_1_Val << GMAC_ST2RPQ_ETHE_Pos)     /* (GMAC_ST2RPQ) EtherType match with bits 15:0 in the register designated by the value of I2ETH is enabled. Position  */
#define GMAC_ST2RPQ_COMPA_Pos                 _UINT32_(13)                                         /* (GMAC_ST2RPQ) Index of Screening Type 2 Compare Word 0/Word 1 register Position */
#define GMAC_ST2RPQ_COMPA_Msk                 (_UINT32_(0x1F) << GMAC_ST2RPQ_COMPA_Pos)            /* (GMAC_ST2RPQ) Index of Screening Type 2 Compare Word 0/Word 1 register Mask */
#define GMAC_ST2RPQ_COMPA(value)              (GMAC_ST2RPQ_COMPA_Msk & (_UINT32_(value) << GMAC_ST2RPQ_COMPA_Pos)) /* Assigment of value for COMPA in the GMAC_ST2RPQ register */
#define GMAC_ST2RPQ_COMPAE_Pos                _UINT32_(18)                                         /* (GMAC_ST2RPQ) Compare A Enable Position */
#define GMAC_ST2RPQ_COMPAE_Msk                (_UINT32_(0x1) << GMAC_ST2RPQ_COMPAE_Pos)            /* (GMAC_ST2RPQ) Compare A Enable Mask */
#define GMAC_ST2RPQ_COMPAE(value)             (GMAC_ST2RPQ_COMPAE_Msk & (_UINT32_(value) << GMAC_ST2RPQ_COMPAE_Pos)) /* Assigment of value for COMPAE in the GMAC_ST2RPQ register */
#define   GMAC_ST2RPQ_COMPAE_0_Val            _UINT32_(0x0)                                        /* (GMAC_ST2RPQ) Comparison via the register designated by index COMPA is disabled.  */
#define   GMAC_ST2RPQ_COMPAE_1_Val            _UINT32_(0x1)                                        /* (GMAC_ST2RPQ) Comparison via the register designated by index COMPA is enabled.  */
#define GMAC_ST2RPQ_COMPAE_0                  (GMAC_ST2RPQ_COMPAE_0_Val << GMAC_ST2RPQ_COMPAE_Pos) /* (GMAC_ST2RPQ) Comparison via the register designated by index COMPA is disabled. Position  */
#define GMAC_ST2RPQ_COMPAE_1                  (GMAC_ST2RPQ_COMPAE_1_Val << GMAC_ST2RPQ_COMPAE_Pos) /* (GMAC_ST2RPQ) Comparison via the register designated by index COMPA is enabled. Position  */
#define GMAC_ST2RPQ_COMPB_Pos                 _UINT32_(19)                                         /* (GMAC_ST2RPQ) Index of Screening Type 2 Compare Word 0/Word 1 register Position */
#define GMAC_ST2RPQ_COMPB_Msk                 (_UINT32_(0x1F) << GMAC_ST2RPQ_COMPB_Pos)            /* (GMAC_ST2RPQ) Index of Screening Type 2 Compare Word 0/Word 1 register Mask */
#define GMAC_ST2RPQ_COMPB(value)              (GMAC_ST2RPQ_COMPB_Msk & (_UINT32_(value) << GMAC_ST2RPQ_COMPB_Pos)) /* Assigment of value for COMPB in the GMAC_ST2RPQ register */
#define GMAC_ST2RPQ_COMPBE_Pos                _UINT32_(24)                                         /* (GMAC_ST2RPQ) Compare B Enable Position */
#define GMAC_ST2RPQ_COMPBE_Msk                (_UINT32_(0x1) << GMAC_ST2RPQ_COMPBE_Pos)            /* (GMAC_ST2RPQ) Compare B Enable Mask */
#define GMAC_ST2RPQ_COMPBE(value)             (GMAC_ST2RPQ_COMPBE_Msk & (_UINT32_(value) << GMAC_ST2RPQ_COMPBE_Pos)) /* Assigment of value for COMPBE in the GMAC_ST2RPQ register */
#define   GMAC_ST2RPQ_COMPBE_0_Val            _UINT32_(0x0)                                        /* (GMAC_ST2RPQ) Comparison via the register designated by index COMPB is disabled.  */
#define   GMAC_ST2RPQ_COMPBE_1_Val            _UINT32_(0x1)                                        /* (GMAC_ST2RPQ) Comparison via the register designated by index COMPB is enabled.  */
#define GMAC_ST2RPQ_COMPBE_0                  (GMAC_ST2RPQ_COMPBE_0_Val << GMAC_ST2RPQ_COMPBE_Pos) /* (GMAC_ST2RPQ) Comparison via the register designated by index COMPB is disabled. Position  */
#define GMAC_ST2RPQ_COMPBE_1                  (GMAC_ST2RPQ_COMPBE_1_Val << GMAC_ST2RPQ_COMPBE_Pos) /* (GMAC_ST2RPQ) Comparison via the register designated by index COMPB is enabled. Position  */
#define GMAC_ST2RPQ_COMPC_Pos                 _UINT32_(25)                                         /* (GMAC_ST2RPQ) Index of Screening Type 2 Compare Word 0/Word 1 register Position */
#define GMAC_ST2RPQ_COMPC_Msk                 (_UINT32_(0x1F) << GMAC_ST2RPQ_COMPC_Pos)            /* (GMAC_ST2RPQ) Index of Screening Type 2 Compare Word 0/Word 1 register Mask */
#define GMAC_ST2RPQ_COMPC(value)              (GMAC_ST2RPQ_COMPC_Msk & (_UINT32_(value) << GMAC_ST2RPQ_COMPC_Pos)) /* Assigment of value for COMPC in the GMAC_ST2RPQ register */
#define GMAC_ST2RPQ_COMPCE_Pos                _UINT32_(30)                                         /* (GMAC_ST2RPQ) Compare C Enable Position */
#define GMAC_ST2RPQ_COMPCE_Msk                (_UINT32_(0x1) << GMAC_ST2RPQ_COMPCE_Pos)            /* (GMAC_ST2RPQ) Compare C Enable Mask */
#define GMAC_ST2RPQ_COMPCE(value)             (GMAC_ST2RPQ_COMPCE_Msk & (_UINT32_(value) << GMAC_ST2RPQ_COMPCE_Pos)) /* Assigment of value for COMPCE in the GMAC_ST2RPQ register */
#define   GMAC_ST2RPQ_COMPCE_0_Val            _UINT32_(0x0)                                        /* (GMAC_ST2RPQ) Comparison via the register designated by index COMPC is disabled.  */
#define   GMAC_ST2RPQ_COMPCE_1_Val            _UINT32_(0x1)                                        /* (GMAC_ST2RPQ) Comparison via the register designated by index COMPC is enabled.  */
#define GMAC_ST2RPQ_COMPCE_0                  (GMAC_ST2RPQ_COMPCE_0_Val << GMAC_ST2RPQ_COMPCE_Pos) /* (GMAC_ST2RPQ) Comparison via the register designated by index COMPC is disabled. Position  */
#define GMAC_ST2RPQ_COMPCE_1                  (GMAC_ST2RPQ_COMPCE_1_Val << GMAC_ST2RPQ_COMPCE_Pos) /* (GMAC_ST2RPQ) Comparison via the register designated by index COMPC is enabled. Position  */
#define GMAC_ST2RPQ_Msk                       _UINT32_(0x7FFFFF77)                                 /* (GMAC_ST2RPQ) Register Mask  */


/* -------- GMAC_TSCTL : (GMAC Offset: 0x580) (R/W 32) Transmit Schedule Control Register -------- */
#define GMAC_TSCTL_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_TSCTL) Transmit Schedule Control Register  Reset Value */

#define GMAC_TSCTL_TXSQ0_Pos                  _UINT32_(0)                                          /* (GMAC_TSCTL) Transmit Schedule for Qx Position */
#define GMAC_TSCTL_TXSQ0_Msk                  (_UINT32_(0x3) << GMAC_TSCTL_TXSQ0_Pos)              /* (GMAC_TSCTL) Transmit Schedule for Qx Mask */
#define GMAC_TSCTL_TXSQ0(value)               (GMAC_TSCTL_TXSQ0_Msk & (_UINT32_(value) << GMAC_TSCTL_TXSQ0_Pos)) /* Assigment of value for TXSQ0 in the GMAC_TSCTL register */
#define   GMAC_TSCTL_TXSQ0_FP_Val             _UINT32_(0x0)                                        /* (GMAC_TSCTL) Fixed Priority  */
#define   GMAC_TSCTL_TXSQ0_CBS_Val            _UINT32_(0x1)                                        /* (GMAC_TSCTL) CBS Enabled only valid for top two enabled queues and if CBS capability selected.  */
#define   GMAC_TSCTL_TXSQ0_DWRR_Val           _UINT32_(0x2)                                        /* (GMAC_TSCTL) DWRR enabled  */
#define   GMAC_TSCTL_TXSQ0_ETS_Val            _UINT32_(0x3)                                        /* (GMAC_TSCTL) ETS enabled  */
#define GMAC_TSCTL_TXSQ0_FP                   (GMAC_TSCTL_TXSQ0_FP_Val << GMAC_TSCTL_TXSQ0_Pos)    /* (GMAC_TSCTL) Fixed Priority Position  */
#define GMAC_TSCTL_TXSQ0_CBS                  (GMAC_TSCTL_TXSQ0_CBS_Val << GMAC_TSCTL_TXSQ0_Pos)   /* (GMAC_TSCTL) CBS Enabled only valid for top two enabled queues and if CBS capability selected. Position  */
#define GMAC_TSCTL_TXSQ0_DWRR                 (GMAC_TSCTL_TXSQ0_DWRR_Val << GMAC_TSCTL_TXSQ0_Pos)  /* (GMAC_TSCTL) DWRR enabled Position  */
#define GMAC_TSCTL_TXSQ0_ETS                  (GMAC_TSCTL_TXSQ0_ETS_Val << GMAC_TSCTL_TXSQ0_Pos)   /* (GMAC_TSCTL) ETS enabled Position  */
#define GMAC_TSCTL_TXSQ1_Pos                  _UINT32_(2)                                          /* (GMAC_TSCTL) Transmit Schedule for Qx Position */
#define GMAC_TSCTL_TXSQ1_Msk                  (_UINT32_(0x3) << GMAC_TSCTL_TXSQ1_Pos)              /* (GMAC_TSCTL) Transmit Schedule for Qx Mask */
#define GMAC_TSCTL_TXSQ1(value)               (GMAC_TSCTL_TXSQ1_Msk & (_UINT32_(value) << GMAC_TSCTL_TXSQ1_Pos)) /* Assigment of value for TXSQ1 in the GMAC_TSCTL register */
#define   GMAC_TSCTL_TXSQ1_FP_Val             _UINT32_(0x0)                                        /* (GMAC_TSCTL) Fixed Priority  */
#define   GMAC_TSCTL_TXSQ1_CBS_Val            _UINT32_(0x1)                                        /* (GMAC_TSCTL) CBS Enabled only valid for top two enabled queues and if CBS capability selected.  */
#define   GMAC_TSCTL_TXSQ1_DWRR_Val           _UINT32_(0x2)                                        /* (GMAC_TSCTL) DWRR enabled  */
#define   GMAC_TSCTL_TXSQ1_ETS_Val            _UINT32_(0x3)                                        /* (GMAC_TSCTL) ETS enabled  */
#define GMAC_TSCTL_TXSQ1_FP                   (GMAC_TSCTL_TXSQ1_FP_Val << GMAC_TSCTL_TXSQ1_Pos)    /* (GMAC_TSCTL) Fixed Priority Position  */
#define GMAC_TSCTL_TXSQ1_CBS                  (GMAC_TSCTL_TXSQ1_CBS_Val << GMAC_TSCTL_TXSQ1_Pos)   /* (GMAC_TSCTL) CBS Enabled only valid for top two enabled queues and if CBS capability selected. Position  */
#define GMAC_TSCTL_TXSQ1_DWRR                 (GMAC_TSCTL_TXSQ1_DWRR_Val << GMAC_TSCTL_TXSQ1_Pos)  /* (GMAC_TSCTL) DWRR enabled Position  */
#define GMAC_TSCTL_TXSQ1_ETS                  (GMAC_TSCTL_TXSQ1_ETS_Val << GMAC_TSCTL_TXSQ1_Pos)   /* (GMAC_TSCTL) ETS enabled Position  */
#define GMAC_TSCTL_TXSQ2_Pos                  _UINT32_(4)                                          /* (GMAC_TSCTL) Transmit Schedule for Qx Position */
#define GMAC_TSCTL_TXSQ2_Msk                  (_UINT32_(0x3) << GMAC_TSCTL_TXSQ2_Pos)              /* (GMAC_TSCTL) Transmit Schedule for Qx Mask */
#define GMAC_TSCTL_TXSQ2(value)               (GMAC_TSCTL_TXSQ2_Msk & (_UINT32_(value) << GMAC_TSCTL_TXSQ2_Pos)) /* Assigment of value for TXSQ2 in the GMAC_TSCTL register */
#define   GMAC_TSCTL_TXSQ2_FP_Val             _UINT32_(0x0)                                        /* (GMAC_TSCTL) Fixed Priority  */
#define   GMAC_TSCTL_TXSQ2_CBS_Val            _UINT32_(0x1)                                        /* (GMAC_TSCTL) CBS Enabled only valid for top two enabled queues and if CBS capability selected.  */
#define   GMAC_TSCTL_TXSQ2_DWRR_Val           _UINT32_(0x2)                                        /* (GMAC_TSCTL) DWRR enabled  */
#define   GMAC_TSCTL_TXSQ2_ETS_Val            _UINT32_(0x3)                                        /* (GMAC_TSCTL) ETS enabled  */
#define GMAC_TSCTL_TXSQ2_FP                   (GMAC_TSCTL_TXSQ2_FP_Val << GMAC_TSCTL_TXSQ2_Pos)    /* (GMAC_TSCTL) Fixed Priority Position  */
#define GMAC_TSCTL_TXSQ2_CBS                  (GMAC_TSCTL_TXSQ2_CBS_Val << GMAC_TSCTL_TXSQ2_Pos)   /* (GMAC_TSCTL) CBS Enabled only valid for top two enabled queues and if CBS capability selected. Position  */
#define GMAC_TSCTL_TXSQ2_DWRR                 (GMAC_TSCTL_TXSQ2_DWRR_Val << GMAC_TSCTL_TXSQ2_Pos)  /* (GMAC_TSCTL) DWRR enabled Position  */
#define GMAC_TSCTL_TXSQ2_ETS                  (GMAC_TSCTL_TXSQ2_ETS_Val << GMAC_TSCTL_TXSQ2_Pos)   /* (GMAC_TSCTL) ETS enabled Position  */
#define GMAC_TSCTL_TXSQ3_Pos                  _UINT32_(6)                                          /* (GMAC_TSCTL) Transmit Schedule for Qx Position */
#define GMAC_TSCTL_TXSQ3_Msk                  (_UINT32_(0x3) << GMAC_TSCTL_TXSQ3_Pos)              /* (GMAC_TSCTL) Transmit Schedule for Qx Mask */
#define GMAC_TSCTL_TXSQ3(value)               (GMAC_TSCTL_TXSQ3_Msk & (_UINT32_(value) << GMAC_TSCTL_TXSQ3_Pos)) /* Assigment of value for TXSQ3 in the GMAC_TSCTL register */
#define   GMAC_TSCTL_TXSQ3_FP_Val             _UINT32_(0x0)                                        /* (GMAC_TSCTL) Fixed Priority  */
#define   GMAC_TSCTL_TXSQ3_CBS_Val            _UINT32_(0x1)                                        /* (GMAC_TSCTL) CBS Enabled only valid for top two enabled queues and if CBS capability selected.  */
#define   GMAC_TSCTL_TXSQ3_DWRR_Val           _UINT32_(0x2)                                        /* (GMAC_TSCTL) DWRR enabled  */
#define   GMAC_TSCTL_TXSQ3_ETS_Val            _UINT32_(0x3)                                        /* (GMAC_TSCTL) ETS enabled  */
#define GMAC_TSCTL_TXSQ3_FP                   (GMAC_TSCTL_TXSQ3_FP_Val << GMAC_TSCTL_TXSQ3_Pos)    /* (GMAC_TSCTL) Fixed Priority Position  */
#define GMAC_TSCTL_TXSQ3_CBS                  (GMAC_TSCTL_TXSQ3_CBS_Val << GMAC_TSCTL_TXSQ3_Pos)   /* (GMAC_TSCTL) CBS Enabled only valid for top two enabled queues and if CBS capability selected. Position  */
#define GMAC_TSCTL_TXSQ3_DWRR                 (GMAC_TSCTL_TXSQ3_DWRR_Val << GMAC_TSCTL_TXSQ3_Pos)  /* (GMAC_TSCTL) DWRR enabled Position  */
#define GMAC_TSCTL_TXSQ3_ETS                  (GMAC_TSCTL_TXSQ3_ETS_Val << GMAC_TSCTL_TXSQ3_Pos)   /* (GMAC_TSCTL) ETS enabled Position  */
#define GMAC_TSCTL_TXSQ4_Pos                  _UINT32_(8)                                          /* (GMAC_TSCTL) Transmit Schedule for Qx Position */
#define GMAC_TSCTL_TXSQ4_Msk                  (_UINT32_(0x3) << GMAC_TSCTL_TXSQ4_Pos)              /* (GMAC_TSCTL) Transmit Schedule for Qx Mask */
#define GMAC_TSCTL_TXSQ4(value)               (GMAC_TSCTL_TXSQ4_Msk & (_UINT32_(value) << GMAC_TSCTL_TXSQ4_Pos)) /* Assigment of value for TXSQ4 in the GMAC_TSCTL register */
#define   GMAC_TSCTL_TXSQ4_FP_Val             _UINT32_(0x0)                                        /* (GMAC_TSCTL) Fixed Priority  */
#define   GMAC_TSCTL_TXSQ4_CBS_Val            _UINT32_(0x1)                                        /* (GMAC_TSCTL) CBS Enabled only valid for top two enabled queues and if CBS capability selected.  */
#define   GMAC_TSCTL_TXSQ4_DWRR_Val           _UINT32_(0x2)                                        /* (GMAC_TSCTL) DWRR enabled  */
#define   GMAC_TSCTL_TXSQ4_ETS_Val            _UINT32_(0x3)                                        /* (GMAC_TSCTL) ETS enabled  */
#define GMAC_TSCTL_TXSQ4_FP                   (GMAC_TSCTL_TXSQ4_FP_Val << GMAC_TSCTL_TXSQ4_Pos)    /* (GMAC_TSCTL) Fixed Priority Position  */
#define GMAC_TSCTL_TXSQ4_CBS                  (GMAC_TSCTL_TXSQ4_CBS_Val << GMAC_TSCTL_TXSQ4_Pos)   /* (GMAC_TSCTL) CBS Enabled only valid for top two enabled queues and if CBS capability selected. Position  */
#define GMAC_TSCTL_TXSQ4_DWRR                 (GMAC_TSCTL_TXSQ4_DWRR_Val << GMAC_TSCTL_TXSQ4_Pos)  /* (GMAC_TSCTL) DWRR enabled Position  */
#define GMAC_TSCTL_TXSQ4_ETS                  (GMAC_TSCTL_TXSQ4_ETS_Val << GMAC_TSCTL_TXSQ4_Pos)   /* (GMAC_TSCTL) ETS enabled Position  */
#define GMAC_TSCTL_TXSQ5_Pos                  _UINT32_(10)                                         /* (GMAC_TSCTL) Transmit Schedule for Qx Position */
#define GMAC_TSCTL_TXSQ5_Msk                  (_UINT32_(0x3) << GMAC_TSCTL_TXSQ5_Pos)              /* (GMAC_TSCTL) Transmit Schedule for Qx Mask */
#define GMAC_TSCTL_TXSQ5(value)               (GMAC_TSCTL_TXSQ5_Msk & (_UINT32_(value) << GMAC_TSCTL_TXSQ5_Pos)) /* Assigment of value for TXSQ5 in the GMAC_TSCTL register */
#define   GMAC_TSCTL_TXSQ5_FP_Val             _UINT32_(0x0)                                        /* (GMAC_TSCTL) Fixed Priority  */
#define   GMAC_TSCTL_TXSQ5_CBS_Val            _UINT32_(0x1)                                        /* (GMAC_TSCTL) CBS Enabled only valid for top two enabled queues and if CBS capability selected.  */
#define   GMAC_TSCTL_TXSQ5_DWRR_Val           _UINT32_(0x2)                                        /* (GMAC_TSCTL) DWRR enabled  */
#define   GMAC_TSCTL_TXSQ5_ETS_Val            _UINT32_(0x3)                                        /* (GMAC_TSCTL) ETS enabled  */
#define GMAC_TSCTL_TXSQ5_FP                   (GMAC_TSCTL_TXSQ5_FP_Val << GMAC_TSCTL_TXSQ5_Pos)    /* (GMAC_TSCTL) Fixed Priority Position  */
#define GMAC_TSCTL_TXSQ5_CBS                  (GMAC_TSCTL_TXSQ5_CBS_Val << GMAC_TSCTL_TXSQ5_Pos)   /* (GMAC_TSCTL) CBS Enabled only valid for top two enabled queues and if CBS capability selected. Position  */
#define GMAC_TSCTL_TXSQ5_DWRR                 (GMAC_TSCTL_TXSQ5_DWRR_Val << GMAC_TSCTL_TXSQ5_Pos)  /* (GMAC_TSCTL) DWRR enabled Position  */
#define GMAC_TSCTL_TXSQ5_ETS                  (GMAC_TSCTL_TXSQ5_ETS_Val << GMAC_TSCTL_TXSQ5_Pos)   /* (GMAC_TSCTL) ETS enabled Position  */
#define GMAC_TSCTL_Msk                        _UINT32_(0x00000FFF)                                 /* (GMAC_TSCTL) Register Mask  */


/* -------- GMAC_TQBWRL0 : (GMAC Offset: 0x590) (R/W 32) Transmit Queue Bandwidth Rate Limit 0 Register -------- */
#define GMAC_TQBWRL0_RESETVALUE               _UINT32_(0x00)                                       /*  (GMAC_TQBWRL0) Transmit Queue Bandwidth Rate Limit 0 Register  Reset Value */

#define GMAC_TQBWRL0_ALLOCQ0_Pos              _UINT32_(0)                                          /* (GMAC_TQBWRL0) DWRR Weighting or ETS Bandwidth Allocation for Qx Position */
#define GMAC_TQBWRL0_ALLOCQ0_Msk              (_UINT32_(0xFF) << GMAC_TQBWRL0_ALLOCQ0_Pos)         /* (GMAC_TQBWRL0) DWRR Weighting or ETS Bandwidth Allocation for Qx Mask */
#define GMAC_TQBWRL0_ALLOCQ0(value)           (GMAC_TQBWRL0_ALLOCQ0_Msk & (_UINT32_(value) << GMAC_TQBWRL0_ALLOCQ0_Pos)) /* Assigment of value for ALLOCQ0 in the GMAC_TQBWRL0 register */
#define GMAC_TQBWRL0_ALLOCQ1_Pos              _UINT32_(8)                                          /* (GMAC_TQBWRL0) DWRR Weighting or ETS Bandwidth Allocation for Qx Position */
#define GMAC_TQBWRL0_ALLOCQ1_Msk              (_UINT32_(0xFF) << GMAC_TQBWRL0_ALLOCQ1_Pos)         /* (GMAC_TQBWRL0) DWRR Weighting or ETS Bandwidth Allocation for Qx Mask */
#define GMAC_TQBWRL0_ALLOCQ1(value)           (GMAC_TQBWRL0_ALLOCQ1_Msk & (_UINT32_(value) << GMAC_TQBWRL0_ALLOCQ1_Pos)) /* Assigment of value for ALLOCQ1 in the GMAC_TQBWRL0 register */
#define GMAC_TQBWRL0_ALLOCQ2_Pos              _UINT32_(16)                                         /* (GMAC_TQBWRL0) DWRR Weighting or ETS Bandwidth Allocation for Qx Position */
#define GMAC_TQBWRL0_ALLOCQ2_Msk              (_UINT32_(0xFF) << GMAC_TQBWRL0_ALLOCQ2_Pos)         /* (GMAC_TQBWRL0) DWRR Weighting or ETS Bandwidth Allocation for Qx Mask */
#define GMAC_TQBWRL0_ALLOCQ2(value)           (GMAC_TQBWRL0_ALLOCQ2_Msk & (_UINT32_(value) << GMAC_TQBWRL0_ALLOCQ2_Pos)) /* Assigment of value for ALLOCQ2 in the GMAC_TQBWRL0 register */
#define GMAC_TQBWRL0_ALLOCQ3_Pos              _UINT32_(24)                                         /* (GMAC_TQBWRL0) DWRR Weighting or ETS Bandwidth Allocation for Qx Position */
#define GMAC_TQBWRL0_ALLOCQ3_Msk              (_UINT32_(0xFF) << GMAC_TQBWRL0_ALLOCQ3_Pos)         /* (GMAC_TQBWRL0) DWRR Weighting or ETS Bandwidth Allocation for Qx Mask */
#define GMAC_TQBWRL0_ALLOCQ3(value)           (GMAC_TQBWRL0_ALLOCQ3_Msk & (_UINT32_(value) << GMAC_TQBWRL0_ALLOCQ3_Pos)) /* Assigment of value for ALLOCQ3 in the GMAC_TQBWRL0 register */
#define GMAC_TQBWRL0_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (GMAC_TQBWRL0) Register Mask  */


/* -------- GMAC_TQSA : (GMAC Offset: 0x5A0) (R/W 32) Transmit Queue Segment Allocation Register -------- */
#define GMAC_TQSA_RESETVALUE                  _UINT32_(0x00)                                       /*  (GMAC_TQSA) Transmit Queue Segment Allocation Register  Reset Value */

#define GMAC_TQSA_SEGALLOCQ0_Pos              _UINT32_(0)                                          /* (GMAC_TQSA) Segment Allocation for Qx Position */
#define GMAC_TQSA_SEGALLOCQ0_Msk              (_UINT32_(0x7) << GMAC_TQSA_SEGALLOCQ0_Pos)          /* (GMAC_TQSA) Segment Allocation for Qx Mask */
#define GMAC_TQSA_SEGALLOCQ0(value)           (GMAC_TQSA_SEGALLOCQ0_Msk & (_UINT32_(value) << GMAC_TQSA_SEGALLOCQ0_Pos)) /* Assigment of value for SEGALLOCQ0 in the GMAC_TQSA register */
#define GMAC_TQSA_SEGALLOCQ1_Pos              _UINT32_(4)                                          /* (GMAC_TQSA) Segment Allocation for Qx Position */
#define GMAC_TQSA_SEGALLOCQ1_Msk              (_UINT32_(0x7) << GMAC_TQSA_SEGALLOCQ1_Pos)          /* (GMAC_TQSA) Segment Allocation for Qx Mask */
#define GMAC_TQSA_SEGALLOCQ1(value)           (GMAC_TQSA_SEGALLOCQ1_Msk & (_UINT32_(value) << GMAC_TQSA_SEGALLOCQ1_Pos)) /* Assigment of value for SEGALLOCQ1 in the GMAC_TQSA register */
#define GMAC_TQSA_SEGALLOCQ2_Pos              _UINT32_(8)                                          /* (GMAC_TQSA) Segment Allocation for Qx Position */
#define GMAC_TQSA_SEGALLOCQ2_Msk              (_UINT32_(0x7) << GMAC_TQSA_SEGALLOCQ2_Pos)          /* (GMAC_TQSA) Segment Allocation for Qx Mask */
#define GMAC_TQSA_SEGALLOCQ2(value)           (GMAC_TQSA_SEGALLOCQ2_Msk & (_UINT32_(value) << GMAC_TQSA_SEGALLOCQ2_Pos)) /* Assigment of value for SEGALLOCQ2 in the GMAC_TQSA register */
#define GMAC_TQSA_SEGALLOCQ3_Pos              _UINT32_(12)                                         /* (GMAC_TQSA) Segment Allocation for Qx Position */
#define GMAC_TQSA_SEGALLOCQ3_Msk              (_UINT32_(0x7) << GMAC_TQSA_SEGALLOCQ3_Pos)          /* (GMAC_TQSA) Segment Allocation for Qx Mask */
#define GMAC_TQSA_SEGALLOCQ3(value)           (GMAC_TQSA_SEGALLOCQ3_Msk & (_UINT32_(value) << GMAC_TQSA_SEGALLOCQ3_Pos)) /* Assigment of value for SEGALLOCQ3 in the GMAC_TQSA register */
#define GMAC_TQSA_SEGALLOCQ4_Pos              _UINT32_(16)                                         /* (GMAC_TQSA) Segment Allocation for Qx Position */
#define GMAC_TQSA_SEGALLOCQ4_Msk              (_UINT32_(0x7) << GMAC_TQSA_SEGALLOCQ4_Pos)          /* (GMAC_TQSA) Segment Allocation for Qx Mask */
#define GMAC_TQSA_SEGALLOCQ4(value)           (GMAC_TQSA_SEGALLOCQ4_Msk & (_UINT32_(value) << GMAC_TQSA_SEGALLOCQ4_Pos)) /* Assigment of value for SEGALLOCQ4 in the GMAC_TQSA register */
#define GMAC_TQSA_SEGALLOCQ5_Pos              _UINT32_(20)                                         /* (GMAC_TQSA) Segment Allocation for Qx Position */
#define GMAC_TQSA_SEGALLOCQ5_Msk              (_UINT32_(0x7) << GMAC_TQSA_SEGALLOCQ5_Pos)          /* (GMAC_TQSA) Segment Allocation for Qx Mask */
#define GMAC_TQSA_SEGALLOCQ5(value)           (GMAC_TQSA_SEGALLOCQ5_Msk & (_UINT32_(value) << GMAC_TQSA_SEGALLOCQ5_Pos)) /* Assigment of value for SEGALLOCQ5 in the GMAC_TQSA register */
#define GMAC_TQSA_Msk                         _UINT32_(0x00777777)                                 /* (GMAC_TQSA) Register Mask  */


/* -------- GMAC_IERPQ : (GMAC Offset: 0x600) ( /W 32) Interrupt Enable Register Priority Queue (index = 1) -------- */
#define GMAC_IERPQ_RCOMP_Pos                  _UINT32_(1)                                          /* (GMAC_IERPQ) Receive Complete Position */
#define GMAC_IERPQ_RCOMP_Msk                  (_UINT32_(0x1) << GMAC_IERPQ_RCOMP_Pos)              /* (GMAC_IERPQ) Receive Complete Mask */
#define GMAC_IERPQ_RCOMP(value)               (GMAC_IERPQ_RCOMP_Msk & (_UINT32_(value) << GMAC_IERPQ_RCOMP_Pos)) /* Assigment of value for RCOMP in the GMAC_IERPQ register */
#define GMAC_IERPQ_RXUBR_Pos                  _UINT32_(2)                                          /* (GMAC_IERPQ) RX Used Bit Read Position */
#define GMAC_IERPQ_RXUBR_Msk                  (_UINT32_(0x1) << GMAC_IERPQ_RXUBR_Pos)              /* (GMAC_IERPQ) RX Used Bit Read Mask */
#define GMAC_IERPQ_RXUBR(value)               (GMAC_IERPQ_RXUBR_Msk & (_UINT32_(value) << GMAC_IERPQ_RXUBR_Pos)) /* Assigment of value for RXUBR in the GMAC_IERPQ register */
#define GMAC_IERPQ_RLEX_Pos                   _UINT32_(5)                                          /* (GMAC_IERPQ) Retry Limit Exceeded or Late Collision Position */
#define GMAC_IERPQ_RLEX_Msk                   (_UINT32_(0x1) << GMAC_IERPQ_RLEX_Pos)               /* (GMAC_IERPQ) Retry Limit Exceeded or Late Collision Mask */
#define GMAC_IERPQ_RLEX(value)                (GMAC_IERPQ_RLEX_Msk & (_UINT32_(value) << GMAC_IERPQ_RLEX_Pos)) /* Assigment of value for RLEX in the GMAC_IERPQ register */
#define GMAC_IERPQ_TFC_Pos                    _UINT32_(6)                                          /* (GMAC_IERPQ) Transmit Frame Corruption Due to System Bus Error Position */
#define GMAC_IERPQ_TFC_Msk                    (_UINT32_(0x1) << GMAC_IERPQ_TFC_Pos)                /* (GMAC_IERPQ) Transmit Frame Corruption Due to System Bus Error Mask */
#define GMAC_IERPQ_TFC(value)                 (GMAC_IERPQ_TFC_Msk & (_UINT32_(value) << GMAC_IERPQ_TFC_Pos)) /* Assigment of value for TFC in the GMAC_IERPQ register */
#define GMAC_IERPQ_TCOMP_Pos                  _UINT32_(7)                                          /* (GMAC_IERPQ) Transmit Complete Position */
#define GMAC_IERPQ_TCOMP_Msk                  (_UINT32_(0x1) << GMAC_IERPQ_TCOMP_Pos)              /* (GMAC_IERPQ) Transmit Complete Mask */
#define GMAC_IERPQ_TCOMP(value)               (GMAC_IERPQ_TCOMP_Msk & (_UINT32_(value) << GMAC_IERPQ_TCOMP_Pos)) /* Assigment of value for TCOMP in the GMAC_IERPQ register */
#define GMAC_IERPQ_HRESP_Pos                  _UINT32_(11)                                         /* (GMAC_IERPQ) System Bus Error Position */
#define GMAC_IERPQ_HRESP_Msk                  (_UINT32_(0x1) << GMAC_IERPQ_HRESP_Pos)              /* (GMAC_IERPQ) System Bus Error Mask */
#define GMAC_IERPQ_HRESP(value)               (GMAC_IERPQ_HRESP_Msk & (_UINT32_(value) << GMAC_IERPQ_HRESP_Pos)) /* Assigment of value for HRESP in the GMAC_IERPQ register */
#define GMAC_IERPQ_Msk                        _UINT32_(0x000008E6)                                 /* (GMAC_IERPQ) Register Mask  */


/* -------- GMAC_IDRPQ : (GMAC Offset: 0x620) ( /W 32) Interrupt Disable Register Priority Queue (index = 1) -------- */
#define GMAC_IDRPQ_RCOMP_Pos                  _UINT32_(1)                                          /* (GMAC_IDRPQ) Receive Complete Position */
#define GMAC_IDRPQ_RCOMP_Msk                  (_UINT32_(0x1) << GMAC_IDRPQ_RCOMP_Pos)              /* (GMAC_IDRPQ) Receive Complete Mask */
#define GMAC_IDRPQ_RCOMP(value)               (GMAC_IDRPQ_RCOMP_Msk & (_UINT32_(value) << GMAC_IDRPQ_RCOMP_Pos)) /* Assigment of value for RCOMP in the GMAC_IDRPQ register */
#define GMAC_IDRPQ_RXUBR_Pos                  _UINT32_(2)                                          /* (GMAC_IDRPQ) RX Used Bit Read Position */
#define GMAC_IDRPQ_RXUBR_Msk                  (_UINT32_(0x1) << GMAC_IDRPQ_RXUBR_Pos)              /* (GMAC_IDRPQ) RX Used Bit Read Mask */
#define GMAC_IDRPQ_RXUBR(value)               (GMAC_IDRPQ_RXUBR_Msk & (_UINT32_(value) << GMAC_IDRPQ_RXUBR_Pos)) /* Assigment of value for RXUBR in the GMAC_IDRPQ register */
#define GMAC_IDRPQ_RLEX_Pos                   _UINT32_(5)                                          /* (GMAC_IDRPQ) Retry Limit Exceeded or Late Collision Position */
#define GMAC_IDRPQ_RLEX_Msk                   (_UINT32_(0x1) << GMAC_IDRPQ_RLEX_Pos)               /* (GMAC_IDRPQ) Retry Limit Exceeded or Late Collision Mask */
#define GMAC_IDRPQ_RLEX(value)                (GMAC_IDRPQ_RLEX_Msk & (_UINT32_(value) << GMAC_IDRPQ_RLEX_Pos)) /* Assigment of value for RLEX in the GMAC_IDRPQ register */
#define GMAC_IDRPQ_TFC_Pos                    _UINT32_(6)                                          /* (GMAC_IDRPQ) Transmit Frame Corruption Due to System Bus Error Position */
#define GMAC_IDRPQ_TFC_Msk                    (_UINT32_(0x1) << GMAC_IDRPQ_TFC_Pos)                /* (GMAC_IDRPQ) Transmit Frame Corruption Due to System Bus Error Mask */
#define GMAC_IDRPQ_TFC(value)                 (GMAC_IDRPQ_TFC_Msk & (_UINT32_(value) << GMAC_IDRPQ_TFC_Pos)) /* Assigment of value for TFC in the GMAC_IDRPQ register */
#define GMAC_IDRPQ_TCOMP_Pos                  _UINT32_(7)                                          /* (GMAC_IDRPQ) Transmit Complete Position */
#define GMAC_IDRPQ_TCOMP_Msk                  (_UINT32_(0x1) << GMAC_IDRPQ_TCOMP_Pos)              /* (GMAC_IDRPQ) Transmit Complete Mask */
#define GMAC_IDRPQ_TCOMP(value)               (GMAC_IDRPQ_TCOMP_Msk & (_UINT32_(value) << GMAC_IDRPQ_TCOMP_Pos)) /* Assigment of value for TCOMP in the GMAC_IDRPQ register */
#define GMAC_IDRPQ_HRESP_Pos                  _UINT32_(11)                                         /* (GMAC_IDRPQ) System Bus Error Position */
#define GMAC_IDRPQ_HRESP_Msk                  (_UINT32_(0x1) << GMAC_IDRPQ_HRESP_Pos)              /* (GMAC_IDRPQ) System Bus Error Mask */
#define GMAC_IDRPQ_HRESP(value)               (GMAC_IDRPQ_HRESP_Msk & (_UINT32_(value) << GMAC_IDRPQ_HRESP_Pos)) /* Assigment of value for HRESP in the GMAC_IDRPQ register */
#define GMAC_IDRPQ_Msk                        _UINT32_(0x000008E6)                                 /* (GMAC_IDRPQ) Register Mask  */


/* -------- GMAC_IMRPQ : (GMAC Offset: 0x640) (R/W 32) Interrupt Mask Register Priority Queue (index = 1) -------- */
#define GMAC_IMRPQ_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_IMRPQ) Interrupt Mask Register Priority Queue (index = 1)  Reset Value */

#define GMAC_IMRPQ_RCOMP_Pos                  _UINT32_(1)                                          /* (GMAC_IMRPQ) Receive Complete Position */
#define GMAC_IMRPQ_RCOMP_Msk                  (_UINT32_(0x1) << GMAC_IMRPQ_RCOMP_Pos)              /* (GMAC_IMRPQ) Receive Complete Mask */
#define GMAC_IMRPQ_RCOMP(value)               (GMAC_IMRPQ_RCOMP_Msk & (_UINT32_(value) << GMAC_IMRPQ_RCOMP_Pos)) /* Assigment of value for RCOMP in the GMAC_IMRPQ register */
#define GMAC_IMRPQ_RXUBR_Pos                  _UINT32_(2)                                          /* (GMAC_IMRPQ) RX Used Bit Read Position */
#define GMAC_IMRPQ_RXUBR_Msk                  (_UINT32_(0x1) << GMAC_IMRPQ_RXUBR_Pos)              /* (GMAC_IMRPQ) RX Used Bit Read Mask */
#define GMAC_IMRPQ_RXUBR(value)               (GMAC_IMRPQ_RXUBR_Msk & (_UINT32_(value) << GMAC_IMRPQ_RXUBR_Pos)) /* Assigment of value for RXUBR in the GMAC_IMRPQ register */
#define GMAC_IMRPQ_RLEX_Pos                   _UINT32_(5)                                          /* (GMAC_IMRPQ) Retry Limit Exceeded or Late Collision Position */
#define GMAC_IMRPQ_RLEX_Msk                   (_UINT32_(0x1) << GMAC_IMRPQ_RLEX_Pos)               /* (GMAC_IMRPQ) Retry Limit Exceeded or Late Collision Mask */
#define GMAC_IMRPQ_RLEX(value)                (GMAC_IMRPQ_RLEX_Msk & (_UINT32_(value) << GMAC_IMRPQ_RLEX_Pos)) /* Assigment of value for RLEX in the GMAC_IMRPQ register */
#define GMAC_IMRPQ_AHB_Pos                    _UINT32_(6)                                          /* (GMAC_IMRPQ) Transmit Frame Corruption Due to System Bus Error Position */
#define GMAC_IMRPQ_AHB_Msk                    (_UINT32_(0x1) << GMAC_IMRPQ_AHB_Pos)                /* (GMAC_IMRPQ) Transmit Frame Corruption Due to System Bus Error Mask */
#define GMAC_IMRPQ_AHB(value)                 (GMAC_IMRPQ_AHB_Msk & (_UINT32_(value) << GMAC_IMRPQ_AHB_Pos)) /* Assigment of value for AHB in the GMAC_IMRPQ register */
#define GMAC_IMRPQ_TCOMP_Pos                  _UINT32_(7)                                          /* (GMAC_IMRPQ) Transmit Complete Position */
#define GMAC_IMRPQ_TCOMP_Msk                  (_UINT32_(0x1) << GMAC_IMRPQ_TCOMP_Pos)              /* (GMAC_IMRPQ) Transmit Complete Mask */
#define GMAC_IMRPQ_TCOMP(value)               (GMAC_IMRPQ_TCOMP_Msk & (_UINT32_(value) << GMAC_IMRPQ_TCOMP_Pos)) /* Assigment of value for TCOMP in the GMAC_IMRPQ register */
#define GMAC_IMRPQ_HRESP_Pos                  _UINT32_(11)                                         /* (GMAC_IMRPQ) System Bus Error Position */
#define GMAC_IMRPQ_HRESP_Msk                  (_UINT32_(0x1) << GMAC_IMRPQ_HRESP_Pos)              /* (GMAC_IMRPQ) System Bus Error Mask */
#define GMAC_IMRPQ_HRESP(value)               (GMAC_IMRPQ_HRESP_Msk & (_UINT32_(value) << GMAC_IMRPQ_HRESP_Pos)) /* Assigment of value for HRESP in the GMAC_IMRPQ register */
#define GMAC_IMRPQ_Msk                        _UINT32_(0x000008E6)                                 /* (GMAC_IMRPQ) Register Mask  */


/* -------- GMAC_ST2ER : (GMAC Offset: 0x6E0) (R/W 32) Screening Type 2 Ethertype Register (index = 0) -------- */
#define GMAC_ST2ER_RESETVALUE                 _UINT32_(0x00)                                       /*  (GMAC_ST2ER) Screening Type 2 Ethertype Register (index = 0)  Reset Value */

#define GMAC_ST2ER_COMPVAL_Pos                _UINT32_(0)                                          /* (GMAC_ST2ER) Ethertype Compare Value Position */
#define GMAC_ST2ER_COMPVAL_Msk                (_UINT32_(0xFFFF) << GMAC_ST2ER_COMPVAL_Pos)         /* (GMAC_ST2ER) Ethertype Compare Value Mask */
#define GMAC_ST2ER_COMPVAL(value)             (GMAC_ST2ER_COMPVAL_Msk & (_UINT32_(value) << GMAC_ST2ER_COMPVAL_Pos)) /* Assigment of value for COMPVAL in the GMAC_ST2ER register */
#define GMAC_ST2ER_Msk                        _UINT32_(0x0000FFFF)                                 /* (GMAC_ST2ER) Register Mask  */


/* -------- GMAC_ENST_START_Q : (GMAC Offset: 0x800) (R/W 32) ENST Start Time Queue Register (index = 0) -------- */
#define GMAC_ENST_START_Q_RESETVALUE          _UINT32_(0x1FFFF)                                    /*  (GMAC_ENST_START_Q) ENST Start Time Queue Register (index = 0)  Reset Value */

#define GMAC_ENST_START_Q_START_NSEC_Pos      _UINT32_(0)                                          /* (GMAC_ENST_START_Q) Nanoseconds for Start Time Position */
#define GMAC_ENST_START_Q_START_NSEC_Msk      (_UINT32_(0x3FFFFFFF) << GMAC_ENST_START_Q_START_NSEC_Pos) /* (GMAC_ENST_START_Q) Nanoseconds for Start Time Mask */
#define GMAC_ENST_START_Q_START_NSEC(value)   (GMAC_ENST_START_Q_START_NSEC_Msk & (_UINT32_(value) << GMAC_ENST_START_Q_START_NSEC_Pos)) /* Assigment of value for START_NSEC in the GMAC_ENST_START_Q register */
#define GMAC_ENST_START_Q_START_SEC_Pos       _UINT32_(30)                                         /* (GMAC_ENST_START_Q) Seconds for Start Time Position */
#define GMAC_ENST_START_Q_START_SEC_Msk       (_UINT32_(0x3) << GMAC_ENST_START_Q_START_SEC_Pos)   /* (GMAC_ENST_START_Q) Seconds for Start Time Mask */
#define GMAC_ENST_START_Q_START_SEC(value)    (GMAC_ENST_START_Q_START_SEC_Msk & (_UINT32_(value) << GMAC_ENST_START_Q_START_SEC_Pos)) /* Assigment of value for START_SEC in the GMAC_ENST_START_Q register */
#define GMAC_ENST_START_Q_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (GMAC_ENST_START_Q) Register Mask  */


/* -------- GMAC_ENST_ON_Q : (GMAC Offset: 0x820) (R/W 32) ENST On Time Queue Register (index = 0) -------- */
#define GMAC_ENST_ON_Q_RESETVALUE             _UINT32_(0x1FFFF)                                    /*  (GMAC_ENST_ON_Q) ENST On Time Queue Register (index = 0)  Reset Value */

#define GMAC_ENST_ON_Q_ON_TIME_Pos            _UINT32_(0)                                          /* (GMAC_ENST_ON_Q) Time for which the Queue is to be Open Position */
#define GMAC_ENST_ON_Q_ON_TIME_Msk            (_UINT32_(0x1FFFF) << GMAC_ENST_ON_Q_ON_TIME_Pos)    /* (GMAC_ENST_ON_Q) Time for which the Queue is to be Open Mask */
#define GMAC_ENST_ON_Q_ON_TIME(value)         (GMAC_ENST_ON_Q_ON_TIME_Msk & (_UINT32_(value) << GMAC_ENST_ON_Q_ON_TIME_Pos)) /* Assigment of value for ON_TIME in the GMAC_ENST_ON_Q register */
#define GMAC_ENST_ON_Q_Msk                    _UINT32_(0x0001FFFF)                                 /* (GMAC_ENST_ON_Q) Register Mask  */


/* -------- GMAC_ENST_OFF_Q : (GMAC Offset: 0x840) (R/W 32) ENST Off Time Queue Register (index = 0) -------- */
#define GMAC_ENST_OFF_Q_RESETVALUE            _UINT32_(0x00)                                       /*  (GMAC_ENST_OFF_Q) ENST Off Time Queue Register (index = 0)  Reset Value */

#define GMAC_ENST_OFF_Q_OFF_TIME_Pos          _UINT32_(0)                                          /* (GMAC_ENST_OFF_Q) Time for which the Queue is to be Blocked Position */
#define GMAC_ENST_OFF_Q_OFF_TIME_Msk          (_UINT32_(0x1FFFF) << GMAC_ENST_OFF_Q_OFF_TIME_Pos)  /* (GMAC_ENST_OFF_Q) Time for which the Queue is to be Blocked Mask */
#define GMAC_ENST_OFF_Q_OFF_TIME(value)       (GMAC_ENST_OFF_Q_OFF_TIME_Msk & (_UINT32_(value) << GMAC_ENST_OFF_Q_OFF_TIME_Pos)) /* Assigment of value for OFF_TIME in the GMAC_ENST_OFF_Q register */
#define GMAC_ENST_OFF_Q_Msk                   _UINT32_(0x0001FFFF)                                 /* (GMAC_ENST_OFF_Q) Register Mask  */


/* -------- GMAC_ENST_CR : (GMAC Offset: 0x880) (R/W 32) ENST Control Register -------- */
#define GMAC_ENST_CR_RESETVALUE               _UINT32_(0x00)                                       /*  (GMAC_ENST_CR) ENST Control Register  Reset Value */

#define GMAC_ENST_CR_EN_Q0_Pos                _UINT32_(0)                                          /* (GMAC_ENST_CR) Enhanced Scheduled Traffic Enable for Queue 0 Position */
#define GMAC_ENST_CR_EN_Q0_Msk                (_UINT32_(0x1) << GMAC_ENST_CR_EN_Q0_Pos)            /* (GMAC_ENST_CR) Enhanced Scheduled Traffic Enable for Queue 0 Mask */
#define GMAC_ENST_CR_EN_Q0(value)             (GMAC_ENST_CR_EN_Q0_Msk & (_UINT32_(value) << GMAC_ENST_CR_EN_Q0_Pos)) /* Assigment of value for EN_Q0 in the GMAC_ENST_CR register */
#define   GMAC_ENST_CR_EN_Q0_0_Val            _UINT32_(0x0)                                        /* (GMAC_ENST_CR) Disables the enhanced scheduled traffic for queue x.  */
#define   GMAC_ENST_CR_EN_Q0_1_Val            _UINT32_(0x1)                                        /* (GMAC_ENST_CR) Enables the enhanced scheduled traffic for queue x. EMAC has only 1 queue and ENST is enabled by writing EN_Q0.  */
#define GMAC_ENST_CR_EN_Q0_0                  (GMAC_ENST_CR_EN_Q0_0_Val << GMAC_ENST_CR_EN_Q0_Pos) /* (GMAC_ENST_CR) Disables the enhanced scheduled traffic for queue x. Position  */
#define GMAC_ENST_CR_EN_Q0_1                  (GMAC_ENST_CR_EN_Q0_1_Val << GMAC_ENST_CR_EN_Q0_Pos) /* (GMAC_ENST_CR) Enables the enhanced scheduled traffic for queue x. EMAC has only 1 queue and ENST is enabled by writing EN_Q0. Position  */
#define GMAC_ENST_CR_EN_Q1_Pos                _UINT32_(1)                                          /* (GMAC_ENST_CR) Enhanced Scheduled Traffic Enable for Queue 1 Position */
#define GMAC_ENST_CR_EN_Q1_Msk                (_UINT32_(0x1) << GMAC_ENST_CR_EN_Q1_Pos)            /* (GMAC_ENST_CR) Enhanced Scheduled Traffic Enable for Queue 1 Mask */
#define GMAC_ENST_CR_EN_Q1(value)             (GMAC_ENST_CR_EN_Q1_Msk & (_UINT32_(value) << GMAC_ENST_CR_EN_Q1_Pos)) /* Assigment of value for EN_Q1 in the GMAC_ENST_CR register */
#define   GMAC_ENST_CR_EN_Q1_0_Val            _UINT32_(0x0)                                        /* (GMAC_ENST_CR) Disables the enhanced scheduled traffic for queue x.  */
#define   GMAC_ENST_CR_EN_Q1_1_Val            _UINT32_(0x1)                                        /* (GMAC_ENST_CR) Enables the enhanced scheduled traffic for queue x. EMAC has only 1 queue and ENST is enabled by writing EN_Q0.  */
#define GMAC_ENST_CR_EN_Q1_0                  (GMAC_ENST_CR_EN_Q1_0_Val << GMAC_ENST_CR_EN_Q1_Pos) /* (GMAC_ENST_CR) Disables the enhanced scheduled traffic for queue x. Position  */
#define GMAC_ENST_CR_EN_Q1_1                  (GMAC_ENST_CR_EN_Q1_1_Val << GMAC_ENST_CR_EN_Q1_Pos) /* (GMAC_ENST_CR) Enables the enhanced scheduled traffic for queue x. EMAC has only 1 queue and ENST is enabled by writing EN_Q0. Position  */
#define GMAC_ENST_CR_EN_Q2_Pos                _UINT32_(2)                                          /* (GMAC_ENST_CR) Enhanced Scheduled Traffic Enable for Queue 2 Position */
#define GMAC_ENST_CR_EN_Q2_Msk                (_UINT32_(0x1) << GMAC_ENST_CR_EN_Q2_Pos)            /* (GMAC_ENST_CR) Enhanced Scheduled Traffic Enable for Queue 2 Mask */
#define GMAC_ENST_CR_EN_Q2(value)             (GMAC_ENST_CR_EN_Q2_Msk & (_UINT32_(value) << GMAC_ENST_CR_EN_Q2_Pos)) /* Assigment of value for EN_Q2 in the GMAC_ENST_CR register */
#define   GMAC_ENST_CR_EN_Q2_0_Val            _UINT32_(0x0)                                        /* (GMAC_ENST_CR) Disables the enhanced scheduled traffic for queue x.  */
#define   GMAC_ENST_CR_EN_Q2_1_Val            _UINT32_(0x1)                                        /* (GMAC_ENST_CR) Enables the enhanced scheduled traffic for queue x. EMAC has only 1 queue and ENST is enabled by writing EN_Q0.  */
#define GMAC_ENST_CR_EN_Q2_0                  (GMAC_ENST_CR_EN_Q2_0_Val << GMAC_ENST_CR_EN_Q2_Pos) /* (GMAC_ENST_CR) Disables the enhanced scheduled traffic for queue x. Position  */
#define GMAC_ENST_CR_EN_Q2_1                  (GMAC_ENST_CR_EN_Q2_1_Val << GMAC_ENST_CR_EN_Q2_Pos) /* (GMAC_ENST_CR) Enables the enhanced scheduled traffic for queue x. EMAC has only 1 queue and ENST is enabled by writing EN_Q0. Position  */
#define GMAC_ENST_CR_EN_Q3_Pos                _UINT32_(3)                                          /* (GMAC_ENST_CR) Enhanced Scheduled Traffic Enable for Queue 3 Position */
#define GMAC_ENST_CR_EN_Q3_Msk                (_UINT32_(0x1) << GMAC_ENST_CR_EN_Q3_Pos)            /* (GMAC_ENST_CR) Enhanced Scheduled Traffic Enable for Queue 3 Mask */
#define GMAC_ENST_CR_EN_Q3(value)             (GMAC_ENST_CR_EN_Q3_Msk & (_UINT32_(value) << GMAC_ENST_CR_EN_Q3_Pos)) /* Assigment of value for EN_Q3 in the GMAC_ENST_CR register */
#define   GMAC_ENST_CR_EN_Q3_0_Val            _UINT32_(0x0)                                        /* (GMAC_ENST_CR) Disables the enhanced scheduled traffic for queue x.  */
#define   GMAC_ENST_CR_EN_Q3_1_Val            _UINT32_(0x1)                                        /* (GMAC_ENST_CR) Enables the enhanced scheduled traffic for queue x. EMAC has only 1 queue and ENST is enabled by writing EN_Q0.  */
#define GMAC_ENST_CR_EN_Q3_0                  (GMAC_ENST_CR_EN_Q3_0_Val << GMAC_ENST_CR_EN_Q3_Pos) /* (GMAC_ENST_CR) Disables the enhanced scheduled traffic for queue x. Position  */
#define GMAC_ENST_CR_EN_Q3_1                  (GMAC_ENST_CR_EN_Q3_1_Val << GMAC_ENST_CR_EN_Q3_Pos) /* (GMAC_ENST_CR) Enables the enhanced scheduled traffic for queue x. EMAC has only 1 queue and ENST is enabled by writing EN_Q0. Position  */
#define GMAC_ENST_CR_EN_Q4_Pos                _UINT32_(4)                                          /* (GMAC_ENST_CR) Enhanced Scheduled Traffic Enable for Queue 4 Position */
#define GMAC_ENST_CR_EN_Q4_Msk                (_UINT32_(0x1) << GMAC_ENST_CR_EN_Q4_Pos)            /* (GMAC_ENST_CR) Enhanced Scheduled Traffic Enable for Queue 4 Mask */
#define GMAC_ENST_CR_EN_Q4(value)             (GMAC_ENST_CR_EN_Q4_Msk & (_UINT32_(value) << GMAC_ENST_CR_EN_Q4_Pos)) /* Assigment of value for EN_Q4 in the GMAC_ENST_CR register */
#define   GMAC_ENST_CR_EN_Q4_0_Val            _UINT32_(0x0)                                        /* (GMAC_ENST_CR) Disables the enhanced scheduled traffic for queue x.  */
#define   GMAC_ENST_CR_EN_Q4_1_Val            _UINT32_(0x1)                                        /* (GMAC_ENST_CR) Enables the enhanced scheduled traffic for queue x. EMAC has only 1 queue and ENST is enabled by writing EN_Q0.  */
#define GMAC_ENST_CR_EN_Q4_0                  (GMAC_ENST_CR_EN_Q4_0_Val << GMAC_ENST_CR_EN_Q4_Pos) /* (GMAC_ENST_CR) Disables the enhanced scheduled traffic for queue x. Position  */
#define GMAC_ENST_CR_EN_Q4_1                  (GMAC_ENST_CR_EN_Q4_1_Val << GMAC_ENST_CR_EN_Q4_Pos) /* (GMAC_ENST_CR) Enables the enhanced scheduled traffic for queue x. EMAC has only 1 queue and ENST is enabled by writing EN_Q0. Position  */
#define GMAC_ENST_CR_EN_Q5_Pos                _UINT32_(5)                                          /* (GMAC_ENST_CR) Enhanced Scheduled Traffic Enable for Queue 5 Position */
#define GMAC_ENST_CR_EN_Q5_Msk                (_UINT32_(0x1) << GMAC_ENST_CR_EN_Q5_Pos)            /* (GMAC_ENST_CR) Enhanced Scheduled Traffic Enable for Queue 5 Mask */
#define GMAC_ENST_CR_EN_Q5(value)             (GMAC_ENST_CR_EN_Q5_Msk & (_UINT32_(value) << GMAC_ENST_CR_EN_Q5_Pos)) /* Assigment of value for EN_Q5 in the GMAC_ENST_CR register */
#define   GMAC_ENST_CR_EN_Q5_0_Val            _UINT32_(0x0)                                        /* (GMAC_ENST_CR) Disables the enhanced scheduled traffic for queue x.  */
#define   GMAC_ENST_CR_EN_Q5_1_Val            _UINT32_(0x1)                                        /* (GMAC_ENST_CR) Enables the enhanced scheduled traffic for queue x. EMAC has only 1 queue and ENST is enabled by writing EN_Q0.  */
#define GMAC_ENST_CR_EN_Q5_0                  (GMAC_ENST_CR_EN_Q5_0_Val << GMAC_ENST_CR_EN_Q5_Pos) /* (GMAC_ENST_CR) Disables the enhanced scheduled traffic for queue x. Position  */
#define GMAC_ENST_CR_EN_Q5_1                  (GMAC_ENST_CR_EN_Q5_1_Val << GMAC_ENST_CR_EN_Q5_Pos) /* (GMAC_ENST_CR) Enables the enhanced scheduled traffic for queue x. EMAC has only 1 queue and ENST is enabled by writing EN_Q0. Position  */
#define GMAC_ENST_CR_Msk                      _UINT32_(0x0000003F)                                 /* (GMAC_ENST_CR) Register Mask  */

#define GMAC_ENST_CR_EN_Q_Pos                 _UINT32_(0)                                          /* (GMAC_ENST_CR Position) Enhanced Scheduled Traffic Enable for Queue 5 */
#define GMAC_ENST_CR_EN_Q_Msk                 (_UINT32_(0x3F) << GMAC_ENST_CR_EN_Q_Pos)            /* (GMAC_ENST_CR Mask) EN_Q */
#define GMAC_ENST_CR_EN_Q(value)              (GMAC_ENST_CR_EN_Q_Msk & (_UINT32_(value) << GMAC_ENST_CR_EN_Q_Pos)) 

/* -------- GMAC_FRER_TIMEOUT : (GMAC Offset: 0x8A0) (R/W 32) Frame Elimination Timeout Register -------- */
#define GMAC_FRER_TIMEOUT_RESETVALUE          _UINT32_(0x00)                                       /*  (GMAC_FRER_TIMEOUT) Frame Elimination Timeout Register  Reset Value */

#define GMAC_FRER_TIMEOUT_TIMEOUT_Pos         _UINT32_(0)                                          /* (GMAC_FRER_TIMEOUT) Sequence Recovery Timer Restart Period for Credit Based Streams Position */
#define GMAC_FRER_TIMEOUT_TIMEOUT_Msk         (_UINT32_(0xFFFF) << GMAC_FRER_TIMEOUT_TIMEOUT_Pos)  /* (GMAC_FRER_TIMEOUT) Sequence Recovery Timer Restart Period for Credit Based Streams Mask */
#define GMAC_FRER_TIMEOUT_TIMEOUT(value)      (GMAC_FRER_TIMEOUT_TIMEOUT_Msk & (_UINT32_(value) << GMAC_FRER_TIMEOUT_TIMEOUT_Pos)) /* Assigment of value for TIMEOUT in the GMAC_FRER_TIMEOUT register */
#define GMAC_FRER_TIMEOUT_Msk                 _UINT32_(0x0000FFFF)                                 /* (GMAC_FRER_TIMEOUT) Register Mask  */


/* -------- GMAC_FRER_REDTAG : (GMAC Offset: 0x8A4) (R/W 32) Frame Elimination Redundancy Tag Register -------- */
#define GMAC_FRER_REDTAG_RESETVALUE           _UINT32_(0x4000F1C1)                                 /*  (GMAC_FRER_REDTAG) Frame Elimination Redundancy Tag Register  Reset Value */

#define GMAC_FRER_REDTAG_RED_TAG_Pos          _UINT32_(0)                                          /* (GMAC_FRER_REDTAG) Redundancy Tag (R-TAG) Position */
#define GMAC_FRER_REDTAG_RED_TAG_Msk          (_UINT32_(0xFFFF) << GMAC_FRER_REDTAG_RED_TAG_Pos)   /* (GMAC_FRER_REDTAG) Redundancy Tag (R-TAG) Mask */
#define GMAC_FRER_REDTAG_RED_TAG(value)       (GMAC_FRER_REDTAG_RED_TAG_Msk & (_UINT32_(value) << GMAC_FRER_REDTAG_RED_TAG_Pos)) /* Assigment of value for RED_TAG in the GMAC_FRER_REDTAG register */
#define GMAC_FRER_REDTAG_SIX_BYTE_TAG_Pos     _UINT32_(30)                                         /* (GMAC_FRER_REDTAG) Six-byte Tag Enable Position */
#define GMAC_FRER_REDTAG_SIX_BYTE_TAG_Msk     (_UINT32_(0x1) << GMAC_FRER_REDTAG_SIX_BYTE_TAG_Pos) /* (GMAC_FRER_REDTAG) Six-byte Tag Enable Mask */
#define GMAC_FRER_REDTAG_SIX_BYTE_TAG(value)  (GMAC_FRER_REDTAG_SIX_BYTE_TAG_Msk & (_UINT32_(value) << GMAC_FRER_REDTAG_SIX_BYTE_TAG_Pos)) /* Assigment of value for SIX_BYTE_TAG in the GMAC_FRER_REDTAG register */
#define   GMAC_FRER_REDTAG_SIX_BYTE_TAG_0_Val _UINT32_(0x0)                                        /* (GMAC_FRER_REDTAG) Defines a four-byte tag as per 802.1CB standard revision 2.4 and earlier.  */
#define   GMAC_FRER_REDTAG_SIX_BYTE_TAG_1_Val _UINT32_(0x1)                                        /* (GMAC_FRER_REDTAG) Enables the six-byte tag as per 802.1CB standard revision 2.4 and later.  */
#define GMAC_FRER_REDTAG_SIX_BYTE_TAG_0       (GMAC_FRER_REDTAG_SIX_BYTE_TAG_0_Val << GMAC_FRER_REDTAG_SIX_BYTE_TAG_Pos) /* (GMAC_FRER_REDTAG) Defines a four-byte tag as per 802.1CB standard revision 2.4 and earlier. Position  */
#define GMAC_FRER_REDTAG_SIX_BYTE_TAG_1       (GMAC_FRER_REDTAG_SIX_BYTE_TAG_1_Val << GMAC_FRER_REDTAG_SIX_BYTE_TAG_Pos) /* (GMAC_FRER_REDTAG) Enables the six-byte tag as per 802.1CB standard revision 2.4 and later. Position  */
#define GMAC_FRER_REDTAG_STRIP_R_TAG_Pos      _UINT32_(31)                                         /* (GMAC_FRER_REDTAG) Stripping Redundancy Tag Enable Position */
#define GMAC_FRER_REDTAG_STRIP_R_TAG_Msk      (_UINT32_(0x1) << GMAC_FRER_REDTAG_STRIP_R_TAG_Pos)  /* (GMAC_FRER_REDTAG) Stripping Redundancy Tag Enable Mask */
#define GMAC_FRER_REDTAG_STRIP_R_TAG(value)   (GMAC_FRER_REDTAG_STRIP_R_TAG_Msk & (_UINT32_(value) << GMAC_FRER_REDTAG_STRIP_R_TAG_Pos)) /* Assigment of value for STRIP_R_TAG in the GMAC_FRER_REDTAG register */
#define   GMAC_FRER_REDTAG_STRIP_R_TAG_0_Val  _UINT32_(0x0)                                        /* (GMAC_FRER_REDTAG) Disables the stripping function. When the statistics counters need to reflect the actual number of octets received, then the stripping functionality must be disabled.  */
#define   GMAC_FRER_REDTAG_STRIP_R_TAG_1_Val  _UINT32_(0x1)                                        /* (GMAC_FRER_REDTAG) Enables the stripping function, the receive octet counters reflect post deletion frame size so the frame elimination functionality is transparent to higher level management.  */
#define GMAC_FRER_REDTAG_STRIP_R_TAG_0        (GMAC_FRER_REDTAG_STRIP_R_TAG_0_Val << GMAC_FRER_REDTAG_STRIP_R_TAG_Pos) /* (GMAC_FRER_REDTAG) Disables the stripping function. When the statistics counters need to reflect the actual number of octets received, then the stripping functionality must be disabled. Position  */
#define GMAC_FRER_REDTAG_STRIP_R_TAG_1        (GMAC_FRER_REDTAG_STRIP_R_TAG_1_Val << GMAC_FRER_REDTAG_STRIP_R_TAG_Pos) /* (GMAC_FRER_REDTAG) Enables the stripping function, the receive octet counters reflect post deletion frame size so the frame elimination functionality is transparent to higher level management. Position  */
#define GMAC_FRER_REDTAG_Msk                  _UINT32_(0xC000FFFF)                                 /* (GMAC_FRER_REDTAG) Register Mask  */


/* -------- GMAC_RX_FLUSH_Q : (GMAC Offset: 0xB00) (R/W 32) Receive Queue Flush Register (index = 0) -------- */
#define GMAC_RX_FLUSH_Q_RESETVALUE            _UINT32_(0x00)                                       /*  (GMAC_RX_FLUSH_Q) Receive Queue Flush Register (index = 0)  Reset Value */

#define GMAC_RX_FLUSH_Q_DROP_ALL_Pos          _UINT32_(0)                                          /* (GMAC_RX_FLUSH_Q) Drop All Frames Position */
#define GMAC_RX_FLUSH_Q_DROP_ALL_Msk          (_UINT32_(0x1) << GMAC_RX_FLUSH_Q_DROP_ALL_Pos)      /* (GMAC_RX_FLUSH_Q) Drop All Frames Mask */
#define GMAC_RX_FLUSH_Q_DROP_ALL(value)       (GMAC_RX_FLUSH_Q_DROP_ALL_Msk & (_UINT32_(value) << GMAC_RX_FLUSH_Q_DROP_ALL_Pos)) /* Assigment of value for DROP_ALL in the GMAC_RX_FLUSH_Q register */
#define   GMAC_RX_FLUSH_Q_DROP_ALL_DISABLED_Val _UINT32_(0x0)                                        /* (GMAC_RX_FLUSH_Q) No effect.  */
#define   GMAC_RX_FLUSH_Q_DROP_ALL_ENABLED_Val _UINT32_(0x1)                                        /* (GMAC_RX_FLUSH_Q) Drops all frames of this queue.  */
#define GMAC_RX_FLUSH_Q_DROP_ALL_DISABLED     (GMAC_RX_FLUSH_Q_DROP_ALL_DISABLED_Val << GMAC_RX_FLUSH_Q_DROP_ALL_Pos) /* (GMAC_RX_FLUSH_Q) No effect. Position  */
#define GMAC_RX_FLUSH_Q_DROP_ALL_ENABLED      (GMAC_RX_FLUSH_Q_DROP_ALL_ENABLED_Val << GMAC_RX_FLUSH_Q_DROP_ALL_Pos) /* (GMAC_RX_FLUSH_Q) Drops all frames of this queue. Position  */
#define GMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_Pos _UINT32_(1)                                          /* (GMAC_RX_FLUSH_Q) Drop on Resource Error Position */
#define GMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_Msk (_UINT32_(0x1) << GMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_Pos) /* (GMAC_RX_FLUSH_Q) Drop on Resource Error Mask */
#define GMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR(value) (GMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_Msk & (_UINT32_(value) << GMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_Pos)) /* Assigment of value for DROP_ON_RESRC_ERR in the GMAC_RX_FLUSH_Q register */
#define   GMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_DISABLED_Val _UINT32_(0x0)                                        /* (GMAC_RX_FLUSH_Q) No effect.  */
#define   GMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_ENABLED_Val _UINT32_(0x1)                                        /* (GMAC_RX_FLUSH_Q) If a free DMA descriptor for this queue cannot be obtained (also referred to as lack of descriptor resource and occurs when the software either cannot free up descriptors quickly enough to meet the receive traffic rate or has deliberately decided not to free any descriptors), all new frames received on this queue will be automatically discarded.  */
#define GMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_DISABLED (GMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_DISABLED_Val << GMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_Pos) /* (GMAC_RX_FLUSH_Q) No effect. Position  */
#define GMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_ENABLED (GMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_ENABLED_Val << GMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_Pos) /* (GMAC_RX_FLUSH_Q) If a free DMA descriptor for this queue cannot be obtained (also referred to as lack of descriptor resource and occurs when the software either cannot free up descriptors quickly enough to meet the receive traffic rate or has deliberately decided not to free any descriptors), all new frames received on this queue will be automatically discarded. Position  */
#define GMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_Pos   _UINT32_(2)                                          /* (GMAC_RX_FLUSH_Q) Limitation of the Number of 128-Byte Chunk of Data Stored in the Memory of this Queue Position */
#define GMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_Msk   (_UINT32_(0x1) << GMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_Pos) /* (GMAC_RX_FLUSH_Q) Limitation of the Number of 128-Byte Chunk of Data Stored in the Memory of this Queue Mask */
#define GMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES(value) (GMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_Msk & (_UINT32_(value) << GMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_Pos)) /* Assigment of value for LIMIT_NUM_BYTES in the GMAC_RX_FLUSH_Q register */
#define   GMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_DISABLED_Val _UINT32_(0x0)                                        /* (GMAC_RX_FLUSH_Q) No effect.  */
#define   GMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_ENABLED_Val _UINT32_(0x1)                                        /* (GMAC_RX_FLUSH_Q) Limits the number of 128 byte chunks of data received for this queue and already stored in the memory of the queue awaiting DMA memory writes to the value defined in the field MAX_VAL.  */
#define GMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_DISABLED (GMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_DISABLED_Val << GMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_Pos) /* (GMAC_RX_FLUSH_Q) No effect. Position  */
#define GMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_ENABLED (GMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_ENABLED_Val << GMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_Pos) /* (GMAC_RX_FLUSH_Q) Limits the number of 128 byte chunks of data received for this queue and already stored in the memory of the queue awaiting DMA memory writes to the value defined in the field MAX_VAL. Position  */
#define GMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_Pos  _UINT32_(3)                                          /* (GMAC_RX_FLUSH_Q) Maximum Frame-length Received Position */
#define GMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_Msk  (_UINT32_(0x1) << GMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_Pos) /* (GMAC_RX_FLUSH_Q) Maximum Frame-length Received Mask */
#define GMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE(value) (GMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_Msk & (_UINT32_(value) << GMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_Pos)) /* Assigment of value for LIMIT_FRAME_SIZE in the GMAC_RX_FLUSH_Q register */
#define   GMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_DISABLED_Val _UINT32_(0x0)                                        /* (GMAC_RX_FLUSH_Q) No effect.  */
#define   GMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_ENABLED_Val _UINT32_(0x1)                                        /* (GMAC_RX_FLUSH_Q) When set, MAX_VAL indicates the maximum frame-length in bytes that may be received. Frames exceeding this length will be dropped. This traffic policing function is relevant to the 802.1Qci standard which specifies stream filtering based on a maximum service data unit (SDU) size.  */
#define GMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_DISABLED (GMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_DISABLED_Val << GMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_Pos) /* (GMAC_RX_FLUSH_Q) No effect. Position  */
#define GMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_ENABLED (GMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_ENABLED_Val << GMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_Pos) /* (GMAC_RX_FLUSH_Q) When set, MAX_VAL indicates the maximum frame-length in bytes that may be received. Frames exceeding this length will be dropped. This traffic policing function is relevant to the 802.1Qci standard which specifies stream filtering based on a maximum service data unit (SDU) size. Position  */
#define GMAC_RX_FLUSH_Q_MAX_VAL_Pos           _UINT32_(16)                                         /* (GMAC_RX_FLUSH_Q) Maximum Value for the Received Frame Size or Number of 128-Byte Chunk Position */
#define GMAC_RX_FLUSH_Q_MAX_VAL_Msk           (_UINT32_(0xFFFF) << GMAC_RX_FLUSH_Q_MAX_VAL_Pos)    /* (GMAC_RX_FLUSH_Q) Maximum Value for the Received Frame Size or Number of 128-Byte Chunk Mask */
#define GMAC_RX_FLUSH_Q_MAX_VAL(value)        (GMAC_RX_FLUSH_Q_MAX_VAL_Msk & (_UINT32_(value) << GMAC_RX_FLUSH_Q_MAX_VAL_Pos)) /* Assigment of value for MAX_VAL in the GMAC_RX_FLUSH_Q register */
#define GMAC_RX_FLUSH_Q_Msk                   _UINT32_(0xFFFF000F)                                 /* (GMAC_RX_FLUSH_Q) Register Mask  */


/* -------- GMAC_SCR2_RATE_LIMIT : (GMAC Offset: 0xB40) (R/W 32) Screening 2 Rate Limit Register (index = 0) -------- */
#define GMAC_SCR2_RATE_LIMIT_RESETVALUE       _UINT32_(0x00)                                       /*  (GMAC_SCR2_RATE_LIMIT) Screening 2 Rate Limit Register (index = 0)  Reset Value */

#define GMAC_SCR2_RATE_LIMIT_INTERVAL_TIME_Pos _UINT32_(0)                                          /* (GMAC_SCR2_RATE_LIMIT) Interval Time for Maximum Rate Checking Position */
#define GMAC_SCR2_RATE_LIMIT_INTERVAL_TIME_Msk (_UINT32_(0xFFFF) << GMAC_SCR2_RATE_LIMIT_INTERVAL_TIME_Pos) /* (GMAC_SCR2_RATE_LIMIT) Interval Time for Maximum Rate Checking Mask */
#define GMAC_SCR2_RATE_LIMIT_INTERVAL_TIME(value) (GMAC_SCR2_RATE_LIMIT_INTERVAL_TIME_Msk & (_UINT32_(value) << GMAC_SCR2_RATE_LIMIT_INTERVAL_TIME_Pos)) /* Assigment of value for INTERVAL_TIME in the GMAC_SCR2_RATE_LIMIT register */
#define GMAC_SCR2_RATE_LIMIT_MAX_RATE_VAL_Pos _UINT32_(16)                                         /* (GMAC_SCR2_RATE_LIMIT) Maximum Rate Value for the Interval Time Position */
#define GMAC_SCR2_RATE_LIMIT_MAX_RATE_VAL_Msk (_UINT32_(0xFFFF) << GMAC_SCR2_RATE_LIMIT_MAX_RATE_VAL_Pos) /* (GMAC_SCR2_RATE_LIMIT) Maximum Rate Value for the Interval Time Mask */
#define GMAC_SCR2_RATE_LIMIT_MAX_RATE_VAL(value) (GMAC_SCR2_RATE_LIMIT_MAX_RATE_VAL_Msk & (_UINT32_(value) << GMAC_SCR2_RATE_LIMIT_MAX_RATE_VAL_Pos)) /* Assigment of value for MAX_RATE_VAL in the GMAC_SCR2_RATE_LIMIT register */
#define GMAC_SCR2_RATE_LIMIT_Msk              _UINT32_(0xFFFFFFFF)                                 /* (GMAC_SCR2_RATE_LIMIT) Register Mask  */


/* -------- GMAC_SCR2_RATE_STATUS : (GMAC Offset: 0xB80) ( R/ 32) Screening 2 Rate Status Register -------- */
#define GMAC_SCR2_RATE_STATUS_RESETVALUE      _UINT32_(0x00)                                       /*  (GMAC_SCR2_RATE_STATUS) Screening 2 Rate Status Register  Reset Value */

#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_Pos _UINT32_(0)                                          /* (GMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 0 Position */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_Msk (_UINT32_(0x1) << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_Pos) /* (GMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 0 Mask */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0(value) (GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_Msk & (_UINT32_(value) << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_Pos)) /* Assigment of value for EXCESS_RATE_Q0 in the GMAC_SCR2_RATE_STATUS register */
#define   GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_0_Val _UINT32_(0x0)                                        /* (GMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_SCR2_RATE_STATUS.  */
#define   GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_1_Val _UINT32_(0x1)                                        /* (GMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_SCR2_RATE_STATUS.  */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_0 (GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_0_Val << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_Pos) /* (GMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_1 (GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_1_Val << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_Pos) /* (GMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_Pos _UINT32_(1)                                          /* (GMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 1 Position */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_Msk (_UINT32_(0x1) << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_Pos) /* (GMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 1 Mask */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1(value) (GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_Msk & (_UINT32_(value) << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_Pos)) /* Assigment of value for EXCESS_RATE_Q1 in the GMAC_SCR2_RATE_STATUS register */
#define   GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_0_Val _UINT32_(0x0)                                        /* (GMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_SCR2_RATE_STATUS.  */
#define   GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_1_Val _UINT32_(0x1)                                        /* (GMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_SCR2_RATE_STATUS.  */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_0 (GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_0_Val << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_Pos) /* (GMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_1 (GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_1_Val << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_Pos) /* (GMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_Pos _UINT32_(2)                                          /* (GMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 2 Position */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_Msk (_UINT32_(0x1) << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_Pos) /* (GMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 2 Mask */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2(value) (GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_Msk & (_UINT32_(value) << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_Pos)) /* Assigment of value for EXCESS_RATE_Q2 in the GMAC_SCR2_RATE_STATUS register */
#define   GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_0_Val _UINT32_(0x0)                                        /* (GMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_SCR2_RATE_STATUS.  */
#define   GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_1_Val _UINT32_(0x1)                                        /* (GMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_SCR2_RATE_STATUS.  */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_0 (GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_0_Val << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_Pos) /* (GMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_1 (GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_1_Val << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_Pos) /* (GMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_Pos _UINT32_(3)                                          /* (GMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 3 Position */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_Msk (_UINT32_(0x1) << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_Pos) /* (GMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 3 Mask */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3(value) (GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_Msk & (_UINT32_(value) << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_Pos)) /* Assigment of value for EXCESS_RATE_Q3 in the GMAC_SCR2_RATE_STATUS register */
#define   GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_0_Val _UINT32_(0x0)                                        /* (GMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_SCR2_RATE_STATUS.  */
#define   GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_1_Val _UINT32_(0x1)                                        /* (GMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_SCR2_RATE_STATUS.  */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_0 (GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_0_Val << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_Pos) /* (GMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_1 (GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_1_Val << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_Pos) /* (GMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_Pos _UINT32_(4)                                          /* (GMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 4 Position */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_Msk (_UINT32_(0x1) << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_Pos) /* (GMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 4 Mask */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4(value) (GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_Msk & (_UINT32_(value) << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_Pos)) /* Assigment of value for EXCESS_RATE_Q4 in the GMAC_SCR2_RATE_STATUS register */
#define   GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_0_Val _UINT32_(0x0)                                        /* (GMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_SCR2_RATE_STATUS.  */
#define   GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_1_Val _UINT32_(0x1)                                        /* (GMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_SCR2_RATE_STATUS.  */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_0 (GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_0_Val << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_Pos) /* (GMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_1 (GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_1_Val << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_Pos) /* (GMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_Pos _UINT32_(5)                                          /* (GMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 5 Position */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_Msk (_UINT32_(0x1) << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_Pos) /* (GMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 5 Mask */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5(value) (GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_Msk & (_UINT32_(value) << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_Pos)) /* Assigment of value for EXCESS_RATE_Q5 in the GMAC_SCR2_RATE_STATUS register */
#define   GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_0_Val _UINT32_(0x0)                                        /* (GMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_SCR2_RATE_STATUS.  */
#define   GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_1_Val _UINT32_(0x1)                                        /* (GMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_SCR2_RATE_STATUS.  */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_0 (GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_0_Val << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_Pos) /* (GMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_1 (GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_1_Val << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_Pos) /* (GMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_Pos _UINT32_(6)                                          /* (GMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 6 Position */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_Msk (_UINT32_(0x1) << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_Pos) /* (GMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 6 Mask */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6(value) (GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_Msk & (_UINT32_(value) << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_Pos)) /* Assigment of value for EXCESS_RATE_Q6 in the GMAC_SCR2_RATE_STATUS register */
#define   GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_0_Val _UINT32_(0x0)                                        /* (GMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_SCR2_RATE_STATUS.  */
#define   GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_1_Val _UINT32_(0x1)                                        /* (GMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_SCR2_RATE_STATUS.  */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_0 (GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_0_Val << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_Pos) /* (GMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_1 (GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_1_Val << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_Pos) /* (GMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_Pos _UINT32_(7)                                          /* (GMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 7 Position */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_Msk (_UINT32_(0x1) << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_Pos) /* (GMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 7 Mask */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7(value) (GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_Msk & (_UINT32_(value) << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_Pos)) /* Assigment of value for EXCESS_RATE_Q7 in the GMAC_SCR2_RATE_STATUS register */
#define   GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_0_Val _UINT32_(0x0)                                        /* (GMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_SCR2_RATE_STATUS.  */
#define   GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_1_Val _UINT32_(0x1)                                        /* (GMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_SCR2_RATE_STATUS.  */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_0 (GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_0_Val << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_Pos) /* (GMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_1 (GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_1_Val << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_Pos) /* (GMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_SCR2_RATE_STATUS_Msk             _UINT32_(0x000000FF)                                 /* (GMAC_SCR2_RATE_STATUS) Register Mask  */

#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q_Pos _UINT32_(0)                                          /* (GMAC_SCR2_RATE_STATUS Position) Excessive Screener Rate Queue 7 */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q_Msk (_UINT32_(0xFF) << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q_Pos) /* (GMAC_SCR2_RATE_STATUS Mask) EXCESS_RATE_Q */
#define GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q(value) (GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q_Msk & (_UINT32_(value) << GMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q_Pos)) 

/* -------- GMAC_MMSL_CR : (GMAC Offset: 0xF00) (R/W 32) MMSL Control Register -------- */
#define GMAC_MMSL_CR_RESETVALUE               _UINT32_(0x20)                                       /*  (GMAC_MMSL_CR) MMSL Control Register  Reset Value */

#define GMAC_MMSL_CR_ADD_FRAG_SIZE_Pos        _UINT32_(0)                                          /* (GMAC_MMSL_CR) PMAC Minimum Number of Bytes before Preemption Position */
#define GMAC_MMSL_CR_ADD_FRAG_SIZE_Msk        (_UINT32_(0x3) << GMAC_MMSL_CR_ADD_FRAG_SIZE_Pos)    /* (GMAC_MMSL_CR) PMAC Minimum Number of Bytes before Preemption Mask */
#define GMAC_MMSL_CR_ADD_FRAG_SIZE(value)     (GMAC_MMSL_CR_ADD_FRAG_SIZE_Msk & (_UINT32_(value) << GMAC_MMSL_CR_ADD_FRAG_SIZE_Pos)) /* Assigment of value for ADD_FRAG_SIZE in the GMAC_MMSL_CR register */
#define   GMAC_MMSL_CR_ADD_FRAG_SIZE_64_BYTES_Val _UINT32_(0x0)                                        /* (GMAC_MMSL_CR) A minimum of 64 bytes can be sent by pMAC before any preemption. The value can be changed only when PRE_ENABLE is cleared  */
#define   GMAC_MMSL_CR_ADD_FRAG_SIZE_128_BYTES_Val _UINT32_(0x1)                                        /* (GMAC_MMSL_CR) A minimum of 128 bytes can be sent by pMAC before any preemption. The value can be changed only when PRE_ENABLE is cleared  */
#define   GMAC_MMSL_CR_ADD_FRAG_SIZE_192_BYTES_Val _UINT32_(0x2)                                        /* (GMAC_MMSL_CR) A minimum of 192 bytes can be sent by pMAC before any preemption. The value can be changed only when PRE_ENABLE is cleared  */
#define   GMAC_MMSL_CR_ADD_FRAG_SIZE_256_BYTES_Val _UINT32_(0x3)                                        /* (GMAC_MMSL_CR) A minimum of 256 bytes can be sent by pMAC before any preemption. The value can be changed only when PRE_ENABLE is cleared  */
#define GMAC_MMSL_CR_ADD_FRAG_SIZE_64_BYTES   (GMAC_MMSL_CR_ADD_FRAG_SIZE_64_BYTES_Val << GMAC_MMSL_CR_ADD_FRAG_SIZE_Pos) /* (GMAC_MMSL_CR) A minimum of 64 bytes can be sent by pMAC before any preemption. The value can be changed only when PRE_ENABLE is cleared Position  */
#define GMAC_MMSL_CR_ADD_FRAG_SIZE_128_BYTES  (GMAC_MMSL_CR_ADD_FRAG_SIZE_128_BYTES_Val << GMAC_MMSL_CR_ADD_FRAG_SIZE_Pos) /* (GMAC_MMSL_CR) A minimum of 128 bytes can be sent by pMAC before any preemption. The value can be changed only when PRE_ENABLE is cleared Position  */
#define GMAC_MMSL_CR_ADD_FRAG_SIZE_192_BYTES  (GMAC_MMSL_CR_ADD_FRAG_SIZE_192_BYTES_Val << GMAC_MMSL_CR_ADD_FRAG_SIZE_Pos) /* (GMAC_MMSL_CR) A minimum of 192 bytes can be sent by pMAC before any preemption. The value can be changed only when PRE_ENABLE is cleared Position  */
#define GMAC_MMSL_CR_ADD_FRAG_SIZE_256_BYTES  (GMAC_MMSL_CR_ADD_FRAG_SIZE_256_BYTES_Val << GMAC_MMSL_CR_ADD_FRAG_SIZE_Pos) /* (GMAC_MMSL_CR) A minimum of 256 bytes can be sent by pMAC before any preemption. The value can be changed only when PRE_ENABLE is cleared Position  */
#define GMAC_MMSL_CR_VERIFY_DISABLE_Pos       _UINT32_(2)                                          /* (GMAC_MMSL_CR) 802.3br Support Check for the Link Partner Position */
#define GMAC_MMSL_CR_VERIFY_DISABLE_Msk       (_UINT32_(0x1) << GMAC_MMSL_CR_VERIFY_DISABLE_Pos)   /* (GMAC_MMSL_CR) 802.3br Support Check for the Link Partner Mask */
#define GMAC_MMSL_CR_VERIFY_DISABLE(value)    (GMAC_MMSL_CR_VERIFY_DISABLE_Msk & (_UINT32_(value) << GMAC_MMSL_CR_VERIFY_DISABLE_Pos)) /* Assigment of value for VERIFY_DISABLE in the GMAC_MMSL_CR register */
#define   GMAC_MMSL_CR_VERIFY_DISABLE_0_Val   _UINT32_(0x0)                                        /* (GMAC_MMSL_CR) Enables the 802.3br support check for the link partner.  */
#define   GMAC_MMSL_CR_VERIFY_DISABLE_1_Val   _UINT32_(0x1)                                        /* (GMAC_MMSL_CR) Disables the 802.3br support check for the link partner and preemption is enabled as soon as PRE_ENABLE=1.  */
#define GMAC_MMSL_CR_VERIFY_DISABLE_0         (GMAC_MMSL_CR_VERIFY_DISABLE_0_Val << GMAC_MMSL_CR_VERIFY_DISABLE_Pos) /* (GMAC_MMSL_CR) Enables the 802.3br support check for the link partner. Position  */
#define GMAC_MMSL_CR_VERIFY_DISABLE_1         (GMAC_MMSL_CR_VERIFY_DISABLE_1_Val << GMAC_MMSL_CR_VERIFY_DISABLE_Pos) /* (GMAC_MMSL_CR) Disables the 802.3br support check for the link partner and preemption is enabled as soon as PRE_ENABLE=1. Position  */
#define GMAC_MMSL_CR_PRE_ENABLE_Pos           _UINT32_(3)                                          /* (GMAC_MMSL_CR) Preemption Operation Enable Position */
#define GMAC_MMSL_CR_PRE_ENABLE_Msk           (_UINT32_(0x1) << GMAC_MMSL_CR_PRE_ENABLE_Pos)       /* (GMAC_MMSL_CR) Preemption Operation Enable Mask */
#define GMAC_MMSL_CR_PRE_ENABLE(value)        (GMAC_MMSL_CR_PRE_ENABLE_Msk & (_UINT32_(value) << GMAC_MMSL_CR_PRE_ENABLE_Pos)) /* Assigment of value for PRE_ENABLE in the GMAC_MMSL_CR register */
#define   GMAC_MMSL_CR_PRE_ENABLE_0_Val       _UINT32_(0x0)                                        /* (GMAC_MMSL_CR) Disables the preemption operation and verify mpackets will not be responded to or sent. If a preemption is in progress, the current preemption will complete and no more preemption will occur.  */
#define   GMAC_MMSL_CR_PRE_ENABLE_1_Val       _UINT32_(0x1)                                        /* (GMAC_MMSL_CR) Enables the preemption by starting the verification procedure when VERIFY_DISABLE=0. Preemption can occur only once the verification process completes. If VERIFY_DISABLE=1, preemption can occur immediately.  */
#define GMAC_MMSL_CR_PRE_ENABLE_0             (GMAC_MMSL_CR_PRE_ENABLE_0_Val << GMAC_MMSL_CR_PRE_ENABLE_Pos) /* (GMAC_MMSL_CR) Disables the preemption operation and verify mpackets will not be responded to or sent. If a preemption is in progress, the current preemption will complete and no more preemption will occur. Position  */
#define GMAC_MMSL_CR_PRE_ENABLE_1             (GMAC_MMSL_CR_PRE_ENABLE_1_Val << GMAC_MMSL_CR_PRE_ENABLE_Pos) /* (GMAC_MMSL_CR) Enables the preemption by starting the verification procedure when VERIFY_DISABLE=0. Preemption can occur only once the verification process completes. If VERIFY_DISABLE=1, preemption can occur immediately. Position  */
#define GMAC_MMSL_CR_RESTART_VER_Pos          _UINT32_(4)                                          /* (GMAC_MMSL_CR) Restart the Verification Procedure (Write-only) Position */
#define GMAC_MMSL_CR_RESTART_VER_Msk          (_UINT32_(0x1) << GMAC_MMSL_CR_RESTART_VER_Pos)      /* (GMAC_MMSL_CR) Restart the Verification Procedure (Write-only) Mask */
#define GMAC_MMSL_CR_RESTART_VER(value)       (GMAC_MMSL_CR_RESTART_VER_Msk & (_UINT32_(value) << GMAC_MMSL_CR_RESTART_VER_Pos)) /* Assigment of value for RESTART_VER in the GMAC_MMSL_CR register */
#define   GMAC_MMSL_CR_RESTART_VER_0_Val      _UINT32_(0x0)                                        /* (GMAC_MMSL_CR) No effect.  */
#define   GMAC_MMSL_CR_RESTART_VER_1_Val      _UINT32_(0x1)                                        /* (GMAC_MMSL_CR) Restarts the verification procedure. Writing a one to this bit has no effect if any of the following are true: PRE_ENABLE=0, VERIFY_DISABLE=1 or the verification procedure is already in progress. When preemption is active, ROUTE_RX_TO_PMAC must be set to zero before writing to the RESTART_VER bit. This bit always returns zero when read.  */
#define GMAC_MMSL_CR_RESTART_VER_0            (GMAC_MMSL_CR_RESTART_VER_0_Val << GMAC_MMSL_CR_RESTART_VER_Pos) /* (GMAC_MMSL_CR) No effect. Position  */
#define GMAC_MMSL_CR_RESTART_VER_1            (GMAC_MMSL_CR_RESTART_VER_1_Val << GMAC_MMSL_CR_RESTART_VER_Pos) /* (GMAC_MMSL_CR) Restarts the verification procedure. Writing a one to this bit has no effect if any of the following are true: PRE_ENABLE=0, VERIFY_DISABLE=1 or the verification procedure is already in progress. When preemption is active, ROUTE_RX_TO_PMAC must be set to zero before writing to the RESTART_VER bit. This bit always returns zero when read. Position  */
#define GMAC_MMSL_CR_ROUTE_RX_TO_PMAC_Pos     _UINT32_(5)                                          /* (GMAC_MMSL_CR) Route Received Frames to Preemptive MAC Position */
#define GMAC_MMSL_CR_ROUTE_RX_TO_PMAC_Msk     (_UINT32_(0x1) << GMAC_MMSL_CR_ROUTE_RX_TO_PMAC_Pos) /* (GMAC_MMSL_CR) Route Received Frames to Preemptive MAC Mask */
#define GMAC_MMSL_CR_ROUTE_RX_TO_PMAC(value)  (GMAC_MMSL_CR_ROUTE_RX_TO_PMAC_Msk & (_UINT32_(value) << GMAC_MMSL_CR_ROUTE_RX_TO_PMAC_Pos)) /* Assigment of value for ROUTE_RX_TO_PMAC in the GMAC_MMSL_CR register */
#define   GMAC_MMSL_CR_ROUTE_RX_TO_PMAC_0_Val _UINT32_(0x0)                                        /* (GMAC_MMSL_CR) Routes all received to express MAC (eMAC).  */
#define   GMAC_MMSL_CR_ROUTE_RX_TO_PMAC_1_Val _UINT32_(0x1)                                        /* (GMAC_MMSL_CR) Routes all received frames to preemptive MAC (pMAC).  */
#define GMAC_MMSL_CR_ROUTE_RX_TO_PMAC_0       (GMAC_MMSL_CR_ROUTE_RX_TO_PMAC_0_Val << GMAC_MMSL_CR_ROUTE_RX_TO_PMAC_Pos) /* (GMAC_MMSL_CR) Routes all received to express MAC (eMAC). Position  */
#define GMAC_MMSL_CR_ROUTE_RX_TO_PMAC_1       (GMAC_MMSL_CR_ROUTE_RX_TO_PMAC_1_Val << GMAC_MMSL_CR_ROUTE_RX_TO_PMAC_Pos) /* (GMAC_MMSL_CR) Routes all received frames to preemptive MAC (pMAC). Position  */
#define GMAC_MMSL_CR_Msk                      _UINT32_(0x0000003F)                                 /* (GMAC_MMSL_CR) Register Mask  */


/* -------- GMAC_MMSL_SR : (GMAC Offset: 0xF04) ( R/ 32) MMSL Status Register -------- */
#define GMAC_MMSL_SR_RESETVALUE               _UINT32_(0x00)                                       /*  (GMAC_MMSL_SR) MMSL Status Register  Reset Value */

#define GMAC_MMSL_SR_PRE_ACTIVE_Pos           _UINT32_(0)                                          /* (GMAC_MMSL_SR) Preemption Status Position */
#define GMAC_MMSL_SR_PRE_ACTIVE_Msk           (_UINT32_(0x1) << GMAC_MMSL_SR_PRE_ACTIVE_Pos)       /* (GMAC_MMSL_SR) Preemption Status Mask */
#define GMAC_MMSL_SR_PRE_ACTIVE(value)        (GMAC_MMSL_SR_PRE_ACTIVE_Msk & (_UINT32_(value) << GMAC_MMSL_SR_PRE_ACTIVE_Pos)) /* Assigment of value for PRE_ACTIVE in the GMAC_MMSL_SR register */
#define   GMAC_MMSL_SR_PRE_ACTIVE_0_Val       _UINT32_(0x0)                                        /* (GMAC_MMSL_SR) Preemption is inactive.  */
#define   GMAC_MMSL_SR_PRE_ACTIVE_1_Val       _UINT32_(0x1)                                        /* (GMAC_MMSL_SR) Preemption is active when the verification process is completed or when GMAC_MMSL_CR.VERIFY_DISABLE=1 and GMAC_MMSL_CR.PRE_ACTIVE=1.  */
#define GMAC_MMSL_SR_PRE_ACTIVE_0             (GMAC_MMSL_SR_PRE_ACTIVE_0_Val << GMAC_MMSL_SR_PRE_ACTIVE_Pos) /* (GMAC_MMSL_SR) Preemption is inactive. Position  */
#define GMAC_MMSL_SR_PRE_ACTIVE_1             (GMAC_MMSL_SR_PRE_ACTIVE_1_Val << GMAC_MMSL_SR_PRE_ACTIVE_Pos) /* (GMAC_MMSL_SR) Preemption is active when the verification process is completed or when GMAC_MMSL_CR.VERIFY_DISABLE=1 and GMAC_MMSL_CR.PRE_ACTIVE=1. Position  */
#define GMAC_MMSL_SR_RESPOND_STATUS_Pos       _UINT32_(1)                                          /* (GMAC_MMSL_SR) Response Status Position */
#define GMAC_MMSL_SR_RESPOND_STATUS_Msk       (_UINT32_(0x1) << GMAC_MMSL_SR_RESPOND_STATUS_Pos)   /* (GMAC_MMSL_SR) Response Status Mask */
#define GMAC_MMSL_SR_RESPOND_STATUS(value)    (GMAC_MMSL_SR_RESPOND_STATUS_Msk & (_UINT32_(value) << GMAC_MMSL_SR_RESPOND_STATUS_Pos)) /* Assigment of value for RESPOND_STATUS in the GMAC_MMSL_SR register */
#define   GMAC_MMSL_SR_RESPOND_STATUS_R_IDLE_Val _UINT32_(0x0)                                        /* (GMAC_MMSL_SR) Idle  */
#define   GMAC_MMSL_SR_RESPOND_STATUS_SEND_RESPOND_Val _UINT32_(0x1)                                        /* (GMAC_MMSL_SR) Sending  */
#define GMAC_MMSL_SR_RESPOND_STATUS_R_IDLE    (GMAC_MMSL_SR_RESPOND_STATUS_R_IDLE_Val << GMAC_MMSL_SR_RESPOND_STATUS_Pos) /* (GMAC_MMSL_SR) Idle Position  */
#define GMAC_MMSL_SR_RESPOND_STATUS_SEND_RESPOND (GMAC_MMSL_SR_RESPOND_STATUS_SEND_RESPOND_Val << GMAC_MMSL_SR_RESPOND_STATUS_Pos) /* (GMAC_MMSL_SR) Sending Position  */
#define GMAC_MMSL_SR_VERIFY_STATUS_Pos        _UINT32_(2)                                          /* (GMAC_MMSL_SR) Verification Status Position */
#define GMAC_MMSL_SR_VERIFY_STATUS_Msk        (_UINT32_(0x7) << GMAC_MMSL_SR_VERIFY_STATUS_Pos)    /* (GMAC_MMSL_SR) Verification Status Mask */
#define GMAC_MMSL_SR_VERIFY_STATUS(value)     (GMAC_MMSL_SR_VERIFY_STATUS_Msk & (_UINT32_(value) << GMAC_MMSL_SR_VERIFY_STATUS_Pos)) /* Assigment of value for VERIFY_STATUS in the GMAC_MMSL_SR register */
#define   GMAC_MMSL_SR_VERIFY_STATUS_INIT_VERIFICATION_Val _UINT32_(0x0)                                        /* (GMAC_MMSL_SR) Initialization  */
#define   GMAC_MMSL_SR_VERIFY_STATUS_VERIFICATION_IDLE_Val _UINT32_(0x1)                                        /* (GMAC_MMSL_SR) Idle  */
#define   GMAC_MMSL_SR_VERIFY_STATUS_SEND_VERIFY_Val _UINT32_(0x2)                                        /* (GMAC_MMSL_SR) Sending a verify command  */
#define   GMAC_MMSL_SR_VERIFY_STATUS_WAIT_FOR_RESPONSE_Val _UINT32_(0x3)                                        /* (GMAC_MMSL_SR) Waiting for a response  */
#define   GMAC_MMSL_SR_VERIFY_STATUS_VERIFIED_Val _UINT32_(0x4)                                        /* (GMAC_MMSL_SR) Verified  */
#define   GMAC_MMSL_SR_VERIFY_STATUS_VERIFY_FAIL_Val _UINT32_(0x5)                                        /* (GMAC_MMSL_SR) Failure during the verify operation  */
#define GMAC_MMSL_SR_VERIFY_STATUS_INIT_VERIFICATION (GMAC_MMSL_SR_VERIFY_STATUS_INIT_VERIFICATION_Val << GMAC_MMSL_SR_VERIFY_STATUS_Pos) /* (GMAC_MMSL_SR) Initialization Position  */
#define GMAC_MMSL_SR_VERIFY_STATUS_VERIFICATION_IDLE (GMAC_MMSL_SR_VERIFY_STATUS_VERIFICATION_IDLE_Val << GMAC_MMSL_SR_VERIFY_STATUS_Pos) /* (GMAC_MMSL_SR) Idle Position  */
#define GMAC_MMSL_SR_VERIFY_STATUS_SEND_VERIFY (GMAC_MMSL_SR_VERIFY_STATUS_SEND_VERIFY_Val << GMAC_MMSL_SR_VERIFY_STATUS_Pos) /* (GMAC_MMSL_SR) Sending a verify command Position  */
#define GMAC_MMSL_SR_VERIFY_STATUS_WAIT_FOR_RESPONSE (GMAC_MMSL_SR_VERIFY_STATUS_WAIT_FOR_RESPONSE_Val << GMAC_MMSL_SR_VERIFY_STATUS_Pos) /* (GMAC_MMSL_SR) Waiting for a response Position  */
#define GMAC_MMSL_SR_VERIFY_STATUS_VERIFIED   (GMAC_MMSL_SR_VERIFY_STATUS_VERIFIED_Val << GMAC_MMSL_SR_VERIFY_STATUS_Pos) /* (GMAC_MMSL_SR) Verified Position  */
#define GMAC_MMSL_SR_VERIFY_STATUS_VERIFY_FAIL (GMAC_MMSL_SR_VERIFY_STATUS_VERIFY_FAIL_Val << GMAC_MMSL_SR_VERIFY_STATUS_Pos) /* (GMAC_MMSL_SR) Failure during the verify operation Position  */
#define GMAC_MMSL_SR_RCV_R_ERR_Pos            _UINT32_(5)                                          /* (GMAC_MMSL_SR) Incorrect Response Mpacket Received (Clear on read) Position */
#define GMAC_MMSL_SR_RCV_R_ERR_Msk            (_UINT32_(0x1) << GMAC_MMSL_SR_RCV_R_ERR_Pos)        /* (GMAC_MMSL_SR) Incorrect Response Mpacket Received (Clear on read) Mask */
#define GMAC_MMSL_SR_RCV_R_ERR(value)         (GMAC_MMSL_SR_RCV_R_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_SR_RCV_R_ERR_Pos)) /* Assigment of value for RCV_R_ERR in the GMAC_MMSL_SR register */
#define   GMAC_MMSL_SR_RCV_R_ERR_0_Val        _UINT32_(0x0)                                        /* (GMAC_MMSL_SR) No error since the last read of GMAC_MMSL_SR  */
#define   GMAC_MMSL_SR_RCV_R_ERR_1_Val        _UINT32_(0x1)                                        /* (GMAC_MMSL_SR) An incorrect response mPacket has been received since the last read of GMAC_MMSL_SR.  */
#define GMAC_MMSL_SR_RCV_R_ERR_0              (GMAC_MMSL_SR_RCV_R_ERR_0_Val << GMAC_MMSL_SR_RCV_R_ERR_Pos) /* (GMAC_MMSL_SR) No error since the last read of GMAC_MMSL_SR Position  */
#define GMAC_MMSL_SR_RCV_R_ERR_1              (GMAC_MMSL_SR_RCV_R_ERR_1_Val << GMAC_MMSL_SR_RCV_R_ERR_Pos) /* (GMAC_MMSL_SR) An incorrect response mPacket has been received since the last read of GMAC_MMSL_SR. Position  */
#define GMAC_MMSL_SR_RCV_V_ERR_Pos            _UINT32_(6)                                          /* (GMAC_MMSL_SR) Incorrect Verification Mpacket Received (Clear on read) Position */
#define GMAC_MMSL_SR_RCV_V_ERR_Msk            (_UINT32_(0x1) << GMAC_MMSL_SR_RCV_V_ERR_Pos)        /* (GMAC_MMSL_SR) Incorrect Verification Mpacket Received (Clear on read) Mask */
#define GMAC_MMSL_SR_RCV_V_ERR(value)         (GMAC_MMSL_SR_RCV_V_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_SR_RCV_V_ERR_Pos)) /* Assigment of value for RCV_V_ERR in the GMAC_MMSL_SR register */
#define   GMAC_MMSL_SR_RCV_V_ERR_0_Val        _UINT32_(0x0)                                        /* (GMAC_MMSL_SR) No error since the last read of GMAC_MMSL_SR  */
#define   GMAC_MMSL_SR_RCV_V_ERR_1_Val        _UINT32_(0x1)                                        /* (GMAC_MMSL_SR) An incorrect verification mPacket has been received since the last read of GMAC_MMSL_SR.  */
#define GMAC_MMSL_SR_RCV_V_ERR_0              (GMAC_MMSL_SR_RCV_V_ERR_0_Val << GMAC_MMSL_SR_RCV_V_ERR_Pos) /* (GMAC_MMSL_SR) No error since the last read of GMAC_MMSL_SR Position  */
#define GMAC_MMSL_SR_RCV_V_ERR_1              (GMAC_MMSL_SR_RCV_V_ERR_1_Val << GMAC_MMSL_SR_RCV_V_ERR_Pos) /* (GMAC_MMSL_SR) An incorrect verification mPacket has been received since the last read of GMAC_MMSL_SR. Position  */
#define GMAC_MMSL_SR_SMDS_ERR_Pos             _UINT32_(7)                                          /* (GMAC_MMSL_SR) SMD-S Received When Waiting an SMD-C (Clear on read) Position */
#define GMAC_MMSL_SR_SMDS_ERR_Msk             (_UINT32_(0x1) << GMAC_MMSL_SR_SMDS_ERR_Pos)         /* (GMAC_MMSL_SR) SMD-S Received When Waiting an SMD-C (Clear on read) Mask */
#define GMAC_MMSL_SR_SMDS_ERR(value)          (GMAC_MMSL_SR_SMDS_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_SR_SMDS_ERR_Pos)) /* Assigment of value for SMDS_ERR in the GMAC_MMSL_SR register */
#define   GMAC_MMSL_SR_SMDS_ERR_0_Val         _UINT32_(0x0)                                        /* (GMAC_MMSL_SR) No error since the last read of GMAC_MMSL_SR  */
#define   GMAC_MMSL_SR_SMDS_ERR_1_Val         _UINT32_(0x1)                                        /* (GMAC_MMSL_SR) An SMD-S has been received when an SMD-C was expected, since the last read of GMAC_MMSL_SR.  */
#define GMAC_MMSL_SR_SMDS_ERR_0               (GMAC_MMSL_SR_SMDS_ERR_0_Val << GMAC_MMSL_SR_SMDS_ERR_Pos) /* (GMAC_MMSL_SR) No error since the last read of GMAC_MMSL_SR Position  */
#define GMAC_MMSL_SR_SMDS_ERR_1               (GMAC_MMSL_SR_SMDS_ERR_1_Val << GMAC_MMSL_SR_SMDS_ERR_Pos) /* (GMAC_MMSL_SR) An SMD-S has been received when an SMD-C was expected, since the last read of GMAC_MMSL_SR. Position  */
#define GMAC_MMSL_SR_SMDC_ERR_Pos             _UINT32_(8)                                          /* (GMAC_MMSL_SR) SMD-C Received When Waiting an SMD-S (Clear on read) Position */
#define GMAC_MMSL_SR_SMDC_ERR_Msk             (_UINT32_(0x1) << GMAC_MMSL_SR_SMDC_ERR_Pos)         /* (GMAC_MMSL_SR) SMD-C Received When Waiting an SMD-S (Clear on read) Mask */
#define GMAC_MMSL_SR_SMDC_ERR(value)          (GMAC_MMSL_SR_SMDC_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_SR_SMDC_ERR_Pos)) /* Assigment of value for SMDC_ERR in the GMAC_MMSL_SR register */
#define   GMAC_MMSL_SR_SMDC_ERR_0_Val         _UINT32_(0x0)                                        /* (GMAC_MMSL_SR) No error since the last read of GMAC_MMSL_SR  */
#define   GMAC_MMSL_SR_SMDC_ERR_1_Val         _UINT32_(0x1)                                        /* (GMAC_MMSL_SR) An SMD-C has been received when an SMD-S was expected, since the last read of GMAC_MMSL_SR.  */
#define GMAC_MMSL_SR_SMDC_ERR_0               (GMAC_MMSL_SR_SMDC_ERR_0_Val << GMAC_MMSL_SR_SMDC_ERR_Pos) /* (GMAC_MMSL_SR) No error since the last read of GMAC_MMSL_SR Position  */
#define GMAC_MMSL_SR_SMDC_ERR_1               (GMAC_MMSL_SR_SMDC_ERR_1_Val << GMAC_MMSL_SR_SMDC_ERR_Pos) /* (GMAC_MMSL_SR) An SMD-C has been received when an SMD-S was expected, since the last read of GMAC_MMSL_SR. Position  */
#define GMAC_MMSL_SR_FRER_COUNT_ERR_Pos       _UINT32_(9)                                          /* (GMAC_MMSL_SR) Frame Counter Error (Clear on read) Position */
#define GMAC_MMSL_SR_FRER_COUNT_ERR_Msk       (_UINT32_(0x1) << GMAC_MMSL_SR_FRER_COUNT_ERR_Pos)   /* (GMAC_MMSL_SR) Frame Counter Error (Clear on read) Mask */
#define GMAC_MMSL_SR_FRER_COUNT_ERR(value)    (GMAC_MMSL_SR_FRER_COUNT_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_SR_FRER_COUNT_ERR_Pos)) /* Assigment of value for FRER_COUNT_ERR in the GMAC_MMSL_SR register */
#define   GMAC_MMSL_SR_FRER_COUNT_ERR_0_Val   _UINT32_(0x0)                                        /* (GMAC_MMSL_SR) No error since the last read of GMAC_MMSL_SR  */
#define   GMAC_MMSL_SR_FRER_COUNT_ERR_1_Val   _UINT32_(0x1)                                        /* (GMAC_MMSL_SR) A frame counter error occurred since the last read of GMAC_MMSL_SR. A frame counter error occurs when the SMD-C received indicates a different frame count than expected (i.e. the fragment belongs to another frame and not to the Start packet already received before this) or when a fragment error happened, which means the field following the SMD-C received was encoding a different fragment count than it was supposed to be.  */
#define GMAC_MMSL_SR_FRER_COUNT_ERR_0         (GMAC_MMSL_SR_FRER_COUNT_ERR_0_Val << GMAC_MMSL_SR_FRER_COUNT_ERR_Pos) /* (GMAC_MMSL_SR) No error since the last read of GMAC_MMSL_SR Position  */
#define GMAC_MMSL_SR_FRER_COUNT_ERR_1         (GMAC_MMSL_SR_FRER_COUNT_ERR_1_Val << GMAC_MMSL_SR_FRER_COUNT_ERR_Pos) /* (GMAC_MMSL_SR) A frame counter error occurred since the last read of GMAC_MMSL_SR. A frame counter error occurs when the SMD-C received indicates a different frame count than expected (i.e. the fragment belongs to another frame and not to the Start packet already received before this) or when a fragment error happened, which means the field following the SMD-C received was encoding a different fragment count than it was supposed to be. Position  */
#define GMAC_MMSL_SR_SMD_ERR_Pos              _UINT32_(10)                                         /* (GMAC_MMSL_SR) Illegal Start Mpacket Delimiter Received (Clear on read) Position */
#define GMAC_MMSL_SR_SMD_ERR_Msk              (_UINT32_(0x1) << GMAC_MMSL_SR_SMD_ERR_Pos)          /* (GMAC_MMSL_SR) Illegal Start Mpacket Delimiter Received (Clear on read) Mask */
#define GMAC_MMSL_SR_SMD_ERR(value)           (GMAC_MMSL_SR_SMD_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_SR_SMD_ERR_Pos)) /* Assigment of value for SMD_ERR in the GMAC_MMSL_SR register */
#define   GMAC_MMSL_SR_SMD_ERR_0_Val          _UINT32_(0x0)                                        /* (GMAC_MMSL_SR) No error since the last read of GMAC_MMSL_SR  */
#define   GMAC_MMSL_SR_SMD_ERR_1_Val          _UINT32_(0x1)                                        /* (GMAC_MMSL_SR) An illegal SMD (different from Express, Verify, Response, Start Preemptible or Continuation Preemptible SMD) has been received since the last read of GMAC_MMSL_SR.  */
#define GMAC_MMSL_SR_SMD_ERR_0                (GMAC_MMSL_SR_SMD_ERR_0_Val << GMAC_MMSL_SR_SMD_ERR_Pos) /* (GMAC_MMSL_SR) No error since the last read of GMAC_MMSL_SR Position  */
#define GMAC_MMSL_SR_SMD_ERR_1                (GMAC_MMSL_SR_SMD_ERR_1_Val << GMAC_MMSL_SR_SMD_ERR_Pos) /* (GMAC_MMSL_SR) An illegal SMD (different from Express, Verify, Response, Start Preemptible or Continuation Preemptible SMD) has been received since the last read of GMAC_MMSL_SR. Position  */
#define GMAC_MMSL_SR_Msk                      _UINT32_(0x000007FF)                                 /* (GMAC_MMSL_SR) Register Mask  */


/* -------- GMAC_MMSL_ESR : (GMAC Offset: 0xF08) ( R/ 32) MMSL Error Statistics Register -------- */
#define GMAC_MMSL_ESR_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_MMSL_ESR) MMSL Error Statistics Register  Reset Value */

#define GMAC_MMSL_ESR_ASS_ERROR_COUNT_Pos     _UINT32_(0)                                          /* (GMAC_MMSL_ESR) Number of Frames with Reassembly Errors (Clear on read) Position */
#define GMAC_MMSL_ESR_ASS_ERROR_COUNT_Msk     (_UINT32_(0xFF) << GMAC_MMSL_ESR_ASS_ERROR_COUNT_Pos) /* (GMAC_MMSL_ESR) Number of Frames with Reassembly Errors (Clear on read) Mask */
#define GMAC_MMSL_ESR_ASS_ERROR_COUNT(value)  (GMAC_MMSL_ESR_ASS_ERROR_COUNT_Msk & (_UINT32_(value) << GMAC_MMSL_ESR_ASS_ERROR_COUNT_Pos)) /* Assigment of value for ASS_ERROR_COUNT in the GMAC_MMSL_ESR register */
#define GMAC_MMSL_ESR_SMD_ERROR_COUNT_Pos     _UINT32_(16)                                         /* (GMAC_MMSL_ESR) Number of Rejected Frames or Fragments due to unknown SMD (Clear on read) Position */
#define GMAC_MMSL_ESR_SMD_ERROR_COUNT_Msk     (_UINT32_(0xFF) << GMAC_MMSL_ESR_SMD_ERROR_COUNT_Pos) /* (GMAC_MMSL_ESR) Number of Rejected Frames or Fragments due to unknown SMD (Clear on read) Mask */
#define GMAC_MMSL_ESR_SMD_ERROR_COUNT(value)  (GMAC_MMSL_ESR_SMD_ERROR_COUNT_Msk & (_UINT32_(value) << GMAC_MMSL_ESR_SMD_ERROR_COUNT_Pos)) /* Assigment of value for SMD_ERROR_COUNT in the GMAC_MMSL_ESR register */
#define GMAC_MMSL_ESR_Msk                     _UINT32_(0x00FF00FF)                                 /* (GMAC_MMSL_ESR) Register Mask  */


/* -------- GMAC_MMSL_ASS_OK : (GMAC Offset: 0xF0C) ( R/ 32) MMSL Frame Re-Assembled OK Register -------- */
#define GMAC_MMSL_ASS_OK_RESETVALUE           _UINT32_(0x00)                                       /*  (GMAC_MMSL_ASS_OK) MMSL Frame Re-Assembled OK Register  Reset Value */

#define GMAC_MMSL_ASS_OK_ASS_OK_COUNT_Pos     _UINT32_(0)                                          /* (GMAC_MMSL_ASS_OK) Number of Correctly Re-Assembled Frames (Clear on read) Position */
#define GMAC_MMSL_ASS_OK_ASS_OK_COUNT_Msk     (_UINT32_(0x1FFFF) << GMAC_MMSL_ASS_OK_ASS_OK_COUNT_Pos) /* (GMAC_MMSL_ASS_OK) Number of Correctly Re-Assembled Frames (Clear on read) Mask */
#define GMAC_MMSL_ASS_OK_ASS_OK_COUNT(value)  (GMAC_MMSL_ASS_OK_ASS_OK_COUNT_Msk & (_UINT32_(value) << GMAC_MMSL_ASS_OK_ASS_OK_COUNT_Pos)) /* Assigment of value for ASS_OK_COUNT in the GMAC_MMSL_ASS_OK register */
#define GMAC_MMSL_ASS_OK_Msk                  _UINT32_(0x0001FFFF)                                 /* (GMAC_MMSL_ASS_OK) Register Mask  */


/* -------- GMAC_MMSL_RXFRAG_CNT : (GMAC Offset: 0xF10) ( R/ 32) MMSL Received Fragment Counter Register -------- */
#define GMAC_MMSL_RXFRAG_CNT_RESETVALUE       _UINT32_(0x00)                                       /*  (GMAC_MMSL_RXFRAG_CNT) MMSL Received Fragment Counter Register  Reset Value */

#define GMAC_MMSL_RXFRAG_CNT_FRAG_COUNT_RX_Pos _UINT32_(0)                                          /* (GMAC_MMSL_RXFRAG_CNT) Number of Received Fragments (Clear on read) Position */
#define GMAC_MMSL_RXFRAG_CNT_FRAG_COUNT_RX_Msk (_UINT32_(0x1FFFF) << GMAC_MMSL_RXFRAG_CNT_FRAG_COUNT_RX_Pos) /* (GMAC_MMSL_RXFRAG_CNT) Number of Received Fragments (Clear on read) Mask */
#define GMAC_MMSL_RXFRAG_CNT_FRAG_COUNT_RX(value) (GMAC_MMSL_RXFRAG_CNT_FRAG_COUNT_RX_Msk & (_UINT32_(value) << GMAC_MMSL_RXFRAG_CNT_FRAG_COUNT_RX_Pos)) /* Assigment of value for FRAG_COUNT_RX in the GMAC_MMSL_RXFRAG_CNT register */
#define GMAC_MMSL_RXFRAG_CNT_Msk              _UINT32_(0x0001FFFF)                                 /* (GMAC_MMSL_RXFRAG_CNT) Register Mask  */


/* -------- GMAC_MMSL_TXFRAG_CNT : (GMAC Offset: 0xF14) ( R/ 32) MMSL Transmitted Fragment Counter Register -------- */
#define GMAC_MMSL_TXFRAG_CNT_RESETVALUE       _UINT32_(0x00)                                       /*  (GMAC_MMSL_TXFRAG_CNT) MMSL Transmitted Fragment Counter Register  Reset Value */

#define GMAC_MMSL_TXFRAG_CNT_FRAG_COUNT_TX_Pos _UINT32_(0)                                          /* (GMAC_MMSL_TXFRAG_CNT) Number of Transmitted Fragments (Clear on read) Position */
#define GMAC_MMSL_TXFRAG_CNT_FRAG_COUNT_TX_Msk (_UINT32_(0x1FFFF) << GMAC_MMSL_TXFRAG_CNT_FRAG_COUNT_TX_Pos) /* (GMAC_MMSL_TXFRAG_CNT) Number of Transmitted Fragments (Clear on read) Mask */
#define GMAC_MMSL_TXFRAG_CNT_FRAG_COUNT_TX(value) (GMAC_MMSL_TXFRAG_CNT_FRAG_COUNT_TX_Msk & (_UINT32_(value) << GMAC_MMSL_TXFRAG_CNT_FRAG_COUNT_TX_Pos)) /* Assigment of value for FRAG_COUNT_TX in the GMAC_MMSL_TXFRAG_CNT register */
#define GMAC_MMSL_TXFRAG_CNT_Msk              _UINT32_(0x0001FFFF)                                 /* (GMAC_MMSL_TXFRAG_CNT) Register Mask  */


/* -------- GMAC_MMSL_ISR : (GMAC Offset: 0xF18) (R/W 32) MMSL Interrupt Status Register -------- */
#define GMAC_MMSL_ISR_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_MMSL_ISR) MMSL Interrupt Status Register  Reset Value */

#define GMAC_MMSL_ISR_RCV_R_ERR_Pos           _UINT32_(0)                                          /* (GMAC_MMSL_ISR) Incorrect Response Mpacket Received (Clear on read) Position */
#define GMAC_MMSL_ISR_RCV_R_ERR_Msk           (_UINT32_(0x1) << GMAC_MMSL_ISR_RCV_R_ERR_Pos)       /* (GMAC_MMSL_ISR) Incorrect Response Mpacket Received (Clear on read) Mask */
#define GMAC_MMSL_ISR_RCV_R_ERR(value)        (GMAC_MMSL_ISR_RCV_R_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_ISR_RCV_R_ERR_Pos)) /* Assigment of value for RCV_R_ERR in the GMAC_MMSL_ISR register */
#define   GMAC_MMSL_ISR_RCV_R_ERR_0_Val       _UINT32_(0x0)                                        /* (GMAC_MMSL_ISR) No error since the last read of GMAC_MMSL_SR  */
#define   GMAC_MMSL_ISR_RCV_R_ERR_1_Val       _UINT32_(0x1)                                        /* (GMAC_MMSL_ISR) An incorrect response mPacket has been received since the last read of GMAC_MMSL_SR.  */
#define GMAC_MMSL_ISR_RCV_R_ERR_0             (GMAC_MMSL_ISR_RCV_R_ERR_0_Val << GMAC_MMSL_ISR_RCV_R_ERR_Pos) /* (GMAC_MMSL_ISR) No error since the last read of GMAC_MMSL_SR Position  */
#define GMAC_MMSL_ISR_RCV_R_ERR_1             (GMAC_MMSL_ISR_RCV_R_ERR_1_Val << GMAC_MMSL_ISR_RCV_R_ERR_Pos) /* (GMAC_MMSL_ISR) An incorrect response mPacket has been received since the last read of GMAC_MMSL_SR. Position  */
#define GMAC_MMSL_ISR_RCV_V_ERR_Pos           _UINT32_(1)                                          /* (GMAC_MMSL_ISR) Incorrect Verification Mpacket Received (Clear on read) Position */
#define GMAC_MMSL_ISR_RCV_V_ERR_Msk           (_UINT32_(0x1) << GMAC_MMSL_ISR_RCV_V_ERR_Pos)       /* (GMAC_MMSL_ISR) Incorrect Verification Mpacket Received (Clear on read) Mask */
#define GMAC_MMSL_ISR_RCV_V_ERR(value)        (GMAC_MMSL_ISR_RCV_V_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_ISR_RCV_V_ERR_Pos)) /* Assigment of value for RCV_V_ERR in the GMAC_MMSL_ISR register */
#define   GMAC_MMSL_ISR_RCV_V_ERR_0_Val       _UINT32_(0x0)                                        /* (GMAC_MMSL_ISR) No error since the last read of GMAC_MMSL_SR  */
#define   GMAC_MMSL_ISR_RCV_V_ERR_1_Val       _UINT32_(0x1)                                        /* (GMAC_MMSL_ISR) An incorrect verification mPacket has been received since the last read of GMAC_MMSL_SR.  */
#define GMAC_MMSL_ISR_RCV_V_ERR_0             (GMAC_MMSL_ISR_RCV_V_ERR_0_Val << GMAC_MMSL_ISR_RCV_V_ERR_Pos) /* (GMAC_MMSL_ISR) No error since the last read of GMAC_MMSL_SR Position  */
#define GMAC_MMSL_ISR_RCV_V_ERR_1             (GMAC_MMSL_ISR_RCV_V_ERR_1_Val << GMAC_MMSL_ISR_RCV_V_ERR_Pos) /* (GMAC_MMSL_ISR) An incorrect verification mPacket has been received since the last read of GMAC_MMSL_SR. Position  */
#define GMAC_MMSL_ISR_SMDS_ERR_Pos            _UINT32_(2)                                          /* (GMAC_MMSL_ISR) SMD-S Received When Waiting an SMD-C (Clear on read) Position */
#define GMAC_MMSL_ISR_SMDS_ERR_Msk            (_UINT32_(0x1) << GMAC_MMSL_ISR_SMDS_ERR_Pos)        /* (GMAC_MMSL_ISR) SMD-S Received When Waiting an SMD-C (Clear on read) Mask */
#define GMAC_MMSL_ISR_SMDS_ERR(value)         (GMAC_MMSL_ISR_SMDS_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_ISR_SMDS_ERR_Pos)) /* Assigment of value for SMDS_ERR in the GMAC_MMSL_ISR register */
#define   GMAC_MMSL_ISR_SMDS_ERR_0_Val        _UINT32_(0x0)                                        /* (GMAC_MMSL_ISR) No error since the last read of GMAC_MMSL_SR  */
#define   GMAC_MMSL_ISR_SMDS_ERR_1_Val        _UINT32_(0x1)                                        /* (GMAC_MMSL_ISR) An SMD-S has been received when an SMD-C was expected, since the last read of GMAC_MMSL_SR.  */
#define GMAC_MMSL_ISR_SMDS_ERR_0              (GMAC_MMSL_ISR_SMDS_ERR_0_Val << GMAC_MMSL_ISR_SMDS_ERR_Pos) /* (GMAC_MMSL_ISR) No error since the last read of GMAC_MMSL_SR Position  */
#define GMAC_MMSL_ISR_SMDS_ERR_1              (GMAC_MMSL_ISR_SMDS_ERR_1_Val << GMAC_MMSL_ISR_SMDS_ERR_Pos) /* (GMAC_MMSL_ISR) An SMD-S has been received when an SMD-C was expected, since the last read of GMAC_MMSL_SR. Position  */
#define GMAC_MMSL_ISR_SMDC_ERR_Pos            _UINT32_(3)                                          /* (GMAC_MMSL_ISR) SMD-C Received When Waiting an SMD-S (Clear on read) Position */
#define GMAC_MMSL_ISR_SMDC_ERR_Msk            (_UINT32_(0x1) << GMAC_MMSL_ISR_SMDC_ERR_Pos)        /* (GMAC_MMSL_ISR) SMD-C Received When Waiting an SMD-S (Clear on read) Mask */
#define GMAC_MMSL_ISR_SMDC_ERR(value)         (GMAC_MMSL_ISR_SMDC_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_ISR_SMDC_ERR_Pos)) /* Assigment of value for SMDC_ERR in the GMAC_MMSL_ISR register */
#define   GMAC_MMSL_ISR_SMDC_ERR_0_Val        _UINT32_(0x0)                                        /* (GMAC_MMSL_ISR) No error since the last read of GMAC_MMSL_SR  */
#define   GMAC_MMSL_ISR_SMDC_ERR_1_Val        _UINT32_(0x1)                                        /* (GMAC_MMSL_ISR) An SMD-C has been received when an SMD-S was expected, since the last read of GMAC_MMSL_SR.  */
#define GMAC_MMSL_ISR_SMDC_ERR_0              (GMAC_MMSL_ISR_SMDC_ERR_0_Val << GMAC_MMSL_ISR_SMDC_ERR_Pos) /* (GMAC_MMSL_ISR) No error since the last read of GMAC_MMSL_SR Position  */
#define GMAC_MMSL_ISR_SMDC_ERR_1              (GMAC_MMSL_ISR_SMDC_ERR_1_Val << GMAC_MMSL_ISR_SMDC_ERR_Pos) /* (GMAC_MMSL_ISR) An SMD-C has been received when an SMD-S was expected, since the last read of GMAC_MMSL_SR. Position  */
#define GMAC_MMSL_ISR_FR_COUNT_ERR_Pos        _UINT32_(4)                                          /* (GMAC_MMSL_ISR) Illegal SMD Received (Clear on read) Position */
#define GMAC_MMSL_ISR_FR_COUNT_ERR_Msk        (_UINT32_(0x1) << GMAC_MMSL_ISR_FR_COUNT_ERR_Pos)    /* (GMAC_MMSL_ISR) Illegal SMD Received (Clear on read) Mask */
#define GMAC_MMSL_ISR_FR_COUNT_ERR(value)     (GMAC_MMSL_ISR_FR_COUNT_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_ISR_FR_COUNT_ERR_Pos)) /* Assigment of value for FR_COUNT_ERR in the GMAC_MMSL_ISR register */
#define   GMAC_MMSL_ISR_FR_COUNT_ERR_0_Val    _UINT32_(0x0)                                        /* (GMAC_MMSL_ISR) No frame count error detected since the last read of GMAC_MMSL_ISR.  */
#define   GMAC_MMSL_ISR_FR_COUNT_ERR_1_Val    _UINT32_(0x1)                                        /* (GMAC_MMSL_ISR) The SMD-C received since the last read of GMAC_MMSL_ISR, indicates a different frame count than expected (i.e. the fragment belongs to another frame and not to the Start packet already received before this) or if a Fragment error happened, which means the field following the SMD-C received was encoding a different fragment count than it was supposed to be.  */
#define GMAC_MMSL_ISR_FR_COUNT_ERR_0          (GMAC_MMSL_ISR_FR_COUNT_ERR_0_Val << GMAC_MMSL_ISR_FR_COUNT_ERR_Pos) /* (GMAC_MMSL_ISR) No frame count error detected since the last read of GMAC_MMSL_ISR. Position  */
#define GMAC_MMSL_ISR_FR_COUNT_ERR_1          (GMAC_MMSL_ISR_FR_COUNT_ERR_1_Val << GMAC_MMSL_ISR_FR_COUNT_ERR_Pos) /* (GMAC_MMSL_ISR) The SMD-C received since the last read of GMAC_MMSL_ISR, indicates a different frame count than expected (i.e. the fragment belongs to another frame and not to the Start packet already received before this) or if a Fragment error happened, which means the field following the SMD-C received was encoding a different fragment count than it was supposed to be. Position  */
#define GMAC_MMSL_ISR_SMD_ERR_Pos             _UINT32_(5)                                          /* (GMAC_MMSL_ISR) Illegal SMD Received (Clear on read) Position */
#define GMAC_MMSL_ISR_SMD_ERR_Msk             (_UINT32_(0x1) << GMAC_MMSL_ISR_SMD_ERR_Pos)         /* (GMAC_MMSL_ISR) Illegal SMD Received (Clear on read) Mask */
#define GMAC_MMSL_ISR_SMD_ERR(value)          (GMAC_MMSL_ISR_SMD_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_ISR_SMD_ERR_Pos)) /* Assigment of value for SMD_ERR in the GMAC_MMSL_ISR register */
#define   GMAC_MMSL_ISR_SMD_ERR_0_Val         _UINT32_(0x0)                                        /* (GMAC_MMSL_ISR) No illegal SMD received since the last read of GMAC_MMSL_ISR.  */
#define   GMAC_MMSL_ISR_SMD_ERR_1_Val         _UINT32_(0x1)                                        /* (GMAC_MMSL_ISR) Illegal SMD received (different from Express, Verify, Response, Start Preemptible or Continuation Preemptible) since the last read of GMAC_MMSL_ISR  */
#define GMAC_MMSL_ISR_SMD_ERR_0               (GMAC_MMSL_ISR_SMD_ERR_0_Val << GMAC_MMSL_ISR_SMD_ERR_Pos) /* (GMAC_MMSL_ISR) No illegal SMD received since the last read of GMAC_MMSL_ISR. Position  */
#define GMAC_MMSL_ISR_SMD_ERR_1               (GMAC_MMSL_ISR_SMD_ERR_1_Val << GMAC_MMSL_ISR_SMD_ERR_Pos) /* (GMAC_MMSL_ISR) Illegal SMD received (different from Express, Verify, Response, Start Preemptible or Continuation Preemptible) since the last read of GMAC_MMSL_ISR Position  */
#define GMAC_MMSL_ISR_Msk                     _UINT32_(0x0000003F)                                 /* (GMAC_MMSL_ISR) Register Mask  */


/* -------- GMAC_MMSL_IER : (GMAC Offset: 0xF1C) (R/W 32) MMSL Interrupt Enable Register -------- */
#define GMAC_MMSL_IER_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_MMSL_IER) MMSL Interrupt Enable Register  Reset Value */

#define GMAC_MMSL_IER_RCV_R_ERR_Pos           _UINT32_(0)                                          /* (GMAC_MMSL_IER) Incorrect Response Mpacket Received Position */
#define GMAC_MMSL_IER_RCV_R_ERR_Msk           (_UINT32_(0x1) << GMAC_MMSL_IER_RCV_R_ERR_Pos)       /* (GMAC_MMSL_IER) Incorrect Response Mpacket Received Mask */
#define GMAC_MMSL_IER_RCV_R_ERR(value)        (GMAC_MMSL_IER_RCV_R_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_IER_RCV_R_ERR_Pos)) /* Assigment of value for RCV_R_ERR in the GMAC_MMSL_IER register */
#define GMAC_MMSL_IER_RCV_V_ERR_Pos           _UINT32_(1)                                          /* (GMAC_MMSL_IER) Incorrect Verification Mpacket Received Position */
#define GMAC_MMSL_IER_RCV_V_ERR_Msk           (_UINT32_(0x1) << GMAC_MMSL_IER_RCV_V_ERR_Pos)       /* (GMAC_MMSL_IER) Incorrect Verification Mpacket Received Mask */
#define GMAC_MMSL_IER_RCV_V_ERR(value)        (GMAC_MMSL_IER_RCV_V_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_IER_RCV_V_ERR_Pos)) /* Assigment of value for RCV_V_ERR in the GMAC_MMSL_IER register */
#define GMAC_MMSL_IER_SMDS_ERR_Pos            _UINT32_(2)                                          /* (GMAC_MMSL_IER) SMD-S Received When Waiting an SMD-C Position */
#define GMAC_MMSL_IER_SMDS_ERR_Msk            (_UINT32_(0x1) << GMAC_MMSL_IER_SMDS_ERR_Pos)        /* (GMAC_MMSL_IER) SMD-S Received When Waiting an SMD-C Mask */
#define GMAC_MMSL_IER_SMDS_ERR(value)         (GMAC_MMSL_IER_SMDS_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_IER_SMDS_ERR_Pos)) /* Assigment of value for SMDS_ERR in the GMAC_MMSL_IER register */
#define GMAC_MMSL_IER_SMDC_ERR_Pos            _UINT32_(3)                                          /* (GMAC_MMSL_IER) SMD-C Received When Waiting an SMD-S Position */
#define GMAC_MMSL_IER_SMDC_ERR_Msk            (_UINT32_(0x1) << GMAC_MMSL_IER_SMDC_ERR_Pos)        /* (GMAC_MMSL_IER) SMD-C Received When Waiting an SMD-S Mask */
#define GMAC_MMSL_IER_SMDC_ERR(value)         (GMAC_MMSL_IER_SMDC_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_IER_SMDC_ERR_Pos)) /* Assigment of value for SMDC_ERR in the GMAC_MMSL_IER register */
#define GMAC_MMSL_IER_FR_COUNT_ERR_Pos        _UINT32_(4)                                          /* (GMAC_MMSL_IER) Illegal SMD Received Position */
#define GMAC_MMSL_IER_FR_COUNT_ERR_Msk        (_UINT32_(0x1) << GMAC_MMSL_IER_FR_COUNT_ERR_Pos)    /* (GMAC_MMSL_IER) Illegal SMD Received Mask */
#define GMAC_MMSL_IER_FR_COUNT_ERR(value)     (GMAC_MMSL_IER_FR_COUNT_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_IER_FR_COUNT_ERR_Pos)) /* Assigment of value for FR_COUNT_ERR in the GMAC_MMSL_IER register */
#define GMAC_MMSL_IER_SMD_ERR_Pos             _UINT32_(5)                                          /* (GMAC_MMSL_IER) Illegal SMD Received Position */
#define GMAC_MMSL_IER_SMD_ERR_Msk             (_UINT32_(0x1) << GMAC_MMSL_IER_SMD_ERR_Pos)         /* (GMAC_MMSL_IER) Illegal SMD Received Mask */
#define GMAC_MMSL_IER_SMD_ERR(value)          (GMAC_MMSL_IER_SMD_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_IER_SMD_ERR_Pos)) /* Assigment of value for SMD_ERR in the GMAC_MMSL_IER register */
#define GMAC_MMSL_IER_Msk                     _UINT32_(0x0000003F)                                 /* (GMAC_MMSL_IER) Register Mask  */


/* -------- GMAC_MMSL_IDR : (GMAC Offset: 0xF20) (R/W 32) MMSL Interrupt Disable Register -------- */
#define GMAC_MMSL_IDR_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_MMSL_IDR) MMSL Interrupt Disable Register  Reset Value */

#define GMAC_MMSL_IDR_RCV_R_ERR_Pos           _UINT32_(0)                                          /* (GMAC_MMSL_IDR) Incorrect Response Mpacket Received Position */
#define GMAC_MMSL_IDR_RCV_R_ERR_Msk           (_UINT32_(0x1) << GMAC_MMSL_IDR_RCV_R_ERR_Pos)       /* (GMAC_MMSL_IDR) Incorrect Response Mpacket Received Mask */
#define GMAC_MMSL_IDR_RCV_R_ERR(value)        (GMAC_MMSL_IDR_RCV_R_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_IDR_RCV_R_ERR_Pos)) /* Assigment of value for RCV_R_ERR in the GMAC_MMSL_IDR register */
#define GMAC_MMSL_IDR_RCV_V_ERR_Pos           _UINT32_(1)                                          /* (GMAC_MMSL_IDR) Incorrect Verification Mpacket Received Position */
#define GMAC_MMSL_IDR_RCV_V_ERR_Msk           (_UINT32_(0x1) << GMAC_MMSL_IDR_RCV_V_ERR_Pos)       /* (GMAC_MMSL_IDR) Incorrect Verification Mpacket Received Mask */
#define GMAC_MMSL_IDR_RCV_V_ERR(value)        (GMAC_MMSL_IDR_RCV_V_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_IDR_RCV_V_ERR_Pos)) /* Assigment of value for RCV_V_ERR in the GMAC_MMSL_IDR register */
#define GMAC_MMSL_IDR_SMDS_ERR_Pos            _UINT32_(2)                                          /* (GMAC_MMSL_IDR) SMD-S Received When Waiting an SMD-C Position */
#define GMAC_MMSL_IDR_SMDS_ERR_Msk            (_UINT32_(0x1) << GMAC_MMSL_IDR_SMDS_ERR_Pos)        /* (GMAC_MMSL_IDR) SMD-S Received When Waiting an SMD-C Mask */
#define GMAC_MMSL_IDR_SMDS_ERR(value)         (GMAC_MMSL_IDR_SMDS_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_IDR_SMDS_ERR_Pos)) /* Assigment of value for SMDS_ERR in the GMAC_MMSL_IDR register */
#define GMAC_MMSL_IDR_SMDC_ERR_Pos            _UINT32_(3)                                          /* (GMAC_MMSL_IDR) SMD-C Received When Waiting an SMD-S Position */
#define GMAC_MMSL_IDR_SMDC_ERR_Msk            (_UINT32_(0x1) << GMAC_MMSL_IDR_SMDC_ERR_Pos)        /* (GMAC_MMSL_IDR) SMD-C Received When Waiting an SMD-S Mask */
#define GMAC_MMSL_IDR_SMDC_ERR(value)         (GMAC_MMSL_IDR_SMDC_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_IDR_SMDC_ERR_Pos)) /* Assigment of value for SMDC_ERR in the GMAC_MMSL_IDR register */
#define GMAC_MMSL_IDR_FR_COUNT_ERR_Pos        _UINT32_(4)                                          /* (GMAC_MMSL_IDR) Illegal SMD Received Position */
#define GMAC_MMSL_IDR_FR_COUNT_ERR_Msk        (_UINT32_(0x1) << GMAC_MMSL_IDR_FR_COUNT_ERR_Pos)    /* (GMAC_MMSL_IDR) Illegal SMD Received Mask */
#define GMAC_MMSL_IDR_FR_COUNT_ERR(value)     (GMAC_MMSL_IDR_FR_COUNT_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_IDR_FR_COUNT_ERR_Pos)) /* Assigment of value for FR_COUNT_ERR in the GMAC_MMSL_IDR register */
#define GMAC_MMSL_IDR_SMD_ERR_Pos             _UINT32_(5)                                          /* (GMAC_MMSL_IDR) Illegal SMD Received Position */
#define GMAC_MMSL_IDR_SMD_ERR_Msk             (_UINT32_(0x1) << GMAC_MMSL_IDR_SMD_ERR_Pos)         /* (GMAC_MMSL_IDR) Illegal SMD Received Mask */
#define GMAC_MMSL_IDR_SMD_ERR(value)          (GMAC_MMSL_IDR_SMD_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_IDR_SMD_ERR_Pos)) /* Assigment of value for SMD_ERR in the GMAC_MMSL_IDR register */
#define GMAC_MMSL_IDR_Msk                     _UINT32_(0x0000003F)                                 /* (GMAC_MMSL_IDR) Register Mask  */


/* -------- GMAC_MMSL_IMR : (GMAC Offset: 0xF24) ( R/ 32) MMSL Interrupt Mask Register -------- */
#define GMAC_MMSL_IMR_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_MMSL_IMR) MMSL Interrupt Mask Register  Reset Value */

#define GMAC_MMSL_IMR_RCV_R_ERR_Pos           _UINT32_(0)                                          /* (GMAC_MMSL_IMR) Incorrect Response Mpacket Received Position */
#define GMAC_MMSL_IMR_RCV_R_ERR_Msk           (_UINT32_(0x1) << GMAC_MMSL_IMR_RCV_R_ERR_Pos)       /* (GMAC_MMSL_IMR) Incorrect Response Mpacket Received Mask */
#define GMAC_MMSL_IMR_RCV_R_ERR(value)        (GMAC_MMSL_IMR_RCV_R_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_IMR_RCV_R_ERR_Pos)) /* Assigment of value for RCV_R_ERR in the GMAC_MMSL_IMR register */
#define GMAC_MMSL_IMR_RCV_V_ERR_Pos           _UINT32_(1)                                          /* (GMAC_MMSL_IMR) Incorrect Verification Mpacket Received Position */
#define GMAC_MMSL_IMR_RCV_V_ERR_Msk           (_UINT32_(0x1) << GMAC_MMSL_IMR_RCV_V_ERR_Pos)       /* (GMAC_MMSL_IMR) Incorrect Verification Mpacket Received Mask */
#define GMAC_MMSL_IMR_RCV_V_ERR(value)        (GMAC_MMSL_IMR_RCV_V_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_IMR_RCV_V_ERR_Pos)) /* Assigment of value for RCV_V_ERR in the GMAC_MMSL_IMR register */
#define GMAC_MMSL_IMR_SMDS_ERR_Pos            _UINT32_(2)                                          /* (GMAC_MMSL_IMR) SMD-S Received When Waiting an SMD-C Position */
#define GMAC_MMSL_IMR_SMDS_ERR_Msk            (_UINT32_(0x1) << GMAC_MMSL_IMR_SMDS_ERR_Pos)        /* (GMAC_MMSL_IMR) SMD-S Received When Waiting an SMD-C Mask */
#define GMAC_MMSL_IMR_SMDS_ERR(value)         (GMAC_MMSL_IMR_SMDS_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_IMR_SMDS_ERR_Pos)) /* Assigment of value for SMDS_ERR in the GMAC_MMSL_IMR register */
#define GMAC_MMSL_IMR_SMDC_ERR_Pos            _UINT32_(3)                                          /* (GMAC_MMSL_IMR) SMD-C Received When Waiting an SMD-S Position */
#define GMAC_MMSL_IMR_SMDC_ERR_Msk            (_UINT32_(0x1) << GMAC_MMSL_IMR_SMDC_ERR_Pos)        /* (GMAC_MMSL_IMR) SMD-C Received When Waiting an SMD-S Mask */
#define GMAC_MMSL_IMR_SMDC_ERR(value)         (GMAC_MMSL_IMR_SMDC_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_IMR_SMDC_ERR_Pos)) /* Assigment of value for SMDC_ERR in the GMAC_MMSL_IMR register */
#define GMAC_MMSL_IMR_FR_COUNT_ERR_Pos        _UINT32_(4)                                          /* (GMAC_MMSL_IMR) Illegal SMD Received Position */
#define GMAC_MMSL_IMR_FR_COUNT_ERR_Msk        (_UINT32_(0x1) << GMAC_MMSL_IMR_FR_COUNT_ERR_Pos)    /* (GMAC_MMSL_IMR) Illegal SMD Received Mask */
#define GMAC_MMSL_IMR_FR_COUNT_ERR(value)     (GMAC_MMSL_IMR_FR_COUNT_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_IMR_FR_COUNT_ERR_Pos)) /* Assigment of value for FR_COUNT_ERR in the GMAC_MMSL_IMR register */
#define GMAC_MMSL_IMR_SMD_ERR_Pos             _UINT32_(5)                                          /* (GMAC_MMSL_IMR) Illegal SMD Received Position */
#define GMAC_MMSL_IMR_SMD_ERR_Msk             (_UINT32_(0x1) << GMAC_MMSL_IMR_SMD_ERR_Pos)         /* (GMAC_MMSL_IMR) Illegal SMD Received Mask */
#define GMAC_MMSL_IMR_SMD_ERR(value)          (GMAC_MMSL_IMR_SMD_ERR_Msk & (_UINT32_(value) << GMAC_MMSL_IMR_SMD_ERR_Pos)) /* Assigment of value for SMD_ERR in the GMAC_MMSL_IMR register */
#define GMAC_MMSL_IMR_Msk                     _UINT32_(0x0000003F)                                 /* (GMAC_MMSL_IMR) Register Mask  */


/* -------- GMAC_EMAC_NCR : (GMAC Offset: 0x1000) (R/W 32) Express MAC Network Control Register -------- */
#define GMAC_EMAC_NCR_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_NCR) Express MAC Network Control Register  Reset Value */

#define GMAC_EMAC_NCR_LBL_Pos                 _UINT32_(1)                                          /* (GMAC_EMAC_NCR) Loop Back Local Position */
#define GMAC_EMAC_NCR_LBL_Msk                 (_UINT32_(0x1) << GMAC_EMAC_NCR_LBL_Pos)             /* (GMAC_EMAC_NCR) Loop Back Local Mask */
#define GMAC_EMAC_NCR_LBL(value)              (GMAC_EMAC_NCR_LBL_Msk & (_UINT32_(value) << GMAC_EMAC_NCR_LBL_Pos)) /* Assigment of value for LBL in the GMAC_EMAC_NCR register */
#define   GMAC_EMAC_NCR_LBL_0_Val             _UINT32_(0x0)                                        /* (GMAC_EMAC_NCR) Normal operating mode (no loop back).  */
#define   GMAC_EMAC_NCR_LBL_1_Val             _UINT32_(0x1)                                        /* (GMAC_EMAC_NCR) Connects GTX to GRX, GTXEN to GRXDV and forces Full Duplex mode. GRXCK and GTXCK may malfunction as the GMAC is switched into and out of internal loop back. It is important that receive and transmit circuits have already been disabled when making the switch into and out of internal loop back.  */
#define GMAC_EMAC_NCR_LBL_0                   (GMAC_EMAC_NCR_LBL_0_Val << GMAC_EMAC_NCR_LBL_Pos)   /* (GMAC_EMAC_NCR) Normal operating mode (no loop back). Position  */
#define GMAC_EMAC_NCR_LBL_1                   (GMAC_EMAC_NCR_LBL_1_Val << GMAC_EMAC_NCR_LBL_Pos)   /* (GMAC_EMAC_NCR) Connects GTX to GRX, GTXEN to GRXDV and forces Full Duplex mode. GRXCK and GTXCK may malfunction as the GMAC is switched into and out of internal loop back. It is important that receive and transmit circuits have already been disabled when making the switch into and out of internal loop back. Position  */
#define GMAC_EMAC_NCR_RXEN_Pos                _UINT32_(2)                                          /* (GMAC_EMAC_NCR) Receive Enable Position */
#define GMAC_EMAC_NCR_RXEN_Msk                (_UINT32_(0x1) << GMAC_EMAC_NCR_RXEN_Pos)            /* (GMAC_EMAC_NCR) Receive Enable Mask */
#define GMAC_EMAC_NCR_RXEN(value)             (GMAC_EMAC_NCR_RXEN_Msk & (_UINT32_(value) << GMAC_EMAC_NCR_RXEN_Pos)) /* Assigment of value for RXEN in the GMAC_EMAC_NCR register */
#define   GMAC_EMAC_NCR_RXEN_0_Val            _UINT32_(0x0)                                        /* (GMAC_EMAC_NCR) Stops frame reception immediately and the receive pipeline will be cleared. The Receive Queue Pointer Register is unaffected.  */
#define   GMAC_EMAC_NCR_RXEN_1_Val            _UINT32_(0x1)                                        /* (GMAC_EMAC_NCR) Enables the GMAC to receive data.  */
#define GMAC_EMAC_NCR_RXEN_0                  (GMAC_EMAC_NCR_RXEN_0_Val << GMAC_EMAC_NCR_RXEN_Pos) /* (GMAC_EMAC_NCR) Stops frame reception immediately and the receive pipeline will be cleared. The Receive Queue Pointer Register is unaffected. Position  */
#define GMAC_EMAC_NCR_RXEN_1                  (GMAC_EMAC_NCR_RXEN_1_Val << GMAC_EMAC_NCR_RXEN_Pos) /* (GMAC_EMAC_NCR) Enables the GMAC to receive data. Position  */
#define GMAC_EMAC_NCR_TXEN_Pos                _UINT32_(3)                                          /* (GMAC_EMAC_NCR) Transmit Enable Position */
#define GMAC_EMAC_NCR_TXEN_Msk                (_UINT32_(0x1) << GMAC_EMAC_NCR_TXEN_Pos)            /* (GMAC_EMAC_NCR) Transmit Enable Mask */
#define GMAC_EMAC_NCR_TXEN(value)             (GMAC_EMAC_NCR_TXEN_Msk & (_UINT32_(value) << GMAC_EMAC_NCR_TXEN_Pos)) /* Assigment of value for TXEN in the GMAC_EMAC_NCR register */
#define   GMAC_EMAC_NCR_TXEN_0_Val            _UINT32_(0x0)                                        /* (GMAC_EMAC_NCR) Stops transmission immediately, the transmit pipeline and control registers will be cleared and the Transmit Queue Pointer Register will reset to point to the start of the transmit descriptor list.  */
#define   GMAC_EMAC_NCR_TXEN_1_Val            _UINT32_(0x1)                                        /* (GMAC_EMAC_NCR) Enables the GMAC transmitter to send data.  */
#define GMAC_EMAC_NCR_TXEN_0                  (GMAC_EMAC_NCR_TXEN_0_Val << GMAC_EMAC_NCR_TXEN_Pos) /* (GMAC_EMAC_NCR) Stops transmission immediately, the transmit pipeline and control registers will be cleared and the Transmit Queue Pointer Register will reset to point to the start of the transmit descriptor list. Position  */
#define GMAC_EMAC_NCR_TXEN_1                  (GMAC_EMAC_NCR_TXEN_1_Val << GMAC_EMAC_NCR_TXEN_Pos) /* (GMAC_EMAC_NCR) Enables the GMAC transmitter to send data. Position  */
#define GMAC_EMAC_NCR_MPE_Pos                 _UINT32_(4)                                          /* (GMAC_EMAC_NCR) Management Port Enable Position */
#define GMAC_EMAC_NCR_MPE_Msk                 (_UINT32_(0x1) << GMAC_EMAC_NCR_MPE_Pos)             /* (GMAC_EMAC_NCR) Management Port Enable Mask */
#define GMAC_EMAC_NCR_MPE(value)              (GMAC_EMAC_NCR_MPE_Msk & (_UINT32_(value) << GMAC_EMAC_NCR_MPE_Pos)) /* Assigment of value for MPE in the GMAC_EMAC_NCR register */
#define   GMAC_EMAC_NCR_MPE_0_Val             _UINT32_(0x0)                                        /* (GMAC_EMAC_NCR) Forces GMDIO to high impedance state and MDC low.  */
#define   GMAC_EMAC_NCR_MPE_1_Val             _UINT32_(0x1)                                        /* (GMAC_EMAC_NCR) Enables the management port.  */
#define GMAC_EMAC_NCR_MPE_0                   (GMAC_EMAC_NCR_MPE_0_Val << GMAC_EMAC_NCR_MPE_Pos)   /* (GMAC_EMAC_NCR) Forces GMDIO to high impedance state and MDC low. Position  */
#define GMAC_EMAC_NCR_MPE_1                   (GMAC_EMAC_NCR_MPE_1_Val << GMAC_EMAC_NCR_MPE_Pos)   /* (GMAC_EMAC_NCR) Enables the management port. Position  */
#define GMAC_EMAC_NCR_CLRSTAT_Pos             _UINT32_(5)                                          /* (GMAC_EMAC_NCR) Clear Statistics Registers (Write-only) Position */
#define GMAC_EMAC_NCR_CLRSTAT_Msk             (_UINT32_(0x1) << GMAC_EMAC_NCR_CLRSTAT_Pos)         /* (GMAC_EMAC_NCR) Clear Statistics Registers (Write-only) Mask */
#define GMAC_EMAC_NCR_CLRSTAT(value)          (GMAC_EMAC_NCR_CLRSTAT_Msk & (_UINT32_(value) << GMAC_EMAC_NCR_CLRSTAT_Pos)) /* Assigment of value for CLRSTAT in the GMAC_EMAC_NCR register */
#define   GMAC_EMAC_NCR_CLRSTAT_0_Val         _UINT32_(0x0)                                        /* (GMAC_EMAC_NCR) No effect.  */
#define   GMAC_EMAC_NCR_CLRSTAT_1_Val         _UINT32_(0x1)                                        /* (GMAC_EMAC_NCR) Clears the statistics registers.  */
#define GMAC_EMAC_NCR_CLRSTAT_0               (GMAC_EMAC_NCR_CLRSTAT_0_Val << GMAC_EMAC_NCR_CLRSTAT_Pos) /* (GMAC_EMAC_NCR) No effect. Position  */
#define GMAC_EMAC_NCR_CLRSTAT_1               (GMAC_EMAC_NCR_CLRSTAT_1_Val << GMAC_EMAC_NCR_CLRSTAT_Pos) /* (GMAC_EMAC_NCR) Clears the statistics registers. Position  */
#define GMAC_EMAC_NCR_INCSTAT_Pos             _UINT32_(6)                                          /* (GMAC_EMAC_NCR) Increment Statistics Registers (Write-only) Position */
#define GMAC_EMAC_NCR_INCSTAT_Msk             (_UINT32_(0x1) << GMAC_EMAC_NCR_INCSTAT_Pos)         /* (GMAC_EMAC_NCR) Increment Statistics Registers (Write-only) Mask */
#define GMAC_EMAC_NCR_INCSTAT(value)          (GMAC_EMAC_NCR_INCSTAT_Msk & (_UINT32_(value) << GMAC_EMAC_NCR_INCSTAT_Pos)) /* Assigment of value for INCSTAT in the GMAC_EMAC_NCR register */
#define GMAC_EMAC_NCR_WESTAT_Pos              _UINT32_(7)                                          /* (GMAC_EMAC_NCR) Write Enable for Statistics Registers Position */
#define GMAC_EMAC_NCR_WESTAT_Msk              (_UINT32_(0x1) << GMAC_EMAC_NCR_WESTAT_Pos)          /* (GMAC_EMAC_NCR) Write Enable for Statistics Registers Mask */
#define GMAC_EMAC_NCR_WESTAT(value)           (GMAC_EMAC_NCR_WESTAT_Msk & (_UINT32_(value) << GMAC_EMAC_NCR_WESTAT_Pos)) /* Assigment of value for WESTAT in the GMAC_EMAC_NCR register */
#define   GMAC_EMAC_NCR_WESTAT_0_Val          _UINT32_(0x0)                                        /* (GMAC_EMAC_NCR) Forces the statistics registers to be in read-only mode for normal operation mode.  */
#define   GMAC_EMAC_NCR_WESTAT_1_Val          _UINT32_(0x1)                                        /* (GMAC_EMAC_NCR) Makes the statistics registers writable for functional test purposes.  */
#define GMAC_EMAC_NCR_WESTAT_0                (GMAC_EMAC_NCR_WESTAT_0_Val << GMAC_EMAC_NCR_WESTAT_Pos) /* (GMAC_EMAC_NCR) Forces the statistics registers to be in read-only mode for normal operation mode. Position  */
#define GMAC_EMAC_NCR_WESTAT_1                (GMAC_EMAC_NCR_WESTAT_1_Val << GMAC_EMAC_NCR_WESTAT_Pos) /* (GMAC_EMAC_NCR) Makes the statistics registers writable for functional test purposes. Position  */
#define GMAC_EMAC_NCR_BP_Pos                  _UINT32_(8)                                          /* (GMAC_EMAC_NCR) Back Pressure Position */
#define GMAC_EMAC_NCR_BP_Msk                  (_UINT32_(0x1) << GMAC_EMAC_NCR_BP_Pos)              /* (GMAC_EMAC_NCR) Back Pressure Mask */
#define GMAC_EMAC_NCR_BP(value)               (GMAC_EMAC_NCR_BP_Msk & (_UINT32_(value) << GMAC_EMAC_NCR_BP_Pos)) /* Assigment of value for BP in the GMAC_EMAC_NCR register */
#define   GMAC_EMAC_NCR_BP_0_Val              _UINT32_(0x0)                                        /* (GMAC_EMAC_NCR) No effect  */
#define   GMAC_EMAC_NCR_BP_1_Val              _UINT32_(0x1)                                        /* (GMAC_EMAC_NCR) When the MAC is set in 10M or 100M Half Duplex mode, forces collisions on all received frames. Ignored in Gigabit Half Duplex mode.  */
#define GMAC_EMAC_NCR_BP_0                    (GMAC_EMAC_NCR_BP_0_Val << GMAC_EMAC_NCR_BP_Pos)     /* (GMAC_EMAC_NCR) No effect Position  */
#define GMAC_EMAC_NCR_BP_1                    (GMAC_EMAC_NCR_BP_1_Val << GMAC_EMAC_NCR_BP_Pos)     /* (GMAC_EMAC_NCR) When the MAC is set in 10M or 100M Half Duplex mode, forces collisions on all received frames. Ignored in Gigabit Half Duplex mode. Position  */
#define GMAC_EMAC_NCR_TSTART_Pos              _UINT32_(9)                                          /* (GMAC_EMAC_NCR) Start Transmission (Write-only) Position */
#define GMAC_EMAC_NCR_TSTART_Msk              (_UINT32_(0x1) << GMAC_EMAC_NCR_TSTART_Pos)          /* (GMAC_EMAC_NCR) Start Transmission (Write-only) Mask */
#define GMAC_EMAC_NCR_TSTART(value)           (GMAC_EMAC_NCR_TSTART_Msk & (_UINT32_(value) << GMAC_EMAC_NCR_TSTART_Pos)) /* Assigment of value for TSTART in the GMAC_EMAC_NCR register */
#define   GMAC_EMAC_NCR_TSTART_0_Val          _UINT32_(0x0)                                        /* (GMAC_EMAC_NCR) No effect.  */
#define   GMAC_EMAC_NCR_TSTART_1_Val          _UINT32_(0x1)                                        /* (GMAC_EMAC_NCR) Starts transmission.  */
#define GMAC_EMAC_NCR_TSTART_0                (GMAC_EMAC_NCR_TSTART_0_Val << GMAC_EMAC_NCR_TSTART_Pos) /* (GMAC_EMAC_NCR) No effect. Position  */
#define GMAC_EMAC_NCR_TSTART_1                (GMAC_EMAC_NCR_TSTART_1_Val << GMAC_EMAC_NCR_TSTART_Pos) /* (GMAC_EMAC_NCR) Starts transmission. Position  */
#define GMAC_EMAC_NCR_THALT_Pos               _UINT32_(10)                                         /* (GMAC_EMAC_NCR) Transmit Halt (Write-only) Position */
#define GMAC_EMAC_NCR_THALT_Msk               (_UINT32_(0x1) << GMAC_EMAC_NCR_THALT_Pos)           /* (GMAC_EMAC_NCR) Transmit Halt (Write-only) Mask */
#define GMAC_EMAC_NCR_THALT(value)            (GMAC_EMAC_NCR_THALT_Msk & (_UINT32_(value) << GMAC_EMAC_NCR_THALT_Pos)) /* Assigment of value for THALT in the GMAC_EMAC_NCR register */
#define   GMAC_EMAC_NCR_THALT_0_Val           _UINT32_(0x0)                                        /* (GMAC_EMAC_NCR) No effect.  */
#define   GMAC_EMAC_NCR_THALT_1_Val           _UINT32_(0x1)                                        /* (GMAC_EMAC_NCR) Halts transmission as soon as any ongoing frame transmission ends.  */
#define GMAC_EMAC_NCR_THALT_0                 (GMAC_EMAC_NCR_THALT_0_Val << GMAC_EMAC_NCR_THALT_Pos) /* (GMAC_EMAC_NCR) No effect. Position  */
#define GMAC_EMAC_NCR_THALT_1                 (GMAC_EMAC_NCR_THALT_1_Val << GMAC_EMAC_NCR_THALT_Pos) /* (GMAC_EMAC_NCR) Halts transmission as soon as any ongoing frame transmission ends. Position  */
#define GMAC_EMAC_NCR_TXPF_Pos                _UINT32_(11)                                         /* (GMAC_EMAC_NCR) Transmit Pause Frame (Write-only) Position */
#define GMAC_EMAC_NCR_TXPF_Msk                (_UINT32_(0x1) << GMAC_EMAC_NCR_TXPF_Pos)            /* (GMAC_EMAC_NCR) Transmit Pause Frame (Write-only) Mask */
#define GMAC_EMAC_NCR_TXPF(value)             (GMAC_EMAC_NCR_TXPF_Msk & (_UINT32_(value) << GMAC_EMAC_NCR_TXPF_Pos)) /* Assigment of value for TXPF in the GMAC_EMAC_NCR register */
#define   GMAC_EMAC_NCR_TXPF_0_Val            _UINT32_(0x0)                                        /* (GMAC_EMAC_NCR) No effect.  */
#define   GMAC_EMAC_NCR_TXPF_1_Val            _UINT32_(0x1)                                        /* (GMAC_EMAC_NCR) Generates a pause frame to be transmitted.  */
#define GMAC_EMAC_NCR_TXPF_0                  (GMAC_EMAC_NCR_TXPF_0_Val << GMAC_EMAC_NCR_TXPF_Pos) /* (GMAC_EMAC_NCR) No effect. Position  */
#define GMAC_EMAC_NCR_TXPF_1                  (GMAC_EMAC_NCR_TXPF_1_Val << GMAC_EMAC_NCR_TXPF_Pos) /* (GMAC_EMAC_NCR) Generates a pause frame to be transmitted. Position  */
#define GMAC_EMAC_NCR_TXZQPF_Pos              _UINT32_(12)                                         /* (GMAC_EMAC_NCR) Transmit Zero Quantum Pause Frame (Write-only) Position */
#define GMAC_EMAC_NCR_TXZQPF_Msk              (_UINT32_(0x1) << GMAC_EMAC_NCR_TXZQPF_Pos)          /* (GMAC_EMAC_NCR) Transmit Zero Quantum Pause Frame (Write-only) Mask */
#define GMAC_EMAC_NCR_TXZQPF(value)           (GMAC_EMAC_NCR_TXZQPF_Msk & (_UINT32_(value) << GMAC_EMAC_NCR_TXZQPF_Pos)) /* Assigment of value for TXZQPF in the GMAC_EMAC_NCR register */
#define   GMAC_EMAC_NCR_TXZQPF_0_Val          _UINT32_(0x0)                                        /* (GMAC_EMAC_NCR) No effect.  */
#define   GMAC_EMAC_NCR_TXZQPF_1_Val          _UINT32_(0x1)                                        /* (GMAC_EMAC_NCR) Generates a pause frame with zero quantum to be transmitted.  */
#define GMAC_EMAC_NCR_TXZQPF_0                (GMAC_EMAC_NCR_TXZQPF_0_Val << GMAC_EMAC_NCR_TXZQPF_Pos) /* (GMAC_EMAC_NCR) No effect. Position  */
#define GMAC_EMAC_NCR_TXZQPF_1                (GMAC_EMAC_NCR_TXZQPF_1_Val << GMAC_EMAC_NCR_TXZQPF_Pos) /* (GMAC_EMAC_NCR) Generates a pause frame with zero quantum to be transmitted. Position  */
#define GMAC_EMAC_NCR_SRTSM_Pos               _UINT32_(15)                                         /* (GMAC_EMAC_NCR) Store Receive Timestamp to Memory Position */
#define GMAC_EMAC_NCR_SRTSM_Msk               (_UINT32_(0x1) << GMAC_EMAC_NCR_SRTSM_Pos)           /* (GMAC_EMAC_NCR) Store Receive Timestamp to Memory Mask */
#define GMAC_EMAC_NCR_SRTSM(value)            (GMAC_EMAC_NCR_SRTSM_Msk & (_UINT32_(value) << GMAC_EMAC_NCR_SRTSM_Pos)) /* Assigment of value for SRTSM in the GMAC_EMAC_NCR register */
#define   GMAC_EMAC_NCR_SRTSM_0_Val           _UINT32_(0x0)                                        /* (GMAC_EMAC_NCR) Normal operation.  */
#define   GMAC_EMAC_NCR_SRTSM_1_Val           _UINT32_(0x1)                                        /* (GMAC_EMAC_NCR) Causes the CRC of every received frame to be replaced with the value of the nanoseconds field of the 1588 timer that was captured as the receive frame passed the message timestamp point. Note that bit RFCS in register GMAC_NCFGR may not be set to 1 when the timer should be captured.  */
#define GMAC_EMAC_NCR_SRTSM_0                 (GMAC_EMAC_NCR_SRTSM_0_Val << GMAC_EMAC_NCR_SRTSM_Pos) /* (GMAC_EMAC_NCR) Normal operation. Position  */
#define GMAC_EMAC_NCR_SRTSM_1                 (GMAC_EMAC_NCR_SRTSM_1_Val << GMAC_EMAC_NCR_SRTSM_Pos) /* (GMAC_EMAC_NCR) Causes the CRC of every received frame to be replaced with the value of the nanoseconds field of the 1588 timer that was captured as the receive frame passed the message timestamp point. Note that bit RFCS in register GMAC_NCFGR may not be set to 1 when the timer should be captured. Position  */
#define GMAC_EMAC_NCR_ENPBPR_Pos              _UINT32_(16)                                         /* (GMAC_EMAC_NCR) Enable PFC Priority-based Pause Reception Position */
#define GMAC_EMAC_NCR_ENPBPR_Msk              (_UINT32_(0x1) << GMAC_EMAC_NCR_ENPBPR_Pos)          /* (GMAC_EMAC_NCR) Enable PFC Priority-based Pause Reception Mask */
#define GMAC_EMAC_NCR_ENPBPR(value)           (GMAC_EMAC_NCR_ENPBPR_Msk & (_UINT32_(value) << GMAC_EMAC_NCR_ENPBPR_Pos)) /* Assigment of value for ENPBPR in the GMAC_EMAC_NCR register */
#define   GMAC_EMAC_NCR_ENPBPR_0_Val          _UINT32_(0x0)                                        /* (GMAC_EMAC_NCR) Disables PFC Priority Based Pause Reception capabilities.  */
#define   GMAC_EMAC_NCR_ENPBPR_1_Val          _UINT32_(0x1)                                        /* (GMAC_EMAC_NCR) Enables PFC Priority Based Pause Reception capabilities by enabling the PFC negotiation and recognition of priority-based pause frames.  */
#define GMAC_EMAC_NCR_ENPBPR_0                (GMAC_EMAC_NCR_ENPBPR_0_Val << GMAC_EMAC_NCR_ENPBPR_Pos) /* (GMAC_EMAC_NCR) Disables PFC Priority Based Pause Reception capabilities. Position  */
#define GMAC_EMAC_NCR_ENPBPR_1                (GMAC_EMAC_NCR_ENPBPR_1_Val << GMAC_EMAC_NCR_ENPBPR_Pos) /* (GMAC_EMAC_NCR) Enables PFC Priority Based Pause Reception capabilities by enabling the PFC negotiation and recognition of priority-based pause frames. Position  */
#define GMAC_EMAC_NCR_TXPBPF_Pos              _UINT32_(17)                                         /* (GMAC_EMAC_NCR) Transmit PFC Priority-based Pause Frame (Write-only) Position */
#define GMAC_EMAC_NCR_TXPBPF_Msk              (_UINT32_(0x1) << GMAC_EMAC_NCR_TXPBPF_Pos)          /* (GMAC_EMAC_NCR) Transmit PFC Priority-based Pause Frame (Write-only) Mask */
#define GMAC_EMAC_NCR_TXPBPF(value)           (GMAC_EMAC_NCR_TXPBPF_Msk & (_UINT32_(value) << GMAC_EMAC_NCR_TXPBPF_Pos)) /* Assigment of value for TXPBPF in the GMAC_EMAC_NCR register */
#define   GMAC_EMAC_NCR_TXPBPF_0_Val          _UINT32_(0x0)                                        /* (GMAC_EMAC_NCR) No effect.  */
#define   GMAC_EMAC_NCR_TXPBPF_1_Val          _UINT32_(0x1)                                        /* (GMAC_EMAC_NCR) Takes the values stored in the Transmit PFC Pause Register.  */
#define GMAC_EMAC_NCR_TXPBPF_0                (GMAC_EMAC_NCR_TXPBPF_0_Val << GMAC_EMAC_NCR_TXPBPF_Pos) /* (GMAC_EMAC_NCR) No effect. Position  */
#define GMAC_EMAC_NCR_TXPBPF_1                (GMAC_EMAC_NCR_TXPBPF_1_Val << GMAC_EMAC_NCR_TXPBPF_Pos) /* (GMAC_EMAC_NCR) Takes the values stored in the Transmit PFC Pause Register. Position  */
#define GMAC_EMAC_NCR_FNP_Pos                 _UINT32_(18)                                         /* (GMAC_EMAC_NCR) Flush Next Packet (Write-only) Position */
#define GMAC_EMAC_NCR_FNP_Msk                 (_UINT32_(0x1) << GMAC_EMAC_NCR_FNP_Pos)             /* (GMAC_EMAC_NCR) Flush Next Packet (Write-only) Mask */
#define GMAC_EMAC_NCR_FNP(value)              (GMAC_EMAC_NCR_FNP_Msk & (_UINT32_(value) << GMAC_EMAC_NCR_FNP_Pos)) /* Assigment of value for FNP in the GMAC_EMAC_NCR register */
#define   GMAC_EMAC_NCR_FNP_0_Val             _UINT32_(0x0)                                        /* (GMAC_EMAC_NCR) No effect.  */
#define   GMAC_EMAC_NCR_FNP_1_Val             _UINT32_(0x1)                                        /* (GMAC_EMAC_NCR) Flushes the next packet from the receive memory. This will only have an effect if the DMA is not currently writing a packet already stored in the receive memory to system memory.  */
#define GMAC_EMAC_NCR_FNP_0                   (GMAC_EMAC_NCR_FNP_0_Val << GMAC_EMAC_NCR_FNP_Pos)   /* (GMAC_EMAC_NCR) No effect. Position  */
#define GMAC_EMAC_NCR_FNP_1                   (GMAC_EMAC_NCR_FNP_1_Val << GMAC_EMAC_NCR_FNP_Pos)   /* (GMAC_EMAC_NCR) Flushes the next packet from the receive memory. This will only have an effect if the DMA is not currently writing a packet already stored in the receive memory to system memory. Position  */
#define GMAC_EMAC_NCR_TXLPIEN_Pos             _UINT32_(19)                                         /* (GMAC_EMAC_NCR) Enable LPI Transmission Position */
#define GMAC_EMAC_NCR_TXLPIEN_Msk             (_UINT32_(0x1) << GMAC_EMAC_NCR_TXLPIEN_Pos)         /* (GMAC_EMAC_NCR) Enable LPI Transmission Mask */
#define GMAC_EMAC_NCR_TXLPIEN(value)          (GMAC_EMAC_NCR_TXLPIEN_Msk & (_UINT32_(value) << GMAC_EMAC_NCR_TXLPIEN_Pos)) /* Assigment of value for TXLPIEN in the GMAC_EMAC_NCR register */
#define GMAC_EMAC_NCR_PTPUNIENA_Pos           _UINT32_(20)                                         /* (GMAC_EMAC_NCR) Detection of Unicast PTP Frames Enable Position */
#define GMAC_EMAC_NCR_PTPUNIENA_Msk           (_UINT32_(0x1) << GMAC_EMAC_NCR_PTPUNIENA_Pos)       /* (GMAC_EMAC_NCR) Detection of Unicast PTP Frames Enable Mask */
#define GMAC_EMAC_NCR_PTPUNIENA(value)        (GMAC_EMAC_NCR_PTPUNIENA_Msk & (_UINT32_(value) << GMAC_EMAC_NCR_PTPUNIENA_Pos)) /* Assigment of value for PTPUNIENA in the GMAC_EMAC_NCR register */
#define   GMAC_EMAC_NCR_PTPUNIENA_0_Val       _UINT32_(0x0)                                        /* (GMAC_EMAC_NCR) Disables detection of unicast PTP frames.  */
#define   GMAC_EMAC_NCR_PTPUNIENA_1_Val       _UINT32_(0x1)                                        /* (GMAC_EMAC_NCR) Enables detection of unicast PTP frames.  */
#define GMAC_EMAC_NCR_PTPUNIENA_0             (GMAC_EMAC_NCR_PTPUNIENA_0_Val << GMAC_EMAC_NCR_PTPUNIENA_Pos) /* (GMAC_EMAC_NCR) Disables detection of unicast PTP frames. Position  */
#define GMAC_EMAC_NCR_PTPUNIENA_1             (GMAC_EMAC_NCR_PTPUNIENA_1_Val << GMAC_EMAC_NCR_PTPUNIENA_Pos) /* (GMAC_EMAC_NCR) Enables detection of unicast PTP frames. Position  */
#define GMAC_EMAC_NCR_STUDPOFFSET_Pos         _UINT32_(22)                                         /* (GMAC_EMAC_NCR) Store UDP Offset Position */
#define GMAC_EMAC_NCR_STUDPOFFSET_Msk         (_UINT32_(0x1) << GMAC_EMAC_NCR_STUDPOFFSET_Pos)     /* (GMAC_EMAC_NCR) Store UDP Offset Mask */
#define GMAC_EMAC_NCR_STUDPOFFSET(value)      (GMAC_EMAC_NCR_STUDPOFFSET_Msk & (_UINT32_(value) << GMAC_EMAC_NCR_STUDPOFFSET_Pos)) /* Assigment of value for STUDPOFFSET in the GMAC_EMAC_NCR register */
#define   GMAC_EMAC_NCR_STUDPOFFSET_0_Val     _UINT32_(0x0)                                        /* (GMAC_EMAC_NCR) Normal operations.  */
#define   GMAC_EMAC_NCR_STUDPOFFSET_1_Val     _UINT32_(0x1)                                        /* (GMAC_EMAC_NCR) The upper 16 bits of the CRC of every received frame are replaced with the offset from start of frame to the beginning of the UDP or TCP header. The lower 16 bits of the CRC are replaced with zero and reserved for future use. The offset is measured in units of 2 bytes.  */
#define GMAC_EMAC_NCR_STUDPOFFSET_0           (GMAC_EMAC_NCR_STUDPOFFSET_0_Val << GMAC_EMAC_NCR_STUDPOFFSET_Pos) /* (GMAC_EMAC_NCR) Normal operations. Position  */
#define GMAC_EMAC_NCR_STUDPOFFSET_1           (GMAC_EMAC_NCR_STUDPOFFSET_1_Val << GMAC_EMAC_NCR_STUDPOFFSET_Pos) /* (GMAC_EMAC_NCR) The upper 16 bits of the CRC of every received frame are replaced with the offset from start of frame to the beginning of the UDP or TCP header. The lower 16 bits of the CRC are replaced with zero and reserved for future use. The offset is measured in units of 2 bytes. Position  */
#define GMAC_EMAC_NCR_OSSMODE_Pos             _UINT32_(24)                                         /* (GMAC_EMAC_NCR) One Step Sync Mode Position */
#define GMAC_EMAC_NCR_OSSMODE_Msk             (_UINT32_(0x1) << GMAC_EMAC_NCR_OSSMODE_Pos)         /* (GMAC_EMAC_NCR) One Step Sync Mode Mask */
#define GMAC_EMAC_NCR_OSSMODE(value)          (GMAC_EMAC_NCR_OSSMODE_Msk & (_UINT32_(value) << GMAC_EMAC_NCR_OSSMODE_Pos)) /* Assigment of value for OSSMODE in the GMAC_EMAC_NCR register */
#define   GMAC_EMAC_NCR_OSSMODE_0_Val         _UINT32_(0x0)                                        /* (GMAC_EMAC_NCR) 1588 One Step Sync Mode is disabled.  */
#define   GMAC_EMAC_NCR_OSSMODE_1_Val         _UINT32_(0x1)                                        /* (GMAC_EMAC_NCR) 1588 One Step Sync Mode is enabled. Replaces timestamp field in the 1588 header for TX Sync Frames with the current TSU timer value.  */
#define GMAC_EMAC_NCR_OSSMODE_0               (GMAC_EMAC_NCR_OSSMODE_0_Val << GMAC_EMAC_NCR_OSSMODE_Pos) /* (GMAC_EMAC_NCR) 1588 One Step Sync Mode is disabled. Position  */
#define GMAC_EMAC_NCR_OSSMODE_1               (GMAC_EMAC_NCR_OSSMODE_1_Val << GMAC_EMAC_NCR_OSSMODE_Pos) /* (GMAC_EMAC_NCR) 1588 One Step Sync Mode is enabled. Replaces timestamp field in the 1588 header for TX Sync Frames with the current TSU timer value. Position  */
#define GMAC_EMAC_NCR_PFCCTL_Pos              _UINT32_(25)                                         /* (GMAC_EMAC_NCR) Multiple PFC Pause quantum Enable Position */
#define GMAC_EMAC_NCR_PFCCTL_Msk              (_UINT32_(0x1) << GMAC_EMAC_NCR_PFCCTL_Pos)          /* (GMAC_EMAC_NCR) Multiple PFC Pause quantum Enable Mask */
#define GMAC_EMAC_NCR_PFCCTL(value)           (GMAC_EMAC_NCR_PFCCTL_Msk & (_UINT32_(value) << GMAC_EMAC_NCR_PFCCTL_Pos)) /* Assigment of value for PFCCTL in the GMAC_EMAC_NCR register */
#define   GMAC_EMAC_NCR_PFCCTL_0_Val          _UINT32_(0x0)                                        /* (GMAC_EMAC_NCR) Disables multiple PFC pause quantums.  */
#define   GMAC_EMAC_NCR_PFCCTL_1_Val          _UINT32_(0x1)                                        /* (GMAC_EMAC_NCR) Enables multiple PFC pause quantums, one per pause priority.  */
#define GMAC_EMAC_NCR_PFCCTL_0                (GMAC_EMAC_NCR_PFCCTL_0_Val << GMAC_EMAC_NCR_PFCCTL_Pos) /* (GMAC_EMAC_NCR) Disables multiple PFC pause quantums. Position  */
#define GMAC_EMAC_NCR_PFCCTL_1                (GMAC_EMAC_NCR_PFCCTL_1_Val << GMAC_EMAC_NCR_PFCCTL_Pos) /* (GMAC_EMAC_NCR) Enables multiple PFC pause quantums, one per pause priority. Position  */
#define GMAC_EMAC_NCR_EXTSELRQEN_Pos          _UINT32_(26)                                         /* (GMAC_EMAC_NCR) External Selection of Receive Queue Enable Position */
#define GMAC_EMAC_NCR_EXTSELRQEN_Msk          (_UINT32_(0x1) << GMAC_EMAC_NCR_EXTSELRQEN_Pos)      /* (GMAC_EMAC_NCR) External Selection of Receive Queue Enable Mask */
#define GMAC_EMAC_NCR_EXTSELRQEN(value)       (GMAC_EMAC_NCR_EXTSELRQEN_Msk & (_UINT32_(value) << GMAC_EMAC_NCR_EXTSELRQEN_Pos)) /* Assigment of value for EXTSELRQEN in the GMAC_EMAC_NCR register */
#define   GMAC_EMAC_NCR_EXTSELRQEN_0_Val      _UINT32_(0x0)                                        /* (GMAC_EMAC_NCR) Disables external selection of receive queue.  */
#define   GMAC_EMAC_NCR_EXTSELRQEN_1_Val      _UINT32_(0x1)                                        /* (GMAC_EMAC_NCR) Enables external selection of receive queue.  */
#define GMAC_EMAC_NCR_EXTSELRQEN_0            (GMAC_EMAC_NCR_EXTSELRQEN_0_Val << GMAC_EMAC_NCR_EXTSELRQEN_Pos) /* (GMAC_EMAC_NCR) Disables external selection of receive queue. Position  */
#define GMAC_EMAC_NCR_EXTSELRQEN_1            (GMAC_EMAC_NCR_EXTSELRQEN_1_Val << GMAC_EMAC_NCR_EXTSELRQEN_Pos) /* (GMAC_EMAC_NCR) Enables external selection of receive queue. Position  */
#define GMAC_EMAC_NCR_OSSCORR_Pos             _UINT32_(27)                                         /* (GMAC_EMAC_NCR) 1588 One Step Sync Mode Correction Field Position */
#define GMAC_EMAC_NCR_OSSCORR_Msk             (_UINT32_(0x1) << GMAC_EMAC_NCR_OSSCORR_Pos)         /* (GMAC_EMAC_NCR) 1588 One Step Sync Mode Correction Field Mask */
#define GMAC_EMAC_NCR_OSSCORR(value)          (GMAC_EMAC_NCR_OSSCORR_Msk & (_UINT32_(value) << GMAC_EMAC_NCR_OSSCORR_Pos)) /* Assigment of value for OSSCORR in the GMAC_EMAC_NCR register */
#define   GMAC_EMAC_NCR_OSSCORR_0_Val         _UINT32_(0x0)                                        /* (GMAC_EMAC_NCR) Disables updating the correction field of PTP 1588 version 2 sync frames by adding current TSU timer value.  */
#define   GMAC_EMAC_NCR_OSSCORR_1_Val         _UINT32_(0x1)                                        /* (GMAC_EMAC_NCR) Enables updating the correction field of PTP 1588 version 2 sync frames by adding current TSU timer value.  */
#define GMAC_EMAC_NCR_OSSCORR_0               (GMAC_EMAC_NCR_OSSCORR_0_Val << GMAC_EMAC_NCR_OSSCORR_Pos) /* (GMAC_EMAC_NCR) Disables updating the correction field of PTP 1588 version 2 sync frames by adding current TSU timer value. Position  */
#define GMAC_EMAC_NCR_OSSCORR_1               (GMAC_EMAC_NCR_OSSCORR_1_Val << GMAC_EMAC_NCR_OSSCORR_Pos) /* (GMAC_EMAC_NCR) Enables updating the correction field of PTP 1588 version 2 sync frames by adding current TSU timer value. Position  */
#define GMAC_EMAC_NCR_IFGQAVCRED_Pos          _UINT32_(30)                                         /* (GMAC_EMAC_NCR) Credit-Based Shaping Algorithm Modification Position */
#define GMAC_EMAC_NCR_IFGQAVCRED_Msk          (_UINT32_(0x1) << GMAC_EMAC_NCR_IFGQAVCRED_Pos)      /* (GMAC_EMAC_NCR) Credit-Based Shaping Algorithm Modification Mask */
#define GMAC_EMAC_NCR_IFGQAVCRED(value)       (GMAC_EMAC_NCR_IFGQAVCRED_Msk & (_UINT32_(value) << GMAC_EMAC_NCR_IFGQAVCRED_Pos)) /* Assigment of value for IFGQAVCRED in the GMAC_EMAC_NCR register */
#define   GMAC_EMAC_NCR_IFGQAVCRED_0_Val      _UINT32_(0x0)                                        /* (GMAC_EMAC_NCR) No modification of the CBS algorithm.  */
#define   GMAC_EMAC_NCR_IFGQAVCRED_1_Val      _UINT32_(0x1)                                        /* (GMAC_EMAC_NCR) Modifies the CBS algorithm so the IFG/IPG associated with a transmit frame counts towards its 802.1Qav credit.  */
#define GMAC_EMAC_NCR_IFGQAVCRED_0            (GMAC_EMAC_NCR_IFGQAVCRED_0_Val << GMAC_EMAC_NCR_IFGQAVCRED_Pos) /* (GMAC_EMAC_NCR) No modification of the CBS algorithm. Position  */
#define GMAC_EMAC_NCR_IFGQAVCRED_1            (GMAC_EMAC_NCR_IFGQAVCRED_1_Val << GMAC_EMAC_NCR_IFGQAVCRED_Pos) /* (GMAC_EMAC_NCR) Modifies the CBS algorithm so the IFG/IPG associated with a transmit frame counts towards its 802.1Qav credit. Position  */
#define GMAC_EMAC_NCR_Msk                     _UINT32_(0x4F5F9FFE)                                 /* (GMAC_EMAC_NCR) Register Mask  */


/* -------- GMAC_EMAC_NCFGR : (GMAC Offset: 0x1004) (R/W 32) Express MAC Network Configuration Register -------- */
#define GMAC_EMAC_NCFGR_RESETVALUE            _UINT32_(0x80000)                                    /*  (GMAC_EMAC_NCFGR) Express MAC Network Configuration Register  Reset Value */

#define GMAC_EMAC_NCFGR_SPD_Pos               _UINT32_(0)                                          /* (GMAC_EMAC_NCFGR) Speed Position */
#define GMAC_EMAC_NCFGR_SPD_Msk               (_UINT32_(0x1) << GMAC_EMAC_NCFGR_SPD_Pos)           /* (GMAC_EMAC_NCFGR) Speed Mask */
#define GMAC_EMAC_NCFGR_SPD(value)            (GMAC_EMAC_NCFGR_SPD_Msk & (_UINT32_(value) << GMAC_EMAC_NCFGR_SPD_Pos)) /* Assigment of value for SPD in the GMAC_EMAC_NCFGR register */
#define   GMAC_EMAC_NCFGR_SPD_0_Val           _UINT32_(0x0)                                        /* (GMAC_EMAC_NCFGR) MAC operates at 10 Mbps.  */
#define   GMAC_EMAC_NCFGR_SPD_1_Val           _UINT32_(0x1)                                        /* (GMAC_EMAC_NCFGR) MAC Operates at 100 Mbps.  */
#define GMAC_EMAC_NCFGR_SPD_0                 (GMAC_EMAC_NCFGR_SPD_0_Val << GMAC_EMAC_NCFGR_SPD_Pos) /* (GMAC_EMAC_NCFGR) MAC operates at 10 Mbps. Position  */
#define GMAC_EMAC_NCFGR_SPD_1                 (GMAC_EMAC_NCFGR_SPD_1_Val << GMAC_EMAC_NCFGR_SPD_Pos) /* (GMAC_EMAC_NCFGR) MAC Operates at 100 Mbps. Position  */
#define GMAC_EMAC_NCFGR_FD_Pos                _UINT32_(1)                                          /* (GMAC_EMAC_NCFGR) Full Duplex Position */
#define GMAC_EMAC_NCFGR_FD_Msk                (_UINT32_(0x1) << GMAC_EMAC_NCFGR_FD_Pos)            /* (GMAC_EMAC_NCFGR) Full Duplex Mask */
#define GMAC_EMAC_NCFGR_FD(value)             (GMAC_EMAC_NCFGR_FD_Msk & (_UINT32_(value) << GMAC_EMAC_NCFGR_FD_Pos)) /* Assigment of value for FD in the GMAC_EMAC_NCFGR register */
#define   GMAC_EMAC_NCFGR_FD_0_Val            _UINT32_(0x0)                                        /* (GMAC_EMAC_NCFGR) Half-duplex mode.  */
#define   GMAC_EMAC_NCFGR_FD_1_Val            _UINT32_(0x1)                                        /* (GMAC_EMAC_NCFGR) The transmit block ignores the state of collision and carrier sense and allows receive while transmitting.  */
#define GMAC_EMAC_NCFGR_FD_0                  (GMAC_EMAC_NCFGR_FD_0_Val << GMAC_EMAC_NCFGR_FD_Pos) /* (GMAC_EMAC_NCFGR) Half-duplex mode. Position  */
#define GMAC_EMAC_NCFGR_FD_1                  (GMAC_EMAC_NCFGR_FD_1_Val << GMAC_EMAC_NCFGR_FD_Pos) /* (GMAC_EMAC_NCFGR) The transmit block ignores the state of collision and carrier sense and allows receive while transmitting. Position  */
#define GMAC_EMAC_NCFGR_DNVLAN_Pos            _UINT32_(2)                                          /* (GMAC_EMAC_NCFGR) Discard Non-VLAN FRAMES Position */
#define GMAC_EMAC_NCFGR_DNVLAN_Msk            (_UINT32_(0x1) << GMAC_EMAC_NCFGR_DNVLAN_Pos)        /* (GMAC_EMAC_NCFGR) Discard Non-VLAN FRAMES Mask */
#define GMAC_EMAC_NCFGR_DNVLAN(value)         (GMAC_EMAC_NCFGR_DNVLAN_Msk & (_UINT32_(value) << GMAC_EMAC_NCFGR_DNVLAN_Pos)) /* Assigment of value for DNVLAN in the GMAC_EMAC_NCFGR register */
#define   GMAC_EMAC_NCFGR_DNVLAN_0_Val        _UINT32_(0x0)                                        /* (GMAC_EMAC_NCFGR) Passes all frames to address matching logic  */
#define   GMAC_EMAC_NCFGR_DNVLAN_1_Val        _UINT32_(0x1)                                        /* (GMAC_EMAC_NCFGR) Passes only VLAN tagged frames to the address matching logic.  */
#define GMAC_EMAC_NCFGR_DNVLAN_0              (GMAC_EMAC_NCFGR_DNVLAN_0_Val << GMAC_EMAC_NCFGR_DNVLAN_Pos) /* (GMAC_EMAC_NCFGR) Passes all frames to address matching logic Position  */
#define GMAC_EMAC_NCFGR_DNVLAN_1              (GMAC_EMAC_NCFGR_DNVLAN_1_Val << GMAC_EMAC_NCFGR_DNVLAN_Pos) /* (GMAC_EMAC_NCFGR) Passes only VLAN tagged frames to the address matching logic. Position  */
#define GMAC_EMAC_NCFGR_JFRAME_Pos            _UINT32_(3)                                          /* (GMAC_EMAC_NCFGR) Jumbo Frame Size Position */
#define GMAC_EMAC_NCFGR_JFRAME_Msk            (_UINT32_(0x1) << GMAC_EMAC_NCFGR_JFRAME_Pos)        /* (GMAC_EMAC_NCFGR) Jumbo Frame Size Mask */
#define GMAC_EMAC_NCFGR_JFRAME(value)         (GMAC_EMAC_NCFGR_JFRAME_Msk & (_UINT32_(value) << GMAC_EMAC_NCFGR_JFRAME_Pos)) /* Assigment of value for JFRAME in the GMAC_EMAC_NCFGR register */
#define   GMAC_EMAC_NCFGR_JFRAME_0_Val        _UINT32_(0x0)                                        /* (GMAC_EMAC_NCFGR) Disables jumbo frames.  */
#define   GMAC_EMAC_NCFGR_JFRAME_1_Val        _UINT32_(0x1)                                        /* (GMAC_EMAC_NCFGR) Enables jumbo frames up to 10240 bytes to be accepted. The default length is 10240 bytes.  */
#define GMAC_EMAC_NCFGR_JFRAME_0              (GMAC_EMAC_NCFGR_JFRAME_0_Val << GMAC_EMAC_NCFGR_JFRAME_Pos) /* (GMAC_EMAC_NCFGR) Disables jumbo frames. Position  */
#define GMAC_EMAC_NCFGR_JFRAME_1              (GMAC_EMAC_NCFGR_JFRAME_1_Val << GMAC_EMAC_NCFGR_JFRAME_Pos) /* (GMAC_EMAC_NCFGR) Enables jumbo frames up to 10240 bytes to be accepted. The default length is 10240 bytes. Position  */
#define GMAC_EMAC_NCFGR_CAF_Pos               _UINT32_(4)                                          /* (GMAC_EMAC_NCFGR) Copy All Frames Position */
#define GMAC_EMAC_NCFGR_CAF_Msk               (_UINT32_(0x1) << GMAC_EMAC_NCFGR_CAF_Pos)           /* (GMAC_EMAC_NCFGR) Copy All Frames Mask */
#define GMAC_EMAC_NCFGR_CAF(value)            (GMAC_EMAC_NCFGR_CAF_Msk & (_UINT32_(value) << GMAC_EMAC_NCFGR_CAF_Pos)) /* Assigment of value for CAF in the GMAC_EMAC_NCFGR register */
#define   GMAC_EMAC_NCFGR_CAF_0_Val           _UINT32_(0x0)                                        /* (GMAC_EMAC_NCFGR) Discards invalid frames.  */
#define   GMAC_EMAC_NCFGR_CAF_1_Val           _UINT32_(0x1)                                        /* (GMAC_EMAC_NCFGR) Accepts all valid frames.  */
#define GMAC_EMAC_NCFGR_CAF_0                 (GMAC_EMAC_NCFGR_CAF_0_Val << GMAC_EMAC_NCFGR_CAF_Pos) /* (GMAC_EMAC_NCFGR) Discards invalid frames. Position  */
#define GMAC_EMAC_NCFGR_CAF_1                 (GMAC_EMAC_NCFGR_CAF_1_Val << GMAC_EMAC_NCFGR_CAF_Pos) /* (GMAC_EMAC_NCFGR) Accepts all valid frames. Position  */
#define GMAC_EMAC_NCFGR_NBC_Pos               _UINT32_(5)                                          /* (GMAC_EMAC_NCFGR) No Broadcast Position */
#define GMAC_EMAC_NCFGR_NBC_Msk               (_UINT32_(0x1) << GMAC_EMAC_NCFGR_NBC_Pos)           /* (GMAC_EMAC_NCFGR) No Broadcast Mask */
#define GMAC_EMAC_NCFGR_NBC(value)            (GMAC_EMAC_NCFGR_NBC_Msk & (_UINT32_(value) << GMAC_EMAC_NCFGR_NBC_Pos)) /* Assigment of value for NBC in the GMAC_EMAC_NCFGR register */
#define   GMAC_EMAC_NCFGR_NBC_0_Val           _UINT32_(0x0)                                        /* (GMAC_EMAC_NCFGR) Accepts broadcast frames.  */
#define   GMAC_EMAC_NCFGR_NBC_1_Val           _UINT32_(0x1)                                        /* (GMAC_EMAC_NCFGR) Rejects frames addressed to the broadcast address of all ones.  */
#define GMAC_EMAC_NCFGR_NBC_0                 (GMAC_EMAC_NCFGR_NBC_0_Val << GMAC_EMAC_NCFGR_NBC_Pos) /* (GMAC_EMAC_NCFGR) Accepts broadcast frames. Position  */
#define GMAC_EMAC_NCFGR_NBC_1                 (GMAC_EMAC_NCFGR_NBC_1_Val << GMAC_EMAC_NCFGR_NBC_Pos) /* (GMAC_EMAC_NCFGR) Rejects frames addressed to the broadcast address of all ones. Position  */
#define GMAC_EMAC_NCFGR_MTIHEN_Pos            _UINT32_(6)                                          /* (GMAC_EMAC_NCFGR) Multicast Hash Enable Position */
#define GMAC_EMAC_NCFGR_MTIHEN_Msk            (_UINT32_(0x1) << GMAC_EMAC_NCFGR_MTIHEN_Pos)        /* (GMAC_EMAC_NCFGR) Multicast Hash Enable Mask */
#define GMAC_EMAC_NCFGR_MTIHEN(value)         (GMAC_EMAC_NCFGR_MTIHEN_Msk & (_UINT32_(value) << GMAC_EMAC_NCFGR_MTIHEN_Pos)) /* Assigment of value for MTIHEN in the GMAC_EMAC_NCFGR register */
#define   GMAC_EMAC_NCFGR_MTIHEN_0_Val        _UINT32_(0x0)                                        /* (GMAC_EMAC_NCFGR) Rejects multicast frames.  */
#define   GMAC_EMAC_NCFGR_MTIHEN_1_Val        _UINT32_(0x1)                                        /* (GMAC_EMAC_NCFGR) Accepts multicast frames when the 6-bit hash function of the destination address points to a bit that is set in the Hash Register.  */
#define GMAC_EMAC_NCFGR_MTIHEN_0              (GMAC_EMAC_NCFGR_MTIHEN_0_Val << GMAC_EMAC_NCFGR_MTIHEN_Pos) /* (GMAC_EMAC_NCFGR) Rejects multicast frames. Position  */
#define GMAC_EMAC_NCFGR_MTIHEN_1              (GMAC_EMAC_NCFGR_MTIHEN_1_Val << GMAC_EMAC_NCFGR_MTIHEN_Pos) /* (GMAC_EMAC_NCFGR) Accepts multicast frames when the 6-bit hash function of the destination address points to a bit that is set in the Hash Register. Position  */
#define GMAC_EMAC_NCFGR_UNIHEN_Pos            _UINT32_(7)                                          /* (GMAC_EMAC_NCFGR) Unicast Hash Enable Position */
#define GMAC_EMAC_NCFGR_UNIHEN_Msk            (_UINT32_(0x1) << GMAC_EMAC_NCFGR_UNIHEN_Pos)        /* (GMAC_EMAC_NCFGR) Unicast Hash Enable Mask */
#define GMAC_EMAC_NCFGR_UNIHEN(value)         (GMAC_EMAC_NCFGR_UNIHEN_Msk & (_UINT32_(value) << GMAC_EMAC_NCFGR_UNIHEN_Pos)) /* Assigment of value for UNIHEN in the GMAC_EMAC_NCFGR register */
#define   GMAC_EMAC_NCFGR_UNIHEN_0_Val        _UINT32_(0x0)                                        /* (GMAC_EMAC_NCFGR) Rejects unicast frames.  */
#define   GMAC_EMAC_NCFGR_UNIHEN_1_Val        _UINT32_(0x1)                                        /* (GMAC_EMAC_NCFGR) Accepts unicast frames when the 6-bit hash function of the destination address points to a bit that is set in the Hash Register.  */
#define GMAC_EMAC_NCFGR_UNIHEN_0              (GMAC_EMAC_NCFGR_UNIHEN_0_Val << GMAC_EMAC_NCFGR_UNIHEN_Pos) /* (GMAC_EMAC_NCFGR) Rejects unicast frames. Position  */
#define GMAC_EMAC_NCFGR_UNIHEN_1              (GMAC_EMAC_NCFGR_UNIHEN_1_Val << GMAC_EMAC_NCFGR_UNIHEN_Pos) /* (GMAC_EMAC_NCFGR) Accepts unicast frames when the 6-bit hash function of the destination address points to a bit that is set in the Hash Register. Position  */
#define GMAC_EMAC_NCFGR_MAXFS_Pos             _UINT32_(8)                                          /* (GMAC_EMAC_NCFGR) 1536 Maximum Frame Size Position */
#define GMAC_EMAC_NCFGR_MAXFS_Msk             (_UINT32_(0x1) << GMAC_EMAC_NCFGR_MAXFS_Pos)         /* (GMAC_EMAC_NCFGR) 1536 Maximum Frame Size Mask */
#define GMAC_EMAC_NCFGR_MAXFS(value)          (GMAC_EMAC_NCFGR_MAXFS_Msk & (_UINT32_(value) << GMAC_EMAC_NCFGR_MAXFS_Pos)) /* Assigment of value for MAXFS in the GMAC_EMAC_NCFGR register */
#define   GMAC_EMAC_NCFGR_MAXFS_0_Val         _UINT32_(0x0)                                        /* (GMAC_EMAC_NCFGR) Rejects frame sizes above 1518 bytes.  */
#define   GMAC_EMAC_NCFGR_MAXFS_1_Val         _UINT32_(0x1)                                        /* (GMAC_EMAC_NCFGR) Accepts frames up to 1536 bytes in length. Normally the GMAC would reject any frame above 1518 bytes.  */
#define GMAC_EMAC_NCFGR_MAXFS_0               (GMAC_EMAC_NCFGR_MAXFS_0_Val << GMAC_EMAC_NCFGR_MAXFS_Pos) /* (GMAC_EMAC_NCFGR) Rejects frame sizes above 1518 bytes. Position  */
#define GMAC_EMAC_NCFGR_MAXFS_1               (GMAC_EMAC_NCFGR_MAXFS_1_Val << GMAC_EMAC_NCFGR_MAXFS_Pos) /* (GMAC_EMAC_NCFGR) Accepts frames up to 1536 bytes in length. Normally the GMAC would reject any frame above 1518 bytes. Position  */
#define GMAC_EMAC_NCFGR_GBE_Pos               _UINT32_(10)                                         /* (GMAC_EMAC_NCFGR) Gigabit Mode Enable Position */
#define GMAC_EMAC_NCFGR_GBE_Msk               (_UINT32_(0x1) << GMAC_EMAC_NCFGR_GBE_Pos)           /* (GMAC_EMAC_NCFGR) Gigabit Mode Enable Mask */
#define GMAC_EMAC_NCFGR_GBE(value)            (GMAC_EMAC_NCFGR_GBE_Msk & (_UINT32_(value) << GMAC_EMAC_NCFGR_GBE_Pos)) /* Assigment of value for GBE in the GMAC_EMAC_NCFGR register */
#define   GMAC_EMAC_NCFGR_GBE_0_Val           _UINT32_(0x0)                                        /* (GMAC_EMAC_NCFGR) Operates in 10/100Mbps mode.  */
#define   GMAC_EMAC_NCFGR_GBE_1_Val           _UINT32_(0x1)                                        /* (GMAC_EMAC_NCFGR) Operates in Gigabit mode.  */
#define GMAC_EMAC_NCFGR_GBE_0                 (GMAC_EMAC_NCFGR_GBE_0_Val << GMAC_EMAC_NCFGR_GBE_Pos) /* (GMAC_EMAC_NCFGR) Operates in 10/100Mbps mode. Position  */
#define GMAC_EMAC_NCFGR_GBE_1                 (GMAC_EMAC_NCFGR_GBE_1_Val << GMAC_EMAC_NCFGR_GBE_Pos) /* (GMAC_EMAC_NCFGR) Operates in Gigabit mode. Position  */
#define GMAC_EMAC_NCFGR_RTY_Pos               _UINT32_(12)                                         /* (GMAC_EMAC_NCFGR) Retry Test0 Position */
#define GMAC_EMAC_NCFGR_RTY_Msk               (_UINT32_(0x1) << GMAC_EMAC_NCFGR_RTY_Pos)           /* (GMAC_EMAC_NCFGR) Retry Test0 Mask */
#define GMAC_EMAC_NCFGR_RTY(value)            (GMAC_EMAC_NCFGR_RTY_Msk & (_UINT32_(value) << GMAC_EMAC_NCFGR_RTY_Pos)) /* Assigment of value for RTY in the GMAC_EMAC_NCFGR register */
#define   GMAC_EMAC_NCFGR_RTY_0_Val           _UINT32_(0x0)                                        /* (GMAC_EMAC_NCFGR) Normal operation.  */
#define   GMAC_EMAC_NCFGR_RTY_1_Val           _UINT32_(0x1)                                        /* (GMAC_EMAC_NCFGR) The backoff between collisions will always be one slot time and helps test the too many retries condition. Also used in the pause frame tests to reduce the pause counter's decrement time from 512 bit times, to every GRXCK cycle.  */
#define GMAC_EMAC_NCFGR_RTY_0                 (GMAC_EMAC_NCFGR_RTY_0_Val << GMAC_EMAC_NCFGR_RTY_Pos) /* (GMAC_EMAC_NCFGR) Normal operation. Position  */
#define GMAC_EMAC_NCFGR_RTY_1                 (GMAC_EMAC_NCFGR_RTY_1_Val << GMAC_EMAC_NCFGR_RTY_Pos) /* (GMAC_EMAC_NCFGR) The backoff between collisions will always be one slot time and helps test the too many retries condition. Also used in the pause frame tests to reduce the pause counter's decrement time from 512 bit times, to every GRXCK cycle. Position  */
#define GMAC_EMAC_NCFGR_PEN_Pos               _UINT32_(13)                                         /* (GMAC_EMAC_NCFGR) Pause Enable Position */
#define GMAC_EMAC_NCFGR_PEN_Msk               (_UINT32_(0x1) << GMAC_EMAC_NCFGR_PEN_Pos)           /* (GMAC_EMAC_NCFGR) Pause Enable Mask */
#define GMAC_EMAC_NCFGR_PEN(value)            (GMAC_EMAC_NCFGR_PEN_Msk & (_UINT32_(value) << GMAC_EMAC_NCFGR_PEN_Pos)) /* Assigment of value for PEN in the GMAC_EMAC_NCFGR register */
#define   GMAC_EMAC_NCFGR_PEN_0_Val           _UINT32_(0x0)                                        /* (GMAC_EMAC_NCFGR) Does not pause the transmission when a non-zero 802.3 classic pause frame is received.  */
#define   GMAC_EMAC_NCFGR_PEN_1_Val           _UINT32_(0x1)                                        /* (GMAC_EMAC_NCFGR) Pauses transmission when a non-zero 802.3 classic pause frame is received and PFC has not been negotiated.  */
#define GMAC_EMAC_NCFGR_PEN_0                 (GMAC_EMAC_NCFGR_PEN_0_Val << GMAC_EMAC_NCFGR_PEN_Pos) /* (GMAC_EMAC_NCFGR) Does not pause the transmission when a non-zero 802.3 classic pause frame is received. Position  */
#define GMAC_EMAC_NCFGR_PEN_1                 (GMAC_EMAC_NCFGR_PEN_1_Val << GMAC_EMAC_NCFGR_PEN_Pos) /* (GMAC_EMAC_NCFGR) Pauses transmission when a non-zero 802.3 classic pause frame is received and PFC has not been negotiated. Position  */
#define GMAC_EMAC_NCFGR_RXBUFO_Pos            _UINT32_(14)                                         /* (GMAC_EMAC_NCFGR) Receive Buffer Offset Position */
#define GMAC_EMAC_NCFGR_RXBUFO_Msk            (_UINT32_(0x3) << GMAC_EMAC_NCFGR_RXBUFO_Pos)        /* (GMAC_EMAC_NCFGR) Receive Buffer Offset Mask */
#define GMAC_EMAC_NCFGR_RXBUFO(value)         (GMAC_EMAC_NCFGR_RXBUFO_Msk & (_UINT32_(value) << GMAC_EMAC_NCFGR_RXBUFO_Pos)) /* Assigment of value for RXBUFO in the GMAC_EMAC_NCFGR register */
#define GMAC_EMAC_NCFGR_LFERD_Pos             _UINT32_(16)                                         /* (GMAC_EMAC_NCFGR) Length Field Error Frame Discard Position */
#define GMAC_EMAC_NCFGR_LFERD_Msk             (_UINT32_(0x1) << GMAC_EMAC_NCFGR_LFERD_Pos)         /* (GMAC_EMAC_NCFGR) Length Field Error Frame Discard Mask */
#define GMAC_EMAC_NCFGR_LFERD(value)          (GMAC_EMAC_NCFGR_LFERD_Msk & (_UINT32_(value) << GMAC_EMAC_NCFGR_LFERD_Pos)) /* Assigment of value for LFERD in the GMAC_EMAC_NCFGR register */
#define   GMAC_EMAC_NCFGR_LFERD_0_Val         _UINT32_(0x0)                                        /* (GMAC_EMAC_NCFGR) Accepts frames with a measured length shorter than the extracted length field  */
#define   GMAC_EMAC_NCFGR_LFERD_1_Val         _UINT32_(0x1)                                        /* (GMAC_EMAC_NCFGR) Discards frames with a measured length shorter than the extracted length field (as indicated by bytes 13 and 14 in a non-VLAN tagged frame). This only applies to frames with a length field less than 0x0600.  */
#define GMAC_EMAC_NCFGR_LFERD_0               (GMAC_EMAC_NCFGR_LFERD_0_Val << GMAC_EMAC_NCFGR_LFERD_Pos) /* (GMAC_EMAC_NCFGR) Accepts frames with a measured length shorter than the extracted length field Position  */
#define GMAC_EMAC_NCFGR_LFERD_1               (GMAC_EMAC_NCFGR_LFERD_1_Val << GMAC_EMAC_NCFGR_LFERD_Pos) /* (GMAC_EMAC_NCFGR) Discards frames with a measured length shorter than the extracted length field (as indicated by bytes 13 and 14 in a non-VLAN tagged frame). This only applies to frames with a length field less than 0x0600. Position  */
#define GMAC_EMAC_NCFGR_RFCS_Pos              _UINT32_(17)                                         /* (GMAC_EMAC_NCFGR) Remove FCS Position */
#define GMAC_EMAC_NCFGR_RFCS_Msk              (_UINT32_(0x1) << GMAC_EMAC_NCFGR_RFCS_Pos)          /* (GMAC_EMAC_NCFGR) Remove FCS Mask */
#define GMAC_EMAC_NCFGR_RFCS(value)           (GMAC_EMAC_NCFGR_RFCS_Msk & (_UINT32_(value) << GMAC_EMAC_NCFGR_RFCS_Pos)) /* Assigment of value for RFCS in the GMAC_EMAC_NCFGR register */
#define   GMAC_EMAC_NCFGR_RFCS_0_Val          _UINT32_(0x0)                                        /* (GMAC_EMAC_NCFGR) Includes the received frame check sequence (last 4 bytes) when writing to memory.  */
#define   GMAC_EMAC_NCFGR_RFCS_1_Val          _UINT32_(0x1)                                        /* (GMAC_EMAC_NCFGR) Excludes the received frame check sequence (last 4 bytes) when writing to memory. The frame length indicated will be reduced by four bytes in this mode.  */
#define GMAC_EMAC_NCFGR_RFCS_0                (GMAC_EMAC_NCFGR_RFCS_0_Val << GMAC_EMAC_NCFGR_RFCS_Pos) /* (GMAC_EMAC_NCFGR) Includes the received frame check sequence (last 4 bytes) when writing to memory. Position  */
#define GMAC_EMAC_NCFGR_RFCS_1                (GMAC_EMAC_NCFGR_RFCS_1_Val << GMAC_EMAC_NCFGR_RFCS_Pos) /* (GMAC_EMAC_NCFGR) Excludes the received frame check sequence (last 4 bytes) when writing to memory. The frame length indicated will be reduced by four bytes in this mode. Position  */
#define GMAC_EMAC_NCFGR_CLK_Pos               _UINT32_(18)                                         /* (GMAC_EMAC_NCFGR) MDC Clock Division Position */
#define GMAC_EMAC_NCFGR_CLK_Msk               (_UINT32_(0x7) << GMAC_EMAC_NCFGR_CLK_Pos)           /* (GMAC_EMAC_NCFGR) MDC Clock Division Mask */
#define GMAC_EMAC_NCFGR_CLK(value)            (GMAC_EMAC_NCFGR_CLK_Msk & (_UINT32_(value) << GMAC_EMAC_NCFGR_CLK_Pos)) /* Assigment of value for CLK in the GMAC_EMAC_NCFGR register */
#define   GMAC_EMAC_NCFGR_CLK_MCK_8_Val       _UINT32_(0x0)                                        /* (GMAC_EMAC_NCFGR) MCK divided by 8 (MCK up to 20 MHz)  */
#define   GMAC_EMAC_NCFGR_CLK_MCK_16_Val      _UINT32_(0x1)                                        /* (GMAC_EMAC_NCFGR) MCK divided by 16 (MCK up to 40 MHz)  */
#define   GMAC_EMAC_NCFGR_CLK_MCK_32_Val      _UINT32_(0x2)                                        /* (GMAC_EMAC_NCFGR) MCK divided by 32 (MCK up to 80 MHz)  */
#define   GMAC_EMAC_NCFGR_CLK_MCK_48_Val      _UINT32_(0x3)                                        /* (GMAC_EMAC_NCFGR) MCK divided by 48 (MCK up to 120 MHz)  */
#define   GMAC_EMAC_NCFGR_CLK_MCK_64_Val      _UINT32_(0x4)                                        /* (GMAC_EMAC_NCFGR) MCK divided by 64 (MCK up to 160 MHz)  */
#define   GMAC_EMAC_NCFGR_CLK_MCK_96_Val      _UINT32_(0x5)                                        /* (GMAC_EMAC_NCFGR) MCK divided by 96 (MCK up to 240 MHz)  */
#define GMAC_EMAC_NCFGR_CLK_MCK_8             (GMAC_EMAC_NCFGR_CLK_MCK_8_Val << GMAC_EMAC_NCFGR_CLK_Pos) /* (GMAC_EMAC_NCFGR) MCK divided by 8 (MCK up to 20 MHz) Position  */
#define GMAC_EMAC_NCFGR_CLK_MCK_16            (GMAC_EMAC_NCFGR_CLK_MCK_16_Val << GMAC_EMAC_NCFGR_CLK_Pos) /* (GMAC_EMAC_NCFGR) MCK divided by 16 (MCK up to 40 MHz) Position  */
#define GMAC_EMAC_NCFGR_CLK_MCK_32            (GMAC_EMAC_NCFGR_CLK_MCK_32_Val << GMAC_EMAC_NCFGR_CLK_Pos) /* (GMAC_EMAC_NCFGR) MCK divided by 32 (MCK up to 80 MHz) Position  */
#define GMAC_EMAC_NCFGR_CLK_MCK_48            (GMAC_EMAC_NCFGR_CLK_MCK_48_Val << GMAC_EMAC_NCFGR_CLK_Pos) /* (GMAC_EMAC_NCFGR) MCK divided by 48 (MCK up to 120 MHz) Position  */
#define GMAC_EMAC_NCFGR_CLK_MCK_64            (GMAC_EMAC_NCFGR_CLK_MCK_64_Val << GMAC_EMAC_NCFGR_CLK_Pos) /* (GMAC_EMAC_NCFGR) MCK divided by 64 (MCK up to 160 MHz) Position  */
#define GMAC_EMAC_NCFGR_CLK_MCK_96            (GMAC_EMAC_NCFGR_CLK_MCK_96_Val << GMAC_EMAC_NCFGR_CLK_Pos) /* (GMAC_EMAC_NCFGR) MCK divided by 96 (MCK up to 240 MHz) Position  */
#define GMAC_EMAC_NCFGR_DBW_Pos               _UINT32_(21)                                         /* (GMAC_EMAC_NCFGR) Always Written to 0 Position */
#define GMAC_EMAC_NCFGR_DBW_Msk               (_UINT32_(0x3) << GMAC_EMAC_NCFGR_DBW_Pos)           /* (GMAC_EMAC_NCFGR) Always Written to 0 Mask */
#define GMAC_EMAC_NCFGR_DBW(value)            (GMAC_EMAC_NCFGR_DBW_Msk & (_UINT32_(value) << GMAC_EMAC_NCFGR_DBW_Pos)) /* Assigment of value for DBW in the GMAC_EMAC_NCFGR register */
#define GMAC_EMAC_NCFGR_DCPF_Pos              _UINT32_(23)                                         /* (GMAC_EMAC_NCFGR) Disable Copy of Pause Frames Position */
#define GMAC_EMAC_NCFGR_DCPF_Msk              (_UINT32_(0x1) << GMAC_EMAC_NCFGR_DCPF_Pos)          /* (GMAC_EMAC_NCFGR) Disable Copy of Pause Frames Mask */
#define GMAC_EMAC_NCFGR_DCPF(value)           (GMAC_EMAC_NCFGR_DCPF_Msk & (_UINT32_(value) << GMAC_EMAC_NCFGR_DCPF_Pos)) /* Assigment of value for DCPF in the GMAC_EMAC_NCFGR register */
#define   GMAC_EMAC_NCFGR_DCPF_0_Val          _UINT32_(0x0)                                        /* (GMAC_EMAC_NCFGR) Copies pause frames to the system memory.  */
#define   GMAC_EMAC_NCFGR_DCPF_1_Val          _UINT32_(0x1)                                        /* (GMAC_EMAC_NCFGR) Prevents valid pause frames being copied to memory. Pause frames are not copied to memory regardless of the state of the Copy All Frames bit, whether a hash match is found or whether a type ID match is identified. If a destination address match is found, the pause frame will be copied to memory. Note that valid pause frames received will still increment pause statistics and pause the transmission of frames as required.  */
#define GMAC_EMAC_NCFGR_DCPF_0                (GMAC_EMAC_NCFGR_DCPF_0_Val << GMAC_EMAC_NCFGR_DCPF_Pos) /* (GMAC_EMAC_NCFGR) Copies pause frames to the system memory. Position  */
#define GMAC_EMAC_NCFGR_DCPF_1                (GMAC_EMAC_NCFGR_DCPF_1_Val << GMAC_EMAC_NCFGR_DCPF_Pos) /* (GMAC_EMAC_NCFGR) Prevents valid pause frames being copied to memory. Pause frames are not copied to memory regardless of the state of the Copy All Frames bit, whether a hash match is found or whether a type ID match is identified. If a destination address match is found, the pause frame will be copied to memory. Note that valid pause frames received will still increment pause statistics and pause the transmission of frames as required. Position  */
#define GMAC_EMAC_NCFGR_RXCOEN_Pos            _UINT32_(24)                                         /* (GMAC_EMAC_NCFGR) Receive Checksum Offload Enable Position */
#define GMAC_EMAC_NCFGR_RXCOEN_Msk            (_UINT32_(0x1) << GMAC_EMAC_NCFGR_RXCOEN_Pos)        /* (GMAC_EMAC_NCFGR) Receive Checksum Offload Enable Mask */
#define GMAC_EMAC_NCFGR_RXCOEN(value)         (GMAC_EMAC_NCFGR_RXCOEN_Msk & (_UINT32_(value) << GMAC_EMAC_NCFGR_RXCOEN_Pos)) /* Assigment of value for RXCOEN in the GMAC_EMAC_NCFGR register */
#define   GMAC_EMAC_NCFGR_RXCOEN_0_Val        _UINT32_(0x0)                                        /* (GMAC_EMAC_NCFGR) Disables the receive checksum engine. Frames with bad IP, TCP or UDP checksums are accepted.  */
#define   GMAC_EMAC_NCFGR_RXCOEN_1_Val        _UINT32_(0x1)                                        /* (GMAC_EMAC_NCFGR) Enables the receive checksum engine. Frames with bad IP, TCP or UDP checksums are discarded.  */
#define GMAC_EMAC_NCFGR_RXCOEN_0              (GMAC_EMAC_NCFGR_RXCOEN_0_Val << GMAC_EMAC_NCFGR_RXCOEN_Pos) /* (GMAC_EMAC_NCFGR) Disables the receive checksum engine. Frames with bad IP, TCP or UDP checksums are accepted. Position  */
#define GMAC_EMAC_NCFGR_RXCOEN_1              (GMAC_EMAC_NCFGR_RXCOEN_1_Val << GMAC_EMAC_NCFGR_RXCOEN_Pos) /* (GMAC_EMAC_NCFGR) Enables the receive checksum engine. Frames with bad IP, TCP or UDP checksums are discarded. Position  */
#define GMAC_EMAC_NCFGR_EFRHD_Pos             _UINT32_(25)                                         /* (GMAC_EMAC_NCFGR) Enable Frames Received in Half Duplex Position */
#define GMAC_EMAC_NCFGR_EFRHD_Msk             (_UINT32_(0x1) << GMAC_EMAC_NCFGR_EFRHD_Pos)         /* (GMAC_EMAC_NCFGR) Enable Frames Received in Half Duplex Mask */
#define GMAC_EMAC_NCFGR_EFRHD(value)          (GMAC_EMAC_NCFGR_EFRHD_Msk & (_UINT32_(value) << GMAC_EMAC_NCFGR_EFRHD_Pos)) /* Assigment of value for EFRHD in the GMAC_EMAC_NCFGR register */
#define   GMAC_EMAC_NCFGR_EFRHD_0_Val         _UINT32_(0x0)                                        /* (GMAC_EMAC_NCFGR) Disables frames to be received in Half Duplex mode while transmitting.  */
#define   GMAC_EMAC_NCFGR_EFRHD_1_Val         _UINT32_(0x1)                                        /* (GMAC_EMAC_NCFGR) Enables frames to be received in Half Duplex mode while transmitting.  */
#define GMAC_EMAC_NCFGR_EFRHD_0               (GMAC_EMAC_NCFGR_EFRHD_0_Val << GMAC_EMAC_NCFGR_EFRHD_Pos) /* (GMAC_EMAC_NCFGR) Disables frames to be received in Half Duplex mode while transmitting. Position  */
#define GMAC_EMAC_NCFGR_EFRHD_1               (GMAC_EMAC_NCFGR_EFRHD_1_Val << GMAC_EMAC_NCFGR_EFRHD_Pos) /* (GMAC_EMAC_NCFGR) Enables frames to be received in Half Duplex mode while transmitting. Position  */
#define GMAC_EMAC_NCFGR_IRXFCS_Pos            _UINT32_(26)                                         /* (GMAC_EMAC_NCFGR) Ignore RX FCS Position */
#define GMAC_EMAC_NCFGR_IRXFCS_Msk            (_UINT32_(0x1) << GMAC_EMAC_NCFGR_IRXFCS_Pos)        /* (GMAC_EMAC_NCFGR) Ignore RX FCS Mask */
#define GMAC_EMAC_NCFGR_IRXFCS(value)         (GMAC_EMAC_NCFGR_IRXFCS_Msk & (_UINT32_(value) << GMAC_EMAC_NCFGR_IRXFCS_Pos)) /* Assigment of value for IRXFCS in the GMAC_EMAC_NCFGR register */
#define   GMAC_EMAC_NCFGR_IRXFCS_0_Val        _UINT32_(0x0)                                        /* (GMAC_EMAC_NCFGR) Normal operation, frames with FCS/CRC errors are rejected.  */
#define   GMAC_EMAC_NCFGR_IRXFCS_1_Val        _UINT32_(0x1)                                        /* (GMAC_EMAC_NCFGR) Frames with FCS/CRC errors are rejected. FCS error statistics are still collected for frames with bad FCS and FCS status is recorded in frame's DMA descriptor.  */
#define GMAC_EMAC_NCFGR_IRXFCS_0              (GMAC_EMAC_NCFGR_IRXFCS_0_Val << GMAC_EMAC_NCFGR_IRXFCS_Pos) /* (GMAC_EMAC_NCFGR) Normal operation, frames with FCS/CRC errors are rejected. Position  */
#define GMAC_EMAC_NCFGR_IRXFCS_1              (GMAC_EMAC_NCFGR_IRXFCS_1_Val << GMAC_EMAC_NCFGR_IRXFCS_Pos) /* (GMAC_EMAC_NCFGR) Frames with FCS/CRC errors are rejected. FCS error statistics are still collected for frames with bad FCS and FCS status is recorded in frame's DMA descriptor. Position  */
#define GMAC_EMAC_NCFGR_IPGSEN_Pos            _UINT32_(28)                                         /* (GMAC_EMAC_NCFGR) Inter Packet Gap Stretch Enable Position */
#define GMAC_EMAC_NCFGR_IPGSEN_Msk            (_UINT32_(0x1) << GMAC_EMAC_NCFGR_IPGSEN_Pos)        /* (GMAC_EMAC_NCFGR) Inter Packet Gap Stretch Enable Mask */
#define GMAC_EMAC_NCFGR_IPGSEN(value)         (GMAC_EMAC_NCFGR_IPGSEN_Msk & (_UINT32_(value) << GMAC_EMAC_NCFGR_IPGSEN_Pos)) /* Assigment of value for IPGSEN in the GMAC_EMAC_NCFGR register */
#define   GMAC_EMAC_NCFGR_IPGSEN_0_Val        _UINT32_(0x0)                                        /* (GMAC_EMAC_NCFGR) The transmit IPG cannot be increased.  */
#define   GMAC_EMAC_NCFGR_IPGSEN_1_Val        _UINT32_(0x1)                                        /* (GMAC_EMAC_NCFGR) The transmit IPG can be increased above 96 bit times depending on the previous frame length using the IPG Stretch Register.  */
#define GMAC_EMAC_NCFGR_IPGSEN_0              (GMAC_EMAC_NCFGR_IPGSEN_0_Val << GMAC_EMAC_NCFGR_IPGSEN_Pos) /* (GMAC_EMAC_NCFGR) The transmit IPG cannot be increased. Position  */
#define GMAC_EMAC_NCFGR_IPGSEN_1              (GMAC_EMAC_NCFGR_IPGSEN_1_Val << GMAC_EMAC_NCFGR_IPGSEN_Pos) /* (GMAC_EMAC_NCFGR) The transmit IPG can be increased above 96 bit times depending on the previous frame length using the IPG Stretch Register. Position  */
#define GMAC_EMAC_NCFGR_RXBP_Pos              _UINT32_(29)                                         /* (GMAC_EMAC_NCFGR) Receive Bad Preamble Position */
#define GMAC_EMAC_NCFGR_RXBP_Msk              (_UINT32_(0x1) << GMAC_EMAC_NCFGR_RXBP_Pos)          /* (GMAC_EMAC_NCFGR) Receive Bad Preamble Mask */
#define GMAC_EMAC_NCFGR_RXBP(value)           (GMAC_EMAC_NCFGR_RXBP_Msk & (_UINT32_(value) << GMAC_EMAC_NCFGR_RXBP_Pos)) /* Assigment of value for RXBP in the GMAC_EMAC_NCFGR register */
#define   GMAC_EMAC_NCFGR_RXBP_0_Val          _UINT32_(0x0)                                        /* (GMAC_EMAC_NCFGR) Rejects frames with non-standard preamble.  */
#define   GMAC_EMAC_NCFGR_RXBP_1_Val          _UINT32_(0x1)                                        /* (GMAC_EMAC_NCFGR) Accepts frames with non-standard preamble.  */
#define GMAC_EMAC_NCFGR_RXBP_0                (GMAC_EMAC_NCFGR_RXBP_0_Val << GMAC_EMAC_NCFGR_RXBP_Pos) /* (GMAC_EMAC_NCFGR) Rejects frames with non-standard preamble. Position  */
#define GMAC_EMAC_NCFGR_RXBP_1                (GMAC_EMAC_NCFGR_RXBP_1_Val << GMAC_EMAC_NCFGR_RXBP_Pos) /* (GMAC_EMAC_NCFGR) Accepts frames with non-standard preamble. Position  */
#define GMAC_EMAC_NCFGR_IRXER_Pos             _UINT32_(30)                                         /* (GMAC_EMAC_NCFGR) Ignore Receive Error from PHY Position */
#define GMAC_EMAC_NCFGR_IRXER_Msk             (_UINT32_(0x1) << GMAC_EMAC_NCFGR_IRXER_Pos)         /* (GMAC_EMAC_NCFGR) Ignore Receive Error from PHY Mask */
#define GMAC_EMAC_NCFGR_IRXER(value)          (GMAC_EMAC_NCFGR_IRXER_Msk & (_UINT32_(value) << GMAC_EMAC_NCFGR_IRXER_Pos)) /* Assigment of value for IRXER in the GMAC_EMAC_NCFGR register */
#define   GMAC_EMAC_NCFGR_IRXER_0_Val         _UINT32_(0x0)                                        /* (GMAC_EMAC_NCFGR)   */
#define   GMAC_EMAC_NCFGR_IRXER_1_Val         _UINT32_(0x1)                                        /* (GMAC_EMAC_NCFGR) GRXER has no effect on the GMAC's operation when GRXDV is low. Set this bit when using the RGMII wrapper in Half Duplex mode.  */
#define GMAC_EMAC_NCFGR_IRXER_0               (GMAC_EMAC_NCFGR_IRXER_0_Val << GMAC_EMAC_NCFGR_IRXER_Pos) /* (GMAC_EMAC_NCFGR)  Position  */
#define GMAC_EMAC_NCFGR_IRXER_1               (GMAC_EMAC_NCFGR_IRXER_1_Val << GMAC_EMAC_NCFGR_IRXER_Pos) /* (GMAC_EMAC_NCFGR) GRXER has no effect on the GMAC's operation when GRXDV is low. Set this bit when using the RGMII wrapper in Half Duplex mode. Position  */
#define GMAC_EMAC_NCFGR_Msk                   _UINT32_(0x77FFF5FF)                                 /* (GMAC_EMAC_NCFGR) Register Mask  */


/* -------- GMAC_EMAC_NSR : (GMAC Offset: 0x1008) ( R/ 32) Express MAC Network Status Register -------- */
#define GMAC_EMAC_NSR_MDIO_Pos                _UINT32_(1)                                          /* (GMAC_EMAC_NSR) MDIO Input Status Position */
#define GMAC_EMAC_NSR_MDIO_Msk                (_UINT32_(0x1) << GMAC_EMAC_NSR_MDIO_Pos)            /* (GMAC_EMAC_NSR) MDIO Input Status Mask */
#define GMAC_EMAC_NSR_MDIO(value)             (GMAC_EMAC_NSR_MDIO_Msk & (_UINT32_(value) << GMAC_EMAC_NSR_MDIO_Pos)) /* Assigment of value for MDIO in the GMAC_EMAC_NSR register */
#define GMAC_EMAC_NSR_IDLE_Pos                _UINT32_(2)                                          /* (GMAC_EMAC_NSR) PHY Management Logic Idle Position */
#define GMAC_EMAC_NSR_IDLE_Msk                (_UINT32_(0x1) << GMAC_EMAC_NSR_IDLE_Pos)            /* (GMAC_EMAC_NSR) PHY Management Logic Idle Mask */
#define GMAC_EMAC_NSR_IDLE(value)             (GMAC_EMAC_NSR_IDLE_Msk & (_UINT32_(value) << GMAC_EMAC_NSR_IDLE_Pos)) /* Assigment of value for IDLE in the GMAC_EMAC_NSR register */
#define GMAC_EMAC_NSR_PFCPAUSN_Pos            _UINT32_(6)                                          /* (GMAC_EMAC_NSR) PFC Pause Negotiated Position */
#define GMAC_EMAC_NSR_PFCPAUSN_Msk            (_UINT32_(0x1) << GMAC_EMAC_NSR_PFCPAUSN_Pos)        /* (GMAC_EMAC_NSR) PFC Pause Negotiated Mask */
#define GMAC_EMAC_NSR_PFCPAUSN(value)         (GMAC_EMAC_NSR_PFCPAUSN_Msk & (_UINT32_(value) << GMAC_EMAC_NSR_PFCPAUSN_Pos)) /* Assigment of value for PFCPAUSN in the GMAC_EMAC_NSR register */
#define GMAC_EMAC_NSR_RXLPIS_Pos              _UINT32_(7)                                          /* (GMAC_EMAC_NSR) LPI Indication Position */
#define GMAC_EMAC_NSR_RXLPIS_Msk              (_UINT32_(0x1) << GMAC_EMAC_NSR_RXLPIS_Pos)          /* (GMAC_EMAC_NSR) LPI Indication Mask */
#define GMAC_EMAC_NSR_RXLPIS(value)           (GMAC_EMAC_NSR_RXLPIS_Msk & (_UINT32_(value) << GMAC_EMAC_NSR_RXLPIS_Pos)) /* Assigment of value for RXLPIS in the GMAC_EMAC_NSR register */
#define GMAC_EMAC_NSR_Msk                     _UINT32_(0x000000C6)                                 /* (GMAC_EMAC_NSR) Register Mask  */


/* -------- GMAC_EMAC_DCFGR : (GMAC Offset: 0x1010) (R/W 32) Express MAC DMA Configuration Register -------- */
#define GMAC_EMAC_DCFGR_RESETVALUE            _UINT32_(0x20004)                                    /*  (GMAC_EMAC_DCFGR) Express MAC DMA Configuration Register  Reset Value */

#define GMAC_EMAC_DCFGR_FBLDO_Pos             _UINT32_(0)                                          /* (GMAC_EMAC_DCFGR) Fixed Burst Length for DMA Data Operations: Position */
#define GMAC_EMAC_DCFGR_FBLDO_Msk             (_UINT32_(0x1F) << GMAC_EMAC_DCFGR_FBLDO_Pos)        /* (GMAC_EMAC_DCFGR) Fixed Burst Length for DMA Data Operations: Mask */
#define GMAC_EMAC_DCFGR_FBLDO(value)          (GMAC_EMAC_DCFGR_FBLDO_Msk & (_UINT32_(value) << GMAC_EMAC_DCFGR_FBLDO_Pos)) /* Assigment of value for FBLDO in the GMAC_EMAC_DCFGR register */
#define   GMAC_EMAC_DCFGR_FBLDO_SINGLE_Val    _UINT32_(0x1)                                        /* (GMAC_EMAC_DCFGR) Always use single access on system bus  */
#define   GMAC_EMAC_DCFGR_FBLDO_INCR4_Val     _UINT32_(0x4)                                        /* (GMAC_EMAC_DCFGR) Attempt to use 4-beat bursts on system bus (Default)  */
#define   GMAC_EMAC_DCFGR_FBLDO_INCR8_Val     _UINT32_(0x8)                                        /* (GMAC_EMAC_DCFGR) Attempt to use 8-beat bursts on system bus bursts  */
#define   GMAC_EMAC_DCFGR_FBLDO_INCR16_Val    _UINT32_(0x10)                                       /* (GMAC_EMAC_DCFGR) Attempt to use 16-beat bursts on system bus bursts  */
#define GMAC_EMAC_DCFGR_FBLDO_SINGLE          (GMAC_EMAC_DCFGR_FBLDO_SINGLE_Val << GMAC_EMAC_DCFGR_FBLDO_Pos) /* (GMAC_EMAC_DCFGR) Always use single access on system bus Position  */
#define GMAC_EMAC_DCFGR_FBLDO_INCR4           (GMAC_EMAC_DCFGR_FBLDO_INCR4_Val << GMAC_EMAC_DCFGR_FBLDO_Pos) /* (GMAC_EMAC_DCFGR) Attempt to use 4-beat bursts on system bus (Default) Position  */
#define GMAC_EMAC_DCFGR_FBLDO_INCR8           (GMAC_EMAC_DCFGR_FBLDO_INCR8_Val << GMAC_EMAC_DCFGR_FBLDO_Pos) /* (GMAC_EMAC_DCFGR) Attempt to use 8-beat bursts on system bus bursts Position  */
#define GMAC_EMAC_DCFGR_FBLDO_INCR16          (GMAC_EMAC_DCFGR_FBLDO_INCR16_Val << GMAC_EMAC_DCFGR_FBLDO_Pos) /* (GMAC_EMAC_DCFGR) Attempt to use 16-beat bursts on system bus bursts Position  */
#define GMAC_EMAC_DCFGR_ESMA_Pos              _UINT32_(6)                                          /* (GMAC_EMAC_DCFGR) Endian Swap Mode Enable for Management Descriptor Accesses Position */
#define GMAC_EMAC_DCFGR_ESMA_Msk              (_UINT32_(0x1) << GMAC_EMAC_DCFGR_ESMA_Pos)          /* (GMAC_EMAC_DCFGR) Endian Swap Mode Enable for Management Descriptor Accesses Mask */
#define GMAC_EMAC_DCFGR_ESMA(value)           (GMAC_EMAC_DCFGR_ESMA_Msk & (_UINT32_(value) << GMAC_EMAC_DCFGR_ESMA_Pos)) /* Assigment of value for ESMA in the GMAC_EMAC_DCFGR register */
#define   GMAC_EMAC_DCFGR_ESMA_LITTLE_ENDIAN_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_DCFGR) Selects Little-endian endianism for system bus transfers.  */
#define   GMAC_EMAC_DCFGR_ESMA_BIG_ENDIAN_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_DCFGR) Selects swapped endianism for system bus transfers.  */
#define GMAC_EMAC_DCFGR_ESMA_LITTLE_ENDIAN    (GMAC_EMAC_DCFGR_ESMA_LITTLE_ENDIAN_Val << GMAC_EMAC_DCFGR_ESMA_Pos) /* (GMAC_EMAC_DCFGR) Selects Little-endian endianism for system bus transfers. Position  */
#define GMAC_EMAC_DCFGR_ESMA_BIG_ENDIAN       (GMAC_EMAC_DCFGR_ESMA_BIG_ENDIAN_Val << GMAC_EMAC_DCFGR_ESMA_Pos) /* (GMAC_EMAC_DCFGR) Selects swapped endianism for system bus transfers. Position  */
#define GMAC_EMAC_DCFGR_ESPA_Pos              _UINT32_(7)                                          /* (GMAC_EMAC_DCFGR) Endian Swap Mode Enable for Packet Data Accesses Position */
#define GMAC_EMAC_DCFGR_ESPA_Msk              (_UINT32_(0x1) << GMAC_EMAC_DCFGR_ESPA_Pos)          /* (GMAC_EMAC_DCFGR) Endian Swap Mode Enable for Packet Data Accesses Mask */
#define GMAC_EMAC_DCFGR_ESPA(value)           (GMAC_EMAC_DCFGR_ESPA_Msk & (_UINT32_(value) << GMAC_EMAC_DCFGR_ESPA_Pos)) /* Assigment of value for ESPA in the GMAC_EMAC_DCFGR register */
#define   GMAC_EMAC_DCFGR_ESPA_LITTLE_ENDIAN_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_DCFGR) Selects Little-endian endianism for system bus transfers.  */
#define   GMAC_EMAC_DCFGR_ESPA_BIG_ENDIAN_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_DCFGR) Selects swapped endianism for system bus transfers.  */
#define GMAC_EMAC_DCFGR_ESPA_LITTLE_ENDIAN    (GMAC_EMAC_DCFGR_ESPA_LITTLE_ENDIAN_Val << GMAC_EMAC_DCFGR_ESPA_Pos) /* (GMAC_EMAC_DCFGR) Selects Little-endian endianism for system bus transfers. Position  */
#define GMAC_EMAC_DCFGR_ESPA_BIG_ENDIAN       (GMAC_EMAC_DCFGR_ESPA_BIG_ENDIAN_Val << GMAC_EMAC_DCFGR_ESPA_Pos) /* (GMAC_EMAC_DCFGR) Selects swapped endianism for system bus transfers. Position  */
#define GMAC_EMAC_DCFGR_RXBMS_Pos             _UINT32_(8)                                          /* (GMAC_EMAC_DCFGR) Receiver Packet Buffer Memory Size Select Position */
#define GMAC_EMAC_DCFGR_RXBMS_Msk             (_UINT32_(0x3) << GMAC_EMAC_DCFGR_RXBMS_Pos)         /* (GMAC_EMAC_DCFGR) Receiver Packet Buffer Memory Size Select Mask */
#define GMAC_EMAC_DCFGR_RXBMS(value)          (GMAC_EMAC_DCFGR_RXBMS_Msk & (_UINT32_(value) << GMAC_EMAC_DCFGR_RXBMS_Pos)) /* Assigment of value for RXBMS in the GMAC_EMAC_DCFGR register */
#define   GMAC_EMAC_DCFGR_RXBMS_EIGHTH_Val    _UINT32_(0x0)                                        /* (GMAC_EMAC_DCFGR) 4/8 Kbyte Memory Size  */
#define   GMAC_EMAC_DCFGR_RXBMS_QUARTER_Val   _UINT32_(0x1)                                        /* (GMAC_EMAC_DCFGR) 4/4 Kbytes Memory Size  */
#define   GMAC_EMAC_DCFGR_RXBMS_HALF_Val      _UINT32_(0x2)                                        /* (GMAC_EMAC_DCFGR) 4/2 Kbytes Memory Size  */
#define   GMAC_EMAC_DCFGR_RXBMS_FULL_Val      _UINT32_(0x3)                                        /* (GMAC_EMAC_DCFGR) 4 Kbytes Memory Size  */
#define GMAC_EMAC_DCFGR_RXBMS_EIGHTH          (GMAC_EMAC_DCFGR_RXBMS_EIGHTH_Val << GMAC_EMAC_DCFGR_RXBMS_Pos) /* (GMAC_EMAC_DCFGR) 4/8 Kbyte Memory Size Position  */
#define GMAC_EMAC_DCFGR_RXBMS_QUARTER         (GMAC_EMAC_DCFGR_RXBMS_QUARTER_Val << GMAC_EMAC_DCFGR_RXBMS_Pos) /* (GMAC_EMAC_DCFGR) 4/4 Kbytes Memory Size Position  */
#define GMAC_EMAC_DCFGR_RXBMS_HALF            (GMAC_EMAC_DCFGR_RXBMS_HALF_Val << GMAC_EMAC_DCFGR_RXBMS_Pos) /* (GMAC_EMAC_DCFGR) 4/2 Kbytes Memory Size Position  */
#define GMAC_EMAC_DCFGR_RXBMS_FULL            (GMAC_EMAC_DCFGR_RXBMS_FULL_Val << GMAC_EMAC_DCFGR_RXBMS_Pos) /* (GMAC_EMAC_DCFGR) 4 Kbytes Memory Size Position  */
#define GMAC_EMAC_DCFGR_TXPBMS_Pos            _UINT32_(10)                                         /* (GMAC_EMAC_DCFGR) Transmitter Packet Buffer Memory Size Select Position */
#define GMAC_EMAC_DCFGR_TXPBMS_Msk            (_UINT32_(0x1) << GMAC_EMAC_DCFGR_TXPBMS_Pos)        /* (GMAC_EMAC_DCFGR) Transmitter Packet Buffer Memory Size Select Mask */
#define GMAC_EMAC_DCFGR_TXPBMS(value)         (GMAC_EMAC_DCFGR_TXPBMS_Msk & (_UINT32_(value) << GMAC_EMAC_DCFGR_TXPBMS_Pos)) /* Assigment of value for TXPBMS in the GMAC_EMAC_DCFGR register */
#define   GMAC_EMAC_DCFGR_TXPBMS_TWO_KB_Val   _UINT32_(0x0)                                        /* (GMAC_EMAC_DCFGR) Do not use top address bit (2 Kbytes).  */
#define   GMAC_EMAC_DCFGR_TXPBMS_FOUR_KB_Val  _UINT32_(0x1)                                        /* (GMAC_EMAC_DCFGR) Use full configured addressable space (4 Kbytes).  */
#define GMAC_EMAC_DCFGR_TXPBMS_TWO_KB         (GMAC_EMAC_DCFGR_TXPBMS_TWO_KB_Val << GMAC_EMAC_DCFGR_TXPBMS_Pos) /* (GMAC_EMAC_DCFGR) Do not use top address bit (2 Kbytes). Position  */
#define GMAC_EMAC_DCFGR_TXPBMS_FOUR_KB        (GMAC_EMAC_DCFGR_TXPBMS_FOUR_KB_Val << GMAC_EMAC_DCFGR_TXPBMS_Pos) /* (GMAC_EMAC_DCFGR) Use full configured addressable space (4 Kbytes). Position  */
#define GMAC_EMAC_DCFGR_TXCOEN_Pos            _UINT32_(11)                                         /* (GMAC_EMAC_DCFGR) Transmitter Checksum Generation Offload Enable Position */
#define GMAC_EMAC_DCFGR_TXCOEN_Msk            (_UINT32_(0x1) << GMAC_EMAC_DCFGR_TXCOEN_Pos)        /* (GMAC_EMAC_DCFGR) Transmitter Checksum Generation Offload Enable Mask */
#define GMAC_EMAC_DCFGR_TXCOEN(value)         (GMAC_EMAC_DCFGR_TXCOEN_Msk & (_UINT32_(value) << GMAC_EMAC_DCFGR_TXCOEN_Pos)) /* Assigment of value for TXCOEN in the GMAC_EMAC_DCFGR register */
#define GMAC_EMAC_DCFGR_INFLASTEN_Pos         _UINT32_(12)                                         /* (GMAC_EMAC_DCFGR) Infinite Size for Last Buffer Enable Position */
#define GMAC_EMAC_DCFGR_INFLASTEN_Msk         (_UINT32_(0x1) << GMAC_EMAC_DCFGR_INFLASTEN_Pos)     /* (GMAC_EMAC_DCFGR) Infinite Size for Last Buffer Enable Mask */
#define GMAC_EMAC_DCFGR_INFLASTEN(value)      (GMAC_EMAC_DCFGR_INFLASTEN_Msk & (_UINT32_(value) << GMAC_EMAC_DCFGR_INFLASTEN_Pos)) /* Assigment of value for INFLASTEN in the GMAC_EMAC_DCFGR register */
#define GMAC_EMAC_DCFGR_CRCERRREP_Pos         _UINT32_(13)                                         /* (GMAC_EMAC_DCFGR) CRC Errors Report Position */
#define GMAC_EMAC_DCFGR_CRCERRREP_Msk         (_UINT32_(0x1) << GMAC_EMAC_DCFGR_CRCERRREP_Pos)     /* (GMAC_EMAC_DCFGR) CRC Errors Report Mask */
#define GMAC_EMAC_DCFGR_CRCERRREP(value)      (GMAC_EMAC_DCFGR_CRCERRREP_Msk & (_UINT32_(value) << GMAC_EMAC_DCFGR_CRCERRREP_Pos)) /* Assigment of value for CRCERRREP in the GMAC_EMAC_DCFGR register */
#define   GMAC_EMAC_DCFGR_CRCERRREP_0_Val     _UINT32_(0x0)                                        /* (GMAC_EMAC_DCFGR) Bit 16 of the receive buffer descriptor represents the Canonical format indicator (CFI) bit as extracted from the receive frame (if the receive buffer descriptor is pointing to the last data buffer of the receive frame and the received frame was VLAN tagged).  */
#define   GMAC_EMAC_DCFGR_CRCERRREP_1_Val     _UINT32_(0x1)                                        /* (GMAC_EMAC_DCFGR) Bit 16 of the receive buffer descriptor represents the FCS/CRC error (only if frames with FCS are copied to memory as enabled by bit 26 in the Network Configuration register).  */
#define GMAC_EMAC_DCFGR_CRCERRREP_0           (GMAC_EMAC_DCFGR_CRCERRREP_0_Val << GMAC_EMAC_DCFGR_CRCERRREP_Pos) /* (GMAC_EMAC_DCFGR) Bit 16 of the receive buffer descriptor represents the Canonical format indicator (CFI) bit as extracted from the receive frame (if the receive buffer descriptor is pointing to the last data buffer of the receive frame and the received frame was VLAN tagged). Position  */
#define GMAC_EMAC_DCFGR_CRCERRREP_1           (GMAC_EMAC_DCFGR_CRCERRREP_1_Val << GMAC_EMAC_DCFGR_CRCERRREP_Pos) /* (GMAC_EMAC_DCFGR) Bit 16 of the receive buffer descriptor represents the FCS/CRC error (only if frames with FCS are copied to memory as enabled by bit 26 in the Network Configuration register). Position  */
#define GMAC_EMAC_DCFGR_DRBS_Pos              _UINT32_(16)                                         /* (GMAC_EMAC_DCFGR) DMA Receive Buffer Size Position */
#define GMAC_EMAC_DCFGR_DRBS_Msk              (_UINT32_(0xFF) << GMAC_EMAC_DCFGR_DRBS_Pos)         /* (GMAC_EMAC_DCFGR) DMA Receive Buffer Size Mask */
#define GMAC_EMAC_DCFGR_DRBS(value)           (GMAC_EMAC_DCFGR_DRBS_Msk & (_UINT32_(value) << GMAC_EMAC_DCFGR_DRBS_Pos)) /* Assigment of value for DRBS in the GMAC_EMAC_DCFGR register */
#define   GMAC_EMAC_DCFGR_DRBS_0x02_Val       _UINT32_(0x2)                                        /* (GMAC_EMAC_DCFGR) 128 bytes  */
#define   GMAC_EMAC_DCFGR_DRBS_0x18_Val       _UINT32_(0x18)                                       /* (GMAC_EMAC_DCFGR) 1536 bytes (1 x max length frame/buffer)  */
#define   GMAC_EMAC_DCFGR_DRBS_0xA0_Val       _UINT32_(0xA0)                                       /* (GMAC_EMAC_DCFGR) 10240 bytes (1 x 10K jumbo frame/buffer)  */
#define GMAC_EMAC_DCFGR_DRBS_0x02             (GMAC_EMAC_DCFGR_DRBS_0x02_Val << GMAC_EMAC_DCFGR_DRBS_Pos) /* (GMAC_EMAC_DCFGR) 128 bytes Position  */
#define GMAC_EMAC_DCFGR_DRBS_0x18             (GMAC_EMAC_DCFGR_DRBS_0x18_Val << GMAC_EMAC_DCFGR_DRBS_Pos) /* (GMAC_EMAC_DCFGR) 1536 bytes (1 x max length frame/buffer) Position  */
#define GMAC_EMAC_DCFGR_DRBS_0xA0             (GMAC_EMAC_DCFGR_DRBS_0xA0_Val << GMAC_EMAC_DCFGR_DRBS_Pos) /* (GMAC_EMAC_DCFGR) 10240 bytes (1 x 10K jumbo frame/buffer) Position  */
#define GMAC_EMAC_DCFGR_DDRP_Pos              _UINT32_(24)                                         /* (GMAC_EMAC_DCFGR) DMA Discard Receive Packets Position */
#define GMAC_EMAC_DCFGR_DDRP_Msk              (_UINT32_(0x1) << GMAC_EMAC_DCFGR_DDRP_Pos)          /* (GMAC_EMAC_DCFGR) DMA Discard Receive Packets Mask */
#define GMAC_EMAC_DCFGR_DDRP(value)           (GMAC_EMAC_DCFGR_DDRP_Msk & (_UINT32_(value) << GMAC_EMAC_DCFGR_DDRP_Pos)) /* Assigment of value for DDRP in the GMAC_EMAC_DCFGR register */
#define GMAC_EMAC_DCFGR_RXFOMAXB_Pos          _UINT32_(25)                                         /* (GMAC_EMAC_DCFGR) Force Receive Max Burst Length Position */
#define GMAC_EMAC_DCFGR_RXFOMAXB_Msk          (_UINT32_(0x1) << GMAC_EMAC_DCFGR_RXFOMAXB_Pos)      /* (GMAC_EMAC_DCFGR) Force Receive Max Burst Length Mask */
#define GMAC_EMAC_DCFGR_RXFOMAXB(value)       (GMAC_EMAC_DCFGR_RXFOMAXB_Msk & (_UINT32_(value) << GMAC_EMAC_DCFGR_RXFOMAXB_Pos)) /* Assigment of value for RXFOMAXB in the GMAC_EMAC_DCFGR register */
#define GMAC_EMAC_DCFGR_TXFOMAXB_Pos          _UINT32_(26)                                         /* (GMAC_EMAC_DCFGR) Force Transmit Max Burst Length Position */
#define GMAC_EMAC_DCFGR_TXFOMAXB_Msk          (_UINT32_(0x1) << GMAC_EMAC_DCFGR_TXFOMAXB_Pos)      /* (GMAC_EMAC_DCFGR) Force Transmit Max Burst Length Mask */
#define GMAC_EMAC_DCFGR_TXFOMAXB(value)       (GMAC_EMAC_DCFGR_TXFOMAXB_Msk & (_UINT32_(value) << GMAC_EMAC_DCFGR_TXFOMAXB_Pos)) /* Assigment of value for TXFOMAXB in the GMAC_EMAC_DCFGR register */
#define GMAC_EMAC_DCFGR_RXBD_EXTENDED_Pos     _UINT32_(28)                                         /* (GMAC_EMAC_DCFGR) Receive Buffer Descriptor Extended Mode Position */
#define GMAC_EMAC_DCFGR_RXBD_EXTENDED_Msk     (_UINT32_(0x1) << GMAC_EMAC_DCFGR_RXBD_EXTENDED_Pos) /* (GMAC_EMAC_DCFGR) Receive Buffer Descriptor Extended Mode Mask */
#define GMAC_EMAC_DCFGR_RXBD_EXTENDED(value)  (GMAC_EMAC_DCFGR_RXBD_EXTENDED_Msk & (_UINT32_(value) << GMAC_EMAC_DCFGR_RXBD_EXTENDED_Pos)) /* Assigment of value for RXBD_EXTENDED in the GMAC_EMAC_DCFGR register */
#define   GMAC_EMAC_DCFGR_RXBD_EXTENDED_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_DCFGR) Disables Receive Buffer Data Extended mode.  */
#define   GMAC_EMAC_DCFGR_RXBD_EXTENDED_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_DCFGR) Enables Receive Buffer Data Extended mode.  */
#define GMAC_EMAC_DCFGR_RXBD_EXTENDED_0       (GMAC_EMAC_DCFGR_RXBD_EXTENDED_0_Val << GMAC_EMAC_DCFGR_RXBD_EXTENDED_Pos) /* (GMAC_EMAC_DCFGR) Disables Receive Buffer Data Extended mode. Position  */
#define GMAC_EMAC_DCFGR_RXBD_EXTENDED_1       (GMAC_EMAC_DCFGR_RXBD_EXTENDED_1_Val << GMAC_EMAC_DCFGR_RXBD_EXTENDED_Pos) /* (GMAC_EMAC_DCFGR) Enables Receive Buffer Data Extended mode. Position  */
#define GMAC_EMAC_DCFGR_TXBD_EXTENDED_Pos     _UINT32_(29)                                         /* (GMAC_EMAC_DCFGR) Transmit Buffer Descriptor Extended Mode Position */
#define GMAC_EMAC_DCFGR_TXBD_EXTENDED_Msk     (_UINT32_(0x1) << GMAC_EMAC_DCFGR_TXBD_EXTENDED_Pos) /* (GMAC_EMAC_DCFGR) Transmit Buffer Descriptor Extended Mode Mask */
#define GMAC_EMAC_DCFGR_TXBD_EXTENDED(value)  (GMAC_EMAC_DCFGR_TXBD_EXTENDED_Msk & (_UINT32_(value) << GMAC_EMAC_DCFGR_TXBD_EXTENDED_Pos)) /* Assigment of value for TXBD_EXTENDED in the GMAC_EMAC_DCFGR register */
#define   GMAC_EMAC_DCFGR_TXBD_EXTENDED_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_DCFGR) Disables Transmit Buffer Data Extended mode.  */
#define   GMAC_EMAC_DCFGR_TXBD_EXTENDED_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_DCFGR) Enables Transmit Buffer Data Extended mode.  */
#define GMAC_EMAC_DCFGR_TXBD_EXTENDED_0       (GMAC_EMAC_DCFGR_TXBD_EXTENDED_0_Val << GMAC_EMAC_DCFGR_TXBD_EXTENDED_Pos) /* (GMAC_EMAC_DCFGR) Disables Transmit Buffer Data Extended mode. Position  */
#define GMAC_EMAC_DCFGR_TXBD_EXTENDED_1       (GMAC_EMAC_DCFGR_TXBD_EXTENDED_1_Val << GMAC_EMAC_DCFGR_TXBD_EXTENDED_Pos) /* (GMAC_EMAC_DCFGR) Enables Transmit Buffer Data Extended mode. Position  */
#define GMAC_EMAC_DCFGR_Msk                   _UINT32_(0x37FF3FDF)                                 /* (GMAC_EMAC_DCFGR) Register Mask  */


/* -------- GMAC_EMAC_TSR : (GMAC Offset: 0x1014) (R/W 32) Express MAC Transmit Status Register -------- */
#define GMAC_EMAC_TSR_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_TSR) Express MAC Transmit Status Register  Reset Value */

#define GMAC_EMAC_TSR_UBR_Pos                 _UINT32_(0)                                          /* (GMAC_EMAC_TSR) Used Bit Read (Clear by Writing a 1) Position */
#define GMAC_EMAC_TSR_UBR_Msk                 (_UINT32_(0x1) << GMAC_EMAC_TSR_UBR_Pos)             /* (GMAC_EMAC_TSR) Used Bit Read (Clear by Writing a 1) Mask */
#define GMAC_EMAC_TSR_UBR(value)              (GMAC_EMAC_TSR_UBR_Msk & (_UINT32_(value) << GMAC_EMAC_TSR_UBR_Pos)) /* Assigment of value for UBR in the GMAC_EMAC_TSR register */
#define GMAC_EMAC_TSR_COL_Pos                 _UINT32_(1)                                          /* (GMAC_EMAC_TSR) Collision Occurred (Clear by Writing a 1) Position */
#define GMAC_EMAC_TSR_COL_Msk                 (_UINT32_(0x1) << GMAC_EMAC_TSR_COL_Pos)             /* (GMAC_EMAC_TSR) Collision Occurred (Clear by Writing a 1) Mask */
#define GMAC_EMAC_TSR_COL(value)              (GMAC_EMAC_TSR_COL_Msk & (_UINT32_(value) << GMAC_EMAC_TSR_COL_Pos)) /* Assigment of value for COL in the GMAC_EMAC_TSR register */
#define GMAC_EMAC_TSR_RLE_Pos                 _UINT32_(2)                                          /* (GMAC_EMAC_TSR) Retry Limit Exceeded (Clear by Writing a 1) Position */
#define GMAC_EMAC_TSR_RLE_Msk                 (_UINT32_(0x1) << GMAC_EMAC_TSR_RLE_Pos)             /* (GMAC_EMAC_TSR) Retry Limit Exceeded (Clear by Writing a 1) Mask */
#define GMAC_EMAC_TSR_RLE(value)              (GMAC_EMAC_TSR_RLE_Msk & (_UINT32_(value) << GMAC_EMAC_TSR_RLE_Pos)) /* Assigment of value for RLE in the GMAC_EMAC_TSR register */
#define GMAC_EMAC_TSR_TXGO_Pos                _UINT32_(3)                                          /* (GMAC_EMAC_TSR) Transmit Go (Read only) Position */
#define GMAC_EMAC_TSR_TXGO_Msk                (_UINT32_(0x1) << GMAC_EMAC_TSR_TXGO_Pos)            /* (GMAC_EMAC_TSR) Transmit Go (Read only) Mask */
#define GMAC_EMAC_TSR_TXGO(value)             (GMAC_EMAC_TSR_TXGO_Msk & (_UINT32_(value) << GMAC_EMAC_TSR_TXGO_Pos)) /* Assigment of value for TXGO in the GMAC_EMAC_TSR register */
#define GMAC_EMAC_TSR_TFC_Pos                 _UINT32_(4)                                          /* (GMAC_EMAC_TSR) Transmit Frame Corruption Due to System Bus Error (Clear by Writing a 1) Position */
#define GMAC_EMAC_TSR_TFC_Msk                 (_UINT32_(0x1) << GMAC_EMAC_TSR_TFC_Pos)             /* (GMAC_EMAC_TSR) Transmit Frame Corruption Due to System Bus Error (Clear by Writing a 1) Mask */
#define GMAC_EMAC_TSR_TFC(value)              (GMAC_EMAC_TSR_TFC_Msk & (_UINT32_(value) << GMAC_EMAC_TSR_TFC_Pos)) /* Assigment of value for TFC in the GMAC_EMAC_TSR register */
#define GMAC_EMAC_TSR_TXCOMP_Pos              _UINT32_(5)                                          /* (GMAC_EMAC_TSR) Transmit Complete (Clear by Writing a 1) Position */
#define GMAC_EMAC_TSR_TXCOMP_Msk              (_UINT32_(0x1) << GMAC_EMAC_TSR_TXCOMP_Pos)          /* (GMAC_EMAC_TSR) Transmit Complete (Clear by Writing a 1) Mask */
#define GMAC_EMAC_TSR_TXCOMP(value)           (GMAC_EMAC_TSR_TXCOMP_Msk & (_UINT32_(value) << GMAC_EMAC_TSR_TXCOMP_Pos)) /* Assigment of value for TXCOMP in the GMAC_EMAC_TSR register */
#define GMAC_EMAC_TSR_LCO_Pos                 _UINT32_(7)                                          /* (GMAC_EMAC_TSR) Late Collision Occurred (Clear by Writing a 1) Position */
#define GMAC_EMAC_TSR_LCO_Msk                 (_UINT32_(0x1) << GMAC_EMAC_TSR_LCO_Pos)             /* (GMAC_EMAC_TSR) Late Collision Occurred (Clear by Writing a 1) Mask */
#define GMAC_EMAC_TSR_LCO(value)              (GMAC_EMAC_TSR_LCO_Msk & (_UINT32_(value) << GMAC_EMAC_TSR_LCO_Pos)) /* Assigment of value for LCO in the GMAC_EMAC_TSR register */
#define GMAC_EMAC_TSR_HRESP_Pos               _UINT32_(8)                                          /* (GMAC_EMAC_TSR) System Bus Response (Clear by Writing a 1) Position */
#define GMAC_EMAC_TSR_HRESP_Msk               (_UINT32_(0x1) << GMAC_EMAC_TSR_HRESP_Pos)           /* (GMAC_EMAC_TSR) System Bus Response (Clear by Writing a 1) Mask */
#define GMAC_EMAC_TSR_HRESP(value)            (GMAC_EMAC_TSR_HRESP_Msk & (_UINT32_(value) << GMAC_EMAC_TSR_HRESP_Pos)) /* Assigment of value for HRESP in the GMAC_EMAC_TSR register */
#define GMAC_EMAC_TSR_TXMACLCK_Pos            _UINT32_(9)                                          /* (GMAC_EMAC_TSR) Transmit MAC Lockup (Clear by Writing a 1) Position */
#define GMAC_EMAC_TSR_TXMACLCK_Msk            (_UINT32_(0x1) << GMAC_EMAC_TSR_TXMACLCK_Pos)        /* (GMAC_EMAC_TSR) Transmit MAC Lockup (Clear by Writing a 1) Mask */
#define GMAC_EMAC_TSR_TXMACLCK(value)         (GMAC_EMAC_TSR_TXMACLCK_Msk & (_UINT32_(value) << GMAC_EMAC_TSR_TXMACLCK_Pos)) /* Assigment of value for TXMACLCK in the GMAC_EMAC_TSR register */
#define GMAC_EMAC_TSR_TXDMALCK_Pos            _UINT32_(10)                                         /* (GMAC_EMAC_TSR) Transmit DMA Lockup (Clear by Writing a 1) Position */
#define GMAC_EMAC_TSR_TXDMALCK_Msk            (_UINT32_(0x1) << GMAC_EMAC_TSR_TXDMALCK_Pos)        /* (GMAC_EMAC_TSR) Transmit DMA Lockup (Clear by Writing a 1) Mask */
#define GMAC_EMAC_TSR_TXDMALCK(value)         (GMAC_EMAC_TSR_TXDMALCK_Msk & (_UINT32_(value) << GMAC_EMAC_TSR_TXDMALCK_Pos)) /* Assigment of value for TXDMALCK in the GMAC_EMAC_TSR register */
#define GMAC_EMAC_TSR_Msk                     _UINT32_(0x000007BF)                                 /* (GMAC_EMAC_TSR) Register Mask  */


/* -------- GMAC_EMAC_RBQB : (GMAC Offset: 0x1018) (R/W 32) Express MAC Receive Buffer Queue Base Address Register -------- */
#define GMAC_EMAC_RBQB_RESETVALUE             _UINT32_(0x00)                                       /*  (GMAC_EMAC_RBQB) Express MAC Receive Buffer Queue Base Address Register  Reset Value */

#define GMAC_EMAC_RBQB_RXQDIS_Pos             _UINT32_(0)                                          /* (GMAC_EMAC_RBQB) Receive Queue Disable Position */
#define GMAC_EMAC_RBQB_RXQDIS_Msk             (_UINT32_(0x1) << GMAC_EMAC_RBQB_RXQDIS_Pos)         /* (GMAC_EMAC_RBQB) Receive Queue Disable Mask */
#define GMAC_EMAC_RBQB_RXQDIS(value)          (GMAC_EMAC_RBQB_RXQDIS_Msk & (_UINT32_(value) << GMAC_EMAC_RBQB_RXQDIS_Pos)) /* Assigment of value for RXQDIS in the GMAC_EMAC_RBQB register */
#define   GMAC_EMAC_RBQB_RXQDIS_0_Val         _UINT32_(0x0)                                        /* (GMAC_EMAC_RBQB) Queue is enabled.  */
#define   GMAC_EMAC_RBQB_RXQDIS_1_Val         _UINT32_(0x1)                                        /* (GMAC_EMAC_RBQB) Queue is disabled. Used to reduce the number of active queues and should only be changed while receive is not enabled.  */
#define GMAC_EMAC_RBQB_RXQDIS_0               (GMAC_EMAC_RBQB_RXQDIS_0_Val << GMAC_EMAC_RBQB_RXQDIS_Pos) /* (GMAC_EMAC_RBQB) Queue is enabled. Position  */
#define GMAC_EMAC_RBQB_RXQDIS_1               (GMAC_EMAC_RBQB_RXQDIS_1_Val << GMAC_EMAC_RBQB_RXQDIS_Pos) /* (GMAC_EMAC_RBQB) Queue is disabled. Used to reduce the number of active queues and should only be changed while receive is not enabled. Position  */
#define GMAC_EMAC_RBQB_ADDR_Pos               _UINT32_(2)                                          /* (GMAC_EMAC_RBQB) Receive Buffer Queue Base Address Position */
#define GMAC_EMAC_RBQB_ADDR_Msk               (_UINT32_(0x3FFFFFFF) << GMAC_EMAC_RBQB_ADDR_Pos)    /* (GMAC_EMAC_RBQB) Receive Buffer Queue Base Address Mask */
#define GMAC_EMAC_RBQB_ADDR(value)            (GMAC_EMAC_RBQB_ADDR_Msk & (_UINT32_(value) << GMAC_EMAC_RBQB_ADDR_Pos)) /* Assigment of value for ADDR in the GMAC_EMAC_RBQB register */
#define GMAC_EMAC_RBQB_Msk                    _UINT32_(0xFFFFFFFD)                                 /* (GMAC_EMAC_RBQB) Register Mask  */


/* -------- GMAC_EMAC_TBQB : (GMAC Offset: 0x101C) (R/W 32) Express MAC Transmit Buffer Queue Base Address Register -------- */
#define GMAC_EMAC_TBQB_RESETVALUE             _UINT32_(0x00)                                       /*  (GMAC_EMAC_TBQB) Express MAC Transmit Buffer Queue Base Address Register  Reset Value */

#define GMAC_EMAC_TBQB_TXQDIS_Pos             _UINT32_(0)                                          /* (GMAC_EMAC_TBQB) Transmit Queue Disable Position */
#define GMAC_EMAC_TBQB_TXQDIS_Msk             (_UINT32_(0x1) << GMAC_EMAC_TBQB_TXQDIS_Pos)         /* (GMAC_EMAC_TBQB) Transmit Queue Disable Mask */
#define GMAC_EMAC_TBQB_TXQDIS(value)          (GMAC_EMAC_TBQB_TXQDIS_Msk & (_UINT32_(value) << GMAC_EMAC_TBQB_TXQDIS_Pos)) /* Assigment of value for TXQDIS in the GMAC_EMAC_TBQB register */
#define   GMAC_EMAC_TBQB_TXQDIS_0_Val         _UINT32_(0x0)                                        /* (GMAC_EMAC_TBQB) Queue is enabled.  */
#define   GMAC_EMAC_TBQB_TXQDIS_1_Val         _UINT32_(0x1)                                        /* (GMAC_EMAC_TBQB) Queue is disabled. Used to reduce the number of active queues and should only be changed while transmit is not enabled.  */
#define GMAC_EMAC_TBQB_TXQDIS_0               (GMAC_EMAC_TBQB_TXQDIS_0_Val << GMAC_EMAC_TBQB_TXQDIS_Pos) /* (GMAC_EMAC_TBQB) Queue is enabled. Position  */
#define GMAC_EMAC_TBQB_TXQDIS_1               (GMAC_EMAC_TBQB_TXQDIS_1_Val << GMAC_EMAC_TBQB_TXQDIS_Pos) /* (GMAC_EMAC_TBQB) Queue is disabled. Used to reduce the number of active queues and should only be changed while transmit is not enabled. Position  */
#define GMAC_EMAC_TBQB_ADDR_Pos               _UINT32_(2)                                          /* (GMAC_EMAC_TBQB) Transmit Buffer Queue Base Address Position */
#define GMAC_EMAC_TBQB_ADDR_Msk               (_UINT32_(0x3FFFFFFF) << GMAC_EMAC_TBQB_ADDR_Pos)    /* (GMAC_EMAC_TBQB) Transmit Buffer Queue Base Address Mask */
#define GMAC_EMAC_TBQB_ADDR(value)            (GMAC_EMAC_TBQB_ADDR_Msk & (_UINT32_(value) << GMAC_EMAC_TBQB_ADDR_Pos)) /* Assigment of value for ADDR in the GMAC_EMAC_TBQB register */
#define GMAC_EMAC_TBQB_Msk                    _UINT32_(0xFFFFFFFD)                                 /* (GMAC_EMAC_TBQB) Register Mask  */


/* -------- GMAC_EMAC_RSR : (GMAC Offset: 0x1020) (R/W 32) Express MAC Receive Status Register -------- */
#define GMAC_EMAC_RSR_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_RSR) Express MAC Receive Status Register  Reset Value */

#define GMAC_EMAC_RSR_BNA_Pos                 _UINT32_(0)                                          /* (GMAC_EMAC_RSR) Buffer Not Available (Clear by Writing a 1) Position */
#define GMAC_EMAC_RSR_BNA_Msk                 (_UINT32_(0x1) << GMAC_EMAC_RSR_BNA_Pos)             /* (GMAC_EMAC_RSR) Buffer Not Available (Clear by Writing a 1) Mask */
#define GMAC_EMAC_RSR_BNA(value)              (GMAC_EMAC_RSR_BNA_Msk & (_UINT32_(value) << GMAC_EMAC_RSR_BNA_Pos)) /* Assigment of value for BNA in the GMAC_EMAC_RSR register */
#define GMAC_EMAC_RSR_REC_Pos                 _UINT32_(1)                                          /* (GMAC_EMAC_RSR) Frame Received (Clear by Writing a 1) Position */
#define GMAC_EMAC_RSR_REC_Msk                 (_UINT32_(0x1) << GMAC_EMAC_RSR_REC_Pos)             /* (GMAC_EMAC_RSR) Frame Received (Clear by Writing a 1) Mask */
#define GMAC_EMAC_RSR_REC(value)              (GMAC_EMAC_RSR_REC_Msk & (_UINT32_(value) << GMAC_EMAC_RSR_REC_Pos)) /* Assigment of value for REC in the GMAC_EMAC_RSR register */
#define GMAC_EMAC_RSR_RXOVR_Pos               _UINT32_(2)                                          /* (GMAC_EMAC_RSR) Receive Overrun (Clear by Writing a 1) Position */
#define GMAC_EMAC_RSR_RXOVR_Msk               (_UINT32_(0x1) << GMAC_EMAC_RSR_RXOVR_Pos)           /* (GMAC_EMAC_RSR) Receive Overrun (Clear by Writing a 1) Mask */
#define GMAC_EMAC_RSR_RXOVR(value)            (GMAC_EMAC_RSR_RXOVR_Msk & (_UINT32_(value) << GMAC_EMAC_RSR_RXOVR_Pos)) /* Assigment of value for RXOVR in the GMAC_EMAC_RSR register */
#define GMAC_EMAC_RSR_HNO_Pos                 _UINT32_(3)                                          /* (GMAC_EMAC_RSR) System Bus Error (Clear by Writing a 1) Position */
#define GMAC_EMAC_RSR_HNO_Msk                 (_UINT32_(0x1) << GMAC_EMAC_RSR_HNO_Pos)             /* (GMAC_EMAC_RSR) System Bus Error (Clear by Writing a 1) Mask */
#define GMAC_EMAC_RSR_HNO(value)              (GMAC_EMAC_RSR_HNO_Msk & (_UINT32_(value) << GMAC_EMAC_RSR_HNO_Pos)) /* Assigment of value for HNO in the GMAC_EMAC_RSR register */
#define GMAC_EMAC_RSR_RXMACLCK_Pos            _UINT32_(4)                                          /* (GMAC_EMAC_RSR) Receive MAC Lockup (Clear by Writing a 1) Position */
#define GMAC_EMAC_RSR_RXMACLCK_Msk            (_UINT32_(0x1) << GMAC_EMAC_RSR_RXMACLCK_Pos)        /* (GMAC_EMAC_RSR) Receive MAC Lockup (Clear by Writing a 1) Mask */
#define GMAC_EMAC_RSR_RXMACLCK(value)         (GMAC_EMAC_RSR_RXMACLCK_Msk & (_UINT32_(value) << GMAC_EMAC_RSR_RXMACLCK_Pos)) /* Assigment of value for RXMACLCK in the GMAC_EMAC_RSR register */
#define GMAC_EMAC_RSR_RXDMALCK_Pos            _UINT32_(5)                                          /* (GMAC_EMAC_RSR) Receive DMA Lockup (Clear by Writing a 1) Position */
#define GMAC_EMAC_RSR_RXDMALCK_Msk            (_UINT32_(0x1) << GMAC_EMAC_RSR_RXDMALCK_Pos)        /* (GMAC_EMAC_RSR) Receive DMA Lockup (Clear by Writing a 1) Mask */
#define GMAC_EMAC_RSR_RXDMALCK(value)         (GMAC_EMAC_RSR_RXDMALCK_Msk & (_UINT32_(value) << GMAC_EMAC_RSR_RXDMALCK_Pos)) /* Assigment of value for RXDMALCK in the GMAC_EMAC_RSR register */
#define GMAC_EMAC_RSR_Msk                     _UINT32_(0x0000003F)                                 /* (GMAC_EMAC_RSR) Register Mask  */


/* -------- GMAC_EMAC_ISR : (GMAC Offset: 0x1024) ( R/ 32) Express MAC Interrupt Status Register -------- */
#define GMAC_EMAC_ISR_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_ISR) Express MAC Interrupt Status Register  Reset Value */

#define GMAC_EMAC_ISR_MFS_Pos                 _UINT32_(0)                                          /* (GMAC_EMAC_ISR) Management Frame Sent (Cleared on read) Position */
#define GMAC_EMAC_ISR_MFS_Msk                 (_UINT32_(0x1) << GMAC_EMAC_ISR_MFS_Pos)             /* (GMAC_EMAC_ISR) Management Frame Sent (Cleared on read) Mask */
#define GMAC_EMAC_ISR_MFS(value)              (GMAC_EMAC_ISR_MFS_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_MFS_Pos)) /* Assigment of value for MFS in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_RCOMP_Pos               _UINT32_(1)                                          /* (GMAC_EMAC_ISR) Receive Complete (Cleared on read) Position */
#define GMAC_EMAC_ISR_RCOMP_Msk               (_UINT32_(0x1) << GMAC_EMAC_ISR_RCOMP_Pos)           /* (GMAC_EMAC_ISR) Receive Complete (Cleared on read) Mask */
#define GMAC_EMAC_ISR_RCOMP(value)            (GMAC_EMAC_ISR_RCOMP_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_RCOMP_Pos)) /* Assigment of value for RCOMP in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_RXUBR_Pos               _UINT32_(2)                                          /* (GMAC_EMAC_ISR) RX Used Bit Read (Cleared on read) Position */
#define GMAC_EMAC_ISR_RXUBR_Msk               (_UINT32_(0x1) << GMAC_EMAC_ISR_RXUBR_Pos)           /* (GMAC_EMAC_ISR) RX Used Bit Read (Cleared on read) Mask */
#define GMAC_EMAC_ISR_RXUBR(value)            (GMAC_EMAC_ISR_RXUBR_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_RXUBR_Pos)) /* Assigment of value for RXUBR in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_TXUBR_Pos               _UINT32_(3)                                          /* (GMAC_EMAC_ISR) TX Used Bit Read (Cleared on read) Position */
#define GMAC_EMAC_ISR_TXUBR_Msk               (_UINT32_(0x1) << GMAC_EMAC_ISR_TXUBR_Pos)           /* (GMAC_EMAC_ISR) TX Used Bit Read (Cleared on read) Mask */
#define GMAC_EMAC_ISR_TXUBR(value)            (GMAC_EMAC_ISR_TXUBR_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_TXUBR_Pos)) /* Assigment of value for TXUBR in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_TUR_Pos                 _UINT32_(4)                                          /* (GMAC_EMAC_ISR) Transmit Underrun (Cleared on read) Position */
#define GMAC_EMAC_ISR_TUR_Msk                 (_UINT32_(0x1) << GMAC_EMAC_ISR_TUR_Pos)             /* (GMAC_EMAC_ISR) Transmit Underrun (Cleared on read) Mask */
#define GMAC_EMAC_ISR_TUR(value)              (GMAC_EMAC_ISR_TUR_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_TUR_Pos)) /* Assigment of value for TUR in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_RLEX_Pos                _UINT32_(5)                                          /* (GMAC_EMAC_ISR) Retry Limit Exceeded or Late Collision (Cleared on read) Position */
#define GMAC_EMAC_ISR_RLEX_Msk                (_UINT32_(0x1) << GMAC_EMAC_ISR_RLEX_Pos)            /* (GMAC_EMAC_ISR) Retry Limit Exceeded or Late Collision (Cleared on read) Mask */
#define GMAC_EMAC_ISR_RLEX(value)             (GMAC_EMAC_ISR_RLEX_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_RLEX_Pos)) /* Assigment of value for RLEX in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_TFC_Pos                 _UINT32_(6)                                          /* (GMAC_EMAC_ISR) Transmit Frame Corruption Due to System Bus Error (Cleared on read) Position */
#define GMAC_EMAC_ISR_TFC_Msk                 (_UINT32_(0x1) << GMAC_EMAC_ISR_TFC_Pos)             /* (GMAC_EMAC_ISR) Transmit Frame Corruption Due to System Bus Error (Cleared on read) Mask */
#define GMAC_EMAC_ISR_TFC(value)              (GMAC_EMAC_ISR_TFC_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_TFC_Pos)) /* Assigment of value for TFC in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_TCOMP_Pos               _UINT32_(7)                                          /* (GMAC_EMAC_ISR) Transmit Complete (Cleared on read) Position */
#define GMAC_EMAC_ISR_TCOMP_Msk               (_UINT32_(0x1) << GMAC_EMAC_ISR_TCOMP_Pos)           /* (GMAC_EMAC_ISR) Transmit Complete (Cleared on read) Mask */
#define GMAC_EMAC_ISR_TCOMP(value)            (GMAC_EMAC_ISR_TCOMP_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_TCOMP_Pos)) /* Assigment of value for TCOMP in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_ROVR_Pos                _UINT32_(10)                                         /* (GMAC_EMAC_ISR) Receive Overrun (Cleared on read) Position */
#define GMAC_EMAC_ISR_ROVR_Msk                (_UINT32_(0x1) << GMAC_EMAC_ISR_ROVR_Pos)            /* (GMAC_EMAC_ISR) Receive Overrun (Cleared on read) Mask */
#define GMAC_EMAC_ISR_ROVR(value)             (GMAC_EMAC_ISR_ROVR_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_ROVR_Pos)) /* Assigment of value for ROVR in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_HRESP_Pos               _UINT32_(11)                                         /* (GMAC_EMAC_ISR) System Bus Error (Cleared on read) Position */
#define GMAC_EMAC_ISR_HRESP_Msk               (_UINT32_(0x1) << GMAC_EMAC_ISR_HRESP_Pos)           /* (GMAC_EMAC_ISR) System Bus Error (Cleared on read) Mask */
#define GMAC_EMAC_ISR_HRESP(value)            (GMAC_EMAC_ISR_HRESP_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_HRESP_Pos)) /* Assigment of value for HRESP in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_PFNZ_Pos                _UINT32_(12)                                         /* (GMAC_EMAC_ISR) Pause Frame with Non-zero Pause Quantum Received (Cleared on read) Position */
#define GMAC_EMAC_ISR_PFNZ_Msk                (_UINT32_(0x1) << GMAC_EMAC_ISR_PFNZ_Pos)            /* (GMAC_EMAC_ISR) Pause Frame with Non-zero Pause Quantum Received (Cleared on read) Mask */
#define GMAC_EMAC_ISR_PFNZ(value)             (GMAC_EMAC_ISR_PFNZ_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_PFNZ_Pos)) /* Assigment of value for PFNZ in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_PTZ_Pos                 _UINT32_(13)                                         /* (GMAC_EMAC_ISR) Pause Time Zero (Cleared on read) Position */
#define GMAC_EMAC_ISR_PTZ_Msk                 (_UINT32_(0x1) << GMAC_EMAC_ISR_PTZ_Pos)             /* (GMAC_EMAC_ISR) Pause Time Zero (Cleared on read) Mask */
#define GMAC_EMAC_ISR_PTZ(value)              (GMAC_EMAC_ISR_PTZ_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_PTZ_Pos)) /* Assigment of value for PTZ in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_PFTR_Pos                _UINT32_(14)                                         /* (GMAC_EMAC_ISR) Pause Frame Transmitted (Cleared on read) Position */
#define GMAC_EMAC_ISR_PFTR_Msk                (_UINT32_(0x1) << GMAC_EMAC_ISR_PFTR_Pos)            /* (GMAC_EMAC_ISR) Pause Frame Transmitted (Cleared on read) Mask */
#define GMAC_EMAC_ISR_PFTR(value)             (GMAC_EMAC_ISR_PFTR_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_PFTR_Pos)) /* Assigment of value for PFTR in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_DRQFR_Pos               _UINT32_(18)                                         /* (GMAC_EMAC_ISR) PTP Delay Request Frame Received (Cleared on read) Position */
#define GMAC_EMAC_ISR_DRQFR_Msk               (_UINT32_(0x1) << GMAC_EMAC_ISR_DRQFR_Pos)           /* (GMAC_EMAC_ISR) PTP Delay Request Frame Received (Cleared on read) Mask */
#define GMAC_EMAC_ISR_DRQFR(value)            (GMAC_EMAC_ISR_DRQFR_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_DRQFR_Pos)) /* Assigment of value for DRQFR in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_SFR_Pos                 _UINT32_(19)                                         /* (GMAC_EMAC_ISR) PTP Sync Frame Received (Cleared on read) Position */
#define GMAC_EMAC_ISR_SFR_Msk                 (_UINT32_(0x1) << GMAC_EMAC_ISR_SFR_Pos)             /* (GMAC_EMAC_ISR) PTP Sync Frame Received (Cleared on read) Mask */
#define GMAC_EMAC_ISR_SFR(value)              (GMAC_EMAC_ISR_SFR_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_SFR_Pos)) /* Assigment of value for SFR in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_DRQFT_Pos               _UINT32_(20)                                         /* (GMAC_EMAC_ISR) PTP Delay Request Frame Transmitted (Cleared on read) Position */
#define GMAC_EMAC_ISR_DRQFT_Msk               (_UINT32_(0x1) << GMAC_EMAC_ISR_DRQFT_Pos)           /* (GMAC_EMAC_ISR) PTP Delay Request Frame Transmitted (Cleared on read) Mask */
#define GMAC_EMAC_ISR_DRQFT(value)            (GMAC_EMAC_ISR_DRQFT_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_DRQFT_Pos)) /* Assigment of value for DRQFT in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_SFT_Pos                 _UINT32_(21)                                         /* (GMAC_EMAC_ISR) PTP Sync Frame Transmitted (Cleared on read) Position */
#define GMAC_EMAC_ISR_SFT_Msk                 (_UINT32_(0x1) << GMAC_EMAC_ISR_SFT_Pos)             /* (GMAC_EMAC_ISR) PTP Sync Frame Transmitted (Cleared on read) Mask */
#define GMAC_EMAC_ISR_SFT(value)              (GMAC_EMAC_ISR_SFT_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_SFT_Pos)) /* Assigment of value for SFT in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_PDRQFR_Pos              _UINT32_(22)                                         /* (GMAC_EMAC_ISR) PDelay Request Frame Received (Cleared on read) Position */
#define GMAC_EMAC_ISR_PDRQFR_Msk              (_UINT32_(0x1) << GMAC_EMAC_ISR_PDRQFR_Pos)          /* (GMAC_EMAC_ISR) PDelay Request Frame Received (Cleared on read) Mask */
#define GMAC_EMAC_ISR_PDRQFR(value)           (GMAC_EMAC_ISR_PDRQFR_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_PDRQFR_Pos)) /* Assigment of value for PDRQFR in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_PDRSFR_Pos              _UINT32_(23)                                         /* (GMAC_EMAC_ISR) PDelay Response Frame Received (Cleared on read) Position */
#define GMAC_EMAC_ISR_PDRSFR_Msk              (_UINT32_(0x1) << GMAC_EMAC_ISR_PDRSFR_Pos)          /* (GMAC_EMAC_ISR) PDelay Response Frame Received (Cleared on read) Mask */
#define GMAC_EMAC_ISR_PDRSFR(value)           (GMAC_EMAC_ISR_PDRSFR_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_PDRSFR_Pos)) /* Assigment of value for PDRSFR in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_PDRQFT_Pos              _UINT32_(24)                                         /* (GMAC_EMAC_ISR) PDelay Request Frame Transmitted (Cleared on read) Position */
#define GMAC_EMAC_ISR_PDRQFT_Msk              (_UINT32_(0x1) << GMAC_EMAC_ISR_PDRQFT_Pos)          /* (GMAC_EMAC_ISR) PDelay Request Frame Transmitted (Cleared on read) Mask */
#define GMAC_EMAC_ISR_PDRQFT(value)           (GMAC_EMAC_ISR_PDRQFT_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_PDRQFT_Pos)) /* Assigment of value for PDRQFT in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_PDRSFT_Pos              _UINT32_(25)                                         /* (GMAC_EMAC_ISR) PDelay Response Frame Transmitted (Cleared on read) Position */
#define GMAC_EMAC_ISR_PDRSFT_Msk              (_UINT32_(0x1) << GMAC_EMAC_ISR_PDRSFT_Pos)          /* (GMAC_EMAC_ISR) PDelay Response Frame Transmitted (Cleared on read) Mask */
#define GMAC_EMAC_ISR_PDRSFT(value)           (GMAC_EMAC_ISR_PDRSFT_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_PDRSFT_Pos)) /* Assigment of value for PDRSFT in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_SRI_Pos                 _UINT32_(26)                                         /* (GMAC_EMAC_ISR) TSU Seconds Register Increment (Cleared on read) Position */
#define GMAC_EMAC_ISR_SRI_Msk                 (_UINT32_(0x1) << GMAC_EMAC_ISR_SRI_Pos)             /* (GMAC_EMAC_ISR) TSU Seconds Register Increment (Cleared on read) Mask */
#define GMAC_EMAC_ISR_SRI(value)              (GMAC_EMAC_ISR_SRI_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_SRI_Pos)) /* Assigment of value for SRI in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_RXLPISBC_Pos            _UINT32_(27)                                         /* (GMAC_EMAC_ISR) Receive LPI indication Status Bit Change (Cleared on read) Position */
#define GMAC_EMAC_ISR_RXLPISBC_Msk            (_UINT32_(0x1) << GMAC_EMAC_ISR_RXLPISBC_Pos)        /* (GMAC_EMAC_ISR) Receive LPI indication Status Bit Change (Cleared on read) Mask */
#define GMAC_EMAC_ISR_RXLPISBC(value)         (GMAC_EMAC_ISR_RXLPISBC_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_RXLPISBC_Pos)) /* Assigment of value for RXLPISBC in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_WOL_Pos                 _UINT32_(28)                                         /* (GMAC_EMAC_ISR) Wake On LAN (Cleared on read) Position */
#define GMAC_EMAC_ISR_WOL_Msk                 (_UINT32_(0x1) << GMAC_EMAC_ISR_WOL_Pos)             /* (GMAC_EMAC_ISR) Wake On LAN (Cleared on read) Mask */
#define GMAC_EMAC_ISR_WOL(value)              (GMAC_EMAC_ISR_WOL_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_WOL_Pos)) /* Assigment of value for WOL in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_TSUTIMCOMP_Pos          _UINT32_(29)                                         /* (GMAC_EMAC_ISR) TSU Timer Comparison (Cleared on read) Position */
#define GMAC_EMAC_ISR_TSUTIMCOMP_Msk          (_UINT32_(0x1) << GMAC_EMAC_ISR_TSUTIMCOMP_Pos)      /* (GMAC_EMAC_ISR) TSU Timer Comparison (Cleared on read) Mask */
#define GMAC_EMAC_ISR_TSUTIMCOMP(value)       (GMAC_EMAC_ISR_TSUTIMCOMP_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_TSUTIMCOMP_Pos)) /* Assigment of value for TSUTIMCOMP in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_RXLCK_Pos               _UINT32_(30)                                         /* (GMAC_EMAC_ISR) Receive Path Locked (Cleared on read) Position */
#define GMAC_EMAC_ISR_RXLCK_Msk               (_UINT32_(0x1) << GMAC_EMAC_ISR_RXLCK_Pos)           /* (GMAC_EMAC_ISR) Receive Path Locked (Cleared on read) Mask */
#define GMAC_EMAC_ISR_RXLCK(value)            (GMAC_EMAC_ISR_RXLCK_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_RXLCK_Pos)) /* Assigment of value for RXLCK in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_TXLCK_Pos               _UINT32_(31)                                         /* (GMAC_EMAC_ISR) Transmit Path Locked (Cleared on read) Position */
#define GMAC_EMAC_ISR_TXLCK_Msk               (_UINT32_(0x1) << GMAC_EMAC_ISR_TXLCK_Pos)           /* (GMAC_EMAC_ISR) Transmit Path Locked (Cleared on read) Mask */
#define GMAC_EMAC_ISR_TXLCK(value)            (GMAC_EMAC_ISR_TXLCK_Msk & (_UINT32_(value) << GMAC_EMAC_ISR_TXLCK_Pos)) /* Assigment of value for TXLCK in the GMAC_EMAC_ISR register */
#define GMAC_EMAC_ISR_Msk                     _UINT32_(0xFFFC7CFF)                                 /* (GMAC_EMAC_ISR) Register Mask  */


/* -------- GMAC_EMAC_IER : (GMAC Offset: 0x1028) ( /W 32) Express MAC Interrupt Enable Register -------- */
#define GMAC_EMAC_IER_MFS_Pos                 _UINT32_(0)                                          /* (GMAC_EMAC_IER) Management Frame Sent Position */
#define GMAC_EMAC_IER_MFS_Msk                 (_UINT32_(0x1) << GMAC_EMAC_IER_MFS_Pos)             /* (GMAC_EMAC_IER) Management Frame Sent Mask */
#define GMAC_EMAC_IER_MFS(value)              (GMAC_EMAC_IER_MFS_Msk & (_UINT32_(value) << GMAC_EMAC_IER_MFS_Pos)) /* Assigment of value for MFS in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_RCOMP_Pos               _UINT32_(1)                                          /* (GMAC_EMAC_IER) Receive Complete Position */
#define GMAC_EMAC_IER_RCOMP_Msk               (_UINT32_(0x1) << GMAC_EMAC_IER_RCOMP_Pos)           /* (GMAC_EMAC_IER) Receive Complete Mask */
#define GMAC_EMAC_IER_RCOMP(value)            (GMAC_EMAC_IER_RCOMP_Msk & (_UINT32_(value) << GMAC_EMAC_IER_RCOMP_Pos)) /* Assigment of value for RCOMP in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_RXUBR_Pos               _UINT32_(2)                                          /* (GMAC_EMAC_IER) RX Used Bit Read Position */
#define GMAC_EMAC_IER_RXUBR_Msk               (_UINT32_(0x1) << GMAC_EMAC_IER_RXUBR_Pos)           /* (GMAC_EMAC_IER) RX Used Bit Read Mask */
#define GMAC_EMAC_IER_RXUBR(value)            (GMAC_EMAC_IER_RXUBR_Msk & (_UINT32_(value) << GMAC_EMAC_IER_RXUBR_Pos)) /* Assigment of value for RXUBR in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_TXUBR_Pos               _UINT32_(3)                                          /* (GMAC_EMAC_IER) TX Used Bit Read Position */
#define GMAC_EMAC_IER_TXUBR_Msk               (_UINT32_(0x1) << GMAC_EMAC_IER_TXUBR_Pos)           /* (GMAC_EMAC_IER) TX Used Bit Read Mask */
#define GMAC_EMAC_IER_TXUBR(value)            (GMAC_EMAC_IER_TXUBR_Msk & (_UINT32_(value) << GMAC_EMAC_IER_TXUBR_Pos)) /* Assigment of value for TXUBR in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_TUR_Pos                 _UINT32_(4)                                          /* (GMAC_EMAC_IER) Transmit Underrun Position */
#define GMAC_EMAC_IER_TUR_Msk                 (_UINT32_(0x1) << GMAC_EMAC_IER_TUR_Pos)             /* (GMAC_EMAC_IER) Transmit Underrun Mask */
#define GMAC_EMAC_IER_TUR(value)              (GMAC_EMAC_IER_TUR_Msk & (_UINT32_(value) << GMAC_EMAC_IER_TUR_Pos)) /* Assigment of value for TUR in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_RLEX_Pos                _UINT32_(5)                                          /* (GMAC_EMAC_IER) Retry Limit Exceeded or Late Collision Position */
#define GMAC_EMAC_IER_RLEX_Msk                (_UINT32_(0x1) << GMAC_EMAC_IER_RLEX_Pos)            /* (GMAC_EMAC_IER) Retry Limit Exceeded or Late Collision Mask */
#define GMAC_EMAC_IER_RLEX(value)             (GMAC_EMAC_IER_RLEX_Msk & (_UINT32_(value) << GMAC_EMAC_IER_RLEX_Pos)) /* Assigment of value for RLEX in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_TFC_Pos                 _UINT32_(6)                                          /* (GMAC_EMAC_IER) Transmit Frame Corruption Due to System Bus Error Position */
#define GMAC_EMAC_IER_TFC_Msk                 (_UINT32_(0x1) << GMAC_EMAC_IER_TFC_Pos)             /* (GMAC_EMAC_IER) Transmit Frame Corruption Due to System Bus Error Mask */
#define GMAC_EMAC_IER_TFC(value)              (GMAC_EMAC_IER_TFC_Msk & (_UINT32_(value) << GMAC_EMAC_IER_TFC_Pos)) /* Assigment of value for TFC in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_TCOMP_Pos               _UINT32_(7)                                          /* (GMAC_EMAC_IER) Transmit Complete Position */
#define GMAC_EMAC_IER_TCOMP_Msk               (_UINT32_(0x1) << GMAC_EMAC_IER_TCOMP_Pos)           /* (GMAC_EMAC_IER) Transmit Complete Mask */
#define GMAC_EMAC_IER_TCOMP(value)            (GMAC_EMAC_IER_TCOMP_Msk & (_UINT32_(value) << GMAC_EMAC_IER_TCOMP_Pos)) /* Assigment of value for TCOMP in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_ROVR_Pos                _UINT32_(10)                                         /* (GMAC_EMAC_IER) Receive Overrun Position */
#define GMAC_EMAC_IER_ROVR_Msk                (_UINT32_(0x1) << GMAC_EMAC_IER_ROVR_Pos)            /* (GMAC_EMAC_IER) Receive Overrun Mask */
#define GMAC_EMAC_IER_ROVR(value)             (GMAC_EMAC_IER_ROVR_Msk & (_UINT32_(value) << GMAC_EMAC_IER_ROVR_Pos)) /* Assigment of value for ROVR in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_HRESP_Pos               _UINT32_(11)                                         /* (GMAC_EMAC_IER) System Bus Error Position */
#define GMAC_EMAC_IER_HRESP_Msk               (_UINT32_(0x1) << GMAC_EMAC_IER_HRESP_Pos)           /* (GMAC_EMAC_IER) System Bus Error Mask */
#define GMAC_EMAC_IER_HRESP(value)            (GMAC_EMAC_IER_HRESP_Msk & (_UINT32_(value) << GMAC_EMAC_IER_HRESP_Pos)) /* Assigment of value for HRESP in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_PFNZ_Pos                _UINT32_(12)                                         /* (GMAC_EMAC_IER) Pause Frame with Non-zero Pause Quantum Received Position */
#define GMAC_EMAC_IER_PFNZ_Msk                (_UINT32_(0x1) << GMAC_EMAC_IER_PFNZ_Pos)            /* (GMAC_EMAC_IER) Pause Frame with Non-zero Pause Quantum Received Mask */
#define GMAC_EMAC_IER_PFNZ(value)             (GMAC_EMAC_IER_PFNZ_Msk & (_UINT32_(value) << GMAC_EMAC_IER_PFNZ_Pos)) /* Assigment of value for PFNZ in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_PTZ_Pos                 _UINT32_(13)                                         /* (GMAC_EMAC_IER) Pause Time Zero Position */
#define GMAC_EMAC_IER_PTZ_Msk                 (_UINT32_(0x1) << GMAC_EMAC_IER_PTZ_Pos)             /* (GMAC_EMAC_IER) Pause Time Zero Mask */
#define GMAC_EMAC_IER_PTZ(value)              (GMAC_EMAC_IER_PTZ_Msk & (_UINT32_(value) << GMAC_EMAC_IER_PTZ_Pos)) /* Assigment of value for PTZ in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_PFTR_Pos                _UINT32_(14)                                         /* (GMAC_EMAC_IER) Pause Frame Transmitted Position */
#define GMAC_EMAC_IER_PFTR_Msk                (_UINT32_(0x1) << GMAC_EMAC_IER_PFTR_Pos)            /* (GMAC_EMAC_IER) Pause Frame Transmitted Mask */
#define GMAC_EMAC_IER_PFTR(value)             (GMAC_EMAC_IER_PFTR_Msk & (_UINT32_(value) << GMAC_EMAC_IER_PFTR_Pos)) /* Assigment of value for PFTR in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_EXINT_Pos               _UINT32_(15)                                         /* (GMAC_EMAC_IER) External Interrupt Position */
#define GMAC_EMAC_IER_EXINT_Msk               (_UINT32_(0x1) << GMAC_EMAC_IER_EXINT_Pos)           /* (GMAC_EMAC_IER) External Interrupt Mask */
#define GMAC_EMAC_IER_EXINT(value)            (GMAC_EMAC_IER_EXINT_Msk & (_UINT32_(value) << GMAC_EMAC_IER_EXINT_Pos)) /* Assigment of value for EXINT in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_DRQFR_Pos               _UINT32_(18)                                         /* (GMAC_EMAC_IER) PTP Delay Request Frame Received Position */
#define GMAC_EMAC_IER_DRQFR_Msk               (_UINT32_(0x1) << GMAC_EMAC_IER_DRQFR_Pos)           /* (GMAC_EMAC_IER) PTP Delay Request Frame Received Mask */
#define GMAC_EMAC_IER_DRQFR(value)            (GMAC_EMAC_IER_DRQFR_Msk & (_UINT32_(value) << GMAC_EMAC_IER_DRQFR_Pos)) /* Assigment of value for DRQFR in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_SFR_Pos                 _UINT32_(19)                                         /* (GMAC_EMAC_IER) PTP Sync Frame Received Position */
#define GMAC_EMAC_IER_SFR_Msk                 (_UINT32_(0x1) << GMAC_EMAC_IER_SFR_Pos)             /* (GMAC_EMAC_IER) PTP Sync Frame Received Mask */
#define GMAC_EMAC_IER_SFR(value)              (GMAC_EMAC_IER_SFR_Msk & (_UINT32_(value) << GMAC_EMAC_IER_SFR_Pos)) /* Assigment of value for SFR in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_DRQFT_Pos               _UINT32_(20)                                         /* (GMAC_EMAC_IER) PTP Delay Request Frame Transmitted Position */
#define GMAC_EMAC_IER_DRQFT_Msk               (_UINT32_(0x1) << GMAC_EMAC_IER_DRQFT_Pos)           /* (GMAC_EMAC_IER) PTP Delay Request Frame Transmitted Mask */
#define GMAC_EMAC_IER_DRQFT(value)            (GMAC_EMAC_IER_DRQFT_Msk & (_UINT32_(value) << GMAC_EMAC_IER_DRQFT_Pos)) /* Assigment of value for DRQFT in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_SFT_Pos                 _UINT32_(21)                                         /* (GMAC_EMAC_IER) PTP Sync Frame Transmitted Position */
#define GMAC_EMAC_IER_SFT_Msk                 (_UINT32_(0x1) << GMAC_EMAC_IER_SFT_Pos)             /* (GMAC_EMAC_IER) PTP Sync Frame Transmitted Mask */
#define GMAC_EMAC_IER_SFT(value)              (GMAC_EMAC_IER_SFT_Msk & (_UINT32_(value) << GMAC_EMAC_IER_SFT_Pos)) /* Assigment of value for SFT in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_PDRQFR_Pos              _UINT32_(22)                                         /* (GMAC_EMAC_IER) PDelay Request Frame Received Position */
#define GMAC_EMAC_IER_PDRQFR_Msk              (_UINT32_(0x1) << GMAC_EMAC_IER_PDRQFR_Pos)          /* (GMAC_EMAC_IER) PDelay Request Frame Received Mask */
#define GMAC_EMAC_IER_PDRQFR(value)           (GMAC_EMAC_IER_PDRQFR_Msk & (_UINT32_(value) << GMAC_EMAC_IER_PDRQFR_Pos)) /* Assigment of value for PDRQFR in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_PDRSFR_Pos              _UINT32_(23)                                         /* (GMAC_EMAC_IER) PDelay Response Frame Received Position */
#define GMAC_EMAC_IER_PDRSFR_Msk              (_UINT32_(0x1) << GMAC_EMAC_IER_PDRSFR_Pos)          /* (GMAC_EMAC_IER) PDelay Response Frame Received Mask */
#define GMAC_EMAC_IER_PDRSFR(value)           (GMAC_EMAC_IER_PDRSFR_Msk & (_UINT32_(value) << GMAC_EMAC_IER_PDRSFR_Pos)) /* Assigment of value for PDRSFR in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_PDRQFT_Pos              _UINT32_(24)                                         /* (GMAC_EMAC_IER) PDelay Request Frame Transmitted Position */
#define GMAC_EMAC_IER_PDRQFT_Msk              (_UINT32_(0x1) << GMAC_EMAC_IER_PDRQFT_Pos)          /* (GMAC_EMAC_IER) PDelay Request Frame Transmitted Mask */
#define GMAC_EMAC_IER_PDRQFT(value)           (GMAC_EMAC_IER_PDRQFT_Msk & (_UINT32_(value) << GMAC_EMAC_IER_PDRQFT_Pos)) /* Assigment of value for PDRQFT in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_PDRSFT_Pos              _UINT32_(25)                                         /* (GMAC_EMAC_IER) PDelay Response Frame Transmitted Position */
#define GMAC_EMAC_IER_PDRSFT_Msk              (_UINT32_(0x1) << GMAC_EMAC_IER_PDRSFT_Pos)          /* (GMAC_EMAC_IER) PDelay Response Frame Transmitted Mask */
#define GMAC_EMAC_IER_PDRSFT(value)           (GMAC_EMAC_IER_PDRSFT_Msk & (_UINT32_(value) << GMAC_EMAC_IER_PDRSFT_Pos)) /* Assigment of value for PDRSFT in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_SRI_Pos                 _UINT32_(26)                                         /* (GMAC_EMAC_IER) TSU Seconds Register Increment Position */
#define GMAC_EMAC_IER_SRI_Msk                 (_UINT32_(0x1) << GMAC_EMAC_IER_SRI_Pos)             /* (GMAC_EMAC_IER) TSU Seconds Register Increment Mask */
#define GMAC_EMAC_IER_SRI(value)              (GMAC_EMAC_IER_SRI_Msk & (_UINT32_(value) << GMAC_EMAC_IER_SRI_Pos)) /* Assigment of value for SRI in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_RXLPISBC_Pos            _UINT32_(27)                                         /* (GMAC_EMAC_IER) Enable RX LPI Indication Position */
#define GMAC_EMAC_IER_RXLPISBC_Msk            (_UINT32_(0x1) << GMAC_EMAC_IER_RXLPISBC_Pos)        /* (GMAC_EMAC_IER) Enable RX LPI Indication Mask */
#define GMAC_EMAC_IER_RXLPISBC(value)         (GMAC_EMAC_IER_RXLPISBC_Msk & (_UINT32_(value) << GMAC_EMAC_IER_RXLPISBC_Pos)) /* Assigment of value for RXLPISBC in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_WOL_Pos                 _UINT32_(28)                                         /* (GMAC_EMAC_IER) Wake On LAN Position */
#define GMAC_EMAC_IER_WOL_Msk                 (_UINT32_(0x1) << GMAC_EMAC_IER_WOL_Pos)             /* (GMAC_EMAC_IER) Wake On LAN Mask */
#define GMAC_EMAC_IER_WOL(value)              (GMAC_EMAC_IER_WOL_Msk & (_UINT32_(value) << GMAC_EMAC_IER_WOL_Pos)) /* Assigment of value for WOL in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_TSUTIMCOMP_Pos          _UINT32_(29)                                         /* (GMAC_EMAC_IER) TSU Timer Comparison Position */
#define GMAC_EMAC_IER_TSUTIMCOMP_Msk          (_UINT32_(0x1) << GMAC_EMAC_IER_TSUTIMCOMP_Pos)      /* (GMAC_EMAC_IER) TSU Timer Comparison Mask */
#define GMAC_EMAC_IER_TSUTIMCOMP(value)       (GMAC_EMAC_IER_TSUTIMCOMP_Msk & (_UINT32_(value) << GMAC_EMAC_IER_TSUTIMCOMP_Pos)) /* Assigment of value for TSUTIMCOMP in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_RXLCK_Pos               _UINT32_(30)                                         /* (GMAC_EMAC_IER) Receive Path Lockup Detected Position */
#define GMAC_EMAC_IER_RXLCK_Msk               (_UINT32_(0x1) << GMAC_EMAC_IER_RXLCK_Pos)           /* (GMAC_EMAC_IER) Receive Path Lockup Detected Mask */
#define GMAC_EMAC_IER_RXLCK(value)            (GMAC_EMAC_IER_RXLCK_Msk & (_UINT32_(value) << GMAC_EMAC_IER_RXLCK_Pos)) /* Assigment of value for RXLCK in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_TXLCK_Pos               _UINT32_(31)                                         /* (GMAC_EMAC_IER) Transmit Path Lockup Detected Position */
#define GMAC_EMAC_IER_TXLCK_Msk               (_UINT32_(0x1) << GMAC_EMAC_IER_TXLCK_Pos)           /* (GMAC_EMAC_IER) Transmit Path Lockup Detected Mask */
#define GMAC_EMAC_IER_TXLCK(value)            (GMAC_EMAC_IER_TXLCK_Msk & (_UINT32_(value) << GMAC_EMAC_IER_TXLCK_Pos)) /* Assigment of value for TXLCK in the GMAC_EMAC_IER register */
#define GMAC_EMAC_IER_Msk                     _UINT32_(0xFFFCFCFF)                                 /* (GMAC_EMAC_IER) Register Mask  */


/* -------- GMAC_EMAC_IDR : (GMAC Offset: 0x102C) ( /W 32) Express MAC Interrupt Disable Register -------- */
#define GMAC_EMAC_IDR_MFS_Pos                 _UINT32_(0)                                          /* (GMAC_EMAC_IDR) Management Frame Sent Position */
#define GMAC_EMAC_IDR_MFS_Msk                 (_UINT32_(0x1) << GMAC_EMAC_IDR_MFS_Pos)             /* (GMAC_EMAC_IDR) Management Frame Sent Mask */
#define GMAC_EMAC_IDR_MFS(value)              (GMAC_EMAC_IDR_MFS_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_MFS_Pos)) /* Assigment of value for MFS in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_RCOMP_Pos               _UINT32_(1)                                          /* (GMAC_EMAC_IDR) Receive Complete Position */
#define GMAC_EMAC_IDR_RCOMP_Msk               (_UINT32_(0x1) << GMAC_EMAC_IDR_RCOMP_Pos)           /* (GMAC_EMAC_IDR) Receive Complete Mask */
#define GMAC_EMAC_IDR_RCOMP(value)            (GMAC_EMAC_IDR_RCOMP_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_RCOMP_Pos)) /* Assigment of value for RCOMP in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_RXUBR_Pos               _UINT32_(2)                                          /* (GMAC_EMAC_IDR) RX Used Bit Read Position */
#define GMAC_EMAC_IDR_RXUBR_Msk               (_UINT32_(0x1) << GMAC_EMAC_IDR_RXUBR_Pos)           /* (GMAC_EMAC_IDR) RX Used Bit Read Mask */
#define GMAC_EMAC_IDR_RXUBR(value)            (GMAC_EMAC_IDR_RXUBR_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_RXUBR_Pos)) /* Assigment of value for RXUBR in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_TXUBR_Pos               _UINT32_(3)                                          /* (GMAC_EMAC_IDR) TX Used Bit Read Position */
#define GMAC_EMAC_IDR_TXUBR_Msk               (_UINT32_(0x1) << GMAC_EMAC_IDR_TXUBR_Pos)           /* (GMAC_EMAC_IDR) TX Used Bit Read Mask */
#define GMAC_EMAC_IDR_TXUBR(value)            (GMAC_EMAC_IDR_TXUBR_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_TXUBR_Pos)) /* Assigment of value for TXUBR in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_TUR_Pos                 _UINT32_(4)                                          /* (GMAC_EMAC_IDR) Transmit Underrun Position */
#define GMAC_EMAC_IDR_TUR_Msk                 (_UINT32_(0x1) << GMAC_EMAC_IDR_TUR_Pos)             /* (GMAC_EMAC_IDR) Transmit Underrun Mask */
#define GMAC_EMAC_IDR_TUR(value)              (GMAC_EMAC_IDR_TUR_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_TUR_Pos)) /* Assigment of value for TUR in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_RLEX_Pos                _UINT32_(5)                                          /* (GMAC_EMAC_IDR) Retry Limit Exceeded or Late Collision Position */
#define GMAC_EMAC_IDR_RLEX_Msk                (_UINT32_(0x1) << GMAC_EMAC_IDR_RLEX_Pos)            /* (GMAC_EMAC_IDR) Retry Limit Exceeded or Late Collision Mask */
#define GMAC_EMAC_IDR_RLEX(value)             (GMAC_EMAC_IDR_RLEX_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_RLEX_Pos)) /* Assigment of value for RLEX in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_TFC_Pos                 _UINT32_(6)                                          /* (GMAC_EMAC_IDR) Transmit Frame Corruption Due to System Bus Error Position */
#define GMAC_EMAC_IDR_TFC_Msk                 (_UINT32_(0x1) << GMAC_EMAC_IDR_TFC_Pos)             /* (GMAC_EMAC_IDR) Transmit Frame Corruption Due to System Bus Error Mask */
#define GMAC_EMAC_IDR_TFC(value)              (GMAC_EMAC_IDR_TFC_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_TFC_Pos)) /* Assigment of value for TFC in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_TCOMP_Pos               _UINT32_(7)                                          /* (GMAC_EMAC_IDR) Transmit Complete Position */
#define GMAC_EMAC_IDR_TCOMP_Msk               (_UINT32_(0x1) << GMAC_EMAC_IDR_TCOMP_Pos)           /* (GMAC_EMAC_IDR) Transmit Complete Mask */
#define GMAC_EMAC_IDR_TCOMP(value)            (GMAC_EMAC_IDR_TCOMP_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_TCOMP_Pos)) /* Assigment of value for TCOMP in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_ROVR_Pos                _UINT32_(10)                                         /* (GMAC_EMAC_IDR) Receive Overrun Position */
#define GMAC_EMAC_IDR_ROVR_Msk                (_UINT32_(0x1) << GMAC_EMAC_IDR_ROVR_Pos)            /* (GMAC_EMAC_IDR) Receive Overrun Mask */
#define GMAC_EMAC_IDR_ROVR(value)             (GMAC_EMAC_IDR_ROVR_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_ROVR_Pos)) /* Assigment of value for ROVR in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_HRESP_Pos               _UINT32_(11)                                         /* (GMAC_EMAC_IDR) System Bus Error Position */
#define GMAC_EMAC_IDR_HRESP_Msk               (_UINT32_(0x1) << GMAC_EMAC_IDR_HRESP_Pos)           /* (GMAC_EMAC_IDR) System Bus Error Mask */
#define GMAC_EMAC_IDR_HRESP(value)            (GMAC_EMAC_IDR_HRESP_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_HRESP_Pos)) /* Assigment of value for HRESP in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_PFNZ_Pos                _UINT32_(12)                                         /* (GMAC_EMAC_IDR) Pause Frame with Non-zero Pause Quantum Received Position */
#define GMAC_EMAC_IDR_PFNZ_Msk                (_UINT32_(0x1) << GMAC_EMAC_IDR_PFNZ_Pos)            /* (GMAC_EMAC_IDR) Pause Frame with Non-zero Pause Quantum Received Mask */
#define GMAC_EMAC_IDR_PFNZ(value)             (GMAC_EMAC_IDR_PFNZ_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_PFNZ_Pos)) /* Assigment of value for PFNZ in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_PTZ_Pos                 _UINT32_(13)                                         /* (GMAC_EMAC_IDR) Pause Time Zero Position */
#define GMAC_EMAC_IDR_PTZ_Msk                 (_UINT32_(0x1) << GMAC_EMAC_IDR_PTZ_Pos)             /* (GMAC_EMAC_IDR) Pause Time Zero Mask */
#define GMAC_EMAC_IDR_PTZ(value)              (GMAC_EMAC_IDR_PTZ_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_PTZ_Pos)) /* Assigment of value for PTZ in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_PFTR_Pos                _UINT32_(14)                                         /* (GMAC_EMAC_IDR) Pause Frame Transmitted Position */
#define GMAC_EMAC_IDR_PFTR_Msk                (_UINT32_(0x1) << GMAC_EMAC_IDR_PFTR_Pos)            /* (GMAC_EMAC_IDR) Pause Frame Transmitted Mask */
#define GMAC_EMAC_IDR_PFTR(value)             (GMAC_EMAC_IDR_PFTR_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_PFTR_Pos)) /* Assigment of value for PFTR in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_EXINT_Pos               _UINT32_(15)                                         /* (GMAC_EMAC_IDR) External Interrupt Position */
#define GMAC_EMAC_IDR_EXINT_Msk               (_UINT32_(0x1) << GMAC_EMAC_IDR_EXINT_Pos)           /* (GMAC_EMAC_IDR) External Interrupt Mask */
#define GMAC_EMAC_IDR_EXINT(value)            (GMAC_EMAC_IDR_EXINT_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_EXINT_Pos)) /* Assigment of value for EXINT in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_DRQFR_Pos               _UINT32_(18)                                         /* (GMAC_EMAC_IDR) PTP Delay Request Frame Received Position */
#define GMAC_EMAC_IDR_DRQFR_Msk               (_UINT32_(0x1) << GMAC_EMAC_IDR_DRQFR_Pos)           /* (GMAC_EMAC_IDR) PTP Delay Request Frame Received Mask */
#define GMAC_EMAC_IDR_DRQFR(value)            (GMAC_EMAC_IDR_DRQFR_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_DRQFR_Pos)) /* Assigment of value for DRQFR in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_SFR_Pos                 _UINT32_(19)                                         /* (GMAC_EMAC_IDR) PTP Sync Frame Received Position */
#define GMAC_EMAC_IDR_SFR_Msk                 (_UINT32_(0x1) << GMAC_EMAC_IDR_SFR_Pos)             /* (GMAC_EMAC_IDR) PTP Sync Frame Received Mask */
#define GMAC_EMAC_IDR_SFR(value)              (GMAC_EMAC_IDR_SFR_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_SFR_Pos)) /* Assigment of value for SFR in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_DRQFT_Pos               _UINT32_(20)                                         /* (GMAC_EMAC_IDR) PTP Delay Request Frame Transmitted Position */
#define GMAC_EMAC_IDR_DRQFT_Msk               (_UINT32_(0x1) << GMAC_EMAC_IDR_DRQFT_Pos)           /* (GMAC_EMAC_IDR) PTP Delay Request Frame Transmitted Mask */
#define GMAC_EMAC_IDR_DRQFT(value)            (GMAC_EMAC_IDR_DRQFT_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_DRQFT_Pos)) /* Assigment of value for DRQFT in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_SFT_Pos                 _UINT32_(21)                                         /* (GMAC_EMAC_IDR) PTP Sync Frame Transmitted Position */
#define GMAC_EMAC_IDR_SFT_Msk                 (_UINT32_(0x1) << GMAC_EMAC_IDR_SFT_Pos)             /* (GMAC_EMAC_IDR) PTP Sync Frame Transmitted Mask */
#define GMAC_EMAC_IDR_SFT(value)              (GMAC_EMAC_IDR_SFT_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_SFT_Pos)) /* Assigment of value for SFT in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_PDRQFR_Pos              _UINT32_(22)                                         /* (GMAC_EMAC_IDR) PDelay Request Frame Received Position */
#define GMAC_EMAC_IDR_PDRQFR_Msk              (_UINT32_(0x1) << GMAC_EMAC_IDR_PDRQFR_Pos)          /* (GMAC_EMAC_IDR) PDelay Request Frame Received Mask */
#define GMAC_EMAC_IDR_PDRQFR(value)           (GMAC_EMAC_IDR_PDRQFR_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_PDRQFR_Pos)) /* Assigment of value for PDRQFR in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_PDRSFR_Pos              _UINT32_(23)                                         /* (GMAC_EMAC_IDR) PDelay Response Frame Received Position */
#define GMAC_EMAC_IDR_PDRSFR_Msk              (_UINT32_(0x1) << GMAC_EMAC_IDR_PDRSFR_Pos)          /* (GMAC_EMAC_IDR) PDelay Response Frame Received Mask */
#define GMAC_EMAC_IDR_PDRSFR(value)           (GMAC_EMAC_IDR_PDRSFR_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_PDRSFR_Pos)) /* Assigment of value for PDRSFR in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_PDRQFT_Pos              _UINT32_(24)                                         /* (GMAC_EMAC_IDR) PDelay Request Frame Transmitted Position */
#define GMAC_EMAC_IDR_PDRQFT_Msk              (_UINT32_(0x1) << GMAC_EMAC_IDR_PDRQFT_Pos)          /* (GMAC_EMAC_IDR) PDelay Request Frame Transmitted Mask */
#define GMAC_EMAC_IDR_PDRQFT(value)           (GMAC_EMAC_IDR_PDRQFT_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_PDRQFT_Pos)) /* Assigment of value for PDRQFT in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_PDRSFT_Pos              _UINT32_(25)                                         /* (GMAC_EMAC_IDR) PDelay Response Frame Transmitted Position */
#define GMAC_EMAC_IDR_PDRSFT_Msk              (_UINT32_(0x1) << GMAC_EMAC_IDR_PDRSFT_Pos)          /* (GMAC_EMAC_IDR) PDelay Response Frame Transmitted Mask */
#define GMAC_EMAC_IDR_PDRSFT(value)           (GMAC_EMAC_IDR_PDRSFT_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_PDRSFT_Pos)) /* Assigment of value for PDRSFT in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_SRI_Pos                 _UINT32_(26)                                         /* (GMAC_EMAC_IDR) TSU Seconds Register Increment Position */
#define GMAC_EMAC_IDR_SRI_Msk                 (_UINT32_(0x1) << GMAC_EMAC_IDR_SRI_Pos)             /* (GMAC_EMAC_IDR) TSU Seconds Register Increment Mask */
#define GMAC_EMAC_IDR_SRI(value)              (GMAC_EMAC_IDR_SRI_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_SRI_Pos)) /* Assigment of value for SRI in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_RXLPISBC_Pos            _UINT32_(27)                                         /* (GMAC_EMAC_IDR) Enable RX LPI Indication Position */
#define GMAC_EMAC_IDR_RXLPISBC_Msk            (_UINT32_(0x1) << GMAC_EMAC_IDR_RXLPISBC_Pos)        /* (GMAC_EMAC_IDR) Enable RX LPI Indication Mask */
#define GMAC_EMAC_IDR_RXLPISBC(value)         (GMAC_EMAC_IDR_RXLPISBC_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_RXLPISBC_Pos)) /* Assigment of value for RXLPISBC in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_WOL_Pos                 _UINT32_(28)                                         /* (GMAC_EMAC_IDR) Wake On LAN Position */
#define GMAC_EMAC_IDR_WOL_Msk                 (_UINT32_(0x1) << GMAC_EMAC_IDR_WOL_Pos)             /* (GMAC_EMAC_IDR) Wake On LAN Mask */
#define GMAC_EMAC_IDR_WOL(value)              (GMAC_EMAC_IDR_WOL_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_WOL_Pos)) /* Assigment of value for WOL in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_TSUTIMCOMP_Pos          _UINT32_(29)                                         /* (GMAC_EMAC_IDR) TSU Timer Comparison Position */
#define GMAC_EMAC_IDR_TSUTIMCOMP_Msk          (_UINT32_(0x1) << GMAC_EMAC_IDR_TSUTIMCOMP_Pos)      /* (GMAC_EMAC_IDR) TSU Timer Comparison Mask */
#define GMAC_EMAC_IDR_TSUTIMCOMP(value)       (GMAC_EMAC_IDR_TSUTIMCOMP_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_TSUTIMCOMP_Pos)) /* Assigment of value for TSUTIMCOMP in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_RXLCK_Pos               _UINT32_(30)                                         /* (GMAC_EMAC_IDR) Receive Path Lockup Detected Position */
#define GMAC_EMAC_IDR_RXLCK_Msk               (_UINT32_(0x1) << GMAC_EMAC_IDR_RXLCK_Pos)           /* (GMAC_EMAC_IDR) Receive Path Lockup Detected Mask */
#define GMAC_EMAC_IDR_RXLCK(value)            (GMAC_EMAC_IDR_RXLCK_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_RXLCK_Pos)) /* Assigment of value for RXLCK in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_TXLCK_Pos               _UINT32_(31)                                         /* (GMAC_EMAC_IDR) Transmit Path Lockup Detected Position */
#define GMAC_EMAC_IDR_TXLCK_Msk               (_UINT32_(0x1) << GMAC_EMAC_IDR_TXLCK_Pos)           /* (GMAC_EMAC_IDR) Transmit Path Lockup Detected Mask */
#define GMAC_EMAC_IDR_TXLCK(value)            (GMAC_EMAC_IDR_TXLCK_Msk & (_UINT32_(value) << GMAC_EMAC_IDR_TXLCK_Pos)) /* Assigment of value for TXLCK in the GMAC_EMAC_IDR register */
#define GMAC_EMAC_IDR_Msk                     _UINT32_(0xFFFCFCFF)                                 /* (GMAC_EMAC_IDR) Register Mask  */


/* -------- GMAC_EMAC_IMR : (GMAC Offset: 0x1030) (R/W 32) Express MAC Interrupt Mask Register -------- */
#define GMAC_EMAC_IMR_RESETVALUE              _UINT32_(0xFFFFFFFF)                                 /*  (GMAC_EMAC_IMR) Express MAC Interrupt Mask Register  Reset Value */

#define GMAC_EMAC_IMR_MFS_Pos                 _UINT32_(0)                                          /* (GMAC_EMAC_IMR) Management Frame Sent Position */
#define GMAC_EMAC_IMR_MFS_Msk                 (_UINT32_(0x1) << GMAC_EMAC_IMR_MFS_Pos)             /* (GMAC_EMAC_IMR) Management Frame Sent Mask */
#define GMAC_EMAC_IMR_MFS(value)              (GMAC_EMAC_IMR_MFS_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_MFS_Pos)) /* Assigment of value for MFS in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_RCOMP_Pos               _UINT32_(1)                                          /* (GMAC_EMAC_IMR) Receive Complete Position */
#define GMAC_EMAC_IMR_RCOMP_Msk               (_UINT32_(0x1) << GMAC_EMAC_IMR_RCOMP_Pos)           /* (GMAC_EMAC_IMR) Receive Complete Mask */
#define GMAC_EMAC_IMR_RCOMP(value)            (GMAC_EMAC_IMR_RCOMP_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_RCOMP_Pos)) /* Assigment of value for RCOMP in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_RXUBR_Pos               _UINT32_(2)                                          /* (GMAC_EMAC_IMR) RX Used Bit Read Position */
#define GMAC_EMAC_IMR_RXUBR_Msk               (_UINT32_(0x1) << GMAC_EMAC_IMR_RXUBR_Pos)           /* (GMAC_EMAC_IMR) RX Used Bit Read Mask */
#define GMAC_EMAC_IMR_RXUBR(value)            (GMAC_EMAC_IMR_RXUBR_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_RXUBR_Pos)) /* Assigment of value for RXUBR in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_TXUBR_Pos               _UINT32_(3)                                          /* (GMAC_EMAC_IMR) TX Used Bit Read Position */
#define GMAC_EMAC_IMR_TXUBR_Msk               (_UINT32_(0x1) << GMAC_EMAC_IMR_TXUBR_Pos)           /* (GMAC_EMAC_IMR) TX Used Bit Read Mask */
#define GMAC_EMAC_IMR_TXUBR(value)            (GMAC_EMAC_IMR_TXUBR_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_TXUBR_Pos)) /* Assigment of value for TXUBR in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_TUR_Pos                 _UINT32_(4)                                          /* (GMAC_EMAC_IMR) Transmit Underrun Position */
#define GMAC_EMAC_IMR_TUR_Msk                 (_UINT32_(0x1) << GMAC_EMAC_IMR_TUR_Pos)             /* (GMAC_EMAC_IMR) Transmit Underrun Mask */
#define GMAC_EMAC_IMR_TUR(value)              (GMAC_EMAC_IMR_TUR_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_TUR_Pos)) /* Assigment of value for TUR in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_RLEX_Pos                _UINT32_(5)                                          /* (GMAC_EMAC_IMR) Retry Limit Exceeded or Late Collision Position */
#define GMAC_EMAC_IMR_RLEX_Msk                (_UINT32_(0x1) << GMAC_EMAC_IMR_RLEX_Pos)            /* (GMAC_EMAC_IMR) Retry Limit Exceeded or Late Collision Mask */
#define GMAC_EMAC_IMR_RLEX(value)             (GMAC_EMAC_IMR_RLEX_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_RLEX_Pos)) /* Assigment of value for RLEX in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_TFC_Pos                 _UINT32_(6)                                          /* (GMAC_EMAC_IMR) Transmit Frame Corruption Due to System Bus Error Position */
#define GMAC_EMAC_IMR_TFC_Msk                 (_UINT32_(0x1) << GMAC_EMAC_IMR_TFC_Pos)             /* (GMAC_EMAC_IMR) Transmit Frame Corruption Due to System Bus Error Mask */
#define GMAC_EMAC_IMR_TFC(value)              (GMAC_EMAC_IMR_TFC_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_TFC_Pos)) /* Assigment of value for TFC in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_TCOMP_Pos               _UINT32_(7)                                          /* (GMAC_EMAC_IMR) Transmit Complete Position */
#define GMAC_EMAC_IMR_TCOMP_Msk               (_UINT32_(0x1) << GMAC_EMAC_IMR_TCOMP_Pos)           /* (GMAC_EMAC_IMR) Transmit Complete Mask */
#define GMAC_EMAC_IMR_TCOMP(value)            (GMAC_EMAC_IMR_TCOMP_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_TCOMP_Pos)) /* Assigment of value for TCOMP in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_ROVR_Pos                _UINT32_(10)                                         /* (GMAC_EMAC_IMR) Receive Overrun Position */
#define GMAC_EMAC_IMR_ROVR_Msk                (_UINT32_(0x1) << GMAC_EMAC_IMR_ROVR_Pos)            /* (GMAC_EMAC_IMR) Receive Overrun Mask */
#define GMAC_EMAC_IMR_ROVR(value)             (GMAC_EMAC_IMR_ROVR_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_ROVR_Pos)) /* Assigment of value for ROVR in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_HRESP_Pos               _UINT32_(11)                                         /* (GMAC_EMAC_IMR) System Bus Error Position */
#define GMAC_EMAC_IMR_HRESP_Msk               (_UINT32_(0x1) << GMAC_EMAC_IMR_HRESP_Pos)           /* (GMAC_EMAC_IMR) System Bus Error Mask */
#define GMAC_EMAC_IMR_HRESP(value)            (GMAC_EMAC_IMR_HRESP_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_HRESP_Pos)) /* Assigment of value for HRESP in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_PFNZ_Pos                _UINT32_(12)                                         /* (GMAC_EMAC_IMR) Pause Frame with Non-zero Pause Quantum Received Position */
#define GMAC_EMAC_IMR_PFNZ_Msk                (_UINT32_(0x1) << GMAC_EMAC_IMR_PFNZ_Pos)            /* (GMAC_EMAC_IMR) Pause Frame with Non-zero Pause Quantum Received Mask */
#define GMAC_EMAC_IMR_PFNZ(value)             (GMAC_EMAC_IMR_PFNZ_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_PFNZ_Pos)) /* Assigment of value for PFNZ in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_PTZ_Pos                 _UINT32_(13)                                         /* (GMAC_EMAC_IMR) Pause Time Zero Position */
#define GMAC_EMAC_IMR_PTZ_Msk                 (_UINT32_(0x1) << GMAC_EMAC_IMR_PTZ_Pos)             /* (GMAC_EMAC_IMR) Pause Time Zero Mask */
#define GMAC_EMAC_IMR_PTZ(value)              (GMAC_EMAC_IMR_PTZ_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_PTZ_Pos)) /* Assigment of value for PTZ in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_PFTR_Pos                _UINT32_(14)                                         /* (GMAC_EMAC_IMR) Pause Frame Transmitted Position */
#define GMAC_EMAC_IMR_PFTR_Msk                (_UINT32_(0x1) << GMAC_EMAC_IMR_PFTR_Pos)            /* (GMAC_EMAC_IMR) Pause Frame Transmitted Mask */
#define GMAC_EMAC_IMR_PFTR(value)             (GMAC_EMAC_IMR_PFTR_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_PFTR_Pos)) /* Assigment of value for PFTR in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_EXINT_Pos               _UINT32_(15)                                         /* (GMAC_EMAC_IMR) External Interrupt Position */
#define GMAC_EMAC_IMR_EXINT_Msk               (_UINT32_(0x1) << GMAC_EMAC_IMR_EXINT_Pos)           /* (GMAC_EMAC_IMR) External Interrupt Mask */
#define GMAC_EMAC_IMR_EXINT(value)            (GMAC_EMAC_IMR_EXINT_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_EXINT_Pos)) /* Assigment of value for EXINT in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_DRQFR_Pos               _UINT32_(18)                                         /* (GMAC_EMAC_IMR) PTP Delay Request Frame Received Position */
#define GMAC_EMAC_IMR_DRQFR_Msk               (_UINT32_(0x1) << GMAC_EMAC_IMR_DRQFR_Pos)           /* (GMAC_EMAC_IMR) PTP Delay Request Frame Received Mask */
#define GMAC_EMAC_IMR_DRQFR(value)            (GMAC_EMAC_IMR_DRQFR_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_DRQFR_Pos)) /* Assigment of value for DRQFR in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_SFR_Pos                 _UINT32_(19)                                         /* (GMAC_EMAC_IMR) PTP Sync Frame Received Position */
#define GMAC_EMAC_IMR_SFR_Msk                 (_UINT32_(0x1) << GMAC_EMAC_IMR_SFR_Pos)             /* (GMAC_EMAC_IMR) PTP Sync Frame Received Mask */
#define GMAC_EMAC_IMR_SFR(value)              (GMAC_EMAC_IMR_SFR_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_SFR_Pos)) /* Assigment of value for SFR in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_DRQFT_Pos               _UINT32_(20)                                         /* (GMAC_EMAC_IMR) PTP Delay Request Frame Transmitted Position */
#define GMAC_EMAC_IMR_DRQFT_Msk               (_UINT32_(0x1) << GMAC_EMAC_IMR_DRQFT_Pos)           /* (GMAC_EMAC_IMR) PTP Delay Request Frame Transmitted Mask */
#define GMAC_EMAC_IMR_DRQFT(value)            (GMAC_EMAC_IMR_DRQFT_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_DRQFT_Pos)) /* Assigment of value for DRQFT in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_SFT_Pos                 _UINT32_(21)                                         /* (GMAC_EMAC_IMR) PTP Sync Frame Transmitted Position */
#define GMAC_EMAC_IMR_SFT_Msk                 (_UINT32_(0x1) << GMAC_EMAC_IMR_SFT_Pos)             /* (GMAC_EMAC_IMR) PTP Sync Frame Transmitted Mask */
#define GMAC_EMAC_IMR_SFT(value)              (GMAC_EMAC_IMR_SFT_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_SFT_Pos)) /* Assigment of value for SFT in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_PDRQFR_Pos              _UINT32_(22)                                         /* (GMAC_EMAC_IMR) PDelay Request Frame Received Position */
#define GMAC_EMAC_IMR_PDRQFR_Msk              (_UINT32_(0x1) << GMAC_EMAC_IMR_PDRQFR_Pos)          /* (GMAC_EMAC_IMR) PDelay Request Frame Received Mask */
#define GMAC_EMAC_IMR_PDRQFR(value)           (GMAC_EMAC_IMR_PDRQFR_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_PDRQFR_Pos)) /* Assigment of value for PDRQFR in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_PDRSFR_Pos              _UINT32_(23)                                         /* (GMAC_EMAC_IMR) PDelay Response Frame Received Position */
#define GMAC_EMAC_IMR_PDRSFR_Msk              (_UINT32_(0x1) << GMAC_EMAC_IMR_PDRSFR_Pos)          /* (GMAC_EMAC_IMR) PDelay Response Frame Received Mask */
#define GMAC_EMAC_IMR_PDRSFR(value)           (GMAC_EMAC_IMR_PDRSFR_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_PDRSFR_Pos)) /* Assigment of value for PDRSFR in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_PDRQFT_Pos              _UINT32_(24)                                         /* (GMAC_EMAC_IMR) PDelay Request Frame Transmitted Position */
#define GMAC_EMAC_IMR_PDRQFT_Msk              (_UINT32_(0x1) << GMAC_EMAC_IMR_PDRQFT_Pos)          /* (GMAC_EMAC_IMR) PDelay Request Frame Transmitted Mask */
#define GMAC_EMAC_IMR_PDRQFT(value)           (GMAC_EMAC_IMR_PDRQFT_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_PDRQFT_Pos)) /* Assigment of value for PDRQFT in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_PDRSFT_Pos              _UINT32_(25)                                         /* (GMAC_EMAC_IMR) PDelay Response Frame Transmitted Position */
#define GMAC_EMAC_IMR_PDRSFT_Msk              (_UINT32_(0x1) << GMAC_EMAC_IMR_PDRSFT_Pos)          /* (GMAC_EMAC_IMR) PDelay Response Frame Transmitted Mask */
#define GMAC_EMAC_IMR_PDRSFT(value)           (GMAC_EMAC_IMR_PDRSFT_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_PDRSFT_Pos)) /* Assigment of value for PDRSFT in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_SRI_Pos                 _UINT32_(26)                                         /* (GMAC_EMAC_IMR) TSU Seconds Register Increment Position */
#define GMAC_EMAC_IMR_SRI_Msk                 (_UINT32_(0x1) << GMAC_EMAC_IMR_SRI_Pos)             /* (GMAC_EMAC_IMR) TSU Seconds Register Increment Mask */
#define GMAC_EMAC_IMR_SRI(value)              (GMAC_EMAC_IMR_SRI_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_SRI_Pos)) /* Assigment of value for SRI in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_RXLPISBC_Pos            _UINT32_(27)                                         /* (GMAC_EMAC_IMR) Enable RX LPI Indication Position */
#define GMAC_EMAC_IMR_RXLPISBC_Msk            (_UINT32_(0x1) << GMAC_EMAC_IMR_RXLPISBC_Pos)        /* (GMAC_EMAC_IMR) Enable RX LPI Indication Mask */
#define GMAC_EMAC_IMR_RXLPISBC(value)         (GMAC_EMAC_IMR_RXLPISBC_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_RXLPISBC_Pos)) /* Assigment of value for RXLPISBC in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_WOL_Pos                 _UINT32_(28)                                         /* (GMAC_EMAC_IMR) Wake On LAN Position */
#define GMAC_EMAC_IMR_WOL_Msk                 (_UINT32_(0x1) << GMAC_EMAC_IMR_WOL_Pos)             /* (GMAC_EMAC_IMR) Wake On LAN Mask */
#define GMAC_EMAC_IMR_WOL(value)              (GMAC_EMAC_IMR_WOL_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_WOL_Pos)) /* Assigment of value for WOL in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_TSUTIMCOMP_Pos          _UINT32_(29)                                         /* (GMAC_EMAC_IMR) TSU Timer Comparison Position */
#define GMAC_EMAC_IMR_TSUTIMCOMP_Msk          (_UINT32_(0x1) << GMAC_EMAC_IMR_TSUTIMCOMP_Pos)      /* (GMAC_EMAC_IMR) TSU Timer Comparison Mask */
#define GMAC_EMAC_IMR_TSUTIMCOMP(value)       (GMAC_EMAC_IMR_TSUTIMCOMP_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_TSUTIMCOMP_Pos)) /* Assigment of value for TSUTIMCOMP in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_RXLCK_Pos               _UINT32_(30)                                         /* (GMAC_EMAC_IMR) Receive Path Lockup Detected Position */
#define GMAC_EMAC_IMR_RXLCK_Msk               (_UINT32_(0x1) << GMAC_EMAC_IMR_RXLCK_Pos)           /* (GMAC_EMAC_IMR) Receive Path Lockup Detected Mask */
#define GMAC_EMAC_IMR_RXLCK(value)            (GMAC_EMAC_IMR_RXLCK_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_RXLCK_Pos)) /* Assigment of value for RXLCK in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_TXLCK_Pos               _UINT32_(31)                                         /* (GMAC_EMAC_IMR) Transmit Path Lockup Detected Position */
#define GMAC_EMAC_IMR_TXLCK_Msk               (_UINT32_(0x1) << GMAC_EMAC_IMR_TXLCK_Pos)           /* (GMAC_EMAC_IMR) Transmit Path Lockup Detected Mask */
#define GMAC_EMAC_IMR_TXLCK(value)            (GMAC_EMAC_IMR_TXLCK_Msk & (_UINT32_(value) << GMAC_EMAC_IMR_TXLCK_Pos)) /* Assigment of value for TXLCK in the GMAC_EMAC_IMR register */
#define GMAC_EMAC_IMR_Msk                     _UINT32_(0xFFFCFCFF)                                 /* (GMAC_EMAC_IMR) Register Mask  */


/* -------- GMAC_EMAC_RPQ : (GMAC Offset: 0x1038) ( R/ 32) Express MAC Receive Pause Quantum Register -------- */
#define GMAC_EMAC_RPQ_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_RPQ) Express MAC Receive Pause Quantum Register  Reset Value */

#define GMAC_EMAC_RPQ_RPQ_Pos                 _UINT32_(0)                                          /* (GMAC_EMAC_RPQ) Received Pause Quantum Position */
#define GMAC_EMAC_RPQ_RPQ_Msk                 (_UINT32_(0xFFFF) << GMAC_EMAC_RPQ_RPQ_Pos)          /* (GMAC_EMAC_RPQ) Received Pause Quantum Mask */
#define GMAC_EMAC_RPQ_RPQ(value)              (GMAC_EMAC_RPQ_RPQ_Msk & (_UINT32_(value) << GMAC_EMAC_RPQ_RPQ_Pos)) /* Assigment of value for RPQ in the GMAC_EMAC_RPQ register */
#define GMAC_EMAC_RPQ_Msk                     _UINT32_(0x0000FFFF)                                 /* (GMAC_EMAC_RPQ) Register Mask  */


/* -------- GMAC_EMAC_TPQ : (GMAC Offset: 0x103C) (R/W 32) Express MAC Transmit Pause Quantum Register -------- */
#define GMAC_EMAC_TPQ_RESETVALUE              _UINT32_(0xFFFFFFFF)                                 /*  (GMAC_EMAC_TPQ) Express MAC Transmit Pause Quantum Register  Reset Value */

#define GMAC_EMAC_TPQ_TPQ_Pos                 _UINT32_(0)                                          /* (GMAC_EMAC_TPQ) Transmit Pause Quantum Position */
#define GMAC_EMAC_TPQ_TPQ_Msk                 (_UINT32_(0xFFFF) << GMAC_EMAC_TPQ_TPQ_Pos)          /* (GMAC_EMAC_TPQ) Transmit Pause Quantum Mask */
#define GMAC_EMAC_TPQ_TPQ(value)              (GMAC_EMAC_TPQ_TPQ_Msk & (_UINT32_(value) << GMAC_EMAC_TPQ_TPQ_Pos)) /* Assigment of value for TPQ in the GMAC_EMAC_TPQ register */
#define GMAC_EMAC_TPQ_P1TPQ_Pos               _UINT32_(16)                                         /* (GMAC_EMAC_TPQ) Priority 1 Transmit Pause Quantum Position */
#define GMAC_EMAC_TPQ_P1TPQ_Msk               (_UINT32_(0xFFFF) << GMAC_EMAC_TPQ_P1TPQ_Pos)        /* (GMAC_EMAC_TPQ) Priority 1 Transmit Pause Quantum Mask */
#define GMAC_EMAC_TPQ_P1TPQ(value)            (GMAC_EMAC_TPQ_P1TPQ_Msk & (_UINT32_(value) << GMAC_EMAC_TPQ_P1TPQ_Pos)) /* Assigment of value for P1TPQ in the GMAC_EMAC_TPQ register */
#define GMAC_EMAC_TPQ_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_TPQ) Register Mask  */


/* -------- GMAC_EMAC_TPSF : (GMAC Offset: 0x1040) (R/W 32) Express MAC TX Partial Store and Forward Register -------- */
#define GMAC_EMAC_TPSF_RESETVALUE             _UINT32_(0xFFF)                                      /*  (GMAC_EMAC_TPSF) Express MAC TX Partial Store and Forward Register  Reset Value */

#define GMAC_EMAC_TPSF_TPB1ADR_Pos            _UINT32_(0)                                          /* (GMAC_EMAC_TPSF) Transmit Partial Store and Forward Address Position */
#define GMAC_EMAC_TPSF_TPB1ADR_Msk            (_UINT32_(0x3FF) << GMAC_EMAC_TPSF_TPB1ADR_Pos)      /* (GMAC_EMAC_TPSF) Transmit Partial Store and Forward Address Mask */
#define GMAC_EMAC_TPSF_TPB1ADR(value)         (GMAC_EMAC_TPSF_TPB1ADR_Msk & (_UINT32_(value) << GMAC_EMAC_TPSF_TPB1ADR_Pos)) /* Assigment of value for TPB1ADR in the GMAC_EMAC_TPSF register */
#define GMAC_EMAC_TPSF_ENTXP_Pos              _UINT32_(31)                                         /* (GMAC_EMAC_TPSF) Enable TX Partial Store and Forward Operation Position */
#define GMAC_EMAC_TPSF_ENTXP_Msk              (_UINT32_(0x1) << GMAC_EMAC_TPSF_ENTXP_Pos)          /* (GMAC_EMAC_TPSF) Enable TX Partial Store and Forward Operation Mask */
#define GMAC_EMAC_TPSF_ENTXP(value)           (GMAC_EMAC_TPSF_ENTXP_Msk & (_UINT32_(value) << GMAC_EMAC_TPSF_ENTXP_Pos)) /* Assigment of value for ENTXP in the GMAC_EMAC_TPSF register */
#define GMAC_EMAC_TPSF_Msk                    _UINT32_(0x800003FF)                                 /* (GMAC_EMAC_TPSF) Register Mask  */


/* -------- GMAC_EMAC_RPSF : (GMAC Offset: 0x1044) (R/W 32) Express MAC RX Partial Store and Forward Register -------- */
#define GMAC_EMAC_RPSF_RESETVALUE             _UINT32_(0xFFF)                                      /*  (GMAC_EMAC_RPSF) Express MAC RX Partial Store and Forward Register  Reset Value */

#define GMAC_EMAC_RPSF_RPB1ADR_Pos            _UINT32_(0)                                          /* (GMAC_EMAC_RPSF) Receive Partial Store and Forward Address Position */
#define GMAC_EMAC_RPSF_RPB1ADR_Msk            (_UINT32_(0x3FF) << GMAC_EMAC_RPSF_RPB1ADR_Pos)      /* (GMAC_EMAC_RPSF) Receive Partial Store and Forward Address Mask */
#define GMAC_EMAC_RPSF_RPB1ADR(value)         (GMAC_EMAC_RPSF_RPB1ADR_Msk & (_UINT32_(value) << GMAC_EMAC_RPSF_RPB1ADR_Pos)) /* Assigment of value for RPB1ADR in the GMAC_EMAC_RPSF register */
#define GMAC_EMAC_RPSF_ENRXP_Pos              _UINT32_(31)                                         /* (GMAC_EMAC_RPSF) Enable RX Partial Store and Forward Operation Position */
#define GMAC_EMAC_RPSF_ENRXP_Msk              (_UINT32_(0x1) << GMAC_EMAC_RPSF_ENRXP_Pos)          /* (GMAC_EMAC_RPSF) Enable RX Partial Store and Forward Operation Mask */
#define GMAC_EMAC_RPSF_ENRXP(value)           (GMAC_EMAC_RPSF_ENRXP_Msk & (_UINT32_(value) << GMAC_EMAC_RPSF_ENRXP_Pos)) /* Assigment of value for ENRXP in the GMAC_EMAC_RPSF register */
#define GMAC_EMAC_RPSF_Msk                    _UINT32_(0x800003FF)                                 /* (GMAC_EMAC_RPSF) Register Mask  */


/* -------- GMAC_EMAC_RJFML : (GMAC Offset: 0x1048) (R/W 32) Express MAC RX Jumbo Frame Max Length Register -------- */
#define GMAC_EMAC_RJFML_RESETVALUE            _UINT32_(0x2800)                                     /*  (GMAC_EMAC_RJFML) Express MAC RX Jumbo Frame Max Length Register  Reset Value */

#define GMAC_EMAC_RJFML_FML_Pos               _UINT32_(0)                                          /* (GMAC_EMAC_RJFML) Frame Max Length Position */
#define GMAC_EMAC_RJFML_FML_Msk               (_UINT32_(0x3FFF) << GMAC_EMAC_RJFML_FML_Pos)        /* (GMAC_EMAC_RJFML) Frame Max Length Mask */
#define GMAC_EMAC_RJFML_FML(value)            (GMAC_EMAC_RJFML_FML_Msk & (_UINT32_(value) << GMAC_EMAC_RJFML_FML_Pos)) /* Assigment of value for FML in the GMAC_EMAC_RJFML register */
#define GMAC_EMAC_RJFML_Msk                   _UINT32_(0x00003FFF)                                 /* (GMAC_EMAC_RJFML) Register Mask  */


/* -------- GMAC_EMAC_AMP : (GMAC Offset: 0x1054) (R/W 32) Express MAC System Bus Maximum Pipeline -------- */
#define GMAC_EMAC_AMP_RESETVALUE              _UINT32_(0x101)                                      /*  (GMAC_EMAC_AMP) Express MAC System Bus Maximum Pipeline  Reset Value */

#define GMAC_EMAC_AMP_AR2R_MAX_PIPELINE_Pos   _UINT32_(0)                                          /* (GMAC_EMAC_AMP) Address Read Bus to Read Data Bus Maximum Pipeline Position */
#define GMAC_EMAC_AMP_AR2R_MAX_PIPELINE_Msk   (_UINT32_(0xFF) << GMAC_EMAC_AMP_AR2R_MAX_PIPELINE_Pos) /* (GMAC_EMAC_AMP) Address Read Bus to Read Data Bus Maximum Pipeline Mask */
#define GMAC_EMAC_AMP_AR2R_MAX_PIPELINE(value) (GMAC_EMAC_AMP_AR2R_MAX_PIPELINE_Msk & (_UINT32_(value) << GMAC_EMAC_AMP_AR2R_MAX_PIPELINE_Pos)) /* Assigment of value for AR2R_MAX_PIPELINE in the GMAC_EMAC_AMP register */
#define GMAC_EMAC_AMP_AW2W_MAX_PIPELINE_Pos   _UINT32_(8)                                          /* (GMAC_EMAC_AMP) Address Write Bus to Write Data Bus Maximum Pipeline Position */
#define GMAC_EMAC_AMP_AW2W_MAX_PIPELINE_Msk   (_UINT32_(0xFF) << GMAC_EMAC_AMP_AW2W_MAX_PIPELINE_Pos) /* (GMAC_EMAC_AMP) Address Write Bus to Write Data Bus Maximum Pipeline Mask */
#define GMAC_EMAC_AMP_AW2W_MAX_PIPELINE(value) (GMAC_EMAC_AMP_AW2W_MAX_PIPELINE_Msk & (_UINT32_(value) << GMAC_EMAC_AMP_AW2W_MAX_PIPELINE_Pos)) /* Assigment of value for AW2W_MAX_PIPELINE in the GMAC_EMAC_AMP register */
#define GMAC_EMAC_AMP_USE_FROM_Pos            _UINT32_(16)                                         /* (GMAC_EMAC_AMP) Address Write Bus to Write Data Bus Maximum Pipeline Position */
#define GMAC_EMAC_AMP_USE_FROM_Msk            (_UINT32_(0x1) << GMAC_EMAC_AMP_USE_FROM_Pos)        /* (GMAC_EMAC_AMP) Address Write Bus to Write Data Bus Maximum Pipeline Mask */
#define GMAC_EMAC_AMP_USE_FROM(value)         (GMAC_EMAC_AMP_USE_FROM_Msk & (_UINT32_(value) << GMAC_EMAC_AMP_USE_FROM_Pos)) /* Assigment of value for USE_FROM in the GMAC_EMAC_AMP register */
#define   GMAC_EMAC_AMP_USE_FROM_AW2W_Val     _UINT32_(0x0)                                        /* (GMAC_EMAC_AMP) Operates the AW2W_MAX_PIPELINE field between AW to W channel.  */
#define   GMAC_EMAC_AMP_USE_FROM_AW2B_Val     _UINT32_(0x1)                                        /* (GMAC_EMAC_AMP) Operates the AW2W_MAX_PIPELINE field between AW to B channel.  */
#define GMAC_EMAC_AMP_USE_FROM_AW2W           (GMAC_EMAC_AMP_USE_FROM_AW2W_Val << GMAC_EMAC_AMP_USE_FROM_Pos) /* (GMAC_EMAC_AMP) Operates the AW2W_MAX_PIPELINE field between AW to W channel. Position  */
#define GMAC_EMAC_AMP_USE_FROM_AW2B           (GMAC_EMAC_AMP_USE_FROM_AW2B_Val << GMAC_EMAC_AMP_USE_FROM_Pos) /* (GMAC_EMAC_AMP) Operates the AW2W_MAX_PIPELINE field between AW to B channel. Position  */
#define GMAC_EMAC_AMP_Msk                     _UINT32_(0x0001FFFF)                                 /* (GMAC_EMAC_AMP) Register Mask  */


/* -------- GMAC_EMAC_INTM : (GMAC Offset: 0x105C) (R/W 32) Express MAC Interrupt Moderation Register -------- */
#define GMAC_EMAC_INTM_RESETVALUE             _UINT32_(0x00)                                       /*  (GMAC_EMAC_INTM) Express MAC Interrupt Moderation Register  Reset Value */

#define GMAC_EMAC_INTM_RXINTMOD_Pos           _UINT32_(0)                                          /* (GMAC_EMAC_INTM) Receive Interrupt Moderation Position */
#define GMAC_EMAC_INTM_RXINTMOD_Msk           (_UINT32_(0xFF) << GMAC_EMAC_INTM_RXINTMOD_Pos)      /* (GMAC_EMAC_INTM) Receive Interrupt Moderation Mask */
#define GMAC_EMAC_INTM_RXINTMOD(value)        (GMAC_EMAC_INTM_RXINTMOD_Msk & (_UINT32_(value) << GMAC_EMAC_INTM_RXINTMOD_Pos)) /* Assigment of value for RXINTMOD in the GMAC_EMAC_INTM register */
#define GMAC_EMAC_INTM_TXINTMOD_Pos           _UINT32_(16)                                         /* (GMAC_EMAC_INTM) Transmit Interrupt Moderation Position */
#define GMAC_EMAC_INTM_TXINTMOD_Msk           (_UINT32_(0xFF) << GMAC_EMAC_INTM_TXINTMOD_Pos)      /* (GMAC_EMAC_INTM) Transmit Interrupt Moderation Mask */
#define GMAC_EMAC_INTM_TXINTMOD(value)        (GMAC_EMAC_INTM_TXINTMOD_Msk & (_UINT32_(value) << GMAC_EMAC_INTM_TXINTMOD_Pos)) /* Assigment of value for TXINTMOD in the GMAC_EMAC_INTM register */
#define GMAC_EMAC_INTM_Msk                    _UINT32_(0x00FF00FF)                                 /* (GMAC_EMAC_INTM) Register Mask  */


/* -------- GMAC_EMAC_SYSWT : (GMAC Offset: 0x1060) (R/W 32) Express MAC System Wake-Up Time Register -------- */
#define GMAC_EMAC_SYSWT_RESETVALUE            _UINT32_(0x00)                                       /*  (GMAC_EMAC_SYSWT) Express MAC System Wake-Up Time Register  Reset Value */

#define GMAC_EMAC_SYSWT_SYSWKUPTIME_Pos       _UINT32_(0)                                          /* (GMAC_EMAC_SYSWT) System Wake-up Time Position */
#define GMAC_EMAC_SYSWT_SYSWKUPTIME_Msk       (_UINT32_(0xFFFF) << GMAC_EMAC_SYSWT_SYSWKUPTIME_Pos) /* (GMAC_EMAC_SYSWT) System Wake-up Time Mask */
#define GMAC_EMAC_SYSWT_SYSWKUPTIME(value)    (GMAC_EMAC_SYSWT_SYSWKUPTIME_Msk & (_UINT32_(value) << GMAC_EMAC_SYSWT_SYSWKUPTIME_Pos)) /* Assigment of value for SYSWKUPTIME in the GMAC_EMAC_SYSWT register */
#define GMAC_EMAC_SYSWT_Msk                   _UINT32_(0x0000FFFF)                                 /* (GMAC_EMAC_SYSWT) Register Mask  */


/* -------- GMAC_EMAC_LCKUP_CFGR : (GMAC Offset: 0x1068) (R/W 32) Express MAC Lockup Detection and Recovery Configuration -------- */
#define GMAC_EMAC_LCKUP_CFGR_RESETVALUE       _UINT32_(0x7FFFFFF)                                  /*  (GMAC_EMAC_LCKUP_CFGR) Express MAC Lockup Detection and Recovery Configuration  Reset Value */

#define GMAC_EMAC_LCKUP_CFGR_PRESCALER_Pos    _UINT32_(0)                                          /* (GMAC_EMAC_LCKUP_CFGR) Prescaler Value for Timeout Position */
#define GMAC_EMAC_LCKUP_CFGR_PRESCALER_Msk    (_UINT32_(0xFFFF) << GMAC_EMAC_LCKUP_CFGR_PRESCALER_Pos) /* (GMAC_EMAC_LCKUP_CFGR) Prescaler Value for Timeout Mask */
#define GMAC_EMAC_LCKUP_CFGR_PRESCALER(value) (GMAC_EMAC_LCKUP_CFGR_PRESCALER_Msk & (_UINT32_(value) << GMAC_EMAC_LCKUP_CFGR_PRESCALER_Pos)) /* Assigment of value for PRESCALER in the GMAC_EMAC_LCKUP_CFGR register */
#define GMAC_EMAC_LCKUP_CFGR_DMA_LOCKUP_TIME_Pos _UINT32_(16)                                         /* (GMAC_EMAC_LCKUP_CFGR) Timeout Value for Receive and Transmit DMA Position */
#define GMAC_EMAC_LCKUP_CFGR_DMA_LOCKUP_TIME_Msk (_UINT32_(0x7FF) << GMAC_EMAC_LCKUP_CFGR_DMA_LOCKUP_TIME_Pos) /* (GMAC_EMAC_LCKUP_CFGR) Timeout Value for Receive and Transmit DMA Mask */
#define GMAC_EMAC_LCKUP_CFGR_DMA_LOCKUP_TIME(value) (GMAC_EMAC_LCKUP_CFGR_DMA_LOCKUP_TIME_Msk & (_UINT32_(value) << GMAC_EMAC_LCKUP_CFGR_DMA_LOCKUP_TIME_Pos)) /* Assigment of value for DMA_LOCKUP_TIME in the GMAC_EMAC_LCKUP_CFGR register */
#define GMAC_EMAC_LCKUP_CFGR_LCKUP_REC_EN_Pos _UINT32_(27)                                         /* (GMAC_EMAC_LCKUP_CFGR) Lockup RecoveryEnable Position */
#define GMAC_EMAC_LCKUP_CFGR_LCKUP_REC_EN_Msk (_UINT32_(0x1) << GMAC_EMAC_LCKUP_CFGR_LCKUP_REC_EN_Pos) /* (GMAC_EMAC_LCKUP_CFGR) Lockup RecoveryEnable Mask */
#define GMAC_EMAC_LCKUP_CFGR_LCKUP_REC_EN(value) (GMAC_EMAC_LCKUP_CFGR_LCKUP_REC_EN_Msk & (_UINT32_(value) << GMAC_EMAC_LCKUP_CFGR_LCKUP_REC_EN_Pos)) /* Assigment of value for LCKUP_REC_EN in the GMAC_EMAC_LCKUP_CFGR register */
#define   GMAC_EMAC_LCKUP_CFGR_LCKUP_REC_EN_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_LCKUP_CFGR) No effect.  */
#define   GMAC_EMAC_LCKUP_CFGR_LCKUP_REC_EN_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_LCKUP_CFGR) Forces the EMAC in Reset mode when a lockup.is detected on the transmit or receive data paths.  */
#define GMAC_EMAC_LCKUP_CFGR_LCKUP_REC_EN_0   (GMAC_EMAC_LCKUP_CFGR_LCKUP_REC_EN_0_Val << GMAC_EMAC_LCKUP_CFGR_LCKUP_REC_EN_Pos) /* (GMAC_EMAC_LCKUP_CFGR) No effect. Position  */
#define GMAC_EMAC_LCKUP_CFGR_LCKUP_REC_EN_1   (GMAC_EMAC_LCKUP_CFGR_LCKUP_REC_EN_1_Val << GMAC_EMAC_LCKUP_CFGR_LCKUP_REC_EN_Pos) /* (GMAC_EMAC_LCKUP_CFGR) Forces the EMAC in Reset mode when a lockup.is detected on the transmit or receive data paths. Position  */
#define GMAC_EMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_Pos _UINT32_(28)                                         /* (GMAC_EMAC_LCKUP_CFGR) Receive MAC Lockup Detector Enable Position */
#define GMAC_EMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_Msk (_UINT32_(0x1) << GMAC_EMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_Pos) /* (GMAC_EMAC_LCKUP_CFGR) Receive MAC Lockup Detector Enable Mask */
#define GMAC_EMAC_LCKUP_CFGR_RXMAC_LCKUP_EN(value) (GMAC_EMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_Msk & (_UINT32_(value) << GMAC_EMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_Pos)) /* Assigment of value for RXMAC_LCKUP_EN in the GMAC_EMAC_LCKUP_CFGR register */
#define   GMAC_EMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_LCKUP_CFGR) Disables the monitor that detects lockups in the receive MAC.  */
#define   GMAC_EMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_LCKUP_CFGR) Enables the monitor that detects lockups in the receive MAC.  */
#define GMAC_EMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_0 (GMAC_EMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_0_Val << GMAC_EMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_Pos) /* (GMAC_EMAC_LCKUP_CFGR) Disables the monitor that detects lockups in the receive MAC. Position  */
#define GMAC_EMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_1 (GMAC_EMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_1_Val << GMAC_EMAC_LCKUP_CFGR_RXMAC_LCKUP_EN_Pos) /* (GMAC_EMAC_LCKUP_CFGR) Enables the monitor that detects lockups in the receive MAC. Position  */
#define GMAC_EMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_Pos _UINT32_(29)                                         /* (GMAC_EMAC_LCKUP_CFGR) Receive DMA Lockup Detector Enable Position */
#define GMAC_EMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_Msk (_UINT32_(0x1) << GMAC_EMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_Pos) /* (GMAC_EMAC_LCKUP_CFGR) Receive DMA Lockup Detector Enable Mask */
#define GMAC_EMAC_LCKUP_CFGR_RXDMA_LCKUP_EN(value) (GMAC_EMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_Msk & (_UINT32_(value) << GMAC_EMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_Pos)) /* Assigment of value for RXDMA_LCKUP_EN in the GMAC_EMAC_LCKUP_CFGR register */
#define   GMAC_EMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_LCKUP_CFGR) Disables the monitor that detects lockups in the receive DMA.  */
#define   GMAC_EMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_LCKUP_CFGR) Enables the monitor that detects lockups in the receive DMA.  */
#define GMAC_EMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_0 (GMAC_EMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_0_Val << GMAC_EMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_Pos) /* (GMAC_EMAC_LCKUP_CFGR) Disables the monitor that detects lockups in the receive DMA. Position  */
#define GMAC_EMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_1 (GMAC_EMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_1_Val << GMAC_EMAC_LCKUP_CFGR_RXDMA_LCKUP_EN_Pos) /* (GMAC_EMAC_LCKUP_CFGR) Enables the monitor that detects lockups in the receive DMA. Position  */
#define GMAC_EMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_Pos _UINT32_(30)                                         /* (GMAC_EMAC_LCKUP_CFGR) Transmit MAC Lockup Detector Enable Position */
#define GMAC_EMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_Msk (_UINT32_(0x1) << GMAC_EMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_Pos) /* (GMAC_EMAC_LCKUP_CFGR) Transmit MAC Lockup Detector Enable Mask */
#define GMAC_EMAC_LCKUP_CFGR_TXMAC_LCKUP_EN(value) (GMAC_EMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_Msk & (_UINT32_(value) << GMAC_EMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_Pos)) /* Assigment of value for TXMAC_LCKUP_EN in the GMAC_EMAC_LCKUP_CFGR register */
#define   GMAC_EMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_LCKUP_CFGR) Disables the monitor that detects lockups in the transmit MAC.  */
#define   GMAC_EMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_LCKUP_CFGR) Enables the monitor that detects lockups in the transmit MAC.  */
#define GMAC_EMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_0 (GMAC_EMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_0_Val << GMAC_EMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_Pos) /* (GMAC_EMAC_LCKUP_CFGR) Disables the monitor that detects lockups in the transmit MAC. Position  */
#define GMAC_EMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_1 (GMAC_EMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_1_Val << GMAC_EMAC_LCKUP_CFGR_TXMAC_LCKUP_EN_Pos) /* (GMAC_EMAC_LCKUP_CFGR) Enables the monitor that detects lockups in the transmit MAC. Position  */
#define GMAC_EMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_Pos _UINT32_(31)                                         /* (GMAC_EMAC_LCKUP_CFGR) Transmit DMA Lockup Detector Enable Position */
#define GMAC_EMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_Msk (_UINT32_(0x1) << GMAC_EMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_Pos) /* (GMAC_EMAC_LCKUP_CFGR) Transmit DMA Lockup Detector Enable Mask */
#define GMAC_EMAC_LCKUP_CFGR_TXDMA_LCKUP_EN(value) (GMAC_EMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_Msk & (_UINT32_(value) << GMAC_EMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_Pos)) /* Assigment of value for TXDMA_LCKUP_EN in the GMAC_EMAC_LCKUP_CFGR register */
#define   GMAC_EMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_LCKUP_CFGR) Disables the monitor that detects lockups in the transmit DMA.  */
#define   GMAC_EMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_LCKUP_CFGR) Enables the monitor that detects lockups in the transmit DMA.  */
#define GMAC_EMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_0 (GMAC_EMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_0_Val << GMAC_EMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_Pos) /* (GMAC_EMAC_LCKUP_CFGR) Disables the monitor that detects lockups in the transmit DMA. Position  */
#define GMAC_EMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_1 (GMAC_EMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_1_Val << GMAC_EMAC_LCKUP_CFGR_TXDMA_LCKUP_EN_Pos) /* (GMAC_EMAC_LCKUP_CFGR) Enables the monitor that detects lockups in the transmit DMA. Position  */
#define GMAC_EMAC_LCKUP_CFGR_Msk              _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_LCKUP_CFGR) Register Mask  */


/* -------- GMAC_EMAC_LCKUP_TIME : (GMAC Offset: 0x106C) (R/W 32) Express MAC Lockup Detection Time -------- */
#define GMAC_EMAC_LCKUP_TIME_RESETVALUE       _UINT32_(0x7FFFFFF)                                  /*  (GMAC_EMAC_LCKUP_TIME) Express MAC Lockup Detection Time  Reset Value */

#define GMAC_EMAC_LCKUP_TIME_RX_MAC_LOCKUP_TIME_Pos _UINT32_(0)                                          /* (GMAC_EMAC_LCKUP_TIME) Receive MAC Lockup Detector Time Position */
#define GMAC_EMAC_LCKUP_TIME_RX_MAC_LOCKUP_TIME_Msk (_UINT32_(0xFFFF) << GMAC_EMAC_LCKUP_TIME_RX_MAC_LOCKUP_TIME_Pos) /* (GMAC_EMAC_LCKUP_TIME) Receive MAC Lockup Detector Time Mask */
#define GMAC_EMAC_LCKUP_TIME_RX_MAC_LOCKUP_TIME(value) (GMAC_EMAC_LCKUP_TIME_RX_MAC_LOCKUP_TIME_Msk & (_UINT32_(value) << GMAC_EMAC_LCKUP_TIME_RX_MAC_LOCKUP_TIME_Pos)) /* Assigment of value for RX_MAC_LOCKUP_TIME in the GMAC_EMAC_LCKUP_TIME register */
#define GMAC_EMAC_LCKUP_TIME_TX_MAC_LOCKUP_TIME_Pos _UINT32_(16)                                         /* (GMAC_EMAC_LCKUP_TIME) Transmit MAC Lockup Detector Time Position */
#define GMAC_EMAC_LCKUP_TIME_TX_MAC_LOCKUP_TIME_Msk (_UINT32_(0x7FF) << GMAC_EMAC_LCKUP_TIME_TX_MAC_LOCKUP_TIME_Pos) /* (GMAC_EMAC_LCKUP_TIME) Transmit MAC Lockup Detector Time Mask */
#define GMAC_EMAC_LCKUP_TIME_TX_MAC_LOCKUP_TIME(value) (GMAC_EMAC_LCKUP_TIME_TX_MAC_LOCKUP_TIME_Msk & (_UINT32_(value) << GMAC_EMAC_LCKUP_TIME_TX_MAC_LOCKUP_TIME_Pos)) /* Assigment of value for TX_MAC_LOCKUP_TIME in the GMAC_EMAC_LCKUP_TIME register */
#define GMAC_EMAC_LCKUP_TIME_Msk              _UINT32_(0x07FFFFFF)                                 /* (GMAC_EMAC_LCKUP_TIME) Register Mask  */


/* -------- GMAC_EMAC_TXDMA_LCKUP_CR : (GMAC Offset: 0x1070) (R/W 32) Express MAC Transmit DMA Lockup Control Register -------- */
#define GMAC_EMAC_TXDMA_LCKUP_CR_RESETVALUE   _UINT32_(0x7FFFFFF)                                  /*  (GMAC_EMAC_TXDMA_LCKUP_CR) Express MAC Transmit DMA Lockup Control Register  Reset Value */

#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_Pos _UINT32_(0)                                          /* (GMAC_EMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Detector Enable for Queue 0 Position */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_Msk (_UINT32_(0x1) << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_Pos) /* (GMAC_EMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Detector Enable for Queue 0 Mask */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0(value) (GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_Msk & (_UINT32_(value) << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_Pos)) /* Assigment of value for LCKUP_EN_Q0 in the GMAC_EMAC_TXDMA_LCKUP_CR register */
#define   GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_TXDMA_LCKUP_CR) Disables the transmit DMA lockup timer for queue x. The number of outstanding packets are still counted but the actual timer does not run.  */
#define   GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_TXDMA_LCKUP_CR) Enables the transmit DMA lockup timer for queue x.  */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_0 (GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_0_Val << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_Pos) /* (GMAC_EMAC_TXDMA_LCKUP_CR) Disables the transmit DMA lockup timer for queue x. The number of outstanding packets are still counted but the actual timer does not run. Position  */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_1 (GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_1_Val << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q0_Pos) /* (GMAC_EMAC_TXDMA_LCKUP_CR) Enables the transmit DMA lockup timer for queue x. Position  */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_Pos _UINT32_(1)                                          /* (GMAC_EMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Detector Enable for Queue 1 Position */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_Msk (_UINT32_(0x1) << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_Pos) /* (GMAC_EMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Detector Enable for Queue 1 Mask */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1(value) (GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_Msk & (_UINT32_(value) << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_Pos)) /* Assigment of value for LCKUP_EN_Q1 in the GMAC_EMAC_TXDMA_LCKUP_CR register */
#define   GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_TXDMA_LCKUP_CR) Disables the transmit DMA lockup timer for queue x. The number of outstanding packets are still counted but the actual timer does not run.  */
#define   GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_TXDMA_LCKUP_CR) Enables the transmit DMA lockup timer for queue x.  */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_0 (GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_0_Val << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_Pos) /* (GMAC_EMAC_TXDMA_LCKUP_CR) Disables the transmit DMA lockup timer for queue x. The number of outstanding packets are still counted but the actual timer does not run. Position  */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_1 (GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_1_Val << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q1_Pos) /* (GMAC_EMAC_TXDMA_LCKUP_CR) Enables the transmit DMA lockup timer for queue x. Position  */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_Pos _UINT32_(2)                                          /* (GMAC_EMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Detector Enable for Queue 2 Position */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_Msk (_UINT32_(0x1) << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_Pos) /* (GMAC_EMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Detector Enable for Queue 2 Mask */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2(value) (GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_Msk & (_UINT32_(value) << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_Pos)) /* Assigment of value for LCKUP_EN_Q2 in the GMAC_EMAC_TXDMA_LCKUP_CR register */
#define   GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_TXDMA_LCKUP_CR) Disables the transmit DMA lockup timer for queue x. The number of outstanding packets are still counted but the actual timer does not run.  */
#define   GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_TXDMA_LCKUP_CR) Enables the transmit DMA lockup timer for queue x.  */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_0 (GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_0_Val << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_Pos) /* (GMAC_EMAC_TXDMA_LCKUP_CR) Disables the transmit DMA lockup timer for queue x. The number of outstanding packets are still counted but the actual timer does not run. Position  */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_1 (GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_1_Val << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q2_Pos) /* (GMAC_EMAC_TXDMA_LCKUP_CR) Enables the transmit DMA lockup timer for queue x. Position  */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_Pos _UINT32_(3)                                          /* (GMAC_EMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Detector Enable for Queue 3 Position */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_Msk (_UINT32_(0x1) << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_Pos) /* (GMAC_EMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Detector Enable for Queue 3 Mask */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3(value) (GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_Msk & (_UINT32_(value) << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_Pos)) /* Assigment of value for LCKUP_EN_Q3 in the GMAC_EMAC_TXDMA_LCKUP_CR register */
#define   GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_TXDMA_LCKUP_CR) Disables the transmit DMA lockup timer for queue x. The number of outstanding packets are still counted but the actual timer does not run.  */
#define   GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_TXDMA_LCKUP_CR) Enables the transmit DMA lockup timer for queue x.  */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_0 (GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_0_Val << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_Pos) /* (GMAC_EMAC_TXDMA_LCKUP_CR) Disables the transmit DMA lockup timer for queue x. The number of outstanding packets are still counted but the actual timer does not run. Position  */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_1 (GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_1_Val << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q3_Pos) /* (GMAC_EMAC_TXDMA_LCKUP_CR) Enables the transmit DMA lockup timer for queue x. Position  */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_Pos _UINT32_(4)                                          /* (GMAC_EMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Detector Enable for Queue 4 Position */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_Msk (_UINT32_(0x1) << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_Pos) /* (GMAC_EMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Detector Enable for Queue 4 Mask */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4(value) (GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_Msk & (_UINT32_(value) << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_Pos)) /* Assigment of value for LCKUP_EN_Q4 in the GMAC_EMAC_TXDMA_LCKUP_CR register */
#define   GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_TXDMA_LCKUP_CR) Disables the transmit DMA lockup timer for queue x. The number of outstanding packets are still counted but the actual timer does not run.  */
#define   GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_TXDMA_LCKUP_CR) Enables the transmit DMA lockup timer for queue x.  */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_0 (GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_0_Val << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_Pos) /* (GMAC_EMAC_TXDMA_LCKUP_CR) Disables the transmit DMA lockup timer for queue x. The number of outstanding packets are still counted but the actual timer does not run. Position  */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_1 (GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_1_Val << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q4_Pos) /* (GMAC_EMAC_TXDMA_LCKUP_CR) Enables the transmit DMA lockup timer for queue x. Position  */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_Pos _UINT32_(5)                                          /* (GMAC_EMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Detector Enable for Queue 5 Position */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_Msk (_UINT32_(0x1) << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_Pos) /* (GMAC_EMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Detector Enable for Queue 5 Mask */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5(value) (GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_Msk & (_UINT32_(value) << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_Pos)) /* Assigment of value for LCKUP_EN_Q5 in the GMAC_EMAC_TXDMA_LCKUP_CR register */
#define   GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_TXDMA_LCKUP_CR) Disables the transmit DMA lockup timer for queue x. The number of outstanding packets are still counted but the actual timer does not run.  */
#define   GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_TXDMA_LCKUP_CR) Enables the transmit DMA lockup timer for queue x.  */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_0 (GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_0_Val << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_Pos) /* (GMAC_EMAC_TXDMA_LCKUP_CR) Disables the transmit DMA lockup timer for queue x. The number of outstanding packets are still counted but the actual timer does not run. Position  */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_1 (GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_1_Val << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q5_Pos) /* (GMAC_EMAC_TXDMA_LCKUP_CR) Enables the transmit DMA lockup timer for queue x. Position  */
#define GMAC_EMAC_TXDMA_LCKUP_CR_Msk          _UINT32_(0x0000003F)                                 /* (GMAC_EMAC_TXDMA_LCKUP_CR) Register Mask  */

#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q_Pos _UINT32_(0)                                          /* (GMAC_EMAC_TXDMA_LCKUP_CR Position) Transmit DMA Lockup Detector Enable for Queue 5 */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q_Msk (_UINT32_(0x3F) << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q_Pos) /* (GMAC_EMAC_TXDMA_LCKUP_CR Mask) LCKUP_EN_Q */
#define GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q(value) (GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q_Msk & (_UINT32_(value) << GMAC_EMAC_TXDMA_LCKUP_CR_LCKUP_EN_Q_Pos)) 

/* -------- GMAC_EMAC_RX_WATERMARK : (GMAC Offset: 0x107C) (R/W 32) Express MAC Receive Watermark Register -------- */
#define GMAC_EMAC_RX_WATERMARK_RESETVALUE     _UINT32_(0x00)                                       /*  (GMAC_EMAC_RX_WATERMARK) Express MAC Receive Watermark Register  Reset Value */

#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK0_Pos _UINT32_(0)                                          /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 0 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK0_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK0_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 0 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK0(value) (GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK0_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK0_Pos)) /* Assigment of value for RX_HIGH_WATERMARK0 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK1_Pos _UINT32_(1)                                          /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 1 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK1_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK1_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 1 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK1(value) (GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK1_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK1_Pos)) /* Assigment of value for RX_HIGH_WATERMARK1 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK2_Pos _UINT32_(2)                                          /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 2 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK2_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK2_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 2 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK2(value) (GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK2_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK2_Pos)) /* Assigment of value for RX_HIGH_WATERMARK2 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK3_Pos _UINT32_(3)                                          /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 3 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK3_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK3_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 3 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK3(value) (GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK3_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK3_Pos)) /* Assigment of value for RX_HIGH_WATERMARK3 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK4_Pos _UINT32_(4)                                          /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 4 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK4_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK4_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 4 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK4(value) (GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK4_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK4_Pos)) /* Assigment of value for RX_HIGH_WATERMARK4 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK5_Pos _UINT32_(5)                                          /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 5 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK5_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK5_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 5 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK5(value) (GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK5_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK5_Pos)) /* Assigment of value for RX_HIGH_WATERMARK5 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK6_Pos _UINT32_(6)                                          /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 6 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK6_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK6_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 6 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK6(value) (GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK6_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK6_Pos)) /* Assigment of value for RX_HIGH_WATERMARK6 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK7_Pos _UINT32_(7)                                          /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 7 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK7_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK7_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 7 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK7(value) (GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK7_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK7_Pos)) /* Assigment of value for RX_HIGH_WATERMARK7 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK8_Pos _UINT32_(8)                                          /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 8 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK8_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK8_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 8 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK8(value) (GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK8_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK8_Pos)) /* Assigment of value for RX_HIGH_WATERMARK8 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK9_Pos _UINT32_(9)                                          /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 9 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK9_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK9_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 9 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK9(value) (GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK9_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK9_Pos)) /* Assigment of value for RX_HIGH_WATERMARK9 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK10_Pos _UINT32_(10)                                         /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 10 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK10_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK10_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 10 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK10(value) (GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK10_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK10_Pos)) /* Assigment of value for RX_HIGH_WATERMARK10 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK11_Pos _UINT32_(11)                                         /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 11 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK11_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK11_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 11 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK11(value) (GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK11_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK11_Pos)) /* Assigment of value for RX_HIGH_WATERMARK11 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK12_Pos _UINT32_(12)                                         /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 12 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK12_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK12_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 12 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK12(value) (GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK12_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK12_Pos)) /* Assigment of value for RX_HIGH_WATERMARK12 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK13_Pos _UINT32_(13)                                         /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 13 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK13_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK13_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 13 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK13(value) (GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK13_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK13_Pos)) /* Assigment of value for RX_HIGH_WATERMARK13 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK14_Pos _UINT32_(14)                                         /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 14 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK14_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK14_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 14 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK14(value) (GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK14_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK14_Pos)) /* Assigment of value for RX_HIGH_WATERMARK14 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK15_Pos _UINT32_(15)                                         /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 15 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK15_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK15_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 15 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK15(value) (GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK15_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK15_Pos)) /* Assigment of value for RX_HIGH_WATERMARK15 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK0_Pos _UINT32_(16)                                         /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 0 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK0_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK0_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 0 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK0(value) (GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK0_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK0_Pos)) /* Assigment of value for RX_LOW_WATERMARK0 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK1_Pos _UINT32_(17)                                         /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 1 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK1_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK1_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 1 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK1(value) (GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK1_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK1_Pos)) /* Assigment of value for RX_LOW_WATERMARK1 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK2_Pos _UINT32_(18)                                         /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 2 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK2_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK2_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 2 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK2(value) (GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK2_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK2_Pos)) /* Assigment of value for RX_LOW_WATERMARK2 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK3_Pos _UINT32_(19)                                         /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 3 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK3_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK3_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 3 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK3(value) (GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK3_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK3_Pos)) /* Assigment of value for RX_LOW_WATERMARK3 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK4_Pos _UINT32_(20)                                         /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 4 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK4_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK4_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 4 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK4(value) (GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK4_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK4_Pos)) /* Assigment of value for RX_LOW_WATERMARK4 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK5_Pos _UINT32_(21)                                         /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 5 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK5_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK5_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 5 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK5(value) (GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK5_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK5_Pos)) /* Assigment of value for RX_LOW_WATERMARK5 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK6_Pos _UINT32_(22)                                         /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 6 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK6_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK6_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 6 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK6(value) (GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK6_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK6_Pos)) /* Assigment of value for RX_LOW_WATERMARK6 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK7_Pos _UINT32_(23)                                         /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 7 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK7_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK7_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 7 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK7(value) (GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK7_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK7_Pos)) /* Assigment of value for RX_LOW_WATERMARK7 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK8_Pos _UINT32_(24)                                         /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 8 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK8_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK8_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 8 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK8(value) (GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK8_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK8_Pos)) /* Assigment of value for RX_LOW_WATERMARK8 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK9_Pos _UINT32_(25)                                         /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 9 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK9_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK9_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 9 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK9(value) (GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK9_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK9_Pos)) /* Assigment of value for RX_LOW_WATERMARK9 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK10_Pos _UINT32_(26)                                         /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 10 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK10_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK10_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 10 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK10(value) (GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK10_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK10_Pos)) /* Assigment of value for RX_LOW_WATERMARK10 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK11_Pos _UINT32_(27)                                         /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 11 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK11_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK11_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 11 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK11(value) (GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK11_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK11_Pos)) /* Assigment of value for RX_LOW_WATERMARK11 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK12_Pos _UINT32_(28)                                         /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 12 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK12_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK12_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 12 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK12(value) (GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK12_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK12_Pos)) /* Assigment of value for RX_LOW_WATERMARK12 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK13_Pos _UINT32_(29)                                         /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 13 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK13_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK13_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 13 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK13(value) (GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK13_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK13_Pos)) /* Assigment of value for RX_LOW_WATERMARK13 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK14_Pos _UINT32_(30)                                         /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 14 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK14_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK14_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 14 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK14(value) (GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK14_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK14_Pos)) /* Assigment of value for RX_LOW_WATERMARK14 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK15_Pos _UINT32_(31)                                         /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 15 Position */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK15_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK15_Pos) /* (GMAC_EMAC_RX_WATERMARK) Transmit DMA Lockup Detector Enable for Queue 15 Mask */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK15(value) (GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK15_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK15_Pos)) /* Assigment of value for RX_LOW_WATERMARK15 in the GMAC_EMAC_RX_WATERMARK register */
#define GMAC_EMAC_RX_WATERMARK_Msk            _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_RX_WATERMARK) Register Mask  */

#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK_Pos _UINT32_(0)                                          /* (GMAC_EMAC_RX_WATERMARK Position) Transmit DMA Lockup Detector Enable for Queue x */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK_Msk (_UINT32_(0xFFFF) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK_Pos) /* (GMAC_EMAC_RX_WATERMARK Mask) RX_HIGH_WATERMARK */
#define GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK(value) (GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_HIGH_WATERMARK_Pos)) 
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK_Pos _UINT32_(16)                                         /* (GMAC_EMAC_RX_WATERMARK Position) Transmit DMA Lockup Detector Enable for Queue x5 */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK_Msk (_UINT32_(0xFFFF) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK_Pos) /* (GMAC_EMAC_RX_WATERMARK Mask) RX_LOW_WATERMARK */
#define GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK(value) (GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK_Msk & (_UINT32_(value) << GMAC_EMAC_RX_WATERMARK_RX_LOW_WATERMARK_Pos)) 

/* -------- GMAC_EMAC_HRB : (GMAC Offset: 0x1080) (R/W 32) Express MAC Hash Register Bottom -------- */
#define GMAC_EMAC_HRB_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_HRB) Express MAC Hash Register Bottom  Reset Value */

#define GMAC_EMAC_HRB_ADDR_Pos                _UINT32_(0)                                          /* (GMAC_EMAC_HRB) Hash Address Position */
#define GMAC_EMAC_HRB_ADDR_Msk                (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_HRB_ADDR_Pos)     /* (GMAC_EMAC_HRB) Hash Address Mask */
#define GMAC_EMAC_HRB_ADDR(value)             (GMAC_EMAC_HRB_ADDR_Msk & (_UINT32_(value) << GMAC_EMAC_HRB_ADDR_Pos)) /* Assigment of value for ADDR in the GMAC_EMAC_HRB register */
#define GMAC_EMAC_HRB_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_HRB) Register Mask  */


/* -------- GMAC_EMAC_HRT : (GMAC Offset: 0x1084) (R/W 32) Express MAC Hash Register Top -------- */
#define GMAC_EMAC_HRT_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_HRT) Express MAC Hash Register Top  Reset Value */

#define GMAC_EMAC_HRT_ADDR_Pos                _UINT32_(0)                                          /* (GMAC_EMAC_HRT) Hash Address Position */
#define GMAC_EMAC_HRT_ADDR_Msk                (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_HRT_ADDR_Pos)     /* (GMAC_EMAC_HRT) Hash Address Mask */
#define GMAC_EMAC_HRT_ADDR(value)             (GMAC_EMAC_HRT_ADDR_Msk & (_UINT32_(value) << GMAC_EMAC_HRT_ADDR_Pos)) /* Assigment of value for ADDR in the GMAC_EMAC_HRT register */
#define GMAC_EMAC_HRT_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_HRT) Register Mask  */


/* -------- GMAC_EMAC_TIDM1 : (GMAC Offset: 0x10A8) (R/W 32) Express MAC Type ID Match 1 Register -------- */
#define GMAC_EMAC_TIDM1_RESETVALUE            _UINT32_(0x00)                                       /*  (GMAC_EMAC_TIDM1) Express MAC Type ID Match 1 Register  Reset Value */

#define GMAC_EMAC_TIDM1_TID_Pos               _UINT32_(0)                                          /* (GMAC_EMAC_TIDM1) Type ID Match 1 Position */
#define GMAC_EMAC_TIDM1_TID_Msk               (_UINT32_(0xFFFF) << GMAC_EMAC_TIDM1_TID_Pos)        /* (GMAC_EMAC_TIDM1) Type ID Match 1 Mask */
#define GMAC_EMAC_TIDM1_TID(value)            (GMAC_EMAC_TIDM1_TID_Msk & (_UINT32_(value) << GMAC_EMAC_TIDM1_TID_Pos)) /* Assigment of value for TID in the GMAC_EMAC_TIDM1 register */
#define GMAC_EMAC_TIDM1_ENID1_Pos             _UINT32_(31)                                         /* (GMAC_EMAC_TIDM1) Enable Copying of TID Matched Frames Position */
#define GMAC_EMAC_TIDM1_ENID1_Msk             (_UINT32_(0x1) << GMAC_EMAC_TIDM1_ENID1_Pos)         /* (GMAC_EMAC_TIDM1) Enable Copying of TID Matched Frames Mask */
#define GMAC_EMAC_TIDM1_ENID1(value)          (GMAC_EMAC_TIDM1_ENID1_Msk & (_UINT32_(value) << GMAC_EMAC_TIDM1_ENID1_Pos)) /* Assigment of value for ENID1 in the GMAC_EMAC_TIDM1 register */
#define   GMAC_EMAC_TIDM1_ENID1_0_Val         _UINT32_(0x0)                                        /* (GMAC_EMAC_TIDM1) TID is not part of the comparison match.  */
#define   GMAC_EMAC_TIDM1_ENID1_1_Val         _UINT32_(0x1)                                        /* (GMAC_EMAC_TIDM1) TID is processed for the comparison match.  */
#define GMAC_EMAC_TIDM1_ENID1_0               (GMAC_EMAC_TIDM1_ENID1_0_Val << GMAC_EMAC_TIDM1_ENID1_Pos) /* (GMAC_EMAC_TIDM1) TID is not part of the comparison match. Position  */
#define GMAC_EMAC_TIDM1_ENID1_1               (GMAC_EMAC_TIDM1_ENID1_1_Val << GMAC_EMAC_TIDM1_ENID1_Pos) /* (GMAC_EMAC_TIDM1) TID is processed for the comparison match. Position  */
#define GMAC_EMAC_TIDM1_Msk                   _UINT32_(0x8000FFFF)                                 /* (GMAC_EMAC_TIDM1) Register Mask  */

#define GMAC_EMAC_TIDM1_ENID_Pos              _UINT32_(31)                                         /* (GMAC_EMAC_TIDM1 Position) Enable Copying of TID Matched Frames */
#define GMAC_EMAC_TIDM1_ENID_Msk              (_UINT32_(0x1) << GMAC_EMAC_TIDM1_ENID_Pos)          /* (GMAC_EMAC_TIDM1 Mask) ENID */
#define GMAC_EMAC_TIDM1_ENID(value)           (GMAC_EMAC_TIDM1_ENID_Msk & (_UINT32_(value) << GMAC_EMAC_TIDM1_ENID_Pos)) 

/* -------- GMAC_EMAC_TIDM2 : (GMAC Offset: 0x10AC) (R/W 32) Express MAC Type ID Match 2 Register -------- */
#define GMAC_EMAC_TIDM2_RESETVALUE            _UINT32_(0x00)                                       /*  (GMAC_EMAC_TIDM2) Express MAC Type ID Match 2 Register  Reset Value */

#define GMAC_EMAC_TIDM2_TID_Pos               _UINT32_(0)                                          /* (GMAC_EMAC_TIDM2) Type ID Match 2 Position */
#define GMAC_EMAC_TIDM2_TID_Msk               (_UINT32_(0xFFFF) << GMAC_EMAC_TIDM2_TID_Pos)        /* (GMAC_EMAC_TIDM2) Type ID Match 2 Mask */
#define GMAC_EMAC_TIDM2_TID(value)            (GMAC_EMAC_TIDM2_TID_Msk & (_UINT32_(value) << GMAC_EMAC_TIDM2_TID_Pos)) /* Assigment of value for TID in the GMAC_EMAC_TIDM2 register */
#define GMAC_EMAC_TIDM2_ENID2_Pos             _UINT32_(31)                                         /* (GMAC_EMAC_TIDM2) Enable Copying of TID Matched Frames Position */
#define GMAC_EMAC_TIDM2_ENID2_Msk             (_UINT32_(0x1) << GMAC_EMAC_TIDM2_ENID2_Pos)         /* (GMAC_EMAC_TIDM2) Enable Copying of TID Matched Frames Mask */
#define GMAC_EMAC_TIDM2_ENID2(value)          (GMAC_EMAC_TIDM2_ENID2_Msk & (_UINT32_(value) << GMAC_EMAC_TIDM2_ENID2_Pos)) /* Assigment of value for ENID2 in the GMAC_EMAC_TIDM2 register */
#define   GMAC_EMAC_TIDM2_ENID2_0_Val         _UINT32_(0x0)                                        /* (GMAC_EMAC_TIDM2) TID is not part of the comparison match.  */
#define   GMAC_EMAC_TIDM2_ENID2_1_Val         _UINT32_(0x1)                                        /* (GMAC_EMAC_TIDM2) TID is processed for the comparison match.  */
#define GMAC_EMAC_TIDM2_ENID2_0               (GMAC_EMAC_TIDM2_ENID2_0_Val << GMAC_EMAC_TIDM2_ENID2_Pos) /* (GMAC_EMAC_TIDM2) TID is not part of the comparison match. Position  */
#define GMAC_EMAC_TIDM2_ENID2_1               (GMAC_EMAC_TIDM2_ENID2_1_Val << GMAC_EMAC_TIDM2_ENID2_Pos) /* (GMAC_EMAC_TIDM2) TID is processed for the comparison match. Position  */
#define GMAC_EMAC_TIDM2_Msk                   _UINT32_(0x8000FFFF)                                 /* (GMAC_EMAC_TIDM2) Register Mask  */

#define GMAC_EMAC_TIDM2_ENID_Pos              _UINT32_(31)                                         /* (GMAC_EMAC_TIDM2 Position) Enable Copying of TID Matched Frames */
#define GMAC_EMAC_TIDM2_ENID_Msk              (_UINT32_(0x1) << GMAC_EMAC_TIDM2_ENID_Pos)          /* (GMAC_EMAC_TIDM2 Mask) ENID */
#define GMAC_EMAC_TIDM2_ENID(value)           (GMAC_EMAC_TIDM2_ENID_Msk & (_UINT32_(value) << GMAC_EMAC_TIDM2_ENID_Pos)) 

/* -------- GMAC_EMAC_TIDM3 : (GMAC Offset: 0x10B0) (R/W 32) Express MAC Type ID Match 3 Register -------- */
#define GMAC_EMAC_TIDM3_RESETVALUE            _UINT32_(0x00)                                       /*  (GMAC_EMAC_TIDM3) Express MAC Type ID Match 3 Register  Reset Value */

#define GMAC_EMAC_TIDM3_TID_Pos               _UINT32_(0)                                          /* (GMAC_EMAC_TIDM3) Type ID Match 3 Position */
#define GMAC_EMAC_TIDM3_TID_Msk               (_UINT32_(0xFFFF) << GMAC_EMAC_TIDM3_TID_Pos)        /* (GMAC_EMAC_TIDM3) Type ID Match 3 Mask */
#define GMAC_EMAC_TIDM3_TID(value)            (GMAC_EMAC_TIDM3_TID_Msk & (_UINT32_(value) << GMAC_EMAC_TIDM3_TID_Pos)) /* Assigment of value for TID in the GMAC_EMAC_TIDM3 register */
#define GMAC_EMAC_TIDM3_ENID3_Pos             _UINT32_(31)                                         /* (GMAC_EMAC_TIDM3) Enable Copying of TID Matched Frames Position */
#define GMAC_EMAC_TIDM3_ENID3_Msk             (_UINT32_(0x1) << GMAC_EMAC_TIDM3_ENID3_Pos)         /* (GMAC_EMAC_TIDM3) Enable Copying of TID Matched Frames Mask */
#define GMAC_EMAC_TIDM3_ENID3(value)          (GMAC_EMAC_TIDM3_ENID3_Msk & (_UINT32_(value) << GMAC_EMAC_TIDM3_ENID3_Pos)) /* Assigment of value for ENID3 in the GMAC_EMAC_TIDM3 register */
#define   GMAC_EMAC_TIDM3_ENID3_0_Val         _UINT32_(0x0)                                        /* (GMAC_EMAC_TIDM3) TID is not part of the comparison match.  */
#define   GMAC_EMAC_TIDM3_ENID3_1_Val         _UINT32_(0x1)                                        /* (GMAC_EMAC_TIDM3) TID is processed for the comparison match.  */
#define GMAC_EMAC_TIDM3_ENID3_0               (GMAC_EMAC_TIDM3_ENID3_0_Val << GMAC_EMAC_TIDM3_ENID3_Pos) /* (GMAC_EMAC_TIDM3) TID is not part of the comparison match. Position  */
#define GMAC_EMAC_TIDM3_ENID3_1               (GMAC_EMAC_TIDM3_ENID3_1_Val << GMAC_EMAC_TIDM3_ENID3_Pos) /* (GMAC_EMAC_TIDM3) TID is processed for the comparison match. Position  */
#define GMAC_EMAC_TIDM3_Msk                   _UINT32_(0x8000FFFF)                                 /* (GMAC_EMAC_TIDM3) Register Mask  */

#define GMAC_EMAC_TIDM3_ENID_Pos              _UINT32_(31)                                         /* (GMAC_EMAC_TIDM3 Position) Enable Copying of TID Matched Frames */
#define GMAC_EMAC_TIDM3_ENID_Msk              (_UINT32_(0x1) << GMAC_EMAC_TIDM3_ENID_Pos)          /* (GMAC_EMAC_TIDM3 Mask) ENID */
#define GMAC_EMAC_TIDM3_ENID(value)           (GMAC_EMAC_TIDM3_ENID_Msk & (_UINT32_(value) << GMAC_EMAC_TIDM3_ENID_Pos)) 

/* -------- GMAC_EMAC_TIDM4 : (GMAC Offset: 0x10B4) (R/W 32) Express MAC Type ID Match 4 Register -------- */
#define GMAC_EMAC_TIDM4_RESETVALUE            _UINT32_(0x00)                                       /*  (GMAC_EMAC_TIDM4) Express MAC Type ID Match 4 Register  Reset Value */

#define GMAC_EMAC_TIDM4_TID_Pos               _UINT32_(0)                                          /* (GMAC_EMAC_TIDM4) Type ID Match 4 Position */
#define GMAC_EMAC_TIDM4_TID_Msk               (_UINT32_(0xFFFF) << GMAC_EMAC_TIDM4_TID_Pos)        /* (GMAC_EMAC_TIDM4) Type ID Match 4 Mask */
#define GMAC_EMAC_TIDM4_TID(value)            (GMAC_EMAC_TIDM4_TID_Msk & (_UINT32_(value) << GMAC_EMAC_TIDM4_TID_Pos)) /* Assigment of value for TID in the GMAC_EMAC_TIDM4 register */
#define GMAC_EMAC_TIDM4_ENID4_Pos             _UINT32_(31)                                         /* (GMAC_EMAC_TIDM4) Enable Copying of TID Matched Frames Position */
#define GMAC_EMAC_TIDM4_ENID4_Msk             (_UINT32_(0x1) << GMAC_EMAC_TIDM4_ENID4_Pos)         /* (GMAC_EMAC_TIDM4) Enable Copying of TID Matched Frames Mask */
#define GMAC_EMAC_TIDM4_ENID4(value)          (GMAC_EMAC_TIDM4_ENID4_Msk & (_UINT32_(value) << GMAC_EMAC_TIDM4_ENID4_Pos)) /* Assigment of value for ENID4 in the GMAC_EMAC_TIDM4 register */
#define   GMAC_EMAC_TIDM4_ENID4_0_Val         _UINT32_(0x0)                                        /* (GMAC_EMAC_TIDM4) TID is not part of the comparison match.  */
#define   GMAC_EMAC_TIDM4_ENID4_1_Val         _UINT32_(0x1)                                        /* (GMAC_EMAC_TIDM4) TID is processed for the comparison match.  */
#define GMAC_EMAC_TIDM4_ENID4_0               (GMAC_EMAC_TIDM4_ENID4_0_Val << GMAC_EMAC_TIDM4_ENID4_Pos) /* (GMAC_EMAC_TIDM4) TID is not part of the comparison match. Position  */
#define GMAC_EMAC_TIDM4_ENID4_1               (GMAC_EMAC_TIDM4_ENID4_1_Val << GMAC_EMAC_TIDM4_ENID4_Pos) /* (GMAC_EMAC_TIDM4) TID is processed for the comparison match. Position  */
#define GMAC_EMAC_TIDM4_Msk                   _UINT32_(0x8000FFFF)                                 /* (GMAC_EMAC_TIDM4) Register Mask  */

#define GMAC_EMAC_TIDM4_ENID_Pos              _UINT32_(31)                                         /* (GMAC_EMAC_TIDM4 Position) Enable Copying of TID Matched Frames */
#define GMAC_EMAC_TIDM4_ENID_Msk              (_UINT32_(0x1) << GMAC_EMAC_TIDM4_ENID_Pos)          /* (GMAC_EMAC_TIDM4 Mask) ENID */
#define GMAC_EMAC_TIDM4_ENID(value)           (GMAC_EMAC_TIDM4_ENID_Msk & (_UINT32_(value) << GMAC_EMAC_TIDM4_ENID_Pos)) 

/* -------- GMAC_EMAC_WOL : (GMAC Offset: 0x10B8) (R/W 32) Express MAC Wake on LAN Register -------- */
#define GMAC_EMAC_WOL_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_WOL) Express MAC Wake on LAN Register  Reset Value */

#define GMAC_EMAC_WOL_IP_Pos                  _UINT32_(0)                                          /* (GMAC_EMAC_WOL) ARP Request IP Address Position */
#define GMAC_EMAC_WOL_IP_Msk                  (_UINT32_(0xFFFF) << GMAC_EMAC_WOL_IP_Pos)           /* (GMAC_EMAC_WOL) ARP Request IP Address Mask */
#define GMAC_EMAC_WOL_IP(value)               (GMAC_EMAC_WOL_IP_Msk & (_UINT32_(value) << GMAC_EMAC_WOL_IP_Pos)) /* Assigment of value for IP in the GMAC_EMAC_WOL register */
#define GMAC_EMAC_WOL_MAG_Pos                 _UINT32_(16)                                         /* (GMAC_EMAC_WOL) Magic Packet Event Enable Position */
#define GMAC_EMAC_WOL_MAG_Msk                 (_UINT32_(0x1) << GMAC_EMAC_WOL_MAG_Pos)             /* (GMAC_EMAC_WOL) Magic Packet Event Enable Mask */
#define GMAC_EMAC_WOL_MAG(value)              (GMAC_EMAC_WOL_MAG_Msk & (_UINT32_(value) << GMAC_EMAC_WOL_MAG_Pos)) /* Assigment of value for MAG in the GMAC_EMAC_WOL register */
#define GMAC_EMAC_WOL_ARP_Pos                 _UINT32_(17)                                         /* (GMAC_EMAC_WOL) ARP Request Event Enable Position */
#define GMAC_EMAC_WOL_ARP_Msk                 (_UINT32_(0x1) << GMAC_EMAC_WOL_ARP_Pos)             /* (GMAC_EMAC_WOL) ARP Request Event Enable Mask */
#define GMAC_EMAC_WOL_ARP(value)              (GMAC_EMAC_WOL_ARP_Msk & (_UINT32_(value) << GMAC_EMAC_WOL_ARP_Pos)) /* Assigment of value for ARP in the GMAC_EMAC_WOL register */
#define GMAC_EMAC_WOL_SA1_Pos                 _UINT32_(18)                                         /* (GMAC_EMAC_WOL) Specific Address Register 1 Event Enable Position */
#define GMAC_EMAC_WOL_SA1_Msk                 (_UINT32_(0x1) << GMAC_EMAC_WOL_SA1_Pos)             /* (GMAC_EMAC_WOL) Specific Address Register 1 Event Enable Mask */
#define GMAC_EMAC_WOL_SA1(value)              (GMAC_EMAC_WOL_SA1_Msk & (_UINT32_(value) << GMAC_EMAC_WOL_SA1_Pos)) /* Assigment of value for SA1 in the GMAC_EMAC_WOL register */
#define GMAC_EMAC_WOL_MTI_Pos                 _UINT32_(19)                                         /* (GMAC_EMAC_WOL) Multicast Hash Event Enable Position */
#define GMAC_EMAC_WOL_MTI_Msk                 (_UINT32_(0x1) << GMAC_EMAC_WOL_MTI_Pos)             /* (GMAC_EMAC_WOL) Multicast Hash Event Enable Mask */
#define GMAC_EMAC_WOL_MTI(value)              (GMAC_EMAC_WOL_MTI_Msk & (_UINT32_(value) << GMAC_EMAC_WOL_MTI_Pos)) /* Assigment of value for MTI in the GMAC_EMAC_WOL register */
#define GMAC_EMAC_WOL_Msk                     _UINT32_(0x000FFFFF)                                 /* (GMAC_EMAC_WOL) Register Mask  */

#define GMAC_EMAC_WOL_SA_Pos                  _UINT32_(18)                                         /* (GMAC_EMAC_WOL Position) Specific Address Register x Event Enable */
#define GMAC_EMAC_WOL_SA_Msk                  (_UINT32_(0x1) << GMAC_EMAC_WOL_SA_Pos)              /* (GMAC_EMAC_WOL Mask) SA */
#define GMAC_EMAC_WOL_SA(value)               (GMAC_EMAC_WOL_SA_Msk & (_UINT32_(value) << GMAC_EMAC_WOL_SA_Pos)) 

/* -------- GMAC_EMAC_IPGS : (GMAC Offset: 0x10BC) (R/W 32) Express MAC IPG Stretch Register -------- */
#define GMAC_EMAC_IPGS_RESETVALUE             _UINT32_(0x00)                                       /*  (GMAC_EMAC_IPGS) Express MAC IPG Stretch Register  Reset Value */

#define GMAC_EMAC_IPGS_FL_Pos                 _UINT32_(0)                                          /* (GMAC_EMAC_IPGS) Frame Length Position */
#define GMAC_EMAC_IPGS_FL_Msk                 (_UINT32_(0xFFFF) << GMAC_EMAC_IPGS_FL_Pos)          /* (GMAC_EMAC_IPGS) Frame Length Mask */
#define GMAC_EMAC_IPGS_FL(value)              (GMAC_EMAC_IPGS_FL_Msk & (_UINT32_(value) << GMAC_EMAC_IPGS_FL_Pos)) /* Assigment of value for FL in the GMAC_EMAC_IPGS register */
#define GMAC_EMAC_IPGS_Msk                    _UINT32_(0x0000FFFF)                                 /* (GMAC_EMAC_IPGS) Register Mask  */


/* -------- GMAC_EMAC_SVLAN : (GMAC Offset: 0x10C0) (R/W 32) Express MAC Stacked VLAN Register -------- */
#define GMAC_EMAC_SVLAN_RESETVALUE            _UINT32_(0x00)                                       /*  (GMAC_EMAC_SVLAN) Express MAC Stacked VLAN Register  Reset Value */

#define GMAC_EMAC_SVLAN_VLAN_TYPE_Pos         _UINT32_(0)                                          /* (GMAC_EMAC_SVLAN) User Defined VLAN_TYPE Field Position */
#define GMAC_EMAC_SVLAN_VLAN_TYPE_Msk         (_UINT32_(0xFFFF) << GMAC_EMAC_SVLAN_VLAN_TYPE_Pos)  /* (GMAC_EMAC_SVLAN) User Defined VLAN_TYPE Field Mask */
#define GMAC_EMAC_SVLAN_VLAN_TYPE(value)      (GMAC_EMAC_SVLAN_VLAN_TYPE_Msk & (_UINT32_(value) << GMAC_EMAC_SVLAN_VLAN_TYPE_Pos)) /* Assigment of value for VLAN_TYPE in the GMAC_EMAC_SVLAN register */
#define GMAC_EMAC_SVLAN_ESVLAN_Pos            _UINT32_(31)                                         /* (GMAC_EMAC_SVLAN) Enable Stacked VLAN Processing Mode Position */
#define GMAC_EMAC_SVLAN_ESVLAN_Msk            (_UINT32_(0x1) << GMAC_EMAC_SVLAN_ESVLAN_Pos)        /* (GMAC_EMAC_SVLAN) Enable Stacked VLAN Processing Mode Mask */
#define GMAC_EMAC_SVLAN_ESVLAN(value)         (GMAC_EMAC_SVLAN_ESVLAN_Msk & (_UINT32_(value) << GMAC_EMAC_SVLAN_ESVLAN_Pos)) /* Assigment of value for ESVLAN in the GMAC_EMAC_SVLAN register */
#define   GMAC_EMAC_SVLAN_ESVLAN_0_Val        _UINT32_(0x0)                                        /* (GMAC_EMAC_SVLAN) Disable the stacked VLAN Processing mode  */
#define   GMAC_EMAC_SVLAN_ESVLAN_1_Val        _UINT32_(0x1)                                        /* (GMAC_EMAC_SVLAN) Enable the stacked VLAN Processing mode  */
#define GMAC_EMAC_SVLAN_ESVLAN_0              (GMAC_EMAC_SVLAN_ESVLAN_0_Val << GMAC_EMAC_SVLAN_ESVLAN_Pos) /* (GMAC_EMAC_SVLAN) Disable the stacked VLAN Processing mode Position  */
#define GMAC_EMAC_SVLAN_ESVLAN_1              (GMAC_EMAC_SVLAN_ESVLAN_1_Val << GMAC_EMAC_SVLAN_ESVLAN_Pos) /* (GMAC_EMAC_SVLAN) Enable the stacked VLAN Processing mode Position  */
#define GMAC_EMAC_SVLAN_Msk                   _UINT32_(0x8000FFFF)                                 /* (GMAC_EMAC_SVLAN) Register Mask  */


/* -------- GMAC_EMAC_TPFCP : (GMAC Offset: 0x10C4) (R/W 32) Express MAC Transmit PFC Pause Register -------- */
#define GMAC_EMAC_TPFCP_RESETVALUE            _UINT32_(0x00)                                       /*  (GMAC_EMAC_TPFCP) Express MAC Transmit PFC Pause Register  Reset Value */

#define GMAC_EMAC_TPFCP_PEV_Pos               _UINT32_(0)                                          /* (GMAC_EMAC_TPFCP) Priority Enable Vector Position */
#define GMAC_EMAC_TPFCP_PEV_Msk               (_UINT32_(0xFF) << GMAC_EMAC_TPFCP_PEV_Pos)          /* (GMAC_EMAC_TPFCP) Priority Enable Vector Mask */
#define GMAC_EMAC_TPFCP_PEV(value)            (GMAC_EMAC_TPFCP_PEV_Msk & (_UINT32_(value) << GMAC_EMAC_TPFCP_PEV_Pos)) /* Assigment of value for PEV in the GMAC_EMAC_TPFCP register */
#define GMAC_EMAC_TPFCP_PQ_Pos                _UINT32_(8)                                          /* (GMAC_EMAC_TPFCP) Pause Quantum Position */
#define GMAC_EMAC_TPFCP_PQ_Msk                (_UINT32_(0xFF) << GMAC_EMAC_TPFCP_PQ_Pos)           /* (GMAC_EMAC_TPFCP) Pause Quantum Mask */
#define GMAC_EMAC_TPFCP_PQ(value)             (GMAC_EMAC_TPFCP_PQ_Msk & (_UINT32_(value) << GMAC_EMAC_TPFCP_PQ_Pos)) /* Assigment of value for PQ in the GMAC_EMAC_TPFCP register */
#define GMAC_EMAC_TPFCP_Msk                   _UINT32_(0x0000FFFF)                                 /* (GMAC_EMAC_TPFCP) Register Mask  */


/* -------- GMAC_EMAC_SAMB1 : (GMAC Offset: 0x10C8) (R/W 32) Express MAC Specific Address 1 Mask Bottom Register -------- */
#define GMAC_EMAC_SAMB1_RESETVALUE            _UINT32_(0x00)                                       /*  (GMAC_EMAC_SAMB1) Express MAC Specific Address 1 Mask Bottom Register  Reset Value */

#define GMAC_EMAC_SAMB1_ADDR_Pos              _UINT32_(0)                                          /* (GMAC_EMAC_SAMB1) Specific Address 1 Mask Position */
#define GMAC_EMAC_SAMB1_ADDR_Msk              (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_SAMB1_ADDR_Pos)   /* (GMAC_EMAC_SAMB1) Specific Address 1 Mask Mask */
#define GMAC_EMAC_SAMB1_ADDR(value)           (GMAC_EMAC_SAMB1_ADDR_Msk & (_UINT32_(value) << GMAC_EMAC_SAMB1_ADDR_Pos)) /* Assigment of value for ADDR in the GMAC_EMAC_SAMB1 register */
#define GMAC_EMAC_SAMB1_Msk                   _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_SAMB1) Register Mask  */


/* -------- GMAC_EMAC_SAMT1 : (GMAC Offset: 0x10CC) (R/W 32) Express MAC Specific Address 1 Mask Top Register -------- */
#define GMAC_EMAC_SAMT1_RESETVALUE            _UINT32_(0x00)                                       /*  (GMAC_EMAC_SAMT1) Express MAC Specific Address 1 Mask Top Register  Reset Value */

#define GMAC_EMAC_SAMT1_ADDR_Pos              _UINT32_(0)                                          /* (GMAC_EMAC_SAMT1) Specific Address 1 Mask Position */
#define GMAC_EMAC_SAMT1_ADDR_Msk              (_UINT32_(0xFFFF) << GMAC_EMAC_SAMT1_ADDR_Pos)       /* (GMAC_EMAC_SAMT1) Specific Address 1 Mask Mask */
#define GMAC_EMAC_SAMT1_ADDR(value)           (GMAC_EMAC_SAMT1_ADDR_Msk & (_UINT32_(value) << GMAC_EMAC_SAMT1_ADDR_Pos)) /* Assigment of value for ADDR in the GMAC_EMAC_SAMT1 register */
#define GMAC_EMAC_SAMT1_Msk                   _UINT32_(0x0000FFFF)                                 /* (GMAC_EMAC_SAMT1) Register Mask  */


/* -------- GMAC_EMAC_AMRX : (GMAC Offset: 0x10D0) (R/W 32) System Memory Address Mask for RX Data Buffer Accesses Register -------- */
#define GMAC_EMAC_AMRX_RESETVALUE             _UINT32_(0x00)                                       /*  (GMAC_EMAC_AMRX) System Memory Address Mask for RX Data Buffer Accesses Register  Reset Value */

#define GMAC_EMAC_AMRX_MSBADDRMSK_Pos         _UINT32_(0)                                          /* (GMAC_EMAC_AMRX) Mask of the Receive Data Buffer Address Position */
#define GMAC_EMAC_AMRX_MSBADDRMSK_Msk         (_UINT32_(0xF) << GMAC_EMAC_AMRX_MSBADDRMSK_Pos)     /* (GMAC_EMAC_AMRX) Mask of the Receive Data Buffer Address Mask */
#define GMAC_EMAC_AMRX_MSBADDRMSK(value)      (GMAC_EMAC_AMRX_MSBADDRMSK_Msk & (_UINT32_(value) << GMAC_EMAC_AMRX_MSBADDRMSK_Pos)) /* Assigment of value for MSBADDRMSK in the GMAC_EMAC_AMRX register */
#define GMAC_EMAC_AMRX_MSBADDR_Pos            _UINT32_(28)                                         /* (GMAC_EMAC_AMRX) MSB of the Receive Data Buffer Address Position */
#define GMAC_EMAC_AMRX_MSBADDR_Msk            (_UINT32_(0xF) << GMAC_EMAC_AMRX_MSBADDR_Pos)        /* (GMAC_EMAC_AMRX) MSB of the Receive Data Buffer Address Mask */
#define GMAC_EMAC_AMRX_MSBADDR(value)         (GMAC_EMAC_AMRX_MSBADDR_Msk & (_UINT32_(value) << GMAC_EMAC_AMRX_MSBADDR_Pos)) /* Assigment of value for MSBADDR in the GMAC_EMAC_AMRX register */
#define GMAC_EMAC_AMRX_Msk                    _UINT32_(0xF000000F)                                 /* (GMAC_EMAC_AMRX) Register Mask  */


/* -------- GMAC_EMAC_RXUDAR : (GMAC Offset: 0x10D4) (R/W 32) Express MAC PTP RX Unicast IP Destination Address Register -------- */
#define GMAC_EMAC_RXUDAR_RESETVALUE           _UINT32_(0x00)                                       /*  (GMAC_EMAC_RXUDAR) Express MAC PTP RX Unicast IP Destination Address Register  Reset Value */

#define GMAC_EMAC_RXUDAR_RXUDA_Pos            _UINT32_(0)                                          /* (GMAC_EMAC_RXUDAR) Receive Unicast Destination Address Position */
#define GMAC_EMAC_RXUDAR_RXUDA_Msk            (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_RXUDAR_RXUDA_Pos) /* (GMAC_EMAC_RXUDAR) Receive Unicast Destination Address Mask */
#define GMAC_EMAC_RXUDAR_RXUDA(value)         (GMAC_EMAC_RXUDAR_RXUDA_Msk & (_UINT32_(value) << GMAC_EMAC_RXUDAR_RXUDA_Pos)) /* Assigment of value for RXUDA in the GMAC_EMAC_RXUDAR register */
#define GMAC_EMAC_RXUDAR_Msk                  _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_RXUDAR) Register Mask  */


/* -------- GMAC_EMAC_TXUDAR : (GMAC Offset: 0x10D8) (R/W 32) Express MAC PTP TX Unicast IP Destination Address Register -------- */
#define GMAC_EMAC_TXUDAR_RESETVALUE           _UINT32_(0x00)                                       /*  (GMAC_EMAC_TXUDAR) Express MAC PTP TX Unicast IP Destination Address Register  Reset Value */

#define GMAC_EMAC_TXUDAR_TXUDA_Pos            _UINT32_(0)                                          /* (GMAC_EMAC_TXUDAR) Transmit Unicast Destination Address Position */
#define GMAC_EMAC_TXUDAR_TXUDA_Msk            (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_TXUDAR_TXUDA_Pos) /* (GMAC_EMAC_TXUDAR) Transmit Unicast Destination Address Mask */
#define GMAC_EMAC_TXUDAR_TXUDA(value)         (GMAC_EMAC_TXUDAR_TXUDA_Msk & (_UINT32_(value) << GMAC_EMAC_TXUDAR_TXUDA_Pos)) /* Assigment of value for TXUDA in the GMAC_EMAC_TXUDAR register */
#define GMAC_EMAC_TXUDAR_Msk                  _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_TXUDAR) Register Mask  */


/* -------- GMAC_EMAC_NSC : (GMAC Offset: 0x10DC) (R/W 32) Express MAC 1588 Timer Nanosecond Comparison Register -------- */
#define GMAC_EMAC_NSC_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_NSC) Express MAC 1588 Timer Nanosecond Comparison Register  Reset Value */

#define GMAC_EMAC_NSC_NANOSEC_Pos             _UINT32_(0)                                          /* (GMAC_EMAC_NSC) 1588 Timer Nanosecond Comparison Value Position */
#define GMAC_EMAC_NSC_NANOSEC_Msk             (_UINT32_(0x3FFFFF) << GMAC_EMAC_NSC_NANOSEC_Pos)    /* (GMAC_EMAC_NSC) 1588 Timer Nanosecond Comparison Value Mask */
#define GMAC_EMAC_NSC_NANOSEC(value)          (GMAC_EMAC_NSC_NANOSEC_Msk & (_UINT32_(value) << GMAC_EMAC_NSC_NANOSEC_Pos)) /* Assigment of value for NANOSEC in the GMAC_EMAC_NSC register */
#define GMAC_EMAC_NSC_Msk                     _UINT32_(0x003FFFFF)                                 /* (GMAC_EMAC_NSC) Register Mask  */


/* -------- GMAC_EMAC_SCL : (GMAC Offset: 0x10E0) (R/W 32) Express MAC 1588 Timer Second Comparison Low Register -------- */
#define GMAC_EMAC_SCL_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_SCL) Express MAC 1588 Timer Second Comparison Low Register  Reset Value */

#define GMAC_EMAC_SCL_SEC_Pos                 _UINT32_(0)                                          /* (GMAC_EMAC_SCL) 1588 Timer Second Comparison Value Position */
#define GMAC_EMAC_SCL_SEC_Msk                 (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_SCL_SEC_Pos)      /* (GMAC_EMAC_SCL) 1588 Timer Second Comparison Value Mask */
#define GMAC_EMAC_SCL_SEC(value)              (GMAC_EMAC_SCL_SEC_Msk & (_UINT32_(value) << GMAC_EMAC_SCL_SEC_Pos)) /* Assigment of value for SEC in the GMAC_EMAC_SCL register */
#define GMAC_EMAC_SCL_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_SCL) Register Mask  */


/* -------- GMAC_EMAC_SCH : (GMAC Offset: 0x10E4) (R/W 32) Express MAC 1588 Timer Second Comparison High Register -------- */
#define GMAC_EMAC_SCH_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_SCH) Express MAC 1588 Timer Second Comparison High Register  Reset Value */

#define GMAC_EMAC_SCH_SEC_Pos                 _UINT32_(0)                                          /* (GMAC_EMAC_SCH) 1588 Timer Second Comparison Value Position */
#define GMAC_EMAC_SCH_SEC_Msk                 (_UINT32_(0xFFFF) << GMAC_EMAC_SCH_SEC_Pos)          /* (GMAC_EMAC_SCH) 1588 Timer Second Comparison Value Mask */
#define GMAC_EMAC_SCH_SEC(value)              (GMAC_EMAC_SCH_SEC_Msk & (_UINT32_(value) << GMAC_EMAC_SCH_SEC_Pos)) /* Assigment of value for SEC in the GMAC_EMAC_SCH register */
#define GMAC_EMAC_SCH_Msk                     _UINT32_(0x0000FFFF)                                 /* (GMAC_EMAC_SCH) Register Mask  */


/* -------- GMAC_EMAC_EFTSH : (GMAC Offset: 0x10E8) ( R/ 32) Express MAC PTP Event Frame Transmitted Seconds High Register -------- */
#define GMAC_EMAC_EFTSH_RESETVALUE            _UINT32_(0x00)                                       /*  (GMAC_EMAC_EFTSH) Express MAC PTP Event Frame Transmitted Seconds High Register  Reset Value */

#define GMAC_EMAC_EFTSH_RUD_Pos               _UINT32_(0)                                          /* (GMAC_EMAC_EFTSH) Register Update Position */
#define GMAC_EMAC_EFTSH_RUD_Msk               (_UINT32_(0xFFFF) << GMAC_EMAC_EFTSH_RUD_Pos)        /* (GMAC_EMAC_EFTSH) Register Update Mask */
#define GMAC_EMAC_EFTSH_RUD(value)            (GMAC_EMAC_EFTSH_RUD_Msk & (_UINT32_(value) << GMAC_EMAC_EFTSH_RUD_Pos)) /* Assigment of value for RUD in the GMAC_EMAC_EFTSH register */
#define GMAC_EMAC_EFTSH_Msk                   _UINT32_(0x0000FFFF)                                 /* (GMAC_EMAC_EFTSH) Register Mask  */


/* -------- GMAC_EMAC_EFRSH : (GMAC Offset: 0x10EC) ( R/ 32) Express MAC PTP Event Frame Received Seconds High Register -------- */
#define GMAC_EMAC_EFRSH_RESETVALUE            _UINT32_(0x00)                                       /*  (GMAC_EMAC_EFRSH) Express MAC PTP Event Frame Received Seconds High Register  Reset Value */

#define GMAC_EMAC_EFRSH_RUD_Pos               _UINT32_(0)                                          /* (GMAC_EMAC_EFRSH) Register Update Position */
#define GMAC_EMAC_EFRSH_RUD_Msk               (_UINT32_(0xFFFF) << GMAC_EMAC_EFRSH_RUD_Pos)        /* (GMAC_EMAC_EFRSH) Register Update Mask */
#define GMAC_EMAC_EFRSH_RUD(value)            (GMAC_EMAC_EFRSH_RUD_Msk & (_UINT32_(value) << GMAC_EMAC_EFRSH_RUD_Pos)) /* Assigment of value for RUD in the GMAC_EMAC_EFRSH register */
#define GMAC_EMAC_EFRSH_Msk                   _UINT32_(0x0000FFFF)                                 /* (GMAC_EMAC_EFRSH) Register Mask  */


/* -------- GMAC_EMAC_PEFTSH : (GMAC Offset: 0x10F0) ( R/ 32) Express MAC PTP Peer Event Frame Transmitted Seconds High Register -------- */
#define GMAC_EMAC_PEFTSH_RESETVALUE           _UINT32_(0x00)                                       /*  (GMAC_EMAC_PEFTSH) Express MAC PTP Peer Event Frame Transmitted Seconds High Register  Reset Value */

#define GMAC_EMAC_PEFTSH_RUD_Pos              _UINT32_(0)                                          /* (GMAC_EMAC_PEFTSH) Register Update Position */
#define GMAC_EMAC_PEFTSH_RUD_Msk              (_UINT32_(0xFFFF) << GMAC_EMAC_PEFTSH_RUD_Pos)       /* (GMAC_EMAC_PEFTSH) Register Update Mask */
#define GMAC_EMAC_PEFTSH_RUD(value)           (GMAC_EMAC_PEFTSH_RUD_Msk & (_UINT32_(value) << GMAC_EMAC_PEFTSH_RUD_Pos)) /* Assigment of value for RUD in the GMAC_EMAC_PEFTSH register */
#define GMAC_EMAC_PEFTSH_Msk                  _UINT32_(0x0000FFFF)                                 /* (GMAC_EMAC_PEFTSH) Register Mask  */


/* -------- GMAC_EMAC_PEFRSH : (GMAC Offset: 0x10F4) ( R/ 32) Express MAC PTP Peer Event Frame Received Seconds High Register -------- */
#define GMAC_EMAC_PEFRSH_RESETVALUE           _UINT32_(0x00)                                       /*  (GMAC_EMAC_PEFRSH) Express MAC PTP Peer Event Frame Received Seconds High Register  Reset Value */

#define GMAC_EMAC_PEFRSH_RUD_Pos              _UINT32_(0)                                          /* (GMAC_EMAC_PEFRSH) Register Update Position */
#define GMAC_EMAC_PEFRSH_RUD_Msk              (_UINT32_(0xFFFF) << GMAC_EMAC_PEFRSH_RUD_Pos)       /* (GMAC_EMAC_PEFRSH) Register Update Mask */
#define GMAC_EMAC_PEFRSH_RUD(value)           (GMAC_EMAC_PEFRSH_RUD_Msk & (_UINT32_(value) << GMAC_EMAC_PEFRSH_RUD_Pos)) /* Assigment of value for RUD in the GMAC_EMAC_PEFRSH register */
#define GMAC_EMAC_PEFRSH_Msk                  _UINT32_(0x0000FFFF)                                 /* (GMAC_EMAC_PEFRSH) Register Mask  */


/* -------- GMAC_EMAC_OTLO : (GMAC Offset: 0x1100) ( R/ 32) Express MAC Octets Transmitted Low Register -------- */
#define GMAC_EMAC_OTLO_RESETVALUE             _UINT32_(0x00)                                       /*  (GMAC_EMAC_OTLO) Express MAC Octets Transmitted Low Register  Reset Value */

#define GMAC_EMAC_OTLO_TXO_Pos                _UINT32_(0)                                          /* (GMAC_EMAC_OTLO) Transmitted Octets Position */
#define GMAC_EMAC_OTLO_TXO_Msk                (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_OTLO_TXO_Pos)     /* (GMAC_EMAC_OTLO) Transmitted Octets Mask */
#define GMAC_EMAC_OTLO_TXO(value)             (GMAC_EMAC_OTLO_TXO_Msk & (_UINT32_(value) << GMAC_EMAC_OTLO_TXO_Pos)) /* Assigment of value for TXO in the GMAC_EMAC_OTLO register */
#define GMAC_EMAC_OTLO_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_OTLO) Register Mask  */


/* -------- GMAC_EMAC_OTHI : (GMAC Offset: 0x1104) ( R/ 32) Express MAC Octets Transmitted High Register -------- */
#define GMAC_EMAC_OTHI_RESETVALUE             _UINT32_(0x00)                                       /*  (GMAC_EMAC_OTHI) Express MAC Octets Transmitted High Register  Reset Value */

#define GMAC_EMAC_OTHI_TXO_Pos                _UINT32_(0)                                          /* (GMAC_EMAC_OTHI) Transmitted Octets Position */
#define GMAC_EMAC_OTHI_TXO_Msk                (_UINT32_(0xFFFF) << GMAC_EMAC_OTHI_TXO_Pos)         /* (GMAC_EMAC_OTHI) Transmitted Octets Mask */
#define GMAC_EMAC_OTHI_TXO(value)             (GMAC_EMAC_OTHI_TXO_Msk & (_UINT32_(value) << GMAC_EMAC_OTHI_TXO_Pos)) /* Assigment of value for TXO in the GMAC_EMAC_OTHI register */
#define GMAC_EMAC_OTHI_Msk                    _UINT32_(0x0000FFFF)                                 /* (GMAC_EMAC_OTHI) Register Mask  */


/* -------- GMAC_EMAC_FT : (GMAC Offset: 0x1108) ( R/ 32) Express MAC Frames Transmitted Register -------- */
#define GMAC_EMAC_FT_RESETVALUE               _UINT32_(0x00)                                       /*  (GMAC_EMAC_FT) Express MAC Frames Transmitted Register  Reset Value */

#define GMAC_EMAC_FT_FTX_Pos                  _UINT32_(0)                                          /* (GMAC_EMAC_FT) Frames Transmitted without Error Position */
#define GMAC_EMAC_FT_FTX_Msk                  (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_FT_FTX_Pos)       /* (GMAC_EMAC_FT) Frames Transmitted without Error Mask */
#define GMAC_EMAC_FT_FTX(value)               (GMAC_EMAC_FT_FTX_Msk & (_UINT32_(value) << GMAC_EMAC_FT_FTX_Pos)) /* Assigment of value for FTX in the GMAC_EMAC_FT register */
#define GMAC_EMAC_FT_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_FT) Register Mask  */


/* -------- GMAC_EMAC_BCFT : (GMAC Offset: 0x110C) ( R/ 32) Express MAC Broadcast Frames Transmitted Register -------- */
#define GMAC_EMAC_BCFT_RESETVALUE             _UINT32_(0x00)                                       /*  (GMAC_EMAC_BCFT) Express MAC Broadcast Frames Transmitted Register  Reset Value */

#define GMAC_EMAC_BCFT_BFTX_Pos               _UINT32_(0)                                          /* (GMAC_EMAC_BCFT) Broadcast Frames Transmitted without Error Position */
#define GMAC_EMAC_BCFT_BFTX_Msk               (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_BCFT_BFTX_Pos)    /* (GMAC_EMAC_BCFT) Broadcast Frames Transmitted without Error Mask */
#define GMAC_EMAC_BCFT_BFTX(value)            (GMAC_EMAC_BCFT_BFTX_Msk & (_UINT32_(value) << GMAC_EMAC_BCFT_BFTX_Pos)) /* Assigment of value for BFTX in the GMAC_EMAC_BCFT register */
#define GMAC_EMAC_BCFT_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_BCFT) Register Mask  */


/* -------- GMAC_EMAC_MFT : (GMAC Offset: 0x1110) ( R/ 32) Express MAC Multicast Frames Transmitted Register -------- */
#define GMAC_EMAC_MFT_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_MFT) Express MAC Multicast Frames Transmitted Register  Reset Value */

#define GMAC_EMAC_MFT_MFTX_Pos                _UINT32_(0)                                          /* (GMAC_EMAC_MFT) Multicast Frames Transmitted without Error Position */
#define GMAC_EMAC_MFT_MFTX_Msk                (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_MFT_MFTX_Pos)     /* (GMAC_EMAC_MFT) Multicast Frames Transmitted without Error Mask */
#define GMAC_EMAC_MFT_MFTX(value)             (GMAC_EMAC_MFT_MFTX_Msk & (_UINT32_(value) << GMAC_EMAC_MFT_MFTX_Pos)) /* Assigment of value for MFTX in the GMAC_EMAC_MFT register */
#define GMAC_EMAC_MFT_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_MFT) Register Mask  */


/* -------- GMAC_EMAC_PFT : (GMAC Offset: 0x1114) ( R/ 32) Express MAC Pause Frames Transmitted Register -------- */
#define GMAC_EMAC_PFT_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_PFT) Express MAC Pause Frames Transmitted Register  Reset Value */

#define GMAC_EMAC_PFT_PFTX_Pos                _UINT32_(0)                                          /* (GMAC_EMAC_PFT) Pause Frames Transmitted Register Position */
#define GMAC_EMAC_PFT_PFTX_Msk                (_UINT32_(0xFFFF) << GMAC_EMAC_PFT_PFTX_Pos)         /* (GMAC_EMAC_PFT) Pause Frames Transmitted Register Mask */
#define GMAC_EMAC_PFT_PFTX(value)             (GMAC_EMAC_PFT_PFTX_Msk & (_UINT32_(value) << GMAC_EMAC_PFT_PFTX_Pos)) /* Assigment of value for PFTX in the GMAC_EMAC_PFT register */
#define GMAC_EMAC_PFT_Msk                     _UINT32_(0x0000FFFF)                                 /* (GMAC_EMAC_PFT) Register Mask  */


/* -------- GMAC_EMAC_BFT64 : (GMAC Offset: 0x1118) ( R/ 32) Express MAC 64 Byte Frames Transmitted Register -------- */
#define GMAC_EMAC_BFT64_RESETVALUE            _UINT32_(0x00)                                       /*  (GMAC_EMAC_BFT64) Express MAC 64 Byte Frames Transmitted Register  Reset Value */

#define GMAC_EMAC_BFT64_NFTX_Pos              _UINT32_(0)                                          /* (GMAC_EMAC_BFT64) 64 Byte Frames Transmitted without Error Position */
#define GMAC_EMAC_BFT64_NFTX_Msk              (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_BFT64_NFTX_Pos)   /* (GMAC_EMAC_BFT64) 64 Byte Frames Transmitted without Error Mask */
#define GMAC_EMAC_BFT64_NFTX(value)           (GMAC_EMAC_BFT64_NFTX_Msk & (_UINT32_(value) << GMAC_EMAC_BFT64_NFTX_Pos)) /* Assigment of value for NFTX in the GMAC_EMAC_BFT64 register */
#define GMAC_EMAC_BFT64_Msk                   _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_BFT64) Register Mask  */


/* -------- GMAC_EMAC_TBFT127 : (GMAC Offset: 0x111C) ( R/ 32) Express MAC 65 to 127 Byte Frames Transmitted Register -------- */
#define GMAC_EMAC_TBFT127_RESETVALUE          _UINT32_(0x00)                                       /*  (GMAC_EMAC_TBFT127) Express MAC 65 to 127 Byte Frames Transmitted Register  Reset Value */

#define GMAC_EMAC_TBFT127_NFTX_Pos            _UINT32_(0)                                          /* (GMAC_EMAC_TBFT127) 65 to 127 Byte Frames Transmitted without Error Position */
#define GMAC_EMAC_TBFT127_NFTX_Msk            (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_TBFT127_NFTX_Pos) /* (GMAC_EMAC_TBFT127) 65 to 127 Byte Frames Transmitted without Error Mask */
#define GMAC_EMAC_TBFT127_NFTX(value)         (GMAC_EMAC_TBFT127_NFTX_Msk & (_UINT32_(value) << GMAC_EMAC_TBFT127_NFTX_Pos)) /* Assigment of value for NFTX in the GMAC_EMAC_TBFT127 register */
#define GMAC_EMAC_TBFT127_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_TBFT127) Register Mask  */


/* -------- GMAC_EMAC_TBFT255 : (GMAC Offset: 0x1120) ( R/ 32) Express MAC 128 to 255 Byte Frames Transmitted Register -------- */
#define GMAC_EMAC_TBFT255_RESETVALUE          _UINT32_(0x00)                                       /*  (GMAC_EMAC_TBFT255) Express MAC 128 to 255 Byte Frames Transmitted Register  Reset Value */

#define GMAC_EMAC_TBFT255_NFTX_Pos            _UINT32_(0)                                          /* (GMAC_EMAC_TBFT255) 128 to 255 Byte Frames Transmitted without Error Position */
#define GMAC_EMAC_TBFT255_NFTX_Msk            (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_TBFT255_NFTX_Pos) /* (GMAC_EMAC_TBFT255) 128 to 255 Byte Frames Transmitted without Error Mask */
#define GMAC_EMAC_TBFT255_NFTX(value)         (GMAC_EMAC_TBFT255_NFTX_Msk & (_UINT32_(value) << GMAC_EMAC_TBFT255_NFTX_Pos)) /* Assigment of value for NFTX in the GMAC_EMAC_TBFT255 register */
#define GMAC_EMAC_TBFT255_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_TBFT255) Register Mask  */


/* -------- GMAC_EMAC_TBFT511 : (GMAC Offset: 0x1124) ( R/ 32) Express MAC 256 to 511 Byte Frames Transmitted Register -------- */
#define GMAC_EMAC_TBFT511_RESETVALUE          _UINT32_(0x00)                                       /*  (GMAC_EMAC_TBFT511) Express MAC 256 to 511 Byte Frames Transmitted Register  Reset Value */

#define GMAC_EMAC_TBFT511_NFTX_Pos            _UINT32_(0)                                          /* (GMAC_EMAC_TBFT511) 256 to 511 Byte Frames Transmitted without Error Position */
#define GMAC_EMAC_TBFT511_NFTX_Msk            (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_TBFT511_NFTX_Pos) /* (GMAC_EMAC_TBFT511) 256 to 511 Byte Frames Transmitted without Error Mask */
#define GMAC_EMAC_TBFT511_NFTX(value)         (GMAC_EMAC_TBFT511_NFTX_Msk & (_UINT32_(value) << GMAC_EMAC_TBFT511_NFTX_Pos)) /* Assigment of value for NFTX in the GMAC_EMAC_TBFT511 register */
#define GMAC_EMAC_TBFT511_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_TBFT511) Register Mask  */


/* -------- GMAC_EMAC_TBFT1023 : (GMAC Offset: 0x1128) ( R/ 32) Express MAC 512 to 1023 Byte Frames Transmitted Register -------- */
#define GMAC_EMAC_TBFT1023_RESETVALUE         _UINT32_(0x00)                                       /*  (GMAC_EMAC_TBFT1023) Express MAC 512 to 1023 Byte Frames Transmitted Register  Reset Value */

#define GMAC_EMAC_TBFT1023_NFTX_Pos           _UINT32_(0)                                          /* (GMAC_EMAC_TBFT1023) 512 to 1023 Byte Frames Transmitted without Error Position */
#define GMAC_EMAC_TBFT1023_NFTX_Msk           (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_TBFT1023_NFTX_Pos) /* (GMAC_EMAC_TBFT1023) 512 to 1023 Byte Frames Transmitted without Error Mask */
#define GMAC_EMAC_TBFT1023_NFTX(value)        (GMAC_EMAC_TBFT1023_NFTX_Msk & (_UINT32_(value) << GMAC_EMAC_TBFT1023_NFTX_Pos)) /* Assigment of value for NFTX in the GMAC_EMAC_TBFT1023 register */
#define GMAC_EMAC_TBFT1023_Msk                _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_TBFT1023) Register Mask  */


/* -------- GMAC_EMAC_TBFT1518 : (GMAC Offset: 0x112C) ( R/ 32) Express MAC 1024 to 1518 Byte Frames Transmitted Register -------- */
#define GMAC_EMAC_TBFT1518_RESETVALUE         _UINT32_(0x00)                                       /*  (GMAC_EMAC_TBFT1518) Express MAC 1024 to 1518 Byte Frames Transmitted Register  Reset Value */

#define GMAC_EMAC_TBFT1518_NFTX_Pos           _UINT32_(0)                                          /* (GMAC_EMAC_TBFT1518) 1024 to 1518 Byte Frames Transmitted without Error Position */
#define GMAC_EMAC_TBFT1518_NFTX_Msk           (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_TBFT1518_NFTX_Pos) /* (GMAC_EMAC_TBFT1518) 1024 to 1518 Byte Frames Transmitted without Error Mask */
#define GMAC_EMAC_TBFT1518_NFTX(value)        (GMAC_EMAC_TBFT1518_NFTX_Msk & (_UINT32_(value) << GMAC_EMAC_TBFT1518_NFTX_Pos)) /* Assigment of value for NFTX in the GMAC_EMAC_TBFT1518 register */
#define GMAC_EMAC_TBFT1518_Msk                _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_TBFT1518) Register Mask  */


/* -------- GMAC_EMAC_GTBFT1518 : (GMAC Offset: 0x1130) ( R/ 32) Express MAC Greater Than 1518 Byte Frames Transmitted Register -------- */
#define GMAC_EMAC_GTBFT1518_RESETVALUE        _UINT32_(0x00)                                       /*  (GMAC_EMAC_GTBFT1518) Express MAC Greater Than 1518 Byte Frames Transmitted Register  Reset Value */

#define GMAC_EMAC_GTBFT1518_NFTX_Pos          _UINT32_(0)                                          /* (GMAC_EMAC_GTBFT1518) Greater than 1518 Byte Frames Transmitted without Error Position */
#define GMAC_EMAC_GTBFT1518_NFTX_Msk          (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_GTBFT1518_NFTX_Pos) /* (GMAC_EMAC_GTBFT1518) Greater than 1518 Byte Frames Transmitted without Error Mask */
#define GMAC_EMAC_GTBFT1518_NFTX(value)       (GMAC_EMAC_GTBFT1518_NFTX_Msk & (_UINT32_(value) << GMAC_EMAC_GTBFT1518_NFTX_Pos)) /* Assigment of value for NFTX in the GMAC_EMAC_GTBFT1518 register */
#define GMAC_EMAC_GTBFT1518_Msk               _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_GTBFT1518) Register Mask  */


/* -------- GMAC_EMAC_TUR : (GMAC Offset: 0x1134) ( R/ 32) Express MAC Transmit Underruns Register -------- */
#define GMAC_EMAC_TUR_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_TUR) Express MAC Transmit Underruns Register  Reset Value */

#define GMAC_EMAC_TUR_TXUNR_Pos               _UINT32_(0)                                          /* (GMAC_EMAC_TUR) Transmit Underruns Position */
#define GMAC_EMAC_TUR_TXUNR_Msk               (_UINT32_(0x3FF) << GMAC_EMAC_TUR_TXUNR_Pos)         /* (GMAC_EMAC_TUR) Transmit Underruns Mask */
#define GMAC_EMAC_TUR_TXUNR(value)            (GMAC_EMAC_TUR_TXUNR_Msk & (_UINT32_(value) << GMAC_EMAC_TUR_TXUNR_Pos)) /* Assigment of value for TXUNR in the GMAC_EMAC_TUR register */
#define GMAC_EMAC_TUR_Msk                     _UINT32_(0x000003FF)                                 /* (GMAC_EMAC_TUR) Register Mask  */


/* -------- GMAC_EMAC_SCF : (GMAC Offset: 0x1138) ( R/ 32) Express MAC Single Collision Frames Register -------- */
#define GMAC_EMAC_SCF_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_SCF) Express MAC Single Collision Frames Register  Reset Value */

#define GMAC_EMAC_SCF_SCOL_Pos                _UINT32_(0)                                          /* (GMAC_EMAC_SCF) Single Collision Position */
#define GMAC_EMAC_SCF_SCOL_Msk                (_UINT32_(0x3FFFF) << GMAC_EMAC_SCF_SCOL_Pos)        /* (GMAC_EMAC_SCF) Single Collision Mask */
#define GMAC_EMAC_SCF_SCOL(value)             (GMAC_EMAC_SCF_SCOL_Msk & (_UINT32_(value) << GMAC_EMAC_SCF_SCOL_Pos)) /* Assigment of value for SCOL in the GMAC_EMAC_SCF register */
#define GMAC_EMAC_SCF_Msk                     _UINT32_(0x0003FFFF)                                 /* (GMAC_EMAC_SCF) Register Mask  */


/* -------- GMAC_EMAC_MCF : (GMAC Offset: 0x113C) ( R/ 32) Express MAC Multiple Collision Frames Register -------- */
#define GMAC_EMAC_MCF_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_MCF) Express MAC Multiple Collision Frames Register  Reset Value */

#define GMAC_EMAC_MCF_MCOL_Pos                _UINT32_(0)                                          /* (GMAC_EMAC_MCF) Multiple Collision Position */
#define GMAC_EMAC_MCF_MCOL_Msk                (_UINT32_(0x3FFFF) << GMAC_EMAC_MCF_MCOL_Pos)        /* (GMAC_EMAC_MCF) Multiple Collision Mask */
#define GMAC_EMAC_MCF_MCOL(value)             (GMAC_EMAC_MCF_MCOL_Msk & (_UINT32_(value) << GMAC_EMAC_MCF_MCOL_Pos)) /* Assigment of value for MCOL in the GMAC_EMAC_MCF register */
#define GMAC_EMAC_MCF_Msk                     _UINT32_(0x0003FFFF)                                 /* (GMAC_EMAC_MCF) Register Mask  */


/* -------- GMAC_EMAC_EC : (GMAC Offset: 0x1140) ( R/ 32) Express MAC Excessive Collisions Register -------- */
#define GMAC_EMAC_EC_RESETVALUE               _UINT32_(0x00)                                       /*  (GMAC_EMAC_EC) Express MAC Excessive Collisions Register  Reset Value */

#define GMAC_EMAC_EC_XCOL_Pos                 _UINT32_(0)                                          /* (GMAC_EMAC_EC) Excessive Collisions Position */
#define GMAC_EMAC_EC_XCOL_Msk                 (_UINT32_(0x3FF) << GMAC_EMAC_EC_XCOL_Pos)           /* (GMAC_EMAC_EC) Excessive Collisions Mask */
#define GMAC_EMAC_EC_XCOL(value)              (GMAC_EMAC_EC_XCOL_Msk & (_UINT32_(value) << GMAC_EMAC_EC_XCOL_Pos)) /* Assigment of value for XCOL in the GMAC_EMAC_EC register */
#define GMAC_EMAC_EC_Msk                      _UINT32_(0x000003FF)                                 /* (GMAC_EMAC_EC) Register Mask  */


/* -------- GMAC_EMAC_LC : (GMAC Offset: 0x1144) ( R/ 32) Express MAC Late Collisions Register -------- */
#define GMAC_EMAC_LC_RESETVALUE               _UINT32_(0x00)                                       /*  (GMAC_EMAC_LC) Express MAC Late Collisions Register  Reset Value */

#define GMAC_EMAC_LC_LCOL_Pos                 _UINT32_(0)                                          /* (GMAC_EMAC_LC) Late Collisions Position */
#define GMAC_EMAC_LC_LCOL_Msk                 (_UINT32_(0x3FF) << GMAC_EMAC_LC_LCOL_Pos)           /* (GMAC_EMAC_LC) Late Collisions Mask */
#define GMAC_EMAC_LC_LCOL(value)              (GMAC_EMAC_LC_LCOL_Msk & (_UINT32_(value) << GMAC_EMAC_LC_LCOL_Pos)) /* Assigment of value for LCOL in the GMAC_EMAC_LC register */
#define GMAC_EMAC_LC_Msk                      _UINT32_(0x000003FF)                                 /* (GMAC_EMAC_LC) Register Mask  */


/* -------- GMAC_EMAC_DTF : (GMAC Offset: 0x1148) ( R/ 32) Express MAC Deferred Transmission Frames Register -------- */
#define GMAC_EMAC_DTF_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_DTF) Express MAC Deferred Transmission Frames Register  Reset Value */

#define GMAC_EMAC_DTF_DEFT_Pos                _UINT32_(0)                                          /* (GMAC_EMAC_DTF) Deferred Transmission Position */
#define GMAC_EMAC_DTF_DEFT_Msk                (_UINT32_(0x3FFFF) << GMAC_EMAC_DTF_DEFT_Pos)        /* (GMAC_EMAC_DTF) Deferred Transmission Mask */
#define GMAC_EMAC_DTF_DEFT(value)             (GMAC_EMAC_DTF_DEFT_Msk & (_UINT32_(value) << GMAC_EMAC_DTF_DEFT_Pos)) /* Assigment of value for DEFT in the GMAC_EMAC_DTF register */
#define GMAC_EMAC_DTF_Msk                     _UINT32_(0x0003FFFF)                                 /* (GMAC_EMAC_DTF) Register Mask  */


/* -------- GMAC_EMAC_CSE : (GMAC Offset: 0x114C) ( R/ 32) Express MAC Carrier Sense Errors Register -------- */
#define GMAC_EMAC_CSE_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_CSE) Express MAC Carrier Sense Errors Register  Reset Value */

#define GMAC_EMAC_CSE_CSR_Pos                 _UINT32_(0)                                          /* (GMAC_EMAC_CSE) Carrier Sense Error Position */
#define GMAC_EMAC_CSE_CSR_Msk                 (_UINT32_(0x3FF) << GMAC_EMAC_CSE_CSR_Pos)           /* (GMAC_EMAC_CSE) Carrier Sense Error Mask */
#define GMAC_EMAC_CSE_CSR(value)              (GMAC_EMAC_CSE_CSR_Msk & (_UINT32_(value) << GMAC_EMAC_CSE_CSR_Pos)) /* Assigment of value for CSR in the GMAC_EMAC_CSE register */
#define GMAC_EMAC_CSE_Msk                     _UINT32_(0x000003FF)                                 /* (GMAC_EMAC_CSE) Register Mask  */


/* -------- GMAC_EMAC_ORLO : (GMAC Offset: 0x1150) ( R/ 32) Express MAC Octets Received Low Received Register -------- */
#define GMAC_EMAC_ORLO_RESETVALUE             _UINT32_(0x00)                                       /*  (GMAC_EMAC_ORLO) Express MAC Octets Received Low Received Register  Reset Value */

#define GMAC_EMAC_ORLO_RXO_Pos                _UINT32_(0)                                          /* (GMAC_EMAC_ORLO) Received Octets Position */
#define GMAC_EMAC_ORLO_RXO_Msk                (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_ORLO_RXO_Pos)     /* (GMAC_EMAC_ORLO) Received Octets Mask */
#define GMAC_EMAC_ORLO_RXO(value)             (GMAC_EMAC_ORLO_RXO_Msk & (_UINT32_(value) << GMAC_EMAC_ORLO_RXO_Pos)) /* Assigment of value for RXO in the GMAC_EMAC_ORLO register */
#define GMAC_EMAC_ORLO_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_ORLO) Register Mask  */


/* -------- GMAC_EMAC_ORHI : (GMAC Offset: 0x1154) ( R/ 32) Express MAC Octets Received High Received Register -------- */
#define GMAC_EMAC_ORHI_RESETVALUE             _UINT32_(0x00)                                       /*  (GMAC_EMAC_ORHI) Express MAC Octets Received High Received Register  Reset Value */

#define GMAC_EMAC_ORHI_RXO_Pos                _UINT32_(0)                                          /* (GMAC_EMAC_ORHI) Received Octets Position */
#define GMAC_EMAC_ORHI_RXO_Msk                (_UINT32_(0xFFFF) << GMAC_EMAC_ORHI_RXO_Pos)         /* (GMAC_EMAC_ORHI) Received Octets Mask */
#define GMAC_EMAC_ORHI_RXO(value)             (GMAC_EMAC_ORHI_RXO_Msk & (_UINT32_(value) << GMAC_EMAC_ORHI_RXO_Pos)) /* Assigment of value for RXO in the GMAC_EMAC_ORHI register */
#define GMAC_EMAC_ORHI_Msk                    _UINT32_(0x0000FFFF)                                 /* (GMAC_EMAC_ORHI) Register Mask  */


/* -------- GMAC_EMAC_FR : (GMAC Offset: 0x1158) ( R/ 32) Express MAC Frames Received Register -------- */
#define GMAC_EMAC_FR_RESETVALUE               _UINT32_(0x00)                                       /*  (GMAC_EMAC_FR) Express MAC Frames Received Register  Reset Value */

#define GMAC_EMAC_FR_FRX_Pos                  _UINT32_(0)                                          /* (GMAC_EMAC_FR) Frames Received without Error Position */
#define GMAC_EMAC_FR_FRX_Msk                  (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_FR_FRX_Pos)       /* (GMAC_EMAC_FR) Frames Received without Error Mask */
#define GMAC_EMAC_FR_FRX(value)               (GMAC_EMAC_FR_FRX_Msk & (_UINT32_(value) << GMAC_EMAC_FR_FRX_Pos)) /* Assigment of value for FRX in the GMAC_EMAC_FR register */
#define GMAC_EMAC_FR_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_FR) Register Mask  */


/* -------- GMAC_EMAC_BCFR : (GMAC Offset: 0x115C) ( R/ 32) Express MAC Broadcast Frames Received Register -------- */
#define GMAC_EMAC_BCFR_RESETVALUE             _UINT32_(0x00)                                       /*  (GMAC_EMAC_BCFR) Express MAC Broadcast Frames Received Register  Reset Value */

#define GMAC_EMAC_BCFR_BFRX_Pos               _UINT32_(0)                                          /* (GMAC_EMAC_BCFR) Broadcast Frames Received without Error Position */
#define GMAC_EMAC_BCFR_BFRX_Msk               (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_BCFR_BFRX_Pos)    /* (GMAC_EMAC_BCFR) Broadcast Frames Received without Error Mask */
#define GMAC_EMAC_BCFR_BFRX(value)            (GMAC_EMAC_BCFR_BFRX_Msk & (_UINT32_(value) << GMAC_EMAC_BCFR_BFRX_Pos)) /* Assigment of value for BFRX in the GMAC_EMAC_BCFR register */
#define GMAC_EMAC_BCFR_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_BCFR) Register Mask  */


/* -------- GMAC_EMAC_MFR : (GMAC Offset: 0x1160) ( R/ 32) Express MAC Multicast Frames Received Register -------- */
#define GMAC_EMAC_MFR_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_MFR) Express MAC Multicast Frames Received Register  Reset Value */

#define GMAC_EMAC_MFR_MFRX_Pos                _UINT32_(0)                                          /* (GMAC_EMAC_MFR) Multicast Frames Received without Error Position */
#define GMAC_EMAC_MFR_MFRX_Msk                (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_MFR_MFRX_Pos)     /* (GMAC_EMAC_MFR) Multicast Frames Received without Error Mask */
#define GMAC_EMAC_MFR_MFRX(value)             (GMAC_EMAC_MFR_MFRX_Msk & (_UINT32_(value) << GMAC_EMAC_MFR_MFRX_Pos)) /* Assigment of value for MFRX in the GMAC_EMAC_MFR register */
#define GMAC_EMAC_MFR_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_MFR) Register Mask  */


/* -------- GMAC_EMAC_PFR : (GMAC Offset: 0x1164) ( R/ 32) Express MAC Pause Frames Received Register -------- */
#define GMAC_EMAC_PFR_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_PFR) Express MAC Pause Frames Received Register  Reset Value */

#define GMAC_EMAC_PFR_PFRX_Pos                _UINT32_(0)                                          /* (GMAC_EMAC_PFR) Pause Frames Received Register Position */
#define GMAC_EMAC_PFR_PFRX_Msk                (_UINT32_(0xFFFF) << GMAC_EMAC_PFR_PFRX_Pos)         /* (GMAC_EMAC_PFR) Pause Frames Received Register Mask */
#define GMAC_EMAC_PFR_PFRX(value)             (GMAC_EMAC_PFR_PFRX_Msk & (_UINT32_(value) << GMAC_EMAC_PFR_PFRX_Pos)) /* Assigment of value for PFRX in the GMAC_EMAC_PFR register */
#define GMAC_EMAC_PFR_Msk                     _UINT32_(0x0000FFFF)                                 /* (GMAC_EMAC_PFR) Register Mask  */


/* -------- GMAC_EMAC_BFR64 : (GMAC Offset: 0x1168) ( R/ 32) Express MAC 64 Byte Frames Received Register -------- */
#define GMAC_EMAC_BFR64_RESETVALUE            _UINT32_(0x00)                                       /*  (GMAC_EMAC_BFR64) Express MAC 64 Byte Frames Received Register  Reset Value */

#define GMAC_EMAC_BFR64_NFRX_Pos              _UINT32_(0)                                          /* (GMAC_EMAC_BFR64) 64 Byte Frames Received without Error Position */
#define GMAC_EMAC_BFR64_NFRX_Msk              (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_BFR64_NFRX_Pos)   /* (GMAC_EMAC_BFR64) 64 Byte Frames Received without Error Mask */
#define GMAC_EMAC_BFR64_NFRX(value)           (GMAC_EMAC_BFR64_NFRX_Msk & (_UINT32_(value) << GMAC_EMAC_BFR64_NFRX_Pos)) /* Assigment of value for NFRX in the GMAC_EMAC_BFR64 register */
#define GMAC_EMAC_BFR64_Msk                   _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_BFR64) Register Mask  */


/* -------- GMAC_EMAC_TBFR127 : (GMAC Offset: 0x116C) ( R/ 32) Express MAC 65 to 127 Byte Frames Received Register -------- */
#define GMAC_EMAC_TBFR127_RESETVALUE          _UINT32_(0x00)                                       /*  (GMAC_EMAC_TBFR127) Express MAC 65 to 127 Byte Frames Received Register  Reset Value */

#define GMAC_EMAC_TBFR127_NFRX_Pos            _UINT32_(0)                                          /* (GMAC_EMAC_TBFR127) 65 to 127 Byte Frames Received without Error Position */
#define GMAC_EMAC_TBFR127_NFRX_Msk            (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_TBFR127_NFRX_Pos) /* (GMAC_EMAC_TBFR127) 65 to 127 Byte Frames Received without Error Mask */
#define GMAC_EMAC_TBFR127_NFRX(value)         (GMAC_EMAC_TBFR127_NFRX_Msk & (_UINT32_(value) << GMAC_EMAC_TBFR127_NFRX_Pos)) /* Assigment of value for NFRX in the GMAC_EMAC_TBFR127 register */
#define GMAC_EMAC_TBFR127_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_TBFR127) Register Mask  */


/* -------- GMAC_EMAC_TBFR255 : (GMAC Offset: 0x1170) ( R/ 32) Express MAC 128 to 255 Byte Frames Received Register -------- */
#define GMAC_EMAC_TBFR255_RESETVALUE          _UINT32_(0x00)                                       /*  (GMAC_EMAC_TBFR255) Express MAC 128 to 255 Byte Frames Received Register  Reset Value */

#define GMAC_EMAC_TBFR255_NFRX_Pos            _UINT32_(0)                                          /* (GMAC_EMAC_TBFR255) 128 to 255 Byte Frames Received without Error Position */
#define GMAC_EMAC_TBFR255_NFRX_Msk            (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_TBFR255_NFRX_Pos) /* (GMAC_EMAC_TBFR255) 128 to 255 Byte Frames Received without Error Mask */
#define GMAC_EMAC_TBFR255_NFRX(value)         (GMAC_EMAC_TBFR255_NFRX_Msk & (_UINT32_(value) << GMAC_EMAC_TBFR255_NFRX_Pos)) /* Assigment of value for NFRX in the GMAC_EMAC_TBFR255 register */
#define GMAC_EMAC_TBFR255_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_TBFR255) Register Mask  */


/* -------- GMAC_EMAC_TBFR511 : (GMAC Offset: 0x1174) ( R/ 32) Express MAC 256 to 511 Byte Frames Received Register -------- */
#define GMAC_EMAC_TBFR511_RESETVALUE          _UINT32_(0x00)                                       /*  (GMAC_EMAC_TBFR511) Express MAC 256 to 511 Byte Frames Received Register  Reset Value */

#define GMAC_EMAC_TBFR511_NFRX_Pos            _UINT32_(0)                                          /* (GMAC_EMAC_TBFR511) 256 to 511 Byte Frames Received without Error Position */
#define GMAC_EMAC_TBFR511_NFRX_Msk            (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_TBFR511_NFRX_Pos) /* (GMAC_EMAC_TBFR511) 256 to 511 Byte Frames Received without Error Mask */
#define GMAC_EMAC_TBFR511_NFRX(value)         (GMAC_EMAC_TBFR511_NFRX_Msk & (_UINT32_(value) << GMAC_EMAC_TBFR511_NFRX_Pos)) /* Assigment of value for NFRX in the GMAC_EMAC_TBFR511 register */
#define GMAC_EMAC_TBFR511_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_TBFR511) Register Mask  */


/* -------- GMAC_EMAC_TBFR1023 : (GMAC Offset: 0x1178) ( R/ 32) Express MAC 512 to 1023 Byte Frames Received Register -------- */
#define GMAC_EMAC_TBFR1023_RESETVALUE         _UINT32_(0x00)                                       /*  (GMAC_EMAC_TBFR1023) Express MAC 512 to 1023 Byte Frames Received Register  Reset Value */

#define GMAC_EMAC_TBFR1023_NFRX_Pos           _UINT32_(0)                                          /* (GMAC_EMAC_TBFR1023) 512 to 1023 Byte Frames Received without Error Position */
#define GMAC_EMAC_TBFR1023_NFRX_Msk           (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_TBFR1023_NFRX_Pos) /* (GMAC_EMAC_TBFR1023) 512 to 1023 Byte Frames Received without Error Mask */
#define GMAC_EMAC_TBFR1023_NFRX(value)        (GMAC_EMAC_TBFR1023_NFRX_Msk & (_UINT32_(value) << GMAC_EMAC_TBFR1023_NFRX_Pos)) /* Assigment of value for NFRX in the GMAC_EMAC_TBFR1023 register */
#define GMAC_EMAC_TBFR1023_Msk                _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_TBFR1023) Register Mask  */


/* -------- GMAC_EMAC_TBFR1518 : (GMAC Offset: 0x117C) ( R/ 32) Express MAC 1024 to 1518 Byte Frames Received Register -------- */
#define GMAC_EMAC_TBFR1518_RESETVALUE         _UINT32_(0x00)                                       /*  (GMAC_EMAC_TBFR1518) Express MAC 1024 to 1518 Byte Frames Received Register  Reset Value */

#define GMAC_EMAC_TBFR1518_NFRX_Pos           _UINT32_(0)                                          /* (GMAC_EMAC_TBFR1518) 1024 to 1518 Byte Frames Received without Error Position */
#define GMAC_EMAC_TBFR1518_NFRX_Msk           (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_TBFR1518_NFRX_Pos) /* (GMAC_EMAC_TBFR1518) 1024 to 1518 Byte Frames Received without Error Mask */
#define GMAC_EMAC_TBFR1518_NFRX(value)        (GMAC_EMAC_TBFR1518_NFRX_Msk & (_UINT32_(value) << GMAC_EMAC_TBFR1518_NFRX_Pos)) /* Assigment of value for NFRX in the GMAC_EMAC_TBFR1518 register */
#define GMAC_EMAC_TBFR1518_Msk                _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_TBFR1518) Register Mask  */


/* -------- GMAC_EMAC_TMXBFR : (GMAC Offset: 0x1180) ( R/ 32) Express MAC 1519 to Maximum Byte Frames Received Register -------- */
#define GMAC_EMAC_TMXBFR_RESETVALUE           _UINT32_(0x00)                                       /*  (GMAC_EMAC_TMXBFR) Express MAC 1519 to Maximum Byte Frames Received Register  Reset Value */

#define GMAC_EMAC_TMXBFR_NFRX_Pos             _UINT32_(0)                                          /* (GMAC_EMAC_TMXBFR) 1519 to Maximum Byte Frames Received without Error Position */
#define GMAC_EMAC_TMXBFR_NFRX_Msk             (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_TMXBFR_NFRX_Pos)  /* (GMAC_EMAC_TMXBFR) 1519 to Maximum Byte Frames Received without Error Mask */
#define GMAC_EMAC_TMXBFR_NFRX(value)          (GMAC_EMAC_TMXBFR_NFRX_Msk & (_UINT32_(value) << GMAC_EMAC_TMXBFR_NFRX_Pos)) /* Assigment of value for NFRX in the GMAC_EMAC_TMXBFR register */
#define GMAC_EMAC_TMXBFR_Msk                  _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_TMXBFR) Register Mask  */


/* -------- GMAC_EMAC_UFR : (GMAC Offset: 0x1184) ( R/ 32) Express MAC Undersize Frames Received Register -------- */
#define GMAC_EMAC_UFR_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_UFR) Express MAC Undersize Frames Received Register  Reset Value */

#define GMAC_EMAC_UFR_UFRX_Pos                _UINT32_(0)                                          /* (GMAC_EMAC_UFR) Undersize Frames Received Position */
#define GMAC_EMAC_UFR_UFRX_Msk                (_UINT32_(0x3FF) << GMAC_EMAC_UFR_UFRX_Pos)          /* (GMAC_EMAC_UFR) Undersize Frames Received Mask */
#define GMAC_EMAC_UFR_UFRX(value)             (GMAC_EMAC_UFR_UFRX_Msk & (_UINT32_(value) << GMAC_EMAC_UFR_UFRX_Pos)) /* Assigment of value for UFRX in the GMAC_EMAC_UFR register */
#define GMAC_EMAC_UFR_Msk                     _UINT32_(0x000003FF)                                 /* (GMAC_EMAC_UFR) Register Mask  */


/* -------- GMAC_EMAC_OFR : (GMAC Offset: 0x1188) ( R/ 32) Express MAC Oversize Frames Received Register -------- */
#define GMAC_EMAC_OFR_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_OFR) Express MAC Oversize Frames Received Register  Reset Value */

#define GMAC_EMAC_OFR_OFRX_Pos                _UINT32_(0)                                          /* (GMAC_EMAC_OFR) Oversized Frames Received Position */
#define GMAC_EMAC_OFR_OFRX_Msk                (_UINT32_(0x3FF) << GMAC_EMAC_OFR_OFRX_Pos)          /* (GMAC_EMAC_OFR) Oversized Frames Received Mask */
#define GMAC_EMAC_OFR_OFRX(value)             (GMAC_EMAC_OFR_OFRX_Msk & (_UINT32_(value) << GMAC_EMAC_OFR_OFRX_Pos)) /* Assigment of value for OFRX in the GMAC_EMAC_OFR register */
#define GMAC_EMAC_OFR_Msk                     _UINT32_(0x000003FF)                                 /* (GMAC_EMAC_OFR) Register Mask  */


/* -------- GMAC_EMAC_JR : (GMAC Offset: 0x118C) ( R/ 32) Express MAC Jabbers Received Register -------- */
#define GMAC_EMAC_JR_RESETVALUE               _UINT32_(0x00)                                       /*  (GMAC_EMAC_JR) Express MAC Jabbers Received Register  Reset Value */

#define GMAC_EMAC_JR_JRX_Pos                  _UINT32_(0)                                          /* (GMAC_EMAC_JR) Jabbers Received Position */
#define GMAC_EMAC_JR_JRX_Msk                  (_UINT32_(0x3FF) << GMAC_EMAC_JR_JRX_Pos)            /* (GMAC_EMAC_JR) Jabbers Received Mask */
#define GMAC_EMAC_JR_JRX(value)               (GMAC_EMAC_JR_JRX_Msk & (_UINT32_(value) << GMAC_EMAC_JR_JRX_Pos)) /* Assigment of value for JRX in the GMAC_EMAC_JR register */
#define GMAC_EMAC_JR_Msk                      _UINT32_(0x000003FF)                                 /* (GMAC_EMAC_JR) Register Mask  */


/* -------- GMAC_EMAC_FCSE : (GMAC Offset: 0x1190) ( R/ 32) Express MAC Frame Check Sequence Errors Register -------- */
#define GMAC_EMAC_FCSE_RESETVALUE             _UINT32_(0x00)                                       /*  (GMAC_EMAC_FCSE) Express MAC Frame Check Sequence Errors Register  Reset Value */

#define GMAC_EMAC_FCSE_FCKR_Pos               _UINT32_(0)                                          /* (GMAC_EMAC_FCSE) Frame Check Sequence Errors Position */
#define GMAC_EMAC_FCSE_FCKR_Msk               (_UINT32_(0x3FF) << GMAC_EMAC_FCSE_FCKR_Pos)         /* (GMAC_EMAC_FCSE) Frame Check Sequence Errors Mask */
#define GMAC_EMAC_FCSE_FCKR(value)            (GMAC_EMAC_FCSE_FCKR_Msk & (_UINT32_(value) << GMAC_EMAC_FCSE_FCKR_Pos)) /* Assigment of value for FCKR in the GMAC_EMAC_FCSE register */
#define GMAC_EMAC_FCSE_Msk                    _UINT32_(0x000003FF)                                 /* (GMAC_EMAC_FCSE) Register Mask  */


/* -------- GMAC_EMAC_LFFE : (GMAC Offset: 0x1194) ( R/ 32) Express MAC Length Field Frame Errors Register -------- */
#define GMAC_EMAC_LFFE_RESETVALUE             _UINT32_(0x00)                                       /*  (GMAC_EMAC_LFFE) Express MAC Length Field Frame Errors Register  Reset Value */

#define GMAC_EMAC_LFFE_LFER_Pos               _UINT32_(0)                                          /* (GMAC_EMAC_LFFE) Length Field Frame Errors Position */
#define GMAC_EMAC_LFFE_LFER_Msk               (_UINT32_(0x3FF) << GMAC_EMAC_LFFE_LFER_Pos)         /* (GMAC_EMAC_LFFE) Length Field Frame Errors Mask */
#define GMAC_EMAC_LFFE_LFER(value)            (GMAC_EMAC_LFFE_LFER_Msk & (_UINT32_(value) << GMAC_EMAC_LFFE_LFER_Pos)) /* Assigment of value for LFER in the GMAC_EMAC_LFFE register */
#define GMAC_EMAC_LFFE_Msk                    _UINT32_(0x000003FF)                                 /* (GMAC_EMAC_LFFE) Register Mask  */


/* -------- GMAC_EMAC_RSE : (GMAC Offset: 0x1198) ( R/ 32) Express MAC Receive Symbol Errors Register -------- */
#define GMAC_EMAC_RSE_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_RSE) Express MAC Receive Symbol Errors Register  Reset Value */

#define GMAC_EMAC_RSE_RXSE_Pos                _UINT32_(0)                                          /* (GMAC_EMAC_RSE) Receive Symbol Errors Position */
#define GMAC_EMAC_RSE_RXSE_Msk                (_UINT32_(0x3FF) << GMAC_EMAC_RSE_RXSE_Pos)          /* (GMAC_EMAC_RSE) Receive Symbol Errors Mask */
#define GMAC_EMAC_RSE_RXSE(value)             (GMAC_EMAC_RSE_RXSE_Msk & (_UINT32_(value) << GMAC_EMAC_RSE_RXSE_Pos)) /* Assigment of value for RXSE in the GMAC_EMAC_RSE register */
#define GMAC_EMAC_RSE_Msk                     _UINT32_(0x000003FF)                                 /* (GMAC_EMAC_RSE) Register Mask  */


/* -------- GMAC_EMAC_AE : (GMAC Offset: 0x119C) ( R/ 32) Express MAC Alignment Errors Register -------- */
#define GMAC_EMAC_AE_RESETVALUE               _UINT32_(0x00)                                       /*  (GMAC_EMAC_AE) Express MAC Alignment Errors Register  Reset Value */

#define GMAC_EMAC_AE_AER_Pos                  _UINT32_(0)                                          /* (GMAC_EMAC_AE) Alignment Errors Position */
#define GMAC_EMAC_AE_AER_Msk                  (_UINT32_(0x3FF) << GMAC_EMAC_AE_AER_Pos)            /* (GMAC_EMAC_AE) Alignment Errors Mask */
#define GMAC_EMAC_AE_AER(value)               (GMAC_EMAC_AE_AER_Msk & (_UINT32_(value) << GMAC_EMAC_AE_AER_Pos)) /* Assigment of value for AER in the GMAC_EMAC_AE register */
#define GMAC_EMAC_AE_Msk                      _UINT32_(0x000003FF)                                 /* (GMAC_EMAC_AE) Register Mask  */


/* -------- GMAC_EMAC_RRE : (GMAC Offset: 0x11A0) ( R/ 32) Express MAC Receive Resource Errors Register -------- */
#define GMAC_EMAC_RRE_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_RRE) Express MAC Receive Resource Errors Register  Reset Value */

#define GMAC_EMAC_RRE_RXRER_Pos               _UINT32_(0)                                          /* (GMAC_EMAC_RRE) Receive Resource Errors Position */
#define GMAC_EMAC_RRE_RXRER_Msk               (_UINT32_(0x3FFFF) << GMAC_EMAC_RRE_RXRER_Pos)       /* (GMAC_EMAC_RRE) Receive Resource Errors Mask */
#define GMAC_EMAC_RRE_RXRER(value)            (GMAC_EMAC_RRE_RXRER_Msk & (_UINT32_(value) << GMAC_EMAC_RRE_RXRER_Pos)) /* Assigment of value for RXRER in the GMAC_EMAC_RRE register */
#define GMAC_EMAC_RRE_Msk                     _UINT32_(0x0003FFFF)                                 /* (GMAC_EMAC_RRE) Register Mask  */


/* -------- GMAC_EMAC_ROE : (GMAC Offset: 0x11A4) ( R/ 32) Express MAC Receive Overrun Register -------- */
#define GMAC_EMAC_ROE_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_ROE) Express MAC Receive Overrun Register  Reset Value */

#define GMAC_EMAC_ROE_RXOVR_Pos               _UINT32_(0)                                          /* (GMAC_EMAC_ROE) Receive Overruns Position */
#define GMAC_EMAC_ROE_RXOVR_Msk               (_UINT32_(0x3FF) << GMAC_EMAC_ROE_RXOVR_Pos)         /* (GMAC_EMAC_ROE) Receive Overruns Mask */
#define GMAC_EMAC_ROE_RXOVR(value)            (GMAC_EMAC_ROE_RXOVR_Msk & (_UINT32_(value) << GMAC_EMAC_ROE_RXOVR_Pos)) /* Assigment of value for RXOVR in the GMAC_EMAC_ROE register */
#define GMAC_EMAC_ROE_Msk                     _UINT32_(0x000003FF)                                 /* (GMAC_EMAC_ROE) Register Mask  */


/* -------- GMAC_EMAC_IHCE : (GMAC Offset: 0x11A8) ( R/ 32) Express MAC IP Header Checksum Errors Register -------- */
#define GMAC_EMAC_IHCE_RESETVALUE             _UINT32_(0x00)                                       /*  (GMAC_EMAC_IHCE) Express MAC IP Header Checksum Errors Register  Reset Value */

#define GMAC_EMAC_IHCE_HCKER_Pos              _UINT32_(0)                                          /* (GMAC_EMAC_IHCE) IP Header Checksum Errors Position */
#define GMAC_EMAC_IHCE_HCKER_Msk              (_UINT32_(0xFF) << GMAC_EMAC_IHCE_HCKER_Pos)         /* (GMAC_EMAC_IHCE) IP Header Checksum Errors Mask */
#define GMAC_EMAC_IHCE_HCKER(value)           (GMAC_EMAC_IHCE_HCKER_Msk & (_UINT32_(value) << GMAC_EMAC_IHCE_HCKER_Pos)) /* Assigment of value for HCKER in the GMAC_EMAC_IHCE register */
#define GMAC_EMAC_IHCE_Msk                    _UINT32_(0x000000FF)                                 /* (GMAC_EMAC_IHCE) Register Mask  */


/* -------- GMAC_EMAC_TCE : (GMAC Offset: 0x11AC) ( R/ 32) Express MAC TCP Checksum Errors Register -------- */
#define GMAC_EMAC_TCE_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_TCE) Express MAC TCP Checksum Errors Register  Reset Value */

#define GMAC_EMAC_TCE_TCKER_Pos               _UINT32_(0)                                          /* (GMAC_EMAC_TCE) TCP Checksum Errors Position */
#define GMAC_EMAC_TCE_TCKER_Msk               (_UINT32_(0xFF) << GMAC_EMAC_TCE_TCKER_Pos)          /* (GMAC_EMAC_TCE) TCP Checksum Errors Mask */
#define GMAC_EMAC_TCE_TCKER(value)            (GMAC_EMAC_TCE_TCKER_Msk & (_UINT32_(value) << GMAC_EMAC_TCE_TCKER_Pos)) /* Assigment of value for TCKER in the GMAC_EMAC_TCE register */
#define GMAC_EMAC_TCE_Msk                     _UINT32_(0x000000FF)                                 /* (GMAC_EMAC_TCE) Register Mask  */


/* -------- GMAC_EMAC_UCE : (GMAC Offset: 0x11B0) ( R/ 32) Express MAC UDP Checksum Errors Register -------- */
#define GMAC_EMAC_UCE_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_UCE) Express MAC UDP Checksum Errors Register  Reset Value */

#define GMAC_EMAC_UCE_UCKER_Pos               _UINT32_(0)                                          /* (GMAC_EMAC_UCE) UDP Checksum Errors Position */
#define GMAC_EMAC_UCE_UCKER_Msk               (_UINT32_(0xFF) << GMAC_EMAC_UCE_UCKER_Pos)          /* (GMAC_EMAC_UCE) UDP Checksum Errors Mask */
#define GMAC_EMAC_UCE_UCKER(value)            (GMAC_EMAC_UCE_UCKER_Msk & (_UINT32_(value) << GMAC_EMAC_UCE_UCKER_Pos)) /* Assigment of value for UCKER in the GMAC_EMAC_UCE register */
#define GMAC_EMAC_UCE_Msk                     _UINT32_(0x000000FF)                                 /* (GMAC_EMAC_UCE) Register Mask  */


/* -------- GMAC_EMAC_FLRXPCR : (GMAC Offset: 0x11B4) ( R/ 32) Express MAC Flushed Received Packets Counter Register -------- */
#define GMAC_EMAC_FLRXPCR_RESETVALUE          _UINT32_(0x00)                                       /*  (GMAC_EMAC_FLRXPCR) Express MAC Flushed Received Packets Counter Register  Reset Value */

#define GMAC_EMAC_FLRXPCR_COUNT_Pos           _UINT32_(0)                                          /* (GMAC_EMAC_FLRXPCR) Flushed Received Packets Count (cleared on read) Position */
#define GMAC_EMAC_FLRXPCR_COUNT_Msk           (_UINT32_(0xFFFF) << GMAC_EMAC_FLRXPCR_COUNT_Pos)    /* (GMAC_EMAC_FLRXPCR) Flushed Received Packets Count (cleared on read) Mask */
#define GMAC_EMAC_FLRXPCR_COUNT(value)        (GMAC_EMAC_FLRXPCR_COUNT_Msk & (_UINT32_(value) << GMAC_EMAC_FLRXPCR_COUNT_Pos)) /* Assigment of value for COUNT in the GMAC_EMAC_FLRXPCR register */
#define GMAC_EMAC_FLRXPCR_Msk                 _UINT32_(0x0000FFFF)                                 /* (GMAC_EMAC_FLRXPCR) Register Mask  */


/* -------- GMAC_EMAC_TISUBN : (GMAC Offset: 0x11BC) (R/W 32) Express MAC 1588 Timer Increment Sub-nanoseconds Register -------- */
#define GMAC_EMAC_TISUBN_RESETVALUE           _UINT32_(0x00)                                       /*  (GMAC_EMAC_TISUBN) Express MAC 1588 Timer Increment Sub-nanoseconds Register  Reset Value */

#define GMAC_EMAC_TISUBN_MSBTIR_Pos           _UINT32_(0)                                          /* (GMAC_EMAC_TISUBN) Most Significant Bits of Timer Increment Register Position */
#define GMAC_EMAC_TISUBN_MSBTIR_Msk           (_UINT32_(0xFFFF) << GMAC_EMAC_TISUBN_MSBTIR_Pos)    /* (GMAC_EMAC_TISUBN) Most Significant Bits of Timer Increment Register Mask */
#define GMAC_EMAC_TISUBN_MSBTIR(value)        (GMAC_EMAC_TISUBN_MSBTIR_Msk & (_UINT32_(value) << GMAC_EMAC_TISUBN_MSBTIR_Pos)) /* Assigment of value for MSBTIR in the GMAC_EMAC_TISUBN register */
#define GMAC_EMAC_TISUBN_LSBTIR_Pos           _UINT32_(24)                                         /* (GMAC_EMAC_TISUBN) Lower Significant Bits of Timer Increment Register Position */
#define GMAC_EMAC_TISUBN_LSBTIR_Msk           (_UINT32_(0xFF) << GMAC_EMAC_TISUBN_LSBTIR_Pos)      /* (GMAC_EMAC_TISUBN) Lower Significant Bits of Timer Increment Register Mask */
#define GMAC_EMAC_TISUBN_LSBTIR(value)        (GMAC_EMAC_TISUBN_LSBTIR_Msk & (_UINT32_(value) << GMAC_EMAC_TISUBN_LSBTIR_Pos)) /* Assigment of value for LSBTIR in the GMAC_EMAC_TISUBN register */
#define GMAC_EMAC_TISUBN_Msk                  _UINT32_(0xFF00FFFF)                                 /* (GMAC_EMAC_TISUBN) Register Mask  */


/* -------- GMAC_EMAC_TSH : (GMAC Offset: 0x11C0) (R/W 32) Express MAC1588 Timer Seconds High Register -------- */
#define GMAC_EMAC_TSH_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_TSH) Express MAC1588 Timer Seconds High Register  Reset Value */

#define GMAC_EMAC_TSH_TCS_Pos                 _UINT32_(0)                                          /* (GMAC_EMAC_TSH) Timer Count in Seconds Position */
#define GMAC_EMAC_TSH_TCS_Msk                 (_UINT32_(0xFFFF) << GMAC_EMAC_TSH_TCS_Pos)          /* (GMAC_EMAC_TSH) Timer Count in Seconds Mask */
#define GMAC_EMAC_TSH_TCS(value)              (GMAC_EMAC_TSH_TCS_Msk & (_UINT32_(value) << GMAC_EMAC_TSH_TCS_Pos)) /* Assigment of value for TCS in the GMAC_EMAC_TSH register */
#define GMAC_EMAC_TSH_Msk                     _UINT32_(0x0000FFFF)                                 /* (GMAC_EMAC_TSH) Register Mask  */


/* -------- GMAC_EMAC_TSL : (GMAC Offset: 0x11D0) (R/W 32) Express MAC1588 Timer Seconds Low Register -------- */
#define GMAC_EMAC_TSL_RESETVALUE              _UINT32_(0x00)                                       /*  (GMAC_EMAC_TSL) Express MAC1588 Timer Seconds Low Register  Reset Value */

#define GMAC_EMAC_TSL_TCS_Pos                 _UINT32_(0)                                          /* (GMAC_EMAC_TSL) Timer Count in Seconds Position */
#define GMAC_EMAC_TSL_TCS_Msk                 (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_TSL_TCS_Pos)      /* (GMAC_EMAC_TSL) Timer Count in Seconds Mask */
#define GMAC_EMAC_TSL_TCS(value)              (GMAC_EMAC_TSL_TCS_Msk & (_UINT32_(value) << GMAC_EMAC_TSL_TCS_Pos)) /* Assigment of value for TCS in the GMAC_EMAC_TSL register */
#define GMAC_EMAC_TSL_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_TSL) Register Mask  */


/* -------- GMAC_EMAC_TN : (GMAC Offset: 0x11D4) (R/W 32) Express MAC1588 Timer Nanoseconds Register -------- */
#define GMAC_EMAC_TN_RESETVALUE               _UINT32_(0x00)                                       /*  (GMAC_EMAC_TN) Express MAC1588 Timer Nanoseconds Register  Reset Value */

#define GMAC_EMAC_TN_TNS_Pos                  _UINT32_(0)                                          /* (GMAC_EMAC_TN) Timer Count in Nanoseconds Position */
#define GMAC_EMAC_TN_TNS_Msk                  (_UINT32_(0x3FFFFFFF) << GMAC_EMAC_TN_TNS_Pos)       /* (GMAC_EMAC_TN) Timer Count in Nanoseconds Mask */
#define GMAC_EMAC_TN_TNS(value)               (GMAC_EMAC_TN_TNS_Msk & (_UINT32_(value) << GMAC_EMAC_TN_TNS_Pos)) /* Assigment of value for TNS in the GMAC_EMAC_TN register */
#define GMAC_EMAC_TN_Msk                      _UINT32_(0x3FFFFFFF)                                 /* (GMAC_EMAC_TN) Register Mask  */


/* -------- GMAC_EMAC_TA : (GMAC Offset: 0x11D8) ( /W 32) Express MAC1588 Timer Adjust Register -------- */
#define GMAC_EMAC_TA_ITDT_Pos                 _UINT32_(0)                                          /* (GMAC_EMAC_TA) Increment/Decrement Position */
#define GMAC_EMAC_TA_ITDT_Msk                 (_UINT32_(0x3FFFFFFF) << GMAC_EMAC_TA_ITDT_Pos)      /* (GMAC_EMAC_TA) Increment/Decrement Mask */
#define GMAC_EMAC_TA_ITDT(value)              (GMAC_EMAC_TA_ITDT_Msk & (_UINT32_(value) << GMAC_EMAC_TA_ITDT_Pos)) /* Assigment of value for ITDT in the GMAC_EMAC_TA register */
#define GMAC_EMAC_TA_ADJ_Pos                  _UINT32_(31)                                         /* (GMAC_EMAC_TA) Adjust 1588 Timer Position */
#define GMAC_EMAC_TA_ADJ_Msk                  (_UINT32_(0x1) << GMAC_EMAC_TA_ADJ_Pos)              /* (GMAC_EMAC_TA) Adjust 1588 Timer Mask */
#define GMAC_EMAC_TA_ADJ(value)               (GMAC_EMAC_TA_ADJ_Msk & (_UINT32_(value) << GMAC_EMAC_TA_ADJ_Pos)) /* Assigment of value for ADJ in the GMAC_EMAC_TA register */
#define GMAC_EMAC_TA_Msk                      _UINT32_(0xBFFFFFFF)                                 /* (GMAC_EMAC_TA) Register Mask  */


/* -------- GMAC_EMAC_TI : (GMAC Offset: 0x11DC) (R/W 32) Express MAC1588 Timer Increment Register -------- */
#define GMAC_EMAC_TI_RESETVALUE               _UINT32_(0x00)                                       /*  (GMAC_EMAC_TI) Express MAC1588 Timer Increment Register  Reset Value */

#define GMAC_EMAC_TI_CNS_Pos                  _UINT32_(0)                                          /* (GMAC_EMAC_TI) Count Nanoseconds Position */
#define GMAC_EMAC_TI_CNS_Msk                  (_UINT32_(0xFF) << GMAC_EMAC_TI_CNS_Pos)             /* (GMAC_EMAC_TI) Count Nanoseconds Mask */
#define GMAC_EMAC_TI_CNS(value)               (GMAC_EMAC_TI_CNS_Msk & (_UINT32_(value) << GMAC_EMAC_TI_CNS_Pos)) /* Assigment of value for CNS in the GMAC_EMAC_TI register */
#define GMAC_EMAC_TI_ACNS_Pos                 _UINT32_(8)                                          /* (GMAC_EMAC_TI) Alternative Count Nanoseconds Position */
#define GMAC_EMAC_TI_ACNS_Msk                 (_UINT32_(0xFF) << GMAC_EMAC_TI_ACNS_Pos)            /* (GMAC_EMAC_TI) Alternative Count Nanoseconds Mask */
#define GMAC_EMAC_TI_ACNS(value)              (GMAC_EMAC_TI_ACNS_Msk & (_UINT32_(value) << GMAC_EMAC_TI_ACNS_Pos)) /* Assigment of value for ACNS in the GMAC_EMAC_TI register */
#define GMAC_EMAC_TI_NIT_Pos                  _UINT32_(16)                                         /* (GMAC_EMAC_TI) Number of Increments Position */
#define GMAC_EMAC_TI_NIT_Msk                  (_UINT32_(0xFF) << GMAC_EMAC_TI_NIT_Pos)             /* (GMAC_EMAC_TI) Number of Increments Mask */
#define GMAC_EMAC_TI_NIT(value)               (GMAC_EMAC_TI_NIT_Msk & (_UINT32_(value) << GMAC_EMAC_TI_NIT_Pos)) /* Assigment of value for NIT in the GMAC_EMAC_TI register */
#define GMAC_EMAC_TI_Msk                      _UINT32_(0x00FFFFFF)                                 /* (GMAC_EMAC_TI) Register Mask  */


/* -------- GMAC_EMAC_EFTSL : (GMAC Offset: 0x11E0) ( R/ 32) Express MAC PTP Event Frame Transmitted Seconds Low Register -------- */
#define GMAC_EMAC_EFTSL_RESETVALUE            _UINT32_(0x00)                                       /*  (GMAC_EMAC_EFTSL) Express MAC PTP Event Frame Transmitted Seconds Low Register  Reset Value */

#define GMAC_EMAC_EFTSL_RUD_Pos               _UINT32_(0)                                          /* (GMAC_EMAC_EFTSL) Register Update Position */
#define GMAC_EMAC_EFTSL_RUD_Msk               (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_EFTSL_RUD_Pos)    /* (GMAC_EMAC_EFTSL) Register Update Mask */
#define GMAC_EMAC_EFTSL_RUD(value)            (GMAC_EMAC_EFTSL_RUD_Msk & (_UINT32_(value) << GMAC_EMAC_EFTSL_RUD_Pos)) /* Assigment of value for RUD in the GMAC_EMAC_EFTSL register */
#define GMAC_EMAC_EFTSL_Msk                   _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_EFTSL) Register Mask  */


/* -------- GMAC_EMAC_EFTN : (GMAC Offset: 0x11E4) ( R/ 32) Express MAC PTP Event Frame Transmitted Nanoseconds Register -------- */
#define GMAC_EMAC_EFTN_RESETVALUE             _UINT32_(0x00)                                       /*  (GMAC_EMAC_EFTN) Express MAC PTP Event Frame Transmitted Nanoseconds Register  Reset Value */

#define GMAC_EMAC_EFTN_RUD_Pos                _UINT32_(0)                                          /* (GMAC_EMAC_EFTN) Register Update Position */
#define GMAC_EMAC_EFTN_RUD_Msk                (_UINT32_(0x3FFFFFFF) << GMAC_EMAC_EFTN_RUD_Pos)     /* (GMAC_EMAC_EFTN) Register Update Mask */
#define GMAC_EMAC_EFTN_RUD(value)             (GMAC_EMAC_EFTN_RUD_Msk & (_UINT32_(value) << GMAC_EMAC_EFTN_RUD_Pos)) /* Assigment of value for RUD in the GMAC_EMAC_EFTN register */
#define GMAC_EMAC_EFTN_Msk                    _UINT32_(0x3FFFFFFF)                                 /* (GMAC_EMAC_EFTN) Register Mask  */


/* -------- GMAC_EMAC_EFRSL : (GMAC Offset: 0x11E8) ( R/ 32) Express MAC PTP Event Frame Received Seconds Low Register -------- */
#define GMAC_EMAC_EFRSL_RESETVALUE            _UINT32_(0x00)                                       /*  (GMAC_EMAC_EFRSL) Express MAC PTP Event Frame Received Seconds Low Register  Reset Value */

#define GMAC_EMAC_EFRSL_RUD_Pos               _UINT32_(0)                                          /* (GMAC_EMAC_EFRSL) Register Update Position */
#define GMAC_EMAC_EFRSL_RUD_Msk               (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_EFRSL_RUD_Pos)    /* (GMAC_EMAC_EFRSL) Register Update Mask */
#define GMAC_EMAC_EFRSL_RUD(value)            (GMAC_EMAC_EFRSL_RUD_Msk & (_UINT32_(value) << GMAC_EMAC_EFRSL_RUD_Pos)) /* Assigment of value for RUD in the GMAC_EMAC_EFRSL register */
#define GMAC_EMAC_EFRSL_Msk                   _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_EFRSL) Register Mask  */


/* -------- GMAC_EMAC_EFRN : (GMAC Offset: 0x11EC) ( R/ 32) Express MAC PTP Event Frame Received Nanoseconds Register -------- */
#define GMAC_EMAC_EFRN_RESETVALUE             _UINT32_(0x00)                                       /*  (GMAC_EMAC_EFRN) Express MAC PTP Event Frame Received Nanoseconds Register  Reset Value */

#define GMAC_EMAC_EFRN_RUD_Pos                _UINT32_(0)                                          /* (GMAC_EMAC_EFRN) Register Update Position */
#define GMAC_EMAC_EFRN_RUD_Msk                (_UINT32_(0x3FFFFFFF) << GMAC_EMAC_EFRN_RUD_Pos)     /* (GMAC_EMAC_EFRN) Register Update Mask */
#define GMAC_EMAC_EFRN_RUD(value)             (GMAC_EMAC_EFRN_RUD_Msk & (_UINT32_(value) << GMAC_EMAC_EFRN_RUD_Pos)) /* Assigment of value for RUD in the GMAC_EMAC_EFRN register */
#define GMAC_EMAC_EFRN_Msk                    _UINT32_(0x3FFFFFFF)                                 /* (GMAC_EMAC_EFRN) Register Mask  */


/* -------- GMAC_EMAC_PEFTSL : (GMAC Offset: 0x11F0) ( R/ 32) Express MAC PTP Peer Event Frame Transmitted Seconds Low Register -------- */
#define GMAC_EMAC_PEFTSL_RESETVALUE           _UINT32_(0x00)                                       /*  (GMAC_EMAC_PEFTSL) Express MAC PTP Peer Event Frame Transmitted Seconds Low Register  Reset Value */

#define GMAC_EMAC_PEFTSL_RUD_Pos              _UINT32_(0)                                          /* (GMAC_EMAC_PEFTSL) Register Update Position */
#define GMAC_EMAC_PEFTSL_RUD_Msk              (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_PEFTSL_RUD_Pos)   /* (GMAC_EMAC_PEFTSL) Register Update Mask */
#define GMAC_EMAC_PEFTSL_RUD(value)           (GMAC_EMAC_PEFTSL_RUD_Msk & (_UINT32_(value) << GMAC_EMAC_PEFTSL_RUD_Pos)) /* Assigment of value for RUD in the GMAC_EMAC_PEFTSL register */
#define GMAC_EMAC_PEFTSL_Msk                  _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_PEFTSL) Register Mask  */


/* -------- GMAC_EMAC_PEFTN : (GMAC Offset: 0x11F4) ( R/ 32) Express MAC PTP Peer Event Frame Transmitted Nanoseconds Register -------- */
#define GMAC_EMAC_PEFTN_RESETVALUE            _UINT32_(0x00)                                       /*  (GMAC_EMAC_PEFTN) Express MAC PTP Peer Event Frame Transmitted Nanoseconds Register  Reset Value */

#define GMAC_EMAC_PEFTN_RUD_Pos               _UINT32_(0)                                          /* (GMAC_EMAC_PEFTN) Register Update Position */
#define GMAC_EMAC_PEFTN_RUD_Msk               (_UINT32_(0x3FFFFFFF) << GMAC_EMAC_PEFTN_RUD_Pos)    /* (GMAC_EMAC_PEFTN) Register Update Mask */
#define GMAC_EMAC_PEFTN_RUD(value)            (GMAC_EMAC_PEFTN_RUD_Msk & (_UINT32_(value) << GMAC_EMAC_PEFTN_RUD_Pos)) /* Assigment of value for RUD in the GMAC_EMAC_PEFTN register */
#define GMAC_EMAC_PEFTN_Msk                   _UINT32_(0x3FFFFFFF)                                 /* (GMAC_EMAC_PEFTN) Register Mask  */


/* -------- GMAC_EMAC_PEFRSL : (GMAC Offset: 0x11F8) ( R/ 32) Express MAC PTP Peer Event Frame Received Seconds Low Register -------- */
#define GMAC_EMAC_PEFRSL_RESETVALUE           _UINT32_(0x00)                                       /*  (GMAC_EMAC_PEFRSL) Express MAC PTP Peer Event Frame Received Seconds Low Register  Reset Value */

#define GMAC_EMAC_PEFRSL_RUD_Pos              _UINT32_(0)                                          /* (GMAC_EMAC_PEFRSL) Register Update Position */
#define GMAC_EMAC_PEFRSL_RUD_Msk              (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_PEFRSL_RUD_Pos)   /* (GMAC_EMAC_PEFRSL) Register Update Mask */
#define GMAC_EMAC_PEFRSL_RUD(value)           (GMAC_EMAC_PEFRSL_RUD_Msk & (_UINT32_(value) << GMAC_EMAC_PEFRSL_RUD_Pos)) /* Assigment of value for RUD in the GMAC_EMAC_PEFRSL register */
#define GMAC_EMAC_PEFRSL_Msk                  _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_PEFRSL) Register Mask  */


/* -------- GMAC_EMAC_PEFRN : (GMAC Offset: 0x11FC) ( R/ 32) Express MAC PTP Peer Event Frame Received Nanoseconds Register -------- */
#define GMAC_EMAC_PEFRN_RESETVALUE            _UINT32_(0x00)                                       /*  (GMAC_EMAC_PEFRN) Express MAC PTP Peer Event Frame Received Nanoseconds Register  Reset Value */

#define GMAC_EMAC_PEFRN_RUD_Pos               _UINT32_(0)                                          /* (GMAC_EMAC_PEFRN) Register Update Position */
#define GMAC_EMAC_PEFRN_RUD_Msk               (_UINT32_(0x3FFFFFFF) << GMAC_EMAC_PEFRN_RUD_Pos)    /* (GMAC_EMAC_PEFRN) Register Update Mask */
#define GMAC_EMAC_PEFRN_RUD(value)            (GMAC_EMAC_PEFRN_RUD_Msk & (_UINT32_(value) << GMAC_EMAC_PEFRN_RUD_Pos)) /* Assigment of value for RUD in the GMAC_EMAC_PEFRN register */
#define GMAC_EMAC_PEFRN_Msk                   _UINT32_(0x3FFFFFFF)                                 /* (GMAC_EMAC_PEFRN) Register Mask  */


/* -------- GMAC_EMAC_TXPQUANT1 : (GMAC Offset: 0x1260) (R/W 32) Express MAC Transmit Pause Quantum 1 Register -------- */
#define GMAC_EMAC_TXPQUANT1_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (GMAC_EMAC_TXPQUANT1) Express MAC Transmit Pause Quantum 1 Register  Reset Value */

#define GMAC_EMAC_TXPQUANT1_QUANT_P2_Pos      _UINT32_(0)                                          /* (GMAC_EMAC_TXPQUANT1) Priority 2 Transmit Pause Quantum Position */
#define GMAC_EMAC_TXPQUANT1_QUANT_P2_Msk      (_UINT32_(0xFFFF) << GMAC_EMAC_TXPQUANT1_QUANT_P2_Pos) /* (GMAC_EMAC_TXPQUANT1) Priority 2 Transmit Pause Quantum Mask */
#define GMAC_EMAC_TXPQUANT1_QUANT_P2(value)   (GMAC_EMAC_TXPQUANT1_QUANT_P2_Msk & (_UINT32_(value) << GMAC_EMAC_TXPQUANT1_QUANT_P2_Pos)) /* Assigment of value for QUANT_P2 in the GMAC_EMAC_TXPQUANT1 register */
#define GMAC_EMAC_TXPQUANT1_QUANT_P3_Pos      _UINT32_(16)                                         /* (GMAC_EMAC_TXPQUANT1) Priority 3 Transmit Pause Quantum Position */
#define GMAC_EMAC_TXPQUANT1_QUANT_P3_Msk      (_UINT32_(0xFFFF) << GMAC_EMAC_TXPQUANT1_QUANT_P3_Pos) /* (GMAC_EMAC_TXPQUANT1) Priority 3 Transmit Pause Quantum Mask */
#define GMAC_EMAC_TXPQUANT1_QUANT_P3(value)   (GMAC_EMAC_TXPQUANT1_QUANT_P3_Msk & (_UINT32_(value) << GMAC_EMAC_TXPQUANT1_QUANT_P3_Pos)) /* Assigment of value for QUANT_P3 in the GMAC_EMAC_TXPQUANT1 register */
#define GMAC_EMAC_TXPQUANT1_Msk               _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_TXPQUANT1) Register Mask  */


/* -------- GMAC_EMAC_TXPQUANT2 : (GMAC Offset: 0x1264) (R/W 32) Express MAC Transmit Pause Quantum 2 Register -------- */
#define GMAC_EMAC_TXPQUANT2_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (GMAC_EMAC_TXPQUANT2) Express MAC Transmit Pause Quantum 2 Register  Reset Value */

#define GMAC_EMAC_TXPQUANT2_QUANT_P4_Pos      _UINT32_(0)                                          /* (GMAC_EMAC_TXPQUANT2) Priority 4 Transmit Pause Quantum Position */
#define GMAC_EMAC_TXPQUANT2_QUANT_P4_Msk      (_UINT32_(0xFFFF) << GMAC_EMAC_TXPQUANT2_QUANT_P4_Pos) /* (GMAC_EMAC_TXPQUANT2) Priority 4 Transmit Pause Quantum Mask */
#define GMAC_EMAC_TXPQUANT2_QUANT_P4(value)   (GMAC_EMAC_TXPQUANT2_QUANT_P4_Msk & (_UINT32_(value) << GMAC_EMAC_TXPQUANT2_QUANT_P4_Pos)) /* Assigment of value for QUANT_P4 in the GMAC_EMAC_TXPQUANT2 register */
#define GMAC_EMAC_TXPQUANT2_QUANT_P5_Pos      _UINT32_(16)                                         /* (GMAC_EMAC_TXPQUANT2) Priority 5 Transmit Pause Quantum Position */
#define GMAC_EMAC_TXPQUANT2_QUANT_P5_Msk      (_UINT32_(0xFFFF) << GMAC_EMAC_TXPQUANT2_QUANT_P5_Pos) /* (GMAC_EMAC_TXPQUANT2) Priority 5 Transmit Pause Quantum Mask */
#define GMAC_EMAC_TXPQUANT2_QUANT_P5(value)   (GMAC_EMAC_TXPQUANT2_QUANT_P5_Msk & (_UINT32_(value) << GMAC_EMAC_TXPQUANT2_QUANT_P5_Pos)) /* Assigment of value for QUANT_P5 in the GMAC_EMAC_TXPQUANT2 register */
#define GMAC_EMAC_TXPQUANT2_Msk               _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_TXPQUANT2) Register Mask  */


/* -------- GMAC_EMAC_TXPQUANT3 : (GMAC Offset: 0x1268) (R/W 32) Express MAC Transmit Pause Quantum 3 Register -------- */
#define GMAC_EMAC_TXPQUANT3_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (GMAC_EMAC_TXPQUANT3) Express MAC Transmit Pause Quantum 3 Register  Reset Value */

#define GMAC_EMAC_TXPQUANT3_QUANT_P6_Pos      _UINT32_(0)                                          /* (GMAC_EMAC_TXPQUANT3) Priority 6 Transmit Pause Quantum Position */
#define GMAC_EMAC_TXPQUANT3_QUANT_P6_Msk      (_UINT32_(0xFFFF) << GMAC_EMAC_TXPQUANT3_QUANT_P6_Pos) /* (GMAC_EMAC_TXPQUANT3) Priority 6 Transmit Pause Quantum Mask */
#define GMAC_EMAC_TXPQUANT3_QUANT_P6(value)   (GMAC_EMAC_TXPQUANT3_QUANT_P6_Msk & (_UINT32_(value) << GMAC_EMAC_TXPQUANT3_QUANT_P6_Pos)) /* Assigment of value for QUANT_P6 in the GMAC_EMAC_TXPQUANT3 register */
#define GMAC_EMAC_TXPQUANT3_QUANT_P7_Pos      _UINT32_(16)                                         /* (GMAC_EMAC_TXPQUANT3) Priority 7 Transmit Pause Quantum Position */
#define GMAC_EMAC_TXPQUANT3_QUANT_P7_Msk      (_UINT32_(0xFFFF) << GMAC_EMAC_TXPQUANT3_QUANT_P7_Pos) /* (GMAC_EMAC_TXPQUANT3) Priority 7 Transmit Pause Quantum Mask */
#define GMAC_EMAC_TXPQUANT3_QUANT_P7(value)   (GMAC_EMAC_TXPQUANT3_QUANT_P7_Msk & (_UINT32_(value) << GMAC_EMAC_TXPQUANT3_QUANT_P7_Pos)) /* Assigment of value for QUANT_P7 in the GMAC_EMAC_TXPQUANT3 register */
#define GMAC_EMAC_TXPQUANT3_Msk               _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_TXPQUANT3) Register Mask  */


/* -------- GMAC_EMAC_RXLPI : (GMAC Offset: 0x1270) ( R/ 32) Express MAC Received LPI Transitions -------- */
#define GMAC_EMAC_RXLPI_RESETVALUE            _UINT32_(0x00)                                       /*  (GMAC_EMAC_RXLPI) Express MAC Received LPI Transitions  Reset Value */

#define GMAC_EMAC_RXLPI_COUNT_Pos             _UINT32_(0)                                          /* (GMAC_EMAC_RXLPI) Count of Received LPI transitions (cleared on read) Position */
#define GMAC_EMAC_RXLPI_COUNT_Msk             (_UINT32_(0xFFFF) << GMAC_EMAC_RXLPI_COUNT_Pos)      /* (GMAC_EMAC_RXLPI) Count of Received LPI transitions (cleared on read) Mask */
#define GMAC_EMAC_RXLPI_COUNT(value)          (GMAC_EMAC_RXLPI_COUNT_Msk & (_UINT32_(value) << GMAC_EMAC_RXLPI_COUNT_Pos)) /* Assigment of value for COUNT in the GMAC_EMAC_RXLPI register */
#define GMAC_EMAC_RXLPI_Msk                   _UINT32_(0x0000FFFF)                                 /* (GMAC_EMAC_RXLPI) Register Mask  */


/* -------- GMAC_EMAC_RXLPITIME : (GMAC Offset: 0x1274) ( R/ 32) Express MAC Received LPI Time -------- */
#define GMAC_EMAC_RXLPITIME_RESETVALUE        _UINT32_(0x00)                                       /*  (GMAC_EMAC_RXLPITIME) Express MAC Received LPI Time  Reset Value */

#define GMAC_EMAC_RXLPITIME_LPITIME_Pos       _UINT32_(0)                                          /* (GMAC_EMAC_RXLPITIME) Time in LPI (cleared on read) Position */
#define GMAC_EMAC_RXLPITIME_LPITIME_Msk       (_UINT32_(0xFFFFFF) << GMAC_EMAC_RXLPITIME_LPITIME_Pos) /* (GMAC_EMAC_RXLPITIME) Time in LPI (cleared on read) Mask */
#define GMAC_EMAC_RXLPITIME_LPITIME(value)    (GMAC_EMAC_RXLPITIME_LPITIME_Msk & (_UINT32_(value) << GMAC_EMAC_RXLPITIME_LPITIME_Pos)) /* Assigment of value for LPITIME in the GMAC_EMAC_RXLPITIME register */
#define GMAC_EMAC_RXLPITIME_Msk               _UINT32_(0x00FFFFFF)                                 /* (GMAC_EMAC_RXLPITIME) Register Mask  */


/* -------- GMAC_EMAC_TXLPI : (GMAC Offset: 0x1278) ( R/ 32) Express MAC Transmit LPI Transitions -------- */
#define GMAC_EMAC_TXLPI_RESETVALUE            _UINT32_(0x00)                                       /*  (GMAC_EMAC_TXLPI) Express MAC Transmit LPI Transitions  Reset Value */

#define GMAC_EMAC_TXLPI_COUNT_Pos             _UINT32_(0)                                          /* (GMAC_EMAC_TXLPI) Count of LPI transitions (cleared on read) Position */
#define GMAC_EMAC_TXLPI_COUNT_Msk             (_UINT32_(0xFFFF) << GMAC_EMAC_TXLPI_COUNT_Pos)      /* (GMAC_EMAC_TXLPI) Count of LPI transitions (cleared on read) Mask */
#define GMAC_EMAC_TXLPI_COUNT(value)          (GMAC_EMAC_TXLPI_COUNT_Msk & (_UINT32_(value) << GMAC_EMAC_TXLPI_COUNT_Pos)) /* Assigment of value for COUNT in the GMAC_EMAC_TXLPI register */
#define GMAC_EMAC_TXLPI_Msk                   _UINT32_(0x0000FFFF)                                 /* (GMAC_EMAC_TXLPI) Register Mask  */


/* -------- GMAC_EMAC_TXLPITIME : (GMAC Offset: 0x127C) ( R/ 32) Express MAC Transmit LPI Time -------- */
#define GMAC_EMAC_TXLPITIME_RESETVALUE        _UINT32_(0x00)                                       /*  (GMAC_EMAC_TXLPITIME) Express MAC Transmit LPI Time  Reset Value */

#define GMAC_EMAC_TXLPITIME_LPITIME_Pos       _UINT32_(0)                                          /* (GMAC_EMAC_TXLPITIME) Time in LPI (cleared on read) Position */
#define GMAC_EMAC_TXLPITIME_LPITIME_Msk       (_UINT32_(0xFFFFFF) << GMAC_EMAC_TXLPITIME_LPITIME_Pos) /* (GMAC_EMAC_TXLPITIME) Time in LPI (cleared on read) Mask */
#define GMAC_EMAC_TXLPITIME_LPITIME(value)    (GMAC_EMAC_TXLPITIME_LPITIME_Msk & (_UINT32_(value) << GMAC_EMAC_TXLPITIME_LPITIME_Pos)) /* Assigment of value for LPITIME in the GMAC_EMAC_TXLPITIME register */
#define GMAC_EMAC_TXLPITIME_Msk               _UINT32_(0x00FFFFFF)                                 /* (GMAC_EMAC_TXLPITIME) Register Mask  */


/* -------- GMAC_EMAC_QOS_CFG : (GMAC Offset: 0x12E0) (R/W 32) Express MAC System Bus QoS Configuration Register -------- */
#define GMAC_EMAC_QOS_CFG_RESETVALUE          _UINT32_(0x00)                                       /*  (GMAC_EMAC_QOS_CFG) Express MAC System Bus QoS Configuration Register  Reset Value */

#define GMAC_EMAC_QOS_CFG_Q0_DATA_Pos         _UINT32_(0)                                          /* (GMAC_EMAC_QOS_CFG) System Bus QoS Attributes for Queue 0 Data Access Position */
#define GMAC_EMAC_QOS_CFG_Q0_DATA_Msk         (_UINT32_(0xF) << GMAC_EMAC_QOS_CFG_Q0_DATA_Pos)     /* (GMAC_EMAC_QOS_CFG) System Bus QoS Attributes for Queue 0 Data Access Mask */
#define GMAC_EMAC_QOS_CFG_Q0_DATA(value)      (GMAC_EMAC_QOS_CFG_Q0_DATA_Msk & (_UINT32_(value) << GMAC_EMAC_QOS_CFG_Q0_DATA_Pos)) /* Assigment of value for Q0_DATA in the GMAC_EMAC_QOS_CFG register */
#define GMAC_EMAC_QOS_CFG_Q0_DESCR_Pos        _UINT32_(4)                                          /* (GMAC_EMAC_QOS_CFG) System Bus QoS Attributes for Queue 0 Descriptor Access Position */
#define GMAC_EMAC_QOS_CFG_Q0_DESCR_Msk        (_UINT32_(0xF) << GMAC_EMAC_QOS_CFG_Q0_DESCR_Pos)    /* (GMAC_EMAC_QOS_CFG) System Bus QoS Attributes for Queue 0 Descriptor Access Mask */
#define GMAC_EMAC_QOS_CFG_Q0_DESCR(value)     (GMAC_EMAC_QOS_CFG_Q0_DESCR_Msk & (_UINT32_(value) << GMAC_EMAC_QOS_CFG_Q0_DESCR_Pos)) /* Assigment of value for Q0_DESCR in the GMAC_EMAC_QOS_CFG register */
#define GMAC_EMAC_QOS_CFG_Q1_DATA_Pos         _UINT32_(8)                                          /* (GMAC_EMAC_QOS_CFG) System Bus QoS Attributes for Queue 1 Data Access Position */
#define GMAC_EMAC_QOS_CFG_Q1_DATA_Msk         (_UINT32_(0xF) << GMAC_EMAC_QOS_CFG_Q1_DATA_Pos)     /* (GMAC_EMAC_QOS_CFG) System Bus QoS Attributes for Queue 1 Data Access Mask */
#define GMAC_EMAC_QOS_CFG_Q1_DATA(value)      (GMAC_EMAC_QOS_CFG_Q1_DATA_Msk & (_UINT32_(value) << GMAC_EMAC_QOS_CFG_Q1_DATA_Pos)) /* Assigment of value for Q1_DATA in the GMAC_EMAC_QOS_CFG register */
#define GMAC_EMAC_QOS_CFG_Q1_DESCR_Pos        _UINT32_(12)                                         /* (GMAC_EMAC_QOS_CFG) System Bus QoS Attributes for Queue 1 Descriptor Access Position */
#define GMAC_EMAC_QOS_CFG_Q1_DESCR_Msk        (_UINT32_(0xF) << GMAC_EMAC_QOS_CFG_Q1_DESCR_Pos)    /* (GMAC_EMAC_QOS_CFG) System Bus QoS Attributes for Queue 1 Descriptor Access Mask */
#define GMAC_EMAC_QOS_CFG_Q1_DESCR(value)     (GMAC_EMAC_QOS_CFG_Q1_DESCR_Msk & (_UINT32_(value) << GMAC_EMAC_QOS_CFG_Q1_DESCR_Pos)) /* Assigment of value for Q1_DESCR in the GMAC_EMAC_QOS_CFG register */
#define GMAC_EMAC_QOS_CFG_Q2_DATA_Pos         _UINT32_(16)                                         /* (GMAC_EMAC_QOS_CFG) System Bus QoS Attributes for Queue 2 Data Access Position */
#define GMAC_EMAC_QOS_CFG_Q2_DATA_Msk         (_UINT32_(0xF) << GMAC_EMAC_QOS_CFG_Q2_DATA_Pos)     /* (GMAC_EMAC_QOS_CFG) System Bus QoS Attributes for Queue 2 Data Access Mask */
#define GMAC_EMAC_QOS_CFG_Q2_DATA(value)      (GMAC_EMAC_QOS_CFG_Q2_DATA_Msk & (_UINT32_(value) << GMAC_EMAC_QOS_CFG_Q2_DATA_Pos)) /* Assigment of value for Q2_DATA in the GMAC_EMAC_QOS_CFG register */
#define GMAC_EMAC_QOS_CFG_Q2_DESCR_Pos        _UINT32_(20)                                         /* (GMAC_EMAC_QOS_CFG) System Bus QoS Attributes for Queue 2 Descriptor Access Position */
#define GMAC_EMAC_QOS_CFG_Q2_DESCR_Msk        (_UINT32_(0xF) << GMAC_EMAC_QOS_CFG_Q2_DESCR_Pos)    /* (GMAC_EMAC_QOS_CFG) System Bus QoS Attributes for Queue 2 Descriptor Access Mask */
#define GMAC_EMAC_QOS_CFG_Q2_DESCR(value)     (GMAC_EMAC_QOS_CFG_Q2_DESCR_Msk & (_UINT32_(value) << GMAC_EMAC_QOS_CFG_Q2_DESCR_Pos)) /* Assigment of value for Q2_DESCR in the GMAC_EMAC_QOS_CFG register */
#define GMAC_EMAC_QOS_CFG_Q3_DATA_Pos         _UINT32_(24)                                         /* (GMAC_EMAC_QOS_CFG) System Bus QoS Attributes for Queue 3 Data Access Position */
#define GMAC_EMAC_QOS_CFG_Q3_DATA_Msk         (_UINT32_(0xF) << GMAC_EMAC_QOS_CFG_Q3_DATA_Pos)     /* (GMAC_EMAC_QOS_CFG) System Bus QoS Attributes for Queue 3 Data Access Mask */
#define GMAC_EMAC_QOS_CFG_Q3_DATA(value)      (GMAC_EMAC_QOS_CFG_Q3_DATA_Msk & (_UINT32_(value) << GMAC_EMAC_QOS_CFG_Q3_DATA_Pos)) /* Assigment of value for Q3_DATA in the GMAC_EMAC_QOS_CFG register */
#define GMAC_EMAC_QOS_CFG_Q3_DESCR_Pos        _UINT32_(28)                                         /* (GMAC_EMAC_QOS_CFG) System Bus QoS Attributes for Queue 3 Descriptor Access Position */
#define GMAC_EMAC_QOS_CFG_Q3_DESCR_Msk        (_UINT32_(0xF) << GMAC_EMAC_QOS_CFG_Q3_DESCR_Pos)    /* (GMAC_EMAC_QOS_CFG) System Bus QoS Attributes for Queue 3 Descriptor Access Mask */
#define GMAC_EMAC_QOS_CFG_Q3_DESCR(value)     (GMAC_EMAC_QOS_CFG_Q3_DESCR_Msk & (_UINT32_(value) << GMAC_EMAC_QOS_CFG_Q3_DESCR_Pos)) /* Assigment of value for Q3_DESCR in the GMAC_EMAC_QOS_CFG register */
#define GMAC_EMAC_QOS_CFG_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_QOS_CFG) Register Mask  */


/* -------- GMAC_EMAC_CBSCR : (GMAC Offset: 0x14BC) (R/W 32) Express MAC Credit-Based Shaping Control Register -------- */
#define GMAC_EMAC_CBSCR_RESETVALUE            _UINT32_(0x00)                                       /*  (GMAC_EMAC_CBSCR) Express MAC Credit-Based Shaping Control Register  Reset Value */

#define GMAC_EMAC_CBSCR_QAE_Pos               _UINT32_(0)                                          /* (GMAC_EMAC_CBSCR) Queue A CBS Enable Position */
#define GMAC_EMAC_CBSCR_QAE_Msk               (_UINT32_(0x1) << GMAC_EMAC_CBSCR_QAE_Pos)           /* (GMAC_EMAC_CBSCR) Queue A CBS Enable Mask */
#define GMAC_EMAC_CBSCR_QAE(value)            (GMAC_EMAC_CBSCR_QAE_Msk & (_UINT32_(value) << GMAC_EMAC_CBSCR_QAE_Pos)) /* Assigment of value for QAE in the GMAC_EMAC_CBSCR register */
#define   GMAC_EMAC_CBSCR_QAE_0_Val           _UINT32_(0x0)                                        /* (GMAC_EMAC_CBSCR) Credit-based shaping on the second highest priority queue (queue A) is disabled.  */
#define   GMAC_EMAC_CBSCR_QAE_1_Val           _UINT32_(0x1)                                        /* (GMAC_EMAC_CBSCR) Credit-based shaping on the second highest priority queue (queue A) is enabled.  */
#define GMAC_EMAC_CBSCR_QAE_0                 (GMAC_EMAC_CBSCR_QAE_0_Val << GMAC_EMAC_CBSCR_QAE_Pos) /* (GMAC_EMAC_CBSCR) Credit-based shaping on the second highest priority queue (queue A) is disabled. Position  */
#define GMAC_EMAC_CBSCR_QAE_1                 (GMAC_EMAC_CBSCR_QAE_1_Val << GMAC_EMAC_CBSCR_QAE_Pos) /* (GMAC_EMAC_CBSCR) Credit-based shaping on the second highest priority queue (queue A) is enabled. Position  */
#define GMAC_EMAC_CBSCR_QBE_Pos               _UINT32_(1)                                          /* (GMAC_EMAC_CBSCR) Queue B CBS Enable Position */
#define GMAC_EMAC_CBSCR_QBE_Msk               (_UINT32_(0x1) << GMAC_EMAC_CBSCR_QBE_Pos)           /* (GMAC_EMAC_CBSCR) Queue B CBS Enable Mask */
#define GMAC_EMAC_CBSCR_QBE(value)            (GMAC_EMAC_CBSCR_QBE_Msk & (_UINT32_(value) << GMAC_EMAC_CBSCR_QBE_Pos)) /* Assigment of value for QBE in the GMAC_EMAC_CBSCR register */
#define   GMAC_EMAC_CBSCR_QBE_0_Val           _UINT32_(0x0)                                        /* (GMAC_EMAC_CBSCR) Credit-based shaping on the highest priority queue (queue B) is disabled.  */
#define   GMAC_EMAC_CBSCR_QBE_1_Val           _UINT32_(0x1)                                        /* (GMAC_EMAC_CBSCR) Credit-based shaping on the highest priority queue (queue B) is enabled.  */
#define GMAC_EMAC_CBSCR_QBE_0                 (GMAC_EMAC_CBSCR_QBE_0_Val << GMAC_EMAC_CBSCR_QBE_Pos) /* (GMAC_EMAC_CBSCR) Credit-based shaping on the highest priority queue (queue B) is disabled. Position  */
#define GMAC_EMAC_CBSCR_QBE_1                 (GMAC_EMAC_CBSCR_QBE_1_Val << GMAC_EMAC_CBSCR_QBE_Pos) /* (GMAC_EMAC_CBSCR) Credit-based shaping on the highest priority queue (queue B) is enabled. Position  */
#define GMAC_EMAC_CBSCR_Msk                   _UINT32_(0x00000003)                                 /* (GMAC_EMAC_CBSCR) Register Mask  */


/* -------- GMAC_EMAC_CBSISQA : (GMAC Offset: 0x14C0) (R/W 32) Express MAC Credit-Based Shaping IdleSlope Register for Queue A -------- */
#define GMAC_EMAC_CBSISQA_RESETVALUE          _UINT32_(0x00)                                       /*  (GMAC_EMAC_CBSISQA) Express MAC Credit-Based Shaping IdleSlope Register for Queue A  Reset Value */

#define GMAC_EMAC_CBSISQA_IS_Pos              _UINT32_(0)                                          /* (GMAC_EMAC_CBSISQA) IdleSlope Position */
#define GMAC_EMAC_CBSISQA_IS_Msk              (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_CBSISQA_IS_Pos)   /* (GMAC_EMAC_CBSISQA) IdleSlope Mask */
#define GMAC_EMAC_CBSISQA_IS(value)           (GMAC_EMAC_CBSISQA_IS_Msk & (_UINT32_(value) << GMAC_EMAC_CBSISQA_IS_Pos)) /* Assigment of value for IS in the GMAC_EMAC_CBSISQA register */
#define GMAC_EMAC_CBSISQA_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_CBSISQA) Register Mask  */


/* -------- GMAC_EMAC_CBSISQB : (GMAC Offset: 0x14C4) (R/W 32) Express MAC Credit-Based Shaping IdleSlope Register for Queue B -------- */
#define GMAC_EMAC_CBSISQB_RESETVALUE          _UINT32_(0x00)                                       /*  (GMAC_EMAC_CBSISQB) Express MAC Credit-Based Shaping IdleSlope Register for Queue B  Reset Value */

#define GMAC_EMAC_CBSISQB_IS_Pos              _UINT32_(0)                                          /* (GMAC_EMAC_CBSISQB) IdleSlope Position */
#define GMAC_EMAC_CBSISQB_IS_Msk              (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_CBSISQB_IS_Pos)   /* (GMAC_EMAC_CBSISQB) IdleSlope Mask */
#define GMAC_EMAC_CBSISQB_IS(value)           (GMAC_EMAC_CBSISQB_IS_Msk & (_UINT32_(value) << GMAC_EMAC_CBSISQB_IS_Pos)) /* Assigment of value for IS in the GMAC_EMAC_CBSISQB register */
#define GMAC_EMAC_CBSISQB_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_CBSISQB) Register Mask  */


/* -------- GMAC_EMAC_TQUBA : (GMAC Offset: 0x14C8) (R/W 32) Express MAC 32 MSB Transmit Buffer Descriptor Queue Base Address Register -------- */
#define GMAC_EMAC_TQUBA_RESETVALUE            _UINT32_(0x00)                                       /*  (GMAC_EMAC_TQUBA) Express MAC 32 MSB Transmit Buffer Descriptor Queue Base Address Register  Reset Value */

#define GMAC_EMAC_TQUBA_TQUBA_Pos             _UINT32_(0)                                          /* (GMAC_EMAC_TQUBA) Transmit Queue Upper Buffer Address Position */
#define GMAC_EMAC_TQUBA_TQUBA_Msk             (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_TQUBA_TQUBA_Pos)  /* (GMAC_EMAC_TQUBA) Transmit Queue Upper Buffer Address Mask */
#define GMAC_EMAC_TQUBA_TQUBA(value)          (GMAC_EMAC_TQUBA_TQUBA_Msk & (_UINT32_(value) << GMAC_EMAC_TQUBA_TQUBA_Pos)) /* Assigment of value for TQUBA in the GMAC_EMAC_TQUBA register */
#define GMAC_EMAC_TQUBA_Msk                   _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_TQUBA) Register Mask  */


/* -------- GMAC_EMAC_TXBDCTRL : (GMAC Offset: 0x14CC) (R/W 32) Express MAC Transmit Buffer Data Control Register -------- */
#define GMAC_EMAC_TXBDCTRL_RESETVALUE         _UINT32_(0x00)                                       /*  (GMAC_EMAC_TXBDCTRL) Express MAC Transmit Buffer Data Control Register  Reset Value */

#define GMAC_EMAC_TXBDCTRL_TSMODE_Pos         _UINT32_(4)                                          /* (GMAC_EMAC_TXBDCTRL) Transmit Descriptor Timestamp Insertion Mode Position */
#define GMAC_EMAC_TXBDCTRL_TSMODE_Msk         (_UINT32_(0x3) << GMAC_EMAC_TXBDCTRL_TSMODE_Pos)     /* (GMAC_EMAC_TXBDCTRL) Transmit Descriptor Timestamp Insertion Mode Mask */
#define GMAC_EMAC_TXBDCTRL_TSMODE(value)      (GMAC_EMAC_TXBDCTRL_TSMODE_Msk & (_UINT32_(value) << GMAC_EMAC_TXBDCTRL_TSMODE_Pos)) /* Assigment of value for TSMODE in the GMAC_EMAC_TXBDCTRL register */
#define   GMAC_EMAC_TXBDCTRL_TSMODE_DISABLE_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_TXBDCTRL) Timestamp insertion disable.  */
#define   GMAC_EMAC_TXBDCTRL_TSMODE_PTPEVENT_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_TXBDCTRL) Timestamp inserted for PTP Event Frames only.  */
#define   GMAC_EMAC_TXBDCTRL_TSMODE_PTPALL_Val _UINT32_(0x2)                                        /* (GMAC_EMAC_TXBDCTRL) Timestamp inserted for All PTP Frames only.  */
#define   GMAC_EMAC_TXBDCTRL_TSMODE_ALL_Val   _UINT32_(0x3)                                        /* (GMAC_EMAC_TXBDCTRL) Timestamp inserted for All Frames.  */
#define GMAC_EMAC_TXBDCTRL_TSMODE_DISABLE     (GMAC_EMAC_TXBDCTRL_TSMODE_DISABLE_Val << GMAC_EMAC_TXBDCTRL_TSMODE_Pos) /* (GMAC_EMAC_TXBDCTRL) Timestamp insertion disable. Position  */
#define GMAC_EMAC_TXBDCTRL_TSMODE_PTPEVENT    (GMAC_EMAC_TXBDCTRL_TSMODE_PTPEVENT_Val << GMAC_EMAC_TXBDCTRL_TSMODE_Pos) /* (GMAC_EMAC_TXBDCTRL) Timestamp inserted for PTP Event Frames only. Position  */
#define GMAC_EMAC_TXBDCTRL_TSMODE_PTPALL      (GMAC_EMAC_TXBDCTRL_TSMODE_PTPALL_Val << GMAC_EMAC_TXBDCTRL_TSMODE_Pos) /* (GMAC_EMAC_TXBDCTRL) Timestamp inserted for All PTP Frames only. Position  */
#define GMAC_EMAC_TXBDCTRL_TSMODE_ALL         (GMAC_EMAC_TXBDCTRL_TSMODE_ALL_Val << GMAC_EMAC_TXBDCTRL_TSMODE_Pos) /* (GMAC_EMAC_TXBDCTRL) Timestamp inserted for All Frames. Position  */
#define GMAC_EMAC_TXBDCTRL_Msk                _UINT32_(0x00000030)                                 /* (GMAC_EMAC_TXBDCTRL) Register Mask  */


/* -------- GMAC_EMAC_RXBDCTRL : (GMAC Offset: 0x14D0) (R/W 32) Express MAC Receive Buffer Data Control Register -------- */
#define GMAC_EMAC_RXBDCTRL_RESETVALUE         _UINT32_(0x00)                                       /*  (GMAC_EMAC_RXBDCTRL) Express MAC Receive Buffer Data Control Register  Reset Value */

#define GMAC_EMAC_RXBDCTRL_TSMODE_Pos         _UINT32_(4)                                          /* (GMAC_EMAC_RXBDCTRL) Receive Descriptor Timestamp Insertion Mode Position */
#define GMAC_EMAC_RXBDCTRL_TSMODE_Msk         (_UINT32_(0x3) << GMAC_EMAC_RXBDCTRL_TSMODE_Pos)     /* (GMAC_EMAC_RXBDCTRL) Receive Descriptor Timestamp Insertion Mode Mask */
#define GMAC_EMAC_RXBDCTRL_TSMODE(value)      (GMAC_EMAC_RXBDCTRL_TSMODE_Msk & (_UINT32_(value) << GMAC_EMAC_RXBDCTRL_TSMODE_Pos)) /* Assigment of value for TSMODE in the GMAC_EMAC_RXBDCTRL register */
#define   GMAC_EMAC_RXBDCTRL_TSMODE_DISABLE_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_RXBDCTRL) Timestamp insertion disable.  */
#define   GMAC_EMAC_RXBDCTRL_TSMODE_PTPEVENT_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_RXBDCTRL) Timestamp inserted for PTP Event Frames only.  */
#define   GMAC_EMAC_RXBDCTRL_TSMODE_PTPALL_Val _UINT32_(0x2)                                        /* (GMAC_EMAC_RXBDCTRL) Timestamp inserted for All PTP Frames only.  */
#define   GMAC_EMAC_RXBDCTRL_TSMODE_ALL_Val   _UINT32_(0x3)                                        /* (GMAC_EMAC_RXBDCTRL) Timestamp inserted for All Frames.  */
#define GMAC_EMAC_RXBDCTRL_TSMODE_DISABLE     (GMAC_EMAC_RXBDCTRL_TSMODE_DISABLE_Val << GMAC_EMAC_RXBDCTRL_TSMODE_Pos) /* (GMAC_EMAC_RXBDCTRL) Timestamp insertion disable. Position  */
#define GMAC_EMAC_RXBDCTRL_TSMODE_PTPEVENT    (GMAC_EMAC_RXBDCTRL_TSMODE_PTPEVENT_Val << GMAC_EMAC_RXBDCTRL_TSMODE_Pos) /* (GMAC_EMAC_RXBDCTRL) Timestamp inserted for PTP Event Frames only. Position  */
#define GMAC_EMAC_RXBDCTRL_TSMODE_PTPALL      (GMAC_EMAC_RXBDCTRL_TSMODE_PTPALL_Val << GMAC_EMAC_RXBDCTRL_TSMODE_Pos) /* (GMAC_EMAC_RXBDCTRL) Timestamp inserted for All PTP Frames only. Position  */
#define GMAC_EMAC_RXBDCTRL_TSMODE_ALL         (GMAC_EMAC_RXBDCTRL_TSMODE_ALL_Val << GMAC_EMAC_RXBDCTRL_TSMODE_Pos) /* (GMAC_EMAC_RXBDCTRL) Timestamp inserted for All Frames. Position  */
#define GMAC_EMAC_RXBDCTRL_Msk                _UINT32_(0x00000030)                                 /* (GMAC_EMAC_RXBDCTRL) Register Mask  */


/* -------- GMAC_EMAC_RQUBA : (GMAC Offset: 0x14D4) (R/W 32) Express MAC 32 MSB Receive Buffer Descriptor Queue Base Address Register -------- */
#define GMAC_EMAC_RQUBA_RESETVALUE            _UINT32_(0x00)                                       /*  (GMAC_EMAC_RQUBA) Express MAC 32 MSB Receive Buffer Descriptor Queue Base Address Register  Reset Value */

#define GMAC_EMAC_RQUBA_RQUBA_Pos             _UINT32_(0)                                          /* (GMAC_EMAC_RQUBA) Receive Queue Upper Buffer Address Position */
#define GMAC_EMAC_RQUBA_RQUBA_Msk             (_UINT32_(0xFFFFFFFF) << GMAC_EMAC_RQUBA_RQUBA_Pos)  /* (GMAC_EMAC_RQUBA) Receive Queue Upper Buffer Address Mask */
#define GMAC_EMAC_RQUBA_RQUBA(value)          (GMAC_EMAC_RQUBA_RQUBA_Msk & (_UINT32_(value) << GMAC_EMAC_RQUBA_RQUBA_Pos)) /* Assigment of value for RQUBA in the GMAC_EMAC_RQUBA register */
#define GMAC_EMAC_RQUBA_Msk                   _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_RQUBA) Register Mask  */


/* -------- GMAC_EMAC_ST1R : (GMAC Offset: 0x1500) (R/W 32) Express MAC Screening Type 1 Register -------- */
#define GMAC_EMAC_ST1R_RESETVALUE             _UINT32_(0x00)                                       /*  (GMAC_EMAC_ST1R) Express MAC Screening Type 1 Register  Reset Value */

#define GMAC_EMAC_ST1R_QNB_Pos                _UINT32_(0)                                          /* (GMAC_EMAC_ST1R) Queue Number (0-5) Position */
#define GMAC_EMAC_ST1R_QNB_Msk                (_UINT32_(0x7) << GMAC_EMAC_ST1R_QNB_Pos)            /* (GMAC_EMAC_ST1R) Queue Number (0-5) Mask */
#define GMAC_EMAC_ST1R_QNB(value)             (GMAC_EMAC_ST1R_QNB_Msk & (_UINT32_(value) << GMAC_EMAC_ST1R_QNB_Pos)) /* Assigment of value for QNB in the GMAC_EMAC_ST1R register */
#define GMAC_EMAC_ST1R_DSTCM_Pos              _UINT32_(4)                                          /* (GMAC_EMAC_ST1R) Differentiated Services or Traffic Class Match Position */
#define GMAC_EMAC_ST1R_DSTCM_Msk              (_UINT32_(0xFF) << GMAC_EMAC_ST1R_DSTCM_Pos)         /* (GMAC_EMAC_ST1R) Differentiated Services or Traffic Class Match Mask */
#define GMAC_EMAC_ST1R_DSTCM(value)           (GMAC_EMAC_ST1R_DSTCM_Msk & (_UINT32_(value) << GMAC_EMAC_ST1R_DSTCM_Pos)) /* Assigment of value for DSTCM in the GMAC_EMAC_ST1R register */
#define GMAC_EMAC_ST1R_UDPM_Pos               _UINT32_(12)                                         /* (GMAC_EMAC_ST1R) UDP Port Match Position */
#define GMAC_EMAC_ST1R_UDPM_Msk               (_UINT32_(0xFFFF) << GMAC_EMAC_ST1R_UDPM_Pos)        /* (GMAC_EMAC_ST1R) UDP Port Match Mask */
#define GMAC_EMAC_ST1R_UDPM(value)            (GMAC_EMAC_ST1R_UDPM_Msk & (_UINT32_(value) << GMAC_EMAC_ST1R_UDPM_Pos)) /* Assigment of value for UDPM in the GMAC_EMAC_ST1R register */
#define GMAC_EMAC_ST1R_DSTCE_Pos              _UINT32_(28)                                         /* (GMAC_EMAC_ST1R) Differentiated Services or Traffic Class Match Enable Position */
#define GMAC_EMAC_ST1R_DSTCE_Msk              (_UINT32_(0x1) << GMAC_EMAC_ST1R_DSTCE_Pos)          /* (GMAC_EMAC_ST1R) Differentiated Services or Traffic Class Match Enable Mask */
#define GMAC_EMAC_ST1R_DSTCE(value)           (GMAC_EMAC_ST1R_DSTCE_Msk & (_UINT32_(value) << GMAC_EMAC_ST1R_DSTCE_Pos)) /* Assigment of value for DSTCE in the GMAC_EMAC_ST1R register */
#define GMAC_EMAC_ST1R_UDPE_Pos               _UINT32_(29)                                         /* (GMAC_EMAC_ST1R) UDP Port Match Enable Position */
#define GMAC_EMAC_ST1R_UDPE_Msk               (_UINT32_(0x1) << GMAC_EMAC_ST1R_UDPE_Pos)           /* (GMAC_EMAC_ST1R) UDP Port Match Enable Mask */
#define GMAC_EMAC_ST1R_UDPE(value)            (GMAC_EMAC_ST1R_UDPE_Msk & (_UINT32_(value) << GMAC_EMAC_ST1R_UDPE_Pos)) /* Assigment of value for UDPE in the GMAC_EMAC_ST1R register */
#define GMAC_EMAC_ST1R_Msk                    _UINT32_(0x3FFFFFF7)                                 /* (GMAC_EMAC_ST1R) Register Mask  */


/* -------- GMAC_EMAC_ST2R : (GMAC Offset: 0x1540) (R/W 32) Express MAC Screening Type 2 Register (index = 0) -------- */
#define GMAC_EMAC_ST2R_RESETVALUE             _UINT32_(0x00)                                       /*  (GMAC_EMAC_ST2R) Express MAC Screening Type 2 Register (index = 0)  Reset Value */

#define GMAC_EMAC_ST2R_QNB_Pos                _UINT32_(0)                                          /* (GMAC_EMAC_ST2R) Queue Number (0-5) Position */
#define GMAC_EMAC_ST2R_QNB_Msk                (_UINT32_(0x7) << GMAC_EMAC_ST2R_QNB_Pos)            /* (GMAC_EMAC_ST2R) Queue Number (0-5) Mask */
#define GMAC_EMAC_ST2R_QNB(value)             (GMAC_EMAC_ST2R_QNB_Msk & (_UINT32_(value) << GMAC_EMAC_ST2R_QNB_Pos)) /* Assigment of value for QNB in the GMAC_EMAC_ST2R register */
#define GMAC_EMAC_ST2R_VLANP_Pos              _UINT32_(4)                                          /* (GMAC_EMAC_ST2R) VLAN Priority Position */
#define GMAC_EMAC_ST2R_VLANP_Msk              (_UINT32_(0x7) << GMAC_EMAC_ST2R_VLANP_Pos)          /* (GMAC_EMAC_ST2R) VLAN Priority Mask */
#define GMAC_EMAC_ST2R_VLANP(value)           (GMAC_EMAC_ST2R_VLANP_Msk & (_UINT32_(value) << GMAC_EMAC_ST2R_VLANP_Pos)) /* Assigment of value for VLANP in the GMAC_EMAC_ST2R register */
#define GMAC_EMAC_ST2R_VLANE_Pos              _UINT32_(8)                                          /* (GMAC_EMAC_ST2R) VLAN Enable Position */
#define GMAC_EMAC_ST2R_VLANE_Msk              (_UINT32_(0x1) << GMAC_EMAC_ST2R_VLANE_Pos)          /* (GMAC_EMAC_ST2R) VLAN Enable Mask */
#define GMAC_EMAC_ST2R_VLANE(value)           (GMAC_EMAC_ST2R_VLANE_Msk & (_UINT32_(value) << GMAC_EMAC_ST2R_VLANE_Pos)) /* Assigment of value for VLANE in the GMAC_EMAC_ST2R register */
#define   GMAC_EMAC_ST2R_VLANE_0_Val          _UINT32_(0x0)                                        /* (GMAC_EMAC_ST2R) VLAN match is disabled.  */
#define   GMAC_EMAC_ST2R_VLANE_1_Val          _UINT32_(0x1)                                        /* (GMAC_EMAC_ST2R) VLAN match is enabled.  */
#define GMAC_EMAC_ST2R_VLANE_0                (GMAC_EMAC_ST2R_VLANE_0_Val << GMAC_EMAC_ST2R_VLANE_Pos) /* (GMAC_EMAC_ST2R) VLAN match is disabled. Position  */
#define GMAC_EMAC_ST2R_VLANE_1                (GMAC_EMAC_ST2R_VLANE_1_Val << GMAC_EMAC_ST2R_VLANE_Pos) /* (GMAC_EMAC_ST2R) VLAN match is enabled. Position  */
#define GMAC_EMAC_ST2R_I2ETH_Pos              _UINT32_(9)                                          /* (GMAC_EMAC_ST2R) Index of Screening Type 2 EtherType register Position */
#define GMAC_EMAC_ST2R_I2ETH_Msk              (_UINT32_(0x7) << GMAC_EMAC_ST2R_I2ETH_Pos)          /* (GMAC_EMAC_ST2R) Index of Screening Type 2 EtherType register Mask */
#define GMAC_EMAC_ST2R_I2ETH(value)           (GMAC_EMAC_ST2R_I2ETH_Msk & (_UINT32_(value) << GMAC_EMAC_ST2R_I2ETH_Pos)) /* Assigment of value for I2ETH in the GMAC_EMAC_ST2R register */
#define GMAC_EMAC_ST2R_ETHE_Pos               _UINT32_(12)                                         /* (GMAC_EMAC_ST2R) EtherType Enable Position */
#define GMAC_EMAC_ST2R_ETHE_Msk               (_UINT32_(0x1) << GMAC_EMAC_ST2R_ETHE_Pos)           /* (GMAC_EMAC_ST2R) EtherType Enable Mask */
#define GMAC_EMAC_ST2R_ETHE(value)            (GMAC_EMAC_ST2R_ETHE_Msk & (_UINT32_(value) << GMAC_EMAC_ST2R_ETHE_Pos)) /* Assigment of value for ETHE in the GMAC_EMAC_ST2R register */
#define   GMAC_EMAC_ST2R_ETHE_0_Val           _UINT32_(0x0)                                        /* (GMAC_EMAC_ST2R) EtherType match with bits 15:0 in the register designated by the value of I2ETH is disabled.  */
#define   GMAC_EMAC_ST2R_ETHE_1_Val           _UINT32_(0x1)                                        /* (GMAC_EMAC_ST2R) EtherType match with bits 15:0 in the register designated by the value of I2ETH is enabled.  */
#define GMAC_EMAC_ST2R_ETHE_0                 (GMAC_EMAC_ST2R_ETHE_0_Val << GMAC_EMAC_ST2R_ETHE_Pos) /* (GMAC_EMAC_ST2R) EtherType match with bits 15:0 in the register designated by the value of I2ETH is disabled. Position  */
#define GMAC_EMAC_ST2R_ETHE_1                 (GMAC_EMAC_ST2R_ETHE_1_Val << GMAC_EMAC_ST2R_ETHE_Pos) /* (GMAC_EMAC_ST2R) EtherType match with bits 15:0 in the register designated by the value of I2ETH is enabled. Position  */
#define GMAC_EMAC_ST2R_COMPA_Pos              _UINT32_(13)                                         /* (GMAC_EMAC_ST2R) Index of Screening Type 2 Compare Word 0/Word 1 register Position */
#define GMAC_EMAC_ST2R_COMPA_Msk              (_UINT32_(0x1F) << GMAC_EMAC_ST2R_COMPA_Pos)         /* (GMAC_EMAC_ST2R) Index of Screening Type 2 Compare Word 0/Word 1 register Mask */
#define GMAC_EMAC_ST2R_COMPA(value)           (GMAC_EMAC_ST2R_COMPA_Msk & (_UINT32_(value) << GMAC_EMAC_ST2R_COMPA_Pos)) /* Assigment of value for COMPA in the GMAC_EMAC_ST2R register */
#define GMAC_EMAC_ST2R_COMPAE_Pos             _UINT32_(18)                                         /* (GMAC_EMAC_ST2R) Compare A Enable Position */
#define GMAC_EMAC_ST2R_COMPAE_Msk             (_UINT32_(0x1) << GMAC_EMAC_ST2R_COMPAE_Pos)         /* (GMAC_EMAC_ST2R) Compare A Enable Mask */
#define GMAC_EMAC_ST2R_COMPAE(value)          (GMAC_EMAC_ST2R_COMPAE_Msk & (_UINT32_(value) << GMAC_EMAC_ST2R_COMPAE_Pos)) /* Assigment of value for COMPAE in the GMAC_EMAC_ST2R register */
#define   GMAC_EMAC_ST2R_COMPAE_0_Val         _UINT32_(0x0)                                        /* (GMAC_EMAC_ST2R) Comparison via the register designated by index COMPA is disabled.  */
#define   GMAC_EMAC_ST2R_COMPAE_1_Val         _UINT32_(0x1)                                        /* (GMAC_EMAC_ST2R) Comparison via the register designated by index COMPA is enabled.  */
#define GMAC_EMAC_ST2R_COMPAE_0               (GMAC_EMAC_ST2R_COMPAE_0_Val << GMAC_EMAC_ST2R_COMPAE_Pos) /* (GMAC_EMAC_ST2R) Comparison via the register designated by index COMPA is disabled. Position  */
#define GMAC_EMAC_ST2R_COMPAE_1               (GMAC_EMAC_ST2R_COMPAE_1_Val << GMAC_EMAC_ST2R_COMPAE_Pos) /* (GMAC_EMAC_ST2R) Comparison via the register designated by index COMPA is enabled. Position  */
#define GMAC_EMAC_ST2R_COMPB_Pos              _UINT32_(19)                                         /* (GMAC_EMAC_ST2R) Index of Screening Type 2 Compare Word 0/Word 1 register Position */
#define GMAC_EMAC_ST2R_COMPB_Msk              (_UINT32_(0x1F) << GMAC_EMAC_ST2R_COMPB_Pos)         /* (GMAC_EMAC_ST2R) Index of Screening Type 2 Compare Word 0/Word 1 register Mask */
#define GMAC_EMAC_ST2R_COMPB(value)           (GMAC_EMAC_ST2R_COMPB_Msk & (_UINT32_(value) << GMAC_EMAC_ST2R_COMPB_Pos)) /* Assigment of value for COMPB in the GMAC_EMAC_ST2R register */
#define GMAC_EMAC_ST2R_COMPBE_Pos             _UINT32_(24)                                         /* (GMAC_EMAC_ST2R) Compare B Enable Position */
#define GMAC_EMAC_ST2R_COMPBE_Msk             (_UINT32_(0x1) << GMAC_EMAC_ST2R_COMPBE_Pos)         /* (GMAC_EMAC_ST2R) Compare B Enable Mask */
#define GMAC_EMAC_ST2R_COMPBE(value)          (GMAC_EMAC_ST2R_COMPBE_Msk & (_UINT32_(value) << GMAC_EMAC_ST2R_COMPBE_Pos)) /* Assigment of value for COMPBE in the GMAC_EMAC_ST2R register */
#define   GMAC_EMAC_ST2R_COMPBE_0_Val         _UINT32_(0x0)                                        /* (GMAC_EMAC_ST2R) Comparison via the register designated by index COMPB is disabled.  */
#define   GMAC_EMAC_ST2R_COMPBE_1_Val         _UINT32_(0x1)                                        /* (GMAC_EMAC_ST2R) Comparison via the register designated by index COMPB is enabled.  */
#define GMAC_EMAC_ST2R_COMPBE_0               (GMAC_EMAC_ST2R_COMPBE_0_Val << GMAC_EMAC_ST2R_COMPBE_Pos) /* (GMAC_EMAC_ST2R) Comparison via the register designated by index COMPB is disabled. Position  */
#define GMAC_EMAC_ST2R_COMPBE_1               (GMAC_EMAC_ST2R_COMPBE_1_Val << GMAC_EMAC_ST2R_COMPBE_Pos) /* (GMAC_EMAC_ST2R) Comparison via the register designated by index COMPB is enabled. Position  */
#define GMAC_EMAC_ST2R_COMPC_Pos              _UINT32_(25)                                         /* (GMAC_EMAC_ST2R) Index of Screening Type 2 Compare Word 0/Word 1 register Position */
#define GMAC_EMAC_ST2R_COMPC_Msk              (_UINT32_(0x1F) << GMAC_EMAC_ST2R_COMPC_Pos)         /* (GMAC_EMAC_ST2R) Index of Screening Type 2 Compare Word 0/Word 1 register Mask */
#define GMAC_EMAC_ST2R_COMPC(value)           (GMAC_EMAC_ST2R_COMPC_Msk & (_UINT32_(value) << GMAC_EMAC_ST2R_COMPC_Pos)) /* Assigment of value for COMPC in the GMAC_EMAC_ST2R register */
#define GMAC_EMAC_ST2R_COMPCE_Pos             _UINT32_(30)                                         /* (GMAC_EMAC_ST2R) Compare C Enable Position */
#define GMAC_EMAC_ST2R_COMPCE_Msk             (_UINT32_(0x1) << GMAC_EMAC_ST2R_COMPCE_Pos)         /* (GMAC_EMAC_ST2R) Compare C Enable Mask */
#define GMAC_EMAC_ST2R_COMPCE(value)          (GMAC_EMAC_ST2R_COMPCE_Msk & (_UINT32_(value) << GMAC_EMAC_ST2R_COMPCE_Pos)) /* Assigment of value for COMPCE in the GMAC_EMAC_ST2R register */
#define   GMAC_EMAC_ST2R_COMPCE_0_Val         _UINT32_(0x0)                                        /* (GMAC_EMAC_ST2R) Comparison via the register designated by index COMPC is disabled.  */
#define   GMAC_EMAC_ST2R_COMPCE_1_Val         _UINT32_(0x1)                                        /* (GMAC_EMAC_ST2R) Comparison via the register designated by index COMPC is enabled.  */
#define GMAC_EMAC_ST2R_COMPCE_0               (GMAC_EMAC_ST2R_COMPCE_0_Val << GMAC_EMAC_ST2R_COMPCE_Pos) /* (GMAC_EMAC_ST2R) Comparison via the register designated by index COMPC is disabled. Position  */
#define GMAC_EMAC_ST2R_COMPCE_1               (GMAC_EMAC_ST2R_COMPCE_1_Val << GMAC_EMAC_ST2R_COMPCE_Pos) /* (GMAC_EMAC_ST2R) Comparison via the register designated by index COMPC is enabled. Position  */
#define GMAC_EMAC_ST2R_Msk                    _UINT32_(0x7FFFFF77)                                 /* (GMAC_EMAC_ST2R) Register Mask  */


/* -------- GMAC_EMAC_TSCTL : (GMAC Offset: 0x1580) (R/W 32) Express MACTransmit Schedule Control Register -------- */
#define GMAC_EMAC_TSCTL_RESETVALUE            _UINT32_(0x00)                                       /*  (GMAC_EMAC_TSCTL) Express MACTransmit Schedule Control Register  Reset Value */

#define GMAC_EMAC_TSCTL_TXSQ0_Pos             _UINT32_(0)                                          /* (GMAC_EMAC_TSCTL) Transmit Schedule for Qx Position */
#define GMAC_EMAC_TSCTL_TXSQ0_Msk             (_UINT32_(0x3) << GMAC_EMAC_TSCTL_TXSQ0_Pos)         /* (GMAC_EMAC_TSCTL) Transmit Schedule for Qx Mask */
#define GMAC_EMAC_TSCTL_TXSQ0(value)          (GMAC_EMAC_TSCTL_TXSQ0_Msk & (_UINT32_(value) << GMAC_EMAC_TSCTL_TXSQ0_Pos)) /* Assigment of value for TXSQ0 in the GMAC_EMAC_TSCTL register */
#define   GMAC_EMAC_TSCTL_TXSQ0_FP_Val        _UINT32_(0x0)                                        /* (GMAC_EMAC_TSCTL) Fixed Priority  */
#define   GMAC_EMAC_TSCTL_TXSQ0_CBS_Val       _UINT32_(0x1)                                        /* (GMAC_EMAC_TSCTL) CBS Enabled only valid for top two enabled queues and if CBS capability selected.  */
#define   GMAC_EMAC_TSCTL_TXSQ0_DWRR_Val      _UINT32_(0x2)                                        /* (GMAC_EMAC_TSCTL) DWRR enabled  */
#define   GMAC_EMAC_TSCTL_TXSQ0_ETS_Val       _UINT32_(0x3)                                        /* (GMAC_EMAC_TSCTL) ETS enabled  */
#define GMAC_EMAC_TSCTL_TXSQ0_FP              (GMAC_EMAC_TSCTL_TXSQ0_FP_Val << GMAC_EMAC_TSCTL_TXSQ0_Pos) /* (GMAC_EMAC_TSCTL) Fixed Priority Position  */
#define GMAC_EMAC_TSCTL_TXSQ0_CBS             (GMAC_EMAC_TSCTL_TXSQ0_CBS_Val << GMAC_EMAC_TSCTL_TXSQ0_Pos) /* (GMAC_EMAC_TSCTL) CBS Enabled only valid for top two enabled queues and if CBS capability selected. Position  */
#define GMAC_EMAC_TSCTL_TXSQ0_DWRR            (GMAC_EMAC_TSCTL_TXSQ0_DWRR_Val << GMAC_EMAC_TSCTL_TXSQ0_Pos) /* (GMAC_EMAC_TSCTL) DWRR enabled Position  */
#define GMAC_EMAC_TSCTL_TXSQ0_ETS             (GMAC_EMAC_TSCTL_TXSQ0_ETS_Val << GMAC_EMAC_TSCTL_TXSQ0_Pos) /* (GMAC_EMAC_TSCTL) ETS enabled Position  */
#define GMAC_EMAC_TSCTL_TXSQ1_Pos             _UINT32_(2)                                          /* (GMAC_EMAC_TSCTL) Transmit Schedule for Qx Position */
#define GMAC_EMAC_TSCTL_TXSQ1_Msk             (_UINT32_(0x3) << GMAC_EMAC_TSCTL_TXSQ1_Pos)         /* (GMAC_EMAC_TSCTL) Transmit Schedule for Qx Mask */
#define GMAC_EMAC_TSCTL_TXSQ1(value)          (GMAC_EMAC_TSCTL_TXSQ1_Msk & (_UINT32_(value) << GMAC_EMAC_TSCTL_TXSQ1_Pos)) /* Assigment of value for TXSQ1 in the GMAC_EMAC_TSCTL register */
#define   GMAC_EMAC_TSCTL_TXSQ1_FP_Val        _UINT32_(0x0)                                        /* (GMAC_EMAC_TSCTL) Fixed Priority  */
#define   GMAC_EMAC_TSCTL_TXSQ1_CBS_Val       _UINT32_(0x1)                                        /* (GMAC_EMAC_TSCTL) CBS Enabled only valid for top two enabled queues and if CBS capability selected.  */
#define   GMAC_EMAC_TSCTL_TXSQ1_DWRR_Val      _UINT32_(0x2)                                        /* (GMAC_EMAC_TSCTL) DWRR enabled  */
#define   GMAC_EMAC_TSCTL_TXSQ1_ETS_Val       _UINT32_(0x3)                                        /* (GMAC_EMAC_TSCTL) ETS enabled  */
#define GMAC_EMAC_TSCTL_TXSQ1_FP              (GMAC_EMAC_TSCTL_TXSQ1_FP_Val << GMAC_EMAC_TSCTL_TXSQ1_Pos) /* (GMAC_EMAC_TSCTL) Fixed Priority Position  */
#define GMAC_EMAC_TSCTL_TXSQ1_CBS             (GMAC_EMAC_TSCTL_TXSQ1_CBS_Val << GMAC_EMAC_TSCTL_TXSQ1_Pos) /* (GMAC_EMAC_TSCTL) CBS Enabled only valid for top two enabled queues and if CBS capability selected. Position  */
#define GMAC_EMAC_TSCTL_TXSQ1_DWRR            (GMAC_EMAC_TSCTL_TXSQ1_DWRR_Val << GMAC_EMAC_TSCTL_TXSQ1_Pos) /* (GMAC_EMAC_TSCTL) DWRR enabled Position  */
#define GMAC_EMAC_TSCTL_TXSQ1_ETS             (GMAC_EMAC_TSCTL_TXSQ1_ETS_Val << GMAC_EMAC_TSCTL_TXSQ1_Pos) /* (GMAC_EMAC_TSCTL) ETS enabled Position  */
#define GMAC_EMAC_TSCTL_TXSQ2_Pos             _UINT32_(4)                                          /* (GMAC_EMAC_TSCTL) Transmit Schedule for Qx Position */
#define GMAC_EMAC_TSCTL_TXSQ2_Msk             (_UINT32_(0x3) << GMAC_EMAC_TSCTL_TXSQ2_Pos)         /* (GMAC_EMAC_TSCTL) Transmit Schedule for Qx Mask */
#define GMAC_EMAC_TSCTL_TXSQ2(value)          (GMAC_EMAC_TSCTL_TXSQ2_Msk & (_UINT32_(value) << GMAC_EMAC_TSCTL_TXSQ2_Pos)) /* Assigment of value for TXSQ2 in the GMAC_EMAC_TSCTL register */
#define   GMAC_EMAC_TSCTL_TXSQ2_FP_Val        _UINT32_(0x0)                                        /* (GMAC_EMAC_TSCTL) Fixed Priority  */
#define   GMAC_EMAC_TSCTL_TXSQ2_CBS_Val       _UINT32_(0x1)                                        /* (GMAC_EMAC_TSCTL) CBS Enabled only valid for top two enabled queues and if CBS capability selected.  */
#define   GMAC_EMAC_TSCTL_TXSQ2_DWRR_Val      _UINT32_(0x2)                                        /* (GMAC_EMAC_TSCTL) DWRR enabled  */
#define   GMAC_EMAC_TSCTL_TXSQ2_ETS_Val       _UINT32_(0x3)                                        /* (GMAC_EMAC_TSCTL) ETS enabled  */
#define GMAC_EMAC_TSCTL_TXSQ2_FP              (GMAC_EMAC_TSCTL_TXSQ2_FP_Val << GMAC_EMAC_TSCTL_TXSQ2_Pos) /* (GMAC_EMAC_TSCTL) Fixed Priority Position  */
#define GMAC_EMAC_TSCTL_TXSQ2_CBS             (GMAC_EMAC_TSCTL_TXSQ2_CBS_Val << GMAC_EMAC_TSCTL_TXSQ2_Pos) /* (GMAC_EMAC_TSCTL) CBS Enabled only valid for top two enabled queues and if CBS capability selected. Position  */
#define GMAC_EMAC_TSCTL_TXSQ2_DWRR            (GMAC_EMAC_TSCTL_TXSQ2_DWRR_Val << GMAC_EMAC_TSCTL_TXSQ2_Pos) /* (GMAC_EMAC_TSCTL) DWRR enabled Position  */
#define GMAC_EMAC_TSCTL_TXSQ2_ETS             (GMAC_EMAC_TSCTL_TXSQ2_ETS_Val << GMAC_EMAC_TSCTL_TXSQ2_Pos) /* (GMAC_EMAC_TSCTL) ETS enabled Position  */
#define GMAC_EMAC_TSCTL_TXSQ3_Pos             _UINT32_(6)                                          /* (GMAC_EMAC_TSCTL) Transmit Schedule for Qx Position */
#define GMAC_EMAC_TSCTL_TXSQ3_Msk             (_UINT32_(0x3) << GMAC_EMAC_TSCTL_TXSQ3_Pos)         /* (GMAC_EMAC_TSCTL) Transmit Schedule for Qx Mask */
#define GMAC_EMAC_TSCTL_TXSQ3(value)          (GMAC_EMAC_TSCTL_TXSQ3_Msk & (_UINT32_(value) << GMAC_EMAC_TSCTL_TXSQ3_Pos)) /* Assigment of value for TXSQ3 in the GMAC_EMAC_TSCTL register */
#define   GMAC_EMAC_TSCTL_TXSQ3_FP_Val        _UINT32_(0x0)                                        /* (GMAC_EMAC_TSCTL) Fixed Priority  */
#define   GMAC_EMAC_TSCTL_TXSQ3_CBS_Val       _UINT32_(0x1)                                        /* (GMAC_EMAC_TSCTL) CBS Enabled only valid for top two enabled queues and if CBS capability selected.  */
#define   GMAC_EMAC_TSCTL_TXSQ3_DWRR_Val      _UINT32_(0x2)                                        /* (GMAC_EMAC_TSCTL) DWRR enabled  */
#define   GMAC_EMAC_TSCTL_TXSQ3_ETS_Val       _UINT32_(0x3)                                        /* (GMAC_EMAC_TSCTL) ETS enabled  */
#define GMAC_EMAC_TSCTL_TXSQ3_FP              (GMAC_EMAC_TSCTL_TXSQ3_FP_Val << GMAC_EMAC_TSCTL_TXSQ3_Pos) /* (GMAC_EMAC_TSCTL) Fixed Priority Position  */
#define GMAC_EMAC_TSCTL_TXSQ3_CBS             (GMAC_EMAC_TSCTL_TXSQ3_CBS_Val << GMAC_EMAC_TSCTL_TXSQ3_Pos) /* (GMAC_EMAC_TSCTL) CBS Enabled only valid for top two enabled queues and if CBS capability selected. Position  */
#define GMAC_EMAC_TSCTL_TXSQ3_DWRR            (GMAC_EMAC_TSCTL_TXSQ3_DWRR_Val << GMAC_EMAC_TSCTL_TXSQ3_Pos) /* (GMAC_EMAC_TSCTL) DWRR enabled Position  */
#define GMAC_EMAC_TSCTL_TXSQ3_ETS             (GMAC_EMAC_TSCTL_TXSQ3_ETS_Val << GMAC_EMAC_TSCTL_TXSQ3_Pos) /* (GMAC_EMAC_TSCTL) ETS enabled Position  */
#define GMAC_EMAC_TSCTL_TXSQ4_Pos             _UINT32_(8)                                          /* (GMAC_EMAC_TSCTL) Transmit Schedule for Qx Position */
#define GMAC_EMAC_TSCTL_TXSQ4_Msk             (_UINT32_(0x3) << GMAC_EMAC_TSCTL_TXSQ4_Pos)         /* (GMAC_EMAC_TSCTL) Transmit Schedule for Qx Mask */
#define GMAC_EMAC_TSCTL_TXSQ4(value)          (GMAC_EMAC_TSCTL_TXSQ4_Msk & (_UINT32_(value) << GMAC_EMAC_TSCTL_TXSQ4_Pos)) /* Assigment of value for TXSQ4 in the GMAC_EMAC_TSCTL register */
#define   GMAC_EMAC_TSCTL_TXSQ4_FP_Val        _UINT32_(0x0)                                        /* (GMAC_EMAC_TSCTL) Fixed Priority  */
#define   GMAC_EMAC_TSCTL_TXSQ4_CBS_Val       _UINT32_(0x1)                                        /* (GMAC_EMAC_TSCTL) CBS Enabled only valid for top two enabled queues and if CBS capability selected.  */
#define   GMAC_EMAC_TSCTL_TXSQ4_DWRR_Val      _UINT32_(0x2)                                        /* (GMAC_EMAC_TSCTL) DWRR enabled  */
#define   GMAC_EMAC_TSCTL_TXSQ4_ETS_Val       _UINT32_(0x3)                                        /* (GMAC_EMAC_TSCTL) ETS enabled  */
#define GMAC_EMAC_TSCTL_TXSQ4_FP              (GMAC_EMAC_TSCTL_TXSQ4_FP_Val << GMAC_EMAC_TSCTL_TXSQ4_Pos) /* (GMAC_EMAC_TSCTL) Fixed Priority Position  */
#define GMAC_EMAC_TSCTL_TXSQ4_CBS             (GMAC_EMAC_TSCTL_TXSQ4_CBS_Val << GMAC_EMAC_TSCTL_TXSQ4_Pos) /* (GMAC_EMAC_TSCTL) CBS Enabled only valid for top two enabled queues and if CBS capability selected. Position  */
#define GMAC_EMAC_TSCTL_TXSQ4_DWRR            (GMAC_EMAC_TSCTL_TXSQ4_DWRR_Val << GMAC_EMAC_TSCTL_TXSQ4_Pos) /* (GMAC_EMAC_TSCTL) DWRR enabled Position  */
#define GMAC_EMAC_TSCTL_TXSQ4_ETS             (GMAC_EMAC_TSCTL_TXSQ4_ETS_Val << GMAC_EMAC_TSCTL_TXSQ4_Pos) /* (GMAC_EMAC_TSCTL) ETS enabled Position  */
#define GMAC_EMAC_TSCTL_TXSQ5_Pos             _UINT32_(10)                                         /* (GMAC_EMAC_TSCTL) Transmit Schedule for Qx Position */
#define GMAC_EMAC_TSCTL_TXSQ5_Msk             (_UINT32_(0x3) << GMAC_EMAC_TSCTL_TXSQ5_Pos)         /* (GMAC_EMAC_TSCTL) Transmit Schedule for Qx Mask */
#define GMAC_EMAC_TSCTL_TXSQ5(value)          (GMAC_EMAC_TSCTL_TXSQ5_Msk & (_UINT32_(value) << GMAC_EMAC_TSCTL_TXSQ5_Pos)) /* Assigment of value for TXSQ5 in the GMAC_EMAC_TSCTL register */
#define   GMAC_EMAC_TSCTL_TXSQ5_FP_Val        _UINT32_(0x0)                                        /* (GMAC_EMAC_TSCTL) Fixed Priority  */
#define   GMAC_EMAC_TSCTL_TXSQ5_CBS_Val       _UINT32_(0x1)                                        /* (GMAC_EMAC_TSCTL) CBS Enabled only valid for top two enabled queues and if CBS capability selected.  */
#define   GMAC_EMAC_TSCTL_TXSQ5_DWRR_Val      _UINT32_(0x2)                                        /* (GMAC_EMAC_TSCTL) DWRR enabled  */
#define   GMAC_EMAC_TSCTL_TXSQ5_ETS_Val       _UINT32_(0x3)                                        /* (GMAC_EMAC_TSCTL) ETS enabled  */
#define GMAC_EMAC_TSCTL_TXSQ5_FP              (GMAC_EMAC_TSCTL_TXSQ5_FP_Val << GMAC_EMAC_TSCTL_TXSQ5_Pos) /* (GMAC_EMAC_TSCTL) Fixed Priority Position  */
#define GMAC_EMAC_TSCTL_TXSQ5_CBS             (GMAC_EMAC_TSCTL_TXSQ5_CBS_Val << GMAC_EMAC_TSCTL_TXSQ5_Pos) /* (GMAC_EMAC_TSCTL) CBS Enabled only valid for top two enabled queues and if CBS capability selected. Position  */
#define GMAC_EMAC_TSCTL_TXSQ5_DWRR            (GMAC_EMAC_TSCTL_TXSQ5_DWRR_Val << GMAC_EMAC_TSCTL_TXSQ5_Pos) /* (GMAC_EMAC_TSCTL) DWRR enabled Position  */
#define GMAC_EMAC_TSCTL_TXSQ5_ETS             (GMAC_EMAC_TSCTL_TXSQ5_ETS_Val << GMAC_EMAC_TSCTL_TXSQ5_Pos) /* (GMAC_EMAC_TSCTL) ETS enabled Position  */
#define GMAC_EMAC_TSCTL_Msk                   _UINT32_(0x00000FFF)                                 /* (GMAC_EMAC_TSCTL) Register Mask  */


/* -------- GMAC_EMAC_TQBWRL0 : (GMAC Offset: 0x1590) (R/W 32) Express MAC Transmit Queue Bandwidth Rate Limit 0 Register -------- */
#define GMAC_EMAC_TQBWRL0_RESETVALUE          _UINT32_(0x00)                                       /*  (GMAC_EMAC_TQBWRL0) Express MAC Transmit Queue Bandwidth Rate Limit 0 Register  Reset Value */

#define GMAC_EMAC_TQBWRL0_ALLOCQ0_Pos         _UINT32_(0)                                          /* (GMAC_EMAC_TQBWRL0) DWRR Weighting or ETS Bandwidth Allocation for Qx Position */
#define GMAC_EMAC_TQBWRL0_ALLOCQ0_Msk         (_UINT32_(0xFF) << GMAC_EMAC_TQBWRL0_ALLOCQ0_Pos)    /* (GMAC_EMAC_TQBWRL0) DWRR Weighting or ETS Bandwidth Allocation for Qx Mask */
#define GMAC_EMAC_TQBWRL0_ALLOCQ0(value)      (GMAC_EMAC_TQBWRL0_ALLOCQ0_Msk & (_UINT32_(value) << GMAC_EMAC_TQBWRL0_ALLOCQ0_Pos)) /* Assigment of value for ALLOCQ0 in the GMAC_EMAC_TQBWRL0 register */
#define GMAC_EMAC_TQBWRL0_ALLOCQ1_Pos         _UINT32_(8)                                          /* (GMAC_EMAC_TQBWRL0) DWRR Weighting or ETS Bandwidth Allocation for Qx Position */
#define GMAC_EMAC_TQBWRL0_ALLOCQ1_Msk         (_UINT32_(0xFF) << GMAC_EMAC_TQBWRL0_ALLOCQ1_Pos)    /* (GMAC_EMAC_TQBWRL0) DWRR Weighting or ETS Bandwidth Allocation for Qx Mask */
#define GMAC_EMAC_TQBWRL0_ALLOCQ1(value)      (GMAC_EMAC_TQBWRL0_ALLOCQ1_Msk & (_UINT32_(value) << GMAC_EMAC_TQBWRL0_ALLOCQ1_Pos)) /* Assigment of value for ALLOCQ1 in the GMAC_EMAC_TQBWRL0 register */
#define GMAC_EMAC_TQBWRL0_ALLOCQ2_Pos         _UINT32_(16)                                         /* (GMAC_EMAC_TQBWRL0) DWRR Weighting or ETS Bandwidth Allocation for Qx Position */
#define GMAC_EMAC_TQBWRL0_ALLOCQ2_Msk         (_UINT32_(0xFF) << GMAC_EMAC_TQBWRL0_ALLOCQ2_Pos)    /* (GMAC_EMAC_TQBWRL0) DWRR Weighting or ETS Bandwidth Allocation for Qx Mask */
#define GMAC_EMAC_TQBWRL0_ALLOCQ2(value)      (GMAC_EMAC_TQBWRL0_ALLOCQ2_Msk & (_UINT32_(value) << GMAC_EMAC_TQBWRL0_ALLOCQ2_Pos)) /* Assigment of value for ALLOCQ2 in the GMAC_EMAC_TQBWRL0 register */
#define GMAC_EMAC_TQBWRL0_ALLOCQ3_Pos         _UINT32_(24)                                         /* (GMAC_EMAC_TQBWRL0) DWRR Weighting or ETS Bandwidth Allocation for Qx Position */
#define GMAC_EMAC_TQBWRL0_ALLOCQ3_Msk         (_UINT32_(0xFF) << GMAC_EMAC_TQBWRL0_ALLOCQ3_Pos)    /* (GMAC_EMAC_TQBWRL0) DWRR Weighting or ETS Bandwidth Allocation for Qx Mask */
#define GMAC_EMAC_TQBWRL0_ALLOCQ3(value)      (GMAC_EMAC_TQBWRL0_ALLOCQ3_Msk & (_UINT32_(value) << GMAC_EMAC_TQBWRL0_ALLOCQ3_Pos)) /* Assigment of value for ALLOCQ3 in the GMAC_EMAC_TQBWRL0 register */
#define GMAC_EMAC_TQBWRL0_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_TQBWRL0) Register Mask  */


/* -------- GMAC_EMAC_TQSA : (GMAC Offset: 0x15A0) (R/W 32) Express MAC Transmit Queue Segment Allocation Register -------- */
#define GMAC_EMAC_TQSA_RESETVALUE             _UINT32_(0x00)                                       /*  (GMAC_EMAC_TQSA) Express MAC Transmit Queue Segment Allocation Register  Reset Value */

#define GMAC_EMAC_TQSA_SEGALLOCQ0_Pos         _UINT32_(0)                                          /* (GMAC_EMAC_TQSA) Segment Allocation for Qx Position */
#define GMAC_EMAC_TQSA_SEGALLOCQ0_Msk         (_UINT32_(0x7) << GMAC_EMAC_TQSA_SEGALLOCQ0_Pos)     /* (GMAC_EMAC_TQSA) Segment Allocation for Qx Mask */
#define GMAC_EMAC_TQSA_SEGALLOCQ0(value)      (GMAC_EMAC_TQSA_SEGALLOCQ0_Msk & (_UINT32_(value) << GMAC_EMAC_TQSA_SEGALLOCQ0_Pos)) /* Assigment of value for SEGALLOCQ0 in the GMAC_EMAC_TQSA register */
#define GMAC_EMAC_TQSA_SEGALLOCQ1_Pos         _UINT32_(4)                                          /* (GMAC_EMAC_TQSA) Segment Allocation for Qx Position */
#define GMAC_EMAC_TQSA_SEGALLOCQ1_Msk         (_UINT32_(0x7) << GMAC_EMAC_TQSA_SEGALLOCQ1_Pos)     /* (GMAC_EMAC_TQSA) Segment Allocation for Qx Mask */
#define GMAC_EMAC_TQSA_SEGALLOCQ1(value)      (GMAC_EMAC_TQSA_SEGALLOCQ1_Msk & (_UINT32_(value) << GMAC_EMAC_TQSA_SEGALLOCQ1_Pos)) /* Assigment of value for SEGALLOCQ1 in the GMAC_EMAC_TQSA register */
#define GMAC_EMAC_TQSA_SEGALLOCQ2_Pos         _UINT32_(8)                                          /* (GMAC_EMAC_TQSA) Segment Allocation for Qx Position */
#define GMAC_EMAC_TQSA_SEGALLOCQ2_Msk         (_UINT32_(0x7) << GMAC_EMAC_TQSA_SEGALLOCQ2_Pos)     /* (GMAC_EMAC_TQSA) Segment Allocation for Qx Mask */
#define GMAC_EMAC_TQSA_SEGALLOCQ2(value)      (GMAC_EMAC_TQSA_SEGALLOCQ2_Msk & (_UINT32_(value) << GMAC_EMAC_TQSA_SEGALLOCQ2_Pos)) /* Assigment of value for SEGALLOCQ2 in the GMAC_EMAC_TQSA register */
#define GMAC_EMAC_TQSA_SEGALLOCQ3_Pos         _UINT32_(12)                                         /* (GMAC_EMAC_TQSA) Segment Allocation for Qx Position */
#define GMAC_EMAC_TQSA_SEGALLOCQ3_Msk         (_UINT32_(0x7) << GMAC_EMAC_TQSA_SEGALLOCQ3_Pos)     /* (GMAC_EMAC_TQSA) Segment Allocation for Qx Mask */
#define GMAC_EMAC_TQSA_SEGALLOCQ3(value)      (GMAC_EMAC_TQSA_SEGALLOCQ3_Msk & (_UINT32_(value) << GMAC_EMAC_TQSA_SEGALLOCQ3_Pos)) /* Assigment of value for SEGALLOCQ3 in the GMAC_EMAC_TQSA register */
#define GMAC_EMAC_TQSA_SEGALLOCQ4_Pos         _UINT32_(16)                                         /* (GMAC_EMAC_TQSA) Segment Allocation for Qx Position */
#define GMAC_EMAC_TQSA_SEGALLOCQ4_Msk         (_UINT32_(0x7) << GMAC_EMAC_TQSA_SEGALLOCQ4_Pos)     /* (GMAC_EMAC_TQSA) Segment Allocation for Qx Mask */
#define GMAC_EMAC_TQSA_SEGALLOCQ4(value)      (GMAC_EMAC_TQSA_SEGALLOCQ4_Msk & (_UINT32_(value) << GMAC_EMAC_TQSA_SEGALLOCQ4_Pos)) /* Assigment of value for SEGALLOCQ4 in the GMAC_EMAC_TQSA register */
#define GMAC_EMAC_TQSA_SEGALLOCQ5_Pos         _UINT32_(20)                                         /* (GMAC_EMAC_TQSA) Segment Allocation for Qx Position */
#define GMAC_EMAC_TQSA_SEGALLOCQ5_Msk         (_UINT32_(0x7) << GMAC_EMAC_TQSA_SEGALLOCQ5_Pos)     /* (GMAC_EMAC_TQSA) Segment Allocation for Qx Mask */
#define GMAC_EMAC_TQSA_SEGALLOCQ5(value)      (GMAC_EMAC_TQSA_SEGALLOCQ5_Msk & (_UINT32_(value) << GMAC_EMAC_TQSA_SEGALLOCQ5_Pos)) /* Assigment of value for SEGALLOCQ5 in the GMAC_EMAC_TQSA register */
#define GMAC_EMAC_TQSA_Msk                    _UINT32_(0x00777777)                                 /* (GMAC_EMAC_TQSA) Register Mask  */


/* -------- GMAC_EMAC_ENST_START_Q : (GMAC Offset: 0x1800) (R/W 32) Express MAC ENST Start Time Queue Register (index = 0) -------- */
#define GMAC_EMAC_ENST_START_Q_RESETVALUE     _UINT32_(0x1FFFF)                                    /*  (GMAC_EMAC_ENST_START_Q) Express MAC ENST Start Time Queue Register (index = 0)  Reset Value */

#define GMAC_EMAC_ENST_START_Q_START_NSEC_Pos _UINT32_(0)                                          /* (GMAC_EMAC_ENST_START_Q) Nanoseconds for Start Time Position */
#define GMAC_EMAC_ENST_START_Q_START_NSEC_Msk (_UINT32_(0x3FFFFFFF) << GMAC_EMAC_ENST_START_Q_START_NSEC_Pos) /* (GMAC_EMAC_ENST_START_Q) Nanoseconds for Start Time Mask */
#define GMAC_EMAC_ENST_START_Q_START_NSEC(value) (GMAC_EMAC_ENST_START_Q_START_NSEC_Msk & (_UINT32_(value) << GMAC_EMAC_ENST_START_Q_START_NSEC_Pos)) /* Assigment of value for START_NSEC in the GMAC_EMAC_ENST_START_Q register */
#define GMAC_EMAC_ENST_START_Q_START_SEC_Pos  _UINT32_(30)                                         /* (GMAC_EMAC_ENST_START_Q) Seconds for Start Time Position */
#define GMAC_EMAC_ENST_START_Q_START_SEC_Msk  (_UINT32_(0x3) << GMAC_EMAC_ENST_START_Q_START_SEC_Pos) /* (GMAC_EMAC_ENST_START_Q) Seconds for Start Time Mask */
#define GMAC_EMAC_ENST_START_Q_START_SEC(value) (GMAC_EMAC_ENST_START_Q_START_SEC_Msk & (_UINT32_(value) << GMAC_EMAC_ENST_START_Q_START_SEC_Pos)) /* Assigment of value for START_SEC in the GMAC_EMAC_ENST_START_Q register */
#define GMAC_EMAC_ENST_START_Q_Msk            _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_ENST_START_Q) Register Mask  */


/* -------- GMAC_EMAC_ENST_ON_Q : (GMAC Offset: 0x1820) (R/W 32) Express MAC ENST On Time Queue Register (index = 0) -------- */
#define GMAC_EMAC_ENST_ON_Q_RESETVALUE        _UINT32_(0x1FFFF)                                    /*  (GMAC_EMAC_ENST_ON_Q) Express MAC ENST On Time Queue Register (index = 0)  Reset Value */

#define GMAC_EMAC_ENST_ON_Q_ON_TIME_Pos       _UINT32_(0)                                          /* (GMAC_EMAC_ENST_ON_Q) Time for which the Queue is to be Open Position */
#define GMAC_EMAC_ENST_ON_Q_ON_TIME_Msk       (_UINT32_(0x1FFFF) << GMAC_EMAC_ENST_ON_Q_ON_TIME_Pos) /* (GMAC_EMAC_ENST_ON_Q) Time for which the Queue is to be Open Mask */
#define GMAC_EMAC_ENST_ON_Q_ON_TIME(value)    (GMAC_EMAC_ENST_ON_Q_ON_TIME_Msk & (_UINT32_(value) << GMAC_EMAC_ENST_ON_Q_ON_TIME_Pos)) /* Assigment of value for ON_TIME in the GMAC_EMAC_ENST_ON_Q register */
#define GMAC_EMAC_ENST_ON_Q_Msk               _UINT32_(0x0001FFFF)                                 /* (GMAC_EMAC_ENST_ON_Q) Register Mask  */


/* -------- GMAC_EMAC_ENST_OFF_Q : (GMAC Offset: 0x1840) (R/W 32) Express MAC ENST Off Time Queue Register (index = 0) -------- */
#define GMAC_EMAC_ENST_OFF_Q_RESETVALUE       _UINT32_(0x00)                                       /*  (GMAC_EMAC_ENST_OFF_Q) Express MAC ENST Off Time Queue Register (index = 0)  Reset Value */

#define GMAC_EMAC_ENST_OFF_Q_OFF_TIME_Pos     _UINT32_(0)                                          /* (GMAC_EMAC_ENST_OFF_Q) Time for which the Queue is to be Blocked Position */
#define GMAC_EMAC_ENST_OFF_Q_OFF_TIME_Msk     (_UINT32_(0x1FFFF) << GMAC_EMAC_ENST_OFF_Q_OFF_TIME_Pos) /* (GMAC_EMAC_ENST_OFF_Q) Time for which the Queue is to be Blocked Mask */
#define GMAC_EMAC_ENST_OFF_Q_OFF_TIME(value)  (GMAC_EMAC_ENST_OFF_Q_OFF_TIME_Msk & (_UINT32_(value) << GMAC_EMAC_ENST_OFF_Q_OFF_TIME_Pos)) /* Assigment of value for OFF_TIME in the GMAC_EMAC_ENST_OFF_Q register */
#define GMAC_EMAC_ENST_OFF_Q_Msk              _UINT32_(0x0001FFFF)                                 /* (GMAC_EMAC_ENST_OFF_Q) Register Mask  */


/* -------- GMAC_EMAC_ENST_CR : (GMAC Offset: 0x1880) (R/W 32) Express MAC ENST Control Register -------- */
#define GMAC_EMAC_ENST_CR_RESETVALUE          _UINT32_(0x00)                                       /*  (GMAC_EMAC_ENST_CR) Express MAC ENST Control Register  Reset Value */

#define GMAC_EMAC_ENST_CR_EN_Q0_Pos           _UINT32_(0)                                          /* (GMAC_EMAC_ENST_CR) Enhanced Scheduled Traffic Enable for Queue 0 Position */
#define GMAC_EMAC_ENST_CR_EN_Q0_Msk           (_UINT32_(0x1) << GMAC_EMAC_ENST_CR_EN_Q0_Pos)       /* (GMAC_EMAC_ENST_CR) Enhanced Scheduled Traffic Enable for Queue 0 Mask */
#define GMAC_EMAC_ENST_CR_EN_Q0(value)        (GMAC_EMAC_ENST_CR_EN_Q0_Msk & (_UINT32_(value) << GMAC_EMAC_ENST_CR_EN_Q0_Pos)) /* Assigment of value for EN_Q0 in the GMAC_EMAC_ENST_CR register */
#define   GMAC_EMAC_ENST_CR_EN_Q0_0_Val       _UINT32_(0x0)                                        /* (GMAC_EMAC_ENST_CR) Disables the enhanced scheduled traffic for queue x.  */
#define   GMAC_EMAC_ENST_CR_EN_Q0_1_Val       _UINT32_(0x1)                                        /* (GMAC_EMAC_ENST_CR) Enables the enhanced scheduled traffic for queue x. EMAC has only 1 queue and ENST is enabled by writing EN_Q0.  */
#define GMAC_EMAC_ENST_CR_EN_Q0_0             (GMAC_EMAC_ENST_CR_EN_Q0_0_Val << GMAC_EMAC_ENST_CR_EN_Q0_Pos) /* (GMAC_EMAC_ENST_CR) Disables the enhanced scheduled traffic for queue x. Position  */
#define GMAC_EMAC_ENST_CR_EN_Q0_1             (GMAC_EMAC_ENST_CR_EN_Q0_1_Val << GMAC_EMAC_ENST_CR_EN_Q0_Pos) /* (GMAC_EMAC_ENST_CR) Enables the enhanced scheduled traffic for queue x. EMAC has only 1 queue and ENST is enabled by writing EN_Q0. Position  */
#define GMAC_EMAC_ENST_CR_EN_Q1_Pos           _UINT32_(1)                                          /* (GMAC_EMAC_ENST_CR) Enhanced Scheduled Traffic Enable for Queue 1 Position */
#define GMAC_EMAC_ENST_CR_EN_Q1_Msk           (_UINT32_(0x1) << GMAC_EMAC_ENST_CR_EN_Q1_Pos)       /* (GMAC_EMAC_ENST_CR) Enhanced Scheduled Traffic Enable for Queue 1 Mask */
#define GMAC_EMAC_ENST_CR_EN_Q1(value)        (GMAC_EMAC_ENST_CR_EN_Q1_Msk & (_UINT32_(value) << GMAC_EMAC_ENST_CR_EN_Q1_Pos)) /* Assigment of value for EN_Q1 in the GMAC_EMAC_ENST_CR register */
#define   GMAC_EMAC_ENST_CR_EN_Q1_0_Val       _UINT32_(0x0)                                        /* (GMAC_EMAC_ENST_CR) Disables the enhanced scheduled traffic for queue x.  */
#define   GMAC_EMAC_ENST_CR_EN_Q1_1_Val       _UINT32_(0x1)                                        /* (GMAC_EMAC_ENST_CR) Enables the enhanced scheduled traffic for queue x. EMAC has only 1 queue and ENST is enabled by writing EN_Q0.  */
#define GMAC_EMAC_ENST_CR_EN_Q1_0             (GMAC_EMAC_ENST_CR_EN_Q1_0_Val << GMAC_EMAC_ENST_CR_EN_Q1_Pos) /* (GMAC_EMAC_ENST_CR) Disables the enhanced scheduled traffic for queue x. Position  */
#define GMAC_EMAC_ENST_CR_EN_Q1_1             (GMAC_EMAC_ENST_CR_EN_Q1_1_Val << GMAC_EMAC_ENST_CR_EN_Q1_Pos) /* (GMAC_EMAC_ENST_CR) Enables the enhanced scheduled traffic for queue x. EMAC has only 1 queue and ENST is enabled by writing EN_Q0. Position  */
#define GMAC_EMAC_ENST_CR_EN_Q2_Pos           _UINT32_(2)                                          /* (GMAC_EMAC_ENST_CR) Enhanced Scheduled Traffic Enable for Queue 2 Position */
#define GMAC_EMAC_ENST_CR_EN_Q2_Msk           (_UINT32_(0x1) << GMAC_EMAC_ENST_CR_EN_Q2_Pos)       /* (GMAC_EMAC_ENST_CR) Enhanced Scheduled Traffic Enable for Queue 2 Mask */
#define GMAC_EMAC_ENST_CR_EN_Q2(value)        (GMAC_EMAC_ENST_CR_EN_Q2_Msk & (_UINT32_(value) << GMAC_EMAC_ENST_CR_EN_Q2_Pos)) /* Assigment of value for EN_Q2 in the GMAC_EMAC_ENST_CR register */
#define   GMAC_EMAC_ENST_CR_EN_Q2_0_Val       _UINT32_(0x0)                                        /* (GMAC_EMAC_ENST_CR) Disables the enhanced scheduled traffic for queue x.  */
#define   GMAC_EMAC_ENST_CR_EN_Q2_1_Val       _UINT32_(0x1)                                        /* (GMAC_EMAC_ENST_CR) Enables the enhanced scheduled traffic for queue x. EMAC has only 1 queue and ENST is enabled by writing EN_Q0.  */
#define GMAC_EMAC_ENST_CR_EN_Q2_0             (GMAC_EMAC_ENST_CR_EN_Q2_0_Val << GMAC_EMAC_ENST_CR_EN_Q2_Pos) /* (GMAC_EMAC_ENST_CR) Disables the enhanced scheduled traffic for queue x. Position  */
#define GMAC_EMAC_ENST_CR_EN_Q2_1             (GMAC_EMAC_ENST_CR_EN_Q2_1_Val << GMAC_EMAC_ENST_CR_EN_Q2_Pos) /* (GMAC_EMAC_ENST_CR) Enables the enhanced scheduled traffic for queue x. EMAC has only 1 queue and ENST is enabled by writing EN_Q0. Position  */
#define GMAC_EMAC_ENST_CR_EN_Q3_Pos           _UINT32_(3)                                          /* (GMAC_EMAC_ENST_CR) Enhanced Scheduled Traffic Enable for Queue 3 Position */
#define GMAC_EMAC_ENST_CR_EN_Q3_Msk           (_UINT32_(0x1) << GMAC_EMAC_ENST_CR_EN_Q3_Pos)       /* (GMAC_EMAC_ENST_CR) Enhanced Scheduled Traffic Enable for Queue 3 Mask */
#define GMAC_EMAC_ENST_CR_EN_Q3(value)        (GMAC_EMAC_ENST_CR_EN_Q3_Msk & (_UINT32_(value) << GMAC_EMAC_ENST_CR_EN_Q3_Pos)) /* Assigment of value for EN_Q3 in the GMAC_EMAC_ENST_CR register */
#define   GMAC_EMAC_ENST_CR_EN_Q3_0_Val       _UINT32_(0x0)                                        /* (GMAC_EMAC_ENST_CR) Disables the enhanced scheduled traffic for queue x.  */
#define   GMAC_EMAC_ENST_CR_EN_Q3_1_Val       _UINT32_(0x1)                                        /* (GMAC_EMAC_ENST_CR) Enables the enhanced scheduled traffic for queue x. EMAC has only 1 queue and ENST is enabled by writing EN_Q0.  */
#define GMAC_EMAC_ENST_CR_EN_Q3_0             (GMAC_EMAC_ENST_CR_EN_Q3_0_Val << GMAC_EMAC_ENST_CR_EN_Q3_Pos) /* (GMAC_EMAC_ENST_CR) Disables the enhanced scheduled traffic for queue x. Position  */
#define GMAC_EMAC_ENST_CR_EN_Q3_1             (GMAC_EMAC_ENST_CR_EN_Q3_1_Val << GMAC_EMAC_ENST_CR_EN_Q3_Pos) /* (GMAC_EMAC_ENST_CR) Enables the enhanced scheduled traffic for queue x. EMAC has only 1 queue and ENST is enabled by writing EN_Q0. Position  */
#define GMAC_EMAC_ENST_CR_EN_Q4_Pos           _UINT32_(4)                                          /* (GMAC_EMAC_ENST_CR) Enhanced Scheduled Traffic Enable for Queue 4 Position */
#define GMAC_EMAC_ENST_CR_EN_Q4_Msk           (_UINT32_(0x1) << GMAC_EMAC_ENST_CR_EN_Q4_Pos)       /* (GMAC_EMAC_ENST_CR) Enhanced Scheduled Traffic Enable for Queue 4 Mask */
#define GMAC_EMAC_ENST_CR_EN_Q4(value)        (GMAC_EMAC_ENST_CR_EN_Q4_Msk & (_UINT32_(value) << GMAC_EMAC_ENST_CR_EN_Q4_Pos)) /* Assigment of value for EN_Q4 in the GMAC_EMAC_ENST_CR register */
#define   GMAC_EMAC_ENST_CR_EN_Q4_0_Val       _UINT32_(0x0)                                        /* (GMAC_EMAC_ENST_CR) Disables the enhanced scheduled traffic for queue x.  */
#define   GMAC_EMAC_ENST_CR_EN_Q4_1_Val       _UINT32_(0x1)                                        /* (GMAC_EMAC_ENST_CR) Enables the enhanced scheduled traffic for queue x. EMAC has only 1 queue and ENST is enabled by writing EN_Q0.  */
#define GMAC_EMAC_ENST_CR_EN_Q4_0             (GMAC_EMAC_ENST_CR_EN_Q4_0_Val << GMAC_EMAC_ENST_CR_EN_Q4_Pos) /* (GMAC_EMAC_ENST_CR) Disables the enhanced scheduled traffic for queue x. Position  */
#define GMAC_EMAC_ENST_CR_EN_Q4_1             (GMAC_EMAC_ENST_CR_EN_Q4_1_Val << GMAC_EMAC_ENST_CR_EN_Q4_Pos) /* (GMAC_EMAC_ENST_CR) Enables the enhanced scheduled traffic for queue x. EMAC has only 1 queue and ENST is enabled by writing EN_Q0. Position  */
#define GMAC_EMAC_ENST_CR_EN_Q5_Pos           _UINT32_(5)                                          /* (GMAC_EMAC_ENST_CR) Enhanced Scheduled Traffic Enable for Queue 5 Position */
#define GMAC_EMAC_ENST_CR_EN_Q5_Msk           (_UINT32_(0x1) << GMAC_EMAC_ENST_CR_EN_Q5_Pos)       /* (GMAC_EMAC_ENST_CR) Enhanced Scheduled Traffic Enable for Queue 5 Mask */
#define GMAC_EMAC_ENST_CR_EN_Q5(value)        (GMAC_EMAC_ENST_CR_EN_Q5_Msk & (_UINT32_(value) << GMAC_EMAC_ENST_CR_EN_Q5_Pos)) /* Assigment of value for EN_Q5 in the GMAC_EMAC_ENST_CR register */
#define   GMAC_EMAC_ENST_CR_EN_Q5_0_Val       _UINT32_(0x0)                                        /* (GMAC_EMAC_ENST_CR) Disables the enhanced scheduled traffic for queue x.  */
#define   GMAC_EMAC_ENST_CR_EN_Q5_1_Val       _UINT32_(0x1)                                        /* (GMAC_EMAC_ENST_CR) Enables the enhanced scheduled traffic for queue x. EMAC has only 1 queue and ENST is enabled by writing EN_Q0.  */
#define GMAC_EMAC_ENST_CR_EN_Q5_0             (GMAC_EMAC_ENST_CR_EN_Q5_0_Val << GMAC_EMAC_ENST_CR_EN_Q5_Pos) /* (GMAC_EMAC_ENST_CR) Disables the enhanced scheduled traffic for queue x. Position  */
#define GMAC_EMAC_ENST_CR_EN_Q5_1             (GMAC_EMAC_ENST_CR_EN_Q5_1_Val << GMAC_EMAC_ENST_CR_EN_Q5_Pos) /* (GMAC_EMAC_ENST_CR) Enables the enhanced scheduled traffic for queue x. EMAC has only 1 queue and ENST is enabled by writing EN_Q0. Position  */
#define GMAC_EMAC_ENST_CR_Msk                 _UINT32_(0x0000003F)                                 /* (GMAC_EMAC_ENST_CR) Register Mask  */

#define GMAC_EMAC_ENST_CR_EN_Q_Pos            _UINT32_(0)                                          /* (GMAC_EMAC_ENST_CR Position) Enhanced Scheduled Traffic Enable for Queue 5 */
#define GMAC_EMAC_ENST_CR_EN_Q_Msk            (_UINT32_(0x3F) << GMAC_EMAC_ENST_CR_EN_Q_Pos)       /* (GMAC_EMAC_ENST_CR Mask) EN_Q */
#define GMAC_EMAC_ENST_CR_EN_Q(value)         (GMAC_EMAC_ENST_CR_EN_Q_Msk & (_UINT32_(value) << GMAC_EMAC_ENST_CR_EN_Q_Pos)) 

/* -------- GMAC_EMAC_FRER_TIMEOUT : (GMAC Offset: 0x18A0) (R/W 32) Express MAC Frame Elimination Timeout Register -------- */
#define GMAC_EMAC_FRER_TIMEOUT_RESETVALUE     _UINT32_(0x00)                                       /*  (GMAC_EMAC_FRER_TIMEOUT) Express MAC Frame Elimination Timeout Register  Reset Value */

#define GMAC_EMAC_FRER_TIMEOUT_TIMEOUT_Pos    _UINT32_(0)                                          /* (GMAC_EMAC_FRER_TIMEOUT) Sequence Recovery Timer Restart Period for Credit Based Streams Position */
#define GMAC_EMAC_FRER_TIMEOUT_TIMEOUT_Msk    (_UINT32_(0xFFFF) << GMAC_EMAC_FRER_TIMEOUT_TIMEOUT_Pos) /* (GMAC_EMAC_FRER_TIMEOUT) Sequence Recovery Timer Restart Period for Credit Based Streams Mask */
#define GMAC_EMAC_FRER_TIMEOUT_TIMEOUT(value) (GMAC_EMAC_FRER_TIMEOUT_TIMEOUT_Msk & (_UINT32_(value) << GMAC_EMAC_FRER_TIMEOUT_TIMEOUT_Pos)) /* Assigment of value for TIMEOUT in the GMAC_EMAC_FRER_TIMEOUT register */
#define GMAC_EMAC_FRER_TIMEOUT_Msk            _UINT32_(0x0000FFFF)                                 /* (GMAC_EMAC_FRER_TIMEOUT) Register Mask  */


/* -------- GMAC_EMAC_FRER_REDTAG : (GMAC Offset: 0x18A4) (R/W 32) Express MAC Frame Elimination Redundancy Tag Register -------- */
#define GMAC_EMAC_FRER_REDTAG_RESETVALUE      _UINT32_(0x4000F1C1)                                 /*  (GMAC_EMAC_FRER_REDTAG) Express MAC Frame Elimination Redundancy Tag Register  Reset Value */

#define GMAC_EMAC_FRER_REDTAG_RED_TAG_Pos     _UINT32_(0)                                          /* (GMAC_EMAC_FRER_REDTAG) Redundancy Tag (R-TAG) Position */
#define GMAC_EMAC_FRER_REDTAG_RED_TAG_Msk     (_UINT32_(0xFFFF) << GMAC_EMAC_FRER_REDTAG_RED_TAG_Pos) /* (GMAC_EMAC_FRER_REDTAG) Redundancy Tag (R-TAG) Mask */
#define GMAC_EMAC_FRER_REDTAG_RED_TAG(value)  (GMAC_EMAC_FRER_REDTAG_RED_TAG_Msk & (_UINT32_(value) << GMAC_EMAC_FRER_REDTAG_RED_TAG_Pos)) /* Assigment of value for RED_TAG in the GMAC_EMAC_FRER_REDTAG register */
#define GMAC_EMAC_FRER_REDTAG_SIX_BYTE_TAG_Pos _UINT32_(30)                                         /* (GMAC_EMAC_FRER_REDTAG) Six-byte Tag Enable Position */
#define GMAC_EMAC_FRER_REDTAG_SIX_BYTE_TAG_Msk (_UINT32_(0x1) << GMAC_EMAC_FRER_REDTAG_SIX_BYTE_TAG_Pos) /* (GMAC_EMAC_FRER_REDTAG) Six-byte Tag Enable Mask */
#define GMAC_EMAC_FRER_REDTAG_SIX_BYTE_TAG(value) (GMAC_EMAC_FRER_REDTAG_SIX_BYTE_TAG_Msk & (_UINT32_(value) << GMAC_EMAC_FRER_REDTAG_SIX_BYTE_TAG_Pos)) /* Assigment of value for SIX_BYTE_TAG in the GMAC_EMAC_FRER_REDTAG register */
#define   GMAC_EMAC_FRER_REDTAG_SIX_BYTE_TAG_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_FRER_REDTAG) Defines a four-byte tag as per 802.1CB standard revision 2.4 and earlier.  */
#define   GMAC_EMAC_FRER_REDTAG_SIX_BYTE_TAG_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_FRER_REDTAG) Enables the six-byte tag as per 802.1CB standard revision 2.4 and later.  */
#define GMAC_EMAC_FRER_REDTAG_SIX_BYTE_TAG_0  (GMAC_EMAC_FRER_REDTAG_SIX_BYTE_TAG_0_Val << GMAC_EMAC_FRER_REDTAG_SIX_BYTE_TAG_Pos) /* (GMAC_EMAC_FRER_REDTAG) Defines a four-byte tag as per 802.1CB standard revision 2.4 and earlier. Position  */
#define GMAC_EMAC_FRER_REDTAG_SIX_BYTE_TAG_1  (GMAC_EMAC_FRER_REDTAG_SIX_BYTE_TAG_1_Val << GMAC_EMAC_FRER_REDTAG_SIX_BYTE_TAG_Pos) /* (GMAC_EMAC_FRER_REDTAG) Enables the six-byte tag as per 802.1CB standard revision 2.4 and later. Position  */
#define GMAC_EMAC_FRER_REDTAG_STRIP_R_TAG_Pos _UINT32_(31)                                         /* (GMAC_EMAC_FRER_REDTAG) Stripping Redundancy Tag Enable Position */
#define GMAC_EMAC_FRER_REDTAG_STRIP_R_TAG_Msk (_UINT32_(0x1) << GMAC_EMAC_FRER_REDTAG_STRIP_R_TAG_Pos) /* (GMAC_EMAC_FRER_REDTAG) Stripping Redundancy Tag Enable Mask */
#define GMAC_EMAC_FRER_REDTAG_STRIP_R_TAG(value) (GMAC_EMAC_FRER_REDTAG_STRIP_R_TAG_Msk & (_UINT32_(value) << GMAC_EMAC_FRER_REDTAG_STRIP_R_TAG_Pos)) /* Assigment of value for STRIP_R_TAG in the GMAC_EMAC_FRER_REDTAG register */
#define   GMAC_EMAC_FRER_REDTAG_STRIP_R_TAG_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_FRER_REDTAG) Disables the stripping function. When the statistics counters need to reflect the actual number of octets received, then the stripping functionality must be disabled.  */
#define   GMAC_EMAC_FRER_REDTAG_STRIP_R_TAG_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_FRER_REDTAG) Enables the stripping function, the receive octet counters reflect post deletion frame size so the frame elimination functionality is transparent to higher level management.  */
#define GMAC_EMAC_FRER_REDTAG_STRIP_R_TAG_0   (GMAC_EMAC_FRER_REDTAG_STRIP_R_TAG_0_Val << GMAC_EMAC_FRER_REDTAG_STRIP_R_TAG_Pos) /* (GMAC_EMAC_FRER_REDTAG) Disables the stripping function. When the statistics counters need to reflect the actual number of octets received, then the stripping functionality must be disabled. Position  */
#define GMAC_EMAC_FRER_REDTAG_STRIP_R_TAG_1   (GMAC_EMAC_FRER_REDTAG_STRIP_R_TAG_1_Val << GMAC_EMAC_FRER_REDTAG_STRIP_R_TAG_Pos) /* (GMAC_EMAC_FRER_REDTAG) Enables the stripping function, the receive octet counters reflect post deletion frame size so the frame elimination functionality is transparent to higher level management. Position  */
#define GMAC_EMAC_FRER_REDTAG_Msk             _UINT32_(0xC000FFFF)                                 /* (GMAC_EMAC_FRER_REDTAG) Register Mask  */


/* -------- GMAC_EMAC_RX_FLUSH_Q : (GMAC Offset: 0x1B00) (R/W 32) Express MAC Receive Queue Flush Register -------- */
#define GMAC_EMAC_RX_FLUSH_Q_RESETVALUE       _UINT32_(0x00)                                       /*  (GMAC_EMAC_RX_FLUSH_Q) Express MAC Receive Queue Flush Register  Reset Value */

#define GMAC_EMAC_RX_FLUSH_Q_DROP_ALL_Pos     _UINT32_(0)                                          /* (GMAC_EMAC_RX_FLUSH_Q) Drop All Frames Position */
#define GMAC_EMAC_RX_FLUSH_Q_DROP_ALL_Msk     (_UINT32_(0x1) << GMAC_EMAC_RX_FLUSH_Q_DROP_ALL_Pos) /* (GMAC_EMAC_RX_FLUSH_Q) Drop All Frames Mask */
#define GMAC_EMAC_RX_FLUSH_Q_DROP_ALL(value)  (GMAC_EMAC_RX_FLUSH_Q_DROP_ALL_Msk & (_UINT32_(value) << GMAC_EMAC_RX_FLUSH_Q_DROP_ALL_Pos)) /* Assigment of value for DROP_ALL in the GMAC_EMAC_RX_FLUSH_Q register */
#define   GMAC_EMAC_RX_FLUSH_Q_DROP_ALL_DISABLED_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_RX_FLUSH_Q) No effect.  */
#define   GMAC_EMAC_RX_FLUSH_Q_DROP_ALL_ENABLED_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_RX_FLUSH_Q) Drops all frames of this queue.  */
#define GMAC_EMAC_RX_FLUSH_Q_DROP_ALL_DISABLED (GMAC_EMAC_RX_FLUSH_Q_DROP_ALL_DISABLED_Val << GMAC_EMAC_RX_FLUSH_Q_DROP_ALL_Pos) /* (GMAC_EMAC_RX_FLUSH_Q) No effect. Position  */
#define GMAC_EMAC_RX_FLUSH_Q_DROP_ALL_ENABLED (GMAC_EMAC_RX_FLUSH_Q_DROP_ALL_ENABLED_Val << GMAC_EMAC_RX_FLUSH_Q_DROP_ALL_Pos) /* (GMAC_EMAC_RX_FLUSH_Q) Drops all frames of this queue. Position  */
#define GMAC_EMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_Pos _UINT32_(1)                                          /* (GMAC_EMAC_RX_FLUSH_Q) Drop on Resource Error Position */
#define GMAC_EMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_Pos) /* (GMAC_EMAC_RX_FLUSH_Q) Drop on Resource Error Mask */
#define GMAC_EMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR(value) (GMAC_EMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_Msk & (_UINT32_(value) << GMAC_EMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_Pos)) /* Assigment of value for DROP_ON_RESRC_ERR in the GMAC_EMAC_RX_FLUSH_Q register */
#define   GMAC_EMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_DISABLED_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_RX_FLUSH_Q) No effect.  */
#define   GMAC_EMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_ENABLED_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_RX_FLUSH_Q) If a free DMA descriptor for this queue cannot be obtained (also referred to as lack of descriptor resource and occurs when the software either cannot free up descriptors quickly enough to meet the receive traffic rate or has deliberately decided not to free any descriptors), all new frames received on this queue will be automatically discarded.  */
#define GMAC_EMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_DISABLED (GMAC_EMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_DISABLED_Val << GMAC_EMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_Pos) /* (GMAC_EMAC_RX_FLUSH_Q) No effect. Position  */
#define GMAC_EMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_ENABLED (GMAC_EMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_ENABLED_Val << GMAC_EMAC_RX_FLUSH_Q_DROP_ON_RESRC_ERR_Pos) /* (GMAC_EMAC_RX_FLUSH_Q) If a free DMA descriptor for this queue cannot be obtained (also referred to as lack of descriptor resource and occurs when the software either cannot free up descriptors quickly enough to meet the receive traffic rate or has deliberately decided not to free any descriptors), all new frames received on this queue will be automatically discarded. Position  */
#define GMAC_EMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_Pos _UINT32_(2)                                          /* (GMAC_EMAC_RX_FLUSH_Q) Limitation of the Number of 128-Byte Chunk of Data Stored in the Memory of this Queue Position */
#define GMAC_EMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_Pos) /* (GMAC_EMAC_RX_FLUSH_Q) Limitation of the Number of 128-Byte Chunk of Data Stored in the Memory of this Queue Mask */
#define GMAC_EMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES(value) (GMAC_EMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_Msk & (_UINT32_(value) << GMAC_EMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_Pos)) /* Assigment of value for LIMIT_NUM_BYTES in the GMAC_EMAC_RX_FLUSH_Q register */
#define   GMAC_EMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_DISABLED_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_RX_FLUSH_Q) No effect.  */
#define   GMAC_EMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_ENABLED_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_RX_FLUSH_Q) Limits the number of 128 byte chunks of data received for this queue and already stored in the memory of the queue awaiting DMA memory writes to the value defined in the field MAX_VAL.  */
#define GMAC_EMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_DISABLED (GMAC_EMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_DISABLED_Val << GMAC_EMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_Pos) /* (GMAC_EMAC_RX_FLUSH_Q) No effect. Position  */
#define GMAC_EMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_ENABLED (GMAC_EMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_ENABLED_Val << GMAC_EMAC_RX_FLUSH_Q_LIMIT_NUM_BYTES_Pos) /* (GMAC_EMAC_RX_FLUSH_Q) Limits the number of 128 byte chunks of data received for this queue and already stored in the memory of the queue awaiting DMA memory writes to the value defined in the field MAX_VAL. Position  */
#define GMAC_EMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_Pos _UINT32_(3)                                          /* (GMAC_EMAC_RX_FLUSH_Q) Maximum Frame-length Received Position */
#define GMAC_EMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_Msk (_UINT32_(0x1) << GMAC_EMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_Pos) /* (GMAC_EMAC_RX_FLUSH_Q) Maximum Frame-length Received Mask */
#define GMAC_EMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE(value) (GMAC_EMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_Msk & (_UINT32_(value) << GMAC_EMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_Pos)) /* Assigment of value for LIMIT_FRAME_SIZE in the GMAC_EMAC_RX_FLUSH_Q register */
#define   GMAC_EMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_DISABLED_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_RX_FLUSH_Q) No effect.  */
#define   GMAC_EMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_ENABLED_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_RX_FLUSH_Q) When set, MAX_VAL indicates the maximum frame-length in bytes that may be received. Frames exceeding this length will be dropped. This traffic policing function is relevant to the 802.1Qci standard which specifies stream filtering based on a maximum service data unit (SDU) size.  */
#define GMAC_EMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_DISABLED (GMAC_EMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_DISABLED_Val << GMAC_EMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_Pos) /* (GMAC_EMAC_RX_FLUSH_Q) No effect. Position  */
#define GMAC_EMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_ENABLED (GMAC_EMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_ENABLED_Val << GMAC_EMAC_RX_FLUSH_Q_LIMIT_FRAME_SIZE_Pos) /* (GMAC_EMAC_RX_FLUSH_Q) When set, MAX_VAL indicates the maximum frame-length in bytes that may be received. Frames exceeding this length will be dropped. This traffic policing function is relevant to the 802.1Qci standard which specifies stream filtering based on a maximum service data unit (SDU) size. Position  */
#define GMAC_EMAC_RX_FLUSH_Q_MAX_VAL_Pos      _UINT32_(16)                                         /* (GMAC_EMAC_RX_FLUSH_Q) Maximum Value for the Received Frame Size or Number of 128-Byte Chunk Position */
#define GMAC_EMAC_RX_FLUSH_Q_MAX_VAL_Msk      (_UINT32_(0xFFFF) << GMAC_EMAC_RX_FLUSH_Q_MAX_VAL_Pos) /* (GMAC_EMAC_RX_FLUSH_Q) Maximum Value for the Received Frame Size or Number of 128-Byte Chunk Mask */
#define GMAC_EMAC_RX_FLUSH_Q_MAX_VAL(value)   (GMAC_EMAC_RX_FLUSH_Q_MAX_VAL_Msk & (_UINT32_(value) << GMAC_EMAC_RX_FLUSH_Q_MAX_VAL_Pos)) /* Assigment of value for MAX_VAL in the GMAC_EMAC_RX_FLUSH_Q register */
#define GMAC_EMAC_RX_FLUSH_Q_Msk              _UINT32_(0xFFFF000F)                                 /* (GMAC_EMAC_RX_FLUSH_Q) Register Mask  */


/* -------- GMAC_EMAC_SCR2_RATE_LIMIT : (GMAC Offset: 0x1B40) (R/W 32) Express MAC Screening 2 Rate Limit Register -------- */
#define GMAC_EMAC_SCR2_RATE_LIMIT_RESETVALUE  _UINT32_(0x00)                                       /*  (GMAC_EMAC_SCR2_RATE_LIMIT) Express MAC Screening 2 Rate Limit Register  Reset Value */

#define GMAC_EMAC_SCR2_RATE_LIMIT_INTERVAL_TIME_Pos _UINT32_(0)                                          /* (GMAC_EMAC_SCR2_RATE_LIMIT) Interval Time for Maximum Rate Checking Position */
#define GMAC_EMAC_SCR2_RATE_LIMIT_INTERVAL_TIME_Msk (_UINT32_(0xFFFF) << GMAC_EMAC_SCR2_RATE_LIMIT_INTERVAL_TIME_Pos) /* (GMAC_EMAC_SCR2_RATE_LIMIT) Interval Time for Maximum Rate Checking Mask */
#define GMAC_EMAC_SCR2_RATE_LIMIT_INTERVAL_TIME(value) (GMAC_EMAC_SCR2_RATE_LIMIT_INTERVAL_TIME_Msk & (_UINT32_(value) << GMAC_EMAC_SCR2_RATE_LIMIT_INTERVAL_TIME_Pos)) /* Assigment of value for INTERVAL_TIME in the GMAC_EMAC_SCR2_RATE_LIMIT register */
#define GMAC_EMAC_SCR2_RATE_LIMIT_MAX_RATE_VAL_Pos _UINT32_(16)                                         /* (GMAC_EMAC_SCR2_RATE_LIMIT) Maximum Rate Value for the Interval Time Position */
#define GMAC_EMAC_SCR2_RATE_LIMIT_MAX_RATE_VAL_Msk (_UINT32_(0xFFFF) << GMAC_EMAC_SCR2_RATE_LIMIT_MAX_RATE_VAL_Pos) /* (GMAC_EMAC_SCR2_RATE_LIMIT) Maximum Rate Value for the Interval Time Mask */
#define GMAC_EMAC_SCR2_RATE_LIMIT_MAX_RATE_VAL(value) (GMAC_EMAC_SCR2_RATE_LIMIT_MAX_RATE_VAL_Msk & (_UINT32_(value) << GMAC_EMAC_SCR2_RATE_LIMIT_MAX_RATE_VAL_Pos)) /* Assigment of value for MAX_RATE_VAL in the GMAC_EMAC_SCR2_RATE_LIMIT register */
#define GMAC_EMAC_SCR2_RATE_LIMIT_Msk         _UINT32_(0xFFFFFFFF)                                 /* (GMAC_EMAC_SCR2_RATE_LIMIT) Register Mask  */


/* -------- GMAC_EMAC_SCR2_RATE_STATUS : (GMAC Offset: 0x1B80) ( R/ 32) Express MAC Screening 2 Rate Status Register -------- */
#define GMAC_EMAC_SCR2_RATE_STATUS_RESETVALUE _UINT32_(0x00)                                       /*  (GMAC_EMAC_SCR2_RATE_STATUS) Express MAC Screening 2 Rate Status Register  Reset Value */

#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_Pos _UINT32_(0)                                          /* (GMAC_EMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 0 Position */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_Msk (_UINT32_(0x1) << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_Pos) /* (GMAC_EMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 0 Mask */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0(value) (GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_Msk & (_UINT32_(value) << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_Pos)) /* Assigment of value for EXCESS_RATE_Q0 in the GMAC_EMAC_SCR2_RATE_STATUS register */
#define   GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_EMAC_SCR2_RATE_STATUS.  */
#define   GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_EMAC_SCR2_RATE_STATUS.  */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_0 (GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_0_Val << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_Pos) /* (GMAC_EMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_EMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_1 (GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_1_Val << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q0_Pos) /* (GMAC_EMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_EMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_Pos _UINT32_(1)                                          /* (GMAC_EMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 1 Position */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_Msk (_UINT32_(0x1) << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_Pos) /* (GMAC_EMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 1 Mask */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1(value) (GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_Msk & (_UINT32_(value) << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_Pos)) /* Assigment of value for EXCESS_RATE_Q1 in the GMAC_EMAC_SCR2_RATE_STATUS register */
#define   GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_EMAC_SCR2_RATE_STATUS.  */
#define   GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_EMAC_SCR2_RATE_STATUS.  */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_0 (GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_0_Val << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_Pos) /* (GMAC_EMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_EMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_1 (GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_1_Val << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q1_Pos) /* (GMAC_EMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_EMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_Pos _UINT32_(2)                                          /* (GMAC_EMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 2 Position */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_Msk (_UINT32_(0x1) << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_Pos) /* (GMAC_EMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 2 Mask */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2(value) (GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_Msk & (_UINT32_(value) << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_Pos)) /* Assigment of value for EXCESS_RATE_Q2 in the GMAC_EMAC_SCR2_RATE_STATUS register */
#define   GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_EMAC_SCR2_RATE_STATUS.  */
#define   GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_EMAC_SCR2_RATE_STATUS.  */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_0 (GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_0_Val << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_Pos) /* (GMAC_EMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_EMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_1 (GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_1_Val << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q2_Pos) /* (GMAC_EMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_EMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_Pos _UINT32_(3)                                          /* (GMAC_EMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 3 Position */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_Msk (_UINT32_(0x1) << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_Pos) /* (GMAC_EMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 3 Mask */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3(value) (GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_Msk & (_UINT32_(value) << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_Pos)) /* Assigment of value for EXCESS_RATE_Q3 in the GMAC_EMAC_SCR2_RATE_STATUS register */
#define   GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_EMAC_SCR2_RATE_STATUS.  */
#define   GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_EMAC_SCR2_RATE_STATUS.  */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_0 (GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_0_Val << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_Pos) /* (GMAC_EMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_EMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_1 (GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_1_Val << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q3_Pos) /* (GMAC_EMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_EMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_Pos _UINT32_(4)                                          /* (GMAC_EMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 4 Position */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_Msk (_UINT32_(0x1) << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_Pos) /* (GMAC_EMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 4 Mask */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4(value) (GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_Msk & (_UINT32_(value) << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_Pos)) /* Assigment of value for EXCESS_RATE_Q4 in the GMAC_EMAC_SCR2_RATE_STATUS register */
#define   GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_EMAC_SCR2_RATE_STATUS.  */
#define   GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_EMAC_SCR2_RATE_STATUS.  */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_0 (GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_0_Val << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_Pos) /* (GMAC_EMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_EMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_1 (GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_1_Val << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q4_Pos) /* (GMAC_EMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_EMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_Pos _UINT32_(5)                                          /* (GMAC_EMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 5 Position */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_Msk (_UINT32_(0x1) << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_Pos) /* (GMAC_EMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 5 Mask */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5(value) (GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_Msk & (_UINT32_(value) << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_Pos)) /* Assigment of value for EXCESS_RATE_Q5 in the GMAC_EMAC_SCR2_RATE_STATUS register */
#define   GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_EMAC_SCR2_RATE_STATUS.  */
#define   GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_EMAC_SCR2_RATE_STATUS.  */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_0 (GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_0_Val << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_Pos) /* (GMAC_EMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_EMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_1 (GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_1_Val << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q5_Pos) /* (GMAC_EMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_EMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_Pos _UINT32_(6)                                          /* (GMAC_EMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 6 Position */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_Msk (_UINT32_(0x1) << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_Pos) /* (GMAC_EMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 6 Mask */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6(value) (GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_Msk & (_UINT32_(value) << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_Pos)) /* Assigment of value for EXCESS_RATE_Q6 in the GMAC_EMAC_SCR2_RATE_STATUS register */
#define   GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_EMAC_SCR2_RATE_STATUS.  */
#define   GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_EMAC_SCR2_RATE_STATUS.  */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_0 (GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_0_Val << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_Pos) /* (GMAC_EMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_EMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_1 (GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_1_Val << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q6_Pos) /* (GMAC_EMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_EMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_Pos _UINT32_(7)                                          /* (GMAC_EMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 7 Position */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_Msk (_UINT32_(0x1) << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_Pos) /* (GMAC_EMAC_SCR2_RATE_STATUS) Excessive Screener Rate Queue 7 Mask */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7(value) (GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_Msk & (_UINT32_(value) << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_Pos)) /* Assigment of value for EXCESS_RATE_Q7 in the GMAC_EMAC_SCR2_RATE_STATUS register */
#define   GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_0_Val _UINT32_(0x0)                                        /* (GMAC_EMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_EMAC_SCR2_RATE_STATUS.  */
#define   GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_1_Val _UINT32_(0x1)                                        /* (GMAC_EMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_EMAC_SCR2_RATE_STATUS.  */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_0 (GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_0_Val << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_Pos) /* (GMAC_EMAC_SCR2_RATE_STATUS) No excessive rate in screener since the last read of GMAC_EMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_1 (GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_1_Val << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q7_Pos) /* (GMAC_EMAC_SCR2_RATE_STATUS) A screener rate limiting mechanism has been triggered since the last read of GMAC_EMAC_SCR2_RATE_STATUS. Position  */
#define GMAC_EMAC_SCR2_RATE_STATUS_Msk        _UINT32_(0x000000FF)                                 /* (GMAC_EMAC_SCR2_RATE_STATUS) Register Mask  */

#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q_Pos _UINT32_(0)                                          /* (GMAC_EMAC_SCR2_RATE_STATUS Position) Excessive Screener Rate Queue 7 */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q_Msk (_UINT32_(0xFF) << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q_Pos) /* (GMAC_EMAC_SCR2_RATE_STATUS Mask) EXCESS_RATE_Q */
#define GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q(value) (GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q_Msk & (_UINT32_(value) << GMAC_EMAC_SCR2_RATE_STATUS_EXCESS_RATE_Q_Pos)) 

/** \brief GMAC register offsets definitions */
#define GMAC_EMAC_ASAB_REG_OFST        _UINT32_(0x00)      /* (GMAC_EMAC_ASAB) Express MAC Additional Specific Address Bottom Register  Offset */
#define GMAC_EMAC_ASAT_REG_OFST        _UINT32_(0x04)      /* (GMAC_EMAC_ASAT) Express MAC Additional Specific Address Top Register  Offset */
#define GMAC_EMAC_FRER_CTRLx_A_REG_OFST _UINT32_(0x00)      /* (GMAC_EMAC_FRER_CTRLx_A) Express MAC Frame Elimination Control1 A Register Offset */
#define GMAC_EMAC_FRER_CTRLx_B_REG_OFST _UINT32_(0x04)      /* (GMAC_EMAC_FRER_CTRLx_B) Express MAC Frame Elimination Control1 B Register Offset */
#define GMAC_EMAC_FRER_STATx_A_REG_OFST _UINT32_(0x08)      /* (GMAC_EMAC_FRER_STATx_A) Express MAC Frame Elimination Statistics1 A Register Offset */
#define GMAC_EMAC_FRER_STATx_B_REG_OFST _UINT32_(0x0C)      /* (GMAC_EMAC_FRER_STATx_B) Express MAC Frame Elimination Statistics1 B Register Offset */
#define GMAC_EMAC_SAB_REG_OFST         _UINT32_(0x00)      /* (GMAC_EMAC_SAB) Express MAC Specific Address Bottom Register  Offset */
#define GMAC_EMAC_SAT_REG_OFST         _UINT32_(0x04)      /* (GMAC_EMAC_SAT) Express MAC Specific Address Top Register  Offset */
#define GMAC_EMAC_ST2CW0R_REG_OFST     _UINT32_(0x00)      /* (GMAC_EMAC_ST2CW0R) Express MAC Screening Type 2 Compare Word 0 Register  Offset */
#define GMAC_EMAC_ST2CW1R_REG_OFST     _UINT32_(0x04)      /* (GMAC_EMAC_ST2CW1R) Express MAC Screening Type 2 Compare Word 1 Register  Offset */
#define GMAC_FRER_CTRL_A_REG_OFST      _UINT32_(0x00)      /* (GMAC_FRER_CTRL_A) Frame Elimination Control A Register  Offset */
#define GMAC_FRER_CTRL_B_REG_OFST      _UINT32_(0x04)      /* (GMAC_FRER_CTRL_B) Frame Elimination Control B Register  Offset */
#define GMAC_FRER_STAT_A_REG_OFST      _UINT32_(0x08)      /* (GMAC_FRER_STAT_A) Frame Elimination Statistics A Register  Offset */
#define GMAC_FRER_STAT_B_REG_OFST      _UINT32_(0x0C)      /* (GMAC_FRER_STAT_B) Frame Elimination Statistics B Register  Offset */
#define GMAC_ST2CW0R_REG_OFST          _UINT32_(0x00)      /* (GMAC_ST2CW0R) Screening Type 2 Compare Word 0 Register  Offset */
#define GMAC_ST2CW1R_REG_OFST          _UINT32_(0x04)      /* (GMAC_ST2CW1R) Screening Type 2 Compare Word 1 Register  Offset */
#define GMAC_NCR_REG_OFST              _UINT32_(0x00)      /* (GMAC_NCR) Network Control Register Offset */
#define GMAC_NCFGR_REG_OFST            _UINT32_(0x04)      /* (GMAC_NCFGR) Network Configuration Register Offset */
#define GMAC_NSR_REG_OFST              _UINT32_(0x08)      /* (GMAC_NSR) Network Status Register Offset */
#define GMAC_UR_REG_OFST               _UINT32_(0x0C)      /* (GMAC_UR) User Register Offset */
#define GMAC_DCFGR_REG_OFST            _UINT32_(0x10)      /* (GMAC_DCFGR) DMA Configuration Register Offset */
#define GMAC_TSR_REG_OFST              _UINT32_(0x14)      /* (GMAC_TSR) Transmit Status Register Offset */
#define GMAC_RBQB_REG_OFST             _UINT32_(0x18)      /* (GMAC_RBQB) Receive Buffer Queue Base Address Register Offset */
#define GMAC_TBQB_REG_OFST             _UINT32_(0x1C)      /* (GMAC_TBQB) Transmit Buffer Queue Base Address Register Offset */
#define GMAC_RSR_REG_OFST              _UINT32_(0x20)      /* (GMAC_RSR) Receive Status Register Offset */
#define GMAC_ISR_REG_OFST              _UINT32_(0x24)      /* (GMAC_ISR) Interrupt Status Register Offset */
#define GMAC_IER_REG_OFST              _UINT32_(0x28)      /* (GMAC_IER) Interrupt Enable Register Offset */
#define GMAC_IDR_REG_OFST              _UINT32_(0x2C)      /* (GMAC_IDR) Interrupt Disable Register Offset */
#define GMAC_IMR_REG_OFST              _UINT32_(0x30)      /* (GMAC_IMR) Interrupt Mask Register Offset */
#define GMAC_MAN_REG_OFST              _UINT32_(0x34)      /* (GMAC_MAN) PHY Maintenance Register Offset */
#define GMAC_RPQ_REG_OFST              _UINT32_(0x38)      /* (GMAC_RPQ) Receive Pause Quantum Register Offset */
#define GMAC_TPQ_REG_OFST              _UINT32_(0x3C)      /* (GMAC_TPQ) Transmit Pause Quantum Register Offset */
#define GMAC_TPSF_REG_OFST             _UINT32_(0x40)      /* (GMAC_TPSF) TX Partial Store and Forward Register Offset */
#define GMAC_RPSF_REG_OFST             _UINT32_(0x44)      /* (GMAC_RPSF) RX Partial Store and Forward Register Offset */
#define GMAC_RJFML_REG_OFST            _UINT32_(0x48)      /* (GMAC_RJFML) RX Jumbo Frame Max Length Register Offset */
#define GMAC_INTM_REG_OFST             _UINT32_(0x5C)      /* (GMAC_INTM) Interrupt Moderation Register Offset */
#define GMAC_SYSWT_REG_OFST            _UINT32_(0x60)      /* (GMAC_SYSWT) System Wake-Up Time Register Offset */
#define GMAC_LCKUP_CFGR_REG_OFST       _UINT32_(0x68)      /* (GMAC_LCKUP_CFGR) Lockup Configuration Register Offset */
#define GMAC_LCKUP_TIME_REG_OFST       _UINT32_(0x6C)      /* (GMAC_LCKUP_TIME) MAC Lockup Detection Time register Offset */
#define GMAC_TXDMA_LCKUP_CR_REG_OFST   _UINT32_(0x70)      /* (GMAC_TXDMA_LCKUP_CR) Transmit DMA Lockup Control Register Offset */
#define GMAC_RX_WATERMARK_REG_OFST     _UINT32_(0x7C)      /* (GMAC_RX_WATERMARK) Receive Watermark Register Offset */
#define GMAC_HRB_REG_OFST              _UINT32_(0x80)      /* (GMAC_HRB) Hash Register Bottom Offset */
#define GMAC_HRT_REG_OFST              _UINT32_(0x84)      /* (GMAC_HRT) Hash Register Top Offset */
#define GMAC_SAB1_REG_OFST             _UINT32_(0x88)      /* (GMAC_SAB1) Specific Address 1 Bottom Register Offset */
#define GMAC_SAT1_REG_OFST             _UINT32_(0x8C)      /* (GMAC_SAT1) Specific Address 1 Top Register Offset */
#define GMAC_SAB2_REG_OFST             _UINT32_(0x90)      /* (GMAC_SAB2) Specific Address 2 Bottom Register Offset */
#define GMAC_SAT2_REG_OFST             _UINT32_(0x94)      /* (GMAC_SAT2) Specific Address 2 Top Register Offset */
#define GMAC_SAB3_REG_OFST             _UINT32_(0x98)      /* (GMAC_SAB3) Specific Address 3 Bottom Register Offset */
#define GMAC_SAT3_REG_OFST             _UINT32_(0x9C)      /* (GMAC_SAT3) Specific Address 3 Top Register Offset */
#define GMAC_SAB4_REG_OFST             _UINT32_(0xA0)      /* (GMAC_SAB4) Specific Address 4 Bottom Register Offset */
#define GMAC_SAT4_REG_OFST             _UINT32_(0xA4)      /* (GMAC_SAT4) Specific Address 4 Top Register Offset */
#define GMAC_TIDM1_REG_OFST            _UINT32_(0xA8)      /* (GMAC_TIDM1) Type ID Match 1 Register Offset */
#define GMAC_TIDM2_REG_OFST            _UINT32_(0xAC)      /* (GMAC_TIDM2) Type ID Match 2 Register Offset */
#define GMAC_TIDM3_REG_OFST            _UINT32_(0xB0)      /* (GMAC_TIDM3) Type ID Match 3 Register Offset */
#define GMAC_TIDM4_REG_OFST            _UINT32_(0xB4)      /* (GMAC_TIDM4) Type ID Match 4 Register Offset */
#define GMAC_WOL_REG_OFST              _UINT32_(0xB8)      /* (GMAC_WOL) Wake on LAN Register Offset */
#define GMAC_IPGS_REG_OFST             _UINT32_(0xBC)      /* (GMAC_IPGS) IPG Stretch Register Offset */
#define GMAC_SVLAN_REG_OFST            _UINT32_(0xC0)      /* (GMAC_SVLAN) Stacked VLAN Register Offset */
#define GMAC_TPFCP_REG_OFST            _UINT32_(0xC4)      /* (GMAC_TPFCP) Transmit PFC Pause Register Offset */
#define GMAC_SAMB1_REG_OFST            _UINT32_(0xC8)      /* (GMAC_SAMB1) Specific Address 1 Mask Bottom Register Offset */
#define GMAC_SAMT1_REG_OFST            _UINT32_(0xCC)      /* (GMAC_SAMT1) Specific Address 1 Mask Top Register Offset */
#define GMAC_AMRX_REG_OFST             _UINT32_(0xD0)      /* (GMAC_AMRX) System Memory Address Mask for RX Data Buffer Accesses Register Offset */
#define GMAC_RXUDAR_REG_OFST           _UINT32_(0xD4)      /* (GMAC_RXUDAR) PTP RX Unicast IP Destination Address Register Offset */
#define GMAC_TXUDAR_REG_OFST           _UINT32_(0xD8)      /* (GMAC_TXUDAR) PTP TX Unicast IP Destination Address Register Offset */
#define GMAC_NSC_REG_OFST              _UINT32_(0xDC)      /* (GMAC_NSC) 1588 Timer Nanosecond Comparison Register Offset */
#define GMAC_SCL_REG_OFST              _UINT32_(0xE0)      /* (GMAC_SCL) 1588 Timer Second Comparison Low Register Offset */
#define GMAC_SCH_REG_OFST              _UINT32_(0xE4)      /* (GMAC_SCH) 1588 Timer Second Comparison High Register Offset */
#define GMAC_EFTSH_REG_OFST            _UINT32_(0xE8)      /* (GMAC_EFTSH) PTP Event Frame Transmitted Seconds High Register Offset */
#define GMAC_EFRSH_REG_OFST            _UINT32_(0xEC)      /* (GMAC_EFRSH) PTP Event Frame Received Seconds High Register Offset */
#define GMAC_PEFTSH_REG_OFST           _UINT32_(0xF0)      /* (GMAC_PEFTSH) PTP Peer Event Frame Transmitted Seconds High Register Offset */
#define GMAC_PEFRSH_REG_OFST           _UINT32_(0xF4)      /* (GMAC_PEFRSH) PTP Peer Event Frame Received Seconds High Register Offset */
#define GMAC_OTLO_REG_OFST             _UINT32_(0x100)     /* (GMAC_OTLO) Octets Transmitted Low Register Offset */
#define GMAC_OTHI_REG_OFST             _UINT32_(0x104)     /* (GMAC_OTHI) Octets Transmitted High Register Offset */
#define GMAC_FT_REG_OFST               _UINT32_(0x108)     /* (GMAC_FT) Frames Transmitted Register Offset */
#define GMAC_BCFT_REG_OFST             _UINT32_(0x10C)     /* (GMAC_BCFT) Broadcast Frames Transmitted Register Offset */
#define GMAC_MFT_REG_OFST              _UINT32_(0x110)     /* (GMAC_MFT) Multicast Frames Transmitted Register Offset */
#define GMAC_PFT_REG_OFST              _UINT32_(0x114)     /* (GMAC_PFT) Pause Frames Transmitted Register Offset */
#define GMAC_BFT64_REG_OFST            _UINT32_(0x118)     /* (GMAC_BFT64) 64 Byte Frames Transmitted Register Offset */
#define GMAC_TBFT127_REG_OFST          _UINT32_(0x11C)     /* (GMAC_TBFT127) 65 to 127 Byte Frames Transmitted Register Offset */
#define GMAC_TBFT255_REG_OFST          _UINT32_(0x120)     /* (GMAC_TBFT255) 128 to 255 Byte Frames Transmitted Register Offset */
#define GMAC_TBFT511_REG_OFST          _UINT32_(0x124)     /* (GMAC_TBFT511) 256 to 511 Byte Frames Transmitted Register Offset */
#define GMAC_TBFT1023_REG_OFST         _UINT32_(0x128)     /* (GMAC_TBFT1023) 512 to 1023 Byte Frames Transmitted Register Offset */
#define GMAC_TBFT1518_REG_OFST         _UINT32_(0x12C)     /* (GMAC_TBFT1518) 1024 to 1518 Byte Frames Transmitted Register Offset */
#define GMAC_GTBFT1518_REG_OFST        _UINT32_(0x130)     /* (GMAC_GTBFT1518) Greater Than 1518 Byte Frames Transmitted Register Offset */
#define GMAC_TUR_REG_OFST              _UINT32_(0x134)     /* (GMAC_TUR) Transmit Underruns Register Offset */
#define GMAC_SCF_REG_OFST              _UINT32_(0x138)     /* (GMAC_SCF) Single Collision Frames Register Offset */
#define GMAC_MCF_REG_OFST              _UINT32_(0x13C)     /* (GMAC_MCF) Multiple Collision Frames Register Offset */
#define GMAC_EC_REG_OFST               _UINT32_(0x140)     /* (GMAC_EC) Excessive Collisions Register Offset */
#define GMAC_LC_REG_OFST               _UINT32_(0x144)     /* (GMAC_LC) Late Collisions Register Offset */
#define GMAC_DTF_REG_OFST              _UINT32_(0x148)     /* (GMAC_DTF) Deferred Transmission Frames Register Offset */
#define GMAC_CSE_REG_OFST              _UINT32_(0x14C)     /* (GMAC_CSE) Carrier Sense Errors Register Offset */
#define GMAC_ORLO_REG_OFST             _UINT32_(0x150)     /* (GMAC_ORLO) Octets Received Low Received Register Offset */
#define GMAC_ORHI_REG_OFST             _UINT32_(0x154)     /* (GMAC_ORHI) Octets Received High Received Register Offset */
#define GMAC_FR_REG_OFST               _UINT32_(0x158)     /* (GMAC_FR) Frames Received Register Offset */
#define GMAC_BCFR_REG_OFST             _UINT32_(0x15C)     /* (GMAC_BCFR) Broadcast Frames Received Register Offset */
#define GMAC_MFR_REG_OFST              _UINT32_(0x160)     /* (GMAC_MFR) Multicast Frames Received Register Offset */
#define GMAC_PFR_REG_OFST              _UINT32_(0x164)     /* (GMAC_PFR) Pause Frames Received Register Offset */
#define GMAC_BFR64_REG_OFST            _UINT32_(0x168)     /* (GMAC_BFR64) 64 Byte Frames Received Register Offset */
#define GMAC_TBFR127_REG_OFST          _UINT32_(0x16C)     /* (GMAC_TBFR127) 65 to 127 Byte Frames Received Register Offset */
#define GMAC_TBFR255_REG_OFST          _UINT32_(0x170)     /* (GMAC_TBFR255) 128 to 255 Byte Frames Received Register Offset */
#define GMAC_TBFR511_REG_OFST          _UINT32_(0x174)     /* (GMAC_TBFR511) 256 to 511 Byte Frames Received Register Offset */
#define GMAC_TBFR1023_REG_OFST         _UINT32_(0x178)     /* (GMAC_TBFR1023) 512 to 1023 Byte Frames Received Register Offset */
#define GMAC_TBFR1518_REG_OFST         _UINT32_(0x17C)     /* (GMAC_TBFR1518) 1024 to 1518 Byte Frames Received Register Offset */
#define GMAC_TMXBFR_REG_OFST           _UINT32_(0x180)     /* (GMAC_TMXBFR) 1519 to Maximum Byte Frames Received Register Offset */
#define GMAC_UFR_REG_OFST              _UINT32_(0x184)     /* (GMAC_UFR) Undersize Frames Received Register Offset */
#define GMAC_OFR_REG_OFST              _UINT32_(0x188)     /* (GMAC_OFR) Oversize Frames Received Register Offset */
#define GMAC_JR_REG_OFST               _UINT32_(0x18C)     /* (GMAC_JR) Jabbers Received Register Offset */
#define GMAC_FCSE_REG_OFST             _UINT32_(0x190)     /* (GMAC_FCSE) Frame Check Sequence Errors Register Offset */
#define GMAC_LFFE_REG_OFST             _UINT32_(0x194)     /* (GMAC_LFFE) Length Field Frame Errors Register Offset */
#define GMAC_RSE_REG_OFST              _UINT32_(0x198)     /* (GMAC_RSE) Receive Symbol Errors Register Offset */
#define GMAC_AE_REG_OFST               _UINT32_(0x19C)     /* (GMAC_AE) Alignment Errors Register Offset */
#define GMAC_RRE_REG_OFST              _UINT32_(0x1A0)     /* (GMAC_RRE) Receive Resource Errors Register Offset */
#define GMAC_ROE_REG_OFST              _UINT32_(0x1A4)     /* (GMAC_ROE) Receive Overrun Register Offset */
#define GMAC_IHCE_REG_OFST             _UINT32_(0x1A8)     /* (GMAC_IHCE) IP Header Checksum Errors Register Offset */
#define GMAC_TCE_REG_OFST              _UINT32_(0x1AC)     /* (GMAC_TCE) TCP Checksum Errors Register Offset */
#define GMAC_UCE_REG_OFST              _UINT32_(0x1B0)     /* (GMAC_UCE) UDP Checksum Errors Register Offset */
#define GMAC_FLRXPCR_REG_OFST          _UINT32_(0x1B4)     /* (GMAC_FLRXPCR) Flushed Received Packets Counter Register Offset */
#define GMAC_TISUBN_REG_OFST           _UINT32_(0x1BC)     /* (GMAC_TISUBN) 1588 Timer Increment Sub-nanoseconds Register Offset */
#define GMAC_TSH_REG_OFST              _UINT32_(0x1C0)     /* (GMAC_TSH) 1588 Timer Seconds High Register Offset */
#define GMAC_TSL_REG_OFST              _UINT32_(0x1D0)     /* (GMAC_TSL) 1588 Timer Seconds Low Register Offset */
#define GMAC_TN_REG_OFST               _UINT32_(0x1D4)     /* (GMAC_TN) 1588 Timer Nanoseconds Register Offset */
#define GMAC_TA_REG_OFST               _UINT32_(0x1D8)     /* (GMAC_TA) 1588 Timer Adjust Register Offset */
#define GMAC_TI_REG_OFST               _UINT32_(0x1DC)     /* (GMAC_TI) 1588 Timer Increment Register Offset */
#define GMAC_EFTSL_REG_OFST            _UINT32_(0x1E0)     /* (GMAC_EFTSL) PTP Event Frame Transmitted Seconds Low Register Offset */
#define GMAC_EFTN_REG_OFST             _UINT32_(0x1E4)     /* (GMAC_EFTN) PTP Event Frame Transmitted Nanoseconds Register Offset */
#define GMAC_EFRSL_REG_OFST            _UINT32_(0x1E8)     /* (GMAC_EFRSL) PTP Event Frame Received Seconds Low Register Offset */
#define GMAC_EFRN_REG_OFST             _UINT32_(0x1EC)     /* (GMAC_EFRN) PTP Event Frame Received Nanoseconds Register Offset */
#define GMAC_PEFTSL_REG_OFST           _UINT32_(0x1F0)     /* (GMAC_PEFTSL) PTP Peer Event Frame Transmitted Seconds Low Register Offset */
#define GMAC_PEFTN_REG_OFST            _UINT32_(0x1F4)     /* (GMAC_PEFTN) PTP Peer Event Frame Transmitted Nanoseconds Register Offset */
#define GMAC_PEFRSL_REG_OFST           _UINT32_(0x1F8)     /* (GMAC_PEFRSL) PTP Peer Event Frame Received Seconds Low Register Offset */
#define GMAC_PEFRN_REG_OFST            _UINT32_(0x1FC)     /* (GMAC_PEFRN) PTP Peer Event Frame Received Nanoseconds Register Offset */
#define GMAC_RXLPI_REG_OFST            _UINT32_(0x270)     /* (GMAC_RXLPI) Received LPI Transitions Offset */
#define GMAC_RXLPITIME_REG_OFST        _UINT32_(0x274)     /* (GMAC_RXLPITIME) Received LPI Time Offset */
#define GMAC_TXLPI_REG_OFST            _UINT32_(0x278)     /* (GMAC_TXLPI) Transmit LPI Transitions Offset */
#define GMAC_TXLPITIME_REG_OFST        _UINT32_(0x27C)     /* (GMAC_TXLPITIME) Transmit LPI Time Offset */
#define GMAC_ISRPQ_REG_OFST            _UINT32_(0x400)     /* (GMAC_ISRPQ) Interrupt Status Register Priority Queue (index = 1) Offset */
#define GMAC_ISRPQ0_REG_OFST           _UINT32_(0x400)     /* (GMAC_ISRPQ0) Interrupt Status Register Priority Queue (index = 1) Offset */
#define GMAC_ISRPQ1_REG_OFST           _UINT32_(0x404)     /* (GMAC_ISRPQ1) Interrupt Status Register Priority Queue (index = 1) Offset */
#define GMAC_ISRPQ2_REG_OFST           _UINT32_(0x408)     /* (GMAC_ISRPQ2) Interrupt Status Register Priority Queue (index = 1) Offset */
#define GMAC_ISRPQ3_REG_OFST           _UINT32_(0x40C)     /* (GMAC_ISRPQ3) Interrupt Status Register Priority Queue (index = 1) Offset */
#define GMAC_ISRPQ4_REG_OFST           _UINT32_(0x410)     /* (GMAC_ISRPQ4) Interrupt Status Register Priority Queue (index = 1) Offset */
#define GMAC_TBQBAPQ_REG_OFST          _UINT32_(0x440)     /* (GMAC_TBQBAPQ) Transmit Buffer Queue Base Address Register Priority Queue (index = 1) Offset */
#define GMAC_TBQBAPQ0_REG_OFST         _UINT32_(0x440)     /* (GMAC_TBQBAPQ0) Transmit Buffer Queue Base Address Register Priority Queue (index = 1) Offset */
#define GMAC_TBQBAPQ1_REG_OFST         _UINT32_(0x444)     /* (GMAC_TBQBAPQ1) Transmit Buffer Queue Base Address Register Priority Queue (index = 1) Offset */
#define GMAC_TBQBAPQ2_REG_OFST         _UINT32_(0x448)     /* (GMAC_TBQBAPQ2) Transmit Buffer Queue Base Address Register Priority Queue (index = 1) Offset */
#define GMAC_TBQBAPQ3_REG_OFST         _UINT32_(0x44C)     /* (GMAC_TBQBAPQ3) Transmit Buffer Queue Base Address Register Priority Queue (index = 1) Offset */
#define GMAC_TBQBAPQ4_REG_OFST         _UINT32_(0x450)     /* (GMAC_TBQBAPQ4) Transmit Buffer Queue Base Address Register Priority Queue (index = 1) Offset */
#define GMAC_RBQBAPQ_REG_OFST          _UINT32_(0x480)     /* (GMAC_RBQBAPQ) Receive Buffer Queue Base Address Register Priority Queue (index = 1) Offset */
#define GMAC_RBQBAPQ0_REG_OFST         _UINT32_(0x480)     /* (GMAC_RBQBAPQ0) Receive Buffer Queue Base Address Register Priority Queue (index = 1) Offset */
#define GMAC_RBQBAPQ1_REG_OFST         _UINT32_(0x484)     /* (GMAC_RBQBAPQ1) Receive Buffer Queue Base Address Register Priority Queue (index = 1) Offset */
#define GMAC_RBQBAPQ2_REG_OFST         _UINT32_(0x488)     /* (GMAC_RBQBAPQ2) Receive Buffer Queue Base Address Register Priority Queue (index = 1) Offset */
#define GMAC_RBQBAPQ3_REG_OFST         _UINT32_(0x48C)     /* (GMAC_RBQBAPQ3) Receive Buffer Queue Base Address Register Priority Queue (index = 1) Offset */
#define GMAC_RBQBAPQ4_REG_OFST         _UINT32_(0x490)     /* (GMAC_RBQBAPQ4) Receive Buffer Queue Base Address Register Priority Queue (index = 1) Offset */
#define GMAC_RBSRPQ_REG_OFST           _UINT32_(0x4A0)     /* (GMAC_RBSRPQ) Receive Buffer Size Register Priority Queue (index = 1) Offset */
#define GMAC_RBSRPQ0_REG_OFST          _UINT32_(0x4A0)     /* (GMAC_RBSRPQ0) Receive Buffer Size Register Priority Queue (index = 1) Offset */
#define GMAC_RBSRPQ1_REG_OFST          _UINT32_(0x4A4)     /* (GMAC_RBSRPQ1) Receive Buffer Size Register Priority Queue (index = 1) Offset */
#define GMAC_RBSRPQ2_REG_OFST          _UINT32_(0x4A8)     /* (GMAC_RBSRPQ2) Receive Buffer Size Register Priority Queue (index = 1) Offset */
#define GMAC_RBSRPQ3_REG_OFST          _UINT32_(0x4AC)     /* (GMAC_RBSRPQ3) Receive Buffer Size Register Priority Queue (index = 1) Offset */
#define GMAC_RBSRPQ4_REG_OFST          _UINT32_(0x4B0)     /* (GMAC_RBSRPQ4) Receive Buffer Size Register Priority Queue (index = 1) Offset */
#define GMAC_CBSCR_REG_OFST            _UINT32_(0x4BC)     /* (GMAC_CBSCR) Credit-Based Shaping Control Register Offset */
#define GMAC_CBSISQA_REG_OFST          _UINT32_(0x4C0)     /* (GMAC_CBSISQA) Credit-Based Shaping IdleSlope Register for Queue A Offset */
#define GMAC_CBSISQB_REG_OFST          _UINT32_(0x4C4)     /* (GMAC_CBSISQB) Credit-Based Shaping IdleSlope Register for Queue B Offset */
#define GMAC_TQUBA_REG_OFST            _UINT32_(0x4C8)     /* (GMAC_TQUBA) 32 MSB Transmit Buffer Descriptor Queue Base Address Register Offset */
#define GMAC_TXBDCTRL_REG_OFST         _UINT32_(0x4CC)     /* (GMAC_TXBDCTRL) Transmit Buffer Data Control Register Offset */
#define GMAC_RXBDCTRL_REG_OFST         _UINT32_(0x4D0)     /* (GMAC_RXBDCTRL) Receive Buffer Data Control Register Offset */
#define GMAC_RQUBA_REG_OFST            _UINT32_(0x4D4)     /* (GMAC_RQUBA) 32 MSB Receive Buffer Descriptor Queue Base Address Register Offset */
#define GMAC_ST1RPQ_REG_OFST           _UINT32_(0x500)     /* (GMAC_ST1RPQ) Screening Type 1 Register Priority Queue (index = 0) Offset */
#define GMAC_ST1RPQ0_REG_OFST          _UINT32_(0x500)     /* (GMAC_ST1RPQ0) Screening Type 1 Register Priority Queue (index = 0) Offset */
#define GMAC_ST1RPQ1_REG_OFST          _UINT32_(0x504)     /* (GMAC_ST1RPQ1) Screening Type 1 Register Priority Queue (index = 0) Offset */
#define GMAC_ST1RPQ2_REG_OFST          _UINT32_(0x508)     /* (GMAC_ST1RPQ2) Screening Type 1 Register Priority Queue (index = 0) Offset */
#define GMAC_ST1RPQ3_REG_OFST          _UINT32_(0x50C)     /* (GMAC_ST1RPQ3) Screening Type 1 Register Priority Queue (index = 0) Offset */
#define GMAC_ST2RPQ_REG_OFST           _UINT32_(0x540)     /* (GMAC_ST2RPQ) Screening Type 2 Register Priority Queue (index = 0) Offset */
#define GMAC_ST2RPQ0_REG_OFST          _UINT32_(0x540)     /* (GMAC_ST2RPQ0) Screening Type 2 Register Priority Queue (index = 0) Offset */
#define GMAC_ST2RPQ1_REG_OFST          _UINT32_(0x544)     /* (GMAC_ST2RPQ1) Screening Type 2 Register Priority Queue (index = 0) Offset */
#define GMAC_ST2RPQ2_REG_OFST          _UINT32_(0x548)     /* (GMAC_ST2RPQ2) Screening Type 2 Register Priority Queue (index = 0) Offset */
#define GMAC_ST2RPQ3_REG_OFST          _UINT32_(0x54C)     /* (GMAC_ST2RPQ3) Screening Type 2 Register Priority Queue (index = 0) Offset */
#define GMAC_ST2RPQ4_REG_OFST          _UINT32_(0x550)     /* (GMAC_ST2RPQ4) Screening Type 2 Register Priority Queue (index = 0) Offset */
#define GMAC_ST2RPQ5_REG_OFST          _UINT32_(0x554)     /* (GMAC_ST2RPQ5) Screening Type 2 Register Priority Queue (index = 0) Offset */
#define GMAC_ST2RPQ6_REG_OFST          _UINT32_(0x558)     /* (GMAC_ST2RPQ6) Screening Type 2 Register Priority Queue (index = 0) Offset */
#define GMAC_ST2RPQ7_REG_OFST          _UINT32_(0x55C)     /* (GMAC_ST2RPQ7) Screening Type 2 Register Priority Queue (index = 0) Offset */
#define GMAC_TSCTL_REG_OFST            _UINT32_(0x580)     /* (GMAC_TSCTL) Transmit Schedule Control Register Offset */
#define GMAC_TQBWRL0_REG_OFST          _UINT32_(0x590)     /* (GMAC_TQBWRL0) Transmit Queue Bandwidth Rate Limit 0 Register Offset */
#define GMAC_TQSA_REG_OFST             _UINT32_(0x5A0)     /* (GMAC_TQSA) Transmit Queue Segment Allocation Register Offset */
#define GMAC_IERPQ_REG_OFST            _UINT32_(0x600)     /* (GMAC_IERPQ) Interrupt Enable Register Priority Queue (index = 1) Offset */
#define GMAC_IERPQ0_REG_OFST           _UINT32_(0x600)     /* (GMAC_IERPQ0) Interrupt Enable Register Priority Queue (index = 1) Offset */
#define GMAC_IERPQ1_REG_OFST           _UINT32_(0x604)     /* (GMAC_IERPQ1) Interrupt Enable Register Priority Queue (index = 1) Offset */
#define GMAC_IERPQ2_REG_OFST           _UINT32_(0x608)     /* (GMAC_IERPQ2) Interrupt Enable Register Priority Queue (index = 1) Offset */
#define GMAC_IERPQ3_REG_OFST           _UINT32_(0x60C)     /* (GMAC_IERPQ3) Interrupt Enable Register Priority Queue (index = 1) Offset */
#define GMAC_IERPQ4_REG_OFST           _UINT32_(0x610)     /* (GMAC_IERPQ4) Interrupt Enable Register Priority Queue (index = 1) Offset */
#define GMAC_IDRPQ_REG_OFST            _UINT32_(0x620)     /* (GMAC_IDRPQ) Interrupt Disable Register Priority Queue (index = 1) Offset */
#define GMAC_IDRPQ0_REG_OFST           _UINT32_(0x620)     /* (GMAC_IDRPQ0) Interrupt Disable Register Priority Queue (index = 1) Offset */
#define GMAC_IDRPQ1_REG_OFST           _UINT32_(0x624)     /* (GMAC_IDRPQ1) Interrupt Disable Register Priority Queue (index = 1) Offset */
#define GMAC_IDRPQ2_REG_OFST           _UINT32_(0x628)     /* (GMAC_IDRPQ2) Interrupt Disable Register Priority Queue (index = 1) Offset */
#define GMAC_IDRPQ3_REG_OFST           _UINT32_(0x62C)     /* (GMAC_IDRPQ3) Interrupt Disable Register Priority Queue (index = 1) Offset */
#define GMAC_IDRPQ4_REG_OFST           _UINT32_(0x630)     /* (GMAC_IDRPQ4) Interrupt Disable Register Priority Queue (index = 1) Offset */
#define GMAC_IMRPQ_REG_OFST            _UINT32_(0x640)     /* (GMAC_IMRPQ) Interrupt Mask Register Priority Queue (index = 1) Offset */
#define GMAC_IMRPQ0_REG_OFST           _UINT32_(0x640)     /* (GMAC_IMRPQ0) Interrupt Mask Register Priority Queue (index = 1) Offset */
#define GMAC_IMRPQ1_REG_OFST           _UINT32_(0x644)     /* (GMAC_IMRPQ1) Interrupt Mask Register Priority Queue (index = 1) Offset */
#define GMAC_IMRPQ2_REG_OFST           _UINT32_(0x648)     /* (GMAC_IMRPQ2) Interrupt Mask Register Priority Queue (index = 1) Offset */
#define GMAC_IMRPQ3_REG_OFST           _UINT32_(0x64C)     /* (GMAC_IMRPQ3) Interrupt Mask Register Priority Queue (index = 1) Offset */
#define GMAC_IMRPQ4_REG_OFST           _UINT32_(0x650)     /* (GMAC_IMRPQ4) Interrupt Mask Register Priority Queue (index = 1) Offset */
#define GMAC_ST2ER_REG_OFST            _UINT32_(0x6E0)     /* (GMAC_ST2ER) Screening Type 2 Ethertype Register (index = 0) Offset */
#define GMAC_ST2ER0_REG_OFST           _UINT32_(0x6E0)     /* (GMAC_ST2ER0) Screening Type 2 Ethertype Register (index = 0) Offset */
#define GMAC_ST2ER1_REG_OFST           _UINT32_(0x6E4)     /* (GMAC_ST2ER1) Screening Type 2 Ethertype Register (index = 0) Offset */
#define GMAC_ST2ER2_REG_OFST           _UINT32_(0x6E8)     /* (GMAC_ST2ER2) Screening Type 2 Ethertype Register (index = 0) Offset */
#define GMAC_ST2ER3_REG_OFST           _UINT32_(0x6EC)     /* (GMAC_ST2ER3) Screening Type 2 Ethertype Register (index = 0) Offset */
#define GMAC_ENST_START_Q_REG_OFST     _UINT32_(0x800)     /* (GMAC_ENST_START_Q) ENST Start Time Queue Register (index = 0) Offset */
#define GMAC_ENST_START_Q0_REG_OFST    _UINT32_(0x800)     /* (GMAC_ENST_START_Q0) ENST Start Time Queue Register (index = 0) Offset */
#define GMAC_ENST_START_Q1_REG_OFST    _UINT32_(0x804)     /* (GMAC_ENST_START_Q1) ENST Start Time Queue Register (index = 0) Offset */
#define GMAC_ENST_START_Q2_REG_OFST    _UINT32_(0x808)     /* (GMAC_ENST_START_Q2) ENST Start Time Queue Register (index = 0) Offset */
#define GMAC_ENST_START_Q3_REG_OFST    _UINT32_(0x80C)     /* (GMAC_ENST_START_Q3) ENST Start Time Queue Register (index = 0) Offset */
#define GMAC_ENST_START_Q4_REG_OFST    _UINT32_(0x810)     /* (GMAC_ENST_START_Q4) ENST Start Time Queue Register (index = 0) Offset */
#define GMAC_ENST_START_Q5_REG_OFST    _UINT32_(0x814)     /* (GMAC_ENST_START_Q5) ENST Start Time Queue Register (index = 0) Offset */
#define GMAC_ENST_ON_Q_REG_OFST        _UINT32_(0x820)     /* (GMAC_ENST_ON_Q) ENST On Time Queue Register (index = 0) Offset */
#define GMAC_ENST_ON_Q0_REG_OFST       _UINT32_(0x820)     /* (GMAC_ENST_ON_Q0) ENST On Time Queue Register (index = 0) Offset */
#define GMAC_ENST_ON_Q1_REG_OFST       _UINT32_(0x824)     /* (GMAC_ENST_ON_Q1) ENST On Time Queue Register (index = 0) Offset */
#define GMAC_ENST_ON_Q2_REG_OFST       _UINT32_(0x828)     /* (GMAC_ENST_ON_Q2) ENST On Time Queue Register (index = 0) Offset */
#define GMAC_ENST_ON_Q3_REG_OFST       _UINT32_(0x82C)     /* (GMAC_ENST_ON_Q3) ENST On Time Queue Register (index = 0) Offset */
#define GMAC_ENST_ON_Q4_REG_OFST       _UINT32_(0x830)     /* (GMAC_ENST_ON_Q4) ENST On Time Queue Register (index = 0) Offset */
#define GMAC_ENST_ON_Q5_REG_OFST       _UINT32_(0x834)     /* (GMAC_ENST_ON_Q5) ENST On Time Queue Register (index = 0) Offset */
#define GMAC_ENST_OFF_Q_REG_OFST       _UINT32_(0x840)     /* (GMAC_ENST_OFF_Q) ENST Off Time Queue Register (index = 0) Offset */
#define GMAC_ENST_OFF_Q0_REG_OFST      _UINT32_(0x840)     /* (GMAC_ENST_OFF_Q0) ENST Off Time Queue Register (index = 0) Offset */
#define GMAC_ENST_OFF_Q1_REG_OFST      _UINT32_(0x844)     /* (GMAC_ENST_OFF_Q1) ENST Off Time Queue Register (index = 0) Offset */
#define GMAC_ENST_OFF_Q2_REG_OFST      _UINT32_(0x848)     /* (GMAC_ENST_OFF_Q2) ENST Off Time Queue Register (index = 0) Offset */
#define GMAC_ENST_OFF_Q3_REG_OFST      _UINT32_(0x84C)     /* (GMAC_ENST_OFF_Q3) ENST Off Time Queue Register (index = 0) Offset */
#define GMAC_ENST_OFF_Q4_REG_OFST      _UINT32_(0x850)     /* (GMAC_ENST_OFF_Q4) ENST Off Time Queue Register (index = 0) Offset */
#define GMAC_ENST_OFF_Q5_REG_OFST      _UINT32_(0x854)     /* (GMAC_ENST_OFF_Q5) ENST Off Time Queue Register (index = 0) Offset */
#define GMAC_ENST_CR_REG_OFST          _UINT32_(0x880)     /* (GMAC_ENST_CR) ENST Control Register Offset */
#define GMAC_FRER_TIMEOUT_REG_OFST     _UINT32_(0x8A0)     /* (GMAC_FRER_TIMEOUT) Frame Elimination Timeout Register Offset */
#define GMAC_FRER_REDTAG_REG_OFST      _UINT32_(0x8A4)     /* (GMAC_FRER_REDTAG) Frame Elimination Redundancy Tag Register Offset */
#define GMAC_RX_FLUSH_Q_REG_OFST       _UINT32_(0xB00)     /* (GMAC_RX_FLUSH_Q) Receive Queue Flush Register (index = 0) Offset */
#define GMAC_RX_FLUSH_Q0_REG_OFST      _UINT32_(0xB00)     /* (GMAC_RX_FLUSH_Q0) Receive Queue Flush Register (index = 0) Offset */
#define GMAC_RX_FLUSH_Q1_REG_OFST      _UINT32_(0xB04)     /* (GMAC_RX_FLUSH_Q1) Receive Queue Flush Register (index = 0) Offset */
#define GMAC_RX_FLUSH_Q2_REG_OFST      _UINT32_(0xB08)     /* (GMAC_RX_FLUSH_Q2) Receive Queue Flush Register (index = 0) Offset */
#define GMAC_RX_FLUSH_Q3_REG_OFST      _UINT32_(0xB0C)     /* (GMAC_RX_FLUSH_Q3) Receive Queue Flush Register (index = 0) Offset */
#define GMAC_RX_FLUSH_Q4_REG_OFST      _UINT32_(0xB10)     /* (GMAC_RX_FLUSH_Q4) Receive Queue Flush Register (index = 0) Offset */
#define GMAC_RX_FLUSH_Q5_REG_OFST      _UINT32_(0xB14)     /* (GMAC_RX_FLUSH_Q5) Receive Queue Flush Register (index = 0) Offset */
#define GMAC_SCR2_RATE_LIMIT_REG_OFST  _UINT32_(0xB40)     /* (GMAC_SCR2_RATE_LIMIT) Screening 2 Rate Limit Register (index = 0) Offset */
#define GMAC_SCR2_RATE_LIMIT0_REG_OFST _UINT32_(0xB40)     /* (GMAC_SCR2_RATE_LIMIT0) Screening 2 Rate Limit Register (index = 0) Offset */
#define GMAC_SCR2_RATE_LIMIT1_REG_OFST _UINT32_(0xB44)     /* (GMAC_SCR2_RATE_LIMIT1) Screening 2 Rate Limit Register (index = 0) Offset */
#define GMAC_SCR2_RATE_LIMIT2_REG_OFST _UINT32_(0xB48)     /* (GMAC_SCR2_RATE_LIMIT2) Screening 2 Rate Limit Register (index = 0) Offset */
#define GMAC_SCR2_RATE_LIMIT3_REG_OFST _UINT32_(0xB4C)     /* (GMAC_SCR2_RATE_LIMIT3) Screening 2 Rate Limit Register (index = 0) Offset */
#define GMAC_SCR2_RATE_LIMIT4_REG_OFST _UINT32_(0xB50)     /* (GMAC_SCR2_RATE_LIMIT4) Screening 2 Rate Limit Register (index = 0) Offset */
#define GMAC_SCR2_RATE_LIMIT5_REG_OFST _UINT32_(0xB54)     /* (GMAC_SCR2_RATE_LIMIT5) Screening 2 Rate Limit Register (index = 0) Offset */
#define GMAC_SCR2_RATE_STATUS_REG_OFST _UINT32_(0xB80)     /* (GMAC_SCR2_RATE_STATUS) Screening 2 Rate Status Register Offset */
#define GMAC_MMSL_CR_REG_OFST          _UINT32_(0xF00)     /* (GMAC_MMSL_CR) MMSL Control Register Offset */
#define GMAC_MMSL_SR_REG_OFST          _UINT32_(0xF04)     /* (GMAC_MMSL_SR) MMSL Status Register Offset */
#define GMAC_MMSL_ESR_REG_OFST         _UINT32_(0xF08)     /* (GMAC_MMSL_ESR) MMSL Error Statistics Register Offset */
#define GMAC_MMSL_ASS_OK_REG_OFST      _UINT32_(0xF0C)     /* (GMAC_MMSL_ASS_OK) MMSL Frame Re-Assembled OK Register Offset */
#define GMAC_MMSL_RXFRAG_CNT_REG_OFST  _UINT32_(0xF10)     /* (GMAC_MMSL_RXFRAG_CNT) MMSL Received Fragment Counter Register Offset */
#define GMAC_MMSL_TXFRAG_CNT_REG_OFST  _UINT32_(0xF14)     /* (GMAC_MMSL_TXFRAG_CNT) MMSL Transmitted Fragment Counter Register Offset */
#define GMAC_MMSL_ISR_REG_OFST         _UINT32_(0xF18)     /* (GMAC_MMSL_ISR) MMSL Interrupt Status Register Offset */
#define GMAC_MMSL_IER_REG_OFST         _UINT32_(0xF1C)     /* (GMAC_MMSL_IER) MMSL Interrupt Enable Register Offset */
#define GMAC_MMSL_IDR_REG_OFST         _UINT32_(0xF20)     /* (GMAC_MMSL_IDR) MMSL Interrupt Disable Register Offset */
#define GMAC_MMSL_IMR_REG_OFST         _UINT32_(0xF24)     /* (GMAC_MMSL_IMR) MMSL Interrupt Mask Register Offset */
#define GMAC_EMAC_NCR_REG_OFST         _UINT32_(0x1000)    /* (GMAC_EMAC_NCR) Express MAC Network Control Register Offset */
#define GMAC_EMAC_NCFGR_REG_OFST       _UINT32_(0x1004)    /* (GMAC_EMAC_NCFGR) Express MAC Network Configuration Register Offset */
#define GMAC_EMAC_NSR_REG_OFST         _UINT32_(0x1008)    /* (GMAC_EMAC_NSR) Express MAC Network Status Register Offset */
#define GMAC_EMAC_DCFGR_REG_OFST       _UINT32_(0x1010)    /* (GMAC_EMAC_DCFGR) Express MAC DMA Configuration Register Offset */
#define GMAC_EMAC_TSR_REG_OFST         _UINT32_(0x1014)    /* (GMAC_EMAC_TSR) Express MAC Transmit Status Register Offset */
#define GMAC_EMAC_RBQB_REG_OFST        _UINT32_(0x1018)    /* (GMAC_EMAC_RBQB) Express MAC Receive Buffer Queue Base Address Register Offset */
#define GMAC_EMAC_TBQB_REG_OFST        _UINT32_(0x101C)    /* (GMAC_EMAC_TBQB) Express MAC Transmit Buffer Queue Base Address Register Offset */
#define GMAC_EMAC_RSR_REG_OFST         _UINT32_(0x1020)    /* (GMAC_EMAC_RSR) Express MAC Receive Status Register Offset */
#define GMAC_EMAC_ISR_REG_OFST         _UINT32_(0x1024)    /* (GMAC_EMAC_ISR) Express MAC Interrupt Status Register Offset */
#define GMAC_EMAC_IER_REG_OFST         _UINT32_(0x1028)    /* (GMAC_EMAC_IER) Express MAC Interrupt Enable Register Offset */
#define GMAC_EMAC_IDR_REG_OFST         _UINT32_(0x102C)    /* (GMAC_EMAC_IDR) Express MAC Interrupt Disable Register Offset */
#define GMAC_EMAC_IMR_REG_OFST         _UINT32_(0x1030)    /* (GMAC_EMAC_IMR) Express MAC Interrupt Mask Register Offset */
#define GMAC_EMAC_RPQ_REG_OFST         _UINT32_(0x1038)    /* (GMAC_EMAC_RPQ) Express MAC Receive Pause Quantum Register Offset */
#define GMAC_EMAC_TPQ_REG_OFST         _UINT32_(0x103C)    /* (GMAC_EMAC_TPQ) Express MAC Transmit Pause Quantum Register Offset */
#define GMAC_EMAC_TPSF_REG_OFST        _UINT32_(0x1040)    /* (GMAC_EMAC_TPSF) Express MAC TX Partial Store and Forward Register Offset */
#define GMAC_EMAC_RPSF_REG_OFST        _UINT32_(0x1044)    /* (GMAC_EMAC_RPSF) Express MAC RX Partial Store and Forward Register Offset */
#define GMAC_EMAC_RJFML_REG_OFST       _UINT32_(0x1048)    /* (GMAC_EMAC_RJFML) Express MAC RX Jumbo Frame Max Length Register Offset */
#define GMAC_EMAC_AMP_REG_OFST         _UINT32_(0x1054)    /* (GMAC_EMAC_AMP) Express MAC System Bus Maximum Pipeline Offset */
#define GMAC_EMAC_INTM_REG_OFST        _UINT32_(0x105C)    /* (GMAC_EMAC_INTM) Express MAC Interrupt Moderation Register Offset */
#define GMAC_EMAC_SYSWT_REG_OFST       _UINT32_(0x1060)    /* (GMAC_EMAC_SYSWT) Express MAC System Wake-Up Time Register Offset */
#define GMAC_EMAC_LCKUP_CFGR_REG_OFST  _UINT32_(0x1068)    /* (GMAC_EMAC_LCKUP_CFGR) Express MAC Lockup Detection and Recovery Configuration Offset */
#define GMAC_EMAC_LCKUP_TIME_REG_OFST  _UINT32_(0x106C)    /* (GMAC_EMAC_LCKUP_TIME) Express MAC Lockup Detection Time Offset */
#define GMAC_EMAC_TXDMA_LCKUP_CR_REG_OFST _UINT32_(0x1070)    /* (GMAC_EMAC_TXDMA_LCKUP_CR) Express MAC Transmit DMA Lockup Control Register Offset */
#define GMAC_EMAC_RX_WATERMARK_REG_OFST _UINT32_(0x107C)    /* (GMAC_EMAC_RX_WATERMARK) Express MAC Receive Watermark Register Offset */
#define GMAC_EMAC_HRB_REG_OFST         _UINT32_(0x1080)    /* (GMAC_EMAC_HRB) Express MAC Hash Register Bottom Offset */
#define GMAC_EMAC_HRT_REG_OFST         _UINT32_(0x1084)    /* (GMAC_EMAC_HRT) Express MAC Hash Register Top Offset */
#define GMAC_EMAC_TIDM1_REG_OFST       _UINT32_(0x10A8)    /* (GMAC_EMAC_TIDM1) Express MAC Type ID Match 1 Register Offset */
#define GMAC_EMAC_TIDM2_REG_OFST       _UINT32_(0x10AC)    /* (GMAC_EMAC_TIDM2) Express MAC Type ID Match 2 Register Offset */
#define GMAC_EMAC_TIDM3_REG_OFST       _UINT32_(0x10B0)    /* (GMAC_EMAC_TIDM3) Express MAC Type ID Match 3 Register Offset */
#define GMAC_EMAC_TIDM4_REG_OFST       _UINT32_(0x10B4)    /* (GMAC_EMAC_TIDM4) Express MAC Type ID Match 4 Register Offset */
#define GMAC_EMAC_WOL_REG_OFST         _UINT32_(0x10B8)    /* (GMAC_EMAC_WOL) Express MAC Wake on LAN Register Offset */
#define GMAC_EMAC_IPGS_REG_OFST        _UINT32_(0x10BC)    /* (GMAC_EMAC_IPGS) Express MAC IPG Stretch Register Offset */
#define GMAC_EMAC_SVLAN_REG_OFST       _UINT32_(0x10C0)    /* (GMAC_EMAC_SVLAN) Express MAC Stacked VLAN Register Offset */
#define GMAC_EMAC_TPFCP_REG_OFST       _UINT32_(0x10C4)    /* (GMAC_EMAC_TPFCP) Express MAC Transmit PFC Pause Register Offset */
#define GMAC_EMAC_SAMB1_REG_OFST       _UINT32_(0x10C8)    /* (GMAC_EMAC_SAMB1) Express MAC Specific Address 1 Mask Bottom Register Offset */
#define GMAC_EMAC_SAMT1_REG_OFST       _UINT32_(0x10CC)    /* (GMAC_EMAC_SAMT1) Express MAC Specific Address 1 Mask Top Register Offset */
#define GMAC_EMAC_AMRX_REG_OFST        _UINT32_(0x10D0)    /* (GMAC_EMAC_AMRX) System Memory Address Mask for RX Data Buffer Accesses Register Offset */
#define GMAC_EMAC_RXUDAR_REG_OFST      _UINT32_(0x10D4)    /* (GMAC_EMAC_RXUDAR) Express MAC PTP RX Unicast IP Destination Address Register Offset */
#define GMAC_EMAC_TXUDAR_REG_OFST      _UINT32_(0x10D8)    /* (GMAC_EMAC_TXUDAR) Express MAC PTP TX Unicast IP Destination Address Register Offset */
#define GMAC_EMAC_NSC_REG_OFST         _UINT32_(0x10DC)    /* (GMAC_EMAC_NSC) Express MAC 1588 Timer Nanosecond Comparison Register Offset */
#define GMAC_EMAC_SCL_REG_OFST         _UINT32_(0x10E0)    /* (GMAC_EMAC_SCL) Express MAC 1588 Timer Second Comparison Low Register Offset */
#define GMAC_EMAC_SCH_REG_OFST         _UINT32_(0x10E4)    /* (GMAC_EMAC_SCH) Express MAC 1588 Timer Second Comparison High Register Offset */
#define GMAC_EMAC_EFTSH_REG_OFST       _UINT32_(0x10E8)    /* (GMAC_EMAC_EFTSH) Express MAC PTP Event Frame Transmitted Seconds High Register Offset */
#define GMAC_EMAC_EFRSH_REG_OFST       _UINT32_(0x10EC)    /* (GMAC_EMAC_EFRSH) Express MAC PTP Event Frame Received Seconds High Register Offset */
#define GMAC_EMAC_PEFTSH_REG_OFST      _UINT32_(0x10F0)    /* (GMAC_EMAC_PEFTSH) Express MAC PTP Peer Event Frame Transmitted Seconds High Register Offset */
#define GMAC_EMAC_PEFRSH_REG_OFST      _UINT32_(0x10F4)    /* (GMAC_EMAC_PEFRSH) Express MAC PTP Peer Event Frame Received Seconds High Register Offset */
#define GMAC_EMAC_OTLO_REG_OFST        _UINT32_(0x1100)    /* (GMAC_EMAC_OTLO) Express MAC Octets Transmitted Low Register Offset */
#define GMAC_EMAC_OTHI_REG_OFST        _UINT32_(0x1104)    /* (GMAC_EMAC_OTHI) Express MAC Octets Transmitted High Register Offset */
#define GMAC_EMAC_FT_REG_OFST          _UINT32_(0x1108)    /* (GMAC_EMAC_FT) Express MAC Frames Transmitted Register Offset */
#define GMAC_EMAC_BCFT_REG_OFST        _UINT32_(0x110C)    /* (GMAC_EMAC_BCFT) Express MAC Broadcast Frames Transmitted Register Offset */
#define GMAC_EMAC_MFT_REG_OFST         _UINT32_(0x1110)    /* (GMAC_EMAC_MFT) Express MAC Multicast Frames Transmitted Register Offset */
#define GMAC_EMAC_PFT_REG_OFST         _UINT32_(0x1114)    /* (GMAC_EMAC_PFT) Express MAC Pause Frames Transmitted Register Offset */
#define GMAC_EMAC_BFT64_REG_OFST       _UINT32_(0x1118)    /* (GMAC_EMAC_BFT64) Express MAC 64 Byte Frames Transmitted Register Offset */
#define GMAC_EMAC_TBFT127_REG_OFST     _UINT32_(0x111C)    /* (GMAC_EMAC_TBFT127) Express MAC 65 to 127 Byte Frames Transmitted Register Offset */
#define GMAC_EMAC_TBFT255_REG_OFST     _UINT32_(0x1120)    /* (GMAC_EMAC_TBFT255) Express MAC 128 to 255 Byte Frames Transmitted Register Offset */
#define GMAC_EMAC_TBFT511_REG_OFST     _UINT32_(0x1124)    /* (GMAC_EMAC_TBFT511) Express MAC 256 to 511 Byte Frames Transmitted Register Offset */
#define GMAC_EMAC_TBFT1023_REG_OFST    _UINT32_(0x1128)    /* (GMAC_EMAC_TBFT1023) Express MAC 512 to 1023 Byte Frames Transmitted Register Offset */
#define GMAC_EMAC_TBFT1518_REG_OFST    _UINT32_(0x112C)    /* (GMAC_EMAC_TBFT1518) Express MAC 1024 to 1518 Byte Frames Transmitted Register Offset */
#define GMAC_EMAC_GTBFT1518_REG_OFST   _UINT32_(0x1130)    /* (GMAC_EMAC_GTBFT1518) Express MAC Greater Than 1518 Byte Frames Transmitted Register Offset */
#define GMAC_EMAC_TUR_REG_OFST         _UINT32_(0x1134)    /* (GMAC_EMAC_TUR) Express MAC Transmit Underruns Register Offset */
#define GMAC_EMAC_SCF_REG_OFST         _UINT32_(0x1138)    /* (GMAC_EMAC_SCF) Express MAC Single Collision Frames Register Offset */
#define GMAC_EMAC_MCF_REG_OFST         _UINT32_(0x113C)    /* (GMAC_EMAC_MCF) Express MAC Multiple Collision Frames Register Offset */
#define GMAC_EMAC_EC_REG_OFST          _UINT32_(0x1140)    /* (GMAC_EMAC_EC) Express MAC Excessive Collisions Register Offset */
#define GMAC_EMAC_LC_REG_OFST          _UINT32_(0x1144)    /* (GMAC_EMAC_LC) Express MAC Late Collisions Register Offset */
#define GMAC_EMAC_DTF_REG_OFST         _UINT32_(0x1148)    /* (GMAC_EMAC_DTF) Express MAC Deferred Transmission Frames Register Offset */
#define GMAC_EMAC_CSE_REG_OFST         _UINT32_(0x114C)    /* (GMAC_EMAC_CSE) Express MAC Carrier Sense Errors Register Offset */
#define GMAC_EMAC_ORLO_REG_OFST        _UINT32_(0x1150)    /* (GMAC_EMAC_ORLO) Express MAC Octets Received Low Received Register Offset */
#define GMAC_EMAC_ORHI_REG_OFST        _UINT32_(0x1154)    /* (GMAC_EMAC_ORHI) Express MAC Octets Received High Received Register Offset */
#define GMAC_EMAC_FR_REG_OFST          _UINT32_(0x1158)    /* (GMAC_EMAC_FR) Express MAC Frames Received Register Offset */
#define GMAC_EMAC_BCFR_REG_OFST        _UINT32_(0x115C)    /* (GMAC_EMAC_BCFR) Express MAC Broadcast Frames Received Register Offset */
#define GMAC_EMAC_MFR_REG_OFST         _UINT32_(0x1160)    /* (GMAC_EMAC_MFR) Express MAC Multicast Frames Received Register Offset */
#define GMAC_EMAC_PFR_REG_OFST         _UINT32_(0x1164)    /* (GMAC_EMAC_PFR) Express MAC Pause Frames Received Register Offset */
#define GMAC_EMAC_BFR64_REG_OFST       _UINT32_(0x1168)    /* (GMAC_EMAC_BFR64) Express MAC 64 Byte Frames Received Register Offset */
#define GMAC_EMAC_TBFR127_REG_OFST     _UINT32_(0x116C)    /* (GMAC_EMAC_TBFR127) Express MAC 65 to 127 Byte Frames Received Register Offset */
#define GMAC_EMAC_TBFR255_REG_OFST     _UINT32_(0x1170)    /* (GMAC_EMAC_TBFR255) Express MAC 128 to 255 Byte Frames Received Register Offset */
#define GMAC_EMAC_TBFR511_REG_OFST     _UINT32_(0x1174)    /* (GMAC_EMAC_TBFR511) Express MAC 256 to 511 Byte Frames Received Register Offset */
#define GMAC_EMAC_TBFR1023_REG_OFST    _UINT32_(0x1178)    /* (GMAC_EMAC_TBFR1023) Express MAC 512 to 1023 Byte Frames Received Register Offset */
#define GMAC_EMAC_TBFR1518_REG_OFST    _UINT32_(0x117C)    /* (GMAC_EMAC_TBFR1518) Express MAC 1024 to 1518 Byte Frames Received Register Offset */
#define GMAC_EMAC_TMXBFR_REG_OFST      _UINT32_(0x1180)    /* (GMAC_EMAC_TMXBFR) Express MAC 1519 to Maximum Byte Frames Received Register Offset */
#define GMAC_EMAC_UFR_REG_OFST         _UINT32_(0x1184)    /* (GMAC_EMAC_UFR) Express MAC Undersize Frames Received Register Offset */
#define GMAC_EMAC_OFR_REG_OFST         _UINT32_(0x1188)    /* (GMAC_EMAC_OFR) Express MAC Oversize Frames Received Register Offset */
#define GMAC_EMAC_JR_REG_OFST          _UINT32_(0x118C)    /* (GMAC_EMAC_JR) Express MAC Jabbers Received Register Offset */
#define GMAC_EMAC_FCSE_REG_OFST        _UINT32_(0x1190)    /* (GMAC_EMAC_FCSE) Express MAC Frame Check Sequence Errors Register Offset */
#define GMAC_EMAC_LFFE_REG_OFST        _UINT32_(0x1194)    /* (GMAC_EMAC_LFFE) Express MAC Length Field Frame Errors Register Offset */
#define GMAC_EMAC_RSE_REG_OFST         _UINT32_(0x1198)    /* (GMAC_EMAC_RSE) Express MAC Receive Symbol Errors Register Offset */
#define GMAC_EMAC_AE_REG_OFST          _UINT32_(0x119C)    /* (GMAC_EMAC_AE) Express MAC Alignment Errors Register Offset */
#define GMAC_EMAC_RRE_REG_OFST         _UINT32_(0x11A0)    /* (GMAC_EMAC_RRE) Express MAC Receive Resource Errors Register Offset */
#define GMAC_EMAC_ROE_REG_OFST         _UINT32_(0x11A4)    /* (GMAC_EMAC_ROE) Express MAC Receive Overrun Register Offset */
#define GMAC_EMAC_IHCE_REG_OFST        _UINT32_(0x11A8)    /* (GMAC_EMAC_IHCE) Express MAC IP Header Checksum Errors Register Offset */
#define GMAC_EMAC_TCE_REG_OFST         _UINT32_(0x11AC)    /* (GMAC_EMAC_TCE) Express MAC TCP Checksum Errors Register Offset */
#define GMAC_EMAC_UCE_REG_OFST         _UINT32_(0x11B0)    /* (GMAC_EMAC_UCE) Express MAC UDP Checksum Errors Register Offset */
#define GMAC_EMAC_FLRXPCR_REG_OFST     _UINT32_(0x11B4)    /* (GMAC_EMAC_FLRXPCR) Express MAC Flushed Received Packets Counter Register Offset */
#define GMAC_EMAC_TISUBN_REG_OFST      _UINT32_(0x11BC)    /* (GMAC_EMAC_TISUBN) Express MAC 1588 Timer Increment Sub-nanoseconds Register Offset */
#define GMAC_EMAC_TSH_REG_OFST         _UINT32_(0x11C0)    /* (GMAC_EMAC_TSH) Express MAC1588 Timer Seconds High Register Offset */
#define GMAC_EMAC_TSL_REG_OFST         _UINT32_(0x11D0)    /* (GMAC_EMAC_TSL) Express MAC1588 Timer Seconds Low Register Offset */
#define GMAC_EMAC_TN_REG_OFST          _UINT32_(0x11D4)    /* (GMAC_EMAC_TN) Express MAC1588 Timer Nanoseconds Register Offset */
#define GMAC_EMAC_TA_REG_OFST          _UINT32_(0x11D8)    /* (GMAC_EMAC_TA) Express MAC1588 Timer Adjust Register Offset */
#define GMAC_EMAC_TI_REG_OFST          _UINT32_(0x11DC)    /* (GMAC_EMAC_TI) Express MAC1588 Timer Increment Register Offset */
#define GMAC_EMAC_EFTSL_REG_OFST       _UINT32_(0x11E0)    /* (GMAC_EMAC_EFTSL) Express MAC PTP Event Frame Transmitted Seconds Low Register Offset */
#define GMAC_EMAC_EFTN_REG_OFST        _UINT32_(0x11E4)    /* (GMAC_EMAC_EFTN) Express MAC PTP Event Frame Transmitted Nanoseconds Register Offset */
#define GMAC_EMAC_EFRSL_REG_OFST       _UINT32_(0x11E8)    /* (GMAC_EMAC_EFRSL) Express MAC PTP Event Frame Received Seconds Low Register Offset */
#define GMAC_EMAC_EFRN_REG_OFST        _UINT32_(0x11EC)    /* (GMAC_EMAC_EFRN) Express MAC PTP Event Frame Received Nanoseconds Register Offset */
#define GMAC_EMAC_PEFTSL_REG_OFST      _UINT32_(0x11F0)    /* (GMAC_EMAC_PEFTSL) Express MAC PTP Peer Event Frame Transmitted Seconds Low Register Offset */
#define GMAC_EMAC_PEFTN_REG_OFST       _UINT32_(0x11F4)    /* (GMAC_EMAC_PEFTN) Express MAC PTP Peer Event Frame Transmitted Nanoseconds Register Offset */
#define GMAC_EMAC_PEFRSL_REG_OFST      _UINT32_(0x11F8)    /* (GMAC_EMAC_PEFRSL) Express MAC PTP Peer Event Frame Received Seconds Low Register Offset */
#define GMAC_EMAC_PEFRN_REG_OFST       _UINT32_(0x11FC)    /* (GMAC_EMAC_PEFRN) Express MAC PTP Peer Event Frame Received Nanoseconds Register Offset */
#define GMAC_EMAC_TXPQUANT1_REG_OFST   _UINT32_(0x1260)    /* (GMAC_EMAC_TXPQUANT1) Express MAC Transmit Pause Quantum 1 Register Offset */
#define GMAC_EMAC_TXPQUANT2_REG_OFST   _UINT32_(0x1264)    /* (GMAC_EMAC_TXPQUANT2) Express MAC Transmit Pause Quantum 2 Register Offset */
#define GMAC_EMAC_TXPQUANT3_REG_OFST   _UINT32_(0x1268)    /* (GMAC_EMAC_TXPQUANT3) Express MAC Transmit Pause Quantum 3 Register Offset */
#define GMAC_EMAC_RXLPI_REG_OFST       _UINT32_(0x1270)    /* (GMAC_EMAC_RXLPI) Express MAC Received LPI Transitions Offset */
#define GMAC_EMAC_RXLPITIME_REG_OFST   _UINT32_(0x1274)    /* (GMAC_EMAC_RXLPITIME) Express MAC Received LPI Time Offset */
#define GMAC_EMAC_TXLPI_REG_OFST       _UINT32_(0x1278)    /* (GMAC_EMAC_TXLPI) Express MAC Transmit LPI Transitions Offset */
#define GMAC_EMAC_TXLPITIME_REG_OFST   _UINT32_(0x127C)    /* (GMAC_EMAC_TXLPITIME) Express MAC Transmit LPI Time Offset */
#define GMAC_EMAC_QOS_CFG_REG_OFST     _UINT32_(0x12E0)    /* (GMAC_EMAC_QOS_CFG) Express MAC System Bus QoS Configuration Register Offset */
#define GMAC_EMAC_CBSCR_REG_OFST       _UINT32_(0x14BC)    /* (GMAC_EMAC_CBSCR) Express MAC Credit-Based Shaping Control Register Offset */
#define GMAC_EMAC_CBSISQA_REG_OFST     _UINT32_(0x14C0)    /* (GMAC_EMAC_CBSISQA) Express MAC Credit-Based Shaping IdleSlope Register for Queue A Offset */
#define GMAC_EMAC_CBSISQB_REG_OFST     _UINT32_(0x14C4)    /* (GMAC_EMAC_CBSISQB) Express MAC Credit-Based Shaping IdleSlope Register for Queue B Offset */
#define GMAC_EMAC_TQUBA_REG_OFST       _UINT32_(0x14C8)    /* (GMAC_EMAC_TQUBA) Express MAC 32 MSB Transmit Buffer Descriptor Queue Base Address Register Offset */
#define GMAC_EMAC_TXBDCTRL_REG_OFST    _UINT32_(0x14CC)    /* (GMAC_EMAC_TXBDCTRL) Express MAC Transmit Buffer Data Control Register Offset */
#define GMAC_EMAC_RXBDCTRL_REG_OFST    _UINT32_(0x14D0)    /* (GMAC_EMAC_RXBDCTRL) Express MAC Receive Buffer Data Control Register Offset */
#define GMAC_EMAC_RQUBA_REG_OFST       _UINT32_(0x14D4)    /* (GMAC_EMAC_RQUBA) Express MAC 32 MSB Receive Buffer Descriptor Queue Base Address Register Offset */
#define GMAC_EMAC_ST1R_REG_OFST        _UINT32_(0x1500)    /* (GMAC_EMAC_ST1R) Express MAC Screening Type 1 Register Offset */
#define GMAC_EMAC_ST2R_REG_OFST        _UINT32_(0x1540)    /* (GMAC_EMAC_ST2R) Express MAC Screening Type 2 Register (index = 0) Offset */
#define GMAC_EMAC_ST2R0_REG_OFST       _UINT32_(0x1540)    /* (GMAC_EMAC_ST2R0) Express MAC Screening Type 2 Register (index = 0) Offset */
#define GMAC_EMAC_ST2R1_REG_OFST       _UINT32_(0x1544)    /* (GMAC_EMAC_ST2R1) Express MAC Screening Type 2 Register (index = 0) Offset */
#define GMAC_EMAC_TSCTL_REG_OFST       _UINT32_(0x1580)    /* (GMAC_EMAC_TSCTL) Express MACTransmit Schedule Control Register Offset */
#define GMAC_EMAC_TQBWRL0_REG_OFST     _UINT32_(0x1590)    /* (GMAC_EMAC_TQBWRL0) Express MAC Transmit Queue Bandwidth Rate Limit 0 Register Offset */
#define GMAC_EMAC_TQSA_REG_OFST        _UINT32_(0x15A0)    /* (GMAC_EMAC_TQSA) Express MAC Transmit Queue Segment Allocation Register Offset */
#define GMAC_EMAC_ENST_START_Q_REG_OFST _UINT32_(0x1800)    /* (GMAC_EMAC_ENST_START_Q) Express MAC ENST Start Time Queue Register (index = 0) Offset */
#define GMAC_EMAC_ENST_START_Q0_REG_OFST _UINT32_(0x1800)    /* (GMAC_EMAC_ENST_START_Q0) Express MAC ENST Start Time Queue Register (index = 0) Offset */
#define GMAC_EMAC_ENST_START_Q1_REG_OFST _UINT32_(0x1804)    /* (GMAC_EMAC_ENST_START_Q1) Express MAC ENST Start Time Queue Register (index = 0) Offset */
#define GMAC_EMAC_ENST_START_Q2_REG_OFST _UINT32_(0x1808)    /* (GMAC_EMAC_ENST_START_Q2) Express MAC ENST Start Time Queue Register (index = 0) Offset */
#define GMAC_EMAC_ENST_START_Q3_REG_OFST _UINT32_(0x180C)    /* (GMAC_EMAC_ENST_START_Q3) Express MAC ENST Start Time Queue Register (index = 0) Offset */
#define GMAC_EMAC_ENST_START_Q4_REG_OFST _UINT32_(0x1810)    /* (GMAC_EMAC_ENST_START_Q4) Express MAC ENST Start Time Queue Register (index = 0) Offset */
#define GMAC_EMAC_ENST_START_Q5_REG_OFST _UINT32_(0x1814)    /* (GMAC_EMAC_ENST_START_Q5) Express MAC ENST Start Time Queue Register (index = 0) Offset */
#define GMAC_EMAC_ENST_ON_Q_REG_OFST   _UINT32_(0x1820)    /* (GMAC_EMAC_ENST_ON_Q) Express MAC ENST On Time Queue Register (index = 0) Offset */
#define GMAC_EMAC_ENST_ON_Q0_REG_OFST  _UINT32_(0x1820)    /* (GMAC_EMAC_ENST_ON_Q0) Express MAC ENST On Time Queue Register (index = 0) Offset */
#define GMAC_EMAC_ENST_ON_Q1_REG_OFST  _UINT32_(0x1824)    /* (GMAC_EMAC_ENST_ON_Q1) Express MAC ENST On Time Queue Register (index = 0) Offset */
#define GMAC_EMAC_ENST_ON_Q2_REG_OFST  _UINT32_(0x1828)    /* (GMAC_EMAC_ENST_ON_Q2) Express MAC ENST On Time Queue Register (index = 0) Offset */
#define GMAC_EMAC_ENST_ON_Q3_REG_OFST  _UINT32_(0x182C)    /* (GMAC_EMAC_ENST_ON_Q3) Express MAC ENST On Time Queue Register (index = 0) Offset */
#define GMAC_EMAC_ENST_ON_Q4_REG_OFST  _UINT32_(0x1830)    /* (GMAC_EMAC_ENST_ON_Q4) Express MAC ENST On Time Queue Register (index = 0) Offset */
#define GMAC_EMAC_ENST_ON_Q5_REG_OFST  _UINT32_(0x1834)    /* (GMAC_EMAC_ENST_ON_Q5) Express MAC ENST On Time Queue Register (index = 0) Offset */
#define GMAC_EMAC_ENST_OFF_Q_REG_OFST  _UINT32_(0x1840)    /* (GMAC_EMAC_ENST_OFF_Q) Express MAC ENST Off Time Queue Register (index = 0) Offset */
#define GMAC_EMAC_ENST_OFF_Q0_REG_OFST _UINT32_(0x1840)    /* (GMAC_EMAC_ENST_OFF_Q0) Express MAC ENST Off Time Queue Register (index = 0) Offset */
#define GMAC_EMAC_ENST_OFF_Q1_REG_OFST _UINT32_(0x1844)    /* (GMAC_EMAC_ENST_OFF_Q1) Express MAC ENST Off Time Queue Register (index = 0) Offset */
#define GMAC_EMAC_ENST_OFF_Q2_REG_OFST _UINT32_(0x1848)    /* (GMAC_EMAC_ENST_OFF_Q2) Express MAC ENST Off Time Queue Register (index = 0) Offset */
#define GMAC_EMAC_ENST_OFF_Q3_REG_OFST _UINT32_(0x184C)    /* (GMAC_EMAC_ENST_OFF_Q3) Express MAC ENST Off Time Queue Register (index = 0) Offset */
#define GMAC_EMAC_ENST_OFF_Q4_REG_OFST _UINT32_(0x1850)    /* (GMAC_EMAC_ENST_OFF_Q4) Express MAC ENST Off Time Queue Register (index = 0) Offset */
#define GMAC_EMAC_ENST_OFF_Q5_REG_OFST _UINT32_(0x1854)    /* (GMAC_EMAC_ENST_OFF_Q5) Express MAC ENST Off Time Queue Register (index = 0) Offset */
#define GMAC_EMAC_ENST_CR_REG_OFST     _UINT32_(0x1880)    /* (GMAC_EMAC_ENST_CR) Express MAC ENST Control Register Offset */
#define GMAC_EMAC_FRER_TIMEOUT_REG_OFST _UINT32_(0x18A0)    /* (GMAC_EMAC_FRER_TIMEOUT) Express MAC Frame Elimination Timeout Register Offset */
#define GMAC_EMAC_FRER_REDTAG_REG_OFST _UINT32_(0x18A4)    /* (GMAC_EMAC_FRER_REDTAG) Express MAC Frame Elimination Redundancy Tag Register Offset */
#define GMAC_EMAC_RX_FLUSH_Q_REG_OFST  _UINT32_(0x1B00)    /* (GMAC_EMAC_RX_FLUSH_Q) Express MAC Receive Queue Flush Register Offset */
#define GMAC_EMAC_SCR2_RATE_LIMIT_REG_OFST _UINT32_(0x1B40)    /* (GMAC_EMAC_SCR2_RATE_LIMIT) Express MAC Screening 2 Rate Limit Register Offset */
#define GMAC_EMAC_SCR2_RATE_STATUS_REG_OFST _UINT32_(0x1B80)    /* (GMAC_EMAC_SCR2_RATE_STATUS) Express MAC Screening 2 Rate Status Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief GMAC_EMAC_ASA register API structure */
typedef struct
{
  __IO  uint32_t                       GMAC_EMAC_ASAB;     /**< Offset: 0x00 (R/W  32) Express MAC Additional Specific Address Bottom Register  */
  __IO  uint32_t                       GMAC_EMAC_ASAT;     /**< Offset: 0x04 (R/W  32) Express MAC Additional Specific Address Top Register  */
} gmac_emac_asa_registers_t;

/** \brief GMAC_EMAC_FRER register API structure */
typedef struct
{
  __IO  uint32_t                       GMAC_EMAC_FRER_CTRLx_A; /**< Offset: 0x00 (R/W  32) Express MAC Frame Elimination Control1 A Register */
  __IO  uint32_t                       GMAC_EMAC_FRER_CTRLx_B; /**< Offset: 0x04 (R/W  32) Express MAC Frame Elimination Control1 B Register */
  __IO  uint32_t                       GMAC_EMAC_FRER_STATx_A; /**< Offset: 0x08 (R/W  32) Express MAC Frame Elimination Statistics1 A Register */
  __IO  uint32_t                       GMAC_EMAC_FRER_STATx_B; /**< Offset: 0x0C (R/W  32) Express MAC Frame Elimination Statistics1 B Register */
} gmac_emac_frer_registers_t;

/** \brief GMAC_EMAC_SA register API structure */
typedef struct
{
  __IO  uint32_t                       GMAC_EMAC_SAB;      /**< Offset: 0x00 (R/W  32) Express MAC Specific Address Bottom Register  */
  __IO  uint32_t                       GMAC_EMAC_SAT;      /**< Offset: 0x04 (R/W  32) Express MAC Specific Address Top Register  */
} gmac_emac_sa_registers_t;

/** \brief GMAC_EMAC_ST2CW register API structure */
typedef struct
{
  __IO  uint32_t                       GMAC_EMAC_ST2CW0R;  /**< Offset: 0x00 (R/W  32) Express MAC Screening Type 2 Compare Word 0 Register  */
  __IO  uint32_t                       GMAC_EMAC_ST2CW1R;  /**< Offset: 0x04 (R/W  32) Express MAC Screening Type 2 Compare Word 1 Register  */
} gmac_emac_st2cw_registers_t;

/** \brief GMAC_FRER register API structure */
typedef struct
{
  __IO  uint32_t                       GMAC_FRER_CTRL_A;   /**< Offset: 0x00 (R/W  32) Frame Elimination Control A Register  */
  __IO  uint32_t                       GMAC_FRER_CTRL_B;   /**< Offset: 0x04 (R/W  32) Frame Elimination Control B Register  */
  __I   uint32_t                       GMAC_FRER_STAT_A;   /**< Offset: 0x08 (R/   32) Frame Elimination Statistics A Register  */
  __I   uint32_t                       GMAC_FRER_STAT_B;   /**< Offset: 0x0C (R/   32) Frame Elimination Statistics B Register  */
} gmac_frer_registers_t;

/** \brief GMAC_ST2CW register API structure */
typedef struct
{
  __IO  uint32_t                       GMAC_ST2CW0R;       /**< Offset: 0x00 (R/W  32) Screening Type 2 Compare Word 0 Register  */
  __IO  uint32_t                       GMAC_ST2CW1R;       /**< Offset: 0x04 (R/W  32) Screening Type 2 Compare Word 1 Register  */
} gmac_st2cw_registers_t;

#define GMAC_ST2CW_NUMBER 24

#define GMAC_FRER_NUMBER 6

#define GMAC_EMAC_SA_NUMBER 4

#define GMAC_EMAC_ASA_NUMBER 32

#define GMAC_EMAC_ST2CW_NUMBER 6

#define GMAC_EMAC_FRER_NUMBER 2

/** \brief GMAC register API structure */
typedef struct
{  /* Gigabit Ethernet MAC */
  __IO  uint32_t                       GMAC_NCR;           /**< Offset: 0x00 (R/W  32) Network Control Register */
  __IO  uint32_t                       GMAC_NCFGR;         /**< Offset: 0x04 (R/W  32) Network Configuration Register */
  __I   uint32_t                       GMAC_NSR;           /**< Offset: 0x08 (R/   32) Network Status Register */
  __IO  uint32_t                       GMAC_UR;            /**< Offset: 0x0C (R/W  32) User Register */
  __IO  uint32_t                       GMAC_DCFGR;         /**< Offset: 0x10 (R/W  32) DMA Configuration Register */
  __IO  uint32_t                       GMAC_TSR;           /**< Offset: 0x14 (R/W  32) Transmit Status Register */
  __IO  uint32_t                       GMAC_RBQB;          /**< Offset: 0x18 (R/W  32) Receive Buffer Queue Base Address Register */
  __IO  uint32_t                       GMAC_TBQB;          /**< Offset: 0x1C (R/W  32) Transmit Buffer Queue Base Address Register */
  __IO  uint32_t                       GMAC_RSR;           /**< Offset: 0x20 (R/W  32) Receive Status Register */
  __I   uint32_t                       GMAC_ISR;           /**< Offset: 0x24 (R/   32) Interrupt Status Register */
  __O   uint32_t                       GMAC_IER;           /**< Offset: 0x28 ( /W  32) Interrupt Enable Register */
  __O   uint32_t                       GMAC_IDR;           /**< Offset: 0x2C ( /W  32) Interrupt Disable Register */
  __IO  uint32_t                       GMAC_IMR;           /**< Offset: 0x30 (R/W  32) Interrupt Mask Register */
  __IO  uint32_t                       GMAC_MAN;           /**< Offset: 0x34 (R/W  32) PHY Maintenance Register */
  __I   uint32_t                       GMAC_RPQ;           /**< Offset: 0x38 (R/   32) Receive Pause Quantum Register */
  __IO  uint32_t                       GMAC_TPQ;           /**< Offset: 0x3C (R/W  32) Transmit Pause Quantum Register */
  __IO  uint32_t                       GMAC_TPSF;          /**< Offset: 0x40 (R/W  32) TX Partial Store and Forward Register */
  __IO  uint32_t                       GMAC_RPSF;          /**< Offset: 0x44 (R/W  32) RX Partial Store and Forward Register */
  __IO  uint32_t                       GMAC_RJFML;         /**< Offset: 0x48 (R/W  32) RX Jumbo Frame Max Length Register */
  __I   uint8_t                        Reserved1[0x10];
  __IO  uint32_t                       GMAC_INTM;          /**< Offset: 0x5C (R/W  32) Interrupt Moderation Register */
  __IO  uint32_t                       GMAC_SYSWT;         /**< Offset: 0x60 (R/W  32) System Wake-Up Time Register */
  __I   uint8_t                        Reserved2[0x04];
  __IO  uint32_t                       GMAC_LCKUP_CFGR;    /**< Offset: 0x68 (R/W  32) Lockup Configuration Register */
  __IO  uint32_t                       GMAC_LCKUP_TIME;    /**< Offset: 0x6C (R/W  32) MAC Lockup Detection Time register */
  __IO  uint32_t                       GMAC_TXDMA_LCKUP_CR; /**< Offset: 0x70 (R/W  32) Transmit DMA Lockup Control Register */
  __I   uint8_t                        Reserved3[0x08];
  __IO  uint32_t                       GMAC_RX_WATERMARK;  /**< Offset: 0x7C (R/W  32) Receive Watermark Register */
  __IO  uint32_t                       GMAC_HRB;           /**< Offset: 0x80 (R/W  32) Hash Register Bottom */
  __IO  uint32_t                       GMAC_HRT;           /**< Offset: 0x84 (R/W  32) Hash Register Top */
  __IO  uint32_t                       GMAC_SAB1;          /**< Offset: 0x88 (R/W  32) Specific Address 1 Bottom Register */
  __IO  uint32_t                       GMAC_SAT1;          /**< Offset: 0x8C (R/W  32) Specific Address 1 Top Register */
  __IO  uint32_t                       GMAC_SAB2;          /**< Offset: 0x90 (R/W  32) Specific Address 2 Bottom Register */
  __IO  uint32_t                       GMAC_SAT2;          /**< Offset: 0x94 (R/W  32) Specific Address 2 Top Register */
  __IO  uint32_t                       GMAC_SAB3;          /**< Offset: 0x98 (R/W  32) Specific Address 3 Bottom Register */
  __IO  uint32_t                       GMAC_SAT3;          /**< Offset: 0x9C (R/W  32) Specific Address 3 Top Register */
  __IO  uint32_t                       GMAC_SAB4;          /**< Offset: 0xA0 (R/W  32) Specific Address 4 Bottom Register */
  __IO  uint32_t                       GMAC_SAT4;          /**< Offset: 0xA4 (R/W  32) Specific Address 4 Top Register */
  __IO  uint32_t                       GMAC_TIDM1;         /**< Offset: 0xA8 (R/W  32) Type ID Match 1 Register */
  __IO  uint32_t                       GMAC_TIDM2;         /**< Offset: 0xAC (R/W  32) Type ID Match 2 Register */
  __IO  uint32_t                       GMAC_TIDM3;         /**< Offset: 0xB0 (R/W  32) Type ID Match 3 Register */
  __IO  uint32_t                       GMAC_TIDM4;         /**< Offset: 0xB4 (R/W  32) Type ID Match 4 Register */
  __IO  uint32_t                       GMAC_WOL;           /**< Offset: 0xB8 (R/W  32) Wake on LAN Register */
  __IO  uint32_t                       GMAC_IPGS;          /**< Offset: 0xBC (R/W  32) IPG Stretch Register */
  __IO  uint32_t                       GMAC_SVLAN;         /**< Offset: 0xC0 (R/W  32) Stacked VLAN Register */
  __IO  uint32_t                       GMAC_TPFCP;         /**< Offset: 0xC4 (R/W  32) Transmit PFC Pause Register */
  __IO  uint32_t                       GMAC_SAMB1;         /**< Offset: 0xC8 (R/W  32) Specific Address 1 Mask Bottom Register */
  __IO  uint32_t                       GMAC_SAMT1;         /**< Offset: 0xCC (R/W  32) Specific Address 1 Mask Top Register */
  __IO  uint32_t                       GMAC_AMRX;          /**< Offset: 0xD0 (R/W  32) System Memory Address Mask for RX Data Buffer Accesses Register */
  __IO  uint32_t                       GMAC_RXUDAR;        /**< Offset: 0xD4 (R/W  32) PTP RX Unicast IP Destination Address Register */
  __IO  uint32_t                       GMAC_TXUDAR;        /**< Offset: 0xD8 (R/W  32) PTP TX Unicast IP Destination Address Register */
  __IO  uint32_t                       GMAC_NSC;           /**< Offset: 0xDC (R/W  32) 1588 Timer Nanosecond Comparison Register */
  __IO  uint32_t                       GMAC_SCL;           /**< Offset: 0xE0 (R/W  32) 1588 Timer Second Comparison Low Register */
  __IO  uint32_t                       GMAC_SCH;           /**< Offset: 0xE4 (R/W  32) 1588 Timer Second Comparison High Register */
  __I   uint32_t                       GMAC_EFTSH;         /**< Offset: 0xE8 (R/   32) PTP Event Frame Transmitted Seconds High Register */
  __I   uint32_t                       GMAC_EFRSH;         /**< Offset: 0xEC (R/   32) PTP Event Frame Received Seconds High Register */
  __I   uint32_t                       GMAC_PEFTSH;        /**< Offset: 0xF0 (R/   32) PTP Peer Event Frame Transmitted Seconds High Register */
  __I   uint32_t                       GMAC_PEFRSH;        /**< Offset: 0xF4 (R/   32) PTP Peer Event Frame Received Seconds High Register */
  __I   uint8_t                        Reserved4[0x08];
  __I   uint32_t                       GMAC_OTLO;          /**< Offset: 0x100 (R/   32) Octets Transmitted Low Register */
  __I   uint32_t                       GMAC_OTHI;          /**< Offset: 0x104 (R/   32) Octets Transmitted High Register */
  __I   uint32_t                       GMAC_FT;            /**< Offset: 0x108 (R/   32) Frames Transmitted Register */
  __I   uint32_t                       GMAC_BCFT;          /**< Offset: 0x10C (R/   32) Broadcast Frames Transmitted Register */
  __I   uint32_t                       GMAC_MFT;           /**< Offset: 0x110 (R/   32) Multicast Frames Transmitted Register */
  __I   uint32_t                       GMAC_PFT;           /**< Offset: 0x114 (R/   32) Pause Frames Transmitted Register */
  __I   uint32_t                       GMAC_BFT64;         /**< Offset: 0x118 (R/   32) 64 Byte Frames Transmitted Register */
  __I   uint32_t                       GMAC_TBFT127;       /**< Offset: 0x11C (R/   32) 65 to 127 Byte Frames Transmitted Register */
  __I   uint32_t                       GMAC_TBFT255;       /**< Offset: 0x120 (R/   32) 128 to 255 Byte Frames Transmitted Register */
  __I   uint32_t                       GMAC_TBFT511;       /**< Offset: 0x124 (R/   32) 256 to 511 Byte Frames Transmitted Register */
  __I   uint32_t                       GMAC_TBFT1023;      /**< Offset: 0x128 (R/   32) 512 to 1023 Byte Frames Transmitted Register */
  __I   uint32_t                       GMAC_TBFT1518;      /**< Offset: 0x12C (R/   32) 1024 to 1518 Byte Frames Transmitted Register */
  __I   uint32_t                       GMAC_GTBFT1518;     /**< Offset: 0x130 (R/   32) Greater Than 1518 Byte Frames Transmitted Register */
  __I   uint32_t                       GMAC_TUR;           /**< Offset: 0x134 (R/   32) Transmit Underruns Register */
  __I   uint32_t                       GMAC_SCF;           /**< Offset: 0x138 (R/   32) Single Collision Frames Register */
  __I   uint32_t                       GMAC_MCF;           /**< Offset: 0x13C (R/   32) Multiple Collision Frames Register */
  __I   uint32_t                       GMAC_EC;            /**< Offset: 0x140 (R/   32) Excessive Collisions Register */
  __I   uint32_t                       GMAC_LC;            /**< Offset: 0x144 (R/   32) Late Collisions Register */
  __I   uint32_t                       GMAC_DTF;           /**< Offset: 0x148 (R/   32) Deferred Transmission Frames Register */
  __I   uint32_t                       GMAC_CSE;           /**< Offset: 0x14C (R/   32) Carrier Sense Errors Register */
  __I   uint32_t                       GMAC_ORLO;          /**< Offset: 0x150 (R/   32) Octets Received Low Received Register */
  __I   uint32_t                       GMAC_ORHI;          /**< Offset: 0x154 (R/   32) Octets Received High Received Register */
  __I   uint32_t                       GMAC_FR;            /**< Offset: 0x158 (R/   32) Frames Received Register */
  __I   uint32_t                       GMAC_BCFR;          /**< Offset: 0x15C (R/   32) Broadcast Frames Received Register */
  __I   uint32_t                       GMAC_MFR;           /**< Offset: 0x160 (R/   32) Multicast Frames Received Register */
  __I   uint32_t                       GMAC_PFR;           /**< Offset: 0x164 (R/   32) Pause Frames Received Register */
  __I   uint32_t                       GMAC_BFR64;         /**< Offset: 0x168 (R/   32) 64 Byte Frames Received Register */
  __I   uint32_t                       GMAC_TBFR127;       /**< Offset: 0x16C (R/   32) 65 to 127 Byte Frames Received Register */
  __I   uint32_t                       GMAC_TBFR255;       /**< Offset: 0x170 (R/   32) 128 to 255 Byte Frames Received Register */
  __I   uint32_t                       GMAC_TBFR511;       /**< Offset: 0x174 (R/   32) 256 to 511 Byte Frames Received Register */
  __I   uint32_t                       GMAC_TBFR1023;      /**< Offset: 0x178 (R/   32) 512 to 1023 Byte Frames Received Register */
  __I   uint32_t                       GMAC_TBFR1518;      /**< Offset: 0x17C (R/   32) 1024 to 1518 Byte Frames Received Register */
  __I   uint32_t                       GMAC_TMXBFR;        /**< Offset: 0x180 (R/   32) 1519 to Maximum Byte Frames Received Register */
  __I   uint32_t                       GMAC_UFR;           /**< Offset: 0x184 (R/   32) Undersize Frames Received Register */
  __I   uint32_t                       GMAC_OFR;           /**< Offset: 0x188 (R/   32) Oversize Frames Received Register */
  __I   uint32_t                       GMAC_JR;            /**< Offset: 0x18C (R/   32) Jabbers Received Register */
  __I   uint32_t                       GMAC_FCSE;          /**< Offset: 0x190 (R/   32) Frame Check Sequence Errors Register */
  __I   uint32_t                       GMAC_LFFE;          /**< Offset: 0x194 (R/   32) Length Field Frame Errors Register */
  __I   uint32_t                       GMAC_RSE;           /**< Offset: 0x198 (R/   32) Receive Symbol Errors Register */
  __I   uint32_t                       GMAC_AE;            /**< Offset: 0x19C (R/   32) Alignment Errors Register */
  __I   uint32_t                       GMAC_RRE;           /**< Offset: 0x1A0 (R/   32) Receive Resource Errors Register */
  __I   uint32_t                       GMAC_ROE;           /**< Offset: 0x1A4 (R/   32) Receive Overrun Register */
  __I   uint32_t                       GMAC_IHCE;          /**< Offset: 0x1A8 (R/   32) IP Header Checksum Errors Register */
  __I   uint32_t                       GMAC_TCE;           /**< Offset: 0x1AC (R/   32) TCP Checksum Errors Register */
  __I   uint32_t                       GMAC_UCE;           /**< Offset: 0x1B0 (R/   32) UDP Checksum Errors Register */
  __I   uint32_t                       GMAC_FLRXPCR;       /**< Offset: 0x1B4 (R/   32) Flushed Received Packets Counter Register */
  __I   uint8_t                        Reserved5[0x04];
  __IO  uint32_t                       GMAC_TISUBN;        /**< Offset: 0x1BC (R/W  32) 1588 Timer Increment Sub-nanoseconds Register */
  __IO  uint32_t                       GMAC_TSH;           /**< Offset: 0x1C0 (R/W  32) 1588 Timer Seconds High Register */
  __I   uint8_t                        Reserved6[0x0C];
  __IO  uint32_t                       GMAC_TSL;           /**< Offset: 0x1D0 (R/W  32) 1588 Timer Seconds Low Register */
  __IO  uint32_t                       GMAC_TN;            /**< Offset: 0x1D4 (R/W  32) 1588 Timer Nanoseconds Register */
  __O   uint32_t                       GMAC_TA;            /**< Offset: 0x1D8 ( /W  32) 1588 Timer Adjust Register */
  __IO  uint32_t                       GMAC_TI;            /**< Offset: 0x1DC (R/W  32) 1588 Timer Increment Register */
  __I   uint32_t                       GMAC_EFTSL;         /**< Offset: 0x1E0 (R/   32) PTP Event Frame Transmitted Seconds Low Register */
  __I   uint32_t                       GMAC_EFTN;          /**< Offset: 0x1E4 (R/   32) PTP Event Frame Transmitted Nanoseconds Register */
  __I   uint32_t                       GMAC_EFRSL;         /**< Offset: 0x1E8 (R/   32) PTP Event Frame Received Seconds Low Register */
  __I   uint32_t                       GMAC_EFRN;          /**< Offset: 0x1EC (R/   32) PTP Event Frame Received Nanoseconds Register */
  __I   uint32_t                       GMAC_PEFTSL;        /**< Offset: 0x1F0 (R/   32) PTP Peer Event Frame Transmitted Seconds Low Register */
  __I   uint32_t                       GMAC_PEFTN;         /**< Offset: 0x1F4 (R/   32) PTP Peer Event Frame Transmitted Nanoseconds Register */
  __I   uint32_t                       GMAC_PEFRSL;        /**< Offset: 0x1F8 (R/   32) PTP Peer Event Frame Received Seconds Low Register */
  __I   uint32_t                       GMAC_PEFRN;         /**< Offset: 0x1FC (R/   32) PTP Peer Event Frame Received Nanoseconds Register */
  __I   uint8_t                        Reserved7[0x70];
  __I   uint32_t                       GMAC_RXLPI;         /**< Offset: 0x270 (R/   32) Received LPI Transitions */
  __I   uint32_t                       GMAC_RXLPITIME;     /**< Offset: 0x274 (R/   32) Received LPI Time */
  __I   uint32_t                       GMAC_TXLPI;         /**< Offset: 0x278 (R/   32) Transmit LPI Transitions */
  __I   uint32_t                       GMAC_TXLPITIME;     /**< Offset: 0x27C (R/   32) Transmit LPI Time */
  __I   uint8_t                        Reserved8[0x180];
  __I   uint32_t                       GMAC_ISRPQ[5];      /**< Offset: 0x400 (R/   32) Interrupt Status Register Priority Queue (index = 1) */
  __I   uint8_t                        Reserved9[0x2C];
  __IO  uint32_t                       GMAC_TBQBAPQ[5];    /**< Offset: 0x440 (R/W  32) Transmit Buffer Queue Base Address Register Priority Queue (index = 1) */
  __I   uint8_t                        Reserved10[0x2C];
  __IO  uint32_t                       GMAC_RBQBAPQ[5];    /**< Offset: 0x480 (R/W  32) Receive Buffer Queue Base Address Register Priority Queue (index = 1) */
  __I   uint8_t                        Reserved11[0x0C];
  __IO  uint32_t                       GMAC_RBSRPQ[5];     /**< Offset: 0x4A0 (R/W  32) Receive Buffer Size Register Priority Queue (index = 1) */
  __I   uint8_t                        Reserved12[0x08];
  __IO  uint32_t                       GMAC_CBSCR;         /**< Offset: 0x4BC (R/W  32) Credit-Based Shaping Control Register */
  __IO  uint32_t                       GMAC_CBSISQA;       /**< Offset: 0x4C0 (R/W  32) Credit-Based Shaping IdleSlope Register for Queue A */
  __IO  uint32_t                       GMAC_CBSISQB;       /**< Offset: 0x4C4 (R/W  32) Credit-Based Shaping IdleSlope Register for Queue B */
  __IO  uint32_t                       GMAC_TQUBA;         /**< Offset: 0x4C8 (R/W  32) 32 MSB Transmit Buffer Descriptor Queue Base Address Register */
  __IO  uint32_t                       GMAC_TXBDCTRL;      /**< Offset: 0x4CC (R/W  32) Transmit Buffer Data Control Register */
  __IO  uint32_t                       GMAC_RXBDCTRL;      /**< Offset: 0x4D0 (R/W  32) Receive Buffer Data Control Register */
  __IO  uint32_t                       GMAC_RQUBA;         /**< Offset: 0x4D4 (R/W  32) 32 MSB Receive Buffer Descriptor Queue Base Address Register */
  __I   uint8_t                        Reserved13[0x28];
  __IO  uint32_t                       GMAC_ST1RPQ[4];     /**< Offset: 0x500 (R/W  32) Screening Type 1 Register Priority Queue (index = 0) */
  __I   uint8_t                        Reserved14[0x30];
  __IO  uint32_t                       GMAC_ST2RPQ[8];     /**< Offset: 0x540 (R/W  32) Screening Type 2 Register Priority Queue (index = 0) */
  __I   uint8_t                        Reserved15[0x20];
  __IO  uint32_t                       GMAC_TSCTL;         /**< Offset: 0x580 (R/W  32) Transmit Schedule Control Register */
  __I   uint8_t                        Reserved16[0x0C];
  __IO  uint32_t                       GMAC_TQBWRL0;       /**< Offset: 0x590 (R/W  32) Transmit Queue Bandwidth Rate Limit 0 Register */
  __I   uint8_t                        Reserved17[0x0C];
  __IO  uint32_t                       GMAC_TQSA;          /**< Offset: 0x5A0 (R/W  32) Transmit Queue Segment Allocation Register */
  __I   uint8_t                        Reserved18[0x5C];
  __O   uint32_t                       GMAC_IERPQ[5];      /**< Offset: 0x600 ( /W  32) Interrupt Enable Register Priority Queue (index = 1) */
  __I   uint8_t                        Reserved19[0x0C];
  __O   uint32_t                       GMAC_IDRPQ[5];      /**< Offset: 0x620 ( /W  32) Interrupt Disable Register Priority Queue (index = 1) */
  __I   uint8_t                        Reserved20[0x0C];
  __IO  uint32_t                       GMAC_IMRPQ[5];      /**< Offset: 0x640 (R/W  32) Interrupt Mask Register Priority Queue (index = 1) */
  __I   uint8_t                        Reserved21[0x8C];
  __IO  uint32_t                       GMAC_ST2ER[4];      /**< Offset: 0x6E0 (R/W  32) Screening Type 2 Ethertype Register (index = 0) */
  __I   uint8_t                        Reserved22[0x10];
        gmac_st2cw_registers_t         GMAC_ST2CW[GMAC_ST2CW_NUMBER]; /**< Offset: 0x700  */
  __I   uint8_t                        Reserved23[0x40];
  __IO  uint32_t                       GMAC_ENST_START_Q[6]; /**< Offset: 0x800 (R/W  32) ENST Start Time Queue Register (index = 0) */
  __I   uint8_t                        Reserved24[0x08];
  __IO  uint32_t                       GMAC_ENST_ON_Q[6];  /**< Offset: 0x820 (R/W  32) ENST On Time Queue Register (index = 0) */
  __I   uint8_t                        Reserved25[0x08];
  __IO  uint32_t                       GMAC_ENST_OFF_Q[6]; /**< Offset: 0x840 (R/W  32) ENST Off Time Queue Register (index = 0) */
  __I   uint8_t                        Reserved26[0x28];
  __IO  uint32_t                       GMAC_ENST_CR;       /**< Offset: 0x880 (R/W  32) ENST Control Register */
  __I   uint8_t                        Reserved27[0x1C];
  __IO  uint32_t                       GMAC_FRER_TIMEOUT;  /**< Offset: 0x8A0 (R/W  32) Frame Elimination Timeout Register */
  __IO  uint32_t                       GMAC_FRER_REDTAG;   /**< Offset: 0x8A4 (R/W  32) Frame Elimination Redundancy Tag Register */
  __I   uint8_t                        Reserved28[0x18];
        gmac_frer_registers_t          GMAC_FRER[GMAC_FRER_NUMBER]; /**< Offset: 0x8C0  */
  __I   uint8_t                        Reserved29[0x1E0];
  __IO  uint32_t                       GMAC_RX_FLUSH_Q[6]; /**< Offset: 0xB00 (R/W  32) Receive Queue Flush Register (index = 0) */
  __I   uint8_t                        Reserved30[0x28];
  __IO  uint32_t                       GMAC_SCR2_RATE_LIMIT[6]; /**< Offset: 0xB40 (R/W  32) Screening 2 Rate Limit Register (index = 0) */
  __I   uint8_t                        Reserved31[0x28];
  __I   uint32_t                       GMAC_SCR2_RATE_STATUS; /**< Offset: 0xB80 (R/   32) Screening 2 Rate Status Register */
  __I   uint8_t                        Reserved32[0x37C];
  __IO  uint32_t                       GMAC_MMSL_CR;       /**< Offset: 0xF00 (R/W  32) MMSL Control Register */
  __I   uint32_t                       GMAC_MMSL_SR;       /**< Offset: 0xF04 (R/   32) MMSL Status Register */
  __I   uint32_t                       GMAC_MMSL_ESR;      /**< Offset: 0xF08 (R/   32) MMSL Error Statistics Register */
  __I   uint32_t                       GMAC_MMSL_ASS_OK;   /**< Offset: 0xF0C (R/   32) MMSL Frame Re-Assembled OK Register */
  __I   uint32_t                       GMAC_MMSL_RXFRAG_CNT; /**< Offset: 0xF10 (R/   32) MMSL Received Fragment Counter Register */
  __I   uint32_t                       GMAC_MMSL_TXFRAG_CNT; /**< Offset: 0xF14 (R/   32) MMSL Transmitted Fragment Counter Register */
  __IO  uint32_t                       GMAC_MMSL_ISR;      /**< Offset: 0xF18 (R/W  32) MMSL Interrupt Status Register */
  __IO  uint32_t                       GMAC_MMSL_IER;      /**< Offset: 0xF1C (R/W  32) MMSL Interrupt Enable Register */
  __IO  uint32_t                       GMAC_MMSL_IDR;      /**< Offset: 0xF20 (R/W  32) MMSL Interrupt Disable Register */
  __I   uint32_t                       GMAC_MMSL_IMR;      /**< Offset: 0xF24 (R/   32) MMSL Interrupt Mask Register */
  __I   uint8_t                        Reserved33[0xD8];
  __IO  uint32_t                       GMAC_EMAC_NCR;      /**< Offset: 0x1000 (R/W  32) Express MAC Network Control Register */
  __IO  uint32_t                       GMAC_EMAC_NCFGR;    /**< Offset: 0x1004 (R/W  32) Express MAC Network Configuration Register */
  __I   uint32_t                       GMAC_EMAC_NSR;      /**< Offset: 0x1008 (R/   32) Express MAC Network Status Register */
  __I   uint8_t                        Reserved34[0x04];
  __IO  uint32_t                       GMAC_EMAC_DCFGR;    /**< Offset: 0x1010 (R/W  32) Express MAC DMA Configuration Register */
  __IO  uint32_t                       GMAC_EMAC_TSR;      /**< Offset: 0x1014 (R/W  32) Express MAC Transmit Status Register */
  __IO  uint32_t                       GMAC_EMAC_RBQB;     /**< Offset: 0x1018 (R/W  32) Express MAC Receive Buffer Queue Base Address Register */
  __IO  uint32_t                       GMAC_EMAC_TBQB;     /**< Offset: 0x101C (R/W  32) Express MAC Transmit Buffer Queue Base Address Register */
  __IO  uint32_t                       GMAC_EMAC_RSR;      /**< Offset: 0x1020 (R/W  32) Express MAC Receive Status Register */
  __I   uint32_t                       GMAC_EMAC_ISR;      /**< Offset: 0x1024 (R/   32) Express MAC Interrupt Status Register */
  __O   uint32_t                       GMAC_EMAC_IER;      /**< Offset: 0x1028 ( /W  32) Express MAC Interrupt Enable Register */
  __O   uint32_t                       GMAC_EMAC_IDR;      /**< Offset: 0x102C ( /W  32) Express MAC Interrupt Disable Register */
  __IO  uint32_t                       GMAC_EMAC_IMR;      /**< Offset: 0x1030 (R/W  32) Express MAC Interrupt Mask Register */
  __I   uint8_t                        Reserved35[0x04];
  __I   uint32_t                       GMAC_EMAC_RPQ;      /**< Offset: 0x1038 (R/   32) Express MAC Receive Pause Quantum Register */
  __IO  uint32_t                       GMAC_EMAC_TPQ;      /**< Offset: 0x103C (R/W  32) Express MAC Transmit Pause Quantum Register */
  __IO  uint32_t                       GMAC_EMAC_TPSF;     /**< Offset: 0x1040 (R/W  32) Express MAC TX Partial Store and Forward Register */
  __IO  uint32_t                       GMAC_EMAC_RPSF;     /**< Offset: 0x1044 (R/W  32) Express MAC RX Partial Store and Forward Register */
  __IO  uint32_t                       GMAC_EMAC_RJFML;    /**< Offset: 0x1048 (R/W  32) Express MAC RX Jumbo Frame Max Length Register */
  __I   uint8_t                        Reserved36[0x08];
  __IO  uint32_t                       GMAC_EMAC_AMP;      /**< Offset: 0x1054 (R/W  32) Express MAC System Bus Maximum Pipeline */
  __I   uint8_t                        Reserved37[0x04];
  __IO  uint32_t                       GMAC_EMAC_INTM;     /**< Offset: 0x105C (R/W  32) Express MAC Interrupt Moderation Register */
  __IO  uint32_t                       GMAC_EMAC_SYSWT;    /**< Offset: 0x1060 (R/W  32) Express MAC System Wake-Up Time Register */
  __I   uint8_t                        Reserved38[0x04];
  __IO  uint32_t                       GMAC_EMAC_LCKUP_CFGR; /**< Offset: 0x1068 (R/W  32) Express MAC Lockup Detection and Recovery Configuration */
  __IO  uint32_t                       GMAC_EMAC_LCKUP_TIME; /**< Offset: 0x106C (R/W  32) Express MAC Lockup Detection Time */
  __IO  uint32_t                       GMAC_EMAC_TXDMA_LCKUP_CR; /**< Offset: 0x1070 (R/W  32) Express MAC Transmit DMA Lockup Control Register */
  __I   uint8_t                        Reserved39[0x08];
  __IO  uint32_t                       GMAC_EMAC_RX_WATERMARK; /**< Offset: 0x107C (R/W  32) Express MAC Receive Watermark Register */
  __IO  uint32_t                       GMAC_EMAC_HRB;      /**< Offset: 0x1080 (R/W  32) Express MAC Hash Register Bottom */
  __IO  uint32_t                       GMAC_EMAC_HRT;      /**< Offset: 0x1084 (R/W  32) Express MAC Hash Register Top */
        gmac_emac_sa_registers_t       GMAC_EMAC_SA[GMAC_EMAC_SA_NUMBER]; /**< Offset: 0x1088  */
  __IO  uint32_t                       GMAC_EMAC_TIDM1;    /**< Offset: 0x10A8 (R/W  32) Express MAC Type ID Match 1 Register */
  __IO  uint32_t                       GMAC_EMAC_TIDM2;    /**< Offset: 0x10AC (R/W  32) Express MAC Type ID Match 2 Register */
  __IO  uint32_t                       GMAC_EMAC_TIDM3;    /**< Offset: 0x10B0 (R/W  32) Express MAC Type ID Match 3 Register */
  __IO  uint32_t                       GMAC_EMAC_TIDM4;    /**< Offset: 0x10B4 (R/W  32) Express MAC Type ID Match 4 Register */
  __IO  uint32_t                       GMAC_EMAC_WOL;      /**< Offset: 0x10B8 (R/W  32) Express MAC Wake on LAN Register */
  __IO  uint32_t                       GMAC_EMAC_IPGS;     /**< Offset: 0x10BC (R/W  32) Express MAC IPG Stretch Register */
  __IO  uint32_t                       GMAC_EMAC_SVLAN;    /**< Offset: 0x10C0 (R/W  32) Express MAC Stacked VLAN Register */
  __IO  uint32_t                       GMAC_EMAC_TPFCP;    /**< Offset: 0x10C4 (R/W  32) Express MAC Transmit PFC Pause Register */
  __IO  uint32_t                       GMAC_EMAC_SAMB1;    /**< Offset: 0x10C8 (R/W  32) Express MAC Specific Address 1 Mask Bottom Register */
  __IO  uint32_t                       GMAC_EMAC_SAMT1;    /**< Offset: 0x10CC (R/W  32) Express MAC Specific Address 1 Mask Top Register */
  __IO  uint32_t                       GMAC_EMAC_AMRX;     /**< Offset: 0x10D0 (R/W  32) System Memory Address Mask for RX Data Buffer Accesses Register */
  __IO  uint32_t                       GMAC_EMAC_RXUDAR;   /**< Offset: 0x10D4 (R/W  32) Express MAC PTP RX Unicast IP Destination Address Register */
  __IO  uint32_t                       GMAC_EMAC_TXUDAR;   /**< Offset: 0x10D8 (R/W  32) Express MAC PTP TX Unicast IP Destination Address Register */
  __IO  uint32_t                       GMAC_EMAC_NSC;      /**< Offset: 0x10DC (R/W  32) Express MAC 1588 Timer Nanosecond Comparison Register */
  __IO  uint32_t                       GMAC_EMAC_SCL;      /**< Offset: 0x10E0 (R/W  32) Express MAC 1588 Timer Second Comparison Low Register */
  __IO  uint32_t                       GMAC_EMAC_SCH;      /**< Offset: 0x10E4 (R/W  32) Express MAC 1588 Timer Second Comparison High Register */
  __I   uint32_t                       GMAC_EMAC_EFTSH;    /**< Offset: 0x10E8 (R/   32) Express MAC PTP Event Frame Transmitted Seconds High Register */
  __I   uint32_t                       GMAC_EMAC_EFRSH;    /**< Offset: 0x10EC (R/   32) Express MAC PTP Event Frame Received Seconds High Register */
  __I   uint32_t                       GMAC_EMAC_PEFTSH;   /**< Offset: 0x10F0 (R/   32) Express MAC PTP Peer Event Frame Transmitted Seconds High Register */
  __I   uint32_t                       GMAC_EMAC_PEFRSH;   /**< Offset: 0x10F4 (R/   32) Express MAC PTP Peer Event Frame Received Seconds High Register */
  __I   uint8_t                        Reserved40[0x08];
  __I   uint32_t                       GMAC_EMAC_OTLO;     /**< Offset: 0x1100 (R/   32) Express MAC Octets Transmitted Low Register */
  __I   uint32_t                       GMAC_EMAC_OTHI;     /**< Offset: 0x1104 (R/   32) Express MAC Octets Transmitted High Register */
  __I   uint32_t                       GMAC_EMAC_FT;       /**< Offset: 0x1108 (R/   32) Express MAC Frames Transmitted Register */
  __I   uint32_t                       GMAC_EMAC_BCFT;     /**< Offset: 0x110C (R/   32) Express MAC Broadcast Frames Transmitted Register */
  __I   uint32_t                       GMAC_EMAC_MFT;      /**< Offset: 0x1110 (R/   32) Express MAC Multicast Frames Transmitted Register */
  __I   uint32_t                       GMAC_EMAC_PFT;      /**< Offset: 0x1114 (R/   32) Express MAC Pause Frames Transmitted Register */
  __I   uint32_t                       GMAC_EMAC_BFT64;    /**< Offset: 0x1118 (R/   32) Express MAC 64 Byte Frames Transmitted Register */
  __I   uint32_t                       GMAC_EMAC_TBFT127;  /**< Offset: 0x111C (R/   32) Express MAC 65 to 127 Byte Frames Transmitted Register */
  __I   uint32_t                       GMAC_EMAC_TBFT255;  /**< Offset: 0x1120 (R/   32) Express MAC 128 to 255 Byte Frames Transmitted Register */
  __I   uint32_t                       GMAC_EMAC_TBFT511;  /**< Offset: 0x1124 (R/   32) Express MAC 256 to 511 Byte Frames Transmitted Register */
  __I   uint32_t                       GMAC_EMAC_TBFT1023; /**< Offset: 0x1128 (R/   32) Express MAC 512 to 1023 Byte Frames Transmitted Register */
  __I   uint32_t                       GMAC_EMAC_TBFT1518; /**< Offset: 0x112C (R/   32) Express MAC 1024 to 1518 Byte Frames Transmitted Register */
  __I   uint32_t                       GMAC_EMAC_GTBFT1518; /**< Offset: 0x1130 (R/   32) Express MAC Greater Than 1518 Byte Frames Transmitted Register */
  __I   uint32_t                       GMAC_EMAC_TUR;      /**< Offset: 0x1134 (R/   32) Express MAC Transmit Underruns Register */
  __I   uint32_t                       GMAC_EMAC_SCF;      /**< Offset: 0x1138 (R/   32) Express MAC Single Collision Frames Register */
  __I   uint32_t                       GMAC_EMAC_MCF;      /**< Offset: 0x113C (R/   32) Express MAC Multiple Collision Frames Register */
  __I   uint32_t                       GMAC_EMAC_EC;       /**< Offset: 0x1140 (R/   32) Express MAC Excessive Collisions Register */
  __I   uint32_t                       GMAC_EMAC_LC;       /**< Offset: 0x1144 (R/   32) Express MAC Late Collisions Register */
  __I   uint32_t                       GMAC_EMAC_DTF;      /**< Offset: 0x1148 (R/   32) Express MAC Deferred Transmission Frames Register */
  __I   uint32_t                       GMAC_EMAC_CSE;      /**< Offset: 0x114C (R/   32) Express MAC Carrier Sense Errors Register */
  __I   uint32_t                       GMAC_EMAC_ORLO;     /**< Offset: 0x1150 (R/   32) Express MAC Octets Received Low Received Register */
  __I   uint32_t                       GMAC_EMAC_ORHI;     /**< Offset: 0x1154 (R/   32) Express MAC Octets Received High Received Register */
  __I   uint32_t                       GMAC_EMAC_FR;       /**< Offset: 0x1158 (R/   32) Express MAC Frames Received Register */
  __I   uint32_t                       GMAC_EMAC_BCFR;     /**< Offset: 0x115C (R/   32) Express MAC Broadcast Frames Received Register */
  __I   uint32_t                       GMAC_EMAC_MFR;      /**< Offset: 0x1160 (R/   32) Express MAC Multicast Frames Received Register */
  __I   uint32_t                       GMAC_EMAC_PFR;      /**< Offset: 0x1164 (R/   32) Express MAC Pause Frames Received Register */
  __I   uint32_t                       GMAC_EMAC_BFR64;    /**< Offset: 0x1168 (R/   32) Express MAC 64 Byte Frames Received Register */
  __I   uint32_t                       GMAC_EMAC_TBFR127;  /**< Offset: 0x116C (R/   32) Express MAC 65 to 127 Byte Frames Received Register */
  __I   uint32_t                       GMAC_EMAC_TBFR255;  /**< Offset: 0x1170 (R/   32) Express MAC 128 to 255 Byte Frames Received Register */
  __I   uint32_t                       GMAC_EMAC_TBFR511;  /**< Offset: 0x1174 (R/   32) Express MAC 256 to 511 Byte Frames Received Register */
  __I   uint32_t                       GMAC_EMAC_TBFR1023; /**< Offset: 0x1178 (R/   32) Express MAC 512 to 1023 Byte Frames Received Register */
  __I   uint32_t                       GMAC_EMAC_TBFR1518; /**< Offset: 0x117C (R/   32) Express MAC 1024 to 1518 Byte Frames Received Register */
  __I   uint32_t                       GMAC_EMAC_TMXBFR;   /**< Offset: 0x1180 (R/   32) Express MAC 1519 to Maximum Byte Frames Received Register */
  __I   uint32_t                       GMAC_EMAC_UFR;      /**< Offset: 0x1184 (R/   32) Express MAC Undersize Frames Received Register */
  __I   uint32_t                       GMAC_EMAC_OFR;      /**< Offset: 0x1188 (R/   32) Express MAC Oversize Frames Received Register */
  __I   uint32_t                       GMAC_EMAC_JR;       /**< Offset: 0x118C (R/   32) Express MAC Jabbers Received Register */
  __I   uint32_t                       GMAC_EMAC_FCSE;     /**< Offset: 0x1190 (R/   32) Express MAC Frame Check Sequence Errors Register */
  __I   uint32_t                       GMAC_EMAC_LFFE;     /**< Offset: 0x1194 (R/   32) Express MAC Length Field Frame Errors Register */
  __I   uint32_t                       GMAC_EMAC_RSE;      /**< Offset: 0x1198 (R/   32) Express MAC Receive Symbol Errors Register */
  __I   uint32_t                       GMAC_EMAC_AE;       /**< Offset: 0x119C (R/   32) Express MAC Alignment Errors Register */
  __I   uint32_t                       GMAC_EMAC_RRE;      /**< Offset: 0x11A0 (R/   32) Express MAC Receive Resource Errors Register */
  __I   uint32_t                       GMAC_EMAC_ROE;      /**< Offset: 0x11A4 (R/   32) Express MAC Receive Overrun Register */
  __I   uint32_t                       GMAC_EMAC_IHCE;     /**< Offset: 0x11A8 (R/   32) Express MAC IP Header Checksum Errors Register */
  __I   uint32_t                       GMAC_EMAC_TCE;      /**< Offset: 0x11AC (R/   32) Express MAC TCP Checksum Errors Register */
  __I   uint32_t                       GMAC_EMAC_UCE;      /**< Offset: 0x11B0 (R/   32) Express MAC UDP Checksum Errors Register */
  __I   uint32_t                       GMAC_EMAC_FLRXPCR;  /**< Offset: 0x11B4 (R/   32) Express MAC Flushed Received Packets Counter Register */
  __I   uint8_t                        Reserved41[0x04];
  __IO  uint32_t                       GMAC_EMAC_TISUBN;   /**< Offset: 0x11BC (R/W  32) Express MAC 1588 Timer Increment Sub-nanoseconds Register */
  __IO  uint32_t                       GMAC_EMAC_TSH;      /**< Offset: 0x11C0 (R/W  32) Express MAC1588 Timer Seconds High Register */
  __I   uint8_t                        Reserved42[0x0C];
  __IO  uint32_t                       GMAC_EMAC_TSL;      /**< Offset: 0x11D0 (R/W  32) Express MAC1588 Timer Seconds Low Register */
  __IO  uint32_t                       GMAC_EMAC_TN;       /**< Offset: 0x11D4 (R/W  32) Express MAC1588 Timer Nanoseconds Register */
  __O   uint32_t                       GMAC_EMAC_TA;       /**< Offset: 0x11D8 ( /W  32) Express MAC1588 Timer Adjust Register */
  __IO  uint32_t                       GMAC_EMAC_TI;       /**< Offset: 0x11DC (R/W  32) Express MAC1588 Timer Increment Register */
  __I   uint32_t                       GMAC_EMAC_EFTSL;    /**< Offset: 0x11E0 (R/   32) Express MAC PTP Event Frame Transmitted Seconds Low Register */
  __I   uint32_t                       GMAC_EMAC_EFTN;     /**< Offset: 0x11E4 (R/   32) Express MAC PTP Event Frame Transmitted Nanoseconds Register */
  __I   uint32_t                       GMAC_EMAC_EFRSL;    /**< Offset: 0x11E8 (R/   32) Express MAC PTP Event Frame Received Seconds Low Register */
  __I   uint32_t                       GMAC_EMAC_EFRN;     /**< Offset: 0x11EC (R/   32) Express MAC PTP Event Frame Received Nanoseconds Register */
  __I   uint32_t                       GMAC_EMAC_PEFTSL;   /**< Offset: 0x11F0 (R/   32) Express MAC PTP Peer Event Frame Transmitted Seconds Low Register */
  __I   uint32_t                       GMAC_EMAC_PEFTN;    /**< Offset: 0x11F4 (R/   32) Express MAC PTP Peer Event Frame Transmitted Nanoseconds Register */
  __I   uint32_t                       GMAC_EMAC_PEFRSL;   /**< Offset: 0x11F8 (R/   32) Express MAC PTP Peer Event Frame Received Seconds Low Register */
  __I   uint32_t                       GMAC_EMAC_PEFRN;    /**< Offset: 0x11FC (R/   32) Express MAC PTP Peer Event Frame Received Nanoseconds Register */
  __I   uint8_t                        Reserved43[0x60];
  __IO  uint32_t                       GMAC_EMAC_TXPQUANT1; /**< Offset: 0x1260 (R/W  32) Express MAC Transmit Pause Quantum 1 Register */
  __IO  uint32_t                       GMAC_EMAC_TXPQUANT2; /**< Offset: 0x1264 (R/W  32) Express MAC Transmit Pause Quantum 2 Register */
  __IO  uint32_t                       GMAC_EMAC_TXPQUANT3; /**< Offset: 0x1268 (R/W  32) Express MAC Transmit Pause Quantum 3 Register */
  __I   uint8_t                        Reserved44[0x04];
  __I   uint32_t                       GMAC_EMAC_RXLPI;    /**< Offset: 0x1270 (R/   32) Express MAC Received LPI Transitions */
  __I   uint32_t                       GMAC_EMAC_RXLPITIME; /**< Offset: 0x1274 (R/   32) Express MAC Received LPI Time */
  __I   uint32_t                       GMAC_EMAC_TXLPI;    /**< Offset: 0x1278 (R/   32) Express MAC Transmit LPI Transitions */
  __I   uint32_t                       GMAC_EMAC_TXLPITIME; /**< Offset: 0x127C (R/   32) Express MAC Transmit LPI Time */
  __I   uint8_t                        Reserved45[0x60];
  __IO  uint32_t                       GMAC_EMAC_QOS_CFG;  /**< Offset: 0x12E0 (R/W  32) Express MAC System Bus QoS Configuration Register */
  __I   uint8_t                        Reserved46[0x1C];
        gmac_emac_asa_registers_t      GMAC_EMAC_ASA[GMAC_EMAC_ASA_NUMBER]; /**< Offset: 0x1300  */
  __I   uint8_t                        Reserved47[0xBC];
  __IO  uint32_t                       GMAC_EMAC_CBSCR;    /**< Offset: 0x14BC (R/W  32) Express MAC Credit-Based Shaping Control Register */
  __IO  uint32_t                       GMAC_EMAC_CBSISQA;  /**< Offset: 0x14C0 (R/W  32) Express MAC Credit-Based Shaping IdleSlope Register for Queue A */
  __IO  uint32_t                       GMAC_EMAC_CBSISQB;  /**< Offset: 0x14C4 (R/W  32) Express MAC Credit-Based Shaping IdleSlope Register for Queue B */
  __IO  uint32_t                       GMAC_EMAC_TQUBA;    /**< Offset: 0x14C8 (R/W  32) Express MAC 32 MSB Transmit Buffer Descriptor Queue Base Address Register */
  __IO  uint32_t                       GMAC_EMAC_TXBDCTRL; /**< Offset: 0x14CC (R/W  32) Express MAC Transmit Buffer Data Control Register */
  __IO  uint32_t                       GMAC_EMAC_RXBDCTRL; /**< Offset: 0x14D0 (R/W  32) Express MAC Receive Buffer Data Control Register */
  __IO  uint32_t                       GMAC_EMAC_RQUBA;    /**< Offset: 0x14D4 (R/W  32) Express MAC 32 MSB Receive Buffer Descriptor Queue Base Address Register */
  __I   uint8_t                        Reserved48[0x28];
  __IO  uint32_t                       GMAC_EMAC_ST1R;     /**< Offset: 0x1500 (R/W  32) Express MAC Screening Type 1 Register */
  __I   uint8_t                        Reserved49[0x3C];
  __IO  uint32_t                       GMAC_EMAC_ST2R[2];  /**< Offset: 0x1540 (R/W  32) Express MAC Screening Type 2 Register (index = 0) */
  __I   uint8_t                        Reserved50[0x38];
  __IO  uint32_t                       GMAC_EMAC_TSCTL;    /**< Offset: 0x1580 (R/W  32) Express MACTransmit Schedule Control Register */
  __I   uint8_t                        Reserved51[0x0C];
  __IO  uint32_t                       GMAC_EMAC_TQBWRL0;  /**< Offset: 0x1590 (R/W  32) Express MAC Transmit Queue Bandwidth Rate Limit 0 Register */
  __I   uint8_t                        Reserved52[0x0C];
  __IO  uint32_t                       GMAC_EMAC_TQSA;     /**< Offset: 0x15A0 (R/W  32) Express MAC Transmit Queue Segment Allocation Register */
  __I   uint8_t                        Reserved53[0x15C];
        gmac_emac_st2cw_registers_t    GMAC_EMAC_ST2CW[GMAC_EMAC_ST2CW_NUMBER]; /**< Offset: 0x1700  */
  __I   uint8_t                        Reserved54[0xD0];
  __IO  uint32_t                       GMAC_EMAC_ENST_START_Q[6]; /**< Offset: 0x1800 (R/W  32) Express MAC ENST Start Time Queue Register (index = 0) */
  __I   uint8_t                        Reserved55[0x08];
  __IO  uint32_t                       GMAC_EMAC_ENST_ON_Q[6]; /**< Offset: 0x1820 (R/W  32) Express MAC ENST On Time Queue Register (index = 0) */
  __I   uint8_t                        Reserved56[0x08];
  __IO  uint32_t                       GMAC_EMAC_ENST_OFF_Q[6]; /**< Offset: 0x1840 (R/W  32) Express MAC ENST Off Time Queue Register (index = 0) */
  __I   uint8_t                        Reserved57[0x28];
  __IO  uint32_t                       GMAC_EMAC_ENST_CR;  /**< Offset: 0x1880 (R/W  32) Express MAC ENST Control Register */
  __I   uint8_t                        Reserved58[0x1C];
  __IO  uint32_t                       GMAC_EMAC_FRER_TIMEOUT; /**< Offset: 0x18A0 (R/W  32) Express MAC Frame Elimination Timeout Register */
  __IO  uint32_t                       GMAC_EMAC_FRER_REDTAG; /**< Offset: 0x18A4 (R/W  32) Express MAC Frame Elimination Redundancy Tag Register */
  __I   uint8_t                        Reserved59[0x18];
        gmac_emac_frer_registers_t     GMAC_EMAC_FRER[GMAC_EMAC_FRER_NUMBER]; /**< Offset: 0x18C0  */
  __I   uint8_t                        Reserved60[0x220];
  __IO  uint32_t                       GMAC_EMAC_RX_FLUSH_Q; /**< Offset: 0x1B00 (R/W  32) Express MAC Receive Queue Flush Register */
  __I   uint8_t                        Reserved61[0x3C];
  __IO  uint32_t                       GMAC_EMAC_SCR2_RATE_LIMIT; /**< Offset: 0x1B40 (R/W  32) Express MAC Screening 2 Rate Limit Register */
  __I   uint8_t                        Reserved62[0x3C];
  __I   uint32_t                       GMAC_EMAC_SCR2_RATE_STATUS; /**< Offset: 0x1B80 (R/   32) Express MAC Screening 2 Rate Status Register */
} gmac_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAM9X7_GMAC_COMPONENT_H_ */
