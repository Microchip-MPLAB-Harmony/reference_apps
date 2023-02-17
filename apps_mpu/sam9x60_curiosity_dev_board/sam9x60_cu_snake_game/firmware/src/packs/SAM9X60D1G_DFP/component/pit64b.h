/*
 * Component description for PIT64B
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

/* file generated from device description version 2022-01-05T08:53:32Z */
#ifndef _SAM9X_PIT64B_COMPONENT_H_
#define _SAM9X_PIT64B_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR PIT64B                                       */
/* ************************************************************************** */

/* -------- PIT64B_CR : (PIT64B Offset: 0x00) ( /W 32) Control Register -------- */
#define PIT64B_CR_START_Pos                   _UINT32_(0)                                          /* (PIT64B_CR) Start Timer Position */
#define PIT64B_CR_START_Msk                   (_UINT32_(0x1) << PIT64B_CR_START_Pos)               /* (PIT64B_CR) Start Timer Mask */
#define PIT64B_CR_START(value)                (PIT64B_CR_START_Msk & (_UINT32_(value) << PIT64B_CR_START_Pos)) /* Assigment of value for START in the PIT64B_CR register */
#define PIT64B_CR_SWRST_Pos                   _UINT32_(8)                                          /* (PIT64B_CR) Software Reset Position */
#define PIT64B_CR_SWRST_Msk                   (_UINT32_(0x1) << PIT64B_CR_SWRST_Pos)               /* (PIT64B_CR) Software Reset Mask */
#define PIT64B_CR_SWRST(value)                (PIT64B_CR_SWRST_Msk & (_UINT32_(value) << PIT64B_CR_SWRST_Pos)) /* Assigment of value for SWRST in the PIT64B_CR register */
#define PIT64B_CR_Msk                         _UINT32_(0x00000101)                                 /* (PIT64B_CR) Register Mask  */


/* -------- PIT64B_MR : (PIT64B Offset: 0x04) (R/W 32) Mode Register -------- */
#define PIT64B_MR_CONT_Pos                    _UINT32_(0)                                          /* (PIT64B_MR) Continuous Mode Position */
#define PIT64B_MR_CONT_Msk                    (_UINT32_(0x1) << PIT64B_MR_CONT_Pos)                /* (PIT64B_MR) Continuous Mode Mask */
#define PIT64B_MR_CONT(value)                 (PIT64B_MR_CONT_Msk & (_UINT32_(value) << PIT64B_MR_CONT_Pos)) /* Assigment of value for CONT in the PIT64B_MR register */
#define PIT64B_MR_SGCLK_Pos                   _UINT32_(3)                                          /* (PIT64B_MR) Generic Clock Selection Enable Position */
#define PIT64B_MR_SGCLK_Msk                   (_UINT32_(0x1) << PIT64B_MR_SGCLK_Pos)               /* (PIT64B_MR) Generic Clock Selection Enable Mask */
#define PIT64B_MR_SGCLK(value)                (PIT64B_MR_SGCLK_Msk & (_UINT32_(value) << PIT64B_MR_SGCLK_Pos)) /* Assigment of value for SGCLK in the PIT64B_MR register */
#define PIT64B_MR_SMOD_Pos                    _UINT32_(4)                                          /* (PIT64B_MR) Start Mode Position */
#define PIT64B_MR_SMOD_Msk                    (_UINT32_(0x1) << PIT64B_MR_SMOD_Pos)                /* (PIT64B_MR) Start Mode Mask */
#define PIT64B_MR_SMOD(value)                 (PIT64B_MR_SMOD_Msk & (_UINT32_(value) << PIT64B_MR_SMOD_Pos)) /* Assigment of value for SMOD in the PIT64B_MR register */
#define PIT64B_MR_PRESCALER_Pos               _UINT32_(8)                                          /* (PIT64B_MR) Prescaler Period Position */
#define PIT64B_MR_PRESCALER_Msk               (_UINT32_(0xF) << PIT64B_MR_PRESCALER_Pos)           /* (PIT64B_MR) Prescaler Period Mask */
#define PIT64B_MR_PRESCALER(value)            (PIT64B_MR_PRESCALER_Msk & (_UINT32_(value) << PIT64B_MR_PRESCALER_Pos)) /* Assigment of value for PRESCALER in the PIT64B_MR register */
#define PIT64B_MR_Msk                         _UINT32_(0x00000F19)                                 /* (PIT64B_MR) Register Mask  */


