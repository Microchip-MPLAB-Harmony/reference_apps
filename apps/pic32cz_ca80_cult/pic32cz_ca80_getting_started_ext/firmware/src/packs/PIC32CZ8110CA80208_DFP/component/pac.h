/*
 * Component description for PAC
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
#ifndef _PIC32CZCA80_PAC_COMPONENT_H_
#define _PIC32CZCA80_PAC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR PAC                                          */
/* ************************************************************************** */

/* -------- PAC_WRCTRL : (PAC Offset: 0x00) (R/W 32) Write control -------- */
#define PAC_WRCTRL_RESETVALUE                 _UINT32_(0x00)                                       /*  (PAC_WRCTRL) Write control  Reset Value */

#define PAC_WRCTRL_PERID_Pos                  _UINT32_(0)                                          /* (PAC_WRCTRL) Peripheral identifier Position */
#define PAC_WRCTRL_PERID_Msk                  (_UINT32_(0xFFFF) << PAC_WRCTRL_PERID_Pos)           /* (PAC_WRCTRL) Peripheral identifier Mask */
#define PAC_WRCTRL_PERID(value)               (PAC_WRCTRL_PERID_Msk & (_UINT32_(value) << PAC_WRCTRL_PERID_Pos)) /* Assigment of value for PERID in the PAC_WRCTRL register */
#define PAC_WRCTRL_KEY_Pos                    _UINT32_(16)                                         /* (PAC_WRCTRL) Peripheral access control key Position */
#define PAC_WRCTRL_KEY_Msk                    (_UINT32_(0xFF) << PAC_WRCTRL_KEY_Pos)               /* (PAC_WRCTRL) Peripheral access control key Mask */
#define PAC_WRCTRL_KEY(value)                 (PAC_WRCTRL_KEY_Msk & (_UINT32_(value) << PAC_WRCTRL_KEY_Pos)) /* Assigment of value for KEY in the PAC_WRCTRL register */
#define   PAC_WRCTRL_KEY_OFF_Val              _UINT32_(0x0)                                        /* (PAC_WRCTRL) No action  */
#define   PAC_WRCTRL_KEY_CLR_Val              _UINT32_(0x1)                                        /* (PAC_WRCTRL) Clear protection  */
#define   PAC_WRCTRL_KEY_SET_Val              _UINT32_(0x2)                                        /* (PAC_WRCTRL) Set protection  */
#define   PAC_WRCTRL_KEY_SETLCK_Val           _UINT32_(0x3)                                        /* (PAC_WRCTRL) Set and lock protection  */
#define PAC_WRCTRL_KEY_OFF                    (PAC_WRCTRL_KEY_OFF_Val << PAC_WRCTRL_KEY_Pos)       /* (PAC_WRCTRL) No action Position  */
#define PAC_WRCTRL_KEY_CLR                    (PAC_WRCTRL_KEY_CLR_Val << PAC_WRCTRL_KEY_Pos)       /* (PAC_WRCTRL) Clear protection Position  */
#define PAC_WRCTRL_KEY_SET                    (PAC_WRCTRL_KEY_SET_Val << PAC_WRCTRL_KEY_Pos)       /* (PAC_WRCTRL) Set protection Position  */
#define PAC_WRCTRL_KEY_SETLCK                 (PAC_WRCTRL_KEY_SETLCK_Val << PAC_WRCTRL_KEY_Pos)    /* (PAC_WRCTRL) Set and lock protection Position  */
#define PAC_WRCTRL_Msk                        _UINT32_(0x00FFFFFF)                                 /* (PAC_WRCTRL) Register Mask  */


/* -------- PAC_EVCTRL : (PAC Offset: 0x04) (R/W 8) Event control -------- */
#define PAC_EVCTRL_RESETVALUE                 _UINT8_(0x00)                                        /*  (PAC_EVCTRL) Event control  Reset Value */

#define PAC_EVCTRL_ERREO_Pos                  _UINT8_(0)                                           /* (PAC_EVCTRL) Peripheral acess error event output Position */
#define PAC_EVCTRL_ERREO_Msk                  (_UINT8_(0x1) << PAC_EVCTRL_ERREO_Pos)               /* (PAC_EVCTRL) Peripheral acess error event output Mask */
#define PAC_EVCTRL_ERREO(value)               (PAC_EVCTRL_ERREO_Msk & (_UINT8_(value) << PAC_EVCTRL_ERREO_Pos)) /* Assigment of value for ERREO in the PAC_EVCTRL register */
#define PAC_EVCTRL_Msk                        _UINT8_(0x01)                                        /* (PAC_EVCTRL) Register Mask  */


/* -------- PAC_INTENCLR : (PAC Offset: 0x08) (R/W 8) Interrupt enable clear -------- */
#define PAC_INTENCLR_RESETVALUE               _UINT8_(0x00)                                        /*  (PAC_INTENCLR) Interrupt enable clear  Reset Value */

#define PAC_INTENCLR_ERR_Pos                  _UINT8_(0)                                           /* (PAC_INTENCLR) Peripheral access error interrupt disable Position */
#define PAC_INTENCLR_ERR_Msk                  (_UINT8_(0x1) << PAC_INTENCLR_ERR_Pos)               /* (PAC_INTENCLR) Peripheral access error interrupt disable Mask */
#define PAC_INTENCLR_ERR(value)               (PAC_INTENCLR_ERR_Msk & (_UINT8_(value) << PAC_INTENCLR_ERR_Pos)) /* Assigment of value for ERR in the PAC_INTENCLR register */
#define PAC_INTENCLR_Msk                      _UINT8_(0x01)                                        /* (PAC_INTENCLR) Register Mask  */


/* -------- PAC_INTENSET : (PAC Offset: 0x09) (R/W 8) Interrupt enable set -------- */
#define PAC_INTENSET_RESETVALUE               _UINT8_(0x00)                                        /*  (PAC_INTENSET) Interrupt enable set  Reset Value */

#define PAC_INTENSET_ERR_Pos                  _UINT8_(0)                                           /* (PAC_INTENSET) Peripheral access error interrupt enable Position */
#define PAC_INTENSET_ERR_Msk                  (_UINT8_(0x1) << PAC_INTENSET_ERR_Pos)               /* (PAC_INTENSET) Peripheral access error interrupt enable Mask */
#define PAC_INTENSET_ERR(value)               (PAC_INTENSET_ERR_Msk & (_UINT8_(value) << PAC_INTENSET_ERR_Pos)) /* Assigment of value for ERR in the PAC_INTENSET register */
#define PAC_INTENSET_Msk                      _UINT8_(0x01)                                        /* (PAC_INTENSET) Register Mask  */


/* -------- PAC_INTFLAGAHB : (PAC Offset: 0x10) (R/W 32) Bridge interrupt flag status -------- */
#define PAC_INTFLAGAHB_RESETVALUE             _UINT32_(0x00)                                       /*  (PAC_INTFLAGAHB) Bridge interrupt flag status  Reset Value */

#define PAC_INTFLAGAHB_Msk                    _UINT32_(0x00000000)                                 /* (PAC_INTFLAGAHB) Register Mask  */


/* -------- PAC_INTFLAGA : (PAC Offset: 0x14) (R/W 32) Peripheral interrupt flag status - Bridge A -------- */
#define PAC_INTFLAGA_RESETVALUE               _UINT32_(0x00)                                       /*  (PAC_INTFLAGA) Peripheral interrupt flag status - Bridge A  Reset Value */

