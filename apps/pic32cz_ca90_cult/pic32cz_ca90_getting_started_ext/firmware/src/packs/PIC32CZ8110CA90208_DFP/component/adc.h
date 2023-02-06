/*
 * Component description for ADC
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
#ifndef _PIC32CZCA90_ADC_COMPONENT_H_
#define _PIC32CZCA90_ADC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR ADC                                          */
/* ************************************************************************** */

/* -------- ADC_CORCTRL : (ADC Offset: 0x00) (R/W 32) SARCORE Control -------- */
#define ADC_CORCTRL_RESETVALUE                _UINT32_(0xC00)                                      /*  (ADC_CORCTRL) SARCORE Control  Reset Value */

#define ADC_CORCTRL_SAMC_Pos                  _UINT32_(0)                                          /* (ADC_CORCTRL) Sample Count Position */
#define ADC_CORCTRL_SAMC_Msk                  (_UINT32_(0x3FF) << ADC_CORCTRL_SAMC_Pos)            /* (ADC_CORCTRL) Sample Count Mask */
#define ADC_CORCTRL_SAMC(value)               (ADC_CORCTRL_SAMC_Msk & (_UINT32_(value) << ADC_CORCTRL_SAMC_Pos)) /* Assigment of value for SAMC in the ADC_CORCTRL register */
#define ADC_CORCTRL_SELRES_Pos                _UINT32_(10)                                         /* (ADC_CORCTRL) Selects Resolution Position */
#define ADC_CORCTRL_SELRES_Msk                (_UINT32_(0x3) << ADC_CORCTRL_SELRES_Pos)            /* (ADC_CORCTRL) Selects Resolution Mask */
#define ADC_CORCTRL_SELRES(value)             (ADC_CORCTRL_SELRES_Msk & (_UINT32_(value) << ADC_CORCTRL_SELRES_Pos)) /* Assigment of value for SELRES in the ADC_CORCTRL register */
#define   ADC_CORCTRL_SELRES_6_BITS_Val       _UINT32_(0x0)                                        /* (ADC_CORCTRL) 6 bits  */
#define   ADC_CORCTRL_SELRES_8_BITS_Val       _UINT32_(0x1)                                        /* (ADC_CORCTRL) 8 bits  */
#define   ADC_CORCTRL_SELRES_10_BITS_Val      _UINT32_(0x2)                                        /* (ADC_CORCTRL) 10 bits  */
#define   ADC_CORCTRL_SELRES_12_BITS_Val      _UINT32_(0x3)                                        /* (ADC_CORCTRL) 12 bits (default)  */
#define ADC_CORCTRL_SELRES_6_BITS             (ADC_CORCTRL_SELRES_6_BITS_Val << ADC_CORCTRL_SELRES_Pos) /* (ADC_CORCTRL) 6 bits Position  */
#define ADC_CORCTRL_SELRES_8_BITS             (ADC_CORCTRL_SELRES_8_BITS_Val << ADC_CORCTRL_SELRES_Pos) /* (ADC_CORCTRL) 8 bits Position  */
#define ADC_CORCTRL_SELRES_10_BITS            (ADC_CORCTRL_SELRES_10_BITS_Val << ADC_CORCTRL_SELRES_Pos) /* (ADC_CORCTRL) 10 bits Position  */
#define ADC_CORCTRL_SELRES_12_BITS            (ADC_CORCTRL_SELRES_12_BITS_Val << ADC_CORCTRL_SELRES_Pos) /* (ADC_CORCTRL) 12 bits (default) Position  */
#define ADC_CORCTRL_EIS_Pos                   _UINT32_(12)                                         /* (ADC_CORCTRL) Early Interrupt Select Position */
#define ADC_CORCTRL_EIS_Msk                   (_UINT32_(0x7) << ADC_CORCTRL_EIS_Pos)               /* (ADC_CORCTRL) Early Interrupt Select Mask */
#define ADC_CORCTRL_EIS(value)                (ADC_CORCTRL_EIS_Msk & (_UINT32_(value) << ADC_CORCTRL_EIS_Pos)) /* Assigment of value for EIS in the ADC_CORCTRL register */
#define ADC_CORCTRL_EIRQOVR_Pos               _UINT32_(15)                                         /* (ADC_CORCTRL) Interrupt Type Select Position */
#define ADC_CORCTRL_EIRQOVR_Msk               (_UINT32_(0x1) << ADC_CORCTRL_EIRQOVR_Pos)           /* (ADC_CORCTRL) Interrupt Type Select Mask */
#define ADC_CORCTRL_EIRQOVR(value)            (ADC_CORCTRL_EIRQOVR_Msk & (_UINT32_(value) << ADC_CORCTRL_EIRQOVR_Pos)) /* Assigment of value for EIRQOVR in the ADC_CORCTRL register */
#define ADC_CORCTRL_STRGSRC_Pos               _UINT32_(16)                                         /* (ADC_CORCTRL) SCAN trigger source selection Position */
#define ADC_CORCTRL_STRGSRC_Msk               (_UINT32_(0xF) << ADC_CORCTRL_STRGSRC_Pos)           /* (ADC_CORCTRL) SCAN trigger source selection Mask */
#define ADC_CORCTRL_STRGSRC(value)            (ADC_CORCTRL_STRGSRC_Msk & (_UINT32_(value) << ADC_CORCTRL_STRGSRC_Pos)) /* Assigment of value for STRGSRC in the ADC_CORCTRL register */
#define   ADC_CORCTRL_STRGSRC_NO_TRIGGER_Val  _UINT32_(0x0)                                        /* (ADC_CORCTRL) No Trigger (NOP)  */
#define   ADC_CORCTRL_STRGSRC_GLOBAL_SOFTWARE_TRIGGER_Val _UINT32_(0x1)                                        /* (ADC_CORCTRL) Global Software Trigger  */
#define   ADC_CORCTRL_STRGSRC_GLOBAL_LEVEL_TRIGGER_Val _UINT32_(0x2)                                        /* (ADC_CORCTRL) Global Level Software Trigger  */
#define   ADC_CORCTRL_STRGSRC_SYNC_TRIGGER_Val _UINT32_(0x4)                                        /* (ADC_CORCTRL) STRIG Synchronous Trigger  */
#define   ADC_CORCTRL_STRGSRC_EVENT_USER0_Val _UINT32_(0x5)                                        /* (ADC_CORCTRL) ADC Trigger Event User 0  */
#define   ADC_CORCTRL_STRGSRC_EVENT_USER1_Val _UINT32_(0x6)                                        /* (ADC_CORCTRL) ADC Trigger Event User 1  */
#define   ADC_CORCTRL_STRGSRC_EVENT_USER2_Val _UINT32_(0x7)                                        /* (ADC_CORCTRL) ADC Trigger Event User 2  */
#define   ADC_CORCTRL_STRGSRC_EVENT_USER3_Val _UINT32_(0x8)                                        /* (ADC_CORCTRL) ADC Trigger Event User 3  */
#define   ADC_CORCTRL_STRGSRC_EVENT_USER4_Val _UINT32_(0x9)                                        /* (ADC_CORCTRL) ADC Trigger Event User 4  */
#define   ADC_CORCTRL_STRGSRC_EVENT_USER5_Val _UINT32_(0xA)                                        /* (ADC_CORCTRL) ADC Trigger Event User 5  */
#define   ADC_CORCTRL_STRGSRC_EVENT_USER6_Val _UINT32_(0xB)                                        /* (ADC_CORCTRL) ADC Trigger Event User 6  */
#define   ADC_CORCTRL_STRGSRC_EVENT_USER7_Val _UINT32_(0xC)                                        /* (ADC_CORCTRL) ADC Trigger Event User 7  */
#define   ADC_CORCTRL_STRGSRC_EVENT_USER8_Val _UINT32_(0xD)                                        /* (ADC_CORCTRL) ADC Trigger Event User 8  */
#define   ADC_CORCTRL_STRGSRC_EVENT_USER9_Val _UINT32_(0xE)                                        /* (ADC_CORCTRL) ADC Trigger Event User 9  */
#define   ADC_CORCTRL_STRGSRC_EVENT_USER10_Val _UINT32_(0xF)                                        /* (ADC_CORCTRL) ADC Trigger Event User 10  */
#define ADC_CORCTRL_STRGSRC_NO_TRIGGER        (ADC_CORCTRL_STRGSRC_NO_TRIGGER_Val << ADC_CORCTRL_STRGSRC_Pos) /* (ADC_CORCTRL) No Trigger (NOP) Position  */
#define ADC_CORCTRL_STRGSRC_GLOBAL_SOFTWARE_TRIGGER (ADC_CORCTRL_STRGSRC_GLOBAL_SOFTWARE_TRIGGER_Val << ADC_CORCTRL_STRGSRC_Pos) /* (ADC_CORCTRL) Global Software Trigger Position  */
#define ADC_CORCTRL_STRGSRC_GLOBAL_LEVEL_TRIGGER (ADC_CORCTRL_STRGSRC_GLOBAL_LEVEL_TRIGGER_Val << ADC_CORCTRL_STRGSRC_Pos) /* (ADC_CORCTRL) Global Level Software Trigger Position  */
#define ADC_CORCTRL_STRGSRC_SYNC_TRIGGER      (ADC_CORCTRL_STRGSRC_SYNC_TRIGGER_Val << ADC_CORCTRL_STRGSRC_Pos) /* (ADC_CORCTRL) STRIG Synchronous Trigger Position  */
#define ADC_CORCTRL_STRGSRC_EVENT_USER0       (ADC_CORCTRL_STRGSRC_EVENT_USER0_Val << ADC_CORCTRL_STRGSRC_Pos) /* (ADC_CORCTRL) ADC Trigger Event User 0 Position  */
#define ADC_CORCTRL_STRGSRC_EVENT_USER1       (ADC_CORCTRL_STRGSRC_EVENT_USER1_Val << ADC_CORCTRL_STRGSRC_Pos) /* (ADC_CORCTRL) ADC Trigger Event User 1 Position  */
#define ADC_CORCTRL_STRGSRC_EVENT_USER2       (ADC_CORCTRL_STRGSRC_EVENT_USER2_Val << ADC_CORCTRL_STRGSRC_Pos) /* (ADC_CORCTRL) ADC Trigger Event User 2 Position  */
#define ADC_CORCTRL_STRGSRC_EVENT_USER3       (ADC_CORCTRL_STRGSRC_EVENT_USER3_Val << ADC_CORCTRL_STRGSRC_Pos) /* (ADC_CORCTRL) ADC Trigger Event User 3 Position  */
#define ADC_CORCTRL_STRGSRC_EVENT_USER4       (ADC_CORCTRL_STRGSRC_EVENT_USER4_Val << ADC_CORCTRL_STRGSRC_Pos) /* (ADC_CORCTRL) ADC Trigger Event User 4 Position  */
#define ADC_CORCTRL_STRGSRC_EVENT_USER5       (ADC_CORCTRL_STRGSRC_EVENT_USER5_Val << ADC_CORCTRL_STRGSRC_Pos) /* (ADC_CORCTRL) ADC Trigger Event User 5 Position  */
#define ADC_CORCTRL_STRGSRC_EVENT_USER6       (ADC_CORCTRL_STRGSRC_EVENT_USER6_Val << ADC_CORCTRL_STRGSRC_Pos) /* (ADC_CORCTRL) ADC Trigger Event User 6 Position  */
#define ADC_CORCTRL_STRGSRC_EVENT_USER7       (ADC_CORCTRL_STRGSRC_EVENT_USER7_Val << ADC_CORCTRL_STRGSRC_Pos) /* (ADC_CORCTRL) ADC Trigger Event User 7 Position  */
#define ADC_CORCTRL_STRGSRC_EVENT_USER8       (ADC_CORCTRL_STRGSRC_EVENT_USER8_Val << ADC_CORCTRL_STRGSRC_Pos) /* (ADC_CORCTRL) ADC Trigger Event User 8 Position  */
#define ADC_CORCTRL_STRGSRC_EVENT_USER9       (ADC_CORCTRL_STRGSRC_EVENT_USER9_Val << ADC_CORCTRL_STRGSRC_Pos) /* (ADC_CORCTRL) ADC Trigger Event User 9 Position  */
#define ADC_CORCTRL_STRGSRC_EVENT_USER10      (ADC_CORCTRL_STRGSRC_EVENT_USER10_Val << ADC_CORCTRL_STRGSRC_Pos) /* (ADC_CORCTRL) ADC Trigger Event User 10 Position  */
#define ADC_CORCTRL_STRGLVL_Pos               _UINT32_(21)                                         /* (ADC_CORCTRL) Scan Trigger Level Sensitivity Position */
#define ADC_CORCTRL_STRGLVL_Msk               (_UINT32_(0x1) << ADC_CORCTRL_STRGLVL_Pos)           /* (ADC_CORCTRL) Scan Trigger Level Sensitivity Mask */
#define ADC_CORCTRL_STRGLVL(value)            (ADC_CORCTRL_STRGLVL_Msk & (_UINT32_(value) << ADC_CORCTRL_STRGLVL_Pos)) /* Assigment of value for STRGLVL in the ADC_CORCTRL register */
#define ADC_CORCTRL_SCNRTDS_Pos               _UINT32_(22)                                         /* (ADC_CORCTRL) SCAN Re-trigger Disable Position */
#define ADC_CORCTRL_SCNRTDS_Msk               (_UINT32_(0x1) << ADC_CORCTRL_SCNRTDS_Pos)           /* (ADC_CORCTRL) SCAN Re-trigger Disable Mask */
#define ADC_CORCTRL_SCNRTDS(value)            (ADC_CORCTRL_SCNRTDS_Msk & (_UINT32_(value) << ADC_CORCTRL_SCNRTDS_Pos)) /* Assigment of value for SCNRTDS in the ADC_CORCTRL register */
#define ADC_CORCTRL_ADCDIV_Pos                _UINT32_(24)                                         /* (ADC_CORCTRL) Division Ratio for SARCORE clock Position */
#define ADC_CORCTRL_ADCDIV_Msk                (_UINT32_(0x7F) << ADC_CORCTRL_ADCDIV_Pos)           /* (ADC_CORCTRL) Division Ratio for SARCORE clock Mask */
#define ADC_CORCTRL_ADCDIV(value)             (ADC_CORCTRL_ADCDIV_Msk & (_UINT32_(value) << ADC_CORCTRL_ADCDIV_Pos)) /* Assigment of value for ADCDIV in the ADC_CORCTRL register */
#define ADC_CORCTRL_Msk                       _UINT32_(0x7F6FFFFF)                                 /* (ADC_CORCTRL) Register Mask  */


/* -------- ADC_CHNCFG1 : (ADC Offset: 0x04) (R/W 32) Channel Configuration 1 (LVL/CMPEN) -------- */
#define ADC_CHNCFG1_RESETVALUE                _UINT32_(0x00)                                       /*  (ADC_CHNCFG1) Channel Configuration 1 (LVL/CMPEN)  Reset Value */

#define ADC_CHNCFG1_CHNCMPEN_Pos              _UINT32_(0)                                          /* (ADC_CHNCFG1) Channel Comparator Enable Position */
#define ADC_CHNCFG1_CHNCMPEN_Msk              (_UINT32_(0xFFFF) << ADC_CHNCFG1_CHNCMPEN_Pos)       /* (ADC_CHNCFG1) Channel Comparator Enable Mask */
#define ADC_CHNCFG1_CHNCMPEN(value)           (ADC_CHNCFG1_CHNCMPEN_Msk & (_UINT32_(value) << ADC_CHNCFG1_CHNCMPEN_Pos)) /* Assigment of value for CHNCMPEN in the ADC_CHNCFG1 register */
#define ADC_CHNCFG1_LVL_Pos                   _UINT32_(16)                                         /* (ADC_CHNCFG1) Channel Level Position */
#define ADC_CHNCFG1_LVL_Msk                   (_UINT32_(0xFFFF) << ADC_CHNCFG1_LVL_Pos)            /* (ADC_CHNCFG1) Channel Level Mask */
#define ADC_CHNCFG1_LVL(value)                (ADC_CHNCFG1_LVL_Msk & (_UINT32_(value) << ADC_CHNCFG1_LVL_Pos)) /* Assigment of value for LVL in the ADC_CHNCFG1 register */
#define ADC_CHNCFG1_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (ADC_CHNCFG1) Register Mask  */


/* -------- ADC_CHNCFG2 : (ADC Offset: 0x08) (R/W 32) Channel Configuration 2(FRACT/CSS) -------- */
#define ADC_CHNCFG2_RESETVALUE                _UINT32_(0x00)                                       /*  (ADC_CHNCFG2) Channel Configuration 2(FRACT/CSS)  Reset Value */

#define ADC_CHNCFG2_CSS_Pos                   _UINT32_(0)                                          /* (ADC_CHNCFG2) Channel SCAN Select Position */
#define ADC_CHNCFG2_CSS_Msk                   (_UINT32_(0xFFFF) << ADC_CHNCFG2_CSS_Pos)            /* (ADC_CHNCFG2) Channel SCAN Select Mask */
#define ADC_CHNCFG2_CSS(value)                (ADC_CHNCFG2_CSS_Msk & (_UINT32_(value) << ADC_CHNCFG2_CSS_Pos)) /* Assigment of value for CSS in the ADC_CHNCFG2 register */
#define ADC_CHNCFG2_FRACT_Pos                 _UINT32_(16)                                         /* (ADC_CHNCFG2) Channel Fractional Position */
#define ADC_CHNCFG2_FRACT_Msk                 (_UINT32_(0xFFFF) << ADC_CHNCFG2_FRACT_Pos)          /* (ADC_CHNCFG2) Channel Fractional Mask */
#define ADC_CHNCFG2_FRACT(value)              (ADC_CHNCFG2_FRACT_Msk & (_UINT32_(value) << ADC_CHNCFG2_FRACT_Pos)) /* Assigment of value for FRACT in the ADC_CHNCFG2 register */
#define ADC_CHNCFG2_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (ADC_CHNCFG2) Register Mask  */


/* -------- ADC_CHNCFG3 : (ADC Offset: 0x0C) (R/W 32) Channel Configuration3 (SIGN/DIFF) -------- */
#define ADC_CHNCFG3_RESETVALUE                _UINT32_(0x00)                                       /*  (ADC_CHNCFG3) Channel Configuration3 (SIGN/DIFF)  Reset Value */

#define ADC_CHNCFG3_DIFF_Pos                  _UINT32_(0)                                          /* (ADC_CHNCFG3) Differential Mode Position */
#define ADC_CHNCFG3_DIFF_Msk                  (_UINT32_(0xFFFF) << ADC_CHNCFG3_DIFF_Pos)           /* (ADC_CHNCFG3) Differential Mode Mask */
#define ADC_CHNCFG3_DIFF(value)               (ADC_CHNCFG3_DIFF_Msk & (_UINT32_(value) << ADC_CHNCFG3_DIFF_Pos)) /* Assigment of value for DIFF in the ADC_CHNCFG3 register */
#define ADC_CHNCFG3_SIGN_Pos                  _UINT32_(16)                                         /* (ADC_CHNCFG3) SIGN setting Position */
#define ADC_CHNCFG3_SIGN_Msk                  (_UINT32_(0xFFFF) << ADC_CHNCFG3_SIGN_Pos)           /* (ADC_CHNCFG3) SIGN setting Mask */
#define ADC_CHNCFG3_SIGN(value)               (ADC_CHNCFG3_SIGN_Msk & (_UINT32_(value) << ADC_CHNCFG3_SIGN_Pos)) /* Assigment of value for SIGN in the ADC_CHNCFG3 register */
#define ADC_CHNCFG3_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (ADC_CHNCFG3) Register Mask  */


/* -------- ADC_CHNCFG4 : (ADC Offset: 0x10) (R/W 32) Channel Configuration 4 (TRGSRC) -------- */
#define ADC_CHNCFG4_RESETVALUE                _UINT32_(0x00)                                       /*  (ADC_CHNCFG4) Channel Configuration 4 (TRGSRC)  Reset Value */

