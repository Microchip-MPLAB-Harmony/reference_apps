/*
 * Component description for I2SMCC
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

/* file generated from device description version 2022-01-05T08:53:32Z */
#ifndef _SAM9X_I2SMCC_COMPONENT_H_
#define _SAM9X_I2SMCC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR I2SMCC                                       */
/* ************************************************************************** */

/* -------- I2SMCC_CR : (I2SMCC Offset: 0x00) ( /W 32) Control Register -------- */
#define I2SMCC_CR_RXEN_Pos                    _UINT32_(0)                                          /* (I2SMCC_CR) Receiver Enable Position */
#define I2SMCC_CR_RXEN_Msk                    (_UINT32_(0x1) << I2SMCC_CR_RXEN_Pos)                /* (I2SMCC_CR) Receiver Enable Mask */
#define I2SMCC_CR_RXEN(value)                 (I2SMCC_CR_RXEN_Msk & (_UINT32_(value) << I2SMCC_CR_RXEN_Pos)) /* Assigment of value for RXEN in the I2SMCC_CR register */
#define I2SMCC_CR_RXDIS_Pos                   _UINT32_(1)                                          /* (I2SMCC_CR) Receiver Disable Position */
#define I2SMCC_CR_RXDIS_Msk                   (_UINT32_(0x1) << I2SMCC_CR_RXDIS_Pos)               /* (I2SMCC_CR) Receiver Disable Mask */
#define I2SMCC_CR_RXDIS(value)                (I2SMCC_CR_RXDIS_Msk & (_UINT32_(value) << I2SMCC_CR_RXDIS_Pos)) /* Assigment of value for RXDIS in the I2SMCC_CR register */
#define I2SMCC_CR_CKEN_Pos                    _UINT32_(2)                                          /* (I2SMCC_CR) Clocks Enable Position */
#define I2SMCC_CR_CKEN_Msk                    (_UINT32_(0x1) << I2SMCC_CR_CKEN_Pos)                /* (I2SMCC_CR) Clocks Enable Mask */
#define I2SMCC_CR_CKEN(value)                 (I2SMCC_CR_CKEN_Msk & (_UINT32_(value) << I2SMCC_CR_CKEN_Pos)) /* Assigment of value for CKEN in the I2SMCC_CR register */
#define I2SMCC_CR_CKDIS_Pos                   _UINT32_(3)                                          /* (I2SMCC_CR) Clocks Disable Position */
#define I2SMCC_CR_CKDIS_Msk                   (_UINT32_(0x1) << I2SMCC_CR_CKDIS_Pos)               /* (I2SMCC_CR) Clocks Disable Mask */
#define I2SMCC_CR_CKDIS(value)                (I2SMCC_CR_CKDIS_Msk & (_UINT32_(value) << I2SMCC_CR_CKDIS_Pos)) /* Assigment of value for CKDIS in the I2SMCC_CR register */
#define I2SMCC_CR_TXEN_Pos                    _UINT32_(4)                                          /* (I2SMCC_CR) Transmitter Enable Position */
#define I2SMCC_CR_TXEN_Msk                    (_UINT32_(0x1) << I2SMCC_CR_TXEN_Pos)                /* (I2SMCC_CR) Transmitter Enable Mask */
#define I2SMCC_CR_TXEN(value)                 (I2SMCC_CR_TXEN_Msk & (_UINT32_(value) << I2SMCC_CR_TXEN_Pos)) /* Assigment of value for TXEN in the I2SMCC_CR register */
#define I2SMCC_CR_TXDIS_Pos                   _UINT32_(5)                                          /* (I2SMCC_CR) Transmitter Disable Position */
#define I2SMCC_CR_TXDIS_Msk                   (_UINT32_(0x1) << I2SMCC_CR_TXDIS_Pos)               /* (I2SMCC_CR) Transmitter Disable Mask */
#define I2SMCC_CR_TXDIS(value)                (I2SMCC_CR_TXDIS_Msk & (_UINT32_(value) << I2SMCC_CR_TXDIS_Pos)) /* Assigment of value for TXDIS in the I2SMCC_CR register */
#define I2SMCC_CR_SWRST_Pos                   _UINT32_(7)                                          /* (I2SMCC_CR) Software Reset Position */
#define I2SMCC_CR_SWRST_Msk                   (_UINT32_(0x1) << I2SMCC_CR_SWRST_Pos)               /* (I2SMCC_CR) Software Reset Mask */
#define I2SMCC_CR_SWRST(value)                (I2SMCC_CR_SWRST_Msk & (_UINT32_(value) << I2SMCC_CR_SWRST_Pos)) /* Assigment of value for SWRST in the I2SMCC_CR register */
#define I2SMCC_CR_Msk                         _UINT32_(0x000000BF)                                 /* (I2SMCC_CR) Register Mask  */


/* -------- I2SMCC_MRA : (I2SMCC Offset: 0x04) (R/W 32) Mode Register A -------- */
#define I2SMCC_MRA_MODE_Pos                   _UINT32_(0)                                          /* (I2SMCC_MRA) Inter-IC Sound Multi Channel Controller Mode Position */
#define I2SMCC_MRA_MODE_Msk                   (_UINT32_(0x1) << I2SMCC_MRA_MODE_Pos)               /* (I2SMCC_MRA) Inter-IC Sound Multi Channel Controller Mode Mask */
#define I2SMCC_MRA_MODE(value)                (I2SMCC_MRA_MODE_Msk & (_UINT32_(value) << I2SMCC_MRA_MODE_Pos)) /* Assigment of value for MODE in the I2SMCC_MRA register */
#define   I2SMCC_MRA_MODE_SLAVE_Val           _UINT32_(0x0)                                        /* (I2SMCC_MRA) I2SMCC_CK and I2SMCC_WS pin inputs used as bit clock and word select/frame synchronization.  */
#define   I2SMCC_MRA_MODE_MASTER_Val          _UINT32_(0x1)                                        /* (I2SMCC_MRA) Bit clock and word select/frame synchronization generated by I2SMCC from MCK and output to I2SMCC_CK and I2SMCC_WS pins. MCK is output as master clock on I2SMCC_MCK if I2SMCC_MRA.IMCKMODE is set.  */
#define I2SMCC_MRA_MODE_SLAVE                 (I2SMCC_MRA_MODE_SLAVE_Val << I2SMCC_MRA_MODE_Pos)   /* (I2SMCC_MRA) I2SMCC_CK and I2SMCC_WS pin inputs used as bit clock and word select/frame synchronization. Position  */
#define I2SMCC_MRA_MODE_MASTER                (I2SMCC_MRA_MODE_MASTER_Val << I2SMCC_MRA_MODE_Pos)  /* (I2SMCC_MRA) Bit clock and word select/frame synchronization generated by I2SMCC from MCK and output to I2SMCC_CK and I2SMCC_WS pins. MCK is output as master clock on I2SMCC_MCK if I2SMCC_MRA.IMCKMODE is set. Position  */
#define I2SMCC_MRA_DATALENGTH_Pos             _UINT32_(1)                                          /* (I2SMCC_MRA) Data Word Length Position */
#define I2SMCC_MRA_DATALENGTH_Msk             (_UINT32_(0x7) << I2SMCC_MRA_DATALENGTH_Pos)         /* (I2SMCC_MRA) Data Word Length Mask */
#define I2SMCC_MRA_DATALENGTH(value)          (I2SMCC_MRA_DATALENGTH_Msk & (_UINT32_(value) << I2SMCC_MRA_DATALENGTH_Pos)) /* Assigment of value for DATALENGTH in the I2SMCC_MRA register */
#define   I2SMCC_MRA_DATALENGTH_32_BITS_Val   _UINT32_(0x0)                                        /* (I2SMCC_MRA) Data length is set to 32 bits.  */
#define   I2SMCC_MRA_DATALENGTH_24_BITS_Val   _UINT32_(0x1)                                        /* (I2SMCC_MRA) Data length is set to 24 bits.  */
#define   I2SMCC_MRA_DATALENGTH_20_BITS_Val   _UINT32_(0x2)                                        /* (I2SMCC_MRA) Data length is set to 20 bits.  */
#define   I2SMCC_MRA_DATALENGTH_18_BITS_Val   _UINT32_(0x3)                                        /* (I2SMCC_MRA) Data length is set to 18 bits.  */
#define   I2SMCC_MRA_DATALENGTH_16_BITS_Val   _UINT32_(0x4)                                        /* (I2SMCC_MRA) Data length is set to 16 bits.  */
#define   I2SMCC_MRA_DATALENGTH_16_BITS_COMPACT_Val _UINT32_(0x5)                                        /* (I2SMCC_MRA) Data length is set to 16-bit compact stereo. Left sample in bits [15:0] and right sample in bits [31:16] of same word.  */
#define   I2SMCC_MRA_DATALENGTH_8_BITS_Val    _UINT32_(0x6)                                        /* (I2SMCC_MRA) Data length is set to 8 bits.  */
#define   I2SMCC_MRA_DATALENGTH_8_BITS_COMPACT_Val _UINT32_(0x7)                                        /* (I2SMCC_MRA) Data length is set to 8-bit compact stereo. Left sample in bits [7:0] and right sample in bits [15:8] of the same word.  */
#define I2SMCC_MRA_DATALENGTH_32_BITS         (I2SMCC_MRA_DATALENGTH_32_BITS_Val << I2SMCC_MRA_DATALENGTH_Pos) /* (I2SMCC_MRA) Data length is set to 32 bits. Position  */
#define I2SMCC_MRA_DATALENGTH_24_BITS         (I2SMCC_MRA_DATALENGTH_24_BITS_Val << I2SMCC_MRA_DATALENGTH_Pos) /* (I2SMCC_MRA) Data length is set to 24 bits. Position  */
#define I2SMCC_MRA_DATALENGTH_20_BITS         (I2SMCC_MRA_DATALENGTH_20_BITS_Val << I2SMCC_MRA_DATALENGTH_Pos) /* (I2SMCC_MRA) Data length is set to 20 bits. Position  */
#define I2SMCC_MRA_DATALENGTH_18_BITS         (I2SMCC_MRA_DATALENGTH_18_BITS_Val << I2SMCC_MRA_DATALENGTH_Pos) /* (I2SMCC_MRA) Data length is set to 18 bits. Position  */
#define I2SMCC_MRA_DATALENGTH_16_BITS         (I2SMCC_MRA_DATALENGTH_16_BITS_Val << I2SMCC_MRA_DATALENGTH_Pos) /* (I2SMCC_MRA) Data length is set to 16 bits. Position  */
#define I2SMCC_MRA_DATALENGTH_16_BITS_COMPACT (I2SMCC_MRA_DATALENGTH_16_BITS_COMPACT_Val << I2SMCC_MRA_DATALENGTH_Pos) /* (I2SMCC_MRA) Data length is set to 16-bit compact stereo. Left sample in bits [15:0] and right sample in bits [31:16] of same word. Position  */
#define I2SMCC_MRA_DATALENGTH_8_BITS          (I2SMCC_MRA_DATALENGTH_8_BITS_Val << I2SMCC_MRA_DATALENGTH_Pos) /* (I2SMCC_MRA) Data length is set to 8 bits. Position  */
#define I2SMCC_MRA_DATALENGTH_8_BITS_COMPACT  (I2SMCC_MRA_DATALENGTH_8_BITS_COMPACT_Val << I2SMCC_MRA_DATALENGTH_Pos) /* (I2SMCC_MRA) Data length is set to 8-bit compact stereo. Left sample in bits [7:0] and right sample in bits [15:8] of the same word. Position  */
#define I2SMCC_MRA_ZERO_Pos                   _UINT32_(4)                                          /* (I2SMCC_MRA) Must always be written to 0. Position */
#define I2SMCC_MRA_ZERO_Msk                   (_UINT32_(0x3) << I2SMCC_MRA_ZERO_Pos)               /* (I2SMCC_MRA) Must always be written to 0. Mask */
#define I2SMCC_MRA_ZERO(value)                (I2SMCC_MRA_ZERO_Msk & (_UINT32_(value) << I2SMCC_MRA_ZERO_Pos)) /* Assigment of value for ZERO in the I2SMCC_MRA register */
#define I2SMCC_MRA_FORMAT_Pos                 _UINT32_(6)                                          /* (I2SMCC_MRA) Data Format Position */
#define I2SMCC_MRA_FORMAT_Msk                 (_UINT32_(0x3) << I2SMCC_MRA_FORMAT_Pos)             /* (I2SMCC_MRA) Data Format Mask */
#define I2SMCC_MRA_FORMAT(value)              (I2SMCC_MRA_FORMAT_Msk & (_UINT32_(value) << I2SMCC_MRA_FORMAT_Pos)) /* Assigment of value for FORMAT in the I2SMCC_MRA register */
#define   I2SMCC_MRA_FORMAT_I2S_Val           _UINT32_(0x0)                                        /* (I2SMCC_MRA) I2S format, stereo with I2SMCC_WS low for left channel, and MSB of sample starting one I2SMCC_CK period after I2SMCC_WS edge.  */
#define   I2SMCC_MRA_FORMAT_LJ_Val            _UINT32_(0x1)                                        /* (I2SMCC_MRA) Left-justified format, stereo with I2SMCC_WS high for left channel, and MSB of sample starting on I2SMCC_WS edge.  */
#define   I2SMCC_MRA_FORMAT_TDM_Val           _UINT32_(0x2)                                        /* (I2SMCC_MRA) TDM format, with (NBCHAN + 1) channels, I2SMCC_WS high at beginning of first channel, and MSB of sample starting one I2SMCC_CK period after I2SMCC_WS edge.  */
#define   I2SMCC_MRA_FORMAT_TDMLJ_Val         _UINT32_(0x3)                                        /* (I2SMCC_MRA) TDM format, left-justified, with (NBCHAN + 1) channels, I2SMCC_WS high at beginning of first channel, and MSB of sample starting on I2SMCC_WS edge.  */
#define I2SMCC_MRA_FORMAT_I2S                 (I2SMCC_MRA_FORMAT_I2S_Val << I2SMCC_MRA_FORMAT_Pos) /* (I2SMCC_MRA) I2S format, stereo with I2SMCC_WS low for left channel, and MSB of sample starting one I2SMCC_CK period after I2SMCC_WS edge. Position  */
#define I2SMCC_MRA_FORMAT_LJ                  (I2SMCC_MRA_FORMAT_LJ_Val << I2SMCC_MRA_FORMAT_Pos)  /* (I2SMCC_MRA) Left-justified format, stereo with I2SMCC_WS high for left channel, and MSB of sample starting on I2SMCC_WS edge. Position  */
#define I2SMCC_MRA_FORMAT_TDM                 (I2SMCC_MRA_FORMAT_TDM_Val << I2SMCC_MRA_FORMAT_Pos) /* (I2SMCC_MRA) TDM format, with (NBCHAN + 1) channels, I2SMCC_WS high at beginning of first channel, and MSB of sample starting one I2SMCC_CK period after I2SMCC_WS edge. Position  */
#define I2SMCC_MRA_FORMAT_TDMLJ               (I2SMCC_MRA_FORMAT_TDMLJ_Val << I2SMCC_MRA_FORMAT_Pos) /* (I2SMCC_MRA) TDM format, left-justified, with (NBCHAN + 1) channels, I2SMCC_WS high at beginning of first channel, and MSB of sample starting on I2SMCC_WS edge. Position  */
#define I2SMCC_MRA_RXMONO_Pos                 _UINT32_(8)                                          /* (I2SMCC_MRA) Receive Mono Position */
#define I2SMCC_MRA_RXMONO_Msk                 (_UINT32_(0x1) << I2SMCC_MRA_RXMONO_Pos)             /* (I2SMCC_MRA) Receive Mono Mask */
#define I2SMCC_MRA_RXMONO(value)              (I2SMCC_MRA_RXMONO_Msk & (_UINT32_(value) << I2SMCC_MRA_RXMONO_Pos)) /* Assigment of value for RXMONO in the I2SMCC_MRA register */
#define I2SMCC_MRA_RXLOOP_Pos                 _UINT32_(9)                                          /* (I2SMCC_MRA) Loop-back Test Mode Position */
#define I2SMCC_MRA_RXLOOP_Msk                 (_UINT32_(0x1) << I2SMCC_MRA_RXLOOP_Pos)             /* (I2SMCC_MRA) Loop-back Test Mode Mask */
#define I2SMCC_MRA_RXLOOP(value)              (I2SMCC_MRA_RXLOOP_Msk & (_UINT32_(value) << I2SMCC_MRA_RXLOOP_Pos)) /* Assigment of value for RXLOOP in the I2SMCC_MRA register */
#define I2SMCC_MRA_TXMONO_Pos                 _UINT32_(10)                                         /* (I2SMCC_MRA) Transmit Mono Position */
#define I2SMCC_MRA_TXMONO_Msk                 (_UINT32_(0x1) << I2SMCC_MRA_TXMONO_Pos)             /* (I2SMCC_MRA) Transmit Mono Mask */
#define I2SMCC_MRA_TXMONO(value)              (I2SMCC_MRA_TXMONO_Msk & (_UINT32_(value) << I2SMCC_MRA_TXMONO_Pos)) /* Assigment of value for TXMONO in the I2SMCC_MRA register */
#define I2SMCC_MRA_TXSAME_Pos                 _UINT32_(11)                                         /* (I2SMCC_MRA) Transmit Data when Underrun Position */
#define I2SMCC_MRA_TXSAME_Msk                 (_UINT32_(0x1) << I2SMCC_MRA_TXSAME_Pos)             /* (I2SMCC_MRA) Transmit Data when Underrun Mask */
#define I2SMCC_MRA_TXSAME(value)              (I2SMCC_MRA_TXSAME_Msk & (_UINT32_(value) << I2SMCC_MRA_TXSAME_Pos)) /* Assigment of value for TXSAME in the I2SMCC_MRA register */
#define I2SMCC_MRA_SRCCLK_Pos                 _UINT32_(12)                                         /* (I2SMCC_MRA) Source Clock Selection Position */
#define I2SMCC_MRA_SRCCLK_Msk                 (_UINT32_(0x1) << I2SMCC_MRA_SRCCLK_Pos)             /* (I2SMCC_MRA) Source Clock Selection Mask */
#define I2SMCC_MRA_SRCCLK(value)              (I2SMCC_MRA_SRCCLK_Msk & (_UINT32_(value) << I2SMCC_MRA_SRCCLK_Pos)) /* Assigment of value for SRCCLK in the I2SMCC_MRA register */
#define I2SMCC_MRA_NBCHAN_Pos                 _UINT32_(13)                                         /* (I2SMCC_MRA) Number of TDM Channels-1 Position */
#define I2SMCC_MRA_NBCHAN_Msk                 (_UINT32_(0x7) << I2SMCC_MRA_NBCHAN_Pos)             /* (I2SMCC_MRA) Number of TDM Channels-1 Mask */
#define I2SMCC_MRA_NBCHAN(value)              (I2SMCC_MRA_NBCHAN_Msk & (_UINT32_(value) << I2SMCC_MRA_NBCHAN_Pos)) /* Assigment of value for NBCHAN in the I2SMCC_MRA register */
#define I2SMCC_MRA_IMCKDIV_Pos                _UINT32_(16)                                         /* (I2SMCC_MRA) Selected Clock to I2SMCC Master Clock Ratio Position */
#define I2SMCC_MRA_IMCKDIV_Msk                (_UINT32_(0x3F) << I2SMCC_MRA_IMCKDIV_Pos)           /* (I2SMCC_MRA) Selected Clock to I2SMCC Master Clock Ratio Mask */
#define I2SMCC_MRA_IMCKDIV(value)             (I2SMCC_MRA_IMCKDIV_Msk & (_UINT32_(value) << I2SMCC_MRA_IMCKDIV_Pos)) /* Assigment of value for IMCKDIV in the I2SMCC_MRA register */
#define I2SMCC_MRA_TDMFS_Pos                  _UINT32_(22)                                         /* (I2SMCC_MRA) TDM Frame Synchronization Position */
#define I2SMCC_MRA_TDMFS_Msk                  (_UINT32_(0x3) << I2SMCC_MRA_TDMFS_Pos)              /* (I2SMCC_MRA) TDM Frame Synchronization Mask */
#define I2SMCC_MRA_TDMFS(value)               (I2SMCC_MRA_TDMFS_Msk & (_UINT32_(value) << I2SMCC_MRA_TDMFS_Pos)) /* Assigment of value for TDMFS in the I2SMCC_MRA register */
#define   I2SMCC_MRA_TDMFS_SLOT_Val           _UINT32_(0x0)                                        /* (I2SMCC_MRA) I2SMCC_WS pulse is high for one time slot at beginning of frame.  */
#define   I2SMCC_MRA_TDMFS_HALF_Val           _UINT32_(0x1)                                        /* (I2SMCC_MRA) I2SMCC_WS pulse is high for half the time slots at beginning of frame.  */
#define   I2SMCC_MRA_TDMFS_BIT_Val            _UINT32_(0x2)                                        /* (I2SMCC_MRA) I2SMCC_WS pulse is high for one bit period at beginning of frame, i.e., one ISCK period.  */
#define I2SMCC_MRA_TDMFS_SLOT                 (I2SMCC_MRA_TDMFS_SLOT_Val << I2SMCC_MRA_TDMFS_Pos)  /* (I2SMCC_MRA) I2SMCC_WS pulse is high for one time slot at beginning of frame. Position  */
#define I2SMCC_MRA_TDMFS_HALF                 (I2SMCC_MRA_TDMFS_HALF_Val << I2SMCC_MRA_TDMFS_Pos)  /* (I2SMCC_MRA) I2SMCC_WS pulse is high for half the time slots at beginning of frame. Position  */
#define I2SMCC_MRA_TDMFS_BIT                  (I2SMCC_MRA_TDMFS_BIT_Val << I2SMCC_MRA_TDMFS_Pos)   /* (I2SMCC_MRA) I2SMCC_WS pulse is high for one bit period at beginning of frame, i.e., one ISCK period. Position  */
#define I2SMCC_MRA_ISCKDIV_Pos                _UINT32_(24)                                         /* (I2SMCC_MRA) Selected Clock to I2SMCC Serial Clock Ratio Position */
#define I2SMCC_MRA_ISCKDIV_Msk                (_UINT32_(0x3F) << I2SMCC_MRA_ISCKDIV_Pos)           /* (I2SMCC_MRA) Selected Clock to I2SMCC Serial Clock Ratio Mask */
#define I2SMCC_MRA_ISCKDIV(value)             (I2SMCC_MRA_ISCKDIV_Msk & (_UINT32_(value) << I2SMCC_MRA_ISCKDIV_Pos)) /* Assigment of value for ISCKDIV in the I2SMCC_MRA register */
#define I2SMCC_MRA_IMCKMODE_Pos               _UINT32_(30)                                         /* (I2SMCC_MRA) Master Clock Mode Position */
#define I2SMCC_MRA_IMCKMODE_Msk               (_UINT32_(0x1) << I2SMCC_MRA_IMCKMODE_Pos)           /* (I2SMCC_MRA) Master Clock Mode Mask */
#define I2SMCC_MRA_IMCKMODE(value)            (I2SMCC_MRA_IMCKMODE_Msk & (_UINT32_(value) << I2SMCC_MRA_IMCKMODE_Pos)) /* Assigment of value for IMCKMODE in the I2SMCC_MRA register */
#define I2SMCC_MRA_IWS_Pos                    _UINT32_(31)                                         /* (I2SMCC_MRA) I2SMCC_WS Slot Length Position */
#define I2SMCC_MRA_IWS_Msk                    (_UINT32_(0x1) << I2SMCC_MRA_IWS_Pos)                /* (I2SMCC_MRA) I2SMCC_WS Slot Length Mask */
#define I2SMCC_MRA_IWS(value)                 (I2SMCC_MRA_IWS_Msk & (_UINT32_(value) << I2SMCC_MRA_IWS_Pos)) /* Assigment of value for IWS in the I2SMCC_MRA register */
#define I2SMCC_MRA_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (I2SMCC_MRA) Register Mask  */


