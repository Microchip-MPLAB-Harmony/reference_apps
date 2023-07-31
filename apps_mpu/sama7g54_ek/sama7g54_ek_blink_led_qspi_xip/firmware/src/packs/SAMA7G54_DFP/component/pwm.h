/*
 * Component description for PWM
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

/* file generated from device description version 2023-01-20T08:56:57Z */
#ifndef _SAMA7G_PWM_COMPONENT_H_
#define _SAMA7G_PWM_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR PWM                                          */
/* ************************************************************************** */

/* -------- PWM_CMR : (PWM Offset: 0x00) (R/W 32) PWM Channel Mode Register  -------- */
#define PWM_CMR_RESETVALUE                    _UINT32_(0x00)                                       /*  (PWM_CMR) PWM Channel Mode Register   Reset Value */

#define PWM_CMR_CPRE_Pos                      _UINT32_(0)                                          /* (PWM_CMR) Channel Prescaler Position */
#define PWM_CMR_CPRE_Msk                      (_UINT32_(0xF) << PWM_CMR_CPRE_Pos)                  /* (PWM_CMR) Channel Prescaler Mask */
#define PWM_CMR_CPRE(value)                   (PWM_CMR_CPRE_Msk & (_UINT32_(value) << PWM_CMR_CPRE_Pos)) /* Assigment of value for CPRE in the PWM_CMR register */
#define   PWM_CMR_CPRE_MCK_Val                _UINT32_(0x0)                                        /* (PWM_CMR) Peripheral clock  */
#define   PWM_CMR_CPRE_MCK_DIV_2_Val          _UINT32_(0x1)                                        /* (PWM_CMR) Peripheral clock/2  */
#define   PWM_CMR_CPRE_MCK_DIV_4_Val          _UINT32_(0x2)                                        /* (PWM_CMR) Peripheral clock/4  */
#define   PWM_CMR_CPRE_MCK_DIV_8_Val          _UINT32_(0x3)                                        /* (PWM_CMR) Peripheral clock/8  */
#define   PWM_CMR_CPRE_MCK_DIV_16_Val         _UINT32_(0x4)                                        /* (PWM_CMR) Peripheral clock/16  */
#define   PWM_CMR_CPRE_MCK_DIV_32_Val         _UINT32_(0x5)                                        /* (PWM_CMR) Peripheral clock/32  */
#define   PWM_CMR_CPRE_MCK_DIV_64_Val         _UINT32_(0x6)                                        /* (PWM_CMR) Peripheral clock/64  */
#define   PWM_CMR_CPRE_MCK_DIV_128_Val        _UINT32_(0x7)                                        /* (PWM_CMR) Peripheral clock/128  */
#define   PWM_CMR_CPRE_MCK_DIV_256_Val        _UINT32_(0x8)                                        /* (PWM_CMR) Peripheral clock/256  */
#define   PWM_CMR_CPRE_MCK_DIV_512_Val        _UINT32_(0x9)                                        /* (PWM_CMR) Peripheral clock/512  */
#define   PWM_CMR_CPRE_MCK_DIV_1024_Val       _UINT32_(0xA)                                        /* (PWM_CMR) Peripheral clock/1024  */
#define   PWM_CMR_CPRE_CLKA_Val               _UINT32_(0xB)                                        /* (PWM_CMR) Clock A  */
#define   PWM_CMR_CPRE_CLKB_Val               _UINT32_(0xC)                                        /* (PWM_CMR) Clock B  */
#define PWM_CMR_CPRE_MCK                      (PWM_CMR_CPRE_MCK_Val << PWM_CMR_CPRE_Pos)           /* (PWM_CMR) Peripheral clock Position  */
#define PWM_CMR_CPRE_MCK_DIV_2                (PWM_CMR_CPRE_MCK_DIV_2_Val << PWM_CMR_CPRE_Pos)     /* (PWM_CMR) Peripheral clock/2 Position  */
#define PWM_CMR_CPRE_MCK_DIV_4                (PWM_CMR_CPRE_MCK_DIV_4_Val << PWM_CMR_CPRE_Pos)     /* (PWM_CMR) Peripheral clock/4 Position  */
#define PWM_CMR_CPRE_MCK_DIV_8                (PWM_CMR_CPRE_MCK_DIV_8_Val << PWM_CMR_CPRE_Pos)     /* (PWM_CMR) Peripheral clock/8 Position  */
#define PWM_CMR_CPRE_MCK_DIV_16               (PWM_CMR_CPRE_MCK_DIV_16_Val << PWM_CMR_CPRE_Pos)    /* (PWM_CMR) Peripheral clock/16 Position  */
#define PWM_CMR_CPRE_MCK_DIV_32               (PWM_CMR_CPRE_MCK_DIV_32_Val << PWM_CMR_CPRE_Pos)    /* (PWM_CMR) Peripheral clock/32 Position  */
#define PWM_CMR_CPRE_MCK_DIV_64               (PWM_CMR_CPRE_MCK_DIV_64_Val << PWM_CMR_CPRE_Pos)    /* (PWM_CMR) Peripheral clock/64 Position  */
#define PWM_CMR_CPRE_MCK_DIV_128              (PWM_CMR_CPRE_MCK_DIV_128_Val << PWM_CMR_CPRE_Pos)   /* (PWM_CMR) Peripheral clock/128 Position  */
#define PWM_CMR_CPRE_MCK_DIV_256              (PWM_CMR_CPRE_MCK_DIV_256_Val << PWM_CMR_CPRE_Pos)   /* (PWM_CMR) Peripheral clock/256 Position  */
#define PWM_CMR_CPRE_MCK_DIV_512              (PWM_CMR_CPRE_MCK_DIV_512_Val << PWM_CMR_CPRE_Pos)   /* (PWM_CMR) Peripheral clock/512 Position  */
#define PWM_CMR_CPRE_MCK_DIV_1024             (PWM_CMR_CPRE_MCK_DIV_1024_Val << PWM_CMR_CPRE_Pos)  /* (PWM_CMR) Peripheral clock/1024 Position  */
#define PWM_CMR_CPRE_CLKA                     (PWM_CMR_CPRE_CLKA_Val << PWM_CMR_CPRE_Pos)          /* (PWM_CMR) Clock A Position  */
#define PWM_CMR_CPRE_CLKB                     (PWM_CMR_CPRE_CLKB_Val << PWM_CMR_CPRE_Pos)          /* (PWM_CMR) Clock B Position  */
#define PWM_CMR_CALG_Pos                      _UINT32_(8)                                          /* (PWM_CMR) Channel Alignment Position */
#define PWM_CMR_CALG_Msk                      (_UINT32_(0x1) << PWM_CMR_CALG_Pos)                  /* (PWM_CMR) Channel Alignment Mask */
#define PWM_CMR_CALG(value)                   (PWM_CMR_CALG_Msk & (_UINT32_(value) << PWM_CMR_CALG_Pos)) /* Assigment of value for CALG in the PWM_CMR register */
#define   PWM_CMR_CALG_0_Val                  _UINT32_(0x0)                                        /* (PWM_CMR) The period is left-aligned.  */
#define   PWM_CMR_CALG_1_Val                  _UINT32_(0x1)                                        /* (PWM_CMR) The period is center-aligned.  */
#define PWM_CMR_CALG_0                        (PWM_CMR_CALG_0_Val << PWM_CMR_CALG_Pos)             /* (PWM_CMR) The period is left-aligned. Position  */
#define PWM_CMR_CALG_1                        (PWM_CMR_CALG_1_Val << PWM_CMR_CALG_Pos)             /* (PWM_CMR) The period is center-aligned. Position  */
#define PWM_CMR_CPOL_Pos                      _UINT32_(9)                                          /* (PWM_CMR) Channel Polarity Position */
#define PWM_CMR_CPOL_Msk                      (_UINT32_(0x1) << PWM_CMR_CPOL_Pos)                  /* (PWM_CMR) Channel Polarity Mask */
#define PWM_CMR_CPOL(value)                   (PWM_CMR_CPOL_Msk & (_UINT32_(value) << PWM_CMR_CPOL_Pos)) /* Assigment of value for CPOL in the PWM_CMR register */
#define   PWM_CMR_CPOL_0_Val                  _UINT32_(0x0)                                        /* (PWM_CMR) The OCx output waveform (output from the comparator) starts at a low level.  */
#define   PWM_CMR_CPOL_1_Val                  _UINT32_(0x1)                                        /* (PWM_CMR) The OCx output waveform (output from the comparator) starts at a high level.  */
#define PWM_CMR_CPOL_0                        (PWM_CMR_CPOL_0_Val << PWM_CMR_CPOL_Pos)             /* (PWM_CMR) The OCx output waveform (output from the comparator) starts at a low level. Position  */
#define PWM_CMR_CPOL_1                        (PWM_CMR_CPOL_1_Val << PWM_CMR_CPOL_Pos)             /* (PWM_CMR) The OCx output waveform (output from the comparator) starts at a high level. Position  */
#define PWM_CMR_CES_Pos                       _UINT32_(10)                                         /* (PWM_CMR) Counter Event Selection Position */
#define PWM_CMR_CES_Msk                       (_UINT32_(0x1) << PWM_CMR_CES_Pos)                   /* (PWM_CMR) Counter Event Selection Mask */
#define PWM_CMR_CES(value)                    (PWM_CMR_CES_Msk & (_UINT32_(value) << PWM_CMR_CES_Pos)) /* Assigment of value for CES in the PWM_CMR register */
#define   PWM_CMR_CES_0_Val                   _UINT32_(0x0)                                        /* (PWM_CMR) The channel counter event occurs at the end of the PWM period.  */
#define   PWM_CMR_CES_1_Val                   _UINT32_(0x1)                                        /* (PWM_CMR) The channel counter event occurs at the end of the PWM period and at half the PWM period.  */
#define PWM_CMR_CES_0                         (PWM_CMR_CES_0_Val << PWM_CMR_CES_Pos)               /* (PWM_CMR) The channel counter event occurs at the end of the PWM period. Position  */
#define PWM_CMR_CES_1                         (PWM_CMR_CES_1_Val << PWM_CMR_CES_Pos)               /* (PWM_CMR) The channel counter event occurs at the end of the PWM period and at half the PWM period. Position  */
#define PWM_CMR_UPDS_Pos                      _UINT32_(11)                                         /* (PWM_CMR) Update Selection Position */
#define PWM_CMR_UPDS_Msk                      (_UINT32_(0x1) << PWM_CMR_UPDS_Pos)                  /* (PWM_CMR) Update Selection Mask */
#define PWM_CMR_UPDS(value)                   (PWM_CMR_UPDS_Msk & (_UINT32_(value) << PWM_CMR_UPDS_Pos)) /* Assigment of value for UPDS in the PWM_CMR register */
#define   PWM_CMR_UPDS_0_Val                  _UINT32_(0x0)                                        /* (PWM_CMR) The update occurs at the next end of the PWM period after writing the update register(s).  */
#define   PWM_CMR_UPDS_1_Val                  _UINT32_(0x1)                                        /* (PWM_CMR) The update occurs at the next end of the PWM half period after writing the update register(s).  */
#define PWM_CMR_UPDS_0                        (PWM_CMR_UPDS_0_Val << PWM_CMR_UPDS_Pos)             /* (PWM_CMR) The update occurs at the next end of the PWM period after writing the update register(s). Position  */
#define PWM_CMR_UPDS_1                        (PWM_CMR_UPDS_1_Val << PWM_CMR_UPDS_Pos)             /* (PWM_CMR) The update occurs at the next end of the PWM half period after writing the update register(s). Position  */
#define PWM_CMR_DPOLI_Pos                     _UINT32_(12)                                         /* (PWM_CMR) Disabled Polarity Inverted Position */
#define PWM_CMR_DPOLI_Msk                     (_UINT32_(0x1) << PWM_CMR_DPOLI_Pos)                 /* (PWM_CMR) Disabled Polarity Inverted Mask */
#define PWM_CMR_DPOLI(value)                  (PWM_CMR_DPOLI_Msk & (_UINT32_(value) << PWM_CMR_DPOLI_Pos)) /* Assigment of value for DPOLI in the PWM_CMR register */
#define   PWM_CMR_DPOLI_0_Val                 _UINT32_(0x0)                                        /* (PWM_CMR) When the PWM channel x is disabled (CHIDx(PWM_SR) = 0), the OCx output waveform is the same as the one defined by the CPOL bit.  */
#define   PWM_CMR_DPOLI_1_Val                 _UINT32_(0x1)                                        /* (PWM_CMR) When the PWM channel x is disabled (CHIDx(PWM_SR) = 0), the OCx output waveform is inverted compared to the one defined by the CPOL bit.  */
#define PWM_CMR_DPOLI_0                       (PWM_CMR_DPOLI_0_Val << PWM_CMR_DPOLI_Pos)           /* (PWM_CMR) When the PWM channel x is disabled (CHIDx(PWM_SR) = 0), the OCx output waveform is the same as the one defined by the CPOL bit. Position  */
#define PWM_CMR_DPOLI_1                       (PWM_CMR_DPOLI_1_Val << PWM_CMR_DPOLI_Pos)           /* (PWM_CMR) When the PWM channel x is disabled (CHIDx(PWM_SR) = 0), the OCx output waveform is inverted compared to the one defined by the CPOL bit. Position  */
#define PWM_CMR_TCTS_Pos                      _UINT32_(13)                                         /* (PWM_CMR) Timer Counter Trigger Selection Position */
#define PWM_CMR_TCTS_Msk                      (_UINT32_(0x1) << PWM_CMR_TCTS_Pos)                  /* (PWM_CMR) Timer Counter Trigger Selection Mask */
#define PWM_CMR_TCTS(value)                   (PWM_CMR_TCTS_Msk & (_UINT32_(value) << PWM_CMR_TCTS_Pos)) /* Assigment of value for TCTS in the PWM_CMR register */
#define   PWM_CMR_TCTS_0_Val                  _UINT32_(0x0)                                        /* (PWM_CMR) The comparator of the channel x (OCx) is used as the trigger source for the Timer Counter (TC).  */
#define   PWM_CMR_TCTS_1_Val                  _UINT32_(0x1)                                        /* (PWM_CMR) The counter events of the channel x is used as the trigger source for the Timer Counter (TC).  */
#define PWM_CMR_TCTS_0                        (PWM_CMR_TCTS_0_Val << PWM_CMR_TCTS_Pos)             /* (PWM_CMR) The comparator of the channel x (OCx) is used as the trigger source for the Timer Counter (TC). Position  */
#define PWM_CMR_TCTS_1                        (PWM_CMR_TCTS_1_Val << PWM_CMR_TCTS_Pos)             /* (PWM_CMR) The counter events of the channel x is used as the trigger source for the Timer Counter (TC). Position  */
#define PWM_CMR_DTE_Pos                       _UINT32_(16)                                         /* (PWM_CMR) Dead-Time Generator Enable Position */
#define PWM_CMR_DTE_Msk                       (_UINT32_(0x1) << PWM_CMR_DTE_Pos)                   /* (PWM_CMR) Dead-Time Generator Enable Mask */
#define PWM_CMR_DTE(value)                    (PWM_CMR_DTE_Msk & (_UINT32_(value) << PWM_CMR_DTE_Pos)) /* Assigment of value for DTE in the PWM_CMR register */
#define   PWM_CMR_DTE_0_Val                   _UINT32_(0x0)                                        /* (PWM_CMR) The dead-time generator is disabled.  */
#define   PWM_CMR_DTE_1_Val                   _UINT32_(0x1)                                        /* (PWM_CMR) The dead-time generator is enabled.  */
#define PWM_CMR_DTE_0                         (PWM_CMR_DTE_0_Val << PWM_CMR_DTE_Pos)               /* (PWM_CMR) The dead-time generator is disabled. Position  */
#define PWM_CMR_DTE_1                         (PWM_CMR_DTE_1_Val << PWM_CMR_DTE_Pos)               /* (PWM_CMR) The dead-time generator is enabled. Position  */
#define PWM_CMR_DTHI_Pos                      _UINT32_(17)                                         /* (PWM_CMR) Dead-Time PWMHx Output Inverted Position */
#define PWM_CMR_DTHI_Msk                      (_UINT32_(0x1) << PWM_CMR_DTHI_Pos)                  /* (PWM_CMR) Dead-Time PWMHx Output Inverted Mask */
#define PWM_CMR_DTHI(value)                   (PWM_CMR_DTHI_Msk & (_UINT32_(value) << PWM_CMR_DTHI_Pos)) /* Assigment of value for DTHI in the PWM_CMR register */
#define   PWM_CMR_DTHI_0_Val                  _UINT32_(0x0)                                        /* (PWM_CMR) The dead-time PWMHx output is not inverted.  */
#define   PWM_CMR_DTHI_1_Val                  _UINT32_(0x1)                                        /* (PWM_CMR) The dead-time PWMHx output is inverted.  */
#define PWM_CMR_DTHI_0                        (PWM_CMR_DTHI_0_Val << PWM_CMR_DTHI_Pos)             /* (PWM_CMR) The dead-time PWMHx output is not inverted. Position  */
#define PWM_CMR_DTHI_1                        (PWM_CMR_DTHI_1_Val << PWM_CMR_DTHI_Pos)             /* (PWM_CMR) The dead-time PWMHx output is inverted. Position  */
#define PWM_CMR_DTLI_Pos                      _UINT32_(18)                                         /* (PWM_CMR) Dead-Time PWMLx Output Inverted Position */
#define PWM_CMR_DTLI_Msk                      (_UINT32_(0x1) << PWM_CMR_DTLI_Pos)                  /* (PWM_CMR) Dead-Time PWMLx Output Inverted Mask */
#define PWM_CMR_DTLI(value)                   (PWM_CMR_DTLI_Msk & (_UINT32_(value) << PWM_CMR_DTLI_Pos)) /* Assigment of value for DTLI in the PWM_CMR register */
#define   PWM_CMR_DTLI_0_Val                  _UINT32_(0x0)                                        /* (PWM_CMR) The dead-time PWMLx output is not inverted.  */
#define   PWM_CMR_DTLI_1_Val                  _UINT32_(0x1)                                        /* (PWM_CMR) The dead-time PWMLx output is inverted.  */
#define PWM_CMR_DTLI_0                        (PWM_CMR_DTLI_0_Val << PWM_CMR_DTLI_Pos)             /* (PWM_CMR) The dead-time PWMLx output is not inverted. Position  */
#define PWM_CMR_DTLI_1                        (PWM_CMR_DTLI_1_Val << PWM_CMR_DTLI_Pos)             /* (PWM_CMR) The dead-time PWMLx output is inverted. Position  */
#define PWM_CMR_PPM_Pos                       _UINT32_(19)                                         /* (PWM_CMR) Push-Pull Mode Position */
#define PWM_CMR_PPM_Msk                       (_UINT32_(0x1) << PWM_CMR_PPM_Pos)                   /* (PWM_CMR) Push-Pull Mode Mask */
#define PWM_CMR_PPM(value)                    (PWM_CMR_PPM_Msk & (_UINT32_(value) << PWM_CMR_PPM_Pos)) /* Assigment of value for PPM in the PWM_CMR register */
#define   PWM_CMR_PPM_0_Val                   _UINT32_(0x0)                                        /* (PWM_CMR) The Push-Pull mode is disabled for channel x.  */
#define   PWM_CMR_PPM_1_Val                   _UINT32_(0x1)                                        /* (PWM_CMR) The Push-Pull mode is enabled for channel x.  */
#define PWM_CMR_PPM_0                         (PWM_CMR_PPM_0_Val << PWM_CMR_PPM_Pos)               /* (PWM_CMR) The Push-Pull mode is disabled for channel x. Position  */
#define PWM_CMR_PPM_1                         (PWM_CMR_PPM_1_Val << PWM_CMR_PPM_Pos)               /* (PWM_CMR) The Push-Pull mode is enabled for channel x. Position  */
#define PWM_CMR_Msk                           _UINT32_(0x000F3F0F)                                 /* (PWM_CMR) Register Mask  */


/* -------- PWM_CDTY : (PWM Offset: 0x04) (R/W 32) PWM Channel Duty Cycle Register  -------- */
#define PWM_CDTY_RESETVALUE                   _UINT32_(0x00)                                       /*  (PWM_CDTY) PWM Channel Duty Cycle Register   Reset Value */

#define PWM_CDTY_CDTY_Pos                     _UINT32_(0)                                          /* (PWM_CDTY) Channel Duty-Cycle Position */
#define PWM_CDTY_CDTY_Msk                     (_UINT32_(0xFFFFFF) << PWM_CDTY_CDTY_Pos)            /* (PWM_CDTY) Channel Duty-Cycle Mask */
#define PWM_CDTY_CDTY(value)                  (PWM_CDTY_CDTY_Msk & (_UINT32_(value) << PWM_CDTY_CDTY_Pos)) /* Assigment of value for CDTY in the PWM_CDTY register */
#define PWM_CDTY_Msk                          _UINT32_(0x00FFFFFF)                                 /* (PWM_CDTY) Register Mask  */


/* -------- PWM_CDTYUPD : (PWM Offset: 0x08) ( /W 32) PWM Channel Duty Cycle Update Register  -------- */
#define PWM_CDTYUPD_CDTYUPD_Pos               _UINT32_(0)                                          /* (PWM_CDTYUPD) Channel Duty-Cycle Update Position */
#define PWM_CDTYUPD_CDTYUPD_Msk               (_UINT32_(0xFFFFFF) << PWM_CDTYUPD_CDTYUPD_Pos)      /* (PWM_CDTYUPD) Channel Duty-Cycle Update Mask */
#define PWM_CDTYUPD_CDTYUPD(value)            (PWM_CDTYUPD_CDTYUPD_Msk & (_UINT32_(value) << PWM_CDTYUPD_CDTYUPD_Pos)) /* Assigment of value for CDTYUPD in the PWM_CDTYUPD register */
#define PWM_CDTYUPD_Msk                       _UINT32_(0x00FFFFFF)                                 /* (PWM_CDTYUPD) Register Mask  */


/* -------- PWM_CPRD : (PWM Offset: 0x0C) (R/W 32) PWM Channel Period Register  -------- */
#define PWM_CPRD_RESETVALUE                   _UINT32_(0x00)                                       /*  (PWM_CPRD) PWM Channel Period Register   Reset Value */

#define PWM_CPRD_CPRD_Pos                     _UINT32_(0)                                          /* (PWM_CPRD) Channel Period Position */
#define PWM_CPRD_CPRD_Msk                     (_UINT32_(0xFFFFFF) << PWM_CPRD_CPRD_Pos)            /* (PWM_CPRD) Channel Period Mask */
#define PWM_CPRD_CPRD(value)                  (PWM_CPRD_CPRD_Msk & (_UINT32_(value) << PWM_CPRD_CPRD_Pos)) /* Assigment of value for CPRD in the PWM_CPRD register */
#define PWM_CPRD_Msk                          _UINT32_(0x00FFFFFF)                                 /* (PWM_CPRD) Register Mask  */


/* -------- PWM_CPRDUPD : (PWM Offset: 0x10) ( /W 32) PWM Channel Period Update Register  -------- */
#define PWM_CPRDUPD_CPRDUPD_Pos               _UINT32_(0)                                          /* (PWM_CPRDUPD) Channel Period Update Position */
#define PWM_CPRDUPD_CPRDUPD_Msk               (_UINT32_(0xFFFFFF) << PWM_CPRDUPD_CPRDUPD_Pos)      /* (PWM_CPRDUPD) Channel Period Update Mask */
#define PWM_CPRDUPD_CPRDUPD(value)            (PWM_CPRDUPD_CPRDUPD_Msk & (_UINT32_(value) << PWM_CPRDUPD_CPRDUPD_Pos)) /* Assigment of value for CPRDUPD in the PWM_CPRDUPD register */
#define PWM_CPRDUPD_Msk                       _UINT32_(0x00FFFFFF)                                 /* (PWM_CPRDUPD) Register Mask  */


/* -------- PWM_CCNT : (PWM Offset: 0x14) ( R/ 32) PWM Channel Counter Register  -------- */
#define PWM_CCNT_RESETVALUE                   _UINT32_(0x00)                                       /*  (PWM_CCNT) PWM Channel Counter Register   Reset Value */

#define PWM_CCNT_CNT_Pos                      _UINT32_(0)                                          /* (PWM_CCNT) Channel Counter Register Position */
#define PWM_CCNT_CNT_Msk                      (_UINT32_(0xFFFFFF) << PWM_CCNT_CNT_Pos)             /* (PWM_CCNT) Channel Counter Register Mask */
#define PWM_CCNT_CNT(value)                   (PWM_CCNT_CNT_Msk & (_UINT32_(value) << PWM_CCNT_CNT_Pos)) /* Assigment of value for CNT in the PWM_CCNT register */
#define PWM_CCNT_Msk                          _UINT32_(0x00FFFFFF)                                 /* (PWM_CCNT) Register Mask  */


/* -------- PWM_DT : (PWM Offset: 0x18) (R/W 32) PWM Channel Dead Time Register  -------- */
#define PWM_DT_RESETVALUE                     _UINT32_(0x00)                                       /*  (PWM_DT) PWM Channel Dead Time Register   Reset Value */

#define PWM_DT_DTH_Pos                        _UINT32_(0)                                          /* (PWM_DT) Dead-Time Value for PWMHx Output Position */
#define PWM_DT_DTH_Msk                        (_UINT32_(0xFFFF) << PWM_DT_DTH_Pos)                 /* (PWM_DT) Dead-Time Value for PWMHx Output Mask */
#define PWM_DT_DTH(value)                     (PWM_DT_DTH_Msk & (_UINT32_(value) << PWM_DT_DTH_Pos)) /* Assigment of value for DTH in the PWM_DT register */
#define PWM_DT_DTL_Pos                        _UINT32_(16)                                         /* (PWM_DT) Dead-Time Value for PWMLx Output Position */
#define PWM_DT_DTL_Msk                        (_UINT32_(0xFFFF) << PWM_DT_DTL_Pos)                 /* (PWM_DT) Dead-Time Value for PWMLx Output Mask */
#define PWM_DT_DTL(value)                     (PWM_DT_DTL_Msk & (_UINT32_(value) << PWM_DT_DTL_Pos)) /* Assigment of value for DTL in the PWM_DT register */
#define PWM_DT_Msk                            _UINT32_(0xFFFFFFFF)                                 /* (PWM_DT) Register Mask  */


/* -------- PWM_DTUPD : (PWM Offset: 0x1C) ( /W 32) PWM Channel Dead Time Update Register  -------- */
#define PWM_DTUPD_DTHUPD_Pos                  _UINT32_(0)                                          /* (PWM_DTUPD) Dead-Time Value Update for PWMHx Output Position */
#define PWM_DTUPD_DTHUPD_Msk                  (_UINT32_(0xFFFF) << PWM_DTUPD_DTHUPD_Pos)           /* (PWM_DTUPD) Dead-Time Value Update for PWMHx Output Mask */
#define PWM_DTUPD_DTHUPD(value)               (PWM_DTUPD_DTHUPD_Msk & (_UINT32_(value) << PWM_DTUPD_DTHUPD_Pos)) /* Assigment of value for DTHUPD in the PWM_DTUPD register */
#define PWM_DTUPD_DTLUPD_Pos                  _UINT32_(16)                                         /* (PWM_DTUPD) Dead-Time Value Update for PWMLx Output Position */
#define PWM_DTUPD_DTLUPD_Msk                  (_UINT32_(0xFFFF) << PWM_DTUPD_DTLUPD_Pos)           /* (PWM_DTUPD) Dead-Time Value Update for PWMLx Output Mask */
#define PWM_DTUPD_DTLUPD(value)               (PWM_DTUPD_DTLUPD_Msk & (_UINT32_(value) << PWM_DTUPD_DTLUPD_Pos)) /* Assigment of value for DTLUPD in the PWM_DTUPD register */
#define PWM_DTUPD_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (PWM_DTUPD) Register Mask  */


/* -------- PWM_CMPV : (PWM Offset: 0x00) (R/W 32) PWM Comparison x Value Register -------- */
#define PWM_CMPV_RESETVALUE                   _UINT32_(0x00)                                       /*  (PWM_CMPV) PWM Comparison x Value Register  Reset Value */

#define PWM_CMPV_CV_Pos                       _UINT32_(0)                                          /* (PWM_CMPV) Comparison Value Position */
#define PWM_CMPV_CV_Msk                       (_UINT32_(0xFFFFFF) << PWM_CMPV_CV_Pos)              /* (PWM_CMPV) Comparison Value Mask */
#define PWM_CMPV_CV(value)                    (PWM_CMPV_CV_Msk & (_UINT32_(value) << PWM_CMPV_CV_Pos)) /* Assigment of value for CV in the PWM_CMPV register */
#define PWM_CMPV_CVM_Pos                      _UINT32_(24)                                         /* (PWM_CMPV) Comparison Value Mode Position */
#define PWM_CMPV_CVM_Msk                      (_UINT32_(0x1) << PWM_CMPV_CVM_Pos)                  /* (PWM_CMPV) Comparison Value Mode Mask */
#define PWM_CMPV_CVM(value)                   (PWM_CMPV_CVM_Msk & (_UINT32_(value) << PWM_CMPV_CVM_Pos)) /* Assigment of value for CVM in the PWM_CMPV register */
#define   PWM_CMPV_CVM_0_Val                  _UINT32_(0x0)                                        /* (PWM_CMPV) The comparison x between the counter of the channel 0 and the comparison x value is performed when this counter is incrementing.  */
#define   PWM_CMPV_CVM_1_Val                  _UINT32_(0x1)                                        /* (PWM_CMPV) The comparison x between the counter of the channel 0 and the comparison x value is performed when this counter is decrementing.  */
#define PWM_CMPV_CVM_0                        (PWM_CMPV_CVM_0_Val << PWM_CMPV_CVM_Pos)             /* (PWM_CMPV) The comparison x between the counter of the channel 0 and the comparison x value is performed when this counter is incrementing. Position  */
#define PWM_CMPV_CVM_1                        (PWM_CMPV_CVM_1_Val << PWM_CMPV_CVM_Pos)             /* (PWM_CMPV) The comparison x between the counter of the channel 0 and the comparison x value is performed when this counter is decrementing. Position  */
#define PWM_CMPV_Msk                          _UINT32_(0x01FFFFFF)                                 /* (PWM_CMPV) Register Mask  */


/* -------- PWM_CMPVUPD : (PWM Offset: 0x04) ( /W 32) PWM Comparison x Value Update Register -------- */
#define PWM_CMPVUPD_CVUPD_Pos                 _UINT32_(0)                                          /* (PWM_CMPVUPD) Comparison Value Update Position */
#define PWM_CMPVUPD_CVUPD_Msk                 (_UINT32_(0xFFFFFF) << PWM_CMPVUPD_CVUPD_Pos)        /* (PWM_CMPVUPD) Comparison Value Update Mask */
#define PWM_CMPVUPD_CVUPD(value)              (PWM_CMPVUPD_CVUPD_Msk & (_UINT32_(value) << PWM_CMPVUPD_CVUPD_Pos)) /* Assigment of value for CVUPD in the PWM_CMPVUPD register */
#define PWM_CMPVUPD_CVMUPD_Pos                _UINT32_(24)                                         /* (PWM_CMPVUPD) Comparison Value Mode Update Position */
#define PWM_CMPVUPD_CVMUPD_Msk                (_UINT32_(0x1) << PWM_CMPVUPD_CVMUPD_Pos)            /* (PWM_CMPVUPD) Comparison Value Mode Update Mask */
#define PWM_CMPVUPD_CVMUPD(value)             (PWM_CMPVUPD_CVMUPD_Msk & (_UINT32_(value) << PWM_CMPVUPD_CVMUPD_Pos)) /* Assigment of value for CVMUPD in the PWM_CMPVUPD register */
#define   PWM_CMPVUPD_CVMUPD_0_Val            _UINT32_(0x0)                                        /* (PWM_CMPVUPD) The comparison x between the counter of the channel 0 and the comparison x value is performed when this counter is incrementing.  */
#define   PWM_CMPVUPD_CVMUPD_1_Val            _UINT32_(0x1)                                        /* (PWM_CMPVUPD) The comparison x between the counter of the channel 0 and the comparison x value is performed when this counter is decrementing.  */
#define PWM_CMPVUPD_CVMUPD_0                  (PWM_CMPVUPD_CVMUPD_0_Val << PWM_CMPVUPD_CVMUPD_Pos) /* (PWM_CMPVUPD) The comparison x between the counter of the channel 0 and the comparison x value is performed when this counter is incrementing. Position  */
#define PWM_CMPVUPD_CVMUPD_1                  (PWM_CMPVUPD_CVMUPD_1_Val << PWM_CMPVUPD_CVMUPD_Pos) /* (PWM_CMPVUPD) The comparison x between the counter of the channel 0 and the comparison x value is performed when this counter is decrementing. Position  */
#define PWM_CMPVUPD_Msk                       _UINT32_(0x01FFFFFF)                                 /* (PWM_CMPVUPD) Register Mask  */


/* -------- PWM_CMPM : (PWM Offset: 0x08) (R/W 32) PWM Comparison x Mode Register -------- */
#define PWM_CMPM_RESETVALUE                   _UINT32_(0x00)                                       /*  (PWM_CMPM) PWM Comparison x Mode Register  Reset Value */

#define PWM_CMPM_CEN_Pos                      _UINT32_(0)                                          /* (PWM_CMPM) Comparison Enable Position */
#define PWM_CMPM_CEN_Msk                      (_UINT32_(0x1) << PWM_CMPM_CEN_Pos)                  /* (PWM_CMPM) Comparison Enable Mask */
#define PWM_CMPM_CEN(value)                   (PWM_CMPM_CEN_Msk & (_UINT32_(value) << PWM_CMPM_CEN_Pos)) /* Assigment of value for CEN in the PWM_CMPM register */
#define   PWM_CMPM_CEN_0_Val                  _UINT32_(0x0)                                        /* (PWM_CMPM) The comparison x is disabled and can not match.  */
#define   PWM_CMPM_CEN_1_Val                  _UINT32_(0x1)                                        /* (PWM_CMPM) The comparison x is enabled and can match.  */
#define PWM_CMPM_CEN_0                        (PWM_CMPM_CEN_0_Val << PWM_CMPM_CEN_Pos)             /* (PWM_CMPM) The comparison x is disabled and can not match. Position  */
#define PWM_CMPM_CEN_1                        (PWM_CMPM_CEN_1_Val << PWM_CMPM_CEN_Pos)             /* (PWM_CMPM) The comparison x is enabled and can match. Position  */
#define PWM_CMPM_CTR_Pos                      _UINT32_(4)                                          /* (PWM_CMPM) Comparison Trigger Position */
#define PWM_CMPM_CTR_Msk                      (_UINT32_(0xF) << PWM_CMPM_CTR_Pos)                  /* (PWM_CMPM) Comparison Trigger Mask */
#define PWM_CMPM_CTR(value)                   (PWM_CMPM_CTR_Msk & (_UINT32_(value) << PWM_CMPM_CTR_Pos)) /* Assigment of value for CTR in the PWM_CMPM register */
#define PWM_CMPM_CPR_Pos                      _UINT32_(8)                                          /* (PWM_CMPM) Comparison Period Position */
#define PWM_CMPM_CPR_Msk                      (_UINT32_(0xF) << PWM_CMPM_CPR_Pos)                  /* (PWM_CMPM) Comparison Period Mask */
#define PWM_CMPM_CPR(value)                   (PWM_CMPM_CPR_Msk & (_UINT32_(value) << PWM_CMPM_CPR_Pos)) /* Assigment of value for CPR in the PWM_CMPM register */
#define PWM_CMPM_CPRCNT_Pos                   _UINT32_(12)                                         /* (PWM_CMPM) Comparison Period Counter Position */
#define PWM_CMPM_CPRCNT_Msk                   (_UINT32_(0xF) << PWM_CMPM_CPRCNT_Pos)               /* (PWM_CMPM) Comparison Period Counter Mask */
#define PWM_CMPM_CPRCNT(value)                (PWM_CMPM_CPRCNT_Msk & (_UINT32_(value) << PWM_CMPM_CPRCNT_Pos)) /* Assigment of value for CPRCNT in the PWM_CMPM register */
#define PWM_CMPM_CUPR_Pos                     _UINT32_(16)                                         /* (PWM_CMPM) Comparison Update Period Position */
#define PWM_CMPM_CUPR_Msk                     (_UINT32_(0xF) << PWM_CMPM_CUPR_Pos)                 /* (PWM_CMPM) Comparison Update Period Mask */
#define PWM_CMPM_CUPR(value)                  (PWM_CMPM_CUPR_Msk & (_UINT32_(value) << PWM_CMPM_CUPR_Pos)) /* Assigment of value for CUPR in the PWM_CMPM register */
#define PWM_CMPM_CUPRCNT_Pos                  _UINT32_(20)                                         /* (PWM_CMPM) Comparison Update Period Counter Position */
#define PWM_CMPM_CUPRCNT_Msk                  (_UINT32_(0xF) << PWM_CMPM_CUPRCNT_Pos)              /* (PWM_CMPM) Comparison Update Period Counter Mask */
#define PWM_CMPM_CUPRCNT(value)               (PWM_CMPM_CUPRCNT_Msk & (_UINT32_(value) << PWM_CMPM_CUPRCNT_Pos)) /* Assigment of value for CUPRCNT in the PWM_CMPM register */
#define PWM_CMPM_Msk                          _UINT32_(0x00FFFFF1)                                 /* (PWM_CMPM) Register Mask  */


/* -------- PWM_CMPMUPD : (PWM Offset: 0x0C) ( /W 32) PWM Comparison x Mode Update Register -------- */
#define PWM_CMPMUPD_CENUPD_Pos                _UINT32_(0)                                          /* (PWM_CMPMUPD) Comparison Enable Update Position */
#define PWM_CMPMUPD_CENUPD_Msk                (_UINT32_(0x1) << PWM_CMPMUPD_CENUPD_Pos)            /* (PWM_CMPMUPD) Comparison Enable Update Mask */
#define PWM_CMPMUPD_CENUPD(value)             (PWM_CMPMUPD_CENUPD_Msk & (_UINT32_(value) << PWM_CMPMUPD_CENUPD_Pos)) /* Assigment of value for CENUPD in the PWM_CMPMUPD register */
#define   PWM_CMPMUPD_CENUPD_0_Val            _UINT32_(0x0)                                        /* (PWM_CMPMUPD) The comparison x is disabled and can not match.  */
#define   PWM_CMPMUPD_CENUPD_1_Val            _UINT32_(0x1)                                        /* (PWM_CMPMUPD) The comparison x is enabled and can match.  */
#define PWM_CMPMUPD_CENUPD_0                  (PWM_CMPMUPD_CENUPD_0_Val << PWM_CMPMUPD_CENUPD_Pos) /* (PWM_CMPMUPD) The comparison x is disabled and can not match. Position  */
#define PWM_CMPMUPD_CENUPD_1                  (PWM_CMPMUPD_CENUPD_1_Val << PWM_CMPMUPD_CENUPD_Pos) /* (PWM_CMPMUPD) The comparison x is enabled and can match. Position  */
#define PWM_CMPMUPD_CTRUPD_Pos                _UINT32_(4)                                          /* (PWM_CMPMUPD) Comparison Trigger Update Position */
#define PWM_CMPMUPD_CTRUPD_Msk                (_UINT32_(0xF) << PWM_CMPMUPD_CTRUPD_Pos)            /* (PWM_CMPMUPD) Comparison Trigger Update Mask */
#define PWM_CMPMUPD_CTRUPD(value)             (PWM_CMPMUPD_CTRUPD_Msk & (_UINT32_(value) << PWM_CMPMUPD_CTRUPD_Pos)) /* Assigment of value for CTRUPD in the PWM_CMPMUPD register */
#define PWM_CMPMUPD_CPRUPD_Pos                _UINT32_(8)                                          /* (PWM_CMPMUPD) Comparison Period Update Position */
#define PWM_CMPMUPD_CPRUPD_Msk                (_UINT32_(0xF) << PWM_CMPMUPD_CPRUPD_Pos)            /* (PWM_CMPMUPD) Comparison Period Update Mask */
#define PWM_CMPMUPD_CPRUPD(value)             (PWM_CMPMUPD_CPRUPD_Msk & (_UINT32_(value) << PWM_CMPMUPD_CPRUPD_Pos)) /* Assigment of value for CPRUPD in the PWM_CMPMUPD register */
#define PWM_CMPMUPD_CUPRUPD_Pos               _UINT32_(16)                                         /* (PWM_CMPMUPD) Comparison Update Period Update Position */
#define PWM_CMPMUPD_CUPRUPD_Msk               (_UINT32_(0xF) << PWM_CMPMUPD_CUPRUPD_Pos)           /* (PWM_CMPMUPD) Comparison Update Period Update Mask */
#define PWM_CMPMUPD_CUPRUPD(value)            (PWM_CMPMUPD_CUPRUPD_Msk & (_UINT32_(value) << PWM_CMPMUPD_CUPRUPD_Pos)) /* Assigment of value for CUPRUPD in the PWM_CMPMUPD register */
#define PWM_CMPMUPD_Msk                       _UINT32_(0x000F0FF1)                                 /* (PWM_CMPMUPD) Register Mask  */


/* -------- PWM_CLK : (PWM Offset: 0x00) (R/W 32) PWM Clock Register -------- */
#define PWM_CLK_RESETVALUE                    _UINT32_(0x00)                                       /*  (PWM_CLK) PWM Clock Register  Reset Value */

#define PWM_CLK_DIVA_Pos                      _UINT32_(0)                                          /* (PWM_CLK) CLKA Divide Factor Position */
#define PWM_CLK_DIVA_Msk                      (_UINT32_(0xFF) << PWM_CLK_DIVA_Pos)                 /* (PWM_CLK) CLKA Divide Factor Mask */
#define PWM_CLK_DIVA(value)                   (PWM_CLK_DIVA_Msk & (_UINT32_(value) << PWM_CLK_DIVA_Pos)) /* Assigment of value for DIVA in the PWM_CLK register */
#define   PWM_CLK_DIVA_CLKA_POFF_Val          _UINT32_(0x0)                                        /* (PWM_CLK) CLKA clock is turned off  */
#define   PWM_CLK_DIVA_PREA_Val               _UINT32_(0x1)                                        /* (PWM_CLK) CLKA clock is clock selected by PREA  */
#define PWM_CLK_DIVA_CLKA_POFF                (PWM_CLK_DIVA_CLKA_POFF_Val << PWM_CLK_DIVA_Pos)     /* (PWM_CLK) CLKA clock is turned off Position  */
#define PWM_CLK_DIVA_PREA                     (PWM_CLK_DIVA_PREA_Val << PWM_CLK_DIVA_Pos)          /* (PWM_CLK) CLKA clock is clock selected by PREA Position  */
#define PWM_CLK_PREA_Pos                      _UINT32_(8)                                          /* (PWM_CLK) CLKA Source Clock Selection Position */
#define PWM_CLK_PREA_Msk                      (_UINT32_(0xF) << PWM_CLK_PREA_Pos)                  /* (PWM_CLK) CLKA Source Clock Selection Mask */
#define PWM_CLK_PREA(value)                   (PWM_CLK_PREA_Msk & (_UINT32_(value) << PWM_CLK_PREA_Pos)) /* Assigment of value for PREA in the PWM_CLK register */
#define   PWM_CLK_PREA_CLK_Val                _UINT32_(0x0)                                        /* (PWM_CLK) Peripheral clock  */
#define   PWM_CLK_PREA_CLK_DIV2_Val           _UINT32_(0x1)                                        /* (PWM_CLK) Peripheral clock/2  */
#define   PWM_CLK_PREA_CLK_DIV4_Val           _UINT32_(0x2)                                        /* (PWM_CLK) Peripheral clock/4  */
#define   PWM_CLK_PREA_CLK_DIV8_Val           _UINT32_(0x3)                                        /* (PWM_CLK) Peripheral clock/8  */
#define   PWM_CLK_PREA_CLK_DIV16_Val          _UINT32_(0x4)                                        /* (PWM_CLK) Peripheral clock/16  */
#define   PWM_CLK_PREA_CLK_DIV32_Val          _UINT32_(0x5)                                        /* (PWM_CLK) Peripheral clock/32  */
#define   PWM_CLK_PREA_CLK_DIV64_Val          _UINT32_(0x6)                                        /* (PWM_CLK) Peripheral clock/64  */
#define   PWM_CLK_PREA_CLK_DIV128_Val         _UINT32_(0x7)                                        /* (PWM_CLK) Peripheral clock/128  */
#define   PWM_CLK_PREA_CLK_DIV256_Val         _UINT32_(0x8)                                        /* (PWM_CLK) Peripheral clock/256  */
#define   PWM_CLK_PREA_CLK_DIV512_Val         _UINT32_(0x9)                                        /* (PWM_CLK) Peripheral clock/512  */
#define   PWM_CLK_PREA_CLK_DIV1024_Val        _UINT32_(0xA)                                        /* (PWM_CLK) Peripheral clock/1024  */
#define PWM_CLK_PREA_CLK                      (PWM_CLK_PREA_CLK_Val << PWM_CLK_PREA_Pos)           /* (PWM_CLK) Peripheral clock Position  */
#define PWM_CLK_PREA_CLK_DIV2                 (PWM_CLK_PREA_CLK_DIV2_Val << PWM_CLK_PREA_Pos)      /* (PWM_CLK) Peripheral clock/2 Position  */
#define PWM_CLK_PREA_CLK_DIV4                 (PWM_CLK_PREA_CLK_DIV4_Val << PWM_CLK_PREA_Pos)      /* (PWM_CLK) Peripheral clock/4 Position  */
#define PWM_CLK_PREA_CLK_DIV8                 (PWM_CLK_PREA_CLK_DIV8_Val << PWM_CLK_PREA_Pos)      /* (PWM_CLK) Peripheral clock/8 Position  */
#define PWM_CLK_PREA_CLK_DIV16                (PWM_CLK_PREA_CLK_DIV16_Val << PWM_CLK_PREA_Pos)     /* (PWM_CLK) Peripheral clock/16 Position  */
#define PWM_CLK_PREA_CLK_DIV32                (PWM_CLK_PREA_CLK_DIV32_Val << PWM_CLK_PREA_Pos)     /* (PWM_CLK) Peripheral clock/32 Position  */
#define PWM_CLK_PREA_CLK_DIV64                (PWM_CLK_PREA_CLK_DIV64_Val << PWM_CLK_PREA_Pos)     /* (PWM_CLK) Peripheral clock/64 Position  */
#define PWM_CLK_PREA_CLK_DIV128               (PWM_CLK_PREA_CLK_DIV128_Val << PWM_CLK_PREA_Pos)    /* (PWM_CLK) Peripheral clock/128 Position  */
#define PWM_CLK_PREA_CLK_DIV256               (PWM_CLK_PREA_CLK_DIV256_Val << PWM_CLK_PREA_Pos)    /* (PWM_CLK) Peripheral clock/256 Position  */
#define PWM_CLK_PREA_CLK_DIV512               (PWM_CLK_PREA_CLK_DIV512_Val << PWM_CLK_PREA_Pos)    /* (PWM_CLK) Peripheral clock/512 Position  */
#define PWM_CLK_PREA_CLK_DIV1024              (PWM_CLK_PREA_CLK_DIV1024_Val << PWM_CLK_PREA_Pos)   /* (PWM_CLK) Peripheral clock/1024 Position  */
#define PWM_CLK_DIVB_Pos                      _UINT32_(16)                                         /* (PWM_CLK) CLKB Divide Factor Position */
#define PWM_CLK_DIVB_Msk                      (_UINT32_(0xFF) << PWM_CLK_DIVB_Pos)                 /* (PWM_CLK) CLKB Divide Factor Mask */
#define PWM_CLK_DIVB(value)                   (PWM_CLK_DIVB_Msk & (_UINT32_(value) << PWM_CLK_DIVB_Pos)) /* Assigment of value for DIVB in the PWM_CLK register */
#define   PWM_CLK_DIVB_CLKB_POFF_Val          _UINT32_(0x0)                                        /* (PWM_CLK) CLKB clock is turned off  */
#define   PWM_CLK_DIVB_PREB_Val               _UINT32_(0x1)                                        /* (PWM_CLK) CLKB clock is clock selected by PREB  */
#define PWM_CLK_DIVB_CLKB_POFF                (PWM_CLK_DIVB_CLKB_POFF_Val << PWM_CLK_DIVB_Pos)     /* (PWM_CLK) CLKB clock is turned off Position  */
#define PWM_CLK_DIVB_PREB                     (PWM_CLK_DIVB_PREB_Val << PWM_CLK_DIVB_Pos)          /* (PWM_CLK) CLKB clock is clock selected by PREB Position  */
#define PWM_CLK_PREB_Pos                      _UINT32_(24)                                         /* (PWM_CLK) CLKB Source Clock Selection Position */
#define PWM_CLK_PREB_Msk                      (_UINT32_(0xF) << PWM_CLK_PREB_Pos)                  /* (PWM_CLK) CLKB Source Clock Selection Mask */
#define PWM_CLK_PREB(value)                   (PWM_CLK_PREB_Msk & (_UINT32_(value) << PWM_CLK_PREB_Pos)) /* Assigment of value for PREB in the PWM_CLK register */
#define   PWM_CLK_PREB_CLK_Val                _UINT32_(0x0)                                        /* (PWM_CLK) Peripheral clock  */
#define   PWM_CLK_PREB_CLK_DIV2_Val           _UINT32_(0x1)                                        /* (PWM_CLK) Peripheral clock/2  */
#define   PWM_CLK_PREB_CLK_DIV4_Val           _UINT32_(0x2)                                        /* (PWM_CLK) Peripheral clock/4  */
#define   PWM_CLK_PREB_CLK_DIV8_Val           _UINT32_(0x3)                                        /* (PWM_CLK) Peripheral clock/8  */
#define   PWM_CLK_PREB_CLK_DIV16_Val          _UINT32_(0x4)                                        /* (PWM_CLK) Peripheral clock/16  */
#define   PWM_CLK_PREB_CLK_DIV32_Val          _UINT32_(0x5)                                        /* (PWM_CLK) Peripheral clock/32  */
#define   PWM_CLK_PREB_CLK_DIV64_Val          _UINT32_(0x6)                                        /* (PWM_CLK) Peripheral clock/64  */
#define   PWM_CLK_PREB_CLK_DIV128_Val         _UINT32_(0x7)                                        /* (PWM_CLK) Peripheral clock/128  */
#define   PWM_CLK_PREB_CLK_DIV256_Val         _UINT32_(0x8)                                        /* (PWM_CLK) Peripheral clock/256  */
#define   PWM_CLK_PREB_CLK_DIV512_Val         _UINT32_(0x9)                                        /* (PWM_CLK) Peripheral clock/512  */
#define   PWM_CLK_PREB_CLK_DIV1024_Val        _UINT32_(0xA)                                        /* (PWM_CLK) Peripheral clock/1024  */
#define PWM_CLK_PREB_CLK                      (PWM_CLK_PREB_CLK_Val << PWM_CLK_PREB_Pos)           /* (PWM_CLK) Peripheral clock Position  */
#define PWM_CLK_PREB_CLK_DIV2                 (PWM_CLK_PREB_CLK_DIV2_Val << PWM_CLK_PREB_Pos)      /* (PWM_CLK) Peripheral clock/2 Position  */
#define PWM_CLK_PREB_CLK_DIV4                 (PWM_CLK_PREB_CLK_DIV4_Val << PWM_CLK_PREB_Pos)      /* (PWM_CLK) Peripheral clock/4 Position  */
#define PWM_CLK_PREB_CLK_DIV8                 (PWM_CLK_PREB_CLK_DIV8_Val << PWM_CLK_PREB_Pos)      /* (PWM_CLK) Peripheral clock/8 Position  */
#define PWM_CLK_PREB_CLK_DIV16                (PWM_CLK_PREB_CLK_DIV16_Val << PWM_CLK_PREB_Pos)     /* (PWM_CLK) Peripheral clock/16 Position  */
#define PWM_CLK_PREB_CLK_DIV32                (PWM_CLK_PREB_CLK_DIV32_Val << PWM_CLK_PREB_Pos)     /* (PWM_CLK) Peripheral clock/32 Position  */
#define PWM_CLK_PREB_CLK_DIV64                (PWM_CLK_PREB_CLK_DIV64_Val << PWM_CLK_PREB_Pos)     /* (PWM_CLK) Peripheral clock/64 Position  */
#define PWM_CLK_PREB_CLK_DIV128               (PWM_CLK_PREB_CLK_DIV128_Val << PWM_CLK_PREB_Pos)    /* (PWM_CLK) Peripheral clock/128 Position  */
#define PWM_CLK_PREB_CLK_DIV256               (PWM_CLK_PREB_CLK_DIV256_Val << PWM_CLK_PREB_Pos)    /* (PWM_CLK) Peripheral clock/256 Position  */
#define PWM_CLK_PREB_CLK_DIV512               (PWM_CLK_PREB_CLK_DIV512_Val << PWM_CLK_PREB_Pos)    /* (PWM_CLK) Peripheral clock/512 Position  */
#define PWM_CLK_PREB_CLK_DIV1024              (PWM_CLK_PREB_CLK_DIV1024_Val << PWM_CLK_PREB_Pos)   /* (PWM_CLK) Peripheral clock/1024 Position  */
#define PWM_CLK_Msk                           _UINT32_(0x0FFF0FFF)                                 /* (PWM_CLK) Register Mask  */


/* -------- PWM_ENA : (PWM Offset: 0x04) ( /W 32) PWM Enable Register -------- */
#define PWM_ENA_CHID0_Pos                     _UINT32_(0)                                          /* (PWM_ENA) Channel ID Position */
#define PWM_ENA_CHID0_Msk                     (_UINT32_(0x1) << PWM_ENA_CHID0_Pos)                 /* (PWM_ENA) Channel ID Mask */
#define PWM_ENA_CHID0(value)                  (PWM_ENA_CHID0_Msk & (_UINT32_(value) << PWM_ENA_CHID0_Pos)) /* Assigment of value for CHID0 in the PWM_ENA register */
#define   PWM_ENA_CHID0_0_Val                 _UINT32_(0x0)                                        /* (PWM_ENA) No effect.  */
#define   PWM_ENA_CHID0_1_Val                 _UINT32_(0x1)                                        /* (PWM_ENA) Enable PWM output for channel x.  */
#define PWM_ENA_CHID0_0                       (PWM_ENA_CHID0_0_Val << PWM_ENA_CHID0_Pos)           /* (PWM_ENA) No effect. Position  */
#define PWM_ENA_CHID0_1                       (PWM_ENA_CHID0_1_Val << PWM_ENA_CHID0_Pos)           /* (PWM_ENA) Enable PWM output for channel x. Position  */
#define PWM_ENA_CHID1_Pos                     _UINT32_(1)                                          /* (PWM_ENA) Channel ID Position */
#define PWM_ENA_CHID1_Msk                     (_UINT32_(0x1) << PWM_ENA_CHID1_Pos)                 /* (PWM_ENA) Channel ID Mask */
#define PWM_ENA_CHID1(value)                  (PWM_ENA_CHID1_Msk & (_UINT32_(value) << PWM_ENA_CHID1_Pos)) /* Assigment of value for CHID1 in the PWM_ENA register */
#define   PWM_ENA_CHID1_0_Val                 _UINT32_(0x0)                                        /* (PWM_ENA) No effect.  */
#define   PWM_ENA_CHID1_1_Val                 _UINT32_(0x1)                                        /* (PWM_ENA) Enable PWM output for channel x.  */
#define PWM_ENA_CHID1_0                       (PWM_ENA_CHID1_0_Val << PWM_ENA_CHID1_Pos)           /* (PWM_ENA) No effect. Position  */
#define PWM_ENA_CHID1_1                       (PWM_ENA_CHID1_1_Val << PWM_ENA_CHID1_Pos)           /* (PWM_ENA) Enable PWM output for channel x. Position  */
#define PWM_ENA_CHID2_Pos                     _UINT32_(2)                                          /* (PWM_ENA) Channel ID Position */
#define PWM_ENA_CHID2_Msk                     (_UINT32_(0x1) << PWM_ENA_CHID2_Pos)                 /* (PWM_ENA) Channel ID Mask */
#define PWM_ENA_CHID2(value)                  (PWM_ENA_CHID2_Msk & (_UINT32_(value) << PWM_ENA_CHID2_Pos)) /* Assigment of value for CHID2 in the PWM_ENA register */
#define   PWM_ENA_CHID2_0_Val                 _UINT32_(0x0)                                        /* (PWM_ENA) No effect.  */
#define   PWM_ENA_CHID2_1_Val                 _UINT32_(0x1)                                        /* (PWM_ENA) Enable PWM output for channel x.  */
#define PWM_ENA_CHID2_0                       (PWM_ENA_CHID2_0_Val << PWM_ENA_CHID2_Pos)           /* (PWM_ENA) No effect. Position  */
#define PWM_ENA_CHID2_1                       (PWM_ENA_CHID2_1_Val << PWM_ENA_CHID2_Pos)           /* (PWM_ENA) Enable PWM output for channel x. Position  */
#define PWM_ENA_CHID3_Pos                     _UINT32_(3)                                          /* (PWM_ENA) Channel ID Position */
#define PWM_ENA_CHID3_Msk                     (_UINT32_(0x1) << PWM_ENA_CHID3_Pos)                 /* (PWM_ENA) Channel ID Mask */
#define PWM_ENA_CHID3(value)                  (PWM_ENA_CHID3_Msk & (_UINT32_(value) << PWM_ENA_CHID3_Pos)) /* Assigment of value for CHID3 in the PWM_ENA register */
#define   PWM_ENA_CHID3_0_Val                 _UINT32_(0x0)                                        /* (PWM_ENA) No effect.  */
#define   PWM_ENA_CHID3_1_Val                 _UINT32_(0x1)                                        /* (PWM_ENA) Enable PWM output for channel x.  */
#define PWM_ENA_CHID3_0                       (PWM_ENA_CHID3_0_Val << PWM_ENA_CHID3_Pos)           /* (PWM_ENA) No effect. Position  */
#define PWM_ENA_CHID3_1                       (PWM_ENA_CHID3_1_Val << PWM_ENA_CHID3_Pos)           /* (PWM_ENA) Enable PWM output for channel x. Position  */
#define PWM_ENA_Msk                           _UINT32_(0x0000000F)                                 /* (PWM_ENA) Register Mask  */

#define PWM_ENA_CHID_Pos                      _UINT32_(0)                                          /* (PWM_ENA Position) Channel ID */
#define PWM_ENA_CHID_Msk                      (_UINT32_(0xF) << PWM_ENA_CHID_Pos)                  /* (PWM_ENA Mask) CHID */
#define PWM_ENA_CHID(value)                   (PWM_ENA_CHID_Msk & (_UINT32_(value) << PWM_ENA_CHID_Pos)) 

/* -------- PWM_DIS : (PWM Offset: 0x08) ( /W 32) PWM Disable Register -------- */
#define PWM_DIS_CHID0_Pos                     _UINT32_(0)                                          /* (PWM_DIS) Channel ID Position */
#define PWM_DIS_CHID0_Msk                     (_UINT32_(0x1) << PWM_DIS_CHID0_Pos)                 /* (PWM_DIS) Channel ID Mask */
#define PWM_DIS_CHID0(value)                  (PWM_DIS_CHID0_Msk & (_UINT32_(value) << PWM_DIS_CHID0_Pos)) /* Assigment of value for CHID0 in the PWM_DIS register */
#define   PWM_DIS_CHID0_0_Val                 _UINT32_(0x0)                                        /* (PWM_DIS) No effect.  */
#define   PWM_DIS_CHID0_1_Val                 _UINT32_(0x1)                                        /* (PWM_DIS) Disable PWM output for channel x.  */
#define PWM_DIS_CHID0_0                       (PWM_DIS_CHID0_0_Val << PWM_DIS_CHID0_Pos)           /* (PWM_DIS) No effect. Position  */
#define PWM_DIS_CHID0_1                       (PWM_DIS_CHID0_1_Val << PWM_DIS_CHID0_Pos)           /* (PWM_DIS) Disable PWM output for channel x. Position  */
#define PWM_DIS_CHID1_Pos                     _UINT32_(1)                                          /* (PWM_DIS) Channel ID Position */
#define PWM_DIS_CHID1_Msk                     (_UINT32_(0x1) << PWM_DIS_CHID1_Pos)                 /* (PWM_DIS) Channel ID Mask */
#define PWM_DIS_CHID1(value)                  (PWM_DIS_CHID1_Msk & (_UINT32_(value) << PWM_DIS_CHID1_Pos)) /* Assigment of value for CHID1 in the PWM_DIS register */
#define   PWM_DIS_CHID1_0_Val                 _UINT32_(0x0)                                        /* (PWM_DIS) No effect.  */
#define   PWM_DIS_CHID1_1_Val                 _UINT32_(0x1)                                        /* (PWM_DIS) Disable PWM output for channel x.  */
#define PWM_DIS_CHID1_0                       (PWM_DIS_CHID1_0_Val << PWM_DIS_CHID1_Pos)           /* (PWM_DIS) No effect. Position  */
#define PWM_DIS_CHID1_1                       (PWM_DIS_CHID1_1_Val << PWM_DIS_CHID1_Pos)           /* (PWM_DIS) Disable PWM output for channel x. Position  */
#define PWM_DIS_CHID2_Pos                     _UINT32_(2)                                          /* (PWM_DIS) Channel ID Position */
#define PWM_DIS_CHID2_Msk                     (_UINT32_(0x1) << PWM_DIS_CHID2_Pos)                 /* (PWM_DIS) Channel ID Mask */
#define PWM_DIS_CHID2(value)                  (PWM_DIS_CHID2_Msk & (_UINT32_(value) << PWM_DIS_CHID2_Pos)) /* Assigment of value for CHID2 in the PWM_DIS register */
#define   PWM_DIS_CHID2_0_Val                 _UINT32_(0x0)                                        /* (PWM_DIS) No effect.  */
#define   PWM_DIS_CHID2_1_Val                 _UINT32_(0x1)                                        /* (PWM_DIS) Disable PWM output for channel x.  */
#define PWM_DIS_CHID2_0                       (PWM_DIS_CHID2_0_Val << PWM_DIS_CHID2_Pos)           /* (PWM_DIS) No effect. Position  */
#define PWM_DIS_CHID2_1                       (PWM_DIS_CHID2_1_Val << PWM_DIS_CHID2_Pos)           /* (PWM_DIS) Disable PWM output for channel x. Position  */
#define PWM_DIS_CHID3_Pos                     _UINT32_(3)                                          /* (PWM_DIS) Channel ID Position */
#define PWM_DIS_CHID3_Msk                     (_UINT32_(0x1) << PWM_DIS_CHID3_Pos)                 /* (PWM_DIS) Channel ID Mask */
#define PWM_DIS_CHID3(value)                  (PWM_DIS_CHID3_Msk & (_UINT32_(value) << PWM_DIS_CHID3_Pos)) /* Assigment of value for CHID3 in the PWM_DIS register */
#define   PWM_DIS_CHID3_0_Val                 _UINT32_(0x0)                                        /* (PWM_DIS) No effect.  */
#define   PWM_DIS_CHID3_1_Val                 _UINT32_(0x1)                                        /* (PWM_DIS) Disable PWM output for channel x.  */
#define PWM_DIS_CHID3_0                       (PWM_DIS_CHID3_0_Val << PWM_DIS_CHID3_Pos)           /* (PWM_DIS) No effect. Position  */
#define PWM_DIS_CHID3_1                       (PWM_DIS_CHID3_1_Val << PWM_DIS_CHID3_Pos)           /* (PWM_DIS) Disable PWM output for channel x. Position  */
#define PWM_DIS_Msk                           _UINT32_(0x0000000F)                                 /* (PWM_DIS) Register Mask  */

#define PWM_DIS_CHID_Pos                      _UINT32_(0)                                          /* (PWM_DIS Position) Channel ID */
#define PWM_DIS_CHID_Msk                      (_UINT32_(0xF) << PWM_DIS_CHID_Pos)                  /* (PWM_DIS Mask) CHID */
#define PWM_DIS_CHID(value)                   (PWM_DIS_CHID_Msk & (_UINT32_(value) << PWM_DIS_CHID_Pos)) 

/* -------- PWM_SR : (PWM Offset: 0x0C) ( R/ 32) PWM Status Register -------- */
#define PWM_SR_RESETVALUE                     _UINT32_(0x00)                                       /*  (PWM_SR) PWM Status Register  Reset Value */

#define PWM_SR_CHID0_Pos                      _UINT32_(0)                                          /* (PWM_SR) Channel ID Position */
#define PWM_SR_CHID0_Msk                      (_UINT32_(0x1) << PWM_SR_CHID0_Pos)                  /* (PWM_SR) Channel ID Mask */
#define PWM_SR_CHID0(value)                   (PWM_SR_CHID0_Msk & (_UINT32_(value) << PWM_SR_CHID0_Pos)) /* Assigment of value for CHID0 in the PWM_SR register */
#define   PWM_SR_CHID0_0_Val                  _UINT32_(0x0)                                        /* (PWM_SR) PWM output for channel x is disabled.  */
#define   PWM_SR_CHID0_1_Val                  _UINT32_(0x1)                                        /* (PWM_SR) PWM output for channel x is enabled.  */
#define PWM_SR_CHID0_0                        (PWM_SR_CHID0_0_Val << PWM_SR_CHID0_Pos)             /* (PWM_SR) PWM output for channel x is disabled. Position  */
#define PWM_SR_CHID0_1                        (PWM_SR_CHID0_1_Val << PWM_SR_CHID0_Pos)             /* (PWM_SR) PWM output for channel x is enabled. Position  */
#define PWM_SR_CHID1_Pos                      _UINT32_(1)                                          /* (PWM_SR) Channel ID Position */
#define PWM_SR_CHID1_Msk                      (_UINT32_(0x1) << PWM_SR_CHID1_Pos)                  /* (PWM_SR) Channel ID Mask */
#define PWM_SR_CHID1(value)                   (PWM_SR_CHID1_Msk & (_UINT32_(value) << PWM_SR_CHID1_Pos)) /* Assigment of value for CHID1 in the PWM_SR register */
#define   PWM_SR_CHID1_0_Val                  _UINT32_(0x0)                                        /* (PWM_SR) PWM output for channel x is disabled.  */
#define   PWM_SR_CHID1_1_Val                  _UINT32_(0x1)                                        /* (PWM_SR) PWM output for channel x is enabled.  */
#define PWM_SR_CHID1_0                        (PWM_SR_CHID1_0_Val << PWM_SR_CHID1_Pos)             /* (PWM_SR) PWM output for channel x is disabled. Position  */
#define PWM_SR_CHID1_1                        (PWM_SR_CHID1_1_Val << PWM_SR_CHID1_Pos)             /* (PWM_SR) PWM output for channel x is enabled. Position  */
#define PWM_SR_CHID2_Pos                      _UINT32_(2)                                          /* (PWM_SR) Channel ID Position */
#define PWM_SR_CHID2_Msk                      (_UINT32_(0x1) << PWM_SR_CHID2_Pos)                  /* (PWM_SR) Channel ID Mask */
#define PWM_SR_CHID2(value)                   (PWM_SR_CHID2_Msk & (_UINT32_(value) << PWM_SR_CHID2_Pos)) /* Assigment of value for CHID2 in the PWM_SR register */
#define   PWM_SR_CHID2_0_Val                  _UINT32_(0x0)                                        /* (PWM_SR) PWM output for channel x is disabled.  */
#define   PWM_SR_CHID2_1_Val                  _UINT32_(0x1)                                        /* (PWM_SR) PWM output for channel x is enabled.  */
#define PWM_SR_CHID2_0                        (PWM_SR_CHID2_0_Val << PWM_SR_CHID2_Pos)             /* (PWM_SR) PWM output for channel x is disabled. Position  */
#define PWM_SR_CHID2_1                        (PWM_SR_CHID2_1_Val << PWM_SR_CHID2_Pos)             /* (PWM_SR) PWM output for channel x is enabled. Position  */
#define PWM_SR_CHID3_Pos                      _UINT32_(3)                                          /* (PWM_SR) Channel ID Position */
#define PWM_SR_CHID3_Msk                      (_UINT32_(0x1) << PWM_SR_CHID3_Pos)                  /* (PWM_SR) Channel ID Mask */
#define PWM_SR_CHID3(value)                   (PWM_SR_CHID3_Msk & (_UINT32_(value) << PWM_SR_CHID3_Pos)) /* Assigment of value for CHID3 in the PWM_SR register */
#define   PWM_SR_CHID3_0_Val                  _UINT32_(0x0)                                        /* (PWM_SR) PWM output for channel x is disabled.  */
#define   PWM_SR_CHID3_1_Val                  _UINT32_(0x1)                                        /* (PWM_SR) PWM output for channel x is enabled.  */
#define PWM_SR_CHID3_0                        (PWM_SR_CHID3_0_Val << PWM_SR_CHID3_Pos)             /* (PWM_SR) PWM output for channel x is disabled. Position  */
#define PWM_SR_CHID3_1                        (PWM_SR_CHID3_1_Val << PWM_SR_CHID3_Pos)             /* (PWM_SR) PWM output for channel x is enabled. Position  */
#define PWM_SR_Msk                            _UINT32_(0x0000000F)                                 /* (PWM_SR) Register Mask  */

#define PWM_SR_CHID_Pos                       _UINT32_(0)                                          /* (PWM_SR Position) Channel ID */
#define PWM_SR_CHID_Msk                       (_UINT32_(0xF) << PWM_SR_CHID_Pos)                   /* (PWM_SR Mask) CHID */
#define PWM_SR_CHID(value)                    (PWM_SR_CHID_Msk & (_UINT32_(value) << PWM_SR_CHID_Pos)) 

/* -------- PWM_IER1 : (PWM Offset: 0x10) ( /W 32) PWM Interrupt Enable Register 1 -------- */
#define PWM_IER1_CHID0_Pos                    _UINT32_(0)                                          /* (PWM_IER1) Counter Event on Channel 0 Interrupt Enable Position */
#define PWM_IER1_CHID0_Msk                    (_UINT32_(0x1) << PWM_IER1_CHID0_Pos)                /* (PWM_IER1) Counter Event on Channel 0 Interrupt Enable Mask */
#define PWM_IER1_CHID0(value)                 (PWM_IER1_CHID0_Msk & (_UINT32_(value) << PWM_IER1_CHID0_Pos)) /* Assigment of value for CHID0 in the PWM_IER1 register */
#define PWM_IER1_CHID1_Pos                    _UINT32_(1)                                          /* (PWM_IER1) Counter Event on Channel 1 Interrupt Enable Position */
#define PWM_IER1_CHID1_Msk                    (_UINT32_(0x1) << PWM_IER1_CHID1_Pos)                /* (PWM_IER1) Counter Event on Channel 1 Interrupt Enable Mask */
#define PWM_IER1_CHID1(value)                 (PWM_IER1_CHID1_Msk & (_UINT32_(value) << PWM_IER1_CHID1_Pos)) /* Assigment of value for CHID1 in the PWM_IER1 register */
#define PWM_IER1_CHID2_Pos                    _UINT32_(2)                                          /* (PWM_IER1) Counter Event on Channel 2 Interrupt Enable Position */
#define PWM_IER1_CHID2_Msk                    (_UINT32_(0x1) << PWM_IER1_CHID2_Pos)                /* (PWM_IER1) Counter Event on Channel 2 Interrupt Enable Mask */
#define PWM_IER1_CHID2(value)                 (PWM_IER1_CHID2_Msk & (_UINT32_(value) << PWM_IER1_CHID2_Pos)) /* Assigment of value for CHID2 in the PWM_IER1 register */
#define PWM_IER1_CHID3_Pos                    _UINT32_(3)                                          /* (PWM_IER1) Counter Event on Channel 3 Interrupt Enable Position */
#define PWM_IER1_CHID3_Msk                    (_UINT32_(0x1) << PWM_IER1_CHID3_Pos)                /* (PWM_IER1) Counter Event on Channel 3 Interrupt Enable Mask */
#define PWM_IER1_CHID3(value)                 (PWM_IER1_CHID3_Msk & (_UINT32_(value) << PWM_IER1_CHID3_Pos)) /* Assigment of value for CHID3 in the PWM_IER1 register */
#define PWM_IER1_FCHID0_Pos                   _UINT32_(16)                                         /* (PWM_IER1) Fault Protection Trigger on Channel 0 Interrupt Enable Position */
#define PWM_IER1_FCHID0_Msk                   (_UINT32_(0x1) << PWM_IER1_FCHID0_Pos)               /* (PWM_IER1) Fault Protection Trigger on Channel 0 Interrupt Enable Mask */
#define PWM_IER1_FCHID0(value)                (PWM_IER1_FCHID0_Msk & (_UINT32_(value) << PWM_IER1_FCHID0_Pos)) /* Assigment of value for FCHID0 in the PWM_IER1 register */
#define PWM_IER1_FCHID1_Pos                   _UINT32_(17)                                         /* (PWM_IER1) Fault Protection Trigger on Channel 1 Interrupt Enable Position */
#define PWM_IER1_FCHID1_Msk                   (_UINT32_(0x1) << PWM_IER1_FCHID1_Pos)               /* (PWM_IER1) Fault Protection Trigger on Channel 1 Interrupt Enable Mask */
#define PWM_IER1_FCHID1(value)                (PWM_IER1_FCHID1_Msk & (_UINT32_(value) << PWM_IER1_FCHID1_Pos)) /* Assigment of value for FCHID1 in the PWM_IER1 register */
#define PWM_IER1_FCHID2_Pos                   _UINT32_(18)                                         /* (PWM_IER1) Fault Protection Trigger on Channel 2 Interrupt Enable Position */
#define PWM_IER1_FCHID2_Msk                   (_UINT32_(0x1) << PWM_IER1_FCHID2_Pos)               /* (PWM_IER1) Fault Protection Trigger on Channel 2 Interrupt Enable Mask */
#define PWM_IER1_FCHID2(value)                (PWM_IER1_FCHID2_Msk & (_UINT32_(value) << PWM_IER1_FCHID2_Pos)) /* Assigment of value for FCHID2 in the PWM_IER1 register */
#define PWM_IER1_FCHID3_Pos                   _UINT32_(19)                                         /* (PWM_IER1) Fault Protection Trigger on Channel 3 Interrupt Enable Position */
#define PWM_IER1_FCHID3_Msk                   (_UINT32_(0x1) << PWM_IER1_FCHID3_Pos)               /* (PWM_IER1) Fault Protection Trigger on Channel 3 Interrupt Enable Mask */
#define PWM_IER1_FCHID3(value)                (PWM_IER1_FCHID3_Msk & (_UINT32_(value) << PWM_IER1_FCHID3_Pos)) /* Assigment of value for FCHID3 in the PWM_IER1 register */
#define PWM_IER1_Msk                          _UINT32_(0x000F000F)                                 /* (PWM_IER1) Register Mask  */

#define PWM_IER1_CHID_Pos                     _UINT32_(0)                                          /* (PWM_IER1 Position) Counter Event on Channel x Interrupt Enable */
#define PWM_IER1_CHID_Msk                     (_UINT32_(0xF) << PWM_IER1_CHID_Pos)                 /* (PWM_IER1 Mask) CHID */
#define PWM_IER1_CHID(value)                  (PWM_IER1_CHID_Msk & (_UINT32_(value) << PWM_IER1_CHID_Pos)) 
#define PWM_IER1_FCHID_Pos                    _UINT32_(16)                                         /* (PWM_IER1 Position) Fault Protection Trigger on Channel 3 Interrupt Enable */
#define PWM_IER1_FCHID_Msk                    (_UINT32_(0xF) << PWM_IER1_FCHID_Pos)                /* (PWM_IER1 Mask) FCHID */
#define PWM_IER1_FCHID(value)                 (PWM_IER1_FCHID_Msk & (_UINT32_(value) << PWM_IER1_FCHID_Pos)) 

/* -------- PWM_IDR1 : (PWM Offset: 0x14) ( /W 32) PWM Interrupt Disable Register 1 -------- */
#define PWM_IDR1_CHID0_Pos                    _UINT32_(0)                                          /* (PWM_IDR1) Counter Event on Channel 0 Interrupt Disable Position */
#define PWM_IDR1_CHID0_Msk                    (_UINT32_(0x1) << PWM_IDR1_CHID0_Pos)                /* (PWM_IDR1) Counter Event on Channel 0 Interrupt Disable Mask */
#define PWM_IDR1_CHID0(value)                 (PWM_IDR1_CHID0_Msk & (_UINT32_(value) << PWM_IDR1_CHID0_Pos)) /* Assigment of value for CHID0 in the PWM_IDR1 register */
#define PWM_IDR1_CHID1_Pos                    _UINT32_(1)                                          /* (PWM_IDR1) Counter Event on Channel 1 Interrupt Disable Position */
#define PWM_IDR1_CHID1_Msk                    (_UINT32_(0x1) << PWM_IDR1_CHID1_Pos)                /* (PWM_IDR1) Counter Event on Channel 1 Interrupt Disable Mask */
#define PWM_IDR1_CHID1(value)                 (PWM_IDR1_CHID1_Msk & (_UINT32_(value) << PWM_IDR1_CHID1_Pos)) /* Assigment of value for CHID1 in the PWM_IDR1 register */
#define PWM_IDR1_CHID2_Pos                    _UINT32_(2)                                          /* (PWM_IDR1) Counter Event on Channel 2 Interrupt Disable Position */
#define PWM_IDR1_CHID2_Msk                    (_UINT32_(0x1) << PWM_IDR1_CHID2_Pos)                /* (PWM_IDR1) Counter Event on Channel 2 Interrupt Disable Mask */
#define PWM_IDR1_CHID2(value)                 (PWM_IDR1_CHID2_Msk & (_UINT32_(value) << PWM_IDR1_CHID2_Pos)) /* Assigment of value for CHID2 in the PWM_IDR1 register */
#define PWM_IDR1_CHID3_Pos                    _UINT32_(3)                                          /* (PWM_IDR1) Counter Event on Channel 3 Interrupt Disable Position */
#define PWM_IDR1_CHID3_Msk                    (_UINT32_(0x1) << PWM_IDR1_CHID3_Pos)                /* (PWM_IDR1) Counter Event on Channel 3 Interrupt Disable Mask */
#define PWM_IDR1_CHID3(value)                 (PWM_IDR1_CHID3_Msk & (_UINT32_(value) << PWM_IDR1_CHID3_Pos)) /* Assigment of value for CHID3 in the PWM_IDR1 register */
#define PWM_IDR1_FCHID0_Pos                   _UINT32_(16)                                         /* (PWM_IDR1) Fault Protection Trigger on Channel 0 Interrupt Disable Position */
#define PWM_IDR1_FCHID0_Msk                   (_UINT32_(0x1) << PWM_IDR1_FCHID0_Pos)               /* (PWM_IDR1) Fault Protection Trigger on Channel 0 Interrupt Disable Mask */
#define PWM_IDR1_FCHID0(value)                (PWM_IDR1_FCHID0_Msk & (_UINT32_(value) << PWM_IDR1_FCHID0_Pos)) /* Assigment of value for FCHID0 in the PWM_IDR1 register */
#define PWM_IDR1_FCHID1_Pos                   _UINT32_(17)                                         /* (PWM_IDR1) Fault Protection Trigger on Channel 1 Interrupt Disable Position */
#define PWM_IDR1_FCHID1_Msk                   (_UINT32_(0x1) << PWM_IDR1_FCHID1_Pos)               /* (PWM_IDR1) Fault Protection Trigger on Channel 1 Interrupt Disable Mask */
#define PWM_IDR1_FCHID1(value)                (PWM_IDR1_FCHID1_Msk & (_UINT32_(value) << PWM_IDR1_FCHID1_Pos)) /* Assigment of value for FCHID1 in the PWM_IDR1 register */
#define PWM_IDR1_FCHID2_Pos                   _UINT32_(18)                                         /* (PWM_IDR1) Fault Protection Trigger on Channel 2 Interrupt Disable Position */
#define PWM_IDR1_FCHID2_Msk                   (_UINT32_(0x1) << PWM_IDR1_FCHID2_Pos)               /* (PWM_IDR1) Fault Protection Trigger on Channel 2 Interrupt Disable Mask */
#define PWM_IDR1_FCHID2(value)                (PWM_IDR1_FCHID2_Msk & (_UINT32_(value) << PWM_IDR1_FCHID2_Pos)) /* Assigment of value for FCHID2 in the PWM_IDR1 register */
#define PWM_IDR1_FCHID3_Pos                   _UINT32_(19)                                         /* (PWM_IDR1) Fault Protection Trigger on Channel 3 Interrupt Disable Position */
#define PWM_IDR1_FCHID3_Msk                   (_UINT32_(0x1) << PWM_IDR1_FCHID3_Pos)               /* (PWM_IDR1) Fault Protection Trigger on Channel 3 Interrupt Disable Mask */
#define PWM_IDR1_FCHID3(value)                (PWM_IDR1_FCHID3_Msk & (_UINT32_(value) << PWM_IDR1_FCHID3_Pos)) /* Assigment of value for FCHID3 in the PWM_IDR1 register */
#define PWM_IDR1_Msk                          _UINT32_(0x000F000F)                                 /* (PWM_IDR1) Register Mask  */

#define PWM_IDR1_CHID_Pos                     _UINT32_(0)                                          /* (PWM_IDR1 Position) Counter Event on Channel x Interrupt Disable */
#define PWM_IDR1_CHID_Msk                     (_UINT32_(0xF) << PWM_IDR1_CHID_Pos)                 /* (PWM_IDR1 Mask) CHID */
#define PWM_IDR1_CHID(value)                  (PWM_IDR1_CHID_Msk & (_UINT32_(value) << PWM_IDR1_CHID_Pos)) 
#define PWM_IDR1_FCHID_Pos                    _UINT32_(16)                                         /* (PWM_IDR1 Position) Fault Protection Trigger on Channel 3 Interrupt Disable */
#define PWM_IDR1_FCHID_Msk                    (_UINT32_(0xF) << PWM_IDR1_FCHID_Pos)                /* (PWM_IDR1 Mask) FCHID */
#define PWM_IDR1_FCHID(value)                 (PWM_IDR1_FCHID_Msk & (_UINT32_(value) << PWM_IDR1_FCHID_Pos)) 

/* -------- PWM_IMR1 : (PWM Offset: 0x18) ( R/ 32) PWM Interrupt Mask Register 1 -------- */
#define PWM_IMR1_RESETVALUE                   _UINT32_(0x00)                                       /*  (PWM_IMR1) PWM Interrupt Mask Register 1  Reset Value */

#define PWM_IMR1_CHID0_Pos                    _UINT32_(0)                                          /* (PWM_IMR1) Counter Event on Channel 0 Interrupt Mask Position */
#define PWM_IMR1_CHID0_Msk                    (_UINT32_(0x1) << PWM_IMR1_CHID0_Pos)                /* (PWM_IMR1) Counter Event on Channel 0 Interrupt Mask Mask */
#define PWM_IMR1_CHID0(value)                 (PWM_IMR1_CHID0_Msk & (_UINT32_(value) << PWM_IMR1_CHID0_Pos)) /* Assigment of value for CHID0 in the PWM_IMR1 register */
#define PWM_IMR1_CHID1_Pos                    _UINT32_(1)                                          /* (PWM_IMR1) Counter Event on Channel 1 Interrupt Mask Position */
#define PWM_IMR1_CHID1_Msk                    (_UINT32_(0x1) << PWM_IMR1_CHID1_Pos)                /* (PWM_IMR1) Counter Event on Channel 1 Interrupt Mask Mask */
#define PWM_IMR1_CHID1(value)                 (PWM_IMR1_CHID1_Msk & (_UINT32_(value) << PWM_IMR1_CHID1_Pos)) /* Assigment of value for CHID1 in the PWM_IMR1 register */
#define PWM_IMR1_CHID2_Pos                    _UINT32_(2)                                          /* (PWM_IMR1) Counter Event on Channel 2 Interrupt Mask Position */
#define PWM_IMR1_CHID2_Msk                    (_UINT32_(0x1) << PWM_IMR1_CHID2_Pos)                /* (PWM_IMR1) Counter Event on Channel 2 Interrupt Mask Mask */
#define PWM_IMR1_CHID2(value)                 (PWM_IMR1_CHID2_Msk & (_UINT32_(value) << PWM_IMR1_CHID2_Pos)) /* Assigment of value for CHID2 in the PWM_IMR1 register */
#define PWM_IMR1_CHID3_Pos                    _UINT32_(3)                                          /* (PWM_IMR1) Counter Event on Channel 3 Interrupt Mask Position */
#define PWM_IMR1_CHID3_Msk                    (_UINT32_(0x1) << PWM_IMR1_CHID3_Pos)                /* (PWM_IMR1) Counter Event on Channel 3 Interrupt Mask Mask */
#define PWM_IMR1_CHID3(value)                 (PWM_IMR1_CHID3_Msk & (_UINT32_(value) << PWM_IMR1_CHID3_Pos)) /* Assigment of value for CHID3 in the PWM_IMR1 register */
#define PWM_IMR1_FCHID0_Pos                   _UINT32_(16)                                         /* (PWM_IMR1) Fault Protection Trigger on Channel 0 Interrupt Mask Position */
#define PWM_IMR1_FCHID0_Msk                   (_UINT32_(0x1) << PWM_IMR1_FCHID0_Pos)               /* (PWM_IMR1) Fault Protection Trigger on Channel 0 Interrupt Mask Mask */
#define PWM_IMR1_FCHID0(value)                (PWM_IMR1_FCHID0_Msk & (_UINT32_(value) << PWM_IMR1_FCHID0_Pos)) /* Assigment of value for FCHID0 in the PWM_IMR1 register */
#define PWM_IMR1_FCHID1_Pos                   _UINT32_(17)                                         /* (PWM_IMR1) Fault Protection Trigger on Channel 1 Interrupt Mask Position */
#define PWM_IMR1_FCHID1_Msk                   (_UINT32_(0x1) << PWM_IMR1_FCHID1_Pos)               /* (PWM_IMR1) Fault Protection Trigger on Channel 1 Interrupt Mask Mask */
#define PWM_IMR1_FCHID1(value)                (PWM_IMR1_FCHID1_Msk & (_UINT32_(value) << PWM_IMR1_FCHID1_Pos)) /* Assigment of value for FCHID1 in the PWM_IMR1 register */
#define PWM_IMR1_FCHID2_Pos                   _UINT32_(18)                                         /* (PWM_IMR1) Fault Protection Trigger on Channel 2 Interrupt Mask Position */
#define PWM_IMR1_FCHID2_Msk                   (_UINT32_(0x1) << PWM_IMR1_FCHID2_Pos)               /* (PWM_IMR1) Fault Protection Trigger on Channel 2 Interrupt Mask Mask */
#define PWM_IMR1_FCHID2(value)                (PWM_IMR1_FCHID2_Msk & (_UINT32_(value) << PWM_IMR1_FCHID2_Pos)) /* Assigment of value for FCHID2 in the PWM_IMR1 register */
#define PWM_IMR1_FCHID3_Pos                   _UINT32_(19)                                         /* (PWM_IMR1) Fault Protection Trigger on Channel 3 Interrupt Mask Position */
#define PWM_IMR1_FCHID3_Msk                   (_UINT32_(0x1) << PWM_IMR1_FCHID3_Pos)               /* (PWM_IMR1) Fault Protection Trigger on Channel 3 Interrupt Mask Mask */
#define PWM_IMR1_FCHID3(value)                (PWM_IMR1_FCHID3_Msk & (_UINT32_(value) << PWM_IMR1_FCHID3_Pos)) /* Assigment of value for FCHID3 in the PWM_IMR1 register */
#define PWM_IMR1_Msk                          _UINT32_(0x000F000F)                                 /* (PWM_IMR1) Register Mask  */

#define PWM_IMR1_CHID_Pos                     _UINT32_(0)                                          /* (PWM_IMR1 Position) Counter Event on Channel x Interrupt Mask */
#define PWM_IMR1_CHID_Msk                     (_UINT32_(0xF) << PWM_IMR1_CHID_Pos)                 /* (PWM_IMR1 Mask) CHID */
#define PWM_IMR1_CHID(value)                  (PWM_IMR1_CHID_Msk & (_UINT32_(value) << PWM_IMR1_CHID_Pos)) 
#define PWM_IMR1_FCHID_Pos                    _UINT32_(16)                                         /* (PWM_IMR1 Position) Fault Protection Trigger on Channel 3 Interrupt Mask */
#define PWM_IMR1_FCHID_Msk                    (_UINT32_(0xF) << PWM_IMR1_FCHID_Pos)                /* (PWM_IMR1 Mask) FCHID */
#define PWM_IMR1_FCHID(value)                 (PWM_IMR1_FCHID_Msk & (_UINT32_(value) << PWM_IMR1_FCHID_Pos)) 

/* -------- PWM_ISR1 : (PWM Offset: 0x1C) ( R/ 32) PWM Interrupt Status Register 1 -------- */
#define PWM_ISR1_RESETVALUE                   _UINT32_(0x00)                                       /*  (PWM_ISR1) PWM Interrupt Status Register 1  Reset Value */

#define PWM_ISR1_CHID0_Pos                    _UINT32_(0)                                          /* (PWM_ISR1) Counter Event on Channel 0 Position */
#define PWM_ISR1_CHID0_Msk                    (_UINT32_(0x1) << PWM_ISR1_CHID0_Pos)                /* (PWM_ISR1) Counter Event on Channel 0 Mask */
#define PWM_ISR1_CHID0(value)                 (PWM_ISR1_CHID0_Msk & (_UINT32_(value) << PWM_ISR1_CHID0_Pos)) /* Assigment of value for CHID0 in the PWM_ISR1 register */
#define   PWM_ISR1_CHID0_0_Val                _UINT32_(0x0)                                        /* (PWM_ISR1) No new counter event has occurred since the last read of PWM_ISR1.  */
#define   PWM_ISR1_CHID0_1_Val                _UINT32_(0x1)                                        /* (PWM_ISR1) At least one counter event has occurred since the last read of PWM_ISR1.  */
#define PWM_ISR1_CHID0_0                      (PWM_ISR1_CHID0_0_Val << PWM_ISR1_CHID0_Pos)         /* (PWM_ISR1) No new counter event has occurred since the last read of PWM_ISR1. Position  */
#define PWM_ISR1_CHID0_1                      (PWM_ISR1_CHID0_1_Val << PWM_ISR1_CHID0_Pos)         /* (PWM_ISR1) At least one counter event has occurred since the last read of PWM_ISR1. Position  */
#define PWM_ISR1_CHID1_Pos                    _UINT32_(1)                                          /* (PWM_ISR1) Counter Event on Channel 1 Position */
#define PWM_ISR1_CHID1_Msk                    (_UINT32_(0x1) << PWM_ISR1_CHID1_Pos)                /* (PWM_ISR1) Counter Event on Channel 1 Mask */
#define PWM_ISR1_CHID1(value)                 (PWM_ISR1_CHID1_Msk & (_UINT32_(value) << PWM_ISR1_CHID1_Pos)) /* Assigment of value for CHID1 in the PWM_ISR1 register */
#define   PWM_ISR1_CHID1_0_Val                _UINT32_(0x0)                                        /* (PWM_ISR1) No new counter event has occurred since the last read of PWM_ISR1.  */
#define   PWM_ISR1_CHID1_1_Val                _UINT32_(0x1)                                        /* (PWM_ISR1) At least one counter event has occurred since the last read of PWM_ISR1.  */
#define PWM_ISR1_CHID1_0                      (PWM_ISR1_CHID1_0_Val << PWM_ISR1_CHID1_Pos)         /* (PWM_ISR1) No new counter event has occurred since the last read of PWM_ISR1. Position  */
#define PWM_ISR1_CHID1_1                      (PWM_ISR1_CHID1_1_Val << PWM_ISR1_CHID1_Pos)         /* (PWM_ISR1) At least one counter event has occurred since the last read of PWM_ISR1. Position  */
#define PWM_ISR1_CHID2_Pos                    _UINT32_(2)                                          /* (PWM_ISR1) Counter Event on Channel 2 Position */
#define PWM_ISR1_CHID2_Msk                    (_UINT32_(0x1) << PWM_ISR1_CHID2_Pos)                /* (PWM_ISR1) Counter Event on Channel 2 Mask */
#define PWM_ISR1_CHID2(value)                 (PWM_ISR1_CHID2_Msk & (_UINT32_(value) << PWM_ISR1_CHID2_Pos)) /* Assigment of value for CHID2 in the PWM_ISR1 register */
#define   PWM_ISR1_CHID2_0_Val                _UINT32_(0x0)                                        /* (PWM_ISR1) No new counter event has occurred since the last read of PWM_ISR1.  */
#define   PWM_ISR1_CHID2_1_Val                _UINT32_(0x1)                                        /* (PWM_ISR1) At least one counter event has occurred since the last read of PWM_ISR1.  */
#define PWM_ISR1_CHID2_0                      (PWM_ISR1_CHID2_0_Val << PWM_ISR1_CHID2_Pos)         /* (PWM_ISR1) No new counter event has occurred since the last read of PWM_ISR1. Position  */
#define PWM_ISR1_CHID2_1                      (PWM_ISR1_CHID2_1_Val << PWM_ISR1_CHID2_Pos)         /* (PWM_ISR1) At least one counter event has occurred since the last read of PWM_ISR1. Position  */
#define PWM_ISR1_CHID3_Pos                    _UINT32_(3)                                          /* (PWM_ISR1) Counter Event on Channel 3 Position */
#define PWM_ISR1_CHID3_Msk                    (_UINT32_(0x1) << PWM_ISR1_CHID3_Pos)                /* (PWM_ISR1) Counter Event on Channel 3 Mask */
#define PWM_ISR1_CHID3(value)                 (PWM_ISR1_CHID3_Msk & (_UINT32_(value) << PWM_ISR1_CHID3_Pos)) /* Assigment of value for CHID3 in the PWM_ISR1 register */
#define   PWM_ISR1_CHID3_0_Val                _UINT32_(0x0)                                        /* (PWM_ISR1) No new counter event has occurred since the last read of PWM_ISR1.  */
#define   PWM_ISR1_CHID3_1_Val                _UINT32_(0x1)                                        /* (PWM_ISR1) At least one counter event has occurred since the last read of PWM_ISR1.  */
#define PWM_ISR1_CHID3_0                      (PWM_ISR1_CHID3_0_Val << PWM_ISR1_CHID3_Pos)         /* (PWM_ISR1) No new counter event has occurred since the last read of PWM_ISR1. Position  */
#define PWM_ISR1_CHID3_1                      (PWM_ISR1_CHID3_1_Val << PWM_ISR1_CHID3_Pos)         /* (PWM_ISR1) At least one counter event has occurred since the last read of PWM_ISR1. Position  */
#define PWM_ISR1_FCHID0_Pos                   _UINT32_(16)                                         /* (PWM_ISR1) Fault Protection Trigger on Channel 0 Position */
#define PWM_ISR1_FCHID0_Msk                   (_UINT32_(0x1) << PWM_ISR1_FCHID0_Pos)               /* (PWM_ISR1) Fault Protection Trigger on Channel 0 Mask */
#define PWM_ISR1_FCHID0(value)                (PWM_ISR1_FCHID0_Msk & (_UINT32_(value) << PWM_ISR1_FCHID0_Pos)) /* Assigment of value for FCHID0 in the PWM_ISR1 register */
#define   PWM_ISR1_FCHID0_0_Val               _UINT32_(0x0)                                        /* (PWM_ISR1) No new trigger of the fault protection since the last read of PWM_ISR1.  */
#define   PWM_ISR1_FCHID0_1_Val               _UINT32_(0x1)                                        /* (PWM_ISR1) At least one trigger of the fault protection since the last read of PWM_ISR1.  */
#define PWM_ISR1_FCHID0_0                     (PWM_ISR1_FCHID0_0_Val << PWM_ISR1_FCHID0_Pos)       /* (PWM_ISR1) No new trigger of the fault protection since the last read of PWM_ISR1. Position  */
#define PWM_ISR1_FCHID0_1                     (PWM_ISR1_FCHID0_1_Val << PWM_ISR1_FCHID0_Pos)       /* (PWM_ISR1) At least one trigger of the fault protection since the last read of PWM_ISR1. Position  */
#define PWM_ISR1_FCHID1_Pos                   _UINT32_(17)                                         /* (PWM_ISR1) Fault Protection Trigger on Channel 1 Position */
#define PWM_ISR1_FCHID1_Msk                   (_UINT32_(0x1) << PWM_ISR1_FCHID1_Pos)               /* (PWM_ISR1) Fault Protection Trigger on Channel 1 Mask */
#define PWM_ISR1_FCHID1(value)                (PWM_ISR1_FCHID1_Msk & (_UINT32_(value) << PWM_ISR1_FCHID1_Pos)) /* Assigment of value for FCHID1 in the PWM_ISR1 register */
#define   PWM_ISR1_FCHID1_0_Val               _UINT32_(0x0)                                        /* (PWM_ISR1) No new trigger of the fault protection since the last read of PWM_ISR1.  */
#define   PWM_ISR1_FCHID1_1_Val               _UINT32_(0x1)                                        /* (PWM_ISR1) At least one trigger of the fault protection since the last read of PWM_ISR1.  */
#define PWM_ISR1_FCHID1_0                     (PWM_ISR1_FCHID1_0_Val << PWM_ISR1_FCHID1_Pos)       /* (PWM_ISR1) No new trigger of the fault protection since the last read of PWM_ISR1. Position  */
#define PWM_ISR1_FCHID1_1                     (PWM_ISR1_FCHID1_1_Val << PWM_ISR1_FCHID1_Pos)       /* (PWM_ISR1) At least one trigger of the fault protection since the last read of PWM_ISR1. Position  */
#define PWM_ISR1_FCHID2_Pos                   _UINT32_(18)                                         /* (PWM_ISR1) Fault Protection Trigger on Channel 2 Position */
#define PWM_ISR1_FCHID2_Msk                   (_UINT32_(0x1) << PWM_ISR1_FCHID2_Pos)               /* (PWM_ISR1) Fault Protection Trigger on Channel 2 Mask */
#define PWM_ISR1_FCHID2(value)                (PWM_ISR1_FCHID2_Msk & (_UINT32_(value) << PWM_ISR1_FCHID2_Pos)) /* Assigment of value for FCHID2 in the PWM_ISR1 register */
#define   PWM_ISR1_FCHID2_0_Val               _UINT32_(0x0)                                        /* (PWM_ISR1) No new trigger of the fault protection since the last read of PWM_ISR1.  */
#define   PWM_ISR1_FCHID2_1_Val               _UINT32_(0x1)                                        /* (PWM_ISR1) At least one trigger of the fault protection since the last read of PWM_ISR1.  */
#define PWM_ISR1_FCHID2_0                     (PWM_ISR1_FCHID2_0_Val << PWM_ISR1_FCHID2_Pos)       /* (PWM_ISR1) No new trigger of the fault protection since the last read of PWM_ISR1. Position  */
#define PWM_ISR1_FCHID2_1                     (PWM_ISR1_FCHID2_1_Val << PWM_ISR1_FCHID2_Pos)       /* (PWM_ISR1) At least one trigger of the fault protection since the last read of PWM_ISR1. Position  */
#define PWM_ISR1_FCHID3_Pos                   _UINT32_(19)                                         /* (PWM_ISR1) Fault Protection Trigger on Channel 3 Position */
#define PWM_ISR1_FCHID3_Msk                   (_UINT32_(0x1) << PWM_ISR1_FCHID3_Pos)               /* (PWM_ISR1) Fault Protection Trigger on Channel 3 Mask */
#define PWM_ISR1_FCHID3(value)                (PWM_ISR1_FCHID3_Msk & (_UINT32_(value) << PWM_ISR1_FCHID3_Pos)) /* Assigment of value for FCHID3 in the PWM_ISR1 register */
#define   PWM_ISR1_FCHID3_0_Val               _UINT32_(0x0)                                        /* (PWM_ISR1) No new trigger of the fault protection since the last read of PWM_ISR1.  */
#define   PWM_ISR1_FCHID3_1_Val               _UINT32_(0x1)                                        /* (PWM_ISR1) At least one trigger of the fault protection since the last read of PWM_ISR1.  */
#define PWM_ISR1_FCHID3_0                     (PWM_ISR1_FCHID3_0_Val << PWM_ISR1_FCHID3_Pos)       /* (PWM_ISR1) No new trigger of the fault protection since the last read of PWM_ISR1. Position  */
#define PWM_ISR1_FCHID3_1                     (PWM_ISR1_FCHID3_1_Val << PWM_ISR1_FCHID3_Pos)       /* (PWM_ISR1) At least one trigger of the fault protection since the last read of PWM_ISR1. Position  */
#define PWM_ISR1_Msk                          _UINT32_(0x000F000F)                                 /* (PWM_ISR1) Register Mask  */

#define PWM_ISR1_CHID_Pos                     _UINT32_(0)                                          /* (PWM_ISR1 Position) Counter Event on Channel x */
#define PWM_ISR1_CHID_Msk                     (_UINT32_(0xF) << PWM_ISR1_CHID_Pos)                 /* (PWM_ISR1 Mask) CHID */
#define PWM_ISR1_CHID(value)                  (PWM_ISR1_CHID_Msk & (_UINT32_(value) << PWM_ISR1_CHID_Pos)) 
#define PWM_ISR1_FCHID_Pos                    _UINT32_(16)                                         /* (PWM_ISR1 Position) Fault Protection Trigger on Channel 3 */
#define PWM_ISR1_FCHID_Msk                    (_UINT32_(0xF) << PWM_ISR1_FCHID_Pos)                /* (PWM_ISR1 Mask) FCHID */
#define PWM_ISR1_FCHID(value)                 (PWM_ISR1_FCHID_Msk & (_UINT32_(value) << PWM_ISR1_FCHID_Pos)) 

/* -------- PWM_SCM : (PWM Offset: 0x20) (R/W 32) PWM Sync Channels Mode Register -------- */
#define PWM_SCM_RESETVALUE                    _UINT32_(0x00)                                       /*  (PWM_SCM) PWM Sync Channels Mode Register  Reset Value */

#define PWM_SCM_SYNC0_Pos                     _UINT32_(0)                                          /* (PWM_SCM) Synchronous Channel 0 Position */
#define PWM_SCM_SYNC0_Msk                     (_UINT32_(0x1) << PWM_SCM_SYNC0_Pos)                 /* (PWM_SCM) Synchronous Channel 0 Mask */
#define PWM_SCM_SYNC0(value)                  (PWM_SCM_SYNC0_Msk & (_UINT32_(value) << PWM_SCM_SYNC0_Pos)) /* Assigment of value for SYNC0 in the PWM_SCM register */
#define   PWM_SCM_SYNC0_0_Val                 _UINT32_(0x0)                                        /* (PWM_SCM) Channel x is not a synchronous channel.  */
#define   PWM_SCM_SYNC0_1_Val                 _UINT32_(0x1)                                        /* (PWM_SCM) Channel x is a synchronous channel.  */
#define PWM_SCM_SYNC0_0                       (PWM_SCM_SYNC0_0_Val << PWM_SCM_SYNC0_Pos)           /* (PWM_SCM) Channel x is not a synchronous channel. Position  */
#define PWM_SCM_SYNC0_1                       (PWM_SCM_SYNC0_1_Val << PWM_SCM_SYNC0_Pos)           /* (PWM_SCM) Channel x is a synchronous channel. Position  */
#define PWM_SCM_SYNC1_Pos                     _UINT32_(1)                                          /* (PWM_SCM) Synchronous Channel 1 Position */
#define PWM_SCM_SYNC1_Msk                     (_UINT32_(0x1) << PWM_SCM_SYNC1_Pos)                 /* (PWM_SCM) Synchronous Channel 1 Mask */
#define PWM_SCM_SYNC1(value)                  (PWM_SCM_SYNC1_Msk & (_UINT32_(value) << PWM_SCM_SYNC1_Pos)) /* Assigment of value for SYNC1 in the PWM_SCM register */
#define   PWM_SCM_SYNC1_0_Val                 _UINT32_(0x0)                                        /* (PWM_SCM) Channel x is not a synchronous channel.  */
#define   PWM_SCM_SYNC1_1_Val                 _UINT32_(0x1)                                        /* (PWM_SCM) Channel x is a synchronous channel.  */
#define PWM_SCM_SYNC1_0                       (PWM_SCM_SYNC1_0_Val << PWM_SCM_SYNC1_Pos)           /* (PWM_SCM) Channel x is not a synchronous channel. Position  */
#define PWM_SCM_SYNC1_1                       (PWM_SCM_SYNC1_1_Val << PWM_SCM_SYNC1_Pos)           /* (PWM_SCM) Channel x is a synchronous channel. Position  */
#define PWM_SCM_SYNC2_Pos                     _UINT32_(2)                                          /* (PWM_SCM) Synchronous Channel 2 Position */
#define PWM_SCM_SYNC2_Msk                     (_UINT32_(0x1) << PWM_SCM_SYNC2_Pos)                 /* (PWM_SCM) Synchronous Channel 2 Mask */
#define PWM_SCM_SYNC2(value)                  (PWM_SCM_SYNC2_Msk & (_UINT32_(value) << PWM_SCM_SYNC2_Pos)) /* Assigment of value for SYNC2 in the PWM_SCM register */
#define   PWM_SCM_SYNC2_0_Val                 _UINT32_(0x0)                                        /* (PWM_SCM) Channel x is not a synchronous channel.  */
#define   PWM_SCM_SYNC2_1_Val                 _UINT32_(0x1)                                        /* (PWM_SCM) Channel x is a synchronous channel.  */
#define PWM_SCM_SYNC2_0                       (PWM_SCM_SYNC2_0_Val << PWM_SCM_SYNC2_Pos)           /* (PWM_SCM) Channel x is not a synchronous channel. Position  */
#define PWM_SCM_SYNC2_1                       (PWM_SCM_SYNC2_1_Val << PWM_SCM_SYNC2_Pos)           /* (PWM_SCM) Channel x is a synchronous channel. Position  */
#define PWM_SCM_SYNC3_Pos                     _UINT32_(3)                                          /* (PWM_SCM) Synchronous Channel 3 Position */
#define PWM_SCM_SYNC3_Msk                     (_UINT32_(0x1) << PWM_SCM_SYNC3_Pos)                 /* (PWM_SCM) Synchronous Channel 3 Mask */
#define PWM_SCM_SYNC3(value)                  (PWM_SCM_SYNC3_Msk & (_UINT32_(value) << PWM_SCM_SYNC3_Pos)) /* Assigment of value for SYNC3 in the PWM_SCM register */
#define   PWM_SCM_SYNC3_0_Val                 _UINT32_(0x0)                                        /* (PWM_SCM) Channel x is not a synchronous channel.  */
#define   PWM_SCM_SYNC3_1_Val                 _UINT32_(0x1)                                        /* (PWM_SCM) Channel x is a synchronous channel.  */
#define PWM_SCM_SYNC3_0                       (PWM_SCM_SYNC3_0_Val << PWM_SCM_SYNC3_Pos)           /* (PWM_SCM) Channel x is not a synchronous channel. Position  */
#define PWM_SCM_SYNC3_1                       (PWM_SCM_SYNC3_1_Val << PWM_SCM_SYNC3_Pos)           /* (PWM_SCM) Channel x is a synchronous channel. Position  */
#define PWM_SCM_UPDM_Pos                      _UINT32_(16)                                         /* (PWM_SCM) Synchronous Channels Update Mode Position */
#define PWM_SCM_UPDM_Msk                      (_UINT32_(0x3) << PWM_SCM_UPDM_Pos)                  /* (PWM_SCM) Synchronous Channels Update Mode Mask */
#define PWM_SCM_UPDM(value)                   (PWM_SCM_UPDM_Msk & (_UINT32_(value) << PWM_SCM_UPDM_Pos)) /* Assigment of value for UPDM in the PWM_SCM register */
#define   PWM_SCM_UPDM_MODE0_Val              _UINT32_(0x0)                                        /* (PWM_SCM) Manual write of double buffer registers and manual update of synchronous channels  */
#define   PWM_SCM_UPDM_MODE1_Val              _UINT32_(0x1)                                        /* (PWM_SCM) Manual write of double buffer registers and automatic update of synchronous channels  */
#define   PWM_SCM_UPDM_MODE2_Val              _UINT32_(0x2)                                        /* (PWM_SCM) Automatic write of duty-cycle update registers by the DMA Controller and automatic update of synchronous channels  */
#define PWM_SCM_UPDM_MODE0                    (PWM_SCM_UPDM_MODE0_Val << PWM_SCM_UPDM_Pos)         /* (PWM_SCM) Manual write of double buffer registers and manual update of synchronous channels Position  */
#define PWM_SCM_UPDM_MODE1                    (PWM_SCM_UPDM_MODE1_Val << PWM_SCM_UPDM_Pos)         /* (PWM_SCM) Manual write of double buffer registers and automatic update of synchronous channels Position  */
#define PWM_SCM_UPDM_MODE2                    (PWM_SCM_UPDM_MODE2_Val << PWM_SCM_UPDM_Pos)         /* (PWM_SCM) Automatic write of duty-cycle update registers by the DMA Controller and automatic update of synchronous channels Position  */
#define PWM_SCM_PTRM_Pos                      _UINT32_(20)                                         /* (PWM_SCM) DMA Controller Transfer Request Mode Position */
#define PWM_SCM_PTRM_Msk                      (_UINT32_(0x1) << PWM_SCM_PTRM_Pos)                  /* (PWM_SCM) DMA Controller Transfer Request Mode Mask */
#define PWM_SCM_PTRM(value)                   (PWM_SCM_PTRM_Msk & (_UINT32_(value) << PWM_SCM_PTRM_Pos)) /* Assigment of value for PTRM in the PWM_SCM register */
#define PWM_SCM_PTRCS_Pos                     _UINT32_(21)                                         /* (PWM_SCM) DMA Controller Transfer Request Comparison Selection Position */
#define PWM_SCM_PTRCS_Msk                     (_UINT32_(0x7) << PWM_SCM_PTRCS_Pos)                 /* (PWM_SCM) DMA Controller Transfer Request Comparison Selection Mask */
#define PWM_SCM_PTRCS(value)                  (PWM_SCM_PTRCS_Msk & (_UINT32_(value) << PWM_SCM_PTRCS_Pos)) /* Assigment of value for PTRCS in the PWM_SCM register */
#define PWM_SCM_Msk                           _UINT32_(0x00F3000F)                                 /* (PWM_SCM) Register Mask  */

#define PWM_SCM_SYNC_Pos                      _UINT32_(0)                                          /* (PWM_SCM Position) Synchronous Channel x */
#define PWM_SCM_SYNC_Msk                      (_UINT32_(0xF) << PWM_SCM_SYNC_Pos)                  /* (PWM_SCM Mask) SYNC */
#define PWM_SCM_SYNC(value)                   (PWM_SCM_SYNC_Msk & (_UINT32_(value) << PWM_SCM_SYNC_Pos)) 

/* -------- PWM_DMAR : (PWM Offset: 0x24) ( /W 32) PWM DMA Register -------- */
#define PWM_DMAR_DMADUTY_Pos                  _UINT32_(0)                                          /* (PWM_DMAR) Duty-Cycle Holding Register for DMA Access Position */
#define PWM_DMAR_DMADUTY_Msk                  (_UINT32_(0xFFFFFF) << PWM_DMAR_DMADUTY_Pos)         /* (PWM_DMAR) Duty-Cycle Holding Register for DMA Access Mask */
#define PWM_DMAR_DMADUTY(value)               (PWM_DMAR_DMADUTY_Msk & (_UINT32_(value) << PWM_DMAR_DMADUTY_Pos)) /* Assigment of value for DMADUTY in the PWM_DMAR register */
#define PWM_DMAR_Msk                          _UINT32_(0x00FFFFFF)                                 /* (PWM_DMAR) Register Mask  */


/* -------- PWM_SCUC : (PWM Offset: 0x28) (R/W 32) PWM Sync Channels Update Control Register -------- */
#define PWM_SCUC_RESETVALUE                   _UINT32_(0x00)                                       /*  (PWM_SCUC) PWM Sync Channels Update Control Register  Reset Value */

#define PWM_SCUC_UPDULOCK_Pos                 _UINT32_(0)                                          /* (PWM_SCUC) Synchronous Channels Update Unlock Position */
#define PWM_SCUC_UPDULOCK_Msk                 (_UINT32_(0x1) << PWM_SCUC_UPDULOCK_Pos)             /* (PWM_SCUC) Synchronous Channels Update Unlock Mask */
#define PWM_SCUC_UPDULOCK(value)              (PWM_SCUC_UPDULOCK_Msk & (_UINT32_(value) << PWM_SCUC_UPDULOCK_Pos)) /* Assigment of value for UPDULOCK in the PWM_SCUC register */
#define   PWM_SCUC_UPDULOCK_0_Val             _UINT32_(0x0)                                        /* (PWM_SCUC) No effect  */
#define   PWM_SCUC_UPDULOCK_1_Val             _UINT32_(0x1)                                        /* (PWM_SCUC) If the UPDM field is set to '0' in PWM Sync Channels Mode Register, writing the UPDULOCK bit to '1' triggers the update of the period value, the duty-cycle and the dead-time values of synchronous channels at the beginning of the next PWM period. If the field UPDM is set to '1' or '2', writing the UPDULOCK bit to '1' triggers only the update of the period value and of the dead-time values of synchronous channels.  */
#define PWM_SCUC_UPDULOCK_0                   (PWM_SCUC_UPDULOCK_0_Val << PWM_SCUC_UPDULOCK_Pos)   /* (PWM_SCUC) No effect Position  */
#define PWM_SCUC_UPDULOCK_1                   (PWM_SCUC_UPDULOCK_1_Val << PWM_SCUC_UPDULOCK_Pos)   /* (PWM_SCUC) If the UPDM field is set to '0' in PWM Sync Channels Mode Register, writing the UPDULOCK bit to '1' triggers the update of the period value, the duty-cycle and the dead-time values of synchronous channels at the beginning of the next PWM period. If the field UPDM is set to '1' or '2', writing the UPDULOCK bit to '1' triggers only the update of the period value and of the dead-time values of synchronous channels. Position  */
#define PWM_SCUC_Msk                          _UINT32_(0x00000001)                                 /* (PWM_SCUC) Register Mask  */


/* -------- PWM_SCUP : (PWM Offset: 0x2C) (R/W 32) PWM Sync Channels Update Period Register -------- */
#define PWM_SCUP_RESETVALUE                   _UINT32_(0x00)                                       /*  (PWM_SCUP) PWM Sync Channels Update Period Register  Reset Value */

#define PWM_SCUP_UPR_Pos                      _UINT32_(0)                                          /* (PWM_SCUP) Update Period Position */
#define PWM_SCUP_UPR_Msk                      (_UINT32_(0xF) << PWM_SCUP_UPR_Pos)                  /* (PWM_SCUP) Update Period Mask */
#define PWM_SCUP_UPR(value)                   (PWM_SCUP_UPR_Msk & (_UINT32_(value) << PWM_SCUP_UPR_Pos)) /* Assigment of value for UPR in the PWM_SCUP register */
#define PWM_SCUP_UPRCNT_Pos                   _UINT32_(4)                                          /* (PWM_SCUP) Update Period Counter Position */
#define PWM_SCUP_UPRCNT_Msk                   (_UINT32_(0xF) << PWM_SCUP_UPRCNT_Pos)               /* (PWM_SCUP) Update Period Counter Mask */
#define PWM_SCUP_UPRCNT(value)                (PWM_SCUP_UPRCNT_Msk & (_UINT32_(value) << PWM_SCUP_UPRCNT_Pos)) /* Assigment of value for UPRCNT in the PWM_SCUP register */
#define PWM_SCUP_Msk                          _UINT32_(0x000000FF)                                 /* (PWM_SCUP) Register Mask  */


/* -------- PWM_SCUPUPD : (PWM Offset: 0x30) ( /W 32) PWM Sync Channels Update Period Update Register -------- */
#define PWM_SCUPUPD_UPRUPD_Pos                _UINT32_(0)                                          /* (PWM_SCUPUPD) Update Period Update Position */
#define PWM_SCUPUPD_UPRUPD_Msk                (_UINT32_(0xF) << PWM_SCUPUPD_UPRUPD_Pos)            /* (PWM_SCUPUPD) Update Period Update Mask */
#define PWM_SCUPUPD_UPRUPD(value)             (PWM_SCUPUPD_UPRUPD_Msk & (_UINT32_(value) << PWM_SCUPUPD_UPRUPD_Pos)) /* Assigment of value for UPRUPD in the PWM_SCUPUPD register */
#define PWM_SCUPUPD_Msk                       _UINT32_(0x0000000F)                                 /* (PWM_SCUPUPD) Register Mask  */


/* -------- PWM_IER2 : (PWM Offset: 0x34) ( /W 32) PWM Interrupt Enable Register 2 -------- */
#define PWM_IER2_WRDY_Pos                     _UINT32_(0)                                          /* (PWM_IER2) Write Ready for Synchronous Channels Update Interrupt Enable Position */
#define PWM_IER2_WRDY_Msk                     (_UINT32_(0x1) << PWM_IER2_WRDY_Pos)                 /* (PWM_IER2) Write Ready for Synchronous Channels Update Interrupt Enable Mask */
#define PWM_IER2_WRDY(value)                  (PWM_IER2_WRDY_Msk & (_UINT32_(value) << PWM_IER2_WRDY_Pos)) /* Assigment of value for WRDY in the PWM_IER2 register */
#define PWM_IER2_UNRE_Pos                     _UINT32_(3)                                          /* (PWM_IER2) Synchronous Channels Update Underrun Error Interrupt Enable Position */
#define PWM_IER2_UNRE_Msk                     (_UINT32_(0x1) << PWM_IER2_UNRE_Pos)                 /* (PWM_IER2) Synchronous Channels Update Underrun Error Interrupt Enable Mask */
#define PWM_IER2_UNRE(value)                  (PWM_IER2_UNRE_Msk & (_UINT32_(value) << PWM_IER2_UNRE_Pos)) /* Assigment of value for UNRE in the PWM_IER2 register */
#define PWM_IER2_CMPM0_Pos                    _UINT32_(8)                                          /* (PWM_IER2) Comparison 0 Match Interrupt Enable Position */
#define PWM_IER2_CMPM0_Msk                    (_UINT32_(0x1) << PWM_IER2_CMPM0_Pos)                /* (PWM_IER2) Comparison 0 Match Interrupt Enable Mask */
#define PWM_IER2_CMPM0(value)                 (PWM_IER2_CMPM0_Msk & (_UINT32_(value) << PWM_IER2_CMPM0_Pos)) /* Assigment of value for CMPM0 in the PWM_IER2 register */
#define PWM_IER2_CMPM1_Pos                    _UINT32_(9)                                          /* (PWM_IER2) Comparison 1 Match Interrupt Enable Position */
#define PWM_IER2_CMPM1_Msk                    (_UINT32_(0x1) << PWM_IER2_CMPM1_Pos)                /* (PWM_IER2) Comparison 1 Match Interrupt Enable Mask */
#define PWM_IER2_CMPM1(value)                 (PWM_IER2_CMPM1_Msk & (_UINT32_(value) << PWM_IER2_CMPM1_Pos)) /* Assigment of value for CMPM1 in the PWM_IER2 register */
#define PWM_IER2_CMPM2_Pos                    _UINT32_(10)                                         /* (PWM_IER2) Comparison 2 Match Interrupt Enable Position */
#define PWM_IER2_CMPM2_Msk                    (_UINT32_(0x1) << PWM_IER2_CMPM2_Pos)                /* (PWM_IER2) Comparison 2 Match Interrupt Enable Mask */
#define PWM_IER2_CMPM2(value)                 (PWM_IER2_CMPM2_Msk & (_UINT32_(value) << PWM_IER2_CMPM2_Pos)) /* Assigment of value for CMPM2 in the PWM_IER2 register */
#define PWM_IER2_CMPM3_Pos                    _UINT32_(11)                                         /* (PWM_IER2) Comparison 3 Match Interrupt Enable Position */
#define PWM_IER2_CMPM3_Msk                    (_UINT32_(0x1) << PWM_IER2_CMPM3_Pos)                /* (PWM_IER2) Comparison 3 Match Interrupt Enable Mask */
#define PWM_IER2_CMPM3(value)                 (PWM_IER2_CMPM3_Msk & (_UINT32_(value) << PWM_IER2_CMPM3_Pos)) /* Assigment of value for CMPM3 in the PWM_IER2 register */
#define PWM_IER2_CMPM4_Pos                    _UINT32_(12)                                         /* (PWM_IER2) Comparison 4 Match Interrupt Enable Position */
#define PWM_IER2_CMPM4_Msk                    (_UINT32_(0x1) << PWM_IER2_CMPM4_Pos)                /* (PWM_IER2) Comparison 4 Match Interrupt Enable Mask */
#define PWM_IER2_CMPM4(value)                 (PWM_IER2_CMPM4_Msk & (_UINT32_(value) << PWM_IER2_CMPM4_Pos)) /* Assigment of value for CMPM4 in the PWM_IER2 register */
#define PWM_IER2_CMPM5_Pos                    _UINT32_(13)                                         /* (PWM_IER2) Comparison 5 Match Interrupt Enable Position */
#define PWM_IER2_CMPM5_Msk                    (_UINT32_(0x1) << PWM_IER2_CMPM5_Pos)                /* (PWM_IER2) Comparison 5 Match Interrupt Enable Mask */
#define PWM_IER2_CMPM5(value)                 (PWM_IER2_CMPM5_Msk & (_UINT32_(value) << PWM_IER2_CMPM5_Pos)) /* Assigment of value for CMPM5 in the PWM_IER2 register */
#define PWM_IER2_CMPM6_Pos                    _UINT32_(14)                                         /* (PWM_IER2) Comparison 6 Match Interrupt Enable Position */
#define PWM_IER2_CMPM6_Msk                    (_UINT32_(0x1) << PWM_IER2_CMPM6_Pos)                /* (PWM_IER2) Comparison 6 Match Interrupt Enable Mask */
#define PWM_IER2_CMPM6(value)                 (PWM_IER2_CMPM6_Msk & (_UINT32_(value) << PWM_IER2_CMPM6_Pos)) /* Assigment of value for CMPM6 in the PWM_IER2 register */
#define PWM_IER2_CMPM7_Pos                    _UINT32_(15)                                         /* (PWM_IER2) Comparison 7 Match Interrupt Enable Position */
#define PWM_IER2_CMPM7_Msk                    (_UINT32_(0x1) << PWM_IER2_CMPM7_Pos)                /* (PWM_IER2) Comparison 7 Match Interrupt Enable Mask */
#define PWM_IER2_CMPM7(value)                 (PWM_IER2_CMPM7_Msk & (_UINT32_(value) << PWM_IER2_CMPM7_Pos)) /* Assigment of value for CMPM7 in the PWM_IER2 register */
#define PWM_IER2_CMPU0_Pos                    _UINT32_(16)                                         /* (PWM_IER2) Comparison 0 Update Interrupt Enable Position */
#define PWM_IER2_CMPU0_Msk                    (_UINT32_(0x1) << PWM_IER2_CMPU0_Pos)                /* (PWM_IER2) Comparison 0 Update Interrupt Enable Mask */
#define PWM_IER2_CMPU0(value)                 (PWM_IER2_CMPU0_Msk & (_UINT32_(value) << PWM_IER2_CMPU0_Pos)) /* Assigment of value for CMPU0 in the PWM_IER2 register */
#define PWM_IER2_CMPU1_Pos                    _UINT32_(17)                                         /* (PWM_IER2) Comparison 1 Update Interrupt Enable Position */
#define PWM_IER2_CMPU1_Msk                    (_UINT32_(0x1) << PWM_IER2_CMPU1_Pos)                /* (PWM_IER2) Comparison 1 Update Interrupt Enable Mask */
#define PWM_IER2_CMPU1(value)                 (PWM_IER2_CMPU1_Msk & (_UINT32_(value) << PWM_IER2_CMPU1_Pos)) /* Assigment of value for CMPU1 in the PWM_IER2 register */
#define PWM_IER2_CMPU2_Pos                    _UINT32_(18)                                         /* (PWM_IER2) Comparison 2 Update Interrupt Enable Position */
#define PWM_IER2_CMPU2_Msk                    (_UINT32_(0x1) << PWM_IER2_CMPU2_Pos)                /* (PWM_IER2) Comparison 2 Update Interrupt Enable Mask */
#define PWM_IER2_CMPU2(value)                 (PWM_IER2_CMPU2_Msk & (_UINT32_(value) << PWM_IER2_CMPU2_Pos)) /* Assigment of value for CMPU2 in the PWM_IER2 register */
#define PWM_IER2_CMPU3_Pos                    _UINT32_(19)                                         /* (PWM_IER2) Comparison 3 Update Interrupt Enable Position */
#define PWM_IER2_CMPU3_Msk                    (_UINT32_(0x1) << PWM_IER2_CMPU3_Pos)                /* (PWM_IER2) Comparison 3 Update Interrupt Enable Mask */
#define PWM_IER2_CMPU3(value)                 (PWM_IER2_CMPU3_Msk & (_UINT32_(value) << PWM_IER2_CMPU3_Pos)) /* Assigment of value for CMPU3 in the PWM_IER2 register */
#define PWM_IER2_CMPU4_Pos                    _UINT32_(20)                                         /* (PWM_IER2) Comparison 4 Update Interrupt Enable Position */
#define PWM_IER2_CMPU4_Msk                    (_UINT32_(0x1) << PWM_IER2_CMPU4_Pos)                /* (PWM_IER2) Comparison 4 Update Interrupt Enable Mask */
#define PWM_IER2_CMPU4(value)                 (PWM_IER2_CMPU4_Msk & (_UINT32_(value) << PWM_IER2_CMPU4_Pos)) /* Assigment of value for CMPU4 in the PWM_IER2 register */
#define PWM_IER2_CMPU5_Pos                    _UINT32_(21)                                         /* (PWM_IER2) Comparison 5 Update Interrupt Enable Position */
#define PWM_IER2_CMPU5_Msk                    (_UINT32_(0x1) << PWM_IER2_CMPU5_Pos)                /* (PWM_IER2) Comparison 5 Update Interrupt Enable Mask */
#define PWM_IER2_CMPU5(value)                 (PWM_IER2_CMPU5_Msk & (_UINT32_(value) << PWM_IER2_CMPU5_Pos)) /* Assigment of value for CMPU5 in the PWM_IER2 register */
#define PWM_IER2_CMPU6_Pos                    _UINT32_(22)                                         /* (PWM_IER2) Comparison 6 Update Interrupt Enable Position */
#define PWM_IER2_CMPU6_Msk                    (_UINT32_(0x1) << PWM_IER2_CMPU6_Pos)                /* (PWM_IER2) Comparison 6 Update Interrupt Enable Mask */
#define PWM_IER2_CMPU6(value)                 (PWM_IER2_CMPU6_Msk & (_UINT32_(value) << PWM_IER2_CMPU6_Pos)) /* Assigment of value for CMPU6 in the PWM_IER2 register */
#define PWM_IER2_CMPU7_Pos                    _UINT32_(23)                                         /* (PWM_IER2) Comparison 7 Update Interrupt Enable Position */
#define PWM_IER2_CMPU7_Msk                    (_UINT32_(0x1) << PWM_IER2_CMPU7_Pos)                /* (PWM_IER2) Comparison 7 Update Interrupt Enable Mask */
#define PWM_IER2_CMPU7(value)                 (PWM_IER2_CMPU7_Msk & (_UINT32_(value) << PWM_IER2_CMPU7_Pos)) /* Assigment of value for CMPU7 in the PWM_IER2 register */
#define PWM_IER2_Msk                          _UINT32_(0x00FFFF09)                                 /* (PWM_IER2) Register Mask  */

#define PWM_IER2_CMPM_Pos                     _UINT32_(8)                                          /* (PWM_IER2 Position) Comparison x Match Interrupt Enable */
#define PWM_IER2_CMPM_Msk                     (_UINT32_(0xFF) << PWM_IER2_CMPM_Pos)                /* (PWM_IER2 Mask) CMPM */
#define PWM_IER2_CMPM(value)                  (PWM_IER2_CMPM_Msk & (_UINT32_(value) << PWM_IER2_CMPM_Pos)) 
#define PWM_IER2_CMPU_Pos                     _UINT32_(16)                                         /* (PWM_IER2 Position) Comparison 7 Update Interrupt Enable */
#define PWM_IER2_CMPU_Msk                     (_UINT32_(0xFF) << PWM_IER2_CMPU_Pos)                /* (PWM_IER2 Mask) CMPU */
#define PWM_IER2_CMPU(value)                  (PWM_IER2_CMPU_Msk & (_UINT32_(value) << PWM_IER2_CMPU_Pos)) 

/* -------- PWM_IDR2 : (PWM Offset: 0x38) ( /W 32) PWM Interrupt Disable Register 2 -------- */
#define PWM_IDR2_WRDY_Pos                     _UINT32_(0)                                          /* (PWM_IDR2) Write Ready for Synchronous Channels Update Interrupt Disable Position */
#define PWM_IDR2_WRDY_Msk                     (_UINT32_(0x1) << PWM_IDR2_WRDY_Pos)                 /* (PWM_IDR2) Write Ready for Synchronous Channels Update Interrupt Disable Mask */
#define PWM_IDR2_WRDY(value)                  (PWM_IDR2_WRDY_Msk & (_UINT32_(value) << PWM_IDR2_WRDY_Pos)) /* Assigment of value for WRDY in the PWM_IDR2 register */
#define PWM_IDR2_UNRE_Pos                     _UINT32_(3)                                          /* (PWM_IDR2) Synchronous Channels Update Underrun Error Interrupt Disable Position */
#define PWM_IDR2_UNRE_Msk                     (_UINT32_(0x1) << PWM_IDR2_UNRE_Pos)                 /* (PWM_IDR2) Synchronous Channels Update Underrun Error Interrupt Disable Mask */
#define PWM_IDR2_UNRE(value)                  (PWM_IDR2_UNRE_Msk & (_UINT32_(value) << PWM_IDR2_UNRE_Pos)) /* Assigment of value for UNRE in the PWM_IDR2 register */
#define PWM_IDR2_CMPM0_Pos                    _UINT32_(8)                                          /* (PWM_IDR2) Comparison 0 Match Interrupt Disable Position */
#define PWM_IDR2_CMPM0_Msk                    (_UINT32_(0x1) << PWM_IDR2_CMPM0_Pos)                /* (PWM_IDR2) Comparison 0 Match Interrupt Disable Mask */
#define PWM_IDR2_CMPM0(value)                 (PWM_IDR2_CMPM0_Msk & (_UINT32_(value) << PWM_IDR2_CMPM0_Pos)) /* Assigment of value for CMPM0 in the PWM_IDR2 register */
#define PWM_IDR2_CMPM1_Pos                    _UINT32_(9)                                          /* (PWM_IDR2) Comparison 1 Match Interrupt Disable Position */
#define PWM_IDR2_CMPM1_Msk                    (_UINT32_(0x1) << PWM_IDR2_CMPM1_Pos)                /* (PWM_IDR2) Comparison 1 Match Interrupt Disable Mask */
#define PWM_IDR2_CMPM1(value)                 (PWM_IDR2_CMPM1_Msk & (_UINT32_(value) << PWM_IDR2_CMPM1_Pos)) /* Assigment of value for CMPM1 in the PWM_IDR2 register */
#define PWM_IDR2_CMPM2_Pos                    _UINT32_(10)                                         /* (PWM_IDR2) Comparison 2 Match Interrupt Disable Position */
#define PWM_IDR2_CMPM2_Msk                    (_UINT32_(0x1) << PWM_IDR2_CMPM2_Pos)                /* (PWM_IDR2) Comparison 2 Match Interrupt Disable Mask */
#define PWM_IDR2_CMPM2(value)                 (PWM_IDR2_CMPM2_Msk & (_UINT32_(value) << PWM_IDR2_CMPM2_Pos)) /* Assigment of value for CMPM2 in the PWM_IDR2 register */
#define PWM_IDR2_CMPM3_Pos                    _UINT32_(11)                                         /* (PWM_IDR2) Comparison 3 Match Interrupt Disable Position */
#define PWM_IDR2_CMPM3_Msk                    (_UINT32_(0x1) << PWM_IDR2_CMPM3_Pos)                /* (PWM_IDR2) Comparison 3 Match Interrupt Disable Mask */
#define PWM_IDR2_CMPM3(value)                 (PWM_IDR2_CMPM3_Msk & (_UINT32_(value) << PWM_IDR2_CMPM3_Pos)) /* Assigment of value for CMPM3 in the PWM_IDR2 register */
#define PWM_IDR2_CMPM4_Pos                    _UINT32_(12)                                         /* (PWM_IDR2) Comparison 4 Match Interrupt Disable Position */
#define PWM_IDR2_CMPM4_Msk                    (_UINT32_(0x1) << PWM_IDR2_CMPM4_Pos)                /* (PWM_IDR2) Comparison 4 Match Interrupt Disable Mask */
#define PWM_IDR2_CMPM4(value)                 (PWM_IDR2_CMPM4_Msk & (_UINT32_(value) << PWM_IDR2_CMPM4_Pos)) /* Assigment of value for CMPM4 in the PWM_IDR2 register */
#define PWM_IDR2_CMPM5_Pos                    _UINT32_(13)                                         /* (PWM_IDR2) Comparison 5 Match Interrupt Disable Position */
#define PWM_IDR2_CMPM5_Msk                    (_UINT32_(0x1) << PWM_IDR2_CMPM5_Pos)                /* (PWM_IDR2) Comparison 5 Match Interrupt Disable Mask */
#define PWM_IDR2_CMPM5(value)                 (PWM_IDR2_CMPM5_Msk & (_UINT32_(value) << PWM_IDR2_CMPM5_Pos)) /* Assigment of value for CMPM5 in the PWM_IDR2 register */
#define PWM_IDR2_CMPM6_Pos                    _UINT32_(14)                                         /* (PWM_IDR2) Comparison 6 Match Interrupt Disable Position */
#define PWM_IDR2_CMPM6_Msk                    (_UINT32_(0x1) << PWM_IDR2_CMPM6_Pos)                /* (PWM_IDR2) Comparison 6 Match Interrupt Disable Mask */
#define PWM_IDR2_CMPM6(value)                 (PWM_IDR2_CMPM6_Msk & (_UINT32_(value) << PWM_IDR2_CMPM6_Pos)) /* Assigment of value for CMPM6 in the PWM_IDR2 register */
#define PWM_IDR2_CMPM7_Pos                    _UINT32_(15)                                         /* (PWM_IDR2) Comparison 7 Match Interrupt Disable Position */
#define PWM_IDR2_CMPM7_Msk                    (_UINT32_(0x1) << PWM_IDR2_CMPM7_Pos)                /* (PWM_IDR2) Comparison 7 Match Interrupt Disable Mask */
#define PWM_IDR2_CMPM7(value)                 (PWM_IDR2_CMPM7_Msk & (_UINT32_(value) << PWM_IDR2_CMPM7_Pos)) /* Assigment of value for CMPM7 in the PWM_IDR2 register */
#define PWM_IDR2_CMPU0_Pos                    _UINT32_(16)                                         /* (PWM_IDR2) Comparison 0 Update Interrupt Disable Position */
#define PWM_IDR2_CMPU0_Msk                    (_UINT32_(0x1) << PWM_IDR2_CMPU0_Pos)                /* (PWM_IDR2) Comparison 0 Update Interrupt Disable Mask */
#define PWM_IDR2_CMPU0(value)                 (PWM_IDR2_CMPU0_Msk & (_UINT32_(value) << PWM_IDR2_CMPU0_Pos)) /* Assigment of value for CMPU0 in the PWM_IDR2 register */
#define PWM_IDR2_CMPU1_Pos                    _UINT32_(17)                                         /* (PWM_IDR2) Comparison 1 Update Interrupt Disable Position */
#define PWM_IDR2_CMPU1_Msk                    (_UINT32_(0x1) << PWM_IDR2_CMPU1_Pos)                /* (PWM_IDR2) Comparison 1 Update Interrupt Disable Mask */
#define PWM_IDR2_CMPU1(value)                 (PWM_IDR2_CMPU1_Msk & (_UINT32_(value) << PWM_IDR2_CMPU1_Pos)) /* Assigment of value for CMPU1 in the PWM_IDR2 register */
#define PWM_IDR2_CMPU2_Pos                    _UINT32_(18)                                         /* (PWM_IDR2) Comparison 2 Update Interrupt Disable Position */
#define PWM_IDR2_CMPU2_Msk                    (_UINT32_(0x1) << PWM_IDR2_CMPU2_Pos)                /* (PWM_IDR2) Comparison 2 Update Interrupt Disable Mask */
#define PWM_IDR2_CMPU2(value)                 (PWM_IDR2_CMPU2_Msk & (_UINT32_(value) << PWM_IDR2_CMPU2_Pos)) /* Assigment of value for CMPU2 in the PWM_IDR2 register */
#define PWM_IDR2_CMPU3_Pos                    _UINT32_(19)                                         /* (PWM_IDR2) Comparison 3 Update Interrupt Disable Position */
#define PWM_IDR2_CMPU3_Msk                    (_UINT32_(0x1) << PWM_IDR2_CMPU3_Pos)                /* (PWM_IDR2) Comparison 3 Update Interrupt Disable Mask */
#define PWM_IDR2_CMPU3(value)                 (PWM_IDR2_CMPU3_Msk & (_UINT32_(value) << PWM_IDR2_CMPU3_Pos)) /* Assigment of value for CMPU3 in the PWM_IDR2 register */
#define PWM_IDR2_CMPU4_Pos                    _UINT32_(20)                                         /* (PWM_IDR2) Comparison 4 Update Interrupt Disable Position */
#define PWM_IDR2_CMPU4_Msk                    (_UINT32_(0x1) << PWM_IDR2_CMPU4_Pos)                /* (PWM_IDR2) Comparison 4 Update Interrupt Disable Mask */
#define PWM_IDR2_CMPU4(value)                 (PWM_IDR2_CMPU4_Msk & (_UINT32_(value) << PWM_IDR2_CMPU4_Pos)) /* Assigment of value for CMPU4 in the PWM_IDR2 register */
#define PWM_IDR2_CMPU5_Pos                    _UINT32_(21)                                         /* (PWM_IDR2) Comparison 5 Update Interrupt Disable Position */
#define PWM_IDR2_CMPU5_Msk                    (_UINT32_(0x1) << PWM_IDR2_CMPU5_Pos)                /* (PWM_IDR2) Comparison 5 Update Interrupt Disable Mask */
#define PWM_IDR2_CMPU5(value)                 (PWM_IDR2_CMPU5_Msk & (_UINT32_(value) << PWM_IDR2_CMPU5_Pos)) /* Assigment of value for CMPU5 in the PWM_IDR2 register */
#define PWM_IDR2_CMPU6_Pos                    _UINT32_(22)                                         /* (PWM_IDR2) Comparison 6 Update Interrupt Disable Position */
#define PWM_IDR2_CMPU6_Msk                    (_UINT32_(0x1) << PWM_IDR2_CMPU6_Pos)                /* (PWM_IDR2) Comparison 6 Update Interrupt Disable Mask */
#define PWM_IDR2_CMPU6(value)                 (PWM_IDR2_CMPU6_Msk & (_UINT32_(value) << PWM_IDR2_CMPU6_Pos)) /* Assigment of value for CMPU6 in the PWM_IDR2 register */
#define PWM_IDR2_CMPU7_Pos                    _UINT32_(23)                                         /* (PWM_IDR2) Comparison 7 Update Interrupt Disable Position */
#define PWM_IDR2_CMPU7_Msk                    (_UINT32_(0x1) << PWM_IDR2_CMPU7_Pos)                /* (PWM_IDR2) Comparison 7 Update Interrupt Disable Mask */
#define PWM_IDR2_CMPU7(value)                 (PWM_IDR2_CMPU7_Msk & (_UINT32_(value) << PWM_IDR2_CMPU7_Pos)) /* Assigment of value for CMPU7 in the PWM_IDR2 register */
#define PWM_IDR2_Msk                          _UINT32_(0x00FFFF09)                                 /* (PWM_IDR2) Register Mask  */

#define PWM_IDR2_CMPM_Pos                     _UINT32_(8)                                          /* (PWM_IDR2 Position) Comparison x Match Interrupt Disable */
#define PWM_IDR2_CMPM_Msk                     (_UINT32_(0xFF) << PWM_IDR2_CMPM_Pos)                /* (PWM_IDR2 Mask) CMPM */
#define PWM_IDR2_CMPM(value)                  (PWM_IDR2_CMPM_Msk & (_UINT32_(value) << PWM_IDR2_CMPM_Pos)) 
#define PWM_IDR2_CMPU_Pos                     _UINT32_(16)                                         /* (PWM_IDR2 Position) Comparison 7 Update Interrupt Disable */
#define PWM_IDR2_CMPU_Msk                     (_UINT32_(0xFF) << PWM_IDR2_CMPU_Pos)                /* (PWM_IDR2 Mask) CMPU */
#define PWM_IDR2_CMPU(value)                  (PWM_IDR2_CMPU_Msk & (_UINT32_(value) << PWM_IDR2_CMPU_Pos)) 

/* -------- PWM_IMR2 : (PWM Offset: 0x3C) ( R/ 32) PWM Interrupt Mask Register 2 -------- */
#define PWM_IMR2_RESETVALUE                   _UINT32_(0x00)                                       /*  (PWM_IMR2) PWM Interrupt Mask Register 2  Reset Value */

#define PWM_IMR2_WRDY_Pos                     _UINT32_(0)                                          /* (PWM_IMR2) Write Ready for Synchronous Channels Update Interrupt Mask Position */
#define PWM_IMR2_WRDY_Msk                     (_UINT32_(0x1) << PWM_IMR2_WRDY_Pos)                 /* (PWM_IMR2) Write Ready for Synchronous Channels Update Interrupt Mask Mask */
#define PWM_IMR2_WRDY(value)                  (PWM_IMR2_WRDY_Msk & (_UINT32_(value) << PWM_IMR2_WRDY_Pos)) /* Assigment of value for WRDY in the PWM_IMR2 register */
#define PWM_IMR2_UNRE_Pos                     _UINT32_(3)                                          /* (PWM_IMR2) Synchronous Channels Update Underrun Error Interrupt Mask Position */
#define PWM_IMR2_UNRE_Msk                     (_UINT32_(0x1) << PWM_IMR2_UNRE_Pos)                 /* (PWM_IMR2) Synchronous Channels Update Underrun Error Interrupt Mask Mask */
#define PWM_IMR2_UNRE(value)                  (PWM_IMR2_UNRE_Msk & (_UINT32_(value) << PWM_IMR2_UNRE_Pos)) /* Assigment of value for UNRE in the PWM_IMR2 register */
#define PWM_IMR2_CMPM0_Pos                    _UINT32_(8)                                          /* (PWM_IMR2) Comparison 0 Match Interrupt Mask Position */
#define PWM_IMR2_CMPM0_Msk                    (_UINT32_(0x1) << PWM_IMR2_CMPM0_Pos)                /* (PWM_IMR2) Comparison 0 Match Interrupt Mask Mask */
#define PWM_IMR2_CMPM0(value)                 (PWM_IMR2_CMPM0_Msk & (_UINT32_(value) << PWM_IMR2_CMPM0_Pos)) /* Assigment of value for CMPM0 in the PWM_IMR2 register */
#define PWM_IMR2_CMPM1_Pos                    _UINT32_(9)                                          /* (PWM_IMR2) Comparison 1 Match Interrupt Mask Position */
#define PWM_IMR2_CMPM1_Msk                    (_UINT32_(0x1) << PWM_IMR2_CMPM1_Pos)                /* (PWM_IMR2) Comparison 1 Match Interrupt Mask Mask */
#define PWM_IMR2_CMPM1(value)                 (PWM_IMR2_CMPM1_Msk & (_UINT32_(value) << PWM_IMR2_CMPM1_Pos)) /* Assigment of value for CMPM1 in the PWM_IMR2 register */
#define PWM_IMR2_CMPM2_Pos                    _UINT32_(10)                                         /* (PWM_IMR2) Comparison 2 Match Interrupt Mask Position */
#define PWM_IMR2_CMPM2_Msk                    (_UINT32_(0x1) << PWM_IMR2_CMPM2_Pos)                /* (PWM_IMR2) Comparison 2 Match Interrupt Mask Mask */
#define PWM_IMR2_CMPM2(value)                 (PWM_IMR2_CMPM2_Msk & (_UINT32_(value) << PWM_IMR2_CMPM2_Pos)) /* Assigment of value for CMPM2 in the PWM_IMR2 register */
#define PWM_IMR2_CMPM3_Pos                    _UINT32_(11)                                         /* (PWM_IMR2) Comparison 3 Match Interrupt Mask Position */
#define PWM_IMR2_CMPM3_Msk                    (_UINT32_(0x1) << PWM_IMR2_CMPM3_Pos)                /* (PWM_IMR2) Comparison 3 Match Interrupt Mask Mask */
#define PWM_IMR2_CMPM3(value)                 (PWM_IMR2_CMPM3_Msk & (_UINT32_(value) << PWM_IMR2_CMPM3_Pos)) /* Assigment of value for CMPM3 in the PWM_IMR2 register */
#define PWM_IMR2_CMPM4_Pos                    _UINT32_(12)                                         /* (PWM_IMR2) Comparison 4 Match Interrupt Mask Position */
#define PWM_IMR2_CMPM4_Msk                    (_UINT32_(0x1) << PWM_IMR2_CMPM4_Pos)                /* (PWM_IMR2) Comparison 4 Match Interrupt Mask Mask */
#define PWM_IMR2_CMPM4(value)                 (PWM_IMR2_CMPM4_Msk & (_UINT32_(value) << PWM_IMR2_CMPM4_Pos)) /* Assigment of value for CMPM4 in the PWM_IMR2 register */
#define PWM_IMR2_CMPM5_Pos                    _UINT32_(13)                                         /* (PWM_IMR2) Comparison 5 Match Interrupt Mask Position */
#define PWM_IMR2_CMPM5_Msk                    (_UINT32_(0x1) << PWM_IMR2_CMPM5_Pos)                /* (PWM_IMR2) Comparison 5 Match Interrupt Mask Mask */
#define PWM_IMR2_CMPM5(value)                 (PWM_IMR2_CMPM5_Msk & (_UINT32_(value) << PWM_IMR2_CMPM5_Pos)) /* Assigment of value for CMPM5 in the PWM_IMR2 register */
#define PWM_IMR2_CMPM6_Pos                    _UINT32_(14)                                         /* (PWM_IMR2) Comparison 6 Match Interrupt Mask Position */
#define PWM_IMR2_CMPM6_Msk                    (_UINT32_(0x1) << PWM_IMR2_CMPM6_Pos)                /* (PWM_IMR2) Comparison 6 Match Interrupt Mask Mask */
#define PWM_IMR2_CMPM6(value)                 (PWM_IMR2_CMPM6_Msk & (_UINT32_(value) << PWM_IMR2_CMPM6_Pos)) /* Assigment of value for CMPM6 in the PWM_IMR2 register */
#define PWM_IMR2_CMPM7_Pos                    _UINT32_(15)                                         /* (PWM_IMR2) Comparison 7 Match Interrupt Mask Position */
#define PWM_IMR2_CMPM7_Msk                    (_UINT32_(0x1) << PWM_IMR2_CMPM7_Pos)                /* (PWM_IMR2) Comparison 7 Match Interrupt Mask Mask */
#define PWM_IMR2_CMPM7(value)                 (PWM_IMR2_CMPM7_Msk & (_UINT32_(value) << PWM_IMR2_CMPM7_Pos)) /* Assigment of value for CMPM7 in the PWM_IMR2 register */
#define PWM_IMR2_CMPU0_Pos                    _UINT32_(16)                                         /* (PWM_IMR2) Comparison 0 Update Interrupt Mask Position */
#define PWM_IMR2_CMPU0_Msk                    (_UINT32_(0x1) << PWM_IMR2_CMPU0_Pos)                /* (PWM_IMR2) Comparison 0 Update Interrupt Mask Mask */
#define PWM_IMR2_CMPU0(value)                 (PWM_IMR2_CMPU0_Msk & (_UINT32_(value) << PWM_IMR2_CMPU0_Pos)) /* Assigment of value for CMPU0 in the PWM_IMR2 register */
#define PWM_IMR2_CMPU1_Pos                    _UINT32_(17)                                         /* (PWM_IMR2) Comparison 1 Update Interrupt Mask Position */
#define PWM_IMR2_CMPU1_Msk                    (_UINT32_(0x1) << PWM_IMR2_CMPU1_Pos)                /* (PWM_IMR2) Comparison 1 Update Interrupt Mask Mask */
#define PWM_IMR2_CMPU1(value)                 (PWM_IMR2_CMPU1_Msk & (_UINT32_(value) << PWM_IMR2_CMPU1_Pos)) /* Assigment of value for CMPU1 in the PWM_IMR2 register */
#define PWM_IMR2_CMPU2_Pos                    _UINT32_(18)                                         /* (PWM_IMR2) Comparison 2 Update Interrupt Mask Position */
#define PWM_IMR2_CMPU2_Msk                    (_UINT32_(0x1) << PWM_IMR2_CMPU2_Pos)                /* (PWM_IMR2) Comparison 2 Update Interrupt Mask Mask */
#define PWM_IMR2_CMPU2(value)                 (PWM_IMR2_CMPU2_Msk & (_UINT32_(value) << PWM_IMR2_CMPU2_Pos)) /* Assigment of value for CMPU2 in the PWM_IMR2 register */
#define PWM_IMR2_CMPU3_Pos                    _UINT32_(19)                                         /* (PWM_IMR2) Comparison 3 Update Interrupt Mask Position */
#define PWM_IMR2_CMPU3_Msk                    (_UINT32_(0x1) << PWM_IMR2_CMPU3_Pos)                /* (PWM_IMR2) Comparison 3 Update Interrupt Mask Mask */
#define PWM_IMR2_CMPU3(value)                 (PWM_IMR2_CMPU3_Msk & (_UINT32_(value) << PWM_IMR2_CMPU3_Pos)) /* Assigment of value for CMPU3 in the PWM_IMR2 register */
#define PWM_IMR2_CMPU4_Pos                    _UINT32_(20)                                         /* (PWM_IMR2) Comparison 4 Update Interrupt Mask Position */
#define PWM_IMR2_CMPU4_Msk                    (_UINT32_(0x1) << PWM_IMR2_CMPU4_Pos)                /* (PWM_IMR2) Comparison 4 Update Interrupt Mask Mask */
#define PWM_IMR2_CMPU4(value)                 (PWM_IMR2_CMPU4_Msk & (_UINT32_(value) << PWM_IMR2_CMPU4_Pos)) /* Assigment of value for CMPU4 in the PWM_IMR2 register */
#define PWM_IMR2_CMPU5_Pos                    _UINT32_(21)                                         /* (PWM_IMR2) Comparison 5 Update Interrupt Mask Position */
#define PWM_IMR2_CMPU5_Msk                    (_UINT32_(0x1) << PWM_IMR2_CMPU5_Pos)                /* (PWM_IMR2) Comparison 5 Update Interrupt Mask Mask */
#define PWM_IMR2_CMPU5(value)                 (PWM_IMR2_CMPU5_Msk & (_UINT32_(value) << PWM_IMR2_CMPU5_Pos)) /* Assigment of value for CMPU5 in the PWM_IMR2 register */
#define PWM_IMR2_CMPU6_Pos                    _UINT32_(22)                                         /* (PWM_IMR2) Comparison 6 Update Interrupt Mask Position */
#define PWM_IMR2_CMPU6_Msk                    (_UINT32_(0x1) << PWM_IMR2_CMPU6_Pos)                /* (PWM_IMR2) Comparison 6 Update Interrupt Mask Mask */
#define PWM_IMR2_CMPU6(value)                 (PWM_IMR2_CMPU6_Msk & (_UINT32_(value) << PWM_IMR2_CMPU6_Pos)) /* Assigment of value for CMPU6 in the PWM_IMR2 register */
#define PWM_IMR2_CMPU7_Pos                    _UINT32_(23)                                         /* (PWM_IMR2) Comparison 7 Update Interrupt Mask Position */
#define PWM_IMR2_CMPU7_Msk                    (_UINT32_(0x1) << PWM_IMR2_CMPU7_Pos)                /* (PWM_IMR2) Comparison 7 Update Interrupt Mask Mask */
#define PWM_IMR2_CMPU7(value)                 (PWM_IMR2_CMPU7_Msk & (_UINT32_(value) << PWM_IMR2_CMPU7_Pos)) /* Assigment of value for CMPU7 in the PWM_IMR2 register */
#define PWM_IMR2_Msk                          _UINT32_(0x00FFFF09)                                 /* (PWM_IMR2) Register Mask  */

#define PWM_IMR2_CMPM_Pos                     _UINT32_(8)                                          /* (PWM_IMR2 Position) Comparison x Match Interrupt Mask */
#define PWM_IMR2_CMPM_Msk                     (_UINT32_(0xFF) << PWM_IMR2_CMPM_Pos)                /* (PWM_IMR2 Mask) CMPM */
#define PWM_IMR2_CMPM(value)                  (PWM_IMR2_CMPM_Msk & (_UINT32_(value) << PWM_IMR2_CMPM_Pos)) 
#define PWM_IMR2_CMPU_Pos                     _UINT32_(16)                                         /* (PWM_IMR2 Position) Comparison 7 Update Interrupt Mask */
#define PWM_IMR2_CMPU_Msk                     (_UINT32_(0xFF) << PWM_IMR2_CMPU_Pos)                /* (PWM_IMR2 Mask) CMPU */
#define PWM_IMR2_CMPU(value)                  (PWM_IMR2_CMPU_Msk & (_UINT32_(value) << PWM_IMR2_CMPU_Pos)) 

/* -------- PWM_ISR2 : (PWM Offset: 0x40) ( R/ 32) PWM Interrupt Status Register 2 -------- */
#define PWM_ISR2_RESETVALUE                   _UINT32_(0x00)                                       /*  (PWM_ISR2) PWM Interrupt Status Register 2  Reset Value */

#define PWM_ISR2_WRDY_Pos                     _UINT32_(0)                                          /* (PWM_ISR2) Write Ready for Synchronous Channels Update Position */
#define PWM_ISR2_WRDY_Msk                     (_UINT32_(0x1) << PWM_ISR2_WRDY_Pos)                 /* (PWM_ISR2) Write Ready for Synchronous Channels Update Mask */
#define PWM_ISR2_WRDY(value)                  (PWM_ISR2_WRDY_Msk & (_UINT32_(value) << PWM_ISR2_WRDY_Pos)) /* Assigment of value for WRDY in the PWM_ISR2 register */
#define   PWM_ISR2_WRDY_0_Val                 _UINT32_(0x0)                                        /* (PWM_ISR2) New duty-cycle and dead-time values for the synchronous channels cannot be written.  */
#define   PWM_ISR2_WRDY_1_Val                 _UINT32_(0x1)                                        /* (PWM_ISR2) New duty-cycle and dead-time values for the synchronous channels can be written.  */
#define PWM_ISR2_WRDY_0                       (PWM_ISR2_WRDY_0_Val << PWM_ISR2_WRDY_Pos)           /* (PWM_ISR2) New duty-cycle and dead-time values for the synchronous channels cannot be written. Position  */
#define PWM_ISR2_WRDY_1                       (PWM_ISR2_WRDY_1_Val << PWM_ISR2_WRDY_Pos)           /* (PWM_ISR2) New duty-cycle and dead-time values for the synchronous channels can be written. Position  */
#define PWM_ISR2_UNRE_Pos                     _UINT32_(3)                                          /* (PWM_ISR2) Synchronous Channels Update Underrun Error Position */
#define PWM_ISR2_UNRE_Msk                     (_UINT32_(0x1) << PWM_ISR2_UNRE_Pos)                 /* (PWM_ISR2) Synchronous Channels Update Underrun Error Mask */
#define PWM_ISR2_UNRE(value)                  (PWM_ISR2_UNRE_Msk & (_UINT32_(value) << PWM_ISR2_UNRE_Pos)) /* Assigment of value for UNRE in the PWM_ISR2 register */
#define   PWM_ISR2_UNRE_0_Val                 _UINT32_(0x0)                                        /* (PWM_ISR2) No Synchronous Channels Update Underrun has occurred since the last read of the PWM_ISR2 register.  */
#define   PWM_ISR2_UNRE_1_Val                 _UINT32_(0x1)                                        /* (PWM_ISR2) At least one Synchronous Channels Update Underrun has occurred since the last read of the PWM_ISR2 register.  */
#define PWM_ISR2_UNRE_0                       (PWM_ISR2_UNRE_0_Val << PWM_ISR2_UNRE_Pos)           /* (PWM_ISR2) No Synchronous Channels Update Underrun has occurred since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_UNRE_1                       (PWM_ISR2_UNRE_1_Val << PWM_ISR2_UNRE_Pos)           /* (PWM_ISR2) At least one Synchronous Channels Update Underrun has occurred since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPM0_Pos                    _UINT32_(8)                                          /* (PWM_ISR2) Comparison 0 Match Position */
#define PWM_ISR2_CMPM0_Msk                    (_UINT32_(0x1) << PWM_ISR2_CMPM0_Pos)                /* (PWM_ISR2) Comparison 0 Match Mask */
#define PWM_ISR2_CMPM0(value)                 (PWM_ISR2_CMPM0_Msk & (_UINT32_(value) << PWM_ISR2_CMPM0_Pos)) /* Assigment of value for CMPM0 in the PWM_ISR2 register */
#define   PWM_ISR2_CMPM0_0_Val                _UINT32_(0x0)                                        /* (PWM_ISR2) The comparison x has not matched since the last read of the PWM_ISR2 register.  */
#define   PWM_ISR2_CMPM0_1_Val                _UINT32_(0x1)                                        /* (PWM_ISR2) The comparison x has matched at least one time since the last read of the PWM_ISR2 register.  */
#define PWM_ISR2_CMPM0_0                      (PWM_ISR2_CMPM0_0_Val << PWM_ISR2_CMPM0_Pos)         /* (PWM_ISR2) The comparison x has not matched since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPM0_1                      (PWM_ISR2_CMPM0_1_Val << PWM_ISR2_CMPM0_Pos)         /* (PWM_ISR2) The comparison x has matched at least one time since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPM1_Pos                    _UINT32_(9)                                          /* (PWM_ISR2) Comparison 1 Match Position */
#define PWM_ISR2_CMPM1_Msk                    (_UINT32_(0x1) << PWM_ISR2_CMPM1_Pos)                /* (PWM_ISR2) Comparison 1 Match Mask */
#define PWM_ISR2_CMPM1(value)                 (PWM_ISR2_CMPM1_Msk & (_UINT32_(value) << PWM_ISR2_CMPM1_Pos)) /* Assigment of value for CMPM1 in the PWM_ISR2 register */
#define   PWM_ISR2_CMPM1_0_Val                _UINT32_(0x0)                                        /* (PWM_ISR2) The comparison x has not matched since the last read of the PWM_ISR2 register.  */
#define   PWM_ISR2_CMPM1_1_Val                _UINT32_(0x1)                                        /* (PWM_ISR2) The comparison x has matched at least one time since the last read of the PWM_ISR2 register.  */
#define PWM_ISR2_CMPM1_0                      (PWM_ISR2_CMPM1_0_Val << PWM_ISR2_CMPM1_Pos)         /* (PWM_ISR2) The comparison x has not matched since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPM1_1                      (PWM_ISR2_CMPM1_1_Val << PWM_ISR2_CMPM1_Pos)         /* (PWM_ISR2) The comparison x has matched at least one time since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPM2_Pos                    _UINT32_(10)                                         /* (PWM_ISR2) Comparison 2 Match Position */
#define PWM_ISR2_CMPM2_Msk                    (_UINT32_(0x1) << PWM_ISR2_CMPM2_Pos)                /* (PWM_ISR2) Comparison 2 Match Mask */
#define PWM_ISR2_CMPM2(value)                 (PWM_ISR2_CMPM2_Msk & (_UINT32_(value) << PWM_ISR2_CMPM2_Pos)) /* Assigment of value for CMPM2 in the PWM_ISR2 register */
#define   PWM_ISR2_CMPM2_0_Val                _UINT32_(0x0)                                        /* (PWM_ISR2) The comparison x has not matched since the last read of the PWM_ISR2 register.  */
#define   PWM_ISR2_CMPM2_1_Val                _UINT32_(0x1)                                        /* (PWM_ISR2) The comparison x has matched at least one time since the last read of the PWM_ISR2 register.  */
#define PWM_ISR2_CMPM2_0                      (PWM_ISR2_CMPM2_0_Val << PWM_ISR2_CMPM2_Pos)         /* (PWM_ISR2) The comparison x has not matched since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPM2_1                      (PWM_ISR2_CMPM2_1_Val << PWM_ISR2_CMPM2_Pos)         /* (PWM_ISR2) The comparison x has matched at least one time since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPM3_Pos                    _UINT32_(11)                                         /* (PWM_ISR2) Comparison 3 Match Position */
#define PWM_ISR2_CMPM3_Msk                    (_UINT32_(0x1) << PWM_ISR2_CMPM3_Pos)                /* (PWM_ISR2) Comparison 3 Match Mask */
#define PWM_ISR2_CMPM3(value)                 (PWM_ISR2_CMPM3_Msk & (_UINT32_(value) << PWM_ISR2_CMPM3_Pos)) /* Assigment of value for CMPM3 in the PWM_ISR2 register */
#define   PWM_ISR2_CMPM3_0_Val                _UINT32_(0x0)                                        /* (PWM_ISR2) The comparison x has not matched since the last read of the PWM_ISR2 register.  */
#define   PWM_ISR2_CMPM3_1_Val                _UINT32_(0x1)                                        /* (PWM_ISR2) The comparison x has matched at least one time since the last read of the PWM_ISR2 register.  */
#define PWM_ISR2_CMPM3_0                      (PWM_ISR2_CMPM3_0_Val << PWM_ISR2_CMPM3_Pos)         /* (PWM_ISR2) The comparison x has not matched since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPM3_1                      (PWM_ISR2_CMPM3_1_Val << PWM_ISR2_CMPM3_Pos)         /* (PWM_ISR2) The comparison x has matched at least one time since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPM4_Pos                    _UINT32_(12)                                         /* (PWM_ISR2) Comparison 4 Match Position */
#define PWM_ISR2_CMPM4_Msk                    (_UINT32_(0x1) << PWM_ISR2_CMPM4_Pos)                /* (PWM_ISR2) Comparison 4 Match Mask */
#define PWM_ISR2_CMPM4(value)                 (PWM_ISR2_CMPM4_Msk & (_UINT32_(value) << PWM_ISR2_CMPM4_Pos)) /* Assigment of value for CMPM4 in the PWM_ISR2 register */
#define   PWM_ISR2_CMPM4_0_Val                _UINT32_(0x0)                                        /* (PWM_ISR2) The comparison x has not matched since the last read of the PWM_ISR2 register.  */
#define   PWM_ISR2_CMPM4_1_Val                _UINT32_(0x1)                                        /* (PWM_ISR2) The comparison x has matched at least one time since the last read of the PWM_ISR2 register.  */
#define PWM_ISR2_CMPM4_0                      (PWM_ISR2_CMPM4_0_Val << PWM_ISR2_CMPM4_Pos)         /* (PWM_ISR2) The comparison x has not matched since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPM4_1                      (PWM_ISR2_CMPM4_1_Val << PWM_ISR2_CMPM4_Pos)         /* (PWM_ISR2) The comparison x has matched at least one time since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPM5_Pos                    _UINT32_(13)                                         /* (PWM_ISR2) Comparison 5 Match Position */
#define PWM_ISR2_CMPM5_Msk                    (_UINT32_(0x1) << PWM_ISR2_CMPM5_Pos)                /* (PWM_ISR2) Comparison 5 Match Mask */
#define PWM_ISR2_CMPM5(value)                 (PWM_ISR2_CMPM5_Msk & (_UINT32_(value) << PWM_ISR2_CMPM5_Pos)) /* Assigment of value for CMPM5 in the PWM_ISR2 register */
#define   PWM_ISR2_CMPM5_0_Val                _UINT32_(0x0)                                        /* (PWM_ISR2) The comparison x has not matched since the last read of the PWM_ISR2 register.  */
#define   PWM_ISR2_CMPM5_1_Val                _UINT32_(0x1)                                        /* (PWM_ISR2) The comparison x has matched at least one time since the last read of the PWM_ISR2 register.  */
#define PWM_ISR2_CMPM5_0                      (PWM_ISR2_CMPM5_0_Val << PWM_ISR2_CMPM5_Pos)         /* (PWM_ISR2) The comparison x has not matched since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPM5_1                      (PWM_ISR2_CMPM5_1_Val << PWM_ISR2_CMPM5_Pos)         /* (PWM_ISR2) The comparison x has matched at least one time since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPM6_Pos                    _UINT32_(14)                                         /* (PWM_ISR2) Comparison 6 Match Position */
#define PWM_ISR2_CMPM6_Msk                    (_UINT32_(0x1) << PWM_ISR2_CMPM6_Pos)                /* (PWM_ISR2) Comparison 6 Match Mask */
#define PWM_ISR2_CMPM6(value)                 (PWM_ISR2_CMPM6_Msk & (_UINT32_(value) << PWM_ISR2_CMPM6_Pos)) /* Assigment of value for CMPM6 in the PWM_ISR2 register */
#define   PWM_ISR2_CMPM6_0_Val                _UINT32_(0x0)                                        /* (PWM_ISR2) The comparison x has not matched since the last read of the PWM_ISR2 register.  */
#define   PWM_ISR2_CMPM6_1_Val                _UINT32_(0x1)                                        /* (PWM_ISR2) The comparison x has matched at least one time since the last read of the PWM_ISR2 register.  */
#define PWM_ISR2_CMPM6_0                      (PWM_ISR2_CMPM6_0_Val << PWM_ISR2_CMPM6_Pos)         /* (PWM_ISR2) The comparison x has not matched since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPM6_1                      (PWM_ISR2_CMPM6_1_Val << PWM_ISR2_CMPM6_Pos)         /* (PWM_ISR2) The comparison x has matched at least one time since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPM7_Pos                    _UINT32_(15)                                         /* (PWM_ISR2) Comparison 7 Match Position */
#define PWM_ISR2_CMPM7_Msk                    (_UINT32_(0x1) << PWM_ISR2_CMPM7_Pos)                /* (PWM_ISR2) Comparison 7 Match Mask */
#define PWM_ISR2_CMPM7(value)                 (PWM_ISR2_CMPM7_Msk & (_UINT32_(value) << PWM_ISR2_CMPM7_Pos)) /* Assigment of value for CMPM7 in the PWM_ISR2 register */
#define   PWM_ISR2_CMPM7_0_Val                _UINT32_(0x0)                                        /* (PWM_ISR2) The comparison x has not matched since the last read of the PWM_ISR2 register.  */
#define   PWM_ISR2_CMPM7_1_Val                _UINT32_(0x1)                                        /* (PWM_ISR2) The comparison x has matched at least one time since the last read of the PWM_ISR2 register.  */
#define PWM_ISR2_CMPM7_0                      (PWM_ISR2_CMPM7_0_Val << PWM_ISR2_CMPM7_Pos)         /* (PWM_ISR2) The comparison x has not matched since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPM7_1                      (PWM_ISR2_CMPM7_1_Val << PWM_ISR2_CMPM7_Pos)         /* (PWM_ISR2) The comparison x has matched at least one time since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPU0_Pos                    _UINT32_(16)                                         /* (PWM_ISR2) Comparison 0 Update Position */
#define PWM_ISR2_CMPU0_Msk                    (_UINT32_(0x1) << PWM_ISR2_CMPU0_Pos)                /* (PWM_ISR2) Comparison 0 Update Mask */
#define PWM_ISR2_CMPU0(value)                 (PWM_ISR2_CMPU0_Msk & (_UINT32_(value) << PWM_ISR2_CMPU0_Pos)) /* Assigment of value for CMPU0 in the PWM_ISR2 register */
#define   PWM_ISR2_CMPU0_0_Val                _UINT32_(0x0)                                        /* (PWM_ISR2) The comparison x has not been updated since the last read of the PWM_ISR2 register.  */
#define   PWM_ISR2_CMPU0_1_Val                _UINT32_(0x1)                                        /* (PWM_ISR2) The comparison x has been updated at least one time since the last read of the PWM_ISR2 register.  */
#define PWM_ISR2_CMPU0_0                      (PWM_ISR2_CMPU0_0_Val << PWM_ISR2_CMPU0_Pos)         /* (PWM_ISR2) The comparison x has not been updated since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPU0_1                      (PWM_ISR2_CMPU0_1_Val << PWM_ISR2_CMPU0_Pos)         /* (PWM_ISR2) The comparison x has been updated at least one time since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPU1_Pos                    _UINT32_(17)                                         /* (PWM_ISR2) Comparison 1 Update Position */
#define PWM_ISR2_CMPU1_Msk                    (_UINT32_(0x1) << PWM_ISR2_CMPU1_Pos)                /* (PWM_ISR2) Comparison 1 Update Mask */
#define PWM_ISR2_CMPU1(value)                 (PWM_ISR2_CMPU1_Msk & (_UINT32_(value) << PWM_ISR2_CMPU1_Pos)) /* Assigment of value for CMPU1 in the PWM_ISR2 register */
#define   PWM_ISR2_CMPU1_0_Val                _UINT32_(0x0)                                        /* (PWM_ISR2) The comparison x has not been updated since the last read of the PWM_ISR2 register.  */
#define   PWM_ISR2_CMPU1_1_Val                _UINT32_(0x1)                                        /* (PWM_ISR2) The comparison x has been updated at least one time since the last read of the PWM_ISR2 register.  */
#define PWM_ISR2_CMPU1_0                      (PWM_ISR2_CMPU1_0_Val << PWM_ISR2_CMPU1_Pos)         /* (PWM_ISR2) The comparison x has not been updated since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPU1_1                      (PWM_ISR2_CMPU1_1_Val << PWM_ISR2_CMPU1_Pos)         /* (PWM_ISR2) The comparison x has been updated at least one time since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPU2_Pos                    _UINT32_(18)                                         /* (PWM_ISR2) Comparison 2 Update Position */
#define PWM_ISR2_CMPU2_Msk                    (_UINT32_(0x1) << PWM_ISR2_CMPU2_Pos)                /* (PWM_ISR2) Comparison 2 Update Mask */
#define PWM_ISR2_CMPU2(value)                 (PWM_ISR2_CMPU2_Msk & (_UINT32_(value) << PWM_ISR2_CMPU2_Pos)) /* Assigment of value for CMPU2 in the PWM_ISR2 register */
#define   PWM_ISR2_CMPU2_0_Val                _UINT32_(0x0)                                        /* (PWM_ISR2) The comparison x has not been updated since the last read of the PWM_ISR2 register.  */
#define   PWM_ISR2_CMPU2_1_Val                _UINT32_(0x1)                                        /* (PWM_ISR2) The comparison x has been updated at least one time since the last read of the PWM_ISR2 register.  */
#define PWM_ISR2_CMPU2_0                      (PWM_ISR2_CMPU2_0_Val << PWM_ISR2_CMPU2_Pos)         /* (PWM_ISR2) The comparison x has not been updated since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPU2_1                      (PWM_ISR2_CMPU2_1_Val << PWM_ISR2_CMPU2_Pos)         /* (PWM_ISR2) The comparison x has been updated at least one time since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPU3_Pos                    _UINT32_(19)                                         /* (PWM_ISR2) Comparison 3 Update Position */
#define PWM_ISR2_CMPU3_Msk                    (_UINT32_(0x1) << PWM_ISR2_CMPU3_Pos)                /* (PWM_ISR2) Comparison 3 Update Mask */
#define PWM_ISR2_CMPU3(value)                 (PWM_ISR2_CMPU3_Msk & (_UINT32_(value) << PWM_ISR2_CMPU3_Pos)) /* Assigment of value for CMPU3 in the PWM_ISR2 register */
#define   PWM_ISR2_CMPU3_0_Val                _UINT32_(0x0)                                        /* (PWM_ISR2) The comparison x has not been updated since the last read of the PWM_ISR2 register.  */
#define   PWM_ISR2_CMPU3_1_Val                _UINT32_(0x1)                                        /* (PWM_ISR2) The comparison x has been updated at least one time since the last read of the PWM_ISR2 register.  */
#define PWM_ISR2_CMPU3_0                      (PWM_ISR2_CMPU3_0_Val << PWM_ISR2_CMPU3_Pos)         /* (PWM_ISR2) The comparison x has not been updated since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPU3_1                      (PWM_ISR2_CMPU3_1_Val << PWM_ISR2_CMPU3_Pos)         /* (PWM_ISR2) The comparison x has been updated at least one time since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPU4_Pos                    _UINT32_(20)                                         /* (PWM_ISR2) Comparison 4 Update Position */
#define PWM_ISR2_CMPU4_Msk                    (_UINT32_(0x1) << PWM_ISR2_CMPU4_Pos)                /* (PWM_ISR2) Comparison 4 Update Mask */
#define PWM_ISR2_CMPU4(value)                 (PWM_ISR2_CMPU4_Msk & (_UINT32_(value) << PWM_ISR2_CMPU4_Pos)) /* Assigment of value for CMPU4 in the PWM_ISR2 register */
#define   PWM_ISR2_CMPU4_0_Val                _UINT32_(0x0)                                        /* (PWM_ISR2) The comparison x has not been updated since the last read of the PWM_ISR2 register.  */
#define   PWM_ISR2_CMPU4_1_Val                _UINT32_(0x1)                                        /* (PWM_ISR2) The comparison x has been updated at least one time since the last read of the PWM_ISR2 register.  */
#define PWM_ISR2_CMPU4_0                      (PWM_ISR2_CMPU4_0_Val << PWM_ISR2_CMPU4_Pos)         /* (PWM_ISR2) The comparison x has not been updated since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPU4_1                      (PWM_ISR2_CMPU4_1_Val << PWM_ISR2_CMPU4_Pos)         /* (PWM_ISR2) The comparison x has been updated at least one time since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPU5_Pos                    _UINT32_(21)                                         /* (PWM_ISR2) Comparison 5 Update Position */
#define PWM_ISR2_CMPU5_Msk                    (_UINT32_(0x1) << PWM_ISR2_CMPU5_Pos)                /* (PWM_ISR2) Comparison 5 Update Mask */
#define PWM_ISR2_CMPU5(value)                 (PWM_ISR2_CMPU5_Msk & (_UINT32_(value) << PWM_ISR2_CMPU5_Pos)) /* Assigment of value for CMPU5 in the PWM_ISR2 register */
#define   PWM_ISR2_CMPU5_0_Val                _UINT32_(0x0)                                        /* (PWM_ISR2) The comparison x has not been updated since the last read of the PWM_ISR2 register.  */
#define   PWM_ISR2_CMPU5_1_Val                _UINT32_(0x1)                                        /* (PWM_ISR2) The comparison x has been updated at least one time since the last read of the PWM_ISR2 register.  */
#define PWM_ISR2_CMPU5_0                      (PWM_ISR2_CMPU5_0_Val << PWM_ISR2_CMPU5_Pos)         /* (PWM_ISR2) The comparison x has not been updated since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPU5_1                      (PWM_ISR2_CMPU5_1_Val << PWM_ISR2_CMPU5_Pos)         /* (PWM_ISR2) The comparison x has been updated at least one time since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPU6_Pos                    _UINT32_(22)                                         /* (PWM_ISR2) Comparison 6 Update Position */
#define PWM_ISR2_CMPU6_Msk                    (_UINT32_(0x1) << PWM_ISR2_CMPU6_Pos)                /* (PWM_ISR2) Comparison 6 Update Mask */
#define PWM_ISR2_CMPU6(value)                 (PWM_ISR2_CMPU6_Msk & (_UINT32_(value) << PWM_ISR2_CMPU6_Pos)) /* Assigment of value for CMPU6 in the PWM_ISR2 register */
#define   PWM_ISR2_CMPU6_0_Val                _UINT32_(0x0)                                        /* (PWM_ISR2) The comparison x has not been updated since the last read of the PWM_ISR2 register.  */
#define   PWM_ISR2_CMPU6_1_Val                _UINT32_(0x1)                                        /* (PWM_ISR2) The comparison x has been updated at least one time since the last read of the PWM_ISR2 register.  */
#define PWM_ISR2_CMPU6_0                      (PWM_ISR2_CMPU6_0_Val << PWM_ISR2_CMPU6_Pos)         /* (PWM_ISR2) The comparison x has not been updated since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPU6_1                      (PWM_ISR2_CMPU6_1_Val << PWM_ISR2_CMPU6_Pos)         /* (PWM_ISR2) The comparison x has been updated at least one time since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPU7_Pos                    _UINT32_(23)                                         /* (PWM_ISR2) Comparison 7 Update Position */
#define PWM_ISR2_CMPU7_Msk                    (_UINT32_(0x1) << PWM_ISR2_CMPU7_Pos)                /* (PWM_ISR2) Comparison 7 Update Mask */
#define PWM_ISR2_CMPU7(value)                 (PWM_ISR2_CMPU7_Msk & (_UINT32_(value) << PWM_ISR2_CMPU7_Pos)) /* Assigment of value for CMPU7 in the PWM_ISR2 register */
#define   PWM_ISR2_CMPU7_0_Val                _UINT32_(0x0)                                        /* (PWM_ISR2) The comparison x has not been updated since the last read of the PWM_ISR2 register.  */
#define   PWM_ISR2_CMPU7_1_Val                _UINT32_(0x1)                                        /* (PWM_ISR2) The comparison x has been updated at least one time since the last read of the PWM_ISR2 register.  */
#define PWM_ISR2_CMPU7_0                      (PWM_ISR2_CMPU7_0_Val << PWM_ISR2_CMPU7_Pos)         /* (PWM_ISR2) The comparison x has not been updated since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_CMPU7_1                      (PWM_ISR2_CMPU7_1_Val << PWM_ISR2_CMPU7_Pos)         /* (PWM_ISR2) The comparison x has been updated at least one time since the last read of the PWM_ISR2 register. Position  */
#define PWM_ISR2_Msk                          _UINT32_(0x00FFFF09)                                 /* (PWM_ISR2) Register Mask  */

#define PWM_ISR2_CMPM_Pos                     _UINT32_(8)                                          /* (PWM_ISR2 Position) Comparison x Match */
#define PWM_ISR2_CMPM_Msk                     (_UINT32_(0xFF) << PWM_ISR2_CMPM_Pos)                /* (PWM_ISR2 Mask) CMPM */
#define PWM_ISR2_CMPM(value)                  (PWM_ISR2_CMPM_Msk & (_UINT32_(value) << PWM_ISR2_CMPM_Pos)) 
#define PWM_ISR2_CMPU_Pos                     _UINT32_(16)                                         /* (PWM_ISR2 Position) Comparison 7 Update */
#define PWM_ISR2_CMPU_Msk                     (_UINT32_(0xFF) << PWM_ISR2_CMPU_Pos)                /* (PWM_ISR2 Mask) CMPU */
#define PWM_ISR2_CMPU(value)                  (PWM_ISR2_CMPU_Msk & (_UINT32_(value) << PWM_ISR2_CMPU_Pos)) 

/* -------- PWM_OOV : (PWM Offset: 0x44) (R/W 32) PWM Output Override Value Register -------- */
#define PWM_OOV_RESETVALUE                    _UINT32_(0x00)                                       /*  (PWM_OOV) PWM Output Override Value Register  Reset Value */

#define PWM_OOV_OOVH0_Pos                     _UINT32_(0)                                          /* (PWM_OOV) Output Override Value for PWMH output of the channel 0 Position */
#define PWM_OOV_OOVH0_Msk                     (_UINT32_(0x1) << PWM_OOV_OOVH0_Pos)                 /* (PWM_OOV) Output Override Value for PWMH output of the channel 0 Mask */
#define PWM_OOV_OOVH0(value)                  (PWM_OOV_OOVH0_Msk & (_UINT32_(value) << PWM_OOV_OOVH0_Pos)) /* Assigment of value for OOVH0 in the PWM_OOV register */
#define   PWM_OOV_OOVH0_0_Val                 _UINT32_(0x0)                                        /* (PWM_OOV) Override value is 0 for PWMH output of channel x.  */
#define   PWM_OOV_OOVH0_1_Val                 _UINT32_(0x1)                                        /* (PWM_OOV) Override value is 1 for PWMH output of channel x.  */
#define PWM_OOV_OOVH0_0                       (PWM_OOV_OOVH0_0_Val << PWM_OOV_OOVH0_Pos)           /* (PWM_OOV) Override value is 0 for PWMH output of channel x. Position  */
#define PWM_OOV_OOVH0_1                       (PWM_OOV_OOVH0_1_Val << PWM_OOV_OOVH0_Pos)           /* (PWM_OOV) Override value is 1 for PWMH output of channel x. Position  */
#define PWM_OOV_OOVH1_Pos                     _UINT32_(1)                                          /* (PWM_OOV) Output Override Value for PWMH output of the channel 1 Position */
#define PWM_OOV_OOVH1_Msk                     (_UINT32_(0x1) << PWM_OOV_OOVH1_Pos)                 /* (PWM_OOV) Output Override Value for PWMH output of the channel 1 Mask */
#define PWM_OOV_OOVH1(value)                  (PWM_OOV_OOVH1_Msk & (_UINT32_(value) << PWM_OOV_OOVH1_Pos)) /* Assigment of value for OOVH1 in the PWM_OOV register */
#define   PWM_OOV_OOVH1_0_Val                 _UINT32_(0x0)                                        /* (PWM_OOV) Override value is 0 for PWMH output of channel x.  */
#define   PWM_OOV_OOVH1_1_Val                 _UINT32_(0x1)                                        /* (PWM_OOV) Override value is 1 for PWMH output of channel x.  */
#define PWM_OOV_OOVH1_0                       (PWM_OOV_OOVH1_0_Val << PWM_OOV_OOVH1_Pos)           /* (PWM_OOV) Override value is 0 for PWMH output of channel x. Position  */
#define PWM_OOV_OOVH1_1                       (PWM_OOV_OOVH1_1_Val << PWM_OOV_OOVH1_Pos)           /* (PWM_OOV) Override value is 1 for PWMH output of channel x. Position  */
#define PWM_OOV_OOVH2_Pos                     _UINT32_(2)                                          /* (PWM_OOV) Output Override Value for PWMH output of the channel 2 Position */
#define PWM_OOV_OOVH2_Msk                     (_UINT32_(0x1) << PWM_OOV_OOVH2_Pos)                 /* (PWM_OOV) Output Override Value for PWMH output of the channel 2 Mask */
#define PWM_OOV_OOVH2(value)                  (PWM_OOV_OOVH2_Msk & (_UINT32_(value) << PWM_OOV_OOVH2_Pos)) /* Assigment of value for OOVH2 in the PWM_OOV register */
#define   PWM_OOV_OOVH2_0_Val                 _UINT32_(0x0)                                        /* (PWM_OOV) Override value is 0 for PWMH output of channel x.  */
#define   PWM_OOV_OOVH2_1_Val                 _UINT32_(0x1)                                        /* (PWM_OOV) Override value is 1 for PWMH output of channel x.  */
#define PWM_OOV_OOVH2_0                       (PWM_OOV_OOVH2_0_Val << PWM_OOV_OOVH2_Pos)           /* (PWM_OOV) Override value is 0 for PWMH output of channel x. Position  */
#define PWM_OOV_OOVH2_1                       (PWM_OOV_OOVH2_1_Val << PWM_OOV_OOVH2_Pos)           /* (PWM_OOV) Override value is 1 for PWMH output of channel x. Position  */
#define PWM_OOV_OOVH3_Pos                     _UINT32_(3)                                          /* (PWM_OOV) Output Override Value for PWMH output of the channel 3 Position */
#define PWM_OOV_OOVH3_Msk                     (_UINT32_(0x1) << PWM_OOV_OOVH3_Pos)                 /* (PWM_OOV) Output Override Value for PWMH output of the channel 3 Mask */
#define PWM_OOV_OOVH3(value)                  (PWM_OOV_OOVH3_Msk & (_UINT32_(value) << PWM_OOV_OOVH3_Pos)) /* Assigment of value for OOVH3 in the PWM_OOV register */
#define   PWM_OOV_OOVH3_0_Val                 _UINT32_(0x0)                                        /* (PWM_OOV) Override value is 0 for PWMH output of channel x.  */
#define   PWM_OOV_OOVH3_1_Val                 _UINT32_(0x1)                                        /* (PWM_OOV) Override value is 1 for PWMH output of channel x.  */
#define PWM_OOV_OOVH3_0                       (PWM_OOV_OOVH3_0_Val << PWM_OOV_OOVH3_Pos)           /* (PWM_OOV) Override value is 0 for PWMH output of channel x. Position  */
#define PWM_OOV_OOVH3_1                       (PWM_OOV_OOVH3_1_Val << PWM_OOV_OOVH3_Pos)           /* (PWM_OOV) Override value is 1 for PWMH output of channel x. Position  */
#define PWM_OOV_OOVL0_Pos                     _UINT32_(16)                                         /* (PWM_OOV) Output Override Value for PWML output of the channel 0 Position */
#define PWM_OOV_OOVL0_Msk                     (_UINT32_(0x1) << PWM_OOV_OOVL0_Pos)                 /* (PWM_OOV) Output Override Value for PWML output of the channel 0 Mask */
#define PWM_OOV_OOVL0(value)                  (PWM_OOV_OOVL0_Msk & (_UINT32_(value) << PWM_OOV_OOVL0_Pos)) /* Assigment of value for OOVL0 in the PWM_OOV register */
#define   PWM_OOV_OOVL0_0_Val                 _UINT32_(0x0)                                        /* (PWM_OOV) Override value is 0 for PWML output of channel x.  */
#define   PWM_OOV_OOVL0_1_Val                 _UINT32_(0x1)                                        /* (PWM_OOV) Override value is 1 for PWML output of channel x.  */
#define PWM_OOV_OOVL0_0                       (PWM_OOV_OOVL0_0_Val << PWM_OOV_OOVL0_Pos)           /* (PWM_OOV) Override value is 0 for PWML output of channel x. Position  */
#define PWM_OOV_OOVL0_1                       (PWM_OOV_OOVL0_1_Val << PWM_OOV_OOVL0_Pos)           /* (PWM_OOV) Override value is 1 for PWML output of channel x. Position  */
#define PWM_OOV_OOVL1_Pos                     _UINT32_(17)                                         /* (PWM_OOV) Output Override Value for PWML output of the channel 1 Position */
#define PWM_OOV_OOVL1_Msk                     (_UINT32_(0x1) << PWM_OOV_OOVL1_Pos)                 /* (PWM_OOV) Output Override Value for PWML output of the channel 1 Mask */
#define PWM_OOV_OOVL1(value)                  (PWM_OOV_OOVL1_Msk & (_UINT32_(value) << PWM_OOV_OOVL1_Pos)) /* Assigment of value for OOVL1 in the PWM_OOV register */
#define   PWM_OOV_OOVL1_0_Val                 _UINT32_(0x0)                                        /* (PWM_OOV) Override value is 0 for PWML output of channel x.  */
#define   PWM_OOV_OOVL1_1_Val                 _UINT32_(0x1)                                        /* (PWM_OOV) Override value is 1 for PWML output of channel x.  */
#define PWM_OOV_OOVL1_0                       (PWM_OOV_OOVL1_0_Val << PWM_OOV_OOVL1_Pos)           /* (PWM_OOV) Override value is 0 for PWML output of channel x. Position  */
#define PWM_OOV_OOVL1_1                       (PWM_OOV_OOVL1_1_Val << PWM_OOV_OOVL1_Pos)           /* (PWM_OOV) Override value is 1 for PWML output of channel x. Position  */
#define PWM_OOV_OOVL2_Pos                     _UINT32_(18)                                         /* (PWM_OOV) Output Override Value for PWML output of the channel 2 Position */
#define PWM_OOV_OOVL2_Msk                     (_UINT32_(0x1) << PWM_OOV_OOVL2_Pos)                 /* (PWM_OOV) Output Override Value for PWML output of the channel 2 Mask */
#define PWM_OOV_OOVL2(value)                  (PWM_OOV_OOVL2_Msk & (_UINT32_(value) << PWM_OOV_OOVL2_Pos)) /* Assigment of value for OOVL2 in the PWM_OOV register */
#define   PWM_OOV_OOVL2_0_Val                 _UINT32_(0x0)                                        /* (PWM_OOV) Override value is 0 for PWML output of channel x.  */
#define   PWM_OOV_OOVL2_1_Val                 _UINT32_(0x1)                                        /* (PWM_OOV) Override value is 1 for PWML output of channel x.  */
#define PWM_OOV_OOVL2_0                       (PWM_OOV_OOVL2_0_Val << PWM_OOV_OOVL2_Pos)           /* (PWM_OOV) Override value is 0 for PWML output of channel x. Position  */
#define PWM_OOV_OOVL2_1                       (PWM_OOV_OOVL2_1_Val << PWM_OOV_OOVL2_Pos)           /* (PWM_OOV) Override value is 1 for PWML output of channel x. Position  */
#define PWM_OOV_OOVL3_Pos                     _UINT32_(19)                                         /* (PWM_OOV) Output Override Value for PWML output of the channel 3 Position */
#define PWM_OOV_OOVL3_Msk                     (_UINT32_(0x1) << PWM_OOV_OOVL3_Pos)                 /* (PWM_OOV) Output Override Value for PWML output of the channel 3 Mask */
#define PWM_OOV_OOVL3(value)                  (PWM_OOV_OOVL3_Msk & (_UINT32_(value) << PWM_OOV_OOVL3_Pos)) /* Assigment of value for OOVL3 in the PWM_OOV register */
#define   PWM_OOV_OOVL3_0_Val                 _UINT32_(0x0)                                        /* (PWM_OOV) Override value is 0 for PWML output of channel x.  */
#define   PWM_OOV_OOVL3_1_Val                 _UINT32_(0x1)                                        /* (PWM_OOV) Override value is 1 for PWML output of channel x.  */
#define PWM_OOV_OOVL3_0                       (PWM_OOV_OOVL3_0_Val << PWM_OOV_OOVL3_Pos)           /* (PWM_OOV) Override value is 0 for PWML output of channel x. Position  */
#define PWM_OOV_OOVL3_1                       (PWM_OOV_OOVL3_1_Val << PWM_OOV_OOVL3_Pos)           /* (PWM_OOV) Override value is 1 for PWML output of channel x. Position  */
#define PWM_OOV_Msk                           _UINT32_(0x000F000F)                                 /* (PWM_OOV) Register Mask  */

#define PWM_OOV_OOVH_Pos                      _UINT32_(0)                                          /* (PWM_OOV Position) Output Override Value for PWMH output of the channel x */
#define PWM_OOV_OOVH_Msk                      (_UINT32_(0xF) << PWM_OOV_OOVH_Pos)                  /* (PWM_OOV Mask) OOVH */
#define PWM_OOV_OOVH(value)                   (PWM_OOV_OOVH_Msk & (_UINT32_(value) << PWM_OOV_OOVH_Pos)) 
#define PWM_OOV_OOVL_Pos                      _UINT32_(16)                                         /* (PWM_OOV Position) Output Override Value for PWML output of the channel 3 */
#define PWM_OOV_OOVL_Msk                      (_UINT32_(0xF) << PWM_OOV_OOVL_Pos)                  /* (PWM_OOV Mask) OOVL */
#define PWM_OOV_OOVL(value)                   (PWM_OOV_OOVL_Msk & (_UINT32_(value) << PWM_OOV_OOVL_Pos)) 

/* -------- PWM_OS : (PWM Offset: 0x48) (R/W 32) PWM Output Selection Register -------- */
#define PWM_OS_RESETVALUE                     _UINT32_(0x00)                                       /*  (PWM_OS) PWM Output Selection Register  Reset Value */

#define PWM_OS_OSH0_Pos                       _UINT32_(0)                                          /* (PWM_OS) Output Selection for PWMH output of the channel 0 Position */
#define PWM_OS_OSH0_Msk                       (_UINT32_(0x1) << PWM_OS_OSH0_Pos)                   /* (PWM_OS) Output Selection for PWMH output of the channel 0 Mask */
#define PWM_OS_OSH0(value)                    (PWM_OS_OSH0_Msk & (_UINT32_(value) << PWM_OS_OSH0_Pos)) /* Assigment of value for OSH0 in the PWM_OS register */
#define   PWM_OS_OSH0_0_Val                   _UINT32_(0x0)                                        /* (PWM_OS) Dead-time generator output DTOHx selected as PWMH output of channel x.  */
#define   PWM_OS_OSH0_1_Val                   _UINT32_(0x1)                                        /* (PWM_OS) Output override value OOVHx selected as PWMH output of channel x.  */
#define PWM_OS_OSH0_0                         (PWM_OS_OSH0_0_Val << PWM_OS_OSH0_Pos)               /* (PWM_OS) Dead-time generator output DTOHx selected as PWMH output of channel x. Position  */
#define PWM_OS_OSH0_1                         (PWM_OS_OSH0_1_Val << PWM_OS_OSH0_Pos)               /* (PWM_OS) Output override value OOVHx selected as PWMH output of channel x. Position  */
#define PWM_OS_OSH1_Pos                       _UINT32_(1)                                          /* (PWM_OS) Output Selection for PWMH output of the channel 1 Position */
#define PWM_OS_OSH1_Msk                       (_UINT32_(0x1) << PWM_OS_OSH1_Pos)                   /* (PWM_OS) Output Selection for PWMH output of the channel 1 Mask */
#define PWM_OS_OSH1(value)                    (PWM_OS_OSH1_Msk & (_UINT32_(value) << PWM_OS_OSH1_Pos)) /* Assigment of value for OSH1 in the PWM_OS register */
#define   PWM_OS_OSH1_0_Val                   _UINT32_(0x0)                                        /* (PWM_OS) Dead-time generator output DTOHx selected as PWMH output of channel x.  */
#define   PWM_OS_OSH1_1_Val                   _UINT32_(0x1)                                        /* (PWM_OS) Output override value OOVHx selected as PWMH output of channel x.  */
#define PWM_OS_OSH1_0                         (PWM_OS_OSH1_0_Val << PWM_OS_OSH1_Pos)               /* (PWM_OS) Dead-time generator output DTOHx selected as PWMH output of channel x. Position  */
#define PWM_OS_OSH1_1                         (PWM_OS_OSH1_1_Val << PWM_OS_OSH1_Pos)               /* (PWM_OS) Output override value OOVHx selected as PWMH output of channel x. Position  */
#define PWM_OS_OSH2_Pos                       _UINT32_(2)                                          /* (PWM_OS) Output Selection for PWMH output of the channel 2 Position */
#define PWM_OS_OSH2_Msk                       (_UINT32_(0x1) << PWM_OS_OSH2_Pos)                   /* (PWM_OS) Output Selection for PWMH output of the channel 2 Mask */
#define PWM_OS_OSH2(value)                    (PWM_OS_OSH2_Msk & (_UINT32_(value) << PWM_OS_OSH2_Pos)) /* Assigment of value for OSH2 in the PWM_OS register */
#define   PWM_OS_OSH2_0_Val                   _UINT32_(0x0)                                        /* (PWM_OS) Dead-time generator output DTOHx selected as PWMH output of channel x.  */
#define   PWM_OS_OSH2_1_Val                   _UINT32_(0x1)                                        /* (PWM_OS) Output override value OOVHx selected as PWMH output of channel x.  */
#define PWM_OS_OSH2_0                         (PWM_OS_OSH2_0_Val << PWM_OS_OSH2_Pos)               /* (PWM_OS) Dead-time generator output DTOHx selected as PWMH output of channel x. Position  */
#define PWM_OS_OSH2_1                         (PWM_OS_OSH2_1_Val << PWM_OS_OSH2_Pos)               /* (PWM_OS) Output override value OOVHx selected as PWMH output of channel x. Position  */
#define PWM_OS_OSH3_Pos                       _UINT32_(3)                                          /* (PWM_OS) Output Selection for PWMH output of the channel 3 Position */
#define PWM_OS_OSH3_Msk                       (_UINT32_(0x1) << PWM_OS_OSH3_Pos)                   /* (PWM_OS) Output Selection for PWMH output of the channel 3 Mask */
#define PWM_OS_OSH3(value)                    (PWM_OS_OSH3_Msk & (_UINT32_(value) << PWM_OS_OSH3_Pos)) /* Assigment of value for OSH3 in the PWM_OS register */
#define   PWM_OS_OSH3_0_Val                   _UINT32_(0x0)                                        /* (PWM_OS) Dead-time generator output DTOHx selected as PWMH output of channel x.  */
#define   PWM_OS_OSH3_1_Val                   _UINT32_(0x1)                                        /* (PWM_OS) Output override value OOVHx selected as PWMH output of channel x.  */
#define PWM_OS_OSH3_0                         (PWM_OS_OSH3_0_Val << PWM_OS_OSH3_Pos)               /* (PWM_OS) Dead-time generator output DTOHx selected as PWMH output of channel x. Position  */
#define PWM_OS_OSH3_1                         (PWM_OS_OSH3_1_Val << PWM_OS_OSH3_Pos)               /* (PWM_OS) Output override value OOVHx selected as PWMH output of channel x. Position  */
#define PWM_OS_OSL0_Pos                       _UINT32_(16)                                         /* (PWM_OS) Output Selection for PWML output of the channel 0 Position */
#define PWM_OS_OSL0_Msk                       (_UINT32_(0x1) << PWM_OS_OSL0_Pos)                   /* (PWM_OS) Output Selection for PWML output of the channel 0 Mask */
#define PWM_OS_OSL0(value)                    (PWM_OS_OSL0_Msk & (_UINT32_(value) << PWM_OS_OSL0_Pos)) /* Assigment of value for OSL0 in the PWM_OS register */
#define   PWM_OS_OSL0_0_Val                   _UINT32_(0x0)                                        /* (PWM_OS) Dead-time generator output DTOLx selected as PWML output of channel x.  */
#define   PWM_OS_OSL0_1_Val                   _UINT32_(0x1)                                        /* (PWM_OS) Output override value OOVLx selected as PWML output of channel x.  */
#define PWM_OS_OSL0_0                         (PWM_OS_OSL0_0_Val << PWM_OS_OSL0_Pos)               /* (PWM_OS) Dead-time generator output DTOLx selected as PWML output of channel x. Position  */
#define PWM_OS_OSL0_1                         (PWM_OS_OSL0_1_Val << PWM_OS_OSL0_Pos)               /* (PWM_OS) Output override value OOVLx selected as PWML output of channel x. Position  */
#define PWM_OS_OSL1_Pos                       _UINT32_(17)                                         /* (PWM_OS) Output Selection for PWML output of the channel 1 Position */
#define PWM_OS_OSL1_Msk                       (_UINT32_(0x1) << PWM_OS_OSL1_Pos)                   /* (PWM_OS) Output Selection for PWML output of the channel 1 Mask */
#define PWM_OS_OSL1(value)                    (PWM_OS_OSL1_Msk & (_UINT32_(value) << PWM_OS_OSL1_Pos)) /* Assigment of value for OSL1 in the PWM_OS register */
#define   PWM_OS_OSL1_0_Val                   _UINT32_(0x0)                                        /* (PWM_OS) Dead-time generator output DTOLx selected as PWML output of channel x.  */
#define   PWM_OS_OSL1_1_Val                   _UINT32_(0x1)                                        /* (PWM_OS) Output override value OOVLx selected as PWML output of channel x.  */
#define PWM_OS_OSL1_0                         (PWM_OS_OSL1_0_Val << PWM_OS_OSL1_Pos)               /* (PWM_OS) Dead-time generator output DTOLx selected as PWML output of channel x. Position  */
#define PWM_OS_OSL1_1                         (PWM_OS_OSL1_1_Val << PWM_OS_OSL1_Pos)               /* (PWM_OS) Output override value OOVLx selected as PWML output of channel x. Position  */
#define PWM_OS_OSL2_Pos                       _UINT32_(18)                                         /* (PWM_OS) Output Selection for PWML output of the channel 2 Position */
#define PWM_OS_OSL2_Msk                       (_UINT32_(0x1) << PWM_OS_OSL2_Pos)                   /* (PWM_OS) Output Selection for PWML output of the channel 2 Mask */
#define PWM_OS_OSL2(value)                    (PWM_OS_OSL2_Msk & (_UINT32_(value) << PWM_OS_OSL2_Pos)) /* Assigment of value for OSL2 in the PWM_OS register */
#define   PWM_OS_OSL2_0_Val                   _UINT32_(0x0)                                        /* (PWM_OS) Dead-time generator output DTOLx selected as PWML output of channel x.  */
#define   PWM_OS_OSL2_1_Val                   _UINT32_(0x1)                                        /* (PWM_OS) Output override value OOVLx selected as PWML output of channel x.  */
#define PWM_OS_OSL2_0                         (PWM_OS_OSL2_0_Val << PWM_OS_OSL2_Pos)               /* (PWM_OS) Dead-time generator output DTOLx selected as PWML output of channel x. Position  */
#define PWM_OS_OSL2_1                         (PWM_OS_OSL2_1_Val << PWM_OS_OSL2_Pos)               /* (PWM_OS) Output override value OOVLx selected as PWML output of channel x. Position  */
#define PWM_OS_OSL3_Pos                       _UINT32_(19)                                         /* (PWM_OS) Output Selection for PWML output of the channel 3 Position */
#define PWM_OS_OSL3_Msk                       (_UINT32_(0x1) << PWM_OS_OSL3_Pos)                   /* (PWM_OS) Output Selection for PWML output of the channel 3 Mask */
#define PWM_OS_OSL3(value)                    (PWM_OS_OSL3_Msk & (_UINT32_(value) << PWM_OS_OSL3_Pos)) /* Assigment of value for OSL3 in the PWM_OS register */
#define   PWM_OS_OSL3_0_Val                   _UINT32_(0x0)                                        /* (PWM_OS) Dead-time generator output DTOLx selected as PWML output of channel x.  */
#define   PWM_OS_OSL3_1_Val                   _UINT32_(0x1)                                        /* (PWM_OS) Output override value OOVLx selected as PWML output of channel x.  */
#define PWM_OS_OSL3_0                         (PWM_OS_OSL3_0_Val << PWM_OS_OSL3_Pos)               /* (PWM_OS) Dead-time generator output DTOLx selected as PWML output of channel x. Position  */
#define PWM_OS_OSL3_1                         (PWM_OS_OSL3_1_Val << PWM_OS_OSL3_Pos)               /* (PWM_OS) Output override value OOVLx selected as PWML output of channel x. Position  */
#define PWM_OS_Msk                            _UINT32_(0x000F000F)                                 /* (PWM_OS) Register Mask  */

#define PWM_OS_OSH_Pos                        _UINT32_(0)                                          /* (PWM_OS Position) Output Selection for PWMH output of the channel x */
#define PWM_OS_OSH_Msk                        (_UINT32_(0xF) << PWM_OS_OSH_Pos)                    /* (PWM_OS Mask) OSH */
#define PWM_OS_OSH(value)                     (PWM_OS_OSH_Msk & (_UINT32_(value) << PWM_OS_OSH_Pos)) 
#define PWM_OS_OSL_Pos                        _UINT32_(16)                                         /* (PWM_OS Position) Output Selection for PWML output of the channel 3 */
#define PWM_OS_OSL_Msk                        (_UINT32_(0xF) << PWM_OS_OSL_Pos)                    /* (PWM_OS Mask) OSL */
#define PWM_OS_OSL(value)                     (PWM_OS_OSL_Msk & (_UINT32_(value) << PWM_OS_OSL_Pos)) 

/* -------- PWM_OSS : (PWM Offset: 0x4C) ( /W 32) PWM Output Selection Set Register -------- */
#define PWM_OSS_OSSH0_Pos                     _UINT32_(0)                                          /* (PWM_OSS) Output Selection Set for PWMH output of the channel 0 Position */
#define PWM_OSS_OSSH0_Msk                     (_UINT32_(0x1) << PWM_OSS_OSSH0_Pos)                 /* (PWM_OSS) Output Selection Set for PWMH output of the channel 0 Mask */
#define PWM_OSS_OSSH0(value)                  (PWM_OSS_OSSH0_Msk & (_UINT32_(value) << PWM_OSS_OSSH0_Pos)) /* Assigment of value for OSSH0 in the PWM_OSS register */
#define   PWM_OSS_OSSH0_0_Val                 _UINT32_(0x0)                                        /* (PWM_OSS) No effect.  */
#define   PWM_OSS_OSSH0_1_Val                 _UINT32_(0x1)                                        /* (PWM_OSS) Output override value OOVHx selected as PWMH output of channel x.  */
#define PWM_OSS_OSSH0_0                       (PWM_OSS_OSSH0_0_Val << PWM_OSS_OSSH0_Pos)           /* (PWM_OSS) No effect. Position  */
#define PWM_OSS_OSSH0_1                       (PWM_OSS_OSSH0_1_Val << PWM_OSS_OSSH0_Pos)           /* (PWM_OSS) Output override value OOVHx selected as PWMH output of channel x. Position  */
#define PWM_OSS_OSSH1_Pos                     _UINT32_(1)                                          /* (PWM_OSS) Output Selection Set for PWMH output of the channel 1 Position */
#define PWM_OSS_OSSH1_Msk                     (_UINT32_(0x1) << PWM_OSS_OSSH1_Pos)                 /* (PWM_OSS) Output Selection Set for PWMH output of the channel 1 Mask */
#define PWM_OSS_OSSH1(value)                  (PWM_OSS_OSSH1_Msk & (_UINT32_(value) << PWM_OSS_OSSH1_Pos)) /* Assigment of value for OSSH1 in the PWM_OSS register */
#define   PWM_OSS_OSSH1_0_Val                 _UINT32_(0x0)                                        /* (PWM_OSS) No effect.  */
#define   PWM_OSS_OSSH1_1_Val                 _UINT32_(0x1)                                        /* (PWM_OSS) Output override value OOVHx selected as PWMH output of channel x.  */
#define PWM_OSS_OSSH1_0                       (PWM_OSS_OSSH1_0_Val << PWM_OSS_OSSH1_Pos)           /* (PWM_OSS) No effect. Position  */
#define PWM_OSS_OSSH1_1                       (PWM_OSS_OSSH1_1_Val << PWM_OSS_OSSH1_Pos)           /* (PWM_OSS) Output override value OOVHx selected as PWMH output of channel x. Position  */
#define PWM_OSS_OSSH2_Pos                     _UINT32_(2)                                          /* (PWM_OSS) Output Selection Set for PWMH output of the channel 2 Position */
#define PWM_OSS_OSSH2_Msk                     (_UINT32_(0x1) << PWM_OSS_OSSH2_Pos)                 /* (PWM_OSS) Output Selection Set for PWMH output of the channel 2 Mask */
#define PWM_OSS_OSSH2(value)                  (PWM_OSS_OSSH2_Msk & (_UINT32_(value) << PWM_OSS_OSSH2_Pos)) /* Assigment of value for OSSH2 in the PWM_OSS register */
#define   PWM_OSS_OSSH2_0_Val                 _UINT32_(0x0)                                        /* (PWM_OSS) No effect.  */
#define   PWM_OSS_OSSH2_1_Val                 _UINT32_(0x1)                                        /* (PWM_OSS) Output override value OOVHx selected as PWMH output of channel x.  */
#define PWM_OSS_OSSH2_0                       (PWM_OSS_OSSH2_0_Val << PWM_OSS_OSSH2_Pos)           /* (PWM_OSS) No effect. Position  */
#define PWM_OSS_OSSH2_1                       (PWM_OSS_OSSH2_1_Val << PWM_OSS_OSSH2_Pos)           /* (PWM_OSS) Output override value OOVHx selected as PWMH output of channel x. Position  */
#define PWM_OSS_OSSH3_Pos                     _UINT32_(3)                                          /* (PWM_OSS) Output Selection Set for PWMH output of the channel 3 Position */
#define PWM_OSS_OSSH3_Msk                     (_UINT32_(0x1) << PWM_OSS_OSSH3_Pos)                 /* (PWM_OSS) Output Selection Set for PWMH output of the channel 3 Mask */
#define PWM_OSS_OSSH3(value)                  (PWM_OSS_OSSH3_Msk & (_UINT32_(value) << PWM_OSS_OSSH3_Pos)) /* Assigment of value for OSSH3 in the PWM_OSS register */
#define   PWM_OSS_OSSH3_0_Val                 _UINT32_(0x0)                                        /* (PWM_OSS) No effect.  */
#define   PWM_OSS_OSSH3_1_Val                 _UINT32_(0x1)                                        /* (PWM_OSS) Output override value OOVHx selected as PWMH output of channel x.  */
#define PWM_OSS_OSSH3_0                       (PWM_OSS_OSSH3_0_Val << PWM_OSS_OSSH3_Pos)           /* (PWM_OSS) No effect. Position  */
#define PWM_OSS_OSSH3_1                       (PWM_OSS_OSSH3_1_Val << PWM_OSS_OSSH3_Pos)           /* (PWM_OSS) Output override value OOVHx selected as PWMH output of channel x. Position  */
#define PWM_OSS_OSSL0_Pos                     _UINT32_(16)                                         /* (PWM_OSS) Output Selection Set for PWML output of the channel 0 Position */
#define PWM_OSS_OSSL0_Msk                     (_UINT32_(0x1) << PWM_OSS_OSSL0_Pos)                 /* (PWM_OSS) Output Selection Set for PWML output of the channel 0 Mask */
#define PWM_OSS_OSSL0(value)                  (PWM_OSS_OSSL0_Msk & (_UINT32_(value) << PWM_OSS_OSSL0_Pos)) /* Assigment of value for OSSL0 in the PWM_OSS register */
#define   PWM_OSS_OSSL0_0_Val                 _UINT32_(0x0)                                        /* (PWM_OSS) No effect.  */
#define   PWM_OSS_OSSL0_1_Val                 _UINT32_(0x1)                                        /* (PWM_OSS) Output override value OOVLx selected as PWML output of channel x.  */
#define PWM_OSS_OSSL0_0                       (PWM_OSS_OSSL0_0_Val << PWM_OSS_OSSL0_Pos)           /* (PWM_OSS) No effect. Position  */
#define PWM_OSS_OSSL0_1                       (PWM_OSS_OSSL0_1_Val << PWM_OSS_OSSL0_Pos)           /* (PWM_OSS) Output override value OOVLx selected as PWML output of channel x. Position  */
#define PWM_OSS_OSSL1_Pos                     _UINT32_(17)                                         /* (PWM_OSS) Output Selection Set for PWML output of the channel 1 Position */
#define PWM_OSS_OSSL1_Msk                     (_UINT32_(0x1) << PWM_OSS_OSSL1_Pos)                 /* (PWM_OSS) Output Selection Set for PWML output of the channel 1 Mask */
#define PWM_OSS_OSSL1(value)                  (PWM_OSS_OSSL1_Msk & (_UINT32_(value) << PWM_OSS_OSSL1_Pos)) /* Assigment of value for OSSL1 in the PWM_OSS register */
#define   PWM_OSS_OSSL1_0_Val                 _UINT32_(0x0)                                        /* (PWM_OSS) No effect.  */
#define   PWM_OSS_OSSL1_1_Val                 _UINT32_(0x1)                                        /* (PWM_OSS) Output override value OOVLx selected as PWML output of channel x.  */
#define PWM_OSS_OSSL1_0                       (PWM_OSS_OSSL1_0_Val << PWM_OSS_OSSL1_Pos)           /* (PWM_OSS) No effect. Position  */
#define PWM_OSS_OSSL1_1                       (PWM_OSS_OSSL1_1_Val << PWM_OSS_OSSL1_Pos)           /* (PWM_OSS) Output override value OOVLx selected as PWML output of channel x. Position  */
#define PWM_OSS_OSSL2_Pos                     _UINT32_(18)                                         /* (PWM_OSS) Output Selection Set for PWML output of the channel 2 Position */
#define PWM_OSS_OSSL2_Msk                     (_UINT32_(0x1) << PWM_OSS_OSSL2_Pos)                 /* (PWM_OSS) Output Selection Set for PWML output of the channel 2 Mask */
#define PWM_OSS_OSSL2(value)                  (PWM_OSS_OSSL2_Msk & (_UINT32_(value) << PWM_OSS_OSSL2_Pos)) /* Assigment of value for OSSL2 in the PWM_OSS register */
#define   PWM_OSS_OSSL2_0_Val                 _UINT32_(0x0)                                        /* (PWM_OSS) No effect.  */
#define   PWM_OSS_OSSL2_1_Val                 _UINT32_(0x1)                                        /* (PWM_OSS) Output override value OOVLx selected as PWML output of channel x.  */
#define PWM_OSS_OSSL2_0                       (PWM_OSS_OSSL2_0_Val << PWM_OSS_OSSL2_Pos)           /* (PWM_OSS) No effect. Position  */
#define PWM_OSS_OSSL2_1                       (PWM_OSS_OSSL2_1_Val << PWM_OSS_OSSL2_Pos)           /* (PWM_OSS) Output override value OOVLx selected as PWML output of channel x. Position  */
#define PWM_OSS_OSSL3_Pos                     _UINT32_(19)                                         /* (PWM_OSS) Output Selection Set for PWML output of the channel 3 Position */
#define PWM_OSS_OSSL3_Msk                     (_UINT32_(0x1) << PWM_OSS_OSSL3_Pos)                 /* (PWM_OSS) Output Selection Set for PWML output of the channel 3 Mask */
#define PWM_OSS_OSSL3(value)                  (PWM_OSS_OSSL3_Msk & (_UINT32_(value) << PWM_OSS_OSSL3_Pos)) /* Assigment of value for OSSL3 in the PWM_OSS register */
#define   PWM_OSS_OSSL3_0_Val                 _UINT32_(0x0)                                        /* (PWM_OSS) No effect.  */
#define   PWM_OSS_OSSL3_1_Val                 _UINT32_(0x1)                                        /* (PWM_OSS) Output override value OOVLx selected as PWML output of channel x.  */
#define PWM_OSS_OSSL3_0                       (PWM_OSS_OSSL3_0_Val << PWM_OSS_OSSL3_Pos)           /* (PWM_OSS) No effect. Position  */
#define PWM_OSS_OSSL3_1                       (PWM_OSS_OSSL3_1_Val << PWM_OSS_OSSL3_Pos)           /* (PWM_OSS) Output override value OOVLx selected as PWML output of channel x. Position  */
#define PWM_OSS_Msk                           _UINT32_(0x000F000F)                                 /* (PWM_OSS) Register Mask  */

#define PWM_OSS_OSSH_Pos                      _UINT32_(0)                                          /* (PWM_OSS Position) Output Selection Set for PWMH output of the channel x */
#define PWM_OSS_OSSH_Msk                      (_UINT32_(0xF) << PWM_OSS_OSSH_Pos)                  /* (PWM_OSS Mask) OSSH */
#define PWM_OSS_OSSH(value)                   (PWM_OSS_OSSH_Msk & (_UINT32_(value) << PWM_OSS_OSSH_Pos)) 
#define PWM_OSS_OSSL_Pos                      _UINT32_(16)                                         /* (PWM_OSS Position) Output Selection Set for PWML output of the channel 3 */
#define PWM_OSS_OSSL_Msk                      (_UINT32_(0xF) << PWM_OSS_OSSL_Pos)                  /* (PWM_OSS Mask) OSSL */
#define PWM_OSS_OSSL(value)                   (PWM_OSS_OSSL_Msk & (_UINT32_(value) << PWM_OSS_OSSL_Pos)) 

/* -------- PWM_OSC : (PWM Offset: 0x50) ( /W 32) PWM Output Selection Clear Register -------- */
#define PWM_OSC_OSCH0_Pos                     _UINT32_(0)                                          /* (PWM_OSC) Output Selection Clear for PWMH output of the channel 0 Position */
#define PWM_OSC_OSCH0_Msk                     (_UINT32_(0x1) << PWM_OSC_OSCH0_Pos)                 /* (PWM_OSC) Output Selection Clear for PWMH output of the channel 0 Mask */
#define PWM_OSC_OSCH0(value)                  (PWM_OSC_OSCH0_Msk & (_UINT32_(value) << PWM_OSC_OSCH0_Pos)) /* Assigment of value for OSCH0 in the PWM_OSC register */
#define   PWM_OSC_OSCH0_0_Val                 _UINT32_(0x0)                                        /* (PWM_OSC) No effect.  */
#define   PWM_OSC_OSCH0_1_Val                 _UINT32_(0x1)                                        /* (PWM_OSC) Dead-time generator output DTOHx selected as PWMH output of channel x.  */
#define PWM_OSC_OSCH0_0                       (PWM_OSC_OSCH0_0_Val << PWM_OSC_OSCH0_Pos)           /* (PWM_OSC) No effect. Position  */
#define PWM_OSC_OSCH0_1                       (PWM_OSC_OSCH0_1_Val << PWM_OSC_OSCH0_Pos)           /* (PWM_OSC) Dead-time generator output DTOHx selected as PWMH output of channel x. Position  */
#define PWM_OSC_OSCH1_Pos                     _UINT32_(1)                                          /* (PWM_OSC) Output Selection Clear for PWMH output of the channel 1 Position */
#define PWM_OSC_OSCH1_Msk                     (_UINT32_(0x1) << PWM_OSC_OSCH1_Pos)                 /* (PWM_OSC) Output Selection Clear for PWMH output of the channel 1 Mask */
#define PWM_OSC_OSCH1(value)                  (PWM_OSC_OSCH1_Msk & (_UINT32_(value) << PWM_OSC_OSCH1_Pos)) /* Assigment of value for OSCH1 in the PWM_OSC register */
#define   PWM_OSC_OSCH1_0_Val                 _UINT32_(0x0)                                        /* (PWM_OSC) No effect.  */
#define   PWM_OSC_OSCH1_1_Val                 _UINT32_(0x1)                                        /* (PWM_OSC) Dead-time generator output DTOHx selected as PWMH output of channel x.  */
#define PWM_OSC_OSCH1_0                       (PWM_OSC_OSCH1_0_Val << PWM_OSC_OSCH1_Pos)           /* (PWM_OSC) No effect. Position  */
#define PWM_OSC_OSCH1_1                       (PWM_OSC_OSCH1_1_Val << PWM_OSC_OSCH1_Pos)           /* (PWM_OSC) Dead-time generator output DTOHx selected as PWMH output of channel x. Position  */
#define PWM_OSC_OSCH2_Pos                     _UINT32_(2)                                          /* (PWM_OSC) Output Selection Clear for PWMH output of the channel 2 Position */
#define PWM_OSC_OSCH2_Msk                     (_UINT32_(0x1) << PWM_OSC_OSCH2_Pos)                 /* (PWM_OSC) Output Selection Clear for PWMH output of the channel 2 Mask */
#define PWM_OSC_OSCH2(value)                  (PWM_OSC_OSCH2_Msk & (_UINT32_(value) << PWM_OSC_OSCH2_Pos)) /* Assigment of value for OSCH2 in the PWM_OSC register */
#define   PWM_OSC_OSCH2_0_Val                 _UINT32_(0x0)                                        /* (PWM_OSC) No effect.  */
#define   PWM_OSC_OSCH2_1_Val                 _UINT32_(0x1)                                        /* (PWM_OSC) Dead-time generator output DTOHx selected as PWMH output of channel x.  */
#define PWM_OSC_OSCH2_0                       (PWM_OSC_OSCH2_0_Val << PWM_OSC_OSCH2_Pos)           /* (PWM_OSC) No effect. Position  */
#define PWM_OSC_OSCH2_1                       (PWM_OSC_OSCH2_1_Val << PWM_OSC_OSCH2_Pos)           /* (PWM_OSC) Dead-time generator output DTOHx selected as PWMH output of channel x. Position  */
#define PWM_OSC_OSCH3_Pos                     _UINT32_(3)                                          /* (PWM_OSC) Output Selection Clear for PWMH output of the channel 3 Position */
#define PWM_OSC_OSCH3_Msk                     (_UINT32_(0x1) << PWM_OSC_OSCH3_Pos)                 /* (PWM_OSC) Output Selection Clear for PWMH output of the channel 3 Mask */
#define PWM_OSC_OSCH3(value)                  (PWM_OSC_OSCH3_Msk & (_UINT32_(value) << PWM_OSC_OSCH3_Pos)) /* Assigment of value for OSCH3 in the PWM_OSC register */
#define   PWM_OSC_OSCH3_0_Val                 _UINT32_(0x0)                                        /* (PWM_OSC) No effect.  */
#define   PWM_OSC_OSCH3_1_Val                 _UINT32_(0x1)                                        /* (PWM_OSC) Dead-time generator output DTOHx selected as PWMH output of channel x.  */
#define PWM_OSC_OSCH3_0                       (PWM_OSC_OSCH3_0_Val << PWM_OSC_OSCH3_Pos)           /* (PWM_OSC) No effect. Position  */
#define PWM_OSC_OSCH3_1                       (PWM_OSC_OSCH3_1_Val << PWM_OSC_OSCH3_Pos)           /* (PWM_OSC) Dead-time generator output DTOHx selected as PWMH output of channel x. Position  */
#define PWM_OSC_OSCL0_Pos                     _UINT32_(16)                                         /* (PWM_OSC) Output Selection Clear for PWML output of the channel 0 Position */
#define PWM_OSC_OSCL0_Msk                     (_UINT32_(0x1) << PWM_OSC_OSCL0_Pos)                 /* (PWM_OSC) Output Selection Clear for PWML output of the channel 0 Mask */
#define PWM_OSC_OSCL0(value)                  (PWM_OSC_OSCL0_Msk & (_UINT32_(value) << PWM_OSC_OSCL0_Pos)) /* Assigment of value for OSCL0 in the PWM_OSC register */
#define   PWM_OSC_OSCL0_0_Val                 _UINT32_(0x0)                                        /* (PWM_OSC) No effect.  */
#define   PWM_OSC_OSCL0_1_Val                 _UINT32_(0x1)                                        /* (PWM_OSC) Dead-time generator output DTOLx selected as PWML output of channel x.  */
#define PWM_OSC_OSCL0_0                       (PWM_OSC_OSCL0_0_Val << PWM_OSC_OSCL0_Pos)           /* (PWM_OSC) No effect. Position  */
#define PWM_OSC_OSCL0_1                       (PWM_OSC_OSCL0_1_Val << PWM_OSC_OSCL0_Pos)           /* (PWM_OSC) Dead-time generator output DTOLx selected as PWML output of channel x. Position  */
#define PWM_OSC_OSCL1_Pos                     _UINT32_(17)                                         /* (PWM_OSC) Output Selection Clear for PWML output of the channel 1 Position */
#define PWM_OSC_OSCL1_Msk                     (_UINT32_(0x1) << PWM_OSC_OSCL1_Pos)                 /* (PWM_OSC) Output Selection Clear for PWML output of the channel 1 Mask */
#define PWM_OSC_OSCL1(value)                  (PWM_OSC_OSCL1_Msk & (_UINT32_(value) << PWM_OSC_OSCL1_Pos)) /* Assigment of value for OSCL1 in the PWM_OSC register */
#define   PWM_OSC_OSCL1_0_Val                 _UINT32_(0x0)                                        /* (PWM_OSC) No effect.  */
#define   PWM_OSC_OSCL1_1_Val                 _UINT32_(0x1)                                        /* (PWM_OSC) Dead-time generator output DTOLx selected as PWML output of channel x.  */
#define PWM_OSC_OSCL1_0                       (PWM_OSC_OSCL1_0_Val << PWM_OSC_OSCL1_Pos)           /* (PWM_OSC) No effect. Position  */
#define PWM_OSC_OSCL1_1                       (PWM_OSC_OSCL1_1_Val << PWM_OSC_OSCL1_Pos)           /* (PWM_OSC) Dead-time generator output DTOLx selected as PWML output of channel x. Position  */
#define PWM_OSC_OSCL2_Pos                     _UINT32_(18)                                         /* (PWM_OSC) Output Selection Clear for PWML output of the channel 2 Position */
#define PWM_OSC_OSCL2_Msk                     (_UINT32_(0x1) << PWM_OSC_OSCL2_Pos)                 /* (PWM_OSC) Output Selection Clear for PWML output of the channel 2 Mask */
#define PWM_OSC_OSCL2(value)                  (PWM_OSC_OSCL2_Msk & (_UINT32_(value) << PWM_OSC_OSCL2_Pos)) /* Assigment of value for OSCL2 in the PWM_OSC register */
#define   PWM_OSC_OSCL2_0_Val                 _UINT32_(0x0)                                        /* (PWM_OSC) No effect.  */
#define   PWM_OSC_OSCL2_1_Val                 _UINT32_(0x1)                                        /* (PWM_OSC) Dead-time generator output DTOLx selected as PWML output of channel x.  */
#define PWM_OSC_OSCL2_0                       (PWM_OSC_OSCL2_0_Val << PWM_OSC_OSCL2_Pos)           /* (PWM_OSC) No effect. Position  */
#define PWM_OSC_OSCL2_1                       (PWM_OSC_OSCL2_1_Val << PWM_OSC_OSCL2_Pos)           /* (PWM_OSC) Dead-time generator output DTOLx selected as PWML output of channel x. Position  */
#define PWM_OSC_OSCL3_Pos                     _UINT32_(19)                                         /* (PWM_OSC) Output Selection Clear for PWML output of the channel 3 Position */
#define PWM_OSC_OSCL3_Msk                     (_UINT32_(0x1) << PWM_OSC_OSCL3_Pos)                 /* (PWM_OSC) Output Selection Clear for PWML output of the channel 3 Mask */
#define PWM_OSC_OSCL3(value)                  (PWM_OSC_OSCL3_Msk & (_UINT32_(value) << PWM_OSC_OSCL3_Pos)) /* Assigment of value for OSCL3 in the PWM_OSC register */
#define   PWM_OSC_OSCL3_0_Val                 _UINT32_(0x0)                                        /* (PWM_OSC) No effect.  */
#define   PWM_OSC_OSCL3_1_Val                 _UINT32_(0x1)                                        /* (PWM_OSC) Dead-time generator output DTOLx selected as PWML output of channel x.  */
#define PWM_OSC_OSCL3_0                       (PWM_OSC_OSCL3_0_Val << PWM_OSC_OSCL3_Pos)           /* (PWM_OSC) No effect. Position  */
#define PWM_OSC_OSCL3_1                       (PWM_OSC_OSCL3_1_Val << PWM_OSC_OSCL3_Pos)           /* (PWM_OSC) Dead-time generator output DTOLx selected as PWML output of channel x. Position  */
#define PWM_OSC_Msk                           _UINT32_(0x000F000F)                                 /* (PWM_OSC) Register Mask  */

#define PWM_OSC_OSCH_Pos                      _UINT32_(0)                                          /* (PWM_OSC Position) Output Selection Clear for PWMH output of the channel x */
#define PWM_OSC_OSCH_Msk                      (_UINT32_(0xF) << PWM_OSC_OSCH_Pos)                  /* (PWM_OSC Mask) OSCH */
#define PWM_OSC_OSCH(value)                   (PWM_OSC_OSCH_Msk & (_UINT32_(value) << PWM_OSC_OSCH_Pos)) 
#define PWM_OSC_OSCL_Pos                      _UINT32_(16)                                         /* (PWM_OSC Position) Output Selection Clear for PWML output of the channel 3 */
#define PWM_OSC_OSCL_Msk                      (_UINT32_(0xF) << PWM_OSC_OSCL_Pos)                  /* (PWM_OSC Mask) OSCL */
#define PWM_OSC_OSCL(value)                   (PWM_OSC_OSCL_Msk & (_UINT32_(value) << PWM_OSC_OSCL_Pos)) 

/* -------- PWM_OSSUPD : (PWM Offset: 0x54) ( /W 32) PWM Output Selection Set Update Register -------- */
#define PWM_OSSUPD_OSSUPH0_Pos                _UINT32_(0)                                          /* (PWM_OSSUPD) Output Selection Set for PWMH output of the channel 0 Position */
#define PWM_OSSUPD_OSSUPH0_Msk                (_UINT32_(0x1) << PWM_OSSUPD_OSSUPH0_Pos)            /* (PWM_OSSUPD) Output Selection Set for PWMH output of the channel 0 Mask */
#define PWM_OSSUPD_OSSUPH0(value)             (PWM_OSSUPD_OSSUPH0_Msk & (_UINT32_(value) << PWM_OSSUPD_OSSUPH0_Pos)) /* Assigment of value for OSSUPH0 in the PWM_OSSUPD register */
#define   PWM_OSSUPD_OSSUPH0_0_Val            _UINT32_(0x0)                                        /* (PWM_OSSUPD) No effect.  */
#define   PWM_OSSUPD_OSSUPH0_1_Val            _UINT32_(0x1)                                        /* (PWM_OSSUPD) Output override value OOVHx selected as PWMH output of channel x at the beginning of the next channel x PWM period.  */
#define PWM_OSSUPD_OSSUPH0_0                  (PWM_OSSUPD_OSSUPH0_0_Val << PWM_OSSUPD_OSSUPH0_Pos) /* (PWM_OSSUPD) No effect. Position  */
#define PWM_OSSUPD_OSSUPH0_1                  (PWM_OSSUPD_OSSUPH0_1_Val << PWM_OSSUPD_OSSUPH0_Pos) /* (PWM_OSSUPD) Output override value OOVHx selected as PWMH output of channel x at the beginning of the next channel x PWM period. Position  */
#define PWM_OSSUPD_OSSUPH1_Pos                _UINT32_(1)                                          /* (PWM_OSSUPD) Output Selection Set for PWMH output of the channel 1 Position */
#define PWM_OSSUPD_OSSUPH1_Msk                (_UINT32_(0x1) << PWM_OSSUPD_OSSUPH1_Pos)            /* (PWM_OSSUPD) Output Selection Set for PWMH output of the channel 1 Mask */
#define PWM_OSSUPD_OSSUPH1(value)             (PWM_OSSUPD_OSSUPH1_Msk & (_UINT32_(value) << PWM_OSSUPD_OSSUPH1_Pos)) /* Assigment of value for OSSUPH1 in the PWM_OSSUPD register */
#define   PWM_OSSUPD_OSSUPH1_0_Val            _UINT32_(0x0)                                        /* (PWM_OSSUPD) No effect.  */
#define   PWM_OSSUPD_OSSUPH1_1_Val            _UINT32_(0x1)                                        /* (PWM_OSSUPD) Output override value OOVHx selected as PWMH output of channel x at the beginning of the next channel x PWM period.  */
#define PWM_OSSUPD_OSSUPH1_0                  (PWM_OSSUPD_OSSUPH1_0_Val << PWM_OSSUPD_OSSUPH1_Pos) /* (PWM_OSSUPD) No effect. Position  */
#define PWM_OSSUPD_OSSUPH1_1                  (PWM_OSSUPD_OSSUPH1_1_Val << PWM_OSSUPD_OSSUPH1_Pos) /* (PWM_OSSUPD) Output override value OOVHx selected as PWMH output of channel x at the beginning of the next channel x PWM period. Position  */
#define PWM_OSSUPD_OSSUPH2_Pos                _UINT32_(2)                                          /* (PWM_OSSUPD) Output Selection Set for PWMH output of the channel 2 Position */
#define PWM_OSSUPD_OSSUPH2_Msk                (_UINT32_(0x1) << PWM_OSSUPD_OSSUPH2_Pos)            /* (PWM_OSSUPD) Output Selection Set for PWMH output of the channel 2 Mask */
#define PWM_OSSUPD_OSSUPH2(value)             (PWM_OSSUPD_OSSUPH2_Msk & (_UINT32_(value) << PWM_OSSUPD_OSSUPH2_Pos)) /* Assigment of value for OSSUPH2 in the PWM_OSSUPD register */
#define   PWM_OSSUPD_OSSUPH2_0_Val            _UINT32_(0x0)                                        /* (PWM_OSSUPD) No effect.  */
#define   PWM_OSSUPD_OSSUPH2_1_Val            _UINT32_(0x1)                                        /* (PWM_OSSUPD) Output override value OOVHx selected as PWMH output of channel x at the beginning of the next channel x PWM period.  */
#define PWM_OSSUPD_OSSUPH2_0                  (PWM_OSSUPD_OSSUPH2_0_Val << PWM_OSSUPD_OSSUPH2_Pos) /* (PWM_OSSUPD) No effect. Position  */
#define PWM_OSSUPD_OSSUPH2_1                  (PWM_OSSUPD_OSSUPH2_1_Val << PWM_OSSUPD_OSSUPH2_Pos) /* (PWM_OSSUPD) Output override value OOVHx selected as PWMH output of channel x at the beginning of the next channel x PWM period. Position  */
#define PWM_OSSUPD_OSSUPH3_Pos                _UINT32_(3)                                          /* (PWM_OSSUPD) Output Selection Set for PWMH output of the channel 3 Position */
#define PWM_OSSUPD_OSSUPH3_Msk                (_UINT32_(0x1) << PWM_OSSUPD_OSSUPH3_Pos)            /* (PWM_OSSUPD) Output Selection Set for PWMH output of the channel 3 Mask */
#define PWM_OSSUPD_OSSUPH3(value)             (PWM_OSSUPD_OSSUPH3_Msk & (_UINT32_(value) << PWM_OSSUPD_OSSUPH3_Pos)) /* Assigment of value for OSSUPH3 in the PWM_OSSUPD register */
#define   PWM_OSSUPD_OSSUPH3_0_Val            _UINT32_(0x0)                                        /* (PWM_OSSUPD) No effect.  */
#define   PWM_OSSUPD_OSSUPH3_1_Val            _UINT32_(0x1)                                        /* (PWM_OSSUPD) Output override value OOVHx selected as PWMH output of channel x at the beginning of the next channel x PWM period.  */
#define PWM_OSSUPD_OSSUPH3_0                  (PWM_OSSUPD_OSSUPH3_0_Val << PWM_OSSUPD_OSSUPH3_Pos) /* (PWM_OSSUPD) No effect. Position  */
#define PWM_OSSUPD_OSSUPH3_1                  (PWM_OSSUPD_OSSUPH3_1_Val << PWM_OSSUPD_OSSUPH3_Pos) /* (PWM_OSSUPD) Output override value OOVHx selected as PWMH output of channel x at the beginning of the next channel x PWM period. Position  */
#define PWM_OSSUPD_OSSUPL0_Pos                _UINT32_(16)                                         /* (PWM_OSSUPD) Output Selection Set for PWML output of the channel 0 Position */
#define PWM_OSSUPD_OSSUPL0_Msk                (_UINT32_(0x1) << PWM_OSSUPD_OSSUPL0_Pos)            /* (PWM_OSSUPD) Output Selection Set for PWML output of the channel 0 Mask */
#define PWM_OSSUPD_OSSUPL0(value)             (PWM_OSSUPD_OSSUPL0_Msk & (_UINT32_(value) << PWM_OSSUPD_OSSUPL0_Pos)) /* Assigment of value for OSSUPL0 in the PWM_OSSUPD register */
#define   PWM_OSSUPD_OSSUPL0_0_Val            _UINT32_(0x0)                                        /* (PWM_OSSUPD) No effect.  */
#define   PWM_OSSUPD_OSSUPL0_1_Val            _UINT32_(0x1)                                        /* (PWM_OSSUPD) Output override value OOVLx selected as PWML output of channel x at the beginning of the next channel x PWM period.  */
#define PWM_OSSUPD_OSSUPL0_0                  (PWM_OSSUPD_OSSUPL0_0_Val << PWM_OSSUPD_OSSUPL0_Pos) /* (PWM_OSSUPD) No effect. Position  */
#define PWM_OSSUPD_OSSUPL0_1                  (PWM_OSSUPD_OSSUPL0_1_Val << PWM_OSSUPD_OSSUPL0_Pos) /* (PWM_OSSUPD) Output override value OOVLx selected as PWML output of channel x at the beginning of the next channel x PWM period. Position  */
#define PWM_OSSUPD_OSSUPL1_Pos                _UINT32_(17)                                         /* (PWM_OSSUPD) Output Selection Set for PWML output of the channel 1 Position */
#define PWM_OSSUPD_OSSUPL1_Msk                (_UINT32_(0x1) << PWM_OSSUPD_OSSUPL1_Pos)            /* (PWM_OSSUPD) Output Selection Set for PWML output of the channel 1 Mask */
#define PWM_OSSUPD_OSSUPL1(value)             (PWM_OSSUPD_OSSUPL1_Msk & (_UINT32_(value) << PWM_OSSUPD_OSSUPL1_Pos)) /* Assigment of value for OSSUPL1 in the PWM_OSSUPD register */
#define   PWM_OSSUPD_OSSUPL1_0_Val            _UINT32_(0x0)                                        /* (PWM_OSSUPD) No effect.  */
#define   PWM_OSSUPD_OSSUPL1_1_Val            _UINT32_(0x1)                                        /* (PWM_OSSUPD) Output override value OOVLx selected as PWML output of channel x at the beginning of the next channel x PWM period.  */
#define PWM_OSSUPD_OSSUPL1_0                  (PWM_OSSUPD_OSSUPL1_0_Val << PWM_OSSUPD_OSSUPL1_Pos) /* (PWM_OSSUPD) No effect. Position  */
#define PWM_OSSUPD_OSSUPL1_1                  (PWM_OSSUPD_OSSUPL1_1_Val << PWM_OSSUPD_OSSUPL1_Pos) /* (PWM_OSSUPD) Output override value OOVLx selected as PWML output of channel x at the beginning of the next channel x PWM period. Position  */
#define PWM_OSSUPD_OSSUPL2_Pos                _UINT32_(18)                                         /* (PWM_OSSUPD) Output Selection Set for PWML output of the channel 2 Position */
#define PWM_OSSUPD_OSSUPL2_Msk                (_UINT32_(0x1) << PWM_OSSUPD_OSSUPL2_Pos)            /* (PWM_OSSUPD) Output Selection Set for PWML output of the channel 2 Mask */
#define PWM_OSSUPD_OSSUPL2(value)             (PWM_OSSUPD_OSSUPL2_Msk & (_UINT32_(value) << PWM_OSSUPD_OSSUPL2_Pos)) /* Assigment of value for OSSUPL2 in the PWM_OSSUPD register */
#define   PWM_OSSUPD_OSSUPL2_0_Val            _UINT32_(0x0)                                        /* (PWM_OSSUPD) No effect.  */
#define   PWM_OSSUPD_OSSUPL2_1_Val            _UINT32_(0x1)                                        /* (PWM_OSSUPD) Output override value OOVLx selected as PWML output of channel x at the beginning of the next channel x PWM period.  */
#define PWM_OSSUPD_OSSUPL2_0                  (PWM_OSSUPD_OSSUPL2_0_Val << PWM_OSSUPD_OSSUPL2_Pos) /* (PWM_OSSUPD) No effect. Position  */
#define PWM_OSSUPD_OSSUPL2_1                  (PWM_OSSUPD_OSSUPL2_1_Val << PWM_OSSUPD_OSSUPL2_Pos) /* (PWM_OSSUPD) Output override value OOVLx selected as PWML output of channel x at the beginning of the next channel x PWM period. Position  */
#define PWM_OSSUPD_OSSUPL3_Pos                _UINT32_(19)                                         /* (PWM_OSSUPD) Output Selection Set for PWML output of the channel 3 Position */
#define PWM_OSSUPD_OSSUPL3_Msk                (_UINT32_(0x1) << PWM_OSSUPD_OSSUPL3_Pos)            /* (PWM_OSSUPD) Output Selection Set for PWML output of the channel 3 Mask */
#define PWM_OSSUPD_OSSUPL3(value)             (PWM_OSSUPD_OSSUPL3_Msk & (_UINT32_(value) << PWM_OSSUPD_OSSUPL3_Pos)) /* Assigment of value for OSSUPL3 in the PWM_OSSUPD register */
#define   PWM_OSSUPD_OSSUPL3_0_Val            _UINT32_(0x0)                                        /* (PWM_OSSUPD) No effect.  */
#define   PWM_OSSUPD_OSSUPL3_1_Val            _UINT32_(0x1)                                        /* (PWM_OSSUPD) Output override value OOVLx selected as PWML output of channel x at the beginning of the next channel x PWM period.  */
#define PWM_OSSUPD_OSSUPL3_0                  (PWM_OSSUPD_OSSUPL3_0_Val << PWM_OSSUPD_OSSUPL3_Pos) /* (PWM_OSSUPD) No effect. Position  */
#define PWM_OSSUPD_OSSUPL3_1                  (PWM_OSSUPD_OSSUPL3_1_Val << PWM_OSSUPD_OSSUPL3_Pos) /* (PWM_OSSUPD) Output override value OOVLx selected as PWML output of channel x at the beginning of the next channel x PWM period. Position  */
#define PWM_OSSUPD_Msk                        _UINT32_(0x000F000F)                                 /* (PWM_OSSUPD) Register Mask  */

#define PWM_OSSUPD_OSSUPH_Pos                 _UINT32_(0)                                          /* (PWM_OSSUPD Position) Output Selection Set for PWMH output of the channel x */
#define PWM_OSSUPD_OSSUPH_Msk                 (_UINT32_(0xF) << PWM_OSSUPD_OSSUPH_Pos)             /* (PWM_OSSUPD Mask) OSSUPH */
#define PWM_OSSUPD_OSSUPH(value)              (PWM_OSSUPD_OSSUPH_Msk & (_UINT32_(value) << PWM_OSSUPD_OSSUPH_Pos)) 
#define PWM_OSSUPD_OSSUPL_Pos                 _UINT32_(16)                                         /* (PWM_OSSUPD Position) Output Selection Set for PWML output of the channel 3 */
#define PWM_OSSUPD_OSSUPL_Msk                 (_UINT32_(0xF) << PWM_OSSUPD_OSSUPL_Pos)             /* (PWM_OSSUPD Mask) OSSUPL */
#define PWM_OSSUPD_OSSUPL(value)              (PWM_OSSUPD_OSSUPL_Msk & (_UINT32_(value) << PWM_OSSUPD_OSSUPL_Pos)) 

/* -------- PWM_OSCUPD : (PWM Offset: 0x58) ( /W 32) PWM Output Selection Clear Update Register -------- */
#define PWM_OSCUPD_OSCUPH0_Pos                _UINT32_(0)                                          /* (PWM_OSCUPD) Output Selection Clear for PWMH output of the channel 0 Position */
#define PWM_OSCUPD_OSCUPH0_Msk                (_UINT32_(0x1) << PWM_OSCUPD_OSCUPH0_Pos)            /* (PWM_OSCUPD) Output Selection Clear for PWMH output of the channel 0 Mask */
#define PWM_OSCUPD_OSCUPH0(value)             (PWM_OSCUPD_OSCUPH0_Msk & (_UINT32_(value) << PWM_OSCUPD_OSCUPH0_Pos)) /* Assigment of value for OSCUPH0 in the PWM_OSCUPD register */
#define   PWM_OSCUPD_OSCUPH0_0_Val            _UINT32_(0x0)                                        /* (PWM_OSCUPD) No effect.  */
#define   PWM_OSCUPD_OSCUPH0_1_Val            _UINT32_(0x1)                                        /* (PWM_OSCUPD) Dead-time generator output DTOHx selected as PWMH output of channel x at the beginning of the next channel x PWM period.  */
#define PWM_OSCUPD_OSCUPH0_0                  (PWM_OSCUPD_OSCUPH0_0_Val << PWM_OSCUPD_OSCUPH0_Pos) /* (PWM_OSCUPD) No effect. Position  */
#define PWM_OSCUPD_OSCUPH0_1                  (PWM_OSCUPD_OSCUPH0_1_Val << PWM_OSCUPD_OSCUPH0_Pos) /* (PWM_OSCUPD) Dead-time generator output DTOHx selected as PWMH output of channel x at the beginning of the next channel x PWM period. Position  */
#define PWM_OSCUPD_OSCUPH1_Pos                _UINT32_(1)                                          /* (PWM_OSCUPD) Output Selection Clear for PWMH output of the channel 1 Position */
#define PWM_OSCUPD_OSCUPH1_Msk                (_UINT32_(0x1) << PWM_OSCUPD_OSCUPH1_Pos)            /* (PWM_OSCUPD) Output Selection Clear for PWMH output of the channel 1 Mask */
#define PWM_OSCUPD_OSCUPH1(value)             (PWM_OSCUPD_OSCUPH1_Msk & (_UINT32_(value) << PWM_OSCUPD_OSCUPH1_Pos)) /* Assigment of value for OSCUPH1 in the PWM_OSCUPD register */
#define   PWM_OSCUPD_OSCUPH1_0_Val            _UINT32_(0x0)                                        /* (PWM_OSCUPD) No effect.  */
#define   PWM_OSCUPD_OSCUPH1_1_Val            _UINT32_(0x1)                                        /* (PWM_OSCUPD) Dead-time generator output DTOHx selected as PWMH output of channel x at the beginning of the next channel x PWM period.  */
#define PWM_OSCUPD_OSCUPH1_0                  (PWM_OSCUPD_OSCUPH1_0_Val << PWM_OSCUPD_OSCUPH1_Pos) /* (PWM_OSCUPD) No effect. Position  */
#define PWM_OSCUPD_OSCUPH1_1                  (PWM_OSCUPD_OSCUPH1_1_Val << PWM_OSCUPD_OSCUPH1_Pos) /* (PWM_OSCUPD) Dead-time generator output DTOHx selected as PWMH output of channel x at the beginning of the next channel x PWM period. Position  */
#define PWM_OSCUPD_OSCUPH2_Pos                _UINT32_(2)                                          /* (PWM_OSCUPD) Output Selection Clear for PWMH output of the channel 2 Position */
#define PWM_OSCUPD_OSCUPH2_Msk                (_UINT32_(0x1) << PWM_OSCUPD_OSCUPH2_Pos)            /* (PWM_OSCUPD) Output Selection Clear for PWMH output of the channel 2 Mask */
#define PWM_OSCUPD_OSCUPH2(value)             (PWM_OSCUPD_OSCUPH2_Msk & (_UINT32_(value) << PWM_OSCUPD_OSCUPH2_Pos)) /* Assigment of value for OSCUPH2 in the PWM_OSCUPD register */
#define   PWM_OSCUPD_OSCUPH2_0_Val            _UINT32_(0x0)                                        /* (PWM_OSCUPD) No effect.  */
#define   PWM_OSCUPD_OSCUPH2_1_Val            _UINT32_(0x1)                                        /* (PWM_OSCUPD) Dead-time generator output DTOHx selected as PWMH output of channel x at the beginning of the next channel x PWM period.  */
#define PWM_OSCUPD_OSCUPH2_0                  (PWM_OSCUPD_OSCUPH2_0_Val << PWM_OSCUPD_OSCUPH2_Pos) /* (PWM_OSCUPD) No effect. Position  */
#define PWM_OSCUPD_OSCUPH2_1                  (PWM_OSCUPD_OSCUPH2_1_Val << PWM_OSCUPD_OSCUPH2_Pos) /* (PWM_OSCUPD) Dead-time generator output DTOHx selected as PWMH output of channel x at the beginning of the next channel x PWM period. Position  */
#define PWM_OSCUPD_OSCUPH3_Pos                _UINT32_(3)                                          /* (PWM_OSCUPD) Output Selection Clear for PWMH output of the channel 3 Position */
#define PWM_OSCUPD_OSCUPH3_Msk                (_UINT32_(0x1) << PWM_OSCUPD_OSCUPH3_Pos)            /* (PWM_OSCUPD) Output Selection Clear for PWMH output of the channel 3 Mask */
#define PWM_OSCUPD_OSCUPH3(value)             (PWM_OSCUPD_OSCUPH3_Msk & (_UINT32_(value) << PWM_OSCUPD_OSCUPH3_Pos)) /* Assigment of value for OSCUPH3 in the PWM_OSCUPD register */
#define   PWM_OSCUPD_OSCUPH3_0_Val            _UINT32_(0x0)                                        /* (PWM_OSCUPD) No effect.  */
#define   PWM_OSCUPD_OSCUPH3_1_Val            _UINT32_(0x1)                                        /* (PWM_OSCUPD) Dead-time generator output DTOHx selected as PWMH output of channel x at the beginning of the next channel x PWM period.  */
#define PWM_OSCUPD_OSCUPH3_0                  (PWM_OSCUPD_OSCUPH3_0_Val << PWM_OSCUPD_OSCUPH3_Pos) /* (PWM_OSCUPD) No effect. Position  */
#define PWM_OSCUPD_OSCUPH3_1                  (PWM_OSCUPD_OSCUPH3_1_Val << PWM_OSCUPD_OSCUPH3_Pos) /* (PWM_OSCUPD) Dead-time generator output DTOHx selected as PWMH output of channel x at the beginning of the next channel x PWM period. Position  */
#define PWM_OSCUPD_OSCUPL0_Pos                _UINT32_(16)                                         /* (PWM_OSCUPD) Output Selection Clear for PWML output of the channel 0 Position */
#define PWM_OSCUPD_OSCUPL0_Msk                (_UINT32_(0x1) << PWM_OSCUPD_OSCUPL0_Pos)            /* (PWM_OSCUPD) Output Selection Clear for PWML output of the channel 0 Mask */
#define PWM_OSCUPD_OSCUPL0(value)             (PWM_OSCUPD_OSCUPL0_Msk & (_UINT32_(value) << PWM_OSCUPD_OSCUPL0_Pos)) /* Assigment of value for OSCUPL0 in the PWM_OSCUPD register */
#define   PWM_OSCUPD_OSCUPL0_0_Val            _UINT32_(0x0)                                        /* (PWM_OSCUPD) No effect.  */
#define   PWM_OSCUPD_OSCUPL0_1_Val            _UINT32_(0x1)                                        /* (PWM_OSCUPD) Dead-time generator output DTOLx selected as PWML output of channel x at the beginning of the next channel x PWM period.  */
#define PWM_OSCUPD_OSCUPL0_0                  (PWM_OSCUPD_OSCUPL0_0_Val << PWM_OSCUPD_OSCUPL0_Pos) /* (PWM_OSCUPD) No effect. Position  */
#define PWM_OSCUPD_OSCUPL0_1                  (PWM_OSCUPD_OSCUPL0_1_Val << PWM_OSCUPD_OSCUPL0_Pos) /* (PWM_OSCUPD) Dead-time generator output DTOLx selected as PWML output of channel x at the beginning of the next channel x PWM period. Position  */
#define PWM_OSCUPD_OSCUPL1_Pos                _UINT32_(17)                                         /* (PWM_OSCUPD) Output Selection Clear for PWML output of the channel 1 Position */
#define PWM_OSCUPD_OSCUPL1_Msk                (_UINT32_(0x1) << PWM_OSCUPD_OSCUPL1_Pos)            /* (PWM_OSCUPD) Output Selection Clear for PWML output of the channel 1 Mask */
#define PWM_OSCUPD_OSCUPL1(value)             (PWM_OSCUPD_OSCUPL1_Msk & (_UINT32_(value) << PWM_OSCUPD_OSCUPL1_Pos)) /* Assigment of value for OSCUPL1 in the PWM_OSCUPD register */
#define   PWM_OSCUPD_OSCUPL1_0_Val            _UINT32_(0x0)                                        /* (PWM_OSCUPD) No effect.  */
#define   PWM_OSCUPD_OSCUPL1_1_Val            _UINT32_(0x1)                                        /* (PWM_OSCUPD) Dead-time generator output DTOLx selected as PWML output of channel x at the beginning of the next channel x PWM period.  */
#define PWM_OSCUPD_OSCUPL1_0                  (PWM_OSCUPD_OSCUPL1_0_Val << PWM_OSCUPD_OSCUPL1_Pos) /* (PWM_OSCUPD) No effect. Position  */
#define PWM_OSCUPD_OSCUPL1_1                  (PWM_OSCUPD_OSCUPL1_1_Val << PWM_OSCUPD_OSCUPL1_Pos) /* (PWM_OSCUPD) Dead-time generator output DTOLx selected as PWML output of channel x at the beginning of the next channel x PWM period. Position  */
#define PWM_OSCUPD_OSCUPL2_Pos                _UINT32_(18)                                         /* (PWM_OSCUPD) Output Selection Clear for PWML output of the channel 2 Position */
#define PWM_OSCUPD_OSCUPL2_Msk                (_UINT32_(0x1) << PWM_OSCUPD_OSCUPL2_Pos)            /* (PWM_OSCUPD) Output Selection Clear for PWML output of the channel 2 Mask */
#define PWM_OSCUPD_OSCUPL2(value)             (PWM_OSCUPD_OSCUPL2_Msk & (_UINT32_(value) << PWM_OSCUPD_OSCUPL2_Pos)) /* Assigment of value for OSCUPL2 in the PWM_OSCUPD register */
#define   PWM_OSCUPD_OSCUPL2_0_Val            _UINT32_(0x0)                                        /* (PWM_OSCUPD) No effect.  */
#define   PWM_OSCUPD_OSCUPL2_1_Val            _UINT32_(0x1)                                        /* (PWM_OSCUPD) Dead-time generator output DTOLx selected as PWML output of channel x at the beginning of the next channel x PWM period.  */
#define PWM_OSCUPD_OSCUPL2_0                  (PWM_OSCUPD_OSCUPL2_0_Val << PWM_OSCUPD_OSCUPL2_Pos) /* (PWM_OSCUPD) No effect. Position  */
#define PWM_OSCUPD_OSCUPL2_1                  (PWM_OSCUPD_OSCUPL2_1_Val << PWM_OSCUPD_OSCUPL2_Pos) /* (PWM_OSCUPD) Dead-time generator output DTOLx selected as PWML output of channel x at the beginning of the next channel x PWM period. Position  */
#define PWM_OSCUPD_OSCUPL3_Pos                _UINT32_(19)                                         /* (PWM_OSCUPD) Output Selection Clear for PWML output of the channel 3 Position */
#define PWM_OSCUPD_OSCUPL3_Msk                (_UINT32_(0x1) << PWM_OSCUPD_OSCUPL3_Pos)            /* (PWM_OSCUPD) Output Selection Clear for PWML output of the channel 3 Mask */
#define PWM_OSCUPD_OSCUPL3(value)             (PWM_OSCUPD_OSCUPL3_Msk & (_UINT32_(value) << PWM_OSCUPD_OSCUPL3_Pos)) /* Assigment of value for OSCUPL3 in the PWM_OSCUPD register */
#define   PWM_OSCUPD_OSCUPL3_0_Val            _UINT32_(0x0)                                        /* (PWM_OSCUPD) No effect.  */
#define   PWM_OSCUPD_OSCUPL3_1_Val            _UINT32_(0x1)                                        /* (PWM_OSCUPD) Dead-time generator output DTOLx selected as PWML output of channel x at the beginning of the next channel x PWM period.  */
#define PWM_OSCUPD_OSCUPL3_0                  (PWM_OSCUPD_OSCUPL3_0_Val << PWM_OSCUPD_OSCUPL3_Pos) /* (PWM_OSCUPD) No effect. Position  */
#define PWM_OSCUPD_OSCUPL3_1                  (PWM_OSCUPD_OSCUPL3_1_Val << PWM_OSCUPD_OSCUPL3_Pos) /* (PWM_OSCUPD) Dead-time generator output DTOLx selected as PWML output of channel x at the beginning of the next channel x PWM period. Position  */
#define PWM_OSCUPD_Msk                        _UINT32_(0x000F000F)                                 /* (PWM_OSCUPD) Register Mask  */

#define PWM_OSCUPD_OSCUPH_Pos                 _UINT32_(0)                                          /* (PWM_OSCUPD Position) Output Selection Clear for PWMH output of the channel x */
#define PWM_OSCUPD_OSCUPH_Msk                 (_UINT32_(0xF) << PWM_OSCUPD_OSCUPH_Pos)             /* (PWM_OSCUPD Mask) OSCUPH */
#define PWM_OSCUPD_OSCUPH(value)              (PWM_OSCUPD_OSCUPH_Msk & (_UINT32_(value) << PWM_OSCUPD_OSCUPH_Pos)) 
#define PWM_OSCUPD_OSCUPL_Pos                 _UINT32_(16)                                         /* (PWM_OSCUPD Position) Output Selection Clear for PWML output of the channel 3 */
#define PWM_OSCUPD_OSCUPL_Msk                 (_UINT32_(0xF) << PWM_OSCUPD_OSCUPL_Pos)             /* (PWM_OSCUPD Mask) OSCUPL */
#define PWM_OSCUPD_OSCUPL(value)              (PWM_OSCUPD_OSCUPL_Msk & (_UINT32_(value) << PWM_OSCUPD_OSCUPL_Pos)) 

/* -------- PWM_FMR : (PWM Offset: 0x5C) (R/W 32) PWM Fault Mode Register -------- */
#define PWM_FMR_RESETVALUE                    _UINT32_(0x00)                                       /*  (PWM_FMR) PWM Fault Mode Register  Reset Value */

#define PWM_FMR_FPOL_Pos                      _UINT32_(0)                                          /* (PWM_FMR) Fault Polarity Position */
#define PWM_FMR_FPOL_Msk                      (_UINT32_(0xFF) << PWM_FMR_FPOL_Pos)                 /* (PWM_FMR) Fault Polarity Mask */
#define PWM_FMR_FPOL(value)                   (PWM_FMR_FPOL_Msk & (_UINT32_(value) << PWM_FMR_FPOL_Pos)) /* Assigment of value for FPOL in the PWM_FMR register */
#define   PWM_FMR_FPOL_0_Val                  _UINT32_(0x0)                                        /* (PWM_FMR) The fault y becomes active when the fault input y is at 0.  */
#define   PWM_FMR_FPOL_1_Val                  _UINT32_(0x1)                                        /* (PWM_FMR) The fault y becomes active when the fault input y is at 1.  */
#define PWM_FMR_FPOL_0                        (PWM_FMR_FPOL_0_Val << PWM_FMR_FPOL_Pos)             /* (PWM_FMR) The fault y becomes active when the fault input y is at 0. Position  */
#define PWM_FMR_FPOL_1                        (PWM_FMR_FPOL_1_Val << PWM_FMR_FPOL_Pos)             /* (PWM_FMR) The fault y becomes active when the fault input y is at 1. Position  */
#define PWM_FMR_FMOD_Pos                      _UINT32_(8)                                          /* (PWM_FMR) Fault Activation Mode Position */
#define PWM_FMR_FMOD_Msk                      (_UINT32_(0xFF) << PWM_FMR_FMOD_Pos)                 /* (PWM_FMR) Fault Activation Mode Mask */
#define PWM_FMR_FMOD(value)                   (PWM_FMR_FMOD_Msk & (_UINT32_(value) << PWM_FMR_FMOD_Pos)) /* Assigment of value for FMOD in the PWM_FMR register */
#define PWM_FMR_FFIL_Pos                      _UINT32_(16)                                         /* (PWM_FMR) Fault Filtering Position */
#define PWM_FMR_FFIL_Msk                      (_UINT32_(0xFF) << PWM_FMR_FFIL_Pos)                 /* (PWM_FMR) Fault Filtering Mask */
#define PWM_FMR_FFIL(value)                   (PWM_FMR_FFIL_Msk & (_UINT32_(value) << PWM_FMR_FFIL_Pos)) /* Assigment of value for FFIL in the PWM_FMR register */
#define PWM_FMR_Msk                           _UINT32_(0x00FFFFFF)                                 /* (PWM_FMR) Register Mask  */


/* -------- PWM_FSR : (PWM Offset: 0x60) ( R/ 32) PWM Fault Status Register -------- */
#define PWM_FSR_RESETVALUE                    _UINT32_(0x00)                                       /*  (PWM_FSR) PWM Fault Status Register  Reset Value */

#define PWM_FSR_FIV_Pos                       _UINT32_(0)                                          /* (PWM_FSR) Fault Input Value Position */
#define PWM_FSR_FIV_Msk                       (_UINT32_(0xFF) << PWM_FSR_FIV_Pos)                  /* (PWM_FSR) Fault Input Value Mask */
#define PWM_FSR_FIV(value)                    (PWM_FSR_FIV_Msk & (_UINT32_(value) << PWM_FSR_FIV_Pos)) /* Assigment of value for FIV in the PWM_FSR register */
#define PWM_FSR_FS_Pos                        _UINT32_(8)                                          /* (PWM_FSR) Fault Status Position */
#define PWM_FSR_FS_Msk                        (_UINT32_(0xFF) << PWM_FSR_FS_Pos)                   /* (PWM_FSR) Fault Status Mask */
#define PWM_FSR_FS(value)                     (PWM_FSR_FS_Msk & (_UINT32_(value) << PWM_FSR_FS_Pos)) /* Assigment of value for FS in the PWM_FSR register */
#define PWM_FSR_Msk                           _UINT32_(0x0000FFFF)                                 /* (PWM_FSR) Register Mask  */


/* -------- PWM_FCR : (PWM Offset: 0x64) ( /W 32) PWM Fault Clear Register -------- */
#define PWM_FCR_FCLR_Pos                      _UINT32_(0)                                          /* (PWM_FCR) Fault Clear Position */
#define PWM_FCR_FCLR_Msk                      (_UINT32_(0xFF) << PWM_FCR_FCLR_Pos)                 /* (PWM_FCR) Fault Clear Mask */
#define PWM_FCR_FCLR(value)                   (PWM_FCR_FCLR_Msk & (_UINT32_(value) << PWM_FCR_FCLR_Pos)) /* Assigment of value for FCLR in the PWM_FCR register */
#define PWM_FCR_Msk                           _UINT32_(0x000000FF)                                 /* (PWM_FCR) Register Mask  */


/* -------- PWM_FPV1 : (PWM Offset: 0x68) (R/W 32) PWM Fault Protection Value Register 1 -------- */
#define PWM_FPV1_RESETVALUE                   _UINT32_(0x00)                                       /*  (PWM_FPV1) PWM Fault Protection Value Register 1  Reset Value */

#define PWM_FPV1_FPVH0_Pos                    _UINT32_(0)                                          /* (PWM_FPV1) Fault Protection Value for PWMH output on channel 0 Position */
#define PWM_FPV1_FPVH0_Msk                    (_UINT32_(0x1) << PWM_FPV1_FPVH0_Pos)                /* (PWM_FPV1) Fault Protection Value for PWMH output on channel 0 Mask */
#define PWM_FPV1_FPVH0(value)                 (PWM_FPV1_FPVH0_Msk & (_UINT32_(value) << PWM_FPV1_FPVH0_Pos)) /* Assigment of value for FPVH0 in the PWM_FPV1 register */
#define   PWM_FPV1_FPVH0_0_Val                _UINT32_(0x0)                                        /* (PWM_FPV1) PWMH output of channel x is forced to '0' when fault occurs.  */
#define   PWM_FPV1_FPVH0_1_Val                _UINT32_(0x1)                                        /* (PWM_FPV1) PWMH output of channel x is forced to '1' when fault occurs.  */
#define PWM_FPV1_FPVH0_0                      (PWM_FPV1_FPVH0_0_Val << PWM_FPV1_FPVH0_Pos)         /* (PWM_FPV1) PWMH output of channel x is forced to '0' when fault occurs. Position  */
#define PWM_FPV1_FPVH0_1                      (PWM_FPV1_FPVH0_1_Val << PWM_FPV1_FPVH0_Pos)         /* (PWM_FPV1) PWMH output of channel x is forced to '1' when fault occurs. Position  */
#define PWM_FPV1_FPVH1_Pos                    _UINT32_(1)                                          /* (PWM_FPV1) Fault Protection Value for PWMH output on channel 1 Position */
#define PWM_FPV1_FPVH1_Msk                    (_UINT32_(0x1) << PWM_FPV1_FPVH1_Pos)                /* (PWM_FPV1) Fault Protection Value for PWMH output on channel 1 Mask */
#define PWM_FPV1_FPVH1(value)                 (PWM_FPV1_FPVH1_Msk & (_UINT32_(value) << PWM_FPV1_FPVH1_Pos)) /* Assigment of value for FPVH1 in the PWM_FPV1 register */
#define   PWM_FPV1_FPVH1_0_Val                _UINT32_(0x0)                                        /* (PWM_FPV1) PWMH output of channel x is forced to '0' when fault occurs.  */
#define   PWM_FPV1_FPVH1_1_Val                _UINT32_(0x1)                                        /* (PWM_FPV1) PWMH output of channel x is forced to '1' when fault occurs.  */
#define PWM_FPV1_FPVH1_0                      (PWM_FPV1_FPVH1_0_Val << PWM_FPV1_FPVH1_Pos)         /* (PWM_FPV1) PWMH output of channel x is forced to '0' when fault occurs. Position  */
#define PWM_FPV1_FPVH1_1                      (PWM_FPV1_FPVH1_1_Val << PWM_FPV1_FPVH1_Pos)         /* (PWM_FPV1) PWMH output of channel x is forced to '1' when fault occurs. Position  */
#define PWM_FPV1_FPVH2_Pos                    _UINT32_(2)                                          /* (PWM_FPV1) Fault Protection Value for PWMH output on channel 2 Position */
#define PWM_FPV1_FPVH2_Msk                    (_UINT32_(0x1) << PWM_FPV1_FPVH2_Pos)                /* (PWM_FPV1) Fault Protection Value for PWMH output on channel 2 Mask */
#define PWM_FPV1_FPVH2(value)                 (PWM_FPV1_FPVH2_Msk & (_UINT32_(value) << PWM_FPV1_FPVH2_Pos)) /* Assigment of value for FPVH2 in the PWM_FPV1 register */
#define   PWM_FPV1_FPVH2_0_Val                _UINT32_(0x0)                                        /* (PWM_FPV1) PWMH output of channel x is forced to '0' when fault occurs.  */
#define   PWM_FPV1_FPVH2_1_Val                _UINT32_(0x1)                                        /* (PWM_FPV1) PWMH output of channel x is forced to '1' when fault occurs.  */
#define PWM_FPV1_FPVH2_0                      (PWM_FPV1_FPVH2_0_Val << PWM_FPV1_FPVH2_Pos)         /* (PWM_FPV1) PWMH output of channel x is forced to '0' when fault occurs. Position  */
#define PWM_FPV1_FPVH2_1                      (PWM_FPV1_FPVH2_1_Val << PWM_FPV1_FPVH2_Pos)         /* (PWM_FPV1) PWMH output of channel x is forced to '1' when fault occurs. Position  */
#define PWM_FPV1_FPVH3_Pos                    _UINT32_(3)                                          /* (PWM_FPV1) Fault Protection Value for PWMH output on channel 3 Position */
#define PWM_FPV1_FPVH3_Msk                    (_UINT32_(0x1) << PWM_FPV1_FPVH3_Pos)                /* (PWM_FPV1) Fault Protection Value for PWMH output on channel 3 Mask */
#define PWM_FPV1_FPVH3(value)                 (PWM_FPV1_FPVH3_Msk & (_UINT32_(value) << PWM_FPV1_FPVH3_Pos)) /* Assigment of value for FPVH3 in the PWM_FPV1 register */
#define   PWM_FPV1_FPVH3_0_Val                _UINT32_(0x0)                                        /* (PWM_FPV1) PWMH output of channel x is forced to '0' when fault occurs.  */
#define   PWM_FPV1_FPVH3_1_Val                _UINT32_(0x1)                                        /* (PWM_FPV1) PWMH output of channel x is forced to '1' when fault occurs.  */
#define PWM_FPV1_FPVH3_0                      (PWM_FPV1_FPVH3_0_Val << PWM_FPV1_FPVH3_Pos)         /* (PWM_FPV1) PWMH output of channel x is forced to '0' when fault occurs. Position  */
#define PWM_FPV1_FPVH3_1                      (PWM_FPV1_FPVH3_1_Val << PWM_FPV1_FPVH3_Pos)         /* (PWM_FPV1) PWMH output of channel x is forced to '1' when fault occurs. Position  */
#define PWM_FPV1_FPVL0_Pos                    _UINT32_(16)                                         /* (PWM_FPV1) Fault Protection Value for PWML output on channel 0 Position */
#define PWM_FPV1_FPVL0_Msk                    (_UINT32_(0x1) << PWM_FPV1_FPVL0_Pos)                /* (PWM_FPV1) Fault Protection Value for PWML output on channel 0 Mask */
#define PWM_FPV1_FPVL0(value)                 (PWM_FPV1_FPVL0_Msk & (_UINT32_(value) << PWM_FPV1_FPVL0_Pos)) /* Assigment of value for FPVL0 in the PWM_FPV1 register */
#define   PWM_FPV1_FPVL0_0_Val                _UINT32_(0x0)                                        /* (PWM_FPV1) PWML output of channel x is forced to '0' when fault occurs.  */
#define   PWM_FPV1_FPVL0_1_Val                _UINT32_(0x1)                                        /* (PWM_FPV1) PWML output of channel x is forced to '1' when fault occurs.  */
#define PWM_FPV1_FPVL0_0                      (PWM_FPV1_FPVL0_0_Val << PWM_FPV1_FPVL0_Pos)         /* (PWM_FPV1) PWML output of channel x is forced to '0' when fault occurs. Position  */
#define PWM_FPV1_FPVL0_1                      (PWM_FPV1_FPVL0_1_Val << PWM_FPV1_FPVL0_Pos)         /* (PWM_FPV1) PWML output of channel x is forced to '1' when fault occurs. Position  */
#define PWM_FPV1_FPVL1_Pos                    _UINT32_(17)                                         /* (PWM_FPV1) Fault Protection Value for PWML output on channel 1 Position */
#define PWM_FPV1_FPVL1_Msk                    (_UINT32_(0x1) << PWM_FPV1_FPVL1_Pos)                /* (PWM_FPV1) Fault Protection Value for PWML output on channel 1 Mask */
#define PWM_FPV1_FPVL1(value)                 (PWM_FPV1_FPVL1_Msk & (_UINT32_(value) << PWM_FPV1_FPVL1_Pos)) /* Assigment of value for FPVL1 in the PWM_FPV1 register */
#define   PWM_FPV1_FPVL1_0_Val                _UINT32_(0x0)                                        /* (PWM_FPV1) PWML output of channel x is forced to '0' when fault occurs.  */
#define   PWM_FPV1_FPVL1_1_Val                _UINT32_(0x1)                                        /* (PWM_FPV1) PWML output of channel x is forced to '1' when fault occurs.  */
#define PWM_FPV1_FPVL1_0                      (PWM_FPV1_FPVL1_0_Val << PWM_FPV1_FPVL1_Pos)         /* (PWM_FPV1) PWML output of channel x is forced to '0' when fault occurs. Position  */
#define PWM_FPV1_FPVL1_1                      (PWM_FPV1_FPVL1_1_Val << PWM_FPV1_FPVL1_Pos)         /* (PWM_FPV1) PWML output of channel x is forced to '1' when fault occurs. Position  */
#define PWM_FPV1_FPVL2_Pos                    _UINT32_(18)                                         /* (PWM_FPV1) Fault Protection Value for PWML output on channel 2 Position */
#define PWM_FPV1_FPVL2_Msk                    (_UINT32_(0x1) << PWM_FPV1_FPVL2_Pos)                /* (PWM_FPV1) Fault Protection Value for PWML output on channel 2 Mask */
#define PWM_FPV1_FPVL2(value)                 (PWM_FPV1_FPVL2_Msk & (_UINT32_(value) << PWM_FPV1_FPVL2_Pos)) /* Assigment of value for FPVL2 in the PWM_FPV1 register */
#define   PWM_FPV1_FPVL2_0_Val                _UINT32_(0x0)                                        /* (PWM_FPV1) PWML output of channel x is forced to '0' when fault occurs.  */
#define   PWM_FPV1_FPVL2_1_Val                _UINT32_(0x1)                                        /* (PWM_FPV1) PWML output of channel x is forced to '1' when fault occurs.  */
#define PWM_FPV1_FPVL2_0                      (PWM_FPV1_FPVL2_0_Val << PWM_FPV1_FPVL2_Pos)         /* (PWM_FPV1) PWML output of channel x is forced to '0' when fault occurs. Position  */
#define PWM_FPV1_FPVL2_1                      (PWM_FPV1_FPVL2_1_Val << PWM_FPV1_FPVL2_Pos)         /* (PWM_FPV1) PWML output of channel x is forced to '1' when fault occurs. Position  */
#define PWM_FPV1_FPVL3_Pos                    _UINT32_(19)                                         /* (PWM_FPV1) Fault Protection Value for PWML output on channel 3 Position */
#define PWM_FPV1_FPVL3_Msk                    (_UINT32_(0x1) << PWM_FPV1_FPVL3_Pos)                /* (PWM_FPV1) Fault Protection Value for PWML output on channel 3 Mask */
#define PWM_FPV1_FPVL3(value)                 (PWM_FPV1_FPVL3_Msk & (_UINT32_(value) << PWM_FPV1_FPVL3_Pos)) /* Assigment of value for FPVL3 in the PWM_FPV1 register */
#define   PWM_FPV1_FPVL3_0_Val                _UINT32_(0x0)                                        /* (PWM_FPV1) PWML output of channel x is forced to '0' when fault occurs.  */
#define   PWM_FPV1_FPVL3_1_Val                _UINT32_(0x1)                                        /* (PWM_FPV1) PWML output of channel x is forced to '1' when fault occurs.  */
#define PWM_FPV1_FPVL3_0                      (PWM_FPV1_FPVL3_0_Val << PWM_FPV1_FPVL3_Pos)         /* (PWM_FPV1) PWML output of channel x is forced to '0' when fault occurs. Position  */
#define PWM_FPV1_FPVL3_1                      (PWM_FPV1_FPVL3_1_Val << PWM_FPV1_FPVL3_Pos)         /* (PWM_FPV1) PWML output of channel x is forced to '1' when fault occurs. Position  */
#define PWM_FPV1_Msk                          _UINT32_(0x000F000F)                                 /* (PWM_FPV1) Register Mask  */

#define PWM_FPV1_FPVH_Pos                     _UINT32_(0)                                          /* (PWM_FPV1 Position) Fault Protection Value for PWMH output on channel x */
#define PWM_FPV1_FPVH_Msk                     (_UINT32_(0xF) << PWM_FPV1_FPVH_Pos)                 /* (PWM_FPV1 Mask) FPVH */
#define PWM_FPV1_FPVH(value)                  (PWM_FPV1_FPVH_Msk & (_UINT32_(value) << PWM_FPV1_FPVH_Pos)) 
#define PWM_FPV1_FPVL_Pos                     _UINT32_(16)                                         /* (PWM_FPV1 Position) Fault Protection Value for PWML output on channel 3 */
#define PWM_FPV1_FPVL_Msk                     (_UINT32_(0xF) << PWM_FPV1_FPVL_Pos)                 /* (PWM_FPV1 Mask) FPVL */
#define PWM_FPV1_FPVL(value)                  (PWM_FPV1_FPVL_Msk & (_UINT32_(value) << PWM_FPV1_FPVL_Pos)) 

/* -------- PWM_FPE : (PWM Offset: 0x6C) (R/W 32) PWM Fault Protection Enable Register -------- */
#define PWM_FPE_RESETVALUE                    _UINT32_(0x00)                                       /*  (PWM_FPE) PWM Fault Protection Enable Register  Reset Value */

#define PWM_FPE_FPE0_Pos                      _UINT32_(0)                                          /* (PWM_FPE) Fault Protection Enable for channel 0 Position */
#define PWM_FPE_FPE0_Msk                      (_UINT32_(0xFF) << PWM_FPE_FPE0_Pos)                 /* (PWM_FPE) Fault Protection Enable for channel 0 Mask */
#define PWM_FPE_FPE0(value)                   (PWM_FPE_FPE0_Msk & (_UINT32_(value) << PWM_FPE_FPE0_Pos)) /* Assigment of value for FPE0 in the PWM_FPE register */
#define PWM_FPE_FPE1_Pos                      _UINT32_(8)                                          /* (PWM_FPE) Fault Protection Enable for channel 1 Position */
#define PWM_FPE_FPE1_Msk                      (_UINT32_(0xFF) << PWM_FPE_FPE1_Pos)                 /* (PWM_FPE) Fault Protection Enable for channel 1 Mask */
#define PWM_FPE_FPE1(value)                   (PWM_FPE_FPE1_Msk & (_UINT32_(value) << PWM_FPE_FPE1_Pos)) /* Assigment of value for FPE1 in the PWM_FPE register */
#define PWM_FPE_FPE2_Pos                      _UINT32_(16)                                         /* (PWM_FPE) Fault Protection Enable for channel 2 Position */
#define PWM_FPE_FPE2_Msk                      (_UINT32_(0xFF) << PWM_FPE_FPE2_Pos)                 /* (PWM_FPE) Fault Protection Enable for channel 2 Mask */
#define PWM_FPE_FPE2(value)                   (PWM_FPE_FPE2_Msk & (_UINT32_(value) << PWM_FPE_FPE2_Pos)) /* Assigment of value for FPE2 in the PWM_FPE register */
#define PWM_FPE_FPE3_Pos                      _UINT32_(24)                                         /* (PWM_FPE) Fault Protection Enable for channel 3 Position */
#define PWM_FPE_FPE3_Msk                      (_UINT32_(0xFF) << PWM_FPE_FPE3_Pos)                 /* (PWM_FPE) Fault Protection Enable for channel 3 Mask */
#define PWM_FPE_FPE3(value)                   (PWM_FPE_FPE3_Msk & (_UINT32_(value) << PWM_FPE_FPE3_Pos)) /* Assigment of value for FPE3 in the PWM_FPE register */
#define PWM_FPE_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (PWM_FPE) Register Mask  */


/* -------- PWM_ELMR : (PWM Offset: 0x7C) (R/W 32) PWM Event Line x Mode Register -------- */
#define PWM_ELMR_RESETVALUE                   _UINT32_(0x00)                                       /*  (PWM_ELMR) PWM Event Line x Mode Register  Reset Value */

#define PWM_ELMR_CSEL0_Pos                    _UINT32_(0)                                          /* (PWM_ELMR) Comparison y Selection Position */
#define PWM_ELMR_CSEL0_Msk                    (_UINT32_(0x1) << PWM_ELMR_CSEL0_Pos)                /* (PWM_ELMR) Comparison y Selection Mask */
#define PWM_ELMR_CSEL0(value)                 (PWM_ELMR_CSEL0_Msk & (_UINT32_(value) << PWM_ELMR_CSEL0_Pos)) /* Assigment of value for CSEL0 in the PWM_ELMR register */
#define   PWM_ELMR_CSEL0_0_Val                _UINT32_(0x0)                                        /* (PWM_ELMR) A pulse is not generated on the event line x when the comparison y matches.  */
#define   PWM_ELMR_CSEL0_1_Val                _UINT32_(0x1)                                        /* (PWM_ELMR) A pulse is generated on the event line x when the comparison y match.  */
#define PWM_ELMR_CSEL0_0                      (PWM_ELMR_CSEL0_0_Val << PWM_ELMR_CSEL0_Pos)         /* (PWM_ELMR) A pulse is not generated on the event line x when the comparison y matches. Position  */
#define PWM_ELMR_CSEL0_1                      (PWM_ELMR_CSEL0_1_Val << PWM_ELMR_CSEL0_Pos)         /* (PWM_ELMR) A pulse is generated on the event line x when the comparison y match. Position  */
#define PWM_ELMR_CSEL1_Pos                    _UINT32_(1)                                          /* (PWM_ELMR) Comparison y Selection Position */
#define PWM_ELMR_CSEL1_Msk                    (_UINT32_(0x1) << PWM_ELMR_CSEL1_Pos)                /* (PWM_ELMR) Comparison y Selection Mask */
#define PWM_ELMR_CSEL1(value)                 (PWM_ELMR_CSEL1_Msk & (_UINT32_(value) << PWM_ELMR_CSEL1_Pos)) /* Assigment of value for CSEL1 in the PWM_ELMR register */
#define   PWM_ELMR_CSEL1_0_Val                _UINT32_(0x0)                                        /* (PWM_ELMR) A pulse is not generated on the event line x when the comparison y matches.  */
#define   PWM_ELMR_CSEL1_1_Val                _UINT32_(0x1)                                        /* (PWM_ELMR) A pulse is generated on the event line x when the comparison y match.  */
#define PWM_ELMR_CSEL1_0                      (PWM_ELMR_CSEL1_0_Val << PWM_ELMR_CSEL1_Pos)         /* (PWM_ELMR) A pulse is not generated on the event line x when the comparison y matches. Position  */
#define PWM_ELMR_CSEL1_1                      (PWM_ELMR_CSEL1_1_Val << PWM_ELMR_CSEL1_Pos)         /* (PWM_ELMR) A pulse is generated on the event line x when the comparison y match. Position  */
#define PWM_ELMR_CSEL2_Pos                    _UINT32_(2)                                          /* (PWM_ELMR) Comparison y Selection Position */
#define PWM_ELMR_CSEL2_Msk                    (_UINT32_(0x1) << PWM_ELMR_CSEL2_Pos)                /* (PWM_ELMR) Comparison y Selection Mask */
#define PWM_ELMR_CSEL2(value)                 (PWM_ELMR_CSEL2_Msk & (_UINT32_(value) << PWM_ELMR_CSEL2_Pos)) /* Assigment of value for CSEL2 in the PWM_ELMR register */
#define   PWM_ELMR_CSEL2_0_Val                _UINT32_(0x0)                                        /* (PWM_ELMR) A pulse is not generated on the event line x when the comparison y matches.  */
#define   PWM_ELMR_CSEL2_1_Val                _UINT32_(0x1)                                        /* (PWM_ELMR) A pulse is generated on the event line x when the comparison y match.  */
#define PWM_ELMR_CSEL2_0                      (PWM_ELMR_CSEL2_0_Val << PWM_ELMR_CSEL2_Pos)         /* (PWM_ELMR) A pulse is not generated on the event line x when the comparison y matches. Position  */
#define PWM_ELMR_CSEL2_1                      (PWM_ELMR_CSEL2_1_Val << PWM_ELMR_CSEL2_Pos)         /* (PWM_ELMR) A pulse is generated on the event line x when the comparison y match. Position  */
#define PWM_ELMR_CSEL3_Pos                    _UINT32_(3)                                          /* (PWM_ELMR) Comparison y Selection Position */
#define PWM_ELMR_CSEL3_Msk                    (_UINT32_(0x1) << PWM_ELMR_CSEL3_Pos)                /* (PWM_ELMR) Comparison y Selection Mask */
#define PWM_ELMR_CSEL3(value)                 (PWM_ELMR_CSEL3_Msk & (_UINT32_(value) << PWM_ELMR_CSEL3_Pos)) /* Assigment of value for CSEL3 in the PWM_ELMR register */
#define   PWM_ELMR_CSEL3_0_Val                _UINT32_(0x0)                                        /* (PWM_ELMR) A pulse is not generated on the event line x when the comparison y matches.  */
#define   PWM_ELMR_CSEL3_1_Val                _UINT32_(0x1)                                        /* (PWM_ELMR) A pulse is generated on the event line x when the comparison y match.  */
#define PWM_ELMR_CSEL3_0                      (PWM_ELMR_CSEL3_0_Val << PWM_ELMR_CSEL3_Pos)         /* (PWM_ELMR) A pulse is not generated on the event line x when the comparison y matches. Position  */
#define PWM_ELMR_CSEL3_1                      (PWM_ELMR_CSEL3_1_Val << PWM_ELMR_CSEL3_Pos)         /* (PWM_ELMR) A pulse is generated on the event line x when the comparison y match. Position  */
#define PWM_ELMR_CSEL4_Pos                    _UINT32_(4)                                          /* (PWM_ELMR) Comparison y Selection Position */
#define PWM_ELMR_CSEL4_Msk                    (_UINT32_(0x1) << PWM_ELMR_CSEL4_Pos)                /* (PWM_ELMR) Comparison y Selection Mask */
#define PWM_ELMR_CSEL4(value)                 (PWM_ELMR_CSEL4_Msk & (_UINT32_(value) << PWM_ELMR_CSEL4_Pos)) /* Assigment of value for CSEL4 in the PWM_ELMR register */
#define   PWM_ELMR_CSEL4_0_Val                _UINT32_(0x0)                                        /* (PWM_ELMR) A pulse is not generated on the event line x when the comparison y matches.  */
#define   PWM_ELMR_CSEL4_1_Val                _UINT32_(0x1)                                        /* (PWM_ELMR) A pulse is generated on the event line x when the comparison y match.  */
#define PWM_ELMR_CSEL4_0                      (PWM_ELMR_CSEL4_0_Val << PWM_ELMR_CSEL4_Pos)         /* (PWM_ELMR) A pulse is not generated on the event line x when the comparison y matches. Position  */
#define PWM_ELMR_CSEL4_1                      (PWM_ELMR_CSEL4_1_Val << PWM_ELMR_CSEL4_Pos)         /* (PWM_ELMR) A pulse is generated on the event line x when the comparison y match. Position  */
#define PWM_ELMR_CSEL5_Pos                    _UINT32_(5)                                          /* (PWM_ELMR) Comparison y Selection Position */
#define PWM_ELMR_CSEL5_Msk                    (_UINT32_(0x1) << PWM_ELMR_CSEL5_Pos)                /* (PWM_ELMR) Comparison y Selection Mask */
#define PWM_ELMR_CSEL5(value)                 (PWM_ELMR_CSEL5_Msk & (_UINT32_(value) << PWM_ELMR_CSEL5_Pos)) /* Assigment of value for CSEL5 in the PWM_ELMR register */
#define   PWM_ELMR_CSEL5_0_Val                _UINT32_(0x0)                                        /* (PWM_ELMR) A pulse is not generated on the event line x when the comparison y matches.  */
#define   PWM_ELMR_CSEL5_1_Val                _UINT32_(0x1)                                        /* (PWM_ELMR) A pulse is generated on the event line x when the comparison y match.  */
#define PWM_ELMR_CSEL5_0                      (PWM_ELMR_CSEL5_0_Val << PWM_ELMR_CSEL5_Pos)         /* (PWM_ELMR) A pulse is not generated on the event line x when the comparison y matches. Position  */
#define PWM_ELMR_CSEL5_1                      (PWM_ELMR_CSEL5_1_Val << PWM_ELMR_CSEL5_Pos)         /* (PWM_ELMR) A pulse is generated on the event line x when the comparison y match. Position  */
#define PWM_ELMR_CSEL6_Pos                    _UINT32_(6)                                          /* (PWM_ELMR) Comparison y Selection Position */
#define PWM_ELMR_CSEL6_Msk                    (_UINT32_(0x1) << PWM_ELMR_CSEL6_Pos)                /* (PWM_ELMR) Comparison y Selection Mask */
#define PWM_ELMR_CSEL6(value)                 (PWM_ELMR_CSEL6_Msk & (_UINT32_(value) << PWM_ELMR_CSEL6_Pos)) /* Assigment of value for CSEL6 in the PWM_ELMR register */
#define   PWM_ELMR_CSEL6_0_Val                _UINT32_(0x0)                                        /* (PWM_ELMR) A pulse is not generated on the event line x when the comparison y matches.  */
#define   PWM_ELMR_CSEL6_1_Val                _UINT32_(0x1)                                        /* (PWM_ELMR) A pulse is generated on the event line x when the comparison y match.  */
#define PWM_ELMR_CSEL6_0                      (PWM_ELMR_CSEL6_0_Val << PWM_ELMR_CSEL6_Pos)         /* (PWM_ELMR) A pulse is not generated on the event line x when the comparison y matches. Position  */
#define PWM_ELMR_CSEL6_1                      (PWM_ELMR_CSEL6_1_Val << PWM_ELMR_CSEL6_Pos)         /* (PWM_ELMR) A pulse is generated on the event line x when the comparison y match. Position  */
#define PWM_ELMR_CSEL7_Pos                    _UINT32_(7)                                          /* (PWM_ELMR) Comparison y Selection Position */
#define PWM_ELMR_CSEL7_Msk                    (_UINT32_(0x1) << PWM_ELMR_CSEL7_Pos)                /* (PWM_ELMR) Comparison y Selection Mask */
#define PWM_ELMR_CSEL7(value)                 (PWM_ELMR_CSEL7_Msk & (_UINT32_(value) << PWM_ELMR_CSEL7_Pos)) /* Assigment of value for CSEL7 in the PWM_ELMR register */
#define   PWM_ELMR_CSEL7_0_Val                _UINT32_(0x0)                                        /* (PWM_ELMR) A pulse is not generated on the event line x when the comparison y matches.  */
#define   PWM_ELMR_CSEL7_1_Val                _UINT32_(0x1)                                        /* (PWM_ELMR) A pulse is generated on the event line x when the comparison y match.  */
#define PWM_ELMR_CSEL7_0                      (PWM_ELMR_CSEL7_0_Val << PWM_ELMR_CSEL7_Pos)         /* (PWM_ELMR) A pulse is not generated on the event line x when the comparison y matches. Position  */
#define PWM_ELMR_CSEL7_1                      (PWM_ELMR_CSEL7_1_Val << PWM_ELMR_CSEL7_Pos)         /* (PWM_ELMR) A pulse is generated on the event line x when the comparison y match. Position  */
#define PWM_ELMR_Msk                          _UINT32_(0x000000FF)                                 /* (PWM_ELMR) Register Mask  */

#define PWM_ELMR_CSEL_Pos                     _UINT32_(0)                                          /* (PWM_ELMR Position) Comparison y Selection */
#define PWM_ELMR_CSEL_Msk                     (_UINT32_(0xFF) << PWM_ELMR_CSEL_Pos)                /* (PWM_ELMR Mask) CSEL */
#define PWM_ELMR_CSEL(value)                  (PWM_ELMR_CSEL_Msk & (_UINT32_(value) << PWM_ELMR_CSEL_Pos)) 

/* -------- PWM_SSPR : (PWM Offset: 0xA0) (R/W 32) PWM Spread Spectrum Register -------- */
#define PWM_SSPR_RESETVALUE                   _UINT32_(0x00)                                       /*  (PWM_SSPR) PWM Spread Spectrum Register  Reset Value */

#define PWM_SSPR_SPRD_Pos                     _UINT32_(0)                                          /* (PWM_SSPR) Spread Spectrum Limit Value Position */
#define PWM_SSPR_SPRD_Msk                     (_UINT32_(0xFFFFFF) << PWM_SSPR_SPRD_Pos)            /* (PWM_SSPR) Spread Spectrum Limit Value Mask */
#define PWM_SSPR_SPRD(value)                  (PWM_SSPR_SPRD_Msk & (_UINT32_(value) << PWM_SSPR_SPRD_Pos)) /* Assigment of value for SPRD in the PWM_SSPR register */
#define PWM_SSPR_SPRDM_Pos                    _UINT32_(24)                                         /* (PWM_SSPR) Spread Spectrum Counter Mode Position */
#define PWM_SSPR_SPRDM_Msk                    (_UINT32_(0x1) << PWM_SSPR_SPRDM_Pos)                /* (PWM_SSPR) Spread Spectrum Counter Mode Mask */
#define PWM_SSPR_SPRDM(value)                 (PWM_SSPR_SPRDM_Msk & (_UINT32_(value) << PWM_SSPR_SPRDM_Pos)) /* Assigment of value for SPRDM in the PWM_SSPR register */
#define   PWM_SSPR_SPRDM_0_Val                _UINT32_(0x0)                                        /* (PWM_SSPR) Triangular mode. The spread spectrum counter starts to count from -SPRD when the channel 0 is enabled and counts upwards at each PWM period. When it reaches +SPRD, it restarts to count from -SPRD again.  */
#define   PWM_SSPR_SPRDM_1_Val                _UINT32_(0x1)                                        /* (PWM_SSPR) Random mode. The spread spectrum counter is loaded with a new random value at each PWM period. This random value is uniformly distributed and is between -SPRD and +SPRD.  */
#define PWM_SSPR_SPRDM_0                      (PWM_SSPR_SPRDM_0_Val << PWM_SSPR_SPRDM_Pos)         /* (PWM_SSPR) Triangular mode. The spread spectrum counter starts to count from -SPRD when the channel 0 is enabled and counts upwards at each PWM period. When it reaches +SPRD, it restarts to count from -SPRD again. Position  */
#define PWM_SSPR_SPRDM_1                      (PWM_SSPR_SPRDM_1_Val << PWM_SSPR_SPRDM_Pos)         /* (PWM_SSPR) Random mode. The spread spectrum counter is loaded with a new random value at each PWM period. This random value is uniformly distributed and is between -SPRD and +SPRD. Position  */
#define PWM_SSPR_Msk                          _UINT32_(0x01FFFFFF)                                 /* (PWM_SSPR) Register Mask  */


/* -------- PWM_SSPUP : (PWM Offset: 0xA4) ( /W 32) PWM Spread Spectrum Update Register -------- */
#define PWM_SSPUP_SPRDUP_Pos                  _UINT32_(0)                                          /* (PWM_SSPUP) Spread Spectrum Limit Value Update Position */
#define PWM_SSPUP_SPRDUP_Msk                  (_UINT32_(0xFFFFFF) << PWM_SSPUP_SPRDUP_Pos)         /* (PWM_SSPUP) Spread Spectrum Limit Value Update Mask */
#define PWM_SSPUP_SPRDUP(value)               (PWM_SSPUP_SPRDUP_Msk & (_UINT32_(value) << PWM_SSPUP_SPRDUP_Pos)) /* Assigment of value for SPRDUP in the PWM_SSPUP register */
#define PWM_SSPUP_Msk                         _UINT32_(0x00FFFFFF)                                 /* (PWM_SSPUP) Register Mask  */


/* -------- PWM_SMMR : (PWM Offset: 0xB0) (R/W 32) PWM Stepper Motor Mode Register -------- */
#define PWM_SMMR_RESETVALUE                   _UINT32_(0x00)                                       /*  (PWM_SMMR) PWM Stepper Motor Mode Register  Reset Value */

#define PWM_SMMR_GCEN0_Pos                    _UINT32_(0)                                          /* (PWM_SMMR) Gray Count Enable Position */
#define PWM_SMMR_GCEN0_Msk                    (_UINT32_(0x1) << PWM_SMMR_GCEN0_Pos)                /* (PWM_SMMR) Gray Count Enable Mask */
#define PWM_SMMR_GCEN0(value)                 (PWM_SMMR_GCEN0_Msk & (_UINT32_(value) << PWM_SMMR_GCEN0_Pos)) /* Assigment of value for GCEN0 in the PWM_SMMR register */
#define   PWM_SMMR_GCEN0_0_Val                _UINT32_(0x0)                                        /* (PWM_SMMR) Disable Gray count generation on PWML[2*x], PWMH[2*x], PWML[2*x +1], PWMH[2*x +1]  */
#define   PWM_SMMR_GCEN0_1_Val                _UINT32_(0x1)                                        /* (PWM_SMMR) Enable Gray count generation on PWML[2*x], PWMH[2*x], PWML[2*x +1], PWMH[2*x +1].  */
#define PWM_SMMR_GCEN0_0                      (PWM_SMMR_GCEN0_0_Val << PWM_SMMR_GCEN0_Pos)         /* (PWM_SMMR) Disable Gray count generation on PWML[2*x], PWMH[2*x], PWML[2*x +1], PWMH[2*x +1] Position  */
#define PWM_SMMR_GCEN0_1                      (PWM_SMMR_GCEN0_1_Val << PWM_SMMR_GCEN0_Pos)         /* (PWM_SMMR) Enable Gray count generation on PWML[2*x], PWMH[2*x], PWML[2*x +1], PWMH[2*x +1]. Position  */
#define PWM_SMMR_GCEN1_Pos                    _UINT32_(1)                                          /* (PWM_SMMR) Gray Count Enable Position */
#define PWM_SMMR_GCEN1_Msk                    (_UINT32_(0x1) << PWM_SMMR_GCEN1_Pos)                /* (PWM_SMMR) Gray Count Enable Mask */
#define PWM_SMMR_GCEN1(value)                 (PWM_SMMR_GCEN1_Msk & (_UINT32_(value) << PWM_SMMR_GCEN1_Pos)) /* Assigment of value for GCEN1 in the PWM_SMMR register */
#define   PWM_SMMR_GCEN1_0_Val                _UINT32_(0x0)                                        /* (PWM_SMMR) Disable Gray count generation on PWML[2*x], PWMH[2*x], PWML[2*x +1], PWMH[2*x +1]  */
#define   PWM_SMMR_GCEN1_1_Val                _UINT32_(0x1)                                        /* (PWM_SMMR) Enable Gray count generation on PWML[2*x], PWMH[2*x], PWML[2*x +1], PWMH[2*x +1].  */
#define PWM_SMMR_GCEN1_0                      (PWM_SMMR_GCEN1_0_Val << PWM_SMMR_GCEN1_Pos)         /* (PWM_SMMR) Disable Gray count generation on PWML[2*x], PWMH[2*x], PWML[2*x +1], PWMH[2*x +1] Position  */
#define PWM_SMMR_GCEN1_1                      (PWM_SMMR_GCEN1_1_Val << PWM_SMMR_GCEN1_Pos)         /* (PWM_SMMR) Enable Gray count generation on PWML[2*x], PWMH[2*x], PWML[2*x +1], PWMH[2*x +1]. Position  */
#define PWM_SMMR_DOWN0_Pos                    _UINT32_(16)                                         /* (PWM_SMMR) Down Count Position */
#define PWM_SMMR_DOWN0_Msk                    (_UINT32_(0x1) << PWM_SMMR_DOWN0_Pos)                /* (PWM_SMMR) Down Count Mask */
#define PWM_SMMR_DOWN0(value)                 (PWM_SMMR_DOWN0_Msk & (_UINT32_(value) << PWM_SMMR_DOWN0_Pos)) /* Assigment of value for DOWN0 in the PWM_SMMR register */
#define   PWM_SMMR_DOWN0_0_Val                _UINT32_(0x0)                                        /* (PWM_SMMR) Up counter.  */
#define   PWM_SMMR_DOWN0_1_Val                _UINT32_(0x1)                                        /* (PWM_SMMR) Down counter.  */
#define PWM_SMMR_DOWN0_0                      (PWM_SMMR_DOWN0_0_Val << PWM_SMMR_DOWN0_Pos)         /* (PWM_SMMR) Up counter. Position  */
#define PWM_SMMR_DOWN0_1                      (PWM_SMMR_DOWN0_1_Val << PWM_SMMR_DOWN0_Pos)         /* (PWM_SMMR) Down counter. Position  */
#define PWM_SMMR_DOWN1_Pos                    _UINT32_(17)                                         /* (PWM_SMMR) Down Count Position */
#define PWM_SMMR_DOWN1_Msk                    (_UINT32_(0x1) << PWM_SMMR_DOWN1_Pos)                /* (PWM_SMMR) Down Count Mask */
#define PWM_SMMR_DOWN1(value)                 (PWM_SMMR_DOWN1_Msk & (_UINT32_(value) << PWM_SMMR_DOWN1_Pos)) /* Assigment of value for DOWN1 in the PWM_SMMR register */
#define   PWM_SMMR_DOWN1_0_Val                _UINT32_(0x0)                                        /* (PWM_SMMR) Up counter.  */
#define   PWM_SMMR_DOWN1_1_Val                _UINT32_(0x1)                                        /* (PWM_SMMR) Down counter.  */
#define PWM_SMMR_DOWN1_0                      (PWM_SMMR_DOWN1_0_Val << PWM_SMMR_DOWN1_Pos)         /* (PWM_SMMR) Up counter. Position  */
#define PWM_SMMR_DOWN1_1                      (PWM_SMMR_DOWN1_1_Val << PWM_SMMR_DOWN1_Pos)         /* (PWM_SMMR) Down counter. Position  */
#define PWM_SMMR_Msk                          _UINT32_(0x00030003)                                 /* (PWM_SMMR) Register Mask  */

#define PWM_SMMR_GCEN_Pos                     _UINT32_(0)                                          /* (PWM_SMMR Position) Gray Count Enable */
#define PWM_SMMR_GCEN_Msk                     (_UINT32_(0x3) << PWM_SMMR_GCEN_Pos)                 /* (PWM_SMMR Mask) GCEN */
#define PWM_SMMR_GCEN(value)                  (PWM_SMMR_GCEN_Msk & (_UINT32_(value) << PWM_SMMR_GCEN_Pos)) 
#define PWM_SMMR_DOWN_Pos                     _UINT32_(16)                                         /* (PWM_SMMR Position) Down Count */
#define PWM_SMMR_DOWN_Msk                     (_UINT32_(0x3) << PWM_SMMR_DOWN_Pos)                 /* (PWM_SMMR Mask) DOWN */
#define PWM_SMMR_DOWN(value)                  (PWM_SMMR_DOWN_Msk & (_UINT32_(value) << PWM_SMMR_DOWN_Pos)) 

/* -------- PWM_FPV2 : (PWM Offset: 0xC0) (R/W 32) PWM Fault Protection Value 2 Register -------- */
#define PWM_FPV2_RESETVALUE                   _UINT32_(0x3F003F)                                   /*  (PWM_FPV2) PWM Fault Protection Value 2 Register  Reset Value */

#define PWM_FPV2_FPZH0_Pos                    _UINT32_(0)                                          /* (PWM_FPV2) Fault Protection to Hi-Z for PWMH output on channel 0 Position */
#define PWM_FPV2_FPZH0_Msk                    (_UINT32_(0x1) << PWM_FPV2_FPZH0_Pos)                /* (PWM_FPV2) Fault Protection to Hi-Z for PWMH output on channel 0 Mask */
#define PWM_FPV2_FPZH0(value)                 (PWM_FPV2_FPZH0_Msk & (_UINT32_(value) << PWM_FPV2_FPZH0_Pos)) /* Assigment of value for FPZH0 in the PWM_FPV2 register */
#define   PWM_FPV2_FPZH0_0_Val                _UINT32_(0x0)                                        /* (PWM_FPV2) When fault occurs, PWMH output of channel x is forced to value defined by the bit FPVHx in PWM Fault Protection Value Register 1.  */
#define   PWM_FPV2_FPZH0_1_Val                _UINT32_(0x1)                                        /* (PWM_FPV2) When fault occurs, PWMH output of channel x is forced to high-impedance state.  */
#define PWM_FPV2_FPZH0_0                      (PWM_FPV2_FPZH0_0_Val << PWM_FPV2_FPZH0_Pos)         /* (PWM_FPV2) When fault occurs, PWMH output of channel x is forced to value defined by the bit FPVHx in PWM Fault Protection Value Register 1. Position  */
#define PWM_FPV2_FPZH0_1                      (PWM_FPV2_FPZH0_1_Val << PWM_FPV2_FPZH0_Pos)         /* (PWM_FPV2) When fault occurs, PWMH output of channel x is forced to high-impedance state. Position  */
#define PWM_FPV2_FPZH1_Pos                    _UINT32_(1)                                          /* (PWM_FPV2) Fault Protection to Hi-Z for PWMH output on channel 1 Position */
#define PWM_FPV2_FPZH1_Msk                    (_UINT32_(0x1) << PWM_FPV2_FPZH1_Pos)                /* (PWM_FPV2) Fault Protection to Hi-Z for PWMH output on channel 1 Mask */
#define PWM_FPV2_FPZH1(value)                 (PWM_FPV2_FPZH1_Msk & (_UINT32_(value) << PWM_FPV2_FPZH1_Pos)) /* Assigment of value for FPZH1 in the PWM_FPV2 register */
#define   PWM_FPV2_FPZH1_0_Val                _UINT32_(0x0)                                        /* (PWM_FPV2) When fault occurs, PWMH output of channel x is forced to value defined by the bit FPVHx in PWM Fault Protection Value Register 1.  */
#define   PWM_FPV2_FPZH1_1_Val                _UINT32_(0x1)                                        /* (PWM_FPV2) When fault occurs, PWMH output of channel x is forced to high-impedance state.  */
#define PWM_FPV2_FPZH1_0                      (PWM_FPV2_FPZH1_0_Val << PWM_FPV2_FPZH1_Pos)         /* (PWM_FPV2) When fault occurs, PWMH output of channel x is forced to value defined by the bit FPVHx in PWM Fault Protection Value Register 1. Position  */
#define PWM_FPV2_FPZH1_1                      (PWM_FPV2_FPZH1_1_Val << PWM_FPV2_FPZH1_Pos)         /* (PWM_FPV2) When fault occurs, PWMH output of channel x is forced to high-impedance state. Position  */
#define PWM_FPV2_FPZH2_Pos                    _UINT32_(2)                                          /* (PWM_FPV2) Fault Protection to Hi-Z for PWMH output on channel 2 Position */
#define PWM_FPV2_FPZH2_Msk                    (_UINT32_(0x1) << PWM_FPV2_FPZH2_Pos)                /* (PWM_FPV2) Fault Protection to Hi-Z for PWMH output on channel 2 Mask */
#define PWM_FPV2_FPZH2(value)                 (PWM_FPV2_FPZH2_Msk & (_UINT32_(value) << PWM_FPV2_FPZH2_Pos)) /* Assigment of value for FPZH2 in the PWM_FPV2 register */
#define   PWM_FPV2_FPZH2_0_Val                _UINT32_(0x0)                                        /* (PWM_FPV2) When fault occurs, PWMH output of channel x is forced to value defined by the bit FPVHx in PWM Fault Protection Value Register 1.  */
#define   PWM_FPV2_FPZH2_1_Val                _UINT32_(0x1)                                        /* (PWM_FPV2) When fault occurs, PWMH output of channel x is forced to high-impedance state.  */
#define PWM_FPV2_FPZH2_0                      (PWM_FPV2_FPZH2_0_Val << PWM_FPV2_FPZH2_Pos)         /* (PWM_FPV2) When fault occurs, PWMH output of channel x is forced to value defined by the bit FPVHx in PWM Fault Protection Value Register 1. Position  */
#define PWM_FPV2_FPZH2_1                      (PWM_FPV2_FPZH2_1_Val << PWM_FPV2_FPZH2_Pos)         /* (PWM_FPV2) When fault occurs, PWMH output of channel x is forced to high-impedance state. Position  */
#define PWM_FPV2_FPZH3_Pos                    _UINT32_(3)                                          /* (PWM_FPV2) Fault Protection to Hi-Z for PWMH output on channel 3 Position */
#define PWM_FPV2_FPZH3_Msk                    (_UINT32_(0x1) << PWM_FPV2_FPZH3_Pos)                /* (PWM_FPV2) Fault Protection to Hi-Z for PWMH output on channel 3 Mask */
#define PWM_FPV2_FPZH3(value)                 (PWM_FPV2_FPZH3_Msk & (_UINT32_(value) << PWM_FPV2_FPZH3_Pos)) /* Assigment of value for FPZH3 in the PWM_FPV2 register */
#define   PWM_FPV2_FPZH3_0_Val                _UINT32_(0x0)                                        /* (PWM_FPV2) When fault occurs, PWMH output of channel x is forced to value defined by the bit FPVHx in PWM Fault Protection Value Register 1.  */
#define   PWM_FPV2_FPZH3_1_Val                _UINT32_(0x1)                                        /* (PWM_FPV2) When fault occurs, PWMH output of channel x is forced to high-impedance state.  */
#define PWM_FPV2_FPZH3_0                      (PWM_FPV2_FPZH3_0_Val << PWM_FPV2_FPZH3_Pos)         /* (PWM_FPV2) When fault occurs, PWMH output of channel x is forced to value defined by the bit FPVHx in PWM Fault Protection Value Register 1. Position  */
#define PWM_FPV2_FPZH3_1                      (PWM_FPV2_FPZH3_1_Val << PWM_FPV2_FPZH3_Pos)         /* (PWM_FPV2) When fault occurs, PWMH output of channel x is forced to high-impedance state. Position  */
#define PWM_FPV2_FPZL0_Pos                    _UINT32_(16)                                         /* (PWM_FPV2) Fault Protection to Hi-Z for PWML output on channel 0 Position */
#define PWM_FPV2_FPZL0_Msk                    (_UINT32_(0x1) << PWM_FPV2_FPZL0_Pos)                /* (PWM_FPV2) Fault Protection to Hi-Z for PWML output on channel 0 Mask */
#define PWM_FPV2_FPZL0(value)                 (PWM_FPV2_FPZL0_Msk & (_UINT32_(value) << PWM_FPV2_FPZL0_Pos)) /* Assigment of value for FPZL0 in the PWM_FPV2 register */
#define   PWM_FPV2_FPZL0_0_Val                _UINT32_(0x0)                                        /* (PWM_FPV2) When fault occurs, PWML output of channel x is forced to value defined by the bit FPVLx in PWM Fault Protection Value Register 1.  */
#define   PWM_FPV2_FPZL0_1_Val                _UINT32_(0x1)                                        /* (PWM_FPV2) When fault occurs, PWML output of channel x is forced to high-impedance state.  */
#define PWM_FPV2_FPZL0_0                      (PWM_FPV2_FPZL0_0_Val << PWM_FPV2_FPZL0_Pos)         /* (PWM_FPV2) When fault occurs, PWML output of channel x is forced to value defined by the bit FPVLx in PWM Fault Protection Value Register 1. Position  */
#define PWM_FPV2_FPZL0_1                      (PWM_FPV2_FPZL0_1_Val << PWM_FPV2_FPZL0_Pos)         /* (PWM_FPV2) When fault occurs, PWML output of channel x is forced to high-impedance state. Position  */
#define PWM_FPV2_FPZL1_Pos                    _UINT32_(17)                                         /* (PWM_FPV2) Fault Protection to Hi-Z for PWML output on channel 1 Position */
#define PWM_FPV2_FPZL1_Msk                    (_UINT32_(0x1) << PWM_FPV2_FPZL1_Pos)                /* (PWM_FPV2) Fault Protection to Hi-Z for PWML output on channel 1 Mask */
#define PWM_FPV2_FPZL1(value)                 (PWM_FPV2_FPZL1_Msk & (_UINT32_(value) << PWM_FPV2_FPZL1_Pos)) /* Assigment of value for FPZL1 in the PWM_FPV2 register */
#define   PWM_FPV2_FPZL1_0_Val                _UINT32_(0x0)                                        /* (PWM_FPV2) When fault occurs, PWML output of channel x is forced to value defined by the bit FPVLx in PWM Fault Protection Value Register 1.  */
#define   PWM_FPV2_FPZL1_1_Val                _UINT32_(0x1)                                        /* (PWM_FPV2) When fault occurs, PWML output of channel x is forced to high-impedance state.  */
#define PWM_FPV2_FPZL1_0                      (PWM_FPV2_FPZL1_0_Val << PWM_FPV2_FPZL1_Pos)         /* (PWM_FPV2) When fault occurs, PWML output of channel x is forced to value defined by the bit FPVLx in PWM Fault Protection Value Register 1. Position  */
#define PWM_FPV2_FPZL1_1                      (PWM_FPV2_FPZL1_1_Val << PWM_FPV2_FPZL1_Pos)         /* (PWM_FPV2) When fault occurs, PWML output of channel x is forced to high-impedance state. Position  */
#define PWM_FPV2_FPZL2_Pos                    _UINT32_(18)                                         /* (PWM_FPV2) Fault Protection to Hi-Z for PWML output on channel 2 Position */
#define PWM_FPV2_FPZL2_Msk                    (_UINT32_(0x1) << PWM_FPV2_FPZL2_Pos)                /* (PWM_FPV2) Fault Protection to Hi-Z for PWML output on channel 2 Mask */
#define PWM_FPV2_FPZL2(value)                 (PWM_FPV2_FPZL2_Msk & (_UINT32_(value) << PWM_FPV2_FPZL2_Pos)) /* Assigment of value for FPZL2 in the PWM_FPV2 register */
#define   PWM_FPV2_FPZL2_0_Val                _UINT32_(0x0)                                        /* (PWM_FPV2) When fault occurs, PWML output of channel x is forced to value defined by the bit FPVLx in PWM Fault Protection Value Register 1.  */
#define   PWM_FPV2_FPZL2_1_Val                _UINT32_(0x1)                                        /* (PWM_FPV2) When fault occurs, PWML output of channel x is forced to high-impedance state.  */
#define PWM_FPV2_FPZL2_0                      (PWM_FPV2_FPZL2_0_Val << PWM_FPV2_FPZL2_Pos)         /* (PWM_FPV2) When fault occurs, PWML output of channel x is forced to value defined by the bit FPVLx in PWM Fault Protection Value Register 1. Position  */
#define PWM_FPV2_FPZL2_1                      (PWM_FPV2_FPZL2_1_Val << PWM_FPV2_FPZL2_Pos)         /* (PWM_FPV2) When fault occurs, PWML output of channel x is forced to high-impedance state. Position  */
#define PWM_FPV2_FPZL3_Pos                    _UINT32_(19)                                         /* (PWM_FPV2) Fault Protection to Hi-Z for PWML output on channel 3 Position */
#define PWM_FPV2_FPZL3_Msk                    (_UINT32_(0x1) << PWM_FPV2_FPZL3_Pos)                /* (PWM_FPV2) Fault Protection to Hi-Z for PWML output on channel 3 Mask */
#define PWM_FPV2_FPZL3(value)                 (PWM_FPV2_FPZL3_Msk & (_UINT32_(value) << PWM_FPV2_FPZL3_Pos)) /* Assigment of value for FPZL3 in the PWM_FPV2 register */
#define   PWM_FPV2_FPZL3_0_Val                _UINT32_(0x0)                                        /* (PWM_FPV2) When fault occurs, PWML output of channel x is forced to value defined by the bit FPVLx in PWM Fault Protection Value Register 1.  */
#define   PWM_FPV2_FPZL3_1_Val                _UINT32_(0x1)                                        /* (PWM_FPV2) When fault occurs, PWML output of channel x is forced to high-impedance state.  */
#define PWM_FPV2_FPZL3_0                      (PWM_FPV2_FPZL3_0_Val << PWM_FPV2_FPZL3_Pos)         /* (PWM_FPV2) When fault occurs, PWML output of channel x is forced to value defined by the bit FPVLx in PWM Fault Protection Value Register 1. Position  */
#define PWM_FPV2_FPZL3_1                      (PWM_FPV2_FPZL3_1_Val << PWM_FPV2_FPZL3_Pos)         /* (PWM_FPV2) When fault occurs, PWML output of channel x is forced to high-impedance state. Position  */
#define PWM_FPV2_Msk                          _UINT32_(0x000F000F)                                 /* (PWM_FPV2) Register Mask  */

#define PWM_FPV2_FPZH_Pos                     _UINT32_(0)                                          /* (PWM_FPV2 Position) Fault Protection to Hi-Z for PWMH output on channel x */
#define PWM_FPV2_FPZH_Msk                     (_UINT32_(0xF) << PWM_FPV2_FPZH_Pos)                 /* (PWM_FPV2 Mask) FPZH */
#define PWM_FPV2_FPZH(value)                  (PWM_FPV2_FPZH_Msk & (_UINT32_(value) << PWM_FPV2_FPZH_Pos)) 
#define PWM_FPV2_FPZL_Pos                     _UINT32_(16)                                         /* (PWM_FPV2 Position) Fault Protection to Hi-Z for PWML output on channel 3 */
#define PWM_FPV2_FPZL_Msk                     (_UINT32_(0xF) << PWM_FPV2_FPZL_Pos)                 /* (PWM_FPV2 Mask) FPZL */
#define PWM_FPV2_FPZL(value)                  (PWM_FPV2_FPZL_Msk & (_UINT32_(value) << PWM_FPV2_FPZL_Pos)) 

/* -------- PWM_WPCR : (PWM Offset: 0xE4) ( /W 32) PWM Write Protection Control Register -------- */
#define PWM_WPCR_WPCMD_Pos                    _UINT32_(0)                                          /* (PWM_WPCR) Write Protection Command Position */
#define PWM_WPCR_WPCMD_Msk                    (_UINT32_(0x3) << PWM_WPCR_WPCMD_Pos)                /* (PWM_WPCR) Write Protection Command Mask */
#define PWM_WPCR_WPCMD(value)                 (PWM_WPCR_WPCMD_Msk & (_UINT32_(value) << PWM_WPCR_WPCMD_Pos)) /* Assigment of value for WPCMD in the PWM_WPCR register */
#define   PWM_WPCR_WPCMD_DISABLE_SW_PROT_Val  _UINT32_(0x0)                                        /* (PWM_WPCR) Disables the software write protection of the register groups of which the bit WPRGx is at '1'.  */
#define   PWM_WPCR_WPCMD_ENABLE_SW_PROT_Val   _UINT32_(0x1)                                        /* (PWM_WPCR) Enables the software write protection of the register groups of which the bit WPRGx is at '1'.  */
#define   PWM_WPCR_WPCMD_ENABLE_HW_PROT_Val   _UINT32_(0x2)                                        /* (PWM_WPCR) Enables the hardware write protection of the register groups of which the bit WPRGx is at '1'. Only a hardware reset of the PWM controller can disable the hardware write protection. Moreover, to meet security requirements, the PIO lines associated with the PWM can not be configured through the PIO interface.  */
#define PWM_WPCR_WPCMD_DISABLE_SW_PROT        (PWM_WPCR_WPCMD_DISABLE_SW_PROT_Val << PWM_WPCR_WPCMD_Pos) /* (PWM_WPCR) Disables the software write protection of the register groups of which the bit WPRGx is at '1'. Position  */
#define PWM_WPCR_WPCMD_ENABLE_SW_PROT         (PWM_WPCR_WPCMD_ENABLE_SW_PROT_Val << PWM_WPCR_WPCMD_Pos) /* (PWM_WPCR) Enables the software write protection of the register groups of which the bit WPRGx is at '1'. Position  */
#define PWM_WPCR_WPCMD_ENABLE_HW_PROT         (PWM_WPCR_WPCMD_ENABLE_HW_PROT_Val << PWM_WPCR_WPCMD_Pos) /* (PWM_WPCR) Enables the hardware write protection of the register groups of which the bit WPRGx is at '1'. Only a hardware reset of the PWM controller can disable the hardware write protection. Moreover, to meet security requirements, the PIO lines associated with the PWM can not be configured through the PIO interface. Position  */
#define PWM_WPCR_WPRG0_Pos                    _UINT32_(2)                                          /* (PWM_WPCR) Write Protection Register Group 0 Position */
#define PWM_WPCR_WPRG0_Msk                    (_UINT32_(0x1) << PWM_WPCR_WPRG0_Pos)                /* (PWM_WPCR) Write Protection Register Group 0 Mask */
#define PWM_WPCR_WPRG0(value)                 (PWM_WPCR_WPRG0_Msk & (_UINT32_(value) << PWM_WPCR_WPRG0_Pos)) /* Assigment of value for WPRG0 in the PWM_WPCR register */
#define   PWM_WPCR_WPRG0_0_Val                _UINT32_(0x0)                                        /* (PWM_WPCR) The WPCMD command has no effect on the register group x.  */
#define   PWM_WPCR_WPRG0_1_Val                _UINT32_(0x1)                                        /* (PWM_WPCR) The WPCMD command is applied to the register group x.  */
#define PWM_WPCR_WPRG0_0                      (PWM_WPCR_WPRG0_0_Val << PWM_WPCR_WPRG0_Pos)         /* (PWM_WPCR) The WPCMD command has no effect on the register group x. Position  */
#define PWM_WPCR_WPRG0_1                      (PWM_WPCR_WPRG0_1_Val << PWM_WPCR_WPRG0_Pos)         /* (PWM_WPCR) The WPCMD command is applied to the register group x. Position  */
#define PWM_WPCR_WPRG1_Pos                    _UINT32_(3)                                          /* (PWM_WPCR) Write Protection Register Group 1 Position */
#define PWM_WPCR_WPRG1_Msk                    (_UINT32_(0x1) << PWM_WPCR_WPRG1_Pos)                /* (PWM_WPCR) Write Protection Register Group 1 Mask */
#define PWM_WPCR_WPRG1(value)                 (PWM_WPCR_WPRG1_Msk & (_UINT32_(value) << PWM_WPCR_WPRG1_Pos)) /* Assigment of value for WPRG1 in the PWM_WPCR register */
#define   PWM_WPCR_WPRG1_0_Val                _UINT32_(0x0)                                        /* (PWM_WPCR) The WPCMD command has no effect on the register group x.  */
#define   PWM_WPCR_WPRG1_1_Val                _UINT32_(0x1)                                        /* (PWM_WPCR) The WPCMD command is applied to the register group x.  */
#define PWM_WPCR_WPRG1_0                      (PWM_WPCR_WPRG1_0_Val << PWM_WPCR_WPRG1_Pos)         /* (PWM_WPCR) The WPCMD command has no effect on the register group x. Position  */
#define PWM_WPCR_WPRG1_1                      (PWM_WPCR_WPRG1_1_Val << PWM_WPCR_WPRG1_Pos)         /* (PWM_WPCR) The WPCMD command is applied to the register group x. Position  */
#define PWM_WPCR_WPRG2_Pos                    _UINT32_(4)                                          /* (PWM_WPCR) Write Protection Register Group 2 Position */
#define PWM_WPCR_WPRG2_Msk                    (_UINT32_(0x1) << PWM_WPCR_WPRG2_Pos)                /* (PWM_WPCR) Write Protection Register Group 2 Mask */
#define PWM_WPCR_WPRG2(value)                 (PWM_WPCR_WPRG2_Msk & (_UINT32_(value) << PWM_WPCR_WPRG2_Pos)) /* Assigment of value for WPRG2 in the PWM_WPCR register */
#define   PWM_WPCR_WPRG2_0_Val                _UINT32_(0x0)                                        /* (PWM_WPCR) The WPCMD command has no effect on the register group x.  */
#define   PWM_WPCR_WPRG2_1_Val                _UINT32_(0x1)                                        /* (PWM_WPCR) The WPCMD command is applied to the register group x.  */
#define PWM_WPCR_WPRG2_0                      (PWM_WPCR_WPRG2_0_Val << PWM_WPCR_WPRG2_Pos)         /* (PWM_WPCR) The WPCMD command has no effect on the register group x. Position  */
#define PWM_WPCR_WPRG2_1                      (PWM_WPCR_WPRG2_1_Val << PWM_WPCR_WPRG2_Pos)         /* (PWM_WPCR) The WPCMD command is applied to the register group x. Position  */
#define PWM_WPCR_WPRG3_Pos                    _UINT32_(5)                                          /* (PWM_WPCR) Write Protection Register Group 3 Position */
#define PWM_WPCR_WPRG3_Msk                    (_UINT32_(0x1) << PWM_WPCR_WPRG3_Pos)                /* (PWM_WPCR) Write Protection Register Group 3 Mask */
#define PWM_WPCR_WPRG3(value)                 (PWM_WPCR_WPRG3_Msk & (_UINT32_(value) << PWM_WPCR_WPRG3_Pos)) /* Assigment of value for WPRG3 in the PWM_WPCR register */
#define   PWM_WPCR_WPRG3_0_Val                _UINT32_(0x0)                                        /* (PWM_WPCR) The WPCMD command has no effect on the register group x.  */
#define   PWM_WPCR_WPRG3_1_Val                _UINT32_(0x1)                                        /* (PWM_WPCR) The WPCMD command is applied to the register group x.  */
#define PWM_WPCR_WPRG3_0                      (PWM_WPCR_WPRG3_0_Val << PWM_WPCR_WPRG3_Pos)         /* (PWM_WPCR) The WPCMD command has no effect on the register group x. Position  */
#define PWM_WPCR_WPRG3_1                      (PWM_WPCR_WPRG3_1_Val << PWM_WPCR_WPRG3_Pos)         /* (PWM_WPCR) The WPCMD command is applied to the register group x. Position  */
#define PWM_WPCR_WPRG4_Pos                    _UINT32_(6)                                          /* (PWM_WPCR) Write Protection Register Group 4 Position */
#define PWM_WPCR_WPRG4_Msk                    (_UINT32_(0x1) << PWM_WPCR_WPRG4_Pos)                /* (PWM_WPCR) Write Protection Register Group 4 Mask */
#define PWM_WPCR_WPRG4(value)                 (PWM_WPCR_WPRG4_Msk & (_UINT32_(value) << PWM_WPCR_WPRG4_Pos)) /* Assigment of value for WPRG4 in the PWM_WPCR register */
#define   PWM_WPCR_WPRG4_0_Val                _UINT32_(0x0)                                        /* (PWM_WPCR) The WPCMD command has no effect on the register group x.  */
#define   PWM_WPCR_WPRG4_1_Val                _UINT32_(0x1)                                        /* (PWM_WPCR) The WPCMD command is applied to the register group x.  */
#define PWM_WPCR_WPRG4_0                      (PWM_WPCR_WPRG4_0_Val << PWM_WPCR_WPRG4_Pos)         /* (PWM_WPCR) The WPCMD command has no effect on the register group x. Position  */
#define PWM_WPCR_WPRG4_1                      (PWM_WPCR_WPRG4_1_Val << PWM_WPCR_WPRG4_Pos)         /* (PWM_WPCR) The WPCMD command is applied to the register group x. Position  */
#define PWM_WPCR_WPRG5_Pos                    _UINT32_(7)                                          /* (PWM_WPCR) Write Protection Register Group 5 Position */
#define PWM_WPCR_WPRG5_Msk                    (_UINT32_(0x1) << PWM_WPCR_WPRG5_Pos)                /* (PWM_WPCR) Write Protection Register Group 5 Mask */
#define PWM_WPCR_WPRG5(value)                 (PWM_WPCR_WPRG5_Msk & (_UINT32_(value) << PWM_WPCR_WPRG5_Pos)) /* Assigment of value for WPRG5 in the PWM_WPCR register */
#define   PWM_WPCR_WPRG5_0_Val                _UINT32_(0x0)                                        /* (PWM_WPCR) The WPCMD command has no effect on the register group x.  */
#define   PWM_WPCR_WPRG5_1_Val                _UINT32_(0x1)                                        /* (PWM_WPCR) The WPCMD command is applied to the register group x.  */
#define PWM_WPCR_WPRG5_0                      (PWM_WPCR_WPRG5_0_Val << PWM_WPCR_WPRG5_Pos)         /* (PWM_WPCR) The WPCMD command has no effect on the register group x. Position  */
#define PWM_WPCR_WPRG5_1                      (PWM_WPCR_WPRG5_1_Val << PWM_WPCR_WPRG5_Pos)         /* (PWM_WPCR) The WPCMD command is applied to the register group x. Position  */
#define PWM_WPCR_WPKEY_Pos                    _UINT32_(8)                                          /* (PWM_WPCR) Write Protection Key Position */
#define PWM_WPCR_WPKEY_Msk                    (_UINT32_(0xFFFFFF) << PWM_WPCR_WPKEY_Pos)           /* (PWM_WPCR) Write Protection Key Mask */
#define PWM_WPCR_WPKEY(value)                 (PWM_WPCR_WPKEY_Msk & (_UINT32_(value) << PWM_WPCR_WPKEY_Pos)) /* Assigment of value for WPKEY in the PWM_WPCR register */
#define   PWM_WPCR_WPKEY_PASSWD_Val           _UINT32_(0x50574D)                                   /* (PWM_WPCR) Writing any other value in this field aborts the write operation of the WPCMD field. Always reads as 0  */
#define PWM_WPCR_WPKEY_PASSWD                 (PWM_WPCR_WPKEY_PASSWD_Val << PWM_WPCR_WPKEY_Pos)    /* (PWM_WPCR) Writing any other value in this field aborts the write operation of the WPCMD field. Always reads as 0 Position  */
#define PWM_WPCR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (PWM_WPCR) Register Mask  */

#define PWM_WPCR_WPRG_Pos                     _UINT32_(2)                                          /* (PWM_WPCR Position) Write Protection Register Group x */
#define PWM_WPCR_WPRG_Msk                     (_UINT32_(0x3F) << PWM_WPCR_WPRG_Pos)                /* (PWM_WPCR Mask) WPRG */
#define PWM_WPCR_WPRG(value)                  (PWM_WPCR_WPRG_Msk & (_UINT32_(value) << PWM_WPCR_WPRG_Pos)) 

/* -------- PWM_WPSR : (PWM Offset: 0xE8) ( R/ 32) PWM Write Protection Status Register -------- */
#define PWM_WPSR_RESETVALUE                   _UINT32_(0x00)                                       /*  (PWM_WPSR) PWM Write Protection Status Register  Reset Value */

#define PWM_WPSR_WPSWS0_Pos                   _UINT32_(0)                                          /* (PWM_WPSR) Write Protect SW Status Position */
#define PWM_WPSR_WPSWS0_Msk                   (_UINT32_(0x1) << PWM_WPSR_WPSWS0_Pos)               /* (PWM_WPSR) Write Protect SW Status Mask */
#define PWM_WPSR_WPSWS0(value)                (PWM_WPSR_WPSWS0_Msk & (_UINT32_(value) << PWM_WPSR_WPSWS0_Pos)) /* Assigment of value for WPSWS0 in the PWM_WPSR register */
#define   PWM_WPSR_WPSWS0_0_Val               _UINT32_(0x0)                                        /* (PWM_WPSR) The SW write protection x of the register group x is disabled.  */
#define   PWM_WPSR_WPSWS0_1_Val               _UINT32_(0x1)                                        /* (PWM_WPSR) The SW write protection x of the register group x is enabled.  */
#define PWM_WPSR_WPSWS0_0                     (PWM_WPSR_WPSWS0_0_Val << PWM_WPSR_WPSWS0_Pos)       /* (PWM_WPSR) The SW write protection x of the register group x is disabled. Position  */
#define PWM_WPSR_WPSWS0_1                     (PWM_WPSR_WPSWS0_1_Val << PWM_WPSR_WPSWS0_Pos)       /* (PWM_WPSR) The SW write protection x of the register group x is enabled. Position  */
#define PWM_WPSR_WPSWS1_Pos                   _UINT32_(1)                                          /* (PWM_WPSR) Write Protect SW Status Position */
#define PWM_WPSR_WPSWS1_Msk                   (_UINT32_(0x1) << PWM_WPSR_WPSWS1_Pos)               /* (PWM_WPSR) Write Protect SW Status Mask */
#define PWM_WPSR_WPSWS1(value)                (PWM_WPSR_WPSWS1_Msk & (_UINT32_(value) << PWM_WPSR_WPSWS1_Pos)) /* Assigment of value for WPSWS1 in the PWM_WPSR register */
#define   PWM_WPSR_WPSWS1_0_Val               _UINT32_(0x0)                                        /* (PWM_WPSR) The SW write protection x of the register group x is disabled.  */
#define   PWM_WPSR_WPSWS1_1_Val               _UINT32_(0x1)                                        /* (PWM_WPSR) The SW write protection x of the register group x is enabled.  */
#define PWM_WPSR_WPSWS1_0                     (PWM_WPSR_WPSWS1_0_Val << PWM_WPSR_WPSWS1_Pos)       /* (PWM_WPSR) The SW write protection x of the register group x is disabled. Position  */
#define PWM_WPSR_WPSWS1_1                     (PWM_WPSR_WPSWS1_1_Val << PWM_WPSR_WPSWS1_Pos)       /* (PWM_WPSR) The SW write protection x of the register group x is enabled. Position  */
#define PWM_WPSR_WPSWS2_Pos                   _UINT32_(2)                                          /* (PWM_WPSR) Write Protect SW Status Position */
#define PWM_WPSR_WPSWS2_Msk                   (_UINT32_(0x1) << PWM_WPSR_WPSWS2_Pos)               /* (PWM_WPSR) Write Protect SW Status Mask */
#define PWM_WPSR_WPSWS2(value)                (PWM_WPSR_WPSWS2_Msk & (_UINT32_(value) << PWM_WPSR_WPSWS2_Pos)) /* Assigment of value for WPSWS2 in the PWM_WPSR register */
#define   PWM_WPSR_WPSWS2_0_Val               _UINT32_(0x0)                                        /* (PWM_WPSR) The SW write protection x of the register group x is disabled.  */
#define   PWM_WPSR_WPSWS2_1_Val               _UINT32_(0x1)                                        /* (PWM_WPSR) The SW write protection x of the register group x is enabled.  */
#define PWM_WPSR_WPSWS2_0                     (PWM_WPSR_WPSWS2_0_Val << PWM_WPSR_WPSWS2_Pos)       /* (PWM_WPSR) The SW write protection x of the register group x is disabled. Position  */
#define PWM_WPSR_WPSWS2_1                     (PWM_WPSR_WPSWS2_1_Val << PWM_WPSR_WPSWS2_Pos)       /* (PWM_WPSR) The SW write protection x of the register group x is enabled. Position  */
#define PWM_WPSR_WPSWS3_Pos                   _UINT32_(3)                                          /* (PWM_WPSR) Write Protect SW Status Position */
#define PWM_WPSR_WPSWS3_Msk                   (_UINT32_(0x1) << PWM_WPSR_WPSWS3_Pos)               /* (PWM_WPSR) Write Protect SW Status Mask */
#define PWM_WPSR_WPSWS3(value)                (PWM_WPSR_WPSWS3_Msk & (_UINT32_(value) << PWM_WPSR_WPSWS3_Pos)) /* Assigment of value for WPSWS3 in the PWM_WPSR register */
#define   PWM_WPSR_WPSWS3_0_Val               _UINT32_(0x0)                                        /* (PWM_WPSR) The SW write protection x of the register group x is disabled.  */
#define   PWM_WPSR_WPSWS3_1_Val               _UINT32_(0x1)                                        /* (PWM_WPSR) The SW write protection x of the register group x is enabled.  */
#define PWM_WPSR_WPSWS3_0                     (PWM_WPSR_WPSWS3_0_Val << PWM_WPSR_WPSWS3_Pos)       /* (PWM_WPSR) The SW write protection x of the register group x is disabled. Position  */
#define PWM_WPSR_WPSWS3_1                     (PWM_WPSR_WPSWS3_1_Val << PWM_WPSR_WPSWS3_Pos)       /* (PWM_WPSR) The SW write protection x of the register group x is enabled. Position  */
#define PWM_WPSR_WPSWS4_Pos                   _UINT32_(4)                                          /* (PWM_WPSR) Write Protect SW Status Position */
#define PWM_WPSR_WPSWS4_Msk                   (_UINT32_(0x1) << PWM_WPSR_WPSWS4_Pos)               /* (PWM_WPSR) Write Protect SW Status Mask */
#define PWM_WPSR_WPSWS4(value)                (PWM_WPSR_WPSWS4_Msk & (_UINT32_(value) << PWM_WPSR_WPSWS4_Pos)) /* Assigment of value for WPSWS4 in the PWM_WPSR register */
#define   PWM_WPSR_WPSWS4_0_Val               _UINT32_(0x0)                                        /* (PWM_WPSR) The SW write protection x of the register group x is disabled.  */
#define   PWM_WPSR_WPSWS4_1_Val               _UINT32_(0x1)                                        /* (PWM_WPSR) The SW write protection x of the register group x is enabled.  */
#define PWM_WPSR_WPSWS4_0                     (PWM_WPSR_WPSWS4_0_Val << PWM_WPSR_WPSWS4_Pos)       /* (PWM_WPSR) The SW write protection x of the register group x is disabled. Position  */
#define PWM_WPSR_WPSWS4_1                     (PWM_WPSR_WPSWS4_1_Val << PWM_WPSR_WPSWS4_Pos)       /* (PWM_WPSR) The SW write protection x of the register group x is enabled. Position  */
#define PWM_WPSR_WPSWS5_Pos                   _UINT32_(5)                                          /* (PWM_WPSR) Write Protect SW Status Position */
#define PWM_WPSR_WPSWS5_Msk                   (_UINT32_(0x1) << PWM_WPSR_WPSWS5_Pos)               /* (PWM_WPSR) Write Protect SW Status Mask */
#define PWM_WPSR_WPSWS5(value)                (PWM_WPSR_WPSWS5_Msk & (_UINT32_(value) << PWM_WPSR_WPSWS5_Pos)) /* Assigment of value for WPSWS5 in the PWM_WPSR register */
#define   PWM_WPSR_WPSWS5_0_Val               _UINT32_(0x0)                                        /* (PWM_WPSR) The SW write protection x of the register group x is disabled.  */
#define   PWM_WPSR_WPSWS5_1_Val               _UINT32_(0x1)                                        /* (PWM_WPSR) The SW write protection x of the register group x is enabled.  */
#define PWM_WPSR_WPSWS5_0                     (PWM_WPSR_WPSWS5_0_Val << PWM_WPSR_WPSWS5_Pos)       /* (PWM_WPSR) The SW write protection x of the register group x is disabled. Position  */
#define PWM_WPSR_WPSWS5_1                     (PWM_WPSR_WPSWS5_1_Val << PWM_WPSR_WPSWS5_Pos)       /* (PWM_WPSR) The SW write protection x of the register group x is enabled. Position  */
#define PWM_WPSR_WPVS_Pos                     _UINT32_(7)                                          /* (PWM_WPSR) Write Protect Violation Status Position */
#define PWM_WPSR_WPVS_Msk                     (_UINT32_(0x1) << PWM_WPSR_WPVS_Pos)                 /* (PWM_WPSR) Write Protect Violation Status Mask */
#define PWM_WPSR_WPVS(value)                  (PWM_WPSR_WPVS_Msk & (_UINT32_(value) << PWM_WPSR_WPVS_Pos)) /* Assigment of value for WPVS in the PWM_WPSR register */
#define   PWM_WPSR_WPVS_0_Val                 _UINT32_(0x0)                                        /* (PWM_WPSR) No write protection violation has occurred since the last read of PWM_WPSR.  */
#define   PWM_WPSR_WPVS_1_Val                 _UINT32_(0x1)                                        /* (PWM_WPSR) At least one write protection violation has occurred since the last read of PWM_WPSR. If this violation is an unauthorized attempt to write a protected register, the associated violation is reported into field WPVSRC.  */
#define PWM_WPSR_WPVS_0                       (PWM_WPSR_WPVS_0_Val << PWM_WPSR_WPVS_Pos)           /* (PWM_WPSR) No write protection violation has occurred since the last read of PWM_WPSR. Position  */
#define PWM_WPSR_WPVS_1                       (PWM_WPSR_WPVS_1_Val << PWM_WPSR_WPVS_Pos)           /* (PWM_WPSR) At least one write protection violation has occurred since the last read of PWM_WPSR. If this violation is an unauthorized attempt to write a protected register, the associated violation is reported into field WPVSRC. Position  */
#define PWM_WPSR_WPHWS0_Pos                   _UINT32_(8)                                          /* (PWM_WPSR) Write Protect HW Status Position */
#define PWM_WPSR_WPHWS0_Msk                   (_UINT32_(0x1) << PWM_WPSR_WPHWS0_Pos)               /* (PWM_WPSR) Write Protect HW Status Mask */
#define PWM_WPSR_WPHWS0(value)                (PWM_WPSR_WPHWS0_Msk & (_UINT32_(value) << PWM_WPSR_WPHWS0_Pos)) /* Assigment of value for WPHWS0 in the PWM_WPSR register */
#define   PWM_WPSR_WPHWS0_0_Val               _UINT32_(0x0)                                        /* (PWM_WPSR) The HW write protection x of the register group x is disabled.  */
#define   PWM_WPSR_WPHWS0_1_Val               _UINT32_(0x1)                                        /* (PWM_WPSR) The HW write protection x of the register group x is enabled.  */
#define PWM_WPSR_WPHWS0_0                     (PWM_WPSR_WPHWS0_0_Val << PWM_WPSR_WPHWS0_Pos)       /* (PWM_WPSR) The HW write protection x of the register group x is disabled. Position  */
#define PWM_WPSR_WPHWS0_1                     (PWM_WPSR_WPHWS0_1_Val << PWM_WPSR_WPHWS0_Pos)       /* (PWM_WPSR) The HW write protection x of the register group x is enabled. Position  */
#define PWM_WPSR_WPHWS1_Pos                   _UINT32_(9)                                          /* (PWM_WPSR) Write Protect HW Status Position */
#define PWM_WPSR_WPHWS1_Msk                   (_UINT32_(0x1) << PWM_WPSR_WPHWS1_Pos)               /* (PWM_WPSR) Write Protect HW Status Mask */
#define PWM_WPSR_WPHWS1(value)                (PWM_WPSR_WPHWS1_Msk & (_UINT32_(value) << PWM_WPSR_WPHWS1_Pos)) /* Assigment of value for WPHWS1 in the PWM_WPSR register */
#define   PWM_WPSR_WPHWS1_0_Val               _UINT32_(0x0)                                        /* (PWM_WPSR) The HW write protection x of the register group x is disabled.  */
#define   PWM_WPSR_WPHWS1_1_Val               _UINT32_(0x1)                                        /* (PWM_WPSR) The HW write protection x of the register group x is enabled.  */
#define PWM_WPSR_WPHWS1_0                     (PWM_WPSR_WPHWS1_0_Val << PWM_WPSR_WPHWS1_Pos)       /* (PWM_WPSR) The HW write protection x of the register group x is disabled. Position  */
#define PWM_WPSR_WPHWS1_1                     (PWM_WPSR_WPHWS1_1_Val << PWM_WPSR_WPHWS1_Pos)       /* (PWM_WPSR) The HW write protection x of the register group x is enabled. Position  */
#define PWM_WPSR_WPHWS2_Pos                   _UINT32_(10)                                         /* (PWM_WPSR) Write Protect HW Status Position */
#define PWM_WPSR_WPHWS2_Msk                   (_UINT32_(0x1) << PWM_WPSR_WPHWS2_Pos)               /* (PWM_WPSR) Write Protect HW Status Mask */
#define PWM_WPSR_WPHWS2(value)                (PWM_WPSR_WPHWS2_Msk & (_UINT32_(value) << PWM_WPSR_WPHWS2_Pos)) /* Assigment of value for WPHWS2 in the PWM_WPSR register */
#define   PWM_WPSR_WPHWS2_0_Val               _UINT32_(0x0)                                        /* (PWM_WPSR) The HW write protection x of the register group x is disabled.  */
#define   PWM_WPSR_WPHWS2_1_Val               _UINT32_(0x1)                                        /* (PWM_WPSR) The HW write protection x of the register group x is enabled.  */
#define PWM_WPSR_WPHWS2_0                     (PWM_WPSR_WPHWS2_0_Val << PWM_WPSR_WPHWS2_Pos)       /* (PWM_WPSR) The HW write protection x of the register group x is disabled. Position  */
#define PWM_WPSR_WPHWS2_1                     (PWM_WPSR_WPHWS2_1_Val << PWM_WPSR_WPHWS2_Pos)       /* (PWM_WPSR) The HW write protection x of the register group x is enabled. Position  */
#define PWM_WPSR_WPHWS3_Pos                   _UINT32_(11)                                         /* (PWM_WPSR) Write Protect HW Status Position */
#define PWM_WPSR_WPHWS3_Msk                   (_UINT32_(0x1) << PWM_WPSR_WPHWS3_Pos)               /* (PWM_WPSR) Write Protect HW Status Mask */
#define PWM_WPSR_WPHWS3(value)                (PWM_WPSR_WPHWS3_Msk & (_UINT32_(value) << PWM_WPSR_WPHWS3_Pos)) /* Assigment of value for WPHWS3 in the PWM_WPSR register */
#define   PWM_WPSR_WPHWS3_0_Val               _UINT32_(0x0)                                        /* (PWM_WPSR) The HW write protection x of the register group x is disabled.  */
#define   PWM_WPSR_WPHWS3_1_Val               _UINT32_(0x1)                                        /* (PWM_WPSR) The HW write protection x of the register group x is enabled.  */
#define PWM_WPSR_WPHWS3_0                     (PWM_WPSR_WPHWS3_0_Val << PWM_WPSR_WPHWS3_Pos)       /* (PWM_WPSR) The HW write protection x of the register group x is disabled. Position  */
#define PWM_WPSR_WPHWS3_1                     (PWM_WPSR_WPHWS3_1_Val << PWM_WPSR_WPHWS3_Pos)       /* (PWM_WPSR) The HW write protection x of the register group x is enabled. Position  */
#define PWM_WPSR_WPHWS4_Pos                   _UINT32_(12)                                         /* (PWM_WPSR) Write Protect HW Status Position */
#define PWM_WPSR_WPHWS4_Msk                   (_UINT32_(0x1) << PWM_WPSR_WPHWS4_Pos)               /* (PWM_WPSR) Write Protect HW Status Mask */
#define PWM_WPSR_WPHWS4(value)                (PWM_WPSR_WPHWS4_Msk & (_UINT32_(value) << PWM_WPSR_WPHWS4_Pos)) /* Assigment of value for WPHWS4 in the PWM_WPSR register */
#define   PWM_WPSR_WPHWS4_0_Val               _UINT32_(0x0)                                        /* (PWM_WPSR) The HW write protection x of the register group x is disabled.  */
#define   PWM_WPSR_WPHWS4_1_Val               _UINT32_(0x1)                                        /* (PWM_WPSR) The HW write protection x of the register group x is enabled.  */
#define PWM_WPSR_WPHWS4_0                     (PWM_WPSR_WPHWS4_0_Val << PWM_WPSR_WPHWS4_Pos)       /* (PWM_WPSR) The HW write protection x of the register group x is disabled. Position  */
#define PWM_WPSR_WPHWS4_1                     (PWM_WPSR_WPHWS4_1_Val << PWM_WPSR_WPHWS4_Pos)       /* (PWM_WPSR) The HW write protection x of the register group x is enabled. Position  */
#define PWM_WPSR_WPHWS5_Pos                   _UINT32_(13)                                         /* (PWM_WPSR) Write Protect HW Status Position */
#define PWM_WPSR_WPHWS5_Msk                   (_UINT32_(0x1) << PWM_WPSR_WPHWS5_Pos)               /* (PWM_WPSR) Write Protect HW Status Mask */
#define PWM_WPSR_WPHWS5(value)                (PWM_WPSR_WPHWS5_Msk & (_UINT32_(value) << PWM_WPSR_WPHWS5_Pos)) /* Assigment of value for WPHWS5 in the PWM_WPSR register */
#define   PWM_WPSR_WPHWS5_0_Val               _UINT32_(0x0)                                        /* (PWM_WPSR) The HW write protection x of the register group x is disabled.  */
#define   PWM_WPSR_WPHWS5_1_Val               _UINT32_(0x1)                                        /* (PWM_WPSR) The HW write protection x of the register group x is enabled.  */
#define PWM_WPSR_WPHWS5_0                     (PWM_WPSR_WPHWS5_0_Val << PWM_WPSR_WPHWS5_Pos)       /* (PWM_WPSR) The HW write protection x of the register group x is disabled. Position  */
#define PWM_WPSR_WPHWS5_1                     (PWM_WPSR_WPHWS5_1_Val << PWM_WPSR_WPHWS5_Pos)       /* (PWM_WPSR) The HW write protection x of the register group x is enabled. Position  */
#define PWM_WPSR_WPVSRC_Pos                   _UINT32_(16)                                         /* (PWM_WPSR) Write Protect Violation Source Position */
#define PWM_WPSR_WPVSRC_Msk                   (_UINT32_(0xFFFF) << PWM_WPSR_WPVSRC_Pos)            /* (PWM_WPSR) Write Protect Violation Source Mask */
#define PWM_WPSR_WPVSRC(value)                (PWM_WPSR_WPVSRC_Msk & (_UINT32_(value) << PWM_WPSR_WPVSRC_Pos)) /* Assigment of value for WPVSRC in the PWM_WPSR register */
#define PWM_WPSR_Msk                          _UINT32_(0xFFFF3FBF)                                 /* (PWM_WPSR) Register Mask  */

#define PWM_WPSR_WPSWS_Pos                    _UINT32_(0)                                          /* (PWM_WPSR Position) Write Protect SW Status */
#define PWM_WPSR_WPSWS_Msk                    (_UINT32_(0x3F) << PWM_WPSR_WPSWS_Pos)               /* (PWM_WPSR Mask) WPSWS */
#define PWM_WPSR_WPSWS(value)                 (PWM_WPSR_WPSWS_Msk & (_UINT32_(value) << PWM_WPSR_WPSWS_Pos)) 
#define PWM_WPSR_WPHWS_Pos                    _UINT32_(8)                                          /* (PWM_WPSR Position) Write Protect HW Status */
#define PWM_WPSR_WPHWS_Msk                    (_UINT32_(0x3F) << PWM_WPSR_WPHWS_Pos)               /* (PWM_WPSR Mask) WPHWS */
#define PWM_WPSR_WPHWS(value)                 (PWM_WPSR_WPHWS_Msk & (_UINT32_(value) << PWM_WPSR_WPHWS_Pos)) 

/* -------- PWM_CMUPD0 : (PWM Offset: 0x400) ( /W 32) PWM Channel Mode Update Register (ch_num = 0) -------- */
#define PWM_CMUPD0_CPOLUP_Pos                 _UINT32_(9)                                          /* (PWM_CMUPD0) Channel Polarity Update Position */
#define PWM_CMUPD0_CPOLUP_Msk                 (_UINT32_(0x1) << PWM_CMUPD0_CPOLUP_Pos)             /* (PWM_CMUPD0) Channel Polarity Update Mask */
#define PWM_CMUPD0_CPOLUP(value)              (PWM_CMUPD0_CPOLUP_Msk & (_UINT32_(value) << PWM_CMUPD0_CPOLUP_Pos)) /* Assigment of value for CPOLUP in the PWM_CMUPD0 register */
#define   PWM_CMUPD0_CPOLUP_0_Val             _UINT32_(0x0)                                        /* (PWM_CMUPD0) The OCx output waveform (output from the comparator) starts at a low level.  */
#define   PWM_CMUPD0_CPOLUP_1_Val             _UINT32_(0x1)                                        /* (PWM_CMUPD0) The OCx output waveform (output from the comparator) starts at a high level.  */
#define PWM_CMUPD0_CPOLUP_0                   (PWM_CMUPD0_CPOLUP_0_Val << PWM_CMUPD0_CPOLUP_Pos)   /* (PWM_CMUPD0) The OCx output waveform (output from the comparator) starts at a low level. Position  */
#define PWM_CMUPD0_CPOLUP_1                   (PWM_CMUPD0_CPOLUP_1_Val << PWM_CMUPD0_CPOLUP_Pos)   /* (PWM_CMUPD0) The OCx output waveform (output from the comparator) starts at a high level. Position  */
#define PWM_CMUPD0_CPOLINVUP_Pos              _UINT32_(13)                                         /* (PWM_CMUPD0) Channel Polarity Inversion Update Position */
#define PWM_CMUPD0_CPOLINVUP_Msk              (_UINT32_(0x1) << PWM_CMUPD0_CPOLINVUP_Pos)          /* (PWM_CMUPD0) Channel Polarity Inversion Update Mask */
#define PWM_CMUPD0_CPOLINVUP(value)           (PWM_CMUPD0_CPOLINVUP_Msk & (_UINT32_(value) << PWM_CMUPD0_CPOLINVUP_Pos)) /* Assigment of value for CPOLINVUP in the PWM_CMUPD0 register */
#define   PWM_CMUPD0_CPOLINVUP_0_Val          _UINT32_(0x0)                                        /* (PWM_CMUPD0) No effect.  */
#define   PWM_CMUPD0_CPOLINVUP_1_Val          _UINT32_(0x1)                                        /* (PWM_CMUPD0) The OCx output waveform (output from the comparator) is inverted.  */
#define PWM_CMUPD0_CPOLINVUP_0                (PWM_CMUPD0_CPOLINVUP_0_Val << PWM_CMUPD0_CPOLINVUP_Pos) /* (PWM_CMUPD0) No effect. Position  */
#define PWM_CMUPD0_CPOLINVUP_1                (PWM_CMUPD0_CPOLINVUP_1_Val << PWM_CMUPD0_CPOLINVUP_Pos) /* (PWM_CMUPD0) The OCx output waveform (output from the comparator) is inverted. Position  */
#define PWM_CMUPD0_Msk                        _UINT32_(0x00002200)                                 /* (PWM_CMUPD0) Register Mask  */


/* -------- PWM_CMUPD1 : (PWM Offset: 0x420) ( /W 32) PWM Channel Mode Update Register (ch_num = 1) -------- */
#define PWM_CMUPD1_CPOLUP_Pos                 _UINT32_(9)                                          /* (PWM_CMUPD1) Channel Polarity Update Position */
#define PWM_CMUPD1_CPOLUP_Msk                 (_UINT32_(0x1) << PWM_CMUPD1_CPOLUP_Pos)             /* (PWM_CMUPD1) Channel Polarity Update Mask */
#define PWM_CMUPD1_CPOLUP(value)              (PWM_CMUPD1_CPOLUP_Msk & (_UINT32_(value) << PWM_CMUPD1_CPOLUP_Pos)) /* Assigment of value for CPOLUP in the PWM_CMUPD1 register */
#define   PWM_CMUPD1_CPOLUP_0_Val             _UINT32_(0x0)                                        /* (PWM_CMUPD1) The OCx output waveform (output from the comparator) starts at a low level.  */
#define   PWM_CMUPD1_CPOLUP_1_Val             _UINT32_(0x1)                                        /* (PWM_CMUPD1) The OCx output waveform (output from the comparator) starts at a high level.  */
#define PWM_CMUPD1_CPOLUP_0                   (PWM_CMUPD1_CPOLUP_0_Val << PWM_CMUPD1_CPOLUP_Pos)   /* (PWM_CMUPD1) The OCx output waveform (output from the comparator) starts at a low level. Position  */
#define PWM_CMUPD1_CPOLUP_1                   (PWM_CMUPD1_CPOLUP_1_Val << PWM_CMUPD1_CPOLUP_Pos)   /* (PWM_CMUPD1) The OCx output waveform (output from the comparator) starts at a high level. Position  */
#define PWM_CMUPD1_CPOLINVUP_Pos              _UINT32_(13)                                         /* (PWM_CMUPD1) Channel Polarity Inversion Update Position */
#define PWM_CMUPD1_CPOLINVUP_Msk              (_UINT32_(0x1) << PWM_CMUPD1_CPOLINVUP_Pos)          /* (PWM_CMUPD1) Channel Polarity Inversion Update Mask */
#define PWM_CMUPD1_CPOLINVUP(value)           (PWM_CMUPD1_CPOLINVUP_Msk & (_UINT32_(value) << PWM_CMUPD1_CPOLINVUP_Pos)) /* Assigment of value for CPOLINVUP in the PWM_CMUPD1 register */
#define   PWM_CMUPD1_CPOLINVUP_0_Val          _UINT32_(0x0)                                        /* (PWM_CMUPD1) No effect.  */
#define   PWM_CMUPD1_CPOLINVUP_1_Val          _UINT32_(0x1)                                        /* (PWM_CMUPD1) The OCx output waveform (output from the comparator) is inverted.  */
#define PWM_CMUPD1_CPOLINVUP_0                (PWM_CMUPD1_CPOLINVUP_0_Val << PWM_CMUPD1_CPOLINVUP_Pos) /* (PWM_CMUPD1) No effect. Position  */
#define PWM_CMUPD1_CPOLINVUP_1                (PWM_CMUPD1_CPOLINVUP_1_Val << PWM_CMUPD1_CPOLINVUP_Pos) /* (PWM_CMUPD1) The OCx output waveform (output from the comparator) is inverted. Position  */
#define PWM_CMUPD1_Msk                        _UINT32_(0x00002200)                                 /* (PWM_CMUPD1) Register Mask  */


/* -------- PWM_ETRG1 : (PWM Offset: 0x42C) (R/W 32) PWM External Trigger Register 1 -------- */
#define PWM_ETRG1_MAXCNT_Pos                  _UINT32_(0)                                          /* (PWM_ETRG1) Maximum Counter value Position */
#define PWM_ETRG1_MAXCNT_Msk                  (_UINT32_(0xFFFFFF) << PWM_ETRG1_MAXCNT_Pos)         /* (PWM_ETRG1) Maximum Counter value Mask */
#define PWM_ETRG1_MAXCNT(value)               (PWM_ETRG1_MAXCNT_Msk & (_UINT32_(value) << PWM_ETRG1_MAXCNT_Pos)) /* Assigment of value for MAXCNT in the PWM_ETRG1 register */
#define PWM_ETRG1_TRGMODE_Pos                 _UINT32_(24)                                         /* (PWM_ETRG1) External Trigger Mode Position */
#define PWM_ETRG1_TRGMODE_Msk                 (_UINT32_(0x3) << PWM_ETRG1_TRGMODE_Pos)             /* (PWM_ETRG1) External Trigger Mode Mask */
#define PWM_ETRG1_TRGMODE(value)              (PWM_ETRG1_TRGMODE_Msk & (_UINT32_(value) << PWM_ETRG1_TRGMODE_Pos)) /* Assigment of value for TRGMODE in the PWM_ETRG1 register */
#define   PWM_ETRG1_TRGMODE_OFF_Val           _UINT32_(0x0)                                        /* (PWM_ETRG1) External trigger is not enabled.  */
#define   PWM_ETRG1_TRGMODE_MODE1_Val         _UINT32_(0x1)                                        /* (PWM_ETRG1) External PWM Reset Mode  */
#define   PWM_ETRG1_TRGMODE_MODE2_Val         _UINT32_(0x2)                                        /* (PWM_ETRG1) External PWM Start Mode  */
#define   PWM_ETRG1_TRGMODE_MODE3_Val         _UINT32_(0x3)                                        /* (PWM_ETRG1) Cycle-by-cycle Duty Mode  */
#define PWM_ETRG1_TRGMODE_OFF                 (PWM_ETRG1_TRGMODE_OFF_Val << PWM_ETRG1_TRGMODE_Pos) /* (PWM_ETRG1) External trigger is not enabled. Position  */
#define PWM_ETRG1_TRGMODE_MODE1               (PWM_ETRG1_TRGMODE_MODE1_Val << PWM_ETRG1_TRGMODE_Pos) /* (PWM_ETRG1) External PWM Reset Mode Position  */
#define PWM_ETRG1_TRGMODE_MODE2               (PWM_ETRG1_TRGMODE_MODE2_Val << PWM_ETRG1_TRGMODE_Pos) /* (PWM_ETRG1) External PWM Start Mode Position  */
#define PWM_ETRG1_TRGMODE_MODE3               (PWM_ETRG1_TRGMODE_MODE3_Val << PWM_ETRG1_TRGMODE_Pos) /* (PWM_ETRG1) Cycle-by-cycle Duty Mode Position  */
#define PWM_ETRG1_TRGEDGE_Pos                 _UINT32_(28)                                         /* (PWM_ETRG1) Edge Selection Position */
#define PWM_ETRG1_TRGEDGE_Msk                 (_UINT32_(0x1) << PWM_ETRG1_TRGEDGE_Pos)             /* (PWM_ETRG1) Edge Selection Mask */
#define PWM_ETRG1_TRGEDGE(value)              (PWM_ETRG1_TRGEDGE_Msk & (_UINT32_(value) << PWM_ETRG1_TRGEDGE_Pos)) /* Assigment of value for TRGEDGE in the PWM_ETRG1 register */
#define   PWM_ETRG1_TRGEDGE_FALLING_ZERO_Val  _UINT32_(0x0)                                        /* (PWM_ETRG1) TRGMODE = 1: TRGINx event detection on falling edge. TRGMODE = 2, 3: TRGINx active level is 0  */
#define   PWM_ETRG1_TRGEDGE_RISING_ONE_Val    _UINT32_(0x1)                                        /* (PWM_ETRG1) TRGMODE = 1: TRGINx event detection on rising edge. TRGMODE = 2, 3: TRGINx active level is 1  */
#define PWM_ETRG1_TRGEDGE_FALLING_ZERO        (PWM_ETRG1_TRGEDGE_FALLING_ZERO_Val << PWM_ETRG1_TRGEDGE_Pos) /* (PWM_ETRG1) TRGMODE = 1: TRGINx event detection on falling edge. TRGMODE = 2, 3: TRGINx active level is 0 Position  */
#define PWM_ETRG1_TRGEDGE_RISING_ONE          (PWM_ETRG1_TRGEDGE_RISING_ONE_Val << PWM_ETRG1_TRGEDGE_Pos) /* (PWM_ETRG1) TRGMODE = 1: TRGINx event detection on rising edge. TRGMODE = 2, 3: TRGINx active level is 1 Position  */
#define PWM_ETRG1_TRGFILT_Pos                 _UINT32_(29)                                         /* (PWM_ETRG1) Filtered input Position */
#define PWM_ETRG1_TRGFILT_Msk                 (_UINT32_(0x1) << PWM_ETRG1_TRGFILT_Pos)             /* (PWM_ETRG1) Filtered input Mask */
#define PWM_ETRG1_TRGFILT(value)              (PWM_ETRG1_TRGFILT_Msk & (_UINT32_(value) << PWM_ETRG1_TRGFILT_Pos)) /* Assigment of value for TRGFILT in the PWM_ETRG1 register */
#define   PWM_ETRG1_TRGFILT_0_Val             _UINT32_(0x0)                                        /* (PWM_ETRG1) The external trigger input x is not filtered.  */
#define   PWM_ETRG1_TRGFILT_1_Val             _UINT32_(0x1)                                        /* (PWM_ETRG1) The external trigger input x is filtered.  */
#define PWM_ETRG1_TRGFILT_0                   (PWM_ETRG1_TRGFILT_0_Val << PWM_ETRG1_TRGFILT_Pos)   /* (PWM_ETRG1) The external trigger input x is not filtered. Position  */
#define PWM_ETRG1_TRGFILT_1                   (PWM_ETRG1_TRGFILT_1_Val << PWM_ETRG1_TRGFILT_Pos)   /* (PWM_ETRG1) The external trigger input x is filtered. Position  */
#define PWM_ETRG1_TRGSRC_Pos                  _UINT32_(30)                                         /* (PWM_ETRG1) Trigger Source Position */
#define PWM_ETRG1_TRGSRC_Msk                  (_UINT32_(0x1) << PWM_ETRG1_TRGSRC_Pos)              /* (PWM_ETRG1) Trigger Source Mask */
#define PWM_ETRG1_TRGSRC(value)               (PWM_ETRG1_TRGSRC_Msk & (_UINT32_(value) << PWM_ETRG1_TRGSRC_Pos)) /* Assigment of value for TRGSRC in the PWM_ETRG1 register */
#define   PWM_ETRG1_TRGSRC_0_Val              _UINT32_(0x0)                                        /* (PWM_ETRG1) The TRGINx signal is driven by the PWMEXTRGx input.  */
#define   PWM_ETRG1_TRGSRC_1_Val              _UINT32_(0x1)                                        /* (PWM_ETRG1) The TRGINx signal is driven by the Analog Comparator Controller.  */
#define PWM_ETRG1_TRGSRC_0                    (PWM_ETRG1_TRGSRC_0_Val << PWM_ETRG1_TRGSRC_Pos)     /* (PWM_ETRG1) The TRGINx signal is driven by the PWMEXTRGx input. Position  */
#define PWM_ETRG1_TRGSRC_1                    (PWM_ETRG1_TRGSRC_1_Val << PWM_ETRG1_TRGSRC_Pos)     /* (PWM_ETRG1) The TRGINx signal is driven by the Analog Comparator Controller. Position  */
#define PWM_ETRG1_RFEN_Pos                    _UINT32_(31)                                         /* (PWM_ETRG1) Recoverable Fault Enable Position */
#define PWM_ETRG1_RFEN_Msk                    (_UINT32_(0x1) << PWM_ETRG1_RFEN_Pos)                /* (PWM_ETRG1) Recoverable Fault Enable Mask */
#define PWM_ETRG1_RFEN(value)                 (PWM_ETRG1_RFEN_Msk & (_UINT32_(value) << PWM_ETRG1_RFEN_Pos)) /* Assigment of value for RFEN in the PWM_ETRG1 register */
#define   PWM_ETRG1_RFEN_0_Val                _UINT32_(0x0)                                        /* (PWM_ETRG1) The TRGINx signal does not generate a recoverable fault.  */
#define   PWM_ETRG1_RFEN_1_Val                _UINT32_(0x1)                                        /* (PWM_ETRG1) The TRGINx signal generate a recoverable fault in place of the fault x input.  */
#define PWM_ETRG1_RFEN_0                      (PWM_ETRG1_RFEN_0_Val << PWM_ETRG1_RFEN_Pos)         /* (PWM_ETRG1) The TRGINx signal does not generate a recoverable fault. Position  */
#define PWM_ETRG1_RFEN_1                      (PWM_ETRG1_RFEN_1_Val << PWM_ETRG1_RFEN_Pos)         /* (PWM_ETRG1) The TRGINx signal generate a recoverable fault in place of the fault x input. Position  */
#define PWM_ETRG1_Msk                         _UINT32_(0xF3FFFFFF)                                 /* (PWM_ETRG1) Register Mask  */


/* -------- PWM_LEBR1 : (PWM Offset: 0x430) (R/W 32) PWM Leading-Edge Blanking Register 1 -------- */
#define PWM_LEBR1_LEBDELAY_Pos                _UINT32_(0)                                          /* (PWM_LEBR1) Leading-Edge Blanking Delay for TRGINx Position */
#define PWM_LEBR1_LEBDELAY_Msk                (_UINT32_(0x7F) << PWM_LEBR1_LEBDELAY_Pos)           /* (PWM_LEBR1) Leading-Edge Blanking Delay for TRGINx Mask */
#define PWM_LEBR1_LEBDELAY(value)             (PWM_LEBR1_LEBDELAY_Msk & (_UINT32_(value) << PWM_LEBR1_LEBDELAY_Pos)) /* Assigment of value for LEBDELAY in the PWM_LEBR1 register */
#define PWM_LEBR1_PWMLFEN_Pos                 _UINT32_(16)                                         /* (PWM_LEBR1) PWML Falling Edge Enable Position */
#define PWM_LEBR1_PWMLFEN_Msk                 (_UINT32_(0x1) << PWM_LEBR1_PWMLFEN_Pos)             /* (PWM_LEBR1) PWML Falling Edge Enable Mask */
#define PWM_LEBR1_PWMLFEN(value)              (PWM_LEBR1_PWMLFEN_Msk & (_UINT32_(value) << PWM_LEBR1_PWMLFEN_Pos)) /* Assigment of value for PWMLFEN in the PWM_LEBR1 register */
#define   PWM_LEBR1_PWMLFEN_0_Val             _UINT32_(0x0)                                        /* (PWM_LEBR1) Leading-edge blanking is disabled on PWMLx output falling edge.  */
#define   PWM_LEBR1_PWMLFEN_1_Val             _UINT32_(0x1)                                        /* (PWM_LEBR1) Leading-edge blanking is enabled on PWMLx output falling edge.  */
#define PWM_LEBR1_PWMLFEN_0                   (PWM_LEBR1_PWMLFEN_0_Val << PWM_LEBR1_PWMLFEN_Pos)   /* (PWM_LEBR1) Leading-edge blanking is disabled on PWMLx output falling edge. Position  */
#define PWM_LEBR1_PWMLFEN_1                   (PWM_LEBR1_PWMLFEN_1_Val << PWM_LEBR1_PWMLFEN_Pos)   /* (PWM_LEBR1) Leading-edge blanking is enabled on PWMLx output falling edge. Position  */
#define PWM_LEBR1_PWMLREN_Pos                 _UINT32_(17)                                         /* (PWM_LEBR1) PWML Rising Edge Enable Position */
#define PWM_LEBR1_PWMLREN_Msk                 (_UINT32_(0x1) << PWM_LEBR1_PWMLREN_Pos)             /* (PWM_LEBR1) PWML Rising Edge Enable Mask */
#define PWM_LEBR1_PWMLREN(value)              (PWM_LEBR1_PWMLREN_Msk & (_UINT32_(value) << PWM_LEBR1_PWMLREN_Pos)) /* Assigment of value for PWMLREN in the PWM_LEBR1 register */
#define   PWM_LEBR1_PWMLREN_0_Val             _UINT32_(0x0)                                        /* (PWM_LEBR1) Leading-edge blanking is disabled on PWMLx output rising edge.  */
#define   PWM_LEBR1_PWMLREN_1_Val             _UINT32_(0x1)                                        /* (PWM_LEBR1) Leading-edge blanking is enabled on PWMLx output rising edge.  */
#define PWM_LEBR1_PWMLREN_0                   (PWM_LEBR1_PWMLREN_0_Val << PWM_LEBR1_PWMLREN_Pos)   /* (PWM_LEBR1) Leading-edge blanking is disabled on PWMLx output rising edge. Position  */
#define PWM_LEBR1_PWMLREN_1                   (PWM_LEBR1_PWMLREN_1_Val << PWM_LEBR1_PWMLREN_Pos)   /* (PWM_LEBR1) Leading-edge blanking is enabled on PWMLx output rising edge. Position  */
#define PWM_LEBR1_PWMHFEN_Pos                 _UINT32_(18)                                         /* (PWM_LEBR1) PWMH Falling Edge Enable Position */
#define PWM_LEBR1_PWMHFEN_Msk                 (_UINT32_(0x1) << PWM_LEBR1_PWMHFEN_Pos)             /* (PWM_LEBR1) PWMH Falling Edge Enable Mask */
#define PWM_LEBR1_PWMHFEN(value)              (PWM_LEBR1_PWMHFEN_Msk & (_UINT32_(value) << PWM_LEBR1_PWMHFEN_Pos)) /* Assigment of value for PWMHFEN in the PWM_LEBR1 register */
#define   PWM_LEBR1_PWMHFEN_0_Val             _UINT32_(0x0)                                        /* (PWM_LEBR1) Leading-edge blanking is disabled on PWMHx output falling edge.  */
#define   PWM_LEBR1_PWMHFEN_1_Val             _UINT32_(0x1)                                        /* (PWM_LEBR1) Leading-edge blanking is enabled on PWMHx output falling edge.  */
#define PWM_LEBR1_PWMHFEN_0                   (PWM_LEBR1_PWMHFEN_0_Val << PWM_LEBR1_PWMHFEN_Pos)   /* (PWM_LEBR1) Leading-edge blanking is disabled on PWMHx output falling edge. Position  */
#define PWM_LEBR1_PWMHFEN_1                   (PWM_LEBR1_PWMHFEN_1_Val << PWM_LEBR1_PWMHFEN_Pos)   /* (PWM_LEBR1) Leading-edge blanking is enabled on PWMHx output falling edge. Position  */
#define PWM_LEBR1_PWMHREN_Pos                 _UINT32_(19)                                         /* (PWM_LEBR1) PWMH Rising Edge Enable Position */
#define PWM_LEBR1_PWMHREN_Msk                 (_UINT32_(0x1) << PWM_LEBR1_PWMHREN_Pos)             /* (PWM_LEBR1) PWMH Rising Edge Enable Mask */
#define PWM_LEBR1_PWMHREN(value)              (PWM_LEBR1_PWMHREN_Msk & (_UINT32_(value) << PWM_LEBR1_PWMHREN_Pos)) /* Assigment of value for PWMHREN in the PWM_LEBR1 register */
#define   PWM_LEBR1_PWMHREN_0_Val             _UINT32_(0x0)                                        /* (PWM_LEBR1) Leading-edge blanking is disabled on PWMHx output rising edge.  */
#define   PWM_LEBR1_PWMHREN_1_Val             _UINT32_(0x1)                                        /* (PWM_LEBR1) Leading-edge blanking is enabled on PWMHx output rising edge.  */
#define PWM_LEBR1_PWMHREN_0                   (PWM_LEBR1_PWMHREN_0_Val << PWM_LEBR1_PWMHREN_Pos)   /* (PWM_LEBR1) Leading-edge blanking is disabled on PWMHx output rising edge. Position  */
#define PWM_LEBR1_PWMHREN_1                   (PWM_LEBR1_PWMHREN_1_Val << PWM_LEBR1_PWMHREN_Pos)   /* (PWM_LEBR1) Leading-edge blanking is enabled on PWMHx output rising edge. Position  */
#define PWM_LEBR1_Msk                         _UINT32_(0x000F007F)                                 /* (PWM_LEBR1) Register Mask  */


/* -------- PWM_CMUPD2 : (PWM Offset: 0x440) ( /W 32) PWM Channel Mode Update Register (ch_num = 2) -------- */
#define PWM_CMUPD2_CPOLUP_Pos                 _UINT32_(9)                                          /* (PWM_CMUPD2) Channel Polarity Update Position */
#define PWM_CMUPD2_CPOLUP_Msk                 (_UINT32_(0x1) << PWM_CMUPD2_CPOLUP_Pos)             /* (PWM_CMUPD2) Channel Polarity Update Mask */
#define PWM_CMUPD2_CPOLUP(value)              (PWM_CMUPD2_CPOLUP_Msk & (_UINT32_(value) << PWM_CMUPD2_CPOLUP_Pos)) /* Assigment of value for CPOLUP in the PWM_CMUPD2 register */
#define   PWM_CMUPD2_CPOLUP_0_Val             _UINT32_(0x0)                                        /* (PWM_CMUPD2) The OCx output waveform (output from the comparator) starts at a low level.  */
#define   PWM_CMUPD2_CPOLUP_1_Val             _UINT32_(0x1)                                        /* (PWM_CMUPD2) The OCx output waveform (output from the comparator) starts at a high level.  */
#define PWM_CMUPD2_CPOLUP_0                   (PWM_CMUPD2_CPOLUP_0_Val << PWM_CMUPD2_CPOLUP_Pos)   /* (PWM_CMUPD2) The OCx output waveform (output from the comparator) starts at a low level. Position  */
#define PWM_CMUPD2_CPOLUP_1                   (PWM_CMUPD2_CPOLUP_1_Val << PWM_CMUPD2_CPOLUP_Pos)   /* (PWM_CMUPD2) The OCx output waveform (output from the comparator) starts at a high level. Position  */
#define PWM_CMUPD2_CPOLINVUP_Pos              _UINT32_(13)                                         /* (PWM_CMUPD2) Channel Polarity Inversion Update Position */
#define PWM_CMUPD2_CPOLINVUP_Msk              (_UINT32_(0x1) << PWM_CMUPD2_CPOLINVUP_Pos)          /* (PWM_CMUPD2) Channel Polarity Inversion Update Mask */
#define PWM_CMUPD2_CPOLINVUP(value)           (PWM_CMUPD2_CPOLINVUP_Msk & (_UINT32_(value) << PWM_CMUPD2_CPOLINVUP_Pos)) /* Assigment of value for CPOLINVUP in the PWM_CMUPD2 register */
#define   PWM_CMUPD2_CPOLINVUP_0_Val          _UINT32_(0x0)                                        /* (PWM_CMUPD2) No effect.  */
#define   PWM_CMUPD2_CPOLINVUP_1_Val          _UINT32_(0x1)                                        /* (PWM_CMUPD2) The OCx output waveform (output from the comparator) is inverted.  */
#define PWM_CMUPD2_CPOLINVUP_0                (PWM_CMUPD2_CPOLINVUP_0_Val << PWM_CMUPD2_CPOLINVUP_Pos) /* (PWM_CMUPD2) No effect. Position  */
#define PWM_CMUPD2_CPOLINVUP_1                (PWM_CMUPD2_CPOLINVUP_1_Val << PWM_CMUPD2_CPOLINVUP_Pos) /* (PWM_CMUPD2) The OCx output waveform (output from the comparator) is inverted. Position  */
#define PWM_CMUPD2_Msk                        _UINT32_(0x00002200)                                 /* (PWM_CMUPD2) Register Mask  */


/* -------- PWM_ETRG2 : (PWM Offset: 0x44C) (R/W 32) PWM External Trigger Register 2 -------- */
#define PWM_ETRG2_MAXCNT_Pos                  _UINT32_(0)                                          /* (PWM_ETRG2) Maximum Counter value Position */
#define PWM_ETRG2_MAXCNT_Msk                  (_UINT32_(0xFFFFFF) << PWM_ETRG2_MAXCNT_Pos)         /* (PWM_ETRG2) Maximum Counter value Mask */
#define PWM_ETRG2_MAXCNT(value)               (PWM_ETRG2_MAXCNT_Msk & (_UINT32_(value) << PWM_ETRG2_MAXCNT_Pos)) /* Assigment of value for MAXCNT in the PWM_ETRG2 register */
#define PWM_ETRG2_TRGMODE_Pos                 _UINT32_(24)                                         /* (PWM_ETRG2) External Trigger Mode Position */
#define PWM_ETRG2_TRGMODE_Msk                 (_UINT32_(0x3) << PWM_ETRG2_TRGMODE_Pos)             /* (PWM_ETRG2) External Trigger Mode Mask */
#define PWM_ETRG2_TRGMODE(value)              (PWM_ETRG2_TRGMODE_Msk & (_UINT32_(value) << PWM_ETRG2_TRGMODE_Pos)) /* Assigment of value for TRGMODE in the PWM_ETRG2 register */
#define   PWM_ETRG2_TRGMODE_OFF_Val           _UINT32_(0x0)                                        /* (PWM_ETRG2) External trigger is not enabled.  */
#define   PWM_ETRG2_TRGMODE_MODE1_Val         _UINT32_(0x1)                                        /* (PWM_ETRG2) External PWM Reset Mode  */
#define   PWM_ETRG2_TRGMODE_MODE2_Val         _UINT32_(0x2)                                        /* (PWM_ETRG2) External PWM Start Mode  */
#define   PWM_ETRG2_TRGMODE_MODE3_Val         _UINT32_(0x3)                                        /* (PWM_ETRG2) Cycle-by-cycle Duty Mode  */
#define PWM_ETRG2_TRGMODE_OFF                 (PWM_ETRG2_TRGMODE_OFF_Val << PWM_ETRG2_TRGMODE_Pos) /* (PWM_ETRG2) External trigger is not enabled. Position  */
#define PWM_ETRG2_TRGMODE_MODE1               (PWM_ETRG2_TRGMODE_MODE1_Val << PWM_ETRG2_TRGMODE_Pos) /* (PWM_ETRG2) External PWM Reset Mode Position  */
#define PWM_ETRG2_TRGMODE_MODE2               (PWM_ETRG2_TRGMODE_MODE2_Val << PWM_ETRG2_TRGMODE_Pos) /* (PWM_ETRG2) External PWM Start Mode Position  */
#define PWM_ETRG2_TRGMODE_MODE3               (PWM_ETRG2_TRGMODE_MODE3_Val << PWM_ETRG2_TRGMODE_Pos) /* (PWM_ETRG2) Cycle-by-cycle Duty Mode Position  */
#define PWM_ETRG2_TRGEDGE_Pos                 _UINT32_(28)                                         /* (PWM_ETRG2) Edge Selection Position */
#define PWM_ETRG2_TRGEDGE_Msk                 (_UINT32_(0x1) << PWM_ETRG2_TRGEDGE_Pos)             /* (PWM_ETRG2) Edge Selection Mask */
#define PWM_ETRG2_TRGEDGE(value)              (PWM_ETRG2_TRGEDGE_Msk & (_UINT32_(value) << PWM_ETRG2_TRGEDGE_Pos)) /* Assigment of value for TRGEDGE in the PWM_ETRG2 register */
#define   PWM_ETRG2_TRGEDGE_FALLING_ZERO_Val  _UINT32_(0x0)                                        /* (PWM_ETRG2) TRGMODE = 1: TRGINx event detection on falling edge. TRGMODE = 2, 3: TRGINx active level is 0  */
#define   PWM_ETRG2_TRGEDGE_RISING_ONE_Val    _UINT32_(0x1)                                        /* (PWM_ETRG2) TRGMODE = 1: TRGINx event detection on rising edge. TRGMODE = 2, 3: TRGINx active level is 1  */
#define PWM_ETRG2_TRGEDGE_FALLING_ZERO        (PWM_ETRG2_TRGEDGE_FALLING_ZERO_Val << PWM_ETRG2_TRGEDGE_Pos) /* (PWM_ETRG2) TRGMODE = 1: TRGINx event detection on falling edge. TRGMODE = 2, 3: TRGINx active level is 0 Position  */
#define PWM_ETRG2_TRGEDGE_RISING_ONE          (PWM_ETRG2_TRGEDGE_RISING_ONE_Val << PWM_ETRG2_TRGEDGE_Pos) /* (PWM_ETRG2) TRGMODE = 1: TRGINx event detection on rising edge. TRGMODE = 2, 3: TRGINx active level is 1 Position  */
#define PWM_ETRG2_TRGFILT_Pos                 _UINT32_(29)                                         /* (PWM_ETRG2) Filtered input Position */
#define PWM_ETRG2_TRGFILT_Msk                 (_UINT32_(0x1) << PWM_ETRG2_TRGFILT_Pos)             /* (PWM_ETRG2) Filtered input Mask */
#define PWM_ETRG2_TRGFILT(value)              (PWM_ETRG2_TRGFILT_Msk & (_UINT32_(value) << PWM_ETRG2_TRGFILT_Pos)) /* Assigment of value for TRGFILT in the PWM_ETRG2 register */
#define   PWM_ETRG2_TRGFILT_0_Val             _UINT32_(0x0)                                        /* (PWM_ETRG2) The external trigger input x is not filtered.  */
#define   PWM_ETRG2_TRGFILT_1_Val             _UINT32_(0x1)                                        /* (PWM_ETRG2) The external trigger input x is filtered.  */
#define PWM_ETRG2_TRGFILT_0                   (PWM_ETRG2_TRGFILT_0_Val << PWM_ETRG2_TRGFILT_Pos)   /* (PWM_ETRG2) The external trigger input x is not filtered. Position  */
#define PWM_ETRG2_TRGFILT_1                   (PWM_ETRG2_TRGFILT_1_Val << PWM_ETRG2_TRGFILT_Pos)   /* (PWM_ETRG2) The external trigger input x is filtered. Position  */
#define PWM_ETRG2_TRGSRC_Pos                  _UINT32_(30)                                         /* (PWM_ETRG2) Trigger Source Position */
#define PWM_ETRG2_TRGSRC_Msk                  (_UINT32_(0x1) << PWM_ETRG2_TRGSRC_Pos)              /* (PWM_ETRG2) Trigger Source Mask */
#define PWM_ETRG2_TRGSRC(value)               (PWM_ETRG2_TRGSRC_Msk & (_UINT32_(value) << PWM_ETRG2_TRGSRC_Pos)) /* Assigment of value for TRGSRC in the PWM_ETRG2 register */
#define   PWM_ETRG2_TRGSRC_0_Val              _UINT32_(0x0)                                        /* (PWM_ETRG2) The TRGINx signal is driven by the PWMEXTRGx input.  */
#define   PWM_ETRG2_TRGSRC_1_Val              _UINT32_(0x1)                                        /* (PWM_ETRG2) The TRGINx signal is driven by the Analog Comparator Controller.  */
#define PWM_ETRG2_TRGSRC_0                    (PWM_ETRG2_TRGSRC_0_Val << PWM_ETRG2_TRGSRC_Pos)     /* (PWM_ETRG2) The TRGINx signal is driven by the PWMEXTRGx input. Position  */
#define PWM_ETRG2_TRGSRC_1                    (PWM_ETRG2_TRGSRC_1_Val << PWM_ETRG2_TRGSRC_Pos)     /* (PWM_ETRG2) The TRGINx signal is driven by the Analog Comparator Controller. Position  */
#define PWM_ETRG2_RFEN_Pos                    _UINT32_(31)                                         /* (PWM_ETRG2) Recoverable Fault Enable Position */
#define PWM_ETRG2_RFEN_Msk                    (_UINT32_(0x1) << PWM_ETRG2_RFEN_Pos)                /* (PWM_ETRG2) Recoverable Fault Enable Mask */
#define PWM_ETRG2_RFEN(value)                 (PWM_ETRG2_RFEN_Msk & (_UINT32_(value) << PWM_ETRG2_RFEN_Pos)) /* Assigment of value for RFEN in the PWM_ETRG2 register */
#define   PWM_ETRG2_RFEN_0_Val                _UINT32_(0x0)                                        /* (PWM_ETRG2) The TRGINx signal does not generate a recoverable fault.  */
#define   PWM_ETRG2_RFEN_1_Val                _UINT32_(0x1)                                        /* (PWM_ETRG2) The TRGINx signal generate a recoverable fault in place of the fault x input.  */
#define PWM_ETRG2_RFEN_0                      (PWM_ETRG2_RFEN_0_Val << PWM_ETRG2_RFEN_Pos)         /* (PWM_ETRG2) The TRGINx signal does not generate a recoverable fault. Position  */
#define PWM_ETRG2_RFEN_1                      (PWM_ETRG2_RFEN_1_Val << PWM_ETRG2_RFEN_Pos)         /* (PWM_ETRG2) The TRGINx signal generate a recoverable fault in place of the fault x input. Position  */
#define PWM_ETRG2_Msk                         _UINT32_(0xF3FFFFFF)                                 /* (PWM_ETRG2) Register Mask  */


/* -------- PWM_LEBR2 : (PWM Offset: 0x450) (R/W 32) PWM Leading-Edge Blanking Register 2 -------- */
#define PWM_LEBR2_LEBDELAY_Pos                _UINT32_(0)                                          /* (PWM_LEBR2) Leading-Edge Blanking Delay for TRGINx Position */
#define PWM_LEBR2_LEBDELAY_Msk                (_UINT32_(0x7F) << PWM_LEBR2_LEBDELAY_Pos)           /* (PWM_LEBR2) Leading-Edge Blanking Delay for TRGINx Mask */
#define PWM_LEBR2_LEBDELAY(value)             (PWM_LEBR2_LEBDELAY_Msk & (_UINT32_(value) << PWM_LEBR2_LEBDELAY_Pos)) /* Assigment of value for LEBDELAY in the PWM_LEBR2 register */
#define PWM_LEBR2_PWMLFEN_Pos                 _UINT32_(16)                                         /* (PWM_LEBR2) PWML Falling Edge Enable Position */
#define PWM_LEBR2_PWMLFEN_Msk                 (_UINT32_(0x1) << PWM_LEBR2_PWMLFEN_Pos)             /* (PWM_LEBR2) PWML Falling Edge Enable Mask */
#define PWM_LEBR2_PWMLFEN(value)              (PWM_LEBR2_PWMLFEN_Msk & (_UINT32_(value) << PWM_LEBR2_PWMLFEN_Pos)) /* Assigment of value for PWMLFEN in the PWM_LEBR2 register */
#define   PWM_LEBR2_PWMLFEN_0_Val             _UINT32_(0x0)                                        /* (PWM_LEBR2) Leading-edge blanking is disabled on PWMLx output falling edge.  */
#define   PWM_LEBR2_PWMLFEN_1_Val             _UINT32_(0x1)                                        /* (PWM_LEBR2) Leading-edge blanking is enabled on PWMLx output falling edge.  */
#define PWM_LEBR2_PWMLFEN_0                   (PWM_LEBR2_PWMLFEN_0_Val << PWM_LEBR2_PWMLFEN_Pos)   /* (PWM_LEBR2) Leading-edge blanking is disabled on PWMLx output falling edge. Position  */
#define PWM_LEBR2_PWMLFEN_1                   (PWM_LEBR2_PWMLFEN_1_Val << PWM_LEBR2_PWMLFEN_Pos)   /* (PWM_LEBR2) Leading-edge blanking is enabled on PWMLx output falling edge. Position  */
#define PWM_LEBR2_PWMLREN_Pos                 _UINT32_(17)                                         /* (PWM_LEBR2) PWML Rising Edge Enable Position */
#define PWM_LEBR2_PWMLREN_Msk                 (_UINT32_(0x1) << PWM_LEBR2_PWMLREN_Pos)             /* (PWM_LEBR2) PWML Rising Edge Enable Mask */
#define PWM_LEBR2_PWMLREN(value)              (PWM_LEBR2_PWMLREN_Msk & (_UINT32_(value) << PWM_LEBR2_PWMLREN_Pos)) /* Assigment of value for PWMLREN in the PWM_LEBR2 register */
#define   PWM_LEBR2_PWMLREN_0_Val             _UINT32_(0x0)                                        /* (PWM_LEBR2) Leading-edge blanking is disabled on PWMLx output rising edge.  */
#define   PWM_LEBR2_PWMLREN_1_Val             _UINT32_(0x1)                                        /* (PWM_LEBR2) Leading-edge blanking is enabled on PWMLx output rising edge.  */
#define PWM_LEBR2_PWMLREN_0                   (PWM_LEBR2_PWMLREN_0_Val << PWM_LEBR2_PWMLREN_Pos)   /* (PWM_LEBR2) Leading-edge blanking is disabled on PWMLx output rising edge. Position  */
#define PWM_LEBR2_PWMLREN_1                   (PWM_LEBR2_PWMLREN_1_Val << PWM_LEBR2_PWMLREN_Pos)   /* (PWM_LEBR2) Leading-edge blanking is enabled on PWMLx output rising edge. Position  */
#define PWM_LEBR2_PWMHFEN_Pos                 _UINT32_(18)                                         /* (PWM_LEBR2) PWMH Falling Edge Enable Position */
#define PWM_LEBR2_PWMHFEN_Msk                 (_UINT32_(0x1) << PWM_LEBR2_PWMHFEN_Pos)             /* (PWM_LEBR2) PWMH Falling Edge Enable Mask */
#define PWM_LEBR2_PWMHFEN(value)              (PWM_LEBR2_PWMHFEN_Msk & (_UINT32_(value) << PWM_LEBR2_PWMHFEN_Pos)) /* Assigment of value for PWMHFEN in the PWM_LEBR2 register */
#define   PWM_LEBR2_PWMHFEN_0_Val             _UINT32_(0x0)                                        /* (PWM_LEBR2) Leading-edge blanking is disabled on PWMHx output falling edge.  */
#define   PWM_LEBR2_PWMHFEN_1_Val             _UINT32_(0x1)                                        /* (PWM_LEBR2) Leading-edge blanking is enabled on PWMHx output falling edge.  */
#define PWM_LEBR2_PWMHFEN_0                   (PWM_LEBR2_PWMHFEN_0_Val << PWM_LEBR2_PWMHFEN_Pos)   /* (PWM_LEBR2) Leading-edge blanking is disabled on PWMHx output falling edge. Position  */
#define PWM_LEBR2_PWMHFEN_1                   (PWM_LEBR2_PWMHFEN_1_Val << PWM_LEBR2_PWMHFEN_Pos)   /* (PWM_LEBR2) Leading-edge blanking is enabled on PWMHx output falling edge. Position  */
#define PWM_LEBR2_PWMHREN_Pos                 _UINT32_(19)                                         /* (PWM_LEBR2) PWMH Rising Edge Enable Position */
#define PWM_LEBR2_PWMHREN_Msk                 (_UINT32_(0x1) << PWM_LEBR2_PWMHREN_Pos)             /* (PWM_LEBR2) PWMH Rising Edge Enable Mask */
#define PWM_LEBR2_PWMHREN(value)              (PWM_LEBR2_PWMHREN_Msk & (_UINT32_(value) << PWM_LEBR2_PWMHREN_Pos)) /* Assigment of value for PWMHREN in the PWM_LEBR2 register */
#define   PWM_LEBR2_PWMHREN_0_Val             _UINT32_(0x0)                                        /* (PWM_LEBR2) Leading-edge blanking is disabled on PWMHx output rising edge.  */
#define   PWM_LEBR2_PWMHREN_1_Val             _UINT32_(0x1)                                        /* (PWM_LEBR2) Leading-edge blanking is enabled on PWMHx output rising edge.  */
#define PWM_LEBR2_PWMHREN_0                   (PWM_LEBR2_PWMHREN_0_Val << PWM_LEBR2_PWMHREN_Pos)   /* (PWM_LEBR2) Leading-edge blanking is disabled on PWMHx output rising edge. Position  */
#define PWM_LEBR2_PWMHREN_1                   (PWM_LEBR2_PWMHREN_1_Val << PWM_LEBR2_PWMHREN_Pos)   /* (PWM_LEBR2) Leading-edge blanking is enabled on PWMHx output rising edge. Position  */
#define PWM_LEBR2_Msk                         _UINT32_(0x000F007F)                                 /* (PWM_LEBR2) Register Mask  */


/* -------- PWM_CMUPD3 : (PWM Offset: 0x460) ( /W 32) PWM Channel Mode Update Register (ch_num = 3) -------- */
#define PWM_CMUPD3_CPOLUP_Pos                 _UINT32_(9)                                          /* (PWM_CMUPD3) Channel Polarity Update Position */
#define PWM_CMUPD3_CPOLUP_Msk                 (_UINT32_(0x1) << PWM_CMUPD3_CPOLUP_Pos)             /* (PWM_CMUPD3) Channel Polarity Update Mask */
#define PWM_CMUPD3_CPOLUP(value)              (PWM_CMUPD3_CPOLUP_Msk & (_UINT32_(value) << PWM_CMUPD3_CPOLUP_Pos)) /* Assigment of value for CPOLUP in the PWM_CMUPD3 register */
#define   PWM_CMUPD3_CPOLUP_0_Val             _UINT32_(0x0)                                        /* (PWM_CMUPD3) The OCx output waveform (output from the comparator) starts at a low level.  */
#define   PWM_CMUPD3_CPOLUP_1_Val             _UINT32_(0x1)                                        /* (PWM_CMUPD3) The OCx output waveform (output from the comparator) starts at a high level.  */
#define PWM_CMUPD3_CPOLUP_0                   (PWM_CMUPD3_CPOLUP_0_Val << PWM_CMUPD3_CPOLUP_Pos)   /* (PWM_CMUPD3) The OCx output waveform (output from the comparator) starts at a low level. Position  */
#define PWM_CMUPD3_CPOLUP_1                   (PWM_CMUPD3_CPOLUP_1_Val << PWM_CMUPD3_CPOLUP_Pos)   /* (PWM_CMUPD3) The OCx output waveform (output from the comparator) starts at a high level. Position  */
#define PWM_CMUPD3_CPOLINVUP_Pos              _UINT32_(13)                                         /* (PWM_CMUPD3) Channel Polarity Inversion Update Position */
#define PWM_CMUPD3_CPOLINVUP_Msk              (_UINT32_(0x1) << PWM_CMUPD3_CPOLINVUP_Pos)          /* (PWM_CMUPD3) Channel Polarity Inversion Update Mask */
#define PWM_CMUPD3_CPOLINVUP(value)           (PWM_CMUPD3_CPOLINVUP_Msk & (_UINT32_(value) << PWM_CMUPD3_CPOLINVUP_Pos)) /* Assigment of value for CPOLINVUP in the PWM_CMUPD3 register */
#define   PWM_CMUPD3_CPOLINVUP_0_Val          _UINT32_(0x0)                                        /* (PWM_CMUPD3) No effect.  */
#define   PWM_CMUPD3_CPOLINVUP_1_Val          _UINT32_(0x1)                                        /* (PWM_CMUPD3) The OCx output waveform (output from the comparator) is inverted.  */
#define PWM_CMUPD3_CPOLINVUP_0                (PWM_CMUPD3_CPOLINVUP_0_Val << PWM_CMUPD3_CPOLINVUP_Pos) /* (PWM_CMUPD3) No effect. Position  */
#define PWM_CMUPD3_CPOLINVUP_1                (PWM_CMUPD3_CPOLINVUP_1_Val << PWM_CMUPD3_CPOLINVUP_Pos) /* (PWM_CMUPD3) The OCx output waveform (output from the comparator) is inverted. Position  */
#define PWM_CMUPD3_Msk                        _UINT32_(0x00002200)                                 /* (PWM_CMUPD3) Register Mask  */


/** \brief PWM register offsets definitions */
#define PWM_CMR_REG_OFST               _UINT32_(0x00)      /* (PWM_CMR) PWM Channel Mode Register  Offset */
#define PWM_CDTY_REG_OFST              _UINT32_(0x04)      /* (PWM_CDTY) PWM Channel Duty Cycle Register  Offset */
#define PWM_CDTYUPD_REG_OFST           _UINT32_(0x08)      /* (PWM_CDTYUPD) PWM Channel Duty Cycle Update Register  Offset */
#define PWM_CPRD_REG_OFST              _UINT32_(0x0C)      /* (PWM_CPRD) PWM Channel Period Register  Offset */
#define PWM_CPRDUPD_REG_OFST           _UINT32_(0x10)      /* (PWM_CPRDUPD) PWM Channel Period Update Register  Offset */
#define PWM_CCNT_REG_OFST              _UINT32_(0x14)      /* (PWM_CCNT) PWM Channel Counter Register  Offset */
#define PWM_DT_REG_OFST                _UINT32_(0x18)      /* (PWM_DT) PWM Channel Dead Time Register  Offset */
#define PWM_DTUPD_REG_OFST             _UINT32_(0x1C)      /* (PWM_DTUPD) PWM Channel Dead Time Update Register  Offset */
#define PWM_CMPV_REG_OFST              _UINT32_(0x00)      /* (PWM_CMPV) PWM Comparison x Value Register Offset */
#define PWM_CMPVUPD_REG_OFST           _UINT32_(0x04)      /* (PWM_CMPVUPD) PWM Comparison x Value Update Register Offset */
#define PWM_CMPM_REG_OFST              _UINT32_(0x08)      /* (PWM_CMPM) PWM Comparison x Mode Register Offset */
#define PWM_CMPMUPD_REG_OFST           _UINT32_(0x0C)      /* (PWM_CMPMUPD) PWM Comparison x Mode Update Register Offset */
#define PWM_CLK_REG_OFST               _UINT32_(0x00)      /* (PWM_CLK) PWM Clock Register Offset */
#define PWM_ENA_REG_OFST               _UINT32_(0x04)      /* (PWM_ENA) PWM Enable Register Offset */
#define PWM_DIS_REG_OFST               _UINT32_(0x08)      /* (PWM_DIS) PWM Disable Register Offset */
#define PWM_SR_REG_OFST                _UINT32_(0x0C)      /* (PWM_SR) PWM Status Register Offset */
#define PWM_IER1_REG_OFST              _UINT32_(0x10)      /* (PWM_IER1) PWM Interrupt Enable Register 1 Offset */
#define PWM_IDR1_REG_OFST              _UINT32_(0x14)      /* (PWM_IDR1) PWM Interrupt Disable Register 1 Offset */
#define PWM_IMR1_REG_OFST              _UINT32_(0x18)      /* (PWM_IMR1) PWM Interrupt Mask Register 1 Offset */
#define PWM_ISR1_REG_OFST              _UINT32_(0x1C)      /* (PWM_ISR1) PWM Interrupt Status Register 1 Offset */
#define PWM_SCM_REG_OFST               _UINT32_(0x20)      /* (PWM_SCM) PWM Sync Channels Mode Register Offset */
#define PWM_DMAR_REG_OFST              _UINT32_(0x24)      /* (PWM_DMAR) PWM DMA Register Offset */
#define PWM_SCUC_REG_OFST              _UINT32_(0x28)      /* (PWM_SCUC) PWM Sync Channels Update Control Register Offset */
#define PWM_SCUP_REG_OFST              _UINT32_(0x2C)      /* (PWM_SCUP) PWM Sync Channels Update Period Register Offset */
#define PWM_SCUPUPD_REG_OFST           _UINT32_(0x30)      /* (PWM_SCUPUPD) PWM Sync Channels Update Period Update Register Offset */
#define PWM_IER2_REG_OFST              _UINT32_(0x34)      /* (PWM_IER2) PWM Interrupt Enable Register 2 Offset */
#define PWM_IDR2_REG_OFST              _UINT32_(0x38)      /* (PWM_IDR2) PWM Interrupt Disable Register 2 Offset */
#define PWM_IMR2_REG_OFST              _UINT32_(0x3C)      /* (PWM_IMR2) PWM Interrupt Mask Register 2 Offset */
#define PWM_ISR2_REG_OFST              _UINT32_(0x40)      /* (PWM_ISR2) PWM Interrupt Status Register 2 Offset */
#define PWM_OOV_REG_OFST               _UINT32_(0x44)      /* (PWM_OOV) PWM Output Override Value Register Offset */
#define PWM_OS_REG_OFST                _UINT32_(0x48)      /* (PWM_OS) PWM Output Selection Register Offset */
#define PWM_OSS_REG_OFST               _UINT32_(0x4C)      /* (PWM_OSS) PWM Output Selection Set Register Offset */
#define PWM_OSC_REG_OFST               _UINT32_(0x50)      /* (PWM_OSC) PWM Output Selection Clear Register Offset */
#define PWM_OSSUPD_REG_OFST            _UINT32_(0x54)      /* (PWM_OSSUPD) PWM Output Selection Set Update Register Offset */
#define PWM_OSCUPD_REG_OFST            _UINT32_(0x58)      /* (PWM_OSCUPD) PWM Output Selection Clear Update Register Offset */
#define PWM_FMR_REG_OFST               _UINT32_(0x5C)      /* (PWM_FMR) PWM Fault Mode Register Offset */
#define PWM_FSR_REG_OFST               _UINT32_(0x60)      /* (PWM_FSR) PWM Fault Status Register Offset */
#define PWM_FCR_REG_OFST               _UINT32_(0x64)      /* (PWM_FCR) PWM Fault Clear Register Offset */
#define PWM_FPV1_REG_OFST              _UINT32_(0x68)      /* (PWM_FPV1) PWM Fault Protection Value Register 1 Offset */
#define PWM_FPE_REG_OFST               _UINT32_(0x6C)      /* (PWM_FPE) PWM Fault Protection Enable Register Offset */
#define PWM_ELMR_REG_OFST              _UINT32_(0x7C)      /* (PWM_ELMR) PWM Event Line x Mode Register Offset */
#define PWM_ELMR0_REG_OFST             _UINT32_(0x7C)      /* (PWM_ELMR0) PWM Event Line x Mode Register Offset */
#define PWM_ELMR1_REG_OFST             _UINT32_(0x80)      /* (PWM_ELMR1) PWM Event Line x Mode Register Offset */
#define PWM_SSPR_REG_OFST              _UINT32_(0xA0)      /* (PWM_SSPR) PWM Spread Spectrum Register Offset */
#define PWM_SSPUP_REG_OFST             _UINT32_(0xA4)      /* (PWM_SSPUP) PWM Spread Spectrum Update Register Offset */
#define PWM_SMMR_REG_OFST              _UINT32_(0xB0)      /* (PWM_SMMR) PWM Stepper Motor Mode Register Offset */
#define PWM_FPV2_REG_OFST              _UINT32_(0xC0)      /* (PWM_FPV2) PWM Fault Protection Value 2 Register Offset */
#define PWM_WPCR_REG_OFST              _UINT32_(0xE4)      /* (PWM_WPCR) PWM Write Protection Control Register Offset */
#define PWM_WPSR_REG_OFST              _UINT32_(0xE8)      /* (PWM_WPSR) PWM Write Protection Status Register Offset */
#define PWM_CMUPD0_REG_OFST            _UINT32_(0x400)     /* (PWM_CMUPD0) PWM Channel Mode Update Register (ch_num = 0) Offset */
#define PWM_CMUPD1_REG_OFST            _UINT32_(0x420)     /* (PWM_CMUPD1) PWM Channel Mode Update Register (ch_num = 1) Offset */
#define PWM_ETRG1_REG_OFST             _UINT32_(0x42C)     /* (PWM_ETRG1) PWM External Trigger Register 1 Offset */
#define PWM_LEBR1_REG_OFST             _UINT32_(0x430)     /* (PWM_LEBR1) PWM Leading-Edge Blanking Register 1 Offset */
#define PWM_CMUPD2_REG_OFST            _UINT32_(0x440)     /* (PWM_CMUPD2) PWM Channel Mode Update Register (ch_num = 2) Offset */
#define PWM_ETRG2_REG_OFST             _UINT32_(0x44C)     /* (PWM_ETRG2) PWM External Trigger Register 2 Offset */
#define PWM_LEBR2_REG_OFST             _UINT32_(0x450)     /* (PWM_LEBR2) PWM Leading-Edge Blanking Register 2 Offset */
#define PWM_CMUPD3_REG_OFST            _UINT32_(0x460)     /* (PWM_CMUPD3) PWM Channel Mode Update Register (ch_num = 3) Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief PWM_CH_NUM register API structure */
typedef struct
{
  __IO  uint32_t                       PWM_CMR;            /**< Offset: 0x00 (R/W  32) PWM Channel Mode Register  */
  __IO  uint32_t                       PWM_CDTY;           /**< Offset: 0x04 (R/W  32) PWM Channel Duty Cycle Register  */
  __O   uint32_t                       PWM_CDTYUPD;        /**< Offset: 0x08 ( /W  32) PWM Channel Duty Cycle Update Register  */
  __IO  uint32_t                       PWM_CPRD;           /**< Offset: 0x0C (R/W  32) PWM Channel Period Register  */
  __O   uint32_t                       PWM_CPRDUPD;        /**< Offset: 0x10 ( /W  32) PWM Channel Period Update Register  */
  __I   uint32_t                       PWM_CCNT;           /**< Offset: 0x14 (R/   32) PWM Channel Counter Register  */
  __IO  uint32_t                       PWM_DT;             /**< Offset: 0x18 (R/W  32) PWM Channel Dead Time Register  */
  __O   uint32_t                       PWM_DTUPD;          /**< Offset: 0x1C ( /W  32) PWM Channel Dead Time Update Register  */
} pwm_ch_num_registers_t;

/** \brief PWM_CMP register API structure */
typedef struct
{
  __IO  uint32_t                       PWM_CMPV;           /**< Offset: 0x00 (R/W  32) PWM Comparison x Value Register */
  __O   uint32_t                       PWM_CMPVUPD;        /**< Offset: 0x04 ( /W  32) PWM Comparison x Value Update Register */
  __IO  uint32_t                       PWM_CMPM;           /**< Offset: 0x08 (R/W  32) PWM Comparison x Mode Register */
  __O   uint32_t                       PWM_CMPMUPD;        /**< Offset: 0x0C ( /W  32) PWM Comparison x Mode Update Register */
} pwm_cmp_registers_t;

#define PWM_CMP_NUMBER 8

#define PWM_CH_NUM_NUMBER 4

/** \brief PWM register API structure */
typedef struct
{  /* Pulse Width Modulation Controller */
  __IO  uint32_t                       PWM_CLK;            /**< Offset: 0x00 (R/W  32) PWM Clock Register */
  __O   uint32_t                       PWM_ENA;            /**< Offset: 0x04 ( /W  32) PWM Enable Register */
  __O   uint32_t                       PWM_DIS;            /**< Offset: 0x08 ( /W  32) PWM Disable Register */
  __I   uint32_t                       PWM_SR;             /**< Offset: 0x0C (R/   32) PWM Status Register */
  __O   uint32_t                       PWM_IER1;           /**< Offset: 0x10 ( /W  32) PWM Interrupt Enable Register 1 */
  __O   uint32_t                       PWM_IDR1;           /**< Offset: 0x14 ( /W  32) PWM Interrupt Disable Register 1 */
  __I   uint32_t                       PWM_IMR1;           /**< Offset: 0x18 (R/   32) PWM Interrupt Mask Register 1 */
  __I   uint32_t                       PWM_ISR1;           /**< Offset: 0x1C (R/   32) PWM Interrupt Status Register 1 */
  __IO  uint32_t                       PWM_SCM;            /**< Offset: 0x20 (R/W  32) PWM Sync Channels Mode Register */
  __O   uint32_t                       PWM_DMAR;           /**< Offset: 0x24 ( /W  32) PWM DMA Register */
  __IO  uint32_t                       PWM_SCUC;           /**< Offset: 0x28 (R/W  32) PWM Sync Channels Update Control Register */
  __IO  uint32_t                       PWM_SCUP;           /**< Offset: 0x2C (R/W  32) PWM Sync Channels Update Period Register */
  __O   uint32_t                       PWM_SCUPUPD;        /**< Offset: 0x30 ( /W  32) PWM Sync Channels Update Period Update Register */
  __O   uint32_t                       PWM_IER2;           /**< Offset: 0x34 ( /W  32) PWM Interrupt Enable Register 2 */
  __O   uint32_t                       PWM_IDR2;           /**< Offset: 0x38 ( /W  32) PWM Interrupt Disable Register 2 */
  __I   uint32_t                       PWM_IMR2;           /**< Offset: 0x3C (R/   32) PWM Interrupt Mask Register 2 */
  __I   uint32_t                       PWM_ISR2;           /**< Offset: 0x40 (R/   32) PWM Interrupt Status Register 2 */
  __IO  uint32_t                       PWM_OOV;            /**< Offset: 0x44 (R/W  32) PWM Output Override Value Register */
  __IO  uint32_t                       PWM_OS;             /**< Offset: 0x48 (R/W  32) PWM Output Selection Register */
  __O   uint32_t                       PWM_OSS;            /**< Offset: 0x4C ( /W  32) PWM Output Selection Set Register */
  __O   uint32_t                       PWM_OSC;            /**< Offset: 0x50 ( /W  32) PWM Output Selection Clear Register */
  __O   uint32_t                       PWM_OSSUPD;         /**< Offset: 0x54 ( /W  32) PWM Output Selection Set Update Register */
  __O   uint32_t                       PWM_OSCUPD;         /**< Offset: 0x58 ( /W  32) PWM Output Selection Clear Update Register */
  __IO  uint32_t                       PWM_FMR;            /**< Offset: 0x5C (R/W  32) PWM Fault Mode Register */
  __I   uint32_t                       PWM_FSR;            /**< Offset: 0x60 (R/   32) PWM Fault Status Register */
  __O   uint32_t                       PWM_FCR;            /**< Offset: 0x64 ( /W  32) PWM Fault Clear Register */
  __IO  uint32_t                       PWM_FPV1;           /**< Offset: 0x68 (R/W  32) PWM Fault Protection Value Register 1 */
  __IO  uint32_t                       PWM_FPE;            /**< Offset: 0x6C (R/W  32) PWM Fault Protection Enable Register */
  __I   uint8_t                        Reserved1[0x0C];
  __IO  uint32_t                       PWM_ELMR[2];        /**< Offset: 0x7C (R/W  32) PWM Event Line x Mode Register */
  __I   uint8_t                        Reserved2[0x1C];
  __IO  uint32_t                       PWM_SSPR;           /**< Offset: 0xA0 (R/W  32) PWM Spread Spectrum Register */
  __O   uint32_t                       PWM_SSPUP;          /**< Offset: 0xA4 ( /W  32) PWM Spread Spectrum Update Register */
  __I   uint8_t                        Reserved3[0x08];
  __IO  uint32_t                       PWM_SMMR;           /**< Offset: 0xB0 (R/W  32) PWM Stepper Motor Mode Register */
  __I   uint8_t                        Reserved4[0x0C];
  __IO  uint32_t                       PWM_FPV2;           /**< Offset: 0xC0 (R/W  32) PWM Fault Protection Value 2 Register */
  __I   uint8_t                        Reserved5[0x20];
  __O   uint32_t                       PWM_WPCR;           /**< Offset: 0xE4 ( /W  32) PWM Write Protection Control Register */
  __I   uint32_t                       PWM_WPSR;           /**< Offset: 0xE8 (R/   32) PWM Write Protection Status Register */
  __I   uint8_t                        Reserved6[0x44];
        pwm_cmp_registers_t            PWM_CMP[PWM_CMP_NUMBER]; /**< Offset: 0x130  */
  __I   uint8_t                        Reserved7[0x50];
        pwm_ch_num_registers_t         PWM_CH_NUM[PWM_CH_NUM_NUMBER]; /**< Offset: 0x200  */
  __I   uint8_t                        Reserved8[0x180];
  __O   uint32_t                       PWM_CMUPD0;         /**< Offset: 0x400 ( /W  32) PWM Channel Mode Update Register (ch_num = 0) */
  __I   uint8_t                        Reserved9[0x1C];
  __O   uint32_t                       PWM_CMUPD1;         /**< Offset: 0x420 ( /W  32) PWM Channel Mode Update Register (ch_num = 1) */
  __I   uint8_t                        Reserved10[0x08];
  __IO  uint32_t                       PWM_ETRG1;          /**< Offset: 0x42C (R/W  32) PWM External Trigger Register 1 */
  __IO  uint32_t                       PWM_LEBR1;          /**< Offset: 0x430 (R/W  32) PWM Leading-Edge Blanking Register 1 */
  __I   uint8_t                        Reserved11[0x0C];
  __O   uint32_t                       PWM_CMUPD2;         /**< Offset: 0x440 ( /W  32) PWM Channel Mode Update Register (ch_num = 2) */
  __I   uint8_t                        Reserved12[0x08];
  __IO  uint32_t                       PWM_ETRG2;          /**< Offset: 0x44C (R/W  32) PWM External Trigger Register 2 */
  __IO  uint32_t                       PWM_LEBR2;          /**< Offset: 0x450 (R/W  32) PWM Leading-Edge Blanking Register 2 */
  __I   uint8_t                        Reserved13[0x0C];
  __O   uint32_t                       PWM_CMUPD3;         /**< Offset: 0x460 ( /W  32) PWM Channel Mode Update Register (ch_num = 3) */
} pwm_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAMA7G_PWM_COMPONENT_H_ */
