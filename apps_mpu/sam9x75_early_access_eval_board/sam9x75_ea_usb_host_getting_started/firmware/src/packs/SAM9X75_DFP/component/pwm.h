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

/* file generated from device description version 2023-01-20T08:33:42Z */
#ifndef _SAM9X7_PWM_COMPONENT_H_
#define _SAM9X7_PWM_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR PWM                                          */
/* ************************************************************************** */

/* -------- PWM_CMR : (PWM Offset: 0x00) (R/W 32) PWM Channel Mode Register  -------- */
#define PWM_CMR_RESETVALUE                    _UINT32_(0x00)                                       /*  (PWM_CMR) PWM Channel Mode Register   Reset Value */

#define PWM_CMR_CPRE_Pos                      _UINT32_(0)                                          /* (PWM_CMR) Channel Prescaler Position */
#define PWM_CMR_CPRE_Msk                      (_UINT32_(0xF) << PWM_CMR_CPRE_Pos)                  /* (PWM_CMR) Channel Prescaler Mask */
#define PWM_CMR_CPRE(value)                   (PWM_CMR_CPRE_Msk & (_UINT32_(value) << PWM_CMR_CPRE_Pos)) /* Assigment of value for CPRE in the PWM_CMR register */
#define   PWM_CMR_CPRE_MCK_Val                _UINT32_(0x0)                                        /* (PWM_CMR) Peripheral clock  */
#define   PWM_CMR_CPRE_MCKDIV2_Val            _UINT32_(0x1)                                        /* (PWM_CMR) Peripheral clock divided by 2  */
#define   PWM_CMR_CPRE_MCKDIV4_Val            _UINT32_(0x2)                                        /* (PWM_CMR) Peripheral clock divided by 4  */
#define   PWM_CMR_CPRE_MCKDIV8_Val            _UINT32_(0x3)                                        /* (PWM_CMR) Peripheral clock divided by 8  */
#define   PWM_CMR_CPRE_MCKDIV16_Val           _UINT32_(0x4)                                        /* (PWM_CMR) Peripheral clock divided by 16  */
#define   PWM_CMR_CPRE_MCKDIV32_Val           _UINT32_(0x5)                                        /* (PWM_CMR) Peripheral clock divided by 32  */
#define   PWM_CMR_CPRE_MCKDIV64_Val           _UINT32_(0x6)                                        /* (PWM_CMR) Peripheral clock divided by 64  */
#define   PWM_CMR_CPRE_MCKDIV128_Val          _UINT32_(0x7)                                        /* (PWM_CMR) Peripheral clock divided by 128  */
#define   PWM_CMR_CPRE_MCKDIV256_Val          _UINT32_(0x8)                                        /* (PWM_CMR) Peripheral clock divided by 256  */
#define   PWM_CMR_CPRE_MCKDIV512_Val          _UINT32_(0x9)                                        /* (PWM_CMR) Peripheral clock divided by 512  */
#define   PWM_CMR_CPRE_MCKDIV1024_Val         _UINT32_(0xA)                                        /* (PWM_CMR) Peripheral clock divided by 1024  */
#define   PWM_CMR_CPRE_CLKA_Val               _UINT32_(0xB)                                        /* (PWM_CMR) Clock A  */
#define   PWM_CMR_CPRE_CLKB_Val               _UINT32_(0xC)                                        /* (PWM_CMR) Clock B  */
#define PWM_CMR_CPRE_MCK                      (PWM_CMR_CPRE_MCK_Val << PWM_CMR_CPRE_Pos)           /* (PWM_CMR) Peripheral clock Position  */
#define PWM_CMR_CPRE_MCKDIV2                  (PWM_CMR_CPRE_MCKDIV2_Val << PWM_CMR_CPRE_Pos)       /* (PWM_CMR) Peripheral clock divided by 2 Position  */
#define PWM_CMR_CPRE_MCKDIV4                  (PWM_CMR_CPRE_MCKDIV4_Val << PWM_CMR_CPRE_Pos)       /* (PWM_CMR) Peripheral clock divided by 4 Position  */
#define PWM_CMR_CPRE_MCKDIV8                  (PWM_CMR_CPRE_MCKDIV8_Val << PWM_CMR_CPRE_Pos)       /* (PWM_CMR) Peripheral clock divided by 8 Position  */
#define PWM_CMR_CPRE_MCKDIV16                 (PWM_CMR_CPRE_MCKDIV16_Val << PWM_CMR_CPRE_Pos)      /* (PWM_CMR) Peripheral clock divided by 16 Position  */
#define PWM_CMR_CPRE_MCKDIV32                 (PWM_CMR_CPRE_MCKDIV32_Val << PWM_CMR_CPRE_Pos)      /* (PWM_CMR) Peripheral clock divided by 32 Position  */
#define PWM_CMR_CPRE_MCKDIV64                 (PWM_CMR_CPRE_MCKDIV64_Val << PWM_CMR_CPRE_Pos)      /* (PWM_CMR) Peripheral clock divided by 64 Position  */
#define PWM_CMR_CPRE_MCKDIV128                (PWM_CMR_CPRE_MCKDIV128_Val << PWM_CMR_CPRE_Pos)     /* (PWM_CMR) Peripheral clock divided by 128 Position  */
#define PWM_CMR_CPRE_MCKDIV256                (PWM_CMR_CPRE_MCKDIV256_Val << PWM_CMR_CPRE_Pos)     /* (PWM_CMR) Peripheral clock divided by 256 Position  */
#define PWM_CMR_CPRE_MCKDIV512                (PWM_CMR_CPRE_MCKDIV512_Val << PWM_CMR_CPRE_Pos)     /* (PWM_CMR) Peripheral clock divided by 512 Position  */
#define PWM_CMR_CPRE_MCKDIV1024               (PWM_CMR_CPRE_MCKDIV1024_Val << PWM_CMR_CPRE_Pos)    /* (PWM_CMR) Peripheral clock divided by 1024 Position  */
#define PWM_CMR_CPRE_CLKA                     (PWM_CMR_CPRE_CLKA_Val << PWM_CMR_CPRE_Pos)          /* (PWM_CMR) Clock A Position  */
#define PWM_CMR_CPRE_CLKB                     (PWM_CMR_CPRE_CLKB_Val << PWM_CMR_CPRE_Pos)          /* (PWM_CMR) Clock B Position  */
#define PWM_CMR_CALG_Pos                      _UINT32_(8)                                          /* (PWM_CMR) Channel Alignment Position */
#define PWM_CMR_CALG_Msk                      (_UINT32_(0x1) << PWM_CMR_CALG_Pos)                  /* (PWM_CMR) Channel Alignment Mask */
#define PWM_CMR_CALG(value)                   (PWM_CMR_CALG_Msk & (_UINT32_(value) << PWM_CMR_CALG_Pos)) /* Assigment of value for CALG in the PWM_CMR register */
#define   PWM_CMR_CALG_LEFT_ALIGNED_Val       _UINT32_(0x0)                                        /* (PWM_CMR) The period is left-aligned.  */
#define   PWM_CMR_CALG_CENTER_ALIGNED_Val     _UINT32_(0x1)                                        /* (PWM_CMR) The period is center-aligned.  */
#define PWM_CMR_CALG_LEFT_ALIGNED             (PWM_CMR_CALG_LEFT_ALIGNED_Val << PWM_CMR_CALG_Pos)  /* (PWM_CMR) The period is left-aligned. Position  */
#define PWM_CMR_CALG_CENTER_ALIGNED           (PWM_CMR_CALG_CENTER_ALIGNED_Val << PWM_CMR_CALG_Pos) /* (PWM_CMR) The period is center-aligned. Position  */
#define PWM_CMR_CPOL_Pos                      _UINT32_(9)                                          /* (PWM_CMR) Channel Polarity Position */
#define PWM_CMR_CPOL_Msk                      (_UINT32_(0x1) << PWM_CMR_CPOL_Pos)                  /* (PWM_CMR) Channel Polarity Mask */
#define PWM_CMR_CPOL(value)                   (PWM_CMR_CPOL_Msk & (_UINT32_(value) << PWM_CMR_CPOL_Pos)) /* Assigment of value for CPOL in the PWM_CMR register */
#define   PWM_CMR_CPOL_LOW_POLARITY_Val       _UINT32_(0x0)                                        /* (PWM_CMR) The output waveform starts at a low level.  */
#define   PWM_CMR_CPOL_HIGH_POLARITY_Val      _UINT32_(0x1)                                        /* (PWM_CMR) The output waveform starts at a high level.  */
#define PWM_CMR_CPOL_LOW_POLARITY             (PWM_CMR_CPOL_LOW_POLARITY_Val << PWM_CMR_CPOL_Pos)  /* (PWM_CMR) The output waveform starts at a low level. Position  */
#define PWM_CMR_CPOL_HIGH_POLARITY            (PWM_CMR_CPOL_HIGH_POLARITY_Val << PWM_CMR_CPOL_Pos) /* (PWM_CMR) The output waveform starts at a high level. Position  */
#define PWM_CMR_CPD_Pos                       _UINT32_(10)                                         /* (PWM_CMR) Channel Update Period Position */
#define PWM_CMR_CPD_Msk                       (_UINT32_(0x1) << PWM_CMR_CPD_Pos)                   /* (PWM_CMR) Channel Update Period Mask */
#define PWM_CMR_CPD(value)                    (PWM_CMR_CPD_Msk & (_UINT32_(value) << PWM_CMR_CPD_Pos)) /* Assigment of value for CPD in the PWM_CMR register */
#define   PWM_CMR_CPD_0_Val                   _UINT32_(0x0)                                        /* (PWM_CMR) Writing to PWM_CUPDx will modify the duty cycle at the next period start event.  */
#define   PWM_CMR_CPD_1_Val                   _UINT32_(0x1)                                        /* (PWM_CMR) Writing to PWM_CUPDx will modify the period at the next period start event.  */
#define PWM_CMR_CPD_0                         (PWM_CMR_CPD_0_Val << PWM_CMR_CPD_Pos)               /* (PWM_CMR) Writing to PWM_CUPDx will modify the duty cycle at the next period start event. Position  */
#define PWM_CMR_CPD_1                         (PWM_CMR_CPD_1_Val << PWM_CMR_CPD_Pos)               /* (PWM_CMR) Writing to PWM_CUPDx will modify the period at the next period start event. Position  */
#define PWM_CMR_Msk                           _UINT32_(0x0000070F)                                 /* (PWM_CMR) Register Mask  */