/* -------- I2SMCC_MRB : (I2SMCC Offset: 0x08) (R/W 32) Mode Register B -------- */
#define I2SMCC_MRB_DMACHUNK_Pos               _UINT32_(8)                                          /* (I2SMCC_MRB) DMA Chunk Size Position */
#define I2SMCC_MRB_DMACHUNK_Msk               (_UINT32_(0x3) << I2SMCC_MRB_DMACHUNK_Pos)           /* (I2SMCC_MRB) DMA Chunk Size Mask */
#define I2SMCC_MRB_DMACHUNK(value)            (I2SMCC_MRB_DMACHUNK_Msk & (_UINT32_(value) << I2SMCC_MRB_DMACHUNK_Pos)) /* Assigment of value for DMACHUNK in the I2SMCC_MRB register */
#define   I2SMCC_MRB_DMACHUNK_1_WORD_Val      _UINT32_(0x0)                                        /* (I2SMCC_MRB) Each DMA transfer contains 1 word.  */
#define   I2SMCC_MRB_DMACHUNK_2_WORDS_Val     _UINT32_(0x1)                                        /* (I2SMCC_MRB) Each DMA transfer contains 2 words.  */
#define   I2SMCC_MRB_DMACHUNK_4_WORDS_Val     _UINT32_(0x2)                                        /* (I2SMCC_MRB) Each DMA transfer contains 4 words.  */
#define   I2SMCC_MRB_DMACHUNK_8_WORDS_Val     _UINT32_(0x3)                                        /* (I2SMCC_MRB) Each DMA transfer contains 8 words.  */
#define I2SMCC_MRB_DMACHUNK_1_WORD            (I2SMCC_MRB_DMACHUNK_1_WORD_Val << I2SMCC_MRB_DMACHUNK_Pos) /* (I2SMCC_MRB) Each DMA transfer contains 1 word. Position  */
#define I2SMCC_MRB_DMACHUNK_2_WORDS           (I2SMCC_MRB_DMACHUNK_2_WORDS_Val << I2SMCC_MRB_DMACHUNK_Pos) /* (I2SMCC_MRB) Each DMA transfer contains 2 words. Position  */
#define I2SMCC_MRB_DMACHUNK_4_WORDS           (I2SMCC_MRB_DMACHUNK_4_WORDS_Val << I2SMCC_MRB_DMACHUNK_Pos) /* (I2SMCC_MRB) Each DMA transfer contains 4 words. Position  */
#define I2SMCC_MRB_DMACHUNK_8_WORDS           (I2SMCC_MRB_DMACHUNK_8_WORDS_Val << I2SMCC_MRB_DMACHUNK_Pos) /* (I2SMCC_MRB) Each DMA transfer contains 8 words. Position  */
#define I2SMCC_MRB_CLKSEL_Pos                 _UINT32_(16)                                         /* (I2SMCC_MRB) Serial Clock Selection Position */
#define I2SMCC_MRB_CLKSEL_Msk                 (_UINT32_(0x1) << I2SMCC_MRB_CLKSEL_Pos)             /* (I2SMCC_MRB) Serial Clock Selection Mask */
#define I2SMCC_MRB_CLKSEL(value)              (I2SMCC_MRB_CLKSEL_Msk & (_UINT32_(value) << I2SMCC_MRB_CLKSEL_Pos)) /* Assigment of value for CLKSEL in the I2SMCC_MRB register */
#define I2SMCC_MRB_Msk                        _UINT32_(0x00010300)                                 /* (I2SMCC_MRB) Register Mask  */


/* -------- I2SMCC_SR : (I2SMCC Offset: 0x0C) ( R/ 32) Status Register -------- */
#define I2SMCC_SR_RXEN_Pos                    _UINT32_(0)                                          /* (I2SMCC_SR) Receiver Enabled Position */
#define I2SMCC_SR_RXEN_Msk                    (_UINT32_(0x1) << I2SMCC_SR_RXEN_Pos)                /* (I2SMCC_SR) Receiver Enabled Mask */
#define I2SMCC_SR_RXEN(value)                 (I2SMCC_SR_RXEN_Msk & (_UINT32_(value) << I2SMCC_SR_RXEN_Pos)) /* Assigment of value for RXEN in the I2SMCC_SR register */
#define I2SMCC_SR_TXEN_Pos                    _UINT32_(4)                                          /* (I2SMCC_SR) Transmitter Enabled Position */
#define I2SMCC_SR_TXEN_Msk                    (_UINT32_(0x1) << I2SMCC_SR_TXEN_Pos)                /* (I2SMCC_SR) Transmitter Enabled Mask */
#define I2SMCC_SR_TXEN(value)                 (I2SMCC_SR_TXEN_Msk & (_UINT32_(value) << I2SMCC_SR_TXEN_Pos)) /* Assigment of value for TXEN in the I2SMCC_SR register */
#define I2SMCC_SR_Msk                         _UINT32_(0x00000011)                                 /* (I2SMCC_SR) Register Mask  */