#define ADC_CHNCFG4_TRGSRC0_Pos               _UINT32_(0)                                          /* (ADC_CHNCFG4) Channel 0 Trigger Source Position */
#define ADC_CHNCFG4_TRGSRC0_Msk               (_UINT32_(0xF) << ADC_CHNCFG4_TRGSRC0_Pos)           /* (ADC_CHNCFG4) Channel 0 Trigger Source Mask */
#define ADC_CHNCFG4_TRGSRC0(value)            (ADC_CHNCFG4_TRGSRC0_Msk & (_UINT32_(value) << ADC_CHNCFG4_TRGSRC0_Pos)) /* Assigment of value for TRGSRC0 in the ADC_CHNCFG4 register */
#define   ADC_CHNCFG4_TRGSRC0_NO_TRIGGER_Val  _UINT32_(0x0)                                        /* (ADC_CHNCFG4) No Trigger (NOP)  */
#define   ADC_CHNCFG4_TRGSRC0_GLOBAL_SOFTWARE_TRIGGER_Val _UINT32_(0x1)                                        /* (ADC_CHNCFG4) Global Software Trigger  */
#define   ADC_CHNCFG4_TRGSRC0_GLOBAL_LEVEL_TRIGGER_Val _UINT32_(0x2)                                        /* (ADC_CHNCFG4) Global Level Software Trigger  */
#define   ADC_CHNCFG4_TRGSRC0_SCAN_TRIGGER_Val _UINT32_(0x3)                                        /* (ADC_CHNCFG4) SCANTRG - Scan Trigger  */
#define   ADC_CHNCFG4_TRGSRC0_SYNC_TRIGGER_Val _UINT32_(0x4)                                        /* (ADC_CHNCFG4) STRIG Synchronous Trigger  */
#define   ADC_CHNCFG4_TRGSRC0_EVENT_USER0_Val _UINT32_(0x5)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 0  */
#define   ADC_CHNCFG4_TRGSRC0_EVENT_USER1_Val _UINT32_(0x6)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 1  */
#define   ADC_CHNCFG4_TRGSRC0_EVENT_USER2_Val _UINT32_(0x7)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 2  */
#define   ADC_CHNCFG4_TRGSRC0_EVENT_USER3_Val _UINT32_(0x8)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 3  */
#define   ADC_CHNCFG4_TRGSRC0_EVENT_USER4_Val _UINT32_(0x9)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 4  */
#define   ADC_CHNCFG4_TRGSRC0_EVENT_USER5_Val _UINT32_(0xA)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 5  */
#define   ADC_CHNCFG4_TRGSRC0_EVENT_USER6_Val _UINT32_(0xB)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 6  */
#define   ADC_CHNCFG4_TRGSRC0_EVENT_USER7_Val _UINT32_(0xC)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 7  */
#define   ADC_CHNCFG4_TRGSRC0_EVENT_USER8_Val _UINT32_(0xD)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 8  */
#define   ADC_CHNCFG4_TRGSRC0_EVENT_USER9_Val _UINT32_(0xE)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 9  */
#define   ADC_CHNCFG4_TRGSRC0_EVENT_USER10_Val _UINT32_(0xF)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 10  */
#define ADC_CHNCFG4_TRGSRC0_NO_TRIGGER        (ADC_CHNCFG4_TRGSRC0_NO_TRIGGER_Val << ADC_CHNCFG4_TRGSRC0_Pos) /* (ADC_CHNCFG4) No Trigger (NOP) Position  */
#define ADC_CHNCFG4_TRGSRC0_GLOBAL_SOFTWARE_TRIGGER (ADC_CHNCFG4_TRGSRC0_GLOBAL_SOFTWARE_TRIGGER_Val << ADC_CHNCFG4_TRGSRC0_Pos) /* (ADC_CHNCFG4) Global Software Trigger Position  */
#define ADC_CHNCFG4_TRGSRC0_GLOBAL_LEVEL_TRIGGER (ADC_CHNCFG4_TRGSRC0_GLOBAL_LEVEL_TRIGGER_Val << ADC_CHNCFG4_TRGSRC0_Pos) /* (ADC_CHNCFG4) Global Level Software Trigger Position  */
#define ADC_CHNCFG4_TRGSRC0_SCAN_TRIGGER      (ADC_CHNCFG4_TRGSRC0_SCAN_TRIGGER_Val << ADC_CHNCFG4_TRGSRC0_Pos) /* (ADC_CHNCFG4) SCANTRG - Scan Trigger Position  */
#define ADC_CHNCFG4_TRGSRC0_SYNC_TRIGGER      (ADC_CHNCFG4_TRGSRC0_SYNC_TRIGGER_Val << ADC_CHNCFG4_TRGSRC0_Pos) /* (ADC_CHNCFG4) STRIG Synchronous Trigger Position  */
#define ADC_CHNCFG4_TRGSRC0_EVENT_USER0       (ADC_CHNCFG4_TRGSRC0_EVENT_USER0_Val << ADC_CHNCFG4_TRGSRC0_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 0 Position  */
#define ADC_CHNCFG4_TRGSRC0_EVENT_USER1       (ADC_CHNCFG4_TRGSRC0_EVENT_USER1_Val << ADC_CHNCFG4_TRGSRC0_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 1 Position  */
#define ADC_CHNCFG4_TRGSRC0_EVENT_USER2       (ADC_CHNCFG4_TRGSRC0_EVENT_USER2_Val << ADC_CHNCFG4_TRGSRC0_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 2 Position  */
#define ADC_CHNCFG4_TRGSRC0_EVENT_USER3       (ADC_CHNCFG4_TRGSRC0_EVENT_USER3_Val << ADC_CHNCFG4_TRGSRC0_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 3 Position  */
#define ADC_CHNCFG4_TRGSRC0_EVENT_USER4       (ADC_CHNCFG4_TRGSRC0_EVENT_USER4_Val << ADC_CHNCFG4_TRGSRC0_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 4 Position  */
#define ADC_CHNCFG4_TRGSRC0_EVENT_USER5       (ADC_CHNCFG4_TRGSRC0_EVENT_USER5_Val << ADC_CHNCFG4_TRGSRC0_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 5 Position  */
#define ADC_CHNCFG4_TRGSRC0_EVENT_USER6       (ADC_CHNCFG4_TRGSRC0_EVENT_USER6_Val << ADC_CHNCFG4_TRGSRC0_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 6 Position  */
#define ADC_CHNCFG4_TRGSRC0_EVENT_USER7       (ADC_CHNCFG4_TRGSRC0_EVENT_USER7_Val << ADC_CHNCFG4_TRGSRC0_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 7 Position  */
#define ADC_CHNCFG4_TRGSRC0_EVENT_USER8       (ADC_CHNCFG4_TRGSRC0_EVENT_USER8_Val << ADC_CHNCFG4_TRGSRC0_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 8 Position  */
#define ADC_CHNCFG4_TRGSRC0_EVENT_USER9       (ADC_CHNCFG4_TRGSRC0_EVENT_USER9_Val << ADC_CHNCFG4_TRGSRC0_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 9 Position  */
#define ADC_CHNCFG4_TRGSRC0_EVENT_USER10      (ADC_CHNCFG4_TRGSRC0_EVENT_USER10_Val << ADC_CHNCFG4_TRGSRC0_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 10 Position  */
#define ADC_CHNCFG4_TRGSRC1_Pos               _UINT32_(4)                                          /* (ADC_CHNCFG4) Channel 1 Trigger Source Position */
#define ADC_CHNCFG4_TRGSRC1_Msk               (_UINT32_(0xF) << ADC_CHNCFG4_TRGSRC1_Pos)           /* (ADC_CHNCFG4) Channel 1 Trigger Source Mask */
#define ADC_CHNCFG4_TRGSRC1(value)            (ADC_CHNCFG4_TRGSRC1_Msk & (_UINT32_(value) << ADC_CHNCFG4_TRGSRC1_Pos)) /* Assigment of value for TRGSRC1 in the ADC_CHNCFG4 register */
#define   ADC_CHNCFG4_TRGSRC1_NO_TRIGGER_Val  _UINT32_(0x0)                                        /* (ADC_CHNCFG4) No Trigger (NOP)  */
#define   ADC_CHNCFG4_TRGSRC1_GLOBAL_SOFTWARE_TRIGGER_Val _UINT32_(0x1)                                        /* (ADC_CHNCFG4) Global Software Trigger  */
#define   ADC_CHNCFG4_TRGSRC1_GLOBAL_LEVEL_TRIGGER_Val _UINT32_(0x2)                                        /* (ADC_CHNCFG4) Global Level Software Trigger  */
#define   ADC_CHNCFG4_TRGSRC1_SCAN_TRIGGER_Val _UINT32_(0x3)                                        /* (ADC_CHNCFG4) SCANTRG - Scan Trigger  */
#define   ADC_CHNCFG4_TRGSRC1_SYNC_TRIGGER_Val _UINT32_(0x4)                                        /* (ADC_CHNCFG4) STRIG Synchronous Trigger  */
#define   ADC_CHNCFG4_TRGSRC1_EVENT_USER0_Val _UINT32_(0x5)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 0  */
#define   ADC_CHNCFG4_TRGSRC1_EVENT_USER1_Val _UINT32_(0x6)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 1  */
#define   ADC_CHNCFG4_TRGSRC1_EVENT_USER2_Val _UINT32_(0x7)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 2  */
#define   ADC_CHNCFG4_TRGSRC1_EVENT_USER3_Val _UINT32_(0x8)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 3  */
#define   ADC_CHNCFG4_TRGSRC1_EVENT_USER4_Val _UINT32_(0x9)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 4  */
#define   ADC_CHNCFG4_TRGSRC1_EVENT_USER5_Val _UINT32_(0xA)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 5  */
#define   ADC_CHNCFG4_TRGSRC1_EVENT_USER6_Val _UINT32_(0xB)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 6  */
#define   ADC_CHNCFG4_TRGSRC1_EVENT_USER7_Val _UINT32_(0xC)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 7  */
#define   ADC_CHNCFG4_TRGSRC1_EVENT_USER8_Val _UINT32_(0xD)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 8  */
#define   ADC_CHNCFG4_TRGSRC1_EVENT_USER9_Val _UINT32_(0xE)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 9  */
#define   ADC_CHNCFG4_TRGSRC1_EVENT_USER10_Val _UINT32_(0xF)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 10  */
#define ADC_CHNCFG4_TRGSRC1_NO_TRIGGER        (ADC_CHNCFG4_TRGSRC1_NO_TRIGGER_Val << ADC_CHNCFG4_TRGSRC1_Pos) /* (ADC_CHNCFG4) No Trigger (NOP) Position  */
#define ADC_CHNCFG4_TRGSRC1_GLOBAL_SOFTWARE_TRIGGER (ADC_CHNCFG4_TRGSRC1_GLOBAL_SOFTWARE_TRIGGER_Val << ADC_CHNCFG4_TRGSRC1_Pos) /* (ADC_CHNCFG4) Global Software Trigger Position  */
#define ADC_CHNCFG4_TRGSRC1_GLOBAL_LEVEL_TRIGGER (ADC_CHNCFG4_TRGSRC1_GLOBAL_LEVEL_TRIGGER_Val << ADC_CHNCFG4_TRGSRC1_Pos) /* (ADC_CHNCFG4) Global Level Software Trigger Position  */
#define ADC_CHNCFG4_TRGSRC1_SCAN_TRIGGER      (ADC_CHNCFG4_TRGSRC1_SCAN_TRIGGER_Val << ADC_CHNCFG4_TRGSRC1_Pos) /* (ADC_CHNCFG4) SCANTRG - Scan Trigger Position  */
#define ADC_CHNCFG4_TRGSRC1_SYNC_TRIGGER      (ADC_CHNCFG4_TRGSRC1_SYNC_TRIGGER_Val << ADC_CHNCFG4_TRGSRC1_Pos) /* (ADC_CHNCFG4) STRIG Synchronous Trigger Position  */
#define ADC_CHNCFG4_TRGSRC1_EVENT_USER0       (ADC_CHNCFG4_TRGSRC1_EVENT_USER0_Val << ADC_CHNCFG4_TRGSRC1_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 0 Position  */
#define ADC_CHNCFG4_TRGSRC1_EVENT_USER1       (ADC_CHNCFG4_TRGSRC1_EVENT_USER1_Val << ADC_CHNCFG4_TRGSRC1_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 1 Position  */
#define ADC_CHNCFG4_TRGSRC1_EVENT_USER2       (ADC_CHNCFG4_TRGSRC1_EVENT_USER2_Val << ADC_CHNCFG4_TRGSRC1_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 2 Position  */
#define ADC_CHNCFG4_TRGSRC1_EVENT_USER3       (ADC_CHNCFG4_TRGSRC1_EVENT_USER3_Val << ADC_CHNCFG4_TRGSRC1_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 3 Position  */
#define ADC_CHNCFG4_TRGSRC1_EVENT_USER4       (ADC_CHNCFG4_TRGSRC1_EVENT_USER4_Val << ADC_CHNCFG4_TRGSRC1_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 4 Position  */
#define ADC_CHNCFG4_TRGSRC1_EVENT_USER5       (ADC_CHNCFG4_TRGSRC1_EVENT_USER5_Val << ADC_CHNCFG4_TRGSRC1_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 5 Position  */
#define ADC_CHNCFG4_TRGSRC1_EVENT_USER6       (ADC_CHNCFG4_TRGSRC1_EVENT_USER6_Val << ADC_CHNCFG4_TRGSRC1_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 6 Position  */
#define ADC_CHNCFG4_TRGSRC1_EVENT_USER7       (ADC_CHNCFG4_TRGSRC1_EVENT_USER7_Val << ADC_CHNCFG4_TRGSRC1_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 7 Position  */
#define ADC_CHNCFG4_TRGSRC1_EVENT_USER8       (ADC_CHNCFG4_TRGSRC1_EVENT_USER8_Val << ADC_CHNCFG4_TRGSRC1_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 8 Position  */
#define ADC_CHNCFG4_TRGSRC1_EVENT_USER9       (ADC_CHNCFG4_TRGSRC1_EVENT_USER9_Val << ADC_CHNCFG4_TRGSRC1_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 9 Position  */
#define ADC_CHNCFG4_TRGSRC1_EVENT_USER10      (ADC_CHNCFG4_TRGSRC1_EVENT_USER10_Val << ADC_CHNCFG4_TRGSRC1_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 10 Position  */
#define ADC_CHNCFG4_TRGSRC2_Pos               _UINT32_(8)                                          /* (ADC_CHNCFG4) Channel 2 Trigger Source Position */
#define ADC_CHNCFG4_TRGSRC2_Msk               (_UINT32_(0xF) << ADC_CHNCFG4_TRGSRC2_Pos)           /* (ADC_CHNCFG4) Channel 2 Trigger Source Mask */
#define ADC_CHNCFG4_TRGSRC2(value)            (ADC_CHNCFG4_TRGSRC2_Msk & (_UINT32_(value) << ADC_CHNCFG4_TRGSRC2_Pos)) /* Assigment of value for TRGSRC2 in the ADC_CHNCFG4 register */
#define   ADC_CHNCFG4_TRGSRC2_NO_TRIGGER_Val  _UINT32_(0x0)                                        /* (ADC_CHNCFG4) No Trigger (NOP)  */
#define   ADC_CHNCFG4_TRGSRC2_GLOBAL_SOFTWARE_TRIGGER_Val _UINT32_(0x1)                                        /* (ADC_CHNCFG4) Global Software Trigger  */
#define   ADC_CHNCFG4_TRGSRC2_GLOBAL_LEVEL_TRIGGER_Val _UINT32_(0x2)                                        /* (ADC_CHNCFG4) Global Level Software Trigger  */
#define   ADC_CHNCFG4_TRGSRC2_SCAN_TRIGGER_Val _UINT32_(0x3)                                        /* (ADC_CHNCFG4) SCANTRG - Scan Trigger  */
#define   ADC_CHNCFG4_TRGSRC2_SYNC_TRIGGER_Val _UINT32_(0x4)                                        /* (ADC_CHNCFG4) STRIG Synchronous Trigger  */
#define   ADC_CHNCFG4_TRGSRC2_EVENT_USER0_Val _UINT32_(0x5)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 0  */
#define   ADC_CHNCFG4_TRGSRC2_EVENT_USER1_Val _UINT32_(0x6)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 1  */
#define   ADC_CHNCFG4_TRGSRC2_EVENT_USER2_Val _UINT32_(0x7)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 2  */
#define   ADC_CHNCFG4_TRGSRC2_EVENT_USER3_Val _UINT32_(0x8)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 3  */
#define   ADC_CHNCFG4_TRGSRC2_EVENT_USER4_Val _UINT32_(0x9)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 4  */
#define   ADC_CHNCFG4_TRGSRC2_EVENT_USER5_Val _UINT32_(0xA)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 5  */
#define   ADC_CHNCFG4_TRGSRC2_EVENT_USER6_Val _UINT32_(0xB)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 6  */
#define   ADC_CHNCFG4_TRGSRC2_EVENT_USER7_Val _UINT32_(0xC)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 7  */
#define   ADC_CHNCFG4_TRGSRC2_EVENT_USER8_Val _UINT32_(0xD)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 8  */
#define   ADC_CHNCFG4_TRGSRC2_EVENT_USER9_Val _UINT32_(0xE)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 9  */
#define   ADC_CHNCFG4_TRGSRC2_EVENT_USER10_Val _UINT32_(0xF)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 10  */
#define ADC_CHNCFG4_TRGSRC2_NO_TRIGGER        (ADC_CHNCFG4_TRGSRC2_NO_TRIGGER_Val << ADC_CHNCFG4_TRGSRC2_Pos) /* (ADC_CHNCFG4) No Trigger (NOP) Position  */
#define ADC_CHNCFG4_TRGSRC2_GLOBAL_SOFTWARE_TRIGGER (ADC_CHNCFG4_TRGSRC2_GLOBAL_SOFTWARE_TRIGGER_Val << ADC_CHNCFG4_TRGSRC2_Pos) /* (ADC_CHNCFG4) Global Software Trigger Position  */
#define ADC_CHNCFG4_TRGSRC2_GLOBAL_LEVEL_TRIGGER (ADC_CHNCFG4_TRGSRC2_GLOBAL_LEVEL_TRIGGER_Val << ADC_CHNCFG4_TRGSRC2_Pos) /* (ADC_CHNCFG4) Global Level Software Trigger Position  */
#define ADC_CHNCFG4_TRGSRC2_SCAN_TRIGGER      (ADC_CHNCFG4_TRGSRC2_SCAN_TRIGGER_Val << ADC_CHNCFG4_TRGSRC2_Pos) /* (ADC_CHNCFG4) SCANTRG - Scan Trigger Position  */
#define ADC_CHNCFG4_TRGSRC2_SYNC_TRIGGER      (ADC_CHNCFG4_TRGSRC2_SYNC_TRIGGER_Val << ADC_CHNCFG4_TRGSRC2_Pos) /* (ADC_CHNCFG4) STRIG Synchronous Trigger Position  */
#define ADC_CHNCFG4_TRGSRC2_EVENT_USER0       (ADC_CHNCFG4_TRGSRC2_EVENT_USER0_Val << ADC_CHNCFG4_TRGSRC2_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 0 Position  */
#define ADC_CHNCFG4_TRGSRC2_EVENT_USER1       (ADC_CHNCFG4_TRGSRC2_EVENT_USER1_Val << ADC_CHNCFG4_TRGSRC2_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 1 Position  */
#define ADC_CHNCFG4_TRGSRC2_EVENT_USER2       (ADC_CHNCFG4_TRGSRC2_EVENT_USER2_Val << ADC_CHNCFG4_TRGSRC2_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 2 Position  */
#define ADC_CHNCFG4_TRGSRC2_EVENT_USER3       (ADC_CHNCFG4_TRGSRC2_EVENT_USER3_Val << ADC_CHNCFG4_TRGSRC2_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 3 Position  */
#define ADC_CHNCFG4_TRGSRC2_EVENT_USER4       (ADC_CHNCFG4_TRGSRC2_EVENT_USER4_Val << ADC_CHNCFG4_TRGSRC2_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 4 Position  */
#define ADC_CHNCFG4_TRGSRC2_EVENT_USER5       (ADC_CHNCFG4_TRGSRC2_EVENT_USER5_Val << ADC_CHNCFG4_TRGSRC2_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 5 Position  */
#define ADC_CHNCFG4_TRGSRC2_EVENT_USER6       (ADC_CHNCFG4_TRGSRC2_EVENT_USER6_Val << ADC_CHNCFG4_TRGSRC2_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 6 Position  */
#define ADC_CHNCFG4_TRGSRC2_EVENT_USER7       (ADC_CHNCFG4_TRGSRC2_EVENT_USER7_Val << ADC_CHNCFG4_TRGSRC2_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 7 Position  */
#define ADC_CHNCFG4_TRGSRC2_EVENT_USER8       (ADC_CHNCFG4_TRGSRC2_EVENT_USER8_Val << ADC_CHNCFG4_TRGSRC2_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 8 Position  */
#define ADC_CHNCFG4_TRGSRC2_EVENT_USER9       (ADC_CHNCFG4_TRGSRC2_EVENT_USER9_Val << ADC_CHNCFG4_TRGSRC2_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 9 Position  */
#define ADC_CHNCFG4_TRGSRC2_EVENT_USER10      (ADC_CHNCFG4_TRGSRC2_EVENT_USER10_Val << ADC_CHNCFG4_TRGSRC2_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 10 Position  */
#define ADC_CHNCFG4_TRGSRC3_Pos               _UINT32_(12)                                         /* (ADC_CHNCFG4) Channel 3 Trigger Source Position */
#define ADC_CHNCFG4_TRGSRC3_Msk               (_UINT32_(0xF) << ADC_CHNCFG4_TRGSRC3_Pos)           /* (ADC_CHNCFG4) Channel 3 Trigger Source Mask */
#define ADC_CHNCFG4_TRGSRC3(value)            (ADC_CHNCFG4_TRGSRC3_Msk & (_UINT32_(value) << ADC_CHNCFG4_TRGSRC3_Pos)) /* Assigment of value for TRGSRC3 in the ADC_CHNCFG4 register */
#define   ADC_CHNCFG4_TRGSRC3_NO_TRIGGER_Val  _UINT32_(0x0)                                        /* (ADC_CHNCFG4) No Trigger (NOP)  */
#define   ADC_CHNCFG4_TRGSRC3_GLOBAL_SOFTWARE_TRIGGER_Val _UINT32_(0x1)                                        /* (ADC_CHNCFG4) Global Software Trigger  */
#define   ADC_CHNCFG4_TRGSRC3_GLOBAL_LEVEL_TRIGGER_Val _UINT32_(0x2)                                        /* (ADC_CHNCFG4) Global Level Software Trigger  */
#define   ADC_CHNCFG4_TRGSRC3_SCAN_TRIGGER_Val _UINT32_(0x3)                                        /* (ADC_CHNCFG4) SCANTRG - Scan Trigger  */
#define   ADC_CHNCFG4_TRGSRC3_SYNC_TRIGGER_Val _UINT32_(0x4)                                        /* (ADC_CHNCFG4) STRIG Synchronous Trigger  */
#define   ADC_CHNCFG4_TRGSRC3_EVENT_USER0_Val _UINT32_(0x5)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 0  */
#define   ADC_CHNCFG4_TRGSRC3_EVENT_USER1_Val _UINT32_(0x6)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 1  */
#define   ADC_CHNCFG4_TRGSRC3_EVENT_USER2_Val _UINT32_(0x7)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 2  */
#define   ADC_CHNCFG4_TRGSRC3_EVENT_USER3_Val _UINT32_(0x8)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 3  */
#define   ADC_CHNCFG4_TRGSRC3_EVENT_USER4_Val _UINT32_(0x9)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 4  */
#define   ADC_CHNCFG4_TRGSRC3_EVENT_USER5_Val _UINT32_(0xA)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 5  */
#define   ADC_CHNCFG4_TRGSRC3_EVENT_USER6_Val _UINT32_(0xB)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 6  */
#define   ADC_CHNCFG4_TRGSRC3_EVENT_USER7_Val _UINT32_(0xC)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 7  */
#define   ADC_CHNCFG4_TRGSRC3_EVENT_USER8_Val _UINT32_(0xD)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 8  */
#define   ADC_CHNCFG4_TRGSRC3_EVENT_USER9_Val _UINT32_(0xE)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 9  */
#define   ADC_CHNCFG4_TRGSRC3_EVENT_USER10_Val _UINT32_(0xF)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 10  */
#define ADC_CHNCFG4_TRGSRC3_NO_TRIGGER        (ADC_CHNCFG4_TRGSRC3_NO_TRIGGER_Val << ADC_CHNCFG4_TRGSRC3_Pos) /* (ADC_CHNCFG4) No Trigger (NOP) Position  */
#define ADC_CHNCFG4_TRGSRC3_GLOBAL_SOFTWARE_TRIGGER (ADC_CHNCFG4_TRGSRC3_GLOBAL_SOFTWARE_TRIGGER_Val << ADC_CHNCFG4_TRGSRC3_Pos) /* (ADC_CHNCFG4) Global Software Trigger Position  */
#define ADC_CHNCFG4_TRGSRC3_GLOBAL_LEVEL_TRIGGER (ADC_CHNCFG4_TRGSRC3_GLOBAL_LEVEL_TRIGGER_Val << ADC_CHNCFG4_TRGSRC3_Pos) /* (ADC_CHNCFG4) Global Level Software Trigger Position  */
#define ADC_CHNCFG4_TRGSRC3_SCAN_TRIGGER      (ADC_CHNCFG4_TRGSRC3_SCAN_TRIGGER_Val << ADC_CHNCFG4_TRGSRC3_Pos) /* (ADC_CHNCFG4) SCANTRG - Scan Trigger Position  */
#define ADC_CHNCFG4_TRGSRC3_SYNC_TRIGGER      (ADC_CHNCFG4_TRGSRC3_SYNC_TRIGGER_Val << ADC_CHNCFG4_TRGSRC3_Pos) /* (ADC_CHNCFG4) STRIG Synchronous Trigger Position  */
#define ADC_CHNCFG4_TRGSRC3_EVENT_USER0       (ADC_CHNCFG4_TRGSRC3_EVENT_USER0_Val << ADC_CHNCFG4_TRGSRC3_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 0 Position  */
#define ADC_CHNCFG4_TRGSRC3_EVENT_USER1       (ADC_CHNCFG4_TRGSRC3_EVENT_USER1_Val << ADC_CHNCFG4_TRGSRC3_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 1 Position  */
#define ADC_CHNCFG4_TRGSRC3_EVENT_USER2       (ADC_CHNCFG4_TRGSRC3_EVENT_USER2_Val << ADC_CHNCFG4_TRGSRC3_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 2 Position  */
#define ADC_CHNCFG4_TRGSRC3_EVENT_USER3       (ADC_CHNCFG4_TRGSRC3_EVENT_USER3_Val << ADC_CHNCFG4_TRGSRC3_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 3 Position  */
#define ADC_CHNCFG4_TRGSRC3_EVENT_USER4       (ADC_CHNCFG4_TRGSRC3_EVENT_USER4_Val << ADC_CHNCFG4_TRGSRC3_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 4 Position  */
#define ADC_CHNCFG4_TRGSRC3_EVENT_USER5       (ADC_CHNCFG4_TRGSRC3_EVENT_USER5_Val << ADC_CHNCFG4_TRGSRC3_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 5 Position  */
#define ADC_CHNCFG4_TRGSRC3_EVENT_USER6       (ADC_CHNCFG4_TRGSRC3_EVENT_USER6_Val << ADC_CHNCFG4_TRGSRC3_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 6 Position  */
#define ADC_CHNCFG4_TRGSRC3_EVENT_USER7       (ADC_CHNCFG4_TRGSRC3_EVENT_USER7_Val << ADC_CHNCFG4_TRGSRC3_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 7 Position  */
#define ADC_CHNCFG4_TRGSRC3_EVENT_USER8       (ADC_CHNCFG4_TRGSRC3_EVENT_USER8_Val << ADC_CHNCFG4_TRGSRC3_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 8 Position  */
#define ADC_CHNCFG4_TRGSRC3_EVENT_USER9       (ADC_CHNCFG4_TRGSRC3_EVENT_USER9_Val << ADC_CHNCFG4_TRGSRC3_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 9 Position  */
#define ADC_CHNCFG4_TRGSRC3_EVENT_USER10      (ADC_CHNCFG4_TRGSRC3_EVENT_USER10_Val << ADC_CHNCFG4_TRGSRC3_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 10 Position  */
#define ADC_CHNCFG4_TRGSRC4_Pos               _UINT32_(16)                                         /* (ADC_CHNCFG4) Channel 4 Trigger Source Position */
#define ADC_CHNCFG4_TRGSRC4_Msk               (_UINT32_(0xF) << ADC_CHNCFG4_TRGSRC4_Pos)           /* (ADC_CHNCFG4) Channel 4 Trigger Source Mask */
#define ADC_CHNCFG4_TRGSRC4(value)            (ADC_CHNCFG4_TRGSRC4_Msk & (_UINT32_(value) << ADC_CHNCFG4_TRGSRC4_Pos)) /* Assigment of value for TRGSRC4 in the ADC_CHNCFG4 register */
#define   ADC_CHNCFG4_TRGSRC4_NO_TRIGGER_Val  _UINT32_(0x0)                                        /* (ADC_CHNCFG4) No Trigger (NOP)  */
#define   ADC_CHNCFG4_TRGSRC4_GLOBAL_SOFTWARE_TRIGGER_Val _UINT32_(0x1)                                        /* (ADC_CHNCFG4) Global Software Trigger  */
#define   ADC_CHNCFG4_TRGSRC4_GLOBAL_LEVEL_TRIGGER_Val _UINT32_(0x2)                                        /* (ADC_CHNCFG4) Global Level Software Trigger  */
#define   ADC_CHNCFG4_TRGSRC4_SCAN_TRIGGER_Val _UINT32_(0x3)                                        /* (ADC_CHNCFG4) SCANTRG - Scan Trigger  */
#define   ADC_CHNCFG4_TRGSRC4_SYNC_TRIGGER_Val _UINT32_(0x4)                                        /* (ADC_CHNCFG4) STRIG Synchronous Trigger  */
#define   ADC_CHNCFG4_TRGSRC4_EVENT_USER0_Val _UINT32_(0x5)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 0  */
#define   ADC_CHNCFG4_TRGSRC4_EVENT_USER1_Val _UINT32_(0x6)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 1  */
#define   ADC_CHNCFG4_TRGSRC4_EVENT_USER2_Val _UINT32_(0x7)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 2  */
#define   ADC_CHNCFG4_TRGSRC4_EVENT_USER3_Val _UINT32_(0x8)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 3  */
#define   ADC_CHNCFG4_TRGSRC4_EVENT_USER4_Val _UINT32_(0x9)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 4  */
#define   ADC_CHNCFG4_TRGSRC4_EVENT_USER5_Val _UINT32_(0xA)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 5  */
#define   ADC_CHNCFG4_TRGSRC4_EVENT_USER6_Val _UINT32_(0xB)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 6  */
#define   ADC_CHNCFG4_TRGSRC4_EVENT_USER7_Val _UINT32_(0xC)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 7  */
#define   ADC_CHNCFG4_TRGSRC4_EVENT_USER8_Val _UINT32_(0xD)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 8  */
#define   ADC_CHNCFG4_TRGSRC4_EVENT_USER9_Val _UINT32_(0xE)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 9  */
#define   ADC_CHNCFG4_TRGSRC4_EVENT_USER10_Val _UINT32_(0xF)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 10  */
#define ADC_CHNCFG4_TRGSRC4_NO_TRIGGER        (ADC_CHNCFG4_TRGSRC4_NO_TRIGGER_Val << ADC_CHNCFG4_TRGSRC4_Pos) /* (ADC_CHNCFG4) No Trigger (NOP) Position  */
#define ADC_CHNCFG4_TRGSRC4_GLOBAL_SOFTWARE_TRIGGER (ADC_CHNCFG4_TRGSRC4_GLOBAL_SOFTWARE_TRIGGER_Val << ADC_CHNCFG4_TRGSRC4_Pos) /* (ADC_CHNCFG4) Global Software Trigger Position  */
#define ADC_CHNCFG4_TRGSRC4_GLOBAL_LEVEL_TRIGGER (ADC_CHNCFG4_TRGSRC4_GLOBAL_LEVEL_TRIGGER_Val << ADC_CHNCFG4_TRGSRC4_Pos) /* (ADC_CHNCFG4) Global Level Software Trigger Position  */
#define ADC_CHNCFG4_TRGSRC4_SCAN_TRIGGER      (ADC_CHNCFG4_TRGSRC4_SCAN_TRIGGER_Val << ADC_CHNCFG4_TRGSRC4_Pos) /* (ADC_CHNCFG4) SCANTRG - Scan Trigger Position  */
#define ADC_CHNCFG4_TRGSRC4_SYNC_TRIGGER      (ADC_CHNCFG4_TRGSRC4_SYNC_TRIGGER_Val << ADC_CHNCFG4_TRGSRC4_Pos) /* (ADC_CHNCFG4) STRIG Synchronous Trigger Position  */
#define ADC_CHNCFG4_TRGSRC4_EVENT_USER0       (ADC_CHNCFG4_TRGSRC4_EVENT_USER0_Val << ADC_CHNCFG4_TRGSRC4_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 0 Position  */
#define ADC_CHNCFG4_TRGSRC4_EVENT_USER1       (ADC_CHNCFG4_TRGSRC4_EVENT_USER1_Val << ADC_CHNCFG4_TRGSRC4_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 1 Position  */
#define ADC_CHNCFG4_TRGSRC4_EVENT_USER2       (ADC_CHNCFG4_TRGSRC4_EVENT_USER2_Val << ADC_CHNCFG4_TRGSRC4_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 2 Position  */
#define ADC_CHNCFG4_TRGSRC4_EVENT_USER3       (ADC_CHNCFG4_TRGSRC4_EVENT_USER3_Val << ADC_CHNCFG4_TRGSRC4_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 3 Position  */
#define ADC_CHNCFG4_TRGSRC4_EVENT_USER4       (ADC_CHNCFG4_TRGSRC4_EVENT_USER4_Val << ADC_CHNCFG4_TRGSRC4_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 4 Position  */
#define ADC_CHNCFG4_TRGSRC4_EVENT_USER5       (ADC_CHNCFG4_TRGSRC4_EVENT_USER5_Val << ADC_CHNCFG4_TRGSRC4_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 5 Position  */
#define ADC_CHNCFG4_TRGSRC4_EVENT_USER6       (ADC_CHNCFG4_TRGSRC4_EVENT_USER6_Val << ADC_CHNCFG4_TRGSRC4_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 6 Position  */
#define ADC_CHNCFG4_TRGSRC4_EVENT_USER7       (ADC_CHNCFG4_TRGSRC4_EVENT_USER7_Val << ADC_CHNCFG4_TRGSRC4_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 7 Position  */
#define ADC_CHNCFG4_TRGSRC4_EVENT_USER8       (ADC_CHNCFG4_TRGSRC4_EVENT_USER8_Val << ADC_CHNCFG4_TRGSRC4_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 8 Position  */
#define ADC_CHNCFG4_TRGSRC4_EVENT_USER9       (ADC_CHNCFG4_TRGSRC4_EVENT_USER9_Val << ADC_CHNCFG4_TRGSRC4_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 9 Position  */
#define ADC_CHNCFG4_TRGSRC4_EVENT_USER10      (ADC_CHNCFG4_TRGSRC4_EVENT_USER10_Val << ADC_CHNCFG4_TRGSRC4_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 10 Position  */
#define ADC_CHNCFG4_TRGSRC5_Pos               _UINT32_(20)                                         /* (ADC_CHNCFG4) Channel 5 Trigger Source Position */
#define ADC_CHNCFG4_TRGSRC5_Msk               (_UINT32_(0xF) << ADC_CHNCFG4_TRGSRC5_Pos)           /* (ADC_CHNCFG4) Channel 5 Trigger Source Mask */
#define ADC_CHNCFG4_TRGSRC5(value)            (ADC_CHNCFG4_TRGSRC5_Msk & (_UINT32_(value) << ADC_CHNCFG4_TRGSRC5_Pos)) /* Assigment of value for TRGSRC5 in the ADC_CHNCFG4 register */
#define   ADC_CHNCFG4_TRGSRC5_NO_TRIGGER_Val  _UINT32_(0x0)                                        /* (ADC_CHNCFG4) No Trigger (NOP)  */
#define   ADC_CHNCFG4_TRGSRC5_GLOBAL_SOFTWARE_TRIGGER_Val _UINT32_(0x1)                                        /* (ADC_CHNCFG4) Global Software Trigger  */
#define   ADC_CHNCFG4_TRGSRC5_GLOBAL_LEVEL_TRIGGER_Val _UINT32_(0x2)                                        /* (ADC_CHNCFG4) Global Level Software Trigger  */
#define   ADC_CHNCFG4_TRGSRC5_SCAN_TRIGGER_Val _UINT32_(0x3)                                        /* (ADC_CHNCFG4) SCANTRG - Scan Trigger  */
#define   ADC_CHNCFG4_TRGSRC5_SYNC_TRIGGER_Val _UINT32_(0x4)                                        /* (ADC_CHNCFG4) STRIG Synchronous Trigger  */
#define   ADC_CHNCFG4_TRGSRC5_EVENT_USER0_Val _UINT32_(0x5)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 0  */
#define   ADC_CHNCFG4_TRGSRC5_EVENT_USER1_Val _UINT32_(0x6)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 1  */
#define   ADC_CHNCFG4_TRGSRC5_EVENT_USER2_Val _UINT32_(0x7)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 2  */
#define   ADC_CHNCFG4_TRGSRC5_EVENT_USER3_Val _UINT32_(0x8)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 3  */
#define   ADC_CHNCFG4_TRGSRC5_EVENT_USER4_Val _UINT32_(0x9)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 4  */
#define   ADC_CHNCFG4_TRGSRC5_EVENT_USER5_Val _UINT32_(0xA)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 5  */
#define   ADC_CHNCFG4_TRGSRC5_EVENT_USER6_Val _UINT32_(0xB)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 6  */
#define   ADC_CHNCFG4_TRGSRC5_EVENT_USER7_Val _UINT32_(0xC)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 7  */
#define   ADC_CHNCFG4_TRGSRC5_EVENT_USER8_Val _UINT32_(0xD)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 8  */
#define   ADC_CHNCFG4_TRGSRC5_EVENT_USER9_Val _UINT32_(0xE)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 9  */
#define   ADC_CHNCFG4_TRGSRC5_EVENT_USER10_Val _UINT32_(0xF)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 10  */
#define ADC_CHNCFG4_TRGSRC5_NO_TRIGGER        (ADC_CHNCFG4_TRGSRC5_NO_TRIGGER_Val << ADC_CHNCFG4_TRGSRC5_Pos) /* (ADC_CHNCFG4) No Trigger (NOP) Position  */
#define ADC_CHNCFG4_TRGSRC5_GLOBAL_SOFTWARE_TRIGGER (ADC_CHNCFG4_TRGSRC5_GLOBAL_SOFTWARE_TRIGGER_Val << ADC_CHNCFG4_TRGSRC5_Pos) /* (ADC_CHNCFG4) Global Software Trigger Position  */
#define ADC_CHNCFG4_TRGSRC5_GLOBAL_LEVEL_TRIGGER (ADC_CHNCFG4_TRGSRC5_GLOBAL_LEVEL_TRIGGER_Val << ADC_CHNCFG4_TRGSRC5_Pos) /* (ADC_CHNCFG4) Global Level Software Trigger Position  */
#define ADC_CHNCFG4_TRGSRC5_SCAN_TRIGGER      (ADC_CHNCFG4_TRGSRC5_SCAN_TRIGGER_Val << ADC_CHNCFG4_TRGSRC5_Pos) /* (ADC_CHNCFG4) SCANTRG - Scan Trigger Position  */
#define ADC_CHNCFG4_TRGSRC5_SYNC_TRIGGER      (ADC_CHNCFG4_TRGSRC5_SYNC_TRIGGER_Val << ADC_CHNCFG4_TRGSRC5_Pos) /* (ADC_CHNCFG4) STRIG Synchronous Trigger Position  */
#define ADC_CHNCFG4_TRGSRC5_EVENT_USER0       (ADC_CHNCFG4_TRGSRC5_EVENT_USER0_Val << ADC_CHNCFG4_TRGSRC5_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 0 Position  */
#define ADC_CHNCFG4_TRGSRC5_EVENT_USER1       (ADC_CHNCFG4_TRGSRC5_EVENT_USER1_Val << ADC_CHNCFG4_TRGSRC5_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 1 Position  */
#define ADC_CHNCFG4_TRGSRC5_EVENT_USER2       (ADC_CHNCFG4_TRGSRC5_EVENT_USER2_Val << ADC_CHNCFG4_TRGSRC5_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 2 Position  */
#define ADC_CHNCFG4_TRGSRC5_EVENT_USER3       (ADC_CHNCFG4_TRGSRC5_EVENT_USER3_Val << ADC_CHNCFG4_TRGSRC5_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 3 Position  */
#define ADC_CHNCFG4_TRGSRC5_EVENT_USER4       (ADC_CHNCFG4_TRGSRC5_EVENT_USER4_Val << ADC_CHNCFG4_TRGSRC5_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 4 Position  */
#define ADC_CHNCFG4_TRGSRC5_EVENT_USER5       (ADC_CHNCFG4_TRGSRC5_EVENT_USER5_Val << ADC_CHNCFG4_TRGSRC5_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 5 Position  */
#define ADC_CHNCFG4_TRGSRC5_EVENT_USER6       (ADC_CHNCFG4_TRGSRC5_EVENT_USER6_Val << ADC_CHNCFG4_TRGSRC5_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 6 Position  */
#define ADC_CHNCFG4_TRGSRC5_EVENT_USER7       (ADC_CHNCFG4_TRGSRC5_EVENT_USER7_Val << ADC_CHNCFG4_TRGSRC5_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 7 Position  */
#define ADC_CHNCFG4_TRGSRC5_EVENT_USER8       (ADC_CHNCFG4_TRGSRC5_EVENT_USER8_Val << ADC_CHNCFG4_TRGSRC5_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 8 Position  */
#define ADC_CHNCFG4_TRGSRC5_EVENT_USER9       (ADC_CHNCFG4_TRGSRC5_EVENT_USER9_Val << ADC_CHNCFG4_TRGSRC5_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 9 Position  */
#define ADC_CHNCFG4_TRGSRC5_EVENT_USER10      (ADC_CHNCFG4_TRGSRC5_EVENT_USER10_Val << ADC_CHNCFG4_TRGSRC5_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 10 Position  */
#define ADC_CHNCFG4_TRGSRC6_Pos               _UINT32_(24)                                         /* (ADC_CHNCFG4) Channel 6 Trigger Source Position */
#define ADC_CHNCFG4_TRGSRC6_Msk               (_UINT32_(0xF) << ADC_CHNCFG4_TRGSRC6_Pos)           /* (ADC_CHNCFG4) Channel 6 Trigger Source Mask */
#define ADC_CHNCFG4_TRGSRC6(value)            (ADC_CHNCFG4_TRGSRC6_Msk & (_UINT32_(value) << ADC_CHNCFG4_TRGSRC6_Pos)) /* Assigment of value for TRGSRC6 in the ADC_CHNCFG4 register */
#define   ADC_CHNCFG4_TRGSRC6_NO_TRIGGER_Val  _UINT32_(0x0)                                        /* (ADC_CHNCFG4) No Trigger (NOP)  */
#define   ADC_CHNCFG4_TRGSRC6_GLOBAL_SOFTWARE_TRIGGER_Val _UINT32_(0x1)                                        /* (ADC_CHNCFG4) Global Software Trigger  */
#define   ADC_CHNCFG4_TRGSRC6_GLOBAL_LEVEL_TRIGGER_Val _UINT32_(0x2)                                        /* (ADC_CHNCFG4) Global Level Software Trigger  */
#define   ADC_CHNCFG4_TRGSRC6_SCAN_TRIGGER_Val _UINT32_(0x3)                                        /* (ADC_CHNCFG4) SCANTRG - Scan Trigger  */
#define   ADC_CHNCFG4_TRGSRC6_SYNC_TRIGGER_Val _UINT32_(0x4)                                        /* (ADC_CHNCFG4) STRIG Synchronous Trigger  */
#define   ADC_CHNCFG4_TRGSRC6_EVENT_USER0_Val _UINT32_(0x5)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 0  */
#define   ADC_CHNCFG4_TRGSRC6_EVENT_USER1_Val _UINT32_(0x6)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 1  */
#define   ADC_CHNCFG4_TRGSRC6_EVENT_USER2_Val _UINT32_(0x7)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 2  */
#define   ADC_CHNCFG4_TRGSRC6_EVENT_USER3_Val _UINT32_(0x8)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 3  */
#define   ADC_CHNCFG4_TRGSRC6_EVENT_USER4_Val _UINT32_(0x9)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 4  */
#define   ADC_CHNCFG4_TRGSRC6_EVENT_USER5_Val _UINT32_(0xA)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 5  */
#define   ADC_CHNCFG4_TRGSRC6_EVENT_USER6_Val _UINT32_(0xB)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 6  */
#define   ADC_CHNCFG4_TRGSRC6_EVENT_USER7_Val _UINT32_(0xC)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 7  */
#define   ADC_CHNCFG4_TRGSRC6_EVENT_USER8_Val _UINT32_(0xD)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 8  */
#define   ADC_CHNCFG4_TRGSRC6_EVENT_USER9_Val _UINT32_(0xE)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 9  */
#define   ADC_CHNCFG4_TRGSRC6_EVENT_USER10_Val _UINT32_(0xF)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 10  */
#define ADC_CHNCFG4_TRGSRC6_NO_TRIGGER        (ADC_CHNCFG4_TRGSRC6_NO_TRIGGER_Val << ADC_CHNCFG4_TRGSRC6_Pos) /* (ADC_CHNCFG4) No Trigger (NOP) Position  */
#define ADC_CHNCFG4_TRGSRC6_GLOBAL_SOFTWARE_TRIGGER (ADC_CHNCFG4_TRGSRC6_GLOBAL_SOFTWARE_TRIGGER_Val << ADC_CHNCFG4_TRGSRC6_Pos) /* (ADC_CHNCFG4) Global Software Trigger Position  */
#define ADC_CHNCFG4_TRGSRC6_GLOBAL_LEVEL_TRIGGER (ADC_CHNCFG4_TRGSRC6_GLOBAL_LEVEL_TRIGGER_Val << ADC_CHNCFG4_TRGSRC6_Pos) /* (ADC_CHNCFG4) Global Level Software Trigger Position  */
#define ADC_CHNCFG4_TRGSRC6_SCAN_TRIGGER      (ADC_CHNCFG4_TRGSRC6_SCAN_TRIGGER_Val << ADC_CHNCFG4_TRGSRC6_Pos) /* (ADC_CHNCFG4) SCANTRG - Scan Trigger Position  */
#define ADC_CHNCFG4_TRGSRC6_SYNC_TRIGGER      (ADC_CHNCFG4_TRGSRC6_SYNC_TRIGGER_Val << ADC_CHNCFG4_TRGSRC6_Pos) /* (ADC_CHNCFG4) STRIG Synchronous Trigger Position  */
#define ADC_CHNCFG4_TRGSRC6_EVENT_USER0       (ADC_CHNCFG4_TRGSRC6_EVENT_USER0_Val << ADC_CHNCFG4_TRGSRC6_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 0 Position  */
#define ADC_CHNCFG4_TRGSRC6_EVENT_USER1       (ADC_CHNCFG4_TRGSRC6_EVENT_USER1_Val << ADC_CHNCFG4_TRGSRC6_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 1 Position  */
#define ADC_CHNCFG4_TRGSRC6_EVENT_USER2       (ADC_CHNCFG4_TRGSRC6_EVENT_USER2_Val << ADC_CHNCFG4_TRGSRC6_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 2 Position  */
#define ADC_CHNCFG4_TRGSRC6_EVENT_USER3       (ADC_CHNCFG4_TRGSRC6_EVENT_USER3_Val << ADC_CHNCFG4_TRGSRC6_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 3 Position  */
#define ADC_CHNCFG4_TRGSRC6_EVENT_USER4       (ADC_CHNCFG4_TRGSRC6_EVENT_USER4_Val << ADC_CHNCFG4_TRGSRC6_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 4 Position  */
#define ADC_CHNCFG4_TRGSRC6_EVENT_USER5       (ADC_CHNCFG4_TRGSRC6_EVENT_USER5_Val << ADC_CHNCFG4_TRGSRC6_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 5 Position  */
#define ADC_CHNCFG4_TRGSRC6_EVENT_USER6       (ADC_CHNCFG4_TRGSRC6_EVENT_USER6_Val << ADC_CHNCFG4_TRGSRC6_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 6 Position  */
#define ADC_CHNCFG4_TRGSRC6_EVENT_USER7       (ADC_CHNCFG4_TRGSRC6_EVENT_USER7_Val << ADC_CHNCFG4_TRGSRC6_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 7 Position  */
#define ADC_CHNCFG4_TRGSRC6_EVENT_USER8       (ADC_CHNCFG4_TRGSRC6_EVENT_USER8_Val << ADC_CHNCFG4_TRGSRC6_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 8 Position  */
#define ADC_CHNCFG4_TRGSRC6_EVENT_USER9       (ADC_CHNCFG4_TRGSRC6_EVENT_USER9_Val << ADC_CHNCFG4_TRGSRC6_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 9 Position  */
#define ADC_CHNCFG4_TRGSRC6_EVENT_USER10      (ADC_CHNCFG4_TRGSRC6_EVENT_USER10_Val << ADC_CHNCFG4_TRGSRC6_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 10 Position  */
#define ADC_CHNCFG4_TRGSRC7_Pos               _UINT32_(28)                                         /* (ADC_CHNCFG4) Channel 7 Trigger Source Position */
#define ADC_CHNCFG4_TRGSRC7_Msk               (_UINT32_(0xF) << ADC_CHNCFG4_TRGSRC7_Pos)           /* (ADC_CHNCFG4) Channel 7 Trigger Source Mask */
#define ADC_CHNCFG4_TRGSRC7(value)            (ADC_CHNCFG4_TRGSRC7_Msk & (_UINT32_(value) << ADC_CHNCFG4_TRGSRC7_Pos)) /* Assigment of value for TRGSRC7 in the ADC_CHNCFG4 register */
#define   ADC_CHNCFG4_TRGSRC7_NO_TRIGGER_Val  _UINT32_(0x0)                                        /* (ADC_CHNCFG4) No Trigger (NOP)  */
#define   ADC_CHNCFG4_TRGSRC7_GLOBAL_SOFTWARE_TRIGGER_Val _UINT32_(0x1)                                        /* (ADC_CHNCFG4) Global Software Trigger  */
#define   ADC_CHNCFG4_TRGSRC7_GLOBAL_LEVEL_TRIGGER_Val _UINT32_(0x2)                                        /* (ADC_CHNCFG4) Global Level Software Trigger  */
#define   ADC_CHNCFG4_TRGSRC7_SCAN_TRIGGER_Val _UINT32_(0x3)                                        /* (ADC_CHNCFG4) SCANTRG - Scan Trigger  */
#define   ADC_CHNCFG4_TRGSRC7_SYNC_TRIGGER_Val _UINT32_(0x4)                                        /* (ADC_CHNCFG4) STRIG Synchronous Trigger  */
#define   ADC_CHNCFG4_TRGSRC7_EVENT_USER0_Val _UINT32_(0x5)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 0  */
#define   ADC_CHNCFG4_TRGSRC7_EVENT_USER1_Val _UINT32_(0x6)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 1  */
#define   ADC_CHNCFG4_TRGSRC7_EVENT_USER2_Val _UINT32_(0x7)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 2  */
#define   ADC_CHNCFG4_TRGSRC7_EVENT_USER3_Val _UINT32_(0x8)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 3  */
#define   ADC_CHNCFG4_TRGSRC7_EVENT_USER4_Val _UINT32_(0x9)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 4  */
#define   ADC_CHNCFG4_TRGSRC7_EVENT_USER5_Val _UINT32_(0xA)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 5  */
#define   ADC_CHNCFG4_TRGSRC7_EVENT_USER6_Val _UINT32_(0xB)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 6  */
#define   ADC_CHNCFG4_TRGSRC7_EVENT_USER7_Val _UINT32_(0xC)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 7  */
#define   ADC_CHNCFG4_TRGSRC7_EVENT_USER8_Val _UINT32_(0xD)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 8  */
#define   ADC_CHNCFG4_TRGSRC7_EVENT_USER9_Val _UINT32_(0xE)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 9  */
#define   ADC_CHNCFG4_TRGSRC7_EVENT_USER10_Val _UINT32_(0xF)                                        /* (ADC_CHNCFG4) ADC Trigger Event User 10  */
#define ADC_CHNCFG4_TRGSRC7_NO_TRIGGER        (ADC_CHNCFG4_TRGSRC7_NO_TRIGGER_Val << ADC_CHNCFG4_TRGSRC7_Pos) /* (ADC_CHNCFG4) No Trigger (NOP) Position  */
#define ADC_CHNCFG4_TRGSRC7_GLOBAL_SOFTWARE_TRIGGER (ADC_CHNCFG4_TRGSRC7_GLOBAL_SOFTWARE_TRIGGER_Val << ADC_CHNCFG4_TRGSRC7_Pos) /* (ADC_CHNCFG4) Global Software Trigger Position  */
#define ADC_CHNCFG4_TRGSRC7_GLOBAL_LEVEL_TRIGGER (ADC_CHNCFG4_TRGSRC7_GLOBAL_LEVEL_TRIGGER_Val << ADC_CHNCFG4_TRGSRC7_Pos) /* (ADC_CHNCFG4) Global Level Software Trigger Position  */
#define ADC_CHNCFG4_TRGSRC7_SCAN_TRIGGER      (ADC_CHNCFG4_TRGSRC7_SCAN_TRIGGER_Val << ADC_CHNCFG4_TRGSRC7_Pos) /* (ADC_CHNCFG4) SCANTRG - Scan Trigger Position  */
#define ADC_CHNCFG4_TRGSRC7_SYNC_TRIGGER      (ADC_CHNCFG4_TRGSRC7_SYNC_TRIGGER_Val << ADC_CHNCFG4_TRGSRC7_Pos) /* (ADC_CHNCFG4) STRIG Synchronous Trigger Position  */
#define ADC_CHNCFG4_TRGSRC7_EVENT_USER0       (ADC_CHNCFG4_TRGSRC7_EVENT_USER0_Val << ADC_CHNCFG4_TRGSRC7_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 0 Position  */
#define ADC_CHNCFG4_TRGSRC7_EVENT_USER1       (ADC_CHNCFG4_TRGSRC7_EVENT_USER1_Val << ADC_CHNCFG4_TRGSRC7_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 1 Position  */
#define ADC_CHNCFG4_TRGSRC7_EVENT_USER2       (ADC_CHNCFG4_TRGSRC7_EVENT_USER2_Val << ADC_CHNCFG4_TRGSRC7_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 2 Position  */
#define ADC_CHNCFG4_TRGSRC7_EVENT_USER3       (ADC_CHNCFG4_TRGSRC7_EVENT_USER3_Val << ADC_CHNCFG4_TRGSRC7_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 3 Position  */
#define ADC_CHNCFG4_TRGSRC7_EVENT_USER4       (ADC_CHNCFG4_TRGSRC7_EVENT_USER4_Val << ADC_CHNCFG4_TRGSRC7_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 4 Position  */
#define ADC_CHNCFG4_TRGSRC7_EVENT_USER5       (ADC_CHNCFG4_TRGSRC7_EVENT_USER5_Val << ADC_CHNCFG4_TRGSRC7_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 5 Position  */
#define ADC_CHNCFG4_TRGSRC7_EVENT_USER6       (ADC_CHNCFG4_TRGSRC7_EVENT_USER6_Val << ADC_CHNCFG4_TRGSRC7_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 6 Position  */
#define ADC_CHNCFG4_TRGSRC7_EVENT_USER7       (ADC_CHNCFG4_TRGSRC7_EVENT_USER7_Val << ADC_CHNCFG4_TRGSRC7_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 7 Position  */
#define ADC_CHNCFG4_TRGSRC7_EVENT_USER8       (ADC_CHNCFG4_TRGSRC7_EVENT_USER8_Val << ADC_CHNCFG4_TRGSRC7_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 8 Position  */
#define ADC_CHNCFG4_TRGSRC7_EVENT_USER9       (ADC_CHNCFG4_TRGSRC7_EVENT_USER9_Val << ADC_CHNCFG4_TRGSRC7_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 9 Position  */
#define ADC_CHNCFG4_TRGSRC7_EVENT_USER10      (ADC_CHNCFG4_TRGSRC7_EVENT_USER10_Val << ADC_CHNCFG4_TRGSRC7_Pos) /* (ADC_CHNCFG4) ADC Trigger Event User 10 Position  */
#define ADC_CHNCFG4_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (ADC_CHNCFG4) Register Mask  */


