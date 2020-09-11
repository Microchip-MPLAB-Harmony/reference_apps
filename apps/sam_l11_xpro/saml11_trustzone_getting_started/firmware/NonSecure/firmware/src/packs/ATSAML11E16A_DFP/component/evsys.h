/**
 * \brief Component description for EVSYS
 *
 * Copyright (c) 2020 Microchip Technology Inc. and its subsidiaries.
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

/* file generated from device description version 2020-08-24T19:30:38Z */
#ifndef _SAML11_EVSYS_COMPONENT_H_
#define _SAML11_EVSYS_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR EVSYS                                        */
/* ************************************************************************** */

/* -------- EVSYS_CHANNEL : (EVSYS Offset: 0x00) (R/W 32) Channel n Control -------- */
#define EVSYS_CHANNEL_RESETVALUE              _U_(0x8000)                                          /**<  (EVSYS_CHANNEL) Channel n Control  Reset Value */

#define EVSYS_CHANNEL_EVGEN_Pos               _U_(0)                                               /**< (EVSYS_CHANNEL) Event Generator Selection Position */
#define EVSYS_CHANNEL_EVGEN_Msk               (_U_(0x3F) << EVSYS_CHANNEL_EVGEN_Pos)               /**< (EVSYS_CHANNEL) Event Generator Selection Mask */
#define EVSYS_CHANNEL_EVGEN(value)            (EVSYS_CHANNEL_EVGEN_Msk & ((value) << EVSYS_CHANNEL_EVGEN_Pos))
#define EVSYS_CHANNEL_PATH_Pos                _U_(8)                                               /**< (EVSYS_CHANNEL) Path Selection Position */
#define EVSYS_CHANNEL_PATH_Msk                (_U_(0x3) << EVSYS_CHANNEL_PATH_Pos)                 /**< (EVSYS_CHANNEL) Path Selection Mask */
#define EVSYS_CHANNEL_PATH(value)             (EVSYS_CHANNEL_PATH_Msk & ((value) << EVSYS_CHANNEL_PATH_Pos))
#define   EVSYS_CHANNEL_PATH_SYNCHRONOUS_Val  _U_(0x0)                                             /**< (EVSYS_CHANNEL) Synchronous path  */
#define   EVSYS_CHANNEL_PATH_RESYNCHRONIZED_Val _U_(0x1)                                             /**< (EVSYS_CHANNEL) Resynchronized path  */
#define   EVSYS_CHANNEL_PATH_ASYNCHRONOUS_Val _U_(0x2)                                             /**< (EVSYS_CHANNEL) Asynchronous path  */
#define EVSYS_CHANNEL_PATH_SYNCHRONOUS        (EVSYS_CHANNEL_PATH_SYNCHRONOUS_Val << EVSYS_CHANNEL_PATH_Pos) /**< (EVSYS_CHANNEL) Synchronous path Position  */
#define EVSYS_CHANNEL_PATH_RESYNCHRONIZED     (EVSYS_CHANNEL_PATH_RESYNCHRONIZED_Val << EVSYS_CHANNEL_PATH_Pos) /**< (EVSYS_CHANNEL) Resynchronized path Position  */
#define EVSYS_CHANNEL_PATH_ASYNCHRONOUS       (EVSYS_CHANNEL_PATH_ASYNCHRONOUS_Val << EVSYS_CHANNEL_PATH_Pos) /**< (EVSYS_CHANNEL) Asynchronous path Position  */
#define EVSYS_CHANNEL_EDGSEL_Pos              _U_(10)                                              /**< (EVSYS_CHANNEL) Edge Detection Selection Position */
#define EVSYS_CHANNEL_EDGSEL_Msk              (_U_(0x3) << EVSYS_CHANNEL_EDGSEL_Pos)               /**< (EVSYS_CHANNEL) Edge Detection Selection Mask */
#define EVSYS_CHANNEL_EDGSEL(value)           (EVSYS_CHANNEL_EDGSEL_Msk & ((value) << EVSYS_CHANNEL_EDGSEL_Pos))
#define   EVSYS_CHANNEL_EDGSEL_NO_EVT_OUTPUT_Val _U_(0x0)                                             /**< (EVSYS_CHANNEL) No event output when using the resynchronized or synchronous path  */
#define   EVSYS_CHANNEL_EDGSEL_RISING_EDGE_Val _U_(0x1)                                             /**< (EVSYS_CHANNEL) Event detection only on the rising edge of the signal from the event generator when using the resynchronized or synchronous path  */
#define   EVSYS_CHANNEL_EDGSEL_FALLING_EDGE_Val _U_(0x2)                                             /**< (EVSYS_CHANNEL) Event detection only on the falling edge of the signal from the event generator when using the resynchronized or synchronous path  */
#define   EVSYS_CHANNEL_EDGSEL_BOTH_EDGES_Val _U_(0x3)                                             /**< (EVSYS_CHANNEL) Event detection on rising and falling edges of the signal from the event generator when using the resynchronized or synchronous path  */
#define EVSYS_CHANNEL_EDGSEL_NO_EVT_OUTPUT    (EVSYS_CHANNEL_EDGSEL_NO_EVT_OUTPUT_Val << EVSYS_CHANNEL_EDGSEL_Pos) /**< (EVSYS_CHANNEL) No event output when using the resynchronized or synchronous path Position  */
#define EVSYS_CHANNEL_EDGSEL_RISING_EDGE      (EVSYS_CHANNEL_EDGSEL_RISING_EDGE_Val << EVSYS_CHANNEL_EDGSEL_Pos) /**< (EVSYS_CHANNEL) Event detection only on the rising edge of the signal from the event generator when using the resynchronized or synchronous path Position  */
#define EVSYS_CHANNEL_EDGSEL_FALLING_EDGE     (EVSYS_CHANNEL_EDGSEL_FALLING_EDGE_Val << EVSYS_CHANNEL_EDGSEL_Pos) /**< (EVSYS_CHANNEL) Event detection only on the falling edge of the signal from the event generator when using the resynchronized or synchronous path Position  */
#define EVSYS_CHANNEL_EDGSEL_BOTH_EDGES       (EVSYS_CHANNEL_EDGSEL_BOTH_EDGES_Val << EVSYS_CHANNEL_EDGSEL_Pos) /**< (EVSYS_CHANNEL) Event detection on rising and falling edges of the signal from the event generator when using the resynchronized or synchronous path Position  */
#define EVSYS_CHANNEL_RUNSTDBY_Pos            _U_(14)                                              /**< (EVSYS_CHANNEL) Run in standby Position */
#define EVSYS_CHANNEL_RUNSTDBY_Msk            (_U_(0x1) << EVSYS_CHANNEL_RUNSTDBY_Pos)             /**< (EVSYS_CHANNEL) Run in standby Mask */
#define EVSYS_CHANNEL_RUNSTDBY(value)         (EVSYS_CHANNEL_RUNSTDBY_Msk & ((value) << EVSYS_CHANNEL_RUNSTDBY_Pos))
#define EVSYS_CHANNEL_ONDEMAND_Pos            _U_(15)                                              /**< (EVSYS_CHANNEL) Generic Clock On Demand Position */
#define EVSYS_CHANNEL_ONDEMAND_Msk            (_U_(0x1) << EVSYS_CHANNEL_ONDEMAND_Pos)             /**< (EVSYS_CHANNEL) Generic Clock On Demand Mask */
#define EVSYS_CHANNEL_ONDEMAND(value)         (EVSYS_CHANNEL_ONDEMAND_Msk & ((value) << EVSYS_CHANNEL_ONDEMAND_Pos))
#define EVSYS_CHANNEL_Msk                     _U_(0x0000CF3F)                                      /**< (EVSYS_CHANNEL) Register Mask  */


/* -------- EVSYS_CHINTENCLR : (EVSYS Offset: 0x04) (R/W 8) Channel n Interrupt Enable Clear -------- */
#define EVSYS_CHINTENCLR_RESETVALUE           _U_(0x00)                                            /**<  (EVSYS_CHINTENCLR) Channel n Interrupt Enable Clear  Reset Value */

#define EVSYS_CHINTENCLR_OVR_Pos              _U_(0)                                               /**< (EVSYS_CHINTENCLR) Channel Overrun Interrupt Disable Position */
#define EVSYS_CHINTENCLR_OVR_Msk              (_U_(0x1) << EVSYS_CHINTENCLR_OVR_Pos)               /**< (EVSYS_CHINTENCLR) Channel Overrun Interrupt Disable Mask */
#define EVSYS_CHINTENCLR_OVR(value)           (EVSYS_CHINTENCLR_OVR_Msk & ((value) << EVSYS_CHINTENCLR_OVR_Pos))
#define EVSYS_CHINTENCLR_EVD_Pos              _U_(1)                                               /**< (EVSYS_CHINTENCLR) Channel Event Detected Interrupt Disable Position */
#define EVSYS_CHINTENCLR_EVD_Msk              (_U_(0x1) << EVSYS_CHINTENCLR_EVD_Pos)               /**< (EVSYS_CHINTENCLR) Channel Event Detected Interrupt Disable Mask */
#define EVSYS_CHINTENCLR_EVD(value)           (EVSYS_CHINTENCLR_EVD_Msk & ((value) << EVSYS_CHINTENCLR_EVD_Pos))
#define EVSYS_CHINTENCLR_Msk                  _U_(0x03)                                            /**< (EVSYS_CHINTENCLR) Register Mask  */


/* -------- EVSYS_CHINTENSET : (EVSYS Offset: 0x05) (R/W 8) Channel n Interrupt Enable Set -------- */
#define EVSYS_CHINTENSET_RESETVALUE           _U_(0x00)                                            /**<  (EVSYS_CHINTENSET) Channel n Interrupt Enable Set  Reset Value */

#define EVSYS_CHINTENSET_OVR_Pos              _U_(0)                                               /**< (EVSYS_CHINTENSET) Channel Overrun Interrupt Enable Position */
#define EVSYS_CHINTENSET_OVR_Msk              (_U_(0x1) << EVSYS_CHINTENSET_OVR_Pos)               /**< (EVSYS_CHINTENSET) Channel Overrun Interrupt Enable Mask */
#define EVSYS_CHINTENSET_OVR(value)           (EVSYS_CHINTENSET_OVR_Msk & ((value) << EVSYS_CHINTENSET_OVR_Pos))
#define EVSYS_CHINTENSET_EVD_Pos              _U_(1)                                               /**< (EVSYS_CHINTENSET) Channel Event Detected Interrupt Enable Position */
#define EVSYS_CHINTENSET_EVD_Msk              (_U_(0x1) << EVSYS_CHINTENSET_EVD_Pos)               /**< (EVSYS_CHINTENSET) Channel Event Detected Interrupt Enable Mask */
#define EVSYS_CHINTENSET_EVD(value)           (EVSYS_CHINTENSET_EVD_Msk & ((value) << EVSYS_CHINTENSET_EVD_Pos))
#define EVSYS_CHINTENSET_Msk                  _U_(0x03)                                            /**< (EVSYS_CHINTENSET) Register Mask  */