/* -------- PIT64B_LSBPR : (PIT64B Offset: 0x08) (R/W 32) LSB Period Register -------- */
#define PIT64B_LSBPR_LSBPERIOD_Pos            _UINT32_(0)                                          /* (PIT64B_LSBPR) 32 LSB of the Timer Period Position */
#define PIT64B_LSBPR_LSBPERIOD_Msk            (_UINT32_(0xFFFFFFFF) << PIT64B_LSBPR_LSBPERIOD_Pos) /* (PIT64B_LSBPR) 32 LSB of the Timer Period Mask */
#define PIT64B_LSBPR_LSBPERIOD(value)         (PIT64B_LSBPR_LSBPERIOD_Msk & (_UINT32_(value) << PIT64B_LSBPR_LSBPERIOD_Pos)) /* Assigment of value for LSBPERIOD in the PIT64B_LSBPR register */
#define PIT64B_LSBPR_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (PIT64B_LSBPR) Register Mask  */


/* -------- PIT64B_MSBPR : (PIT64B Offset: 0x0C) (R/W 32) MSB Period Register -------- */
#define PIT64B_MSBPR_MSBPERIOD_Pos            _UINT32_(0)                                          /* (PIT64B_MSBPR) 32 MSB of the Timer Period Position */
#define PIT64B_MSBPR_MSBPERIOD_Msk            (_UINT32_(0xFFFFFFFF) << PIT64B_MSBPR_MSBPERIOD_Pos) /* (PIT64B_MSBPR) 32 MSB of the Timer Period Mask */
#define PIT64B_MSBPR_MSBPERIOD(value)         (PIT64B_MSBPR_MSBPERIOD_Msk & (_UINT32_(value) << PIT64B_MSBPR_MSBPERIOD_Pos)) /* Assigment of value for MSBPERIOD in the PIT64B_MSBPR register */
#define PIT64B_MSBPR_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (PIT64B_MSBPR) Register Mask  */


/* -------- PIT64B_IER : (PIT64B Offset: 0x10) ( /W 32) Interrupt Enable Register -------- */
#define PIT64B_IER_PERIOD_Pos                 _UINT32_(0)                                          /* (PIT64B_IER) Elapsed Timer Period Interrupt Enable Position */
#define PIT64B_IER_PERIOD_Msk                 (_UINT32_(0x1) << PIT64B_IER_PERIOD_Pos)             /* (PIT64B_IER) Elapsed Timer Period Interrupt Enable Mask */
#define PIT64B_IER_PERIOD(value)              (PIT64B_IER_PERIOD_Msk & (_UINT32_(value) << PIT64B_IER_PERIOD_Pos)) /* Assigment of value for PERIOD in the PIT64B_IER register */
#define PIT64B_IER_OVRE_Pos                   _UINT32_(1)                                          /* (PIT64B_IER) Overrun Error Interrupt Enable Position */
#define PIT64B_IER_OVRE_Msk                   (_UINT32_(0x1) << PIT64B_IER_OVRE_Pos)               /* (PIT64B_IER) Overrun Error Interrupt Enable Mask */
#define PIT64B_IER_OVRE(value)                (PIT64B_IER_OVRE_Msk & (_UINT32_(value) << PIT64B_IER_OVRE_Pos)) /* Assigment of value for OVRE in the PIT64B_IER register */
#define PIT64B_IER_SECE_Pos                   _UINT32_(4)                                          /* (PIT64B_IER) Safety and/or Security Report Interrupt Enable Position */
#define PIT64B_IER_SECE_Msk                   (_UINT32_(0x1) << PIT64B_IER_SECE_Pos)               /* (PIT64B_IER) Safety and/or Security Report Interrupt Enable Mask */
#define PIT64B_IER_SECE(value)                (PIT64B_IER_SECE_Msk & (_UINT32_(value) << PIT64B_IER_SECE_Pos)) /* Assigment of value for SECE in the PIT64B_IER register */
#define PIT64B_IER_Msk                        _UINT32_(0x00000013)                                 /* (PIT64B_IER) Register Mask  */


