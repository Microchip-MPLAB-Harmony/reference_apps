/*
 * Component description for FCR
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
#ifndef _PIC32CZCA80_FCR_COMPONENT_H_
#define _PIC32CZCA80_FCR_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR FCR                                          */
/* ************************************************************************** */

/* -------- FCR_CTRLA : (FCR Offset: 0x00) (R/W 32) Control A Register -------- */
#define FCR_CTRLA_RESETVALUE                  _UINT32_(0x00)                                       /*  (FCR_CTRLA) Control A Register  Reset Value */

#define FCR_CTRLA_ARB_Pos                     _UINT32_(2)                                          /* (FCR_CTRLA) AHB Arbitration scheme Position */
#define FCR_CTRLA_ARB_Msk                     (_UINT32_(0x1) << FCR_CTRLA_ARB_Pos)                 /* (FCR_CTRLA) AHB Arbitration scheme Mask */
#define FCR_CTRLA_ARB(value)                  (FCR_CTRLA_ARB_Msk & (_UINT32_(value) << FCR_CTRLA_ARB_Pos)) /* Assigment of value for ARB in the FCR_CTRLA register */
#define FCR_CTRLA_FWS_Pos                     _UINT32_(8)                                          /* (FCR_CTRLA) Flash Access Time Defined in terms of AHB Clock Wait States Position */
#define FCR_CTRLA_FWS_Msk                     (_UINT32_(0xF) << FCR_CTRLA_FWS_Pos)                 /* (FCR_CTRLA) Flash Access Time Defined in terms of AHB Clock Wait States Mask */
#define FCR_CTRLA_FWS(value)                  (FCR_CTRLA_FWS_Msk & (_UINT32_(value) << FCR_CTRLA_FWS_Pos)) /* Assigment of value for FWS in the FCR_CTRLA register */
#define FCR_CTRLA_ADRWS_Pos                   _UINT32_(14)                                         /* (FCR_CTRLA) Address Wait State Enable Position */
#define FCR_CTRLA_ADRWS_Msk                   (_UINT32_(0x1) << FCR_CTRLA_ADRWS_Pos)               /* (FCR_CTRLA) Address Wait State Enable Mask */
#define FCR_CTRLA_ADRWS(value)                (FCR_CTRLA_ADRWS_Msk & (_UINT32_(value) << FCR_CTRLA_ADRWS_Pos)) /* Assigment of value for ADRWS in the FCR_CTRLA register */
#define FCR_CTRLA_AUTOWS_Pos                  _UINT32_(15)                                         /* (FCR_CTRLA) Automatic Wait State Enable. Position */
#define FCR_CTRLA_AUTOWS_Msk                  (_UINT32_(0x1) << FCR_CTRLA_AUTOWS_Pos)              /* (FCR_CTRLA) Automatic Wait State Enable. Mask */
#define FCR_CTRLA_AUTOWS(value)               (FCR_CTRLA_AUTOWS_Msk & (_UINT32_(value) << FCR_CTRLA_AUTOWS_Pos)) /* Assigment of value for AUTOWS in the FCR_CTRLA register */
#define FCR_CTRLA_RDBUFWS_Pos                 _UINT32_(16)                                         /* (FCR_CTRLA) Data returned from the Read Buffer match the Flash Wait States Position */
#define FCR_CTRLA_RDBUFWS_Msk                 (_UINT32_(0xF) << FCR_CTRLA_RDBUFWS_Pos)             /* (FCR_CTRLA) Data returned from the Read Buffer match the Flash Wait States Mask */
#define FCR_CTRLA_RDBUFWS(value)              (FCR_CTRLA_RDBUFWS_Msk & (_UINT32_(value) << FCR_CTRLA_RDBUFWS_Pos)) /* Assigment of value for RDBUFWS in the FCR_CTRLA register */
#define FCR_CTRLA_Msk                         _UINT32_(0x000FCF04)                                 /* (FCR_CTRLA) Register Mask  */


/* -------- FCR_CTRLB : (FCR Offset: 0x04) (R/W 32) Control B Register -------- */
#define FCR_CTRLB_RESETVALUE                  _UINT32_(0x00)                                       /*  (FCR_CTRLB) Control B Register  Reset Value */

#define FCR_CTRLB_PRM_Pos                     _UINT32_(0)                                          /* (FCR_CTRLB) Set NVM Power Reduction Mode Position */
#define FCR_CTRLB_PRM_Msk                     (_UINT32_(0x1) << FCR_CTRLB_PRM_Pos)                 /* (FCR_CTRLB) Set NVM Power Reduction Mode Mask */
#define FCR_CTRLB_PRM(value)                  (FCR_CTRLB_PRM_Msk & (_UINT32_(value) << FCR_CTRLB_PRM_Pos)) /* Assigment of value for PRM in the FCR_CTRLB register */
#define FCR_CTRLB_TEMP_Pos                    _UINT32_(1)                                          /* (FCR_CTRLB) NVM Operating Temperature Read Mode Position */
#define FCR_CTRLB_TEMP_Msk                    (_UINT32_(0x1) << FCR_CTRLB_TEMP_Pos)                /* (FCR_CTRLB) NVM Operating Temperature Read Mode Mask */
#define FCR_CTRLB_TEMP(value)                 (FCR_CTRLB_TEMP_Msk & (_UINT32_(value) << FCR_CTRLB_TEMP_Pos)) /* Assigment of value for TEMP in the FCR_CTRLB register */
#define FCR_CTRLB_SLP_Pos                     _UINT32_(8)                                          /* (FCR_CTRLB) NVM Power Reduction Mode selection during System Standby Sleep Position */
#define FCR_CTRLB_SLP_Msk                     (_UINT32_(0x3) << FCR_CTRLB_SLP_Pos)                 /* (FCR_CTRLB) NVM Power Reduction Mode selection during System Standby Sleep Mask */
#define FCR_CTRLB_SLP(value)                  (FCR_CTRLB_SLP_Msk & (_UINT32_(value) << FCR_CTRLB_SLP_Pos)) /* Assigment of value for SLP in the FCR_CTRLB register */
#define FCR_CTRLB_Msk                         _UINT32_(0x00000303)                                 /* (FCR_CTRLB) Register Mask  */


/* -------- FCR_INTENCLR : (FCR Offset: 0x08) (R/W 32) Interrupt Enable Clear Register -------- */
#define FCR_INTENCLR_RESETVALUE               _UINT32_(0x00)                                       /*  (FCR_INTENCLR) Interrupt Enable Clear Register  Reset Value */

