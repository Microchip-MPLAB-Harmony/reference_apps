/*
 * Component description for OSC32KCTRL
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
#ifndef _PIC32CZCA80_OSC32KCTRL_COMPONENT_H_
#define _PIC32CZCA80_OSC32KCTRL_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR OSC32KCTRL                                   */
/* ************************************************************************** */

/* -------- OSC32KCTRL_INTENCLR : (OSC32KCTRL Offset: 0x00) (R/W 32) Interrupt Enable Clear -------- */
#define OSC32KCTRL_INTENCLR_RESETVALUE        _UINT32_(0x00)                                       /*  (OSC32KCTRL_INTENCLR) Interrupt Enable Clear  Reset Value */

#define OSC32KCTRL_INTENCLR_XOSC32KRDY_Pos    _UINT32_(0)                                          /* (OSC32KCTRL_INTENCLR) XOSC32K Ready Interrupt Enable Position */
#define OSC32KCTRL_INTENCLR_XOSC32KRDY_Msk    (_UINT32_(0x1) << OSC32KCTRL_INTENCLR_XOSC32KRDY_Pos) /* (OSC32KCTRL_INTENCLR) XOSC32K Ready Interrupt Enable Mask */
#define OSC32KCTRL_INTENCLR_XOSC32KRDY(value) (OSC32KCTRL_INTENCLR_XOSC32KRDY_Msk & (_UINT32_(value) << OSC32KCTRL_INTENCLR_XOSC32KRDY_Pos)) /* Assigment of value for XOSC32KRDY in the OSC32KCTRL_INTENCLR register */
#define OSC32KCTRL_INTENCLR_XOSC32KFAIL_Pos   _UINT32_(2)                                          /* (OSC32KCTRL_INTENCLR) XOSC32K Clock Failure Detector Interrupt Enable Position */
#define OSC32KCTRL_INTENCLR_XOSC32KFAIL_Msk   (_UINT32_(0x1) << OSC32KCTRL_INTENCLR_XOSC32KFAIL_Pos) /* (OSC32KCTRL_INTENCLR) XOSC32K Clock Failure Detector Interrupt Enable Mask */
#define OSC32KCTRL_INTENCLR_XOSC32KFAIL(value) (OSC32KCTRL_INTENCLR_XOSC32KFAIL_Msk & (_UINT32_(value) << OSC32KCTRL_INTENCLR_XOSC32KFAIL_Pos)) /* Assigment of value for XOSC32KFAIL in the OSC32KCTRL_INTENCLR register */
#define OSC32KCTRL_INTENCLR_Msk               _UINT32_(0x00000005)                                 /* (OSC32KCTRL_INTENCLR) Register Mask  */


/* -------- OSC32KCTRL_INTENSET : (OSC32KCTRL Offset: 0x04) (R/W 32) Interrupt Enable Set -------- */
#define OSC32KCTRL_INTENSET_RESETVALUE        _UINT32_(0x00)                                       /*  (OSC32KCTRL_INTENSET) Interrupt Enable Set  Reset Value */

#define OSC32KCTRL_INTENSET_XOSC32KRDY_Pos    _UINT32_(0)                                          /* (OSC32KCTRL_INTENSET) XOSC32K Ready Interrupt Enable Position */
#define OSC32KCTRL_INTENSET_XOSC32KRDY_Msk    (_UINT32_(0x1) << OSC32KCTRL_INTENSET_XOSC32KRDY_Pos) /* (OSC32KCTRL_INTENSET) XOSC32K Ready Interrupt Enable Mask */
#define OSC32KCTRL_INTENSET_XOSC32KRDY(value) (OSC32KCTRL_INTENSET_XOSC32KRDY_Msk & (_UINT32_(value) << OSC32KCTRL_INTENSET_XOSC32KRDY_Pos)) /* Assigment of value for XOSC32KRDY in the OSC32KCTRL_INTENSET register */
#define OSC32KCTRL_INTENSET_XOSC32KFAIL_Pos   _UINT32_(2)                                          /* (OSC32KCTRL_INTENSET) XOSC32K Clock Failure Detector Interrupt Enable Position */
#define OSC32KCTRL_INTENSET_XOSC32KFAIL_Msk   (_UINT32_(0x1) << OSC32KCTRL_INTENSET_XOSC32KFAIL_Pos) /* (OSC32KCTRL_INTENSET) XOSC32K Clock Failure Detector Interrupt Enable Mask */
#define OSC32KCTRL_INTENSET_XOSC32KFAIL(value) (OSC32KCTRL_INTENSET_XOSC32KFAIL_Msk & (_UINT32_(value) << OSC32KCTRL_INTENSET_XOSC32KFAIL_Pos)) /* Assigment of value for XOSC32KFAIL in the OSC32KCTRL_INTENSET register */
#define OSC32KCTRL_INTENSET_Msk               _UINT32_(0x00000005)                                 /* (OSC32KCTRL_INTENSET) Register Mask  */


/* -------- OSC32KCTRL_INTFLAG : (OSC32KCTRL Offset: 0x08) (R/W 32) Interrupt Flag Status and Clear -------- */
#define OSC32KCTRL_INTFLAG_RESETVALUE         _UINT32_(0x00)                                       /*  (OSC32KCTRL_INTFLAG) Interrupt Flag Status and Clear  Reset Value */

