/*
 * Component description for CPKCC
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

/* file generated from device description version 2023-02-02T10:07:15Z */
#ifndef _SAMA7G_CPKCC_COMPONENT_H_
#define _SAMA7G_CPKCC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR CPKCC                                        */
/* ************************************************************************** */

/* -------- CPKCC_R : (CPKCC Offset: 0x00) (R/W 32) R Parameter Register -------- */
#define CPKCC_R_VALUE_Pos                     _UINT32_(0)                                          /* (CPKCC_R) CPKCC_R value Position */
#define CPKCC_R_VALUE_Msk                     (_UINT32_(0xFFFFFFFF) << CPKCC_R_VALUE_Pos)          /* (CPKCC_R) CPKCC_R value Mask */
#define CPKCC_R_VALUE(value)                  (CPKCC_R_VALUE_Msk & (_UINT32_(value) << CPKCC_R_VALUE_Pos)) /* Assigment of value for VALUE in the CPKCC_R register */
#define CPKCC_R_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (CPKCC_R) Register Mask  */


/* -------- CPKCC_X : (CPKCC Offset: 0x04) (R/W 32) X Parameter Register -------- */
#define CPKCC_X_VALUE_Pos                     _UINT32_(0)                                          /* (CPKCC_X) CPKCC_X value Position */
#define CPKCC_X_VALUE_Msk                     (_UINT32_(0xFFFFFFFF) << CPKCC_X_VALUE_Pos)          /* (CPKCC_X) CPKCC_X value Mask */
#define CPKCC_X_VALUE(value)                  (CPKCC_X_VALUE_Msk & (_UINT32_(value) << CPKCC_X_VALUE_Pos)) /* Assigment of value for VALUE in the CPKCC_X register */
#define CPKCC_X_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (CPKCC_X) Register Mask  */


/* -------- CPKCC_Y : (CPKCC Offset: 0x08) (R/W 32) Y Parameter Register -------- */
#define CPKCC_Y_VALUE_Pos                     _UINT32_(0)                                          /* (CPKCC_Y) CPKCC_Y value Position */
#define CPKCC_Y_VALUE_Msk                     (_UINT32_(0xFFFFFFFF) << CPKCC_Y_VALUE_Pos)          /* (CPKCC_Y) CPKCC_Y value Mask */
#define CPKCC_Y_VALUE(value)                  (CPKCC_Y_VALUE_Msk & (_UINT32_(value) << CPKCC_Y_VALUE_Pos)) /* Assigment of value for VALUE in the CPKCC_Y register */
#define CPKCC_Y_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (CPKCC_Y) Register Mask  */


/* -------- CPKCC_Z : (CPKCC Offset: 0x0C) (R/W 32) Z Parameter Register -------- */
#define CPKCC_Z_VALUE_Pos                     _UINT32_(0)                                          /* (CPKCC_Z) CPKCC_Z value Position */
#define CPKCC_Z_VALUE_Msk                     (_UINT32_(0xFFFFFFFF) << CPKCC_Z_VALUE_Pos)          /* (CPKCC_Z) CPKCC_Z value Mask */
#define CPKCC_Z_VALUE(value)                  (CPKCC_Z_VALUE_Msk & (_UINT32_(value) << CPKCC_Z_VALUE_Pos)) /* Assigment of value for VALUE in the CPKCC_Z register */
#define CPKCC_Z_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (CPKCC_Z) Register Mask  */


/* -------- CPKCC_J : (CPKCC Offset: 0x10) (R/W 32) J Parameter Register -------- */
#define CPKCC_J_VALUE_Pos                     _UINT32_(0)                                          /* (CPKCC_J) CPKCC_J value Position */
#define CPKCC_J_VALUE_Msk                     (_UINT32_(0xFFFFFFFF) << CPKCC_J_VALUE_Pos)          /* (CPKCC_J) CPKCC_J value Mask */
#define CPKCC_J_VALUE(value)                  (CPKCC_J_VALUE_Msk & (_UINT32_(value) << CPKCC_J_VALUE_Pos)) /* Assigment of value for VALUE in the CPKCC_J register */
#define CPKCC_J_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (CPKCC_J) Register Mask  */


/* -------- CPKCC_K : (CPKCC Offset: 0x14) (R/W 32) K Parameter Register -------- */
#define CPKCC_K_VALUE_Pos                     _UINT32_(0)                                          /* (CPKCC_K) CPKCC_K value Position */
#define CPKCC_K_VALUE_Msk                     (_UINT32_(0xFFFFFFFF) << CPKCC_K_VALUE_Pos)          /* (CPKCC_K) CPKCC_K value Mask */
#define CPKCC_K_VALUE(value)                  (CPKCC_K_VALUE_Msk & (_UINT32_(value) << CPKCC_K_VALUE_Pos)) /* Assigment of value for VALUE in the CPKCC_K register */
#define CPKCC_K_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (CPKCC_K) Register Mask  */


