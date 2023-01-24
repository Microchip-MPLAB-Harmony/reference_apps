/*
 * Component description for AC
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
#ifndef _PIC32CZCA80_AC_COMPONENT_H_
#define _PIC32CZCA80_AC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR AC                                           */
/* ************************************************************************** */

/* -------- AC_CTRLA : (AC Offset: 0x00) (R/W 32) Control A -------- */
#define AC_CTRLA_RESETVALUE                   _UINT32_(0x00)                                       /*  (AC_CTRLA) Control A  Reset Value */

#define AC_CTRLA_SWRST_Pos                    _UINT32_(0)                                          /* (AC_CTRLA) Software Reset Position */
#define AC_CTRLA_SWRST_Msk                    (_UINT32_(0x1) << AC_CTRLA_SWRST_Pos)                /* (AC_CTRLA) Software Reset Mask */
#define AC_CTRLA_SWRST(value)                 (AC_CTRLA_SWRST_Msk & (_UINT32_(value) << AC_CTRLA_SWRST_Pos)) /* Assigment of value for SWRST in the AC_CTRLA register */
#define AC_CTRLA_ENABLE_Pos                   _UINT32_(1)                                          /* (AC_CTRLA) Enable Position */
#define AC_CTRLA_ENABLE_Msk                   (_UINT32_(0x1) << AC_CTRLA_ENABLE_Pos)               /* (AC_CTRLA) Enable Mask */
#define AC_CTRLA_ENABLE(value)                (AC_CTRLA_ENABLE_Msk & (_UINT32_(value) << AC_CTRLA_ENABLE_Pos)) /* Assigment of value for ENABLE in the AC_CTRLA register */
#define AC_CTRLA_Msk                          _UINT32_(0x00000003)                                 /* (AC_CTRLA) Register Mask  */


/* -------- AC_CTRLB : (AC Offset: 0x04) (R/W 32) Control B -------- */
#define AC_CTRLB_RESETVALUE                   _UINT32_(0x00)                                       /*  (AC_CTRLB) Control B  Reset Value */

#define AC_CTRLB_START0_Pos                   _UINT32_(0)                                          /* (AC_CTRLB) Comparator 0 Start Comparison Position */
#define AC_CTRLB_START0_Msk                   (_UINT32_(0x1) << AC_CTRLB_START0_Pos)               /* (AC_CTRLB) Comparator 0 Start Comparison Mask */
#define AC_CTRLB_START0(value)                (AC_CTRLB_START0_Msk & (_UINT32_(value) << AC_CTRLB_START0_Pos)) /* Assigment of value for START0 in the AC_CTRLB register */
#define AC_CTRLB_START1_Pos                   _UINT32_(1)                                          /* (AC_CTRLB) Comparator 1 Start Comparison Position */
#define AC_CTRLB_START1_Msk                   (_UINT32_(0x1) << AC_CTRLB_START1_Pos)               /* (AC_CTRLB) Comparator 1 Start Comparison Mask */
#define AC_CTRLB_START1(value)                (AC_CTRLB_START1_Msk & (_UINT32_(value) << AC_CTRLB_START1_Pos)) /* Assigment of value for START1 in the AC_CTRLB register */
#define AC_CTRLB_Msk                          _UINT32_(0x00000003)                                 /* (AC_CTRLB) Register Mask  */

#define AC_CTRLB_START_Pos                    _UINT32_(0)                                          /* (AC_CTRLB Position) Comparator x Start Comparison */
#define AC_CTRLB_START_Msk                    (_UINT32_(0x3) << AC_CTRLB_START_Pos)                /* (AC_CTRLB Mask) START */
#define AC_CTRLB_START(value)                 (AC_CTRLB_START_Msk & (_UINT32_(value) << AC_CTRLB_START_Pos)) 

/* -------- AC_CTRLC : (AC Offset: 0x08) (R/W 32) Control C -------- */
#define AC_CTRLC_RESETVALUE                   _UINT32_(0x00)                                       /*  (AC_CTRLC) Control C  Reset Value */

#define AC_CTRLC_WIDTH_Pos                    _UINT32_(0)                                          /* (AC_CTRLC) Sample and Hold Clock Pulse Width Position */
#define AC_CTRLC_WIDTH_Msk                    (_UINT32_(0x3FF) << AC_CTRLC_WIDTH_Pos)              /* (AC_CTRLC) Sample and Hold Clock Pulse Width Mask */
#define AC_CTRLC_WIDTH(value)                 (AC_CTRLC_WIDTH_Msk & (_UINT32_(value) << AC_CTRLC_WIDTH_Pos)) /* Assigment of value for WIDTH in the AC_CTRLC register */
#define AC_CTRLC_PER_Pos                      _UINT32_(12)                                         /* (AC_CTRLC) Sample and Hold Clock Period Position */
#define AC_CTRLC_PER_Msk                      (_UINT32_(0x3FF) << AC_CTRLC_PER_Pos)                /* (AC_CTRLC) Sample and Hold Clock Period Mask */
#define AC_CTRLC_PER(value)                   (AC_CTRLC_PER_Msk & (_UINT32_(value) << AC_CTRLC_PER_Pos)) /* Assigment of value for PER in the AC_CTRLC register */
#define AC_CTRLC_PRESCALER_Pos                _UINT32_(24)                                         /* (AC_CTRLC) Prescaling Factor Position */
#define AC_CTRLC_PRESCALER_Msk                (_UINT32_(0x7) << AC_CTRLC_PRESCALER_Pos)            /* (AC_CTRLC) Prescaling Factor Mask */
#define AC_CTRLC_PRESCALER(value)             (AC_CTRLC_PRESCALER_Msk & (_UINT32_(value) << AC_CTRLC_PRESCALER_Pos)) /* Assigment of value for PRESCALER in the AC_CTRLC register */
#define   AC_CTRLC_PRESCALER_DIV1_Val         _UINT32_(0x0)                                        /* (AC_CTRLC) Sampling rate is GCLK_AC (No division)  */
#define   AC_CTRLC_PRESCALER_DIV2_Val         _UINT32_(0x1)                                        /* (AC_CTRLC) Sampling rate is GCLK_AC/2  */
#define   AC_CTRLC_PRESCALER_DIV4_Val         _UINT32_(0x2)                                        /* (AC_CTRLC) Sampling rate is GCLK_AC/4  */
#define   AC_CTRLC_PRESCALER_DIV8_Val         _UINT32_(0x3)                                        /* (AC_CTRLC) Sampling rate is GCLK_AC/8  */
#define   AC_CTRLC_PRESCALER_DIV16_Val        _UINT32_(0x4)                                        /* (AC_CTRLC) Sampling rate is GCLK_AC/16  */
#define   AC_CTRLC_PRESCALER_DIV32_Val        _UINT32_(0x5)                                        /* (AC_CTRLC) Sampling rate is GCLK_AC/32  */
#define   AC_CTRLC_PRESCALER_DIV64_Val        _UINT32_(0x6)                                        /* (AC_CTRLC) Sampling rate is GCLK_AC/64  */
#define   AC_CTRLC_PRESCALER_DIV128_Val       _UINT32_(0x7)                                        /* (AC_CTRLC) Sampling rate is GCLK_AC/128  */
#define AC_CTRLC_PRESCALER_DIV1               (AC_CTRLC_PRESCALER_DIV1_Val << AC_CTRLC_PRESCALER_Pos) /* (AC_CTRLC) Sampling rate is GCLK_AC (No division) Position  */
#define AC_CTRLC_PRESCALER_DIV2               (AC_CTRLC_PRESCALER_DIV2_Val << AC_CTRLC_PRESCALER_Pos) /* (AC_CTRLC) Sampling rate is GCLK_AC/2 Position  */
#define AC_CTRLC_PRESCALER_DIV4               (AC_CTRLC_PRESCALER_DIV4_Val << AC_CTRLC_PRESCALER_Pos) /* (AC_CTRLC) Sampling rate is GCLK_AC/4 Position  */
#define AC_CTRLC_PRESCALER_DIV8               (AC_CTRLC_PRESCALER_DIV8_Val << AC_CTRLC_PRESCALER_Pos) /* (AC_CTRLC) Sampling rate is GCLK_AC/8 Position  */
#define AC_CTRLC_PRESCALER_DIV16              (AC_CTRLC_PRESCALER_DIV16_Val << AC_CTRLC_PRESCALER_Pos) /* (AC_CTRLC) Sampling rate is GCLK_AC/16 Position  */
#define AC_CTRLC_PRESCALER_DIV32              (AC_CTRLC_PRESCALER_DIV32_Val << AC_CTRLC_PRESCALER_Pos) /* (AC_CTRLC) Sampling rate is GCLK_AC/32 Position  */
#define AC_CTRLC_PRESCALER_DIV64              (AC_CTRLC_PRESCALER_DIV64_Val << AC_CTRLC_PRESCALER_Pos) /* (AC_CTRLC) Sampling rate is GCLK_AC/64 Position  */
#define AC_CTRLC_PRESCALER_DIV128             (AC_CTRLC_PRESCALER_DIV128_Val << AC_CTRLC_PRESCALER_Pos) /* (AC_CTRLC) Sampling rate is GCLK_AC/128 Position  */
#define AC_CTRLC_AIPMPEN_Pos                  _UINT32_(27)                                         /* (AC_CTRLC) Analog Input Charge Pump Enable Position */
#define AC_CTRLC_AIPMPEN_Msk                  (_UINT32_(0x1) << AC_CTRLC_AIPMPEN_Pos)              /* (AC_CTRLC) Analog Input Charge Pump Enable Mask */
#define AC_CTRLC_AIPMPEN(value)               (AC_CTRLC_AIPMPEN_Msk & (_UINT32_(value) << AC_CTRLC_AIPMPEN_Pos)) /* Assigment of value for AIPMPEN in the AC_CTRLC register */
#define AC_CTRLC_CONFIG_Pos                   _UINT32_(28)                                         /* (AC_CTRLC) Configuration Extension Position */
#define AC_CTRLC_CONFIG_Msk                   (_UINT32_(0xF) << AC_CTRLC_CONFIG_Pos)               /* (AC_CTRLC) Configuration Extension Mask */
#define AC_CTRLC_CONFIG(value)                (AC_CTRLC_CONFIG_Msk & (_UINT32_(value) << AC_CTRLC_CONFIG_Pos)) /* Assigment of value for CONFIG in the AC_CTRLC register */
#define AC_CTRLC_Msk                          _UINT32_(0xFF3FF3FF)                                 /* (AC_CTRLC) Register Mask  */


