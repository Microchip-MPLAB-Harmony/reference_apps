/*
 * Component description for FREQM
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
#ifndef _PIC32CZCA90_FREQM_COMPONENT_H_
#define _PIC32CZCA90_FREQM_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR FREQM                                        */
/* ************************************************************************** */

/* -------- FREQM_CTRLA : (FREQM Offset: 0x00) (R/W 8) Control A Register -------- */
#define FREQM_CTRLA_RESETVALUE                _UINT8_(0x80)                                        /*  (FREQM_CTRLA) Control A Register  Reset Value */

#define FREQM_CTRLA_SWRST_Pos                 _UINT8_(0)                                           /* (FREQM_CTRLA) Software Reset Position */
#define FREQM_CTRLA_SWRST_Msk                 (_UINT8_(0x1) << FREQM_CTRLA_SWRST_Pos)              /* (FREQM_CTRLA) Software Reset Mask */
#define FREQM_CTRLA_SWRST(value)              (FREQM_CTRLA_SWRST_Msk & (_UINT8_(value) << FREQM_CTRLA_SWRST_Pos)) /* Assigment of value for SWRST in the FREQM_CTRLA register */
#define FREQM_CTRLA_ENABLE_Pos                _UINT8_(1)                                           /* (FREQM_CTRLA) Enable Position */
#define FREQM_CTRLA_ENABLE_Msk                (_UINT8_(0x1) << FREQM_CTRLA_ENABLE_Pos)             /* (FREQM_CTRLA) Enable Mask */
#define FREQM_CTRLA_ENABLE(value)             (FREQM_CTRLA_ENABLE_Msk & (_UINT8_(value) << FREQM_CTRLA_ENABLE_Pos)) /* Assigment of value for ENABLE in the FREQM_CTRLA register */
#define FREQM_CTRLA_FREERUN_Pos               _UINT8_(2)                                           /* (FREQM_CTRLA) Free Running Mode Position */
#define FREQM_CTRLA_FREERUN_Msk               (_UINT8_(0x1) << FREQM_CTRLA_FREERUN_Pos)            /* (FREQM_CTRLA) Free Running Mode Mask */
#define FREQM_CTRLA_FREERUN(value)            (FREQM_CTRLA_FREERUN_Msk & (_UINT8_(value) << FREQM_CTRLA_FREERUN_Pos)) /* Assigment of value for FREERUN in the FREQM_CTRLA register */
#define FREQM_CTRLA_RUNSTDBY_Pos              _UINT8_(6)                                           /* (FREQM_CTRLA) Run In Standby Position */
#define FREQM_CTRLA_RUNSTDBY_Msk              (_UINT8_(0x1) << FREQM_CTRLA_RUNSTDBY_Pos)           /* (FREQM_CTRLA) Run In Standby Mask */
#define FREQM_CTRLA_RUNSTDBY(value)           (FREQM_CTRLA_RUNSTDBY_Msk & (_UINT8_(value) << FREQM_CTRLA_RUNSTDBY_Pos)) /* Assigment of value for RUNSTDBY in the FREQM_CTRLA register */
#define FREQM_CTRLA_ONDEMAND_Pos              _UINT8_(7)                                           /* (FREQM_CTRLA) On Demand Control Position */
#define FREQM_CTRLA_ONDEMAND_Msk              (_UINT8_(0x1) << FREQM_CTRLA_ONDEMAND_Pos)           /* (FREQM_CTRLA) On Demand Control Mask */
#define FREQM_CTRLA_ONDEMAND(value)           (FREQM_CTRLA_ONDEMAND_Msk & (_UINT8_(value) << FREQM_CTRLA_ONDEMAND_Pos)) /* Assigment of value for ONDEMAND in the FREQM_CTRLA register */
#define FREQM_CTRLA_Msk                       _UINT8_(0xC7)                                        /* (FREQM_CTRLA) Register Mask  */