/* -------- ADC_CHNCFG5 : (ADC Offset: 0x14) (R/W 32) Channel Configuration 5 (TRGSRC) -------- */
#define ADC_CHNCFG5_RESETVALUE                _UINT32_(0x00)                                       /*  (ADC_CHNCFG5) Channel Configuration 5 (TRGSRC)  Reset Value */

#define ADC_CHNCFG5_TRGSRC8_Pos               _UINT32_(0)                                          /* (ADC_CHNCFG5) Channel 8 Trigger Source Position */
#define ADC_CHNCFG5_TRGSRC8_Msk               (_UINT32_(0xF) << ADC_CHNCFG5_TRGSRC8_Pos)           /* (ADC_CHNCFG5) Channel 8 Trigger Source Mask */
#define ADC_CHNCFG5_TRGSRC8(value)            (ADC_CHNCFG5_TRGSRC8_Msk & (_UINT32_(value) << ADC_CHNCFG5_TRGSRC8_Pos)) /* Assigment of value for TRGSRC8 in the ADC_CHNCFG5 register */
#define   ADC_CHNCFG5_TRGSRC8_NO_TRIGGER_Val  _UINT32_(0x0)                                        /* (ADC_CHNCFG5) No Trigger (NOP)  */
#define   ADC_CHNCFG5_TRGSRC8_GLOBAL_SOFTWARE_TRIGGER_Val _UINT32_(0x1)                                        /* (ADC_CHNCFG5) Global Software Trigger  */
#define   ADC_CHNCFG5_TRGSRC8_GLOBAL_LEVEL_TRIGGER_Val _UINT32_(0x2)                                        /* (ADC_CHNCFG5) Global Level Software Trigger  */
#define   ADC_CHNCFG5_TRGSRC8_SCAN_TRIGGER_Val _UINT32_(0x3)                                        /* (ADC_CHNCFG5) SCANTRG - Scan Trigger  */
#define   ADC_CHNCFG5_TRGSRC8_SYNC_TRIGGER_Val _UINT32_(0x4)                                        /* (ADC_CHNCFG5) STRIG Synchronous Trigger  */
#define   ADC_CHNCFG5_TRGSRC8_EVENT_USER0_Val _UINT32_(0x5)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 0  */
#define   ADC_CHNCFG5_TRGSRC8_EVENT_USER1_Val _UINT32_(0x6)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 1  */
#define   ADC_CHNCFG5_TRGSRC8_EVENT_USER2_Val _UINT32_(0x7)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 2  */
#define   ADC_CHNCFG5_TRGSRC8_EVENT_USER3_Val _UINT32_(0x8)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 3  */
#define   ADC_CHNCFG5_TRGSRC8_EVENT_USER4_Val _UINT32_(0x9)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 4  */
#define   ADC_CHNCFG5_TRGSRC8_EVENT_USER5_Val _UINT32_(0xA)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 5  */
#define   ADC_CHNCFG5_TRGSRC8_EVENT_USER6_Val _UINT32_(0xB)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 6  */
#define   ADC_CHNCFG5_TRGSRC8_EVENT_USER7_Val _UINT32_(0xC)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 7  */
#define   ADC_CHNCFG5_TRGSRC8_EVENT_USER8_Val _UINT32_(0xD)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 8  */
#define   ADC_CHNCFG5_TRGSRC8_EVENT_USER9_Val _UINT32_(0xE)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 9  */
#define   ADC_CHNCFG5_TRGSRC8_EVENT_USER10_Val _UINT32_(0xF)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 10  */
#define ADC_CHNCFG5_TRGSRC8_NO_TRIGGER        (ADC_CHNCFG5_TRGSRC8_NO_TRIGGER_Val << ADC_CHNCFG5_TRGSRC8_Pos) /* (ADC_CHNCFG5) No Trigger (NOP) Position  */
#define ADC_CHNCFG5_TRGSRC8_GLOBAL_SOFTWARE_TRIGGER (ADC_CHNCFG5_TRGSRC8_GLOBAL_SOFTWARE_TRIGGER_Val << ADC_CHNCFG5_TRGSRC8_Pos) /* (ADC_CHNCFG5) Global Software Trigger Position  */
#define ADC_CHNCFG5_TRGSRC8_GLOBAL_LEVEL_TRIGGER (ADC_CHNCFG5_TRGSRC8_GLOBAL_LEVEL_TRIGGER_Val << ADC_CHNCFG5_TRGSRC8_Pos) /* (ADC_CHNCFG5) Global Level Software Trigger Position  */
#define ADC_CHNCFG5_TRGSRC8_SCAN_TRIGGER      (ADC_CHNCFG5_TRGSRC8_SCAN_TRIGGER_Val << ADC_CHNCFG5_TRGSRC8_Pos) /* (ADC_CHNCFG5) SCANTRG - Scan Trigger Position  */
#define ADC_CHNCFG5_TRGSRC8_SYNC_TRIGGER      (ADC_CHNCFG5_TRGSRC8_SYNC_TRIGGER_Val << ADC_CHNCFG5_TRGSRC8_Pos) /* (ADC_CHNCFG5) STRIG Synchronous Trigger Position  */
#define ADC_CHNCFG5_TRGSRC8_EVENT_USER0       (ADC_CHNCFG5_TRGSRC8_EVENT_USER0_Val << ADC_CHNCFG5_TRGSRC8_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 0 Position  */
#define ADC_CHNCFG5_TRGSRC8_EVENT_USER1       (ADC_CHNCFG5_TRGSRC8_EVENT_USER1_Val << ADC_CHNCFG5_TRGSRC8_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 1 Position  */
#define ADC_CHNCFG5_TRGSRC8_EVENT_USER2       (ADC_CHNCFG5_TRGSRC8_EVENT_USER2_Val << ADC_CHNCFG5_TRGSRC8_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 2 Position  */
#define ADC_CHNCFG5_TRGSRC8_EVENT_USER3       (ADC_CHNCFG5_TRGSRC8_EVENT_USER3_Val << ADC_CHNCFG5_TRGSRC8_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 3 Position  */
#define ADC_CHNCFG5_TRGSRC8_EVENT_USER4       (ADC_CHNCFG5_TRGSRC8_EVENT_USER4_Val << ADC_CHNCFG5_TRGSRC8_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 4 Position  */
#define ADC_CHNCFG5_TRGSRC8_EVENT_USER5       (ADC_CHNCFG5_TRGSRC8_EVENT_USER5_Val << ADC_CHNCFG5_TRGSRC8_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 5 Position  */
#define ADC_CHNCFG5_TRGSRC8_EVENT_USER6       (ADC_CHNCFG5_TRGSRC8_EVENT_USER6_Val << ADC_CHNCFG5_TRGSRC8_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 6 Position  */
#define ADC_CHNCFG5_TRGSRC8_EVENT_USER7       (ADC_CHNCFG5_TRGSRC8_EVENT_USER7_Val << ADC_CHNCFG5_TRGSRC8_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 7 Position  */
#define ADC_CHNCFG5_TRGSRC8_EVENT_USER8       (ADC_CHNCFG5_TRGSRC8_EVENT_USER8_Val << ADC_CHNCFG5_TRGSRC8_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 8 Position  */
#define ADC_CHNCFG5_TRGSRC8_EVENT_USER9       (ADC_CHNCFG5_TRGSRC8_EVENT_USER9_Val << ADC_CHNCFG5_TRGSRC8_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 9 Position  */
#define ADC_CHNCFG5_TRGSRC8_EVENT_USER10      (ADC_CHNCFG5_TRGSRC8_EVENT_USER10_Val << ADC_CHNCFG5_TRGSRC8_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 10 Position  */
#define ADC_CHNCFG5_TRGSRC9_Pos               _UINT32_(4)                                          /* (ADC_CHNCFG5) Channel 9 Trigger Source Position */
#define ADC_CHNCFG5_TRGSRC9_Msk               (_UINT32_(0xF) << ADC_CHNCFG5_TRGSRC9_Pos)           /* (ADC_CHNCFG5) Channel 9 Trigger Source Mask */
#define ADC_CHNCFG5_TRGSRC9(value)            (ADC_CHNCFG5_TRGSRC9_Msk & (_UINT32_(value) << ADC_CHNCFG5_TRGSRC9_Pos)) /* Assigment of value for TRGSRC9 in the ADC_CHNCFG5 register */
#define   ADC_CHNCFG5_TRGSRC9_NO_TRIGGER_Val  _UINT32_(0x0)                                        /* (ADC_CHNCFG5) No Trigger (NOP)  */
#define   ADC_CHNCFG5_TRGSRC9_GLOBAL_SOFTWARE_TRIGGER_Val _UINT32_(0x1)                                        /* (ADC_CHNCFG5) Global Software Trigger  */
#define   ADC_CHNCFG5_TRGSRC9_GLOBAL_LEVEL_TRIGGER_Val _UINT32_(0x2)                                        /* (ADC_CHNCFG5) Global Level Software Trigger  */
#define   ADC_CHNCFG5_TRGSRC9_SCAN_TRIGGER_Val _UINT32_(0x3)                                        /* (ADC_CHNCFG5) SCANTRG - Scan Trigger  */
#define   ADC_CHNCFG5_TRGSRC9_SYNC_TRIGGER_Val _UINT32_(0x4)                                        /* (ADC_CHNCFG5) STRIG Synchronous Trigger  */
#define   ADC_CHNCFG5_TRGSRC9_EVENT_USER0_Val _UINT32_(0x5)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 0  */
#define   ADC_CHNCFG5_TRGSRC9_EVENT_USER1_Val _UINT32_(0x6)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 1  */
#define   ADC_CHNCFG5_TRGSRC9_EVENT_USER2_Val _UINT32_(0x7)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 2  */
#define   ADC_CHNCFG5_TRGSRC9_EVENT_USER3_Val _UINT32_(0x8)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 3  */
#define   ADC_CHNCFG5_TRGSRC9_EVENT_USER4_Val _UINT32_(0x9)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 4  */
#define   ADC_CHNCFG5_TRGSRC9_EVENT_USER5_Val _UINT32_(0xA)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 5  */
#define   ADC_CHNCFG5_TRGSRC9_EVENT_USER6_Val _UINT32_(0xB)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 6  */
#define   ADC_CHNCFG5_TRGSRC9_EVENT_USER7_Val _UINT32_(0xC)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 7  */
#define   ADC_CHNCFG5_TRGSRC9_EVENT_USER8_Val _UINT32_(0xD)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 8  */
#define   ADC_CHNCFG5_TRGSRC9_EVENT_USER9_Val _UINT32_(0xE)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 9  */
#define   ADC_CHNCFG5_TRGSRC9_EVENT_USER10_Val _UINT32_(0xF)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 10  */
#define ADC_CHNCFG5_TRGSRC9_NO_TRIGGER        (ADC_CHNCFG5_TRGSRC9_NO_TRIGGER_Val << ADC_CHNCFG5_TRGSRC9_Pos) /* (ADC_CHNCFG5) No Trigger (NOP) Position  */
#define ADC_CHNCFG5_TRGSRC9_GLOBAL_SOFTWARE_TRIGGER (ADC_CHNCFG5_TRGSRC9_GLOBAL_SOFTWARE_TRIGGER_Val << ADC_CHNCFG5_TRGSRC9_Pos) /* (ADC_CHNCFG5) Global Software Trigger Position  */
#define ADC_CHNCFG5_TRGSRC9_GLOBAL_LEVEL_TRIGGER (ADC_CHNCFG5_TRGSRC9_GLOBAL_LEVEL_TRIGGER_Val << ADC_CHNCFG5_TRGSRC9_Pos) /* (ADC_CHNCFG5) Global Level Software Trigger Position  */
#define ADC_CHNCFG5_TRGSRC9_SCAN_TRIGGER      (ADC_CHNCFG5_TRGSRC9_SCAN_TRIGGER_Val << ADC_CHNCFG5_TRGSRC9_Pos) /* (ADC_CHNCFG5) SCANTRG - Scan Trigger Position  */
#define ADC_CHNCFG5_TRGSRC9_SYNC_TRIGGER      (ADC_CHNCFG5_TRGSRC9_SYNC_TRIGGER_Val << ADC_CHNCFG5_TRGSRC9_Pos) /* (ADC_CHNCFG5) STRIG Synchronous Trigger Position  */
#define ADC_CHNCFG5_TRGSRC9_EVENT_USER0       (ADC_CHNCFG5_TRGSRC9_EVENT_USER0_Val << ADC_CHNCFG5_TRGSRC9_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 0 Position  */
#define ADC_CHNCFG5_TRGSRC9_EVENT_USER1       (ADC_CHNCFG5_TRGSRC9_EVENT_USER1_Val << ADC_CHNCFG5_TRGSRC9_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 1 Position  */
#define ADC_CHNCFG5_TRGSRC9_EVENT_USER2       (ADC_CHNCFG5_TRGSRC9_EVENT_USER2_Val << ADC_CHNCFG5_TRGSRC9_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 2 Position  */
#define ADC_CHNCFG5_TRGSRC9_EVENT_USER3       (ADC_CHNCFG5_TRGSRC9_EVENT_USER3_Val << ADC_CHNCFG5_TRGSRC9_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 3 Position  */
#define ADC_CHNCFG5_TRGSRC9_EVENT_USER4       (ADC_CHNCFG5_TRGSRC9_EVENT_USER4_Val << ADC_CHNCFG5_TRGSRC9_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 4 Position  */
#define ADC_CHNCFG5_TRGSRC9_EVENT_USER5       (ADC_CHNCFG5_TRGSRC9_EVENT_USER5_Val << ADC_CHNCFG5_TRGSRC9_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 5 Position  */
#define ADC_CHNCFG5_TRGSRC9_EVENT_USER6       (ADC_CHNCFG5_TRGSRC9_EVENT_USER6_Val << ADC_CHNCFG5_TRGSRC9_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 6 Position  */
#define ADC_CHNCFG5_TRGSRC9_EVENT_USER7       (ADC_CHNCFG5_TRGSRC9_EVENT_USER7_Val << ADC_CHNCFG5_TRGSRC9_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 7 Position  */
#define ADC_CHNCFG5_TRGSRC9_EVENT_USER8       (ADC_CHNCFG5_TRGSRC9_EVENT_USER8_Val << ADC_CHNCFG5_TRGSRC9_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 8 Position  */
#define ADC_CHNCFG5_TRGSRC9_EVENT_USER9       (ADC_CHNCFG5_TRGSRC9_EVENT_USER9_Val << ADC_CHNCFG5_TRGSRC9_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 9 Position  */
#define ADC_CHNCFG5_TRGSRC9_EVENT_USER10      (ADC_CHNCFG5_TRGSRC9_EVENT_USER10_Val << ADC_CHNCFG5_TRGSRC9_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 10 Position  */
#define ADC_CHNCFG5_TRGSRC10_Pos              _UINT32_(8)                                          /* (ADC_CHNCFG5) Channel 10 Trigger Source Position */
#define ADC_CHNCFG5_TRGSRC10_Msk              (_UINT32_(0xF) << ADC_CHNCFG5_TRGSRC10_Pos)          /* (ADC_CHNCFG5) Channel 10 Trigger Source Mask */
#define ADC_CHNCFG5_TRGSRC10(value)           (ADC_CHNCFG5_TRGSRC10_Msk & (_UINT32_(value) << ADC_CHNCFG5_TRGSRC10_Pos)) /* Assigment of value for TRGSRC10 in the ADC_CHNCFG5 register */
#define   ADC_CHNCFG5_TRGSRC10_NO_TRIGGER_Val _UINT32_(0x0)                                        /* (ADC_CHNCFG5) No Trigger (NOP)  */
#define   ADC_CHNCFG5_TRGSRC10_GLOBAL_SOFTWARE_TRIGGER_Val _UINT32_(0x1)                                        /* (ADC_CHNCFG5) Global Software Trigger  */
#define   ADC_CHNCFG5_TRGSRC10_GLOBAL_LEVEL_TRIGGER_Val _UINT32_(0x2)                                        /* (ADC_CHNCFG5) Global Level Software Trigger  */
#define   ADC_CHNCFG5_TRGSRC10_SCAN_TRIGGER_Val _UINT32_(0x3)                                        /* (ADC_CHNCFG5) SCANTRG - Scan Trigger  */
#define   ADC_CHNCFG5_TRGSRC10_SYNC_TRIGGER_Val _UINT32_(0x4)                                        /* (ADC_CHNCFG5) STRIG Synchronous Trigger  */
#define   ADC_CHNCFG5_TRGSRC10_EVENT_USER0_Val _UINT32_(0x5)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 0  */
#define   ADC_CHNCFG5_TRGSRC10_EVENT_USER1_Val _UINT32_(0x6)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 1  */
#define   ADC_CHNCFG5_TRGSRC10_EVENT_USER2_Val _UINT32_(0x7)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 2  */
#define   ADC_CHNCFG5_TRGSRC10_EVENT_USER3_Val _UINT32_(0x8)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 3  */
#define   ADC_CHNCFG5_TRGSRC10_EVENT_USER4_Val _UINT32_(0x9)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 4  */
#define   ADC_CHNCFG5_TRGSRC10_EVENT_USER5_Val _UINT32_(0xA)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 5  */
#define   ADC_CHNCFG5_TRGSRC10_EVENT_USER6_Val _UINT32_(0xB)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 6  */
#define   ADC_CHNCFG5_TRGSRC10_EVENT_USER7_Val _UINT32_(0xC)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 7  */
#define   ADC_CHNCFG5_TRGSRC10_EVENT_USER8_Val _UINT32_(0xD)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 8  */
#define   ADC_CHNCFG5_TRGSRC10_EVENT_USER9_Val _UINT32_(0xE)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 9  */
#define   ADC_CHNCFG5_TRGSRC10_EVENT_USER10_Val _UINT32_(0xF)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 10  */
#define ADC_CHNCFG5_TRGSRC10_NO_TRIGGER       (ADC_CHNCFG5_TRGSRC10_NO_TRIGGER_Val << ADC_CHNCFG5_TRGSRC10_Pos) /* (ADC_CHNCFG5) No Trigger (NOP) Position  */
#define ADC_CHNCFG5_TRGSRC10_GLOBAL_SOFTWARE_TRIGGER (ADC_CHNCFG5_TRGSRC10_GLOBAL_SOFTWARE_TRIGGER_Val << ADC_CHNCFG5_TRGSRC10_Pos) /* (ADC_CHNCFG5) Global Software Trigger Position  */
#define ADC_CHNCFG5_TRGSRC10_GLOBAL_LEVEL_TRIGGER (ADC_CHNCFG5_TRGSRC10_GLOBAL_LEVEL_TRIGGER_Val << ADC_CHNCFG5_TRGSRC10_Pos) /* (ADC_CHNCFG5) Global Level Software Trigger Position  */
#define ADC_CHNCFG5_TRGSRC10_SCAN_TRIGGER     (ADC_CHNCFG5_TRGSRC10_SCAN_TRIGGER_Val << ADC_CHNCFG5_TRGSRC10_Pos) /* (ADC_CHNCFG5) SCANTRG - Scan Trigger Position  */
#define ADC_CHNCFG5_TRGSRC10_SYNC_TRIGGER     (ADC_CHNCFG5_TRGSRC10_SYNC_TRIGGER_Val << ADC_CHNCFG5_TRGSRC10_Pos) /* (ADC_CHNCFG5) STRIG Synchronous Trigger Position  */
#define ADC_CHNCFG5_TRGSRC10_EVENT_USER0      (ADC_CHNCFG5_TRGSRC10_EVENT_USER0_Val << ADC_CHNCFG5_TRGSRC10_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 0 Position  */
#define ADC_CHNCFG5_TRGSRC10_EVENT_USER1      (ADC_CHNCFG5_TRGSRC10_EVENT_USER1_Val << ADC_CHNCFG5_TRGSRC10_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 1 Position  */
#define ADC_CHNCFG5_TRGSRC10_EVENT_USER2      (ADC_CHNCFG5_TRGSRC10_EVENT_USER2_Val << ADC_CHNCFG5_TRGSRC10_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 2 Position  */
#define ADC_CHNCFG5_TRGSRC10_EVENT_USER3      (ADC_CHNCFG5_TRGSRC10_EVENT_USER3_Val << ADC_CHNCFG5_TRGSRC10_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 3 Position  */
#define ADC_CHNCFG5_TRGSRC10_EVENT_USER4      (ADC_CHNCFG5_TRGSRC10_EVENT_USER4_Val << ADC_CHNCFG5_TRGSRC10_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 4 Position  */
#define ADC_CHNCFG5_TRGSRC10_EVENT_USER5      (ADC_CHNCFG5_TRGSRC10_EVENT_USER5_Val << ADC_CHNCFG5_TRGSRC10_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 5 Position  */
#define ADC_CHNCFG5_TRGSRC10_EVENT_USER6      (ADC_CHNCFG5_TRGSRC10_EVENT_USER6_Val << ADC_CHNCFG5_TRGSRC10_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 6 Position  */
#define ADC_CHNCFG5_TRGSRC10_EVENT_USER7      (ADC_CHNCFG5_TRGSRC10_EVENT_USER7_Val << ADC_CHNCFG5_TRGSRC10_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 7 Position  */
#define ADC_CHNCFG5_TRGSRC10_EVENT_USER8      (ADC_CHNCFG5_TRGSRC10_EVENT_USER8_Val << ADC_CHNCFG5_TRGSRC10_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 8 Position  */
#define ADC_CHNCFG5_TRGSRC10_EVENT_USER9      (ADC_CHNCFG5_TRGSRC10_EVENT_USER9_Val << ADC_CHNCFG5_TRGSRC10_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 9 Position  */
#define ADC_CHNCFG5_TRGSRC10_EVENT_USER10     (ADC_CHNCFG5_TRGSRC10_EVENT_USER10_Val << ADC_CHNCFG5_TRGSRC10_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 10 Position  */
#define ADC_CHNCFG5_TRGSRC11_Pos              _UINT32_(12)                                         /* (ADC_CHNCFG5) Channel 11 Trigger Source Position */
#define ADC_CHNCFG5_TRGSRC11_Msk              (_UINT32_(0xF) << ADC_CHNCFG5_TRGSRC11_Pos)          /* (ADC_CHNCFG5) Channel 11 Trigger Source Mask */
#define ADC_CHNCFG5_TRGSRC11(value)           (ADC_CHNCFG5_TRGSRC11_Msk & (_UINT32_(value) << ADC_CHNCFG5_TRGSRC11_Pos)) /* Assigment of value for TRGSRC11 in the ADC_CHNCFG5 register */
#define   ADC_CHNCFG5_TRGSRC11_NO_TRIGGER_Val _UINT32_(0x0)                                        /* (ADC_CHNCFG5) No Trigger (NOP)  */
#define   ADC_CHNCFG5_TRGSRC11_GLOBAL_SOFTWARE_TRIGGER_Val _UINT32_(0x1)                                        /* (ADC_CHNCFG5) Global Software Trigger  */
#define   ADC_CHNCFG5_TRGSRC11_GLOBAL_LEVEL_TRIGGER_Val _UINT32_(0x2)                                        /* (ADC_CHNCFG5) Global Level Software Trigger  */
#define   ADC_CHNCFG5_TRGSRC11_SCAN_TRIGGER_Val _UINT32_(0x3)                                        /* (ADC_CHNCFG5) SCANTRG - Scan Trigger  */
#define   ADC_CHNCFG5_TRGSRC11_SYNC_TRIGGER_Val _UINT32_(0x4)                                        /* (ADC_CHNCFG5) STRIG Synchronous Trigger  */
#define   ADC_CHNCFG5_TRGSRC11_EVENT_USER0_Val _UINT32_(0x5)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 0  */
#define   ADC_CHNCFG5_TRGSRC11_EVENT_USER1_Val _UINT32_(0x6)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 1  */
#define   ADC_CHNCFG5_TRGSRC11_EVENT_USER2_Val _UINT32_(0x7)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 2  */
#define   ADC_CHNCFG5_TRGSRC11_EVENT_USER3_Val _UINT32_(0x8)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 3  */
#define   ADC_CHNCFG5_TRGSRC11_EVENT_USER4_Val _UINT32_(0x9)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 4  */
#define   ADC_CHNCFG5_TRGSRC11_EVENT_USER5_Val _UINT32_(0xA)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 5  */
#define   ADC_CHNCFG5_TRGSRC11_EVENT_USER6_Val _UINT32_(0xB)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 6  */
#define   ADC_CHNCFG5_TRGSRC11_EVENT_USER7_Val _UINT32_(0xC)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 7  */
#define   ADC_CHNCFG5_TRGSRC11_EVENT_USER8_Val _UINT32_(0xD)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 8  */
#define   ADC_CHNCFG5_TRGSRC11_EVENT_USER9_Val _UINT32_(0xE)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 9  */
#define   ADC_CHNCFG5_TRGSRC11_EVENT_USER10_Val _UINT32_(0xF)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 10  */
#define ADC_CHNCFG5_TRGSRC11_NO_TRIGGER       (ADC_CHNCFG5_TRGSRC11_NO_TRIGGER_Val << ADC_CHNCFG5_TRGSRC11_Pos) /* (ADC_CHNCFG5) No Trigger (NOP) Position  */
#define ADC_CHNCFG5_TRGSRC11_GLOBAL_SOFTWARE_TRIGGER (ADC_CHNCFG5_TRGSRC11_GLOBAL_SOFTWARE_TRIGGER_Val << ADC_CHNCFG5_TRGSRC11_Pos) /* (ADC_CHNCFG5) Global Software Trigger Position  */
#define ADC_CHNCFG5_TRGSRC11_GLOBAL_LEVEL_TRIGGER (ADC_CHNCFG5_TRGSRC11_GLOBAL_LEVEL_TRIGGER_Val << ADC_CHNCFG5_TRGSRC11_Pos) /* (ADC_CHNCFG5) Global Level Software Trigger Position  */
#define ADC_CHNCFG5_TRGSRC11_SCAN_TRIGGER     (ADC_CHNCFG5_TRGSRC11_SCAN_TRIGGER_Val << ADC_CHNCFG5_TRGSRC11_Pos) /* (ADC_CHNCFG5) SCANTRG - Scan Trigger Position  */
#define ADC_CHNCFG5_TRGSRC11_SYNC_TRIGGER     (ADC_CHNCFG5_TRGSRC11_SYNC_TRIGGER_Val << ADC_CHNCFG5_TRGSRC11_Pos) /* (ADC_CHNCFG5) STRIG Synchronous Trigger Position  */
#define ADC_CHNCFG5_TRGSRC11_EVENT_USER0      (ADC_CHNCFG5_TRGSRC11_EVENT_USER0_Val << ADC_CHNCFG5_TRGSRC11_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 0 Position  */
#define ADC_CHNCFG5_TRGSRC11_EVENT_USER1      (ADC_CHNCFG5_TRGSRC11_EVENT_USER1_Val << ADC_CHNCFG5_TRGSRC11_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 1 Position  */
#define ADC_CHNCFG5_TRGSRC11_EVENT_USER2      (ADC_CHNCFG5_TRGSRC11_EVENT_USER2_Val << ADC_CHNCFG5_TRGSRC11_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 2 Position  */
#define ADC_CHNCFG5_TRGSRC11_EVENT_USER3      (ADC_CHNCFG5_TRGSRC11_EVENT_USER3_Val << ADC_CHNCFG5_TRGSRC11_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 3 Position  */
#define ADC_CHNCFG5_TRGSRC11_EVENT_USER4      (ADC_CHNCFG5_TRGSRC11_EVENT_USER4_Val << ADC_CHNCFG5_TRGSRC11_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 4 Position  */
#define ADC_CHNCFG5_TRGSRC11_EVENT_USER5      (ADC_CHNCFG5_TRGSRC11_EVENT_USER5_Val << ADC_CHNCFG5_TRGSRC11_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 5 Position  */
#define ADC_CHNCFG5_TRGSRC11_EVENT_USER6      (ADC_CHNCFG5_TRGSRC11_EVENT_USER6_Val << ADC_CHNCFG5_TRGSRC11_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 6 Position  */
#define ADC_CHNCFG5_TRGSRC11_EVENT_USER7      (ADC_CHNCFG5_TRGSRC11_EVENT_USER7_Val << ADC_CHNCFG5_TRGSRC11_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 7 Position  */
#define ADC_CHNCFG5_TRGSRC11_EVENT_USER8      (ADC_CHNCFG5_TRGSRC11_EVENT_USER8_Val << ADC_CHNCFG5_TRGSRC11_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 8 Position  */
#define ADC_CHNCFG5_TRGSRC11_EVENT_USER9      (ADC_CHNCFG5_TRGSRC11_EVENT_USER9_Val << ADC_CHNCFG5_TRGSRC11_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 9 Position  */
#define ADC_CHNCFG5_TRGSRC11_EVENT_USER10     (ADC_CHNCFG5_TRGSRC11_EVENT_USER10_Val << ADC_CHNCFG5_TRGSRC11_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 10 Position  */
#define ADC_CHNCFG5_TRGSRC12_Pos              _UINT32_(16)                                         /* (ADC_CHNCFG5) Channel 12 Trigger Source Position */
#define ADC_CHNCFG5_TRGSRC12_Msk              (_UINT32_(0xF) << ADC_CHNCFG5_TRGSRC12_Pos)          /* (ADC_CHNCFG5) Channel 12 Trigger Source Mask */
#define ADC_CHNCFG5_TRGSRC12(value)           (ADC_CHNCFG5_TRGSRC12_Msk & (_UINT32_(value) << ADC_CHNCFG5_TRGSRC12_Pos)) /* Assigment of value for TRGSRC12 in the ADC_CHNCFG5 register */
#define   ADC_CHNCFG5_TRGSRC12_NO_TRIGGER_Val _UINT32_(0x0)                                        /* (ADC_CHNCFG5) No Trigger (NOP)  */
#define   ADC_CHNCFG5_TRGSRC12_GLOBAL_SOFTWARE_TRIGGER_Val _UINT32_(0x1)                                        /* (ADC_CHNCFG5) Global Software Trigger  */
#define   ADC_CHNCFG5_TRGSRC12_GLOBAL_LEVEL_TRIGGER_Val _UINT32_(0x2)                                        /* (ADC_CHNCFG5) Global Level Software Trigger  */
#define   ADC_CHNCFG5_TRGSRC12_SCAN_TRIGGER_Val _UINT32_(0x3)                                        /* (ADC_CHNCFG5) SCANTRG - Scan Trigger  */
#define   ADC_CHNCFG5_TRGSRC12_SYNC_TRIGGER_Val _UINT32_(0x4)                                        /* (ADC_CHNCFG5) STRIG Synchronous Trigger  */
#define   ADC_CHNCFG5_TRGSRC12_EVENT_USER0_Val _UINT32_(0x5)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 0  */
#define   ADC_CHNCFG5_TRGSRC12_EVENT_USER1_Val _UINT32_(0x6)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 1  */
#define   ADC_CHNCFG5_TRGSRC12_EVENT_USER2_Val _UINT32_(0x7)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 2  */
#define   ADC_CHNCFG5_TRGSRC12_EVENT_USER3_Val _UINT32_(0x8)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 3  */
#define   ADC_CHNCFG5_TRGSRC12_EVENT_USER4_Val _UINT32_(0x9)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 4  */
#define   ADC_CHNCFG5_TRGSRC12_EVENT_USER5_Val _UINT32_(0xA)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 5  */
#define   ADC_CHNCFG5_TRGSRC12_EVENT_USER6_Val _UINT32_(0xB)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 6  */
#define   ADC_CHNCFG5_TRGSRC12_EVENT_USER7_Val _UINT32_(0xC)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 7  */
#define   ADC_CHNCFG5_TRGSRC12_EVENT_USER8_Val _UINT32_(0xD)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 8  */
#define   ADC_CHNCFG5_TRGSRC12_EVENT_USER9_Val _UINT32_(0xE)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 9  */
#define   ADC_CHNCFG5_TRGSRC12_EVENT_USER10_Val _UINT32_(0xF)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 10  */
#define ADC_CHNCFG5_TRGSRC12_NO_TRIGGER       (ADC_CHNCFG5_TRGSRC12_NO_TRIGGER_Val << ADC_CHNCFG5_TRGSRC12_Pos) /* (ADC_CHNCFG5) No Trigger (NOP) Position  */
#define ADC_CHNCFG5_TRGSRC12_GLOBAL_SOFTWARE_TRIGGER (ADC_CHNCFG5_TRGSRC12_GLOBAL_SOFTWARE_TRIGGER_Val << ADC_CHNCFG5_TRGSRC12_Pos) /* (ADC_CHNCFG5) Global Software Trigger Position  */
#define ADC_CHNCFG5_TRGSRC12_GLOBAL_LEVEL_TRIGGER (ADC_CHNCFG5_TRGSRC12_GLOBAL_LEVEL_TRIGGER_Val << ADC_CHNCFG5_TRGSRC12_Pos) /* (ADC_CHNCFG5) Global Level Software Trigger Position  */
#define ADC_CHNCFG5_TRGSRC12_SCAN_TRIGGER     (ADC_CHNCFG5_TRGSRC12_SCAN_TRIGGER_Val << ADC_CHNCFG5_TRGSRC12_Pos) /* (ADC_CHNCFG5) SCANTRG - Scan Trigger Position  */
#define ADC_CHNCFG5_TRGSRC12_SYNC_TRIGGER     (ADC_CHNCFG5_TRGSRC12_SYNC_TRIGGER_Val << ADC_CHNCFG5_TRGSRC12_Pos) /* (ADC_CHNCFG5) STRIG Synchronous Trigger Position  */
#define ADC_CHNCFG5_TRGSRC12_EVENT_USER0      (ADC_CHNCFG5_TRGSRC12_EVENT_USER0_Val << ADC_CHNCFG5_TRGSRC12_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 0 Position  */
#define ADC_CHNCFG5_TRGSRC12_EVENT_USER1      (ADC_CHNCFG5_TRGSRC12_EVENT_USER1_Val << ADC_CHNCFG5_TRGSRC12_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 1 Position  */
#define ADC_CHNCFG5_TRGSRC12_EVENT_USER2      (ADC_CHNCFG5_TRGSRC12_EVENT_USER2_Val << ADC_CHNCFG5_TRGSRC12_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 2 Position  */
#define ADC_CHNCFG5_TRGSRC12_EVENT_USER3      (ADC_CHNCFG5_TRGSRC12_EVENT_USER3_Val << ADC_CHNCFG5_TRGSRC12_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 3 Position  */
#define ADC_CHNCFG5_TRGSRC12_EVENT_USER4      (ADC_CHNCFG5_TRGSRC12_EVENT_USER4_Val << ADC_CHNCFG5_TRGSRC12_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 4 Position  */
#define ADC_CHNCFG5_TRGSRC12_EVENT_USER5      (ADC_CHNCFG5_TRGSRC12_EVENT_USER5_Val << ADC_CHNCFG5_TRGSRC12_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 5 Position  */
#define ADC_CHNCFG5_TRGSRC12_EVENT_USER6      (ADC_CHNCFG5_TRGSRC12_EVENT_USER6_Val << ADC_CHNCFG5_TRGSRC12_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 6 Position  */
#define ADC_CHNCFG5_TRGSRC12_EVENT_USER7      (ADC_CHNCFG5_TRGSRC12_EVENT_USER7_Val << ADC_CHNCFG5_TRGSRC12_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 7 Position  */
#define ADC_CHNCFG5_TRGSRC12_EVENT_USER8      (ADC_CHNCFG5_TRGSRC12_EVENT_USER8_Val << ADC_CHNCFG5_TRGSRC12_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 8 Position  */
#define ADC_CHNCFG5_TRGSRC12_EVENT_USER9      (ADC_CHNCFG5_TRGSRC12_EVENT_USER9_Val << ADC_CHNCFG5_TRGSRC12_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 9 Position  */
#define ADC_CHNCFG5_TRGSRC12_EVENT_USER10     (ADC_CHNCFG5_TRGSRC12_EVENT_USER10_Val << ADC_CHNCFG5_TRGSRC12_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 10 Position  */
#define ADC_CHNCFG5_TRGSRC13_Pos              _UINT32_(20)                                         /* (ADC_CHNCFG5) Channel 13 Trigger Source Position */
#define ADC_CHNCFG5_TRGSRC13_Msk              (_UINT32_(0xF) << ADC_CHNCFG5_TRGSRC13_Pos)          /* (ADC_CHNCFG5) Channel 13 Trigger Source Mask */
#define ADC_CHNCFG5_TRGSRC13(value)           (ADC_CHNCFG5_TRGSRC13_Msk & (_UINT32_(value) << ADC_CHNCFG5_TRGSRC13_Pos)) /* Assigment of value for TRGSRC13 in the ADC_CHNCFG5 register */
#define   ADC_CHNCFG5_TRGSRC13_NO_TRIGGER_Val _UINT32_(0x0)                                        /* (ADC_CHNCFG5) No Trigger (NOP)  */
#define   ADC_CHNCFG5_TRGSRC13_GLOBAL_SOFTWARE_TRIGGER_Val _UINT32_(0x1)                                        /* (ADC_CHNCFG5) Global Software Trigger  */
#define   ADC_CHNCFG5_TRGSRC13_GLOBAL_LEVEL_TRIGGER_Val _UINT32_(0x2)                                        /* (ADC_CHNCFG5) Global Level Software Trigger  */
#define   ADC_CHNCFG5_TRGSRC13_SCAN_TRIGGER_Val _UINT32_(0x3)                                        /* (ADC_CHNCFG5) SCANTRG - Scan Trigger  */
#define   ADC_CHNCFG5_TRGSRC13_SYNC_TRIGGER_Val _UINT32_(0x4)                                        /* (ADC_CHNCFG5) STRIG Synchronous Trigger  */
#define   ADC_CHNCFG5_TRGSRC13_EVENT_USER0_Val _UINT32_(0x5)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 0  */
#define   ADC_CHNCFG5_TRGSRC13_EVENT_USER1_Val _UINT32_(0x6)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 1  */
#define   ADC_CHNCFG5_TRGSRC13_EVENT_USER2_Val _UINT32_(0x7)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 2  */
#define   ADC_CHNCFG5_TRGSRC13_EVENT_USER3_Val _UINT32_(0x8)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 3  */
#define   ADC_CHNCFG5_TRGSRC13_EVENT_USER4_Val _UINT32_(0x9)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 4  */
#define   ADC_CHNCFG5_TRGSRC13_EVENT_USER5_Val _UINT32_(0xA)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 5  */
#define   ADC_CHNCFG5_TRGSRC13_EVENT_USER6_Val _UINT32_(0xB)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 6  */
#define   ADC_CHNCFG5_TRGSRC13_EVENT_USER7_Val _UINT32_(0xC)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 7  */
#define   ADC_CHNCFG5_TRGSRC13_EVENT_USER8_Val _UINT32_(0xD)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 8  */
#define   ADC_CHNCFG5_TRGSRC13_EVENT_USER9_Val _UINT32_(0xE)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 9  */
#define   ADC_CHNCFG5_TRGSRC13_EVENT_USER10_Val _UINT32_(0xF)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 10  */
#define ADC_CHNCFG5_TRGSRC13_NO_TRIGGER       (ADC_CHNCFG5_TRGSRC13_NO_TRIGGER_Val << ADC_CHNCFG5_TRGSRC13_Pos) /* (ADC_CHNCFG5) No Trigger (NOP) Position  */
#define ADC_CHNCFG5_TRGSRC13_GLOBAL_SOFTWARE_TRIGGER (ADC_CHNCFG5_TRGSRC13_GLOBAL_SOFTWARE_TRIGGER_Val << ADC_CHNCFG5_TRGSRC13_Pos) /* (ADC_CHNCFG5) Global Software Trigger Position  */
#define ADC_CHNCFG5_TRGSRC13_GLOBAL_LEVEL_TRIGGER (ADC_CHNCFG5_TRGSRC13_GLOBAL_LEVEL_TRIGGER_Val << ADC_CHNCFG5_TRGSRC13_Pos) /* (ADC_CHNCFG5) Global Level Software Trigger Position  */
#define ADC_CHNCFG5_TRGSRC13_SCAN_TRIGGER     (ADC_CHNCFG5_TRGSRC13_SCAN_TRIGGER_Val << ADC_CHNCFG5_TRGSRC13_Pos) /* (ADC_CHNCFG5) SCANTRG - Scan Trigger Position  */
#define ADC_CHNCFG5_TRGSRC13_SYNC_TRIGGER     (ADC_CHNCFG5_TRGSRC13_SYNC_TRIGGER_Val << ADC_CHNCFG5_TRGSRC13_Pos) /* (ADC_CHNCFG5) STRIG Synchronous Trigger Position  */
#define ADC_CHNCFG5_TRGSRC13_EVENT_USER0      (ADC_CHNCFG5_TRGSRC13_EVENT_USER0_Val << ADC_CHNCFG5_TRGSRC13_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 0 Position  */
#define ADC_CHNCFG5_TRGSRC13_EVENT_USER1      (ADC_CHNCFG5_TRGSRC13_EVENT_USER1_Val << ADC_CHNCFG5_TRGSRC13_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 1 Position  */
#define ADC_CHNCFG5_TRGSRC13_EVENT_USER2      (ADC_CHNCFG5_TRGSRC13_EVENT_USER2_Val << ADC_CHNCFG5_TRGSRC13_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 2 Position  */
#define ADC_CHNCFG5_TRGSRC13_EVENT_USER3      (ADC_CHNCFG5_TRGSRC13_EVENT_USER3_Val << ADC_CHNCFG5_TRGSRC13_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 3 Position  */
#define ADC_CHNCFG5_TRGSRC13_EVENT_USER4      (ADC_CHNCFG5_TRGSRC13_EVENT_USER4_Val << ADC_CHNCFG5_TRGSRC13_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 4 Position  */
#define ADC_CHNCFG5_TRGSRC13_EVENT_USER5      (ADC_CHNCFG5_TRGSRC13_EVENT_USER5_Val << ADC_CHNCFG5_TRGSRC13_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 5 Position  */
#define ADC_CHNCFG5_TRGSRC13_EVENT_USER6      (ADC_CHNCFG5_TRGSRC13_EVENT_USER6_Val << ADC_CHNCFG5_TRGSRC13_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 6 Position  */
#define ADC_CHNCFG5_TRGSRC13_EVENT_USER7      (ADC_CHNCFG5_TRGSRC13_EVENT_USER7_Val << ADC_CHNCFG5_TRGSRC13_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 7 Position  */
#define ADC_CHNCFG5_TRGSRC13_EVENT_USER8      (ADC_CHNCFG5_TRGSRC13_EVENT_USER8_Val << ADC_CHNCFG5_TRGSRC13_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 8 Position  */
#define ADC_CHNCFG5_TRGSRC13_EVENT_USER9      (ADC_CHNCFG5_TRGSRC13_EVENT_USER9_Val << ADC_CHNCFG5_TRGSRC13_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 9 Position  */
#define ADC_CHNCFG5_TRGSRC13_EVENT_USER10     (ADC_CHNCFG5_TRGSRC13_EVENT_USER10_Val << ADC_CHNCFG5_TRGSRC13_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 10 Position  */
#define ADC_CHNCFG5_TRGSRC14_Pos              _UINT32_(24)                                         /* (ADC_CHNCFG5) Channel 14 Trigger Source Position */
#define ADC_CHNCFG5_TRGSRC14_Msk              (_UINT32_(0xF) << ADC_CHNCFG5_TRGSRC14_Pos)          /* (ADC_CHNCFG5) Channel 14 Trigger Source Mask */
#define ADC_CHNCFG5_TRGSRC14(value)           (ADC_CHNCFG5_TRGSRC14_Msk & (_UINT32_(value) << ADC_CHNCFG5_TRGSRC14_Pos)) /* Assigment of value for TRGSRC14 in the ADC_CHNCFG5 register */
#define   ADC_CHNCFG5_TRGSRC14_NO_TRIGGER_Val _UINT32_(0x0)                                        /* (ADC_CHNCFG5) No Trigger (NOP)  */
#define   ADC_CHNCFG5_TRGSRC14_GLOBAL_SOFTWARE_TRIGGER_Val _UINT32_(0x1)                                        /* (ADC_CHNCFG5) Global Software Trigger  */
#define   ADC_CHNCFG5_TRGSRC14_GLOBAL_LEVEL_TRIGGER_Val _UINT32_(0x2)                                        /* (ADC_CHNCFG5) Global Level Software Trigger  */
#define   ADC_CHNCFG5_TRGSRC14_SCAN_TRIGGER_Val _UINT32_(0x3)                                        /* (ADC_CHNCFG5) SCANTRG - Scan Trigger  */
#define   ADC_CHNCFG5_TRGSRC14_SYNC_TRIGGER_Val _UINT32_(0x4)                                        /* (ADC_CHNCFG5) STRIG Synchronous Trigger  */
#define   ADC_CHNCFG5_TRGSRC14_EVENT_USER0_Val _UINT32_(0x5)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 0  */
#define   ADC_CHNCFG5_TRGSRC14_EVENT_USER1_Val _UINT32_(0x6)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 1  */
#define   ADC_CHNCFG5_TRGSRC14_EVENT_USER2_Val _UINT32_(0x7)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 2  */
#define   ADC_CHNCFG5_TRGSRC14_EVENT_USER3_Val _UINT32_(0x8)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 3  */
#define   ADC_CHNCFG5_TRGSRC14_EVENT_USER4_Val _UINT32_(0x9)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 4  */
#define   ADC_CHNCFG5_TRGSRC14_EVENT_USER5_Val _UINT32_(0xA)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 5  */
#define   ADC_CHNCFG5_TRGSRC14_EVENT_USER6_Val _UINT32_(0xB)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 6  */
#define   ADC_CHNCFG5_TRGSRC14_EVENT_USER7_Val _UINT32_(0xC)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 7  */
#define   ADC_CHNCFG5_TRGSRC14_EVENT_USER8_Val _UINT32_(0xD)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 8  */
#define   ADC_CHNCFG5_TRGSRC14_EVENT_USER9_Val _UINT32_(0xE)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 9  */
#define   ADC_CHNCFG5_TRGSRC14_EVENT_USER10_Val _UINT32_(0xF)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 10  */
#define ADC_CHNCFG5_TRGSRC14_NO_TRIGGER       (ADC_CHNCFG5_TRGSRC14_NO_TRIGGER_Val << ADC_CHNCFG5_TRGSRC14_Pos) /* (ADC_CHNCFG5) No Trigger (NOP) Position  */
#define ADC_CHNCFG5_TRGSRC14_GLOBAL_SOFTWARE_TRIGGER (ADC_CHNCFG5_TRGSRC14_GLOBAL_SOFTWARE_TRIGGER_Val << ADC_CHNCFG5_TRGSRC14_Pos) /* (ADC_CHNCFG5) Global Software Trigger Position  */
#define ADC_CHNCFG5_TRGSRC14_GLOBAL_LEVEL_TRIGGER (ADC_CHNCFG5_TRGSRC14_GLOBAL_LEVEL_TRIGGER_Val << ADC_CHNCFG5_TRGSRC14_Pos) /* (ADC_CHNCFG5) Global Level Software Trigger Position  */
#define ADC_CHNCFG5_TRGSRC14_SCAN_TRIGGER     (ADC_CHNCFG5_TRGSRC14_SCAN_TRIGGER_Val << ADC_CHNCFG5_TRGSRC14_Pos) /* (ADC_CHNCFG5) SCANTRG - Scan Trigger Position  */
#define ADC_CHNCFG5_TRGSRC14_SYNC_TRIGGER     (ADC_CHNCFG5_TRGSRC14_SYNC_TRIGGER_Val << ADC_CHNCFG5_TRGSRC14_Pos) /* (ADC_CHNCFG5) STRIG Synchronous Trigger Position  */
#define ADC_CHNCFG5_TRGSRC14_EVENT_USER0      (ADC_CHNCFG5_TRGSRC14_EVENT_USER0_Val << ADC_CHNCFG5_TRGSRC14_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 0 Position  */
#define ADC_CHNCFG5_TRGSRC14_EVENT_USER1      (ADC_CHNCFG5_TRGSRC14_EVENT_USER1_Val << ADC_CHNCFG5_TRGSRC14_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 1 Position  */
#define ADC_CHNCFG5_TRGSRC14_EVENT_USER2      (ADC_CHNCFG5_TRGSRC14_EVENT_USER2_Val << ADC_CHNCFG5_TRGSRC14_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 2 Position  */
#define ADC_CHNCFG5_TRGSRC14_EVENT_USER3      (ADC_CHNCFG5_TRGSRC14_EVENT_USER3_Val << ADC_CHNCFG5_TRGSRC14_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 3 Position  */
#define ADC_CHNCFG5_TRGSRC14_EVENT_USER4      (ADC_CHNCFG5_TRGSRC14_EVENT_USER4_Val << ADC_CHNCFG5_TRGSRC14_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 4 Position  */
#define ADC_CHNCFG5_TRGSRC14_EVENT_USER5      (ADC_CHNCFG5_TRGSRC14_EVENT_USER5_Val << ADC_CHNCFG5_TRGSRC14_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 5 Position  */
#define ADC_CHNCFG5_TRGSRC14_EVENT_USER6      (ADC_CHNCFG5_TRGSRC14_EVENT_USER6_Val << ADC_CHNCFG5_TRGSRC14_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 6 Position  */
#define ADC_CHNCFG5_TRGSRC14_EVENT_USER7      (ADC_CHNCFG5_TRGSRC14_EVENT_USER7_Val << ADC_CHNCFG5_TRGSRC14_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 7 Position  */
#define ADC_CHNCFG5_TRGSRC14_EVENT_USER8      (ADC_CHNCFG5_TRGSRC14_EVENT_USER8_Val << ADC_CHNCFG5_TRGSRC14_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 8 Position  */
#define ADC_CHNCFG5_TRGSRC14_EVENT_USER9      (ADC_CHNCFG5_TRGSRC14_EVENT_USER9_Val << ADC_CHNCFG5_TRGSRC14_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 9 Position  */
#define ADC_CHNCFG5_TRGSRC14_EVENT_USER10     (ADC_CHNCFG5_TRGSRC14_EVENT_USER10_Val << ADC_CHNCFG5_TRGSRC14_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 10 Position  */
#define ADC_CHNCFG5_TRGSRC15_Pos              _UINT32_(28)                                         /* (ADC_CHNCFG5) Channel 15 Trigger Source Position */
#define ADC_CHNCFG5_TRGSRC15_Msk              (_UINT32_(0xF) << ADC_CHNCFG5_TRGSRC15_Pos)          /* (ADC_CHNCFG5) Channel 15 Trigger Source Mask */
#define ADC_CHNCFG5_TRGSRC15(value)           (ADC_CHNCFG5_TRGSRC15_Msk & (_UINT32_(value) << ADC_CHNCFG5_TRGSRC15_Pos)) /* Assigment of value for TRGSRC15 in the ADC_CHNCFG5 register */
#define   ADC_CHNCFG5_TRGSRC15_NO_TRIGGER_Val _UINT32_(0x0)                                        /* (ADC_CHNCFG5) No Trigger (NOP)  */
#define   ADC_CHNCFG5_TRGSRC15_GLOBAL_SOFTWARE_TRIGGER_Val _UINT32_(0x1)                                        /* (ADC_CHNCFG5) Global Software Trigger  */
#define   ADC_CHNCFG5_TRGSRC15_GLOBAL_LEVEL_TRIGGER_Val _UINT32_(0x2)                                        /* (ADC_CHNCFG5) Global Level Software Trigger  */
#define   ADC_CHNCFG5_TRGSRC15_SCAN_TRIGGER_Val _UINT32_(0x3)                                        /* (ADC_CHNCFG5) SCANTRG - Scan Trigger  */
#define   ADC_CHNCFG5_TRGSRC15_SYNC_TRIGGER_Val _UINT32_(0x4)                                        /* (ADC_CHNCFG5) STRIG Synchronous Trigger  */
#define   ADC_CHNCFG5_TRGSRC15_EVENT_USER0_Val _UINT32_(0x5)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 0  */
#define   ADC_CHNCFG5_TRGSRC15_EVENT_USER1_Val _UINT32_(0x6)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 1  */
#define   ADC_CHNCFG5_TRGSRC15_EVENT_USER2_Val _UINT32_(0x7)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 2  */
#define   ADC_CHNCFG5_TRGSRC15_EVENT_USER3_Val _UINT32_(0x8)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 3  */
#define   ADC_CHNCFG5_TRGSRC15_EVENT_USER4_Val _UINT32_(0x9)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 4  */
#define   ADC_CHNCFG5_TRGSRC15_EVENT_USER5_Val _UINT32_(0xA)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 5  */
#define   ADC_CHNCFG5_TRGSRC15_EVENT_USER6_Val _UINT32_(0xB)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 6  */
#define   ADC_CHNCFG5_TRGSRC15_EVENT_USER7_Val _UINT32_(0xC)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 7  */
#define   ADC_CHNCFG5_TRGSRC15_EVENT_USER8_Val _UINT32_(0xD)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 8  */
#define   ADC_CHNCFG5_TRGSRC15_EVENT_USER9_Val _UINT32_(0xE)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 9  */
#define   ADC_CHNCFG5_TRGSRC15_EVENT_USER10_Val _UINT32_(0xF)                                        /* (ADC_CHNCFG5) ADC Trigger Event User 10  */
#define ADC_CHNCFG5_TRGSRC15_NO_TRIGGER       (ADC_CHNCFG5_TRGSRC15_NO_TRIGGER_Val << ADC_CHNCFG5_TRGSRC15_Pos) /* (ADC_CHNCFG5) No Trigger (NOP) Position  */
#define ADC_CHNCFG5_TRGSRC15_GLOBAL_SOFTWARE_TRIGGER (ADC_CHNCFG5_TRGSRC15_GLOBAL_SOFTWARE_TRIGGER_Val << ADC_CHNCFG5_TRGSRC15_Pos) /* (ADC_CHNCFG5) Global Software Trigger Position  */
#define ADC_CHNCFG5_TRGSRC15_GLOBAL_LEVEL_TRIGGER (ADC_CHNCFG5_TRGSRC15_GLOBAL_LEVEL_TRIGGER_Val << ADC_CHNCFG5_TRGSRC15_Pos) /* (ADC_CHNCFG5) Global Level Software Trigger Position  */
#define ADC_CHNCFG5_TRGSRC15_SCAN_TRIGGER     (ADC_CHNCFG5_TRGSRC15_SCAN_TRIGGER_Val << ADC_CHNCFG5_TRGSRC15_Pos) /* (ADC_CHNCFG5) SCANTRG - Scan Trigger Position  */
#define ADC_CHNCFG5_TRGSRC15_SYNC_TRIGGER     (ADC_CHNCFG5_TRGSRC15_SYNC_TRIGGER_Val << ADC_CHNCFG5_TRGSRC15_Pos) /* (ADC_CHNCFG5) STRIG Synchronous Trigger Position  */
#define ADC_CHNCFG5_TRGSRC15_EVENT_USER0      (ADC_CHNCFG5_TRGSRC15_EVENT_USER0_Val << ADC_CHNCFG5_TRGSRC15_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 0 Position  */
#define ADC_CHNCFG5_TRGSRC15_EVENT_USER1      (ADC_CHNCFG5_TRGSRC15_EVENT_USER1_Val << ADC_CHNCFG5_TRGSRC15_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 1 Position  */
#define ADC_CHNCFG5_TRGSRC15_EVENT_USER2      (ADC_CHNCFG5_TRGSRC15_EVENT_USER2_Val << ADC_CHNCFG5_TRGSRC15_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 2 Position  */
#define ADC_CHNCFG5_TRGSRC15_EVENT_USER3      (ADC_CHNCFG5_TRGSRC15_EVENT_USER3_Val << ADC_CHNCFG5_TRGSRC15_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 3 Position  */
#define ADC_CHNCFG5_TRGSRC15_EVENT_USER4      (ADC_CHNCFG5_TRGSRC15_EVENT_USER4_Val << ADC_CHNCFG5_TRGSRC15_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 4 Position  */
#define ADC_CHNCFG5_TRGSRC15_EVENT_USER5      (ADC_CHNCFG5_TRGSRC15_EVENT_USER5_Val << ADC_CHNCFG5_TRGSRC15_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 5 Position  */
#define ADC_CHNCFG5_TRGSRC15_EVENT_USER6      (ADC_CHNCFG5_TRGSRC15_EVENT_USER6_Val << ADC_CHNCFG5_TRGSRC15_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 6 Position  */
#define ADC_CHNCFG5_TRGSRC15_EVENT_USER7      (ADC_CHNCFG5_TRGSRC15_EVENT_USER7_Val << ADC_CHNCFG5_TRGSRC15_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 7 Position  */
#define ADC_CHNCFG5_TRGSRC15_EVENT_USER8      (ADC_CHNCFG5_TRGSRC15_EVENT_USER8_Val << ADC_CHNCFG5_TRGSRC15_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 8 Position  */
#define ADC_CHNCFG5_TRGSRC15_EVENT_USER9      (ADC_CHNCFG5_TRGSRC15_EVENT_USER9_Val << ADC_CHNCFG5_TRGSRC15_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 9 Position  */
#define ADC_CHNCFG5_TRGSRC15_EVENT_USER10     (ADC_CHNCFG5_TRGSRC15_EVENT_USER10_Val << ADC_CHNCFG5_TRGSRC15_Pos) /* (ADC_CHNCFG5) ADC Trigger Event User 10 Position  */
#define ADC_CHNCFG5_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (ADC_CHNCFG5) Register Mask  */