/* -------- AC_EVCTRL : (AC Offset: 0x0C) (R/W 32) Event Control -------- */
#define AC_EVCTRL_RESETVALUE                  _UINT32_(0x00)                                       /*  (AC_EVCTRL) Event Control  Reset Value */

#define AC_EVCTRL_COMPEO0_Pos                 _UINT32_(0)                                          /* (AC_EVCTRL) Comparator 0 Event Output Enable Position */
#define AC_EVCTRL_COMPEO0_Msk                 (_UINT32_(0x1) << AC_EVCTRL_COMPEO0_Pos)             /* (AC_EVCTRL) Comparator 0 Event Output Enable Mask */
#define AC_EVCTRL_COMPEO0(value)              (AC_EVCTRL_COMPEO0_Msk & (_UINT32_(value) << AC_EVCTRL_COMPEO0_Pos)) /* Assigment of value for COMPEO0 in the AC_EVCTRL register */
#define AC_EVCTRL_COMPEO1_Pos                 _UINT32_(1)                                          /* (AC_EVCTRL) Comparator 1 Event Output Enable Position */
#define AC_EVCTRL_COMPEO1_Msk                 (_UINT32_(0x1) << AC_EVCTRL_COMPEO1_Pos)             /* (AC_EVCTRL) Comparator 1 Event Output Enable Mask */
#define AC_EVCTRL_COMPEO1(value)              (AC_EVCTRL_COMPEO1_Msk & (_UINT32_(value) << AC_EVCTRL_COMPEO1_Pos)) /* Assigment of value for COMPEO1 in the AC_EVCTRL register */
#define AC_EVCTRL_WINEO0_Pos                  _UINT32_(8)                                          /* (AC_EVCTRL) Window 0 Event Output Enable Position */
#define AC_EVCTRL_WINEO0_Msk                  (_UINT32_(0x1) << AC_EVCTRL_WINEO0_Pos)              /* (AC_EVCTRL) Window 0 Event Output Enable Mask */
#define AC_EVCTRL_WINEO0(value)               (AC_EVCTRL_WINEO0_Msk & (_UINT32_(value) << AC_EVCTRL_WINEO0_Pos)) /* Assigment of value for WINEO0 in the AC_EVCTRL register */
#define AC_EVCTRL_COMPEI0_Pos                 _UINT32_(16)                                         /* (AC_EVCTRL) Comparator 0 Event Input Enable Position */
#define AC_EVCTRL_COMPEI0_Msk                 (_UINT32_(0x1) << AC_EVCTRL_COMPEI0_Pos)             /* (AC_EVCTRL) Comparator 0 Event Input Enable Mask */
#define AC_EVCTRL_COMPEI0(value)              (AC_EVCTRL_COMPEI0_Msk & (_UINT32_(value) << AC_EVCTRL_COMPEI0_Pos)) /* Assigment of value for COMPEI0 in the AC_EVCTRL register */
#define AC_EVCTRL_COMPEI1_Pos                 _UINT32_(17)                                         /* (AC_EVCTRL) Comparator 1 Event Input Enable Position */
#define AC_EVCTRL_COMPEI1_Msk                 (_UINT32_(0x1) << AC_EVCTRL_COMPEI1_Pos)             /* (AC_EVCTRL) Comparator 1 Event Input Enable Mask */
#define AC_EVCTRL_COMPEI1(value)              (AC_EVCTRL_COMPEI1_Msk & (_UINT32_(value) << AC_EVCTRL_COMPEI1_Pos)) /* Assigment of value for COMPEI1 in the AC_EVCTRL register */
#define AC_EVCTRL_INVEI0_Pos                  _UINT32_(24)                                         /* (AC_EVCTRL) Inverted Event Input Enable 0 Position */
#define AC_EVCTRL_INVEI0_Msk                  (_UINT32_(0x1) << AC_EVCTRL_INVEI0_Pos)              /* (AC_EVCTRL) Inverted Event Input Enable 0 Mask */
#define AC_EVCTRL_INVEI0(value)               (AC_EVCTRL_INVEI0_Msk & (_UINT32_(value) << AC_EVCTRL_INVEI0_Pos)) /* Assigment of value for INVEI0 in the AC_EVCTRL register */
#define AC_EVCTRL_INVEI1_Pos                  _UINT32_(25)                                         /* (AC_EVCTRL) Inverted Event Input Enable 1 Position */
#define AC_EVCTRL_INVEI1_Msk                  (_UINT32_(0x1) << AC_EVCTRL_INVEI1_Pos)              /* (AC_EVCTRL) Inverted Event Input Enable 1 Mask */
#define AC_EVCTRL_INVEI1(value)               (AC_EVCTRL_INVEI1_Msk & (_UINT32_(value) << AC_EVCTRL_INVEI1_Pos)) /* Assigment of value for INVEI1 in the AC_EVCTRL register */
#define AC_EVCTRL_Msk                         _UINT32_(0x03030103)                                 /* (AC_EVCTRL) Register Mask  */

#define AC_EVCTRL_COMPEO_Pos                  _UINT32_(0)                                          /* (AC_EVCTRL Position) Comparator x Event Output Enable */
#define AC_EVCTRL_COMPEO_Msk                  (_UINT32_(0x3) << AC_EVCTRL_COMPEO_Pos)              /* (AC_EVCTRL Mask) COMPEO */
#define AC_EVCTRL_COMPEO(value)               (AC_EVCTRL_COMPEO_Msk & (_UINT32_(value) << AC_EVCTRL_COMPEO_Pos)) 
#define AC_EVCTRL_WINEO_Pos                   _UINT32_(8)                                          /* (AC_EVCTRL Position) Window x Event Output Enable */
#define AC_EVCTRL_WINEO_Msk                   (_UINT32_(0x1) << AC_EVCTRL_WINEO_Pos)               /* (AC_EVCTRL Mask) WINEO */
#define AC_EVCTRL_WINEO(value)                (AC_EVCTRL_WINEO_Msk & (_UINT32_(value) << AC_EVCTRL_WINEO_Pos)) 
#define AC_EVCTRL_COMPEI_Pos                  _UINT32_(16)                                         /* (AC_EVCTRL Position) Comparator x Event Input Enable */
#define AC_EVCTRL_COMPEI_Msk                  (_UINT32_(0x3) << AC_EVCTRL_COMPEI_Pos)              /* (AC_EVCTRL Mask) COMPEI */
#define AC_EVCTRL_COMPEI(value)               (AC_EVCTRL_COMPEI_Msk & (_UINT32_(value) << AC_EVCTRL_COMPEI_Pos)) 
#define AC_EVCTRL_INVEI_Pos                   _UINT32_(24)                                         /* (AC_EVCTRL Position) Inverted Event Input Enable x */
#define AC_EVCTRL_INVEI_Msk                   (_UINT32_(0x3) << AC_EVCTRL_INVEI_Pos)               /* (AC_EVCTRL Mask) INVEI */
#define AC_EVCTRL_INVEI(value)                (AC_EVCTRL_INVEI_Msk & (_UINT32_(value) << AC_EVCTRL_INVEI_Pos)) 

