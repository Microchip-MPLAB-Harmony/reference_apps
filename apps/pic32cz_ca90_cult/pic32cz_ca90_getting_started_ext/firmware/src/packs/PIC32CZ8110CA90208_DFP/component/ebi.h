/*
 * Component description for EBI
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
#ifndef _PIC32CZCA90_EBI_COMPONENT_H_
#define _PIC32CZCA90_EBI_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR EBI                                          */
/* ************************************************************************** */

/* -------- EBI_SMC_SETUP : (EBI Offset: 0x00) (R/W 32) SMC Setup Register -------- */
#define EBI_SMC_SETUP_RESETVALUE              _UINT32_(0x1010101)                                  /*  (EBI_SMC_SETUP) SMC Setup Register  Reset Value */

#define EBI_SMC_SETUP_NWE_SETUP_Pos           _UINT32_(0)                                          /* (EBI_SMC_SETUP) NWE Setup Length Position */
#define EBI_SMC_SETUP_NWE_SETUP_Msk           (_UINT32_(0x3F) << EBI_SMC_SETUP_NWE_SETUP_Pos)      /* (EBI_SMC_SETUP) NWE Setup Length Mask */
#define EBI_SMC_SETUP_NWE_SETUP(value)        (EBI_SMC_SETUP_NWE_SETUP_Msk & (_UINT32_(value) << EBI_SMC_SETUP_NWE_SETUP_Pos)) /* Assigment of value for NWE_SETUP in the EBI_SMC_SETUP register */
#define EBI_SMC_SETUP_NCS_WR_SETUP_Pos        _UINT32_(8)                                          /* (EBI_SMC_SETUP) NCS Setup Length in WRITE Access Position */
#define EBI_SMC_SETUP_NCS_WR_SETUP_Msk        (_UINT32_(0x3F) << EBI_SMC_SETUP_NCS_WR_SETUP_Pos)   /* (EBI_SMC_SETUP) NCS Setup Length in WRITE Access Mask */
#define EBI_SMC_SETUP_NCS_WR_SETUP(value)     (EBI_SMC_SETUP_NCS_WR_SETUP_Msk & (_UINT32_(value) << EBI_SMC_SETUP_NCS_WR_SETUP_Pos)) /* Assigment of value for NCS_WR_SETUP in the EBI_SMC_SETUP register */
#define EBI_SMC_SETUP_NRD_SETUP_Pos           _UINT32_(16)                                         /* (EBI_SMC_SETUP) NRD Setup Length Position */
#define EBI_SMC_SETUP_NRD_SETUP_Msk           (_UINT32_(0x3F) << EBI_SMC_SETUP_NRD_SETUP_Pos)      /* (EBI_SMC_SETUP) NRD Setup Length Mask */
#define EBI_SMC_SETUP_NRD_SETUP(value)        (EBI_SMC_SETUP_NRD_SETUP_Msk & (_UINT32_(value) << EBI_SMC_SETUP_NRD_SETUP_Pos)) /* Assigment of value for NRD_SETUP in the EBI_SMC_SETUP register */
#define EBI_SMC_SETUP_NCS_RD_SETUP_Pos        _UINT32_(24)                                         /* (EBI_SMC_SETUP) NCS Setup Length in READ Access Position */
#define EBI_SMC_SETUP_NCS_RD_SETUP_Msk        (_UINT32_(0x3F) << EBI_SMC_SETUP_NCS_RD_SETUP_Pos)   /* (EBI_SMC_SETUP) NCS Setup Length in READ Access Mask */
#define EBI_SMC_SETUP_NCS_RD_SETUP(value)     (EBI_SMC_SETUP_NCS_RD_SETUP_Msk & (_UINT32_(value) << EBI_SMC_SETUP_NCS_RD_SETUP_Pos)) /* Assigment of value for NCS_RD_SETUP in the EBI_SMC_SETUP register */
#define EBI_SMC_SETUP_Msk                     _UINT32_(0x3F3F3F3F)                                 /* (EBI_SMC_SETUP) Register Mask  */


