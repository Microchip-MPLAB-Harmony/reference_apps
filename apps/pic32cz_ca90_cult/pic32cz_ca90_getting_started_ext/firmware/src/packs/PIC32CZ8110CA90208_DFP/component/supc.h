/*
 * Component description for SUPC
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
#ifndef _PIC32CZCA90_SUPC_COMPONENT_H_
#define _PIC32CZCA90_SUPC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR SUPC                                         */
/* ************************************************************************** */

/* -------- SUPC_INTENCLR : (SUPC Offset: 0x00) (R/W 32) Interrupt Enable Clear -------- */
#define SUPC_INTENCLR_RESETVALUE              _UINT32_(0x00)                                       /*  (SUPC_INTENCLR) Interrupt Enable Clear  Reset Value */

#define SUPC_INTENCLR_LVDET_Pos               _UINT32_(0)                                          /* (SUPC_INTENCLR) Low Voltage Detector Interrupt Enable Position */
#define SUPC_INTENCLR_LVDET_Msk               (_UINT32_(0x1) << SUPC_INTENCLR_LVDET_Pos)           /* (SUPC_INTENCLR) Low Voltage Detector Interrupt Enable Mask */
#define SUPC_INTENCLR_LVDET(value)            (SUPC_INTENCLR_LVDET_Msk & (_UINT32_(value) << SUPC_INTENCLR_LVDET_Pos)) /* Assigment of value for LVDET in the SUPC_INTENCLR register */
#define SUPC_INTENCLR_LVDRDY_Pos              _UINT32_(1)                                          /* (SUPC_INTENCLR) Low Voltage Detector Ready Interrupt Enable Position */
#define SUPC_INTENCLR_LVDRDY_Msk              (_UINT32_(0x1) << SUPC_INTENCLR_LVDRDY_Pos)          /* (SUPC_INTENCLR) Low Voltage Detector Ready Interrupt Enable Mask */
#define SUPC_INTENCLR_LVDRDY(value)           (SUPC_INTENCLR_LVDRDY_Msk & (_UINT32_(value) << SUPC_INTENCLR_LVDRDY_Pos)) /* Assigment of value for LVDRDY in the SUPC_INTENCLR register */
#define SUPC_INTENCLR_BORVDDUSB_Pos           _UINT32_(5)                                          /* (SUPC_INTENCLR) BORVDDUSB Interrupt Enable Position */
#define SUPC_INTENCLR_BORVDDUSB_Msk           (_UINT32_(0x3) << SUPC_INTENCLR_BORVDDUSB_Pos)       /* (SUPC_INTENCLR) BORVDDUSB Interrupt Enable Mask */
#define SUPC_INTENCLR_BORVDDUSB(value)        (SUPC_INTENCLR_BORVDDUSB_Msk & (_UINT32_(value) << SUPC_INTENCLR_BORVDDUSB_Pos)) /* Assigment of value for BORVDDUSB in the SUPC_INTENCLR register */
#define SUPC_INTENCLR_ADDVREGRDY0_Pos         _UINT32_(8)                                          /* (SUPC_INTENCLR) Additional Regulator ready 0 Interrupt Enable Position */
#define SUPC_INTENCLR_ADDVREGRDY0_Msk         (_UINT32_(0x1) << SUPC_INTENCLR_ADDVREGRDY0_Pos)     /* (SUPC_INTENCLR) Additional Regulator ready 0 Interrupt Enable Mask */
#define SUPC_INTENCLR_ADDVREGRDY0(value)      (SUPC_INTENCLR_ADDVREGRDY0_Msk & (_UINT32_(value) << SUPC_INTENCLR_ADDVREGRDY0_Pos)) /* Assigment of value for ADDVREGRDY0 in the SUPC_INTENCLR register */
#define SUPC_INTENCLR_ADDVREGRDY1_Pos         _UINT32_(9)                                          /* (SUPC_INTENCLR) Additional Regulator ready 1 Interrupt Enable Position */
#define SUPC_INTENCLR_ADDVREGRDY1_Msk         (_UINT32_(0x1) << SUPC_INTENCLR_ADDVREGRDY1_Pos)     /* (SUPC_INTENCLR) Additional Regulator ready 1 Interrupt Enable Mask */
#define SUPC_INTENCLR_ADDVREGRDY1(value)      (SUPC_INTENCLR_ADDVREGRDY1_Msk & (_UINT32_(value) << SUPC_INTENCLR_ADDVREGRDY1_Pos)) /* Assigment of value for ADDVREGRDY1 in the SUPC_INTENCLR register */
#define SUPC_INTENCLR_ADDVREGRDY2_Pos         _UINT32_(10)                                         /* (SUPC_INTENCLR) Additional Regulator ready 2 Interrupt Enable Position */
#define SUPC_INTENCLR_ADDVREGRDY2_Msk         (_UINT32_(0x1) << SUPC_INTENCLR_ADDVREGRDY2_Pos)     /* (SUPC_INTENCLR) Additional Regulator ready 2 Interrupt Enable Mask */
#define SUPC_INTENCLR_ADDVREGRDY2(value)      (SUPC_INTENCLR_ADDVREGRDY2_Msk & (_UINT32_(value) << SUPC_INTENCLR_ADDVREGRDY2_Pos)) /* Assigment of value for ADDVREGRDY2 in the SUPC_INTENCLR register */
#define SUPC_INTENCLR_Msk                     _UINT32_(0x00000763)                                 /* (SUPC_INTENCLR) Register Mask  */

#define SUPC_INTENCLR_ADDVREGRDY_Pos          _UINT32_(8)                                          /* (SUPC_INTENCLR Position) Additional Regulator ready 2 Interrupt Enable */
#define SUPC_INTENCLR_ADDVREGRDY_Msk          (_UINT32_(0x7) << SUPC_INTENCLR_ADDVREGRDY_Pos)      /* (SUPC_INTENCLR Mask) ADDVREGRDY */
#define SUPC_INTENCLR_ADDVREGRDY(value)       (SUPC_INTENCLR_ADDVREGRDY_Msk & (_UINT32_(value) << SUPC_INTENCLR_ADDVREGRDY_Pos)) 

/* -------- SUPC_INTENSET : (SUPC Offset: 0x04) (R/W 32) Interrupt Enable Set -------- */
#define SUPC_INTENSET_RESETVALUE              _UINT32_(0x00)                                       /*  (SUPC_INTENSET) Interrupt Enable Set  Reset Value */