/* -------- EVSYS_CHINTFLAG : (EVSYS Offset: 0x06) (R/W 8) Channel n Interrupt Flag Status and Clear -------- */
#define EVSYS_CHINTFLAG_RESETVALUE            _U_(0x00)                                            /**<  (EVSYS_CHINTFLAG) Channel n Interrupt Flag Status and Clear  Reset Value */

#define EVSYS_CHINTFLAG_OVR_Pos               _U_(0)                                               /**< (EVSYS_CHINTFLAG) Channel Overrun Position */
#define EVSYS_CHINTFLAG_OVR_Msk               (_U_(0x1) << EVSYS_CHINTFLAG_OVR_Pos)                /**< (EVSYS_CHINTFLAG) Channel Overrun Mask */
#define EVSYS_CHINTFLAG_OVR(value)            (EVSYS_CHINTFLAG_OVR_Msk & ((value) << EVSYS_CHINTFLAG_OVR_Pos))
#define EVSYS_CHINTFLAG_EVD_Pos               _U_(1)                                               /**< (EVSYS_CHINTFLAG) Channel Event Detected Position */
#define EVSYS_CHINTFLAG_EVD_Msk               (_U_(0x1) << EVSYS_CHINTFLAG_EVD_Pos)                /**< (EVSYS_CHINTFLAG) Channel Event Detected Mask */
#define EVSYS_CHINTFLAG_EVD(value)            (EVSYS_CHINTFLAG_EVD_Msk & ((value) << EVSYS_CHINTFLAG_EVD_Pos))
#define EVSYS_CHINTFLAG_Msk                   _U_(0x03)                                            /**< (EVSYS_CHINTFLAG) Register Mask  */


/* -------- EVSYS_CHSTATUS : (EVSYS Offset: 0x07) ( R/ 8) Channel n Status -------- */
#define EVSYS_CHSTATUS_RESETVALUE             _U_(0x01)                                            /**<  (EVSYS_CHSTATUS) Channel n Status  Reset Value */

#define EVSYS_CHSTATUS_RDYUSR_Pos             _U_(0)                                               /**< (EVSYS_CHSTATUS) Ready User Position */
#define EVSYS_CHSTATUS_RDYUSR_Msk             (_U_(0x1) << EVSYS_CHSTATUS_RDYUSR_Pos)              /**< (EVSYS_CHSTATUS) Ready User Mask */
#define EVSYS_CHSTATUS_RDYUSR(value)          (EVSYS_CHSTATUS_RDYUSR_Msk & ((value) << EVSYS_CHSTATUS_RDYUSR_Pos))
#define EVSYS_CHSTATUS_BUSYCH_Pos             _U_(1)                                               /**< (EVSYS_CHSTATUS) Busy Channel Position */
#define EVSYS_CHSTATUS_BUSYCH_Msk             (_U_(0x1) << EVSYS_CHSTATUS_BUSYCH_Pos)              /**< (EVSYS_CHSTATUS) Busy Channel Mask */
#define EVSYS_CHSTATUS_BUSYCH(value)          (EVSYS_CHSTATUS_BUSYCH_Msk & ((value) << EVSYS_CHSTATUS_BUSYCH_Pos))
#define EVSYS_CHSTATUS_Msk                    _U_(0x03)                                            /**< (EVSYS_CHSTATUS) Register Mask  */


/* -------- EVSYS_CTRLA : (EVSYS Offset: 0x00) ( /W 8) Control -------- */
#define EVSYS_CTRLA_RESETVALUE                _U_(0x00)                                            /**<  (EVSYS_CTRLA) Control  Reset Value */

#define EVSYS_CTRLA_SWRST_Pos                 _U_(0)                                               /**< (EVSYS_CTRLA) Software Reset Position */
#define EVSYS_CTRLA_SWRST_Msk                 (_U_(0x1) << EVSYS_CTRLA_SWRST_Pos)                  /**< (EVSYS_CTRLA) Software Reset Mask */
#define EVSYS_CTRLA_SWRST(value)              (EVSYS_CTRLA_SWRST_Msk & ((value) << EVSYS_CTRLA_SWRST_Pos))
#define EVSYS_CTRLA_Msk                       _U_(0x01)                                            /**< (EVSYS_CTRLA) Register Mask  */


/* -------- EVSYS_SWEVT : (EVSYS Offset: 0x04) ( /W 32) Software Event -------- */
#define EVSYS_SWEVT_RESETVALUE                _U_(0x00)                                            /**<  (EVSYS_SWEVT) Software Event  Reset Value */

#define EVSYS_SWEVT_CHANNEL0_Pos              _U_(0)                                               /**< (EVSYS_SWEVT) Channel 0 Software Selection Position */
#define EVSYS_SWEVT_CHANNEL0_Msk              (_U_(0x1) << EVSYS_SWEVT_CHANNEL0_Pos)               /**< (EVSYS_SWEVT) Channel 0 Software Selection Mask */
#define EVSYS_SWEVT_CHANNEL0(value)           (EVSYS_SWEVT_CHANNEL0_Msk & ((value) << EVSYS_SWEVT_CHANNEL0_Pos))
#define EVSYS_SWEVT_CHANNEL1_Pos              _U_(1)                                               /**< (EVSYS_SWEVT) Channel 1 Software Selection Position */
#define EVSYS_SWEVT_CHANNEL1_Msk              (_U_(0x1) << EVSYS_SWEVT_CHANNEL1_Pos)               /**< (EVSYS_SWEVT) Channel 1 Software Selection Mask */
#define EVSYS_SWEVT_CHANNEL1(value)           (EVSYS_SWEVT_CHANNEL1_Msk & ((value) << EVSYS_SWEVT_CHANNEL1_Pos))
#define EVSYS_SWEVT_CHANNEL2_Pos              _U_(2)                                               /**< (EVSYS_SWEVT) Channel 2 Software Selection Position */
#define EVSYS_SWEVT_CHANNEL2_Msk              (_U_(0x1) << EVSYS_SWEVT_CHANNEL2_Pos)               /**< (EVSYS_SWEVT) Channel 2 Software Selection Mask */
#define EVSYS_SWEVT_CHANNEL2(value)           (EVSYS_SWEVT_CHANNEL2_Msk & ((value) << EVSYS_SWEVT_CHANNEL2_Pos))
#define EVSYS_SWEVT_CHANNEL3_Pos              _U_(3)                                               /**< (EVSYS_SWEVT) Channel 3 Software Selection Position */
#define EVSYS_SWEVT_CHANNEL3_Msk              (_U_(0x1) << EVSYS_SWEVT_CHANNEL3_Pos)               /**< (EVSYS_SWEVT) Channel 3 Software Selection Mask */
#define EVSYS_SWEVT_CHANNEL3(value)           (EVSYS_SWEVT_CHANNEL3_Msk & ((value) << EVSYS_SWEVT_CHANNEL3_Pos))
#define EVSYS_SWEVT_CHANNEL4_Pos              _U_(4)                                               /**< (EVSYS_SWEVT) Channel 4 Software Selection Position */
#define EVSYS_SWEVT_CHANNEL4_Msk              (_U_(0x1) << EVSYS_SWEVT_CHANNEL4_Pos)               /**< (EVSYS_SWEVT) Channel 4 Software Selection Mask */
#define EVSYS_SWEVT_CHANNEL4(value)           (EVSYS_SWEVT_CHANNEL4_Msk & ((value) << EVSYS_SWEVT_CHANNEL4_Pos))
#define EVSYS_SWEVT_CHANNEL5_Pos              _U_(5)                                               /**< (EVSYS_SWEVT) Channel 5 Software Selection Position */
#define EVSYS_SWEVT_CHANNEL5_Msk              (_U_(0x1) << EVSYS_SWEVT_CHANNEL5_Pos)               /**< (EVSYS_SWEVT) Channel 5 Software Selection Mask */
#define EVSYS_SWEVT_CHANNEL5(value)           (EVSYS_SWEVT_CHANNEL5_Msk & ((value) << EVSYS_SWEVT_CHANNEL5_Pos))
#define EVSYS_SWEVT_CHANNEL6_Pos              _U_(6)                                               /**< (EVSYS_SWEVT) Channel 6 Software Selection Position */
#define EVSYS_SWEVT_CHANNEL6_Msk              (_U_(0x1) << EVSYS_SWEVT_CHANNEL6_Pos)               /**< (EVSYS_SWEVT) Channel 6 Software Selection Mask */
#define EVSYS_SWEVT_CHANNEL6(value)           (EVSYS_SWEVT_CHANNEL6_Msk & ((value) << EVSYS_SWEVT_CHANNEL6_Pos))
#define EVSYS_SWEVT_CHANNEL7_Pos              _U_(7)                                               /**< (EVSYS_SWEVT) Channel 7 Software Selection Position */
#define EVSYS_SWEVT_CHANNEL7_Msk              (_U_(0x1) << EVSYS_SWEVT_CHANNEL7_Pos)               /**< (EVSYS_SWEVT) Channel 7 Software Selection Mask */
#define EVSYS_SWEVT_CHANNEL7(value)           (EVSYS_SWEVT_CHANNEL7_Msk & ((value) << EVSYS_SWEVT_CHANNEL7_Pos))
#define EVSYS_SWEVT_Msk                       _U_(0x000000FF)                                      /**< (EVSYS_SWEVT) Register Mask  */

#define EVSYS_SWEVT_CHANNEL_Pos               _U_(0)                                               /**< (EVSYS_SWEVT Position) Channel 7 Software Selection */
#define EVSYS_SWEVT_CHANNEL_Msk               (_U_(0xFF) << EVSYS_SWEVT_CHANNEL_Pos)               /**< (EVSYS_SWEVT Mask) CHANNEL */
#define EVSYS_SWEVT_CHANNEL(value)            (EVSYS_SWEVT_CHANNEL_Msk & ((value) << EVSYS_SWEVT_CHANNEL_Pos)) 

/* -------- EVSYS_PRICTRL : (EVSYS Offset: 0x08) (R/W 8) Priority Control -------- */
#define EVSYS_PRICTRL_RESETVALUE              _U_(0x00)                                            /**<  (EVSYS_PRICTRL) Priority Control  Reset Value */

