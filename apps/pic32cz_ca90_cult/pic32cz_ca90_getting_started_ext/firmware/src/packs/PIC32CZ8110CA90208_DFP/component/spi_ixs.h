/*
 * Component description for SPI_IXS
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
#ifndef _PIC32CZCA90_SPI_IXS_COMPONENT_H_
#define _PIC32CZCA90_SPI_IXS_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR SPI_IXS                                      */
/* ************************************************************************** */

/* -------- SPI_IXS_CTRLA : (SPI_IXS Offset: 0x00) (R/W 32) SPI Control Enable Register -------- */
#define SPI_IXS_CTRLA_RESETVALUE              _UINT32_(0x00)                                       /*  (SPI_IXS_CTRLA) SPI Control Enable Register  Reset Value */

#define SPI_IXS_CTRLA_SWRST_Pos               _UINT32_(0)                                          /* (SPI_IXS_CTRLA) SPI Software Reset Position */
#define SPI_IXS_CTRLA_SWRST_Msk               (_UINT32_(0x1) << SPI_IXS_CTRLA_SWRST_Pos)           /* (SPI_IXS_CTRLA) SPI Software Reset Mask */
#define SPI_IXS_CTRLA_SWRST(value)            (SPI_IXS_CTRLA_SWRST_Msk & (_UINT32_(value) << SPI_IXS_CTRLA_SWRST_Pos)) /* Assigment of value for SWRST in the SPI_IXS_CTRLA register */
#define SPI_IXS_CTRLA_ENABLE_Pos              _UINT32_(1)                                          /* (SPI_IXS_CTRLA) SPI Enable (ON) bit Position */
#define SPI_IXS_CTRLA_ENABLE_Msk              (_UINT32_(0x1) << SPI_IXS_CTRLA_ENABLE_Pos)          /* (SPI_IXS_CTRLA) SPI Enable (ON) bit Mask */
#define SPI_IXS_CTRLA_ENABLE(value)           (SPI_IXS_CTRLA_ENABLE_Msk & (_UINT32_(value) << SPI_IXS_CTRLA_ENABLE_Pos)) /* Assigment of value for ENABLE in the SPI_IXS_CTRLA register */
#define SPI_IXS_CTRLA_RUNSTDBY_Pos            _UINT32_(6)                                          /* (SPI_IXS_CTRLA) RUN STANDBY Mode Enable bit Position */
#define SPI_IXS_CTRLA_RUNSTDBY_Msk            (_UINT32_(0x1) << SPI_IXS_CTRLA_RUNSTDBY_Pos)        /* (SPI_IXS_CTRLA) RUN STANDBY Mode Enable bit Mask */
#define SPI_IXS_CTRLA_RUNSTDBY(value)         (SPI_IXS_CTRLA_RUNSTDBY_Msk & (_UINT32_(value) << SPI_IXS_CTRLA_RUNSTDBY_Pos)) /* Assigment of value for RUNSTDBY in the SPI_IXS_CTRLA register */
#define SPI_IXS_CTRLA_Msk                     _UINT32_(0x00000043)                                 /* (SPI_IXS_CTRLA) Register Mask  */


/* -------- SPI_IXS_SELCTRL : (SPI_IXS Offset: 0x04) (R/W 32) SPI Control Options Select Register -------- */
#define SPI_IXS_SELCTRL_RESETVALUE            _UINT32_(0x00)                                       /*  (SPI_IXS_SELCTRL) SPI Control Options Select Register  Reset Value */

#define SPI_IXS_SELCTRL_CLKINDLY_Pos          _UINT32_(0)                                          /* (SPI_IXS_SELCTRL) Serial Clock Input Delay for SDI sampling Position */
#define SPI_IXS_SELCTRL_CLKINDLY_Msk          (_UINT32_(0x3) << SPI_IXS_SELCTRL_CLKINDLY_Pos)      /* (SPI_IXS_SELCTRL) Serial Clock Input Delay for SDI sampling Mask */
#define SPI_IXS_SELCTRL_CLKINDLY(value)       (SPI_IXS_SELCTRL_CLKINDLY_Msk & (_UINT32_(value) << SPI_IXS_SELCTRL_CLKINDLY_Pos)) /* Assigment of value for CLKINDLY in the SPI_IXS_SELCTRL register */
#define   SPI_IXS_SELCTRL_CLKINDLY_TDLY0_Val  _UINT32_(0x0)                                        /* (SPI_IXS_SELCTRL) 0 Tap Delays  */
#define   SPI_IXS_SELCTRL_CLKINDLY_TDLY1_Val  _UINT32_(0x1)                                        /* (SPI_IXS_SELCTRL) 1 Tap Delay  */
#define   SPI_IXS_SELCTRL_CLKINDLY_TDLY2_Val  _UINT32_(0x2)                                        /* (SPI_IXS_SELCTRL) 2 Tap Delay  */
#define   SPI_IXS_SELCTRL_CLKINDLY_TDLY3_Val  _UINT32_(0x3)                                        /* (SPI_IXS_SELCTRL) 3 Tap Delay  */
#define SPI_IXS_SELCTRL_CLKINDLY_TDLY0        (SPI_IXS_SELCTRL_CLKINDLY_TDLY0_Val << SPI_IXS_SELCTRL_CLKINDLY_Pos) /* (SPI_IXS_SELCTRL) 0 Tap Delays Position  */
#define SPI_IXS_SELCTRL_CLKINDLY_TDLY1        (SPI_IXS_SELCTRL_CLKINDLY_TDLY1_Val << SPI_IXS_SELCTRL_CLKINDLY_Pos) /* (SPI_IXS_SELCTRL) 1 Tap Delay Position  */
#define SPI_IXS_SELCTRL_CLKINDLY_TDLY2        (SPI_IXS_SELCTRL_CLKINDLY_TDLY2_Val << SPI_IXS_SELCTRL_CLKINDLY_Pos) /* (SPI_IXS_SELCTRL) 2 Tap Delay Position  */
#define SPI_IXS_SELCTRL_CLKINDLY_TDLY3        (SPI_IXS_SELCTRL_CLKINDLY_TDLY3_Val << SPI_IXS_SELCTRL_CLKINDLY_Pos) /* (SPI_IXS_SELCTRL) 3 Tap Delay Position  */
#define SPI_IXS_SELCTRL_SRXISEL_Pos           _UINT32_(4)                                          /* (SPI_IXS_SELCTRL) SPI Receive Service Request Interrupt Select Position */
#define SPI_IXS_SELCTRL_SRXISEL_Msk           (_UINT32_(0x3) << SPI_IXS_SELCTRL_SRXISEL_Pos)       /* (SPI_IXS_SELCTRL) SPI Receive Service Request Interrupt Select Mask */
#define SPI_IXS_SELCTRL_SRXISEL(value)        (SPI_IXS_SELCTRL_SRXISEL_Msk & (_UINT32_(value) << SPI_IXS_SELCTRL_SRXISEL_Pos)) /* Assigment of value for SRXISEL in the SPI_IXS_SELCTRL register */
#define   SPI_IXS_SELCTRL_SRXISEL_RXBEMPTY_Val _UINT32_(0x0)                                        /* (SPI_IXS_SELCTRL) RXB Empty  */
#define   SPI_IXS_SELCTRL_SRXISEL_RXBNEMPTY_Val _UINT32_(0x1)                                        /* (SPI_IXS_SELCTRL) RXB Not Empty  */
#define   SPI_IXS_SELCTRL_SRXISEL_RXBHFULL_Val _UINT32_(0x2)                                        /* (SPI_IXS_SELCTRL) RXB Half Full  */
#define   SPI_IXS_SELCTRL_SRXISEL_RXBFULL_Val _UINT32_(0x3)                                        /* (SPI_IXS_SELCTRL) RXB Full  */
#define SPI_IXS_SELCTRL_SRXISEL_RXBEMPTY      (SPI_IXS_SELCTRL_SRXISEL_RXBEMPTY_Val << SPI_IXS_SELCTRL_SRXISEL_Pos) /* (SPI_IXS_SELCTRL) RXB Empty Position  */
#define SPI_IXS_SELCTRL_SRXISEL_RXBNEMPTY     (SPI_IXS_SELCTRL_SRXISEL_RXBNEMPTY_Val << SPI_IXS_SELCTRL_SRXISEL_Pos) /* (SPI_IXS_SELCTRL) RXB Not Empty Position  */
#define SPI_IXS_SELCTRL_SRXISEL_RXBHFULL      (SPI_IXS_SELCTRL_SRXISEL_RXBHFULL_Val << SPI_IXS_SELCTRL_SRXISEL_Pos) /* (SPI_IXS_SELCTRL) RXB Half Full Position  */
#define SPI_IXS_SELCTRL_SRXISEL_RXBFULL       (SPI_IXS_SELCTRL_SRXISEL_RXBFULL_Val << SPI_IXS_SELCTRL_SRXISEL_Pos) /* (SPI_IXS_SELCTRL) RXB Full Position  */
#define SPI_IXS_SELCTRL_IGNROV_Pos            _UINT32_(6)                                          /* (SPI_IXS_SELCTRL) Ignore Receive Overflow (for Audio Data Transmissions) Position */
#define SPI_IXS_SELCTRL_IGNROV_Msk            (_UINT32_(0x1) << SPI_IXS_SELCTRL_IGNROV_Pos)        /* (SPI_IXS_SELCTRL) Ignore Receive Overflow (for Audio Data Transmissions) Mask */
#define SPI_IXS_SELCTRL_IGNROV(value)         (SPI_IXS_SELCTRL_IGNROV_Msk & (_UINT32_(value) << SPI_IXS_SELCTRL_IGNROV_Pos)) /* Assigment of value for IGNROV in the SPI_IXS_SELCTRL register */
#define SPI_IXS_SELCTRL_CPHA_Pos              _UINT32_(10)                                         /* (SPI_IXS_SELCTRL) SPI Clock Edge Select bit Position */
#define SPI_IXS_SELCTRL_CPHA_Msk              (_UINT32_(0x1) << SPI_IXS_SELCTRL_CPHA_Pos)          /* (SPI_IXS_SELCTRL) SPI Clock Edge Select bit Mask */
#define SPI_IXS_SELCTRL_CPHA(value)           (SPI_IXS_SELCTRL_CPHA_Msk & (_UINT32_(value) << SPI_IXS_SELCTRL_CPHA_Pos)) /* Assigment of value for CPHA in the SPI_IXS_SELCTRL register */
#define SPI_IXS_SELCTRL_CPOL_Pos              _UINT32_(11)                                         /* (SPI_IXS_SELCTRL) Clock Polarity Select bit Position */
#define SPI_IXS_SELCTRL_CPOL_Msk              (_UINT32_(0x1) << SPI_IXS_SELCTRL_CPOL_Pos)          /* (SPI_IXS_SELCTRL) Clock Polarity Select bit Mask */
#define SPI_IXS_SELCTRL_CPOL(value)           (SPI_IXS_SELCTRL_CPOL_Msk & (_UINT32_(value) << SPI_IXS_SELCTRL_CPOL_Pos)) /* Assigment of value for CPOL in the SPI_IXS_SELCTRL register */
#define SPI_IXS_SELCTRL_STXISEL_Pos           _UINT32_(12)                                         /* (SPI_IXS_SELCTRL) SPI Transmit Service Request Interrupt Select Position */
#define SPI_IXS_SELCTRL_STXISEL_Msk           (_UINT32_(0x3) << SPI_IXS_SELCTRL_STXISEL_Pos)       /* (SPI_IXS_SELCTRL) SPI Transmit Service Request Interrupt Select Mask */
#define SPI_IXS_SELCTRL_STXISEL(value)        (SPI_IXS_SELCTRL_STXISEL_Msk & (_UINT32_(value) << SPI_IXS_SELCTRL_STXISEL_Pos)) /* Assigment of value for STXISEL in the SPI_IXS_SELCTRL register */
#define   SPI_IXS_SELCTRL_STXISEL_TXBSREMPTY_Val _UINT32_(0x0)                                        /* (SPI_IXS_SELCTRL) TXB And SR Empty  */
#define   SPI_IXS_SELCTRL_STXISEL_TXBEMPTY_Val _UINT32_(0x1)                                        /* (SPI_IXS_SELCTRL) TXB Empty  */
#define   SPI_IXS_SELCTRL_STXISEL_TXBHEMPTY_Val _UINT32_(0x2)                                        /* (SPI_IXS_SELCTRL) TXB Half Empty  */
#define   SPI_IXS_SELCTRL_STXISEL_TXBNFULL_Val _UINT32_(0x3)                                        /* (SPI_IXS_SELCTRL) TXB Not Full  */
#define SPI_IXS_SELCTRL_STXISEL_TXBSREMPTY    (SPI_IXS_SELCTRL_STXISEL_TXBSREMPTY_Val << SPI_IXS_SELCTRL_STXISEL_Pos) /* (SPI_IXS_SELCTRL) TXB And SR Empty Position  */
#define SPI_IXS_SELCTRL_STXISEL_TXBEMPTY      (SPI_IXS_SELCTRL_STXISEL_TXBEMPTY_Val << SPI_IXS_SELCTRL_STXISEL_Pos) /* (SPI_IXS_SELCTRL) TXB Empty Position  */
#define SPI_IXS_SELCTRL_STXISEL_TXBHEMPTY     (SPI_IXS_SELCTRL_STXISEL_TXBHEMPTY_Val << SPI_IXS_SELCTRL_STXISEL_Pos) /* (SPI_IXS_SELCTRL) TXB Half Empty Position  */
#define SPI_IXS_SELCTRL_STXISEL_TXBNFULL      (SPI_IXS_SELCTRL_STXISEL_TXBNFULL_Val << SPI_IXS_SELCTRL_STXISEL_Pos) /* (SPI_IXS_SELCTRL) TXB Not Full Position  */
#define SPI_IXS_SELCTRL_IGNTUR_Pos            _UINT32_(14)                                         /* (SPI_IXS_SELCTRL) Ignore Transmit Underrun (for Audio Data Transmissions) Position */
#define SPI_IXS_SELCTRL_IGNTUR_Msk            (_UINT32_(0x1) << SPI_IXS_SELCTRL_IGNTUR_Pos)        /* (SPI_IXS_SELCTRL) Ignore Transmit Underrun (for Audio Data Transmissions) Mask */
#define SPI_IXS_SELCTRL_IGNTUR(value)         (SPI_IXS_SELCTRL_IGNTUR_Msk & (_UINT32_(value) << SPI_IXS_SELCTRL_IGNTUR_Pos)) /* Assigment of value for IGNTUR in the SPI_IXS_SELCTRL register */
#define SPI_IXS_SELCTRL_DATFMTLR_Pos          _UINT32_(16)                                         /* (SPI_IXS_SELCTRL) Packed data format -- left or right justified Position */
#define SPI_IXS_SELCTRL_DATFMTLR_Msk          (_UINT32_(0x1) << SPI_IXS_SELCTRL_DATFMTLR_Pos)      /* (SPI_IXS_SELCTRL) Packed data format -- left or right justified Mask */
#define SPI_IXS_SELCTRL_DATFMTLR(value)       (SPI_IXS_SELCTRL_DATFMTLR_Msk & (_UINT32_(value) << SPI_IXS_SELCTRL_DATFMTLR_Pos)) /* Assigment of value for DATFMTLR in the SPI_IXS_SELCTRL register */
#define SPI_IXS_SELCTRL_TURSAMP_Pos           _UINT32_(23)                                         /* (SPI_IXS_SELCTRL) Transmit Under-run last sample sent Position */
#define SPI_IXS_SELCTRL_TURSAMP_Msk           (_UINT32_(0x1) << SPI_IXS_SELCTRL_TURSAMP_Pos)       /* (SPI_IXS_SELCTRL) Transmit Under-run last sample sent Mask */
#define SPI_IXS_SELCTRL_TURSAMP(value)        (SPI_IXS_SELCTRL_TURSAMP_Msk & (_UINT32_(value) << SPI_IXS_SELCTRL_TURSAMP_Pos)) /* Assigment of value for TURSAMP in the SPI_IXS_SELCTRL register */
#define SPI_IXS_SELCTRL_DATFILL_Pos           _UINT32_(24)                                         /* (SPI_IXS_SELCTRL) DATFILL undefined bits 1 or 0 Position */
#define SPI_IXS_SELCTRL_DATFILL_Msk           (_UINT32_(0x1) << SPI_IXS_SELCTRL_DATFILL_Pos)       /* (SPI_IXS_SELCTRL) DATFILL undefined bits 1 or 0 Mask */
#define SPI_IXS_SELCTRL_DATFILL(value)        (SPI_IXS_SELCTRL_DATFILL_Msk & (_UINT32_(value) << SPI_IXS_SELCTRL_DATFILL_Pos)) /* Assigment of value for DATFILL in the SPI_IXS_SELCTRL register */
#define SPI_IXS_SELCTRL_MODEEN_Pos            _UINT32_(30)                                         /* (SPI_IXS_SELCTRL) MACRO MODE ENABLED Position */
#define SPI_IXS_SELCTRL_MODEEN_Msk            (_UINT32_(0x3) << SPI_IXS_SELCTRL_MODEEN_Pos)        /* (SPI_IXS_SELCTRL) MACRO MODE ENABLED Mask */
#define SPI_IXS_SELCTRL_MODEEN(value)         (SPI_IXS_SELCTRL_MODEEN_Msk & (_UINT32_(value) << SPI_IXS_SELCTRL_MODEEN_Pos)) /* Assigment of value for MODEEN in the SPI_IXS_SELCTRL register */
#define   SPI_IXS_SELCTRL_MODEEN_DFTLEN_Val   _UINT32_(0x0)                                        /* (SPI_IXS_SELCTRL) Default Mode  */
#define   SPI_IXS_SELCTRL_MODEEN_AUDEN_Val    _UINT32_(0x1)                                        /* (SPI_IXS_SELCTRL) Audio Mode  */
#define   SPI_IXS_SELCTRL_MODEEN_TDMEN_Val    _UINT32_(0x2)                                        /* (SPI_IXS_SELCTRL) Framed Mode  */
#define   SPI_IXS_SELCTRL_MODEEN_TPDEN_Val    _UINT32_(0x3)                                        /* (SPI_IXS_SELCTRL) Broadcast Mode  */
#define SPI_IXS_SELCTRL_MODEEN_DFTLEN         (SPI_IXS_SELCTRL_MODEEN_DFTLEN_Val << SPI_IXS_SELCTRL_MODEEN_Pos) /* (SPI_IXS_SELCTRL) Default Mode Position  */
#define SPI_IXS_SELCTRL_MODEEN_AUDEN          (SPI_IXS_SELCTRL_MODEEN_AUDEN_Val << SPI_IXS_SELCTRL_MODEEN_Pos) /* (SPI_IXS_SELCTRL) Audio Mode Position  */
#define SPI_IXS_SELCTRL_MODEEN_TDMEN          (SPI_IXS_SELCTRL_MODEEN_TDMEN_Val << SPI_IXS_SELCTRL_MODEEN_Pos) /* (SPI_IXS_SELCTRL) Framed Mode Position  */
#define SPI_IXS_SELCTRL_MODEEN_TPDEN          (SPI_IXS_SELCTRL_MODEEN_TPDEN_Val << SPI_IXS_SELCTRL_MODEEN_Pos) /* (SPI_IXS_SELCTRL) Broadcast Mode Position  */
#define SPI_IXS_SELCTRL_Msk                   _UINT32_(0xC1817C73)                                 /* (SPI_IXS_SELCTRL) Register Mask  */