/* -------- PWM_CDTY : (PWM Offset: 0x04) (R/W 32) PWM Channel Duty Cycle Register  -------- */
#define PWM_CDTY_RESETVALUE                   _UINT32_(0x00)                                       /*  (PWM_CDTY) PWM Channel Duty Cycle Register   Reset Value */

#define PWM_CDTY_CDTY_Pos                     _UINT32_(0)                                          /* (PWM_CDTY) Channel Duty Cycle Position */
#define PWM_CDTY_CDTY_Msk                     (_UINT32_(0xFFFFFFFF) << PWM_CDTY_CDTY_Pos)          /* (PWM_CDTY) Channel Duty Cycle Mask */
#define PWM_CDTY_CDTY(value)                  (PWM_CDTY_CDTY_Msk & (_UINT32_(value) << PWM_CDTY_CDTY_Pos)) /* Assigment of value for CDTY in the PWM_CDTY register */
#define PWM_CDTY_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (PWM_CDTY) Register Mask  */


/* -------- PWM_CPRD : (PWM Offset: 0x08) (R/W 32) PWM Channel Period Register  -------- */
#define PWM_CPRD_RESETVALUE                   _UINT32_(0x00)                                       /*  (PWM_CPRD) PWM Channel Period Register   Reset Value */

#define PWM_CPRD_CPRD_Pos                     _UINT32_(0)                                          /* (PWM_CPRD) Channel Period Position */
#define PWM_CPRD_CPRD_Msk                     (_UINT32_(0xFFFFFFFF) << PWM_CPRD_CPRD_Pos)          /* (PWM_CPRD) Channel Period Mask */
#define PWM_CPRD_CPRD(value)                  (PWM_CPRD_CPRD_Msk & (_UINT32_(value) << PWM_CPRD_CPRD_Pos)) /* Assigment of value for CPRD in the PWM_CPRD register */
#define PWM_CPRD_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (PWM_CPRD) Register Mask  */


/* -------- PWM_CCNT : (PWM Offset: 0x0C) ( R/ 32) PWM Channel Counter Register  -------- */
#define PWM_CCNT_RESETVALUE                   _UINT32_(0x00)                                       /*  (PWM_CCNT) PWM Channel Counter Register   Reset Value */

#define PWM_CCNT_CNT_Pos                      _UINT32_(0)                                          /* (PWM_CCNT) Channel Counter Register Position */
#define PWM_CCNT_CNT_Msk                      (_UINT32_(0xFFFFFFFF) << PWM_CCNT_CNT_Pos)           /* (PWM_CCNT) Channel Counter Register Mask */
#define PWM_CCNT_CNT(value)                   (PWM_CCNT_CNT_Msk & (_UINT32_(value) << PWM_CCNT_CNT_Pos)) /* Assigment of value for CNT in the PWM_CCNT register */
#define PWM_CCNT_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (PWM_CCNT) Register Mask  */