/* -------- ADC_CALCTRL : (ADC Offset: 0x18) (R/W 32) SARCORE Calibration Value -------- */
#define ADC_CALCTRL_RESETVALUE                _UINT32_(0x00)                                       /*  (ADC_CALCTRL) SARCORE Calibration Value  Reset Value */

#define ADC_CALCTRL_CALBITS_Pos               _UINT32_(0)                                          /* (ADC_CALCTRL) Calibration Values Position */
#define ADC_CALCTRL_CALBITS_Msk               (_UINT32_(0xFFFFFFFF) << ADC_CALCTRL_CALBITS_Pos)    /* (ADC_CALCTRL) Calibration Values Mask */
#define ADC_CALCTRL_CALBITS(value)            (ADC_CALCTRL_CALBITS_Msk & (_UINT32_(value) << ADC_CALCTRL_CALBITS_Pos)) /* Assigment of value for CALBITS in the ADC_CALCTRL register */
#define ADC_CALCTRL_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (ADC_CALCTRL) Register Mask  */

/* FUSES_ADC_SARCORE_12BIT_V7A0 mode */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_en_cmbf_Pos _UINT32_(0)                                          /* (ADC_CALCTRL) Enable Common Mode Buffer Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_en_cmbf_Msk (_UINT32_(0x1) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_en_cmbf_Pos) /* (ADC_CALCTRL) Enable Common Mode Buffer Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_en_cmbf(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_en_cmbf_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_en_cmbf_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_en_dither_Pos _UINT32_(2)                                          /* (ADC_CALCTRL) Enable Dither Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_en_dither_Msk (_UINT32_(0x1) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_en_dither_Pos) /* (ADC_CALCTRL) Enable Dither Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_en_dither(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_en_dither_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_en_dither_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_dis_faz_Pos _UINT32_(3)                                          /* (ADC_CALCTRL) Disable auto-zeroing Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_dis_faz_Msk (_UINT32_(0x1) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_dis_faz_Pos) /* (ADC_CALCTRL) Disable auto-zeroing Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_dis_faz(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_dis_faz_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_dis_faz_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_dis_saz_Pos _UINT32_(4)                                          /* (ADC_CALCTRL) Disable auto-zeroing Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_dis_saz_Msk (_UINT32_(0x1) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_dis_saz_Pos) /* (ADC_CALCTRL) Disable auto-zeroing Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_dis_saz(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_dis_saz_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_dis_saz_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_dis_laz_Pos _UINT32_(5)                                          /* (ADC_CALCTRL) Disable auto-zeroing Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_dis_laz_Msk (_UINT32_(0x1) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_dis_laz_Pos) /* (ADC_CALCTRL) Disable auto-zeroing Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_dis_laz(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_dis_laz_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_dis_laz_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_en_rdac_Pos _UINT32_(6)                                          /* (ADC_CALCTRL) Disable Power Cycling Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_en_rdac_Msk (_UINT32_(0x1) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_en_rdac_Pos) /* (ADC_CALCTRL) Disable Power Cycling Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_en_rdac(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_en_rdac_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_en_rdac_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_dbg_sel_Pos _UINT32_(7)                                          /* (ADC_CALCTRL) Debug Bus Select Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_dbg_sel_Msk (_UINT32_(0x1) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_dbg_sel_Pos) /* (ADC_CALCTRL) Debug Bus Select Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_dbg_sel(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_dbg_sel_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_dbg_sel_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_sel_del_Pos _UINT32_(8)                                          /* (ADC_CALCTRL) Scan Mode comp_out Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_sel_del_Msk (_UINT32_(0x1) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_sel_del_Pos) /* (ADC_CALCTRL) Scan Mode comp_out Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_sel_del(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_sel_del_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_sel_del_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_t1_dly_Pos _UINT32_(9)                                          /* (ADC_CALCTRL) Regen Latch Delay Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_t1_dly_Msk (_UINT32_(0x3) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_t1_dly_Pos) /* (ADC_CALCTRL) Regen Latch Delay Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_t1_dly(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_t1_dly_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_t1_dly_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_tclk_div_Pos _UINT32_(11)                                         /* (ADC_CALCTRL) Test Clock Divider Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_tclk_div_Msk (_UINT32_(0x1F) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_tclk_div_Pos) /* (ADC_CALCTRL) Test Clock Divider Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_tclk_div(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_tclk_div_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_tclk_div_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_iadc_1_Pos _UINT32_(20)                                         /* (ADC_CALCTRL) Current Consumption 1 Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_iadc_1_Msk (_UINT32_(0x3) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_iadc_1_Pos) /* (ADC_CALCTRL) Current Consumption 1 Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_iadc_1(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_iadc_1_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_iadc_1_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_iadc_2_Pos _UINT32_(22)                                         /* (ADC_CALCTRL) Current Consumption 2 Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_iadc_2_Msk (_UINT32_(0x3) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_iadc_2_Pos) /* (ADC_CALCTRL) Current Consumption 2 Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_iadc_2(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_iadc_2_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_iadc_2_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_icmp_1_Pos _UINT32_(24)                                         /* (ADC_CALCTRL) Bias Current Stage 1 Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_icmp_1_Msk (_UINT32_(0x3) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_icmp_1_Pos) /* (ADC_CALCTRL) Bias Current Stage 1 Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_icmp_1(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_icmp_1_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_icmp_1_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_icmp_2_Pos _UINT32_(26)                                         /* (ADC_CALCTRL) Bias Current Stage 2 Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_icmp_2_Msk (_UINT32_(0x3) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_icmp_2_Pos) /* (ADC_CALCTRL) Bias Current Stage 2 Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_icmp_2(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_icmp_2_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_icmp_2_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_icmbf_Pos _UINT32_(28)                                         /* (ADC_CALCTRL) Bias Current Common Mode Buffer Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_icmbf_Msk (_UINT32_(0x3) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_icmbf_Pos) /* (ADC_CALCTRL) Bias Current Common Mode Buffer Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_icmbf(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_icmbf_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_icmbf_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_en_ext_bias_Pos _UINT32_(31)                                         /* (ADC_CALCTRL) Dsiable Internal Bias Circuit Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_en_ext_bias_Msk (_UINT32_(0x1) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_en_ext_bias_Pos) /* (ADC_CALCTRL) Dsiable Internal Bias Circuit Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_en_ext_bias(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_en_ext_bias_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_en_ext_bias_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0_Msk _UINT32_(0xBFF0FFFD)                                  /* (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7A0) Register Mask  */