/* -------- EBI_SMC_PULSE : (EBI Offset: 0x04) (R/W 32) SMC Pulse Register -------- */
#define EBI_SMC_PULSE_RESETVALUE              _UINT32_(0x1010101)                                  /*  (EBI_SMC_PULSE) SMC Pulse Register  Reset Value */

#define EBI_SMC_PULSE_NWE_PULSE_Pos           _UINT32_(0)                                          /* (EBI_SMC_PULSE) NWE Pulse Length Position */
#define EBI_SMC_PULSE_NWE_PULSE_Msk           (_UINT32_(0x7F) << EBI_SMC_PULSE_NWE_PULSE_Pos)      /* (EBI_SMC_PULSE) NWE Pulse Length Mask */
#define EBI_SMC_PULSE_NWE_PULSE(value)        (EBI_SMC_PULSE_NWE_PULSE_Msk & (_UINT32_(value) << EBI_SMC_PULSE_NWE_PULSE_Pos)) /* Assigment of value for NWE_PULSE in the EBI_SMC_PULSE register */
#define EBI_SMC_PULSE_NCS_WR_PULSE_Pos        _UINT32_(8)                                          /* (EBI_SMC_PULSE) NCS Pulse Length in WRITE Access Position */
#define EBI_SMC_PULSE_NCS_WR_PULSE_Msk        (_UINT32_(0x7F) << EBI_SMC_PULSE_NCS_WR_PULSE_Pos)   /* (EBI_SMC_PULSE) NCS Pulse Length in WRITE Access Mask */
#define EBI_SMC_PULSE_NCS_WR_PULSE(value)     (EBI_SMC_PULSE_NCS_WR_PULSE_Msk & (_UINT32_(value) << EBI_SMC_PULSE_NCS_WR_PULSE_Pos)) /* Assigment of value for NCS_WR_PULSE in the EBI_SMC_PULSE register */
#define EBI_SMC_PULSE_NRD_PULSE_Pos           _UINT32_(16)                                         /* (EBI_SMC_PULSE) NRD Pulse Length Position */
#define EBI_SMC_PULSE_NRD_PULSE_Msk           (_UINT32_(0x7F) << EBI_SMC_PULSE_NRD_PULSE_Pos)      /* (EBI_SMC_PULSE) NRD Pulse Length Mask */
#define EBI_SMC_PULSE_NRD_PULSE(value)        (EBI_SMC_PULSE_NRD_PULSE_Msk & (_UINT32_(value) << EBI_SMC_PULSE_NRD_PULSE_Pos)) /* Assigment of value for NRD_PULSE in the EBI_SMC_PULSE register */
#define EBI_SMC_PULSE_NCS_RD_PULSE_Pos        _UINT32_(24)                                         /* (EBI_SMC_PULSE) NCS Pulse Length in READ Access Position */
#define EBI_SMC_PULSE_NCS_RD_PULSE_Msk        (_UINT32_(0x7F) << EBI_SMC_PULSE_NCS_RD_PULSE_Pos)   /* (EBI_SMC_PULSE) NCS Pulse Length in READ Access Mask */
#define EBI_SMC_PULSE_NCS_RD_PULSE(value)     (EBI_SMC_PULSE_NCS_RD_PULSE_Msk & (_UINT32_(value) << EBI_SMC_PULSE_NCS_RD_PULSE_Pos)) /* Assigment of value for NCS_RD_PULSE in the EBI_SMC_PULSE register */
#define EBI_SMC_PULSE_Msk                     _UINT32_(0x7F7F7F7F)                                 /* (EBI_SMC_PULSE) Register Mask  */


/* -------- EBI_SMC_CYCLE : (EBI Offset: 0x08) (R/W 32) SMC Cycle Register -------- */
#define EBI_SMC_CYCLE_RESETVALUE              _UINT32_(0x30003)                                    /*  (EBI_SMC_CYCLE) SMC Cycle Register  Reset Value */