/* -------- AC_INTENCLR : (AC Offset: 0x10) (R/W 32) Interrupt Enable Clear -------- */
#define AC_INTENCLR_RESETVALUE                _UINT32_(0x00)                                       /*  (AC_INTENCLR) Interrupt Enable Clear  Reset Value */

#define AC_INTENCLR_COMP0_Pos                 _UINT32_(0)                                          /* (AC_INTENCLR) Comparator 0 Interrupt Enable Position */
#define AC_INTENCLR_COMP0_Msk                 (_UINT32_(0x1) << AC_INTENCLR_COMP0_Pos)             /* (AC_INTENCLR) Comparator 0 Interrupt Enable Mask */
#define AC_INTENCLR_COMP0(value)              (AC_INTENCLR_COMP0_Msk & (_UINT32_(value) << AC_INTENCLR_COMP0_Pos)) /* Assigment of value for COMP0 in the AC_INTENCLR register */
#define AC_INTENCLR_COMP1_Pos                 _UINT32_(1)                                          /* (AC_INTENCLR) Comparator 1 Interrupt Enable Position */
#define AC_INTENCLR_COMP1_Msk                 (_UINT32_(0x1) << AC_INTENCLR_COMP1_Pos)             /* (AC_INTENCLR) Comparator 1 Interrupt Enable Mask */
#define AC_INTENCLR_COMP1(value)              (AC_INTENCLR_COMP1_Msk & (_UINT32_(value) << AC_INTENCLR_COMP1_Pos)) /* Assigment of value for COMP1 in the AC_INTENCLR register */
#define AC_INTENCLR_WIN0_Pos                  _UINT32_(8)                                          /* (AC_INTENCLR) Window 0 Interrupt Enable Position */
#define AC_INTENCLR_WIN0_Msk                  (_UINT32_(0x1) << AC_INTENCLR_WIN0_Pos)              /* (AC_INTENCLR) Window 0 Interrupt Enable Mask */
#define AC_INTENCLR_WIN0(value)               (AC_INTENCLR_WIN0_Msk & (_UINT32_(value) << AC_INTENCLR_WIN0_Pos)) /* Assigment of value for WIN0 in the AC_INTENCLR register */
#define AC_INTENCLR_Msk                       _UINT32_(0x00000103)                                 /* (AC_INTENCLR) Register Mask  */

#define AC_INTENCLR_COMP_Pos                  _UINT32_(0)                                          /* (AC_INTENCLR Position) Comparator x Interrupt Enable */
#define AC_INTENCLR_COMP_Msk                  (_UINT32_(0x3) << AC_INTENCLR_COMP_Pos)              /* (AC_INTENCLR Mask) COMP */
#define AC_INTENCLR_COMP(value)               (AC_INTENCLR_COMP_Msk & (_UINT32_(value) << AC_INTENCLR_COMP_Pos)) 
#define AC_INTENCLR_WIN_Pos                   _UINT32_(8)                                          /* (AC_INTENCLR Position) Window x Interrupt Enable */
#define AC_INTENCLR_WIN_Msk                   (_UINT32_(0x1) << AC_INTENCLR_WIN_Pos)               /* (AC_INTENCLR Mask) WIN */
#define AC_INTENCLR_WIN(value)                (AC_INTENCLR_WIN_Msk & (_UINT32_(value) << AC_INTENCLR_WIN_Pos)) 

/* -------- AC_INTENSET : (AC Offset: 0x14) (R/W 32) Interrupt Enable Set -------- */
#define AC_INTENSET_RESETVALUE                _UINT32_(0x00)                                       /*  (AC_INTENSET) Interrupt Enable Set  Reset Value */

#define AC_INTENSET_COMP0_Pos                 _UINT32_(0)                                          /* (AC_INTENSET) Comparator 0 Interrupt Enable Position */
#define AC_INTENSET_COMP0_Msk                 (_UINT32_(0x1) << AC_INTENSET_COMP0_Pos)             /* (AC_INTENSET) Comparator 0 Interrupt Enable Mask */
#define AC_INTENSET_COMP0(value)              (AC_INTENSET_COMP0_Msk & (_UINT32_(value) << AC_INTENSET_COMP0_Pos)) /* Assigment of value for COMP0 in the AC_INTENSET register */
#define AC_INTENSET_COMP1_Pos                 _UINT32_(1)                                          /* (AC_INTENSET) Comparator 1 Interrupt Enable Position */
#define AC_INTENSET_COMP1_Msk                 (_UINT32_(0x1) << AC_INTENSET_COMP1_Pos)             /* (AC_INTENSET) Comparator 1 Interrupt Enable Mask */
#define AC_INTENSET_COMP1(value)              (AC_INTENSET_COMP1_Msk & (_UINT32_(value) << AC_INTENSET_COMP1_Pos)) /* Assigment of value for COMP1 in the AC_INTENSET register */
#define AC_INTENSET_WIN0_Pos                  _UINT32_(8)                                          /* (AC_INTENSET) Window 0 Interrupt Enable Position */
#define AC_INTENSET_WIN0_Msk                  (_UINT32_(0x1) << AC_INTENSET_WIN0_Pos)              /* (AC_INTENSET) Window 0 Interrupt Enable Mask */
#define AC_INTENSET_WIN0(value)               (AC_INTENSET_WIN0_Msk & (_UINT32_(value) << AC_INTENSET_WIN0_Pos)) /* Assigment of value for WIN0 in the AC_INTENSET register */
#define AC_INTENSET_Msk                       _UINT32_(0x00000103)                                 /* (AC_INTENSET) Register Mask  */

#define AC_INTENSET_COMP_Pos                  _UINT32_(0)                                          /* (AC_INTENSET Position) Comparator x Interrupt Enable */
#define AC_INTENSET_COMP_Msk                  (_UINT32_(0x3) << AC_INTENSET_COMP_Pos)              /* (AC_INTENSET Mask) COMP */
#define AC_INTENSET_COMP(value)               (AC_INTENSET_COMP_Msk & (_UINT32_(value) << AC_INTENSET_COMP_Pos)) 
#define AC_INTENSET_WIN_Pos                   _UINT32_(8)                                          /* (AC_INTENSET Position) Window x Interrupt Enable */
#define AC_INTENSET_WIN_Msk                   (_UINT32_(0x1) << AC_INTENSET_WIN_Pos)               /* (AC_INTENSET Mask) WIN */
#define AC_INTENSET_WIN(value)                (AC_INTENSET_WIN_Msk & (_UINT32_(value) << AC_INTENSET_WIN_Pos)) 

/* -------- AC_INTFLAG : (AC Offset: 0x18) (R/W 32) Interrupt Flag Status and Clear -------- */
#define AC_INTFLAG_RESETVALUE                 _UINT32_(0x00)                                       /*  (AC_INTFLAG) Interrupt Flag Status and Clear  Reset Value */

#define AC_INTFLAG_COMP0_Pos                  _UINT32_(0)                                          /* (AC_INTFLAG) Comparator 0 Position */
#define AC_INTFLAG_COMP0_Msk                  (_UINT32_(0x1) << AC_INTFLAG_COMP0_Pos)              /* (AC_INTFLAG) Comparator 0 Mask */
#define AC_INTFLAG_COMP0(value)               (AC_INTFLAG_COMP0_Msk & (_UINT32_(value) << AC_INTFLAG_COMP0_Pos)) /* Assigment of value for COMP0 in the AC_INTFLAG register */
#define AC_INTFLAG_COMP1_Pos                  _UINT32_(1)                                          /* (AC_INTFLAG) Comparator 1 Position */
#define AC_INTFLAG_COMP1_Msk                  (_UINT32_(0x1) << AC_INTFLAG_COMP1_Pos)              /* (AC_INTFLAG) Comparator 1 Mask */
#define AC_INTFLAG_COMP1(value)               (AC_INTFLAG_COMP1_Msk & (_UINT32_(value) << AC_INTFLAG_COMP1_Pos)) /* Assigment of value for COMP1 in the AC_INTFLAG register */
#define AC_INTFLAG_WIN0_Pos                   _UINT32_(8)                                          /* (AC_INTFLAG) Window 0 Position */
#define AC_INTFLAG_WIN0_Msk                   (_UINT32_(0x1) << AC_INTFLAG_WIN0_Pos)               /* (AC_INTFLAG) Window 0 Mask */
#define AC_INTFLAG_WIN0(value)                (AC_INTFLAG_WIN0_Msk & (_UINT32_(value) << AC_INTFLAG_WIN0_Pos)) /* Assigment of value for WIN0 in the AC_INTFLAG register */
#define AC_INTFLAG_Msk                        _UINT32_(0x00000103)                                 /* (AC_INTFLAG) Register Mask  */