/* -------- CPKCC_N : (CPKCC Offset: 0x18) (R/W 32) N Parameter Register -------- */
#define CPKCC_N_VALUE_Pos                     _UINT32_(0)                                          /* (CPKCC_N) CPKCC_N value Position */
#define CPKCC_N_VALUE_Msk                     (_UINT32_(0xFFFFFFFF) << CPKCC_N_VALUE_Pos)          /* (CPKCC_N) CPKCC_N value Mask */
#define CPKCC_N_VALUE(value)                  (CPKCC_N_VALUE_Msk & (_UINT32_(value) << CPKCC_N_VALUE_Pos)) /* Assigment of value for VALUE in the CPKCC_N register */
#define CPKCC_N_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (CPKCC_N) Register Mask  */


/* -------- CPKCC_SMULA : (CPKCC Offset: 0x1C) (R/W 32) SMULA Register -------- */
#define CPKCC_SMULA_VALUE_Pos                 _UINT32_(0)                                          /* (CPKCC_SMULA) CPKCC_SMULA value Position */
#define CPKCC_SMULA_VALUE_Msk                 (_UINT32_(0xFFFFFFFF) << CPKCC_SMULA_VALUE_Pos)      /* (CPKCC_SMULA) CPKCC_SMULA value Mask */
#define CPKCC_SMULA_VALUE(value)              (CPKCC_SMULA_VALUE_Msk & (_UINT32_(value) << CPKCC_SMULA_VALUE_Pos)) /* Assigment of value for VALUE in the CPKCC_SMULA register */
#define CPKCC_SMULA_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (CPKCC_SMULA) Register Mask  */


/* -------- CPKCC_SMULB : (CPKCC Offset: 0x20) (R/W 32) SMULB Register -------- */
#define CPKCC_SMULB_VALUE_Pos                 _UINT32_(0)                                          /* (CPKCC_SMULB) CPKCC_SMULB value Position */
#define CPKCC_SMULB_VALUE_Msk                 (_UINT32_(0xFFFFFFFF) << CPKCC_SMULB_VALUE_Pos)      /* (CPKCC_SMULB) CPKCC_SMULB value Mask */
#define CPKCC_SMULB_VALUE(value)              (CPKCC_SMULB_VALUE_Msk & (_UINT32_(value) << CPKCC_SMULB_VALUE_Pos)) /* Assigment of value for VALUE in the CPKCC_SMULB register */
#define CPKCC_SMULB_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (CPKCC_SMULB) Register Mask  */


/* -------- CPKCC_SMULRL : (CPKCC Offset: 0x24) (R/W 32) SMULRL Register -------- */
#define CPKCC_SMULRL_VALUE_Pos                _UINT32_(0)                                          /* (CPKCC_SMULRL) CPKCC_SMULRL value Position */
#define CPKCC_SMULRL_VALUE_Msk                (_UINT32_(0xFFFFFFFF) << CPKCC_SMULRL_VALUE_Pos)     /* (CPKCC_SMULRL) CPKCC_SMULRL value Mask */
#define CPKCC_SMULRL_VALUE(value)             (CPKCC_SMULRL_VALUE_Msk & (_UINT32_(value) << CPKCC_SMULRL_VALUE_Pos)) /* Assigment of value for VALUE in the CPKCC_SMULRL register */
#define CPKCC_SMULRL_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (CPKCC_SMULRL) Register Mask  */


/* -------- CPKCC_SMULRH : (CPKCC Offset: 0x28) (R/W 32) SMULRH Register -------- */
#define CPKCC_SMULRH_VALUE_Pos                _UINT32_(0)                                          /* (CPKCC_SMULRH) CPKCC_SMULRH value Position */
#define CPKCC_SMULRH_VALUE_Msk                (_UINT32_(0xFFFFFFFF) << CPKCC_SMULRH_VALUE_Pos)     /* (CPKCC_SMULRH) CPKCC_SMULRH value Mask */
#define CPKCC_SMULRH_VALUE(value)             (CPKCC_SMULRH_VALUE_Msk & (_UINT32_(value) << CPKCC_SMULRH_VALUE_Pos)) /* Assigment of value for VALUE in the CPKCC_SMULRH register */
#define CPKCC_SMULRH_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (CPKCC_SMULRH) Register Mask  */


/* -------- CPKCC_IDLE : (CPKCC Offset: 0x2C) (R/W 8) IDLE Register -------- */
#define CPKCC_IDLE_VALUE_Pos                  _UINT8_(0)                                           /* (CPKCC_IDLE) CPKCC_IDLE value Position */
#define CPKCC_IDLE_VALUE_Msk                  (_UINT8_(0xFF) << CPKCC_IDLE_VALUE_Pos)              /* (CPKCC_IDLE) CPKCC_IDLE value Mask */
#define CPKCC_IDLE_VALUE(value)               (CPKCC_IDLE_VALUE_Msk & (_UINT8_(value) << CPKCC_IDLE_VALUE_Pos)) /* Assigment of value for VALUE in the CPKCC_IDLE register */
#define CPKCC_IDLE_Msk                        _UINT8_(0xFF)                                        /* (CPKCC_IDLE) Register Mask  */