/* -------- I2SMCC_IERA : (I2SMCC Offset: 0x10) ( /W 32) Interrupt Enable Register A -------- */
#define I2SMCC_IERA_TXLRDY0_Pos               _UINT32_(0)                                          /* (I2SMCC_IERA) I2S Transmit Left 0 (x=0 only) or TDM Channel 2x Ready Interrupt Enable Position */
#define I2SMCC_IERA_TXLRDY0_Msk               (_UINT32_(0x1) << I2SMCC_IERA_TXLRDY0_Pos)           /* (I2SMCC_IERA) I2S Transmit Left 0 (x=0 only) or TDM Channel 2x Ready Interrupt Enable Mask */
#define I2SMCC_IERA_TXLRDY0(value)            (I2SMCC_IERA_TXLRDY0_Msk & (_UINT32_(value) << I2SMCC_IERA_TXLRDY0_Pos)) /* Assigment of value for TXLRDY0 in the I2SMCC_IERA register */
#define I2SMCC_IERA_TXRRDY0_Pos               _UINT32_(1)                                          /* (I2SMCC_IERA) I2S Transmit Right 0 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Enable Position */
#define I2SMCC_IERA_TXRRDY0_Msk               (_UINT32_(0x1) << I2SMCC_IERA_TXRRDY0_Pos)           /* (I2SMCC_IERA) I2S Transmit Right 0 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Enable Mask */
#define I2SMCC_IERA_TXRRDY0(value)            (I2SMCC_IERA_TXRRDY0_Msk & (_UINT32_(value) << I2SMCC_IERA_TXRRDY0_Pos)) /* Assigment of value for TXRRDY0 in the I2SMCC_IERA register */
#define I2SMCC_IERA_TXLRDY1_Pos               _UINT32_(2)                                          /* (I2SMCC_IERA) I2S Transmit Left 1 (x=0 only) or TDM Channel 2x Ready Interrupt Enable Position */
#define I2SMCC_IERA_TXLRDY1_Msk               (_UINT32_(0x1) << I2SMCC_IERA_TXLRDY1_Pos)           /* (I2SMCC_IERA) I2S Transmit Left 1 (x=0 only) or TDM Channel 2x Ready Interrupt Enable Mask */
#define I2SMCC_IERA_TXLRDY1(value)            (I2SMCC_IERA_TXLRDY1_Msk & (_UINT32_(value) << I2SMCC_IERA_TXLRDY1_Pos)) /* Assigment of value for TXLRDY1 in the I2SMCC_IERA register */
#define I2SMCC_IERA_TXRRDY1_Pos               _UINT32_(3)                                          /* (I2SMCC_IERA) I2S Transmit Right 1 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Enable Position */
#define I2SMCC_IERA_TXRRDY1_Msk               (_UINT32_(0x1) << I2SMCC_IERA_TXRRDY1_Pos)           /* (I2SMCC_IERA) I2S Transmit Right 1 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Enable Mask */
#define I2SMCC_IERA_TXRRDY1(value)            (I2SMCC_IERA_TXRRDY1_Msk & (_UINT32_(value) << I2SMCC_IERA_TXRRDY1_Pos)) /* Assigment of value for TXRRDY1 in the I2SMCC_IERA register */
#define I2SMCC_IERA_TXLRDY2_Pos               _UINT32_(4)                                          /* (I2SMCC_IERA) I2S Transmit Left 2 (x=0 only) or TDM Channel 2x Ready Interrupt Enable Position */
#define I2SMCC_IERA_TXLRDY2_Msk               (_UINT32_(0x1) << I2SMCC_IERA_TXLRDY2_Pos)           /* (I2SMCC_IERA) I2S Transmit Left 2 (x=0 only) or TDM Channel 2x Ready Interrupt Enable Mask */
#define I2SMCC_IERA_TXLRDY2(value)            (I2SMCC_IERA_TXLRDY2_Msk & (_UINT32_(value) << I2SMCC_IERA_TXLRDY2_Pos)) /* Assigment of value for TXLRDY2 in the I2SMCC_IERA register */
#define I2SMCC_IERA_TXRRDY2_Pos               _UINT32_(5)                                          /* (I2SMCC_IERA) I2S Transmit Right 2 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Enable Position */
#define I2SMCC_IERA_TXRRDY2_Msk               (_UINT32_(0x1) << I2SMCC_IERA_TXRRDY2_Pos)           /* (I2SMCC_IERA) I2S Transmit Right 2 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Enable Mask */
#define I2SMCC_IERA_TXRRDY2(value)            (I2SMCC_IERA_TXRRDY2_Msk & (_UINT32_(value) << I2SMCC_IERA_TXRRDY2_Pos)) /* Assigment of value for TXRRDY2 in the I2SMCC_IERA register */
#define I2SMCC_IERA_TXLRDY3_Pos               _UINT32_(6)                                          /* (I2SMCC_IERA) I2S Transmit Left 3 (x=0 only) or TDM Channel 2x Ready Interrupt Enable Position */
#define I2SMCC_IERA_TXLRDY3_Msk               (_UINT32_(0x1) << I2SMCC_IERA_TXLRDY3_Pos)           /* (I2SMCC_IERA) I2S Transmit Left 3 (x=0 only) or TDM Channel 2x Ready Interrupt Enable Mask */
#define I2SMCC_IERA_TXLRDY3(value)            (I2SMCC_IERA_TXLRDY3_Msk & (_UINT32_(value) << I2SMCC_IERA_TXLRDY3_Pos)) /* Assigment of value for TXLRDY3 in the I2SMCC_IERA register */
#define I2SMCC_IERA_TXRRDY3_Pos               _UINT32_(7)                                          /* (I2SMCC_IERA) I2S Transmit Right 3 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Enable Position */
#define I2SMCC_IERA_TXRRDY3_Msk               (_UINT32_(0x1) << I2SMCC_IERA_TXRRDY3_Pos)           /* (I2SMCC_IERA) I2S Transmit Right 3 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Enable Mask */
#define I2SMCC_IERA_TXRRDY3(value)            (I2SMCC_IERA_TXRRDY3_Msk & (_UINT32_(value) << I2SMCC_IERA_TXRRDY3_Pos)) /* Assigment of value for TXRRDY3 in the I2SMCC_IERA register */
#define I2SMCC_IERA_TXLUNF0_Pos               _UINT32_(8)                                          /* (I2SMCC_IERA) I2S Transmit Left 0 (x=0 only) or TDM Channel 2x Underrun Interrupt Enable Position */
#define I2SMCC_IERA_TXLUNF0_Msk               (_UINT32_(0x1) << I2SMCC_IERA_TXLUNF0_Pos)           /* (I2SMCC_IERA) I2S Transmit Left 0 (x=0 only) or TDM Channel 2x Underrun Interrupt Enable Mask */
#define I2SMCC_IERA_TXLUNF0(value)            (I2SMCC_IERA_TXLUNF0_Msk & (_UINT32_(value) << I2SMCC_IERA_TXLUNF0_Pos)) /* Assigment of value for TXLUNF0 in the I2SMCC_IERA register */
#define I2SMCC_IERA_TXRUNF0_Pos               _UINT32_(9)                                          /* (I2SMCC_IERA) I2S Transmit Right 0 (x=0 only) or TDM Channel [2x]+1 Underrun Interrupt Enable Position */
#define I2SMCC_IERA_TXRUNF0_Msk               (_UINT32_(0x1) << I2SMCC_IERA_TXRUNF0_Pos)           /* (I2SMCC_IERA) I2S Transmit Right 0 (x=0 only) or TDM Channel [2x]+1 Underrun Interrupt Enable Mask */
#define I2SMCC_IERA_TXRUNF0(value)            (I2SMCC_IERA_TXRUNF0_Msk & (_UINT32_(value) << I2SMCC_IERA_TXRUNF0_Pos)) /* Assigment of value for TXRUNF0 in the I2SMCC_IERA register */
#define I2SMCC_IERA_TXLUNF1_Pos               _UINT32_(10)                                         /* (I2SMCC_IERA) I2S Transmit Left 1 (x=0 only) or TDM Channel 2x Underrun Interrupt Enable Position */
#define I2SMCC_IERA_TXLUNF1_Msk               (_UINT32_(0x1) << I2SMCC_IERA_TXLUNF1_Pos)           /* (I2SMCC_IERA) I2S Transmit Left 1 (x=0 only) or TDM Channel 2x Underrun Interrupt Enable Mask */
#define I2SMCC_IERA_TXLUNF1(value)            (I2SMCC_IERA_TXLUNF1_Msk & (_UINT32_(value) << I2SMCC_IERA_TXLUNF1_Pos)) /* Assigment of value for TXLUNF1 in the I2SMCC_IERA register */
#define I2SMCC_IERA_TXRUNF1_Pos               _UINT32_(11)                                         /* (I2SMCC_IERA) I2S Transmit Right 1 (x=0 only) or TDM Channel [2x]+1 Underrun Interrupt Enable Position */
#define I2SMCC_IERA_TXRUNF1_Msk               (_UINT32_(0x1) << I2SMCC_IERA_TXRUNF1_Pos)           /* (I2SMCC_IERA) I2S Transmit Right 1 (x=0 only) or TDM Channel [2x]+1 Underrun Interrupt Enable Mask */
#define I2SMCC_IERA_TXRUNF1(value)            (I2SMCC_IERA_TXRUNF1_Msk & (_UINT32_(value) << I2SMCC_IERA_TXRUNF1_Pos)) /* Assigment of value for TXRUNF1 in the I2SMCC_IERA register */
#define I2SMCC_IERA_TXLUNF2_Pos               _UINT32_(12)                                         /* (I2SMCC_IERA) I2S Transmit Left 2 (x=0 only) or TDM Channel 2x Underrun Interrupt Enable Position */
#define I2SMCC_IERA_TXLUNF2_Msk               (_UINT32_(0x1) << I2SMCC_IERA_TXLUNF2_Pos)           /* (I2SMCC_IERA) I2S Transmit Left 2 (x=0 only) or TDM Channel 2x Underrun Interrupt Enable Mask */
#define I2SMCC_IERA_TXLUNF2(value)            (I2SMCC_IERA_TXLUNF2_Msk & (_UINT32_(value) << I2SMCC_IERA_TXLUNF2_Pos)) /* Assigment of value for TXLUNF2 in the I2SMCC_IERA register */
#define I2SMCC_IERA_TXRUNF2_Pos               _UINT32_(13)                                         /* (I2SMCC_IERA) I2S Transmit Right 2 (x=0 only) or TDM Channel [2x]+1 Underrun Interrupt Enable Position */
#define I2SMCC_IERA_TXRUNF2_Msk               (_UINT32_(0x1) << I2SMCC_IERA_TXRUNF2_Pos)           /* (I2SMCC_IERA) I2S Transmit Right 2 (x=0 only) or TDM Channel [2x]+1 Underrun Interrupt Enable Mask */
#define I2SMCC_IERA_TXRUNF2(value)            (I2SMCC_IERA_TXRUNF2_Msk & (_UINT32_(value) << I2SMCC_IERA_TXRUNF2_Pos)) /* Assigment of value for TXRUNF2 in the I2SMCC_IERA register */
#define I2SMCC_IERA_TXLUNF3_Pos               _UINT32_(14)                                         /* (I2SMCC_IERA) I2S Transmit Left 3 (x=0 only) or TDM Channel 2x Underrun Interrupt Enable Position */
#define I2SMCC_IERA_TXLUNF3_Msk               (_UINT32_(0x1) << I2SMCC_IERA_TXLUNF3_Pos)           /* (I2SMCC_IERA) I2S Transmit Left 3 (x=0 only) or TDM Channel 2x Underrun Interrupt Enable Mask */
#define I2SMCC_IERA_TXLUNF3(value)            (I2SMCC_IERA_TXLUNF3_Msk & (_UINT32_(value) << I2SMCC_IERA_TXLUNF3_Pos)) /* Assigment of value for TXLUNF3 in the I2SMCC_IERA register */
#define I2SMCC_IERA_TXRUNF3_Pos               _UINT32_(15)                                         /* (I2SMCC_IERA) I2S Transmit Right 3 (x=0 only) or TDM Channel [2x]+1 Underrun Interrupt Enable Position */
#define I2SMCC_IERA_TXRUNF3_Msk               (_UINT32_(0x1) << I2SMCC_IERA_TXRUNF3_Pos)           /* (I2SMCC_IERA) I2S Transmit Right 3 (x=0 only) or TDM Channel [2x]+1 Underrun Interrupt Enable Mask */
#define I2SMCC_IERA_TXRUNF3(value)            (I2SMCC_IERA_TXRUNF3_Msk & (_UINT32_(value) << I2SMCC_IERA_TXRUNF3_Pos)) /* Assigment of value for TXRUNF3 in the I2SMCC_IERA register */
#define I2SMCC_IERA_RXLRDY0_Pos               _UINT32_(16)                                         /* (I2SMCC_IERA) I2S Receive Left 0 (x=0 only) or TDM Channel 2x Ready Interrupt Enable Position */
#define I2SMCC_IERA_RXLRDY0_Msk               (_UINT32_(0x1) << I2SMCC_IERA_RXLRDY0_Pos)           /* (I2SMCC_IERA) I2S Receive Left 0 (x=0 only) or TDM Channel 2x Ready Interrupt Enable Mask */
#define I2SMCC_IERA_RXLRDY0(value)            (I2SMCC_IERA_RXLRDY0_Msk & (_UINT32_(value) << I2SMCC_IERA_RXLRDY0_Pos)) /* Assigment of value for RXLRDY0 in the I2SMCC_IERA register */
#define I2SMCC_IERA_RXRRDY0_Pos               _UINT32_(17)                                         /* (I2SMCC_IERA) I2S Receive Right 0 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Enable Position */
#define I2SMCC_IERA_RXRRDY0_Msk               (_UINT32_(0x1) << I2SMCC_IERA_RXRRDY0_Pos)           /* (I2SMCC_IERA) I2S Receive Right 0 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Enable Mask */
#define I2SMCC_IERA_RXRRDY0(value)            (I2SMCC_IERA_RXRRDY0_Msk & (_UINT32_(value) << I2SMCC_IERA_RXRRDY0_Pos)) /* Assigment of value for RXRRDY0 in the I2SMCC_IERA register */
#define I2SMCC_IERA_RXLRDY1_Pos               _UINT32_(18)                                         /* (I2SMCC_IERA) I2S Receive Left 1 (x=0 only) or TDM Channel 2x Ready Interrupt Enable Position */
#define I2SMCC_IERA_RXLRDY1_Msk               (_UINT32_(0x1) << I2SMCC_IERA_RXLRDY1_Pos)           /* (I2SMCC_IERA) I2S Receive Left 1 (x=0 only) or TDM Channel 2x Ready Interrupt Enable Mask */
#define I2SMCC_IERA_RXLRDY1(value)            (I2SMCC_IERA_RXLRDY1_Msk & (_UINT32_(value) << I2SMCC_IERA_RXLRDY1_Pos)) /* Assigment of value for RXLRDY1 in the I2SMCC_IERA register */
#define I2SMCC_IERA_RXRRDY1_Pos               _UINT32_(19)                                         /* (I2SMCC_IERA) I2S Receive Right 1 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Enable Position */
#define I2SMCC_IERA_RXRRDY1_Msk               (_UINT32_(0x1) << I2SMCC_IERA_RXRRDY1_Pos)           /* (I2SMCC_IERA) I2S Receive Right 1 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Enable Mask */
#define I2SMCC_IERA_RXRRDY1(value)            (I2SMCC_IERA_RXRRDY1_Msk & (_UINT32_(value) << I2SMCC_IERA_RXRRDY1_Pos)) /* Assigment of value for RXRRDY1 in the I2SMCC_IERA register */
#define I2SMCC_IERA_RXLRDY2_Pos               _UINT32_(20)                                         /* (I2SMCC_IERA) I2S Receive Left 2 (x=0 only) or TDM Channel 2x Ready Interrupt Enable Position */
#define I2SMCC_IERA_RXLRDY2_Msk               (_UINT32_(0x1) << I2SMCC_IERA_RXLRDY2_Pos)           /* (I2SMCC_IERA) I2S Receive Left 2 (x=0 only) or TDM Channel 2x Ready Interrupt Enable Mask */
#define I2SMCC_IERA_RXLRDY2(value)            (I2SMCC_IERA_RXLRDY2_Msk & (_UINT32_(value) << I2SMCC_IERA_RXLRDY2_Pos)) /* Assigment of value for RXLRDY2 in the I2SMCC_IERA register */
#define I2SMCC_IERA_RXRRDY2_Pos               _UINT32_(21)                                         /* (I2SMCC_IERA) I2S Receive Right 2 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Enable Position */
#define I2SMCC_IERA_RXRRDY2_Msk               (_UINT32_(0x1) << I2SMCC_IERA_RXRRDY2_Pos)           /* (I2SMCC_IERA) I2S Receive Right 2 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Enable Mask */
#define I2SMCC_IERA_RXRRDY2(value)            (I2SMCC_IERA_RXRRDY2_Msk & (_UINT32_(value) << I2SMCC_IERA_RXRRDY2_Pos)) /* Assigment of value for RXRRDY2 in the I2SMCC_IERA register */
#define I2SMCC_IERA_RXLRDY3_Pos               _UINT32_(22)                                         /* (I2SMCC_IERA) I2S Receive Left 3 (x=0 only) or TDM Channel 2x Ready Interrupt Enable Position */
#define I2SMCC_IERA_RXLRDY3_Msk               (_UINT32_(0x1) << I2SMCC_IERA_RXLRDY3_Pos)           /* (I2SMCC_IERA) I2S Receive Left 3 (x=0 only) or TDM Channel 2x Ready Interrupt Enable Mask */
#define I2SMCC_IERA_RXLRDY3(value)            (I2SMCC_IERA_RXLRDY3_Msk & (_UINT32_(value) << I2SMCC_IERA_RXLRDY3_Pos)) /* Assigment of value for RXLRDY3 in the I2SMCC_IERA register */
#define I2SMCC_IERA_RXRRDY3_Pos               _UINT32_(23)                                         /* (I2SMCC_IERA) I2S Receive Right 3 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Enable Position */
#define I2SMCC_IERA_RXRRDY3_Msk               (_UINT32_(0x1) << I2SMCC_IERA_RXRRDY3_Pos)           /* (I2SMCC_IERA) I2S Receive Right 3 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Enable Mask */
#define I2SMCC_IERA_RXRRDY3(value)            (I2SMCC_IERA_RXRRDY3_Msk & (_UINT32_(value) << I2SMCC_IERA_RXRRDY3_Pos)) /* Assigment of value for RXRRDY3 in the I2SMCC_IERA register */
#define I2SMCC_IERA_RXLOVF0_Pos               _UINT32_(24)                                         /* (I2SMCC_IERA) I2S Receive Left 0 (x=0 only) or TDM Channel 2x Overrun Interrupt Enable Position */
#define I2SMCC_IERA_RXLOVF0_Msk               (_UINT32_(0x1) << I2SMCC_IERA_RXLOVF0_Pos)           /* (I2SMCC_IERA) I2S Receive Left 0 (x=0 only) or TDM Channel 2x Overrun Interrupt Enable Mask */
#define I2SMCC_IERA_RXLOVF0(value)            (I2SMCC_IERA_RXLOVF0_Msk & (_UINT32_(value) << I2SMCC_IERA_RXLOVF0_Pos)) /* Assigment of value for RXLOVF0 in the I2SMCC_IERA register */
#define I2SMCC_IERA_RXROVF0_Pos               _UINT32_(25)                                         /* (I2SMCC_IERA) I2S Receive Right 0 (x=0 only) or TDM Channel [2x]+1 Overrun Interrupt Enable Position */
#define I2SMCC_IERA_RXROVF0_Msk               (_UINT32_(0x1) << I2SMCC_IERA_RXROVF0_Pos)           /* (I2SMCC_IERA) I2S Receive Right 0 (x=0 only) or TDM Channel [2x]+1 Overrun Interrupt Enable Mask */
#define I2SMCC_IERA_RXROVF0(value)            (I2SMCC_IERA_RXROVF0_Msk & (_UINT32_(value) << I2SMCC_IERA_RXROVF0_Pos)) /* Assigment of value for RXROVF0 in the I2SMCC_IERA register */
#define I2SMCC_IERA_RXLOVF1_Pos               _UINT32_(26)                                         /* (I2SMCC_IERA) I2S Receive Left 1 (x=0 only) or TDM Channel 2x Overrun Interrupt Enable Position */
#define I2SMCC_IERA_RXLOVF1_Msk               (_UINT32_(0x1) << I2SMCC_IERA_RXLOVF1_Pos)           /* (I2SMCC_IERA) I2S Receive Left 1 (x=0 only) or TDM Channel 2x Overrun Interrupt Enable Mask */
#define I2SMCC_IERA_RXLOVF1(value)            (I2SMCC_IERA_RXLOVF1_Msk & (_UINT32_(value) << I2SMCC_IERA_RXLOVF1_Pos)) /* Assigment of value for RXLOVF1 in the I2SMCC_IERA register */
#define I2SMCC_IERA_RXROVF1_Pos               _UINT32_(27)                                         /* (I2SMCC_IERA) I2S Receive Right 1 (x=0 only) or TDM Channel [2x]+1 Overrun Interrupt Enable Position */
#define I2SMCC_IERA_RXROVF1_Msk               (_UINT32_(0x1) << I2SMCC_IERA_RXROVF1_Pos)           /* (I2SMCC_IERA) I2S Receive Right 1 (x=0 only) or TDM Channel [2x]+1 Overrun Interrupt Enable Mask */
#define I2SMCC_IERA_RXROVF1(value)            (I2SMCC_IERA_RXROVF1_Msk & (_UINT32_(value) << I2SMCC_IERA_RXROVF1_Pos)) /* Assigment of value for RXROVF1 in the I2SMCC_IERA register */
#define I2SMCC_IERA_RXLOVF2_Pos               _UINT32_(28)                                         /* (I2SMCC_IERA) I2S Receive Left 2 (x=0 only) or TDM Channel 2x Overrun Interrupt Enable Position */
#define I2SMCC_IERA_RXLOVF2_Msk               (_UINT32_(0x1) << I2SMCC_IERA_RXLOVF2_Pos)           /* (I2SMCC_IERA) I2S Receive Left 2 (x=0 only) or TDM Channel 2x Overrun Interrupt Enable Mask */
#define I2SMCC_IERA_RXLOVF2(value)            (I2SMCC_IERA_RXLOVF2_Msk & (_UINT32_(value) << I2SMCC_IERA_RXLOVF2_Pos)) /* Assigment of value for RXLOVF2 in the I2SMCC_IERA register */
#define I2SMCC_IERA_RXROVF2_Pos               _UINT32_(29)                                         /* (I2SMCC_IERA) I2S Receive Right 2 (x=0 only) or TDM Channel [2x]+1 Overrun Interrupt Enable Position */
#define I2SMCC_IERA_RXROVF2_Msk               (_UINT32_(0x1) << I2SMCC_IERA_RXROVF2_Pos)           /* (I2SMCC_IERA) I2S Receive Right 2 (x=0 only) or TDM Channel [2x]+1 Overrun Interrupt Enable Mask */
#define I2SMCC_IERA_RXROVF2(value)            (I2SMCC_IERA_RXROVF2_Msk & (_UINT32_(value) << I2SMCC_IERA_RXROVF2_Pos)) /* Assigment of value for RXROVF2 in the I2SMCC_IERA register */
#define I2SMCC_IERA_RXLOVF3_Pos               _UINT32_(30)                                         /* (I2SMCC_IERA) I2S Receive Left 3 (x=0 only) or TDM Channel 2x Overrun Interrupt Enable Position */
#define I2SMCC_IERA_RXLOVF3_Msk               (_UINT32_(0x1) << I2SMCC_IERA_RXLOVF3_Pos)           /* (I2SMCC_IERA) I2S Receive Left 3 (x=0 only) or TDM Channel 2x Overrun Interrupt Enable Mask */
#define I2SMCC_IERA_RXLOVF3(value)            (I2SMCC_IERA_RXLOVF3_Msk & (_UINT32_(value) << I2SMCC_IERA_RXLOVF3_Pos)) /* Assigment of value for RXLOVF3 in the I2SMCC_IERA register */
#define I2SMCC_IERA_RXROVF3_Pos               _UINT32_(31)                                         /* (I2SMCC_IERA) I2S Receive Right 3 (x=0 only) or TDM Channel [2x]+1 Overrun Interrupt Enable Position */
#define I2SMCC_IERA_RXROVF3_Msk               (_UINT32_(0x1) << I2SMCC_IERA_RXROVF3_Pos)           /* (I2SMCC_IERA) I2S Receive Right 3 (x=0 only) or TDM Channel [2x]+1 Overrun Interrupt Enable Mask */
#define I2SMCC_IERA_RXROVF3(value)            (I2SMCC_IERA_RXROVF3_Msk & (_UINT32_(value) << I2SMCC_IERA_RXROVF3_Pos)) /* Assigment of value for RXROVF3 in the I2SMCC_IERA register */
#define I2SMCC_IERA_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (I2SMCC_IERA) Register Mask  */