/* FUSES_ADC_SARCORE_12BIT_V7C0 mode */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_en_cmbf_Pos _UINT32_(0)                                          /* (ADC_CALCTRL) Enable Common Mode Buffer Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_en_cmbf_Msk (_UINT32_(0x1) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_en_cmbf_Pos) /* (ADC_CALCTRL) Enable Common Mode Buffer Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_en_cmbf(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_en_cmbf_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_en_cmbf_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_en_dither_Pos _UINT32_(2)                                          /* (ADC_CALCTRL) Enable Dither Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_en_dither_Msk (_UINT32_(0x1) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_en_dither_Pos) /* (ADC_CALCTRL) Enable Dither Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_en_dither(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_en_dither_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_en_dither_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_dis_faz_Pos _UINT32_(3)                                          /* (ADC_CALCTRL) Disable auto-zeroing Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_dis_faz_Msk (_UINT32_(0x1) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_dis_faz_Pos) /* (ADC_CALCTRL) Disable auto-zeroing Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_dis_faz(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_dis_faz_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_dis_faz_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_dis_saz_Pos _UINT32_(4)                                          /* (ADC_CALCTRL) Disable auto-zeroing Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_dis_saz_Msk (_UINT32_(0x1) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_dis_saz_Pos) /* (ADC_CALCTRL) Disable auto-zeroing Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_dis_saz(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_dis_saz_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_dis_saz_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_dis_laz_Pos _UINT32_(5)                                          /* (ADC_CALCTRL) Disable auto-zeroing Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_dis_laz_Msk (_UINT32_(0x1) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_dis_laz_Pos) /* (ADC_CALCTRL) Disable auto-zeroing Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_dis_laz(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_dis_laz_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_dis_laz_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_en_rdac_Pos _UINT32_(6)                                          /* (ADC_CALCTRL) Disable Power Cycling Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_en_rdac_Msk (_UINT32_(0x1) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_en_rdac_Pos) /* (ADC_CALCTRL) Disable Power Cycling Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_en_rdac(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_en_rdac_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_en_rdac_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_dbg_sel_Pos _UINT32_(7)                                          /* (ADC_CALCTRL) Debug Bus Select Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_dbg_sel_Msk (_UINT32_(0x1) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_dbg_sel_Pos) /* (ADC_CALCTRL) Debug Bus Select Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_dbg_sel(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_dbg_sel_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_dbg_sel_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_sel_del_Pos _UINT32_(8)                                          /* (ADC_CALCTRL) Scan Mode comp_out Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_sel_del_Msk (_UINT32_(0x1) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_sel_del_Pos) /* (ADC_CALCTRL) Scan Mode comp_out Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_sel_del(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_sel_del_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_sel_del_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_t1_dly_Pos _UINT32_(9)                                          /* (ADC_CALCTRL) Regen Latch Delay Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_t1_dly_Msk (_UINT32_(0x3) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_t1_dly_Pos) /* (ADC_CALCTRL) Regen Latch Delay Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_t1_dly(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_t1_dly_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_t1_dly_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_tclk_div_Pos _UINT32_(11)                                         /* (ADC_CALCTRL) Test Clock Divider Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_tclk_div_Msk (_UINT32_(0x1F) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_tclk_div_Pos) /* (ADC_CALCTRL) Test Clock Divider Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_tclk_div(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_tclk_div_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_tclk_div_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_iadc_1_Pos _UINT32_(20)                                         /* (ADC_CALCTRL) Current Consumption 1 Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_iadc_1_Msk (_UINT32_(0x3) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_iadc_1_Pos) /* (ADC_CALCTRL) Current Consumption 1 Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_iadc_1(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_iadc_1_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_iadc_1_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_iadc_2_Pos _UINT32_(22)                                         /* (ADC_CALCTRL) Current Consumption 2 Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_iadc_2_Msk (_UINT32_(0x3) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_iadc_2_Pos) /* (ADC_CALCTRL) Current Consumption 2 Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_iadc_2(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_iadc_2_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_iadc_2_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_icmp_1_Pos _UINT32_(24)                                         /* (ADC_CALCTRL) Bias Current Stage 1 Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_icmp_1_Msk (_UINT32_(0x3) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_icmp_1_Pos) /* (ADC_CALCTRL) Bias Current Stage 1 Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_icmp_1(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_icmp_1_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_icmp_1_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_icmp_2_Pos _UINT32_(26)                                         /* (ADC_CALCTRL) Bias Current Stage 2 Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_icmp_2_Msk (_UINT32_(0x3) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_icmp_2_Pos) /* (ADC_CALCTRL) Bias Current Stage 2 Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_icmp_2(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_icmp_2_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_icmp_2_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_icmbf_Pos _UINT32_(28)                                         /* (ADC_CALCTRL) Bias Current Common Mode Buffer Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_icmbf_Msk (_UINT32_(0x3) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_icmbf_Pos) /* (ADC_CALCTRL) Bias Current Common Mode Buffer Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_icmbf(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_icmbf_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_icmbf_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_en_ext_bias_Pos _UINT32_(31)                                         /* (ADC_CALCTRL) Dsiable Internal Bias Circuit Position */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_en_ext_bias_Msk (_UINT32_(0x1) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_en_ext_bias_Pos) /* (ADC_CALCTRL) Dsiable Internal Bias Circuit Mask */
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_en_ext_bias(value) (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_en_ext_bias_Msk & (_UINT32_(value) << ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_en_ext_bias_Pos))
#define ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0_Msk _UINT32_(0xBFF0FFFD)                                  /* (ADC_CALCTRL_FUSES_ADC_SARCORE_12BIT_V7C0) Register Mask  */


/* -------- ADC_EVCTRL : (ADC Offset: 0x1C) (R/W 32) Event Control -------- */
#define ADC_EVCTRL_RESETVALUE                 _UINT32_(0x00)                                       /*  (ADC_EVCTRL) Event Control  Reset Value */

#define ADC_EVCTRL_STARTEI_Pos                _UINT32_(0)                                          /* (ADC_EVCTRL) Start Event conversion input enable Position */
#define ADC_EVCTRL_STARTEI_Msk                (_UINT32_(0x1) << ADC_EVCTRL_STARTEI_Pos)            /* (ADC_EVCTRL) Start Event conversion input enable Mask */
#define ADC_EVCTRL_STARTEI(value)             (ADC_EVCTRL_STARTEI_Msk & (_UINT32_(value) << ADC_EVCTRL_STARTEI_Pos)) /* Assigment of value for STARTEI in the ADC_EVCTRL register */
#define ADC_EVCTRL_STARTINV_Pos               _UINT32_(3)                                          /* (ADC_EVCTRL) Start Conversion Invert Position */
#define ADC_EVCTRL_STARTINV_Msk               (_UINT32_(0x1) << ADC_EVCTRL_STARTINV_Pos)           /* (ADC_EVCTRL) Start Conversion Invert Mask */
#define ADC_EVCTRL_STARTINV(value)            (ADC_EVCTRL_STARTINV_Msk & (_UINT32_(value) << ADC_EVCTRL_STARTINV_Pos)) /* Assigment of value for STARTINV in the ADC_EVCTRL register */
#define ADC_EVCTRL_RESRDYEO_Pos               _UINT32_(4)                                          /* (ADC_EVCTRL) Result Ready Event Out Position */
#define ADC_EVCTRL_RESRDYEO_Msk               (_UINT32_(0x1) << ADC_EVCTRL_RESRDYEO_Pos)           /* (ADC_EVCTRL) Result Ready Event Out Mask */
#define ADC_EVCTRL_RESRDYEO(value)            (ADC_EVCTRL_RESRDYEO_Msk & (_UINT32_(value) << ADC_EVCTRL_RESRDYEO_Pos)) /* Assigment of value for RESRDYEO in the ADC_EVCTRL register */
#define ADC_EVCTRL_Msk                        _UINT32_(0x00000019)                                 /* (ADC_EVCTRL) Register Mask  */


/* -------- ADC_INTENCLR : (ADC Offset: 0x00) (R/W 32) Interrupt Enable Clear -------- */
#define ADC_INTENCLR_RESETVALUE               _UINT32_(0x00)                                       /*  (ADC_INTENCLR) Interrupt Enable Clear  Reset Value */

#define ADC_INTENCLR_CMPHIT_Pos               _UINT32_(4)                                          /* (ADC_INTENCLR) Compare Hit Disable Position */
#define ADC_INTENCLR_CMPHIT_Msk               (_UINT32_(0x1) << ADC_INTENCLR_CMPHIT_Pos)           /* (ADC_INTENCLR) Compare Hit Disable Mask */
#define ADC_INTENCLR_CMPHIT(value)            (ADC_INTENCLR_CMPHIT_Msk & (_UINT32_(value) << ADC_INTENCLR_CMPHIT_Pos)) /* Assigment of value for CMPHIT in the ADC_INTENCLR register */
#define ADC_INTENCLR_SOVFL_Pos                _UINT32_(7)                                          /* (ADC_INTENCLR) Synchonizer Overflow Disable Position */
#define ADC_INTENCLR_SOVFL_Msk                (_UINT32_(0x1) << ADC_INTENCLR_SOVFL_Pos)            /* (ADC_INTENCLR) Synchonizer Overflow Disable Mask */
#define ADC_INTENCLR_SOVFL(value)             (ADC_INTENCLR_SOVFL_Msk & (_UINT32_(value) << ADC_INTENCLR_SOVFL_Pos)) /* Assigment of value for SOVFL in the ADC_INTENCLR register */
#define ADC_INTENCLR_CHRDYC_Pos               _UINT32_(8)                                          /* (ADC_INTENCLR) Core Current Channel Disable Position */
#define ADC_INTENCLR_CHRDYC_Msk               (_UINT32_(0x1) << ADC_INTENCLR_CHRDYC_Pos)           /* (ADC_INTENCLR) Core Current Channel Disable Mask */
#define ADC_INTENCLR_CHRDYC(value)            (ADC_INTENCLR_CHRDYC_Msk & (_UINT32_(value) << ADC_INTENCLR_CHRDYC_Pos)) /* Assigment of value for CHRDYC in the ADC_INTENCLR register */
#define ADC_INTENCLR_FLTRDY_Pos               _UINT32_(9)                                          /* (ADC_INTENCLR) Filter Ready Disable Position */
#define ADC_INTENCLR_FLTRDY_Msk               (_UINT32_(0x1) << ADC_INTENCLR_FLTRDY_Pos)           /* (ADC_INTENCLR) Filter Ready Disable Mask */
#define ADC_INTENCLR_FLTRDY(value)            (ADC_INTENCLR_FLTRDY_Msk & (_UINT32_(value) << ADC_INTENCLR_FLTRDY_Pos)) /* Assigment of value for FLTRDY in the ADC_INTENCLR register */
#define ADC_INTENCLR_CHNERRC_Pos              _UINT32_(10)                                         /* (ADC_INTENCLR) Channel Overwrite Error Disable Position */
#define ADC_INTENCLR_CHNERRC_Msk              (_UINT32_(0x1) << ADC_INTENCLR_CHNERRC_Pos)          /* (ADC_INTENCLR) Channel Overwrite Error Disable Mask */
#define ADC_INTENCLR_CHNERRC(value)           (ADC_INTENCLR_CHNERRC_Msk & (_UINT32_(value) << ADC_INTENCLR_CHNERRC_Pos)) /* Assigment of value for CHNERRC in the ADC_INTENCLR register */
#define ADC_INTENCLR_EOSRDY_Pos               _UINT32_(11)                                         /* (ADC_INTENCLR) Endo of Scan Disable Position */
#define ADC_INTENCLR_EOSRDY_Msk               (_UINT32_(0x1) << ADC_INTENCLR_EOSRDY_Pos)           /* (ADC_INTENCLR) Endo of Scan Disable Mask */
#define ADC_INTENCLR_EOSRDY(value)            (ADC_INTENCLR_EOSRDY_Msk & (_UINT32_(value) << ADC_INTENCLR_EOSRDY_Pos)) /* Assigment of value for EOSRDY in the ADC_INTENCLR register */
#define ADC_INTENCLR_CHRDY_Pos                _UINT32_(12)                                         /* (ADC_INTENCLR) Channel Ready Disable Position */
#define ADC_INTENCLR_CHRDY_Msk                (_UINT32_(0xFFFF) << ADC_INTENCLR_CHRDY_Pos)         /* (ADC_INTENCLR) Channel Ready Disable Mask */
#define ADC_INTENCLR_CHRDY(value)             (ADC_INTENCLR_CHRDY_Msk & (_UINT32_(value) << ADC_INTENCLR_CHRDY_Pos)) /* Assigment of value for CHRDY in the ADC_INTENCLR register */
#define ADC_INTENCLR_Msk                      _UINT32_(0x0FFFFF90)                                 /* (ADC_INTENCLR) Register Mask  */


/* -------- ADC_INTENSET : (ADC Offset: 0x04) (R/W 32) Interrupt Enable Set -------- */
#define ADC_INTENSET_RESETVALUE               _UINT32_(0x00)                                       /*  (ADC_INTENSET) Interrupt Enable Set  Reset Value */

#define ADC_INTENSET_CMPHIT_Pos               _UINT32_(4)                                          /* (ADC_INTENSET) Compare Hit Enable Position */
#define ADC_INTENSET_CMPHIT_Msk               (_UINT32_(0x1) << ADC_INTENSET_CMPHIT_Pos)           /* (ADC_INTENSET) Compare Hit Enable Mask */
#define ADC_INTENSET_CMPHIT(value)            (ADC_INTENSET_CMPHIT_Msk & (_UINT32_(value) << ADC_INTENSET_CMPHIT_Pos)) /* Assigment of value for CMPHIT in the ADC_INTENSET register */
#define ADC_INTENSET_SOVFL_Pos                _UINT32_(7)                                          /* (ADC_INTENSET) Synchronizer Overflow Enable Position */
#define ADC_INTENSET_SOVFL_Msk                (_UINT32_(0x1) << ADC_INTENSET_SOVFL_Pos)            /* (ADC_INTENSET) Synchronizer Overflow Enable Mask */
#define ADC_INTENSET_SOVFL(value)             (ADC_INTENSET_SOVFL_Msk & (_UINT32_(value) << ADC_INTENSET_SOVFL_Pos)) /* Assigment of value for SOVFL in the ADC_INTENSET register */
#define ADC_INTENSET_CHRDYC_Pos               _UINT32_(8)                                          /* (ADC_INTENSET) Current Channel Ready Enable Position */
#define ADC_INTENSET_CHRDYC_Msk               (_UINT32_(0x1) << ADC_INTENSET_CHRDYC_Pos)           /* (ADC_INTENSET) Current Channel Ready Enable Mask */
#define ADC_INTENSET_CHRDYC(value)            (ADC_INTENSET_CHRDYC_Msk & (_UINT32_(value) << ADC_INTENSET_CHRDYC_Pos)) /* Assigment of value for CHRDYC in the ADC_INTENSET register */
#define ADC_INTENSET_FLTRDY_Pos               _UINT32_(9)                                          /* (ADC_INTENSET) Filter Ready Enable Position */
#define ADC_INTENSET_FLTRDY_Msk               (_UINT32_(0x1) << ADC_INTENSET_FLTRDY_Pos)           /* (ADC_INTENSET) Filter Ready Enable Mask */
#define ADC_INTENSET_FLTRDY(value)            (ADC_INTENSET_FLTRDY_Msk & (_UINT32_(value) << ADC_INTENSET_FLTRDY_Pos)) /* Assigment of value for FLTRDY in the ADC_INTENSET register */
#define ADC_INTENSET_CHNERRC_Pos              _UINT32_(10)                                         /* (ADC_INTENSET) Channel Overwrite Enable Position */
#define ADC_INTENSET_CHNERRC_Msk              (_UINT32_(0x1) << ADC_INTENSET_CHNERRC_Pos)          /* (ADC_INTENSET) Channel Overwrite Enable Mask */
#define ADC_INTENSET_CHNERRC(value)           (ADC_INTENSET_CHNERRC_Msk & (_UINT32_(value) << ADC_INTENSET_CHNERRC_Pos)) /* Assigment of value for CHNERRC in the ADC_INTENSET register */
#define ADC_INTENSET_EOSRDY_Pos               _UINT32_(11)                                         /* (ADC_INTENSET) End of Scan Enable Position */
#define ADC_INTENSET_EOSRDY_Msk               (_UINT32_(0x1) << ADC_INTENSET_EOSRDY_Pos)           /* (ADC_INTENSET) End of Scan Enable Mask */
#define ADC_INTENSET_EOSRDY(value)            (ADC_INTENSET_EOSRDY_Msk & (_UINT32_(value) << ADC_INTENSET_EOSRDY_Pos)) /* Assigment of value for EOSRDY in the ADC_INTENSET register */
#define ADC_INTENSET_CHRDY_Pos                _UINT32_(16)                                         /* (ADC_INTENSET) Channel Ready Enable Position */
#define ADC_INTENSET_CHRDY_Msk                (_UINT32_(0xFFFF) << ADC_INTENSET_CHRDY_Pos)         /* (ADC_INTENSET) Channel Ready Enable Mask */
#define ADC_INTENSET_CHRDY(value)             (ADC_INTENSET_CHRDY_Msk & (_UINT32_(value) << ADC_INTENSET_CHRDY_Pos)) /* Assigment of value for CHRDY in the ADC_INTENSET register */
#define ADC_INTENSET_Msk                      _UINT32_(0xFFFF0F90)                                 /* (ADC_INTENSET) Register Mask  */


/* -------- ADC_INTFLAG : (ADC Offset: 0x08) (R/W 32) Interrupt Flags -------- */
#define ADC_INTFLAG_RESETVALUE                _UINT32_(0x00)                                       /*  (ADC_INTFLAG) Interrupt Flags  Reset Value */

#define ADC_INTFLAG_CMPINTID_Pos              _UINT32_(0)                                          /* (ADC_INTFLAG) Compare Channel ID Position */
#define ADC_INTFLAG_CMPINTID_Msk              (_UINT32_(0xF) << ADC_INTFLAG_CMPINTID_Pos)          /* (ADC_INTFLAG) Compare Channel ID Mask */
#define ADC_INTFLAG_CMPINTID(value)           (ADC_INTFLAG_CMPINTID_Msk & (_UINT32_(value) << ADC_INTFLAG_CMPINTID_Pos)) /* Assigment of value for CMPINTID in the ADC_INTFLAG register */
#define ADC_INTFLAG_CMPHIT_Pos                _UINT32_(4)                                          /* (ADC_INTFLAG) Compare Hit Position */
#define ADC_INTFLAG_CMPHIT_Msk                (_UINT32_(0x1) << ADC_INTFLAG_CMPHIT_Pos)            /* (ADC_INTFLAG) Compare Hit Mask */
#define ADC_INTFLAG_CMPHIT(value)             (ADC_INTFLAG_CMPHIT_Msk & (_UINT32_(value) << ADC_INTFLAG_CMPHIT_Pos)) /* Assigment of value for CMPHIT in the ADC_INTFLAG register */
#define ADC_INTFLAG_SOVFL_Pos                 _UINT32_(7)                                          /* (ADC_INTFLAG) Synchronizer Overflow Position */
#define ADC_INTFLAG_SOVFL_Msk                 (_UINT32_(0x1) << ADC_INTFLAG_SOVFL_Pos)             /* (ADC_INTFLAG) Synchronizer Overflow Mask */
#define ADC_INTFLAG_SOVFL(value)              (ADC_INTFLAG_SOVFL_Msk & (_UINT32_(value) << ADC_INTFLAG_SOVFL_Pos)) /* Assigment of value for SOVFL in the ADC_INTFLAG register */
#define ADC_INTFLAG_CHRDYC_Pos                _UINT32_(8)                                          /* (ADC_INTFLAG) Current Channel Ready Position */
#define ADC_INTFLAG_CHRDYC_Msk                (_UINT32_(0x1) << ADC_INTFLAG_CHRDYC_Pos)            /* (ADC_INTFLAG) Current Channel Ready Mask */
#define ADC_INTFLAG_CHRDYC(value)             (ADC_INTFLAG_CHRDYC_Msk & (_UINT32_(value) << ADC_INTFLAG_CHRDYC_Pos)) /* Assigment of value for CHRDYC in the ADC_INTFLAG register */
#define ADC_INTFLAG_FLTRDY_Pos                _UINT32_(9)                                          /* (ADC_INTFLAG) Filter Ready Position */
#define ADC_INTFLAG_FLTRDY_Msk                (_UINT32_(0x1) << ADC_INTFLAG_FLTRDY_Pos)            /* (ADC_INTFLAG) Filter Ready Mask */
#define ADC_INTFLAG_FLTRDY(value)             (ADC_INTFLAG_FLTRDY_Msk & (_UINT32_(value) << ADC_INTFLAG_FLTRDY_Pos)) /* Assigment of value for FLTRDY in the ADC_INTFLAG register */
#define ADC_INTFLAG_CHNERRC_Pos               _UINT32_(10)                                         /* (ADC_INTFLAG) Channel Overwrite Error Position */
#define ADC_INTFLAG_CHNERRC_Msk               (_UINT32_(0x1) << ADC_INTFLAG_CHNERRC_Pos)           /* (ADC_INTFLAG) Channel Overwrite Error Mask */
#define ADC_INTFLAG_CHNERRC(value)            (ADC_INTFLAG_CHNERRC_Msk & (_UINT32_(value) << ADC_INTFLAG_CHNERRC_Pos)) /* Assigment of value for CHNERRC in the ADC_INTFLAG register */
#define ADC_INTFLAG_EOSRDY_Pos                _UINT32_(11)                                         /* (ADC_INTFLAG) End of Scan Ready Position */
#define ADC_INTFLAG_EOSRDY_Msk                (_UINT32_(0x1) << ADC_INTFLAG_EOSRDY_Pos)            /* (ADC_INTFLAG) End of Scan Ready Mask */
#define ADC_INTFLAG_EOSRDY(value)             (ADC_INTFLAG_EOSRDY_Msk & (_UINT32_(value) << ADC_INTFLAG_EOSRDY_Pos)) /* Assigment of value for EOSRDY in the ADC_INTFLAG register */
#define ADC_INTFLAG_CRDYID_Pos                _UINT32_(12)                                         /* (ADC_INTFLAG) Channel Ready ID Position */
#define ADC_INTFLAG_CRDYID_Msk                (_UINT32_(0xF) << ADC_INTFLAG_CRDYID_Pos)            /* (ADC_INTFLAG) Channel Ready ID Mask */
#define ADC_INTFLAG_CRDYID(value)             (ADC_INTFLAG_CRDYID_Msk & (_UINT32_(value) << ADC_INTFLAG_CRDYID_Pos)) /* Assigment of value for CRDYID in the ADC_INTFLAG register */
#define ADC_INTFLAG_CHRDY_Pos                 _UINT32_(16)                                         /* (ADC_INTFLAG) Channel Ready Position */
#define ADC_INTFLAG_CHRDY_Msk                 (_UINT32_(0xFFFF) << ADC_INTFLAG_CHRDY_Pos)          /* (ADC_INTFLAG) Channel Ready Mask */
#define ADC_INTFLAG_CHRDY(value)              (ADC_INTFLAG_CHRDY_Msk & (_UINT32_(value) << ADC_INTFLAG_CHRDY_Pos)) /* Assigment of value for CHRDY in the ADC_INTFLAG register */
#define ADC_INTFLAG_Msk                       _UINT32_(0xFFFFFF9F)                                 /* (ADC_INTFLAG) Register Mask  */