#define AC_INTFLAG_COMP_Pos                   _UINT32_(0)                                          /* (AC_INTFLAG Position) Comparator x */
#define AC_INTFLAG_COMP_Msk                   (_UINT32_(0x3) << AC_INTFLAG_COMP_Pos)               /* (AC_INTFLAG Mask) COMP */
#define AC_INTFLAG_COMP(value)                (AC_INTFLAG_COMP_Msk & (_UINT32_(value) << AC_INTFLAG_COMP_Pos)) 
#define AC_INTFLAG_WIN_Pos                    _UINT32_(8)                                          /* (AC_INTFLAG Position) Window x */
#define AC_INTFLAG_WIN_Msk                    (_UINT32_(0x1) << AC_INTFLAG_WIN_Pos)                /* (AC_INTFLAG Mask) WIN */
#define AC_INTFLAG_WIN(value)                 (AC_INTFLAG_WIN_Msk & (_UINT32_(value) << AC_INTFLAG_WIN_Pos)) 

/* -------- AC_STATUSA : (AC Offset: 0x1C) ( R/ 32) Status A -------- */
#define AC_STATUSA_RESETVALUE                 _UINT32_(0x00)                                       /*  (AC_STATUSA) Status A  Reset Value */

#define AC_STATUSA_STATE0_Pos                 _UINT32_(0)                                          /* (AC_STATUSA) Comparator 0 Current State Position */
#define AC_STATUSA_STATE0_Msk                 (_UINT32_(0x1) << AC_STATUSA_STATE0_Pos)             /* (AC_STATUSA) Comparator 0 Current State Mask */
#define AC_STATUSA_STATE0(value)              (AC_STATUSA_STATE0_Msk & (_UINT32_(value) << AC_STATUSA_STATE0_Pos)) /* Assigment of value for STATE0 in the AC_STATUSA register */
#define AC_STATUSA_STATE1_Pos                 _UINT32_(1)                                          /* (AC_STATUSA) Comparator 1 Current State Position */
#define AC_STATUSA_STATE1_Msk                 (_UINT32_(0x1) << AC_STATUSA_STATE1_Pos)             /* (AC_STATUSA) Comparator 1 Current State Mask */
#define AC_STATUSA_STATE1(value)              (AC_STATUSA_STATE1_Msk & (_UINT32_(value) << AC_STATUSA_STATE1_Pos)) /* Assigment of value for STATE1 in the AC_STATUSA register */
#define AC_STATUSA_WSTATE0_Pos                _UINT32_(16)                                         /* (AC_STATUSA) Window 0 Current State Position */
#define AC_STATUSA_WSTATE0_Msk                (_UINT32_(0x1) << AC_STATUSA_WSTATE0_Pos)            /* (AC_STATUSA) Window 0 Current State Mask */
#define AC_STATUSA_WSTATE0(value)             (AC_STATUSA_WSTATE0_Msk & (_UINT32_(value) << AC_STATUSA_WSTATE0_Pos)) /* Assigment of value for WSTATE0 in the AC_STATUSA register */
#define   AC_STATUSA_WSTATE0_ABOVE_Val        _UINT32_(0x0)                                        /* (AC_STATUSA) Signal is above window  */
#define   AC_STATUSA_WSTATE0_INSIDE_Val       _UINT32_(0x1)                                        /* (AC_STATUSA) Signal is inside window  */
#define   AC_STATUSA_WSTATE0_BELOW_Val        _UINT32_(0x2)                                        /* (AC_STATUSA) Signal is below window  */
#define AC_STATUSA_WSTATE0_ABOVE              (AC_STATUSA_WSTATE0_ABOVE_Val << AC_STATUSA_WSTATE0_Pos) /* (AC_STATUSA) Signal is above window Position  */
#define AC_STATUSA_WSTATE0_INSIDE             (AC_STATUSA_WSTATE0_INSIDE_Val << AC_STATUSA_WSTATE0_Pos) /* (AC_STATUSA) Signal is inside window Position  */
#define AC_STATUSA_WSTATE0_BELOW              (AC_STATUSA_WSTATE0_BELOW_Val << AC_STATUSA_WSTATE0_Pos) /* (AC_STATUSA) Signal is below window Position  */
#define AC_STATUSA_WSTATE1_Pos                _UINT32_(17)                                         /* (AC_STATUSA) Window 1 Current State Position */
#define AC_STATUSA_WSTATE1_Msk                (_UINT32_(0x1) << AC_STATUSA_WSTATE1_Pos)            /* (AC_STATUSA) Window 1 Current State Mask */
#define AC_STATUSA_WSTATE1(value)             (AC_STATUSA_WSTATE1_Msk & (_UINT32_(value) << AC_STATUSA_WSTATE1_Pos)) /* Assigment of value for WSTATE1 in the AC_STATUSA register */
#define   AC_STATUSA_WSTATE1_ABOVE_Val        _UINT32_(0x0)                                        /* (AC_STATUSA) Signal is above window  */
#define   AC_STATUSA_WSTATE1_INSIDE_Val       _UINT32_(0x1)                                        /* (AC_STATUSA) Signal is inside window  */
#define   AC_STATUSA_WSTATE1_BELOW_Val        _UINT32_(0x2)                                        /* (AC_STATUSA) Signal is below window  */
#define AC_STATUSA_WSTATE1_ABOVE              (AC_STATUSA_WSTATE1_ABOVE_Val << AC_STATUSA_WSTATE1_Pos) /* (AC_STATUSA) Signal is above window Position  */
#define AC_STATUSA_WSTATE1_INSIDE             (AC_STATUSA_WSTATE1_INSIDE_Val << AC_STATUSA_WSTATE1_Pos) /* (AC_STATUSA) Signal is inside window Position  */
#define AC_STATUSA_WSTATE1_BELOW              (AC_STATUSA_WSTATE1_BELOW_Val << AC_STATUSA_WSTATE1_Pos) /* (AC_STATUSA) Signal is below window Position  */
#define AC_STATUSA_Msk                        _UINT32_(0x00030003)                                 /* (AC_STATUSA) Register Mask  */

#define AC_STATUSA_STATE_Pos                  _UINT32_(0)                                          /* (AC_STATUSA Position) Comparator x Current State */
#define AC_STATUSA_STATE_Msk                  (_UINT32_(0x3) << AC_STATUSA_STATE_Pos)              /* (AC_STATUSA Mask) STATE */
#define AC_STATUSA_STATE(value)               (AC_STATUSA_STATE_Msk & (_UINT32_(value) << AC_STATUSA_STATE_Pos)) 
#define AC_STATUSA_WSTATE_Pos                 _UINT32_(16)                                         /* (AC_STATUSA Position) Window x Current State */
#define AC_STATUSA_WSTATE_Msk                 (_UINT32_(0x3) << AC_STATUSA_WSTATE_Pos)             /* (AC_STATUSA Mask) WSTATE */
#define AC_STATUSA_WSTATE(value)              (AC_STATUSA_WSTATE_Msk & (_UINT32_(value) << AC_STATUSA_WSTATE_Pos)) 

/* -------- AC_STATUSB : (AC Offset: 0x20) ( R/ 32) Status B -------- */
#define AC_STATUSB_RESETVALUE                 _UINT32_(0x00)                                       /*  (AC_STATUSB) Status B  Reset Value */

#define AC_STATUSB_READY0_Pos                 _UINT32_(0)                                          /* (AC_STATUSB) Comparator 0 Ready Position */
#define AC_STATUSB_READY0_Msk                 (_UINT32_(0x1) << AC_STATUSB_READY0_Pos)             /* (AC_STATUSB) Comparator 0 Ready Mask */
#define AC_STATUSB_READY0(value)              (AC_STATUSB_READY0_Msk & (_UINT32_(value) << AC_STATUSB_READY0_Pos)) /* Assigment of value for READY0 in the AC_STATUSB register */
#define AC_STATUSB_READY1_Pos                 _UINT32_(1)                                          /* (AC_STATUSB) Comparator 1 Ready Position */
#define AC_STATUSB_READY1_Msk                 (_UINT32_(0x1) << AC_STATUSB_READY1_Pos)             /* (AC_STATUSB) Comparator 1 Ready Mask */
#define AC_STATUSB_READY1(value)              (AC_STATUSB_READY1_Msk & (_UINT32_(value) << AC_STATUSB_READY1_Pos)) /* Assigment of value for READY1 in the AC_STATUSB register */
#define AC_STATUSB_Msk                        _UINT32_(0x00000003)                                 /* (AC_STATUSB) Register Mask  */

#define AC_STATUSB_READY_Pos                  _UINT32_(0)                                          /* (AC_STATUSB Position) Comparator x Ready */
#define AC_STATUSB_READY_Msk                  (_UINT32_(0x3) << AC_STATUSB_READY_Pos)              /* (AC_STATUSB Mask) READY */
#define AC_STATUSB_READY(value)               (AC_STATUSB_READY_Msk & (_UINT32_(value) << AC_STATUSB_READY_Pos)) 