#define SUPC_INTENSET_LVDET_Pos               _UINT32_(0)                                          /* (SUPC_INTENSET) Low Voltage Detector Interrupt Enable Position */
#define SUPC_INTENSET_LVDET_Msk               (_UINT32_(0x1) << SUPC_INTENSET_LVDET_Pos)           /* (SUPC_INTENSET) Low Voltage Detector Interrupt Enable Mask */
#define SUPC_INTENSET_LVDET(value)            (SUPC_INTENSET_LVDET_Msk & (_UINT32_(value) << SUPC_INTENSET_LVDET_Pos)) /* Assigment of value for LVDET in the SUPC_INTENSET register */
#define SUPC_INTENSET_LVDRDY_Pos              _UINT32_(1)                                          /* (SUPC_INTENSET) Low Voltage Detector Ready Interrupt Enable Position */
#define SUPC_INTENSET_LVDRDY_Msk              (_UINT32_(0x1) << SUPC_INTENSET_LVDRDY_Pos)          /* (SUPC_INTENSET) Low Voltage Detector Ready Interrupt Enable Mask */
#define SUPC_INTENSET_LVDRDY(value)           (SUPC_INTENSET_LVDRDY_Msk & (_UINT32_(value) << SUPC_INTENSET_LVDRDY_Pos)) /* Assigment of value for LVDRDY in the SUPC_INTENSET register */
#define SUPC_INTENSET_BORVDDUSB_Pos           _UINT32_(5)                                          /* (SUPC_INTENSET) BORVDDUSB Interrupt Enable Position */
#define SUPC_INTENSET_BORVDDUSB_Msk           (_UINT32_(0x3) << SUPC_INTENSET_BORVDDUSB_Pos)       /* (SUPC_INTENSET) BORVDDUSB Interrupt Enable Mask */
#define SUPC_INTENSET_BORVDDUSB(value)        (SUPC_INTENSET_BORVDDUSB_Msk & (_UINT32_(value) << SUPC_INTENSET_BORVDDUSB_Pos)) /* Assigment of value for BORVDDUSB in the SUPC_INTENSET register */
#define SUPC_INTENSET_ADDVREGRDY0_Pos         _UINT32_(8)                                          /* (SUPC_INTENSET) Additional Regulator ready 0 Interrupt Enable Position */
#define SUPC_INTENSET_ADDVREGRDY0_Msk         (_UINT32_(0x1) << SUPC_INTENSET_ADDVREGRDY0_Pos)     /* (SUPC_INTENSET) Additional Regulator ready 0 Interrupt Enable Mask */
#define SUPC_INTENSET_ADDVREGRDY0(value)      (SUPC_INTENSET_ADDVREGRDY0_Msk & (_UINT32_(value) << SUPC_INTENSET_ADDVREGRDY0_Pos)) /* Assigment of value for ADDVREGRDY0 in the SUPC_INTENSET register */
#define SUPC_INTENSET_ADDVREGRDY1_Pos         _UINT32_(9)                                          /* (SUPC_INTENSET) Additional Regulator ready 1 Interrupt Enable Position */
#define SUPC_INTENSET_ADDVREGRDY1_Msk         (_UINT32_(0x1) << SUPC_INTENSET_ADDVREGRDY1_Pos)     /* (SUPC_INTENSET) Additional Regulator ready 1 Interrupt Enable Mask */
#define SUPC_INTENSET_ADDVREGRDY1(value)      (SUPC_INTENSET_ADDVREGRDY1_Msk & (_UINT32_(value) << SUPC_INTENSET_ADDVREGRDY1_Pos)) /* Assigment of value for ADDVREGRDY1 in the SUPC_INTENSET register */
#define SUPC_INTENSET_ADDVREGRDY2_Pos         _UINT32_(10)                                         /* (SUPC_INTENSET) Additional Regulator ready 2 Interrupt Enable Position */
#define SUPC_INTENSET_ADDVREGRDY2_Msk         (_UINT32_(0x1) << SUPC_INTENSET_ADDVREGRDY2_Pos)     /* (SUPC_INTENSET) Additional Regulator ready 2 Interrupt Enable Mask */
#define SUPC_INTENSET_ADDVREGRDY2(value)      (SUPC_INTENSET_ADDVREGRDY2_Msk & (_UINT32_(value) << SUPC_INTENSET_ADDVREGRDY2_Pos)) /* Assigment of value for ADDVREGRDY2 in the SUPC_INTENSET register */
#define SUPC_INTENSET_Msk                     _UINT32_(0x00000763)                                 /* (SUPC_INTENSET) Register Mask  */

#define SUPC_INTENSET_ADDVREGRDY_Pos          _UINT32_(8)                                          /* (SUPC_INTENSET Position) Additional Regulator ready 2 Interrupt Enable */
#define SUPC_INTENSET_ADDVREGRDY_Msk          (_UINT32_(0x7) << SUPC_INTENSET_ADDVREGRDY_Pos)      /* (SUPC_INTENSET Mask) ADDVREGRDY */
#define SUPC_INTENSET_ADDVREGRDY(value)       (SUPC_INTENSET_ADDVREGRDY_Msk & (_UINT32_(value) << SUPC_INTENSET_ADDVREGRDY_Pos)) 

/* -------- SUPC_INTFLAG : (SUPC Offset: 0x08) (R/W 32) Interrupt Flag Status and Clear -------- */
#define SUPC_INTFLAG_RESETVALUE               _UINT32_(0x00)                                       /*  (SUPC_INTFLAG) Interrupt Flag Status and Clear  Reset Value */

#define SUPC_INTFLAG_LVDET_Pos                _UINT32_(0)                                          /* (SUPC_INTFLAG) Low Voltage Detector Interrupt. Set to one if VDDIO crosses the treshold voltage in the good direction according to LVD.DIR. Position */
#define SUPC_INTFLAG_LVDET_Msk                (_UINT32_(0x1) << SUPC_INTFLAG_LVDET_Pos)            /* (SUPC_INTFLAG) Low Voltage Detector Interrupt. Set to one if VDDIO crosses the treshold voltage in the good direction according to LVD.DIR. Mask */
#define SUPC_INTFLAG_LVDET(value)             (SUPC_INTFLAG_LVDET_Msk & (_UINT32_(value) << SUPC_INTFLAG_LVDET_Pos)) /* Assigment of value for LVDET in the SUPC_INTFLAG register */
#define SUPC_INTFLAG_LVDRDY_Pos               _UINT32_(1)                                          /* (SUPC_INTFLAG) Low Voltage Detector Ready Interrupt. Set to one if LVD is ready to operate. Position */
#define SUPC_INTFLAG_LVDRDY_Msk               (_UINT32_(0x1) << SUPC_INTFLAG_LVDRDY_Pos)           /* (SUPC_INTFLAG) Low Voltage Detector Ready Interrupt. Set to one if LVD is ready to operate. Mask */
#define SUPC_INTFLAG_LVDRDY(value)            (SUPC_INTFLAG_LVDRDY_Msk & (_UINT32_(value) << SUPC_INTFLAG_LVDRDY_Pos)) /* Assigment of value for LVDRDY in the SUPC_INTFLAG register */
#define SUPC_INTFLAG_BORVDDUSB_Pos            _UINT32_(5)                                          /* (SUPC_INTFLAG) BORVDDUSB Interrupt. Set to one if VDDUSB issue is detected. Position */
#define SUPC_INTFLAG_BORVDDUSB_Msk            (_UINT32_(0x3) << SUPC_INTFLAG_BORVDDUSB_Pos)        /* (SUPC_INTFLAG) BORVDDUSB Interrupt. Set to one if VDDUSB issue is detected. Mask */
#define SUPC_INTFLAG_BORVDDUSB(value)         (SUPC_INTFLAG_BORVDDUSB_Msk & (_UINT32_(value) << SUPC_INTFLAG_BORVDDUSB_Pos)) /* Assigment of value for BORVDDUSB in the SUPC_INTFLAG register */
#define SUPC_INTFLAG_ADDVREGRDY0_Pos          _UINT32_(8)                                          /* (SUPC_INTFLAG) Additional Regulator ready 0 Interrupt. Set to one if additionnal regulator is ready meaning that output voltage is correct. Position */
#define SUPC_INTFLAG_ADDVREGRDY0_Msk          (_UINT32_(0x1) << SUPC_INTFLAG_ADDVREGRDY0_Pos)      /* (SUPC_INTFLAG) Additional Regulator ready 0 Interrupt. Set to one if additionnal regulator is ready meaning that output voltage is correct. Mask */
#define SUPC_INTFLAG_ADDVREGRDY0(value)       (SUPC_INTFLAG_ADDVREGRDY0_Msk & (_UINT32_(value) << SUPC_INTFLAG_ADDVREGRDY0_Pos)) /* Assigment of value for ADDVREGRDY0 in the SUPC_INTFLAG register */
#define SUPC_INTFLAG_ADDVREGRDY1_Pos          _UINT32_(9)                                          /* (SUPC_INTFLAG) Additional Regulator ready 1 Interrupt. Set to one if additionnal regulator is ready meaning that output voltage is correct. Position */
#define SUPC_INTFLAG_ADDVREGRDY1_Msk          (_UINT32_(0x1) << SUPC_INTFLAG_ADDVREGRDY1_Pos)      /* (SUPC_INTFLAG) Additional Regulator ready 1 Interrupt. Set to one if additionnal regulator is ready meaning that output voltage is correct. Mask */
#define SUPC_INTFLAG_ADDVREGRDY1(value)       (SUPC_INTFLAG_ADDVREGRDY1_Msk & (_UINT32_(value) << SUPC_INTFLAG_ADDVREGRDY1_Pos)) /* Assigment of value for ADDVREGRDY1 in the SUPC_INTFLAG register */
#define SUPC_INTFLAG_ADDVREGRDY2_Pos          _UINT32_(10)                                         /* (SUPC_INTFLAG) Additional Regulator ready 2 Interrupt. Set to one if additionnal regulator is ready meaning that output voltage is correct. Position */
#define SUPC_INTFLAG_ADDVREGRDY2_Msk          (_UINT32_(0x1) << SUPC_INTFLAG_ADDVREGRDY2_Pos)      /* (SUPC_INTFLAG) Additional Regulator ready 2 Interrupt. Set to one if additionnal regulator is ready meaning that output voltage is correct. Mask */
#define SUPC_INTFLAG_ADDVREGRDY2(value)       (SUPC_INTFLAG_ADDVREGRDY2_Msk & (_UINT32_(value) << SUPC_INTFLAG_ADDVREGRDY2_Pos)) /* Assigment of value for ADDVREGRDY2 in the SUPC_INTFLAG register */
#define SUPC_INTFLAG_Msk                      _UINT32_(0x00000763)                                 /* (SUPC_INTFLAG) Register Mask  */

