/*
 * Component description for OSCCTRL
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
#ifndef _PIC32CZCA80_OSCCTRL_COMPONENT_H_
#define _PIC32CZCA80_OSCCTRL_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR OSCCTRL                                      */
/* ************************************************************************** */

/* -------- OSCCTRL_EVCTRL : (OSCCTRL Offset: 0x00) (R/W 32) Event Control -------- */
#define OSCCTRL_EVCTRL_RESETVALUE             _UINT32_(0x00)                                       /*  (OSCCTRL_EVCTRL) Event Control  Reset Value */

#define OSCCTRL_EVCTRL_CFDEO_Pos              _UINT32_(0)                                          /* (OSCCTRL_EVCTRL) Clock Failure Detector Event Output Enable Position */
#define OSCCTRL_EVCTRL_CFDEO_Msk              (_UINT32_(0x1) << OSCCTRL_EVCTRL_CFDEO_Pos)          /* (OSCCTRL_EVCTRL) Clock Failure Detector Event Output Enable Mask */
#define OSCCTRL_EVCTRL_CFDEO(value)           (OSCCTRL_EVCTRL_CFDEO_Msk & (_UINT32_(value) << OSCCTRL_EVCTRL_CFDEO_Pos)) /* Assigment of value for CFDEO in the OSCCTRL_EVCTRL register */
#define OSCCTRL_EVCTRL_Msk                    _UINT32_(0x00000001)                                 /* (OSCCTRL_EVCTRL) Register Mask  */


/* -------- OSCCTRL_INTENCLR : (OSCCTRL Offset: 0x04) (R/W 32) Interrupt Enable Clear -------- */
#define OSCCTRL_INTENCLR_RESETVALUE           _UINT32_(0x00)                                       /*  (OSCCTRL_INTENCLR) Interrupt Enable Clear  Reset Value */

#define OSCCTRL_INTENCLR_XOSCRDY_Pos          _UINT32_(0)                                          /* (OSCCTRL_INTENCLR) XOSC Ready Interrupt Enable Position */
#define OSCCTRL_INTENCLR_XOSCRDY_Msk          (_UINT32_(0x1) << OSCCTRL_INTENCLR_XOSCRDY_Pos)      /* (OSCCTRL_INTENCLR) XOSC Ready Interrupt Enable Mask */
#define OSCCTRL_INTENCLR_XOSCRDY(value)       (OSCCTRL_INTENCLR_XOSCRDY_Msk & (_UINT32_(value) << OSCCTRL_INTENCLR_XOSCRDY_Pos)) /* Assigment of value for XOSCRDY in the OSCCTRL_INTENCLR register */
#define OSCCTRL_INTENCLR_XOSCFAIL_Pos         _UINT32_(1)                                          /* (OSCCTRL_INTENCLR) XOSC Startup Failure Interrupt Enable Position */
#define OSCCTRL_INTENCLR_XOSCFAIL_Msk         (_UINT32_(0x1) << OSCCTRL_INTENCLR_XOSCFAIL_Pos)     /* (OSCCTRL_INTENCLR) XOSC Startup Failure Interrupt Enable Mask */
#define OSCCTRL_INTENCLR_XOSCFAIL(value)      (OSCCTRL_INTENCLR_XOSCFAIL_Msk & (_UINT32_(value) << OSCCTRL_INTENCLR_XOSCFAIL_Pos)) /* Assigment of value for XOSCFAIL in the OSCCTRL_INTENCLR register */
#define OSCCTRL_INTENCLR_CLKFAIL_Pos          _UINT32_(2)                                          /* (OSCCTRL_INTENCLR) XOSC Clock Failure Interrupt Enable Position */
#define OSCCTRL_INTENCLR_CLKFAIL_Msk          (_UINT32_(0x1) << OSCCTRL_INTENCLR_CLKFAIL_Pos)      /* (OSCCTRL_INTENCLR) XOSC Clock Failure Interrupt Enable Mask */
#define OSCCTRL_INTENCLR_CLKFAIL(value)       (OSCCTRL_INTENCLR_CLKFAIL_Msk & (_UINT32_(value) << OSCCTRL_INTENCLR_CLKFAIL_Pos)) /* Assigment of value for CLKFAIL in the OSCCTRL_INTENCLR register */
#define OSCCTRL_INTENCLR_DFLLRDY_Pos          _UINT32_(8)                                          /* (OSCCTRL_INTENCLR) DFLL Ready Interrupt Enable Position */
#define OSCCTRL_INTENCLR_DFLLRDY_Msk          (_UINT32_(0x1) << OSCCTRL_INTENCLR_DFLLRDY_Pos)      /* (OSCCTRL_INTENCLR) DFLL Ready Interrupt Enable Mask */
#define OSCCTRL_INTENCLR_DFLLRDY(value)       (OSCCTRL_INTENCLR_DFLLRDY_Msk & (_UINT32_(value) << OSCCTRL_INTENCLR_DFLLRDY_Pos)) /* Assigment of value for DFLLRDY in the OSCCTRL_INTENCLR register */
#define OSCCTRL_INTENCLR_DFLLLOCK_Pos         _UINT32_(9)                                          /* (OSCCTRL_INTENCLR) DFLL Lock Interrupt Enable Position */
#define OSCCTRL_INTENCLR_DFLLLOCK_Msk         (_UINT32_(0x1) << OSCCTRL_INTENCLR_DFLLLOCK_Pos)     /* (OSCCTRL_INTENCLR) DFLL Lock Interrupt Enable Mask */
#define OSCCTRL_INTENCLR_DFLLLOCK(value)      (OSCCTRL_INTENCLR_DFLLLOCK_Msk & (_UINT32_(value) << OSCCTRL_INTENCLR_DFLLLOCK_Pos)) /* Assigment of value for DFLLLOCK in the OSCCTRL_INTENCLR register */
#define OSCCTRL_INTENCLR_DFLLOVF_Pos          _UINT32_(10)                                         /* (OSCCTRL_INTENCLR) DFLL Tuner Overflow Interrupt Enable Position */
#define OSCCTRL_INTENCLR_DFLLOVF_Msk          (_UINT32_(0x1) << OSCCTRL_INTENCLR_DFLLOVF_Pos)      /* (OSCCTRL_INTENCLR) DFLL Tuner Overflow Interrupt Enable Mask */
#define OSCCTRL_INTENCLR_DFLLOVF(value)       (OSCCTRL_INTENCLR_DFLLOVF_Msk & (_UINT32_(value) << OSCCTRL_INTENCLR_DFLLOVF_Pos)) /* Assigment of value for DFLLOVF in the OSCCTRL_INTENCLR register */
#define OSCCTRL_INTENCLR_DFLLUNF_Pos          _UINT32_(11)                                         /* (OSCCTRL_INTENCLR) DFLL Tuner Underflow Interrupt Enable Position */
#define OSCCTRL_INTENCLR_DFLLUNF_Msk          (_UINT32_(0x1) << OSCCTRL_INTENCLR_DFLLUNF_Pos)      /* (OSCCTRL_INTENCLR) DFLL Tuner Underflow Interrupt Enable Mask */
#define OSCCTRL_INTENCLR_DFLLUNF(value)       (OSCCTRL_INTENCLR_DFLLUNF_Msk & (_UINT32_(value) << OSCCTRL_INTENCLR_DFLLUNF_Pos)) /* Assigment of value for DFLLUNF in the OSCCTRL_INTENCLR register */
#define OSCCTRL_INTENCLR_DFLLRCS_Pos          _UINT32_(12)                                         /* (OSCCTRL_INTENCLR) DFLL Reference Clock Stopped Interrupt Enable Position */
#define OSCCTRL_INTENCLR_DFLLRCS_Msk          (_UINT32_(0x1) << OSCCTRL_INTENCLR_DFLLRCS_Pos)      /* (OSCCTRL_INTENCLR) DFLL Reference Clock Stopped Interrupt Enable Mask */
#define OSCCTRL_INTENCLR_DFLLRCS(value)       (OSCCTRL_INTENCLR_DFLLRCS_Msk & (_UINT32_(value) << OSCCTRL_INTENCLR_DFLLRCS_Pos)) /* Assigment of value for DFLLRCS in the OSCCTRL_INTENCLR register */
#define OSCCTRL_INTENCLR_DFLLFAIL_Pos         _UINT32_(13)                                         /* (OSCCTRL_INTENCLR) DFLL Startup Failure Interrupt Enable Position */
#define OSCCTRL_INTENCLR_DFLLFAIL_Msk         (_UINT32_(0x1) << OSCCTRL_INTENCLR_DFLLFAIL_Pos)     /* (OSCCTRL_INTENCLR) DFLL Startup Failure Interrupt Enable Mask */
#define OSCCTRL_INTENCLR_DFLLFAIL(value)      (OSCCTRL_INTENCLR_DFLLFAIL_Msk & (_UINT32_(value) << OSCCTRL_INTENCLR_DFLLFAIL_Pos)) /* Assigment of value for DFLLFAIL in the OSCCTRL_INTENCLR register */
#define OSCCTRL_INTENCLR_PLL0LOCKR_Pos        _UINT32_(24)                                         /* (OSCCTRL_INTENCLR) PLL 0 Lock Rise Interrupt Enable Position */
#define OSCCTRL_INTENCLR_PLL0LOCKR_Msk        (_UINT32_(0x1) << OSCCTRL_INTENCLR_PLL0LOCKR_Pos)    /* (OSCCTRL_INTENCLR) PLL 0 Lock Rise Interrupt Enable Mask */
#define OSCCTRL_INTENCLR_PLL0LOCKR(value)     (OSCCTRL_INTENCLR_PLL0LOCKR_Msk & (_UINT32_(value) << OSCCTRL_INTENCLR_PLL0LOCKR_Pos)) /* Assigment of value for PLL0LOCKR in the OSCCTRL_INTENCLR register */
#define OSCCTRL_INTENCLR_PLL0LOCKF_Pos        _UINT32_(25)                                         /* (OSCCTRL_INTENCLR) PLL 0 Lock Fall Interrupt Enable Position */
#define OSCCTRL_INTENCLR_PLL0LOCKF_Msk        (_UINT32_(0x1) << OSCCTRL_INTENCLR_PLL0LOCKF_Pos)    /* (OSCCTRL_INTENCLR) PLL 0 Lock Fall Interrupt Enable Mask */
#define OSCCTRL_INTENCLR_PLL0LOCKF(value)     (OSCCTRL_INTENCLR_PLL0LOCKF_Msk & (_UINT32_(value) << OSCCTRL_INTENCLR_PLL0LOCKF_Pos)) /* Assigment of value for PLL0LOCKF in the OSCCTRL_INTENCLR register */
#define OSCCTRL_INTENCLR_PLL1LOCKR_Pos        _UINT32_(26)                                         /* (OSCCTRL_INTENCLR) PLL 1 Lock Rise Interrupt Enable Position */
#define OSCCTRL_INTENCLR_PLL1LOCKR_Msk        (_UINT32_(0x1) << OSCCTRL_INTENCLR_PLL1LOCKR_Pos)    /* (OSCCTRL_INTENCLR) PLL 1 Lock Rise Interrupt Enable Mask */
#define OSCCTRL_INTENCLR_PLL1LOCKR(value)     (OSCCTRL_INTENCLR_PLL1LOCKR_Msk & (_UINT32_(value) << OSCCTRL_INTENCLR_PLL1LOCKR_Pos)) /* Assigment of value for PLL1LOCKR in the OSCCTRL_INTENCLR register */
#define OSCCTRL_INTENCLR_PLL1LOCKF_Pos        _UINT32_(27)                                         /* (OSCCTRL_INTENCLR) PLL 1 Lock Fall Interrupt Enable Position */
#define OSCCTRL_INTENCLR_PLL1LOCKF_Msk        (_UINT32_(0x1) << OSCCTRL_INTENCLR_PLL1LOCKF_Pos)    /* (OSCCTRL_INTENCLR) PLL 1 Lock Fall Interrupt Enable Mask */
#define OSCCTRL_INTENCLR_PLL1LOCKF(value)     (OSCCTRL_INTENCLR_PLL1LOCKF_Msk & (_UINT32_(value) << OSCCTRL_INTENCLR_PLL1LOCKF_Pos)) /* Assigment of value for PLL1LOCKF in the OSCCTRL_INTENCLR register */
#define OSCCTRL_INTENCLR_Msk                  _UINT32_(0x0F003F07)                                 /* (OSCCTRL_INTENCLR) Register Mask  */


/* -------- OSCCTRL_INTENSET : (OSCCTRL Offset: 0x08) (R/W 32) Interrupt Enable Set -------- */
#define OSCCTRL_INTENSET_RESETVALUE           _UINT32_(0x00)                                       /*  (OSCCTRL_INTENSET) Interrupt Enable Set  Reset Value */

#define OSCCTRL_INTENSET_XOSCRDY_Pos          _UINT32_(0)                                          /* (OSCCTRL_INTENSET) XOSC Ready Interrupt Enable Position */
#define OSCCTRL_INTENSET_XOSCRDY_Msk          (_UINT32_(0x1) << OSCCTRL_INTENSET_XOSCRDY_Pos)      /* (OSCCTRL_INTENSET) XOSC Ready Interrupt Enable Mask */
#define OSCCTRL_INTENSET_XOSCRDY(value)       (OSCCTRL_INTENSET_XOSCRDY_Msk & (_UINT32_(value) << OSCCTRL_INTENSET_XOSCRDY_Pos)) /* Assigment of value for XOSCRDY in the OSCCTRL_INTENSET register */
#define OSCCTRL_INTENSET_XOSCFAIL_Pos         _UINT32_(1)                                          /* (OSCCTRL_INTENSET) XOSC Startup Failure Interrupt Enable Position */
#define OSCCTRL_INTENSET_XOSCFAIL_Msk         (_UINT32_(0x1) << OSCCTRL_INTENSET_XOSCFAIL_Pos)     /* (OSCCTRL_INTENSET) XOSC Startup Failure Interrupt Enable Mask */
#define OSCCTRL_INTENSET_XOSCFAIL(value)      (OSCCTRL_INTENSET_XOSCFAIL_Msk & (_UINT32_(value) << OSCCTRL_INTENSET_XOSCFAIL_Pos)) /* Assigment of value for XOSCFAIL in the OSCCTRL_INTENSET register */
#define OSCCTRL_INTENSET_CLKFAIL_Pos          _UINT32_(2)                                          /* (OSCCTRL_INTENSET) XOSC Clock Failure Interrupt Enable Position */
#define OSCCTRL_INTENSET_CLKFAIL_Msk          (_UINT32_(0x1) << OSCCTRL_INTENSET_CLKFAIL_Pos)      /* (OSCCTRL_INTENSET) XOSC Clock Failure Interrupt Enable Mask */
#define OSCCTRL_INTENSET_CLKFAIL(value)       (OSCCTRL_INTENSET_CLKFAIL_Msk & (_UINT32_(value) << OSCCTRL_INTENSET_CLKFAIL_Pos)) /* Assigment of value for CLKFAIL in the OSCCTRL_INTENSET register */
#define OSCCTRL_INTENSET_DFLLRDY_Pos          _UINT32_(8)                                          /* (OSCCTRL_INTENSET) DFLL Ready Interrupt Enable Position */
#define OSCCTRL_INTENSET_DFLLRDY_Msk          (_UINT32_(0x1) << OSCCTRL_INTENSET_DFLLRDY_Pos)      /* (OSCCTRL_INTENSET) DFLL Ready Interrupt Enable Mask */
#define OSCCTRL_INTENSET_DFLLRDY(value)       (OSCCTRL_INTENSET_DFLLRDY_Msk & (_UINT32_(value) << OSCCTRL_INTENSET_DFLLRDY_Pos)) /* Assigment of value for DFLLRDY in the OSCCTRL_INTENSET register */
#define OSCCTRL_INTENSET_DFLLLOCK_Pos         _UINT32_(9)                                          /* (OSCCTRL_INTENSET) DFLL Lock Interrupt Enable Position */
#define OSCCTRL_INTENSET_DFLLLOCK_Msk         (_UINT32_(0x1) << OSCCTRL_INTENSET_DFLLLOCK_Pos)     /* (OSCCTRL_INTENSET) DFLL Lock Interrupt Enable Mask */
#define OSCCTRL_INTENSET_DFLLLOCK(value)      (OSCCTRL_INTENSET_DFLLLOCK_Msk & (_UINT32_(value) << OSCCTRL_INTENSET_DFLLLOCK_Pos)) /* Assigment of value for DFLLLOCK in the OSCCTRL_INTENSET register */
#define OSCCTRL_INTENSET_DFLLOVF_Pos          _UINT32_(10)                                         /* (OSCCTRL_INTENSET) DFLL Tuner Overflow Interrupt Enable Position */
#define OSCCTRL_INTENSET_DFLLOVF_Msk          (_UINT32_(0x1) << OSCCTRL_INTENSET_DFLLOVF_Pos)      /* (OSCCTRL_INTENSET) DFLL Tuner Overflow Interrupt Enable Mask */
#define OSCCTRL_INTENSET_DFLLOVF(value)       (OSCCTRL_INTENSET_DFLLOVF_Msk & (_UINT32_(value) << OSCCTRL_INTENSET_DFLLOVF_Pos)) /* Assigment of value for DFLLOVF in the OSCCTRL_INTENSET register */
#define OSCCTRL_INTENSET_DFLLUNF_Pos          _UINT32_(11)                                         /* (OSCCTRL_INTENSET) DFLL Tuner Underflow Interrupt Enable Position */
#define OSCCTRL_INTENSET_DFLLUNF_Msk          (_UINT32_(0x1) << OSCCTRL_INTENSET_DFLLUNF_Pos)      /* (OSCCTRL_INTENSET) DFLL Tuner Underflow Interrupt Enable Mask */
#define OSCCTRL_INTENSET_DFLLUNF(value)       (OSCCTRL_INTENSET_DFLLUNF_Msk & (_UINT32_(value) << OSCCTRL_INTENSET_DFLLUNF_Pos)) /* Assigment of value for DFLLUNF in the OSCCTRL_INTENSET register */
#define OSCCTRL_INTENSET_DFLLRCS_Pos          _UINT32_(12)                                         /* (OSCCTRL_INTENSET) DFLL Reference Clock Stopped Interrupt Enable Position */
#define OSCCTRL_INTENSET_DFLLRCS_Msk          (_UINT32_(0x1) << OSCCTRL_INTENSET_DFLLRCS_Pos)      /* (OSCCTRL_INTENSET) DFLL Reference Clock Stopped Interrupt Enable Mask */
#define OSCCTRL_INTENSET_DFLLRCS(value)       (OSCCTRL_INTENSET_DFLLRCS_Msk & (_UINT32_(value) << OSCCTRL_INTENSET_DFLLRCS_Pos)) /* Assigment of value for DFLLRCS in the OSCCTRL_INTENSET register */
#define OSCCTRL_INTENSET_DFLLFAIL_Pos         _UINT32_(13)                                         /* (OSCCTRL_INTENSET) DFLL Startup Failure Interrupt Enable Position */
#define OSCCTRL_INTENSET_DFLLFAIL_Msk         (_UINT32_(0x1) << OSCCTRL_INTENSET_DFLLFAIL_Pos)     /* (OSCCTRL_INTENSET) DFLL Startup Failure Interrupt Enable Mask */
#define OSCCTRL_INTENSET_DFLLFAIL(value)      (OSCCTRL_INTENSET_DFLLFAIL_Msk & (_UINT32_(value) << OSCCTRL_INTENSET_DFLLFAIL_Pos)) /* Assigment of value for DFLLFAIL in the OSCCTRL_INTENSET register */
#define OSCCTRL_INTENSET_PLL0LOCKR_Pos        _UINT32_(24)                                         /* (OSCCTRL_INTENSET) PLL 0 Lock Rise Interrupt Enable Position */
#define OSCCTRL_INTENSET_PLL0LOCKR_Msk        (_UINT32_(0x1) << OSCCTRL_INTENSET_PLL0LOCKR_Pos)    /* (OSCCTRL_INTENSET) PLL 0 Lock Rise Interrupt Enable Mask */
#define OSCCTRL_INTENSET_PLL0LOCKR(value)     (OSCCTRL_INTENSET_PLL0LOCKR_Msk & (_UINT32_(value) << OSCCTRL_INTENSET_PLL0LOCKR_Pos)) /* Assigment of value for PLL0LOCKR in the OSCCTRL_INTENSET register */
#define OSCCTRL_INTENSET_PLL0LOCKF_Pos        _UINT32_(25)                                         /* (OSCCTRL_INTENSET) PLL 0 Lock Fall Interrupt Enable Position */
#define OSCCTRL_INTENSET_PLL0LOCKF_Msk        (_UINT32_(0x1) << OSCCTRL_INTENSET_PLL0LOCKF_Pos)    /* (OSCCTRL_INTENSET) PLL 0 Lock Fall Interrupt Enable Mask */
#define OSCCTRL_INTENSET_PLL0LOCKF(value)     (OSCCTRL_INTENSET_PLL0LOCKF_Msk & (_UINT32_(value) << OSCCTRL_INTENSET_PLL0LOCKF_Pos)) /* Assigment of value for PLL0LOCKF in the OSCCTRL_INTENSET register */
#define OSCCTRL_INTENSET_PLL1LOCKR_Pos        _UINT32_(26)                                         /* (OSCCTRL_INTENSET) PLL 1 Lock Rise Interrupt Enable Position */
#define OSCCTRL_INTENSET_PLL1LOCKR_Msk        (_UINT32_(0x1) << OSCCTRL_INTENSET_PLL1LOCKR_Pos)    /* (OSCCTRL_INTENSET) PLL 1 Lock Rise Interrupt Enable Mask */
#define OSCCTRL_INTENSET_PLL1LOCKR(value)     (OSCCTRL_INTENSET_PLL1LOCKR_Msk & (_UINT32_(value) << OSCCTRL_INTENSET_PLL1LOCKR_Pos)) /* Assigment of value for PLL1LOCKR in the OSCCTRL_INTENSET register */
#define OSCCTRL_INTENSET_PLL1LOCKF_Pos        _UINT32_(27)                                         /* (OSCCTRL_INTENSET) PLL 1 Lock Fall Interrupt Enable Position */
#define OSCCTRL_INTENSET_PLL1LOCKF_Msk        (_UINT32_(0x1) << OSCCTRL_INTENSET_PLL1LOCKF_Pos)    /* (OSCCTRL_INTENSET) PLL 1 Lock Fall Interrupt Enable Mask */
#define OSCCTRL_INTENSET_PLL1LOCKF(value)     (OSCCTRL_INTENSET_PLL1LOCKF_Msk & (_UINT32_(value) << OSCCTRL_INTENSET_PLL1LOCKF_Pos)) /* Assigment of value for PLL1LOCKF in the OSCCTRL_INTENSET register */
#define OSCCTRL_INTENSET_Msk                  _UINT32_(0x0F003F07)                                 /* (OSCCTRL_INTENSET) Register Mask  */