/* -------- ADC_CTRLA : (ADC Offset: 0x00) (R/W 32) CONTROL A REGISTER -------- */
#define ADC_CTRLA_RESETVALUE                  _UINT32_(0x80)                                       /*  (ADC_CTRLA) CONTROL A REGISTER  Reset Value */

#define ADC_CTRLA_SWRST_Pos                   _UINT32_(0)                                          /* (ADC_CTRLA) SOFTWARE RESET BIT Position */
#define ADC_CTRLA_SWRST_Msk                   (_UINT32_(0x1) << ADC_CTRLA_SWRST_Pos)               /* (ADC_CTRLA) SOFTWARE RESET BIT Mask */
#define ADC_CTRLA_SWRST(value)                (ADC_CTRLA_SWRST_Msk & (_UINT32_(value) << ADC_CTRLA_SWRST_Pos)) /* Assigment of value for SWRST in the ADC_CTRLA register */
#define ADC_CTRLA_ENABLE_Pos                  _UINT32_(1)                                          /* (ADC_CTRLA) ENABLE BIT Position */
#define ADC_CTRLA_ENABLE_Msk                  (_UINT32_(0x1) << ADC_CTRLA_ENABLE_Pos)              /* (ADC_CTRLA) ENABLE BIT Mask */
#define ADC_CTRLA_ENABLE(value)               (ADC_CTRLA_ENABLE_Msk & (_UINT32_(value) << ADC_CTRLA_ENABLE_Pos)) /* Assigment of value for ENABLE in the ADC_CTRLA register */
#define ADC_CTRLA_ANAEN_Pos                   _UINT32_(2)                                          /* (ADC_CTRLA) Analog Enable Position */
#define ADC_CTRLA_ANAEN_Msk                   (_UINT32_(0x1) << ADC_CTRLA_ANAEN_Pos)               /* (ADC_CTRLA) Analog Enable Mask */
#define ADC_CTRLA_ANAEN(value)                (ADC_CTRLA_ANAEN_Msk & (_UINT32_(value) << ADC_CTRLA_ANAEN_Pos)) /* Assigment of value for ANAEN in the ADC_CTRLA register */
#define ADC_CTRLA_AIPMPEN_Pos                 _UINT32_(4)                                          /* (ADC_CTRLA) Charge Pump Enable Position */
#define ADC_CTRLA_AIPMPEN_Msk                 (_UINT32_(0x1) << ADC_CTRLA_AIPMPEN_Pos)             /* (ADC_CTRLA) Charge Pump Enable Mask */
#define ADC_CTRLA_AIPMPEN(value)              (ADC_CTRLA_AIPMPEN_Msk & (_UINT32_(value) << ADC_CTRLA_AIPMPEN_Pos)) /* Assigment of value for AIPMPEN in the ADC_CTRLA register */
#define ADC_CTRLA_RUNSTDBY_Pos                _UINT32_(6)                                          /* (ADC_CTRLA) Run in Standby Position */
#define ADC_CTRLA_RUNSTDBY_Msk                (_UINT32_(0x1) << ADC_CTRLA_RUNSTDBY_Pos)            /* (ADC_CTRLA) Run in Standby Mask */
#define ADC_CTRLA_RUNSTDBY(value)             (ADC_CTRLA_RUNSTDBY_Msk & (_UINT32_(value) << ADC_CTRLA_RUNSTDBY_Pos)) /* Assigment of value for RUNSTDBY in the ADC_CTRLA register */
#define ADC_CTRLA_ONDEMAND_Pos                _UINT32_(7)                                          /* (ADC_CTRLA) On Demand Control Position */
#define ADC_CTRLA_ONDEMAND_Msk                (_UINT32_(0x1) << ADC_CTRLA_ONDEMAND_Pos)            /* (ADC_CTRLA) On Demand Control Mask */
#define ADC_CTRLA_ONDEMAND(value)             (ADC_CTRLA_ONDEMAND_Msk & (_UINT32_(value) << ADC_CTRLA_ONDEMAND_Pos)) /* Assigment of value for ONDEMAND in the ADC_CTRLA register */
#define ADC_CTRLA_Msk                         _UINT32_(0x000000D7)                                 /* (ADC_CTRLA) Register Mask  */


/* -------- ADC_CTRLB : (ADC Offset: 0x04) (R/W 32) CONTROL B REGISTER -------- */
#define ADC_CTRLB_RESETVALUE                  _UINT32_(0x00)                                       /*  (ADC_CTRLB) CONTROL B REGISTER  Reset Value */

#define ADC_CTRLB_ADCHSEL_Pos                 _UINT32_(0)                                          /* (ADC_CTRLB) Software Trigger Channel Select Position */
#define ADC_CTRLB_ADCHSEL_Msk                 (_UINT32_(0xF) << ADC_CTRLB_ADCHSEL_Pos)             /* (ADC_CTRLB) Software Trigger Channel Select Mask */
#define ADC_CTRLB_ADCHSEL(value)              (ADC_CTRLB_ADCHSEL_Msk & (_UINT32_(value) << ADC_CTRLB_ADCHSEL_Pos)) /* Assigment of value for ADCHSEL in the ADC_CTRLB register */
#define ADC_CTRLB_ADCORSEL_Pos                _UINT32_(4)                                          /* (ADC_CTRLB) Software Trigger Core Select Position */
#define ADC_CTRLB_ADCORSEL_Msk                (_UINT32_(0x3) << ADC_CTRLB_ADCORSEL_Pos)            /* (ADC_CTRLB) Software Trigger Core Select Mask */
#define ADC_CTRLB_ADCORSEL(value)             (ADC_CTRLB_ADCORSEL_Msk & (_UINT32_(value) << ADC_CTRLB_ADCORSEL_Pos)) /* Assigment of value for ADCORSEL in the ADC_CTRLB register */
#define ADC_CTRLB_RQCNVRT_Pos                 _UINT32_(6)                                          /* (ADC_CTRLB) Request Channel Convert Position */
#define ADC_CTRLB_RQCNVRT_Msk                 (_UINT32_(0x1) << ADC_CTRLB_RQCNVRT_Pos)             /* (ADC_CTRLB) Request Channel Convert Mask */
#define ADC_CTRLB_RQCNVRT(value)              (ADC_CTRLB_RQCNVRT_Msk & (_UINT32_(value) << ADC_CTRLB_RQCNVRT_Pos)) /* Assigment of value for RQCNVRT in the ADC_CTRLB register */
#define ADC_CTRLB_SAMP_Pos                    _UINT32_(7)                                          /* (ADC_CTRLB) Channel Sample Position */
#define ADC_CTRLB_SAMP_Msk                    (_UINT32_(0x1) << ADC_CTRLB_SAMP_Pos)                /* (ADC_CTRLB) Channel Sample Mask */
#define ADC_CTRLB_SAMP(value)                 (ADC_CTRLB_SAMP_Msk & (_UINT32_(value) << ADC_CTRLB_SAMP_Pos)) /* Assigment of value for SAMP in the ADC_CTRLB register */
#define ADC_CTRLB_GSWTRG_Pos                  _UINT32_(8)                                          /* (ADC_CTRLB) Global Software Trigger Position */
#define ADC_CTRLB_GSWTRG_Msk                  (_UINT32_(0x1) << ADC_CTRLB_GSWTRG_Pos)              /* (ADC_CTRLB) Global Software Trigger Mask */
#define ADC_CTRLB_GSWTRG(value)               (ADC_CTRLB_GSWTRG_Msk & (_UINT32_(value) << ADC_CTRLB_GSWTRG_Pos)) /* Assigment of value for GSWTRG in the ADC_CTRLB register */
#define ADC_CTRLB_LSWTRG_Pos                  _UINT32_(9)                                          /* (ADC_CTRLB) Level Global Trigger Position */
#define ADC_CTRLB_LSWTRG_Msk                  (_UINT32_(0x1) << ADC_CTRLB_LSWTRG_Pos)              /* (ADC_CTRLB) Level Global Trigger Mask */
#define ADC_CTRLB_LSWTRG(value)               (ADC_CTRLB_LSWTRG_Msk & (_UINT32_(value) << ADC_CTRLB_LSWTRG_Pos)) /* Assigment of value for LSWTRG in the ADC_CTRLB register */
#define ADC_CTRLB_TRGSUSP_Pos                 _UINT32_(10)                                         /* (ADC_CTRLB) Trigger Suspend Position */
#define ADC_CTRLB_TRGSUSP_Msk                 (_UINT32_(0x1) << ADC_CTRLB_TRGSUSP_Pos)             /* (ADC_CTRLB) Trigger Suspend Mask */
#define ADC_CTRLB_TRGSUSP(value)              (ADC_CTRLB_TRGSUSP_Msk & (_UINT32_(value) << ADC_CTRLB_TRGSUSP_Pos)) /* Assigment of value for TRGSUSP in the ADC_CTRLB register */
#define ADC_CTRLB_SWCNVEN_Pos                 _UINT32_(15)                                         /* (ADC_CTRLB) Software Conversion Enable Position */
#define ADC_CTRLB_SWCNVEN_Msk                 (_UINT32_(0x1) << ADC_CTRLB_SWCNVEN_Pos)             /* (ADC_CTRLB) Software Conversion Enable Mask */
#define ADC_CTRLB_SWCNVEN(value)              (ADC_CTRLB_SWCNVEN_Msk & (_UINT32_(value) << ADC_CTRLB_SWCNVEN_Pos)) /* Assigment of value for SWCNVEN in the ADC_CTRLB register */
#define ADC_CTRLB_Msk                         _UINT32_(0x000087FF)                                 /* (ADC_CTRLB) Register Mask  */


/* -------- ADC_CTRLC : (ADC Offset: 0x08) (R/W 32) Control C Register -------- */
#define ADC_CTRLC_RESETVALUE                  _UINT32_(0x00)                                       /*  (ADC_CTRLC) Control C Register  Reset Value */

#define ADC_CTRLC_CNT_Pos                     _UINT32_(0)                                          /* (ADC_CTRLC) Clock Divider for Synchronous Trigger Position */
#define ADC_CTRLC_CNT_Msk                     (_UINT32_(0xFFFF) << ADC_CTRLC_CNT_Pos)              /* (ADC_CTRLC) Clock Divider for Synchronous Trigger Mask */
#define ADC_CTRLC_CNT(value)                  (ADC_CTRLC_CNT_Msk & (_UINT32_(value) << ADC_CTRLC_CNT_Pos)) /* Assigment of value for CNT in the ADC_CTRLC register */
#define ADC_CTRLC_COREINTERLEAVED_Pos         _UINT32_(28)                                         /* (ADC_CTRLC) Number of Core to Interleave Triggers Position */
#define ADC_CTRLC_COREINTERLEAVED_Msk         (_UINT32_(0x3) << ADC_CTRLC_COREINTERLEAVED_Pos)     /* (ADC_CTRLC) Number of Core to Interleave Triggers Mask */
#define ADC_CTRLC_COREINTERLEAVED(value)      (ADC_CTRLC_COREINTERLEAVED_Msk & (_UINT32_(value) << ADC_CTRLC_COREINTERLEAVED_Pos)) /* Assigment of value for COREINTERLEAVED in the ADC_CTRLC register */
#define   ADC_CTRLC_COREINTERLEAVED_INTERLEAVING_OFF_Val _UINT32_(0x0)                                        /* (ADC_CTRLC) Interleaving Off  */
#define   ADC_CTRLC_COREINTERLEAVED_INTERLEAVING_CORES_0_1_Val _UINT32_(0x4)                                        /* (ADC_CTRLC) Interleaving Cores 0 and 1  */
#define   ADC_CTRLC_COREINTERLEAVED_INTERLEAVING_CORES_1_2_Val _UINT32_(0x1)                                        /* (ADC_CTRLC) Interleaving Cores 1 and 2  */
#define   ADC_CTRLC_COREINTERLEAVED_INTERLEAVING_CORES_0_1_2_Val _UINT32_(0x5)                                        /* (ADC_CTRLC) Interleaving Cores 0, 1 and 2  */
#define   ADC_CTRLC_COREINTERLEAVED_INTERLEAVING_CORES_1_2_3_Val _UINT32_(0x2)                                        /* (ADC_CTRLC) Interleaving Cores 1, 2 and 3  */
#define   ADC_CTRLC_COREINTERLEAVED_INTERLEAVING_CORES_0_1_2_3_Val _UINT32_(0x3)                                        /* (ADC_CTRLC) Interleaving Cores 0, 1, 2 and 3  */
#define ADC_CTRLC_COREINTERLEAVED_INTERLEAVING_OFF (ADC_CTRLC_COREINTERLEAVED_INTERLEAVING_OFF_Val << ADC_CTRLC_COREINTERLEAVED_Pos) /* (ADC_CTRLC) Interleaving Off Position  */
#define ADC_CTRLC_COREINTERLEAVED_INTERLEAVING_CORES_0_1 (ADC_CTRLC_COREINTERLEAVED_INTERLEAVING_CORES_0_1_Val << ADC_CTRLC_COREINTERLEAVED_Pos) /* (ADC_CTRLC) Interleaving Cores 0 and 1 Position  */
#define ADC_CTRLC_COREINTERLEAVED_INTERLEAVING_CORES_1_2 (ADC_CTRLC_COREINTERLEAVED_INTERLEAVING_CORES_1_2_Val << ADC_CTRLC_COREINTERLEAVED_Pos) /* (ADC_CTRLC) Interleaving Cores 1 and 2 Position  */
#define ADC_CTRLC_COREINTERLEAVED_INTERLEAVING_CORES_0_1_2 (ADC_CTRLC_COREINTERLEAVED_INTERLEAVING_CORES_0_1_2_Val << ADC_CTRLC_COREINTERLEAVED_Pos) /* (ADC_CTRLC) Interleaving Cores 0, 1 and 2 Position  */
#define ADC_CTRLC_COREINTERLEAVED_INTERLEAVING_CORES_1_2_3 (ADC_CTRLC_COREINTERLEAVED_INTERLEAVING_CORES_1_2_3_Val << ADC_CTRLC_COREINTERLEAVED_Pos) /* (ADC_CTRLC) Interleaving Cores 1, 2 and 3 Position  */
#define ADC_CTRLC_COREINTERLEAVED_INTERLEAVING_CORES_0_1_2_3 (ADC_CTRLC_COREINTERLEAVED_INTERLEAVING_CORES_0_1_2_3_Val << ADC_CTRLC_COREINTERLEAVED_Pos) /* (ADC_CTRLC) Interleaving Cores 0, 1, 2 and 3 Position  */
#define ADC_CTRLC_Msk                         _UINT32_(0x3000FFFF)                                 /* (ADC_CTRLC) Register Mask  */


/* -------- ADC_CTRLD : (ADC Offset: 0x10) (R/W 32) Control D Register -------- */
#define ADC_CTRLD_RESETVALUE                  _UINT32_(0x00)                                       /*  (ADC_CTRLD) Control D Register  Reset Value */

#define ADC_CTRLD_CTLCKDIV_Pos                _UINT32_(8)                                          /* (ADC_CTRLD) Control Clock Divider Position */
#define ADC_CTRLD_CTLCKDIV_Msk                (_UINT32_(0x3F) << ADC_CTRLD_CTLCKDIV_Pos)           /* (ADC_CTRLD) Control Clock Divider Mask */
#define ADC_CTRLD_CTLCKDIV(value)             (ADC_CTRLD_CTLCKDIV_Msk & (_UINT32_(value) << ADC_CTRLD_CTLCKDIV_Pos)) /* Assigment of value for CTLCKDIV in the ADC_CTRLD register */
#define ADC_CTRLD_CHNEN_Pos                   _UINT32_(16)                                         /* (ADC_CTRLD) Digital Channel Enable Position */
#define ADC_CTRLD_CHNEN_Msk                   (_UINT32_(0xF) << ADC_CTRLD_CHNEN_Pos)               /* (ADC_CTRLD) Digital Channel Enable Mask */
#define ADC_CTRLD_CHNEN(value)                (ADC_CTRLD_CHNEN_Msk & (_UINT32_(value) << ADC_CTRLD_CHNEN_Pos)) /* Assigment of value for CHNEN in the ADC_CTRLD register */
#define ADC_CTRLD_ANLEN_Pos                   _UINT32_(20)                                         /* (ADC_CTRLD) Analog Channel Enable Position */
#define ADC_CTRLD_ANLEN_Msk                   (_UINT32_(0xF) << ADC_CTRLD_ANLEN_Pos)               /* (ADC_CTRLD) Analog Channel Enable Mask */
#define ADC_CTRLD_ANLEN(value)                (ADC_CTRLD_ANLEN_Msk & (_UINT32_(value) << ADC_CTRLD_ANLEN_Pos)) /* Assigment of value for ANLEN in the ADC_CTRLD register */
#define ADC_CTRLD_WKUPEXP_Pos                 _UINT32_(24)                                         /* (ADC_CTRLD) Wakeup cycles Position */
#define ADC_CTRLD_WKUPEXP_Msk                 (_UINT32_(0xF) << ADC_CTRLD_WKUPEXP_Pos)             /* (ADC_CTRLD) Wakeup cycles Mask */
#define ADC_CTRLD_WKUPEXP(value)              (ADC_CTRLD_WKUPEXP_Msk & (_UINT32_(value) << ADC_CTRLD_WKUPEXP_Pos)) /* Assigment of value for WKUPEXP in the ADC_CTRLD register */
#define ADC_CTRLD_VREFSEL_Pos                 _UINT32_(28)                                         /* (ADC_CTRLD) Voltage Reference Select Position */
#define ADC_CTRLD_VREFSEL_Msk                 (_UINT32_(0x7) << ADC_CTRLD_VREFSEL_Pos)             /* (ADC_CTRLD) Voltage Reference Select Mask */
#define ADC_CTRLD_VREFSEL(value)              (ADC_CTRLD_VREFSEL_Msk & (_UINT32_(value) << ADC_CTRLD_VREFSEL_Pos)) /* Assigment of value for VREFSEL in the ADC_CTRLD register */
#define   ADC_CTRLD_VREFSEL_AVDD_AVSS_Val     _UINT32_(0x0)                                        /* (ADC_CTRLD) AVDD and AVSS  */
#define   ADC_CTRLD_VREFSEL_EXTERNAL_VREFH_AVSS_Val _UINT32_(0x1)                                        /* (ADC_CTRLD) External VREFH and AVSS  */
#define ADC_CTRLD_VREFSEL_AVDD_AVSS           (ADC_CTRLD_VREFSEL_AVDD_AVSS_Val << ADC_CTRLD_VREFSEL_Pos) /* (ADC_CTRLD) AVDD and AVSS Position  */
#define ADC_CTRLD_VREFSEL_EXTERNAL_VREFH_AVSS (ADC_CTRLD_VREFSEL_EXTERNAL_VREFH_AVSS_Val << ADC_CTRLD_VREFSEL_Pos) /* (ADC_CTRLD) External VREFH and AVSS Position  */
#define ADC_CTRLD_Msk                         _UINT32_(0x7FFF3F00)                                 /* (ADC_CTRLD) Register Mask  */


/* -------- ADC_CMPCTRL : (ADC Offset: 0xB0) (R/W 32) Comparator Control -------- */
#define ADC_CMPCTRL_RESETVALUE                _UINT32_(0x00)                                       /*  (ADC_CMPCTRL) Comparator Control  Reset Value */

#define ADC_CMPCTRL_ADCMPLO_Pos               _UINT32_(0)                                          /* (ADC_CMPCTRL) Low Limit of Digital Comparator Position */
#define ADC_CMPCTRL_ADCMPLO_Msk               (_UINT32_(0xFFF) << ADC_CMPCTRL_ADCMPLO_Pos)         /* (ADC_CMPCTRL) Low Limit of Digital Comparator Mask */
#define ADC_CMPCTRL_ADCMPLO(value)            (ADC_CMPCTRL_ADCMPLO_Msk & (_UINT32_(value) << ADC_CMPCTRL_ADCMPLO_Pos)) /* Assigment of value for ADCMPLO in the ADC_CMPCTRL register */
#define ADC_CMPCTRL_CMPEN_Pos                 _UINT32_(12)                                         /* (ADC_CMPCTRL) Comparator Enable Position */
#define ADC_CMPCTRL_CMPEN_Msk                 (_UINT32_(0x1) << ADC_CMPCTRL_CMPEN_Pos)             /* (ADC_CMPCTRL) Comparator Enable Mask */
#define ADC_CMPCTRL_CMPEN(value)              (ADC_CMPCTRL_CMPEN_Msk & (_UINT32_(value) << ADC_CMPCTRL_CMPEN_Pos)) /* Assigment of value for CMPEN in the ADC_CMPCTRL register */
#define ADC_CMPCTRL_IELOLO_Pos                _UINT32_(13)                                         /* (ADC_CMPCTRL) Enable VAL < CMPLO Position */
#define ADC_CMPCTRL_IELOLO_Msk                (_UINT32_(0x1) << ADC_CMPCTRL_IELOLO_Pos)            /* (ADC_CMPCTRL) Enable VAL < CMPLO Mask */
#define ADC_CMPCTRL_IELOLO(value)             (ADC_CMPCTRL_IELOLO_Msk & (_UINT32_(value) << ADC_CMPCTRL_IELOLO_Pos)) /* Assigment of value for IELOLO in the ADC_CMPCTRL register */
#define ADC_CMPCTRL_IELOHI_Pos                _UINT32_(14)                                         /* (ADC_CMPCTRL) Enable VAL >= CMPLO Position */
#define ADC_CMPCTRL_IELOHI_Msk                (_UINT32_(0x1) << ADC_CMPCTRL_IELOHI_Pos)            /* (ADC_CMPCTRL) Enable VAL >= CMPLO Mask */
#define ADC_CMPCTRL_IELOHI(value)             (ADC_CMPCTRL_IELOHI_Msk & (_UINT32_(value) << ADC_CMPCTRL_IELOHI_Pos)) /* Assigment of value for IELOHI in the ADC_CMPCTRL register */
#define ADC_CMPCTRL_IEBTWN_Pos                _UINT32_(15)                                         /* (ADC_CMPCTRL) Enable CMPLO <= VAL < CMPHI Position */
#define ADC_CMPCTRL_IEBTWN_Msk                (_UINT32_(0x1) << ADC_CMPCTRL_IEBTWN_Pos)            /* (ADC_CMPCTRL) Enable CMPLO <= VAL < CMPHI Mask */
#define ADC_CMPCTRL_IEBTWN(value)             (ADC_CMPCTRL_IEBTWN_Msk & (_UINT32_(value) << ADC_CMPCTRL_IEBTWN_Pos)) /* Assigment of value for IEBTWN in the ADC_CMPCTRL register */
#define ADC_CMPCTRL_ADCMPHI_Pos               _UINT32_(16)                                         /* (ADC_CMPCTRL) High Limit of Digital Comparator Position */
#define ADC_CMPCTRL_ADCMPHI_Msk               (_UINT32_(0xFFF) << ADC_CMPCTRL_ADCMPHI_Pos)         /* (ADC_CMPCTRL) High Limit of Digital Comparator Mask */
#define ADC_CMPCTRL_ADCMPHI(value)            (ADC_CMPCTRL_ADCMPHI_Msk & (_UINT32_(value) << ADC_CMPCTRL_ADCMPHI_Pos)) /* Assigment of value for ADCMPHI in the ADC_CMPCTRL register */
#define ADC_CMPCTRL_IEHILO_Pos                _UINT32_(28)                                         /* (ADC_CMPCTRL) Enable VAL < CMPHI Position */
#define ADC_CMPCTRL_IEHILO_Msk                (_UINT32_(0x1) << ADC_CMPCTRL_IEHILO_Pos)            /* (ADC_CMPCTRL) Enable VAL < CMPHI Mask */
#define ADC_CMPCTRL_IEHILO(value)             (ADC_CMPCTRL_IEHILO_Msk & (_UINT32_(value) << ADC_CMPCTRL_IEHILO_Pos)) /* Assigment of value for IEHILO in the ADC_CMPCTRL register */
#define ADC_CMPCTRL_IEHIHI_Pos                _UINT32_(29)                                         /* (ADC_CMPCTRL) Enable VAL >= CMPHI Position */
#define ADC_CMPCTRL_IEHIHI_Msk                (_UINT32_(0x1) << ADC_CMPCTRL_IEHIHI_Pos)            /* (ADC_CMPCTRL) Enable VAL >= CMPHI Mask */
#define ADC_CMPCTRL_IEHIHI(value)             (ADC_CMPCTRL_IEHIHI_Msk & (_UINT32_(value) << ADC_CMPCTRL_IEHIHI_Pos)) /* Assigment of value for IEHIHI in the ADC_CMPCTRL register */
#define ADC_CMPCTRL_Msk                       _UINT32_(0x3FFFFFFF)                                 /* (ADC_CMPCTRL) Register Mask  */


/* -------- ADC_FLTCTRL : (ADC Offset: 0xC0) (R/W 32) Filter Control -------- */
#define ADC_FLTCTRL_RESETVALUE                _UINT32_(0x00)                                       /*  (ADC_FLTCTRL) Filter Control  Reset Value */

#define ADC_FLTCTRL_OVRSAM_Pos                _UINT32_(0)                                          /* (ADC_FLTCTRL) Oversampling Ratio Position */
#define ADC_FLTCTRL_OVRSAM_Msk                (_UINT32_(0x7) << ADC_FLTCTRL_OVRSAM_Pos)            /* (ADC_FLTCTRL) Oversampling Ratio Mask */
#define ADC_FLTCTRL_OVRSAM(value)             (ADC_FLTCTRL_OVRSAM_Msk & (_UINT32_(value) << ADC_FLTCTRL_OVRSAM_Pos)) /* Assigment of value for OVRSAM in the ADC_FLTCTRL register */
#define   ADC_FLTCTRL_OVRSAM_4_SAMPLES_Val    _UINT32_(0x0)                                        /* (ADC_FLTCTRL) (If FMODE is 0) 4 samples (shift sum 1 bit to right, output data is 13-bits) / (If FMODE is 1) 2 samples to be averaged  */
#define   ADC_FLTCTRL_OVRSAM_16_SAMPLES_Val   _UINT32_(0x1)                                        /* (ADC_FLTCTRL) (If FMODE is 0) 16 samples (shift sum 2 bits to right, output data is 14-bits) / (If FMODE is 1) 4 samples to be averaged  */
#define   ADC_FLTCTRL_OVRSAM_64_SAMPLES_Val   _UINT32_(0x2)                                        /* (ADC_FLTCTRL) (If FMODE is 0) 64 samples (shift sum 3 bits to right, output data is 15-bits) / (If FMODE is 1) 8 samples to be averaged  */
#define   ADC_FLTCTRL_OVRSAM_256_SAMPLES_Val  _UINT32_(0x3)                                        /* (ADC_FLTCTRL) (If FMODE is 0) 256 samples (shift sum 4 bits to right, output data is 16-bits) / (If FMODE is 1) 16 samples to be averaged  */
#define   ADC_FLTCTRL_OVRSAM_2_SAMPLES_Val    _UINT32_(0x4)                                        /* (ADC_FLTCTRL) (If FMODE is 0) 2 samples (shift sum 0 bits to right, output data is 12.1 format) / (If FMODE is 1) 32 samples to be averaged  */
#define   ADC_FLTCTRL_OVRSAM_8_SAMPLES_Val    _UINT32_(0x5)                                        /* (ADC_FLTCTRL) (If FMODE is 0) 8 samples (shift sum 1 bit to right, output data is 13.1 format) / (If FMODE is 1) 64 samples to be averaged  */
#define   ADC_FLTCTRL_OVRSAM_32_SAMPLES_Val   _UINT32_(0x6)                                        /* (ADC_FLTCTRL) (If FMODE is 0) 32 samples (shift sum 2 bits to right, output data is 14.1 format) / (If FMODE is 1) 128 samples to be averaged  */
#define   ADC_FLTCTRL_OVRSAM_128_SAMPLES_Val  _UINT32_(0x7)                                        /* (ADC_FLTCTRL) (If FMODE is 0) 128 samples (shift sum 3 bits to right, output data is 15.1 format) / (If FMODE is 1) 256 samples to be averaged  */
#define ADC_FLTCTRL_OVRSAM_4_SAMPLES          (ADC_FLTCTRL_OVRSAM_4_SAMPLES_Val << ADC_FLTCTRL_OVRSAM_Pos) /* (ADC_FLTCTRL) (If FMODE is 0) 4 samples (shift sum 1 bit to right, output data is 13-bits) / (If FMODE is 1) 2 samples to be averaged Position  */
#define ADC_FLTCTRL_OVRSAM_16_SAMPLES         (ADC_FLTCTRL_OVRSAM_16_SAMPLES_Val << ADC_FLTCTRL_OVRSAM_Pos) /* (ADC_FLTCTRL) (If FMODE is 0) 16 samples (shift sum 2 bits to right, output data is 14-bits) / (If FMODE is 1) 4 samples to be averaged Position  */
#define ADC_FLTCTRL_OVRSAM_64_SAMPLES         (ADC_FLTCTRL_OVRSAM_64_SAMPLES_Val << ADC_FLTCTRL_OVRSAM_Pos) /* (ADC_FLTCTRL) (If FMODE is 0) 64 samples (shift sum 3 bits to right, output data is 15-bits) / (If FMODE is 1) 8 samples to be averaged Position  */
#define ADC_FLTCTRL_OVRSAM_256_SAMPLES        (ADC_FLTCTRL_OVRSAM_256_SAMPLES_Val << ADC_FLTCTRL_OVRSAM_Pos) /* (ADC_FLTCTRL) (If FMODE is 0) 256 samples (shift sum 4 bits to right, output data is 16-bits) / (If FMODE is 1) 16 samples to be averaged Position  */
#define ADC_FLTCTRL_OVRSAM_2_SAMPLES          (ADC_FLTCTRL_OVRSAM_2_SAMPLES_Val << ADC_FLTCTRL_OVRSAM_Pos) /* (ADC_FLTCTRL) (If FMODE is 0) 2 samples (shift sum 0 bits to right, output data is 12.1 format) / (If FMODE is 1) 32 samples to be averaged Position  */
#define ADC_FLTCTRL_OVRSAM_8_SAMPLES          (ADC_FLTCTRL_OVRSAM_8_SAMPLES_Val << ADC_FLTCTRL_OVRSAM_Pos) /* (ADC_FLTCTRL) (If FMODE is 0) 8 samples (shift sum 1 bit to right, output data is 13.1 format) / (If FMODE is 1) 64 samples to be averaged Position  */
#define ADC_FLTCTRL_OVRSAM_32_SAMPLES         (ADC_FLTCTRL_OVRSAM_32_SAMPLES_Val << ADC_FLTCTRL_OVRSAM_Pos) /* (ADC_FLTCTRL) (If FMODE is 0) 32 samples (shift sum 2 bits to right, output data is 14.1 format) / (If FMODE is 1) 128 samples to be averaged Position  */
#define ADC_FLTCTRL_OVRSAM_128_SAMPLES        (ADC_FLTCTRL_OVRSAM_128_SAMPLES_Val << ADC_FLTCTRL_OVRSAM_Pos) /* (ADC_FLTCTRL) (If FMODE is 0) 128 samples (shift sum 3 bits to right, output data is 15.1 format) / (If FMODE is 1) 256 samples to be averaged Position  */
#define ADC_FLTCTRL_FMODE_Pos                 _UINT32_(3)                                          /* (ADC_FLTCTRL) Filter Mode Position */
#define ADC_FLTCTRL_FMODE_Msk                 (_UINT32_(0x1) << ADC_FLTCTRL_FMODE_Pos)             /* (ADC_FLTCTRL) Filter Mode Mask */
#define ADC_FLTCTRL_FMODE(value)              (ADC_FLTCTRL_FMODE_Msk & (_UINT32_(value) << ADC_FLTCTRL_FMODE_Pos)) /* Assigment of value for FMODE in the ADC_FLTCTRL register */
#define ADC_FLTCTRL_DATA16EN_Pos              _UINT32_(4)                                          /* (ADC_FLTCTRL) 16bit Averaging Mode Position */
#define ADC_FLTCTRL_DATA16EN_Msk              (_UINT32_(0x1) << ADC_FLTCTRL_DATA16EN_Pos)          /* (ADC_FLTCTRL) 16bit Averaging Mode Mask */
#define ADC_FLTCTRL_DATA16EN(value)           (ADC_FLTCTRL_DATA16EN_Msk & (_UINT32_(value) << ADC_FLTCTRL_DATA16EN_Pos)) /* Assigment of value for DATA16EN in the ADC_FLTCTRL register */
#define ADC_FLTCTRL_FLTEN_Pos                 _UINT32_(8)                                          /* (ADC_FLTCTRL) Filter Enable Position */
#define ADC_FLTCTRL_FLTEN_Msk                 (_UINT32_(0x1) << ADC_FLTCTRL_FLTEN_Pos)             /* (ADC_FLTCTRL) Filter Enable Mask */
#define ADC_FLTCTRL_FLTEN(value)              (ADC_FLTCTRL_FLTEN_Msk & (_UINT32_(value) << ADC_FLTCTRL_FLTEN_Pos)) /* Assigment of value for FLTEN in the ADC_FLTCTRL register */
#define ADC_FLTCTRL_FLTCHNID_Pos              _UINT32_(10)                                         /* (ADC_FLTCTRL) Channel ID Position */
#define ADC_FLTCTRL_FLTCHNID_Msk              (_UINT32_(0xF) << ADC_FLTCTRL_FLTCHNID_Pos)          /* (ADC_FLTCTRL) Channel ID Mask */
#define ADC_FLTCTRL_FLTCHNID(value)           (ADC_FLTCTRL_FLTCHNID_Msk & (_UINT32_(value) << ADC_FLTCTRL_FLTCHNID_Pos)) /* Assigment of value for FLTCHNID in the ADC_FLTCTRL register */
#define ADC_FLTCTRL_Msk                       _UINT32_(0x00003D1F)                                 /* (ADC_FLTCTRL) Register Mask  */