/* -------- CPKCC_IDLECACHE : (CPKCC Offset: 0x2D) (R/W 8) IDLECACHE Register -------- */
#define CPKCC_IDLECACHE_VALUE_Pos             _UINT8_(0)                                           /* (CPKCC_IDLECACHE) CPKCC_IDLECACHE value Position */
#define CPKCC_IDLECACHE_VALUE_Msk             (_UINT8_(0xFF) << CPKCC_IDLECACHE_VALUE_Pos)         /* (CPKCC_IDLECACHE) CPKCC_IDLECACHE value Mask */
#define CPKCC_IDLECACHE_VALUE(value)          (CPKCC_IDLECACHE_VALUE_Msk & (_UINT8_(value) << CPKCC_IDLECACHE_VALUE_Pos)) /* Assigment of value for VALUE in the CPKCC_IDLECACHE register */
#define CPKCC_IDLECACHE_Msk                   _UINT8_(0xFF)                                        /* (CPKCC_IDLECACHE) Register Mask  */


/* -------- CPKCC_CR_C : (CPKCC Offset: 0x30) (R/W 32) CR_C Register -------- */
#define CPKCC_CR_C_VALUE_Pos                  _UINT32_(0)                                          /* (CPKCC_CR_C) CPKCC_CR_C value Position */
#define CPKCC_CR_C_VALUE_Msk                  (_UINT32_(0xFFFFFFFF) << CPKCC_CR_C_VALUE_Pos)       /* (CPKCC_CR_C) CPKCC_CR_C value Mask */
#define CPKCC_CR_C_VALUE(value)               (CPKCC_CR_C_VALUE_Msk & (_UINT32_(value) << CPKCC_CR_C_VALUE_Pos)) /* Assigment of value for VALUE in the CPKCC_CR_C register */
#define CPKCC_CR_C_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (CPKCC_CR_C) Register Mask  */


/* -------- CPKCC_CR_S : (CPKCC Offset: 0x34) (R/W 32) CR_S Register -------- */
#define CPKCC_CR_S_VALUE_Pos                  _UINT32_(0)                                          /* (CPKCC_CR_S) CPKCC_CR_S value Position */
#define CPKCC_CR_S_VALUE_Msk                  (_UINT32_(0xFFFFFFFF) << CPKCC_CR_S_VALUE_Pos)       /* (CPKCC_CR_S) CPKCC_CR_S value Mask */
#define CPKCC_CR_S_VALUE(value)               (CPKCC_CR_S_VALUE_Msk & (_UINT32_(value) << CPKCC_CR_S_VALUE_Pos)) /* Assigment of value for VALUE in the CPKCC_CR_S register */
#define CPKCC_CR_S_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (CPKCC_CR_S) Register Mask  */