#define OSC32KCTRL_INTFLAG_XOSC32KRDY_Pos     _UINT32_(0)                                          /* (OSC32KCTRL_INTFLAG) XOSC32K Ready Position */
#define OSC32KCTRL_INTFLAG_XOSC32KRDY_Msk     (_UINT32_(0x1) << OSC32KCTRL_INTFLAG_XOSC32KRDY_Pos) /* (OSC32KCTRL_INTFLAG) XOSC32K Ready Mask */
#define OSC32KCTRL_INTFLAG_XOSC32KRDY(value)  (OSC32KCTRL_INTFLAG_XOSC32KRDY_Msk & (_UINT32_(value) << OSC32KCTRL_INTFLAG_XOSC32KRDY_Pos)) /* Assigment of value for XOSC32KRDY in the OSC32KCTRL_INTFLAG register */
#define OSC32KCTRL_INTFLAG_XOSC32KFAIL_Pos    _UINT32_(2)                                          /* (OSC32KCTRL_INTFLAG) XOSC32K Clock Failure Detector Position */
#define OSC32KCTRL_INTFLAG_XOSC32KFAIL_Msk    (_UINT32_(0x1) << OSC32KCTRL_INTFLAG_XOSC32KFAIL_Pos) /* (OSC32KCTRL_INTFLAG) XOSC32K Clock Failure Detector Mask */
#define OSC32KCTRL_INTFLAG_XOSC32KFAIL(value) (OSC32KCTRL_INTFLAG_XOSC32KFAIL_Msk & (_UINT32_(value) << OSC32KCTRL_INTFLAG_XOSC32KFAIL_Pos)) /* Assigment of value for XOSC32KFAIL in the OSC32KCTRL_INTFLAG register */
#define OSC32KCTRL_INTFLAG_Msk                _UINT32_(0x00000005)                                 /* (OSC32KCTRL_INTFLAG) Register Mask  */


/* -------- OSC32KCTRL_STATUS : (OSC32KCTRL Offset: 0x0C) ( R/ 32) Power and Clocks Status -------- */
#define OSC32KCTRL_STATUS_RESETVALUE          _UINT32_(0x00)                                       /*  (OSC32KCTRL_STATUS) Power and Clocks Status  Reset Value */

#define OSC32KCTRL_STATUS_XOSC32KRDY_Pos      _UINT32_(0)                                          /* (OSC32KCTRL_STATUS) XOSC32K Ready Position */
#define OSC32KCTRL_STATUS_XOSC32KRDY_Msk      (_UINT32_(0x1) << OSC32KCTRL_STATUS_XOSC32KRDY_Pos)  /* (OSC32KCTRL_STATUS) XOSC32K Ready Mask */
#define OSC32KCTRL_STATUS_XOSC32KRDY(value)   (OSC32KCTRL_STATUS_XOSC32KRDY_Msk & (_UINT32_(value) << OSC32KCTRL_STATUS_XOSC32KRDY_Pos)) /* Assigment of value for XOSC32KRDY in the OSC32KCTRL_STATUS register */
#define OSC32KCTRL_STATUS_XOSC32KFAIL_Pos     _UINT32_(2)                                          /* (OSC32KCTRL_STATUS) XOSC32K Clock Failure Detector Position */
#define OSC32KCTRL_STATUS_XOSC32KFAIL_Msk     (_UINT32_(0x1) << OSC32KCTRL_STATUS_XOSC32KFAIL_Pos) /* (OSC32KCTRL_STATUS) XOSC32K Clock Failure Detector Mask */
#define OSC32KCTRL_STATUS_XOSC32KFAIL(value)  (OSC32KCTRL_STATUS_XOSC32KFAIL_Msk & (_UINT32_(value) << OSC32KCTRL_STATUS_XOSC32KFAIL_Pos)) /* Assigment of value for XOSC32KFAIL in the OSC32KCTRL_STATUS register */
#define OSC32KCTRL_STATUS_XOSC32KSW_Pos       _UINT32_(3)                                          /* (OSC32KCTRL_STATUS) XOSC32K Clock switch Position */
#define OSC32KCTRL_STATUS_XOSC32KSW_Msk       (_UINT32_(0x1) << OSC32KCTRL_STATUS_XOSC32KSW_Pos)   /* (OSC32KCTRL_STATUS) XOSC32K Clock switch Mask */
#define OSC32KCTRL_STATUS_XOSC32KSW(value)    (OSC32KCTRL_STATUS_XOSC32KSW_Msk & (_UINT32_(value) << OSC32KCTRL_STATUS_XOSC32KSW_Pos)) /* Assigment of value for XOSC32KSW in the OSC32KCTRL_STATUS register */
#define OSC32KCTRL_STATUS_Msk                 _UINT32_(0x0000000D)                                 /* (OSC32KCTRL_STATUS) Register Mask  */


/* -------- OSC32KCTRL_CLKSELCTRL : (OSC32KCTRL Offset: 0x10) (R/W 32) Clock Selection Control -------- */
#define OSC32KCTRL_CLKSELCTRL_RESETVALUE      _UINT32_(0x00)                                       /*  (OSC32KCTRL_CLKSELCTRL) Clock Selection Control  Reset Value */