#define SUPC_INTFLAG_ADDVREGRDY_Pos           _UINT32_(8)                                          /* (SUPC_INTFLAG Position) Additional Regulator ready 2 Interrupt. Set to one if additionnal regulator is ready meaning that output voltage is correct. */
#define SUPC_INTFLAG_ADDVREGRDY_Msk           (_UINT32_(0x7) << SUPC_INTFLAG_ADDVREGRDY_Pos)       /* (SUPC_INTFLAG Mask) ADDVREGRDY */
#define SUPC_INTFLAG_ADDVREGRDY(value)        (SUPC_INTFLAG_ADDVREGRDY_Msk & (_UINT32_(value) << SUPC_INTFLAG_ADDVREGRDY_Pos)) 

/* -------- SUPC_STATUS : (SUPC Offset: 0x0C) ( R/ 32) Flag status -------- */
#define SUPC_STATUS_RESETVALUE                _UINT32_(0x00)                                       /*  (SUPC_STATUS) Flag status  Reset Value */

#define SUPC_STATUS_LVDET_Pos                 _UINT32_(0)                                          /* (SUPC_STATUS) Low Voltage Detector Status. Position */
#define SUPC_STATUS_LVDET_Msk                 (_UINT32_(0x1) << SUPC_STATUS_LVDET_Pos)             /* (SUPC_STATUS) Low Voltage Detector Status. Mask */
#define SUPC_STATUS_LVDET(value)              (SUPC_STATUS_LVDET_Msk & (_UINT32_(value) << SUPC_STATUS_LVDET_Pos)) /* Assigment of value for LVDET in the SUPC_STATUS register */
#define SUPC_STATUS_LVDRDY_Pos                _UINT32_(1)                                          /* (SUPC_STATUS) Low Voltage Detector Ready Status Position */
#define SUPC_STATUS_LVDRDY_Msk                (_UINT32_(0x1) << SUPC_STATUS_LVDRDY_Pos)            /* (SUPC_STATUS) Low Voltage Detector Ready Status Mask */
#define SUPC_STATUS_LVDRDY(value)             (SUPC_STATUS_LVDRDY_Msk & (_UINT32_(value) << SUPC_STATUS_LVDRDY_Pos)) /* Assigment of value for LVDRDY in the SUPC_STATUS register */
#define SUPC_STATUS_BORVDDUSB_Pos             _UINT32_(5)                                          /* (SUPC_STATUS) BORVDDUSB Status. One if VDDUSB is OK. It corresponds to bor_vddusb_n_mv signal of SMOR. Position */
#define SUPC_STATUS_BORVDDUSB_Msk             (_UINT32_(0x3) << SUPC_STATUS_BORVDDUSB_Pos)         /* (SUPC_STATUS) BORVDDUSB Status. One if VDDUSB is OK. It corresponds to bor_vddusb_n_mv signal of SMOR. Mask */
#define SUPC_STATUS_BORVDDUSB(value)          (SUPC_STATUS_BORVDDUSB_Msk & (_UINT32_(value) << SUPC_STATUS_BORVDDUSB_Pos)) /* Assigment of value for BORVDDUSB in the SUPC_STATUS register */
#define SUPC_STATUS_ADDVREGRDY0_Pos           _UINT32_(8)                                          /* (SUPC_STATUS) Additional Regulator ready 0 Status. One if voltage is OK. It corresponds to vreg_ready_mv signal of additional regulator. Position */
#define SUPC_STATUS_ADDVREGRDY0_Msk           (_UINT32_(0x1) << SUPC_STATUS_ADDVREGRDY0_Pos)       /* (SUPC_STATUS) Additional Regulator ready 0 Status. One if voltage is OK. It corresponds to vreg_ready_mv signal of additional regulator. Mask */
#define SUPC_STATUS_ADDVREGRDY0(value)        (SUPC_STATUS_ADDVREGRDY0_Msk & (_UINT32_(value) << SUPC_STATUS_ADDVREGRDY0_Pos)) /* Assigment of value for ADDVREGRDY0 in the SUPC_STATUS register */
#define SUPC_STATUS_ADDVREGRDY1_Pos           _UINT32_(9)                                          /* (SUPC_STATUS) Additional Regulator ready 1 Status. One if voltage is OK. It corresponds to vreg_ready_mv signal of additional regulator. Position */
#define SUPC_STATUS_ADDVREGRDY1_Msk           (_UINT32_(0x1) << SUPC_STATUS_ADDVREGRDY1_Pos)       /* (SUPC_STATUS) Additional Regulator ready 1 Status. One if voltage is OK. It corresponds to vreg_ready_mv signal of additional regulator. Mask */
#define SUPC_STATUS_ADDVREGRDY1(value)        (SUPC_STATUS_ADDVREGRDY1_Msk & (_UINT32_(value) << SUPC_STATUS_ADDVREGRDY1_Pos)) /* Assigment of value for ADDVREGRDY1 in the SUPC_STATUS register */
#define SUPC_STATUS_ADDVREGRDY2_Pos           _UINT32_(10)                                         /* (SUPC_STATUS) Additional Regulator ready 2 Status. One if voltage is OK. It corresponds to vreg_ready_mv signal of additional regulator. Position */
#define SUPC_STATUS_ADDVREGRDY2_Msk           (_UINT32_(0x1) << SUPC_STATUS_ADDVREGRDY2_Pos)       /* (SUPC_STATUS) Additional Regulator ready 2 Status. One if voltage is OK. It corresponds to vreg_ready_mv signal of additional regulator. Mask */
#define SUPC_STATUS_ADDVREGRDY2(value)        (SUPC_STATUS_ADDVREGRDY2_Msk & (_UINT32_(value) << SUPC_STATUS_ADDVREGRDY2_Pos)) /* Assigment of value for ADDVREGRDY2 in the SUPC_STATUS register */
#define SUPC_STATUS_Msk                       _UINT32_(0x00000763)                                 /* (SUPC_STATUS) Register Mask  */

#define SUPC_STATUS_ADDVREGRDY_Pos            _UINT32_(8)                                          /* (SUPC_STATUS Position) Additional Regulator ready 2 Status. One if voltage is OK. It corresponds to vreg_ready_mv signal of additional regulator. */
#define SUPC_STATUS_ADDVREGRDY_Msk            (_UINT32_(0x7) << SUPC_STATUS_ADDVREGRDY_Pos)        /* (SUPC_STATUS Mask) ADDVREGRDY */
#define SUPC_STATUS_ADDVREGRDY(value)         (SUPC_STATUS_ADDVREGRDY_Msk & (_UINT32_(value) << SUPC_STATUS_ADDVREGRDY_Pos)) 

/* -------- SUPC_SYNCBUSY : (SUPC Offset: 0x10) ( R/ 32) Synchronisation Busy -------- */
#define SUPC_SYNCBUSY_RESETVALUE              _UINT32_(0x00)                                       /*  (SUPC_SYNCBUSY) Synchronisation Busy  Reset Value */