#define FCR_INTENCLR_SERR_Pos                 _UINT32_(0)                                          /* (FCR_INTENCLR) Flash SEC Interrupt Clear Enable Position */
#define FCR_INTENCLR_SERR_Msk                 (_UINT32_(0x1) << FCR_INTENCLR_SERR_Pos)             /* (FCR_INTENCLR) Flash SEC Interrupt Clear Enable Mask */
#define FCR_INTENCLR_SERR(value)              (FCR_INTENCLR_SERR_Msk & (_UINT32_(value) << FCR_INTENCLR_SERR_Pos)) /* Assigment of value for SERR in the FCR_INTENCLR register */
#define FCR_INTENCLR_DERR_Pos                 _UINT32_(1)                                          /* (FCR_INTENCLR) ECC Double Error Detected Clear Enable Position */
#define FCR_INTENCLR_DERR_Msk                 (_UINT32_(0x1) << FCR_INTENCLR_DERR_Pos)             /* (FCR_INTENCLR) ECC Double Error Detected Clear Enable Mask */
#define FCR_INTENCLR_DERR(value)              (FCR_INTENCLR_DERR_Msk & (_UINT32_(value) << FCR_INTENCLR_DERR_Pos)) /* Assigment of value for DERR in the FCR_INTENCLR register */
#define FCR_INTENCLR_CRCDONE_Pos              _UINT32_(8)                                          /* (FCR_INTENCLR) CRC Calculation Done Clear Enable Position */
#define FCR_INTENCLR_CRCDONE_Msk              (_UINT32_(0x1) << FCR_INTENCLR_CRCDONE_Pos)          /* (FCR_INTENCLR) CRC Calculation Done Clear Enable Mask */
#define FCR_INTENCLR_CRCDONE(value)           (FCR_INTENCLR_CRCDONE_Msk & (_UINT32_(value) << FCR_INTENCLR_CRCDONE_Pos)) /* Assigment of value for CRCDONE in the FCR_INTENCLR register */
#define FCR_INTENCLR_CRCERR_Pos               _UINT32_(9)                                          /* (FCR_INTENCLR) CRC Error Clear Enable Position */
#define FCR_INTENCLR_CRCERR_Msk               (_UINT32_(0x1) << FCR_INTENCLR_CRCERR_Pos)           /* (FCR_INTENCLR) CRC Error Clear Enable Mask */
#define FCR_INTENCLR_CRCERR(value)            (FCR_INTENCLR_CRCERR_Msk & (_UINT32_(value) << FCR_INTENCLR_CRCERR_Pos)) /* Assigment of value for CRCERR in the FCR_INTENCLR register */
#define FCR_INTENCLR_FLTCAP_Pos               _UINT32_(16)                                         /* (FCR_INTENCLR) ECC Fault Capture Clear Enable Position */
#define FCR_INTENCLR_FLTCAP_Msk               (_UINT32_(0x1) << FCR_INTENCLR_FLTCAP_Pos)           /* (FCR_INTENCLR) ECC Fault Capture Clear Enable Mask */
#define FCR_INTENCLR_FLTCAP(value)            (FCR_INTENCLR_FLTCAP_Msk & (_UINT32_(value) << FCR_INTENCLR_FLTCAP_Pos)) /* Assigment of value for FLTCAP in the FCR_INTENCLR register */
#define FCR_INTENCLR_Msk                      _UINT32_(0x00010303)                                 /* (FCR_INTENCLR) Register Mask  */


/* -------- FCR_INTENSET : (FCR Offset: 0x0C) (R/W 32) Interrupt Enable SET Register -------- */
#define FCR_INTENSET_RESETVALUE               _UINT32_(0x00)                                       /*  (FCR_INTENSET) Interrupt Enable SET Register  Reset Value */

#define FCR_INTENSET_SERR_Pos                 _UINT32_(0)                                          /* (FCR_INTENSET) Flash Single Error Corrected Set Enable Position */
#define FCR_INTENSET_SERR_Msk                 (_UINT32_(0x1) << FCR_INTENSET_SERR_Pos)             /* (FCR_INTENSET) Flash Single Error Corrected Set Enable Mask */
#define FCR_INTENSET_SERR(value)              (FCR_INTENSET_SERR_Msk & (_UINT32_(value) << FCR_INTENSET_SERR_Pos)) /* Assigment of value for SERR in the FCR_INTENSET register */
#define FCR_INTENSET_DERR_Pos                 _UINT32_(1)                                          /* (FCR_INTENSET) ECC Double Error Detected Set Enable Position */
#define FCR_INTENSET_DERR_Msk                 (_UINT32_(0x1) << FCR_INTENSET_DERR_Pos)             /* (FCR_INTENSET) ECC Double Error Detected Set Enable Mask */
#define FCR_INTENSET_DERR(value)              (FCR_INTENSET_DERR_Msk & (_UINT32_(value) << FCR_INTENSET_DERR_Pos)) /* Assigment of value for DERR in the FCR_INTENSET register */
#define FCR_INTENSET_CRCDONE_Pos              _UINT32_(8)                                          /* (FCR_INTENSET) CRC Calculation Done Set Enable Position */
#define FCR_INTENSET_CRCDONE_Msk              (_UINT32_(0x1) << FCR_INTENSET_CRCDONE_Pos)          /* (FCR_INTENSET) CRC Calculation Done Set Enable Mask */
#define FCR_INTENSET_CRCDONE(value)           (FCR_INTENSET_CRCDONE_Msk & (_UINT32_(value) << FCR_INTENSET_CRCDONE_Pos)) /* Assigment of value for CRCDONE in the FCR_INTENSET register */
#define FCR_INTENSET_CRCERR_Pos               _UINT32_(9)                                          /* (FCR_INTENSET) CRC Error Interrupt Set Enable Position */
#define FCR_INTENSET_CRCERR_Msk               (_UINT32_(0x1) << FCR_INTENSET_CRCERR_Pos)           /* (FCR_INTENSET) CRC Error Interrupt Set Enable Mask */
#define FCR_INTENSET_CRCERR(value)            (FCR_INTENSET_CRCERR_Msk & (_UINT32_(value) << FCR_INTENSET_CRCERR_Pos)) /* Assigment of value for CRCERR in the FCR_INTENSET register */
#define FCR_INTENSET_FLTCAP_Pos               _UINT32_(16)                                         /* (FCR_INTENSET) ECC Fault Capture Interrupt Set Enable Position */
#define FCR_INTENSET_FLTCAP_Msk               (_UINT32_(0x1) << FCR_INTENSET_FLTCAP_Pos)           /* (FCR_INTENSET) ECC Fault Capture Interrupt Set Enable Mask */
#define FCR_INTENSET_FLTCAP(value)            (FCR_INTENSET_FLTCAP_Msk & (_UINT32_(value) << FCR_INTENSET_FLTCAP_Pos)) /* Assigment of value for FLTCAP in the FCR_INTENSET register */
#define FCR_INTENSET_Msk                      _UINT32_(0x00010303)                                 /* (FCR_INTENSET) Register Mask  */


/* -------- FCR_INTFLAG : (FCR Offset: 0x10) (R/W 32) Interrupt Flag Register -------- */
#define FCR_INTFLAG_RESETVALUE                _UINT32_(0x00)                                       /*  (FCR_INTFLAG) Interrupt Flag Register  Reset Value */

#define FCR_INTFLAG_SERR_Pos                  _UINT32_(0)                                          /* (FCR_INTFLAG) Flash Single Error Corrected Flag Position */
#define FCR_INTFLAG_SERR_Msk                  (_UINT32_(0x1) << FCR_INTFLAG_SERR_Pos)              /* (FCR_INTFLAG) Flash Single Error Corrected Flag Mask */
#define FCR_INTFLAG_SERR(value)               (FCR_INTFLAG_SERR_Msk & (_UINT32_(value) << FCR_INTFLAG_SERR_Pos)) /* Assigment of value for SERR in the FCR_INTFLAG register */
#define FCR_INTFLAG_DERR_Pos                  _UINT32_(1)                                          /* (FCR_INTFLAG) ECC Double Error Detected Flag Position */
#define FCR_INTFLAG_DERR_Msk                  (_UINT32_(0x1) << FCR_INTFLAG_DERR_Pos)              /* (FCR_INTFLAG) ECC Double Error Detected Flag Mask */
#define FCR_INTFLAG_DERR(value)               (FCR_INTFLAG_DERR_Msk & (_UINT32_(value) << FCR_INTFLAG_DERR_Pos)) /* Assigment of value for DERR in the FCR_INTFLAG register */
#define FCR_INTFLAG_CRCDONE_Pos               _UINT32_(8)                                          /* (FCR_INTFLAG) CRC Calculation Done Flag Position */
#define FCR_INTFLAG_CRCDONE_Msk               (_UINT32_(0x1) << FCR_INTFLAG_CRCDONE_Pos)           /* (FCR_INTFLAG) CRC Calculation Done Flag Mask */
#define FCR_INTFLAG_CRCDONE(value)            (FCR_INTFLAG_CRCDONE_Msk & (_UINT32_(value) << FCR_INTFLAG_CRCDONE_Pos)) /* Assigment of value for CRCDONE in the FCR_INTFLAG register */
#define FCR_INTFLAG_CRCERR_Pos                _UINT32_(9)                                          /* (FCR_INTFLAG) CRC Error Flag Position */
#define FCR_INTFLAG_CRCERR_Msk                (_UINT32_(0x1) << FCR_INTFLAG_CRCERR_Pos)            /* (FCR_INTFLAG) CRC Error Flag Mask */
#define FCR_INTFLAG_CRCERR(value)             (FCR_INTFLAG_CRCERR_Msk & (_UINT32_(value) << FCR_INTFLAG_CRCERR_Pos)) /* Assigment of value for CRCERR in the FCR_INTFLAG register */
#define FCR_INTFLAG_FLTCAP_Pos                _UINT32_(16)                                         /* (FCR_INTFLAG) ECC Fault Capture Flag Position */
#define FCR_INTFLAG_FLTCAP_Msk                (_UINT32_(0x1) << FCR_INTFLAG_FLTCAP_Pos)            /* (FCR_INTFLAG) ECC Fault Capture Flag Mask */
#define FCR_INTFLAG_FLTCAP(value)             (FCR_INTFLAG_FLTCAP_Msk & (_UINT32_(value) << FCR_INTFLAG_FLTCAP_Pos)) /* Assigment of value for FLTCAP in the FCR_INTFLAG register */
#define FCR_INTFLAG_Msk                       _UINT32_(0x00010303)                                 /* (FCR_INTFLAG) Register Mask  */


