/*
 * Component description for SFR
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
#ifndef _SAM9X_SFR_COMPONENT_H_
#define _SAM9X_SFR_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR SFR                                          */
/* ************************************************************************** */

/* -------- SFR_CCFG_EBICSA : (SFR Offset: 0x04) (R/W 32) EBI Chip Select Register -------- */
#define SFR_CCFG_EBICSA_EBI_CS1A_Pos          _UINT32_(1)                                          /* (SFR_CCFG_EBICSA) EBI Chip Select 1 Assignment Position */
#define SFR_CCFG_EBICSA_EBI_CS1A_Msk          (_UINT32_(0x1) << SFR_CCFG_EBICSA_EBI_CS1A_Pos)      /* (SFR_CCFG_EBICSA) EBI Chip Select 1 Assignment Mask */
#define SFR_CCFG_EBICSA_EBI_CS1A(value)       (SFR_CCFG_EBICSA_EBI_CS1A_Msk & (_UINT32_(value) << SFR_CCFG_EBICSA_EBI_CS1A_Pos)) /* Assigment of value for EBI_CS1A in the SFR_CCFG_EBICSA register */
#define SFR_CCFG_EBICSA_EBI_CS3A_Pos          _UINT32_(3)                                          /* (SFR_CCFG_EBICSA) EBI Chip Select 3 Assignment Position */
#define SFR_CCFG_EBICSA_EBI_CS3A_Msk          (_UINT32_(0x1) << SFR_CCFG_EBICSA_EBI_CS3A_Pos)      /* (SFR_CCFG_EBICSA) EBI Chip Select 3 Assignment Mask */
#define SFR_CCFG_EBICSA_EBI_CS3A(value)       (SFR_CCFG_EBICSA_EBI_CS3A_Msk & (_UINT32_(value) << SFR_CCFG_EBICSA_EBI_CS3A_Pos)) /* Assigment of value for EBI_CS3A in the SFR_CCFG_EBICSA register */
#define SFR_CCFG_EBICSA_EBI_CS4A_Pos          _UINT32_(4)                                          /* (SFR_CCFG_EBICSA) EBI Chip Select 4 Assignment Position */
#define SFR_CCFG_EBICSA_EBI_CS4A_Msk          (_UINT32_(0x1) << SFR_CCFG_EBICSA_EBI_CS4A_Pos)      /* (SFR_CCFG_EBICSA) EBI Chip Select 4 Assignment Mask */
#define SFR_CCFG_EBICSA_EBI_CS4A(value)       (SFR_CCFG_EBICSA_EBI_CS4A_Msk & (_UINT32_(value) << SFR_CCFG_EBICSA_EBI_CS4A_Pos)) /* Assigment of value for EBI_CS4A in the SFR_CCFG_EBICSA register */
#define SFR_CCFG_EBICSA_EBI_CS5A_Pos          _UINT32_(5)                                          /* (SFR_CCFG_EBICSA) EBI Chip Select 5 Assignment Position */
#define SFR_CCFG_EBICSA_EBI_CS5A_Msk          (_UINT32_(0x1) << SFR_CCFG_EBICSA_EBI_CS5A_Pos)      /* (SFR_CCFG_EBICSA) EBI Chip Select 5 Assignment Mask */
#define SFR_CCFG_EBICSA_EBI_CS5A(value)       (SFR_CCFG_EBICSA_EBI_CS5A_Msk & (_UINT32_(value) << SFR_CCFG_EBICSA_EBI_CS5A_Pos)) /* Assigment of value for EBI_CS5A in the SFR_CCFG_EBICSA register */
#define SFR_CCFG_EBICSA_EBI_DBPUC_Pos         _UINT32_(8)                                          /* (SFR_CCFG_EBICSA) EBI Data Bus Pullup Configuration Position */
#define SFR_CCFG_EBICSA_EBI_DBPUC_Msk         (_UINT32_(0x1) << SFR_CCFG_EBICSA_EBI_DBPUC_Pos)     /* (SFR_CCFG_EBICSA) EBI Data Bus Pullup Configuration Mask */
#define SFR_CCFG_EBICSA_EBI_DBPUC(value)      (SFR_CCFG_EBICSA_EBI_DBPUC_Msk & (_UINT32_(value) << SFR_CCFG_EBICSA_EBI_DBPUC_Pos)) /* Assigment of value for EBI_DBPUC in the SFR_CCFG_EBICSA register */
#define SFR_CCFG_EBICSA_EBI_DBPDC_Pos         _UINT32_(9)                                          /* (SFR_CCFG_EBICSA) EBI Data Bus Pulldown Configuration Position */
#define SFR_CCFG_EBICSA_EBI_DBPDC_Msk         (_UINT32_(0x1) << SFR_CCFG_EBICSA_EBI_DBPDC_Pos)     /* (SFR_CCFG_EBICSA) EBI Data Bus Pulldown Configuration Mask */
#define SFR_CCFG_EBICSA_EBI_DBPDC(value)      (SFR_CCFG_EBICSA_EBI_DBPDC_Msk & (_UINT32_(value) << SFR_CCFG_EBICSA_EBI_DBPDC_Pos)) /* Assigment of value for EBI_DBPDC in the SFR_CCFG_EBICSA register */
#define SFR_CCFG_EBICSA_EBI_DRIVE_Pos         _UINT32_(16)                                         /* (SFR_CCFG_EBICSA) EBI I/O Drive Configuration Position */
#define SFR_CCFG_EBICSA_EBI_DRIVE_Msk         (_UINT32_(0x1) << SFR_CCFG_EBICSA_EBI_DRIVE_Pos)     /* (SFR_CCFG_EBICSA) EBI I/O Drive Configuration Mask */
#define SFR_CCFG_EBICSA_EBI_DRIVE(value)      (SFR_CCFG_EBICSA_EBI_DRIVE_Msk & (_UINT32_(value) << SFR_CCFG_EBICSA_EBI_DRIVE_Pos)) /* Assigment of value for EBI_DRIVE in the SFR_CCFG_EBICSA register */
#define SFR_CCFG_EBICSA_DQIEN_F_Pos           _UINT32_(20)                                         /* (SFR_CCFG_EBICSA) Force Analog Input Comparator Configuration Position */
#define SFR_CCFG_EBICSA_DQIEN_F_Msk           (_UINT32_(0x1) << SFR_CCFG_EBICSA_DQIEN_F_Pos)       /* (SFR_CCFG_EBICSA) Force Analog Input Comparator Configuration Mask */
#define SFR_CCFG_EBICSA_DQIEN_F(value)        (SFR_CCFG_EBICSA_DQIEN_F_Msk & (_UINT32_(value) << SFR_CCFG_EBICSA_DQIEN_F_Pos)) /* Assigment of value for DQIEN_F in the SFR_CCFG_EBICSA register */
#define SFR_CCFG_EBICSA_NFD0_ON_D16_Pos       _UINT32_(24)                                         /* (SFR_CCFG_EBICSA) NAND Flash Databus Selection Position */
#define SFR_CCFG_EBICSA_NFD0_ON_D16_Msk       (_UINT32_(0x1) << SFR_CCFG_EBICSA_NFD0_ON_D16_Pos)   /* (SFR_CCFG_EBICSA) NAND Flash Databus Selection Mask */
#define SFR_CCFG_EBICSA_NFD0_ON_D16(value)    (SFR_CCFG_EBICSA_NFD0_ON_D16_Msk & (_UINT32_(value) << SFR_CCFG_EBICSA_NFD0_ON_D16_Pos)) /* Assigment of value for NFD0_ON_D16 in the SFR_CCFG_EBICSA register */
#define SFR_CCFG_EBICSA_DDR_MP_EN_Pos         _UINT32_(25)                                         /* (SFR_CCFG_EBICSA) DDR Multi-port Enable Position */
#define SFR_CCFG_EBICSA_DDR_MP_EN_Msk         (_UINT32_(0x1) << SFR_CCFG_EBICSA_DDR_MP_EN_Pos)     /* (SFR_CCFG_EBICSA) DDR Multi-port Enable Mask */
#define SFR_CCFG_EBICSA_DDR_MP_EN(value)      (SFR_CCFG_EBICSA_DDR_MP_EN_Msk & (_UINT32_(value) << SFR_CCFG_EBICSA_DDR_MP_EN_Pos)) /* Assigment of value for DDR_MP_EN in the SFR_CCFG_EBICSA register */
#define SFR_CCFG_EBICSA_Msk                   _UINT32_(0x0311033A)                                 /* (SFR_CCFG_EBICSA) Register Mask  */