#define EVSYS_PRICTRL_PRI_Pos                 _U_(0)                                               /**< (EVSYS_PRICTRL) Channel Priority Number Position */
#define EVSYS_PRICTRL_PRI_Msk                 (_U_(0x3) << EVSYS_PRICTRL_PRI_Pos)                  /**< (EVSYS_PRICTRL) Channel Priority Number Mask */
#define EVSYS_PRICTRL_PRI(value)              (EVSYS_PRICTRL_PRI_Msk & ((value) << EVSYS_PRICTRL_PRI_Pos))
#define EVSYS_PRICTRL_RREN_Pos                _U_(7)                                               /**< (EVSYS_PRICTRL) Round-Robin Scheduling Enable Position */
#define EVSYS_PRICTRL_RREN_Msk                (_U_(0x1) << EVSYS_PRICTRL_RREN_Pos)                 /**< (EVSYS_PRICTRL) Round-Robin Scheduling Enable Mask */
#define EVSYS_PRICTRL_RREN(value)             (EVSYS_PRICTRL_RREN_Msk & ((value) << EVSYS_PRICTRL_RREN_Pos))
#define EVSYS_PRICTRL_Msk                     _U_(0x83)                                            /**< (EVSYS_PRICTRL) Register Mask  */


/* -------- EVSYS_INTPEND : (EVSYS Offset: 0x10) (R/W 16) Channel Pending Interrupt -------- */
#define EVSYS_INTPEND_RESETVALUE              _U_(0x4000)                                          /**<  (EVSYS_INTPEND) Channel Pending Interrupt  Reset Value */

#define EVSYS_INTPEND_ID_Pos                  _U_(0)                                               /**< (EVSYS_INTPEND) Channel ID Position */
#define EVSYS_INTPEND_ID_Msk                  (_U_(0x3) << EVSYS_INTPEND_ID_Pos)                   /**< (EVSYS_INTPEND) Channel ID Mask */
#define EVSYS_INTPEND_ID(value)               (EVSYS_INTPEND_ID_Msk & ((value) << EVSYS_INTPEND_ID_Pos))
#define EVSYS_INTPEND_OVR_Pos                 _U_(8)                                               /**< (EVSYS_INTPEND) Channel Overrun Position */
#define EVSYS_INTPEND_OVR_Msk                 (_U_(0x1) << EVSYS_INTPEND_OVR_Pos)                  /**< (EVSYS_INTPEND) Channel Overrun Mask */
#define EVSYS_INTPEND_OVR(value)              (EVSYS_INTPEND_OVR_Msk & ((value) << EVSYS_INTPEND_OVR_Pos))
#define EVSYS_INTPEND_EVD_Pos                 _U_(9)                                               /**< (EVSYS_INTPEND) Channel Event Detected Position */
#define EVSYS_INTPEND_EVD_Msk                 (_U_(0x1) << EVSYS_INTPEND_EVD_Pos)                  /**< (EVSYS_INTPEND) Channel Event Detected Mask */
#define EVSYS_INTPEND_EVD(value)              (EVSYS_INTPEND_EVD_Msk & ((value) << EVSYS_INTPEND_EVD_Pos))
#define EVSYS_INTPEND_READY_Pos               _U_(14)                                              /**< (EVSYS_INTPEND) Ready Position */
#define EVSYS_INTPEND_READY_Msk               (_U_(0x1) << EVSYS_INTPEND_READY_Pos)                /**< (EVSYS_INTPEND) Ready Mask */
#define EVSYS_INTPEND_READY(value)            (EVSYS_INTPEND_READY_Msk & ((value) << EVSYS_INTPEND_READY_Pos))
#define EVSYS_INTPEND_BUSY_Pos                _U_(15)                                              /**< (EVSYS_INTPEND) Busy Position */
#define EVSYS_INTPEND_BUSY_Msk                (_U_(0x1) << EVSYS_INTPEND_BUSY_Pos)                 /**< (EVSYS_INTPEND) Busy Mask */
#define EVSYS_INTPEND_BUSY(value)             (EVSYS_INTPEND_BUSY_Msk & ((value) << EVSYS_INTPEND_BUSY_Pos))
#define EVSYS_INTPEND_Msk                     _U_(0xC303)                                          /**< (EVSYS_INTPEND) Register Mask  */


/* -------- EVSYS_INTSTATUS : (EVSYS Offset: 0x14) ( R/ 32) Interrupt Status -------- */
#define EVSYS_INTSTATUS_RESETVALUE            _U_(0x00)                                            /**<  (EVSYS_INTSTATUS) Interrupt Status  Reset Value */

#define EVSYS_INTSTATUS_CHINT0_Pos            _U_(0)                                               /**< (EVSYS_INTSTATUS) Channel 0 Pending Interrupt Position */
#define EVSYS_INTSTATUS_CHINT0_Msk            (_U_(0x1) << EVSYS_INTSTATUS_CHINT0_Pos)             /**< (EVSYS_INTSTATUS) Channel 0 Pending Interrupt Mask */
#define EVSYS_INTSTATUS_CHINT0(value)         (EVSYS_INTSTATUS_CHINT0_Msk & ((value) << EVSYS_INTSTATUS_CHINT0_Pos))
#define EVSYS_INTSTATUS_CHINT1_Pos            _U_(1)                                               /**< (EVSYS_INTSTATUS) Channel 1 Pending Interrupt Position */
#define EVSYS_INTSTATUS_CHINT1_Msk            (_U_(0x1) << EVSYS_INTSTATUS_CHINT1_Pos)             /**< (EVSYS_INTSTATUS) Channel 1 Pending Interrupt Mask */
#define EVSYS_INTSTATUS_CHINT1(value)         (EVSYS_INTSTATUS_CHINT1_Msk & ((value) << EVSYS_INTSTATUS_CHINT1_Pos))
#define EVSYS_INTSTATUS_CHINT2_Pos            _U_(2)                                               /**< (EVSYS_INTSTATUS) Channel 2 Pending Interrupt Position */
#define EVSYS_INTSTATUS_CHINT2_Msk            (_U_(0x1) << EVSYS_INTSTATUS_CHINT2_Pos)             /**< (EVSYS_INTSTATUS) Channel 2 Pending Interrupt Mask */
#define EVSYS_INTSTATUS_CHINT2(value)         (EVSYS_INTSTATUS_CHINT2_Msk & ((value) << EVSYS_INTSTATUS_CHINT2_Pos))
#define EVSYS_INTSTATUS_CHINT3_Pos            _U_(3)                                               /**< (EVSYS_INTSTATUS) Channel 3 Pending Interrupt Position */
#define EVSYS_INTSTATUS_CHINT3_Msk            (_U_(0x1) << EVSYS_INTSTATUS_CHINT3_Pos)             /**< (EVSYS_INTSTATUS) Channel 3 Pending Interrupt Mask */
#define EVSYS_INTSTATUS_CHINT3(value)         (EVSYS_INTSTATUS_CHINT3_Msk & ((value) << EVSYS_INTSTATUS_CHINT3_Pos))
#define EVSYS_INTSTATUS_Msk                   _U_(0x0000000F)                                      /**< (EVSYS_INTSTATUS) Register Mask  */

#define EVSYS_INTSTATUS_CHINT_Pos             _U_(0)                                               /**< (EVSYS_INTSTATUS Position) Channel 3 Pending Interrupt */
#define EVSYS_INTSTATUS_CHINT_Msk             (_U_(0xF) << EVSYS_INTSTATUS_CHINT_Pos)              /**< (EVSYS_INTSTATUS Mask) CHINT */
#define EVSYS_INTSTATUS_CHINT(value)          (EVSYS_INTSTATUS_CHINT_Msk & ((value) << EVSYS_INTSTATUS_CHINT_Pos)) 

/* -------- EVSYS_BUSYCH : (EVSYS Offset: 0x18) ( R/ 32) Busy Channels -------- */
#define EVSYS_BUSYCH_RESETVALUE               _U_(0x00)                                            /**<  (EVSYS_BUSYCH) Busy Channels  Reset Value */

#define EVSYS_BUSYCH_BUSYCH0_Pos              _U_(0)                                               /**< (EVSYS_BUSYCH) Busy Channel 0 Position */
#define EVSYS_BUSYCH_BUSYCH0_Msk              (_U_(0x1) << EVSYS_BUSYCH_BUSYCH0_Pos)               /**< (EVSYS_BUSYCH) Busy Channel 0 Mask */
#define EVSYS_BUSYCH_BUSYCH0(value)           (EVSYS_BUSYCH_BUSYCH0_Msk & ((value) << EVSYS_BUSYCH_BUSYCH0_Pos))
#define EVSYS_BUSYCH_BUSYCH1_Pos              _U_(1)                                               /**< (EVSYS_BUSYCH) Busy Channel 1 Position */
#define EVSYS_BUSYCH_BUSYCH1_Msk              (_U_(0x1) << EVSYS_BUSYCH_BUSYCH1_Pos)               /**< (EVSYS_BUSYCH) Busy Channel 1 Mask */
#define EVSYS_BUSYCH_BUSYCH1(value)           (EVSYS_BUSYCH_BUSYCH1_Msk & ((value) << EVSYS_BUSYCH_BUSYCH1_Pos))
#define EVSYS_BUSYCH_BUSYCH2_Pos              _U_(2)                                               /**< (EVSYS_BUSYCH) Busy Channel 2 Position */
#define EVSYS_BUSYCH_BUSYCH2_Msk              (_U_(0x1) << EVSYS_BUSYCH_BUSYCH2_Pos)               /**< (EVSYS_BUSYCH) Busy Channel 2 Mask */
#define EVSYS_BUSYCH_BUSYCH2(value)           (EVSYS_BUSYCH_BUSYCH2_Msk & ((value) << EVSYS_BUSYCH_BUSYCH2_Pos))
#define EVSYS_BUSYCH_BUSYCH3_Pos              _U_(3)                                               /**< (EVSYS_BUSYCH) Busy Channel 3 Position */
#define EVSYS_BUSYCH_BUSYCH3_Msk              (_U_(0x1) << EVSYS_BUSYCH_BUSYCH3_Pos)               /**< (EVSYS_BUSYCH) Busy Channel 3 Mask */
#define EVSYS_BUSYCH_BUSYCH3(value)           (EVSYS_BUSYCH_BUSYCH3_Msk & ((value) << EVSYS_BUSYCH_BUSYCH3_Pos))
#define EVSYS_BUSYCH_Msk                      _U_(0x0000000F)                                      /**< (EVSYS_BUSYCH) Register Mask  */