#define PAC_INTFLAGA_DSU_Pos                  _UINT32_(0)                                          /* (PAC_INTFLAGA) DSU Position */
#define PAC_INTFLAGA_DSU_Msk                  (_UINT32_(0x1) << PAC_INTFLAGA_DSU_Pos)              /* (PAC_INTFLAGA) DSU Mask */
#define PAC_INTFLAGA_DSU(value)               (PAC_INTFLAGA_DSU_Msk & (_UINT32_(value) << PAC_INTFLAGA_DSU_Pos)) /* Assigment of value for DSU in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_FCW_Pos                  _UINT32_(1)                                          /* (PAC_INTFLAGA) FCW Position */
#define PAC_INTFLAGA_FCW_Msk                  (_UINT32_(0x1) << PAC_INTFLAGA_FCW_Pos)              /* (PAC_INTFLAGA) FCW Mask */
#define PAC_INTFLAGA_FCW(value)               (PAC_INTFLAGA_FCW_Msk & (_UINT32_(value) << PAC_INTFLAGA_FCW_Pos)) /* Assigment of value for FCW in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_FCR_Pos                  _UINT32_(2)                                          /* (PAC_INTFLAGA) FCR Position */
#define PAC_INTFLAGA_FCR_Msk                  (_UINT32_(0x1) << PAC_INTFLAGA_FCR_Pos)              /* (PAC_INTFLAGA) FCR Mask */
#define PAC_INTFLAGA_FCR(value)               (PAC_INTFLAGA_FCR_Msk & (_UINT32_(value) << PAC_INTFLAGA_FCR_Pos)) /* Assigment of value for FCR in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_PM_Pos                   _UINT32_(3)                                          /* (PAC_INTFLAGA) PM Position */
#define PAC_INTFLAGA_PM_Msk                   (_UINT32_(0x1) << PAC_INTFLAGA_PM_Pos)               /* (PAC_INTFLAGA) PM Mask */
#define PAC_INTFLAGA_PM(value)                (PAC_INTFLAGA_PM_Msk & (_UINT32_(value) << PAC_INTFLAGA_PM_Pos)) /* Assigment of value for PM in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_SUPC_Pos                 _UINT32_(4)                                          /* (PAC_INTFLAGA) SUPC Position */
#define PAC_INTFLAGA_SUPC_Msk                 (_UINT32_(0x1) << PAC_INTFLAGA_SUPC_Pos)             /* (PAC_INTFLAGA) SUPC Mask */
#define PAC_INTFLAGA_SUPC(value)              (PAC_INTFLAGA_SUPC_Msk & (_UINT32_(value) << PAC_INTFLAGA_SUPC_Pos)) /* Assigment of value for SUPC in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_RSTC_Pos                 _UINT32_(5)                                          /* (PAC_INTFLAGA) RSTC Position */
#define PAC_INTFLAGA_RSTC_Msk                 (_UINT32_(0x1) << PAC_INTFLAGA_RSTC_Pos)             /* (PAC_INTFLAGA) RSTC Mask */
#define PAC_INTFLAGA_RSTC(value)              (PAC_INTFLAGA_RSTC_Msk & (_UINT32_(value) << PAC_INTFLAGA_RSTC_Pos)) /* Assigment of value for RSTC in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_OSCCTRL_Pos              _UINT32_(6)                                          /* (PAC_INTFLAGA) OSCCTRL Position */
#define PAC_INTFLAGA_OSCCTRL_Msk              (_UINT32_(0x1) << PAC_INTFLAGA_OSCCTRL_Pos)          /* (PAC_INTFLAGA) OSCCTRL Mask */
#define PAC_INTFLAGA_OSCCTRL(value)           (PAC_INTFLAGA_OSCCTRL_Msk & (_UINT32_(value) << PAC_INTFLAGA_OSCCTRL_Pos)) /* Assigment of value for OSCCTRL in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_OSC32KCTRL_Pos           _UINT32_(7)                                          /* (PAC_INTFLAGA) OSC32KCTRL Position */
#define PAC_INTFLAGA_OSC32KCTRL_Msk           (_UINT32_(0x1) << PAC_INTFLAGA_OSC32KCTRL_Pos)       /* (PAC_INTFLAGA) OSC32KCTRL Mask */
#define PAC_INTFLAGA_OSC32KCTRL(value)        (PAC_INTFLAGA_OSC32KCTRL_Msk & (_UINT32_(value) << PAC_INTFLAGA_OSC32KCTRL_Pos)) /* Assigment of value for OSC32KCTRL in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_GCLK_Pos                 _UINT32_(8)                                          /* (PAC_INTFLAGA) GCLK Position */
#define PAC_INTFLAGA_GCLK_Msk                 (_UINT32_(0x1) << PAC_INTFLAGA_GCLK_Pos)             /* (PAC_INTFLAGA) GCLK Mask */
#define PAC_INTFLAGA_GCLK(value)              (PAC_INTFLAGA_GCLK_Msk & (_UINT32_(value) << PAC_INTFLAGA_GCLK_Pos)) /* Assigment of value for GCLK in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_MCLK_Pos                 _UINT32_(9)                                          /* (PAC_INTFLAGA) MCLK Position */
#define PAC_INTFLAGA_MCLK_Msk                 (_UINT32_(0x1) << PAC_INTFLAGA_MCLK_Pos)             /* (PAC_INTFLAGA) MCLK Mask */
#define PAC_INTFLAGA_MCLK(value)              (PAC_INTFLAGA_MCLK_Msk & (_UINT32_(value) << PAC_INTFLAGA_MCLK_Pos)) /* Assigment of value for MCLK in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_FREQM_Pos                _UINT32_(10)                                         /* (PAC_INTFLAGA) FREQM Position */
#define PAC_INTFLAGA_FREQM_Msk                (_UINT32_(0x1) << PAC_INTFLAGA_FREQM_Pos)            /* (PAC_INTFLAGA) FREQM Mask */
#define PAC_INTFLAGA_FREQM(value)             (PAC_INTFLAGA_FREQM_Msk & (_UINT32_(value) << PAC_INTFLAGA_FREQM_Pos)) /* Assigment of value for FREQM in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_WDT_Pos                  _UINT32_(11)                                         /* (PAC_INTFLAGA) WDT Position */
#define PAC_INTFLAGA_WDT_Msk                  (_UINT32_(0x1) << PAC_INTFLAGA_WDT_Pos)              /* (PAC_INTFLAGA) WDT Mask */
#define PAC_INTFLAGA_WDT(value)               (PAC_INTFLAGA_WDT_Msk & (_UINT32_(value) << PAC_INTFLAGA_WDT_Pos)) /* Assigment of value for WDT in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_RTC_Pos                  _UINT32_(12)                                         /* (PAC_INTFLAGA) RTC Position */
#define PAC_INTFLAGA_RTC_Msk                  (_UINT32_(0x1) << PAC_INTFLAGA_RTC_Pos)              /* (PAC_INTFLAGA) RTC Mask */
#define PAC_INTFLAGA_RTC(value)               (PAC_INTFLAGA_RTC_Msk & (_UINT32_(value) << PAC_INTFLAGA_RTC_Pos)) /* Assigment of value for RTC in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_EIC_Pos                  _UINT32_(13)                                         /* (PAC_INTFLAGA) EIC Position */
#define PAC_INTFLAGA_EIC_Msk                  (_UINT32_(0x1) << PAC_INTFLAGA_EIC_Pos)              /* (PAC_INTFLAGA) EIC Mask */
#define PAC_INTFLAGA_EIC(value)               (PAC_INTFLAGA_EIC_Msk & (_UINT32_(value) << PAC_INTFLAGA_EIC_Pos)) /* Assigment of value for EIC in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_PAC_Pos                  _UINT32_(14)                                         /* (PAC_INTFLAGA) PAC Position */
#define PAC_INTFLAGA_PAC_Msk                  (_UINT32_(0x1) << PAC_INTFLAGA_PAC_Pos)              /* (PAC_INTFLAGA) PAC Mask */
#define PAC_INTFLAGA_PAC(value)               (PAC_INTFLAGA_PAC_Msk & (_UINT32_(value) << PAC_INTFLAGA_PAC_Pos)) /* Assigment of value for PAC in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_DRMTCM_Pos               _UINT32_(15)                                         /* (PAC_INTFLAGA) DRMTCM Position */
#define PAC_INTFLAGA_DRMTCM_Msk               (_UINT32_(0x1) << PAC_INTFLAGA_DRMTCM_Pos)           /* (PAC_INTFLAGA) DRMTCM Mask */
#define PAC_INTFLAGA_DRMTCM(value)            (PAC_INTFLAGA_DRMTCM_Msk & (_UINT32_(value) << PAC_INTFLAGA_DRMTCM_Pos)) /* Assigment of value for DRMTCM in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_MCRAMC_Pos               _UINT32_(16)                                         /* (PAC_INTFLAGA) MCRAMC Position */
#define PAC_INTFLAGA_MCRAMC_Msk               (_UINT32_(0x1) << PAC_INTFLAGA_MCRAMC_Pos)           /* (PAC_INTFLAGA) MCRAMC Mask */
#define PAC_INTFLAGA_MCRAMC(value)            (PAC_INTFLAGA_MCRAMC_Msk & (_UINT32_(value) << PAC_INTFLAGA_MCRAMC_Pos)) /* Assigment of value for MCRAMC in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_TRAM_Pos                 _UINT32_(17)                                         /* (PAC_INTFLAGA) TRAM Position */
#define PAC_INTFLAGA_TRAM_Msk                 (_UINT32_(0x1) << PAC_INTFLAGA_TRAM_Pos)             /* (PAC_INTFLAGA) TRAM Mask */
#define PAC_INTFLAGA_TRAM(value)              (PAC_INTFLAGA_TRAM_Msk & (_UINT32_(value) << PAC_INTFLAGA_TRAM_Pos)) /* Assigment of value for TRAM in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_PORT_Pos                 _UINT32_(18)                                         /* (PAC_INTFLAGA) PORT Position */
#define PAC_INTFLAGA_PORT_Msk                 (_UINT32_(0x1) << PAC_INTFLAGA_PORT_Pos)             /* (PAC_INTFLAGA) PORT Mask */
#define PAC_INTFLAGA_PORT(value)              (PAC_INTFLAGA_PORT_Msk & (_UINT32_(value) << PAC_INTFLAGA_PORT_Pos)) /* Assigment of value for PORT in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_DMA_Pos                  _UINT32_(19)                                         /* (PAC_INTFLAGA) DMA Position */
#define PAC_INTFLAGA_DMA_Msk                  (_UINT32_(0x1) << PAC_INTFLAGA_DMA_Pos)              /* (PAC_INTFLAGA) DMA Mask */
#define PAC_INTFLAGA_DMA(value)               (PAC_INTFLAGA_DMA_Msk & (_UINT32_(value) << PAC_INTFLAGA_DMA_Pos)) /* Assigment of value for DMA in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_PRM_Pos                  _UINT32_(21)                                         /* (PAC_INTFLAGA) PRM Position */
#define PAC_INTFLAGA_PRM_Msk                  (_UINT32_(0x1) << PAC_INTFLAGA_PRM_Pos)              /* (PAC_INTFLAGA) PRM Mask */
#define PAC_INTFLAGA_PRM(value)               (PAC_INTFLAGA_PRM_Msk & (_UINT32_(value) << PAC_INTFLAGA_PRM_Pos)) /* Assigment of value for PRM in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_EVSYS_Pos                _UINT32_(22)                                         /* (PAC_INTFLAGA) EVSYS Position */
#define PAC_INTFLAGA_EVSYS_Msk                (_UINT32_(0x1) << PAC_INTFLAGA_EVSYS_Pos)            /* (PAC_INTFLAGA) EVSYS Mask */
#define PAC_INTFLAGA_EVSYS(value)             (PAC_INTFLAGA_EVSYS_Msk & (_UINT32_(value) << PAC_INTFLAGA_EVSYS_Pos)) /* Assigment of value for EVSYS in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_SERCOM0_Pos              _UINT32_(23)                                         /* (PAC_INTFLAGA) SERCOM0 Position */
#define PAC_INTFLAGA_SERCOM0_Msk              (_UINT32_(0x1) << PAC_INTFLAGA_SERCOM0_Pos)          /* (PAC_INTFLAGA) SERCOM0 Mask */
#define PAC_INTFLAGA_SERCOM0(value)           (PAC_INTFLAGA_SERCOM0_Msk & (_UINT32_(value) << PAC_INTFLAGA_SERCOM0_Pos)) /* Assigment of value for SERCOM0 in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_SERCOM1_Pos              _UINT32_(24)                                         /* (PAC_INTFLAGA) SERCOM1 Position */
#define PAC_INTFLAGA_SERCOM1_Msk              (_UINT32_(0x1) << PAC_INTFLAGA_SERCOM1_Pos)          /* (PAC_INTFLAGA) SERCOM1 Mask */
#define PAC_INTFLAGA_SERCOM1(value)           (PAC_INTFLAGA_SERCOM1_Msk & (_UINT32_(value) << PAC_INTFLAGA_SERCOM1_Pos)) /* Assigment of value for SERCOM1 in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_SERCOM2_Pos              _UINT32_(25)                                         /* (PAC_INTFLAGA) SERCOM2 Position */
#define PAC_INTFLAGA_SERCOM2_Msk              (_UINT32_(0x1) << PAC_INTFLAGA_SERCOM2_Pos)          /* (PAC_INTFLAGA) SERCOM2 Mask */
#define PAC_INTFLAGA_SERCOM2(value)           (PAC_INTFLAGA_SERCOM2_Msk & (_UINT32_(value) << PAC_INTFLAGA_SERCOM2_Pos)) /* Assigment of value for SERCOM2 in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_SERCOM3_Pos              _UINT32_(26)                                         /* (PAC_INTFLAGA) SERCOM3 Position */
#define PAC_INTFLAGA_SERCOM3_Msk              (_UINT32_(0x1) << PAC_INTFLAGA_SERCOM3_Pos)          /* (PAC_INTFLAGA) SERCOM3 Mask */
#define PAC_INTFLAGA_SERCOM3(value)           (PAC_INTFLAGA_SERCOM3_Msk & (_UINT32_(value) << PAC_INTFLAGA_SERCOM3_Pos)) /* Assigment of value for SERCOM3 in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_SERCOM4_Pos              _UINT32_(27)                                         /* (PAC_INTFLAGA) SERCOM4 Position */
#define PAC_INTFLAGA_SERCOM4_Msk              (_UINT32_(0x1) << PAC_INTFLAGA_SERCOM4_Pos)          /* (PAC_INTFLAGA) SERCOM4 Mask */
#define PAC_INTFLAGA_SERCOM4(value)           (PAC_INTFLAGA_SERCOM4_Msk & (_UINT32_(value) << PAC_INTFLAGA_SERCOM4_Pos)) /* Assigment of value for SERCOM4 in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_SERCOM5_Pos              _UINT32_(28)                                         /* (PAC_INTFLAGA) SERCOM5 Position */
#define PAC_INTFLAGA_SERCOM5_Msk              (_UINT32_(0x1) << PAC_INTFLAGA_SERCOM5_Pos)          /* (PAC_INTFLAGA) SERCOM5 Mask */
#define PAC_INTFLAGA_SERCOM5(value)           (PAC_INTFLAGA_SERCOM5_Msk & (_UINT32_(value) << PAC_INTFLAGA_SERCOM5_Pos)) /* Assigment of value for SERCOM5 in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_SERCOM6_Pos              _UINT32_(29)                                         /* (PAC_INTFLAGA) SERCOM6 Position */
#define PAC_INTFLAGA_SERCOM6_Msk              (_UINT32_(0x1) << PAC_INTFLAGA_SERCOM6_Pos)          /* (PAC_INTFLAGA) SERCOM6 Mask */
#define PAC_INTFLAGA_SERCOM6(value)           (PAC_INTFLAGA_SERCOM6_Msk & (_UINT32_(value) << PAC_INTFLAGA_SERCOM6_Pos)) /* Assigment of value for SERCOM6 in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_SERCOM7_Pos              _UINT32_(30)                                         /* (PAC_INTFLAGA) SERCOM7 Position */
#define PAC_INTFLAGA_SERCOM7_Msk              (_UINT32_(0x1) << PAC_INTFLAGA_SERCOM7_Pos)          /* (PAC_INTFLAGA) SERCOM7 Mask */
#define PAC_INTFLAGA_SERCOM7(value)           (PAC_INTFLAGA_SERCOM7_Msk & (_UINT32_(value) << PAC_INTFLAGA_SERCOM7_Pos)) /* Assigment of value for SERCOM7 in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_SERCOM8_Pos              _UINT32_(31)                                         /* (PAC_INTFLAGA) SERCOM8 Position */
#define PAC_INTFLAGA_SERCOM8_Msk              (_UINT32_(0x1) << PAC_INTFLAGA_SERCOM8_Pos)          /* (PAC_INTFLAGA) SERCOM8 Mask */
#define PAC_INTFLAGA_SERCOM8(value)           (PAC_INTFLAGA_SERCOM8_Msk & (_UINT32_(value) << PAC_INTFLAGA_SERCOM8_Pos)) /* Assigment of value for SERCOM8 in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_Msk                      _UINT32_(0xFFEFFFFF)                                 /* (PAC_INTFLAGA) Register Mask  */