#define SFR_CCFG_EBICSA_NFD0_ON_D_Pos         _UINT32_(24)                                         /* (SFR_CCFG_EBICSA Position) NAND Flash Databus Selection */
#define SFR_CCFG_EBICSA_NFD0_ON_D_Msk         (_UINT32_(0x1) << SFR_CCFG_EBICSA_NFD0_ON_D_Pos)     /* (SFR_CCFG_EBICSA Mask) NFD0_ON_D */
#define SFR_CCFG_EBICSA_NFD0_ON_D(value)      (SFR_CCFG_EBICSA_NFD0_ON_D_Msk & (_UINT32_(value) << SFR_CCFG_EBICSA_NFD0_ON_D_Pos)) 

/* -------- SFR_OHCIICR : (SFR Offset: 0x10) (R/W 32) OHCI Interrupt Configuration Register -------- */
#define SFR_OHCIICR_RES0_Pos                  _UINT32_(0)                                          /* (SFR_OHCIICR) USB PORTx Reset Position */
#define SFR_OHCIICR_RES0_Msk                  (_UINT32_(0x1) << SFR_OHCIICR_RES0_Pos)              /* (SFR_OHCIICR) USB PORTx Reset Mask */
#define SFR_OHCIICR_RES0(value)               (SFR_OHCIICR_RES0_Msk & (_UINT32_(value) << SFR_OHCIICR_RES0_Pos)) /* Assigment of value for RES0 in the SFR_OHCIICR register */
#define SFR_OHCIICR_RES1_Pos                  _UINT32_(1)                                          /* (SFR_OHCIICR) USB PORTx Reset Position */
#define SFR_OHCIICR_RES1_Msk                  (_UINT32_(0x1) << SFR_OHCIICR_RES1_Pos)              /* (SFR_OHCIICR) USB PORTx Reset Mask */
#define SFR_OHCIICR_RES1(value)               (SFR_OHCIICR_RES1_Msk & (_UINT32_(value) << SFR_OHCIICR_RES1_Pos)) /* Assigment of value for RES1 in the SFR_OHCIICR register */
#define SFR_OHCIICR_RES2_Pos                  _UINT32_(2)                                          /* (SFR_OHCIICR) USB PORTx Reset Position */
#define SFR_OHCIICR_RES2_Msk                  (_UINT32_(0x1) << SFR_OHCIICR_RES2_Pos)              /* (SFR_OHCIICR) USB PORTx Reset Mask */
#define SFR_OHCIICR_RES2(value)               (SFR_OHCIICR_RES2_Msk & (_UINT32_(value) << SFR_OHCIICR_RES2_Pos)) /* Assigment of value for RES2 in the SFR_OHCIICR register */
#define SFR_OHCIICR_ARIE_Pos                  _UINT32_(4)                                          /* (SFR_OHCIICR) OHCI Asynchronous Resume Interrupt Enable Position */
#define SFR_OHCIICR_ARIE_Msk                  (_UINT32_(0x1) << SFR_OHCIICR_ARIE_Pos)              /* (SFR_OHCIICR) OHCI Asynchronous Resume Interrupt Enable Mask */
#define SFR_OHCIICR_ARIE(value)               (SFR_OHCIICR_ARIE_Msk & (_UINT32_(value) << SFR_OHCIICR_ARIE_Pos)) /* Assigment of value for ARIE in the SFR_OHCIICR register */
#define SFR_OHCIICR_APPSTART_Pos              _UINT32_(5)                                          /* (SFR_OHCIICR) Reserved Position */
#define SFR_OHCIICR_APPSTART_Msk              (_UINT32_(0x1) << SFR_OHCIICR_APPSTART_Pos)          /* (SFR_OHCIICR) Reserved Mask */
#define SFR_OHCIICR_APPSTART(value)           (SFR_OHCIICR_APPSTART_Msk & (_UINT32_(value) << SFR_OHCIICR_APPSTART_Pos)) /* Assigment of value for APPSTART in the SFR_OHCIICR register */
#define SFR_OHCIICR_SUSP0_Pos                 _UINT32_(8)                                          /* (SFR_OHCIICR) USB PORTx Position */
#define SFR_OHCIICR_SUSP0_Msk                 (_UINT32_(0x1) << SFR_OHCIICR_SUSP0_Pos)             /* (SFR_OHCIICR) USB PORTx Mask */
#define SFR_OHCIICR_SUSP0(value)              (SFR_OHCIICR_SUSP0_Msk & (_UINT32_(value) << SFR_OHCIICR_SUSP0_Pos)) /* Assigment of value for SUSP0 in the SFR_OHCIICR register */
#define SFR_OHCIICR_SUSP1_Pos                 _UINT32_(9)                                          /* (SFR_OHCIICR) USB PORTx Position */
#define SFR_OHCIICR_SUSP1_Msk                 (_UINT32_(0x1) << SFR_OHCIICR_SUSP1_Pos)             /* (SFR_OHCIICR) USB PORTx Mask */
#define SFR_OHCIICR_SUSP1(value)              (SFR_OHCIICR_SUSP1_Msk & (_UINT32_(value) << SFR_OHCIICR_SUSP1_Pos)) /* Assigment of value for SUSP1 in the SFR_OHCIICR register */
#define SFR_OHCIICR_SUSP2_Pos                 _UINT32_(10)                                         /* (SFR_OHCIICR) USB PORTx Position */
#define SFR_OHCIICR_SUSP2_Msk                 (_UINT32_(0x1) << SFR_OHCIICR_SUSP2_Pos)             /* (SFR_OHCIICR) USB PORTx Mask */
#define SFR_OHCIICR_SUSP2(value)              (SFR_OHCIICR_SUSP2_Msk & (_UINT32_(value) << SFR_OHCIICR_SUSP2_Pos)) /* Assigment of value for SUSP2 in the SFR_OHCIICR register */
#define SFR_OHCIICR_UDPPUDIS_Pos              _UINT32_(23)                                         /* (SFR_OHCIICR) Reserved Position */
#define SFR_OHCIICR_UDPPUDIS_Msk              (_UINT32_(0x1) << SFR_OHCIICR_UDPPUDIS_Pos)          /* (SFR_OHCIICR) Reserved Mask */
#define SFR_OHCIICR_UDPPUDIS(value)           (SFR_OHCIICR_UDPPUDIS_Msk & (_UINT32_(value) << SFR_OHCIICR_UDPPUDIS_Pos)) /* Assigment of value for UDPPUDIS in the SFR_OHCIICR register */
#define SFR_OHCIICR_Msk                       _UINT32_(0x00800737)                                 /* (SFR_OHCIICR) Register Mask  */