/* -------- PWM_CUPD : (PWM Offset: 0x10) ( /W 32) PWM Channel Update Register  -------- */
#define PWM_CUPD_CUPD_Pos                     _UINT32_(0)                                          /* (PWM_CUPD) Channel Update Register Position */
#define PWM_CUPD_CUPD_Msk                     (_UINT32_(0xFFFFFFFF) << PWM_CUPD_CUPD_Pos)          /* (PWM_CUPD) Channel Update Register Mask */
#define PWM_CUPD_CUPD(value)                  (PWM_CUPD_CUPD_Msk & (_UINT32_(value) << PWM_CUPD_CUPD_Pos)) /* Assigment of value for CUPD in the PWM_CUPD register */
#define PWM_CUPD_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (PWM_CUPD) Register Mask  */


/* -------- PWM_MR : (PWM Offset: 0x00) (R/W 32) PWM Mode Register -------- */
#define PWM_MR_RESETVALUE                     _UINT32_(0x00)                                       /*  (PWM_MR) PWM Mode Register  Reset Value */

#define PWM_MR_DIVA_Pos                       _UINT32_(0)                                          /* (PWM_MR) CLKA Divide Factor Position */
#define PWM_MR_DIVA_Msk                       (_UINT32_(0xFF) << PWM_MR_DIVA_Pos)                  /* (PWM_MR) CLKA Divide Factor Mask */
#define PWM_MR_DIVA(value)                    (PWM_MR_DIVA_Msk & (_UINT32_(value) << PWM_MR_DIVA_Pos)) /* Assigment of value for DIVA in the PWM_MR register */
#define   PWM_MR_DIVA_CLK_OFF_Val             _UINT32_(0x0)                                        /* (PWM_MR) CLKA clock is turned off  */
#define   PWM_MR_DIVA_CLK_DIV1_Val            _UINT32_(0x1)                                        /* (PWM_MR) CLKA clock is clock selected by PREA  */
#define PWM_MR_DIVA_CLK_OFF                   (PWM_MR_DIVA_CLK_OFF_Val << PWM_MR_DIVA_Pos)         /* (PWM_MR) CLKA clock is turned off Position  */
#define PWM_MR_DIVA_CLK_DIV1                  (PWM_MR_DIVA_CLK_DIV1_Val << PWM_MR_DIVA_Pos)        /* (PWM_MR) CLKA clock is clock selected by PREA Position  */
#define PWM_MR_PREA_Pos                       _UINT32_(8)                                          /* (PWM_MR) CLKA Source Clock Selection Position */
#define PWM_MR_PREA_Msk                       (_UINT32_(0xF) << PWM_MR_PREA_Pos)                   /* (PWM_MR) CLKA Source Clock Selection Mask */
#define PWM_MR_PREA(value)                    (PWM_MR_PREA_Msk & (_UINT32_(value) << PWM_MR_PREA_Pos)) /* Assigment of value for PREA in the PWM_MR register */
#define   PWM_MR_PREA_MCK_Val                 _UINT32_(0x0)                                        /* (PWM_MR) Peripheral clock  */
#define   PWM_MR_PREA_MCKDIV2_Val             _UINT32_(0x1)                                        /* (PWM_MR) Peripheral clock divided by 2  */
#define   PWM_MR_PREA_MCKDIV4_Val             _UINT32_(0x2)                                        /* (PWM_MR) Peripheral clock divided by 4  */
#define   PWM_MR_PREA_MCKDIV8_Val             _UINT32_(0x3)                                        /* (PWM_MR) Peripheral clock divided by 8  */
#define   PWM_MR_PREA_MCKDIV16_Val            _UINT32_(0x4)                                        /* (PWM_MR) Peripheral clock divided by 16  */
#define   PWM_MR_PREA_MCKDIV32_Val            _UINT32_(0x5)                                        /* (PWM_MR) Peripheral clock divided by 32  */
#define   PWM_MR_PREA_MCKDIV64_Val            _UINT32_(0x6)                                        /* (PWM_MR) Peripheral clock divided by 64  */
#define   PWM_MR_PREA_MCKDIV128_Val           _UINT32_(0x7)                                        /* (PWM_MR) Peripheral clock divided by 128  */
#define   PWM_MR_PREA_MCKDIV256_Val           _UINT32_(0x8)                                        /* (PWM_MR) Peripheral clock divided by 256  */
#define   PWM_MR_PREA_MCKDIV512_Val           _UINT32_(0x9)                                        /* (PWM_MR) Peripheral clock divided by 512  */
#define   PWM_MR_PREA_MCKDIV1024_Val          _UINT32_(0xA)                                        /* (PWM_MR) Peripheral clock divided by 1024  */
#define PWM_MR_PREA_MCK                       (PWM_MR_PREA_MCK_Val << PWM_MR_PREA_Pos)             /* (PWM_MR) Peripheral clock Position  */
#define PWM_MR_PREA_MCKDIV2                   (PWM_MR_PREA_MCKDIV2_Val << PWM_MR_PREA_Pos)         /* (PWM_MR) Peripheral clock divided by 2 Position  */
#define PWM_MR_PREA_MCKDIV4                   (PWM_MR_PREA_MCKDIV4_Val << PWM_MR_PREA_Pos)         /* (PWM_MR) Peripheral clock divided by 4 Position  */
#define PWM_MR_PREA_MCKDIV8                   (PWM_MR_PREA_MCKDIV8_Val << PWM_MR_PREA_Pos)         /* (PWM_MR) Peripheral clock divided by 8 Position  */
#define PWM_MR_PREA_MCKDIV16                  (PWM_MR_PREA_MCKDIV16_Val << PWM_MR_PREA_Pos)        /* (PWM_MR) Peripheral clock divided by 16 Position  */
#define PWM_MR_PREA_MCKDIV32                  (PWM_MR_PREA_MCKDIV32_Val << PWM_MR_PREA_Pos)        /* (PWM_MR) Peripheral clock divided by 32 Position  */
#define PWM_MR_PREA_MCKDIV64                  (PWM_MR_PREA_MCKDIV64_Val << PWM_MR_PREA_Pos)        /* (PWM_MR) Peripheral clock divided by 64 Position  */
#define PWM_MR_PREA_MCKDIV128                 (PWM_MR_PREA_MCKDIV128_Val << PWM_MR_PREA_Pos)       /* (PWM_MR) Peripheral clock divided by 128 Position  */
#define PWM_MR_PREA_MCKDIV256                 (PWM_MR_PREA_MCKDIV256_Val << PWM_MR_PREA_Pos)       /* (PWM_MR) Peripheral clock divided by 256 Position  */
#define PWM_MR_PREA_MCKDIV512                 (PWM_MR_PREA_MCKDIV512_Val << PWM_MR_PREA_Pos)       /* (PWM_MR) Peripheral clock divided by 512 Position  */
#define PWM_MR_PREA_MCKDIV1024                (PWM_MR_PREA_MCKDIV1024_Val << PWM_MR_PREA_Pos)      /* (PWM_MR) Peripheral clock divided by 1024 Position  */
#define PWM_MR_DIVB_Pos                       _UINT32_(16)                                         /* (PWM_MR) CLKB Divide Factor Position */
#define PWM_MR_DIVB_Msk                       (_UINT32_(0xFF) << PWM_MR_DIVB_Pos)                  /* (PWM_MR) CLKB Divide Factor Mask */
#define PWM_MR_DIVB(value)                    (PWM_MR_DIVB_Msk & (_UINT32_(value) << PWM_MR_DIVB_Pos)) /* Assigment of value for DIVB in the PWM_MR register */
#define   PWM_MR_DIVB_CLK_OFF_Val             _UINT32_(0x0)                                        /* (PWM_MR) CLKB clock is turned off  */
#define   PWM_MR_DIVB_CLK_DIV1_Val            _UINT32_(0x1)                                        /* (PWM_MR) CLKB clock is clock selected by PREB  */
#define PWM_MR_DIVB_CLK_OFF                   (PWM_MR_DIVB_CLK_OFF_Val << PWM_MR_DIVB_Pos)         /* (PWM_MR) CLKB clock is turned off Position  */
#define PWM_MR_DIVB_CLK_DIV1                  (PWM_MR_DIVB_CLK_DIV1_Val << PWM_MR_DIVB_Pos)        /* (PWM_MR) CLKB clock is clock selected by PREB Position  */
#define PWM_MR_PREB_Pos                       _UINT32_(24)                                         /* (PWM_MR) CLKB Source Clock Selection Position */
#define PWM_MR_PREB_Msk                       (_UINT32_(0xF) << PWM_MR_PREB_Pos)                   /* (PWM_MR) CLKB Source Clock Selection Mask */
#define PWM_MR_PREB(value)                    (PWM_MR_PREB_Msk & (_UINT32_(value) << PWM_MR_PREB_Pos)) /* Assigment of value for PREB in the PWM_MR register */
#define   PWM_MR_PREB_MCK_Val                 _UINT32_(0x0)                                        /* (PWM_MR) Peripheral clock  */
#define   PWM_MR_PREB_MCKDIV2_Val             _UINT32_(0x1)                                        /* (PWM_MR) Peripheral clock divided by 2  */
#define   PWM_MR_PREB_MCKDIV4_Val             _UINT32_(0x2)                                        /* (PWM_MR) Peripheral clock divided by 4  */
#define   PWM_MR_PREB_MCKDIV8_Val             _UINT32_(0x3)                                        /* (PWM_MR) Peripheral clock divided by 8  */
#define   PWM_MR_PREB_MCKDIV16_Val            _UINT32_(0x4)                                        /* (PWM_MR) Peripheral clock divided by 16  */
#define   PWM_MR_PREB_MCKDIV32_Val            _UINT32_(0x5)                                        /* (PWM_MR) Peripheral clock divided by 32  */
#define   PWM_MR_PREB_MCKDIV64_Val            _UINT32_(0x6)                                        /* (PWM_MR) Peripheral clock divided by 64  */
#define   PWM_MR_PREB_MCKDIV128_Val           _UINT32_(0x7)                                        /* (PWM_MR) Peripheral clock divided by 128  */
#define   PWM_MR_PREB_MCKDIV256_Val           _UINT32_(0x8)                                        /* (PWM_MR) Peripheral clock divided by 256  */
#define   PWM_MR_PREB_MCKDIV512_Val           _UINT32_(0x9)                                        /* (PWM_MR) Peripheral clock divided by 512  */
#define   PWM_MR_PREB_MCKDIV1024_Val          _UINT32_(0xA)                                        /* (PWM_MR) Peripheral clock divided by 1024  */
#define PWM_MR_PREB_MCK                       (PWM_MR_PREB_MCK_Val << PWM_MR_PREB_Pos)             /* (PWM_MR) Peripheral clock Position  */
#define PWM_MR_PREB_MCKDIV2                   (PWM_MR_PREB_MCKDIV2_Val << PWM_MR_PREB_Pos)         /* (PWM_MR) Peripheral clock divided by 2 Position  */
#define PWM_MR_PREB_MCKDIV4                   (PWM_MR_PREB_MCKDIV4_Val << PWM_MR_PREB_Pos)         /* (PWM_MR) Peripheral clock divided by 4 Position  */
#define PWM_MR_PREB_MCKDIV8                   (PWM_MR_PREB_MCKDIV8_Val << PWM_MR_PREB_Pos)         /* (PWM_MR) Peripheral clock divided by 8 Position  */
#define PWM_MR_PREB_MCKDIV16                  (PWM_MR_PREB_MCKDIV16_Val << PWM_MR_PREB_Pos)        /* (PWM_MR) Peripheral clock divided by 16 Position  */
#define PWM_MR_PREB_MCKDIV32                  (PWM_MR_PREB_MCKDIV32_Val << PWM_MR_PREB_Pos)        /* (PWM_MR) Peripheral clock divided by 32 Position  */
#define PWM_MR_PREB_MCKDIV64                  (PWM_MR_PREB_MCKDIV64_Val << PWM_MR_PREB_Pos)        /* (PWM_MR) Peripheral clock divided by 64 Position  */
#define PWM_MR_PREB_MCKDIV128                 (PWM_MR_PREB_MCKDIV128_Val << PWM_MR_PREB_Pos)       /* (PWM_MR) Peripheral clock divided by 128 Position  */
#define PWM_MR_PREB_MCKDIV256                 (PWM_MR_PREB_MCKDIV256_Val << PWM_MR_PREB_Pos)       /* (PWM_MR) Peripheral clock divided by 256 Position  */
#define PWM_MR_PREB_MCKDIV512                 (PWM_MR_PREB_MCKDIV512_Val << PWM_MR_PREB_Pos)       /* (PWM_MR) Peripheral clock divided by 512 Position  */
#define PWM_MR_PREB_MCKDIV1024                (PWM_MR_PREB_MCKDIV1024_Val << PWM_MR_PREB_Pos)      /* (PWM_MR) Peripheral clock divided by 1024 Position  */
#define PWM_MR_Msk                            _UINT32_(0x0FFF0FFF)                                 /* (PWM_MR) Register Mask  */


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