#define EBI_SMC_CYCLE_NWE_CYCLE_Pos           _UINT32_(0)                                          /* (EBI_SMC_CYCLE) Total Write Cycle Length Position */
#define EBI_SMC_CYCLE_NWE_CYCLE_Msk           (_UINT32_(0x1FF) << EBI_SMC_CYCLE_NWE_CYCLE_Pos)     /* (EBI_SMC_CYCLE) Total Write Cycle Length Mask */
#define EBI_SMC_CYCLE_NWE_CYCLE(value)        (EBI_SMC_CYCLE_NWE_CYCLE_Msk & (_UINT32_(value) << EBI_SMC_CYCLE_NWE_CYCLE_Pos)) /* Assigment of value for NWE_CYCLE in the EBI_SMC_CYCLE register */
#define EBI_SMC_CYCLE_NRD_CYCLE_Pos           _UINT32_(16)                                         /* (EBI_SMC_CYCLE) Total Read Cycle Length Position */
#define EBI_SMC_CYCLE_NRD_CYCLE_Msk           (_UINT32_(0x1FF) << EBI_SMC_CYCLE_NRD_CYCLE_Pos)     /* (EBI_SMC_CYCLE) Total Read Cycle Length Mask */
#define EBI_SMC_CYCLE_NRD_CYCLE(value)        (EBI_SMC_CYCLE_NRD_CYCLE_Msk & (_UINT32_(value) << EBI_SMC_CYCLE_NRD_CYCLE_Pos)) /* Assigment of value for NRD_CYCLE in the EBI_SMC_CYCLE register */
#define EBI_SMC_CYCLE_Msk                     _UINT32_(0x01FF01FF)                                 /* (EBI_SMC_CYCLE) Register Mask  */


/* -------- EBI_SMC_MODE : (EBI Offset: 0x0C) (R/W 32) SMC Mode Register -------- */
#define EBI_SMC_MODE_RESETVALUE               _UINT32_(0x10001003)                                 /*  (EBI_SMC_MODE) SMC Mode Register  Reset Value */