/* -------- AC_DBGCTRL : (AC Offset: 0x24) (R/W 32) Debug Control -------- */
#define AC_DBGCTRL_RESETVALUE                 _UINT32_(0x00)                                       /*  (AC_DBGCTRL) Debug Control  Reset Value */

#define AC_DBGCTRL_DBGRUN_Pos                 _UINT32_(0)                                          /* (AC_DBGCTRL) Debug Run Position */
#define AC_DBGCTRL_DBGRUN_Msk                 (_UINT32_(0x1) << AC_DBGCTRL_DBGRUN_Pos)             /* (AC_DBGCTRL) Debug Run Mask */
#define AC_DBGCTRL_DBGRUN(value)              (AC_DBGCTRL_DBGRUN_Msk & (_UINT32_(value) << AC_DBGCTRL_DBGRUN_Pos)) /* Assigment of value for DBGRUN in the AC_DBGCTRL register */
#define AC_DBGCTRL_Msk                        _UINT32_(0x00000001)                                 /* (AC_DBGCTRL) Register Mask  */


/* -------- AC_SYNCBUSY : (AC Offset: 0x28) ( R/ 32) Synchronization Busy -------- */
#define AC_SYNCBUSY_RESETVALUE                _UINT32_(0x00)                                       /*  (AC_SYNCBUSY) Synchronization Busy  Reset Value */

#define AC_SYNCBUSY_SWRST_Pos                 _UINT32_(0)                                          /* (AC_SYNCBUSY) Software Reset Synchronization Busy Position */
#define AC_SYNCBUSY_SWRST_Msk                 (_UINT32_(0x1) << AC_SYNCBUSY_SWRST_Pos)             /* (AC_SYNCBUSY) Software Reset Synchronization Busy Mask */
#define AC_SYNCBUSY_SWRST(value)              (AC_SYNCBUSY_SWRST_Msk & (_UINT32_(value) << AC_SYNCBUSY_SWRST_Pos)) /* Assigment of value for SWRST in the AC_SYNCBUSY register */
#define AC_SYNCBUSY_ENABLE_Pos                _UINT32_(1)                                          /* (AC_SYNCBUSY) Enable Synchronization Busy Position */
#define AC_SYNCBUSY_ENABLE_Msk                (_UINT32_(0x1) << AC_SYNCBUSY_ENABLE_Pos)            /* (AC_SYNCBUSY) Enable Synchronization Busy Mask */
#define AC_SYNCBUSY_ENABLE(value)             (AC_SYNCBUSY_ENABLE_Msk & (_UINT32_(value) << AC_SYNCBUSY_ENABLE_Pos)) /* Assigment of value for ENABLE in the AC_SYNCBUSY register */
#define AC_SYNCBUSY_COMPCTRL0_Pos             _UINT32_(2)                                          /* (AC_SYNCBUSY) COMPCTRL 0 Synchronization Busy Position */
#define AC_SYNCBUSY_COMPCTRL0_Msk             (_UINT32_(0x1) << AC_SYNCBUSY_COMPCTRL0_Pos)         /* (AC_SYNCBUSY) COMPCTRL 0 Synchronization Busy Mask */
#define AC_SYNCBUSY_COMPCTRL0(value)          (AC_SYNCBUSY_COMPCTRL0_Msk & (_UINT32_(value) << AC_SYNCBUSY_COMPCTRL0_Pos)) /* Assigment of value for COMPCTRL0 in the AC_SYNCBUSY register */
#define AC_SYNCBUSY_COMPCTRL1_Pos             _UINT32_(3)                                          /* (AC_SYNCBUSY) COMPCTRL 1 Synchronization Busy Position */
#define AC_SYNCBUSY_COMPCTRL1_Msk             (_UINT32_(0x1) << AC_SYNCBUSY_COMPCTRL1_Pos)         /* (AC_SYNCBUSY) COMPCTRL 1 Synchronization Busy Mask */
#define AC_SYNCBUSY_COMPCTRL1(value)          (AC_SYNCBUSY_COMPCTRL1_Msk & (_UINT32_(value) << AC_SYNCBUSY_COMPCTRL1_Pos)) /* Assigment of value for COMPCTRL1 in the AC_SYNCBUSY register */
#define AC_SYNCBUSY_WINCTRL0_Pos              _UINT32_(10)                                         /* (AC_SYNCBUSY) WINCTRL 0 Synchronization Busy Position */
#define AC_SYNCBUSY_WINCTRL0_Msk              (_UINT32_(0x1) << AC_SYNCBUSY_WINCTRL0_Pos)          /* (AC_SYNCBUSY) WINCTRL 0 Synchronization Busy Mask */
#define AC_SYNCBUSY_WINCTRL0(value)           (AC_SYNCBUSY_WINCTRL0_Msk & (_UINT32_(value) << AC_SYNCBUSY_WINCTRL0_Pos)) /* Assigment of value for WINCTRL0 in the AC_SYNCBUSY register */
#define AC_SYNCBUSY_Msk                       _UINT32_(0x0000040F)                                 /* (AC_SYNCBUSY) Register Mask  */

#define AC_SYNCBUSY_COMPCTRL_Pos              _UINT32_(2)                                          /* (AC_SYNCBUSY Position) COMPCTRL x Synchronization Busy */
#define AC_SYNCBUSY_COMPCTRL_Msk              (_UINT32_(0x3) << AC_SYNCBUSY_COMPCTRL_Pos)          /* (AC_SYNCBUSY Mask) COMPCTRL */
#define AC_SYNCBUSY_COMPCTRL(value)           (AC_SYNCBUSY_COMPCTRL_Msk & (_UINT32_(value) << AC_SYNCBUSY_COMPCTRL_Pos)) 
#define AC_SYNCBUSY_WINCTRL_Pos               _UINT32_(10)                                         /* (AC_SYNCBUSY Position) WINCTRL x Synchronization Busy */
#define AC_SYNCBUSY_WINCTRL_Msk               (_UINT32_(0x1) << AC_SYNCBUSY_WINCTRL_Pos)           /* (AC_SYNCBUSY Mask) WINCTRL */
#define AC_SYNCBUSY_WINCTRL(value)            (AC_SYNCBUSY_WINCTRL_Msk & (_UINT32_(value) << AC_SYNCBUSY_WINCTRL_Pos)) 

/* -------- AC_COMPCTRL : (AC Offset: 0x30) (R/W 32) Pair n Comparator Control 0 -------- */
#define AC_COMPCTRL_RESETVALUE                _UINT32_(0x00)                                       /*  (AC_COMPCTRL) Pair n Comparator Control 0  Reset Value */

