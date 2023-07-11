/*
 * Component description for LCDC
 *
 * Copyright (c) 2023 Microchip Technology Inc. and its subsidiaries.
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

/* file generated from device description version 2023-01-20T08:33:42Z */
#ifndef _SAM9X7_LCDC_COMPONENT_H_
#define _SAM9X7_LCDC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR LCDC                                         */
/* ************************************************************************** */

/* -------- LCDC_HEOYFBA : (LCDC Offset: 0x00) (R/W 32) High-End Overlay Y Frame Buffer x Addr -------- */
#define LCDC_HEOYFBA_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_HEOYFBA) High-End Overlay Y Frame Buffer x Addr  Reset Value */

#define LCDC_HEOYFBA_FBA_Pos                  _UINT32_(0)                                          /* (LCDC_HEOYFBA) Frame Buffer Address Position */
#define LCDC_HEOYFBA_FBA_Msk                  (_UINT32_(0xFFFFFFFF) << LCDC_HEOYFBA_FBA_Pos)       /* (LCDC_HEOYFBA) Frame Buffer Address Mask */
#define LCDC_HEOYFBA_FBA(value)               (LCDC_HEOYFBA_FBA_Msk & (_UINT32_(value) << LCDC_HEOYFBA_FBA_Pos)) /* Assigment of value for FBA in the LCDC_HEOYFBA register */
#define LCDC_HEOYFBA_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (LCDC_HEOYFBA) Register Mask  */


/* -------- LCDC_HEOCBFBA : (LCDC Offset: 0x04) (R/W 32) High-End Overlay Cb Frame Buffer x Addr -------- */
#define LCDC_HEOCBFBA_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_HEOCBFBA) High-End Overlay Cb Frame Buffer x Addr  Reset Value */

#define LCDC_HEOCBFBA_CBFBA_Pos               _UINT32_(0)                                          /* (LCDC_HEOCBFBA) Cb or CbCr Plane Frame Buffer Address Position */
#define LCDC_HEOCBFBA_CBFBA_Msk               (_UINT32_(0xFFFFFFFF) << LCDC_HEOCBFBA_CBFBA_Pos)    /* (LCDC_HEOCBFBA) Cb or CbCr Plane Frame Buffer Address Mask */
#define LCDC_HEOCBFBA_CBFBA(value)            (LCDC_HEOCBFBA_CBFBA_Msk & (_UINT32_(value) << LCDC_HEOCBFBA_CBFBA_Pos)) /* Assigment of value for CBFBA in the LCDC_HEOCBFBA register */
#define LCDC_HEOCBFBA_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (LCDC_HEOCBFBA) Register Mask  */


/* -------- LCDC_HEOCRFBA : (LCDC Offset: 0x08) (R/W 32) High-End Overlay Cr Frame Buffer x Addr -------- */
#define LCDC_HEOCRFBA_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_HEOCRFBA) High-End Overlay Cr Frame Buffer x Addr  Reset Value */

#define LCDC_HEOCRFBA_CRFBA_Pos               _UINT32_(0)                                          /* (LCDC_HEOCRFBA) Cr Chroma Plane Frame Buffer Address Position */
#define LCDC_HEOCRFBA_CRFBA_Msk               (_UINT32_(0xFFFFFFFF) << LCDC_HEOCRFBA_CRFBA_Pos)    /* (LCDC_HEOCRFBA) Cr Chroma Plane Frame Buffer Address Mask */
#define LCDC_HEOCRFBA_CRFBA(value)            (LCDC_HEOCRFBA_CRFBA_Msk & (_UINT32_(value) << LCDC_HEOCRFBA_CRFBA_Pos)) /* Assigment of value for CRFBA in the LCDC_HEOCRFBA register */
#define LCDC_HEOCRFBA_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (LCDC_HEOCRFBA) Register Mask  */


/* -------- LCDC_HEOHTAP10P : (LCDC Offset: 0x00) (R/W 32) High-End Overlay HXS T10 Phi Register  -------- */
#define LCDC_HEOHTAP10P_RESETVALUE            _UINT32_(0x00)                                       /*  (LCDC_HEOHTAP10P) High-End Overlay HXS T10 Phi Register   Reset Value */

#define LCDC_HEOHTAP10P_TAP0_Pos              _UINT32_(0)                                          /* (LCDC_HEOHTAP10P) Horizontal Filter Tap 0 Coefficient Position */
#define LCDC_HEOHTAP10P_TAP0_Msk              (_UINT32_(0x1FFF) << LCDC_HEOHTAP10P_TAP0_Pos)       /* (LCDC_HEOHTAP10P) Horizontal Filter Tap 0 Coefficient Mask */
#define LCDC_HEOHTAP10P_TAP0(value)           (LCDC_HEOHTAP10P_TAP0_Msk & (_UINT32_(value) << LCDC_HEOHTAP10P_TAP0_Pos)) /* Assigment of value for TAP0 in the LCDC_HEOHTAP10P register */
#define LCDC_HEOHTAP10P_TAP1_Pos              _UINT32_(16)                                         /* (LCDC_HEOHTAP10P) Horitzontal Filter Tap 1 Coefficient Position */
#define LCDC_HEOHTAP10P_TAP1_Msk              (_UINT32_(0x1FFF) << LCDC_HEOHTAP10P_TAP1_Pos)       /* (LCDC_HEOHTAP10P) Horitzontal Filter Tap 1 Coefficient Mask */
#define LCDC_HEOHTAP10P_TAP1(value)           (LCDC_HEOHTAP10P_TAP1_Msk & (_UINT32_(value) << LCDC_HEOHTAP10P_TAP1_Pos)) /* Assigment of value for TAP1 in the LCDC_HEOHTAP10P register */
#define LCDC_HEOHTAP10P_Msk                   _UINT32_(0x1FFF1FFF)                                 /* (LCDC_HEOHTAP10P) Register Mask  */


/* -------- LCDC_HEOHTAP32P : (LCDC Offset: 0x04) (R/W 32) High-End Overlay HXS T32 Phi Register  -------- */
#define LCDC_HEOHTAP32P_RESETVALUE            _UINT32_(0x00)                                       /*  (LCDC_HEOHTAP32P) High-End Overlay HXS T32 Phi Register   Reset Value */

#define LCDC_HEOHTAP32P_TAP2_Pos              _UINT32_(0)                                          /* (LCDC_HEOHTAP32P) Horizontal Filter Tap 2 Coefficient Position */
#define LCDC_HEOHTAP32P_TAP2_Msk              (_UINT32_(0x1FFF) << LCDC_HEOHTAP32P_TAP2_Pos)       /* (LCDC_HEOHTAP32P) Horizontal Filter Tap 2 Coefficient Mask */
#define LCDC_HEOHTAP32P_TAP2(value)           (LCDC_HEOHTAP32P_TAP2_Msk & (_UINT32_(value) << LCDC_HEOHTAP32P_TAP2_Pos)) /* Assigment of value for TAP2 in the LCDC_HEOHTAP32P register */
#define LCDC_HEOHTAP32P_TAP3_Pos              _UINT32_(16)                                         /* (LCDC_HEOHTAP32P) Horizontal Filter Tap 3 Coefficient Position */
#define LCDC_HEOHTAP32P_TAP3_Msk              (_UINT32_(0x1FFF) << LCDC_HEOHTAP32P_TAP3_Pos)       /* (LCDC_HEOHTAP32P) Horizontal Filter Tap 3 Coefficient Mask */
#define LCDC_HEOHTAP32P_TAP3(value)           (LCDC_HEOHTAP32P_TAP3_Msk & (_UINT32_(value) << LCDC_HEOHTAP32P_TAP3_Pos)) /* Assigment of value for TAP3 in the LCDC_HEOHTAP32P register */
#define LCDC_HEOHTAP32P_Msk                   _UINT32_(0x1FFF1FFF)                                 /* (LCDC_HEOHTAP32P) Register Mask  */


/* -------- LCDC_HEOVTAP10P : (LCDC Offset: 0x00) (R/W 32) High-End Overlay VXS T10 Phi Register  -------- */
#define LCDC_HEOVTAP10P_RESETVALUE            _UINT32_(0x00)                                       /*  (LCDC_HEOVTAP10P) High-End Overlay VXS T10 Phi Register   Reset Value */

#define LCDC_HEOVTAP10P_TAP0_Pos              _UINT32_(0)                                          /* (LCDC_HEOVTAP10P) Vertical Filter Tap 0 Coefficient Position */
#define LCDC_HEOVTAP10P_TAP0_Msk              (_UINT32_(0x1FFF) << LCDC_HEOVTAP10P_TAP0_Pos)       /* (LCDC_HEOVTAP10P) Vertical Filter Tap 0 Coefficient Mask */
#define LCDC_HEOVTAP10P_TAP0(value)           (LCDC_HEOVTAP10P_TAP0_Msk & (_UINT32_(value) << LCDC_HEOVTAP10P_TAP0_Pos)) /* Assigment of value for TAP0 in the LCDC_HEOVTAP10P register */
#define LCDC_HEOVTAP10P_TAP1_Pos              _UINT32_(16)                                         /* (LCDC_HEOVTAP10P) Vertical Filter Tap 1 Coefficient Position */
#define LCDC_HEOVTAP10P_TAP1_Msk              (_UINT32_(0x1FFF) << LCDC_HEOVTAP10P_TAP1_Pos)       /* (LCDC_HEOVTAP10P) Vertical Filter Tap 1 Coefficient Mask */
#define LCDC_HEOVTAP10P_TAP1(value)           (LCDC_HEOVTAP10P_TAP1_Msk & (_UINT32_(value) << LCDC_HEOVTAP10P_TAP1_Pos)) /* Assigment of value for TAP1 in the LCDC_HEOVTAP10P register */
#define LCDC_HEOVTAP10P_Msk                   _UINT32_(0x1FFF1FFF)                                 /* (LCDC_HEOVTAP10P) Register Mask  */


/* -------- LCDC_HEOVTAP32P : (LCDC Offset: 0x04) (R/W 32) High-End Overlay VXS T32 Phi Register  -------- */
#define LCDC_HEOVTAP32P_RESETVALUE            _UINT32_(0x00)                                       /*  (LCDC_HEOVTAP32P) High-End Overlay VXS T32 Phi Register   Reset Value */

#define LCDC_HEOVTAP32P_TAP2_Pos              _UINT32_(0)                                          /* (LCDC_HEOVTAP32P) Vertical Filter Tap 2 Coefficient Position */
#define LCDC_HEOVTAP32P_TAP2_Msk              (_UINT32_(0x1FFF) << LCDC_HEOVTAP32P_TAP2_Pos)       /* (LCDC_HEOVTAP32P) Vertical Filter Tap 2 Coefficient Mask */
#define LCDC_HEOVTAP32P_TAP2(value)           (LCDC_HEOVTAP32P_TAP2_Msk & (_UINT32_(value) << LCDC_HEOVTAP32P_TAP2_Pos)) /* Assigment of value for TAP2 in the LCDC_HEOVTAP32P register */
#define LCDC_HEOVTAP32P_TAP3_Pos              _UINT32_(16)                                         /* (LCDC_HEOVTAP32P) Vertical Filter Tap 3 Coefficient Position */
#define LCDC_HEOVTAP32P_TAP3_Msk              (_UINT32_(0x1FFF) << LCDC_HEOVTAP32P_TAP3_Pos)       /* (LCDC_HEOVTAP32P) Vertical Filter Tap 3 Coefficient Mask */
#define LCDC_HEOVTAP32P_TAP3(value)           (LCDC_HEOVTAP32P_TAP3_Msk & (_UINT32_(value) << LCDC_HEOVTAP32P_TAP3_Pos)) /* Assigment of value for TAP3 in the LCDC_HEOVTAP32P register */
#define LCDC_HEOVTAP32P_Msk                   _UINT32_(0x1FFF1FFF)                                 /* (LCDC_HEOVTAP32P) Register Mask  */


/* -------- LCDC_LCDCFG0 : (LCDC Offset: 0x00) (R/W 32) Configuration Register 0 -------- */
#define LCDC_LCDCFG0_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_LCDCFG0) Configuration Register 0  Reset Value */

#define LCDC_LCDCFG0_CLKPOL_Pos               _UINT32_(0)                                          /* (LCDC_LCDCFG0) LCDC Clock Polarity Position */
#define LCDC_LCDCFG0_CLKPOL_Msk               (_UINT32_(0x1) << LCDC_LCDCFG0_CLKPOL_Pos)           /* (LCDC_LCDCFG0) LCDC Clock Polarity Mask */
#define LCDC_LCDCFG0_CLKPOL(value)            (LCDC_LCDCFG0_CLKPOL_Msk & (_UINT32_(value) << LCDC_LCDCFG0_CLKPOL_Pos)) /* Assigment of value for CLKPOL in the LCDC_LCDCFG0 register */
#define   LCDC_LCDCFG0_CLKPOL_0_Val           _UINT32_(0x0)                                        /* (LCDC_LCDCFG0) Data/Control signals are launched on the rising edge of the pixel clock.  */
#define   LCDC_LCDCFG0_CLKPOL_1_Val           _UINT32_(0x1)                                        /* (LCDC_LCDCFG0) Data/Control signals are launched on the falling edge of the pixel clock.  */
#define LCDC_LCDCFG0_CLKPOL_0                 (LCDC_LCDCFG0_CLKPOL_0_Val << LCDC_LCDCFG0_CLKPOL_Pos) /* (LCDC_LCDCFG0) Data/Control signals are launched on the rising edge of the pixel clock. Position  */
#define LCDC_LCDCFG0_CLKPOL_1                 (LCDC_LCDCFG0_CLKPOL_1_Val << LCDC_LCDCFG0_CLKPOL_Pos) /* (LCDC_LCDCFG0) Data/Control signals are launched on the falling edge of the pixel clock. Position  */
#define LCDC_LCDCFG0_CLKBYP_Pos               _UINT32_(1)                                          /* (LCDC_LCDCFG0) LCDC Pixel Clock Divider Bypass Position */
#define LCDC_LCDCFG0_CLKBYP_Msk               (_UINT32_(0x1) << LCDC_LCDCFG0_CLKBYP_Pos)           /* (LCDC_LCDCFG0) LCDC Pixel Clock Divider Bypass Mask */
#define LCDC_LCDCFG0_CLKBYP(value)            (LCDC_LCDCFG0_CLKBYP_Msk & (_UINT32_(value) << LCDC_LCDCFG0_CLKBYP_Pos)) /* Assigment of value for CLKBYP in the LCDC_LCDCFG0 register */
#define   LCDC_LCDCFG0_CLKBYP_0_Val           _UINT32_(0x0)                                        /* (LCDC_LCDCFG0) Pixel clock divider is not bypassed. LCDC_PCK is defined with CLKDIV parameter.  */
#define   LCDC_LCDCFG0_CLKBYP_1_Val           _UINT32_(0x1)                                        /* (LCDC_LCDCFG0) Pixel clock divider is bypassed. LCDC_PCK = GCLK clock  */
#define LCDC_LCDCFG0_CLKBYP_0                 (LCDC_LCDCFG0_CLKBYP_0_Val << LCDC_LCDCFG0_CLKBYP_Pos) /* (LCDC_LCDCFG0) Pixel clock divider is not bypassed. LCDC_PCK is defined with CLKDIV parameter. Position  */
#define LCDC_LCDCFG0_CLKBYP_1                 (LCDC_LCDCFG0_CLKBYP_1_Val << LCDC_LCDCFG0_CLKBYP_Pos) /* (LCDC_LCDCFG0) Pixel clock divider is bypassed. LCDC_PCK = GCLK clock Position  */
#define LCDC_LCDCFG0_CLKPWMSEL_Pos            _UINT32_(3)                                          /* (LCDC_LCDCFG0) LCDC PWM Clock Source Selection Position */
#define LCDC_LCDCFG0_CLKPWMSEL_Msk            (_UINT32_(0x1) << LCDC_LCDCFG0_CLKPWMSEL_Pos)        /* (LCDC_LCDCFG0) LCDC PWM Clock Source Selection Mask */
#define LCDC_LCDCFG0_CLKPWMSEL(value)         (LCDC_LCDCFG0_CLKPWMSEL_Msk & (_UINT32_(value) << LCDC_LCDCFG0_CLKPWMSEL_Pos)) /* Assigment of value for CLKPWMSEL in the LCDC_LCDCFG0 register */
#define   LCDC_LCDCFG0_CLKPWMSEL_0_Val        _UINT32_(0x0)                                        /* (LCDC_LCDCFG0) The slow clock is selected and feeds the PWM module.  */
#define   LCDC_LCDCFG0_CLKPWMSEL_1_Val        _UINT32_(0x1)                                        /* (LCDC_LCDCFG0) The system clock is selected and feeds the PWM module.  */
#define LCDC_LCDCFG0_CLKPWMSEL_0              (LCDC_LCDCFG0_CLKPWMSEL_0_Val << LCDC_LCDCFG0_CLKPWMSEL_Pos) /* (LCDC_LCDCFG0) The slow clock is selected and feeds the PWM module. Position  */
#define LCDC_LCDCFG0_CLKPWMSEL_1              (LCDC_LCDCFG0_CLKPWMSEL_1_Val << LCDC_LCDCFG0_CLKPWMSEL_Pos) /* (LCDC_LCDCFG0) The system clock is selected and feeds the PWM module. Position  */
#define LCDC_LCDCFG0_CLKDIV_Pos               _UINT32_(16)                                         /* (LCDC_LCDCFG0) LCDC Clock Divider Position */
#define LCDC_LCDCFG0_CLKDIV_Msk               (_UINT32_(0xFF) << LCDC_LCDCFG0_CLKDIV_Pos)          /* (LCDC_LCDCFG0) LCDC Clock Divider Mask */
#define LCDC_LCDCFG0_CLKDIV(value)            (LCDC_LCDCFG0_CLKDIV_Msk & (_UINT32_(value) << LCDC_LCDCFG0_CLKDIV_Pos)) /* Assigment of value for CLKDIV in the LCDC_LCDCFG0 register */
#define LCDC_LCDCFG0_Msk                      _UINT32_(0x00FF000B)                                 /* (LCDC_LCDCFG0) Register Mask  */


/* -------- LCDC_LCDCFG1 : (LCDC Offset: 0x04) (R/W 32) Configuration Register 1 -------- */
#define LCDC_LCDCFG1_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_LCDCFG1) Configuration Register 1  Reset Value */

#define LCDC_LCDCFG1_HSPW_Pos                 _UINT32_(0)                                          /* (LCDC_LCDCFG1) Horizontal Synchronization Pulse Width Position */
#define LCDC_LCDCFG1_HSPW_Msk                 (_UINT32_(0x3FF) << LCDC_LCDCFG1_HSPW_Pos)           /* (LCDC_LCDCFG1) Horizontal Synchronization Pulse Width Mask */
#define LCDC_LCDCFG1_HSPW(value)              (LCDC_LCDCFG1_HSPW_Msk & (_UINT32_(value) << LCDC_LCDCFG1_HSPW_Pos)) /* Assigment of value for HSPW in the LCDC_LCDCFG1 register */
#define LCDC_LCDCFG1_VSPW_Pos                 _UINT32_(16)                                         /* (LCDC_LCDCFG1) Vertical Synchronization Pulse Width Position */
#define LCDC_LCDCFG1_VSPW_Msk                 (_UINT32_(0x3FF) << LCDC_LCDCFG1_VSPW_Pos)           /* (LCDC_LCDCFG1) Vertical Synchronization Pulse Width Mask */
#define LCDC_LCDCFG1_VSPW(value)              (LCDC_LCDCFG1_VSPW_Msk & (_UINT32_(value) << LCDC_LCDCFG1_VSPW_Pos)) /* Assigment of value for VSPW in the LCDC_LCDCFG1 register */
#define LCDC_LCDCFG1_Msk                      _UINT32_(0x03FF03FF)                                 /* (LCDC_LCDCFG1) Register Mask  */


/* -------- LCDC_LCDCFG2 : (LCDC Offset: 0x08) (R/W 32) Configuration Register 2 -------- */
#define LCDC_LCDCFG2_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_LCDCFG2) Configuration Register 2  Reset Value */

#define LCDC_LCDCFG2_VFPW_Pos                 _UINT32_(0)                                          /* (LCDC_LCDCFG2) Vertical Front Porch Width Position */
#define LCDC_LCDCFG2_VFPW_Msk                 (_UINT32_(0x3FF) << LCDC_LCDCFG2_VFPW_Pos)           /* (LCDC_LCDCFG2) Vertical Front Porch Width Mask */
#define LCDC_LCDCFG2_VFPW(value)              (LCDC_LCDCFG2_VFPW_Msk & (_UINT32_(value) << LCDC_LCDCFG2_VFPW_Pos)) /* Assigment of value for VFPW in the LCDC_LCDCFG2 register */
#define LCDC_LCDCFG2_VBPW_Pos                 _UINT32_(16)                                         /* (LCDC_LCDCFG2) Vertical Back Porch Width Position */
#define LCDC_LCDCFG2_VBPW_Msk                 (_UINT32_(0x3FF) << LCDC_LCDCFG2_VBPW_Pos)           /* (LCDC_LCDCFG2) Vertical Back Porch Width Mask */
#define LCDC_LCDCFG2_VBPW(value)              (LCDC_LCDCFG2_VBPW_Msk & (_UINT32_(value) << LCDC_LCDCFG2_VBPW_Pos)) /* Assigment of value for VBPW in the LCDC_LCDCFG2 register */
#define LCDC_LCDCFG2_Msk                      _UINT32_(0x03FF03FF)                                 /* (LCDC_LCDCFG2) Register Mask  */


/* -------- LCDC_LCDCFG3 : (LCDC Offset: 0x0C) (R/W 32) Configuration Register 3 -------- */
#define LCDC_LCDCFG3_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_LCDCFG3) Configuration Register 3  Reset Value */

#define LCDC_LCDCFG3_HFPW_Pos                 _UINT32_(0)                                          /* (LCDC_LCDCFG3) Horizontal Front Porch Width Position */
#define LCDC_LCDCFG3_HFPW_Msk                 (_UINT32_(0x3FF) << LCDC_LCDCFG3_HFPW_Pos)           /* (LCDC_LCDCFG3) Horizontal Front Porch Width Mask */
#define LCDC_LCDCFG3_HFPW(value)              (LCDC_LCDCFG3_HFPW_Msk & (_UINT32_(value) << LCDC_LCDCFG3_HFPW_Pos)) /* Assigment of value for HFPW in the LCDC_LCDCFG3 register */
#define LCDC_LCDCFG3_HBPW_Pos                 _UINT32_(16)                                         /* (LCDC_LCDCFG3) Horizontal Back Porch Width Position */
#define LCDC_LCDCFG3_HBPW_Msk                 (_UINT32_(0x3FF) << LCDC_LCDCFG3_HBPW_Pos)           /* (LCDC_LCDCFG3) Horizontal Back Porch Width Mask */
#define LCDC_LCDCFG3_HBPW(value)              (LCDC_LCDCFG3_HBPW_Msk & (_UINT32_(value) << LCDC_LCDCFG3_HBPW_Pos)) /* Assigment of value for HBPW in the LCDC_LCDCFG3 register */
#define LCDC_LCDCFG3_Msk                      _UINT32_(0x03FF03FF)                                 /* (LCDC_LCDCFG3) Register Mask  */


/* -------- LCDC_LCDCFG4 : (LCDC Offset: 0x10) (R/W 32) Configuration Register 4 -------- */
#define LCDC_LCDCFG4_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_LCDCFG4) Configuration Register 4  Reset Value */

#define LCDC_LCDCFG4_PPL_Pos                  _UINT32_(0)                                          /* (LCDC_LCDCFG4) Number of Pixels Per Line Position */
#define LCDC_LCDCFG4_PPL_Msk                  (_UINT32_(0x7FF) << LCDC_LCDCFG4_PPL_Pos)            /* (LCDC_LCDCFG4) Number of Pixels Per Line Mask */
#define LCDC_LCDCFG4_PPL(value)               (LCDC_LCDCFG4_PPL_Msk & (_UINT32_(value) << LCDC_LCDCFG4_PPL_Pos)) /* Assigment of value for PPL in the LCDC_LCDCFG4 register */
#define LCDC_LCDCFG4_RPF_Pos                  _UINT32_(16)                                         /* (LCDC_LCDCFG4) Number of Active Row Per Frame Position */
#define LCDC_LCDCFG4_RPF_Msk                  (_UINT32_(0x7FF) << LCDC_LCDCFG4_RPF_Pos)            /* (LCDC_LCDCFG4) Number of Active Row Per Frame Mask */
#define LCDC_LCDCFG4_RPF(value)               (LCDC_LCDCFG4_RPF_Msk & (_UINT32_(value) << LCDC_LCDCFG4_RPF_Pos)) /* Assigment of value for RPF in the LCDC_LCDCFG4 register */
#define LCDC_LCDCFG4_Msk                      _UINT32_(0x07FF07FF)                                 /* (LCDC_LCDCFG4) Register Mask  */


/* -------- LCDC_LCDCFG5 : (LCDC Offset: 0x14) (R/W 32) Configuration Register 5 -------- */
#define LCDC_LCDCFG5_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_LCDCFG5) Configuration Register 5  Reset Value */

#define LCDC_LCDCFG5_HSPOL_Pos                _UINT32_(0)                                          /* (LCDC_LCDCFG5) Horizontal Synchronization Pulse Polarity Position */
#define LCDC_LCDCFG5_HSPOL_Msk                (_UINT32_(0x1) << LCDC_LCDCFG5_HSPOL_Pos)            /* (LCDC_LCDCFG5) Horizontal Synchronization Pulse Polarity Mask */
#define LCDC_LCDCFG5_HSPOL(value)             (LCDC_LCDCFG5_HSPOL_Msk & (_UINT32_(value) << LCDC_LCDCFG5_HSPOL_Pos)) /* Assigment of value for HSPOL in the LCDC_LCDCFG5 register */
#define   LCDC_LCDCFG5_HSPOL_0_Val            _UINT32_(0x0)                                        /* (LCDC_LCDCFG5) Active high.  */
#define   LCDC_LCDCFG5_HSPOL_1_Val            _UINT32_(0x1)                                        /* (LCDC_LCDCFG5) Active low.  */
#define LCDC_LCDCFG5_HSPOL_0                  (LCDC_LCDCFG5_HSPOL_0_Val << LCDC_LCDCFG5_HSPOL_Pos) /* (LCDC_LCDCFG5) Active high. Position  */
#define LCDC_LCDCFG5_HSPOL_1                  (LCDC_LCDCFG5_HSPOL_1_Val << LCDC_LCDCFG5_HSPOL_Pos) /* (LCDC_LCDCFG5) Active low. Position  */
#define LCDC_LCDCFG5_VSPOL_Pos                _UINT32_(1)                                          /* (LCDC_LCDCFG5) Vertical Synchronization Pulse Polarity Position */
#define LCDC_LCDCFG5_VSPOL_Msk                (_UINT32_(0x1) << LCDC_LCDCFG5_VSPOL_Pos)            /* (LCDC_LCDCFG5) Vertical Synchronization Pulse Polarity Mask */
#define LCDC_LCDCFG5_VSPOL(value)             (LCDC_LCDCFG5_VSPOL_Msk & (_UINT32_(value) << LCDC_LCDCFG5_VSPOL_Pos)) /* Assigment of value for VSPOL in the LCDC_LCDCFG5 register */
#define   LCDC_LCDCFG5_VSPOL_0_Val            _UINT32_(0x0)                                        /* (LCDC_LCDCFG5) Active high.  */
#define   LCDC_LCDCFG5_VSPOL_1_Val            _UINT32_(0x1)                                        /* (LCDC_LCDCFG5) Active low.  */
#define LCDC_LCDCFG5_VSPOL_0                  (LCDC_LCDCFG5_VSPOL_0_Val << LCDC_LCDCFG5_VSPOL_Pos) /* (LCDC_LCDCFG5) Active high. Position  */
#define LCDC_LCDCFG5_VSPOL_1                  (LCDC_LCDCFG5_VSPOL_1_Val << LCDC_LCDCFG5_VSPOL_Pos) /* (LCDC_LCDCFG5) Active low. Position  */
#define LCDC_LCDCFG5_VSPDLYS_Pos              _UINT32_(2)                                          /* (LCDC_LCDCFG5) Vertical Synchronization Pulse Start Position */
#define LCDC_LCDCFG5_VSPDLYS_Msk              (_UINT32_(0x1) << LCDC_LCDCFG5_VSPDLYS_Pos)          /* (LCDC_LCDCFG5) Vertical Synchronization Pulse Start Mask */
#define LCDC_LCDCFG5_VSPDLYS(value)           (LCDC_LCDCFG5_VSPDLYS_Msk & (_UINT32_(value) << LCDC_LCDCFG5_VSPDLYS_Pos)) /* Assigment of value for VSPDLYS in the LCDC_LCDCFG5 register */
#define   LCDC_LCDCFG5_VSPDLYS_0_Val          _UINT32_(0x0)                                        /* (LCDC_LCDCFG5) The first active edge of the vertical synchronization pulse is synchronous with the second edge of the horizontal pulse.  */
#define   LCDC_LCDCFG5_VSPDLYS_1_Val          _UINT32_(0x1)                                        /* (LCDC_LCDCFG5) The first active edge of the vertical synchronization pulse is synchronous with the first edge of the horizontal pulse.  */
#define LCDC_LCDCFG5_VSPDLYS_0                (LCDC_LCDCFG5_VSPDLYS_0_Val << LCDC_LCDCFG5_VSPDLYS_Pos) /* (LCDC_LCDCFG5) The first active edge of the vertical synchronization pulse is synchronous with the second edge of the horizontal pulse. Position  */
#define LCDC_LCDCFG5_VSPDLYS_1                (LCDC_LCDCFG5_VSPDLYS_1_Val << LCDC_LCDCFG5_VSPDLYS_Pos) /* (LCDC_LCDCFG5) The first active edge of the vertical synchronization pulse is synchronous with the first edge of the horizontal pulse. Position  */
#define LCDC_LCDCFG5_VSPDLYE_Pos              _UINT32_(3)                                          /* (LCDC_LCDCFG5) Vertical Synchronization Pulse End Position */
#define LCDC_LCDCFG5_VSPDLYE_Msk              (_UINT32_(0x1) << LCDC_LCDCFG5_VSPDLYE_Pos)          /* (LCDC_LCDCFG5) Vertical Synchronization Pulse End Mask */
#define LCDC_LCDCFG5_VSPDLYE(value)           (LCDC_LCDCFG5_VSPDLYE_Msk & (_UINT32_(value) << LCDC_LCDCFG5_VSPDLYE_Pos)) /* Assigment of value for VSPDLYE in the LCDC_LCDCFG5 register */
#define   LCDC_LCDCFG5_VSPDLYE_0_Val          _UINT32_(0x0)                                        /* (LCDC_LCDCFG5) The second active edge of the vertical synchronization pulse is synchronous with the second edge of the horizontal pulse.  */
#define   LCDC_LCDCFG5_VSPDLYE_1_Val          _UINT32_(0x1)                                        /* (LCDC_LCDCFG5) The second active edge of the vertical synchronization pulse is synchronous with the first edge of the horizontal pulse.  */
#define LCDC_LCDCFG5_VSPDLYE_0                (LCDC_LCDCFG5_VSPDLYE_0_Val << LCDC_LCDCFG5_VSPDLYE_Pos) /* (LCDC_LCDCFG5) The second active edge of the vertical synchronization pulse is synchronous with the second edge of the horizontal pulse. Position  */
#define LCDC_LCDCFG5_VSPDLYE_1                (LCDC_LCDCFG5_VSPDLYE_1_Val << LCDC_LCDCFG5_VSPDLYE_Pos) /* (LCDC_LCDCFG5) The second active edge of the vertical synchronization pulse is synchronous with the first edge of the horizontal pulse. Position  */
#define LCDC_LCDCFG5_DISPPOL_Pos              _UINT32_(4)                                          /* (LCDC_LCDCFG5) Display Signal Polarity Position */
#define LCDC_LCDCFG5_DISPPOL_Msk              (_UINT32_(0x1) << LCDC_LCDCFG5_DISPPOL_Pos)          /* (LCDC_LCDCFG5) Display Signal Polarity Mask */
#define LCDC_LCDCFG5_DISPPOL(value)           (LCDC_LCDCFG5_DISPPOL_Msk & (_UINT32_(value) << LCDC_LCDCFG5_DISPPOL_Pos)) /* Assigment of value for DISPPOL in the LCDC_LCDCFG5 register */
#define   LCDC_LCDCFG5_DISPPOL_0_Val          _UINT32_(0x0)                                        /* (LCDC_LCDCFG5) Active high.  */
#define   LCDC_LCDCFG5_DISPPOL_1_Val          _UINT32_(0x1)                                        /* (LCDC_LCDCFG5) Active low.  */
#define LCDC_LCDCFG5_DISPPOL_0                (LCDC_LCDCFG5_DISPPOL_0_Val << LCDC_LCDCFG5_DISPPOL_Pos) /* (LCDC_LCDCFG5) Active high. Position  */
#define LCDC_LCDCFG5_DISPPOL_1                (LCDC_LCDCFG5_DISPPOL_1_Val << LCDC_LCDCFG5_DISPPOL_Pos) /* (LCDC_LCDCFG5) Active low. Position  */
#define LCDC_LCDCFG5_DITHER_Pos               _UINT32_(6)                                          /* (LCDC_LCDCFG5) LCDC Dithering Position */
#define LCDC_LCDCFG5_DITHER_Msk               (_UINT32_(0x1) << LCDC_LCDCFG5_DITHER_Pos)           /* (LCDC_LCDCFG5) LCDC Dithering Mask */
#define LCDC_LCDCFG5_DITHER(value)            (LCDC_LCDCFG5_DITHER_Msk & (_UINT32_(value) << LCDC_LCDCFG5_DITHER_Pos)) /* Assigment of value for DITHER in the LCDC_LCDCFG5 register */
#define   LCDC_LCDCFG5_DITHER_0_Val           _UINT32_(0x0)                                        /* (LCDC_LCDCFG5) Dithering logical unit is disabled.  */
#define   LCDC_LCDCFG5_DITHER_1_Val           _UINT32_(0x1)                                        /* (LCDC_LCDCFG5) Dithering logical unit is activated.  */
#define LCDC_LCDCFG5_DITHER_0                 (LCDC_LCDCFG5_DITHER_0_Val << LCDC_LCDCFG5_DITHER_Pos) /* (LCDC_LCDCFG5) Dithering logical unit is disabled. Position  */
#define LCDC_LCDCFG5_DITHER_1                 (LCDC_LCDCFG5_DITHER_1_Val << LCDC_LCDCFG5_DITHER_Pos) /* (LCDC_LCDCFG5) Dithering logical unit is activated. Position  */
#define LCDC_LCDCFG5_DISPDLY_Pos              _UINT32_(7)                                          /* (LCDC_LCDCFG5) LCDC Display Power Signal Synchronization Position */
#define LCDC_LCDCFG5_DISPDLY_Msk              (_UINT32_(0x1) << LCDC_LCDCFG5_DISPDLY_Pos)          /* (LCDC_LCDCFG5) LCDC Display Power Signal Synchronization Mask */
#define LCDC_LCDCFG5_DISPDLY(value)           (LCDC_LCDCFG5_DISPDLY_Msk & (_UINT32_(value) << LCDC_LCDCFG5_DISPDLY_Pos)) /* Assigment of value for DISPDLY in the LCDC_LCDCFG5 register */
#define   LCDC_LCDCFG5_DISPDLY_0_Val          _UINT32_(0x0)                                        /* (LCDC_LCDCFG5) The LCDC_DISP signal is asserted synchronously with the second active edge of the horizontal pulse.  */
#define   LCDC_LCDCFG5_DISPDLY_1_Val          _UINT32_(0x1)                                        /* (LCDC_LCDCFG5) The LCDC_DISP signal is asserted asynchronously with both edges of the horizontal pulse.  */
#define LCDC_LCDCFG5_DISPDLY_0                (LCDC_LCDCFG5_DISPDLY_0_Val << LCDC_LCDCFG5_DISPDLY_Pos) /* (LCDC_LCDCFG5) The LCDC_DISP signal is asserted synchronously with the second active edge of the horizontal pulse. Position  */
#define LCDC_LCDCFG5_DISPDLY_1                (LCDC_LCDCFG5_DISPDLY_1_Val << LCDC_LCDCFG5_DISPDLY_Pos) /* (LCDC_LCDCFG5) The LCDC_DISP signal is asserted asynchronously with both edges of the horizontal pulse. Position  */
#define LCDC_LCDCFG5_MODE_Pos                 _UINT32_(8)                                          /* (LCDC_LCDCFG5) LCDC Output Mode Position */
#define LCDC_LCDCFG5_MODE_Msk                 (_UINT32_(0x7) << LCDC_LCDCFG5_MODE_Pos)             /* (LCDC_LCDCFG5) LCDC Output Mode Mask */
#define LCDC_LCDCFG5_MODE(value)              (LCDC_LCDCFG5_MODE_Msk & (_UINT32_(value) << LCDC_LCDCFG5_MODE_Pos)) /* Assigment of value for MODE in the LCDC_LCDCFG5 register */
#define   LCDC_LCDCFG5_MODE_OUTPUT_12BPP_Val  _UINT32_(0x0)                                        /* (LCDC_LCDCFG5) LCD Output mode is set to 12 bits per pixel  */
#define   LCDC_LCDCFG5_MODE_OUTPUT_DPI_16BPPCFG1_Val _UINT32_(0x0)                                        /* (LCDC_LCDCFG5) LCD Output mode is set to 16 bits per pixel Configuration 1  */
#define   LCDC_LCDCFG5_MODE_OUTPUT_16BPP_Val  _UINT32_(0x1)                                        /* (LCDC_LCDCFG5) LCD Output mode is set to 16 bits per pixel  */
#define   LCDC_LCDCFG5_MODE_OUTPUT_DPI_16BPPCFG2_Val _UINT32_(0x1)                                        /* (LCDC_LCDCFG5) LCD Output mode is set to 16 bits per pixel Configuration 2  */
#define   LCDC_LCDCFG5_MODE_OUTPUT_18BPP_Val  _UINT32_(0x2)                                        /* (LCDC_LCDCFG5) LCD Output mode is set to 18 bits per pixel  */
#define   LCDC_LCDCFG5_MODE_OUTPUT_DPI_16BPPCFG3_Val _UINT32_(0x2)                                        /* (LCDC_LCDCFG5) LCD Output mode is set to 16 bits per pixel Configuration 3  */
#define   LCDC_LCDCFG5_MODE_OUTPUT_24BPP_Val  _UINT32_(0x3)                                        /* (LCDC_LCDCFG5) LCD Output mode is set to 24 bits per pixel  */
#define   LCDC_LCDCFG5_MODE_OUTPUT_DPI_18BPPCFG1_Val _UINT32_(0x3)                                        /* (LCDC_LCDCFG5) LCD Output mode is set to 18 bits per pixel Configuration 1  */
#define   LCDC_LCDCFG5_MODE_OUTPUT_DPI_18BPPCFG2_Val _UINT32_(0x4)                                        /* (LCDC_LCDCFG5) LCD Output mode is set to 18 bits per pixel Configuration 2  */
#define   LCDC_LCDCFG5_MODE_OUTPUT_DPI_24BPP_Val _UINT32_(0x5)                                        /* (LCDC_LCDCFG5) LCD Output mode is set to 24 bits per pixel  */
#define LCDC_LCDCFG5_MODE_OUTPUT_12BPP        (LCDC_LCDCFG5_MODE_OUTPUT_12BPP_Val << LCDC_LCDCFG5_MODE_Pos) /* (LCDC_LCDCFG5) LCD Output mode is set to 12 bits per pixel Position  */
#define LCDC_LCDCFG5_MODE_OUTPUT_DPI_16BPPCFG1 (LCDC_LCDCFG5_MODE_OUTPUT_DPI_16BPPCFG1_Val << LCDC_LCDCFG5_MODE_Pos) /* (LCDC_LCDCFG5) LCD Output mode is set to 16 bits per pixel Configuration 1 Position  */
#define LCDC_LCDCFG5_MODE_OUTPUT_16BPP        (LCDC_LCDCFG5_MODE_OUTPUT_16BPP_Val << LCDC_LCDCFG5_MODE_Pos) /* (LCDC_LCDCFG5) LCD Output mode is set to 16 bits per pixel Position  */
#define LCDC_LCDCFG5_MODE_OUTPUT_DPI_16BPPCFG2 (LCDC_LCDCFG5_MODE_OUTPUT_DPI_16BPPCFG2_Val << LCDC_LCDCFG5_MODE_Pos) /* (LCDC_LCDCFG5) LCD Output mode is set to 16 bits per pixel Configuration 2 Position  */
#define LCDC_LCDCFG5_MODE_OUTPUT_18BPP        (LCDC_LCDCFG5_MODE_OUTPUT_18BPP_Val << LCDC_LCDCFG5_MODE_Pos) /* (LCDC_LCDCFG5) LCD Output mode is set to 18 bits per pixel Position  */
#define LCDC_LCDCFG5_MODE_OUTPUT_DPI_16BPPCFG3 (LCDC_LCDCFG5_MODE_OUTPUT_DPI_16BPPCFG3_Val << LCDC_LCDCFG5_MODE_Pos) /* (LCDC_LCDCFG5) LCD Output mode is set to 16 bits per pixel Configuration 3 Position  */
#define LCDC_LCDCFG5_MODE_OUTPUT_24BPP        (LCDC_LCDCFG5_MODE_OUTPUT_24BPP_Val << LCDC_LCDCFG5_MODE_Pos) /* (LCDC_LCDCFG5) LCD Output mode is set to 24 bits per pixel Position  */
#define LCDC_LCDCFG5_MODE_OUTPUT_DPI_18BPPCFG1 (LCDC_LCDCFG5_MODE_OUTPUT_DPI_18BPPCFG1_Val << LCDC_LCDCFG5_MODE_Pos) /* (LCDC_LCDCFG5) LCD Output mode is set to 18 bits per pixel Configuration 1 Position  */
#define LCDC_LCDCFG5_MODE_OUTPUT_DPI_18BPPCFG2 (LCDC_LCDCFG5_MODE_OUTPUT_DPI_18BPPCFG2_Val << LCDC_LCDCFG5_MODE_Pos) /* (LCDC_LCDCFG5) LCD Output mode is set to 18 bits per pixel Configuration 2 Position  */
#define LCDC_LCDCFG5_MODE_OUTPUT_DPI_24BPP    (LCDC_LCDCFG5_MODE_OUTPUT_DPI_24BPP_Val << LCDC_LCDCFG5_MODE_Pos) /* (LCDC_LCDCFG5) LCD Output mode is set to 24 bits per pixel Position  */
#define LCDC_LCDCFG5_DPI_Pos                  _UINT32_(11)                                         /* (LCDC_LCDCFG5) Display Pixel Interface Compatible Mode Position */
#define LCDC_LCDCFG5_DPI_Msk                  (_UINT32_(0x1) << LCDC_LCDCFG5_DPI_Pos)              /* (LCDC_LCDCFG5) Display Pixel Interface Compatible Mode Mask */
#define LCDC_LCDCFG5_DPI(value)               (LCDC_LCDCFG5_DPI_Msk & (_UINT32_(value) << LCDC_LCDCFG5_DPI_Pos)) /* Assigment of value for DPI in the LCDC_LCDCFG5 register */
#define   LCDC_LCDCFG5_DPI_0_Val              _UINT32_(0x0)                                        /* (LCDC_LCDCFG5) Legacy pixel mapping.  */
#define   LCDC_LCDCFG5_DPI_1_Val              _UINT32_(0x1)                                        /* (LCDC_LCDCFG5) Activates the DPI compliant pixel stream. Refer to field MODE: LCDC Output Mode  */
#define LCDC_LCDCFG5_DPI_0                    (LCDC_LCDCFG5_DPI_0_Val << LCDC_LCDCFG5_DPI_Pos)     /* (LCDC_LCDCFG5) Legacy pixel mapping. Position  */
#define LCDC_LCDCFG5_DPI_1                    (LCDC_LCDCFG5_DPI_1_Val << LCDC_LCDCFG5_DPI_Pos)     /* (LCDC_LCDCFG5) Activates the DPI compliant pixel stream. Refer to field MODE: LCDC Output Mode Position  */
#define LCDC_LCDCFG5_VSPSU_Pos                _UINT32_(12)                                         /* (LCDC_LCDCFG5) LCDC Vertical Synchronization Pulse Setup Configuration Position */
#define LCDC_LCDCFG5_VSPSU_Msk                (_UINT32_(0x1) << LCDC_LCDCFG5_VSPSU_Pos)            /* (LCDC_LCDCFG5) LCDC Vertical Synchronization Pulse Setup Configuration Mask */
#define LCDC_LCDCFG5_VSPSU(value)             (LCDC_LCDCFG5_VSPSU_Msk & (_UINT32_(value) << LCDC_LCDCFG5_VSPSU_Pos)) /* Assigment of value for VSPSU in the LCDC_LCDCFG5 register */
#define   LCDC_LCDCFG5_VSPSU_0_Val            _UINT32_(0x0)                                        /* (LCDC_LCDCFG5) The vertical synchronization pulse is asserted synchronously with horizontal pulse edge.  */
#define   LCDC_LCDCFG5_VSPSU_1_Val            _UINT32_(0x1)                                        /* (LCDC_LCDCFG5) The vertical synchronization pulse is asserted one pixel clock cycle before the horizontal pulse.  */
#define LCDC_LCDCFG5_VSPSU_0                  (LCDC_LCDCFG5_VSPSU_0_Val << LCDC_LCDCFG5_VSPSU_Pos) /* (LCDC_LCDCFG5) The vertical synchronization pulse is asserted synchronously with horizontal pulse edge. Position  */
#define LCDC_LCDCFG5_VSPSU_1                  (LCDC_LCDCFG5_VSPSU_1_Val << LCDC_LCDCFG5_VSPSU_Pos) /* (LCDC_LCDCFG5) The vertical synchronization pulse is asserted one pixel clock cycle before the horizontal pulse. Position  */
#define LCDC_LCDCFG5_VSPHO_Pos                _UINT32_(13)                                         /* (LCDC_LCDCFG5) LCDC Vertical Synchronization Pulse Hold Configuration Position */
#define LCDC_LCDCFG5_VSPHO_Msk                (_UINT32_(0x1) << LCDC_LCDCFG5_VSPHO_Pos)            /* (LCDC_LCDCFG5) LCDC Vertical Synchronization Pulse Hold Configuration Mask */
#define LCDC_LCDCFG5_VSPHO(value)             (LCDC_LCDCFG5_VSPHO_Msk & (_UINT32_(value) << LCDC_LCDCFG5_VSPHO_Pos)) /* Assigment of value for VSPHO in the LCDC_LCDCFG5 register */
#define   LCDC_LCDCFG5_VSPHO_0_Val            _UINT32_(0x0)                                        /* (LCDC_LCDCFG5) The vertical synchronization pulse is asserted synchronously with horizontal pulse edge.  */
#define   LCDC_LCDCFG5_VSPHO_1_Val            _UINT32_(0x1)                                        /* (LCDC_LCDCFG5) The vertical synchronization pulse is held active one pixel clock cycle after the horizontal pulse.  */
#define LCDC_LCDCFG5_VSPHO_0                  (LCDC_LCDCFG5_VSPHO_0_Val << LCDC_LCDCFG5_VSPHO_Pos) /* (LCDC_LCDCFG5) The vertical synchronization pulse is asserted synchronously with horizontal pulse edge. Position  */
#define LCDC_LCDCFG5_VSPHO_1                  (LCDC_LCDCFG5_VSPHO_1_Val << LCDC_LCDCFG5_VSPHO_Pos) /* (LCDC_LCDCFG5) The vertical synchronization pulse is held active one pixel clock cycle after the horizontal pulse. Position  */
#define LCDC_LCDCFG5_GUARDTIME_Pos            _UINT32_(16)                                         /* (LCDC_LCDCFG5) LCD Display Guard Time Position */
#define LCDC_LCDCFG5_GUARDTIME_Msk            (_UINT32_(0xFF) << LCDC_LCDCFG5_GUARDTIME_Pos)       /* (LCDC_LCDCFG5) LCD Display Guard Time Mask */
#define LCDC_LCDCFG5_GUARDTIME(value)         (LCDC_LCDCFG5_GUARDTIME_Msk & (_UINT32_(value) << LCDC_LCDCFG5_GUARDTIME_Pos)) /* Assigment of value for GUARDTIME in the LCDC_LCDCFG5 register */
#define LCDC_LCDCFG5_Msk                      _UINT32_(0x00FF3FDF)                                 /* (LCDC_LCDCFG5) Register Mask  */


/* -------- LCDC_LCDCFG6 : (LCDC Offset: 0x18) (R/W 32) Configuration Register 6 -------- */
#define LCDC_LCDCFG6_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_LCDCFG6) Configuration Register 6  Reset Value */

#define LCDC_LCDCFG6_PWMPS_Pos                _UINT32_(0)                                          /* (LCDC_LCDCFG6) PWM Clock Prescaler Position */
#define LCDC_LCDCFG6_PWMPS_Msk                (_UINT32_(0xF) << LCDC_LCDCFG6_PWMPS_Pos)            /* (LCDC_LCDCFG6) PWM Clock Prescaler Mask */
#define LCDC_LCDCFG6_PWMPS(value)             (LCDC_LCDCFG6_PWMPS_Msk & (_UINT32_(value) << LCDC_LCDCFG6_PWMPS_Pos)) /* Assigment of value for PWMPS in the LCDC_LCDCFG6 register */
#define   LCDC_LCDCFG6_PWMPS_DIV_1_Val        _UINT32_(0x0)                                        /* (LCDC_LCDCFG6) The counter advances at a rate of fCOUNTER = fPWM_SELECTED_CLOCK  */
#define   LCDC_LCDCFG6_PWMPS_DIV_2_Val        _UINT32_(0x1)                                        /* (LCDC_LCDCFG6) The counter advances at a rate of fCOUNTER = fPWM_SELECTED_CLOCK/2  */
#define   LCDC_LCDCFG6_PWMPS_DIV_4_Val        _UINT32_(0x2)                                        /* (LCDC_LCDCFG6) The counter advances at a rate of fCOUNTER = fPWM_SELECTED_CLOCK/4  */
#define   LCDC_LCDCFG6_PWMPS_DIV_8_Val        _UINT32_(0x3)                                        /* (LCDC_LCDCFG6) The counter advances at a rate of fCOUNTER = fPWM_SELECTED_CLOCK/8  */
#define   LCDC_LCDCFG6_PWMPS_DIV_16_Val       _UINT32_(0x4)                                        /* (LCDC_LCDCFG6) The counter advances at a rate of fCOUNTER = fPWM_SELECTED_CLOCK/16  */
#define   LCDC_LCDCFG6_PWMPS_DIV_32_Val       _UINT32_(0x5)                                        /* (LCDC_LCDCFG6) The counter advances at a of rate fCOUNTER = fPWM_SELECTED_CLOCK/32  */
#define   LCDC_LCDCFG6_PWMPS_DIV_64_Val       _UINT32_(0x6)                                        /* (LCDC_LCDCFG6) The counter advances at a of rate fCOUNTER = fPWM_SELECTED_CLOCK/64  */
#define   LCDC_LCDCFG6_PWMPS_DIV_128_Val      _UINT32_(0x7)                                        /* (LCDC_LCDCFG6) The counter advances at a of rate fCOUNTER = fPWM_SELECTED_CLOCK/128  */
#define   LCDC_LCDCFG6_PWMPS_DIV_256_Val      _UINT32_(0x8)                                        /* (LCDC_LCDCFG6) The counter advances at a of rate fCOUNTER = fPWM_SELECTED_CLOCK/256  */
#define   LCDC_LCDCFG6_PWMPS_DIV_512_Val      _UINT32_(0x9)                                        /* (LCDC_LCDCFG6) The counter advances at a of rate fCOUNTER = fPWM_SELECTED_CLOCK/512  */
#define   LCDC_LCDCFG6_PWMPS_DIV_1024_Val     _UINT32_(0xA)                                        /* (LCDC_LCDCFG6) The counter advances at a of rate fCOUNTER = fPWM_SELECTED_CLOCK/1024  */
#define   LCDC_LCDCFG6_PWMPS_DIV_2048_Val     _UINT32_(0xB)                                        /* (LCDC_LCDCFG6) The counter advances at a of rate fCOUNTER = fPWM_SELECTED_CLOCK/2048  */
#define   LCDC_LCDCFG6_PWMPS_DIV_4096_Val     _UINT32_(0xC)                                        /* (LCDC_LCDCFG6) The counter advances at a of rate fCOUNTER = fPWM_SELECTED_CLOCK/4096  */
#define   LCDC_LCDCFG6_PWMPS_DIV_8192_Val     _UINT32_(0xD)                                        /* (LCDC_LCDCFG6) The counter advances at a of rate fCOUNTER = fPWM_SELECTED_CLOCK/8192  */
#define   LCDC_LCDCFG6_PWMPS_DIV_16384_Val    _UINT32_(0xE)                                        /* (LCDC_LCDCFG6) The counter advances at a of rate fCOUNTER = fPWM_SELECTED_CLOCK/16384  */
#define   LCDC_LCDCFG6_PWMPS_DIV_32768_Val    _UINT32_(0xF)                                        /* (LCDC_LCDCFG6) The counter advances at a of rate fCOUNTER = fPWM_SELECTED_CLOCK/32768  */
#define LCDC_LCDCFG6_PWMPS_DIV_1              (LCDC_LCDCFG6_PWMPS_DIV_1_Val << LCDC_LCDCFG6_PWMPS_Pos) /* (LCDC_LCDCFG6) The counter advances at a rate of fCOUNTER = fPWM_SELECTED_CLOCK Position  */
#define LCDC_LCDCFG6_PWMPS_DIV_2              (LCDC_LCDCFG6_PWMPS_DIV_2_Val << LCDC_LCDCFG6_PWMPS_Pos) /* (LCDC_LCDCFG6) The counter advances at a rate of fCOUNTER = fPWM_SELECTED_CLOCK/2 Position  */
#define LCDC_LCDCFG6_PWMPS_DIV_4              (LCDC_LCDCFG6_PWMPS_DIV_4_Val << LCDC_LCDCFG6_PWMPS_Pos) /* (LCDC_LCDCFG6) The counter advances at a rate of fCOUNTER = fPWM_SELECTED_CLOCK/4 Position  */
#define LCDC_LCDCFG6_PWMPS_DIV_8              (LCDC_LCDCFG6_PWMPS_DIV_8_Val << LCDC_LCDCFG6_PWMPS_Pos) /* (LCDC_LCDCFG6) The counter advances at a rate of fCOUNTER = fPWM_SELECTED_CLOCK/8 Position  */
#define LCDC_LCDCFG6_PWMPS_DIV_16             (LCDC_LCDCFG6_PWMPS_DIV_16_Val << LCDC_LCDCFG6_PWMPS_Pos) /* (LCDC_LCDCFG6) The counter advances at a rate of fCOUNTER = fPWM_SELECTED_CLOCK/16 Position  */
#define LCDC_LCDCFG6_PWMPS_DIV_32             (LCDC_LCDCFG6_PWMPS_DIV_32_Val << LCDC_LCDCFG6_PWMPS_Pos) /* (LCDC_LCDCFG6) The counter advances at a of rate fCOUNTER = fPWM_SELECTED_CLOCK/32 Position  */
#define LCDC_LCDCFG6_PWMPS_DIV_64             (LCDC_LCDCFG6_PWMPS_DIV_64_Val << LCDC_LCDCFG6_PWMPS_Pos) /* (LCDC_LCDCFG6) The counter advances at a of rate fCOUNTER = fPWM_SELECTED_CLOCK/64 Position  */
#define LCDC_LCDCFG6_PWMPS_DIV_128            (LCDC_LCDCFG6_PWMPS_DIV_128_Val << LCDC_LCDCFG6_PWMPS_Pos) /* (LCDC_LCDCFG6) The counter advances at a of rate fCOUNTER = fPWM_SELECTED_CLOCK/128 Position  */
#define LCDC_LCDCFG6_PWMPS_DIV_256            (LCDC_LCDCFG6_PWMPS_DIV_256_Val << LCDC_LCDCFG6_PWMPS_Pos) /* (LCDC_LCDCFG6) The counter advances at a of rate fCOUNTER = fPWM_SELECTED_CLOCK/256 Position  */
#define LCDC_LCDCFG6_PWMPS_DIV_512            (LCDC_LCDCFG6_PWMPS_DIV_512_Val << LCDC_LCDCFG6_PWMPS_Pos) /* (LCDC_LCDCFG6) The counter advances at a of rate fCOUNTER = fPWM_SELECTED_CLOCK/512 Position  */
#define LCDC_LCDCFG6_PWMPS_DIV_1024           (LCDC_LCDCFG6_PWMPS_DIV_1024_Val << LCDC_LCDCFG6_PWMPS_Pos) /* (LCDC_LCDCFG6) The counter advances at a of rate fCOUNTER = fPWM_SELECTED_CLOCK/1024 Position  */
#define LCDC_LCDCFG6_PWMPS_DIV_2048           (LCDC_LCDCFG6_PWMPS_DIV_2048_Val << LCDC_LCDCFG6_PWMPS_Pos) /* (LCDC_LCDCFG6) The counter advances at a of rate fCOUNTER = fPWM_SELECTED_CLOCK/2048 Position  */
#define LCDC_LCDCFG6_PWMPS_DIV_4096           (LCDC_LCDCFG6_PWMPS_DIV_4096_Val << LCDC_LCDCFG6_PWMPS_Pos) /* (LCDC_LCDCFG6) The counter advances at a of rate fCOUNTER = fPWM_SELECTED_CLOCK/4096 Position  */
#define LCDC_LCDCFG6_PWMPS_DIV_8192           (LCDC_LCDCFG6_PWMPS_DIV_8192_Val << LCDC_LCDCFG6_PWMPS_Pos) /* (LCDC_LCDCFG6) The counter advances at a of rate fCOUNTER = fPWM_SELECTED_CLOCK/8192 Position  */
#define LCDC_LCDCFG6_PWMPS_DIV_16384          (LCDC_LCDCFG6_PWMPS_DIV_16384_Val << LCDC_LCDCFG6_PWMPS_Pos) /* (LCDC_LCDCFG6) The counter advances at a of rate fCOUNTER = fPWM_SELECTED_CLOCK/16384 Position  */
#define LCDC_LCDCFG6_PWMPS_DIV_32768          (LCDC_LCDCFG6_PWMPS_DIV_32768_Val << LCDC_LCDCFG6_PWMPS_Pos) /* (LCDC_LCDCFG6) The counter advances at a of rate fCOUNTER = fPWM_SELECTED_CLOCK/32768 Position  */
#define LCDC_LCDCFG6_PWMPOL_Pos               _UINT32_(4)                                          /* (LCDC_LCDCFG6) LCDC PWM Signal Polarity Position */
#define LCDC_LCDCFG6_PWMPOL_Msk               (_UINT32_(0x1) << LCDC_LCDCFG6_PWMPOL_Pos)           /* (LCDC_LCDCFG6) LCDC PWM Signal Polarity Mask */
#define LCDC_LCDCFG6_PWMPOL(value)            (LCDC_LCDCFG6_PWMPOL_Msk & (_UINT32_(value) << LCDC_LCDCFG6_PWMPOL_Pos)) /* Assigment of value for PWMPOL in the LCDC_LCDCFG6 register */
#define   LCDC_LCDCFG6_PWMPOL_0_Val           _UINT32_(0x0)                                        /* (LCDC_LCDCFG6) The output pulses are low level.  */
#define   LCDC_LCDCFG6_PWMPOL_1_Val           _UINT32_(0x1)                                        /* (LCDC_LCDCFG6) The output pulses are high level (the output is high whenever the value in the counter is less than the value PWMCVAL).  */
#define LCDC_LCDCFG6_PWMPOL_0                 (LCDC_LCDCFG6_PWMPOL_0_Val << LCDC_LCDCFG6_PWMPOL_Pos) /* (LCDC_LCDCFG6) The output pulses are low level. Position  */
#define LCDC_LCDCFG6_PWMPOL_1                 (LCDC_LCDCFG6_PWMPOL_1_Val << LCDC_LCDCFG6_PWMPOL_Pos) /* (LCDC_LCDCFG6) The output pulses are high level (the output is high whenever the value in the counter is less than the value PWMCVAL). Position  */
#define LCDC_LCDCFG6_PWMCVAL_Pos              _UINT32_(8)                                          /* (LCDC_LCDCFG6) LCDC PWM Compare Value Position */
#define LCDC_LCDCFG6_PWMCVAL_Msk              (_UINT32_(0xFF) << LCDC_LCDCFG6_PWMCVAL_Pos)         /* (LCDC_LCDCFG6) LCDC PWM Compare Value Mask */
#define LCDC_LCDCFG6_PWMCVAL(value)           (LCDC_LCDCFG6_PWMCVAL_Msk & (_UINT32_(value) << LCDC_LCDCFG6_PWMCVAL_Pos)) /* Assigment of value for PWMCVAL in the LCDC_LCDCFG6 register */
#define LCDC_LCDCFG6_Msk                      _UINT32_(0x0000FF1F)                                 /* (LCDC_LCDCFG6) Register Mask  */


/* -------- LCDC_LCDCFG7 : (LCDC Offset: 0x1C) (R/W 32) Configuration Register 7 -------- */
#define LCDC_LCDCFG7_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_LCDCFG7) Configuration Register 7  Reset Value */

#define LCDC_LCDCFG7_ROW_Pos                  _UINT32_(0)                                          /* (LCDC_LCDCFG7) Row Identifier For Row Interrupt Signal Position */
#define LCDC_LCDCFG7_ROW_Msk                  (_UINT32_(0x7FF) << LCDC_LCDCFG7_ROW_Pos)            /* (LCDC_LCDCFG7) Row Identifier For Row Interrupt Signal Mask */
#define LCDC_LCDCFG7_ROW(value)               (LCDC_LCDCFG7_ROW_Msk & (_UINT32_(value) << LCDC_LCDCFG7_ROW_Pos)) /* Assigment of value for ROW in the LCDC_LCDCFG7 register */
#define LCDC_LCDCFG7_Msk                      _UINT32_(0x000007FF)                                 /* (LCDC_LCDCFG7) Register Mask  */


/* -------- LCDC_LCDEN : (LCDC Offset: 0x20) ( /W 32) Enable Register -------- */
#define LCDC_LCDEN_CLKEN_Pos                  _UINT32_(0)                                          /* (LCDC_LCDEN) LCDC Pixel Clock Enable Position */
#define LCDC_LCDEN_CLKEN_Msk                  (_UINT32_(0x1) << LCDC_LCDEN_CLKEN_Pos)              /* (LCDC_LCDEN) LCDC Pixel Clock Enable Mask */
#define LCDC_LCDEN_CLKEN(value)               (LCDC_LCDEN_CLKEN_Msk & (_UINT32_(value) << LCDC_LCDEN_CLKEN_Pos)) /* Assigment of value for CLKEN in the LCDC_LCDEN register */
#define   LCDC_LCDEN_CLKEN_0_Val              _UINT32_(0x0)                                        /* (LCDC_LCDEN) No effect  */
#define   LCDC_LCDEN_CLKEN_1_Val              _UINT32_(0x1)                                        /* (LCDC_LCDEN) Pixel clock logical unit is activated.  */
#define LCDC_LCDEN_CLKEN_0                    (LCDC_LCDEN_CLKEN_0_Val << LCDC_LCDEN_CLKEN_Pos)     /* (LCDC_LCDEN) No effect Position  */
#define LCDC_LCDEN_CLKEN_1                    (LCDC_LCDEN_CLKEN_1_Val << LCDC_LCDEN_CLKEN_Pos)     /* (LCDC_LCDEN) Pixel clock logical unit is activated. Position  */
#define LCDC_LCDEN_SYNCEN_Pos                 _UINT32_(1)                                          /* (LCDC_LCDEN) LCDC Horizontal and Vertical Synchronization Enable Position */
#define LCDC_LCDEN_SYNCEN_Msk                 (_UINT32_(0x1) << LCDC_LCDEN_SYNCEN_Pos)             /* (LCDC_LCDEN) LCDC Horizontal and Vertical Synchronization Enable Mask */
#define LCDC_LCDEN_SYNCEN(value)              (LCDC_LCDEN_SYNCEN_Msk & (_UINT32_(value) << LCDC_LCDEN_SYNCEN_Pos)) /* Assigment of value for SYNCEN in the LCDC_LCDEN register */
#define   LCDC_LCDEN_SYNCEN_0_Val             _UINT32_(0x0)                                        /* (LCDC_LCDEN) No effect  */
#define   LCDC_LCDEN_SYNCEN_1_Val             _UINT32_(0x1)                                        /* (LCDC_LCDEN) Both horizontal and vertical synchronization (LCD_VSYNC and LCD_HSYNC) signals are generated.  */
#define LCDC_LCDEN_SYNCEN_0                   (LCDC_LCDEN_SYNCEN_0_Val << LCDC_LCDEN_SYNCEN_Pos)   /* (LCDC_LCDEN) No effect Position  */
#define LCDC_LCDEN_SYNCEN_1                   (LCDC_LCDEN_SYNCEN_1_Val << LCDC_LCDEN_SYNCEN_Pos)   /* (LCDC_LCDEN) Both horizontal and vertical synchronization (LCD_VSYNC and LCD_HSYNC) signals are generated. Position  */
#define LCDC_LCDEN_DISPEN_Pos                 _UINT32_(2)                                          /* (LCDC_LCDEN) LCDC DISP Signal Enable Position */
#define LCDC_LCDEN_DISPEN_Msk                 (_UINT32_(0x1) << LCDC_LCDEN_DISPEN_Pos)             /* (LCDC_LCDEN) LCDC DISP Signal Enable Mask */
#define LCDC_LCDEN_DISPEN(value)              (LCDC_LCDEN_DISPEN_Msk & (_UINT32_(value) << LCDC_LCDEN_DISPEN_Pos)) /* Assigment of value for DISPEN in the LCDC_LCDEN register */
#define   LCDC_LCDEN_DISPEN_0_Val             _UINT32_(0x0)                                        /* (LCDC_LCDEN) No effect  */
#define   LCDC_LCDEN_DISPEN_1_Val             _UINT32_(0x1)                                        /* (LCDC_LCDEN) LCDC_DISP signal is generated.  */
#define LCDC_LCDEN_DISPEN_0                   (LCDC_LCDEN_DISPEN_0_Val << LCDC_LCDEN_DISPEN_Pos)   /* (LCDC_LCDEN) No effect Position  */
#define LCDC_LCDEN_DISPEN_1                   (LCDC_LCDEN_DISPEN_1_Val << LCDC_LCDEN_DISPEN_Pos)   /* (LCDC_LCDEN) LCDC_DISP signal is generated. Position  */
#define LCDC_LCDEN_PWMEN_Pos                  _UINT32_(3)                                          /* (LCDC_LCDEN) LCDC Pulse Width Modulation Enable Position */
#define LCDC_LCDEN_PWMEN_Msk                  (_UINT32_(0x1) << LCDC_LCDEN_PWMEN_Pos)              /* (LCDC_LCDEN) LCDC Pulse Width Modulation Enable Mask */
#define LCDC_LCDEN_PWMEN(value)               (LCDC_LCDEN_PWMEN_Msk & (_UINT32_(value) << LCDC_LCDEN_PWMEN_Pos)) /* Assigment of value for PWMEN in the LCDC_LCDEN register */
#define   LCDC_LCDEN_PWMEN_0_Val              _UINT32_(0x0)                                        /* (LCDC_LCDEN) No effect  */
#define   LCDC_LCDEN_PWMEN_1_Val              _UINT32_(0x1)                                        /* (LCDC_LCDEN) PWM is enabled.  */
#define LCDC_LCDEN_PWMEN_0                    (LCDC_LCDEN_PWMEN_0_Val << LCDC_LCDEN_PWMEN_Pos)     /* (LCDC_LCDEN) No effect Position  */
#define LCDC_LCDEN_PWMEN_1                    (LCDC_LCDEN_PWMEN_1_Val << LCDC_LCDEN_PWMEN_Pos)     /* (LCDC_LCDEN) PWM is enabled. Position  */
#define LCDC_LCDEN_SDEN_Pos                   _UINT32_(5)                                          /* (LCDC_LCDEN) Shutdown Signal Enable Position */
#define LCDC_LCDEN_SDEN_Msk                   (_UINT32_(0x1) << LCDC_LCDEN_SDEN_Pos)               /* (LCDC_LCDEN) Shutdown Signal Enable Mask */
#define LCDC_LCDEN_SDEN(value)                (LCDC_LCDEN_SDEN_Msk & (_UINT32_(value) << LCDC_LCDEN_SDEN_Pos)) /* Assigment of value for SDEN in the LCDC_LCDEN register */
#define   LCDC_LCDEN_SDEN_0_Val               _UINT32_(0x0)                                        /* (LCDC_LCDEN) No effect.  */
#define   LCDC_LCDEN_SDEN_1_Val               _UINT32_(0x1)                                        /* (LCDC_LCDEN) Sets the shutdown signal (lcd_sd) to one. If a rising edge is generated, signals the MIPI DSI host to send a "Shutdown Peripheral" command to the LCD screen when the MIPI output interface is selected.  */
#define LCDC_LCDEN_SDEN_0                     (LCDC_LCDEN_SDEN_0_Val << LCDC_LCDEN_SDEN_Pos)       /* (LCDC_LCDEN) No effect. Position  */
#define LCDC_LCDEN_SDEN_1                     (LCDC_LCDEN_SDEN_1_Val << LCDC_LCDEN_SDEN_Pos)       /* (LCDC_LCDEN) Sets the shutdown signal (lcd_sd) to one. If a rising edge is generated, signals the MIPI DSI host to send a "Shutdown Peripheral" command to the LCD screen when the MIPI output interface is selected. Position  */
#define LCDC_LCDEN_CMEN_Pos                   _UINT32_(6)                                          /* (LCDC_LCDEN) Color Mode Signal Enable Position */
#define LCDC_LCDEN_CMEN_Msk                   (_UINT32_(0x1) << LCDC_LCDEN_CMEN_Pos)               /* (LCDC_LCDEN) Color Mode Signal Enable Mask */
#define LCDC_LCDEN_CMEN(value)                (LCDC_LCDEN_CMEN_Msk & (_UINT32_(value) << LCDC_LCDEN_CMEN_Pos)) /* Assigment of value for CMEN in the LCDC_LCDEN register */
#define   LCDC_LCDEN_CMEN_0_Val               _UINT32_(0x0)                                        /* (LCDC_LCDEN) No effect.  */
#define   LCDC_LCDEN_CMEN_1_Val               _UINT32_(0x1)                                        /* (LCDC_LCDEN) Sets the color mode signal (lcd_cm) to one. If a rising edge is generated, signals the MIPI DSI host to send a "Color Mode On" command to the LCD screen when the MIPI output interface is selected.  */
#define LCDC_LCDEN_CMEN_0                     (LCDC_LCDEN_CMEN_0_Val << LCDC_LCDEN_CMEN_Pos)       /* (LCDC_LCDEN) No effect. Position  */
#define LCDC_LCDEN_CMEN_1                     (LCDC_LCDEN_CMEN_1_Val << LCDC_LCDEN_CMEN_Pos)       /* (LCDC_LCDEN) Sets the color mode signal (lcd_cm) to one. If a rising edge is generated, signals the MIPI DSI host to send a "Color Mode On" command to the LCD screen when the MIPI output interface is selected. Position  */
#define LCDC_LCDEN_Msk                        _UINT32_(0x0000006F)                                 /* (LCDC_LCDEN) Register Mask  */


/* -------- LCDC_LCDDIS : (LCDC Offset: 0x24) ( /W 32) Disable Register -------- */
#define LCDC_LCDDIS_CLKDIS_Pos                _UINT32_(0)                                          /* (LCDC_LCDDIS) LCDC Pixel Clock Disable Position */
#define LCDC_LCDDIS_CLKDIS_Msk                (_UINT32_(0x1) << LCDC_LCDDIS_CLKDIS_Pos)            /* (LCDC_LCDDIS) LCDC Pixel Clock Disable Mask */
#define LCDC_LCDDIS_CLKDIS(value)             (LCDC_LCDDIS_CLKDIS_Msk & (_UINT32_(value) << LCDC_LCDDIS_CLKDIS_Pos)) /* Assigment of value for CLKDIS in the LCDC_LCDDIS register */
#define   LCDC_LCDDIS_CLKDIS_0_Val            _UINT32_(0x0)                                        /* (LCDC_LCDDIS) No effect.  */
#define   LCDC_LCDDIS_CLKDIS_1_Val            _UINT32_(0x1)                                        /* (LCDC_LCDDIS) Disables the pixel clock after the end of the frame.  */
#define LCDC_LCDDIS_CLKDIS_0                  (LCDC_LCDDIS_CLKDIS_0_Val << LCDC_LCDDIS_CLKDIS_Pos) /* (LCDC_LCDDIS) No effect. Position  */
#define LCDC_LCDDIS_CLKDIS_1                  (LCDC_LCDDIS_CLKDIS_1_Val << LCDC_LCDDIS_CLKDIS_Pos) /* (LCDC_LCDDIS) Disables the pixel clock after the end of the frame. Position  */
#define LCDC_LCDDIS_SYNCDIS_Pos               _UINT32_(1)                                          /* (LCDC_LCDDIS) LCDC Horizontal and Vertical Synchronization Disable Position */
#define LCDC_LCDDIS_SYNCDIS_Msk               (_UINT32_(0x1) << LCDC_LCDDIS_SYNCDIS_Pos)           /* (LCDC_LCDDIS) LCDC Horizontal and Vertical Synchronization Disable Mask */
#define LCDC_LCDDIS_SYNCDIS(value)            (LCDC_LCDDIS_SYNCDIS_Msk & (_UINT32_(value) << LCDC_LCDDIS_SYNCDIS_Pos)) /* Assigment of value for SYNCDIS in the LCDC_LCDDIS register */
#define   LCDC_LCDDIS_SYNCDIS_0_Val           _UINT32_(0x0)                                        /* (LCDC_LCDDIS) No effect.  */
#define   LCDC_LCDDIS_SYNCDIS_1_Val           _UINT32_(0x1)                                        /* (LCDC_LCDDIS) Disables the synchronization signals after the end of the frame.  */
#define LCDC_LCDDIS_SYNCDIS_0                 (LCDC_LCDDIS_SYNCDIS_0_Val << LCDC_LCDDIS_SYNCDIS_Pos) /* (LCDC_LCDDIS) No effect. Position  */
#define LCDC_LCDDIS_SYNCDIS_1                 (LCDC_LCDDIS_SYNCDIS_1_Val << LCDC_LCDDIS_SYNCDIS_Pos) /* (LCDC_LCDDIS) Disables the synchronization signals after the end of the frame. Position  */
#define LCDC_LCDDIS_DISPDIS_Pos               _UINT32_(2)                                          /* (LCDC_LCDDIS) LCDC DISP Signal Disable Position */
#define LCDC_LCDDIS_DISPDIS_Msk               (_UINT32_(0x1) << LCDC_LCDDIS_DISPDIS_Pos)           /* (LCDC_LCDDIS) LCDC DISP Signal Disable Mask */
#define LCDC_LCDDIS_DISPDIS(value)            (LCDC_LCDDIS_DISPDIS_Msk & (_UINT32_(value) << LCDC_LCDDIS_DISPDIS_Pos)) /* Assigment of value for DISPDIS in the LCDC_LCDDIS register */
#define   LCDC_LCDDIS_DISPDIS_0_Val           _UINT32_(0x0)                                        /* (LCDC_LCDDIS) No effect.  */
#define   LCDC_LCDDIS_DISPDIS_1_Val           _UINT32_(0x1)                                        /* (LCDC_LCDDIS) Disables the DISP signal after the end of the frame.  */
#define LCDC_LCDDIS_DISPDIS_0                 (LCDC_LCDDIS_DISPDIS_0_Val << LCDC_LCDDIS_DISPDIS_Pos) /* (LCDC_LCDDIS) No effect. Position  */
#define LCDC_LCDDIS_DISPDIS_1                 (LCDC_LCDDIS_DISPDIS_1_Val << LCDC_LCDDIS_DISPDIS_Pos) /* (LCDC_LCDDIS) Disables the DISP signal after the end of the frame. Position  */
#define LCDC_LCDDIS_PWMDIS_Pos                _UINT32_(3)                                          /* (LCDC_LCDDIS) LCDC Pulse Width Modulation Disable Position */
#define LCDC_LCDDIS_PWMDIS_Msk                (_UINT32_(0x1) << LCDC_LCDDIS_PWMDIS_Pos)            /* (LCDC_LCDDIS) LCDC Pulse Width Modulation Disable Mask */
#define LCDC_LCDDIS_PWMDIS(value)             (LCDC_LCDDIS_PWMDIS_Msk & (_UINT32_(value) << LCDC_LCDDIS_PWMDIS_Pos)) /* Assigment of value for PWMDIS in the LCDC_LCDDIS register */
#define   LCDC_LCDDIS_PWMDIS_0_Val            _UINT32_(0x0)                                        /* (LCDC_LCDDIS) No effect.  */
#define   LCDC_LCDDIS_PWMDIS_1_Val            _UINT32_(0x1)                                        /* (LCDC_LCDDIS) Disables the pulse width modulation signal after the end of the frame.  */
#define LCDC_LCDDIS_PWMDIS_0                  (LCDC_LCDDIS_PWMDIS_0_Val << LCDC_LCDDIS_PWMDIS_Pos) /* (LCDC_LCDDIS) No effect. Position  */
#define LCDC_LCDDIS_PWMDIS_1                  (LCDC_LCDDIS_PWMDIS_1_Val << LCDC_LCDDIS_PWMDIS_Pos) /* (LCDC_LCDDIS) Disables the pulse width modulation signal after the end of the frame. Position  */
#define LCDC_LCDDIS_SDDIS_Pos                 _UINT32_(5)                                          /* (LCDC_LCDDIS) Shutdown Signal Disable Position */
#define LCDC_LCDDIS_SDDIS_Msk                 (_UINT32_(0x1) << LCDC_LCDDIS_SDDIS_Pos)             /* (LCDC_LCDDIS) Shutdown Signal Disable Mask */
#define LCDC_LCDDIS_SDDIS(value)              (LCDC_LCDDIS_SDDIS_Msk & (_UINT32_(value) << LCDC_LCDDIS_SDDIS_Pos)) /* Assigment of value for SDDIS in the LCDC_LCDDIS register */
#define   LCDC_LCDDIS_SDDIS_0_Val             _UINT32_(0x0)                                        /* (LCDC_LCDDIS) No effect.  */
#define   LCDC_LCDDIS_SDDIS_1_Val             _UINT32_(0x1)                                        /* (LCDC_LCDDIS) Sets the shutdown signal (lcd_sd) to zero. If a falling edge is generated, signals the MIPI DSI host to send a "Turn On Peripheral" command to the LCD screen when the MIPI output interface is selected).  */
#define LCDC_LCDDIS_SDDIS_0                   (LCDC_LCDDIS_SDDIS_0_Val << LCDC_LCDDIS_SDDIS_Pos)   /* (LCDC_LCDDIS) No effect. Position  */
#define LCDC_LCDDIS_SDDIS_1                   (LCDC_LCDDIS_SDDIS_1_Val << LCDC_LCDDIS_SDDIS_Pos)   /* (LCDC_LCDDIS) Sets the shutdown signal (lcd_sd) to zero. If a falling edge is generated, signals the MIPI DSI host to send a "Turn On Peripheral" command to the LCD screen when the MIPI output interface is selected). Position  */
#define LCDC_LCDDIS_CMDIS_Pos                 _UINT32_(6)                                          /* (LCDC_LCDDIS) Color Mode Signal Disable Position */
#define LCDC_LCDDIS_CMDIS_Msk                 (_UINT32_(0x1) << LCDC_LCDDIS_CMDIS_Pos)             /* (LCDC_LCDDIS) Color Mode Signal Disable Mask */
#define LCDC_LCDDIS_CMDIS(value)              (LCDC_LCDDIS_CMDIS_Msk & (_UINT32_(value) << LCDC_LCDDIS_CMDIS_Pos)) /* Assigment of value for CMDIS in the LCDC_LCDDIS register */
#define   LCDC_LCDDIS_CMDIS_0_Val             _UINT32_(0x0)                                        /* (LCDC_LCDDIS) No effect.  */
#define   LCDC_LCDDIS_CMDIS_1_Val             _UINT32_(0x1)                                        /* (LCDC_LCDDIS) Sets the color mode signa (lcd_cm) to zero. If a falling edge is generated, signals the MIPI DSI host to send a "Color Mode Off" command to the LCD screen when the MIPI output interface is selected).  */
#define LCDC_LCDDIS_CMDIS_0                   (LCDC_LCDDIS_CMDIS_0_Val << LCDC_LCDDIS_CMDIS_Pos)   /* (LCDC_LCDDIS) No effect. Position  */
#define LCDC_LCDDIS_CMDIS_1                   (LCDC_LCDDIS_CMDIS_1_Val << LCDC_LCDDIS_CMDIS_Pos)   /* (LCDC_LCDDIS) Sets the color mode signa (lcd_cm) to zero. If a falling edge is generated, signals the MIPI DSI host to send a "Color Mode Off" command to the LCD screen when the MIPI output interface is selected). Position  */
#define LCDC_LCDDIS_CLKRST_Pos                _UINT32_(8)                                          /* (LCDC_LCDDIS) LCDC Clock Reset Position */
#define LCDC_LCDDIS_CLKRST_Msk                (_UINT32_(0x1) << LCDC_LCDDIS_CLKRST_Pos)            /* (LCDC_LCDDIS) LCDC Clock Reset Mask */
#define LCDC_LCDDIS_CLKRST(value)             (LCDC_LCDDIS_CLKRST_Msk & (_UINT32_(value) << LCDC_LCDDIS_CLKRST_Pos)) /* Assigment of value for CLKRST in the LCDC_LCDDIS register */
#define   LCDC_LCDDIS_CLKRST_0_Val            _UINT32_(0x0)                                        /* (LCDC_LCDDIS) No effect.  */
#define   LCDC_LCDDIS_CLKRST_1_Val            _UINT32_(0x1)                                        /* (LCDC_LCDDIS) Resets the pixel clock generator module immediately. The pixel clock duty cycle may be violated.  */
#define LCDC_LCDDIS_CLKRST_0                  (LCDC_LCDDIS_CLKRST_0_Val << LCDC_LCDDIS_CLKRST_Pos) /* (LCDC_LCDDIS) No effect. Position  */
#define LCDC_LCDDIS_CLKRST_1                  (LCDC_LCDDIS_CLKRST_1_Val << LCDC_LCDDIS_CLKRST_Pos) /* (LCDC_LCDDIS) Resets the pixel clock generator module immediately. The pixel clock duty cycle may be violated. Position  */
#define LCDC_LCDDIS_SYNCRST_Pos               _UINT32_(9)                                          /* (LCDC_LCDDIS) LCDC Horizontal and Vertical Synchronization Reset Position */
#define LCDC_LCDDIS_SYNCRST_Msk               (_UINT32_(0x1) << LCDC_LCDDIS_SYNCRST_Pos)           /* (LCDC_LCDDIS) LCDC Horizontal and Vertical Synchronization Reset Mask */
#define LCDC_LCDDIS_SYNCRST(value)            (LCDC_LCDDIS_SYNCRST_Msk & (_UINT32_(value) << LCDC_LCDDIS_SYNCRST_Pos)) /* Assigment of value for SYNCRST in the LCDC_LCDDIS register */
#define   LCDC_LCDDIS_SYNCRST_0_Val           _UINT32_(0x0)                                        /* (LCDC_LCDDIS) No effect.  */
#define   LCDC_LCDDIS_SYNCRST_1_Val           _UINT32_(0x1)                                        /* (LCDC_LCDDIS) Resets the timing engine immediately. The horizontal and vertical pulse widths are both violated.  */
#define LCDC_LCDDIS_SYNCRST_0                 (LCDC_LCDDIS_SYNCRST_0_Val << LCDC_LCDDIS_SYNCRST_Pos) /* (LCDC_LCDDIS) No effect. Position  */
#define LCDC_LCDDIS_SYNCRST_1                 (LCDC_LCDDIS_SYNCRST_1_Val << LCDC_LCDDIS_SYNCRST_Pos) /* (LCDC_LCDDIS) Resets the timing engine immediately. The horizontal and vertical pulse widths are both violated. Position  */
#define LCDC_LCDDIS_DISPRST_Pos               _UINT32_(10)                                         /* (LCDC_LCDDIS) LCDC DISP Signal Reset Position */
#define LCDC_LCDDIS_DISPRST_Msk               (_UINT32_(0x1) << LCDC_LCDDIS_DISPRST_Pos)           /* (LCDC_LCDDIS) LCDC DISP Signal Reset Mask */
#define LCDC_LCDDIS_DISPRST(value)            (LCDC_LCDDIS_DISPRST_Msk & (_UINT32_(value) << LCDC_LCDDIS_DISPRST_Pos)) /* Assigment of value for DISPRST in the LCDC_LCDDIS register */
#define   LCDC_LCDDIS_DISPRST_0_Val           _UINT32_(0x0)                                        /* (LCDC_LCDDIS) No effect.  */
#define   LCDC_LCDDIS_DISPRST_1_Val           _UINT32_(0x1)                                        /* (LCDC_LCDDIS) Resets the DISP signa immediatelyl.  */
#define LCDC_LCDDIS_DISPRST_0                 (LCDC_LCDDIS_DISPRST_0_Val << LCDC_LCDDIS_DISPRST_Pos) /* (LCDC_LCDDIS) No effect. Position  */
#define LCDC_LCDDIS_DISPRST_1                 (LCDC_LCDDIS_DISPRST_1_Val << LCDC_LCDDIS_DISPRST_Pos) /* (LCDC_LCDDIS) Resets the DISP signa immediatelyl. Position  */
#define LCDC_LCDDIS_PWMRST_Pos                _UINT32_(11)                                         /* (LCDC_LCDDIS) LCDC PWM Reset Position */
#define LCDC_LCDDIS_PWMRST_Msk                (_UINT32_(0x1) << LCDC_LCDDIS_PWMRST_Pos)            /* (LCDC_LCDDIS) LCDC PWM Reset Mask */
#define LCDC_LCDDIS_PWMRST(value)             (LCDC_LCDDIS_PWMRST_Msk & (_UINT32_(value) << LCDC_LCDDIS_PWMRST_Pos)) /* Assigment of value for PWMRST in the LCDC_LCDDIS register */
#define   LCDC_LCDDIS_PWMRST_0_Val            _UINT32_(0x0)                                        /* (LCDC_LCDDIS) No effect.  */
#define   LCDC_LCDDIS_PWMRST_1_Val            _UINT32_(0x1)                                        /* (LCDC_LCDDIS) Resets the PWM module immediately. The duty cycle may be violated.  */
#define LCDC_LCDDIS_PWMRST_0                  (LCDC_LCDDIS_PWMRST_0_Val << LCDC_LCDDIS_PWMRST_Pos) /* (LCDC_LCDDIS) No effect. Position  */
#define LCDC_LCDDIS_PWMRST_1                  (LCDC_LCDDIS_PWMRST_1_Val << LCDC_LCDDIS_PWMRST_Pos) /* (LCDC_LCDDIS) Resets the PWM module immediately. The duty cycle may be violated. Position  */
#define LCDC_LCDDIS_Msk                       _UINT32_(0x00000F6F)                                 /* (LCDC_LCDDIS) Register Mask  */


/* -------- LCDC_LCDSR : (LCDC Offset: 0x28) ( R/ 32) Status Register -------- */
#define LCDC_LCDSR_RESETVALUE                 _UINT32_(0x20)                                       /*  (LCDC_LCDSR) Status Register  Reset Value */

#define LCDC_LCDSR_CLKSTS_Pos                 _UINT32_(0)                                          /* (LCDC_LCDSR) Clock Status Position */
#define LCDC_LCDSR_CLKSTS_Msk                 (_UINT32_(0x1) << LCDC_LCDSR_CLKSTS_Pos)             /* (LCDC_LCDSR) Clock Status Mask */
#define LCDC_LCDSR_CLKSTS(value)              (LCDC_LCDSR_CLKSTS_Msk & (_UINT32_(value) << LCDC_LCDSR_CLKSTS_Pos)) /* Assigment of value for CLKSTS in the LCDC_LCDSR register */
#define   LCDC_LCDSR_CLKSTS_0_Val             _UINT32_(0x0)                                        /* (LCDC_LCDSR) Pixel clock is disabled.  */
#define   LCDC_LCDSR_CLKSTS_1_Val             _UINT32_(0x1)                                        /* (LCDC_LCDSR) Pixel clock is running.  */
#define LCDC_LCDSR_CLKSTS_0                   (LCDC_LCDSR_CLKSTS_0_Val << LCDC_LCDSR_CLKSTS_Pos)   /* (LCDC_LCDSR) Pixel clock is disabled. Position  */
#define LCDC_LCDSR_CLKSTS_1                   (LCDC_LCDSR_CLKSTS_1_Val << LCDC_LCDSR_CLKSTS_Pos)   /* (LCDC_LCDSR) Pixel clock is running. Position  */
#define LCDC_LCDSR_LCDSTS_Pos                 _UINT32_(1)                                          /* (LCDC_LCDSR) LCDC Synchronization Status Position */
#define LCDC_LCDSR_LCDSTS_Msk                 (_UINT32_(0x1) << LCDC_LCDSR_LCDSTS_Pos)             /* (LCDC_LCDSR) LCDC Synchronization Status Mask */
#define LCDC_LCDSR_LCDSTS(value)              (LCDC_LCDSR_LCDSTS_Msk & (_UINT32_(value) << LCDC_LCDSR_LCDSTS_Pos)) /* Assigment of value for LCDSTS in the LCDC_LCDSR register */
#define   LCDC_LCDSR_LCDSTS_0_Val             _UINT32_(0x0)                                        /* (LCDC_LCDSR) Timing engine is disabled.  */
#define   LCDC_LCDSR_LCDSTS_1_Val             _UINT32_(0x1)                                        /* (LCDC_LCDSR) Timing engine is running.  */
#define LCDC_LCDSR_LCDSTS_0                   (LCDC_LCDSR_LCDSTS_0_Val << LCDC_LCDSR_LCDSTS_Pos)   /* (LCDC_LCDSR) Timing engine is disabled. Position  */
#define LCDC_LCDSR_LCDSTS_1                   (LCDC_LCDSR_LCDSTS_1_Val << LCDC_LCDSR_LCDSTS_Pos)   /* (LCDC_LCDSR) Timing engine is running. Position  */
#define LCDC_LCDSR_DISPSTS_Pos                _UINT32_(2)                                          /* (LCDC_LCDSR) LCDC DISP Signal Status Position */
#define LCDC_LCDSR_DISPSTS_Msk                (_UINT32_(0x1) << LCDC_LCDSR_DISPSTS_Pos)            /* (LCDC_LCDSR) LCDC DISP Signal Status Mask */
#define LCDC_LCDSR_DISPSTS(value)             (LCDC_LCDSR_DISPSTS_Msk & (_UINT32_(value) << LCDC_LCDSR_DISPSTS_Pos)) /* Assigment of value for DISPSTS in the LCDC_LCDSR register */
#define   LCDC_LCDSR_DISPSTS_0_Val            _UINT32_(0x0)                                        /* (LCDC_LCDSR) DISP is disabled.  */
#define   LCDC_LCDSR_DISPSTS_1_Val            _UINT32_(0x1)                                        /* (LCDC_LCDSR) DISP signal is activated.  */
#define LCDC_LCDSR_DISPSTS_0                  (LCDC_LCDSR_DISPSTS_0_Val << LCDC_LCDSR_DISPSTS_Pos) /* (LCDC_LCDSR) DISP is disabled. Position  */
#define LCDC_LCDSR_DISPSTS_1                  (LCDC_LCDSR_DISPSTS_1_Val << LCDC_LCDSR_DISPSTS_Pos) /* (LCDC_LCDSR) DISP signal is activated. Position  */
#define LCDC_LCDSR_PWMSTS_Pos                 _UINT32_(3)                                          /* (LCDC_LCDSR) LCDC PWM Signal Status Position */
#define LCDC_LCDSR_PWMSTS_Msk                 (_UINT32_(0x1) << LCDC_LCDSR_PWMSTS_Pos)             /* (LCDC_LCDSR) LCDC PWM Signal Status Mask */
#define LCDC_LCDSR_PWMSTS(value)              (LCDC_LCDSR_PWMSTS_Msk & (_UINT32_(value) << LCDC_LCDSR_PWMSTS_Pos)) /* Assigment of value for PWMSTS in the LCDC_LCDSR register */
#define   LCDC_LCDSR_PWMSTS_0_Val             _UINT32_(0x0)                                        /* (LCDC_LCDSR) PWM is disabled.  */
#define   LCDC_LCDSR_PWMSTS_1_Val             _UINT32_(0x1)                                        /* (LCDC_LCDSR) PWM signal is activated.  */
#define LCDC_LCDSR_PWMSTS_0                   (LCDC_LCDSR_PWMSTS_0_Val << LCDC_LCDSR_PWMSTS_Pos)   /* (LCDC_LCDSR) PWM is disabled. Position  */
#define LCDC_LCDSR_PWMSTS_1                   (LCDC_LCDSR_PWMSTS_1_Val << LCDC_LCDSR_PWMSTS_Pos)   /* (LCDC_LCDSR) PWM signal is activated. Position  */
#define LCDC_LCDSR_SIPSTS_Pos                 _UINT32_(4)                                          /* (LCDC_LCDSR) Synchronization In Progress Position */
#define LCDC_LCDSR_SIPSTS_Msk                 (_UINT32_(0x1) << LCDC_LCDSR_SIPSTS_Pos)             /* (LCDC_LCDSR) Synchronization In Progress Mask */
#define LCDC_LCDSR_SIPSTS(value)              (LCDC_LCDSR_SIPSTS_Msk & (_UINT32_(value) << LCDC_LCDSR_SIPSTS_Pos)) /* Assigment of value for SIPSTS in the LCDC_LCDSR register */
#define   LCDC_LCDSR_SIPSTS_0_Val             _UINT32_(0x0)                                        /* (LCDC_LCDSR) Clock domain synchronization is terminated.  */
#define   LCDC_LCDSR_SIPSTS_1_Val             _UINT32_(0x1)                                        /* (LCDC_LCDSR) Synchronization is in progress. Access to the registers LCDC_LCDCCFG[0..7], LCDC_LCDEN and LCDC_LCDDIS has no effect.  */
#define LCDC_LCDSR_SIPSTS_0                   (LCDC_LCDSR_SIPSTS_0_Val << LCDC_LCDSR_SIPSTS_Pos)   /* (LCDC_LCDSR) Clock domain synchronization is terminated. Position  */
#define LCDC_LCDSR_SIPSTS_1                   (LCDC_LCDSR_SIPSTS_1_Val << LCDC_LCDSR_SIPSTS_Pos)   /* (LCDC_LCDSR) Synchronization is in progress. Access to the registers LCDC_LCDCCFG[0..7], LCDC_LCDEN and LCDC_LCDDIS has no effect. Position  */
#define LCDC_LCDSR_SDSTS_Pos                  _UINT32_(5)                                          /* (LCDC_LCDSR) Shutdown Signal Status Position */
#define LCDC_LCDSR_SDSTS_Msk                  (_UINT32_(0x1) << LCDC_LCDSR_SDSTS_Pos)              /* (LCDC_LCDSR) Shutdown Signal Status Mask */
#define LCDC_LCDSR_SDSTS(value)               (LCDC_LCDSR_SDSTS_Msk & (_UINT32_(value) << LCDC_LCDSR_SDSTS_Pos)) /* Assigment of value for SDSTS in the LCDC_LCDSR register */
#define   LCDC_LCDSR_SDSTS_0_Val              _UINT32_(0x0)                                        /* (LCDC_LCDSR) Shutdown signal output is zero.  */
#define   LCDC_LCDSR_SDSTS_1_Val              _UINT32_(0x1)                                        /* (LCDC_LCDSR) Shutdown signal output is one.  */
#define LCDC_LCDSR_SDSTS_0                    (LCDC_LCDSR_SDSTS_0_Val << LCDC_LCDSR_SDSTS_Pos)     /* (LCDC_LCDSR) Shutdown signal output is zero. Position  */
#define LCDC_LCDSR_SDSTS_1                    (LCDC_LCDSR_SDSTS_1_Val << LCDC_LCDSR_SDSTS_Pos)     /* (LCDC_LCDSR) Shutdown signal output is one. Position  */
#define LCDC_LCDSR_CMSTS_Pos                  _UINT32_(6)                                          /* (LCDC_LCDSR) Color Mode Signal Status Position */
#define LCDC_LCDSR_CMSTS_Msk                  (_UINT32_(0x1) << LCDC_LCDSR_CMSTS_Pos)              /* (LCDC_LCDSR) Color Mode Signal Status Mask */
#define LCDC_LCDSR_CMSTS(value)               (LCDC_LCDSR_CMSTS_Msk & (_UINT32_(value) << LCDC_LCDSR_CMSTS_Pos)) /* Assigment of value for CMSTS in the LCDC_LCDSR register */
#define   LCDC_LCDSR_CMSTS_0_Val              _UINT32_(0x0)                                        /* (LCDC_LCDSR) Color mode signal output is zero.  */
#define   LCDC_LCDSR_CMSTS_1_Val              _UINT32_(0x1)                                        /* (LCDC_LCDSR) Color mode signal output is one.  */
#define LCDC_LCDSR_CMSTS_0                    (LCDC_LCDSR_CMSTS_0_Val << LCDC_LCDSR_CMSTS_Pos)     /* (LCDC_LCDSR) Color mode signal output is zero. Position  */
#define LCDC_LCDSR_CMSTS_1                    (LCDC_LCDSR_CMSTS_1_Val << LCDC_LCDSR_CMSTS_Pos)     /* (LCDC_LCDSR) Color mode signal output is one. Position  */
#define LCDC_LCDSR_Msk                        _UINT32_(0x0000007F)                                 /* (LCDC_LCDSR) Register Mask  */


/* -------- LCDC_LCDIER : (LCDC Offset: 0x2C) ( /W 32) Interrupt Enable Register -------- */
#define LCDC_LCDIER_SOFIE_Pos                 _UINT32_(0)                                          /* (LCDC_LCDIER) Start of Frame Interrupt Enable Position */
#define LCDC_LCDIER_SOFIE_Msk                 (_UINT32_(0x1) << LCDC_LCDIER_SOFIE_Pos)             /* (LCDC_LCDIER) Start of Frame Interrupt Enable Mask */
#define LCDC_LCDIER_SOFIE(value)              (LCDC_LCDIER_SOFIE_Msk & (_UINT32_(value) << LCDC_LCDIER_SOFIE_Pos)) /* Assigment of value for SOFIE in the LCDC_LCDIER register */
#define LCDC_LCDIER_DISIE_Pos                 _UINT32_(1)                                          /* (LCDC_LCDIER) LCD Disable Interrupt Enable Position */
#define LCDC_LCDIER_DISIE_Msk                 (_UINT32_(0x1) << LCDC_LCDIER_DISIE_Pos)             /* (LCDC_LCDIER) LCD Disable Interrupt Enable Mask */
#define LCDC_LCDIER_DISIE(value)              (LCDC_LCDIER_DISIE_Msk & (_UINT32_(value) << LCDC_LCDIER_DISIE_Pos)) /* Assigment of value for DISIE in the LCDC_LCDIER register */
#define LCDC_LCDIER_DISPIE_Pos                _UINT32_(2)                                          /* (LCDC_LCDIER) Power-up/Power-down Sequence Terminated Interrupt Enable Position */
#define LCDC_LCDIER_DISPIE_Msk                (_UINT32_(0x1) << LCDC_LCDIER_DISPIE_Pos)            /* (LCDC_LCDIER) Power-up/Power-down Sequence Terminated Interrupt Enable Mask */
#define LCDC_LCDIER_DISPIE(value)             (LCDC_LCDIER_DISPIE_Msk & (_UINT32_(value) << LCDC_LCDIER_DISPIE_Pos)) /* Assigment of value for DISPIE in the LCDC_LCDIER register */
#define LCDC_LCDIER_ROWIE_Pos                 _UINT32_(3)                                          /* (LCDC_LCDIER) Row Interrupt Enable Position */
#define LCDC_LCDIER_ROWIE_Msk                 (_UINT32_(0x1) << LCDC_LCDIER_ROWIE_Pos)             /* (LCDC_LCDIER) Row Interrupt Enable Mask */
#define LCDC_LCDIER_ROWIE(value)              (LCDC_LCDIER_ROWIE_Msk & (_UINT32_(value) << LCDC_LCDIER_ROWIE_Pos)) /* Assigment of value for ROWIE in the LCDC_LCDIER register */
#define LCDC_LCDIER_FIFOERRIE_Pos             _UINT32_(4)                                          /* (LCDC_LCDIER) Output FIFO Error Interrupt Enable Position */
#define LCDC_LCDIER_FIFOERRIE_Msk             (_UINT32_(0x1) << LCDC_LCDIER_FIFOERRIE_Pos)         /* (LCDC_LCDIER) Output FIFO Error Interrupt Enable Mask */
#define LCDC_LCDIER_FIFOERRIE(value)          (LCDC_LCDIER_FIFOERRIE_Msk & (_UINT32_(value) << LCDC_LCDIER_FIFOERRIE_Pos)) /* Assigment of value for FIFOERRIE in the LCDC_LCDIER register */
#define LCDC_LCDIER_BASEIE_Pos                _UINT32_(8)                                          /* (LCDC_LCDIER) Base Layer Interrupt Enable Position */
#define LCDC_LCDIER_BASEIE_Msk                (_UINT32_(0x1) << LCDC_LCDIER_BASEIE_Pos)            /* (LCDC_LCDIER) Base Layer Interrupt Enable Mask */
#define LCDC_LCDIER_BASEIE(value)             (LCDC_LCDIER_BASEIE_Msk & (_UINT32_(value) << LCDC_LCDIER_BASEIE_Pos)) /* Assigment of value for BASEIE in the LCDC_LCDIER register */
#define LCDC_LCDIER_OVR1IE_Pos                _UINT32_(9)                                          /* (LCDC_LCDIER) Overlay 1 Interrupt Enable Position */
#define LCDC_LCDIER_OVR1IE_Msk                (_UINT32_(0x1) << LCDC_LCDIER_OVR1IE_Pos)            /* (LCDC_LCDIER) Overlay 1 Interrupt Enable Mask */
#define LCDC_LCDIER_OVR1IE(value)             (LCDC_LCDIER_OVR1IE_Msk & (_UINT32_(value) << LCDC_LCDIER_OVR1IE_Pos)) /* Assigment of value for OVR1IE in the LCDC_LCDIER register */
#define LCDC_LCDIER_OVR2IE_Pos                _UINT32_(10)                                         /* (LCDC_LCDIER) Overlay 2 Interrupt Enable Position */
#define LCDC_LCDIER_OVR2IE_Msk                (_UINT32_(0x1) << LCDC_LCDIER_OVR2IE_Pos)            /* (LCDC_LCDIER) Overlay 2 Interrupt Enable Mask */
#define LCDC_LCDIER_OVR2IE(value)             (LCDC_LCDIER_OVR2IE_Msk & (_UINT32_(value) << LCDC_LCDIER_OVR2IE_Pos)) /* Assigment of value for OVR2IE in the LCDC_LCDIER register */
#define LCDC_LCDIER_HEOIE_Pos                 _UINT32_(11)                                         /* (LCDC_LCDIER) High-End Overlay Interrupt Enable Position */
#define LCDC_LCDIER_HEOIE_Msk                 (_UINT32_(0x1) << LCDC_LCDIER_HEOIE_Pos)             /* (LCDC_LCDIER) High-End Overlay Interrupt Enable Mask */
#define LCDC_LCDIER_HEOIE(value)              (LCDC_LCDIER_HEOIE_Msk & (_UINT32_(value) << LCDC_LCDIER_HEOIE_Pos)) /* Assigment of value for HEOIE in the LCDC_LCDIER register */
#define LCDC_LCDIER_WPIE_Pos                  _UINT32_(31)                                         /* (LCDC_LCDIER) Write Protection Interrupt Enable Position */
#define LCDC_LCDIER_WPIE_Msk                  (_UINT32_(0x1) << LCDC_LCDIER_WPIE_Pos)              /* (LCDC_LCDIER) Write Protection Interrupt Enable Mask */
#define LCDC_LCDIER_WPIE(value)               (LCDC_LCDIER_WPIE_Msk & (_UINT32_(value) << LCDC_LCDIER_WPIE_Pos)) /* Assigment of value for WPIE in the LCDC_LCDIER register */
#define LCDC_LCDIER_Msk                       _UINT32_(0x80000F1F)                                 /* (LCDC_LCDIER) Register Mask  */


/* -------- LCDC_LCDIDR : (LCDC Offset: 0x30) ( /W 32) Interrupt Disable Register -------- */
#define LCDC_LCDIDR_SOFID_Pos                 _UINT32_(0)                                          /* (LCDC_LCDIDR) Start of Frame Interrupt Disable Position */
#define LCDC_LCDIDR_SOFID_Msk                 (_UINT32_(0x1) << LCDC_LCDIDR_SOFID_Pos)             /* (LCDC_LCDIDR) Start of Frame Interrupt Disable Mask */
#define LCDC_LCDIDR_SOFID(value)              (LCDC_LCDIDR_SOFID_Msk & (_UINT32_(value) << LCDC_LCDIDR_SOFID_Pos)) /* Assigment of value for SOFID in the LCDC_LCDIDR register */
#define LCDC_LCDIDR_DISID_Pos                 _UINT32_(1)                                          /* (LCDC_LCDIDR) LCD Disable Interrupt Disable Position */
#define LCDC_LCDIDR_DISID_Msk                 (_UINT32_(0x1) << LCDC_LCDIDR_DISID_Pos)             /* (LCDC_LCDIDR) LCD Disable Interrupt Disable Mask */
#define LCDC_LCDIDR_DISID(value)              (LCDC_LCDIDR_DISID_Msk & (_UINT32_(value) << LCDC_LCDIDR_DISID_Pos)) /* Assigment of value for DISID in the LCDC_LCDIDR register */
#define LCDC_LCDIDR_DISPID_Pos                _UINT32_(2)                                          /* (LCDC_LCDIDR) Power-up/Power-down Sequence Terminated Interrupt Disable Position */
#define LCDC_LCDIDR_DISPID_Msk                (_UINT32_(0x1) << LCDC_LCDIDR_DISPID_Pos)            /* (LCDC_LCDIDR) Power-up/Power-down Sequence Terminated Interrupt Disable Mask */
#define LCDC_LCDIDR_DISPID(value)             (LCDC_LCDIDR_DISPID_Msk & (_UINT32_(value) << LCDC_LCDIDR_DISPID_Pos)) /* Assigment of value for DISPID in the LCDC_LCDIDR register */
#define LCDC_LCDIDR_ROWID_Pos                 _UINT32_(3)                                          /* (LCDC_LCDIDR) Row Interrupt Disable Position */
#define LCDC_LCDIDR_ROWID_Msk                 (_UINT32_(0x1) << LCDC_LCDIDR_ROWID_Pos)             /* (LCDC_LCDIDR) Row Interrupt Disable Mask */
#define LCDC_LCDIDR_ROWID(value)              (LCDC_LCDIDR_ROWID_Msk & (_UINT32_(value) << LCDC_LCDIDR_ROWID_Pos)) /* Assigment of value for ROWID in the LCDC_LCDIDR register */
#define LCDC_LCDIDR_FIFOERRID_Pos             _UINT32_(4)                                          /* (LCDC_LCDIDR) Output FIFO Error Interrupt Disable Position */
#define LCDC_LCDIDR_FIFOERRID_Msk             (_UINT32_(0x1) << LCDC_LCDIDR_FIFOERRID_Pos)         /* (LCDC_LCDIDR) Output FIFO Error Interrupt Disable Mask */
#define LCDC_LCDIDR_FIFOERRID(value)          (LCDC_LCDIDR_FIFOERRID_Msk & (_UINT32_(value) << LCDC_LCDIDR_FIFOERRID_Pos)) /* Assigment of value for FIFOERRID in the LCDC_LCDIDR register */
#define LCDC_LCDIDR_BASEID_Pos                _UINT32_(8)                                          /* (LCDC_LCDIDR) Base Layer Interrupt Disable Position */
#define LCDC_LCDIDR_BASEID_Msk                (_UINT32_(0x1) << LCDC_LCDIDR_BASEID_Pos)            /* (LCDC_LCDIDR) Base Layer Interrupt Disable Mask */
#define LCDC_LCDIDR_BASEID(value)             (LCDC_LCDIDR_BASEID_Msk & (_UINT32_(value) << LCDC_LCDIDR_BASEID_Pos)) /* Assigment of value for BASEID in the LCDC_LCDIDR register */
#define LCDC_LCDIDR_OVR1ID_Pos                _UINT32_(9)                                          /* (LCDC_LCDIDR) Overlay 1 Interrupt Disable Position */
#define LCDC_LCDIDR_OVR1ID_Msk                (_UINT32_(0x1) << LCDC_LCDIDR_OVR1ID_Pos)            /* (LCDC_LCDIDR) Overlay 1 Interrupt Disable Mask */
#define LCDC_LCDIDR_OVR1ID(value)             (LCDC_LCDIDR_OVR1ID_Msk & (_UINT32_(value) << LCDC_LCDIDR_OVR1ID_Pos)) /* Assigment of value for OVR1ID in the LCDC_LCDIDR register */
#define LCDC_LCDIDR_OVR2ID_Pos                _UINT32_(10)                                         /* (LCDC_LCDIDR) Overlay 2 Interrupt Disable Position */
#define LCDC_LCDIDR_OVR2ID_Msk                (_UINT32_(0x1) << LCDC_LCDIDR_OVR2ID_Pos)            /* (LCDC_LCDIDR) Overlay 2 Interrupt Disable Mask */
#define LCDC_LCDIDR_OVR2ID(value)             (LCDC_LCDIDR_OVR2ID_Msk & (_UINT32_(value) << LCDC_LCDIDR_OVR2ID_Pos)) /* Assigment of value for OVR2ID in the LCDC_LCDIDR register */
#define LCDC_LCDIDR_HEOID_Pos                 _UINT32_(11)                                         /* (LCDC_LCDIDR) High-End Overlay Interrupt Disable Position */
#define LCDC_LCDIDR_HEOID_Msk                 (_UINT32_(0x1) << LCDC_LCDIDR_HEOID_Pos)             /* (LCDC_LCDIDR) High-End Overlay Interrupt Disable Mask */
#define LCDC_LCDIDR_HEOID(value)              (LCDC_LCDIDR_HEOID_Msk & (_UINT32_(value) << LCDC_LCDIDR_HEOID_Pos)) /* Assigment of value for HEOID in the LCDC_LCDIDR register */
#define LCDC_LCDIDR_WPID_Pos                  _UINT32_(31)                                         /* (LCDC_LCDIDR) Write Protection Interrupt Disable Position */
#define LCDC_LCDIDR_WPID_Msk                  (_UINT32_(0x1) << LCDC_LCDIDR_WPID_Pos)              /* (LCDC_LCDIDR) Write Protection Interrupt Disable Mask */
#define LCDC_LCDIDR_WPID(value)               (LCDC_LCDIDR_WPID_Msk & (_UINT32_(value) << LCDC_LCDIDR_WPID_Pos)) /* Assigment of value for WPID in the LCDC_LCDIDR register */
#define LCDC_LCDIDR_Msk                       _UINT32_(0x80000F1F)                                 /* (LCDC_LCDIDR) Register Mask  */


/* -------- LCDC_LCDIMR : (LCDC Offset: 0x34) ( R/ 32) Interrupt Mask Register -------- */
#define LCDC_LCDIMR_RESETVALUE                _UINT32_(0x00)                                       /*  (LCDC_LCDIMR) Interrupt Mask Register  Reset Value */

#define LCDC_LCDIMR_SOFIM_Pos                 _UINT32_(0)                                          /* (LCDC_LCDIMR) Start of Frame Interrupt Mask Position */
#define LCDC_LCDIMR_SOFIM_Msk                 (_UINT32_(0x1) << LCDC_LCDIMR_SOFIM_Pos)             /* (LCDC_LCDIMR) Start of Frame Interrupt Mask Mask */
#define LCDC_LCDIMR_SOFIM(value)              (LCDC_LCDIMR_SOFIM_Msk & (_UINT32_(value) << LCDC_LCDIMR_SOFIM_Pos)) /* Assigment of value for SOFIM in the LCDC_LCDIMR register */
#define LCDC_LCDIMR_DISIM_Pos                 _UINT32_(1)                                          /* (LCDC_LCDIMR) LCD Disable Interrupt Mask Position */
#define LCDC_LCDIMR_DISIM_Msk                 (_UINT32_(0x1) << LCDC_LCDIMR_DISIM_Pos)             /* (LCDC_LCDIMR) LCD Disable Interrupt Mask Mask */
#define LCDC_LCDIMR_DISIM(value)              (LCDC_LCDIMR_DISIM_Msk & (_UINT32_(value) << LCDC_LCDIMR_DISIM_Pos)) /* Assigment of value for DISIM in the LCDC_LCDIMR register */
#define LCDC_LCDIMR_DISPIM_Pos                _UINT32_(2)                                          /* (LCDC_LCDIMR) Power-up/Power-down Sequence Terminated Interrupt Mask Position */
#define LCDC_LCDIMR_DISPIM_Msk                (_UINT32_(0x1) << LCDC_LCDIMR_DISPIM_Pos)            /* (LCDC_LCDIMR) Power-up/Power-down Sequence Terminated Interrupt Mask Mask */
#define LCDC_LCDIMR_DISPIM(value)             (LCDC_LCDIMR_DISPIM_Msk & (_UINT32_(value) << LCDC_LCDIMR_DISPIM_Pos)) /* Assigment of value for DISPIM in the LCDC_LCDIMR register */
#define LCDC_LCDIMR_ROWIM_Pos                 _UINT32_(3)                                          /* (LCDC_LCDIMR) Row Interrupt Mask Position */
#define LCDC_LCDIMR_ROWIM_Msk                 (_UINT32_(0x1) << LCDC_LCDIMR_ROWIM_Pos)             /* (LCDC_LCDIMR) Row Interrupt Mask Mask */
#define LCDC_LCDIMR_ROWIM(value)              (LCDC_LCDIMR_ROWIM_Msk & (_UINT32_(value) << LCDC_LCDIMR_ROWIM_Pos)) /* Assigment of value for ROWIM in the LCDC_LCDIMR register */
#define LCDC_LCDIMR_FIFOERRIM_Pos             _UINT32_(4)                                          /* (LCDC_LCDIMR) Output FIFO Error Interrupt Mask Position */
#define LCDC_LCDIMR_FIFOERRIM_Msk             (_UINT32_(0x1) << LCDC_LCDIMR_FIFOERRIM_Pos)         /* (LCDC_LCDIMR) Output FIFO Error Interrupt Mask Mask */
#define LCDC_LCDIMR_FIFOERRIM(value)          (LCDC_LCDIMR_FIFOERRIM_Msk & (_UINT32_(value) << LCDC_LCDIMR_FIFOERRIM_Pos)) /* Assigment of value for FIFOERRIM in the LCDC_LCDIMR register */
#define LCDC_LCDIMR_BASEIM_Pos                _UINT32_(8)                                          /* (LCDC_LCDIMR) Base Layer Interrupt Mask Position */
#define LCDC_LCDIMR_BASEIM_Msk                (_UINT32_(0x1) << LCDC_LCDIMR_BASEIM_Pos)            /* (LCDC_LCDIMR) Base Layer Interrupt Mask Mask */
#define LCDC_LCDIMR_BASEIM(value)             (LCDC_LCDIMR_BASEIM_Msk & (_UINT32_(value) << LCDC_LCDIMR_BASEIM_Pos)) /* Assigment of value for BASEIM in the LCDC_LCDIMR register */
#define LCDC_LCDIMR_OVR1IM_Pos                _UINT32_(9)                                          /* (LCDC_LCDIMR) Overlay 1 Interrupt Mask Position */
#define LCDC_LCDIMR_OVR1IM_Msk                (_UINT32_(0x1) << LCDC_LCDIMR_OVR1IM_Pos)            /* (LCDC_LCDIMR) Overlay 1 Interrupt Mask Mask */
#define LCDC_LCDIMR_OVR1IM(value)             (LCDC_LCDIMR_OVR1IM_Msk & (_UINT32_(value) << LCDC_LCDIMR_OVR1IM_Pos)) /* Assigment of value for OVR1IM in the LCDC_LCDIMR register */
#define LCDC_LCDIMR_OVR2IM_Pos                _UINT32_(10)                                         /* (LCDC_LCDIMR) Overlay 2 Interrupt Mask Position */
#define LCDC_LCDIMR_OVR2IM_Msk                (_UINT32_(0x1) << LCDC_LCDIMR_OVR2IM_Pos)            /* (LCDC_LCDIMR) Overlay 2 Interrupt Mask Mask */
#define LCDC_LCDIMR_OVR2IM(value)             (LCDC_LCDIMR_OVR2IM_Msk & (_UINT32_(value) << LCDC_LCDIMR_OVR2IM_Pos)) /* Assigment of value for OVR2IM in the LCDC_LCDIMR register */
#define LCDC_LCDIMR_HEOIM_Pos                 _UINT32_(11)                                         /* (LCDC_LCDIMR) High-End Overlay Interrupt Mask Position */
#define LCDC_LCDIMR_HEOIM_Msk                 (_UINT32_(0x1) << LCDC_LCDIMR_HEOIM_Pos)             /* (LCDC_LCDIMR) High-End Overlay Interrupt Mask Mask */
#define LCDC_LCDIMR_HEOIM(value)              (LCDC_LCDIMR_HEOIM_Msk & (_UINT32_(value) << LCDC_LCDIMR_HEOIM_Pos)) /* Assigment of value for HEOIM in the LCDC_LCDIMR register */
#define LCDC_LCDIMR_WPIM_Pos                  _UINT32_(31)                                         /* (LCDC_LCDIMR) Write Protection Interrupt Mask Position */
#define LCDC_LCDIMR_WPIM_Msk                  (_UINT32_(0x1) << LCDC_LCDIMR_WPIM_Pos)              /* (LCDC_LCDIMR) Write Protection Interrupt Mask Mask */
#define LCDC_LCDIMR_WPIM(value)               (LCDC_LCDIMR_WPIM_Msk & (_UINT32_(value) << LCDC_LCDIMR_WPIM_Pos)) /* Assigment of value for WPIM in the LCDC_LCDIMR register */
#define LCDC_LCDIMR_Msk                       _UINT32_(0x80000F1F)                                 /* (LCDC_LCDIMR) Register Mask  */


/* -------- LCDC_LCDISR : (LCDC Offset: 0x38) ( R/ 32) Interrupt Status Register -------- */
#define LCDC_LCDISR_RESETVALUE                _UINT32_(0x00)                                       /*  (LCDC_LCDISR) Interrupt Status Register  Reset Value */

#define LCDC_LCDISR_SOF_Pos                   _UINT32_(0)                                          /* (LCDC_LCDISR) Start of Frame Interrupt Status Position */
#define LCDC_LCDISR_SOF_Msk                   (_UINT32_(0x1) << LCDC_LCDISR_SOF_Pos)               /* (LCDC_LCDISR) Start of Frame Interrupt Status Mask */
#define LCDC_LCDISR_SOF(value)                (LCDC_LCDISR_SOF_Msk & (_UINT32_(value) << LCDC_LCDISR_SOF_Pos)) /* Assigment of value for SOF in the LCDC_LCDISR register */
#define   LCDC_LCDISR_SOF_0_Val               _UINT32_(0x0)                                        /* (LCDC_LCDISR) No detection since last read of LCDC_LCDISR.  */
#define   LCDC_LCDISR_SOF_1_Val               _UINT32_(0x1)                                        /* (LCDC_LCDISR) Indicates that a start of frame event has been detected. This flag is reset after a read operation.  */
#define LCDC_LCDISR_SOF_0                     (LCDC_LCDISR_SOF_0_Val << LCDC_LCDISR_SOF_Pos)       /* (LCDC_LCDISR) No detection since last read of LCDC_LCDISR. Position  */
#define LCDC_LCDISR_SOF_1                     (LCDC_LCDISR_SOF_1_Val << LCDC_LCDISR_SOF_Pos)       /* (LCDC_LCDISR) Indicates that a start of frame event has been detected. This flag is reset after a read operation. Position  */
#define LCDC_LCDISR_DIS_Pos                   _UINT32_(1)                                          /* (LCDC_LCDISR) LCD Disable Interrupt Status Position */
#define LCDC_LCDISR_DIS_Msk                   (_UINT32_(0x1) << LCDC_LCDISR_DIS_Pos)               /* (LCDC_LCDISR) LCD Disable Interrupt Status Mask */
#define LCDC_LCDISR_DIS(value)                (LCDC_LCDISR_DIS_Msk & (_UINT32_(value) << LCDC_LCDISR_DIS_Pos)) /* Assigment of value for DIS in the LCDC_LCDISR register */
#define   LCDC_LCDISR_DIS_0_Val               _UINT32_(0x0)                                        /* (LCDC_LCDISR) Horizontal and vertical timing generator has not yet been disabled.  */
#define   LCDC_LCDISR_DIS_1_Val               _UINT32_(0x1)                                        /* (LCDC_LCDISR) Indicates that the horizontal and vertical timing generator has been disabled. This flag is reset after a read operation.  */
#define LCDC_LCDISR_DIS_0                     (LCDC_LCDISR_DIS_0_Val << LCDC_LCDISR_DIS_Pos)       /* (LCDC_LCDISR) Horizontal and vertical timing generator has not yet been disabled. Position  */
#define LCDC_LCDISR_DIS_1                     (LCDC_LCDISR_DIS_1_Val << LCDC_LCDISR_DIS_Pos)       /* (LCDC_LCDISR) Indicates that the horizontal and vertical timing generator has been disabled. This flag is reset after a read operation. Position  */
#define LCDC_LCDISR_DISP_Pos                  _UINT32_(2)                                          /* (LCDC_LCDISR) Power-up/Power-down Sequence Terminated Interrupt Status Position */
#define LCDC_LCDISR_DISP_Msk                  (_UINT32_(0x1) << LCDC_LCDISR_DISP_Pos)              /* (LCDC_LCDISR) Power-up/Power-down Sequence Terminated Interrupt Status Mask */
#define LCDC_LCDISR_DISP(value)               (LCDC_LCDISR_DISP_Msk & (_UINT32_(value) << LCDC_LCDISR_DISP_Pos)) /* Assigment of value for DISP in the LCDC_LCDISR register */
#define   LCDC_LCDISR_DISP_0_Val              _UINT32_(0x0)                                        /* (LCDC_LCDISR) Power-up sequence or power-down sequence has not yet terminated.  */
#define   LCDC_LCDISR_DISP_1_Val              _UINT32_(0x1)                                        /* (LCDC_LCDISR) Indicates the power-up sequence or power-down sequence has terminated. This flag is reset after a read operation.  */
#define LCDC_LCDISR_DISP_0                    (LCDC_LCDISR_DISP_0_Val << LCDC_LCDISR_DISP_Pos)     /* (LCDC_LCDISR) Power-up sequence or power-down sequence has not yet terminated. Position  */
#define LCDC_LCDISR_DISP_1                    (LCDC_LCDISR_DISP_1_Val << LCDC_LCDISR_DISP_Pos)     /* (LCDC_LCDISR) Indicates the power-up sequence or power-down sequence has terminated. This flag is reset after a read operation. Position  */
#define LCDC_LCDISR_ROW_Pos                   _UINT32_(3)                                          /* (LCDC_LCDISR) Row Interrupt Status Position */
#define LCDC_LCDISR_ROW_Msk                   (_UINT32_(0x1) << LCDC_LCDISR_ROW_Pos)               /* (LCDC_LCDISR) Row Interrupt Status Mask */
#define LCDC_LCDISR_ROW(value)                (LCDC_LCDISR_ROW_Msk & (_UINT32_(value) << LCDC_LCDISR_ROW_Pos)) /* Assigment of value for ROW in the LCDC_LCDISR register */
#define   LCDC_LCDISR_ROW_0_Val               _UINT32_(0x0)                                        /* (LCDC_LCDISR) No detection since last read of the LCDC_LCDCISR.  */
#define   LCDC_LCDISR_ROW_1_Val               _UINT32_(0x1)                                        /* (LCDC_LCDISR) Indicates that a row event has been detected. This flag is reset after a read operation.  */
#define LCDC_LCDISR_ROW_0                     (LCDC_LCDISR_ROW_0_Val << LCDC_LCDISR_ROW_Pos)       /* (LCDC_LCDISR) No detection since last read of the LCDC_LCDCISR. Position  */
#define LCDC_LCDISR_ROW_1                     (LCDC_LCDISR_ROW_1_Val << LCDC_LCDISR_ROW_Pos)       /* (LCDC_LCDISR) Indicates that a row event has been detected. This flag is reset after a read operation. Position  */
#define LCDC_LCDISR_FIFOERR_Pos               _UINT32_(4)                                          /* (LCDC_LCDISR) Output FIFO Error Position */
#define LCDC_LCDISR_FIFOERR_Msk               (_UINT32_(0x1) << LCDC_LCDISR_FIFOERR_Pos)           /* (LCDC_LCDISR) Output FIFO Error Mask */
#define LCDC_LCDISR_FIFOERR(value)            (LCDC_LCDISR_FIFOERR_Msk & (_UINT32_(value) << LCDC_LCDISR_FIFOERR_Pos)) /* Assigment of value for FIFOERR in the LCDC_LCDISR register */
#define   LCDC_LCDISR_FIFOERR_0_Val           _UINT32_(0x0)                                        /* (LCDC_LCDISR) No underflow has occurred in the output FIFO since last read of LCDC_LCDISR.  */
#define   LCDC_LCDISR_FIFOERR_1_Val           _UINT32_(0x1)                                        /* (LCDC_LCDISR) Indicates that an underflow has occurred in the output FIFO. This flag is reset after a read operation.  */
#define LCDC_LCDISR_FIFOERR_0                 (LCDC_LCDISR_FIFOERR_0_Val << LCDC_LCDISR_FIFOERR_Pos) /* (LCDC_LCDISR) No underflow has occurred in the output FIFO since last read of LCDC_LCDISR. Position  */
#define LCDC_LCDISR_FIFOERR_1                 (LCDC_LCDISR_FIFOERR_1_Val << LCDC_LCDISR_FIFOERR_Pos) /* (LCDC_LCDISR) Indicates that an underflow has occurred in the output FIFO. This flag is reset after a read operation. Position  */
#define LCDC_LCDISR_BASE_Pos                  _UINT32_(8)                                          /* (LCDC_LCDISR) Base Layer Raw Interrupt Status Position */
#define LCDC_LCDISR_BASE_Msk                  (_UINT32_(0x1) << LCDC_LCDISR_BASE_Pos)              /* (LCDC_LCDISR) Base Layer Raw Interrupt Status Mask */
#define LCDC_LCDISR_BASE(value)               (LCDC_LCDISR_BASE_Msk & (_UINT32_(value) << LCDC_LCDISR_BASE_Pos)) /* Assigment of value for BASE in the LCDC_LCDISR register */
#define   LCDC_LCDISR_BASE_0_Val              _UINT32_(0x0)                                        /* (LCDC_LCDISR) No base layer interrupt detected since last read of LCDC_BASEISR.  */
#define   LCDC_LCDISR_BASE_1_Val              _UINT32_(0x1)                                        /* (LCDC_LCDISR) Indicates that a base layer interrupt is pending. This flag is reset as soon as the LCDC_BASEISR is read.  */
#define LCDC_LCDISR_BASE_0                    (LCDC_LCDISR_BASE_0_Val << LCDC_LCDISR_BASE_Pos)     /* (LCDC_LCDISR) No base layer interrupt detected since last read of LCDC_BASEISR. Position  */
#define LCDC_LCDISR_BASE_1                    (LCDC_LCDISR_BASE_1_Val << LCDC_LCDISR_BASE_Pos)     /* (LCDC_LCDISR) Indicates that a base layer interrupt is pending. This flag is reset as soon as the LCDC_BASEISR is read. Position  */
#define LCDC_LCDISR_OVR1_Pos                  _UINT32_(9)                                          /* (LCDC_LCDISR) Overlay 1 Raw Interrupt Status Position */
#define LCDC_LCDISR_OVR1_Msk                  (_UINT32_(0x1) << LCDC_LCDISR_OVR1_Pos)              /* (LCDC_LCDISR) Overlay 1 Raw Interrupt Status Mask */
#define LCDC_LCDISR_OVR1(value)               (LCDC_LCDISR_OVR1_Msk & (_UINT32_(value) << LCDC_LCDISR_OVR1_Pos)) /* Assigment of value for OVR1 in the LCDC_LCDISR register */
#define   LCDC_LCDISR_OVR1_0_Val              _UINT32_(0x0)                                        /* (LCDC_LCDISR) No Overlay 1 layer interrupt detected since last read of LCDC_OVR1ISR.  */
#define   LCDC_LCDISR_OVR1_1_Val              _UINT32_(0x1)                                        /* (LCDC_LCDISR) Indicates that an Overlay 1 layer interrupt is pending. This flag is reset as soon as the LCDC_OVR1ISR is read.  */
#define LCDC_LCDISR_OVR1_0                    (LCDC_LCDISR_OVR1_0_Val << LCDC_LCDISR_OVR1_Pos)     /* (LCDC_LCDISR) No Overlay 1 layer interrupt detected since last read of LCDC_OVR1ISR. Position  */
#define LCDC_LCDISR_OVR1_1                    (LCDC_LCDISR_OVR1_1_Val << LCDC_LCDISR_OVR1_Pos)     /* (LCDC_LCDISR) Indicates that an Overlay 1 layer interrupt is pending. This flag is reset as soon as the LCDC_OVR1ISR is read. Position  */
#define LCDC_LCDISR_OVR2_Pos                  _UINT32_(10)                                         /* (LCDC_LCDISR) Overlay 2 Raw Interrupt Status Position */
#define LCDC_LCDISR_OVR2_Msk                  (_UINT32_(0x1) << LCDC_LCDISR_OVR2_Pos)              /* (LCDC_LCDISR) Overlay 2 Raw Interrupt Status Mask */
#define LCDC_LCDISR_OVR2(value)               (LCDC_LCDISR_OVR2_Msk & (_UINT32_(value) << LCDC_LCDISR_OVR2_Pos)) /* Assigment of value for OVR2 in the LCDC_LCDISR register */
#define   LCDC_LCDISR_OVR2_0_Val              _UINT32_(0x0)                                        /* (LCDC_LCDISR) No Overlay 2 layer interrupt detected since last read of LCDC_OVR2ISR.  */
#define   LCDC_LCDISR_OVR2_1_Val              _UINT32_(0x1)                                        /* (LCDC_LCDISR) Indicates that an Overlay 2 layer interrupt is pending. This flag is reset as soon as the LCDC_OVR2ISR is read.  */
#define LCDC_LCDISR_OVR2_0                    (LCDC_LCDISR_OVR2_0_Val << LCDC_LCDISR_OVR2_Pos)     /* (LCDC_LCDISR) No Overlay 2 layer interrupt detected since last read of LCDC_OVR2ISR. Position  */
#define LCDC_LCDISR_OVR2_1                    (LCDC_LCDISR_OVR2_1_Val << LCDC_LCDISR_OVR2_Pos)     /* (LCDC_LCDISR) Indicates that an Overlay 2 layer interrupt is pending. This flag is reset as soon as the LCDC_OVR2ISR is read. Position  */
#define LCDC_LCDISR_HEO_Pos                   _UINT32_(11)                                         /* (LCDC_LCDISR) High-End Overlay Raw Interrupt Status Position */
#define LCDC_LCDISR_HEO_Msk                   (_UINT32_(0x1) << LCDC_LCDISR_HEO_Pos)               /* (LCDC_LCDISR) High-End Overlay Raw Interrupt Status Mask */
#define LCDC_LCDISR_HEO(value)                (LCDC_LCDISR_HEO_Msk & (_UINT32_(value) << LCDC_LCDISR_HEO_Pos)) /* Assigment of value for HEO in the LCDC_LCDISR register */
#define   LCDC_LCDISR_HEO_0_Val               _UINT32_(0x0)                                        /* (LCDC_LCDISR) No High-End layer interrupt detected since last read of LCDC_HEOISR.  */
#define   LCDC_LCDISR_HEO_1_Val               _UINT32_(0x1)                                        /* (LCDC_LCDISR) Indicates that a High-End layer interrupt is pending. This flag is reset as soon as the LCDC_HEOISR is read.  */
#define LCDC_LCDISR_HEO_0                     (LCDC_LCDISR_HEO_0_Val << LCDC_LCDISR_HEO_Pos)       /* (LCDC_LCDISR) No High-End layer interrupt detected since last read of LCDC_HEOISR. Position  */
#define LCDC_LCDISR_HEO_1                     (LCDC_LCDISR_HEO_1_Val << LCDC_LCDISR_HEO_Pos)       /* (LCDC_LCDISR) Indicates that a High-End layer interrupt is pending. This flag is reset as soon as the LCDC_HEOISR is read. Position  */
#define LCDC_LCDISR_WP_Pos                    _UINT32_(31)                                         /* (LCDC_LCDISR) Write Protection Interrupt Status Position */
#define LCDC_LCDISR_WP_Msk                    (_UINT32_(0x1) << LCDC_LCDISR_WP_Pos)                /* (LCDC_LCDISR) Write Protection Interrupt Status Mask */
#define LCDC_LCDISR_WP(value)                 (LCDC_LCDISR_WP_Msk & (_UINT32_(value) << LCDC_LCDISR_WP_Pos)) /* Assigment of value for WP in the LCDC_LCDISR register */
#define   LCDC_LCDISR_WP_0_Val                _UINT32_(0x0)                                        /* (LCDC_LCDISR) No Write Protection interrupt detected since last read of LCDC_WPSR  */
#define   LCDC_LCDISR_WP_1_Val                _UINT32_(0x1)                                        /* (LCDC_LCDISR) Indicates that Write Protection interrupt is pending. This flag is reset as soon as the LCDC_WPSR is read.  */
#define LCDC_LCDISR_WP_0                      (LCDC_LCDISR_WP_0_Val << LCDC_LCDISR_WP_Pos)         /* (LCDC_LCDISR) No Write Protection interrupt detected since last read of LCDC_WPSR Position  */
#define LCDC_LCDISR_WP_1                      (LCDC_LCDISR_WP_1_Val << LCDC_LCDISR_WP_Pos)         /* (LCDC_LCDISR) Indicates that Write Protection interrupt is pending. This flag is reset as soon as the LCDC_WPSR is read. Position  */
#define LCDC_LCDISR_Msk                       _UINT32_(0x80000F1F)                                 /* (LCDC_LCDISR) Register Mask  */

#define LCDC_LCDISR_OVR_Pos                   _UINT32_(9)                                          /* (LCDC_LCDISR Position) Overlay x Raw Interrupt Status */
#define LCDC_LCDISR_OVR_Msk                   (_UINT32_(0x3) << LCDC_LCDISR_OVR_Pos)               /* (LCDC_LCDISR Mask) OVR */
#define LCDC_LCDISR_OVR(value)                (LCDC_LCDISR_OVR_Msk & (_UINT32_(value) << LCDC_LCDISR_OVR_Pos)) 

/* -------- LCDC_ATTRE : (LCDC Offset: 0x3C) ( /W 32) Attribute Enable Register -------- */
#define LCDC_ATTRE_BASE_Pos                   _UINT32_(0)                                          /* (LCDC_ATTRE) Base Layer Update Attribute Position */
#define LCDC_ATTRE_BASE_Msk                   (_UINT32_(0x1) << LCDC_ATTRE_BASE_Pos)               /* (LCDC_ATTRE) Base Layer Update Attribute Mask */
#define LCDC_ATTRE_BASE(value)                (LCDC_ATTRE_BASE_Msk & (_UINT32_(value) << LCDC_ATTRE_BASE_Pos)) /* Assigment of value for BASE in the LCDC_ATTRE register */
#define   LCDC_ATTRE_BASE_0_Val               _UINT32_(0x0)                                        /* (LCDC_ATTRE) No effect.  */
#define   LCDC_ATTRE_BASE_1_Val               _UINT32_(0x1)                                        /* (LCDC_ATTRE) Updates the base window attributes.  */
#define LCDC_ATTRE_BASE_0                     (LCDC_ATTRE_BASE_0_Val << LCDC_ATTRE_BASE_Pos)       /* (LCDC_ATTRE) No effect. Position  */
#define LCDC_ATTRE_BASE_1                     (LCDC_ATTRE_BASE_1_Val << LCDC_ATTRE_BASE_Pos)       /* (LCDC_ATTRE) Updates the base window attributes. Position  */
#define LCDC_ATTRE_OVR1_Pos                   _UINT32_(1)                                          /* (LCDC_ATTRE) Overlay 1 Update Attribute Position */
#define LCDC_ATTRE_OVR1_Msk                   (_UINT32_(0x1) << LCDC_ATTRE_OVR1_Pos)               /* (LCDC_ATTRE) Overlay 1 Update Attribute Mask */
#define LCDC_ATTRE_OVR1(value)                (LCDC_ATTRE_OVR1_Msk & (_UINT32_(value) << LCDC_ATTRE_OVR1_Pos)) /* Assigment of value for OVR1 in the LCDC_ATTRE register */
#define   LCDC_ATTRE_OVR1_0_Val               _UINT32_(0x0)                                        /* (LCDC_ATTRE) No effect.  */
#define   LCDC_ATTRE_OVR1_1_Val               _UINT32_(0x1)                                        /* (LCDC_ATTRE) Updates the OVR1 window attribute.  */
#define LCDC_ATTRE_OVR1_0                     (LCDC_ATTRE_OVR1_0_Val << LCDC_ATTRE_OVR1_Pos)       /* (LCDC_ATTRE) No effect. Position  */
#define LCDC_ATTRE_OVR1_1                     (LCDC_ATTRE_OVR1_1_Val << LCDC_ATTRE_OVR1_Pos)       /* (LCDC_ATTRE) Updates the OVR1 window attribute. Position  */
#define LCDC_ATTRE_OVR2_Pos                   _UINT32_(2)                                          /* (LCDC_ATTRE) Overlay 2 Update Attribute Position */
#define LCDC_ATTRE_OVR2_Msk                   (_UINT32_(0x1) << LCDC_ATTRE_OVR2_Pos)               /* (LCDC_ATTRE) Overlay 2 Update Attribute Mask */
#define LCDC_ATTRE_OVR2(value)                (LCDC_ATTRE_OVR2_Msk & (_UINT32_(value) << LCDC_ATTRE_OVR2_Pos)) /* Assigment of value for OVR2 in the LCDC_ATTRE register */
#define   LCDC_ATTRE_OVR2_0_Val               _UINT32_(0x0)                                        /* (LCDC_ATTRE) No effect.  */
#define   LCDC_ATTRE_OVR2_1_Val               _UINT32_(0x1)                                        /* (LCDC_ATTRE) Updates the OVR2 window attribute.  */
#define LCDC_ATTRE_OVR2_0                     (LCDC_ATTRE_OVR2_0_Val << LCDC_ATTRE_OVR2_Pos)       /* (LCDC_ATTRE) No effect. Position  */
#define LCDC_ATTRE_OVR2_1                     (LCDC_ATTRE_OVR2_1_Val << LCDC_ATTRE_OVR2_Pos)       /* (LCDC_ATTRE) Updates the OVR2 window attribute. Position  */
#define LCDC_ATTRE_HEO_Pos                    _UINT32_(3)                                          /* (LCDC_ATTRE) High-End Overlay Update Attribute Position */
#define LCDC_ATTRE_HEO_Msk                    (_UINT32_(0x1) << LCDC_ATTRE_HEO_Pos)                /* (LCDC_ATTRE) High-End Overlay Update Attribute Mask */
#define LCDC_ATTRE_HEO(value)                 (LCDC_ATTRE_HEO_Msk & (_UINT32_(value) << LCDC_ATTRE_HEO_Pos)) /* Assigment of value for HEO in the LCDC_ATTRE register */
#define   LCDC_ATTRE_HEO_0_Val                _UINT32_(0x0)                                        /* (LCDC_ATTRE) No effect.  */
#define   LCDC_ATTRE_HEO_1_Val                _UINT32_(0x1)                                        /* (LCDC_ATTRE) Updates the HEO window attribute.  */
#define LCDC_ATTRE_HEO_0                      (LCDC_ATTRE_HEO_0_Val << LCDC_ATTRE_HEO_Pos)         /* (LCDC_ATTRE) No effect. Position  */
#define LCDC_ATTRE_HEO_1                      (LCDC_ATTRE_HEO_1_Val << LCDC_ATTRE_HEO_Pos)         /* (LCDC_ATTRE) Updates the HEO window attribute. Position  */
#define LCDC_ATTRE_BASECL_Pos                 _UINT32_(8)                                          /* (LCDC_ATTRE) Base Layer Update Color LUT Position */
#define LCDC_ATTRE_BASECL_Msk                 (_UINT32_(0x1) << LCDC_ATTRE_BASECL_Pos)             /* (LCDC_ATTRE) Base Layer Update Color LUT Mask */
#define LCDC_ATTRE_BASECL(value)              (LCDC_ATTRE_BASECL_Msk & (_UINT32_(value) << LCDC_ATTRE_BASECL_Pos)) /* Assigment of value for BASECL in the LCDC_ATTRE register */
#define   LCDC_ATTRE_BASECL_0_Val             _UINT32_(0x0)                                        /* (LCDC_ATTRE) No effect.  */
#define   LCDC_ATTRE_BASECL_1_Val             _UINT32_(0x1)                                        /* (LCDC_ATTRE) DMA update request for the base layer CLUT content.  */
#define LCDC_ATTRE_BASECL_0                   (LCDC_ATTRE_BASECL_0_Val << LCDC_ATTRE_BASECL_Pos)   /* (LCDC_ATTRE) No effect. Position  */
#define LCDC_ATTRE_BASECL_1                   (LCDC_ATTRE_BASECL_1_Val << LCDC_ATTRE_BASECL_Pos)   /* (LCDC_ATTRE) DMA update request for the base layer CLUT content. Position  */
#define LCDC_ATTRE_OVR1CL_Pos                 _UINT32_(9)                                          /* (LCDC_ATTRE) Overlay 1 Update Color LUT Position */
#define LCDC_ATTRE_OVR1CL_Msk                 (_UINT32_(0x1) << LCDC_ATTRE_OVR1CL_Pos)             /* (LCDC_ATTRE) Overlay 1 Update Color LUT Mask */
#define LCDC_ATTRE_OVR1CL(value)              (LCDC_ATTRE_OVR1CL_Msk & (_UINT32_(value) << LCDC_ATTRE_OVR1CL_Pos)) /* Assigment of value for OVR1CL in the LCDC_ATTRE register */
#define   LCDC_ATTRE_OVR1CL_0_Val             _UINT32_(0x0)                                        /* (LCDC_ATTRE) No effect.  */
#define   LCDC_ATTRE_OVR1CL_1_Val             _UINT32_(0x1)                                        /* (LCDC_ATTRE) DMA update request for the OVR1 layer CLUT content.  */
#define LCDC_ATTRE_OVR1CL_0                   (LCDC_ATTRE_OVR1CL_0_Val << LCDC_ATTRE_OVR1CL_Pos)   /* (LCDC_ATTRE) No effect. Position  */
#define LCDC_ATTRE_OVR1CL_1                   (LCDC_ATTRE_OVR1CL_1_Val << LCDC_ATTRE_OVR1CL_Pos)   /* (LCDC_ATTRE) DMA update request for the OVR1 layer CLUT content. Position  */
#define LCDC_ATTRE_OVR2CL_Pos                 _UINT32_(10)                                         /* (LCDC_ATTRE) Overlay 2 Update Color LUT Position */
#define LCDC_ATTRE_OVR2CL_Msk                 (_UINT32_(0x1) << LCDC_ATTRE_OVR2CL_Pos)             /* (LCDC_ATTRE) Overlay 2 Update Color LUT Mask */
#define LCDC_ATTRE_OVR2CL(value)              (LCDC_ATTRE_OVR2CL_Msk & (_UINT32_(value) << LCDC_ATTRE_OVR2CL_Pos)) /* Assigment of value for OVR2CL in the LCDC_ATTRE register */
#define   LCDC_ATTRE_OVR2CL_0_Val             _UINT32_(0x0)                                        /* (LCDC_ATTRE) No effect.  */
#define   LCDC_ATTRE_OVR2CL_1_Val             _UINT32_(0x1)                                        /* (LCDC_ATTRE) DMA update request for the OVR2 layer CLUT content.  */
#define LCDC_ATTRE_OVR2CL_0                   (LCDC_ATTRE_OVR2CL_0_Val << LCDC_ATTRE_OVR2CL_Pos)   /* (LCDC_ATTRE) No effect. Position  */
#define LCDC_ATTRE_OVR2CL_1                   (LCDC_ATTRE_OVR2CL_1_Val << LCDC_ATTRE_OVR2CL_Pos)   /* (LCDC_ATTRE) DMA update request for the OVR2 layer CLUT content. Position  */
#define LCDC_ATTRE_HEOCL_Pos                  _UINT32_(11)                                         /* (LCDC_ATTRE) High-End Overlay Update Color LUT Position */
#define LCDC_ATTRE_HEOCL_Msk                  (_UINT32_(0x1) << LCDC_ATTRE_HEOCL_Pos)              /* (LCDC_ATTRE) High-End Overlay Update Color LUT Mask */
#define LCDC_ATTRE_HEOCL(value)               (LCDC_ATTRE_HEOCL_Msk & (_UINT32_(value) << LCDC_ATTRE_HEOCL_Pos)) /* Assigment of value for HEOCL in the LCDC_ATTRE register */
#define   LCDC_ATTRE_HEOCL_0_Val              _UINT32_(0x0)                                        /* (LCDC_ATTRE) No effect.  */
#define   LCDC_ATTRE_HEOCL_1_Val              _UINT32_(0x1)                                        /* (LCDC_ATTRE) DMA update request for the HEO layer CLUT content.  */
#define LCDC_ATTRE_HEOCL_0                    (LCDC_ATTRE_HEOCL_0_Val << LCDC_ATTRE_HEOCL_Pos)     /* (LCDC_ATTRE) No effect. Position  */
#define LCDC_ATTRE_HEOCL_1                    (LCDC_ATTRE_HEOCL_1_Val << LCDC_ATTRE_HEOCL_Pos)     /* (LCDC_ATTRE) DMA update request for the HEO layer CLUT content. Position  */
#define LCDC_ATTRE_Msk                        _UINT32_(0x00000F0F)                                 /* (LCDC_ATTRE) Register Mask  */

#define LCDC_ATTRE_OVR_Pos                    _UINT32_(1)                                          /* (LCDC_ATTRE Position) Overlay x Update Attribute */
#define LCDC_ATTRE_OVR_Msk                    (_UINT32_(0x3) << LCDC_ATTRE_OVR_Pos)                /* (LCDC_ATTRE Mask) OVR */
#define LCDC_ATTRE_OVR(value)                 (LCDC_ATTRE_OVR_Msk & (_UINT32_(value) << LCDC_ATTRE_OVR_Pos)) 

/* -------- LCDC_ATTRS : (LCDC Offset: 0x40) ( R/ 32) Attribute Status Register -------- */
#define LCDC_ATTRS_RESETVALUE                 _UINT32_(0x00)                                       /*  (LCDC_ATTRS) Attribute Status Register  Reset Value */

#define LCDC_ATTRS_BASE_Pos                   _UINT32_(0)                                          /* (LCDC_ATTRS) Base Layer Update Status Position */
#define LCDC_ATTRS_BASE_Msk                   (_UINT32_(0x1) << LCDC_ATTRS_BASE_Pos)               /* (LCDC_ATTRS) Base Layer Update Status Mask */
#define LCDC_ATTRS_BASE(value)                (LCDC_ATTRS_BASE_Msk & (_UINT32_(value) << LCDC_ATTRS_BASE_Pos)) /* Assigment of value for BASE in the LCDC_ATTRS register */
#define   LCDC_ATTRS_BASE_0_Val               _UINT32_(0x0)                                        /* (LCDC_ATTRS) No effect.  */
#define   LCDC_ATTRS_BASE_1_Val               _UINT32_(0x1)                                        /* (LCDC_ATTRS) Indicates that an update request is pending for the base layer.  */
#define LCDC_ATTRS_BASE_0                     (LCDC_ATTRS_BASE_0_Val << LCDC_ATTRS_BASE_Pos)       /* (LCDC_ATTRS) No effect. Position  */
#define LCDC_ATTRS_BASE_1                     (LCDC_ATTRS_BASE_1_Val << LCDC_ATTRS_BASE_Pos)       /* (LCDC_ATTRS) Indicates that an update request is pending for the base layer. Position  */
#define LCDC_ATTRS_OVR1_Pos                   _UINT32_(1)                                          /* (LCDC_ATTRS) Overlay 1 Update Status Position */
#define LCDC_ATTRS_OVR1_Msk                   (_UINT32_(0x1) << LCDC_ATTRS_OVR1_Pos)               /* (LCDC_ATTRS) Overlay 1 Update Status Mask */
#define LCDC_ATTRS_OVR1(value)                (LCDC_ATTRS_OVR1_Msk & (_UINT32_(value) << LCDC_ATTRS_OVR1_Pos)) /* Assigment of value for OVR1 in the LCDC_ATTRS register */
#define   LCDC_ATTRS_OVR1_0_Val               _UINT32_(0x0)                                        /* (LCDC_ATTRS) No effect.  */
#define   LCDC_ATTRS_OVR1_1_Val               _UINT32_(0x1)                                        /* (LCDC_ATTRS) Indicates that an update request is pending for the Overlay 1 layer.  */
#define LCDC_ATTRS_OVR1_0                     (LCDC_ATTRS_OVR1_0_Val << LCDC_ATTRS_OVR1_Pos)       /* (LCDC_ATTRS) No effect. Position  */
#define LCDC_ATTRS_OVR1_1                     (LCDC_ATTRS_OVR1_1_Val << LCDC_ATTRS_OVR1_Pos)       /* (LCDC_ATTRS) Indicates that an update request is pending for the Overlay 1 layer. Position  */
#define LCDC_ATTRS_OVR2_Pos                   _UINT32_(2)                                          /* (LCDC_ATTRS) Overlay 2 Update Status Position */
#define LCDC_ATTRS_OVR2_Msk                   (_UINT32_(0x1) << LCDC_ATTRS_OVR2_Pos)               /* (LCDC_ATTRS) Overlay 2 Update Status Mask */
#define LCDC_ATTRS_OVR2(value)                (LCDC_ATTRS_OVR2_Msk & (_UINT32_(value) << LCDC_ATTRS_OVR2_Pos)) /* Assigment of value for OVR2 in the LCDC_ATTRS register */
#define   LCDC_ATTRS_OVR2_0_Val               _UINT32_(0x0)                                        /* (LCDC_ATTRS) No effect.  */
#define   LCDC_ATTRS_OVR2_1_Val               _UINT32_(0x1)                                        /* (LCDC_ATTRS) Indicates that an update request is pending for the Overlay 2 layer.  */
#define LCDC_ATTRS_OVR2_0                     (LCDC_ATTRS_OVR2_0_Val << LCDC_ATTRS_OVR2_Pos)       /* (LCDC_ATTRS) No effect. Position  */
#define LCDC_ATTRS_OVR2_1                     (LCDC_ATTRS_OVR2_1_Val << LCDC_ATTRS_OVR2_Pos)       /* (LCDC_ATTRS) Indicates that an update request is pending for the Overlay 2 layer. Position  */
#define LCDC_ATTRS_HEO_Pos                    _UINT32_(3)                                          /* (LCDC_ATTRS) High-End Overlay Update Status Position */
#define LCDC_ATTRS_HEO_Msk                    (_UINT32_(0x1) << LCDC_ATTRS_HEO_Pos)                /* (LCDC_ATTRS) High-End Overlay Update Status Mask */
#define LCDC_ATTRS_HEO(value)                 (LCDC_ATTRS_HEO_Msk & (_UINT32_(value) << LCDC_ATTRS_HEO_Pos)) /* Assigment of value for HEO in the LCDC_ATTRS register */
#define   LCDC_ATTRS_HEO_0_Val                _UINT32_(0x0)                                        /* (LCDC_ATTRS) No effect.  */
#define   LCDC_ATTRS_HEO_1_Val                _UINT32_(0x1)                                        /* (LCDC_ATTRS) Indicates that an update request is pending for High-end Overlay.  */
#define LCDC_ATTRS_HEO_0                      (LCDC_ATTRS_HEO_0_Val << LCDC_ATTRS_HEO_Pos)         /* (LCDC_ATTRS) No effect. Position  */
#define LCDC_ATTRS_HEO_1                      (LCDC_ATTRS_HEO_1_Val << LCDC_ATTRS_HEO_Pos)         /* (LCDC_ATTRS) Indicates that an update request is pending for High-end Overlay. Position  */
#define LCDC_ATTRS_BASECL_Pos                 _UINT32_(8)                                          /* (LCDC_ATTRS) Base Layer Color Table Status Position */
#define LCDC_ATTRS_BASECL_Msk                 (_UINT32_(0x1) << LCDC_ATTRS_BASECL_Pos)             /* (LCDC_ATTRS) Base Layer Color Table Status Mask */
#define LCDC_ATTRS_BASECL(value)              (LCDC_ATTRS_BASECL_Msk & (_UINT32_(value) << LCDC_ATTRS_BASECL_Pos)) /* Assigment of value for BASECL in the LCDC_ATTRS register */
#define   LCDC_ATTRS_BASECL_0_Val             _UINT32_(0x0)                                        /* (LCDC_ATTRS) No effect.  */
#define   LCDC_ATTRS_BASECL_1_Val             _UINT32_(0x1)                                        /* (LCDC_ATTRS) Indicates that an update request is pending for the base CLUT.  */
#define LCDC_ATTRS_BASECL_0                   (LCDC_ATTRS_BASECL_0_Val << LCDC_ATTRS_BASECL_Pos)   /* (LCDC_ATTRS) No effect. Position  */
#define LCDC_ATTRS_BASECL_1                   (LCDC_ATTRS_BASECL_1_Val << LCDC_ATTRS_BASECL_Pos)   /* (LCDC_ATTRS) Indicates that an update request is pending for the base CLUT. Position  */
#define LCDC_ATTRS_OVR1CL_Pos                 _UINT32_(9)                                          /* (LCDC_ATTRS) Overlay 1 Color Table Status Position */
#define LCDC_ATTRS_OVR1CL_Msk                 (_UINT32_(0x1) << LCDC_ATTRS_OVR1CL_Pos)             /* (LCDC_ATTRS) Overlay 1 Color Table Status Mask */
#define LCDC_ATTRS_OVR1CL(value)              (LCDC_ATTRS_OVR1CL_Msk & (_UINT32_(value) << LCDC_ATTRS_OVR1CL_Pos)) /* Assigment of value for OVR1CL in the LCDC_ATTRS register */
#define   LCDC_ATTRS_OVR1CL_0_Val             _UINT32_(0x0)                                        /* (LCDC_ATTRS) No effect.  */
#define   LCDC_ATTRS_OVR1CL_1_Val             _UINT32_(0x1)                                        /* (LCDC_ATTRS) Indicates that an update request is pending for the Overlay 1 CLUT.  */
#define LCDC_ATTRS_OVR1CL_0                   (LCDC_ATTRS_OVR1CL_0_Val << LCDC_ATTRS_OVR1CL_Pos)   /* (LCDC_ATTRS) No effect. Position  */
#define LCDC_ATTRS_OVR1CL_1                   (LCDC_ATTRS_OVR1CL_1_Val << LCDC_ATTRS_OVR1CL_Pos)   /* (LCDC_ATTRS) Indicates that an update request is pending for the Overlay 1 CLUT. Position  */
#define LCDC_ATTRS_OVR2CL_Pos                 _UINT32_(10)                                         /* (LCDC_ATTRS) Overlay 2 Color Table Status Position */
#define LCDC_ATTRS_OVR2CL_Msk                 (_UINT32_(0x1) << LCDC_ATTRS_OVR2CL_Pos)             /* (LCDC_ATTRS) Overlay 2 Color Table Status Mask */
#define LCDC_ATTRS_OVR2CL(value)              (LCDC_ATTRS_OVR2CL_Msk & (_UINT32_(value) << LCDC_ATTRS_OVR2CL_Pos)) /* Assigment of value for OVR2CL in the LCDC_ATTRS register */
#define   LCDC_ATTRS_OVR2CL_0_Val             _UINT32_(0x0)                                        /* (LCDC_ATTRS) No effect.  */
#define   LCDC_ATTRS_OVR2CL_1_Val             _UINT32_(0x1)                                        /* (LCDC_ATTRS) Indicates that an update request is pending for the Overlay 2 CLUT.  */
#define LCDC_ATTRS_OVR2CL_0                   (LCDC_ATTRS_OVR2CL_0_Val << LCDC_ATTRS_OVR2CL_Pos)   /* (LCDC_ATTRS) No effect. Position  */
#define LCDC_ATTRS_OVR2CL_1                   (LCDC_ATTRS_OVR2CL_1_Val << LCDC_ATTRS_OVR2CL_Pos)   /* (LCDC_ATTRS) Indicates that an update request is pending for the Overlay 2 CLUT. Position  */
#define LCDC_ATTRS_HEOCL_Pos                  _UINT32_(11)                                         /* (LCDC_ATTRS) High-End Overlay Color Table Status Position */
#define LCDC_ATTRS_HEOCL_Msk                  (_UINT32_(0x1) << LCDC_ATTRS_HEOCL_Pos)              /* (LCDC_ATTRS) High-End Overlay Color Table Status Mask */
#define LCDC_ATTRS_HEOCL(value)               (LCDC_ATTRS_HEOCL_Msk & (_UINT32_(value) << LCDC_ATTRS_HEOCL_Pos)) /* Assigment of value for HEOCL in the LCDC_ATTRS register */
#define   LCDC_ATTRS_HEOCL_0_Val              _UINT32_(0x0)                                        /* (LCDC_ATTRS) No effect.  */
#define   LCDC_ATTRS_HEOCL_1_Val              _UINT32_(0x1)                                        /* (LCDC_ATTRS) Indicates that an update request is pending for the High-end Overlay CLUT.  */
#define LCDC_ATTRS_HEOCL_0                    (LCDC_ATTRS_HEOCL_0_Val << LCDC_ATTRS_HEOCL_Pos)     /* (LCDC_ATTRS) No effect. Position  */
#define LCDC_ATTRS_HEOCL_1                    (LCDC_ATTRS_HEOCL_1_Val << LCDC_ATTRS_HEOCL_Pos)     /* (LCDC_ATTRS) Indicates that an update request is pending for the High-end Overlay CLUT. Position  */
#define LCDC_ATTRS_SIP_Pos                    _UINT32_(31)                                         /* (LCDC_ATTRS) Synchronization In Progress Position */
#define LCDC_ATTRS_SIP_Msk                    (_UINT32_(0x1) << LCDC_ATTRS_SIP_Pos)                /* (LCDC_ATTRS) Synchronization In Progress Mask */
#define LCDC_ATTRS_SIP(value)                 (LCDC_ATTRS_SIP_Msk & (_UINT32_(value) << LCDC_ATTRS_SIP_Pos)) /* Assigment of value for SIP in the LCDC_ATTRS register */
#define   LCDC_ATTRS_SIP_0_Val                _UINT32_(0x0)                                        /* (LCDC_ATTRS) Clock domain synchronization is terminated.  */
#define   LCDC_ATTRS_SIP_1_Val                _UINT32_(0x1)                                        /* (LCDC_ATTRS) Synchronization is in progress. Access to LCDC_ATTRE has no effect.  */
#define LCDC_ATTRS_SIP_0                      (LCDC_ATTRS_SIP_0_Val << LCDC_ATTRS_SIP_Pos)         /* (LCDC_ATTRS) Clock domain synchronization is terminated. Position  */
#define LCDC_ATTRS_SIP_1                      (LCDC_ATTRS_SIP_1_Val << LCDC_ATTRS_SIP_Pos)         /* (LCDC_ATTRS) Synchronization is in progress. Access to LCDC_ATTRE has no effect. Position  */
#define LCDC_ATTRS_Msk                        _UINT32_(0x80000F0F)                                 /* (LCDC_ATTRS) Register Mask  */

#define LCDC_ATTRS_OVR_Pos                    _UINT32_(1)                                          /* (LCDC_ATTRS Position) Overlay x Update Status */
#define LCDC_ATTRS_OVR_Msk                    (_UINT32_(0x3) << LCDC_ATTRS_OVR_Pos)                /* (LCDC_ATTRS Mask) OVR */
#define LCDC_ATTRS_OVR(value)                 (LCDC_ATTRS_OVR_Msk & (_UINT32_(value) << LCDC_ATTRS_OVR_Pos)) 

/* -------- LCDC_BASEIER : (LCDC Offset: 0x60) ( /W 32) Base Layer Interrupt Enable Register -------- */
#define LCDC_BASEIER_END_Pos                  _UINT32_(0)                                          /* (LCDC_BASEIER) End of Frame DMA Transfer Interrupt Enable Position */
#define LCDC_BASEIER_END_Msk                  (_UINT32_(0x1) << LCDC_BASEIER_END_Pos)              /* (LCDC_BASEIER) End of Frame DMA Transfer Interrupt Enable Mask */
#define LCDC_BASEIER_END(value)               (LCDC_BASEIER_END_Msk & (_UINT32_(value) << LCDC_BASEIER_END_Pos)) /* Assigment of value for END in the LCDC_BASEIER register */
#define LCDC_BASEIER_ERROR_Pos                _UINT32_(1)                                          /* (LCDC_BASEIER) Transfer Error Detected Interrupt Enable Position */
#define LCDC_BASEIER_ERROR_Msk                (_UINT32_(0x1) << LCDC_BASEIER_ERROR_Pos)            /* (LCDC_BASEIER) Transfer Error Detected Interrupt Enable Mask */
#define LCDC_BASEIER_ERROR(value)             (LCDC_BASEIER_ERROR_Msk & (_UINT32_(value) << LCDC_BASEIER_ERROR_Pos)) /* Assigment of value for ERROR in the LCDC_BASEIER register */
#define LCDC_BASEIER_OVF_Pos                  _UINT32_(2)                                          /* (LCDC_BASEIER) Overflow Interrupt Enable Position */
#define LCDC_BASEIER_OVF_Msk                  (_UINT32_(0x1) << LCDC_BASEIER_OVF_Pos)              /* (LCDC_BASEIER) Overflow Interrupt Enable Mask */
#define LCDC_BASEIER_OVF(value)               (LCDC_BASEIER_OVF_Msk & (_UINT32_(value) << LCDC_BASEIER_OVF_Pos)) /* Assigment of value for OVF in the LCDC_BASEIER register */
#define LCDC_BASEIER_Msk                      _UINT32_(0x00000007)                                 /* (LCDC_BASEIER) Register Mask  */


/* -------- LCDC_BASEIDR : (LCDC Offset: 0x64) ( /W 32) Base Layer Interrupt Disable Register -------- */
#define LCDC_BASEIDR_END_Pos                  _UINT32_(0)                                          /* (LCDC_BASEIDR) End of Frame DMA Transfer Interrupt Disable Position */
#define LCDC_BASEIDR_END_Msk                  (_UINT32_(0x1) << LCDC_BASEIDR_END_Pos)              /* (LCDC_BASEIDR) End of Frame DMA Transfer Interrupt Disable Mask */
#define LCDC_BASEIDR_END(value)               (LCDC_BASEIDR_END_Msk & (_UINT32_(value) << LCDC_BASEIDR_END_Pos)) /* Assigment of value for END in the LCDC_BASEIDR register */
#define LCDC_BASEIDR_ERROR_Pos                _UINT32_(1)                                          /* (LCDC_BASEIDR) Transfer Error Interrupt Disable Position */
#define LCDC_BASEIDR_ERROR_Msk                (_UINT32_(0x1) << LCDC_BASEIDR_ERROR_Pos)            /* (LCDC_BASEIDR) Transfer Error Interrupt Disable Mask */
#define LCDC_BASEIDR_ERROR(value)             (LCDC_BASEIDR_ERROR_Msk & (_UINT32_(value) << LCDC_BASEIDR_ERROR_Pos)) /* Assigment of value for ERROR in the LCDC_BASEIDR register */
#define LCDC_BASEIDR_OVF_Pos                  _UINT32_(2)                                          /* (LCDC_BASEIDR) Overflow Interrupt Disable Position */
#define LCDC_BASEIDR_OVF_Msk                  (_UINT32_(0x1) << LCDC_BASEIDR_OVF_Pos)              /* (LCDC_BASEIDR) Overflow Interrupt Disable Mask */
#define LCDC_BASEIDR_OVF(value)               (LCDC_BASEIDR_OVF_Msk & (_UINT32_(value) << LCDC_BASEIDR_OVF_Pos)) /* Assigment of value for OVF in the LCDC_BASEIDR register */
#define LCDC_BASEIDR_Msk                      _UINT32_(0x00000007)                                 /* (LCDC_BASEIDR) Register Mask  */


/* -------- LCDC_BASEIMR : (LCDC Offset: 0x68) ( R/ 32) Base Layer Interrupt Mask Register -------- */
#define LCDC_BASEIMR_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_BASEIMR) Base Layer Interrupt Mask Register  Reset Value */

#define LCDC_BASEIMR_END_Pos                  _UINT32_(0)                                          /* (LCDC_BASEIMR) End of Frame DMA Transfer Interrupt Mask Position */
#define LCDC_BASEIMR_END_Msk                  (_UINT32_(0x1) << LCDC_BASEIMR_END_Pos)              /* (LCDC_BASEIMR) End of Frame DMA Transfer Interrupt Mask Mask */
#define LCDC_BASEIMR_END(value)               (LCDC_BASEIMR_END_Msk & (_UINT32_(value) << LCDC_BASEIMR_END_Pos)) /* Assigment of value for END in the LCDC_BASEIMR register */
#define LCDC_BASEIMR_ERROR_Pos                _UINT32_(1)                                          /* (LCDC_BASEIMR) Transfer Error Interrupt Mask Position */
#define LCDC_BASEIMR_ERROR_Msk                (_UINT32_(0x1) << LCDC_BASEIMR_ERROR_Pos)            /* (LCDC_BASEIMR) Transfer Error Interrupt Mask Mask */
#define LCDC_BASEIMR_ERROR(value)             (LCDC_BASEIMR_ERROR_Msk & (_UINT32_(value) << LCDC_BASEIMR_ERROR_Pos)) /* Assigment of value for ERROR in the LCDC_BASEIMR register */
#define LCDC_BASEIMR_OVF_Pos                  _UINT32_(2)                                          /* (LCDC_BASEIMR) Overflow Interrupt Mask Position */
#define LCDC_BASEIMR_OVF_Msk                  (_UINT32_(0x1) << LCDC_BASEIMR_OVF_Pos)              /* (LCDC_BASEIMR) Overflow Interrupt Mask Mask */
#define LCDC_BASEIMR_OVF(value)               (LCDC_BASEIMR_OVF_Msk & (_UINT32_(value) << LCDC_BASEIMR_OVF_Pos)) /* Assigment of value for OVF in the LCDC_BASEIMR register */
#define LCDC_BASEIMR_Msk                      _UINT32_(0x00000007)                                 /* (LCDC_BASEIMR) Register Mask  */


/* -------- LCDC_BASEISR : (LCDC Offset: 0x6C) ( R/ 32) Base Layer Interrupt Status Register -------- */
#define LCDC_BASEISR_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_BASEISR) Base Layer Interrupt Status Register  Reset Value */

#define LCDC_BASEISR_END_Pos                  _UINT32_(0)                                          /* (LCDC_BASEISR) End of Frame DMA Transfer Position */
#define LCDC_BASEISR_END_Msk                  (_UINT32_(0x1) << LCDC_BASEISR_END_Pos)              /* (LCDC_BASEISR) End of Frame DMA Transfer Mask */
#define LCDC_BASEISR_END(value)               (LCDC_BASEISR_END_Msk & (_UINT32_(value) << LCDC_BASEISR_END_Pos)) /* Assigment of value for END in the LCDC_BASEISR register */
#define   LCDC_BASEISR_END_0_Val              _UINT32_(0x0)                                        /* (LCDC_BASEISR) No end of frame DMA transfer has been detected since last read of LCDC_BASEISR.  */
#define   LCDC_BASEISR_END_1_Val              _UINT32_(0x1)                                        /* (LCDC_BASEISR) End of transfer has been detected. This flag is reset after a read operation.  */
#define LCDC_BASEISR_END_0                    (LCDC_BASEISR_END_0_Val << LCDC_BASEISR_END_Pos)     /* (LCDC_BASEISR) No end of frame DMA transfer has been detected since last read of LCDC_BASEISR. Position  */
#define LCDC_BASEISR_END_1                    (LCDC_BASEISR_END_1_Val << LCDC_BASEISR_END_Pos)     /* (LCDC_BASEISR) End of transfer has been detected. This flag is reset after a read operation. Position  */
#define LCDC_BASEISR_ERROR_Pos                _UINT32_(1)                                          /* (LCDC_BASEISR) Transfer Error Detected Position */
#define LCDC_BASEISR_ERROR_Msk                (_UINT32_(0x1) << LCDC_BASEISR_ERROR_Pos)            /* (LCDC_BASEISR) Transfer Error Detected Mask */
#define LCDC_BASEISR_ERROR(value)             (LCDC_BASEISR_ERROR_Msk & (_UINT32_(value) << LCDC_BASEISR_ERROR_Pos)) /* Assigment of value for ERROR in the LCDC_BASEISR register */
#define   LCDC_BASEISR_ERROR_0_Val            _UINT32_(0x0)                                        /* (LCDC_BASEISR) No system bus error has been detected since the last read of LCDC_BASEISR.  */
#define   LCDC_BASEISR_ERROR_1_Val            _UINT32_(0x1)                                        /* (LCDC_BASEISR) A system bus error has been detected. This flag is reset after a read operation.  */
#define LCDC_BASEISR_ERROR_0                  (LCDC_BASEISR_ERROR_0_Val << LCDC_BASEISR_ERROR_Pos) /* (LCDC_BASEISR) No system bus error has been detected since the last read of LCDC_BASEISR. Position  */
#define LCDC_BASEISR_ERROR_1                  (LCDC_BASEISR_ERROR_1_Val << LCDC_BASEISR_ERROR_Pos) /* (LCDC_BASEISR) A system bus error has been detected. This flag is reset after a read operation. Position  */
#define LCDC_BASEISR_OVF_Pos                  _UINT32_(2)                                          /* (LCDC_BASEISR) Overflow Detected Position */
#define LCDC_BASEISR_OVF_Msk                  (_UINT32_(0x1) << LCDC_BASEISR_OVF_Pos)              /* (LCDC_BASEISR) Overflow Detected Mask */
#define LCDC_BASEISR_OVF(value)               (LCDC_BASEISR_OVF_Msk & (_UINT32_(value) << LCDC_BASEISR_OVF_Pos)) /* Assigment of value for OVF in the LCDC_BASEISR register */
#define   LCDC_BASEISR_OVF_0_Val              _UINT32_(0x0)                                        /* (LCDC_BASEISR) No overflow occurred since last read of LCDC_BASEISR.  */
#define   LCDC_BASEISR_OVF_1_Val              _UINT32_(0x1)                                        /* (LCDC_BASEISR) An overflow occurred, at least one DMA transfer is still running at the End Of Frame. This flag is reset after a read operation.  */
#define LCDC_BASEISR_OVF_0                    (LCDC_BASEISR_OVF_0_Val << LCDC_BASEISR_OVF_Pos)     /* (LCDC_BASEISR) No overflow occurred since last read of LCDC_BASEISR. Position  */
#define LCDC_BASEISR_OVF_1                    (LCDC_BASEISR_OVF_1_Val << LCDC_BASEISR_OVF_Pos)     /* (LCDC_BASEISR) An overflow occurred, at least one DMA transfer is still running at the End Of Frame. This flag is reset after a read operation. Position  */
#define LCDC_BASEISR_Msk                      _UINT32_(0x00000007)                                 /* (LCDC_BASEISR) Register Mask  */


/* -------- LCDC_BASEEN : (LCDC Offset: 0x70) (R/W 32) Base Layer Enable Register -------- */
#define LCDC_BASEEN_RESETVALUE                _UINT32_(0x00)                                       /*  (LCDC_BASEEN) Base Layer Enable Register  Reset Value */

#define LCDC_BASEEN_ENABLE_Pos                _UINT32_(0)                                          /* (LCDC_BASEEN) Base Layer Enable Position */
#define LCDC_BASEEN_ENABLE_Msk                (_UINT32_(0x1) << LCDC_BASEEN_ENABLE_Pos)            /* (LCDC_BASEEN) Base Layer Enable Mask */
#define LCDC_BASEEN_ENABLE(value)             (LCDC_BASEEN_ENABLE_Msk & (_UINT32_(value) << LCDC_BASEEN_ENABLE_Pos)) /* Assigment of value for ENABLE in the LCDC_BASEEN register */
#define   LCDC_BASEEN_ENABLE_0_Val            _UINT32_(0x0)                                        /* (LCDC_BASEEN) The layer is disabled.  */
#define   LCDC_BASEEN_ENABLE_1_Val            _UINT32_(0x1)                                        /* (LCDC_BASEEN) The layer is enabled.  */
#define LCDC_BASEEN_ENABLE_0                  (LCDC_BASEEN_ENABLE_0_Val << LCDC_BASEEN_ENABLE_Pos) /* (LCDC_BASEEN) The layer is disabled. Position  */
#define LCDC_BASEEN_ENABLE_1                  (LCDC_BASEEN_ENABLE_1_Val << LCDC_BASEEN_ENABLE_Pos) /* (LCDC_BASEEN) The layer is enabled. Position  */
#define LCDC_BASEEN_Msk                       _UINT32_(0x00000001)                                 /* (LCDC_BASEEN) Register Mask  */


/* -------- LCDC_BASECLA : (LCDC Offset: 0x74) (R/W 32) Base Layer Color Table Address Register -------- */
#define LCDC_BASECLA_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_BASECLA) Base Layer Color Table Address Register  Reset Value */

#define LCDC_BASECLA_CLA_Pos                  _UINT32_(2)                                          /* (LCDC_BASECLA) Base Layer CLUT Address Position */
#define LCDC_BASECLA_CLA_Msk                  (_UINT32_(0x3FFFFFFF) << LCDC_BASECLA_CLA_Pos)       /* (LCDC_BASECLA) Base Layer CLUT Address Mask */
#define LCDC_BASECLA_CLA(value)               (LCDC_BASECLA_CLA_Msk & (_UINT32_(value) << LCDC_BASECLA_CLA_Pos)) /* Assigment of value for CLA in the LCDC_BASECLA register */
#define LCDC_BASECLA_Msk                      _UINT32_(0xFFFFFFFC)                                 /* (LCDC_BASECLA) Register Mask  */


/* -------- LCDC_BASEFBA : (LCDC Offset: 0x78) (R/W 32) Base Layer Frame Buffer Address Register -------- */
#define LCDC_BASEFBA_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_BASEFBA) Base Layer Frame Buffer Address Register  Reset Value */

#define LCDC_BASEFBA_FBA_Pos                  _UINT32_(2)                                          /* (LCDC_BASEFBA) Frame Buffer Address Position */
#define LCDC_BASEFBA_FBA_Msk                  (_UINT32_(0x3FFFFFFF) << LCDC_BASEFBA_FBA_Pos)       /* (LCDC_BASEFBA) Frame Buffer Address Mask */
#define LCDC_BASEFBA_FBA(value)               (LCDC_BASEFBA_FBA_Msk & (_UINT32_(value) << LCDC_BASEFBA_FBA_Pos)) /* Assigment of value for FBA in the LCDC_BASEFBA register */
#define LCDC_BASEFBA_Msk                      _UINT32_(0xFFFFFFFC)                                 /* (LCDC_BASEFBA) Register Mask  */


/* -------- LCDC_BASECFG0 : (LCDC Offset: 0x7C) (R/W 32) Base Layer Configuration Register 0 -------- */
#define LCDC_BASECFG0_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_BASECFG0) Base Layer Configuration Register 0  Reset Value */

#define LCDC_BASECFG0_BLEN_Pos                _UINT32_(4)                                          /* (LCDC_BASECFG0) System Bus Burst Length Position */
#define LCDC_BASECFG0_BLEN_Msk                (_UINT32_(0x7) << LCDC_BASECFG0_BLEN_Pos)            /* (LCDC_BASECFG0) System Bus Burst Length Mask */
#define LCDC_BASECFG0_BLEN(value)             (LCDC_BASECFG0_BLEN_Msk & (_UINT32_(value) << LCDC_BASECFG0_BLEN_Pos)) /* Assigment of value for BLEN in the LCDC_BASECFG0 register */
#define   LCDC_BASECFG0_BLEN_INCR1_Val        _UINT32_(0x0)                                        /* (LCDC_BASECFG0) System bus access is started as soon as there is enough space in the FIFO to store one data.  */
#define   LCDC_BASECFG0_BLEN_INCR4_Val        _UINT32_(0x1)                                        /* (LCDC_BASECFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 4 data. A system bus INCR4 Burst is used by default. INCR1 is used for bursts less than 4.  */
#define   LCDC_BASECFG0_BLEN_INCR8_Val        _UINT32_(0x2)                                        /* (LCDC_BASECFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 8 data. A system bus INCR8 Burst is used by default. INCR4 bursts are used for bursts of 4 beats.INCR1 is used for bursts less than 4.  */
#define   LCDC_BASECFG0_BLEN_INCR16_Val       _UINT32_(0x3)                                        /* (LCDC_BASECFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 16 data. A system bus INCR16 Burst is used by default. INCR8 and INCR4 bursts are respectively used for bursts of 8 and 4 beats.INCR1 is used for bursts less than 4.  */
#define   LCDC_BASECFG0_BLEN_INCR32_Val       _UINT32_(0x4)                                        /* (LCDC_BASECFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 32 data. A system bus INCR32 Burst is used by default. INCR16, INCR8 and INCR4 bursts are respectively used for bursts of 16, 8 and 4 beats. INCR1 is used for bursts less than 4.  */
#define LCDC_BASECFG0_BLEN_INCR1              (LCDC_BASECFG0_BLEN_INCR1_Val << LCDC_BASECFG0_BLEN_Pos) /* (LCDC_BASECFG0) System bus access is started as soon as there is enough space in the FIFO to store one data. Position  */
#define LCDC_BASECFG0_BLEN_INCR4              (LCDC_BASECFG0_BLEN_INCR4_Val << LCDC_BASECFG0_BLEN_Pos) /* (LCDC_BASECFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 4 data. A system bus INCR4 Burst is used by default. INCR1 is used for bursts less than 4. Position  */
#define LCDC_BASECFG0_BLEN_INCR8              (LCDC_BASECFG0_BLEN_INCR8_Val << LCDC_BASECFG0_BLEN_Pos) /* (LCDC_BASECFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 8 data. A system bus INCR8 Burst is used by default. INCR4 bursts are used for bursts of 4 beats.INCR1 is used for bursts less than 4. Position  */
#define LCDC_BASECFG0_BLEN_INCR16             (LCDC_BASECFG0_BLEN_INCR16_Val << LCDC_BASECFG0_BLEN_Pos) /* (LCDC_BASECFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 16 data. A system bus INCR16 Burst is used by default. INCR8 and INCR4 bursts are respectively used for bursts of 8 and 4 beats.INCR1 is used for bursts less than 4. Position  */
#define LCDC_BASECFG0_BLEN_INCR32             (LCDC_BASECFG0_BLEN_INCR32_Val << LCDC_BASECFG0_BLEN_Pos) /* (LCDC_BASECFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 32 data. A system bus INCR32 Burst is used by default. INCR16, INCR8 and INCR4 bursts are respectively used for bursts of 16, 8 and 4 beats. INCR1 is used for bursts less than 4. Position  */
#define LCDC_BASECFG0_Msk                     _UINT32_(0x00000070)                                 /* (LCDC_BASECFG0) Register Mask  */


/* -------- LCDC_BASECFG1 : (LCDC Offset: 0x80) (R/W 32) Base Layer Configuration Register 1 -------- */
#define LCDC_BASECFG1_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_BASECFG1) Base Layer Configuration Register 1  Reset Value */

#define LCDC_BASECFG1_CLUTEN_Pos              _UINT32_(0)                                          /* (LCDC_BASECFG1) CLUT Mode Enable Position */
#define LCDC_BASECFG1_CLUTEN_Msk              (_UINT32_(0x1) << LCDC_BASECFG1_CLUTEN_Pos)          /* (LCDC_BASECFG1) CLUT Mode Enable Mask */
#define LCDC_BASECFG1_CLUTEN(value)           (LCDC_BASECFG1_CLUTEN_Msk & (_UINT32_(value) << LCDC_BASECFG1_CLUTEN_Pos)) /* Assigment of value for CLUTEN in the LCDC_BASECFG1 register */
#define   LCDC_BASECFG1_CLUTEN_0_Val          _UINT32_(0x0)                                        /* (LCDC_BASECFG1) RGB mode is selected.  */
#define   LCDC_BASECFG1_CLUTEN_1_Val          _UINT32_(0x1)                                        /* (LCDC_BASECFG1) CLUT mode is selected.  */
#define LCDC_BASECFG1_CLUTEN_0                (LCDC_BASECFG1_CLUTEN_0_Val << LCDC_BASECFG1_CLUTEN_Pos) /* (LCDC_BASECFG1) RGB mode is selected. Position  */
#define LCDC_BASECFG1_CLUTEN_1                (LCDC_BASECFG1_CLUTEN_1_Val << LCDC_BASECFG1_CLUTEN_Pos) /* (LCDC_BASECFG1) CLUT mode is selected. Position  */
#define LCDC_BASECFG1_GAM_Pos                 _UINT32_(2)                                          /* (LCDC_BASECFG1) Gamma Correction Position */
#define LCDC_BASECFG1_GAM_Msk                 (_UINT32_(0x1) << LCDC_BASECFG1_GAM_Pos)             /* (LCDC_BASECFG1) Gamma Correction Mask */
#define LCDC_BASECFG1_GAM(value)              (LCDC_BASECFG1_GAM_Msk & (_UINT32_(value) << LCDC_BASECFG1_GAM_Pos)) /* Assigment of value for GAM in the LCDC_BASECFG1 register */
#define   LCDC_BASECFG1_GAM_0_Val             _UINT32_(0x0)                                        /* (LCDC_BASECFG1) Gamma correction is disabled  */
#define   LCDC_BASECFG1_GAM_1_Val             _UINT32_(0x1)                                        /* (LCDC_BASECFG1) Gamma correction is activated  */
#define LCDC_BASECFG1_GAM_0                   (LCDC_BASECFG1_GAM_0_Val << LCDC_BASECFG1_GAM_Pos)   /* (LCDC_BASECFG1) Gamma correction is disabled Position  */
#define LCDC_BASECFG1_GAM_1                   (LCDC_BASECFG1_GAM_1_Val << LCDC_BASECFG1_GAM_Pos)   /* (LCDC_BASECFG1) Gamma correction is activated Position  */
#define LCDC_BASECFG1_RGBMODE_Pos             _UINT32_(4)                                          /* (LCDC_BASECFG1) RGB Mode Input Selection Position */
#define LCDC_BASECFG1_RGBMODE_Msk             (_UINT32_(0xF) << LCDC_BASECFG1_RGBMODE_Pos)         /* (LCDC_BASECFG1) RGB Mode Input Selection Mask */
#define LCDC_BASECFG1_RGBMODE(value)          (LCDC_BASECFG1_RGBMODE_Msk & (_UINT32_(value) << LCDC_BASECFG1_RGBMODE_Pos)) /* Assigment of value for RGBMODE in the LCDC_BASECFG1 register */
#define   LCDC_BASECFG1_RGBMODE_12BPP_RGB_444_Val _UINT32_(0x0)                                        /* (LCDC_BASECFG1) 12 bpp RGB 444  */
#define   LCDC_BASECFG1_RGBMODE_16BPP_ARGB_4444_Val _UINT32_(0x1)                                        /* (LCDC_BASECFG1) 16 bpp ARGB 4444  */
#define   LCDC_BASECFG1_RGBMODE_16BPP_RGBA_4444_Val _UINT32_(0x2)                                        /* (LCDC_BASECFG1) 16 bpp RGBA 4444  */
#define   LCDC_BASECFG1_RGBMODE_16BPP_RGB_565_Val _UINT32_(0x3)                                        /* (LCDC_BASECFG1) 16 bpp RGB 565  */
#define   LCDC_BASECFG1_RGBMODE_16BPP_ARGB_1555_Val _UINT32_(0x4)                                        /* (LCDC_BASECFG1) 16 bpp ARGB 1555  */
#define   LCDC_BASECFG1_RGBMODE_18BPP_RGB_666_Val _UINT32_(0x5)                                        /* (LCDC_BASECFG1) 18 bpp RGB 666  */
#define   LCDC_BASECFG1_RGBMODE_18BPP_RGB_666PACKED_Val _UINT32_(0x6)                                        /* (LCDC_BASECFG1) 18 bpp RGB 666 PACKED  */
#define   LCDC_BASECFG1_RGBMODE_19BPP_ARGB_1666_Val _UINT32_(0x7)                                        /* (LCDC_BASECFG1) 19 bpp ARGB 1666  */
#define   LCDC_BASECFG1_RGBMODE_19BPP_ARGB_PACKED_Val _UINT32_(0x8)                                        /* (LCDC_BASECFG1) 19 bpp ARGB 1666 PACKED  */
#define   LCDC_BASECFG1_RGBMODE_24BPP_RGB_888_Val _UINT32_(0x9)                                        /* (LCDC_BASECFG1) 24 bpp RGB 888  */
#define   LCDC_BASECFG1_RGBMODE_24BPP_RGB_888_PACKED_Val _UINT32_(0xA)                                        /* (LCDC_BASECFG1) 24 bpp RGB 888 PACKED  */
#define   LCDC_BASECFG1_RGBMODE_25BPP_ARGB_1888_Val _UINT32_(0xB)                                        /* (LCDC_BASECFG1) 25 bpp ARGB 1888  */
#define   LCDC_BASECFG1_RGBMODE_32BPP_ARGB_8888_Val _UINT32_(0xC)                                        /* (LCDC_BASECFG1) 32 bpp ARGB 8888  */
#define   LCDC_BASECFG1_RGBMODE_32BPP_RGBA_8888_Val _UINT32_(0xD)                                        /* (LCDC_BASECFG1) 32 bpp RGBA 8888  */
#define LCDC_BASECFG1_RGBMODE_12BPP_RGB_444   (LCDC_BASECFG1_RGBMODE_12BPP_RGB_444_Val << LCDC_BASECFG1_RGBMODE_Pos) /* (LCDC_BASECFG1) 12 bpp RGB 444 Position  */
#define LCDC_BASECFG1_RGBMODE_16BPP_ARGB_4444 (LCDC_BASECFG1_RGBMODE_16BPP_ARGB_4444_Val << LCDC_BASECFG1_RGBMODE_Pos) /* (LCDC_BASECFG1) 16 bpp ARGB 4444 Position  */
#define LCDC_BASECFG1_RGBMODE_16BPP_RGBA_4444 (LCDC_BASECFG1_RGBMODE_16BPP_RGBA_4444_Val << LCDC_BASECFG1_RGBMODE_Pos) /* (LCDC_BASECFG1) 16 bpp RGBA 4444 Position  */
#define LCDC_BASECFG1_RGBMODE_16BPP_RGB_565   (LCDC_BASECFG1_RGBMODE_16BPP_RGB_565_Val << LCDC_BASECFG1_RGBMODE_Pos) /* (LCDC_BASECFG1) 16 bpp RGB 565 Position  */
#define LCDC_BASECFG1_RGBMODE_16BPP_ARGB_1555 (LCDC_BASECFG1_RGBMODE_16BPP_ARGB_1555_Val << LCDC_BASECFG1_RGBMODE_Pos) /* (LCDC_BASECFG1) 16 bpp ARGB 1555 Position  */
#define LCDC_BASECFG1_RGBMODE_18BPP_RGB_666   (LCDC_BASECFG1_RGBMODE_18BPP_RGB_666_Val << LCDC_BASECFG1_RGBMODE_Pos) /* (LCDC_BASECFG1) 18 bpp RGB 666 Position  */
#define LCDC_BASECFG1_RGBMODE_18BPP_RGB_666PACKED (LCDC_BASECFG1_RGBMODE_18BPP_RGB_666PACKED_Val << LCDC_BASECFG1_RGBMODE_Pos) /* (LCDC_BASECFG1) 18 bpp RGB 666 PACKED Position  */
#define LCDC_BASECFG1_RGBMODE_19BPP_ARGB_1666 (LCDC_BASECFG1_RGBMODE_19BPP_ARGB_1666_Val << LCDC_BASECFG1_RGBMODE_Pos) /* (LCDC_BASECFG1) 19 bpp ARGB 1666 Position  */
#define LCDC_BASECFG1_RGBMODE_19BPP_ARGB_PACKED (LCDC_BASECFG1_RGBMODE_19BPP_ARGB_PACKED_Val << LCDC_BASECFG1_RGBMODE_Pos) /* (LCDC_BASECFG1) 19 bpp ARGB 1666 PACKED Position  */
#define LCDC_BASECFG1_RGBMODE_24BPP_RGB_888   (LCDC_BASECFG1_RGBMODE_24BPP_RGB_888_Val << LCDC_BASECFG1_RGBMODE_Pos) /* (LCDC_BASECFG1) 24 bpp RGB 888 Position  */
#define LCDC_BASECFG1_RGBMODE_24BPP_RGB_888_PACKED (LCDC_BASECFG1_RGBMODE_24BPP_RGB_888_PACKED_Val << LCDC_BASECFG1_RGBMODE_Pos) /* (LCDC_BASECFG1) 24 bpp RGB 888 PACKED Position  */
#define LCDC_BASECFG1_RGBMODE_25BPP_ARGB_1888 (LCDC_BASECFG1_RGBMODE_25BPP_ARGB_1888_Val << LCDC_BASECFG1_RGBMODE_Pos) /* (LCDC_BASECFG1) 25 bpp ARGB 1888 Position  */
#define LCDC_BASECFG1_RGBMODE_32BPP_ARGB_8888 (LCDC_BASECFG1_RGBMODE_32BPP_ARGB_8888_Val << LCDC_BASECFG1_RGBMODE_Pos) /* (LCDC_BASECFG1) 32 bpp ARGB 8888 Position  */
#define LCDC_BASECFG1_RGBMODE_32BPP_RGBA_8888 (LCDC_BASECFG1_RGBMODE_32BPP_RGBA_8888_Val << LCDC_BASECFG1_RGBMODE_Pos) /* (LCDC_BASECFG1) 32 bpp RGBA 8888 Position  */
#define LCDC_BASECFG1_CLUTMODE_Pos            _UINT32_(8)                                          /* (LCDC_BASECFG1) CLUT Mode Input Selection Position */
#define LCDC_BASECFG1_CLUTMODE_Msk            (_UINT32_(0x3) << LCDC_BASECFG1_CLUTMODE_Pos)        /* (LCDC_BASECFG1) CLUT Mode Input Selection Mask */
#define LCDC_BASECFG1_CLUTMODE(value)         (LCDC_BASECFG1_CLUTMODE_Msk & (_UINT32_(value) << LCDC_BASECFG1_CLUTMODE_Pos)) /* Assigment of value for CLUTMODE in the LCDC_BASECFG1 register */
#define   LCDC_BASECFG1_CLUTMODE_CLUT_1BPP_Val _UINT32_(0x0)                                        /* (LCDC_BASECFG1) CLUT mode set to 1 bit per pixel  */
#define   LCDC_BASECFG1_CLUTMODE_CLUT_2BPP_Val _UINT32_(0x1)                                        /* (LCDC_BASECFG1) CLUT mode set to 2 bits per pixel  */
#define   LCDC_BASECFG1_CLUTMODE_CLUT_4BPP_Val _UINT32_(0x2)                                        /* (LCDC_BASECFG1) CLUT mode set to 4 bits per pixel  */
#define   LCDC_BASECFG1_CLUTMODE_CLUT_8BPP_Val _UINT32_(0x3)                                        /* (LCDC_BASECFG1) CLUT mode set to 8 bits per pixel  */
#define LCDC_BASECFG1_CLUTMODE_CLUT_1BPP      (LCDC_BASECFG1_CLUTMODE_CLUT_1BPP_Val << LCDC_BASECFG1_CLUTMODE_Pos) /* (LCDC_BASECFG1) CLUT mode set to 1 bit per pixel Position  */
#define LCDC_BASECFG1_CLUTMODE_CLUT_2BPP      (LCDC_BASECFG1_CLUTMODE_CLUT_2BPP_Val << LCDC_BASECFG1_CLUTMODE_Pos) /* (LCDC_BASECFG1) CLUT mode set to 2 bits per pixel Position  */
#define LCDC_BASECFG1_CLUTMODE_CLUT_4BPP      (LCDC_BASECFG1_CLUTMODE_CLUT_4BPP_Val << LCDC_BASECFG1_CLUTMODE_Pos) /* (LCDC_BASECFG1) CLUT mode set to 4 bits per pixel Position  */
#define LCDC_BASECFG1_CLUTMODE_CLUT_8BPP      (LCDC_BASECFG1_CLUTMODE_CLUT_8BPP_Val << LCDC_BASECFG1_CLUTMODE_Pos) /* (LCDC_BASECFG1) CLUT mode set to 8 bits per pixel Position  */
#define LCDC_BASECFG1_Msk                     _UINT32_(0x000003F5)                                 /* (LCDC_BASECFG1) Register Mask  */


/* -------- LCDC_BASECFG2 : (LCDC Offset: 0x84) (R/W 32) Base Layer Configuration Register 2 -------- */
#define LCDC_BASECFG2_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_BASECFG2) Base Layer Configuration Register 2  Reset Value */

#define LCDC_BASECFG2_XSTRIDE_Pos             _UINT32_(0)                                          /* (LCDC_BASECFG2) Horizontal Stride Position */
#define LCDC_BASECFG2_XSTRIDE_Msk             (_UINT32_(0xFFFFFFFF) << LCDC_BASECFG2_XSTRIDE_Pos)  /* (LCDC_BASECFG2) Horizontal Stride Mask */
#define LCDC_BASECFG2_XSTRIDE(value)          (LCDC_BASECFG2_XSTRIDE_Msk & (_UINT32_(value) << LCDC_BASECFG2_XSTRIDE_Pos)) /* Assigment of value for XSTRIDE in the LCDC_BASECFG2 register */
#define LCDC_BASECFG2_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (LCDC_BASECFG2) Register Mask  */


/* -------- LCDC_BASECFG3 : (LCDC Offset: 0x88) (R/W 32) Base Layer Configuration Register 3 -------- */
#define LCDC_BASECFG3_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_BASECFG3) Base Layer Configuration Register 3  Reset Value */

#define LCDC_BASECFG3_BDEF_Pos                _UINT32_(0)                                          /* (LCDC_BASECFG3) Blue Default Position */
#define LCDC_BASECFG3_BDEF_Msk                (_UINT32_(0xFF) << LCDC_BASECFG3_BDEF_Pos)           /* (LCDC_BASECFG3) Blue Default Mask */
#define LCDC_BASECFG3_BDEF(value)             (LCDC_BASECFG3_BDEF_Msk & (_UINT32_(value) << LCDC_BASECFG3_BDEF_Pos)) /* Assigment of value for BDEF in the LCDC_BASECFG3 register */
#define LCDC_BASECFG3_GDEF_Pos                _UINT32_(8)                                          /* (LCDC_BASECFG3) Green Default Position */
#define LCDC_BASECFG3_GDEF_Msk                (_UINT32_(0xFF) << LCDC_BASECFG3_GDEF_Pos)           /* (LCDC_BASECFG3) Green Default Mask */
#define LCDC_BASECFG3_GDEF(value)             (LCDC_BASECFG3_GDEF_Msk & (_UINT32_(value) << LCDC_BASECFG3_GDEF_Pos)) /* Assigment of value for GDEF in the LCDC_BASECFG3 register */
#define LCDC_BASECFG3_RDEF_Pos                _UINT32_(16)                                         /* (LCDC_BASECFG3) Red Default Position */
#define LCDC_BASECFG3_RDEF_Msk                (_UINT32_(0xFF) << LCDC_BASECFG3_RDEF_Pos)           /* (LCDC_BASECFG3) Red Default Mask */
#define LCDC_BASECFG3_RDEF(value)             (LCDC_BASECFG3_RDEF_Msk & (_UINT32_(value) << LCDC_BASECFG3_RDEF_Pos)) /* Assigment of value for RDEF in the LCDC_BASECFG3 register */
#define LCDC_BASECFG3_Msk                     _UINT32_(0x00FFFFFF)                                 /* (LCDC_BASECFG3) Register Mask  */


/* -------- LCDC_BASECFG4 : (LCDC Offset: 0x8C) (R/W 32) Base Layer Configuration Register 4 -------- */
#define LCDC_BASECFG4_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_BASECFG4) Base Layer Configuration Register 4  Reset Value */

#define LCDC_BASECFG4_DMA_Pos                 _UINT32_(0)                                          /* (LCDC_BASECFG4) Use DMA Data Path Position */
#define LCDC_BASECFG4_DMA_Msk                 (_UINT32_(0x1) << LCDC_BASECFG4_DMA_Pos)             /* (LCDC_BASECFG4) Use DMA Data Path Mask */
#define LCDC_BASECFG4_DMA(value)              (LCDC_BASECFG4_DMA_Msk & (_UINT32_(value) << LCDC_BASECFG4_DMA_Pos)) /* Assigment of value for DMA in the LCDC_BASECFG4 register */
#define   LCDC_BASECFG4_DMA_0_Val             _UINT32_(0x0)                                        /* (LCDC_BASECFG4) The default color is used on the base layer.  */
#define   LCDC_BASECFG4_DMA_1_Val             _UINT32_(0x1)                                        /* (LCDC_BASECFG4) The DMA channel retrieves the pixel stream from the memory.  */
#define LCDC_BASECFG4_DMA_0                   (LCDC_BASECFG4_DMA_0_Val << LCDC_BASECFG4_DMA_Pos)   /* (LCDC_BASECFG4) The default color is used on the base layer. Position  */
#define LCDC_BASECFG4_DMA_1                   (LCDC_BASECFG4_DMA_1_Val << LCDC_BASECFG4_DMA_Pos)   /* (LCDC_BASECFG4) The DMA channel retrieves the pixel stream from the memory. Position  */
#define LCDC_BASECFG4_REP_Pos                 _UINT32_(1)                                          /* (LCDC_BASECFG4) Use Replication Logic to Expand RGB Color to 24 Bits Position */
#define LCDC_BASECFG4_REP_Msk                 (_UINT32_(0x1) << LCDC_BASECFG4_REP_Pos)             /* (LCDC_BASECFG4) Use Replication Logic to Expand RGB Color to 24 Bits Mask */
#define LCDC_BASECFG4_REP(value)              (LCDC_BASECFG4_REP_Msk & (_UINT32_(value) << LCDC_BASECFG4_REP_Pos)) /* Assigment of value for REP in the LCDC_BASECFG4 register */
#define   LCDC_BASECFG4_REP_0_Val             _UINT32_(0x0)                                        /* (LCDC_BASECFG4) When the selected pixel depth is less than 24 bpp, the pixel is shifted and LSBs are set to 0.  */
#define   LCDC_BASECFG4_REP_1_Val             _UINT32_(0x1)                                        /* (LCDC_BASECFG4) When the selected pixel depth is less than 24 bpp, the pixel is shifted and the LSB replicates the MSB.  */
#define LCDC_BASECFG4_REP_0                   (LCDC_BASECFG4_REP_0_Val << LCDC_BASECFG4_REP_Pos)   /* (LCDC_BASECFG4) When the selected pixel depth is less than 24 bpp, the pixel is shifted and LSBs are set to 0. Position  */
#define LCDC_BASECFG4_REP_1                   (LCDC_BASECFG4_REP_1_Val << LCDC_BASECFG4_REP_Pos)   /* (LCDC_BASECFG4) When the selected pixel depth is less than 24 bpp, the pixel is shifted and the LSB replicates the MSB. Position  */
#define LCDC_BASECFG4_DISCEN_Pos              _UINT32_(4)                                          /* (LCDC_BASECFG4) Discard Area Enable Position */
#define LCDC_BASECFG4_DISCEN_Msk              (_UINT32_(0x1) << LCDC_BASECFG4_DISCEN_Pos)          /* (LCDC_BASECFG4) Discard Area Enable Mask */
#define LCDC_BASECFG4_DISCEN(value)           (LCDC_BASECFG4_DISCEN_Msk & (_UINT32_(value) << LCDC_BASECFG4_DISCEN_Pos)) /* Assigment of value for DISCEN in the LCDC_BASECFG4 register */
#define   LCDC_BASECFG4_DISCEN_0_Val          _UINT32_(0x0)                                        /* (LCDC_BASECFG4) The whole frame is retrieved from memory.  */
#define   LCDC_BASECFG4_DISCEN_1_Val          _UINT32_(0x1)                                        /* (LCDC_BASECFG4) The DMA channel discards the area located at screen coordinates {DISCXPOS, DISCYPOS}.  */
#define LCDC_BASECFG4_DISCEN_0                (LCDC_BASECFG4_DISCEN_0_Val << LCDC_BASECFG4_DISCEN_Pos) /* (LCDC_BASECFG4) The whole frame is retrieved from memory. Position  */
#define LCDC_BASECFG4_DISCEN_1                (LCDC_BASECFG4_DISCEN_1_Val << LCDC_BASECFG4_DISCEN_Pos) /* (LCDC_BASECFG4) The DMA channel discards the area located at screen coordinates {DISCXPOS, DISCYPOS}. Position  */
#define LCDC_BASECFG4_Msk                     _UINT32_(0x00000013)                                 /* (LCDC_BASECFG4) Register Mask  */


/* -------- LCDC_BASECFG5 : (LCDC Offset: 0x90) (R/W 32) Base Layer Configuration Register 5 -------- */
#define LCDC_BASECFG5_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_BASECFG5) Base Layer Configuration Register 5  Reset Value */

#define LCDC_BASECFG5_DISCXPOS_Pos            _UINT32_(0)                                          /* (LCDC_BASECFG5) Discard Area Horizontal Coordinate Position */
#define LCDC_BASECFG5_DISCXPOS_Msk            (_UINT32_(0x7FF) << LCDC_BASECFG5_DISCXPOS_Pos)      /* (LCDC_BASECFG5) Discard Area Horizontal Coordinate Mask */
#define LCDC_BASECFG5_DISCXPOS(value)         (LCDC_BASECFG5_DISCXPOS_Msk & (_UINT32_(value) << LCDC_BASECFG5_DISCXPOS_Pos)) /* Assigment of value for DISCXPOS in the LCDC_BASECFG5 register */
#define LCDC_BASECFG5_DISCYPOS_Pos            _UINT32_(16)                                         /* (LCDC_BASECFG5) Discard Area Vertical Coordinate Position */
#define LCDC_BASECFG5_DISCYPOS_Msk            (_UINT32_(0x7FF) << LCDC_BASECFG5_DISCYPOS_Pos)      /* (LCDC_BASECFG5) Discard Area Vertical Coordinate Mask */
#define LCDC_BASECFG5_DISCYPOS(value)         (LCDC_BASECFG5_DISCYPOS_Msk & (_UINT32_(value) << LCDC_BASECFG5_DISCYPOS_Pos)) /* Assigment of value for DISCYPOS in the LCDC_BASECFG5 register */
#define LCDC_BASECFG5_Msk                     _UINT32_(0x07FF07FF)                                 /* (LCDC_BASECFG5) Register Mask  */


/* -------- LCDC_BASECFG6 : (LCDC Offset: 0x94) (R/W 32) Base Layer Configuration Register 6 -------- */
#define LCDC_BASECFG6_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_BASECFG6) Base Layer Configuration Register 6  Reset Value */

#define LCDC_BASECFG6_DISCXSIZE_Pos           _UINT32_(0)                                          /* (LCDC_BASECFG6) Discard Area Horizontal Size Position */
#define LCDC_BASECFG6_DISCXSIZE_Msk           (_UINT32_(0x7FF) << LCDC_BASECFG6_DISCXSIZE_Pos)     /* (LCDC_BASECFG6) Discard Area Horizontal Size Mask */
#define LCDC_BASECFG6_DISCXSIZE(value)        (LCDC_BASECFG6_DISCXSIZE_Msk & (_UINT32_(value) << LCDC_BASECFG6_DISCXSIZE_Pos)) /* Assigment of value for DISCXSIZE in the LCDC_BASECFG6 register */
#define LCDC_BASECFG6_DISCYSIZE_Pos           _UINT32_(16)                                         /* (LCDC_BASECFG6) Discard Area Vertical Size Position */
#define LCDC_BASECFG6_DISCYSIZE_Msk           (_UINT32_(0x7FF) << LCDC_BASECFG6_DISCYSIZE_Pos)     /* (LCDC_BASECFG6) Discard Area Vertical Size Mask */
#define LCDC_BASECFG6_DISCYSIZE(value)        (LCDC_BASECFG6_DISCYSIZE_Msk & (_UINT32_(value) << LCDC_BASECFG6_DISCYSIZE_Pos)) /* Assigment of value for DISCYSIZE in the LCDC_BASECFG6 register */
#define LCDC_BASECFG6_Msk                     _UINT32_(0x07FF07FF)                                 /* (LCDC_BASECFG6) Register Mask  */


/* -------- LCDC_WPMR : (LCDC Offset: 0xE4) (R/W 32) Write Protection Mode Register -------- */
#define LCDC_WPMR_RESETVALUE                  _UINT32_(0x00)                                       /*  (LCDC_WPMR) Write Protection Mode Register  Reset Value */

#define LCDC_WPMR_WPCFGE_Pos                  _UINT32_(0)                                          /* (LCDC_WPMR) Write Protection Configuration Registers Enable Position */
#define LCDC_WPMR_WPCFGE_Msk                  (_UINT32_(0x1) << LCDC_WPMR_WPCFGE_Pos)              /* (LCDC_WPMR) Write Protection Configuration Registers Enable Mask */
#define LCDC_WPMR_WPCFGE(value)               (LCDC_WPMR_WPCFGE_Msk & (_UINT32_(value) << LCDC_WPMR_WPCFGE_Pos)) /* Assigment of value for WPCFGE in the LCDC_WPMR register */
#define   LCDC_WPMR_WPCFGE_0_Val              _UINT32_(0x0)                                        /* (LCDC_WPMR) Disables the write protection of LCDC Configuration registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define   LCDC_WPMR_WPCFGE_1_Val              _UINT32_(0x1)                                        /* (LCDC_WPMR) Enables the write protection of LCDC Configuration registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define LCDC_WPMR_WPCFGE_0                    (LCDC_WPMR_WPCFGE_0_Val << LCDC_WPMR_WPCFGE_Pos)     /* (LCDC_WPMR) Disables the write protection of LCDC Configuration registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_WPCFGE_1                    (LCDC_WPMR_WPCFGE_1_Val << LCDC_WPMR_WPCFGE_Pos)     /* (LCDC_WPMR) Enables the write protection of LCDC Configuration registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_WPITE_Pos                   _UINT32_(1)                                          /* (LCDC_WPMR) Write Protection Interrupt Registers Enable Position */
#define LCDC_WPMR_WPITE_Msk                   (_UINT32_(0x1) << LCDC_WPMR_WPITE_Pos)               /* (LCDC_WPMR) Write Protection Interrupt Registers Enable Mask */
#define LCDC_WPMR_WPITE(value)                (LCDC_WPMR_WPITE_Msk & (_UINT32_(value) << LCDC_WPMR_WPITE_Pos)) /* Assigment of value for WPITE in the LCDC_WPMR register */
#define   LCDC_WPMR_WPITE_0_Val               _UINT32_(0x0)                                        /* (LCDC_WPMR) Disables the write protection of LCDC Interrupt Enable/Disable registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define   LCDC_WPMR_WPITE_1_Val               _UINT32_(0x1)                                        /* (LCDC_WPMR) Enables the write protection of LCDC Interrupt Enable/Disable registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define LCDC_WPMR_WPITE_0                     (LCDC_WPMR_WPITE_0_Val << LCDC_WPMR_WPITE_Pos)       /* (LCDC_WPMR) Disables the write protection of LCDC Interrupt Enable/Disable registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_WPITE_1                     (LCDC_WPMR_WPITE_1_Val << LCDC_WPMR_WPITE_Pos)       /* (LCDC_WPMR) Enables the write protection of LCDC Interrupt Enable/Disable registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_WPCRE_Pos                   _UINT32_(2)                                          /* (LCDC_WPMR) Write Protection Control Registers Enable Position */
#define LCDC_WPMR_WPCRE_Msk                   (_UINT32_(0x1) << LCDC_WPMR_WPCRE_Pos)               /* (LCDC_WPMR) Write Protection Control Registers Enable Mask */
#define LCDC_WPMR_WPCRE(value)                (LCDC_WPMR_WPCRE_Msk & (_UINT32_(value) << LCDC_WPMR_WPCRE_Pos)) /* Assigment of value for WPCRE in the LCDC_WPMR register */
#define   LCDC_WPMR_WPCRE_0_Val               _UINT32_(0x0)                                        /* (LCDC_WPMR) Disables the write protection of LCDC Control registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define   LCDC_WPMR_WPCRE_1_Val               _UINT32_(0x1)                                        /* (LCDC_WPMR) Enables the write protection of LCDC Control registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define LCDC_WPMR_WPCRE_0                     (LCDC_WPMR_WPCRE_0_Val << LCDC_WPMR_WPCRE_Pos)       /* (LCDC_WPMR) Disables the write protection of LCDC Control registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_WPCRE_1                     (LCDC_WPMR_WPCRE_1_Val << LCDC_WPMR_WPCRE_Pos)       /* (LCDC_WPMR) Enables the write protection of LCDC Control registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_BWPCFGE_Pos                 _UINT32_(3)                                          /* (LCDC_WPMR) Base Layer Write Protection Configuration Registers Enable Position */
#define LCDC_WPMR_BWPCFGE_Msk                 (_UINT32_(0x1) << LCDC_WPMR_BWPCFGE_Pos)             /* (LCDC_WPMR) Base Layer Write Protection Configuration Registers Enable Mask */
#define LCDC_WPMR_BWPCFGE(value)              (LCDC_WPMR_BWPCFGE_Msk & (_UINT32_(value) << LCDC_WPMR_BWPCFGE_Pos)) /* Assigment of value for BWPCFGE in the LCDC_WPMR register */
#define   LCDC_WPMR_BWPCFGE_0_Val             _UINT32_(0x0)                                        /* (LCDC_WPMR) Disables the write protection of base layer Configuration registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define   LCDC_WPMR_BWPCFGE_1_Val             _UINT32_(0x1)                                        /* (LCDC_WPMR) Enables the write protection of base layer Configuration registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define LCDC_WPMR_BWPCFGE_0                   (LCDC_WPMR_BWPCFGE_0_Val << LCDC_WPMR_BWPCFGE_Pos)   /* (LCDC_WPMR) Disables the write protection of base layer Configuration registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_BWPCFGE_1                   (LCDC_WPMR_BWPCFGE_1_Val << LCDC_WPMR_BWPCFGE_Pos)   /* (LCDC_WPMR) Enables the write protection of base layer Configuration registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_BWPITE_Pos                  _UINT32_(4)                                          /* (LCDC_WPMR) Base Layer Write Protection Interrupt Registers Enable Position */
#define LCDC_WPMR_BWPITE_Msk                  (_UINT32_(0x1) << LCDC_WPMR_BWPITE_Pos)              /* (LCDC_WPMR) Base Layer Write Protection Interrupt Registers Enable Mask */
#define LCDC_WPMR_BWPITE(value)               (LCDC_WPMR_BWPITE_Msk & (_UINT32_(value) << LCDC_WPMR_BWPITE_Pos)) /* Assigment of value for BWPITE in the LCDC_WPMR register */
#define   LCDC_WPMR_BWPITE_0_Val              _UINT32_(0x0)                                        /* (LCDC_WPMR) Disables the write protection of base layer Interrupt Enable/Disable registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define   LCDC_WPMR_BWPITE_1_Val              _UINT32_(0x1)                                        /* (LCDC_WPMR) Enables the write protection of base layer Interrupt Enable/Disable registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define LCDC_WPMR_BWPITE_0                    (LCDC_WPMR_BWPITE_0_Val << LCDC_WPMR_BWPITE_Pos)     /* (LCDC_WPMR) Disables the write protection of base layer Interrupt Enable/Disable registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_BWPITE_1                    (LCDC_WPMR_BWPITE_1_Val << LCDC_WPMR_BWPITE_Pos)     /* (LCDC_WPMR) Enables the write protection of base layer Interrupt Enable/Disable registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_BWPCRE_Pos                  _UINT32_(5)                                          /* (LCDC_WPMR) Base Layer Write Protection Control Registers Enable Position */
#define LCDC_WPMR_BWPCRE_Msk                  (_UINT32_(0x1) << LCDC_WPMR_BWPCRE_Pos)              /* (LCDC_WPMR) Base Layer Write Protection Control Registers Enable Mask */
#define LCDC_WPMR_BWPCRE(value)               (LCDC_WPMR_BWPCRE_Msk & (_UINT32_(value) << LCDC_WPMR_BWPCRE_Pos)) /* Assigment of value for BWPCRE in the LCDC_WPMR register */
#define   LCDC_WPMR_BWPCRE_0_Val              _UINT32_(0x0)                                        /* (LCDC_WPMR) Disables the write protection of base layer Control registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define   LCDC_WPMR_BWPCRE_1_Val              _UINT32_(0x1)                                        /* (LCDC_WPMR) Enables the write protection of base layer Control registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define LCDC_WPMR_BWPCRE_0                    (LCDC_WPMR_BWPCRE_0_Val << LCDC_WPMR_BWPCRE_Pos)     /* (LCDC_WPMR) Disables the write protection of base layer Control registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_BWPCRE_1                    (LCDC_WPMR_BWPCRE_1_Val << LCDC_WPMR_BWPCRE_Pos)     /* (LCDC_WPMR) Enables the write protection of base layer Control registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_O1WPCFGE_Pos                _UINT32_(6)                                          /* (LCDC_WPMR) Overlay 1 Write Protection Configuration Registers Enable Position */
#define LCDC_WPMR_O1WPCFGE_Msk                (_UINT32_(0x1) << LCDC_WPMR_O1WPCFGE_Pos)            /* (LCDC_WPMR) Overlay 1 Write Protection Configuration Registers Enable Mask */
#define LCDC_WPMR_O1WPCFGE(value)             (LCDC_WPMR_O1WPCFGE_Msk & (_UINT32_(value) << LCDC_WPMR_O1WPCFGE_Pos)) /* Assigment of value for O1WPCFGE in the LCDC_WPMR register */
#define   LCDC_WPMR_O1WPCFGE_0_Val            _UINT32_(0x0)                                        /* (LCDC_WPMR) Disables the write protection of Overlay 1 Configuration registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define   LCDC_WPMR_O1WPCFGE_1_Val            _UINT32_(0x1)                                        /* (LCDC_WPMR) Enables the write protection of Overlay 1 Configuration registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define LCDC_WPMR_O1WPCFGE_0                  (LCDC_WPMR_O1WPCFGE_0_Val << LCDC_WPMR_O1WPCFGE_Pos) /* (LCDC_WPMR) Disables the write protection of Overlay 1 Configuration registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_O1WPCFGE_1                  (LCDC_WPMR_O1WPCFGE_1_Val << LCDC_WPMR_O1WPCFGE_Pos) /* (LCDC_WPMR) Enables the write protection of Overlay 1 Configuration registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_O1WPITE_Pos                 _UINT32_(7)                                          /* (LCDC_WPMR) Overlay 1 Write Protection Interrupt Registers Enable Position */
#define LCDC_WPMR_O1WPITE_Msk                 (_UINT32_(0x1) << LCDC_WPMR_O1WPITE_Pos)             /* (LCDC_WPMR) Overlay 1 Write Protection Interrupt Registers Enable Mask */
#define LCDC_WPMR_O1WPITE(value)              (LCDC_WPMR_O1WPITE_Msk & (_UINT32_(value) << LCDC_WPMR_O1WPITE_Pos)) /* Assigment of value for O1WPITE in the LCDC_WPMR register */
#define   LCDC_WPMR_O1WPITE_0_Val             _UINT32_(0x0)                                        /* (LCDC_WPMR) Disables the write protection of Overlay 1 Interrupt Enable/Disable registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define   LCDC_WPMR_O1WPITE_1_Val             _UINT32_(0x1)                                        /* (LCDC_WPMR) Enables the write protection of Overlay 1 Interrupt Enable/Disable registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define LCDC_WPMR_O1WPITE_0                   (LCDC_WPMR_O1WPITE_0_Val << LCDC_WPMR_O1WPITE_Pos)   /* (LCDC_WPMR) Disables the write protection of Overlay 1 Interrupt Enable/Disable registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_O1WPITE_1                   (LCDC_WPMR_O1WPITE_1_Val << LCDC_WPMR_O1WPITE_Pos)   /* (LCDC_WPMR) Enables the write protection of Overlay 1 Interrupt Enable/Disable registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_O1WPCRE_Pos                 _UINT32_(8)                                          /* (LCDC_WPMR) Overlay 1 Write Protection Control Registers Enable Position */
#define LCDC_WPMR_O1WPCRE_Msk                 (_UINT32_(0x1) << LCDC_WPMR_O1WPCRE_Pos)             /* (LCDC_WPMR) Overlay 1 Write Protection Control Registers Enable Mask */
#define LCDC_WPMR_O1WPCRE(value)              (LCDC_WPMR_O1WPCRE_Msk & (_UINT32_(value) << LCDC_WPMR_O1WPCRE_Pos)) /* Assigment of value for O1WPCRE in the LCDC_WPMR register */
#define   LCDC_WPMR_O1WPCRE_0_Val             _UINT32_(0x0)                                        /* (LCDC_WPMR) Disables the write protection of Overlay 1 Control registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define   LCDC_WPMR_O1WPCRE_1_Val             _UINT32_(0x1)                                        /* (LCDC_WPMR) Enables the write protection of Overlay 1 Control registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define LCDC_WPMR_O1WPCRE_0                   (LCDC_WPMR_O1WPCRE_0_Val << LCDC_WPMR_O1WPCRE_Pos)   /* (LCDC_WPMR) Disables the write protection of Overlay 1 Control registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_O1WPCRE_1                   (LCDC_WPMR_O1WPCRE_1_Val << LCDC_WPMR_O1WPCRE_Pos)   /* (LCDC_WPMR) Enables the write protection of Overlay 1 Control registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_O2WPCFGE_Pos                _UINT32_(9)                                          /* (LCDC_WPMR) Overlay 2 Write Protection Configuration Registers Enable Position */
#define LCDC_WPMR_O2WPCFGE_Msk                (_UINT32_(0x1) << LCDC_WPMR_O2WPCFGE_Pos)            /* (LCDC_WPMR) Overlay 2 Write Protection Configuration Registers Enable Mask */
#define LCDC_WPMR_O2WPCFGE(value)             (LCDC_WPMR_O2WPCFGE_Msk & (_UINT32_(value) << LCDC_WPMR_O2WPCFGE_Pos)) /* Assigment of value for O2WPCFGE in the LCDC_WPMR register */
#define   LCDC_WPMR_O2WPCFGE_0_Val            _UINT32_(0x0)                                        /* (LCDC_WPMR) Disables the write protection of Overlay 2 Configuration registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define   LCDC_WPMR_O2WPCFGE_1_Val            _UINT32_(0x1)                                        /* (LCDC_WPMR) Enables the write protection of Overlay 2 Configuration registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define LCDC_WPMR_O2WPCFGE_0                  (LCDC_WPMR_O2WPCFGE_0_Val << LCDC_WPMR_O2WPCFGE_Pos) /* (LCDC_WPMR) Disables the write protection of Overlay 2 Configuration registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_O2WPCFGE_1                  (LCDC_WPMR_O2WPCFGE_1_Val << LCDC_WPMR_O2WPCFGE_Pos) /* (LCDC_WPMR) Enables the write protection of Overlay 2 Configuration registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_O2WPITE_Pos                 _UINT32_(10)                                         /* (LCDC_WPMR) Overlay 2 Write Protection Interrupt Registers Enable Position */
#define LCDC_WPMR_O2WPITE_Msk                 (_UINT32_(0x1) << LCDC_WPMR_O2WPITE_Pos)             /* (LCDC_WPMR) Overlay 2 Write Protection Interrupt Registers Enable Mask */
#define LCDC_WPMR_O2WPITE(value)              (LCDC_WPMR_O2WPITE_Msk & (_UINT32_(value) << LCDC_WPMR_O2WPITE_Pos)) /* Assigment of value for O2WPITE in the LCDC_WPMR register */
#define   LCDC_WPMR_O2WPITE_0_Val             _UINT32_(0x0)                                        /* (LCDC_WPMR) Disables the write protection of Overlay 2 Interrupt Enable/Disable registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define   LCDC_WPMR_O2WPITE_1_Val             _UINT32_(0x1)                                        /* (LCDC_WPMR) Enables the write protection of Overlay 2 Interrupt Enable/Disable registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define LCDC_WPMR_O2WPITE_0                   (LCDC_WPMR_O2WPITE_0_Val << LCDC_WPMR_O2WPITE_Pos)   /* (LCDC_WPMR) Disables the write protection of Overlay 2 Interrupt Enable/Disable registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_O2WPITE_1                   (LCDC_WPMR_O2WPITE_1_Val << LCDC_WPMR_O2WPITE_Pos)   /* (LCDC_WPMR) Enables the write protection of Overlay 2 Interrupt Enable/Disable registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_O2WPCRE_Pos                 _UINT32_(11)                                         /* (LCDC_WPMR) Overlay 2 Write Protection Control Registers Enable Position */
#define LCDC_WPMR_O2WPCRE_Msk                 (_UINT32_(0x1) << LCDC_WPMR_O2WPCRE_Pos)             /* (LCDC_WPMR) Overlay 2 Write Protection Control Registers Enable Mask */
#define LCDC_WPMR_O2WPCRE(value)              (LCDC_WPMR_O2WPCRE_Msk & (_UINT32_(value) << LCDC_WPMR_O2WPCRE_Pos)) /* Assigment of value for O2WPCRE in the LCDC_WPMR register */
#define   LCDC_WPMR_O2WPCRE_0_Val             _UINT32_(0x0)                                        /* (LCDC_WPMR) Disables the write protection of Overlay 2 Control registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define   LCDC_WPMR_O2WPCRE_1_Val             _UINT32_(0x1)                                        /* (LCDC_WPMR) Enables the write protection of Overlay 2 Control registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define LCDC_WPMR_O2WPCRE_0                   (LCDC_WPMR_O2WPCRE_0_Val << LCDC_WPMR_O2WPCRE_Pos)   /* (LCDC_WPMR) Disables the write protection of Overlay 2 Control registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_O2WPCRE_1                   (LCDC_WPMR_O2WPCRE_1_Val << LCDC_WPMR_O2WPCRE_Pos)   /* (LCDC_WPMR) Enables the write protection of Overlay 2 Control registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_HEWPCFGE_Pos                _UINT32_(12)                                         /* (LCDC_WPMR) High-End Overlay Write Protection Configuration Registers Enable Position */
#define LCDC_WPMR_HEWPCFGE_Msk                (_UINT32_(0x1) << LCDC_WPMR_HEWPCFGE_Pos)            /* (LCDC_WPMR) High-End Overlay Write Protection Configuration Registers Enable Mask */
#define LCDC_WPMR_HEWPCFGE(value)             (LCDC_WPMR_HEWPCFGE_Msk & (_UINT32_(value) << LCDC_WPMR_HEWPCFGE_Pos)) /* Assigment of value for HEWPCFGE in the LCDC_WPMR register */
#define   LCDC_WPMR_HEWPCFGE_0_Val            _UINT32_(0x0)                                        /* (LCDC_WPMR) Disables the write protection of High-End Overlay Configuration registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define   LCDC_WPMR_HEWPCFGE_1_Val            _UINT32_(0x1)                                        /* (LCDC_WPMR) Enables the write protection of High-End Overlay Configuration registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define LCDC_WPMR_HEWPCFGE_0                  (LCDC_WPMR_HEWPCFGE_0_Val << LCDC_WPMR_HEWPCFGE_Pos) /* (LCDC_WPMR) Disables the write protection of High-End Overlay Configuration registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_HEWPCFGE_1                  (LCDC_WPMR_HEWPCFGE_1_Val << LCDC_WPMR_HEWPCFGE_Pos) /* (LCDC_WPMR) Enables the write protection of High-End Overlay Configuration registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_HEWPITE_Pos                 _UINT32_(13)                                         /* (LCDC_WPMR) High-End Overlay Write Protection Interrupt Registers Enable Position */
#define LCDC_WPMR_HEWPITE_Msk                 (_UINT32_(0x1) << LCDC_WPMR_HEWPITE_Pos)             /* (LCDC_WPMR) High-End Overlay Write Protection Interrupt Registers Enable Mask */
#define LCDC_WPMR_HEWPITE(value)              (LCDC_WPMR_HEWPITE_Msk & (_UINT32_(value) << LCDC_WPMR_HEWPITE_Pos)) /* Assigment of value for HEWPITE in the LCDC_WPMR register */
#define   LCDC_WPMR_HEWPITE_0_Val             _UINT32_(0x0)                                        /* (LCDC_WPMR) Disables the write protection of High-End Overlay Interrupt Enable/Disable registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define   LCDC_WPMR_HEWPITE_1_Val             _UINT32_(0x1)                                        /* (LCDC_WPMR) Enables the write protection of High-End Overlay Interrupt Enable/Disable registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define LCDC_WPMR_HEWPITE_0                   (LCDC_WPMR_HEWPITE_0_Val << LCDC_WPMR_HEWPITE_Pos)   /* (LCDC_WPMR) Disables the write protection of High-End Overlay Interrupt Enable/Disable registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_HEWPITE_1                   (LCDC_WPMR_HEWPITE_1_Val << LCDC_WPMR_HEWPITE_Pos)   /* (LCDC_WPMR) Enables the write protection of High-End Overlay Interrupt Enable/Disable registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_HEWPCRE_Pos                 _UINT32_(14)                                         /* (LCDC_WPMR) High-End Overlay Write Protection Control Registers Enable Position */
#define LCDC_WPMR_HEWPCRE_Msk                 (_UINT32_(0x1) << LCDC_WPMR_HEWPCRE_Pos)             /* (LCDC_WPMR) High-End Overlay Write Protection Control Registers Enable Mask */
#define LCDC_WPMR_HEWPCRE(value)              (LCDC_WPMR_HEWPCRE_Msk & (_UINT32_(value) << LCDC_WPMR_HEWPCRE_Pos)) /* Assigment of value for HEWPCRE in the LCDC_WPMR register */
#define   LCDC_WPMR_HEWPCRE_0_Val             _UINT32_(0x0)                                        /* (LCDC_WPMR) Disables the write protection of High-End Overlay Control registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define   LCDC_WPMR_HEWPCRE_1_Val             _UINT32_(0x1)                                        /* (LCDC_WPMR) Enables the write protection of High-End Overlay Control registers if WPKEY corresponds to 0x58 ("X" in ASCII).  */
#define LCDC_WPMR_HEWPCRE_0                   (LCDC_WPMR_HEWPCRE_0_Val << LCDC_WPMR_HEWPCRE_Pos)   /* (LCDC_WPMR) Disables the write protection of High-End Overlay Control registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_HEWPCRE_1                   (LCDC_WPMR_HEWPCRE_1_Val << LCDC_WPMR_HEWPCRE_Pos)   /* (LCDC_WPMR) Enables the write protection of High-End Overlay Control registers if WPKEY corresponds to 0x58 ("X" in ASCII). Position  */
#define LCDC_WPMR_WPKEY_Pos                   _UINT32_(24)                                         /* (LCDC_WPMR) Write Protection Key Password Position */
#define LCDC_WPMR_WPKEY_Msk                   (_UINT32_(0xFF) << LCDC_WPMR_WPKEY_Pos)              /* (LCDC_WPMR) Write Protection Key Password Mask */
#define LCDC_WPMR_WPKEY(value)                (LCDC_WPMR_WPKEY_Msk & (_UINT32_(value) << LCDC_WPMR_WPKEY_Pos)) /* Assigment of value for WPKEY in the LCDC_WPMR register */
#define   LCDC_WPMR_WPKEY_PASSWD_Val          _UINT32_(0x58)                                       /* (LCDC_WPMR) Writing any other value in this field aborts the write operation of the WPCFGEN, WPITEN, WPCREN bits.  Always reads as 0.  */
#define LCDC_WPMR_WPKEY_PASSWD                (LCDC_WPMR_WPKEY_PASSWD_Val << LCDC_WPMR_WPKEY_Pos)  /* (LCDC_WPMR) Writing any other value in this field aborts the write operation of the WPCFGEN, WPITEN, WPCREN bits.  Always reads as 0. Position  */
#define LCDC_WPMR_Msk                         _UINT32_(0xFF007FFF)                                 /* (LCDC_WPMR) Register Mask  */


/* -------- LCDC_WPSR : (LCDC Offset: 0xE8) ( R/ 32) Write Protection Status Register -------- */
#define LCDC_WPSR_RESETVALUE                  _UINT32_(0x00)                                       /*  (LCDC_WPSR) Write Protection Status Register  Reset Value */

#define LCDC_WPSR_WPVS_Pos                    _UINT32_(0)                                          /* (LCDC_WPSR) Write Protection Violation Status Position */
#define LCDC_WPSR_WPVS_Msk                    (_UINT32_(0x1) << LCDC_WPSR_WPVS_Pos)                /* (LCDC_WPSR) Write Protection Violation Status Mask */
#define LCDC_WPSR_WPVS(value)                 (LCDC_WPSR_WPVS_Msk & (_UINT32_(value) << LCDC_WPSR_WPVS_Pos)) /* Assigment of value for WPVS in the LCDC_WPSR register */
#define LCDC_WPSR_CGD_Pos                     _UINT32_(1)                                          /* (LCDC_WPSR) Clock Glitch Detected (cleared on read) Position */
#define LCDC_WPSR_CGD_Msk                     (_UINT32_(0x1) << LCDC_WPSR_CGD_Pos)                 /* (LCDC_WPSR) Clock Glitch Detected (cleared on read) Mask */
#define LCDC_WPSR_CGD(value)                  (LCDC_WPSR_CGD_Msk & (_UINT32_(value) << LCDC_WPSR_CGD_Pos)) /* Assigment of value for CGD in the LCDC_WPSR register */
#define   LCDC_WPSR_CGD_0_Val                 _UINT32_(0x0)                                        /* (LCDC_WPSR) The clock monitoring circuitry has not been corrupted since the last read of LCDC_WPSR. Under normal operating conditions, this bit is always cleared.  */
#define   LCDC_WPSR_CGD_1_Val                 _UINT32_(0x1)                                        /* (LCDC_WPSR) The clock monitoring circuitry has been corrupted since the last read of LCDC_WPSR. This flag can only be set in case of an abnormal clock signal waveform (glitch).  */
#define LCDC_WPSR_CGD_0                       (LCDC_WPSR_CGD_0_Val << LCDC_WPSR_CGD_Pos)           /* (LCDC_WPSR) The clock monitoring circuitry has not been corrupted since the last read of LCDC_WPSR. Under normal operating conditions, this bit is always cleared. Position  */
#define LCDC_WPSR_CGD_1                       (LCDC_WPSR_CGD_1_Val << LCDC_WPSR_CGD_Pos)           /* (LCDC_WPSR) The clock monitoring circuitry has been corrupted since the last read of LCDC_WPSR. This flag can only be set in case of an abnormal clock signal waveform (glitch). Position  */
#define LCDC_WPSR_SEQE_Pos                    _UINT32_(2)                                          /* (LCDC_WPSR) Internal Sequencer Error (cleared on read) Position */
#define LCDC_WPSR_SEQE_Msk                    (_UINT32_(0x1) << LCDC_WPSR_SEQE_Pos)                /* (LCDC_WPSR) Internal Sequencer Error (cleared on read) Mask */
#define LCDC_WPSR_SEQE(value)                 (LCDC_WPSR_SEQE_Msk & (_UINT32_(value) << LCDC_WPSR_SEQE_Pos)) /* Assigment of value for SEQE in the LCDC_WPSR register */
#define   LCDC_WPSR_SEQE_0_Val                _UINT32_(0x0)                                        /* (LCDC_WPSR) No peripheral internal sequencer error has occurred since the last read of LCDC_WPSR.  */
#define   LCDC_WPSR_SEQE_1_Val                _UINT32_(0x1)                                        /* (LCDC_WPSR) A peripheral internal sequencer error has occurred since the last read of LCDC_WPSR. This flag can only be set under abnormal operating conditions.  */
#define LCDC_WPSR_SEQE_0                      (LCDC_WPSR_SEQE_0_Val << LCDC_WPSR_SEQE_Pos)         /* (LCDC_WPSR) No peripheral internal sequencer error has occurred since the last read of LCDC_WPSR. Position  */
#define LCDC_WPSR_SEQE_1                      (LCDC_WPSR_SEQE_1_Val << LCDC_WPSR_SEQE_Pos)         /* (LCDC_WPSR) A peripheral internal sequencer error has occurred since the last read of LCDC_WPSR. This flag can only be set under abnormal operating conditions. Position  */
#define LCDC_WPSR_WPVSRC_Pos                  _UINT32_(8)                                          /* (LCDC_WPSR) Write Protection Violation Source Position */
#define LCDC_WPSR_WPVSRC_Msk                  (_UINT32_(0xFFFF) << LCDC_WPSR_WPVSRC_Pos)           /* (LCDC_WPSR) Write Protection Violation Source Mask */
#define LCDC_WPSR_WPVSRC(value)               (LCDC_WPSR_WPVSRC_Msk & (_UINT32_(value) << LCDC_WPSR_WPVSRC_Pos)) /* Assigment of value for WPVSRC in the LCDC_WPSR register */
#define LCDC_WPSR_Msk                         _UINT32_(0x00FFFF07)                                 /* (LCDC_WPSR) Register Mask  */


/* -------- LCDC_OVR1IER : (LCDC Offset: 0x160) ( /W 32) Overlay 1 Interrupt Enable Register -------- */
#define LCDC_OVR1IER_END_Pos                  _UINT32_(0)                                          /* (LCDC_OVR1IER) End of Frame DMA Transfer Interrupt Enable Position */
#define LCDC_OVR1IER_END_Msk                  (_UINT32_(0x1) << LCDC_OVR1IER_END_Pos)              /* (LCDC_OVR1IER) End of Frame DMA Transfer Interrupt Enable Mask */
#define LCDC_OVR1IER_END(value)               (LCDC_OVR1IER_END_Msk & (_UINT32_(value) << LCDC_OVR1IER_END_Pos)) /* Assigment of value for END in the LCDC_OVR1IER register */
#define LCDC_OVR1IER_ERROR_Pos                _UINT32_(1)                                          /* (LCDC_OVR1IER) Transfer Error Detected Interrupt Enable Position */
#define LCDC_OVR1IER_ERROR_Msk                (_UINT32_(0x1) << LCDC_OVR1IER_ERROR_Pos)            /* (LCDC_OVR1IER) Transfer Error Detected Interrupt Enable Mask */
#define LCDC_OVR1IER_ERROR(value)             (LCDC_OVR1IER_ERROR_Msk & (_UINT32_(value) << LCDC_OVR1IER_ERROR_Pos)) /* Assigment of value for ERROR in the LCDC_OVR1IER register */
#define LCDC_OVR1IER_OVF_Pos                  _UINT32_(2)                                          /* (LCDC_OVR1IER) Overflow Interrupt Enable Position */
#define LCDC_OVR1IER_OVF_Msk                  (_UINT32_(0x1) << LCDC_OVR1IER_OVF_Pos)              /* (LCDC_OVR1IER) Overflow Interrupt Enable Mask */
#define LCDC_OVR1IER_OVF(value)               (LCDC_OVR1IER_OVF_Msk & (_UINT32_(value) << LCDC_OVR1IER_OVF_Pos)) /* Assigment of value for OVF in the LCDC_OVR1IER register */
#define LCDC_OVR1IER_Msk                      _UINT32_(0x00000007)                                 /* (LCDC_OVR1IER) Register Mask  */


/* -------- LCDC_OVR1IDR : (LCDC Offset: 0x164) ( /W 32) Overlay 1 Interrupt Disable Register -------- */
#define LCDC_OVR1IDR_END_Pos                  _UINT32_(0)                                          /* (LCDC_OVR1IDR) End of Frame DMA Transfer Interrupt Disable Position */
#define LCDC_OVR1IDR_END_Msk                  (_UINT32_(0x1) << LCDC_OVR1IDR_END_Pos)              /* (LCDC_OVR1IDR) End of Frame DMA Transfer Interrupt Disable Mask */
#define LCDC_OVR1IDR_END(value)               (LCDC_OVR1IDR_END_Msk & (_UINT32_(value) << LCDC_OVR1IDR_END_Pos)) /* Assigment of value for END in the LCDC_OVR1IDR register */
#define LCDC_OVR1IDR_ERROR_Pos                _UINT32_(1)                                          /* (LCDC_OVR1IDR) Error Interrupt Disable Position */
#define LCDC_OVR1IDR_ERROR_Msk                (_UINT32_(0x1) << LCDC_OVR1IDR_ERROR_Pos)            /* (LCDC_OVR1IDR) Error Interrupt Disable Mask */
#define LCDC_OVR1IDR_ERROR(value)             (LCDC_OVR1IDR_ERROR_Msk & (_UINT32_(value) << LCDC_OVR1IDR_ERROR_Pos)) /* Assigment of value for ERROR in the LCDC_OVR1IDR register */
#define LCDC_OVR1IDR_OVF_Pos                  _UINT32_(2)                                          /* (LCDC_OVR1IDR) Overflow Interrupt Disable Position */
#define LCDC_OVR1IDR_OVF_Msk                  (_UINT32_(0x1) << LCDC_OVR1IDR_OVF_Pos)              /* (LCDC_OVR1IDR) Overflow Interrupt Disable Mask */
#define LCDC_OVR1IDR_OVF(value)               (LCDC_OVR1IDR_OVF_Msk & (_UINT32_(value) << LCDC_OVR1IDR_OVF_Pos)) /* Assigment of value for OVF in the LCDC_OVR1IDR register */
#define LCDC_OVR1IDR_Msk                      _UINT32_(0x00000007)                                 /* (LCDC_OVR1IDR) Register Mask  */


/* -------- LCDC_OVR1IMR : (LCDC Offset: 0x168) ( R/ 32) Overlay 1 Interrupt Mask Register -------- */
#define LCDC_OVR1IMR_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_OVR1IMR) Overlay 1 Interrupt Mask Register  Reset Value */

#define LCDC_OVR1IMR_END_Pos                  _UINT32_(0)                                          /* (LCDC_OVR1IMR) End of Frame DMA Transfer Interrupt Mask Position */
#define LCDC_OVR1IMR_END_Msk                  (_UINT32_(0x1) << LCDC_OVR1IMR_END_Pos)              /* (LCDC_OVR1IMR) End of Frame DMA Transfer Interrupt Mask Mask */
#define LCDC_OVR1IMR_END(value)               (LCDC_OVR1IMR_END_Msk & (_UINT32_(value) << LCDC_OVR1IMR_END_Pos)) /* Assigment of value for END in the LCDC_OVR1IMR register */
#define LCDC_OVR1IMR_ERROR_Pos                _UINT32_(1)                                          /* (LCDC_OVR1IMR) Bus Error Detected Interrupt Mask Position */
#define LCDC_OVR1IMR_ERROR_Msk                (_UINT32_(0x1) << LCDC_OVR1IMR_ERROR_Pos)            /* (LCDC_OVR1IMR) Bus Error Detected Interrupt Mask Mask */
#define LCDC_OVR1IMR_ERROR(value)             (LCDC_OVR1IMR_ERROR_Msk & (_UINT32_(value) << LCDC_OVR1IMR_ERROR_Pos)) /* Assigment of value for ERROR in the LCDC_OVR1IMR register */
#define LCDC_OVR1IMR_OVF_Pos                  _UINT32_(2)                                          /* (LCDC_OVR1IMR) Overflow Interrupt Mask Position */
#define LCDC_OVR1IMR_OVF_Msk                  (_UINT32_(0x1) << LCDC_OVR1IMR_OVF_Pos)              /* (LCDC_OVR1IMR) Overflow Interrupt Mask Mask */
#define LCDC_OVR1IMR_OVF(value)               (LCDC_OVR1IMR_OVF_Msk & (_UINT32_(value) << LCDC_OVR1IMR_OVF_Pos)) /* Assigment of value for OVF in the LCDC_OVR1IMR register */
#define LCDC_OVR1IMR_Msk                      _UINT32_(0x00000007)                                 /* (LCDC_OVR1IMR) Register Mask  */


/* -------- LCDC_OVR1ISR : (LCDC Offset: 0x16C) ( R/ 32) Overlay 1 Interrupt Status Register -------- */
#define LCDC_OVR1ISR_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_OVR1ISR) Overlay 1 Interrupt Status Register  Reset Value */

#define LCDC_OVR1ISR_END_Pos                  _UINT32_(0)                                          /* (LCDC_OVR1ISR) End of Frame DMA Transfer Position */
#define LCDC_OVR1ISR_END_Msk                  (_UINT32_(0x1) << LCDC_OVR1ISR_END_Pos)              /* (LCDC_OVR1ISR) End of Frame DMA Transfer Mask */
#define LCDC_OVR1ISR_END(value)               (LCDC_OVR1ISR_END_Msk & (_UINT32_(value) << LCDC_OVR1ISR_END_Pos)) /* Assigment of value for END in the LCDC_OVR1ISR register */
#define   LCDC_OVR1ISR_END_0_Val              _UINT32_(0x0)                                        /* (LCDC_OVR1ISR) No end of transfer has been detected since last read of LCDC_OVR1ISR.  */
#define   LCDC_OVR1ISR_END_1_Val              _UINT32_(0x1)                                        /* (LCDC_OVR1ISR) End of transfer has been detected. This flag is reset after a read operation.  */
#define LCDC_OVR1ISR_END_0                    (LCDC_OVR1ISR_END_0_Val << LCDC_OVR1ISR_END_Pos)     /* (LCDC_OVR1ISR) No end of transfer has been detected since last read of LCDC_OVR1ISR. Position  */
#define LCDC_OVR1ISR_END_1                    (LCDC_OVR1ISR_END_1_Val << LCDC_OVR1ISR_END_Pos)     /* (LCDC_OVR1ISR) End of transfer has been detected. This flag is reset after a read operation. Position  */
#define LCDC_OVR1ISR_ERROR_Pos                _UINT32_(1)                                          /* (LCDC_OVR1ISR) Bus Error Detected Position */
#define LCDC_OVR1ISR_ERROR_Msk                (_UINT32_(0x1) << LCDC_OVR1ISR_ERROR_Pos)            /* (LCDC_OVR1ISR) Bus Error Detected Mask */
#define LCDC_OVR1ISR_ERROR(value)             (LCDC_OVR1ISR_ERROR_Msk & (_UINT32_(value) << LCDC_OVR1ISR_ERROR_Pos)) /* Assigment of value for ERROR in the LCDC_OVR1ISR register */
#define   LCDC_OVR1ISR_ERROR_0_Val            _UINT32_(0x0)                                        /* (LCDC_OVR1ISR) No system bus error has been detected since the last read of LCDC_OVR1ISR.  */
#define   LCDC_OVR1ISR_ERROR_1_Val            _UINT32_(0x1)                                        /* (LCDC_OVR1ISR) A system bus error has been detected. This flag is reset after a read operation  */
#define LCDC_OVR1ISR_ERROR_0                  (LCDC_OVR1ISR_ERROR_0_Val << LCDC_OVR1ISR_ERROR_Pos) /* (LCDC_OVR1ISR) No system bus error has been detected since the last read of LCDC_OVR1ISR. Position  */
#define LCDC_OVR1ISR_ERROR_1                  (LCDC_OVR1ISR_ERROR_1_Val << LCDC_OVR1ISR_ERROR_Pos) /* (LCDC_OVR1ISR) A system bus error has been detected. This flag is reset after a read operation Position  */
#define LCDC_OVR1ISR_OVF_Pos                  _UINT32_(2)                                          /* (LCDC_OVR1ISR) Overflow Detected Position */
#define LCDC_OVR1ISR_OVF_Msk                  (_UINT32_(0x1) << LCDC_OVR1ISR_OVF_Pos)              /* (LCDC_OVR1ISR) Overflow Detected Mask */
#define LCDC_OVR1ISR_OVF(value)               (LCDC_OVR1ISR_OVF_Msk & (_UINT32_(value) << LCDC_OVR1ISR_OVF_Pos)) /* Assigment of value for OVF in the LCDC_OVR1ISR register */
#define   LCDC_OVR1ISR_OVF_0_Val              _UINT32_(0x0)                                        /* (LCDC_OVR1ISR) No overflow occurred since last read of LCDC_OVR1ISR.  */
#define   LCDC_OVR1ISR_OVF_1_Val              _UINT32_(0x1)                                        /* (LCDC_OVR1ISR) An overflow occurred, at least one DMA transfer is still running at the End Of Frame. This flag is reset after a read operation  */
#define LCDC_OVR1ISR_OVF_0                    (LCDC_OVR1ISR_OVF_0_Val << LCDC_OVR1ISR_OVF_Pos)     /* (LCDC_OVR1ISR) No overflow occurred since last read of LCDC_OVR1ISR. Position  */
#define LCDC_OVR1ISR_OVF_1                    (LCDC_OVR1ISR_OVF_1_Val << LCDC_OVR1ISR_OVF_Pos)     /* (LCDC_OVR1ISR) An overflow occurred, at least one DMA transfer is still running at the End Of Frame. This flag is reset after a read operation Position  */
#define LCDC_OVR1ISR_Msk                      _UINT32_(0x00000007)                                 /* (LCDC_OVR1ISR) Register Mask  */


/* -------- LCDC_OVR1EN : (LCDC Offset: 0x170) (R/W 32) Overlay 1 Enable Register -------- */
#define LCDC_OVR1EN_RESETVALUE                _UINT32_(0x00)                                       /*  (LCDC_OVR1EN) Overlay 1 Enable Register  Reset Value */

#define LCDC_OVR1EN_ENABLE_Pos                _UINT32_(0)                                          /* (LCDC_OVR1EN) Layer Enable Position */
#define LCDC_OVR1EN_ENABLE_Msk                (_UINT32_(0x1) << LCDC_OVR1EN_ENABLE_Pos)            /* (LCDC_OVR1EN) Layer Enable Mask */
#define LCDC_OVR1EN_ENABLE(value)             (LCDC_OVR1EN_ENABLE_Msk & (_UINT32_(value) << LCDC_OVR1EN_ENABLE_Pos)) /* Assigment of value for ENABLE in the LCDC_OVR1EN register */
#define   LCDC_OVR1EN_ENABLE_0_Val            _UINT32_(0x0)                                        /* (LCDC_OVR1EN) The layer is disabled.  */
#define   LCDC_OVR1EN_ENABLE_1_Val            _UINT32_(0x1)                                        /* (LCDC_OVR1EN) The layer is enabled.  */
#define LCDC_OVR1EN_ENABLE_0                  (LCDC_OVR1EN_ENABLE_0_Val << LCDC_OVR1EN_ENABLE_Pos) /* (LCDC_OVR1EN) The layer is disabled. Position  */
#define LCDC_OVR1EN_ENABLE_1                  (LCDC_OVR1EN_ENABLE_1_Val << LCDC_OVR1EN_ENABLE_Pos) /* (LCDC_OVR1EN) The layer is enabled. Position  */
#define LCDC_OVR1EN_Msk                       _UINT32_(0x00000001)                                 /* (LCDC_OVR1EN) Register Mask  */


/* -------- LCDC_OVR1CLA : (LCDC Offset: 0x174) (R/W 32) Overlay 1 Color Table Address Register -------- */
#define LCDC_OVR1CLA_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_OVR1CLA) Overlay 1 Color Table Address Register  Reset Value */

#define LCDC_OVR1CLA_CLA_Pos                  _UINT32_(2)                                          /* (LCDC_OVR1CLA) Overlay 1 CLUT Address Position */
#define LCDC_OVR1CLA_CLA_Msk                  (_UINT32_(0x3FFFFFFF) << LCDC_OVR1CLA_CLA_Pos)       /* (LCDC_OVR1CLA) Overlay 1 CLUT Address Mask */
#define LCDC_OVR1CLA_CLA(value)               (LCDC_OVR1CLA_CLA_Msk & (_UINT32_(value) << LCDC_OVR1CLA_CLA_Pos)) /* Assigment of value for CLA in the LCDC_OVR1CLA register */
#define LCDC_OVR1CLA_Msk                      _UINT32_(0xFFFFFFFC)                                 /* (LCDC_OVR1CLA) Register Mask  */


/* -------- LCDC_OVR1FBA : (LCDC Offset: 0x178) (R/W 32) Overlay 1 Frame Buffer Address Register -------- */
#define LCDC_OVR1FBA_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_OVR1FBA) Overlay 1 Frame Buffer Address Register  Reset Value */

#define LCDC_OVR1FBA_FBA_Pos                  _UINT32_(0)                                          /* (LCDC_OVR1FBA) Frame Buffer Address Position */
#define LCDC_OVR1FBA_FBA_Msk                  (_UINT32_(0xFFFFFFFF) << LCDC_OVR1FBA_FBA_Pos)       /* (LCDC_OVR1FBA) Frame Buffer Address Mask */
#define LCDC_OVR1FBA_FBA(value)               (LCDC_OVR1FBA_FBA_Msk & (_UINT32_(value) << LCDC_OVR1FBA_FBA_Pos)) /* Assigment of value for FBA in the LCDC_OVR1FBA register */
#define LCDC_OVR1FBA_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (LCDC_OVR1FBA) Register Mask  */


/* -------- LCDC_OVR1CFG0 : (LCDC Offset: 0x17C) (R/W 32) Overlay 1 Configuration Register 0 -------- */
#define LCDC_OVR1CFG0_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_OVR1CFG0) Overlay 1 Configuration Register 0  Reset Value */

#define LCDC_OVR1CFG0_BLEN_Pos                _UINT32_(4)                                          /* (LCDC_OVR1CFG0) System Bus Burst Length Position */
#define LCDC_OVR1CFG0_BLEN_Msk                (_UINT32_(0x7) << LCDC_OVR1CFG0_BLEN_Pos)            /* (LCDC_OVR1CFG0) System Bus Burst Length Mask */
#define LCDC_OVR1CFG0_BLEN(value)             (LCDC_OVR1CFG0_BLEN_Msk & (_UINT32_(value) << LCDC_OVR1CFG0_BLEN_Pos)) /* Assigment of value for BLEN in the LCDC_OVR1CFG0 register */
#define   LCDC_OVR1CFG0_BLEN_INCR1_Val        _UINT32_(0x0)                                        /* (LCDC_OVR1CFG0) System bus access is started as soon as there is enough space in the FIFO to store one data.  */
#define   LCDC_OVR1CFG0_BLEN_INCR4_Val        _UINT32_(0x1)                                        /* (LCDC_OVR1CFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 4 data. A system bus INCR4 Burst is used by default. INCR1 is used for bursts less than 4.  */
#define   LCDC_OVR1CFG0_BLEN_INCR8_Val        _UINT32_(0x2)                                        /* (LCDC_OVR1CFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 8 data. A system bus INCR8 Burst is used by default. INCR4 bursts are used for burst of 4 beats. INCR1 is used for bursts less than 4.  */
#define   LCDC_OVR1CFG0_BLEN_INCR16_Val       _UINT32_(0x3)                                        /* (LCDC_OVR1CFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 16 data. A system bus INCR16 Burst is used by default. INCR8 and INCR4 bursts are respectively used for burst of 8 and 4 beats. INCR1 is used for bursts less than 4.  */
#define   LCDC_OVR1CFG0_BLEN_INCR32_Val       _UINT32_(0x4)                                        /* (LCDC_OVR1CFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 32 data. A system bus INCR32 Burst is used by default. INCR16, INCR8 and INCR4 bursts are respectively used for burst of 16, 8 and 4 beats. INCR1 is used for bursts less than 4.  */
#define LCDC_OVR1CFG0_BLEN_INCR1              (LCDC_OVR1CFG0_BLEN_INCR1_Val << LCDC_OVR1CFG0_BLEN_Pos) /* (LCDC_OVR1CFG0) System bus access is started as soon as there is enough space in the FIFO to store one data. Position  */
#define LCDC_OVR1CFG0_BLEN_INCR4              (LCDC_OVR1CFG0_BLEN_INCR4_Val << LCDC_OVR1CFG0_BLEN_Pos) /* (LCDC_OVR1CFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 4 data. A system bus INCR4 Burst is used by default. INCR1 is used for bursts less than 4. Position  */
#define LCDC_OVR1CFG0_BLEN_INCR8              (LCDC_OVR1CFG0_BLEN_INCR8_Val << LCDC_OVR1CFG0_BLEN_Pos) /* (LCDC_OVR1CFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 8 data. A system bus INCR8 Burst is used by default. INCR4 bursts are used for burst of 4 beats. INCR1 is used for bursts less than 4. Position  */
#define LCDC_OVR1CFG0_BLEN_INCR16             (LCDC_OVR1CFG0_BLEN_INCR16_Val << LCDC_OVR1CFG0_BLEN_Pos) /* (LCDC_OVR1CFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 16 data. A system bus INCR16 Burst is used by default. INCR8 and INCR4 bursts are respectively used for burst of 8 and 4 beats. INCR1 is used for bursts less than 4. Position  */
#define LCDC_OVR1CFG0_BLEN_INCR32             (LCDC_OVR1CFG0_BLEN_INCR32_Val << LCDC_OVR1CFG0_BLEN_Pos) /* (LCDC_OVR1CFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 32 data. A system bus INCR32 Burst is used by default. INCR16, INCR8 and INCR4 bursts are respectively used for burst of 16, 8 and 4 beats. INCR1 is used for bursts less than 4. Position  */
#define LCDC_OVR1CFG0_Msk                     _UINT32_(0x00000070)                                 /* (LCDC_OVR1CFG0) Register Mask  */


/* -------- LCDC_OVR1CFG1 : (LCDC Offset: 0x180) (R/W 32) Overlay 1 Configuration Register 1 -------- */
#define LCDC_OVR1CFG1_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_OVR1CFG1) Overlay 1 Configuration Register 1  Reset Value */

#define LCDC_OVR1CFG1_CLUTEN_Pos              _UINT32_(0)                                          /* (LCDC_OVR1CFG1) CLUT Mode Enable Position */
#define LCDC_OVR1CFG1_CLUTEN_Msk              (_UINT32_(0x1) << LCDC_OVR1CFG1_CLUTEN_Pos)          /* (LCDC_OVR1CFG1) CLUT Mode Enable Mask */
#define LCDC_OVR1CFG1_CLUTEN(value)           (LCDC_OVR1CFG1_CLUTEN_Msk & (_UINT32_(value) << LCDC_OVR1CFG1_CLUTEN_Pos)) /* Assigment of value for CLUTEN in the LCDC_OVR1CFG1 register */
#define   LCDC_OVR1CFG1_CLUTEN_0_Val          _UINT32_(0x0)                                        /* (LCDC_OVR1CFG1) RGB mode is selected.  */
#define   LCDC_OVR1CFG1_CLUTEN_1_Val          _UINT32_(0x1)                                        /* (LCDC_OVR1CFG1) CLUT mode is selected.  */
#define LCDC_OVR1CFG1_CLUTEN_0                (LCDC_OVR1CFG1_CLUTEN_0_Val << LCDC_OVR1CFG1_CLUTEN_Pos) /* (LCDC_OVR1CFG1) RGB mode is selected. Position  */
#define LCDC_OVR1CFG1_CLUTEN_1                (LCDC_OVR1CFG1_CLUTEN_1_Val << LCDC_OVR1CFG1_CLUTEN_Pos) /* (LCDC_OVR1CFG1) CLUT mode is selected. Position  */
#define LCDC_OVR1CFG1_GAM_Pos                 _UINT32_(2)                                          /* (LCDC_OVR1CFG1) Gamma Correction Position */
#define LCDC_OVR1CFG1_GAM_Msk                 (_UINT32_(0x1) << LCDC_OVR1CFG1_GAM_Pos)             /* (LCDC_OVR1CFG1) Gamma Correction Mask */
#define LCDC_OVR1CFG1_GAM(value)              (LCDC_OVR1CFG1_GAM_Msk & (_UINT32_(value) << LCDC_OVR1CFG1_GAM_Pos)) /* Assigment of value for GAM in the LCDC_OVR1CFG1 register */
#define   LCDC_OVR1CFG1_GAM_0_Val             _UINT32_(0x0)                                        /* (LCDC_OVR1CFG1) Gamma correction is disabled  */
#define   LCDC_OVR1CFG1_GAM_1_Val             _UINT32_(0x1)                                        /* (LCDC_OVR1CFG1) Gamma correction is enabled  */
#define LCDC_OVR1CFG1_GAM_0                   (LCDC_OVR1CFG1_GAM_0_Val << LCDC_OVR1CFG1_GAM_Pos)   /* (LCDC_OVR1CFG1) Gamma correction is disabled Position  */
#define LCDC_OVR1CFG1_GAM_1                   (LCDC_OVR1CFG1_GAM_1_Val << LCDC_OVR1CFG1_GAM_Pos)   /* (LCDC_OVR1CFG1) Gamma correction is enabled Position  */
#define LCDC_OVR1CFG1_RGBMODE_Pos             _UINT32_(4)                                          /* (LCDC_OVR1CFG1) RGB Mode Input Selection Position */
#define LCDC_OVR1CFG1_RGBMODE_Msk             (_UINT32_(0xF) << LCDC_OVR1CFG1_RGBMODE_Pos)         /* (LCDC_OVR1CFG1) RGB Mode Input Selection Mask */
#define LCDC_OVR1CFG1_RGBMODE(value)          (LCDC_OVR1CFG1_RGBMODE_Msk & (_UINT32_(value) << LCDC_OVR1CFG1_RGBMODE_Pos)) /* Assigment of value for RGBMODE in the LCDC_OVR1CFG1 register */
#define   LCDC_OVR1CFG1_RGBMODE_12BPP_RGB_444_Val _UINT32_(0x0)                                        /* (LCDC_OVR1CFG1) 12 bpp RGB 444  */
#define   LCDC_OVR1CFG1_RGBMODE_16BPP_ARGB_4444_Val _UINT32_(0x1)                                        /* (LCDC_OVR1CFG1) 16 bpp ARGB 4444  */
#define   LCDC_OVR1CFG1_RGBMODE_16BPP_RGBA_4444_Val _UINT32_(0x2)                                        /* (LCDC_OVR1CFG1) 16 bpp RGBA 4444  */
#define   LCDC_OVR1CFG1_RGBMODE_16BPP_RGB_565_Val _UINT32_(0x3)                                        /* (LCDC_OVR1CFG1) 16 bpp RGB 565  */
#define   LCDC_OVR1CFG1_RGBMODE_16BPP_ARGB_1555_Val _UINT32_(0x4)                                        /* (LCDC_OVR1CFG1) 16 bpp ARGB 1555  */
#define   LCDC_OVR1CFG1_RGBMODE_18BPP_RGB_666_Val _UINT32_(0x5)                                        /* (LCDC_OVR1CFG1) 18 bpp RGB 666  */
#define   LCDC_OVR1CFG1_RGBMODE_18BPP_RGB_666PACKED_Val _UINT32_(0x6)                                        /* (LCDC_OVR1CFG1) 18 bpp RGB 666 PACKED  */
#define   LCDC_OVR1CFG1_RGBMODE_19BPP_ARGB_1666_Val _UINT32_(0x7)                                        /* (LCDC_OVR1CFG1) 19 bpp ARGB 1666  */
#define   LCDC_OVR1CFG1_RGBMODE_19BPP_ARGB_PACKED_Val _UINT32_(0x8)                                        /* (LCDC_OVR1CFG1) 19 bpp ARGB 1666 PACKED  */
#define   LCDC_OVR1CFG1_RGBMODE_24BPP_RGB_888_Val _UINT32_(0x9)                                        /* (LCDC_OVR1CFG1) 24 bpp RGB 888  */
#define   LCDC_OVR1CFG1_RGBMODE_24BPP_RGB_888_PACKED_Val _UINT32_(0xA)                                        /* (LCDC_OVR1CFG1) 24 bpp RGB 888 PACKED  */
#define   LCDC_OVR1CFG1_RGBMODE_25BPP_ARGB_1888_Val _UINT32_(0xB)                                        /* (LCDC_OVR1CFG1) 25 bpp ARGB 1888  */
#define   LCDC_OVR1CFG1_RGBMODE_32BPP_ARGB_8888_Val _UINT32_(0xC)                                        /* (LCDC_OVR1CFG1) 32 bpp ARGB 8888  */
#define   LCDC_OVR1CFG1_RGBMODE_32BPP_RGBA_8888_Val _UINT32_(0xD)                                        /* (LCDC_OVR1CFG1) 32 bpp RGBA 8888  */
#define LCDC_OVR1CFG1_RGBMODE_12BPP_RGB_444   (LCDC_OVR1CFG1_RGBMODE_12BPP_RGB_444_Val << LCDC_OVR1CFG1_RGBMODE_Pos) /* (LCDC_OVR1CFG1) 12 bpp RGB 444 Position  */
#define LCDC_OVR1CFG1_RGBMODE_16BPP_ARGB_4444 (LCDC_OVR1CFG1_RGBMODE_16BPP_ARGB_4444_Val << LCDC_OVR1CFG1_RGBMODE_Pos) /* (LCDC_OVR1CFG1) 16 bpp ARGB 4444 Position  */
#define LCDC_OVR1CFG1_RGBMODE_16BPP_RGBA_4444 (LCDC_OVR1CFG1_RGBMODE_16BPP_RGBA_4444_Val << LCDC_OVR1CFG1_RGBMODE_Pos) /* (LCDC_OVR1CFG1) 16 bpp RGBA 4444 Position  */
#define LCDC_OVR1CFG1_RGBMODE_16BPP_RGB_565   (LCDC_OVR1CFG1_RGBMODE_16BPP_RGB_565_Val << LCDC_OVR1CFG1_RGBMODE_Pos) /* (LCDC_OVR1CFG1) 16 bpp RGB 565 Position  */
#define LCDC_OVR1CFG1_RGBMODE_16BPP_ARGB_1555 (LCDC_OVR1CFG1_RGBMODE_16BPP_ARGB_1555_Val << LCDC_OVR1CFG1_RGBMODE_Pos) /* (LCDC_OVR1CFG1) 16 bpp ARGB 1555 Position  */
#define LCDC_OVR1CFG1_RGBMODE_18BPP_RGB_666   (LCDC_OVR1CFG1_RGBMODE_18BPP_RGB_666_Val << LCDC_OVR1CFG1_RGBMODE_Pos) /* (LCDC_OVR1CFG1) 18 bpp RGB 666 Position  */
#define LCDC_OVR1CFG1_RGBMODE_18BPP_RGB_666PACKED (LCDC_OVR1CFG1_RGBMODE_18BPP_RGB_666PACKED_Val << LCDC_OVR1CFG1_RGBMODE_Pos) /* (LCDC_OVR1CFG1) 18 bpp RGB 666 PACKED Position  */
#define LCDC_OVR1CFG1_RGBMODE_19BPP_ARGB_1666 (LCDC_OVR1CFG1_RGBMODE_19BPP_ARGB_1666_Val << LCDC_OVR1CFG1_RGBMODE_Pos) /* (LCDC_OVR1CFG1) 19 bpp ARGB 1666 Position  */
#define LCDC_OVR1CFG1_RGBMODE_19BPP_ARGB_PACKED (LCDC_OVR1CFG1_RGBMODE_19BPP_ARGB_PACKED_Val << LCDC_OVR1CFG1_RGBMODE_Pos) /* (LCDC_OVR1CFG1) 19 bpp ARGB 1666 PACKED Position  */
#define LCDC_OVR1CFG1_RGBMODE_24BPP_RGB_888   (LCDC_OVR1CFG1_RGBMODE_24BPP_RGB_888_Val << LCDC_OVR1CFG1_RGBMODE_Pos) /* (LCDC_OVR1CFG1) 24 bpp RGB 888 Position  */
#define LCDC_OVR1CFG1_RGBMODE_24BPP_RGB_888_PACKED (LCDC_OVR1CFG1_RGBMODE_24BPP_RGB_888_PACKED_Val << LCDC_OVR1CFG1_RGBMODE_Pos) /* (LCDC_OVR1CFG1) 24 bpp RGB 888 PACKED Position  */
#define LCDC_OVR1CFG1_RGBMODE_25BPP_ARGB_1888 (LCDC_OVR1CFG1_RGBMODE_25BPP_ARGB_1888_Val << LCDC_OVR1CFG1_RGBMODE_Pos) /* (LCDC_OVR1CFG1) 25 bpp ARGB 1888 Position  */
#define LCDC_OVR1CFG1_RGBMODE_32BPP_ARGB_8888 (LCDC_OVR1CFG1_RGBMODE_32BPP_ARGB_8888_Val << LCDC_OVR1CFG1_RGBMODE_Pos) /* (LCDC_OVR1CFG1) 32 bpp ARGB 8888 Position  */
#define LCDC_OVR1CFG1_RGBMODE_32BPP_RGBA_8888 (LCDC_OVR1CFG1_RGBMODE_32BPP_RGBA_8888_Val << LCDC_OVR1CFG1_RGBMODE_Pos) /* (LCDC_OVR1CFG1) 32 bpp RGBA 8888 Position  */
#define LCDC_OVR1CFG1_CLUTMODE_Pos            _UINT32_(8)                                          /* (LCDC_OVR1CFG1) CLUT Mode Input Selection Position */
#define LCDC_OVR1CFG1_CLUTMODE_Msk            (_UINT32_(0x3) << LCDC_OVR1CFG1_CLUTMODE_Pos)        /* (LCDC_OVR1CFG1) CLUT Mode Input Selection Mask */
#define LCDC_OVR1CFG1_CLUTMODE(value)         (LCDC_OVR1CFG1_CLUTMODE_Msk & (_UINT32_(value) << LCDC_OVR1CFG1_CLUTMODE_Pos)) /* Assigment of value for CLUTMODE in the LCDC_OVR1CFG1 register */
#define   LCDC_OVR1CFG1_CLUTMODE_CLUT_1BPP_Val _UINT32_(0x0)                                        /* (LCDC_OVR1CFG1) CLUT mode set to 1 bit per pixel  */
#define   LCDC_OVR1CFG1_CLUTMODE_CLUT_2BPP_Val _UINT32_(0x1)                                        /* (LCDC_OVR1CFG1) CLUT mode set to 2 bits per pixel  */
#define   LCDC_OVR1CFG1_CLUTMODE_CLUT_4BPP_Val _UINT32_(0x2)                                        /* (LCDC_OVR1CFG1) CLUT mode set to 4 bits per pixel  */
#define   LCDC_OVR1CFG1_CLUTMODE_CLUT_8BPP_Val _UINT32_(0x3)                                        /* (LCDC_OVR1CFG1) CLUT mode set to 8 bits per pixel  */
#define LCDC_OVR1CFG1_CLUTMODE_CLUT_1BPP      (LCDC_OVR1CFG1_CLUTMODE_CLUT_1BPP_Val << LCDC_OVR1CFG1_CLUTMODE_Pos) /* (LCDC_OVR1CFG1) CLUT mode set to 1 bit per pixel Position  */
#define LCDC_OVR1CFG1_CLUTMODE_CLUT_2BPP      (LCDC_OVR1CFG1_CLUTMODE_CLUT_2BPP_Val << LCDC_OVR1CFG1_CLUTMODE_Pos) /* (LCDC_OVR1CFG1) CLUT mode set to 2 bits per pixel Position  */
#define LCDC_OVR1CFG1_CLUTMODE_CLUT_4BPP      (LCDC_OVR1CFG1_CLUTMODE_CLUT_4BPP_Val << LCDC_OVR1CFG1_CLUTMODE_Pos) /* (LCDC_OVR1CFG1) CLUT mode set to 4 bits per pixel Position  */
#define LCDC_OVR1CFG1_CLUTMODE_CLUT_8BPP      (LCDC_OVR1CFG1_CLUTMODE_CLUT_8BPP_Val << LCDC_OVR1CFG1_CLUTMODE_Pos) /* (LCDC_OVR1CFG1) CLUT mode set to 8 bits per pixel Position  */
#define LCDC_OVR1CFG1_Msk                     _UINT32_(0x000003F5)                                 /* (LCDC_OVR1CFG1) Register Mask  */


/* -------- LCDC_OVR1CFG2 : (LCDC Offset: 0x184) (R/W 32) Overlay 1 Configuration Register 2 -------- */
#define LCDC_OVR1CFG2_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_OVR1CFG2) Overlay 1 Configuration Register 2  Reset Value */

#define LCDC_OVR1CFG2_XPOS_Pos                _UINT32_(0)                                          /* (LCDC_OVR1CFG2) Horizontal Window Position Position */
#define LCDC_OVR1CFG2_XPOS_Msk                (_UINT32_(0x7FF) << LCDC_OVR1CFG2_XPOS_Pos)          /* (LCDC_OVR1CFG2) Horizontal Window Position Mask */
#define LCDC_OVR1CFG2_XPOS(value)             (LCDC_OVR1CFG2_XPOS_Msk & (_UINT32_(value) << LCDC_OVR1CFG2_XPOS_Pos)) /* Assigment of value for XPOS in the LCDC_OVR1CFG2 register */
#define LCDC_OVR1CFG2_YPOS_Pos                _UINT32_(16)                                         /* (LCDC_OVR1CFG2) Vertical Window Position Position */
#define LCDC_OVR1CFG2_YPOS_Msk                (_UINT32_(0x7FF) << LCDC_OVR1CFG2_YPOS_Pos)          /* (LCDC_OVR1CFG2) Vertical Window Position Mask */
#define LCDC_OVR1CFG2_YPOS(value)             (LCDC_OVR1CFG2_YPOS_Msk & (_UINT32_(value) << LCDC_OVR1CFG2_YPOS_Pos)) /* Assigment of value for YPOS in the LCDC_OVR1CFG2 register */
#define LCDC_OVR1CFG2_Msk                     _UINT32_(0x07FF07FF)                                 /* (LCDC_OVR1CFG2) Register Mask  */


/* -------- LCDC_OVR1CFG3 : (LCDC Offset: 0x188) (R/W 32) Overlay 1 Configuration Register 3 -------- */
#define LCDC_OVR1CFG3_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_OVR1CFG3) Overlay 1 Configuration Register 3  Reset Value */

#define LCDC_OVR1CFG3_XSIZE_Pos               _UINT32_(0)                                          /* (LCDC_OVR1CFG3) Horizontal Window Size Position */
#define LCDC_OVR1CFG3_XSIZE_Msk               (_UINT32_(0x7FF) << LCDC_OVR1CFG3_XSIZE_Pos)         /* (LCDC_OVR1CFG3) Horizontal Window Size Mask */
#define LCDC_OVR1CFG3_XSIZE(value)            (LCDC_OVR1CFG3_XSIZE_Msk & (_UINT32_(value) << LCDC_OVR1CFG3_XSIZE_Pos)) /* Assigment of value for XSIZE in the LCDC_OVR1CFG3 register */
#define LCDC_OVR1CFG3_YSIZE_Pos               _UINT32_(16)                                         /* (LCDC_OVR1CFG3) Vertical Window Size Position */
#define LCDC_OVR1CFG3_YSIZE_Msk               (_UINT32_(0x7FF) << LCDC_OVR1CFG3_YSIZE_Pos)         /* (LCDC_OVR1CFG3) Vertical Window Size Mask */
#define LCDC_OVR1CFG3_YSIZE(value)            (LCDC_OVR1CFG3_YSIZE_Msk & (_UINT32_(value) << LCDC_OVR1CFG3_YSIZE_Pos)) /* Assigment of value for YSIZE in the LCDC_OVR1CFG3 register */
#define LCDC_OVR1CFG3_Msk                     _UINT32_(0x07FF07FF)                                 /* (LCDC_OVR1CFG3) Register Mask  */


/* -------- LCDC_OVR1CFG4 : (LCDC Offset: 0x18C) (R/W 32) Overlay 1 Configuration Register 4 -------- */
#define LCDC_OVR1CFG4_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_OVR1CFG4) Overlay 1 Configuration Register 4  Reset Value */

#define LCDC_OVR1CFG4_XSTRIDE_Pos             _UINT32_(0)                                          /* (LCDC_OVR1CFG4) Horizontal Stride Position */
#define LCDC_OVR1CFG4_XSTRIDE_Msk             (_UINT32_(0xFFFFFFFF) << LCDC_OVR1CFG4_XSTRIDE_Pos)  /* (LCDC_OVR1CFG4) Horizontal Stride Mask */
#define LCDC_OVR1CFG4_XSTRIDE(value)          (LCDC_OVR1CFG4_XSTRIDE_Msk & (_UINT32_(value) << LCDC_OVR1CFG4_XSTRIDE_Pos)) /* Assigment of value for XSTRIDE in the LCDC_OVR1CFG4 register */
#define LCDC_OVR1CFG4_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (LCDC_OVR1CFG4) Register Mask  */


/* -------- LCDC_OVR1CFG5 : (LCDC Offset: 0x190) (R/W 32) Overlay 1 Configuration Register 5 -------- */
#define LCDC_OVR1CFG5_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_OVR1CFG5) Overlay 1 Configuration Register 5  Reset Value */

#define LCDC_OVR1CFG5_PSTRIDE_Pos             _UINT32_(0)                                          /* (LCDC_OVR1CFG5) Pixel Stride Position */
#define LCDC_OVR1CFG5_PSTRIDE_Msk             (_UINT32_(0xFFFFFFFF) << LCDC_OVR1CFG5_PSTRIDE_Pos)  /* (LCDC_OVR1CFG5) Pixel Stride Mask */
#define LCDC_OVR1CFG5_PSTRIDE(value)          (LCDC_OVR1CFG5_PSTRIDE_Msk & (_UINT32_(value) << LCDC_OVR1CFG5_PSTRIDE_Pos)) /* Assigment of value for PSTRIDE in the LCDC_OVR1CFG5 register */
#define LCDC_OVR1CFG5_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (LCDC_OVR1CFG5) Register Mask  */


/* -------- LCDC_OVR1CFG6 : (LCDC Offset: 0x194) (R/W 32) Overlay 1 Configuration Register 6 -------- */
#define LCDC_OVR1CFG6_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_OVR1CFG6) Overlay 1 Configuration Register 6  Reset Value */

#define LCDC_OVR1CFG6_BDEF_Pos                _UINT32_(0)                                          /* (LCDC_OVR1CFG6) Blue Default Position */
#define LCDC_OVR1CFG6_BDEF_Msk                (_UINT32_(0xFF) << LCDC_OVR1CFG6_BDEF_Pos)           /* (LCDC_OVR1CFG6) Blue Default Mask */
#define LCDC_OVR1CFG6_BDEF(value)             (LCDC_OVR1CFG6_BDEF_Msk & (_UINT32_(value) << LCDC_OVR1CFG6_BDEF_Pos)) /* Assigment of value for BDEF in the LCDC_OVR1CFG6 register */
#define LCDC_OVR1CFG6_GDEF_Pos                _UINT32_(8)                                          /* (LCDC_OVR1CFG6) Green Default Position */
#define LCDC_OVR1CFG6_GDEF_Msk                (_UINT32_(0xFF) << LCDC_OVR1CFG6_GDEF_Pos)           /* (LCDC_OVR1CFG6) Green Default Mask */
#define LCDC_OVR1CFG6_GDEF(value)             (LCDC_OVR1CFG6_GDEF_Msk & (_UINT32_(value) << LCDC_OVR1CFG6_GDEF_Pos)) /* Assigment of value for GDEF in the LCDC_OVR1CFG6 register */
#define LCDC_OVR1CFG6_RDEF_Pos                _UINT32_(16)                                         /* (LCDC_OVR1CFG6) Red Default Position */
#define LCDC_OVR1CFG6_RDEF_Msk                (_UINT32_(0xFF) << LCDC_OVR1CFG6_RDEF_Pos)           /* (LCDC_OVR1CFG6) Red Default Mask */
#define LCDC_OVR1CFG6_RDEF(value)             (LCDC_OVR1CFG6_RDEF_Msk & (_UINT32_(value) << LCDC_OVR1CFG6_RDEF_Pos)) /* Assigment of value for RDEF in the LCDC_OVR1CFG6 register */
#define LCDC_OVR1CFG6_Msk                     _UINT32_(0x00FFFFFF)                                 /* (LCDC_OVR1CFG6) Register Mask  */


/* -------- LCDC_OVR1CFG7 : (LCDC Offset: 0x198) (R/W 32) Overlay 1 Configuration Register 7 -------- */
#define LCDC_OVR1CFG7_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_OVR1CFG7) Overlay 1 Configuration Register 7  Reset Value */

#define LCDC_OVR1CFG7_BKEY_Pos                _UINT32_(0)                                          /* (LCDC_OVR1CFG7) Blue Color Component Chroma Key Position */
#define LCDC_OVR1CFG7_BKEY_Msk                (_UINT32_(0xFF) << LCDC_OVR1CFG7_BKEY_Pos)           /* (LCDC_OVR1CFG7) Blue Color Component Chroma Key Mask */
#define LCDC_OVR1CFG7_BKEY(value)             (LCDC_OVR1CFG7_BKEY_Msk & (_UINT32_(value) << LCDC_OVR1CFG7_BKEY_Pos)) /* Assigment of value for BKEY in the LCDC_OVR1CFG7 register */
#define LCDC_OVR1CFG7_GKEY_Pos                _UINT32_(8)                                          /* (LCDC_OVR1CFG7) Green Color Component Chroma Key Position */
#define LCDC_OVR1CFG7_GKEY_Msk                (_UINT32_(0xFF) << LCDC_OVR1CFG7_GKEY_Pos)           /* (LCDC_OVR1CFG7) Green Color Component Chroma Key Mask */
#define LCDC_OVR1CFG7_GKEY(value)             (LCDC_OVR1CFG7_GKEY_Msk & (_UINT32_(value) << LCDC_OVR1CFG7_GKEY_Pos)) /* Assigment of value for GKEY in the LCDC_OVR1CFG7 register */
#define LCDC_OVR1CFG7_RKEY_Pos                _UINT32_(16)                                         /* (LCDC_OVR1CFG7) Red Color Component Chroma Key Position */
#define LCDC_OVR1CFG7_RKEY_Msk                (_UINT32_(0xFF) << LCDC_OVR1CFG7_RKEY_Pos)           /* (LCDC_OVR1CFG7) Red Color Component Chroma Key Mask */
#define LCDC_OVR1CFG7_RKEY(value)             (LCDC_OVR1CFG7_RKEY_Msk & (_UINT32_(value) << LCDC_OVR1CFG7_RKEY_Pos)) /* Assigment of value for RKEY in the LCDC_OVR1CFG7 register */
#define LCDC_OVR1CFG7_Msk                     _UINT32_(0x00FFFFFF)                                 /* (LCDC_OVR1CFG7) Register Mask  */


/* -------- LCDC_OVR1CFG8 : (LCDC Offset: 0x19C) (R/W 32) Overlay 1 Configuration Register 8 -------- */
#define LCDC_OVR1CFG8_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_OVR1CFG8) Overlay 1 Configuration Register 8  Reset Value */

#define LCDC_OVR1CFG8_BMASK_Pos               _UINT32_(0)                                          /* (LCDC_OVR1CFG8) Blue Color Component Chroma Key Mask Position */
#define LCDC_OVR1CFG8_BMASK_Msk               (_UINT32_(0xFF) << LCDC_OVR1CFG8_BMASK_Pos)          /* (LCDC_OVR1CFG8) Blue Color Component Chroma Key Mask Mask */
#define LCDC_OVR1CFG8_BMASK(value)            (LCDC_OVR1CFG8_BMASK_Msk & (_UINT32_(value) << LCDC_OVR1CFG8_BMASK_Pos)) /* Assigment of value for BMASK in the LCDC_OVR1CFG8 register */
#define LCDC_OVR1CFG8_GMASK_Pos               _UINT32_(8)                                          /* (LCDC_OVR1CFG8) Green Color Component Chroma Key Mask Position */
#define LCDC_OVR1CFG8_GMASK_Msk               (_UINT32_(0xFF) << LCDC_OVR1CFG8_GMASK_Pos)          /* (LCDC_OVR1CFG8) Green Color Component Chroma Key Mask Mask */
#define LCDC_OVR1CFG8_GMASK(value)            (LCDC_OVR1CFG8_GMASK_Msk & (_UINT32_(value) << LCDC_OVR1CFG8_GMASK_Pos)) /* Assigment of value for GMASK in the LCDC_OVR1CFG8 register */
#define LCDC_OVR1CFG8_RMASK_Pos               _UINT32_(16)                                         /* (LCDC_OVR1CFG8) Red Color Component Chroma Key Mask Position */
#define LCDC_OVR1CFG8_RMASK_Msk               (_UINT32_(0xFF) << LCDC_OVR1CFG8_RMASK_Pos)          /* (LCDC_OVR1CFG8) Red Color Component Chroma Key Mask Mask */
#define LCDC_OVR1CFG8_RMASK(value)            (LCDC_OVR1CFG8_RMASK_Msk & (_UINT32_(value) << LCDC_OVR1CFG8_RMASK_Pos)) /* Assigment of value for RMASK in the LCDC_OVR1CFG8 register */
#define LCDC_OVR1CFG8_Msk                     _UINT32_(0x00FFFFFF)                                 /* (LCDC_OVR1CFG8) Register Mask  */


/* -------- LCDC_OVR1CFG9 : (LCDC Offset: 0x1A0) (R/W 32) Overlay 1 Configuration Register 9 -------- */
#define LCDC_OVR1CFG9_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_OVR1CFG9) Overlay 1 Configuration Register 9  Reset Value */

#define LCDC_OVR1CFG9_DMA_Pos                 _UINT32_(0)                                          /* (LCDC_OVR1CFG9) DMA Enable Position */
#define LCDC_OVR1CFG9_DMA_Msk                 (_UINT32_(0x1) << LCDC_OVR1CFG9_DMA_Pos)             /* (LCDC_OVR1CFG9) DMA Enable Mask */
#define LCDC_OVR1CFG9_DMA(value)              (LCDC_OVR1CFG9_DMA_Msk & (_UINT32_(value) << LCDC_OVR1CFG9_DMA_Pos)) /* Assigment of value for DMA in the LCDC_OVR1CFG9 register */
#define   LCDC_OVR1CFG9_DMA_0_Val             _UINT32_(0x0)                                        /* (LCDC_OVR1CFG9) The pixel for the current layer is retrieved from the default color register.  */
#define   LCDC_OVR1CFG9_DMA_1_Val             _UINT32_(0x1)                                        /* (LCDC_OVR1CFG9) The pixel stream is retrieved from the memory.  */
#define LCDC_OVR1CFG9_DMA_0                   (LCDC_OVR1CFG9_DMA_0_Val << LCDC_OVR1CFG9_DMA_Pos)   /* (LCDC_OVR1CFG9) The pixel for the current layer is retrieved from the default color register. Position  */
#define LCDC_OVR1CFG9_DMA_1                   (LCDC_OVR1CFG9_DMA_1_Val << LCDC_OVR1CFG9_DMA_Pos)   /* (LCDC_OVR1CFG9) The pixel stream is retrieved from the memory. Position  */
#define LCDC_OVR1CFG9_REP_Pos                 _UINT32_(1)                                          /* (LCDC_OVR1CFG9) Replication Logic Position */
#define LCDC_OVR1CFG9_REP_Msk                 (_UINT32_(0x1) << LCDC_OVR1CFG9_REP_Pos)             /* (LCDC_OVR1CFG9) Replication Logic Mask */
#define LCDC_OVR1CFG9_REP(value)              (LCDC_OVR1CFG9_REP_Msk & (_UINT32_(value) << LCDC_OVR1CFG9_REP_Pos)) /* Assigment of value for REP in the LCDC_OVR1CFG9 register */
#define   LCDC_OVR1CFG9_REP_0_Val             _UINT32_(0x0)                                        /* (LCDC_OVR1CFG9) When the selected pixel depth is less than 24 bpp, the pixel is shifted and LSBs are set to 0.  */
#define   LCDC_OVR1CFG9_REP_1_Val             _UINT32_(0x1)                                        /* (LCDC_OVR1CFG9) When the selected pixel depth is less than 24 bpp, the pixel is shifted and the LSB replicates the MSB.  */
#define LCDC_OVR1CFG9_REP_0                   (LCDC_OVR1CFG9_REP_0_Val << LCDC_OVR1CFG9_REP_Pos)   /* (LCDC_OVR1CFG9) When the selected pixel depth is less than 24 bpp, the pixel is shifted and LSBs are set to 0. Position  */
#define LCDC_OVR1CFG9_REP_1                   (LCDC_OVR1CFG9_REP_1_Val << LCDC_OVR1CFG9_REP_Pos)   /* (LCDC_OVR1CFG9) When the selected pixel depth is less than 24 bpp, the pixel is shifted and the LSB replicates the MSB. Position  */
#define LCDC_OVR1CFG9_CRKEY_Pos               _UINT32_(2)                                          /* (LCDC_OVR1CFG9) Chroma Keying Enable Position */
#define LCDC_OVR1CFG9_CRKEY_Msk               (_UINT32_(0x1) << LCDC_OVR1CFG9_CRKEY_Pos)           /* (LCDC_OVR1CFG9) Chroma Keying Enable Mask */
#define LCDC_OVR1CFG9_CRKEY(value)            (LCDC_OVR1CFG9_CRKEY_Msk & (_UINT32_(value) << LCDC_OVR1CFG9_CRKEY_Pos)) /* Assigment of value for CRKEY in the LCDC_OVR1CFG9 register */
#define LCDC_OVR1CFG9_DSTKEY_Pos              _UINT32_(3)                                          /* (LCDC_OVR1CFG9) Destination Color Keying Position */
#define LCDC_OVR1CFG9_DSTKEY_Msk              (_UINT32_(0x1) << LCDC_OVR1CFG9_DSTKEY_Pos)          /* (LCDC_OVR1CFG9) Destination Color Keying Mask */
#define LCDC_OVR1CFG9_DSTKEY(value)           (LCDC_OVR1CFG9_DSTKEY_Msk & (_UINT32_(value) << LCDC_OVR1CFG9_DSTKEY_Pos)) /* Assigment of value for DSTKEY in the LCDC_OVR1CFG9 register */
#define   LCDC_OVR1CFG9_DSTKEY_0_Val          _UINT32_(0x0)                                        /* (LCDC_OVR1CFG9) When CRKEY is enabled, color key is applied on OVR1 pixels, before the blending operation.  */
#define   LCDC_OVR1CFG9_DSTKEY_1_Val          _UINT32_(0x1)                                        /* (LCDC_OVR1CFG9) When CRKEY is enabled, color key is applied on OVR1 pixels, after the blending operation.  */
#define LCDC_OVR1CFG9_DSTKEY_0                (LCDC_OVR1CFG9_DSTKEY_0_Val << LCDC_OVR1CFG9_DSTKEY_Pos) /* (LCDC_OVR1CFG9) When CRKEY is enabled, color key is applied on OVR1 pixels, before the blending operation. Position  */
#define LCDC_OVR1CFG9_DSTKEY_1                (LCDC_OVR1CFG9_DSTKEY_1_Val << LCDC_OVR1CFG9_DSTKEY_Pos) /* (LCDC_OVR1CFG9) When CRKEY is enabled, color key is applied on OVR1 pixels, after the blending operation. Position  */
#define LCDC_OVR1CFG9_SFACTC_Pos              _UINT32_(6)                                          /* (LCDC_OVR1CFG9) Source Factor for the Blending Equation of the Color Component Position */
#define LCDC_OVR1CFG9_SFACTC_Msk              (_UINT32_(0x7) << LCDC_OVR1CFG9_SFACTC_Pos)          /* (LCDC_OVR1CFG9) Source Factor for the Blending Equation of the Color Component Mask */
#define LCDC_OVR1CFG9_SFACTC(value)           (LCDC_OVR1CFG9_SFACTC_Msk & (_UINT32_(value) << LCDC_OVR1CFG9_SFACTC_Pos)) /* Assigment of value for SFACTC in the LCDC_OVR1CFG9 register */
#define   LCDC_OVR1CFG9_SFACTC_ONE_Val        _UINT32_(0x0)                                        /* (LCDC_OVR1CFG9) Sets the factor to 1.0.  */
#define   LCDC_OVR1CFG9_SFACTC_ZERO_Val       _UINT32_(0x1)                                        /* (LCDC_OVR1CFG9) Sets the factor to 0.0.  */
#define   LCDC_OVR1CFG9_SFACTC_A0_Val         _UINT32_(0x2)                                        /* (LCDC_OVR1CFG9) Sets the factor to A0/255.  */
#define   LCDC_OVR1CFG9_SFACTC_A0_MULT_AD_Val _UINT32_(0x3)                                        /* (LCDC_OVR1CFG9) Sets the factor to A0 multiplied by Destination Alpha.  */
#define   LCDC_OVR1CFG9_SFACTC_A0_MUL_AS_Val  _UINT32_(0x4)                                        /* (LCDC_OVR1CFG9) Sets the factor to A0 multiplied by Source Alpha.  */
#define   LCDC_OVR1CFG9_SFACTC_M_A0_MUL_AD_Val _UINT32_(0x5)                                        /* (LCDC_OVR1CFG9) Computes A0 multiplied by Destination Alpha, then sets the factor to minus the result .  */
#define LCDC_OVR1CFG9_SFACTC_ONE              (LCDC_OVR1CFG9_SFACTC_ONE_Val << LCDC_OVR1CFG9_SFACTC_Pos) /* (LCDC_OVR1CFG9) Sets the factor to 1.0. Position  */
#define LCDC_OVR1CFG9_SFACTC_ZERO             (LCDC_OVR1CFG9_SFACTC_ZERO_Val << LCDC_OVR1CFG9_SFACTC_Pos) /* (LCDC_OVR1CFG9) Sets the factor to 0.0. Position  */
#define LCDC_OVR1CFG9_SFACTC_A0               (LCDC_OVR1CFG9_SFACTC_A0_Val << LCDC_OVR1CFG9_SFACTC_Pos) /* (LCDC_OVR1CFG9) Sets the factor to A0/255. Position  */
#define LCDC_OVR1CFG9_SFACTC_A0_MULT_AD       (LCDC_OVR1CFG9_SFACTC_A0_MULT_AD_Val << LCDC_OVR1CFG9_SFACTC_Pos) /* (LCDC_OVR1CFG9) Sets the factor to A0 multiplied by Destination Alpha. Position  */
#define LCDC_OVR1CFG9_SFACTC_A0_MUL_AS        (LCDC_OVR1CFG9_SFACTC_A0_MUL_AS_Val << LCDC_OVR1CFG9_SFACTC_Pos) /* (LCDC_OVR1CFG9) Sets the factor to A0 multiplied by Source Alpha. Position  */
#define LCDC_OVR1CFG9_SFACTC_M_A0_MUL_AD      (LCDC_OVR1CFG9_SFACTC_M_A0_MUL_AD_Val << LCDC_OVR1CFG9_SFACTC_Pos) /* (LCDC_OVR1CFG9) Computes A0 multiplied by Destination Alpha, then sets the factor to minus the result . Position  */
#define LCDC_OVR1CFG9_DFACTC_Pos              _UINT32_(11)                                         /* (LCDC_OVR1CFG9) Destination Factor for the Blending Equation of the Color Component Position */
#define LCDC_OVR1CFG9_DFACTC_Msk              (_UINT32_(0x7) << LCDC_OVR1CFG9_DFACTC_Pos)          /* (LCDC_OVR1CFG9) Destination Factor for the Blending Equation of the Color Component Mask */
#define LCDC_OVR1CFG9_DFACTC(value)           (LCDC_OVR1CFG9_DFACTC_Msk & (_UINT32_(value) << LCDC_OVR1CFG9_DFACTC_Pos)) /* Assigment of value for DFACTC in the LCDC_OVR1CFG9 register */
#define   LCDC_OVR1CFG9_DFACTC_ZERO_Val       _UINT32_(0x0)                                        /* (LCDC_OVR1CFG9) Sets the factor to 0.0.  */
#define   LCDC_OVR1CFG9_DFACTC_ONE_Val        _UINT32_(0x1)                                        /* (LCDC_OVR1CFG9) Sets the factor to 1.0.  */
#define   LCDC_OVR1CFG9_DFACTC_A0_Val         _UINT32_(0x2)                                        /* (LCDC_OVR1CFG9) Sets the factor to A0/255.  */
#define   LCDC_OVR1CFG9_DFACTC_A1_Val         _UINT32_(0x3)                                        /* (LCDC_OVR1CFG9) Sets the factor to A1/255.  */
#define   LCDC_OVR1CFG9_DFACTC_A0_MULT_AD_Val _UINT32_(0x4)                                        /* (LCDC_OVR1CFG9) Sets the factor to A0 multiplied by Destination Alpha.  */
#define   LCDC_OVR1CFG9_DFACTC_M_A0_MULT_AD_Val _UINT32_(0x5)                                        /* (LCDC_OVR1CFG9) Sets the factor to A0 multiplied by Destination Alpha, then sets the factor to one minus the result.  */
#define   LCDC_OVR1CFG9_DFACTC_M_A0_MUL_AS_Val _UINT32_(0x6)                                        /* (LCDC_OVR1CFG9) Computes A0 multiplied by source alpha0, then sets the factor to one minus the result.  */
#define   LCDC_OVR1CFG9_DFACTC_M_A0_Val       _UINT32_(0x7)                                        /* (LCDC_OVR1CFG9) Computes one minus A0, then sets the factor to one minus the result.  */
#define LCDC_OVR1CFG9_DFACTC_ZERO             (LCDC_OVR1CFG9_DFACTC_ZERO_Val << LCDC_OVR1CFG9_DFACTC_Pos) /* (LCDC_OVR1CFG9) Sets the factor to 0.0. Position  */
#define LCDC_OVR1CFG9_DFACTC_ONE              (LCDC_OVR1CFG9_DFACTC_ONE_Val << LCDC_OVR1CFG9_DFACTC_Pos) /* (LCDC_OVR1CFG9) Sets the factor to 1.0. Position  */
#define LCDC_OVR1CFG9_DFACTC_A0               (LCDC_OVR1CFG9_DFACTC_A0_Val << LCDC_OVR1CFG9_DFACTC_Pos) /* (LCDC_OVR1CFG9) Sets the factor to A0/255. Position  */
#define LCDC_OVR1CFG9_DFACTC_A1               (LCDC_OVR1CFG9_DFACTC_A1_Val << LCDC_OVR1CFG9_DFACTC_Pos) /* (LCDC_OVR1CFG9) Sets the factor to A1/255. Position  */
#define LCDC_OVR1CFG9_DFACTC_A0_MULT_AD       (LCDC_OVR1CFG9_DFACTC_A0_MULT_AD_Val << LCDC_OVR1CFG9_DFACTC_Pos) /* (LCDC_OVR1CFG9) Sets the factor to A0 multiplied by Destination Alpha. Position  */
#define LCDC_OVR1CFG9_DFACTC_M_A0_MULT_AD     (LCDC_OVR1CFG9_DFACTC_M_A0_MULT_AD_Val << LCDC_OVR1CFG9_DFACTC_Pos) /* (LCDC_OVR1CFG9) Sets the factor to A0 multiplied by Destination Alpha, then sets the factor to one minus the result. Position  */
#define LCDC_OVR1CFG9_DFACTC_M_A0_MUL_AS      (LCDC_OVR1CFG9_DFACTC_M_A0_MUL_AS_Val << LCDC_OVR1CFG9_DFACTC_Pos) /* (LCDC_OVR1CFG9) Computes A0 multiplied by source alpha0, then sets the factor to one minus the result. Position  */
#define LCDC_OVR1CFG9_DFACTC_M_A0             (LCDC_OVR1CFG9_DFACTC_M_A0_Val << LCDC_OVR1CFG9_DFACTC_Pos) /* (LCDC_OVR1CFG9) Computes one minus A0, then sets the factor to one minus the result. Position  */
#define LCDC_OVR1CFG9_A0_Pos                  _UINT32_(16)                                         /* (LCDC_OVR1CFG9) Alpha 0 Value Position */
#define LCDC_OVR1CFG9_A0_Msk                  (_UINT32_(0xFF) << LCDC_OVR1CFG9_A0_Pos)             /* (LCDC_OVR1CFG9) Alpha 0 Value Mask */
#define LCDC_OVR1CFG9_A0(value)               (LCDC_OVR1CFG9_A0_Msk & (_UINT32_(value) << LCDC_OVR1CFG9_A0_Pos)) /* Assigment of value for A0 in the LCDC_OVR1CFG9 register */
#define LCDC_OVR1CFG9_A1_Pos                  _UINT32_(24)                                         /* (LCDC_OVR1CFG9) Alpha 1 Value Position */
#define LCDC_OVR1CFG9_A1_Msk                  (_UINT32_(0xFF) << LCDC_OVR1CFG9_A1_Pos)             /* (LCDC_OVR1CFG9) Alpha 1 Value Mask */
#define LCDC_OVR1CFG9_A1(value)               (LCDC_OVR1CFG9_A1_Msk & (_UINT32_(value) << LCDC_OVR1CFG9_A1_Pos)) /* Assigment of value for A1 in the LCDC_OVR1CFG9 register */
#define LCDC_OVR1CFG9_Msk                     _UINT32_(0xFFFF39CF)                                 /* (LCDC_OVR1CFG9) Register Mask  */


/* -------- LCDC_OVR2IER : (LCDC Offset: 0x260) ( /W 32) Overlay 2 Interrupt Enable Register -------- */
#define LCDC_OVR2IER_END_Pos                  _UINT32_(0)                                          /* (LCDC_OVR2IER) End of Frame DMA Transfer Interrupt Enable Position */
#define LCDC_OVR2IER_END_Msk                  (_UINT32_(0x1) << LCDC_OVR2IER_END_Pos)              /* (LCDC_OVR2IER) End of Frame DMA Transfer Interrupt Enable Mask */
#define LCDC_OVR2IER_END(value)               (LCDC_OVR2IER_END_Msk & (_UINT32_(value) << LCDC_OVR2IER_END_Pos)) /* Assigment of value for END in the LCDC_OVR2IER register */
#define LCDC_OVR2IER_ERROR_Pos                _UINT32_(1)                                          /* (LCDC_OVR2IER) Bus Transfer Error Detected Interrupt Enable Position */
#define LCDC_OVR2IER_ERROR_Msk                (_UINT32_(0x1) << LCDC_OVR2IER_ERROR_Pos)            /* (LCDC_OVR2IER) Bus Transfer Error Detected Interrupt Enable Mask */
#define LCDC_OVR2IER_ERROR(value)             (LCDC_OVR2IER_ERROR_Msk & (_UINT32_(value) << LCDC_OVR2IER_ERROR_Pos)) /* Assigment of value for ERROR in the LCDC_OVR2IER register */
#define LCDC_OVR2IER_OVF_Pos                  _UINT32_(2)                                          /* (LCDC_OVR2IER) Overflow Interrupt Enable Position */
#define LCDC_OVR2IER_OVF_Msk                  (_UINT32_(0x1) << LCDC_OVR2IER_OVF_Pos)              /* (LCDC_OVR2IER) Overflow Interrupt Enable Mask */
#define LCDC_OVR2IER_OVF(value)               (LCDC_OVR2IER_OVF_Msk & (_UINT32_(value) << LCDC_OVR2IER_OVF_Pos)) /* Assigment of value for OVF in the LCDC_OVR2IER register */
#define LCDC_OVR2IER_Msk                      _UINT32_(0x00000007)                                 /* (LCDC_OVR2IER) Register Mask  */


/* -------- LCDC_OVR2IDR : (LCDC Offset: 0x264) ( /W 32) Overlay 2 Interrupt Disable Register -------- */
#define LCDC_OVR2IDR_END_Pos                  _UINT32_(0)                                          /* (LCDC_OVR2IDR) End of Frame DMA Transfer Interrupt Disable Position */
#define LCDC_OVR2IDR_END_Msk                  (_UINT32_(0x1) << LCDC_OVR2IDR_END_Pos)              /* (LCDC_OVR2IDR) End of Frame DMA Transfer Interrupt Disable Mask */
#define LCDC_OVR2IDR_END(value)               (LCDC_OVR2IDR_END_Msk & (_UINT32_(value) << LCDC_OVR2IDR_END_Pos)) /* Assigment of value for END in the LCDC_OVR2IDR register */
#define LCDC_OVR2IDR_ERROR_Pos                _UINT32_(1)                                          /* (LCDC_OVR2IDR) Bus Transfer Error Detected Interrupt Disable Position */
#define LCDC_OVR2IDR_ERROR_Msk                (_UINT32_(0x1) << LCDC_OVR2IDR_ERROR_Pos)            /* (LCDC_OVR2IDR) Bus Transfer Error Detected Interrupt Disable Mask */
#define LCDC_OVR2IDR_ERROR(value)             (LCDC_OVR2IDR_ERROR_Msk & (_UINT32_(value) << LCDC_OVR2IDR_ERROR_Pos)) /* Assigment of value for ERROR in the LCDC_OVR2IDR register */
#define LCDC_OVR2IDR_OVF_Pos                  _UINT32_(2)                                          /* (LCDC_OVR2IDR) Overflow Interrupt Disable Position */
#define LCDC_OVR2IDR_OVF_Msk                  (_UINT32_(0x1) << LCDC_OVR2IDR_OVF_Pos)              /* (LCDC_OVR2IDR) Overflow Interrupt Disable Mask */
#define LCDC_OVR2IDR_OVF(value)               (LCDC_OVR2IDR_OVF_Msk & (_UINT32_(value) << LCDC_OVR2IDR_OVF_Pos)) /* Assigment of value for OVF in the LCDC_OVR2IDR register */
#define LCDC_OVR2IDR_Msk                      _UINT32_(0x00000007)                                 /* (LCDC_OVR2IDR) Register Mask  */


/* -------- LCDC_OVR2IMR : (LCDC Offset: 0x268) ( R/ 32) Overlay 2 Interrupt Mask Register -------- */
#define LCDC_OVR2IMR_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_OVR2IMR) Overlay 2 Interrupt Mask Register  Reset Value */

#define LCDC_OVR2IMR_END_Pos                  _UINT32_(0)                                          /* (LCDC_OVR2IMR) End of Frame DMA Transfer Interrupt Mask Position */
#define LCDC_OVR2IMR_END_Msk                  (_UINT32_(0x1) << LCDC_OVR2IMR_END_Pos)              /* (LCDC_OVR2IMR) End of Frame DMA Transfer Interrupt Mask Mask */
#define LCDC_OVR2IMR_END(value)               (LCDC_OVR2IMR_END_Msk & (_UINT32_(value) << LCDC_OVR2IMR_END_Pos)) /* Assigment of value for END in the LCDC_OVR2IMR register */
#define LCDC_OVR2IMR_ERROR_Pos                _UINT32_(1)                                          /* (LCDC_OVR2IMR) Bus Transfer Error Detected Interrupt Mask Position */
#define LCDC_OVR2IMR_ERROR_Msk                (_UINT32_(0x1) << LCDC_OVR2IMR_ERROR_Pos)            /* (LCDC_OVR2IMR) Bus Transfer Error Detected Interrupt Mask Mask */
#define LCDC_OVR2IMR_ERROR(value)             (LCDC_OVR2IMR_ERROR_Msk & (_UINT32_(value) << LCDC_OVR2IMR_ERROR_Pos)) /* Assigment of value for ERROR in the LCDC_OVR2IMR register */
#define LCDC_OVR2IMR_OVF_Pos                  _UINT32_(2)                                          /* (LCDC_OVR2IMR) Overflow Interrupt Mask Position */
#define LCDC_OVR2IMR_OVF_Msk                  (_UINT32_(0x1) << LCDC_OVR2IMR_OVF_Pos)              /* (LCDC_OVR2IMR) Overflow Interrupt Mask Mask */
#define LCDC_OVR2IMR_OVF(value)               (LCDC_OVR2IMR_OVF_Msk & (_UINT32_(value) << LCDC_OVR2IMR_OVF_Pos)) /* Assigment of value for OVF in the LCDC_OVR2IMR register */
#define LCDC_OVR2IMR_Msk                      _UINT32_(0x00000007)                                 /* (LCDC_OVR2IMR) Register Mask  */


/* -------- LCDC_OVR2ISR : (LCDC Offset: 0x26C) ( R/ 32) Overlay 2 Interrupt Status Register -------- */
#define LCDC_OVR2ISR_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_OVR2ISR) Overlay 2 Interrupt Status Register  Reset Value */

#define LCDC_OVR2ISR_END_Pos                  _UINT32_(0)                                          /* (LCDC_OVR2ISR) End of Frame DMA Transfer Position */
#define LCDC_OVR2ISR_END_Msk                  (_UINT32_(0x1) << LCDC_OVR2ISR_END_Pos)              /* (LCDC_OVR2ISR) End of Frame DMA Transfer Mask */
#define LCDC_OVR2ISR_END(value)               (LCDC_OVR2ISR_END_Msk & (_UINT32_(value) << LCDC_OVR2ISR_END_Pos)) /* Assigment of value for END in the LCDC_OVR2ISR register */
#define   LCDC_OVR2ISR_END_0_Val              _UINT32_(0x0)                                        /* (LCDC_OVR2ISR) No end of transfer has been detected since last read of LCDC_OVR2ISR  */
#define   LCDC_OVR2ISR_END_1_Val              _UINT32_(0x1)                                        /* (LCDC_OVR2ISR) End of transfer has been detected. This flag is reset after a read operation.  */
#define LCDC_OVR2ISR_END_0                    (LCDC_OVR2ISR_END_0_Val << LCDC_OVR2ISR_END_Pos)     /* (LCDC_OVR2ISR) No end of transfer has been detected since last read of LCDC_OVR2ISR Position  */
#define LCDC_OVR2ISR_END_1                    (LCDC_OVR2ISR_END_1_Val << LCDC_OVR2ISR_END_Pos)     /* (LCDC_OVR2ISR) End of transfer has been detected. This flag is reset after a read operation. Position  */
#define LCDC_OVR2ISR_ERROR_Pos                _UINT32_(1)                                          /* (LCDC_OVR2ISR) Bus Error Detected Position */
#define LCDC_OVR2ISR_ERROR_Msk                (_UINT32_(0x1) << LCDC_OVR2ISR_ERROR_Pos)            /* (LCDC_OVR2ISR) Bus Error Detected Mask */
#define LCDC_OVR2ISR_ERROR(value)             (LCDC_OVR2ISR_ERROR_Msk & (_UINT32_(value) << LCDC_OVR2ISR_ERROR_Pos)) /* Assigment of value for ERROR in the LCDC_OVR2ISR register */
#define   LCDC_OVR2ISR_ERROR_0_Val            _UINT32_(0x0)                                        /* (LCDC_OVR2ISR) No system bus error has been detected since the last read of LCDC_OVR2ISR  */
#define   LCDC_OVR2ISR_ERROR_1_Val            _UINT32_(0x1)                                        /* (LCDC_OVR2ISR) A system bus error has been detected. This flag is reset after a read operation  */
#define LCDC_OVR2ISR_ERROR_0                  (LCDC_OVR2ISR_ERROR_0_Val << LCDC_OVR2ISR_ERROR_Pos) /* (LCDC_OVR2ISR) No system bus error has been detected since the last read of LCDC_OVR2ISR Position  */
#define LCDC_OVR2ISR_ERROR_1                  (LCDC_OVR2ISR_ERROR_1_Val << LCDC_OVR2ISR_ERROR_Pos) /* (LCDC_OVR2ISR) A system bus error has been detected. This flag is reset after a read operation Position  */
#define LCDC_OVR2ISR_OVF_Pos                  _UINT32_(2)                                          /* (LCDC_OVR2ISR) Overflow Detected Position */
#define LCDC_OVR2ISR_OVF_Msk                  (_UINT32_(0x1) << LCDC_OVR2ISR_OVF_Pos)              /* (LCDC_OVR2ISR) Overflow Detected Mask */
#define LCDC_OVR2ISR_OVF(value)               (LCDC_OVR2ISR_OVF_Msk & (_UINT32_(value) << LCDC_OVR2ISR_OVF_Pos)) /* Assigment of value for OVF in the LCDC_OVR2ISR register */
#define   LCDC_OVR2ISR_OVF_0_Val              _UINT32_(0x0)                                        /* (LCDC_OVR2ISR) No overflow occurred since last read of LCDC_OVR2ISR  */
#define   LCDC_OVR2ISR_OVF_1_Val              _UINT32_(0x1)                                        /* (LCDC_OVR2ISR) An overflow occurred, at least one DMA transfer is still running at the End Of Frame. This flag is reset after a read operation  */
#define LCDC_OVR2ISR_OVF_0                    (LCDC_OVR2ISR_OVF_0_Val << LCDC_OVR2ISR_OVF_Pos)     /* (LCDC_OVR2ISR) No overflow occurred since last read of LCDC_OVR2ISR Position  */
#define LCDC_OVR2ISR_OVF_1                    (LCDC_OVR2ISR_OVF_1_Val << LCDC_OVR2ISR_OVF_Pos)     /* (LCDC_OVR2ISR) An overflow occurred, at least one DMA transfer is still running at the End Of Frame. This flag is reset after a read operation Position  */
#define LCDC_OVR2ISR_Msk                      _UINT32_(0x00000007)                                 /* (LCDC_OVR2ISR) Register Mask  */


/* -------- LCDC_OVR2EN : (LCDC Offset: 0x270) (R/W 32) Overlay 2 Enable Register -------- */
#define LCDC_OVR2EN_RESETVALUE                _UINT32_(0x00)                                       /*  (LCDC_OVR2EN) Overlay 2 Enable Register  Reset Value */

#define LCDC_OVR2EN_ENABLE_Pos                _UINT32_(0)                                          /* (LCDC_OVR2EN) Layer Enable Position */
#define LCDC_OVR2EN_ENABLE_Msk                (_UINT32_(0x1) << LCDC_OVR2EN_ENABLE_Pos)            /* (LCDC_OVR2EN) Layer Enable Mask */
#define LCDC_OVR2EN_ENABLE(value)             (LCDC_OVR2EN_ENABLE_Msk & (_UINT32_(value) << LCDC_OVR2EN_ENABLE_Pos)) /* Assigment of value for ENABLE in the LCDC_OVR2EN register */
#define   LCDC_OVR2EN_ENABLE_0_Val            _UINT32_(0x0)                                        /* (LCDC_OVR2EN) The layer is disabled.  */
#define   LCDC_OVR2EN_ENABLE_1_Val            _UINT32_(0x1)                                        /* (LCDC_OVR2EN) The layer is enabled.  */
#define LCDC_OVR2EN_ENABLE_0                  (LCDC_OVR2EN_ENABLE_0_Val << LCDC_OVR2EN_ENABLE_Pos) /* (LCDC_OVR2EN) The layer is disabled. Position  */
#define LCDC_OVR2EN_ENABLE_1                  (LCDC_OVR2EN_ENABLE_1_Val << LCDC_OVR2EN_ENABLE_Pos) /* (LCDC_OVR2EN) The layer is enabled. Position  */
#define LCDC_OVR2EN_Msk                       _UINT32_(0x00000001)                                 /* (LCDC_OVR2EN) Register Mask  */


/* -------- LCDC_OVR2CLA : (LCDC Offset: 0x274) (R/W 32) Overlay 2 Color Table Address Register -------- */
#define LCDC_OVR2CLA_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_OVR2CLA) Overlay 2 Color Table Address Register  Reset Value */

#define LCDC_OVR2CLA_CLA_Pos                  _UINT32_(2)                                          /* (LCDC_OVR2CLA) Overlay 2 CLUT Address Position */
#define LCDC_OVR2CLA_CLA_Msk                  (_UINT32_(0x3FFFFFFF) << LCDC_OVR2CLA_CLA_Pos)       /* (LCDC_OVR2CLA) Overlay 2 CLUT Address Mask */
#define LCDC_OVR2CLA_CLA(value)               (LCDC_OVR2CLA_CLA_Msk & (_UINT32_(value) << LCDC_OVR2CLA_CLA_Pos)) /* Assigment of value for CLA in the LCDC_OVR2CLA register */
#define LCDC_OVR2CLA_Msk                      _UINT32_(0xFFFFFFFC)                                 /* (LCDC_OVR2CLA) Register Mask  */


/* -------- LCDC_OVR2FBA : (LCDC Offset: 0x278) (R/W 32) Overlay 2 Frame Buffer Address Register -------- */
#define LCDC_OVR2FBA_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_OVR2FBA) Overlay 2 Frame Buffer Address Register  Reset Value */

#define LCDC_OVR2FBA_FBA_Pos                  _UINT32_(0)                                          /* (LCDC_OVR2FBA) Frame Buffer Address Position */
#define LCDC_OVR2FBA_FBA_Msk                  (_UINT32_(0xFFFFFFFF) << LCDC_OVR2FBA_FBA_Pos)       /* (LCDC_OVR2FBA) Frame Buffer Address Mask */
#define LCDC_OVR2FBA_FBA(value)               (LCDC_OVR2FBA_FBA_Msk & (_UINT32_(value) << LCDC_OVR2FBA_FBA_Pos)) /* Assigment of value for FBA in the LCDC_OVR2FBA register */
#define LCDC_OVR2FBA_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (LCDC_OVR2FBA) Register Mask  */


/* -------- LCDC_OVR2CFG0 : (LCDC Offset: 0x27C) (R/W 32) Overlay 2 Configuration Register 0 -------- */
#define LCDC_OVR2CFG0_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_OVR2CFG0) Overlay 2 Configuration Register 0  Reset Value */

#define LCDC_OVR2CFG0_BLEN_Pos                _UINT32_(4)                                          /* (LCDC_OVR2CFG0) System Bus Burst Length Position */
#define LCDC_OVR2CFG0_BLEN_Msk                (_UINT32_(0x7) << LCDC_OVR2CFG0_BLEN_Pos)            /* (LCDC_OVR2CFG0) System Bus Burst Length Mask */
#define LCDC_OVR2CFG0_BLEN(value)             (LCDC_OVR2CFG0_BLEN_Msk & (_UINT32_(value) << LCDC_OVR2CFG0_BLEN_Pos)) /* Assigment of value for BLEN in the LCDC_OVR2CFG0 register */
#define   LCDC_OVR2CFG0_BLEN_INCR1_Val        _UINT32_(0x0)                                        /* (LCDC_OVR2CFG0) System bus access is started as soon as there is enough space in the FIFO to store one data.  */
#define   LCDC_OVR2CFG0_BLEN_INCR4_Val        _UINT32_(0x1)                                        /* (LCDC_OVR2CFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 4 data. A system bus INCR4 Burst is used by default. INCR1 is used for bursts less than 4.  */
#define   LCDC_OVR2CFG0_BLEN_INCR8_Val        _UINT32_(0x2)                                        /* (LCDC_OVR2CFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 8 data. A system bus INCR8 Burst is used by default. INCR4 bursts are used for bursts of 4 beats. INCR1 is used for bursts less than 4.  */
#define   LCDC_OVR2CFG0_BLEN_INCR16_Val       _UINT32_(0x3)                                        /* (LCDC_OVR2CFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 16 data. A system bus INCR16 Burst is used by default. INCR8 and INCR4 bursts are respectively used for bursts of 8 and 4 beats. INCR1 is used for bursts less than 4.  */
#define   LCDC_OVR2CFG0_BLEN_INCR32_Val       _UINT32_(0x4)                                        /* (LCDC_OVR2CFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 32 data. A system bus INCR32 Burst is used by default. INCR16, INCR8 and INCR4 bursts are respectively used for bursts of 16, 8 and 4 beats. INCR1 is used for bursts less than 4.  */
#define LCDC_OVR2CFG0_BLEN_INCR1              (LCDC_OVR2CFG0_BLEN_INCR1_Val << LCDC_OVR2CFG0_BLEN_Pos) /* (LCDC_OVR2CFG0) System bus access is started as soon as there is enough space in the FIFO to store one data. Position  */
#define LCDC_OVR2CFG0_BLEN_INCR4              (LCDC_OVR2CFG0_BLEN_INCR4_Val << LCDC_OVR2CFG0_BLEN_Pos) /* (LCDC_OVR2CFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 4 data. A system bus INCR4 Burst is used by default. INCR1 is used for bursts less than 4. Position  */
#define LCDC_OVR2CFG0_BLEN_INCR8              (LCDC_OVR2CFG0_BLEN_INCR8_Val << LCDC_OVR2CFG0_BLEN_Pos) /* (LCDC_OVR2CFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 8 data. A system bus INCR8 Burst is used by default. INCR4 bursts are used for bursts of 4 beats. INCR1 is used for bursts less than 4. Position  */
#define LCDC_OVR2CFG0_BLEN_INCR16             (LCDC_OVR2CFG0_BLEN_INCR16_Val << LCDC_OVR2CFG0_BLEN_Pos) /* (LCDC_OVR2CFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 16 data. A system bus INCR16 Burst is used by default. INCR8 and INCR4 bursts are respectively used for bursts of 8 and 4 beats. INCR1 is used for bursts less than 4. Position  */
#define LCDC_OVR2CFG0_BLEN_INCR32             (LCDC_OVR2CFG0_BLEN_INCR32_Val << LCDC_OVR2CFG0_BLEN_Pos) /* (LCDC_OVR2CFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 32 data. A system bus INCR32 Burst is used by default. INCR16, INCR8 and INCR4 bursts are respectively used for bursts of 16, 8 and 4 beats. INCR1 is used for bursts less than 4. Position  */
#define LCDC_OVR2CFG0_Msk                     _UINT32_(0x00000070)                                 /* (LCDC_OVR2CFG0) Register Mask  */


/* -------- LCDC_OVR2CFG1 : (LCDC Offset: 0x280) (R/W 32) Overlay 2 Configuration Register 1 -------- */
#define LCDC_OVR2CFG1_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_OVR2CFG1) Overlay 2 Configuration Register 1  Reset Value */

#define LCDC_OVR2CFG1_CLUTEN_Pos              _UINT32_(0)                                          /* (LCDC_OVR2CFG1) CLUT Mode Enable Position */
#define LCDC_OVR2CFG1_CLUTEN_Msk              (_UINT32_(0x1) << LCDC_OVR2CFG1_CLUTEN_Pos)          /* (LCDC_OVR2CFG1) CLUT Mode Enable Mask */
#define LCDC_OVR2CFG1_CLUTEN(value)           (LCDC_OVR2CFG1_CLUTEN_Msk & (_UINT32_(value) << LCDC_OVR2CFG1_CLUTEN_Pos)) /* Assigment of value for CLUTEN in the LCDC_OVR2CFG1 register */
#define   LCDC_OVR2CFG1_CLUTEN_0_Val          _UINT32_(0x0)                                        /* (LCDC_OVR2CFG1) RGB mode is selected.  */
#define   LCDC_OVR2CFG1_CLUTEN_1_Val          _UINT32_(0x1)                                        /* (LCDC_OVR2CFG1) CLUT mode is selected.  */
#define LCDC_OVR2CFG1_CLUTEN_0                (LCDC_OVR2CFG1_CLUTEN_0_Val << LCDC_OVR2CFG1_CLUTEN_Pos) /* (LCDC_OVR2CFG1) RGB mode is selected. Position  */
#define LCDC_OVR2CFG1_CLUTEN_1                (LCDC_OVR2CFG1_CLUTEN_1_Val << LCDC_OVR2CFG1_CLUTEN_Pos) /* (LCDC_OVR2CFG1) CLUT mode is selected. Position  */
#define LCDC_OVR2CFG1_GAM_Pos                 _UINT32_(2)                                          /* (LCDC_OVR2CFG1) Gamma Correction Position */
#define LCDC_OVR2CFG1_GAM_Msk                 (_UINT32_(0x1) << LCDC_OVR2CFG1_GAM_Pos)             /* (LCDC_OVR2CFG1) Gamma Correction Mask */
#define LCDC_OVR2CFG1_GAM(value)              (LCDC_OVR2CFG1_GAM_Msk & (_UINT32_(value) << LCDC_OVR2CFG1_GAM_Pos)) /* Assigment of value for GAM in the LCDC_OVR2CFG1 register */
#define   LCDC_OVR2CFG1_GAM_0_Val             _UINT32_(0x0)                                        /* (LCDC_OVR2CFG1) Gamma correction is disabled  */
#define   LCDC_OVR2CFG1_GAM_1_Val             _UINT32_(0x1)                                        /* (LCDC_OVR2CFG1) Gamma correction is enabled  */
#define LCDC_OVR2CFG1_GAM_0                   (LCDC_OVR2CFG1_GAM_0_Val << LCDC_OVR2CFG1_GAM_Pos)   /* (LCDC_OVR2CFG1) Gamma correction is disabled Position  */
#define LCDC_OVR2CFG1_GAM_1                   (LCDC_OVR2CFG1_GAM_1_Val << LCDC_OVR2CFG1_GAM_Pos)   /* (LCDC_OVR2CFG1) Gamma correction is enabled Position  */
#define LCDC_OVR2CFG1_RGBMODE_Pos             _UINT32_(4)                                          /* (LCDC_OVR2CFG1) RGB Mode Input Selection Position */
#define LCDC_OVR2CFG1_RGBMODE_Msk             (_UINT32_(0xF) << LCDC_OVR2CFG1_RGBMODE_Pos)         /* (LCDC_OVR2CFG1) RGB Mode Input Selection Mask */
#define LCDC_OVR2CFG1_RGBMODE(value)          (LCDC_OVR2CFG1_RGBMODE_Msk & (_UINT32_(value) << LCDC_OVR2CFG1_RGBMODE_Pos)) /* Assigment of value for RGBMODE in the LCDC_OVR2CFG1 register */
#define   LCDC_OVR2CFG1_RGBMODE_12BPP_RGB_444_Val _UINT32_(0x0)                                        /* (LCDC_OVR2CFG1) 12 bpp RGB 444  */
#define   LCDC_OVR2CFG1_RGBMODE_16BPP_ARGB_4444_Val _UINT32_(0x1)                                        /* (LCDC_OVR2CFG1) 16 bpp ARGB 4444  */
#define   LCDC_OVR2CFG1_RGBMODE_16BPP_RGBA_4444_Val _UINT32_(0x2)                                        /* (LCDC_OVR2CFG1) 16 bpp RGBA 4444  */
#define   LCDC_OVR2CFG1_RGBMODE_16BPP_RGB_565_Val _UINT32_(0x3)                                        /* (LCDC_OVR2CFG1) 16 bpp RGB 565  */
#define   LCDC_OVR2CFG1_RGBMODE_16BPP_ARGB_1555_Val _UINT32_(0x4)                                        /* (LCDC_OVR2CFG1) 16 bpp ARGB 1555  */
#define   LCDC_OVR2CFG1_RGBMODE_18BPP_RGB_666_Val _UINT32_(0x5)                                        /* (LCDC_OVR2CFG1) 18 bpp RGB 666  */
#define   LCDC_OVR2CFG1_RGBMODE_18BPP_RGB_666PACKED_Val _UINT32_(0x6)                                        /* (LCDC_OVR2CFG1) 18 bpp RGB 666 PACKED  */
#define   LCDC_OVR2CFG1_RGBMODE_19BPP_ARGB_1666_Val _UINT32_(0x7)                                        /* (LCDC_OVR2CFG1) 19 bpp ARGB 1666  */
#define   LCDC_OVR2CFG1_RGBMODE_19BPP_ARGB_PACKED_Val _UINT32_(0x8)                                        /* (LCDC_OVR2CFG1) 19 bpp ARGB 1666 PACKED  */
#define   LCDC_OVR2CFG1_RGBMODE_24BPP_RGB_888_Val _UINT32_(0x9)                                        /* (LCDC_OVR2CFG1) 24 bpp RGB 888  */
#define   LCDC_OVR2CFG1_RGBMODE_24BPP_RGB_888_PACKED_Val _UINT32_(0xA)                                        /* (LCDC_OVR2CFG1) 24 bpp RGB 888 PACKED  */
#define   LCDC_OVR2CFG1_RGBMODE_25BPP_ARGB_1888_Val _UINT32_(0xB)                                        /* (LCDC_OVR2CFG1) 25 bpp ARGB 1888  */
#define   LCDC_OVR2CFG1_RGBMODE_32BPP_ARGB_8888_Val _UINT32_(0xC)                                        /* (LCDC_OVR2CFG1) 32 bpp ARGB 8888  */
#define   LCDC_OVR2CFG1_RGBMODE_32BPP_RGBA_8888_Val _UINT32_(0xD)                                        /* (LCDC_OVR2CFG1) 32 bpp RGBA 8888  */
#define LCDC_OVR2CFG1_RGBMODE_12BPP_RGB_444   (LCDC_OVR2CFG1_RGBMODE_12BPP_RGB_444_Val << LCDC_OVR2CFG1_RGBMODE_Pos) /* (LCDC_OVR2CFG1) 12 bpp RGB 444 Position  */
#define LCDC_OVR2CFG1_RGBMODE_16BPP_ARGB_4444 (LCDC_OVR2CFG1_RGBMODE_16BPP_ARGB_4444_Val << LCDC_OVR2CFG1_RGBMODE_Pos) /* (LCDC_OVR2CFG1) 16 bpp ARGB 4444 Position  */
#define LCDC_OVR2CFG1_RGBMODE_16BPP_RGBA_4444 (LCDC_OVR2CFG1_RGBMODE_16BPP_RGBA_4444_Val << LCDC_OVR2CFG1_RGBMODE_Pos) /* (LCDC_OVR2CFG1) 16 bpp RGBA 4444 Position  */
#define LCDC_OVR2CFG1_RGBMODE_16BPP_RGB_565   (LCDC_OVR2CFG1_RGBMODE_16BPP_RGB_565_Val << LCDC_OVR2CFG1_RGBMODE_Pos) /* (LCDC_OVR2CFG1) 16 bpp RGB 565 Position  */
#define LCDC_OVR2CFG1_RGBMODE_16BPP_ARGB_1555 (LCDC_OVR2CFG1_RGBMODE_16BPP_ARGB_1555_Val << LCDC_OVR2CFG1_RGBMODE_Pos) /* (LCDC_OVR2CFG1) 16 bpp ARGB 1555 Position  */
#define LCDC_OVR2CFG1_RGBMODE_18BPP_RGB_666   (LCDC_OVR2CFG1_RGBMODE_18BPP_RGB_666_Val << LCDC_OVR2CFG1_RGBMODE_Pos) /* (LCDC_OVR2CFG1) 18 bpp RGB 666 Position  */
#define LCDC_OVR2CFG1_RGBMODE_18BPP_RGB_666PACKED (LCDC_OVR2CFG1_RGBMODE_18BPP_RGB_666PACKED_Val << LCDC_OVR2CFG1_RGBMODE_Pos) /* (LCDC_OVR2CFG1) 18 bpp RGB 666 PACKED Position  */
#define LCDC_OVR2CFG1_RGBMODE_19BPP_ARGB_1666 (LCDC_OVR2CFG1_RGBMODE_19BPP_ARGB_1666_Val << LCDC_OVR2CFG1_RGBMODE_Pos) /* (LCDC_OVR2CFG1) 19 bpp ARGB 1666 Position  */
#define LCDC_OVR2CFG1_RGBMODE_19BPP_ARGB_PACKED (LCDC_OVR2CFG1_RGBMODE_19BPP_ARGB_PACKED_Val << LCDC_OVR2CFG1_RGBMODE_Pos) /* (LCDC_OVR2CFG1) 19 bpp ARGB 1666 PACKED Position  */
#define LCDC_OVR2CFG1_RGBMODE_24BPP_RGB_888   (LCDC_OVR2CFG1_RGBMODE_24BPP_RGB_888_Val << LCDC_OVR2CFG1_RGBMODE_Pos) /* (LCDC_OVR2CFG1) 24 bpp RGB 888 Position  */
#define LCDC_OVR2CFG1_RGBMODE_24BPP_RGB_888_PACKED (LCDC_OVR2CFG1_RGBMODE_24BPP_RGB_888_PACKED_Val << LCDC_OVR2CFG1_RGBMODE_Pos) /* (LCDC_OVR2CFG1) 24 bpp RGB 888 PACKED Position  */
#define LCDC_OVR2CFG1_RGBMODE_25BPP_ARGB_1888 (LCDC_OVR2CFG1_RGBMODE_25BPP_ARGB_1888_Val << LCDC_OVR2CFG1_RGBMODE_Pos) /* (LCDC_OVR2CFG1) 25 bpp ARGB 1888 Position  */
#define LCDC_OVR2CFG1_RGBMODE_32BPP_ARGB_8888 (LCDC_OVR2CFG1_RGBMODE_32BPP_ARGB_8888_Val << LCDC_OVR2CFG1_RGBMODE_Pos) /* (LCDC_OVR2CFG1) 32 bpp ARGB 8888 Position  */
#define LCDC_OVR2CFG1_RGBMODE_32BPP_RGBA_8888 (LCDC_OVR2CFG1_RGBMODE_32BPP_RGBA_8888_Val << LCDC_OVR2CFG1_RGBMODE_Pos) /* (LCDC_OVR2CFG1) 32 bpp RGBA 8888 Position  */
#define LCDC_OVR2CFG1_CLUTMODE_Pos            _UINT32_(8)                                          /* (LCDC_OVR2CFG1) CLUT Mode Input Selection Position */
#define LCDC_OVR2CFG1_CLUTMODE_Msk            (_UINT32_(0x3) << LCDC_OVR2CFG1_CLUTMODE_Pos)        /* (LCDC_OVR2CFG1) CLUT Mode Input Selection Mask */
#define LCDC_OVR2CFG1_CLUTMODE(value)         (LCDC_OVR2CFG1_CLUTMODE_Msk & (_UINT32_(value) << LCDC_OVR2CFG1_CLUTMODE_Pos)) /* Assigment of value for CLUTMODE in the LCDC_OVR2CFG1 register */
#define   LCDC_OVR2CFG1_CLUTMODE_CLUT_1BPP_Val _UINT32_(0x0)                                        /* (LCDC_OVR2CFG1) CLUT mode set to 1 bit per pixel  */
#define   LCDC_OVR2CFG1_CLUTMODE_CLUT_2BPP_Val _UINT32_(0x1)                                        /* (LCDC_OVR2CFG1) CLUT mode set to 2 bits per pixel  */
#define   LCDC_OVR2CFG1_CLUTMODE_CLUT_4BPP_Val _UINT32_(0x2)                                        /* (LCDC_OVR2CFG1) CLUT mode set to 4 bits per pixel  */
#define   LCDC_OVR2CFG1_CLUTMODE_CLUT_8BPP_Val _UINT32_(0x3)                                        /* (LCDC_OVR2CFG1) CLUT mode set to 8 bits per pixel  */
#define LCDC_OVR2CFG1_CLUTMODE_CLUT_1BPP      (LCDC_OVR2CFG1_CLUTMODE_CLUT_1BPP_Val << LCDC_OVR2CFG1_CLUTMODE_Pos) /* (LCDC_OVR2CFG1) CLUT mode set to 1 bit per pixel Position  */
#define LCDC_OVR2CFG1_CLUTMODE_CLUT_2BPP      (LCDC_OVR2CFG1_CLUTMODE_CLUT_2BPP_Val << LCDC_OVR2CFG1_CLUTMODE_Pos) /* (LCDC_OVR2CFG1) CLUT mode set to 2 bits per pixel Position  */
#define LCDC_OVR2CFG1_CLUTMODE_CLUT_4BPP      (LCDC_OVR2CFG1_CLUTMODE_CLUT_4BPP_Val << LCDC_OVR2CFG1_CLUTMODE_Pos) /* (LCDC_OVR2CFG1) CLUT mode set to 4 bits per pixel Position  */
#define LCDC_OVR2CFG1_CLUTMODE_CLUT_8BPP      (LCDC_OVR2CFG1_CLUTMODE_CLUT_8BPP_Val << LCDC_OVR2CFG1_CLUTMODE_Pos) /* (LCDC_OVR2CFG1) CLUT mode set to 8 bits per pixel Position  */
#define LCDC_OVR2CFG1_Msk                     _UINT32_(0x000003F5)                                 /* (LCDC_OVR2CFG1) Register Mask  */


/* -------- LCDC_OVR2CFG2 : (LCDC Offset: 0x284) (R/W 32) Overlay 2 Configuration Register 2 -------- */
#define LCDC_OVR2CFG2_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_OVR2CFG2) Overlay 2 Configuration Register 2  Reset Value */

#define LCDC_OVR2CFG2_XPOS_Pos                _UINT32_(0)                                          /* (LCDC_OVR2CFG2) Horizontal Window Position Position */
#define LCDC_OVR2CFG2_XPOS_Msk                (_UINT32_(0x7FF) << LCDC_OVR2CFG2_XPOS_Pos)          /* (LCDC_OVR2CFG2) Horizontal Window Position Mask */
#define LCDC_OVR2CFG2_XPOS(value)             (LCDC_OVR2CFG2_XPOS_Msk & (_UINT32_(value) << LCDC_OVR2CFG2_XPOS_Pos)) /* Assigment of value for XPOS in the LCDC_OVR2CFG2 register */
#define LCDC_OVR2CFG2_YPOS_Pos                _UINT32_(16)                                         /* (LCDC_OVR2CFG2) Vertical Window Position Position */
#define LCDC_OVR2CFG2_YPOS_Msk                (_UINT32_(0x7FF) << LCDC_OVR2CFG2_YPOS_Pos)          /* (LCDC_OVR2CFG2) Vertical Window Position Mask */
#define LCDC_OVR2CFG2_YPOS(value)             (LCDC_OVR2CFG2_YPOS_Msk & (_UINT32_(value) << LCDC_OVR2CFG2_YPOS_Pos)) /* Assigment of value for YPOS in the LCDC_OVR2CFG2 register */
#define LCDC_OVR2CFG2_Msk                     _UINT32_(0x07FF07FF)                                 /* (LCDC_OVR2CFG2) Register Mask  */


/* -------- LCDC_OVR2CFG3 : (LCDC Offset: 0x288) (R/W 32) Overlay 2 Configuration Register 3 -------- */
#define LCDC_OVR2CFG3_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_OVR2CFG3) Overlay 2 Configuration Register 3  Reset Value */

#define LCDC_OVR2CFG3_XSIZE_Pos               _UINT32_(0)                                          /* (LCDC_OVR2CFG3) Horizontal Window Size Position */
#define LCDC_OVR2CFG3_XSIZE_Msk               (_UINT32_(0x7FF) << LCDC_OVR2CFG3_XSIZE_Pos)         /* (LCDC_OVR2CFG3) Horizontal Window Size Mask */
#define LCDC_OVR2CFG3_XSIZE(value)            (LCDC_OVR2CFG3_XSIZE_Msk & (_UINT32_(value) << LCDC_OVR2CFG3_XSIZE_Pos)) /* Assigment of value for XSIZE in the LCDC_OVR2CFG3 register */
#define LCDC_OVR2CFG3_YSIZE_Pos               _UINT32_(16)                                         /* (LCDC_OVR2CFG3) Vertical Window Size Position */
#define LCDC_OVR2CFG3_YSIZE_Msk               (_UINT32_(0x7FF) << LCDC_OVR2CFG3_YSIZE_Pos)         /* (LCDC_OVR2CFG3) Vertical Window Size Mask */
#define LCDC_OVR2CFG3_YSIZE(value)            (LCDC_OVR2CFG3_YSIZE_Msk & (_UINT32_(value) << LCDC_OVR2CFG3_YSIZE_Pos)) /* Assigment of value for YSIZE in the LCDC_OVR2CFG3 register */
#define LCDC_OVR2CFG3_Msk                     _UINT32_(0x07FF07FF)                                 /* (LCDC_OVR2CFG3) Register Mask  */


/* -------- LCDC_OVR2CFG4 : (LCDC Offset: 0x28C) (R/W 32) Overlay 2 Configuration Register 4 -------- */
#define LCDC_OVR2CFG4_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_OVR2CFG4) Overlay 2 Configuration Register 4  Reset Value */

#define LCDC_OVR2CFG4_XSTRIDE_Pos             _UINT32_(0)                                          /* (LCDC_OVR2CFG4) Horizontal Stride Position */
#define LCDC_OVR2CFG4_XSTRIDE_Msk             (_UINT32_(0xFFFFFFFF) << LCDC_OVR2CFG4_XSTRIDE_Pos)  /* (LCDC_OVR2CFG4) Horizontal Stride Mask */
#define LCDC_OVR2CFG4_XSTRIDE(value)          (LCDC_OVR2CFG4_XSTRIDE_Msk & (_UINT32_(value) << LCDC_OVR2CFG4_XSTRIDE_Pos)) /* Assigment of value for XSTRIDE in the LCDC_OVR2CFG4 register */
#define LCDC_OVR2CFG4_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (LCDC_OVR2CFG4) Register Mask  */


/* -------- LCDC_OVR2CFG5 : (LCDC Offset: 0x290) (R/W 32) Overlay 2 Configuration Register 5 -------- */
#define LCDC_OVR2CFG5_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_OVR2CFG5) Overlay 2 Configuration Register 5  Reset Value */

#define LCDC_OVR2CFG5_PSTRIDE_Pos             _UINT32_(0)                                          /* (LCDC_OVR2CFG5) Pixel Stride Position */
#define LCDC_OVR2CFG5_PSTRIDE_Msk             (_UINT32_(0xFFFFFFFF) << LCDC_OVR2CFG5_PSTRIDE_Pos)  /* (LCDC_OVR2CFG5) Pixel Stride Mask */
#define LCDC_OVR2CFG5_PSTRIDE(value)          (LCDC_OVR2CFG5_PSTRIDE_Msk & (_UINT32_(value) << LCDC_OVR2CFG5_PSTRIDE_Pos)) /* Assigment of value for PSTRIDE in the LCDC_OVR2CFG5 register */
#define LCDC_OVR2CFG5_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (LCDC_OVR2CFG5) Register Mask  */


/* -------- LCDC_OVR2CFG6 : (LCDC Offset: 0x294) (R/W 32) Overlay 2 Configuration Register 6 -------- */
#define LCDC_OVR2CFG6_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_OVR2CFG6) Overlay 2 Configuration Register 6  Reset Value */

#define LCDC_OVR2CFG6_BDEF_Pos                _UINT32_(0)                                          /* (LCDC_OVR2CFG6) Blue Default Position */
#define LCDC_OVR2CFG6_BDEF_Msk                (_UINT32_(0xFF) << LCDC_OVR2CFG6_BDEF_Pos)           /* (LCDC_OVR2CFG6) Blue Default Mask */
#define LCDC_OVR2CFG6_BDEF(value)             (LCDC_OVR2CFG6_BDEF_Msk & (_UINT32_(value) << LCDC_OVR2CFG6_BDEF_Pos)) /* Assigment of value for BDEF in the LCDC_OVR2CFG6 register */
#define LCDC_OVR2CFG6_GDEF_Pos                _UINT32_(8)                                          /* (LCDC_OVR2CFG6) Green Default Position */
#define LCDC_OVR2CFG6_GDEF_Msk                (_UINT32_(0xFF) << LCDC_OVR2CFG6_GDEF_Pos)           /* (LCDC_OVR2CFG6) Green Default Mask */
#define LCDC_OVR2CFG6_GDEF(value)             (LCDC_OVR2CFG6_GDEF_Msk & (_UINT32_(value) << LCDC_OVR2CFG6_GDEF_Pos)) /* Assigment of value for GDEF in the LCDC_OVR2CFG6 register */
#define LCDC_OVR2CFG6_RDEF_Pos                _UINT32_(16)                                         /* (LCDC_OVR2CFG6) Red Default Position */
#define LCDC_OVR2CFG6_RDEF_Msk                (_UINT32_(0xFF) << LCDC_OVR2CFG6_RDEF_Pos)           /* (LCDC_OVR2CFG6) Red Default Mask */
#define LCDC_OVR2CFG6_RDEF(value)             (LCDC_OVR2CFG6_RDEF_Msk & (_UINT32_(value) << LCDC_OVR2CFG6_RDEF_Pos)) /* Assigment of value for RDEF in the LCDC_OVR2CFG6 register */
#define LCDC_OVR2CFG6_Msk                     _UINT32_(0x00FFFFFF)                                 /* (LCDC_OVR2CFG6) Register Mask  */


/* -------- LCDC_OVR2CFG7 : (LCDC Offset: 0x298) (R/W 32) Overlay 2 Configuration Register 7 -------- */
#define LCDC_OVR2CFG7_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_OVR2CFG7) Overlay 2 Configuration Register 7  Reset Value */

#define LCDC_OVR2CFG7_BKEY_Pos                _UINT32_(0)                                          /* (LCDC_OVR2CFG7) Blue Color Component Chroma Key Position */
#define LCDC_OVR2CFG7_BKEY_Msk                (_UINT32_(0xFF) << LCDC_OVR2CFG7_BKEY_Pos)           /* (LCDC_OVR2CFG7) Blue Color Component Chroma Key Mask */
#define LCDC_OVR2CFG7_BKEY(value)             (LCDC_OVR2CFG7_BKEY_Msk & (_UINT32_(value) << LCDC_OVR2CFG7_BKEY_Pos)) /* Assigment of value for BKEY in the LCDC_OVR2CFG7 register */
#define LCDC_OVR2CFG7_GKEY_Pos                _UINT32_(8)                                          /* (LCDC_OVR2CFG7) Green Color Component Chroma Key Position */
#define LCDC_OVR2CFG7_GKEY_Msk                (_UINT32_(0xFF) << LCDC_OVR2CFG7_GKEY_Pos)           /* (LCDC_OVR2CFG7) Green Color Component Chroma Key Mask */
#define LCDC_OVR2CFG7_GKEY(value)             (LCDC_OVR2CFG7_GKEY_Msk & (_UINT32_(value) << LCDC_OVR2CFG7_GKEY_Pos)) /* Assigment of value for GKEY in the LCDC_OVR2CFG7 register */
#define LCDC_OVR2CFG7_RKEY_Pos                _UINT32_(16)                                         /* (LCDC_OVR2CFG7) Red Color Component Chroma Key Position */
#define LCDC_OVR2CFG7_RKEY_Msk                (_UINT32_(0xFF) << LCDC_OVR2CFG7_RKEY_Pos)           /* (LCDC_OVR2CFG7) Red Color Component Chroma Key Mask */
#define LCDC_OVR2CFG7_RKEY(value)             (LCDC_OVR2CFG7_RKEY_Msk & (_UINT32_(value) << LCDC_OVR2CFG7_RKEY_Pos)) /* Assigment of value for RKEY in the LCDC_OVR2CFG7 register */
#define LCDC_OVR2CFG7_Msk                     _UINT32_(0x00FFFFFF)                                 /* (LCDC_OVR2CFG7) Register Mask  */


/* -------- LCDC_OVR2CFG8 : (LCDC Offset: 0x29C) (R/W 32) Overlay 2 Configuration Register 8 -------- */
#define LCDC_OVR2CFG8_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_OVR2CFG8) Overlay 2 Configuration Register 8  Reset Value */

#define LCDC_OVR2CFG8_BMASK_Pos               _UINT32_(0)                                          /* (LCDC_OVR2CFG8) Blue Color Component Chroma Key Mask Position */
#define LCDC_OVR2CFG8_BMASK_Msk               (_UINT32_(0xFF) << LCDC_OVR2CFG8_BMASK_Pos)          /* (LCDC_OVR2CFG8) Blue Color Component Chroma Key Mask Mask */
#define LCDC_OVR2CFG8_BMASK(value)            (LCDC_OVR2CFG8_BMASK_Msk & (_UINT32_(value) << LCDC_OVR2CFG8_BMASK_Pos)) /* Assigment of value for BMASK in the LCDC_OVR2CFG8 register */
#define LCDC_OVR2CFG8_GMASK_Pos               _UINT32_(8)                                          /* (LCDC_OVR2CFG8) Green Color Component Chroma Key Mask Position */
#define LCDC_OVR2CFG8_GMASK_Msk               (_UINT32_(0xFF) << LCDC_OVR2CFG8_GMASK_Pos)          /* (LCDC_OVR2CFG8) Green Color Component Chroma Key Mask Mask */
#define LCDC_OVR2CFG8_GMASK(value)            (LCDC_OVR2CFG8_GMASK_Msk & (_UINT32_(value) << LCDC_OVR2CFG8_GMASK_Pos)) /* Assigment of value for GMASK in the LCDC_OVR2CFG8 register */
#define LCDC_OVR2CFG8_RMASK_Pos               _UINT32_(16)                                         /* (LCDC_OVR2CFG8) Red Color Component Chroma Key Mask Position */
#define LCDC_OVR2CFG8_RMASK_Msk               (_UINT32_(0xFF) << LCDC_OVR2CFG8_RMASK_Pos)          /* (LCDC_OVR2CFG8) Red Color Component Chroma Key Mask Mask */
#define LCDC_OVR2CFG8_RMASK(value)            (LCDC_OVR2CFG8_RMASK_Msk & (_UINT32_(value) << LCDC_OVR2CFG8_RMASK_Pos)) /* Assigment of value for RMASK in the LCDC_OVR2CFG8 register */
#define LCDC_OVR2CFG8_Msk                     _UINT32_(0x00FFFFFF)                                 /* (LCDC_OVR2CFG8) Register Mask  */


/* -------- LCDC_OVR2CFG9 : (LCDC Offset: 0x2A0) (R/W 32) Overlay 2 Configuration Register 9 -------- */
#define LCDC_OVR2CFG9_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_OVR2CFG9) Overlay 2 Configuration Register 9  Reset Value */

#define LCDC_OVR2CFG9_DMA_Pos                 _UINT32_(0)                                          /* (LCDC_OVR2CFG9) DMA Enable Position */
#define LCDC_OVR2CFG9_DMA_Msk                 (_UINT32_(0x1) << LCDC_OVR2CFG9_DMA_Pos)             /* (LCDC_OVR2CFG9) DMA Enable Mask */
#define LCDC_OVR2CFG9_DMA(value)              (LCDC_OVR2CFG9_DMA_Msk & (_UINT32_(value) << LCDC_OVR2CFG9_DMA_Pos)) /* Assigment of value for DMA in the LCDC_OVR2CFG9 register */
#define   LCDC_OVR2CFG9_DMA_0_Val             _UINT32_(0x0)                                        /* (LCDC_OVR2CFG9) The pixel for the current layer is retrieved from the default color register.  */
#define   LCDC_OVR2CFG9_DMA_1_Val             _UINT32_(0x1)                                        /* (LCDC_OVR2CFG9) The pixel stream is retrieved from the memory.  */
#define LCDC_OVR2CFG9_DMA_0                   (LCDC_OVR2CFG9_DMA_0_Val << LCDC_OVR2CFG9_DMA_Pos)   /* (LCDC_OVR2CFG9) The pixel for the current layer is retrieved from the default color register. Position  */
#define LCDC_OVR2CFG9_DMA_1                   (LCDC_OVR2CFG9_DMA_1_Val << LCDC_OVR2CFG9_DMA_Pos)   /* (LCDC_OVR2CFG9) The pixel stream is retrieved from the memory. Position  */
#define LCDC_OVR2CFG9_REP_Pos                 _UINT32_(1)                                          /* (LCDC_OVR2CFG9) Replication Logic Position */
#define LCDC_OVR2CFG9_REP_Msk                 (_UINT32_(0x1) << LCDC_OVR2CFG9_REP_Pos)             /* (LCDC_OVR2CFG9) Replication Logic Mask */
#define LCDC_OVR2CFG9_REP(value)              (LCDC_OVR2CFG9_REP_Msk & (_UINT32_(value) << LCDC_OVR2CFG9_REP_Pos)) /* Assigment of value for REP in the LCDC_OVR2CFG9 register */
#define   LCDC_OVR2CFG9_REP_0_Val             _UINT32_(0x0)                                        /* (LCDC_OVR2CFG9) When the selected pixel depth is less than 24 bpp, the pixel is shifted and LSBs are set to 0.  */
#define   LCDC_OVR2CFG9_REP_1_Val             _UINT32_(0x1)                                        /* (LCDC_OVR2CFG9) When the selected pixel depth is less than 24 bpp, the pixel is shifted and the LSB replicates the MSB.  */
#define LCDC_OVR2CFG9_REP_0                   (LCDC_OVR2CFG9_REP_0_Val << LCDC_OVR2CFG9_REP_Pos)   /* (LCDC_OVR2CFG9) When the selected pixel depth is less than 24 bpp, the pixel is shifted and LSBs are set to 0. Position  */
#define LCDC_OVR2CFG9_REP_1                   (LCDC_OVR2CFG9_REP_1_Val << LCDC_OVR2CFG9_REP_Pos)   /* (LCDC_OVR2CFG9) When the selected pixel depth is less than 24 bpp, the pixel is shifted and the LSB replicates the MSB. Position  */
#define LCDC_OVR2CFG9_CRKEY_Pos               _UINT32_(2)                                          /* (LCDC_OVR2CFG9) Chroma Keying Position */
#define LCDC_OVR2CFG9_CRKEY_Msk               (_UINT32_(0x1) << LCDC_OVR2CFG9_CRKEY_Pos)           /* (LCDC_OVR2CFG9) Chroma Keying Mask */
#define LCDC_OVR2CFG9_CRKEY(value)            (LCDC_OVR2CFG9_CRKEY_Msk & (_UINT32_(value) << LCDC_OVR2CFG9_CRKEY_Pos)) /* Assigment of value for CRKEY in the LCDC_OVR2CFG9 register */
#define LCDC_OVR2CFG9_DSTKEY_Pos              _UINT32_(3)                                          /* (LCDC_OVR2CFG9) Destination Color Keying Position */
#define LCDC_OVR2CFG9_DSTKEY_Msk              (_UINT32_(0x1) << LCDC_OVR2CFG9_DSTKEY_Pos)          /* (LCDC_OVR2CFG9) Destination Color Keying Mask */
#define LCDC_OVR2CFG9_DSTKEY(value)           (LCDC_OVR2CFG9_DSTKEY_Msk & (_UINT32_(value) << LCDC_OVR2CFG9_DSTKEY_Pos)) /* Assigment of value for DSTKEY in the LCDC_OVR2CFG9 register */
#define   LCDC_OVR2CFG9_DSTKEY_0_Val          _UINT32_(0x0)                                        /* (LCDC_OVR2CFG9) When CRKEY is enabled, color key is applied on OVR2 pixels, before the blending operation.  */
#define   LCDC_OVR2CFG9_DSTKEY_1_Val          _UINT32_(0x1)                                        /* (LCDC_OVR2CFG9) When CRKEY is enabled, color key is applied on OVR2 pixels, after the blending operation.  */
#define LCDC_OVR2CFG9_DSTKEY_0                (LCDC_OVR2CFG9_DSTKEY_0_Val << LCDC_OVR2CFG9_DSTKEY_Pos) /* (LCDC_OVR2CFG9) When CRKEY is enabled, color key is applied on OVR2 pixels, before the blending operation. Position  */
#define LCDC_OVR2CFG9_DSTKEY_1                (LCDC_OVR2CFG9_DSTKEY_1_Val << LCDC_OVR2CFG9_DSTKEY_Pos) /* (LCDC_OVR2CFG9) When CRKEY is enabled, color key is applied on OVR2 pixels, after the blending operation. Position  */
#define LCDC_OVR2CFG9_SFACTC_Pos              _UINT32_(6)                                          /* (LCDC_OVR2CFG9) Source Factor for the Blending Equation of the Color Component Position */
#define LCDC_OVR2CFG9_SFACTC_Msk              (_UINT32_(0x7) << LCDC_OVR2CFG9_SFACTC_Pos)          /* (LCDC_OVR2CFG9) Source Factor for the Blending Equation of the Color Component Mask */
#define LCDC_OVR2CFG9_SFACTC(value)           (LCDC_OVR2CFG9_SFACTC_Msk & (_UINT32_(value) << LCDC_OVR2CFG9_SFACTC_Pos)) /* Assigment of value for SFACTC in the LCDC_OVR2CFG9 register */
#define   LCDC_OVR2CFG9_SFACTC_ONE_Val        _UINT32_(0x0)                                        /* (LCDC_OVR2CFG9) Sets the factor to 1.0.  */
#define   LCDC_OVR2CFG9_SFACTC_ZERO_Val       _UINT32_(0x1)                                        /* (LCDC_OVR2CFG9) Sets the factor to 0.0.  */
#define   LCDC_OVR2CFG9_SFACTC_A0_Val         _UINT32_(0x2)                                        /* (LCDC_OVR2CFG9) Sets the factor to A0/255.  */
#define   LCDC_OVR2CFG9_SFACTC_A0_MULT_AD_Val _UINT32_(0x3)                                        /* (LCDC_OVR2CFG9) Sets the factor to A0 multiplied by Destination Alpha.  */
#define   LCDC_OVR2CFG9_SFACTC_A0_MUL_AS_Val  _UINT32_(0x4)                                        /* (LCDC_OVR2CFG9) Sets the factor to A0 multiplied by Source Alpha.  */
#define   LCDC_OVR2CFG9_SFACTC_M_A0_MUL_AD_Val _UINT32_(0x5)                                        /* (LCDC_OVR2CFG9) Computes A0 multiplied by Destination Alpha, then sets the factor to minus the result.  */
#define LCDC_OVR2CFG9_SFACTC_ONE              (LCDC_OVR2CFG9_SFACTC_ONE_Val << LCDC_OVR2CFG9_SFACTC_Pos) /* (LCDC_OVR2CFG9) Sets the factor to 1.0. Position  */
#define LCDC_OVR2CFG9_SFACTC_ZERO             (LCDC_OVR2CFG9_SFACTC_ZERO_Val << LCDC_OVR2CFG9_SFACTC_Pos) /* (LCDC_OVR2CFG9) Sets the factor to 0.0. Position  */
#define LCDC_OVR2CFG9_SFACTC_A0               (LCDC_OVR2CFG9_SFACTC_A0_Val << LCDC_OVR2CFG9_SFACTC_Pos) /* (LCDC_OVR2CFG9) Sets the factor to A0/255. Position  */
#define LCDC_OVR2CFG9_SFACTC_A0_MULT_AD       (LCDC_OVR2CFG9_SFACTC_A0_MULT_AD_Val << LCDC_OVR2CFG9_SFACTC_Pos) /* (LCDC_OVR2CFG9) Sets the factor to A0 multiplied by Destination Alpha. Position  */
#define LCDC_OVR2CFG9_SFACTC_A0_MUL_AS        (LCDC_OVR2CFG9_SFACTC_A0_MUL_AS_Val << LCDC_OVR2CFG9_SFACTC_Pos) /* (LCDC_OVR2CFG9) Sets the factor to A0 multiplied by Source Alpha. Position  */
#define LCDC_OVR2CFG9_SFACTC_M_A0_MUL_AD      (LCDC_OVR2CFG9_SFACTC_M_A0_MUL_AD_Val << LCDC_OVR2CFG9_SFACTC_Pos) /* (LCDC_OVR2CFG9) Computes A0 multiplied by Destination Alpha, then sets the factor to minus the result. Position  */
#define LCDC_OVR2CFG9_DFACTC_Pos              _UINT32_(11)                                         /* (LCDC_OVR2CFG9) Destination Factor for the Blending Equation of the Color Component Position */
#define LCDC_OVR2CFG9_DFACTC_Msk              (_UINT32_(0x7) << LCDC_OVR2CFG9_DFACTC_Pos)          /* (LCDC_OVR2CFG9) Destination Factor for the Blending Equation of the Color Component Mask */
#define LCDC_OVR2CFG9_DFACTC(value)           (LCDC_OVR2CFG9_DFACTC_Msk & (_UINT32_(value) << LCDC_OVR2CFG9_DFACTC_Pos)) /* Assigment of value for DFACTC in the LCDC_OVR2CFG9 register */
#define   LCDC_OVR2CFG9_DFACTC_ZERO_Val       _UINT32_(0x0)                                        /* (LCDC_OVR2CFG9) Sets the factor to 0.0.  */
#define   LCDC_OVR2CFG9_DFACTC_ONE_Val        _UINT32_(0x1)                                        /* (LCDC_OVR2CFG9) Sets the factor to 1.0.  */
#define   LCDC_OVR2CFG9_DFACTC_A0_Val         _UINT32_(0x2)                                        /* (LCDC_OVR2CFG9) Sets the factor to A0/255.  */
#define   LCDC_OVR2CFG9_DFACTC_A1_Val         _UINT32_(0x3)                                        /* (LCDC_OVR2CFG9) Sets the factor to A1/255.  */
#define   LCDC_OVR2CFG9_DFACTC_A0_MULT_AD_Val _UINT32_(0x4)                                        /* (LCDC_OVR2CFG9) Sets the factor to A0 multiplied by Destination Alpha.  */
#define   LCDC_OVR2CFG9_DFACTC_M_A0_MULT_AD_Val _UINT32_(0x5)                                        /* (LCDC_OVR2CFG9) Sets the factor to A0 multiplied by Destination Alpha, then set the factor one minus the result.  */
#define   LCDC_OVR2CFG9_DFACTC_M_A0_MUL_AS_Val _UINT32_(0x6)                                        /* (LCDC_OVR2CFG9) Computes A0 multiplied by source alpha0, then sets the factor to one minus the result.  */
#define   LCDC_OVR2CFG9_DFACTC_M_A0_Val       _UINT32_(0x7)                                        /* (LCDC_OVR2CFG9) Computes one minus A0, then sets the factor to one minus the result.  */
#define LCDC_OVR2CFG9_DFACTC_ZERO             (LCDC_OVR2CFG9_DFACTC_ZERO_Val << LCDC_OVR2CFG9_DFACTC_Pos) /* (LCDC_OVR2CFG9) Sets the factor to 0.0. Position  */
#define LCDC_OVR2CFG9_DFACTC_ONE              (LCDC_OVR2CFG9_DFACTC_ONE_Val << LCDC_OVR2CFG9_DFACTC_Pos) /* (LCDC_OVR2CFG9) Sets the factor to 1.0. Position  */
#define LCDC_OVR2CFG9_DFACTC_A0               (LCDC_OVR2CFG9_DFACTC_A0_Val << LCDC_OVR2CFG9_DFACTC_Pos) /* (LCDC_OVR2CFG9) Sets the factor to A0/255. Position  */
#define LCDC_OVR2CFG9_DFACTC_A1               (LCDC_OVR2CFG9_DFACTC_A1_Val << LCDC_OVR2CFG9_DFACTC_Pos) /* (LCDC_OVR2CFG9) Sets the factor to A1/255. Position  */
#define LCDC_OVR2CFG9_DFACTC_A0_MULT_AD       (LCDC_OVR2CFG9_DFACTC_A0_MULT_AD_Val << LCDC_OVR2CFG9_DFACTC_Pos) /* (LCDC_OVR2CFG9) Sets the factor to A0 multiplied by Destination Alpha. Position  */
#define LCDC_OVR2CFG9_DFACTC_M_A0_MULT_AD     (LCDC_OVR2CFG9_DFACTC_M_A0_MULT_AD_Val << LCDC_OVR2CFG9_DFACTC_Pos) /* (LCDC_OVR2CFG9) Sets the factor to A0 multiplied by Destination Alpha, then set the factor one minus the result. Position  */
#define LCDC_OVR2CFG9_DFACTC_M_A0_MUL_AS      (LCDC_OVR2CFG9_DFACTC_M_A0_MUL_AS_Val << LCDC_OVR2CFG9_DFACTC_Pos) /* (LCDC_OVR2CFG9) Computes A0 multiplied by source alpha0, then sets the factor to one minus the result. Position  */
#define LCDC_OVR2CFG9_DFACTC_M_A0             (LCDC_OVR2CFG9_DFACTC_M_A0_Val << LCDC_OVR2CFG9_DFACTC_Pos) /* (LCDC_OVR2CFG9) Computes one minus A0, then sets the factor to one minus the result. Position  */
#define LCDC_OVR2CFG9_A0_Pos                  _UINT32_(16)                                         /* (LCDC_OVR2CFG9) Alpha 0 Value Position */
#define LCDC_OVR2CFG9_A0_Msk                  (_UINT32_(0xFF) << LCDC_OVR2CFG9_A0_Pos)             /* (LCDC_OVR2CFG9) Alpha 0 Value Mask */
#define LCDC_OVR2CFG9_A0(value)               (LCDC_OVR2CFG9_A0_Msk & (_UINT32_(value) << LCDC_OVR2CFG9_A0_Pos)) /* Assigment of value for A0 in the LCDC_OVR2CFG9 register */
#define LCDC_OVR2CFG9_A1_Pos                  _UINT32_(24)                                         /* (LCDC_OVR2CFG9) Alpha 1 Value Position */
#define LCDC_OVR2CFG9_A1_Msk                  (_UINT32_(0xFF) << LCDC_OVR2CFG9_A1_Pos)             /* (LCDC_OVR2CFG9) Alpha 1 Value Mask */
#define LCDC_OVR2CFG9_A1(value)               (LCDC_OVR2CFG9_A1_Msk & (_UINT32_(value) << LCDC_OVR2CFG9_A1_Pos)) /* Assigment of value for A1 in the LCDC_OVR2CFG9 register */
#define LCDC_OVR2CFG9_Msk                     _UINT32_(0xFFFF39CF)                                 /* (LCDC_OVR2CFG9) Register Mask  */


/* -------- LCDC_HEOIER : (LCDC Offset: 0x360) ( /W 32) High-End Overlay Interrupt Enable Register -------- */
#define LCDC_HEOIER_END_Pos                   _UINT32_(0)                                          /* (LCDC_HEOIER) End of Frame DMA Transfer Interrupt Enable Position */
#define LCDC_HEOIER_END_Msk                   (_UINT32_(0x1) << LCDC_HEOIER_END_Pos)               /* (LCDC_HEOIER) End of Frame DMA Transfer Interrupt Enable Mask */
#define LCDC_HEOIER_END(value)                (LCDC_HEOIER_END_Msk & (_UINT32_(value) << LCDC_HEOIER_END_Pos)) /* Assigment of value for END in the LCDC_HEOIER register */
#define LCDC_HEOIER_ERROR_Pos                 _UINT32_(1)                                          /* (LCDC_HEOIER) Bus Transfer Error Detected Interrupt Enable Position */
#define LCDC_HEOIER_ERROR_Msk                 (_UINT32_(0x1) << LCDC_HEOIER_ERROR_Pos)             /* (LCDC_HEOIER) Bus Transfer Error Detected Interrupt Enable Mask */
#define LCDC_HEOIER_ERROR(value)              (LCDC_HEOIER_ERROR_Msk & (_UINT32_(value) << LCDC_HEOIER_ERROR_Pos)) /* Assigment of value for ERROR in the LCDC_HEOIER register */
#define LCDC_HEOIER_OVF_Pos                   _UINT32_(2)                                          /* (LCDC_HEOIER) Overflow Interrupt Enable Position */
#define LCDC_HEOIER_OVF_Msk                   (_UINT32_(0x1) << LCDC_HEOIER_OVF_Pos)               /* (LCDC_HEOIER) Overflow Interrupt Enable Mask */
#define LCDC_HEOIER_OVF(value)                (LCDC_HEOIER_OVF_Msk & (_UINT32_(value) << LCDC_HEOIER_OVF_Pos)) /* Assigment of value for OVF in the LCDC_HEOIER register */
#define LCDC_HEOIER_CBEND_Pos                 _UINT32_(8)                                          /* (LCDC_HEOIER) End of Frame DMA Transfer for Cb or CbCr Chroma Plane Interrupt Enable Position */
#define LCDC_HEOIER_CBEND_Msk                 (_UINT32_(0x1) << LCDC_HEOIER_CBEND_Pos)             /* (LCDC_HEOIER) End of Frame DMA Transfer for Cb or CbCr Chroma Plane Interrupt Enable Mask */
#define LCDC_HEOIER_CBEND(value)              (LCDC_HEOIER_CBEND_Msk & (_UINT32_(value) << LCDC_HEOIER_CBEND_Pos)) /* Assigment of value for CBEND in the LCDC_HEOIER register */
#define LCDC_HEOIER_CBERROR_Pos               _UINT32_(9)                                          /* (LCDC_HEOIER) Bus Transfer Error Detected for Cb or CbCr Chroma Plane Interrupt Enable Position */
#define LCDC_HEOIER_CBERROR_Msk               (_UINT32_(0x1) << LCDC_HEOIER_CBERROR_Pos)           /* (LCDC_HEOIER) Bus Transfer Error Detected for Cb or CbCr Chroma Plane Interrupt Enable Mask */
#define LCDC_HEOIER_CBERROR(value)            (LCDC_HEOIER_CBERROR_Msk & (_UINT32_(value) << LCDC_HEOIER_CBERROR_Pos)) /* Assigment of value for CBERROR in the LCDC_HEOIER register */
#define LCDC_HEOIER_CBOVF_Pos                 _UINT32_(10)                                         /* (LCDC_HEOIER) Overflow for Cb or CbCr Chroma Plane Interrupt Enable Position */
#define LCDC_HEOIER_CBOVF_Msk                 (_UINT32_(0x1) << LCDC_HEOIER_CBOVF_Pos)             /* (LCDC_HEOIER) Overflow for Cb or CbCr Chroma Plane Interrupt Enable Mask */
#define LCDC_HEOIER_CBOVF(value)              (LCDC_HEOIER_CBOVF_Msk & (_UINT32_(value) << LCDC_HEOIER_CBOVF_Pos)) /* Assigment of value for CBOVF in the LCDC_HEOIER register */
#define LCDC_HEOIER_CREND_Pos                 _UINT32_(16)                                         /* (LCDC_HEOIER) End of Frame DMA for Cr Chroma Plane Transfer Interrupt Enable Position */
#define LCDC_HEOIER_CREND_Msk                 (_UINT32_(0x1) << LCDC_HEOIER_CREND_Pos)             /* (LCDC_HEOIER) End of Frame DMA for Cr Chroma Plane Transfer Interrupt Enable Mask */
#define LCDC_HEOIER_CREND(value)              (LCDC_HEOIER_CREND_Msk & (_UINT32_(value) << LCDC_HEOIER_CREND_Pos)) /* Assigment of value for CREND in the LCDC_HEOIER register */
#define LCDC_HEOIER_CRERROR_Pos               _UINT32_(17)                                         /* (LCDC_HEOIER) Bus Transfer Error Detected for Cr Chroma Plane Interrupt Enable Position */
#define LCDC_HEOIER_CRERROR_Msk               (_UINT32_(0x1) << LCDC_HEOIER_CRERROR_Pos)           /* (LCDC_HEOIER) Bus Transfer Error Detected for Cr Chroma Plane Interrupt Enable Mask */
#define LCDC_HEOIER_CRERROR(value)            (LCDC_HEOIER_CRERROR_Msk & (_UINT32_(value) << LCDC_HEOIER_CRERROR_Pos)) /* Assigment of value for CRERROR in the LCDC_HEOIER register */
#define LCDC_HEOIER_CROVF_Pos                 _UINT32_(18)                                         /* (LCDC_HEOIER) Overflow for Cr Chroma Plane Interrupt Enable Position */
#define LCDC_HEOIER_CROVF_Msk                 (_UINT32_(0x1) << LCDC_HEOIER_CROVF_Pos)             /* (LCDC_HEOIER) Overflow for Cr Chroma Plane Interrupt Enable Mask */
#define LCDC_HEOIER_CROVF(value)              (LCDC_HEOIER_CROVF_Msk & (_UINT32_(value) << LCDC_HEOIER_CROVF_Pos)) /* Assigment of value for CROVF in the LCDC_HEOIER register */
#define LCDC_HEOIER_Msk                       _UINT32_(0x00070707)                                 /* (LCDC_HEOIER) Register Mask  */


/* -------- LCDC_HEOIDR : (LCDC Offset: 0x364) ( /W 32) High-End Overlay Interrupt Disable Register -------- */
#define LCDC_HEOIDR_END_Pos                   _UINT32_(0)                                          /* (LCDC_HEOIDR) End of Frame DMA Transfer Interrupt Disable Position */
#define LCDC_HEOIDR_END_Msk                   (_UINT32_(0x1) << LCDC_HEOIDR_END_Pos)               /* (LCDC_HEOIDR) End of Frame DMA Transfer Interrupt Disable Mask */
#define LCDC_HEOIDR_END(value)                (LCDC_HEOIDR_END_Msk & (_UINT32_(value) << LCDC_HEOIDR_END_Pos)) /* Assigment of value for END in the LCDC_HEOIDR register */
#define LCDC_HEOIDR_ERROR_Pos                 _UINT32_(1)                                          /* (LCDC_HEOIDR) Bus Transfer Error Detected Interrupt Disable Position */
#define LCDC_HEOIDR_ERROR_Msk                 (_UINT32_(0x1) << LCDC_HEOIDR_ERROR_Pos)             /* (LCDC_HEOIDR) Bus Transfer Error Detected Interrupt Disable Mask */
#define LCDC_HEOIDR_ERROR(value)              (LCDC_HEOIDR_ERROR_Msk & (_UINT32_(value) << LCDC_HEOIDR_ERROR_Pos)) /* Assigment of value for ERROR in the LCDC_HEOIDR register */
#define LCDC_HEOIDR_OVF_Pos                   _UINT32_(2)                                          /* (LCDC_HEOIDR) Overflow Interrupt Disable Position */
#define LCDC_HEOIDR_OVF_Msk                   (_UINT32_(0x1) << LCDC_HEOIDR_OVF_Pos)               /* (LCDC_HEOIDR) Overflow Interrupt Disable Mask */
#define LCDC_HEOIDR_OVF(value)                (LCDC_HEOIDR_OVF_Msk & (_UINT32_(value) << LCDC_HEOIDR_OVF_Pos)) /* Assigment of value for OVF in the LCDC_HEOIDR register */
#define LCDC_HEOIDR_CBEND_Pos                 _UINT32_(8)                                          /* (LCDC_HEOIDR) End of Frame DMA Transfer for Cb or CbCr Chroma Plane Interrupt Disable Position */
#define LCDC_HEOIDR_CBEND_Msk                 (_UINT32_(0x1) << LCDC_HEOIDR_CBEND_Pos)             /* (LCDC_HEOIDR) End of Frame DMA Transfer for Cb or CbCr Chroma Plane Interrupt Disable Mask */
#define LCDC_HEOIDR_CBEND(value)              (LCDC_HEOIDR_CBEND_Msk & (_UINT32_(value) << LCDC_HEOIDR_CBEND_Pos)) /* Assigment of value for CBEND in the LCDC_HEOIDR register */
#define LCDC_HEOIDR_CBERROR_Pos               _UINT32_(9)                                          /* (LCDC_HEOIDR) Bus Transfer Error Detected for Cb or CbCr Chroma Plane Interrupt Disable Position */
#define LCDC_HEOIDR_CBERROR_Msk               (_UINT32_(0x1) << LCDC_HEOIDR_CBERROR_Pos)           /* (LCDC_HEOIDR) Bus Transfer Error Detected for Cb or CbCr Chroma Plane Interrupt Disable Mask */
#define LCDC_HEOIDR_CBERROR(value)            (LCDC_HEOIDR_CBERROR_Msk & (_UINT32_(value) << LCDC_HEOIDR_CBERROR_Pos)) /* Assigment of value for CBERROR in the LCDC_HEOIDR register */
#define LCDC_HEOIDR_CBOVF_Pos                 _UINT32_(10)                                         /* (LCDC_HEOIDR) Overflow for Cb or CbCr Chroma Plane Interrupt Disable Position */
#define LCDC_HEOIDR_CBOVF_Msk                 (_UINT32_(0x1) << LCDC_HEOIDR_CBOVF_Pos)             /* (LCDC_HEOIDR) Overflow for Cb or CbCr Chroma Plane Interrupt Disable Mask */
#define LCDC_HEOIDR_CBOVF(value)              (LCDC_HEOIDR_CBOVF_Msk & (_UINT32_(value) << LCDC_HEOIDR_CBOVF_Pos)) /* Assigment of value for CBOVF in the LCDC_HEOIDR register */
#define LCDC_HEOIDR_CREND_Pos                 _UINT32_(16)                                         /* (LCDC_HEOIDR) End of Frame DMA Transfer for Cr Chroma Plane Interrupt Disable Position */
#define LCDC_HEOIDR_CREND_Msk                 (_UINT32_(0x1) << LCDC_HEOIDR_CREND_Pos)             /* (LCDC_HEOIDR) End of Frame DMA Transfer for Cr Chroma Plane Interrupt Disable Mask */
#define LCDC_HEOIDR_CREND(value)              (LCDC_HEOIDR_CREND_Msk & (_UINT32_(value) << LCDC_HEOIDR_CREND_Pos)) /* Assigment of value for CREND in the LCDC_HEOIDR register */
#define LCDC_HEOIDR_CRERROR_Pos               _UINT32_(17)                                         /* (LCDC_HEOIDR) Bus Transfer Error Detected for Cr Chroma Plane Interrupt Disable Position */
#define LCDC_HEOIDR_CRERROR_Msk               (_UINT32_(0x1) << LCDC_HEOIDR_CRERROR_Pos)           /* (LCDC_HEOIDR) Bus Transfer Error Detected for Cr Chroma Plane Interrupt Disable Mask */
#define LCDC_HEOIDR_CRERROR(value)            (LCDC_HEOIDR_CRERROR_Msk & (_UINT32_(value) << LCDC_HEOIDR_CRERROR_Pos)) /* Assigment of value for CRERROR in the LCDC_HEOIDR register */
#define LCDC_HEOIDR_CROVF_Pos                 _UINT32_(18)                                         /* (LCDC_HEOIDR) Overflow for Cr Chroma Plane Interrupt Disable Position */
#define LCDC_HEOIDR_CROVF_Msk                 (_UINT32_(0x1) << LCDC_HEOIDR_CROVF_Pos)             /* (LCDC_HEOIDR) Overflow for Cr Chroma Plane Interrupt Disable Mask */
#define LCDC_HEOIDR_CROVF(value)              (LCDC_HEOIDR_CROVF_Msk & (_UINT32_(value) << LCDC_HEOIDR_CROVF_Pos)) /* Assigment of value for CROVF in the LCDC_HEOIDR register */
#define LCDC_HEOIDR_Msk                       _UINT32_(0x00070707)                                 /* (LCDC_HEOIDR) Register Mask  */


/* -------- LCDC_HEOIMR : (LCDC Offset: 0x368) ( R/ 32) High-End Overlay Interrupt Mask Register -------- */
#define LCDC_HEOIMR_RESETVALUE                _UINT32_(0x00)                                       /*  (LCDC_HEOIMR) High-End Overlay Interrupt Mask Register  Reset Value */

#define LCDC_HEOIMR_END_Pos                   _UINT32_(0)                                          /* (LCDC_HEOIMR) End of Frame DMA Transfer Interrupt Mask Position */
#define LCDC_HEOIMR_END_Msk                   (_UINT32_(0x1) << LCDC_HEOIMR_END_Pos)               /* (LCDC_HEOIMR) End of Frame DMA Transfer Interrupt Mask Mask */
#define LCDC_HEOIMR_END(value)                (LCDC_HEOIMR_END_Msk & (_UINT32_(value) << LCDC_HEOIMR_END_Pos)) /* Assigment of value for END in the LCDC_HEOIMR register */
#define LCDC_HEOIMR_ERROR_Pos                 _UINT32_(1)                                          /* (LCDC_HEOIMR) Bus Transfer Error Detected Interrupt Mask Position */
#define LCDC_HEOIMR_ERROR_Msk                 (_UINT32_(0x1) << LCDC_HEOIMR_ERROR_Pos)             /* (LCDC_HEOIMR) Bus Transfer Error Detected Interrupt Mask Mask */
#define LCDC_HEOIMR_ERROR(value)              (LCDC_HEOIMR_ERROR_Msk & (_UINT32_(value) << LCDC_HEOIMR_ERROR_Pos)) /* Assigment of value for ERROR in the LCDC_HEOIMR register */
#define LCDC_HEOIMR_OVF_Pos                   _UINT32_(2)                                          /* (LCDC_HEOIMR) Overflow Interrupt Mask Position */
#define LCDC_HEOIMR_OVF_Msk                   (_UINT32_(0x1) << LCDC_HEOIMR_OVF_Pos)               /* (LCDC_HEOIMR) Overflow Interrupt Mask Mask */
#define LCDC_HEOIMR_OVF(value)                (LCDC_HEOIMR_OVF_Msk & (_UINT32_(value) << LCDC_HEOIMR_OVF_Pos)) /* Assigment of value for OVF in the LCDC_HEOIMR register */
#define LCDC_HEOIMR_CBEND_Pos                 _UINT32_(8)                                          /* (LCDC_HEOIMR) End of Frame DMA Transfer for Cb or CbCr Chroma Plane Interrupt Mask Position */
#define LCDC_HEOIMR_CBEND_Msk                 (_UINT32_(0x1) << LCDC_HEOIMR_CBEND_Pos)             /* (LCDC_HEOIMR) End of Frame DMA Transfer for Cb or CbCr Chroma Plane Interrupt Mask Mask */
#define LCDC_HEOIMR_CBEND(value)              (LCDC_HEOIMR_CBEND_Msk & (_UINT32_(value) << LCDC_HEOIMR_CBEND_Pos)) /* Assigment of value for CBEND in the LCDC_HEOIMR register */
#define LCDC_HEOIMR_CBERROR_Pos               _UINT32_(9)                                          /* (LCDC_HEOIMR) Bus Transfer Error Detected for Cb or CbCr Chroma Plane Interrupt Mask Position */
#define LCDC_HEOIMR_CBERROR_Msk               (_UINT32_(0x1) << LCDC_HEOIMR_CBERROR_Pos)           /* (LCDC_HEOIMR) Bus Transfer Error Detected for Cb or CbCr Chroma Plane Interrupt Mask Mask */
#define LCDC_HEOIMR_CBERROR(value)            (LCDC_HEOIMR_CBERROR_Msk & (_UINT32_(value) << LCDC_HEOIMR_CBERROR_Pos)) /* Assigment of value for CBERROR in the LCDC_HEOIMR register */
#define LCDC_HEOIMR_CBOVF_Pos                 _UINT32_(10)                                         /* (LCDC_HEOIMR) Overflow for Cb or CbCr Chroma Plane Interrupt Mask Position */
#define LCDC_HEOIMR_CBOVF_Msk                 (_UINT32_(0x1) << LCDC_HEOIMR_CBOVF_Pos)             /* (LCDC_HEOIMR) Overflow for Cb or CbCr Chroma Plane Interrupt Mask Mask */
#define LCDC_HEOIMR_CBOVF(value)              (LCDC_HEOIMR_CBOVF_Msk & (_UINT32_(value) << LCDC_HEOIMR_CBOVF_Pos)) /* Assigment of value for CBOVF in the LCDC_HEOIMR register */
#define LCDC_HEOIMR_CREND_Pos                 _UINT32_(16)                                         /* (LCDC_HEOIMR) End of Frame DMA Transfer for Cr Chroma Plane Interrupt Mask Position */
#define LCDC_HEOIMR_CREND_Msk                 (_UINT32_(0x1) << LCDC_HEOIMR_CREND_Pos)             /* (LCDC_HEOIMR) End of Frame DMA Transfer for Cr Chroma Plane Interrupt Mask Mask */
#define LCDC_HEOIMR_CREND(value)              (LCDC_HEOIMR_CREND_Msk & (_UINT32_(value) << LCDC_HEOIMR_CREND_Pos)) /* Assigment of value for CREND in the LCDC_HEOIMR register */
#define LCDC_HEOIMR_CRERROR_Pos               _UINT32_(17)                                         /* (LCDC_HEOIMR) Bus Transfer Error Detected for Cr Chroma Plane Interrupt Mask Position */
#define LCDC_HEOIMR_CRERROR_Msk               (_UINT32_(0x1) << LCDC_HEOIMR_CRERROR_Pos)           /* (LCDC_HEOIMR) Bus Transfer Error Detected for Cr Chroma Plane Interrupt Mask Mask */
#define LCDC_HEOIMR_CRERROR(value)            (LCDC_HEOIMR_CRERROR_Msk & (_UINT32_(value) << LCDC_HEOIMR_CRERROR_Pos)) /* Assigment of value for CRERROR in the LCDC_HEOIMR register */
#define LCDC_HEOIMR_CROVF_Pos                 _UINT32_(18)                                         /* (LCDC_HEOIMR) Overflow for Cr Chroma Plane Interrupt Mask Position */
#define LCDC_HEOIMR_CROVF_Msk                 (_UINT32_(0x1) << LCDC_HEOIMR_CROVF_Pos)             /* (LCDC_HEOIMR) Overflow for Cr Chroma Plane Interrupt Mask Mask */
#define LCDC_HEOIMR_CROVF(value)              (LCDC_HEOIMR_CROVF_Msk & (_UINT32_(value) << LCDC_HEOIMR_CROVF_Pos)) /* Assigment of value for CROVF in the LCDC_HEOIMR register */
#define LCDC_HEOIMR_Msk                       _UINT32_(0x00070707)                                 /* (LCDC_HEOIMR) Register Mask  */


/* -------- LCDC_HEOISR : (LCDC Offset: 0x36C) ( R/ 32) High-End Overlay Interrupt Status Register -------- */
#define LCDC_HEOISR_RESETVALUE                _UINT32_(0x00)                                       /*  (LCDC_HEOISR) High-End Overlay Interrupt Status Register  Reset Value */

#define LCDC_HEOISR_END_Pos                   _UINT32_(0)                                          /* (LCDC_HEOISR) End of Frame DMA Transfer Position */
#define LCDC_HEOISR_END_Msk                   (_UINT32_(0x1) << LCDC_HEOISR_END_Pos)               /* (LCDC_HEOISR) End of Frame DMA Transfer Mask */
#define LCDC_HEOISR_END(value)                (LCDC_HEOISR_END_Msk & (_UINT32_(value) << LCDC_HEOISR_END_Pos)) /* Assigment of value for END in the LCDC_HEOISR register */
#define   LCDC_HEOISR_END_0_Val               _UINT32_(0x0)                                        /* (LCDC_HEOISR) No end of transfer has been detected since last read of LCDC_HEOISR.  */
#define   LCDC_HEOISR_END_1_Val               _UINT32_(0x1)                                        /* (LCDC_HEOISR) End of transfer has been detected. This flag is reset after a read operation.  */
#define LCDC_HEOISR_END_0                     (LCDC_HEOISR_END_0_Val << LCDC_HEOISR_END_Pos)       /* (LCDC_HEOISR) No end of transfer has been detected since last read of LCDC_HEOISR. Position  */
#define LCDC_HEOISR_END_1                     (LCDC_HEOISR_END_1_Val << LCDC_HEOISR_END_Pos)       /* (LCDC_HEOISR) End of transfer has been detected. This flag is reset after a read operation. Position  */
#define LCDC_HEOISR_ERROR_Pos                 _UINT32_(1)                                          /* (LCDC_HEOISR) Bus Error Detected Position */
#define LCDC_HEOISR_ERROR_Msk                 (_UINT32_(0x1) << LCDC_HEOISR_ERROR_Pos)             /* (LCDC_HEOISR) Bus Error Detected Mask */
#define LCDC_HEOISR_ERROR(value)              (LCDC_HEOISR_ERROR_Msk & (_UINT32_(value) << LCDC_HEOISR_ERROR_Pos)) /* Assigment of value for ERROR in the LCDC_HEOISR register */
#define   LCDC_HEOISR_ERROR_0_Val             _UINT32_(0x0)                                        /* (LCDC_HEOISR) No system bus error has been detected since the last read of LCDC_HEOISR.  */
#define   LCDC_HEOISR_ERROR_1_Val             _UINT32_(0x1)                                        /* (LCDC_HEOISR) A system bus error has been detected. This flag is reset after a read operation.  */
#define LCDC_HEOISR_ERROR_0                   (LCDC_HEOISR_ERROR_0_Val << LCDC_HEOISR_ERROR_Pos)   /* (LCDC_HEOISR) No system bus error has been detected since the last read of LCDC_HEOISR. Position  */
#define LCDC_HEOISR_ERROR_1                   (LCDC_HEOISR_ERROR_1_Val << LCDC_HEOISR_ERROR_Pos)   /* (LCDC_HEOISR) A system bus error has been detected. This flag is reset after a read operation. Position  */
#define LCDC_HEOISR_OVF_Pos                   _UINT32_(2)                                          /* (LCDC_HEOISR) Overflow Detected Position */
#define LCDC_HEOISR_OVF_Msk                   (_UINT32_(0x1) << LCDC_HEOISR_OVF_Pos)               /* (LCDC_HEOISR) Overflow Detected Mask */
#define LCDC_HEOISR_OVF(value)                (LCDC_HEOISR_OVF_Msk & (_UINT32_(value) << LCDC_HEOISR_OVF_Pos)) /* Assigment of value for OVF in the LCDC_HEOISR register */
#define   LCDC_HEOISR_OVF_0_Val               _UINT32_(0x0)                                        /* (LCDC_HEOISR) No overflow occurred since last read of LCDC_HEOISR.  */
#define   LCDC_HEOISR_OVF_1_Val               _UINT32_(0x1)                                        /* (LCDC_HEOISR) An overflow occurred, at least one DMA transfer is still running at the End Of Frame. This flag is reset after a read operation  */
#define LCDC_HEOISR_OVF_0                     (LCDC_HEOISR_OVF_0_Val << LCDC_HEOISR_OVF_Pos)       /* (LCDC_HEOISR) No overflow occurred since last read of LCDC_HEOISR. Position  */
#define LCDC_HEOISR_OVF_1                     (LCDC_HEOISR_OVF_1_Val << LCDC_HEOISR_OVF_Pos)       /* (LCDC_HEOISR) An overflow occurred, at least one DMA transfer is still running at the End Of Frame. This flag is reset after a read operation Position  */
#define LCDC_HEOISR_CBEND_Pos                 _UINT32_(8)                                          /* (LCDC_HEOISR) End of Frame DMA Transfer for Cb or CbCr plane Position */
#define LCDC_HEOISR_CBEND_Msk                 (_UINT32_(0x1) << LCDC_HEOISR_CBEND_Pos)             /* (LCDC_HEOISR) End of Frame DMA Transfer for Cb or CbCr plane Mask */
#define LCDC_HEOISR_CBEND(value)              (LCDC_HEOISR_CBEND_Msk & (_UINT32_(value) << LCDC_HEOISR_CBEND_Pos)) /* Assigment of value for CBEND in the LCDC_HEOISR register */
#define   LCDC_HEOISR_CBEND_0_Val             _UINT32_(0x0)                                        /* (LCDC_HEOISR) No end of transfer has been detected since last read of LCDC_HEOISR.  */
#define   LCDC_HEOISR_CBEND_1_Val             _UINT32_(0x1)                                        /* (LCDC_HEOISR) End of transfer has been detected. This flag is reset after a read operation.  */
#define LCDC_HEOISR_CBEND_0                   (LCDC_HEOISR_CBEND_0_Val << LCDC_HEOISR_CBEND_Pos)   /* (LCDC_HEOISR) No end of transfer has been detected since last read of LCDC_HEOISR. Position  */
#define LCDC_HEOISR_CBEND_1                   (LCDC_HEOISR_CBEND_1_Val << LCDC_HEOISR_CBEND_Pos)   /* (LCDC_HEOISR) End of transfer has been detected. This flag is reset after a read operation. Position  */
#define LCDC_HEOISR_CBERROR_Pos               _UINT32_(9)                                          /* (LCDC_HEOISR) Bus Transfer Error Detected for Cb or CbCr plane Position */
#define LCDC_HEOISR_CBERROR_Msk               (_UINT32_(0x1) << LCDC_HEOISR_CBERROR_Pos)           /* (LCDC_HEOISR) Bus Transfer Error Detected for Cb or CbCr plane Mask */
#define LCDC_HEOISR_CBERROR(value)            (LCDC_HEOISR_CBERROR_Msk & (_UINT32_(value) << LCDC_HEOISR_CBERROR_Pos)) /* Assigment of value for CBERROR in the LCDC_HEOISR register */
#define   LCDC_HEOISR_CBERROR_0_Val           _UINT32_(0x0)                                        /* (LCDC_HEOISR) No system bus error has been detected since the last read of LCDC_HEOISR.  */
#define   LCDC_HEOISR_CBERROR_1_Val           _UINT32_(0x1)                                        /* (LCDC_HEOISR) A system bus error has been detected. This flag is reset after a read operation.  */
#define LCDC_HEOISR_CBERROR_0                 (LCDC_HEOISR_CBERROR_0_Val << LCDC_HEOISR_CBERROR_Pos) /* (LCDC_HEOISR) No system bus error has been detected since the last read of LCDC_HEOISR. Position  */
#define LCDC_HEOISR_CBERROR_1                 (LCDC_HEOISR_CBERROR_1_Val << LCDC_HEOISR_CBERROR_Pos) /* (LCDC_HEOISR) A system bus error has been detected. This flag is reset after a read operation. Position  */
#define LCDC_HEOISR_CBOVF_Pos                 _UINT32_(10)                                         /* (LCDC_HEOISR) Overflow Detected for Cb or CbCr plane Position */
#define LCDC_HEOISR_CBOVF_Msk                 (_UINT32_(0x1) << LCDC_HEOISR_CBOVF_Pos)             /* (LCDC_HEOISR) Overflow Detected for Cb or CbCr plane Mask */
#define LCDC_HEOISR_CBOVF(value)              (LCDC_HEOISR_CBOVF_Msk & (_UINT32_(value) << LCDC_HEOISR_CBOVF_Pos)) /* Assigment of value for CBOVF in the LCDC_HEOISR register */
#define   LCDC_HEOISR_CBOVF_0_Val             _UINT32_(0x0)                                        /* (LCDC_HEOISR) No overflow occurred since last read of LCDC_HEOISR.  */
#define   LCDC_HEOISR_CBOVF_1_Val             _UINT32_(0x1)                                        /* (LCDC_HEOISR) An overflow occurred, at least one DMA transfer is still running at the End Of Frame. This flag is reset after a read operation.  */
#define LCDC_HEOISR_CBOVF_0                   (LCDC_HEOISR_CBOVF_0_Val << LCDC_HEOISR_CBOVF_Pos)   /* (LCDC_HEOISR) No overflow occurred since last read of LCDC_HEOISR. Position  */
#define LCDC_HEOISR_CBOVF_1                   (LCDC_HEOISR_CBOVF_1_Val << LCDC_HEOISR_CBOVF_Pos)   /* (LCDC_HEOISR) An overflow occurred, at least one DMA transfer is still running at the End Of Frame. This flag is reset after a read operation. Position  */
#define LCDC_HEOISR_CREND_Pos                 _UINT32_(16)                                         /* (LCDC_HEOISR) End of Frame DMA Transfer for Cr plane Position */
#define LCDC_HEOISR_CREND_Msk                 (_UINT32_(0x1) << LCDC_HEOISR_CREND_Pos)             /* (LCDC_HEOISR) End of Frame DMA Transfer for Cr plane Mask */
#define LCDC_HEOISR_CREND(value)              (LCDC_HEOISR_CREND_Msk & (_UINT32_(value) << LCDC_HEOISR_CREND_Pos)) /* Assigment of value for CREND in the LCDC_HEOISR register */
#define   LCDC_HEOISR_CREND_0_Val             _UINT32_(0x0)                                        /* (LCDC_HEOISR) No end of transfer has been detected since last read of LCDC_HEOISR.  */
#define   LCDC_HEOISR_CREND_1_Val             _UINT32_(0x1)                                        /* (LCDC_HEOISR) End of transfer has been detected. This flag is reset after a read operation.  */
#define LCDC_HEOISR_CREND_0                   (LCDC_HEOISR_CREND_0_Val << LCDC_HEOISR_CREND_Pos)   /* (LCDC_HEOISR) No end of transfer has been detected since last read of LCDC_HEOISR. Position  */
#define LCDC_HEOISR_CREND_1                   (LCDC_HEOISR_CREND_1_Val << LCDC_HEOISR_CREND_Pos)   /* (LCDC_HEOISR) End of transfer has been detected. This flag is reset after a read operation. Position  */
#define LCDC_HEOISR_CRERROR_Pos               _UINT32_(17)                                         /* (LCDC_HEOISR) Bus Transfer Error detected for Cr plane Position */
#define LCDC_HEOISR_CRERROR_Msk               (_UINT32_(0x1) << LCDC_HEOISR_CRERROR_Pos)           /* (LCDC_HEOISR) Bus Transfer Error detected for Cr plane Mask */
#define LCDC_HEOISR_CRERROR(value)            (LCDC_HEOISR_CRERROR_Msk & (_UINT32_(value) << LCDC_HEOISR_CRERROR_Pos)) /* Assigment of value for CRERROR in the LCDC_HEOISR register */
#define   LCDC_HEOISR_CRERROR_0_Val           _UINT32_(0x0)                                        /* (LCDC_HEOISR) No system bus error has been detected since the last read of LCDC_HEOISR.  */
#define   LCDC_HEOISR_CRERROR_1_Val           _UINT32_(0x1)                                        /* (LCDC_HEOISR) A system bus error has been detected. This flag is reset after a read operation.  */
#define LCDC_HEOISR_CRERROR_0                 (LCDC_HEOISR_CRERROR_0_Val << LCDC_HEOISR_CRERROR_Pos) /* (LCDC_HEOISR) No system bus error has been detected since the last read of LCDC_HEOISR. Position  */
#define LCDC_HEOISR_CRERROR_1                 (LCDC_HEOISR_CRERROR_1_Val << LCDC_HEOISR_CRERROR_Pos) /* (LCDC_HEOISR) A system bus error has been detected. This flag is reset after a read operation. Position  */
#define LCDC_HEOISR_CROVF_Pos                 _UINT32_(18)                                         /* (LCDC_HEOISR) Overflow Detected for Cr plane Position */
#define LCDC_HEOISR_CROVF_Msk                 (_UINT32_(0x1) << LCDC_HEOISR_CROVF_Pos)             /* (LCDC_HEOISR) Overflow Detected for Cr plane Mask */
#define LCDC_HEOISR_CROVF(value)              (LCDC_HEOISR_CROVF_Msk & (_UINT32_(value) << LCDC_HEOISR_CROVF_Pos)) /* Assigment of value for CROVF in the LCDC_HEOISR register */
#define   LCDC_HEOISR_CROVF_0_Val             _UINT32_(0x0)                                        /* (LCDC_HEOISR) No overflow occurred since last read of LCDC_HEOISR.  */
#define   LCDC_HEOISR_CROVF_1_Val             _UINT32_(0x1)                                        /* (LCDC_HEOISR) An overflow occurred, at least one DMA transfer is still running at the End Of Frame. This flag is reset after a read operation.  */
#define LCDC_HEOISR_CROVF_0                   (LCDC_HEOISR_CROVF_0_Val << LCDC_HEOISR_CROVF_Pos)   /* (LCDC_HEOISR) No overflow occurred since last read of LCDC_HEOISR. Position  */
#define LCDC_HEOISR_CROVF_1                   (LCDC_HEOISR_CROVF_1_Val << LCDC_HEOISR_CROVF_Pos)   /* (LCDC_HEOISR) An overflow occurred, at least one DMA transfer is still running at the End Of Frame. This flag is reset after a read operation. Position  */
#define LCDC_HEOISR_Msk                       _UINT32_(0x00070707)                                 /* (LCDC_HEOISR) Register Mask  */


/* -------- LCDC_HEOEN : (LCDC Offset: 0x370) (R/W 32) High-End Overlay Enable Register -------- */
#define LCDC_HEOEN_RESETVALUE                 _UINT32_(0x00)                                       /*  (LCDC_HEOEN) High-End Overlay Enable Register  Reset Value */

#define LCDC_HEOEN_ENABLE_Pos                 _UINT32_(0)                                          /* (LCDC_HEOEN) Overlay Enable Position */
#define LCDC_HEOEN_ENABLE_Msk                 (_UINT32_(0x1) << LCDC_HEOEN_ENABLE_Pos)             /* (LCDC_HEOEN) Overlay Enable Mask */
#define LCDC_HEOEN_ENABLE(value)              (LCDC_HEOEN_ENABLE_Msk & (_UINT32_(value) << LCDC_HEOEN_ENABLE_Pos)) /* Assigment of value for ENABLE in the LCDC_HEOEN register */
#define   LCDC_HEOEN_ENABLE_0_Val             _UINT32_(0x0)                                        /* (LCDC_HEOEN) The layer is disabled.  */
#define   LCDC_HEOEN_ENABLE_1_Val             _UINT32_(0x1)                                        /* (LCDC_HEOEN) The layer is enabled.  */
#define LCDC_HEOEN_ENABLE_0                   (LCDC_HEOEN_ENABLE_0_Val << LCDC_HEOEN_ENABLE_Pos)   /* (LCDC_HEOEN) The layer is disabled. Position  */
#define LCDC_HEOEN_ENABLE_1                   (LCDC_HEOEN_ENABLE_1_Val << LCDC_HEOEN_ENABLE_Pos)   /* (LCDC_HEOEN) The layer is enabled. Position  */
#define LCDC_HEOEN_Msk                        _UINT32_(0x00000001)                                 /* (LCDC_HEOEN) Register Mask  */


/* -------- LCDC_HEOCLA : (LCDC Offset: 0x374) (R/W 32) High-End Overlay Table Address Register -------- */
#define LCDC_HEOCLA_RESETVALUE                _UINT32_(0x00)                                       /*  (LCDC_HEOCLA) High-End Overlay Table Address Register  Reset Value */

#define LCDC_HEOCLA_CLA_Pos                   _UINT32_(2)                                          /* (LCDC_HEOCLA) High-End Overlay CLUT Address Position */
#define LCDC_HEOCLA_CLA_Msk                   (_UINT32_(0x3FFFFFFF) << LCDC_HEOCLA_CLA_Pos)        /* (LCDC_HEOCLA) High-End Overlay CLUT Address Mask */
#define LCDC_HEOCLA_CLA(value)                (LCDC_HEOCLA_CLA_Msk & (_UINT32_(value) << LCDC_HEOCLA_CLA_Pos)) /* Assigment of value for CLA in the LCDC_HEOCLA register */
#define LCDC_HEOCLA_Msk                       _UINT32_(0xFFFFFFFC)                                 /* (LCDC_HEOCLA) Register Mask  */


/* -------- LCDC_HEOCFG0 : (LCDC Offset: 0x390) (R/W 32) High-End Overlay Configuration Register 0 -------- */
#define LCDC_HEOCFG0_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_HEOCFG0) High-End Overlay Configuration Register 0  Reset Value */

#define LCDC_HEOCFG0_BLEN_Pos                 _UINT32_(4)                                          /* (LCDC_HEOCFG0) System Bus Burst Length Position */
#define LCDC_HEOCFG0_BLEN_Msk                 (_UINT32_(0x7) << LCDC_HEOCFG0_BLEN_Pos)             /* (LCDC_HEOCFG0) System Bus Burst Length Mask */
#define LCDC_HEOCFG0_BLEN(value)              (LCDC_HEOCFG0_BLEN_Msk & (_UINT32_(value) << LCDC_HEOCFG0_BLEN_Pos)) /* Assigment of value for BLEN in the LCDC_HEOCFG0 register */
#define   LCDC_HEOCFG0_BLEN_INCR1_Val         _UINT32_(0x0)                                        /* (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store one data.  */
#define   LCDC_HEOCFG0_BLEN_INCR4_Val         _UINT32_(0x1)                                        /* (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 4 data. A system bus INCR4 Burst is used by default. INCR1 is used for bursts less than 4.  */
#define   LCDC_HEOCFG0_BLEN_INCR8_Val         _UINT32_(0x2)                                        /* (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 8 data. A system bus INCR8 Burst is used by default. INCR4 bursts are used for bursts of 4 beats. INCR1 is used for bursts less than 4.  */
#define   LCDC_HEOCFG0_BLEN_INCR16_Val        _UINT32_(0x3)                                        /* (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 16 data. A system bus INCR16 Burst is used by default. INCR8 and INCR4 bursts are respectively used for bursts of 8 and 4 beats. INCR1 is used for bursts less than 4.  */
#define   LCDC_HEOCFG0_BLEN_INCR32_Val        _UINT32_(0x4)                                        /* (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 32 data. A system bus INCR32 Burst is used by default. INCR16, INCR8 and INCR4 bursts are respectively used for bursts of 16, 8 and 4 beats. INCR1 is used for bursts less than 4.  */
#define LCDC_HEOCFG0_BLEN_INCR1               (LCDC_HEOCFG0_BLEN_INCR1_Val << LCDC_HEOCFG0_BLEN_Pos) /* (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store one data. Position  */
#define LCDC_HEOCFG0_BLEN_INCR4               (LCDC_HEOCFG0_BLEN_INCR4_Val << LCDC_HEOCFG0_BLEN_Pos) /* (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 4 data. A system bus INCR4 Burst is used by default. INCR1 is used for bursts less than 4. Position  */
#define LCDC_HEOCFG0_BLEN_INCR8               (LCDC_HEOCFG0_BLEN_INCR8_Val << LCDC_HEOCFG0_BLEN_Pos) /* (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 8 data. A system bus INCR8 Burst is used by default. INCR4 bursts are used for bursts of 4 beats. INCR1 is used for bursts less than 4. Position  */
#define LCDC_HEOCFG0_BLEN_INCR16              (LCDC_HEOCFG0_BLEN_INCR16_Val << LCDC_HEOCFG0_BLEN_Pos) /* (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 16 data. A system bus INCR16 Burst is used by default. INCR8 and INCR4 bursts are respectively used for bursts of 8 and 4 beats. INCR1 is used for bursts less than 4. Position  */
#define LCDC_HEOCFG0_BLEN_INCR32              (LCDC_HEOCFG0_BLEN_INCR32_Val << LCDC_HEOCFG0_BLEN_Pos) /* (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 32 data. A system bus INCR32 Burst is used by default. INCR16, INCR8 and INCR4 bursts are respectively used for bursts of 16, 8 and 4 beats. INCR1 is used for bursts less than 4. Position  */
#define LCDC_HEOCFG0_BLENCC_Pos               _UINT32_(8)                                          /* (LCDC_HEOCFG0) System Bus Burst Length for Cb-Cr Channel Position */
#define LCDC_HEOCFG0_BLENCC_Msk               (_UINT32_(0x7) << LCDC_HEOCFG0_BLENCC_Pos)           /* (LCDC_HEOCFG0) System Bus Burst Length for Cb-Cr Channel Mask */
#define LCDC_HEOCFG0_BLENCC(value)            (LCDC_HEOCFG0_BLENCC_Msk & (_UINT32_(value) << LCDC_HEOCFG0_BLENCC_Pos)) /* Assigment of value for BLENCC in the LCDC_HEOCFG0 register */
#define   LCDC_HEOCFG0_BLENCC_INCR1_Val       _UINT32_(0x0)                                        /* (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store one data.  */
#define   LCDC_HEOCFG0_BLENCC_INCR4_Val       _UINT32_(0x1)                                        /* (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 4 data. A system bus INCR4 Burst is used by default. INCR1 is used for bursts less than 4.  */
#define   LCDC_HEOCFG0_BLENCC_INCR8_Val       _UINT32_(0x2)                                        /* (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 8 data. A system bus INCR8 Burst is used by default. INCR4 bursts are used for bursts of 4 beats. INCR1 is used for bursts less than 4.  */
#define   LCDC_HEOCFG0_BLENCC_INCR16_Val      _UINT32_(0x3)                                        /* (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 16 data. A system bus INCR16 Burst is used by default. INCR8 and INCR4 bursts are respectively used for bursts of 8 and 4 beats. INCR1 is used for bursts less than 4.  */
#define   LCDC_HEOCFG0_BLENCC_INCR32_Val      _UINT32_(0x4)                                        /* (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 32 data. A system bus INCR32 Burst is used by default. INCR16, INCR8 and INCR4 bursts are respectively used for bursts of 16, 8 and 4 beats. INCR1 is used for bursts less than 4.  */
#define LCDC_HEOCFG0_BLENCC_INCR1             (LCDC_HEOCFG0_BLENCC_INCR1_Val << LCDC_HEOCFG0_BLENCC_Pos) /* (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store one data. Position  */
#define LCDC_HEOCFG0_BLENCC_INCR4             (LCDC_HEOCFG0_BLENCC_INCR4_Val << LCDC_HEOCFG0_BLENCC_Pos) /* (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 4 data. A system bus INCR4 Burst is used by default. INCR1 is used for bursts less than 4. Position  */
#define LCDC_HEOCFG0_BLENCC_INCR8             (LCDC_HEOCFG0_BLENCC_INCR8_Val << LCDC_HEOCFG0_BLENCC_Pos) /* (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 8 data. A system bus INCR8 Burst is used by default. INCR4 bursts are used for bursts of 4 beats. INCR1 is used for bursts less than 4. Position  */
#define LCDC_HEOCFG0_BLENCC_INCR16            (LCDC_HEOCFG0_BLENCC_INCR16_Val << LCDC_HEOCFG0_BLENCC_Pos) /* (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 16 data. A system bus INCR16 Burst is used by default. INCR8 and INCR4 bursts are respectively used for bursts of 8 and 4 beats. INCR1 is used for bursts less than 4. Position  */
#define LCDC_HEOCFG0_BLENCC_INCR32            (LCDC_HEOCFG0_BLENCC_INCR32_Val << LCDC_HEOCFG0_BLENCC_Pos) /* (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 32 data. A system bus INCR32 Burst is used by default. INCR16, INCR8 and INCR4 bursts are respectively used for bursts of 16, 8 and 4 beats. INCR1 is used for bursts less than 4. Position  */
#define LCDC_HEOCFG0_Msk                      _UINT32_(0x00000770)                                 /* (LCDC_HEOCFG0) Register Mask  */


/* -------- LCDC_HEOCFG1 : (LCDC Offset: 0x394) (R/W 32) High-End Overlay Configuration Register 1 -------- */
#define LCDC_HEOCFG1_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_HEOCFG1) High-End Overlay Configuration Register 1  Reset Value */

#define LCDC_HEOCFG1_CLUTEN_Pos               _UINT32_(0)                                          /* (LCDC_HEOCFG1) CLUT Mode Enable Position */
#define LCDC_HEOCFG1_CLUTEN_Msk               (_UINT32_(0x1) << LCDC_HEOCFG1_CLUTEN_Pos)           /* (LCDC_HEOCFG1) CLUT Mode Enable Mask */
#define LCDC_HEOCFG1_CLUTEN(value)            (LCDC_HEOCFG1_CLUTEN_Msk & (_UINT32_(value) << LCDC_HEOCFG1_CLUTEN_Pos)) /* Assigment of value for CLUTEN in the LCDC_HEOCFG1 register */
#define   LCDC_HEOCFG1_CLUTEN_0_Val           _UINT32_(0x0)                                        /* (LCDC_HEOCFG1) RGB mode is selected.  */
#define   LCDC_HEOCFG1_CLUTEN_1_Val           _UINT32_(0x1)                                        /* (LCDC_HEOCFG1) CLUT mode is selected.  */
#define LCDC_HEOCFG1_CLUTEN_0                 (LCDC_HEOCFG1_CLUTEN_0_Val << LCDC_HEOCFG1_CLUTEN_Pos) /* (LCDC_HEOCFG1) RGB mode is selected. Position  */
#define LCDC_HEOCFG1_CLUTEN_1                 (LCDC_HEOCFG1_CLUTEN_1_Val << LCDC_HEOCFG1_CLUTEN_Pos) /* (LCDC_HEOCFG1) CLUT mode is selected. Position  */
#define LCDC_HEOCFG1_YCCEN_Pos                _UINT32_(1)                                          /* (LCDC_HEOCFG1) YCbCr Color Space Enable Position */
#define LCDC_HEOCFG1_YCCEN_Msk                (_UINT32_(0x1) << LCDC_HEOCFG1_YCCEN_Pos)            /* (LCDC_HEOCFG1) YCbCr Color Space Enable Mask */
#define LCDC_HEOCFG1_YCCEN(value)             (LCDC_HEOCFG1_YCCEN_Msk & (_UINT32_(value) << LCDC_HEOCFG1_YCCEN_Pos)) /* Assigment of value for YCCEN in the LCDC_HEOCFG1 register */
#define   LCDC_HEOCFG1_YCCEN_0_Val            _UINT32_(0x0)                                        /* (LCDC_HEOCFG1) Color space is RGB.  */
#define   LCDC_HEOCFG1_YCCEN_1_Val            _UINT32_(0x1)                                        /* (LCDC_HEOCFG1) Color space is YCbCr.  */
#define LCDC_HEOCFG1_YCCEN_0                  (LCDC_HEOCFG1_YCCEN_0_Val << LCDC_HEOCFG1_YCCEN_Pos) /* (LCDC_HEOCFG1) Color space is RGB. Position  */
#define LCDC_HEOCFG1_YCCEN_1                  (LCDC_HEOCFG1_YCCEN_1_Val << LCDC_HEOCFG1_YCCEN_Pos) /* (LCDC_HEOCFG1) Color space is YCbCr. Position  */
#define LCDC_HEOCFG1_GAM_Pos                  _UINT32_(2)                                          /* (LCDC_HEOCFG1) Gamma Correction Position */
#define LCDC_HEOCFG1_GAM_Msk                  (_UINT32_(0x1) << LCDC_HEOCFG1_GAM_Pos)              /* (LCDC_HEOCFG1) Gamma Correction Mask */
#define LCDC_HEOCFG1_GAM(value)               (LCDC_HEOCFG1_GAM_Msk & (_UINT32_(value) << LCDC_HEOCFG1_GAM_Pos)) /* Assigment of value for GAM in the LCDC_HEOCFG1 register */
#define   LCDC_HEOCFG1_GAM_0_Val              _UINT32_(0x0)                                        /* (LCDC_HEOCFG1) Gamma correction is disabled.  */
#define   LCDC_HEOCFG1_GAM_1_Val              _UINT32_(0x1)                                        /* (LCDC_HEOCFG1) Gamma correction is enabled.  */
#define LCDC_HEOCFG1_GAM_0                    (LCDC_HEOCFG1_GAM_0_Val << LCDC_HEOCFG1_GAM_Pos)     /* (LCDC_HEOCFG1) Gamma correction is disabled. Position  */
#define LCDC_HEOCFG1_GAM_1                    (LCDC_HEOCFG1_GAM_1_Val << LCDC_HEOCFG1_GAM_Pos)     /* (LCDC_HEOCFG1) Gamma correction is enabled. Position  */
#define LCDC_HEOCFG1_RGBMODE_Pos              _UINT32_(4)                                          /* (LCDC_HEOCFG1) RGB Mode Input Selection Position */
#define LCDC_HEOCFG1_RGBMODE_Msk              (_UINT32_(0xF) << LCDC_HEOCFG1_RGBMODE_Pos)          /* (LCDC_HEOCFG1) RGB Mode Input Selection Mask */
#define LCDC_HEOCFG1_RGBMODE(value)           (LCDC_HEOCFG1_RGBMODE_Msk & (_UINT32_(value) << LCDC_HEOCFG1_RGBMODE_Pos)) /* Assigment of value for RGBMODE in the LCDC_HEOCFG1 register */
#define   LCDC_HEOCFG1_RGBMODE_12BPP_RGB_444_Val _UINT32_(0x0)                                        /* (LCDC_HEOCFG1) 12 bpp RGB 444  */
#define   LCDC_HEOCFG1_RGBMODE_16BPP_ARGB_4444_Val _UINT32_(0x1)                                        /* (LCDC_HEOCFG1) 16 bpp ARGB 4444  */
#define   LCDC_HEOCFG1_RGBMODE_16BPP_RGBA_4444_Val _UINT32_(0x2)                                        /* (LCDC_HEOCFG1) 16 bpp RGBA 4444  */
#define   LCDC_HEOCFG1_RGBMODE_16BPP_RGB_565_Val _UINT32_(0x3)                                        /* (LCDC_HEOCFG1) 16 bpp RGB 565  */
#define   LCDC_HEOCFG1_RGBMODE_16BPP_ARGB_1555_Val _UINT32_(0x4)                                        /* (LCDC_HEOCFG1) 16 bpp ARGB 1555  */
#define   LCDC_HEOCFG1_RGBMODE_18BPP_RGB_666_Val _UINT32_(0x5)                                        /* (LCDC_HEOCFG1) 18 bpp RGB 666  */
#define   LCDC_HEOCFG1_RGBMODE_18BPP_RGB_666PACKED_Val _UINT32_(0x6)                                        /* (LCDC_HEOCFG1) 18 bpp RGB 666 PACKED  */
#define   LCDC_HEOCFG1_RGBMODE_19BPP_ARGB_1666_Val _UINT32_(0x7)                                        /* (LCDC_HEOCFG1) 19 bpp ARGB 1666  */
#define   LCDC_HEOCFG1_RGBMODE_19BPP_ARGB_PACKED_Val _UINT32_(0x8)                                        /* (LCDC_HEOCFG1) 19 bpp ARGB 1666 PACKED  */
#define   LCDC_HEOCFG1_RGBMODE_24BPP_RGB_888_Val _UINT32_(0x9)                                        /* (LCDC_HEOCFG1) 24 bpp RGB 888  */
#define   LCDC_HEOCFG1_RGBMODE_24BPP_RGB_888_PACKED_Val _UINT32_(0xA)                                        /* (LCDC_HEOCFG1) 24 bpp RGB 888 PACKED  */
#define   LCDC_HEOCFG1_RGBMODE_25BPP_ARGB_1888_Val _UINT32_(0xB)                                        /* (LCDC_HEOCFG1) 25 bpp ARGB 1888  */
#define   LCDC_HEOCFG1_RGBMODE_32BPP_ARGB_8888_Val _UINT32_(0xC)                                        /* (LCDC_HEOCFG1) 32 bpp ARGB 8888  */
#define   LCDC_HEOCFG1_RGBMODE_32BPP_RGBA_8888_Val _UINT32_(0xD)                                        /* (LCDC_HEOCFG1) 32 bpp RGBA 8888  */
#define LCDC_HEOCFG1_RGBMODE_12BPP_RGB_444    (LCDC_HEOCFG1_RGBMODE_12BPP_RGB_444_Val << LCDC_HEOCFG1_RGBMODE_Pos) /* (LCDC_HEOCFG1) 12 bpp RGB 444 Position  */
#define LCDC_HEOCFG1_RGBMODE_16BPP_ARGB_4444  (LCDC_HEOCFG1_RGBMODE_16BPP_ARGB_4444_Val << LCDC_HEOCFG1_RGBMODE_Pos) /* (LCDC_HEOCFG1) 16 bpp ARGB 4444 Position  */
#define LCDC_HEOCFG1_RGBMODE_16BPP_RGBA_4444  (LCDC_HEOCFG1_RGBMODE_16BPP_RGBA_4444_Val << LCDC_HEOCFG1_RGBMODE_Pos) /* (LCDC_HEOCFG1) 16 bpp RGBA 4444 Position  */
#define LCDC_HEOCFG1_RGBMODE_16BPP_RGB_565    (LCDC_HEOCFG1_RGBMODE_16BPP_RGB_565_Val << LCDC_HEOCFG1_RGBMODE_Pos) /* (LCDC_HEOCFG1) 16 bpp RGB 565 Position  */
#define LCDC_HEOCFG1_RGBMODE_16BPP_ARGB_1555  (LCDC_HEOCFG1_RGBMODE_16BPP_ARGB_1555_Val << LCDC_HEOCFG1_RGBMODE_Pos) /* (LCDC_HEOCFG1) 16 bpp ARGB 1555 Position  */
#define LCDC_HEOCFG1_RGBMODE_18BPP_RGB_666    (LCDC_HEOCFG1_RGBMODE_18BPP_RGB_666_Val << LCDC_HEOCFG1_RGBMODE_Pos) /* (LCDC_HEOCFG1) 18 bpp RGB 666 Position  */
#define LCDC_HEOCFG1_RGBMODE_18BPP_RGB_666PACKED (LCDC_HEOCFG1_RGBMODE_18BPP_RGB_666PACKED_Val << LCDC_HEOCFG1_RGBMODE_Pos) /* (LCDC_HEOCFG1) 18 bpp RGB 666 PACKED Position  */
#define LCDC_HEOCFG1_RGBMODE_19BPP_ARGB_1666  (LCDC_HEOCFG1_RGBMODE_19BPP_ARGB_1666_Val << LCDC_HEOCFG1_RGBMODE_Pos) /* (LCDC_HEOCFG1) 19 bpp ARGB 1666 Position  */
#define LCDC_HEOCFG1_RGBMODE_19BPP_ARGB_PACKED (LCDC_HEOCFG1_RGBMODE_19BPP_ARGB_PACKED_Val << LCDC_HEOCFG1_RGBMODE_Pos) /* (LCDC_HEOCFG1) 19 bpp ARGB 1666 PACKED Position  */
#define LCDC_HEOCFG1_RGBMODE_24BPP_RGB_888    (LCDC_HEOCFG1_RGBMODE_24BPP_RGB_888_Val << LCDC_HEOCFG1_RGBMODE_Pos) /* (LCDC_HEOCFG1) 24 bpp RGB 888 Position  */
#define LCDC_HEOCFG1_RGBMODE_24BPP_RGB_888_PACKED (LCDC_HEOCFG1_RGBMODE_24BPP_RGB_888_PACKED_Val << LCDC_HEOCFG1_RGBMODE_Pos) /* (LCDC_HEOCFG1) 24 bpp RGB 888 PACKED Position  */
#define LCDC_HEOCFG1_RGBMODE_25BPP_ARGB_1888  (LCDC_HEOCFG1_RGBMODE_25BPP_ARGB_1888_Val << LCDC_HEOCFG1_RGBMODE_Pos) /* (LCDC_HEOCFG1) 25 bpp ARGB 1888 Position  */
#define LCDC_HEOCFG1_RGBMODE_32BPP_ARGB_8888  (LCDC_HEOCFG1_RGBMODE_32BPP_ARGB_8888_Val << LCDC_HEOCFG1_RGBMODE_Pos) /* (LCDC_HEOCFG1) 32 bpp ARGB 8888 Position  */
#define LCDC_HEOCFG1_RGBMODE_32BPP_RGBA_8888  (LCDC_HEOCFG1_RGBMODE_32BPP_RGBA_8888_Val << LCDC_HEOCFG1_RGBMODE_Pos) /* (LCDC_HEOCFG1) 32 bpp RGBA 8888 Position  */
#define LCDC_HEOCFG1_CLUTMODE_Pos             _UINT32_(8)                                          /* (LCDC_HEOCFG1) CLUT Mode Input Selection Position */
#define LCDC_HEOCFG1_CLUTMODE_Msk             (_UINT32_(0x3) << LCDC_HEOCFG1_CLUTMODE_Pos)         /* (LCDC_HEOCFG1) CLUT Mode Input Selection Mask */
#define LCDC_HEOCFG1_CLUTMODE(value)          (LCDC_HEOCFG1_CLUTMODE_Msk & (_UINT32_(value) << LCDC_HEOCFG1_CLUTMODE_Pos)) /* Assigment of value for CLUTMODE in the LCDC_HEOCFG1 register */
#define   LCDC_HEOCFG1_CLUTMODE_CLUT_1BPP_Val _UINT32_(0x0)                                        /* (LCDC_HEOCFG1) CLUT mode set to 1 bit per pixel  */
#define   LCDC_HEOCFG1_CLUTMODE_CLUT_2BPP_Val _UINT32_(0x1)                                        /* (LCDC_HEOCFG1) CLUT mode set to 2 bits per pixel  */
#define   LCDC_HEOCFG1_CLUTMODE_CLUT_4BPP_Val _UINT32_(0x2)                                        /* (LCDC_HEOCFG1) CLUT mode set to 4 bits per pixel  */
#define   LCDC_HEOCFG1_CLUTMODE_CLUT_8BPP_Val _UINT32_(0x3)                                        /* (LCDC_HEOCFG1) CLUT mode set to 8 bits per pixel  */
#define LCDC_HEOCFG1_CLUTMODE_CLUT_1BPP       (LCDC_HEOCFG1_CLUTMODE_CLUT_1BPP_Val << LCDC_HEOCFG1_CLUTMODE_Pos) /* (LCDC_HEOCFG1) CLUT mode set to 1 bit per pixel Position  */
#define LCDC_HEOCFG1_CLUTMODE_CLUT_2BPP       (LCDC_HEOCFG1_CLUTMODE_CLUT_2BPP_Val << LCDC_HEOCFG1_CLUTMODE_Pos) /* (LCDC_HEOCFG1) CLUT mode set to 2 bits per pixel Position  */
#define LCDC_HEOCFG1_CLUTMODE_CLUT_4BPP       (LCDC_HEOCFG1_CLUTMODE_CLUT_4BPP_Val << LCDC_HEOCFG1_CLUTMODE_Pos) /* (LCDC_HEOCFG1) CLUT mode set to 4 bits per pixel Position  */
#define LCDC_HEOCFG1_CLUTMODE_CLUT_8BPP       (LCDC_HEOCFG1_CLUTMODE_CLUT_8BPP_Val << LCDC_HEOCFG1_CLUTMODE_Pos) /* (LCDC_HEOCFG1) CLUT mode set to 8 bits per pixel Position  */
#define LCDC_HEOCFG1_YCCMODE_Pos              _UINT32_(12)                                         /* (LCDC_HEOCFG1)  Position */
#define LCDC_HEOCFG1_YCCMODE_Msk              (_UINT32_(0xF) << LCDC_HEOCFG1_YCCMODE_Pos)          /* (LCDC_HEOCFG1)  Mask */
#define LCDC_HEOCFG1_YCCMODE(value)           (LCDC_HEOCFG1_YCCMODE_Msk & (_UINT32_(value) << LCDC_HEOCFG1_YCCMODE_Pos)) /* Assigment of value for YCCMODE in the LCDC_HEOCFG1 register */
#define LCDC_HEOCFG1_YCC422ROT_Pos            _UINT32_(16)                                         /* (LCDC_HEOCFG1)  Position */
#define LCDC_HEOCFG1_YCC422ROT_Msk            (_UINT32_(0x1) << LCDC_HEOCFG1_YCC422ROT_Pos)        /* (LCDC_HEOCFG1)  Mask */
#define LCDC_HEOCFG1_YCC422ROT(value)         (LCDC_HEOCFG1_YCC422ROT_Msk & (_UINT32_(value) << LCDC_HEOCFG1_YCC422ROT_Pos)) /* Assigment of value for YCC422ROT in the LCDC_HEOCFG1 register */
#define LCDC_HEOCFG1_ILD_Pos                  _UINT32_(24)                                         /* (LCDC_HEOCFG1)  Position */
#define LCDC_HEOCFG1_ILD_Msk                  (_UINT32_(0x1) << LCDC_HEOCFG1_ILD_Pos)              /* (LCDC_HEOCFG1)  Mask */
#define LCDC_HEOCFG1_ILD(value)               (LCDC_HEOCFG1_ILD_Msk & (_UINT32_(value) << LCDC_HEOCFG1_ILD_Pos)) /* Assigment of value for ILD in the LCDC_HEOCFG1 register */
#define LCDC_HEOCFG1_Msk                      _UINT32_(0x0101F3F7)                                 /* (LCDC_HEOCFG1) Register Mask  */


/* -------- LCDC_HEOCFG2 : (LCDC Offset: 0x398) (R/W 32) High-End Overlay Configuration Register 2 -------- */
#define LCDC_HEOCFG2_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_HEOCFG2) High-End Overlay Configuration Register 2  Reset Value */

#define LCDC_HEOCFG2_XPOS_Pos                 _UINT32_(0)                                          /* (LCDC_HEOCFG2) Horizontal Window Position Position */
#define LCDC_HEOCFG2_XPOS_Msk                 (_UINT32_(0x7FF) << LCDC_HEOCFG2_XPOS_Pos)           /* (LCDC_HEOCFG2) Horizontal Window Position Mask */
#define LCDC_HEOCFG2_XPOS(value)              (LCDC_HEOCFG2_XPOS_Msk & (_UINT32_(value) << LCDC_HEOCFG2_XPOS_Pos)) /* Assigment of value for XPOS in the LCDC_HEOCFG2 register */
#define LCDC_HEOCFG2_YPOS_Pos                 _UINT32_(16)                                         /* (LCDC_HEOCFG2) Vertical Window Position Position */
#define LCDC_HEOCFG2_YPOS_Msk                 (_UINT32_(0x7FF) << LCDC_HEOCFG2_YPOS_Pos)           /* (LCDC_HEOCFG2) Vertical Window Position Mask */
#define LCDC_HEOCFG2_YPOS(value)              (LCDC_HEOCFG2_YPOS_Msk & (_UINT32_(value) << LCDC_HEOCFG2_YPOS_Pos)) /* Assigment of value for YPOS in the LCDC_HEOCFG2 register */
#define LCDC_HEOCFG2_Msk                      _UINT32_(0x07FF07FF)                                 /* (LCDC_HEOCFG2) Register Mask  */


/* -------- LCDC_HEOCFG3 : (LCDC Offset: 0x39C) (R/W 32) High-End Overlay Configuration Register 3 -------- */
#define LCDC_HEOCFG3_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_HEOCFG3) High-End Overlay Configuration Register 3  Reset Value */

#define LCDC_HEOCFG3_XSIZE_Pos                _UINT32_(0)                                          /* (LCDC_HEOCFG3) Horizontal Window Size Position */
#define LCDC_HEOCFG3_XSIZE_Msk                (_UINT32_(0x7FF) << LCDC_HEOCFG3_XSIZE_Pos)          /* (LCDC_HEOCFG3) Horizontal Window Size Mask */
#define LCDC_HEOCFG3_XSIZE(value)             (LCDC_HEOCFG3_XSIZE_Msk & (_UINT32_(value) << LCDC_HEOCFG3_XSIZE_Pos)) /* Assigment of value for XSIZE in the LCDC_HEOCFG3 register */
#define LCDC_HEOCFG3_YSIZE_Pos                _UINT32_(16)                                         /* (LCDC_HEOCFG3) Vertical Window Size Position */
#define LCDC_HEOCFG3_YSIZE_Msk                (_UINT32_(0x7FF) << LCDC_HEOCFG3_YSIZE_Pos)          /* (LCDC_HEOCFG3) Vertical Window Size Mask */
#define LCDC_HEOCFG3_YSIZE(value)             (LCDC_HEOCFG3_YSIZE_Msk & (_UINT32_(value) << LCDC_HEOCFG3_YSIZE_Pos)) /* Assigment of value for YSIZE in the LCDC_HEOCFG3 register */
#define LCDC_HEOCFG3_Msk                      _UINT32_(0x07FF07FF)                                 /* (LCDC_HEOCFG3) Register Mask  */


/* -------- LCDC_HEOCFG4 : (LCDC Offset: 0x3A0) (R/W 32) High-End Overlay Configuration Register 4 -------- */
#define LCDC_HEOCFG4_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_HEOCFG4) High-End Overlay Configuration Register 4  Reset Value */

#define LCDC_HEOCFG4_XMEMSIZE_Pos             _UINT32_(0)                                          /* (LCDC_HEOCFG4) Horizontal image Size in Memory Position */
#define LCDC_HEOCFG4_XMEMSIZE_Msk             (_UINT32_(0x7FF) << LCDC_HEOCFG4_XMEMSIZE_Pos)       /* (LCDC_HEOCFG4) Horizontal image Size in Memory Mask */
#define LCDC_HEOCFG4_XMEMSIZE(value)          (LCDC_HEOCFG4_XMEMSIZE_Msk & (_UINT32_(value) << LCDC_HEOCFG4_XMEMSIZE_Pos)) /* Assigment of value for XMEMSIZE in the LCDC_HEOCFG4 register */
#define LCDC_HEOCFG4_YMEMSIZE_Pos             _UINT32_(16)                                         /* (LCDC_HEOCFG4) Vertical image Size in Memory Position */
#define LCDC_HEOCFG4_YMEMSIZE_Msk             (_UINT32_(0x7FF) << LCDC_HEOCFG4_YMEMSIZE_Pos)       /* (LCDC_HEOCFG4) Vertical image Size in Memory Mask */
#define LCDC_HEOCFG4_YMEMSIZE(value)          (LCDC_HEOCFG4_YMEMSIZE_Msk & (_UINT32_(value) << LCDC_HEOCFG4_YMEMSIZE_Pos)) /* Assigment of value for YMEMSIZE in the LCDC_HEOCFG4 register */
#define LCDC_HEOCFG4_Msk                      _UINT32_(0x07FF07FF)                                 /* (LCDC_HEOCFG4) Register Mask  */


/* -------- LCDC_HEOCFG5 : (LCDC Offset: 0x3A4) (R/W 32) High-End Overlay Configuration Register 5 -------- */
#define LCDC_HEOCFG5_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_HEOCFG5) High-End Overlay Configuration Register 5  Reset Value */

#define LCDC_HEOCFG5_XSTRIDE_Pos              _UINT32_(0)                                          /* (LCDC_HEOCFG5) Horizontal Stride Position */
#define LCDC_HEOCFG5_XSTRIDE_Msk              (_UINT32_(0xFFFFFFFF) << LCDC_HEOCFG5_XSTRIDE_Pos)   /* (LCDC_HEOCFG5) Horizontal Stride Mask */
#define LCDC_HEOCFG5_XSTRIDE(value)           (LCDC_HEOCFG5_XSTRIDE_Msk & (_UINT32_(value) << LCDC_HEOCFG5_XSTRIDE_Pos)) /* Assigment of value for XSTRIDE in the LCDC_HEOCFG5 register */
#define LCDC_HEOCFG5_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (LCDC_HEOCFG5) Register Mask  */


/* -------- LCDC_HEOCFG6 : (LCDC Offset: 0x3A8) (R/W 32) High-End Overlay Configuration Register 6 -------- */
#define LCDC_HEOCFG6_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_HEOCFG6) High-End Overlay Configuration Register 6  Reset Value */

#define LCDC_HEOCFG6_PSTRIDE_Pos              _UINT32_(0)                                          /* (LCDC_HEOCFG6) Pixel Stride Position */
#define LCDC_HEOCFG6_PSTRIDE_Msk              (_UINT32_(0xFFFFFFFF) << LCDC_HEOCFG6_PSTRIDE_Pos)   /* (LCDC_HEOCFG6) Pixel Stride Mask */
#define LCDC_HEOCFG6_PSTRIDE(value)           (LCDC_HEOCFG6_PSTRIDE_Msk & (_UINT32_(value) << LCDC_HEOCFG6_PSTRIDE_Pos)) /* Assigment of value for PSTRIDE in the LCDC_HEOCFG6 register */
#define LCDC_HEOCFG6_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (LCDC_HEOCFG6) Register Mask  */


/* -------- LCDC_HEOCFG7 : (LCDC Offset: 0x3AC) (R/W 32) High-End Overlay Configuration Register 7 -------- */
#define LCDC_HEOCFG7_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_HEOCFG7) High-End Overlay Configuration Register 7  Reset Value */

#define LCDC_HEOCFG7_CCXSTRIDE_Pos            _UINT32_(0)                                          /* (LCDC_HEOCFG7) CbCr Horizontal Stride Position */
#define LCDC_HEOCFG7_CCXSTRIDE_Msk            (_UINT32_(0xFFFFFFFF) << LCDC_HEOCFG7_CCXSTRIDE_Pos) /* (LCDC_HEOCFG7) CbCr Horizontal Stride Mask */
#define LCDC_HEOCFG7_CCXSTRIDE(value)         (LCDC_HEOCFG7_CCXSTRIDE_Msk & (_UINT32_(value) << LCDC_HEOCFG7_CCXSTRIDE_Pos)) /* Assigment of value for CCXSTRIDE in the LCDC_HEOCFG7 register */
#define LCDC_HEOCFG7_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (LCDC_HEOCFG7) Register Mask  */


/* -------- LCDC_HEOCFG8 : (LCDC Offset: 0x3B0) (R/W 32) High-End Overlay Configuration Register 8 -------- */
#define LCDC_HEOCFG8_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_HEOCFG8) High-End Overlay Configuration Register 8  Reset Value */

#define LCDC_HEOCFG8_CCPSTRIDE_Pos            _UINT32_(0)                                          /* (LCDC_HEOCFG8) CbCr Pixel Stride Position */
#define LCDC_HEOCFG8_CCPSTRIDE_Msk            (_UINT32_(0xFFFFFFFF) << LCDC_HEOCFG8_CCPSTRIDE_Pos) /* (LCDC_HEOCFG8) CbCr Pixel Stride Mask */
#define LCDC_HEOCFG8_CCPSTRIDE(value)         (LCDC_HEOCFG8_CCPSTRIDE_Msk & (_UINT32_(value) << LCDC_HEOCFG8_CCPSTRIDE_Pos)) /* Assigment of value for CCPSTRIDE in the LCDC_HEOCFG8 register */
#define LCDC_HEOCFG8_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (LCDC_HEOCFG8) Register Mask  */


/* -------- LCDC_HEOCFG9 : (LCDC Offset: 0x3B4) (R/W 32) High-End Overlay Configuration Register 9 -------- */
#define LCDC_HEOCFG9_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_HEOCFG9) High-End Overlay Configuration Register 9  Reset Value */

#define LCDC_HEOCFG9_BDEF_Pos                 _UINT32_(0)                                          /* (LCDC_HEOCFG9) Blue Default Position */
#define LCDC_HEOCFG9_BDEF_Msk                 (_UINT32_(0xFF) << LCDC_HEOCFG9_BDEF_Pos)            /* (LCDC_HEOCFG9) Blue Default Mask */
#define LCDC_HEOCFG9_BDEF(value)              (LCDC_HEOCFG9_BDEF_Msk & (_UINT32_(value) << LCDC_HEOCFG9_BDEF_Pos)) /* Assigment of value for BDEF in the LCDC_HEOCFG9 register */
#define LCDC_HEOCFG9_GDEF_Pos                 _UINT32_(8)                                          /* (LCDC_HEOCFG9) Green Default Position */
#define LCDC_HEOCFG9_GDEF_Msk                 (_UINT32_(0xFF) << LCDC_HEOCFG9_GDEF_Pos)            /* (LCDC_HEOCFG9) Green Default Mask */
#define LCDC_HEOCFG9_GDEF(value)              (LCDC_HEOCFG9_GDEF_Msk & (_UINT32_(value) << LCDC_HEOCFG9_GDEF_Pos)) /* Assigment of value for GDEF in the LCDC_HEOCFG9 register */
#define LCDC_HEOCFG9_RDEF_Pos                 _UINT32_(16)                                         /* (LCDC_HEOCFG9) Red Default Position */
#define LCDC_HEOCFG9_RDEF_Msk                 (_UINT32_(0xFF) << LCDC_HEOCFG9_RDEF_Pos)            /* (LCDC_HEOCFG9) Red Default Mask */
#define LCDC_HEOCFG9_RDEF(value)              (LCDC_HEOCFG9_RDEF_Msk & (_UINT32_(value) << LCDC_HEOCFG9_RDEF_Pos)) /* Assigment of value for RDEF in the LCDC_HEOCFG9 register */
#define LCDC_HEOCFG9_Msk                      _UINT32_(0x00FFFFFF)                                 /* (LCDC_HEOCFG9) Register Mask  */


/* -------- LCDC_HEOCFG10 : (LCDC Offset: 0x3B8) (R/W 32) High-End Overlay Configuration Register 10 -------- */
#define LCDC_HEOCFG10_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_HEOCFG10) High-End Overlay Configuration Register 10  Reset Value */

#define LCDC_HEOCFG10_BKEY_Pos                _UINT32_(0)                                          /* (LCDC_HEOCFG10) Blue Color Component Chroma Key Position */
#define LCDC_HEOCFG10_BKEY_Msk                (_UINT32_(0xFF) << LCDC_HEOCFG10_BKEY_Pos)           /* (LCDC_HEOCFG10) Blue Color Component Chroma Key Mask */
#define LCDC_HEOCFG10_BKEY(value)             (LCDC_HEOCFG10_BKEY_Msk & (_UINT32_(value) << LCDC_HEOCFG10_BKEY_Pos)) /* Assigment of value for BKEY in the LCDC_HEOCFG10 register */
#define LCDC_HEOCFG10_GKEY_Pos                _UINT32_(8)                                          /* (LCDC_HEOCFG10) Green Color Component Chroma Key Position */
#define LCDC_HEOCFG10_GKEY_Msk                (_UINT32_(0xFF) << LCDC_HEOCFG10_GKEY_Pos)           /* (LCDC_HEOCFG10) Green Color Component Chroma Key Mask */
#define LCDC_HEOCFG10_GKEY(value)             (LCDC_HEOCFG10_GKEY_Msk & (_UINT32_(value) << LCDC_HEOCFG10_GKEY_Pos)) /* Assigment of value for GKEY in the LCDC_HEOCFG10 register */
#define LCDC_HEOCFG10_RKEY_Pos                _UINT32_(16)                                         /* (LCDC_HEOCFG10) Red Color Component Chroma Key Position */
#define LCDC_HEOCFG10_RKEY_Msk                (_UINT32_(0xFF) << LCDC_HEOCFG10_RKEY_Pos)           /* (LCDC_HEOCFG10) Red Color Component Chroma Key Mask */
#define LCDC_HEOCFG10_RKEY(value)             (LCDC_HEOCFG10_RKEY_Msk & (_UINT32_(value) << LCDC_HEOCFG10_RKEY_Pos)) /* Assigment of value for RKEY in the LCDC_HEOCFG10 register */
#define LCDC_HEOCFG10_Msk                     _UINT32_(0x00FFFFFF)                                 /* (LCDC_HEOCFG10) Register Mask  */


/* -------- LCDC_HEOCFG11 : (LCDC Offset: 0x3BC) (R/W 32) High-End Overlay Configuration Register 11 -------- */
#define LCDC_HEOCFG11_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_HEOCFG11) High-End Overlay Configuration Register 11  Reset Value */

#define LCDC_HEOCFG11_BMASK_Pos               _UINT32_(0)                                          /* (LCDC_HEOCFG11) Blue Color Component Chroma Key Mask Position */
#define LCDC_HEOCFG11_BMASK_Msk               (_UINT32_(0xFF) << LCDC_HEOCFG11_BMASK_Pos)          /* (LCDC_HEOCFG11) Blue Color Component Chroma Key Mask Mask */
#define LCDC_HEOCFG11_BMASK(value)            (LCDC_HEOCFG11_BMASK_Msk & (_UINT32_(value) << LCDC_HEOCFG11_BMASK_Pos)) /* Assigment of value for BMASK in the LCDC_HEOCFG11 register */
#define LCDC_HEOCFG11_GMASK_Pos               _UINT32_(8)                                          /* (LCDC_HEOCFG11) Green Color Component Chroma Key Mask Position */
#define LCDC_HEOCFG11_GMASK_Msk               (_UINT32_(0xFF) << LCDC_HEOCFG11_GMASK_Pos)          /* (LCDC_HEOCFG11) Green Color Component Chroma Key Mask Mask */
#define LCDC_HEOCFG11_GMASK(value)            (LCDC_HEOCFG11_GMASK_Msk & (_UINT32_(value) << LCDC_HEOCFG11_GMASK_Pos)) /* Assigment of value for GMASK in the LCDC_HEOCFG11 register */
#define LCDC_HEOCFG11_RMASK_Pos               _UINT32_(16)                                         /* (LCDC_HEOCFG11) Red Color Component Chroma Key Mask Position */
#define LCDC_HEOCFG11_RMASK_Msk               (_UINT32_(0xFF) << LCDC_HEOCFG11_RMASK_Pos)          /* (LCDC_HEOCFG11) Red Color Component Chroma Key Mask Mask */
#define LCDC_HEOCFG11_RMASK(value)            (LCDC_HEOCFG11_RMASK_Msk & (_UINT32_(value) << LCDC_HEOCFG11_RMASK_Pos)) /* Assigment of value for RMASK in the LCDC_HEOCFG11 register */
#define LCDC_HEOCFG11_Msk                     _UINT32_(0x00FFFFFF)                                 /* (LCDC_HEOCFG11) Register Mask  */


/* -------- LCDC_HEOCFG12 : (LCDC Offset: 0x3C0) (R/W 32) High-End Overlay Configuration Register 12 -------- */
#define LCDC_HEOCFG12_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_HEOCFG12) High-End Overlay Configuration Register 12  Reset Value */

#define LCDC_HEOCFG12_DMA_Pos                 _UINT32_(0)                                          /* (LCDC_HEOCFG12) DMA Enable Position */
#define LCDC_HEOCFG12_DMA_Msk                 (_UINT32_(0x1) << LCDC_HEOCFG12_DMA_Pos)             /* (LCDC_HEOCFG12) DMA Enable Mask */
#define LCDC_HEOCFG12_DMA(value)              (LCDC_HEOCFG12_DMA_Msk & (_UINT32_(value) << LCDC_HEOCFG12_DMA_Pos)) /* Assigment of value for DMA in the LCDC_HEOCFG12 register */
#define   LCDC_HEOCFG12_DMA_0_Val             _UINT32_(0x0)                                        /* (LCDC_HEOCFG12) The pixel for the current layer is retrieved from the default color register.  */
#define   LCDC_HEOCFG12_DMA_1_Val             _UINT32_(0x1)                                        /* (LCDC_HEOCFG12) The pixel stream is retrieved from the memory.  */
#define LCDC_HEOCFG12_DMA_0                   (LCDC_HEOCFG12_DMA_0_Val << LCDC_HEOCFG12_DMA_Pos)   /* (LCDC_HEOCFG12) The pixel for the current layer is retrieved from the default color register. Position  */
#define LCDC_HEOCFG12_DMA_1                   (LCDC_HEOCFG12_DMA_1_Val << LCDC_HEOCFG12_DMA_Pos)   /* (LCDC_HEOCFG12) The pixel stream is retrieved from the memory. Position  */
#define LCDC_HEOCFG12_REP_Pos                 _UINT32_(1)                                          /* (LCDC_HEOCFG12) Replication Logic Position */
#define LCDC_HEOCFG12_REP_Msk                 (_UINT32_(0x1) << LCDC_HEOCFG12_REP_Pos)             /* (LCDC_HEOCFG12) Replication Logic Mask */
#define LCDC_HEOCFG12_REP(value)              (LCDC_HEOCFG12_REP_Msk & (_UINT32_(value) << LCDC_HEOCFG12_REP_Pos)) /* Assigment of value for REP in the LCDC_HEOCFG12 register */
#define   LCDC_HEOCFG12_REP_0_Val             _UINT32_(0x0)                                        /* (LCDC_HEOCFG12) When the selected pixel depth is less than 24 bpp, the pixel is shifted and LSBs are set to 0.  */
#define   LCDC_HEOCFG12_REP_1_Val             _UINT32_(0x1)                                        /* (LCDC_HEOCFG12) When the selected pixel depth is less than 24 bpp, the pixel is shifted and the LSB replicates the MSB.  */
#define LCDC_HEOCFG12_REP_0                   (LCDC_HEOCFG12_REP_0_Val << LCDC_HEOCFG12_REP_Pos)   /* (LCDC_HEOCFG12) When the selected pixel depth is less than 24 bpp, the pixel is shifted and LSBs are set to 0. Position  */
#define LCDC_HEOCFG12_REP_1                   (LCDC_HEOCFG12_REP_1_Val << LCDC_HEOCFG12_REP_Pos)   /* (LCDC_HEOCFG12) When the selected pixel depth is less than 24 bpp, the pixel is shifted and the LSB replicates the MSB. Position  */
#define LCDC_HEOCFG12_CRKEY_Pos               _UINT32_(2)                                          /* (LCDC_HEOCFG12) Chroma Keying Position */
#define LCDC_HEOCFG12_CRKEY_Msk               (_UINT32_(0x1) << LCDC_HEOCFG12_CRKEY_Pos)           /* (LCDC_HEOCFG12) Chroma Keying Mask */
#define LCDC_HEOCFG12_CRKEY(value)            (LCDC_HEOCFG12_CRKEY_Msk & (_UINT32_(value) << LCDC_HEOCFG12_CRKEY_Pos)) /* Assigment of value for CRKEY in the LCDC_HEOCFG12 register */
#define LCDC_HEOCFG12_DSTKEY_Pos              _UINT32_(3)                                          /* (LCDC_HEOCFG12) Destination Color Keying Position */
#define LCDC_HEOCFG12_DSTKEY_Msk              (_UINT32_(0x1) << LCDC_HEOCFG12_DSTKEY_Pos)          /* (LCDC_HEOCFG12) Destination Color Keying Mask */
#define LCDC_HEOCFG12_DSTKEY(value)           (LCDC_HEOCFG12_DSTKEY_Msk & (_UINT32_(value) << LCDC_HEOCFG12_DSTKEY_Pos)) /* Assigment of value for DSTKEY in the LCDC_HEOCFG12 register */
#define   LCDC_HEOCFG12_DSTKEY_0_Val          _UINT32_(0x0)                                        /* (LCDC_HEOCFG12) When CRKEY is enabled, color key is applied on HEO pixels, before blending operation.  */
#define   LCDC_HEOCFG12_DSTKEY_1_Val          _UINT32_(0x1)                                        /* (LCDC_HEOCFG12) When CRKEY is enabled, color key is applied on HEO pixels, after blending operation.  */
#define LCDC_HEOCFG12_DSTKEY_0                (LCDC_HEOCFG12_DSTKEY_0_Val << LCDC_HEOCFG12_DSTKEY_Pos) /* (LCDC_HEOCFG12) When CRKEY is enabled, color key is applied on HEO pixels, before blending operation. Position  */
#define LCDC_HEOCFG12_DSTKEY_1                (LCDC_HEOCFG12_DSTKEY_1_Val << LCDC_HEOCFG12_DSTKEY_Pos) /* (LCDC_HEOCFG12) When CRKEY is enabled, color key is applied on HEO pixels, after blending operation. Position  */
#define LCDC_HEOCFG12_VIDPRI_Pos              _UINT32_(5)                                          /* (LCDC_HEOCFG12) Video Priority Mode Position */
#define LCDC_HEOCFG12_VIDPRI_Msk              (_UINT32_(0x1) << LCDC_HEOCFG12_VIDPRI_Pos)          /* (LCDC_HEOCFG12) Video Priority Mode Mask */
#define LCDC_HEOCFG12_VIDPRI(value)           (LCDC_HEOCFG12_VIDPRI_Msk & (_UINT32_(value) << LCDC_HEOCFG12_VIDPRI_Pos)) /* Assigment of value for VIDPRI in the LCDC_HEOCFG12 register */
#define   LCDC_HEOCFG12_VIDPRI_0_Val          _UINT32_(0x0)                                        /* (LCDC_HEOCFG12) HEO is located below OVR1.  */
#define   LCDC_HEOCFG12_VIDPRI_1_Val          _UINT32_(0x1)                                        /* (LCDC_HEOCFG12) HEO is located above OVR1.  */
#define LCDC_HEOCFG12_VIDPRI_0                (LCDC_HEOCFG12_VIDPRI_0_Val << LCDC_HEOCFG12_VIDPRI_Pos) /* (LCDC_HEOCFG12) HEO is located below OVR1. Position  */
#define LCDC_HEOCFG12_VIDPRI_1                (LCDC_HEOCFG12_VIDPRI_1_Val << LCDC_HEOCFG12_VIDPRI_Pos) /* (LCDC_HEOCFG12) HEO is located above OVR1. Position  */
#define LCDC_HEOCFG12_SFACTC_Pos              _UINT32_(8)                                          /* (LCDC_HEOCFG12) Source Factor for the Blending Equation of the Color Component Position */
#define LCDC_HEOCFG12_SFACTC_Msk              (_UINT32_(0x1) << LCDC_HEOCFG12_SFACTC_Pos)          /* (LCDC_HEOCFG12) Source Factor for the Blending Equation of the Color Component Mask */
#define LCDC_HEOCFG12_SFACTC(value)           (LCDC_HEOCFG12_SFACTC_Msk & (_UINT32_(value) << LCDC_HEOCFG12_SFACTC_Pos)) /* Assigment of value for SFACTC in the LCDC_HEOCFG12 register */
#define   LCDC_HEOCFG12_SFACTC_ONE_Val        _UINT32_(0x0)                                        /* (LCDC_HEOCFG12) Sets the factor to 1.0.  */
#define   LCDC_HEOCFG12_SFACTC_ZERO_Val       _UINT32_(0x1)                                        /* (LCDC_HEOCFG12) Sets the factor to 0.0.  */
#define   LCDC_HEOCFG12_SFACTC_A0_Val         _UINT32_(0x2)                                        /* (LCDC_HEOCFG12) Sets the factor to A0/255.  */
#define   LCDC_HEOCFG12_SFACTC_A0_MULT_AD_Val _UINT32_(0x3)                                        /* (LCDC_HEOCFG12) Sets the factor to A0 multiplied by Destination Alpha.  */
#define   LCDC_HEOCFG12_SFACTC_A0_MUL_AS_Val  _UINT32_(0x4)                                        /* (LCDC_HEOCFG12) Sets the factor to A0 multiplied by Source Alpha.  */
#define   LCDC_HEOCFG12_SFACTC_M_A0_MUL_AD_Val _UINT32_(0x5)                                        /* (LCDC_HEOCFG12) Computes A0 multiplied by Destination Alpha, then sets the factor to minus the result.  */
#define LCDC_HEOCFG12_SFACTC_ONE              (LCDC_HEOCFG12_SFACTC_ONE_Val << LCDC_HEOCFG12_SFACTC_Pos) /* (LCDC_HEOCFG12) Sets the factor to 1.0. Position  */
#define LCDC_HEOCFG12_SFACTC_ZERO             (LCDC_HEOCFG12_SFACTC_ZERO_Val << LCDC_HEOCFG12_SFACTC_Pos) /* (LCDC_HEOCFG12) Sets the factor to 0.0. Position  */
#define LCDC_HEOCFG12_SFACTC_A0               (LCDC_HEOCFG12_SFACTC_A0_Val << LCDC_HEOCFG12_SFACTC_Pos) /* (LCDC_HEOCFG12) Sets the factor to A0/255. Position  */
#define LCDC_HEOCFG12_SFACTC_A0_MULT_AD       (LCDC_HEOCFG12_SFACTC_A0_MULT_AD_Val << LCDC_HEOCFG12_SFACTC_Pos) /* (LCDC_HEOCFG12) Sets the factor to A0 multiplied by Destination Alpha. Position  */
#define LCDC_HEOCFG12_SFACTC_A0_MUL_AS        (LCDC_HEOCFG12_SFACTC_A0_MUL_AS_Val << LCDC_HEOCFG12_SFACTC_Pos) /* (LCDC_HEOCFG12) Sets the factor to A0 multiplied by Source Alpha. Position  */
#define LCDC_HEOCFG12_SFACTC_M_A0_MUL_AD      (LCDC_HEOCFG12_SFACTC_M_A0_MUL_AD_Val << LCDC_HEOCFG12_SFACTC_Pos) /* (LCDC_HEOCFG12) Computes A0 multiplied by Destination Alpha, then sets the factor to minus the result. Position  */
#define LCDC_HEOCFG12_SFACTA_Pos              _UINT32_(9)                                          /* (LCDC_HEOCFG12)  Position */
#define LCDC_HEOCFG12_SFACTA_Msk              (_UINT32_(0x3) << LCDC_HEOCFG12_SFACTA_Pos)          /* (LCDC_HEOCFG12)  Mask */
#define LCDC_HEOCFG12_SFACTA(value)           (LCDC_HEOCFG12_SFACTA_Msk & (_UINT32_(value) << LCDC_HEOCFG12_SFACTA_Pos)) /* Assigment of value for SFACTA in the LCDC_HEOCFG12 register */
#define LCDC_HEOCFG12_DFACTC_Pos              _UINT32_(11)                                         /* (LCDC_HEOCFG12) Destination Factor for the Blending Equation of the Color Component Position */
#define LCDC_HEOCFG12_DFACTC_Msk              (_UINT32_(0x7) << LCDC_HEOCFG12_DFACTC_Pos)          /* (LCDC_HEOCFG12) Destination Factor for the Blending Equation of the Color Component Mask */
#define LCDC_HEOCFG12_DFACTC(value)           (LCDC_HEOCFG12_DFACTC_Msk & (_UINT32_(value) << LCDC_HEOCFG12_DFACTC_Pos)) /* Assigment of value for DFACTC in the LCDC_HEOCFG12 register */
#define   LCDC_HEOCFG12_DFACTC_ZERO_Val       _UINT32_(0x0)                                        /* (LCDC_HEOCFG12) Sets the factor to 0.0.  */
#define   LCDC_HEOCFG12_DFACTC_ONE_Val        _UINT32_(0x1)                                        /* (LCDC_HEOCFG12) Sets the factor to 1.0.  */
#define   LCDC_HEOCFG12_DFACTC_A0_Val         _UINT32_(0x2)                                        /* (LCDC_HEOCFG12) Sets the factor to A0/255.  */
#define   LCDC_HEOCFG12_DFACTC_A1_Val         _UINT32_(0x3)                                        /* (LCDC_HEOCFG12) Sets the factor to A1/255.  */
#define   LCDC_HEOCFG12_DFACTC_A0_MULT_AD_Val _UINT32_(0x4)                                        /* (LCDC_HEOCFG12) Sets the factor to A0 multiplied by Destination Alpha.  */
#define   LCDC_HEOCFG12_DFACTC_M_A0_MULT_AD_Val _UINT32_(0x5)                                        /* (LCDC_HEOCFG12) Sets the factor to A0 multiplied by Destination Alpha, then sets the factor one minus the result.  */
#define   LCDC_HEOCFG12_DFACTC_M_A0_MUL_AS_Val _UINT32_(0x6)                                        /* (LCDC_HEOCFG12) Computes A0 multiplied by source alpha0, then set the factor to one minus the result.  */
#define   LCDC_HEOCFG12_DFACTC_M_A0_Val       _UINT32_(0x7)                                        /* (LCDC_HEOCFG12) Computes one minus A0, then set the factor to one minus the result.  */
#define LCDC_HEOCFG12_DFACTC_ZERO             (LCDC_HEOCFG12_DFACTC_ZERO_Val << LCDC_HEOCFG12_DFACTC_Pos) /* (LCDC_HEOCFG12) Sets the factor to 0.0. Position  */
#define LCDC_HEOCFG12_DFACTC_ONE              (LCDC_HEOCFG12_DFACTC_ONE_Val << LCDC_HEOCFG12_DFACTC_Pos) /* (LCDC_HEOCFG12) Sets the factor to 1.0. Position  */
#define LCDC_HEOCFG12_DFACTC_A0               (LCDC_HEOCFG12_DFACTC_A0_Val << LCDC_HEOCFG12_DFACTC_Pos) /* (LCDC_HEOCFG12) Sets the factor to A0/255. Position  */
#define LCDC_HEOCFG12_DFACTC_A1               (LCDC_HEOCFG12_DFACTC_A1_Val << LCDC_HEOCFG12_DFACTC_Pos) /* (LCDC_HEOCFG12) Sets the factor to A1/255. Position  */
#define LCDC_HEOCFG12_DFACTC_A0_MULT_AD       (LCDC_HEOCFG12_DFACTC_A0_MULT_AD_Val << LCDC_HEOCFG12_DFACTC_Pos) /* (LCDC_HEOCFG12) Sets the factor to A0 multiplied by Destination Alpha. Position  */
#define LCDC_HEOCFG12_DFACTC_M_A0_MULT_AD     (LCDC_HEOCFG12_DFACTC_M_A0_MULT_AD_Val << LCDC_HEOCFG12_DFACTC_Pos) /* (LCDC_HEOCFG12) Sets the factor to A0 multiplied by Destination Alpha, then sets the factor one minus the result. Position  */
#define LCDC_HEOCFG12_DFACTC_M_A0_MUL_AS      (LCDC_HEOCFG12_DFACTC_M_A0_MUL_AS_Val << LCDC_HEOCFG12_DFACTC_Pos) /* (LCDC_HEOCFG12) Computes A0 multiplied by source alpha0, then set the factor to one minus the result. Position  */
#define LCDC_HEOCFG12_DFACTC_M_A0             (LCDC_HEOCFG12_DFACTC_M_A0_Val << LCDC_HEOCFG12_DFACTC_Pos) /* (LCDC_HEOCFG12) Computes one minus A0, then set the factor to one minus the result. Position  */
#define LCDC_HEOCFG12_DFACTA_Pos              _UINT32_(14)                                         /* (LCDC_HEOCFG12)  Position */
#define LCDC_HEOCFG12_DFACTA_Msk              (_UINT32_(0x3) << LCDC_HEOCFG12_DFACTA_Pos)          /* (LCDC_HEOCFG12)  Mask */
#define LCDC_HEOCFG12_DFACTA(value)           (LCDC_HEOCFG12_DFACTA_Msk & (_UINT32_(value) << LCDC_HEOCFG12_DFACTA_Pos)) /* Assigment of value for DFACTA in the LCDC_HEOCFG12 register */
#define LCDC_HEOCFG12_A0_Pos                  _UINT32_(16)                                         /* (LCDC_HEOCFG12) Alpha 0 Value Position */
#define LCDC_HEOCFG12_A0_Msk                  (_UINT32_(0xFF) << LCDC_HEOCFG12_A0_Pos)             /* (LCDC_HEOCFG12) Alpha 0 Value Mask */
#define LCDC_HEOCFG12_A0(value)               (LCDC_HEOCFG12_A0_Msk & (_UINT32_(value) << LCDC_HEOCFG12_A0_Pos)) /* Assigment of value for A0 in the LCDC_HEOCFG12 register */
#define LCDC_HEOCFG12_A1_Pos                  _UINT32_(24)                                         /* (LCDC_HEOCFG12) Alpha 1 Value Position */
#define LCDC_HEOCFG12_A1_Msk                  (_UINT32_(0xFF) << LCDC_HEOCFG12_A1_Pos)             /* (LCDC_HEOCFG12) Alpha 1 Value Mask */
#define LCDC_HEOCFG12_A1(value)               (LCDC_HEOCFG12_A1_Msk & (_UINT32_(value) << LCDC_HEOCFG12_A1_Pos)) /* Assigment of value for A1 in the LCDC_HEOCFG12 register */
#define LCDC_HEOCFG12_Msk                     _UINT32_(0xFFFFFF2F)                                 /* (LCDC_HEOCFG12) Register Mask  */


/* -------- LCDC_HEOCFG13 : (LCDC Offset: 0x3C4) (R/W 32) High-End Overlay Configuration Register 13 -------- */
#define LCDC_HEOCFG13_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_HEOCFG13) High-End Overlay Configuration Register 13  Reset Value */

#define LCDC_HEOCFG13_ENABLE_Pos              _UINT32_(0)                                          /* (LCDC_HEOCFG13) Contrast, Brightness Hue and Saturation Enable Position */
#define LCDC_HEOCFG13_ENABLE_Msk              (_UINT32_(0x1) << LCDC_HEOCFG13_ENABLE_Pos)          /* (LCDC_HEOCFG13) Contrast, Brightness Hue and Saturation Enable Mask */
#define LCDC_HEOCFG13_ENABLE(value)           (LCDC_HEOCFG13_ENABLE_Msk & (_UINT32_(value) << LCDC_HEOCFG13_ENABLE_Pos)) /* Assigment of value for ENABLE in the LCDC_HEOCFG13 register */
#define   LCDC_HEOCFG13_ENABLE_0_Val          _UINT32_(0x0)                                        /* (LCDC_HEOCFG13) CBHS is disabled.  */
#define   LCDC_HEOCFG13_ENABLE_1_Val          _UINT32_(0x1)                                        /* (LCDC_HEOCFG13) CBHS is enabled.  */
#define LCDC_HEOCFG13_ENABLE_0                (LCDC_HEOCFG13_ENABLE_0_Val << LCDC_HEOCFG13_ENABLE_Pos) /* (LCDC_HEOCFG13) CBHS is disabled. Position  */
#define LCDC_HEOCFG13_ENABLE_1                (LCDC_HEOCFG13_ENABLE_1_Val << LCDC_HEOCFG13_ENABLE_Pos) /* (LCDC_HEOCFG13) CBHS is enabled. Position  */
#define LCDC_HEOCFG13_BL_Pos                  _UINT32_(4)                                          /* (LCDC_HEOCFG13) Black Level Position */
#define LCDC_HEOCFG13_BL_Msk                  (_UINT32_(0x1) << LCDC_HEOCFG13_BL_Pos)              /* (LCDC_HEOCFG13) Black Level Mask */
#define LCDC_HEOCFG13_BL(value)               (LCDC_HEOCFG13_BL_Msk & (_UINT32_(value) << LCDC_HEOCFG13_BL_Pos)) /* Assigment of value for BL in the LCDC_HEOCFG13 register */
#define   LCDC_HEOCFG13_BL_0_Val              _UINT32_(0x0)                                        /* (LCDC_HEOCFG13) Black level offset is disabled.  */
#define   LCDC_HEOCFG13_BL_1_Val              _UINT32_(0x1)                                        /* (LCDC_HEOCFG13) Black level offset is enabled.  */
#define LCDC_HEOCFG13_BL_0                    (LCDC_HEOCFG13_BL_0_Val << LCDC_HEOCFG13_BL_Pos)     /* (LCDC_HEOCFG13) Black level offset is disabled. Position  */
#define LCDC_HEOCFG13_BL_1                    (LCDC_HEOCFG13_BL_1_Val << LCDC_HEOCFG13_BL_Pos)     /* (LCDC_HEOCFG13) Black level offset is enabled. Position  */
#define LCDC_HEOCFG13_Msk                     _UINT32_(0x00000011)                                 /* (LCDC_HEOCFG13) Register Mask  */


/* -------- LCDC_HEOCFG14 : (LCDC Offset: 0x3C8) (R/W 32) High-End Overlay Configuration Register 14 -------- */
#define LCDC_HEOCFG14_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_HEOCFG14) High-End Overlay Configuration Register 14  Reset Value */

#define LCDC_HEOCFG14_BRIGHT_Pos              _UINT32_(0)                                          /* (LCDC_HEOCFG14) Brightness Value Position */
#define LCDC_HEOCFG14_BRIGHT_Msk              (_UINT32_(0x7FF) << LCDC_HEOCFG14_BRIGHT_Pos)        /* (LCDC_HEOCFG14) Brightness Value Mask */
#define LCDC_HEOCFG14_BRIGHT(value)           (LCDC_HEOCFG14_BRIGHT_Msk & (_UINT32_(value) << LCDC_HEOCFG14_BRIGHT_Pos)) /* Assigment of value for BRIGHT in the LCDC_HEOCFG14 register */
#define LCDC_HEOCFG14_CONT_Pos                _UINT32_(16)                                         /* (LCDC_HEOCFG14) Contrast Value Position */
#define LCDC_HEOCFG14_CONT_Msk                (_UINT32_(0xFFF) << LCDC_HEOCFG14_CONT_Pos)          /* (LCDC_HEOCFG14) Contrast Value Mask */
#define LCDC_HEOCFG14_CONT(value)             (LCDC_HEOCFG14_CONT_Msk & (_UINT32_(value) << LCDC_HEOCFG14_CONT_Pos)) /* Assigment of value for CONT in the LCDC_HEOCFG14 register */
#define LCDC_HEOCFG14_Msk                     _UINT32_(0x0FFF07FF)                                 /* (LCDC_HEOCFG14) Register Mask  */


/* -------- LCDC_HEOCFG15 : (LCDC Offset: 0x3CC) (R/W 32) High-End Overlay Configuration Register 15 -------- */
#define LCDC_HEOCFG15_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_HEOCFG15) High-End Overlay Configuration Register 15  Reset Value */

#define LCDC_HEOCFG15_HUE_Pos                 _UINT32_(0)                                          /* (LCDC_HEOCFG15) Hue Value in Degrees Position */
#define LCDC_HEOCFG15_HUE_Msk                 (_UINT32_(0x1FF) << LCDC_HEOCFG15_HUE_Pos)           /* (LCDC_HEOCFG15) Hue Value in Degrees Mask */
#define LCDC_HEOCFG15_HUE(value)              (LCDC_HEOCFG15_HUE_Msk & (_UINT32_(value) << LCDC_HEOCFG15_HUE_Pos)) /* Assigment of value for HUE in the LCDC_HEOCFG15 register */
#define LCDC_HEOCFG15_SAT_Pos                 _UINT32_(16)                                         /* (LCDC_HEOCFG15) Saturation Value Position */
#define LCDC_HEOCFG15_SAT_Msk                 (_UINT32_(0xFFF) << LCDC_HEOCFG15_SAT_Pos)           /* (LCDC_HEOCFG15) Saturation Value Mask */
#define LCDC_HEOCFG15_SAT(value)              (LCDC_HEOCFG15_SAT_Msk & (_UINT32_(value) << LCDC_HEOCFG15_SAT_Pos)) /* Assigment of value for SAT in the LCDC_HEOCFG15 register */
#define LCDC_HEOCFG15_Msk                     _UINT32_(0x0FFF01FF)                                 /* (LCDC_HEOCFG15) Register Mask  */


/* -------- LCDC_HEOCFG16 : (LCDC Offset: 0x3D0) (R/W 32) High-End Overlay Configuration Register 16 -------- */
#define LCDC_HEOCFG16_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_HEOCFG16) High-End Overlay Configuration Register 16  Reset Value */

#define LCDC_HEOCFG16_RYGAIN_Pos              _UINT32_(0)                                          /* (LCDC_HEOCFG16) Color Space Conversion Y Coefficient for Red Component 1:2:10 Format Position */
#define LCDC_HEOCFG16_RYGAIN_Msk              (_UINT32_(0x1FFF) << LCDC_HEOCFG16_RYGAIN_Pos)       /* (LCDC_HEOCFG16) Color Space Conversion Y Coefficient for Red Component 1:2:10 Format Mask */
#define LCDC_HEOCFG16_RYGAIN(value)           (LCDC_HEOCFG16_RYGAIN_Msk & (_UINT32_(value) << LCDC_HEOCFG16_RYGAIN_Pos)) /* Assigment of value for RYGAIN in the LCDC_HEOCFG16 register */
#define LCDC_HEOCFG16_RCBGAIN_Pos             _UINT32_(16)                                         /* (LCDC_HEOCFG16) Color Space Conversion CB Coefficient for Red Component 1:2:10 Format Position */
#define LCDC_HEOCFG16_RCBGAIN_Msk             (_UINT32_(0x1FFF) << LCDC_HEOCFG16_RCBGAIN_Pos)      /* (LCDC_HEOCFG16) Color Space Conversion CB Coefficient for Red Component 1:2:10 Format Mask */
#define LCDC_HEOCFG16_RCBGAIN(value)          (LCDC_HEOCFG16_RCBGAIN_Msk & (_UINT32_(value) << LCDC_HEOCFG16_RCBGAIN_Pos)) /* Assigment of value for RCBGAIN in the LCDC_HEOCFG16 register */
#define LCDC_HEOCFG16_Msk                     _UINT32_(0x1FFF1FFF)                                 /* (LCDC_HEOCFG16) Register Mask  */


/* -------- LCDC_HEOCFG17 : (LCDC Offset: 0x3D4) (R/W 32) High-End Overlay Configuration Register 17 -------- */
#define LCDC_HEOCFG17_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_HEOCFG17) High-End Overlay Configuration Register 17  Reset Value */

#define LCDC_HEOCFG17_RCRGAIN_Pos             _UINT32_(0)                                          /* (LCDC_HEOCFG17) Color Space Conversion CR Coefficient for Red Component 1:2:10 Format Position */
#define LCDC_HEOCFG17_RCRGAIN_Msk             (_UINT32_(0x1FFF) << LCDC_HEOCFG17_RCRGAIN_Pos)      /* (LCDC_HEOCFG17) Color Space Conversion CR Coefficient for Red Component 1:2:10 Format Mask */
#define LCDC_HEOCFG17_RCRGAIN(value)          (LCDC_HEOCFG17_RCRGAIN_Msk & (_UINT32_(value) << LCDC_HEOCFG17_RCRGAIN_Pos)) /* Assigment of value for RCRGAIN in the LCDC_HEOCFG17 register */
#define LCDC_HEOCFG17_Msk                     _UINT32_(0x00001FFF)                                 /* (LCDC_HEOCFG17) Register Mask  */


/* -------- LCDC_HEOCFG18 : (LCDC Offset: 0x3D8) (R/W 32) High-End Overlay Configuration Register 18 -------- */
#define LCDC_HEOCFG18_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_HEOCFG18) High-End Overlay Configuration Register 18  Reset Value */

#define LCDC_HEOCFG18_GYGAIN_Pos              _UINT32_(0)                                          /* (LCDC_HEOCFG18) Color Space Conversion Y Coefficient for Green Component 1:2:10 Format Position */
#define LCDC_HEOCFG18_GYGAIN_Msk              (_UINT32_(0x1FFF) << LCDC_HEOCFG18_GYGAIN_Pos)       /* (LCDC_HEOCFG18) Color Space Conversion Y Coefficient for Green Component 1:2:10 Format Mask */
#define LCDC_HEOCFG18_GYGAIN(value)           (LCDC_HEOCFG18_GYGAIN_Msk & (_UINT32_(value) << LCDC_HEOCFG18_GYGAIN_Pos)) /* Assigment of value for GYGAIN in the LCDC_HEOCFG18 register */
#define LCDC_HEOCFG18_GCBGAIN_Pos             _UINT32_(16)                                         /* (LCDC_HEOCFG18) Color Space Conversion CB Coefficient for Green Component 1:2:10 Format Position */
#define LCDC_HEOCFG18_GCBGAIN_Msk             (_UINT32_(0x1FFF) << LCDC_HEOCFG18_GCBGAIN_Pos)      /* (LCDC_HEOCFG18) Color Space Conversion CB Coefficient for Green Component 1:2:10 Format Mask */
#define LCDC_HEOCFG18_GCBGAIN(value)          (LCDC_HEOCFG18_GCBGAIN_Msk & (_UINT32_(value) << LCDC_HEOCFG18_GCBGAIN_Pos)) /* Assigment of value for GCBGAIN in the LCDC_HEOCFG18 register */
#define LCDC_HEOCFG18_Msk                     _UINT32_(0x1FFF1FFF)                                 /* (LCDC_HEOCFG18) Register Mask  */


/* -------- LCDC_HEOCFG19 : (LCDC Offset: 0x3DC) (R/W 32) High-End Overlay Configuration Register 19 -------- */
#define LCDC_HEOCFG19_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_HEOCFG19) High-End Overlay Configuration Register 19  Reset Value */

#define LCDC_HEOCFG19_GCRGAIN_Pos             _UINT32_(0)                                          /* (LCDC_HEOCFG19) Color Space Conversion CR Coefficient for Green Component 1:2:10 Format Position */
#define LCDC_HEOCFG19_GCRGAIN_Msk             (_UINT32_(0x1FFF) << LCDC_HEOCFG19_GCRGAIN_Pos)      /* (LCDC_HEOCFG19) Color Space Conversion CR Coefficient for Green Component 1:2:10 Format Mask */
#define LCDC_HEOCFG19_GCRGAIN(value)          (LCDC_HEOCFG19_GCRGAIN_Msk & (_UINT32_(value) << LCDC_HEOCFG19_GCRGAIN_Pos)) /* Assigment of value for GCRGAIN in the LCDC_HEOCFG19 register */
#define LCDC_HEOCFG19_Msk                     _UINT32_(0x00001FFF)                                 /* (LCDC_HEOCFG19) Register Mask  */


/* -------- LCDC_HEOCFG20 : (LCDC Offset: 0x3E0) (R/W 32) High-End Overlay Configuration Register 20 -------- */
#define LCDC_HEOCFG20_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_HEOCFG20) High-End Overlay Configuration Register 20  Reset Value */

#define LCDC_HEOCFG20_BYGAIN_Pos              _UINT32_(0)                                          /* (LCDC_HEOCFG20) Color Space Conversion Y Coefficient for Blue Component 1:2:10 Format Position */
#define LCDC_HEOCFG20_BYGAIN_Msk              (_UINT32_(0x1FFF) << LCDC_HEOCFG20_BYGAIN_Pos)       /* (LCDC_HEOCFG20) Color Space Conversion Y Coefficient for Blue Component 1:2:10 Format Mask */
#define LCDC_HEOCFG20_BYGAIN(value)           (LCDC_HEOCFG20_BYGAIN_Msk & (_UINT32_(value) << LCDC_HEOCFG20_BYGAIN_Pos)) /* Assigment of value for BYGAIN in the LCDC_HEOCFG20 register */
#define LCDC_HEOCFG20_BCBGAIN_Pos             _UINT32_(16)                                         /* (LCDC_HEOCFG20) Color Space Conversion CB Coefficient for Blue Component 1:2:10 Format Position */
#define LCDC_HEOCFG20_BCBGAIN_Msk             (_UINT32_(0x1FFF) << LCDC_HEOCFG20_BCBGAIN_Pos)      /* (LCDC_HEOCFG20) Color Space Conversion CB Coefficient for Blue Component 1:2:10 Format Mask */
#define LCDC_HEOCFG20_BCBGAIN(value)          (LCDC_HEOCFG20_BCBGAIN_Msk & (_UINT32_(value) << LCDC_HEOCFG20_BCBGAIN_Pos)) /* Assigment of value for BCBGAIN in the LCDC_HEOCFG20 register */
#define LCDC_HEOCFG20_Msk                     _UINT32_(0x1FFF1FFF)                                 /* (LCDC_HEOCFG20) Register Mask  */


/* -------- LCDC_HEOCFG21 : (LCDC Offset: 0x3E4) (R/W 32) High-End Overlay Configuration Register 21 -------- */
#define LCDC_HEOCFG21_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_HEOCFG21) High-End Overlay Configuration Register 21  Reset Value */

#define LCDC_HEOCFG21_BCRGAIN_Pos             _UINT32_(0)                                          /* (LCDC_HEOCFG21) Color Space Conversion Y Coefficient for Blue Component 1:2:10 Format Position */
#define LCDC_HEOCFG21_BCRGAIN_Msk             (_UINT32_(0x1FFF) << LCDC_HEOCFG21_BCRGAIN_Pos)      /* (LCDC_HEOCFG21) Color Space Conversion Y Coefficient for Blue Component 1:2:10 Format Mask */
#define LCDC_HEOCFG21_BCRGAIN(value)          (LCDC_HEOCFG21_BCRGAIN_Msk & (_UINT32_(value) << LCDC_HEOCFG21_BCRGAIN_Pos)) /* Assigment of value for BCRGAIN in the LCDC_HEOCFG21 register */
#define LCDC_HEOCFG21_Msk                     _UINT32_(0x00001FFF)                                 /* (LCDC_HEOCFG21) Register Mask  */


/* -------- LCDC_HEOCFG22 : (LCDC Offset: 0x3E8) (R/W 32) High-End Overlay Configuration Register 22 -------- */
#define LCDC_HEOCFG22_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_HEOCFG22) High-End Overlay Configuration Register 22  Reset Value */

#define LCDC_HEOCFG22_YOFF_Pos                _UINT32_(0)                                          /* (LCDC_HEOCFG22) Luma Offset Position */
#define LCDC_HEOCFG22_YOFF_Msk                (_UINT32_(0x1) << LCDC_HEOCFG22_YOFF_Pos)            /* (LCDC_HEOCFG22) Luma Offset Mask */
#define LCDC_HEOCFG22_YOFF(value)             (LCDC_HEOCFG22_YOFF_Msk & (_UINT32_(value) << LCDC_HEOCFG22_YOFF_Pos)) /* Assigment of value for YOFF in the LCDC_HEOCFG22 register */
#define LCDC_HEOCFG22_CBOFF_Pos               _UINT32_(1)                                          /* (LCDC_HEOCFG22) Blue Chroma Offset Position */
#define LCDC_HEOCFG22_CBOFF_Msk               (_UINT32_(0x1) << LCDC_HEOCFG22_CBOFF_Pos)           /* (LCDC_HEOCFG22) Blue Chroma Offset Mask */
#define LCDC_HEOCFG22_CBOFF(value)            (LCDC_HEOCFG22_CBOFF_Msk & (_UINT32_(value) << LCDC_HEOCFG22_CBOFF_Pos)) /* Assigment of value for CBOFF in the LCDC_HEOCFG22 register */
#define LCDC_HEOCFG22_CROFF_Pos               _UINT32_(2)                                          /* (LCDC_HEOCFG22) Red Chroma Offset Position */
#define LCDC_HEOCFG22_CROFF_Msk               (_UINT32_(0x1) << LCDC_HEOCFG22_CROFF_Pos)           /* (LCDC_HEOCFG22) Red Chroma Offset Mask */
#define LCDC_HEOCFG22_CROFF(value)            (LCDC_HEOCFG22_CROFF_Msk & (_UINT32_(value) << LCDC_HEOCFG22_CROFF_Pos)) /* Assigment of value for CROFF in the LCDC_HEOCFG22 register */
#define LCDC_HEOCFG22_Msk                     _UINT32_(0x00000007)                                 /* (LCDC_HEOCFG22) Register Mask  */


/* -------- LCDC_HEOCFG23 : (LCDC Offset: 0x3EC) (R/W 32) High-End Overlay Configuration Register 23 -------- */
#define LCDC_HEOCFG23_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_HEOCFG23) High-End Overlay Configuration Register 23  Reset Value */

#define LCDC_HEOCFG23_VXSYEN_Pos              _UINT32_(0)                                          /* (LCDC_HEOCFG23) Vertical Scaler Luma Component Enable Position */
#define LCDC_HEOCFG23_VXSYEN_Msk              (_UINT32_(0x1) << LCDC_HEOCFG23_VXSYEN_Pos)          /* (LCDC_HEOCFG23) Vertical Scaler Luma Component Enable Mask */
#define LCDC_HEOCFG23_VXSYEN(value)           (LCDC_HEOCFG23_VXSYEN_Msk & (_UINT32_(value) << LCDC_HEOCFG23_VXSYEN_Pos)) /* Assigment of value for VXSYEN in the LCDC_HEOCFG23 register */
#define LCDC_HEOCFG23_VXSCEN_Pos              _UINT32_(1)                                          /* (LCDC_HEOCFG23) Vertical Scaler Chroma Component Enable Position */
#define LCDC_HEOCFG23_VXSCEN_Msk              (_UINT32_(0x1) << LCDC_HEOCFG23_VXSCEN_Pos)          /* (LCDC_HEOCFG23) Vertical Scaler Chroma Component Enable Mask */
#define LCDC_HEOCFG23_VXSCEN(value)           (LCDC_HEOCFG23_VXSCEN_Msk & (_UINT32_(value) << LCDC_HEOCFG23_VXSCEN_Pos)) /* Assigment of value for VXSCEN in the LCDC_HEOCFG23 register */
#define LCDC_HEOCFG23_HXSYEN_Pos              _UINT32_(4)                                          /* (LCDC_HEOCFG23) Horizontal Scaler Luma Component Enable Position */
#define LCDC_HEOCFG23_HXSYEN_Msk              (_UINT32_(0x1) << LCDC_HEOCFG23_HXSYEN_Pos)          /* (LCDC_HEOCFG23) Horizontal Scaler Luma Component Enable Mask */
#define LCDC_HEOCFG23_HXSYEN(value)           (LCDC_HEOCFG23_HXSYEN_Msk & (_UINT32_(value) << LCDC_HEOCFG23_HXSYEN_Pos)) /* Assigment of value for HXSYEN in the LCDC_HEOCFG23 register */
#define LCDC_HEOCFG23_HXSCEN_Pos              _UINT32_(5)                                          /* (LCDC_HEOCFG23) Horizontal Scaler Chroma Component Enable Position */
#define LCDC_HEOCFG23_HXSCEN_Msk              (_UINT32_(0x1) << LCDC_HEOCFG23_HXSCEN_Pos)          /* (LCDC_HEOCFG23) Horizontal Scaler Chroma Component Enable Mask */
#define LCDC_HEOCFG23_HXSCEN(value)           (LCDC_HEOCFG23_HXSCEN_Msk & (_UINT32_(value) << LCDC_HEOCFG23_HXSCEN_Pos)) /* Assigment of value for HXSCEN in the LCDC_HEOCFG23 register */
#define LCDC_HEOCFG23_Msk                     _UINT32_(0x00000033)                                 /* (LCDC_HEOCFG23) Register Mask  */


/* -------- LCDC_HEOCFG24 : (LCDC Offset: 0x3F0) (R/W 32) High-End Overlay Configuration Register 24 -------- */
#define LCDC_HEOCFG24_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_HEOCFG24) High-End Overlay Configuration Register 24  Reset Value */

#define LCDC_HEOCFG24_VXSYFACT_Pos            _UINT32_(0)                                          /* (LCDC_HEOCFG24) Vertical Luma Scaling Factor Position */
#define LCDC_HEOCFG24_VXSYFACT_Msk            (_UINT32_(0xFFFFFF) << LCDC_HEOCFG24_VXSYFACT_Pos)   /* (LCDC_HEOCFG24) Vertical Luma Scaling Factor Mask */
#define LCDC_HEOCFG24_VXSYFACT(value)         (LCDC_HEOCFG24_VXSYFACT_Msk & (_UINT32_(value) << LCDC_HEOCFG24_VXSYFACT_Pos)) /* Assigment of value for VXSYFACT in the LCDC_HEOCFG24 register */
#define LCDC_HEOCFG24_Msk                     _UINT32_(0x00FFFFFF)                                 /* (LCDC_HEOCFG24) Register Mask  */


/* -------- LCDC_HEOCFG25 : (LCDC Offset: 0x3F4) (R/W 32) High-End Overlay Configuration Register 25 -------- */
#define LCDC_HEOCFG25_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_HEOCFG25) High-End Overlay Configuration Register 25  Reset Value */

#define LCDC_HEOCFG25_VXSCFACT_Pos            _UINT32_(0)                                          /* (LCDC_HEOCFG25) Vertical Chroma Scaling Factor Position */
#define LCDC_HEOCFG25_VXSCFACT_Msk            (_UINT32_(0xFFFFFF) << LCDC_HEOCFG25_VXSCFACT_Pos)   /* (LCDC_HEOCFG25) Vertical Chroma Scaling Factor Mask */
#define LCDC_HEOCFG25_VXSCFACT(value)         (LCDC_HEOCFG25_VXSCFACT_Msk & (_UINT32_(value) << LCDC_HEOCFG25_VXSCFACT_Pos)) /* Assigment of value for VXSCFACT in the LCDC_HEOCFG25 register */
#define LCDC_HEOCFG25_Msk                     _UINT32_(0x00FFFFFF)                                 /* (LCDC_HEOCFG25) Register Mask  */


/* -------- LCDC_HEOCFG26 : (LCDC Offset: 0x3F8) (R/W 32) High-End Overlay Configuration Register 26 -------- */
#define LCDC_HEOCFG26_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_HEOCFG26) High-End Overlay Configuration Register 26  Reset Value */

#define LCDC_HEOCFG26_HXSYFACT_Pos            _UINT32_(0)                                          /* (LCDC_HEOCFG26) Horizontal Luma Scaling factor Position */
#define LCDC_HEOCFG26_HXSYFACT_Msk            (_UINT32_(0xFFFFFF) << LCDC_HEOCFG26_HXSYFACT_Pos)   /* (LCDC_HEOCFG26) Horizontal Luma Scaling factor Mask */
#define LCDC_HEOCFG26_HXSYFACT(value)         (LCDC_HEOCFG26_HXSYFACT_Msk & (_UINT32_(value) << LCDC_HEOCFG26_HXSYFACT_Pos)) /* Assigment of value for HXSYFACT in the LCDC_HEOCFG26 register */
#define LCDC_HEOCFG26_Msk                     _UINT32_(0x00FFFFFF)                                 /* (LCDC_HEOCFG26) Register Mask  */


/* -------- LCDC_HEOCFG27 : (LCDC Offset: 0x3FC) (R/W 32) High-End Overlay Configuration Register 27 -------- */
#define LCDC_HEOCFG27_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_HEOCFG27) High-End Overlay Configuration Register 27  Reset Value */

#define LCDC_HEOCFG27_HXSCFACT_Pos            _UINT32_(0)                                          /* (LCDC_HEOCFG27) Horizontal Chroma Scaling Factor Position */
#define LCDC_HEOCFG27_HXSCFACT_Msk            (_UINT32_(0xFFFFFF) << LCDC_HEOCFG27_HXSCFACT_Pos)   /* (LCDC_HEOCFG27) Horizontal Chroma Scaling Factor Mask */
#define LCDC_HEOCFG27_HXSCFACT(value)         (LCDC_HEOCFG27_HXSCFACT_Msk & (_UINT32_(value) << LCDC_HEOCFG27_HXSCFACT_Pos)) /* Assigment of value for HXSCFACT in the LCDC_HEOCFG27 register */
#define LCDC_HEOCFG27_Msk                     _UINT32_(0x00FFFFFF)                                 /* (LCDC_HEOCFG27) Register Mask  */


/* -------- LCDC_HEOCFG28 : (LCDC Offset: 0x400) (R/W 32) High-End Overlay Configuration Register 28 -------- */
#define LCDC_HEOCFG28_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_HEOCFG28) High-End Overlay Configuration Register 28  Reset Value */

#define LCDC_HEOCFG28_VXSYOFF_Pos             _UINT32_(0)                                          /* (LCDC_HEOCFG28) Vertical Scaler Luma Default Phase for Field 0 or Progressive Scan Position */
#define LCDC_HEOCFG28_VXSYOFF_Msk             (_UINT32_(0xF) << LCDC_HEOCFG28_VXSYOFF_Pos)         /* (LCDC_HEOCFG28) Vertical Scaler Luma Default Phase for Field 0 or Progressive Scan Mask */
#define LCDC_HEOCFG28_VXSYOFF(value)          (LCDC_HEOCFG28_VXSYOFF_Msk & (_UINT32_(value) << LCDC_HEOCFG28_VXSYOFF_Pos)) /* Assigment of value for VXSYOFF in the LCDC_HEOCFG28 register */
#define LCDC_HEOCFG28_VXSYOFF1_Pos            _UINT32_(8)                                          /* (LCDC_HEOCFG28) Vertical Scaler Luma Default Phase for Field 1 Position */
#define LCDC_HEOCFG28_VXSYOFF1_Msk            (_UINT32_(0xF) << LCDC_HEOCFG28_VXSYOFF1_Pos)        /* (LCDC_HEOCFG28) Vertical Scaler Luma Default Phase for Field 1 Mask */
#define LCDC_HEOCFG28_VXSYOFF1(value)         (LCDC_HEOCFG28_VXSYOFF1_Msk & (_UINT32_(value) << LCDC_HEOCFG28_VXSYOFF1_Pos)) /* Assigment of value for VXSYOFF1 in the LCDC_HEOCFG28 register */
#define LCDC_HEOCFG28_VXSCOFF_Pos             _UINT32_(16)                                         /* (LCDC_HEOCFG28) Vertical Scaler Chroma Default Phase for Field 0 or Progressive Scan Position */
#define LCDC_HEOCFG28_VXSCOFF_Msk             (_UINT32_(0xF) << LCDC_HEOCFG28_VXSCOFF_Pos)         /* (LCDC_HEOCFG28) Vertical Scaler Chroma Default Phase for Field 0 or Progressive Scan Mask */
#define LCDC_HEOCFG28_VXSCOFF(value)          (LCDC_HEOCFG28_VXSCOFF_Msk & (_UINT32_(value) << LCDC_HEOCFG28_VXSCOFF_Pos)) /* Assigment of value for VXSCOFF in the LCDC_HEOCFG28 register */
#define LCDC_HEOCFG28_VXSCOFF1_Pos            _UINT32_(24)                                         /* (LCDC_HEOCFG28) Vertical Scaler Chroma Default Phase for Field 1 Position */
#define LCDC_HEOCFG28_VXSCOFF1_Msk            (_UINT32_(0xF) << LCDC_HEOCFG28_VXSCOFF1_Pos)        /* (LCDC_HEOCFG28) Vertical Scaler Chroma Default Phase for Field 1 Mask */
#define LCDC_HEOCFG28_VXSCOFF1(value)         (LCDC_HEOCFG28_VXSCOFF1_Msk & (_UINT32_(value) << LCDC_HEOCFG28_VXSCOFF1_Pos)) /* Assigment of value for VXSCOFF1 in the LCDC_HEOCFG28 register */
#define LCDC_HEOCFG28_Msk                     _UINT32_(0x0F0F0F0F)                                 /* (LCDC_HEOCFG28) Register Mask  */


/* -------- LCDC_HEOCFG29 : (LCDC Offset: 0x404) (R/W 32) High-End Overlay Configuration Register 29 -------- */
#define LCDC_HEOCFG29_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_HEOCFG29) High-End Overlay Configuration Register 29  Reset Value */

#define LCDC_HEOCFG29_HXSYOFF_Pos             _UINT32_(0)                                          /* (LCDC_HEOCFG29) Horizontal Scaler Luma Offset Position */
#define LCDC_HEOCFG29_HXSYOFF_Msk             (_UINT32_(0xF) << LCDC_HEOCFG29_HXSYOFF_Pos)         /* (LCDC_HEOCFG29) Horizontal Scaler Luma Offset Mask */
#define LCDC_HEOCFG29_HXSYOFF(value)          (LCDC_HEOCFG29_HXSYOFF_Msk & (_UINT32_(value) << LCDC_HEOCFG29_HXSYOFF_Pos)) /* Assigment of value for HXSYOFF in the LCDC_HEOCFG29 register */
#define LCDC_HEOCFG29_HXSCOFF_Pos             _UINT32_(16)                                         /* (LCDC_HEOCFG29) Hozontal Scaler Chroma Offset Position */
#define LCDC_HEOCFG29_HXSCOFF_Msk             (_UINT32_(0xF) << LCDC_HEOCFG29_HXSCOFF_Pos)         /* (LCDC_HEOCFG29) Hozontal Scaler Chroma Offset Mask */
#define LCDC_HEOCFG29_HXSCOFF(value)          (LCDC_HEOCFG29_HXSCOFF_Msk & (_UINT32_(value) << LCDC_HEOCFG29_HXSCOFF_Pos)) /* Assigment of value for HXSCOFF in the LCDC_HEOCFG29 register */
#define LCDC_HEOCFG29_Msk                     _UINT32_(0x000F000F)                                 /* (LCDC_HEOCFG29) Register Mask  */


/* -------- LCDC_HEOCFG30 : (LCDC Offset: 0x408) (R/W 32) High-End Overlay Configuration Register 30 -------- */
#define LCDC_HEOCFG30_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_HEOCFG30) High-End Overlay Configuration Register 30  Reset Value */

#define LCDC_HEOCFG30_VXSYCFG_Pos             _UINT32_(0)                                          /* (LCDC_HEOCFG30) Vertical Scaler Luma/AR Configuration for Field 0 or Progressive Scan Position */
#define LCDC_HEOCFG30_VXSYCFG_Msk             (_UINT32_(0x3) << LCDC_HEOCFG30_VXSYCFG_Pos)         /* (LCDC_HEOCFG30) Vertical Scaler Luma/AR Configuration for Field 0 or Progressive Scan Mask */
#define LCDC_HEOCFG30_VXSYCFG(value)          (LCDC_HEOCFG30_VXSYCFG_Msk & (_UINT32_(value) << LCDC_HEOCFG30_VXSYCFG_Pos)) /* Assigment of value for VXSYCFG in the LCDC_HEOCFG30 register */
#define LCDC_HEOCFG30_VXSYTAP2_Pos            _UINT32_(4)                                          /* (LCDC_HEOCFG30) Vertical Scaler Predefined Bilinear 2 Taps Selected for Luma/AR Component Position */
#define LCDC_HEOCFG30_VXSYTAP2_Msk            (_UINT32_(0x1) << LCDC_HEOCFG30_VXSYTAP2_Pos)        /* (LCDC_HEOCFG30) Vertical Scaler Predefined Bilinear 2 Taps Selected for Luma/AR Component Mask */
#define LCDC_HEOCFG30_VXSYTAP2(value)         (LCDC_HEOCFG30_VXSYTAP2_Msk & (_UINT32_(value) << LCDC_HEOCFG30_VXSYTAP2_Pos)) /* Assigment of value for VXSYTAP2 in the LCDC_HEOCFG30 register */
#define   LCDC_HEOCFG30_VXSYTAP2_0_Val        _UINT32_(0x0)                                        /* (LCDC_HEOCFG30) Bilinear 2 taps value not selected.  */
#define   LCDC_HEOCFG30_VXSYTAP2_1_Val        _UINT32_(0x1)                                        /* (LCDC_HEOCFG30) Bilinear 2 taps value selected.  */
#define LCDC_HEOCFG30_VXSYTAP2_0              (LCDC_HEOCFG30_VXSYTAP2_0_Val << LCDC_HEOCFG30_VXSYTAP2_Pos) /* (LCDC_HEOCFG30) Bilinear 2 taps value not selected. Position  */
#define LCDC_HEOCFG30_VXSYTAP2_1              (LCDC_HEOCFG30_VXSYTAP2_1_Val << LCDC_HEOCFG30_VXSYTAP2_Pos) /* (LCDC_HEOCFG30) Bilinear 2 taps value selected. Position  */
#define LCDC_HEOCFG30_VXSY1201N_Pos           _UINT32_(5)                                          /* (LCDC_HEOCFG30) Vertical Scaler Bilinear 2 Taps Position among 4 Filter Taps for Luma/AR Component Position */
#define LCDC_HEOCFG30_VXSY1201N_Msk           (_UINT32_(0x1) << LCDC_HEOCFG30_VXSY1201N_Pos)       /* (LCDC_HEOCFG30) Vertical Scaler Bilinear 2 Taps Position among 4 Filter Taps for Luma/AR Component Mask */
#define LCDC_HEOCFG30_VXSY1201N(value)        (LCDC_HEOCFG30_VXSY1201N_Msk & (_UINT32_(value) << LCDC_HEOCFG30_VXSY1201N_Pos)) /* Assigment of value for VXSY1201N in the LCDC_HEOCFG30 register */
#define   LCDC_HEOCFG30_VXSY1201N_0_Val       _UINT32_(0x0)                                        /* (LCDC_HEOCFG30) When selected, bilinear tap values are located on 0 and 1 positions (left-aligned).  */
#define   LCDC_HEOCFG30_VXSY1201N_1_Val       _UINT32_(0x1)                                        /* (LCDC_HEOCFG30) When selected, bilinear tap values are located on 0 and 1 positions (center-aligned).  */
#define LCDC_HEOCFG30_VXSY1201N_0             (LCDC_HEOCFG30_VXSY1201N_0_Val << LCDC_HEOCFG30_VXSY1201N_Pos) /* (LCDC_HEOCFG30) When selected, bilinear tap values are located on 0 and 1 positions (left-aligned). Position  */
#define LCDC_HEOCFG30_VXSY1201N_1             (LCDC_HEOCFG30_VXSY1201N_1_Val << LCDC_HEOCFG30_VXSY1201N_Pos) /* (LCDC_HEOCFG30) When selected, bilinear tap values are located on 0 and 1 positions (center-aligned). Position  */
#define LCDC_HEOCFG30_VXSYBICU_Pos            _UINT32_(6)                                          /* (LCDC_HEOCFG30) Vertical Scaler Predefined Bicubic Taps Selected for Luma/AR Component Position */
#define LCDC_HEOCFG30_VXSYBICU_Msk            (_UINT32_(0x1) << LCDC_HEOCFG30_VXSYBICU_Pos)        /* (LCDC_HEOCFG30) Vertical Scaler Predefined Bicubic Taps Selected for Luma/AR Component Mask */
#define LCDC_HEOCFG30_VXSYBICU(value)         (LCDC_HEOCFG30_VXSYBICU_Msk & (_UINT32_(value) << LCDC_HEOCFG30_VXSYBICU_Pos)) /* Assigment of value for VXSYBICU in the LCDC_HEOCFG30 register */
#define   LCDC_HEOCFG30_VXSYBICU_0_Val        _UINT32_(0x0)                                        /* (LCDC_HEOCFG30) Bicubic taps values are not selected.  */
#define   LCDC_HEOCFG30_VXSYBICU_1_Val        _UINT32_(0x1)                                        /* (LCDC_HEOCFG30) Bicubic taps values are selected.  */
#define LCDC_HEOCFG30_VXSYBICU_0              (LCDC_HEOCFG30_VXSYBICU_0_Val << LCDC_HEOCFG30_VXSYBICU_Pos) /* (LCDC_HEOCFG30) Bicubic taps values are not selected. Position  */
#define LCDC_HEOCFG30_VXSYBICU_1              (LCDC_HEOCFG30_VXSYBICU_1_Val << LCDC_HEOCFG30_VXSYBICU_Pos) /* (LCDC_HEOCFG30) Bicubic taps values are selected. Position  */
#define LCDC_HEOCFG30_VXSYCFG1_Pos            _UINT32_(8)                                          /* (LCDC_HEOCFG30) Vertical Scaler Chroma/GB Configuration for Field 1 (only used for interlaced frame content) Position */
#define LCDC_HEOCFG30_VXSYCFG1_Msk            (_UINT32_(0x3) << LCDC_HEOCFG30_VXSYCFG1_Pos)        /* (LCDC_HEOCFG30) Vertical Scaler Chroma/GB Configuration for Field 1 (only used for interlaced frame content) Mask */
#define LCDC_HEOCFG30_VXSYCFG1(value)         (LCDC_HEOCFG30_VXSYCFG1_Msk & (_UINT32_(value) << LCDC_HEOCFG30_VXSYCFG1_Pos)) /* Assigment of value for VXSYCFG1 in the LCDC_HEOCFG30 register */
#define LCDC_HEOCFG30_VXSCCFG_Pos             _UINT32_(16)                                         /* (LCDC_HEOCFG30) Vertical Scaler Chroma/GB Configuration for Field 0 or Progressive Scan Position */
#define LCDC_HEOCFG30_VXSCCFG_Msk             (_UINT32_(0x3) << LCDC_HEOCFG30_VXSCCFG_Pos)         /* (LCDC_HEOCFG30) Vertical Scaler Chroma/GB Configuration for Field 0 or Progressive Scan Mask */
#define LCDC_HEOCFG30_VXSCCFG(value)          (LCDC_HEOCFG30_VXSCCFG_Msk & (_UINT32_(value) << LCDC_HEOCFG30_VXSCCFG_Pos)) /* Assigment of value for VXSCCFG in the LCDC_HEOCFG30 register */
#define LCDC_HEOCFG30_VXSCTAP2_Pos            _UINT32_(20)                                         /* (LCDC_HEOCFG30) Vertical Scaler Predefined Bilinear 2 Taps Selected for Chroma/GB Component Position */
#define LCDC_HEOCFG30_VXSCTAP2_Msk            (_UINT32_(0x1) << LCDC_HEOCFG30_VXSCTAP2_Pos)        /* (LCDC_HEOCFG30) Vertical Scaler Predefined Bilinear 2 Taps Selected for Chroma/GB Component Mask */
#define LCDC_HEOCFG30_VXSCTAP2(value)         (LCDC_HEOCFG30_VXSCTAP2_Msk & (_UINT32_(value) << LCDC_HEOCFG30_VXSCTAP2_Pos)) /* Assigment of value for VXSCTAP2 in the LCDC_HEOCFG30 register */
#define   LCDC_HEOCFG30_VXSCTAP2_0_Val        _UINT32_(0x0)                                        /* (LCDC_HEOCFG30) Bilinear 2 taps value not selected.  */
#define   LCDC_HEOCFG30_VXSCTAP2_1_Val        _UINT32_(0x1)                                        /* (LCDC_HEOCFG30) Bilinear 2 taps value selected.  */
#define LCDC_HEOCFG30_VXSCTAP2_0              (LCDC_HEOCFG30_VXSCTAP2_0_Val << LCDC_HEOCFG30_VXSCTAP2_Pos) /* (LCDC_HEOCFG30) Bilinear 2 taps value not selected. Position  */
#define LCDC_HEOCFG30_VXSCTAP2_1              (LCDC_HEOCFG30_VXSCTAP2_1_Val << LCDC_HEOCFG30_VXSCTAP2_Pos) /* (LCDC_HEOCFG30) Bilinear 2 taps value selected. Position  */
#define LCDC_HEOCFG30_VXSC1201N_Pos           _UINT32_(21)                                         /* (LCDC_HEOCFG30) Vertical Scaler Bilinear 2 Taps Position among 4 Taps Filter for Chroma/GB Component Position */
#define LCDC_HEOCFG30_VXSC1201N_Msk           (_UINT32_(0x1) << LCDC_HEOCFG30_VXSC1201N_Pos)       /* (LCDC_HEOCFG30) Vertical Scaler Bilinear 2 Taps Position among 4 Taps Filter for Chroma/GB Component Mask */
#define LCDC_HEOCFG30_VXSC1201N(value)        (LCDC_HEOCFG30_VXSC1201N_Msk & (_UINT32_(value) << LCDC_HEOCFG30_VXSC1201N_Pos)) /* Assigment of value for VXSC1201N in the LCDC_HEOCFG30 register */
#define   LCDC_HEOCFG30_VXSC1201N_0_Val       _UINT32_(0x0)                                        /* (LCDC_HEOCFG30) When selected, bilinear taps values are located on 0 and 1 positions (left aligned).  */
#define   LCDC_HEOCFG30_VXSC1201N_1_Val       _UINT32_(0x1)                                        /* (LCDC_HEOCFG30) When selected, bilinear taps values are located on 0 and 1 positions (center aligned).  */
#define LCDC_HEOCFG30_VXSC1201N_0             (LCDC_HEOCFG30_VXSC1201N_0_Val << LCDC_HEOCFG30_VXSC1201N_Pos) /* (LCDC_HEOCFG30) When selected, bilinear taps values are located on 0 and 1 positions (left aligned). Position  */
#define LCDC_HEOCFG30_VXSC1201N_1             (LCDC_HEOCFG30_VXSC1201N_1_Val << LCDC_HEOCFG30_VXSC1201N_Pos) /* (LCDC_HEOCFG30) When selected, bilinear taps values are located on 0 and 1 positions (center aligned). Position  */
#define LCDC_HEOCFG30_VXSCBICU_Pos            _UINT32_(22)                                         /* (LCDC_HEOCFG30) Vertical Scaler Predefined Bicubic Taps Selected for Chroma/GB Component Position */
#define LCDC_HEOCFG30_VXSCBICU_Msk            (_UINT32_(0x1) << LCDC_HEOCFG30_VXSCBICU_Pos)        /* (LCDC_HEOCFG30) Vertical Scaler Predefined Bicubic Taps Selected for Chroma/GB Component Mask */
#define LCDC_HEOCFG30_VXSCBICU(value)         (LCDC_HEOCFG30_VXSCBICU_Msk & (_UINT32_(value) << LCDC_HEOCFG30_VXSCBICU_Pos)) /* Assigment of value for VXSCBICU in the LCDC_HEOCFG30 register */
#define   LCDC_HEOCFG30_VXSCBICU_0_Val        _UINT32_(0x0)                                        /* (LCDC_HEOCFG30) Bicubic taps values are not selected.  */
#define   LCDC_HEOCFG30_VXSCBICU_1_Val        _UINT32_(0x1)                                        /* (LCDC_HEOCFG30) Bicubic taps values are selected.  */
#define LCDC_HEOCFG30_VXSCBICU_0              (LCDC_HEOCFG30_VXSCBICU_0_Val << LCDC_HEOCFG30_VXSCBICU_Pos) /* (LCDC_HEOCFG30) Bicubic taps values are not selected. Position  */
#define LCDC_HEOCFG30_VXSCBICU_1              (LCDC_HEOCFG30_VXSCBICU_1_Val << LCDC_HEOCFG30_VXSCBICU_Pos) /* (LCDC_HEOCFG30) Bicubic taps values are selected. Position  */
#define LCDC_HEOCFG30_VXSCCFG1_Pos            _UINT32_(24)                                         /* (LCDC_HEOCFG30) Vertical Scaler Chroma Configuration for Field 1(only used for YCrCb Interlaced Frame Content) Position */
#define LCDC_HEOCFG30_VXSCCFG1_Msk            (_UINT32_(0x3) << LCDC_HEOCFG30_VXSCCFG1_Pos)        /* (LCDC_HEOCFG30) Vertical Scaler Chroma Configuration for Field 1(only used for YCrCb Interlaced Frame Content) Mask */
#define LCDC_HEOCFG30_VXSCCFG1(value)         (LCDC_HEOCFG30_VXSCCFG1_Msk & (_UINT32_(value) << LCDC_HEOCFG30_VXSCCFG1_Pos)) /* Assigment of value for VXSCCFG1 in the LCDC_HEOCFG30 register */
#define LCDC_HEOCFG30_Msk                     _UINT32_(0x03730373)                                 /* (LCDC_HEOCFG30) Register Mask  */

#define LCDC_HEOCFG30_VXSYTAP_Pos             _UINT32_(4)                                          /* (LCDC_HEOCFG30 Position) Vertical Scaler Predefined Bilinear 2 Taps Selected for Luma/AR Component */
#define LCDC_HEOCFG30_VXSYTAP_Msk             (_UINT32_(0x1) << LCDC_HEOCFG30_VXSYTAP_Pos)         /* (LCDC_HEOCFG30 Mask) VXSYTAP */
#define LCDC_HEOCFG30_VXSYTAP(value)          (LCDC_HEOCFG30_VXSYTAP_Msk & (_UINT32_(value) << LCDC_HEOCFG30_VXSYTAP_Pos)) 
#define LCDC_HEOCFG30_VXSCTAP_Pos             _UINT32_(20)                                         /* (LCDC_HEOCFG30 Position) Vertical Scaler Predefined Bilinear 2 Taps Selected for Chroma/GB Component */
#define LCDC_HEOCFG30_VXSCTAP_Msk             (_UINT32_(0x1) << LCDC_HEOCFG30_VXSCTAP_Pos)         /* (LCDC_HEOCFG30 Mask) VXSCTAP */
#define LCDC_HEOCFG30_VXSCTAP(value)          (LCDC_HEOCFG30_VXSCTAP_Msk & (_UINT32_(value) << LCDC_HEOCFG30_VXSCTAP_Pos)) 

/* -------- LCDC_HEOCFG31 : (LCDC Offset: 0x40C) (R/W 32) High-End Overlay Configuration Register 31 -------- */
#define LCDC_HEOCFG31_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_HEOCFG31) High-End Overlay Configuration Register 31  Reset Value */

#define LCDC_HEOCFG31_HXSYCFG_Pos             _UINT32_(0)                                          /* (LCDC_HEOCFG31) Horizontal Scaler Luma Configuration Position */
#define LCDC_HEOCFG31_HXSYCFG_Msk             (_UINT32_(0x3) << LCDC_HEOCFG31_HXSYCFG_Pos)         /* (LCDC_HEOCFG31) Horizontal Scaler Luma Configuration Mask */
#define LCDC_HEOCFG31_HXSYCFG(value)          (LCDC_HEOCFG31_HXSYCFG_Msk & (_UINT32_(value) << LCDC_HEOCFG31_HXSYCFG_Pos)) /* Assigment of value for HXSYCFG in the LCDC_HEOCFG31 register */
#define LCDC_HEOCFG31_HXSYTAP2_Pos            _UINT32_(4)                                          /* (LCDC_HEOCFG31) Horizontal Scaler Predefined Bilinear 2 Taps Selected for Luma/AR Component Position */
#define LCDC_HEOCFG31_HXSYTAP2_Msk            (_UINT32_(0x1) << LCDC_HEOCFG31_HXSYTAP2_Pos)        /* (LCDC_HEOCFG31) Horizontal Scaler Predefined Bilinear 2 Taps Selected for Luma/AR Component Mask */
#define LCDC_HEOCFG31_HXSYTAP2(value)         (LCDC_HEOCFG31_HXSYTAP2_Msk & (_UINT32_(value) << LCDC_HEOCFG31_HXSYTAP2_Pos)) /* Assigment of value for HXSYTAP2 in the LCDC_HEOCFG31 register */
#define   LCDC_HEOCFG31_HXSYTAP2_0_Val        _UINT32_(0x0)                                        /* (LCDC_HEOCFG31) Bilinear 2 taps value not selected.  */
#define   LCDC_HEOCFG31_HXSYTAP2_1_Val        _UINT32_(0x1)                                        /* (LCDC_HEOCFG31) Bilinear 2 taps value selected.  */
#define LCDC_HEOCFG31_HXSYTAP2_0              (LCDC_HEOCFG31_HXSYTAP2_0_Val << LCDC_HEOCFG31_HXSYTAP2_Pos) /* (LCDC_HEOCFG31) Bilinear 2 taps value not selected. Position  */
#define LCDC_HEOCFG31_HXSYTAP2_1              (LCDC_HEOCFG31_HXSYTAP2_1_Val << LCDC_HEOCFG31_HXSYTAP2_Pos) /* (LCDC_HEOCFG31) Bilinear 2 taps value selected. Position  */
#define LCDC_HEOCFG31_HXSYBICU_Pos            _UINT32_(5)                                          /* (LCDC_HEOCFG31) Horizontal Scaler Predefined Bicubic Taps Selected for Luma/AR Component Position */
#define LCDC_HEOCFG31_HXSYBICU_Msk            (_UINT32_(0x1) << LCDC_HEOCFG31_HXSYBICU_Pos)        /* (LCDC_HEOCFG31) Horizontal Scaler Predefined Bicubic Taps Selected for Luma/AR Component Mask */
#define LCDC_HEOCFG31_HXSYBICU(value)         (LCDC_HEOCFG31_HXSYBICU_Msk & (_UINT32_(value) << LCDC_HEOCFG31_HXSYBICU_Pos)) /* Assigment of value for HXSYBICU in the LCDC_HEOCFG31 register */
#define   LCDC_HEOCFG31_HXSYBICU_0_Val        _UINT32_(0x0)                                        /* (LCDC_HEOCFG31) Bicubic taps values are not selected.  */
#define   LCDC_HEOCFG31_HXSYBICU_1_Val        _UINT32_(0x1)                                        /* (LCDC_HEOCFG31) Bicubic taps values are selected.  */
#define LCDC_HEOCFG31_HXSYBICU_0              (LCDC_HEOCFG31_HXSYBICU_0_Val << LCDC_HEOCFG31_HXSYBICU_Pos) /* (LCDC_HEOCFG31) Bicubic taps values are not selected. Position  */
#define LCDC_HEOCFG31_HXSYBICU_1              (LCDC_HEOCFG31_HXSYBICU_1_Val << LCDC_HEOCFG31_HXSYBICU_Pos) /* (LCDC_HEOCFG31) Bicubic taps values are selected. Position  */
#define LCDC_HEOCFG31_HXSCCFG_Pos             _UINT32_(16)                                         /* (LCDC_HEOCFG31) Horizontal Scaler Chroma/GB Configuration Position */
#define LCDC_HEOCFG31_HXSCCFG_Msk             (_UINT32_(0x3) << LCDC_HEOCFG31_HXSCCFG_Pos)         /* (LCDC_HEOCFG31) Horizontal Scaler Chroma/GB Configuration Mask */
#define LCDC_HEOCFG31_HXSCCFG(value)          (LCDC_HEOCFG31_HXSCCFG_Msk & (_UINT32_(value) << LCDC_HEOCFG31_HXSCCFG_Pos)) /* Assigment of value for HXSCCFG in the LCDC_HEOCFG31 register */
#define LCDC_HEOCFG31_HXSCTAP2_Pos            _UINT32_(20)                                         /* (LCDC_HEOCFG31) Horizontal Scaler Predefined Bilinear 2 Taps Selected for Chroma Component Position */
#define LCDC_HEOCFG31_HXSCTAP2_Msk            (_UINT32_(0x1) << LCDC_HEOCFG31_HXSCTAP2_Pos)        /* (LCDC_HEOCFG31) Horizontal Scaler Predefined Bilinear 2 Taps Selected for Chroma Component Mask */
#define LCDC_HEOCFG31_HXSCTAP2(value)         (LCDC_HEOCFG31_HXSCTAP2_Msk & (_UINT32_(value) << LCDC_HEOCFG31_HXSCTAP2_Pos)) /* Assigment of value for HXSCTAP2 in the LCDC_HEOCFG31 register */
#define   LCDC_HEOCFG31_HXSCTAP2_0_Val        _UINT32_(0x0)                                        /* (LCDC_HEOCFG31) Bilinear 2 taps value not selected.  */
#define   LCDC_HEOCFG31_HXSCTAP2_1_Val        _UINT32_(0x1)                                        /* (LCDC_HEOCFG31) Bilinear 2 taps value selected.  */
#define LCDC_HEOCFG31_HXSCTAP2_0              (LCDC_HEOCFG31_HXSCTAP2_0_Val << LCDC_HEOCFG31_HXSCTAP2_Pos) /* (LCDC_HEOCFG31) Bilinear 2 taps value not selected. Position  */
#define LCDC_HEOCFG31_HXSCTAP2_1              (LCDC_HEOCFG31_HXSCTAP2_1_Val << LCDC_HEOCFG31_HXSCTAP2_Pos) /* (LCDC_HEOCFG31) Bilinear 2 taps value selected. Position  */
#define LCDC_HEOCFG31_HXSCBICU_Pos            _UINT32_(21)                                         /* (LCDC_HEOCFG31) Horizontal Scaler Bicubic Coefficients Selected for Chroma Component Position */
#define LCDC_HEOCFG31_HXSCBICU_Msk            (_UINT32_(0x1) << LCDC_HEOCFG31_HXSCBICU_Pos)        /* (LCDC_HEOCFG31) Horizontal Scaler Bicubic Coefficients Selected for Chroma Component Mask */
#define LCDC_HEOCFG31_HXSCBICU(value)         (LCDC_HEOCFG31_HXSCBICU_Msk & (_UINT32_(value) << LCDC_HEOCFG31_HXSCBICU_Pos)) /* Assigment of value for HXSCBICU in the LCDC_HEOCFG31 register */
#define   LCDC_HEOCFG31_HXSCBICU_0_Val        _UINT32_(0x0)                                        /* (LCDC_HEOCFG31) Bicubic taps values are not selected.  */
#define   LCDC_HEOCFG31_HXSCBICU_1_Val        _UINT32_(0x1)                                        /* (LCDC_HEOCFG31) Bicubic taps values are selected.  */
#define LCDC_HEOCFG31_HXSCBICU_0              (LCDC_HEOCFG31_HXSCBICU_0_Val << LCDC_HEOCFG31_HXSCBICU_Pos) /* (LCDC_HEOCFG31) Bicubic taps values are not selected. Position  */
#define LCDC_HEOCFG31_HXSCBICU_1              (LCDC_HEOCFG31_HXSCBICU_1_Val << LCDC_HEOCFG31_HXSCBICU_Pos) /* (LCDC_HEOCFG31) Bicubic taps values are selected. Position  */
#define LCDC_HEOCFG31_Msk                     _UINT32_(0x00330033)                                 /* (LCDC_HEOCFG31) Register Mask  */

#define LCDC_HEOCFG31_HXSYTAP_Pos             _UINT32_(4)                                          /* (LCDC_HEOCFG31 Position) Horizontal Scaler Predefined Bilinear 2 Taps Selected for Luma/AR Component */
#define LCDC_HEOCFG31_HXSYTAP_Msk             (_UINT32_(0x1) << LCDC_HEOCFG31_HXSYTAP_Pos)         /* (LCDC_HEOCFG31 Mask) HXSYTAP */
#define LCDC_HEOCFG31_HXSYTAP(value)          (LCDC_HEOCFG31_HXSYTAP_Msk & (_UINT32_(value) << LCDC_HEOCFG31_HXSYTAP_Pos)) 
#define LCDC_HEOCFG31_HXSCTAP_Pos             _UINT32_(20)                                         /* (LCDC_HEOCFG31 Position) Horizontal Scaler Predefined Bilinear 2 Taps Selected for Chroma Component */
#define LCDC_HEOCFG31_HXSCTAP_Msk             (_UINT32_(0x1) << LCDC_HEOCFG31_HXSCTAP_Pos)         /* (LCDC_HEOCFG31 Mask) HXSCTAP */
#define LCDC_HEOCFG31_HXSCTAP(value)          (LCDC_HEOCFG31_HXSCTAP_Msk & (_UINT32_(value) << LCDC_HEOCFG31_HXSCTAP_Pos)) 

/* -------- LCDC_BASECLUT : (LCDC Offset: 0x700) (R/W 32) Base Layer CLUT Register x -------- */
#define LCDC_BASECLUT_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_BASECLUT) Base Layer CLUT Register x  Reset Value */

#define LCDC_BASECLUT_BCLUT_Pos               _UINT32_(0)                                          /* (LCDC_BASECLUT) Blue Color Entry Position */
#define LCDC_BASECLUT_BCLUT_Msk               (_UINT32_(0xFF) << LCDC_BASECLUT_BCLUT_Pos)          /* (LCDC_BASECLUT) Blue Color Entry Mask */
#define LCDC_BASECLUT_BCLUT(value)            (LCDC_BASECLUT_BCLUT_Msk & (_UINT32_(value) << LCDC_BASECLUT_BCLUT_Pos)) /* Assigment of value for BCLUT in the LCDC_BASECLUT register */
#define LCDC_BASECLUT_GCLUT_Pos               _UINT32_(8)                                          /* (LCDC_BASECLUT) Green Color Entry Position */
#define LCDC_BASECLUT_GCLUT_Msk               (_UINT32_(0xFF) << LCDC_BASECLUT_GCLUT_Pos)          /* (LCDC_BASECLUT) Green Color Entry Mask */
#define LCDC_BASECLUT_GCLUT(value)            (LCDC_BASECLUT_GCLUT_Msk & (_UINT32_(value) << LCDC_BASECLUT_GCLUT_Pos)) /* Assigment of value for GCLUT in the LCDC_BASECLUT register */
#define LCDC_BASECLUT_RCLUT_Pos               _UINT32_(16)                                         /* (LCDC_BASECLUT) Red Color Entry Position */
#define LCDC_BASECLUT_RCLUT_Msk               (_UINT32_(0xFF) << LCDC_BASECLUT_RCLUT_Pos)          /* (LCDC_BASECLUT) Red Color Entry Mask */
#define LCDC_BASECLUT_RCLUT(value)            (LCDC_BASECLUT_RCLUT_Msk & (_UINT32_(value) << LCDC_BASECLUT_RCLUT_Pos)) /* Assigment of value for RCLUT in the LCDC_BASECLUT register */
#define LCDC_BASECLUT_ACLUT_Pos               _UINT32_(24)                                         /* (LCDC_BASECLUT) Alpha Component Entry Position */
#define LCDC_BASECLUT_ACLUT_Msk               (_UINT32_(0xFF) << LCDC_BASECLUT_ACLUT_Pos)          /* (LCDC_BASECLUT) Alpha Component Entry Mask */
#define LCDC_BASECLUT_ACLUT(value)            (LCDC_BASECLUT_ACLUT_Msk & (_UINT32_(value) << LCDC_BASECLUT_ACLUT_Pos)) /* Assigment of value for ACLUT in the LCDC_BASECLUT register */
#define LCDC_BASECLUT_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (LCDC_BASECLUT) Register Mask  */


/* -------- LCDC_OVR1CLUT : (LCDC Offset: 0xB00) (R/W 32) Overlay 1 CLUT Register x -------- */
#define LCDC_OVR1CLUT_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_OVR1CLUT) Overlay 1 CLUT Register x  Reset Value */

#define LCDC_OVR1CLUT_BCLUT_Pos               _UINT32_(0)                                          /* (LCDC_OVR1CLUT) Blue Color Entry Position */
#define LCDC_OVR1CLUT_BCLUT_Msk               (_UINT32_(0xFF) << LCDC_OVR1CLUT_BCLUT_Pos)          /* (LCDC_OVR1CLUT) Blue Color Entry Mask */
#define LCDC_OVR1CLUT_BCLUT(value)            (LCDC_OVR1CLUT_BCLUT_Msk & (_UINT32_(value) << LCDC_OVR1CLUT_BCLUT_Pos)) /* Assigment of value for BCLUT in the LCDC_OVR1CLUT register */
#define LCDC_OVR1CLUT_GCLUT_Pos               _UINT32_(8)                                          /* (LCDC_OVR1CLUT) Green Color Entry Position */
#define LCDC_OVR1CLUT_GCLUT_Msk               (_UINT32_(0xFF) << LCDC_OVR1CLUT_GCLUT_Pos)          /* (LCDC_OVR1CLUT) Green Color Entry Mask */
#define LCDC_OVR1CLUT_GCLUT(value)            (LCDC_OVR1CLUT_GCLUT_Msk & (_UINT32_(value) << LCDC_OVR1CLUT_GCLUT_Pos)) /* Assigment of value for GCLUT in the LCDC_OVR1CLUT register */
#define LCDC_OVR1CLUT_RCLUT_Pos               _UINT32_(16)                                         /* (LCDC_OVR1CLUT) Red Color Entry Position */
#define LCDC_OVR1CLUT_RCLUT_Msk               (_UINT32_(0xFF) << LCDC_OVR1CLUT_RCLUT_Pos)          /* (LCDC_OVR1CLUT) Red Color Entry Mask */
#define LCDC_OVR1CLUT_RCLUT(value)            (LCDC_OVR1CLUT_RCLUT_Msk & (_UINT32_(value) << LCDC_OVR1CLUT_RCLUT_Pos)) /* Assigment of value for RCLUT in the LCDC_OVR1CLUT register */
#define LCDC_OVR1CLUT_ACLUT_Pos               _UINT32_(24)                                         /* (LCDC_OVR1CLUT) Alpha Color Entry Position */
#define LCDC_OVR1CLUT_ACLUT_Msk               (_UINT32_(0xFF) << LCDC_OVR1CLUT_ACLUT_Pos)          /* (LCDC_OVR1CLUT) Alpha Color Entry Mask */
#define LCDC_OVR1CLUT_ACLUT(value)            (LCDC_OVR1CLUT_ACLUT_Msk & (_UINT32_(value) << LCDC_OVR1CLUT_ACLUT_Pos)) /* Assigment of value for ACLUT in the LCDC_OVR1CLUT register */
#define LCDC_OVR1CLUT_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (LCDC_OVR1CLUT) Register Mask  */


/* -------- LCDC_OVR2CLUT : (LCDC Offset: 0xF00) (R/W 32) Overlay 2 CLUT Register x -------- */
#define LCDC_OVR2CLUT_RESETVALUE              _UINT32_(0x00)                                       /*  (LCDC_OVR2CLUT) Overlay 2 CLUT Register x  Reset Value */

#define LCDC_OVR2CLUT_BCLUT_Pos               _UINT32_(0)                                          /* (LCDC_OVR2CLUT) Blue Color Entry Position */
#define LCDC_OVR2CLUT_BCLUT_Msk               (_UINT32_(0xFF) << LCDC_OVR2CLUT_BCLUT_Pos)          /* (LCDC_OVR2CLUT) Blue Color Entry Mask */
#define LCDC_OVR2CLUT_BCLUT(value)            (LCDC_OVR2CLUT_BCLUT_Msk & (_UINT32_(value) << LCDC_OVR2CLUT_BCLUT_Pos)) /* Assigment of value for BCLUT in the LCDC_OVR2CLUT register */
#define LCDC_OVR2CLUT_GCLUT_Pos               _UINT32_(8)                                          /* (LCDC_OVR2CLUT) Green Color Entry Position */
#define LCDC_OVR2CLUT_GCLUT_Msk               (_UINT32_(0xFF) << LCDC_OVR2CLUT_GCLUT_Pos)          /* (LCDC_OVR2CLUT) Green Color Entry Mask */
#define LCDC_OVR2CLUT_GCLUT(value)            (LCDC_OVR2CLUT_GCLUT_Msk & (_UINT32_(value) << LCDC_OVR2CLUT_GCLUT_Pos)) /* Assigment of value for GCLUT in the LCDC_OVR2CLUT register */
#define LCDC_OVR2CLUT_RCLUT_Pos               _UINT32_(16)                                         /* (LCDC_OVR2CLUT) Red Color Entry Position */
#define LCDC_OVR2CLUT_RCLUT_Msk               (_UINT32_(0xFF) << LCDC_OVR2CLUT_RCLUT_Pos)          /* (LCDC_OVR2CLUT) Red Color Entry Mask */
#define LCDC_OVR2CLUT_RCLUT(value)            (LCDC_OVR2CLUT_RCLUT_Msk & (_UINT32_(value) << LCDC_OVR2CLUT_RCLUT_Pos)) /* Assigment of value for RCLUT in the LCDC_OVR2CLUT register */
#define LCDC_OVR2CLUT_ACLUT_Pos               _UINT32_(24)                                         /* (LCDC_OVR2CLUT) Alpha Color Entry Position */
#define LCDC_OVR2CLUT_ACLUT_Msk               (_UINT32_(0xFF) << LCDC_OVR2CLUT_ACLUT_Pos)          /* (LCDC_OVR2CLUT) Alpha Color Entry Mask */
#define LCDC_OVR2CLUT_ACLUT(value)            (LCDC_OVR2CLUT_ACLUT_Msk & (_UINT32_(value) << LCDC_OVR2CLUT_ACLUT_Pos)) /* Assigment of value for ACLUT in the LCDC_OVR2CLUT register */
#define LCDC_OVR2CLUT_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (LCDC_OVR2CLUT) Register Mask  */


/* -------- LCDC_HEOCLUT : (LCDC Offset: 0x1300) (R/W 32) High-End Overlay CLUT Register x -------- */
#define LCDC_HEOCLUT_RESETVALUE               _UINT32_(0x00)                                       /*  (LCDC_HEOCLUT) High-End Overlay CLUT Register x  Reset Value */

#define LCDC_HEOCLUT_BCLUT_Pos                _UINT32_(0)                                          /* (LCDC_HEOCLUT) Blue Color Entry Position */
#define LCDC_HEOCLUT_BCLUT_Msk                (_UINT32_(0xFF) << LCDC_HEOCLUT_BCLUT_Pos)           /* (LCDC_HEOCLUT) Blue Color Entry Mask */
#define LCDC_HEOCLUT_BCLUT(value)             (LCDC_HEOCLUT_BCLUT_Msk & (_UINT32_(value) << LCDC_HEOCLUT_BCLUT_Pos)) /* Assigment of value for BCLUT in the LCDC_HEOCLUT register */
#define LCDC_HEOCLUT_GCLUT_Pos                _UINT32_(8)                                          /* (LCDC_HEOCLUT) Green Color Entry Position */
#define LCDC_HEOCLUT_GCLUT_Msk                (_UINT32_(0xFF) << LCDC_HEOCLUT_GCLUT_Pos)           /* (LCDC_HEOCLUT) Green Color Entry Mask */
#define LCDC_HEOCLUT_GCLUT(value)             (LCDC_HEOCLUT_GCLUT_Msk & (_UINT32_(value) << LCDC_HEOCLUT_GCLUT_Pos)) /* Assigment of value for GCLUT in the LCDC_HEOCLUT register */
#define LCDC_HEOCLUT_RCLUT_Pos                _UINT32_(16)                                         /* (LCDC_HEOCLUT) Red Color Entry Position */
#define LCDC_HEOCLUT_RCLUT_Msk                (_UINT32_(0xFF) << LCDC_HEOCLUT_RCLUT_Pos)           /* (LCDC_HEOCLUT) Red Color Entry Mask */
#define LCDC_HEOCLUT_RCLUT(value)             (LCDC_HEOCLUT_RCLUT_Msk & (_UINT32_(value) << LCDC_HEOCLUT_RCLUT_Pos)) /* Assigment of value for RCLUT in the LCDC_HEOCLUT register */
#define LCDC_HEOCLUT_ACLUT_Pos                _UINT32_(24)                                         /* (LCDC_HEOCLUT) Alpha Color Entry Position */
#define LCDC_HEOCLUT_ACLUT_Msk                (_UINT32_(0xFF) << LCDC_HEOCLUT_ACLUT_Pos)           /* (LCDC_HEOCLUT) Alpha Color Entry Mask */
#define LCDC_HEOCLUT_ACLUT(value)             (LCDC_HEOCLUT_ACLUT_Msk & (_UINT32_(value) << LCDC_HEOCLUT_ACLUT_Pos)) /* Assigment of value for ACLUT in the LCDC_HEOCLUT register */
#define LCDC_HEOCLUT_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (LCDC_HEOCLUT) Register Mask  */


/** \brief LCDC register offsets definitions */
#define LCDC_HEOYFBA_REG_OFST          _UINT32_(0x00)      /* (LCDC_HEOYFBA) High-End Overlay Y Frame Buffer x Addr Offset */
#define LCDC_HEOCBFBA_REG_OFST         _UINT32_(0x04)      /* (LCDC_HEOCBFBA) High-End Overlay Cb Frame Buffer x Addr Offset */
#define LCDC_HEOCRFBA_REG_OFST         _UINT32_(0x08)      /* (LCDC_HEOCRFBA) High-End Overlay Cr Frame Buffer x Addr Offset */
#define LCDC_HEOHTAP10P_REG_OFST       _UINT32_(0x00)      /* (LCDC_HEOHTAP10P) High-End Overlay HXS T10 Phi Register  Offset */
#define LCDC_HEOHTAP32P_REG_OFST       _UINT32_(0x04)      /* (LCDC_HEOHTAP32P) High-End Overlay HXS T32 Phi Register  Offset */
#define LCDC_HEOVTAP10P_REG_OFST       _UINT32_(0x00)      /* (LCDC_HEOVTAP10P) High-End Overlay VXS T10 Phi Register  Offset */
#define LCDC_HEOVTAP32P_REG_OFST       _UINT32_(0x04)      /* (LCDC_HEOVTAP32P) High-End Overlay VXS T32 Phi Register  Offset */
#define LCDC_LCDCFG0_REG_OFST          _UINT32_(0x00)      /* (LCDC_LCDCFG0) Configuration Register 0 Offset */
#define LCDC_LCDCFG1_REG_OFST          _UINT32_(0x04)      /* (LCDC_LCDCFG1) Configuration Register 1 Offset */
#define LCDC_LCDCFG2_REG_OFST          _UINT32_(0x08)      /* (LCDC_LCDCFG2) Configuration Register 2 Offset */
#define LCDC_LCDCFG3_REG_OFST          _UINT32_(0x0C)      /* (LCDC_LCDCFG3) Configuration Register 3 Offset */
#define LCDC_LCDCFG4_REG_OFST          _UINT32_(0x10)      /* (LCDC_LCDCFG4) Configuration Register 4 Offset */
#define LCDC_LCDCFG5_REG_OFST          _UINT32_(0x14)      /* (LCDC_LCDCFG5) Configuration Register 5 Offset */
#define LCDC_LCDCFG6_REG_OFST          _UINT32_(0x18)      /* (LCDC_LCDCFG6) Configuration Register 6 Offset */
#define LCDC_LCDCFG7_REG_OFST          _UINT32_(0x1C)      /* (LCDC_LCDCFG7) Configuration Register 7 Offset */
#define LCDC_LCDEN_REG_OFST            _UINT32_(0x20)      /* (LCDC_LCDEN) Enable Register Offset */
#define LCDC_LCDDIS_REG_OFST           _UINT32_(0x24)      /* (LCDC_LCDDIS) Disable Register Offset */
#define LCDC_LCDSR_REG_OFST            _UINT32_(0x28)      /* (LCDC_LCDSR) Status Register Offset */
#define LCDC_LCDIER_REG_OFST           _UINT32_(0x2C)      /* (LCDC_LCDIER) Interrupt Enable Register Offset */
#define LCDC_LCDIDR_REG_OFST           _UINT32_(0x30)      /* (LCDC_LCDIDR) Interrupt Disable Register Offset */
#define LCDC_LCDIMR_REG_OFST           _UINT32_(0x34)      /* (LCDC_LCDIMR) Interrupt Mask Register Offset */
#define LCDC_LCDISR_REG_OFST           _UINT32_(0x38)      /* (LCDC_LCDISR) Interrupt Status Register Offset */
#define LCDC_ATTRE_REG_OFST            _UINT32_(0x3C)      /* (LCDC_ATTRE) Attribute Enable Register Offset */
#define LCDC_ATTRS_REG_OFST            _UINT32_(0x40)      /* (LCDC_ATTRS) Attribute Status Register Offset */
#define LCDC_BASEIER_REG_OFST          _UINT32_(0x60)      /* (LCDC_BASEIER) Base Layer Interrupt Enable Register Offset */
#define LCDC_BASEIDR_REG_OFST          _UINT32_(0x64)      /* (LCDC_BASEIDR) Base Layer Interrupt Disable Register Offset */
#define LCDC_BASEIMR_REG_OFST          _UINT32_(0x68)      /* (LCDC_BASEIMR) Base Layer Interrupt Mask Register Offset */
#define LCDC_BASEISR_REG_OFST          _UINT32_(0x6C)      /* (LCDC_BASEISR) Base Layer Interrupt Status Register Offset */
#define LCDC_BASEEN_REG_OFST           _UINT32_(0x70)      /* (LCDC_BASEEN) Base Layer Enable Register Offset */
#define LCDC_BASECLA_REG_OFST          _UINT32_(0x74)      /* (LCDC_BASECLA) Base Layer Color Table Address Register Offset */
#define LCDC_BASEFBA_REG_OFST          _UINT32_(0x78)      /* (LCDC_BASEFBA) Base Layer Frame Buffer Address Register Offset */
#define LCDC_BASECFG0_REG_OFST         _UINT32_(0x7C)      /* (LCDC_BASECFG0) Base Layer Configuration Register 0 Offset */
#define LCDC_BASECFG1_REG_OFST         _UINT32_(0x80)      /* (LCDC_BASECFG1) Base Layer Configuration Register 1 Offset */
#define LCDC_BASECFG2_REG_OFST         _UINT32_(0x84)      /* (LCDC_BASECFG2) Base Layer Configuration Register 2 Offset */
#define LCDC_BASECFG3_REG_OFST         _UINT32_(0x88)      /* (LCDC_BASECFG3) Base Layer Configuration Register 3 Offset */
#define LCDC_BASECFG4_REG_OFST         _UINT32_(0x8C)      /* (LCDC_BASECFG4) Base Layer Configuration Register 4 Offset */
#define LCDC_BASECFG5_REG_OFST         _UINT32_(0x90)      /* (LCDC_BASECFG5) Base Layer Configuration Register 5 Offset */
#define LCDC_BASECFG6_REG_OFST         _UINT32_(0x94)      /* (LCDC_BASECFG6) Base Layer Configuration Register 6 Offset */
#define LCDC_WPMR_REG_OFST             _UINT32_(0xE4)      /* (LCDC_WPMR) Write Protection Mode Register Offset */
#define LCDC_WPSR_REG_OFST             _UINT32_(0xE8)      /* (LCDC_WPSR) Write Protection Status Register Offset */
#define LCDC_OVR1IER_REG_OFST          _UINT32_(0x160)     /* (LCDC_OVR1IER) Overlay 1 Interrupt Enable Register Offset */
#define LCDC_OVR1IDR_REG_OFST          _UINT32_(0x164)     /* (LCDC_OVR1IDR) Overlay 1 Interrupt Disable Register Offset */
#define LCDC_OVR1IMR_REG_OFST          _UINT32_(0x168)     /* (LCDC_OVR1IMR) Overlay 1 Interrupt Mask Register Offset */
#define LCDC_OVR1ISR_REG_OFST          _UINT32_(0x16C)     /* (LCDC_OVR1ISR) Overlay 1 Interrupt Status Register Offset */
#define LCDC_OVR1EN_REG_OFST           _UINT32_(0x170)     /* (LCDC_OVR1EN) Overlay 1 Enable Register Offset */
#define LCDC_OVR1CLA_REG_OFST          _UINT32_(0x174)     /* (LCDC_OVR1CLA) Overlay 1 Color Table Address Register Offset */
#define LCDC_OVR1FBA_REG_OFST          _UINT32_(0x178)     /* (LCDC_OVR1FBA) Overlay 1 Frame Buffer Address Register Offset */
#define LCDC_OVR1CFG0_REG_OFST         _UINT32_(0x17C)     /* (LCDC_OVR1CFG0) Overlay 1 Configuration Register 0 Offset */
#define LCDC_OVR1CFG1_REG_OFST         _UINT32_(0x180)     /* (LCDC_OVR1CFG1) Overlay 1 Configuration Register 1 Offset */
#define LCDC_OVR1CFG2_REG_OFST         _UINT32_(0x184)     /* (LCDC_OVR1CFG2) Overlay 1 Configuration Register 2 Offset */
#define LCDC_OVR1CFG3_REG_OFST         _UINT32_(0x188)     /* (LCDC_OVR1CFG3) Overlay 1 Configuration Register 3 Offset */
#define LCDC_OVR1CFG4_REG_OFST         _UINT32_(0x18C)     /* (LCDC_OVR1CFG4) Overlay 1 Configuration Register 4 Offset */
#define LCDC_OVR1CFG5_REG_OFST         _UINT32_(0x190)     /* (LCDC_OVR1CFG5) Overlay 1 Configuration Register 5 Offset */
#define LCDC_OVR1CFG6_REG_OFST         _UINT32_(0x194)     /* (LCDC_OVR1CFG6) Overlay 1 Configuration Register 6 Offset */
#define LCDC_OVR1CFG7_REG_OFST         _UINT32_(0x198)     /* (LCDC_OVR1CFG7) Overlay 1 Configuration Register 7 Offset */
#define LCDC_OVR1CFG8_REG_OFST         _UINT32_(0x19C)     /* (LCDC_OVR1CFG8) Overlay 1 Configuration Register 8 Offset */
#define LCDC_OVR1CFG9_REG_OFST         _UINT32_(0x1A0)     /* (LCDC_OVR1CFG9) Overlay 1 Configuration Register 9 Offset */
#define LCDC_OVR2IER_REG_OFST          _UINT32_(0x260)     /* (LCDC_OVR2IER) Overlay 2 Interrupt Enable Register Offset */
#define LCDC_OVR2IDR_REG_OFST          _UINT32_(0x264)     /* (LCDC_OVR2IDR) Overlay 2 Interrupt Disable Register Offset */
#define LCDC_OVR2IMR_REG_OFST          _UINT32_(0x268)     /* (LCDC_OVR2IMR) Overlay 2 Interrupt Mask Register Offset */
#define LCDC_OVR2ISR_REG_OFST          _UINT32_(0x26C)     /* (LCDC_OVR2ISR) Overlay 2 Interrupt Status Register Offset */
#define LCDC_OVR2EN_REG_OFST           _UINT32_(0x270)     /* (LCDC_OVR2EN) Overlay 2 Enable Register Offset */
#define LCDC_OVR2CLA_REG_OFST          _UINT32_(0x274)     /* (LCDC_OVR2CLA) Overlay 2 Color Table Address Register Offset */
#define LCDC_OVR2FBA_REG_OFST          _UINT32_(0x278)     /* (LCDC_OVR2FBA) Overlay 2 Frame Buffer Address Register Offset */
#define LCDC_OVR2CFG0_REG_OFST         _UINT32_(0x27C)     /* (LCDC_OVR2CFG0) Overlay 2 Configuration Register 0 Offset */
#define LCDC_OVR2CFG1_REG_OFST         _UINT32_(0x280)     /* (LCDC_OVR2CFG1) Overlay 2 Configuration Register 1 Offset */
#define LCDC_OVR2CFG2_REG_OFST         _UINT32_(0x284)     /* (LCDC_OVR2CFG2) Overlay 2 Configuration Register 2 Offset */
#define LCDC_OVR2CFG3_REG_OFST         _UINT32_(0x288)     /* (LCDC_OVR2CFG3) Overlay 2 Configuration Register 3 Offset */
#define LCDC_OVR2CFG4_REG_OFST         _UINT32_(0x28C)     /* (LCDC_OVR2CFG4) Overlay 2 Configuration Register 4 Offset */
#define LCDC_OVR2CFG5_REG_OFST         _UINT32_(0x290)     /* (LCDC_OVR2CFG5) Overlay 2 Configuration Register 5 Offset */
#define LCDC_OVR2CFG6_REG_OFST         _UINT32_(0x294)     /* (LCDC_OVR2CFG6) Overlay 2 Configuration Register 6 Offset */
#define LCDC_OVR2CFG7_REG_OFST         _UINT32_(0x298)     /* (LCDC_OVR2CFG7) Overlay 2 Configuration Register 7 Offset */
#define LCDC_OVR2CFG8_REG_OFST         _UINT32_(0x29C)     /* (LCDC_OVR2CFG8) Overlay 2 Configuration Register 8 Offset */
#define LCDC_OVR2CFG9_REG_OFST         _UINT32_(0x2A0)     /* (LCDC_OVR2CFG9) Overlay 2 Configuration Register 9 Offset */
#define LCDC_HEOIER_REG_OFST           _UINT32_(0x360)     /* (LCDC_HEOIER) High-End Overlay Interrupt Enable Register Offset */
#define LCDC_HEOIDR_REG_OFST           _UINT32_(0x364)     /* (LCDC_HEOIDR) High-End Overlay Interrupt Disable Register Offset */
#define LCDC_HEOIMR_REG_OFST           _UINT32_(0x368)     /* (LCDC_HEOIMR) High-End Overlay Interrupt Mask Register Offset */
#define LCDC_HEOISR_REG_OFST           _UINT32_(0x36C)     /* (LCDC_HEOISR) High-End Overlay Interrupt Status Register Offset */
#define LCDC_HEOEN_REG_OFST            _UINT32_(0x370)     /* (LCDC_HEOEN) High-End Overlay Enable Register Offset */
#define LCDC_HEOCLA_REG_OFST           _UINT32_(0x374)     /* (LCDC_HEOCLA) High-End Overlay Table Address Register Offset */
#define LCDC_HEOCFG0_REG_OFST          _UINT32_(0x390)     /* (LCDC_HEOCFG0) High-End Overlay Configuration Register 0 Offset */
#define LCDC_HEOCFG1_REG_OFST          _UINT32_(0x394)     /* (LCDC_HEOCFG1) High-End Overlay Configuration Register 1 Offset */
#define LCDC_HEOCFG2_REG_OFST          _UINT32_(0x398)     /* (LCDC_HEOCFG2) High-End Overlay Configuration Register 2 Offset */
#define LCDC_HEOCFG3_REG_OFST          _UINT32_(0x39C)     /* (LCDC_HEOCFG3) High-End Overlay Configuration Register 3 Offset */
#define LCDC_HEOCFG4_REG_OFST          _UINT32_(0x3A0)     /* (LCDC_HEOCFG4) High-End Overlay Configuration Register 4 Offset */
#define LCDC_HEOCFG5_REG_OFST          _UINT32_(0x3A4)     /* (LCDC_HEOCFG5) High-End Overlay Configuration Register 5 Offset */
#define LCDC_HEOCFG6_REG_OFST          _UINT32_(0x3A8)     /* (LCDC_HEOCFG6) High-End Overlay Configuration Register 6 Offset */
#define LCDC_HEOCFG7_REG_OFST          _UINT32_(0x3AC)     /* (LCDC_HEOCFG7) High-End Overlay Configuration Register 7 Offset */
#define LCDC_HEOCFG8_REG_OFST          _UINT32_(0x3B0)     /* (LCDC_HEOCFG8) High-End Overlay Configuration Register 8 Offset */
#define LCDC_HEOCFG9_REG_OFST          _UINT32_(0x3B4)     /* (LCDC_HEOCFG9) High-End Overlay Configuration Register 9 Offset */
#define LCDC_HEOCFG10_REG_OFST         _UINT32_(0x3B8)     /* (LCDC_HEOCFG10) High-End Overlay Configuration Register 10 Offset */
#define LCDC_HEOCFG11_REG_OFST         _UINT32_(0x3BC)     /* (LCDC_HEOCFG11) High-End Overlay Configuration Register 11 Offset */
#define LCDC_HEOCFG12_REG_OFST         _UINT32_(0x3C0)     /* (LCDC_HEOCFG12) High-End Overlay Configuration Register 12 Offset */
#define LCDC_HEOCFG13_REG_OFST         _UINT32_(0x3C4)     /* (LCDC_HEOCFG13) High-End Overlay Configuration Register 13 Offset */
#define LCDC_HEOCFG14_REG_OFST         _UINT32_(0x3C8)     /* (LCDC_HEOCFG14) High-End Overlay Configuration Register 14 Offset */
#define LCDC_HEOCFG15_REG_OFST         _UINT32_(0x3CC)     /* (LCDC_HEOCFG15) High-End Overlay Configuration Register 15 Offset */
#define LCDC_HEOCFG16_REG_OFST         _UINT32_(0x3D0)     /* (LCDC_HEOCFG16) High-End Overlay Configuration Register 16 Offset */
#define LCDC_HEOCFG17_REG_OFST         _UINT32_(0x3D4)     /* (LCDC_HEOCFG17) High-End Overlay Configuration Register 17 Offset */
#define LCDC_HEOCFG18_REG_OFST         _UINT32_(0x3D8)     /* (LCDC_HEOCFG18) High-End Overlay Configuration Register 18 Offset */
#define LCDC_HEOCFG19_REG_OFST         _UINT32_(0x3DC)     /* (LCDC_HEOCFG19) High-End Overlay Configuration Register 19 Offset */
#define LCDC_HEOCFG20_REG_OFST         _UINT32_(0x3E0)     /* (LCDC_HEOCFG20) High-End Overlay Configuration Register 20 Offset */
#define LCDC_HEOCFG21_REG_OFST         _UINT32_(0x3E4)     /* (LCDC_HEOCFG21) High-End Overlay Configuration Register 21 Offset */
#define LCDC_HEOCFG22_REG_OFST         _UINT32_(0x3E8)     /* (LCDC_HEOCFG22) High-End Overlay Configuration Register 22 Offset */
#define LCDC_HEOCFG23_REG_OFST         _UINT32_(0x3EC)     /* (LCDC_HEOCFG23) High-End Overlay Configuration Register 23 Offset */
#define LCDC_HEOCFG24_REG_OFST         _UINT32_(0x3F0)     /* (LCDC_HEOCFG24) High-End Overlay Configuration Register 24 Offset */
#define LCDC_HEOCFG25_REG_OFST         _UINT32_(0x3F4)     /* (LCDC_HEOCFG25) High-End Overlay Configuration Register 25 Offset */
#define LCDC_HEOCFG26_REG_OFST         _UINT32_(0x3F8)     /* (LCDC_HEOCFG26) High-End Overlay Configuration Register 26 Offset */
#define LCDC_HEOCFG27_REG_OFST         _UINT32_(0x3FC)     /* (LCDC_HEOCFG27) High-End Overlay Configuration Register 27 Offset */
#define LCDC_HEOCFG28_REG_OFST         _UINT32_(0x400)     /* (LCDC_HEOCFG28) High-End Overlay Configuration Register 28 Offset */
#define LCDC_HEOCFG29_REG_OFST         _UINT32_(0x404)     /* (LCDC_HEOCFG29) High-End Overlay Configuration Register 29 Offset */
#define LCDC_HEOCFG30_REG_OFST         _UINT32_(0x408)     /* (LCDC_HEOCFG30) High-End Overlay Configuration Register 30 Offset */
#define LCDC_HEOCFG31_REG_OFST         _UINT32_(0x40C)     /* (LCDC_HEOCFG31) High-End Overlay Configuration Register 31 Offset */
#define LCDC_BASECLUT_REG_OFST         _UINT32_(0x700)     /* (LCDC_BASECLUT) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT0_REG_OFST        _UINT32_(0x700)     /* (LCDC_BASECLUT0) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT1_REG_OFST        _UINT32_(0x704)     /* (LCDC_BASECLUT1) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT2_REG_OFST        _UINT32_(0x708)     /* (LCDC_BASECLUT2) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT3_REG_OFST        _UINT32_(0x70C)     /* (LCDC_BASECLUT3) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT4_REG_OFST        _UINT32_(0x710)     /* (LCDC_BASECLUT4) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT5_REG_OFST        _UINT32_(0x714)     /* (LCDC_BASECLUT5) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT6_REG_OFST        _UINT32_(0x718)     /* (LCDC_BASECLUT6) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT7_REG_OFST        _UINT32_(0x71C)     /* (LCDC_BASECLUT7) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT8_REG_OFST        _UINT32_(0x720)     /* (LCDC_BASECLUT8) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT9_REG_OFST        _UINT32_(0x724)     /* (LCDC_BASECLUT9) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT10_REG_OFST       _UINT32_(0x728)     /* (LCDC_BASECLUT10) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT11_REG_OFST       _UINT32_(0x72C)     /* (LCDC_BASECLUT11) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT12_REG_OFST       _UINT32_(0x730)     /* (LCDC_BASECLUT12) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT13_REG_OFST       _UINT32_(0x734)     /* (LCDC_BASECLUT13) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT14_REG_OFST       _UINT32_(0x738)     /* (LCDC_BASECLUT14) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT15_REG_OFST       _UINT32_(0x73C)     /* (LCDC_BASECLUT15) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT16_REG_OFST       _UINT32_(0x740)     /* (LCDC_BASECLUT16) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT17_REG_OFST       _UINT32_(0x744)     /* (LCDC_BASECLUT17) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT18_REG_OFST       _UINT32_(0x748)     /* (LCDC_BASECLUT18) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT19_REG_OFST       _UINT32_(0x74C)     /* (LCDC_BASECLUT19) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT20_REG_OFST       _UINT32_(0x750)     /* (LCDC_BASECLUT20) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT21_REG_OFST       _UINT32_(0x754)     /* (LCDC_BASECLUT21) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT22_REG_OFST       _UINT32_(0x758)     /* (LCDC_BASECLUT22) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT23_REG_OFST       _UINT32_(0x75C)     /* (LCDC_BASECLUT23) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT24_REG_OFST       _UINT32_(0x760)     /* (LCDC_BASECLUT24) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT25_REG_OFST       _UINT32_(0x764)     /* (LCDC_BASECLUT25) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT26_REG_OFST       _UINT32_(0x768)     /* (LCDC_BASECLUT26) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT27_REG_OFST       _UINT32_(0x76C)     /* (LCDC_BASECLUT27) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT28_REG_OFST       _UINT32_(0x770)     /* (LCDC_BASECLUT28) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT29_REG_OFST       _UINT32_(0x774)     /* (LCDC_BASECLUT29) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT30_REG_OFST       _UINT32_(0x778)     /* (LCDC_BASECLUT30) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT31_REG_OFST       _UINT32_(0x77C)     /* (LCDC_BASECLUT31) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT32_REG_OFST       _UINT32_(0x780)     /* (LCDC_BASECLUT32) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT33_REG_OFST       _UINT32_(0x784)     /* (LCDC_BASECLUT33) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT34_REG_OFST       _UINT32_(0x788)     /* (LCDC_BASECLUT34) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT35_REG_OFST       _UINT32_(0x78C)     /* (LCDC_BASECLUT35) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT36_REG_OFST       _UINT32_(0x790)     /* (LCDC_BASECLUT36) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT37_REG_OFST       _UINT32_(0x794)     /* (LCDC_BASECLUT37) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT38_REG_OFST       _UINT32_(0x798)     /* (LCDC_BASECLUT38) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT39_REG_OFST       _UINT32_(0x79C)     /* (LCDC_BASECLUT39) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT40_REG_OFST       _UINT32_(0x7A0)     /* (LCDC_BASECLUT40) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT41_REG_OFST       _UINT32_(0x7A4)     /* (LCDC_BASECLUT41) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT42_REG_OFST       _UINT32_(0x7A8)     /* (LCDC_BASECLUT42) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT43_REG_OFST       _UINT32_(0x7AC)     /* (LCDC_BASECLUT43) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT44_REG_OFST       _UINT32_(0x7B0)     /* (LCDC_BASECLUT44) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT45_REG_OFST       _UINT32_(0x7B4)     /* (LCDC_BASECLUT45) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT46_REG_OFST       _UINT32_(0x7B8)     /* (LCDC_BASECLUT46) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT47_REG_OFST       _UINT32_(0x7BC)     /* (LCDC_BASECLUT47) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT48_REG_OFST       _UINT32_(0x7C0)     /* (LCDC_BASECLUT48) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT49_REG_OFST       _UINT32_(0x7C4)     /* (LCDC_BASECLUT49) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT50_REG_OFST       _UINT32_(0x7C8)     /* (LCDC_BASECLUT50) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT51_REG_OFST       _UINT32_(0x7CC)     /* (LCDC_BASECLUT51) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT52_REG_OFST       _UINT32_(0x7D0)     /* (LCDC_BASECLUT52) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT53_REG_OFST       _UINT32_(0x7D4)     /* (LCDC_BASECLUT53) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT54_REG_OFST       _UINT32_(0x7D8)     /* (LCDC_BASECLUT54) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT55_REG_OFST       _UINT32_(0x7DC)     /* (LCDC_BASECLUT55) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT56_REG_OFST       _UINT32_(0x7E0)     /* (LCDC_BASECLUT56) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT57_REG_OFST       _UINT32_(0x7E4)     /* (LCDC_BASECLUT57) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT58_REG_OFST       _UINT32_(0x7E8)     /* (LCDC_BASECLUT58) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT59_REG_OFST       _UINT32_(0x7EC)     /* (LCDC_BASECLUT59) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT60_REG_OFST       _UINT32_(0x7F0)     /* (LCDC_BASECLUT60) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT61_REG_OFST       _UINT32_(0x7F4)     /* (LCDC_BASECLUT61) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT62_REG_OFST       _UINT32_(0x7F8)     /* (LCDC_BASECLUT62) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT63_REG_OFST       _UINT32_(0x7FC)     /* (LCDC_BASECLUT63) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT64_REG_OFST       _UINT32_(0x800)     /* (LCDC_BASECLUT64) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT65_REG_OFST       _UINT32_(0x804)     /* (LCDC_BASECLUT65) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT66_REG_OFST       _UINT32_(0x808)     /* (LCDC_BASECLUT66) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT67_REG_OFST       _UINT32_(0x80C)     /* (LCDC_BASECLUT67) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT68_REG_OFST       _UINT32_(0x810)     /* (LCDC_BASECLUT68) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT69_REG_OFST       _UINT32_(0x814)     /* (LCDC_BASECLUT69) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT70_REG_OFST       _UINT32_(0x818)     /* (LCDC_BASECLUT70) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT71_REG_OFST       _UINT32_(0x81C)     /* (LCDC_BASECLUT71) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT72_REG_OFST       _UINT32_(0x820)     /* (LCDC_BASECLUT72) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT73_REG_OFST       _UINT32_(0x824)     /* (LCDC_BASECLUT73) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT74_REG_OFST       _UINT32_(0x828)     /* (LCDC_BASECLUT74) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT75_REG_OFST       _UINT32_(0x82C)     /* (LCDC_BASECLUT75) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT76_REG_OFST       _UINT32_(0x830)     /* (LCDC_BASECLUT76) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT77_REG_OFST       _UINT32_(0x834)     /* (LCDC_BASECLUT77) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT78_REG_OFST       _UINT32_(0x838)     /* (LCDC_BASECLUT78) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT79_REG_OFST       _UINT32_(0x83C)     /* (LCDC_BASECLUT79) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT80_REG_OFST       _UINT32_(0x840)     /* (LCDC_BASECLUT80) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT81_REG_OFST       _UINT32_(0x844)     /* (LCDC_BASECLUT81) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT82_REG_OFST       _UINT32_(0x848)     /* (LCDC_BASECLUT82) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT83_REG_OFST       _UINT32_(0x84C)     /* (LCDC_BASECLUT83) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT84_REG_OFST       _UINT32_(0x850)     /* (LCDC_BASECLUT84) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT85_REG_OFST       _UINT32_(0x854)     /* (LCDC_BASECLUT85) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT86_REG_OFST       _UINT32_(0x858)     /* (LCDC_BASECLUT86) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT87_REG_OFST       _UINT32_(0x85C)     /* (LCDC_BASECLUT87) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT88_REG_OFST       _UINT32_(0x860)     /* (LCDC_BASECLUT88) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT89_REG_OFST       _UINT32_(0x864)     /* (LCDC_BASECLUT89) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT90_REG_OFST       _UINT32_(0x868)     /* (LCDC_BASECLUT90) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT91_REG_OFST       _UINT32_(0x86C)     /* (LCDC_BASECLUT91) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT92_REG_OFST       _UINT32_(0x870)     /* (LCDC_BASECLUT92) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT93_REG_OFST       _UINT32_(0x874)     /* (LCDC_BASECLUT93) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT94_REG_OFST       _UINT32_(0x878)     /* (LCDC_BASECLUT94) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT95_REG_OFST       _UINT32_(0x87C)     /* (LCDC_BASECLUT95) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT96_REG_OFST       _UINT32_(0x880)     /* (LCDC_BASECLUT96) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT97_REG_OFST       _UINT32_(0x884)     /* (LCDC_BASECLUT97) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT98_REG_OFST       _UINT32_(0x888)     /* (LCDC_BASECLUT98) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT99_REG_OFST       _UINT32_(0x88C)     /* (LCDC_BASECLUT99) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT100_REG_OFST      _UINT32_(0x890)     /* (LCDC_BASECLUT100) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT101_REG_OFST      _UINT32_(0x894)     /* (LCDC_BASECLUT101) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT102_REG_OFST      _UINT32_(0x898)     /* (LCDC_BASECLUT102) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT103_REG_OFST      _UINT32_(0x89C)     /* (LCDC_BASECLUT103) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT104_REG_OFST      _UINT32_(0x8A0)     /* (LCDC_BASECLUT104) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT105_REG_OFST      _UINT32_(0x8A4)     /* (LCDC_BASECLUT105) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT106_REG_OFST      _UINT32_(0x8A8)     /* (LCDC_BASECLUT106) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT107_REG_OFST      _UINT32_(0x8AC)     /* (LCDC_BASECLUT107) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT108_REG_OFST      _UINT32_(0x8B0)     /* (LCDC_BASECLUT108) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT109_REG_OFST      _UINT32_(0x8B4)     /* (LCDC_BASECLUT109) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT110_REG_OFST      _UINT32_(0x8B8)     /* (LCDC_BASECLUT110) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT111_REG_OFST      _UINT32_(0x8BC)     /* (LCDC_BASECLUT111) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT112_REG_OFST      _UINT32_(0x8C0)     /* (LCDC_BASECLUT112) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT113_REG_OFST      _UINT32_(0x8C4)     /* (LCDC_BASECLUT113) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT114_REG_OFST      _UINT32_(0x8C8)     /* (LCDC_BASECLUT114) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT115_REG_OFST      _UINT32_(0x8CC)     /* (LCDC_BASECLUT115) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT116_REG_OFST      _UINT32_(0x8D0)     /* (LCDC_BASECLUT116) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT117_REG_OFST      _UINT32_(0x8D4)     /* (LCDC_BASECLUT117) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT118_REG_OFST      _UINT32_(0x8D8)     /* (LCDC_BASECLUT118) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT119_REG_OFST      _UINT32_(0x8DC)     /* (LCDC_BASECLUT119) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT120_REG_OFST      _UINT32_(0x8E0)     /* (LCDC_BASECLUT120) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT121_REG_OFST      _UINT32_(0x8E4)     /* (LCDC_BASECLUT121) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT122_REG_OFST      _UINT32_(0x8E8)     /* (LCDC_BASECLUT122) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT123_REG_OFST      _UINT32_(0x8EC)     /* (LCDC_BASECLUT123) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT124_REG_OFST      _UINT32_(0x8F0)     /* (LCDC_BASECLUT124) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT125_REG_OFST      _UINT32_(0x8F4)     /* (LCDC_BASECLUT125) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT126_REG_OFST      _UINT32_(0x8F8)     /* (LCDC_BASECLUT126) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT127_REG_OFST      _UINT32_(0x8FC)     /* (LCDC_BASECLUT127) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT128_REG_OFST      _UINT32_(0x900)     /* (LCDC_BASECLUT128) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT129_REG_OFST      _UINT32_(0x904)     /* (LCDC_BASECLUT129) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT130_REG_OFST      _UINT32_(0x908)     /* (LCDC_BASECLUT130) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT131_REG_OFST      _UINT32_(0x90C)     /* (LCDC_BASECLUT131) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT132_REG_OFST      _UINT32_(0x910)     /* (LCDC_BASECLUT132) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT133_REG_OFST      _UINT32_(0x914)     /* (LCDC_BASECLUT133) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT134_REG_OFST      _UINT32_(0x918)     /* (LCDC_BASECLUT134) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT135_REG_OFST      _UINT32_(0x91C)     /* (LCDC_BASECLUT135) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT136_REG_OFST      _UINT32_(0x920)     /* (LCDC_BASECLUT136) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT137_REG_OFST      _UINT32_(0x924)     /* (LCDC_BASECLUT137) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT138_REG_OFST      _UINT32_(0x928)     /* (LCDC_BASECLUT138) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT139_REG_OFST      _UINT32_(0x92C)     /* (LCDC_BASECLUT139) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT140_REG_OFST      _UINT32_(0x930)     /* (LCDC_BASECLUT140) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT141_REG_OFST      _UINT32_(0x934)     /* (LCDC_BASECLUT141) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT142_REG_OFST      _UINT32_(0x938)     /* (LCDC_BASECLUT142) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT143_REG_OFST      _UINT32_(0x93C)     /* (LCDC_BASECLUT143) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT144_REG_OFST      _UINT32_(0x940)     /* (LCDC_BASECLUT144) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT145_REG_OFST      _UINT32_(0x944)     /* (LCDC_BASECLUT145) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT146_REG_OFST      _UINT32_(0x948)     /* (LCDC_BASECLUT146) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT147_REG_OFST      _UINT32_(0x94C)     /* (LCDC_BASECLUT147) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT148_REG_OFST      _UINT32_(0x950)     /* (LCDC_BASECLUT148) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT149_REG_OFST      _UINT32_(0x954)     /* (LCDC_BASECLUT149) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT150_REG_OFST      _UINT32_(0x958)     /* (LCDC_BASECLUT150) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT151_REG_OFST      _UINT32_(0x95C)     /* (LCDC_BASECLUT151) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT152_REG_OFST      _UINT32_(0x960)     /* (LCDC_BASECLUT152) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT153_REG_OFST      _UINT32_(0x964)     /* (LCDC_BASECLUT153) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT154_REG_OFST      _UINT32_(0x968)     /* (LCDC_BASECLUT154) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT155_REG_OFST      _UINT32_(0x96C)     /* (LCDC_BASECLUT155) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT156_REG_OFST      _UINT32_(0x970)     /* (LCDC_BASECLUT156) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT157_REG_OFST      _UINT32_(0x974)     /* (LCDC_BASECLUT157) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT158_REG_OFST      _UINT32_(0x978)     /* (LCDC_BASECLUT158) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT159_REG_OFST      _UINT32_(0x97C)     /* (LCDC_BASECLUT159) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT160_REG_OFST      _UINT32_(0x980)     /* (LCDC_BASECLUT160) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT161_REG_OFST      _UINT32_(0x984)     /* (LCDC_BASECLUT161) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT162_REG_OFST      _UINT32_(0x988)     /* (LCDC_BASECLUT162) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT163_REG_OFST      _UINT32_(0x98C)     /* (LCDC_BASECLUT163) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT164_REG_OFST      _UINT32_(0x990)     /* (LCDC_BASECLUT164) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT165_REG_OFST      _UINT32_(0x994)     /* (LCDC_BASECLUT165) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT166_REG_OFST      _UINT32_(0x998)     /* (LCDC_BASECLUT166) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT167_REG_OFST      _UINT32_(0x99C)     /* (LCDC_BASECLUT167) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT168_REG_OFST      _UINT32_(0x9A0)     /* (LCDC_BASECLUT168) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT169_REG_OFST      _UINT32_(0x9A4)     /* (LCDC_BASECLUT169) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT170_REG_OFST      _UINT32_(0x9A8)     /* (LCDC_BASECLUT170) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT171_REG_OFST      _UINT32_(0x9AC)     /* (LCDC_BASECLUT171) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT172_REG_OFST      _UINT32_(0x9B0)     /* (LCDC_BASECLUT172) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT173_REG_OFST      _UINT32_(0x9B4)     /* (LCDC_BASECLUT173) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT174_REG_OFST      _UINT32_(0x9B8)     /* (LCDC_BASECLUT174) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT175_REG_OFST      _UINT32_(0x9BC)     /* (LCDC_BASECLUT175) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT176_REG_OFST      _UINT32_(0x9C0)     /* (LCDC_BASECLUT176) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT177_REG_OFST      _UINT32_(0x9C4)     /* (LCDC_BASECLUT177) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT178_REG_OFST      _UINT32_(0x9C8)     /* (LCDC_BASECLUT178) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT179_REG_OFST      _UINT32_(0x9CC)     /* (LCDC_BASECLUT179) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT180_REG_OFST      _UINT32_(0x9D0)     /* (LCDC_BASECLUT180) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT181_REG_OFST      _UINT32_(0x9D4)     /* (LCDC_BASECLUT181) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT182_REG_OFST      _UINT32_(0x9D8)     /* (LCDC_BASECLUT182) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT183_REG_OFST      _UINT32_(0x9DC)     /* (LCDC_BASECLUT183) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT184_REG_OFST      _UINT32_(0x9E0)     /* (LCDC_BASECLUT184) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT185_REG_OFST      _UINT32_(0x9E4)     /* (LCDC_BASECLUT185) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT186_REG_OFST      _UINT32_(0x9E8)     /* (LCDC_BASECLUT186) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT187_REG_OFST      _UINT32_(0x9EC)     /* (LCDC_BASECLUT187) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT188_REG_OFST      _UINT32_(0x9F0)     /* (LCDC_BASECLUT188) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT189_REG_OFST      _UINT32_(0x9F4)     /* (LCDC_BASECLUT189) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT190_REG_OFST      _UINT32_(0x9F8)     /* (LCDC_BASECLUT190) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT191_REG_OFST      _UINT32_(0x9FC)     /* (LCDC_BASECLUT191) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT192_REG_OFST      _UINT32_(0xA00)     /* (LCDC_BASECLUT192) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT193_REG_OFST      _UINT32_(0xA04)     /* (LCDC_BASECLUT193) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT194_REG_OFST      _UINT32_(0xA08)     /* (LCDC_BASECLUT194) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT195_REG_OFST      _UINT32_(0xA0C)     /* (LCDC_BASECLUT195) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT196_REG_OFST      _UINT32_(0xA10)     /* (LCDC_BASECLUT196) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT197_REG_OFST      _UINT32_(0xA14)     /* (LCDC_BASECLUT197) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT198_REG_OFST      _UINT32_(0xA18)     /* (LCDC_BASECLUT198) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT199_REG_OFST      _UINT32_(0xA1C)     /* (LCDC_BASECLUT199) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT200_REG_OFST      _UINT32_(0xA20)     /* (LCDC_BASECLUT200) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT201_REG_OFST      _UINT32_(0xA24)     /* (LCDC_BASECLUT201) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT202_REG_OFST      _UINT32_(0xA28)     /* (LCDC_BASECLUT202) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT203_REG_OFST      _UINT32_(0xA2C)     /* (LCDC_BASECLUT203) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT204_REG_OFST      _UINT32_(0xA30)     /* (LCDC_BASECLUT204) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT205_REG_OFST      _UINT32_(0xA34)     /* (LCDC_BASECLUT205) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT206_REG_OFST      _UINT32_(0xA38)     /* (LCDC_BASECLUT206) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT207_REG_OFST      _UINT32_(0xA3C)     /* (LCDC_BASECLUT207) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT208_REG_OFST      _UINT32_(0xA40)     /* (LCDC_BASECLUT208) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT209_REG_OFST      _UINT32_(0xA44)     /* (LCDC_BASECLUT209) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT210_REG_OFST      _UINT32_(0xA48)     /* (LCDC_BASECLUT210) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT211_REG_OFST      _UINT32_(0xA4C)     /* (LCDC_BASECLUT211) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT212_REG_OFST      _UINT32_(0xA50)     /* (LCDC_BASECLUT212) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT213_REG_OFST      _UINT32_(0xA54)     /* (LCDC_BASECLUT213) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT214_REG_OFST      _UINT32_(0xA58)     /* (LCDC_BASECLUT214) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT215_REG_OFST      _UINT32_(0xA5C)     /* (LCDC_BASECLUT215) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT216_REG_OFST      _UINT32_(0xA60)     /* (LCDC_BASECLUT216) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT217_REG_OFST      _UINT32_(0xA64)     /* (LCDC_BASECLUT217) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT218_REG_OFST      _UINT32_(0xA68)     /* (LCDC_BASECLUT218) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT219_REG_OFST      _UINT32_(0xA6C)     /* (LCDC_BASECLUT219) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT220_REG_OFST      _UINT32_(0xA70)     /* (LCDC_BASECLUT220) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT221_REG_OFST      _UINT32_(0xA74)     /* (LCDC_BASECLUT221) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT222_REG_OFST      _UINT32_(0xA78)     /* (LCDC_BASECLUT222) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT223_REG_OFST      _UINT32_(0xA7C)     /* (LCDC_BASECLUT223) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT224_REG_OFST      _UINT32_(0xA80)     /* (LCDC_BASECLUT224) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT225_REG_OFST      _UINT32_(0xA84)     /* (LCDC_BASECLUT225) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT226_REG_OFST      _UINT32_(0xA88)     /* (LCDC_BASECLUT226) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT227_REG_OFST      _UINT32_(0xA8C)     /* (LCDC_BASECLUT227) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT228_REG_OFST      _UINT32_(0xA90)     /* (LCDC_BASECLUT228) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT229_REG_OFST      _UINT32_(0xA94)     /* (LCDC_BASECLUT229) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT230_REG_OFST      _UINT32_(0xA98)     /* (LCDC_BASECLUT230) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT231_REG_OFST      _UINT32_(0xA9C)     /* (LCDC_BASECLUT231) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT232_REG_OFST      _UINT32_(0xAA0)     /* (LCDC_BASECLUT232) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT233_REG_OFST      _UINT32_(0xAA4)     /* (LCDC_BASECLUT233) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT234_REG_OFST      _UINT32_(0xAA8)     /* (LCDC_BASECLUT234) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT235_REG_OFST      _UINT32_(0xAAC)     /* (LCDC_BASECLUT235) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT236_REG_OFST      _UINT32_(0xAB0)     /* (LCDC_BASECLUT236) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT237_REG_OFST      _UINT32_(0xAB4)     /* (LCDC_BASECLUT237) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT238_REG_OFST      _UINT32_(0xAB8)     /* (LCDC_BASECLUT238) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT239_REG_OFST      _UINT32_(0xABC)     /* (LCDC_BASECLUT239) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT240_REG_OFST      _UINT32_(0xAC0)     /* (LCDC_BASECLUT240) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT241_REG_OFST      _UINT32_(0xAC4)     /* (LCDC_BASECLUT241) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT242_REG_OFST      _UINT32_(0xAC8)     /* (LCDC_BASECLUT242) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT243_REG_OFST      _UINT32_(0xACC)     /* (LCDC_BASECLUT243) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT244_REG_OFST      _UINT32_(0xAD0)     /* (LCDC_BASECLUT244) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT245_REG_OFST      _UINT32_(0xAD4)     /* (LCDC_BASECLUT245) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT246_REG_OFST      _UINT32_(0xAD8)     /* (LCDC_BASECLUT246) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT247_REG_OFST      _UINT32_(0xADC)     /* (LCDC_BASECLUT247) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT248_REG_OFST      _UINT32_(0xAE0)     /* (LCDC_BASECLUT248) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT249_REG_OFST      _UINT32_(0xAE4)     /* (LCDC_BASECLUT249) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT250_REG_OFST      _UINT32_(0xAE8)     /* (LCDC_BASECLUT250) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT251_REG_OFST      _UINT32_(0xAEC)     /* (LCDC_BASECLUT251) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT252_REG_OFST      _UINT32_(0xAF0)     /* (LCDC_BASECLUT252) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT253_REG_OFST      _UINT32_(0xAF4)     /* (LCDC_BASECLUT253) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT254_REG_OFST      _UINT32_(0xAF8)     /* (LCDC_BASECLUT254) Base Layer CLUT Register x Offset */
#define LCDC_BASECLUT255_REG_OFST      _UINT32_(0xAFC)     /* (LCDC_BASECLUT255) Base Layer CLUT Register x Offset */
#define LCDC_OVR1CLUT_REG_OFST         _UINT32_(0xB00)     /* (LCDC_OVR1CLUT) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT0_REG_OFST        _UINT32_(0xB00)     /* (LCDC_OVR1CLUT0) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT1_REG_OFST        _UINT32_(0xB04)     /* (LCDC_OVR1CLUT1) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT2_REG_OFST        _UINT32_(0xB08)     /* (LCDC_OVR1CLUT2) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT3_REG_OFST        _UINT32_(0xB0C)     /* (LCDC_OVR1CLUT3) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT4_REG_OFST        _UINT32_(0xB10)     /* (LCDC_OVR1CLUT4) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT5_REG_OFST        _UINT32_(0xB14)     /* (LCDC_OVR1CLUT5) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT6_REG_OFST        _UINT32_(0xB18)     /* (LCDC_OVR1CLUT6) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT7_REG_OFST        _UINT32_(0xB1C)     /* (LCDC_OVR1CLUT7) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT8_REG_OFST        _UINT32_(0xB20)     /* (LCDC_OVR1CLUT8) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT9_REG_OFST        _UINT32_(0xB24)     /* (LCDC_OVR1CLUT9) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT10_REG_OFST       _UINT32_(0xB28)     /* (LCDC_OVR1CLUT10) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT11_REG_OFST       _UINT32_(0xB2C)     /* (LCDC_OVR1CLUT11) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT12_REG_OFST       _UINT32_(0xB30)     /* (LCDC_OVR1CLUT12) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT13_REG_OFST       _UINT32_(0xB34)     /* (LCDC_OVR1CLUT13) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT14_REG_OFST       _UINT32_(0xB38)     /* (LCDC_OVR1CLUT14) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT15_REG_OFST       _UINT32_(0xB3C)     /* (LCDC_OVR1CLUT15) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT16_REG_OFST       _UINT32_(0xB40)     /* (LCDC_OVR1CLUT16) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT17_REG_OFST       _UINT32_(0xB44)     /* (LCDC_OVR1CLUT17) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT18_REG_OFST       _UINT32_(0xB48)     /* (LCDC_OVR1CLUT18) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT19_REG_OFST       _UINT32_(0xB4C)     /* (LCDC_OVR1CLUT19) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT20_REG_OFST       _UINT32_(0xB50)     /* (LCDC_OVR1CLUT20) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT21_REG_OFST       _UINT32_(0xB54)     /* (LCDC_OVR1CLUT21) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT22_REG_OFST       _UINT32_(0xB58)     /* (LCDC_OVR1CLUT22) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT23_REG_OFST       _UINT32_(0xB5C)     /* (LCDC_OVR1CLUT23) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT24_REG_OFST       _UINT32_(0xB60)     /* (LCDC_OVR1CLUT24) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT25_REG_OFST       _UINT32_(0xB64)     /* (LCDC_OVR1CLUT25) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT26_REG_OFST       _UINT32_(0xB68)     /* (LCDC_OVR1CLUT26) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT27_REG_OFST       _UINT32_(0xB6C)     /* (LCDC_OVR1CLUT27) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT28_REG_OFST       _UINT32_(0xB70)     /* (LCDC_OVR1CLUT28) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT29_REG_OFST       _UINT32_(0xB74)     /* (LCDC_OVR1CLUT29) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT30_REG_OFST       _UINT32_(0xB78)     /* (LCDC_OVR1CLUT30) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT31_REG_OFST       _UINT32_(0xB7C)     /* (LCDC_OVR1CLUT31) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT32_REG_OFST       _UINT32_(0xB80)     /* (LCDC_OVR1CLUT32) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT33_REG_OFST       _UINT32_(0xB84)     /* (LCDC_OVR1CLUT33) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT34_REG_OFST       _UINT32_(0xB88)     /* (LCDC_OVR1CLUT34) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT35_REG_OFST       _UINT32_(0xB8C)     /* (LCDC_OVR1CLUT35) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT36_REG_OFST       _UINT32_(0xB90)     /* (LCDC_OVR1CLUT36) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT37_REG_OFST       _UINT32_(0xB94)     /* (LCDC_OVR1CLUT37) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT38_REG_OFST       _UINT32_(0xB98)     /* (LCDC_OVR1CLUT38) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT39_REG_OFST       _UINT32_(0xB9C)     /* (LCDC_OVR1CLUT39) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT40_REG_OFST       _UINT32_(0xBA0)     /* (LCDC_OVR1CLUT40) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT41_REG_OFST       _UINT32_(0xBA4)     /* (LCDC_OVR1CLUT41) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT42_REG_OFST       _UINT32_(0xBA8)     /* (LCDC_OVR1CLUT42) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT43_REG_OFST       _UINT32_(0xBAC)     /* (LCDC_OVR1CLUT43) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT44_REG_OFST       _UINT32_(0xBB0)     /* (LCDC_OVR1CLUT44) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT45_REG_OFST       _UINT32_(0xBB4)     /* (LCDC_OVR1CLUT45) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT46_REG_OFST       _UINT32_(0xBB8)     /* (LCDC_OVR1CLUT46) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT47_REG_OFST       _UINT32_(0xBBC)     /* (LCDC_OVR1CLUT47) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT48_REG_OFST       _UINT32_(0xBC0)     /* (LCDC_OVR1CLUT48) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT49_REG_OFST       _UINT32_(0xBC4)     /* (LCDC_OVR1CLUT49) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT50_REG_OFST       _UINT32_(0xBC8)     /* (LCDC_OVR1CLUT50) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT51_REG_OFST       _UINT32_(0xBCC)     /* (LCDC_OVR1CLUT51) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT52_REG_OFST       _UINT32_(0xBD0)     /* (LCDC_OVR1CLUT52) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT53_REG_OFST       _UINT32_(0xBD4)     /* (LCDC_OVR1CLUT53) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT54_REG_OFST       _UINT32_(0xBD8)     /* (LCDC_OVR1CLUT54) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT55_REG_OFST       _UINT32_(0xBDC)     /* (LCDC_OVR1CLUT55) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT56_REG_OFST       _UINT32_(0xBE0)     /* (LCDC_OVR1CLUT56) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT57_REG_OFST       _UINT32_(0xBE4)     /* (LCDC_OVR1CLUT57) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT58_REG_OFST       _UINT32_(0xBE8)     /* (LCDC_OVR1CLUT58) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT59_REG_OFST       _UINT32_(0xBEC)     /* (LCDC_OVR1CLUT59) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT60_REG_OFST       _UINT32_(0xBF0)     /* (LCDC_OVR1CLUT60) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT61_REG_OFST       _UINT32_(0xBF4)     /* (LCDC_OVR1CLUT61) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT62_REG_OFST       _UINT32_(0xBF8)     /* (LCDC_OVR1CLUT62) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT63_REG_OFST       _UINT32_(0xBFC)     /* (LCDC_OVR1CLUT63) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT64_REG_OFST       _UINT32_(0xC00)     /* (LCDC_OVR1CLUT64) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT65_REG_OFST       _UINT32_(0xC04)     /* (LCDC_OVR1CLUT65) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT66_REG_OFST       _UINT32_(0xC08)     /* (LCDC_OVR1CLUT66) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT67_REG_OFST       _UINT32_(0xC0C)     /* (LCDC_OVR1CLUT67) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT68_REG_OFST       _UINT32_(0xC10)     /* (LCDC_OVR1CLUT68) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT69_REG_OFST       _UINT32_(0xC14)     /* (LCDC_OVR1CLUT69) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT70_REG_OFST       _UINT32_(0xC18)     /* (LCDC_OVR1CLUT70) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT71_REG_OFST       _UINT32_(0xC1C)     /* (LCDC_OVR1CLUT71) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT72_REG_OFST       _UINT32_(0xC20)     /* (LCDC_OVR1CLUT72) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT73_REG_OFST       _UINT32_(0xC24)     /* (LCDC_OVR1CLUT73) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT74_REG_OFST       _UINT32_(0xC28)     /* (LCDC_OVR1CLUT74) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT75_REG_OFST       _UINT32_(0xC2C)     /* (LCDC_OVR1CLUT75) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT76_REG_OFST       _UINT32_(0xC30)     /* (LCDC_OVR1CLUT76) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT77_REG_OFST       _UINT32_(0xC34)     /* (LCDC_OVR1CLUT77) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT78_REG_OFST       _UINT32_(0xC38)     /* (LCDC_OVR1CLUT78) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT79_REG_OFST       _UINT32_(0xC3C)     /* (LCDC_OVR1CLUT79) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT80_REG_OFST       _UINT32_(0xC40)     /* (LCDC_OVR1CLUT80) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT81_REG_OFST       _UINT32_(0xC44)     /* (LCDC_OVR1CLUT81) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT82_REG_OFST       _UINT32_(0xC48)     /* (LCDC_OVR1CLUT82) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT83_REG_OFST       _UINT32_(0xC4C)     /* (LCDC_OVR1CLUT83) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT84_REG_OFST       _UINT32_(0xC50)     /* (LCDC_OVR1CLUT84) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT85_REG_OFST       _UINT32_(0xC54)     /* (LCDC_OVR1CLUT85) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT86_REG_OFST       _UINT32_(0xC58)     /* (LCDC_OVR1CLUT86) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT87_REG_OFST       _UINT32_(0xC5C)     /* (LCDC_OVR1CLUT87) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT88_REG_OFST       _UINT32_(0xC60)     /* (LCDC_OVR1CLUT88) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT89_REG_OFST       _UINT32_(0xC64)     /* (LCDC_OVR1CLUT89) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT90_REG_OFST       _UINT32_(0xC68)     /* (LCDC_OVR1CLUT90) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT91_REG_OFST       _UINT32_(0xC6C)     /* (LCDC_OVR1CLUT91) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT92_REG_OFST       _UINT32_(0xC70)     /* (LCDC_OVR1CLUT92) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT93_REG_OFST       _UINT32_(0xC74)     /* (LCDC_OVR1CLUT93) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT94_REG_OFST       _UINT32_(0xC78)     /* (LCDC_OVR1CLUT94) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT95_REG_OFST       _UINT32_(0xC7C)     /* (LCDC_OVR1CLUT95) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT96_REG_OFST       _UINT32_(0xC80)     /* (LCDC_OVR1CLUT96) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT97_REG_OFST       _UINT32_(0xC84)     /* (LCDC_OVR1CLUT97) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT98_REG_OFST       _UINT32_(0xC88)     /* (LCDC_OVR1CLUT98) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT99_REG_OFST       _UINT32_(0xC8C)     /* (LCDC_OVR1CLUT99) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT100_REG_OFST      _UINT32_(0xC90)     /* (LCDC_OVR1CLUT100) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT101_REG_OFST      _UINT32_(0xC94)     /* (LCDC_OVR1CLUT101) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT102_REG_OFST      _UINT32_(0xC98)     /* (LCDC_OVR1CLUT102) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT103_REG_OFST      _UINT32_(0xC9C)     /* (LCDC_OVR1CLUT103) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT104_REG_OFST      _UINT32_(0xCA0)     /* (LCDC_OVR1CLUT104) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT105_REG_OFST      _UINT32_(0xCA4)     /* (LCDC_OVR1CLUT105) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT106_REG_OFST      _UINT32_(0xCA8)     /* (LCDC_OVR1CLUT106) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT107_REG_OFST      _UINT32_(0xCAC)     /* (LCDC_OVR1CLUT107) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT108_REG_OFST      _UINT32_(0xCB0)     /* (LCDC_OVR1CLUT108) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT109_REG_OFST      _UINT32_(0xCB4)     /* (LCDC_OVR1CLUT109) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT110_REG_OFST      _UINT32_(0xCB8)     /* (LCDC_OVR1CLUT110) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT111_REG_OFST      _UINT32_(0xCBC)     /* (LCDC_OVR1CLUT111) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT112_REG_OFST      _UINT32_(0xCC0)     /* (LCDC_OVR1CLUT112) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT113_REG_OFST      _UINT32_(0xCC4)     /* (LCDC_OVR1CLUT113) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT114_REG_OFST      _UINT32_(0xCC8)     /* (LCDC_OVR1CLUT114) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT115_REG_OFST      _UINT32_(0xCCC)     /* (LCDC_OVR1CLUT115) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT116_REG_OFST      _UINT32_(0xCD0)     /* (LCDC_OVR1CLUT116) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT117_REG_OFST      _UINT32_(0xCD4)     /* (LCDC_OVR1CLUT117) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT118_REG_OFST      _UINT32_(0xCD8)     /* (LCDC_OVR1CLUT118) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT119_REG_OFST      _UINT32_(0xCDC)     /* (LCDC_OVR1CLUT119) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT120_REG_OFST      _UINT32_(0xCE0)     /* (LCDC_OVR1CLUT120) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT121_REG_OFST      _UINT32_(0xCE4)     /* (LCDC_OVR1CLUT121) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT122_REG_OFST      _UINT32_(0xCE8)     /* (LCDC_OVR1CLUT122) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT123_REG_OFST      _UINT32_(0xCEC)     /* (LCDC_OVR1CLUT123) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT124_REG_OFST      _UINT32_(0xCF0)     /* (LCDC_OVR1CLUT124) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT125_REG_OFST      _UINT32_(0xCF4)     /* (LCDC_OVR1CLUT125) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT126_REG_OFST      _UINT32_(0xCF8)     /* (LCDC_OVR1CLUT126) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT127_REG_OFST      _UINT32_(0xCFC)     /* (LCDC_OVR1CLUT127) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT128_REG_OFST      _UINT32_(0xD00)     /* (LCDC_OVR1CLUT128) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT129_REG_OFST      _UINT32_(0xD04)     /* (LCDC_OVR1CLUT129) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT130_REG_OFST      _UINT32_(0xD08)     /* (LCDC_OVR1CLUT130) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT131_REG_OFST      _UINT32_(0xD0C)     /* (LCDC_OVR1CLUT131) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT132_REG_OFST      _UINT32_(0xD10)     /* (LCDC_OVR1CLUT132) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT133_REG_OFST      _UINT32_(0xD14)     /* (LCDC_OVR1CLUT133) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT134_REG_OFST      _UINT32_(0xD18)     /* (LCDC_OVR1CLUT134) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT135_REG_OFST      _UINT32_(0xD1C)     /* (LCDC_OVR1CLUT135) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT136_REG_OFST      _UINT32_(0xD20)     /* (LCDC_OVR1CLUT136) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT137_REG_OFST      _UINT32_(0xD24)     /* (LCDC_OVR1CLUT137) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT138_REG_OFST      _UINT32_(0xD28)     /* (LCDC_OVR1CLUT138) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT139_REG_OFST      _UINT32_(0xD2C)     /* (LCDC_OVR1CLUT139) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT140_REG_OFST      _UINT32_(0xD30)     /* (LCDC_OVR1CLUT140) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT141_REG_OFST      _UINT32_(0xD34)     /* (LCDC_OVR1CLUT141) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT142_REG_OFST      _UINT32_(0xD38)     /* (LCDC_OVR1CLUT142) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT143_REG_OFST      _UINT32_(0xD3C)     /* (LCDC_OVR1CLUT143) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT144_REG_OFST      _UINT32_(0xD40)     /* (LCDC_OVR1CLUT144) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT145_REG_OFST      _UINT32_(0xD44)     /* (LCDC_OVR1CLUT145) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT146_REG_OFST      _UINT32_(0xD48)     /* (LCDC_OVR1CLUT146) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT147_REG_OFST      _UINT32_(0xD4C)     /* (LCDC_OVR1CLUT147) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT148_REG_OFST      _UINT32_(0xD50)     /* (LCDC_OVR1CLUT148) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT149_REG_OFST      _UINT32_(0xD54)     /* (LCDC_OVR1CLUT149) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT150_REG_OFST      _UINT32_(0xD58)     /* (LCDC_OVR1CLUT150) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT151_REG_OFST      _UINT32_(0xD5C)     /* (LCDC_OVR1CLUT151) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT152_REG_OFST      _UINT32_(0xD60)     /* (LCDC_OVR1CLUT152) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT153_REG_OFST      _UINT32_(0xD64)     /* (LCDC_OVR1CLUT153) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT154_REG_OFST      _UINT32_(0xD68)     /* (LCDC_OVR1CLUT154) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT155_REG_OFST      _UINT32_(0xD6C)     /* (LCDC_OVR1CLUT155) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT156_REG_OFST      _UINT32_(0xD70)     /* (LCDC_OVR1CLUT156) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT157_REG_OFST      _UINT32_(0xD74)     /* (LCDC_OVR1CLUT157) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT158_REG_OFST      _UINT32_(0xD78)     /* (LCDC_OVR1CLUT158) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT159_REG_OFST      _UINT32_(0xD7C)     /* (LCDC_OVR1CLUT159) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT160_REG_OFST      _UINT32_(0xD80)     /* (LCDC_OVR1CLUT160) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT161_REG_OFST      _UINT32_(0xD84)     /* (LCDC_OVR1CLUT161) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT162_REG_OFST      _UINT32_(0xD88)     /* (LCDC_OVR1CLUT162) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT163_REG_OFST      _UINT32_(0xD8C)     /* (LCDC_OVR1CLUT163) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT164_REG_OFST      _UINT32_(0xD90)     /* (LCDC_OVR1CLUT164) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT165_REG_OFST      _UINT32_(0xD94)     /* (LCDC_OVR1CLUT165) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT166_REG_OFST      _UINT32_(0xD98)     /* (LCDC_OVR1CLUT166) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT167_REG_OFST      _UINT32_(0xD9C)     /* (LCDC_OVR1CLUT167) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT168_REG_OFST      _UINT32_(0xDA0)     /* (LCDC_OVR1CLUT168) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT169_REG_OFST      _UINT32_(0xDA4)     /* (LCDC_OVR1CLUT169) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT170_REG_OFST      _UINT32_(0xDA8)     /* (LCDC_OVR1CLUT170) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT171_REG_OFST      _UINT32_(0xDAC)     /* (LCDC_OVR1CLUT171) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT172_REG_OFST      _UINT32_(0xDB0)     /* (LCDC_OVR1CLUT172) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT173_REG_OFST      _UINT32_(0xDB4)     /* (LCDC_OVR1CLUT173) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT174_REG_OFST      _UINT32_(0xDB8)     /* (LCDC_OVR1CLUT174) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT175_REG_OFST      _UINT32_(0xDBC)     /* (LCDC_OVR1CLUT175) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT176_REG_OFST      _UINT32_(0xDC0)     /* (LCDC_OVR1CLUT176) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT177_REG_OFST      _UINT32_(0xDC4)     /* (LCDC_OVR1CLUT177) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT178_REG_OFST      _UINT32_(0xDC8)     /* (LCDC_OVR1CLUT178) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT179_REG_OFST      _UINT32_(0xDCC)     /* (LCDC_OVR1CLUT179) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT180_REG_OFST      _UINT32_(0xDD0)     /* (LCDC_OVR1CLUT180) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT181_REG_OFST      _UINT32_(0xDD4)     /* (LCDC_OVR1CLUT181) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT182_REG_OFST      _UINT32_(0xDD8)     /* (LCDC_OVR1CLUT182) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT183_REG_OFST      _UINT32_(0xDDC)     /* (LCDC_OVR1CLUT183) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT184_REG_OFST      _UINT32_(0xDE0)     /* (LCDC_OVR1CLUT184) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT185_REG_OFST      _UINT32_(0xDE4)     /* (LCDC_OVR1CLUT185) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT186_REG_OFST      _UINT32_(0xDE8)     /* (LCDC_OVR1CLUT186) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT187_REG_OFST      _UINT32_(0xDEC)     /* (LCDC_OVR1CLUT187) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT188_REG_OFST      _UINT32_(0xDF0)     /* (LCDC_OVR1CLUT188) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT189_REG_OFST      _UINT32_(0xDF4)     /* (LCDC_OVR1CLUT189) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT190_REG_OFST      _UINT32_(0xDF8)     /* (LCDC_OVR1CLUT190) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT191_REG_OFST      _UINT32_(0xDFC)     /* (LCDC_OVR1CLUT191) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT192_REG_OFST      _UINT32_(0xE00)     /* (LCDC_OVR1CLUT192) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT193_REG_OFST      _UINT32_(0xE04)     /* (LCDC_OVR1CLUT193) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT194_REG_OFST      _UINT32_(0xE08)     /* (LCDC_OVR1CLUT194) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT195_REG_OFST      _UINT32_(0xE0C)     /* (LCDC_OVR1CLUT195) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT196_REG_OFST      _UINT32_(0xE10)     /* (LCDC_OVR1CLUT196) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT197_REG_OFST      _UINT32_(0xE14)     /* (LCDC_OVR1CLUT197) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT198_REG_OFST      _UINT32_(0xE18)     /* (LCDC_OVR1CLUT198) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT199_REG_OFST      _UINT32_(0xE1C)     /* (LCDC_OVR1CLUT199) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT200_REG_OFST      _UINT32_(0xE20)     /* (LCDC_OVR1CLUT200) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT201_REG_OFST      _UINT32_(0xE24)     /* (LCDC_OVR1CLUT201) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT202_REG_OFST      _UINT32_(0xE28)     /* (LCDC_OVR1CLUT202) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT203_REG_OFST      _UINT32_(0xE2C)     /* (LCDC_OVR1CLUT203) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT204_REG_OFST      _UINT32_(0xE30)     /* (LCDC_OVR1CLUT204) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT205_REG_OFST      _UINT32_(0xE34)     /* (LCDC_OVR1CLUT205) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT206_REG_OFST      _UINT32_(0xE38)     /* (LCDC_OVR1CLUT206) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT207_REG_OFST      _UINT32_(0xE3C)     /* (LCDC_OVR1CLUT207) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT208_REG_OFST      _UINT32_(0xE40)     /* (LCDC_OVR1CLUT208) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT209_REG_OFST      _UINT32_(0xE44)     /* (LCDC_OVR1CLUT209) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT210_REG_OFST      _UINT32_(0xE48)     /* (LCDC_OVR1CLUT210) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT211_REG_OFST      _UINT32_(0xE4C)     /* (LCDC_OVR1CLUT211) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT212_REG_OFST      _UINT32_(0xE50)     /* (LCDC_OVR1CLUT212) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT213_REG_OFST      _UINT32_(0xE54)     /* (LCDC_OVR1CLUT213) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT214_REG_OFST      _UINT32_(0xE58)     /* (LCDC_OVR1CLUT214) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT215_REG_OFST      _UINT32_(0xE5C)     /* (LCDC_OVR1CLUT215) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT216_REG_OFST      _UINT32_(0xE60)     /* (LCDC_OVR1CLUT216) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT217_REG_OFST      _UINT32_(0xE64)     /* (LCDC_OVR1CLUT217) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT218_REG_OFST      _UINT32_(0xE68)     /* (LCDC_OVR1CLUT218) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT219_REG_OFST      _UINT32_(0xE6C)     /* (LCDC_OVR1CLUT219) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT220_REG_OFST      _UINT32_(0xE70)     /* (LCDC_OVR1CLUT220) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT221_REG_OFST      _UINT32_(0xE74)     /* (LCDC_OVR1CLUT221) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT222_REG_OFST      _UINT32_(0xE78)     /* (LCDC_OVR1CLUT222) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT223_REG_OFST      _UINT32_(0xE7C)     /* (LCDC_OVR1CLUT223) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT224_REG_OFST      _UINT32_(0xE80)     /* (LCDC_OVR1CLUT224) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT225_REG_OFST      _UINT32_(0xE84)     /* (LCDC_OVR1CLUT225) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT226_REG_OFST      _UINT32_(0xE88)     /* (LCDC_OVR1CLUT226) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT227_REG_OFST      _UINT32_(0xE8C)     /* (LCDC_OVR1CLUT227) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT228_REG_OFST      _UINT32_(0xE90)     /* (LCDC_OVR1CLUT228) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT229_REG_OFST      _UINT32_(0xE94)     /* (LCDC_OVR1CLUT229) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT230_REG_OFST      _UINT32_(0xE98)     /* (LCDC_OVR1CLUT230) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT231_REG_OFST      _UINT32_(0xE9C)     /* (LCDC_OVR1CLUT231) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT232_REG_OFST      _UINT32_(0xEA0)     /* (LCDC_OVR1CLUT232) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT233_REG_OFST      _UINT32_(0xEA4)     /* (LCDC_OVR1CLUT233) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT234_REG_OFST      _UINT32_(0xEA8)     /* (LCDC_OVR1CLUT234) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT235_REG_OFST      _UINT32_(0xEAC)     /* (LCDC_OVR1CLUT235) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT236_REG_OFST      _UINT32_(0xEB0)     /* (LCDC_OVR1CLUT236) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT237_REG_OFST      _UINT32_(0xEB4)     /* (LCDC_OVR1CLUT237) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT238_REG_OFST      _UINT32_(0xEB8)     /* (LCDC_OVR1CLUT238) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT239_REG_OFST      _UINT32_(0xEBC)     /* (LCDC_OVR1CLUT239) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT240_REG_OFST      _UINT32_(0xEC0)     /* (LCDC_OVR1CLUT240) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT241_REG_OFST      _UINT32_(0xEC4)     /* (LCDC_OVR1CLUT241) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT242_REG_OFST      _UINT32_(0xEC8)     /* (LCDC_OVR1CLUT242) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT243_REG_OFST      _UINT32_(0xECC)     /* (LCDC_OVR1CLUT243) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT244_REG_OFST      _UINT32_(0xED0)     /* (LCDC_OVR1CLUT244) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT245_REG_OFST      _UINT32_(0xED4)     /* (LCDC_OVR1CLUT245) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT246_REG_OFST      _UINT32_(0xED8)     /* (LCDC_OVR1CLUT246) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT247_REG_OFST      _UINT32_(0xEDC)     /* (LCDC_OVR1CLUT247) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT248_REG_OFST      _UINT32_(0xEE0)     /* (LCDC_OVR1CLUT248) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT249_REG_OFST      _UINT32_(0xEE4)     /* (LCDC_OVR1CLUT249) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT250_REG_OFST      _UINT32_(0xEE8)     /* (LCDC_OVR1CLUT250) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT251_REG_OFST      _UINT32_(0xEEC)     /* (LCDC_OVR1CLUT251) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT252_REG_OFST      _UINT32_(0xEF0)     /* (LCDC_OVR1CLUT252) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT253_REG_OFST      _UINT32_(0xEF4)     /* (LCDC_OVR1CLUT253) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT254_REG_OFST      _UINT32_(0xEF8)     /* (LCDC_OVR1CLUT254) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR1CLUT255_REG_OFST      _UINT32_(0xEFC)     /* (LCDC_OVR1CLUT255) Overlay 1 CLUT Register x Offset */
#define LCDC_OVR2CLUT_REG_OFST         _UINT32_(0xF00)     /* (LCDC_OVR2CLUT) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT0_REG_OFST        _UINT32_(0xF00)     /* (LCDC_OVR2CLUT0) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT1_REG_OFST        _UINT32_(0xF04)     /* (LCDC_OVR2CLUT1) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT2_REG_OFST        _UINT32_(0xF08)     /* (LCDC_OVR2CLUT2) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT3_REG_OFST        _UINT32_(0xF0C)     /* (LCDC_OVR2CLUT3) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT4_REG_OFST        _UINT32_(0xF10)     /* (LCDC_OVR2CLUT4) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT5_REG_OFST        _UINT32_(0xF14)     /* (LCDC_OVR2CLUT5) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT6_REG_OFST        _UINT32_(0xF18)     /* (LCDC_OVR2CLUT6) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT7_REG_OFST        _UINT32_(0xF1C)     /* (LCDC_OVR2CLUT7) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT8_REG_OFST        _UINT32_(0xF20)     /* (LCDC_OVR2CLUT8) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT9_REG_OFST        _UINT32_(0xF24)     /* (LCDC_OVR2CLUT9) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT10_REG_OFST       _UINT32_(0xF28)     /* (LCDC_OVR2CLUT10) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT11_REG_OFST       _UINT32_(0xF2C)     /* (LCDC_OVR2CLUT11) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT12_REG_OFST       _UINT32_(0xF30)     /* (LCDC_OVR2CLUT12) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT13_REG_OFST       _UINT32_(0xF34)     /* (LCDC_OVR2CLUT13) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT14_REG_OFST       _UINT32_(0xF38)     /* (LCDC_OVR2CLUT14) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT15_REG_OFST       _UINT32_(0xF3C)     /* (LCDC_OVR2CLUT15) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT16_REG_OFST       _UINT32_(0xF40)     /* (LCDC_OVR2CLUT16) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT17_REG_OFST       _UINT32_(0xF44)     /* (LCDC_OVR2CLUT17) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT18_REG_OFST       _UINT32_(0xF48)     /* (LCDC_OVR2CLUT18) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT19_REG_OFST       _UINT32_(0xF4C)     /* (LCDC_OVR2CLUT19) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT20_REG_OFST       _UINT32_(0xF50)     /* (LCDC_OVR2CLUT20) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT21_REG_OFST       _UINT32_(0xF54)     /* (LCDC_OVR2CLUT21) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT22_REG_OFST       _UINT32_(0xF58)     /* (LCDC_OVR2CLUT22) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT23_REG_OFST       _UINT32_(0xF5C)     /* (LCDC_OVR2CLUT23) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT24_REG_OFST       _UINT32_(0xF60)     /* (LCDC_OVR2CLUT24) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT25_REG_OFST       _UINT32_(0xF64)     /* (LCDC_OVR2CLUT25) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT26_REG_OFST       _UINT32_(0xF68)     /* (LCDC_OVR2CLUT26) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT27_REG_OFST       _UINT32_(0xF6C)     /* (LCDC_OVR2CLUT27) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT28_REG_OFST       _UINT32_(0xF70)     /* (LCDC_OVR2CLUT28) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT29_REG_OFST       _UINT32_(0xF74)     /* (LCDC_OVR2CLUT29) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT30_REG_OFST       _UINT32_(0xF78)     /* (LCDC_OVR2CLUT30) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT31_REG_OFST       _UINT32_(0xF7C)     /* (LCDC_OVR2CLUT31) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT32_REG_OFST       _UINT32_(0xF80)     /* (LCDC_OVR2CLUT32) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT33_REG_OFST       _UINT32_(0xF84)     /* (LCDC_OVR2CLUT33) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT34_REG_OFST       _UINT32_(0xF88)     /* (LCDC_OVR2CLUT34) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT35_REG_OFST       _UINT32_(0xF8C)     /* (LCDC_OVR2CLUT35) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT36_REG_OFST       _UINT32_(0xF90)     /* (LCDC_OVR2CLUT36) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT37_REG_OFST       _UINT32_(0xF94)     /* (LCDC_OVR2CLUT37) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT38_REG_OFST       _UINT32_(0xF98)     /* (LCDC_OVR2CLUT38) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT39_REG_OFST       _UINT32_(0xF9C)     /* (LCDC_OVR2CLUT39) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT40_REG_OFST       _UINT32_(0xFA0)     /* (LCDC_OVR2CLUT40) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT41_REG_OFST       _UINT32_(0xFA4)     /* (LCDC_OVR2CLUT41) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT42_REG_OFST       _UINT32_(0xFA8)     /* (LCDC_OVR2CLUT42) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT43_REG_OFST       _UINT32_(0xFAC)     /* (LCDC_OVR2CLUT43) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT44_REG_OFST       _UINT32_(0xFB0)     /* (LCDC_OVR2CLUT44) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT45_REG_OFST       _UINT32_(0xFB4)     /* (LCDC_OVR2CLUT45) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT46_REG_OFST       _UINT32_(0xFB8)     /* (LCDC_OVR2CLUT46) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT47_REG_OFST       _UINT32_(0xFBC)     /* (LCDC_OVR2CLUT47) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT48_REG_OFST       _UINT32_(0xFC0)     /* (LCDC_OVR2CLUT48) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT49_REG_OFST       _UINT32_(0xFC4)     /* (LCDC_OVR2CLUT49) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT50_REG_OFST       _UINT32_(0xFC8)     /* (LCDC_OVR2CLUT50) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT51_REG_OFST       _UINT32_(0xFCC)     /* (LCDC_OVR2CLUT51) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT52_REG_OFST       _UINT32_(0xFD0)     /* (LCDC_OVR2CLUT52) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT53_REG_OFST       _UINT32_(0xFD4)     /* (LCDC_OVR2CLUT53) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT54_REG_OFST       _UINT32_(0xFD8)     /* (LCDC_OVR2CLUT54) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT55_REG_OFST       _UINT32_(0xFDC)     /* (LCDC_OVR2CLUT55) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT56_REG_OFST       _UINT32_(0xFE0)     /* (LCDC_OVR2CLUT56) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT57_REG_OFST       _UINT32_(0xFE4)     /* (LCDC_OVR2CLUT57) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT58_REG_OFST       _UINT32_(0xFE8)     /* (LCDC_OVR2CLUT58) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT59_REG_OFST       _UINT32_(0xFEC)     /* (LCDC_OVR2CLUT59) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT60_REG_OFST       _UINT32_(0xFF0)     /* (LCDC_OVR2CLUT60) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT61_REG_OFST       _UINT32_(0xFF4)     /* (LCDC_OVR2CLUT61) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT62_REG_OFST       _UINT32_(0xFF8)     /* (LCDC_OVR2CLUT62) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT63_REG_OFST       _UINT32_(0xFFC)     /* (LCDC_OVR2CLUT63) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT64_REG_OFST       _UINT32_(0x1000)    /* (LCDC_OVR2CLUT64) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT65_REG_OFST       _UINT32_(0x1004)    /* (LCDC_OVR2CLUT65) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT66_REG_OFST       _UINT32_(0x1008)    /* (LCDC_OVR2CLUT66) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT67_REG_OFST       _UINT32_(0x100C)    /* (LCDC_OVR2CLUT67) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT68_REG_OFST       _UINT32_(0x1010)    /* (LCDC_OVR2CLUT68) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT69_REG_OFST       _UINT32_(0x1014)    /* (LCDC_OVR2CLUT69) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT70_REG_OFST       _UINT32_(0x1018)    /* (LCDC_OVR2CLUT70) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT71_REG_OFST       _UINT32_(0x101C)    /* (LCDC_OVR2CLUT71) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT72_REG_OFST       _UINT32_(0x1020)    /* (LCDC_OVR2CLUT72) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT73_REG_OFST       _UINT32_(0x1024)    /* (LCDC_OVR2CLUT73) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT74_REG_OFST       _UINT32_(0x1028)    /* (LCDC_OVR2CLUT74) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT75_REG_OFST       _UINT32_(0x102C)    /* (LCDC_OVR2CLUT75) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT76_REG_OFST       _UINT32_(0x1030)    /* (LCDC_OVR2CLUT76) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT77_REG_OFST       _UINT32_(0x1034)    /* (LCDC_OVR2CLUT77) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT78_REG_OFST       _UINT32_(0x1038)    /* (LCDC_OVR2CLUT78) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT79_REG_OFST       _UINT32_(0x103C)    /* (LCDC_OVR2CLUT79) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT80_REG_OFST       _UINT32_(0x1040)    /* (LCDC_OVR2CLUT80) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT81_REG_OFST       _UINT32_(0x1044)    /* (LCDC_OVR2CLUT81) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT82_REG_OFST       _UINT32_(0x1048)    /* (LCDC_OVR2CLUT82) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT83_REG_OFST       _UINT32_(0x104C)    /* (LCDC_OVR2CLUT83) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT84_REG_OFST       _UINT32_(0x1050)    /* (LCDC_OVR2CLUT84) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT85_REG_OFST       _UINT32_(0x1054)    /* (LCDC_OVR2CLUT85) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT86_REG_OFST       _UINT32_(0x1058)    /* (LCDC_OVR2CLUT86) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT87_REG_OFST       _UINT32_(0x105C)    /* (LCDC_OVR2CLUT87) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT88_REG_OFST       _UINT32_(0x1060)    /* (LCDC_OVR2CLUT88) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT89_REG_OFST       _UINT32_(0x1064)    /* (LCDC_OVR2CLUT89) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT90_REG_OFST       _UINT32_(0x1068)    /* (LCDC_OVR2CLUT90) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT91_REG_OFST       _UINT32_(0x106C)    /* (LCDC_OVR2CLUT91) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT92_REG_OFST       _UINT32_(0x1070)    /* (LCDC_OVR2CLUT92) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT93_REG_OFST       _UINT32_(0x1074)    /* (LCDC_OVR2CLUT93) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT94_REG_OFST       _UINT32_(0x1078)    /* (LCDC_OVR2CLUT94) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT95_REG_OFST       _UINT32_(0x107C)    /* (LCDC_OVR2CLUT95) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT96_REG_OFST       _UINT32_(0x1080)    /* (LCDC_OVR2CLUT96) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT97_REG_OFST       _UINT32_(0x1084)    /* (LCDC_OVR2CLUT97) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT98_REG_OFST       _UINT32_(0x1088)    /* (LCDC_OVR2CLUT98) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT99_REG_OFST       _UINT32_(0x108C)    /* (LCDC_OVR2CLUT99) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT100_REG_OFST      _UINT32_(0x1090)    /* (LCDC_OVR2CLUT100) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT101_REG_OFST      _UINT32_(0x1094)    /* (LCDC_OVR2CLUT101) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT102_REG_OFST      _UINT32_(0x1098)    /* (LCDC_OVR2CLUT102) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT103_REG_OFST      _UINT32_(0x109C)    /* (LCDC_OVR2CLUT103) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT104_REG_OFST      _UINT32_(0x10A0)    /* (LCDC_OVR2CLUT104) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT105_REG_OFST      _UINT32_(0x10A4)    /* (LCDC_OVR2CLUT105) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT106_REG_OFST      _UINT32_(0x10A8)    /* (LCDC_OVR2CLUT106) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT107_REG_OFST      _UINT32_(0x10AC)    /* (LCDC_OVR2CLUT107) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT108_REG_OFST      _UINT32_(0x10B0)    /* (LCDC_OVR2CLUT108) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT109_REG_OFST      _UINT32_(0x10B4)    /* (LCDC_OVR2CLUT109) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT110_REG_OFST      _UINT32_(0x10B8)    /* (LCDC_OVR2CLUT110) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT111_REG_OFST      _UINT32_(0x10BC)    /* (LCDC_OVR2CLUT111) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT112_REG_OFST      _UINT32_(0x10C0)    /* (LCDC_OVR2CLUT112) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT113_REG_OFST      _UINT32_(0x10C4)    /* (LCDC_OVR2CLUT113) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT114_REG_OFST      _UINT32_(0x10C8)    /* (LCDC_OVR2CLUT114) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT115_REG_OFST      _UINT32_(0x10CC)    /* (LCDC_OVR2CLUT115) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT116_REG_OFST      _UINT32_(0x10D0)    /* (LCDC_OVR2CLUT116) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT117_REG_OFST      _UINT32_(0x10D4)    /* (LCDC_OVR2CLUT117) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT118_REG_OFST      _UINT32_(0x10D8)    /* (LCDC_OVR2CLUT118) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT119_REG_OFST      _UINT32_(0x10DC)    /* (LCDC_OVR2CLUT119) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT120_REG_OFST      _UINT32_(0x10E0)    /* (LCDC_OVR2CLUT120) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT121_REG_OFST      _UINT32_(0x10E4)    /* (LCDC_OVR2CLUT121) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT122_REG_OFST      _UINT32_(0x10E8)    /* (LCDC_OVR2CLUT122) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT123_REG_OFST      _UINT32_(0x10EC)    /* (LCDC_OVR2CLUT123) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT124_REG_OFST      _UINT32_(0x10F0)    /* (LCDC_OVR2CLUT124) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT125_REG_OFST      _UINT32_(0x10F4)    /* (LCDC_OVR2CLUT125) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT126_REG_OFST      _UINT32_(0x10F8)    /* (LCDC_OVR2CLUT126) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT127_REG_OFST      _UINT32_(0x10FC)    /* (LCDC_OVR2CLUT127) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT128_REG_OFST      _UINT32_(0x1100)    /* (LCDC_OVR2CLUT128) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT129_REG_OFST      _UINT32_(0x1104)    /* (LCDC_OVR2CLUT129) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT130_REG_OFST      _UINT32_(0x1108)    /* (LCDC_OVR2CLUT130) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT131_REG_OFST      _UINT32_(0x110C)    /* (LCDC_OVR2CLUT131) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT132_REG_OFST      _UINT32_(0x1110)    /* (LCDC_OVR2CLUT132) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT133_REG_OFST      _UINT32_(0x1114)    /* (LCDC_OVR2CLUT133) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT134_REG_OFST      _UINT32_(0x1118)    /* (LCDC_OVR2CLUT134) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT135_REG_OFST      _UINT32_(0x111C)    /* (LCDC_OVR2CLUT135) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT136_REG_OFST      _UINT32_(0x1120)    /* (LCDC_OVR2CLUT136) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT137_REG_OFST      _UINT32_(0x1124)    /* (LCDC_OVR2CLUT137) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT138_REG_OFST      _UINT32_(0x1128)    /* (LCDC_OVR2CLUT138) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT139_REG_OFST      _UINT32_(0x112C)    /* (LCDC_OVR2CLUT139) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT140_REG_OFST      _UINT32_(0x1130)    /* (LCDC_OVR2CLUT140) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT141_REG_OFST      _UINT32_(0x1134)    /* (LCDC_OVR2CLUT141) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT142_REG_OFST      _UINT32_(0x1138)    /* (LCDC_OVR2CLUT142) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT143_REG_OFST      _UINT32_(0x113C)    /* (LCDC_OVR2CLUT143) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT144_REG_OFST      _UINT32_(0x1140)    /* (LCDC_OVR2CLUT144) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT145_REG_OFST      _UINT32_(0x1144)    /* (LCDC_OVR2CLUT145) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT146_REG_OFST      _UINT32_(0x1148)    /* (LCDC_OVR2CLUT146) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT147_REG_OFST      _UINT32_(0x114C)    /* (LCDC_OVR2CLUT147) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT148_REG_OFST      _UINT32_(0x1150)    /* (LCDC_OVR2CLUT148) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT149_REG_OFST      _UINT32_(0x1154)    /* (LCDC_OVR2CLUT149) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT150_REG_OFST      _UINT32_(0x1158)    /* (LCDC_OVR2CLUT150) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT151_REG_OFST      _UINT32_(0x115C)    /* (LCDC_OVR2CLUT151) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT152_REG_OFST      _UINT32_(0x1160)    /* (LCDC_OVR2CLUT152) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT153_REG_OFST      _UINT32_(0x1164)    /* (LCDC_OVR2CLUT153) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT154_REG_OFST      _UINT32_(0x1168)    /* (LCDC_OVR2CLUT154) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT155_REG_OFST      _UINT32_(0x116C)    /* (LCDC_OVR2CLUT155) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT156_REG_OFST      _UINT32_(0x1170)    /* (LCDC_OVR2CLUT156) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT157_REG_OFST      _UINT32_(0x1174)    /* (LCDC_OVR2CLUT157) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT158_REG_OFST      _UINT32_(0x1178)    /* (LCDC_OVR2CLUT158) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT159_REG_OFST      _UINT32_(0x117C)    /* (LCDC_OVR2CLUT159) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT160_REG_OFST      _UINT32_(0x1180)    /* (LCDC_OVR2CLUT160) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT161_REG_OFST      _UINT32_(0x1184)    /* (LCDC_OVR2CLUT161) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT162_REG_OFST      _UINT32_(0x1188)    /* (LCDC_OVR2CLUT162) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT163_REG_OFST      _UINT32_(0x118C)    /* (LCDC_OVR2CLUT163) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT164_REG_OFST      _UINT32_(0x1190)    /* (LCDC_OVR2CLUT164) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT165_REG_OFST      _UINT32_(0x1194)    /* (LCDC_OVR2CLUT165) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT166_REG_OFST      _UINT32_(0x1198)    /* (LCDC_OVR2CLUT166) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT167_REG_OFST      _UINT32_(0x119C)    /* (LCDC_OVR2CLUT167) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT168_REG_OFST      _UINT32_(0x11A0)    /* (LCDC_OVR2CLUT168) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT169_REG_OFST      _UINT32_(0x11A4)    /* (LCDC_OVR2CLUT169) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT170_REG_OFST      _UINT32_(0x11A8)    /* (LCDC_OVR2CLUT170) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT171_REG_OFST      _UINT32_(0x11AC)    /* (LCDC_OVR2CLUT171) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT172_REG_OFST      _UINT32_(0x11B0)    /* (LCDC_OVR2CLUT172) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT173_REG_OFST      _UINT32_(0x11B4)    /* (LCDC_OVR2CLUT173) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT174_REG_OFST      _UINT32_(0x11B8)    /* (LCDC_OVR2CLUT174) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT175_REG_OFST      _UINT32_(0x11BC)    /* (LCDC_OVR2CLUT175) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT176_REG_OFST      _UINT32_(0x11C0)    /* (LCDC_OVR2CLUT176) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT177_REG_OFST      _UINT32_(0x11C4)    /* (LCDC_OVR2CLUT177) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT178_REG_OFST      _UINT32_(0x11C8)    /* (LCDC_OVR2CLUT178) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT179_REG_OFST      _UINT32_(0x11CC)    /* (LCDC_OVR2CLUT179) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT180_REG_OFST      _UINT32_(0x11D0)    /* (LCDC_OVR2CLUT180) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT181_REG_OFST      _UINT32_(0x11D4)    /* (LCDC_OVR2CLUT181) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT182_REG_OFST      _UINT32_(0x11D8)    /* (LCDC_OVR2CLUT182) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT183_REG_OFST      _UINT32_(0x11DC)    /* (LCDC_OVR2CLUT183) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT184_REG_OFST      _UINT32_(0x11E0)    /* (LCDC_OVR2CLUT184) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT185_REG_OFST      _UINT32_(0x11E4)    /* (LCDC_OVR2CLUT185) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT186_REG_OFST      _UINT32_(0x11E8)    /* (LCDC_OVR2CLUT186) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT187_REG_OFST      _UINT32_(0x11EC)    /* (LCDC_OVR2CLUT187) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT188_REG_OFST      _UINT32_(0x11F0)    /* (LCDC_OVR2CLUT188) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT189_REG_OFST      _UINT32_(0x11F4)    /* (LCDC_OVR2CLUT189) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT190_REG_OFST      _UINT32_(0x11F8)    /* (LCDC_OVR2CLUT190) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT191_REG_OFST      _UINT32_(0x11FC)    /* (LCDC_OVR2CLUT191) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT192_REG_OFST      _UINT32_(0x1200)    /* (LCDC_OVR2CLUT192) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT193_REG_OFST      _UINT32_(0x1204)    /* (LCDC_OVR2CLUT193) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT194_REG_OFST      _UINT32_(0x1208)    /* (LCDC_OVR2CLUT194) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT195_REG_OFST      _UINT32_(0x120C)    /* (LCDC_OVR2CLUT195) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT196_REG_OFST      _UINT32_(0x1210)    /* (LCDC_OVR2CLUT196) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT197_REG_OFST      _UINT32_(0x1214)    /* (LCDC_OVR2CLUT197) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT198_REG_OFST      _UINT32_(0x1218)    /* (LCDC_OVR2CLUT198) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT199_REG_OFST      _UINT32_(0x121C)    /* (LCDC_OVR2CLUT199) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT200_REG_OFST      _UINT32_(0x1220)    /* (LCDC_OVR2CLUT200) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT201_REG_OFST      _UINT32_(0x1224)    /* (LCDC_OVR2CLUT201) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT202_REG_OFST      _UINT32_(0x1228)    /* (LCDC_OVR2CLUT202) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT203_REG_OFST      _UINT32_(0x122C)    /* (LCDC_OVR2CLUT203) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT204_REG_OFST      _UINT32_(0x1230)    /* (LCDC_OVR2CLUT204) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT205_REG_OFST      _UINT32_(0x1234)    /* (LCDC_OVR2CLUT205) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT206_REG_OFST      _UINT32_(0x1238)    /* (LCDC_OVR2CLUT206) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT207_REG_OFST      _UINT32_(0x123C)    /* (LCDC_OVR2CLUT207) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT208_REG_OFST      _UINT32_(0x1240)    /* (LCDC_OVR2CLUT208) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT209_REG_OFST      _UINT32_(0x1244)    /* (LCDC_OVR2CLUT209) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT210_REG_OFST      _UINT32_(0x1248)    /* (LCDC_OVR2CLUT210) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT211_REG_OFST      _UINT32_(0x124C)    /* (LCDC_OVR2CLUT211) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT212_REG_OFST      _UINT32_(0x1250)    /* (LCDC_OVR2CLUT212) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT213_REG_OFST      _UINT32_(0x1254)    /* (LCDC_OVR2CLUT213) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT214_REG_OFST      _UINT32_(0x1258)    /* (LCDC_OVR2CLUT214) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT215_REG_OFST      _UINT32_(0x125C)    /* (LCDC_OVR2CLUT215) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT216_REG_OFST      _UINT32_(0x1260)    /* (LCDC_OVR2CLUT216) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT217_REG_OFST      _UINT32_(0x1264)    /* (LCDC_OVR2CLUT217) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT218_REG_OFST      _UINT32_(0x1268)    /* (LCDC_OVR2CLUT218) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT219_REG_OFST      _UINT32_(0x126C)    /* (LCDC_OVR2CLUT219) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT220_REG_OFST      _UINT32_(0x1270)    /* (LCDC_OVR2CLUT220) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT221_REG_OFST      _UINT32_(0x1274)    /* (LCDC_OVR2CLUT221) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT222_REG_OFST      _UINT32_(0x1278)    /* (LCDC_OVR2CLUT222) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT223_REG_OFST      _UINT32_(0x127C)    /* (LCDC_OVR2CLUT223) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT224_REG_OFST      _UINT32_(0x1280)    /* (LCDC_OVR2CLUT224) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT225_REG_OFST      _UINT32_(0x1284)    /* (LCDC_OVR2CLUT225) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT226_REG_OFST      _UINT32_(0x1288)    /* (LCDC_OVR2CLUT226) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT227_REG_OFST      _UINT32_(0x128C)    /* (LCDC_OVR2CLUT227) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT228_REG_OFST      _UINT32_(0x1290)    /* (LCDC_OVR2CLUT228) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT229_REG_OFST      _UINT32_(0x1294)    /* (LCDC_OVR2CLUT229) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT230_REG_OFST      _UINT32_(0x1298)    /* (LCDC_OVR2CLUT230) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT231_REG_OFST      _UINT32_(0x129C)    /* (LCDC_OVR2CLUT231) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT232_REG_OFST      _UINT32_(0x12A0)    /* (LCDC_OVR2CLUT232) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT233_REG_OFST      _UINT32_(0x12A4)    /* (LCDC_OVR2CLUT233) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT234_REG_OFST      _UINT32_(0x12A8)    /* (LCDC_OVR2CLUT234) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT235_REG_OFST      _UINT32_(0x12AC)    /* (LCDC_OVR2CLUT235) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT236_REG_OFST      _UINT32_(0x12B0)    /* (LCDC_OVR2CLUT236) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT237_REG_OFST      _UINT32_(0x12B4)    /* (LCDC_OVR2CLUT237) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT238_REG_OFST      _UINT32_(0x12B8)    /* (LCDC_OVR2CLUT238) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT239_REG_OFST      _UINT32_(0x12BC)    /* (LCDC_OVR2CLUT239) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT240_REG_OFST      _UINT32_(0x12C0)    /* (LCDC_OVR2CLUT240) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT241_REG_OFST      _UINT32_(0x12C4)    /* (LCDC_OVR2CLUT241) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT242_REG_OFST      _UINT32_(0x12C8)    /* (LCDC_OVR2CLUT242) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT243_REG_OFST      _UINT32_(0x12CC)    /* (LCDC_OVR2CLUT243) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT244_REG_OFST      _UINT32_(0x12D0)    /* (LCDC_OVR2CLUT244) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT245_REG_OFST      _UINT32_(0x12D4)    /* (LCDC_OVR2CLUT245) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT246_REG_OFST      _UINT32_(0x12D8)    /* (LCDC_OVR2CLUT246) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT247_REG_OFST      _UINT32_(0x12DC)    /* (LCDC_OVR2CLUT247) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT248_REG_OFST      _UINT32_(0x12E0)    /* (LCDC_OVR2CLUT248) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT249_REG_OFST      _UINT32_(0x12E4)    /* (LCDC_OVR2CLUT249) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT250_REG_OFST      _UINT32_(0x12E8)    /* (LCDC_OVR2CLUT250) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT251_REG_OFST      _UINT32_(0x12EC)    /* (LCDC_OVR2CLUT251) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT252_REG_OFST      _UINT32_(0x12F0)    /* (LCDC_OVR2CLUT252) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT253_REG_OFST      _UINT32_(0x12F4)    /* (LCDC_OVR2CLUT253) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT254_REG_OFST      _UINT32_(0x12F8)    /* (LCDC_OVR2CLUT254) Overlay 2 CLUT Register x Offset */
#define LCDC_OVR2CLUT255_REG_OFST      _UINT32_(0x12FC)    /* (LCDC_OVR2CLUT255) Overlay 2 CLUT Register x Offset */
#define LCDC_HEOCLUT_REG_OFST          _UINT32_(0x1300)    /* (LCDC_HEOCLUT) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT0_REG_OFST         _UINT32_(0x1300)    /* (LCDC_HEOCLUT0) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT1_REG_OFST         _UINT32_(0x1304)    /* (LCDC_HEOCLUT1) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT2_REG_OFST         _UINT32_(0x1308)    /* (LCDC_HEOCLUT2) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT3_REG_OFST         _UINT32_(0x130C)    /* (LCDC_HEOCLUT3) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT4_REG_OFST         _UINT32_(0x1310)    /* (LCDC_HEOCLUT4) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT5_REG_OFST         _UINT32_(0x1314)    /* (LCDC_HEOCLUT5) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT6_REG_OFST         _UINT32_(0x1318)    /* (LCDC_HEOCLUT6) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT7_REG_OFST         _UINT32_(0x131C)    /* (LCDC_HEOCLUT7) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT8_REG_OFST         _UINT32_(0x1320)    /* (LCDC_HEOCLUT8) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT9_REG_OFST         _UINT32_(0x1324)    /* (LCDC_HEOCLUT9) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT10_REG_OFST        _UINT32_(0x1328)    /* (LCDC_HEOCLUT10) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT11_REG_OFST        _UINT32_(0x132C)    /* (LCDC_HEOCLUT11) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT12_REG_OFST        _UINT32_(0x1330)    /* (LCDC_HEOCLUT12) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT13_REG_OFST        _UINT32_(0x1334)    /* (LCDC_HEOCLUT13) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT14_REG_OFST        _UINT32_(0x1338)    /* (LCDC_HEOCLUT14) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT15_REG_OFST        _UINT32_(0x133C)    /* (LCDC_HEOCLUT15) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT16_REG_OFST        _UINT32_(0x1340)    /* (LCDC_HEOCLUT16) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT17_REG_OFST        _UINT32_(0x1344)    /* (LCDC_HEOCLUT17) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT18_REG_OFST        _UINT32_(0x1348)    /* (LCDC_HEOCLUT18) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT19_REG_OFST        _UINT32_(0x134C)    /* (LCDC_HEOCLUT19) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT20_REG_OFST        _UINT32_(0x1350)    /* (LCDC_HEOCLUT20) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT21_REG_OFST        _UINT32_(0x1354)    /* (LCDC_HEOCLUT21) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT22_REG_OFST        _UINT32_(0x1358)    /* (LCDC_HEOCLUT22) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT23_REG_OFST        _UINT32_(0x135C)    /* (LCDC_HEOCLUT23) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT24_REG_OFST        _UINT32_(0x1360)    /* (LCDC_HEOCLUT24) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT25_REG_OFST        _UINT32_(0x1364)    /* (LCDC_HEOCLUT25) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT26_REG_OFST        _UINT32_(0x1368)    /* (LCDC_HEOCLUT26) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT27_REG_OFST        _UINT32_(0x136C)    /* (LCDC_HEOCLUT27) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT28_REG_OFST        _UINT32_(0x1370)    /* (LCDC_HEOCLUT28) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT29_REG_OFST        _UINT32_(0x1374)    /* (LCDC_HEOCLUT29) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT30_REG_OFST        _UINT32_(0x1378)    /* (LCDC_HEOCLUT30) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT31_REG_OFST        _UINT32_(0x137C)    /* (LCDC_HEOCLUT31) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT32_REG_OFST        _UINT32_(0x1380)    /* (LCDC_HEOCLUT32) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT33_REG_OFST        _UINT32_(0x1384)    /* (LCDC_HEOCLUT33) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT34_REG_OFST        _UINT32_(0x1388)    /* (LCDC_HEOCLUT34) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT35_REG_OFST        _UINT32_(0x138C)    /* (LCDC_HEOCLUT35) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT36_REG_OFST        _UINT32_(0x1390)    /* (LCDC_HEOCLUT36) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT37_REG_OFST        _UINT32_(0x1394)    /* (LCDC_HEOCLUT37) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT38_REG_OFST        _UINT32_(0x1398)    /* (LCDC_HEOCLUT38) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT39_REG_OFST        _UINT32_(0x139C)    /* (LCDC_HEOCLUT39) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT40_REG_OFST        _UINT32_(0x13A0)    /* (LCDC_HEOCLUT40) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT41_REG_OFST        _UINT32_(0x13A4)    /* (LCDC_HEOCLUT41) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT42_REG_OFST        _UINT32_(0x13A8)    /* (LCDC_HEOCLUT42) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT43_REG_OFST        _UINT32_(0x13AC)    /* (LCDC_HEOCLUT43) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT44_REG_OFST        _UINT32_(0x13B0)    /* (LCDC_HEOCLUT44) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT45_REG_OFST        _UINT32_(0x13B4)    /* (LCDC_HEOCLUT45) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT46_REG_OFST        _UINT32_(0x13B8)    /* (LCDC_HEOCLUT46) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT47_REG_OFST        _UINT32_(0x13BC)    /* (LCDC_HEOCLUT47) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT48_REG_OFST        _UINT32_(0x13C0)    /* (LCDC_HEOCLUT48) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT49_REG_OFST        _UINT32_(0x13C4)    /* (LCDC_HEOCLUT49) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT50_REG_OFST        _UINT32_(0x13C8)    /* (LCDC_HEOCLUT50) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT51_REG_OFST        _UINT32_(0x13CC)    /* (LCDC_HEOCLUT51) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT52_REG_OFST        _UINT32_(0x13D0)    /* (LCDC_HEOCLUT52) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT53_REG_OFST        _UINT32_(0x13D4)    /* (LCDC_HEOCLUT53) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT54_REG_OFST        _UINT32_(0x13D8)    /* (LCDC_HEOCLUT54) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT55_REG_OFST        _UINT32_(0x13DC)    /* (LCDC_HEOCLUT55) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT56_REG_OFST        _UINT32_(0x13E0)    /* (LCDC_HEOCLUT56) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT57_REG_OFST        _UINT32_(0x13E4)    /* (LCDC_HEOCLUT57) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT58_REG_OFST        _UINT32_(0x13E8)    /* (LCDC_HEOCLUT58) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT59_REG_OFST        _UINT32_(0x13EC)    /* (LCDC_HEOCLUT59) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT60_REG_OFST        _UINT32_(0x13F0)    /* (LCDC_HEOCLUT60) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT61_REG_OFST        _UINT32_(0x13F4)    /* (LCDC_HEOCLUT61) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT62_REG_OFST        _UINT32_(0x13F8)    /* (LCDC_HEOCLUT62) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT63_REG_OFST        _UINT32_(0x13FC)    /* (LCDC_HEOCLUT63) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT64_REG_OFST        _UINT32_(0x1400)    /* (LCDC_HEOCLUT64) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT65_REG_OFST        _UINT32_(0x1404)    /* (LCDC_HEOCLUT65) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT66_REG_OFST        _UINT32_(0x1408)    /* (LCDC_HEOCLUT66) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT67_REG_OFST        _UINT32_(0x140C)    /* (LCDC_HEOCLUT67) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT68_REG_OFST        _UINT32_(0x1410)    /* (LCDC_HEOCLUT68) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT69_REG_OFST        _UINT32_(0x1414)    /* (LCDC_HEOCLUT69) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT70_REG_OFST        _UINT32_(0x1418)    /* (LCDC_HEOCLUT70) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT71_REG_OFST        _UINT32_(0x141C)    /* (LCDC_HEOCLUT71) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT72_REG_OFST        _UINT32_(0x1420)    /* (LCDC_HEOCLUT72) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT73_REG_OFST        _UINT32_(0x1424)    /* (LCDC_HEOCLUT73) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT74_REG_OFST        _UINT32_(0x1428)    /* (LCDC_HEOCLUT74) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT75_REG_OFST        _UINT32_(0x142C)    /* (LCDC_HEOCLUT75) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT76_REG_OFST        _UINT32_(0x1430)    /* (LCDC_HEOCLUT76) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT77_REG_OFST        _UINT32_(0x1434)    /* (LCDC_HEOCLUT77) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT78_REG_OFST        _UINT32_(0x1438)    /* (LCDC_HEOCLUT78) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT79_REG_OFST        _UINT32_(0x143C)    /* (LCDC_HEOCLUT79) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT80_REG_OFST        _UINT32_(0x1440)    /* (LCDC_HEOCLUT80) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT81_REG_OFST        _UINT32_(0x1444)    /* (LCDC_HEOCLUT81) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT82_REG_OFST        _UINT32_(0x1448)    /* (LCDC_HEOCLUT82) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT83_REG_OFST        _UINT32_(0x144C)    /* (LCDC_HEOCLUT83) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT84_REG_OFST        _UINT32_(0x1450)    /* (LCDC_HEOCLUT84) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT85_REG_OFST        _UINT32_(0x1454)    /* (LCDC_HEOCLUT85) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT86_REG_OFST        _UINT32_(0x1458)    /* (LCDC_HEOCLUT86) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT87_REG_OFST        _UINT32_(0x145C)    /* (LCDC_HEOCLUT87) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT88_REG_OFST        _UINT32_(0x1460)    /* (LCDC_HEOCLUT88) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT89_REG_OFST        _UINT32_(0x1464)    /* (LCDC_HEOCLUT89) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT90_REG_OFST        _UINT32_(0x1468)    /* (LCDC_HEOCLUT90) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT91_REG_OFST        _UINT32_(0x146C)    /* (LCDC_HEOCLUT91) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT92_REG_OFST        _UINT32_(0x1470)    /* (LCDC_HEOCLUT92) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT93_REG_OFST        _UINT32_(0x1474)    /* (LCDC_HEOCLUT93) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT94_REG_OFST        _UINT32_(0x1478)    /* (LCDC_HEOCLUT94) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT95_REG_OFST        _UINT32_(0x147C)    /* (LCDC_HEOCLUT95) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT96_REG_OFST        _UINT32_(0x1480)    /* (LCDC_HEOCLUT96) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT97_REG_OFST        _UINT32_(0x1484)    /* (LCDC_HEOCLUT97) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT98_REG_OFST        _UINT32_(0x1488)    /* (LCDC_HEOCLUT98) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT99_REG_OFST        _UINT32_(0x148C)    /* (LCDC_HEOCLUT99) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT100_REG_OFST       _UINT32_(0x1490)    /* (LCDC_HEOCLUT100) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT101_REG_OFST       _UINT32_(0x1494)    /* (LCDC_HEOCLUT101) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT102_REG_OFST       _UINT32_(0x1498)    /* (LCDC_HEOCLUT102) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT103_REG_OFST       _UINT32_(0x149C)    /* (LCDC_HEOCLUT103) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT104_REG_OFST       _UINT32_(0x14A0)    /* (LCDC_HEOCLUT104) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT105_REG_OFST       _UINT32_(0x14A4)    /* (LCDC_HEOCLUT105) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT106_REG_OFST       _UINT32_(0x14A8)    /* (LCDC_HEOCLUT106) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT107_REG_OFST       _UINT32_(0x14AC)    /* (LCDC_HEOCLUT107) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT108_REG_OFST       _UINT32_(0x14B0)    /* (LCDC_HEOCLUT108) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT109_REG_OFST       _UINT32_(0x14B4)    /* (LCDC_HEOCLUT109) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT110_REG_OFST       _UINT32_(0x14B8)    /* (LCDC_HEOCLUT110) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT111_REG_OFST       _UINT32_(0x14BC)    /* (LCDC_HEOCLUT111) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT112_REG_OFST       _UINT32_(0x14C0)    /* (LCDC_HEOCLUT112) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT113_REG_OFST       _UINT32_(0x14C4)    /* (LCDC_HEOCLUT113) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT114_REG_OFST       _UINT32_(0x14C8)    /* (LCDC_HEOCLUT114) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT115_REG_OFST       _UINT32_(0x14CC)    /* (LCDC_HEOCLUT115) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT116_REG_OFST       _UINT32_(0x14D0)    /* (LCDC_HEOCLUT116) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT117_REG_OFST       _UINT32_(0x14D4)    /* (LCDC_HEOCLUT117) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT118_REG_OFST       _UINT32_(0x14D8)    /* (LCDC_HEOCLUT118) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT119_REG_OFST       _UINT32_(0x14DC)    /* (LCDC_HEOCLUT119) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT120_REG_OFST       _UINT32_(0x14E0)    /* (LCDC_HEOCLUT120) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT121_REG_OFST       _UINT32_(0x14E4)    /* (LCDC_HEOCLUT121) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT122_REG_OFST       _UINT32_(0x14E8)    /* (LCDC_HEOCLUT122) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT123_REG_OFST       _UINT32_(0x14EC)    /* (LCDC_HEOCLUT123) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT124_REG_OFST       _UINT32_(0x14F0)    /* (LCDC_HEOCLUT124) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT125_REG_OFST       _UINT32_(0x14F4)    /* (LCDC_HEOCLUT125) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT126_REG_OFST       _UINT32_(0x14F8)    /* (LCDC_HEOCLUT126) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT127_REG_OFST       _UINT32_(0x14FC)    /* (LCDC_HEOCLUT127) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT128_REG_OFST       _UINT32_(0x1500)    /* (LCDC_HEOCLUT128) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT129_REG_OFST       _UINT32_(0x1504)    /* (LCDC_HEOCLUT129) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT130_REG_OFST       _UINT32_(0x1508)    /* (LCDC_HEOCLUT130) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT131_REG_OFST       _UINT32_(0x150C)    /* (LCDC_HEOCLUT131) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT132_REG_OFST       _UINT32_(0x1510)    /* (LCDC_HEOCLUT132) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT133_REG_OFST       _UINT32_(0x1514)    /* (LCDC_HEOCLUT133) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT134_REG_OFST       _UINT32_(0x1518)    /* (LCDC_HEOCLUT134) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT135_REG_OFST       _UINT32_(0x151C)    /* (LCDC_HEOCLUT135) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT136_REG_OFST       _UINT32_(0x1520)    /* (LCDC_HEOCLUT136) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT137_REG_OFST       _UINT32_(0x1524)    /* (LCDC_HEOCLUT137) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT138_REG_OFST       _UINT32_(0x1528)    /* (LCDC_HEOCLUT138) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT139_REG_OFST       _UINT32_(0x152C)    /* (LCDC_HEOCLUT139) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT140_REG_OFST       _UINT32_(0x1530)    /* (LCDC_HEOCLUT140) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT141_REG_OFST       _UINT32_(0x1534)    /* (LCDC_HEOCLUT141) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT142_REG_OFST       _UINT32_(0x1538)    /* (LCDC_HEOCLUT142) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT143_REG_OFST       _UINT32_(0x153C)    /* (LCDC_HEOCLUT143) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT144_REG_OFST       _UINT32_(0x1540)    /* (LCDC_HEOCLUT144) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT145_REG_OFST       _UINT32_(0x1544)    /* (LCDC_HEOCLUT145) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT146_REG_OFST       _UINT32_(0x1548)    /* (LCDC_HEOCLUT146) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT147_REG_OFST       _UINT32_(0x154C)    /* (LCDC_HEOCLUT147) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT148_REG_OFST       _UINT32_(0x1550)    /* (LCDC_HEOCLUT148) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT149_REG_OFST       _UINT32_(0x1554)    /* (LCDC_HEOCLUT149) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT150_REG_OFST       _UINT32_(0x1558)    /* (LCDC_HEOCLUT150) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT151_REG_OFST       _UINT32_(0x155C)    /* (LCDC_HEOCLUT151) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT152_REG_OFST       _UINT32_(0x1560)    /* (LCDC_HEOCLUT152) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT153_REG_OFST       _UINT32_(0x1564)    /* (LCDC_HEOCLUT153) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT154_REG_OFST       _UINT32_(0x1568)    /* (LCDC_HEOCLUT154) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT155_REG_OFST       _UINT32_(0x156C)    /* (LCDC_HEOCLUT155) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT156_REG_OFST       _UINT32_(0x1570)    /* (LCDC_HEOCLUT156) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT157_REG_OFST       _UINT32_(0x1574)    /* (LCDC_HEOCLUT157) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT158_REG_OFST       _UINT32_(0x1578)    /* (LCDC_HEOCLUT158) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT159_REG_OFST       _UINT32_(0x157C)    /* (LCDC_HEOCLUT159) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT160_REG_OFST       _UINT32_(0x1580)    /* (LCDC_HEOCLUT160) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT161_REG_OFST       _UINT32_(0x1584)    /* (LCDC_HEOCLUT161) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT162_REG_OFST       _UINT32_(0x1588)    /* (LCDC_HEOCLUT162) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT163_REG_OFST       _UINT32_(0x158C)    /* (LCDC_HEOCLUT163) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT164_REG_OFST       _UINT32_(0x1590)    /* (LCDC_HEOCLUT164) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT165_REG_OFST       _UINT32_(0x1594)    /* (LCDC_HEOCLUT165) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT166_REG_OFST       _UINT32_(0x1598)    /* (LCDC_HEOCLUT166) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT167_REG_OFST       _UINT32_(0x159C)    /* (LCDC_HEOCLUT167) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT168_REG_OFST       _UINT32_(0x15A0)    /* (LCDC_HEOCLUT168) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT169_REG_OFST       _UINT32_(0x15A4)    /* (LCDC_HEOCLUT169) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT170_REG_OFST       _UINT32_(0x15A8)    /* (LCDC_HEOCLUT170) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT171_REG_OFST       _UINT32_(0x15AC)    /* (LCDC_HEOCLUT171) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT172_REG_OFST       _UINT32_(0x15B0)    /* (LCDC_HEOCLUT172) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT173_REG_OFST       _UINT32_(0x15B4)    /* (LCDC_HEOCLUT173) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT174_REG_OFST       _UINT32_(0x15B8)    /* (LCDC_HEOCLUT174) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT175_REG_OFST       _UINT32_(0x15BC)    /* (LCDC_HEOCLUT175) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT176_REG_OFST       _UINT32_(0x15C0)    /* (LCDC_HEOCLUT176) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT177_REG_OFST       _UINT32_(0x15C4)    /* (LCDC_HEOCLUT177) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT178_REG_OFST       _UINT32_(0x15C8)    /* (LCDC_HEOCLUT178) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT179_REG_OFST       _UINT32_(0x15CC)    /* (LCDC_HEOCLUT179) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT180_REG_OFST       _UINT32_(0x15D0)    /* (LCDC_HEOCLUT180) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT181_REG_OFST       _UINT32_(0x15D4)    /* (LCDC_HEOCLUT181) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT182_REG_OFST       _UINT32_(0x15D8)    /* (LCDC_HEOCLUT182) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT183_REG_OFST       _UINT32_(0x15DC)    /* (LCDC_HEOCLUT183) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT184_REG_OFST       _UINT32_(0x15E0)    /* (LCDC_HEOCLUT184) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT185_REG_OFST       _UINT32_(0x15E4)    /* (LCDC_HEOCLUT185) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT186_REG_OFST       _UINT32_(0x15E8)    /* (LCDC_HEOCLUT186) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT187_REG_OFST       _UINT32_(0x15EC)    /* (LCDC_HEOCLUT187) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT188_REG_OFST       _UINT32_(0x15F0)    /* (LCDC_HEOCLUT188) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT189_REG_OFST       _UINT32_(0x15F4)    /* (LCDC_HEOCLUT189) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT190_REG_OFST       _UINT32_(0x15F8)    /* (LCDC_HEOCLUT190) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT191_REG_OFST       _UINT32_(0x15FC)    /* (LCDC_HEOCLUT191) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT192_REG_OFST       _UINT32_(0x1600)    /* (LCDC_HEOCLUT192) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT193_REG_OFST       _UINT32_(0x1604)    /* (LCDC_HEOCLUT193) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT194_REG_OFST       _UINT32_(0x1608)    /* (LCDC_HEOCLUT194) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT195_REG_OFST       _UINT32_(0x160C)    /* (LCDC_HEOCLUT195) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT196_REG_OFST       _UINT32_(0x1610)    /* (LCDC_HEOCLUT196) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT197_REG_OFST       _UINT32_(0x1614)    /* (LCDC_HEOCLUT197) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT198_REG_OFST       _UINT32_(0x1618)    /* (LCDC_HEOCLUT198) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT199_REG_OFST       _UINT32_(0x161C)    /* (LCDC_HEOCLUT199) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT200_REG_OFST       _UINT32_(0x1620)    /* (LCDC_HEOCLUT200) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT201_REG_OFST       _UINT32_(0x1624)    /* (LCDC_HEOCLUT201) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT202_REG_OFST       _UINT32_(0x1628)    /* (LCDC_HEOCLUT202) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT203_REG_OFST       _UINT32_(0x162C)    /* (LCDC_HEOCLUT203) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT204_REG_OFST       _UINT32_(0x1630)    /* (LCDC_HEOCLUT204) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT205_REG_OFST       _UINT32_(0x1634)    /* (LCDC_HEOCLUT205) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT206_REG_OFST       _UINT32_(0x1638)    /* (LCDC_HEOCLUT206) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT207_REG_OFST       _UINT32_(0x163C)    /* (LCDC_HEOCLUT207) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT208_REG_OFST       _UINT32_(0x1640)    /* (LCDC_HEOCLUT208) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT209_REG_OFST       _UINT32_(0x1644)    /* (LCDC_HEOCLUT209) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT210_REG_OFST       _UINT32_(0x1648)    /* (LCDC_HEOCLUT210) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT211_REG_OFST       _UINT32_(0x164C)    /* (LCDC_HEOCLUT211) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT212_REG_OFST       _UINT32_(0x1650)    /* (LCDC_HEOCLUT212) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT213_REG_OFST       _UINT32_(0x1654)    /* (LCDC_HEOCLUT213) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT214_REG_OFST       _UINT32_(0x1658)    /* (LCDC_HEOCLUT214) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT215_REG_OFST       _UINT32_(0x165C)    /* (LCDC_HEOCLUT215) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT216_REG_OFST       _UINT32_(0x1660)    /* (LCDC_HEOCLUT216) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT217_REG_OFST       _UINT32_(0x1664)    /* (LCDC_HEOCLUT217) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT218_REG_OFST       _UINT32_(0x1668)    /* (LCDC_HEOCLUT218) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT219_REG_OFST       _UINT32_(0x166C)    /* (LCDC_HEOCLUT219) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT220_REG_OFST       _UINT32_(0x1670)    /* (LCDC_HEOCLUT220) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT221_REG_OFST       _UINT32_(0x1674)    /* (LCDC_HEOCLUT221) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT222_REG_OFST       _UINT32_(0x1678)    /* (LCDC_HEOCLUT222) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT223_REG_OFST       _UINT32_(0x167C)    /* (LCDC_HEOCLUT223) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT224_REG_OFST       _UINT32_(0x1680)    /* (LCDC_HEOCLUT224) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT225_REG_OFST       _UINT32_(0x1684)    /* (LCDC_HEOCLUT225) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT226_REG_OFST       _UINT32_(0x1688)    /* (LCDC_HEOCLUT226) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT227_REG_OFST       _UINT32_(0x168C)    /* (LCDC_HEOCLUT227) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT228_REG_OFST       _UINT32_(0x1690)    /* (LCDC_HEOCLUT228) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT229_REG_OFST       _UINT32_(0x1694)    /* (LCDC_HEOCLUT229) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT230_REG_OFST       _UINT32_(0x1698)    /* (LCDC_HEOCLUT230) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT231_REG_OFST       _UINT32_(0x169C)    /* (LCDC_HEOCLUT231) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT232_REG_OFST       _UINT32_(0x16A0)    /* (LCDC_HEOCLUT232) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT233_REG_OFST       _UINT32_(0x16A4)    /* (LCDC_HEOCLUT233) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT234_REG_OFST       _UINT32_(0x16A8)    /* (LCDC_HEOCLUT234) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT235_REG_OFST       _UINT32_(0x16AC)    /* (LCDC_HEOCLUT235) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT236_REG_OFST       _UINT32_(0x16B0)    /* (LCDC_HEOCLUT236) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT237_REG_OFST       _UINT32_(0x16B4)    /* (LCDC_HEOCLUT237) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT238_REG_OFST       _UINT32_(0x16B8)    /* (LCDC_HEOCLUT238) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT239_REG_OFST       _UINT32_(0x16BC)    /* (LCDC_HEOCLUT239) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT240_REG_OFST       _UINT32_(0x16C0)    /* (LCDC_HEOCLUT240) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT241_REG_OFST       _UINT32_(0x16C4)    /* (LCDC_HEOCLUT241) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT242_REG_OFST       _UINT32_(0x16C8)    /* (LCDC_HEOCLUT242) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT243_REG_OFST       _UINT32_(0x16CC)    /* (LCDC_HEOCLUT243) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT244_REG_OFST       _UINT32_(0x16D0)    /* (LCDC_HEOCLUT244) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT245_REG_OFST       _UINT32_(0x16D4)    /* (LCDC_HEOCLUT245) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT246_REG_OFST       _UINT32_(0x16D8)    /* (LCDC_HEOCLUT246) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT247_REG_OFST       _UINT32_(0x16DC)    /* (LCDC_HEOCLUT247) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT248_REG_OFST       _UINT32_(0x16E0)    /* (LCDC_HEOCLUT248) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT249_REG_OFST       _UINT32_(0x16E4)    /* (LCDC_HEOCLUT249) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT250_REG_OFST       _UINT32_(0x16E8)    /* (LCDC_HEOCLUT250) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT251_REG_OFST       _UINT32_(0x16EC)    /* (LCDC_HEOCLUT251) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT252_REG_OFST       _UINT32_(0x16F0)    /* (LCDC_HEOCLUT252) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT253_REG_OFST       _UINT32_(0x16F4)    /* (LCDC_HEOCLUT253) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT254_REG_OFST       _UINT32_(0x16F8)    /* (LCDC_HEOCLUT254) High-End Overlay CLUT Register x Offset */
#define LCDC_HEOCLUT255_REG_OFST       _UINT32_(0x16FC)    /* (LCDC_HEOCLUT255) High-End Overlay CLUT Register x Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief LCDC_HEO register API structure */
typedef struct
{
  __IO  uint32_t                       LCDC_HEOYFBA;       /**< Offset: 0x00 (R/W  32) High-End Overlay Y Frame Buffer x Addr */
  __IO  uint32_t                       LCDC_HEOCBFBA;      /**< Offset: 0x04 (R/W  32) High-End Overlay Cb Frame Buffer x Addr */
  __IO  uint32_t                       LCDC_HEOCRFBA;      /**< Offset: 0x08 (R/W  32) High-End Overlay Cr Frame Buffer x Addr */
} lcdc_heo_registers_t;

/** \brief LCDC_HEOHTAP register API structure */
typedef struct
{
  __IO  uint32_t                       LCDC_HEOHTAP10P;    /**< Offset: 0x00 (R/W  32) High-End Overlay HXS T10 Phi Register  */
  __IO  uint32_t                       LCDC_HEOHTAP32P;    /**< Offset: 0x04 (R/W  32) High-End Overlay HXS T32 Phi Register  */
} lcdc_heohtap_registers_t;

/** \brief LCDC_HEOVTAP register API structure */
typedef struct
{
  __IO  uint32_t                       LCDC_HEOVTAP10P;    /**< Offset: 0x00 (R/W  32) High-End Overlay VXS T10 Phi Register  */
  __IO  uint32_t                       LCDC_HEOVTAP32P;    /**< Offset: 0x04 (R/W  32) High-End Overlay VXS T32 Phi Register  */
} lcdc_heovtap_registers_t;

#define LCDC_HEO_NUMBER 2

#define LCDC_HEOVTAP_NUMBER 16

#define LCDC_HEOHTAP_NUMBER 16

/** \brief LCDC register API structure */
typedef struct
{  /* LCD Controller */
  __IO  uint32_t                       LCDC_LCDCFG0;       /**< Offset: 0x00 (R/W  32) Configuration Register 0 */
  __IO  uint32_t                       LCDC_LCDCFG1;       /**< Offset: 0x04 (R/W  32) Configuration Register 1 */
  __IO  uint32_t                       LCDC_LCDCFG2;       /**< Offset: 0x08 (R/W  32) Configuration Register 2 */
  __IO  uint32_t                       LCDC_LCDCFG3;       /**< Offset: 0x0C (R/W  32) Configuration Register 3 */
  __IO  uint32_t                       LCDC_LCDCFG4;       /**< Offset: 0x10 (R/W  32) Configuration Register 4 */
  __IO  uint32_t                       LCDC_LCDCFG5;       /**< Offset: 0x14 (R/W  32) Configuration Register 5 */
  __IO  uint32_t                       LCDC_LCDCFG6;       /**< Offset: 0x18 (R/W  32) Configuration Register 6 */
  __IO  uint32_t                       LCDC_LCDCFG7;       /**< Offset: 0x1C (R/W  32) Configuration Register 7 */
  __O   uint32_t                       LCDC_LCDEN;         /**< Offset: 0x20 ( /W  32) Enable Register */
  __O   uint32_t                       LCDC_LCDDIS;        /**< Offset: 0x24 ( /W  32) Disable Register */
  __I   uint32_t                       LCDC_LCDSR;         /**< Offset: 0x28 (R/   32) Status Register */
  __O   uint32_t                       LCDC_LCDIER;        /**< Offset: 0x2C ( /W  32) Interrupt Enable Register */
  __O   uint32_t                       LCDC_LCDIDR;        /**< Offset: 0x30 ( /W  32) Interrupt Disable Register */
  __I   uint32_t                       LCDC_LCDIMR;        /**< Offset: 0x34 (R/   32) Interrupt Mask Register */
  __I   uint32_t                       LCDC_LCDISR;        /**< Offset: 0x38 (R/   32) Interrupt Status Register */
  __O   uint32_t                       LCDC_ATTRE;         /**< Offset: 0x3C ( /W  32) Attribute Enable Register */
  __I   uint32_t                       LCDC_ATTRS;         /**< Offset: 0x40 (R/   32) Attribute Status Register */
  __I   uint8_t                        Reserved1[0x1C];
  __O   uint32_t                       LCDC_BASEIER;       /**< Offset: 0x60 ( /W  32) Base Layer Interrupt Enable Register */
  __O   uint32_t                       LCDC_BASEIDR;       /**< Offset: 0x64 ( /W  32) Base Layer Interrupt Disable Register */
  __I   uint32_t                       LCDC_BASEIMR;       /**< Offset: 0x68 (R/   32) Base Layer Interrupt Mask Register */
  __I   uint32_t                       LCDC_BASEISR;       /**< Offset: 0x6C (R/   32) Base Layer Interrupt Status Register */
  __IO  uint32_t                       LCDC_BASEEN;        /**< Offset: 0x70 (R/W  32) Base Layer Enable Register */
  __IO  uint32_t                       LCDC_BASECLA;       /**< Offset: 0x74 (R/W  32) Base Layer Color Table Address Register */
  __IO  uint32_t                       LCDC_BASEFBA;       /**< Offset: 0x78 (R/W  32) Base Layer Frame Buffer Address Register */
  __IO  uint32_t                       LCDC_BASECFG0;      /**< Offset: 0x7C (R/W  32) Base Layer Configuration Register 0 */
  __IO  uint32_t                       LCDC_BASECFG1;      /**< Offset: 0x80 (R/W  32) Base Layer Configuration Register 1 */
  __IO  uint32_t                       LCDC_BASECFG2;      /**< Offset: 0x84 (R/W  32) Base Layer Configuration Register 2 */
  __IO  uint32_t                       LCDC_BASECFG3;      /**< Offset: 0x88 (R/W  32) Base Layer Configuration Register 3 */
  __IO  uint32_t                       LCDC_BASECFG4;      /**< Offset: 0x8C (R/W  32) Base Layer Configuration Register 4 */
  __IO  uint32_t                       LCDC_BASECFG5;      /**< Offset: 0x90 (R/W  32) Base Layer Configuration Register 5 */
  __IO  uint32_t                       LCDC_BASECFG6;      /**< Offset: 0x94 (R/W  32) Base Layer Configuration Register 6 */
  __I   uint8_t                        Reserved2[0x4C];
  __IO  uint32_t                       LCDC_WPMR;          /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
  __I   uint32_t                       LCDC_WPSR;          /**< Offset: 0xE8 (R/   32) Write Protection Status Register */
  __I   uint8_t                        Reserved3[0x74];
  __O   uint32_t                       LCDC_OVR1IER;       /**< Offset: 0x160 ( /W  32) Overlay 1 Interrupt Enable Register */
  __O   uint32_t                       LCDC_OVR1IDR;       /**< Offset: 0x164 ( /W  32) Overlay 1 Interrupt Disable Register */
  __I   uint32_t                       LCDC_OVR1IMR;       /**< Offset: 0x168 (R/   32) Overlay 1 Interrupt Mask Register */
  __I   uint32_t                       LCDC_OVR1ISR;       /**< Offset: 0x16C (R/   32) Overlay 1 Interrupt Status Register */
  __IO  uint32_t                       LCDC_OVR1EN;        /**< Offset: 0x170 (R/W  32) Overlay 1 Enable Register */
  __IO  uint32_t                       LCDC_OVR1CLA;       /**< Offset: 0x174 (R/W  32) Overlay 1 Color Table Address Register */
  __IO  uint32_t                       LCDC_OVR1FBA;       /**< Offset: 0x178 (R/W  32) Overlay 1 Frame Buffer Address Register */
  __IO  uint32_t                       LCDC_OVR1CFG0;      /**< Offset: 0x17C (R/W  32) Overlay 1 Configuration Register 0 */
  __IO  uint32_t                       LCDC_OVR1CFG1;      /**< Offset: 0x180 (R/W  32) Overlay 1 Configuration Register 1 */
  __IO  uint32_t                       LCDC_OVR1CFG2;      /**< Offset: 0x184 (R/W  32) Overlay 1 Configuration Register 2 */
  __IO  uint32_t                       LCDC_OVR1CFG3;      /**< Offset: 0x188 (R/W  32) Overlay 1 Configuration Register 3 */
  __IO  uint32_t                       LCDC_OVR1CFG4;      /**< Offset: 0x18C (R/W  32) Overlay 1 Configuration Register 4 */
  __IO  uint32_t                       LCDC_OVR1CFG5;      /**< Offset: 0x190 (R/W  32) Overlay 1 Configuration Register 5 */
  __IO  uint32_t                       LCDC_OVR1CFG6;      /**< Offset: 0x194 (R/W  32) Overlay 1 Configuration Register 6 */
  __IO  uint32_t                       LCDC_OVR1CFG7;      /**< Offset: 0x198 (R/W  32) Overlay 1 Configuration Register 7 */
  __IO  uint32_t                       LCDC_OVR1CFG8;      /**< Offset: 0x19C (R/W  32) Overlay 1 Configuration Register 8 */
  __IO  uint32_t                       LCDC_OVR1CFG9;      /**< Offset: 0x1A0 (R/W  32) Overlay 1 Configuration Register 9 */
  __I   uint8_t                        Reserved4[0xBC];
  __O   uint32_t                       LCDC_OVR2IER;       /**< Offset: 0x260 ( /W  32) Overlay 2 Interrupt Enable Register */
  __O   uint32_t                       LCDC_OVR2IDR;       /**< Offset: 0x264 ( /W  32) Overlay 2 Interrupt Disable Register */
  __I   uint32_t                       LCDC_OVR2IMR;       /**< Offset: 0x268 (R/   32) Overlay 2 Interrupt Mask Register */
  __I   uint32_t                       LCDC_OVR2ISR;       /**< Offset: 0x26C (R/   32) Overlay 2 Interrupt Status Register */
  __IO  uint32_t                       LCDC_OVR2EN;        /**< Offset: 0x270 (R/W  32) Overlay 2 Enable Register */
  __IO  uint32_t                       LCDC_OVR2CLA;       /**< Offset: 0x274 (R/W  32) Overlay 2 Color Table Address Register */
  __IO  uint32_t                       LCDC_OVR2FBA;       /**< Offset: 0x278 (R/W  32) Overlay 2 Frame Buffer Address Register */
  __IO  uint32_t                       LCDC_OVR2CFG0;      /**< Offset: 0x27C (R/W  32) Overlay 2 Configuration Register 0 */
  __IO  uint32_t                       LCDC_OVR2CFG1;      /**< Offset: 0x280 (R/W  32) Overlay 2 Configuration Register 1 */
  __IO  uint32_t                       LCDC_OVR2CFG2;      /**< Offset: 0x284 (R/W  32) Overlay 2 Configuration Register 2 */
  __IO  uint32_t                       LCDC_OVR2CFG3;      /**< Offset: 0x288 (R/W  32) Overlay 2 Configuration Register 3 */
  __IO  uint32_t                       LCDC_OVR2CFG4;      /**< Offset: 0x28C (R/W  32) Overlay 2 Configuration Register 4 */
  __IO  uint32_t                       LCDC_OVR2CFG5;      /**< Offset: 0x290 (R/W  32) Overlay 2 Configuration Register 5 */
  __IO  uint32_t                       LCDC_OVR2CFG6;      /**< Offset: 0x294 (R/W  32) Overlay 2 Configuration Register 6 */
  __IO  uint32_t                       LCDC_OVR2CFG7;      /**< Offset: 0x298 (R/W  32) Overlay 2 Configuration Register 7 */
  __IO  uint32_t                       LCDC_OVR2CFG8;      /**< Offset: 0x29C (R/W  32) Overlay 2 Configuration Register 8 */
  __IO  uint32_t                       LCDC_OVR2CFG9;      /**< Offset: 0x2A0 (R/W  32) Overlay 2 Configuration Register 9 */
  __I   uint8_t                        Reserved5[0xBC];
  __O   uint32_t                       LCDC_HEOIER;        /**< Offset: 0x360 ( /W  32) High-End Overlay Interrupt Enable Register */
  __O   uint32_t                       LCDC_HEOIDR;        /**< Offset: 0x364 ( /W  32) High-End Overlay Interrupt Disable Register */
  __I   uint32_t                       LCDC_HEOIMR;        /**< Offset: 0x368 (R/   32) High-End Overlay Interrupt Mask Register */
  __I   uint32_t                       LCDC_HEOISR;        /**< Offset: 0x36C (R/   32) High-End Overlay Interrupt Status Register */
  __IO  uint32_t                       LCDC_HEOEN;         /**< Offset: 0x370 (R/W  32) High-End Overlay Enable Register */
  __IO  uint32_t                       LCDC_HEOCLA;        /**< Offset: 0x374 (R/W  32) High-End Overlay Table Address Register */
        lcdc_heo_registers_t           LCDC_HEO[LCDC_HEO_NUMBER]; /**< Offset: 0x378  */
  __IO  uint32_t                       LCDC_HEOCFG0;       /**< Offset: 0x390 (R/W  32) High-End Overlay Configuration Register 0 */
  __IO  uint32_t                       LCDC_HEOCFG1;       /**< Offset: 0x394 (R/W  32) High-End Overlay Configuration Register 1 */
  __IO  uint32_t                       LCDC_HEOCFG2;       /**< Offset: 0x398 (R/W  32) High-End Overlay Configuration Register 2 */
  __IO  uint32_t                       LCDC_HEOCFG3;       /**< Offset: 0x39C (R/W  32) High-End Overlay Configuration Register 3 */
  __IO  uint32_t                       LCDC_HEOCFG4;       /**< Offset: 0x3A0 (R/W  32) High-End Overlay Configuration Register 4 */
  __IO  uint32_t                       LCDC_HEOCFG5;       /**< Offset: 0x3A4 (R/W  32) High-End Overlay Configuration Register 5 */
  __IO  uint32_t                       LCDC_HEOCFG6;       /**< Offset: 0x3A8 (R/W  32) High-End Overlay Configuration Register 6 */
  __IO  uint32_t                       LCDC_HEOCFG7;       /**< Offset: 0x3AC (R/W  32) High-End Overlay Configuration Register 7 */
  __IO  uint32_t                       LCDC_HEOCFG8;       /**< Offset: 0x3B0 (R/W  32) High-End Overlay Configuration Register 8 */
  __IO  uint32_t                       LCDC_HEOCFG9;       /**< Offset: 0x3B4 (R/W  32) High-End Overlay Configuration Register 9 */
  __IO  uint32_t                       LCDC_HEOCFG10;      /**< Offset: 0x3B8 (R/W  32) High-End Overlay Configuration Register 10 */
  __IO  uint32_t                       LCDC_HEOCFG11;      /**< Offset: 0x3BC (R/W  32) High-End Overlay Configuration Register 11 */
  __IO  uint32_t                       LCDC_HEOCFG12;      /**< Offset: 0x3C0 (R/W  32) High-End Overlay Configuration Register 12 */
  __IO  uint32_t                       LCDC_HEOCFG13;      /**< Offset: 0x3C4 (R/W  32) High-End Overlay Configuration Register 13 */
  __IO  uint32_t                       LCDC_HEOCFG14;      /**< Offset: 0x3C8 (R/W  32) High-End Overlay Configuration Register 14 */
  __IO  uint32_t                       LCDC_HEOCFG15;      /**< Offset: 0x3CC (R/W  32) High-End Overlay Configuration Register 15 */
  __IO  uint32_t                       LCDC_HEOCFG16;      /**< Offset: 0x3D0 (R/W  32) High-End Overlay Configuration Register 16 */
  __IO  uint32_t                       LCDC_HEOCFG17;      /**< Offset: 0x3D4 (R/W  32) High-End Overlay Configuration Register 17 */
  __IO  uint32_t                       LCDC_HEOCFG18;      /**< Offset: 0x3D8 (R/W  32) High-End Overlay Configuration Register 18 */
  __IO  uint32_t                       LCDC_HEOCFG19;      /**< Offset: 0x3DC (R/W  32) High-End Overlay Configuration Register 19 */
  __IO  uint32_t                       LCDC_HEOCFG20;      /**< Offset: 0x3E0 (R/W  32) High-End Overlay Configuration Register 20 */
  __IO  uint32_t                       LCDC_HEOCFG21;      /**< Offset: 0x3E4 (R/W  32) High-End Overlay Configuration Register 21 */
  __IO  uint32_t                       LCDC_HEOCFG22;      /**< Offset: 0x3E8 (R/W  32) High-End Overlay Configuration Register 22 */
  __IO  uint32_t                       LCDC_HEOCFG23;      /**< Offset: 0x3EC (R/W  32) High-End Overlay Configuration Register 23 */
  __IO  uint32_t                       LCDC_HEOCFG24;      /**< Offset: 0x3F0 (R/W  32) High-End Overlay Configuration Register 24 */
  __IO  uint32_t                       LCDC_HEOCFG25;      /**< Offset: 0x3F4 (R/W  32) High-End Overlay Configuration Register 25 */
  __IO  uint32_t                       LCDC_HEOCFG26;      /**< Offset: 0x3F8 (R/W  32) High-End Overlay Configuration Register 26 */
  __IO  uint32_t                       LCDC_HEOCFG27;      /**< Offset: 0x3FC (R/W  32) High-End Overlay Configuration Register 27 */
  __IO  uint32_t                       LCDC_HEOCFG28;      /**< Offset: 0x400 (R/W  32) High-End Overlay Configuration Register 28 */
  __IO  uint32_t                       LCDC_HEOCFG29;      /**< Offset: 0x404 (R/W  32) High-End Overlay Configuration Register 29 */
  __IO  uint32_t                       LCDC_HEOCFG30;      /**< Offset: 0x408 (R/W  32) High-End Overlay Configuration Register 30 */
  __IO  uint32_t                       LCDC_HEOCFG31;      /**< Offset: 0x40C (R/W  32) High-End Overlay Configuration Register 31 */
        lcdc_heovtap_registers_t       LCDC_HEOVTAP[LCDC_HEOVTAP_NUMBER]; /**< Offset: 0x410  */
        lcdc_heohtap_registers_t       LCDC_HEOHTAP[LCDC_HEOHTAP_NUMBER]; /**< Offset: 0x490  */
  __I   uint8_t                        Reserved6[0x1F0];
  __IO  uint32_t                       LCDC_BASECLUT[256]; /**< Offset: 0x700 (R/W  32) Base Layer CLUT Register x */
  __IO  uint32_t                       LCDC_OVR1CLUT[256]; /**< Offset: 0xB00 (R/W  32) Overlay 1 CLUT Register x */
  __IO  uint32_t                       LCDC_OVR2CLUT[256]; /**< Offset: 0xF00 (R/W  32) Overlay 2 CLUT Register x */
  __IO  uint32_t                       LCDC_HEOCLUT[256];  /**< Offset: 0x1300 (R/W  32) High-End Overlay CLUT Register x */
} lcdc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAM9X7_LCDC_COMPONENT_H_ */