/* -------- PWM_IER : (PWM Offset: 0x10) ( /W 32) PWM Interrupt Enable Register -------- */
#define PWM_IER_CHID0_Pos                     _UINT32_(0)                                          /* (PWM_IER) Channel ID Position */
#define PWM_IER_CHID0_Msk                     (_UINT32_(0x1) << PWM_IER_CHID0_Pos)                 /* (PWM_IER) Channel ID Mask */
#define PWM_IER_CHID0(value)                  (PWM_IER_CHID0_Msk & (_UINT32_(value) << PWM_IER_CHID0_Pos)) /* Assigment of value for CHID0 in the PWM_IER register */
#define   PWM_IER_CHID0_0_Val                 _UINT32_(0x0)                                        /* (PWM_IER) No effect.  */
#define   PWM_IER_CHID0_1_Val                 _UINT32_(0x1)                                        /* (PWM_IER) Enable interrupt for PWM channel x.  */
#define PWM_IER_CHID0_0                       (PWM_IER_CHID0_0_Val << PWM_IER_CHID0_Pos)           /* (PWM_IER) No effect. Position  */
#define PWM_IER_CHID0_1                       (PWM_IER_CHID0_1_Val << PWM_IER_CHID0_Pos)           /* (PWM_IER) Enable interrupt for PWM channel x. Position  */
#define PWM_IER_CHID1_Pos                     _UINT32_(1)                                          /* (PWM_IER) Channel ID Position */
#define PWM_IER_CHID1_Msk                     (_UINT32_(0x1) << PWM_IER_CHID1_Pos)                 /* (PWM_IER) Channel ID Mask */
#define PWM_IER_CHID1(value)                  (PWM_IER_CHID1_Msk & (_UINT32_(value) << PWM_IER_CHID1_Pos)) /* Assigment of value for CHID1 in the PWM_IER register */
#define   PWM_IER_CHID1_0_Val                 _UINT32_(0x0)                                        /* (PWM_IER) No effect.  */
#define   PWM_IER_CHID1_1_Val                 _UINT32_(0x1)                                        /* (PWM_IER) Enable interrupt for PWM channel x.  */
#define PWM_IER_CHID1_0                       (PWM_IER_CHID1_0_Val << PWM_IER_CHID1_Pos)           /* (PWM_IER) No effect. Position  */
#define PWM_IER_CHID1_1                       (PWM_IER_CHID1_1_Val << PWM_IER_CHID1_Pos)           /* (PWM_IER) Enable interrupt for PWM channel x. Position  */
#define PWM_IER_CHID2_Pos                     _UINT32_(2)                                          /* (PWM_IER) Channel ID Position */
#define PWM_IER_CHID2_Msk                     (_UINT32_(0x1) << PWM_IER_CHID2_Pos)                 /* (PWM_IER) Channel ID Mask */
#define PWM_IER_CHID2(value)                  (PWM_IER_CHID2_Msk & (_UINT32_(value) << PWM_IER_CHID2_Pos)) /* Assigment of value for CHID2 in the PWM_IER register */
#define   PWM_IER_CHID2_0_Val                 _UINT32_(0x0)                                        /* (PWM_IER) No effect.  */
#define   PWM_IER_CHID2_1_Val                 _UINT32_(0x1)                                        /* (PWM_IER) Enable interrupt for PWM channel x.  */
#define PWM_IER_CHID2_0                       (PWM_IER_CHID2_0_Val << PWM_IER_CHID2_Pos)           /* (PWM_IER) No effect. Position  */
#define PWM_IER_CHID2_1                       (PWM_IER_CHID2_1_Val << PWM_IER_CHID2_Pos)           /* (PWM_IER) Enable interrupt for PWM channel x. Position  */
#define PWM_IER_CHID3_Pos                     _UINT32_(3)                                          /* (PWM_IER) Channel ID Position */
#define PWM_IER_CHID3_Msk                     (_UINT32_(0x1) << PWM_IER_CHID3_Pos)                 /* (PWM_IER) Channel ID Mask */
#define PWM_IER_CHID3(value)                  (PWM_IER_CHID3_Msk & (_UINT32_(value) << PWM_IER_CHID3_Pos)) /* Assigment of value for CHID3 in the PWM_IER register */
#define   PWM_IER_CHID3_0_Val                 _UINT32_(0x0)                                        /* (PWM_IER) No effect.  */
#define   PWM_IER_CHID3_1_Val                 _UINT32_(0x1)                                        /* (PWM_IER) Enable interrupt for PWM channel x.  */
#define PWM_IER_CHID3_0                       (PWM_IER_CHID3_0_Val << PWM_IER_CHID3_Pos)           /* (PWM_IER) No effect. Position  */
#define PWM_IER_CHID3_1                       (PWM_IER_CHID3_1_Val << PWM_IER_CHID3_Pos)           /* (PWM_IER) Enable interrupt for PWM channel x. Position  */
#define PWM_IER_Msk                           _UINT32_(0x0000000F)                                 /* (PWM_IER) Register Mask  */

