/**
 * \brief Component description for TRAM
 *
 * Copyright (c) 2021 Microchip Technology Inc. and its subsidiaries.
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

/* file generated from device description version 2020-11-19T07:18:13Z */
#ifndef _SAML10_TRAM_COMPONENT_H_
#define _SAML10_TRAM_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR TRAM                                         */
/* ************************************************************************** */

/* -------- TRAM_CTRLA : (TRAM Offset: 0x00) (R/W 8) Control -------- */
#define TRAM_CTRLA_RESETVALUE                 _U_(0x00)                                            /**<  (TRAM_CTRLA) Control  Reset Value */

#define TRAM_CTRLA_SWRST_Pos                  _U_(0)                                               /**< (TRAM_CTRLA) Software Reset Position */
#define TRAM_CTRLA_SWRST_Msk                  (_U_(0x1) << TRAM_CTRLA_SWRST_Pos)                   /**< (TRAM_CTRLA) Software Reset Mask */
#define TRAM_CTRLA_SWRST(value)               (TRAM_CTRLA_SWRST_Msk & ((value) << TRAM_CTRLA_SWRST_Pos))
#define TRAM_CTRLA_ENABLE_Pos                 _U_(1)                                               /**< (TRAM_CTRLA) Enable Position */
#define TRAM_CTRLA_ENABLE_Msk                 (_U_(0x1) << TRAM_CTRLA_ENABLE_Pos)                  /**< (TRAM_CTRLA) Enable Mask */
#define TRAM_CTRLA_ENABLE(value)              (TRAM_CTRLA_ENABLE_Msk & ((value) << TRAM_CTRLA_ENABLE_Pos))
#define TRAM_CTRLA_TAMPERS_Pos                _U_(4)                                               /**< (TRAM_CTRLA) Tamper Erase Position */
#define TRAM_CTRLA_TAMPERS_Msk                (_U_(0x1) << TRAM_CTRLA_TAMPERS_Pos)                 /**< (TRAM_CTRLA) Tamper Erase Mask */
#define TRAM_CTRLA_TAMPERS(value)             (TRAM_CTRLA_TAMPERS_Msk & ((value) << TRAM_CTRLA_TAMPERS_Pos))
#define TRAM_CTRLA_DRP_Pos                    _U_(6)                                               /**< (TRAM_CTRLA) Data Remanence Prevention Position */
#define TRAM_CTRLA_DRP_Msk                    (_U_(0x1) << TRAM_CTRLA_DRP_Pos)                     /**< (TRAM_CTRLA) Data Remanence Prevention Mask */
#define TRAM_CTRLA_DRP(value)                 (TRAM_CTRLA_DRP_Msk & ((value) << TRAM_CTRLA_DRP_Pos))
#define TRAM_CTRLA_SILACC_Pos                 _U_(7)                                               /**< (TRAM_CTRLA) Silent Access Position */
#define TRAM_CTRLA_SILACC_Msk                 (_U_(0x1) << TRAM_CTRLA_SILACC_Pos)                  /**< (TRAM_CTRLA) Silent Access Mask */
#define TRAM_CTRLA_SILACC(value)              (TRAM_CTRLA_SILACC_Msk & ((value) << TRAM_CTRLA_SILACC_Pos))
#define TRAM_CTRLA_Msk                        _U_(0xD3)                                            /**< (TRAM_CTRLA) Register Mask  */


/* -------- TRAM_INTENCLR : (TRAM Offset: 0x04) (R/W 8) Interrupt Enable Clear -------- */
#define TRAM_INTENCLR_RESETVALUE              _U_(0x00)                                            /**<  (TRAM_INTENCLR) Interrupt Enable Clear  Reset Value */