/* -------- ADC_CORCHDATAID : (ADC Offset: 0xD0) (R/W 32) Channel Ready DATA ID -------- */
#define ADC_CORCHDATAID_RESETVALUE            _UINT32_(0x00)                                       /*  (ADC_CORCHDATAID) Channel Ready DATA ID  Reset Value */

#define ADC_CORCHDATAID_CHRDYID_Pos           _UINT32_(0)                                          /* (ADC_CORCHDATAID) Channel Read ID Position */
#define ADC_CORCHDATAID_CHRDYID_Msk           (_UINT32_(0xF) << ADC_CORCHDATAID_CHRDYID_Pos)       /* (ADC_CORCHDATAID) Channel Read ID Mask */
#define ADC_CORCHDATAID_CHRDYID(value)        (ADC_CORCHDATAID_CHRDYID_Msk & (_UINT32_(value) << ADC_CORCHDATAID_CHRDYID_Pos)) /* Assigment of value for CHRDYID in the ADC_CORCHDATAID register */
#define ADC_CORCHDATAID_CORDYID_Pos           _UINT32_(4)                                          /* (ADC_CORCHDATAID) Core Read ID Position */
#define ADC_CORCHDATAID_CORDYID_Msk           (_UINT32_(0x3) << ADC_CORCHDATAID_CORDYID_Pos)       /* (ADC_CORCHDATAID) Core Read ID Mask */
#define ADC_CORCHDATAID_CORDYID(value)        (ADC_CORCHDATAID_CORDYID_Msk & (_UINT32_(value) << ADC_CORCHDATAID_CORDYID_Pos)) /* Assigment of value for CORDYID in the ADC_CORCHDATAID register */
#define ADC_CORCHDATAID_Msk                   _UINT32_(0x0000003F)                                 /* (ADC_CORCHDATAID) Register Mask  */


/* -------- ADC_CHRDYDAT : (ADC Offset: 0xD4) (R/W 32) Channel Ready Data Register -------- */
#define ADC_CHRDYDAT_RESETVALUE               _UINT32_(0x00)                                       /*  (ADC_CHRDYDAT) Channel Ready Data Register  Reset Value */

#define ADC_CHRDYDAT_CHRDYDAT_Pos             _UINT32_(0)                                          /* (ADC_CHRDYDAT) Channel Output Data Position */
#define ADC_CHRDYDAT_CHRDYDAT_Msk             (_UINT32_(0xFFFF) << ADC_CHRDYDAT_CHRDYDAT_Pos)      /* (ADC_CHRDYDAT) Channel Output Data Mask */
#define ADC_CHRDYDAT_CHRDYDAT(value)          (ADC_CHRDYDAT_CHRDYDAT_Msk & (_UINT32_(value) << ADC_CHRDYDAT_CHRDYDAT_Pos)) /* Assigment of value for CHRDYDAT in the ADC_CHRDYDAT register */
#define ADC_CHRDYDAT_LVL_Pos                  _UINT32_(24)                                         /* (ADC_CHRDYDAT) Level Setting Position */
#define ADC_CHRDYDAT_LVL_Msk                  (_UINT32_(0x1) << ADC_CHRDYDAT_LVL_Pos)              /* (ADC_CHRDYDAT) Level Setting Mask */
#define ADC_CHRDYDAT_LVL(value)               (ADC_CHRDYDAT_LVL_Msk & (_UINT32_(value) << ADC_CHRDYDAT_LVL_Pos)) /* Assigment of value for LVL in the ADC_CHRDYDAT register */
#define ADC_CHRDYDAT_DIFF_Pos                 _UINT32_(25)                                         /* (ADC_CHRDYDAT) Differential Setting Position */
#define ADC_CHRDYDAT_DIFF_Msk                 (_UINT32_(0x1) << ADC_CHRDYDAT_DIFF_Pos)             /* (ADC_CHRDYDAT) Differential Setting Mask */
#define ADC_CHRDYDAT_DIFF(value)              (ADC_CHRDYDAT_DIFF_Msk & (_UINT32_(value) << ADC_CHRDYDAT_DIFF_Pos)) /* Assigment of value for DIFF in the ADC_CHRDYDAT register */
#define ADC_CHRDYDAT_SIGN_Pos                 _UINT32_(26)                                         /* (ADC_CHRDYDAT) Sign Setting Position */
#define ADC_CHRDYDAT_SIGN_Msk                 (_UINT32_(0x1) << ADC_CHRDYDAT_SIGN_Pos)             /* (ADC_CHRDYDAT) Sign Setting Mask */
#define ADC_CHRDYDAT_SIGN(value)              (ADC_CHRDYDAT_SIGN_Msk & (_UINT32_(value) << ADC_CHRDYDAT_SIGN_Pos)) /* Assigment of value for SIGN in the ADC_CHRDYDAT register */
#define ADC_CHRDYDAT_FRACT_Pos                _UINT32_(27)                                         /* (ADC_CHRDYDAT) Fractional Setting Position */
#define ADC_CHRDYDAT_FRACT_Msk                (_UINT32_(0x1) << ADC_CHRDYDAT_FRACT_Pos)            /* (ADC_CHRDYDAT) Fractional Setting Mask */
#define ADC_CHRDYDAT_FRACT(value)             (ADC_CHRDYDAT_FRACT_Msk & (_UINT32_(value) << ADC_CHRDYDAT_FRACT_Pos)) /* Assigment of value for FRACT in the ADC_CHRDYDAT register */
#define ADC_CHRDYDAT_Msk                      _UINT32_(0x0F00FFFF)                                 /* (ADC_CHRDYDAT) Register Mask  */


/* -------- ADC_PFFDATA : (ADC Offset: 0xD8) ( R/ 32) APB FIFO Output Data -------- */
#define ADC_PFFDATA_RESETVALUE                _UINT32_(0x00)                                       /*  (ADC_PFFDATA) APB FIFO Output Data  Reset Value */

#define ADC_PFFDATA_PFFDATA_Pos               _UINT32_(0)                                          /* (ADC_PFFDATA) SARCORE Conversion data from the APB FIFO Position */
#define ADC_PFFDATA_PFFDATA_Msk               (_UINT32_(0xFFFF) << ADC_PFFDATA_PFFDATA_Pos)        /* (ADC_PFFDATA) SARCORE Conversion data from the APB FIFO Mask */
#define ADC_PFFDATA_PFFDATA(value)            (ADC_PFFDATA_PFFDATA_Msk & (_UINT32_(value) << ADC_PFFDATA_PFFDATA_Pos)) /* Assigment of value for PFFDATA in the ADC_PFFDATA register */
#define ADC_PFFDATA_PFFCHNID_Pos              _UINT32_(16)                                         /* (ADC_PFFDATA) Channel ID from APB FIFO Position */
#define ADC_PFFDATA_PFFCHNID_Msk              (_UINT32_(0xF) << ADC_PFFDATA_PFFCHNID_Pos)          /* (ADC_PFFDATA) Channel ID from APB FIFO Mask */
#define ADC_PFFDATA_PFFCHNID(value)           (ADC_PFFDATA_PFFCHNID_Msk & (_UINT32_(value) << ADC_PFFDATA_PFFCHNID_Pos)) /* Assigment of value for PFFCHNID in the ADC_PFFDATA register */
#define ADC_PFFDATA_PFFCORID_Pos              _UINT32_(20)                                         /* (ADC_PFFDATA) Core ID from APB FIFO Position */
#define ADC_PFFDATA_PFFCORID_Msk              (_UINT32_(0x3) << ADC_PFFDATA_PFFCORID_Pos)          /* (ADC_PFFDATA) Core ID from APB FIFO Mask */
#define ADC_PFFDATA_PFFCORID(value)           (ADC_PFFDATA_PFFCORID_Msk & (_UINT32_(value) << ADC_PFFDATA_PFFCORID_Pos)) /* Assigment of value for PFFCORID in the ADC_PFFDATA register */
#define ADC_PFFDATA_PFFSIGN_Pos               _UINT32_(22)                                         /* (ADC_PFFDATA) Channel Sign from the APB FIFO Position */
#define ADC_PFFDATA_PFFSIGN_Msk               (_UINT32_(0x1) << ADC_PFFDATA_PFFSIGN_Pos)           /* (ADC_PFFDATA) Channel Sign from the APB FIFO Mask */
#define ADC_PFFDATA_PFFSIGN(value)            (ADC_PFFDATA_PFFSIGN_Msk & (_UINT32_(value) << ADC_PFFDATA_PFFSIGN_Pos)) /* Assigment of value for PFFSIGN in the ADC_PFFDATA register */
#define ADC_PFFDATA_PFFFRACT_Pos              _UINT32_(23)                                         /* (ADC_PFFDATA) Fractional Setting from APB FIFO Position */
#define ADC_PFFDATA_PFFFRACT_Msk              (_UINT32_(0x1) << ADC_PFFDATA_PFFFRACT_Pos)          /* (ADC_PFFDATA) Fractional Setting from APB FIFO Mask */
#define ADC_PFFDATA_PFFFRACT(value)           (ADC_PFFDATA_PFFFRACT_Msk & (_UINT32_(value) << ADC_PFFDATA_PFFFRACT_Pos)) /* Assigment of value for PFFFRACT in the ADC_PFFDATA register */
#define ADC_PFFDATA_PFFCNT_Pos                _UINT32_(24)                                         /* (ADC_PFFDATA) Current Data Entries in APB FIFO Position */
#define ADC_PFFDATA_PFFCNT_Msk                (_UINT32_(0xFF) << ADC_PFFDATA_PFFCNT_Pos)           /* (ADC_PFFDATA) Current Data Entries in APB FIFO Mask */
#define ADC_PFFDATA_PFFCNT(value)             (ADC_PFFDATA_PFFCNT_Msk & (_UINT32_(value) << ADC_PFFDATA_PFFCNT_Pos)) /* Assigment of value for PFFCNT in the ADC_PFFDATA register */
#define ADC_PFFDATA_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (ADC_PFFDATA) Register Mask  */


/* -------- ADC_DMABASE : (ADC Offset: 0xDC) (R/W 32) DMA Sample Base Address -------- */
#define ADC_DMABASE_RESETVALUE                _UINT32_(0x00)                                       /*  (ADC_DMABASE) DMA Sample Base Address  Reset Value */

#define ADC_DMABASE_DMABASE_Pos               _UINT32_(0)                                          /* (ADC_DMABASE) DMA Sample Value Base Address Position */
#define ADC_DMABASE_DMABASE_Msk               (_UINT32_(0xFFFFFFFF) << ADC_DMABASE_DMABASE_Pos)    /* (ADC_DMABASE) DMA Sample Value Base Address Mask */
#define ADC_DMABASE_DMABASE(value)            (ADC_DMABASE_DMABASE_Msk & (_UINT32_(value) << ADC_DMABASE_DMABASE_Pos)) /* Assigment of value for DMABASE in the ADC_DMABASE register */
#define ADC_DMABASE_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (ADC_DMABASE) Register Mask  */


/* -------- ADC_DMACTRL : (ADC Offset: 0xE0) (R/W 32) DMA Control Register -------- */
#define ADC_DMACTRL_RESETVALUE                _UINT32_(0x00)                                       /*  (ADC_DMACTRL) DMA Control Register  Reset Value */

#define ADC_DMACTRL_DMAEN_Pos                 _UINT32_(1)                                          /* (ADC_DMACTRL) DMA Enable Position */
#define ADC_DMACTRL_DMAEN_Msk                 (_UINT32_(0x1) << ADC_DMACTRL_DMAEN_Pos)             /* (ADC_DMACTRL) DMA Enable Mask */
#define ADC_DMACTRL_DMAEN(value)              (ADC_DMACTRL_DMAEN_Msk & (_UINT32_(value) << ADC_DMACTRL_DMAEN_Pos)) /* Assigment of value for DMAEN in the ADC_DMACTRL register */
#define ADC_DMACTRL_DMACR_Pos                 _UINT32_(4)                                          /* (ADC_DMACTRL) DMA CORE Enables Position */
#define ADC_DMACTRL_DMACR_Msk                 (_UINT32_(0xF) << ADC_DMACTRL_DMACR_Pos)             /* (ADC_DMACTRL) DMA CORE Enables Mask */
#define ADC_DMACTRL_DMACR(value)              (ADC_DMACTRL_DMACR_Msk & (_UINT32_(value) << ADC_DMACTRL_DMACR_Pos)) /* Assigment of value for DMACR in the ADC_DMACTRL register */
#define ADC_DMACTRL_DMABL_Pos                 _UINT32_(8)                                          /* (ADC_DMACTRL) DMA System RAM Buffer Length Position */
#define ADC_DMACTRL_DMABL_Msk                 (_UINT32_(0x7) << ADC_DMACTRL_DMABL_Pos)             /* (ADC_DMACTRL) DMA System RAM Buffer Length Mask */
#define ADC_DMACTRL_DMABL(value)              (ADC_DMACTRL_DMABL_Msk & (_UINT32_(value) << ADC_DMACTRL_DMABL_Pos)) /* Assigment of value for DMABL in the ADC_DMACTRL register */
#define ADC_DMACTRL_Msk                       _UINT32_(0x000007F2)                                 /* (ADC_DMACTRL) Register Mask  */


/* -------- ADC_PFFCTRL : (ADC Offset: 0xE4) (R/W 32) APB FIFO Control Register -------- */
#define ADC_PFFCTRL_RESETVALUE                _UINT32_(0x00)                                       /*  (ADC_PFFCTRL) APB FIFO Control Register  Reset Value */

#define ADC_PFFCTRL_PFFEN_Pos                 _UINT32_(1)                                          /* (ADC_PFFCTRL) APB FIFO Enable Position */
#define ADC_PFFCTRL_PFFEN_Msk                 (_UINT32_(0x1) << ADC_PFFCTRL_PFFEN_Pos)             /* (ADC_PFFCTRL) APB FIFO Enable Mask */
#define ADC_PFFCTRL_PFFEN(value)              (ADC_PFFCTRL_PFFEN_Msk & (_UINT32_(value) << ADC_PFFCTRL_PFFEN_Pos)) /* Assigment of value for PFFEN in the ADC_PFFCTRL register */
#define ADC_PFFCTRL_PFFCR_Pos                 _UINT32_(4)                                          /* (ADC_PFFCTRL) APB CORE FIFO Enable Position */
#define ADC_PFFCTRL_PFFCR_Msk                 (_UINT32_(0xF) << ADC_PFFCTRL_PFFCR_Pos)             /* (ADC_PFFCTRL) APB CORE FIFO Enable Mask */
#define ADC_PFFCTRL_PFFCR(value)              (ADC_PFFCTRL_PFFCR_Msk & (_UINT32_(value) << ADC_PFFCTRL_PFFCR_Pos)) /* Assigment of value for PFFCR in the ADC_PFFCTRL register */
#define ADC_PFFCTRL_PFFRDYDM_Pos              _UINT32_(16)                                         /* (ADC_PFFCTRL) DMA APB FIFO Data Ready Position */
#define ADC_PFFCTRL_PFFRDYDM_Msk              (_UINT32_(0x1) << ADC_PFFCTRL_PFFRDYDM_Pos)          /* (ADC_PFFCTRL) DMA APB FIFO Data Ready Mask */
#define ADC_PFFCTRL_PFFRDYDM(value)           (ADC_PFFCTRL_PFFRDYDM_Msk & (_UINT32_(value) << ADC_PFFCTRL_PFFRDYDM_Pos)) /* Assigment of value for PFFRDYDM in the ADC_PFFCTRL register */
#define   ADC_PFFCTRL_PFFRDYDM_CTLINTFLAG_PFFHFUL_Val _UINT32_(0x0)                                        /* (ADC_PFFCTRL) Selects CTLINTFLAG.PFFHFUL for the ADC DMA PFFRDY trigger signal to the DMAC  */
#define   ADC_PFFCTRL_PFFRDYDM_CTLINTFLAG_PFFRDY_Val _UINT32_(0x1)                                        /* (ADC_PFFCTRL) Selects CTLINTFLAG.PFFRDY for the ADC DMA PFFRDY trigger signal to the DMAC  */
#define ADC_PFFCTRL_PFFRDYDM_CTLINTFLAG_PFFHFUL (ADC_PFFCTRL_PFFRDYDM_CTLINTFLAG_PFFHFUL_Val << ADC_PFFCTRL_PFFRDYDM_Pos) /* (ADC_PFFCTRL) Selects CTLINTFLAG.PFFHFUL for the ADC DMA PFFRDY trigger signal to the DMAC Position  */
#define ADC_PFFCTRL_PFFRDYDM_CTLINTFLAG_PFFRDY (ADC_PFFCTRL_PFFRDYDM_CTLINTFLAG_PFFRDY_Val << ADC_PFFCTRL_PFFRDYDM_Pos) /* (ADC_PFFCTRL) Selects CTLINTFLAG.PFFRDY for the ADC DMA PFFRDY trigger signal to the DMAC Position  */
#define ADC_PFFCTRL_Msk                       _UINT32_(0x000100F2)                                 /* (ADC_PFFCTRL) Register Mask  */


/* -------- ADC_SYNCBUSY : (ADC Offset: 0xE8) ( R/ 32) CORE SYNC Busy Status Register -------- */
#define ADC_SYNCBUSY_RESETVALUE               _UINT32_(0x00)                                       /*  (ADC_SYNCBUSY) CORE SYNC Busy Status Register  Reset Value */

#define ADC_SYNCBUSY_ENABLE_Pos               _UINT32_(0)                                          /* (ADC_SYNCBUSY) Enable bit Sync Busy Position */
#define ADC_SYNCBUSY_ENABLE_Msk               (_UINT32_(0x1) << ADC_SYNCBUSY_ENABLE_Pos)           /* (ADC_SYNCBUSY) Enable bit Sync Busy Mask */
#define ADC_SYNCBUSY_ENABLE(value)            (ADC_SYNCBUSY_ENABLE_Msk & (_UINT32_(value) << ADC_SYNCBUSY_ENABLE_Pos)) /* Assigment of value for ENABLE in the ADC_SYNCBUSY register */
#define ADC_SYNCBUSY_CTRLB_Pos                _UINT32_(2)                                          /* (ADC_SYNCBUSY) CTRLB sync busy Position */
#define ADC_SYNCBUSY_CTRLB_Msk                (_UINT32_(0x1) << ADC_SYNCBUSY_CTRLB_Pos)            /* (ADC_SYNCBUSY) CTRLB sync busy Mask */
#define ADC_SYNCBUSY_CTRLB(value)             (ADC_SYNCBUSY_CTRLB_Msk & (_UINT32_(value) << ADC_SYNCBUSY_CTRLB_Pos)) /* Assigment of value for CTRLB in the ADC_SYNCBUSY register */
#define ADC_SYNCBUSY_SWRST_Pos                _UINT32_(24)                                         /* (ADC_SYNCBUSY) Software Reset Sync Busy Position */
#define ADC_SYNCBUSY_SWRST_Msk                (_UINT32_(0x1) << ADC_SYNCBUSY_SWRST_Pos)            /* (ADC_SYNCBUSY) Software Reset Sync Busy Mask */
#define ADC_SYNCBUSY_SWRST(value)             (ADC_SYNCBUSY_SWRST_Msk & (_UINT32_(value) << ADC_SYNCBUSY_SWRST_Pos)) /* Assigment of value for SWRST in the ADC_SYNCBUSY register */
#define ADC_SYNCBUSY_Msk                      _UINT32_(0x01000005)                                 /* (ADC_SYNCBUSY) Register Mask  */


/* -------- ADC_TESTREG : (ADC Offset: 0xEC) (R/W 32) Test Control Register -------- */
#define ADC_TESTREG_RESETVALUE                _UINT32_(0x00)                                       /*  (ADC_TESTREG) Test Control Register  Reset Value */

#define ADC_TESTREG_TESTEN_Pos                _UINT32_(0)                                          /* (ADC_TESTREG) Test Mode Enable Position */
#define ADC_TESTREG_TESTEN_Msk                (_UINT32_(0x1) << ADC_TESTREG_TESTEN_Pos)            /* (ADC_TESTREG) Test Mode Enable Mask */
#define ADC_TESTREG_TESTEN(value)             (ADC_TESTREG_TESTEN_Msk & (_UINT32_(value) << ADC_TESTREG_TESTEN_Pos)) /* Assigment of value for TESTEN in the ADC_TESTREG register */
#define ADC_TESTREG_EN_ATEST_Pos              _UINT32_(16)                                         /* (ADC_TESTREG) Analog Test Circuitry Enables Position */
#define ADC_TESTREG_EN_ATEST_Msk              (_UINT32_(0xF) << ADC_TESTREG_EN_ATEST_Pos)          /* (ADC_TESTREG) Analog Test Circuitry Enables Mask */
#define ADC_TESTREG_EN_ATEST(value)           (ADC_TESTREG_EN_ATEST_Msk & (_UINT32_(value) << ADC_TESTREG_EN_ATEST_Pos)) /* Assigment of value for EN_ATEST in the ADC_TESTREG register */
#define ADC_TESTREG_ADCHSEL_Pos               _UINT32_(24)                                         /* (ADC_TESTREG) Channel Select Position */
#define ADC_TESTREG_ADCHSEL_Msk               (_UINT32_(0xF) << ADC_TESTREG_ADCHSEL_Pos)           /* (ADC_TESTREG) Channel Select Mask */
#define ADC_TESTREG_ADCHSEL(value)            (ADC_TESTREG_ADCHSEL_Msk & (_UINT32_(value) << ADC_TESTREG_ADCHSEL_Pos)) /* Assigment of value for ADCHSEL in the ADC_TESTREG register */
#define ADC_TESTREG_ADCORSEL_Pos              _UINT32_(28)                                         /* (ADC_TESTREG) Core Select Position */
#define ADC_TESTREG_ADCORSEL_Msk              (_UINT32_(0x3) << ADC_TESTREG_ADCORSEL_Pos)          /* (ADC_TESTREG) Core Select Mask */
#define ADC_TESTREG_ADCORSEL(value)           (ADC_TESTREG_ADCORSEL_Msk & (_UINT32_(value) << ADC_TESTREG_ADCORSEL_Pos)) /* Assigment of value for ADCORSEL in the ADC_TESTREG register */
#define ADC_TESTREG_Msk                       _UINT32_(0x3F0F0001)                                 /* (ADC_TESTREG) Register Mask  */


/* -------- ADC_DMAINTENCLR : (ADC Offset: 0xF0) (R/W 32) DMA Interrupt Enable Clear -------- */
#define ADC_DMAINTENCLR_RESETVALUE            _UINT32_(0x00)                                       /*  (ADC_DMAINTENCLR) DMA Interrupt Enable Clear  Reset Value */

#define ADC_DMAINTENCLR_RAF_Pos               _UINT32_(0)                                          /* (ADC_DMAINTENCLR) Ram Buffer A Full Position */
#define ADC_DMAINTENCLR_RAF_Msk               (_UINT32_(0xF) << ADC_DMAINTENCLR_RAF_Pos)           /* (ADC_DMAINTENCLR) Ram Buffer A Full Mask */
#define ADC_DMAINTENCLR_RAF(value)            (ADC_DMAINTENCLR_RAF_Msk & (_UINT32_(value) << ADC_DMAINTENCLR_RAF_Pos)) /* Assigment of value for RAF in the ADC_DMAINTENCLR register */
#define ADC_DMAINTENCLR_RBF_Pos               _UINT32_(4)                                          /* (ADC_DMAINTENCLR) Ram Buffer B Full Position */
#define ADC_DMAINTENCLR_RBF_Msk               (_UINT32_(0xF) << ADC_DMAINTENCLR_RBF_Pos)           /* (ADC_DMAINTENCLR) Ram Buffer B Full Mask */
#define ADC_DMAINTENCLR_RBF(value)            (ADC_DMAINTENCLR_RBF_Msk & (_UINT32_(value) << ADC_DMAINTENCLR_RBF_Pos)) /* Assigment of value for RBF in the ADC_DMAINTENCLR register */
#define ADC_DMAINTENCLR_SOVFL_Pos             _UINT32_(16)                                         /* (ADC_DMAINTENCLR) Synchonizer Overflow Position */
#define ADC_DMAINTENCLR_SOVFL_Msk             (_UINT32_(0x1) << ADC_DMAINTENCLR_SOVFL_Pos)         /* (ADC_DMAINTENCLR) Synchonizer Overflow Mask */
#define ADC_DMAINTENCLR_SOVFL(value)          (ADC_DMAINTENCLR_SOVFL_Msk & (_UINT32_(value) << ADC_DMAINTENCLR_SOVFL_Pos)) /* Assigment of value for SOVFL in the ADC_DMAINTENCLR register */
#define ADC_DMAINTENCLR_Msk                   _UINT32_(0x000100FF)                                 /* (ADC_DMAINTENCLR) Register Mask  */


/* -------- ADC_DMAINTSET : (ADC Offset: 0xF4) (R/W 32) DMA Interrupt Enable Set -------- */
#define ADC_DMAINTSET_RESETVALUE              _UINT32_(0x00)                                       /*  (ADC_DMAINTSET) DMA Interrupt Enable Set  Reset Value */

#define ADC_DMAINTSET_RAF_Pos                 _UINT32_(0)                                          /* (ADC_DMAINTSET) Ram Buffer A Full Position */
#define ADC_DMAINTSET_RAF_Msk                 (_UINT32_(0xF) << ADC_DMAINTSET_RAF_Pos)             /* (ADC_DMAINTSET) Ram Buffer A Full Mask */
#define ADC_DMAINTSET_RAF(value)              (ADC_DMAINTSET_RAF_Msk & (_UINT32_(value) << ADC_DMAINTSET_RAF_Pos)) /* Assigment of value for RAF in the ADC_DMAINTSET register */
#define ADC_DMAINTSET_RBF_Pos                 _UINT32_(4)                                          /* (ADC_DMAINTSET) Ram Buffer B Full Position */
#define ADC_DMAINTSET_RBF_Msk                 (_UINT32_(0xF) << ADC_DMAINTSET_RBF_Pos)             /* (ADC_DMAINTSET) Ram Buffer B Full Mask */
#define ADC_DMAINTSET_RBF(value)              (ADC_DMAINTSET_RBF_Msk & (_UINT32_(value) << ADC_DMAINTSET_RBF_Pos)) /* Assigment of value for RBF in the ADC_DMAINTSET register */
#define ADC_DMAINTSET_SOVFL_Pos               _UINT32_(16)                                         /* (ADC_DMAINTSET) Synchonizer Overflow Position */
#define ADC_DMAINTSET_SOVFL_Msk               (_UINT32_(0x1) << ADC_DMAINTSET_SOVFL_Pos)           /* (ADC_DMAINTSET) Synchonizer Overflow Mask */
#define ADC_DMAINTSET_SOVFL(value)            (ADC_DMAINTSET_SOVFL_Msk & (_UINT32_(value) << ADC_DMAINTSET_SOVFL_Pos)) /* Assigment of value for SOVFL in the ADC_DMAINTSET register */
#define ADC_DMAINTSET_Msk                     _UINT32_(0x000100FF)                                 /* (ADC_DMAINTSET) Register Mask  */


/* -------- ADC_DMAINTFLAG : (ADC Offset: 0xF8) (R/W 32) DMA Interrupt Flag and Status -------- */
#define ADC_DMAINTFLAG_RESETVALUE             _UINT32_(0x00)                                       /*  (ADC_DMAINTFLAG) DMA Interrupt Flag and Status  Reset Value */