#define PAC_INTFLAGA_SERCOM_Pos               _UINT32_(23)                                         /* (PAC_INTFLAGA Position) SERCOM8 */
#define PAC_INTFLAGA_SERCOM_Msk               (_UINT32_(0x1FF) << PAC_INTFLAGA_SERCOM_Pos)         /* (PAC_INTFLAGA Mask) SERCOM */
#define PAC_INTFLAGA_SERCOM(value)            (PAC_INTFLAGA_SERCOM_Msk & (_UINT32_(value) << PAC_INTFLAGA_SERCOM_Pos)) 

/* -------- PAC_INTFLAGB : (PAC Offset: 0x18) (R/W 32) Peripheral interrupt flag status - Bridge B -------- */
#define PAC_INTFLAGB_RESETVALUE               _UINT32_(0x00)                                       /*  (PAC_INTFLAGB) Peripheral interrupt flag status - Bridge B  Reset Value */

#define PAC_INTFLAGB_SERCOM9_Pos              _UINT32_(0)                                          /* (PAC_INTFLAGB) SERCOM9 Position */
#define PAC_INTFLAGB_SERCOM9_Msk              (_UINT32_(0x1) << PAC_INTFLAGB_SERCOM9_Pos)          /* (PAC_INTFLAGB) SERCOM9 Mask */
#define PAC_INTFLAGB_SERCOM9(value)           (PAC_INTFLAGB_SERCOM9_Msk & (_UINT32_(value) << PAC_INTFLAGB_SERCOM9_Pos)) /* Assigment of value for SERCOM9 in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_TCC0_Pos                 _UINT32_(1)                                          /* (PAC_INTFLAGB) TCC0 Position */
#define PAC_INTFLAGB_TCC0_Msk                 (_UINT32_(0x1) << PAC_INTFLAGB_TCC0_Pos)             /* (PAC_INTFLAGB) TCC0 Mask */
#define PAC_INTFLAGB_TCC0(value)              (PAC_INTFLAGB_TCC0_Msk & (_UINT32_(value) << PAC_INTFLAGB_TCC0_Pos)) /* Assigment of value for TCC0 in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_TCC1_Pos                 _UINT32_(2)                                          /* (PAC_INTFLAGB) TCC1 Position */
#define PAC_INTFLAGB_TCC1_Msk                 (_UINT32_(0x1) << PAC_INTFLAGB_TCC1_Pos)             /* (PAC_INTFLAGB) TCC1 Mask */
#define PAC_INTFLAGB_TCC1(value)              (PAC_INTFLAGB_TCC1_Msk & (_UINT32_(value) << PAC_INTFLAGB_TCC1_Pos)) /* Assigment of value for TCC1 in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_TCC2_Pos                 _UINT32_(3)                                          /* (PAC_INTFLAGB) TCC2 Position */
#define PAC_INTFLAGB_TCC2_Msk                 (_UINT32_(0x1) << PAC_INTFLAGB_TCC2_Pos)             /* (PAC_INTFLAGB) TCC2 Mask */
#define PAC_INTFLAGB_TCC2(value)              (PAC_INTFLAGB_TCC2_Msk & (_UINT32_(value) << PAC_INTFLAGB_TCC2_Pos)) /* Assigment of value for TCC2 in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_TCC3_Pos                 _UINT32_(4)                                          /* (PAC_INTFLAGB) TCC3 Position */
#define PAC_INTFLAGB_TCC3_Msk                 (_UINT32_(0x1) << PAC_INTFLAGB_TCC3_Pos)             /* (PAC_INTFLAGB) TCC3 Mask */
#define PAC_INTFLAGB_TCC3(value)              (PAC_INTFLAGB_TCC3_Msk & (_UINT32_(value) << PAC_INTFLAGB_TCC3_Pos)) /* Assigment of value for TCC3 in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_TCC4_Pos                 _UINT32_(5)                                          /* (PAC_INTFLAGB) TCC4 Position */
#define PAC_INTFLAGB_TCC4_Msk                 (_UINT32_(0x1) << PAC_INTFLAGB_TCC4_Pos)             /* (PAC_INTFLAGB) TCC4 Mask */
#define PAC_INTFLAGB_TCC4(value)              (PAC_INTFLAGB_TCC4_Msk & (_UINT32_(value) << PAC_INTFLAGB_TCC4_Pos)) /* Assigment of value for TCC4 in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_TCC5_Pos                 _UINT32_(6)                                          /* (PAC_INTFLAGB) TCC5 Position */
#define PAC_INTFLAGB_TCC5_Msk                 (_UINT32_(0x1) << PAC_INTFLAGB_TCC5_Pos)             /* (PAC_INTFLAGB) TCC5 Mask */
#define PAC_INTFLAGB_TCC5(value)              (PAC_INTFLAGB_TCC5_Msk & (_UINT32_(value) << PAC_INTFLAGB_TCC5_Pos)) /* Assigment of value for TCC5 in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_TCC6_Pos                 _UINT32_(7)                                          /* (PAC_INTFLAGB) TCC6 Position */
#define PAC_INTFLAGB_TCC6_Msk                 (_UINT32_(0x1) << PAC_INTFLAGB_TCC6_Pos)             /* (PAC_INTFLAGB) TCC6 Mask */
#define PAC_INTFLAGB_TCC6(value)              (PAC_INTFLAGB_TCC6_Msk & (_UINT32_(value) << PAC_INTFLAGB_TCC6_Pos)) /* Assigment of value for TCC6 in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_TCC7_Pos                 _UINT32_(8)                                          /* (PAC_INTFLAGB) TCC7 Position */
#define PAC_INTFLAGB_TCC7_Msk                 (_UINT32_(0x1) << PAC_INTFLAGB_TCC7_Pos)             /* (PAC_INTFLAGB) TCC7 Mask */
#define PAC_INTFLAGB_TCC7(value)              (PAC_INTFLAGB_TCC7_Msk & (_UINT32_(value) << PAC_INTFLAGB_TCC7_Pos)) /* Assigment of value for TCC7 in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_TCC8_Pos                 _UINT32_(9)                                          /* (PAC_INTFLAGB) TCC8 Position */
#define PAC_INTFLAGB_TCC8_Msk                 (_UINT32_(0x1) << PAC_INTFLAGB_TCC8_Pos)             /* (PAC_INTFLAGB) TCC8 Mask */
#define PAC_INTFLAGB_TCC8(value)              (PAC_INTFLAGB_TCC8_Msk & (_UINT32_(value) << PAC_INTFLAGB_TCC8_Pos)) /* Assigment of value for TCC8 in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_TCC9_Pos                 _UINT32_(10)                                         /* (PAC_INTFLAGB) TCC9 Position */
#define PAC_INTFLAGB_TCC9_Msk                 (_UINT32_(0x1) << PAC_INTFLAGB_TCC9_Pos)             /* (PAC_INTFLAGB) TCC9 Mask */
#define PAC_INTFLAGB_TCC9(value)              (PAC_INTFLAGB_TCC9_Msk & (_UINT32_(value) << PAC_INTFLAGB_TCC9_Pos)) /* Assigment of value for TCC9 in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_ADC_Pos                  _UINT32_(11)                                         /* (PAC_INTFLAGB) ADC Position */
#define PAC_INTFLAGB_ADC_Msk                  (_UINT32_(0x1) << PAC_INTFLAGB_ADC_Pos)              /* (PAC_INTFLAGB) ADC Mask */
#define PAC_INTFLAGB_ADC(value)               (PAC_INTFLAGB_ADC_Msk & (_UINT32_(value) << PAC_INTFLAGB_ADC_Pos)) /* Assigment of value for ADC in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_AC_Pos                   _UINT32_(12)                                         /* (PAC_INTFLAGB) AC Position */
#define PAC_INTFLAGB_AC_Msk                   (_UINT32_(0x1) << PAC_INTFLAGB_AC_Pos)               /* (PAC_INTFLAGB) AC Mask */
#define PAC_INTFLAGB_AC(value)                (PAC_INTFLAGB_AC_Msk & (_UINT32_(value) << PAC_INTFLAGB_AC_Pos)) /* Assigment of value for AC in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_PTC_Pos                  _UINT32_(13)                                         /* (PAC_INTFLAGB) PTC Position */
#define PAC_INTFLAGB_PTC_Msk                  (_UINT32_(0x1) << PAC_INTFLAGB_PTC_Pos)              /* (PAC_INTFLAGB) PTC Mask */
#define PAC_INTFLAGB_PTC(value)               (PAC_INTFLAGB_PTC_Msk & (_UINT32_(value) << PAC_INTFLAGB_PTC_Pos)) /* Assigment of value for PTC in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_SPI_IXS0_Pos             _UINT32_(14)                                         /* (PAC_INTFLAGB) SPI_IXS0 Position */
#define PAC_INTFLAGB_SPI_IXS0_Msk             (_UINT32_(0x1) << PAC_INTFLAGB_SPI_IXS0_Pos)         /* (PAC_INTFLAGB) SPI_IXS0 Mask */
#define PAC_INTFLAGB_SPI_IXS0(value)          (PAC_INTFLAGB_SPI_IXS0_Msk & (_UINT32_(value) << PAC_INTFLAGB_SPI_IXS0_Pos)) /* Assigment of value for SPI_IXS0 in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_SPI_IXS1_Pos             _UINT32_(15)                                         /* (PAC_INTFLAGB) SPI_IXS1 Position */
#define PAC_INTFLAGB_SPI_IXS1_Msk             (_UINT32_(0x1) << PAC_INTFLAGB_SPI_IXS1_Pos)         /* (PAC_INTFLAGB) SPI_IXS1 Mask */
#define PAC_INTFLAGB_SPI_IXS1(value)          (PAC_INTFLAGB_SPI_IXS1_Msk & (_UINT32_(value) << PAC_INTFLAGB_SPI_IXS1_Pos)) /* Assigment of value for SPI_IXS1 in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_CAN0_Pos                 _UINT32_(16)                                         /* (PAC_INTFLAGB) CAN0 Position */
#define PAC_INTFLAGB_CAN0_Msk                 (_UINT32_(0x1) << PAC_INTFLAGB_CAN0_Pos)             /* (PAC_INTFLAGB) CAN0 Mask */
#define PAC_INTFLAGB_CAN0(value)              (PAC_INTFLAGB_CAN0_Msk & (_UINT32_(value) << PAC_INTFLAGB_CAN0_Pos)) /* Assigment of value for CAN0 in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_CAN1_Pos                 _UINT32_(17)                                         /* (PAC_INTFLAGB) CAN1 Position */
#define PAC_INTFLAGB_CAN1_Msk                 (_UINT32_(0x1) << PAC_INTFLAGB_CAN1_Pos)             /* (PAC_INTFLAGB) CAN1 Mask */
#define PAC_INTFLAGB_CAN1(value)              (PAC_INTFLAGB_CAN1_Msk & (_UINT32_(value) << PAC_INTFLAGB_CAN1_Pos)) /* Assigment of value for CAN1 in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_CAN2_Pos                 _UINT32_(18)                                         /* (PAC_INTFLAGB) CAN2 Position */
#define PAC_INTFLAGB_CAN2_Msk                 (_UINT32_(0x1) << PAC_INTFLAGB_CAN2_Pos)             /* (PAC_INTFLAGB) CAN2 Mask */
#define PAC_INTFLAGB_CAN2(value)              (PAC_INTFLAGB_CAN2_Msk & (_UINT32_(value) << PAC_INTFLAGB_CAN2_Pos)) /* Assigment of value for CAN2 in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_CAN3_Pos                 _UINT32_(19)                                         /* (PAC_INTFLAGB) CAN3 Position */
#define PAC_INTFLAGB_CAN3_Msk                 (_UINT32_(0x1) << PAC_INTFLAGB_CAN3_Pos)             /* (PAC_INTFLAGB) CAN3 Mask */
#define PAC_INTFLAGB_CAN3(value)              (PAC_INTFLAGB_CAN3_Msk & (_UINT32_(value) << PAC_INTFLAGB_CAN3_Pos)) /* Assigment of value for CAN3 in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_CAN4_Pos                 _UINT32_(20)                                         /* (PAC_INTFLAGB) CAN4 Position */
#define PAC_INTFLAGB_CAN4_Msk                 (_UINT32_(0x1) << PAC_INTFLAGB_CAN4_Pos)             /* (PAC_INTFLAGB) CAN4 Mask */
#define PAC_INTFLAGB_CAN4(value)              (PAC_INTFLAGB_CAN4_Msk & (_UINT32_(value) << PAC_INTFLAGB_CAN4_Pos)) /* Assigment of value for CAN4 in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_CAN5_Pos                 _UINT32_(21)                                         /* (PAC_INTFLAGB) CAN5 Position */
#define PAC_INTFLAGB_CAN5_Msk                 (_UINT32_(0x1) << PAC_INTFLAGB_CAN5_Pos)             /* (PAC_INTFLAGB) CAN5 Mask */
#define PAC_INTFLAGB_CAN5(value)              (PAC_INTFLAGB_CAN5_Msk & (_UINT32_(value) << PAC_INTFLAGB_CAN5_Pos)) /* Assigment of value for CAN5 in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_ETH_Pos                  _UINT32_(24)                                         /* (PAC_INTFLAGB) ETH Position */
#define PAC_INTFLAGB_ETH_Msk                  (_UINT32_(0x1) << PAC_INTFLAGB_ETH_Pos)              /* (PAC_INTFLAGB) ETH Mask */
#define PAC_INTFLAGB_ETH(value)               (PAC_INTFLAGB_ETH_Msk & (_UINT32_(value) << PAC_INTFLAGB_ETH_Pos)) /* Assigment of value for ETH in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_TRNG_Pos                 _UINT32_(27)                                         /* (PAC_INTFLAGB) TRNG Position */
#define PAC_INTFLAGB_TRNG_Msk                 (_UINT32_(0x1) << PAC_INTFLAGB_TRNG_Pos)             /* (PAC_INTFLAGB) TRNG Mask */
#define PAC_INTFLAGB_TRNG(value)              (PAC_INTFLAGB_TRNG_Msk & (_UINT32_(value) << PAC_INTFLAGB_TRNG_Pos)) /* Assigment of value for TRNG in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_SDMMC0_Pos               _UINT32_(28)                                         /* (PAC_INTFLAGB) SDMMC0 Position */
#define PAC_INTFLAGB_SDMMC0_Msk               (_UINT32_(0x1) << PAC_INTFLAGB_SDMMC0_Pos)           /* (PAC_INTFLAGB) SDMMC0 Mask */
#define PAC_INTFLAGB_SDMMC0(value)            (PAC_INTFLAGB_SDMMC0_Msk & (_UINT32_(value) << PAC_INTFLAGB_SDMMC0_Pos)) /* Assigment of value for SDMMC0 in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_SDMMC1_Pos               _UINT32_(29)                                         /* (PAC_INTFLAGB) SDMMC1 Position */
#define PAC_INTFLAGB_SDMMC1_Msk               (_UINT32_(0x1) << PAC_INTFLAGB_SDMMC1_Pos)           /* (PAC_INTFLAGB) SDMMC1 Mask */
#define PAC_INTFLAGB_SDMMC1(value)            (PAC_INTFLAGB_SDMMC1_Msk & (_UINT32_(value) << PAC_INTFLAGB_SDMMC1_Pos)) /* Assigment of value for SDMMC1 in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_Msk                      _UINT32_(0x393FFFFF)                                 /* (PAC_INTFLAGB) Register Mask  */