#define TRAM_INTENCLR_ERR_Pos                 _U_(0)                                               /**< (TRAM_INTENCLR) TrustRAM Readout Error Interrupt Enable Position */
#define TRAM_INTENCLR_ERR_Msk                 (_U_(0x1) << TRAM_INTENCLR_ERR_Pos)                  /**< (TRAM_INTENCLR) TrustRAM Readout Error Interrupt Enable Mask */
#define TRAM_INTENCLR_ERR(value)              (TRAM_INTENCLR_ERR_Msk & ((value) << TRAM_INTENCLR_ERR_Pos))
#define TRAM_INTENCLR_DRP_Pos                 _U_(1)                                               /**< (TRAM_INTENCLR) Data Remanence Prevention Ended Interrupt Enable Position */
#define TRAM_INTENCLR_DRP_Msk                 (_U_(0x1) << TRAM_INTENCLR_DRP_Pos)                  /**< (TRAM_INTENCLR) Data Remanence Prevention Ended Interrupt Enable Mask */
#define TRAM_INTENCLR_DRP(value)              (TRAM_INTENCLR_DRP_Msk & ((value) << TRAM_INTENCLR_DRP_Pos))
#define TRAM_INTENCLR_Msk                     _U_(0x03)                                            /**< (TRAM_INTENCLR) Register Mask  */


/* -------- TRAM_INTENSET : (TRAM Offset: 0x05) (R/W 8) Interrupt Enable Set -------- */
#define TRAM_INTENSET_RESETVALUE              _U_(0x00)                                            /**<  (TRAM_INTENSET) Interrupt Enable Set  Reset Value */

#define TRAM_INTENSET_ERR_Pos                 _U_(0)                                               /**< (TRAM_INTENSET) TrustRAM Readout Error Interrupt Enable Position */
#define TRAM_INTENSET_ERR_Msk                 (_U_(0x1) << TRAM_INTENSET_ERR_Pos)                  /**< (TRAM_INTENSET) TrustRAM Readout Error Interrupt Enable Mask */
#define TRAM_INTENSET_ERR(value)              (TRAM_INTENSET_ERR_Msk & ((value) << TRAM_INTENSET_ERR_Pos))
#define TRAM_INTENSET_DRP_Pos                 _U_(1)                                               /**< (TRAM_INTENSET) Data Remanence Prevention Ended Interrupt Enable Position */
#define TRAM_INTENSET_DRP_Msk                 (_U_(0x1) << TRAM_INTENSET_DRP_Pos)                  /**< (TRAM_INTENSET) Data Remanence Prevention Ended Interrupt Enable Mask */
#define TRAM_INTENSET_DRP(value)              (TRAM_INTENSET_DRP_Msk & ((value) << TRAM_INTENSET_DRP_Pos))
#define TRAM_INTENSET_Msk                     _U_(0x03)                                            /**< (TRAM_INTENSET) Register Mask  */


/* -------- TRAM_INTFLAG : (TRAM Offset: 0x06) (R/W 8) Interrupt Flag Status and Clear -------- */
#define TRAM_INTFLAG_RESETVALUE               _U_(0x00)                                            /**<  (TRAM_INTFLAG) Interrupt Flag Status and Clear  Reset Value */

#define TRAM_INTFLAG_ERR_Pos                  _U_(0)                                               /**< (TRAM_INTFLAG) TrustRAM Readout Error Position */
#define TRAM_INTFLAG_ERR_Msk                  (_U_(0x1) << TRAM_INTFLAG_ERR_Pos)                   /**< (TRAM_INTFLAG) TrustRAM Readout Error Mask */
#define TRAM_INTFLAG_ERR(value)               (TRAM_INTFLAG_ERR_Msk & ((value) << TRAM_INTFLAG_ERR_Pos))
#define TRAM_INTFLAG_DRP_Pos                  _U_(1)                                               /**< (TRAM_INTFLAG) Data Remanence Prevention Ended Position */
#define TRAM_INTFLAG_DRP_Msk                  (_U_(0x1) << TRAM_INTFLAG_DRP_Pos)                   /**< (TRAM_INTFLAG) Data Remanence Prevention Ended Mask */
#define TRAM_INTFLAG_DRP(value)               (TRAM_INTFLAG_DRP_Msk & ((value) << TRAM_INTFLAG_DRP_Pos))
#define TRAM_INTFLAG_Msk                      _U_(0x03)                                            /**< (TRAM_INTFLAG) Register Mask  */