/* -------- CPKCC_CR : (CPKCC Offset: 0x38) (R/W 32) CR Register -------- */
#define CPKCC_CR_GF2N_Pos                     _UINT32_(0)                                          /* (CPKCC_CR) GF(2n) mode Position */
#define CPKCC_CR_GF2N_Msk                     (_UINT32_(0x1) << CPKCC_CR_GF2N_Pos)                 /* (CPKCC_CR) GF(2n) mode Mask */
#define CPKCC_CR_GF2N(value)                  (CPKCC_CR_GF2N_Msk & (_UINT32_(value) << CPKCC_CR_GF2N_Pos)) /* Assigment of value for GF2N in the CPKCC_CR register */
#define CPKCC_CR_CARRYIN_Pos                  _UINT32_(1)                                          /* (CPKCC_CR) CARRYIN value Position */
#define CPKCC_CR_CARRYIN_Msk                  (_UINT32_(0x1) << CPKCC_CR_CARRYIN_Pos)              /* (CPKCC_CR) CARRYIN value Mask */
#define CPKCC_CR_CARRYIN(value)               (CPKCC_CR_CARRYIN_Msk & (_UINT32_(value) << CPKCC_CR_CARRYIN_Pos)) /* Assigment of value for CARRYIN in the CPKCC_CR register */
#define CPKCC_CR_ONEMUL_Pos                   _UINT32_(2)                                          /* (CPKCC_CR) ONEMUL value Position */
#define CPKCC_CR_ONEMUL_Msk                   (_UINT32_(0x1) << CPKCC_CR_ONEMUL_Pos)               /* (CPKCC_CR) ONEMUL value Mask */
#define CPKCC_CR_ONEMUL(value)                (CPKCC_CR_ONEMUL_Msk & (_UINT32_(value) << CPKCC_CR_ONEMUL_Pos)) /* Assigment of value for ONEMUL in the CPKCC_CR register */
#define CPKCC_CR_ABORT_Pos                    _UINT32_(3)                                          /* (CPKCC_CR) ABORT value Position */
#define CPKCC_CR_ABORT_Msk                    (_UINT32_(0x1) << CPKCC_CR_ABORT_Pos)                /* (CPKCC_CR) ABORT value Mask */
#define CPKCC_CR_ABORT(value)                 (CPKCC_CR_ABORT_Msk & (_UINT32_(value) << CPKCC_CR_ABORT_Pos)) /* Assigment of value for ABORT in the CPKCC_CR register */
#define CPKCC_CR_SPILLW_Pos                   _UINT32_(4)                                          /* (CPKCC_CR) Spill Word register bit Position */
#define CPKCC_CR_SPILLW_Msk                   (_UINT32_(0x1) << CPKCC_CR_SPILLW_Pos)               /* (CPKCC_CR) Spill Word register bit Mask */
#define CPKCC_CR_SPILLW(value)                (CPKCC_CR_SPILLW_Msk & (_UINT32_(value) << CPKCC_CR_SPILLW_Pos)) /* Assigment of value for SPILLW in the CPKCC_CR register */
#define CPKCC_CR_AWAKE_Pos                    _UINT32_(5)                                          /* (CPKCC_CR) AWAKE value Position */
#define CPKCC_CR_AWAKE_Msk                    (_UINT32_(0x1) << CPKCC_CR_AWAKE_Pos)                /* (CPKCC_CR) AWAKE value Mask */
#define CPKCC_CR_AWAKE(value)                 (CPKCC_CR_AWAKE_Msk & (_UINT32_(value) << CPKCC_CR_AWAKE_Pos)) /* Assigment of value for AWAKE in the CPKCC_CR register */
#define CPKCC_CR_PKCCIRQ_Pos                  _UINT32_(6)                                          /* (CPKCC_CR) CPKCC_IRQ value Position */
#define CPKCC_CR_PKCCIRQ_Msk                  (_UINT32_(0x1) << CPKCC_CR_PKCCIRQ_Pos)              /* (CPKCC_CR) CPKCC_IRQ value Mask */
#define CPKCC_CR_PKCCIRQ(value)               (CPKCC_CR_PKCCIRQ_Msk & (_UINT32_(value) << CPKCC_CR_PKCCIRQ_Pos)) /* Assigment of value for PKCCIRQ in the CPKCC_CR register */
#define CPKCC_CR_ITEN_Pos                     _UINT32_(7)                                          /* (CPKCC_CR) ITEN value Position */
#define CPKCC_CR_ITEN_Msk                     (_UINT32_(0x1) << CPKCC_CR_ITEN_Pos)                 /* (CPKCC_CR) ITEN value Mask */
#define CPKCC_CR_ITEN(value)                  (CPKCC_CR_ITEN_Msk & (_UINT32_(value) << CPKCC_CR_ITEN_Pos)) /* Assigment of value for ITEN in the CPKCC_CR register */
#define CPKCC_CR_CLRRAM_Pos                   _UINT32_(8)                                          /* (CPKCC_CR) CLRRAM value Position */
#define CPKCC_CR_CLRRAM_Msk                   (_UINT32_(0x1) << CPKCC_CR_CLRRAM_Pos)               /* (CPKCC_CR) CLRRAM value Mask */
#define CPKCC_CR_CLRRAM(value)                (CPKCC_CR_CLRRAM_Msk & (_UINT32_(value) << CPKCC_CR_CLRRAM_Pos)) /* Assigment of value for CLRRAM in the CPKCC_CR register */
#define CPKCC_CR_VALUE_Pos                    _UINT32_(9)                                          /* (CPKCC_CR) CPKCC_CR value Position */
#define CPKCC_CR_VALUE_Msk                    (_UINT32_(0x7FFFFF) << CPKCC_CR_VALUE_Pos)           /* (CPKCC_CR) CPKCC_CR value Mask */
#define CPKCC_CR_VALUE(value)                 (CPKCC_CR_VALUE_Msk & (_UINT32_(value) << CPKCC_CR_VALUE_Pos)) /* Assigment of value for VALUE in the CPKCC_CR register */
#define CPKCC_CR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (CPKCC_CR) Register Mask  */