/* -------- PIT64B_IDR : (PIT64B Offset: 0x14) ( /W 32) Interrupt Disable Register -------- */
#define PIT64B_IDR_PERIOD_Pos                 _UINT32_(0)                                          /* (PIT64B_IDR) Elapsed Timer Period Interrupt Disable Position */
#define PIT64B_IDR_PERIOD_Msk                 (_UINT32_(0x1) << PIT64B_IDR_PERIOD_Pos)             /* (PIT64B_IDR) Elapsed Timer Period Interrupt Disable Mask */
#define PIT64B_IDR_PERIOD(value)              (PIT64B_IDR_PERIOD_Msk & (_UINT32_(value) << PIT64B_IDR_PERIOD_Pos)) /* Assigment of value for PERIOD in the PIT64B_IDR register */
#define PIT64B_IDR_OVRE_Pos                   _UINT32_(1)                                          /* (PIT64B_IDR) Overrun Error Interrupt Disable Position */
#define PIT64B_IDR_OVRE_Msk                   (_UINT32_(0x1) << PIT64B_IDR_OVRE_Pos)               /* (PIT64B_IDR) Overrun Error Interrupt Disable Mask */
#define PIT64B_IDR_OVRE(value)                (PIT64B_IDR_OVRE_Msk & (_UINT32_(value) << PIT64B_IDR_OVRE_Pos)) /* Assigment of value for OVRE in the PIT64B_IDR register */
#define PIT64B_IDR_SECE_Pos                   _UINT32_(4)                                          /* (PIT64B_IDR) Safety and/or Security Report Interrupt Disable Position */
#define PIT64B_IDR_SECE_Msk                   (_UINT32_(0x1) << PIT64B_IDR_SECE_Pos)               /* (PIT64B_IDR) Safety and/or Security Report Interrupt Disable Mask */
#define PIT64B_IDR_SECE(value)                (PIT64B_IDR_SECE_Msk & (_UINT32_(value) << PIT64B_IDR_SECE_Pos)) /* Assigment of value for SECE in the PIT64B_IDR register */
#define PIT64B_IDR_Msk                        _UINT32_(0x00000013)                                 /* (PIT64B_IDR) Register Mask  */


/* -------- PIT64B_IMR : (PIT64B Offset: 0x18) ( R/ 32) Interrupt Mask Register -------- */
#define PIT64B_IMR_PERIOD_Pos                 _UINT32_(0)                                          /* (PIT64B_IMR) Elapsed Timer Period Interrupt Mask Position */
#define PIT64B_IMR_PERIOD_Msk                 (_UINT32_(0x1) << PIT64B_IMR_PERIOD_Pos)             /* (PIT64B_IMR) Elapsed Timer Period Interrupt Mask Mask */
#define PIT64B_IMR_PERIOD(value)              (PIT64B_IMR_PERIOD_Msk & (_UINT32_(value) << PIT64B_IMR_PERIOD_Pos)) /* Assigment of value for PERIOD in the PIT64B_IMR register */
#define PIT64B_IMR_OVRE_Pos                   _UINT32_(1)                                          /* (PIT64B_IMR) Overrun Error Interrupt Mask Position */
#define PIT64B_IMR_OVRE_Msk                   (_UINT32_(0x1) << PIT64B_IMR_OVRE_Pos)               /* (PIT64B_IMR) Overrun Error Interrupt Mask Mask */
#define PIT64B_IMR_OVRE(value)                (PIT64B_IMR_OVRE_Msk & (_UINT32_(value) << PIT64B_IMR_OVRE_Pos)) /* Assigment of value for OVRE in the PIT64B_IMR register */
#define PIT64B_IMR_SECE_Pos                   _UINT32_(4)                                          /* (PIT64B_IMR) Safety and/or Security Report Interrupt Mask Position */
#define PIT64B_IMR_SECE_Msk                   (_UINT32_(0x1) << PIT64B_IMR_SECE_Pos)               /* (PIT64B_IMR) Safety and/or Security Report Interrupt Mask Mask */
#define PIT64B_IMR_SECE(value)                (PIT64B_IMR_SECE_Msk & (_UINT32_(value) << PIT64B_IMR_SECE_Pos)) /* Assigment of value for SECE in the PIT64B_IMR register */
#define PIT64B_IMR_Msk                        _UINT32_(0x00000013)                                 /* (PIT64B_IMR) Register Mask  */