/* -------- OSCCTRL_INTFLAG : (OSCCTRL Offset: 0x0C) (R/W 32) Interrupt Flag Status and Clear -------- */
#define OSCCTRL_INTFLAG_RESETVALUE            _UINT32_(0x00)                                       /*  (OSCCTRL_INTFLAG) Interrupt Flag Status and Clear  Reset Value */

#define OSCCTRL_INTFLAG_XOSCRDY_Pos           _UINT32_(0)                                          /* (OSCCTRL_INTFLAG) XOSC Ready Position */
#define OSCCTRL_INTFLAG_XOSCRDY_Msk           (_UINT32_(0x1) << OSCCTRL_INTFLAG_XOSCRDY_Pos)       /* (OSCCTRL_INTFLAG) XOSC Ready Mask */
#define OSCCTRL_INTFLAG_XOSCRDY(value)        (OSCCTRL_INTFLAG_XOSCRDY_Msk & (_UINT32_(value) << OSCCTRL_INTFLAG_XOSCRDY_Pos)) /* Assigment of value for XOSCRDY in the OSCCTRL_INTFLAG register */
#define OSCCTRL_INTFLAG_XOSCFAIL_Pos          _UINT32_(1)                                          /* (OSCCTRL_INTFLAG) XOSC Startup Failure Position */
#define OSCCTRL_INTFLAG_XOSCFAIL_Msk          (_UINT32_(0x1) << OSCCTRL_INTFLAG_XOSCFAIL_Pos)      /* (OSCCTRL_INTFLAG) XOSC Startup Failure Mask */
#define OSCCTRL_INTFLAG_XOSCFAIL(value)       (OSCCTRL_INTFLAG_XOSCFAIL_Msk & (_UINT32_(value) << OSCCTRL_INTFLAG_XOSCFAIL_Pos)) /* Assigment of value for XOSCFAIL in the OSCCTRL_INTFLAG register */
#define OSCCTRL_INTFLAG_CLKFAIL_Pos           _UINT32_(2)                                          /* (OSCCTRL_INTFLAG) XOSC Clock Failure Position */
#define OSCCTRL_INTFLAG_CLKFAIL_Msk           (_UINT32_(0x1) << OSCCTRL_INTFLAG_CLKFAIL_Pos)       /* (OSCCTRL_INTFLAG) XOSC Clock Failure Mask */
#define OSCCTRL_INTFLAG_CLKFAIL(value)        (OSCCTRL_INTFLAG_CLKFAIL_Msk & (_UINT32_(value) << OSCCTRL_INTFLAG_CLKFAIL_Pos)) /* Assigment of value for CLKFAIL in the OSCCTRL_INTFLAG register */
#define OSCCTRL_INTFLAG_DFLLRDY_Pos           _UINT32_(8)                                          /* (OSCCTRL_INTFLAG) DFLL Ready Position */
#define OSCCTRL_INTFLAG_DFLLRDY_Msk           (_UINT32_(0x1) << OSCCTRL_INTFLAG_DFLLRDY_Pos)       /* (OSCCTRL_INTFLAG) DFLL Ready Mask */
#define OSCCTRL_INTFLAG_DFLLRDY(value)        (OSCCTRL_INTFLAG_DFLLRDY_Msk & (_UINT32_(value) << OSCCTRL_INTFLAG_DFLLRDY_Pos)) /* Assigment of value for DFLLRDY in the OSCCTRL_INTFLAG register */
#define OSCCTRL_INTFLAG_DFLLLOCK_Pos          _UINT32_(9)                                          /* (OSCCTRL_INTFLAG) DFLL Lock Position */
#define OSCCTRL_INTFLAG_DFLLLOCK_Msk          (_UINT32_(0x1) << OSCCTRL_INTFLAG_DFLLLOCK_Pos)      /* (OSCCTRL_INTFLAG) DFLL Lock Mask */
#define OSCCTRL_INTFLAG_DFLLLOCK(value)       (OSCCTRL_INTFLAG_DFLLLOCK_Msk & (_UINT32_(value) << OSCCTRL_INTFLAG_DFLLLOCK_Pos)) /* Assigment of value for DFLLLOCK in the OSCCTRL_INTFLAG register */
#define OSCCTRL_INTFLAG_DFLLOVF_Pos           _UINT32_(10)                                         /* (OSCCTRL_INTFLAG) DFLL Tuner Overflow Position */
#define OSCCTRL_INTFLAG_DFLLOVF_Msk           (_UINT32_(0x1) << OSCCTRL_INTFLAG_DFLLOVF_Pos)       /* (OSCCTRL_INTFLAG) DFLL Tuner Overflow Mask */
#define OSCCTRL_INTFLAG_DFLLOVF(value)        (OSCCTRL_INTFLAG_DFLLOVF_Msk & (_UINT32_(value) << OSCCTRL_INTFLAG_DFLLOVF_Pos)) /* Assigment of value for DFLLOVF in the OSCCTRL_INTFLAG register */
#define OSCCTRL_INTFLAG_DFLLUNF_Pos           _UINT32_(11)                                         /* (OSCCTRL_INTFLAG) DFLL Tuner Underflow Position */
#define OSCCTRL_INTFLAG_DFLLUNF_Msk           (_UINT32_(0x1) << OSCCTRL_INTFLAG_DFLLUNF_Pos)       /* (OSCCTRL_INTFLAG) DFLL Tuner Underflow Mask */
#define OSCCTRL_INTFLAG_DFLLUNF(value)        (OSCCTRL_INTFLAG_DFLLUNF_Msk & (_UINT32_(value) << OSCCTRL_INTFLAG_DFLLUNF_Pos)) /* Assigment of value for DFLLUNF in the OSCCTRL_INTFLAG register */
#define OSCCTRL_INTFLAG_DFLLRCS_Pos           _UINT32_(12)                                         /* (OSCCTRL_INTFLAG) DFLL Reference Clock Stopped Position */
#define OSCCTRL_INTFLAG_DFLLRCS_Msk           (_UINT32_(0x1) << OSCCTRL_INTFLAG_DFLLRCS_Pos)       /* (OSCCTRL_INTFLAG) DFLL Reference Clock Stopped Mask */
#define OSCCTRL_INTFLAG_DFLLRCS(value)        (OSCCTRL_INTFLAG_DFLLRCS_Msk & (_UINT32_(value) << OSCCTRL_INTFLAG_DFLLRCS_Pos)) /* Assigment of value for DFLLRCS in the OSCCTRL_INTFLAG register */
#define OSCCTRL_INTFLAG_DFLLFAIL_Pos          _UINT32_(13)                                         /* (OSCCTRL_INTFLAG) DFLL Startup Failure Position */
#define OSCCTRL_INTFLAG_DFLLFAIL_Msk          (_UINT32_(0x1) << OSCCTRL_INTFLAG_DFLLFAIL_Pos)      /* (OSCCTRL_INTFLAG) DFLL Startup Failure Mask */
#define OSCCTRL_INTFLAG_DFLLFAIL(value)       (OSCCTRL_INTFLAG_DFLLFAIL_Msk & (_UINT32_(value) << OSCCTRL_INTFLAG_DFLLFAIL_Pos)) /* Assigment of value for DFLLFAIL in the OSCCTRL_INTFLAG register */
#define OSCCTRL_INTFLAG_PLL0LOCKR_Pos         _UINT32_(24)                                         /* (OSCCTRL_INTFLAG) PLL 0 Lock Rise Position */
#define OSCCTRL_INTFLAG_PLL0LOCKR_Msk         (_UINT32_(0x1) << OSCCTRL_INTFLAG_PLL0LOCKR_Pos)     /* (OSCCTRL_INTFLAG) PLL 0 Lock Rise Mask */
#define OSCCTRL_INTFLAG_PLL0LOCKR(value)      (OSCCTRL_INTFLAG_PLL0LOCKR_Msk & (_UINT32_(value) << OSCCTRL_INTFLAG_PLL0LOCKR_Pos)) /* Assigment of value for PLL0LOCKR in the OSCCTRL_INTFLAG register */
#define OSCCTRL_INTFLAG_PLL0LOCKF_Pos         _UINT32_(25)                                         /* (OSCCTRL_INTFLAG) PLL 0 Lock Fall Position */
#define OSCCTRL_INTFLAG_PLL0LOCKF_Msk         (_UINT32_(0x1) << OSCCTRL_INTFLAG_PLL0LOCKF_Pos)     /* (OSCCTRL_INTFLAG) PLL 0 Lock Fall Mask */
#define OSCCTRL_INTFLAG_PLL0LOCKF(value)      (OSCCTRL_INTFLAG_PLL0LOCKF_Msk & (_UINT32_(value) << OSCCTRL_INTFLAG_PLL0LOCKF_Pos)) /* Assigment of value for PLL0LOCKF in the OSCCTRL_INTFLAG register */
#define OSCCTRL_INTFLAG_PLL1LOCKR_Pos         _UINT32_(26)                                         /* (OSCCTRL_INTFLAG) PLL 1 Lock Rise Position */
#define OSCCTRL_INTFLAG_PLL1LOCKR_Msk         (_UINT32_(0x1) << OSCCTRL_INTFLAG_PLL1LOCKR_Pos)     /* (OSCCTRL_INTFLAG) PLL 1 Lock Rise Mask */
#define OSCCTRL_INTFLAG_PLL1LOCKR(value)      (OSCCTRL_INTFLAG_PLL1LOCKR_Msk & (_UINT32_(value) << OSCCTRL_INTFLAG_PLL1LOCKR_Pos)) /* Assigment of value for PLL1LOCKR in the OSCCTRL_INTFLAG register */
#define OSCCTRL_INTFLAG_PLL1LOCKF_Pos         _UINT32_(27)                                         /* (OSCCTRL_INTFLAG) PLL 1 Lock Fall Position */
#define OSCCTRL_INTFLAG_PLL1LOCKF_Msk         (_UINT32_(0x1) << OSCCTRL_INTFLAG_PLL1LOCKF_Pos)     /* (OSCCTRL_INTFLAG) PLL 1 Lock Fall Mask */
#define OSCCTRL_INTFLAG_PLL1LOCKF(value)      (OSCCTRL_INTFLAG_PLL1LOCKF_Msk & (_UINT32_(value) << OSCCTRL_INTFLAG_PLL1LOCKF_Pos)) /* Assigment of value for PLL1LOCKF in the OSCCTRL_INTFLAG register */
#define OSCCTRL_INTFLAG_Msk                   _UINT32_(0x0F003F07)                                 /* (OSCCTRL_INTFLAG) Register Mask  */


/* -------- OSCCTRL_STATUS : (OSCCTRL Offset: 0x10) ( R/ 32) Status -------- */
#define OSCCTRL_STATUS_RESETVALUE             _UINT32_(0x00)                                       /*  (OSCCTRL_STATUS) Status  Reset Value */