/* -------- SPI_IXS_SPICTRL : (SPI_IXS Offset: 0x08) (R/W 32) SPI Control Register -------- */
#define SPI_IXS_SPICTRL_RESETVALUE            _UINT32_(0x00)                                       /*  (SPI_IXS_SPICTRL) SPI Control Register  Reset Value */

#define SPI_IXS_SPICTRL_MODE_Pos              _UINT32_(0)                                          /* (SPI_IXS_SPICTRL) Serial Word Length bits for AUDEN=0, not used when AUDEN=1 Position */
#define SPI_IXS_SPICTRL_MODE_Msk              (_UINT32_(0x3) << SPI_IXS_SPICTRL_MODE_Pos)          /* (SPI_IXS_SPICTRL) Serial Word Length bits for AUDEN=0, not used when AUDEN=1 Mask */
#define SPI_IXS_SPICTRL_MODE(value)           (SPI_IXS_SPICTRL_MODE_Msk & (_UINT32_(value) << SPI_IXS_SPICTRL_MODE_Pos)) /* Assigment of value for MODE in the SPI_IXS_SPICTRL register */
#define   SPI_IXS_SPICTRL_MODE_MODE8_Val      _UINT32_(0x0)                                        /* (SPI_IXS_SPICTRL) 8 Bits Mode  */
#define   SPI_IXS_SPICTRL_MODE_MODE16_Val     _UINT32_(0x1)                                        /* (SPI_IXS_SPICTRL) 16 Bits Mode  */
#define   SPI_IXS_SPICTRL_MODE_MODE32_Val     _UINT32_(0x2)                                        /* (SPI_IXS_SPICTRL) 32 Bits Mode  */
#define SPI_IXS_SPICTRL_MODE_MODE8            (SPI_IXS_SPICTRL_MODE_MODE8_Val << SPI_IXS_SPICTRL_MODE_Pos) /* (SPI_IXS_SPICTRL) 8 Bits Mode Position  */
#define SPI_IXS_SPICTRL_MODE_MODE16           (SPI_IXS_SPICTRL_MODE_MODE16_Val << SPI_IXS_SPICTRL_MODE_Pos) /* (SPI_IXS_SPICTRL) 16 Bits Mode Position  */
#define SPI_IXS_SPICTRL_MODE_MODE32           (SPI_IXS_SPICTRL_MODE_MODE32_Val << SPI_IXS_SPICTRL_MODE_Pos) /* (SPI_IXS_SPICTRL) 32 Bits Mode Position  */
#define SPI_IXS_SPICTRL_DISSDI_Pos            _UINT32_(3)                                          /* (SPI_IXS_SPICTRL) Disable SDI bit Position */
#define SPI_IXS_SPICTRL_DISSDI_Msk            (_UINT32_(0x1) << SPI_IXS_SPICTRL_DISSDI_Pos)        /* (SPI_IXS_SPICTRL) Disable SDI bit Mask */
#define SPI_IXS_SPICTRL_DISSDI(value)         (SPI_IXS_SPICTRL_DISSDI_Msk & (_UINT32_(value) << SPI_IXS_SPICTRL_DISSDI_Pos)) /* Assigment of value for DISSDI in the SPI_IXS_SPICTRL register */
#define SPI_IXS_SPICTRL_DISSDO_Pos            _UINT32_(4)                                          /* (SPI_IXS_SPICTRL) Disable SDO bit Position */
#define SPI_IXS_SPICTRL_DISSDO_Msk            (_UINT32_(0x1) << SPI_IXS_SPICTRL_DISSDO_Pos)        /* (SPI_IXS_SPICTRL) Disable SDO bit Mask */
#define SPI_IXS_SPICTRL_DISSDO(value)         (SPI_IXS_SPICTRL_DISSDO_Msk & (_UINT32_(value) << SPI_IXS_SPICTRL_DISSDO_Pos)) /* Assigment of value for DISSDO in the SPI_IXS_SPICTRL register */
#define SPI_IXS_SPICTRL_MSTEN_Pos             _UINT32_(5)                                          /* (SPI_IXS_SPICTRL) Master Mode Enable bit Position */
#define SPI_IXS_SPICTRL_MSTEN_Msk             (_UINT32_(0x1) << SPI_IXS_SPICTRL_MSTEN_Pos)         /* (SPI_IXS_SPICTRL) Master Mode Enable bit Mask */
#define SPI_IXS_SPICTRL_MSTEN(value)          (SPI_IXS_SPICTRL_MSTEN_Msk & (_UINT32_(value) << SPI_IXS_SPICTRL_MSTEN_Pos)) /* Assigment of value for MSTEN in the SPI_IXS_SPICTRL register */
#define SPI_IXS_SPICTRL_MSSEN_Pos             _UINT32_(6)                                          /* (SPI_IXS_SPICTRL) Master/Slave Mode Select Enable bit Position */
#define SPI_IXS_SPICTRL_MSSEN_Msk             (_UINT32_(0x1) << SPI_IXS_SPICTRL_MSSEN_Pos)         /* (SPI_IXS_SPICTRL) Master/Slave Mode Select Enable bit Mask */
#define SPI_IXS_SPICTRL_MSSEN(value)          (SPI_IXS_SPICTRL_MSSEN_Msk & (_UINT32_(value) << SPI_IXS_SPICTRL_MSSEN_Pos)) /* Assigment of value for MSSEN in the SPI_IXS_SPICTRL register */
#define SPI_IXS_SPICTRL_SPISGNEXT_Pos         _UINT32_(9)                                          /* (SPI_IXS_SPICTRL) Sign Extend Read Data from the RX FIFO Position */
#define SPI_IXS_SPICTRL_SPISGNEXT_Msk         (_UINT32_(0x1) << SPI_IXS_SPICTRL_SPISGNEXT_Pos)     /* (SPI_IXS_SPICTRL) Sign Extend Read Data from the RX FIFO Mask */
#define SPI_IXS_SPICTRL_SPISGNEXT(value)      (SPI_IXS_SPICTRL_SPISGNEXT_Msk & (_UINT32_(value) << SPI_IXS_SPICTRL_SPISGNEXT_Pos)) /* Assigment of value for SPISGNEXT in the SPI_IXS_SPICTRL register */
#define SPI_IXS_SPICTRL_SMP_Pos               _UINT32_(10)                                         /* (SPI_IXS_SPICTRL) SPI Data Input Sample Phase bit Position */
#define SPI_IXS_SPICTRL_SMP_Msk               (_UINT32_(0x1) << SPI_IXS_SPICTRL_SMP_Pos)           /* (SPI_IXS_SPICTRL) SPI Data Input Sample Phase bit Mask */
#define SPI_IXS_SPICTRL_SMP(value)            (SPI_IXS_SPICTRL_SMP_Msk & (_UINT32_(value) << SPI_IXS_SPICTRL_SMP_Pos)) /* Assigment of value for SMP in the SPI_IXS_SPICTRL register */
#define SPI_IXS_SPICTRL_Msk                   _UINT32_(0x0000067B)                                 /* (SPI_IXS_SPICTRL) Register Mask  */