#define EVSYS_BUSYCH_BUSYCH_Pos               _U_(0)                                               /**< (EVSYS_BUSYCH Position) Busy Channel 3 */
#define EVSYS_BUSYCH_BUSYCH_Msk               (_U_(0xF) << EVSYS_BUSYCH_BUSYCH_Pos)                /**< (EVSYS_BUSYCH Mask) BUSYCH */
#define EVSYS_BUSYCH_BUSYCH(value)            (EVSYS_BUSYCH_BUSYCH_Msk & ((value) << EVSYS_BUSYCH_BUSYCH_Pos)) 

/* -------- EVSYS_READYUSR : (EVSYS Offset: 0x1C) ( R/ 32) Ready Users -------- */
#define EVSYS_READYUSR_RESETVALUE             _U_(0xFFFFFFFF)                                      /**<  (EVSYS_READYUSR) Ready Users  Reset Value */

#define EVSYS_READYUSR_READYUSR0_Pos          _U_(0)                                               /**< (EVSYS_READYUSR) Ready User for Channel 0 Position */
#define EVSYS_READYUSR_READYUSR0_Msk          (_U_(0x1) << EVSYS_READYUSR_READYUSR0_Pos)           /**< (EVSYS_READYUSR) Ready User for Channel 0 Mask */
#define EVSYS_READYUSR_READYUSR0(value)       (EVSYS_READYUSR_READYUSR0_Msk & ((value) << EVSYS_READYUSR_READYUSR0_Pos))
#define EVSYS_READYUSR_READYUSR1_Pos          _U_(1)                                               /**< (EVSYS_READYUSR) Ready User for Channel 1 Position */
#define EVSYS_READYUSR_READYUSR1_Msk          (_U_(0x1) << EVSYS_READYUSR_READYUSR1_Pos)           /**< (EVSYS_READYUSR) Ready User for Channel 1 Mask */
#define EVSYS_READYUSR_READYUSR1(value)       (EVSYS_READYUSR_READYUSR1_Msk & ((value) << EVSYS_READYUSR_READYUSR1_Pos))
#define EVSYS_READYUSR_READYUSR2_Pos          _U_(2)                                               /**< (EVSYS_READYUSR) Ready User for Channel 2 Position */
#define EVSYS_READYUSR_READYUSR2_Msk          (_U_(0x1) << EVSYS_READYUSR_READYUSR2_Pos)           /**< (EVSYS_READYUSR) Ready User for Channel 2 Mask */
#define EVSYS_READYUSR_READYUSR2(value)       (EVSYS_READYUSR_READYUSR2_Msk & ((value) << EVSYS_READYUSR_READYUSR2_Pos))
#define EVSYS_READYUSR_READYUSR3_Pos          _U_(3)                                               /**< (EVSYS_READYUSR) Ready User for Channel 3 Position */
#define EVSYS_READYUSR_READYUSR3_Msk          (_U_(0x1) << EVSYS_READYUSR_READYUSR3_Pos)           /**< (EVSYS_READYUSR) Ready User for Channel 3 Mask */
#define EVSYS_READYUSR_READYUSR3(value)       (EVSYS_READYUSR_READYUSR3_Msk & ((value) << EVSYS_READYUSR_READYUSR3_Pos))
#define EVSYS_READYUSR_Msk                    _U_(0x0000000F)                                      /**< (EVSYS_READYUSR) Register Mask  */

#define EVSYS_READYUSR_READYUSR_Pos           _U_(0)                                               /**< (EVSYS_READYUSR Position) Ready User for Channel 3 */
#define EVSYS_READYUSR_READYUSR_Msk           (_U_(0xF) << EVSYS_READYUSR_READYUSR_Pos)            /**< (EVSYS_READYUSR Mask) READYUSR */
#define EVSYS_READYUSR_READYUSR(value)        (EVSYS_READYUSR_READYUSR_Msk & ((value) << EVSYS_READYUSR_READYUSR_Pos)) 

/* -------- EVSYS_USER : (EVSYS Offset: 0x120) (R/W 8) User Multiplexer n -------- */
#define EVSYS_USER_RESETVALUE                 _U_(0x00)                                            /**<  (EVSYS_USER) User Multiplexer n  Reset Value */

#define EVSYS_USER_CHANNEL_Pos                _U_(0)                                               /**< (EVSYS_USER) Channel Event Selection Position */
#define EVSYS_USER_CHANNEL_Msk                (_U_(0xF) << EVSYS_USER_CHANNEL_Pos)                 /**< (EVSYS_USER) Channel Event Selection Mask */
#define EVSYS_USER_CHANNEL(value)             (EVSYS_USER_CHANNEL_Msk & ((value) << EVSYS_USER_CHANNEL_Pos))
#define EVSYS_USER_Msk                        _U_(0x0F)                                            /**< (EVSYS_USER) Register Mask  */


/* -------- EVSYS_INTENCLR : (EVSYS Offset: 0x1D4) (R/W 8) Interrupt Enable Clear -------- */
#define EVSYS_INTENCLR_RESETVALUE             _U_(0x00)                                            /**<  (EVSYS_INTENCLR) Interrupt Enable Clear  Reset Value */

#define EVSYS_INTENCLR_NSCHK_Pos              _U_(0)                                               /**< (EVSYS_INTENCLR) Non-Secure Check Interrupt Enable Position */
#define EVSYS_INTENCLR_NSCHK_Msk              (_U_(0x1) << EVSYS_INTENCLR_NSCHK_Pos)               /**< (EVSYS_INTENCLR) Non-Secure Check Interrupt Enable Mask */
#define EVSYS_INTENCLR_NSCHK(value)           (EVSYS_INTENCLR_NSCHK_Msk & ((value) << EVSYS_INTENCLR_NSCHK_Pos))
#define EVSYS_INTENCLR_Msk                    _U_(0x01)                                            /**< (EVSYS_INTENCLR) Register Mask  */


/* -------- EVSYS_INTENSET : (EVSYS Offset: 0x1D5) (R/W 8) Interrupt Enable Set -------- */
#define EVSYS_INTENSET_RESETVALUE             _U_(0x00)                                            /**<  (EVSYS_INTENSET) Interrupt Enable Set  Reset Value */

#define EVSYS_INTENSET_NSCHK_Pos              _U_(0)                                               /**< (EVSYS_INTENSET) Non-Secure Check Interrupt Enable Position */
#define EVSYS_INTENSET_NSCHK_Msk              (_U_(0x1) << EVSYS_INTENSET_NSCHK_Pos)               /**< (EVSYS_INTENSET) Non-Secure Check Interrupt Enable Mask */
#define EVSYS_INTENSET_NSCHK(value)           (EVSYS_INTENSET_NSCHK_Msk & ((value) << EVSYS_INTENSET_NSCHK_Pos))
#define EVSYS_INTENSET_Msk                    _U_(0x01)                                            /**< (EVSYS_INTENSET) Register Mask  */


/* -------- EVSYS_INTFLAG : (EVSYS Offset: 0x1D6) (R/W 8) Interrupt Flag Status and Clear -------- */
#define EVSYS_INTFLAG_RESETVALUE              _U_(0x00)                                            /**<  (EVSYS_INTFLAG) Interrupt Flag Status and Clear  Reset Value */

#define EVSYS_INTFLAG_NSCHK_Pos               _U_(0)                                               /**< (EVSYS_INTFLAG) Non-Secure Check Position */
#define EVSYS_INTFLAG_NSCHK_Msk               (_U_(0x1) << EVSYS_INTFLAG_NSCHK_Pos)                /**< (EVSYS_INTFLAG) Non-Secure Check Mask */
#define EVSYS_INTFLAG_NSCHK(value)            (EVSYS_INTFLAG_NSCHK_Msk & ((value) << EVSYS_INTFLAG_NSCHK_Pos))
#define EVSYS_INTFLAG_Msk                     _U_(0x01)                                            /**< (EVSYS_INTFLAG) Register Mask  */


/* -------- EVSYS_NONSECCHAN : (EVSYS Offset: 0x1D8) (R/W 32) Channels Security Attribution -------- */
#define EVSYS_NONSECCHAN_RESETVALUE           _U_(0x00)                                            /**<  (EVSYS_NONSECCHAN) Channels Security Attribution  Reset Value */