/* -------- I2SMCC_IDRA : (I2SMCC Offset: 0x14) ( /W 32) Interrupt Disable Register A -------- */
#define I2SMCC_IDRA_TXLRDY0_Pos               _UINT32_(0)                                          /* (I2SMCC_IDRA) I2S Transmit Left 0 (x=0 only) or TDM Channel 2x Ready Interrupt Disable Position */
#define I2SMCC_IDRA_TXLRDY0_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_TXLRDY0_Pos)           /* (I2SMCC_IDRA) I2S Transmit Left 0 (x=0 only) or TDM Channel 2x Ready Interrupt Disable Mask */
#define I2SMCC_IDRA_TXLRDY0(value)            (I2SMCC_IDRA_TXLRDY0_Msk & (_UINT32_(value) << I2SMCC_IDRA_TXLRDY0_Pos)) /* Assigment of value for TXLRDY0 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_TXRRDY0_Pos               _UINT32_(1)                                          /* (I2SMCC_IDRA) I2S Transmit Right 0 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Disable Position */
#define I2SMCC_IDRA_TXRRDY0_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_TXRRDY0_Pos)           /* (I2SMCC_IDRA) I2S Transmit Right 0 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Disable Mask */
#define I2SMCC_IDRA_TXRRDY0(value)            (I2SMCC_IDRA_TXRRDY0_Msk & (_UINT32_(value) << I2SMCC_IDRA_TXRRDY0_Pos)) /* Assigment of value for TXRRDY0 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_TXLRDY1_Pos               _UINT32_(2)                                          /* (I2SMCC_IDRA) I2S Transmit Left 1 (x=0 only) or TDM Channel 2x Ready Interrupt Disable Position */
#define I2SMCC_IDRA_TXLRDY1_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_TXLRDY1_Pos)           /* (I2SMCC_IDRA) I2S Transmit Left 1 (x=0 only) or TDM Channel 2x Ready Interrupt Disable Mask */
#define I2SMCC_IDRA_TXLRDY1(value)            (I2SMCC_IDRA_TXLRDY1_Msk & (_UINT32_(value) << I2SMCC_IDRA_TXLRDY1_Pos)) /* Assigment of value for TXLRDY1 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_TXRRDY1_Pos               _UINT32_(3)                                          /* (I2SMCC_IDRA) I2S Transmit Right 1 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Disable Position */
#define I2SMCC_IDRA_TXRRDY1_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_TXRRDY1_Pos)           /* (I2SMCC_IDRA) I2S Transmit Right 1 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Disable Mask */
#define I2SMCC_IDRA_TXRRDY1(value)            (I2SMCC_IDRA_TXRRDY1_Msk & (_UINT32_(value) << I2SMCC_IDRA_TXRRDY1_Pos)) /* Assigment of value for TXRRDY1 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_TXLRDY2_Pos               _UINT32_(4)                                          /* (I2SMCC_IDRA) I2S Transmit Left 2 (x=0 only) or TDM Channel 2x Ready Interrupt Disable Position */
#define I2SMCC_IDRA_TXLRDY2_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_TXLRDY2_Pos)           /* (I2SMCC_IDRA) I2S Transmit Left 2 (x=0 only) or TDM Channel 2x Ready Interrupt Disable Mask */
#define I2SMCC_IDRA_TXLRDY2(value)            (I2SMCC_IDRA_TXLRDY2_Msk & (_UINT32_(value) << I2SMCC_IDRA_TXLRDY2_Pos)) /* Assigment of value for TXLRDY2 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_TXRRDY2_Pos               _UINT32_(5)                                          /* (I2SMCC_IDRA) I2S Transmit Right 2 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Disable Position */
#define I2SMCC_IDRA_TXRRDY2_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_TXRRDY2_Pos)           /* (I2SMCC_IDRA) I2S Transmit Right 2 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Disable Mask */
#define I2SMCC_IDRA_TXRRDY2(value)            (I2SMCC_IDRA_TXRRDY2_Msk & (_UINT32_(value) << I2SMCC_IDRA_TXRRDY2_Pos)) /* Assigment of value for TXRRDY2 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_TXLRDY3_Pos               _UINT32_(6)                                          /* (I2SMCC_IDRA) I2S Transmit Left 3 (x=0 only) or TDM Channel 2x Ready Interrupt Disable Position */
#define I2SMCC_IDRA_TXLRDY3_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_TXLRDY3_Pos)           /* (I2SMCC_IDRA) I2S Transmit Left 3 (x=0 only) or TDM Channel 2x Ready Interrupt Disable Mask */
#define I2SMCC_IDRA_TXLRDY3(value)            (I2SMCC_IDRA_TXLRDY3_Msk & (_UINT32_(value) << I2SMCC_IDRA_TXLRDY3_Pos)) /* Assigment of value for TXLRDY3 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_TXRRDY3_Pos               _UINT32_(7)                                          /* (I2SMCC_IDRA) I2S Transmit Right 3 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Disable Position */
#define I2SMCC_IDRA_TXRRDY3_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_TXRRDY3_Pos)           /* (I2SMCC_IDRA) I2S Transmit Right 3 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Disable Mask */
#define I2SMCC_IDRA_TXRRDY3(value)            (I2SMCC_IDRA_TXRRDY3_Msk & (_UINT32_(value) << I2SMCC_IDRA_TXRRDY3_Pos)) /* Assigment of value for TXRRDY3 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_TXLUNF0_Pos               _UINT32_(8)                                          /* (I2SMCC_IDRA) I2S Transmit Left 0 (x=0 only) or TDM Channel 2x Underrun Interrupt Disable Position */
#define I2SMCC_IDRA_TXLUNF0_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_TXLUNF0_Pos)           /* (I2SMCC_IDRA) I2S Transmit Left 0 (x=0 only) or TDM Channel 2x Underrun Interrupt Disable Mask */
#define I2SMCC_IDRA_TXLUNF0(value)            (I2SMCC_IDRA_TXLUNF0_Msk & (_UINT32_(value) << I2SMCC_IDRA_TXLUNF0_Pos)) /* Assigment of value for TXLUNF0 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_TXRUNF0_Pos               _UINT32_(9)                                          /* (I2SMCC_IDRA) I2S Transmit Right 0 (x=0 only) or TDM Channel [2x]+1 Underrun Interrupt Disable Position */
#define I2SMCC_IDRA_TXRUNF0_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_TXRUNF0_Pos)           /* (I2SMCC_IDRA) I2S Transmit Right 0 (x=0 only) or TDM Channel [2x]+1 Underrun Interrupt Disable Mask */
#define I2SMCC_IDRA_TXRUNF0(value)            (I2SMCC_IDRA_TXRUNF0_Msk & (_UINT32_(value) << I2SMCC_IDRA_TXRUNF0_Pos)) /* Assigment of value for TXRUNF0 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_TXLUNF1_Pos               _UINT32_(10)                                         /* (I2SMCC_IDRA) I2S Transmit Left 1 (x=0 only) or TDM Channel 2x Underrun Interrupt Disable Position */
#define I2SMCC_IDRA_TXLUNF1_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_TXLUNF1_Pos)           /* (I2SMCC_IDRA) I2S Transmit Left 1 (x=0 only) or TDM Channel 2x Underrun Interrupt Disable Mask */
#define I2SMCC_IDRA_TXLUNF1(value)            (I2SMCC_IDRA_TXLUNF1_Msk & (_UINT32_(value) << I2SMCC_IDRA_TXLUNF1_Pos)) /* Assigment of value for TXLUNF1 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_TXRUNF1_Pos               _UINT32_(11)                                         /* (I2SMCC_IDRA) I2S Transmit Right 1 (x=0 only) or TDM Channel [2x]+1 Underrun Interrupt Disable Position */
#define I2SMCC_IDRA_TXRUNF1_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_TXRUNF1_Pos)           /* (I2SMCC_IDRA) I2S Transmit Right 1 (x=0 only) or TDM Channel [2x]+1 Underrun Interrupt Disable Mask */
#define I2SMCC_IDRA_TXRUNF1(value)            (I2SMCC_IDRA_TXRUNF1_Msk & (_UINT32_(value) << I2SMCC_IDRA_TXRUNF1_Pos)) /* Assigment of value for TXRUNF1 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_TXLUNF2_Pos               _UINT32_(12)                                         /* (I2SMCC_IDRA) I2S Transmit Left 2 (x=0 only) or TDM Channel 2x Underrun Interrupt Disable Position */
#define I2SMCC_IDRA_TXLUNF2_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_TXLUNF2_Pos)           /* (I2SMCC_IDRA) I2S Transmit Left 2 (x=0 only) or TDM Channel 2x Underrun Interrupt Disable Mask */
#define I2SMCC_IDRA_TXLUNF2(value)            (I2SMCC_IDRA_TXLUNF2_Msk & (_UINT32_(value) << I2SMCC_IDRA_TXLUNF2_Pos)) /* Assigment of value for TXLUNF2 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_TXRUNF2_Pos               _UINT32_(13)                                         /* (I2SMCC_IDRA) I2S Transmit Right 2 (x=0 only) or TDM Channel [2x]+1 Underrun Interrupt Disable Position */
#define I2SMCC_IDRA_TXRUNF2_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_TXRUNF2_Pos)           /* (I2SMCC_IDRA) I2S Transmit Right 2 (x=0 only) or TDM Channel [2x]+1 Underrun Interrupt Disable Mask */
#define I2SMCC_IDRA_TXRUNF2(value)            (I2SMCC_IDRA_TXRUNF2_Msk & (_UINT32_(value) << I2SMCC_IDRA_TXRUNF2_Pos)) /* Assigment of value for TXRUNF2 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_TXLUNF3_Pos               _UINT32_(14)                                         /* (I2SMCC_IDRA) I2S Transmit Left 3 (x=0 only) or TDM Channel 2x Underrun Interrupt Disable Position */
#define I2SMCC_IDRA_TXLUNF3_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_TXLUNF3_Pos)           /* (I2SMCC_IDRA) I2S Transmit Left 3 (x=0 only) or TDM Channel 2x Underrun Interrupt Disable Mask */
#define I2SMCC_IDRA_TXLUNF3(value)            (I2SMCC_IDRA_TXLUNF3_Msk & (_UINT32_(value) << I2SMCC_IDRA_TXLUNF3_Pos)) /* Assigment of value for TXLUNF3 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_TXRUNF3_Pos               _UINT32_(15)                                         /* (I2SMCC_IDRA) I2S Transmit Right 3 (x=0 only) or TDM Channel [2x]+1 Underrun Interrupt Disable Position */
#define I2SMCC_IDRA_TXRUNF3_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_TXRUNF3_Pos)           /* (I2SMCC_IDRA) I2S Transmit Right 3 (x=0 only) or TDM Channel [2x]+1 Underrun Interrupt Disable Mask */
#define I2SMCC_IDRA_TXRUNF3(value)            (I2SMCC_IDRA_TXRUNF3_Msk & (_UINT32_(value) << I2SMCC_IDRA_TXRUNF3_Pos)) /* Assigment of value for TXRUNF3 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_RXLRDY0_Pos               _UINT32_(16)                                         /* (I2SMCC_IDRA) I2S Receive Left 0 (x=0 only) or TDM Channel 2x Ready Interrupt Disable Position */
#define I2SMCC_IDRA_RXLRDY0_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_RXLRDY0_Pos)           /* (I2SMCC_IDRA) I2S Receive Left 0 (x=0 only) or TDM Channel 2x Ready Interrupt Disable Mask */
#define I2SMCC_IDRA_RXLRDY0(value)            (I2SMCC_IDRA_RXLRDY0_Msk & (_UINT32_(value) << I2SMCC_IDRA_RXLRDY0_Pos)) /* Assigment of value for RXLRDY0 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_RXRRDY0_Pos               _UINT32_(17)                                         /* (I2SMCC_IDRA) I2S Receive Right 0 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Disable Position */
#define I2SMCC_IDRA_RXRRDY0_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_RXRRDY0_Pos)           /* (I2SMCC_IDRA) I2S Receive Right 0 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Disable Mask */
#define I2SMCC_IDRA_RXRRDY0(value)            (I2SMCC_IDRA_RXRRDY0_Msk & (_UINT32_(value) << I2SMCC_IDRA_RXRRDY0_Pos)) /* Assigment of value for RXRRDY0 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_RXLRDY1_Pos               _UINT32_(18)                                         /* (I2SMCC_IDRA) I2S Receive Left 1 (x=0 only) or TDM Channel 2x Ready Interrupt Disable Position */
#define I2SMCC_IDRA_RXLRDY1_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_RXLRDY1_Pos)           /* (I2SMCC_IDRA) I2S Receive Left 1 (x=0 only) or TDM Channel 2x Ready Interrupt Disable Mask */
#define I2SMCC_IDRA_RXLRDY1(value)            (I2SMCC_IDRA_RXLRDY1_Msk & (_UINT32_(value) << I2SMCC_IDRA_RXLRDY1_Pos)) /* Assigment of value for RXLRDY1 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_RXRRDY1_Pos               _UINT32_(19)                                         /* (I2SMCC_IDRA) I2S Receive Right 1 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Disable Position */
#define I2SMCC_IDRA_RXRRDY1_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_RXRRDY1_Pos)           /* (I2SMCC_IDRA) I2S Receive Right 1 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Disable Mask */
#define I2SMCC_IDRA_RXRRDY1(value)            (I2SMCC_IDRA_RXRRDY1_Msk & (_UINT32_(value) << I2SMCC_IDRA_RXRRDY1_Pos)) /* Assigment of value for RXRRDY1 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_RXLRDY2_Pos               _UINT32_(20)                                         /* (I2SMCC_IDRA) I2S Receive Left 2 (x=0 only) or TDM Channel 2x Ready Interrupt Disable Position */
#define I2SMCC_IDRA_RXLRDY2_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_RXLRDY2_Pos)           /* (I2SMCC_IDRA) I2S Receive Left 2 (x=0 only) or TDM Channel 2x Ready Interrupt Disable Mask */
#define I2SMCC_IDRA_RXLRDY2(value)            (I2SMCC_IDRA_RXLRDY2_Msk & (_UINT32_(value) << I2SMCC_IDRA_RXLRDY2_Pos)) /* Assigment of value for RXLRDY2 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_RXRRDY2_Pos               _UINT32_(21)                                         /* (I2SMCC_IDRA) I2S Receive Right 2 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Disable Position */
#define I2SMCC_IDRA_RXRRDY2_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_RXRRDY2_Pos)           /* (I2SMCC_IDRA) I2S Receive Right 2 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Disable Mask */
#define I2SMCC_IDRA_RXRRDY2(value)            (I2SMCC_IDRA_RXRRDY2_Msk & (_UINT32_(value) << I2SMCC_IDRA_RXRRDY2_Pos)) /* Assigment of value for RXRRDY2 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_RXLRDY3_Pos               _UINT32_(22)                                         /* (I2SMCC_IDRA) I2S Receive Left 3 (x=0 only) or TDM Channel 2x Ready Interrupt Disable Position */
#define I2SMCC_IDRA_RXLRDY3_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_RXLRDY3_Pos)           /* (I2SMCC_IDRA) I2S Receive Left 3 (x=0 only) or TDM Channel 2x Ready Interrupt Disable Mask */
#define I2SMCC_IDRA_RXLRDY3(value)            (I2SMCC_IDRA_RXLRDY3_Msk & (_UINT32_(value) << I2SMCC_IDRA_RXLRDY3_Pos)) /* Assigment of value for RXLRDY3 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_RXRRDY3_Pos               _UINT32_(23)                                         /* (I2SMCC_IDRA) I2S Receive Right 3 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Disable Position */
#define I2SMCC_IDRA_RXRRDY3_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_RXRRDY3_Pos)           /* (I2SMCC_IDRA) I2S Receive Right 3 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Disable Mask */
#define I2SMCC_IDRA_RXRRDY3(value)            (I2SMCC_IDRA_RXRRDY3_Msk & (_UINT32_(value) << I2SMCC_IDRA_RXRRDY3_Pos)) /* Assigment of value for RXRRDY3 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_RXLOVF0_Pos               _UINT32_(24)                                         /* (I2SMCC_IDRA) I2S Receive Left 0 (x=0 only) or TDM Channel 2x Overrun Interrupt Disable Position */
#define I2SMCC_IDRA_RXLOVF0_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_RXLOVF0_Pos)           /* (I2SMCC_IDRA) I2S Receive Left 0 (x=0 only) or TDM Channel 2x Overrun Interrupt Disable Mask */
#define I2SMCC_IDRA_RXLOVF0(value)            (I2SMCC_IDRA_RXLOVF0_Msk & (_UINT32_(value) << I2SMCC_IDRA_RXLOVF0_Pos)) /* Assigment of value for RXLOVF0 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_RXROVF0_Pos               _UINT32_(25)                                         /* (I2SMCC_IDRA) I2S Receive Right 0 (x=0 only) or TDM Channel [2x]+1 Overrun Interrupt Disable Position */
#define I2SMCC_IDRA_RXROVF0_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_RXROVF0_Pos)           /* (I2SMCC_IDRA) I2S Receive Right 0 (x=0 only) or TDM Channel [2x]+1 Overrun Interrupt Disable Mask */
#define I2SMCC_IDRA_RXROVF0(value)            (I2SMCC_IDRA_RXROVF0_Msk & (_UINT32_(value) << I2SMCC_IDRA_RXROVF0_Pos)) /* Assigment of value for RXROVF0 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_RXLOVF1_Pos               _UINT32_(26)                                         /* (I2SMCC_IDRA) I2S Receive Left 1 (x=0 only) or TDM Channel 2x Overrun Interrupt Disable Position */
#define I2SMCC_IDRA_RXLOVF1_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_RXLOVF1_Pos)           /* (I2SMCC_IDRA) I2S Receive Left 1 (x=0 only) or TDM Channel 2x Overrun Interrupt Disable Mask */
#define I2SMCC_IDRA_RXLOVF1(value)            (I2SMCC_IDRA_RXLOVF1_Msk & (_UINT32_(value) << I2SMCC_IDRA_RXLOVF1_Pos)) /* Assigment of value for RXLOVF1 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_RXROVF1_Pos               _UINT32_(27)                                         /* (I2SMCC_IDRA) I2S Receive Right 1 (x=0 only) or TDM Channel [2x]+1 Overrun Interrupt Disable Position */
#define I2SMCC_IDRA_RXROVF1_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_RXROVF1_Pos)           /* (I2SMCC_IDRA) I2S Receive Right 1 (x=0 only) or TDM Channel [2x]+1 Overrun Interrupt Disable Mask */
#define I2SMCC_IDRA_RXROVF1(value)            (I2SMCC_IDRA_RXROVF1_Msk & (_UINT32_(value) << I2SMCC_IDRA_RXROVF1_Pos)) /* Assigment of value for RXROVF1 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_RXLOVF2_Pos               _UINT32_(28)                                         /* (I2SMCC_IDRA) I2S Receive Left 2 (x=0 only) or TDM Channel 2x Overrun Interrupt Disable Position */
#define I2SMCC_IDRA_RXLOVF2_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_RXLOVF2_Pos)           /* (I2SMCC_IDRA) I2S Receive Left 2 (x=0 only) or TDM Channel 2x Overrun Interrupt Disable Mask */
#define I2SMCC_IDRA_RXLOVF2(value)            (I2SMCC_IDRA_RXLOVF2_Msk & (_UINT32_(value) << I2SMCC_IDRA_RXLOVF2_Pos)) /* Assigment of value for RXLOVF2 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_RXROVF2_Pos               _UINT32_(29)                                         /* (I2SMCC_IDRA) I2S Receive Right 2 (x=0 only) or TDM Channel [2x]+1 Overrun Interrupt Disable Position */
#define I2SMCC_IDRA_RXROVF2_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_RXROVF2_Pos)           /* (I2SMCC_IDRA) I2S Receive Right 2 (x=0 only) or TDM Channel [2x]+1 Overrun Interrupt Disable Mask */
#define I2SMCC_IDRA_RXROVF2(value)            (I2SMCC_IDRA_RXROVF2_Msk & (_UINT32_(value) << I2SMCC_IDRA_RXROVF2_Pos)) /* Assigment of value for RXROVF2 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_RXLOVF3_Pos               _UINT32_(30)                                         /* (I2SMCC_IDRA) I2S Receive Left 3 (x=0 only) or TDM Channel 2x Overrun Interrupt Disable Position */
#define I2SMCC_IDRA_RXLOVF3_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_RXLOVF3_Pos)           /* (I2SMCC_IDRA) I2S Receive Left 3 (x=0 only) or TDM Channel 2x Overrun Interrupt Disable Mask */
#define I2SMCC_IDRA_RXLOVF3(value)            (I2SMCC_IDRA_RXLOVF3_Msk & (_UINT32_(value) << I2SMCC_IDRA_RXLOVF3_Pos)) /* Assigment of value for RXLOVF3 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_RXROVF3_Pos               _UINT32_(31)                                         /* (I2SMCC_IDRA) I2S Receive Right 3 (x=0 only) or TDM Channel [2x]+1 Overrun Interrupt Disable Position */
#define I2SMCC_IDRA_RXROVF3_Msk               (_UINT32_(0x1) << I2SMCC_IDRA_RXROVF3_Pos)           /* (I2SMCC_IDRA) I2S Receive Right 3 (x=0 only) or TDM Channel [2x]+1 Overrun Interrupt Disable Mask */
#define I2SMCC_IDRA_RXROVF3(value)            (I2SMCC_IDRA_RXROVF3_Msk & (_UINT32_(value) << I2SMCC_IDRA_RXROVF3_Pos)) /* Assigment of value for RXROVF3 in the I2SMCC_IDRA register */
#define I2SMCC_IDRA_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (I2SMCC_IDRA) Register Mask  */