/* -------- CPKCC_OR : (CPKCC Offset: 0x3C) (R/W 32) Operation Register -------- */
#define CPKCC_OR_CMD0_Pos                     _UINT32_(0)                                          /* (CPKCC_OR) CMD0 value Position */
#define CPKCC_OR_CMD0_Msk                     (_UINT32_(0x1) << CPKCC_OR_CMD0_Pos)                 /* (CPKCC_OR) CMD0 value Mask */
#define CPKCC_OR_CMD0(value)                  (CPKCC_OR_CMD0_Msk & (_UINT32_(value) << CPKCC_OR_CMD0_Pos)) /* Assigment of value for CMD0 in the CPKCC_OR register */
#define CPKCC_OR_CMD1_Pos                     _UINT32_(1)                                          /* (CPKCC_OR) CMD1 value Position */
#define CPKCC_OR_CMD1_Msk                     (_UINT32_(0x1) << CPKCC_OR_CMD1_Pos)                 /* (CPKCC_OR) CMD1 value Mask */
#define CPKCC_OR_CMD1(value)                  (CPKCC_OR_CMD1_Msk & (_UINT32_(value) << CPKCC_OR_CMD1_Pos)) /* Assigment of value for CMD1 in the CPKCC_OR register */
#define CPKCC_OR_CMD2_Pos                     _UINT32_(2)                                          /* (CPKCC_OR) CMD2 value Position */
#define CPKCC_OR_CMD2_Msk                     (_UINT32_(0x1) << CPKCC_OR_CMD2_Pos)                 /* (CPKCC_OR) CMD2 value Mask */
#define CPKCC_OR_CMD2(value)                  (CPKCC_OR_CMD2_Msk & (_UINT32_(value) << CPKCC_OR_CMD2_Pos)) /* Assigment of value for CMD2 in the CPKCC_OR register */
#define CPKCC_OR_CMD3_Pos                     _UINT32_(3)                                          /* (CPKCC_OR) CMD3 value Position */
#define CPKCC_OR_CMD3_Msk                     (_UINT32_(0x1) << CPKCC_OR_CMD3_Pos)                 /* (CPKCC_OR) CMD3 value Mask */
#define CPKCC_OR_CMD3(value)                  (CPKCC_OR_CMD3_Msk & (_UINT32_(value) << CPKCC_OR_CMD3_Pos)) /* Assigment of value for CMD3 in the CPKCC_OR register */
#define CPKCC_OR_OPTM0_Pos                    _UINT32_(4)                                          /* (CPKCC_OR) OPTM0 value Position */
#define CPKCC_OR_OPTM0_Msk                    (_UINT32_(0x1) << CPKCC_OR_OPTM0_Pos)                /* (CPKCC_OR) OPTM0 value Mask */
#define CPKCC_OR_OPTM0(value)                 (CPKCC_OR_OPTM0_Msk & (_UINT32_(value) << CPKCC_OR_OPTM0_Pos)) /* Assigment of value for OPTM0 in the CPKCC_OR register */
#define CPKCC_OR_OPTM1_Pos                    _UINT32_(5)                                          /* (CPKCC_OR) OPTM1 value Position */
#define CPKCC_OR_OPTM1_Msk                    (_UINT32_(0x1) << CPKCC_OR_OPTM1_Pos)                /* (CPKCC_OR) OPTM1 value Mask */
#define CPKCC_OR_OPTM1(value)                 (CPKCC_OR_OPTM1_Msk & (_UINT32_(value) << CPKCC_OR_OPTM1_Pos)) /* Assigment of value for OPTM1 in the CPKCC_OR register */
#define CPKCC_OR_OPTC0_Pos                    _UINT32_(6)                                          /* (CPKCC_OR) OPTC0 value Position */
#define CPKCC_OR_OPTC0_Msk                    (_UINT32_(0x1) << CPKCC_OR_OPTC0_Pos)                /* (CPKCC_OR) OPTC0 value Mask */
#define CPKCC_OR_OPTC0(value)                 (CPKCC_OR_OPTC0_Msk & (_UINT32_(value) << CPKCC_OR_OPTC0_Pos)) /* Assigment of value for OPTC0 in the CPKCC_OR register */
#define CPKCC_OR_OPTC1_Pos                    _UINT32_(7)                                          /* (CPKCC_OR) OPTC1 value Position */
#define CPKCC_OR_OPTC1_Msk                    (_UINT32_(0x1) << CPKCC_OR_OPTC1_Pos)                /* (CPKCC_OR) OPTC1 value Mask */
#define CPKCC_OR_OPTC1(value)                 (CPKCC_OR_OPTC1_Msk & (_UINT32_(value) << CPKCC_OR_OPTC1_Pos)) /* Assigment of value for OPTC1 in the CPKCC_OR register */
#define CPKCC_OR_CARRYMUL_Pos                 _UINT32_(10)                                         /* (CPKCC_OR) CARRYMUL value Position */
#define CPKCC_OR_CARRYMUL_Msk                 (_UINT32_(0x1) << CPKCC_OR_CARRYMUL_Pos)             /* (CPKCC_OR) CARRYMUL value Mask */
#define CPKCC_OR_CARRYMUL(value)              (CPKCC_OR_CARRYMUL_Msk & (_UINT32_(value) << CPKCC_OR_CARRYMUL_Pos)) /* Assigment of value for CARRYMUL in the CPKCC_OR register */
#define CPKCC_OR_VALUE_Pos                    _UINT32_(11)                                         /* (CPKCC_OR) CPKCC_OR value Position */
#define CPKCC_OR_VALUE_Msk                    (_UINT32_(0x1FFFFF) << CPKCC_OR_VALUE_Pos)           /* (CPKCC_OR) CPKCC_OR value Mask */
#define CPKCC_OR_VALUE(value)                 (CPKCC_OR_VALUE_Msk & (_UINT32_(value) << CPKCC_OR_VALUE_Pos)) /* Assigment of value for VALUE in the CPKCC_OR register */
#define CPKCC_OR_Msk                          _UINT32_(0xFFFFFCFF)                                 /* (CPKCC_OR) Register Mask  */