#define AC_COMPCTRL_ENABLE_Pos                _UINT32_(1)                                          /* (AC_COMPCTRL) Enable Position */
#define AC_COMPCTRL_ENABLE_Msk                (_UINT32_(0x1) << AC_COMPCTRL_ENABLE_Pos)            /* (AC_COMPCTRL) Enable Mask */
#define AC_COMPCTRL_ENABLE(value)             (AC_COMPCTRL_ENABLE_Msk & (_UINT32_(value) << AC_COMPCTRL_ENABLE_Pos)) /* Assigment of value for ENABLE in the AC_COMPCTRL register */
#define AC_COMPCTRL_SINGLE_Pos                _UINT32_(3)                                          /* (AC_COMPCTRL) Single-Shot Mode Position */
#define AC_COMPCTRL_SINGLE_Msk                (_UINT32_(0x1) << AC_COMPCTRL_SINGLE_Pos)            /* (AC_COMPCTRL) Single-Shot Mode Mask */
#define AC_COMPCTRL_SINGLE(value)             (AC_COMPCTRL_SINGLE_Msk & (_UINT32_(value) << AC_COMPCTRL_SINGLE_Pos)) /* Assigment of value for SINGLE in the AC_COMPCTRL register */
#define AC_COMPCTRL_INTSEL_Pos                _UINT32_(4)                                          /* (AC_COMPCTRL) Interrupt Selection Position */
#define AC_COMPCTRL_INTSEL_Msk                (_UINT32_(0x3) << AC_COMPCTRL_INTSEL_Pos)            /* (AC_COMPCTRL) Interrupt Selection Mask */
#define AC_COMPCTRL_INTSEL(value)             (AC_COMPCTRL_INTSEL_Msk & (_UINT32_(value) << AC_COMPCTRL_INTSEL_Pos)) /* Assigment of value for INTSEL in the AC_COMPCTRL register */
#define   AC_COMPCTRL_INTSEL_TOGGLE_Val       _UINT32_(0x0)                                        /* (AC_COMPCTRL) Interrupt on comparator output toggle  */
#define   AC_COMPCTRL_INTSEL_RISING_Val       _UINT32_(0x1)                                        /* (AC_COMPCTRL) Interrupt on comparator output rising  */
#define   AC_COMPCTRL_INTSEL_FALLING_Val      _UINT32_(0x2)                                        /* (AC_COMPCTRL) Interrupt on comparator output falling  */
#define   AC_COMPCTRL_INTSEL_EOC_Val          _UINT32_(0x3)                                        /* (AC_COMPCTRL) Interrupt on end of comparison (single-shot mode only)  */
#define AC_COMPCTRL_INTSEL_TOGGLE             (AC_COMPCTRL_INTSEL_TOGGLE_Val << AC_COMPCTRL_INTSEL_Pos) /* (AC_COMPCTRL) Interrupt on comparator output toggle Position  */
#define AC_COMPCTRL_INTSEL_RISING             (AC_COMPCTRL_INTSEL_RISING_Val << AC_COMPCTRL_INTSEL_Pos) /* (AC_COMPCTRL) Interrupt on comparator output rising Position  */
#define AC_COMPCTRL_INTSEL_FALLING            (AC_COMPCTRL_INTSEL_FALLING_Val << AC_COMPCTRL_INTSEL_Pos) /* (AC_COMPCTRL) Interrupt on comparator output falling Position  */
#define AC_COMPCTRL_INTSEL_EOC                (AC_COMPCTRL_INTSEL_EOC_Val << AC_COMPCTRL_INTSEL_Pos) /* (AC_COMPCTRL) Interrupt on end of comparison (single-shot mode only) Position  */
#define AC_COMPCTRL_RUNSTDBY_Pos              _UINT32_(6)                                          /* (AC_COMPCTRL) Run in Standby Position */
#define AC_COMPCTRL_RUNSTDBY_Msk              (_UINT32_(0x1) << AC_COMPCTRL_RUNSTDBY_Pos)          /* (AC_COMPCTRL) Run in Standby Mask */
#define AC_COMPCTRL_RUNSTDBY(value)           (AC_COMPCTRL_RUNSTDBY_Msk & (_UINT32_(value) << AC_COMPCTRL_RUNSTDBY_Pos)) /* Assigment of value for RUNSTDBY in the AC_COMPCTRL register */
#define AC_COMPCTRL_MUXNEG_Pos                _UINT32_(8)                                          /* (AC_COMPCTRL) Negative Input Mux Selection Position */
#define AC_COMPCTRL_MUXNEG_Msk                (_UINT32_(0x7) << AC_COMPCTRL_MUXNEG_Pos)            /* (AC_COMPCTRL) Negative Input Mux Selection Mask */
#define AC_COMPCTRL_MUXNEG(value)             (AC_COMPCTRL_MUXNEG_Msk & (_UINT32_(value) << AC_COMPCTRL_MUXNEG_Pos)) /* Assigment of value for MUXNEG in the AC_COMPCTRL register */
#define   AC_COMPCTRL_MUXNEG_PIN0_Val         _UINT32_(0x0)                                        /* (AC_COMPCTRL) I/O pin 0  */
#define   AC_COMPCTRL_MUXNEG_PIN1_Val         _UINT32_(0x1)                                        /* (AC_COMPCTRL) I/O pin 1  */
#define   AC_COMPCTRL_MUXNEG_PIN2_Val         _UINT32_(0x2)                                        /* (AC_COMPCTRL) I/O pin 2  */
#define   AC_COMPCTRL_MUXNEG_PIN3_Val         _UINT32_(0x3)                                        /* (AC_COMPCTRL) I/O pin 3  */
#define   AC_COMPCTRL_MUXNEG_INT0_Val         _UINT32_(0x4)                                        /* (AC_COMPCTRL) Internal connection 0, device specific  */
#define   AC_COMPCTRL_MUXNEG_BANDGAP_Val      _UINT32_(0x5)                                        /* (AC_COMPCTRL) Bangap  */
#define   AC_COMPCTRL_MUXNEG_GND_Val          _UINT32_(0x6)                                        /* (AC_COMPCTRL) Ground  */
#define   AC_COMPCTRL_MUXNEG_INTDAC_Val       _UINT32_(0x7)                                        /* (AC_COMPCTRL) Internal DAC  */
#define AC_COMPCTRL_MUXNEG_PIN0               (AC_COMPCTRL_MUXNEG_PIN0_Val << AC_COMPCTRL_MUXNEG_Pos) /* (AC_COMPCTRL) I/O pin 0 Position  */
#define AC_COMPCTRL_MUXNEG_PIN1               (AC_COMPCTRL_MUXNEG_PIN1_Val << AC_COMPCTRL_MUXNEG_Pos) /* (AC_COMPCTRL) I/O pin 1 Position  */
#define AC_COMPCTRL_MUXNEG_PIN2               (AC_COMPCTRL_MUXNEG_PIN2_Val << AC_COMPCTRL_MUXNEG_Pos) /* (AC_COMPCTRL) I/O pin 2 Position  */
#define AC_COMPCTRL_MUXNEG_PIN3               (AC_COMPCTRL_MUXNEG_PIN3_Val << AC_COMPCTRL_MUXNEG_Pos) /* (AC_COMPCTRL) I/O pin 3 Position  */
#define AC_COMPCTRL_MUXNEG_INT0               (AC_COMPCTRL_MUXNEG_INT0_Val << AC_COMPCTRL_MUXNEG_Pos) /* (AC_COMPCTRL) Internal connection 0, device specific Position  */
#define AC_COMPCTRL_MUXNEG_BANDGAP            (AC_COMPCTRL_MUXNEG_BANDGAP_Val << AC_COMPCTRL_MUXNEG_Pos) /* (AC_COMPCTRL) Bangap Position  */
#define AC_COMPCTRL_MUXNEG_GND                (AC_COMPCTRL_MUXNEG_GND_Val << AC_COMPCTRL_MUXNEG_Pos) /* (AC_COMPCTRL) Ground Position  */
#define AC_COMPCTRL_MUXNEG_INTDAC             (AC_COMPCTRL_MUXNEG_INTDAC_Val << AC_COMPCTRL_MUXNEG_Pos) /* (AC_COMPCTRL) Internal DAC Position  */
#define AC_COMPCTRL_MUXPOS_Pos                _UINT32_(12)                                         /* (AC_COMPCTRL) Positive Input Mux Selection Position */
#define AC_COMPCTRL_MUXPOS_Msk                (_UINT32_(0x7) << AC_COMPCTRL_MUXPOS_Pos)            /* (AC_COMPCTRL) Positive Input Mux Selection Mask */
#define AC_COMPCTRL_MUXPOS(value)             (AC_COMPCTRL_MUXPOS_Msk & (_UINT32_(value) << AC_COMPCTRL_MUXPOS_Pos)) /* Assigment of value for MUXPOS in the AC_COMPCTRL register */
#define   AC_COMPCTRL_MUXPOS_PIN0_Val         _UINT32_(0x0)                                        /* (AC_COMPCTRL) I/O pin 0  */
#define   AC_COMPCTRL_MUXPOS_PIN1_Val         _UINT32_(0x1)                                        /* (AC_COMPCTRL) I/O pin 1  */
#define   AC_COMPCTRL_MUXPOS_PIN2_Val         _UINT32_(0x2)                                        /* (AC_COMPCTRL) I/O pin 2  */
#define   AC_COMPCTRL_MUXPOS_PIN3_Val         _UINT32_(0x3)                                        /* (AC_COMPCTRL) I/O pin 3  */
#define   AC_COMPCTRL_MUXPOS_INT0_Val         _UINT32_(0x4)                                        /* (AC_COMPCTRL) Internal connection 0, device specific  */
#define   AC_COMPCTRL_MUXPOS_INT1_Val         _UINT32_(0x5)                                        /* (AC_COMPCTRL) Internal connection 1, device specific  */
#define   AC_COMPCTRL_MUXPOS_INT2_Val         _UINT32_(0x6)                                        /* (AC_COMPCTRL) Internal connection 2, device specific  */
#define   AC_COMPCTRL_MUXPOS_INTDAC_Val       _UINT32_(0x7)                                        /* (AC_COMPCTRL) Internal DAC  */
#define AC_COMPCTRL_MUXPOS_PIN0               (AC_COMPCTRL_MUXPOS_PIN0_Val << AC_COMPCTRL_MUXPOS_Pos) /* (AC_COMPCTRL) I/O pin 0 Position  */
#define AC_COMPCTRL_MUXPOS_PIN1               (AC_COMPCTRL_MUXPOS_PIN1_Val << AC_COMPCTRL_MUXPOS_Pos) /* (AC_COMPCTRL) I/O pin 1 Position  */
#define AC_COMPCTRL_MUXPOS_PIN2               (AC_COMPCTRL_MUXPOS_PIN2_Val << AC_COMPCTRL_MUXPOS_Pos) /* (AC_COMPCTRL) I/O pin 2 Position  */
#define AC_COMPCTRL_MUXPOS_PIN3               (AC_COMPCTRL_MUXPOS_PIN3_Val << AC_COMPCTRL_MUXPOS_Pos) /* (AC_COMPCTRL) I/O pin 3 Position  */
#define AC_COMPCTRL_MUXPOS_INT0               (AC_COMPCTRL_MUXPOS_INT0_Val << AC_COMPCTRL_MUXPOS_Pos) /* (AC_COMPCTRL) Internal connection 0, device specific Position  */
#define AC_COMPCTRL_MUXPOS_INT1               (AC_COMPCTRL_MUXPOS_INT1_Val << AC_COMPCTRL_MUXPOS_Pos) /* (AC_COMPCTRL) Internal connection 1, device specific Position  */
#define AC_COMPCTRL_MUXPOS_INT2               (AC_COMPCTRL_MUXPOS_INT2_Val << AC_COMPCTRL_MUXPOS_Pos) /* (AC_COMPCTRL) Internal connection 2, device specific Position  */
#define AC_COMPCTRL_MUXPOS_INTDAC             (AC_COMPCTRL_MUXPOS_INTDAC_Val << AC_COMPCTRL_MUXPOS_Pos) /* (AC_COMPCTRL) Internal DAC Position  */
#define AC_COMPCTRL_SWAP_Pos                  _UINT32_(16)                                         /* (AC_COMPCTRL) Swap Inputs and Invert Position */
#define AC_COMPCTRL_SWAP_Msk                  (_UINT32_(0x1) << AC_COMPCTRL_SWAP_Pos)              /* (AC_COMPCTRL) Swap Inputs and Invert Mask */
#define AC_COMPCTRL_SWAP(value)               (AC_COMPCTRL_SWAP_Msk & (_UINT32_(value) << AC_COMPCTRL_SWAP_Pos)) /* Assigment of value for SWAP in the AC_COMPCTRL register */
#define AC_COMPCTRL_SPEED_Pos                 _UINT32_(17)                                         /* (AC_COMPCTRL) Speed Selection Position */
#define AC_COMPCTRL_SPEED_Msk                 (_UINT32_(0x1) << AC_COMPCTRL_SPEED_Pos)             /* (AC_COMPCTRL) Speed Selection Mask */
#define AC_COMPCTRL_SPEED(value)              (AC_COMPCTRL_SPEED_Msk & (_UINT32_(value) << AC_COMPCTRL_SPEED_Pos)) /* Assigment of value for SPEED in the AC_COMPCTRL register */
#define   AC_COMPCTRL_SPEED_HIGH_Val          _UINT32_(0x0)                                        /* (AC_COMPCTRL) High speed, high power  */
#define   AC_COMPCTRL_SPEED_LOW_Val           _UINT32_(0x1)                                        /* (AC_COMPCTRL) Low speed, low power  */
#define AC_COMPCTRL_SPEED_HIGH                (AC_COMPCTRL_SPEED_HIGH_Val << AC_COMPCTRL_SPEED_Pos) /* (AC_COMPCTRL) High speed, high power Position  */
#define AC_COMPCTRL_SPEED_LOW                 (AC_COMPCTRL_SPEED_LOW_Val << AC_COMPCTRL_SPEED_Pos) /* (AC_COMPCTRL) Low speed, low power Position  */
#define AC_COMPCTRL_HYST_Pos                  _UINT32_(19)                                         /* (AC_COMPCTRL) Hysteresis Level Position */
#define AC_COMPCTRL_HYST_Msk                  (_UINT32_(0x3) << AC_COMPCTRL_HYST_Pos)              /* (AC_COMPCTRL) Hysteresis Level Mask */
#define AC_COMPCTRL_HYST(value)               (AC_COMPCTRL_HYST_Msk & (_UINT32_(value) << AC_COMPCTRL_HYST_Pos)) /* Assigment of value for HYST in the AC_COMPCTRL register */
#define   AC_COMPCTRL_HYST_HYST10_Val         _UINT32_(0x0)                                        /* (AC_COMPCTRL) 10mV  */
#define   AC_COMPCTRL_HYST_HYST20_Val         _UINT32_(0x1)                                        /* (AC_COMPCTRL) 20mV  */
#define   AC_COMPCTRL_HYST_HYST40_Val         _UINT32_(0x2)                                        /* (AC_COMPCTRL) 40mV  */
#define   AC_COMPCTRL_HYST_HYST60_Val         _UINT32_(0x3)                                        /* (AC_COMPCTRL) 60mV  */
#define AC_COMPCTRL_HYST_HYST10               (AC_COMPCTRL_HYST_HYST10_Val << AC_COMPCTRL_HYST_Pos) /* (AC_COMPCTRL) 10mV Position  */
#define AC_COMPCTRL_HYST_HYST20               (AC_COMPCTRL_HYST_HYST20_Val << AC_COMPCTRL_HYST_Pos) /* (AC_COMPCTRL) 20mV Position  */
#define AC_COMPCTRL_HYST_HYST40               (AC_COMPCTRL_HYST_HYST40_Val << AC_COMPCTRL_HYST_Pos) /* (AC_COMPCTRL) 40mV Position  */
#define AC_COMPCTRL_HYST_HYST60               (AC_COMPCTRL_HYST_HYST60_Val << AC_COMPCTRL_HYST_Pos) /* (AC_COMPCTRL) 60mV Position  */
#define AC_COMPCTRL_FLEN_Pos                  _UINT32_(21)                                         /* (AC_COMPCTRL) Filter Length Position */
#define AC_COMPCTRL_FLEN_Msk                  (_UINT32_(0x7) << AC_COMPCTRL_FLEN_Pos)              /* (AC_COMPCTRL) Filter Length Mask */
#define AC_COMPCTRL_FLEN(value)               (AC_COMPCTRL_FLEN_Msk & (_UINT32_(value) << AC_COMPCTRL_FLEN_Pos)) /* Assigment of value for FLEN in the AC_COMPCTRL register */
#define   AC_COMPCTRL_FLEN_OFF_Val            _UINT32_(0x0)                                        /* (AC_COMPCTRL) No filtering  */
#define   AC_COMPCTRL_FLEN_MAJ3_Val           _UINT32_(0x1)                                        /* (AC_COMPCTRL) 3-bit majority function (2 of 3)  */
#define   AC_COMPCTRL_FLEN_MAJ5_Val           _UINT32_(0x2)                                        /* (AC_COMPCTRL) 5-bit majority function (3 of 5)  */
#define AC_COMPCTRL_FLEN_OFF                  (AC_COMPCTRL_FLEN_OFF_Val << AC_COMPCTRL_FLEN_Pos)   /* (AC_COMPCTRL) No filtering Position  */
#define AC_COMPCTRL_FLEN_MAJ3                 (AC_COMPCTRL_FLEN_MAJ3_Val << AC_COMPCTRL_FLEN_Pos)  /* (AC_COMPCTRL) 3-bit majority function (2 of 3) Position  */
#define AC_COMPCTRL_FLEN_MAJ5                 (AC_COMPCTRL_FLEN_MAJ5_Val << AC_COMPCTRL_FLEN_Pos)  /* (AC_COMPCTRL) 5-bit majority function (3 of 5) Position  */
#define AC_COMPCTRL_OUT_Pos                   _UINT32_(24)                                         /* (AC_COMPCTRL) Output Position */
#define AC_COMPCTRL_OUT_Msk                   (_UINT32_(0x3) << AC_COMPCTRL_OUT_Pos)               /* (AC_COMPCTRL) Output Mask */
#define AC_COMPCTRL_OUT(value)                (AC_COMPCTRL_OUT_Msk & (_UINT32_(value) << AC_COMPCTRL_OUT_Pos)) /* Assigment of value for OUT in the AC_COMPCTRL register */
#define   AC_COMPCTRL_OUT_OFF_Val             _UINT32_(0x0)                                        /* (AC_COMPCTRL) The output of COMPn is not routed to the COMPn I/O port  */
#define   AC_COMPCTRL_OUT_ASYNC_Val           _UINT32_(0x1)                                        /* (AC_COMPCTRL) The asynchronous output of COMPn is routed to the COMPn I/O port  */
#define   AC_COMPCTRL_OUT_SYNC_Val            _UINT32_(0x2)                                        /* (AC_COMPCTRL) The synchronous output (including filtering) of COMPn is routed to the COMPn I/O port  */
#define AC_COMPCTRL_OUT_OFF                   (AC_COMPCTRL_OUT_OFF_Val << AC_COMPCTRL_OUT_Pos)     /* (AC_COMPCTRL) The output of COMPn is not routed to the COMPn I/O port Position  */
#define AC_COMPCTRL_OUT_ASYNC                 (AC_COMPCTRL_OUT_ASYNC_Val << AC_COMPCTRL_OUT_Pos)   /* (AC_COMPCTRL) The asynchronous output of COMPn is routed to the COMPn I/O port Position  */
#define AC_COMPCTRL_OUT_SYNC                  (AC_COMPCTRL_OUT_SYNC_Val << AC_COMPCTRL_OUT_Pos)    /* (AC_COMPCTRL) The synchronous output (including filtering) of COMPn is routed to the COMPn I/O port Position  */
#define AC_COMPCTRL_SUT_Pos                   _UINT32_(26)                                         /* (AC_COMPCTRL) Start-up Time Position */
#define AC_COMPCTRL_SUT_Msk                   (_UINT32_(0x3F) << AC_COMPCTRL_SUT_Pos)              /* (AC_COMPCTRL) Start-up Time Mask */
#define AC_COMPCTRL_SUT(value)                (AC_COMPCTRL_SUT_Msk & (_UINT32_(value) << AC_COMPCTRL_SUT_Pos)) /* Assigment of value for SUT in the AC_COMPCTRL register */
#define AC_COMPCTRL_Msk                       _UINT32_(0xFFFB777A)                                 /* (AC_COMPCTRL) Register Mask  */


