/**
 * \brief Component description for EVSYS
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

/* file generated from device description version 2020-11-19T06:59:39Z */
#ifndef _SAML22_EVSYS_COMPONENT_H_
#define _SAML22_EVSYS_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR EVSYS                                        */
/* ************************************************************************** */

/* -------- EVSYS_CTRLA : (EVSYS Offset: 0x00) (R/W 8) Control -------- */
#define EVSYS_CTRLA_RESETVALUE                _U_(0x00)                                            /**<  (EVSYS_CTRLA) Control  Reset Value */

#define EVSYS_CTRLA_SWRST_Pos                 _U_(0)                                               /**< (EVSYS_CTRLA) Software Reset Position */
#define EVSYS_CTRLA_SWRST_Msk                 (_U_(0x1) << EVSYS_CTRLA_SWRST_Pos)                  /**< (EVSYS_CTRLA) Software Reset Mask */
#define EVSYS_CTRLA_SWRST(value)              (EVSYS_CTRLA_SWRST_Msk & ((value) << EVSYS_CTRLA_SWRST_Pos))
#define EVSYS_CTRLA_Msk                       _U_(0x01)                                            /**< (EVSYS_CTRLA) Register Mask  */


/* -------- EVSYS_CHSTATUS : (EVSYS Offset: 0x0C) ( R/ 32) Channel Status -------- */
#define EVSYS_CHSTATUS_RESETVALUE             _U_(0x00)                                            /**<  (EVSYS_CHSTATUS) Channel Status  Reset Value */

#define EVSYS_CHSTATUS_USRRDY0_Pos            _U_(0)                                               /**< (EVSYS_CHSTATUS) Channel 0 User Ready Position */
#define EVSYS_CHSTATUS_USRRDY0_Msk            (_U_(0x1) << EVSYS_CHSTATUS_USRRDY0_Pos)             /**< (EVSYS_CHSTATUS) Channel 0 User Ready Mask */
#define EVSYS_CHSTATUS_USRRDY0(value)         (EVSYS_CHSTATUS_USRRDY0_Msk & ((value) << EVSYS_CHSTATUS_USRRDY0_Pos))
#define EVSYS_CHSTATUS_USRRDY1_Pos            _U_(1)                                               /**< (EVSYS_CHSTATUS) Channel 1 User Ready Position */
#define EVSYS_CHSTATUS_USRRDY1_Msk            (_U_(0x1) << EVSYS_CHSTATUS_USRRDY1_Pos)             /**< (EVSYS_CHSTATUS) Channel 1 User Ready Mask */
#define EVSYS_CHSTATUS_USRRDY1(value)         (EVSYS_CHSTATUS_USRRDY1_Msk & ((value) << EVSYS_CHSTATUS_USRRDY1_Pos))
#define EVSYS_CHSTATUS_USRRDY2_Pos            _U_(2)                                               /**< (EVSYS_CHSTATUS) Channel 2 User Ready Position */
#define EVSYS_CHSTATUS_USRRDY2_Msk            (_U_(0x1) << EVSYS_CHSTATUS_USRRDY2_Pos)             /**< (EVSYS_CHSTATUS) Channel 2 User Ready Mask */
#define EVSYS_CHSTATUS_USRRDY2(value)         (EVSYS_CHSTATUS_USRRDY2_Msk & ((value) << EVSYS_CHSTATUS_USRRDY2_Pos))
#define EVSYS_CHSTATUS_USRRDY3_Pos            _U_(3)                                               /**< (EVSYS_CHSTATUS) Channel 3 User Ready Position */
#define EVSYS_CHSTATUS_USRRDY3_Msk            (_U_(0x1) << EVSYS_CHSTATUS_USRRDY3_Pos)             /**< (EVSYS_CHSTATUS) Channel 3 User Ready Mask */
#define EVSYS_CHSTATUS_USRRDY3(value)         (EVSYS_CHSTATUS_USRRDY3_Msk & ((value) << EVSYS_CHSTATUS_USRRDY3_Pos))
#define EVSYS_CHSTATUS_USRRDY4_Pos            _U_(4)                                               /**< (EVSYS_CHSTATUS) Channel 4 User Ready Position */
#define EVSYS_CHSTATUS_USRRDY4_Msk            (_U_(0x1) << EVSYS_CHSTATUS_USRRDY4_Pos)             /**< (EVSYS_CHSTATUS) Channel 4 User Ready Mask */
#define EVSYS_CHSTATUS_USRRDY4(value)         (EVSYS_CHSTATUS_USRRDY4_Msk & ((value) << EVSYS_CHSTATUS_USRRDY4_Pos))
#define EVSYS_CHSTATUS_USRRDY5_Pos            _U_(5)                                               /**< (EVSYS_CHSTATUS) Channel 5 User Ready Position */
#define EVSYS_CHSTATUS_USRRDY5_Msk            (_U_(0x1) << EVSYS_CHSTATUS_USRRDY5_Pos)             /**< (EVSYS_CHSTATUS) Channel 5 User Ready Mask */
#define EVSYS_CHSTATUS_USRRDY5(value)         (EVSYS_CHSTATUS_USRRDY5_Msk & ((value) << EVSYS_CHSTATUS_USRRDY5_Pos))
#define EVSYS_CHSTATUS_USRRDY6_Pos            _U_(6)                                               /**< (EVSYS_CHSTATUS) Channel 6 User Ready Position */
#define EVSYS_CHSTATUS_USRRDY6_Msk            (_U_(0x1) << EVSYS_CHSTATUS_USRRDY6_Pos)             /**< (EVSYS_CHSTATUS) Channel 6 User Ready Mask */
#define EVSYS_CHSTATUS_USRRDY6(value)         (EVSYS_CHSTATUS_USRRDY6_Msk & ((value) << EVSYS_CHSTATUS_USRRDY6_Pos))
#define EVSYS_CHSTATUS_USRRDY7_Pos            _U_(7)                                               /**< (EVSYS_CHSTATUS) Channel 7 User Ready Position */
#define EVSYS_CHSTATUS_USRRDY7_Msk            (_U_(0x1) << EVSYS_CHSTATUS_USRRDY7_Pos)             /**< (EVSYS_CHSTATUS) Channel 7 User Ready Mask */
#define EVSYS_CHSTATUS_USRRDY7(value)         (EVSYS_CHSTATUS_USRRDY7_Msk & ((value) << EVSYS_CHSTATUS_USRRDY7_Pos))
#define EVSYS_CHSTATUS_CHBUSY0_Pos            _U_(16)                                              /**< (EVSYS_CHSTATUS) Channel 0 Busy Position */
#define EVSYS_CHSTATUS_CHBUSY0_Msk            (_U_(0x1) << EVSYS_CHSTATUS_CHBUSY0_Pos)             /**< (EVSYS_CHSTATUS) Channel 0 Busy Mask */
#define EVSYS_CHSTATUS_CHBUSY0(value)         (EVSYS_CHSTATUS_CHBUSY0_Msk & ((value) << EVSYS_CHSTATUS_CHBUSY0_Pos))
#define EVSYS_CHSTATUS_CHBUSY1_Pos            _U_(17)                                              /**< (EVSYS_CHSTATUS) Channel 1 Busy Position */
#define EVSYS_CHSTATUS_CHBUSY1_Msk            (_U_(0x1) << EVSYS_CHSTATUS_CHBUSY1_Pos)             /**< (EVSYS_CHSTATUS) Channel 1 Busy Mask */
#define EVSYS_CHSTATUS_CHBUSY1(value)         (EVSYS_CHSTATUS_CHBUSY1_Msk & ((value) << EVSYS_CHSTATUS_CHBUSY1_Pos))
#define EVSYS_CHSTATUS_CHBUSY2_Pos            _U_(18)                                              /**< (EVSYS_CHSTATUS) Channel 2 Busy Position */
#define EVSYS_CHSTATUS_CHBUSY2_Msk            (_U_(0x1) << EVSYS_CHSTATUS_CHBUSY2_Pos)             /**< (EVSYS_CHSTATUS) Channel 2 Busy Mask */
#define EVSYS_CHSTATUS_CHBUSY2(value)         (EVSYS_CHSTATUS_CHBUSY2_Msk & ((value) << EVSYS_CHSTATUS_CHBUSY2_Pos))
#define EVSYS_CHSTATUS_CHBUSY3_Pos            _U_(19)                                              /**< (EVSYS_CHSTATUS) Channel 3 Busy Position */
#define EVSYS_CHSTATUS_CHBUSY3_Msk            (_U_(0x1) << EVSYS_CHSTATUS_CHBUSY3_Pos)             /**< (EVSYS_CHSTATUS) Channel 3 Busy Mask */
#define EVSYS_CHSTATUS_CHBUSY3(value)         (EVSYS_CHSTATUS_CHBUSY3_Msk & ((value) << EVSYS_CHSTATUS_CHBUSY3_Pos))
#define EVSYS_CHSTATUS_CHBUSY4_Pos            _U_(20)                                              /**< (EVSYS_CHSTATUS) Channel 4 Busy Position */
#define EVSYS_CHSTATUS_CHBUSY4_Msk            (_U_(0x1) << EVSYS_CHSTATUS_CHBUSY4_Pos)             /**< (EVSYS_CHSTATUS) Channel 4 Busy Mask */
#define EVSYS_CHSTATUS_CHBUSY4(value)         (EVSYS_CHSTATUS_CHBUSY4_Msk & ((value) << EVSYS_CHSTATUS_CHBUSY4_Pos))
#define EVSYS_CHSTATUS_CHBUSY5_Pos            _U_(21)                                              /**< (EVSYS_CHSTATUS) Channel 5 Busy Position */
#define EVSYS_CHSTATUS_CHBUSY5_Msk            (_U_(0x1) << EVSYS_CHSTATUS_CHBUSY5_Pos)             /**< (EVSYS_CHSTATUS) Channel 5 Busy Mask */
#define EVSYS_CHSTATUS_CHBUSY5(value)         (EVSYS_CHSTATUS_CHBUSY5_Msk & ((value) << EVSYS_CHSTATUS_CHBUSY5_Pos))
#define EVSYS_CHSTATUS_CHBUSY6_Pos            _U_(22)                                              /**< (EVSYS_CHSTATUS) Channel 6 Busy Position */
#define EVSYS_CHSTATUS_CHBUSY6_Msk            (_U_(0x1) << EVSYS_CHSTATUS_CHBUSY6_Pos)             /**< (EVSYS_CHSTATUS) Channel 6 Busy Mask */
#define EVSYS_CHSTATUS_CHBUSY6(value)         (EVSYS_CHSTATUS_CHBUSY6_Msk & ((value) << EVSYS_CHSTATUS_CHBUSY6_Pos))
#define EVSYS_CHSTATUS_CHBUSY7_Pos            _U_(23)                                              /**< (EVSYS_CHSTATUS) Channel 7 Busy Position */
#define EVSYS_CHSTATUS_CHBUSY7_Msk            (_U_(0x1) << EVSYS_CHSTATUS_CHBUSY7_Pos)             /**< (EVSYS_CHSTATUS) Channel 7 Busy Mask */
#define EVSYS_CHSTATUS_CHBUSY7(value)         (EVSYS_CHSTATUS_CHBUSY7_Msk & ((value) << EVSYS_CHSTATUS_CHBUSY7_Pos))
#define EVSYS_CHSTATUS_Msk                    _U_(0x00FF00FF)                                      /**< (EVSYS_CHSTATUS) Register Mask  */