#define SUPC_SYNCBUSY_BOR_Pos                 _UINT32_(0)                                          /* (SUPC_SYNCBUSY) BOR Synchronization Busy Position */
#define SUPC_SYNCBUSY_BOR_Msk                 (_UINT32_(0x1) << SUPC_SYNCBUSY_BOR_Pos)             /* (SUPC_SYNCBUSY) BOR Synchronization Busy Mask */
#define SUPC_SYNCBUSY_BOR(value)              (SUPC_SYNCBUSY_BOR_Msk & (_UINT32_(value) << SUPC_SYNCBUSY_BOR_Pos)) /* Assigment of value for BOR in the SUPC_SYNCBUSY register */
#define SUPC_SYNCBUSY_Msk                     _UINT32_(0x00000001)                                 /* (SUPC_SYNCBUSY) Register Mask  */


/* -------- SUPC_BOR : (SUPC Offset: 0x14) (R/W 32) BOR Control -------- */
#define SUPC_BOR_RESETVALUE                   _UINT32_(0x00)                                       /*  (SUPC_BOR) BOR Control  Reset Value */

#define SUPC_BOR_DCBORPSEL_Pos                _UINT32_(4)                                          /* (SUPC_BOR) Duty Cycle BOR Prescaler Select Position */
#define SUPC_BOR_DCBORPSEL_Msk                (_UINT32_(0x7) << SUPC_BOR_DCBORPSEL_Pos)            /* (SUPC_BOR) Duty Cycle BOR Prescaler Select Mask */
#define SUPC_BOR_DCBORPSEL(value)             (SUPC_BOR_DCBORPSEL_Msk & (_UINT32_(value) << SUPC_BOR_DCBORPSEL_Pos)) /* Assigment of value for DCBORPSEL in the SUPC_BOR register */
#define   SUPC_BOR_DCBORPSEL_NODIV_Val        _UINT32_(0x0)                                        /* (SUPC_BOR) Not Divided  */
#define   SUPC_BOR_DCBORPSEL_DIV2_Val         _UINT32_(0x1)                                        /* (SUPC_BOR) Divide clock by 2  */
#define   SUPC_BOR_DCBORPSEL_DIV4_Val         _UINT32_(0x2)                                        /* (SUPC_BOR) Divide clock by 4  */
#define   SUPC_BOR_DCBORPSEL_DIV8_Val         _UINT32_(0x3)                                        /* (SUPC_BOR) Divide clock by 8  */
#define   SUPC_BOR_DCBORPSEL_DIV16_Val        _UINT32_(0x4)                                        /* (SUPC_BOR) Divide clock by 16  */
#define   SUPC_BOR_DCBORPSEL_DIV32_Val        _UINT32_(0x5)                                        /* (SUPC_BOR) Divide clock by 32  */
#define   SUPC_BOR_DCBORPSEL_DIV64_Val        _UINT32_(0x6)                                        /* (SUPC_BOR) Divide clock by 64  */
#define   SUPC_BOR_DCBORPSEL_DIV128_Val       _UINT32_(0x7)                                        /* (SUPC_BOR) Divide clock by 128  */
#define SUPC_BOR_DCBORPSEL_NODIV              (SUPC_BOR_DCBORPSEL_NODIV_Val << SUPC_BOR_DCBORPSEL_Pos) /* (SUPC_BOR) Not Divided Position  */
#define SUPC_BOR_DCBORPSEL_DIV2               (SUPC_BOR_DCBORPSEL_DIV2_Val << SUPC_BOR_DCBORPSEL_Pos) /* (SUPC_BOR) Divide clock by 2 Position  */
#define SUPC_BOR_DCBORPSEL_DIV4               (SUPC_BOR_DCBORPSEL_DIV4_Val << SUPC_BOR_DCBORPSEL_Pos) /* (SUPC_BOR) Divide clock by 4 Position  */
#define SUPC_BOR_DCBORPSEL_DIV8               (SUPC_BOR_DCBORPSEL_DIV8_Val << SUPC_BOR_DCBORPSEL_Pos) /* (SUPC_BOR) Divide clock by 8 Position  */
#define SUPC_BOR_DCBORPSEL_DIV16              (SUPC_BOR_DCBORPSEL_DIV16_Val << SUPC_BOR_DCBORPSEL_Pos) /* (SUPC_BOR) Divide clock by 16 Position  */
#define SUPC_BOR_DCBORPSEL_DIV32              (SUPC_BOR_DCBORPSEL_DIV32_Val << SUPC_BOR_DCBORPSEL_Pos) /* (SUPC_BOR) Divide clock by 32 Position  */
#define SUPC_BOR_DCBORPSEL_DIV64              (SUPC_BOR_DCBORPSEL_DIV64_Val << SUPC_BOR_DCBORPSEL_Pos) /* (SUPC_BOR) Divide clock by 64 Position  */
#define SUPC_BOR_DCBORPSEL_DIV128             (SUPC_BOR_DCBORPSEL_DIV128_Val << SUPC_BOR_DCBORPSEL_Pos) /* (SUPC_BOR) Divide clock by 128 Position  */
#define SUPC_BOR_BORFILT_Pos                  _UINT32_(8)                                          /* (SUPC_BOR) BOR filtering Position */
#define SUPC_BOR_BORFILT_Msk                  (_UINT32_(0x3) << SUPC_BOR_BORFILT_Pos)              /* (SUPC_BOR) BOR filtering Mask */
#define SUPC_BOR_BORFILT(value)               (SUPC_BOR_BORFILT_Msk & (_UINT32_(value) << SUPC_BOR_BORFILT_Pos)) /* Assigment of value for BORFILT in the SUPC_BOR register */
#define   SUPC_BOR_BORFILT_NOFILT_Val         _UINT32_(0x0)                                        /* (SUPC_BOR) No digital filtering  */
#define   SUPC_BOR_BORFILT_FILT32US_Val       _UINT32_(0x1)                                        /* (SUPC_BOR) 32us filtering  */
#define   SUPC_BOR_BORFILT_FILT125US_Val      _UINT32_(0x2)                                        /* (SUPC_BOR) 125us filtering  */
#define   SUPC_BOR_BORFILT_FILT250US_Val      _UINT32_(0x3)                                        /* (SUPC_BOR) 250us filtering  */
#define SUPC_BOR_BORFILT_NOFILT               (SUPC_BOR_BORFILT_NOFILT_Val << SUPC_BOR_BORFILT_Pos) /* (SUPC_BOR) No digital filtering Position  */
#define SUPC_BOR_BORFILT_FILT32US             (SUPC_BOR_BORFILT_FILT32US_Val << SUPC_BOR_BORFILT_Pos) /* (SUPC_BOR) 32us filtering Position  */
#define SUPC_BOR_BORFILT_FILT125US            (SUPC_BOR_BORFILT_FILT125US_Val << SUPC_BOR_BORFILT_Pos) /* (SUPC_BOR) 125us filtering Position  */
#define SUPC_BOR_BORFILT_FILT250US            (SUPC_BOR_BORFILT_FILT250US_Val << SUPC_BOR_BORFILT_Pos) /* (SUPC_BOR) 250us filtering Position  */
#define SUPC_BOR_Msk                          _UINT32_(0x00000370)                                 /* (SUPC_BOR) Register Mask  */


/* -------- SUPC_LVD : (SUPC Offset: 0x18) (R/W 32) LVD Control -------- */
#define SUPC_LVD_RESETVALUE                   _UINT32_(0x00)                                       /*  (SUPC_LVD) LVD Control  Reset Value */