/* -------- TRAM_STATUS : (TRAM Offset: 0x07) ( R/ 8) Status -------- */
#define TRAM_STATUS_RESETVALUE                _U_(0x00)                                            /**<  (TRAM_STATUS) Status  Reset Value */

#define TRAM_STATUS_RAMINV_Pos                _U_(0)                                               /**< (TRAM_STATUS) RAM Inversion Bit Position */
#define TRAM_STATUS_RAMINV_Msk                (_U_(0x1) << TRAM_STATUS_RAMINV_Pos)                 /**< (TRAM_STATUS) RAM Inversion Bit Mask */
#define TRAM_STATUS_RAMINV(value)             (TRAM_STATUS_RAMINV_Msk & ((value) << TRAM_STATUS_RAMINV_Pos))
#define TRAM_STATUS_DRP_Pos                   _U_(1)                                               /**< (TRAM_STATUS) Data Remanence Prevention Ongoing Position */
#define TRAM_STATUS_DRP_Msk                   (_U_(0x1) << TRAM_STATUS_DRP_Pos)                    /**< (TRAM_STATUS) Data Remanence Prevention Ongoing Mask */
#define TRAM_STATUS_DRP(value)                (TRAM_STATUS_DRP_Msk & ((value) << TRAM_STATUS_DRP_Pos))
#define TRAM_STATUS_Msk                       _U_(0x03)                                            /**< (TRAM_STATUS) Register Mask  */


/* -------- TRAM_SYNCBUSY : (TRAM Offset: 0x08) ( R/ 32) Synchronization Busy Status -------- */
#define TRAM_SYNCBUSY_RESETVALUE              _U_(0x00)                                            /**<  (TRAM_SYNCBUSY) Synchronization Busy Status  Reset Value */

#define TRAM_SYNCBUSY_SWRST_Pos               _U_(0)                                               /**< (TRAM_SYNCBUSY) Software Reset Busy Position */
#define TRAM_SYNCBUSY_SWRST_Msk               (_U_(0x1) << TRAM_SYNCBUSY_SWRST_Pos)                /**< (TRAM_SYNCBUSY) Software Reset Busy Mask */
#define TRAM_SYNCBUSY_SWRST(value)            (TRAM_SYNCBUSY_SWRST_Msk & ((value) << TRAM_SYNCBUSY_SWRST_Pos))
#define TRAM_SYNCBUSY_ENABLE_Pos              _U_(1)                                               /**< (TRAM_SYNCBUSY) Enable Busy Position */
#define TRAM_SYNCBUSY_ENABLE_Msk              (_U_(0x1) << TRAM_SYNCBUSY_ENABLE_Pos)               /**< (TRAM_SYNCBUSY) Enable Busy Mask */
#define TRAM_SYNCBUSY_ENABLE(value)           (TRAM_SYNCBUSY_ENABLE_Msk & ((value) << TRAM_SYNCBUSY_ENABLE_Pos))
#define TRAM_SYNCBUSY_Msk                     _U_(0x00000003)                                      /**< (TRAM_SYNCBUSY) Register Mask  */


/* -------- TRAM_DSCC : (TRAM Offset: 0x0C) ( /W 32) Data Scramble Control -------- */
#define TRAM_DSCC_RESETVALUE                  _U_(0x00)                                            /**<  (TRAM_DSCC) Data Scramble Control  Reset Value */