/* -------- PIT64B_ISR : (PIT64B Offset: 0x1C) ( R/ 32) Interrupt Status Register -------- */
#define PIT64B_ISR_PERIOD_Pos                 _UINT32_(0)                                          /* (PIT64B_ISR) Elapsed Timer Period Status Flag (cleared on read) Position */
#define PIT64B_ISR_PERIOD_Msk                 (_UINT32_(0x1) << PIT64B_ISR_PERIOD_Pos)             /* (PIT64B_ISR) Elapsed Timer Period Status Flag (cleared on read) Mask */
#define PIT64B_ISR_PERIOD(value)              (PIT64B_ISR_PERIOD_Msk & (_UINT32_(value) << PIT64B_ISR_PERIOD_Pos)) /* Assigment of value for PERIOD in the PIT64B_ISR register */
#define PIT64B_ISR_OVRE_Pos                   _UINT32_(1)                                          /* (PIT64B_ISR) Overrun Error (cleared on read) Position */
#define PIT64B_ISR_OVRE_Msk                   (_UINT32_(0x1) << PIT64B_ISR_OVRE_Pos)               /* (PIT64B_ISR) Overrun Error (cleared on read) Mask */
#define PIT64B_ISR_OVRE(value)                (PIT64B_ISR_OVRE_Msk & (_UINT32_(value) << PIT64B_ISR_OVRE_Pos)) /* Assigment of value for OVRE in the PIT64B_ISR register */
#define PIT64B_ISR_SECE_Pos                   _UINT32_(4)                                          /* (PIT64B_ISR) Safety/Security Report (cleared on read) Position */
#define PIT64B_ISR_SECE_Msk                   (_UINT32_(0x1) << PIT64B_ISR_SECE_Pos)               /* (PIT64B_ISR) Safety/Security Report (cleared on read) Mask */
#define PIT64B_ISR_SECE(value)                (PIT64B_ISR_SECE_Msk & (_UINT32_(value) << PIT64B_ISR_SECE_Pos)) /* Assigment of value for SECE in the PIT64B_ISR register */
#define PIT64B_ISR_Msk                        _UINT32_(0x00000013)                                 /* (PIT64B_ISR) Register Mask  */


/* -------- PIT64B_TLSBR : (PIT64B Offset: 0x20) ( R/ 32) Timer LSB Current Value Register -------- */
#define PIT64B_TLSBR_LSBTIMER_Pos             _UINT32_(0)                                          /* (PIT64B_TLSBR) Current 32 LSB of the Timer Position */
#define PIT64B_TLSBR_LSBTIMER_Msk             (_UINT32_(0xFFFFFFFF) << PIT64B_TLSBR_LSBTIMER_Pos)  /* (PIT64B_TLSBR) Current 32 LSB of the Timer Mask */
#define PIT64B_TLSBR_LSBTIMER(value)          (PIT64B_TLSBR_LSBTIMER_Msk & (_UINT32_(value) << PIT64B_TLSBR_LSBTIMER_Pos)) /* Assigment of value for LSBTIMER in the PIT64B_TLSBR register */
#define PIT64B_TLSBR_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (PIT64B_TLSBR) Register Mask  */