#define SUPC_LVD_ENABLE_Pos                   _UINT32_(1)                                          /* (SUPC_LVD) Enable Position */
#define SUPC_LVD_ENABLE_Msk                   (_UINT32_(0x1) << SUPC_LVD_ENABLE_Pos)               /* (SUPC_LVD) Enable Mask */
#define SUPC_LVD_ENABLE(value)                (SUPC_LVD_ENABLE_Msk & (_UINT32_(value) << SUPC_LVD_ENABLE_Pos)) /* Assigment of value for ENABLE in the SUPC_LVD register */
#define SUPC_LVD_DIR_Pos                      _UINT32_(2)                                          /* (SUPC_LVD) Direction Position */
#define SUPC_LVD_DIR_Msk                      (_UINT32_(0x1) << SUPC_LVD_DIR_Pos)                  /* (SUPC_LVD) Direction Mask */
#define SUPC_LVD_DIR(value)                   (SUPC_LVD_DIR_Msk & (_UINT32_(value) << SUPC_LVD_DIR_Pos)) /* Assigment of value for DIR in the SUPC_LVD register */
#define   SUPC_LVD_DIR_rising_Val             _UINT32_(0x0)                                        /* (SUPC_LVD) Rising detection  */
#define   SUPC_LVD_DIR_falling_Val            _UINT32_(0x1)                                        /* (SUPC_LVD) Falling detection  */
#define SUPC_LVD_DIR_rising                   (SUPC_LVD_DIR_rising_Val << SUPC_LVD_DIR_Pos)        /* (SUPC_LVD) Rising detection Position  */
#define SUPC_LVD_DIR_falling                  (SUPC_LVD_DIR_falling_Val << SUPC_LVD_DIR_Pos)       /* (SUPC_LVD) Falling detection Position  */
#define SUPC_LVD_OEVEN_Pos                    _UINT32_(3)                                          /* (SUPC_LVD) Output Event Enable Position */
#define SUPC_LVD_OEVEN_Msk                    (_UINT32_(0x1) << SUPC_LVD_OEVEN_Pos)                /* (SUPC_LVD) Output Event Enable Mask */
#define SUPC_LVD_OEVEN(value)                 (SUPC_LVD_OEVEN_Msk & (_UINT32_(value) << SUPC_LVD_OEVEN_Pos)) /* Assigment of value for OEVEN in the SUPC_LVD register */
#define SUPC_LVD_RUNSTDBY_Pos                 _UINT32_(4)                                          /* (SUPC_LVD) Run during Standby Position */
#define SUPC_LVD_RUNSTDBY_Msk                 (_UINT32_(0x1) << SUPC_LVD_RUNSTDBY_Pos)             /* (SUPC_LVD) Run during Standby Mask */
#define SUPC_LVD_RUNSTDBY(value)              (SUPC_LVD_RUNSTDBY_Msk & (_UINT32_(value) << SUPC_LVD_RUNSTDBY_Pos)) /* Assigment of value for RUNSTDBY in the SUPC_LVD register */
#define SUPC_LVD_LEVEL_Pos                    _UINT32_(16)                                         /* (SUPC_LVD) Threshold Level. See "pwr_smor_[nn]_v1 DOS" - level section to get details. Position */
#define SUPC_LVD_LEVEL_Msk                    (_UINT32_(0xF) << SUPC_LVD_LEVEL_Pos)                /* (SUPC_LVD) Threshold Level. See "pwr_smor_[nn]_v1 DOS" - level section to get details. Mask */
#define SUPC_LVD_LEVEL(value)                 (SUPC_LVD_LEVEL_Msk & (_UINT32_(value) << SUPC_LVD_LEVEL_Pos)) /* Assigment of value for LEVEL in the SUPC_LVD register */
#define SUPC_LVD_Msk                          _UINT32_(0x000F001E)                                 /* (SUPC_LVD) Register Mask  */


/* -------- SUPC_VREGCTRL : (SUPC Offset: 0x1C) (R/W 32) VREG Control -------- */
#define SUPC_VREGCTRL_RESETVALUE              _UINT32_(0x30)                                       /*  (SUPC_VREGCTRL) VREG Control  Reset Value */