#define EVSYS_NONSECCHAN_CHANNEL0_Pos         _U_(0)                                               /**< (EVSYS_NONSECCHAN) Non-Secure for Channel 0 Position */
#define EVSYS_NONSECCHAN_CHANNEL0_Msk         (_U_(0x1) << EVSYS_NONSECCHAN_CHANNEL0_Pos)          /**< (EVSYS_NONSECCHAN) Non-Secure for Channel 0 Mask */
#define EVSYS_NONSECCHAN_CHANNEL0(value)      (EVSYS_NONSECCHAN_CHANNEL0_Msk & ((value) << EVSYS_NONSECCHAN_CHANNEL0_Pos))
#define EVSYS_NONSECCHAN_CHANNEL1_Pos         _U_(1)                                               /**< (EVSYS_NONSECCHAN) Non-Secure for Channel 1 Position */
#define EVSYS_NONSECCHAN_CHANNEL1_Msk         (_U_(0x1) << EVSYS_NONSECCHAN_CHANNEL1_Pos)          /**< (EVSYS_NONSECCHAN) Non-Secure for Channel 1 Mask */
#define EVSYS_NONSECCHAN_CHANNEL1(value)      (EVSYS_NONSECCHAN_CHANNEL1_Msk & ((value) << EVSYS_NONSECCHAN_CHANNEL1_Pos))
#define EVSYS_NONSECCHAN_CHANNEL2_Pos         _U_(2)                                               /**< (EVSYS_NONSECCHAN) Non-Secure for Channel 2 Position */
#define EVSYS_NONSECCHAN_CHANNEL2_Msk         (_U_(0x1) << EVSYS_NONSECCHAN_CHANNEL2_Pos)          /**< (EVSYS_NONSECCHAN) Non-Secure for Channel 2 Mask */
#define EVSYS_NONSECCHAN_CHANNEL2(value)      (EVSYS_NONSECCHAN_CHANNEL2_Msk & ((value) << EVSYS_NONSECCHAN_CHANNEL2_Pos))
#define EVSYS_NONSECCHAN_CHANNEL3_Pos         _U_(3)                                               /**< (EVSYS_NONSECCHAN) Non-Secure for Channel 3 Position */
#define EVSYS_NONSECCHAN_CHANNEL3_Msk         (_U_(0x1) << EVSYS_NONSECCHAN_CHANNEL3_Pos)          /**< (EVSYS_NONSECCHAN) Non-Secure for Channel 3 Mask */
#define EVSYS_NONSECCHAN_CHANNEL3(value)      (EVSYS_NONSECCHAN_CHANNEL3_Msk & ((value) << EVSYS_NONSECCHAN_CHANNEL3_Pos))
#define EVSYS_NONSECCHAN_CHANNEL4_Pos         _U_(4)                                               /**< (EVSYS_NONSECCHAN) Non-Secure for Channel 4 Position */
#define EVSYS_NONSECCHAN_CHANNEL4_Msk         (_U_(0x1) << EVSYS_NONSECCHAN_CHANNEL4_Pos)          /**< (EVSYS_NONSECCHAN) Non-Secure for Channel 4 Mask */
#define EVSYS_NONSECCHAN_CHANNEL4(value)      (EVSYS_NONSECCHAN_CHANNEL4_Msk & ((value) << EVSYS_NONSECCHAN_CHANNEL4_Pos))
#define EVSYS_NONSECCHAN_CHANNEL5_Pos         _U_(5)                                               /**< (EVSYS_NONSECCHAN) Non-Secure for Channel 5 Position */
#define EVSYS_NONSECCHAN_CHANNEL5_Msk         (_U_(0x1) << EVSYS_NONSECCHAN_CHANNEL5_Pos)          /**< (EVSYS_NONSECCHAN) Non-Secure for Channel 5 Mask */
#define EVSYS_NONSECCHAN_CHANNEL5(value)      (EVSYS_NONSECCHAN_CHANNEL5_Msk & ((value) << EVSYS_NONSECCHAN_CHANNEL5_Pos))
#define EVSYS_NONSECCHAN_CHANNEL6_Pos         _U_(6)                                               /**< (EVSYS_NONSECCHAN) Non-Secure for Channel 6 Position */
#define EVSYS_NONSECCHAN_CHANNEL6_Msk         (_U_(0x1) << EVSYS_NONSECCHAN_CHANNEL6_Pos)          /**< (EVSYS_NONSECCHAN) Non-Secure for Channel 6 Mask */
#define EVSYS_NONSECCHAN_CHANNEL6(value)      (EVSYS_NONSECCHAN_CHANNEL6_Msk & ((value) << EVSYS_NONSECCHAN_CHANNEL6_Pos))
#define EVSYS_NONSECCHAN_CHANNEL7_Pos         _U_(7)                                               /**< (EVSYS_NONSECCHAN) Non-Secure for Channel 7 Position */
#define EVSYS_NONSECCHAN_CHANNEL7_Msk         (_U_(0x1) << EVSYS_NONSECCHAN_CHANNEL7_Pos)          /**< (EVSYS_NONSECCHAN) Non-Secure for Channel 7 Mask */
#define EVSYS_NONSECCHAN_CHANNEL7(value)      (EVSYS_NONSECCHAN_CHANNEL7_Msk & ((value) << EVSYS_NONSECCHAN_CHANNEL7_Pos))
#define EVSYS_NONSECCHAN_Msk                  _U_(0x000000FF)                                      /**< (EVSYS_NONSECCHAN) Register Mask  */

#define EVSYS_NONSECCHAN_CHANNEL_Pos          _U_(0)                                               /**< (EVSYS_NONSECCHAN Position) Non-Secure for Channel 7 */
#define EVSYS_NONSECCHAN_CHANNEL_Msk          (_U_(0xFF) << EVSYS_NONSECCHAN_CHANNEL_Pos)          /**< (EVSYS_NONSECCHAN Mask) CHANNEL */
#define EVSYS_NONSECCHAN_CHANNEL(value)       (EVSYS_NONSECCHAN_CHANNEL_Msk & ((value) << EVSYS_NONSECCHAN_CHANNEL_Pos)) 

/* -------- EVSYS_NSCHKCHAN : (EVSYS Offset: 0x1DC) (R/W 32) Non-Secure Channels Check -------- */
#define EVSYS_NSCHKCHAN_RESETVALUE            _U_(0x00)                                            /**<  (EVSYS_NSCHKCHAN) Non-Secure Channels Check  Reset Value */

#define EVSYS_NSCHKCHAN_CHANNEL0_Pos          _U_(0)                                               /**< (EVSYS_NSCHKCHAN) Channel 0 to be checked as non-secured Position */
#define EVSYS_NSCHKCHAN_CHANNEL0_Msk          (_U_(0x1) << EVSYS_NSCHKCHAN_CHANNEL0_Pos)           /**< (EVSYS_NSCHKCHAN) Channel 0 to be checked as non-secured Mask */
#define EVSYS_NSCHKCHAN_CHANNEL0(value)       (EVSYS_NSCHKCHAN_CHANNEL0_Msk & ((value) << EVSYS_NSCHKCHAN_CHANNEL0_Pos))
#define EVSYS_NSCHKCHAN_CHANNEL1_Pos          _U_(1)                                               /**< (EVSYS_NSCHKCHAN) Channel 1 to be checked as non-secured Position */
#define EVSYS_NSCHKCHAN_CHANNEL1_Msk          (_U_(0x1) << EVSYS_NSCHKCHAN_CHANNEL1_Pos)           /**< (EVSYS_NSCHKCHAN) Channel 1 to be checked as non-secured Mask */
#define EVSYS_NSCHKCHAN_CHANNEL1(value)       (EVSYS_NSCHKCHAN_CHANNEL1_Msk & ((value) << EVSYS_NSCHKCHAN_CHANNEL1_Pos))
#define EVSYS_NSCHKCHAN_CHANNEL2_Pos          _U_(2)                                               /**< (EVSYS_NSCHKCHAN) Channel 2 to be checked as non-secured Position */
#define EVSYS_NSCHKCHAN_CHANNEL2_Msk          (_U_(0x1) << EVSYS_NSCHKCHAN_CHANNEL2_Pos)           /**< (EVSYS_NSCHKCHAN) Channel 2 to be checked as non-secured Mask */
#define EVSYS_NSCHKCHAN_CHANNEL2(value)       (EVSYS_NSCHKCHAN_CHANNEL2_Msk & ((value) << EVSYS_NSCHKCHAN_CHANNEL2_Pos))
#define EVSYS_NSCHKCHAN_CHANNEL3_Pos          _U_(3)                                               /**< (EVSYS_NSCHKCHAN) Channel 3 to be checked as non-secured Position */
#define EVSYS_NSCHKCHAN_CHANNEL3_Msk          (_U_(0x1) << EVSYS_NSCHKCHAN_CHANNEL3_Pos)           /**< (EVSYS_NSCHKCHAN) Channel 3 to be checked as non-secured Mask */
#define EVSYS_NSCHKCHAN_CHANNEL3(value)       (EVSYS_NSCHKCHAN_CHANNEL3_Msk & ((value) << EVSYS_NSCHKCHAN_CHANNEL3_Pos))
#define EVSYS_NSCHKCHAN_CHANNEL4_Pos          _U_(4)                                               /**< (EVSYS_NSCHKCHAN) Channel 4 to be checked as non-secured Position */
#define EVSYS_NSCHKCHAN_CHANNEL4_Msk          (_U_(0x1) << EVSYS_NSCHKCHAN_CHANNEL4_Pos)           /**< (EVSYS_NSCHKCHAN) Channel 4 to be checked as non-secured Mask */
#define EVSYS_NSCHKCHAN_CHANNEL4(value)       (EVSYS_NSCHKCHAN_CHANNEL4_Msk & ((value) << EVSYS_NSCHKCHAN_CHANNEL4_Pos))
#define EVSYS_NSCHKCHAN_CHANNEL5_Pos          _U_(5)                                               /**< (EVSYS_NSCHKCHAN) Channel 5 to be checked as non-secured Position */
#define EVSYS_NSCHKCHAN_CHANNEL5_Msk          (_U_(0x1) << EVSYS_NSCHKCHAN_CHANNEL5_Pos)           /**< (EVSYS_NSCHKCHAN) Channel 5 to be checked as non-secured Mask */
#define EVSYS_NSCHKCHAN_CHANNEL5(value)       (EVSYS_NSCHKCHAN_CHANNEL5_Msk & ((value) << EVSYS_NSCHKCHAN_CHANNEL5_Pos))
#define EVSYS_NSCHKCHAN_CHANNEL6_Pos          _U_(6)                                               /**< (EVSYS_NSCHKCHAN) Channel 6 to be checked as non-secured Position */
#define EVSYS_NSCHKCHAN_CHANNEL6_Msk          (_U_(0x1) << EVSYS_NSCHKCHAN_CHANNEL6_Pos)           /**< (EVSYS_NSCHKCHAN) Channel 6 to be checked as non-secured Mask */
#define EVSYS_NSCHKCHAN_CHANNEL6(value)       (EVSYS_NSCHKCHAN_CHANNEL6_Msk & ((value) << EVSYS_NSCHKCHAN_CHANNEL6_Pos))
#define EVSYS_NSCHKCHAN_CHANNEL7_Pos          _U_(7)                                               /**< (EVSYS_NSCHKCHAN) Channel 7 to be checked as non-secured Position */
#define EVSYS_NSCHKCHAN_CHANNEL7_Msk          (_U_(0x1) << EVSYS_NSCHKCHAN_CHANNEL7_Pos)           /**< (EVSYS_NSCHKCHAN) Channel 7 to be checked as non-secured Mask */
#define EVSYS_NSCHKCHAN_CHANNEL7(value)       (EVSYS_NSCHKCHAN_CHANNEL7_Msk & ((value) << EVSYS_NSCHKCHAN_CHANNEL7_Pos))
#define EVSYS_NSCHKCHAN_Msk                   _U_(0x000000FF)                                      /**< (EVSYS_NSCHKCHAN) Register Mask  */

#define EVSYS_NSCHKCHAN_CHANNEL_Pos           _U_(0)                                               /**< (EVSYS_NSCHKCHAN Position) Channel 7 to be checked as non-secured */
#define EVSYS_NSCHKCHAN_CHANNEL_Msk           (_U_(0xFF) << EVSYS_NSCHKCHAN_CHANNEL_Pos)           /**< (EVSYS_NSCHKCHAN Mask) CHANNEL */
#define EVSYS_NSCHKCHAN_CHANNEL(value)        (EVSYS_NSCHKCHAN_CHANNEL_Msk & ((value) << EVSYS_NSCHKCHAN_CHANNEL_Pos)) 

/* -------- EVSYS_NONSECUSER : (EVSYS Offset: 0x1E0) (R/W 32) Users Security Attribution -------- */
#define EVSYS_NONSECUSER_RESETVALUE           _U_(0x00)                                            /**<  (EVSYS_NONSECUSER) Users Security Attribution  Reset Value */