#define CPKCC_OR_CMD_Pos                      _UINT32_(0)                                          /* (CPKCC_OR Position) CMDx value */
#define CPKCC_OR_CMD_Msk                      (_UINT32_(0xF) << CPKCC_OR_CMD_Pos)                  /* (CPKCC_OR Mask) CMD */
#define CPKCC_OR_CMD(value)                   (CPKCC_OR_CMD_Msk & (_UINT32_(value) << CPKCC_OR_CMD_Pos)) 
#define CPKCC_OR_OPTM_Pos                     _UINT32_(4)                                          /* (CPKCC_OR Position) OPTMx value */
#define CPKCC_OR_OPTM_Msk                     (_UINT32_(0x3) << CPKCC_OR_OPTM_Pos)                 /* (CPKCC_OR Mask) OPTM */
#define CPKCC_OR_OPTM(value)                  (CPKCC_OR_OPTM_Msk & (_UINT32_(value) << CPKCC_OR_OPTM_Pos)) 
#define CPKCC_OR_OPTC_Pos                     _UINT32_(6)                                          /* (CPKCC_OR Position) OPTCx value */
#define CPKCC_OR_OPTC_Msk                     (_UINT32_(0x3) << CPKCC_OR_OPTC_Pos)                 /* (CPKCC_OR Mask) OPTC */
#define CPKCC_OR_OPTC(value)                  (CPKCC_OR_OPTC_Msk & (_UINT32_(value) << CPKCC_OR_OPTC_Pos)) 

/* -------- CPKCC_SR : (CPKCC Offset: 0x40) (R/W 32) SR Register -------- */
#define CPKCC_SR_BUSY_Pos                     _UINT32_(0)                                          /* (CPKCC_SR) BUSY value Position */
#define CPKCC_SR_BUSY_Msk                     (_UINT32_(0x1) << CPKCC_SR_BUSY_Pos)                 /* (CPKCC_SR) BUSY value Mask */
#define CPKCC_SR_BUSY(value)                  (CPKCC_SR_BUSY_Msk & (_UINT32_(value) << CPKCC_SR_BUSY_Pos)) /* Assigment of value for BUSY in the CPKCC_SR register */
#define CPKCC_SR_CACHE_Pos                    _UINT32_(1)                                          /* (CPKCC_SR) CACHE value Position */
#define CPKCC_SR_CACHE_Msk                    (_UINT32_(0x1) << CPKCC_SR_CACHE_Pos)                /* (CPKCC_SR) CACHE value Mask */
#define CPKCC_SR_CACHE(value)                 (CPKCC_SR_CACHE_Msk & (_UINT32_(value) << CPKCC_SR_CACHE_Pos)) /* Assigment of value for CACHE in the CPKCC_SR register */
#define CPKCC_SR_CARRY_Pos                    _UINT32_(2)                                          /* (CPKCC_SR) CARRY value Position */
#define CPKCC_SR_CARRY_Msk                    (_UINT32_(0x1) << CPKCC_SR_CARRY_Pos)                /* (CPKCC_SR) CARRY value Mask */
#define CPKCC_SR_CARRY(value)                 (CPKCC_SR_CARRY_Msk & (_UINT32_(value) << CPKCC_SR_CARRY_Pos)) /* Assigment of value for CARRY in the CPKCC_SR register */
#define CPKCC_SR_ZERO_Pos                     _UINT32_(3)                                          /* (CPKCC_SR) ZERO value Position */
#define CPKCC_SR_ZERO_Msk                     (_UINT32_(0x1) << CPKCC_SR_ZERO_Pos)                 /* (CPKCC_SR) ZERO value Mask */
#define CPKCC_SR_ZERO(value)                  (CPKCC_SR_ZERO_Msk & (_UINT32_(value) << CPKCC_SR_ZERO_Pos)) /* Assigment of value for ZERO in the CPKCC_SR register */
#define CPKCC_SR_RAMV_Pos                     _UINT32_(4)                                          /* (CPKCC_SR) RAM violation Position */
#define CPKCC_SR_RAMV_Msk                     (_UINT32_(0x1) << CPKCC_SR_RAMV_Pos)                 /* (CPKCC_SR) RAM violation Mask */
#define CPKCC_SR_RAMV(value)                  (CPKCC_SR_RAMV_Msk & (_UINT32_(value) << CPKCC_SR_RAMV_Pos)) /* Assigment of value for RAMV in the CPKCC_SR register */
#define CPKCC_SR_SHAREV_Pos                   _UINT32_(5)                                          /* (CPKCC_SR) SHAREV value Position */
#define CPKCC_SR_SHAREV_Msk                   (_UINT32_(0x1) << CPKCC_SR_SHAREV_Pos)               /* (CPKCC_SR) SHAREV value Mask */
#define CPKCC_SR_SHAREV(value)                (CPKCC_SR_SHAREV_Msk & (_UINT32_(value) << CPKCC_SR_SHAREV_Pos)) /* Assigment of value for SHAREV in the CPKCC_SR register */
#define CPKCC_SR_CLRRAM_BUSY_Pos              _UINT32_(6)                                          /* (CPKCC_SR) CLRRAM_BUSY value Position */
#define CPKCC_SR_CLRRAM_BUSY_Msk              (_UINT32_(0x1) << CPKCC_SR_CLRRAM_BUSY_Pos)          /* (CPKCC_SR) CLRRAM_BUSY value Mask */
#define CPKCC_SR_CLRRAM_BUSY(value)           (CPKCC_SR_CLRRAM_BUSY_Msk & (_UINT32_(value) << CPKCC_SR_CLRRAM_BUSY_Pos)) /* Assigment of value for CLRRAM_BUSY in the CPKCC_SR register */
#define CPKCC_SR_VALUE_Pos                    _UINT32_(7)                                          /* (CPKCC_SR) CPKCC_SR value Position */
#define CPKCC_SR_VALUE_Msk                    (_UINT32_(0x1FFFFFF) << CPKCC_SR_VALUE_Pos)          /* (CPKCC_SR) CPKCC_SR value Mask */
#define CPKCC_SR_VALUE(value)                 (CPKCC_SR_VALUE_Msk & (_UINT32_(value) << CPKCC_SR_VALUE_Pos)) /* Assigment of value for VALUE in the CPKCC_SR register */
#define CPKCC_SR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (CPKCC_SR) Register Mask  */