#define EBI_SMC_MODE_READ_MODE_Pos            _UINT32_(0)                                          /* (EBI_SMC_MODE) Read Mode Position */
#define EBI_SMC_MODE_READ_MODE_Msk            (_UINT32_(0x1) << EBI_SMC_MODE_READ_MODE_Pos)        /* (EBI_SMC_MODE) Read Mode Mask */
#define EBI_SMC_MODE_READ_MODE(value)         (EBI_SMC_MODE_READ_MODE_Msk & (_UINT32_(value) << EBI_SMC_MODE_READ_MODE_Pos)) /* Assigment of value for READ_MODE in the EBI_SMC_MODE register */
#define EBI_SMC_MODE_WRITE_MODE_Pos           _UINT32_(1)                                          /* (EBI_SMC_MODE) Write Mode Position */
#define EBI_SMC_MODE_WRITE_MODE_Msk           (_UINT32_(0x1) << EBI_SMC_MODE_WRITE_MODE_Pos)       /* (EBI_SMC_MODE) Write Mode Mask */
#define EBI_SMC_MODE_WRITE_MODE(value)        (EBI_SMC_MODE_WRITE_MODE_Msk & (_UINT32_(value) << EBI_SMC_MODE_WRITE_MODE_Pos)) /* Assigment of value for WRITE_MODE in the EBI_SMC_MODE register */
#define EBI_SMC_MODE_EXNW_MODE_Pos            _UINT32_(4)                                          /* (EBI_SMC_MODE) NWAIT Mode Position */
#define EBI_SMC_MODE_EXNW_MODE_Msk            (_UINT32_(0x3) << EBI_SMC_MODE_EXNW_MODE_Pos)        /* (EBI_SMC_MODE) NWAIT Mode Mask */
#define EBI_SMC_MODE_EXNW_MODE(value)         (EBI_SMC_MODE_EXNW_MODE_Msk & (_UINT32_(value) << EBI_SMC_MODE_EXNW_MODE_Pos)) /* Assigment of value for EXNW_MODE in the EBI_SMC_MODE register */
#define   EBI_SMC_MODE_EXNW_MODE_DISABLED_Val _UINT32_(0x0)                                        /* (EBI_SMC_MODE) Disabled-The NWAIT input signal is ignored on the corresponding chip select.  */
#define   EBI_SMC_MODE_EXNW_MODE_FROZEN_Val   _UINT32_(0x2)                                        /* (EBI_SMC_MODE) Frozen Mode-If asserted, the NWAIT signal freezes the current read or write cycle. After deassertion, the read/write cycle is resumed from the point where it was stopped.  */
#define   EBI_SMC_MODE_EXNW_MODE_READY_Val    _UINT32_(0x3)                                        /* (EBI_SMC_MODE) Ready Mode-The NWAIT signal indicates the availability of the external device at the end of the pulse of the controlling read or write signal, to complete the access. If high, the access normally completes. If low, the access is extended until NWAIT returns high.  */
#define EBI_SMC_MODE_EXNW_MODE_DISABLED       (EBI_SMC_MODE_EXNW_MODE_DISABLED_Val << EBI_SMC_MODE_EXNW_MODE_Pos) /* (EBI_SMC_MODE) Disabled-The NWAIT input signal is ignored on the corresponding chip select. Position  */
#define EBI_SMC_MODE_EXNW_MODE_FROZEN         (EBI_SMC_MODE_EXNW_MODE_FROZEN_Val << EBI_SMC_MODE_EXNW_MODE_Pos) /* (EBI_SMC_MODE) Frozen Mode-If asserted, the NWAIT signal freezes the current read or write cycle. After deassertion, the read/write cycle is resumed from the point where it was stopped. Position  */
#define EBI_SMC_MODE_EXNW_MODE_READY          (EBI_SMC_MODE_EXNW_MODE_READY_Val << EBI_SMC_MODE_EXNW_MODE_Pos) /* (EBI_SMC_MODE) Ready Mode-The NWAIT signal indicates the availability of the external device at the end of the pulse of the controlling read or write signal, to complete the access. If high, the access normally completes. If low, the access is extended until NWAIT returns high. Position  */
#define EBI_SMC_MODE_BAT_Pos                  _UINT32_(8)                                          /* (EBI_SMC_MODE) Byte Access Type Position */
#define EBI_SMC_MODE_BAT_Msk                  (_UINT32_(0x1) << EBI_SMC_MODE_BAT_Pos)              /* (EBI_SMC_MODE) Byte Access Type Mask */
#define EBI_SMC_MODE_BAT(value)               (EBI_SMC_MODE_BAT_Msk & (_UINT32_(value) << EBI_SMC_MODE_BAT_Pos)) /* Assigment of value for BAT in the EBI_SMC_MODE register */
#define   EBI_SMC_MODE_BAT_BYTE_SELECT_Val    _UINT32_(0x0)                                        /* (EBI_SMC_MODE) Byte select access type:- Write operation is controlled using NCS, NWE, NBS0, NBS1.- Read operation is controlled using NCS, NRD, NBS0, NBS1.  */
#define   EBI_SMC_MODE_BAT_BYTE_WRITE_Val     _UINT32_(0x1)                                        /* (EBI_SMC_MODE) Byte write access type:- Write operation is controlled using NCS, NWR0, NWR1.- Read operation is controlled using NCS and NRD.  */
#define EBI_SMC_MODE_BAT_BYTE_SELECT          (EBI_SMC_MODE_BAT_BYTE_SELECT_Val << EBI_SMC_MODE_BAT_Pos) /* (EBI_SMC_MODE) Byte select access type:- Write operation is controlled using NCS, NWE, NBS0, NBS1.- Read operation is controlled using NCS, NRD, NBS0, NBS1. Position  */
#define EBI_SMC_MODE_BAT_BYTE_WRITE           (EBI_SMC_MODE_BAT_BYTE_WRITE_Val << EBI_SMC_MODE_BAT_Pos) /* (EBI_SMC_MODE) Byte write access type:- Write operation is controlled using NCS, NWR0, NWR1.- Read operation is controlled using NCS and NRD. Position  */
#define EBI_SMC_MODE_DBW_Pos                  _UINT32_(12)                                         /* (EBI_SMC_MODE) Data Bus Width Position */
#define EBI_SMC_MODE_DBW_Msk                  (_UINT32_(0x1) << EBI_SMC_MODE_DBW_Pos)              /* (EBI_SMC_MODE) Data Bus Width Mask */
#define EBI_SMC_MODE_DBW(value)               (EBI_SMC_MODE_DBW_Msk & (_UINT32_(value) << EBI_SMC_MODE_DBW_Pos)) /* Assigment of value for DBW in the EBI_SMC_MODE register */
#define   EBI_SMC_MODE_DBW_8_BIT_Val          _UINT32_(0x0)                                        /* (EBI_SMC_MODE) 8-bit Data Bus  */
#define   EBI_SMC_MODE_DBW_16_BIT_Val         _UINT32_(0x1)                                        /* (EBI_SMC_MODE) 16-bit Data Bus  */
#define EBI_SMC_MODE_DBW_8_BIT                (EBI_SMC_MODE_DBW_8_BIT_Val << EBI_SMC_MODE_DBW_Pos) /* (EBI_SMC_MODE) 8-bit Data Bus Position  */
#define EBI_SMC_MODE_DBW_16_BIT               (EBI_SMC_MODE_DBW_16_BIT_Val << EBI_SMC_MODE_DBW_Pos) /* (EBI_SMC_MODE) 16-bit Data Bus Position  */
#define EBI_SMC_MODE_TDF_CYCLES_Pos           _UINT32_(16)                                         /* (EBI_SMC_MODE) Data Float Time Position */
#define EBI_SMC_MODE_TDF_CYCLES_Msk           (_UINT32_(0xF) << EBI_SMC_MODE_TDF_CYCLES_Pos)       /* (EBI_SMC_MODE) Data Float Time Mask */
#define EBI_SMC_MODE_TDF_CYCLES(value)        (EBI_SMC_MODE_TDF_CYCLES_Msk & (_UINT32_(value) << EBI_SMC_MODE_TDF_CYCLES_Pos)) /* Assigment of value for TDF_CYCLES in the EBI_SMC_MODE register */
#define EBI_SMC_MODE_TDF_MODE_Pos             _UINT32_(20)                                         /* (EBI_SMC_MODE) TDF Optimization Position */
#define EBI_SMC_MODE_TDF_MODE_Msk             (_UINT32_(0x1) << EBI_SMC_MODE_TDF_MODE_Pos)         /* (EBI_SMC_MODE) TDF Optimization Mask */
#define EBI_SMC_MODE_TDF_MODE(value)          (EBI_SMC_MODE_TDF_MODE_Msk & (_UINT32_(value) << EBI_SMC_MODE_TDF_MODE_Pos)) /* Assigment of value for TDF_MODE in the EBI_SMC_MODE register */
#define EBI_SMC_MODE_PMEN_Pos                 _UINT32_(24)                                         /* (EBI_SMC_MODE) Page Mode Enabled Position */
#define EBI_SMC_MODE_PMEN_Msk                 (_UINT32_(0x1) << EBI_SMC_MODE_PMEN_Pos)             /* (EBI_SMC_MODE) Page Mode Enabled Mask */
#define EBI_SMC_MODE_PMEN(value)              (EBI_SMC_MODE_PMEN_Msk & (_UINT32_(value) << EBI_SMC_MODE_PMEN_Pos)) /* Assigment of value for PMEN in the EBI_SMC_MODE register */
#define EBI_SMC_MODE_PS_Pos                   _UINT32_(28)                                         /* (EBI_SMC_MODE) Page Size Position */
#define EBI_SMC_MODE_PS_Msk                   (_UINT32_(0x3) << EBI_SMC_MODE_PS_Pos)               /* (EBI_SMC_MODE) Page Size Mask */
#define EBI_SMC_MODE_PS(value)                (EBI_SMC_MODE_PS_Msk & (_UINT32_(value) << EBI_SMC_MODE_PS_Pos)) /* Assigment of value for PS in the EBI_SMC_MODE register */
#define   EBI_SMC_MODE_PS_4_BYTE_Val          _UINT32_(0x0)                                        /* (EBI_SMC_MODE) 4-byte page  */
#define   EBI_SMC_MODE_PS_8_BYTE_Val          _UINT32_(0x1)                                        /* (EBI_SMC_MODE) 8-byte page  */
#define   EBI_SMC_MODE_PS_16_BYTE_Val         _UINT32_(0x2)                                        /* (EBI_SMC_MODE) 16-byte page  */
#define   EBI_SMC_MODE_PS_32_BYTE_Val         _UINT32_(0x3)                                        /* (EBI_SMC_MODE) 32-byte page  */
#define EBI_SMC_MODE_PS_4_BYTE                (EBI_SMC_MODE_PS_4_BYTE_Val << EBI_SMC_MODE_PS_Pos)  /* (EBI_SMC_MODE) 4-byte page Position  */
#define EBI_SMC_MODE_PS_8_BYTE                (EBI_SMC_MODE_PS_8_BYTE_Val << EBI_SMC_MODE_PS_Pos)  /* (EBI_SMC_MODE) 8-byte page Position  */
#define EBI_SMC_MODE_PS_16_BYTE               (EBI_SMC_MODE_PS_16_BYTE_Val << EBI_SMC_MODE_PS_Pos) /* (EBI_SMC_MODE) 16-byte page Position  */
#define EBI_SMC_MODE_PS_32_BYTE               (EBI_SMC_MODE_PS_32_BYTE_Val << EBI_SMC_MODE_PS_Pos) /* (EBI_SMC_MODE) 32-byte page Position  */
#define EBI_SMC_MODE_Msk                      _UINT32_(0x311F1133)                                 /* (EBI_SMC_MODE) Register Mask  */