/* -------- I2SMCC_IMRA : (I2SMCC Offset: 0x18) ( R/ 32) Interrupt Mask Register A -------- */
#define I2SMCC_IMRA_TXLRDY0_Pos               _UINT32_(0)                                          /* (I2SMCC_IMRA) I2S Transmit Left 0 (x=0 only) or TDM Channel 2x Ready Interrupt Mask Position */
#define I2SMCC_IMRA_TXLRDY0_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_TXLRDY0_Pos)           /* (I2SMCC_IMRA) I2S Transmit Left 0 (x=0 only) or TDM Channel 2x Ready Interrupt Mask Mask */
#define I2SMCC_IMRA_TXLRDY0(value)            (I2SMCC_IMRA_TXLRDY0_Msk & (_UINT32_(value) << I2SMCC_IMRA_TXLRDY0_Pos)) /* Assigment of value for TXLRDY0 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_TXRRDY0_Pos               _UINT32_(1)                                          /* (I2SMCC_IMRA) I2S Transmit Right 0 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Mask Position */
#define I2SMCC_IMRA_TXRRDY0_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_TXRRDY0_Pos)           /* (I2SMCC_IMRA) I2S Transmit Right 0 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Mask Mask */
#define I2SMCC_IMRA_TXRRDY0(value)            (I2SMCC_IMRA_TXRRDY0_Msk & (_UINT32_(value) << I2SMCC_IMRA_TXRRDY0_Pos)) /* Assigment of value for TXRRDY0 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_TXLRDY1_Pos               _UINT32_(2)                                          /* (I2SMCC_IMRA) I2S Transmit Left 1 (x=0 only) or TDM Channel 2x Ready Interrupt Mask Position */
#define I2SMCC_IMRA_TXLRDY1_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_TXLRDY1_Pos)           /* (I2SMCC_IMRA) I2S Transmit Left 1 (x=0 only) or TDM Channel 2x Ready Interrupt Mask Mask */
#define I2SMCC_IMRA_TXLRDY1(value)            (I2SMCC_IMRA_TXLRDY1_Msk & (_UINT32_(value) << I2SMCC_IMRA_TXLRDY1_Pos)) /* Assigment of value for TXLRDY1 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_TXRRDY1_Pos               _UINT32_(3)                                          /* (I2SMCC_IMRA) I2S Transmit Right 1 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Mask Position */
#define I2SMCC_IMRA_TXRRDY1_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_TXRRDY1_Pos)           /* (I2SMCC_IMRA) I2S Transmit Right 1 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Mask Mask */
#define I2SMCC_IMRA_TXRRDY1(value)            (I2SMCC_IMRA_TXRRDY1_Msk & (_UINT32_(value) << I2SMCC_IMRA_TXRRDY1_Pos)) /* Assigment of value for TXRRDY1 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_TXLRDY2_Pos               _UINT32_(4)                                          /* (I2SMCC_IMRA) I2S Transmit Left 2 (x=0 only) or TDM Channel 2x Ready Interrupt Mask Position */
#define I2SMCC_IMRA_TXLRDY2_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_TXLRDY2_Pos)           /* (I2SMCC_IMRA) I2S Transmit Left 2 (x=0 only) or TDM Channel 2x Ready Interrupt Mask Mask */
#define I2SMCC_IMRA_TXLRDY2(value)            (I2SMCC_IMRA_TXLRDY2_Msk & (_UINT32_(value) << I2SMCC_IMRA_TXLRDY2_Pos)) /* Assigment of value for TXLRDY2 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_TXRRDY2_Pos               _UINT32_(5)                                          /* (I2SMCC_IMRA) I2S Transmit Right 2 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Mask Position */
#define I2SMCC_IMRA_TXRRDY2_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_TXRRDY2_Pos)           /* (I2SMCC_IMRA) I2S Transmit Right 2 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Mask Mask */
#define I2SMCC_IMRA_TXRRDY2(value)            (I2SMCC_IMRA_TXRRDY2_Msk & (_UINT32_(value) << I2SMCC_IMRA_TXRRDY2_Pos)) /* Assigment of value for TXRRDY2 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_TXLRDY3_Pos               _UINT32_(6)                                          /* (I2SMCC_IMRA) I2S Transmit Left 3 (x=0 only) or TDM Channel 2x Ready Interrupt Mask Position */
#define I2SMCC_IMRA_TXLRDY3_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_TXLRDY3_Pos)           /* (I2SMCC_IMRA) I2S Transmit Left 3 (x=0 only) or TDM Channel 2x Ready Interrupt Mask Mask */
#define I2SMCC_IMRA_TXLRDY3(value)            (I2SMCC_IMRA_TXLRDY3_Msk & (_UINT32_(value) << I2SMCC_IMRA_TXLRDY3_Pos)) /* Assigment of value for TXLRDY3 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_TXRRDY3_Pos               _UINT32_(7)                                          /* (I2SMCC_IMRA) I2S Transmit Right 3 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Mask Position */
#define I2SMCC_IMRA_TXRRDY3_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_TXRRDY3_Pos)           /* (I2SMCC_IMRA) I2S Transmit Right 3 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Mask Mask */
#define I2SMCC_IMRA_TXRRDY3(value)            (I2SMCC_IMRA_TXRRDY3_Msk & (_UINT32_(value) << I2SMCC_IMRA_TXRRDY3_Pos)) /* Assigment of value for TXRRDY3 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_TXLUNF0_Pos               _UINT32_(8)                                          /* (I2SMCC_IMRA) I2S Transmit Left 0 (x=0 only) or TDM Channel 2x Underrun Interrupt Mask Position */
#define I2SMCC_IMRA_TXLUNF0_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_TXLUNF0_Pos)           /* (I2SMCC_IMRA) I2S Transmit Left 0 (x=0 only) or TDM Channel 2x Underrun Interrupt Mask Mask */
#define I2SMCC_IMRA_TXLUNF0(value)            (I2SMCC_IMRA_TXLUNF0_Msk & (_UINT32_(value) << I2SMCC_IMRA_TXLUNF0_Pos)) /* Assigment of value for TXLUNF0 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_TXRUNF0_Pos               _UINT32_(9)                                          /* (I2SMCC_IMRA) I2S Transmit Right 0 (x=0 only) or TDM Channel [2x]+1 Underrun Interrupt Mask Position */
#define I2SMCC_IMRA_TXRUNF0_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_TXRUNF0_Pos)           /* (I2SMCC_IMRA) I2S Transmit Right 0 (x=0 only) or TDM Channel [2x]+1 Underrun Interrupt Mask Mask */
#define I2SMCC_IMRA_TXRUNF0(value)            (I2SMCC_IMRA_TXRUNF0_Msk & (_UINT32_(value) << I2SMCC_IMRA_TXRUNF0_Pos)) /* Assigment of value for TXRUNF0 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_TXLUNF1_Pos               _UINT32_(10)                                         /* (I2SMCC_IMRA) I2S Transmit Left 1 (x=0 only) or TDM Channel 2x Underrun Interrupt Mask Position */
#define I2SMCC_IMRA_TXLUNF1_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_TXLUNF1_Pos)           /* (I2SMCC_IMRA) I2S Transmit Left 1 (x=0 only) or TDM Channel 2x Underrun Interrupt Mask Mask */
#define I2SMCC_IMRA_TXLUNF1(value)            (I2SMCC_IMRA_TXLUNF1_Msk & (_UINT32_(value) << I2SMCC_IMRA_TXLUNF1_Pos)) /* Assigment of value for TXLUNF1 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_TXRUNF1_Pos               _UINT32_(11)                                         /* (I2SMCC_IMRA) I2S Transmit Right 1 (x=0 only) or TDM Channel [2x]+1 Underrun Interrupt Mask Position */
#define I2SMCC_IMRA_TXRUNF1_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_TXRUNF1_Pos)           /* (I2SMCC_IMRA) I2S Transmit Right 1 (x=0 only) or TDM Channel [2x]+1 Underrun Interrupt Mask Mask */
#define I2SMCC_IMRA_TXRUNF1(value)            (I2SMCC_IMRA_TXRUNF1_Msk & (_UINT32_(value) << I2SMCC_IMRA_TXRUNF1_Pos)) /* Assigment of value for TXRUNF1 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_TXLUNF2_Pos               _UINT32_(12)                                         /* (I2SMCC_IMRA) I2S Transmit Left 2 (x=0 only) or TDM Channel 2x Underrun Interrupt Mask Position */
#define I2SMCC_IMRA_TXLUNF2_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_TXLUNF2_Pos)           /* (I2SMCC_IMRA) I2S Transmit Left 2 (x=0 only) or TDM Channel 2x Underrun Interrupt Mask Mask */
#define I2SMCC_IMRA_TXLUNF2(value)            (I2SMCC_IMRA_TXLUNF2_Msk & (_UINT32_(value) << I2SMCC_IMRA_TXLUNF2_Pos)) /* Assigment of value for TXLUNF2 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_TXRUNF2_Pos               _UINT32_(13)                                         /* (I2SMCC_IMRA) I2S Transmit Right 2 (x=0 only) or TDM Channel [2x]+1 Underrun Interrupt Mask Position */
#define I2SMCC_IMRA_TXRUNF2_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_TXRUNF2_Pos)           /* (I2SMCC_IMRA) I2S Transmit Right 2 (x=0 only) or TDM Channel [2x]+1 Underrun Interrupt Mask Mask */
#define I2SMCC_IMRA_TXRUNF2(value)            (I2SMCC_IMRA_TXRUNF2_Msk & (_UINT32_(value) << I2SMCC_IMRA_TXRUNF2_Pos)) /* Assigment of value for TXRUNF2 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_TXLUNF3_Pos               _UINT32_(14)                                         /* (I2SMCC_IMRA) I2S Transmit Left 3 (x=0 only) or TDM Channel 2x Underrun Interrupt Mask Position */
#define I2SMCC_IMRA_TXLUNF3_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_TXLUNF3_Pos)           /* (I2SMCC_IMRA) I2S Transmit Left 3 (x=0 only) or TDM Channel 2x Underrun Interrupt Mask Mask */
#define I2SMCC_IMRA_TXLUNF3(value)            (I2SMCC_IMRA_TXLUNF3_Msk & (_UINT32_(value) << I2SMCC_IMRA_TXLUNF3_Pos)) /* Assigment of value for TXLUNF3 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_TXRUNF3_Pos               _UINT32_(15)                                         /* (I2SMCC_IMRA) I2S Transmit Right 3 (x=0 only) or TDM Channel [2x]+1 Underrun Interrupt Mask Position */
#define I2SMCC_IMRA_TXRUNF3_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_TXRUNF3_Pos)           /* (I2SMCC_IMRA) I2S Transmit Right 3 (x=0 only) or TDM Channel [2x]+1 Underrun Interrupt Mask Mask */
#define I2SMCC_IMRA_TXRUNF3(value)            (I2SMCC_IMRA_TXRUNF3_Msk & (_UINT32_(value) << I2SMCC_IMRA_TXRUNF3_Pos)) /* Assigment of value for TXRUNF3 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_RXLRDY0_Pos               _UINT32_(16)                                         /* (I2SMCC_IMRA) I2S Receive Left 0 (x=0 only) or TDM Channel 2x Ready Interrupt Mask Position */
#define I2SMCC_IMRA_RXLRDY0_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_RXLRDY0_Pos)           /* (I2SMCC_IMRA) I2S Receive Left 0 (x=0 only) or TDM Channel 2x Ready Interrupt Mask Mask */
#define I2SMCC_IMRA_RXLRDY0(value)            (I2SMCC_IMRA_RXLRDY0_Msk & (_UINT32_(value) << I2SMCC_IMRA_RXLRDY0_Pos)) /* Assigment of value for RXLRDY0 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_RXRRDY0_Pos               _UINT32_(17)                                         /* (I2SMCC_IMRA) I2S Receive Right 0 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Mask Position */
#define I2SMCC_IMRA_RXRRDY0_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_RXRRDY0_Pos)           /* (I2SMCC_IMRA) I2S Receive Right 0 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Mask Mask */
#define I2SMCC_IMRA_RXRRDY0(value)            (I2SMCC_IMRA_RXRRDY0_Msk & (_UINT32_(value) << I2SMCC_IMRA_RXRRDY0_Pos)) /* Assigment of value for RXRRDY0 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_RXLRDY1_Pos               _UINT32_(18)                                         /* (I2SMCC_IMRA) I2S Receive Left 1 (x=0 only) or TDM Channel 2x Ready Interrupt Mask Position */
#define I2SMCC_IMRA_RXLRDY1_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_RXLRDY1_Pos)           /* (I2SMCC_IMRA) I2S Receive Left 1 (x=0 only) or TDM Channel 2x Ready Interrupt Mask Mask */
#define I2SMCC_IMRA_RXLRDY1(value)            (I2SMCC_IMRA_RXLRDY1_Msk & (_UINT32_(value) << I2SMCC_IMRA_RXLRDY1_Pos)) /* Assigment of value for RXLRDY1 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_RXRRDY1_Pos               _UINT32_(19)                                         /* (I2SMCC_IMRA) I2S Receive Right 1 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Mask Position */
#define I2SMCC_IMRA_RXRRDY1_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_RXRRDY1_Pos)           /* (I2SMCC_IMRA) I2S Receive Right 1 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Mask Mask */
#define I2SMCC_IMRA_RXRRDY1(value)            (I2SMCC_IMRA_RXRRDY1_Msk & (_UINT32_(value) << I2SMCC_IMRA_RXRRDY1_Pos)) /* Assigment of value for RXRRDY1 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_RXLRDY2_Pos               _UINT32_(20)                                         /* (I2SMCC_IMRA) I2S Receive Left 2 (x=0 only) or TDM Channel 2x Ready Interrupt Mask Position */
#define I2SMCC_IMRA_RXLRDY2_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_RXLRDY2_Pos)           /* (I2SMCC_IMRA) I2S Receive Left 2 (x=0 only) or TDM Channel 2x Ready Interrupt Mask Mask */
#define I2SMCC_IMRA_RXLRDY2(value)            (I2SMCC_IMRA_RXLRDY2_Msk & (_UINT32_(value) << I2SMCC_IMRA_RXLRDY2_Pos)) /* Assigment of value for RXLRDY2 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_RXRRDY2_Pos               _UINT32_(21)                                         /* (I2SMCC_IMRA) I2S Receive Right 2 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Mask Position */
#define I2SMCC_IMRA_RXRRDY2_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_RXRRDY2_Pos)           /* (I2SMCC_IMRA) I2S Receive Right 2 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Mask Mask */
#define I2SMCC_IMRA_RXRRDY2(value)            (I2SMCC_IMRA_RXRRDY2_Msk & (_UINT32_(value) << I2SMCC_IMRA_RXRRDY2_Pos)) /* Assigment of value for RXRRDY2 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_RXLRDY3_Pos               _UINT32_(22)                                         /* (I2SMCC_IMRA) I2S Receive Left 3 (x=0 only) or TDM Channel 2x Ready Interrupt Mask Position */
#define I2SMCC_IMRA_RXLRDY3_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_RXLRDY3_Pos)           /* (I2SMCC_IMRA) I2S Receive Left 3 (x=0 only) or TDM Channel 2x Ready Interrupt Mask Mask */
#define I2SMCC_IMRA_RXLRDY3(value)            (I2SMCC_IMRA_RXLRDY3_Msk & (_UINT32_(value) << I2SMCC_IMRA_RXLRDY3_Pos)) /* Assigment of value for RXLRDY3 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_RXRRDY3_Pos               _UINT32_(23)                                         /* (I2SMCC_IMRA) I2S Receive Right 3 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Mask Position */
#define I2SMCC_IMRA_RXRRDY3_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_RXRRDY3_Pos)           /* (I2SMCC_IMRA) I2S Receive Right 3 (x=0 only) or TDM Channel [2x]+1 Ready Interrupt Mask Mask */
#define I2SMCC_IMRA_RXRRDY3(value)            (I2SMCC_IMRA_RXRRDY3_Msk & (_UINT32_(value) << I2SMCC_IMRA_RXRRDY3_Pos)) /* Assigment of value for RXRRDY3 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_RXLOVF0_Pos               _UINT32_(24)                                         /* (I2SMCC_IMRA) I2S Receive Left 0 (x=0 only) or TDM Channel 2x Overrun Interrupt Mask Position */
#define I2SMCC_IMRA_RXLOVF0_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_RXLOVF0_Pos)           /* (I2SMCC_IMRA) I2S Receive Left 0 (x=0 only) or TDM Channel 2x Overrun Interrupt Mask Mask */
#define I2SMCC_IMRA_RXLOVF0(value)            (I2SMCC_IMRA_RXLOVF0_Msk & (_UINT32_(value) << I2SMCC_IMRA_RXLOVF0_Pos)) /* Assigment of value for RXLOVF0 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_RXROVF0_Pos               _UINT32_(25)                                         /* (I2SMCC_IMRA) I2S Receive Right 0 (x=0 only) or TDM Channel [2x]+1 Overrun Interrupt Mask Position */
#define I2SMCC_IMRA_RXROVF0_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_RXROVF0_Pos)           /* (I2SMCC_IMRA) I2S Receive Right 0 (x=0 only) or TDM Channel [2x]+1 Overrun Interrupt Mask Mask */
#define I2SMCC_IMRA_RXROVF0(value)            (I2SMCC_IMRA_RXROVF0_Msk & (_UINT32_(value) << I2SMCC_IMRA_RXROVF0_Pos)) /* Assigment of value for RXROVF0 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_RXLOVF1_Pos               _UINT32_(26)                                         /* (I2SMCC_IMRA) I2S Receive Left 1 (x=0 only) or TDM Channel 2x Overrun Interrupt Mask Position */
#define I2SMCC_IMRA_RXLOVF1_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_RXLOVF1_Pos)           /* (I2SMCC_IMRA) I2S Receive Left 1 (x=0 only) or TDM Channel 2x Overrun Interrupt Mask Mask */
#define I2SMCC_IMRA_RXLOVF1(value)            (I2SMCC_IMRA_RXLOVF1_Msk & (_UINT32_(value) << I2SMCC_IMRA_RXLOVF1_Pos)) /* Assigment of value for RXLOVF1 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_RXROVF1_Pos               _UINT32_(27)                                         /* (I2SMCC_IMRA) I2S Receive Right 1 (x=0 only) or TDM Channel [2x]+1 Overrun Interrupt Mask Position */
#define I2SMCC_IMRA_RXROVF1_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_RXROVF1_Pos)           /* (I2SMCC_IMRA) I2S Receive Right 1 (x=0 only) or TDM Channel [2x]+1 Overrun Interrupt Mask Mask */
#define I2SMCC_IMRA_RXROVF1(value)            (I2SMCC_IMRA_RXROVF1_Msk & (_UINT32_(value) << I2SMCC_IMRA_RXROVF1_Pos)) /* Assigment of value for RXROVF1 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_RXLOVF2_Pos               _UINT32_(28)                                         /* (I2SMCC_IMRA) I2S Receive Left 2 (x=0 only) or TDM Channel 2x Overrun Interrupt Mask Position */
#define I2SMCC_IMRA_RXLOVF2_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_RXLOVF2_Pos)           /* (I2SMCC_IMRA) I2S Receive Left 2 (x=0 only) or TDM Channel 2x Overrun Interrupt Mask Mask */
#define I2SMCC_IMRA_RXLOVF2(value)            (I2SMCC_IMRA_RXLOVF2_Msk & (_UINT32_(value) << I2SMCC_IMRA_RXLOVF2_Pos)) /* Assigment of value for RXLOVF2 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_RXROVF2_Pos               _UINT32_(29)                                         /* (I2SMCC_IMRA) I2S Receive Right 2 (x=0 only) or TDM Channel [2x]+1 Overrun Interrupt Mask Position */
#define I2SMCC_IMRA_RXROVF2_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_RXROVF2_Pos)           /* (I2SMCC_IMRA) I2S Receive Right 2 (x=0 only) or TDM Channel [2x]+1 Overrun Interrupt Mask Mask */
#define I2SMCC_IMRA_RXROVF2(value)            (I2SMCC_IMRA_RXROVF2_Msk & (_UINT32_(value) << I2SMCC_IMRA_RXROVF2_Pos)) /* Assigment of value for RXROVF2 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_RXLOVF3_Pos               _UINT32_(30)                                         /* (I2SMCC_IMRA) I2S Receive Left 3 (x=0 only) or TDM Channel 2x Overrun Interrupt Mask Position */
#define I2SMCC_IMRA_RXLOVF3_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_RXLOVF3_Pos)           /* (I2SMCC_IMRA) I2S Receive Left 3 (x=0 only) or TDM Channel 2x Overrun Interrupt Mask Mask */
#define I2SMCC_IMRA_RXLOVF3(value)            (I2SMCC_IMRA_RXLOVF3_Msk & (_UINT32_(value) << I2SMCC_IMRA_RXLOVF3_Pos)) /* Assigment of value for RXLOVF3 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_RXROVF3_Pos               _UINT32_(31)                                         /* (I2SMCC_IMRA) I2S Receive Right 3 (x=0 only) or TDM Channel [2x]+1 Overrun Interrupt Mask Position */
#define I2SMCC_IMRA_RXROVF3_Msk               (_UINT32_(0x1) << I2SMCC_IMRA_RXROVF3_Pos)           /* (I2SMCC_IMRA) I2S Receive Right 3 (x=0 only) or TDM Channel [2x]+1 Overrun Interrupt Mask Mask */
#define I2SMCC_IMRA_RXROVF3(value)            (I2SMCC_IMRA_RXROVF3_Msk & (_UINT32_(value) << I2SMCC_IMRA_RXROVF3_Pos)) /* Assigment of value for RXROVF3 in the I2SMCC_IMRA register */
#define I2SMCC_IMRA_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (I2SMCC_IMRA) Register Mask  */