#define EVSYS_NONSECUSER_USER0_Pos            _U_(0)                                               /**< (EVSYS_NONSECUSER) Non-Secure for User 0 Position */
#define EVSYS_NONSECUSER_USER0_Msk            (_U_(0x1) << EVSYS_NONSECUSER_USER0_Pos)             /**< (EVSYS_NONSECUSER) Non-Secure for User 0 Mask */
#define EVSYS_NONSECUSER_USER0(value)         (EVSYS_NONSECUSER_USER0_Msk & ((value) << EVSYS_NONSECUSER_USER0_Pos))
#define EVSYS_NONSECUSER_USER1_Pos            _U_(1)                                               /**< (EVSYS_NONSECUSER) Non-Secure for User 1 Position */
#define EVSYS_NONSECUSER_USER1_Msk            (_U_(0x1) << EVSYS_NONSECUSER_USER1_Pos)             /**< (EVSYS_NONSECUSER) Non-Secure for User 1 Mask */
#define EVSYS_NONSECUSER_USER1(value)         (EVSYS_NONSECUSER_USER1_Msk & ((value) << EVSYS_NONSECUSER_USER1_Pos))
#define EVSYS_NONSECUSER_USER2_Pos            _U_(2)                                               /**< (EVSYS_NONSECUSER) Non-Secure for User 2 Position */
#define EVSYS_NONSECUSER_USER2_Msk            (_U_(0x1) << EVSYS_NONSECUSER_USER2_Pos)             /**< (EVSYS_NONSECUSER) Non-Secure for User 2 Mask */
#define EVSYS_NONSECUSER_USER2(value)         (EVSYS_NONSECUSER_USER2_Msk & ((value) << EVSYS_NONSECUSER_USER2_Pos))
#define EVSYS_NONSECUSER_USER3_Pos            _U_(3)                                               /**< (EVSYS_NONSECUSER) Non-Secure for User 3 Position */
#define EVSYS_NONSECUSER_USER3_Msk            (_U_(0x1) << EVSYS_NONSECUSER_USER3_Pos)             /**< (EVSYS_NONSECUSER) Non-Secure for User 3 Mask */
#define EVSYS_NONSECUSER_USER3(value)         (EVSYS_NONSECUSER_USER3_Msk & ((value) << EVSYS_NONSECUSER_USER3_Pos))
#define EVSYS_NONSECUSER_USER4_Pos            _U_(4)                                               /**< (EVSYS_NONSECUSER) Non-Secure for User 4 Position */
#define EVSYS_NONSECUSER_USER4_Msk            (_U_(0x1) << EVSYS_NONSECUSER_USER4_Pos)             /**< (EVSYS_NONSECUSER) Non-Secure for User 4 Mask */
#define EVSYS_NONSECUSER_USER4(value)         (EVSYS_NONSECUSER_USER4_Msk & ((value) << EVSYS_NONSECUSER_USER4_Pos))
#define EVSYS_NONSECUSER_USER5_Pos            _U_(5)                                               /**< (EVSYS_NONSECUSER) Non-Secure for User 5 Position */
#define EVSYS_NONSECUSER_USER5_Msk            (_U_(0x1) << EVSYS_NONSECUSER_USER5_Pos)             /**< (EVSYS_NONSECUSER) Non-Secure for User 5 Mask */
#define EVSYS_NONSECUSER_USER5(value)         (EVSYS_NONSECUSER_USER5_Msk & ((value) << EVSYS_NONSECUSER_USER5_Pos))
#define EVSYS_NONSECUSER_USER6_Pos            _U_(6)                                               /**< (EVSYS_NONSECUSER) Non-Secure for User 6 Position */
#define EVSYS_NONSECUSER_USER6_Msk            (_U_(0x1) << EVSYS_NONSECUSER_USER6_Pos)             /**< (EVSYS_NONSECUSER) Non-Secure for User 6 Mask */
#define EVSYS_NONSECUSER_USER6(value)         (EVSYS_NONSECUSER_USER6_Msk & ((value) << EVSYS_NONSECUSER_USER6_Pos))
#define EVSYS_NONSECUSER_USER7_Pos            _U_(7)                                               /**< (EVSYS_NONSECUSER) Non-Secure for User 7 Position */
#define EVSYS_NONSECUSER_USER7_Msk            (_U_(0x1) << EVSYS_NONSECUSER_USER7_Pos)             /**< (EVSYS_NONSECUSER) Non-Secure for User 7 Mask */
#define EVSYS_NONSECUSER_USER7(value)         (EVSYS_NONSECUSER_USER7_Msk & ((value) << EVSYS_NONSECUSER_USER7_Pos))
#define EVSYS_NONSECUSER_USER8_Pos            _U_(8)                                               /**< (EVSYS_NONSECUSER) Non-Secure for User 8 Position */
#define EVSYS_NONSECUSER_USER8_Msk            (_U_(0x1) << EVSYS_NONSECUSER_USER8_Pos)             /**< (EVSYS_NONSECUSER) Non-Secure for User 8 Mask */
#define EVSYS_NONSECUSER_USER8(value)         (EVSYS_NONSECUSER_USER8_Msk & ((value) << EVSYS_NONSECUSER_USER8_Pos))
#define EVSYS_NONSECUSER_USER9_Pos            _U_(9)                                               /**< (EVSYS_NONSECUSER) Non-Secure for User 9 Position */
#define EVSYS_NONSECUSER_USER9_Msk            (_U_(0x1) << EVSYS_NONSECUSER_USER9_Pos)             /**< (EVSYS_NONSECUSER) Non-Secure for User 9 Mask */
#define EVSYS_NONSECUSER_USER9(value)         (EVSYS_NONSECUSER_USER9_Msk & ((value) << EVSYS_NONSECUSER_USER9_Pos))
#define EVSYS_NONSECUSER_USER10_Pos           _U_(10)                                              /**< (EVSYS_NONSECUSER) Non-Secure for User 10 Position */
#define EVSYS_NONSECUSER_USER10_Msk           (_U_(0x1) << EVSYS_NONSECUSER_USER10_Pos)            /**< (EVSYS_NONSECUSER) Non-Secure for User 10 Mask */
#define EVSYS_NONSECUSER_USER10(value)        (EVSYS_NONSECUSER_USER10_Msk & ((value) << EVSYS_NONSECUSER_USER10_Pos))
#define EVSYS_NONSECUSER_USER11_Pos           _U_(11)                                              /**< (EVSYS_NONSECUSER) Non-Secure for User 11 Position */
#define EVSYS_NONSECUSER_USER11_Msk           (_U_(0x1) << EVSYS_NONSECUSER_USER11_Pos)            /**< (EVSYS_NONSECUSER) Non-Secure for User 11 Mask */
#define EVSYS_NONSECUSER_USER11(value)        (EVSYS_NONSECUSER_USER11_Msk & ((value) << EVSYS_NONSECUSER_USER11_Pos))
#define EVSYS_NONSECUSER_USER12_Pos           _U_(12)                                              /**< (EVSYS_NONSECUSER) Non-Secure for User 12 Position */
#define EVSYS_NONSECUSER_USER12_Msk           (_U_(0x1) << EVSYS_NONSECUSER_USER12_Pos)            /**< (EVSYS_NONSECUSER) Non-Secure for User 12 Mask */
#define EVSYS_NONSECUSER_USER12(value)        (EVSYS_NONSECUSER_USER12_Msk & ((value) << EVSYS_NONSECUSER_USER12_Pos))
#define EVSYS_NONSECUSER_USER13_Pos           _U_(13)                                              /**< (EVSYS_NONSECUSER) Non-Secure for User 13 Position */
#define EVSYS_NONSECUSER_USER13_Msk           (_U_(0x1) << EVSYS_NONSECUSER_USER13_Pos)            /**< (EVSYS_NONSECUSER) Non-Secure for User 13 Mask */
#define EVSYS_NONSECUSER_USER13(value)        (EVSYS_NONSECUSER_USER13_Msk & ((value) << EVSYS_NONSECUSER_USER13_Pos))
#define EVSYS_NONSECUSER_USER14_Pos           _U_(14)                                              /**< (EVSYS_NONSECUSER) Non-Secure for User 14 Position */
#define EVSYS_NONSECUSER_USER14_Msk           (_U_(0x1) << EVSYS_NONSECUSER_USER14_Pos)            /**< (EVSYS_NONSECUSER) Non-Secure for User 14 Mask */
#define EVSYS_NONSECUSER_USER14(value)        (EVSYS_NONSECUSER_USER14_Msk & ((value) << EVSYS_NONSECUSER_USER14_Pos))
#define EVSYS_NONSECUSER_USER15_Pos           _U_(15)                                              /**< (EVSYS_NONSECUSER) Non-Secure for User 15 Position */
#define EVSYS_NONSECUSER_USER15_Msk           (_U_(0x1) << EVSYS_NONSECUSER_USER15_Pos)            /**< (EVSYS_NONSECUSER) Non-Secure for User 15 Mask */
#define EVSYS_NONSECUSER_USER15(value)        (EVSYS_NONSECUSER_USER15_Msk & ((value) << EVSYS_NONSECUSER_USER15_Pos))
#define EVSYS_NONSECUSER_USER16_Pos           _U_(16)                                              /**< (EVSYS_NONSECUSER) Non-Secure for User 16 Position */
#define EVSYS_NONSECUSER_USER16_Msk           (_U_(0x1) << EVSYS_NONSECUSER_USER16_Pos)            /**< (EVSYS_NONSECUSER) Non-Secure for User 16 Mask */
#define EVSYS_NONSECUSER_USER16(value)        (EVSYS_NONSECUSER_USER16_Msk & ((value) << EVSYS_NONSECUSER_USER16_Pos))
#define EVSYS_NONSECUSER_USER17_Pos           _U_(17)                                              /**< (EVSYS_NONSECUSER) Non-Secure for User 17 Position */
#define EVSYS_NONSECUSER_USER17_Msk           (_U_(0x1) << EVSYS_NONSECUSER_USER17_Pos)            /**< (EVSYS_NONSECUSER) Non-Secure for User 17 Mask */
#define EVSYS_NONSECUSER_USER17(value)        (EVSYS_NONSECUSER_USER17_Msk & ((value) << EVSYS_NONSECUSER_USER17_Pos))
#define EVSYS_NONSECUSER_USER18_Pos           _U_(18)                                              /**< (EVSYS_NONSECUSER) Non-Secure for User 18 Position */
#define EVSYS_NONSECUSER_USER18_Msk           (_U_(0x1) << EVSYS_NONSECUSER_USER18_Pos)            /**< (EVSYS_NONSECUSER) Non-Secure for User 18 Mask */
#define EVSYS_NONSECUSER_USER18(value)        (EVSYS_NONSECUSER_USER18_Msk & ((value) << EVSYS_NONSECUSER_USER18_Pos))
#define EVSYS_NONSECUSER_USER19_Pos           _U_(19)                                              /**< (EVSYS_NONSECUSER) Non-Secure for User 19 Position */
#define EVSYS_NONSECUSER_USER19_Msk           (_U_(0x1) << EVSYS_NONSECUSER_USER19_Pos)            /**< (EVSYS_NONSECUSER) Non-Secure for User 19 Mask */
#define EVSYS_NONSECUSER_USER19(value)        (EVSYS_NONSECUSER_USER19_Msk & ((value) << EVSYS_NONSECUSER_USER19_Pos))
#define EVSYS_NONSECUSER_USER20_Pos           _U_(20)                                              /**< (EVSYS_NONSECUSER) Non-Secure for User 20 Position */
#define EVSYS_NONSECUSER_USER20_Msk           (_U_(0x1) << EVSYS_NONSECUSER_USER20_Pos)            /**< (EVSYS_NONSECUSER) Non-Secure for User 20 Mask */
#define EVSYS_NONSECUSER_USER20(value)        (EVSYS_NONSECUSER_USER20_Msk & ((value) << EVSYS_NONSECUSER_USER20_Pos))
#define EVSYS_NONSECUSER_USER21_Pos           _U_(21)                                              /**< (EVSYS_NONSECUSER) Non-Secure for User 21 Position */
#define EVSYS_NONSECUSER_USER21_Msk           (_U_(0x1) << EVSYS_NONSECUSER_USER21_Pos)            /**< (EVSYS_NONSECUSER) Non-Secure for User 21 Mask */
#define EVSYS_NONSECUSER_USER21(value)        (EVSYS_NONSECUSER_USER21_Msk & ((value) << EVSYS_NONSECUSER_USER21_Pos))
#define EVSYS_NONSECUSER_USER22_Pos           _U_(22)                                              /**< (EVSYS_NONSECUSER) Non-Secure for User 22 Position */
#define EVSYS_NONSECUSER_USER22_Msk           (_U_(0x1) << EVSYS_NONSECUSER_USER22_Pos)            /**< (EVSYS_NONSECUSER) Non-Secure for User 22 Mask */
#define EVSYS_NONSECUSER_USER22(value)        (EVSYS_NONSECUSER_USER22_Msk & ((value) << EVSYS_NONSECUSER_USER22_Pos))
#define EVSYS_NONSECUSER_Msk                  _U_(0x007FFFFF)                                      /**< (EVSYS_NONSECUSER) Register Mask  */