#define OSCCTRL_STATUS_XOSCRDY_Pos            _UINT32_(0)                                          /* (OSCCTRL_STATUS) XOSC Ready Position */
#define OSCCTRL_STATUS_XOSCRDY_Msk            (_UINT32_(0x1) << OSCCTRL_STATUS_XOSCRDY_Pos)        /* (OSCCTRL_STATUS) XOSC Ready Mask */
#define OSCCTRL_STATUS_XOSCRDY(value)         (OSCCTRL_STATUS_XOSCRDY_Msk & (_UINT32_(value) << OSCCTRL_STATUS_XOSCRDY_Pos)) /* Assigment of value for XOSCRDY in the OSCCTRL_STATUS register */
#define OSCCTRL_STATUS_XOSCFAIL_Pos           _UINT32_(1)                                          /* (OSCCTRL_STATUS) XOSC Startup Failure Position */
#define OSCCTRL_STATUS_XOSCFAIL_Msk           (_UINT32_(0x1) << OSCCTRL_STATUS_XOSCFAIL_Pos)       /* (OSCCTRL_STATUS) XOSC Startup Failure Mask */
#define OSCCTRL_STATUS_XOSCFAIL(value)        (OSCCTRL_STATUS_XOSCFAIL_Msk & (_UINT32_(value) << OSCCTRL_STATUS_XOSCFAIL_Pos)) /* Assigment of value for XOSCFAIL in the OSCCTRL_STATUS register */
#define OSCCTRL_STATUS_CLKFAIL_Pos            _UINT32_(2)                                          /* (OSCCTRL_STATUS) XOSC Clock Failure Position */
#define OSCCTRL_STATUS_CLKFAIL_Msk            (_UINT32_(0x1) << OSCCTRL_STATUS_CLKFAIL_Pos)        /* (OSCCTRL_STATUS) XOSC Clock Failure Mask */
#define OSCCTRL_STATUS_CLKFAIL(value)         (OSCCTRL_STATUS_CLKFAIL_Msk & (_UINT32_(value) << OSCCTRL_STATUS_CLKFAIL_Pos)) /* Assigment of value for CLKFAIL in the OSCCTRL_STATUS register */
#define OSCCTRL_STATUS_XOSCCKSW_Pos           _UINT32_(3)                                          /* (OSCCTRL_STATUS) XOSC Clock Switch Position */
#define OSCCTRL_STATUS_XOSCCKSW_Msk           (_UINT32_(0x1) << OSCCTRL_STATUS_XOSCCKSW_Pos)       /* (OSCCTRL_STATUS) XOSC Clock Switch Mask */
#define OSCCTRL_STATUS_XOSCCKSW(value)        (OSCCTRL_STATUS_XOSCCKSW_Msk & (_UINT32_(value) << OSCCTRL_STATUS_XOSCCKSW_Pos)) /* Assigment of value for XOSCCKSW in the OSCCTRL_STATUS register */
#define OSCCTRL_STATUS_DFLLRDY_Pos            _UINT32_(8)                                          /* (OSCCTRL_STATUS) DFLL Ready Position */
#define OSCCTRL_STATUS_DFLLRDY_Msk            (_UINT32_(0x1) << OSCCTRL_STATUS_DFLLRDY_Pos)        /* (OSCCTRL_STATUS) DFLL Ready Mask */
#define OSCCTRL_STATUS_DFLLRDY(value)         (OSCCTRL_STATUS_DFLLRDY_Msk & (_UINT32_(value) << OSCCTRL_STATUS_DFLLRDY_Pos)) /* Assigment of value for DFLLRDY in the OSCCTRL_STATUS register */
#define OSCCTRL_STATUS_DFLLLOCK_Pos           _UINT32_(9)                                          /* (OSCCTRL_STATUS) DFLL Lock Position */
#define OSCCTRL_STATUS_DFLLLOCK_Msk           (_UINT32_(0x1) << OSCCTRL_STATUS_DFLLLOCK_Pos)       /* (OSCCTRL_STATUS) DFLL Lock Mask */
#define OSCCTRL_STATUS_DFLLLOCK(value)        (OSCCTRL_STATUS_DFLLLOCK_Msk & (_UINT32_(value) << OSCCTRL_STATUS_DFLLLOCK_Pos)) /* Assigment of value for DFLLLOCK in the OSCCTRL_STATUS register */
#define OSCCTRL_STATUS_DFLLOVF_Pos            _UINT32_(10)                                         /* (OSCCTRL_STATUS) DFLL Tuner Overflow Position */
#define OSCCTRL_STATUS_DFLLOVF_Msk            (_UINT32_(0x1) << OSCCTRL_STATUS_DFLLOVF_Pos)        /* (OSCCTRL_STATUS) DFLL Tuner Overflow Mask */
#define OSCCTRL_STATUS_DFLLOVF(value)         (OSCCTRL_STATUS_DFLLOVF_Msk & (_UINT32_(value) << OSCCTRL_STATUS_DFLLOVF_Pos)) /* Assigment of value for DFLLOVF in the OSCCTRL_STATUS register */
#define OSCCTRL_STATUS_DFLLUNF_Pos            _UINT32_(11)                                         /* (OSCCTRL_STATUS) DFLL Tuner Underflow Position */
#define OSCCTRL_STATUS_DFLLUNF_Msk            (_UINT32_(0x1) << OSCCTRL_STATUS_DFLLUNF_Pos)        /* (OSCCTRL_STATUS) DFLL Tuner Underflow Mask */
#define OSCCTRL_STATUS_DFLLUNF(value)         (OSCCTRL_STATUS_DFLLUNF_Msk & (_UINT32_(value) << OSCCTRL_STATUS_DFLLUNF_Pos)) /* Assigment of value for DFLLUNF in the OSCCTRL_STATUS register */
#define OSCCTRL_STATUS_DFLLRCS_Pos            _UINT32_(12)                                         /* (OSCCTRL_STATUS) DFLL Reference Clock Stopped Position */
#define OSCCTRL_STATUS_DFLLRCS_Msk            (_UINT32_(0x1) << OSCCTRL_STATUS_DFLLRCS_Pos)        /* (OSCCTRL_STATUS) DFLL Reference Clock Stopped Mask */
#define OSCCTRL_STATUS_DFLLRCS(value)         (OSCCTRL_STATUS_DFLLRCS_Msk & (_UINT32_(value) << OSCCTRL_STATUS_DFLLRCS_Pos)) /* Assigment of value for DFLLRCS in the OSCCTRL_STATUS register */
#define OSCCTRL_STATUS_DFLLFAIL_Pos           _UINT32_(13)                                         /* (OSCCTRL_STATUS) DFLL Startup Failure Position */
#define OSCCTRL_STATUS_DFLLFAIL_Msk           (_UINT32_(0x1) << OSCCTRL_STATUS_DFLLFAIL_Pos)       /* (OSCCTRL_STATUS) DFLL Startup Failure Mask */
#define OSCCTRL_STATUS_DFLLFAIL(value)        (OSCCTRL_STATUS_DFLLFAIL_Msk & (_UINT32_(value) << OSCCTRL_STATUS_DFLLFAIL_Pos)) /* Assigment of value for DFLLFAIL in the OSCCTRL_STATUS register */
#define OSCCTRL_STATUS_PLL0LOCK_Pos           _UINT32_(24)                                         /* (OSCCTRL_STATUS) PLL 0 Lock Position */
#define OSCCTRL_STATUS_PLL0LOCK_Msk           (_UINT32_(0x1) << OSCCTRL_STATUS_PLL0LOCK_Pos)       /* (OSCCTRL_STATUS) PLL 0 Lock Mask */
#define OSCCTRL_STATUS_PLL0LOCK(value)        (OSCCTRL_STATUS_PLL0LOCK_Msk & (_UINT32_(value) << OSCCTRL_STATUS_PLL0LOCK_Pos)) /* Assigment of value for PLL0LOCK in the OSCCTRL_STATUS register */
#define OSCCTRL_STATUS_PLL1LOCK_Pos           _UINT32_(25)                                         /* (OSCCTRL_STATUS) PLL 1 Lock Position */
#define OSCCTRL_STATUS_PLL1LOCK_Msk           (_UINT32_(0x1) << OSCCTRL_STATUS_PLL1LOCK_Pos)       /* (OSCCTRL_STATUS) PLL 1 Lock Mask */
#define OSCCTRL_STATUS_PLL1LOCK(value)        (OSCCTRL_STATUS_PLL1LOCK_Msk & (_UINT32_(value) << OSCCTRL_STATUS_PLL1LOCK_Pos)) /* Assigment of value for PLL1LOCK in the OSCCTRL_STATUS register */
#define OSCCTRL_STATUS_Msk                    _UINT32_(0x03003F0F)                                 /* (OSCCTRL_STATUS) Register Mask  */


/* -------- OSCCTRL_XOSCCTRLA : (OSCCTRL Offset: 0x14) (R/W 32) External Multipurpose Crystal Oscillator Control A -------- */
#define OSCCTRL_XOSCCTRLA_RESETVALUE          _UINT32_(0xD00)                                      /*  (OSCCTRL_XOSCCTRLA) External Multipurpose Crystal Oscillator Control A  Reset Value */

#define OSCCTRL_XOSCCTRLA_ENABLE_Pos          _UINT32_(1)                                          /* (OSCCTRL_XOSCCTRLA) Oscillator Enable Position */
#define OSCCTRL_XOSCCTRLA_ENABLE_Msk          (_UINT32_(0x1) << OSCCTRL_XOSCCTRLA_ENABLE_Pos)      /* (OSCCTRL_XOSCCTRLA) Oscillator Enable Mask */
#define OSCCTRL_XOSCCTRLA_ENABLE(value)       (OSCCTRL_XOSCCTRLA_ENABLE_Msk & (_UINT32_(value) << OSCCTRL_XOSCCTRLA_ENABLE_Pos)) /* Assigment of value for ENABLE in the OSCCTRL_XOSCCTRLA register */
#define OSCCTRL_XOSCCTRLA_AGC_Pos             _UINT32_(2)                                          /* (OSCCTRL_XOSCCTRLA) Auto Gain Control Loop Enable Position */
#define OSCCTRL_XOSCCTRLA_AGC_Msk             (_UINT32_(0x1) << OSCCTRL_XOSCCTRLA_AGC_Pos)         /* (OSCCTRL_XOSCCTRLA) Auto Gain Control Loop Enable Mask */
#define OSCCTRL_XOSCCTRLA_AGC(value)          (OSCCTRL_XOSCCTRLA_AGC_Msk & (_UINT32_(value) << OSCCTRL_XOSCCTRLA_AGC_Pos)) /* Assigment of value for AGC in the OSCCTRL_XOSCCTRLA register */
#define OSCCTRL_XOSCCTRLA_XTALEN_Pos          _UINT32_(3)                                          /* (OSCCTRL_XOSCCTRLA) Crystal Oscillator Enable Position */
#define OSCCTRL_XOSCCTRLA_XTALEN_Msk          (_UINT32_(0x1) << OSCCTRL_XOSCCTRLA_XTALEN_Pos)      /* (OSCCTRL_XOSCCTRLA) Crystal Oscillator Enable Mask */
#define OSCCTRL_XOSCCTRLA_XTALEN(value)       (OSCCTRL_XOSCCTRLA_XTALEN_Msk & (_UINT32_(value) << OSCCTRL_XOSCCTRLA_XTALEN_Pos)) /* Assigment of value for XTALEN in the OSCCTRL_XOSCCTRLA register */
#define OSCCTRL_XOSCCTRLA_CFDEN_Pos           _UINT32_(4)                                          /* (OSCCTRL_XOSCCTRLA) Clock Failure Detector Enable Position */
#define OSCCTRL_XOSCCTRLA_CFDEN_Msk           (_UINT32_(0x1) << OSCCTRL_XOSCCTRLA_CFDEN_Pos)       /* (OSCCTRL_XOSCCTRLA) Clock Failure Detector Enable Mask */
#define OSCCTRL_XOSCCTRLA_CFDEN(value)        (OSCCTRL_XOSCCTRLA_CFDEN_Msk & (_UINT32_(value) << OSCCTRL_XOSCCTRLA_CFDEN_Pos)) /* Assigment of value for CFDEN in the OSCCTRL_XOSCCTRLA register */
#define OSCCTRL_XOSCCTRLA_SWBEN_Pos           _UINT32_(5)                                          /* (OSCCTRL_XOSCCTRLA) Xosc Clock Switch Back Enable Position */
#define OSCCTRL_XOSCCTRLA_SWBEN_Msk           (_UINT32_(0x1) << OSCCTRL_XOSCCTRLA_SWBEN_Pos)       /* (OSCCTRL_XOSCCTRLA) Xosc Clock Switch Back Enable Mask */
#define OSCCTRL_XOSCCTRLA_SWBEN(value)        (OSCCTRL_XOSCCTRLA_SWBEN_Msk & (_UINT32_(value) << OSCCTRL_XOSCCTRLA_SWBEN_Pos)) /* Assigment of value for SWBEN in the OSCCTRL_XOSCCTRLA register */
#define OSCCTRL_XOSCCTRLA_ONDEMAND_Pos        _UINT32_(7)                                          /* (OSCCTRL_XOSCCTRLA) On Demand Control Position */
#define OSCCTRL_XOSCCTRLA_ONDEMAND_Msk        (_UINT32_(0x1) << OSCCTRL_XOSCCTRLA_ONDEMAND_Pos)    /* (OSCCTRL_XOSCCTRLA) On Demand Control Mask */
#define OSCCTRL_XOSCCTRLA_ONDEMAND(value)     (OSCCTRL_XOSCCTRLA_ONDEMAND_Msk & (_UINT32_(value) << OSCCTRL_XOSCCTRLA_ONDEMAND_Pos)) /* Assigment of value for ONDEMAND in the OSCCTRL_XOSCCTRLA register */
#define OSCCTRL_XOSCCTRLA_STARTUP_Pos         _UINT32_(8)                                          /* (OSCCTRL_XOSCCTRLA) Start-Up Time Position */
#define OSCCTRL_XOSCCTRLA_STARTUP_Msk         (_UINT32_(0xF) << OSCCTRL_XOSCCTRLA_STARTUP_Pos)     /* (OSCCTRL_XOSCCTRLA) Start-Up Time Mask */
#define OSCCTRL_XOSCCTRLA_STARTUP(value)      (OSCCTRL_XOSCCTRLA_STARTUP_Msk & (_UINT32_(value) << OSCCTRL_XOSCCTRLA_STARTUP_Pos)) /* Assigment of value for STARTUP in the OSCCTRL_XOSCCTRLA register */
#define   OSCCTRL_XOSCCTRLA_STARTUP_CYCLE1_Val _UINT32_(0x0)                                        /* (OSCCTRL_XOSCCTRLA) 31 us  */
#define   OSCCTRL_XOSCCTRLA_STARTUP_CYCLE2_Val _UINT32_(0x1)                                        /* (OSCCTRL_XOSCCTRLA) 61 us  */
#define   OSCCTRL_XOSCCTRLA_STARTUP_CYCLE4_Val _UINT32_(0x2)                                        /* (OSCCTRL_XOSCCTRLA) 122 us  */
#define   OSCCTRL_XOSCCTRLA_STARTUP_CYCLE8_Val _UINT32_(0x3)                                        /* (OSCCTRL_XOSCCTRLA) 244 us  */
#define   OSCCTRL_XOSCCTRLA_STARTUP_CYCLE16_Val _UINT32_(0x4)                                        /* (OSCCTRL_XOSCCTRLA) 488 us  */
#define   OSCCTRL_XOSCCTRLA_STARTUP_CYCLE32_Val _UINT32_(0x5)                                        /* (OSCCTRL_XOSCCTRLA) 977 us  */
#define   OSCCTRL_XOSCCTRLA_STARTUP_CYCLE64_Val _UINT32_(0x6)                                        /* (OSCCTRL_XOSCCTRLA) 1953 us  */
#define   OSCCTRL_XOSCCTRLA_STARTUP_CYCLE128_Val _UINT32_(0x7)                                        /* (OSCCTRL_XOSCCTRLA) 3906 us  */
#define   OSCCTRL_XOSCCTRLA_STARTUP_CYCLE256_Val _UINT32_(0x8)                                        /* (OSCCTRL_XOSCCTRLA) 7813 us  */
#define   OSCCTRL_XOSCCTRLA_STARTUP_CYCLE512_Val _UINT32_(0x9)                                        /* (OSCCTRL_XOSCCTRLA) 15625 us  */
#define   OSCCTRL_XOSCCTRLA_STARTUP_CYCLE1024_Val _UINT32_(0xA)                                        /* (OSCCTRL_XOSCCTRLA) 31250 us  */
#define   OSCCTRL_XOSCCTRLA_STARTUP_CYCLE2048_Val _UINT32_(0xB)                                        /* (OSCCTRL_XOSCCTRLA) 62500 us  */
#define   OSCCTRL_XOSCCTRLA_STARTUP_CYCLE4096_Val _UINT32_(0xC)                                        /* (OSCCTRL_XOSCCTRLA) 125000 us  */
#define   OSCCTRL_XOSCCTRLA_STARTUP_CYCLE8192_Val _UINT32_(0xD)                                        /* (OSCCTRL_XOSCCTRLA) 250000 us  */
#define   OSCCTRL_XOSCCTRLA_STARTUP_CYCLE16384_Val _UINT32_(0xE)                                        /* (OSCCTRL_XOSCCTRLA) 500000 us  */
#define   OSCCTRL_XOSCCTRLA_STARTUP_CYCLE32768_Val _UINT32_(0xF)                                        /* (OSCCTRL_XOSCCTRLA) 1000000 us  */
#define OSCCTRL_XOSCCTRLA_STARTUP_CYCLE1      (OSCCTRL_XOSCCTRLA_STARTUP_CYCLE1_Val << OSCCTRL_XOSCCTRLA_STARTUP_Pos) /* (OSCCTRL_XOSCCTRLA) 31 us Position  */
#define OSCCTRL_XOSCCTRLA_STARTUP_CYCLE2      (OSCCTRL_XOSCCTRLA_STARTUP_CYCLE2_Val << OSCCTRL_XOSCCTRLA_STARTUP_Pos) /* (OSCCTRL_XOSCCTRLA) 61 us Position  */
#define OSCCTRL_XOSCCTRLA_STARTUP_CYCLE4      (OSCCTRL_XOSCCTRLA_STARTUP_CYCLE4_Val << OSCCTRL_XOSCCTRLA_STARTUP_Pos) /* (OSCCTRL_XOSCCTRLA) 122 us Position  */
#define OSCCTRL_XOSCCTRLA_STARTUP_CYCLE8      (OSCCTRL_XOSCCTRLA_STARTUP_CYCLE8_Val << OSCCTRL_XOSCCTRLA_STARTUP_Pos) /* (OSCCTRL_XOSCCTRLA) 244 us Position  */
#define OSCCTRL_XOSCCTRLA_STARTUP_CYCLE16     (OSCCTRL_XOSCCTRLA_STARTUP_CYCLE16_Val << OSCCTRL_XOSCCTRLA_STARTUP_Pos) /* (OSCCTRL_XOSCCTRLA) 488 us Position  */
#define OSCCTRL_XOSCCTRLA_STARTUP_CYCLE32     (OSCCTRL_XOSCCTRLA_STARTUP_CYCLE32_Val << OSCCTRL_XOSCCTRLA_STARTUP_Pos) /* (OSCCTRL_XOSCCTRLA) 977 us Position  */
#define OSCCTRL_XOSCCTRLA_STARTUP_CYCLE64     (OSCCTRL_XOSCCTRLA_STARTUP_CYCLE64_Val << OSCCTRL_XOSCCTRLA_STARTUP_Pos) /* (OSCCTRL_XOSCCTRLA) 1953 us Position  */
#define OSCCTRL_XOSCCTRLA_STARTUP_CYCLE128    (OSCCTRL_XOSCCTRLA_STARTUP_CYCLE128_Val << OSCCTRL_XOSCCTRLA_STARTUP_Pos) /* (OSCCTRL_XOSCCTRLA) 3906 us Position  */
#define OSCCTRL_XOSCCTRLA_STARTUP_CYCLE256    (OSCCTRL_XOSCCTRLA_STARTUP_CYCLE256_Val << OSCCTRL_XOSCCTRLA_STARTUP_Pos) /* (OSCCTRL_XOSCCTRLA) 7813 us Position  */
#define OSCCTRL_XOSCCTRLA_STARTUP_CYCLE512    (OSCCTRL_XOSCCTRLA_STARTUP_CYCLE512_Val << OSCCTRL_XOSCCTRLA_STARTUP_Pos) /* (OSCCTRL_XOSCCTRLA) 15625 us Position  */
#define OSCCTRL_XOSCCTRLA_STARTUP_CYCLE1024   (OSCCTRL_XOSCCTRLA_STARTUP_CYCLE1024_Val << OSCCTRL_XOSCCTRLA_STARTUP_Pos) /* (OSCCTRL_XOSCCTRLA) 31250 us Position  */
#define OSCCTRL_XOSCCTRLA_STARTUP_CYCLE2048   (OSCCTRL_XOSCCTRLA_STARTUP_CYCLE2048_Val << OSCCTRL_XOSCCTRLA_STARTUP_Pos) /* (OSCCTRL_XOSCCTRLA) 62500 us Position  */
#define OSCCTRL_XOSCCTRLA_STARTUP_CYCLE4096   (OSCCTRL_XOSCCTRLA_STARTUP_CYCLE4096_Val << OSCCTRL_XOSCCTRLA_STARTUP_Pos) /* (OSCCTRL_XOSCCTRLA) 125000 us Position  */
#define OSCCTRL_XOSCCTRLA_STARTUP_CYCLE8192   (OSCCTRL_XOSCCTRLA_STARTUP_CYCLE8192_Val << OSCCTRL_XOSCCTRLA_STARTUP_Pos) /* (OSCCTRL_XOSCCTRLA) 250000 us Position  */
#define OSCCTRL_XOSCCTRLA_STARTUP_CYCLE16384  (OSCCTRL_XOSCCTRLA_STARTUP_CYCLE16384_Val << OSCCTRL_XOSCCTRLA_STARTUP_Pos) /* (OSCCTRL_XOSCCTRLA) 500000 us Position  */
#define OSCCTRL_XOSCCTRLA_STARTUP_CYCLE32768  (OSCCTRL_XOSCCTRLA_STARTUP_CYCLE32768_Val << OSCCTRL_XOSCCTRLA_STARTUP_Pos) /* (OSCCTRL_XOSCCTRLA) 1000000 us Position  */
#define OSCCTRL_XOSCCTRLA_CFDPRESC_Pos        _UINT32_(16)                                         /* (OSCCTRL_XOSCCTRLA) Clock Failure Detector Prescaler Position */
#define OSCCTRL_XOSCCTRLA_CFDPRESC_Msk        (_UINT32_(0xF) << OSCCTRL_XOSCCTRLA_CFDPRESC_Pos)    /* (OSCCTRL_XOSCCTRLA) Clock Failure Detector Prescaler Mask */
#define OSCCTRL_XOSCCTRLA_CFDPRESC(value)     (OSCCTRL_XOSCCTRLA_CFDPRESC_Msk & (_UINT32_(value) << OSCCTRL_XOSCCTRLA_CFDPRESC_Pos)) /* Assigment of value for CFDPRESC in the OSCCTRL_XOSCCTRLA register */
#define   OSCCTRL_XOSCCTRLA_CFDPRESC_DIV1_Val _UINT32_(0x0)                                        /* (OSCCTRL_XOSCCTRLA) 48 MHz  */
#define   OSCCTRL_XOSCCTRLA_CFDPRESC_DIV2_Val _UINT32_(0x1)                                        /* (OSCCTRL_XOSCCTRLA) 24 MHz  */
#define   OSCCTRL_XOSCCTRLA_CFDPRESC_DIV4_Val _UINT32_(0x2)                                        /* (OSCCTRL_XOSCCTRLA) 12 MHz  */
#define   OSCCTRL_XOSCCTRLA_CFDPRESC_DIV8_Val _UINT32_(0x3)                                        /* (OSCCTRL_XOSCCTRLA) 6 MHz  */
#define   OSCCTRL_XOSCCTRLA_CFDPRESC_DIV16_Val _UINT32_(0x4)                                        /* (OSCCTRL_XOSCCTRLA) 3 MHz  */
#define   OSCCTRL_XOSCCTRLA_CFDPRESC_DIV32_Val _UINT32_(0x5)                                        /* (OSCCTRL_XOSCCTRLA) 1.5 MHz  */
#define   OSCCTRL_XOSCCTRLA_CFDPRESC_DIV64_Val _UINT32_(0x6)                                        /* (OSCCTRL_XOSCCTRLA) 0.75 MHz  */
#define   OSCCTRL_XOSCCTRLA_CFDPRESC_DIV128_Val _UINT32_(0x7)                                        /* (OSCCTRL_XOSCCTRLA) 0.3125 MHz  */
#define OSCCTRL_XOSCCTRLA_CFDPRESC_DIV1       (OSCCTRL_XOSCCTRLA_CFDPRESC_DIV1_Val << OSCCTRL_XOSCCTRLA_CFDPRESC_Pos) /* (OSCCTRL_XOSCCTRLA) 48 MHz Position  */
#define OSCCTRL_XOSCCTRLA_CFDPRESC_DIV2       (OSCCTRL_XOSCCTRLA_CFDPRESC_DIV2_Val << OSCCTRL_XOSCCTRLA_CFDPRESC_Pos) /* (OSCCTRL_XOSCCTRLA) 24 MHz Position  */
#define OSCCTRL_XOSCCTRLA_CFDPRESC_DIV4       (OSCCTRL_XOSCCTRLA_CFDPRESC_DIV4_Val << OSCCTRL_XOSCCTRLA_CFDPRESC_Pos) /* (OSCCTRL_XOSCCTRLA) 12 MHz Position  */
#define OSCCTRL_XOSCCTRLA_CFDPRESC_DIV8       (OSCCTRL_XOSCCTRLA_CFDPRESC_DIV8_Val << OSCCTRL_XOSCCTRLA_CFDPRESC_Pos) /* (OSCCTRL_XOSCCTRLA) 6 MHz Position  */
#define OSCCTRL_XOSCCTRLA_CFDPRESC_DIV16      (OSCCTRL_XOSCCTRLA_CFDPRESC_DIV16_Val << OSCCTRL_XOSCCTRLA_CFDPRESC_Pos) /* (OSCCTRL_XOSCCTRLA) 3 MHz Position  */
#define OSCCTRL_XOSCCTRLA_CFDPRESC_DIV32      (OSCCTRL_XOSCCTRLA_CFDPRESC_DIV32_Val << OSCCTRL_XOSCCTRLA_CFDPRESC_Pos) /* (OSCCTRL_XOSCCTRLA) 1.5 MHz Position  */
#define OSCCTRL_XOSCCTRLA_CFDPRESC_DIV64      (OSCCTRL_XOSCCTRLA_CFDPRESC_DIV64_Val << OSCCTRL_XOSCCTRLA_CFDPRESC_Pos) /* (OSCCTRL_XOSCCTRLA) 0.75 MHz Position  */
#define OSCCTRL_XOSCCTRLA_CFDPRESC_DIV128     (OSCCTRL_XOSCCTRLA_CFDPRESC_DIV128_Val << OSCCTRL_XOSCCTRLA_CFDPRESC_Pos) /* (OSCCTRL_XOSCCTRLA) 0.3125 MHz Position  */
#define OSCCTRL_XOSCCTRLA_USBHSDIV_Pos        _UINT32_(24)                                         /* (OSCCTRL_XOSCCTRLA) USBHS Referrence Clock Division Position */
#define OSCCTRL_XOSCCTRLA_USBHSDIV_Msk        (_UINT32_(0x3) << OSCCTRL_XOSCCTRLA_USBHSDIV_Pos)    /* (OSCCTRL_XOSCCTRLA) USBHS Referrence Clock Division Mask */
#define OSCCTRL_XOSCCTRLA_USBHSDIV(value)     (OSCCTRL_XOSCCTRLA_USBHSDIV_Msk & (_UINT32_(value) << OSCCTRL_XOSCCTRLA_USBHSDIV_Pos)) /* Assigment of value for USBHSDIV in the OSCCTRL_XOSCCTRLA register */
#define   OSCCTRL_XOSCCTRLA_USBHSDIV_DIS_Val  _UINT32_(0x0)                                        /* (OSCCTRL_XOSCCTRLA) USBHS PLL reference XOSC clock is disabled  */
#define   OSCCTRL_XOSCCTRLA_USBHSDIV_DIV1_Val _UINT32_(0x1)                                        /* (OSCCTRL_XOSCCTRLA) USBHS PLL reference XOSC clock is divided by 1  */
#define   OSCCTRL_XOSCCTRLA_USBHSDIV_DIV2_Val _UINT32_(0x2)                                        /* (OSCCTRL_XOSCCTRLA) USBHS PLL reference XOSC clock is divided by 2  */
#define   OSCCTRL_XOSCCTRLA_USBHSDIV_DIV3_Val _UINT32_(0x3)                                        /* (OSCCTRL_XOSCCTRLA) USBHS PLL reference XOSC clock is divided by 4  */
#define OSCCTRL_XOSCCTRLA_USBHSDIV_DIS        (OSCCTRL_XOSCCTRLA_USBHSDIV_DIS_Val << OSCCTRL_XOSCCTRLA_USBHSDIV_Pos) /* (OSCCTRL_XOSCCTRLA) USBHS PLL reference XOSC clock is disabled Position  */
#define OSCCTRL_XOSCCTRLA_USBHSDIV_DIV1       (OSCCTRL_XOSCCTRLA_USBHSDIV_DIV1_Val << OSCCTRL_XOSCCTRLA_USBHSDIV_Pos) /* (OSCCTRL_XOSCCTRLA) USBHS PLL reference XOSC clock is divided by 1 Position  */
#define OSCCTRL_XOSCCTRLA_USBHSDIV_DIV2       (OSCCTRL_XOSCCTRLA_USBHSDIV_DIV2_Val << OSCCTRL_XOSCCTRLA_USBHSDIV_Pos) /* (OSCCTRL_XOSCCTRLA) USBHS PLL reference XOSC clock is divided by 2 Position  */
#define OSCCTRL_XOSCCTRLA_USBHSDIV_DIV3       (OSCCTRL_XOSCCTRLA_USBHSDIV_DIV3_Val << OSCCTRL_XOSCCTRLA_USBHSDIV_Pos) /* (OSCCTRL_XOSCCTRLA) USBHS PLL reference XOSC clock is divided by 4 Position  */
#define OSCCTRL_XOSCCTRLA_WRTLOCK_Pos         _UINT32_(31)                                         /* (OSCCTRL_XOSCCTRLA) Write Lock for CTRLA register Position */
#define OSCCTRL_XOSCCTRLA_WRTLOCK_Msk         (_UINT32_(0x1) << OSCCTRL_XOSCCTRLA_WRTLOCK_Pos)     /* (OSCCTRL_XOSCCTRLA) Write Lock for CTRLA register Mask */
#define OSCCTRL_XOSCCTRLA_WRTLOCK(value)      (OSCCTRL_XOSCCTRLA_WRTLOCK_Msk & (_UINT32_(value) << OSCCTRL_XOSCCTRLA_WRTLOCK_Pos)) /* Assigment of value for WRTLOCK in the OSCCTRL_XOSCCTRLA register */
#define OSCCTRL_XOSCCTRLA_Msk                 _UINT32_(0x830F0FBE)                                 /* (OSCCTRL_XOSCCTRLA) Register Mask  */