#define SUPC_VREGCTRL_VREGOUT_Pos             _UINT32_(0)                                          /* (SUPC_VREGCTRL) VREG Output Control in RUN mode only. Enable by production fuse by CALSUPC.VREGOUTEN Position */
#define SUPC_VREGCTRL_VREGOUT_Msk             (_UINT32_(0x3) << SUPC_VREGCTRL_VREGOUT_Pos)         /* (SUPC_VREGCTRL) VREG Output Control in RUN mode only. Enable by production fuse by CALSUPC.VREGOUTEN Mask */
#define SUPC_VREGCTRL_VREGOUT(value)          (SUPC_VREGCTRL_VREGOUT_Msk & (_UINT32_(value) << SUPC_VREGCTRL_VREGOUT_Pos)) /* Assigment of value for VREGOUT in the SUPC_VREGCTRL register */
#define   SUPC_VREGCTRL_VREGOUT_1p2v_Val      _UINT32_(0x0)                                        /* (SUPC_VREGCTRL) In Active mode, VDDCORE_RAM, VDDCORE_BU, VDDCORE_SW and optionnaly VDDCORE_PLL USB are set to 1.2v.  */
#define   SUPC_VREGCTRL_VREGOUT_1p0v_Val      _UINT32_(0x1)                                        /* (SUPC_VREGCTRL) In Active mode, VDDCORE_RAM, VDDCORE_BU, VDDCORE_SW and optionnaly VDDCORE_PLL USB are set to 1.0v.  */
#define   SUPC_VREGCTRL_VREGOUT_0p8v_Val      _UINT32_(0x2)                                        /* (SUPC_VREGCTRL) In Active mode, VDDCORE_RAM, VDDCORE_BU, VDDCORE_SW and optionnaly VDDCORE_PLL USB are set to 0.8v.  */
#define SUPC_VREGCTRL_VREGOUT_1p2v            (SUPC_VREGCTRL_VREGOUT_1p2v_Val << SUPC_VREGCTRL_VREGOUT_Pos) /* (SUPC_VREGCTRL) In Active mode, VDDCORE_RAM, VDDCORE_BU, VDDCORE_SW and optionnaly VDDCORE_PLL USB are set to 1.2v. Position  */
#define SUPC_VREGCTRL_VREGOUT_1p0v            (SUPC_VREGCTRL_VREGOUT_1p0v_Val << SUPC_VREGCTRL_VREGOUT_Pos) /* (SUPC_VREGCTRL) In Active mode, VDDCORE_RAM, VDDCORE_BU, VDDCORE_SW and optionnaly VDDCORE_PLL USB are set to 1.0v. Position  */
#define SUPC_VREGCTRL_VREGOUT_0p8v            (SUPC_VREGCTRL_VREGOUT_0p8v_Val << SUPC_VREGCTRL_VREGOUT_Pos) /* (SUPC_VREGCTRL) In Active mode, VDDCORE_RAM, VDDCORE_BU, VDDCORE_SW and optionnaly VDDCORE_PLL USB are set to 0.8v. Position  */
#define SUPC_VREGCTRL_OFFSTDBY_Pos            _UINT32_(2)                                          /* (SUPC_VREGCTRL) Off in Standby Control for VREGSW[N-1]. Useful for Riverside only. Position */
#define SUPC_VREGCTRL_OFFSTDBY_Msk            (_UINT32_(0x1) << SUPC_VREGCTRL_OFFSTDBY_Pos)        /* (SUPC_VREGCTRL) Off in Standby Control for VREGSW[N-1]. Useful for Riverside only. Mask */
#define SUPC_VREGCTRL_OFFSTDBY(value)         (SUPC_VREGCTRL_OFFSTDBY_Msk & (_UINT32_(value) << SUPC_VREGCTRL_OFFSTDBY_Pos)) /* Assigment of value for OFFSTDBY in the SUPC_VREGCTRL register */
#define   SUPC_VREGCTRL_OFFSTDBY_OFF_Val      _UINT32_(0x0)                                        /* (SUPC_VREGCTRL) In standby mode, VREGSW1,2,3 are OFF  */
#define   SUPC_VREGCTRL_OFFSTDBY_ON_Val       _UINT32_(0x1)                                        /* (SUPC_VREGCTRL) In standby mode, VREGSW1,2,3 are ON  */
#define SUPC_VREGCTRL_OFFSTDBY_OFF            (SUPC_VREGCTRL_OFFSTDBY_OFF_Val << SUPC_VREGCTRL_OFFSTDBY_Pos) /* (SUPC_VREGCTRL) In standby mode, VREGSW1,2,3 are OFF Position  */
#define SUPC_VREGCTRL_OFFSTDBY_ON             (SUPC_VREGCTRL_OFFSTDBY_ON_Val << SUPC_VREGCTRL_OFFSTDBY_Pos) /* (SUPC_VREGCTRL) In standby mode, VREGSW1,2,3 are ON Position  */
#define SUPC_VREGCTRL_SRAM_VLD_Pos            _UINT32_(4)                                          /* (SUPC_VREGCTRL) SRAM Valid Status Bit Position */
#define SUPC_VREGCTRL_SRAM_VLD_Msk            (_UINT32_(0x1) << SUPC_VREGCTRL_SRAM_VLD_Pos)        /* (SUPC_VREGCTRL) SRAM Valid Status Bit Mask */
#define SUPC_VREGCTRL_SRAM_VLD(value)         (SUPC_VREGCTRL_SRAM_VLD_Msk & (_UINT32_(value) << SUPC_VREGCTRL_SRAM_VLD_Pos)) /* Assigment of value for SRAM_VLD in the SUPC_VREGCTRL register */
#define SUPC_VREGCTRL_BKUP_VLD_Pos            _UINT32_(5)                                          /* (SUPC_VREGCTRL) Backup Valid Status Bit Position */
#define SUPC_VREGCTRL_BKUP_VLD_Msk            (_UINT32_(0x1) << SUPC_VREGCTRL_BKUP_VLD_Pos)        /* (SUPC_VREGCTRL) Backup Valid Status Bit Mask */
#define SUPC_VREGCTRL_BKUP_VLD(value)         (SUPC_VREGCTRL_BKUP_VLD_Msk & (_UINT32_(value) << SUPC_VREGCTRL_BKUP_VLD_Pos)) /* Assigment of value for BKUP_VLD in the SUPC_VREGCTRL register */
#define SUPC_VREGCTRL_CPEN_Pos                _UINT32_(8)                                          /* (SUPC_VREGCTRL) Charge Pump Enable and Auto-enable. Position */
#define SUPC_VREGCTRL_CPEN_Msk                (_UINT32_(0x7) << SUPC_VREGCTRL_CPEN_Pos)            /* (SUPC_VREGCTRL) Charge Pump Enable and Auto-enable. Mask */
#define SUPC_VREGCTRL_CPEN(value)             (SUPC_VREGCTRL_CPEN_Msk & (_UINT32_(value) << SUPC_VREGCTRL_CPEN_Pos)) /* Assigment of value for CPEN in the SUPC_VREGCTRL register */
#define SUPC_VREGCTRL_AVREGEN_Pos             _UINT32_(16)                                         /* (SUPC_VREGCTRL) Additional Voltage Regulator Enable Position */
#define SUPC_VREGCTRL_AVREGEN_Msk             (_UINT32_(0x7) << SUPC_VREGCTRL_AVREGEN_Pos)         /* (SUPC_VREGCTRL) Additional Voltage Regulator Enable Mask */
#define SUPC_VREGCTRL_AVREGEN(value)          (SUPC_VREGCTRL_AVREGEN_Msk & (_UINT32_(value) << SUPC_VREGCTRL_AVREGEN_Pos)) /* Assigment of value for AVREGEN in the SUPC_VREGCTRL register */
#define SUPC_VREGCTRL_AVREGSTDBY_Pos          _UINT32_(24)                                         /* (SUPC_VREGCTRL) Additional Voltage Regulator Configuration Position */
#define SUPC_VREGCTRL_AVREGSTDBY_Msk          (_UINT32_(0x7) << SUPC_VREGCTRL_AVREGSTDBY_Pos)      /* (SUPC_VREGCTRL) Additional Voltage Regulator Configuration Mask */
#define SUPC_VREGCTRL_AVREGSTDBY(value)       (SUPC_VREGCTRL_AVREGSTDBY_Msk & (_UINT32_(value) << SUPC_VREGCTRL_AVREGSTDBY_Pos)) /* Assigment of value for AVREGSTDBY in the SUPC_VREGCTRL register */
#define   SUPC_VREGCTRL_AVREGSTDBY_OFFINSTDBY_Val _UINT32_(0x0)                                        /* (SUPC_VREGCTRL) Regulator is OFF while in sleep mode equal or deeper than standby mode. It is OFF in hibernate and backup mode as well.  */
#define   SUPC_VREGCTRL_AVREGSTDBY_ONINSTDBY_Val _UINT32_(0x1)                                        /* (SUPC_VREGCTRL) Regulator is ON in Standby mode if AVREGEN bit is set. is OFF from Hibernate mode. It is OFF in backup mode as well.  */
#define SUPC_VREGCTRL_AVREGSTDBY_OFFINSTDBY   (SUPC_VREGCTRL_AVREGSTDBY_OFFINSTDBY_Val << SUPC_VREGCTRL_AVREGSTDBY_Pos) /* (SUPC_VREGCTRL) Regulator is OFF while in sleep mode equal or deeper than standby mode. It is OFF in hibernate and backup mode as well. Position  */
#define SUPC_VREGCTRL_AVREGSTDBY_ONINSTDBY    (SUPC_VREGCTRL_AVREGSTDBY_ONINSTDBY_Val << SUPC_VREGCTRL_AVREGSTDBY_Pos) /* (SUPC_VREGCTRL) Regulator is ON in Standby mode if AVREGEN bit is set. is OFF from Hibernate mode. It is OFF in backup mode as well. Position  */
#define SUPC_VREGCTRL_Msk                     _UINT32_(0x07070737)                                 /* (SUPC_VREGCTRL) Register Mask  */


/* -------- SUPC_VREFCTRL : (SUPC Offset: 0x20) (R/W 32) VREF Control -------- */
#define SUPC_VREFCTRL_RESETVALUE              _UINT32_(0x03)                                       /*  (SUPC_VREFCTRL) VREF Control  Reset Value */

#define SUPC_VREFCTRL_LPSTDBY_Pos             _UINT32_(0)                                          /* (SUPC_VREFCTRL) Bandgap and Regulators Low Power Standby Enable Position */
#define SUPC_VREFCTRL_LPSTDBY_Msk             (_UINT32_(0x1) << SUPC_VREFCTRL_LPSTDBY_Pos)         /* (SUPC_VREFCTRL) Bandgap and Regulators Low Power Standby Enable Mask */
#define SUPC_VREFCTRL_LPSTDBY(value)          (SUPC_VREFCTRL_LPSTDBY_Msk & (_UINT32_(value) << SUPC_VREFCTRL_LPSTDBY_Pos)) /* Assigment of value for LPSTDBY in the SUPC_VREFCTRL register */
#define   SUPC_VREFCTRL_LPSTDBY_FullPower_Val _UINT32_(0x0)                                        /* (SUPC_VREFCTRL) In standby mode, bandgap and enabled regulator(s) are set to nominal power mode.  */
#define   SUPC_VREFCTRL_LPSTDBY_LowPower_Val  _UINT32_(0x1)                                        /* (SUPC_VREFCTRL) In standby mode, bandgap and enabled regulator(s) are set to low power mode.  */
#define SUPC_VREFCTRL_LPSTDBY_FullPower       (SUPC_VREFCTRL_LPSTDBY_FullPower_Val << SUPC_VREFCTRL_LPSTDBY_Pos) /* (SUPC_VREFCTRL) In standby mode, bandgap and enabled regulator(s) are set to nominal power mode. Position  */
#define SUPC_VREFCTRL_LPSTDBY_LowPower        (SUPC_VREFCTRL_LPSTDBY_LowPower_Val << SUPC_VREFCTRL_LPSTDBY_Pos) /* (SUPC_VREFCTRL) In standby mode, bandgap and enabled regulator(s) are set to low power mode. Position  */
#define SUPC_VREFCTRL_LPHIB_Pos               _UINT32_(1)                                          /* (SUPC_VREFCTRL) Bandgap and Regulators Low Power Hibernate Enable Position */
#define SUPC_VREFCTRL_LPHIB_Msk               (_UINT32_(0x1) << SUPC_VREFCTRL_LPHIB_Pos)           /* (SUPC_VREFCTRL) Bandgap and Regulators Low Power Hibernate Enable Mask */
#define SUPC_VREFCTRL_LPHIB(value)            (SUPC_VREFCTRL_LPHIB_Msk & (_UINT32_(value) << SUPC_VREFCTRL_LPHIB_Pos)) /* Assigment of value for LPHIB in the SUPC_VREFCTRL register */
#define   SUPC_VREFCTRL_LPHIB_FullPower_Val   _UINT32_(0x0)                                        /* (SUPC_VREFCTRL) In hibernate mode, bandgap is set to nominal power mode. As a consequence, enabled regulator(s) are set to nominal power mode.  */
#define   SUPC_VREFCTRL_LPHIB_LowPower_Val    _UINT32_(0x1)                                        /* (SUPC_VREFCTRL) In hibernate mode, bandgap is set to low power mode. As a consequence, enabled regulator(s) are set to low power mode.  */
#define SUPC_VREFCTRL_LPHIB_FullPower         (SUPC_VREFCTRL_LPHIB_FullPower_Val << SUPC_VREFCTRL_LPHIB_Pos) /* (SUPC_VREFCTRL) In hibernate mode, bandgap is set to nominal power mode. As a consequence, enabled regulator(s) are set to nominal power mode. Position  */
#define SUPC_VREFCTRL_LPHIB_LowPower          (SUPC_VREFCTRL_LPHIB_LowPower_Val << SUPC_VREFCTRL_LPHIB_Pos) /* (SUPC_VREFCTRL) In hibernate mode, bandgap is set to low power mode. As a consequence, enabled regulator(s) are set to low power mode. Position  */
#define SUPC_VREFCTRL_TSEN_Pos                _UINT32_(4)                                          /* (SUPC_VREFCTRL) Temperature Sensor Output Enable Position */
#define SUPC_VREFCTRL_TSEN_Msk                (_UINT32_(0x1) << SUPC_VREFCTRL_TSEN_Pos)            /* (SUPC_VREFCTRL) Temperature Sensor Output Enable Mask */
#define SUPC_VREFCTRL_TSEN(value)             (SUPC_VREFCTRL_TSEN_Msk & (_UINT32_(value) << SUPC_VREFCTRL_TSEN_Pos)) /* Assigment of value for TSEN in the SUPC_VREFCTRL register */
#define SUPC_VREFCTRL_Msk                     _UINT32_(0x00000013)                                 /* (SUPC_VREFCTRL) Register Mask  */