#define PAC_INTFLAGB_SERCOM_Pos               _UINT32_(0)                                          /* (PAC_INTFLAGB Position) SERCOM9 */
#define PAC_INTFLAGB_SERCOM_Msk               (_UINT32_(0x1) << PAC_INTFLAGB_SERCOM_Pos)           /* (PAC_INTFLAGB Mask) SERCOM */
#define PAC_INTFLAGB_SERCOM(value)            (PAC_INTFLAGB_SERCOM_Msk & (_UINT32_(value) << PAC_INTFLAGB_SERCOM_Pos)) 
#define PAC_INTFLAGB_TCC_Pos                  _UINT32_(1)                                          /* (PAC_INTFLAGB Position) TCCx */
#define PAC_INTFLAGB_TCC_Msk                  (_UINT32_(0x3FF) << PAC_INTFLAGB_TCC_Pos)            /* (PAC_INTFLAGB Mask) TCC */
#define PAC_INTFLAGB_TCC(value)               (PAC_INTFLAGB_TCC_Msk & (_UINT32_(value) << PAC_INTFLAGB_TCC_Pos)) 
#define PAC_INTFLAGB_SPI_IXS_Pos              _UINT32_(14)                                         /* (PAC_INTFLAGB Position) SPI_IXSx */
#define PAC_INTFLAGB_SPI_IXS_Msk              (_UINT32_(0x3) << PAC_INTFLAGB_SPI_IXS_Pos)          /* (PAC_INTFLAGB Mask) SPI_IXS */
#define PAC_INTFLAGB_SPI_IXS(value)           (PAC_INTFLAGB_SPI_IXS_Msk & (_UINT32_(value) << PAC_INTFLAGB_SPI_IXS_Pos)) 
#define PAC_INTFLAGB_CAN_Pos                  _UINT32_(16)                                         /* (PAC_INTFLAGB Position) CANx */
#define PAC_INTFLAGB_CAN_Msk                  (_UINT32_(0x3F) << PAC_INTFLAGB_CAN_Pos)             /* (PAC_INTFLAGB Mask) CAN */
#define PAC_INTFLAGB_CAN(value)               (PAC_INTFLAGB_CAN_Msk & (_UINT32_(value) << PAC_INTFLAGB_CAN_Pos)) 
#define PAC_INTFLAGB_SDMMC_Pos                _UINT32_(28)                                         /* (PAC_INTFLAGB Position) SDMMCx */
#define PAC_INTFLAGB_SDMMC_Msk                (_UINT32_(0x3) << PAC_INTFLAGB_SDMMC_Pos)            /* (PAC_INTFLAGB Mask) SDMMC */
#define PAC_INTFLAGB_SDMMC(value)             (PAC_INTFLAGB_SDMMC_Msk & (_UINT32_(value) << PAC_INTFLAGB_SDMMC_Pos)) 

/* -------- PAC_INTFLAGC : (PAC Offset: 0x1C) (R/W 32) Peripheral interrupt flag status - Bridge C -------- */
#define PAC_INTFLAGC_RESETVALUE               _UINT32_(0x00)                                       /*  (PAC_INTFLAGC) Peripheral interrupt flag status - Bridge C  Reset Value */

#define PAC_INTFLAGC_MLB_Pos                  _UINT32_(2)                                          /* (PAC_INTFLAGC) MLB Position */
#define PAC_INTFLAGC_MLB_Msk                  (_UINT32_(0x1) << PAC_INTFLAGC_MLB_Pos)              /* (PAC_INTFLAGC) MLB Mask */
#define PAC_INTFLAGC_MLB(value)               (PAC_INTFLAGC_MLB_Msk & (_UINT32_(value) << PAC_INTFLAGC_MLB_Pos)) /* Assigment of value for MLB in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_Msk                      _UINT32_(0x00000004)                                 /* (PAC_INTFLAGC) Register Mask  */


/* -------- PAC_STATUSA : (PAC Offset: 0x34) ( R/ 32) Peripheral write protection status - Bridge A -------- */
#define PAC_STATUSA_RESETVALUE                _UINT32_(0x00)                                       /*  (PAC_STATUSA) Peripheral write protection status - Bridge A  Reset Value */