/* -------- FCR_STATUS : (FCR Offset: 0x14) ( R/ 32) NVM Status Register -------- */
#define FCR_STATUS_RESETVALUE                 _UINT32_(0x80000000)                                 /*  (FCR_STATUS) NVM Status Register  Reset Value */

#define FCR_STATUS_PRM_Pos                    _UINT32_(0)                                          /* (FCR_STATUS) NVM Power Reduction Mode Status Position */
#define FCR_STATUS_PRM_Msk                    (_UINT32_(0x1) << FCR_STATUS_PRM_Pos)                /* (FCR_STATUS) NVM Power Reduction Mode Status Mask */
#define FCR_STATUS_PRM(value)                 (FCR_STATUS_PRM_Msk & (_UINT32_(value) << FCR_STATUS_PRM_Pos)) /* Assigment of value for PRM in the FCR_STATUS register */
#define FCR_STATUS_TEMP_Pos                   _UINT32_(1)                                          /* (FCR_STATUS) NVM Operating Temperature Read Mode Status Position */
#define FCR_STATUS_TEMP_Msk                   (_UINT32_(0x1) << FCR_STATUS_TEMP_Pos)               /* (FCR_STATUS) NVM Operating Temperature Read Mode Status Mask */
#define FCR_STATUS_TEMP(value)                (FCR_STATUS_TEMP_Msk & (_UINT32_(value) << FCR_STATUS_TEMP_Pos)) /* Assigment of value for TEMP in the FCR_STATUS register */
#define FCR_STATUS_Msk                        _UINT32_(0x00000003)                                 /* (FCR_STATUS) Register Mask  */


/* -------- FCR_DBGCTRL : (FCR Offset: 0x18) (R/W 32) Debug Control Register -------- */
#define FCR_DBGCTRL_RESETVALUE                _UINT32_(0x00)                                       /*  (FCR_DBGCTRL) Debug Control Register  Reset Value */

#define FCR_DBGCTRL_CRCRUN_Pos                _UINT32_(0)                                          /* (FCR_DBGCTRL) CRC Debug Run Position */
#define FCR_DBGCTRL_CRCRUN_Msk                (_UINT32_(0x1) << FCR_DBGCTRL_CRCRUN_Pos)            /* (FCR_DBGCTRL) CRC Debug Run Mask */
#define FCR_DBGCTRL_CRCRUN(value)             (FCR_DBGCTRL_CRCRUN_Msk & (_UINT32_(value) << FCR_DBGCTRL_CRCRUN_Pos)) /* Assigment of value for CRCRUN in the FCR_DBGCTRL register */
#define FCR_DBGCTRL_DBGECC_Pos                _UINT32_(1)                                          /* (FCR_DBGCTRL) Debug ECC Mode Position */
#define FCR_DBGCTRL_DBGECC_Msk                (_UINT32_(0x3) << FCR_DBGCTRL_DBGECC_Pos)            /* (FCR_DBGCTRL) Debug ECC Mode Mask */
#define FCR_DBGCTRL_DBGECC(value)             (FCR_DBGCTRL_DBGECC_Msk & (_UINT32_(value) << FCR_DBGCTRL_DBGECC_Pos)) /* Assigment of value for DBGECC in the FCR_DBGCTRL register */
#define FCR_DBGCTRL_Msk                       _UINT32_(0x00000007)                                 /* (FCR_DBGCTRL) Register Mask  */


/* -------- FCR_ECCCTRL : (FCR Offset: 0x1C) (R/W 32) ECC Control Register -------- */
#define FCR_ECCCTRL_RESETVALUE                _UINT32_(0x40)                                       /*  (FCR_ECCCTRL) ECC Control Register  Reset Value */

#define FCR_ECCCTRL_ECCCTL_Pos                _UINT32_(4)                                          /* (FCR_ECCCTRL) NVM ECC Mode Control- restricts one or more NVMOPs Position */
#define FCR_ECCCTRL_ECCCTL_Msk                (_UINT32_(0x3) << FCR_ECCCTRL_ECCCTL_Pos)            /* (FCR_ECCCTRL) NVM ECC Mode Control- restricts one or more NVMOPs Mask */
#define FCR_ECCCTRL_ECCCTL(value)             (FCR_ECCCTRL_ECCCTL_Msk & (_UINT32_(value) << FCR_ECCCTRL_ECCCTL_Pos)) /* Assigment of value for ECCCTL in the FCR_ECCCTRL register */
#define FCR_ECCCTRL_ECCUNLCK_Pos              _UINT32_(6)                                          /* (FCR_ECCCTRL) NVM ECC Mode Control Unlock Position */
#define FCR_ECCCTRL_ECCUNLCK_Msk              (_UINT32_(0x1) << FCR_ECCCTRL_ECCUNLCK_Pos)          /* (FCR_ECCCTRL) NVM ECC Mode Control Unlock Mask */
#define FCR_ECCCTRL_ECCUNLCK(value)           (FCR_ECCCTRL_ECCUNLCK_Msk & (_UINT32_(value) << FCR_ECCCTRL_ECCUNLCK_Pos)) /* Assigment of value for ECCUNLCK in the FCR_ECCCTRL register */
#define FCR_ECCCTRL_SECCNT_Pos                _UINT32_(8)                                          /* (FCR_ECCCTRL) Flash SEC Count Position */
#define FCR_ECCCTRL_SECCNT_Msk                (_UINT32_(0xFF) << FCR_ECCCTRL_SECCNT_Pos)           /* (FCR_ECCCTRL) Flash SEC Count Mask */
#define FCR_ECCCTRL_SECCNT(value)             (FCR_ECCCTRL_SECCNT_Msk & (_UINT32_(value) << FCR_ECCCTRL_SECCNT_Pos)) /* Assigment of value for SECCNT in the FCR_ECCCTRL register */
#define FCR_ECCCTRL_Msk                       _UINT32_(0x0000FF70)                                 /* (FCR_ECCCTRL) Register Mask  */


/* -------- FCR_CRCCTRL : (FCR Offset: 0x20) (R/W 32) CRC Control Register -------- */
#define FCR_CRCCTRL_RESETVALUE                _UINT32_(0x00)                                       /*  (FCR_CRCCTRL) CRC Control Register  Reset Value */