/* -------- AC_DACCTRL : (AC Offset: 0x38) (R/W 32) Dac Control -------- */
#define AC_DACCTRL_RESETVALUE                 _UINT32_(0x00)                                       /*  (AC_DACCTRL) Dac Control  Reset Value */

#define AC_DACCTRL_VALUE0_Pos                 _UINT32_(0)                                          /* (AC_DACCTRL) DAC0 Output Value Position */
#define AC_DACCTRL_VALUE0_Msk                 (_UINT32_(0x7F) << AC_DACCTRL_VALUE0_Pos)            /* (AC_DACCTRL) DAC0 Output Value Mask */
#define AC_DACCTRL_VALUE0(value)              (AC_DACCTRL_VALUE0_Msk & (_UINT32_(value) << AC_DACCTRL_VALUE0_Pos)) /* Assigment of value for VALUE0 in the AC_DACCTRL register */
#define AC_DACCTRL_SHEN0_Pos                  _UINT32_(15)                                         /* (AC_DACCTRL) DAC0 Sample and Hold Enable Operating Mode Position */
#define AC_DACCTRL_SHEN0_Msk                  (_UINT32_(0x1) << AC_DACCTRL_SHEN0_Pos)              /* (AC_DACCTRL) DAC0 Sample and Hold Enable Operating Mode Mask */
#define AC_DACCTRL_SHEN0(value)               (AC_DACCTRL_SHEN0_Msk & (_UINT32_(value) << AC_DACCTRL_SHEN0_Pos)) /* Assigment of value for SHEN0 in the AC_DACCTRL register */
#define AC_DACCTRL_VALUE1_Pos                 _UINT32_(16)                                         /* (AC_DACCTRL) DAC1 Output Value Position */
#define AC_DACCTRL_VALUE1_Msk                 (_UINT32_(0x7F) << AC_DACCTRL_VALUE1_Pos)            /* (AC_DACCTRL) DAC1 Output Value Mask */
#define AC_DACCTRL_VALUE1(value)              (AC_DACCTRL_VALUE1_Msk & (_UINT32_(value) << AC_DACCTRL_VALUE1_Pos)) /* Assigment of value for VALUE1 in the AC_DACCTRL register */
#define AC_DACCTRL_SHEN1_Pos                  _UINT32_(31)                                         /* (AC_DACCTRL) DAC1 Sample and Hold Enable Operating Mode Position */
#define AC_DACCTRL_SHEN1_Msk                  (_UINT32_(0x1) << AC_DACCTRL_SHEN1_Pos)              /* (AC_DACCTRL) DAC1 Sample and Hold Enable Operating Mode Mask */
#define AC_DACCTRL_SHEN1(value)               (AC_DACCTRL_SHEN1_Msk & (_UINT32_(value) << AC_DACCTRL_SHEN1_Pos)) /* Assigment of value for SHEN1 in the AC_DACCTRL register */
#define AC_DACCTRL_Msk                        _UINT32_(0x807F807F)                                 /* (AC_DACCTRL) Register Mask  */