/* -------- SPI_IXS_FRAMECTRL : (SPI_IXS Offset: 0x0C) (R/W 32) SPI Control Frame Register -------- */
#define SPI_IXS_FRAMECTRL_RESETVALUE          _UINT32_(0x00)                                       /*  (SPI_IXS_FRAMECTRL) SPI Control Frame Register  Reset Value */

#define SPI_IXS_FRAMECTRL_FRMSYPW_Pos         _UINT32_(0)                                          /* (SPI_IXS_FRAMECTRL) Frame sync pulse width in serial words Position */
#define SPI_IXS_FRAMECTRL_FRMSYPW_Msk         (_UINT32_(0xF) << SPI_IXS_FRAMECTRL_FRMSYPW_Pos)     /* (SPI_IXS_FRAMECTRL) Frame sync pulse width in serial words Mask */
#define SPI_IXS_FRAMECTRL_FRMSYPW(value)      (SPI_IXS_FRAMECTRL_FRMSYPW_Msk & (_UINT32_(value) << SPI_IXS_FRAMECTRL_FRMSYPW_Pos)) /* Assigment of value for FRMSYPW in the SPI_IXS_FRAMECTRL register */
#define   SPI_IXS_FRAMECTRL_FRMSYPW_SYPW0_Val _UINT32_(0x0)                                        /* (SPI_IXS_FRAMECTRL) Frame sync pulse is one clock wide  */
#define   SPI_IXS_FRAMECTRL_FRMSYPW_SYPW1_Val _UINT32_(0x1)                                        /* (SPI_IXS_FRAMECTRL) Frame sync pulse is one slots wide  */
#define   SPI_IXS_FRAMECTRL_FRMSYPW_SYPW2_Val _UINT32_(0x2)                                        /* (SPI_IXS_FRAMECTRL) Frame sync pulse is two slots wide  */
#define   SPI_IXS_FRAMECTRL_FRMSYPW_SYPW3_Val _UINT32_(0x3)                                        /* (SPI_IXS_FRAMECTRL) Frame sync pulse is three slots wide  */
#define   SPI_IXS_FRAMECTRL_FRMSYPW_SYPW4_Val _UINT32_(0x4)                                        /* (SPI_IXS_FRAMECTRL) Frame sync pulse is four slots wide  */
#define   SPI_IXS_FRAMECTRL_FRMSYPW_SYPW5_Val _UINT32_(0x5)                                        /* (SPI_IXS_FRAMECTRL) Frame sync pulse is five slots wide  */
#define   SPI_IXS_FRAMECTRL_FRMSYPW_SYPW6_Val _UINT32_(0x6)                                        /* (SPI_IXS_FRAMECTRL) Frame sync pulse is six slots wide  */
#define   SPI_IXS_FRAMECTRL_FRMSYPW_SYPW7_Val _UINT32_(0x7)                                        /* (SPI_IXS_FRAMECTRL) Frame sync pulse is seven slots wide  */
#define   SPI_IXS_FRAMECTRL_FRMSYPW_SYPW8_Val _UINT32_(0x8)                                        /* (SPI_IXS_FRAMECTRL) Frame sync pulse is eight slots wide  */
#define   SPI_IXS_FRAMECTRL_FRMSYPW_SYPW16_Val _UINT32_(0x9)                                        /* (SPI_IXS_FRAMECTRL) Frame sync pulse is sixteen slots wide  */
#define   SPI_IXS_FRAMECTRL_FRMSYPW_SYPW31_Val _UINT32_(0xA)                                        /* (SPI_IXS_FRAMECTRL) Frame sync pulse is thirty one slots wide  */
#define SPI_IXS_FRAMECTRL_FRMSYPW_SYPW0       (SPI_IXS_FRAMECTRL_FRMSYPW_SYPW0_Val << SPI_IXS_FRAMECTRL_FRMSYPW_Pos) /* (SPI_IXS_FRAMECTRL) Frame sync pulse is one clock wide Position  */
#define SPI_IXS_FRAMECTRL_FRMSYPW_SYPW1       (SPI_IXS_FRAMECTRL_FRMSYPW_SYPW1_Val << SPI_IXS_FRAMECTRL_FRMSYPW_Pos) /* (SPI_IXS_FRAMECTRL) Frame sync pulse is one slots wide Position  */
#define SPI_IXS_FRAMECTRL_FRMSYPW_SYPW2       (SPI_IXS_FRAMECTRL_FRMSYPW_SYPW2_Val << SPI_IXS_FRAMECTRL_FRMSYPW_Pos) /* (SPI_IXS_FRAMECTRL) Frame sync pulse is two slots wide Position  */
#define SPI_IXS_FRAMECTRL_FRMSYPW_SYPW3       (SPI_IXS_FRAMECTRL_FRMSYPW_SYPW3_Val << SPI_IXS_FRAMECTRL_FRMSYPW_Pos) /* (SPI_IXS_FRAMECTRL) Frame sync pulse is three slots wide Position  */
#define SPI_IXS_FRAMECTRL_FRMSYPW_SYPW4       (SPI_IXS_FRAMECTRL_FRMSYPW_SYPW4_Val << SPI_IXS_FRAMECTRL_FRMSYPW_Pos) /* (SPI_IXS_FRAMECTRL) Frame sync pulse is four slots wide Position  */
#define SPI_IXS_FRAMECTRL_FRMSYPW_SYPW5       (SPI_IXS_FRAMECTRL_FRMSYPW_SYPW5_Val << SPI_IXS_FRAMECTRL_FRMSYPW_Pos) /* (SPI_IXS_FRAMECTRL) Frame sync pulse is five slots wide Position  */
#define SPI_IXS_FRAMECTRL_FRMSYPW_SYPW6       (SPI_IXS_FRAMECTRL_FRMSYPW_SYPW6_Val << SPI_IXS_FRAMECTRL_FRMSYPW_Pos) /* (SPI_IXS_FRAMECTRL) Frame sync pulse is six slots wide Position  */
#define SPI_IXS_FRAMECTRL_FRMSYPW_SYPW7       (SPI_IXS_FRAMECTRL_FRMSYPW_SYPW7_Val << SPI_IXS_FRAMECTRL_FRMSYPW_Pos) /* (SPI_IXS_FRAMECTRL) Frame sync pulse is seven slots wide Position  */
#define SPI_IXS_FRAMECTRL_FRMSYPW_SYPW8       (SPI_IXS_FRAMECTRL_FRMSYPW_SYPW8_Val << SPI_IXS_FRAMECTRL_FRMSYPW_Pos) /* (SPI_IXS_FRAMECTRL) Frame sync pulse is eight slots wide Position  */
#define SPI_IXS_FRAMECTRL_FRMSYPW_SYPW16      (SPI_IXS_FRAMECTRL_FRMSYPW_SYPW16_Val << SPI_IXS_FRAMECTRL_FRMSYPW_Pos) /* (SPI_IXS_FRAMECTRL) Frame sync pulse is sixteen slots wide Position  */
#define SPI_IXS_FRAMECTRL_FRMSYPW_SYPW31      (SPI_IXS_FRAMECTRL_FRMSYPW_SYPW31_Val << SPI_IXS_FRAMECTRL_FRMSYPW_Pos) /* (SPI_IXS_FRAMECTRL) Frame sync pulse is thirty one slots wide Position  */
#define SPI_IXS_FRAMECTRL_FRMCOINC_Pos        _UINT32_(8)                                          /* (SPI_IXS_FRAMECTRL) Frame Sync Pulse Edge Select bit Position */
#define SPI_IXS_FRAMECTRL_FRMCOINC_Msk        (_UINT32_(0x1) << SPI_IXS_FRAMECTRL_FRMCOINC_Pos)    /* (SPI_IXS_FRAMECTRL) Frame Sync Pulse Edge Select bit Mask */
#define SPI_IXS_FRAMECTRL_FRMCOINC(value)     (SPI_IXS_FRAMECTRL_FRMCOINC_Msk & (_UINT32_(value) << SPI_IXS_FRAMECTRL_FRMCOINC_Pos)) /* Assigment of value for FRMCOINC in the SPI_IXS_FRAMECTRL register */
#define SPI_IXS_FRAMECTRL_FRMPOL_Pos          _UINT32_(13)                                         /* (SPI_IXS_FRAMECTRL) Frame Sync / Slave Select Polarity bit Position */
#define SPI_IXS_FRAMECTRL_FRMPOL_Msk          (_UINT32_(0x1) << SPI_IXS_FRAMECTRL_FRMPOL_Pos)      /* (SPI_IXS_FRAMECTRL) Frame Sync / Slave Select Polarity bit Mask */
#define SPI_IXS_FRAMECTRL_FRMPOL(value)       (SPI_IXS_FRAMECTRL_FRMPOL_Msk & (_UINT32_(value) << SPI_IXS_FRAMECTRL_FRMPOL_Pos)) /* Assigment of value for FRMPOL in the SPI_IXS_FRAMECTRL register */
#define SPI_IXS_FRAMECTRL_FRMSLV_Pos          _UINT32_(14)                                         /* (SPI_IXS_FRAMECTRL) Frame Sync Pulse Direction Control bit Position */
#define SPI_IXS_FRAMECTRL_FRMSLV_Msk          (_UINT32_(0x1) << SPI_IXS_FRAMECTRL_FRMSLV_Pos)      /* (SPI_IXS_FRAMECTRL) Frame Sync Pulse Direction Control bit Mask */
#define SPI_IXS_FRAMECTRL_FRMSLV(value)       (SPI_IXS_FRAMECTRL_FRMSLV_Msk & (_UINT32_(value) << SPI_IXS_FRAMECTRL_FRMSLV_Pos)) /* Assigment of value for FRMSLV in the SPI_IXS_FRAMECTRL register */
#define SPI_IXS_FRAMECTRL_FRMCNT_Pos          _UINT32_(16)                                         /* (SPI_IXS_FRAMECTRL) Frame sync pulse counter Position */
#define SPI_IXS_FRAMECTRL_FRMCNT_Msk          (_UINT32_(0x1F) << SPI_IXS_FRAMECTRL_FRMCNT_Pos)     /* (SPI_IXS_FRAMECTRL) Frame sync pulse counter Mask */
#define SPI_IXS_FRAMECTRL_FRMCNT(value)       (SPI_IXS_FRAMECTRL_FRMCNT_Msk & (_UINT32_(value) << SPI_IXS_FRAMECTRL_FRMCNT_Pos)) /* Assigment of value for FRMCNT in the SPI_IXS_FRAMECTRL register */
#define   SPI_IXS_FRAMECTRL_FRMCNT_CNT1_Val   _UINT32_(0x0)                                        /* (SPI_IXS_FRAMECTRL) Generate a Frame sync pulse on each serial word  */
#define   SPI_IXS_FRAMECTRL_FRMCNT_CNT2_Val   _UINT32_(0x1)                                        /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 2  */
#define   SPI_IXS_FRAMECTRL_FRMCNT_CNT3_Val   _UINT32_(0x2)                                        /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 3  */
#define   SPI_IXS_FRAMECTRL_FRMCNT_CNT4_Val   _UINT32_(0x3)                                        /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 4  */
#define   SPI_IXS_FRAMECTRL_FRMCNT_CNT5_Val   _UINT32_(0x4)                                        /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 5  */
#define   SPI_IXS_FRAMECTRL_FRMCNT_CNT6_Val   _UINT32_(0x5)                                        /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 6  */
#define   SPI_IXS_FRAMECTRL_FRMCNT_CNT8_Val   _UINT32_(0x6)                                        /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 8  */
#define   SPI_IXS_FRAMECTRL_FRMCNT_CNT10_Val  _UINT32_(0x7)                                        /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 10  */
#define   SPI_IXS_FRAMECTRL_FRMCNT_CNT12_Val  _UINT32_(0x8)                                        /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 12  */
#define   SPI_IXS_FRAMECTRL_FRMCNT_CNT14_Val  _UINT32_(0x9)                                        /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 14  */
#define   SPI_IXS_FRAMECTRL_FRMCNT_CNT16_Val  _UINT32_(0xA)                                        /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 16  */
#define   SPI_IXS_FRAMECTRL_FRMCNT_CNT18_Val  _UINT32_(0xB)                                        /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 18  */
#define   SPI_IXS_FRAMECTRL_FRMCNT_CNT20_Val  _UINT32_(0xC)                                        /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 20  */
#define   SPI_IXS_FRAMECTRL_FRMCNT_CNT22_Val  _UINT32_(0xD)                                        /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 22  */
#define   SPI_IXS_FRAMECTRL_FRMCNT_CNT24_Val  _UINT32_(0xE)                                        /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 24  */
#define   SPI_IXS_FRAMECTRL_FRMCNT_CNT26_Val  _UINT32_(0xF)                                        /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 26  */
#define   SPI_IXS_FRAMECTRL_FRMCNT_CNT28_Val  _UINT32_(0x10)                                       /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 28  */
#define   SPI_IXS_FRAMECTRL_FRMCNT_CNT30_Val  _UINT32_(0x11)                                       /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 30  */
#define   SPI_IXS_FRAMECTRL_FRMCNT_CNT32_Val  _UINT32_(0x12)                                       /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 32  */
#define SPI_IXS_FRAMECTRL_FRMCNT_CNT1         (SPI_IXS_FRAMECTRL_FRMCNT_CNT1_Val << SPI_IXS_FRAMECTRL_FRMCNT_Pos) /* (SPI_IXS_FRAMECTRL) Generate a Frame sync pulse on each serial word Position  */
#define SPI_IXS_FRAMECTRL_FRMCNT_CNT2         (SPI_IXS_FRAMECTRL_FRMCNT_CNT2_Val << SPI_IXS_FRAMECTRL_FRMCNT_Pos) /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 2 Position  */
#define SPI_IXS_FRAMECTRL_FRMCNT_CNT3         (SPI_IXS_FRAMECTRL_FRMCNT_CNT3_Val << SPI_IXS_FRAMECTRL_FRMCNT_Pos) /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 3 Position  */
#define SPI_IXS_FRAMECTRL_FRMCNT_CNT4         (SPI_IXS_FRAMECTRL_FRMCNT_CNT4_Val << SPI_IXS_FRAMECTRL_FRMCNT_Pos) /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 4 Position  */
#define SPI_IXS_FRAMECTRL_FRMCNT_CNT5         (SPI_IXS_FRAMECTRL_FRMCNT_CNT5_Val << SPI_IXS_FRAMECTRL_FRMCNT_Pos) /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 5 Position  */
#define SPI_IXS_FRAMECTRL_FRMCNT_CNT6         (SPI_IXS_FRAMECTRL_FRMCNT_CNT6_Val << SPI_IXS_FRAMECTRL_FRMCNT_Pos) /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 6 Position  */
#define SPI_IXS_FRAMECTRL_FRMCNT_CNT8         (SPI_IXS_FRAMECTRL_FRMCNT_CNT8_Val << SPI_IXS_FRAMECTRL_FRMCNT_Pos) /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 8 Position  */
#define SPI_IXS_FRAMECTRL_FRMCNT_CNT10        (SPI_IXS_FRAMECTRL_FRMCNT_CNT10_Val << SPI_IXS_FRAMECTRL_FRMCNT_Pos) /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 10 Position  */
#define SPI_IXS_FRAMECTRL_FRMCNT_CNT12        (SPI_IXS_FRAMECTRL_FRMCNT_CNT12_Val << SPI_IXS_FRAMECTRL_FRMCNT_Pos) /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 12 Position  */
#define SPI_IXS_FRAMECTRL_FRMCNT_CNT14        (SPI_IXS_FRAMECTRL_FRMCNT_CNT14_Val << SPI_IXS_FRAMECTRL_FRMCNT_Pos) /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 14 Position  */
#define SPI_IXS_FRAMECTRL_FRMCNT_CNT16        (SPI_IXS_FRAMECTRL_FRMCNT_CNT16_Val << SPI_IXS_FRAMECTRL_FRMCNT_Pos) /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 16 Position  */
#define SPI_IXS_FRAMECTRL_FRMCNT_CNT18        (SPI_IXS_FRAMECTRL_FRMCNT_CNT18_Val << SPI_IXS_FRAMECTRL_FRMCNT_Pos) /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 18 Position  */
#define SPI_IXS_FRAMECTRL_FRMCNT_CNT20        (SPI_IXS_FRAMECTRL_FRMCNT_CNT20_Val << SPI_IXS_FRAMECTRL_FRMCNT_Pos) /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 20 Position  */
#define SPI_IXS_FRAMECTRL_FRMCNT_CNT22        (SPI_IXS_FRAMECTRL_FRMCNT_CNT22_Val << SPI_IXS_FRAMECTRL_FRMCNT_Pos) /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 22 Position  */
#define SPI_IXS_FRAMECTRL_FRMCNT_CNT24        (SPI_IXS_FRAMECTRL_FRMCNT_CNT24_Val << SPI_IXS_FRAMECTRL_FRMCNT_Pos) /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 24 Position  */
#define SPI_IXS_FRAMECTRL_FRMCNT_CNT26        (SPI_IXS_FRAMECTRL_FRMCNT_CNT26_Val << SPI_IXS_FRAMECTRL_FRMCNT_Pos) /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 26 Position  */
#define SPI_IXS_FRAMECTRL_FRMCNT_CNT28        (SPI_IXS_FRAMECTRL_FRMCNT_CNT28_Val << SPI_IXS_FRAMECTRL_FRMCNT_Pos) /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 28 Position  */
#define SPI_IXS_FRAMECTRL_FRMCNT_CNT30        (SPI_IXS_FRAMECTRL_FRMCNT_CNT30_Val << SPI_IXS_FRAMECTRL_FRMCNT_Pos) /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 30 Position  */
#define SPI_IXS_FRAMECTRL_FRMCNT_CNT32        (SPI_IXS_FRAMECTRL_FRMCNT_CNT32_Val << SPI_IXS_FRAMECTRL_FRMCNT_Pos) /* (SPI_IXS_FRAMECTRL) Number of slots per frame sync pulse is 32 Position  */
#define SPI_IXS_FRAMECTRL_TDMSSZ_Pos          _UINT32_(24)                                         /* (SPI_IXS_FRAMECTRL) TDM Number of Bits in a Slot Size Position */
#define SPI_IXS_FRAMECTRL_TDMSSZ_Msk          (_UINT32_(0x7) << SPI_IXS_FRAMECTRL_TDMSSZ_Pos)      /* (SPI_IXS_FRAMECTRL) TDM Number of Bits in a Slot Size Mask */
#define SPI_IXS_FRAMECTRL_TDMSSZ(value)       (SPI_IXS_FRAMECTRL_TDMSSZ_Msk & (_UINT32_(value) << SPI_IXS_FRAMECTRL_TDMSSZ_Pos)) /* Assigment of value for TDMSSZ in the SPI_IXS_FRAMECTRL register */
#define   SPI_IXS_FRAMECTRL_TDMSSZ_SLTSZ8_Val _UINT32_(0x0)                                        /* (SPI_IXS_FRAMECTRL) Slot Size 8  */
#define   SPI_IXS_FRAMECTRL_TDMSSZ_SLTSZ12_Val _UINT32_(0x1)                                        /* (SPI_IXS_FRAMECTRL) Slot Size 12  */
#define   SPI_IXS_FRAMECTRL_TDMSSZ_SLTSZ16_Val _UINT32_(0x2)                                        /* (SPI_IXS_FRAMECTRL) Slot Size 16  */
#define   SPI_IXS_FRAMECTRL_TDMSSZ_SLTSZ20_Val _UINT32_(0x3)                                        /* (SPI_IXS_FRAMECTRL) Slot Size 20  */
#define   SPI_IXS_FRAMECTRL_TDMSSZ_SLTSZ24_Val _UINT32_(0x4)                                        /* (SPI_IXS_FRAMECTRL) Slot Size 24  */
#define   SPI_IXS_FRAMECTRL_TDMSSZ_SLTSZ28_Val _UINT32_(0x5)                                        /* (SPI_IXS_FRAMECTRL) Slot Size 28  */
#define   SPI_IXS_FRAMECTRL_TDMSSZ_SLTSZ32_Val _UINT32_(0x6)                                        /* (SPI_IXS_FRAMECTRL) Slot Size 32  */
#define SPI_IXS_FRAMECTRL_TDMSSZ_SLTSZ8       (SPI_IXS_FRAMECTRL_TDMSSZ_SLTSZ8_Val << SPI_IXS_FRAMECTRL_TDMSSZ_Pos) /* (SPI_IXS_FRAMECTRL) Slot Size 8 Position  */
#define SPI_IXS_FRAMECTRL_TDMSSZ_SLTSZ12      (SPI_IXS_FRAMECTRL_TDMSSZ_SLTSZ12_Val << SPI_IXS_FRAMECTRL_TDMSSZ_Pos) /* (SPI_IXS_FRAMECTRL) Slot Size 12 Position  */
#define SPI_IXS_FRAMECTRL_TDMSSZ_SLTSZ16      (SPI_IXS_FRAMECTRL_TDMSSZ_SLTSZ16_Val << SPI_IXS_FRAMECTRL_TDMSSZ_Pos) /* (SPI_IXS_FRAMECTRL) Slot Size 16 Position  */
#define SPI_IXS_FRAMECTRL_TDMSSZ_SLTSZ20      (SPI_IXS_FRAMECTRL_TDMSSZ_SLTSZ20_Val << SPI_IXS_FRAMECTRL_TDMSSZ_Pos) /* (SPI_IXS_FRAMECTRL) Slot Size 20 Position  */
#define SPI_IXS_FRAMECTRL_TDMSSZ_SLTSZ24      (SPI_IXS_FRAMECTRL_TDMSSZ_SLTSZ24_Val << SPI_IXS_FRAMECTRL_TDMSSZ_Pos) /* (SPI_IXS_FRAMECTRL) Slot Size 24 Position  */
#define SPI_IXS_FRAMECTRL_TDMSSZ_SLTSZ28      (SPI_IXS_FRAMECTRL_TDMSSZ_SLTSZ28_Val << SPI_IXS_FRAMECTRL_TDMSSZ_Pos) /* (SPI_IXS_FRAMECTRL) Slot Size 28 Position  */
#define SPI_IXS_FRAMECTRL_TDMSSZ_SLTSZ32      (SPI_IXS_FRAMECTRL_TDMSSZ_SLTSZ32_Val << SPI_IXS_FRAMECTRL_TDMSSZ_Pos) /* (SPI_IXS_FRAMECTRL) Slot Size 32 Position  */
#define SPI_IXS_FRAMECTRL_TDMWSZ_Pos          _UINT32_(29)                                         /* (SPI_IXS_FRAMECTRL) TDM Number of Bits in a Word Size Position */
#define SPI_IXS_FRAMECTRL_TDMWSZ_Msk          (_UINT32_(0x7) << SPI_IXS_FRAMECTRL_TDMWSZ_Pos)      /* (SPI_IXS_FRAMECTRL) TDM Number of Bits in a Word Size Mask */
#define SPI_IXS_FRAMECTRL_TDMWSZ(value)       (SPI_IXS_FRAMECTRL_TDMWSZ_Msk & (_UINT32_(value) << SPI_IXS_FRAMECTRL_TDMWSZ_Pos)) /* Assigment of value for TDMWSZ in the SPI_IXS_FRAMECTRL register */
#define   SPI_IXS_FRAMECTRL_TDMWSZ_WDSZ8_Val  _UINT32_(0x0)                                        /* (SPI_IXS_FRAMECTRL) Word Size 8  */
#define   SPI_IXS_FRAMECTRL_TDMWSZ_WDSZ12_Val _UINT32_(0x1)                                        /* (SPI_IXS_FRAMECTRL) Word Size 12  */
#define   SPI_IXS_FRAMECTRL_TDMWSZ_WDSZ16_Val _UINT32_(0x2)                                        /* (SPI_IXS_FRAMECTRL) Word Size 16  */
#define   SPI_IXS_FRAMECTRL_TDMWSZ_WDSZ20_Val _UINT32_(0x3)                                        /* (SPI_IXS_FRAMECTRL) Word Size 20  */
#define   SPI_IXS_FRAMECTRL_TDMWSZ_WDSZ24_Val _UINT32_(0x4)                                        /* (SPI_IXS_FRAMECTRL) Word Size 24  */
#define   SPI_IXS_FRAMECTRL_TDMWSZ_WDSZ28_Val _UINT32_(0x5)                                        /* (SPI_IXS_FRAMECTRL) Word Size 28  */
#define   SPI_IXS_FRAMECTRL_TDMWSZ_WDSZ32_Val _UINT32_(0x6)                                        /* (SPI_IXS_FRAMECTRL) Word Size 32  */
#define SPI_IXS_FRAMECTRL_TDMWSZ_WDSZ8        (SPI_IXS_FRAMECTRL_TDMWSZ_WDSZ8_Val << SPI_IXS_FRAMECTRL_TDMWSZ_Pos) /* (SPI_IXS_FRAMECTRL) Word Size 8 Position  */
#define SPI_IXS_FRAMECTRL_TDMWSZ_WDSZ12       (SPI_IXS_FRAMECTRL_TDMWSZ_WDSZ12_Val << SPI_IXS_FRAMECTRL_TDMWSZ_Pos) /* (SPI_IXS_FRAMECTRL) Word Size 12 Position  */
#define SPI_IXS_FRAMECTRL_TDMWSZ_WDSZ16       (SPI_IXS_FRAMECTRL_TDMWSZ_WDSZ16_Val << SPI_IXS_FRAMECTRL_TDMWSZ_Pos) /* (SPI_IXS_FRAMECTRL) Word Size 16 Position  */
#define SPI_IXS_FRAMECTRL_TDMWSZ_WDSZ20       (SPI_IXS_FRAMECTRL_TDMWSZ_WDSZ20_Val << SPI_IXS_FRAMECTRL_TDMWSZ_Pos) /* (SPI_IXS_FRAMECTRL) Word Size 20 Position  */
#define SPI_IXS_FRAMECTRL_TDMWSZ_WDSZ24       (SPI_IXS_FRAMECTRL_TDMWSZ_WDSZ24_Val << SPI_IXS_FRAMECTRL_TDMWSZ_Pos) /* (SPI_IXS_FRAMECTRL) Word Size 24 Position  */
#define SPI_IXS_FRAMECTRL_TDMWSZ_WDSZ28       (SPI_IXS_FRAMECTRL_TDMWSZ_WDSZ28_Val << SPI_IXS_FRAMECTRL_TDMWSZ_Pos) /* (SPI_IXS_FRAMECTRL) Word Size 28 Position  */
#define SPI_IXS_FRAMECTRL_TDMWSZ_WDSZ32       (SPI_IXS_FRAMECTRL_TDMWSZ_WDSZ32_Val << SPI_IXS_FRAMECTRL_TDMWSZ_Pos) /* (SPI_IXS_FRAMECTRL) Word Size 32 Position  */
#define SPI_IXS_FRAMECTRL_Msk                 _UINT32_(0xE71F610F)                                 /* (SPI_IXS_FRAMECTRL) Register Mask  */