/* -------- I2SMCC_ISRA : (I2SMCC Offset: 0x1C) ( R/ 32) Interrupt Status Register A -------- */
#define I2SMCC_ISRA_TXLRDY0_Pos               _UINT32_(0)                                          /* (I2SMCC_ISRA) I2S Transmit Left 0 (x=0 only) or TDM Channel 2x Ready Flag (Cleared by writing I2SMCC_THR) Position */
#define I2SMCC_ISRA_TXLRDY0_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_TXLRDY0_Pos)           /* (I2SMCC_ISRA) I2S Transmit Left 0 (x=0 only) or TDM Channel 2x Ready Flag (Cleared by writing I2SMCC_THR) Mask */
#define I2SMCC_ISRA_TXLRDY0(value)            (I2SMCC_ISRA_TXLRDY0_Msk & (_UINT32_(value) << I2SMCC_ISRA_TXLRDY0_Pos)) /* Assigment of value for TXLRDY0 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_TXRRDY0_Pos               _UINT32_(1)                                          /* (I2SMCC_ISRA) I2S Transmit Right 0 (x=0 only) or TDM Channel [2x]+1 Ready Flag (Cleared by writing I2SMCC_THR) Position */
#define I2SMCC_ISRA_TXRRDY0_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_TXRRDY0_Pos)           /* (I2SMCC_ISRA) I2S Transmit Right 0 (x=0 only) or TDM Channel [2x]+1 Ready Flag (Cleared by writing I2SMCC_THR) Mask */
#define I2SMCC_ISRA_TXRRDY0(value)            (I2SMCC_ISRA_TXRRDY0_Msk & (_UINT32_(value) << I2SMCC_ISRA_TXRRDY0_Pos)) /* Assigment of value for TXRRDY0 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_TXLRDY1_Pos               _UINT32_(2)                                          /* (I2SMCC_ISRA) I2S Transmit Left 1 (x=0 only) or TDM Channel 2x Ready Flag (Cleared by writing I2SMCC_THR) Position */
#define I2SMCC_ISRA_TXLRDY1_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_TXLRDY1_Pos)           /* (I2SMCC_ISRA) I2S Transmit Left 1 (x=0 only) or TDM Channel 2x Ready Flag (Cleared by writing I2SMCC_THR) Mask */
#define I2SMCC_ISRA_TXLRDY1(value)            (I2SMCC_ISRA_TXLRDY1_Msk & (_UINT32_(value) << I2SMCC_ISRA_TXLRDY1_Pos)) /* Assigment of value for TXLRDY1 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_TXRRDY1_Pos               _UINT32_(3)                                          /* (I2SMCC_ISRA) I2S Transmit Right 1 (x=0 only) or TDM Channel [2x]+1 Ready Flag (Cleared by writing I2SMCC_THR) Position */
#define I2SMCC_ISRA_TXRRDY1_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_TXRRDY1_Pos)           /* (I2SMCC_ISRA) I2S Transmit Right 1 (x=0 only) or TDM Channel [2x]+1 Ready Flag (Cleared by writing I2SMCC_THR) Mask */
#define I2SMCC_ISRA_TXRRDY1(value)            (I2SMCC_ISRA_TXRRDY1_Msk & (_UINT32_(value) << I2SMCC_ISRA_TXRRDY1_Pos)) /* Assigment of value for TXRRDY1 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_TXLRDY2_Pos               _UINT32_(4)                                          /* (I2SMCC_ISRA) I2S Transmit Left 2 (x=0 only) or TDM Channel 2x Ready Flag (Cleared by writing I2SMCC_THR) Position */
#define I2SMCC_ISRA_TXLRDY2_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_TXLRDY2_Pos)           /* (I2SMCC_ISRA) I2S Transmit Left 2 (x=0 only) or TDM Channel 2x Ready Flag (Cleared by writing I2SMCC_THR) Mask */
#define I2SMCC_ISRA_TXLRDY2(value)            (I2SMCC_ISRA_TXLRDY2_Msk & (_UINT32_(value) << I2SMCC_ISRA_TXLRDY2_Pos)) /* Assigment of value for TXLRDY2 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_TXRRDY2_Pos               _UINT32_(5)                                          /* (I2SMCC_ISRA) I2S Transmit Right 2 (x=0 only) or TDM Channel [2x]+1 Ready Flag (Cleared by writing I2SMCC_THR) Position */
#define I2SMCC_ISRA_TXRRDY2_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_TXRRDY2_Pos)           /* (I2SMCC_ISRA) I2S Transmit Right 2 (x=0 only) or TDM Channel [2x]+1 Ready Flag (Cleared by writing I2SMCC_THR) Mask */
#define I2SMCC_ISRA_TXRRDY2(value)            (I2SMCC_ISRA_TXRRDY2_Msk & (_UINT32_(value) << I2SMCC_ISRA_TXRRDY2_Pos)) /* Assigment of value for TXRRDY2 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_TXLRDY3_Pos               _UINT32_(6)                                          /* (I2SMCC_ISRA) I2S Transmit Left 3 (x=0 only) or TDM Channel 2x Ready Flag (Cleared by writing I2SMCC_THR) Position */
#define I2SMCC_ISRA_TXLRDY3_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_TXLRDY3_Pos)           /* (I2SMCC_ISRA) I2S Transmit Left 3 (x=0 only) or TDM Channel 2x Ready Flag (Cleared by writing I2SMCC_THR) Mask */
#define I2SMCC_ISRA_TXLRDY3(value)            (I2SMCC_ISRA_TXLRDY3_Msk & (_UINT32_(value) << I2SMCC_ISRA_TXLRDY3_Pos)) /* Assigment of value for TXLRDY3 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_TXRRDY3_Pos               _UINT32_(7)                                          /* (I2SMCC_ISRA) I2S Transmit Right 3 (x=0 only) or TDM Channel [2x]+1 Ready Flag (Cleared by writing I2SMCC_THR) Position */
#define I2SMCC_ISRA_TXRRDY3_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_TXRRDY3_Pos)           /* (I2SMCC_ISRA) I2S Transmit Right 3 (x=0 only) or TDM Channel [2x]+1 Ready Flag (Cleared by writing I2SMCC_THR) Mask */
#define I2SMCC_ISRA_TXRRDY3(value)            (I2SMCC_ISRA_TXRRDY3_Msk & (_UINT32_(value) << I2SMCC_ISRA_TXRRDY3_Pos)) /* Assigment of value for TXRRDY3 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_TXLUNF0_Pos               _UINT32_(8)                                          /* (I2SMCC_ISRA) I2S Transmit Left 0 (x=0 only) or TDM Channel 2x Underrun (Cleared on read) Position */
#define I2SMCC_ISRA_TXLUNF0_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_TXLUNF0_Pos)           /* (I2SMCC_ISRA) I2S Transmit Left 0 (x=0 only) or TDM Channel 2x Underrun (Cleared on read) Mask */
#define I2SMCC_ISRA_TXLUNF0(value)            (I2SMCC_ISRA_TXLUNF0_Msk & (_UINT32_(value) << I2SMCC_ISRA_TXLUNF0_Pos)) /* Assigment of value for TXLUNF0 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_TXRUNF0_Pos               _UINT32_(9)                                          /* (I2SMCC_ISRA) I2S Transmit Right 0 (x=0 only) or TDM Channel [2x]+1 Underrun Flag (Cleared on read) Position */
#define I2SMCC_ISRA_TXRUNF0_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_TXRUNF0_Pos)           /* (I2SMCC_ISRA) I2S Transmit Right 0 (x=0 only) or TDM Channel [2x]+1 Underrun Flag (Cleared on read) Mask */
#define I2SMCC_ISRA_TXRUNF0(value)            (I2SMCC_ISRA_TXRUNF0_Msk & (_UINT32_(value) << I2SMCC_ISRA_TXRUNF0_Pos)) /* Assigment of value for TXRUNF0 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_TXLUNF1_Pos               _UINT32_(10)                                         /* (I2SMCC_ISRA) I2S Transmit Left 1 (x=0 only) or TDM Channel 2x Underrun (Cleared on read) Position */
#define I2SMCC_ISRA_TXLUNF1_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_TXLUNF1_Pos)           /* (I2SMCC_ISRA) I2S Transmit Left 1 (x=0 only) or TDM Channel 2x Underrun (Cleared on read) Mask */
#define I2SMCC_ISRA_TXLUNF1(value)            (I2SMCC_ISRA_TXLUNF1_Msk & (_UINT32_(value) << I2SMCC_ISRA_TXLUNF1_Pos)) /* Assigment of value for TXLUNF1 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_TXRUNF1_Pos               _UINT32_(11)                                         /* (I2SMCC_ISRA) I2S Transmit Right 1 (x=0 only) or TDM Channel [2x]+1 Underrun Flag (Cleared on read) Position */
#define I2SMCC_ISRA_TXRUNF1_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_TXRUNF1_Pos)           /* (I2SMCC_ISRA) I2S Transmit Right 1 (x=0 only) or TDM Channel [2x]+1 Underrun Flag (Cleared on read) Mask */
#define I2SMCC_ISRA_TXRUNF1(value)            (I2SMCC_ISRA_TXRUNF1_Msk & (_UINT32_(value) << I2SMCC_ISRA_TXRUNF1_Pos)) /* Assigment of value for TXRUNF1 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_TXLUNF2_Pos               _UINT32_(12)                                         /* (I2SMCC_ISRA) I2S Transmit Left 2 (x=0 only) or TDM Channel 2x Underrun (Cleared on read) Position */
#define I2SMCC_ISRA_TXLUNF2_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_TXLUNF2_Pos)           /* (I2SMCC_ISRA) I2S Transmit Left 2 (x=0 only) or TDM Channel 2x Underrun (Cleared on read) Mask */
#define I2SMCC_ISRA_TXLUNF2(value)            (I2SMCC_ISRA_TXLUNF2_Msk & (_UINT32_(value) << I2SMCC_ISRA_TXLUNF2_Pos)) /* Assigment of value for TXLUNF2 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_TXRUNF2_Pos               _UINT32_(13)                                         /* (I2SMCC_ISRA) I2S Transmit Right 2 (x=0 only) or TDM Channel [2x]+1 Underrun Flag (Cleared on read) Position */
#define I2SMCC_ISRA_TXRUNF2_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_TXRUNF2_Pos)           /* (I2SMCC_ISRA) I2S Transmit Right 2 (x=0 only) or TDM Channel [2x]+1 Underrun Flag (Cleared on read) Mask */
#define I2SMCC_ISRA_TXRUNF2(value)            (I2SMCC_ISRA_TXRUNF2_Msk & (_UINT32_(value) << I2SMCC_ISRA_TXRUNF2_Pos)) /* Assigment of value for TXRUNF2 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_TXLUNF3_Pos               _UINT32_(14)                                         /* (I2SMCC_ISRA) I2S Transmit Left 3 (x=0 only) or TDM Channel 2x Underrun (Cleared on read) Position */
#define I2SMCC_ISRA_TXLUNF3_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_TXLUNF3_Pos)           /* (I2SMCC_ISRA) I2S Transmit Left 3 (x=0 only) or TDM Channel 2x Underrun (Cleared on read) Mask */
#define I2SMCC_ISRA_TXLUNF3(value)            (I2SMCC_ISRA_TXLUNF3_Msk & (_UINT32_(value) << I2SMCC_ISRA_TXLUNF3_Pos)) /* Assigment of value for TXLUNF3 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_TXRUNF3_Pos               _UINT32_(15)                                         /* (I2SMCC_ISRA) I2S Transmit Right 3 (x=0 only) or TDM Channel [2x]+1 Underrun Flag (Cleared on read) Position */
#define I2SMCC_ISRA_TXRUNF3_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_TXRUNF3_Pos)           /* (I2SMCC_ISRA) I2S Transmit Right 3 (x=0 only) or TDM Channel [2x]+1 Underrun Flag (Cleared on read) Mask */
#define I2SMCC_ISRA_TXRUNF3(value)            (I2SMCC_ISRA_TXRUNF3_Msk & (_UINT32_(value) << I2SMCC_ISRA_TXRUNF3_Pos)) /* Assigment of value for TXRUNF3 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_RXLRDY0_Pos               _UINT32_(16)                                         /* (I2SMCC_ISRA) I2S Receive Left 0 (x=0 only) or TDM Channel 2x Ready Flag (Cleared by reading I2SMCC_RHR) Position */
#define I2SMCC_ISRA_RXLRDY0_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_RXLRDY0_Pos)           /* (I2SMCC_ISRA) I2S Receive Left 0 (x=0 only) or TDM Channel 2x Ready Flag (Cleared by reading I2SMCC_RHR) Mask */
#define I2SMCC_ISRA_RXLRDY0(value)            (I2SMCC_ISRA_RXLRDY0_Msk & (_UINT32_(value) << I2SMCC_ISRA_RXLRDY0_Pos)) /* Assigment of value for RXLRDY0 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_RXRRDY0_Pos               _UINT32_(17)                                         /* (I2SMCC_ISRA) I2S Receive Right 0 (x=0 only) or TDM Channel [2x]+1 Ready Flag (Cleared by reading I2SMCC_RHR) Position */
#define I2SMCC_ISRA_RXRRDY0_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_RXRRDY0_Pos)           /* (I2SMCC_ISRA) I2S Receive Right 0 (x=0 only) or TDM Channel [2x]+1 Ready Flag (Cleared by reading I2SMCC_RHR) Mask */
#define I2SMCC_ISRA_RXRRDY0(value)            (I2SMCC_ISRA_RXRRDY0_Msk & (_UINT32_(value) << I2SMCC_ISRA_RXRRDY0_Pos)) /* Assigment of value for RXRRDY0 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_RXLRDY1_Pos               _UINT32_(18)                                         /* (I2SMCC_ISRA) I2S Receive Left 1 (x=0 only) or TDM Channel 2x Ready Flag (Cleared by reading I2SMCC_RHR) Position */
#define I2SMCC_ISRA_RXLRDY1_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_RXLRDY1_Pos)           /* (I2SMCC_ISRA) I2S Receive Left 1 (x=0 only) or TDM Channel 2x Ready Flag (Cleared by reading I2SMCC_RHR) Mask */
#define I2SMCC_ISRA_RXLRDY1(value)            (I2SMCC_ISRA_RXLRDY1_Msk & (_UINT32_(value) << I2SMCC_ISRA_RXLRDY1_Pos)) /* Assigment of value for RXLRDY1 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_RXRRDY1_Pos               _UINT32_(19)                                         /* (I2SMCC_ISRA) I2S Receive Right 1 (x=0 only) or TDM Channel [2x]+1 Ready Flag (Cleared by reading I2SMCC_RHR) Position */
#define I2SMCC_ISRA_RXRRDY1_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_RXRRDY1_Pos)           /* (I2SMCC_ISRA) I2S Receive Right 1 (x=0 only) or TDM Channel [2x]+1 Ready Flag (Cleared by reading I2SMCC_RHR) Mask */
#define I2SMCC_ISRA_RXRRDY1(value)            (I2SMCC_ISRA_RXRRDY1_Msk & (_UINT32_(value) << I2SMCC_ISRA_RXRRDY1_Pos)) /* Assigment of value for RXRRDY1 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_RXLRDY2_Pos               _UINT32_(20)                                         /* (I2SMCC_ISRA) I2S Receive Left 2 (x=0 only) or TDM Channel 2x Ready Flag (Cleared by reading I2SMCC_RHR) Position */
#define I2SMCC_ISRA_RXLRDY2_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_RXLRDY2_Pos)           /* (I2SMCC_ISRA) I2S Receive Left 2 (x=0 only) or TDM Channel 2x Ready Flag (Cleared by reading I2SMCC_RHR) Mask */
#define I2SMCC_ISRA_RXLRDY2(value)            (I2SMCC_ISRA_RXLRDY2_Msk & (_UINT32_(value) << I2SMCC_ISRA_RXLRDY2_Pos)) /* Assigment of value for RXLRDY2 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_RXRRDY2_Pos               _UINT32_(21)                                         /* (I2SMCC_ISRA) I2S Receive Right 2 (x=0 only) or TDM Channel [2x]+1 Ready Flag (Cleared by reading I2SMCC_RHR) Position */
#define I2SMCC_ISRA_RXRRDY2_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_RXRRDY2_Pos)           /* (I2SMCC_ISRA) I2S Receive Right 2 (x=0 only) or TDM Channel [2x]+1 Ready Flag (Cleared by reading I2SMCC_RHR) Mask */
#define I2SMCC_ISRA_RXRRDY2(value)            (I2SMCC_ISRA_RXRRDY2_Msk & (_UINT32_(value) << I2SMCC_ISRA_RXRRDY2_Pos)) /* Assigment of value for RXRRDY2 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_RXLRDY3_Pos               _UINT32_(22)                                         /* (I2SMCC_ISRA) I2S Receive Left 3 (x=0 only) or TDM Channel 2x Ready Flag (Cleared by reading I2SMCC_RHR) Position */
#define I2SMCC_ISRA_RXLRDY3_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_RXLRDY3_Pos)           /* (I2SMCC_ISRA) I2S Receive Left 3 (x=0 only) or TDM Channel 2x Ready Flag (Cleared by reading I2SMCC_RHR) Mask */
#define I2SMCC_ISRA_RXLRDY3(value)            (I2SMCC_ISRA_RXLRDY3_Msk & (_UINT32_(value) << I2SMCC_ISRA_RXLRDY3_Pos)) /* Assigment of value for RXLRDY3 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_RXRRDY3_Pos               _UINT32_(23)                                         /* (I2SMCC_ISRA) I2S Receive Right 3 (x=0 only) or TDM Channel [2x]+1 Ready Flag (Cleared by reading I2SMCC_RHR) Position */
#define I2SMCC_ISRA_RXRRDY3_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_RXRRDY3_Pos)           /* (I2SMCC_ISRA) I2S Receive Right 3 (x=0 only) or TDM Channel [2x]+1 Ready Flag (Cleared by reading I2SMCC_RHR) Mask */
#define I2SMCC_ISRA_RXRRDY3(value)            (I2SMCC_ISRA_RXRRDY3_Msk & (_UINT32_(value) << I2SMCC_ISRA_RXRRDY3_Pos)) /* Assigment of value for RXRRDY3 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_RXLOVF0_Pos               _UINT32_(24)                                         /* (I2SMCC_ISRA) I2S Receive Left 0 (x=0 only) or TDM Channel 2x Overrun Flag (Cleared on read) Position */
#define I2SMCC_ISRA_RXLOVF0_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_RXLOVF0_Pos)           /* (I2SMCC_ISRA) I2S Receive Left 0 (x=0 only) or TDM Channel 2x Overrun Flag (Cleared on read) Mask */
#define I2SMCC_ISRA_RXLOVF0(value)            (I2SMCC_ISRA_RXLOVF0_Msk & (_UINT32_(value) << I2SMCC_ISRA_RXLOVF0_Pos)) /* Assigment of value for RXLOVF0 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_RXROVF0_Pos               _UINT32_(25)                                         /* (I2SMCC_ISRA) I2S Receive Right 0 (x=0 only) or TDM Channel [2x]+1 Overrun Flag (Cleared on read) Position */
#define I2SMCC_ISRA_RXROVF0_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_RXROVF0_Pos)           /* (I2SMCC_ISRA) I2S Receive Right 0 (x=0 only) or TDM Channel [2x]+1 Overrun Flag (Cleared on read) Mask */
#define I2SMCC_ISRA_RXROVF0(value)            (I2SMCC_ISRA_RXROVF0_Msk & (_UINT32_(value) << I2SMCC_ISRA_RXROVF0_Pos)) /* Assigment of value for RXROVF0 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_RXLOVF1_Pos               _UINT32_(26)                                         /* (I2SMCC_ISRA) I2S Receive Left 1 (x=0 only) or TDM Channel 2x Overrun Flag (Cleared on read) Position */
#define I2SMCC_ISRA_RXLOVF1_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_RXLOVF1_Pos)           /* (I2SMCC_ISRA) I2S Receive Left 1 (x=0 only) or TDM Channel 2x Overrun Flag (Cleared on read) Mask */
#define I2SMCC_ISRA_RXLOVF1(value)            (I2SMCC_ISRA_RXLOVF1_Msk & (_UINT32_(value) << I2SMCC_ISRA_RXLOVF1_Pos)) /* Assigment of value for RXLOVF1 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_RXROVF1_Pos               _UINT32_(27)                                         /* (I2SMCC_ISRA) I2S Receive Right 1 (x=0 only) or TDM Channel [2x]+1 Overrun Flag (Cleared on read) Position */
#define I2SMCC_ISRA_RXROVF1_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_RXROVF1_Pos)           /* (I2SMCC_ISRA) I2S Receive Right 1 (x=0 only) or TDM Channel [2x]+1 Overrun Flag (Cleared on read) Mask */
#define I2SMCC_ISRA_RXROVF1(value)            (I2SMCC_ISRA_RXROVF1_Msk & (_UINT32_(value) << I2SMCC_ISRA_RXROVF1_Pos)) /* Assigment of value for RXROVF1 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_RXLOVF2_Pos               _UINT32_(28)                                         /* (I2SMCC_ISRA) I2S Receive Left 2 (x=0 only) or TDM Channel 2x Overrun Flag (Cleared on read) Position */
#define I2SMCC_ISRA_RXLOVF2_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_RXLOVF2_Pos)           /* (I2SMCC_ISRA) I2S Receive Left 2 (x=0 only) or TDM Channel 2x Overrun Flag (Cleared on read) Mask */
#define I2SMCC_ISRA_RXLOVF2(value)            (I2SMCC_ISRA_RXLOVF2_Msk & (_UINT32_(value) << I2SMCC_ISRA_RXLOVF2_Pos)) /* Assigment of value for RXLOVF2 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_RXROVF2_Pos               _UINT32_(29)                                         /* (I2SMCC_ISRA) I2S Receive Right 2 (x=0 only) or TDM Channel [2x]+1 Overrun Flag (Cleared on read) Position */
#define I2SMCC_ISRA_RXROVF2_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_RXROVF2_Pos)           /* (I2SMCC_ISRA) I2S Receive Right 2 (x=0 only) or TDM Channel [2x]+1 Overrun Flag (Cleared on read) Mask */
#define I2SMCC_ISRA_RXROVF2(value)            (I2SMCC_ISRA_RXROVF2_Msk & (_UINT32_(value) << I2SMCC_ISRA_RXROVF2_Pos)) /* Assigment of value for RXROVF2 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_RXLOVF3_Pos               _UINT32_(30)                                         /* (I2SMCC_ISRA) I2S Receive Left 3 (x=0 only) or TDM Channel 2x Overrun Flag (Cleared on read) Position */
#define I2SMCC_ISRA_RXLOVF3_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_RXLOVF3_Pos)           /* (I2SMCC_ISRA) I2S Receive Left 3 (x=0 only) or TDM Channel 2x Overrun Flag (Cleared on read) Mask */
#define I2SMCC_ISRA_RXLOVF3(value)            (I2SMCC_ISRA_RXLOVF3_Msk & (_UINT32_(value) << I2SMCC_ISRA_RXLOVF3_Pos)) /* Assigment of value for RXLOVF3 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_RXROVF3_Pos               _UINT32_(31)                                         /* (I2SMCC_ISRA) I2S Receive Right 3 (x=0 only) or TDM Channel [2x]+1 Overrun Flag (Cleared on read) Position */
#define I2SMCC_ISRA_RXROVF3_Msk               (_UINT32_(0x1) << I2SMCC_ISRA_RXROVF3_Pos)           /* (I2SMCC_ISRA) I2S Receive Right 3 (x=0 only) or TDM Channel [2x]+1 Overrun Flag (Cleared on read) Mask */
#define I2SMCC_ISRA_RXROVF3(value)            (I2SMCC_ISRA_RXROVF3_Msk & (_UINT32_(value) << I2SMCC_ISRA_RXROVF3_Pos)) /* Assigment of value for RXROVF3 in the I2SMCC_ISRA register */
#define I2SMCC_ISRA_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (I2SMCC_ISRA) Register Mask  */