/* -------- SUPC_BKOUT : (SUPC Offset: 0x28) (R/W 32) Backup Output Control -------- */
#define SUPC_BKOUT_RESETVALUE                 _UINT32_(0x00)                                       /*  (SUPC_BKOUT) Backup Output Control  Reset Value */

#define SUPC_BKOUT_EN0_Pos                    _UINT32_(0)                                          /* (SUPC_BKOUT) Enable Output Position */
#define SUPC_BKOUT_EN0_Msk                    (_UINT32_(0x1) << SUPC_BKOUT_EN0_Pos)                /* (SUPC_BKOUT) Enable Output Mask */
#define SUPC_BKOUT_EN0(value)                 (SUPC_BKOUT_EN0_Msk & (_UINT32_(value) << SUPC_BKOUT_EN0_Pos)) /* Assigment of value for EN0 in the SUPC_BKOUT register */
#define SUPC_BKOUT_EN1_Pos                    _UINT32_(2)                                          /* (SUPC_BKOUT) Enable Output Position */
#define SUPC_BKOUT_EN1_Msk                    (_UINT32_(0x1) << SUPC_BKOUT_EN1_Pos)                /* (SUPC_BKOUT) Enable Output Mask */
#define SUPC_BKOUT_EN1(value)                 (SUPC_BKOUT_EN1_Msk & (_UINT32_(value) << SUPC_BKOUT_EN1_Pos)) /* Assigment of value for EN1 in the SUPC_BKOUT register */
#define SUPC_BKOUT_CLR0_Pos                   _UINT32_(8)                                          /* (SUPC_BKOUT) Clear Output Position */
#define SUPC_BKOUT_CLR0_Msk                   (_UINT32_(0x1) << SUPC_BKOUT_CLR0_Pos)               /* (SUPC_BKOUT) Clear Output Mask */
#define SUPC_BKOUT_CLR0(value)                (SUPC_BKOUT_CLR0_Msk & (_UINT32_(value) << SUPC_BKOUT_CLR0_Pos)) /* Assigment of value for CLR0 in the SUPC_BKOUT register */
#define SUPC_BKOUT_CLR1_Pos                   _UINT32_(10)                                         /* (SUPC_BKOUT) Clear Output Position */
#define SUPC_BKOUT_CLR1_Msk                   (_UINT32_(0x1) << SUPC_BKOUT_CLR1_Pos)               /* (SUPC_BKOUT) Clear Output Mask */
#define SUPC_BKOUT_CLR1(value)                (SUPC_BKOUT_CLR1_Msk & (_UINT32_(value) << SUPC_BKOUT_CLR1_Pos)) /* Assigment of value for CLR1 in the SUPC_BKOUT register */
#define SUPC_BKOUT_SET0_Pos                   _UINT32_(16)                                         /* (SUPC_BKOUT) Set Output Position */
#define SUPC_BKOUT_SET0_Msk                   (_UINT32_(0x1) << SUPC_BKOUT_SET0_Pos)               /* (SUPC_BKOUT) Set Output Mask */
#define SUPC_BKOUT_SET0(value)                (SUPC_BKOUT_SET0_Msk & (_UINT32_(value) << SUPC_BKOUT_SET0_Pos)) /* Assigment of value for SET0 in the SUPC_BKOUT register */
#define SUPC_BKOUT_SET1_Pos                   _UINT32_(18)                                         /* (SUPC_BKOUT) Set Output Position */
#define SUPC_BKOUT_SET1_Msk                   (_UINT32_(0x1) << SUPC_BKOUT_SET1_Pos)               /* (SUPC_BKOUT) Set Output Mask */
#define SUPC_BKOUT_SET1(value)                (SUPC_BKOUT_SET1_Msk & (_UINT32_(value) << SUPC_BKOUT_SET1_Pos)) /* Assigment of value for SET1 in the SUPC_BKOUT register */
#define SUPC_BKOUT_TGLOM0_Pos                 _UINT32_(24)                                         /* (SUPC_BKOUT) Toggle Output Mode Position */
#define SUPC_BKOUT_TGLOM0_Msk                 (_UINT32_(0x3) << SUPC_BKOUT_TGLOM0_Pos)             /* (SUPC_BKOUT) Toggle Output Mode Mask */
#define SUPC_BKOUT_TGLOM0(value)              (SUPC_BKOUT_TGLOM0_Msk & (_UINT32_(value) << SUPC_BKOUT_TGLOM0_Pos)) /* Assigment of value for TGLOM0 in the SUPC_BKOUT register */
#define   SUPC_BKOUT_TGLOM0_DISABLE_Val       _UINT32_(0x0)                                        /* (SUPC_BKOUT) The output does not toggle.  */
#define   SUPC_BKOUT_TGLOM0_RTCTGL_Val        _UINT32_(0x1)                                        /* (SUPC_BKOUT) The output toggles on RTC event.  */
#define   SUPC_BKOUT_TGLOM0_BKUPTGL_Val       _UINT32_(0x2)                                        /* (SUPC_BKOUT) The output is set when the device enters backup mode or battery backup mode. The output should then be cleared by software.  */
#define SUPC_BKOUT_TGLOM0_DISABLE             (SUPC_BKOUT_TGLOM0_DISABLE_Val << SUPC_BKOUT_TGLOM0_Pos) /* (SUPC_BKOUT) The output does not toggle. Position  */
#define SUPC_BKOUT_TGLOM0_RTCTGL              (SUPC_BKOUT_TGLOM0_RTCTGL_Val << SUPC_BKOUT_TGLOM0_Pos) /* (SUPC_BKOUT) The output toggles on RTC event. Position  */
#define SUPC_BKOUT_TGLOM0_BKUPTGL             (SUPC_BKOUT_TGLOM0_BKUPTGL_Val << SUPC_BKOUT_TGLOM0_Pos) /* (SUPC_BKOUT) The output is set when the device enters backup mode or battery backup mode. The output should then be cleared by software. Position  */
#define SUPC_BKOUT_TGLOM1_Pos                 _UINT32_(26)                                         /* (SUPC_BKOUT) Toggle Output Mode Position */
#define SUPC_BKOUT_TGLOM1_Msk                 (_UINT32_(0x3) << SUPC_BKOUT_TGLOM1_Pos)             /* (SUPC_BKOUT) Toggle Output Mode Mask */
#define SUPC_BKOUT_TGLOM1(value)              (SUPC_BKOUT_TGLOM1_Msk & (_UINT32_(value) << SUPC_BKOUT_TGLOM1_Pos)) /* Assigment of value for TGLOM1 in the SUPC_BKOUT register */
#define   SUPC_BKOUT_TGLOM1_DISABLE_Val       _UINT32_(0x0)                                        /* (SUPC_BKOUT) The output does not toggle.  */
#define   SUPC_BKOUT_TGLOM1_RTCTGL_Val        _UINT32_(0x1)                                        /* (SUPC_BKOUT) The output toggles on RTC event.  */
#define   SUPC_BKOUT_TGLOM1_BKUPTGL_Val       _UINT32_(0x2)                                        /* (SUPC_BKOUT) The output is set when the device enters backup mode or battery backup mode. The output should then be cleared by software.  */
#define SUPC_BKOUT_TGLOM1_DISABLE             (SUPC_BKOUT_TGLOM1_DISABLE_Val << SUPC_BKOUT_TGLOM1_Pos) /* (SUPC_BKOUT) The output does not toggle. Position  */
#define SUPC_BKOUT_TGLOM1_RTCTGL              (SUPC_BKOUT_TGLOM1_RTCTGL_Val << SUPC_BKOUT_TGLOM1_Pos) /* (SUPC_BKOUT) The output toggles on RTC event. Position  */
#define SUPC_BKOUT_TGLOM1_BKUPTGL             (SUPC_BKOUT_TGLOM1_BKUPTGL_Val << SUPC_BKOUT_TGLOM1_Pos) /* (SUPC_BKOUT) The output is set when the device enters backup mode or battery backup mode. The output should then be cleared by software. Position  */
#define SUPC_BKOUT_Msk                        _UINT32_(0x0F050505)                                 /* (SUPC_BKOUT) Register Mask  */