#define EVSYS_CHSTATUS_USRRDY_Pos             _U_(0)                                               /**< (EVSYS_CHSTATUS Position) Channel x User Ready */
#define EVSYS_CHSTATUS_USRRDY_Msk             (_U_(0xFF) << EVSYS_CHSTATUS_USRRDY_Pos)             /**< (EVSYS_CHSTATUS Mask) USRRDY */
#define EVSYS_CHSTATUS_USRRDY(value)          (EVSYS_CHSTATUS_USRRDY_Msk & ((value) << EVSYS_CHSTATUS_USRRDY_Pos)) 
#define EVSYS_CHSTATUS_CHBUSY_Pos             _U_(16)                                              /**< (EVSYS_CHSTATUS Position) Channel 7 Busy */
#define EVSYS_CHSTATUS_CHBUSY_Msk             (_U_(0xFF) << EVSYS_CHSTATUS_CHBUSY_Pos)             /**< (EVSYS_CHSTATUS Mask) CHBUSY */
#define EVSYS_CHSTATUS_CHBUSY(value)          (EVSYS_CHSTATUS_CHBUSY_Msk & ((value) << EVSYS_CHSTATUS_CHBUSY_Pos)) 

/* -------- EVSYS_INTENCLR : (EVSYS Offset: 0x10) (R/W 32) Interrupt Enable Clear -------- */
#define EVSYS_INTENCLR_RESETVALUE             _U_(0x00)                                            /**<  (EVSYS_INTENCLR) Interrupt Enable Clear  Reset Value */