#define OSC32KCTRL_CLKSELCTRL_RTCSEL_Pos      _UINT32_(0)                                          /* (OSC32KCTRL_CLKSELCTRL) RTC Clock Selection Position */
#define OSC32KCTRL_CLKSELCTRL_RTCSEL_Msk      (_UINT32_(0x3) << OSC32KCTRL_CLKSELCTRL_RTCSEL_Pos)  /* (OSC32KCTRL_CLKSELCTRL) RTC Clock Selection Mask */
#define OSC32KCTRL_CLKSELCTRL_RTCSEL(value)   (OSC32KCTRL_CLKSELCTRL_RTCSEL_Msk & (_UINT32_(value) << OSC32KCTRL_CLKSELCTRL_RTCSEL_Pos)) /* Assigment of value for RTCSEL in the OSC32KCTRL_CLKSELCTRL register */
#define   OSC32KCTRL_CLKSELCTRL_RTCSEL_ULP32K_Val _UINT32_(0x0)                                        /* (OSC32KCTRL_CLKSELCTRL) 32.768kHz from 32kHz internal ULP oscillator  */
#define   OSC32KCTRL_CLKSELCTRL_RTCSEL_ULP1K_Val _UINT32_(0x1)                                        /* (OSC32KCTRL_CLKSELCTRL) 1.024kHz from 32kHz internal ULP oscillator  */
#define   OSC32KCTRL_CLKSELCTRL_RTCSEL_XOSC32K_Val _UINT32_(0x2)                                        /* (OSC32KCTRL_CLKSELCTRL) 32.768kHz from 32.768kHz external crystal oscillator  */
#define   OSC32KCTRL_CLKSELCTRL_RTCSEL_XOSC1K_Val _UINT32_(0x3)                                        /* (OSC32KCTRL_CLKSELCTRL) 1.024kHz from 32.768kHz internal oscillator  */
#define OSC32KCTRL_CLKSELCTRL_RTCSEL_ULP32K   (OSC32KCTRL_CLKSELCTRL_RTCSEL_ULP32K_Val << OSC32KCTRL_CLKSELCTRL_RTCSEL_Pos) /* (OSC32KCTRL_CLKSELCTRL) 32.768kHz from 32kHz internal ULP oscillator Position  */
#define OSC32KCTRL_CLKSELCTRL_RTCSEL_ULP1K    (OSC32KCTRL_CLKSELCTRL_RTCSEL_ULP1K_Val << OSC32KCTRL_CLKSELCTRL_RTCSEL_Pos) /* (OSC32KCTRL_CLKSELCTRL) 1.024kHz from 32kHz internal ULP oscillator Position  */
#define OSC32KCTRL_CLKSELCTRL_RTCSEL_XOSC32K  (OSC32KCTRL_CLKSELCTRL_RTCSEL_XOSC32K_Val << OSC32KCTRL_CLKSELCTRL_RTCSEL_Pos) /* (OSC32KCTRL_CLKSELCTRL) 32.768kHz from 32.768kHz external crystal oscillator Position  */
#define OSC32KCTRL_CLKSELCTRL_RTCSEL_XOSC1K   (OSC32KCTRL_CLKSELCTRL_RTCSEL_XOSC1K_Val << OSC32KCTRL_CLKSELCTRL_RTCSEL_Pos) /* (OSC32KCTRL_CLKSELCTRL) 1.024kHz from 32.768kHz internal oscillator Position  */
#define OSC32KCTRL_CLKSELCTRL_HSMSEL_Pos      _UINT32_(4)                                          /* (OSC32KCTRL_CLKSELCTRL) HSM Clock Selection Position */
#define OSC32KCTRL_CLKSELCTRL_HSMSEL_Msk      (_UINT32_(0x3) << OSC32KCTRL_CLKSELCTRL_HSMSEL_Pos)  /* (OSC32KCTRL_CLKSELCTRL) HSM Clock Selection Mask */
#define OSC32KCTRL_CLKSELCTRL_HSMSEL(value)   (OSC32KCTRL_CLKSELCTRL_HSMSEL_Msk & (_UINT32_(value) << OSC32KCTRL_CLKSELCTRL_HSMSEL_Pos)) /* Assigment of value for HSMSEL in the OSC32KCTRL_CLKSELCTRL register */
#define   OSC32KCTRL_CLKSELCTRL_HSMSEL_ULP32K_Val _UINT32_(0x0)                                        /* (OSC32KCTRL_CLKSELCTRL) 32.768kHz from 32kHz internal ULP oscillator  */
#define   OSC32KCTRL_CLKSELCTRL_HSMSEL_XOSC32K_Val _UINT32_(0x2)                                        /* (OSC32KCTRL_CLKSELCTRL) 32.768kHz from 32.768kHz external crystal oscillator  */
#define OSC32KCTRL_CLKSELCTRL_HSMSEL_ULP32K   (OSC32KCTRL_CLKSELCTRL_HSMSEL_ULP32K_Val << OSC32KCTRL_CLKSELCTRL_HSMSEL_Pos) /* (OSC32KCTRL_CLKSELCTRL) 32.768kHz from 32kHz internal ULP oscillator Position  */
#define OSC32KCTRL_CLKSELCTRL_HSMSEL_XOSC32K  (OSC32KCTRL_CLKSELCTRL_HSMSEL_XOSC32K_Val << OSC32KCTRL_CLKSELCTRL_HSMSEL_Pos) /* (OSC32KCTRL_CLKSELCTRL) 32.768kHz from 32.768kHz external crystal oscillator Position  */
#define OSC32KCTRL_CLKSELCTRL_Msk             _UINT32_(0x00000033)                                 /* (OSC32KCTRL_CLKSELCTRL) Register Mask  */