/* -------- EBI_SMC_WPMR : (EBI Offset: 0xE4) (R/W 32) SMC Write Protection Mode Register -------- */
#define EBI_SMC_WPMR_RESETVALUE               _UINT32_(0x00)                                       /*  (EBI_SMC_WPMR) SMC Write Protection Mode Register  Reset Value */

#define EBI_SMC_WPMR_WPEN_Pos                 _UINT32_(0)                                          /* (EBI_SMC_WPMR) Write Protect Enable Position */
#define EBI_SMC_WPMR_WPEN_Msk                 (_UINT32_(0x1) << EBI_SMC_WPMR_WPEN_Pos)             /* (EBI_SMC_WPMR) Write Protect Enable Mask */
#define EBI_SMC_WPMR_WPEN(value)              (EBI_SMC_WPMR_WPEN_Msk & (_UINT32_(value) << EBI_SMC_WPMR_WPEN_Pos)) /* Assigment of value for WPEN in the EBI_SMC_WPMR register */
#define EBI_SMC_WPMR_WPKEY_Pos                _UINT32_(8)                                          /* (EBI_SMC_WPMR) Write Protection Key Position */
#define EBI_SMC_WPMR_WPKEY_Msk                (_UINT32_(0xFFFFFF) << EBI_SMC_WPMR_WPKEY_Pos)       /* (EBI_SMC_WPMR) Write Protection Key Mask */
#define EBI_SMC_WPMR_WPKEY(value)             (EBI_SMC_WPMR_WPKEY_Msk & (_UINT32_(value) << EBI_SMC_WPMR_WPKEY_Pos)) /* Assigment of value for WPKEY in the EBI_SMC_WPMR register */
#define   EBI_SMC_WPMR_WPKEY_PASSWD_Val       _UINT32_(0x534D43)                                   /* (EBI_SMC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0.  */
#define EBI_SMC_WPMR_WPKEY_PASSWD             (EBI_SMC_WPMR_WPKEY_PASSWD_Val << EBI_SMC_WPMR_WPKEY_Pos) /* (EBI_SMC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0. Position  */
#define EBI_SMC_WPMR_Msk                      _UINT32_(0xFFFFFF01)                                 /* (EBI_SMC_WPMR) Register Mask  */