/* -------- FREQM_CTRLB : (FREQM Offset: 0x01) ( /W 8) Control B Register -------- */
#define FREQM_CTRLB_RESETVALUE                _UINT8_(0x00)                                        /*  (FREQM_CTRLB) Control B Register  Reset Value */

#define FREQM_CTRLB_START_Pos                 _UINT8_(0)                                           /* (FREQM_CTRLB) Start Measurement Position */
#define FREQM_CTRLB_START_Msk                 (_UINT8_(0x1) << FREQM_CTRLB_START_Pos)              /* (FREQM_CTRLB) Start Measurement Mask */
#define FREQM_CTRLB_START(value)              (FREQM_CTRLB_START_Msk & (_UINT8_(value) << FREQM_CTRLB_START_Pos)) /* Assigment of value for START in the FREQM_CTRLB register */
#define FREQM_CTRLB_Msk                       _UINT8_(0x01)                                        /* (FREQM_CTRLB) Register Mask  */


/* -------- FREQM_CFGA : (FREQM Offset: 0x02) (R/W 16) Config A Register -------- */
#define FREQM_CFGA_RESETVALUE                 _UINT16_(0x00)                                       /*  (FREQM_CFGA) Config A Register  Reset Value */

#define FREQM_CFGA_REFNUM_Pos                 _UINT16_(0)                                          /* (FREQM_CFGA) Number of Reference Clock Cycles Position */
#define FREQM_CFGA_REFNUM_Msk                 (_UINT16_(0xFF) << FREQM_CFGA_REFNUM_Pos)            /* (FREQM_CFGA) Number of Reference Clock Cycles Mask */
#define FREQM_CFGA_REFNUM(value)              (FREQM_CFGA_REFNUM_Msk & (_UINT16_(value) << FREQM_CFGA_REFNUM_Pos)) /* Assigment of value for REFNUM in the FREQM_CFGA register */
#define FREQM_CFGA_MSRSEL_Pos                 _UINT16_(8)                                          /* (FREQM_CFGA) Measurement Clock Selection Position */
#define FREQM_CFGA_MSRSEL_Msk                 (_UINT16_(0x7) << FREQM_CFGA_MSRSEL_Pos)             /* (FREQM_CFGA) Measurement Clock Selection Mask */
#define FREQM_CFGA_MSRSEL(value)              (FREQM_CFGA_MSRSEL_Msk & (_UINT16_(value) << FREQM_CFGA_MSRSEL_Pos)) /* Assigment of value for MSRSEL in the FREQM_CFGA register */
#define   FREQM_CFGA_MSRSEL_GCLK_Val          _UINT16_(0x0)                                        /* (FREQM_CFGA) GCLK Input Clock  */
#define   FREQM_CFGA_MSRSEL_CPU_Val           _UINT16_(0x1)                                        /* (FREQM_CFGA) CPU Input Clock  */
#define FREQM_CFGA_MSRSEL_GCLK                (FREQM_CFGA_MSRSEL_GCLK_Val << FREQM_CFGA_MSRSEL_Pos) /* (FREQM_CFGA) GCLK Input Clock Position  */
#define FREQM_CFGA_MSRSEL_CPU                 (FREQM_CFGA_MSRSEL_CPU_Val << FREQM_CFGA_MSRSEL_Pos) /* (FREQM_CFGA) CPU Input Clock Position  */
#define FREQM_CFGA_DIVREF_Pos                 _UINT16_(15)                                         /* (FREQM_CFGA) Divide Reference Clock Position */
#define FREQM_CFGA_DIVREF_Msk                 (_UINT16_(0x1) << FREQM_CFGA_DIVREF_Pos)             /* (FREQM_CFGA) Divide Reference Clock Mask */
#define FREQM_CFGA_DIVREF(value)              (FREQM_CFGA_DIVREF_Msk & (_UINT16_(value) << FREQM_CFGA_DIVREF_Pos)) /* Assigment of value for DIVREF in the FREQM_CFGA register */
#define   FREQM_CFGA_DIVREF_DIV1_Val          _UINT16_(0x0)                                        /* (FREQM_CFGA) The reference clock is divided by 1  */
#define   FREQM_CFGA_DIVREF_DIV8_Val          _UINT16_(0x1)                                        /* (FREQM_CFGA) The reference clock is divided by 8  */
#define FREQM_CFGA_DIVREF_DIV1                (FREQM_CFGA_DIVREF_DIV1_Val << FREQM_CFGA_DIVREF_Pos) /* (FREQM_CFGA) The reference clock is divided by 1 Position  */
#define FREQM_CFGA_DIVREF_DIV8                (FREQM_CFGA_DIVREF_DIV8_Val << FREQM_CFGA_DIVREF_Pos) /* (FREQM_CFGA) The reference clock is divided by 8 Position  */
#define FREQM_CFGA_Msk                        _UINT16_(0x87FF)                                     /* (FREQM_CFGA) Register Mask  */