#define EVSYS_INTENCLR_OVR0_Pos               _U_(0)                                               /**< (EVSYS_INTENCLR) Channel 0 Overrun Interrupt Enable Position */
#define EVSYS_INTENCLR_OVR0_Msk               (_U_(0x1) << EVSYS_INTENCLR_OVR0_Pos)                /**< (EVSYS_INTENCLR) Channel 0 Overrun Interrupt Enable Mask */
#define EVSYS_INTENCLR_OVR0(value)            (EVSYS_INTENCLR_OVR0_Msk & ((value) << EVSYS_INTENCLR_OVR0_Pos))
#define EVSYS_INTENCLR_OVR1_Pos               _U_(1)                                               /**< (EVSYS_INTENCLR) Channel 1 Overrun Interrupt Enable Position */
#define EVSYS_INTENCLR_OVR1_Msk               (_U_(0x1) << EVSYS_INTENCLR_OVR1_Pos)                /**< (EVSYS_INTENCLR) Channel 1 Overrun Interrupt Enable Mask */
#define EVSYS_INTENCLR_OVR1(value)            (EVSYS_INTENCLR_OVR1_Msk & ((value) << EVSYS_INTENCLR_OVR1_Pos))
#define EVSYS_INTENCLR_OVR2_Pos               _U_(2)                                               /**< (EVSYS_INTENCLR) Channel 2 Overrun Interrupt Enable Position */
#define EVSYS_INTENCLR_OVR2_Msk               (_U_(0x1) << EVSYS_INTENCLR_OVR2_Pos)                /**< (EVSYS_INTENCLR) Channel 2 Overrun Interrupt Enable Mask */
#define EVSYS_INTENCLR_OVR2(value)            (EVSYS_INTENCLR_OVR2_Msk & ((value) << EVSYS_INTENCLR_OVR2_Pos))
#define EVSYS_INTENCLR_OVR3_Pos               _U_(3)                                               /**< (EVSYS_INTENCLR) Channel 3 Overrun Interrupt Enable Position */
#define EVSYS_INTENCLR_OVR3_Msk               (_U_(0x1) << EVSYS_INTENCLR_OVR3_Pos)                /**< (EVSYS_INTENCLR) Channel 3 Overrun Interrupt Enable Mask */
#define EVSYS_INTENCLR_OVR3(value)            (EVSYS_INTENCLR_OVR3_Msk & ((value) << EVSYS_INTENCLR_OVR3_Pos))
#define EVSYS_INTENCLR_OVR4_Pos               _U_(4)                                               /**< (EVSYS_INTENCLR) Channel 4 Overrun Interrupt Enable Position */
#define EVSYS_INTENCLR_OVR4_Msk               (_U_(0x1) << EVSYS_INTENCLR_OVR4_Pos)                /**< (EVSYS_INTENCLR) Channel 4 Overrun Interrupt Enable Mask */
#define EVSYS_INTENCLR_OVR4(value)            (EVSYS_INTENCLR_OVR4_Msk & ((value) << EVSYS_INTENCLR_OVR4_Pos))
#define EVSYS_INTENCLR_OVR5_Pos               _U_(5)                                               /**< (EVSYS_INTENCLR) Channel 5 Overrun Interrupt Enable Position */
#define EVSYS_INTENCLR_OVR5_Msk               (_U_(0x1) << EVSYS_INTENCLR_OVR5_Pos)                /**< (EVSYS_INTENCLR) Channel 5 Overrun Interrupt Enable Mask */
#define EVSYS_INTENCLR_OVR5(value)            (EVSYS_INTENCLR_OVR5_Msk & ((value) << EVSYS_INTENCLR_OVR5_Pos))
#define EVSYS_INTENCLR_OVR6_Pos               _U_(6)                                               /**< (EVSYS_INTENCLR) Channel 6 Overrun Interrupt Enable Position */
#define EVSYS_INTENCLR_OVR6_Msk               (_U_(0x1) << EVSYS_INTENCLR_OVR6_Pos)                /**< (EVSYS_INTENCLR) Channel 6 Overrun Interrupt Enable Mask */
#define EVSYS_INTENCLR_OVR6(value)            (EVSYS_INTENCLR_OVR6_Msk & ((value) << EVSYS_INTENCLR_OVR6_Pos))
#define EVSYS_INTENCLR_OVR7_Pos               _U_(7)                                               /**< (EVSYS_INTENCLR) Channel 7 Overrun Interrupt Enable Position */
#define EVSYS_INTENCLR_OVR7_Msk               (_U_(0x1) << EVSYS_INTENCLR_OVR7_Pos)                /**< (EVSYS_INTENCLR) Channel 7 Overrun Interrupt Enable Mask */
#define EVSYS_INTENCLR_OVR7(value)            (EVSYS_INTENCLR_OVR7_Msk & ((value) << EVSYS_INTENCLR_OVR7_Pos))
#define EVSYS_INTENCLR_EVD0_Pos               _U_(16)                                              /**< (EVSYS_INTENCLR) Channel 0 Event Detection Interrupt Enable Position */
#define EVSYS_INTENCLR_EVD0_Msk               (_U_(0x1) << EVSYS_INTENCLR_EVD0_Pos)                /**< (EVSYS_INTENCLR) Channel 0 Event Detection Interrupt Enable Mask */
#define EVSYS_INTENCLR_EVD0(value)            (EVSYS_INTENCLR_EVD0_Msk & ((value) << EVSYS_INTENCLR_EVD0_Pos))
#define EVSYS_INTENCLR_EVD1_Pos               _U_(17)                                              /**< (EVSYS_INTENCLR) Channel 1 Event Detection Interrupt Enable Position */
#define EVSYS_INTENCLR_EVD1_Msk               (_U_(0x1) << EVSYS_INTENCLR_EVD1_Pos)                /**< (EVSYS_INTENCLR) Channel 1 Event Detection Interrupt Enable Mask */
#define EVSYS_INTENCLR_EVD1(value)            (EVSYS_INTENCLR_EVD1_Msk & ((value) << EVSYS_INTENCLR_EVD1_Pos))
#define EVSYS_INTENCLR_EVD2_Pos               _U_(18)                                              /**< (EVSYS_INTENCLR) Channel 2 Event Detection Interrupt Enable Position */
#define EVSYS_INTENCLR_EVD2_Msk               (_U_(0x1) << EVSYS_INTENCLR_EVD2_Pos)                /**< (EVSYS_INTENCLR) Channel 2 Event Detection Interrupt Enable Mask */
#define EVSYS_INTENCLR_EVD2(value)            (EVSYS_INTENCLR_EVD2_Msk & ((value) << EVSYS_INTENCLR_EVD2_Pos))
#define EVSYS_INTENCLR_EVD3_Pos               _U_(19)                                              /**< (EVSYS_INTENCLR) Channel 3 Event Detection Interrupt Enable Position */
#define EVSYS_INTENCLR_EVD3_Msk               (_U_(0x1) << EVSYS_INTENCLR_EVD3_Pos)                /**< (EVSYS_INTENCLR) Channel 3 Event Detection Interrupt Enable Mask */
#define EVSYS_INTENCLR_EVD3(value)            (EVSYS_INTENCLR_EVD3_Msk & ((value) << EVSYS_INTENCLR_EVD3_Pos))
#define EVSYS_INTENCLR_EVD4_Pos               _U_(20)                                              /**< (EVSYS_INTENCLR) Channel 4 Event Detection Interrupt Enable Position */
#define EVSYS_INTENCLR_EVD4_Msk               (_U_(0x1) << EVSYS_INTENCLR_EVD4_Pos)                /**< (EVSYS_INTENCLR) Channel 4 Event Detection Interrupt Enable Mask */
#define EVSYS_INTENCLR_EVD4(value)            (EVSYS_INTENCLR_EVD4_Msk & ((value) << EVSYS_INTENCLR_EVD4_Pos))
#define EVSYS_INTENCLR_EVD5_Pos               _U_(21)                                              /**< (EVSYS_INTENCLR) Channel 5 Event Detection Interrupt Enable Position */
#define EVSYS_INTENCLR_EVD5_Msk               (_U_(0x1) << EVSYS_INTENCLR_EVD5_Pos)                /**< (EVSYS_INTENCLR) Channel 5 Event Detection Interrupt Enable Mask */
#define EVSYS_INTENCLR_EVD5(value)            (EVSYS_INTENCLR_EVD5_Msk & ((value) << EVSYS_INTENCLR_EVD5_Pos))
#define EVSYS_INTENCLR_EVD6_Pos               _U_(22)                                              /**< (EVSYS_INTENCLR) Channel 6 Event Detection Interrupt Enable Position */
#define EVSYS_INTENCLR_EVD6_Msk               (_U_(0x1) << EVSYS_INTENCLR_EVD6_Pos)                /**< (EVSYS_INTENCLR) Channel 6 Event Detection Interrupt Enable Mask */
#define EVSYS_INTENCLR_EVD6(value)            (EVSYS_INTENCLR_EVD6_Msk & ((value) << EVSYS_INTENCLR_EVD6_Pos))
#define EVSYS_INTENCLR_EVD7_Pos               _U_(23)                                              /**< (EVSYS_INTENCLR) Channel 7 Event Detection Interrupt Enable Position */
#define EVSYS_INTENCLR_EVD7_Msk               (_U_(0x1) << EVSYS_INTENCLR_EVD7_Pos)                /**< (EVSYS_INTENCLR) Channel 7 Event Detection Interrupt Enable Mask */
#define EVSYS_INTENCLR_EVD7(value)            (EVSYS_INTENCLR_EVD7_Msk & ((value) << EVSYS_INTENCLR_EVD7_Pos))
#define EVSYS_INTENCLR_Msk                    _U_(0x00FF00FF)                                      /**< (EVSYS_INTENCLR) Register Mask  */