/* -------- I2SMCC_IERB : (I2SMCC Offset: 0x20) ( /W 32) Interrupt Enable Register B -------- */
#define I2SMCC_IERB_WERR_Pos                  _UINT32_(0)                                          /* (I2SMCC_IERB) Write Error Interrupt Enable Position */
#define I2SMCC_IERB_WERR_Msk                  (_UINT32_(0x1) << I2SMCC_IERB_WERR_Pos)              /* (I2SMCC_IERB) Write Error Interrupt Enable Mask */
#define I2SMCC_IERB_WERR(value)               (I2SMCC_IERB_WERR_Msk & (_UINT32_(value) << I2SMCC_IERB_WERR_Pos)) /* Assigment of value for WERR in the I2SMCC_IERB register */
#define I2SMCC_IERB_Msk                       _UINT32_(0x00000001)                                 /* (I2SMCC_IERB) Register Mask  */


/* -------- I2SMCC_IDRB : (I2SMCC Offset: 0x24) ( /W 32) Interrupt Disable Register B -------- */
#define I2SMCC_IDRB_WERR_Pos                  _UINT32_(0)                                          /* (I2SMCC_IDRB) Write Error Interrupt Disable Position */
#define I2SMCC_IDRB_WERR_Msk                  (_UINT32_(0x1) << I2SMCC_IDRB_WERR_Pos)              /* (I2SMCC_IDRB) Write Error Interrupt Disable Mask */
#define I2SMCC_IDRB_WERR(value)               (I2SMCC_IDRB_WERR_Msk & (_UINT32_(value) << I2SMCC_IDRB_WERR_Pos)) /* Assigment of value for WERR in the I2SMCC_IDRB register */
#define I2SMCC_IDRB_Msk                       _UINT32_(0x00000001)                                 /* (I2SMCC_IDRB) Register Mask  */