/* -------- FREQM_CTRLC : (FREQM Offset: 0x04) (R/W 8) Control C Register -------- */
#define FREQM_CTRLC_RESETVALUE                _UINT8_(0x00)                                        /*  (FREQM_CTRLC) Control C Register  Reset Value */

#define FREQM_CTRLC_WINMODE_Pos               _UINT8_(0)                                           /* (FREQM_CTRLC) Window Monitor Mode Position */
#define FREQM_CTRLC_WINMODE_Msk               (_UINT8_(0x7) << FREQM_CTRLC_WINMODE_Pos)            /* (FREQM_CTRLC) Window Monitor Mode Mask */
#define FREQM_CTRLC_WINMODE(value)            (FREQM_CTRLC_WINMODE_Msk & (_UINT8_(value) << FREQM_CTRLC_WINMODE_Pos)) /* Assigment of value for WINMODE in the FREQM_CTRLC register */
#define   FREQM_CTRLC_WINMODE_DISABLE_Val     _UINT8_(0x0)                                         /* (FREQM_CTRLC) No window mode (default)  */
#define   FREQM_CTRLC_WINMODE_MODE1_Val       _UINT8_(0x1)                                         /* (FREQM_CTRLC) VALUE > WINLT  */
#define   FREQM_CTRLC_WINMODE_MODE2_Val       _UINT8_(0x2)                                         /* (FREQM_CTRLC) VALUE < WINUT  */
#define   FREQM_CTRLC_WINMODE_MODE3_Val       _UINT8_(0x3)                                         /* (FREQM_CTRLC) WINLT < VALUE < WINUT  */
#define   FREQM_CTRLC_WINMODE_MODE4_Val       _UINT8_(0x4)                                         /* (FREQM_CTRLC) !(WINLT < VALUE < WINUT)  */
#define FREQM_CTRLC_WINMODE_DISABLE           (FREQM_CTRLC_WINMODE_DISABLE_Val << FREQM_CTRLC_WINMODE_Pos) /* (FREQM_CTRLC) No window mode (default) Position  */
#define FREQM_CTRLC_WINMODE_MODE1             (FREQM_CTRLC_WINMODE_MODE1_Val << FREQM_CTRLC_WINMODE_Pos) /* (FREQM_CTRLC) VALUE > WINLT Position  */
#define FREQM_CTRLC_WINMODE_MODE2             (FREQM_CTRLC_WINMODE_MODE2_Val << FREQM_CTRLC_WINMODE_Pos) /* (FREQM_CTRLC) VALUE < WINUT Position  */
#define FREQM_CTRLC_WINMODE_MODE3             (FREQM_CTRLC_WINMODE_MODE3_Val << FREQM_CTRLC_WINMODE_Pos) /* (FREQM_CTRLC) WINLT < VALUE < WINUT Position  */
#define FREQM_CTRLC_WINMODE_MODE4             (FREQM_CTRLC_WINMODE_MODE4_Val << FREQM_CTRLC_WINMODE_Pos) /* (FREQM_CTRLC) !(WINLT < VALUE < WINUT) Position  */
#define FREQM_CTRLC_Msk                       _UINT8_(0x07)                                        /* (FREQM_CTRLC) Register Mask  */