#define FCR_CRCCTRL_CRCRST_Pos                _UINT32_(0)                                          /* (FCR_CRCCTRL) CRC Reset Position */
#define FCR_CRCCTRL_CRCRST_Msk                (_UINT32_(0x1) << FCR_CRCCTRL_CRCRST_Pos)            /* (FCR_CRCCTRL) CRC Reset Mask */
#define FCR_CRCCTRL_CRCRST(value)             (FCR_CRCCTRL_CRCRST_Msk & (_UINT32_(value) << FCR_CRCCTRL_CRCRST_Pos)) /* Assigment of value for CRCRST in the FCR_CRCCTRL register */
#define FCR_CRCCTRL_CRCEN_Pos                 _UINT32_(1)                                          /* (FCR_CRCCTRL) Start CRC Calculation Position */
#define FCR_CRCCTRL_CRCEN_Msk                 (_UINT32_(0x1) << FCR_CRCCTRL_CRCEN_Pos)             /* (FCR_CRCCTRL) Start CRC Calculation Mask */
#define FCR_CRCCTRL_CRCEN(value)              (FCR_CRCCTRL_CRCEN_Msk & (_UINT32_(value) << FCR_CRCCTRL_CRCEN_Pos)) /* Assigment of value for CRCEN in the FCR_CRCCTRL register */
#define FCR_CRCCTRL_RUNSTDBY_Pos              _UINT32_(5)                                          /* (FCR_CRCCTRL) CRC Run in Standby Position */
#define FCR_CRCCTRL_RUNSTDBY_Msk              (_UINT32_(0x1) << FCR_CRCCTRL_RUNSTDBY_Pos)          /* (FCR_CRCCTRL) CRC Run in Standby Mask */
#define FCR_CRCCTRL_RUNSTDBY(value)           (FCR_CRCCTRL_RUNSTDBY_Msk & (_UINT32_(value) << FCR_CRCCTRL_RUNSTDBY_Pos)) /* Assigment of value for RUNSTDBY in the FCR_CRCCTRL register */
#define FCR_CRCCTRL_PLEN32_Pos                _UINT32_(12)                                         /* (FCR_CRCCTRL) Polynomial Length Select Position */
#define FCR_CRCCTRL_PLEN32_Msk                (_UINT32_(0x1) << FCR_CRCCTRL_PLEN32_Pos)            /* (FCR_CRCCTRL) Polynomial Length Select Mask */
#define FCR_CRCCTRL_PLEN32(value)             (FCR_CRCCTRL_PLEN32_Msk & (_UINT32_(value) << FCR_CRCCTRL_PLEN32_Pos)) /* Assigment of value for PLEN32 in the FCR_CRCCTRL register */
#define FCR_CRCCTRL_AUTOR_Pos                 _UINT32_(13)                                         /* (FCR_CRCCTRL) CRC Auto Repeat Position */
#define FCR_CRCCTRL_AUTOR_Msk                 (_UINT32_(0x1) << FCR_CRCCTRL_AUTOR_Pos)             /* (FCR_CRCCTRL) CRC Auto Repeat Mask */
#define FCR_CRCCTRL_AUTOR(value)              (FCR_CRCCTRL_AUTOR_Msk & (_UINT32_(value) << FCR_CRCCTRL_AUTOR_Pos)) /* Assigment of value for AUTOR in the FCR_CRCCTRL register */
#define FCR_CRCCTRL_ROUT_Pos                  _UINT32_(14)                                         /* (FCR_CRCCTRL) CRC Reflected Output Position */
#define FCR_CRCCTRL_ROUT_Msk                  (_UINT32_(0x1) << FCR_CRCCTRL_ROUT_Pos)              /* (FCR_CRCCTRL) CRC Reflected Output Mask */
#define FCR_CRCCTRL_ROUT(value)               (FCR_CRCCTRL_ROUT_Msk & (_UINT32_(value) << FCR_CRCCTRL_ROUT_Pos)) /* Assigment of value for ROUT in the FCR_CRCCTRL register */
#define FCR_CRCCTRL_RIN_Pos                   _UINT32_(15)                                         /* (FCR_CRCCTRL) CRC Reflected Input Position */
#define FCR_CRCCTRL_RIN_Msk                   (_UINT32_(0x1) << FCR_CRCCTRL_RIN_Pos)               /* (FCR_CRCCTRL) CRC Reflected Input Mask */
#define FCR_CRCCTRL_RIN(value)                (FCR_CRCCTRL_RIN_Msk & (_UINT32_(value) << FCR_CRCCTRL_RIN_Pos)) /* Assigment of value for RIN in the FCR_CRCCTRL register */
#define FCR_CRCCTRL_PERIOD_Pos                _UINT32_(16)                                         /* (FCR_CRCCTRL) Read Period in GCLK counts Position */
#define FCR_CRCCTRL_PERIOD_Msk                (_UINT32_(0xFFFF) << FCR_CRCCTRL_PERIOD_Pos)         /* (FCR_CRCCTRL) Read Period in GCLK counts Mask */
#define FCR_CRCCTRL_PERIOD(value)             (FCR_CRCCTRL_PERIOD_Msk & (_UINT32_(value) << FCR_CRCCTRL_PERIOD_Pos)) /* Assigment of value for PERIOD in the FCR_CRCCTRL register */
#define FCR_CRCCTRL_Msk                       _UINT32_(0xFFFFF023)                                 /* (FCR_CRCCTRL) Register Mask  */

#define FCR_CRCCTRL_PLEN_Pos                  _UINT32_(12)                                         /* (FCR_CRCCTRL Position) Polynomial Length Select */
#define FCR_CRCCTRL_PLEN_Msk                  (_UINT32_(0x1) << FCR_CRCCTRL_PLEN_Pos)              /* (FCR_CRCCTRL Mask) PLEN */
#define FCR_CRCCTRL_PLEN(value)               (FCR_CRCCTRL_PLEN_Msk & (_UINT32_(value) << FCR_CRCCTRL_PLEN_Pos)) 

/* -------- FCR_CRCPAUSE : (FCR Offset: 0x24) (R/W 32) CRC PAUSE Register -------- */
#define FCR_CRCPAUSE_RESETVALUE               _UINT32_(0x00)                                       /*  (FCR_CRCPAUSE) CRC PAUSE Register  Reset Value */

#define FCR_CRCPAUSE_PAUSE_Pos                _UINT32_(0)                                          /* (FCR_CRCPAUSE) CRC Pause Position */
#define FCR_CRCPAUSE_PAUSE_Msk                (_UINT32_(0x1) << FCR_CRCPAUSE_PAUSE_Pos)            /* (FCR_CRCPAUSE) CRC Pause Mask */
#define FCR_CRCPAUSE_PAUSE(value)             (FCR_CRCPAUSE_PAUSE_Msk & (_UINT32_(value) << FCR_CRCPAUSE_PAUSE_Pos)) /* Assigment of value for PAUSE in the FCR_CRCPAUSE register */
#define FCR_CRCPAUSE_Msk                      _UINT32_(0x00000001)                                 /* (FCR_CRCPAUSE) Register Mask  */


/* -------- FCR_CRCMADR : (FCR Offset: 0x28) (R/W 32) CRC Message Address Register -------- */
#define FCR_CRCMADR_RESETVALUE                _UINT32_(0x00)                                       /*  (FCR_CRCMADR) CRC Message Address Register  Reset Value */

#define FCR_CRCMADR_CRCMADR_Pos               _UINT32_(0)                                          /* (FCR_CRCMADR) Message Start Address in Flash Position */
#define FCR_CRCMADR_CRCMADR_Msk               (_UINT32_(0xFFFFFFF) << FCR_CRCMADR_CRCMADR_Pos)     /* (FCR_CRCMADR) Message Start Address in Flash Mask */
#define FCR_CRCMADR_CRCMADR(value)            (FCR_CRCMADR_CRCMADR_Msk & (_UINT32_(value) << FCR_CRCMADR_CRCMADR_Pos)) /* Assigment of value for CRCMADR in the FCR_CRCMADR register */
#define FCR_CRCMADR_Msk                       _UINT32_(0x0FFFFFFF)                                 /* (FCR_CRCMADR) Register Mask  */


/* -------- FCR_CRCMLEN : (FCR Offset: 0x2C) (R/W 32) CRC Message Length Register -------- */
#define FCR_CRCMLEN_RESETVALUE                _UINT32_(0x00)                                       /*  (FCR_CRCMLEN) CRC Message Length Register  Reset Value */

#define FCR_CRCMLEN_CRCMLEN_Pos               _UINT32_(0)                                          /* (FCR_CRCMLEN) Message Length in Bytes Position */
#define FCR_CRCMLEN_CRCMLEN_Msk               (_UINT32_(0xFFFFFF) << FCR_CRCMLEN_CRCMLEN_Pos)      /* (FCR_CRCMLEN) Message Length in Bytes Mask */
#define FCR_CRCMLEN_CRCMLEN(value)            (FCR_CRCMLEN_CRCMLEN_Msk & (_UINT32_(value) << FCR_CRCMLEN_CRCMLEN_Pos)) /* Assigment of value for CRCMLEN in the FCR_CRCMLEN register */
#define FCR_CRCMLEN_Msk                       _UINT32_(0x00FFFFFF)                                 /* (FCR_CRCMLEN) Register Mask  */