#define EVSYS_INTENCLR_OVR_Pos                _U_(0)                                               /**< (EVSYS_INTENCLR Position) Channel x Overrun Interrupt Enable */
#define EVSYS_INTENCLR_OVR_Msk                (_U_(0xFF) << EVSYS_INTENCLR_OVR_Pos)                /**< (EVSYS_INTENCLR Mask) OVR */
#define EVSYS_INTENCLR_OVR(value)             (EVSYS_INTENCLR_OVR_Msk & ((value) << EVSYS_INTENCLR_OVR_Pos)) 
#define EVSYS_INTENCLR_EVD_Pos                _U_(16)                                              /**< (EVSYS_INTENCLR Position) Channel 7 Event Detection Interrupt Enable */
#define EVSYS_INTENCLR_EVD_Msk                (_U_(0xFF) << EVSYS_INTENCLR_EVD_Pos)                /**< (EVSYS_INTENCLR Mask) EVD */
#define EVSYS_INTENCLR_EVD(value)             (EVSYS_INTENCLR_EVD_Msk & ((value) << EVSYS_INTENCLR_EVD_Pos)) 

/* -------- EVSYS_INTENSET : (EVSYS Offset: 0x14) (R/W 32) Interrupt Enable Set -------- */
#define EVSYS_INTENSET_RESETVALUE             _U_(0x00)                                            /**<  (EVSYS_INTENSET) Interrupt Enable Set  Reset Value */