/* -------- FREQM_EVCTRL : (FREQM Offset: 0x06) (R/W 8) Event Control Register -------- */
#define FREQM_EVCTRL_RESETVALUE               _UINT8_(0x00)                                        /*  (FREQM_EVCTRL) Event Control Register  Reset Value */

#define FREQM_EVCTRL_STARTEI_Pos              _UINT8_(0)                                           /* (FREQM_EVCTRL) Start Measurement Event Input Enable Position */
#define FREQM_EVCTRL_STARTEI_Msk              (_UINT8_(0x1) << FREQM_EVCTRL_STARTEI_Pos)           /* (FREQM_EVCTRL) Start Measurement Event Input Enable Mask */
#define FREQM_EVCTRL_STARTEI(value)           (FREQM_EVCTRL_STARTEI_Msk & (_UINT8_(value) << FREQM_EVCTRL_STARTEI_Pos)) /* Assigment of value for STARTEI in the FREQM_EVCTRL register */
#define FREQM_EVCTRL_STARTINV_Pos             _UINT8_(1)                                           /* (FREQM_EVCTRL) Start Measurement Event Invert Enable Position */
#define FREQM_EVCTRL_STARTINV_Msk             (_UINT8_(0x1) << FREQM_EVCTRL_STARTINV_Pos)          /* (FREQM_EVCTRL) Start Measurement Event Invert Enable Mask */
#define FREQM_EVCTRL_STARTINV(value)          (FREQM_EVCTRL_STARTINV_Msk & (_UINT8_(value) << FREQM_EVCTRL_STARTINV_Pos)) /* Assigment of value for STARTINV in the FREQM_EVCTRL register */
#define FREQM_EVCTRL_DONEEO_Pos               _UINT8_(4)                                           /* (FREQM_EVCTRL) Measurement Done Event Out Position */
#define FREQM_EVCTRL_DONEEO_Msk               (_UINT8_(0x1) << FREQM_EVCTRL_DONEEO_Pos)            /* (FREQM_EVCTRL) Measurement Done Event Out Mask */
#define FREQM_EVCTRL_DONEEO(value)            (FREQM_EVCTRL_DONEEO_Msk & (_UINT8_(value) << FREQM_EVCTRL_DONEEO_Pos)) /* Assigment of value for DONEEO in the FREQM_EVCTRL register */
#define FREQM_EVCTRL_WINMONEO_Pos             _UINT8_(5)                                           /* (FREQM_EVCTRL) Window Monitor Event Out Position */
#define FREQM_EVCTRL_WINMONEO_Msk             (_UINT8_(0x1) << FREQM_EVCTRL_WINMONEO_Pos)          /* (FREQM_EVCTRL) Window Monitor Event Out Mask */
#define FREQM_EVCTRL_WINMONEO(value)          (FREQM_EVCTRL_WINMONEO_Msk & (_UINT8_(value) << FREQM_EVCTRL_WINMONEO_Pos)) /* Assigment of value for WINMONEO in the FREQM_EVCTRL register */
#define FREQM_EVCTRL_Msk                      _UINT8_(0x33)                                        /* (FREQM_EVCTRL) Register Mask  */


/* -------- FREQM_INTENCLR : (FREQM Offset: 0x08) (R/W 8) Interrupt Enable Clear Register -------- */
#define FREQM_INTENCLR_RESETVALUE             _UINT8_(0x00)                                        /*  (FREQM_INTENCLR) Interrupt Enable Clear Register  Reset Value */