/* -------- PIT64B_TMSBR : (PIT64B Offset: 0x24) ( R/ 32) Timer MSB Current Value Register -------- */
#define PIT64B_TMSBR_MSBTIMER_Pos             _UINT32_(0)                                          /* (PIT64B_TMSBR) Current 32 MSB of the Timer Position */
#define PIT64B_TMSBR_MSBTIMER_Msk             (_UINT32_(0xFFFFFFFF) << PIT64B_TMSBR_MSBTIMER_Pos)  /* (PIT64B_TMSBR) Current 32 MSB of the Timer Mask */
#define PIT64B_TMSBR_MSBTIMER(value)          (PIT64B_TMSBR_MSBTIMER_Msk & (_UINT32_(value) << PIT64B_TMSBR_MSBTIMER_Pos)) /* Assigment of value for MSBTIMER in the PIT64B_TMSBR register */
#define PIT64B_TMSBR_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (PIT64B_TMSBR) Register Mask  */


/* -------- PIT64B_WPMR : (PIT64B Offset: 0xE4) (R/W 32) Write Protection Mode Register -------- */
#define PIT64B_WPMR_WPEN_Pos                  _UINT32_(0)                                          /* (PIT64B_WPMR) Write Protection Enable Position */
#define PIT64B_WPMR_WPEN_Msk                  (_UINT32_(0x1) << PIT64B_WPMR_WPEN_Pos)              /* (PIT64B_WPMR) Write Protection Enable Mask */
#define PIT64B_WPMR_WPEN(value)               (PIT64B_WPMR_WPEN_Msk & (_UINT32_(value) << PIT64B_WPMR_WPEN_Pos)) /* Assigment of value for WPEN in the PIT64B_WPMR register */
#define PIT64B_WPMR_WPITEN_Pos                _UINT32_(1)                                          /* (PIT64B_WPMR) Write Protection Interruption Enable Position */
#define PIT64B_WPMR_WPITEN_Msk                (_UINT32_(0x1) << PIT64B_WPMR_WPITEN_Pos)            /* (PIT64B_WPMR) Write Protection Interruption Enable Mask */
#define PIT64B_WPMR_WPITEN(value)             (PIT64B_WPMR_WPITEN_Msk & (_UINT32_(value) << PIT64B_WPMR_WPITEN_Pos)) /* Assigment of value for WPITEN in the PIT64B_WPMR register */
#define PIT64B_WPMR_WPCREN_Pos                _UINT32_(2)                                          /* (PIT64B_WPMR) Write Protection Control Enable Position */
#define PIT64B_WPMR_WPCREN_Msk                (_UINT32_(0x1) << PIT64B_WPMR_WPCREN_Pos)            /* (PIT64B_WPMR) Write Protection Control Enable Mask */
#define PIT64B_WPMR_WPCREN(value)             (PIT64B_WPMR_WPCREN_Msk & (_UINT32_(value) << PIT64B_WPMR_WPCREN_Pos)) /* Assigment of value for WPCREN in the PIT64B_WPMR register */
#define PIT64B_WPMR_FIRSTE_Pos                _UINT32_(4)                                          /* (PIT64B_WPMR) First Error Report Enable Position */
#define PIT64B_WPMR_FIRSTE_Msk                (_UINT32_(0x1) << PIT64B_WPMR_FIRSTE_Pos)            /* (PIT64B_WPMR) First Error Report Enable Mask */
#define PIT64B_WPMR_FIRSTE(value)             (PIT64B_WPMR_FIRSTE_Msk & (_UINT32_(value) << PIT64B_WPMR_FIRSTE_Pos)) /* Assigment of value for FIRSTE in the PIT64B_WPMR register */
#define PIT64B_WPMR_WPKEY_Pos                 _UINT32_(8)                                          /* (PIT64B_WPMR) Write Protection Key Position */
#define PIT64B_WPMR_WPKEY_Msk                 (_UINT32_(0xFFFFFF) << PIT64B_WPMR_WPKEY_Pos)        /* (PIT64B_WPMR) Write Protection Key Mask */
#define PIT64B_WPMR_WPKEY(value)              (PIT64B_WPMR_WPKEY_Msk & (_UINT32_(value) << PIT64B_WPMR_WPKEY_Pos)) /* Assigment of value for WPKEY in the PIT64B_WPMR register */
#define   PIT64B_WPMR_WPKEY_PASSWD_Val        _UINT32_(0x504954)                                   /* (PIT64B_WPMR) Writing any other value in this field aborts the write operation of the WPCREN, WPITEN and WPEN bits. Always reads as 0.  */
#define PIT64B_WPMR_WPKEY_PASSWD              (PIT64B_WPMR_WPKEY_PASSWD_Val << PIT64B_WPMR_WPKEY_Pos) /* (PIT64B_WPMR) Writing any other value in this field aborts the write operation of the WPCREN, WPITEN and WPEN bits. Always reads as 0. Position  */
#define PIT64B_WPMR_Msk                       _UINT32_(0xFFFFFF17)                                 /* (PIT64B_WPMR) Register Mask  */