/* -------- FCR_CRCIV : (FCR Offset: 0x30) (R/W 32) CRC Initial Value Register -------- */
#define FCR_CRCIV_RESETVALUE                  _UINT32_(0x00)                                       /*  (FCR_CRCIV) CRC Initial Value Register  Reset Value */

#define FCR_CRCIV_CRCIV_Pos                   _UINT32_(0)                                          /* (FCR_CRCIV) CRC Initial Value Position */
#define FCR_CRCIV_CRCIV_Msk                   (_UINT32_(0xFFFFFFFF) << FCR_CRCIV_CRCIV_Pos)        /* (FCR_CRCIV) CRC Initial Value Mask */
#define FCR_CRCIV_CRCIV(value)                (FCR_CRCIV_CRCIV_Msk & (_UINT32_(value) << FCR_CRCIV_CRCIV_Pos)) /* Assigment of value for CRCIV in the FCR_CRCIV register */
#define FCR_CRCIV_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (FCR_CRCIV) Register Mask  */


/* -------- FCR_CRCACC : (FCR Offset: 0x34) ( R/ 32) CRC Accumulator Register -------- */
#define FCR_CRCACC_RESETVALUE                 _UINT32_(0x00)                                       /*  (FCR_CRCACC) CRC Accumulator Register  Reset Value */

#define FCR_CRCACC_CRCACC_Pos                 _UINT32_(0)                                          /* (FCR_CRCACC) CRC Accumulator Result Position */
#define FCR_CRCACC_CRCACC_Msk                 (_UINT32_(0xFFFFFFFF) << FCR_CRCACC_CRCACC_Pos)      /* (FCR_CRCACC) CRC Accumulator Result Mask */
#define FCR_CRCACC_CRCACC(value)              (FCR_CRCACC_CRCACC_Msk & (_UINT32_(value) << FCR_CRCACC_CRCACC_Pos)) /* Assigment of value for CRCACC in the FCR_CRCACC register */
#define FCR_CRCACC_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (FCR_CRCACC) Register Mask  */


/* -------- FCR_CRCPOLY : (FCR Offset: 0x38) (R/W 32) CRC Polynomial Register -------- */
#define FCR_CRCPOLY_RESETVALUE                _UINT32_(0x00)                                       /*  (FCR_CRCPOLY) CRC Polynomial Register  Reset Value */

#define FCR_CRCPOLY_CRCPOLY_Pos               _UINT32_(0)                                          /* (FCR_CRCPOLY) CRC Polynomial Coefficients for LFSR Position */
#define FCR_CRCPOLY_CRCPOLY_Msk               (_UINT32_(0xFFFFFFFF) << FCR_CRCPOLY_CRCPOLY_Pos)    /* (FCR_CRCPOLY) CRC Polynomial Coefficients for LFSR Mask */
#define FCR_CRCPOLY_CRCPOLY(value)            (FCR_CRCPOLY_CRCPOLY_Msk & (_UINT32_(value) << FCR_CRCPOLY_CRCPOLY_Pos)) /* Assigment of value for CRCPOLY in the FCR_CRCPOLY register */
#define FCR_CRCPOLY_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (FCR_CRCPOLY) Register Mask  */


/* -------- FCR_CRCFXOR : (FCR Offset: 0x3C) (R/W 32) CRC Final XOR Register -------- */
#define FCR_CRCFXOR_RESETVALUE                _UINT32_(0x00)                                       /*  (FCR_CRCFXOR) CRC Final XOR Register  Reset Value */

#define FCR_CRCFXOR_CRCFXOR_Pos               _UINT32_(0)                                          /* (FCR_CRCFXOR) CRC Final XOR Position */
#define FCR_CRCFXOR_CRCFXOR_Msk               (_UINT32_(0xFFFFFFFF) << FCR_CRCFXOR_CRCFXOR_Pos)    /* (FCR_CRCFXOR) CRC Final XOR Mask */
#define FCR_CRCFXOR_CRCFXOR(value)            (FCR_CRCFXOR_CRCFXOR_Msk & (_UINT32_(value) << FCR_CRCFXOR_CRCFXOR_Pos)) /* Assigment of value for CRCFXOR in the FCR_CRCFXOR register */
#define FCR_CRCFXOR_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (FCR_CRCFXOR) Register Mask  */


/* -------- FCR_CRCSUM : (FCR Offset: 0x40) (R/W 32) CRC Checksum Register -------- */
#define FCR_CRCSUM_RESETVALUE                 _UINT32_(0x00)                                       /*  (FCR_CRCSUM) CRC Checksum Register  Reset Value */

#define FCR_CRCSUM_CRCSUM_Pos                 _UINT32_(0)                                          /* (FCR_CRCSUM) CRC Checksum Position */
#define FCR_CRCSUM_CRCSUM_Msk                 (_UINT32_(0xFFFFFFFF) << FCR_CRCSUM_CRCSUM_Pos)      /* (FCR_CRCSUM) CRC Checksum Mask */
#define FCR_CRCSUM_CRCSUM(value)              (FCR_CRCSUM_CRCSUM_Msk & (_UINT32_(value) << FCR_CRCSUM_CRCSUM_Pos)) /* Assigment of value for CRCSUM in the FCR_CRCSUM register */
#define FCR_CRCSUM_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (FCR_CRCSUM) Register Mask  */


/* -------- FCR_FFLTCTRL : (FCR Offset: 0x44) (R/W 32) Flash ECC Fault Control Register -------- */
#define FCR_FFLTCTRL_RESETVALUE               _UINT32_(0x00)                                       /*  (FCR_FFLTCTRL) Flash ECC Fault Control Register  Reset Value */

#define FCR_FFLTCTRL_FLTRST_Pos               _UINT32_(0)                                          /* (FCR_FFLTCTRL) Fault Reset Position */
#define FCR_FFLTCTRL_FLTRST_Msk               (_UINT32_(0x1) << FCR_FFLTCTRL_FLTRST_Pos)           /* (FCR_FFLTCTRL) Fault Reset Mask */
#define FCR_FFLTCTRL_FLTRST(value)            (FCR_FFLTCTRL_FLTRST_Msk & (_UINT32_(value) << FCR_FFLTCTRL_FLTRST_Pos)) /* Assigment of value for FLTRST in the FCR_FFLTCTRL register */
#define FCR_FFLTCTRL_FLTEN_Pos                _UINT32_(1)                                          /* (FCR_FFLTCTRL) ECC Fault Enable bit Position */
#define FCR_FFLTCTRL_FLTEN_Msk                (_UINT32_(0x1) << FCR_FFLTCTRL_FLTEN_Pos)            /* (FCR_FFLTCTRL) ECC Fault Enable bit Mask */
#define FCR_FFLTCTRL_FLTEN(value)             (FCR_FFLTCTRL_FLTEN_Msk & (_UINT32_(value) << FCR_FFLTCTRL_FLTEN_Pos)) /* Assigment of value for FLTEN in the FCR_FFLTCTRL register */
#define FCR_FFLTCTRL_CTLFLT_Pos               _UINT32_(8)                                          /* (FCR_FFLTCTRL) ECC/Parity Control Fault bits Position */
#define FCR_FFLTCTRL_CTLFLT_Msk               (_UINT32_(0x7) << FCR_FFLTCTRL_CTLFLT_Pos)           /* (FCR_FFLTCTRL) ECC/Parity Control Fault bits Mask */
#define FCR_FFLTCTRL_CTLFLT(value)            (FCR_FFLTCTRL_CTLFLT_Msk & (_UINT32_(value) << FCR_FFLTCTRL_CTLFLT_Pos)) /* Assigment of value for CTLFLT in the FCR_FFLTCTRL register */
#define FCR_FFLTCTRL_FLTMD_Pos                _UINT32_(12)                                         /* (FCR_FFLTCTRL) Fault Mode Control Position */
#define FCR_FFLTCTRL_FLTMD_Msk                (_UINT32_(0x7) << FCR_FFLTCTRL_FLTMD_Pos)            /* (FCR_FFLTCTRL) Fault Mode Control Mask */
#define FCR_FFLTCTRL_FLTMD(value)             (FCR_FFLTCTRL_FLTMD_Msk & (_UINT32_(value) << FCR_FFLTCTRL_FLTMD_Pos)) /* Assigment of value for FLTMD in the FCR_FFLTCTRL register */
#define FCR_FFLTCTRL_Msk                      _UINT32_(0x00007703)                                 /* (FCR_FFLTCTRL) Register Mask  */