#define SUPC_BKOUT_EN_Pos                     _UINT32_(0)                                          /* (SUPC_BKOUT Position) Enable Output */
#define SUPC_BKOUT_EN_Msk                     (_UINT32_(0x3) << SUPC_BKOUT_EN_Pos)                 /* (SUPC_BKOUT Mask) EN */
#define SUPC_BKOUT_EN(value)                  (SUPC_BKOUT_EN_Msk & (_UINT32_(value) << SUPC_BKOUT_EN_Pos)) 
#define SUPC_BKOUT_CLR_Pos                    _UINT32_(8)                                          /* (SUPC_BKOUT Position) Clear Output */
#define SUPC_BKOUT_CLR_Msk                    (_UINT32_(0x3) << SUPC_BKOUT_CLR_Pos)                /* (SUPC_BKOUT Mask) CLR */
#define SUPC_BKOUT_CLR(value)                 (SUPC_BKOUT_CLR_Msk & (_UINT32_(value) << SUPC_BKOUT_CLR_Pos)) 
#define SUPC_BKOUT_SET_Pos                    _UINT32_(16)                                         /* (SUPC_BKOUT Position) Set Output */
#define SUPC_BKOUT_SET_Msk                    (_UINT32_(0x3) << SUPC_BKOUT_SET_Pos)                /* (SUPC_BKOUT Mask) SET */
#define SUPC_BKOUT_SET(value)                 (SUPC_BKOUT_SET_Msk & (_UINT32_(value) << SUPC_BKOUT_SET_Pos)) 

/* -------- SUPC_BKIN : (SUPC Offset: 0x2C) ( R/ 32) Backup Input Control -------- */
#define SUPC_BKIN_RESETVALUE                  _UINT32_(0x00)                                       /*  (SUPC_BKIN) Backup Input Control  Reset Value */

#define SUPC_BKIN_BKIN_Pos                    _UINT32_(0)                                          /* (SUPC_BKIN) Backup Input Value Position */
#define SUPC_BKIN_BKIN_Msk                    (_UINT32_(0x3) << SUPC_BKIN_BKIN_Pos)                /* (SUPC_BKIN) Backup Input Value Mask */
#define SUPC_BKIN_BKIN(value)                 (SUPC_BKIN_BKIN_Msk & (_UINT32_(value) << SUPC_BKIN_BKIN_Pos)) /* Assigment of value for BKIN in the SUPC_BKIN register */
#define SUPC_BKIN_Msk                         _UINT32_(0x00000003)                                 /* (SUPC_BKIN) Register Mask  */


/** \brief SUPC register offsets definitions */
#define SUPC_INTENCLR_REG_OFST         _UINT32_(0x00)      /* (SUPC_INTENCLR) Interrupt Enable Clear Offset */
#define SUPC_INTENSET_REG_OFST         _UINT32_(0x04)      /* (SUPC_INTENSET) Interrupt Enable Set Offset */
#define SUPC_INTFLAG_REG_OFST          _UINT32_(0x08)      /* (SUPC_INTFLAG) Interrupt Flag Status and Clear Offset */
#define SUPC_STATUS_REG_OFST           _UINT32_(0x0C)      /* (SUPC_STATUS) Flag status Offset */
#define SUPC_SYNCBUSY_REG_OFST         _UINT32_(0x10)      /* (SUPC_SYNCBUSY) Synchronisation Busy Offset */
#define SUPC_BOR_REG_OFST              _UINT32_(0x14)      /* (SUPC_BOR) BOR Control Offset */
#define SUPC_LVD_REG_OFST              _UINT32_(0x18)      /* (SUPC_LVD) LVD Control Offset */
#define SUPC_VREGCTRL_REG_OFST         _UINT32_(0x1C)      /* (SUPC_VREGCTRL) VREG Control Offset */
#define SUPC_VREFCTRL_REG_OFST         _UINT32_(0x20)      /* (SUPC_VREFCTRL) VREF Control Offset */
#define SUPC_BKOUT_REG_OFST            _UINT32_(0x28)      /* (SUPC_BKOUT) Backup Output Control Offset */
#define SUPC_BKIN_REG_OFST             _UINT32_(0x2C)      /* (SUPC_BKIN) Backup Input Control Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief SUPC register API structure */
typedef struct
{  /* Supply Controller */
  __IO  uint32_t                       SUPC_INTENCLR;      /**< Offset: 0x00 (R/W  32) Interrupt Enable Clear */
  __IO  uint32_t                       SUPC_INTENSET;      /**< Offset: 0x04 (R/W  32) Interrupt Enable Set */
  __IO  uint32_t                       SUPC_INTFLAG;       /**< Offset: 0x08 (R/W  32) Interrupt Flag Status and Clear */
  __I   uint32_t                       SUPC_STATUS;        /**< Offset: 0x0C (R/   32) Flag status */
  __I   uint32_t                       SUPC_SYNCBUSY;      /**< Offset: 0x10 (R/   32) Synchronisation Busy */
  __IO  uint32_t                       SUPC_BOR;           /**< Offset: 0x14 (R/W  32) BOR Control */
  __IO  uint32_t                       SUPC_LVD;           /**< Offset: 0x18 (R/W  32) LVD Control */
  __IO  uint32_t                       SUPC_VREGCTRL;      /**< Offset: 0x1C (R/W  32) VREG Control */
  __IO  uint32_t                       SUPC_VREFCTRL;      /**< Offset: 0x20 (R/W  32) VREF Control */
  __I   uint8_t                        Reserved1[0x04];
  __IO  uint32_t                       SUPC_BKOUT;         /**< Offset: 0x28 (R/W  32) Backup Output Control */
  __I   uint32_t                       SUPC_BKIN;          /**< Offset: 0x2C (R/   32) Backup Input Control */
} supc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA90_SUPC_COMPONENT_H_ */