/* -------- EBI_SMC_WPSR : (EBI Offset: 0xE8) ( R/ 32) SMC Write Protection Status Register -------- */
#define EBI_SMC_WPSR_RESETVALUE               _UINT32_(0x00)                                       /*  (EBI_SMC_WPSR) SMC Write Protection Status Register  Reset Value */

#define EBI_SMC_WPSR_WPVS_Pos                 _UINT32_(0)                                          /* (EBI_SMC_WPSR) Write Protection Violation Status Position */
#define EBI_SMC_WPSR_WPVS_Msk                 (_UINT32_(0x1) << EBI_SMC_WPSR_WPVS_Pos)             /* (EBI_SMC_WPSR) Write Protection Violation Status Mask */
#define EBI_SMC_WPSR_WPVS(value)              (EBI_SMC_WPSR_WPVS_Msk & (_UINT32_(value) << EBI_SMC_WPSR_WPVS_Pos)) /* Assigment of value for WPVS in the EBI_SMC_WPSR register */
#define EBI_SMC_WPSR_WPVSRC_Pos               _UINT32_(8)                                          /* (EBI_SMC_WPSR) Write Protection Violation Source Position */
#define EBI_SMC_WPSR_WPVSRC_Msk               (_UINT32_(0xFFFF) << EBI_SMC_WPSR_WPVSRC_Pos)        /* (EBI_SMC_WPSR) Write Protection Violation Source Mask */
#define EBI_SMC_WPSR_WPVSRC(value)            (EBI_SMC_WPSR_WPVSRC_Msk & (_UINT32_(value) << EBI_SMC_WPSR_WPVSRC_Pos)) /* Assigment of value for WPVSRC in the EBI_SMC_WPSR register */
#define EBI_SMC_WPSR_Msk                      _UINT32_(0x00FFFF01)                                 /* (EBI_SMC_WPSR) Register Mask  */