#define TRAM_DSCC_DSCKEY_Pos                  _U_(0)                                               /**< (TRAM_DSCC) Data Scramble Key Position */
#define TRAM_DSCC_DSCKEY_Msk                  (_U_(0x3FFFFFFF) << TRAM_DSCC_DSCKEY_Pos)            /**< (TRAM_DSCC) Data Scramble Key Mask */
#define TRAM_DSCC_DSCKEY(value)               (TRAM_DSCC_DSCKEY_Msk & ((value) << TRAM_DSCC_DSCKEY_Pos))
#define TRAM_DSCC_DSCEN_Pos                   _U_(31)                                              /**< (TRAM_DSCC) Data Scramble Enable Position */
#define TRAM_DSCC_DSCEN_Msk                   (_U_(0x1) << TRAM_DSCC_DSCEN_Pos)                    /**< (TRAM_DSCC) Data Scramble Enable Mask */
#define TRAM_DSCC_DSCEN(value)                (TRAM_DSCC_DSCEN_Msk & ((value) << TRAM_DSCC_DSCEN_Pos))
#define TRAM_DSCC_Msk                         _U_(0xBFFFFFFF)                                      /**< (TRAM_DSCC) Register Mask  */


/* -------- TRAM_RAM : (TRAM Offset: 0x100) (R/W 32) TrustRAM -------- */
#define TRAM_RAM_RESETVALUE                   _U_(0x00)                                            /**<  (TRAM_RAM) TrustRAM  Reset Value */

#define TRAM_RAM_DATA_Pos                     _U_(0)                                               /**< (TRAM_RAM) Trust RAM Data Position */
#define TRAM_RAM_DATA_Msk                     (_U_(0xFFFFFFFF) << TRAM_RAM_DATA_Pos)               /**< (TRAM_RAM) Trust RAM Data Mask */
#define TRAM_RAM_DATA(value)                  (TRAM_RAM_DATA_Msk & ((value) << TRAM_RAM_DATA_Pos))
#define TRAM_RAM_Msk                          _U_(0xFFFFFFFF)                                      /**< (TRAM_RAM) Register Mask  */

/* BYTE mode */
#define TRAM_RAM_BYTE_BYTE0_Pos               _U_(0)                                               /**< (TRAM_RAM) Trust RAM Data Position */
#define TRAM_RAM_BYTE_BYTE0_Msk               (_U_(0xFF) << TRAM_RAM_BYTE_BYTE0_Pos)               /**< (TRAM_RAM) Trust RAM Data Mask */
#define TRAM_RAM_BYTE_BYTE0(value)            (TRAM_RAM_BYTE_BYTE0_Msk & ((value) << TRAM_RAM_BYTE_BYTE0_Pos))
#define TRAM_RAM_BYTE_BYTE1_Pos               _U_(8)                                               /**< (TRAM_RAM) Trust RAM Data Position */
#define TRAM_RAM_BYTE_BYTE1_Msk               (_U_(0xFF) << TRAM_RAM_BYTE_BYTE1_Pos)               /**< (TRAM_RAM) Trust RAM Data Mask */
#define TRAM_RAM_BYTE_BYTE1(value)            (TRAM_RAM_BYTE_BYTE1_Msk & ((value) << TRAM_RAM_BYTE_BYTE1_Pos))
#define TRAM_RAM_BYTE_BYTE2_Pos               _U_(16)                                              /**< (TRAM_RAM) Trust RAM Data Position */
#define TRAM_RAM_BYTE_BYTE2_Msk               (_U_(0xFF) << TRAM_RAM_BYTE_BYTE2_Pos)               /**< (TRAM_RAM) Trust RAM Data Mask */
#define TRAM_RAM_BYTE_BYTE2(value)            (TRAM_RAM_BYTE_BYTE2_Msk & ((value) << TRAM_RAM_BYTE_BYTE2_Pos))
#define TRAM_RAM_BYTE_BYTE3_Pos               _U_(24)                                              /**< (TRAM_RAM) Trust RAM Data Position */
#define TRAM_RAM_BYTE_BYTE3_Msk               (_U_(0xFF) << TRAM_RAM_BYTE_BYTE3_Pos)               /**< (TRAM_RAM) Trust RAM Data Mask */
#define TRAM_RAM_BYTE_BYTE3(value)            (TRAM_RAM_BYTE_BYTE3_Msk & ((value) << TRAM_RAM_BYTE_BYTE3_Pos))
#define TRAM_RAM_BYTE_Msk                     _U_(0xFFFFFFFF)                                       /**< (TRAM_RAM_BYTE) Register Mask  */