#define PWM_IER_CHID_Pos                      _UINT32_(0)                                          /* (PWM_IER Position) Channel ID */
#define PWM_IER_CHID_Msk                      (_UINT32_(0xF) << PWM_IER_CHID_Pos)                  /* (PWM_IER Mask) CHID */
#define PWM_IER_CHID(value)                   (PWM_IER_CHID_Msk & (_UINT32_(value) << PWM_IER_CHID_Pos)) 

/* -------- PWM_IDR : (PWM Offset: 0x14) ( /W 32) PWM Interrupt Disable Register -------- */
#define PWM_IDR_CHID0_Pos                     _UINT32_(0)                                          /* (PWM_IDR) Channel ID Position */
#define PWM_IDR_CHID0_Msk                     (_UINT32_(0x1) << PWM_IDR_CHID0_Pos)                 /* (PWM_IDR) Channel ID Mask */
#define PWM_IDR_CHID0(value)                  (PWM_IDR_CHID0_Msk & (_UINT32_(value) << PWM_IDR_CHID0_Pos)) /* Assigment of value for CHID0 in the PWM_IDR register */
#define   PWM_IDR_CHID0_0_Val                 _UINT32_(0x0)                                        /* (PWM_IDR) No effect.  */
#define   PWM_IDR_CHID0_1_Val                 _UINT32_(0x1)                                        /* (PWM_IDR) Disable interrupt for PWM channel x.  */
#define PWM_IDR_CHID0_0                       (PWM_IDR_CHID0_0_Val << PWM_IDR_CHID0_Pos)           /* (PWM_IDR) No effect. Position  */
#define PWM_IDR_CHID0_1                       (PWM_IDR_CHID0_1_Val << PWM_IDR_CHID0_Pos)           /* (PWM_IDR) Disable interrupt for PWM channel x. Position  */
#define PWM_IDR_CHID1_Pos                     _UINT32_(1)                                          /* (PWM_IDR) Channel ID Position */
#define PWM_IDR_CHID1_Msk                     (_UINT32_(0x1) << PWM_IDR_CHID1_Pos)                 /* (PWM_IDR) Channel ID Mask */
#define PWM_IDR_CHID1(value)                  (PWM_IDR_CHID1_Msk & (_UINT32_(value) << PWM_IDR_CHID1_Pos)) /* Assigment of value for CHID1 in the PWM_IDR register */
#define   PWM_IDR_CHID1_0_Val                 _UINT32_(0x0)                                        /* (PWM_IDR) No effect.  */
#define   PWM_IDR_CHID1_1_Val                 _UINT32_(0x1)                                        /* (PWM_IDR) Disable interrupt for PWM channel x.  */
#define PWM_IDR_CHID1_0                       (PWM_IDR_CHID1_0_Val << PWM_IDR_CHID1_Pos)           /* (PWM_IDR) No effect. Position  */
#define PWM_IDR_CHID1_1                       (PWM_IDR_CHID1_1_Val << PWM_IDR_CHID1_Pos)           /* (PWM_IDR) Disable interrupt for PWM channel x. Position  */
#define PWM_IDR_CHID2_Pos                     _UINT32_(2)                                          /* (PWM_IDR) Channel ID Position */
#define PWM_IDR_CHID2_Msk                     (_UINT32_(0x1) << PWM_IDR_CHID2_Pos)                 /* (PWM_IDR) Channel ID Mask */
#define PWM_IDR_CHID2(value)                  (PWM_IDR_CHID2_Msk & (_UINT32_(value) << PWM_IDR_CHID2_Pos)) /* Assigment of value for CHID2 in the PWM_IDR register */
#define   PWM_IDR_CHID2_0_Val                 _UINT32_(0x0)                                        /* (PWM_IDR) No effect.  */
#define   PWM_IDR_CHID2_1_Val                 _UINT32_(0x1)                                        /* (PWM_IDR) Disable interrupt for PWM channel x.  */
#define PWM_IDR_CHID2_0                       (PWM_IDR_CHID2_0_Val << PWM_IDR_CHID2_Pos)           /* (PWM_IDR) No effect. Position  */
#define PWM_IDR_CHID2_1                       (PWM_IDR_CHID2_1_Val << PWM_IDR_CHID2_Pos)           /* (PWM_IDR) Disable interrupt for PWM channel x. Position  */
#define PWM_IDR_CHID3_Pos                     _UINT32_(3)                                          /* (PWM_IDR) Channel ID Position */
#define PWM_IDR_CHID3_Msk                     (_UINT32_(0x1) << PWM_IDR_CHID3_Pos)                 /* (PWM_IDR) Channel ID Mask */
#define PWM_IDR_CHID3(value)                  (PWM_IDR_CHID3_Msk & (_UINT32_(value) << PWM_IDR_CHID3_Pos)) /* Assigment of value for CHID3 in the PWM_IDR register */
#define   PWM_IDR_CHID3_0_Val                 _UINT32_(0x0)                                        /* (PWM_IDR) No effect.  */
#define   PWM_IDR_CHID3_1_Val                 _UINT32_(0x1)                                        /* (PWM_IDR) Disable interrupt for PWM channel x.  */
#define PWM_IDR_CHID3_0                       (PWM_IDR_CHID3_0_Val << PWM_IDR_CHID3_Pos)           /* (PWM_IDR) No effect. Position  */
#define PWM_IDR_CHID3_1                       (PWM_IDR_CHID3_1_Val << PWM_IDR_CHID3_Pos)           /* (PWM_IDR) Disable interrupt for PWM channel x. Position  */
#define PWM_IDR_Msk                           _UINT32_(0x0000000F)                                 /* (PWM_IDR) Register Mask  */