/* -------- OSC32KCTRL_CFDCTRL : (OSC32KCTRL Offset: 0x14) (R/W 32) Clock Failure Detector Control -------- */
#define OSC32KCTRL_CFDCTRL_RESETVALUE         _UINT32_(0x00)                                       /*  (OSC32KCTRL_CFDCTRL) Clock Failure Detector Control  Reset Value */

#define OSC32KCTRL_CFDCTRL_CFDEN_Pos          _UINT32_(0)                                          /* (OSC32KCTRL_CFDCTRL) Clock Failure Detector Enable Position */
#define OSC32KCTRL_CFDCTRL_CFDEN_Msk          (_UINT32_(0x1) << OSC32KCTRL_CFDCTRL_CFDEN_Pos)      /* (OSC32KCTRL_CFDCTRL) Clock Failure Detector Enable Mask */
#define OSC32KCTRL_CFDCTRL_CFDEN(value)       (OSC32KCTRL_CFDCTRL_CFDEN_Msk & (_UINT32_(value) << OSC32KCTRL_CFDCTRL_CFDEN_Pos)) /* Assigment of value for CFDEN in the OSC32KCTRL_CFDCTRL register */
#define OSC32KCTRL_CFDCTRL_SWBACK_Pos         _UINT32_(1)                                          /* (OSC32KCTRL_CFDCTRL) Clock Switch Back Position */
#define OSC32KCTRL_CFDCTRL_SWBACK_Msk         (_UINT32_(0x1) << OSC32KCTRL_CFDCTRL_SWBACK_Pos)     /* (OSC32KCTRL_CFDCTRL) Clock Switch Back Mask */
#define OSC32KCTRL_CFDCTRL_SWBACK(value)      (OSC32KCTRL_CFDCTRL_SWBACK_Msk & (_UINT32_(value) << OSC32KCTRL_CFDCTRL_SWBACK_Pos)) /* Assigment of value for SWBACK in the OSC32KCTRL_CFDCTRL register */
#define OSC32KCTRL_CFDCTRL_CFDPRESC_Pos       _UINT32_(2)                                          /* (OSC32KCTRL_CFDCTRL) Clock Failure Detector Prescaler Position */
#define OSC32KCTRL_CFDCTRL_CFDPRESC_Msk       (_UINT32_(0x1) << OSC32KCTRL_CFDCTRL_CFDPRESC_Pos)   /* (OSC32KCTRL_CFDCTRL) Clock Failure Detector Prescaler Mask */
#define OSC32KCTRL_CFDCTRL_CFDPRESC(value)    (OSC32KCTRL_CFDCTRL_CFDPRESC_Msk & (_UINT32_(value) << OSC32KCTRL_CFDCTRL_CFDPRESC_Pos)) /* Assigment of value for CFDPRESC in the OSC32KCTRL_CFDCTRL register */
#define OSC32KCTRL_CFDCTRL_Msk                _UINT32_(0x00000007)                                 /* (OSC32KCTRL_CFDCTRL) Register Mask  */


/* -------- OSC32KCTRL_EVCTRL : (OSC32KCTRL Offset: 0x18) (R/W 32) Event Control -------- */
#define OSC32KCTRL_EVCTRL_RESETVALUE          _UINT32_(0x00)                                       /*  (OSC32KCTRL_EVCTRL) Event Control  Reset Value */

#define OSC32KCTRL_EVCTRL_CFDEO_Pos           _UINT32_(0)                                          /* (OSC32KCTRL_EVCTRL) Clock Failure Detector Event Output Enable Position */
#define OSC32KCTRL_EVCTRL_CFDEO_Msk           (_UINT32_(0x1) << OSC32KCTRL_EVCTRL_CFDEO_Pos)       /* (OSC32KCTRL_EVCTRL) Clock Failure Detector Event Output Enable Mask */
#define OSC32KCTRL_EVCTRL_CFDEO(value)        (OSC32KCTRL_EVCTRL_CFDEO_Msk & (_UINT32_(value) << OSC32KCTRL_EVCTRL_CFDEO_Pos)) /* Assigment of value for CFDEO in the OSC32KCTRL_EVCTRL register */
#define OSC32KCTRL_EVCTRL_Msk                 _UINT32_(0x00000001)                                 /* (OSC32KCTRL_EVCTRL) Register Mask  */


/* -------- OSC32KCTRL_XOSC32K : (OSC32KCTRL Offset: 0x1C) (R/W 32) 32kHz External Crystal Oscillator (XOSC32K) Control -------- */
#define OSC32KCTRL_XOSC32K_RESETVALUE         _UINT32_(0x200080)                                   /*  (OSC32KCTRL_XOSC32K) 32kHz External Crystal Oscillator (XOSC32K) Control  Reset Value */