#define PAC_STATUSA_DSU_Pos                   _UINT32_(0)                                          /* (PAC_STATUSA) DSU APB Protect Enable Position */
#define PAC_STATUSA_DSU_Msk                   (_UINT32_(0x1) << PAC_STATUSA_DSU_Pos)               /* (PAC_STATUSA) DSU APB Protect Enable Mask */
#define PAC_STATUSA_DSU(value)                (PAC_STATUSA_DSU_Msk & (_UINT32_(value) << PAC_STATUSA_DSU_Pos)) /* Assigment of value for DSU in the PAC_STATUSA register */
#define PAC_STATUSA_FCW_Pos                   _UINT32_(1)                                          /* (PAC_STATUSA) FCW APB Protect Enable Position */
#define PAC_STATUSA_FCW_Msk                   (_UINT32_(0x1) << PAC_STATUSA_FCW_Pos)               /* (PAC_STATUSA) FCW APB Protect Enable Mask */
#define PAC_STATUSA_FCW(value)                (PAC_STATUSA_FCW_Msk & (_UINT32_(value) << PAC_STATUSA_FCW_Pos)) /* Assigment of value for FCW in the PAC_STATUSA register */
#define PAC_STATUSA_FCR_Pos                   _UINT32_(2)                                          /* (PAC_STATUSA) FCR APB Protect Enable Position */
#define PAC_STATUSA_FCR_Msk                   (_UINT32_(0x1) << PAC_STATUSA_FCR_Pos)               /* (PAC_STATUSA) FCR APB Protect Enable Mask */
#define PAC_STATUSA_FCR(value)                (PAC_STATUSA_FCR_Msk & (_UINT32_(value) << PAC_STATUSA_FCR_Pos)) /* Assigment of value for FCR in the PAC_STATUSA register */
#define PAC_STATUSA_PM_Pos                    _UINT32_(3)                                          /* (PAC_STATUSA) PM APB Protect Enable Position */
#define PAC_STATUSA_PM_Msk                    (_UINT32_(0x1) << PAC_STATUSA_PM_Pos)                /* (PAC_STATUSA) PM APB Protect Enable Mask */
#define PAC_STATUSA_PM(value)                 (PAC_STATUSA_PM_Msk & (_UINT32_(value) << PAC_STATUSA_PM_Pos)) /* Assigment of value for PM in the PAC_STATUSA register */
#define PAC_STATUSA_SUPC_Pos                  _UINT32_(4)                                          /* (PAC_STATUSA) SUPC APB Protect Enable Position */
#define PAC_STATUSA_SUPC_Msk                  (_UINT32_(0x1) << PAC_STATUSA_SUPC_Pos)              /* (PAC_STATUSA) SUPC APB Protect Enable Mask */
#define PAC_STATUSA_SUPC(value)               (PAC_STATUSA_SUPC_Msk & (_UINT32_(value) << PAC_STATUSA_SUPC_Pos)) /* Assigment of value for SUPC in the PAC_STATUSA register */
#define PAC_STATUSA_RSTC_Pos                  _UINT32_(5)                                          /* (PAC_STATUSA) RSTC APB Protect Enable Position */
#define PAC_STATUSA_RSTC_Msk                  (_UINT32_(0x1) << PAC_STATUSA_RSTC_Pos)              /* (PAC_STATUSA) RSTC APB Protect Enable Mask */
#define PAC_STATUSA_RSTC(value)               (PAC_STATUSA_RSTC_Msk & (_UINT32_(value) << PAC_STATUSA_RSTC_Pos)) /* Assigment of value for RSTC in the PAC_STATUSA register */
#define PAC_STATUSA_OSCCTRL_Pos               _UINT32_(6)                                          /* (PAC_STATUSA) OSCCTRL APB Protect Enable Position */
#define PAC_STATUSA_OSCCTRL_Msk               (_UINT32_(0x1) << PAC_STATUSA_OSCCTRL_Pos)           /* (PAC_STATUSA) OSCCTRL APB Protect Enable Mask */
#define PAC_STATUSA_OSCCTRL(value)            (PAC_STATUSA_OSCCTRL_Msk & (_UINT32_(value) << PAC_STATUSA_OSCCTRL_Pos)) /* Assigment of value for OSCCTRL in the PAC_STATUSA register */
#define PAC_STATUSA_OSC32KCTRL_Pos            _UINT32_(7)                                          /* (PAC_STATUSA) OSC32KCTRL APB Protect Enable Position */
#define PAC_STATUSA_OSC32KCTRL_Msk            (_UINT32_(0x1) << PAC_STATUSA_OSC32KCTRL_Pos)        /* (PAC_STATUSA) OSC32KCTRL APB Protect Enable Mask */
#define PAC_STATUSA_OSC32KCTRL(value)         (PAC_STATUSA_OSC32KCTRL_Msk & (_UINT32_(value) << PAC_STATUSA_OSC32KCTRL_Pos)) /* Assigment of value for OSC32KCTRL in the PAC_STATUSA register */
#define PAC_STATUSA_GCLK_Pos                  _UINT32_(8)                                          /* (PAC_STATUSA) GCLK APB Protect Enable Position */
#define PAC_STATUSA_GCLK_Msk                  (_UINT32_(0x1) << PAC_STATUSA_GCLK_Pos)              /* (PAC_STATUSA) GCLK APB Protect Enable Mask */
#define PAC_STATUSA_GCLK(value)               (PAC_STATUSA_GCLK_Msk & (_UINT32_(value) << PAC_STATUSA_GCLK_Pos)) /* Assigment of value for GCLK in the PAC_STATUSA register */
#define PAC_STATUSA_MCLK_Pos                  _UINT32_(9)                                          /* (PAC_STATUSA) MCLK APB Protect Enable Position */
#define PAC_STATUSA_MCLK_Msk                  (_UINT32_(0x1) << PAC_STATUSA_MCLK_Pos)              /* (PAC_STATUSA) MCLK APB Protect Enable Mask */
#define PAC_STATUSA_MCLK(value)               (PAC_STATUSA_MCLK_Msk & (_UINT32_(value) << PAC_STATUSA_MCLK_Pos)) /* Assigment of value for MCLK in the PAC_STATUSA register */
#define PAC_STATUSA_FREQM_Pos                 _UINT32_(10)                                         /* (PAC_STATUSA) FREQM APB Protect Enable Position */
#define PAC_STATUSA_FREQM_Msk                 (_UINT32_(0x1) << PAC_STATUSA_FREQM_Pos)             /* (PAC_STATUSA) FREQM APB Protect Enable Mask */
#define PAC_STATUSA_FREQM(value)              (PAC_STATUSA_FREQM_Msk & (_UINT32_(value) << PAC_STATUSA_FREQM_Pos)) /* Assigment of value for FREQM in the PAC_STATUSA register */
#define PAC_STATUSA_WDT_Pos                   _UINT32_(11)                                         /* (PAC_STATUSA) WDT APB Protect Enable Position */
#define PAC_STATUSA_WDT_Msk                   (_UINT32_(0x1) << PAC_STATUSA_WDT_Pos)               /* (PAC_STATUSA) WDT APB Protect Enable Mask */
#define PAC_STATUSA_WDT(value)                (PAC_STATUSA_WDT_Msk & (_UINT32_(value) << PAC_STATUSA_WDT_Pos)) /* Assigment of value for WDT in the PAC_STATUSA register */
#define PAC_STATUSA_RTC_Pos                   _UINT32_(12)                                         /* (PAC_STATUSA) RTC APB Protect Enable Position */
#define PAC_STATUSA_RTC_Msk                   (_UINT32_(0x1) << PAC_STATUSA_RTC_Pos)               /* (PAC_STATUSA) RTC APB Protect Enable Mask */
#define PAC_STATUSA_RTC(value)                (PAC_STATUSA_RTC_Msk & (_UINT32_(value) << PAC_STATUSA_RTC_Pos)) /* Assigment of value for RTC in the PAC_STATUSA register */
#define PAC_STATUSA_EIC_Pos                   _UINT32_(13)                                         /* (PAC_STATUSA) EIC APB Protect Enable Position */
#define PAC_STATUSA_EIC_Msk                   (_UINT32_(0x1) << PAC_STATUSA_EIC_Pos)               /* (PAC_STATUSA) EIC APB Protect Enable Mask */
#define PAC_STATUSA_EIC(value)                (PAC_STATUSA_EIC_Msk & (_UINT32_(value) << PAC_STATUSA_EIC_Pos)) /* Assigment of value for EIC in the PAC_STATUSA register */
#define PAC_STATUSA_PAC_Pos                   _UINT32_(14)                                         /* (PAC_STATUSA) PAC APB Protect Enable Position */
#define PAC_STATUSA_PAC_Msk                   (_UINT32_(0x1) << PAC_STATUSA_PAC_Pos)               /* (PAC_STATUSA) PAC APB Protect Enable Mask */
#define PAC_STATUSA_PAC(value)                (PAC_STATUSA_PAC_Msk & (_UINT32_(value) << PAC_STATUSA_PAC_Pos)) /* Assigment of value for PAC in the PAC_STATUSA register */
#define PAC_STATUSA_DRMTCM_Pos                _UINT32_(15)                                         /* (PAC_STATUSA) DRMTCM APB Protect Enable Position */
#define PAC_STATUSA_DRMTCM_Msk                (_UINT32_(0x1) << PAC_STATUSA_DRMTCM_Pos)            /* (PAC_STATUSA) DRMTCM APB Protect Enable Mask */
#define PAC_STATUSA_DRMTCM(value)             (PAC_STATUSA_DRMTCM_Msk & (_UINT32_(value) << PAC_STATUSA_DRMTCM_Pos)) /* Assigment of value for DRMTCM in the PAC_STATUSA register */
#define PAC_STATUSA_MCRAMC_Pos                _UINT32_(16)                                         /* (PAC_STATUSA) MCRAMC APB Protect Enable Position */
#define PAC_STATUSA_MCRAMC_Msk                (_UINT32_(0x1) << PAC_STATUSA_MCRAMC_Pos)            /* (PAC_STATUSA) MCRAMC APB Protect Enable Mask */
#define PAC_STATUSA_MCRAMC(value)             (PAC_STATUSA_MCRAMC_Msk & (_UINT32_(value) << PAC_STATUSA_MCRAMC_Pos)) /* Assigment of value for MCRAMC in the PAC_STATUSA register */
#define PAC_STATUSA_TRAM_Pos                  _UINT32_(17)                                         /* (PAC_STATUSA) TRAM APB Protect Enable Position */
#define PAC_STATUSA_TRAM_Msk                  (_UINT32_(0x1) << PAC_STATUSA_TRAM_Pos)              /* (PAC_STATUSA) TRAM APB Protect Enable Mask */
#define PAC_STATUSA_TRAM(value)               (PAC_STATUSA_TRAM_Msk & (_UINT32_(value) << PAC_STATUSA_TRAM_Pos)) /* Assigment of value for TRAM in the PAC_STATUSA register */
#define PAC_STATUSA_PORT_Pos                  _UINT32_(18)                                         /* (PAC_STATUSA) PORT APB Protect Enable Position */
#define PAC_STATUSA_PORT_Msk                  (_UINT32_(0x1) << PAC_STATUSA_PORT_Pos)              /* (PAC_STATUSA) PORT APB Protect Enable Mask */
#define PAC_STATUSA_PORT(value)               (PAC_STATUSA_PORT_Msk & (_UINT32_(value) << PAC_STATUSA_PORT_Pos)) /* Assigment of value for PORT in the PAC_STATUSA register */
#define PAC_STATUSA_DMA_Pos                   _UINT32_(19)                                         /* (PAC_STATUSA) DMA APB Protect Enable Position */
#define PAC_STATUSA_DMA_Msk                   (_UINT32_(0x1) << PAC_STATUSA_DMA_Pos)               /* (PAC_STATUSA) DMA APB Protect Enable Mask */
#define PAC_STATUSA_DMA(value)                (PAC_STATUSA_DMA_Msk & (_UINT32_(value) << PAC_STATUSA_DMA_Pos)) /* Assigment of value for DMA in the PAC_STATUSA register */
#define PAC_STATUSA_PRM_Pos                   _UINT32_(21)                                         /* (PAC_STATUSA) PRM APB Protect Enable Position */
#define PAC_STATUSA_PRM_Msk                   (_UINT32_(0x1) << PAC_STATUSA_PRM_Pos)               /* (PAC_STATUSA) PRM APB Protect Enable Mask */
#define PAC_STATUSA_PRM(value)                (PAC_STATUSA_PRM_Msk & (_UINT32_(value) << PAC_STATUSA_PRM_Pos)) /* Assigment of value for PRM in the PAC_STATUSA register */
#define PAC_STATUSA_EVSYS_Pos                 _UINT32_(22)                                         /* (PAC_STATUSA) EVSYS APB Protect Enable Position */
#define PAC_STATUSA_EVSYS_Msk                 (_UINT32_(0x1) << PAC_STATUSA_EVSYS_Pos)             /* (PAC_STATUSA) EVSYS APB Protect Enable Mask */
#define PAC_STATUSA_EVSYS(value)              (PAC_STATUSA_EVSYS_Msk & (_UINT32_(value) << PAC_STATUSA_EVSYS_Pos)) /* Assigment of value for EVSYS in the PAC_STATUSA register */
#define PAC_STATUSA_SERCOM0_Pos               _UINT32_(23)                                         /* (PAC_STATUSA) SERCOM0 APB Protect Enable Position */
#define PAC_STATUSA_SERCOM0_Msk               (_UINT32_(0x1) << PAC_STATUSA_SERCOM0_Pos)           /* (PAC_STATUSA) SERCOM0 APB Protect Enable Mask */
#define PAC_STATUSA_SERCOM0(value)            (PAC_STATUSA_SERCOM0_Msk & (_UINT32_(value) << PAC_STATUSA_SERCOM0_Pos)) /* Assigment of value for SERCOM0 in the PAC_STATUSA register */
#define PAC_STATUSA_SERCOM1_Pos               _UINT32_(24)                                         /* (PAC_STATUSA) SERCOM1 APB Protect Enable Position */
#define PAC_STATUSA_SERCOM1_Msk               (_UINT32_(0x1) << PAC_STATUSA_SERCOM1_Pos)           /* (PAC_STATUSA) SERCOM1 APB Protect Enable Mask */
#define PAC_STATUSA_SERCOM1(value)            (PAC_STATUSA_SERCOM1_Msk & (_UINT32_(value) << PAC_STATUSA_SERCOM1_Pos)) /* Assigment of value for SERCOM1 in the PAC_STATUSA register */
#define PAC_STATUSA_SERCOM2_Pos               _UINT32_(25)                                         /* (PAC_STATUSA) SERCOM2 APB Protect Enable Position */
#define PAC_STATUSA_SERCOM2_Msk               (_UINT32_(0x1) << PAC_STATUSA_SERCOM2_Pos)           /* (PAC_STATUSA) SERCOM2 APB Protect Enable Mask */
#define PAC_STATUSA_SERCOM2(value)            (PAC_STATUSA_SERCOM2_Msk & (_UINT32_(value) << PAC_STATUSA_SERCOM2_Pos)) /* Assigment of value for SERCOM2 in the PAC_STATUSA register */
#define PAC_STATUSA_SERCOM3_Pos               _UINT32_(26)                                         /* (PAC_STATUSA) SERCOM3 APB Protect Enable Position */
#define PAC_STATUSA_SERCOM3_Msk               (_UINT32_(0x1) << PAC_STATUSA_SERCOM3_Pos)           /* (PAC_STATUSA) SERCOM3 APB Protect Enable Mask */
#define PAC_STATUSA_SERCOM3(value)            (PAC_STATUSA_SERCOM3_Msk & (_UINT32_(value) << PAC_STATUSA_SERCOM3_Pos)) /* Assigment of value for SERCOM3 in the PAC_STATUSA register */
#define PAC_STATUSA_SERCOM4_Pos               _UINT32_(27)                                         /* (PAC_STATUSA) SERCOM4 APB Protect Enable Position */
#define PAC_STATUSA_SERCOM4_Msk               (_UINT32_(0x1) << PAC_STATUSA_SERCOM4_Pos)           /* (PAC_STATUSA) SERCOM4 APB Protect Enable Mask */
#define PAC_STATUSA_SERCOM4(value)            (PAC_STATUSA_SERCOM4_Msk & (_UINT32_(value) << PAC_STATUSA_SERCOM4_Pos)) /* Assigment of value for SERCOM4 in the PAC_STATUSA register */
#define PAC_STATUSA_SERCOM5_Pos               _UINT32_(28)                                         /* (PAC_STATUSA) SERCOM5 APB Protect Enable Position */
#define PAC_STATUSA_SERCOM5_Msk               (_UINT32_(0x1) << PAC_STATUSA_SERCOM5_Pos)           /* (PAC_STATUSA) SERCOM5 APB Protect Enable Mask */
#define PAC_STATUSA_SERCOM5(value)            (PAC_STATUSA_SERCOM5_Msk & (_UINT32_(value) << PAC_STATUSA_SERCOM5_Pos)) /* Assigment of value for SERCOM5 in the PAC_STATUSA register */
#define PAC_STATUSA_SERCOM6_Pos               _UINT32_(29)                                         /* (PAC_STATUSA) SERCOM6 APB Protect Enable Position */
#define PAC_STATUSA_SERCOM6_Msk               (_UINT32_(0x1) << PAC_STATUSA_SERCOM6_Pos)           /* (PAC_STATUSA) SERCOM6 APB Protect Enable Mask */
#define PAC_STATUSA_SERCOM6(value)            (PAC_STATUSA_SERCOM6_Msk & (_UINT32_(value) << PAC_STATUSA_SERCOM6_Pos)) /* Assigment of value for SERCOM6 in the PAC_STATUSA register */
#define PAC_STATUSA_SERCOM7_Pos               _UINT32_(30)                                         /* (PAC_STATUSA) SERCOM7 APB Protect Enable Position */
#define PAC_STATUSA_SERCOM7_Msk               (_UINT32_(0x1) << PAC_STATUSA_SERCOM7_Pos)           /* (PAC_STATUSA) SERCOM7 APB Protect Enable Mask */
#define PAC_STATUSA_SERCOM7(value)            (PAC_STATUSA_SERCOM7_Msk & (_UINT32_(value) << PAC_STATUSA_SERCOM7_Pos)) /* Assigment of value for SERCOM7 in the PAC_STATUSA register */
#define PAC_STATUSA_SERCOM8_Pos               _UINT32_(31)                                         /* (PAC_STATUSA) SERCOM8 APB Protect Enable Position */
#define PAC_STATUSA_SERCOM8_Msk               (_UINT32_(0x1) << PAC_STATUSA_SERCOM8_Pos)           /* (PAC_STATUSA) SERCOM8 APB Protect Enable Mask */
#define PAC_STATUSA_SERCOM8(value)            (PAC_STATUSA_SERCOM8_Msk & (_UINT32_(value) << PAC_STATUSA_SERCOM8_Pos)) /* Assigment of value for SERCOM8 in the PAC_STATUSA register */
#define PAC_STATUSA_Msk                       _UINT32_(0xFFEFFFFF)                                 /* (PAC_STATUSA) Register Mask  */