#define FREQM_INTENCLR_DONE_Pos               _UINT8_(0)                                           /* (FREQM_INTENCLR) Measurement Done Interrupt Disable Position */
#define FREQM_INTENCLR_DONE_Msk               (_UINT8_(0x1) << FREQM_INTENCLR_DONE_Pos)            /* (FREQM_INTENCLR) Measurement Done Interrupt Disable Mask */
#define FREQM_INTENCLR_DONE(value)            (FREQM_INTENCLR_DONE_Msk & (_UINT8_(value) << FREQM_INTENCLR_DONE_Pos)) /* Assigment of value for DONE in the FREQM_INTENCLR register */
#define FREQM_INTENCLR_WINMON_Pos             _UINT8_(1)                                           /* (FREQM_INTENCLR) Window Monitor Interrupt Disable Position */
#define FREQM_INTENCLR_WINMON_Msk             (_UINT8_(0x1) << FREQM_INTENCLR_WINMON_Pos)          /* (FREQM_INTENCLR) Window Monitor Interrupt Disable Mask */
#define FREQM_INTENCLR_WINMON(value)          (FREQM_INTENCLR_WINMON_Msk & (_UINT8_(value) << FREQM_INTENCLR_WINMON_Pos)) /* Assigment of value for WINMON in the FREQM_INTENCLR register */
#define FREQM_INTENCLR_Msk                    _UINT8_(0x03)                                        /* (FREQM_INTENCLR) Register Mask  */


/* -------- FREQM_INTENSET : (FREQM Offset: 0x09) (R/W 8) Interrupt Enable Set Register -------- */
#define FREQM_INTENSET_RESETVALUE             _UINT8_(0x00)                                        /*  (FREQM_INTENSET) Interrupt Enable Set Register  Reset Value */

#define FREQM_INTENSET_DONE_Pos               _UINT8_(0)                                           /* (FREQM_INTENSET) Measurement Done Interrupt Enable Position */
#define FREQM_INTENSET_DONE_Msk               (_UINT8_(0x1) << FREQM_INTENSET_DONE_Pos)            /* (FREQM_INTENSET) Measurement Done Interrupt Enable Mask */
#define FREQM_INTENSET_DONE(value)            (FREQM_INTENSET_DONE_Msk & (_UINT8_(value) << FREQM_INTENSET_DONE_Pos)) /* Assigment of value for DONE in the FREQM_INTENSET register */
#define FREQM_INTENSET_WINMON_Pos             _UINT8_(1)                                           /* (FREQM_INTENSET) Window Monitor Interrupt Enable Position */
#define FREQM_INTENSET_WINMON_Msk             (_UINT8_(0x1) << FREQM_INTENSET_WINMON_Pos)          /* (FREQM_INTENSET) Window Monitor Interrupt Enable Mask */
#define FREQM_INTENSET_WINMON(value)          (FREQM_INTENSET_WINMON_Msk & (_UINT8_(value) << FREQM_INTENSET_WINMON_Pos)) /* Assigment of value for WINMON in the FREQM_INTENSET register */
#define FREQM_INTENSET_Msk                    _UINT8_(0x03)                                        /* (FREQM_INTENSET) Register Mask  */


/* -------- FREQM_INTFLAG : (FREQM Offset: 0x0A) (R/W 8) Interrupt Flag Register -------- */
#define FREQM_INTFLAG_RESETVALUE              _UINT8_(0x00)                                        /*  (FREQM_INTFLAG) Interrupt Flag Register  Reset Value */