/* -------- OSCCTRL_XOSCCTRLB : (OSCCTRL Offset: 0x18) (R/W 32) External Multipurpose Crystal Oscillator Control B -------- */
#define OSCCTRL_XOSCCTRLB_RESETVALUE          _UINT32_(0x00)                                       /*  (OSCCTRL_XOSCCTRLB) External Multipurpose Crystal Oscillator Control B  Reset Value */

#define OSCCTRL_XOSCCTRLB_USRCFG_Pos          _UINT32_(0)                                          /* (OSCCTRL_XOSCCTRLB) User Configuration Control Bits Position */
#define OSCCTRL_XOSCCTRLB_USRCFG_Msk          (_UINT32_(0xFF) << OSCCTRL_XOSCCTRLB_USRCFG_Pos)     /* (OSCCTRL_XOSCCTRLB) User Configuration Control Bits Mask */
#define OSCCTRL_XOSCCTRLB_USRCFG(value)       (OSCCTRL_XOSCCTRLB_USRCFG_Msk & (_UINT32_(value) << OSCCTRL_XOSCCTRLB_USRCFG_Pos)) /* Assigment of value for USRCFG in the OSCCTRL_XOSCCTRLB register */
#define OSCCTRL_XOSCCTRLB_WRTLOCK_Pos         _UINT32_(31)                                         /* (OSCCTRL_XOSCCTRLB) Write Lock for CTRLB register Position */
#define OSCCTRL_XOSCCTRLB_WRTLOCK_Msk         (_UINT32_(0x1) << OSCCTRL_XOSCCTRLB_WRTLOCK_Pos)     /* (OSCCTRL_XOSCCTRLB) Write Lock for CTRLB register Mask */
#define OSCCTRL_XOSCCTRLB_WRTLOCK(value)      (OSCCTRL_XOSCCTRLB_WRTLOCK_Msk & (_UINT32_(value) << OSCCTRL_XOSCCTRLB_WRTLOCK_Pos)) /* Assigment of value for WRTLOCK in the OSCCTRL_XOSCCTRLB register */
#define OSCCTRL_XOSCCTRLB_Msk                 _UINT32_(0x800000FF)                                 /* (OSCCTRL_XOSCCTRLB) Register Mask  */


/* -------- OSCCTRL_DFLLCTRLA : (OSCCTRL Offset: 0x2C) (R/W 32) DFLL48M Control A -------- */
#define OSCCTRL_DFLLCTRLA_RESETVALUE          _UINT32_(0x82)                                       /*  (OSCCTRL_DFLLCTRLA) DFLL48M Control A  Reset Value */

#define OSCCTRL_DFLLCTRLA_ENABLE_Pos          _UINT32_(1)                                          /* (OSCCTRL_DFLLCTRLA) DFLL Enable Position */
#define OSCCTRL_DFLLCTRLA_ENABLE_Msk          (_UINT32_(0x1) << OSCCTRL_DFLLCTRLA_ENABLE_Pos)      /* (OSCCTRL_DFLLCTRLA) DFLL Enable Mask */
#define OSCCTRL_DFLLCTRLA_ENABLE(value)       (OSCCTRL_DFLLCTRLA_ENABLE_Msk & (_UINT32_(value) << OSCCTRL_DFLLCTRLA_ENABLE_Pos)) /* Assigment of value for ENABLE in the OSCCTRL_DFLLCTRLA register */
#define OSCCTRL_DFLLCTRLA_WRTLOCK_Pos         _UINT32_(2)                                          /* (OSCCTRL_DFLLCTRLA) Write Lock Position */
#define OSCCTRL_DFLLCTRLA_WRTLOCK_Msk         (_UINT32_(0x1) << OSCCTRL_DFLLCTRLA_WRTLOCK_Pos)     /* (OSCCTRL_DFLLCTRLA) Write Lock Mask */
#define OSCCTRL_DFLLCTRLA_WRTLOCK(value)      (OSCCTRL_DFLLCTRLA_WRTLOCK_Msk & (_UINT32_(value) << OSCCTRL_DFLLCTRLA_WRTLOCK_Pos)) /* Assigment of value for WRTLOCK in the OSCCTRL_DFLLCTRLA register */
#define OSCCTRL_DFLLCTRLA_LOWFREQ_Pos         _UINT32_(3)                                          /* (OSCCTRL_DFLLCTRLA) Low Frequency Mode Position */
#define OSCCTRL_DFLLCTRLA_LOWFREQ_Msk         (_UINT32_(0x1) << OSCCTRL_DFLLCTRLA_LOWFREQ_Pos)     /* (OSCCTRL_DFLLCTRLA) Low Frequency Mode Mask */
#define OSCCTRL_DFLLCTRLA_LOWFREQ(value)      (OSCCTRL_DFLLCTRLA_LOWFREQ_Msk & (_UINT32_(value) << OSCCTRL_DFLLCTRLA_LOWFREQ_Pos)) /* Assigment of value for LOWFREQ in the OSCCTRL_DFLLCTRLA register */
#define OSCCTRL_DFLLCTRLA_ONDEMAND_Pos        _UINT32_(7)                                          /* (OSCCTRL_DFLLCTRLA) On Demand Control Position */
#define OSCCTRL_DFLLCTRLA_ONDEMAND_Msk        (_UINT32_(0x1) << OSCCTRL_DFLLCTRLA_ONDEMAND_Pos)    /* (OSCCTRL_DFLLCTRLA) On Demand Control Mask */
#define OSCCTRL_DFLLCTRLA_ONDEMAND(value)     (OSCCTRL_DFLLCTRLA_ONDEMAND_Msk & (_UINT32_(value) << OSCCTRL_DFLLCTRLA_ONDEMAND_Pos)) /* Assigment of value for ONDEMAND in the OSCCTRL_DFLLCTRLA register */
#define OSCCTRL_DFLLCTRLA_Msk                 _UINT32_(0x0000008E)                                 /* (OSCCTRL_DFLLCTRLA) Register Mask  */


/* -------- OSCCTRL_DFLLCTRLB : (OSCCTRL Offset: 0x30) (R/W 32) DFLL48M Control B -------- */
#define OSCCTRL_DFLLCTRLB_RESETVALUE          _UINT32_(0x00)                                       /*  (OSCCTRL_DFLLCTRLB) DFLL48M Control B  Reset Value */

#define OSCCTRL_DFLLCTRLB_LOOPEN_Pos          _UINT32_(0)                                          /* (OSCCTRL_DFLLCTRLB) Operating Mode Selection Position */
#define OSCCTRL_DFLLCTRLB_LOOPEN_Msk          (_UINT32_(0x1) << OSCCTRL_DFLLCTRLB_LOOPEN_Pos)      /* (OSCCTRL_DFLLCTRLB) Operating Mode Selection Mask */
#define OSCCTRL_DFLLCTRLB_LOOPEN(value)       (OSCCTRL_DFLLCTRLB_LOOPEN_Msk & (_UINT32_(value) << OSCCTRL_DFLLCTRLB_LOOPEN_Pos)) /* Assigment of value for LOOPEN in the OSCCTRL_DFLLCTRLB register */
#define OSCCTRL_DFLLCTRLB_STABLE_Pos          _UINT32_(1)                                          /* (OSCCTRL_DFLLCTRLB) Stable DFLL Frequency Position */
#define OSCCTRL_DFLLCTRLB_STABLE_Msk          (_UINT32_(0x1) << OSCCTRL_DFLLCTRLB_STABLE_Pos)      /* (OSCCTRL_DFLLCTRLB) Stable DFLL Frequency Mask */
#define OSCCTRL_DFLLCTRLB_STABLE(value)       (OSCCTRL_DFLLCTRLB_STABLE_Msk & (_UINT32_(value) << OSCCTRL_DFLLCTRLB_STABLE_Pos)) /* Assigment of value for STABLE in the OSCCTRL_DFLLCTRLB register */
#define OSCCTRL_DFLLCTRLB_LLAW_Pos            _UINT32_(2)                                          /* (OSCCTRL_DFLLCTRLB) Lose Lock After Wake Position */
#define OSCCTRL_DFLLCTRLB_LLAW_Msk            (_UINT32_(0x1) << OSCCTRL_DFLLCTRLB_LLAW_Pos)        /* (OSCCTRL_DFLLCTRLB) Lose Lock After Wake Mask */
#define OSCCTRL_DFLLCTRLB_LLAW(value)         (OSCCTRL_DFLLCTRLB_LLAW_Msk & (_UINT32_(value) << OSCCTRL_DFLLCTRLB_LLAW_Pos)) /* Assigment of value for LLAW in the OSCCTRL_DFLLCTRLB register */
#define OSCCTRL_DFLLCTRLB_USBCRM_Pos          _UINT32_(3)                                          /* (OSCCTRL_DFLLCTRLB) USB Clock Recovery Mode Position */
#define OSCCTRL_DFLLCTRLB_USBCRM_Msk          (_UINT32_(0x1) << OSCCTRL_DFLLCTRLB_USBCRM_Pos)      /* (OSCCTRL_DFLLCTRLB) USB Clock Recovery Mode Mask */
#define OSCCTRL_DFLLCTRLB_USBCRM(value)       (OSCCTRL_DFLLCTRLB_USBCRM_Msk & (_UINT32_(value) << OSCCTRL_DFLLCTRLB_USBCRM_Pos)) /* Assigment of value for USBCRM in the OSCCTRL_DFLLCTRLB register */
#define OSCCTRL_DFLLCTRLB_CCDIS_Pos           _UINT32_(4)                                          /* (OSCCTRL_DFLLCTRLB) Chill Cycle Disable Position */
#define OSCCTRL_DFLLCTRLB_CCDIS_Msk           (_UINT32_(0x1) << OSCCTRL_DFLLCTRLB_CCDIS_Pos)       /* (OSCCTRL_DFLLCTRLB) Chill Cycle Disable Mask */
#define OSCCTRL_DFLLCTRLB_CCDIS(value)        (OSCCTRL_DFLLCTRLB_CCDIS_Msk & (_UINT32_(value) << OSCCTRL_DFLLCTRLB_CCDIS_Pos)) /* Assigment of value for CCDIS in the OSCCTRL_DFLLCTRLB register */
#define OSCCTRL_DFLLCTRLB_QLDIS_Pos           _UINT32_(5)                                          /* (OSCCTRL_DFLLCTRLB) Quick Lock Disable Position */
#define OSCCTRL_DFLLCTRLB_QLDIS_Msk           (_UINT32_(0x1) << OSCCTRL_DFLLCTRLB_QLDIS_Pos)       /* (OSCCTRL_DFLLCTRLB) Quick Lock Disable Mask */
#define OSCCTRL_DFLLCTRLB_QLDIS(value)        (OSCCTRL_DFLLCTRLB_QLDIS_Msk & (_UINT32_(value) << OSCCTRL_DFLLCTRLB_QLDIS_Pos)) /* Assigment of value for QLDIS in the OSCCTRL_DFLLCTRLB register */
#define OSCCTRL_DFLLCTRLB_WAITLOCK_Pos        _UINT32_(7)                                          /* (OSCCTRL_DFLLCTRLB) Wait Lock Position */
#define OSCCTRL_DFLLCTRLB_WAITLOCK_Msk        (_UINT32_(0x1) << OSCCTRL_DFLLCTRLB_WAITLOCK_Pos)    /* (OSCCTRL_DFLLCTRLB) Wait Lock Mask */
#define OSCCTRL_DFLLCTRLB_WAITLOCK(value)     (OSCCTRL_DFLLCTRLB_WAITLOCK_Msk & (_UINT32_(value) << OSCCTRL_DFLLCTRLB_WAITLOCK_Pos)) /* Assigment of value for WAITLOCK in the OSCCTRL_DFLLCTRLB register */
#define OSCCTRL_DFLLCTRLB_Msk                 _UINT32_(0x000000BF)                                 /* (OSCCTRL_DFLLCTRLB) Register Mask  */