/* -------- SPI_IXS_AUDCTRL : (SPI_IXS Offset: 0x10) (R/W 32) SPI Control Audio Register -------- */
#define SPI_IXS_AUDCTRL_RESETVALUE            _UINT32_(0x00)                                       /*  (SPI_IXS_AUDCTRL) SPI Control Audio Register  Reset Value */

#define SPI_IXS_AUDCTRL_AUDMOD_Pos            _UINT32_(0)                                          /* (SPI_IXS_AUDCTRL) Audio Protocol Mode Position */
#define SPI_IXS_AUDCTRL_AUDMOD_Msk            (_UINT32_(0x3) << SPI_IXS_AUDCTRL_AUDMOD_Pos)        /* (SPI_IXS_AUDCTRL) Audio Protocol Mode Mask */
#define SPI_IXS_AUDCTRL_AUDMOD(value)         (SPI_IXS_AUDCTRL_AUDMOD_Msk & (_UINT32_(value) << SPI_IXS_AUDCTRL_AUDMOD_Pos)) /* Assigment of value for AUDMOD in the SPI_IXS_AUDCTRL register */
#define   SPI_IXS_AUDCTRL_AUDMOD_STDMODE_Val  _UINT32_(0x0)                                        /* (SPI_IXS_AUDCTRL) I2S/I8S Standard Mode  */
#define   SPI_IXS_AUDCTRL_AUDMOD_LJRJMODE_Val _UINT32_(0x1)                                        /* (SPI_IXS_AUDCTRL) I2S/I8S Left Or Right Justified  */
#define   SPI_IXS_AUDCTRL_AUDMOD_PCMMODE_Val  _UINT32_(0x3)                                        /* (SPI_IXS_AUDCTRL) PCM/DSP Mode  */
#define SPI_IXS_AUDCTRL_AUDMOD_STDMODE        (SPI_IXS_AUDCTRL_AUDMOD_STDMODE_Val << SPI_IXS_AUDCTRL_AUDMOD_Pos) /* (SPI_IXS_AUDCTRL) I2S/I8S Standard Mode Position  */
#define SPI_IXS_AUDCTRL_AUDMOD_LJRJMODE       (SPI_IXS_AUDCTRL_AUDMOD_LJRJMODE_Val << SPI_IXS_AUDCTRL_AUDMOD_Pos) /* (SPI_IXS_AUDCTRL) I2S/I8S Left Or Right Justified Position  */
#define SPI_IXS_AUDCTRL_AUDMOD_PCMMODE        (SPI_IXS_AUDCTRL_AUDMOD_PCMMODE_Val << SPI_IXS_AUDCTRL_AUDMOD_Pos) /* (SPI_IXS_AUDCTRL) PCM/DSP Mode Position  */
#define SPI_IXS_AUDCTRL_AUDMONO_Pos           _UINT32_(3)                                          /* (SPI_IXS_AUDCTRL) Transmit audio data format Position */
#define SPI_IXS_AUDCTRL_AUDMONO_Msk           (_UINT32_(0x1) << SPI_IXS_AUDCTRL_AUDMONO_Pos)       /* (SPI_IXS_AUDCTRL) Transmit audio data format Mask */
#define SPI_IXS_AUDCTRL_AUDMONO(value)        (SPI_IXS_AUDCTRL_AUDMONO_Msk & (_UINT32_(value) << SPI_IXS_AUDCTRL_AUDMONO_Pos)) /* Assigment of value for AUDMONO in the SPI_IXS_AUDCTRL register */
#define SPI_IXS_AUDCTRL_AUDFMT_Pos            _UINT32_(4)                                          /* (SPI_IXS_AUDCTRL) Audio Protocol Format Position */
#define SPI_IXS_AUDCTRL_AUDFMT_Msk            (_UINT32_(0x7) << SPI_IXS_AUDCTRL_AUDFMT_Pos)        /* (SPI_IXS_AUDCTRL) Audio Protocol Format Mask */
#define SPI_IXS_AUDCTRL_AUDFMT(value)         (SPI_IXS_AUDCTRL_AUDFMT_Msk & (_UINT32_(value) << SPI_IXS_AUDCTRL_AUDFMT_Pos)) /* Assigment of value for AUDFMT in the SPI_IXS_AUDCTRL register */
#define   SPI_IXS_AUDCTRL_AUDFMT_I2SLEGACY_Val _UINT32_(0x0)                                        /* (SPI_IXS_AUDCTRL) Legacy I2S Mode  */
#define   SPI_IXS_AUDCTRL_AUDFMT_I2SRAW_Val   _UINT32_(0x1)                                        /* (SPI_IXS_AUDCTRL) I2S Raw Audio Format  */
#define   SPI_IXS_AUDCTRL_AUDFMT_I2SOTHER824_Val _UINT32_(0x2)                                        /* (SPI_IXS_AUDCTRL) I2S Other AM824 Format  */
#define   SPI_IXS_AUDCTRL_AUDFMT_I8SOTHER_Val _UINT32_(0x4)                                        /* (SPI_IXS_AUDCTRL) I8S Other Format  */
#define   SPI_IXS_AUDCTRL_AUDFMT_I8SRAW_Val   _UINT32_(0x5)                                        /* (SPI_IXS_AUDCTRL) I8S Raw Audio Format  */
#define   SPI_IXS_AUDCTRL_AUDFMT_I8SOTHER824_Val _UINT32_(0x6)                                        /* (SPI_IXS_AUDCTRL) I8S Other AM824 Format  */
#define SPI_IXS_AUDCTRL_AUDFMT_I2SLEGACY      (SPI_IXS_AUDCTRL_AUDFMT_I2SLEGACY_Val << SPI_IXS_AUDCTRL_AUDFMT_Pos) /* (SPI_IXS_AUDCTRL) Legacy I2S Mode Position  */
#define SPI_IXS_AUDCTRL_AUDFMT_I2SRAW         (SPI_IXS_AUDCTRL_AUDFMT_I2SRAW_Val << SPI_IXS_AUDCTRL_AUDFMT_Pos) /* (SPI_IXS_AUDCTRL) I2S Raw Audio Format Position  */
#define SPI_IXS_AUDCTRL_AUDFMT_I2SOTHER824    (SPI_IXS_AUDCTRL_AUDFMT_I2SOTHER824_Val << SPI_IXS_AUDCTRL_AUDFMT_Pos) /* (SPI_IXS_AUDCTRL) I2S Other AM824 Format Position  */
#define SPI_IXS_AUDCTRL_AUDFMT_I8SOTHER       (SPI_IXS_AUDCTRL_AUDFMT_I8SOTHER_Val << SPI_IXS_AUDCTRL_AUDFMT_Pos) /* (SPI_IXS_AUDCTRL) I8S Other Format Position  */
#define SPI_IXS_AUDCTRL_AUDFMT_I8SRAW         (SPI_IXS_AUDCTRL_AUDFMT_I8SRAW_Val << SPI_IXS_AUDCTRL_AUDFMT_Pos) /* (SPI_IXS_AUDCTRL) I8S Raw Audio Format Position  */
#define SPI_IXS_AUDCTRL_AUDFMT_I8SOTHER824    (SPI_IXS_AUDCTRL_AUDFMT_I8SOTHER824_Val << SPI_IXS_AUDCTRL_AUDFMT_Pos) /* (SPI_IXS_AUDCTRL) I8S Other AM824 Format Position  */
#define SPI_IXS_AUDCTRL_AUDWDMODE_Pos         _UINT32_(8)                                          /* (SPI_IXS_AUDCTRL) Serial Word Length bits (Ignored when AUDEN=0) Position */
#define SPI_IXS_AUDCTRL_AUDWDMODE_Msk         (_UINT32_(0x3) << SPI_IXS_AUDCTRL_AUDWDMODE_Pos)     /* (SPI_IXS_AUDCTRL) Serial Word Length bits (Ignored when AUDEN=0) Mask */
#define SPI_IXS_AUDCTRL_AUDWDMODE(value)      (SPI_IXS_AUDCTRL_AUDWDMODE_Msk & (_UINT32_(value) << SPI_IXS_AUDCTRL_AUDWDMODE_Pos)) /* Assigment of value for AUDWDMODE in the SPI_IXS_AUDCTRL register */
#define SPI_IXS_AUDCTRL_Msk                   _UINT32_(0x0000037B)                                 /* (SPI_IXS_AUDCTRL) Register Mask  */