#define SFR_OHCIICR_RES_Pos                   _UINT32_(0)                                          /* (SFR_OHCIICR Position) USB PORTx Reset */
#define SFR_OHCIICR_RES_Msk                   (_UINT32_(0x7) << SFR_OHCIICR_RES_Pos)               /* (SFR_OHCIICR Mask) RES */
#define SFR_OHCIICR_RES(value)                (SFR_OHCIICR_RES_Msk & (_UINT32_(value) << SFR_OHCIICR_RES_Pos)) 
#define SFR_OHCIICR_SUSP_Pos                  _UINT32_(8)                                          /* (SFR_OHCIICR Position) USB PORTx */
#define SFR_OHCIICR_SUSP_Msk                  (_UINT32_(0x7) << SFR_OHCIICR_SUSP_Pos)              /* (SFR_OHCIICR Mask) SUSP */
#define SFR_OHCIICR_SUSP(value)               (SFR_OHCIICR_SUSP_Msk & (_UINT32_(value) << SFR_OHCIICR_SUSP_Pos)) 

/* -------- SFR_OHCIISR : (SFR Offset: 0x14) ( R/ 32) OHCI Interrupt Status Register -------- */
#define SFR_OHCIISR_RIS0_Pos                  _UINT32_(0)                                          /* (SFR_OHCIISR) OHCI Resume Interrupt Status Port 0 Position */
#define SFR_OHCIISR_RIS0_Msk                  (_UINT32_(0x1) << SFR_OHCIISR_RIS0_Pos)              /* (SFR_OHCIISR) OHCI Resume Interrupt Status Port 0 Mask */
#define SFR_OHCIISR_RIS0(value)               (SFR_OHCIISR_RIS0_Msk & (_UINT32_(value) << SFR_OHCIISR_RIS0_Pos)) /* Assigment of value for RIS0 in the SFR_OHCIISR register */
#define SFR_OHCIISR_RIS1_Pos                  _UINT32_(1)                                          /* (SFR_OHCIISR) OHCI Resume Interrupt Status Port 1 Position */
#define SFR_OHCIISR_RIS1_Msk                  (_UINT32_(0x1) << SFR_OHCIISR_RIS1_Pos)              /* (SFR_OHCIISR) OHCI Resume Interrupt Status Port 1 Mask */
#define SFR_OHCIISR_RIS1(value)               (SFR_OHCIISR_RIS1_Msk & (_UINT32_(value) << SFR_OHCIISR_RIS1_Pos)) /* Assigment of value for RIS1 in the SFR_OHCIISR register */
#define SFR_OHCIISR_RIS2_Pos                  _UINT32_(2)                                          /* (SFR_OHCIISR) OHCI Resume Interrupt Status Port 2 Position */
#define SFR_OHCIISR_RIS2_Msk                  (_UINT32_(0x1) << SFR_OHCIISR_RIS2_Pos)              /* (SFR_OHCIISR) OHCI Resume Interrupt Status Port 2 Mask */
#define SFR_OHCIISR_RIS2(value)               (SFR_OHCIISR_RIS2_Msk & (_UINT32_(value) << SFR_OHCIISR_RIS2_Pos)) /* Assigment of value for RIS2 in the SFR_OHCIISR register */
#define SFR_OHCIISR_Msk                       _UINT32_(0x00000007)                                 /* (SFR_OHCIISR) Register Mask  */