#define EVSYS_INTENSET_OVR0_Pos               _U_(0)                                               /**< (EVSYS_INTENSET) Channel 0 Overrun Interrupt Enable Position */
#define EVSYS_INTENSET_OVR0_Msk               (_U_(0x1) << EVSYS_INTENSET_OVR0_Pos)                /**< (EVSYS_INTENSET) Channel 0 Overrun Interrupt Enable Mask */
#define EVSYS_INTENSET_OVR0(value)            (EVSYS_INTENSET_OVR0_Msk & ((value) << EVSYS_INTENSET_OVR0_Pos))
#define EVSYS_INTENSET_OVR1_Pos               _U_(1)                                               /**< (EVSYS_INTENSET) Channel 1 Overrun Interrupt Enable Position */
#define EVSYS_INTENSET_OVR1_Msk               (_U_(0x1) << EVSYS_INTENSET_OVR1_Pos)                /**< (EVSYS_INTENSET) Channel 1 Overrun Interrupt Enable Mask */
#define EVSYS_INTENSET_OVR1(value)            (EVSYS_INTENSET_OVR1_Msk & ((value) << EVSYS_INTENSET_OVR1_Pos))
#define EVSYS_INTENSET_OVR2_Pos               _U_(2)                                               /**< (EVSYS_INTENSET) Channel 2 Overrun Interrupt Enable Position */
#define EVSYS_INTENSET_OVR2_Msk               (_U_(0x1) << EVSYS_INTENSET_OVR2_Pos)                /**< (EVSYS_INTENSET) Channel 2 Overrun Interrupt Enable Mask */
#define EVSYS_INTENSET_OVR2(value)            (EVSYS_INTENSET_OVR2_Msk & ((value) << EVSYS_INTENSET_OVR2_Pos))
#define EVSYS_INTENSET_OVR3_Pos               _U_(3)                                               /**< (EVSYS_INTENSET) Channel 3 Overrun Interrupt Enable Position */
#define EVSYS_INTENSET_OVR3_Msk               (_U_(0x1) << EVSYS_INTENSET_OVR3_Pos)                /**< (EVSYS_INTENSET) Channel 3 Overrun Interrupt Enable Mask */
#define EVSYS_INTENSET_OVR3(value)            (EVSYS_INTENSET_OVR3_Msk & ((value) << EVSYS_INTENSET_OVR3_Pos))
#define EVSYS_INTENSET_OVR4_Pos               _U_(4)                                               /**< (EVSYS_INTENSET) Channel 4 Overrun Interrupt Enable Position */
#define EVSYS_INTENSET_OVR4_Msk               (_U_(0x1) << EVSYS_INTENSET_OVR4_Pos)                /**< (EVSYS_INTENSET) Channel 4 Overrun Interrupt Enable Mask */
#define EVSYS_INTENSET_OVR4(value)            (EVSYS_INTENSET_OVR4_Msk & ((value) << EVSYS_INTENSET_OVR4_Pos))
#define EVSYS_INTENSET_OVR5_Pos               _U_(5)                                               /**< (EVSYS_INTENSET) Channel 5 Overrun Interrupt Enable Position */
#define EVSYS_INTENSET_OVR5_Msk               (_U_(0x1) << EVSYS_INTENSET_OVR5_Pos)                /**< (EVSYS_INTENSET) Channel 5 Overrun Interrupt Enable Mask */
#define EVSYS_INTENSET_OVR5(value)            (EVSYS_INTENSET_OVR5_Msk & ((value) << EVSYS_INTENSET_OVR5_Pos))
#define EVSYS_INTENSET_OVR6_Pos               _U_(6)                                               /**< (EVSYS_INTENSET) Channel 6 Overrun Interrupt Enable Position */
#define EVSYS_INTENSET_OVR6_Msk               (_U_(0x1) << EVSYS_INTENSET_OVR6_Pos)                /**< (EVSYS_INTENSET) Channel 6 Overrun Interrupt Enable Mask */
#define EVSYS_INTENSET_OVR6(value)            (EVSYS_INTENSET_OVR6_Msk & ((value) << EVSYS_INTENSET_OVR6_Pos))
#define EVSYS_INTENSET_OVR7_Pos               _U_(7)                                               /**< (EVSYS_INTENSET) Channel 7 Overrun Interrupt Enable Position */
#define EVSYS_INTENSET_OVR7_Msk               (_U_(0x1) << EVSYS_INTENSET_OVR7_Pos)                /**< (EVSYS_INTENSET) Channel 7 Overrun Interrupt Enable Mask */
#define EVSYS_INTENSET_OVR7(value)            (EVSYS_INTENSET_OVR7_Msk & ((value) << EVSYS_INTENSET_OVR7_Pos))
#define EVSYS_INTENSET_EVD0_Pos               _U_(16)                                              /**< (EVSYS_INTENSET) Channel 0 Event Detection Interrupt Enable Position */
#define EVSYS_INTENSET_EVD0_Msk               (_U_(0x1) << EVSYS_INTENSET_EVD0_Pos)                /**< (EVSYS_INTENSET) Channel 0 Event Detection Interrupt Enable Mask */
#define EVSYS_INTENSET_EVD0(value)            (EVSYS_INTENSET_EVD0_Msk & ((value) << EVSYS_INTENSET_EVD0_Pos))
#define EVSYS_INTENSET_EVD1_Pos               _U_(17)                                              /**< (EVSYS_INTENSET) Channel 1 Event Detection Interrupt Enable Position */
#define EVSYS_INTENSET_EVD1_Msk               (_U_(0x1) << EVSYS_INTENSET_EVD1_Pos)                /**< (EVSYS_INTENSET) Channel 1 Event Detection Interrupt Enable Mask */
#define EVSYS_INTENSET_EVD1(value)            (EVSYS_INTENSET_EVD1_Msk & ((value) << EVSYS_INTENSET_EVD1_Pos))
#define EVSYS_INTENSET_EVD2_Pos               _U_(18)                                              /**< (EVSYS_INTENSET) Channel 2 Event Detection Interrupt Enable Position */
#define EVSYS_INTENSET_EVD2_Msk               (_U_(0x1) << EVSYS_INTENSET_EVD2_Pos)                /**< (EVSYS_INTENSET) Channel 2 Event Detection Interrupt Enable Mask */
#define EVSYS_INTENSET_EVD2(value)            (EVSYS_INTENSET_EVD2_Msk & ((value) << EVSYS_INTENSET_EVD2_Pos))
#define EVSYS_INTENSET_EVD3_Pos               _U_(19)                                              /**< (EVSYS_INTENSET) Channel 3 Event Detection Interrupt Enable Position */
#define EVSYS_INTENSET_EVD3_Msk               (_U_(0x1) << EVSYS_INTENSET_EVD3_Pos)                /**< (EVSYS_INTENSET) Channel 3 Event Detection Interrupt Enable Mask */
#define EVSYS_INTENSET_EVD3(value)            (EVSYS_INTENSET_EVD3_Msk & ((value) << EVSYS_INTENSET_EVD3_Pos))
#define EVSYS_INTENSET_EVD4_Pos               _U_(20)                                              /**< (EVSYS_INTENSET) Channel 4 Event Detection Interrupt Enable Position */
#define EVSYS_INTENSET_EVD4_Msk               (_U_(0x1) << EVSYS_INTENSET_EVD4_Pos)                /**< (EVSYS_INTENSET) Channel 4 Event Detection Interrupt Enable Mask */
#define EVSYS_INTENSET_EVD4(value)            (EVSYS_INTENSET_EVD4_Msk & ((value) << EVSYS_INTENSET_EVD4_Pos))
#define EVSYS_INTENSET_EVD5_Pos               _U_(21)                                              /**< (EVSYS_INTENSET) Channel 5 Event Detection Interrupt Enable Position */
#define EVSYS_INTENSET_EVD5_Msk               (_U_(0x1) << EVSYS_INTENSET_EVD5_Pos)                /**< (EVSYS_INTENSET) Channel 5 Event Detection Interrupt Enable Mask */
#define EVSYS_INTENSET_EVD5(value)            (EVSYS_INTENSET_EVD5_Msk & ((value) << EVSYS_INTENSET_EVD5_Pos))
#define EVSYS_INTENSET_EVD6_Pos               _U_(22)                                              /**< (EVSYS_INTENSET) Channel 6 Event Detection Interrupt Enable Position */
#define EVSYS_INTENSET_EVD6_Msk               (_U_(0x1) << EVSYS_INTENSET_EVD6_Pos)                /**< (EVSYS_INTENSET) Channel 6 Event Detection Interrupt Enable Mask */
#define EVSYS_INTENSET_EVD6(value)            (EVSYS_INTENSET_EVD6_Msk & ((value) << EVSYS_INTENSET_EVD6_Pos))
#define EVSYS_INTENSET_EVD7_Pos               _U_(23)                                              /**< (EVSYS_INTENSET) Channel 7 Event Detection Interrupt Enable Position */
#define EVSYS_INTENSET_EVD7_Msk               (_U_(0x1) << EVSYS_INTENSET_EVD7_Pos)                /**< (EVSYS_INTENSET) Channel 7 Event Detection Interrupt Enable Mask */
#define EVSYS_INTENSET_EVD7(value)            (EVSYS_INTENSET_EVD7_Msk & ((value) << EVSYS_INTENSET_EVD7_Pos))
#define EVSYS_INTENSET_Msk                    _U_(0x00FF00FF)                                      /**< (EVSYS_INTENSET) Register Mask  */

#define EVSYS_INTENSET_OVR_Pos                _U_(0)                                               /**< (EVSYS_INTENSET Position) Channel x Overrun Interrupt Enable */
#define EVSYS_INTENSET_OVR_Msk                (_U_(0xFF) << EVSYS_INTENSET_OVR_Pos)                /**< (EVSYS_INTENSET Mask) OVR */
#define EVSYS_INTENSET_OVR(value)             (EVSYS_INTENSET_OVR_Msk & ((value) << EVSYS_INTENSET_OVR_Pos)) 
#define EVSYS_INTENSET_EVD_Pos                _U_(16)                                              /**< (EVSYS_INTENSET Position) Channel 7 Event Detection Interrupt Enable */
#define EVSYS_INTENSET_EVD_Msk                (_U_(0xFF) << EVSYS_INTENSET_EVD_Pos)                /**< (EVSYS_INTENSET Mask) EVD */
#define EVSYS_INTENSET_EVD(value)             (EVSYS_INTENSET_EVD_Msk & ((value) << EVSYS_INTENSET_EVD_Pos)) 