#define FREQM_INTFLAG_DONE_Pos                _UINT8_(0)                                           /* (FREQM_INTFLAG) Measurement Done Position */
#define FREQM_INTFLAG_DONE_Msk                (_UINT8_(0x1) << FREQM_INTFLAG_DONE_Pos)             /* (FREQM_INTFLAG) Measurement Done Mask */
#define FREQM_INTFLAG_DONE(value)             (FREQM_INTFLAG_DONE_Msk & (_UINT8_(value) << FREQM_INTFLAG_DONE_Pos)) /* Assigment of value for DONE in the FREQM_INTFLAG register */
#define FREQM_INTFLAG_WINMON_Pos              _UINT8_(1)                                           /* (FREQM_INTFLAG) Window Monitor Position */
#define FREQM_INTFLAG_WINMON_Msk              (_UINT8_(0x1) << FREQM_INTFLAG_WINMON_Pos)           /* (FREQM_INTFLAG) Window Monitor Mask */
#define FREQM_INTFLAG_WINMON(value)           (FREQM_INTFLAG_WINMON_Msk & (_UINT8_(value) << FREQM_INTFLAG_WINMON_Pos)) /* Assigment of value for WINMON in the FREQM_INTFLAG register */
#define FREQM_INTFLAG_Msk                     _UINT8_(0x03)                                        /* (FREQM_INTFLAG) Register Mask  */


/* -------- FREQM_STATUS : (FREQM Offset: 0x0B) (R/W 8) Status Register -------- */
#define FREQM_STATUS_RESETVALUE               _UINT8_(0x00)                                        /*  (FREQM_STATUS) Status Register  Reset Value */

#define FREQM_STATUS_BUSY_Pos                 _UINT8_(0)                                           /* (FREQM_STATUS) FREQM Status Position */
#define FREQM_STATUS_BUSY_Msk                 (_UINT8_(0x1) << FREQM_STATUS_BUSY_Pos)              /* (FREQM_STATUS) FREQM Status Mask */
#define FREQM_STATUS_BUSY(value)              (FREQM_STATUS_BUSY_Msk & (_UINT8_(value) << FREQM_STATUS_BUSY_Pos)) /* Assigment of value for BUSY in the FREQM_STATUS register */
#define FREQM_STATUS_OVF_Pos                  _UINT8_(1)                                           /* (FREQM_STATUS) Sticky Count Value Overflow Position */
#define FREQM_STATUS_OVF_Msk                  (_UINT8_(0x1) << FREQM_STATUS_OVF_Pos)               /* (FREQM_STATUS) Sticky Count Value Overflow Mask */
#define FREQM_STATUS_OVF(value)               (FREQM_STATUS_OVF_Msk & (_UINT8_(value) << FREQM_STATUS_OVF_Pos)) /* Assigment of value for OVF in the FREQM_STATUS register */
#define FREQM_STATUS_Msk                      _UINT8_(0x03)                                        /* (FREQM_STATUS) Register Mask  */


/* -------- FREQM_SYNCBUSY : (FREQM Offset: 0x0C) ( R/ 32) Synchronization Busy Register -------- */
#define FREQM_SYNCBUSY_RESETVALUE             _UINT32_(0x00)                                       /*  (FREQM_SYNCBUSY) Synchronization Busy Register  Reset Value */

#define FREQM_SYNCBUSY_SWRST_Pos              _UINT32_(0)                                          /* (FREQM_SYNCBUSY) Software Reset Position */
#define FREQM_SYNCBUSY_SWRST_Msk              (_UINT32_(0x1) << FREQM_SYNCBUSY_SWRST_Pos)          /* (FREQM_SYNCBUSY) Software Reset Mask */
#define FREQM_SYNCBUSY_SWRST(value)           (FREQM_SYNCBUSY_SWRST_Msk & (_UINT32_(value) << FREQM_SYNCBUSY_SWRST_Pos)) /* Assigment of value for SWRST in the FREQM_SYNCBUSY register */
#define FREQM_SYNCBUSY_ENABLE_Pos             _UINT32_(1)                                          /* (FREQM_SYNCBUSY) Enable Position */
#define FREQM_SYNCBUSY_ENABLE_Msk             (_UINT32_(0x1) << FREQM_SYNCBUSY_ENABLE_Pos)         /* (FREQM_SYNCBUSY) Enable Mask */
#define FREQM_SYNCBUSY_ENABLE(value)          (FREQM_SYNCBUSY_ENABLE_Msk & (_UINT32_(value) << FREQM_SYNCBUSY_ENABLE_Pos)) /* Assigment of value for ENABLE in the FREQM_SYNCBUSY register */
#define FREQM_SYNCBUSY_Msk                    _UINT32_(0x00000003)                                 /* (FREQM_SYNCBUSY) Register Mask  */