#define EVSYS_NONSECUSER_USER_Pos             _U_(0)                                               /**< (EVSYS_NONSECUSER Position) Non-Secure for User 22 */
#define EVSYS_NONSECUSER_USER_Msk             (_U_(0x7FFFFF) << EVSYS_NONSECUSER_USER_Pos)         /**< (EVSYS_NONSECUSER Mask) USER */
#define EVSYS_NONSECUSER_USER(value)          (EVSYS_NONSECUSER_USER_Msk & ((value) << EVSYS_NONSECUSER_USER_Pos)) 

/* -------- EVSYS_NSCHKUSER : (EVSYS Offset: 0x1F0) (R/W 32) Non-Secure Users Check -------- */
#define EVSYS_NSCHKUSER_RESETVALUE            _U_(0x00)                                            /**<  (EVSYS_NSCHKUSER) Non-Secure Users Check  Reset Value */

#define EVSYS_NSCHKUSER_USER0_Pos             _U_(0)                                               /**< (EVSYS_NSCHKUSER) User 0 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER_USER0_Msk             (_U_(0x1) << EVSYS_NSCHKUSER_USER0_Pos)              /**< (EVSYS_NSCHKUSER) User 0 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER_USER0(value)          (EVSYS_NSCHKUSER_USER0_Msk & ((value) << EVSYS_NSCHKUSER_USER0_Pos))
#define EVSYS_NSCHKUSER_USER1_Pos             _U_(1)                                               /**< (EVSYS_NSCHKUSER) User 1 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER_USER1_Msk             (_U_(0x1) << EVSYS_NSCHKUSER_USER1_Pos)              /**< (EVSYS_NSCHKUSER) User 1 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER_USER1(value)          (EVSYS_NSCHKUSER_USER1_Msk & ((value) << EVSYS_NSCHKUSER_USER1_Pos))
#define EVSYS_NSCHKUSER_USER2_Pos             _U_(2)                                               /**< (EVSYS_NSCHKUSER) User 2 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER_USER2_Msk             (_U_(0x1) << EVSYS_NSCHKUSER_USER2_Pos)              /**< (EVSYS_NSCHKUSER) User 2 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER_USER2(value)          (EVSYS_NSCHKUSER_USER2_Msk & ((value) << EVSYS_NSCHKUSER_USER2_Pos))
#define EVSYS_NSCHKUSER_USER3_Pos             _U_(3)                                               /**< (EVSYS_NSCHKUSER) User 3 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER_USER3_Msk             (_U_(0x1) << EVSYS_NSCHKUSER_USER3_Pos)              /**< (EVSYS_NSCHKUSER) User 3 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER_USER3(value)          (EVSYS_NSCHKUSER_USER3_Msk & ((value) << EVSYS_NSCHKUSER_USER3_Pos))
#define EVSYS_NSCHKUSER_USER4_Pos             _U_(4)                                               /**< (EVSYS_NSCHKUSER) User 4 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER_USER4_Msk             (_U_(0x1) << EVSYS_NSCHKUSER_USER4_Pos)              /**< (EVSYS_NSCHKUSER) User 4 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER_USER4(value)          (EVSYS_NSCHKUSER_USER4_Msk & ((value) << EVSYS_NSCHKUSER_USER4_Pos))
#define EVSYS_NSCHKUSER_USER5_Pos             _U_(5)                                               /**< (EVSYS_NSCHKUSER) User 5 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER_USER5_Msk             (_U_(0x1) << EVSYS_NSCHKUSER_USER5_Pos)              /**< (EVSYS_NSCHKUSER) User 5 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER_USER5(value)          (EVSYS_NSCHKUSER_USER5_Msk & ((value) << EVSYS_NSCHKUSER_USER5_Pos))
#define EVSYS_NSCHKUSER_USER6_Pos             _U_(6)                                               /**< (EVSYS_NSCHKUSER) User 6 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER_USER6_Msk             (_U_(0x1) << EVSYS_NSCHKUSER_USER6_Pos)              /**< (EVSYS_NSCHKUSER) User 6 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER_USER6(value)          (EVSYS_NSCHKUSER_USER6_Msk & ((value) << EVSYS_NSCHKUSER_USER6_Pos))
#define EVSYS_NSCHKUSER_USER7_Pos             _U_(7)                                               /**< (EVSYS_NSCHKUSER) User 7 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER_USER7_Msk             (_U_(0x1) << EVSYS_NSCHKUSER_USER7_Pos)              /**< (EVSYS_NSCHKUSER) User 7 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER_USER7(value)          (EVSYS_NSCHKUSER_USER7_Msk & ((value) << EVSYS_NSCHKUSER_USER7_Pos))
#define EVSYS_NSCHKUSER_USER8_Pos             _U_(8)                                               /**< (EVSYS_NSCHKUSER) User 8 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER_USER8_Msk             (_U_(0x1) << EVSYS_NSCHKUSER_USER8_Pos)              /**< (EVSYS_NSCHKUSER) User 8 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER_USER8(value)          (EVSYS_NSCHKUSER_USER8_Msk & ((value) << EVSYS_NSCHKUSER_USER8_Pos))
#define EVSYS_NSCHKUSER_USER9_Pos             _U_(9)                                               /**< (EVSYS_NSCHKUSER) User 9 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER_USER9_Msk             (_U_(0x1) << EVSYS_NSCHKUSER_USER9_Pos)              /**< (EVSYS_NSCHKUSER) User 9 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER_USER9(value)          (EVSYS_NSCHKUSER_USER9_Msk & ((value) << EVSYS_NSCHKUSER_USER9_Pos))
#define EVSYS_NSCHKUSER_USER10_Pos            _U_(10)                                              /**< (EVSYS_NSCHKUSER) User 10 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER_USER10_Msk            (_U_(0x1) << EVSYS_NSCHKUSER_USER10_Pos)             /**< (EVSYS_NSCHKUSER) User 10 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER_USER10(value)         (EVSYS_NSCHKUSER_USER10_Msk & ((value) << EVSYS_NSCHKUSER_USER10_Pos))
#define EVSYS_NSCHKUSER_USER11_Pos            _U_(11)                                              /**< (EVSYS_NSCHKUSER) User 11 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER_USER11_Msk            (_U_(0x1) << EVSYS_NSCHKUSER_USER11_Pos)             /**< (EVSYS_NSCHKUSER) User 11 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER_USER11(value)         (EVSYS_NSCHKUSER_USER11_Msk & ((value) << EVSYS_NSCHKUSER_USER11_Pos))
#define EVSYS_NSCHKUSER_USER12_Pos            _U_(12)                                              /**< (EVSYS_NSCHKUSER) User 12 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER_USER12_Msk            (_U_(0x1) << EVSYS_NSCHKUSER_USER12_Pos)             /**< (EVSYS_NSCHKUSER) User 12 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER_USER12(value)         (EVSYS_NSCHKUSER_USER12_Msk & ((value) << EVSYS_NSCHKUSER_USER12_Pos))
#define EVSYS_NSCHKUSER_USER13_Pos            _U_(13)                                              /**< (EVSYS_NSCHKUSER) User 13 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER_USER13_Msk            (_U_(0x1) << EVSYS_NSCHKUSER_USER13_Pos)             /**< (EVSYS_NSCHKUSER) User 13 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER_USER13(value)         (EVSYS_NSCHKUSER_USER13_Msk & ((value) << EVSYS_NSCHKUSER_USER13_Pos))
#define EVSYS_NSCHKUSER_USER14_Pos            _U_(14)                                              /**< (EVSYS_NSCHKUSER) User 14 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER_USER14_Msk            (_U_(0x1) << EVSYS_NSCHKUSER_USER14_Pos)             /**< (EVSYS_NSCHKUSER) User 14 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER_USER14(value)         (EVSYS_NSCHKUSER_USER14_Msk & ((value) << EVSYS_NSCHKUSER_USER14_Pos))
#define EVSYS_NSCHKUSER_USER15_Pos            _U_(15)                                              /**< (EVSYS_NSCHKUSER) User 15 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER_USER15_Msk            (_U_(0x1) << EVSYS_NSCHKUSER_USER15_Pos)             /**< (EVSYS_NSCHKUSER) User 15 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER_USER15(value)         (EVSYS_NSCHKUSER_USER15_Msk & ((value) << EVSYS_NSCHKUSER_USER15_Pos))
#define EVSYS_NSCHKUSER_USER16_Pos            _U_(16)                                              /**< (EVSYS_NSCHKUSER) User 16 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER_USER16_Msk            (_U_(0x1) << EVSYS_NSCHKUSER_USER16_Pos)             /**< (EVSYS_NSCHKUSER) User 16 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER_USER16(value)         (EVSYS_NSCHKUSER_USER16_Msk & ((value) << EVSYS_NSCHKUSER_USER16_Pos))
#define EVSYS_NSCHKUSER_USER17_Pos            _U_(17)                                              /**< (EVSYS_NSCHKUSER) User 17 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER_USER17_Msk            (_U_(0x1) << EVSYS_NSCHKUSER_USER17_Pos)             /**< (EVSYS_NSCHKUSER) User 17 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER_USER17(value)         (EVSYS_NSCHKUSER_USER17_Msk & ((value) << EVSYS_NSCHKUSER_USER17_Pos))
#define EVSYS_NSCHKUSER_USER18_Pos            _U_(18)                                              /**< (EVSYS_NSCHKUSER) User 18 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER_USER18_Msk            (_U_(0x1) << EVSYS_NSCHKUSER_USER18_Pos)             /**< (EVSYS_NSCHKUSER) User 18 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER_USER18(value)         (EVSYS_NSCHKUSER_USER18_Msk & ((value) << EVSYS_NSCHKUSER_USER18_Pos))
#define EVSYS_NSCHKUSER_USER19_Pos            _U_(19)                                              /**< (EVSYS_NSCHKUSER) User 19 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER_USER19_Msk            (_U_(0x1) << EVSYS_NSCHKUSER_USER19_Pos)             /**< (EVSYS_NSCHKUSER) User 19 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER_USER19(value)         (EVSYS_NSCHKUSER_USER19_Msk & ((value) << EVSYS_NSCHKUSER_USER19_Pos))
#define EVSYS_NSCHKUSER_USER20_Pos            _U_(20)                                              /**< (EVSYS_NSCHKUSER) User 20 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER_USER20_Msk            (_U_(0x1) << EVSYS_NSCHKUSER_USER20_Pos)             /**< (EVSYS_NSCHKUSER) User 20 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER_USER20(value)         (EVSYS_NSCHKUSER_USER20_Msk & ((value) << EVSYS_NSCHKUSER_USER20_Pos))
#define EVSYS_NSCHKUSER_USER21_Pos            _U_(21)                                              /**< (EVSYS_NSCHKUSER) User 21 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER_USER21_Msk            (_U_(0x1) << EVSYS_NSCHKUSER_USER21_Pos)             /**< (EVSYS_NSCHKUSER) User 21 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER_USER21(value)         (EVSYS_NSCHKUSER_USER21_Msk & ((value) << EVSYS_NSCHKUSER_USER21_Pos))
#define EVSYS_NSCHKUSER_USER22_Pos            _U_(22)                                              /**< (EVSYS_NSCHKUSER) User 22 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER_USER22_Msk            (_U_(0x1) << EVSYS_NSCHKUSER_USER22_Pos)             /**< (EVSYS_NSCHKUSER) User 22 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER_USER22(value)         (EVSYS_NSCHKUSER_USER22_Msk & ((value) << EVSYS_NSCHKUSER_USER22_Pos))
#define EVSYS_NSCHKUSER_Msk                   _U_(0x007FFFFF)                                      /**< (EVSYS_NSCHKUSER) Register Mask  */