#define SFR_OHCIISR_RIS_Pos                   _UINT32_(0)                                          /* (SFR_OHCIISR Position) OHCI Resume Interrupt Status Port 2 */
#define SFR_OHCIISR_RIS_Msk                   (_UINT32_(0x7) << SFR_OHCIISR_RIS_Pos)               /* (SFR_OHCIISR Mask) RIS */
#define SFR_OHCIISR_RIS(value)                (SFR_OHCIISR_RIS_Msk & (_UINT32_(value) << SFR_OHCIISR_RIS_Pos)) 

/* -------- SFR_UTMIHSTRIM : (SFR Offset: 0x34) (R/W 32) UTMI High-Speed Trimming Register -------- */
#define SFR_UTMIHSTRIM_SLOPE0_Pos             _UINT32_(8)                                          /* (SFR_UTMIHSTRIM) UTMI HS PORTx Transceiver Slope Trimming Position */
#define SFR_UTMIHSTRIM_SLOPE0_Msk             (_UINT32_(0x7) << SFR_UTMIHSTRIM_SLOPE0_Pos)         /* (SFR_UTMIHSTRIM) UTMI HS PORTx Transceiver Slope Trimming Mask */
#define SFR_UTMIHSTRIM_SLOPE0(value)          (SFR_UTMIHSTRIM_SLOPE0_Msk & (_UINT32_(value) << SFR_UTMIHSTRIM_SLOPE0_Pos)) /* Assigment of value for SLOPE0 in the SFR_UTMIHSTRIM register */
#define SFR_UTMIHSTRIM_SLOPE1_Pos             _UINT32_(12)                                         /* (SFR_UTMIHSTRIM) UTMI HS PORTx Transceiver Slope Trimming Position */
#define SFR_UTMIHSTRIM_SLOPE1_Msk             (_UINT32_(0x7) << SFR_UTMIHSTRIM_SLOPE1_Pos)         /* (SFR_UTMIHSTRIM) UTMI HS PORTx Transceiver Slope Trimming Mask */
#define SFR_UTMIHSTRIM_SLOPE1(value)          (SFR_UTMIHSTRIM_SLOPE1_Msk & (_UINT32_(value) << SFR_UTMIHSTRIM_SLOPE1_Pos)) /* Assigment of value for SLOPE1 in the SFR_UTMIHSTRIM register */
#define SFR_UTMIHSTRIM_SLOPE2_Pos             _UINT32_(16)                                         /* (SFR_UTMIHSTRIM) UTMI HS PORTx Transceiver Slope Trimming Position */
#define SFR_UTMIHSTRIM_SLOPE2_Msk             (_UINT32_(0x7) << SFR_UTMIHSTRIM_SLOPE2_Pos)         /* (SFR_UTMIHSTRIM) UTMI HS PORTx Transceiver Slope Trimming Mask */
#define SFR_UTMIHSTRIM_SLOPE2(value)          (SFR_UTMIHSTRIM_SLOPE2_Msk & (_UINT32_(value) << SFR_UTMIHSTRIM_SLOPE2_Pos)) /* Assigment of value for SLOPE2 in the SFR_UTMIHSTRIM register */
#define SFR_UTMIHSTRIM_Msk                    _UINT32_(0x00077700)                                 /* (SFR_UTMIHSTRIM) Register Mask  */