/* -------- PIT64B_WPSR : (PIT64B Offset: 0xE8) ( R/ 32) Write Protection Status Register -------- */
#define PIT64B_WPSR_WPVS_Pos                  _UINT32_(0)                                          /* (PIT64B_WPSR) Write Protection Violation Status (cleared on read) Position */
#define PIT64B_WPSR_WPVS_Msk                  (_UINT32_(0x1) << PIT64B_WPSR_WPVS_Pos)              /* (PIT64B_WPSR) Write Protection Violation Status (cleared on read) Mask */
#define PIT64B_WPSR_WPVS(value)               (PIT64B_WPSR_WPVS_Msk & (_UINT32_(value) << PIT64B_WPSR_WPVS_Pos)) /* Assigment of value for WPVS in the PIT64B_WPSR register */
#define PIT64B_WPSR_CGD_Pos                   _UINT32_(1)                                          /* (PIT64B_WPSR) Clock Glitch Detected (cleared on read) Position */
#define PIT64B_WPSR_CGD_Msk                   (_UINT32_(0x1) << PIT64B_WPSR_CGD_Pos)               /* (PIT64B_WPSR) Clock Glitch Detected (cleared on read) Mask */
#define PIT64B_WPSR_CGD(value)                (PIT64B_WPSR_CGD_Msk & (_UINT32_(value) << PIT64B_WPSR_CGD_Pos)) /* Assigment of value for CGD in the PIT64B_WPSR register */
#define PIT64B_WPSR_SEQE_Pos                  _UINT32_(2)                                          /* (PIT64B_WPSR) Internal Sequencer Error (cleared on read) Position */
#define PIT64B_WPSR_SEQE_Msk                  (_UINT32_(0x1) << PIT64B_WPSR_SEQE_Pos)              /* (PIT64B_WPSR) Internal Sequencer Error (cleared on read) Mask */
#define PIT64B_WPSR_SEQE(value)               (PIT64B_WPSR_SEQE_Msk & (_UINT32_(value) << PIT64B_WPSR_SEQE_Pos)) /* Assigment of value for SEQE in the PIT64B_WPSR register */
#define PIT64B_WPSR_SWE_Pos                   _UINT32_(3)                                          /* (PIT64B_WPSR) Software Control Error (cleared on read) Position */
#define PIT64B_WPSR_SWE_Msk                   (_UINT32_(0x1) << PIT64B_WPSR_SWE_Pos)               /* (PIT64B_WPSR) Software Control Error (cleared on read) Mask */
#define PIT64B_WPSR_SWE(value)                (PIT64B_WPSR_SWE_Msk & (_UINT32_(value) << PIT64B_WPSR_SWE_Pos)) /* Assigment of value for SWE in the PIT64B_WPSR register */
#define PIT64B_WPSR_WPVSRC_Pos                _UINT32_(8)                                          /* (PIT64B_WPSR) Write Protection Violation Source Position */
#define PIT64B_WPSR_WPVSRC_Msk                (_UINT32_(0xFFFF) << PIT64B_WPSR_WPVSRC_Pos)         /* (PIT64B_WPSR) Write Protection Violation Source Mask */
#define PIT64B_WPSR_WPVSRC(value)             (PIT64B_WPSR_WPVSRC_Msk & (_UINT32_(value) << PIT64B_WPSR_WPVSRC_Pos)) /* Assigment of value for WPVSRC in the PIT64B_WPSR register */
#define PIT64B_WPSR_SWETYP_Pos                _UINT32_(24)                                         /* (PIT64B_WPSR) Software Error Type (cleared on read) Position */
#define PIT64B_WPSR_SWETYP_Msk                (_UINT32_(0x3) << PIT64B_WPSR_SWETYP_Pos)            /* (PIT64B_WPSR) Software Error Type (cleared on read) Mask */
#define PIT64B_WPSR_SWETYP(value)             (PIT64B_WPSR_SWETYP_Msk & (_UINT32_(value) << PIT64B_WPSR_SWETYP_Pos)) /* Assigment of value for SWETYP in the PIT64B_WPSR register */
#define   PIT64B_WPSR_SWETYP_READ_WO_Val      _UINT32_(0x0)                                        /* (PIT64B_WPSR) A write-only register has been read (warning).  */
#define   PIT64B_WPSR_SWETYP_WRITE_RO_Val     _UINT32_(0x1)                                        /* (PIT64B_WPSR) A write access has been performed on a read-only register (Warning).  */
#define   PIT64B_WPSR_SWETYP_UNDEF_RW_Val     _UINT32_(0x2)                                        /* (PIT64B_WPSR) Access to an undefined address (warning).  */
#define   PIT64B_WPSR_SWETYP_WEIRD_ACTION_Val _UINT32_(0x3)                                        /* (PIT64B_WPSR) A write access is performed into PIT64B_MR, PIT64B_LSBR, PIT64B_MSBR while the PIT64B is running (abnormal).  */
#define PIT64B_WPSR_SWETYP_READ_WO            (PIT64B_WPSR_SWETYP_READ_WO_Val << PIT64B_WPSR_SWETYP_Pos) /* (PIT64B_WPSR) A write-only register has been read (warning). Position  */
#define PIT64B_WPSR_SWETYP_WRITE_RO           (PIT64B_WPSR_SWETYP_WRITE_RO_Val << PIT64B_WPSR_SWETYP_Pos) /* (PIT64B_WPSR) A write access has been performed on a read-only register (Warning). Position  */
#define PIT64B_WPSR_SWETYP_UNDEF_RW           (PIT64B_WPSR_SWETYP_UNDEF_RW_Val << PIT64B_WPSR_SWETYP_Pos) /* (PIT64B_WPSR) Access to an undefined address (warning). Position  */
#define PIT64B_WPSR_SWETYP_WEIRD_ACTION       (PIT64B_WPSR_SWETYP_WEIRD_ACTION_Val << PIT64B_WPSR_SWETYP_Pos) /* (PIT64B_WPSR) A write access is performed into PIT64B_MR, PIT64B_LSBR, PIT64B_MSBR while the PIT64B is running (abnormal). Position  */
#define PIT64B_WPSR_ECLASS_Pos                _UINT32_(31)                                         /* (PIT64B_WPSR) Software Error Class (cleared on read) Position */
#define PIT64B_WPSR_ECLASS_Msk                (_UINT32_(0x1) << PIT64B_WPSR_ECLASS_Pos)            /* (PIT64B_WPSR) Software Error Class (cleared on read) Mask */
#define PIT64B_WPSR_ECLASS(value)             (PIT64B_WPSR_ECLASS_Msk & (_UINT32_(value) << PIT64B_WPSR_ECLASS_Pos)) /* Assigment of value for ECLASS in the PIT64B_WPSR register */
#define   PIT64B_WPSR_ECLASS_WARNING_Val      _UINT32_(0x0)                                        /* (PIT64B_WPSR) An abnormal access that does not affect system functionality.  */
#define   PIT64B_WPSR_ECLASS_ERROR_Val        _UINT32_(0x1)                                        /* (PIT64B_WPSR) A write access is performed into PIT64B_MR, PIT64B_LSBR, PIT64B_MSBR while the PIT64B is running.  */
#define PIT64B_WPSR_ECLASS_WARNING            (PIT64B_WPSR_ECLASS_WARNING_Val << PIT64B_WPSR_ECLASS_Pos) /* (PIT64B_WPSR) An abnormal access that does not affect system functionality. Position  */
#define PIT64B_WPSR_ECLASS_ERROR              (PIT64B_WPSR_ECLASS_ERROR_Val << PIT64B_WPSR_ECLASS_Pos) /* (PIT64B_WPSR) A write access is performed into PIT64B_MR, PIT64B_LSBR, PIT64B_MSBR while the PIT64B is running. Position  */
#define PIT64B_WPSR_Msk                       _UINT32_(0x83FFFF0F)                                 /* (PIT64B_WPSR) Register Mask  */