#define PAC_STATUSA_SERCOM_Pos                _UINT32_(23)                                         /* (PAC_STATUSA Position) SERCOM8 APB Protect Enable */
#define PAC_STATUSA_SERCOM_Msk                (_UINT32_(0x1FF) << PAC_STATUSA_SERCOM_Pos)          /* (PAC_STATUSA Mask) SERCOM */
#define PAC_STATUSA_SERCOM(value)             (PAC_STATUSA_SERCOM_Msk & (_UINT32_(value) << PAC_STATUSA_SERCOM_Pos)) 

/* -------- PAC_STATUSB : (PAC Offset: 0x38) ( R/ 32) Peripheral write protection status - Bridge B -------- */
#define PAC_STATUSB_RESETVALUE                _UINT32_(0x00)                                       /*  (PAC_STATUSB) Peripheral write protection status - Bridge B  Reset Value */

#define PAC_STATUSB_SERCOM9_Pos               _UINT32_(0)                                          /* (PAC_STATUSB) SERCOM9 APB Protect Enable Position */
#define PAC_STATUSB_SERCOM9_Msk               (_UINT32_(0x1) << PAC_STATUSB_SERCOM9_Pos)           /* (PAC_STATUSB) SERCOM9 APB Protect Enable Mask */
#define PAC_STATUSB_SERCOM9(value)            (PAC_STATUSB_SERCOM9_Msk & (_UINT32_(value) << PAC_STATUSB_SERCOM9_Pos)) /* Assigment of value for SERCOM9 in the PAC_STATUSB register */
#define PAC_STATUSB_TCC0_Pos                  _UINT32_(1)                                          /* (PAC_STATUSB) TCC0 APB Protect Enable Position */
#define PAC_STATUSB_TCC0_Msk                  (_UINT32_(0x1) << PAC_STATUSB_TCC0_Pos)              /* (PAC_STATUSB) TCC0 APB Protect Enable Mask */
#define PAC_STATUSB_TCC0(value)               (PAC_STATUSB_TCC0_Msk & (_UINT32_(value) << PAC_STATUSB_TCC0_Pos)) /* Assigment of value for TCC0 in the PAC_STATUSB register */
#define PAC_STATUSB_TCC1_Pos                  _UINT32_(2)                                          /* (PAC_STATUSB) TCC1 APB Protect Enable Position */
#define PAC_STATUSB_TCC1_Msk                  (_UINT32_(0x1) << PAC_STATUSB_TCC1_Pos)              /* (PAC_STATUSB) TCC1 APB Protect Enable Mask */
#define PAC_STATUSB_TCC1(value)               (PAC_STATUSB_TCC1_Msk & (_UINT32_(value) << PAC_STATUSB_TCC1_Pos)) /* Assigment of value for TCC1 in the PAC_STATUSB register */
#define PAC_STATUSB_TCC2_Pos                  _UINT32_(3)                                          /* (PAC_STATUSB) TCC2 APB Protect Enable Position */
#define PAC_STATUSB_TCC2_Msk                  (_UINT32_(0x1) << PAC_STATUSB_TCC2_Pos)              /* (PAC_STATUSB) TCC2 APB Protect Enable Mask */
#define PAC_STATUSB_TCC2(value)               (PAC_STATUSB_TCC2_Msk & (_UINT32_(value) << PAC_STATUSB_TCC2_Pos)) /* Assigment of value for TCC2 in the PAC_STATUSB register */
#define PAC_STATUSB_TCC3_Pos                  _UINT32_(4)                                          /* (PAC_STATUSB) TCC3 APB Protect Enable Position */
#define PAC_STATUSB_TCC3_Msk                  (_UINT32_(0x1) << PAC_STATUSB_TCC3_Pos)              /* (PAC_STATUSB) TCC3 APB Protect Enable Mask */
#define PAC_STATUSB_TCC3(value)               (PAC_STATUSB_TCC3_Msk & (_UINT32_(value) << PAC_STATUSB_TCC3_Pos)) /* Assigment of value for TCC3 in the PAC_STATUSB register */
#define PAC_STATUSB_TCC4_Pos                  _UINT32_(5)                                          /* (PAC_STATUSB) TCC4 APB Protect Enable Position */
#define PAC_STATUSB_TCC4_Msk                  (_UINT32_(0x1) << PAC_STATUSB_TCC4_Pos)              /* (PAC_STATUSB) TCC4 APB Protect Enable Mask */
#define PAC_STATUSB_TCC4(value)               (PAC_STATUSB_TCC4_Msk & (_UINT32_(value) << PAC_STATUSB_TCC4_Pos)) /* Assigment of value for TCC4 in the PAC_STATUSB register */
#define PAC_STATUSB_TCC5_Pos                  _UINT32_(6)                                          /* (PAC_STATUSB) TCC5 APB Protect Enable Position */
#define PAC_STATUSB_TCC5_Msk                  (_UINT32_(0x1) << PAC_STATUSB_TCC5_Pos)              /* (PAC_STATUSB) TCC5 APB Protect Enable Mask */
#define PAC_STATUSB_TCC5(value)               (PAC_STATUSB_TCC5_Msk & (_UINT32_(value) << PAC_STATUSB_TCC5_Pos)) /* Assigment of value for TCC5 in the PAC_STATUSB register */
#define PAC_STATUSB_TCC6_Pos                  _UINT32_(7)                                          /* (PAC_STATUSB) TCC6 APB Protect Enable Position */
#define PAC_STATUSB_TCC6_Msk                  (_UINT32_(0x1) << PAC_STATUSB_TCC6_Pos)              /* (PAC_STATUSB) TCC6 APB Protect Enable Mask */
#define PAC_STATUSB_TCC6(value)               (PAC_STATUSB_TCC6_Msk & (_UINT32_(value) << PAC_STATUSB_TCC6_Pos)) /* Assigment of value for TCC6 in the PAC_STATUSB register */
#define PAC_STATUSB_TCC7_Pos                  _UINT32_(8)                                          /* (PAC_STATUSB) TCC7 APB Protect Enable Position */
#define PAC_STATUSB_TCC7_Msk                  (_UINT32_(0x1) << PAC_STATUSB_TCC7_Pos)              /* (PAC_STATUSB) TCC7 APB Protect Enable Mask */
#define PAC_STATUSB_TCC7(value)               (PAC_STATUSB_TCC7_Msk & (_UINT32_(value) << PAC_STATUSB_TCC7_Pos)) /* Assigment of value for TCC7 in the PAC_STATUSB register */
#define PAC_STATUSB_TCC8_Pos                  _UINT32_(9)                                          /* (PAC_STATUSB) TCC8 APB Protect Enable Position */
#define PAC_STATUSB_TCC8_Msk                  (_UINT32_(0x1) << PAC_STATUSB_TCC8_Pos)              /* (PAC_STATUSB) TCC8 APB Protect Enable Mask */
#define PAC_STATUSB_TCC8(value)               (PAC_STATUSB_TCC8_Msk & (_UINT32_(value) << PAC_STATUSB_TCC8_Pos)) /* Assigment of value for TCC8 in the PAC_STATUSB register */
#define PAC_STATUSB_TCC9_Pos                  _UINT32_(10)                                         /* (PAC_STATUSB) TCC9 APB Protect Enable Position */
#define PAC_STATUSB_TCC9_Msk                  (_UINT32_(0x1) << PAC_STATUSB_TCC9_Pos)              /* (PAC_STATUSB) TCC9 APB Protect Enable Mask */
#define PAC_STATUSB_TCC9(value)               (PAC_STATUSB_TCC9_Msk & (_UINT32_(value) << PAC_STATUSB_TCC9_Pos)) /* Assigment of value for TCC9 in the PAC_STATUSB register */
#define PAC_STATUSB_ADC_Pos                   _UINT32_(11)                                         /* (PAC_STATUSB) ADC APB Protect Enable Position */
#define PAC_STATUSB_ADC_Msk                   (_UINT32_(0x1) << PAC_STATUSB_ADC_Pos)               /* (PAC_STATUSB) ADC APB Protect Enable Mask */
#define PAC_STATUSB_ADC(value)                (PAC_STATUSB_ADC_Msk & (_UINT32_(value) << PAC_STATUSB_ADC_Pos)) /* Assigment of value for ADC in the PAC_STATUSB register */
#define PAC_STATUSB_AC_Pos                    _UINT32_(12)                                         /* (PAC_STATUSB) AC APB Protect Enable Position */
#define PAC_STATUSB_AC_Msk                    (_UINT32_(0x1) << PAC_STATUSB_AC_Pos)                /* (PAC_STATUSB) AC APB Protect Enable Mask */
#define PAC_STATUSB_AC(value)                 (PAC_STATUSB_AC_Msk & (_UINT32_(value) << PAC_STATUSB_AC_Pos)) /* Assigment of value for AC in the PAC_STATUSB register */
#define PAC_STATUSB_PTC_Pos                   _UINT32_(13)                                         /* (PAC_STATUSB) PTC APB Protect Enable Position */
#define PAC_STATUSB_PTC_Msk                   (_UINT32_(0x1) << PAC_STATUSB_PTC_Pos)               /* (PAC_STATUSB) PTC APB Protect Enable Mask */
#define PAC_STATUSB_PTC(value)                (PAC_STATUSB_PTC_Msk & (_UINT32_(value) << PAC_STATUSB_PTC_Pos)) /* Assigment of value for PTC in the PAC_STATUSB register */
#define PAC_STATUSB_SPI_IXS0_Pos              _UINT32_(14)                                         /* (PAC_STATUSB) SPI_IXS0 APB Protect Enable Position */
#define PAC_STATUSB_SPI_IXS0_Msk              (_UINT32_(0x1) << PAC_STATUSB_SPI_IXS0_Pos)          /* (PAC_STATUSB) SPI_IXS0 APB Protect Enable Mask */
#define PAC_STATUSB_SPI_IXS0(value)           (PAC_STATUSB_SPI_IXS0_Msk & (_UINT32_(value) << PAC_STATUSB_SPI_IXS0_Pos)) /* Assigment of value for SPI_IXS0 in the PAC_STATUSB register */
#define PAC_STATUSB_SPI_IXS1_Pos              _UINT32_(15)                                         /* (PAC_STATUSB) SPI_IXS1 APB Protect Enable Position */
#define PAC_STATUSB_SPI_IXS1_Msk              (_UINT32_(0x1) << PAC_STATUSB_SPI_IXS1_Pos)          /* (PAC_STATUSB) SPI_IXS1 APB Protect Enable Mask */
#define PAC_STATUSB_SPI_IXS1(value)           (PAC_STATUSB_SPI_IXS1_Msk & (_UINT32_(value) << PAC_STATUSB_SPI_IXS1_Pos)) /* Assigment of value for SPI_IXS1 in the PAC_STATUSB register */
#define PAC_STATUSB_CAN0_Pos                  _UINT32_(16)                                         /* (PAC_STATUSB) CAN0 APB Protect Enable Position */
#define PAC_STATUSB_CAN0_Msk                  (_UINT32_(0x1) << PAC_STATUSB_CAN0_Pos)              /* (PAC_STATUSB) CAN0 APB Protect Enable Mask */
#define PAC_STATUSB_CAN0(value)               (PAC_STATUSB_CAN0_Msk & (_UINT32_(value) << PAC_STATUSB_CAN0_Pos)) /* Assigment of value for CAN0 in the PAC_STATUSB register */
#define PAC_STATUSB_CAN1_Pos                  _UINT32_(17)                                         /* (PAC_STATUSB) CAN1 APB Protect Enable Position */
#define PAC_STATUSB_CAN1_Msk                  (_UINT32_(0x1) << PAC_STATUSB_CAN1_Pos)              /* (PAC_STATUSB) CAN1 APB Protect Enable Mask */
#define PAC_STATUSB_CAN1(value)               (PAC_STATUSB_CAN1_Msk & (_UINT32_(value) << PAC_STATUSB_CAN1_Pos)) /* Assigment of value for CAN1 in the PAC_STATUSB register */
#define PAC_STATUSB_CAN2_Pos                  _UINT32_(18)                                         /* (PAC_STATUSB) CAN2 APB Protect Enable Position */
#define PAC_STATUSB_CAN2_Msk                  (_UINT32_(0x1) << PAC_STATUSB_CAN2_Pos)              /* (PAC_STATUSB) CAN2 APB Protect Enable Mask */
#define PAC_STATUSB_CAN2(value)               (PAC_STATUSB_CAN2_Msk & (_UINT32_(value) << PAC_STATUSB_CAN2_Pos)) /* Assigment of value for CAN2 in the PAC_STATUSB register */
#define PAC_STATUSB_CAN3_Pos                  _UINT32_(19)                                         /* (PAC_STATUSB) CAN3 APB Protect Enable Position */
#define PAC_STATUSB_CAN3_Msk                  (_UINT32_(0x1) << PAC_STATUSB_CAN3_Pos)              /* (PAC_STATUSB) CAN3 APB Protect Enable Mask */
#define PAC_STATUSB_CAN3(value)               (PAC_STATUSB_CAN3_Msk & (_UINT32_(value) << PAC_STATUSB_CAN3_Pos)) /* Assigment of value for CAN3 in the PAC_STATUSB register */
#define PAC_STATUSB_CAN4_Pos                  _UINT32_(20)                                         /* (PAC_STATUSB) CAN4 APB Protect Enable Position */
#define PAC_STATUSB_CAN4_Msk                  (_UINT32_(0x1) << PAC_STATUSB_CAN4_Pos)              /* (PAC_STATUSB) CAN4 APB Protect Enable Mask */
#define PAC_STATUSB_CAN4(value)               (PAC_STATUSB_CAN4_Msk & (_UINT32_(value) << PAC_STATUSB_CAN4_Pos)) /* Assigment of value for CAN4 in the PAC_STATUSB register */
#define PAC_STATUSB_CAN5_Pos                  _UINT32_(21)                                         /* (PAC_STATUSB) CAN5 APB Protect Enable Position */
#define PAC_STATUSB_CAN5_Msk                  (_UINT32_(0x1) << PAC_STATUSB_CAN5_Pos)              /* (PAC_STATUSB) CAN5 APB Protect Enable Mask */
#define PAC_STATUSB_CAN5(value)               (PAC_STATUSB_CAN5_Msk & (_UINT32_(value) << PAC_STATUSB_CAN5_Pos)) /* Assigment of value for CAN5 in the PAC_STATUSB register */
#define PAC_STATUSB_ETH_Pos                   _UINT32_(24)                                         /* (PAC_STATUSB) ETH APB Protect Enable Position */
#define PAC_STATUSB_ETH_Msk                   (_UINT32_(0x1) << PAC_STATUSB_ETH_Pos)               /* (PAC_STATUSB) ETH APB Protect Enable Mask */
#define PAC_STATUSB_ETH(value)                (PAC_STATUSB_ETH_Msk & (_UINT32_(value) << PAC_STATUSB_ETH_Pos)) /* Assigment of value for ETH in the PAC_STATUSB register */
#define PAC_STATUSB_SQI0_Pos                  _UINT32_(25)                                         /* (PAC_STATUSB) SQI0 APB Protect Enable Position */
#define PAC_STATUSB_SQI0_Msk                  (_UINT32_(0x1) << PAC_STATUSB_SQI0_Pos)              /* (PAC_STATUSB) SQI0 APB Protect Enable Mask */
#define PAC_STATUSB_SQI0(value)               (PAC_STATUSB_SQI0_Msk & (_UINT32_(value) << PAC_STATUSB_SQI0_Pos)) /* Assigment of value for SQI0 in the PAC_STATUSB register */
#define PAC_STATUSB_SQI1_Pos                  _UINT32_(26)                                         /* (PAC_STATUSB) SQI1 APB Protect Enable Position */
#define PAC_STATUSB_SQI1_Msk                  (_UINT32_(0x1) << PAC_STATUSB_SQI1_Pos)              /* (PAC_STATUSB) SQI1 APB Protect Enable Mask */
#define PAC_STATUSB_SQI1(value)               (PAC_STATUSB_SQI1_Msk & (_UINT32_(value) << PAC_STATUSB_SQI1_Pos)) /* Assigment of value for SQI1 in the PAC_STATUSB register */
#define PAC_STATUSB_TRNG_Pos                  _UINT32_(27)                                         /* (PAC_STATUSB) TRNG APB Protect Enable Position */
#define PAC_STATUSB_TRNG_Msk                  (_UINT32_(0x1) << PAC_STATUSB_TRNG_Pos)              /* (PAC_STATUSB) TRNG APB Protect Enable Mask */
#define PAC_STATUSB_TRNG(value)               (PAC_STATUSB_TRNG_Msk & (_UINT32_(value) << PAC_STATUSB_TRNG_Pos)) /* Assigment of value for TRNG in the PAC_STATUSB register */
#define PAC_STATUSB_SDMMC0_Pos                _UINT32_(28)                                         /* (PAC_STATUSB) SDMMC0 APB Protect Enable Position */
#define PAC_STATUSB_SDMMC0_Msk                (_UINT32_(0x1) << PAC_STATUSB_SDMMC0_Pos)            /* (PAC_STATUSB) SDMMC0 APB Protect Enable Mask */
#define PAC_STATUSB_SDMMC0(value)             (PAC_STATUSB_SDMMC0_Msk & (_UINT32_(value) << PAC_STATUSB_SDMMC0_Pos)) /* Assigment of value for SDMMC0 in the PAC_STATUSB register */
#define PAC_STATUSB_SDMMC1_Pos                _UINT32_(29)                                         /* (PAC_STATUSB) SDMMC1 APB Protect Enable Position */
#define PAC_STATUSB_SDMMC1_Msk                (_UINT32_(0x1) << PAC_STATUSB_SDMMC1_Pos)            /* (PAC_STATUSB) SDMMC1 APB Protect Enable Mask */
#define PAC_STATUSB_SDMMC1(value)             (PAC_STATUSB_SDMMC1_Msk & (_UINT32_(value) << PAC_STATUSB_SDMMC1_Pos)) /* Assigment of value for SDMMC1 in the PAC_STATUSB register */
#define PAC_STATUSB_Msk                       _UINT32_(0x3F3FFFFF)                                 /* (PAC_STATUSB) Register Mask  */