/* -------- SFR_UTMIFSTRIM : (SFR Offset: 0x38) (R/W 32) UTMI Full-Speed Trimming Register -------- */
#define SFR_UTMIFSTRIM_ZN_Pos                 _UINT32_(16)                                         /* (SFR_UTMIFSTRIM) FS Transceiver NMOS Impedance Trimming Position */
#define SFR_UTMIFSTRIM_ZN_Msk                 (_UINT32_(0x7) << SFR_UTMIFSTRIM_ZN_Pos)             /* (SFR_UTMIFSTRIM) FS Transceiver NMOS Impedance Trimming Mask */
#define SFR_UTMIFSTRIM_ZN(value)              (SFR_UTMIFSTRIM_ZN_Msk & (_UINT32_(value) << SFR_UTMIFSTRIM_ZN_Pos)) /* Assigment of value for ZN in the SFR_UTMIFSTRIM register */
#define SFR_UTMIFSTRIM_ZP_Pos                 _UINT32_(20)                                         /* (SFR_UTMIFSTRIM) FS Transceiver PMOS Impedance Trimming Position */
#define SFR_UTMIFSTRIM_ZP_Msk                 (_UINT32_(0x7) << SFR_UTMIFSTRIM_ZP_Pos)             /* (SFR_UTMIFSTRIM) FS Transceiver PMOS Impedance Trimming Mask */
#define SFR_UTMIFSTRIM_ZP(value)              (SFR_UTMIFSTRIM_ZP_Msk & (_UINT32_(value) << SFR_UTMIFSTRIM_ZP_Pos)) /* Assigment of value for ZP in the SFR_UTMIFSTRIM register */
#define SFR_UTMIFSTRIM_ZN_CAL_Pos             _UINT32_(24)                                         /* (SFR_UTMIFSTRIM) FS Transceiver NMOS Impedance Calibration Position */
#define SFR_UTMIFSTRIM_ZN_CAL_Msk             (_UINT32_(0x7) << SFR_UTMIFSTRIM_ZN_CAL_Pos)         /* (SFR_UTMIFSTRIM) FS Transceiver NMOS Impedance Calibration Mask */
#define SFR_UTMIFSTRIM_ZN_CAL(value)          (SFR_UTMIFSTRIM_ZN_CAL_Msk & (_UINT32_(value) << SFR_UTMIFSTRIM_ZN_CAL_Pos)) /* Assigment of value for ZN_CAL in the SFR_UTMIFSTRIM register */
#define SFR_UTMIFSTRIM_ZP_CAL_Pos             _UINT32_(28)                                         /* (SFR_UTMIFSTRIM) FS Transceiver PMOS Impedance Calibration Position */
#define SFR_UTMIFSTRIM_ZP_CAL_Msk             (_UINT32_(0x7) << SFR_UTMIFSTRIM_ZP_CAL_Pos)         /* (SFR_UTMIFSTRIM) FS Transceiver PMOS Impedance Calibration Mask */
#define SFR_UTMIFSTRIM_ZP_CAL(value)          (SFR_UTMIFSTRIM_ZP_CAL_Msk & (_UINT32_(value) << SFR_UTMIFSTRIM_ZP_CAL_Pos)) /* Assigment of value for ZP_CAL in the SFR_UTMIFSTRIM register */
#define SFR_UTMIFSTRIM_Msk                    _UINT32_(0x77770000)                                 /* (SFR_UTMIFSTRIM) Register Mask  */