/* -------- CPKCC_ADDRSIZE : (CPKCC Offset: 0xEC) (R/W 32) ADDRSIZE Register -------- */
#define CPKCC_ADDRSIZE_VALUE_Pos              _UINT32_(0)                                          /* (CPKCC_ADDRSIZE) CPKCC_ADDRSIZE value Position */
#define CPKCC_ADDRSIZE_VALUE_Msk              (_UINT32_(0xFFFFFFFF) << CPKCC_ADDRSIZE_VALUE_Pos)   /* (CPKCC_ADDRSIZE) CPKCC_ADDRSIZE value Mask */
#define CPKCC_ADDRSIZE_VALUE(value)           (CPKCC_ADDRSIZE_VALUE_Msk & (_UINT32_(value) << CPKCC_ADDRSIZE_VALUE_Pos)) /* Assigment of value for VALUE in the CPKCC_ADDRSIZE register */
#define CPKCC_ADDRSIZE_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (CPKCC_ADDRSIZE) Register Mask  */


/* -------- CPKCC_IPNAME : (CPKCC Offset: 0xF0) (R/W 32) IPNAME1 Register -------- */
#define CPKCC_IPNAME_VALUE_Pos                _UINT32_(0)                                          /* (CPKCC_IPNAME) CPKCC_IPNAME1 value Position */
#define CPKCC_IPNAME_VALUE_Msk                (_UINT32_(0xFFFFFFFF) << CPKCC_IPNAME_VALUE_Pos)     /* (CPKCC_IPNAME) CPKCC_IPNAME1 value Mask */
#define CPKCC_IPNAME_VALUE(value)             (CPKCC_IPNAME_VALUE_Msk & (_UINT32_(value) << CPKCC_IPNAME_VALUE_Pos)) /* Assigment of value for VALUE in the CPKCC_IPNAME register */
#define CPKCC_IPNAME_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (CPKCC_IPNAME) Register Mask  */


/* -------- CPKCC_FEATURES : (CPKCC Offset: 0xF8) (R/W 32) FEATURES Register -------- */
#define CPKCC_FEATURES_VALUE_Pos              _UINT32_(0)                                          /* (CPKCC_FEATURES) CPKCC_FEATURES value Position */
#define CPKCC_FEATURES_VALUE_Msk              (_UINT32_(0xFFFFFFFF) << CPKCC_FEATURES_VALUE_Pos)   /* (CPKCC_FEATURES) CPKCC_FEATURES value Mask */
#define CPKCC_FEATURES_VALUE(value)           (CPKCC_FEATURES_VALUE_Msk & (_UINT32_(value) << CPKCC_FEATURES_VALUE_Pos)) /* Assigment of value for VALUE in the CPKCC_FEATURES register */
#define CPKCC_FEATURES_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (CPKCC_FEATURES) Register Mask  */