/* -------- OSCCTRL_DFLLTUNE : (OSCCTRL Offset: 0x34) (R/W 32) DFLL48M Tune -------- */
#define OSCCTRL_DFLLTUNE_RESETVALUE           _UINT32_(0x00)                                       /*  (OSCCTRL_DFLLTUNE) DFLL48M Tune  Reset Value */

#define OSCCTRL_DFLLTUNE_TUNE_Pos             _UINT32_(0)                                          /* (OSCCTRL_DFLLTUNE) Tune Value Position */
#define OSCCTRL_DFLLTUNE_TUNE_Msk             (_UINT32_(0x7F) << OSCCTRL_DFLLTUNE_TUNE_Pos)        /* (OSCCTRL_DFLLTUNE) Tune Value Mask */
#define OSCCTRL_DFLLTUNE_TUNE(value)          (OSCCTRL_DFLLTUNE_TUNE_Msk & (_UINT32_(value) << OSCCTRL_DFLLTUNE_TUNE_Pos)) /* Assigment of value for TUNE in the OSCCTRL_DFLLTUNE register */
#define OSCCTRL_DFLLTUNE_Msk                  _UINT32_(0x0000007F)                                 /* (OSCCTRL_DFLLTUNE) Register Mask  */


/* -------- OSCCTRL_DFLLDIFF : (OSCCTRL Offset: 0x38) ( R/ 32) DFLL48M Diff -------- */
#define OSCCTRL_DFLLDIFF_RESETVALUE           _UINT32_(0x00)                                       /*  (OSCCTRL_DFLLDIFF) DFLL48M Diff  Reset Value */

#define OSCCTRL_DFLLDIFF_DIFF_Pos             _UINT32_(0)                                          /* (OSCCTRL_DFLLDIFF) Multiplication Ratio Difference Position */
#define OSCCTRL_DFLLDIFF_DIFF_Msk             (_UINT32_(0xFFFF) << OSCCTRL_DFLLDIFF_DIFF_Pos)      /* (OSCCTRL_DFLLDIFF) Multiplication Ratio Difference Mask */
#define OSCCTRL_DFLLDIFF_DIFF(value)          (OSCCTRL_DFLLDIFF_DIFF_Msk & (_UINT32_(value) << OSCCTRL_DFLLDIFF_DIFF_Pos)) /* Assigment of value for DIFF in the OSCCTRL_DFLLDIFF register */
#define OSCCTRL_DFLLDIFF_Msk                  _UINT32_(0x0000FFFF)                                 /* (OSCCTRL_DFLLDIFF) Register Mask  */


/* -------- OSCCTRL_DFLLMUL : (OSCCTRL Offset: 0x3C) (R/W 32) DFLL48M Multiplier -------- */
#define OSCCTRL_DFLLMUL_RESETVALUE            _UINT32_(0x00)                                       /*  (OSCCTRL_DFLLMUL) DFLL48M Multiplier  Reset Value */

#define OSCCTRL_DFLLMUL_MUL_Pos               _UINT32_(0)                                          /* (OSCCTRL_DFLLMUL) DFLL Multiply Factor Position */
#define OSCCTRL_DFLLMUL_MUL_Msk               (_UINT32_(0xFFFF) << OSCCTRL_DFLLMUL_MUL_Pos)        /* (OSCCTRL_DFLLMUL) DFLL Multiply Factor Mask */
#define OSCCTRL_DFLLMUL_MUL(value)            (OSCCTRL_DFLLMUL_MUL_Msk & (_UINT32_(value) << OSCCTRL_DFLLMUL_MUL_Pos)) /* Assigment of value for MUL in the OSCCTRL_DFLLMUL register */
#define OSCCTRL_DFLLMUL_STEP_Pos              _UINT32_(16)                                         /* (OSCCTRL_DFLLMUL) Tune Maximum Step Position */
#define OSCCTRL_DFLLMUL_STEP_Msk              (_UINT32_(0x7F) << OSCCTRL_DFLLMUL_STEP_Pos)         /* (OSCCTRL_DFLLMUL) Tune Maximum Step Mask */
#define OSCCTRL_DFLLMUL_STEP(value)           (OSCCTRL_DFLLMUL_STEP_Msk & (_UINT32_(value) << OSCCTRL_DFLLMUL_STEP_Pos)) /* Assigment of value for STEP in the OSCCTRL_DFLLMUL register */
#define OSCCTRL_DFLLMUL_Msk                   _UINT32_(0x007FFFFF)                                 /* (OSCCTRL_DFLLMUL) Register Mask  */


/* -------- OSCCTRL_PLL0CTRL : (OSCCTRL Offset: 0x40) (R/W 32) PLL Control -------- */
#define OSCCTRL_PLL0CTRL_RESETVALUE           _UINT32_(0x00)                                       /*  (OSCCTRL_PLL0CTRL) PLL Control  Reset Value */

#define OSCCTRL_PLL0CTRL_ENABLE_Pos           _UINT32_(1)                                          /* (OSCCTRL_PLL0CTRL) PLL Enable Position */
#define OSCCTRL_PLL0CTRL_ENABLE_Msk           (_UINT32_(0x1) << OSCCTRL_PLL0CTRL_ENABLE_Pos)       /* (OSCCTRL_PLL0CTRL) PLL Enable Mask */
#define OSCCTRL_PLL0CTRL_ENABLE(value)        (OSCCTRL_PLL0CTRL_ENABLE_Msk & (_UINT32_(value) << OSCCTRL_PLL0CTRL_ENABLE_Pos)) /* Assigment of value for ENABLE in the OSCCTRL_PLL0CTRL register */
#define OSCCTRL_PLL0CTRL_WRTLOCK_Pos          _UINT32_(2)                                          /* (OSCCTRL_PLL0CTRL) Write Lock Position */
#define OSCCTRL_PLL0CTRL_WRTLOCK_Msk          (_UINT32_(0x1) << OSCCTRL_PLL0CTRL_WRTLOCK_Pos)      /* (OSCCTRL_PLL0CTRL) Write Lock Mask */
#define OSCCTRL_PLL0CTRL_WRTLOCK(value)       (OSCCTRL_PLL0CTRL_WRTLOCK_Msk & (_UINT32_(value) << OSCCTRL_PLL0CTRL_WRTLOCK_Pos)) /* Assigment of value for WRTLOCK in the OSCCTRL_PLL0CTRL register */
#define OSCCTRL_PLL0CTRL_ONDEMAND_Pos         _UINT32_(7)                                          /* (OSCCTRL_PLL0CTRL) On Demand Control Position */
#define OSCCTRL_PLL0CTRL_ONDEMAND_Msk         (_UINT32_(0x1) << OSCCTRL_PLL0CTRL_ONDEMAND_Pos)     /* (OSCCTRL_PLL0CTRL) On Demand Control Mask */
#define OSCCTRL_PLL0CTRL_ONDEMAND(value)      (OSCCTRL_PLL0CTRL_ONDEMAND_Msk & (_UINT32_(value) << OSCCTRL_PLL0CTRL_ONDEMAND_Pos)) /* Assigment of value for ONDEMAND in the OSCCTRL_PLL0CTRL register */
#define OSCCTRL_PLL0CTRL_REFSEL_Pos           _UINT32_(8)                                          /* (OSCCTRL_PLL0CTRL) Reference selection Position */
#define OSCCTRL_PLL0CTRL_REFSEL_Msk           (_UINT32_(0x7) << OSCCTRL_PLL0CTRL_REFSEL_Pos)       /* (OSCCTRL_PLL0CTRL) Reference selection Mask */
#define OSCCTRL_PLL0CTRL_REFSEL(value)        (OSCCTRL_PLL0CTRL_REFSEL_Msk & (_UINT32_(value) << OSCCTRL_PLL0CTRL_REFSEL_Pos)) /* Assigment of value for REFSEL in the OSCCTRL_PLL0CTRL register */
#define   OSCCTRL_PLL0CTRL_REFSEL_GCLK_Val    _UINT32_(0x0)                                        /* (OSCCTRL_PLL0CTRL) Dedicated GCLK clock reference  */
#define   OSCCTRL_PLL0CTRL_REFSEL_XOSC_Val    _UINT32_(0x1)                                        /* (OSCCTRL_PLL0CTRL) XOSC clock reference  */
#define   OSCCTRL_PLL0CTRL_REFSEL_DFLL48M_Val _UINT32_(0x2)                                        /* (OSCCTRL_PLL0CTRL) DFLL48M clock reference  */
#define OSCCTRL_PLL0CTRL_REFSEL_GCLK          (OSCCTRL_PLL0CTRL_REFSEL_GCLK_Val << OSCCTRL_PLL0CTRL_REFSEL_Pos) /* (OSCCTRL_PLL0CTRL) Dedicated GCLK clock reference Position  */
#define OSCCTRL_PLL0CTRL_REFSEL_XOSC          (OSCCTRL_PLL0CTRL_REFSEL_XOSC_Val << OSCCTRL_PLL0CTRL_REFSEL_Pos) /* (OSCCTRL_PLL0CTRL) XOSC clock reference Position  */
#define OSCCTRL_PLL0CTRL_REFSEL_DFLL48M       (OSCCTRL_PLL0CTRL_REFSEL_DFLL48M_Val << OSCCTRL_PLL0CTRL_REFSEL_Pos) /* (OSCCTRL_PLL0CTRL) DFLL48M clock reference Position  */
#define OSCCTRL_PLL0CTRL_BWSEL_Pos            _UINT32_(11)                                         /* (OSCCTRL_PLL0CTRL) Bandwidth selection Position */
#define OSCCTRL_PLL0CTRL_BWSEL_Msk            (_UINT32_(0x7) << OSCCTRL_PLL0CTRL_BWSEL_Pos)        /* (OSCCTRL_PLL0CTRL) Bandwidth selection Mask */
#define OSCCTRL_PLL0CTRL_BWSEL(value)         (OSCCTRL_PLL0CTRL_BWSEL_Msk & (_UINT32_(value) << OSCCTRL_PLL0CTRL_BWSEL_Pos)) /* Assigment of value for BWSEL in the OSCCTRL_PLL0CTRL register */
#define   OSCCTRL_PLL0CTRL_BWSEL_BWSEL0_Val   _UINT32_(0x0)                                        /* (OSCCTRL_PLL0CTRL) TBD  */
#define   OSCCTRL_PLL0CTRL_BWSEL_BWSEL1_Val   _UINT32_(0x1)                                        /* (OSCCTRL_PLL0CTRL) TBD  */
#define   OSCCTRL_PLL0CTRL_BWSEL_BWSEL2_Val   _UINT32_(0x2)                                        /* (OSCCTRL_PLL0CTRL) TBD  */
#define   OSCCTRL_PLL0CTRL_BWSEL_BWSEL3_Val   _UINT32_(0x3)                                        /* (OSCCTRL_PLL0CTRL) TBD  */
#define   OSCCTRL_PLL0CTRL_BWSEL_BWSEL4_Val   _UINT32_(0x4)                                        /* (OSCCTRL_PLL0CTRL) TBD  */
#define   OSCCTRL_PLL0CTRL_BWSEL_BWSEL5_Val   _UINT32_(0x5)                                        /* (OSCCTRL_PLL0CTRL) TBD  */
#define   OSCCTRL_PLL0CTRL_BWSEL_BWSEL6_Val   _UINT32_(0x6)                                        /* (OSCCTRL_PLL0CTRL) TBD  */
#define   OSCCTRL_PLL0CTRL_BWSEL_BWSEL7_Val   _UINT32_(0x7)                                        /* (OSCCTRL_PLL0CTRL) TBD  */
#define OSCCTRL_PLL0CTRL_BWSEL_BWSEL0         (OSCCTRL_PLL0CTRL_BWSEL_BWSEL0_Val << OSCCTRL_PLL0CTRL_BWSEL_Pos) /* (OSCCTRL_PLL0CTRL) TBD Position  */
#define OSCCTRL_PLL0CTRL_BWSEL_BWSEL1         (OSCCTRL_PLL0CTRL_BWSEL_BWSEL1_Val << OSCCTRL_PLL0CTRL_BWSEL_Pos) /* (OSCCTRL_PLL0CTRL) TBD Position  */
#define OSCCTRL_PLL0CTRL_BWSEL_BWSEL2         (OSCCTRL_PLL0CTRL_BWSEL_BWSEL2_Val << OSCCTRL_PLL0CTRL_BWSEL_Pos) /* (OSCCTRL_PLL0CTRL) TBD Position  */
#define OSCCTRL_PLL0CTRL_BWSEL_BWSEL3         (OSCCTRL_PLL0CTRL_BWSEL_BWSEL3_Val << OSCCTRL_PLL0CTRL_BWSEL_Pos) /* (OSCCTRL_PLL0CTRL) TBD Position  */
#define OSCCTRL_PLL0CTRL_BWSEL_BWSEL4         (OSCCTRL_PLL0CTRL_BWSEL_BWSEL4_Val << OSCCTRL_PLL0CTRL_BWSEL_Pos) /* (OSCCTRL_PLL0CTRL) TBD Position  */
#define OSCCTRL_PLL0CTRL_BWSEL_BWSEL5         (OSCCTRL_PLL0CTRL_BWSEL_BWSEL5_Val << OSCCTRL_PLL0CTRL_BWSEL_Pos) /* (OSCCTRL_PLL0CTRL) TBD Position  */
#define OSCCTRL_PLL0CTRL_BWSEL_BWSEL6         (OSCCTRL_PLL0CTRL_BWSEL_BWSEL6_Val << OSCCTRL_PLL0CTRL_BWSEL_Pos) /* (OSCCTRL_PLL0CTRL) TBD Position  */
#define OSCCTRL_PLL0CTRL_BWSEL_BWSEL7         (OSCCTRL_PLL0CTRL_BWSEL_BWSEL7_Val << OSCCTRL_PLL0CTRL_BWSEL_Pos) /* (OSCCTRL_PLL0CTRL) TBD Position  */
#define OSCCTRL_PLL0CTRL_Msk                  _UINT32_(0x00003F86)                                 /* (OSCCTRL_PLL0CTRL) Register Mask  */


/* -------- OSCCTRL_PLL0FBDIV : (OSCCTRL Offset: 0x44) (R/W 32) PLL Feed-Back Divider -------- */
#define OSCCTRL_PLL0FBDIV_RESETVALUE          _UINT32_(0x00)                                       /*  (OSCCTRL_PLL0FBDIV) PLL Feed-Back Divider  Reset Value */

#define OSCCTRL_PLL0FBDIV_FBDIV_Pos           _UINT32_(0)                                          /* (OSCCTRL_PLL0FBDIV) PLL Feed-Back Divider Factor Position */
#define OSCCTRL_PLL0FBDIV_FBDIV_Msk           (_UINT32_(0x3FF) << OSCCTRL_PLL0FBDIV_FBDIV_Pos)     /* (OSCCTRL_PLL0FBDIV) PLL Feed-Back Divider Factor Mask */
#define OSCCTRL_PLL0FBDIV_FBDIV(value)        (OSCCTRL_PLL0FBDIV_FBDIV_Msk & (_UINT32_(value) << OSCCTRL_PLL0FBDIV_FBDIV_Pos)) /* Assigment of value for FBDIV in the OSCCTRL_PLL0FBDIV register */
#define OSCCTRL_PLL0FBDIV_Msk                 _UINT32_(0x000003FF)                                 /* (OSCCTRL_PLL0FBDIV) Register Mask  */


/* -------- OSCCTRL_PLL0REFDIV : (OSCCTRL Offset: 0x48) (R/W 32) PLL reference divider -------- */
#define OSCCTRL_PLL0REFDIV_RESETVALUE         _UINT32_(0x00)                                       /*  (OSCCTRL_PLL0REFDIV) PLL reference divider  Reset Value */

#define OSCCTRL_PLL0REFDIV_REFDIV_Pos         _UINT32_(0)                                          /* (OSCCTRL_PLL0REFDIV) PLL reference division factor Position */
#define OSCCTRL_PLL0REFDIV_REFDIV_Msk         (_UINT32_(0x3F) << OSCCTRL_PLL0REFDIV_REFDIV_Pos)    /* (OSCCTRL_PLL0REFDIV) PLL reference division factor Mask */
#define OSCCTRL_PLL0REFDIV_REFDIV(value)      (OSCCTRL_PLL0REFDIV_REFDIV_Msk & (_UINT32_(value) << OSCCTRL_PLL0REFDIV_REFDIV_Pos)) /* Assigment of value for REFDIV in the OSCCTRL_PLL0REFDIV register */
#define OSCCTRL_PLL0REFDIV_Msk                _UINT32_(0x0000003F)                                 /* (OSCCTRL_PLL0REFDIV) Register Mask  */


/* -------- OSCCTRL_PLL0POSTDIVA : (OSCCTRL Offset: 0x4C) (R/W 32) PLL output clock divider A -------- */
#define OSCCTRL_PLL0POSTDIVA_RESETVALUE       _UINT32_(0x20202020)                                 /*  (OSCCTRL_PLL0POSTDIVA) PLL output clock divider A  Reset Value */