/* -------- SPI_IXS_TPDCTRL : (SPI_IXS Offset: 0x14) (R/W 32) SPI Control Tpd Register -------- */
#define SPI_IXS_TPDCTRL_RESETVALUE            _UINT32_(0x00)                                       /*  (SPI_IXS_TPDCTRL) SPI Control Tpd Register  Reset Value */

#define SPI_IXS_TPDCTRL_PKFMT_Pos             _UINT32_(0)                                          /* (SPI_IXS_TPDCTRL) Master Slave TPD mode. Position */
#define SPI_IXS_TPDCTRL_PKFMT_Msk             (_UINT32_(0x7) << SPI_IXS_TPDCTRL_PKFMT_Pos)         /* (SPI_IXS_TPDCTRL) Master Slave TPD mode. Mask */
#define SPI_IXS_TPDCTRL_PKFMT(value)          (SPI_IXS_TPDCTRL_PKFMT_Msk & (_UINT32_(value) << SPI_IXS_TPDCTRL_PKFMT_Pos)) /* Assigment of value for PKFMT in the SPI_IXS_TPDCTRL register */
#define   SPI_IXS_TPDCTRL_PKFMT_PKT4x32_Val   _UINT32_(0x0)                                        /* (SPI_IXS_TPDCTRL) 32 bit data in 4x32 packed format  */
#define   SPI_IXS_TPDCTRL_PKFMT_PKT3x32_Val   _UINT32_(0x1)                                        /* (SPI_IXS_TPDCTRL) 32 bit data in 3x32 packed format  */
#define   SPI_IXS_TPDCTRL_PKFMT_PKT4x24_Val   _UINT32_(0x2)                                        /* (SPI_IXS_TPDCTRL) 24 bit data in 4x24 packed format  */
#define   SPI_IXS_TPDCTRL_PKFMT_PKT3x24_Val   _UINT32_(0x3)                                        /* (SPI_IXS_TPDCTRL) 24 bit data in 3x24 packed format  */
#define   SPI_IXS_TPDCTRL_PKFMT_PKT6x16_Val   _UINT32_(0x4)                                        /* (SPI_IXS_TPDCTRL) 16 bit data in 6x16 packed format  */
#define   SPI_IXS_TPDCTRL_PKFMT_PKT4x16_Val   _UINT32_(0x5)                                        /* (SPI_IXS_TPDCTRL) 16 bit data in 4x16 packed format  */
#define   SPI_IXS_TPDCTRL_PKFMT_PKT2x16_Val   _UINT32_(0x6)                                        /* (SPI_IXS_TPDCTRL) 16 bit data in 2x16 packed format  */
#define SPI_IXS_TPDCTRL_PKFMT_PKT4x32         (SPI_IXS_TPDCTRL_PKFMT_PKT4x32_Val << SPI_IXS_TPDCTRL_PKFMT_Pos) /* (SPI_IXS_TPDCTRL) 32 bit data in 4x32 packed format Position  */
#define SPI_IXS_TPDCTRL_PKFMT_PKT3x32         (SPI_IXS_TPDCTRL_PKFMT_PKT3x32_Val << SPI_IXS_TPDCTRL_PKFMT_Pos) /* (SPI_IXS_TPDCTRL) 32 bit data in 3x32 packed format Position  */
#define SPI_IXS_TPDCTRL_PKFMT_PKT4x24         (SPI_IXS_TPDCTRL_PKFMT_PKT4x24_Val << SPI_IXS_TPDCTRL_PKFMT_Pos) /* (SPI_IXS_TPDCTRL) 24 bit data in 4x24 packed format Position  */
#define SPI_IXS_TPDCTRL_PKFMT_PKT3x24         (SPI_IXS_TPDCTRL_PKFMT_PKT3x24_Val << SPI_IXS_TPDCTRL_PKFMT_Pos) /* (SPI_IXS_TPDCTRL) 24 bit data in 3x24 packed format Position  */
#define SPI_IXS_TPDCTRL_PKFMT_PKT6x16         (SPI_IXS_TPDCTRL_PKFMT_PKT6x16_Val << SPI_IXS_TPDCTRL_PKFMT_Pos) /* (SPI_IXS_TPDCTRL) 16 bit data in 6x16 packed format Position  */
#define SPI_IXS_TPDCTRL_PKFMT_PKT4x16         (SPI_IXS_TPDCTRL_PKFMT_PKT4x16_Val << SPI_IXS_TPDCTRL_PKFMT_Pos) /* (SPI_IXS_TPDCTRL) 16 bit data in 4x16 packed format Position  */
#define SPI_IXS_TPDCTRL_PKFMT_PKT2x16         (SPI_IXS_TPDCTRL_PKFMT_PKT2x16_Val << SPI_IXS_TPDCTRL_PKFMT_Pos) /* (SPI_IXS_TPDCTRL) 16 bit data in 2x16 packed format Position  */
#define SPI_IXS_TPDCTRL_SLVNUM_Pos            _UINT32_(8)                                          /* (SPI_IXS_TPDCTRL) Number of the Slave designated: to be used with the PKFMT to determine the slave. Position */
#define SPI_IXS_TPDCTRL_SLVNUM_Msk            (_UINT32_(0x7) << SPI_IXS_TPDCTRL_SLVNUM_Pos)        /* (SPI_IXS_TPDCTRL) Number of the Slave designated: to be used with the PKFMT to determine the slave. Mask */
#define SPI_IXS_TPDCTRL_SLVNUM(value)         (SPI_IXS_TPDCTRL_SLVNUM_Msk & (_UINT32_(value) << SPI_IXS_TPDCTRL_SLVNUM_Pos)) /* Assigment of value for SLVNUM in the SPI_IXS_TPDCTRL register */
#define   SPI_IXS_TPDCTRL_SLVNUM_SLAVE0_Val   _UINT32_(0x0)                                        /* (SPI_IXS_TPDCTRL) SLAVE 0  */
#define   SPI_IXS_TPDCTRL_SLVNUM_SLAVE1_Val   _UINT32_(0x1)                                        /* (SPI_IXS_TPDCTRL) SLAVE 1  */
#define   SPI_IXS_TPDCTRL_SLVNUM_SLAVE2_Val   _UINT32_(0x2)                                        /* (SPI_IXS_TPDCTRL) SLAVE 2  */
#define   SPI_IXS_TPDCTRL_SLVNUM_SLAVE3_Val   _UINT32_(0x3)                                        /* (SPI_IXS_TPDCTRL) SLAVE 3  */
#define   SPI_IXS_TPDCTRL_SLVNUM_SLAVE4_Val   _UINT32_(0x4)                                        /* (SPI_IXS_TPDCTRL) SLAVE 4  */
#define SPI_IXS_TPDCTRL_SLVNUM_SLAVE0         (SPI_IXS_TPDCTRL_SLVNUM_SLAVE0_Val << SPI_IXS_TPDCTRL_SLVNUM_Pos) /* (SPI_IXS_TPDCTRL) SLAVE 0 Position  */
#define SPI_IXS_TPDCTRL_SLVNUM_SLAVE1         (SPI_IXS_TPDCTRL_SLVNUM_SLAVE1_Val << SPI_IXS_TPDCTRL_SLVNUM_Pos) /* (SPI_IXS_TPDCTRL) SLAVE 1 Position  */
#define SPI_IXS_TPDCTRL_SLVNUM_SLAVE2         (SPI_IXS_TPDCTRL_SLVNUM_SLAVE2_Val << SPI_IXS_TPDCTRL_SLVNUM_Pos) /* (SPI_IXS_TPDCTRL) SLAVE 2 Position  */
#define SPI_IXS_TPDCTRL_SLVNUM_SLAVE3         (SPI_IXS_TPDCTRL_SLVNUM_SLAVE3_Val << SPI_IXS_TPDCTRL_SLVNUM_Pos) /* (SPI_IXS_TPDCTRL) SLAVE 3 Position  */
#define SPI_IXS_TPDCTRL_SLVNUM_SLAVE4         (SPI_IXS_TPDCTRL_SLVNUM_SLAVE4_Val << SPI_IXS_TPDCTRL_SLVNUM_Pos) /* (SPI_IXS_TPDCTRL) SLAVE 4 Position  */
#define SPI_IXS_TPDCTRL_Msk                   _UINT32_(0x00000707)                                 /* (SPI_IXS_TPDCTRL) Register Mask  */