#define PAC_STATUSB_SERCOM_Pos                _UINT32_(0)                                          /* (PAC_STATUSB Position) SERCOM9 APB Protect Enable */
#define PAC_STATUSB_SERCOM_Msk                (_UINT32_(0x1) << PAC_STATUSB_SERCOM_Pos)            /* (PAC_STATUSB Mask) SERCOM */
#define PAC_STATUSB_SERCOM(value)             (PAC_STATUSB_SERCOM_Msk & (_UINT32_(value) << PAC_STATUSB_SERCOM_Pos)) 
#define PAC_STATUSB_TCC_Pos                   _UINT32_(1)                                          /* (PAC_STATUSB Position) TCCx APB Protect Enable */
#define PAC_STATUSB_TCC_Msk                   (_UINT32_(0x3FF) << PAC_STATUSB_TCC_Pos)             /* (PAC_STATUSB Mask) TCC */
#define PAC_STATUSB_TCC(value)                (PAC_STATUSB_TCC_Msk & (_UINT32_(value) << PAC_STATUSB_TCC_Pos)) 
#define PAC_STATUSB_SPI_IXS_Pos               _UINT32_(14)                                         /* (PAC_STATUSB Position) SPI_IXSx APB Protect Enable */
#define PAC_STATUSB_SPI_IXS_Msk               (_UINT32_(0x3) << PAC_STATUSB_SPI_IXS_Pos)           /* (PAC_STATUSB Mask) SPI_IXS */
#define PAC_STATUSB_SPI_IXS(value)            (PAC_STATUSB_SPI_IXS_Msk & (_UINT32_(value) << PAC_STATUSB_SPI_IXS_Pos)) 
#define PAC_STATUSB_CAN_Pos                   _UINT32_(16)                                         /* (PAC_STATUSB Position) CANx APB Protect Enable */
#define PAC_STATUSB_CAN_Msk                   (_UINT32_(0x3F) << PAC_STATUSB_CAN_Pos)              /* (PAC_STATUSB Mask) CAN */
#define PAC_STATUSB_CAN(value)                (PAC_STATUSB_CAN_Msk & (_UINT32_(value) << PAC_STATUSB_CAN_Pos)) 
#define PAC_STATUSB_SQI_Pos                   _UINT32_(25)                                         /* (PAC_STATUSB Position) SQIx APB Protect Enable */
#define PAC_STATUSB_SQI_Msk                   (_UINT32_(0x3) << PAC_STATUSB_SQI_Pos)               /* (PAC_STATUSB Mask) SQI */
#define PAC_STATUSB_SQI(value)                (PAC_STATUSB_SQI_Msk & (_UINT32_(value) << PAC_STATUSB_SQI_Pos)) 
#define PAC_STATUSB_SDMMC_Pos                 _UINT32_(28)                                         /* (PAC_STATUSB Position) SDMMCx APB Protect Enable */
#define PAC_STATUSB_SDMMC_Msk                 (_UINT32_(0x3) << PAC_STATUSB_SDMMC_Pos)             /* (PAC_STATUSB Mask) SDMMC */
#define PAC_STATUSB_SDMMC(value)              (PAC_STATUSB_SDMMC_Msk & (_UINT32_(value) << PAC_STATUSB_SDMMC_Pos)) 