/* -------- SFR_UTMISWAP : (SFR Offset: 0x3C) (R/W 32) UTMI DP/DM Pin Swapping Register -------- */
#define SFR_UTMISWAP_PORT0_Pos                _UINT32_(0)                                          /* (SFR_UTMISWAP) PORT 0 DP/DM Pin Swapping Position */
#define SFR_UTMISWAP_PORT0_Msk                (_UINT32_(0x1) << SFR_UTMISWAP_PORT0_Pos)            /* (SFR_UTMISWAP) PORT 0 DP/DM Pin Swapping Mask */
#define SFR_UTMISWAP_PORT0(value)             (SFR_UTMISWAP_PORT0_Msk & (_UINT32_(value) << SFR_UTMISWAP_PORT0_Pos)) /* Assigment of value for PORT0 in the SFR_UTMISWAP register */
#define   SFR_UTMISWAP_PORT0_NORMAL_Val       _UINT32_(0x0)                                        /* (SFR_UTMISWAP) DP/DM normal pinout.  */
#define   SFR_UTMISWAP_PORT0_SWAPPED_Val      _UINT32_(0x1)                                        /* (SFR_UTMISWAP) DP/DM swapped pinout.  */
#define SFR_UTMISWAP_PORT0_NORMAL             (SFR_UTMISWAP_PORT0_NORMAL_Val << SFR_UTMISWAP_PORT0_Pos) /* (SFR_UTMISWAP) DP/DM normal pinout. Position  */
#define SFR_UTMISWAP_PORT0_SWAPPED            (SFR_UTMISWAP_PORT0_SWAPPED_Val << SFR_UTMISWAP_PORT0_Pos) /* (SFR_UTMISWAP) DP/DM swapped pinout. Position  */
#define SFR_UTMISWAP_PORT1_Pos                _UINT32_(1)                                          /* (SFR_UTMISWAP) PORT 1 DP/DM Pin Swapping Position */
#define SFR_UTMISWAP_PORT1_Msk                (_UINT32_(0x1) << SFR_UTMISWAP_PORT1_Pos)            /* (SFR_UTMISWAP) PORT 1 DP/DM Pin Swapping Mask */
#define SFR_UTMISWAP_PORT1(value)             (SFR_UTMISWAP_PORT1_Msk & (_UINT32_(value) << SFR_UTMISWAP_PORT1_Pos)) /* Assigment of value for PORT1 in the SFR_UTMISWAP register */
#define   SFR_UTMISWAP_PORT1_NORMAL_Val       _UINT32_(0x0)                                        /* (SFR_UTMISWAP) DP/DM normal pinout.  */
#define   SFR_UTMISWAP_PORT1_SWAPPED_Val      _UINT32_(0x1)                                        /* (SFR_UTMISWAP) DP/DM swapped pinout.  */
#define SFR_UTMISWAP_PORT1_NORMAL             (SFR_UTMISWAP_PORT1_NORMAL_Val << SFR_UTMISWAP_PORT1_Pos) /* (SFR_UTMISWAP) DP/DM normal pinout. Position  */
#define SFR_UTMISWAP_PORT1_SWAPPED            (SFR_UTMISWAP_PORT1_SWAPPED_Val << SFR_UTMISWAP_PORT1_Pos) /* (SFR_UTMISWAP) DP/DM swapped pinout. Position  */
#define SFR_UTMISWAP_PORT2_Pos                _UINT32_(2)                                          /* (SFR_UTMISWAP) PORT 2 DP/DM Pin Swapping Position */
#define SFR_UTMISWAP_PORT2_Msk                (_UINT32_(0x1) << SFR_UTMISWAP_PORT2_Pos)            /* (SFR_UTMISWAP) PORT 2 DP/DM Pin Swapping Mask */
#define SFR_UTMISWAP_PORT2(value)             (SFR_UTMISWAP_PORT2_Msk & (_UINT32_(value) << SFR_UTMISWAP_PORT2_Pos)) /* Assigment of value for PORT2 in the SFR_UTMISWAP register */
#define   SFR_UTMISWAP_PORT2_NORMAL_Val       _UINT32_(0x0)                                        /* (SFR_UTMISWAP) DP/DM normal pinout.  */
#define   SFR_UTMISWAP_PORT2_SWAPPED_Val      _UINT32_(0x1)                                        /* (SFR_UTMISWAP) DP/DM swapped pinout.  */
#define SFR_UTMISWAP_PORT2_NORMAL             (SFR_UTMISWAP_PORT2_NORMAL_Val << SFR_UTMISWAP_PORT2_Pos) /* (SFR_UTMISWAP) DP/DM normal pinout. Position  */
#define SFR_UTMISWAP_PORT2_SWAPPED            (SFR_UTMISWAP_PORT2_SWAPPED_Val << SFR_UTMISWAP_PORT2_Pos) /* (SFR_UTMISWAP) DP/DM swapped pinout. Position  */
#define SFR_UTMISWAP_Msk                      _UINT32_(0x00000007)                                 /* (SFR_UTMISWAP) Register Mask  */

#define SFR_UTMISWAP_PORT_Pos                 _UINT32_(0)                                          /* (SFR_UTMISWAP Position) PORT 2 DP/DM Pin Swapping */
#define SFR_UTMISWAP_PORT_Msk                 (_UINT32_(0x7) << SFR_UTMISWAP_PORT_Pos)             /* (SFR_UTMISWAP Mask) PORT */
#define SFR_UTMISWAP_PORT(value)              (SFR_UTMISWAP_PORT_Msk & (_UINT32_(value) << SFR_UTMISWAP_PORT_Pos)) 