/* -------- EVSYS_INTFLAG : (EVSYS Offset: 0x18) (R/W 32) Interrupt Flag Status and Clear -------- */
#define EVSYS_INTFLAG_RESETVALUE              _U_(0x00)                                            /**<  (EVSYS_INTFLAG) Interrupt Flag Status and Clear  Reset Value */

#define EVSYS_INTFLAG_OVR0_Pos                _U_(0)                                               /**< (EVSYS_INTFLAG) Channel 0 Overrun Position */
#define EVSYS_INTFLAG_OVR0_Msk                (_U_(0x1) << EVSYS_INTFLAG_OVR0_Pos)                 /**< (EVSYS_INTFLAG) Channel 0 Overrun Mask */
#define EVSYS_INTFLAG_OVR0(value)             (EVSYS_INTFLAG_OVR0_Msk & ((value) << EVSYS_INTFLAG_OVR0_Pos))
#define EVSYS_INTFLAG_OVR1_Pos                _U_(1)                                               /**< (EVSYS_INTFLAG) Channel 1 Overrun Position */
#define EVSYS_INTFLAG_OVR1_Msk                (_U_(0x1) << EVSYS_INTFLAG_OVR1_Pos)                 /**< (EVSYS_INTFLAG) Channel 1 Overrun Mask */
#define EVSYS_INTFLAG_OVR1(value)             (EVSYS_INTFLAG_OVR1_Msk & ((value) << EVSYS_INTFLAG_OVR1_Pos))
#define EVSYS_INTFLAG_OVR2_Pos                _U_(2)                                               /**< (EVSYS_INTFLAG) Channel 2 Overrun Position */
#define EVSYS_INTFLAG_OVR2_Msk                (_U_(0x1) << EVSYS_INTFLAG_OVR2_Pos)                 /**< (EVSYS_INTFLAG) Channel 2 Overrun Mask */
#define EVSYS_INTFLAG_OVR2(value)             (EVSYS_INTFLAG_OVR2_Msk & ((value) << EVSYS_INTFLAG_OVR2_Pos))
#define EVSYS_INTFLAG_OVR3_Pos                _U_(3)                                               /**< (EVSYS_INTFLAG) Channel 3 Overrun Position */
#define EVSYS_INTFLAG_OVR3_Msk                (_U_(0x1) << EVSYS_INTFLAG_OVR3_Pos)                 /**< (EVSYS_INTFLAG) Channel 3 Overrun Mask */
#define EVSYS_INTFLAG_OVR3(value)             (EVSYS_INTFLAG_OVR3_Msk & ((value) << EVSYS_INTFLAG_OVR3_Pos))
#define EVSYS_INTFLAG_OVR4_Pos                _U_(4)                                               /**< (EVSYS_INTFLAG) Channel 4 Overrun Position */
#define EVSYS_INTFLAG_OVR4_Msk                (_U_(0x1) << EVSYS_INTFLAG_OVR4_Pos)                 /**< (EVSYS_INTFLAG) Channel 4 Overrun Mask */
#define EVSYS_INTFLAG_OVR4(value)             (EVSYS_INTFLAG_OVR4_Msk & ((value) << EVSYS_INTFLAG_OVR4_Pos))
#define EVSYS_INTFLAG_OVR5_Pos                _U_(5)                                               /**< (EVSYS_INTFLAG) Channel 5 Overrun Position */
#define EVSYS_INTFLAG_OVR5_Msk                (_U_(0x1) << EVSYS_INTFLAG_OVR5_Pos)                 /**< (EVSYS_INTFLAG) Channel 5 Overrun Mask */
#define EVSYS_INTFLAG_OVR5(value)             (EVSYS_INTFLAG_OVR5_Msk & ((value) << EVSYS_INTFLAG_OVR5_Pos))
#define EVSYS_INTFLAG_OVR6_Pos                _U_(6)                                               /**< (EVSYS_INTFLAG) Channel 6 Overrun Position */
#define EVSYS_INTFLAG_OVR6_Msk                (_U_(0x1) << EVSYS_INTFLAG_OVR6_Pos)                 /**< (EVSYS_INTFLAG) Channel 6 Overrun Mask */
#define EVSYS_INTFLAG_OVR6(value)             (EVSYS_INTFLAG_OVR6_Msk & ((value) << EVSYS_INTFLAG_OVR6_Pos))
#define EVSYS_INTFLAG_OVR7_Pos                _U_(7)                                               /**< (EVSYS_INTFLAG) Channel 7 Overrun Position */
#define EVSYS_INTFLAG_OVR7_Msk                (_U_(0x1) << EVSYS_INTFLAG_OVR7_Pos)                 /**< (EVSYS_INTFLAG) Channel 7 Overrun Mask */
#define EVSYS_INTFLAG_OVR7(value)             (EVSYS_INTFLAG_OVR7_Msk & ((value) << EVSYS_INTFLAG_OVR7_Pos))
#define EVSYS_INTFLAG_EVD0_Pos                _U_(16)                                              /**< (EVSYS_INTFLAG) Channel 0 Event Detection Position */
#define EVSYS_INTFLAG_EVD0_Msk                (_U_(0x1) << EVSYS_INTFLAG_EVD0_Pos)                 /**< (EVSYS_INTFLAG) Channel 0 Event Detection Mask */
#define EVSYS_INTFLAG_EVD0(value)             (EVSYS_INTFLAG_EVD0_Msk & ((value) << EVSYS_INTFLAG_EVD0_Pos))
#define EVSYS_INTFLAG_EVD1_Pos                _U_(17)                                              /**< (EVSYS_INTFLAG) Channel 1 Event Detection Position */
#define EVSYS_INTFLAG_EVD1_Msk                (_U_(0x1) << EVSYS_INTFLAG_EVD1_Pos)                 /**< (EVSYS_INTFLAG) Channel 1 Event Detection Mask */
#define EVSYS_INTFLAG_EVD1(value)             (EVSYS_INTFLAG_EVD1_Msk & ((value) << EVSYS_INTFLAG_EVD1_Pos))
#define EVSYS_INTFLAG_EVD2_Pos                _U_(18)                                              /**< (EVSYS_INTFLAG) Channel 2 Event Detection Position */
#define EVSYS_INTFLAG_EVD2_Msk                (_U_(0x1) << EVSYS_INTFLAG_EVD2_Pos)                 /**< (EVSYS_INTFLAG) Channel 2 Event Detection Mask */
#define EVSYS_INTFLAG_EVD2(value)             (EVSYS_INTFLAG_EVD2_Msk & ((value) << EVSYS_INTFLAG_EVD2_Pos))
#define EVSYS_INTFLAG_EVD3_Pos                _U_(19)                                              /**< (EVSYS_INTFLAG) Channel 3 Event Detection Position */
#define EVSYS_INTFLAG_EVD3_Msk                (_U_(0x1) << EVSYS_INTFLAG_EVD3_Pos)                 /**< (EVSYS_INTFLAG) Channel 3 Event Detection Mask */
#define EVSYS_INTFLAG_EVD3(value)             (EVSYS_INTFLAG_EVD3_Msk & ((value) << EVSYS_INTFLAG_EVD3_Pos))
#define EVSYS_INTFLAG_EVD4_Pos                _U_(20)                                              /**< (EVSYS_INTFLAG) Channel 4 Event Detection Position */
#define EVSYS_INTFLAG_EVD4_Msk                (_U_(0x1) << EVSYS_INTFLAG_EVD4_Pos)                 /**< (EVSYS_INTFLAG) Channel 4 Event Detection Mask */
#define EVSYS_INTFLAG_EVD4(value)             (EVSYS_INTFLAG_EVD4_Msk & ((value) << EVSYS_INTFLAG_EVD4_Pos))
#define EVSYS_INTFLAG_EVD5_Pos                _U_(21)                                              /**< (EVSYS_INTFLAG) Channel 5 Event Detection Position */
#define EVSYS_INTFLAG_EVD5_Msk                (_U_(0x1) << EVSYS_INTFLAG_EVD5_Pos)                 /**< (EVSYS_INTFLAG) Channel 5 Event Detection Mask */
#define EVSYS_INTFLAG_EVD5(value)             (EVSYS_INTFLAG_EVD5_Msk & ((value) << EVSYS_INTFLAG_EVD5_Pos))
#define EVSYS_INTFLAG_EVD6_Pos                _U_(22)                                              /**< (EVSYS_INTFLAG) Channel 6 Event Detection Position */
#define EVSYS_INTFLAG_EVD6_Msk                (_U_(0x1) << EVSYS_INTFLAG_EVD6_Pos)                 /**< (EVSYS_INTFLAG) Channel 6 Event Detection Mask */
#define EVSYS_INTFLAG_EVD6(value)             (EVSYS_INTFLAG_EVD6_Msk & ((value) << EVSYS_INTFLAG_EVD6_Pos))
#define EVSYS_INTFLAG_EVD7_Pos                _U_(23)                                              /**< (EVSYS_INTFLAG) Channel 7 Event Detection Position */
#define EVSYS_INTFLAG_EVD7_Msk                (_U_(0x1) << EVSYS_INTFLAG_EVD7_Pos)                 /**< (EVSYS_INTFLAG) Channel 7 Event Detection Mask */
#define EVSYS_INTFLAG_EVD7(value)             (EVSYS_INTFLAG_EVD7_Msk & ((value) << EVSYS_INTFLAG_EVD7_Pos))
#define EVSYS_INTFLAG_Msk                     _U_(0x00FF00FF)                                      /**< (EVSYS_INTFLAG) Register Mask  */