/* -------- I2SMCC_IMRB : (I2SMCC Offset: 0x28) ( R/ 32) Interrupt Mask Register B -------- */
#define I2SMCC_IMRB_WERR_Pos                  _UINT32_(0)                                          /* (I2SMCC_IMRB) Write Error Interrupt Enable Position */
#define I2SMCC_IMRB_WERR_Msk                  (_UINT32_(0x1) << I2SMCC_IMRB_WERR_Pos)              /* (I2SMCC_IMRB) Write Error Interrupt Enable Mask */
#define I2SMCC_IMRB_WERR(value)               (I2SMCC_IMRB_WERR_Msk & (_UINT32_(value) << I2SMCC_IMRB_WERR_Pos)) /* Assigment of value for WERR in the I2SMCC_IMRB register */
#define I2SMCC_IMRB_Msk                       _UINT32_(0x00000001)                                 /* (I2SMCC_IMRB) Register Mask  */


/* -------- I2SMCC_ISRB : (I2SMCC Offset: 0x2C) ( R/ 32) Interrupt Status Register B -------- */
#define I2SMCC_ISRB_WERR_Pos                  _UINT32_(0)                                          /* (I2SMCC_ISRB) Write Error Flag (cleared on read) Position */
#define I2SMCC_ISRB_WERR_Msk                  (_UINT32_(0x1) << I2SMCC_ISRB_WERR_Pos)              /* (I2SMCC_ISRB) Write Error Flag (cleared on read) Mask */
#define I2SMCC_ISRB_WERR(value)               (I2SMCC_ISRB_WERR_Msk & (_UINT32_(value) << I2SMCC_ISRB_WERR_Pos)) /* Assigment of value for WERR in the I2SMCC_ISRB register */
#define I2SMCC_ISRB_Msk                       _UINT32_(0x00000001)                                 /* (I2SMCC_ISRB) Register Mask  */


/* -------- I2SMCC_RHR : (I2SMCC Offset: 0x30) ( R/ 32) Receiver Holding Register -------- */
#define I2SMCC_RHR_RHR_Pos                    _UINT32_(0)                                          /* (I2SMCC_RHR) Receiver Holding Register Position */
#define I2SMCC_RHR_RHR_Msk                    (_UINT32_(0xFFFFFFFF) << I2SMCC_RHR_RHR_Pos)         /* (I2SMCC_RHR) Receiver Holding Register Mask */
#define I2SMCC_RHR_RHR(value)                 (I2SMCC_RHR_RHR_Msk & (_UINT32_(value) << I2SMCC_RHR_RHR_Pos)) /* Assigment of value for RHR in the I2SMCC_RHR register */
#define I2SMCC_RHR_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (I2SMCC_RHR) Register Mask  */


/* -------- I2SMCC_THR : (I2SMCC Offset: 0x34) ( /W 32) Transmitter Holding Register -------- */
#define I2SMCC_THR_THR_Pos                    _UINT32_(0)                                          /* (I2SMCC_THR) Transmitter Holding Register Position */
#define I2SMCC_THR_THR_Msk                    (_UINT32_(0xFFFFFFFF) << I2SMCC_THR_THR_Pos)         /* (I2SMCC_THR) Transmitter Holding Register Mask */
#define I2SMCC_THR_THR(value)                 (I2SMCC_THR_THR_Msk & (_UINT32_(value) << I2SMCC_THR_THR_Pos)) /* Assigment of value for THR in the I2SMCC_THR register */
#define I2SMCC_THR_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (I2SMCC_THR) Register Mask  */


/* -------- I2SMCC_WPMR : (I2SMCC Offset: 0xE4) (R/W 32) Write Protection Mode Register -------- */
#define I2SMCC_WPMR_WPCFEN_Pos                _UINT32_(0)                                          /* (I2SMCC_WPMR) Write Protection Configuration Enable Position */
#define I2SMCC_WPMR_WPCFEN_Msk                (_UINT32_(0x1) << I2SMCC_WPMR_WPCFEN_Pos)            /* (I2SMCC_WPMR) Write Protection Configuration Enable Mask */
#define I2SMCC_WPMR_WPCFEN(value)             (I2SMCC_WPMR_WPCFEN_Msk & (_UINT32_(value) << I2SMCC_WPMR_WPCFEN_Pos)) /* Assigment of value for WPCFEN in the I2SMCC_WPMR register */
#define I2SMCC_WPMR_WPITEN_Pos                _UINT32_(1)                                          /* (I2SMCC_WPMR) Write Protection Interrupt Enable Position */
#define I2SMCC_WPMR_WPITEN_Msk                (_UINT32_(0x1) << I2SMCC_WPMR_WPITEN_Pos)            /* (I2SMCC_WPMR) Write Protection Interrupt Enable Mask */
#define I2SMCC_WPMR_WPITEN(value)             (I2SMCC_WPMR_WPITEN_Msk & (_UINT32_(value) << I2SMCC_WPMR_WPITEN_Pos)) /* Assigment of value for WPITEN in the I2SMCC_WPMR register */
#define I2SMCC_WPMR_WPCTEN_Pos                _UINT32_(2)                                          /* (I2SMCC_WPMR) Write Protection Control Enable Position */
#define I2SMCC_WPMR_WPCTEN_Msk                (_UINT32_(0x1) << I2SMCC_WPMR_WPCTEN_Pos)            /* (I2SMCC_WPMR) Write Protection Control Enable Mask */
#define I2SMCC_WPMR_WPCTEN(value)             (I2SMCC_WPMR_WPCTEN_Msk & (_UINT32_(value) << I2SMCC_WPMR_WPCTEN_Pos)) /* Assigment of value for WPCTEN in the I2SMCC_WPMR register */
#define I2SMCC_WPMR_WPKEY_Pos                 _UINT32_(8)                                          /* (I2SMCC_WPMR) Write Protection Key Position */
#define I2SMCC_WPMR_WPKEY_Msk                 (_UINT32_(0xFFFFFF) << I2SMCC_WPMR_WPKEY_Pos)        /* (I2SMCC_WPMR) Write Protection Key Mask */
#define I2SMCC_WPMR_WPKEY(value)              (I2SMCC_WPMR_WPKEY_Msk & (_UINT32_(value) << I2SMCC_WPMR_WPKEY_Pos)) /* Assigment of value for WPKEY in the I2SMCC_WPMR register */
#define   I2SMCC_WPMR_WPKEY_PASSWD_Val        _UINT32_(0x493253)                                   /* (I2SMCC_WPMR) Writing any other value in this field aborts the write operation. Always reads as 0.  */
#define I2SMCC_WPMR_WPKEY_PASSWD              (I2SMCC_WPMR_WPKEY_PASSWD_Val << I2SMCC_WPMR_WPKEY_Pos) /* (I2SMCC_WPMR) Writing any other value in this field aborts the write operation. Always reads as 0. Position  */
#define I2SMCC_WPMR_Msk                       _UINT32_(0xFFFFFF07)                                 /* (I2SMCC_WPMR) Register Mask  */


/* -------- I2SMCC_WPSR : (I2SMCC Offset: 0xE8) ( R/ 32) Write Protection Status Register -------- */
#define I2SMCC_WPSR_WPVS_Pos                  _UINT32_(0)                                          /* (I2SMCC_WPSR) Write Protection Violation Status Position */
#define I2SMCC_WPSR_WPVS_Msk                  (_UINT32_(0x1) << I2SMCC_WPSR_WPVS_Pos)              /* (I2SMCC_WPSR) Write Protection Violation Status Mask */
#define I2SMCC_WPSR_WPVS(value)               (I2SMCC_WPSR_WPVS_Msk & (_UINT32_(value) << I2SMCC_WPSR_WPVS_Pos)) /* Assigment of value for WPVS in the I2SMCC_WPSR register */
#define I2SMCC_WPSR_WPVSRC_Pos                _UINT32_(8)                                          /* (I2SMCC_WPSR) Write Protection Violation Source Position */
#define I2SMCC_WPSR_WPVSRC_Msk                (_UINT32_(0xFFFFFF) << I2SMCC_WPSR_WPVSRC_Pos)       /* (I2SMCC_WPSR) Write Protection Violation Source Mask */
#define I2SMCC_WPSR_WPVSRC(value)             (I2SMCC_WPSR_WPVSRC_Msk & (_UINT32_(value) << I2SMCC_WPSR_WPVSRC_Pos)) /* Assigment of value for WPVSRC in the I2SMCC_WPSR register */
#define I2SMCC_WPSR_Msk                       _UINT32_(0xFFFFFF01)                                 /* (I2SMCC_WPSR) Register Mask  */


/** \brief I2SMCC register offsets definitions */
#define I2SMCC_CR_REG_OFST             _UINT32_(0x00)      /* (I2SMCC_CR) Control Register Offset */
#define I2SMCC_MRA_REG_OFST            _UINT32_(0x04)      /* (I2SMCC_MRA) Mode Register A Offset */
#define I2SMCC_MRB_REG_OFST            _UINT32_(0x08)      /* (I2SMCC_MRB) Mode Register B Offset */
#define I2SMCC_SR_REG_OFST             _UINT32_(0x0C)      /* (I2SMCC_SR) Status Register Offset */
#define I2SMCC_IERA_REG_OFST           _UINT32_(0x10)      /* (I2SMCC_IERA) Interrupt Enable Register A Offset */
#define I2SMCC_IDRA_REG_OFST           _UINT32_(0x14)      /* (I2SMCC_IDRA) Interrupt Disable Register A Offset */
#define I2SMCC_IMRA_REG_OFST           _UINT32_(0x18)      /* (I2SMCC_IMRA) Interrupt Mask Register A Offset */
#define I2SMCC_ISRA_REG_OFST           _UINT32_(0x1C)      /* (I2SMCC_ISRA) Interrupt Status Register A Offset */
#define I2SMCC_IERB_REG_OFST           _UINT32_(0x20)      /* (I2SMCC_IERB) Interrupt Enable Register B Offset */
#define I2SMCC_IDRB_REG_OFST           _UINT32_(0x24)      /* (I2SMCC_IDRB) Interrupt Disable Register B Offset */
#define I2SMCC_IMRB_REG_OFST           _UINT32_(0x28)      /* (I2SMCC_IMRB) Interrupt Mask Register B Offset */
#define I2SMCC_ISRB_REG_OFST           _UINT32_(0x2C)      /* (I2SMCC_ISRB) Interrupt Status Register B Offset */
#define I2SMCC_RHR_REG_OFST            _UINT32_(0x30)      /* (I2SMCC_RHR) Receiver Holding Register Offset */
#define I2SMCC_THR_REG_OFST            _UINT32_(0x34)      /* (I2SMCC_THR) Transmitter Holding Register Offset */
#define I2SMCC_WPMR_REG_OFST           _UINT32_(0xE4)      /* (I2SMCC_WPMR) Write Protection Mode Register Offset */
#define I2SMCC_WPSR_REG_OFST           _UINT32_(0xE8)      /* (I2SMCC_WPSR) Write Protection Status Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief I2SMCC register API structure */
typedef struct
{
  __O   uint32_t                       I2SMCC_CR;          /**< Offset: 0x00 ( /W  32) Control Register */
  __IO  uint32_t                       I2SMCC_MRA;         /**< Offset: 0x04 (R/W  32) Mode Register A */
  __IO  uint32_t                       I2SMCC_MRB;         /**< Offset: 0x08 (R/W  32) Mode Register B */
  __I   uint32_t                       I2SMCC_SR;          /**< Offset: 0x0C (R/   32) Status Register */
  __O   uint32_t                       I2SMCC_IERA;        /**< Offset: 0x10 ( /W  32) Interrupt Enable Register A */
  __O   uint32_t                       I2SMCC_IDRA;        /**< Offset: 0x14 ( /W  32) Interrupt Disable Register A */
  __I   uint32_t                       I2SMCC_IMRA;        /**< Offset: 0x18 (R/   32) Interrupt Mask Register A */
  __I   uint32_t                       I2SMCC_ISRA;        /**< Offset: 0x1C (R/   32) Interrupt Status Register A */
  __O   uint32_t                       I2SMCC_IERB;        /**< Offset: 0x20 ( /W  32) Interrupt Enable Register B */
  __O   uint32_t                       I2SMCC_IDRB;        /**< Offset: 0x24 ( /W  32) Interrupt Disable Register B */
  __I   uint32_t                       I2SMCC_IMRB;        /**< Offset: 0x28 (R/   32) Interrupt Mask Register B */
  __I   uint32_t                       I2SMCC_ISRB;        /**< Offset: 0x2C (R/   32) Interrupt Status Register B */
  __I   uint32_t                       I2SMCC_RHR;         /**< Offset: 0x30 (R/   32) Receiver Holding Register */
  __O   uint32_t                       I2SMCC_THR;         /**< Offset: 0x34 ( /W  32) Transmitter Holding Register */
  __I   uint8_t                        Reserved1[0xAC];
  __IO  uint32_t                       I2SMCC_WPMR;        /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
  __I   uint32_t                       I2SMCC_WPSR;        /**< Offset: 0xE8 (R/   32) Write Protection Status Register */
} i2smcc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAM9X_I2SMCC_COMPONENT_H_ */