#define PWM_IDR_CHID_Pos                      _UINT32_(0)                                          /* (PWM_IDR Position) Channel ID */
#define PWM_IDR_CHID_Msk                      (_UINT32_(0xF) << PWM_IDR_CHID_Pos)                  /* (PWM_IDR Mask) CHID */
#define PWM_IDR_CHID(value)                   (PWM_IDR_CHID_Msk & (_UINT32_(value) << PWM_IDR_CHID_Pos)) 

/* -------- PWM_IMR : (PWM Offset: 0x18) ( R/ 32) PWM Interrupt Mask Register -------- */
#define PWM_IMR_RESETVALUE                    _UINT32_(0x00)                                       /*  (PWM_IMR) PWM Interrupt Mask Register  Reset Value */

#define PWM_IMR_CHID0_Pos                     _UINT32_(0)                                          /* (PWM_IMR) Channel ID Position */
#define PWM_IMR_CHID0_Msk                     (_UINT32_(0x1) << PWM_IMR_CHID0_Pos)                 /* (PWM_IMR) Channel ID Mask */
#define PWM_IMR_CHID0(value)                  (PWM_IMR_CHID0_Msk & (_UINT32_(value) << PWM_IMR_CHID0_Pos)) /* Assigment of value for CHID0 in the PWM_IMR register */
#define   PWM_IMR_CHID0_0_Val                 _UINT32_(0x0)                                        /* (PWM_IMR) Interrupt for PWM channel x is disabled.  */
#define   PWM_IMR_CHID0_1_Val                 _UINT32_(0x1)                                        /* (PWM_IMR) Interrupt for PWM channel x is enabled.  */
#define PWM_IMR_CHID0_0                       (PWM_IMR_CHID0_0_Val << PWM_IMR_CHID0_Pos)           /* (PWM_IMR) Interrupt for PWM channel x is disabled. Position  */
#define PWM_IMR_CHID0_1                       (PWM_IMR_CHID0_1_Val << PWM_IMR_CHID0_Pos)           /* (PWM_IMR) Interrupt for PWM channel x is enabled. Position  */
#define PWM_IMR_CHID1_Pos                     _UINT32_(1)                                          /* (PWM_IMR) Channel ID Position */
#define PWM_IMR_CHID1_Msk                     (_UINT32_(0x1) << PWM_IMR_CHID1_Pos)                 /* (PWM_IMR) Channel ID Mask */
#define PWM_IMR_CHID1(value)                  (PWM_IMR_CHID1_Msk & (_UINT32_(value) << PWM_IMR_CHID1_Pos)) /* Assigment of value for CHID1 in the PWM_IMR register */
#define   PWM_IMR_CHID1_0_Val                 _UINT32_(0x0)                                        /* (PWM_IMR) Interrupt for PWM channel x is disabled.  */
#define   PWM_IMR_CHID1_1_Val                 _UINT32_(0x1)                                        /* (PWM_IMR) Interrupt for PWM channel x is enabled.  */
#define PWM_IMR_CHID1_0                       (PWM_IMR_CHID1_0_Val << PWM_IMR_CHID1_Pos)           /* (PWM_IMR) Interrupt for PWM channel x is disabled. Position  */
#define PWM_IMR_CHID1_1                       (PWM_IMR_CHID1_1_Val << PWM_IMR_CHID1_Pos)           /* (PWM_IMR) Interrupt for PWM channel x is enabled. Position  */
#define PWM_IMR_CHID2_Pos                     _UINT32_(2)                                          /* (PWM_IMR) Channel ID Position */
#define PWM_IMR_CHID2_Msk                     (_UINT32_(0x1) << PWM_IMR_CHID2_Pos)                 /* (PWM_IMR) Channel ID Mask */
#define PWM_IMR_CHID2(value)                  (PWM_IMR_CHID2_Msk & (_UINT32_(value) << PWM_IMR_CHID2_Pos)) /* Assigment of value for CHID2 in the PWM_IMR register */
#define   PWM_IMR_CHID2_0_Val                 _UINT32_(0x0)                                        /* (PWM_IMR) Interrupt for PWM channel x is disabled.  */
#define   PWM_IMR_CHID2_1_Val                 _UINT32_(0x1)                                        /* (PWM_IMR) Interrupt for PWM channel x is enabled.  */
#define PWM_IMR_CHID2_0                       (PWM_IMR_CHID2_0_Val << PWM_IMR_CHID2_Pos)           /* (PWM_IMR) Interrupt for PWM channel x is disabled. Position  */
#define PWM_IMR_CHID2_1                       (PWM_IMR_CHID2_1_Val << PWM_IMR_CHID2_Pos)           /* (PWM_IMR) Interrupt for PWM channel x is enabled. Position  */
#define PWM_IMR_CHID3_Pos                     _UINT32_(3)                                          /* (PWM_IMR) Channel ID Position */
#define PWM_IMR_CHID3_Msk                     (_UINT32_(0x1) << PWM_IMR_CHID3_Pos)                 /* (PWM_IMR) Channel ID Mask */
#define PWM_IMR_CHID3(value)                  (PWM_IMR_CHID3_Msk & (_UINT32_(value) << PWM_IMR_CHID3_Pos)) /* Assigment of value for CHID3 in the PWM_IMR register */
#define   PWM_IMR_CHID3_0_Val                 _UINT32_(0x0)                                        /* (PWM_IMR) Interrupt for PWM channel x is disabled.  */
#define   PWM_IMR_CHID3_1_Val                 _UINT32_(0x1)                                        /* (PWM_IMR) Interrupt for PWM channel x is enabled.  */
#define PWM_IMR_CHID3_0                       (PWM_IMR_CHID3_0_Val << PWM_IMR_CHID3_Pos)           /* (PWM_IMR) Interrupt for PWM channel x is disabled. Position  */
#define PWM_IMR_CHID3_1                       (PWM_IMR_CHID3_1_Val << PWM_IMR_CHID3_Pos)           /* (PWM_IMR) Interrupt for PWM channel x is enabled. Position  */
#define PWM_IMR_Msk                           _UINT32_(0x0000000F)                                 /* (PWM_IMR) Register Mask  */