/* -------- SPI_IXS_INTENSET : (SPI_IXS Offset: 0x18) (R/W 32) SPI Interrupt Enable Set Register -------- */
#define SPI_IXS_INTENSET_RESETVALUE           _UINT32_(0x00)                                       /*  (SPI_IXS_INTENSET) SPI Interrupt Enable Set Register  Reset Value */

#define SPI_IXS_INTENSET_SPIRXBFEN_Pos        _UINT32_(0)                                          /* (SPI_IXS_INTENSET) Enablie Interrupt Events via SPIRXBF Position */
#define SPI_IXS_INTENSET_SPIRXBFEN_Msk        (_UINT32_(0x1) << SPI_IXS_INTENSET_SPIRXBFEN_Pos)    /* (SPI_IXS_INTENSET) Enablie Interrupt Events via SPIRXBF Mask */
#define SPI_IXS_INTENSET_SPIRXBFEN(value)     (SPI_IXS_INTENSET_SPIRXBFEN_Msk & (_UINT32_(value) << SPI_IXS_INTENSET_SPIRXBFEN_Pos)) /* Assigment of value for SPIRXBFEN in the SPI_IXS_INTENSET register */
#define SPI_IXS_INTENSET_SPITXBEEN_Pos        _UINT32_(4)                                          /* (SPI_IXS_INTENSET) Enablie Interrupt Events via SPITXBE Position */
#define SPI_IXS_INTENSET_SPITXBEEN_Msk        (_UINT32_(0x1) << SPI_IXS_INTENSET_SPITXBEEN_Pos)    /* (SPI_IXS_INTENSET) Enablie Interrupt Events via SPITXBE Mask */
#define SPI_IXS_INTENSET_SPITXBEEN(value)     (SPI_IXS_INTENSET_SPITXBEEN_Msk & (_UINT32_(value) << SPI_IXS_INTENSET_SPITXBEEN_Pos)) /* Assigment of value for SPITXBEEN in the SPI_IXS_INTENSET register */
#define SPI_IXS_INTENSET_FRMERREN_Pos         _UINT32_(15)                                         /* (SPI_IXS_INTENSET) Enable Interrupt Events via FRMERR Position */
#define SPI_IXS_INTENSET_FRMERREN_Msk         (_UINT32_(0x1) << SPI_IXS_INTENSET_FRMERREN_Pos)     /* (SPI_IXS_INTENSET) Enable Interrupt Events via FRMERR Mask */
#define SPI_IXS_INTENSET_FRMERREN(value)      (SPI_IXS_INTENSET_FRMERREN_Msk & (_UINT32_(value) << SPI_IXS_INTENSET_FRMERREN_Pos)) /* Assigment of value for FRMERREN in the SPI_IXS_INTENSET register */
#define SPI_IXS_INTENSET_SPITUREN_Pos         _UINT32_(27)                                         /* (SPI_IXS_INTENSET) Enable Interrupt Events via SPITUR Position */
#define SPI_IXS_INTENSET_SPITUREN_Msk         (_UINT32_(0x1) << SPI_IXS_INTENSET_SPITUREN_Pos)     /* (SPI_IXS_INTENSET) Enable Interrupt Events via SPITUR Mask */
#define SPI_IXS_INTENSET_SPITUREN(value)      (SPI_IXS_INTENSET_SPITUREN_Msk & (_UINT32_(value) << SPI_IXS_INTENSET_SPITUREN_Pos)) /* Assigment of value for SPITUREN in the SPI_IXS_INTENSET register */
#define SPI_IXS_INTENSET_SPIROVEN_Pos         _UINT32_(30)                                         /* (SPI_IXS_INTENSET) Enable Interrupt Events via SPIROV Position */
#define SPI_IXS_INTENSET_SPIROVEN_Msk         (_UINT32_(0x1) << SPI_IXS_INTENSET_SPIROVEN_Pos)     /* (SPI_IXS_INTENSET) Enable Interrupt Events via SPIROV Mask */
#define SPI_IXS_INTENSET_SPIROVEN(value)      (SPI_IXS_INTENSET_SPIROVEN_Msk & (_UINT32_(value) << SPI_IXS_INTENSET_SPIROVEN_Pos)) /* Assigment of value for SPIROVEN in the SPI_IXS_INTENSET register */
#define SPI_IXS_INTENSET_Msk                  _UINT32_(0x48008011)                                 /* (SPI_IXS_INTENSET) Register Mask  */


/* -------- SPI_IXS_INTENCLR : (SPI_IXS Offset: 0x1C) (R/W 32) SPI Interrupt Enable Clear Register -------- */
#define SPI_IXS_INTENCLR_RESETVALUE           _UINT32_(0x00)                                       /*  (SPI_IXS_INTENCLR) SPI Interrupt Enable Clear Register  Reset Value */