/** \brief PIT64B register offsets definitions */
#define PIT64B_CR_REG_OFST             _UINT32_(0x00)      /* (PIT64B_CR) Control Register Offset */
#define PIT64B_MR_REG_OFST             _UINT32_(0x04)      /* (PIT64B_MR) Mode Register Offset */
#define PIT64B_LSBPR_REG_OFST          _UINT32_(0x08)      /* (PIT64B_LSBPR) LSB Period Register Offset */
#define PIT64B_MSBPR_REG_OFST          _UINT32_(0x0C)      /* (PIT64B_MSBPR) MSB Period Register Offset */
#define PIT64B_IER_REG_OFST            _UINT32_(0x10)      /* (PIT64B_IER) Interrupt Enable Register Offset */
#define PIT64B_IDR_REG_OFST            _UINT32_(0x14)      /* (PIT64B_IDR) Interrupt Disable Register Offset */
#define PIT64B_IMR_REG_OFST            _UINT32_(0x18)      /* (PIT64B_IMR) Interrupt Mask Register Offset */
#define PIT64B_ISR_REG_OFST            _UINT32_(0x1C)      /* (PIT64B_ISR) Interrupt Status Register Offset */
#define PIT64B_TLSBR_REG_OFST          _UINT32_(0x20)      /* (PIT64B_TLSBR) Timer LSB Current Value Register Offset */
#define PIT64B_TMSBR_REG_OFST          _UINT32_(0x24)      /* (PIT64B_TMSBR) Timer MSB Current Value Register Offset */
#define PIT64B_WPMR_REG_OFST           _UINT32_(0xE4)      /* (PIT64B_WPMR) Write Protection Mode Register Offset */
#define PIT64B_WPSR_REG_OFST           _UINT32_(0xE8)      /* (PIT64B_WPSR) Write Protection Status Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief PIT64B register API structure */
typedef struct
{
  __O   uint32_t                       PIT64B_CR;          /**< Offset: 0x00 ( /W  32) Control Register */
  __IO  uint32_t                       PIT64B_MR;          /**< Offset: 0x04 (R/W  32) Mode Register */
  __IO  uint32_t                       PIT64B_LSBPR;       /**< Offset: 0x08 (R/W  32) LSB Period Register */
  __IO  uint32_t                       PIT64B_MSBPR;       /**< Offset: 0x0C (R/W  32) MSB Period Register */
  __O   uint32_t                       PIT64B_IER;         /**< Offset: 0x10 ( /W  32) Interrupt Enable Register */
  __O   uint32_t                       PIT64B_IDR;         /**< Offset: 0x14 ( /W  32) Interrupt Disable Register */
  __I   uint32_t                       PIT64B_IMR;         /**< Offset: 0x18 (R/   32) Interrupt Mask Register */
  __I   uint32_t                       PIT64B_ISR;         /**< Offset: 0x1C (R/   32) Interrupt Status Register */
  __I   uint32_t                       PIT64B_TLSBR;       /**< Offset: 0x20 (R/   32) Timer LSB Current Value Register */
  __I   uint32_t                       PIT64B_TMSBR;       /**< Offset: 0x24 (R/   32) Timer MSB Current Value Register */
  __I   uint8_t                        Reserved1[0xBC];
  __IO  uint32_t                       PIT64B_WPMR;        /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
  __I   uint32_t                       PIT64B_WPSR;        /**< Offset: 0xE8 (R/   32) Write Protection Status Register */
} pit64b_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAM9X_PIT64B_COMPONENT_H_ */