#define PWM_IMR_CHID_Pos                      _UINT32_(0)                                          /* (PWM_IMR Position) Channel ID */
#define PWM_IMR_CHID_Msk                      (_UINT32_(0xF) << PWM_IMR_CHID_Pos)                  /* (PWM_IMR Mask) CHID */
#define PWM_IMR_CHID(value)                   (PWM_IMR_CHID_Msk & (_UINT32_(value) << PWM_IMR_CHID_Pos)) 

/* -------- PWM_ISR : (PWM Offset: 0x1C) ( R/ 32) PWM Interrupt Status Register -------- */
#define PWM_ISR_RESETVALUE                    _UINT32_(0x00)                                       /*  (PWM_ISR) PWM Interrupt Status Register  Reset Value */

#define PWM_ISR_CHID0_Pos                     _UINT32_(0)                                          /* (PWM_ISR) Channel ID Position */
#define PWM_ISR_CHID0_Msk                     (_UINT32_(0x1) << PWM_ISR_CHID0_Pos)                 /* (PWM_ISR) Channel ID Mask */
#define PWM_ISR_CHID0(value)                  (PWM_ISR_CHID0_Msk & (_UINT32_(value) << PWM_ISR_CHID0_Pos)) /* Assigment of value for CHID0 in the PWM_ISR register */
#define   PWM_ISR_CHID0_0_Val                 _UINT32_(0x0)                                        /* (PWM_ISR) No new channel period has been achieved since the last read of PWM_ISR.  */
#define   PWM_ISR_CHID0_1_Val                 _UINT32_(0x1)                                        /* (PWM_ISR) At least one new channel period has been achieved since the last read of PWM_ISR.  */
#define PWM_ISR_CHID0_0                       (PWM_ISR_CHID0_0_Val << PWM_ISR_CHID0_Pos)           /* (PWM_ISR) No new channel period has been achieved since the last read of PWM_ISR. Position  */
#define PWM_ISR_CHID0_1                       (PWM_ISR_CHID0_1_Val << PWM_ISR_CHID0_Pos)           /* (PWM_ISR) At least one new channel period has been achieved since the last read of PWM_ISR. Position  */
#define PWM_ISR_CHID1_Pos                     _UINT32_(1)                                          /* (PWM_ISR) Channel ID Position */
#define PWM_ISR_CHID1_Msk                     (_UINT32_(0x1) << PWM_ISR_CHID1_Pos)                 /* (PWM_ISR) Channel ID Mask */
#define PWM_ISR_CHID1(value)                  (PWM_ISR_CHID1_Msk & (_UINT32_(value) << PWM_ISR_CHID1_Pos)) /* Assigment of value for CHID1 in the PWM_ISR register */
#define   PWM_ISR_CHID1_0_Val                 _UINT32_(0x0)                                        /* (PWM_ISR) No new channel period has been achieved since the last read of PWM_ISR.  */
#define   PWM_ISR_CHID1_1_Val                 _UINT32_(0x1)                                        /* (PWM_ISR) At least one new channel period has been achieved since the last read of PWM_ISR.  */
#define PWM_ISR_CHID1_0                       (PWM_ISR_CHID1_0_Val << PWM_ISR_CHID1_Pos)           /* (PWM_ISR) No new channel period has been achieved since the last read of PWM_ISR. Position  */
#define PWM_ISR_CHID1_1                       (PWM_ISR_CHID1_1_Val << PWM_ISR_CHID1_Pos)           /* (PWM_ISR) At least one new channel period has been achieved since the last read of PWM_ISR. Position  */
#define PWM_ISR_CHID2_Pos                     _UINT32_(2)                                          /* (PWM_ISR) Channel ID Position */
#define PWM_ISR_CHID2_Msk                     (_UINT32_(0x1) << PWM_ISR_CHID2_Pos)                 /* (PWM_ISR) Channel ID Mask */
#define PWM_ISR_CHID2(value)                  (PWM_ISR_CHID2_Msk & (_UINT32_(value) << PWM_ISR_CHID2_Pos)) /* Assigment of value for CHID2 in the PWM_ISR register */
#define   PWM_ISR_CHID2_0_Val                 _UINT32_(0x0)                                        /* (PWM_ISR) No new channel period has been achieved since the last read of PWM_ISR.  */
#define   PWM_ISR_CHID2_1_Val                 _UINT32_(0x1)                                        /* (PWM_ISR) At least one new channel period has been achieved since the last read of PWM_ISR.  */
#define PWM_ISR_CHID2_0                       (PWM_ISR_CHID2_0_Val << PWM_ISR_CHID2_Pos)           /* (PWM_ISR) No new channel period has been achieved since the last read of PWM_ISR. Position  */
#define PWM_ISR_CHID2_1                       (PWM_ISR_CHID2_1_Val << PWM_ISR_CHID2_Pos)           /* (PWM_ISR) At least one new channel period has been achieved since the last read of PWM_ISR. Position  */
#define PWM_ISR_CHID3_Pos                     _UINT32_(3)                                          /* (PWM_ISR) Channel ID Position */
#define PWM_ISR_CHID3_Msk                     (_UINT32_(0x1) << PWM_ISR_CHID3_Pos)                 /* (PWM_ISR) Channel ID Mask */
#define PWM_ISR_CHID3(value)                  (PWM_ISR_CHID3_Msk & (_UINT32_(value) << PWM_ISR_CHID3_Pos)) /* Assigment of value for CHID3 in the PWM_ISR register */
#define   PWM_ISR_CHID3_0_Val                 _UINT32_(0x0)                                        /* (PWM_ISR) No new channel period has been achieved since the last read of PWM_ISR.  */
#define   PWM_ISR_CHID3_1_Val                 _UINT32_(0x1)                                        /* (PWM_ISR) At least one new channel period has been achieved since the last read of PWM_ISR.  */
#define PWM_ISR_CHID3_0                       (PWM_ISR_CHID3_0_Val << PWM_ISR_CHID3_Pos)           /* (PWM_ISR) No new channel period has been achieved since the last read of PWM_ISR. Position  */
#define PWM_ISR_CHID3_1                       (PWM_ISR_CHID3_1_Val << PWM_ISR_CHID3_Pos)           /* (PWM_ISR) At least one new channel period has been achieved since the last read of PWM_ISR. Position  */
#define PWM_ISR_Msk                           _UINT32_(0x0000000F)                                 /* (PWM_ISR) Register Mask  */