/* -------- SFR_LS : (SFR Offset: 0x7C) (R/W 32) Light Sleep Register -------- */
#define SFR_LS_LS0_Pos                        _UINT32_(0)                                          /* (SFR_LS) Light Sleep Value (GFX2D) Position */
#define SFR_LS_LS0_Msk                        (_UINT32_(0x1) << SFR_LS_LS0_Pos)                    /* (SFR_LS) Light Sleep Value (GFX2D) Mask */
#define SFR_LS_LS0(value)                     (SFR_LS_LS0_Msk & (_UINT32_(value) << SFR_LS_LS0_Pos)) /* Assigment of value for LS0 in the SFR_LS register */
#define SFR_LS_LS1_Pos                        _UINT32_(1)                                          /* (SFR_LS) Light Sleep Value (HLCDC5) Position */
#define SFR_LS_LS1_Msk                        (_UINT32_(0x1) << SFR_LS_LS1_Pos)                    /* (SFR_LS) Light Sleep Value (HLCDC5) Mask */
#define SFR_LS_LS1(value)                     (SFR_LS_LS1_Msk & (_UINT32_(value) << SFR_LS_LS1_Pos)) /* Assigment of value for LS1 in the SFR_LS register */
#define SFR_LS_LS2_Pos                        _UINT32_(2)                                          /* (SFR_LS) Light Sleep Value (SDMMC) Position */
#define SFR_LS_LS2_Msk                        (_UINT32_(0x1) << SFR_LS_LS2_Pos)                    /* (SFR_LS) Light Sleep Value (SDMMC) Mask */
#define SFR_LS_LS2(value)                     (SFR_LS_LS2_Msk & (_UINT32_(value) << SFR_LS_LS2_Pos)) /* Assigment of value for LS2 in the SFR_LS register */
#define SFR_LS_LS3_Pos                        _UINT32_(3)                                          /* (SFR_LS) Light Sleep Value (HUSB) Position */
#define SFR_LS_LS3_Msk                        (_UINT32_(0x1) << SFR_LS_LS3_Pos)                    /* (SFR_LS) Light Sleep Value (HUSB) Mask */
#define SFR_LS_LS3(value)                     (SFR_LS_LS3_Msk & (_UINT32_(value) << SFR_LS_LS3_Pos)) /* Assigment of value for LS3 in the SFR_LS register */
#define SFR_LS_LS4_Pos                        _UINT32_(4)                                          /* (SFR_LS) Light Sleep Value (HXDMA) Position */
#define SFR_LS_LS4_Msk                        (_UINT32_(0x1) << SFR_LS_LS4_Pos)                    /* (SFR_LS) Light Sleep Value (HXDMA) Mask */
#define SFR_LS_LS4(value)                     (SFR_LS_LS4_Msk & (_UINT32_(value) << SFR_LS_LS4_Pos)) /* Assigment of value for LS4 in the SFR_LS register */
#define SFR_LS_LS5_Pos                        _UINT32_(5)                                          /* (SFR_LS) Light Sleep Value (EHCI/OHCI) Position */
#define SFR_LS_LS5_Msk                        (_UINT32_(0x1) << SFR_LS_LS5_Pos)                    /* (SFR_LS) Light Sleep Value (EHCI/OHCI) Mask */
#define SFR_LS_LS5(value)                     (SFR_LS_LS5_Msk & (_UINT32_(value) << SFR_LS_LS5_Pos)) /* Assigment of value for LS5 in the SFR_LS register */
#define SFR_LS_LS6_Pos                        _UINT32_(6)                                          /* (SFR_LS) Light Sleep Value (SRAM0) Position */
#define SFR_LS_LS6_Msk                        (_UINT32_(0x1) << SFR_LS_LS6_Pos)                    /* (SFR_LS) Light Sleep Value (SRAM0) Mask */
#define SFR_LS_LS6(value)                     (SFR_LS_LS6_Msk & (_UINT32_(value) << SFR_LS_LS6_Pos)) /* Assigment of value for LS6 in the SFR_LS register */
#define SFR_LS_LS7_Pos                        _UINT32_(7)                                          /* (SFR_LS) Light Sleep Value (SRAM1 (OTPC)) Position */
#define SFR_LS_LS7_Msk                        (_UINT32_(0x1) << SFR_LS_LS7_Pos)                    /* (SFR_LS) Light Sleep Value (SRAM1 (OTPC)) Mask */
#define SFR_LS_LS7(value)                     (SFR_LS_LS7_Msk & (_UINT32_(value) << SFR_LS_LS7_Pos)) /* Assigment of value for LS7 in the SFR_LS register */
#define SFR_LS_LS8_Pos                        _UINT32_(8)                                          /* (SFR_LS) Light Sleep Value (ROM + OTPC) Position */
#define SFR_LS_LS8_Msk                        (_UINT32_(0x1) << SFR_LS_LS8_Pos)                    /* (SFR_LS) Light Sleep Value (ROM + OTPC) Mask */
#define SFR_LS_LS8(value)                     (SFR_LS_LS8_Msk & (_UINT32_(value) << SFR_LS_LS8_Pos)) /* Assigment of value for LS8 in the SFR_LS register */
#define SFR_LS_LS9_Pos                        _UINT32_(9)                                          /* (SFR_LS) Light Sleep Value (ARM926) Position */
#define SFR_LS_LS9_Msk                        (_UINT32_(0x1) << SFR_LS_LS9_Pos)                    /* (SFR_LS) Light Sleep Value (ARM926) Mask */
#define SFR_LS_LS9(value)                     (SFR_LS_LS9_Msk & (_UINT32_(value) << SFR_LS_LS9_Pos)) /* Assigment of value for LS9 in the SFR_LS register */
#define SFR_LS_MEM_POWER_GATING_ULP1_EN_Pos   _UINT32_(16)                                         /* (SFR_LS) Light Sleep Value for ULP1 Power-Gated Memories Position */
#define SFR_LS_MEM_POWER_GATING_ULP1_EN_Msk   (_UINT32_(0x1) << SFR_LS_MEM_POWER_GATING_ULP1_EN_Pos) /* (SFR_LS) Light Sleep Value for ULP1 Power-Gated Memories Mask */
#define SFR_LS_MEM_POWER_GATING_ULP1_EN(value) (SFR_LS_MEM_POWER_GATING_ULP1_EN_Msk & (_UINT32_(value) << SFR_LS_MEM_POWER_GATING_ULP1_EN_Pos)) /* Assigment of value for MEM_POWER_GATING_ULP1_EN in the SFR_LS register */
#define SFR_LS_Msk                            _UINT32_(0x000103FF)                                 /* (SFR_LS) Register Mask  */