#define ADC_DMAINTFLAG_RAF_Pos                _UINT32_(0)                                          /* (ADC_DMAINTFLAG) Ram Buffer A Full Position */
#define ADC_DMAINTFLAG_RAF_Msk                (_UINT32_(0xF) << ADC_DMAINTFLAG_RAF_Pos)            /* (ADC_DMAINTFLAG) Ram Buffer A Full Mask */
#define ADC_DMAINTFLAG_RAF(value)             (ADC_DMAINTFLAG_RAF_Msk & (_UINT32_(value) << ADC_DMAINTFLAG_RAF_Pos)) /* Assigment of value for RAF in the ADC_DMAINTFLAG register */
#define ADC_DMAINTFLAG_RBF_Pos                _UINT32_(4)                                          /* (ADC_DMAINTFLAG) Ram Buffer B Full Position */
#define ADC_DMAINTFLAG_RBF_Msk                (_UINT32_(0xF) << ADC_DMAINTFLAG_RBF_Pos)            /* (ADC_DMAINTFLAG) Ram Buffer B Full Mask */
#define ADC_DMAINTFLAG_RBF(value)             (ADC_DMAINTFLAG_RBF_Msk & (_UINT32_(value) << ADC_DMAINTFLAG_RBF_Pos)) /* Assigment of value for RBF in the ADC_DMAINTFLAG register */
#define ADC_DMAINTFLAG_SOVFL_Pos              _UINT32_(16)                                         /* (ADC_DMAINTFLAG) Synchronizer overflow Position */
#define ADC_DMAINTFLAG_SOVFL_Msk              (_UINT32_(0x1) << ADC_DMAINTFLAG_SOVFL_Pos)          /* (ADC_DMAINTFLAG) Synchronizer overflow Mask */
#define ADC_DMAINTFLAG_SOVFL(value)           (ADC_DMAINTFLAG_SOVFL_Msk & (_UINT32_(value) << ADC_DMAINTFLAG_SOVFL_Pos)) /* Assigment of value for SOVFL in the ADC_DMAINTFLAG register */
#define ADC_DMAINTFLAG_Msk                    _UINT32_(0x000100FF)                                 /* (ADC_DMAINTFLAG) Register Mask  */


/* -------- ADC_CTLINTENSET : (ADC Offset: 0xFC) (R/W 32) CORE Controller Interrupt Enable Set -------- */
#define ADC_CTLINTENSET_RESETVALUE            _UINT32_(0x00)                                       /*  (ADC_CTLINTENSET) CORE Controller Interrupt Enable Set  Reset Value */

#define ADC_CTLINTENSET_CRRDY_Pos             _UINT32_(0)                                          /* (ADC_CTLINTENSET) Core Ready Position */
#define ADC_CTLINTENSET_CRRDY_Msk             (_UINT32_(0xF) << ADC_CTLINTENSET_CRRDY_Pos)         /* (ADC_CTLINTENSET) Core Ready Mask */
#define ADC_CTLINTENSET_CRRDY(value)          (ADC_CTLINTENSET_CRRDY_Msk & (_UINT32_(value) << ADC_CTLINTENSET_CRRDY_Pos)) /* Assigment of value for CRRDY in the ADC_CTLINTENSET register */
#define ADC_CTLINTENSET_VREFUPD_Pos           _UINT32_(6)                                          /* (ADC_CTLINTENSET) VREF update Position */
#define ADC_CTLINTENSET_VREFUPD_Msk           (_UINT32_(0x1) << ADC_CTLINTENSET_VREFUPD_Pos)       /* (ADC_CTLINTENSET) VREF update Mask */
#define ADC_CTLINTENSET_VREFUPD(value)        (ADC_CTLINTENSET_VREFUPD_Msk & (_UINT32_(value) << ADC_CTLINTENSET_VREFUPD_Pos)) /* Assigment of value for VREFUPD in the ADC_CTLINTENSET register */
#define ADC_CTLINTENSET_VREFRDY_Pos           _UINT32_(7)                                          /* (ADC_CTLINTENSET) VREF Ready Position */
#define ADC_CTLINTENSET_VREFRDY_Msk           (_UINT32_(0x1) << ADC_CTLINTENSET_VREFRDY_Pos)       /* (ADC_CTLINTENSET) VREF Ready Mask */
#define ADC_CTLINTENSET_VREFRDY(value)        (ADC_CTLINTENSET_VREFRDY_Msk & (_UINT32_(value) << ADC_CTLINTENSET_VREFRDY_Pos)) /* Assigment of value for VREFRDY in the ADC_CTLINTENSET register */
#define ADC_CTLINTENSET_PFFUNF_Pos            _UINT32_(8)                                          /* (ADC_CTLINTENSET) APB FIFO Underflow Position */
#define ADC_CTLINTENSET_PFFUNF_Msk            (_UINT32_(0x1) << ADC_CTLINTENSET_PFFUNF_Pos)        /* (ADC_CTLINTENSET) APB FIFO Underflow Mask */
#define ADC_CTLINTENSET_PFFUNF(value)         (ADC_CTLINTENSET_PFFUNF_Msk & (_UINT32_(value) << ADC_CTLINTENSET_PFFUNF_Pos)) /* Assigment of value for PFFUNF in the ADC_CTLINTENSET register */
#define ADC_CTLINTENSET_PFFOVF_Pos            _UINT32_(9)                                          /* (ADC_CTLINTENSET) APB FIFO Overflow Position */
#define ADC_CTLINTENSET_PFFOVF_Msk            (_UINT32_(0x1) << ADC_CTLINTENSET_PFFOVF_Pos)        /* (ADC_CTLINTENSET) APB FIFO Overflow Mask */
#define ADC_CTLINTENSET_PFFOVF(value)         (ADC_CTLINTENSET_PFFOVF_Msk & (_UINT32_(value) << ADC_CTLINTENSET_PFFOVF_Pos)) /* Assigment of value for PFFOVF in the ADC_CTLINTENSET register */
#define ADC_CTLINTENSET_PFFRDY_Pos            _UINT32_(10)                                         /* (ADC_CTLINTENSET) APB FIFO Ready Position */
#define ADC_CTLINTENSET_PFFRDY_Msk            (_UINT32_(0x1) << ADC_CTLINTENSET_PFFRDY_Pos)        /* (ADC_CTLINTENSET) APB FIFO Ready Mask */
#define ADC_CTLINTENSET_PFFRDY(value)         (ADC_CTLINTENSET_PFFRDY_Msk & (_UINT32_(value) << ADC_CTLINTENSET_PFFRDY_Pos)) /* Assigment of value for PFFRDY in the ADC_CTLINTENSET register */
#define ADC_CTLINTENSET_PFFHFUL_Pos           _UINT32_(11)                                         /* (ADC_CTLINTENSET) APB FIFO Half Full Position */
#define ADC_CTLINTENSET_PFFHFUL_Msk           (_UINT32_(0x1) << ADC_CTLINTENSET_PFFHFUL_Pos)       /* (ADC_CTLINTENSET) APB FIFO Half Full Mask */
#define ADC_CTLINTENSET_PFFHFUL(value)        (ADC_CTLINTENSET_PFFHFUL_Msk & (_UINT32_(value) << ADC_CTLINTENSET_PFFHFUL_Pos)) /* Assigment of value for PFFHFUL in the ADC_CTLINTENSET register */
#define ADC_CTLINTENSET_Msk                   _UINT32_(0x00000FCF)                                 /* (ADC_CTLINTENSET) Register Mask  */


/* -------- ADC_CTLINTENCLR : (ADC Offset: 0x100) (R/W 32) CORE Controller Interrupt Enable Clear -------- */
#define ADC_CTLINTENCLR_RESETVALUE            _UINT32_(0x00)                                       /*  (ADC_CTLINTENCLR) CORE Controller Interrupt Enable Clear  Reset Value */

#define ADC_CTLINTENCLR_CRRDY_Pos             _UINT32_(0)                                          /* (ADC_CTLINTENCLR) Core Ready Disable Position */
#define ADC_CTLINTENCLR_CRRDY_Msk             (_UINT32_(0xF) << ADC_CTLINTENCLR_CRRDY_Pos)         /* (ADC_CTLINTENCLR) Core Ready Disable Mask */
#define ADC_CTLINTENCLR_CRRDY(value)          (ADC_CTLINTENCLR_CRRDY_Msk & (_UINT32_(value) << ADC_CTLINTENCLR_CRRDY_Pos)) /* Assigment of value for CRRDY in the ADC_CTLINTENCLR register */
#define ADC_CTLINTENCLR_VREFUPD_Pos           _UINT32_(6)                                          /* (ADC_CTLINTENCLR) VREF Update Position */
#define ADC_CTLINTENCLR_VREFUPD_Msk           (_UINT32_(0x1) << ADC_CTLINTENCLR_VREFUPD_Pos)       /* (ADC_CTLINTENCLR) VREF Update Mask */
#define ADC_CTLINTENCLR_VREFUPD(value)        (ADC_CTLINTENCLR_VREFUPD_Msk & (_UINT32_(value) << ADC_CTLINTENCLR_VREFUPD_Pos)) /* Assigment of value for VREFUPD in the ADC_CTLINTENCLR register */
#define ADC_CTLINTENCLR_VREFRDY_Pos           _UINT32_(7)                                          /* (ADC_CTLINTENCLR) VREF Ready Position */
#define ADC_CTLINTENCLR_VREFRDY_Msk           (_UINT32_(0x1) << ADC_CTLINTENCLR_VREFRDY_Pos)       /* (ADC_CTLINTENCLR) VREF Ready Mask */
#define ADC_CTLINTENCLR_VREFRDY(value)        (ADC_CTLINTENCLR_VREFRDY_Msk & (_UINT32_(value) << ADC_CTLINTENCLR_VREFRDY_Pos)) /* Assigment of value for VREFRDY in the ADC_CTLINTENCLR register */
#define ADC_CTLINTENCLR_PFFUNF_Pos            _UINT32_(8)                                          /* (ADC_CTLINTENCLR) APB FIFO underflow Position */
#define ADC_CTLINTENCLR_PFFUNF_Msk            (_UINT32_(0x1) << ADC_CTLINTENCLR_PFFUNF_Pos)        /* (ADC_CTLINTENCLR) APB FIFO underflow Mask */
#define ADC_CTLINTENCLR_PFFUNF(value)         (ADC_CTLINTENCLR_PFFUNF_Msk & (_UINT32_(value) << ADC_CTLINTENCLR_PFFUNF_Pos)) /* Assigment of value for PFFUNF in the ADC_CTLINTENCLR register */
#define ADC_CTLINTENCLR_PFFOVF_Pos            _UINT32_(9)                                          /* (ADC_CTLINTENCLR) APB FIFO overflow Position */
#define ADC_CTLINTENCLR_PFFOVF_Msk            (_UINT32_(0x1) << ADC_CTLINTENCLR_PFFOVF_Pos)        /* (ADC_CTLINTENCLR) APB FIFO overflow Mask */
#define ADC_CTLINTENCLR_PFFOVF(value)         (ADC_CTLINTENCLR_PFFOVF_Msk & (_UINT32_(value) << ADC_CTLINTENCLR_PFFOVF_Pos)) /* Assigment of value for PFFOVF in the ADC_CTLINTENCLR register */
#define ADC_CTLINTENCLR_PFFRDY_Pos            _UINT32_(10)                                         /* (ADC_CTLINTENCLR) APB FIFO Ready Position */
#define ADC_CTLINTENCLR_PFFRDY_Msk            (_UINT32_(0x1) << ADC_CTLINTENCLR_PFFRDY_Pos)        /* (ADC_CTLINTENCLR) APB FIFO Ready Mask */
#define ADC_CTLINTENCLR_PFFRDY(value)         (ADC_CTLINTENCLR_PFFRDY_Msk & (_UINT32_(value) << ADC_CTLINTENCLR_PFFRDY_Pos)) /* Assigment of value for PFFRDY in the ADC_CTLINTENCLR register */
#define ADC_CTLINTENCLR_PFFHFUL_Pos           _UINT32_(11)                                         /* (ADC_CTLINTENCLR) APB FIFO Half Full Position */
#define ADC_CTLINTENCLR_PFFHFUL_Msk           (_UINT32_(0x1) << ADC_CTLINTENCLR_PFFHFUL_Pos)       /* (ADC_CTLINTENCLR) APB FIFO Half Full Mask */
#define ADC_CTLINTENCLR_PFFHFUL(value)        (ADC_CTLINTENCLR_PFFHFUL_Msk & (_UINT32_(value) << ADC_CTLINTENCLR_PFFHFUL_Pos)) /* Assigment of value for PFFHFUL in the ADC_CTLINTENCLR register */
#define ADC_CTLINTENCLR_Msk                   _UINT32_(0x00000FCF)                                 /* (ADC_CTLINTENCLR) Register Mask  */


/* -------- ADC_CTLINTFLAG : (ADC Offset: 0x104) (R/W 32) CORE Controller Interrupt Flags -------- */
#define ADC_CTLINTFLAG_RESETVALUE             _UINT32_(0x00)                                       /*  (ADC_CTLINTFLAG) CORE Controller Interrupt Flags  Reset Value */

#define ADC_CTLINTFLAG_CRRDY_Pos              _UINT32_(0)                                          /* (ADC_CTLINTFLAG) Core Ready Position */
#define ADC_CTLINTFLAG_CRRDY_Msk              (_UINT32_(0xF) << ADC_CTLINTFLAG_CRRDY_Pos)          /* (ADC_CTLINTFLAG) Core Ready Mask */
#define ADC_CTLINTFLAG_CRRDY(value)           (ADC_CTLINTFLAG_CRRDY_Msk & (_UINT32_(value) << ADC_CTLINTFLAG_CRRDY_Pos)) /* Assigment of value for CRRDY in the ADC_CTLINTFLAG register */
#define ADC_CTLINTFLAG_VREFUPD_Pos            _UINT32_(6)                                          /* (ADC_CTLINTFLAG) VREF update Position */
#define ADC_CTLINTFLAG_VREFUPD_Msk            (_UINT32_(0x1) << ADC_CTLINTFLAG_VREFUPD_Pos)        /* (ADC_CTLINTFLAG) VREF update Mask */
#define ADC_CTLINTFLAG_VREFUPD(value)         (ADC_CTLINTFLAG_VREFUPD_Msk & (_UINT32_(value) << ADC_CTLINTFLAG_VREFUPD_Pos)) /* Assigment of value for VREFUPD in the ADC_CTLINTFLAG register */
#define ADC_CTLINTFLAG_VREFRDY_Pos            _UINT32_(7)                                          /* (ADC_CTLINTFLAG) VREF Ready Position */
#define ADC_CTLINTFLAG_VREFRDY_Msk            (_UINT32_(0x1) << ADC_CTLINTFLAG_VREFRDY_Pos)        /* (ADC_CTLINTFLAG) VREF Ready Mask */
#define ADC_CTLINTFLAG_VREFRDY(value)         (ADC_CTLINTFLAG_VREFRDY_Msk & (_UINT32_(value) << ADC_CTLINTFLAG_VREFRDY_Pos)) /* Assigment of value for VREFRDY in the ADC_CTLINTFLAG register */
#define ADC_CTLINTFLAG_PFFUNF_Pos             _UINT32_(8)                                          /* (ADC_CTLINTFLAG) APB FIFO underflow Position */
#define ADC_CTLINTFLAG_PFFUNF_Msk             (_UINT32_(0x1) << ADC_CTLINTFLAG_PFFUNF_Pos)         /* (ADC_CTLINTFLAG) APB FIFO underflow Mask */
#define ADC_CTLINTFLAG_PFFUNF(value)          (ADC_CTLINTFLAG_PFFUNF_Msk & (_UINT32_(value) << ADC_CTLINTFLAG_PFFUNF_Pos)) /* Assigment of value for PFFUNF in the ADC_CTLINTFLAG register */
#define ADC_CTLINTFLAG_PFFOVF_Pos             _UINT32_(9)                                          /* (ADC_CTLINTFLAG) APB FIFO overflow Position */
#define ADC_CTLINTFLAG_PFFOVF_Msk             (_UINT32_(0x1) << ADC_CTLINTFLAG_PFFOVF_Pos)         /* (ADC_CTLINTFLAG) APB FIFO overflow Mask */
#define ADC_CTLINTFLAG_PFFOVF(value)          (ADC_CTLINTFLAG_PFFOVF_Msk & (_UINT32_(value) << ADC_CTLINTFLAG_PFFOVF_Pos)) /* Assigment of value for PFFOVF in the ADC_CTLINTFLAG register */
#define ADC_CTLINTFLAG_PFFRDY_Pos             _UINT32_(10)                                         /* (ADC_CTLINTFLAG) APB FIFO Ready Position */
#define ADC_CTLINTFLAG_PFFRDY_Msk             (_UINT32_(0x1) << ADC_CTLINTFLAG_PFFRDY_Pos)         /* (ADC_CTLINTFLAG) APB FIFO Ready Mask */
#define ADC_CTLINTFLAG_PFFRDY(value)          (ADC_CTLINTFLAG_PFFRDY_Msk & (_UINT32_(value) << ADC_CTLINTFLAG_PFFRDY_Pos)) /* Assigment of value for PFFRDY in the ADC_CTLINTFLAG register */
#define ADC_CTLINTFLAG_PFFHFUL_Pos            _UINT32_(11)                                         /* (ADC_CTLINTFLAG) APB FIFO Half Full Position */
#define ADC_CTLINTFLAG_PFFHFUL_Msk            (_UINT32_(0x1) << ADC_CTLINTFLAG_PFFHFUL_Pos)        /* (ADC_CTLINTFLAG) APB FIFO Half Full Mask */
#define ADC_CTLINTFLAG_PFFHFUL(value)         (ADC_CTLINTFLAG_PFFHFUL_Msk & (_UINT32_(value) << ADC_CTLINTFLAG_PFFHFUL_Pos)) /* Assigment of value for PFFHFUL in the ADC_CTLINTFLAG register */
#define ADC_CTLINTFLAG_Msk                    _UINT32_(0x00000FCF)                                 /* (ADC_CTLINTFLAG) Register Mask  */


/* -------- ADC_DIGTSTOUT : (ADC Offset: 0x160) ( R/ 32) Test Debug Register -------- */
#define ADC_DIGTSTOUT_RESETVALUE              _UINT32_(0x00)                                       /*  (ADC_DIGTSTOUT) Test Debug Register  Reset Value */

#define ADC_DIGTSTOUT_ADCDIGTST_Pos           _UINT32_(0)                                          /* (ADC_DIGTSTOUT) Digital Debug Test port Register Position */
#define ADC_DIGTSTOUT_ADCDIGTST_Msk           (_UINT32_(0xFFFFFFFF) << ADC_DIGTSTOUT_ADCDIGTST_Pos) /* (ADC_DIGTSTOUT) Digital Debug Test port Register Mask */
#define ADC_DIGTSTOUT_ADCDIGTST(value)        (ADC_DIGTSTOUT_ADCDIGTST_Msk & (_UINT32_(value) << ADC_DIGTSTOUT_ADCDIGTST_Pos)) /* Assigment of value for ADCDIGTST in the ADC_DIGTSTOUT register */
#define ADC_DIGTSTOUT_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (ADC_DIGTSTOUT) Register Mask  */


/* -------- ADC_TSTIDOUT : (ADC Offset: 0x164) (R/W 32) Test Degug2 Register -------- */
#define ADC_TSTIDOUT_RESETVALUE               _UINT32_(0x00)                                       /*  (ADC_TSTIDOUT) Test Degug2 Register  Reset Value */

#define ADC_TSTIDOUT_TSTCORID_Pos             _UINT32_(0)                                          /* (ADC_TSTIDOUT) Core Digital Test Out Read ID Position */
#define ADC_TSTIDOUT_TSTCORID_Msk             (_UINT32_(0x1) << ADC_TSTIDOUT_TSTCORID_Pos)         /* (ADC_TSTIDOUT) Core Digital Test Out Read ID Mask */
#define ADC_TSTIDOUT_TSTCORID(value)          (ADC_TSTIDOUT_TSTCORID_Msk & (_UINT32_(value) << ADC_TSTIDOUT_TSTCORID_Pos)) /* Assigment of value for TSTCORID in the ADC_TSTIDOUT register */
#define ADC_TSTIDOUT_Msk                      _UINT32_(0x00000001)                                 /* (ADC_TSTIDOUT) Register Mask  */


/* -------- ADC_DBGCTRL : (ADC Offset: 0x168) (R/W 32) Debug Control Register -------- */
#define ADC_DBGCTRL_RESETVALUE                _UINT32_(0x00)                                       /*  (ADC_DBGCTRL) Debug Control Register  Reset Value */

#define ADC_DBGCTRL_DBGRUN_Pos                _UINT32_(0)                                          /* (ADC_DBGCTRL) Debug Running State Position */
#define ADC_DBGCTRL_DBGRUN_Msk                (_UINT32_(0x1) << ADC_DBGCTRL_DBGRUN_Pos)            /* (ADC_DBGCTRL) Debug Running State Mask */
#define ADC_DBGCTRL_DBGRUN(value)             (ADC_DBGCTRL_DBGRUN_Msk & (_UINT32_(value) << ADC_DBGCTRL_DBGRUN_Pos)) /* Assigment of value for DBGRUN in the ADC_DBGCTRL register */
#define ADC_DBGCTRL_Msk                       _UINT32_(0x00000001)                                 /* (ADC_DBGCTRL) Register Mask  */


/** \brief ADC register offsets definitions */
#define ADC_CORCTRL_REG_OFST           _UINT32_(0x00)      /* (ADC_CORCTRL) SARCORE Control Offset */
#define ADC_CHNCFG1_REG_OFST           _UINT32_(0x04)      /* (ADC_CHNCFG1) Channel Configuration 1 (LVL/CMPEN) Offset */
#define ADC_CHNCFG2_REG_OFST           _UINT32_(0x08)      /* (ADC_CHNCFG2) Channel Configuration 2(FRACT/CSS) Offset */
#define ADC_CHNCFG3_REG_OFST           _UINT32_(0x0C)      /* (ADC_CHNCFG3) Channel Configuration3 (SIGN/DIFF) Offset */
#define ADC_CHNCFG4_REG_OFST           _UINT32_(0x10)      /* (ADC_CHNCFG4) Channel Configuration 4 (TRGSRC) Offset */
#define ADC_CHNCFG5_REG_OFST           _UINT32_(0x14)      /* (ADC_CHNCFG5) Channel Configuration 5 (TRGSRC) Offset */
#define ADC_CALCTRL_REG_OFST           _UINT32_(0x18)      /* (ADC_CALCTRL) SARCORE Calibration Value Offset */
#define ADC_EVCTRL_REG_OFST            _UINT32_(0x1C)      /* (ADC_EVCTRL) Event Control Offset */
#define ADC_INTENCLR_REG_OFST          _UINT32_(0x00)      /* (ADC_INTENCLR) Interrupt Enable Clear Offset */
#define ADC_INTENSET_REG_OFST          _UINT32_(0x04)      /* (ADC_INTENSET) Interrupt Enable Set Offset */
#define ADC_INTFLAG_REG_OFST           _UINT32_(0x08)      /* (ADC_INTFLAG) Interrupt Flags Offset */
#define ADC_CTRLA_REG_OFST             _UINT32_(0x00)      /* (ADC_CTRLA) CONTROL A REGISTER Offset */
#define ADC_CTRLB_REG_OFST             _UINT32_(0x04)      /* (ADC_CTRLB) CONTROL B REGISTER Offset */
#define ADC_CTRLC_REG_OFST             _UINT32_(0x08)      /* (ADC_CTRLC) Control C Register Offset */
#define ADC_CTRLD_REG_OFST             _UINT32_(0x10)      /* (ADC_CTRLD) Control D Register Offset */
#define ADC_CMPCTRL_REG_OFST           _UINT32_(0xB0)      /* (ADC_CMPCTRL) Comparator Control Offset */
#define ADC_CMPCTRL0_REG_OFST          _UINT32_(0xB0)      /* (ADC_CMPCTRL0) Comparator Control Offset */
#define ADC_CMPCTRL1_REG_OFST          _UINT32_(0xB4)      /* (ADC_CMPCTRL1) Comparator Control Offset */
#define ADC_CMPCTRL2_REG_OFST          _UINT32_(0xB8)      /* (ADC_CMPCTRL2) Comparator Control Offset */
#define ADC_CMPCTRL3_REG_OFST          _UINT32_(0xBC)      /* (ADC_CMPCTRL3) Comparator Control Offset */
#define ADC_FLTCTRL_REG_OFST           _UINT32_(0xC0)      /* (ADC_FLTCTRL) Filter Control Offset */
#define ADC_FLTCTRL0_REG_OFST          _UINT32_(0xC0)      /* (ADC_FLTCTRL0) Filter Control Offset */
#define ADC_FLTCTRL1_REG_OFST          _UINT32_(0xC4)      /* (ADC_FLTCTRL1) Filter Control Offset */
#define ADC_FLTCTRL2_REG_OFST          _UINT32_(0xC8)      /* (ADC_FLTCTRL2) Filter Control Offset */
#define ADC_FLTCTRL3_REG_OFST          _UINT32_(0xCC)      /* (ADC_FLTCTRL3) Filter Control Offset */
#define ADC_CORCHDATAID_REG_OFST       _UINT32_(0xD0)      /* (ADC_CORCHDATAID) Channel Ready DATA ID Offset */
#define ADC_CHRDYDAT_REG_OFST          _UINT32_(0xD4)      /* (ADC_CHRDYDAT) Channel Ready Data Register Offset */
#define ADC_PFFDATA_REG_OFST           _UINT32_(0xD8)      /* (ADC_PFFDATA) APB FIFO Output Data Offset */
#define ADC_DMABASE_REG_OFST           _UINT32_(0xDC)      /* (ADC_DMABASE) DMA Sample Base Address Offset */
#define ADC_DMACTRL_REG_OFST           _UINT32_(0xE0)      /* (ADC_DMACTRL) DMA Control Register Offset */
#define ADC_PFFCTRL_REG_OFST           _UINT32_(0xE4)      /* (ADC_PFFCTRL) APB FIFO Control Register Offset */
#define ADC_SYNCBUSY_REG_OFST          _UINT32_(0xE8)      /* (ADC_SYNCBUSY) CORE SYNC Busy Status Register Offset */
#define ADC_TESTREG_REG_OFST           _UINT32_(0xEC)      /* (ADC_TESTREG) Test Control Register Offset */
#define ADC_DMAINTENCLR_REG_OFST       _UINT32_(0xF0)      /* (ADC_DMAINTENCLR) DMA Interrupt Enable Clear Offset */
#define ADC_DMAINTSET_REG_OFST         _UINT32_(0xF4)      /* (ADC_DMAINTSET) DMA Interrupt Enable Set Offset */
#define ADC_DMAINTFLAG_REG_OFST        _UINT32_(0xF8)      /* (ADC_DMAINTFLAG) DMA Interrupt Flag and Status Offset */
#define ADC_CTLINTENSET_REG_OFST       _UINT32_(0xFC)      /* (ADC_CTLINTENSET) CORE Controller Interrupt Enable Set Offset */
#define ADC_CTLINTENCLR_REG_OFST       _UINT32_(0x100)     /* (ADC_CTLINTENCLR) CORE Controller Interrupt Enable Clear Offset */
#define ADC_CTLINTFLAG_REG_OFST        _UINT32_(0x104)     /* (ADC_CTLINTFLAG) CORE Controller Interrupt Flags Offset */
#define ADC_DIGTSTOUT_REG_OFST         _UINT32_(0x160)     /* (ADC_DIGTSTOUT) Test Debug Register Offset */
#define ADC_TSTIDOUT_REG_OFST          _UINT32_(0x164)     /* (ADC_TSTIDOUT) Test Degug2 Register Offset */
#define ADC_DBGCTRL_REG_OFST           _UINT32_(0x168)     /* (ADC_DBGCTRL) Debug Control Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief CONFIG register API structure */
typedef struct
{
  __IO  uint32_t                       ADC_CORCTRL;        /**< Offset: 0x00 (R/W  32) SARCORE Control */
  __IO  uint32_t                       ADC_CHNCFG1;        /**< Offset: 0x04 (R/W  32) Channel Configuration 1 (LVL/CMPEN) */
  __IO  uint32_t                       ADC_CHNCFG2;        /**< Offset: 0x08 (R/W  32) Channel Configuration 2(FRACT/CSS) */
  __IO  uint32_t                       ADC_CHNCFG3;        /**< Offset: 0x0C (R/W  32) Channel Configuration3 (SIGN/DIFF) */
  __IO  uint32_t                       ADC_CHNCFG4;        /**< Offset: 0x10 (R/W  32) Channel Configuration 4 (TRGSRC) */
  __IO  uint32_t                       ADC_CHNCFG5;        /**< Offset: 0x14 (R/W  32) Channel Configuration 5 (TRGSRC) */
  __IO  uint32_t                       ADC_CALCTRL;        /**< Offset: 0x18 (R/W  32) SARCORE Calibration Value */
  __IO  uint32_t                       ADC_EVCTRL;         /**< Offset: 0x1C (R/W  32) Event Control */
} adc_config_registers_t;

/** \brief INT register API structure */
typedef struct
{
  __IO  uint32_t                       ADC_INTENCLR;       /**< Offset: 0x00 (R/W  32) Interrupt Enable Clear */
  __IO  uint32_t                       ADC_INTENSET;       /**< Offset: 0x04 (R/W  32) Interrupt Enable Set */
  __IO  uint32_t                       ADC_INTFLAG;        /**< Offset: 0x08 (R/W  32) Interrupt Flags */
  __I   uint8_t                        Reserved1[0x04];
} adc_int_registers_t;

#define ADC_CONFIG_NUMBER 4

#define ADC_INT_NUMBER 4

/** \brief ADC register API structure */
typedef struct
{  /* ADC Controller */
  __IO  uint32_t                       ADC_CTRLA;          /**< Offset: 0x00 (R/W  32) CONTROL A REGISTER */
  __IO  uint32_t                       ADC_CTRLB;          /**< Offset: 0x04 (R/W  32) CONTROL B REGISTER */
  __IO  uint32_t                       ADC_CTRLC;          /**< Offset: 0x08 (R/W  32) Control C Register */
  __I   uint8_t                        Reserved1[0x04];
  __IO  uint32_t                       ADC_CTRLD;          /**< Offset: 0x10 (R/W  32) Control D Register */
  __I   uint8_t                        Reserved2[0x0C];
        adc_config_registers_t         CONFIG[ADC_CONFIG_NUMBER]; /**< Offset: 0x20  */
  __I   uint8_t                        Reserved3[0x10];
  __IO  uint32_t                       ADC_CMPCTRL[4];     /**< Offset: 0xB0 (R/W  32) Comparator Control */
  __IO  uint32_t                       ADC_FLTCTRL[4];     /**< Offset: 0xC0 (R/W  32) Filter Control */
  __IO  uint32_t                       ADC_CORCHDATAID;    /**< Offset: 0xD0 (R/W  32) Channel Ready DATA ID */
  __IO  uint32_t                       ADC_CHRDYDAT;       /**< Offset: 0xD4 (R/W  32) Channel Ready Data Register */
  __I   uint32_t                       ADC_PFFDATA;        /**< Offset: 0xD8 (R/   32) APB FIFO Output Data */
  __IO  uint32_t                       ADC_DMABASE;        /**< Offset: 0xDC (R/W  32) DMA Sample Base Address */
  __IO  uint32_t                       ADC_DMACTRL;        /**< Offset: 0xE0 (R/W  32) DMA Control Register */
  __IO  uint32_t                       ADC_PFFCTRL;        /**< Offset: 0xE4 (R/W  32) APB FIFO Control Register */
  __I   uint32_t                       ADC_SYNCBUSY;       /**< Offset: 0xE8 (R/   32) CORE SYNC Busy Status Register */
  __IO  uint32_t                       ADC_TESTREG;        /**< Offset: 0xEC (R/W  32) Test Control Register */
  __IO  uint32_t                       ADC_DMAINTENCLR;    /**< Offset: 0xF0 (R/W  32) DMA Interrupt Enable Clear */
  __IO  uint32_t                       ADC_DMAINTSET;      /**< Offset: 0xF4 (R/W  32) DMA Interrupt Enable Set */
  __IO  uint32_t                       ADC_DMAINTFLAG;     /**< Offset: 0xF8 (R/W  32) DMA Interrupt Flag and Status */
  __IO  uint32_t                       ADC_CTLINTENSET;    /**< Offset: 0xFC (R/W  32) CORE Controller Interrupt Enable Set */
  __IO  uint32_t                       ADC_CTLINTENCLR;    /**< Offset: 0x100 (R/W  32) CORE Controller Interrupt Enable Clear */
  __IO  uint32_t                       ADC_CTLINTFLAG;     /**< Offset: 0x104 (R/W  32) CORE Controller Interrupt Flags */
  __I   uint8_t                        Reserved4[0x18];
        adc_int_registers_t            INT[ADC_INT_NUMBER]; /**< Offset: 0x120  */
  __I   uint32_t                       ADC_DIGTSTOUT;      /**< Offset: 0x160 (R/   32) Test Debug Register */
  __IO  uint32_t                       ADC_TSTIDOUT;       /**< Offset: 0x164 (R/W  32) Test Degug2 Register */
  __IO  uint32_t                       ADC_DBGCTRL;        /**< Offset: 0x168 (R/W  32) Debug Control Register */
} adc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA90_ADC_COMPONENT_H_ */