#define OSCCTRL_PLL0POSTDIVA_POSTDIV0_Pos     _UINT32_(0)                                          /* (OSCCTRL_PLL0POSTDIVA) PLL output 0 clock division factor Position */
#define OSCCTRL_PLL0POSTDIVA_POSTDIV0_Msk     (_UINT32_(0x3F) << OSCCTRL_PLL0POSTDIVA_POSTDIV0_Pos) /* (OSCCTRL_PLL0POSTDIVA) PLL output 0 clock division factor Mask */
#define OSCCTRL_PLL0POSTDIVA_POSTDIV0(value)  (OSCCTRL_PLL0POSTDIVA_POSTDIV0_Msk & (_UINT32_(value) << OSCCTRL_PLL0POSTDIVA_POSTDIV0_Pos)) /* Assigment of value for POSTDIV0 in the OSCCTRL_PLL0POSTDIVA register */
#define OSCCTRL_PLL0POSTDIVA_OUTEN0_Pos       _UINT32_(7)                                          /* (OSCCTRL_PLL0POSTDIVA) PLL output 0 enable Position */
#define OSCCTRL_PLL0POSTDIVA_OUTEN0_Msk       (_UINT32_(0x1) << OSCCTRL_PLL0POSTDIVA_OUTEN0_Pos)   /* (OSCCTRL_PLL0POSTDIVA) PLL output 0 enable Mask */
#define OSCCTRL_PLL0POSTDIVA_OUTEN0(value)    (OSCCTRL_PLL0POSTDIVA_OUTEN0_Msk & (_UINT32_(value) << OSCCTRL_PLL0POSTDIVA_OUTEN0_Pos)) /* Assigment of value for OUTEN0 in the OSCCTRL_PLL0POSTDIVA register */
#define OSCCTRL_PLL0POSTDIVA_POSTDIV1_Pos     _UINT32_(8)                                          /* (OSCCTRL_PLL0POSTDIVA) PLL output 0 clock division factor Position */
#define OSCCTRL_PLL0POSTDIVA_POSTDIV1_Msk     (_UINT32_(0x3F) << OSCCTRL_PLL0POSTDIVA_POSTDIV1_Pos) /* (OSCCTRL_PLL0POSTDIVA) PLL output 0 clock division factor Mask */
#define OSCCTRL_PLL0POSTDIVA_POSTDIV1(value)  (OSCCTRL_PLL0POSTDIVA_POSTDIV1_Msk & (_UINT32_(value) << OSCCTRL_PLL0POSTDIVA_POSTDIV1_Pos)) /* Assigment of value for POSTDIV1 in the OSCCTRL_PLL0POSTDIVA register */
#define OSCCTRL_PLL0POSTDIVA_OUTEN1_Pos       _UINT32_(15)                                         /* (OSCCTRL_PLL0POSTDIVA) PLL output 0 enable Position */
#define OSCCTRL_PLL0POSTDIVA_OUTEN1_Msk       (_UINT32_(0x1) << OSCCTRL_PLL0POSTDIVA_OUTEN1_Pos)   /* (OSCCTRL_PLL0POSTDIVA) PLL output 0 enable Mask */
#define OSCCTRL_PLL0POSTDIVA_OUTEN1(value)    (OSCCTRL_PLL0POSTDIVA_OUTEN1_Msk & (_UINT32_(value) << OSCCTRL_PLL0POSTDIVA_OUTEN1_Pos)) /* Assigment of value for OUTEN1 in the OSCCTRL_PLL0POSTDIVA register */
#define OSCCTRL_PLL0POSTDIVA_POSTDIV2_Pos     _UINT32_(16)                                         /* (OSCCTRL_PLL0POSTDIVA) PLL output 0 clock division factor Position */
#define OSCCTRL_PLL0POSTDIVA_POSTDIV2_Msk     (_UINT32_(0x3F) << OSCCTRL_PLL0POSTDIVA_POSTDIV2_Pos) /* (OSCCTRL_PLL0POSTDIVA) PLL output 0 clock division factor Mask */
#define OSCCTRL_PLL0POSTDIVA_POSTDIV2(value)  (OSCCTRL_PLL0POSTDIVA_POSTDIV2_Msk & (_UINT32_(value) << OSCCTRL_PLL0POSTDIVA_POSTDIV2_Pos)) /* Assigment of value for POSTDIV2 in the OSCCTRL_PLL0POSTDIVA register */
#define OSCCTRL_PLL0POSTDIVA_OUTEN2_Pos       _UINT32_(23)                                         /* (OSCCTRL_PLL0POSTDIVA) PLL output 0 enable Position */
#define OSCCTRL_PLL0POSTDIVA_OUTEN2_Msk       (_UINT32_(0x1) << OSCCTRL_PLL0POSTDIVA_OUTEN2_Pos)   /* (OSCCTRL_PLL0POSTDIVA) PLL output 0 enable Mask */
#define OSCCTRL_PLL0POSTDIVA_OUTEN2(value)    (OSCCTRL_PLL0POSTDIVA_OUTEN2_Msk & (_UINT32_(value) << OSCCTRL_PLL0POSTDIVA_OUTEN2_Pos)) /* Assigment of value for OUTEN2 in the OSCCTRL_PLL0POSTDIVA register */
#define OSCCTRL_PLL0POSTDIVA_POSTDIV3_Pos     _UINT32_(24)                                         /* (OSCCTRL_PLL0POSTDIVA) PLL output 0 clock division factor Position */
#define OSCCTRL_PLL0POSTDIVA_POSTDIV3_Msk     (_UINT32_(0x3F) << OSCCTRL_PLL0POSTDIVA_POSTDIV3_Pos) /* (OSCCTRL_PLL0POSTDIVA) PLL output 0 clock division factor Mask */
#define OSCCTRL_PLL0POSTDIVA_POSTDIV3(value)  (OSCCTRL_PLL0POSTDIVA_POSTDIV3_Msk & (_UINT32_(value) << OSCCTRL_PLL0POSTDIVA_POSTDIV3_Pos)) /* Assigment of value for POSTDIV3 in the OSCCTRL_PLL0POSTDIVA register */
#define OSCCTRL_PLL0POSTDIVA_OUTEN3_Pos       _UINT32_(31)                                         /* (OSCCTRL_PLL0POSTDIVA) PLL output 0 enable Position */
#define OSCCTRL_PLL0POSTDIVA_OUTEN3_Msk       (_UINT32_(0x1) << OSCCTRL_PLL0POSTDIVA_OUTEN3_Pos)   /* (OSCCTRL_PLL0POSTDIVA) PLL output 0 enable Mask */
#define OSCCTRL_PLL0POSTDIVA_OUTEN3(value)    (OSCCTRL_PLL0POSTDIVA_OUTEN3_Msk & (_UINT32_(value) << OSCCTRL_PLL0POSTDIVA_OUTEN3_Pos)) /* Assigment of value for OUTEN3 in the OSCCTRL_PLL0POSTDIVA register */
#define OSCCTRL_PLL0POSTDIVA_Msk              _UINT32_(0xBFBFBFBF)                                 /* (OSCCTRL_PLL0POSTDIVA) Register Mask  */


/* -------- OSCCTRL_PLL1CTRL : (OSCCTRL Offset: 0x54) (R/W 32) PLL Control -------- */
#define OSCCTRL_PLL1CTRL_RESETVALUE           _UINT32_(0x00)                                       /*  (OSCCTRL_PLL1CTRL) PLL Control  Reset Value */

#define OSCCTRL_PLL1CTRL_ENABLE_Pos           _UINT32_(1)                                          /* (OSCCTRL_PLL1CTRL) PLL Enable Position */
#define OSCCTRL_PLL1CTRL_ENABLE_Msk           (_UINT32_(0x1) << OSCCTRL_PLL1CTRL_ENABLE_Pos)       /* (OSCCTRL_PLL1CTRL) PLL Enable Mask */
#define OSCCTRL_PLL1CTRL_ENABLE(value)        (OSCCTRL_PLL1CTRL_ENABLE_Msk & (_UINT32_(value) << OSCCTRL_PLL1CTRL_ENABLE_Pos)) /* Assigment of value for ENABLE in the OSCCTRL_PLL1CTRL register */
#define OSCCTRL_PLL1CTRL_WRTLOCK_Pos          _UINT32_(2)                                          /* (OSCCTRL_PLL1CTRL) Write Lock Position */
#define OSCCTRL_PLL1CTRL_WRTLOCK_Msk          (_UINT32_(0x1) << OSCCTRL_PLL1CTRL_WRTLOCK_Pos)      /* (OSCCTRL_PLL1CTRL) Write Lock Mask */
#define OSCCTRL_PLL1CTRL_WRTLOCK(value)       (OSCCTRL_PLL1CTRL_WRTLOCK_Msk & (_UINT32_(value) << OSCCTRL_PLL1CTRL_WRTLOCK_Pos)) /* Assigment of value for WRTLOCK in the OSCCTRL_PLL1CTRL register */
#define OSCCTRL_PLL1CTRL_ONDEMAND_Pos         _UINT32_(7)                                          /* (OSCCTRL_PLL1CTRL) On Demand Control Position */
#define OSCCTRL_PLL1CTRL_ONDEMAND_Msk         (_UINT32_(0x1) << OSCCTRL_PLL1CTRL_ONDEMAND_Pos)     /* (OSCCTRL_PLL1CTRL) On Demand Control Mask */
#define OSCCTRL_PLL1CTRL_ONDEMAND(value)      (OSCCTRL_PLL1CTRL_ONDEMAND_Msk & (_UINT32_(value) << OSCCTRL_PLL1CTRL_ONDEMAND_Pos)) /* Assigment of value for ONDEMAND in the OSCCTRL_PLL1CTRL register */
#define OSCCTRL_PLL1CTRL_REFSEL_Pos           _UINT32_(8)                                          /* (OSCCTRL_PLL1CTRL) Reference selection Position */
#define OSCCTRL_PLL1CTRL_REFSEL_Msk           (_UINT32_(0x7) << OSCCTRL_PLL1CTRL_REFSEL_Pos)       /* (OSCCTRL_PLL1CTRL) Reference selection Mask */
#define OSCCTRL_PLL1CTRL_REFSEL(value)        (OSCCTRL_PLL1CTRL_REFSEL_Msk & (_UINT32_(value) << OSCCTRL_PLL1CTRL_REFSEL_Pos)) /* Assigment of value for REFSEL in the OSCCTRL_PLL1CTRL register */
#define   OSCCTRL_PLL1CTRL_REFSEL_GCLK_Val    _UINT32_(0x0)                                        /* (OSCCTRL_PLL1CTRL) Dedicated GCLK clock reference  */
#define   OSCCTRL_PLL1CTRL_REFSEL_XOSC_Val    _UINT32_(0x1)                                        /* (OSCCTRL_PLL1CTRL) XOSC clock reference  */
#define   OSCCTRL_PLL1CTRL_REFSEL_DFLL48M_Val _UINT32_(0x2)                                        /* (OSCCTRL_PLL1CTRL) DFLL48M clock reference  */
#define OSCCTRL_PLL1CTRL_REFSEL_GCLK          (OSCCTRL_PLL1CTRL_REFSEL_GCLK_Val << OSCCTRL_PLL1CTRL_REFSEL_Pos) /* (OSCCTRL_PLL1CTRL) Dedicated GCLK clock reference Position  */
#define OSCCTRL_PLL1CTRL_REFSEL_XOSC          (OSCCTRL_PLL1CTRL_REFSEL_XOSC_Val << OSCCTRL_PLL1CTRL_REFSEL_Pos) /* (OSCCTRL_PLL1CTRL) XOSC clock reference Position  */
#define OSCCTRL_PLL1CTRL_REFSEL_DFLL48M       (OSCCTRL_PLL1CTRL_REFSEL_DFLL48M_Val << OSCCTRL_PLL1CTRL_REFSEL_Pos) /* (OSCCTRL_PLL1CTRL) DFLL48M clock reference Position  */
#define OSCCTRL_PLL1CTRL_BWSEL_Pos            _UINT32_(11)                                         /* (OSCCTRL_PLL1CTRL) Bandwidth selection Position */
#define OSCCTRL_PLL1CTRL_BWSEL_Msk            (_UINT32_(0x7) << OSCCTRL_PLL1CTRL_BWSEL_Pos)        /* (OSCCTRL_PLL1CTRL) Bandwidth selection Mask */
#define OSCCTRL_PLL1CTRL_BWSEL(value)         (OSCCTRL_PLL1CTRL_BWSEL_Msk & (_UINT32_(value) << OSCCTRL_PLL1CTRL_BWSEL_Pos)) /* Assigment of value for BWSEL in the OSCCTRL_PLL1CTRL register */
#define   OSCCTRL_PLL1CTRL_BWSEL_BWSEL0_Val   _UINT32_(0x0)                                        /* (OSCCTRL_PLL1CTRL) TBD  */
#define   OSCCTRL_PLL1CTRL_BWSEL_BWSEL1_Val   _UINT32_(0x1)                                        /* (OSCCTRL_PLL1CTRL) TBD  */
#define   OSCCTRL_PLL1CTRL_BWSEL_BWSEL2_Val   _UINT32_(0x2)                                        /* (OSCCTRL_PLL1CTRL) TBD  */
#define   OSCCTRL_PLL1CTRL_BWSEL_BWSEL3_Val   _UINT32_(0x3)                                        /* (OSCCTRL_PLL1CTRL) TBD  */
#define   OSCCTRL_PLL1CTRL_BWSEL_BWSEL4_Val   _UINT32_(0x4)                                        /* (OSCCTRL_PLL1CTRL) TBD  */
#define   OSCCTRL_PLL1CTRL_BWSEL_BWSEL5_Val   _UINT32_(0x5)                                        /* (OSCCTRL_PLL1CTRL) TBD  */
#define   OSCCTRL_PLL1CTRL_BWSEL_BWSEL6_Val   _UINT32_(0x6)                                        /* (OSCCTRL_PLL1CTRL) TBD  */
#define   OSCCTRL_PLL1CTRL_BWSEL_BWSEL7_Val   _UINT32_(0x7)                                        /* (OSCCTRL_PLL1CTRL) TBD  */
#define OSCCTRL_PLL1CTRL_BWSEL_BWSEL0         (OSCCTRL_PLL1CTRL_BWSEL_BWSEL0_Val << OSCCTRL_PLL1CTRL_BWSEL_Pos) /* (OSCCTRL_PLL1CTRL) TBD Position  */
#define OSCCTRL_PLL1CTRL_BWSEL_BWSEL1         (OSCCTRL_PLL1CTRL_BWSEL_BWSEL1_Val << OSCCTRL_PLL1CTRL_BWSEL_Pos) /* (OSCCTRL_PLL1CTRL) TBD Position  */
#define OSCCTRL_PLL1CTRL_BWSEL_BWSEL2         (OSCCTRL_PLL1CTRL_BWSEL_BWSEL2_Val << OSCCTRL_PLL1CTRL_BWSEL_Pos) /* (OSCCTRL_PLL1CTRL) TBD Position  */
#define OSCCTRL_PLL1CTRL_BWSEL_BWSEL3         (OSCCTRL_PLL1CTRL_BWSEL_BWSEL3_Val << OSCCTRL_PLL1CTRL_BWSEL_Pos) /* (OSCCTRL_PLL1CTRL) TBD Position  */
#define OSCCTRL_PLL1CTRL_BWSEL_BWSEL4         (OSCCTRL_PLL1CTRL_BWSEL_BWSEL4_Val << OSCCTRL_PLL1CTRL_BWSEL_Pos) /* (OSCCTRL_PLL1CTRL) TBD Position  */
#define OSCCTRL_PLL1CTRL_BWSEL_BWSEL5         (OSCCTRL_PLL1CTRL_BWSEL_BWSEL5_Val << OSCCTRL_PLL1CTRL_BWSEL_Pos) /* (OSCCTRL_PLL1CTRL) TBD Position  */
#define OSCCTRL_PLL1CTRL_BWSEL_BWSEL6         (OSCCTRL_PLL1CTRL_BWSEL_BWSEL6_Val << OSCCTRL_PLL1CTRL_BWSEL_Pos) /* (OSCCTRL_PLL1CTRL) TBD Position  */
#define OSCCTRL_PLL1CTRL_BWSEL_BWSEL7         (OSCCTRL_PLL1CTRL_BWSEL_BWSEL7_Val << OSCCTRL_PLL1CTRL_BWSEL_Pos) /* (OSCCTRL_PLL1CTRL) TBD Position  */
#define OSCCTRL_PLL1CTRL_Msk                  _UINT32_(0x00003F86)                                 /* (OSCCTRL_PLL1CTRL) Register Mask  */


/* -------- OSCCTRL_PLL1FBDIV : (OSCCTRL Offset: 0x58) (R/W 32) PLL Feed-Back Divider -------- */
#define OSCCTRL_PLL1FBDIV_RESETVALUE          _UINT32_(0x00)                                       /*  (OSCCTRL_PLL1FBDIV) PLL Feed-Back Divider  Reset Value */

#define OSCCTRL_PLL1FBDIV_FBDIV_Pos           _UINT32_(0)                                          /* (OSCCTRL_PLL1FBDIV) PLL Feed-Back Divider Factor Position */
#define OSCCTRL_PLL1FBDIV_FBDIV_Msk           (_UINT32_(0x3FF) << OSCCTRL_PLL1FBDIV_FBDIV_Pos)     /* (OSCCTRL_PLL1FBDIV) PLL Feed-Back Divider Factor Mask */
#define OSCCTRL_PLL1FBDIV_FBDIV(value)        (OSCCTRL_PLL1FBDIV_FBDIV_Msk & (_UINT32_(value) << OSCCTRL_PLL1FBDIV_FBDIV_Pos)) /* Assigment of value for FBDIV in the OSCCTRL_PLL1FBDIV register */
#define OSCCTRL_PLL1FBDIV_Msk                 _UINT32_(0x000003FF)                                 /* (OSCCTRL_PLL1FBDIV) Register Mask  */


/* -------- OSCCTRL_PLL1REFDIV : (OSCCTRL Offset: 0x5C) (R/W 32) PLL reference divider -------- */
#define OSCCTRL_PLL1REFDIV_RESETVALUE         _UINT32_(0x00)                                       /*  (OSCCTRL_PLL1REFDIV) PLL reference divider  Reset Value */

#define OSCCTRL_PLL1REFDIV_REFDIV_Pos         _UINT32_(0)                                          /* (OSCCTRL_PLL1REFDIV) PLL reference division factor Position */
#define OSCCTRL_PLL1REFDIV_REFDIV_Msk         (_UINT32_(0x3F) << OSCCTRL_PLL1REFDIV_REFDIV_Pos)    /* (OSCCTRL_PLL1REFDIV) PLL reference division factor Mask */
#define OSCCTRL_PLL1REFDIV_REFDIV(value)      (OSCCTRL_PLL1REFDIV_REFDIV_Msk & (_UINT32_(value) << OSCCTRL_PLL1REFDIV_REFDIV_Pos)) /* Assigment of value for REFDIV in the OSCCTRL_PLL1REFDIV register */
#define OSCCTRL_PLL1REFDIV_Msk                _UINT32_(0x0000003F)                                 /* (OSCCTRL_PLL1REFDIV) Register Mask  */