/* HALFWORD mode */
#define TRAM_RAM_HALFWORD_HWORD0_Pos          _U_(0)                                               /**< (TRAM_RAM) Trust RAM Halfword Data Position */
#define TRAM_RAM_HALFWORD_HWORD0_Msk          (_U_(0xFFFF) << TRAM_RAM_HALFWORD_HWORD0_Pos)        /**< (TRAM_RAM) Trust RAM Halfword Data Mask */
#define TRAM_RAM_HALFWORD_HWORD0(value)       (TRAM_RAM_HALFWORD_HWORD0_Msk & ((value) << TRAM_RAM_HALFWORD_HWORD0_Pos))
#define TRAM_RAM_HALFWORD_HWORD1_Pos          _U_(16)                                              /**< (TRAM_RAM) Trust RAM Halfword Data Position */
#define TRAM_RAM_HALFWORD_HWORD1_Msk          (_U_(0xFFFF) << TRAM_RAM_HALFWORD_HWORD1_Pos)        /**< (TRAM_RAM) Trust RAM Halfword Data Mask */
#define TRAM_RAM_HALFWORD_HWORD1(value)       (TRAM_RAM_HALFWORD_HWORD1_Msk & ((value) << TRAM_RAM_HALFWORD_HWORD1_Pos))
#define TRAM_RAM_HALFWORD_Msk                 _U_(0xFFFFFFFF)                                       /**< (TRAM_RAM_HALFWORD) Register Mask  */