#define PWM_ISR_CHID_Pos                      _UINT32_(0)                                          /* (PWM_ISR Position) Channel ID */
#define PWM_ISR_CHID_Msk                      (_UINT32_(0xF) << PWM_ISR_CHID_Pos)                  /* (PWM_ISR Mask) CHID */
#define PWM_ISR_CHID(value)                   (PWM_ISR_CHID_Msk & (_UINT32_(value) << PWM_ISR_CHID_Pos)) 

/** \brief PWM register offsets definitions */
#define PWM_CMR_REG_OFST               _UINT32_(0x00)      /* (PWM_CMR) PWM Channel Mode Register  Offset */
#define PWM_CDTY_REG_OFST              _UINT32_(0x04)      /* (PWM_CDTY) PWM Channel Duty Cycle Register  Offset */
#define PWM_CPRD_REG_OFST              _UINT32_(0x08)      /* (PWM_CPRD) PWM Channel Period Register  Offset */
#define PWM_CCNT_REG_OFST              _UINT32_(0x0C)      /* (PWM_CCNT) PWM Channel Counter Register  Offset */
#define PWM_CUPD_REG_OFST              _UINT32_(0x10)      /* (PWM_CUPD) PWM Channel Update Register  Offset */
#define PWM_MR_REG_OFST                _UINT32_(0x00)      /* (PWM_MR) PWM Mode Register Offset */
#define PWM_ENA_REG_OFST               _UINT32_(0x04)      /* (PWM_ENA) PWM Enable Register Offset */
#define PWM_DIS_REG_OFST               _UINT32_(0x08)      /* (PWM_DIS) PWM Disable Register Offset */
#define PWM_SR_REG_OFST                _UINT32_(0x0C)      /* (PWM_SR) PWM Status Register Offset */
#define PWM_IER_REG_OFST               _UINT32_(0x10)      /* (PWM_IER) PWM Interrupt Enable Register Offset */
#define PWM_IDR_REG_OFST               _UINT32_(0x14)      /* (PWM_IDR) PWM Interrupt Disable Register Offset */
#define PWM_IMR_REG_OFST               _UINT32_(0x18)      /* (PWM_IMR) PWM Interrupt Mask Register Offset */
#define PWM_ISR_REG_OFST               _UINT32_(0x1C)      /* (PWM_ISR) PWM Interrupt Status Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief PWM_CH_NUM register API structure */
typedef struct
{
  __IO  uint32_t                       PWM_CMR;            /**< Offset: 0x00 (R/W  32) PWM Channel Mode Register  */
  __IO  uint32_t                       PWM_CDTY;           /**< Offset: 0x04 (R/W  32) PWM Channel Duty Cycle Register  */
  __IO  uint32_t                       PWM_CPRD;           /**< Offset: 0x08 (R/W  32) PWM Channel Period Register  */
  __I   uint32_t                       PWM_CCNT;           /**< Offset: 0x0C (R/   32) PWM Channel Counter Register  */
  __O   uint32_t                       PWM_CUPD;           /**< Offset: 0x10 ( /W  32) PWM Channel Update Register  */
  __I   uint8_t                        Reserved1[0x0C];
} pwm_ch_num_registers_t;

#define PWM_CH_NUM_NUMBER 4

/** \brief PWM register API structure */
typedef struct
{  /* Pulse Width Modulation Controller */
  __IO  uint32_t                       PWM_MR;             /**< Offset: 0x00 (R/W  32) PWM Mode Register */
  __O   uint32_t                       PWM_ENA;            /**< Offset: 0x04 ( /W  32) PWM Enable Register */
  __O   uint32_t                       PWM_DIS;            /**< Offset: 0x08 ( /W  32) PWM Disable Register */
  __I   uint32_t                       PWM_SR;             /**< Offset: 0x0C (R/   32) PWM Status Register */
  __O   uint32_t                       PWM_IER;            /**< Offset: 0x10 ( /W  32) PWM Interrupt Enable Register */
  __O   uint32_t                       PWM_IDR;            /**< Offset: 0x14 ( /W  32) PWM Interrupt Disable Register */
  __I   uint32_t                       PWM_IMR;            /**< Offset: 0x18 (R/   32) PWM Interrupt Mask Register */
  __I   uint32_t                       PWM_ISR;            /**< Offset: 0x1C (R/   32) PWM Interrupt Status Register */
  __I   uint8_t                        Reserved1[0x1E0];
        pwm_ch_num_registers_t         PWM_CH_NUM[PWM_CH_NUM_NUMBER]; /**< Offset: 0x200  */
} pwm_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAM9X7_PWM_COMPONENT_H_ */