/* -------- OSCCTRL_PLL1POSTDIVA : (OSCCTRL Offset: 0x60) (R/W 32) PLL output clock divider A -------- */
#define OSCCTRL_PLL1POSTDIVA_RESETVALUE       _UINT32_(0x20202020)                                 /*  (OSCCTRL_PLL1POSTDIVA) PLL output clock divider A  Reset Value */

#define OSCCTRL_PLL1POSTDIVA_POSTDIV0_Pos     _UINT32_(0)                                          /* (OSCCTRL_PLL1POSTDIVA) PLL output 0 clock division factor Position */
#define OSCCTRL_PLL1POSTDIVA_POSTDIV0_Msk     (_UINT32_(0x3F) << OSCCTRL_PLL1POSTDIVA_POSTDIV0_Pos) /* (OSCCTRL_PLL1POSTDIVA) PLL output 0 clock division factor Mask */
#define OSCCTRL_PLL1POSTDIVA_POSTDIV0(value)  (OSCCTRL_PLL1POSTDIVA_POSTDIV0_Msk & (_UINT32_(value) << OSCCTRL_PLL1POSTDIVA_POSTDIV0_Pos)) /* Assigment of value for POSTDIV0 in the OSCCTRL_PLL1POSTDIVA register */
#define OSCCTRL_PLL1POSTDIVA_OUTEN0_Pos       _UINT32_(7)                                          /* (OSCCTRL_PLL1POSTDIVA) PLL output 0 enable Position */
#define OSCCTRL_PLL1POSTDIVA_OUTEN0_Msk       (_UINT32_(0x1) << OSCCTRL_PLL1POSTDIVA_OUTEN0_Pos)   /* (OSCCTRL_PLL1POSTDIVA) PLL output 0 enable Mask */
#define OSCCTRL_PLL1POSTDIVA_OUTEN0(value)    (OSCCTRL_PLL1POSTDIVA_OUTEN0_Msk & (_UINT32_(value) << OSCCTRL_PLL1POSTDIVA_OUTEN0_Pos)) /* Assigment of value for OUTEN0 in the OSCCTRL_PLL1POSTDIVA register */
#define OSCCTRL_PLL1POSTDIVA_POSTDIV1_Pos     _UINT32_(8)                                          /* (OSCCTRL_PLL1POSTDIVA) PLL output 0 clock division factor Position */
#define OSCCTRL_PLL1POSTDIVA_POSTDIV1_Msk     (_UINT32_(0x3F) << OSCCTRL_PLL1POSTDIVA_POSTDIV1_Pos) /* (OSCCTRL_PLL1POSTDIVA) PLL output 0 clock division factor Mask */
#define OSCCTRL_PLL1POSTDIVA_POSTDIV1(value)  (OSCCTRL_PLL1POSTDIVA_POSTDIV1_Msk & (_UINT32_(value) << OSCCTRL_PLL1POSTDIVA_POSTDIV1_Pos)) /* Assigment of value for POSTDIV1 in the OSCCTRL_PLL1POSTDIVA register */
#define OSCCTRL_PLL1POSTDIVA_OUTEN1_Pos       _UINT32_(15)                                         /* (OSCCTRL_PLL1POSTDIVA) PLL output 0 enable Position */
#define OSCCTRL_PLL1POSTDIVA_OUTEN1_Msk       (_UINT32_(0x1) << OSCCTRL_PLL1POSTDIVA_OUTEN1_Pos)   /* (OSCCTRL_PLL1POSTDIVA) PLL output 0 enable Mask */
#define OSCCTRL_PLL1POSTDIVA_OUTEN1(value)    (OSCCTRL_PLL1POSTDIVA_OUTEN1_Msk & (_UINT32_(value) << OSCCTRL_PLL1POSTDIVA_OUTEN1_Pos)) /* Assigment of value for OUTEN1 in the OSCCTRL_PLL1POSTDIVA register */
#define OSCCTRL_PLL1POSTDIVA_POSTDIV2_Pos     _UINT32_(16)                                         /* (OSCCTRL_PLL1POSTDIVA) PLL output 0 clock division factor Position */
#define OSCCTRL_PLL1POSTDIVA_POSTDIV2_Msk     (_UINT32_(0x3F) << OSCCTRL_PLL1POSTDIVA_POSTDIV2_Pos) /* (OSCCTRL_PLL1POSTDIVA) PLL output 0 clock division factor Mask */
#define OSCCTRL_PLL1POSTDIVA_POSTDIV2(value)  (OSCCTRL_PLL1POSTDIVA_POSTDIV2_Msk & (_UINT32_(value) << OSCCTRL_PLL1POSTDIVA_POSTDIV2_Pos)) /* Assigment of value for POSTDIV2 in the OSCCTRL_PLL1POSTDIVA register */
#define OSCCTRL_PLL1POSTDIVA_OUTEN2_Pos       _UINT32_(23)                                         /* (OSCCTRL_PLL1POSTDIVA) PLL output 0 enable Position */
#define OSCCTRL_PLL1POSTDIVA_OUTEN2_Msk       (_UINT32_(0x1) << OSCCTRL_PLL1POSTDIVA_OUTEN2_Pos)   /* (OSCCTRL_PLL1POSTDIVA) PLL output 0 enable Mask */
#define OSCCTRL_PLL1POSTDIVA_OUTEN2(value)    (OSCCTRL_PLL1POSTDIVA_OUTEN2_Msk & (_UINT32_(value) << OSCCTRL_PLL1POSTDIVA_OUTEN2_Pos)) /* Assigment of value for OUTEN2 in the OSCCTRL_PLL1POSTDIVA register */
#define OSCCTRL_PLL1POSTDIVA_POSTDIV3_Pos     _UINT32_(24)                                         /* (OSCCTRL_PLL1POSTDIVA) PLL output 0 clock division factor Position */
#define OSCCTRL_PLL1POSTDIVA_POSTDIV3_Msk     (_UINT32_(0x3F) << OSCCTRL_PLL1POSTDIVA_POSTDIV3_Pos) /* (OSCCTRL_PLL1POSTDIVA) PLL output 0 clock division factor Mask */
#define OSCCTRL_PLL1POSTDIVA_POSTDIV3(value)  (OSCCTRL_PLL1POSTDIVA_POSTDIV3_Msk & (_UINT32_(value) << OSCCTRL_PLL1POSTDIVA_POSTDIV3_Pos)) /* Assigment of value for POSTDIV3 in the OSCCTRL_PLL1POSTDIVA register */
#define OSCCTRL_PLL1POSTDIVA_OUTEN3_Pos       _UINT32_(31)                                         /* (OSCCTRL_PLL1POSTDIVA) PLL output 0 enable Position */
#define OSCCTRL_PLL1POSTDIVA_OUTEN3_Msk       (_UINT32_(0x1) << OSCCTRL_PLL1POSTDIVA_OUTEN3_Pos)   /* (OSCCTRL_PLL1POSTDIVA) PLL output 0 enable Mask */
#define OSCCTRL_PLL1POSTDIVA_OUTEN3(value)    (OSCCTRL_PLL1POSTDIVA_OUTEN3_Msk & (_UINT32_(value) << OSCCTRL_PLL1POSTDIVA_OUTEN3_Pos)) /* Assigment of value for OUTEN3 in the OSCCTRL_PLL1POSTDIVA register */
#define OSCCTRL_PLL1POSTDIVA_Msk              _UINT32_(0xBFBFBFBF)                                 /* (OSCCTRL_PLL1POSTDIVA) Register Mask  */


/* -------- OSCCTRL_FRACDIV0 : (OSCCTRL Offset: 0x6C) (R/W 32) Fractional Divider -------- */
#define OSCCTRL_FRACDIV0_RESETVALUE           _UINT32_(0x200000)                                   /*  (OSCCTRL_FRACDIV0) Fractional Divider  Reset Value */

#define OSCCTRL_FRACDIV0_REMDIV_Pos           _UINT32_(7)                                          /* (OSCCTRL_FRACDIV0) Frequency division factor reminder part Position */
#define OSCCTRL_FRACDIV0_REMDIV_Msk           (_UINT32_(0x1FF) << OSCCTRL_FRACDIV0_REMDIV_Pos)     /* (OSCCTRL_FRACDIV0) Frequency division factor reminder part Mask */
#define OSCCTRL_FRACDIV0_REMDIV(value)        (OSCCTRL_FRACDIV0_REMDIV_Msk & (_UINT32_(value) << OSCCTRL_FRACDIV0_REMDIV_Pos)) /* Assigment of value for REMDIV in the OSCCTRL_FRACDIV0 register */
#define OSCCTRL_FRACDIV0_INTDIV_Pos           _UINT32_(16)                                         /* (OSCCTRL_FRACDIV0) Frequency division factor integer part Position */
#define OSCCTRL_FRACDIV0_INTDIV_Msk           (_UINT32_(0x7FFF) << OSCCTRL_FRACDIV0_INTDIV_Pos)    /* (OSCCTRL_FRACDIV0) Frequency division factor integer part Mask */
#define OSCCTRL_FRACDIV0_INTDIV(value)        (OSCCTRL_FRACDIV0_INTDIV_Msk & (_UINT32_(value) << OSCCTRL_FRACDIV0_INTDIV_Pos)) /* Assigment of value for INTDIV in the OSCCTRL_FRACDIV0 register */
#define OSCCTRL_FRACDIV0_Msk                  _UINT32_(0x7FFFFF80)                                 /* (OSCCTRL_FRACDIV0) Register Mask  */


/* -------- OSCCTRL_FRACDIV1 : (OSCCTRL Offset: 0x74) (R/W 32) Fractional Divider -------- */
#define OSCCTRL_FRACDIV1_RESETVALUE           _UINT32_(0x200000)                                   /*  (OSCCTRL_FRACDIV1) Fractional Divider  Reset Value */

#define OSCCTRL_FRACDIV1_REMDIV_Pos           _UINT32_(7)                                          /* (OSCCTRL_FRACDIV1) Frequency division factor reminder part Position */
#define OSCCTRL_FRACDIV1_REMDIV_Msk           (_UINT32_(0x1FF) << OSCCTRL_FRACDIV1_REMDIV_Pos)     /* (OSCCTRL_FRACDIV1) Frequency division factor reminder part Mask */
#define OSCCTRL_FRACDIV1_REMDIV(value)        (OSCCTRL_FRACDIV1_REMDIV_Msk & (_UINT32_(value) << OSCCTRL_FRACDIV1_REMDIV_Pos)) /* Assigment of value for REMDIV in the OSCCTRL_FRACDIV1 register */
#define OSCCTRL_FRACDIV1_INTDIV_Pos           _UINT32_(16)                                         /* (OSCCTRL_FRACDIV1) Frequency division factor integer part Position */
#define OSCCTRL_FRACDIV1_INTDIV_Msk           (_UINT32_(0x7FFF) << OSCCTRL_FRACDIV1_INTDIV_Pos)    /* (OSCCTRL_FRACDIV1) Frequency division factor integer part Mask */
#define OSCCTRL_FRACDIV1_INTDIV(value)        (OSCCTRL_FRACDIV1_INTDIV_Msk & (_UINT32_(value) << OSCCTRL_FRACDIV1_INTDIV_Pos)) /* Assigment of value for INTDIV in the OSCCTRL_FRACDIV1 register */
#define OSCCTRL_FRACDIV1_Msk                  _UINT32_(0x7FFFFF80)                                 /* (OSCCTRL_FRACDIV1) Register Mask  */


/* -------- OSCCTRL_SYNCBUSY : (OSCCTRL Offset: 0x78) ( R/ 32) Synchronization Busy -------- */
#define OSCCTRL_SYNCBUSY_RESETVALUE           _UINT32_(0x00)                                       /*  (OSCCTRL_SYNCBUSY) Synchronization Busy  Reset Value */

#define OSCCTRL_SYNCBUSY_DFLLENABLE_Pos       _UINT32_(1)                                          /* (OSCCTRL_SYNCBUSY) DFLL48M ENABLE Synchronization Busy Position */
#define OSCCTRL_SYNCBUSY_DFLLENABLE_Msk       (_UINT32_(0x1) << OSCCTRL_SYNCBUSY_DFLLENABLE_Pos)   /* (OSCCTRL_SYNCBUSY) DFLL48M ENABLE Synchronization Busy Mask */
#define OSCCTRL_SYNCBUSY_DFLLENABLE(value)    (OSCCTRL_SYNCBUSY_DFLLENABLE_Msk & (_UINT32_(value) << OSCCTRL_SYNCBUSY_DFLLENABLE_Pos)) /* Assigment of value for DFLLENABLE in the OSCCTRL_SYNCBUSY register */
#define OSCCTRL_SYNCBUSY_DFLLCTRLB_Pos        _UINT32_(2)                                          /* (OSCCTRL_SYNCBUSY) DFLLCTRLB Synchronization Busy Position */
#define OSCCTRL_SYNCBUSY_DFLLCTRLB_Msk        (_UINT32_(0x1) << OSCCTRL_SYNCBUSY_DFLLCTRLB_Pos)    /* (OSCCTRL_SYNCBUSY) DFLLCTRLB Synchronization Busy Mask */
#define OSCCTRL_SYNCBUSY_DFLLCTRLB(value)     (OSCCTRL_SYNCBUSY_DFLLCTRLB_Msk & (_UINT32_(value) << OSCCTRL_SYNCBUSY_DFLLCTRLB_Pos)) /* Assigment of value for DFLLCTRLB in the OSCCTRL_SYNCBUSY register */
#define OSCCTRL_SYNCBUSY_DFLLTUNE_Pos         _UINT32_(3)                                          /* (OSCCTRL_SYNCBUSY) DFLLTUNE Synchronization Busy Position */
#define OSCCTRL_SYNCBUSY_DFLLTUNE_Msk         (_UINT32_(0x1) << OSCCTRL_SYNCBUSY_DFLLTUNE_Pos)     /* (OSCCTRL_SYNCBUSY) DFLLTUNE Synchronization Busy Mask */
#define OSCCTRL_SYNCBUSY_DFLLTUNE(value)      (OSCCTRL_SYNCBUSY_DFLLTUNE_Msk & (_UINT32_(value) << OSCCTRL_SYNCBUSY_DFLLTUNE_Pos)) /* Assigment of value for DFLLTUNE in the OSCCTRL_SYNCBUSY register */
#define OSCCTRL_SYNCBUSY_DFLLDIFF_Pos         _UINT32_(4)                                          /* (OSCCTRL_SYNCBUSY) DFLLDIFF Synchronization Busy Position */
#define OSCCTRL_SYNCBUSY_DFLLDIFF_Msk         (_UINT32_(0x1) << OSCCTRL_SYNCBUSY_DFLLDIFF_Pos)     /* (OSCCTRL_SYNCBUSY) DFLLDIFF Synchronization Busy Mask */
#define OSCCTRL_SYNCBUSY_DFLLDIFF(value)      (OSCCTRL_SYNCBUSY_DFLLDIFF_Msk & (_UINT32_(value) << OSCCTRL_SYNCBUSY_DFLLDIFF_Pos)) /* Assigment of value for DFLLDIFF in the OSCCTRL_SYNCBUSY register */
#define OSCCTRL_SYNCBUSY_DFLLMUL_Pos          _UINT32_(5)                                          /* (OSCCTRL_SYNCBUSY) DFLLMUL Synchronization Busy Position */
#define OSCCTRL_SYNCBUSY_DFLLMUL_Msk          (_UINT32_(0x1) << OSCCTRL_SYNCBUSY_DFLLMUL_Pos)      /* (OSCCTRL_SYNCBUSY) DFLLMUL Synchronization Busy Mask */
#define OSCCTRL_SYNCBUSY_DFLLMUL(value)       (OSCCTRL_SYNCBUSY_DFLLMUL_Msk & (_UINT32_(value) << OSCCTRL_SYNCBUSY_DFLLMUL_Pos)) /* Assigment of value for DFLLMUL in the OSCCTRL_SYNCBUSY register */
#define OSCCTRL_SYNCBUSY_FRACDIV0_Pos         _UINT32_(6)                                          /* (OSCCTRL_SYNCBUSY) FRACDIV0 Synchronization Busy Position */
#define OSCCTRL_SYNCBUSY_FRACDIV0_Msk         (_UINT32_(0x1) << OSCCTRL_SYNCBUSY_FRACDIV0_Pos)     /* (OSCCTRL_SYNCBUSY) FRACDIV0 Synchronization Busy Mask */
#define OSCCTRL_SYNCBUSY_FRACDIV0(value)      (OSCCTRL_SYNCBUSY_FRACDIV0_Msk & (_UINT32_(value) << OSCCTRL_SYNCBUSY_FRACDIV0_Pos)) /* Assigment of value for FRACDIV0 in the OSCCTRL_SYNCBUSY register */
#define OSCCTRL_SYNCBUSY_FRACDIV1_Pos         _UINT32_(7)                                          /* (OSCCTRL_SYNCBUSY) FRACDIV1 Synchronization Busy Position */
#define OSCCTRL_SYNCBUSY_FRACDIV1_Msk         (_UINT32_(0x1) << OSCCTRL_SYNCBUSY_FRACDIV1_Pos)     /* (OSCCTRL_SYNCBUSY) FRACDIV1 Synchronization Busy Mask */
#define OSCCTRL_SYNCBUSY_FRACDIV1(value)      (OSCCTRL_SYNCBUSY_FRACDIV1_Msk & (_UINT32_(value) << OSCCTRL_SYNCBUSY_FRACDIV1_Pos)) /* Assigment of value for FRACDIV1 in the OSCCTRL_SYNCBUSY register */
#define OSCCTRL_SYNCBUSY_Msk                  _UINT32_(0x000000FE)                                 /* (OSCCTRL_SYNCBUSY) Register Mask  */

#define OSCCTRL_SYNCBUSY_FRACDIV_Pos          _UINT32_(6)                                          /* (OSCCTRL_SYNCBUSY Position) FRACDIVx Synchronization Busy */
#define OSCCTRL_SYNCBUSY_FRACDIV_Msk          (_UINT32_(0x3) << OSCCTRL_SYNCBUSY_FRACDIV_Pos)      /* (OSCCTRL_SYNCBUSY Mask) FRACDIV */
#define OSCCTRL_SYNCBUSY_FRACDIV(value)       (OSCCTRL_SYNCBUSY_FRACDIV_Msk & (_UINT32_(value) << OSCCTRL_SYNCBUSY_FRACDIV_Pos)) 