/** \brief TRAM register offsets definitions */
#define TRAM_CTRLA_REG_OFST            (0x00)              /**< (TRAM_CTRLA) Control Offset */
#define TRAM_INTENCLR_REG_OFST         (0x04)              /**< (TRAM_INTENCLR) Interrupt Enable Clear Offset */
#define TRAM_INTENSET_REG_OFST         (0x05)              /**< (TRAM_INTENSET) Interrupt Enable Set Offset */
#define TRAM_INTFLAG_REG_OFST          (0x06)              /**< (TRAM_INTFLAG) Interrupt Flag Status and Clear Offset */
#define TRAM_STATUS_REG_OFST           (0x07)              /**< (TRAM_STATUS) Status Offset */
#define TRAM_SYNCBUSY_REG_OFST         (0x08)              /**< (TRAM_SYNCBUSY) Synchronization Busy Status Offset */
#define TRAM_DSCC_REG_OFST             (0x0C)              /**< (TRAM_DSCC) Data Scramble Control Offset */
#define TRAM_RAM_REG_OFST              (0x100)             /**< (TRAM_RAM) TrustRAM Offset */
#define TRAM_RAM0_REG_OFST             (0x100)             /**< (TRAM_RAM0) TrustRAM Offset */
#define TRAM_RAM1_REG_OFST             (0x104)             /**< (TRAM_RAM1) TrustRAM Offset */
#define TRAM_RAM2_REG_OFST             (0x108)             /**< (TRAM_RAM2) TrustRAM Offset */
#define TRAM_RAM3_REG_OFST             (0x10C)             /**< (TRAM_RAM3) TrustRAM Offset */
#define TRAM_RAM4_REG_OFST             (0x110)             /**< (TRAM_RAM4) TrustRAM Offset */
#define TRAM_RAM5_REG_OFST             (0x114)             /**< (TRAM_RAM5) TrustRAM Offset */
#define TRAM_RAM6_REG_OFST             (0x118)             /**< (TRAM_RAM6) TrustRAM Offset */
#define TRAM_RAM7_REG_OFST             (0x11C)             /**< (TRAM_RAM7) TrustRAM Offset */
#define TRAM_RAM8_REG_OFST             (0x120)             /**< (TRAM_RAM8) TrustRAM Offset */
#define TRAM_RAM9_REG_OFST             (0x124)             /**< (TRAM_RAM9) TrustRAM Offset */
#define TRAM_RAM10_REG_OFST            (0x128)             /**< (TRAM_RAM10) TrustRAM Offset */
#define TRAM_RAM11_REG_OFST            (0x12C)             /**< (TRAM_RAM11) TrustRAM Offset */
#define TRAM_RAM12_REG_OFST            (0x130)             /**< (TRAM_RAM12) TrustRAM Offset */
#define TRAM_RAM13_REG_OFST            (0x134)             /**< (TRAM_RAM13) TrustRAM Offset */
#define TRAM_RAM14_REG_OFST            (0x138)             /**< (TRAM_RAM14) TrustRAM Offset */
#define TRAM_RAM15_REG_OFST            (0x13C)             /**< (TRAM_RAM15) TrustRAM Offset */
#define TRAM_RAM16_REG_OFST            (0x140)             /**< (TRAM_RAM16) TrustRAM Offset */
#define TRAM_RAM17_REG_OFST            (0x144)             /**< (TRAM_RAM17) TrustRAM Offset */
#define TRAM_RAM18_REG_OFST            (0x148)             /**< (TRAM_RAM18) TrustRAM Offset */
#define TRAM_RAM19_REG_OFST            (0x14C)             /**< (TRAM_RAM19) TrustRAM Offset */
#define TRAM_RAM20_REG_OFST            (0x150)             /**< (TRAM_RAM20) TrustRAM Offset */
#define TRAM_RAM21_REG_OFST            (0x154)             /**< (TRAM_RAM21) TrustRAM Offset */
#define TRAM_RAM22_REG_OFST            (0x158)             /**< (TRAM_RAM22) TrustRAM Offset */
#define TRAM_RAM23_REG_OFST            (0x15C)             /**< (TRAM_RAM23) TrustRAM Offset */
#define TRAM_RAM24_REG_OFST            (0x160)             /**< (TRAM_RAM24) TrustRAM Offset */
#define TRAM_RAM25_REG_OFST            (0x164)             /**< (TRAM_RAM25) TrustRAM Offset */
#define TRAM_RAM26_REG_OFST            (0x168)             /**< (TRAM_RAM26) TrustRAM Offset */
#define TRAM_RAM27_REG_OFST            (0x16C)             /**< (TRAM_RAM27) TrustRAM Offset */
#define TRAM_RAM28_REG_OFST            (0x170)             /**< (TRAM_RAM28) TrustRAM Offset */
#define TRAM_RAM29_REG_OFST            (0x174)             /**< (TRAM_RAM29) TrustRAM Offset */
#define TRAM_RAM30_REG_OFST            (0x178)             /**< (TRAM_RAM30) TrustRAM Offset */
#define TRAM_RAM31_REG_OFST            (0x17C)             /**< (TRAM_RAM31) TrustRAM Offset */
#define TRAM_RAM32_REG_OFST            (0x180)             /**< (TRAM_RAM32) TrustRAM Offset */
#define TRAM_RAM33_REG_OFST            (0x184)             /**< (TRAM_RAM33) TrustRAM Offset */
#define TRAM_RAM34_REG_OFST            (0x188)             /**< (TRAM_RAM34) TrustRAM Offset */
#define TRAM_RAM35_REG_OFST            (0x18C)             /**< (TRAM_RAM35) TrustRAM Offset */
#define TRAM_RAM36_REG_OFST            (0x190)             /**< (TRAM_RAM36) TrustRAM Offset */
#define TRAM_RAM37_REG_OFST            (0x194)             /**< (TRAM_RAM37) TrustRAM Offset */
#define TRAM_RAM38_REG_OFST            (0x198)             /**< (TRAM_RAM38) TrustRAM Offset */
#define TRAM_RAM39_REG_OFST            (0x19C)             /**< (TRAM_RAM39) TrustRAM Offset */
#define TRAM_RAM40_REG_OFST            (0x1A0)             /**< (TRAM_RAM40) TrustRAM Offset */
#define TRAM_RAM41_REG_OFST            (0x1A4)             /**< (TRAM_RAM41) TrustRAM Offset */
#define TRAM_RAM42_REG_OFST            (0x1A8)             /**< (TRAM_RAM42) TrustRAM Offset */
#define TRAM_RAM43_REG_OFST            (0x1AC)             /**< (TRAM_RAM43) TrustRAM Offset */
#define TRAM_RAM44_REG_OFST            (0x1B0)             /**< (TRAM_RAM44) TrustRAM Offset */
#define TRAM_RAM45_REG_OFST            (0x1B4)             /**< (TRAM_RAM45) TrustRAM Offset */
#define TRAM_RAM46_REG_OFST            (0x1B8)             /**< (TRAM_RAM46) TrustRAM Offset */
#define TRAM_RAM47_REG_OFST            (0x1BC)             /**< (TRAM_RAM47) TrustRAM Offset */
#define TRAM_RAM48_REG_OFST            (0x1C0)             /**< (TRAM_RAM48) TrustRAM Offset */
#define TRAM_RAM49_REG_OFST            (0x1C4)             /**< (TRAM_RAM49) TrustRAM Offset */
#define TRAM_RAM50_REG_OFST            (0x1C8)             /**< (TRAM_RAM50) TrustRAM Offset */
#define TRAM_RAM51_REG_OFST            (0x1CC)             /**< (TRAM_RAM51) TrustRAM Offset */
#define TRAM_RAM52_REG_OFST            (0x1D0)             /**< (TRAM_RAM52) TrustRAM Offset */
#define TRAM_RAM53_REG_OFST            (0x1D4)             /**< (TRAM_RAM53) TrustRAM Offset */
#define TRAM_RAM54_REG_OFST            (0x1D8)             /**< (TRAM_RAM54) TrustRAM Offset */
#define TRAM_RAM55_REG_OFST            (0x1DC)             /**< (TRAM_RAM55) TrustRAM Offset */
#define TRAM_RAM56_REG_OFST            (0x1E0)             /**< (TRAM_RAM56) TrustRAM Offset */
#define TRAM_RAM57_REG_OFST            (0x1E4)             /**< (TRAM_RAM57) TrustRAM Offset */
#define TRAM_RAM58_REG_OFST            (0x1E8)             /**< (TRAM_RAM58) TrustRAM Offset */
#define TRAM_RAM59_REG_OFST            (0x1EC)             /**< (TRAM_RAM59) TrustRAM Offset */
#define TRAM_RAM60_REG_OFST            (0x1F0)             /**< (TRAM_RAM60) TrustRAM Offset */
#define TRAM_RAM61_REG_OFST            (0x1F4)             /**< (TRAM_RAM61) TrustRAM Offset */
#define TRAM_RAM62_REG_OFST            (0x1F8)             /**< (TRAM_RAM62) TrustRAM Offset */
#define TRAM_RAM63_REG_OFST            (0x1FC)             /**< (TRAM_RAM63) TrustRAM Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief TRAM register API structure */
typedef struct
{  /* TrustRAM */
  __IO  uint8_t                        TRAM_CTRLA;         /**< Offset: 0x00 (R/W  8) Control */
  __I   uint8_t                        Reserved1[0x03];
  __IO  uint8_t                        TRAM_INTENCLR;      /**< Offset: 0x04 (R/W  8) Interrupt Enable Clear */
  __IO  uint8_t                        TRAM_INTENSET;      /**< Offset: 0x05 (R/W  8) Interrupt Enable Set */
  __IO  uint8_t                        TRAM_INTFLAG;       /**< Offset: 0x06 (R/W  8) Interrupt Flag Status and Clear */
  __I   uint8_t                        TRAM_STATUS;        /**< Offset: 0x07 (R/   8) Status */
  __I   uint32_t                       TRAM_SYNCBUSY;      /**< Offset: 0x08 (R/   32) Synchronization Busy Status */
  __O   uint32_t                       TRAM_DSCC;          /**< Offset: 0x0C ( /W  32) Data Scramble Control */
  __I   uint8_t                        Reserved2[0xF0];
  __IO  uint32_t                       TRAM_RAM[64];       /**< Offset: 0x100 (R/W  32) TrustRAM */
} tram_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAML10_TRAM_COMPONENT_H_ */