#define SPI_IXS_INTENCLR_SPIRXBFEN_Pos        _UINT32_(0)                                          /* (SPI_IXS_INTENCLR) Enablie Interrupt Events via SPIRXBF Position */
#define SPI_IXS_INTENCLR_SPIRXBFEN_Msk        (_UINT32_(0x1) << SPI_IXS_INTENCLR_SPIRXBFEN_Pos)    /* (SPI_IXS_INTENCLR) Enablie Interrupt Events via SPIRXBF Mask */
#define SPI_IXS_INTENCLR_SPIRXBFEN(value)     (SPI_IXS_INTENCLR_SPIRXBFEN_Msk & (_UINT32_(value) << SPI_IXS_INTENCLR_SPIRXBFEN_Pos)) /* Assigment of value for SPIRXBFEN in the SPI_IXS_INTENCLR register */
#define SPI_IXS_INTENCLR_SPITXBEEN_Pos        _UINT32_(4)                                          /* (SPI_IXS_INTENCLR) Enablie Interrupt Events via SPITXBE Position */
#define SPI_IXS_INTENCLR_SPITXBEEN_Msk        (_UINT32_(0x1) << SPI_IXS_INTENCLR_SPITXBEEN_Pos)    /* (SPI_IXS_INTENCLR) Enablie Interrupt Events via SPITXBE Mask */
#define SPI_IXS_INTENCLR_SPITXBEEN(value)     (SPI_IXS_INTENCLR_SPITXBEEN_Msk & (_UINT32_(value) << SPI_IXS_INTENCLR_SPITXBEEN_Pos)) /* Assigment of value for SPITXBEEN in the SPI_IXS_INTENCLR register */
#define SPI_IXS_INTENCLR_FRMERREN_Pos         _UINT32_(15)                                         /* (SPI_IXS_INTENCLR) Enable Interrupt Events via FRMERR Position */
#define SPI_IXS_INTENCLR_FRMERREN_Msk         (_UINT32_(0x1) << SPI_IXS_INTENCLR_FRMERREN_Pos)     /* (SPI_IXS_INTENCLR) Enable Interrupt Events via FRMERR Mask */
#define SPI_IXS_INTENCLR_FRMERREN(value)      (SPI_IXS_INTENCLR_FRMERREN_Msk & (_UINT32_(value) << SPI_IXS_INTENCLR_FRMERREN_Pos)) /* Assigment of value for FRMERREN in the SPI_IXS_INTENCLR register */
#define SPI_IXS_INTENCLR_SPITUREN_Pos         _UINT32_(27)                                         /* (SPI_IXS_INTENCLR) Enable Interrupt Events via SPITUR Position */
#define SPI_IXS_INTENCLR_SPITUREN_Msk         (_UINT32_(0x1) << SPI_IXS_INTENCLR_SPITUREN_Pos)     /* (SPI_IXS_INTENCLR) Enable Interrupt Events via SPITUR Mask */
#define SPI_IXS_INTENCLR_SPITUREN(value)      (SPI_IXS_INTENCLR_SPITUREN_Msk & (_UINT32_(value) << SPI_IXS_INTENCLR_SPITUREN_Pos)) /* Assigment of value for SPITUREN in the SPI_IXS_INTENCLR register */
#define SPI_IXS_INTENCLR_SPIROVEN_Pos         _UINT32_(30)                                         /* (SPI_IXS_INTENCLR) Enable Interrupt Events via SPIROV Position */
#define SPI_IXS_INTENCLR_SPIROVEN_Msk         (_UINT32_(0x1) << SPI_IXS_INTENCLR_SPIROVEN_Pos)     /* (SPI_IXS_INTENCLR) Enable Interrupt Events via SPIROV Mask */
#define SPI_IXS_INTENCLR_SPIROVEN(value)      (SPI_IXS_INTENCLR_SPIROVEN_Msk & (_UINT32_(value) << SPI_IXS_INTENCLR_SPIROVEN_Pos)) /* Assigment of value for SPIROVEN in the SPI_IXS_INTENCLR register */
#define SPI_IXS_INTENCLR_Msk                  _UINT32_(0x48008011)                                 /* (SPI_IXS_INTENCLR) Register Mask  */


/* -------- SPI_IXS_INTFLAG : (SPI_IXS Offset: 0x20) (R/W 32) SPI Interrupt Flag Register -------- */
#define SPI_IXS_INTFLAG_RESETVALUE            _UINT32_(0x00)                                       /*  (SPI_IXS_INTFLAG) SPI Interrupt Flag Register  Reset Value */

#define SPI_IXS_INTFLAG_SPIRXBF_Pos           _UINT32_(0)                                          /* (SPI_IXS_INTFLAG) SPI Receive Buffer Full Status Bit Position */
#define SPI_IXS_INTFLAG_SPIRXBF_Msk           (_UINT32_(0x1) << SPI_IXS_INTFLAG_SPIRXBF_Pos)       /* (SPI_IXS_INTFLAG) SPI Receive Buffer Full Status Bit Mask */
#define SPI_IXS_INTFLAG_SPIRXBF(value)        (SPI_IXS_INTFLAG_SPIRXBF_Msk & (_UINT32_(value) << SPI_IXS_INTFLAG_SPIRXBF_Pos)) /* Assigment of value for SPIRXBF in the SPI_IXS_INTFLAG register */
#define SPI_IXS_INTFLAG_SPITXBE_Pos           _UINT32_(4)                                          /* (SPI_IXS_INTFLAG) SPI Transmit Buffer Empty Status Bit Position */
#define SPI_IXS_INTFLAG_SPITXBE_Msk           (_UINT32_(0x1) << SPI_IXS_INTFLAG_SPITXBE_Pos)       /* (SPI_IXS_INTFLAG) SPI Transmit Buffer Empty Status Bit Mask */
#define SPI_IXS_INTFLAG_SPITXBE(value)        (SPI_IXS_INTFLAG_SPITXBE_Msk & (_UINT32_(value) << SPI_IXS_INTFLAG_SPITXBE_Pos)) /* Assigment of value for SPITXBE in the SPI_IXS_INTFLAG register */
#define SPI_IXS_INTFLAG_FRMERR_Pos            _UINT32_(15)                                         /* (SPI_IXS_INTFLAG) SPI Frame Error Status bit Position */
#define SPI_IXS_INTFLAG_FRMERR_Msk            (_UINT32_(0x1) << SPI_IXS_INTFLAG_FRMERR_Pos)        /* (SPI_IXS_INTFLAG) SPI Frame Error Status bit Mask */
#define SPI_IXS_INTFLAG_FRMERR(value)         (SPI_IXS_INTFLAG_FRMERR_Msk & (_UINT32_(value) << SPI_IXS_INTFLAG_FRMERR_Pos)) /* Assigment of value for FRMERR in the SPI_IXS_INTFLAG register */
#define SPI_IXS_INTFLAG_SPITUR_Pos            _UINT32_(27)                                         /* (SPI_IXS_INTFLAG) Transmit Underrun Status bit Position */
#define SPI_IXS_INTFLAG_SPITUR_Msk            (_UINT32_(0x1) << SPI_IXS_INTFLAG_SPITUR_Pos)        /* (SPI_IXS_INTFLAG) Transmit Underrun Status bit Mask */
#define SPI_IXS_INTFLAG_SPITUR(value)         (SPI_IXS_INTFLAG_SPITUR_Msk & (_UINT32_(value) << SPI_IXS_INTFLAG_SPITUR_Pos)) /* Assigment of value for SPITUR in the SPI_IXS_INTFLAG register */
#define SPI_IXS_INTFLAG_SPIROV_Pos            _UINT32_(30)                                         /* (SPI_IXS_INTFLAG) Receive Overflow Status bit Position */
#define SPI_IXS_INTFLAG_SPIROV_Msk            (_UINT32_(0x1) << SPI_IXS_INTFLAG_SPIROV_Pos)        /* (SPI_IXS_INTFLAG) Receive Overflow Status bit Mask */
#define SPI_IXS_INTFLAG_SPIROV(value)         (SPI_IXS_INTFLAG_SPIROV_Msk & (_UINT32_(value) << SPI_IXS_INTFLAG_SPIROV_Pos)) /* Assigment of value for SPIROV in the SPI_IXS_INTFLAG register */
#define SPI_IXS_INTFLAG_Msk                   _UINT32_(0x48008011)                                 /* (SPI_IXS_INTFLAG) Register Mask  */


/* -------- SPI_IXS_STATUS : (SPI_IXS Offset: 0x24) ( R/ 32) SPI Status Register -------- */
#define SPI_IXS_STATUS_RESETVALUE             _UINT32_(0x90000000)                                 /*  (SPI_IXS_STATUS) SPI Status Register  Reset Value */

#define SPI_IXS_STATUS_RXBUFELM_Pos           _UINT32_(0)                                          /* (SPI_IXS_STATUS) Receive Buffer Element Count bits Position */
#define SPI_IXS_STATUS_RXBUFELM_Msk           (_UINT32_(0x1FF) << SPI_IXS_STATUS_RXBUFELM_Pos)     /* (SPI_IXS_STATUS) Receive Buffer Element Count bits Mask */
#define SPI_IXS_STATUS_RXBUFELM(value)        (SPI_IXS_STATUS_RXBUFELM_Msk & (_UINT32_(value) << SPI_IXS_STATUS_RXBUFELM_Pos)) /* Assigment of value for RXBUFELM in the SPI_IXS_STATUS register */
#define SPI_IXS_STATUS_SRMT_Pos               _UINT32_(13)                                         /* (SPI_IXS_STATUS) Register (SR) Empty bit Position */
#define SPI_IXS_STATUS_SRMT_Msk               (_UINT32_(0x1) << SPI_IXS_STATUS_SRMT_Pos)           /* (SPI_IXS_STATUS) Register (SR) Empty bit Mask */
#define SPI_IXS_STATUS_SRMT(value)            (SPI_IXS_STATUS_SRMT_Msk & (_UINT32_(value) << SPI_IXS_STATUS_SRMT_Pos)) /* Assigment of value for SRMT in the SPI_IXS_STATUS register */
#define SPI_IXS_STATUS_SPIBUSY_Pos            _UINT32_(14)                                         /* (SPI_IXS_STATUS) SPI activity status bit Position */
#define SPI_IXS_STATUS_SPIBUSY_Msk            (_UINT32_(0x1) << SPI_IXS_STATUS_SPIBUSY_Pos)        /* (SPI_IXS_STATUS) SPI activity status bit Mask */
#define SPI_IXS_STATUS_SPIBUSY(value)         (SPI_IXS_STATUS_SPIBUSY_Msk & (_UINT32_(value) << SPI_IXS_STATUS_SPIBUSY_Pos)) /* Assigment of value for SPIBUSY in the SPI_IXS_STATUS register */
#define SPI_IXS_STATUS_TXBUFELM_Pos           _UINT32_(16)                                         /* (SPI_IXS_STATUS) Transmit Buffer Element Count bits Position */
#define SPI_IXS_STATUS_TXBUFELM_Msk           (_UINT32_(0x1FF) << SPI_IXS_STATUS_TXBUFELM_Pos)     /* (SPI_IXS_STATUS) Transmit Buffer Element Count bits Mask */
#define SPI_IXS_STATUS_TXBUFELM(value)        (SPI_IXS_STATUS_TXBUFELM_Msk & (_UINT32_(value) << SPI_IXS_STATUS_TXBUFELM_Pos)) /* Assigment of value for TXBUFELM in the SPI_IXS_STATUS register */
#define SPI_IXS_STATUS_SPITBF_Pos             _UINT32_(26)                                         /* (SPI_IXS_STATUS) SPI Transmit Buffer Full Status bit Position */
#define SPI_IXS_STATUS_SPITBF_Msk             (_UINT32_(0x1) << SPI_IXS_STATUS_SPITBF_Pos)         /* (SPI_IXS_STATUS) SPI Transmit Buffer Full Status bit Mask */
#define SPI_IXS_STATUS_SPITBF(value)          (SPI_IXS_STATUS_SPITBF_Msk & (_UINT32_(value) << SPI_IXS_STATUS_SPITBF_Pos)) /* Assigment of value for SPITBF in the SPI_IXS_STATUS register */
#define SPI_IXS_STATUS_SPITBE_Pos             _UINT32_(28)                                         /* (SPI_IXS_STATUS) SPI Transmit Buffer Empty status bit Position */
#define SPI_IXS_STATUS_SPITBE_Msk             (_UINT32_(0x1) << SPI_IXS_STATUS_SPITBE_Pos)         /* (SPI_IXS_STATUS) SPI Transmit Buffer Empty status bit Mask */
#define SPI_IXS_STATUS_SPITBE(value)          (SPI_IXS_STATUS_SPITBE_Msk & (_UINT32_(value) << SPI_IXS_STATUS_SPITBE_Pos)) /* Assigment of value for SPITBE in the SPI_IXS_STATUS register */
#define SPI_IXS_STATUS_SPIRBF_Pos             _UINT32_(29)                                         /* (SPI_IXS_STATUS) SPI Receive Buffer Full status bit Position */
#define SPI_IXS_STATUS_SPIRBF_Msk             (_UINT32_(0x1) << SPI_IXS_STATUS_SPIRBF_Pos)         /* (SPI_IXS_STATUS) SPI Receive Buffer Full status bit Mask */
#define SPI_IXS_STATUS_SPIRBF(value)          (SPI_IXS_STATUS_SPIRBF_Msk & (_UINT32_(value) << SPI_IXS_STATUS_SPIRBF_Pos)) /* Assigment of value for SPIRBF in the SPI_IXS_STATUS register */
#define SPI_IXS_STATUS_SPIRBE_Pos             _UINT32_(31)                                         /* (SPI_IXS_STATUS) RX Buffer Empty bit Position */
#define SPI_IXS_STATUS_SPIRBE_Msk             (_UINT32_(0x1) << SPI_IXS_STATUS_SPIRBE_Pos)         /* (SPI_IXS_STATUS) RX Buffer Empty bit Mask */
#define SPI_IXS_STATUS_SPIRBE(value)          (SPI_IXS_STATUS_SPIRBE_Msk & (_UINT32_(value) << SPI_IXS_STATUS_SPIRBE_Pos)) /* Assigment of value for SPIRBE in the SPI_IXS_STATUS register */
#define SPI_IXS_STATUS_Msk                    _UINT32_(0xB5FF61FF)                                 /* (SPI_IXS_STATUS) Register Mask  */