/* -------- OSCCTRL_XOSCCAL : (OSCCTRL Offset: 0x80) (R/W 32) XOSC Calibration Register -------- */
#define OSCCTRL_XOSCCAL_RESETVALUE            _UINT32_(0x00)                                       /*  (OSCCTRL_XOSCCAL) XOSC Calibration Register  Reset Value */

#define OSCCTRL_XOSCCAL_CAL_Pos               _UINT32_(0)                                          /* (OSCCTRL_XOSCCAL) XOSC Calibration Position */
#define OSCCTRL_XOSCCAL_CAL_Msk               (_UINT32_(0xFFFF) << OSCCTRL_XOSCCAL_CAL_Pos)        /* (OSCCTRL_XOSCCAL) XOSC Calibration Mask */
#define OSCCTRL_XOSCCAL_CAL(value)            (OSCCTRL_XOSCCAL_CAL_Msk & (_UINT32_(value) << OSCCTRL_XOSCCAL_CAL_Pos)) /* Assigment of value for CAL in the OSCCTRL_XOSCCAL register */
#define OSCCTRL_XOSCCAL_Msk                   _UINT32_(0x0000FFFF)                                 /* (OSCCTRL_XOSCCAL) Register Mask  */

/* FUSES_OSC_XTAL_HF_AGC_V2 mode */
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_FTRANS_Pos _UINT32_(0)                                          /* (OSCCTRL_XOSCCAL) Fine Transconductance programmability for Oscillator Position */
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_FTRANS_Msk (_UINT32_(0x3) << OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_FTRANS_Pos) /* (OSCCTRL_XOSCCAL) Fine Transconductance programmability for Oscillator Mask */
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_FTRANS(value) (OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_FTRANS_Msk & (_UINT32_(value) << OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_FTRANS_Pos))
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_KICKEREN_Pos _UINT32_(2)                                          /* (OSCCTRL_XOSCCAL) Kicker enable Position */
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_KICKEREN_Msk (_UINT32_(0x1) << OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_KICKEREN_Pos) /* (OSCCTRL_XOSCCAL) Kicker enable Mask */
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_KICKEREN(value) (OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_KICKEREN_Msk & (_UINT32_(value) << OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_KICKEREN_Pos))
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_ENVAMP_Pos _UINT32_(3)                                          /* (OSCCTRL_XOSCCAL) envelope amplitude at osci Position */
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_ENVAMP_Msk (_UINT32_(0x3) << OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_ENVAMP_Pos) /* (OSCCTRL_XOSCCAL) envelope amplitude at osci Mask */
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_ENVAMP(value) (OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_ENVAMP_Msk & (_UINT32_(value) << OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_ENVAMP_Pos))
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_HYST_Pos _UINT32_(5)                                          /* (OSCCTRL_XOSCCAL) loop hysteresis control Position */
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_HYST_Msk (_UINT32_(0x1) << OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_HYST_Pos) /* (OSCCTRL_XOSCCAL) loop hysteresis control Mask */
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_HYST(value) (OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_HYST_Msk & (_UINT32_(value) << OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_HYST_Pos))
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_CMSEL_Pos _UINT32_(6)                                          /* (OSCCTRL_XOSCCAL) clock buffer common mode selection Position */
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_CMSEL_Msk (_UINT32_(0x1) << OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_CMSEL_Pos) /* (OSCCTRL_XOSCCAL) clock buffer common mode selection Mask */
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_CMSEL(value) (OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_CMSEL_Msk & (_UINT32_(value) << OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_CMSEL_Pos))
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_FLIPPOL_Pos _UINT32_(7)                                          /* (OSCCTRL_XOSCCAL) flip output clock polarity Position */
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_FLIPPOL_Msk (_UINT32_(0x1) << OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_FLIPPOL_Pos) /* (OSCCTRL_XOSCCAL) flip output clock polarity Mask */
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_FLIPPOL(value) (OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_FLIPPOL_Msk & (_UINT32_(value) << OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_FLIPPOL_Pos))
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_REDGAIN_Pos _UINT32_(8)                                          /* (OSCCTRL_XOSCCAL) reduce gain control timer Position */
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_REDGAIN_Msk (_UINT32_(0x1) << OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_REDGAIN_Pos) /* (OSCCTRL_XOSCCAL) reduce gain control timer Mask */
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_REDGAIN(value) (OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_REDGAIN_Msk & (_UINT32_(value) << OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_REDGAIN_Pos))
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_REDOSC_Pos _UINT32_(9)                                          /* (OSCCTRL_XOSCCAL) reduce oscillation debug counter Position */
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_REDOSC_Msk (_UINT32_(0x1) << OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_REDOSC_Pos) /* (OSCCTRL_XOSCCAL) reduce oscillation debug counter Mask */
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_REDOSC(value) (OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_REDOSC_Msk & (_UINT32_(value) << OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_REDOSC_Pos))
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_SPARES_Pos _UINT32_(10)                                         /* (OSCCTRL_XOSCCAL) Spare bits Position */
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_SPARES_Msk (_UINT32_(0x3F) << OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_SPARES_Pos) /* (OSCCTRL_XOSCCAL) Spare bits Mask */
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_SPARES(value) (OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_SPARES_Msk & (_UINT32_(value) << OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_SPARES_Pos))
#define OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2_Msk _UINT32_(0x0000FFFF)                                  /* (OSCCTRL_XOSCCAL_FUSES_OSC_XTAL_HF_AGC_V2) Register Mask  */


/* -------- OSCCTRL_RC48MCAL0 : (OSCCTRL Offset: 0x88) (R/W 32) RC48M Calibration 0 -------- */
#define OSCCTRL_RC48MCAL0_RESETVALUE          _UINT32_(0x00)                                       /*  (OSCCTRL_RC48MCAL0) RC48M Calibration 0  Reset Value */

#define OSCCTRL_RC48MCAL0_CAL_Pos             _UINT32_(0)                                          /* (OSCCTRL_RC48MCAL0) RC48M Calibration Position */
#define OSCCTRL_RC48MCAL0_CAL_Msk             (_UINT32_(0xFFFFFFFF) << OSCCTRL_RC48MCAL0_CAL_Pos)  /* (OSCCTRL_RC48MCAL0) RC48M Calibration Mask */
#define OSCCTRL_RC48MCAL0_CAL(value)          (OSCCTRL_RC48MCAL0_CAL_Msk & (_UINT32_(value) << OSCCTRL_RC48MCAL0_CAL_Pos)) /* Assigment of value for CAL in the OSCCTRL_RC48MCAL0 register */
#define OSCCTRL_RC48MCAL0_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (OSCCTRL_RC48MCAL0) Register Mask  */

/* FUSES_OSC_RC48MHZ_V1 mode */
#define OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_temp_trim_mv_Pos _UINT32_(0)                                          /* (OSCCTRL_RC48MCAL0) Temp trim value Position */
#define OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_temp_trim_mv_Msk (_UINT32_(0x3F) << OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_temp_trim_mv_Pos) /* (OSCCTRL_RC48MCAL0) Temp trim value Mask */
#define OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_temp_trim_mv(value) (OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_temp_trim_mv_Msk & (_UINT32_(value) << OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_temp_trim_mv_Pos))
#define OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_proc_trim_mv_Pos _UINT32_(6)                                          /* (OSCCTRL_RC48MCAL0) Proc trim value Position */
#define OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_proc_trim_mv_Msk (_UINT32_(0xFF) << OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_proc_trim_mv_Pos) /* (OSCCTRL_RC48MCAL0) Proc trim value Mask */
#define OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_proc_trim_mv(value) (OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_proc_trim_mv_Msk & (_UINT32_(value) << OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_proc_trim_mv_Pos))
#define OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_iosc_boost_Pos _UINT32_(16)                                         /* (OSCCTRL_RC48MCAL0) IOSC boost Position */
#define OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_iosc_boost_Msk (_UINT32_(0x1) << OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_iosc_boost_Pos) /* (OSCCTRL_RC48MCAL0) IOSC boost Mask */
#define OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_iosc_boost(value) (OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_iosc_boost_Msk & (_UINT32_(value) << OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_iosc_boost_Pos))
#define OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_out_buf_sel_Pos _UINT32_(17)                                         /* (OSCCTRL_RC48MCAL0) Output buffer select Position */
#define OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_out_buf_sel_Msk (_UINT32_(0x1) << OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_out_buf_sel_Pos) /* (OSCCTRL_RC48MCAL0) Output buffer select Mask */
#define OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_out_buf_sel(value) (OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_out_buf_sel_Msk & (_UINT32_(value) << OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_out_buf_sel_Pos))
#define OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_ldo_vout_boost_Pos _UINT32_(18)                                         /* (OSCCTRL_RC48MCAL0) LDO VOUT boost Position */
#define OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_ldo_vout_boost_Msk (_UINT32_(0x1) << OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_ldo_vout_boost_Pos) /* (OSCCTRL_RC48MCAL0) LDO VOUT boost Mask */
#define OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_ldo_vout_boost(value) (OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_ldo_vout_boost_Msk & (_UINT32_(value) << OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_ldo_vout_boost_Pos))
#define OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_cmp_8m_lp_Pos _UINT32_(19)                                         /* (OSCCTRL_RC48MCAL0) Comparator 8MHz low-power Position */
#define OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_cmp_8m_lp_Msk (_UINT32_(0x1) << OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_cmp_8m_lp_Pos) /* (OSCCTRL_RC48MCAL0) Comparator 8MHz low-power Mask */
#define OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_cmp_8m_lp(value) (OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_cmp_8m_lp_Msk & (_UINT32_(value) << OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_cmp_8m_lp_Pos))
#define OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_cmp_pwr_ctrl_Pos _UINT32_(20)                                         /* (OSCCTRL_RC48MCAL0) Comparator power control Position */
#define OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_cmp_pwr_ctrl_Msk (_UINT32_(0x7) << OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_cmp_pwr_ctrl_Pos) /* (OSCCTRL_RC48MCAL0) Comparator power control Mask */
#define OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_cmp_pwr_ctrl(value) (OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_cmp_pwr_ctrl_Msk & (_UINT32_(value) << OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_cmp_pwr_ctrl_Pos))
#define OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1_Msk _UINT32_(0x007F3FFF)                                  /* (OSCCTRL_RC48MCAL0_FUSES_OSC_RC48MHZ_V1) Register Mask  */


/** \brief OSCCTRL register offsets definitions */
#define OSCCTRL_EVCTRL_REG_OFST        _UINT32_(0x00)      /* (OSCCTRL_EVCTRL) Event Control Offset */
#define OSCCTRL_INTENCLR_REG_OFST      _UINT32_(0x04)      /* (OSCCTRL_INTENCLR) Interrupt Enable Clear Offset */
#define OSCCTRL_INTENSET_REG_OFST      _UINT32_(0x08)      /* (OSCCTRL_INTENSET) Interrupt Enable Set Offset */
#define OSCCTRL_INTFLAG_REG_OFST       _UINT32_(0x0C)      /* (OSCCTRL_INTFLAG) Interrupt Flag Status and Clear Offset */
#define OSCCTRL_STATUS_REG_OFST        _UINT32_(0x10)      /* (OSCCTRL_STATUS) Status Offset */
#define OSCCTRL_XOSCCTRLA_REG_OFST     _UINT32_(0x14)      /* (OSCCTRL_XOSCCTRLA) External Multipurpose Crystal Oscillator Control A Offset */
#define OSCCTRL_XOSCCTRLB_REG_OFST     _UINT32_(0x18)      /* (OSCCTRL_XOSCCTRLB) External Multipurpose Crystal Oscillator Control B Offset */
#define OSCCTRL_DFLLCTRLA_REG_OFST     _UINT32_(0x2C)      /* (OSCCTRL_DFLLCTRLA) DFLL48M Control A Offset */
#define OSCCTRL_DFLLCTRLB_REG_OFST     _UINT32_(0x30)      /* (OSCCTRL_DFLLCTRLB) DFLL48M Control B Offset */
#define OSCCTRL_DFLLTUNE_REG_OFST      _UINT32_(0x34)      /* (OSCCTRL_DFLLTUNE) DFLL48M Tune Offset */
#define OSCCTRL_DFLLDIFF_REG_OFST      _UINT32_(0x38)      /* (OSCCTRL_DFLLDIFF) DFLL48M Diff Offset */
#define OSCCTRL_DFLLMUL_REG_OFST       _UINT32_(0x3C)      /* (OSCCTRL_DFLLMUL) DFLL48M Multiplier Offset */
#define OSCCTRL_PLL0CTRL_REG_OFST      _UINT32_(0x40)      /* (OSCCTRL_PLL0CTRL) PLL Control Offset */
#define OSCCTRL_PLL0FBDIV_REG_OFST     _UINT32_(0x44)      /* (OSCCTRL_PLL0FBDIV) PLL Feed-Back Divider Offset */
#define OSCCTRL_PLL0REFDIV_REG_OFST    _UINT32_(0x48)      /* (OSCCTRL_PLL0REFDIV) PLL reference divider Offset */
#define OSCCTRL_PLL0POSTDIVA_REG_OFST  _UINT32_(0x4C)      /* (OSCCTRL_PLL0POSTDIVA) PLL output clock divider A Offset */
#define OSCCTRL_PLL1CTRL_REG_OFST      _UINT32_(0x54)      /* (OSCCTRL_PLL1CTRL) PLL Control Offset */
#define OSCCTRL_PLL1FBDIV_REG_OFST     _UINT32_(0x58)      /* (OSCCTRL_PLL1FBDIV) PLL Feed-Back Divider Offset */
#define OSCCTRL_PLL1REFDIV_REG_OFST    _UINT32_(0x5C)      /* (OSCCTRL_PLL1REFDIV) PLL reference divider Offset */
#define OSCCTRL_PLL1POSTDIVA_REG_OFST  _UINT32_(0x60)      /* (OSCCTRL_PLL1POSTDIVA) PLL output clock divider A Offset */
#define OSCCTRL_FRACDIV0_REG_OFST      _UINT32_(0x6C)      /* (OSCCTRL_FRACDIV0) Fractional Divider Offset */
#define OSCCTRL_FRACDIV1_REG_OFST      _UINT32_(0x74)      /* (OSCCTRL_FRACDIV1) Fractional Divider Offset */
#define OSCCTRL_SYNCBUSY_REG_OFST      _UINT32_(0x78)      /* (OSCCTRL_SYNCBUSY) Synchronization Busy Offset */
#define OSCCTRL_XOSCCAL_REG_OFST       _UINT32_(0x80)      /* (OSCCTRL_XOSCCAL) XOSC Calibration Register Offset */
#define OSCCTRL_RC48MCAL0_REG_OFST     _UINT32_(0x88)      /* (OSCCTRL_RC48MCAL0) RC48M Calibration 0 Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief OSCCTRL register API structure */
typedef struct
{  /* Oscillators Control */
  __IO  uint32_t                       OSCCTRL_EVCTRL;     /**< Offset: 0x00 (R/W  32) Event Control */
  __IO  uint32_t                       OSCCTRL_INTENCLR;   /**< Offset: 0x04 (R/W  32) Interrupt Enable Clear */
  __IO  uint32_t                       OSCCTRL_INTENSET;   /**< Offset: 0x08 (R/W  32) Interrupt Enable Set */
  __IO  uint32_t                       OSCCTRL_INTFLAG;    /**< Offset: 0x0C (R/W  32) Interrupt Flag Status and Clear */
  __I   uint32_t                       OSCCTRL_STATUS;     /**< Offset: 0x10 (R/   32) Status */
  __IO  uint32_t                       OSCCTRL_XOSCCTRLA;  /**< Offset: 0x14 (R/W  32) External Multipurpose Crystal Oscillator Control A */
  __IO  uint32_t                       OSCCTRL_XOSCCTRLB;  /**< Offset: 0x18 (R/W  32) External Multipurpose Crystal Oscillator Control B */
  __I   uint8_t                        Reserved1[0x10];
  __IO  uint32_t                       OSCCTRL_DFLLCTRLA;  /**< Offset: 0x2C (R/W  32) DFLL48M Control A */
  __IO  uint32_t                       OSCCTRL_DFLLCTRLB;  /**< Offset: 0x30 (R/W  32) DFLL48M Control B */
  __IO  uint32_t                       OSCCTRL_DFLLTUNE;   /**< Offset: 0x34 (R/W  32) DFLL48M Tune */
  __I   uint32_t                       OSCCTRL_DFLLDIFF;   /**< Offset: 0x38 (R/   32) DFLL48M Diff */
  __IO  uint32_t                       OSCCTRL_DFLLMUL;    /**< Offset: 0x3C (R/W  32) DFLL48M Multiplier */
  __IO  uint32_t                       OSCCTRL_PLL0CTRL;   /**< Offset: 0x40 (R/W  32) PLL Control */
  __IO  uint32_t                       OSCCTRL_PLL0FBDIV;  /**< Offset: 0x44 (R/W  32) PLL Feed-Back Divider */
  __IO  uint32_t                       OSCCTRL_PLL0REFDIV; /**< Offset: 0x48 (R/W  32) PLL reference divider */
  __IO  uint32_t                       OSCCTRL_PLL0POSTDIVA; /**< Offset: 0x4C (R/W  32) PLL output clock divider A */
  __I   uint8_t                        Reserved2[0x04];
  __IO  uint32_t                       OSCCTRL_PLL1CTRL;   /**< Offset: 0x54 (R/W  32) PLL Control */
  __IO  uint32_t                       OSCCTRL_PLL1FBDIV;  /**< Offset: 0x58 (R/W  32) PLL Feed-Back Divider */
  __IO  uint32_t                       OSCCTRL_PLL1REFDIV; /**< Offset: 0x5C (R/W  32) PLL reference divider */
  __IO  uint32_t                       OSCCTRL_PLL1POSTDIVA; /**< Offset: 0x60 (R/W  32) PLL output clock divider A */
  __I   uint8_t                        Reserved3[0x08];
  __IO  uint32_t                       OSCCTRL_FRACDIV0;   /**< Offset: 0x6C (R/W  32) Fractional Divider */
  __I   uint8_t                        Reserved4[0x04];
  __IO  uint32_t                       OSCCTRL_FRACDIV1;   /**< Offset: 0x74 (R/W  32) Fractional Divider */
  __I   uint32_t                       OSCCTRL_SYNCBUSY;   /**< Offset: 0x78 (R/   32) Synchronization Busy */
  __I   uint8_t                        Reserved5[0x04];
  __IO  uint32_t                       OSCCTRL_XOSCCAL;    /**< Offset: 0x80 (R/W  32) XOSC Calibration Register */
  __I   uint8_t                        Reserved6[0x04];
  __IO  uint32_t                       OSCCTRL_RC48MCAL0;  /**< Offset: 0x88 (R/W  32) RC48M Calibration 0 */
} oscctrl_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA80_OSCCTRL_COMPONENT_H_ */