#define EVSYS_INTFLAG_OVR_Pos                 _U_(0)                                               /**< (EVSYS_INTFLAG Position) Channel x Overrun */
#define EVSYS_INTFLAG_OVR_Msk                 (_U_(0xFF) << EVSYS_INTFLAG_OVR_Pos)                 /**< (EVSYS_INTFLAG Mask) OVR */
#define EVSYS_INTFLAG_OVR(value)              (EVSYS_INTFLAG_OVR_Msk & ((value) << EVSYS_INTFLAG_OVR_Pos)) 
#define EVSYS_INTFLAG_EVD_Pos                 _U_(16)                                              /**< (EVSYS_INTFLAG Position) Channel 7 Event Detection */
#define EVSYS_INTFLAG_EVD_Msk                 (_U_(0xFF) << EVSYS_INTFLAG_EVD_Pos)                 /**< (EVSYS_INTFLAG Mask) EVD */
#define EVSYS_INTFLAG_EVD(value)              (EVSYS_INTFLAG_EVD_Msk & ((value) << EVSYS_INTFLAG_EVD_Pos)) 

/* -------- EVSYS_SWEVT : (EVSYS Offset: 0x1C) ( /W 32) Software Event -------- */
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

/* -------- EVSYS_CHANNEL : (EVSYS Offset: 0x20) (R/W 32) Channel n -------- */
#define EVSYS_CHANNEL_RESETVALUE              _U_(0x8000)                                          /**<  (EVSYS_CHANNEL) Channel n  Reset Value */

#define EVSYS_CHANNEL_EVGEN_Pos               _U_(0)                                               /**< (EVSYS_CHANNEL) Event Generator Selection Position */
#define EVSYS_CHANNEL_EVGEN_Msk               (_U_(0x7F) << EVSYS_CHANNEL_EVGEN_Pos)               /**< (EVSYS_CHANNEL) Event Generator Selection Mask */
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
#define EVSYS_CHANNEL_Msk                     _U_(0x0000CF7F)                                      /**< (EVSYS_CHANNEL) Register Mask  */


/* -------- EVSYS_USER : (EVSYS Offset: 0x80) (R/W 32) User Multiplexer n -------- */
#define EVSYS_USER_RESETVALUE                 _U_(0x00)                                            /**<  (EVSYS_USER) User Multiplexer n  Reset Value */

#define EVSYS_USER_CHANNEL_Pos                _U_(0)                                               /**< (EVSYS_USER) Channel Event Selection Position */
#define EVSYS_USER_CHANNEL_Msk                (_U_(0xF) << EVSYS_USER_CHANNEL_Pos)                 /**< (EVSYS_USER) Channel Event Selection Mask */
#define EVSYS_USER_CHANNEL(value)             (EVSYS_USER_CHANNEL_Msk & ((value) << EVSYS_USER_CHANNEL_Pos))
#define EVSYS_USER_Msk                        _U_(0x0000000F)                                      /**< (EVSYS_USER) Register Mask  */