/* -------- FREQM_VALUE : (FREQM Offset: 0x10) ( R/ 32) Count Value Register -------- */
#define FREQM_VALUE_RESETVALUE                _UINT32_(0x00)                                       /*  (FREQM_VALUE) Count Value Register  Reset Value */

#define FREQM_VALUE_VALUE_Pos                 _UINT32_(0)                                          /* (FREQM_VALUE) Measurement Value Position */
#define FREQM_VALUE_VALUE_Msk                 (_UINT32_(0xFFFFFF) << FREQM_VALUE_VALUE_Pos)        /* (FREQM_VALUE) Measurement Value Mask */
#define FREQM_VALUE_VALUE(value)              (FREQM_VALUE_VALUE_Msk & (_UINT32_(value) << FREQM_VALUE_VALUE_Pos)) /* Assigment of value for VALUE in the FREQM_VALUE register */
#define FREQM_VALUE_Msk                       _UINT32_(0x00FFFFFF)                                 /* (FREQM_VALUE) Register Mask  */


/* -------- FREQM_WINLT : (FREQM Offset: 0x20) (R/W 32) Window Monitor Lower Threshold -------- */
#define FREQM_WINLT_RESETVALUE                _UINT32_(0x00)                                       /*  (FREQM_WINLT) Window Monitor Lower Threshold  Reset Value */

#define FREQM_WINLT_WINLT_Pos                 _UINT32_(0)                                          /* (FREQM_WINLT) Window Lower Threshold Position */
#define FREQM_WINLT_WINLT_Msk                 (_UINT32_(0xFFFFFF) << FREQM_WINLT_WINLT_Pos)        /* (FREQM_WINLT) Window Lower Threshold Mask */
#define FREQM_WINLT_WINLT(value)              (FREQM_WINLT_WINLT_Msk & (_UINT32_(value) << FREQM_WINLT_WINLT_Pos)) /* Assigment of value for WINLT in the FREQM_WINLT register */
#define FREQM_WINLT_Msk                       _UINT32_(0x00FFFFFF)                                 /* (FREQM_WINLT) Register Mask  */


/* -------- FREQM_WINUT : (FREQM Offset: 0x24) (R/W 32) Window Monitor Upper Threshold -------- */
#define FREQM_WINUT_RESETVALUE                _UINT32_(0x00)                                       /*  (FREQM_WINUT) Window Monitor Upper Threshold  Reset Value */

#define FREQM_WINUT_WINUT_Pos                 _UINT32_(0)                                          /* (FREQM_WINUT) Window Upper Threshold Position */
#define FREQM_WINUT_WINUT_Msk                 (_UINT32_(0xFFFFFF) << FREQM_WINUT_WINUT_Pos)        /* (FREQM_WINUT) Window Upper Threshold Mask */
#define FREQM_WINUT_WINUT(value)              (FREQM_WINUT_WINUT_Msk & (_UINT32_(value) << FREQM_WINUT_WINUT_Pos)) /* Assigment of value for WINUT in the FREQM_WINUT register */
#define FREQM_WINUT_Msk                       _UINT32_(0x00FFFFFF)                                 /* (FREQM_WINUT) Register Mask  */