#define OSC32KCTRL_XOSC32K_ENABLE_Pos         _UINT32_(1)                                          /* (OSC32KCTRL_XOSC32K) Oscillator Enable Position */
#define OSC32KCTRL_XOSC32K_ENABLE_Msk         (_UINT32_(0x1) << OSC32KCTRL_XOSC32K_ENABLE_Pos)     /* (OSC32KCTRL_XOSC32K) Oscillator Enable Mask */
#define OSC32KCTRL_XOSC32K_ENABLE(value)      (OSC32KCTRL_XOSC32K_ENABLE_Msk & (_UINT32_(value) << OSC32KCTRL_XOSC32K_ENABLE_Pos)) /* Assigment of value for ENABLE in the OSC32KCTRL_XOSC32K register */
#define OSC32KCTRL_XOSC32K_XTALEN_Pos         _UINT32_(2)                                          /* (OSC32KCTRL_XOSC32K) Crystal Oscillator Enable Position */
#define OSC32KCTRL_XOSC32K_XTALEN_Msk         (_UINT32_(0x1) << OSC32KCTRL_XOSC32K_XTALEN_Pos)     /* (OSC32KCTRL_XOSC32K) Crystal Oscillator Enable Mask */
#define OSC32KCTRL_XOSC32K_XTALEN(value)      (OSC32KCTRL_XOSC32K_XTALEN_Msk & (_UINT32_(value) << OSC32KCTRL_XOSC32K_XTALEN_Pos)) /* Assigment of value for XTALEN in the OSC32KCTRL_XOSC32K register */
#define OSC32KCTRL_XOSC32K_ONDEMAND_Pos       _UINT32_(7)                                          /* (OSC32KCTRL_XOSC32K) On Demand Mode Position */
#define OSC32KCTRL_XOSC32K_ONDEMAND_Msk       (_UINT32_(0x1) << OSC32KCTRL_XOSC32K_ONDEMAND_Pos)   /* (OSC32KCTRL_XOSC32K) On Demand Mode Mask */
#define OSC32KCTRL_XOSC32K_ONDEMAND(value)    (OSC32KCTRL_XOSC32K_ONDEMAND_Msk & (_UINT32_(value) << OSC32KCTRL_XOSC32K_ONDEMAND_Pos)) /* Assigment of value for ONDEMAND in the OSC32KCTRL_XOSC32K register */
#define OSC32KCTRL_XOSC32K_STARTUP_Pos        _UINT32_(8)                                          /* (OSC32KCTRL_XOSC32K) Startup Mode Position */
#define OSC32KCTRL_XOSC32K_STARTUP_Msk        (_UINT32_(0xF) << OSC32KCTRL_XOSC32K_STARTUP_Pos)    /* (OSC32KCTRL_XOSC32K) Startup Mode Mask */
#define OSC32KCTRL_XOSC32K_STARTUP(value)     (OSC32KCTRL_XOSC32K_STARTUP_Msk & (_UINT32_(value) << OSC32KCTRL_XOSC32K_STARTUP_Pos)) /* Assigment of value for STARTUP in the OSC32KCTRL_XOSC32K register */
#define   OSC32KCTRL_XOSC32K_STARTUP_1CYCLE_Val _UINT32_(0x0)                                        /* (OSC32KCTRL_XOSC32K) 1 ULP clock cycle  */
#define   OSC32KCTRL_XOSC32K_STARTUP_16CYCLES_Val _UINT32_(0x1)                                        /* (OSC32KCTRL_XOSC32K) 16 ULP clock cycles  */
#define   OSC32KCTRL_XOSC32K_STARTUP_32CYCLES_Val _UINT32_(0x2)                                        /* (OSC32KCTRL_XOSC32K) 32 ULP clock cycles  */
#define   OSC32KCTRL_XOSC32K_STARTUP_2048CYCLES_Val _UINT32_(0x3)                                        /* (OSC32KCTRL_XOSC32K) 2048 ULP clock cycles  */
#define   OSC32KCTRL_XOSC32K_STARTUP_4096CYCLES_Val _UINT32_(0x4)                                        /* (OSC32KCTRL_XOSC32K) 4096 ULP clock cycles  */
#define   OSC32KCTRL_XOSC32K_STARTUP_8192CYCLES_Val _UINT32_(0x5)                                        /* (OSC32KCTRL_XOSC32K) 8192 ULP clock cycles  */
#define   OSC32KCTRL_XOSC32K_STARTUP_16384CYCLES_Val _UINT32_(0x6)                                        /* (OSC32KCTRL_XOSC32K) 16384 ULP clock cycles  */
#define   OSC32KCTRL_XOSC32K_STARTUP_32768CYCLES_Val _UINT32_(0x7)                                        /* (OSC32KCTRL_XOSC32K) 32768 ULP clock cycles  */
#define   OSC32KCTRL_XOSC32K_STARTUP_65536CYCLES_Val _UINT32_(0x8)                                        /* (OSC32KCTRL_XOSC32K) 65536 ULP clock cycles  */
#define   OSC32KCTRL_XOSC32K_STARTUP_131072CYCLES_Val _UINT32_(0x9)                                        /* (OSC32KCTRL_XOSC32K) 131072 ULP clock cycles  */
#define   OSC32KCTRL_XOSC32K_STARTUP_262144CYCLES_Val _UINT32_(0xA)                                        /* (OSC32KCTRL_XOSC32K) 262144 ULP clock cycles  */
#define OSC32KCTRL_XOSC32K_STARTUP_1CYCLE     (OSC32KCTRL_XOSC32K_STARTUP_1CYCLE_Val << OSC32KCTRL_XOSC32K_STARTUP_Pos) /* (OSC32KCTRL_XOSC32K) 1 ULP clock cycle Position  */
#define OSC32KCTRL_XOSC32K_STARTUP_16CYCLES   (OSC32KCTRL_XOSC32K_STARTUP_16CYCLES_Val << OSC32KCTRL_XOSC32K_STARTUP_Pos) /* (OSC32KCTRL_XOSC32K) 16 ULP clock cycles Position  */
#define OSC32KCTRL_XOSC32K_STARTUP_32CYCLES   (OSC32KCTRL_XOSC32K_STARTUP_32CYCLES_Val << OSC32KCTRL_XOSC32K_STARTUP_Pos) /* (OSC32KCTRL_XOSC32K) 32 ULP clock cycles Position  */
#define OSC32KCTRL_XOSC32K_STARTUP_2048CYCLES (OSC32KCTRL_XOSC32K_STARTUP_2048CYCLES_Val << OSC32KCTRL_XOSC32K_STARTUP_Pos) /* (OSC32KCTRL_XOSC32K) 2048 ULP clock cycles Position  */
#define OSC32KCTRL_XOSC32K_STARTUP_4096CYCLES (OSC32KCTRL_XOSC32K_STARTUP_4096CYCLES_Val << OSC32KCTRL_XOSC32K_STARTUP_Pos) /* (OSC32KCTRL_XOSC32K) 4096 ULP clock cycles Position  */
#define OSC32KCTRL_XOSC32K_STARTUP_8192CYCLES (OSC32KCTRL_XOSC32K_STARTUP_8192CYCLES_Val << OSC32KCTRL_XOSC32K_STARTUP_Pos) /* (OSC32KCTRL_XOSC32K) 8192 ULP clock cycles Position  */
#define OSC32KCTRL_XOSC32K_STARTUP_16384CYCLES (OSC32KCTRL_XOSC32K_STARTUP_16384CYCLES_Val << OSC32KCTRL_XOSC32K_STARTUP_Pos) /* (OSC32KCTRL_XOSC32K) 16384 ULP clock cycles Position  */
#define OSC32KCTRL_XOSC32K_STARTUP_32768CYCLES (OSC32KCTRL_XOSC32K_STARTUP_32768CYCLES_Val << OSC32KCTRL_XOSC32K_STARTUP_Pos) /* (OSC32KCTRL_XOSC32K) 32768 ULP clock cycles Position  */
#define OSC32KCTRL_XOSC32K_STARTUP_65536CYCLES (OSC32KCTRL_XOSC32K_STARTUP_65536CYCLES_Val << OSC32KCTRL_XOSC32K_STARTUP_Pos) /* (OSC32KCTRL_XOSC32K) 65536 ULP clock cycles Position  */
#define OSC32KCTRL_XOSC32K_STARTUP_131072CYCLES (OSC32KCTRL_XOSC32K_STARTUP_131072CYCLES_Val << OSC32KCTRL_XOSC32K_STARTUP_Pos) /* (OSC32KCTRL_XOSC32K) 131072 ULP clock cycles Position  */
#define OSC32KCTRL_XOSC32K_STARTUP_262144CYCLES (OSC32KCTRL_XOSC32K_STARTUP_262144CYCLES_Val << OSC32KCTRL_XOSC32K_STARTUP_Pos) /* (OSC32KCTRL_XOSC32K) 262144 ULP clock cycles Position  */
#define OSC32KCTRL_XOSC32K_ENSL_Pos           _UINT32_(16)                                         /* (OSC32KCTRL_XOSC32K) Enable Servo Loop Position */
#define OSC32KCTRL_XOSC32K_ENSL_Msk           (_UINT32_(0x1) << OSC32KCTRL_XOSC32K_ENSL_Pos)       /* (OSC32KCTRL_XOSC32K) Enable Servo Loop Mask */
#define OSC32KCTRL_XOSC32K_ENSL(value)        (OSC32KCTRL_XOSC32K_ENSL_Msk & (_UINT32_(value) << OSC32KCTRL_XOSC32K_ENSL_Pos)) /* Assigment of value for ENSL in the OSC32KCTRL_XOSC32K register */
#define OSC32KCTRL_XOSC32K_BOOST_Pos          _UINT32_(17)                                         /* (OSC32KCTRL_XOSC32K) Gain Boost Position */
#define OSC32KCTRL_XOSC32K_BOOST_Msk          (_UINT32_(0x1) << OSC32KCTRL_XOSC32K_BOOST_Pos)      /* (OSC32KCTRL_XOSC32K) Gain Boost Mask */
#define OSC32KCTRL_XOSC32K_BOOST(value)       (OSC32KCTRL_XOSC32K_BOOST_Msk & (_UINT32_(value) << OSC32KCTRL_XOSC32K_BOOST_Pos)) /* Assigment of value for BOOST in the OSC32KCTRL_XOSC32K register */
#define OSC32KCTRL_XOSC32K_CGM_Pos            _UINT32_(18)                                         /* (OSC32KCTRL_XOSC32K) Control Gain Mode Position */
#define OSC32KCTRL_XOSC32K_CGM_Msk            (_UINT32_(0xF) << OSC32KCTRL_XOSC32K_CGM_Pos)        /* (OSC32KCTRL_XOSC32K) Control Gain Mode Mask */
#define OSC32KCTRL_XOSC32K_CGM(value)         (OSC32KCTRL_XOSC32K_CGM_Msk & (_UINT32_(value) << OSC32KCTRL_XOSC32K_CGM_Pos)) /* Assigment of value for CGM in the OSC32KCTRL_XOSC32K register */
#define   OSC32KCTRL_XOSC32K_CGM_CGM0_Val     _UINT32_(0x0)                                        /* (OSC32KCTRL_XOSC32K) The lower Control Gain Mode value  */
#define   OSC32KCTRL_XOSC32K_CGM_CGM1_Val     _UINT32_(0x1)                                        /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM0  */
#define   OSC32KCTRL_XOSC32K_CGM_CGM2_Val     _UINT32_(0x2)                                        /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM1  */
#define   OSC32KCTRL_XOSC32K_CGM_CGM3_Val     _UINT32_(0x3)                                        /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM2  */
#define   OSC32KCTRL_XOSC32K_CGM_CGM4_Val     _UINT32_(0x4)                                        /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM3  */
#define   OSC32KCTRL_XOSC32K_CGM_CGM5_Val     _UINT32_(0x5)                                        /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM4  */
#define   OSC32KCTRL_XOSC32K_CGM_CGM6_Val     _UINT32_(0x6)                                        /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM5  */
#define   OSC32KCTRL_XOSC32K_CGM_CGM7_Val     _UINT32_(0x7)                                        /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM6  */
#define   OSC32KCTRL_XOSC32K_CGM_CGM8_Val     _UINT32_(0x8)                                        /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM7  */
#define   OSC32KCTRL_XOSC32K_CGM_CGM9_Val     _UINT32_(0x9)                                        /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM8  */
#define   OSC32KCTRL_XOSC32K_CGM_CGM10_Val    _UINT32_(0xA)                                        /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM9  */
#define   OSC32KCTRL_XOSC32K_CGM_CGM11_Val    _UINT32_(0xB)                                        /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM10  */
#define   OSC32KCTRL_XOSC32K_CGM_CGM12_Val    _UINT32_(0xC)                                        /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM11  */
#define   OSC32KCTRL_XOSC32K_CGM_CGM13_Val    _UINT32_(0xD)                                        /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM12  */
#define   OSC32KCTRL_XOSC32K_CGM_CGM14_Val    _UINT32_(0xE)                                        /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM13  */
#define   OSC32KCTRL_XOSC32K_CGM_CGM15_Val    _UINT32_(0xF)                                        /* (OSC32KCTRL_XOSC32K) The highest Control Gain Mode value  */
#define OSC32KCTRL_XOSC32K_CGM_CGM0           (OSC32KCTRL_XOSC32K_CGM_CGM0_Val << OSC32KCTRL_XOSC32K_CGM_Pos) /* (OSC32KCTRL_XOSC32K) The lower Control Gain Mode value Position  */
#define OSC32KCTRL_XOSC32K_CGM_CGM1           (OSC32KCTRL_XOSC32K_CGM_CGM1_Val << OSC32KCTRL_XOSC32K_CGM_Pos) /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM0 Position  */
#define OSC32KCTRL_XOSC32K_CGM_CGM2           (OSC32KCTRL_XOSC32K_CGM_CGM2_Val << OSC32KCTRL_XOSC32K_CGM_Pos) /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM1 Position  */
#define OSC32KCTRL_XOSC32K_CGM_CGM3           (OSC32KCTRL_XOSC32K_CGM_CGM3_Val << OSC32KCTRL_XOSC32K_CGM_Pos) /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM2 Position  */
#define OSC32KCTRL_XOSC32K_CGM_CGM4           (OSC32KCTRL_XOSC32K_CGM_CGM4_Val << OSC32KCTRL_XOSC32K_CGM_Pos) /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM3 Position  */
#define OSC32KCTRL_XOSC32K_CGM_CGM5           (OSC32KCTRL_XOSC32K_CGM_CGM5_Val << OSC32KCTRL_XOSC32K_CGM_Pos) /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM4 Position  */
#define OSC32KCTRL_XOSC32K_CGM_CGM6           (OSC32KCTRL_XOSC32K_CGM_CGM6_Val << OSC32KCTRL_XOSC32K_CGM_Pos) /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM5 Position  */
#define OSC32KCTRL_XOSC32K_CGM_CGM7           (OSC32KCTRL_XOSC32K_CGM_CGM7_Val << OSC32KCTRL_XOSC32K_CGM_Pos) /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM6 Position  */
#define OSC32KCTRL_XOSC32K_CGM_CGM8           (OSC32KCTRL_XOSC32K_CGM_CGM8_Val << OSC32KCTRL_XOSC32K_CGM_Pos) /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM7 Position  */
#define OSC32KCTRL_XOSC32K_CGM_CGM9           (OSC32KCTRL_XOSC32K_CGM_CGM9_Val << OSC32KCTRL_XOSC32K_CGM_Pos) /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM8 Position  */
#define OSC32KCTRL_XOSC32K_CGM_CGM10          (OSC32KCTRL_XOSC32K_CGM_CGM10_Val << OSC32KCTRL_XOSC32K_CGM_Pos) /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM9 Position  */
#define OSC32KCTRL_XOSC32K_CGM_CGM11          (OSC32KCTRL_XOSC32K_CGM_CGM11_Val << OSC32KCTRL_XOSC32K_CGM_Pos) /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM10 Position  */
#define OSC32KCTRL_XOSC32K_CGM_CGM12          (OSC32KCTRL_XOSC32K_CGM_CGM12_Val << OSC32KCTRL_XOSC32K_CGM_Pos) /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM11 Position  */
#define OSC32KCTRL_XOSC32K_CGM_CGM13          (OSC32KCTRL_XOSC32K_CGM_CGM13_Val << OSC32KCTRL_XOSC32K_CGM_Pos) /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM12 Position  */
#define OSC32KCTRL_XOSC32K_CGM_CGM14          (OSC32KCTRL_XOSC32K_CGM_CGM14_Val << OSC32KCTRL_XOSC32K_CGM_Pos) /* (OSC32KCTRL_XOSC32K) A higher Control Gain Mode value than CGM13 Position  */
#define OSC32KCTRL_XOSC32K_CGM_CGM15          (OSC32KCTRL_XOSC32K_CGM_CGM15_Val << OSC32KCTRL_XOSC32K_CGM_Pos) /* (OSC32KCTRL_XOSC32K) The highest Control Gain Mode value Position  */
#define OSC32KCTRL_XOSC32K_CTRLX_Pos          _UINT32_(24)                                         /* (OSC32KCTRL_XOSC32K) Extended Control Position */
#define OSC32KCTRL_XOSC32K_CTRLX_Msk          (_UINT32_(0xF) << OSC32KCTRL_XOSC32K_CTRLX_Pos)      /* (OSC32KCTRL_XOSC32K) Extended Control Mask */
#define OSC32KCTRL_XOSC32K_CTRLX(value)       (OSC32KCTRL_XOSC32K_CTRLX_Msk & (_UINT32_(value) << OSC32KCTRL_XOSC32K_CTRLX_Pos)) /* Assigment of value for CTRLX in the OSC32KCTRL_XOSC32K register */
#define OSC32KCTRL_XOSC32K_Msk                _UINT32_(0x0F3F0F86)                                 /* (OSC32KCTRL_XOSC32K) Register Mask  */