/* -------- PAC_STATUSC : (PAC Offset: 0x3C) ( R/ 32) Peripheral write protection status - Bridge C -------- */
#define PAC_STATUSC_RESETVALUE                _UINT32_(0x38)                                       /*  (PAC_STATUSC) Peripheral write protection status - Bridge C  Reset Value */

#define PAC_STATUSC_MLB_Pos                   _UINT32_(2)                                          /* (PAC_STATUSC) MLB APB Protect Enable Position */
#define PAC_STATUSC_MLB_Msk                   (_UINT32_(0x1) << PAC_STATUSC_MLB_Pos)               /* (PAC_STATUSC) MLB APB Protect Enable Mask */
#define PAC_STATUSC_MLB(value)                (PAC_STATUSC_MLB_Msk & (_UINT32_(value) << PAC_STATUSC_MLB_Pos)) /* Assigment of value for MLB in the PAC_STATUSC register */
#define PAC_STATUSC_Msk                       _UINT32_(0x00000004)                                 /* (PAC_STATUSC) Register Mask  */


/** \brief PAC register offsets definitions */
#define PAC_WRCTRL_REG_OFST            _UINT32_(0x00)      /* (PAC_WRCTRL) Write control Offset */
#define PAC_EVCTRL_REG_OFST            _UINT32_(0x04)      /* (PAC_EVCTRL) Event control Offset */
#define PAC_INTENCLR_REG_OFST          _UINT32_(0x08)      /* (PAC_INTENCLR) Interrupt enable clear Offset */
#define PAC_INTENSET_REG_OFST          _UINT32_(0x09)      /* (PAC_INTENSET) Interrupt enable set Offset */
#define PAC_INTFLAGAHB_REG_OFST        _UINT32_(0x10)      /* (PAC_INTFLAGAHB) Bridge interrupt flag status Offset */
#define PAC_INTFLAGA_REG_OFST          _UINT32_(0x14)      /* (PAC_INTFLAGA) Peripheral interrupt flag status - Bridge A Offset */
#define PAC_INTFLAGB_REG_OFST          _UINT32_(0x18)      /* (PAC_INTFLAGB) Peripheral interrupt flag status - Bridge B Offset */
#define PAC_INTFLAGC_REG_OFST          _UINT32_(0x1C)      /* (PAC_INTFLAGC) Peripheral interrupt flag status - Bridge C Offset */
#define PAC_STATUSA_REG_OFST           _UINT32_(0x34)      /* (PAC_STATUSA) Peripheral write protection status - Bridge A Offset */
#define PAC_STATUSB_REG_OFST           _UINT32_(0x38)      /* (PAC_STATUSB) Peripheral write protection status - Bridge B Offset */
#define PAC_STATUSC_REG_OFST           _UINT32_(0x3C)      /* (PAC_STATUSC) Peripheral write protection status - Bridge C Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief PAC register API structure */
typedef struct
{  /* Peripheral Access Controller */
  __IO  uint32_t                       PAC_WRCTRL;         /**< Offset: 0x00 (R/W  32) Write control */
  __IO  uint8_t                        PAC_EVCTRL;         /**< Offset: 0x04 (R/W  8) Event control */
  __I   uint8_t                        Reserved1[0x03];
  __IO  uint8_t                        PAC_INTENCLR;       /**< Offset: 0x08 (R/W  8) Interrupt enable clear */
  __IO  uint8_t                        PAC_INTENSET;       /**< Offset: 0x09 (R/W  8) Interrupt enable set */
  __I   uint8_t                        Reserved2[0x06];
  __IO  uint32_t                       PAC_INTFLAGAHB;     /**< Offset: 0x10 (R/W  32) Bridge interrupt flag status */
  __IO  uint32_t                       PAC_INTFLAGA;       /**< Offset: 0x14 (R/W  32) Peripheral interrupt flag status - Bridge A */
  __IO  uint32_t                       PAC_INTFLAGB;       /**< Offset: 0x18 (R/W  32) Peripheral interrupt flag status - Bridge B */
  __IO  uint32_t                       PAC_INTFLAGC;       /**< Offset: 0x1C (R/W  32) Peripheral interrupt flag status - Bridge C */
  __I   uint8_t                        Reserved3[0x14];
  __I   uint32_t                       PAC_STATUSA;        /**< Offset: 0x34 (R/   32) Peripheral write protection status - Bridge A */
  __I   uint32_t                       PAC_STATUSB;        /**< Offset: 0x38 (R/   32) Peripheral write protection status - Bridge B */
  __I   uint32_t                       PAC_STATUSC;        /**< Offset: 0x3C (R/   32) Peripheral write protection status - Bridge C */
} pac_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA80_PAC_COMPONENT_H_ */