/** \brief EBI register offsets definitions */
#define EBI_SMC_SETUP_REG_OFST         _UINT32_(0x00)      /* (EBI_SMC_SETUP) SMC Setup Register Offset */
#define EBI_SMC_PULSE_REG_OFST         _UINT32_(0x04)      /* (EBI_SMC_PULSE) SMC Pulse Register Offset */
#define EBI_SMC_CYCLE_REG_OFST         _UINT32_(0x08)      /* (EBI_SMC_CYCLE) SMC Cycle Register Offset */
#define EBI_SMC_MODE_REG_OFST          _UINT32_(0x0C)      /* (EBI_SMC_MODE) SMC Mode Register Offset */
#define EBI_SMC_WPMR_REG_OFST          _UINT32_(0xE4)      /* (EBI_SMC_WPMR) SMC Write Protection Mode Register Offset */
#define EBI_SMC_WPSR_REG_OFST          _UINT32_(0xE8)      /* (EBI_SMC_WPSR) SMC Write Protection Status Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief CS_X register API structure */
typedef struct
{
  __IO  uint32_t                       EBI_SMC_SETUP;      /**< Offset: 0x00 (R/W  32) SMC Setup Register */
  __IO  uint32_t                       EBI_SMC_PULSE;      /**< Offset: 0x04 (R/W  32) SMC Pulse Register */
  __IO  uint32_t                       EBI_SMC_CYCLE;      /**< Offset: 0x08 (R/W  32) SMC Cycle Register */
  __IO  uint32_t                       EBI_SMC_MODE;       /**< Offset: 0x0C (R/W  32) SMC Mode Register */
} ebi_cs_x_registers_t;

#define EBI_CS_X_NUMBER 4

/** \brief EBI register API structure */
typedef struct
{  /* External Bus Interface */
        ebi_cs_x_registers_t           CS_X[EBI_CS_X_NUMBER]; /**< Offset: 0x00  */
  __I   uint8_t                        Reserved1[0xA4];
  __IO  uint32_t                       EBI_SMC_WPMR;       /**< Offset: 0xE4 (R/W  32) SMC Write Protection Mode Register */
  __I   uint32_t                       EBI_SMC_WPSR;       /**< Offset: 0xE8 (R/   32) SMC Write Protection Status Register */
} ebi_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA90_EBI_COMPONENT_H_ */