/** \brief OSC32KCTRL register offsets definitions */
#define OSC32KCTRL_INTENCLR_REG_OFST   _UINT32_(0x00)      /* (OSC32KCTRL_INTENCLR) Interrupt Enable Clear Offset */
#define OSC32KCTRL_INTENSET_REG_OFST   _UINT32_(0x04)      /* (OSC32KCTRL_INTENSET) Interrupt Enable Set Offset */
#define OSC32KCTRL_INTFLAG_REG_OFST    _UINT32_(0x08)      /* (OSC32KCTRL_INTFLAG) Interrupt Flag Status and Clear Offset */
#define OSC32KCTRL_STATUS_REG_OFST     _UINT32_(0x0C)      /* (OSC32KCTRL_STATUS) Power and Clocks Status Offset */
#define OSC32KCTRL_CLKSELCTRL_REG_OFST _UINT32_(0x10)      /* (OSC32KCTRL_CLKSELCTRL) Clock Selection Control Offset */
#define OSC32KCTRL_CFDCTRL_REG_OFST    _UINT32_(0x14)      /* (OSC32KCTRL_CFDCTRL) Clock Failure Detector Control Offset */
#define OSC32KCTRL_EVCTRL_REG_OFST     _UINT32_(0x18)      /* (OSC32KCTRL_EVCTRL) Event Control Offset */
#define OSC32KCTRL_XOSC32K_REG_OFST    _UINT32_(0x1C)      /* (OSC32KCTRL_XOSC32K) 32kHz External Crystal Oscillator (XOSC32K) Control Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief OSC32KCTRL register API structure */
typedef struct
{  /* 32kHz Oscillators Control */
  __IO  uint32_t                       OSC32KCTRL_INTENCLR; /**< Offset: 0x00 (R/W  32) Interrupt Enable Clear */
  __IO  uint32_t                       OSC32KCTRL_INTENSET; /**< Offset: 0x04 (R/W  32) Interrupt Enable Set */
  __IO  uint32_t                       OSC32KCTRL_INTFLAG; /**< Offset: 0x08 (R/W  32) Interrupt Flag Status and Clear */
  __I   uint32_t                       OSC32KCTRL_STATUS;  /**< Offset: 0x0C (R/   32) Power and Clocks Status */
  __IO  uint32_t                       OSC32KCTRL_CLKSELCTRL; /**< Offset: 0x10 (R/W  32) Clock Selection Control */
  __IO  uint32_t                       OSC32KCTRL_CFDCTRL; /**< Offset: 0x14 (R/W  32) Clock Failure Detector Control */
  __IO  uint32_t                       OSC32KCTRL_EVCTRL;  /**< Offset: 0x18 (R/W  32) Event Control */
  __IO  uint32_t                       OSC32KCTRL_XOSC32K; /**< Offset: 0x1C (R/W  32) 32kHz External Crystal Oscillator (XOSC32K) Control */
} osc32kctrl_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA80_OSC32KCTRL_COMPONENT_H_ */