/* -------- FCR_FFLTPTR : (FCR Offset: 0x48) (R/W 32) Flash ECC Fault Pointer Register -------- */
#define FCR_FFLTPTR_RESETVALUE                _UINT32_(0x00)                                       /*  (FCR_FFLTPTR) Flash ECC Fault Pointer Register  Reset Value */

#define FCR_FFLTPTR_FLT1PTR_Pos               _UINT32_(0)                                          /* (FCR_FFLTPTR) Fault 1 Injection Pointer Position */
#define FCR_FFLTPTR_FLT1PTR_Msk               (_UINT32_(0x1FF) << FCR_FFLTPTR_FLT1PTR_Pos)         /* (FCR_FFLTPTR) Fault 1 Injection Pointer Mask */
#define FCR_FFLTPTR_FLT1PTR(value)            (FCR_FFLTPTR_FLT1PTR_Msk & (_UINT32_(value) << FCR_FFLTPTR_FLT1PTR_Pos)) /* Assigment of value for FLT1PTR in the FCR_FFLTPTR register */
#define FCR_FFLTPTR_FLT2PTR_Pos               _UINT32_(16)                                         /* (FCR_FFLTPTR) Fault 2 Injection Pointer Position */
#define FCR_FFLTPTR_FLT2PTR_Msk               (_UINT32_(0x1FF) << FCR_FFLTPTR_FLT2PTR_Pos)         /* (FCR_FFLTPTR) Fault 2 Injection Pointer Mask */
#define FCR_FFLTPTR_FLT2PTR(value)            (FCR_FFLTPTR_FLT2PTR_Msk & (_UINT32_(value) << FCR_FFLTPTR_FLT2PTR_Pos)) /* Assigment of value for FLT2PTR in the FCR_FFLTPTR register */
#define FCR_FFLTPTR_Msk                       _UINT32_(0x01FF01FF)                                 /* (FCR_FFLTPTR) Register Mask  */


/* -------- FCR_FFLTADR : (FCR Offset: 0x4C) (R/W 32) Flash Fault Address Register -------- */
#define FCR_FFLTADR_RESETVALUE                _UINT32_(0x00)                                       /*  (FCR_FFLTADR) Flash Fault Address Register  Reset Value */

#define FCR_FFLTADR_FLTADR_Pos                _UINT32_(0)                                          /* (FCR_FFLTADR) Fault Inject Mode - Physical Address Position */
#define FCR_FFLTADR_FLTADR_Msk                (_UINT32_(0xFFFFFFF) << FCR_FFLTADR_FLTADR_Pos)      /* (FCR_FFLTADR) Fault Inject Mode - Physical Address Mask */
#define FCR_FFLTADR_FLTADR(value)             (FCR_FFLTADR_FLTADR_Msk & (_UINT32_(value) << FCR_FFLTADR_FLTADR_Pos)) /* Assigment of value for FLTADR in the FCR_FFLTADR register */
#define FCR_FFLTADR_Msk                       _UINT32_(0x0FFFFFFF)                                 /* (FCR_FFLTADR) Register Mask  */


/* -------- FCR_FFLTCAP : (FCR Offset: 0x50) ( R/ 32) Flash Fault Capture Address Register -------- */
#define FCR_FFLTCAP_RESETVALUE                _UINT32_(0x00)                                       /*  (FCR_FFLTCAP) Flash Fault Capture Address Register  Reset Value */

#define FCR_FFLTCAP_FLTADR_Pos                _UINT32_(0)                                          /* (FCR_FFLTCAP) Fault capture Mode - Physical Address Position */
#define FCR_FFLTCAP_FLTADR_Msk                (_UINT32_(0xFFFFFFF) << FCR_FFLTCAP_FLTADR_Pos)      /* (FCR_FFLTCAP) Fault capture Mode - Physical Address Mask */
#define FCR_FFLTCAP_FLTADR(value)             (FCR_FFLTCAP_FLTADR_Msk & (_UINT32_(value) << FCR_FFLTCAP_FLTADR_Pos)) /* Assigment of value for FLTADR in the FCR_FFLTCAP register */
#define FCR_FFLTCAP_Msk                       _UINT32_(0x0FFFFFFF)                                 /* (FCR_FFLTCAP) Register Mask  */


/* -------- FCR_FFLTPAR : (FCR Offset: 0x54) ( R/ 32) Flash ECC Fault Parity Register -------- */
#define FCR_FFLTPAR_RESETVALUE                _UINT32_(0x00)                                       /*  (FCR_FFLTPAR) Flash ECC Fault Parity Register  Reset Value */

#define FCR_FFLTPAR_SECIN_Pos                 _UINT32_(0)                                          /* (FCR_FFLTPAR) The Single Error Parity bits from Flash Position */
#define FCR_FFLTPAR_SECIN_Msk                 (_UINT32_(0x1FF) << FCR_FFLTPAR_SECIN_Pos)           /* (FCR_FFLTPAR) The Single Error Parity bits from Flash Mask */
#define FCR_FFLTPAR_SECIN(value)              (FCR_FFLTPAR_SECIN_Msk & (_UINT32_(value) << FCR_FFLTPAR_SECIN_Pos)) /* Assigment of value for SECIN in the FCR_FFLTPAR register */
#define FCR_FFLTPAR_DEDIN_Pos                 _UINT32_(15)                                         /* (FCR_FFLTPAR) The Overall Parity from Flash Position */
#define FCR_FFLTPAR_DEDIN_Msk                 (_UINT32_(0x1) << FCR_FFLTPAR_DEDIN_Pos)             /* (FCR_FFLTPAR) The Overall Parity from Flash Mask */
#define FCR_FFLTPAR_DEDIN(value)              (FCR_FFLTPAR_DEDIN_Msk & (_UINT32_(value) << FCR_FFLTPAR_DEDIN_Pos)) /* Assigment of value for DEDIN in the FCR_FFLTPAR register */
#define FCR_FFLTPAR_SECOUT_Pos                _UINT32_(16)                                         /* (FCR_FFLTPAR) The Calculated Single Error Parity bits Position */
#define FCR_FFLTPAR_SECOUT_Msk                (_UINT32_(0x1FF) << FCR_FFLTPAR_SECOUT_Pos)          /* (FCR_FFLTPAR) The Calculated Single Error Parity bits Mask */
#define FCR_FFLTPAR_SECOUT(value)             (FCR_FFLTPAR_SECOUT_Msk & (_UINT32_(value) << FCR_FFLTPAR_SECOUT_Pos)) /* Assigment of value for SECOUT in the FCR_FFLTPAR register */
#define FCR_FFLTPAR_DEDOUT_Pos                _UINT32_(31)                                         /* (FCR_FFLTPAR) The Calculated Overall Parity used in Double Error Detection Position */
#define FCR_FFLTPAR_DEDOUT_Msk                (_UINT32_(0x1) << FCR_FFLTPAR_DEDOUT_Pos)            /* (FCR_FFLTPAR) The Calculated Overall Parity used in Double Error Detection Mask */
#define FCR_FFLTPAR_DEDOUT(value)             (FCR_FFLTPAR_DEDOUT_Msk & (_UINT32_(value) << FCR_FFLTPAR_DEDOUT_Pos)) /* Assigment of value for DEDOUT in the FCR_FFLTPAR register */
#define FCR_FFLTPAR_Msk                       _UINT32_(0x81FF81FF)                                 /* (FCR_FFLTPAR) Register Mask  */


/* -------- FCR_FFLTSYN : (FCR Offset: 0x58) ( R/ 32) Flash ECC Fault Syndrome Register -------- */
#define FCR_FFLTSYN_RESETVALUE                _UINT32_(0x00)                                       /*  (FCR_FFLTSYN) Flash ECC Fault Syndrome Register  Reset Value */