/** \brief CPKCC register offsets definitions */
#define CPKCC_R_REG_OFST               _UINT32_(0x00)      /* (CPKCC_R) R Parameter Register Offset */
#define CPKCC_X_REG_OFST               _UINT32_(0x04)      /* (CPKCC_X) X Parameter Register Offset */
#define CPKCC_Y_REG_OFST               _UINT32_(0x08)      /* (CPKCC_Y) Y Parameter Register Offset */
#define CPKCC_Z_REG_OFST               _UINT32_(0x0C)      /* (CPKCC_Z) Z Parameter Register Offset */
#define CPKCC_J_REG_OFST               _UINT32_(0x10)      /* (CPKCC_J) J Parameter Register Offset */
#define CPKCC_K_REG_OFST               _UINT32_(0x14)      /* (CPKCC_K) K Parameter Register Offset */
#define CPKCC_N_REG_OFST               _UINT32_(0x18)      /* (CPKCC_N) N Parameter Register Offset */
#define CPKCC_SMULA_REG_OFST           _UINT32_(0x1C)      /* (CPKCC_SMULA) SMULA Register Offset */
#define CPKCC_SMULB_REG_OFST           _UINT32_(0x20)      /* (CPKCC_SMULB) SMULB Register Offset */
#define CPKCC_SMULRL_REG_OFST          _UINT32_(0x24)      /* (CPKCC_SMULRL) SMULRL Register Offset */
#define CPKCC_SMULRH_REG_OFST          _UINT32_(0x28)      /* (CPKCC_SMULRH) SMULRH Register Offset */
#define CPKCC_IDLE_REG_OFST            _UINT32_(0x2C)      /* (CPKCC_IDLE) IDLE Register Offset */
#define CPKCC_IDLECACHE_REG_OFST       _UINT32_(0x2D)      /* (CPKCC_IDLECACHE) IDLECACHE Register Offset */
#define CPKCC_CR_C_REG_OFST            _UINT32_(0x30)      /* (CPKCC_CR_C) CR_C Register Offset */
#define CPKCC_CR_S_REG_OFST            _UINT32_(0x34)      /* (CPKCC_CR_S) CR_S Register Offset */
#define CPKCC_CR_REG_OFST              _UINT32_(0x38)      /* (CPKCC_CR) CR Register Offset */
#define CPKCC_OR_REG_OFST              _UINT32_(0x3C)      /* (CPKCC_OR) Operation Register Offset */
#define CPKCC_SR_REG_OFST              _UINT32_(0x40)      /* (CPKCC_SR) SR Register Offset */
#define CPKCC_ADDRSIZE_REG_OFST        _UINT32_(0xEC)      /* (CPKCC_ADDRSIZE) ADDRSIZE Register Offset */
#define CPKCC_IPNAME_REG_OFST          _UINT32_(0xF0)      /* (CPKCC_IPNAME) IPNAME1 Register Offset */
#define CPKCC_IPNAME0_REG_OFST         _UINT32_(0xF0)      /* (CPKCC_IPNAME0) IPNAME1 Register Offset */
#define CPKCC_IPNAME1_REG_OFST         _UINT32_(0xF4)      /* (CPKCC_IPNAME1) IPNAME1 Register Offset */
#define CPKCC_FEATURES_REG_OFST        _UINT32_(0xF8)      /* (CPKCC_FEATURES) FEATURES Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief CPKCC register API structure */
typedef struct
{  /* Classic Public Key Cryptography Controller */
  __IO  uint32_t                       CPKCC_R;            /**< Offset: 0x00 (R/W  32) R Parameter Register */
  __IO  uint32_t                       CPKCC_X;            /**< Offset: 0x04 (R/W  32) X Parameter Register */
  __IO  uint32_t                       CPKCC_Y;            /**< Offset: 0x08 (R/W  32) Y Parameter Register */
  __IO  uint32_t                       CPKCC_Z;            /**< Offset: 0x0C (R/W  32) Z Parameter Register */
  __IO  uint32_t                       CPKCC_J;            /**< Offset: 0x10 (R/W  32) J Parameter Register */
  __IO  uint32_t                       CPKCC_K;            /**< Offset: 0x14 (R/W  32) K Parameter Register */
  __IO  uint32_t                       CPKCC_N;            /**< Offset: 0x18 (R/W  32) N Parameter Register */
  __IO  uint32_t                       CPKCC_SMULA;        /**< Offset: 0x1C (R/W  32) SMULA Register */
  __IO  uint32_t                       CPKCC_SMULB;        /**< Offset: 0x20 (R/W  32) SMULB Register */
  __IO  uint32_t                       CPKCC_SMULRL;       /**< Offset: 0x24 (R/W  32) SMULRL Register */
  __IO  uint32_t                       CPKCC_SMULRH;       /**< Offset: 0x28 (R/W  32) SMULRH Register */
  __IO  uint8_t                        CPKCC_IDLE;         /**< Offset: 0x2C (R/W  8) IDLE Register */
  __IO  uint8_t                        CPKCC_IDLECACHE;    /**< Offset: 0x2D (R/W  8) IDLECACHE Register */
  __I   uint8_t                        Reserved1[0x02];
  __IO  uint32_t                       CPKCC_CR_C;         /**< Offset: 0x30 (R/W  32) CR_C Register */
  __IO  uint32_t                       CPKCC_CR_S;         /**< Offset: 0x34 (R/W  32) CR_S Register */
  __IO  uint32_t                       CPKCC_CR;           /**< Offset: 0x38 (R/W  32) CR Register */
  __IO  uint32_t                       CPKCC_OR;           /**< Offset: 0x3C (R/W  32) Operation Register */
  __IO  uint32_t                       CPKCC_SR;           /**< Offset: 0x40 (R/W  32) SR Register */
  __I   uint8_t                        Reserved2[0xA8];
  __IO  uint32_t                       CPKCC_ADDRSIZE;     /**< Offset: 0xEC (R/W  32) ADDRSIZE Register */
  __IO  uint32_t                       CPKCC_IPNAME[2];    /**< Offset: 0xF0 (R/W  32) IPNAME1 Register */
  __IO  uint32_t                       CPKCC_FEATURES;     /**< Offset: 0xF8 (R/W  32) FEATURES Register */
} cpkcc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAMA7G_CPKCC_COMPONENT_H_ */