/** \brief FREQM register offsets definitions */
#define FREQM_CTRLA_REG_OFST           _UINT32_(0x00)      /* (FREQM_CTRLA) Control A Register Offset */
#define FREQM_CTRLB_REG_OFST           _UINT32_(0x01)      /* (FREQM_CTRLB) Control B Register Offset */
#define FREQM_CFGA_REG_OFST            _UINT32_(0x02)      /* (FREQM_CFGA) Config A Register Offset */
#define FREQM_CTRLC_REG_OFST           _UINT32_(0x04)      /* (FREQM_CTRLC) Control C Register Offset */
#define FREQM_EVCTRL_REG_OFST          _UINT32_(0x06)      /* (FREQM_EVCTRL) Event Control Register Offset */
#define FREQM_INTENCLR_REG_OFST        _UINT32_(0x08)      /* (FREQM_INTENCLR) Interrupt Enable Clear Register Offset */
#define FREQM_INTENSET_REG_OFST        _UINT32_(0x09)      /* (FREQM_INTENSET) Interrupt Enable Set Register Offset */
#define FREQM_INTFLAG_REG_OFST         _UINT32_(0x0A)      /* (FREQM_INTFLAG) Interrupt Flag Register Offset */
#define FREQM_STATUS_REG_OFST          _UINT32_(0x0B)      /* (FREQM_STATUS) Status Register Offset */
#define FREQM_SYNCBUSY_REG_OFST        _UINT32_(0x0C)      /* (FREQM_SYNCBUSY) Synchronization Busy Register Offset */
#define FREQM_VALUE_REG_OFST           _UINT32_(0x10)      /* (FREQM_VALUE) Count Value Register Offset */
#define FREQM_WINLT_REG_OFST           _UINT32_(0x20)      /* (FREQM_WINLT) Window Monitor Lower Threshold Offset */
#define FREQM_WINUT_REG_OFST           _UINT32_(0x24)      /* (FREQM_WINUT) Window Monitor Upper Threshold Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief FREQM register API structure */
typedef struct
{  /* Frequency Meter */
  __IO  uint8_t                        FREQM_CTRLA;        /**< Offset: 0x00 (R/W  8) Control A Register */
  __O   uint8_t                        FREQM_CTRLB;        /**< Offset: 0x01 ( /W  8) Control B Register */
  __IO  uint16_t                       FREQM_CFGA;         /**< Offset: 0x02 (R/W  16) Config A Register */
  __IO  uint8_t                        FREQM_CTRLC;        /**< Offset: 0x04 (R/W  8) Control C Register */
  __I   uint8_t                        Reserved1[0x01];
  __IO  uint8_t                        FREQM_EVCTRL;       /**< Offset: 0x06 (R/W  8) Event Control Register */
  __I   uint8_t                        Reserved2[0x01];
  __IO  uint8_t                        FREQM_INTENCLR;     /**< Offset: 0x08 (R/W  8) Interrupt Enable Clear Register */
  __IO  uint8_t                        FREQM_INTENSET;     /**< Offset: 0x09 (R/W  8) Interrupt Enable Set Register */
  __IO  uint8_t                        FREQM_INTFLAG;      /**< Offset: 0x0A (R/W  8) Interrupt Flag Register */
  __IO  uint8_t                        FREQM_STATUS;       /**< Offset: 0x0B (R/W  8) Status Register */
  __I   uint32_t                       FREQM_SYNCBUSY;     /**< Offset: 0x0C (R/   32) Synchronization Busy Register */
  __I   uint32_t                       FREQM_VALUE;        /**< Offset: 0x10 (R/   32) Count Value Register */
  __I   uint8_t                        Reserved3[0x0C];
  __IO  uint32_t                       FREQM_WINLT;        /**< Offset: 0x20 (R/W  32) Window Monitor Lower Threshold */
  __IO  uint32_t                       FREQM_WINUT;        /**< Offset: 0x24 (R/W  32) Window Monitor Upper Threshold */
} freqm_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA90_FREQM_COMPONENT_H_ */