#define EVSYS_NSCHKUSER_USER_Pos              _U_(0)                                               /**< (EVSYS_NSCHKUSER Position) User 22 to be checked as non-secured */
#define EVSYS_NSCHKUSER_USER_Msk              (_U_(0x7FFFFF) << EVSYS_NSCHKUSER_USER_Pos)          /**< (EVSYS_NSCHKUSER Mask) USER */
#define EVSYS_NSCHKUSER_USER(value)           (EVSYS_NSCHKUSER_USER_Msk & ((value) << EVSYS_NSCHKUSER_USER_Pos)) 

/** \brief EVSYS register offsets definitions */
#define EVSYS_CHANNEL_REG_OFST         (0x00)              /**< (EVSYS_CHANNEL) Channel n Control Offset */
#define EVSYS_CHINTENCLR_REG_OFST      (0x04)              /**< (EVSYS_CHINTENCLR) Channel n Interrupt Enable Clear Offset */
#define EVSYS_CHINTENSET_REG_OFST      (0x05)              /**< (EVSYS_CHINTENSET) Channel n Interrupt Enable Set Offset */
#define EVSYS_CHINTFLAG_REG_OFST       (0x06)              /**< (EVSYS_CHINTFLAG) Channel n Interrupt Flag Status and Clear Offset */
#define EVSYS_CHSTATUS_REG_OFST        (0x07)              /**< (EVSYS_CHSTATUS) Channel n Status Offset */
#define EVSYS_CTRLA_REG_OFST           (0x00)              /**< (EVSYS_CTRLA) Control Offset */
#define EVSYS_SWEVT_REG_OFST           (0x04)              /**< (EVSYS_SWEVT) Software Event Offset */
#define EVSYS_PRICTRL_REG_OFST         (0x08)              /**< (EVSYS_PRICTRL) Priority Control Offset */
#define EVSYS_INTPEND_REG_OFST         (0x10)              /**< (EVSYS_INTPEND) Channel Pending Interrupt Offset */
#define EVSYS_INTSTATUS_REG_OFST       (0x14)              /**< (EVSYS_INTSTATUS) Interrupt Status Offset */
#define EVSYS_BUSYCH_REG_OFST          (0x18)              /**< (EVSYS_BUSYCH) Busy Channels Offset */
#define EVSYS_READYUSR_REG_OFST        (0x1C)              /**< (EVSYS_READYUSR) Ready Users Offset */
#define EVSYS_USER_REG_OFST            (0x120)             /**< (EVSYS_USER) User Multiplexer n Offset */
#define EVSYS_INTENCLR_REG_OFST        (0x1D4)             /**< (EVSYS_INTENCLR) Interrupt Enable Clear Offset */
#define EVSYS_INTENSET_REG_OFST        (0x1D5)             /**< (EVSYS_INTENSET) Interrupt Enable Set Offset */
#define EVSYS_INTFLAG_REG_OFST         (0x1D6)             /**< (EVSYS_INTFLAG) Interrupt Flag Status and Clear Offset */
#define EVSYS_NONSECCHAN_REG_OFST      (0x1D8)             /**< (EVSYS_NONSECCHAN) Channels Security Attribution Offset */
#define EVSYS_NSCHKCHAN_REG_OFST       (0x1DC)             /**< (EVSYS_NSCHKCHAN) Non-Secure Channels Check Offset */
#define EVSYS_NONSECUSER_REG_OFST      (0x1E0)             /**< (EVSYS_NONSECUSER) Users Security Attribution Offset */
#define EVSYS_NSCHKUSER_REG_OFST       (0x1F0)             /**< (EVSYS_NSCHKUSER) Non-Secure Users Check Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief CHANNEL register API structure */
typedef struct
{
  __IO  uint32_t                       EVSYS_CHANNEL;      /**< Offset: 0x00 (R/W  32) Channel n Control */
  __IO  uint8_t                        EVSYS_CHINTENCLR;   /**< Offset: 0x04 (R/W  8) Channel n Interrupt Enable Clear */
  __IO  uint8_t                        EVSYS_CHINTENSET;   /**< Offset: 0x05 (R/W  8) Channel n Interrupt Enable Set */
  __IO  uint8_t                        EVSYS_CHINTFLAG;    /**< Offset: 0x06 (R/W  8) Channel n Interrupt Flag Status and Clear */
  __I   uint8_t                        EVSYS_CHSTATUS;     /**< Offset: 0x07 (R/   8) Channel n Status */
} evsys_channel_registers_t;

#define EVSYS_CHANNEL_NUMBER _U_(8)

/** \brief EVSYS register API structure */
typedef struct
{  /* Event System Interface */
  __O   uint8_t                        EVSYS_CTRLA;        /**< Offset: 0x00 ( /W  8) Control */
  __I   uint8_t                        Reserved1[0x03];
  __O   uint32_t                       EVSYS_SWEVT;        /**< Offset: 0x04 ( /W  32) Software Event */
  __IO  uint8_t                        EVSYS_PRICTRL;      /**< Offset: 0x08 (R/W  8) Priority Control */
  __I   uint8_t                        Reserved2[0x07];
  __IO  uint16_t                       EVSYS_INTPEND;      /**< Offset: 0x10 (R/W  16) Channel Pending Interrupt */
  __I   uint8_t                        Reserved3[0x02];
  __I   uint32_t                       EVSYS_INTSTATUS;    /**< Offset: 0x14 (R/   32) Interrupt Status */
  __I   uint32_t                       EVSYS_BUSYCH;       /**< Offset: 0x18 (R/   32) Busy Channels */
  __I   uint32_t                       EVSYS_READYUSR;     /**< Offset: 0x1C (R/   32) Ready Users */
        evsys_channel_registers_t      CHANNEL[EVSYS_CHANNEL_NUMBER]; /**< Offset: 0x20  */
  __I   uint8_t                        Reserved4[0xC0];
  __IO  uint8_t                        EVSYS_USER[23];     /**< Offset: 0x120 (R/W  8) User Multiplexer n */
  __I   uint8_t                        Reserved5[0x9D];
  __IO  uint8_t                        EVSYS_INTENCLR;     /**< Offset: 0x1D4 (R/W  8) Interrupt Enable Clear */
  __IO  uint8_t                        EVSYS_INTENSET;     /**< Offset: 0x1D5 (R/W  8) Interrupt Enable Set */
  __IO  uint8_t                        EVSYS_INTFLAG;      /**< Offset: 0x1D6 (R/W  8) Interrupt Flag Status and Clear */
  __I   uint8_t                        Reserved6[0x01];
  __IO  uint32_t                       EVSYS_NONSECCHAN;   /**< Offset: 0x1D8 (R/W  32) Channels Security Attribution */
  __IO  uint32_t                       EVSYS_NSCHKCHAN;    /**< Offset: 0x1DC (R/W  32) Non-Secure Channels Check */
  __IO  uint32_t                       EVSYS_NONSECUSER[1]; /**< Offset: 0x1E0 (R/W  32) Users Security Attribution */
  __I   uint8_t                        Reserved7[0x0C];
  __IO  uint32_t                       EVSYS_NSCHKUSER[1]; /**< Offset: 0x1F0 (R/W  32) Non-Secure Users Check */
} evsys_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAML11_EVSYS_COMPONENT_H_ */