/** \brief EVSYS register offsets definitions */
#define EVSYS_CTRLA_REG_OFST           (0x00)              /**< (EVSYS_CTRLA) Control Offset */
#define EVSYS_CHSTATUS_REG_OFST        (0x0C)              /**< (EVSYS_CHSTATUS) Channel Status Offset */
#define EVSYS_INTENCLR_REG_OFST        (0x10)              /**< (EVSYS_INTENCLR) Interrupt Enable Clear Offset */
#define EVSYS_INTENSET_REG_OFST        (0x14)              /**< (EVSYS_INTENSET) Interrupt Enable Set Offset */
#define EVSYS_INTFLAG_REG_OFST         (0x18)              /**< (EVSYS_INTFLAG) Interrupt Flag Status and Clear Offset */
#define EVSYS_SWEVT_REG_OFST           (0x1C)              /**< (EVSYS_SWEVT) Software Event Offset */
#define EVSYS_CHANNEL_REG_OFST         (0x20)              /**< (EVSYS_CHANNEL) Channel n Offset */
#define EVSYS_CHANNEL0_REG_OFST        (0x20)              /**< (EVSYS_CHANNEL0) Channel n Offset */
#define EVSYS_CHANNEL1_REG_OFST        (0x24)              /**< (EVSYS_CHANNEL1) Channel n Offset */
#define EVSYS_CHANNEL2_REG_OFST        (0x28)              /**< (EVSYS_CHANNEL2) Channel n Offset */
#define EVSYS_CHANNEL3_REG_OFST        (0x2C)              /**< (EVSYS_CHANNEL3) Channel n Offset */
#define EVSYS_CHANNEL4_REG_OFST        (0x30)              /**< (EVSYS_CHANNEL4) Channel n Offset */
#define EVSYS_CHANNEL5_REG_OFST        (0x34)              /**< (EVSYS_CHANNEL5) Channel n Offset */
#define EVSYS_CHANNEL6_REG_OFST        (0x38)              /**< (EVSYS_CHANNEL6) Channel n Offset */
#define EVSYS_CHANNEL7_REG_OFST        (0x3C)              /**< (EVSYS_CHANNEL7) Channel n Offset */
#define EVSYS_USER_REG_OFST            (0x80)              /**< (EVSYS_USER) User Multiplexer n Offset */
#define EVSYS_USER0_REG_OFST           (0x80)              /**< (EVSYS_USER0) User Multiplexer n Offset */
#define EVSYS_USER1_REG_OFST           (0x84)              /**< (EVSYS_USER1) User Multiplexer n Offset */
#define EVSYS_USER2_REG_OFST           (0x88)              /**< (EVSYS_USER2) User Multiplexer n Offset */
#define EVSYS_USER3_REG_OFST           (0x8C)              /**< (EVSYS_USER3) User Multiplexer n Offset */
#define EVSYS_USER4_REG_OFST           (0x90)              /**< (EVSYS_USER4) User Multiplexer n Offset */
#define EVSYS_USER5_REG_OFST           (0x94)              /**< (EVSYS_USER5) User Multiplexer n Offset */
#define EVSYS_USER6_REG_OFST           (0x98)              /**< (EVSYS_USER6) User Multiplexer n Offset */
#define EVSYS_USER7_REG_OFST           (0x9C)              /**< (EVSYS_USER7) User Multiplexer n Offset */
#define EVSYS_USER8_REG_OFST           (0xA0)              /**< (EVSYS_USER8) User Multiplexer n Offset */
#define EVSYS_USER9_REG_OFST           (0xA4)              /**< (EVSYS_USER9) User Multiplexer n Offset */
#define EVSYS_USER10_REG_OFST          (0xA8)              /**< (EVSYS_USER10) User Multiplexer n Offset */
#define EVSYS_USER11_REG_OFST          (0xAC)              /**< (EVSYS_USER11) User Multiplexer n Offset */
#define EVSYS_USER12_REG_OFST          (0xB0)              /**< (EVSYS_USER12) User Multiplexer n Offset */
#define EVSYS_USER13_REG_OFST          (0xB4)              /**< (EVSYS_USER13) User Multiplexer n Offset */
#define EVSYS_USER14_REG_OFST          (0xB8)              /**< (EVSYS_USER14) User Multiplexer n Offset */
#define EVSYS_USER15_REG_OFST          (0xBC)              /**< (EVSYS_USER15) User Multiplexer n Offset */
#define EVSYS_USER16_REG_OFST          (0xC0)              /**< (EVSYS_USER16) User Multiplexer n Offset */
#define EVSYS_USER17_REG_OFST          (0xC4)              /**< (EVSYS_USER17) User Multiplexer n Offset */
#define EVSYS_USER18_REG_OFST          (0xC8)              /**< (EVSYS_USER18) User Multiplexer n Offset */
#define EVSYS_USER19_REG_OFST          (0xCC)              /**< (EVSYS_USER19) User Multiplexer n Offset */
#define EVSYS_USER20_REG_OFST          (0xD0)              /**< (EVSYS_USER20) User Multiplexer n Offset */
#define EVSYS_USER21_REG_OFST          (0xD4)              /**< (EVSYS_USER21) User Multiplexer n Offset */
#define EVSYS_USER22_REG_OFST          (0xD8)              /**< (EVSYS_USER22) User Multiplexer n Offset */
#define EVSYS_USER23_REG_OFST          (0xDC)              /**< (EVSYS_USER23) User Multiplexer n Offset */
#define EVSYS_USER24_REG_OFST          (0xE0)              /**< (EVSYS_USER24) User Multiplexer n Offset */
#define EVSYS_USER25_REG_OFST          (0xE4)              /**< (EVSYS_USER25) User Multiplexer n Offset */
#define EVSYS_USER26_REG_OFST          (0xE8)              /**< (EVSYS_USER26) User Multiplexer n Offset */
#define EVSYS_USER27_REG_OFST          (0xEC)              /**< (EVSYS_USER27) User Multiplexer n Offset */
#define EVSYS_USER28_REG_OFST          (0xF0)              /**< (EVSYS_USER28) User Multiplexer n Offset */
#define EVSYS_USER29_REG_OFST          (0xF4)              /**< (EVSYS_USER29) User Multiplexer n Offset */
#define EVSYS_USER30_REG_OFST          (0xF8)              /**< (EVSYS_USER30) User Multiplexer n Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief EVSYS register API structure */
typedef struct
{  /* Event System Interface */
  __IO  uint8_t                        EVSYS_CTRLA;        /**< Offset: 0x00 (R/W  8) Control */
  __I   uint8_t                        Reserved1[0x0B];
  __I   uint32_t                       EVSYS_CHSTATUS;     /**< Offset: 0x0C (R/   32) Channel Status */
  __IO  uint32_t                       EVSYS_INTENCLR;     /**< Offset: 0x10 (R/W  32) Interrupt Enable Clear */
  __IO  uint32_t                       EVSYS_INTENSET;     /**< Offset: 0x14 (R/W  32) Interrupt Enable Set */
  __IO  uint32_t                       EVSYS_INTFLAG;      /**< Offset: 0x18 (R/W  32) Interrupt Flag Status and Clear */
  __O   uint32_t                       EVSYS_SWEVT;        /**< Offset: 0x1C ( /W  32) Software Event */
  __IO  uint32_t                       EVSYS_CHANNEL[8];   /**< Offset: 0x20 (R/W  32) Channel n */
  __I   uint8_t                        Reserved2[0x40];
  __IO  uint32_t                       EVSYS_USER[31];     /**< Offset: 0x80 (R/W  32) User Multiplexer n */
} evsys_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAML22_EVSYS_COMPONENT_H_ */