/* -------- SPI_IXS_BUF : (SPI_IXS Offset: 0x28) (R/W 32) SPI Buffer Register -------- */
#define SPI_IXS_BUF_RESETVALUE                _UINT32_(0x00)                                       /*  (SPI_IXS_BUF) SPI Buffer Register  Reset Value */

#define SPI_IXS_BUF_DATA_Pos                  _UINT32_(0)                                          /* (SPI_IXS_BUF) FIFO Data bits Position */
#define SPI_IXS_BUF_DATA_Msk                  (_UINT32_(0xFFFFFFFF) << SPI_IXS_BUF_DATA_Pos)       /* (SPI_IXS_BUF) FIFO Data bits Mask */
#define SPI_IXS_BUF_DATA(value)               (SPI_IXS_BUF_DATA_Msk & (_UINT32_(value) << SPI_IXS_BUF_DATA_Pos)) /* Assigment of value for DATA in the SPI_IXS_BUF register */
#define SPI_IXS_BUF_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (SPI_IXS_BUF) Register Mask  */


/* -------- SPI_IXS_BRG : (SPI_IXS Offset: 0x2C) (R/W 32) SPI Baud Rate Register -------- */
#define SPI_IXS_BRG_RESETVALUE                _UINT32_(0x00)                                       /*  (SPI_IXS_BRG) SPI Baud Rate Register  Reset Value */

#define SPI_IXS_BRG_BRG_Pos                   _UINT32_(0)                                          /* (SPI_IXS_BRG) Baud Rate Divisor bits Position */
#define SPI_IXS_BRG_BRG_Msk                   (_UINT32_(0x1FFF) << SPI_IXS_BRG_BRG_Pos)            /* (SPI_IXS_BRG) Baud Rate Divisor bits Mask */
#define SPI_IXS_BRG_BRG(value)                (SPI_IXS_BRG_BRG_Msk & (_UINT32_(value) << SPI_IXS_BRG_BRG_Pos)) /* Assigment of value for BRG in the SPI_IXS_BRG register */
#define SPI_IXS_BRG_Msk                       _UINT32_(0x00001FFF)                                 /* (SPI_IXS_BRG) Register Mask  */


/* -------- SPI_IXS_DBGCTRL : (SPI_IXS Offset: 0x30) (R/W 32) SPI Debug Control Register -------- */
#define SPI_IXS_DBGCTRL_RESETVALUE            _UINT32_(0x00)                                       /*  (SPI_IXS_DBGCTRL) SPI Debug Control Register  Reset Value */

#define SPI_IXS_DBGCTRL_DBGRUN_Pos            _UINT32_(0)                                          /* (SPI_IXS_DBGCTRL) Debug Running State Position */
#define SPI_IXS_DBGCTRL_DBGRUN_Msk            (_UINT32_(0x1) << SPI_IXS_DBGCTRL_DBGRUN_Pos)        /* (SPI_IXS_DBGCTRL) Debug Running State Mask */
#define SPI_IXS_DBGCTRL_DBGRUN(value)         (SPI_IXS_DBGCTRL_DBGRUN_Msk & (_UINT32_(value) << SPI_IXS_DBGCTRL_DBGRUN_Pos)) /* Assigment of value for DBGRUN in the SPI_IXS_DBGCTRL register */
#define SPI_IXS_DBGCTRL_Msk                   _UINT32_(0x00000001)                                 /* (SPI_IXS_DBGCTRL) Register Mask  */


/* -------- SPI_IXS_SYNCBUSY : (SPI_IXS Offset: 0x34) ( R/ 32) SPI Sync Busy Register -------- */
#define SPI_IXS_SYNCBUSY_RESETVALUE           _UINT32_(0x00)                                       /*  (SPI_IXS_SYNCBUSY) SPI Sync Busy Register  Reset Value */

#define SPI_IXS_SYNCBUSY_SWRSTBSY_Pos         _UINT32_(0)                                          /* (SPI_IXS_SYNCBUSY) Software reset busy bit   --- Synchronizing Busy bit for swrst Position */
#define SPI_IXS_SYNCBUSY_SWRSTBSY_Msk         (_UINT32_(0x1) << SPI_IXS_SYNCBUSY_SWRSTBSY_Pos)     /* (SPI_IXS_SYNCBUSY) Software reset busy bit   --- Synchronizing Busy bit for swrst Mask */
#define SPI_IXS_SYNCBUSY_SWRSTBSY(value)      (SPI_IXS_SYNCBUSY_SWRSTBSY_Msk & (_UINT32_(value) << SPI_IXS_SYNCBUSY_SWRSTBSY_Pos)) /* Assigment of value for SWRSTBSY in the SPI_IXS_SYNCBUSY register */
#define SPI_IXS_SYNCBUSY_Msk                  _UINT32_(0x00000001)                                 /* (SPI_IXS_SYNCBUSY) Register Mask  */


/* -------- SPI_IXS_EVCTRL : (SPI_IXS Offset: 0x38) (R/W 32) SPI Event Control Register -------- */
#define SPI_IXS_EVCTRL_RESETVALUE             _UINT32_(0x00)                                       /*  (SPI_IXS_EVCTRL) SPI Event Control Register  Reset Value */

#define SPI_IXS_EVCTRL_FPSEEN_Pos             _UINT32_(0)                                          /* (SPI_IXS_EVCTRL) Frame Pulse Event Enable Bit Position */
#define SPI_IXS_EVCTRL_FPSEEN_Msk             (_UINT32_(0x1) << SPI_IXS_EVCTRL_FPSEEN_Pos)         /* (SPI_IXS_EVCTRL) Frame Pulse Event Enable Bit Mask */
#define SPI_IXS_EVCTRL_FPSEEN(value)          (SPI_IXS_EVCTRL_FPSEEN_Msk & (_UINT32_(value) << SPI_IXS_EVCTRL_FPSEEN_Pos)) /* Assigment of value for FPSEEN in the SPI_IXS_EVCTRL register */
#define SPI_IXS_EVCTRL_Msk                    _UINT32_(0x00000001)                                 /* (SPI_IXS_EVCTRL) Register Mask  */


/** \brief SPI_IXS register offsets definitions */
#define SPI_IXS_CTRLA_REG_OFST         _UINT32_(0x00)      /* (SPI_IXS_CTRLA) SPI Control Enable Register Offset */
#define SPI_IXS_SELCTRL_REG_OFST       _UINT32_(0x04)      /* (SPI_IXS_SELCTRL) SPI Control Options Select Register Offset */
#define SPI_IXS_SPICTRL_REG_OFST       _UINT32_(0x08)      /* (SPI_IXS_SPICTRL) SPI Control Register Offset */
#define SPI_IXS_FRAMECTRL_REG_OFST     _UINT32_(0x0C)      /* (SPI_IXS_FRAMECTRL) SPI Control Frame Register Offset */
#define SPI_IXS_AUDCTRL_REG_OFST       _UINT32_(0x10)      /* (SPI_IXS_AUDCTRL) SPI Control Audio Register Offset */
#define SPI_IXS_TPDCTRL_REG_OFST       _UINT32_(0x14)      /* (SPI_IXS_TPDCTRL) SPI Control Tpd Register Offset */
#define SPI_IXS_INTENSET_REG_OFST      _UINT32_(0x18)      /* (SPI_IXS_INTENSET) SPI Interrupt Enable Set Register Offset */
#define SPI_IXS_INTENCLR_REG_OFST      _UINT32_(0x1C)      /* (SPI_IXS_INTENCLR) SPI Interrupt Enable Clear Register Offset */
#define SPI_IXS_INTFLAG_REG_OFST       _UINT32_(0x20)      /* (SPI_IXS_INTFLAG) SPI Interrupt Flag Register Offset */
#define SPI_IXS_STATUS_REG_OFST        _UINT32_(0x24)      /* (SPI_IXS_STATUS) SPI Status Register Offset */
#define SPI_IXS_BUF_REG_OFST           _UINT32_(0x28)      /* (SPI_IXS_BUF) SPI Buffer Register Offset */
#define SPI_IXS_BRG_REG_OFST           _UINT32_(0x2C)      /* (SPI_IXS_BRG) SPI Baud Rate Register Offset */
#define SPI_IXS_DBGCTRL_REG_OFST       _UINT32_(0x30)      /* (SPI_IXS_DBGCTRL) SPI Debug Control Register Offset */
#define SPI_IXS_SYNCBUSY_REG_OFST      _UINT32_(0x34)      /* (SPI_IXS_SYNCBUSY) SPI Sync Busy Register Offset */
#define SPI_IXS_EVCTRL_REG_OFST        _UINT32_(0x38)      /* (SPI_IXS_EVCTRL) SPI Event Control Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief SPI_IXS register API structure */
typedef struct
{  /* Audio SPI with 8 channels compatibilty */
  __IO  uint32_t                       SPI_IXS_CTRLA;      /**< Offset: 0x00 (R/W  32) SPI Control Enable Register */
  __IO  uint32_t                       SPI_IXS_SELCTRL;    /**< Offset: 0x04 (R/W  32) SPI Control Options Select Register */
  __IO  uint32_t                       SPI_IXS_SPICTRL;    /**< Offset: 0x08 (R/W  32) SPI Control Register */
  __IO  uint32_t                       SPI_IXS_FRAMECTRL;  /**< Offset: 0x0C (R/W  32) SPI Control Frame Register */
  __IO  uint32_t                       SPI_IXS_AUDCTRL;    /**< Offset: 0x10 (R/W  32) SPI Control Audio Register */
  __IO  uint32_t                       SPI_IXS_TPDCTRL;    /**< Offset: 0x14 (R/W  32) SPI Control Tpd Register */
  __IO  uint32_t                       SPI_IXS_INTENSET;   /**< Offset: 0x18 (R/W  32) SPI Interrupt Enable Set Register */
  __IO  uint32_t                       SPI_IXS_INTENCLR;   /**< Offset: 0x1C (R/W  32) SPI Interrupt Enable Clear Register */
  __IO  uint32_t                       SPI_IXS_INTFLAG;    /**< Offset: 0x20 (R/W  32) SPI Interrupt Flag Register */
  __I   uint32_t                       SPI_IXS_STATUS;     /**< Offset: 0x24 (R/   32) SPI Status Register */
  __IO  uint32_t                       SPI_IXS_BUF;        /**< Offset: 0x28 (R/W  32) SPI Buffer Register */
  __IO  uint32_t                       SPI_IXS_BRG;        /**< Offset: 0x2C (R/W  32) SPI Baud Rate Register */
  __IO  uint32_t                       SPI_IXS_DBGCTRL;    /**< Offset: 0x30 (R/W  32) SPI Debug Control Register */
  __I   uint32_t                       SPI_IXS_SYNCBUSY;   /**< Offset: 0x34 (R/   32) SPI Sync Busy Register */
  __IO  uint32_t                       SPI_IXS_EVCTRL;     /**< Offset: 0x38 (R/W  32) SPI Event Control Register */
} spi_ixs_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA90_SPI_IXS_COMPONENT_H_ */