#define FCR_FFLTSYN_SECSYN_Pos                _UINT32_(0)                                          /* (FCR_FFLTSYN) Single Error Correction Syndrome Position */
#define FCR_FFLTSYN_SECSYN_Msk                (_UINT32_(0x1FF) << FCR_FFLTSYN_SECSYN_Pos)          /* (FCR_FFLTSYN) Single Error Correction Syndrome Mask */
#define FCR_FFLTSYN_SECSYN(value)             (FCR_FFLTSYN_SECSYN_Msk & (_UINT32_(value) << FCR_FFLTSYN_SECSYN_Pos)) /* Assigment of value for SECSYN in the FCR_FFLTSYN register */
#define FCR_FFLTSYN_DEDSYN_Pos                _UINT32_(15)                                         /* (FCR_FFLTSYN) DED Syndrome Position */
#define FCR_FFLTSYN_DEDSYN_Msk                (_UINT32_(0x1) << FCR_FFLTSYN_DEDSYN_Pos)            /* (FCR_FFLTSYN) DED Syndrome Mask */
#define FCR_FFLTSYN_DEDSYN(value)             (FCR_FFLTSYN_DEDSYN_Msk & (_UINT32_(value) << FCR_FFLTSYN_DEDSYN_Pos)) /* Assigment of value for DEDSYN in the FCR_FFLTSYN register */
#define FCR_FFLTSYN_DERR_Pos                  _UINT32_(16)                                         /* (FCR_FFLTSYN) Double Error Detected & Single Error Corrected Position */
#define FCR_FFLTSYN_DERR_Msk                  (_UINT32_(0x3) << FCR_FFLTSYN_DERR_Pos)              /* (FCR_FFLTSYN) Double Error Detected & Single Error Corrected Mask */
#define FCR_FFLTSYN_DERR(value)               (FCR_FFLTSYN_DERR_Msk & (_UINT32_(value) << FCR_FFLTSYN_DERR_Pos)) /* Assigment of value for DERR in the FCR_FFLTSYN register */
#define FCR_FFLTSYN_CERR_Pos                  _UINT32_(18)                                         /* (FCR_FFLTSYN) ECC Control bit Error Position */
#define FCR_FFLTSYN_CERR_Msk                  (_UINT32_(0x1) << FCR_FFLTSYN_CERR_Pos)              /* (FCR_FFLTSYN) ECC Control bit Error Mask */
#define FCR_FFLTSYN_CERR(value)               (FCR_FFLTSYN_CERR_Msk & (_UINT32_(value) << FCR_FFLTSYN_CERR_Pos)) /* Assigment of value for CERR in the FCR_FFLTSYN register */
#define FCR_FFLTSYN_CTLSTAT_Pos               _UINT32_(24)                                         /* (FCR_FFLTSYN) Parity vs ECC Control Status Position */
#define FCR_FFLTSYN_CTLSTAT_Msk               (_UINT32_(0x7) << FCR_FFLTSYN_CTLSTAT_Pos)           /* (FCR_FFLTSYN) Parity vs ECC Control Status Mask */
#define FCR_FFLTSYN_CTLSTAT(value)            (FCR_FFLTSYN_CTLSTAT_Msk & (_UINT32_(value) << FCR_FFLTSYN_CTLSTAT_Pos)) /* Assigment of value for CTLSTAT in the FCR_FFLTSYN register */
#define FCR_FFLTSYN_PERR_Pos                  _UINT32_(27)                                         /* (FCR_FFLTSYN) Per Word Parity Error Status Position */
#define FCR_FFLTSYN_PERR_Msk                  (_UINT32_(0x1F) << FCR_FFLTSYN_PERR_Pos)             /* (FCR_FFLTSYN) Per Word Parity Error Status Mask */
#define FCR_FFLTSYN_PERR(value)               (FCR_FFLTSYN_PERR_Msk & (_UINT32_(value) << FCR_FFLTSYN_PERR_Pos)) /* Assigment of value for PERR in the FCR_FFLTSYN register */
#define FCR_FFLTSYN_Msk                       _UINT32_(0xFF0781FF)                                 /* (FCR_FFLTSYN) Register Mask  */


/* -------- FCR_CRP : (FCR Offset: 0x5C) (R/W 32) CFM Page Read Protect Register -------- */
#define FCR_CRP_RESETVALUE                    _UINT32_(0x00)                                       /*  (FCR_CRP) CFM Page Read Protect Register  Reset Value */

#define FCR_CRP_BC1RP_Pos                     _UINT32_(2)                                          /* (FCR_CRP) Boot Configuration Page 1 Read Protect Bit Position */
#define FCR_CRP_BC1RP_Msk                     (_UINT32_(0x1) << FCR_CRP_BC1RP_Pos)                 /* (FCR_CRP) Boot Configuration Page 1 Read Protect Bit Mask */
#define FCR_CRP_BC1RP(value)                  (FCR_CRP_BC1RP_Msk & (_UINT32_(value) << FCR_CRP_BC1RP_Pos)) /* Assigment of value for BC1RP in the FCR_CRP register */
#define FCR_CRP_BC2RP_Pos                     _UINT32_(10)                                         /* (FCR_CRP) Boot Configuration Page 2 Read Protect Bit Position */
#define FCR_CRP_BC2RP_Msk                     (_UINT32_(0x1) << FCR_CRP_BC2RP_Pos)                 /* (FCR_CRP) Boot Configuration Page 2 Read Protect Bit Mask */
#define FCR_CRP_BC2RP(value)                  (FCR_CRP_BC2RP_Msk & (_UINT32_(value) << FCR_CRP_BC2RP_Pos)) /* Assigment of value for BC2RP in the FCR_CRP register */
#define FCR_CRP_BC1RPLOCK_Pos                 _UINT32_(18)                                         /* (FCR_CRP) Boot Configuration Page 1 RP Lock Bit Position */
#define FCR_CRP_BC1RPLOCK_Msk                 (_UINT32_(0x1) << FCR_CRP_BC1RPLOCK_Pos)             /* (FCR_CRP) Boot Configuration Page 1 RP Lock Bit Mask */
#define FCR_CRP_BC1RPLOCK(value)              (FCR_CRP_BC1RPLOCK_Msk & (_UINT32_(value) << FCR_CRP_BC1RPLOCK_Pos)) /* Assigment of value for BC1RPLOCK in the FCR_CRP register */
#define FCR_CRP_BC2RPLOCK_Pos                 _UINT32_(26)                                         /* (FCR_CRP) Boot Configuration Page 2 RP Lock Bit Position */
#define FCR_CRP_BC2RPLOCK_Msk                 (_UINT32_(0x1) << FCR_CRP_BC2RPLOCK_Pos)             /* (FCR_CRP) Boot Configuration Page 2 RP Lock Bit Mask */
#define FCR_CRP_BC2RPLOCK(value)              (FCR_CRP_BC2RPLOCK_Msk & (_UINT32_(value) << FCR_CRP_BC2RPLOCK_Pos)) /* Assigment of value for BC2RPLOCK in the FCR_CRP register */
#define FCR_CRP_Msk                           _UINT32_(0x04040404)                                 /* (FCR_CRP) Register Mask  */


/* -------- FCR_HSMCTRL : (FCR Offset: 0x60) (R/W 32) HSM CFM PAGES Control Register -------- */
#define FCR_HSMCTRL_RESETVALUE                _UINT32_(0x00)                                       /*  (FCR_HSMCTRL) HSM CFM PAGES Control Register  Reset Value */

#define FCR_HSMCTRL_ECCDIS_Pos                _UINT32_(0)                                          /* (FCR_HSMCTRL) ECC Disable for HSM Pages in CFM Position */
#define FCR_HSMCTRL_ECCDIS_Msk                (_UINT32_(0x1) << FCR_HSMCTRL_ECCDIS_Pos)            /* (FCR_HSMCTRL) ECC Disable for HSM Pages in CFM Mask */
#define FCR_HSMCTRL_ECCDIS(value)             (FCR_HSMCTRL_ECCDIS_Msk & (_UINT32_(value) << FCR_HSMCTRL_ECCDIS_Pos)) /* Assigment of value for ECCDIS in the FCR_HSMCTRL register */
#define FCR_HSMCTRL_KEYZ_Pos                  _UINT32_(1)                                          /* (FCR_HSMCTRL) Flash Key Locations read 0\xd5 s Position */
#define FCR_HSMCTRL_KEYZ_Msk                  (_UINT32_(0x1) << FCR_HSMCTRL_KEYZ_Pos)              /* (FCR_HSMCTRL) Flash Key Locations read 0\xd5 s Mask */
#define FCR_HSMCTRL_KEYZ(value)               (FCR_HSMCTRL_KEYZ_Msk & (_UINT32_(value) << FCR_HSMCTRL_KEYZ_Pos)) /* Assigment of value for KEYZ in the FCR_HSMCTRL register */
#define FCR_HSMCTRL_Msk                       _UINT32_(0x00000003)                                 /* (FCR_HSMCTRL) Register Mask  */