#define SFR_LS_LS_Pos                         _UINT32_(0)                                          /* (SFR_LS Position) Light Sleep Value (GFX2D) */
#define SFR_LS_LS_Msk                         (_UINT32_(0x3FF) << SFR_LS_LS_Pos)                   /* (SFR_LS Mask) LS */
#define SFR_LS_LS(value)                      (SFR_LS_LS_Msk & (_UINT32_(value) << SFR_LS_LS_Pos)) 

/* -------- SFR_WPMR : (SFR Offset: 0xE4) (R/W 32) Write Protection Mode Register -------- */
#define SFR_WPMR_WPEN_Pos                     _UINT32_(0)                                          /* (SFR_WPMR) Write Protection Enable Position */
#define SFR_WPMR_WPEN_Msk                     (_UINT32_(0x1) << SFR_WPMR_WPEN_Pos)                 /* (SFR_WPMR) Write Protection Enable Mask */
#define SFR_WPMR_WPEN(value)                  (SFR_WPMR_WPEN_Msk & (_UINT32_(value) << SFR_WPMR_WPEN_Pos)) /* Assigment of value for WPEN in the SFR_WPMR register */
#define SFR_WPMR_WPKEY_Pos                    _UINT32_(8)                                          /* (SFR_WPMR) Write Protection Key Position */
#define SFR_WPMR_WPKEY_Msk                    (_UINT32_(0xFFFFFF) << SFR_WPMR_WPKEY_Pos)           /* (SFR_WPMR) Write Protection Key Mask */
#define SFR_WPMR_WPKEY(value)                 (SFR_WPMR_WPKEY_Msk & (_UINT32_(value) << SFR_WPMR_WPKEY_Pos)) /* Assigment of value for WPKEY in the SFR_WPMR register */
#define   SFR_WPMR_WPKEY_PASSWD_Val           _UINT32_(0x534652)                                   /* (SFR_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0.  */
#define SFR_WPMR_WPKEY_PASSWD                 (SFR_WPMR_WPKEY_PASSWD_Val << SFR_WPMR_WPKEY_Pos)    /* (SFR_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0. Position  */
#define SFR_WPMR_Msk                          _UINT32_(0xFFFFFF01)                                 /* (SFR_WPMR) Register Mask  */


/** \brief SFR register offsets definitions */
#define SFR_CCFG_EBICSA_REG_OFST       _UINT32_(0x04)      /* (SFR_CCFG_EBICSA) EBI Chip Select Register Offset */
#define SFR_OHCIICR_REG_OFST           _UINT32_(0x10)      /* (SFR_OHCIICR) OHCI Interrupt Configuration Register Offset */
#define SFR_OHCIISR_REG_OFST           _UINT32_(0x14)      /* (SFR_OHCIISR) OHCI Interrupt Status Register Offset */
#define SFR_UTMIHSTRIM_REG_OFST        _UINT32_(0x34)      /* (SFR_UTMIHSTRIM) UTMI High-Speed Trimming Register Offset */
#define SFR_UTMIFSTRIM_REG_OFST        _UINT32_(0x38)      /* (SFR_UTMIFSTRIM) UTMI Full-Speed Trimming Register Offset */
#define SFR_UTMISWAP_REG_OFST          _UINT32_(0x3C)      /* (SFR_UTMISWAP) UTMI DP/DM Pin Swapping Register Offset */
#define SFR_LS_REG_OFST                _UINT32_(0x7C)      /* (SFR_LS) Light Sleep Register Offset */
#define SFR_WPMR_REG_OFST              _UINT32_(0xE4)      /* (SFR_WPMR) Write Protection Mode Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief SFR register API structure */
typedef struct
{
  __I   uint8_t                        Reserved1[0x04];
  __IO  uint32_t                       SFR_CCFG_EBICSA;    /**< Offset: 0x04 (R/W  32) EBI Chip Select Register */
  __I   uint8_t                        Reserved2[0x08];
  __IO  uint32_t                       SFR_OHCIICR;        /**< Offset: 0x10 (R/W  32) OHCI Interrupt Configuration Register */
  __I   uint32_t                       SFR_OHCIISR;        /**< Offset: 0x14 (R/   32) OHCI Interrupt Status Register */
  __I   uint8_t                        Reserved3[0x1C];
  __IO  uint32_t                       SFR_UTMIHSTRIM;     /**< Offset: 0x34 (R/W  32) UTMI High-Speed Trimming Register */
  __IO  uint32_t                       SFR_UTMIFSTRIM;     /**< Offset: 0x38 (R/W  32) UTMI Full-Speed Trimming Register */
  __IO  uint32_t                       SFR_UTMISWAP;       /**< Offset: 0x3C (R/W  32) UTMI DP/DM Pin Swapping Register */
  __I   uint8_t                        Reserved4[0x3C];
  __IO  uint32_t                       SFR_LS;             /**< Offset: 0x7C (R/W  32) Light Sleep Register */
  __I   uint8_t                        Reserved5[0x64];
  __IO  uint32_t                       SFR_WPMR;           /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
} sfr_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAM9X_SFR_COMPONENT_H_ */