/* -------- AC_WINCTRL : (AC Offset: 0x3C) (R/W 32) Window Monitor Control -------- */
#define AC_WINCTRL_RESETVALUE                 _UINT32_(0x00)                                       /*  (AC_WINCTRL) Window Monitor Control  Reset Value */

#define AC_WINCTRL_Msk                        _UINT32_(0x00000000)                                 /* (AC_WINCTRL) Register Mask  */


/** \brief AC register offsets definitions */
#define AC_CTRLA_REG_OFST              _UINT32_(0x00)      /* (AC_CTRLA) Control A Offset */
#define AC_CTRLB_REG_OFST              _UINT32_(0x04)      /* (AC_CTRLB) Control B Offset */
#define AC_CTRLC_REG_OFST              _UINT32_(0x08)      /* (AC_CTRLC) Control C Offset */
#define AC_EVCTRL_REG_OFST             _UINT32_(0x0C)      /* (AC_EVCTRL) Event Control Offset */
#define AC_INTENCLR_REG_OFST           _UINT32_(0x10)      /* (AC_INTENCLR) Interrupt Enable Clear Offset */
#define AC_INTENSET_REG_OFST           _UINT32_(0x14)      /* (AC_INTENSET) Interrupt Enable Set Offset */
#define AC_INTFLAG_REG_OFST            _UINT32_(0x18)      /* (AC_INTFLAG) Interrupt Flag Status and Clear Offset */
#define AC_STATUSA_REG_OFST            _UINT32_(0x1C)      /* (AC_STATUSA) Status A Offset */
#define AC_STATUSB_REG_OFST            _UINT32_(0x20)      /* (AC_STATUSB) Status B Offset */
#define AC_DBGCTRL_REG_OFST            _UINT32_(0x24)      /* (AC_DBGCTRL) Debug Control Offset */
#define AC_SYNCBUSY_REG_OFST           _UINT32_(0x28)      /* (AC_SYNCBUSY) Synchronization Busy Offset */
#define AC_COMPCTRL_REG_OFST           _UINT32_(0x30)      /* (AC_COMPCTRL) Pair n Comparator Control 0 Offset */
#define AC_COMPCTRL0_REG_OFST          _UINT32_(0x30)      /* (AC_COMPCTRL0) Pair n Comparator Control 0 Offset */
#define AC_COMPCTRL1_REG_OFST          _UINT32_(0x34)      /* (AC_COMPCTRL1) Pair n Comparator Control 0 Offset */
#define AC_DACCTRL_REG_OFST            _UINT32_(0x38)      /* (AC_DACCTRL) Dac Control Offset */
#define AC_WINCTRL_REG_OFST            _UINT32_(0x3C)      /* (AC_WINCTRL) Window Monitor Control Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief AC register API structure */
typedef struct
{  /* Analog Comparator Controller */
  __IO  uint32_t                       AC_CTRLA;           /**< Offset: 0x00 (R/W  32) Control A */
  __IO  uint32_t                       AC_CTRLB;           /**< Offset: 0x04 (R/W  32) Control B */
  __IO  uint32_t                       AC_CTRLC;           /**< Offset: 0x08 (R/W  32) Control C */
  __IO  uint32_t                       AC_EVCTRL;          /**< Offset: 0x0C (R/W  32) Event Control */
  __IO  uint32_t                       AC_INTENCLR;        /**< Offset: 0x10 (R/W  32) Interrupt Enable Clear */
  __IO  uint32_t                       AC_INTENSET;        /**< Offset: 0x14 (R/W  32) Interrupt Enable Set */
  __IO  uint32_t                       AC_INTFLAG;         /**< Offset: 0x18 (R/W  32) Interrupt Flag Status and Clear */
  __I   uint32_t                       AC_STATUSA;         /**< Offset: 0x1C (R/   32) Status A */
  __I   uint32_t                       AC_STATUSB;         /**< Offset: 0x20 (R/   32) Status B */
  __IO  uint32_t                       AC_DBGCTRL;         /**< Offset: 0x24 (R/W  32) Debug Control */
  __I   uint32_t                       AC_SYNCBUSY;        /**< Offset: 0x28 (R/   32) Synchronization Busy */
  __I   uint8_t                        Reserved1[0x04];
  __IO  uint32_t                       AC_COMPCTRL[2];     /**< Offset: 0x30 (R/W  32) Pair n Comparator Control 0 */
  __IO  uint32_t                       AC_DACCTRL;         /**< Offset: 0x38 (R/W  32) Dac Control */
  __IO  uint32_t                       AC_WINCTRL;         /**< Offset: 0x3C (R/W  32) Window Monitor Control */
} ac_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA80_AC_COMPONENT_H_ */