/** \brief FCR register offsets definitions */
#define FCR_CTRLA_REG_OFST             _UINT32_(0x00)      /* (FCR_CTRLA) Control A Register Offset */
#define FCR_CTRLB_REG_OFST             _UINT32_(0x04)      /* (FCR_CTRLB) Control B Register Offset */
#define FCR_INTENCLR_REG_OFST          _UINT32_(0x08)      /* (FCR_INTENCLR) Interrupt Enable Clear Register Offset */
#define FCR_INTENSET_REG_OFST          _UINT32_(0x0C)      /* (FCR_INTENSET) Interrupt Enable SET Register Offset */
#define FCR_INTFLAG_REG_OFST           _UINT32_(0x10)      /* (FCR_INTFLAG) Interrupt Flag Register Offset */
#define FCR_STATUS_REG_OFST            _UINT32_(0x14)      /* (FCR_STATUS) NVM Status Register Offset */
#define FCR_DBGCTRL_REG_OFST           _UINT32_(0x18)      /* (FCR_DBGCTRL) Debug Control Register Offset */
#define FCR_ECCCTRL_REG_OFST           _UINT32_(0x1C)      /* (FCR_ECCCTRL) ECC Control Register Offset */
#define FCR_CRCCTRL_REG_OFST           _UINT32_(0x20)      /* (FCR_CRCCTRL) CRC Control Register Offset */
#define FCR_CRCPAUSE_REG_OFST          _UINT32_(0x24)      /* (FCR_CRCPAUSE) CRC PAUSE Register Offset */
#define FCR_CRCMADR_REG_OFST           _UINT32_(0x28)      /* (FCR_CRCMADR) CRC Message Address Register Offset */
#define FCR_CRCMLEN_REG_OFST           _UINT32_(0x2C)      /* (FCR_CRCMLEN) CRC Message Length Register Offset */
#define FCR_CRCIV_REG_OFST             _UINT32_(0x30)      /* (FCR_CRCIV) CRC Initial Value Register Offset */
#define FCR_CRCACC_REG_OFST            _UINT32_(0x34)      /* (FCR_CRCACC) CRC Accumulator Register Offset */
#define FCR_CRCPOLY_REG_OFST           _UINT32_(0x38)      /* (FCR_CRCPOLY) CRC Polynomial Register Offset */
#define FCR_CRCFXOR_REG_OFST           _UINT32_(0x3C)      /* (FCR_CRCFXOR) CRC Final XOR Register Offset */
#define FCR_CRCSUM_REG_OFST            _UINT32_(0x40)      /* (FCR_CRCSUM) CRC Checksum Register Offset */
#define FCR_FFLTCTRL_REG_OFST          _UINT32_(0x44)      /* (FCR_FFLTCTRL) Flash ECC Fault Control Register Offset */
#define FCR_FFLTPTR_REG_OFST           _UINT32_(0x48)      /* (FCR_FFLTPTR) Flash ECC Fault Pointer Register Offset */
#define FCR_FFLTADR_REG_OFST           _UINT32_(0x4C)      /* (FCR_FFLTADR) Flash Fault Address Register Offset */
#define FCR_FFLTCAP_REG_OFST           _UINT32_(0x50)      /* (FCR_FFLTCAP) Flash Fault Capture Address Register Offset */
#define FCR_FFLTPAR_REG_OFST           _UINT32_(0x54)      /* (FCR_FFLTPAR) Flash ECC Fault Parity Register Offset */
#define FCR_FFLTSYN_REG_OFST           _UINT32_(0x58)      /* (FCR_FFLTSYN) Flash ECC Fault Syndrome Register Offset */
#define FCR_CRP_REG_OFST               _UINT32_(0x5C)      /* (FCR_CRP) CFM Page Read Protect Register Offset */
#define FCR_HSMCTRL_REG_OFST           _UINT32_(0x60)      /* (FCR_HSMCTRL) HSM CFM PAGES Control Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief FCR register API structure */
typedef struct
{  /* Flash Read Controller (FCR) */
  __IO  uint32_t                       FCR_CTRLA;          /**< Offset: 0x00 (R/W  32) Control A Register */
  __IO  uint32_t                       FCR_CTRLB;          /**< Offset: 0x04 (R/W  32) Control B Register */
  __IO  uint32_t                       FCR_INTENCLR;       /**< Offset: 0x08 (R/W  32) Interrupt Enable Clear Register */
  __IO  uint32_t                       FCR_INTENSET;       /**< Offset: 0x0C (R/W  32) Interrupt Enable SET Register */
  __IO  uint32_t                       FCR_INTFLAG;        /**< Offset: 0x10 (R/W  32) Interrupt Flag Register */
  __I   uint32_t                       FCR_STATUS;         /**< Offset: 0x14 (R/   32) NVM Status Register */
  __IO  uint32_t                       FCR_DBGCTRL;        /**< Offset: 0x18 (R/W  32) Debug Control Register */
  __IO  uint32_t                       FCR_ECCCTRL;        /**< Offset: 0x1C (R/W  32) ECC Control Register */
  __IO  uint32_t                       FCR_CRCCTRL;        /**< Offset: 0x20 (R/W  32) CRC Control Register */
  __IO  uint32_t                       FCR_CRCPAUSE;       /**< Offset: 0x24 (R/W  32) CRC PAUSE Register */
  __IO  uint32_t                       FCR_CRCMADR;        /**< Offset: 0x28 (R/W  32) CRC Message Address Register */
  __IO  uint32_t                       FCR_CRCMLEN;        /**< Offset: 0x2C (R/W  32) CRC Message Length Register */
  __IO  uint32_t                       FCR_CRCIV;          /**< Offset: 0x30 (R/W  32) CRC Initial Value Register */
  __I   uint32_t                       FCR_CRCACC;         /**< Offset: 0x34 (R/   32) CRC Accumulator Register */
  __IO  uint32_t                       FCR_CRCPOLY;        /**< Offset: 0x38 (R/W  32) CRC Polynomial Register */
  __IO  uint32_t                       FCR_CRCFXOR;        /**< Offset: 0x3C (R/W  32) CRC Final XOR Register */
  __IO  uint32_t                       FCR_CRCSUM;         /**< Offset: 0x40 (R/W  32) CRC Checksum Register */
  __IO  uint32_t                       FCR_FFLTCTRL;       /**< Offset: 0x44 (R/W  32) Flash ECC Fault Control Register */
  __IO  uint32_t                       FCR_FFLTPTR;        /**< Offset: 0x48 (R/W  32) Flash ECC Fault Pointer Register */
  __IO  uint32_t                       FCR_FFLTADR;        /**< Offset: 0x4C (R/W  32) Flash Fault Address Register */
  __I   uint32_t                       FCR_FFLTCAP;        /**< Offset: 0x50 (R/   32) Flash Fault Capture Address Register */
  __I   uint32_t                       FCR_FFLTPAR;        /**< Offset: 0x54 (R/   32) Flash ECC Fault Parity Register */
  __I   uint32_t                       FCR_FFLTSYN;        /**< Offset: 0x58 (R/   32) Flash ECC Fault Syndrome Register */
  __IO  uint32_t                       FCR_CRP;            /**< Offset: 0x5C (R/W  32) CFM Page Read Protect Register */
  __IO  uint32_t                       FCR_HSMCTRL;        /**< Offset: 0x60 (R/W  32) HSM CFM PAGES Control Register */
} fcr_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA80_FCR_COMPONENT_H_ */
